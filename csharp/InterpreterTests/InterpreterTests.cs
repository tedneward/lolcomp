using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace InterpreterTests;

using System;
using System.Collections.Generic;
using System.IO;
using LOLCODEParser;
using Interpreter;

[TestClass]
public class InterpreterTests
{
    [TestMethod]
    public void EmptyProgram()
    {
        var input = "";
        var interp = new Interpreter();
        interp.In = new StringReader(input);
        interp.Out = new StringWriter();

        /*
        HAI
        KTHXBYE
         */
        var program = new Program();
        interp.Run(program);

        Assert.AreEqual("", interp.Out.ToString());
    }

    [TestMethod]
    public void SimplestProgram()
    {
        var input = "";
        var interp = new Interpreter();
        interp.In = new StringReader(input);
        interp.Out = new StringWriter();

        /*
        HAI 1.2
        I HAZ A var ITZ 0
        KTHXBYE
         */
        var program = new Program();
        program.Version = "1.2";
        program.Children.Add(new CodeBlock());
        program.CodeBlock.Children.Add(new Declaration() { Name = "var", InitialValue = "0"});

        interp.Run(program);
        Assert.AreEqual("", interp.Out.ToString());
    }

    [TestMethod]
    public void SimplestPrintingProgram()
    {
        var input = "";
        var interp = new Interpreter();
        interp.In = new StringReader(input);
        interp.Out = new StringWriter();

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
        print.Children.Add(new Atom() { Value = "The var is "});
        print.Children.Add(new Label() { Name = "var"});
        program.CodeBlock.Children.Add(print);

        interp.Run(program);
        Assert.AreEqual("The var is 0\n", interp.Out.ToString());
    }
}
