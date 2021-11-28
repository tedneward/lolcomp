using Antlr4.Runtime;
using Microsoft.VisualStudio.TestTools.UnitTesting;

using LOLParser;

namespace LOLParser.Tests
{

    [TestClass]
    public class ASTUnitTests
    {
        [TestMethod]
        public void HelloWorld()
        {
            var lolcode = "HAI 1.2 VISIBLE \"Hello world\" KTHXBYE";
            var asterizer = new ASTerizer();
            asterizer.Parse(lolcode);
            var program = asterizer.program;
            
            Assert.AreEqual(Program.Ver.V12, program.Version);
        }
    }
    
}