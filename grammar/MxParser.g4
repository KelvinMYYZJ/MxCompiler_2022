parser grammar MxParser;
options {
	tokenVocab = MxLexer;
}
prog: (definition)* EOF;
definition: funcDef | varDef | classDef;
varDef: typeName singleVarDef ( Comma singleVarDef)*? Semi;

singleVarDef: Identifier (Assign expression)?;

classDef: Class Identifier classBody Semi;
classBody: LeftBrace memberStmt* RightBrace;

funcDef: typeName Identifier argListDef stmtBlock;
argListDef:
	LeftParen (typeName Identifier (Comma typeName Identifier)*?)? RightParen;
argList:
	LeftParen (expression (Comma expression)*?)? RightParen;
constructFuncDef: Identifier LeftParen RightParen stmtBlock;

typeName: basicType (LeftBracket RightBracket)*;
basicType: Int | Bool | String | Void | Identifier;
stmtBlock: LeftBrace funcStmt* RightBrace;
expression: assignExpr;
assignExpr: orOrExpr ( Assign orOrExpr)?;
orOrExpr: andAndExpr (OrOr andAndExpr)*;
andAndExpr: orExpr (AndAnd orExpr)*;
orExpr: xorExpr (Or xorExpr)*;
xorExpr: andExpr (Caret andExpr)*;
andExpr: equalityExpr (And equalityExpr)*;
equalityExpr: relationExpr (equalOp relationExpr)*;
relationExpr: shiftExpr (relationOp shiftExpr)*;

shiftExpr: addExpr (shiftOp addExpr)*;
addExpr: multiExpr (addOp multiExpr)*;
multiExpr: unaryExpr (multiOp unaryExpr)*;
unaryExpr: postfixExpr | prefixUnaryOp unaryExpr | newExpr;
postfixExpr:
	primaryExpr
	| postfixExpr arrayIndex
	| postfixExpr argList
	| postfixExpr Dot Identifier
	| postfixExpr suffixUnaryOp;
primaryExpr:
	literal
	| This
	| LeftParen expression RightParen
	| Identifier
	| lambdaExpr /* todo? */;
lambdaExpr:
	LeftBracket And? RightBracket argListDef Arrow stmtBlock;
newExpr: newArrayExpr | newObjExpr;
newArrayExpr:
	New basicType (arrayIndex+ (LeftBracket RightBracket)*);
newObjExpr: New basicType (LeftParen RightParen)?;

arrayIndex: LeftBracket expression RightBracket;
equalOp: Equal | NotEqual;
relationOp: Less | Greater | LessEqual | GreaterEqual;
shiftOp: LeftShift | RightShift;
addOp: Plus | Minus;
multiOp: Star | Div | Mod;
prefixUnaryOp: PlusPlus | MinusMinus | Not | Tilde | Minus;
suffixUnaryOp: PlusPlus | MinusMinus;

literal:
	IntLiteral
	| True
	| False
	| NullLiteral
	| StringLiteral;
funcStmt:
	varDef
	| ifStmt
	| whileStmt
	| forStmt
	| returnStmt
	| breakStmt
	| continueStmt
	| exprStmt
	| stmtBlock
	| blankStmt;
ifStmt: If condition block elseStmt?;
elseStmt: Else block;
whileStmt: While condition block;
forStmt: For forCondition block;
memberStmt: varDef | constructFuncDef | funcDef;
leftValue:
	Identifier
	| leftValue arrayIndex
	| leftValue Dot Identifier /*todo? */;

condition: LeftParen expression RightParen;
forCondition:
	LeftParen init_expr = expression? Semi condition_expr = expression? Semi step_expr = expression?
		RightParen;
block: stmtBlock | funcStmt;

returnStmt: Return expression? Semi;
breakStmt: Break Semi;
continueStmt: Continue Semi;
exprStmt: expression Semi;
blankStmt: Semi;