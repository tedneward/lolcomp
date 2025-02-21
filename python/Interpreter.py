import sys
from antlr4 import *
from lolcode.lolcodeLexer import lolcodeLexer
from lolcode.lolcodeParser import lolcodeParser
from lolcode.lolcodeVisitor import lolcodeVisitor

# Python is already a dynamically-typed interpreter,
# so this is/should-be a pretty easy implementation,
# assuming we fall back to native Python types for
# values.
class Interpreter(lolcodeVisitor):

    class Scope:
        def __init__(self):
            self.vars = {}
            self.funcs = {}

    def __init__(self):
        self.scopes = []

    def visitProgram(self, ctx:lolcodeParser.ProgramContext):
        """Visit the root (program) node in the tree."""
        self.scopes.append(Interpreter.Scope())
        return self.visitChildren(ctx)

    # Visit a parse tree produced by lolcodeParser#opening.
    def visitOpening(self, ctx:lolcodeParser.OpeningContext):
        return self.visitChildren(ctx)

    # Visit a parse tree produced by lolcodeParser#version.
    def visitVersion(self, ctx:lolcodeParser.VersionContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by lolcodeParser#closing.
    def visitClosing(self, ctx:lolcodeParser.ClosingContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by lolcodeParser#code_block.
    def visitCode_block(self, ctx:lolcodeParser.Code_blockContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by lolcodeParser#statement.
    def visitStatement(self, ctx:lolcodeParser.StatementContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by lolcodeParser#comment.
    def visitComment(self, ctx:lolcodeParser.CommentContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by lolcodeParser#declaration.
    def visitDeclaration(self, ctx:lolcodeParser.DeclarationContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by lolcodeParser#print_block.
    def visitPrint_block(self, ctx:lolcodeParser.Print_blockContext):
        print("PRINT: ")
        self.visitChildren(ctx)


    # Visit a parse tree produced by lolcodeParser#input_block.
    def visitInput_block(self, ctx:lolcodeParser.Input_blockContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by lolcodeParser#assignment.
    def visitAssignment(self, ctx:lolcodeParser.AssignmentContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by lolcodeParser#loop.
    def visitLoop(self, ctx:lolcodeParser.LoopContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by lolcodeParser#if_block.
    def visitIf_block(self, ctx:lolcodeParser.If_blockContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by lolcodeParser#else_if_block.
    def visitElse_if_block(self, ctx:lolcodeParser.Else_if_blockContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by lolcodeParser#func_decl.
    def visitFunc_decl(self, ctx:lolcodeParser.Func_declContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by lolcodeParser#expression.
    def visitExpression(self, ctx:lolcodeParser.ExpressionContext):
        print("EXPRESSION: ")
        result = self.visitChildren(ctx)
        if ctx.ATOM() != None:
            print("atom", ctx.atom)
        elif ctx.LABEL() != None:
            print("label", ctx.label)

    # Visit a parse tree produced by lolcodeParser#maths.
    def visitMaths(self, ctx:lolcodeParser.MathsContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by lolcodeParser#comparison.
    def visitComparison(self, ctx:lolcodeParser.ComparisonContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by lolcodeParser#logical.
    def visitLogical(self, ctx:lolcodeParser.LogicalContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by lolcodeParser#unary_op.
    def visitUnary_op(self, ctx:lolcodeParser.Unary_opContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by lolcodeParser#func_call.
    def visitFunc_call(self, ctx:lolcodeParser.Func_callContext):
        return self.visitChildren(ctx)


def main(argv):
    if len(sys.argv) < 2:
        print("Specify an incoming file to transpile!")
        return

    incoming = FileStream(sys.argv[1])
    lexer = lolcodeLexer(incoming)
    tokens = CommonTokenStream(lexer)
    parser = lolcodeParser(tokens)
    tree = parser.program()
    print(tree.toStringTree(recog=parser))

    print("Interpreting....")
    interp = Interpreter()
    interp.visit(tree)
    print("Exiting....")

if __name__ == '__main__':
    main(sys.argv)

