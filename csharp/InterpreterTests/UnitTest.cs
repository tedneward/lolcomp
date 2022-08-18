using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace InterpreterTests;

using System;
using System.Collections.Generic;
using Antlr4.Runtime;
using Antlr4.Runtime.Misc;
using Antlr4.Runtime.Tree;
using LOLCODEParser;
using Interpreter;

[TestClass]
public class UnitTest
{
    public TestContext TestContext { get; set; }

    class OpeningInterpreter : lolcodeBaseListener {
        public OpeningInterpreter() {
            System.Console.WriteLine("Opening");
        }
        public override void ExitProgram(lolcodeParser.ProgramContext ctx) {
            var opening = ctx.opening();
            var version = opening.version();
            System.Console.WriteLine("{0}: {1}", opening, version);
        }
    }
    [TestMethod]
    public void TestOpening()
    {
        var code = "HAI 1.2\nKTHXBYE";

        System.Console.WriteLine("Parsing **{0}**", code);

        lolcodeLexer lexer = new lolcodeLexer(CharStreams.fromString(code));
        CommonTokenStream tokens = new CommonTokenStream(lexer);
        lolcodeParser parser = new lolcodeParser(tokens);
        var parseTree = parser.program();
        ParseTreeWalker walker = new ParseTreeWalker();
        walker.Walk(new OpeningInterpreter(), parseTree);
    }
}
