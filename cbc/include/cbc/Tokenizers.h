#ifndef CBC_TOKENIZERS_H
#define CBC_TOKENIZERS_H

#include "Driver.h"
#include "common/Token.h"
#include "lexer/ITokenizer.h"

#include <string_view>

namespace cb {

class IdentifierTokenizer : public lexer::ITokenizer {
public:
  std::pair<common::Token, std::string>
  tokenize(std::string_view Word) override;
};

class IntegralNumberTokenizer : public lexer::ITokenizer {
public:
  std::pair<common::Token, std::string>
  tokenize(std::string_view Word) override;
};

class KeywordTokenizer : public lexer::ITokenizer {
public:
  KeywordTokenizer(TokenID TokId, std::string Keyword);

  std::pair<common::Token, std::string>
  tokenize(std::string_view Word) override;

private:
  TokenID ID;
  std::string KeywordString;
};

} // namespace cb

#endif
