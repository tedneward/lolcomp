using Antlr4.Runtime;
using Microsoft.VisualStudio.TestTools.UnitTesting;

using LOLParser;

namespace LOLParser.Tests
{
    [TestClass]
    public class ParserUnitTests
    {
        static lolcodeParser.ProgramContext Parse(string lolcode)
        {
            var inputStream = new AntlrInputStream(lolcode);
            var lexer = new lolcodeLexer(inputStream);
            var tokenStream = new CommonTokenStream(lexer);
            var parser = new lolcodeParser(tokenStream);

            return parser.program();
        }
        
        [TestMethod]
        public void CanInstantiateParser()
        {
            var text = "HAI 1.2";
            var program = Parse(text);
            Assert.AreEqual("HAI 1.2", program.opening().GetText());
        }
        [TestMethod]
        // ReSharper disable once InconsistentNaming
        // ReSharper disable once IdentifierTypo
        public void CanReadBothHAIandKTHXBYE()
        {
            var text = "HAI 1.2 KTHXBYE";
            var program = Parse(text);
            Assert.AreEqual("HAI 1.2", program.opening().GetText());
        }

        [TestMethod]
        public void SingleLineCommentsShouldWork()
        {
            var text = "HAI 1.2\n" +
                       "BTW this is a comment\n" +
                       "KTHXBYE";
            var program = Parse(text);
            var code_block = program.code_block();
            var statement = code_block.GetChild(0);
            Assert.IsInstanceOfType(statement, typeof(lolcodeParser.StatementContext));
            var comment = statement.GetChild(0);
            Assert.IsInstanceOfType(comment, typeof(lolcodeParser.CommentContext));
        }
        [TestMethod]
        public void MultiLineCommentsShouldWork()
        {
            var text = "HAI 1.2\n" +
                       "OBTW\n" +
                       "this is a comment too\n" +
                       "TLDR\n" +
                       "KTHXBYE";
            var program = Parse(text);
            var code_block = program.code_block();
            var statement = code_block.GetChild(0);
            Assert.IsInstanceOfType(statement, typeof(lolcodeParser.StatementContext));
            var comment = statement.GetChild(0);
            Assert.IsInstanceOfType(comment, typeof(lolcodeParser.CommentContext));
        }

    }
}
