/*
 * This Kotlin source file was generated by the Gradle 'init' task.
 */
package com.tedneward.lolcode

import java.util.Stack
import java.io.BufferedInputStream
import org.antlr.v4.runtime.*
import org.antlr.v4.runtime.tree.ParseTree
import org.antlr.v4.runtime.tree.ParseTreeWalker

import com.tedneward.lolcode.ast.*

class ASTBuilder() : lolcodeBaseListener() {
    val program = Program()
    var blockStack = Stack<CodeBlock>()

    override fun enterProgram(ctx : lolcodeParser.ProgramContext) { 
        program.version = if (ctx.opening().version() != null) ctx.opening().version().getText() else "1.2";
    }
    override fun enterCode_block(ctx : lolcodeParser.Code_blockContext) {
        val codeBlock = if (blockStack.isEmpty()) program.codeBlock else CodeBlock()
        blockStack.push(codeBlock)
    }
    override fun exitCode_block(ctx : lolcodeParser.Code_blockContext) {
        blockStack.pop()
    }
    override fun enterDeclaration(ctx : lolcodeParser.DeclarationContext) {
        val decl = Declaration(
            ctx.LABEL().text, 
            if (ctx.expression() != null) 
                ctx.expression().text
            else
                ""
        )
        blockStack.peek().add(decl);
    }
    override fun enterInput_block(ctx : lolcodeParser.Input_blockContext) {
        val input = Input(ctx.LABEL().text)
        blockStack.peek().add(input)
    }
    override fun enterPrint_block(ctx : lolcodeParser.Print_blockContext) {
        val printAST = Print()
        ctx.expression().forEach { it ->
            if (it.ATOM() != null) {
                printAST.add(Atom(it.ATOM().text))
            }
            else if (it.LABEL() != null) {
                printAST.add(Label(it.LABEL().text))
            }
            else {
                throw Exception("Unrecognized node in printAST_block: " + it)
            }
        }
        blockStack.peek().add(printAST)
    }
    override fun enterAssignment(ctx: lolcodeParser.AssignmentContext) {
        // This is wildly inefficient, and I probably need to move to Visitors
        // here before this gets out of hand.
        val label = ctx.LABEL().text
        val expr : Expression = 
            if (ctx.expression().LABEL() != null) {
                Label(ctx.expression().LABEL().text)
            }
            else if (ctx.expression().ATOM() != null) {
                Atom(ctx.expression().ATOM().text)
            }
            else {
                throw Exception("Unrecognized expression")
            }
        val assignment = Assignment(label, expr)
        blockStack.peek().add(assignment)
    }
}

// ====================================
// Interpreter
class Interpreter {
    var program : Program = Program()
    var ioOut : java.io.PrintStream = System.out
    var ioIn : java.io.InputStream = System.`in`

    fun version() : String { return "0.1" }

    fun run(program : Program) {
        this.program = program
        run(this.program.codeBlock)
    }
    fun run(codeBlock : CodeBlock) {
        val variables : MutableMap<String, Variant> = mutableMapOf()

        fun evaluate(expr : Expression) : Variant {
            return when (expr) {
                is Atom -> Variant(expr.value)
                is Label -> variables[expr.name]!!
                is BinaryOp -> {
                    val left = evaluate(expr.left)
                    val right = evaluate(expr.right)

                    // Type conversions
                    if (left.type == Variant.TYPE.NUMBR && right.type == Variant.TYPE.NUMBR) {
                        // Cool, we have two ints
                        return when (expr.op) {
                            "+" -> Variant(left.asInt64() + right.asInt64())
                            "-" -> Variant(left.asInt64() - right.asInt64())
                            "*" -> Variant(left.asInt64() * right.asInt64())
                            "/" -> Variant(left.asInt64() / right.asInt64())
                            "%" -> Variant(left.asInt64() % right.asInt64())
                            else -> throw Exception("Unrecognized operator: ${expr.op}")
                        }
                    }
                    else if (left.type == Variant.TYPE.NUMBAR && right.type == Variant.TYPE.NUMBAR) {
                        // Cool, we have two doubles
                        return when (expr.op) {
                            "+" -> Variant(left.asDouble() + right.asDouble())
                            "-" -> Variant(left.asDouble() - right.asDouble())
                            "*" -> Variant(left.asDouble() * right.asDouble())
                            "/" -> Variant(left.asDouble() / right.asDouble())
                            "%" -> Variant(left.asDouble() % right.asDouble())
                            else -> throw Exception("Unrecognized operator: ${expr.op}")
                        }
                    }
                    else {
                        // Bleargh
                        throw Exception("Variant type conversions required--bleargh")
                    }
                }
                else -> throw Exception("Unrecognized expression: ${expr}")
            }
        }

        for (node in codeBlock.children) {
            when (node) {
                is Declaration -> {
                    variables.put(node.name, Variant(node.initialValue))
                }
                is Print -> {
                    var message = ""
                    node.children.forEach { it ->
                        when (it) {
                            is Atom -> {
                                var value = it.value.replace("\"", "")
                                message += value
                            }
                            is Label -> {
                                if (variables[it.name] == null)
                                    throw Exception("${it.name} not found")
                                message += variables[it.name]!!.asString()
                            }
                            else -> {
                                message += "((Unrecognized: ${it} ))"
                            }
                        }
                    }
                    ioOut.println(message)
                }
                is Input -> {
                    var input = ioIn.bufferedReader().readLine()
                    variables[node.label] = Variant(input)
                }
                is Assignment -> {
                    variables[node.label] = evaluate(node.expression)
                }
                else -> {
                    System.out.println("Unrecognized node: ${node}")
                }
            }
        }
    }
    fun execute(code : String) {
        val lexer = lolcodeLexer(CharStreams.fromString(code))
        val tokens = CommonTokenStream(lexer)
        val parser = lolcodeParser(tokens)
        val builder = ASTBuilder()
        ParseTreeWalker.DEFAULT.walk(builder, parser.program())
        run(builder.program)
    }
}
