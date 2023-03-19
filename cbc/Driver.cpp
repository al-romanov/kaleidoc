#include "cbc/Driver.h"
#include <map>

namespace cb {

const std::map<OperatorID, int> &operatorPrecedenceTable() {
  enum PrecedenceValues { Min = 1, Middle = 4, Max = 8 };
  static std::map<OperatorID, int> OperatorPrecedenceTable = {
      {MultiplicationOp, Max},   {AdditionOp, Max - 1},
      {SubstractionOp, Max - 1}, {ShiftLeftOp, Middle},
      {ShiftRightOp, Middle},    {AssignmentOp, Min}};
  return OperatorPrecedenceTable;
}

const std::map<OperatorID, OperatorAssociativity> &
operatorAssociativityTable() {
  static std::map<OperatorID, OperatorAssociativity>
      OperatorAssociativityTable = {
          {MultiplicationOp, Left}, {AdditionOp, Left},
          {SubstractionOp, Left},   {ShiftLeftOp, Right},
          {ShiftRightOp, Right},    {AssignmentOp, Left}};
  return OperatorAssociativityTable;
}

} // namespace cb