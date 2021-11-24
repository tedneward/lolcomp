using Microsoft.VisualStudio.TestTools.UnitTesting;

using LOLParser;

namespace LOLParser.Tests
{
    [TestClass]
    public class BaseUnitTests
    {
        [TestMethod]
        public void VerifyLibraryVersion()
        {
            Assert.AreEqual(0, Library.MajorVersion);
            Assert.AreEqual(1, Library.MinorVersion);
            Assert.AreEqual("0.1.0", Library.Version);
        }
    }
}
