namespace Interpreter;

using System.Collections.Generic;
using Antlr4.Runtime;
using Antlr4.Runtime.Misc;
using Antlr4.Runtime.Tree;
using LOLCODEParser;

public class Interpreter : lolcodeBaseListener
{
    public Interpreter() 
    {
    }

    override public void EnterProgram(lolcodeParser.ProgramContext ctx) 
    {
    }

    override public void EnterDeclaration(lolcodeParser.DeclarationContext ctx)
    {
    }

    override public void ExitProgram(lolcodeParser.ProgramContext ctx) 
    {
    }
}
