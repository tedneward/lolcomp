package com.tedneward.lolcode.ast

import java.util.Stack
import java.io.BufferedInputStream

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
