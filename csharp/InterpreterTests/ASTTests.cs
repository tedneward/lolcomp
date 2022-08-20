using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace InterpreterTests;

using System;
using System.Collections.Generic;
using LOLCODEParser;
using Interpreter;

[TestClass]
public class ASTTests
{
    [TestMethod]
    public void EmptyProgram()
    {
        var program = new Program();
        Assert.IsNull(program.CodeBlock);
    }

    [TestMethod]
    public void SimplestProgram()
    {
        /*
        HAI 1.2
        I HAZ A var ITZ 0
        KTHXBYE
         */
        var program = new Program();
        program.Children.Add(new CodeBlock());
        program.CodeBlock.Children.Add(new Declaration() { Name = "var", Value = "0"});

        Assert.AreEqual(1, program.CodeBlock.Children.Count);
        Assert.AreEqual(typeof(Declaration), program.CodeBlock.Children[0].GetType());
        Assert.AreEqual("var", ((Declaration)program.CodeBlock.Children[0]).Name);
        Assert.AreEqual("0", ((Declaration)program.CodeBlock.Children[0]).Value);
    }
}
