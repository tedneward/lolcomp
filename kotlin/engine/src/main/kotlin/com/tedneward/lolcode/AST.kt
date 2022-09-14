package com.tedneward.lolcode.ast

import java.util.Stack
import java.io.BufferedInputStream

import org.antlr.v4.runtime.*
import org.antlr.v4.runtime.tree.ParseTree
import org.antlr.v4.runtime.tree.ParseTreeWalker

import com.tedneward.lolcode.parser.*

// ====================================
// Abstract Syntax Tree
open class Node() { }

class CodeBlock() : Node() {
    val statements: MutableList<Statement> = mutableListOf()
    override fun toString() : String {
        return "(codeBlock statements:${statements.map { it.toString() }})"
    }
}

class Program(var version: String = "", var codeBlock: CodeBlock = CodeBlock()) : Node() { 
    override fun toString() : String {
        return "(program version:${version} codeBlock:${codeBlock})"
    }
}

open class Statement : Node() { }

class Declaration(var name : String, var expr : Expression) : Statement() { 
    override fun toString() : String {
        return "(decl ${name} ${expr})"
    }
}

class Print() : Statement() {
    val expressions: MutableList<Expression> = mutableListOf()
    override fun toString() : String {
        return "(print ${expressions.map { it.toString() }})"
    }
}

class Input(val label : String) : Statement() {
    override fun toString() : String {
        return "(input ${label})"
    }
}

class Assignment(val label : String, val expr : Expression) : Statement() {
    override fun toString() : String {
        return "(assign ${label} ${expr})"
    }
}

open class Expression : Statement() { }

class Atom(val value : String) : Expression() {
    override fun toString() : String {
        return "(ATOM '${value}')"
    }
}
class Label(val name : String) : Expression() { 
    override fun toString() : String {
        return "(LABEL ${name})"
    }
}

class BinaryOp(val left : Expression, val op : Operator, val right : Expression) : Expression() {
    enum class Operator { ADD, SUB, MUL, DIV, MOD }
    
    override fun toString() : String {
        return "(binary_op ${left} ${op} ${right})"
    }
}

class Comparison(val left : Expression, val op : Operator, val right : Expression) : Expression() {
    enum class Operator { EQU, NEQ, GT, LT, GTE, LTE }

    override fun toString() : String {
        return "(comparison ${left} ${op} ${right})"
    }
}

// ====================================
// Visitor: ANTLR parser transformed into Abstract Syntax Tree
//
class ASTVisitor() : lolcodeBaseVisitor<Node>() {

    companion object Utility {
        fun parseToAST(code : String) : Program {
            val lexer = lolcodeLexer(CharStreams.fromString(code))
            val tokens = CommonTokenStream(lexer)
            val parser = lolcodeParser(tokens)
            val syntaxTree : ParseTree = parser.program()
            val programASTNode = ASTVisitor().visit(syntaxTree) as Program
            return programASTNode
        }
    }

    var program = Program()

    override fun visitProgram(ctx: lolcodeParser.ProgramContext) : Node {
        program.version = 
            if (ctx.opening().version() != null) 
                ctx.opening().version().text
            else
                "1.2"

        if (ctx.code_block() != null)
            program.codeBlock = this.visit(ctx.code_block()) as CodeBlock

        return program
    }

	override fun visitCode_block(ctx: lolcodeParser.Code_blockContext) : Node {
        val cb = CodeBlock()
        for (stmt in ctx.statement()) {
            val node = visit(stmt)
            cb.statements.add(node as Statement)
        }
        return cb
    }

	override fun visitDeclaration(ctx: lolcodeParser.DeclarationContext) : Node {
        return Declaration(ctx.LABEL().text, this.visit(ctx.expression()) as Expression)
    }

    override fun visitExpression(ctx: lolcodeParser.ExpressionContext) : Node {
        return if (ctx.ATOM() != null)
            Atom(ctx.ATOM().text.replace("\"", ""))
        else if (ctx.LABEL() != null)
            Label(ctx.LABEL().text)
        else if (ctx.maths() != null)
            this.visit(ctx.maths())
        else if (ctx.comparison() != null)
            this.visit(ctx.comparison())
        else
            throw Exception("Somehow expression ${ctx} didn't generate a node")
    }

	override fun visitPrint_block(ctx: lolcodeParser.Print_blockContext) : Node {
        var prnt = Print()

        for (expr in ctx.expression()) {
            val node = visit(expr)
            prnt.expressions.add(node as Expression)
        }

        return prnt
    }

	override fun visitInput_block(ctx: lolcodeParser.Input_blockContext) : Node {
        return Input(ctx.LABEL().text)
    }
    
	override fun visitAssignment(ctx: lolcodeParser.AssignmentContext) : Node {
        return Assignment(ctx.LABEL().text, this.visit(ctx.expression()) as Expression)
    }

    override fun visitMaths(ctx: lolcodeParser.MathsContext) : Node {
        val op = 
            if ((ctx.op.text).equals("SUM OF"))
                BinaryOp.Operator.ADD
            else if ((ctx.op.text).equals("DIFF OF"))
                BinaryOp.Operator.SUB
            else if ((ctx.op.text).equals("PRODUKT OF"))
                BinaryOp.Operator.MUL
            else if ((ctx.op.text).equals("QUOSHUNT OF"))
                BinaryOp.Operator.DIV
            else if ((ctx.op.text).equals("MOD OF"))
                BinaryOp.Operator.MOD
            else
                throw Exception("Unrecognized operator: ${ctx.op.text}")

        return BinaryOp(
            this.visit(ctx.left) as Expression, 
            op,
            this.visit(ctx.right) as Expression)
    }

    override fun visitComparison(ctx: lolcodeParser.ComparisonContext) : Node {
        val op = 
            if ((ctx.op.text).equals("BOTH SAEM"))
                Comparison.Operator.EQU
            else if ((ctx.op.text).equals("DIFFRINT"))
                Comparison.Operator.NEQ
            else if ((ctx.op.text).equals("BIGGR OF"))
                Comparison.Operator.GT
            else if ((ctx.op.text).equals("SMALLR OF"))
                Comparison.Operator.LT
            else
                throw Exception("Unrecognized operator: ${ctx.op.text}")

        return Comparison(
            this.visit(ctx.left) as Expression, 
            op,
            this.visit(ctx.right) as Expression)
    }
}

