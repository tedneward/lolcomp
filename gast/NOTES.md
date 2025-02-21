# Notes for the Generic Abstract Syntax Tree (GAST)

Might need a different acronym; is it really a "syntax" tree if it's not necessarily tied to syntax?

Thinking that an s-expr form might be the best way to ingest/express these, if not building directly out of code.

Notes doc from up a level has this breakdown from Fantom:
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

So let's work with that, and build out something that's not quite so tightly tied to syntax:

Steps/future work

* Basic procedures (variables, procedures)
* Basic OO types (classes w/fields, methods)
* Exception-handling

* Custom operators ?
* Overloaded operators ?


```
**Node**: base AST node
+-- **Block**: collection of Expressions; yields a value; holds an associated Scope
+-- **Expression**: singular; yields a value
    +-- **LiteralExpression**: constant value recognized at parse-time; actual syntax depends on primitives
    +-- **BinaryExpression**: single-operation expression taking two operands (add, subtract, &&, ||, etc)
    +-- **UnaryExpression**: single-operation expression taking one operand (negation, absolute-value, etc)
    +-- **BindingExpression**: bind value to name in symbol table; returns value of assigned value
    +-- **SymbolExpression**: reference a name stored in the symbol table chain *Should symbol name be a Literal value, or something that's not potentially primitive-based?
    +-- **IfExpression**: conditional evaluation/execution; consists of condition, true-Block, false-Block; return value = executed Block value
    +-- **MatchExpression**: pattern-match; consists of collection of condition + Block pairs; returns executed Block value
    +-- **LoopExpression**: conditional block execution; consists of condition, Block; return = collection value containing each value returned by the executed Block
    +-- **FunctionExpression**: function definition; optional name, arguments, block; return = executed Block value
+-- **Identifier**: a name within the code
+-- **TypeDefinition**?: base for defining new types?
    +-- **ClassDef**?

**SymbolTable**: a single-level mapping of names/symbols to current values

**Scope**: a collection of ordered SymbolTables, providing "prioritized binding" (local variable scope before class scope before global scope, and so on)
```

Let's play this out some:

Add 2 and 2
```
<Binary>
    <Add>
        <Literal>2</>
        <Literal>2</>
    </>
</>
```

Add x and y, each holding a value
```
<Block>
    <Binding> <Identifier>x</> <Literal>2</> </>
    <Binding> <Identifier>y</> <Literal>2</> </>
    <Binary>
        <Add>
            <Symbol> <Identifier>x</> />
            <Symbol> <Identifier>y</> />
        </>
    </>
</>
```

Define add, call it
```
<Block>
    <Function arguments="lhs, rhs">
        <Identifier>add</>
        <Block>
            <Binary>
                <Add>
                    <Symbol> <Identifier>lhs</> />
                    <Symbol> <Identifier>rhs</> />
                </>
            </>
        <Block>
    </>
    <Binding> <Identifier>x</> <Literal>2</> </>
    <Binding> <Identifier>y</> <Literla>3</> </>
    <Call>
        <Identifier>add</> <!-- how do we reference function literals? -->
        <Symbol> <Identifier>x</> />
        <Symbol> <Identifier>y</> />
    </>
</>
```






