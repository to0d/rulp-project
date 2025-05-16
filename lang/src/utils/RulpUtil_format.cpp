// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include <sstream>
#include <assert.h>
#include "lfc/base/trace_macro.h"
#define LFC_TRACE_NAME   "[rulp_util]"
#define LFC_TRACE_NEED   TRACE_GET_TRACE(rulp_util)()
#include <iostream>
#define LFC_TRACE_STREAM std::cout
#include "rulp/lang/RConstant.h"
#include "rulp/lang/RGlobal.h"
#include "rulp/lang/RException.h"
#include "rulp/utils/AttrUtil.h"
#include "rulp/utils/RulpUtil.h"
#include "rulp/utils/RulpFactory.h"
#include "rulp/utils/RuntimeUtil.h"

#include "lfc/base/to_string.h"
#include "lfc/base/trace.h"
#include "lfc/base/string/util.h"
#include "lfc/base/encode.h"
using namespace lfc;
using namespace lfc;
namespace lfc {
 

class IRFormater {
public: 
  virtual void format(std::stringstream& ss, const IRObject* obj) = 0;
};

class XRFormater : public IRFormater{
public:
  virtual void format(std::stringstream& ss, const IRObject* obj) override;
};

void XRFormater::format(std::stringstream& ss, const IRObject* obj){
  if (obj == NULL) {
    ss << A_NIL;
    return;
  }

  switch (TYPE_INDEX_OF(obj)) {
  case E_NIL:
    ss << A_NIL;
    break;

  case E_ATOM:
    {
      auto atom = AS_ATOM(obj);      
      RName* rName = atom->getRName();
      if( rName == NULL ){
        ss << atom->getName();
      }
      else {
        ss << rName->getShorName();
      }
    }
    
    break;

  case E_BOOL:
  case E_INT:
  case E_LONG:
  case E_FLOAT:
  case E_DOUBLE:
    ss << obj->asString();
    break;

  case E_FACTOR:
    ss << AS_FACTOR(obj)->getName();
    break;

  case E_TEMPLATE:
    ss << AS_TEMPLATE(obj)->getName();
    break;

  case E_FUNC:
    ss << AS_FUNC(obj)->getName();
    break;

  case E_MACRO:
    ss << AS_MACRO(obj)->getName();
    break;

  case E_STRING:
    ss << "\"";    
    ss << StringUtil::addEscape(AS_STR(obj)->asString());
    ss << "\"";
    break;

  case E_VAR:
    ss << "&";
    ss << AS_VAR(obj)->getName();
    break;

  case E_CONSTANT:
    ss << AS_CONST(obj)->getName();
    break;

  case E_INSTANCE:
    ss << AS_INSTANCE(obj)->asString();
    break;

  case E_CLASS:
    ss << AS_CLASS(obj)->asString();
    break;

  // case NATIVE:
  //   sb.append(((IRNative) obj).asString());
  //   break;

  case E_FRAME:
    ss << AS_FRAME(obj)->getFrameName();
    break;

  default:
    std::cout << TYPE_INDEX_OF(obj) << "\n";
    assert(false && "unsupport type");
  }
}

class XShortFormater : public XRFormater{

public:
  XShortFormater(int maxLength):maxLength(maxLength){}

  virtual void format(std::stringstream& ss, const IRObject* obj) override {
    if (bShort) {
      return;
    }

    if (ss.str().length() >= maxLength) {
      bShort = true;
      return;
    }

    XRFormater::format(ss, obj);
  }

  boolean bShort = false;

  const int maxLength;

};

class XRPrintFormater : public XRFormater{
public:
  virtual void format(std::stringstream& ss, const IRObject* obj) override;
};

void XRPrintFormater::format(std::stringstream& ss, const IRObject* obj) {
  if (obj == null) {
    ss << A_NIL;
    return;
  }

  switch (TYPE_INDEX_OF(obj)) {
  case E_STRING:
    ss << StringUtil::removeEscape(RulpUtil::asString(obj)->asString());
    break;

  default:
    XRFormater::format(ss, obj);
  }
}

static XRFormater objFormater;

static XRPrintFormater printFormater;

static void _toString(std::stringstream& ss, const IRObject* obj, IRFormater* formater, bool attr) ;

static void _toStringIterator(std::stringstream& ss, IRIteratorPtr iterator, IRFormater* formater, bool attr)  {
  int i = 0;
  while (iterator->hasNext()) {

    if (i++ != 0) {
      ss << ' ';
    }

    _toString(ss, iterator->next(), formater, attr);
  }
}

std::string RulpUtil::formatBlob(IRBlob* blob, int maxLen) {

  std::stringstream ss;

  char* bytes = blob->getValue();
  int   len    = blob->length();

  if (bytes == null) {
    ss << "[]";
  } 
  else if (len > maxLen) {
    ss << "[";
    ss << EncodeUtil::convertBytesToHexString(bytes, 0, maxLen);
    ss << "...]";
  }
  else {
    ss << "[";
    ss << EncodeUtil::convertBytesToHexString(bytes, 0, len);
    ss << "]";
  }

  return ss.str();
}

static void _toString(std::stringstream& ss, const IRObject* obj, IRFormater* formater, bool attr) {
  if (obj == NULL) {
    ss << A_NIL;
    return;
  }

  switch (obj->getType()->getIndex()) {
  case E_NIL:
    ss << A_NIL;
    break;

  case E_LIST: {
    auto list = AS_LIST(obj);

    if (!list->getNamedName().empty()) {
      ss << list->getNamedName();
      ss << ':';
    }

    ss << "'(";
    _toStringIterator(ss, list->iterator(), formater, attr);
    ss << ')';
    break;
  }

  case E_ARRAY: {

    auto arr = AS_ARRAY(obj);
    if (arr->getDimension() > 2) {
      throw RException("invalid dimension: " + TO_STR(arr->getDimension()));
    }

    ss << "{";
    int size = arr->size(0);
    for (int i = 0; i < size; ++i) {
      if (i != 0) {
        ss << ',';
      }
      _toString(ss, arr->get(i), formater, attr);
    }

    ss << "}";
    break;
  }

  case E_BLOB: {

    auto blob = AS_BLOB(obj);

    char* bytes = blob->getValue();
    int   len    = blob->length();

    if (bytes == null) {
      ss << "[]";
    } 
    else if (len > MAX_TOSTRING_LEN) {
      ss << "[";
      ss << EncodeUtil::convertBytesToHexString(bytes, 0, MAX_TOSTRING_LEN);
      ss << "...]";
    }
    else {
      ss << "[";
      ss << EncodeUtil::convertBytesToHexString(bytes, 0, len);
      ss << "]";
    }

    break;
  }

  case E_EXPR: {
    auto expr = AS_EXPR(obj);

    if(expr->isEarly()){
      ss << "$";
    }

    ss << "(";
    _toStringIterator(ss, expr->iterator(), formater, attr);
    ss << ')';
    break;
  }

  case E_MEMBER: {

    auto mbr = AS_MEMBER(obj);		
    _toString(ss, mbr->getSubject(), formater, attr);
    ss << "::";
    ss << mbr->getName();
    break;
  
  }

  case E_ITERATOR: {

    auto it = AS_ITERATOR(obj);
    ss << "''(";
    if(it->hasNext()) {
      _toString(ss, it->peek(), formater, attr);
    }

    ss << ")";
    break;
  }


  default:
    formater->format(ss, obj);
    break;
  }

		// if (attr) {
		// 	_formatAttrList(sb, obj);
		// }

}


std::string RulpUtil::toString(const IRObject* obj){
  std::stringstream ss;
  _toString(ss, obj, &objFormater, false);
  return ss.str();
}

std::string RulpUtil::toString(const IRObject* obj, int maxLength){
  std::stringstream ss;
  XShortFormater formater(maxLength);
  _toString(ss, obj, &formater, false);
  if (formater.bShort) {
    ss << "...";
  }

  return ss.str();
}

std::string RulpUtil::toStringPrint(IRObject* obj){
  std::stringstream ss;
  _toString(ss, obj, &printFormater, false);
  return ss.str();
}

std::string RulpUtil::toStringAttr(IRObject* obj, boolean attr) {
  std::stringstream ss;
  _toString(ss, obj, &objFormater, attr);
  return ss.str();
}

std::string RulpUtil::toString(const std::vector<IRObject*> list){
  std::stringstream ss;
  int i = 0;
  for(auto& obj : list){
    if(i++ != 0)
       ss << ' ';
    _toString(ss, obj, &objFormater, false);
  }
  return ss.str();
}

std::string RulpUtil::formatInt(RInt value){
  return TO_STR(value);
}

std::string RulpUtil::formatLong(RLong value){
  return TO_STR(value) + "L";
}

std::string RulpUtil::formatFloat(RFloat value){
  if( value == 0 )
    return "0.0";

  return std::to_string(value);
}

std::string RulpUtil::formatDouble(RDouble value){
  if( value == 0 )
    return "0.0D";

  return std::to_string(value) + "D";
}

static void _formatAttrList(std::stringstream& ss, IRObject* obj) {

  auto attrKeyList = AttrUtil::getAttributeKeyList(obj);
  if (attrKeyList.empty()) {
    return;
  }

  ss << "[";

  int i = 0;
  for(auto key :attrKeyList) {
    if (i++ != 0) {
      ss << ' ';
    }

    auto value = AttrUtil::getAttributeValue(obj, key);
    ss << key;
    if (value != O_Nil) {
      ss << "=";
      ss << value->asString();
    }
  }

  ss << "]";
}

std::string RulpUtil::formatAttribute(IRObject* obj) {
  std::stringstream ss;
  _formatAttrList(ss, obj);
  return ss.str();
}

static std::string _spaceLines[1024];

std::string RulpUtil::getSpaceLine(int len) {
  if (len < 0) {
    len = 0;
  }

  auto line = _spaceLines[len];
  if (line.empty()) {

    std::stringstream ss;
    for (int i = 0; i < len * 4; ++i) {
      ss << ' ';
    }

    line = ss.str();
    _spaceLines[len] = line;
  }

  return line;
}

#define R_ATOM_PRE      "$$a_"
#define R_BOOL_PRE      "$$b_"
#define R_CLASS_PRE     "$$c_"
#define R_DOUBLE_PRE    "$$d_"
#define R_FACTOR_PRE    "$$ff_"
#define R_FLOAT_PRE     "$$f_"
#define R_INT_PRE       "$$i_"
#define R_NAME_NIL      "$$nil"
#define R_NAME_NULL     "$$null"
#define R_TEMPALTE_PRE  "$$tp_"
#define R_VAR_PRE       "$$v_"

static std::string _uniqStringIterator(IRIteratorPtr iterator) {
  std::stringstream ss;
  int i = 0;
  while (iterator->hasNext()) {
    if (i++ != 0) {
      ss << ' ';
    }
    ss << RulpUtil::toUniqString(iterator->next());
  }

  return ss.str();
}

std::string RulpUtil::toUniqString(IRObject* obj) {
  if (obj == null) {
    return R_NAME_NULL;
  }

  switch (TYPE_INDEX_OF(obj)) {
  case E_NIL:
    return R_NAME_NIL;

  case E_ATOM:
    return R_ATOM_PRE + AS_ATOM(obj)->getName();

  case E_INT:
    return R_INT_PRE + formatInt(AS_INT(obj)->asInteger());

  case E_FLOAT:
    return R_FLOAT_PRE + formatFloat(AS_FLOAT(obj)->asFloat());

  case E_DOUBLE:
    return R_DOUBLE_PRE + formatDouble(AS_DOUBLE(obj)->asDouble());

  case E_BOOL:
    return R_BOOL_PRE + (AS_BOOL(obj)->asBoolean() ? std::string(A_TRUE) : std::string(A_FALSE));

  case E_FACTOR:
    return R_FACTOR_PRE + AS_FACTOR(obj)->getName();

  case E_TEMPLATE:
    return R_TEMPALTE_PRE + AS_TEMPLATE(obj)->getName();

  case E_LIST:
    return "'(" + _uniqStringIterator(AS_LIST(obj)->iterator()) + ")";

  case E_EXPR:
    return "(" + _uniqStringIterator(AS_EXPR(obj)->iterator()) + ")";

  case E_STRING:
    return "\"" +  AS_STR(obj)->asString() + "\"";

  case E_VAR:
    return R_VAR_PRE + AS_VAR(obj)->getName();

  case E_INSTANCE: {
    auto ins = AS_INSTANCE(obj);
    return R_CLASS_PRE + ins->getRClass()->getClassName() + "_" + ins->getInstanceName();
  }
  case E_ARRAY:
  case E_BLOB:
  case E_CLASS:
  case E_CONSTANT:
  case E_FRAME:
  case E_FUNC:
  case E_LONG:
  case E_MACRO:
  case E_MEMBER:
  case E_NATIVE:
  default:
    throw RException("unsupport type: " + obj->getType()->getName());
  }
}

} // namespace lfc