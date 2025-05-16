// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/lang/RArithmeticOperator.h"

namespace lfc {

std::string to_op_string(RArithmeticOperator op){
  switch (op)
  {
    case lfc::RArithmeticOperator::ADD   : return "ADD";
    case lfc::RArithmeticOperator::SUB   : return "SUB";
    case lfc::RArithmeticOperator::BY    : return "BY";
    case lfc::RArithmeticOperator::DIV   : return "DIV";
    case lfc::RArithmeticOperator::MOD   : return "MOD";
    case lfc::RArithmeticOperator::POWER : return "POWER";
    case lfc::RArithmeticOperator::AND   : return "AND";
    case lfc::RArithmeticOperator::OR    : return "OR";
    case lfc::RArithmeticOperator::NOT   : return "NOT";
    case lfc::RArithmeticOperator::XOR   : return "XOR";
    default:      return "BAD";
  }
}

} // namespace lfc
