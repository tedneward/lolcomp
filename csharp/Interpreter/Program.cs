namespace Interpreter;

using System.Collections.Generic;
using System.IO;
using Antlr4.Runtime;
using Antlr4.Runtime.Misc;
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
    public CodeBlock CodeBlock 
    { 
        // By definition the code_block is the first child of program (if present)
        get { return Children.Count > 0 ? (CodeBlock)Children[0] : null; }
    }

    public override string ToString()
    {
        return String.Format("(program version:{0} code_block:{1})", 
            Version, CodeBlock != null ? CodeBlock.ToString() : "()");
    }
}
public class CodeBlock : ASTNode
{ }
public class Declaration : ASTNode
{
    public string Name { get; set; } = "";
    public string InitialValue { get; set; } = "";
    public override string ToString() { return String.Format("(decl {0} {1})", Name, InitialValue); }
}
public class Label : ASTNode
{
    public string Name { get; set; }
    public Label() { Name = ""; }
    public override string ToString() { return String.Format("(LABEL {0})", Name); }
}
public class Atom : ASTNode
{
    public string Value { get; set; } = "";
    public override string ToString() { return String.Format("(ATOM {0})", Value); }
}
public class PrintExpr : ASTNode
{ 
    public override string ToString() { return String.Format("(print {0})", base.ToString()); }
}


public class ASTBuilder : lolcodeBaseListener
{
    public ASTBuilder() { }

    public Program program = new Program();
    public Stack<CodeBlock> currentBlock = new Stack<CodeBlock>();

    override public void EnterProgram(lolcodeParser.ProgramContext ctx) 
    {
        if (ctx.opening().version() != null)
            program.Version = ctx.opening().version().GetText();
        else
            program.Version = "1.2"; // Assume latest
    }

    override public void EnterCode_block(lolcodeParser.Code_blockContext ctx)
    {
        CodeBlock cb = new CodeBlock();

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
        Declaration decl = new Declaration();

        decl.Name = ctx.LABEL().GetText();
        if (ctx.expression() != null)
            decl.InitialValue = ctx.expression().GetText();

        currentBlock.Peek().Children.Add(decl);
    }

    override public void EnterPrint_block(lolcodeParser.Print_blockContext ctx)
    {
        PrintExpr print = new PrintExpr();

        foreach (var expr in ctx.expression())
        {
            if (expr.ATOM() != null)
            {
                print.Children.Add(new Atom() { Value = expr.ATOM().GetText() });
            }
            else if (expr.LABEL() != null)
            {
                print.Children.Add(new Label() { Name = expr.LABEL().GetText() });
            }
            else
            {
                throw new Exception("Unrecognized child of print_block " + expr);
            }
        }

        currentBlock.Peek().Children.Add(print);
    }
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
    public void RunCodeBlock(CodeBlock block)
    {
        // Nothing to do for empty code blocks
        if (block == null || block.Children.Count == 0)
            return;

        var variables = new Dictionary<string, object>();
        foreach (var node in block.Children)
        {
            if (node is Declaration) 
            {
                var decl = (Declaration)node;
                variables[decl.Name] = decl.InitialValue;
            }
            else if (node is PrintExpr)
            {
                var print = (PrintExpr)node;
                var message = "";
                foreach (var expr in print.Children)
                {
                    if (expr is Atom)
                    {
                        var value = ((Atom)expr).Value;
                        if (value.StartsWith("\""))
                        {
                            // It's a literal string, with quotes, which we must strip off
                            value = value.Trim('"');
                        }
                        message += value;
                    }
                    else if (expr is Label)
                    {
                        message += variables[((Label)expr).Name].ToString();
                    }
                    else
                        throw new Exception("Unrecognized expr: " + expr);
                }
                Out.WriteLine(message);
            }
            else if (node is CodeBlock)
            {
                RunCodeBlock((CodeBlock)node);
            }
            else
            {
                throw new Exception("Unrecognized node: " + node);
            }
        }
    }
}