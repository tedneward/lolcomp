
// Generated from ../lolcode.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "lolcodeParser.h"


namespace LOLCODE {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by lolcodeParser.
 */
class  lolcodeVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by lolcodeParser.
   */
    virtual std::any visitProgram(lolcodeParser::ProgramContext *context) = 0;

    virtual std::any visitOpening(lolcodeParser::OpeningContext *context) = 0;

    virtual std::any visitVersion(lolcodeParser::VersionContext *context) = 0;

    virtual std::any visitClosing(lolcodeParser::ClosingContext *context) = 0;

    virtual std::any visitCode_block(lolcodeParser::Code_blockContext *context) = 0;

    virtual std::any visitStatement(lolcodeParser::StatementContext *context) = 0;

    virtual std::any visitComment(lolcodeParser::CommentContext *context) = 0;

    virtual std::any visitDeclaration(lolcodeParser::DeclarationContext *context) = 0;

    virtual std::any visitPrint_block(lolcodeParser::Print_blockContext *context) = 0;

    virtual std::any visitInput_block(lolcodeParser::Input_blockContext *context) = 0;

    virtual std::any visitAssignment(lolcodeParser::AssignmentContext *context) = 0;

    virtual std::any visitLoop(lolcodeParser::LoopContext *context) = 0;

    virtual std::any visitIf_block(lolcodeParser::If_blockContext *context) = 0;

    virtual std::any visitElse_if_block(lolcodeParser::Else_if_blockContext *context) = 0;

    virtual std::any visitFunc_decl(lolcodeParser::Func_declContext *context) = 0;

    virtual std::any visitExpression(lolcodeParser::ExpressionContext *context) = 0;

    virtual std::any visitMaths(lolcodeParser::MathsContext *context) = 0;

    virtual std::any visitComparison(lolcodeParser::ComparisonContext *context) = 0;

    virtual std::any visitLogical(lolcodeParser::LogicalContext *context) = 0;

    virtual std::any visitUnary_op(lolcodeParser::Unary_opContext *context) = 0;

    virtual std::any visitFunc_call(lolcodeParser::Func_callContext *context) = 0;


};

}  // namespace LOLCODE
