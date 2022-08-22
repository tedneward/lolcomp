/*
 * This Kotlin source file was generated by the Gradle 'init' task.
 */
package com.tedneward.lolcode

import java.io.File
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertTrue

class InterpreterTests {
    @Test fun versionTest() {
        val interp = Interpreter()
        assertEquals(interp.version(), "0.1")
    }

    @Test fun simpleProgramTest() {
        val code = """
        HAI 1.2
        KTHXBYE
        """

        val interp = Interpreter()
        interp.execute(code)

        assertEquals(interp.program.version, "1.2")
    }

    fun readExampleFile(filename : String) : String { 
        return File("../../examples/${filename}").readText()
    }

    @Test fun hai12() {
        val code = readExampleFile("hai12.lol")

        val interp = Interpreter()
        interp.execute(code)

        assertEquals(interp.program.version, "1.2")
    }
    @Test fun hai() {
        val code = readExampleFile("hai.lol")

        val interp = Interpreter()
        interp.execute(code)

        assertEquals(interp.program.version, "1.2")
    }
}
