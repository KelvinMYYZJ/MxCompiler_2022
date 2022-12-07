#include "AST_nodes.h"
#include "class_scope.h"
#include "my_any.hpp"
using namespace std;
namespace AST {
void ProgNode::BuildScope(shared_ptr<GScope> _gscope) {
  gscope = _gscope;
  // create all the classes in gscope
  for (auto now_def : definitions) {
    if (auto class_def = AnyCastPtr<ClassDefNode>(now_def)) {
      gscope->AddBlankClass(class_def->class_identifier);
    }
  }

  // create all the func in gscope
  for (auto now_def : definitions) {
    if (auto func_def = AnyCastPtr<FuncDefNode>(now_def)) {
      gscope->AddFunc(func_def->func_identifier, func_def->GetFuncType());
    }
  }

  // build the class info
  for (auto now_def : definitions) {
    if (auto class_def = AnyCastPtr<ClassDefNode>(now_def)) {
      const string& class_identifier = class_def->class_identifier;
      ClassInfo& class_info = (*gscope->classes)[class_identifier];
      auto class_scope = class_def->scope = make_shared<ClassScope>(gscope);
      for (auto member_def : class_def->member_stmts) {
        if (auto var_def = AnyCastPtr<VarDefNode>(member_def)) {
          const auto& var_type = var_def->type;
          for (auto var : var_def->var_defs) {
            const auto& var_identifier = var.var_identifier;
            class_info.AddMemberVar(var_identifier, var_type);
            class_scope->AddMemberVar(var_identifier, var_type);
          }
        } else if (auto func_def = AnyCastPtr<FuncDefNode>(member_def)) {
          const auto& func_identifier = func_def->func_identifier;
          MyAssert(func_identifier != class_identifier, "Member func should not have the same identifier with class.");
          const auto& func_type = func_def->GetFuncType();
          class_info.AddMemberFunc(func_identifier, func_type);
          class_scope->AddMemberFunc(func_identifier, func_type);
        } else if (auto constructor_def = AnyCastPtr<ConstructFuncDefNode>(member_def)) {
          MyAssert(constructor_def->func_identifier == class_identifier,
                   "Constructor should have the same name with class.");
        }
      }
    }
  }

  // visit all the stmts
  for (auto now_def : definitions) {
    if (auto var_def = AnyCastPtr<VarDefNode>(now_def)) {
      var_def->BuildScope(gscope);
    } else if (auto class_def = AnyCastPtr<ClassDefNode>(now_def)) {
      class_def->BuildScope();
    } else if (auto func_def = AnyCastPtr<FuncDefNode>(now_def)) {
      func_def->BuildScope(gscope);
    }
  }
  MyAssert(gscope->funcs->count("main"), "main func not found");
}
void VarDefNode::BuildScope(shared_ptr<Scope> _scope) {
  scope = _scope;
  scope->CheckClass(type.type_identifier);
  MyAssert(type.type_identifier != "void", "wrong type in var def : void");
  for (auto var : var_defs) {
    const auto& var_identifier = var.var_identifier;
    if (var.have_expr) {
      auto expr = var.expr;
      expr->BuildScope(scope);
      MyAssert(expr->value_type.GetObjectType() == type, "init a var with a different type expr.");
    }
    scope->AddVar(var_identifier, type);
  }
}
void ClassDefNode::BuildScope() {
  scope->AddMemberVar("this", {class_identifier});
  for (auto member_def : member_stmts) {
    if (auto var_def = AnyCastPtr<VarDefNode>(member_def)) {
      var_def->BuildScope(scope);
    } else if (auto func_def = AnyCastPtr<FuncDefNode>(member_def)) {
      func_def->BuildScope(scope);
    } else if (auto constructor_def = AnyCastPtr<ConstructFuncDefNode>(member_def)) {
      constructor_def->BuildScope(scope);
    }
  }
}
void FuncDefNode::BuildScope(shared_ptr<Scope> _scope) {
  scope = make_shared<Scope>(_scope);
  scope->CheckClass(type.type_identifier);
  args_def->BuildScope(scope);
  body->BuildScope(scope, false);
  MyAssert(
      type == body->ret_type.type || ((type == kVoidType || func_identifier == "main") && !body->ret_type.have_ret),
      "wrong return type");
}
void ArgListDefNode::BuildScope(shared_ptr<Scope> _scope) {
  scope = _scope;
  for (auto arg : args) {
    scope->CheckClass(arg.type.type_identifier);
    scope->AddVar(arg.arg_identifier, arg.type);
  }
}
void ArgListNode::BuildScope(shared_ptr<Scope> _scope) {
  scope = _scope;
  for (auto arg : args) {
    arg->BuildScope(scope);
    type_list.push_back(arg->value_type.GetObjectType());
  }
}
void ConstructFuncDefNode::BuildScope(shared_ptr<Scope> _scope) {
  scope = make_shared<Scope>(_scope);
  body->BuildScope(scope, false);
  MyAssert(body->ret_type.IsVoid(), "wrong return type of construct func");
}
void StmtBlockNode::BuildScope(shared_ptr<Scope> _scope, bool create_inner_scope) {
  if (create_inner_scope) {
    scope = make_shared<Scope>(_scope);
  } else {
    scope = _scope;
  }
  for (auto stmt : stmts) {
    if (auto var_def_stmt = AnyCastPtr<VarDefNode>(stmt)) {
      var_def_stmt->BuildScope(scope);
    } else if (auto if_stmt = AnyCastPtr<IfStmtNode>(stmt)) {
      if_stmt->BuildScope(scope);
      ret_type.AddRet(if_stmt->ret_type);
    } else if (auto while_stmt = AnyCastPtr<WhileStmtNode>(stmt)) {
      while_stmt->BuildScope(scope);
      ret_type.AddRet(while_stmt->ret_type);
    } else if (auto for_stmt = AnyCastPtr<ForStmtNode>(stmt)) {
      for_stmt->BuildScope(scope);
      ret_type.AddRet(for_stmt->ret_type);
    } else if (auto ret_stmt = AnyCastPtr<ReturnStmtNode>(stmt)) {
      ret_stmt->BuildScope(scope);
      ret_type.AddRet(ret_stmt->ret_type);
    } else if (auto stmt_block = AnyCastPtr<StmtBlockNode>(stmt)) {
      stmt_block->BuildScope(scope);
      ret_type.AddRet(stmt_block->ret_type);
    } else if (auto expr_stmt = AnyCastPtr<ExprStmtNode>(stmt)) {
      expr_stmt->BuildScope(scope);
    }
  }
}
void ExpressionNode::BuildScope(shared_ptr<Scope> _scope) {
  scope = _scope;
  assign_expr->BuildScope(scope);
  value_type = assign_expr->value_type;
}
void AssignExprNode::BuildScope(shared_ptr<Scope> _scope) {
  scope = _scope;
  lor_expr->BuildScope(scope);
  value_type = lor_expr->value_type;
  if (have_left_expr) {
    left_expr->BuildScope(scope);
    auto left_value_type = left_expr->value_type;
    MyAssert(left_value_type.object_leftvalue, "invaild left value");
    MyAssert(value_type.GetObjectType() == left_value_type.GetObjectType(), "different type to assign");
  }
}
void LorExprNode::BuildScope(shared_ptr<Scope> _scope) {
  scope = _scope;
  static const ObjectType correct_type = kBoolType;
  if (land_exprs.size() == 1) {
    land_exprs.front()->BuildScope(scope);
    value_type = land_exprs.front()->value_type;
    return;
  }
  for (auto land_expr : land_exprs) {
    land_expr->BuildScope(scope);
    MyAssert(land_expr->value_type.GetObjectType() == correct_type, "not bool in land expr");
  }
  value_type.SetObjectType(correct_type, false);
}
void LandExprNode::BuildScope(shared_ptr<Scope> _scope) {
  scope = _scope;
  static const ObjectType correct_type = kBoolType;
  if (or_exprs.size() == 1) {
    or_exprs.front()->BuildScope(scope);
    value_type = or_exprs.front()->value_type;
    return;
  }
  for (auto or_expr : or_exprs) {
    or_expr->BuildScope(scope);
    MyAssert(or_expr->value_type.GetObjectType() == correct_type, "not bool in lor expr");
  }
  value_type.SetObjectType(correct_type, false);
}
void OrExprNode::BuildScope(shared_ptr<Scope> _scope) {
  scope = _scope;
  static const ObjectType correct_type = kIntType;
  if (xor_exprs.size() == 1) {
    xor_exprs.front()->BuildScope(scope);
    value_type = xor_exprs.front()->value_type;
    return;
  }
  for (auto xor_expr : xor_exprs) {
    xor_expr->BuildScope(scope);
    MyAssert(xor_expr->value_type.GetObjectType() == correct_type, "not int in or expr");
  }
  value_type.SetObjectType(correct_type, false);
}
void XorExprNode::BuildScope(shared_ptr<Scope> _scope) {
  scope = _scope;
  static const ObjectType correct_type = kIntType;
  if (and_exprs.size() == 1) {
    and_exprs.front()->BuildScope(scope);
    value_type = and_exprs.front()->value_type;
    return;
  }
  for (auto and_expr : and_exprs) {
    and_expr->BuildScope(scope);
    MyAssert(and_expr->value_type.GetObjectType() == correct_type, "not int in xor expr");
  }
  value_type.SetObjectType(correct_type, false);
}
void AndExprNode::BuildScope(shared_ptr<Scope> _scope) {
  scope = _scope;
  static const ObjectType correct_type = kIntType;
  if (equal_exprs.size() == 1) {
    equal_exprs.front()->BuildScope(scope);
    value_type = equal_exprs.front()->value_type;
    return;
  }
  for (auto equal_expr : equal_exprs) {
    equal_expr->BuildScope(scope);
    MyAssert(equal_expr->value_type.GetObjectType() == correct_type, "not int in xor expr");
  }
  value_type.SetObjectType(correct_type, false);
}
void EqualityExprNode::BuildScope(shared_ptr<Scope> _scope) {
  scope = _scope;
  if (relation_exprs.size() == 1) {
    relation_exprs.front()->BuildScope(scope);
    value_type = relation_exprs.front()->value_type;
    return;
  }
  for (auto relation_expr : relation_exprs) {
    relation_expr->BuildScope(scope);
  }
  static const ObjectType correct_type = kBoolType;
  auto iter = relation_exprs.begin();
  auto first_type = (*iter)->value_type.GetObjectType();
  auto second_type = (*(++iter))->value_type.GetObjectType();
  MyAssert(first_type == second_type, "different type equality");
  for (++iter; iter != relation_exprs.end(); ++iter) {
    MyAssert((*iter)->value_type.GetObjectType() == correct_type, "different type equality");
  }
  value_type.SetObjectType(correct_type, false);
}
void RelationExprNode::BuildScope(shared_ptr<Scope> _scope) {
  scope = _scope;
  MyAssert(shift_exprs.size() <= 2, "invaild relation expr : too many exprs");
  if (shift_exprs.size() == 1) {
    shift_exprs.front()->BuildScope(scope);
    value_type = shift_exprs.front()->value_type;
    return;
  }
  shift_exprs.front()->BuildScope(scope);
  shift_exprs.back()->BuildScope(scope);
  auto left_type = shift_exprs.front()->value_type.GetObjectType();
  auto right_type = shift_exprs.back()->value_type.GetObjectType();
  MyAssert(left_type == right_type, "invaild relation expr : different type");
  MyAssert(left_type == kIntType || left_type == kStringType, "invaild relation expr : not vaild type");
  value_type.SetObjectType(kBoolType, false);
}
void ShiftExprNode::BuildScope(shared_ptr<Scope> _scope) {
  scope = _scope;
  static const ObjectType correct_type = kIntType;
  if (add_exprs.size() == 1) {
    add_exprs.front()->BuildScope(scope);
    value_type = add_exprs.front()->value_type;
    return;
  }
  for (auto add_expr : add_exprs) {
    add_expr->BuildScope(scope);
    MyAssert(add_expr->value_type.GetObjectType() == correct_type, "not int in shift expr");
  }
  value_type.SetObjectType(correct_type, false);
}
void AddExprNode::BuildScope(shared_ptr<Scope> _scope) {
  scope = _scope;
  if (multi_exprs.size() == 1) {
    multi_exprs.front()->BuildScope(scope);
    value_type = multi_exprs.front()->value_type;
    return;
  }
  for (auto multi_expr : multi_exprs) {
    multi_expr->BuildScope(scope);
  }
  auto first_type = multi_exprs.front()->value_type.GetObjectType();
  MyAssert(first_type == kIntType || first_type == kStringType, "not int or string in add expr");
  for (auto multi_expr : multi_exprs) {
    MyAssert(multi_expr->value_type.GetObjectType() == first_type, "not same type in add expr");
  }
  value_type.SetObjectType(first_type, false);
}
void MultiExprNode::BuildScope(shared_ptr<Scope> _scope) {
  scope = _scope;
  static const ObjectType correct_type = kIntType;
  if (unary_exprs.size() == 1) {
    unary_exprs.front()->BuildScope(scope);
    value_type = unary_exprs.front()->value_type;
    return;
  }
  for (auto unary_expr : unary_exprs) {
    unary_expr->BuildScope(scope);
    MyAssert(unary_expr->value_type.GetObjectType() == correct_type, "not int in shift expr");
  }
  value_type.SetObjectType(correct_type, false);
}
void UnaryExprNode::BuildScope(shared_ptr<Scope> _scope) {
  scope = _scope;
  if (auto new_expr = AnyCastPtr<NewExprNode>(expr)) {
    new_expr->BuildScope(scope);
    value_type = new_expr->value_type;
  } else if (auto postfix_expr = AnyCastPtr<PostfixExprNode>(expr)) {
    postfix_expr->BuildScope(scope);
    value_type = postfix_expr->value_type;
  }
  for (auto prefix_unary_op : prefix_unary_ops) {
    switch (prefix_unary_op) {
      case kPlusPlus:
      case kMinusMinus:
        MyAssert(value_type.object_leftvalue, "wrong self-crease : not a left value");
        MyAssert(value_type.GetObjectType() == kIntType, "wrong self-crease : not a int value");
        value_type.SetObjectType(kIntType, true);
        break;
      case kTilde:
      case kMinus:

        MyAssert(value_type.GetObjectType() == kIntType, "wrong prefix unary op : not a int value");
        value_type.SetObjectType(kIntType, false);
        break;
      case kNot:
        MyAssert(value_type.GetObjectType() == kBoolType, "wrong not op : not a bool value");
        break;
    }
  }
}
void PostfixExprNode::BuildScope(shared_ptr<Scope> _scope) {
  scope = _scope;
  primary_expr->BuildScope(scope);
  value_type = primary_expr->value_type;
  if (suffix_ops.size() && AnyCastPtr<ArgListNode>(suffix_ops.front())) {
    primary_expr->is_func = true;
  }
  for (auto suffix_op : suffix_ops) {
    if (AnyIs<SuffixUnaryOp>(suffix_op)) {
      MyAssert(value_type.object_leftvalue, "wrong suffix unary op : not left value");
      MyAssert(value_type.GetObjectType() == kIntType, "wrong suffix unary op : not int type");
      value_type.SetObjectType(kIntType, false);
    } else if (AnyIs<Member>(suffix_op)) {
      auto member_op = AnyCast<Member>(suffix_op);
      auto obj_type = value_type.GetObjectType();
      if (obj_type.dim) {
        // array obj
        MyAssert(member_op.member_identifier == "size",
                 "wrong member : array has no member called : \"" + member_op.member_identifier + "\"");
        value_type.SetFuncType({kIntType, {}});
      } else {
        value_type = scope->GetClassMember(obj_type.type_identifier, member_op.member_identifier);
      }
    } else if (auto arg_list_node = AnyCastPtr<ArgListNode>(suffix_op)) {
      arg_list_node->BuildScope(scope);
      auto func_type = value_type.GetFuncType();
      value_type.SetObjectType(func_type.AcceptArgList(arg_list_node->type_list), false);  // todo?
    } else if (auto array_index = AnyCastPtr<ArrayIndexNode>(suffix_op)) {
      array_index->BuildScope(scope);
      auto obj_type = value_type.GetObjectType();
      MyAssert(obj_type.dim, "wrong array index : not a array obj");
      --obj_type.dim;
      value_type.SetObjectType(obj_type, true);
    }
  }
}
void PrimaryExprNode::BuildScope(shared_ptr<Scope> _scope) {
  scope = _scope;
  is_func = false;
  if (auto literal_node = AnyCastPtr<LiteralNode>(expr)) {
    value_type.SetObjectType(literal_node->type, false);
  } else if (AnyIs<This>(expr)) {
    value_type = scope->GetIdentifierType("this");
    value_type.object_leftvalue = false;
  } else if (auto expr_node = AnyCastPtr<ExpressionNode>(expr)) {
    expr_node->BuildScope(scope);
    value_type = expr_node->value_type;
  } else if (AnyIs<string>(expr)) {
    string identifier = AnyCast<string>(expr);
    value_type = scope->GetIdentifierType(identifier);
  } else if (auto lambda_node = AnyCastPtr<LambdaExprNode>(expr)) {
    lambda_node->BuildScope(scope);
    value_type = lambda_node->value_type;
  }
}
void LambdaExprNode::BuildScope(shared_ptr<Scope> _scope) {
  scope = make_shared<Scope>(_scope, !ref);
  args_def->BuildScope(scope);
  body->BuildScope(scope, false);
  MyAssert(body->ret_type.have_ret, "lambda dont have ret");
  value_type.SetFuncType({body->ret_type.type, args_def->GetArgTypeList()});
}
void NewExprNode::BuildScope(shared_ptr<Scope> _scope) {
  scope = _scope;
  if (is_array) {
    for (auto array_idx : array_idxs) {
      array_idx->BuildScope(scope);
    }
  }
  scope->CheckClass(type.type_identifier);
  MyAssert(type.type_identifier != "void", "wrong new : new void");
  value_type.SetObjectType(type, true);
}
void ArrayIndexNode::BuildScope(shared_ptr<Scope> _scope) {
  scope = _scope;
  idx_expr->BuildScope(scope);
  MyAssert(idx_expr->value_type.GetObjectType() == kIntType, "wrong array idx : not int expr");
}
void IfStmtNode::BuildScope(shared_ptr<Scope> _scope) {
  scope = _scope;
  condition_expr->BuildScope(scope);
  MyAssert(condition_expr->value_type.GetObjectType() == kBoolType, "wrong condition expr : not a bool expr");
  block->BuildScope(scope);
  ret_type.AddRet(block->ret_type);
  if (have_else) {
    else_block->BuildScope(scope);
    ret_type.AddRet(else_block->ret_type);
  }
}
void WhileStmtNode::BuildScope(shared_ptr<Scope> _scope) {
  scope = _scope;
  condition_expr->BuildScope(scope);
  MyAssert(condition_expr->value_type.GetObjectType() == kBoolType, "wrong condition expr : not a bool expr");
  block->BuildScope(scope);
  ret_type.AddRet(block->ret_type);
}
void ForStmtNode::BuildScope(shared_ptr<Scope> _scope) {
  scope = _scope;
  if (have_init_expr) {
    init_expr->BuildScope(scope);
    MyAssert(init_expr->value_type.have_object_type, "outside expression must be object");
  }
  if (have_condition_expr) {
    condition_expr->BuildScope(scope);
    MyAssert(condition_expr->value_type.have_object_type, "outside expression must be object");
    MyAssert(condition_expr->value_type.GetObjectType() == kBoolType, "wrong condition expr : not a bool expr");
  }
  if (have_step_expr) {
    step_expr->BuildScope(scope);
    MyAssert(step_expr->value_type.have_object_type, "outside expression must be object");
  }
  block->BuildScope(scope);
  ret_type.AddRet(block->ret_type);
}
void ReturnStmtNode::BuildScope(shared_ptr<Scope> _scope) {
  scope = _scope;
  if (!have_ret_expr) {
    ret_type.AddRet({"void"});
  } else {
    ret_expr->BuildScope(scope);
    MyAssert(ret_expr->value_type.have_object_type, "outside expression must be object");
    ret_type.AddRet(ret_expr->value_type.GetObjectType());
  }
}
void ExprStmtNode::BuildScope(shared_ptr<Scope> _scope) {
  scope = _scope;
  expr->BuildScope(scope);
  MyAssert(expr->value_type.have_object_type, "outside expression must be object");
}
};  // namespace AST