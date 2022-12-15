namespace GAST;

/*
 * Basic procedures (variables, procedures)
 * Basic OO types (classes w/fields, methods)
 * Exception-handling
 * 
 * Custom operators ?
 * Overloaded operators ?
 */

/* ----------------------------------------------
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
   ---------------------------------------------- */

/*
 * Base class for all GAST classes.
 */
public abstract class Node
{
    public Node() { }

    // Source file relationship
    //
    public string File { get; set; } = "";
    public int Line { get; set; } = 0;
    public int ColStart { get; set; } = 0;
    public int ColEnd { get; set; } = 0;
}

/*
 * Module represents a compilation unit
 */
public class Module : Node
{
    public Module() { }

    public List<Statement> Statements { get; } = new List<Statement>();
}

/*
 * Statement 
 */
public abstract class Statement : Node
{
    public Statement() { }
}

/*
 * Expr is an expression type--it yields a value.
 */
public abstract class Expression : Statement
{
    public Expression() { }
}

public class Variable : Expression
{
    public Variable(string name) { Name = name; }

    public string Name { get; }
}

public class Block : Expression
{
    public Block() { }

    public List<Statement> Statements { get; } = new List<Statement>();
}

public class Condition : Expression
{
    public Condition(Expression cond, Block block) { Test = cond; Block = block; }

    public Expression Test { get; }
    public Block Block { get; }
}

/*
 * Literal represents a source-present literal, like "4" or "'Fred Jones'"
 * in the source code.
 */
public class Literal : Expression
{
    public Literal(string literal) { SourceValue = literal; }

    // The literal as written in the source
    public string SourceValue { get; } = "";
}
// Could/would have subclasses of Literal that correspond
// to the core primitive types of the language: CharLiteral, 
// StringLiteral, IntLiteral, FloatLiteral, BoolLiteral
// NullLiteral?

/*
 * Operators that take two operands to perform their operation.
 */
public class BinaryOperator : Expression
{
    public BinaryOperator(Expression l, Expression r) { Left = l; Right = r; }

    public Expression Left { get; set; }
    public Expression Right { get; set; }
}
public class AdditionOperator : BinaryOperator
{
    public AdditionOperator(Expression left, Expression right) : base(left, right) { } 
}
public class SubtractionOperator : BinaryOperator
{
    public SubtractionOperator(Expression left, Expression right) : base(left, right) { } 
}
public class MultiplicationOperator : BinaryOperator
{
    public MultiplicationOperator(Expression left, Expression right) : base(left, right) { } 
}
public class DivisionOperator : BinaryOperator
{
    public DivisionOperator(Expression left, Expression right) : base(left, right) { } 
}
public class ModuloOperator : BinaryOperator
{
    public ModuloOperator(Expression left, Expression right) : base(left, right) { } 
}
// Comparisons: GTOp, GTEOp, LTOp, LTEOp, EqualsOp, NotEqualsOp
public class AssignmentOperator : BinaryOperator
{
    public AssignmentOperator(Variable l, Expression r) : base(l, r) { }
}

public class UnaryOperator : Expression
{
    public UnaryOperator(Expression e) { Unary = e; }

    public Expression Unary { get; set; }
}
// NegationOp (-5), NotOp (!x)



