
// Generated from ../lolcode.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "lolcodeVisitor.h"


namespace LOLCODE {

/**
 * This class provides an empty implementation of lolcodeVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  lolcodeBaseVisitor : public lolcodeVisitor {
public:

  virtual std::any visitProgram(lolcodeParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOpening(lolcodeParser::OpeningContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVersion(lolcodeParser::VersionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClosing(lolcodeParser::ClosingContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCode_block(lolcodeParser::Code_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(lolcodeParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComment(lolcodeParser::CommentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclaration(lolcodeParser::DeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrint_block(lolcodeParser::Print_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInput_block(lolcodeParser::Input_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignment(lolcodeParser::AssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLoop(lolcodeParser::LoopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIf_block(lolcodeParser::If_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitElse_if_block(lolcodeParser::Else_if_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunc_decl(lolcodeParser::Func_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression(lolcodeParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMaths(lolcodeParser::MathsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComparison(lolcodeParser::ComparisonContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogical(lolcodeParser::LogicalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnary_op(lolcodeParser::Unary_opContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunc_call(lolcodeParser::Func_callContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace LOLCODE
