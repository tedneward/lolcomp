/*
 * This Kotlin source file was generated by the Gradle 'init' task.
 */
package com.tedneward.lolcode

import java.util.Stack
import java.io.BufferedInputStream

import com.tedneward.lolcode.ast.*

// ====================================
// Interpreter
typealias Scope = MutableMap<String, Variant>

class Interpreter {
    var program : Program = Program()
    var ioOut : java.io.PrintStream = System.out
    var ioIn : java.io.InputStream = System.`in`

    // Our stack frame management
    //
    val stack = Stack<Scope>()
    fun pushScope() {
        stack.push(mutableMapOf())
    }
    fun lookup(name : String) : Variant {
        stack.asReversed().forEach { scope ->
            if (scope.keys.contains(name))
                return scope.get(name)!!
        }
        
        throw Exception("NUTHIN THERE CALT ${name}");
    }
    fun store(name : String, value : Variant) {
        stack.peek().put(name, value)
    }

    // Version check
    //
    fun version() : String { return "0.1" }

    // Run, interpreter, run
    //
    fun execute(code : String) {
        val programASTNode = ASTVisitor.parseToAST(code)
        run(programASTNode)
    }

    fun run(program : Program) {
        this.program = program
        evaluate(this.program.codeBlock)
    }

    fun evaluate(codeBlock : CodeBlock) {
        pushScope()

        for (stmt in codeBlock.statements) {
            evaluate(stmt)
        }
    }

    fun evaluate(stmt : Statement) {
        when (stmt) {
            is Declaration -> {
                store(stmt.name, evaluate(stmt.expr))
            }
            is Print -> {
                var message = stmt.expressions.joinToString(prefix="", postfix="", separator="") { 
                    evaluate(it).asString()
                }
                ioOut.println(message)
            }
            is Input -> {
                var input = ioIn.bufferedReader().readLine()
                store(stmt.label, Variant(input))
            }
            is Assignment -> {
                store(stmt.label, evaluate(stmt.expr))
            }
            is Expression -> {
                evaluate(stmt)
            }
            is Loop -> {
                while (evaluate(stmt.conditional).asBoolean()) {
                    evaluate(stmt.codeBlock)
                }
            }
        }
    }

    fun evaluate(expr : Expression) : Variant {
        return when (expr) {
            is Atom -> Variant(expr.value)
            is Label -> lookup(expr.name)
            is BinaryOp -> {
                val left = evaluate(expr.left)
                val right = evaluate(expr.right)
                val opInt : (Long, Long) -> Long = when (expr.op.name) {
                    "ADD" -> { l, r -> l + r }
                    "SUB" -> { l, r -> l - r }
                    "MUL" -> { l, r -> l * r }
                    "DIV" -> { l, r -> l / r }
                    "MOD" -> { l, r -> l % r }
                    else -> throw Exception("Implementation error: Unrecognized operator: ${expr.op}")
                }
                val opDbl : (Double, Double) -> Double = when (expr.op.name) {
                    "ADD" -> { l, r -> l + r }
                    "SUB" -> { l, r -> l - r }
                    "MUL" -> { l, r -> l * r }
                    "DIV" -> { l, r -> l / r }
                    "MOD" -> { l, r -> l % r }
                    else -> throw Exception("Implementation error: Unrecognized operator: ${expr.op}")
                }

                return if (left.isNumbr() && right.isNumbr()) 
                        Variant(opInt(left.asInt64(), right.asInt64()))
                    else if (left.isNumbar() || right.isNumbar())
                        Variant(opDbl(left.asDouble(), right.asDouble())) 
                    else if (left.isYarn() || right.isYarn() && 
                        left.canConvertNumbr() && right.canConvertNumbr())
                        Variant(opInt(left.asInt64(), right.asInt64()))
                    else if (left.isYarn() || right.isYarn() &&
                        left.canConvertNumbar() && right.canConvertNumbar())
                        Variant(opDbl(left.asDouble(), right.asDouble())) 
                    else
                        throw Exception("CANT MATH ON WHATEVR")
            }
            is Comparison -> {
                val left = evaluate(expr.left)
                val right = evaluate(expr.right)
                return Variant(when (expr.op.name) {
                    "EQU" -> left.equals(right)
                    "NEQ" -> ! (left.equals(right))
                    "GT" -> left.greaterThan(right)
                    "LT" -> left.lesserThan(right)
                    "GTE" -> ! (left.lesserThan(right))
                    "LTE" -> ! (left.greaterThan(right))
                    else -> throw Exception("Implementation error: Unrecognized operator: ${expr.op}")
                })
            }
            is UnaryOp -> {
                val result = evaluate(expr.expression)
                return result.not()
            }
            is Logical -> {
                when (expr.op) {
                    Logical.Operator.ALL -> {
                        for (e in expr.expressions) {
                            val result = evaluate(e)
                            if (result.asBoolean() == false) {
                                return Variant(false)
                            }
                        }
                        return Variant(true)
                    }
                    Logical.Operator.ANY -> {
                        for (e in expr.expressions) {
                            val result = evaluate(e)
                            if (result.asBoolean() == true) {
                                return Variant(true)
                            }
                        }
                        return Variant(false)
                    }
                    Logical.Operator.AND ->{
                        for (e in expr.expressions) {
                            val result = evaluate(e)
                            if (result.asBoolean() == false) {
                                return Variant(false)
                            }
                        }
                        return Variant(true)
                    }
                    Logical.Operator.OR -> {
                        for (e in expr.expressions) {
                            val result = evaluate(e)
                            if (result.asBoolean() == true) {
                                return Variant(true)
                            }
                        }
                        return Variant(false)
                    }
                    else ->
                        throw Exception("Implementation error: Unrecognized logical: ${expr}")
                }
            }
            else ->
                throw Exception("Unrecognized expression: ${expr}")
        }
    }
}
