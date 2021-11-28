using System;
using System.Collections.Generic;
using Antlr4.Runtime;
using Antlr4.Runtime.Misc;

namespace LOLParser
{
    public class ASTerizer : lolcodeBaseVisitor<object>
    {
        public void Parse(string lolcode)
        {
            var inputStream = new AntlrInputStream(lolcode);
            var lexer = new lolcodeLexer(inputStream);
            var tokenStream = new CommonTokenStream(lexer);
            var parser = new lolcodeParser(tokenStream);

            Visit(parser.program());
        }
        
        public Program program { get; set; }
        public List<Statement> currentContext { get; set; }
        public override object VisitProgram([NotNull] lolcodeParser.ProgramContext context)
        {
            program = new Program();
            var text = context.opening().GetText();
            switch (text)
            {
                case "HAI 1.0": 
                    program.Version = Program.Ver.V10;
                    break;
                case "HAI 1.1":
                    program.Version = Program.Ver.V11;
                    break;
                case "HAI 1.2":
                    program.Version = Program.Ver.V12;
                    break;
                default:
                    throw new Exception("Unrecognized LOLCODE version: " + text);
            }

            currentContext = program.Statements;
            return VisitChildren(context);
        }
        
        
    }
    
    public class Program
    {
        public Program()
        {
            Statements = new List<Statement>(); 
        }
        
        public enum Ver
        {
            V10, V11, V12
        }
        
        public Ver Version { get; set; }
        
        public List<Statement> Statements { get; private set; }

        public void Evaluate()
        {
            foreach (var stmt in Statements)
            {
                stmt.Eval();
            }
        }
    }

    public abstract class Statement
    {
        public abstract void Eval();
    }

    public class CodeBlock : Statement
    {
        public CodeBlock()
        {
            Statements = new List<Statement>(); 
        }
        
        public List<Statement> Statements { get; set; }
        public override void Eval()
        {
            
        }
    }

    public class Comment : Statement
    {
        public Comment(string text)
        {
            Text = text;
        }
        
        public string Text { get; set; }
        
        public override void Eval() { }
    }
    
}

