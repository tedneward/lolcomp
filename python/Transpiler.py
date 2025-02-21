import sys
from antlr4 import *
from lolcode.lolcodeLexer import lolcodeLexer
from lolcode.lolcodeParser import lolcodeParser
from lolcode.lolcodeVisitor import lolcodeVisitor

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

if __name__ == '__main__':
    main(sys.argv)

