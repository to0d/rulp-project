// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include <assert.h>
#include "lfc/base/trace_macro.h"
#define LFC_TRACE_NAME   "[rulp_util]"
#define LFC_TRACE_NEED   TRACE_GET_TRACE(rulp_util)()
#include <iostream>
#define LFC_TRACE_STREAM std::cout
#include "rulp/lang/RConstant.h"
#include "rulp/lang/RGlobal.h"
#include "rulp/lang/RException.h"
#include "rulp/utils/RulpUtil.h"
#include "rulp/utils/RulpFactory.h"
#include "rulp/utils/RuntimeUtil.h"

#include "lfc/base/to_string.h"
#include "lfc/base/trace.h"
using namespace lfc;
using namespace lfc;
namespace lfc {

IRAtom* RulpUtil::asAtom(IRObject* obj) {
  if (obj == null) {
    throw RException("Can't cast null to atom");
  }

  if (TYPE_INDEX_OF(obj) != E_ATOM) {
    throw RException("Can't convert to atom: " + obj->asString());
  }

  return dynamic_cast<IRAtom*>(obj);
}

const IRAtom* RulpUtil::asAtom(const IRObject* obj) {

  if (obj == null) {
    throw RException("Can't cast null to atom");
  }

  if (TYPE_INDEX_OF(obj) != E_ATOM) {
    throw RException("Can't convert to atom: " + obj->asString());
  }

  return dynamic_cast<const IRAtom*>(obj);
}

IRArray* RulpUtil::asArray(IRObject* obj){
  if (obj == null) {
    throw RException("Can't cast null to array");
  }

  if (TYPE_INDEX_OF(obj) != E_ARRAY) {
    throw RException("Can't convert to array: " + obj->asString());
  }

  return dynamic_cast<IRArray*>(obj);
}

const IRArray* RulpUtil::asArray(const IRObject* obj){
  if (obj == null) {
    throw RException("Can't cast null to array");
  }

  if (TYPE_INDEX_OF(obj) != E_ARRAY) {
    throw RException("Can't convert to array: " + obj->asString());
  }

  return dynamic_cast<const IRArray*>(obj);
}

IRBoolean* RulpUtil::asBoolean(IRObject* obj) {

  if (obj == null) {
    throw RException("Can't cast null to bool");
  }

  if (TYPE_INDEX_OF(obj) != E_BOOL) {
    throw RException("Can't convert to bool: " + obj->asString());
  }

  return dynamic_cast<IRBoolean*>(obj);
}

const IRBoolean* RulpUtil::asBoolean(const IRObject* obj) {

  if (obj == null) {
    throw RException("Can't cast null to bool");
  }

  if (TYPE_INDEX_OF(obj) != E_BOOL) {
    throw RException("Can't convert to bool: " + obj->asString());
  }

  return dynamic_cast<const IRBoolean*>(obj);
}

IRBlob* RulpUtil::asBlob(IRObject* obj) {

  if (obj == null) {
    throw RException("Can't cast null to blob");
  }

  if (TYPE_INDEX_OF(obj) != E_BLOB) {
    throw RException("Can't convert to blob: " + obj->asString());
  }

  return dynamic_cast<IRBlob*>(obj);

}

const IRBlob* RulpUtil::asBlob(const IRObject* obj) {

  if (obj == null) {
    throw RException("Can't cast null to blob");
  }

  if (TYPE_INDEX_OF(obj) != E_BLOB) {
    throw RException("Can't convert to blob: " + obj->asString());
  }

  return dynamic_cast<const IRBlob*>(obj);

}

IRCallable* RulpUtil::asCallable(IRObject* obj){

  if (obj == null) {
    throw RException("Can't cast null to callable");
  }

  if(!obj->isCallable()){
    throw RException("Can't convert to callable: " + obj->asString());
  }

  return dynamic_cast<IRCallable*>(obj);
}

IRClass* RulpUtil::asClass(IRObject* obj){
  if (obj == null) {
    throw RException("Can't cast null to class");
  }

  if (TYPE_INDEX_OF(obj) != E_CLASS) {
    throw RException("Can't convert to class: " + obj->asString());
  }

  return dynamic_cast<IRClass*>(obj);
}

const IRClass* RulpUtil::asClass(const IRObject* obj){
  if (obj == null) {
    throw RException("Can't cast null to class");
  }

  if (TYPE_INDEX_OF(obj) != E_CLASS) {
    throw RException("Can't convert to class: " + obj->asString());
  }

  return dynamic_cast<const IRClass*>(obj);
}

IRExpr* RulpUtil::asExpr(IRObject* obj){
  if (obj == null) {
    throw RException("Can't cast null to expr");
  }

  if (TYPE_INDEX_OF(obj) != E_EXPR) {
    throw RException("Can't convert to expr: " + obj->asString());
  }

  return dynamic_cast<IRExpr*>(obj);
}

IRError* RulpUtil::asError(IRObject* obj){
  if (obj == null) {
    throw RException("Can't cast null to error");
  }

  if (TYPE_INDEX_OF(obj) != E_INSTANCE || !AS_INSTANCE(obj)->isError()) {
    throw RException("Can't convert to error: " + obj->asString());
  }

  return dynamic_cast<IRError*>(obj);
}

const IRError* RulpUtil::asError(const IRObject* obj){
  if (obj == null) {
    throw RException("Can't cast null to error");
  }

  if (TYPE_INDEX_OF(obj) != E_INSTANCE || !AS_INSTANCE(obj)->isError()) {
    throw RException("Can't convert to error: " + obj->asString());
  }

  return dynamic_cast<const IRError*>(obj);
}

const IRExpr* RulpUtil::asExpr(const IRObject* obj){
  if (obj == null) {
    throw RException("Can't cast null to expr");
  }

  if (TYPE_INDEX_OF(obj) != E_EXPR) {
    throw RException("Can't convert to expr: " + obj->asString());
  }

  return dynamic_cast<const IRExpr*>(obj);
}

IRInstance* RulpUtil::asInstance(IRObject* obj){
  if (obj == null) {
    throw RException("Can't cast null to instance");
  }

  if (TYPE_INDEX_OF(obj) != E_INSTANCE) {
    throw RException("Can't convert to instance: " + obj->asString());
  }

  return dynamic_cast<IRInstance*>(obj);
}

const IRInstance* RulpUtil::asInstance(const IRObject* obj){
  if (obj == null) {
    throw RException("Can't cast null to instance");
  }

  if (TYPE_INDEX_OF(obj) != E_INSTANCE) {
    throw RException("Can't convert to instance: " + obj->asString());
  }

  return dynamic_cast<const IRInstance*>(obj);
}

const IRObjectIterator* RulpUtil::asObjectIterator(const IRObject* obj){
  if (obj == null) {
    throw RException("Can't cast null to iterator");
  }

  if (TYPE_INDEX_OF(obj) != E_ITERATOR) {
    throw RException("Can't convert to iterator: " + obj->asString());
  }

  return dynamic_cast<const IRObjectIterator*>(obj);
}

IRObjectIterator* RulpUtil::asObjectIterator(IRObject* obj){
  if (obj == null) {
    throw RException("Can't cast null to iterator");
  }

  if (TYPE_INDEX_OF(obj) != E_ITERATOR) {
    throw RException("Can't convert to iterator: " + obj->asString());
  }

  return dynamic_cast<IRObjectIterator*>(obj);
}

IRList* RulpUtil::asList(IRObject* obj){
  if (obj == null) {
    throw RException("Can't cast null to list");
  }

  if (TYPE_INDEX_OF(obj) != E_LIST && TYPE_INDEX_OF(obj) != E_EXPR) {
    throw RException("Can't convert to list: " + obj->asString());
  }

  return dynamic_cast<IRList*>(obj);
}

const IRList* RulpUtil::asList(const IRObject* obj){
  if (obj == null) {
    throw RException("Can't cast null to list");
  }

  if (TYPE_INDEX_OF(obj) != E_LIST && TYPE_INDEX_OF(obj) != E_EXPR) {
    throw RException("Can't convert to list: " + obj->asString());
  }

  return dynamic_cast<const IRList*>(obj);
}

IRFactor* RulpUtil::asFactor(IRObject* obj) {

  if (obj == null) {
    throw RException("Can't cast null to factor");
  }

  if (TYPE_INDEX_OF(obj) != E_FACTOR) {
    throw RException("Can't convert to factor: " + obj->asString());
  }

  return dynamic_cast<IRFactor*>(obj);
}

const IRFactor* RulpUtil::asFactor(const IRObject* obj) {

  if (obj == null) {
    throw RException("Can't cast null to factor");
  }

  if (TYPE_INDEX_OF(obj) != E_FACTOR) {
    throw RException("Can't convert to factor: " + obj->asString());
  }

  return dynamic_cast<const IRFactor*>(obj);
}

IRFunction* RulpUtil::asFunction(IRObject* obj){

  if (obj == null) {
    throw RException("Can't cast null to func");
  }

  if (TYPE_INDEX_OF(obj) != E_FUNC) {
    throw RException("Can't convert to func: " + obj->asString());
  } 

  return dynamic_cast<IRFunction*>(obj);
}

const IRFunction* RulpUtil::asFunction(const IRObject* obj){

  if (obj == null) {
    throw RException("Can't cast null to func");
  }

  if (TYPE_INDEX_OF(obj) != E_FUNC) {
    throw RException("Can't convert to func: " + obj->asString());
  } 

  return dynamic_cast<const IRFunction*>(obj);
}

IRFunctionList* RulpUtil::asFunctionList(IRObject* obj){

  IRFunction* func = asFunction(obj);
  if (!func->isList()) {
    throw RException("Can't convert to funclist: " + obj->asString());
  } 

  return dynamic_cast<IRFunctionList*>(obj);
}

const IRFunctionList* RulpUtil::asFunctionList(const IRObject* obj){

  const IRFunction* func = asFunction(obj);
  if (!func->isList()) {
    throw RException("Can't convert to funclist: " + obj->asString());
  } 

  return dynamic_cast<const IRFunctionList*>(obj);
}

IRFrame* RulpUtil::asFrame(IRObject* obj){
  if (obj == null) {
    throw RException("Can't cast null to frame");
  }

  if (TYPE_INDEX_OF(obj) != E_FRAME) {
    throw RException("Can't convert to frame: " + obj->asString());
  } 

  return dynamic_cast<IRFrame*>(obj);
}

const IRFrame* RulpUtil::asFrame(const IRObject* obj){
  if (obj == null) {
    throw RException("Can't cast null to frame");
  }

  if (TYPE_INDEX_OF(obj) != E_FRAME) {
    throw RException("Can't convert to frame: " + obj->asString());
  } 

  return dynamic_cast<const IRFrame*>(obj);
}


IRString* RulpUtil::asString(IRObject* obj){
  if (obj == null) {
    throw RException("Can't cast null to string");
  }

  if (TYPE_INDEX_OF(obj) != E_STRING) {
    throw RException("Can't convert to string: " + obj->asString());
  } 

  return dynamic_cast<IRString*>(obj);
}

IRMacro* RulpUtil::asMacro(IRObject* obj){
  if (obj == null) {
    throw RException("Can't cast null to macro");
  }

  if (TYPE_INDEX_OF(obj) != E_MACRO) {
    throw RException("Can't convert to macro: " + obj->asString());
  } 

  return dynamic_cast<IRMacro*>(obj);
}


const IRMacro* RulpUtil::asMacro(const IRObject* obj){
  if (obj == null) {
    throw RException("Can't cast null to macro");
  }

  if (TYPE_INDEX_OF(obj) != E_MACRO) {
    throw RException("Can't convert to macro: " + obj->asString());
  } 

  return dynamic_cast<const IRMacro*>(obj);
}


IRTemplate* RulpUtil::asTemplate(IRObject* obj){
  if (obj == null) {
    throw RException("Can't cast null to template");
  }

  if (TYPE_INDEX_OF(obj) != E_TEMPLATE) {
    throw RException("Can't convert to template: " + obj->asString());
  } 

  return dynamic_cast<IRTemplate*>(obj);
}

const IRTemplate* RulpUtil::asTemplate(const IRObject* obj){
  if (obj == null) {
    throw RException("Can't cast null to template");
  }

  if (TYPE_INDEX_OF(obj) != E_TEMPLATE) {
    throw RException("Can't convert to template: " + obj->asString());
  } 

  return dynamic_cast<const IRTemplate*>(obj);
}

const IRString* RulpUtil::asString(const IRObject* obj){
  if (obj == null) {
    throw RException("Can't cast null to string");
  }

  if (TYPE_INDEX_OF(obj) != E_STRING) {
    throw RException("Can't convert to string: " + obj->asString());
  } 

  return dynamic_cast<const IRString*>(obj);
}

IRSubject* RulpUtil::asSubject(IRObject* obj){

  if (obj == null) {
    throw RException("Can't cast null to subject");
  }

  if(!IS_SUBJECT(obj)){
    throw RException("Can't convert to subject: " + obj->asString());
  }

  return dynamic_cast<IRSubject*>(obj);
}

const IRSubject* RulpUtil::asSubject(const IRObject* obj){

  if (obj == null) {
    throw RException("Can't cast null to subject");
  }

  if(!obj->isSubject()){
    throw RException("Can't convert to subject: " + obj->asString());
  }

  return dynamic_cast<const IRSubject*>(obj);
}

IRConst* RulpUtil::asConst(IRObject* obj){
  if (obj == null) {
    throw RException("Can't cast null to constant");
  }

  if (TYPE_INDEX_OF(obj) != E_CONSTANT) {
    throw RException("Can't convert to constant: " + obj->asString());
  } 

  return dynamic_cast<IRConst*>(obj);
}

const IRConst* RulpUtil::asConst(const IRObject* obj){
  if (obj == null) {
    throw RException("Can't cast null to constant");
  }

  if (TYPE_INDEX_OF(obj) != E_CONSTANT) {
    throw RException("Can't convert to constant: " + obj->asString());
  } 

  return dynamic_cast<const IRConst*>(obj);
}

IRInteger* RulpUtil::asInteger(IRObject* obj){
  if (obj == null) {
    throw RException("Can't cast null to integer");
  }

  if (TYPE_INDEX_OF(obj) != E_INT) {
    throw RException("Can't convert to integer: " + obj->asString());
  } 

  return dynamic_cast<IRInteger*>(obj);
}

const IRInteger* RulpUtil::asInteger(const IRObject* obj){
  if (obj == null) {
    throw RException("Can't cast null to integer");
  }

  if (TYPE_INDEX_OF(obj) != E_INT) {
    throw RException("Can't convert to integer: " + obj->asString());
  } 

  return dynamic_cast<const IRInteger*>(obj);
}

IRFloat* RulpUtil::asFloat(IRObject* obj){
  if (obj == null) {
    throw RException("Can't cast null to float");
  }

  if (TYPE_INDEX_OF(obj) != E_FLOAT) {
    throw RException("Can't convert to float: " + obj->asString());
  } 

  return dynamic_cast<IRFloat*>(obj);
}

const IRFloat* RulpUtil::asFloat(const IRObject* obj){
  if (obj == null) {
    throw RException("Can't cast null to float");
  }

  if (TYPE_INDEX_OF(obj) != E_FLOAT) {
    throw RException("Can't convert to float: " + obj->asString());
  } 

  return dynamic_cast<const IRFloat*>(obj);
}

IRDouble* RulpUtil::asDouble(IRObject* obj){
  if (obj == null) {
    throw RException("Can't cast null to double");
  }

  if (TYPE_INDEX_OF(obj) != E_DOUBLE) {
    throw RException("Can't convert to double: " + obj->asString());
  } 

  return dynamic_cast<IRDouble*>(obj);
}

const IRDouble* RulpUtil::asDouble(const IRObject* obj){
  if (obj == null) {
    throw RException("Can't cast null to double");
  }

  if (TYPE_INDEX_OF(obj) != E_DOUBLE) {
    throw RException("Can't convert to double: " + obj->asString());
  } 

  return dynamic_cast<const IRDouble*>(obj);
}


IRLong* RulpUtil::asLong(IRObject* obj){
  if (obj == null) {
    throw RException("Can't cast null to long");
  }

  if (TYPE_INDEX_OF(obj) != E_LONG) {
    throw RException("Can't convert to long: " + obj->asString());
  } 

  return dynamic_cast<IRLong*>(obj);
}

IRMember* RulpUtil::asMember(IRObject* obj){
  if (obj == null) {
    throw RException("Can't cast null to member");
  }

  if (TYPE_INDEX_OF(obj) != E_MEMBER) {
    throw RException("Can't convert to member: " + obj->asString());
  } 

  return dynamic_cast<IRMember*>(obj);
}

const IRMember* RulpUtil::asMember(const IRObject* obj){
  if (obj == null) {
    throw RException("Can't cast null to member");
  }

  if (TYPE_INDEX_OF(obj) != E_MEMBER) {
    throw RException("Can't convert to member: " + obj->asString());
  } 

  return dynamic_cast<const IRMember*>(obj);
}

const IRLong* RulpUtil::asLong(const IRObject* obj){
  if (obj == null) {
    throw RException("Can't cast null to long");
  }

  if (TYPE_INDEX_OF(obj) != E_LONG) {
    throw RException("Can't convert to long: " + obj->asString());
  } 

  return dynamic_cast<const IRLong*>(obj);
}

IRVar* RulpUtil::asVar(IRObject* obj){
  if (obj == null) {
    throw RException("Can't cast null to var");
  }

  if (TYPE_INDEX_OF(obj) != E_VAR) {
    throw RException("Can't convert to var: " + obj->asString());
  } 

  return dynamic_cast<IRVar*>(obj);
}

const IRVar* RulpUtil::asVar(const IRObject* obj){
  if (obj == null) {
    throw RException("Can't cast null to var");
  }

  if (TYPE_INDEX_OF(obj) != E_VAR) {
    throw RException("Can't convert to var: " + obj->asString());
  } 

  return dynamic_cast<const IRVar*>(obj);
}

} // namespace lfc