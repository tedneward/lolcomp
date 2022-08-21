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
        var input = "";
        var interp = new Interpreter();
        interp.In = new StringReader(input);
        interp.Out = new StringWriter();

        interp.Execute(ReadExampleFile("hai.lol"));

        Assert.AreEqual("", interp.Out.ToString());
    }

    [TestMethod]
    public void var()
    {
        var input = "";
        var interp = new Interpreter();
        interp.In = new StringReader(input);
        interp.Out = new StringWriter();

        interp.Execute(ReadExampleFile("var.lol"));

        Assert.AreEqual("The var is 0\n", interp.Out.ToString());
    }
}
