#ifndef CBC_DRIVER_H
#define CBC_DRIVER_H

#include <map>
namespace cb {

enum TokenID {
  EndOfFile,
  Identifier,
  IntegralNumber,
  ExpressionSeparator,
  ArgumentSeparator,
  BinaryOperatorsRangeBegin,
  Assignment,
  Plus,
  Minus,
  Multiplication,
  ShiftLeft,
  ShiftRight,
  BinaryOperatorsRangeEnd,
  Definition,
  ExternalDeclaration,
  BodyBegin,
  BodyEnd,
  OpenParantheses,
  CloseParantheses
};

enum TokenPriority { Unmatched = 0, Normal = 1, High = 2 };

enum OperatorID {
  AssignmentOp = TokenID::Assignment,
  PlusOp = TokenID::Plus,
  MinusOp = TokenID::Minus,
  ShiftLeftOp = TokenID::ShiftLeft,
  ShiftRightOp = TokenID::ShiftRight
};

enum OperatorAssociativity { Left, Right };

const std::map<OperatorID, int> &operatorPrecedenceTable();

const std::map<OperatorID, OperatorAssociativity> &operatorAssociativityTable();

} // namespace cb

#endif
