/*
 * This Kotlin source file was generated by the Gradle 'init' task.
 */
package com.tedneward.lolcode

import java.util.Stack
import org.antlr.v4.runtime.*
import org.antlr.v4.runtime.tree.ParseTree
import org.antlr.v4.runtime.tree.ParseTreeWalker

// ====================================
// Abstract Syntax Tree
open class ASTNode(val children: MutableList<ASTNode> = mutableListOf()) { 
    override fun toString() : String {
        val mappedChildren = children.map { it.toString() }
        return "${mappedChildren}"
    }
}
class CodeBlock() : ASTNode() {

}
class Program(var version: String = "", var codeBlock: CodeBlock = CodeBlock()) : ASTNode() { 
    override fun toString() : String {
        return "(program version:${version} codeBlock:${codeBlock})"
    }
}
class Declaration(var name : String, var initialValue : String) : ASTNode() { 
    override fun toString() : String {
        return "(decl ${name} ${initialValue})"
    }
}
class Atom(val value : String) : ASTNode() { 
    override fun toString() : String {
        return "(ATOM ${value})"
    }
}
class Label(val name : String) : ASTNode() { 
    override fun toString() : String {
        return "(LABEL ${name})"
    }
}
class Print() : ASTNode() {
    override fun toString() : String {
        return "(print ${super.toString()})"
    }
}

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
        blockStack.peek().children.add(decl);
    }
    override fun enterPrint_block(ctx : lolcodeParser.Print_blockContext) {
        val print = Print()
        ctx.expression().forEach { it ->
            if (it.ATOM() != null) {
                print.children.add(Atom(it.ATOM().text))
            }
            else if (it.LABEL() != null) {
                print.children.add(Label(it.LABEL().text))
            }
            else {
                throw Exception("Unrecognized node in print_block: " + it)
            }
        }
        blockStack.peek().children.add(print)
    }
}

// ====================================
// Interpreter
class Variant(public val value : Any? = null) {
    public val type = if (value != null) value::class else Void::class

    fun verifyUntyped() { if (type == Void::class) { throw Exception("CANT CONVER NOOB") } }

    fun asBoolean() : Boolean { 
        verifyUntyped()
        return when {
            value is String && value.uppercase() == "TRUE" -> true
            value is String && value.uppercase() == "FALSE" -> false
            value is Number && value.toLong() == 0L -> false
            value is Number && value.toLong() != 0L -> true
            else -> false
        }
    }
    fun asInt64() : Long { verifyUntyped(); return java.lang.Long.parseLong(value.toString()) }
    fun asDouble() : Double { verifyUntyped(); return java.lang.Double.parseDouble(value.toString()) }
    fun asString() : String { verifyUntyped(); return value.toString() }

    override fun toString() : String {
        return if (value == null) "[NOOB]" else "[${value} (${value::class.qualifiedName})]"
    }
}
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
        System.out.println("AST: ${builder.program}")
        run(builder.program)
    }
}
