namespace Interpreter;

using System.Collections.Generic;
using Antlr4.Runtime;
using Antlr4.Runtime.Misc;
using Antlr4.Runtime.Tree;
using LOLCODEParser;

public class ASTNode
{
    public List<ASTNode> Children { get; private set; }
    public ASTNode() { Children = new List<ASTNode>(); }
}
public class Program : ASTNode
{
    public string Version { get; set; }
    public CodeBlock CodeBlock 
    { 
        // By definition the code_block is the first child of program (if present)
        get { return Children.Count > 0 ? (CodeBlock)Children[0] : null; }
    }
    public Program() { Version = ""; }
}
public class CodeBlock : ASTNode
{ }
public class Declaration : ASTNode
{
    public string Name { get; set; }
    public object Value { get; set; }
    public Declaration() { Name = ""; Value = ""; }
}


public class ASTBuilder : lolcodeBaseListener
{
    public ASTBuilder() { }

    public Program program = new Program();
    public Stack<CodeBlock> currentBlock = new Stack<CodeBlock>();

    override public void EnterProgram(lolcodeParser.ProgramContext ctx) 
    {
        program.Version = ctx.opening().version().GetText();
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
        decl.Value = ctx.expression().GetText();

        currentBlock.Peek().Children.Add(decl);
    }
}
