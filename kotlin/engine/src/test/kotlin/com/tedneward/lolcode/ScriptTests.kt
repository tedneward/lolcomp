package com.tedneward.lolcode

import com.tedneward.lolcode.ast.*

import java.io.File
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertTrue

class ScriptTests {
    @Test fun simpleProgramTest() {
        val code = """
        HAI 1.2
        KTHXBYE
        """

        val interp = Interpreter()
        interp.execute(code)

        assertEquals(interp.program.version, "1.2")
    }

    fun executeExampleFile(filename : String, input : String = "") : Pair<Interpreter, String> {
        val code = File("../../examples/${filename}").readText()

        val interp = Interpreter()
        val outBuffer = java.io.ByteArrayOutputStream()
        interp.ioOut = java.io.PrintStream(outBuffer)
        interp.ioIn = input.byteInputStream()

        interp.execute(code)

        return Pair(interp, outBuffer.toString())
    }

    @Test fun haiExample() {
        val (interp, _) = executeExampleFile("hai.lol")

        assertEquals(interp.program.version, "1.2")
    }
    @Test fun hai12Example() {
        val (interp, _) = executeExampleFile("hai12.lol")

        assertEquals(interp.program.version, "1.2")
    }
    @Test fun justvarExample() {
        val (interp, _) = executeExampleFile("justvar.lol")

        assertEquals(interp.program.version, "1.2")
        assertEquals(interp.program.codeBlock.statements.size, 1)
        val decl = interp.program.codeBlock.statements.get(0) as Declaration
        assertEquals(decl.name, "var")
        assertTrue(decl.expr is Atom)
        assertEquals((decl.expr as Atom).value, "0")
    }
    @Test fun varExample() {
        val (interp, outBuffer) = executeExampleFile("var.lol")

        assertEquals(interp.program.codeBlock.statements.size, 2)

        val decl = interp.program.codeBlock.statements.get(0) as Declaration
        assertEquals(decl.name, "var")
        assertTrue(decl.expr is Atom)
        assertEquals((decl.expr as Atom).value, "0")

        assertTrue(interp.program.codeBlock.statements.get(1) is Print)

        assertEquals("The var is 0\n", outBuffer.toString())
    }
    @Test fun helloExample() {
        val (_, outBuffer) = executeExampleFile("hello.lol")
        assertEquals("Hello world\n", outBuffer.toString())
    }
    @Test fun inputageExample() {
        val (_, outBuffer) = executeExampleFile("inputage.lol", "27\n")
        assertEquals("What is your age?\nYour age is 27\n", outBuffer.toString())
    }
    @Test fun assignExample() {
        val (_, outBuffer) = executeExampleFile("assign.lol", "27\n")
        assertEquals(
            "What is your age?\n" + 
            "Your age is 27\n" +
            "Your age is now 50\n" +
            "UR OLD!\n",
            outBuffer.toString())
    }
    @Test fun mathsExample() {
        val (_, outBuffer) = executeExampleFile("maths.lol")
        assertEquals("4\n0\n100\n5\n0\n",
            outBuffer.toString())
    }
    //@Test fun moremathsExample() {
    //    val (_, outBuffer) = executeExampleFile("moremaths.lol")
    //    assertEquals("4\n0\n100\n5\n0\n",
    //        outBuffer.toString())
    //}
    @Test fun comparisonsExample() {
        val (_, outBuffer) = executeExampleFile("comparisons.lol")
        assertEquals("FAIL\nWIN\nFAIL\nWIN\n",
            outBuffer.toString())
    }
    @Test fun logicalsExample() {
        val (_, outBuffer) = executeExampleFile("logicals.lol")
        assertEquals("WIN? WIN\nWIN? WIN\nFAIL? FAIL\n",
            outBuffer.toString())
    }
}