package com.tedneward.lolcode

import com.tedneward.lolcode.ast.*

import java.io.File
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertTrue

class ASTTests {
    @Test
    fun simpleCalculations() {
        var program = Program("1.2")
        program.codeBlock.children.add(Declaration("age", "27"))
        var print = Print()
        print.children.add(Atom("Ur age is "))
        print.children.add(Label("age"))
        program.codeBlock.children.add(print)

        var interp = Interpreter()
        val outBuffer = java.io.ByteArrayOutputStream()
        interp.ioOut = java.io.PrintStream(outBuffer)

        interp.run(program)

        assertEquals("Ur age is 27\n", outBuffer.toString())
    }
}
