package com.tedneward.lolcode

import org.antlr.v4.runtime.*
import org.antlr.v4.runtime.tree.ParseTree
import org.antlr.v4.runtime.tree.ParseTreeWalker
import kotlin.test.Test
import kotlin.test.assertEquals
import kotlin.test.assertFalse
import kotlin.test.assertTrue

class VisitorTests {
    @Test
    fun basicVisitorTest() {
        val code = "HAI\nI HAS A num ITZ SUM OF 2 AN 2\nI HAS A num2 ITZ DIFF OF 4 AN 2\nKTHXBYE\n"

        val lexer = lolcodeLexer(CharStreams.fromString(code))
        val tokens = CommonTokenStream(lexer)
        val parser = lolcodeParser(tokens)
        val syntaxTree : ParseTree = parser.program()
        val ast = ASTVisitor().visit(syntaxTree)
        println()
        println("ast: ${ast}")
    }
}
