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
        /*
        HAI
        KTHXBYE
         */
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
        program.Version = "1.2";
        program.Children.Add(new CodeBlock());
        program.CodeBlock.Children.Add(new Declaration() { Name = "var", InitialValue = "0"});

        Assert.AreEqual(1, program.CodeBlock.Children.Count);
        Assert.AreEqual(typeof(Declaration), program.CodeBlock.Children[0].GetType());
        Assert.AreEqual("var", ((Declaration)program.CodeBlock.Children[0]).Name);
        Assert.AreEqual("0", ((Declaration)program.CodeBlock.Children[0]).InitialValue);
    }

    [TestMethod]
    public void SimplestPrintingProgram()
    {
        /*
        HAI 1.2
        I HAZ A var ITZ 0
        VISIBLE "The var is " var MKAY?
        KTHXBYE
         */
        var program = new Program();
        program.Version = "1.2";
        program.Children.Add(new CodeBlock());
        program.CodeBlock.Children.Add(new Declaration() { Name = "var", InitialValue = "0"});
        var print = new PrintExpr();
        print.Children.Add(new Atom() { Value = "The var is"});
        print.Children.Add(new Label() { Name = "var"});
        program.CodeBlock.Children.Add(print);

        Assert.AreEqual(2, program.CodeBlock.Children.Count);

        Assert.AreEqual(typeof(Declaration), program.CodeBlock.Children[0].GetType());
        Assert.AreEqual("var", ((Declaration)program.CodeBlock.Children[0]).Name);
        Assert.AreEqual("0", ((Declaration)program.CodeBlock.Children[0]).InitialValue);
    }
}
