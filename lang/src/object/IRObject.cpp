// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/object/IRObject.h"
#include "rulp/utils/RulpUtil.h"

#include "lfc/base/to_string.h"
#include <assert.h>
#include "lfc/base/trace_macro.h"
#define LFC_TRACE_NAME   "[rulp_obj]"
#define LFC_TRACE_NEED   TRACE_GET_TRACE(rulp_obj)()
#include <iostream>
#define LFC_TRACE_STREAM std::cout
#define USE_LFC_NEW_TRACE
TRACE_SUB_MODULE_IMPL(rulp_obj)

using namespace lfc;
using namespace lfc;

namespace lfc {

static std::string NULL_STR = "null";

LFC_TO_STRING_IMPL(lfc::IRObject, OBJ){
  if(!OBJ)
    return NULL_STR;  
  return OBJ->asString();
}

} // namespace lfc