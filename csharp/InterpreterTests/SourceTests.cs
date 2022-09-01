using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace InterpreterTests;

using System;
using System.Collections.Generic;
using System.IO;
using LOLCODEParser;
using Interpreter;

[TestClass]
public class SourceInterpreterTests
{
    public static string ReadExampleFile(string name)
    {
        var filepath = String.Format(@"../../../../../examples/{0}", name);
        return File.ReadAllText(filepath);
    }
    [TestMethod]
    public void hai()
    {
        var interp = new Interpreter();
        var input = "";
        interp.In = new StringReader(input);
        interp.Out = new StringWriter();

        interp.Execute(ReadExampleFile("hai.lol"));

        Assert.AreEqual("", interp.Out.ToString());
    }
    public void hai12()
    {
        var interp = new Interpreter();
        var input = "";
        interp.In = new StringReader(input);
        interp.Out = new StringWriter();

        interp.Execute(ReadExampleFile("hai12.lol"));

        Assert.AreEqual("", interp.Out.ToString());
    }
    public void hello()
    {
        var interp = new Interpreter();
        var input = "";
        interp.In = new StringReader(input);
        interp.Out = new StringWriter();

        interp.Execute(ReadExampleFile("hello.lol"));

        Assert.AreEqual("Hello world", interp.Out.ToString());
    }

    [TestMethod]
    public void justvar()
    {
        var interp = new Interpreter();
        var input = "";
        interp.In = new StringReader(input);
        interp.Out = new StringWriter();

        interp.Execute(ReadExampleFile("justvar.lol"));

        Assert.AreEqual("", interp.Out.ToString());
    }
    [TestMethod]
    public void var()
    {
        var interp = new Interpreter();
        var input = "";
        interp.In = new StringReader(input);
        interp.Out = new StringWriter();

        interp.Execute(ReadExampleFile("var.lol"));

        Assert.AreEqual("The var is 0\n", interp.Out.ToString());
    }
}
