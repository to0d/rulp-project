// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/lang/RRelationalOperator.h"

namespace lfc {

std::string to_op_string(RRelationalOperator op){
  switch (op)
  {
    case lfc::RRelationalOperator::EQ   : return "EQ";
    case lfc::RRelationalOperator::GE   : return "GE";
    case lfc::RRelationalOperator::GT   : return "GT";
    case lfc::RRelationalOperator::LE   : return "LE";
    case lfc::RRelationalOperator::LT   : return "LT";
    case lfc::RRelationalOperator::NE   : return "NE";
    default:                               return "BAD";
  }
}

} // namespace lfc
