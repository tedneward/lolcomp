using Xunit;
using GAST;

namespace GASTTest;

public class ScriptishTests
{
    [Fact]
    public void ScriptishMath()
    {
        // x = 2 + 2
        var varX = new GAST.Variable("x");

        var literal2 = new GAST.Literal("2");
        var twoPlusTwo = new GAST.AdditionOperator(literal2, literal2);

        var xEquals = new GAST.AssignmentOperator(varX, twoPlusTwo);
    }
}
