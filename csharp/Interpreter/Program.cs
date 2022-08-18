namespace Interpreter;

using System.Collections.Generic;
using Antlr4.Runtime;
using Antlr4.Runtime.Misc;
using Antlr4.Runtime.Tree;
using LOLCODEParser;

class Environment
{
    public Environment() { Variables = new Dictionary<string, object>(); }

    public Dictionary<string, object> Variables { get; private set; }

    public string ToString() {
        return String.Format("Environment { Variables: {0} }", Variables);
    }
}

class ASTNode
{
}

class Program
{
    public string Version { get; set; }
    public List<ASTNode> Statements { get; set; }
}

public class Interpreter : lolcodeBaseListener
{
    Environment env = new Environment();

    override public void EnterProgram(lolcodeParser.ProgramContext ctx) {
    }
    override public void ExitProgram(lolcodeParser.ProgramContext ctx) {      
    }
}
