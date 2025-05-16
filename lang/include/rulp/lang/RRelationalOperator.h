// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_RELATIONAL_OPRATOR_H__
#define __RULP_LANG_RELATIONAL_OPRATOR_H__
#include "rulp/lang/base.h"
namespace lfc {

enum class RRelationalOperator {
    EQ // =, Equal
  , GE // >=, Greater than or equal
  , GT // >, Greater than
  , LE // <=, Less than or equal
  , LT // <, Less than
  , NE // !=, Not equal
};

std::string to_op_string(RRelationalOperator op);

RRelationalOperator oppositeOf(RRelationalOperator op);

} // namespace lfc

#endif //__RULP_LANG_RELATIONAL_OPRATOR_H__