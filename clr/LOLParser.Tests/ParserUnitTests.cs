using Antlr4.Runtime;
using Microsoft.VisualStudio.TestTools.UnitTesting;

using LOLParser;

namespace LOLParser.Tests
{
    [TestClass]
    public class ParserUnitTests
    {
        [TestMethod]
        public void CanInstantiateParser()
        {
            var expression = "HAI 1.3";
 
            var inputStream = new AntlrInputStream(expression);
            var lexer = new lolcodeLexer(inputStream);
            var tokenStream = new CommonTokenStream(lexer);
            var parser = new lolcodeParser(tokenStream);

            var program = parser.program();
            Assert.AreEqual("HAI", program.children[0].GetText());
            Assert.AreEqual("1.3", program.children[1].GetText());
        }
        [TestMethod]
        public void CanReadBothHAIandKTHXBYE()
        {
            var expression = "HAI 1.3\nKTHXBYE";
 
            var inputStream = new AntlrInputStream(expression);
            var lexer = new lolcodeLexer(inputStream);
            var tokenStream = new CommonTokenStream(lexer);
            var parser = new lolcodeParser(tokenStream);

            var program = parser.program();
            Assert.AreEqual("HAI", program.children[0].GetText());
            Assert.AreEqual("1.3", program.children[1].GetText());
            Assert.AreEqual("KTHXBYE", program.children[2].GetText());
        }
    }
}
