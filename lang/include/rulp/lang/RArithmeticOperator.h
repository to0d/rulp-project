// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_ARITHMETIC_OPERATOR_H__
#define __RULP_LANG_ARITHMETIC_OPERATOR_H__
#include "rulp/lang/base.h"
namespace lfc {

enum class RArithmeticOperator {
    ADD  = 0  // +
  , SUB       // -
  , BY        // *
  , DIV       // /  
  , MOD       // %
  , POWER     // power 
  , AND       // &  
  , OR        // |  
  , NOT       // ~  
  , XOR       // ^
};

std::string to_op_string(RArithmeticOperator op);

} // namespace lfc

#endif //__RULP_LANG_ARITHMETIC_OPERATOR_H__