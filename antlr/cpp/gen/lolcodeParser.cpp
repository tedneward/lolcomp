
// Generated from ../lolcode.g4 by ANTLR 4.13.1


#include "lolcodeListener.h"
#include "lolcodeVisitor.h"

#include "lolcodeParser.h"


using namespace antlrcpp;
using namespace LOLCODE;

using namespace antlr4;

namespace {

struct LolcodeParserStaticData final {
  LolcodeParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  LolcodeParserStaticData(const LolcodeParserStaticData&) = delete;
  LolcodeParserStaticData(LolcodeParserStaticData&&) = delete;
  LolcodeParserStaticData& operator=(const LolcodeParserStaticData&) = delete;
  LolcodeParserStaticData& operator=(LolcodeParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag lolcodeParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
LolcodeParserStaticData *lolcodeParserStaticData = nullptr;

void lolcodeParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (lolcodeParserStaticData != nullptr) {
    return;
  }
#else
  assert(lolcodeParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<LolcodeParserStaticData>(
    std::vector<std::string>{
      "program", "opening", "version", "closing", "code_block", "statement", 
      "comment", "declaration", "print_block", "input_block", "assignment", 
      "loop", "if_block", "else_if_block", "func_decl", "expression", "maths", 
      "comparison", "logical", "unary_op", "func_call"
    },
    std::vector<std::string>{
      "", "'HAI'", "'1.0'", "'1.1'", "'1.2'", "'KTHXBYE'", "'I HAS A'", 
      "'ITZ'", "'VISIBLE'", "'MKAY\\u003F'", "'GIMMEH'", "'R'", "'IM IN YR'", 
      "'WILE'", "'IM OUTTA YR'", "', O RLY\\u003F'", "'YA RLY'", "'OIC'", 
      "'NO WAI'", "'MEBBE'", "'HOW DUZ I'", "'YR'", "'AN YR'", "'IF U SAY SO'", 
      "'PRODUKT OF'", "'QUOSHUNT OF'", "'MOD OF'", "'AN'", "'SUM OF'", "'DIFF OF'", 
      "'BOTH SAEM'", "'DIFFRINT'", "'BIGGR OF'", "'SMALLR OF'", "'ALL OF'", 
      "'ANY OF'", "'BOTH OF'", "'EITHER OF'", "'NOT'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "ATOM", "LABEL", "STRING", "NEWLINE", "WS", "SINGLE_LINE_COMMENT", 
      "MULTI_LINE_COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,45,213,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,1,0,3,
  	0,44,8,0,1,0,1,0,3,0,48,8,0,1,0,3,0,51,8,0,1,0,1,0,1,1,1,1,3,1,57,8,1,
  	1,2,1,2,1,3,1,3,1,4,4,4,64,8,4,11,4,12,4,65,1,5,1,5,1,5,1,5,1,5,1,5,1,
  	5,1,5,1,5,3,5,77,8,5,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,7,3,7,87,8,7,1,8,1,
  	8,5,8,91,8,8,10,8,12,8,94,9,8,1,8,3,8,97,8,8,1,9,1,9,1,9,1,10,1,10,1,
  	10,1,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,12,1,12,1,12,1,12,1,
  	12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,3,12,128,8,12,1,13,1,
  	13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,3,13,139,8,13,1,14,1,14,1,14,1,
  	14,1,14,1,14,1,14,5,14,148,8,14,10,14,12,14,151,9,14,3,14,153,8,14,1,
  	14,1,14,1,14,1,15,1,15,1,15,1,15,1,15,1,15,1,15,3,15,165,8,15,1,16,1,
  	16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,3,16,177,8,16,1,17,1,17,1,
  	17,1,17,1,17,1,18,1,18,1,18,1,18,5,18,188,8,18,10,18,12,18,191,9,18,1,
  	18,1,18,1,18,1,18,1,18,1,18,1,18,3,18,200,8,18,1,19,1,19,1,19,1,20,1,
  	20,4,20,207,8,20,11,20,12,20,208,1,20,1,20,1,20,0,0,21,0,2,4,6,8,10,12,
  	14,16,18,20,22,24,26,28,30,32,34,36,38,40,0,7,1,0,2,4,1,0,44,45,1,0,24,
  	26,1,0,28,29,1,0,30,33,1,0,34,35,1,0,36,37,221,0,43,1,0,0,0,2,54,1,0,
  	0,0,4,58,1,0,0,0,6,60,1,0,0,0,8,63,1,0,0,0,10,76,1,0,0,0,12,78,1,0,0,
  	0,14,86,1,0,0,0,16,88,1,0,0,0,18,98,1,0,0,0,20,101,1,0,0,0,22,105,1,0,
  	0,0,24,127,1,0,0,0,26,138,1,0,0,0,28,140,1,0,0,0,30,164,1,0,0,0,32,176,
  	1,0,0,0,34,178,1,0,0,0,36,199,1,0,0,0,38,201,1,0,0,0,40,204,1,0,0,0,42,
  	44,3,12,6,0,43,42,1,0,0,0,43,44,1,0,0,0,44,45,1,0,0,0,45,47,3,2,1,0,46,
  	48,3,8,4,0,47,46,1,0,0,0,47,48,1,0,0,0,48,50,1,0,0,0,49,51,3,6,3,0,50,
  	49,1,0,0,0,50,51,1,0,0,0,51,52,1,0,0,0,52,53,5,0,0,1,53,1,1,0,0,0,54,
  	56,5,1,0,0,55,57,3,4,2,0,56,55,1,0,0,0,56,57,1,0,0,0,57,3,1,0,0,0,58,
  	59,7,0,0,0,59,5,1,0,0,0,60,61,5,5,0,0,61,7,1,0,0,0,62,64,3,10,5,0,63,
  	62,1,0,0,0,64,65,1,0,0,0,65,63,1,0,0,0,65,66,1,0,0,0,66,9,1,0,0,0,67,
  	77,3,14,7,0,68,77,3,30,15,0,69,77,3,12,6,0,70,77,3,16,8,0,71,77,3,18,
  	9,0,72,77,3,20,10,0,73,77,3,24,12,0,74,77,3,22,11,0,75,77,3,28,14,0,76,
  	67,1,0,0,0,76,68,1,0,0,0,76,69,1,0,0,0,76,70,1,0,0,0,76,71,1,0,0,0,76,
  	72,1,0,0,0,76,73,1,0,0,0,76,74,1,0,0,0,76,75,1,0,0,0,77,11,1,0,0,0,78,
  	79,7,1,0,0,79,13,1,0,0,0,80,81,5,6,0,0,81,87,5,40,0,0,82,83,5,6,0,0,83,
  	84,5,40,0,0,84,85,5,7,0,0,85,87,3,30,15,0,86,80,1,0,0,0,86,82,1,0,0,0,
  	87,15,1,0,0,0,88,92,5,8,0,0,89,91,3,30,15,0,90,89,1,0,0,0,91,94,1,0,0,
  	0,92,90,1,0,0,0,92,93,1,0,0,0,93,96,1,0,0,0,94,92,1,0,0,0,95,97,5,9,0,
  	0,96,95,1,0,0,0,96,97,1,0,0,0,97,17,1,0,0,0,98,99,5,10,0,0,99,100,5,40,
  	0,0,100,19,1,0,0,0,101,102,5,40,0,0,102,103,5,11,0,0,103,104,3,30,15,
  	0,104,21,1,0,0,0,105,106,5,12,0,0,106,107,5,40,0,0,107,108,5,13,0,0,108,
  	109,3,30,15,0,109,110,3,8,4,0,110,111,5,14,0,0,111,112,5,40,0,0,112,23,
  	1,0,0,0,113,114,3,30,15,0,114,115,5,15,0,0,115,116,5,16,0,0,116,117,3,
  	8,4,0,117,118,5,17,0,0,118,128,1,0,0,0,119,120,3,30,15,0,120,121,5,15,
  	0,0,121,122,5,16,0,0,122,123,3,8,4,0,123,124,5,18,0,0,124,125,3,8,4,0,
  	125,126,5,17,0,0,126,128,1,0,0,0,127,113,1,0,0,0,127,119,1,0,0,0,128,
  	25,1,0,0,0,129,130,5,19,0,0,130,131,3,30,15,0,131,132,3,8,4,0,132,133,
  	3,26,13,0,133,139,1,0,0,0,134,135,5,19,0,0,135,136,3,30,15,0,136,137,
  	3,8,4,0,137,139,1,0,0,0,138,129,1,0,0,0,138,134,1,0,0,0,139,27,1,0,0,
  	0,140,141,5,20,0,0,141,152,5,40,0,0,142,143,5,21,0,0,143,144,5,40,0,0,
  	144,149,1,0,0,0,145,146,5,22,0,0,146,148,5,40,0,0,147,145,1,0,0,0,148,
  	151,1,0,0,0,149,147,1,0,0,0,149,150,1,0,0,0,150,153,1,0,0,0,151,149,1,
  	0,0,0,152,142,1,0,0,0,152,153,1,0,0,0,153,154,1,0,0,0,154,155,3,8,4,0,
  	155,156,5,23,0,0,156,29,1,0,0,0,157,165,3,32,16,0,158,165,3,34,17,0,159,
  	165,3,36,18,0,160,165,3,38,19,0,161,165,3,40,20,0,162,165,5,39,0,0,163,
  	165,5,40,0,0,164,157,1,0,0,0,164,158,1,0,0,0,164,159,1,0,0,0,164,160,
  	1,0,0,0,164,161,1,0,0,0,164,162,1,0,0,0,164,163,1,0,0,0,165,31,1,0,0,
  	0,166,167,7,2,0,0,167,168,3,30,15,0,168,169,5,27,0,0,169,170,3,30,15,
  	0,170,177,1,0,0,0,171,172,7,3,0,0,172,173,3,30,15,0,173,174,5,27,0,0,
  	174,175,3,30,15,0,175,177,1,0,0,0,176,166,1,0,0,0,176,171,1,0,0,0,177,
  	33,1,0,0,0,178,179,7,4,0,0,179,180,3,30,15,0,180,181,5,27,0,0,181,182,
  	3,30,15,0,182,35,1,0,0,0,183,184,7,5,0,0,184,189,3,30,15,0,185,186,5,
  	27,0,0,186,188,3,30,15,0,187,185,1,0,0,0,188,191,1,0,0,0,189,187,1,0,
  	0,0,189,190,1,0,0,0,190,192,1,0,0,0,191,189,1,0,0,0,192,193,5,9,0,0,193,
  	200,1,0,0,0,194,195,7,6,0,0,195,196,3,30,15,0,196,197,5,27,0,0,197,198,
  	3,30,15,0,198,200,1,0,0,0,199,183,1,0,0,0,199,194,1,0,0,0,200,37,1,0,
  	0,0,201,202,5,38,0,0,202,203,3,30,15,0,203,39,1,0,0,0,204,206,5,40,0,
  	0,205,207,3,30,15,0,206,205,1,0,0,0,207,208,1,0,0,0,208,206,1,0,0,0,208,
  	209,1,0,0,0,209,210,1,0,0,0,210,211,5,9,0,0,211,41,1,0,0,0,18,43,47,50,
  	56,65,76,86,92,96,127,138,149,152,164,176,189,199,208
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  lolcodeParserStaticData = staticData.release();
}

}

lolcodeParser::lolcodeParser(TokenStream *input) : lolcodeParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

lolcodeParser::lolcodeParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  lolcodeParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *lolcodeParserStaticData->atn, lolcodeParserStaticData->decisionToDFA, lolcodeParserStaticData->sharedContextCache, options);
}

lolcodeParser::~lolcodeParser() {
  delete _interpreter;
}

const atn::ATN& lolcodeParser::getATN() const {
  return *lolcodeParserStaticData->atn;
}

std::string lolcodeParser::getGrammarFileName() const {
  return "lolcode.g4";
}

const std::vector<std::string>& lolcodeParser::getRuleNames() const {
  return lolcodeParserStaticData->ruleNames;
}

const dfa::Vocabulary& lolcodeParser::getVocabulary() const {
  return lolcodeParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView lolcodeParser::getSerializedATN() const {
  return lolcodeParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

lolcodeParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

lolcodeParser::OpeningContext* lolcodeParser::ProgramContext::opening() {
  return getRuleContext<lolcodeParser::OpeningContext>(0);
}

tree::TerminalNode* lolcodeParser::ProgramContext::EOF() {
  return getToken(lolcodeParser::EOF, 0);
}

lolcodeParser::CommentContext* lolcodeParser::ProgramContext::comment() {
  return getRuleContext<lolcodeParser::CommentContext>(0);
}

lolcodeParser::Code_blockContext* lolcodeParser::ProgramContext::code_block() {
  return getRuleContext<lolcodeParser::Code_blockContext>(0);
}

lolcodeParser::ClosingContext* lolcodeParser::ProgramContext::closing() {
  return getRuleContext<lolcodeParser::ClosingContext>(0);
}


size_t lolcodeParser::ProgramContext::getRuleIndex() const {
  return lolcodeParser::RuleProgram;
}

void lolcodeParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lolcodeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void lolcodeParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lolcodeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


std::any lolcodeParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lolcodeVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

lolcodeParser::ProgramContext* lolcodeParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, lolcodeParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(43);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == lolcodeParser::SINGLE_LINE_COMMENT

    || _la == lolcodeParser::MULTI_LINE_COMMENT) {
      setState(42);
      comment();
    }
    setState(45);
    opening();
    setState(47);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 54975431447872) != 0)) {
      setState(46);
      code_block();
    }
    setState(50);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == lolcodeParser::T__4) {
      setState(49);
      closing();
    }
    setState(52);
    match(lolcodeParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OpeningContext ------------------------------------------------------------------

lolcodeParser::OpeningContext::OpeningContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

lolcodeParser::VersionContext* lolcodeParser::OpeningContext::version() {
  return getRuleContext<lolcodeParser::VersionContext>(0);
}


size_t lolcodeParser::OpeningContext::getRuleIndex() const {
  return lolcodeParser::RuleOpening;
}

void lolcodeParser::OpeningContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lolcodeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOpening(this);
}

void lolcodeParser::OpeningContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lolcodeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOpening(this);
}


std::any lolcodeParser::OpeningContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lolcodeVisitor*>(visitor))
    return parserVisitor->visitOpening(this);
  else
    return visitor->visitChildren(this);
}

lolcodeParser::OpeningContext* lolcodeParser::opening() {
  OpeningContext *_localctx = _tracker.createInstance<OpeningContext>(_ctx, getState());
  enterRule(_localctx, 2, lolcodeParser::RuleOpening);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(54);
    match(lolcodeParser::T__0);
    setState(56);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 28) != 0)) {
      setState(55);
      version();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VersionContext ------------------------------------------------------------------

lolcodeParser::VersionContext::VersionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t lolcodeParser::VersionContext::getRuleIndex() const {
  return lolcodeParser::RuleVersion;
}

void lolcodeParser::VersionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lolcodeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVersion(this);
}

void lolcodeParser::VersionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lolcodeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVersion(this);
}


std::any lolcodeParser::VersionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lolcodeVisitor*>(visitor))
    return parserVisitor->visitVersion(this);
  else
    return visitor->visitChildren(this);
}

lolcodeParser::VersionContext* lolcodeParser::version() {
  VersionContext *_localctx = _tracker.createInstance<VersionContext>(_ctx, getState());
  enterRule(_localctx, 4, lolcodeParser::RuleVersion);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(58);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 28) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClosingContext ------------------------------------------------------------------

lolcodeParser::ClosingContext::ClosingContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t lolcodeParser::ClosingContext::getRuleIndex() const {
  return lolcodeParser::RuleClosing;
}

void lolcodeParser::ClosingContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lolcodeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClosing(this);
}

void lolcodeParser::ClosingContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lolcodeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClosing(this);
}


std::any lolcodeParser::ClosingContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lolcodeVisitor*>(visitor))
    return parserVisitor->visitClosing(this);
  else
    return visitor->visitChildren(this);
}

lolcodeParser::ClosingContext* lolcodeParser::closing() {
  ClosingContext *_localctx = _tracker.createInstance<ClosingContext>(_ctx, getState());
  enterRule(_localctx, 6, lolcodeParser::RuleClosing);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(60);
    match(lolcodeParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Code_blockContext ------------------------------------------------------------------

lolcodeParser::Code_blockContext::Code_blockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<lolcodeParser::StatementContext *> lolcodeParser::Code_blockContext::statement() {
  return getRuleContexts<lolcodeParser::StatementContext>();
}

lolcodeParser::StatementContext* lolcodeParser::Code_blockContext::statement(size_t i) {
  return getRuleContext<lolcodeParser::StatementContext>(i);
}


size_t lolcodeParser::Code_blockContext::getRuleIndex() const {
  return lolcodeParser::RuleCode_block;
}

void lolcodeParser::Code_blockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lolcodeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCode_block(this);
}

void lolcodeParser::Code_blockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lolcodeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCode_block(this);
}


std::any lolcodeParser::Code_blockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lolcodeVisitor*>(visitor))
    return parserVisitor->visitCode_block(this);
  else
    return visitor->visitChildren(this);
}

lolcodeParser::Code_blockContext* lolcodeParser::code_block() {
  Code_blockContext *_localctx = _tracker.createInstance<Code_blockContext>(_ctx, getState());
  enterRule(_localctx, 8, lolcodeParser::RuleCode_block);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(63); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(62);
      statement();
      setState(65); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 54975431447872) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

lolcodeParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

lolcodeParser::DeclarationContext* lolcodeParser::StatementContext::declaration() {
  return getRuleContext<lolcodeParser::DeclarationContext>(0);
}

lolcodeParser::ExpressionContext* lolcodeParser::StatementContext::expression() {
  return getRuleContext<lolcodeParser::ExpressionContext>(0);
}

lolcodeParser::CommentContext* lolcodeParser::StatementContext::comment() {
  return getRuleContext<lolcodeParser::CommentContext>(0);
}

lolcodeParser::Print_blockContext* lolcodeParser::StatementContext::print_block() {
  return getRuleContext<lolcodeParser::Print_blockContext>(0);
}

lolcodeParser::Input_blockContext* lolcodeParser::StatementContext::input_block() {
  return getRuleContext<lolcodeParser::Input_blockContext>(0);
}

lolcodeParser::AssignmentContext* lolcodeParser::StatementContext::assignment() {
  return getRuleContext<lolcodeParser::AssignmentContext>(0);
}

lolcodeParser::If_blockContext* lolcodeParser::StatementContext::if_block() {
  return getRuleContext<lolcodeParser::If_blockContext>(0);
}

lolcodeParser::LoopContext* lolcodeParser::StatementContext::loop() {
  return getRuleContext<lolcodeParser::LoopContext>(0);
}

lolcodeParser::Func_declContext* lolcodeParser::StatementContext::func_decl() {
  return getRuleContext<lolcodeParser::Func_declContext>(0);
}


size_t lolcodeParser::StatementContext::getRuleIndex() const {
  return lolcodeParser::RuleStatement;
}

void lolcodeParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lolcodeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void lolcodeParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lolcodeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


std::any lolcodeParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lolcodeVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

lolcodeParser::StatementContext* lolcodeParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 10, lolcodeParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(76);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(67);
      declaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(68);
      expression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(69);
      comment();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(70);
      print_block();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(71);
      input_block();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(72);
      assignment();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(73);
      if_block();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(74);
      loop();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(75);
      func_decl();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CommentContext ------------------------------------------------------------------

lolcodeParser::CommentContext::CommentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* lolcodeParser::CommentContext::SINGLE_LINE_COMMENT() {
  return getToken(lolcodeParser::SINGLE_LINE_COMMENT, 0);
}

tree::TerminalNode* lolcodeParser::CommentContext::MULTI_LINE_COMMENT() {
  return getToken(lolcodeParser::MULTI_LINE_COMMENT, 0);
}


size_t lolcodeParser::CommentContext::getRuleIndex() const {
  return lolcodeParser::RuleComment;
}

void lolcodeParser::CommentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lolcodeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComment(this);
}

void lolcodeParser::CommentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lolcodeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComment(this);
}


std::any lolcodeParser::CommentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lolcodeVisitor*>(visitor))
    return parserVisitor->visitComment(this);
  else
    return visitor->visitChildren(this);
}

lolcodeParser::CommentContext* lolcodeParser::comment() {
  CommentContext *_localctx = _tracker.createInstance<CommentContext>(_ctx, getState());
  enterRule(_localctx, 12, lolcodeParser::RuleComment);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(78);
    _la = _input->LA(1);
    if (!(_la == lolcodeParser::SINGLE_LINE_COMMENT

    || _la == lolcodeParser::MULTI_LINE_COMMENT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationContext ------------------------------------------------------------------

lolcodeParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* lolcodeParser::DeclarationContext::LABEL() {
  return getToken(lolcodeParser::LABEL, 0);
}

lolcodeParser::ExpressionContext* lolcodeParser::DeclarationContext::expression() {
  return getRuleContext<lolcodeParser::ExpressionContext>(0);
}


size_t lolcodeParser::DeclarationContext::getRuleIndex() const {
  return lolcodeParser::RuleDeclaration;
}

void lolcodeParser::DeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lolcodeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration(this);
}

void lolcodeParser::DeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lolcodeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration(this);
}


std::any lolcodeParser::DeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lolcodeVisitor*>(visitor))
    return parserVisitor->visitDeclaration(this);
  else
    return visitor->visitChildren(this);
}

lolcodeParser::DeclarationContext* lolcodeParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 14, lolcodeParser::RuleDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(86);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(80);
      match(lolcodeParser::T__5);
      setState(81);
      match(lolcodeParser::LABEL);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(82);
      match(lolcodeParser::T__5);
      setState(83);
      match(lolcodeParser::LABEL);
      setState(84);
      match(lolcodeParser::T__6);
      setState(85);
      expression();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Print_blockContext ------------------------------------------------------------------

lolcodeParser::Print_blockContext::Print_blockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<lolcodeParser::ExpressionContext *> lolcodeParser::Print_blockContext::expression() {
  return getRuleContexts<lolcodeParser::ExpressionContext>();
}

lolcodeParser::ExpressionContext* lolcodeParser::Print_blockContext::expression(size_t i) {
  return getRuleContext<lolcodeParser::ExpressionContext>(i);
}


size_t lolcodeParser::Print_blockContext::getRuleIndex() const {
  return lolcodeParser::RulePrint_block;
}

void lolcodeParser::Print_blockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lolcodeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrint_block(this);
}

void lolcodeParser::Print_blockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lolcodeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrint_block(this);
}


std::any lolcodeParser::Print_blockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lolcodeVisitor*>(visitor))
    return parserVisitor->visitPrint_block(this);
  else
    return visitor->visitChildren(this);
}

lolcodeParser::Print_blockContext* lolcodeParser::print_block() {
  Print_blockContext *_localctx = _tracker.createInstance<Print_blockContext>(_ctx, getState());
  enterRule(_localctx, 16, lolcodeParser::RulePrint_block);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(88);
    match(lolcodeParser::T__7);
    setState(92);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(89);
        expression(); 
      }
      setState(94);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    }
    setState(96);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == lolcodeParser::T__8) {
      setState(95);
      match(lolcodeParser::T__8);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Input_blockContext ------------------------------------------------------------------

lolcodeParser::Input_blockContext::Input_blockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* lolcodeParser::Input_blockContext::LABEL() {
  return getToken(lolcodeParser::LABEL, 0);
}


size_t lolcodeParser::Input_blockContext::getRuleIndex() const {
  return lolcodeParser::RuleInput_block;
}

void lolcodeParser::Input_blockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lolcodeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInput_block(this);
}

void lolcodeParser::Input_blockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lolcodeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInput_block(this);
}


std::any lolcodeParser::Input_blockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lolcodeVisitor*>(visitor))
    return parserVisitor->visitInput_block(this);
  else
    return visitor->visitChildren(this);
}

lolcodeParser::Input_blockContext* lolcodeParser::input_block() {
  Input_blockContext *_localctx = _tracker.createInstance<Input_blockContext>(_ctx, getState());
  enterRule(_localctx, 18, lolcodeParser::RuleInput_block);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(98);
    match(lolcodeParser::T__9);
    setState(99);
    match(lolcodeParser::LABEL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentContext ------------------------------------------------------------------

lolcodeParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* lolcodeParser::AssignmentContext::LABEL() {
  return getToken(lolcodeParser::LABEL, 0);
}

lolcodeParser::ExpressionContext* lolcodeParser::AssignmentContext::expression() {
  return getRuleContext<lolcodeParser::ExpressionContext>(0);
}


size_t lolcodeParser::AssignmentContext::getRuleIndex() const {
  return lolcodeParser::RuleAssignment;
}

void lolcodeParser::AssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lolcodeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignment(this);
}

void lolcodeParser::AssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lolcodeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignment(this);
}


std::any lolcodeParser::AssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lolcodeVisitor*>(visitor))
    return parserVisitor->visitAssignment(this);
  else
    return visitor->visitChildren(this);
}

lolcodeParser::AssignmentContext* lolcodeParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 20, lolcodeParser::RuleAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(101);
    match(lolcodeParser::LABEL);
    setState(102);
    match(lolcodeParser::T__10);
    setState(103);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LoopContext ------------------------------------------------------------------

lolcodeParser::LoopContext::LoopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> lolcodeParser::LoopContext::LABEL() {
  return getTokens(lolcodeParser::LABEL);
}

tree::TerminalNode* lolcodeParser::LoopContext::LABEL(size_t i) {
  return getToken(lolcodeParser::LABEL, i);
}

lolcodeParser::ExpressionContext* lolcodeParser::LoopContext::expression() {
  return getRuleContext<lolcodeParser::ExpressionContext>(0);
}

lolcodeParser::Code_blockContext* lolcodeParser::LoopContext::code_block() {
  return getRuleContext<lolcodeParser::Code_blockContext>(0);
}


size_t lolcodeParser::LoopContext::getRuleIndex() const {
  return lolcodeParser::RuleLoop;
}

void lolcodeParser::LoopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lolcodeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLoop(this);
}

void lolcodeParser::LoopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lolcodeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLoop(this);
}


std::any lolcodeParser::LoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lolcodeVisitor*>(visitor))
    return parserVisitor->visitLoop(this);
  else
    return visitor->visitChildren(this);
}

lolcodeParser::LoopContext* lolcodeParser::loop() {
  LoopContext *_localctx = _tracker.createInstance<LoopContext>(_ctx, getState());
  enterRule(_localctx, 22, lolcodeParser::RuleLoop);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(105);
    match(lolcodeParser::T__11);
    setState(106);
    match(lolcodeParser::LABEL);
    setState(107);
    match(lolcodeParser::T__12);
    setState(108);
    expression();
    setState(109);
    code_block();
    setState(110);
    match(lolcodeParser::T__13);
    setState(111);
    match(lolcodeParser::LABEL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_blockContext ------------------------------------------------------------------

lolcodeParser::If_blockContext::If_blockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

lolcodeParser::ExpressionContext* lolcodeParser::If_blockContext::expression() {
  return getRuleContext<lolcodeParser::ExpressionContext>(0);
}

std::vector<lolcodeParser::Code_blockContext *> lolcodeParser::If_blockContext::code_block() {
  return getRuleContexts<lolcodeParser::Code_blockContext>();
}

lolcodeParser::Code_blockContext* lolcodeParser::If_blockContext::code_block(size_t i) {
  return getRuleContext<lolcodeParser::Code_blockContext>(i);
}


size_t lolcodeParser::If_blockContext::getRuleIndex() const {
  return lolcodeParser::RuleIf_block;
}

void lolcodeParser::If_blockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lolcodeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIf_block(this);
}

void lolcodeParser::If_blockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lolcodeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIf_block(this);
}


std::any lolcodeParser::If_blockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lolcodeVisitor*>(visitor))
    return parserVisitor->visitIf_block(this);
  else
    return visitor->visitChildren(this);
}

lolcodeParser::If_blockContext* lolcodeParser::if_block() {
  If_blockContext *_localctx = _tracker.createInstance<If_blockContext>(_ctx, getState());
  enterRule(_localctx, 24, lolcodeParser::RuleIf_block);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(127);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(113);
      expression();
      setState(114);
      match(lolcodeParser::T__14);
      setState(115);
      match(lolcodeParser::T__15);
      setState(116);
      code_block();
      setState(117);
      match(lolcodeParser::T__16);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(119);
      expression();
      setState(120);
      match(lolcodeParser::T__14);
      setState(121);
      match(lolcodeParser::T__15);
      setState(122);
      code_block();
      setState(123);
      match(lolcodeParser::T__17);
      setState(124);
      antlrcpp::downCast<If_blockContext *>(_localctx)->elseBlock = code_block();
      setState(125);
      match(lolcodeParser::T__16);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Else_if_blockContext ------------------------------------------------------------------

lolcodeParser::Else_if_blockContext::Else_if_blockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

lolcodeParser::ExpressionContext* lolcodeParser::Else_if_blockContext::expression() {
  return getRuleContext<lolcodeParser::ExpressionContext>(0);
}

lolcodeParser::Code_blockContext* lolcodeParser::Else_if_blockContext::code_block() {
  return getRuleContext<lolcodeParser::Code_blockContext>(0);
}

lolcodeParser::Else_if_blockContext* lolcodeParser::Else_if_blockContext::else_if_block() {
  return getRuleContext<lolcodeParser::Else_if_blockContext>(0);
}


size_t lolcodeParser::Else_if_blockContext::getRuleIndex() const {
  return lolcodeParser::RuleElse_if_block;
}

void lolcodeParser::Else_if_blockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lolcodeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElse_if_block(this);
}

void lolcodeParser::Else_if_blockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lolcodeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElse_if_block(this);
}


std::any lolcodeParser::Else_if_blockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lolcodeVisitor*>(visitor))
    return parserVisitor->visitElse_if_block(this);
  else
    return visitor->visitChildren(this);
}

lolcodeParser::Else_if_blockContext* lolcodeParser::else_if_block() {
  Else_if_blockContext *_localctx = _tracker.createInstance<Else_if_blockContext>(_ctx, getState());
  enterRule(_localctx, 26, lolcodeParser::RuleElse_if_block);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(138);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(129);
      match(lolcodeParser::T__18);
      setState(130);
      expression();
      setState(131);
      code_block();
      setState(132);
      else_if_block();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(134);
      match(lolcodeParser::T__18);
      setState(135);
      expression();
      setState(136);
      code_block();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_declContext ------------------------------------------------------------------

lolcodeParser::Func_declContext::Func_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

lolcodeParser::Code_blockContext* lolcodeParser::Func_declContext::code_block() {
  return getRuleContext<lolcodeParser::Code_blockContext>(0);
}

std::vector<tree::TerminalNode *> lolcodeParser::Func_declContext::LABEL() {
  return getTokens(lolcodeParser::LABEL);
}

tree::TerminalNode* lolcodeParser::Func_declContext::LABEL(size_t i) {
  return getToken(lolcodeParser::LABEL, i);
}


size_t lolcodeParser::Func_declContext::getRuleIndex() const {
  return lolcodeParser::RuleFunc_decl;
}

void lolcodeParser::Func_declContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lolcodeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunc_decl(this);
}

void lolcodeParser::Func_declContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lolcodeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunc_decl(this);
}


std::any lolcodeParser::Func_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lolcodeVisitor*>(visitor))
    return parserVisitor->visitFunc_decl(this);
  else
    return visitor->visitChildren(this);
}

lolcodeParser::Func_declContext* lolcodeParser::func_decl() {
  Func_declContext *_localctx = _tracker.createInstance<Func_declContext>(_ctx, getState());
  enterRule(_localctx, 28, lolcodeParser::RuleFunc_decl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(140);
    match(lolcodeParser::T__19);
    setState(141);
    antlrcpp::downCast<Func_declContext *>(_localctx)->name = match(lolcodeParser::LABEL);
    setState(152);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == lolcodeParser::T__20) {
      setState(142);
      match(lolcodeParser::T__20);
      setState(143);
      match(lolcodeParser::LABEL);
      setState(149);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == lolcodeParser::T__21) {
        setState(145);
        match(lolcodeParser::T__21);
        setState(146);
        match(lolcodeParser::LABEL);
        setState(151);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(154);
    code_block();
    setState(155);
    match(lolcodeParser::T__22);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

lolcodeParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

lolcodeParser::MathsContext* lolcodeParser::ExpressionContext::maths() {
  return getRuleContext<lolcodeParser::MathsContext>(0);
}

lolcodeParser::ComparisonContext* lolcodeParser::ExpressionContext::comparison() {
  return getRuleContext<lolcodeParser::ComparisonContext>(0);
}

lolcodeParser::LogicalContext* lolcodeParser::ExpressionContext::logical() {
  return getRuleContext<lolcodeParser::LogicalContext>(0);
}

lolcodeParser::Unary_opContext* lolcodeParser::ExpressionContext::unary_op() {
  return getRuleContext<lolcodeParser::Unary_opContext>(0);
}

lolcodeParser::Func_callContext* lolcodeParser::ExpressionContext::func_call() {
  return getRuleContext<lolcodeParser::Func_callContext>(0);
}

tree::TerminalNode* lolcodeParser::ExpressionContext::ATOM() {
  return getToken(lolcodeParser::ATOM, 0);
}

tree::TerminalNode* lolcodeParser::ExpressionContext::LABEL() {
  return getToken(lolcodeParser::LABEL, 0);
}


size_t lolcodeParser::ExpressionContext::getRuleIndex() const {
  return lolcodeParser::RuleExpression;
}

void lolcodeParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lolcodeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void lolcodeParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lolcodeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


std::any lolcodeParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lolcodeVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

lolcodeParser::ExpressionContext* lolcodeParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 30, lolcodeParser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(164);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(157);
      maths();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(158);
      comparison();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(159);
      logical();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(160);
      unary_op();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(161);
      func_call();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(162);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->atom = match(lolcodeParser::ATOM);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(163);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->label = match(lolcodeParser::LABEL);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MathsContext ------------------------------------------------------------------

lolcodeParser::MathsContext::MathsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<lolcodeParser::ExpressionContext *> lolcodeParser::MathsContext::expression() {
  return getRuleContexts<lolcodeParser::ExpressionContext>();
}

lolcodeParser::ExpressionContext* lolcodeParser::MathsContext::expression(size_t i) {
  return getRuleContext<lolcodeParser::ExpressionContext>(i);
}


size_t lolcodeParser::MathsContext::getRuleIndex() const {
  return lolcodeParser::RuleMaths;
}

void lolcodeParser::MathsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lolcodeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMaths(this);
}

void lolcodeParser::MathsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lolcodeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMaths(this);
}


std::any lolcodeParser::MathsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lolcodeVisitor*>(visitor))
    return parserVisitor->visitMaths(this);
  else
    return visitor->visitChildren(this);
}

lolcodeParser::MathsContext* lolcodeParser::maths() {
  MathsContext *_localctx = _tracker.createInstance<MathsContext>(_ctx, getState());
  enterRule(_localctx, 32, lolcodeParser::RuleMaths);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(176);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case lolcodeParser::T__23:
      case lolcodeParser::T__24:
      case lolcodeParser::T__25: {
        enterOuterAlt(_localctx, 1);
        setState(166);
        antlrcpp::downCast<MathsContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 117440512) != 0))) {
          antlrcpp::downCast<MathsContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(167);
        antlrcpp::downCast<MathsContext *>(_localctx)->left = expression();
        setState(168);
        match(lolcodeParser::T__26);
        setState(169);
        antlrcpp::downCast<MathsContext *>(_localctx)->right = expression();
        break;
      }

      case lolcodeParser::T__27:
      case lolcodeParser::T__28: {
        enterOuterAlt(_localctx, 2);
        setState(171);
        antlrcpp::downCast<MathsContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == lolcodeParser::T__27

        || _la == lolcodeParser::T__28)) {
          antlrcpp::downCast<MathsContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(172);
        antlrcpp::downCast<MathsContext *>(_localctx)->left = expression();
        setState(173);
        match(lolcodeParser::T__26);
        setState(174);
        antlrcpp::downCast<MathsContext *>(_localctx)->right = expression();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ComparisonContext ------------------------------------------------------------------

lolcodeParser::ComparisonContext::ComparisonContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<lolcodeParser::ExpressionContext *> lolcodeParser::ComparisonContext::expression() {
  return getRuleContexts<lolcodeParser::ExpressionContext>();
}

lolcodeParser::ExpressionContext* lolcodeParser::ComparisonContext::expression(size_t i) {
  return getRuleContext<lolcodeParser::ExpressionContext>(i);
}


size_t lolcodeParser::ComparisonContext::getRuleIndex() const {
  return lolcodeParser::RuleComparison;
}

void lolcodeParser::ComparisonContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lolcodeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComparison(this);
}

void lolcodeParser::ComparisonContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lolcodeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComparison(this);
}


std::any lolcodeParser::ComparisonContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lolcodeVisitor*>(visitor))
    return parserVisitor->visitComparison(this);
  else
    return visitor->visitChildren(this);
}

lolcodeParser::ComparisonContext* lolcodeParser::comparison() {
  ComparisonContext *_localctx = _tracker.createInstance<ComparisonContext>(_ctx, getState());
  enterRule(_localctx, 34, lolcodeParser::RuleComparison);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(178);
    antlrcpp::downCast<ComparisonContext *>(_localctx)->op = _input->LT(1);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 16106127360) != 0))) {
      antlrcpp::downCast<ComparisonContext *>(_localctx)->op = _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(179);
    antlrcpp::downCast<ComparisonContext *>(_localctx)->left = expression();
    setState(180);
    match(lolcodeParser::T__26);
    setState(181);
    antlrcpp::downCast<ComparisonContext *>(_localctx)->right = expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LogicalContext ------------------------------------------------------------------

lolcodeParser::LogicalContext::LogicalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<lolcodeParser::ExpressionContext *> lolcodeParser::LogicalContext::expression() {
  return getRuleContexts<lolcodeParser::ExpressionContext>();
}

lolcodeParser::ExpressionContext* lolcodeParser::LogicalContext::expression(size_t i) {
  return getRuleContext<lolcodeParser::ExpressionContext>(i);
}


size_t lolcodeParser::LogicalContext::getRuleIndex() const {
  return lolcodeParser::RuleLogical;
}

void lolcodeParser::LogicalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lolcodeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogical(this);
}

void lolcodeParser::LogicalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lolcodeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogical(this);
}


std::any lolcodeParser::LogicalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lolcodeVisitor*>(visitor))
    return parserVisitor->visitLogical(this);
  else
    return visitor->visitChildren(this);
}

lolcodeParser::LogicalContext* lolcodeParser::logical() {
  LogicalContext *_localctx = _tracker.createInstance<LogicalContext>(_ctx, getState());
  enterRule(_localctx, 36, lolcodeParser::RuleLogical);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(199);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case lolcodeParser::T__33:
      case lolcodeParser::T__34: {
        enterOuterAlt(_localctx, 1);
        setState(183);
        antlrcpp::downCast<LogicalContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == lolcodeParser::T__33

        || _la == lolcodeParser::T__34)) {
          antlrcpp::downCast<LogicalContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(184);
        expression();
        setState(189);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == lolcodeParser::T__26) {
          setState(185);
          match(lolcodeParser::T__26);
          setState(186);
          expression();
          setState(191);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(192);
        match(lolcodeParser::T__8);
        break;
      }

      case lolcodeParser::T__35:
      case lolcodeParser::T__36: {
        enterOuterAlt(_localctx, 2);
        setState(194);
        antlrcpp::downCast<LogicalContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == lolcodeParser::T__35

        || _la == lolcodeParser::T__36)) {
          antlrcpp::downCast<LogicalContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(195);
        antlrcpp::downCast<LogicalContext *>(_localctx)->left = expression();
        setState(196);
        match(lolcodeParser::T__26);
        setState(197);
        antlrcpp::downCast<LogicalContext *>(_localctx)->right = expression();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Unary_opContext ------------------------------------------------------------------

lolcodeParser::Unary_opContext::Unary_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

lolcodeParser::ExpressionContext* lolcodeParser::Unary_opContext::expression() {
  return getRuleContext<lolcodeParser::ExpressionContext>(0);
}


size_t lolcodeParser::Unary_opContext::getRuleIndex() const {
  return lolcodeParser::RuleUnary_op;
}

void lolcodeParser::Unary_opContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lolcodeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnary_op(this);
}

void lolcodeParser::Unary_opContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lolcodeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnary_op(this);
}


std::any lolcodeParser::Unary_opContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lolcodeVisitor*>(visitor))
    return parserVisitor->visitUnary_op(this);
  else
    return visitor->visitChildren(this);
}

lolcodeParser::Unary_opContext* lolcodeParser::unary_op() {
  Unary_opContext *_localctx = _tracker.createInstance<Unary_opContext>(_ctx, getState());
  enterRule(_localctx, 38, lolcodeParser::RuleUnary_op);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(201);
    match(lolcodeParser::T__37);
    setState(202);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_callContext ------------------------------------------------------------------

lolcodeParser::Func_callContext::Func_callContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* lolcodeParser::Func_callContext::LABEL() {
  return getToken(lolcodeParser::LABEL, 0);
}

std::vector<lolcodeParser::ExpressionContext *> lolcodeParser::Func_callContext::expression() {
  return getRuleContexts<lolcodeParser::ExpressionContext>();
}

lolcodeParser::ExpressionContext* lolcodeParser::Func_callContext::expression(size_t i) {
  return getRuleContext<lolcodeParser::ExpressionContext>(i);
}


size_t lolcodeParser::Func_callContext::getRuleIndex() const {
  return lolcodeParser::RuleFunc_call;
}

void lolcodeParser::Func_callContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lolcodeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunc_call(this);
}

void lolcodeParser::Func_callContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lolcodeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunc_call(this);
}


std::any lolcodeParser::Func_callContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lolcodeVisitor*>(visitor))
    return parserVisitor->visitFunc_call(this);
  else
    return visitor->visitChildren(this);
}

lolcodeParser::Func_callContext* lolcodeParser::func_call() {
  Func_callContext *_localctx = _tracker.createInstance<Func_callContext>(_ctx, getState());
  enterRule(_localctx, 40, lolcodeParser::RuleFunc_call);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(204);
    antlrcpp::downCast<Func_callContext *>(_localctx)->name = match(lolcodeParser::LABEL);
    setState(206); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(205);
      expression();
      setState(208); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2198872260608) != 0));
    setState(210);
    match(lolcodeParser::T__8);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void lolcodeParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  lolcodeParserInitialize();
#else
  ::antlr4::internal::call_once(lolcodeParserOnceFlag, lolcodeParserInitialize);
#endif
}
