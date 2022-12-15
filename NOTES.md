# NOTES
Random collection of thoughts about this project, some or many of which may turn into other projects or refactoring efforts.

## Generic AST
Feels like a lot of procedural or object-procedural languages have a very similar AST--might be worthwhile to generalize that and use that as a source for back-end processing (interpreter, transpiler, compiler) agents.

References:
* Fantom: https://fantom.org/doc/compiler/index


```
Node: base class for all AST nodes
+-- Block: list of zero or more Stmts
+-- Case: a single case block of a SwitchStmt
+-- Catch: a single catch clause of a TryStmt
+-- CompilationUnit: models the top-level compilation unit of a source file
+-- DefNode: base class for definition nodes such as TypeDef, MethodDef, FieldDef. All definitions may be documented using a Javadoc style FanDoc comment
    +-- SlotDef: models a slot definition - a FieldDef or a MethodDef
        +-- FieldDef: models a field definition
        +-- MethodDef: models a method definition - its signature and body
+-- DocDef: type or slot documentationin plain text FanDoc format
+-- EnumDef: used to define one ordinal/named enum value in an enum TypeDef
+-- Expr: Expression (yields a value)
    +-- BinaryExpr: binary expressions with lhs and rhs including assignment
    +-- ClosureExpr: an "inlined anonymous method" which closes over its lexical scope
    +-- ComplexLiteral: used to model a serialized complex object declared in facets
    +-- CondExpr: ued for || and && short-circuit boolean conditionals
    +-- LiteralExpr: puts a Bool, Int, Float, Str, Duration, Uri or null constant onto the stack
    +-- LocalVarExpr: access a local variable stored in a register
    +-- MapLiteralExpr: creates a List instance
    +-- NameExpr: base class for an identifier expression which has an optional base expression
        +-- CallExpr: a method call
            +-- ShortcutExpr: used for operator expressions which are a shortcut to a method call
        +-- FieldExpr: used for field variable access
    +-- RangeLiteralExpr: creates a Range instance
    +-- SuperExpr: used to access superclass slots
    +-- TernaryExpr: used for ? : conditionals
    +-- ThisExpr: models the "this" keyword to access the implicit this local variable
+-- ParamDef: models the definition of a method parameter
+-- Stmt: Statement (no value)
    +-- BreakStmt
    +-- ContinueStmt: continues a while/for loop
    +-- ExprStmt: statement with a standalone expression such as assignment or method call
    +-- ForStmt: models a for loop of te format "for (init; condition; update) block"
    +-- IfStmt: modles an if or if/else statement
    +-- LocalDefStmt: models a local variable declaration and its optional initialization expression
    +-- NopStmt: do nothing statement
    +-- ReturnStmt: returns from the method
    +-- SwitchStmt:
    +-- ThrowStmt:
    +-- TryStmt:
    +-- WhileStmt:
```