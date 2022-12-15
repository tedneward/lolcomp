using Xunit;
using GAST;

namespace GASTTest;

public class SimpleTests
{
    [Fact]
    public void LiteralTest()
    {
        var lit1 = new GAST.Literal("1");
        var litName = new GAST.Literal("Fred Jones");

        Assert.Equal("1", lit1.SourceValue);
        Assert.Equal("Fred Jones", litName.SourceValue);
    }
}
