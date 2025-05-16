// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/lang.h"
#include "rulp/utils/AttrUtil.h"
#include "rulp/utils/StableUtil.h"
#include "rulp/object/AbsObject.h"
#include "lfc/base/string/util.h"

using namespace lfc;
using namespace lfc;
namespace lfc {

void AttrUtil::addAttribute(IRObject* obj, StrConstRef key){
  AbsObject* absObj = dynamic_cast<AbsObject*>(obj);
  absObj->addAttribute(key);
}

std::vector<IRParaAttr*> AttrUtil::buildAttrList(IRObject* paraObj, IRInterpreter* interpreter, IRFrame* frame){
  if (TYPE_INDEX_OF(paraObj) != E_LIST && TYPE_INDEX_OF(paraObj) != E_EXPR) {
    throw RException("Invalid para type: " + paraObj->asString());
  }

  std::vector<IRParaAttr*> paraAttrs;

  try
  {
    auto iter = RulpUtil::asList(paraObj)->iterator();
    while (iter->hasNext()) {

      auto element = iter->next();

      if (TYPE_INDEX_OF(element) == E_ATOM) {
        paraAttrs.push_back(RulpFactory::createParaAttr(RulpUtil::asAtom(element)->getName()));
        continue;
      }

      if (TYPE_INDEX_OF(element) == E_EXPR) {

        auto argExpr = AS_EXPR(element);

        int aszie = argExpr->size();
        if (aszie == 0 || aszie > 3) {
          throw RException("Invalid para expression: " + argExpr->asString());
        }

        auto a0 = argExpr->get(0);
        if (TYPE_INDEX_OF(a0) != E_ATOM) {
          throw RException("Invalid para name: " + a0->asString() + ", expr=" + argExpr->asString());
        }

        // (?a)
        if (aszie == 1) {
          paraAttrs.push_back(RulpFactory::createParaAttr(RulpUtil::asAtom(a0)->getName(), null));
          continue;
        }

        auto a1 = interpreter->compute(frame, argExpr->get(1));

        // (?a int)
        if (aszie == 2 && TYPE_INDEX_OF(a1) == E_ATOM) {

          auto type = RulpUtil::asAtom(a1);
          if (RRType::toType(type->getName()) == null) {
            throw RException("Undefined para type: " + type->asString());
          }

          paraAttrs.push_back(RulpFactory::createParaAttr(RulpUtil::asAtom(a0)->getName(), type));
          continue;
        }

        // (?a class-name)
        if (aszie == 2 && TYPE_INDEX_OF(a1) == E_CLASS) {

          auto type = RulpUtil::asClass(a1)->getClassTypeAtom();
          paraAttrs.push_back(RulpFactory::createParaAttr(RulpUtil::asAtom(a0)->getName(), type));
          continue;
        }

        throw RException("Invalid para expression: " + argExpr->asString());
      }

      throw RException("Invalid para type: " + paraObj->asString());
    }

    return paraAttrs;

  }
  catch(const RException& e)
  {
    RULP_FREE(paraAttrs);
    throw e;
  }
}

boolean AttrUtil::containAttribute(IRObject* obj, StrConstRef attr){
  AbsObject* absObj = dynamic_cast<AbsObject*>(obj);
  return absObj->containAttribute(attr);
}

IRObject* AttrUtil::getAttributeValue(IRObject* obj, StrConstRef key){
  AbsObject* absObj = dynamic_cast<AbsObject*>(obj);
  return absObj->getAttributeValue(key);
}

const std::vector<std::string>& AttrUtil::getAttributeKeyList(IRObject* obj){
  AbsObject* absObj = dynamic_cast<AbsObject*>(obj);
  return absObj->getAttributeKeyList();
}

boolean AttrUtil::hasAttributeList(IRObject* obj){
  AbsObject* absObj = dynamic_cast<AbsObject*>(obj);
  return absObj->getAttributeCount() > 0;
}

boolean AttrUtil::isConst(IRObject* obj, IRFrame* frame){
  switch (TYPE_INDEX_OF(obj)) {
  case E_STRING:
  case E_MACRO:
  case E_INT:
  case E_FLOAT:
  case E_DOUBLE:
  case E_BOOL:
  case E_LONG:
  case E_FACTOR:
  case E_CONSTANT:
  case E_NIL:
    return true;

  case E_CLASS:
    return RulpUtil::asClass(obj)->isConst();

  case E_FUNC:
    return !RulpUtil::asFunction(obj)->isList();

  case E_LIST:
  case E_EXPR:
    return RulpUtil::asList(obj)->isConst();

  case E_ARRAY:
    return RulpUtil::asArray(obj)->isConst();

  case E_ATOM: {

    auto atomName = RulpUtil::asAtom(obj)->getName();

    auto entry = RuntimeUtil::lookupFrameEntry(frame, atomName);
    // is pure atom
    if (entry == null) {
      return true;
    }

    auto entryValue = entry->getObject();
    if (entryValue == null || TYPE_INDEX_OF(entryValue) == E_ATOM) {
      return true;
    }

    return isConst(entryValue, frame);
  }

  default:
    return false;
  }
}

static boolean _isRecursiveFunc(IRFunction* func) {

  if (func->isList()) {

    auto funcList = RulpUtil::asFunctionList(func);
    for (auto childFunc : funcList->getAllFuncList()) {
      if (AttrUtil::isRecursive(childFunc)) {
        return true;
      }
    }

    return false;
  }

  return RulpUtil::containFunc(func->getFunBody(), func->getName());
}

boolean AttrUtil::isRecursive(IRFunction* func){
  auto value = AttrUtil::getAttributeValue(func, A_RECURSIVE);
  if (value != null) {
    return RulpUtil::asBoolean(value)->asBoolean();
  }

  boolean rc = _isRecursiveFunc(func);
  AttrUtil::setAttribute(func, A_RECURSIVE, RulpFactory::createBoolean(rc));
  return rc;
}

boolean AttrUtil::isStable(IRObject* obj, IRFrame* frame){
  return StableUtil::isStable(obj, frame);
}

std::string AttrUtil::toValidAttribute(StrConstRef attr){
  if (attr.empty()) {
    return attr;
  }

  auto str = STR_TRIM(attr);
  if (str.empty()) {
    return str;
  }

  return attr;
}

void AttrUtil::removeAllAttributes(IRObject* obj){
  AbsObject* absObj = dynamic_cast<AbsObject*>(obj);
  absObj->removeAllAttributes();
}

IRObject* AttrUtil::removeAttribute(IRObject* obj, StrConstRef attr){
  AbsObject* absObj = dynamic_cast<AbsObject*>(obj);
  return absObj->removeAttribute(attr);
}

void AttrUtil::setAttribute(IRObject* obj, StrConstRef key, IRObject* value){
  AbsObject* absObj = dynamic_cast<AbsObject*>(obj);
  absObj->setAttribute(key, value);
}

} // namespace lfc