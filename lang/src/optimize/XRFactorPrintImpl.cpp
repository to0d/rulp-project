// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "lfc/base/string.h"
#include "lfc/base/function.h"
#include "rulp/utils/FormatUtil.h"
#include "rulp/object/IRRebuild.h"
#include <sstream>

namespace lfc {

typedef lfc::function<void(IRObject*)> visit_F;

static void visit(IRObject* obj, visit_F func) {

  if (obj == null) {
    return;
  }

  func(obj);

  switch (TYPE_INDEX_OF(obj)) {
  case E_EXPR:
  case E_LIST: {
    auto it = AS_LIST(obj)->iterator();
    while (it->hasNext()) {
      visit(it->next(), func);
    }
    break;
  }

  default: 
    break; 
  }
}

static void printFunc(IRInterpreter* interpreter, IRFunction* func) {

  if (func->isList()) {
    throw RException("not support list function: " + func->asString());
  }

  if (func->isLambda()) {
    throw RException("not support lambda function: " + func->asString());
  }

  std::stringstream ss;
  ss << LFC_STR_FORMAT_BGN "(%s %s (", F_DEFUN, func->getName().c_str() LFC_STR_FORMAT_END;

  int index = 0;
  for (auto para : func->getParaAttrs()) {

    if (index++ != 0) {
      ss << " ";
    }

    if (para->getParaType() == O_Nil) {
      ss << para->getParaName();
      ss << RulpUtil::formatAttribute(para);
    
    }
    else {
      ss << "(";
      ss << para->getParaName();
      ss << RulpUtil::formatAttribute(para);
      ss << " ";
      ss << para->getParaType()->asString();
      ss << ")";
    }
  }

  ss << ")";

  std::vector<std::string> lines;
  lines.push_back(ss.str());

  /**************************************************/
  // Output function body
  /**************************************************/
  auto bodyExpr = func->getFunBody();

  // (do ...)
  if (bodyExpr->size() > 1 && RulpUtil::isFactor(bodyExpr->get(0), A_DO)) {

    auto it = bodyExpr->listIterator(1);
    while (it->hasNext()) {
      FormatUtil::format(it->next(), lines, 1);
    }

  } 
  else {
    FormatUtil::format(bodyExpr, lines, 1);
  }

  /**************************************************/
  // print
  /**************************************************/
  lines.push_back(")" + RulpUtil::formatAttribute(func));

  for (auto line : lines) {
    interpreter->write(line);
    interpreter->write("\n");
  }

  std::set<IRObject*> ccObjs;

  visit(func->getFunBody(), [&](auto obj) {

    if (TYPE_INDEX_OF(obj) != E_FACTOR) {
      return;
    }

    if (!AS_FACTOR(obj)->isRebuild()) {
      return;
    }

    if (ccObjs.count(obj) != 0) {
      return;
    }

    ccObjs.insert(obj);

    interpreter->write("rebuild:");
    IRRebuild* rebuild = dynamic_cast<IRRebuild*>(obj);
    interpreter->write(rebuild->getRebuildInformation());
    interpreter->write("\n");
  });
}

XRFACTOR_IMPL_BEGIN(XRFactorPrintImpl)

  auto obj = args->get(1);
  if (TYPE_INDEX_OF(obj) == E_ATOM) {
    auto entry = RuntimeUtil::lookupFrameEntry(frame, AS_ATOM(obj)->getName());
    if (entry != null) {
      obj = entry->getValue();
    }
  }

  switch (TYPE_INDEX_OF(obj)) {
  case E_ATOM:
    throw RException("object not found: " + obj->asString());

  case E_FUNC:
    printFunc(interpreter, AS_FUNC(obj));
    break;

  default:
    throw RException("not support object: " + obj->asString());
  }

  return O_Nil;

XRFACTOR_IMPL_ARG(2, -1)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorPrintImpl, F_PRINT_IMPL);

} // namespace lfc