// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "lfc/base/to_string.h"
#include "lfc/base/string/format.h"
#include "lfc/base/container.h"
#include <iostream>

namespace lfc {

XRFACTOR_IMPL_BEGIN(XRFactorDefMacro)

  std::string macroName;
  std::vector<std::string> macroParaList;

  IRObject* nameObj = args->get(1);
  IRObject* paraObj = args->get(2);
  IRObject* bodyObj = null;

  if (args->size() == 4) {
    bodyObj = args->get(3);
  }
  else {
    bodyObj = RulpUtil::toDoExpr(args->listIterator(3));
  }

  /*****************************************************/
  // Macro will always be defined at top frame (root/syste/main)
  /*****************************************************/
  IRFrame* macroFrame = frame->getLevel() <= 2 ? frame : interpreter->getMainFrame();

  /*****************************************************/
  // Check macro name
  /*****************************************************/
  macroName = RulpUtil::asAtom(nameObj)->getName();
  if (macroFrame->getEntry(macroName) != null) {
    throw RException("Duplicated macro name: " + macroName + ", parameters: " + args->asString());
  }

  /*****************************************************/
  // Check macro parameter list
  /*****************************************************/
  if (paraObj != null) {

    if (!RulpUtil::isPureAtomList(paraObj)) {
      throw RException("Invalid para type: " + paraObj->asString());
    } 
    else {
      macroParaList = RulpUtil::toStringList(paraObj);
    }
  }

  IRMacro* macro = RulpFactory::createMacro(macroName, macroParaList, AS_EXPR(bodyObj));
  macroFrame->setEntry(macroName, macro);
  return macro;

XRFACTOR_IMPL_ARG(4, -1)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorDefMacro, F_DEFMACRO);

} // namespace lfc