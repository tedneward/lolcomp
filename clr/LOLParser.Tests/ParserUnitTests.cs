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
            Assert.AreEqual("HAI", program.children[0].GetText());
        }
        [TestMethod]
        // ReSharper disable once InconsistentNaming
        // ReSharper disable once IdentifierTypo
        public void CanReadBothHAIandKTHXBYE()
        {
            var text = "HAI 1.2 KTHXBYE";
            var program = Parse(text);
            Assert.AreEqual("HAI", program.children[0].GetText());
        }

        [TestMethod]
        public void SingleLineCommentsShouldWork()
        {
            
        }
    }
}
