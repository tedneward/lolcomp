using Xunit;
using GAST;

namespace GASTTest;

public class ScriptishTests
{
    [Fact]
    public void Math()
    {
        // x = 2 + 2
        var varX = new GAST.Variable("x");

        var literal2 = new GAST.Literal("2");
        var twoPlusTwo = new GAST.AdditionOperator(literal2, literal2);

        var xEquals = new GAST.AssignmentOperator(varX, twoPlusTwo);

        Assert.Equal("(assignment-operator (variable x) (addition-operator (literal 2) (literal 2)))", 
            xEquals.SExpr);
    }
    [Fact]
    public void Block()
    {
        // {
        //   var x = 2
        //   var y = 3
        //   var z = 0
        //   z = x + y   
        // }
        var block = new GAST.Block();
        var x = new GAST.Variable("x");
        var assignX = new GAST.AssignmentOperator(x, new GAST.Literal("2"));
        var y = new GAST.Variable("y");
        var assignY = new GAST.AssignmentOperator(x, new GAST.Literal("3"));
        var z = new GAST.Variable("z");
        var assignZ = new GAST.AdditionOperator(x, y);
        block.Statements.Add();
    }
}
