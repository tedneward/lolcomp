package com.tedneward.lolcode.ast

import java.util.Stack
import java.io.BufferedInputStream

// ====================================
// Abstract Syntax Tree
open class Node(val children: MutableList<Node> = mutableListOf()) { 
    fun add(node : Node) { children.add(node) }

    override fun toString() : String {
        val mappedChildren = children.map { it.toString() }
        return "${mappedChildren}"
    }
}

class CodeBlock() : Node() { }

class Program(var version: String = "", var codeBlock: CodeBlock = CodeBlock()) : Node() { 
    override fun toString() : String {
        return "(program version:${version} codeBlock:${codeBlock})"
    }
}

open class Statement : Node() { }

class Declaration(var name : String, var initialValue : String) : Statement() { 
    override fun toString() : String {
        return "(decl ${name} ${initialValue})"
    }
}

class Print() : Statement() {
    override fun toString() : String {
        return "(print ${super.toString()})"
    }
}

class Input(val label : String) : Statement() {
    override fun toString() : String {
        return "(input ${label})"
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

class Assignment(val label : String, val expression : Expression) : Node() {
    override fun toString() : String {
        return "(assign ${label} ${expression})"
    }
}

class BinaryOp(val left : Expression, val op : Operator, val right : Expression) : Expression() {
    enum class Operator {
        ADD, SUB, MUL, DIV, MOD
    }
    
    override fun toString() : String {
        return "(${left} ${op} ${right})"
    }
}
