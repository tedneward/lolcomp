
// Generated from ../lolcode.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "lolcodeParser.h"


namespace LOLCODE {

/**
 * This interface defines an abstract listener for a parse tree produced by lolcodeParser.
 */
class  lolcodeListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(lolcodeParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(lolcodeParser::ProgramContext *ctx) = 0;

  virtual void enterOpening(lolcodeParser::OpeningContext *ctx) = 0;
  virtual void exitOpening(lolcodeParser::OpeningContext *ctx) = 0;

  virtual void enterVersion(lolcodeParser::VersionContext *ctx) = 0;
  virtual void exitVersion(lolcodeParser::VersionContext *ctx) = 0;

  virtual void enterClosing(lolcodeParser::ClosingContext *ctx) = 0;
  virtual void exitClosing(lolcodeParser::ClosingContext *ctx) = 0;

  virtual void enterCode_block(lolcodeParser::Code_blockContext *ctx) = 0;
  virtual void exitCode_block(lolcodeParser::Code_blockContext *ctx) = 0;

  virtual void enterStatement(lolcodeParser::StatementContext *ctx) = 0;
  virtual void exitStatement(lolcodeParser::StatementContext *ctx) = 0;

  virtual void enterComment(lolcodeParser::CommentContext *ctx) = 0;
  virtual void exitComment(lolcodeParser::CommentContext *ctx) = 0;

  virtual void enterDeclaration(lolcodeParser::DeclarationContext *ctx) = 0;
  virtual void exitDeclaration(lolcodeParser::DeclarationContext *ctx) = 0;

  virtual void enterPrint_block(lolcodeParser::Print_blockContext *ctx) = 0;
  virtual void exitPrint_block(lolcodeParser::Print_blockContext *ctx) = 0;

  virtual void enterInput_block(lolcodeParser::Input_blockContext *ctx) = 0;
  virtual void exitInput_block(lolcodeParser::Input_blockContext *ctx) = 0;

  virtual void enterAssignment(lolcodeParser::AssignmentContext *ctx) = 0;
  virtual void exitAssignment(lolcodeParser::AssignmentContext *ctx) = 0;

  virtual void enterLoop(lolcodeParser::LoopContext *ctx) = 0;
  virtual void exitLoop(lolcodeParser::LoopContext *ctx) = 0;

  virtual void enterIf_block(lolcodeParser::If_blockContext *ctx) = 0;
  virtual void exitIf_block(lolcodeParser::If_blockContext *ctx) = 0;

  virtual void enterElse_if_block(lolcodeParser::Else_if_blockContext *ctx) = 0;
  virtual void exitElse_if_block(lolcodeParser::Else_if_blockContext *ctx) = 0;

  virtual void enterFunc_decl(lolcodeParser::Func_declContext *ctx) = 0;
  virtual void exitFunc_decl(lolcodeParser::Func_declContext *ctx) = 0;

  virtual void enterExpression(lolcodeParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(lolcodeParser::ExpressionContext *ctx) = 0;

  virtual void enterMaths(lolcodeParser::MathsContext *ctx) = 0;
  virtual void exitMaths(lolcodeParser::MathsContext *ctx) = 0;

  virtual void enterComparison(lolcodeParser::ComparisonContext *ctx) = 0;
  virtual void exitComparison(lolcodeParser::ComparisonContext *ctx) = 0;

  virtual void enterLogical(lolcodeParser::LogicalContext *ctx) = 0;
  virtual void exitLogical(lolcodeParser::LogicalContext *ctx) = 0;

  virtual void enterUnary_op(lolcodeParser::Unary_opContext *ctx) = 0;
  virtual void exitUnary_op(lolcodeParser::Unary_opContext *ctx) = 0;

  virtual void enterFunc_call(lolcodeParser::Func_callContext *ctx) = 0;
  virtual void exitFunc_call(lolcodeParser::Func_callContext *ctx) = 0;


};

}  // namespace LOLCODE
