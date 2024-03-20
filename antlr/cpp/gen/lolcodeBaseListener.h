
// Generated from ../lolcode.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "lolcodeListener.h"


namespace LOLCODE {

/**
 * This class provides an empty implementation of lolcodeListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  lolcodeBaseListener : public lolcodeListener {
public:

  virtual void enterProgram(lolcodeParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(lolcodeParser::ProgramContext * /*ctx*/) override { }

  virtual void enterOpening(lolcodeParser::OpeningContext * /*ctx*/) override { }
  virtual void exitOpening(lolcodeParser::OpeningContext * /*ctx*/) override { }

  virtual void enterVersion(lolcodeParser::VersionContext * /*ctx*/) override { }
  virtual void exitVersion(lolcodeParser::VersionContext * /*ctx*/) override { }

  virtual void enterClosing(lolcodeParser::ClosingContext * /*ctx*/) override { }
  virtual void exitClosing(lolcodeParser::ClosingContext * /*ctx*/) override { }

  virtual void enterCode_block(lolcodeParser::Code_blockContext * /*ctx*/) override { }
  virtual void exitCode_block(lolcodeParser::Code_blockContext * /*ctx*/) override { }

  virtual void enterStatement(lolcodeParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(lolcodeParser::StatementContext * /*ctx*/) override { }

  virtual void enterComment(lolcodeParser::CommentContext * /*ctx*/) override { }
  virtual void exitComment(lolcodeParser::CommentContext * /*ctx*/) override { }

  virtual void enterDeclaration(lolcodeParser::DeclarationContext * /*ctx*/) override { }
  virtual void exitDeclaration(lolcodeParser::DeclarationContext * /*ctx*/) override { }

  virtual void enterPrint_block(lolcodeParser::Print_blockContext * /*ctx*/) override { }
  virtual void exitPrint_block(lolcodeParser::Print_blockContext * /*ctx*/) override { }

  virtual void enterInput_block(lolcodeParser::Input_blockContext * /*ctx*/) override { }
  virtual void exitInput_block(lolcodeParser::Input_blockContext * /*ctx*/) override { }

  virtual void enterAssignment(lolcodeParser::AssignmentContext * /*ctx*/) override { }
  virtual void exitAssignment(lolcodeParser::AssignmentContext * /*ctx*/) override { }

  virtual void enterLoop(lolcodeParser::LoopContext * /*ctx*/) override { }
  virtual void exitLoop(lolcodeParser::LoopContext * /*ctx*/) override { }

  virtual void enterIf_block(lolcodeParser::If_blockContext * /*ctx*/) override { }
  virtual void exitIf_block(lolcodeParser::If_blockContext * /*ctx*/) override { }

  virtual void enterElse_if_block(lolcodeParser::Else_if_blockContext * /*ctx*/) override { }
  virtual void exitElse_if_block(lolcodeParser::Else_if_blockContext * /*ctx*/) override { }

  virtual void enterFunc_decl(lolcodeParser::Func_declContext * /*ctx*/) override { }
  virtual void exitFunc_decl(lolcodeParser::Func_declContext * /*ctx*/) override { }

  virtual void enterExpression(lolcodeParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(lolcodeParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterMaths(lolcodeParser::MathsContext * /*ctx*/) override { }
  virtual void exitMaths(lolcodeParser::MathsContext * /*ctx*/) override { }

  virtual void enterComparison(lolcodeParser::ComparisonContext * /*ctx*/) override { }
  virtual void exitComparison(lolcodeParser::ComparisonContext * /*ctx*/) override { }

  virtual void enterLogical(lolcodeParser::LogicalContext * /*ctx*/) override { }
  virtual void exitLogical(lolcodeParser::LogicalContext * /*ctx*/) override { }

  virtual void enterUnary_op(lolcodeParser::Unary_opContext * /*ctx*/) override { }
  virtual void exitUnary_op(lolcodeParser::Unary_opContext * /*ctx*/) override { }

  virtual void enterFunc_call(lolcodeParser::Func_callContext * /*ctx*/) override { }
  virtual void exitFunc_call(lolcodeParser::Func_callContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

}  // namespace LOLCODE
