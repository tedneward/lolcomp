namespace Interpreter;

using System.Collections.Generic;
using Antlr4.Runtime;
using Antlr4.Runtime.Tree;
using LOLCODEParser;

public class ASTNode
{
    public List<ASTNode> Children { get; private set; } = new List<ASTNode>();
    public override string ToString()
    {
        string listrep = "children:(";
        Children.ForEach( (node) => { listrep += node.ToString(); } );
        return listrep + ")";
    }
}
public class Program : ASTNode
{
    public string Version { get; set; } = "";
    public CodeBlockAST CodeBlock 
    { 
        // By definition the code_block is the first child of program (if present)
        get { return Children.Count > 0 ? (CodeBlockAST)Children[0] : null; }
    }

    public override string ToString()
    {
        return String.Format("(program version:{0} code_block:{1})", 
            Version, CodeBlock != null ? CodeBlock.ToString() : "()");
    }
}
public class CodeBlockAST : ASTNode
{ }
public class StatementAST : ASTNode { }
public class ExpressionAST : StatementAST { }
public class DeclarationAST : StatementAST
{
    public string Name { get; set; } = "";
    public string InitialValue { get; set; } = "";
    public override string ToString() { return String.Format("(decl {0} {1})", Name, InitialValue); }
}
public class LabelAST : ExpressionAST
{
    public string Name { get; set; } = "";
    public override string ToString() { return String.Format("(LABEL {0})", Name); }
}
public class AtomAST : ExpressionAST
{
    public string Value { get; set; } = "";
    public override string ToString() { return String.Format("(ATOM {0})", Value); }
}
public class PrintExprAST : StatementAST
{ 
    public override string ToString() { return String.Format("(print {0})", base.ToString()); }
}
public class InputAST : StatementAST
{
    public string Label { get; set; } = "";
    public override string ToString() { return String.Format("(input {0})", Label); }
}
public class AssignmentAST : ExpressionAST
{
    public string Label { get; set; } = "";
    public ExpressionAST Expr { get; set; } = new ExpressionAST();
    public override string ToString() { return String.Format("(assign {0} = {1})", Label, Expr); }
}


public class ASTBuilder : lolcodeBaseListener
{
    public ASTBuilder() { }

    public Program program = new Program();
    public Stack<CodeBlockAST> currentBlock = new Stack<CodeBlockAST>();

    override public void EnterProgram(lolcodeParser.ProgramContext ctx) 
    {
        if (ctx.opening().version() != null)
            program.Version = ctx.opening().version().GetText();
        else
            program.Version = "1.2"; // Assume latest
    }

    override public void EnterCode_block(lolcodeParser.Code_blockContext ctx)
    {
        CodeBlockAST cb = new CodeBlockAST();

        // Are we at the very first code block?
        if (currentBlock.Count == 0)
        {
            program.Children.Add(cb);
        }
        // If not, we must have a CodeBlock already
        else
        {
            currentBlock.Peek().Children.Add(cb);
        }

        currentBlock.Push(cb);
    }
    override public void ExitCode_block(lolcodeParser.Code_blockContext ctx)
    {
        currentBlock.Pop();
    }

    override public void EnterDeclaration(lolcodeParser.DeclarationContext ctx)
    {
        var decl = new DeclarationAST();

        decl.Name = ctx.LABEL().GetText();
        if (ctx.expression() != null)
            decl.InitialValue = ctx.expression().GetText();

        currentBlock.Peek().Children.Add(decl);
    }

    override public void EnterPrint_block(lolcodeParser.Print_blockContext ctx)
    {
        var print = new PrintExprAST();

        foreach (var expr in ctx.expression())
        {
            if (expr.ATOM() != null)
            {
                print.Children.Add(new AtomAST() { Value = expr.ATOM().GetText() });
            }
            else if (expr.LABEL() != null)
            {
                print.Children.Add(new LabelAST() { Name = expr.LABEL().GetText() });
            }
            else
            {
                throw new Exception("Unrecognized child of print_block " + expr);
            }
        }

        currentBlock.Peek().Children.Add(print);
    }
}

// LOLCODE types can be strings, int64s, float64s, bools, or "untyped"
public class Variant
{
    private object? value;
    private Type type;

    public Variant() { value = null; type = typeof(void); }
    public Variant(bool bVal) { value = bVal; type = typeof(bool); }
    public Variant(Int64 lVal) { value = lVal; type = typeof(long); }
    public Variant(Double dVal) { value = dVal; type = typeof(double); }
    public Variant(String sVal) { value = sVal; type = typeof(string); }

    private void UntypedCheck() { if (type == typeof(void)) throw new Exception("Cannot cast from an Untyped value"); }
    public bool AsBool() { UntypedCheck(); return Boolean.Parse(value.ToString()); }
    public Int64 AsInt() { UntypedCheck(); return Int64.Parse(value.ToString()); }
    public Double AsDouble() { UntypedCheck(); return Double.Parse(value.ToString()); }
    public String AsString() { UntypedCheck(); return value.ToString(); }
}

public class Interpreter
{
    public System.IO.TextWriter Out { get; set; }
    public System.IO.TextReader In { get; set; }

    public Interpreter()
    {
        Out = System.Console.Out;
        In = System.Console.In;
    }

    public void Execute(string code)
    {
        System.Console.WriteLine("Executing {0}", code);

        lolcodeLexer lexer = new lolcodeLexer(CharStreams.fromString(code));
        CommonTokenStream tokens = new CommonTokenStream(lexer);
        lolcodeParser parser = new lolcodeParser(tokens);
        var builder = new ASTBuilder();
        ParseTreeWalker.Default.Walk(builder, parser.program());
        System.Console.WriteLine("AST: {0}", builder.program.ToString());

        Run(builder.program);
    }

    public void Run(Program program)
    {
        RunCodeBlock(program.CodeBlock);
    }
    public void RunCodeBlock(CodeBlockAST block)
    {
        // Nothing to do for empty code blocks
        if (block == null || block.Children.Count == 0)
            return;

        var variables = new Dictionary<string, object>();
        foreach (var node in block.Children)
        {
            if (node is DeclarationAST) 
            {
                var decl = (DeclarationAST)node;
                variables[decl.Name] = decl.InitialValue;
            }
            else if (node is PrintExprAST)
            {
                var print = (PrintExprAST)node;
                var message = "";
                foreach (var expr in print.Children)
                {
                    if (expr is AtomAST)
                    {
                        var value = ((AtomAST)expr).Value;
                        if (value.StartsWith("\""))
                        {
                            // It's a literal string, with quotes, which we must strip off
                            value = value.Trim('"');
                        }
                        message += value;
                    }
                    else if (expr is LabelAST)
                    {
                        message += variables[((LabelAST)expr).Name].ToString();
                    }
                    else
                        throw new Exception("Unrecognized expr: " + expr);
                }
                Out.WriteLine(message);
            }
            else if (node is CodeBlockAST)
            {
                RunCodeBlock((CodeBlockAST)node);
            }
            else
            {
                throw new Exception("Unrecognized node: " + node);
            }
        }
    }
}