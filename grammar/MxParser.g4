parser grammar MxParser;
options {
	tokenVocab = MxLexer;
}
prog: (definition)* EOF;
definition: funcDef | varDef | classDef;
varDef:
	typeName Identifier (Equal expression)? (
		Comma Identifier (Equal expression)?
	)*? Semi;

classDef: Class Identifier classBody Semi;
classBody: LeftBrace memberStmt* RightBrace;

funcDef: typeName Identifier argListDef funcBody;
argListDef:
	LeftParen (typeName Identifier (Comma typeName Identifier)*?)? RightParen;
argList:
	LeftParen (expression (Comma expression)*?)? RightParen;
constructFuncDef: Identifier LeftParen RightParen funcBody;

typeName:
	basicType (LeftBracket RightBracket)*;
basicType: Int | Bool | String | Void|Identifier;
funcBody: LeftBrace funcStmt* RightBrace;
expression: assignExpr | orOrExpr;
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
	| Identifier /* todo? */;
newExpr: New typeName arrayIndex;
newExprTest: newExpr EOF;

arrayIndex: LeftBrace expression RightBrace;

equalOp: Equal | NotEqual;
relationOp: Less | Greater | LessEqual | GreaterEqual;
shiftOp: LeftShift | RightShift;
addOp: Plus | Minus;
multiOp: Star | Div | Mod;
prefixUnaryOp: PlusPlus | MinusMinus | Not | Tilde | Minus;
suffixUnaryOp: PlusPlus | MinusMinus;

literal: IntLiteral | BoolLiteral | NullLiteral | StringLiteral;
funcStmt:
	varDef
	| ifStmt
	| whileStmt
	| forStmt
	| returnStmt
	| breakStmt
	| continueStmt
	| exprStmt;
ifStmt: If condition block elseStmt?;
elseStmt: Else block;
whileStmt: While condition block;
forStmt: For forCondition block;
memberStmt: varDef | constructFuncDef | funcDef;
assignExpr: leftValue Equal expression;
leftValue:
	Identifier
	| leftValue arrayIndex
	| leftValue Dot Identifier /*todo? */;

exprTest: expression EOF;
condition: LeftParen expression RightParen;
forCondition:
	LeftParen Semi expression Semi expression RightParen;
block: multiStmtBlock | funcStmt;
multiStmtBlock: LeftBrace funcStmt*? RightBrace;

returnStmt: Return expression? Semi;
breakStmt: Break Semi;
continueStmt: Continue Semi;
exprStmt: expression Semi;