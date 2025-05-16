// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_RULPUTIL_H__
#define __RULP_LANG_RULPUTIL_H__
#include "lfc/base/trace_macro.h"
#include "rulp/lang/RGlobal.h"
#include "rulp/object/IRArray.h"
#include "rulp/object/IRBlob.h"
#include "rulp/object/IRClass.h"
#include "rulp/object/IRConst.h"
#include "rulp/object/IRError.h"
#include "rulp/object/IRInstance.h"
#include "rulp/object/IRVar.h"
#include "rulp/object/IRObjectIterator.h"
#include "rulp/runtime/IRFactor.h"
#include "rulp/runtime/IRMacro.h"
#include "rulp/runtime/IRFrame.h"
#include "rulp/runtime/IRFunction.h"
#include "rulp/runtime/IRFunctionList.h"
#include "rulp/runtime/IRIterator.h"
#include "rulp/runtime/IRTemplate.h"

namespace lfc {

#define _R_AS_FUNC_NAME(_type) as##_type

#define _R_AS_TYPE_NAME(_type) IR##_type

#define _R_DEF_AS(_type) \
  static _R_AS_TYPE_NAME(_type) * _R_AS_FUNC_NAME(_type)(IRObject*); \
  static const _R_AS_TYPE_NAME(_type) * _R_AS_FUNC_NAME(_type)(const IRObject*);

#define _R_IS_FUNC_NAME(_type) is##_type
#define _R_DEF_IS(_type) \
  static boolean _R_IS_FUNC_NAME(_type)(const IRObject*);

#define AS_ATOM(obj)      RulpUtil::_R_AS_FUNC_NAME(Atom)(obj)
#define AS_ARRAY(obj)     RulpUtil::_R_AS_FUNC_NAME(Array)(obj)
#define AS_BOOL(obj)      RulpUtil::_R_AS_FUNC_NAME(Boolean)(obj)
#define AS_BLOB(obj)      RulpUtil::_R_AS_FUNC_NAME(Blob)(obj)
#define AS_CALL(obj)      RulpUtil::_R_AS_FUNC_NAME(Callable)(obj)
#define AS_CLASS(obj)     RulpUtil::_R_AS_FUNC_NAME(Class)(obj)
#define AS_CONST(obj)     RulpUtil::_R_AS_FUNC_NAME(Const)(obj)
#define AS_DOUBLE(obj)    RulpUtil::_R_AS_FUNC_NAME(Double)(obj)
#define AS_EXPR(obj)      RulpUtil::_R_AS_FUNC_NAME(Expr)(obj)
#define AS_ERROR(obj)     RulpUtil::_R_AS_FUNC_NAME(Error)(obj)
#define AS_FACTOR(obj)    RulpUtil::_R_AS_FUNC_NAME(Factor)(obj)
#define AS_FLOAT(obj)     RulpUtil::_R_AS_FUNC_NAME(Float)(obj)
#define AS_FRAME(obj)     RulpUtil::_R_AS_FUNC_NAME(Frame)(obj)
#define AS_FUNC(obj)      RulpUtil::_R_AS_FUNC_NAME(Function)(obj)
#define AS_FUNC_LIST(obj) RulpUtil::_R_AS_FUNC_NAME(FunctionList)(obj)
#define AS_INT(obj)       RulpUtil::_R_AS_FUNC_NAME(Integer)(obj)
#define AS_INSTANCE(obj)  RulpUtil::_R_AS_FUNC_NAME(Instance)(obj)
#define AS_LONG(obj)      RulpUtil::_R_AS_FUNC_NAME(Long)(obj)
#define AS_LIST(obj)      RulpUtil::_R_AS_FUNC_NAME(List)(obj)
#define AS_MACRO(obj)     RulpUtil::_R_AS_FUNC_NAME(Macro)(obj)
#define AS_MEMBER(obj)    RulpUtil::_R_AS_FUNC_NAME(Member)(obj)
#define AS_ITERATOR(obj)  RulpUtil::_R_AS_FUNC_NAME(ObjectIterator)(obj)
#define AS_STR(obj)       RulpUtil::_R_AS_FUNC_NAME(String)(obj)
#define AS_SUBJECT(obj)   RulpUtil::_R_AS_FUNC_NAME(Subject)(obj)
#define AS_TEMPLATE(obj)  RulpUtil::_R_AS_FUNC_NAME(Template)(obj)
#define AS_VAR(obj)       RulpUtil::_R_AS_FUNC_NAME(Var)(obj)

#define IS_CALLABLE(obj)  RulpUtil::_R_IS_FUNC_NAME(Callable)(obj)
#define IS_FUNC_LIST(obj) RulpUtil::_R_IS_FUNC_NAME(FunctionList)(obj)
#define IS_NIL(obj)       RulpUtil::_R_IS_FUNC_NAME(Nil)(obj)
#define IS_SUBJECT(obj)   RulpUtil::_R_IS_FUNC_NAME(Subject)(obj)

class RulpUtil {

public:

  _R_DEF_AS(Atom);
  _R_DEF_AS(Array);
  _R_DEF_AS(Boolean);
  _R_DEF_AS(Blob);
  _R_DEF_AS(Callable);
  _R_DEF_AS(Class);
  _R_DEF_AS(Const);
  _R_DEF_AS(Double);
  _R_DEF_AS(Expr);
  _R_DEF_AS(Error);
  _R_DEF_AS(Factor);
  _R_DEF_AS(Float);
  _R_DEF_AS(Frame);
  _R_DEF_AS(Function);
  _R_DEF_AS(FunctionList);
  _R_DEF_AS(Integer);
  _R_DEF_AS(Instance); 
  _R_DEF_AS(Long);
  _R_DEF_AS(List);
  _R_DEF_AS(Macro);
  _R_DEF_AS(Member);
  _R_DEF_AS(ObjectIterator);
  _R_DEF_AS(String);
  _R_DEF_AS(Subject);
  _R_DEF_AS(Template);
  _R_DEF_AS(Var);



public:

  static std::vector<IRObject*> toArray(IRList* list);
  static IRAtom*      toAtom(StrConstRef name);
  static boolean      toBoolean(const IRObject* a);
  static IRBlob*      toBlob(IRObject* a);
  static IRObject*    toConst(IRObject* obj, IRFrame* frame);
  static double       toDouble(const IRObject* obj);
  static IRExpr*      toDoExpr(IRIteratorPtr it);
  static float        toFloat(const IRObject* obj);
  static int          toInt(const IRObject* obj);
  static long         toLong(const IRObject* obj);
  static IRList*      toList(StrConstRef name, IRArray* array);
  static IRList*      toList(StrConstRef name, std::vector<IRObject*>&& elements);
  static IRList*      toList(StrConstRef name, IRObject* listObj, IRFrame* frame);
  static IRList*      toNamedList(IRObject* nameObj, IRObject* listObj, IRFrame* frame);
  static std::string  toString(const IRObject* obj);
  static std::string  toString(const IRObject* obj, int maxLength);
  static std::string  toString(const std::vector<IRObject*> list);
  static IRObject*    toString(IRObject* obj, IRInterpreter* interpreter);
  static std::string  toStringAttr(IRObject* obj, boolean attr);
  static StrList      toStringList(IRObject* obj);
  static std::string  toStringPrint(IRObject* obj);
  static IRObject*    toVary(IRObject* obj, IRFrame* frame);

public:

  static void         addAll(IRList* list, IRIteratorPtr it);
  static void         addAll(std::vector<IRObject*>& l1, IRIteratorPtr it);
  static void         addAll(std::vector<IRObject*>& l1, IRList* l2);
  static IRList*      addAll(IRList* list, IRArray* array);
  static IRList*      addAll(IRList* l1, IRList* l2);
  static IRArray*     addAll(IRArray* array, IRList* list);

  static IRList*      buildListOfString(const std::vector<std::string>& strlist);

  static boolean      containFunc(IRObject* obj, StrConstRef name);
  static int          compare(IRObject* a, IRObject* b);
  static IRObject*    clone(IRObject* obj);
  static boolean      equal(IRObject* a, IRObject* b);
  static IRAtom*      getObjectType(IRObject* obj);
  static std::string  getNextUnusedName();

  static boolean      isAtom(const IRObject* obj);
  static boolean      isAtom(const IRObject* obj, StrConstRef name);
  static boolean      isFactor(const IRObject* obj, StrConstRef name);

  _R_DEF_IS(Callable);
  _R_DEF_IS(FunctionList);
  _R_DEF_IS(Nil);
  _R_DEF_IS(Subject);

  static boolean      isObject(const IRObject* obj, StrConstRef name, std::initializer_list<RTypeIndex> types);
  static boolean      isPropertyFinal(IRMember* mbr);
  static boolean      isPropertyInherit(IRMember* mbr);
  static boolean      isPropertyStatic(IRMember* mbr);
  static boolean      isPureAtomList(IRObject* obj);
  static boolean      isTrace(IRFrame* frame);
  static boolean      isValidAtomName(const std::string& name);
  static boolean      isVarAtom(const IRObject* obj);
  static boolean      isVarName(StrConstRef var);
  static IRObject*    lookup(IRObject* obj, IRInterpreter* interpreter, IRFrame* frame);
  static boolean      matchType(IRAtom* typeAtom, IRObject* obj);
  static std::string  nameOf(IRObject* obj, IRFrame* frame);

  static void         setMember(IRSubject* subject, StrConstRef name, factor_func factor, RAccessType accessType, int property = 0);
  static void         setMember(IRSubject* subject, StrConstRef name, IRObject* obj, RAccessType accessType = RAccessType::NIL, int property = 0);

  static void         setPropertyFinal(IRMember* mbr, boolean bValue);
  static void         setPropertyInherit(IRMember* mbr, boolean bValue);
  static void         setPropertyStatic(IRMember* mbr, boolean bValue);

  static void         sortByStr(std::vector<IRObject*> list);
  static void         sortByUniqString(std::vector<IRObject*> list);

  static std::string  toOneLine(const std::vector<std::string>& lines);

  static void         tryOverride(IRFunction* oldFun, IRFunction* newFun);

public:

  static void         addPathVar(IRFrame* frame, StrConstRef path);
  static IRObject*    getVarValue(IRFrame* frame, StrConstRef varName);
  static void         setLocalVar(IRFrame* frame, StrConstRef varName, IRObject* value);


public:

  static boolean isIf1(IRList* args);
  static boolean isIf2(IRList* args);
  static boolean isIf3(IRList* args);

  static boolean isLoop1(IRList* args);
  static boolean isLoop2(IRList* args);
  static boolean isLoop3(IRList* args);
  static boolean isLoop4(IRList* args);

public:

  static IRObject* handle_error(IRError* err, IRInterpreter* interpreter, IRFrame* frame);
  static IRObject* throw_error(IRInterpreter* interpreter, IRFrame* frame, IRAtom* errId, IRObject* errValue, IRObject* fromObject);

public:

  static std::string formatInt(RInt value);
  static std::string formatLong(RLong value);
  static std::string formatFloat(RFloat value);
  static std::string formatDouble(RDouble value);
  static std::string formatBlob(IRBlob* blob, int maxLen);
  static std::string formatAttribute(IRObject* obj) ;

  static std::string toUniqString(IRObject* obj);
  
  static std::string getSpaceLine(int len);

public:

  static void incRef(IRObject* obj);
  static void decRef(IRObject* obj);

public:


  static void reset();
};

#define RULP_INC_REF(obj)           lfc::rulp_auto_inc_ref(obj)
#define RULP_DEC_REF(obj)           lfc::rulp_auto_dec_ref(obj)
#define RULP_AUTO_DEC_REF(obj)      LFC_AUTO_DO([&](){ RULP_DEC_REF(obj);})

template<typename _T, typename Enable = void>
struct _rulp_auto_inc_ref{
  inline static void incRef(_T ptr){
    if (ptr != 0){
      lfc::RulpUtil::incRef(ptr);
    }
  }
};

template<typename _T>
struct _rulp_auto_inc_ref<std::vector<_T*>>{
  inline static void incRef(std::vector<_T*>& vec){
    for(auto& ptr : vec){
      if (ptr != 0){
        lfc::RulpUtil::incRef(ptr);
      }
    }
  }
};

template<typename _T>
void rulp_auto_inc_ref(_T ptr){
  typedef _rulp_auto_inc_ref<_T> auto_inc_type;
  auto_inc_type::incRef(ptr);
}

template<typename _T, typename Enable = void>
struct _rulp_auto_dec_ref{
  inline static void decRef(_T& ptr){
    if (ptr != 0){
      lfc::RulpUtil::decRef(ptr);
      ptr = null;
    }
  }
};

template<typename _T>
struct _rulp_auto_dec_ref<std::vector<_T*>>{
  inline static void decRef(std::vector<_T*>& vec){
    for(_T* ptr : vec){
      if (ptr != 0){
        lfc::RulpUtil::decRef(ptr);
        ptr = null;
      }
    }
    vec.clear();
  }
};

template<typename _T>
void rulp_auto_dec_ref(_T ptr){
  typedef _rulp_auto_dec_ref<_T> auto_dec_type;
  auto_dec_type::decRef(ptr);
}


class RObjecAutoHandler {

public:

  RObjecAutoHandler() {};

  RObjecAutoHandler(RObjecAutoHandler&& RH)
    : obj(RH.obj)
    , more(RH.more)
  {
    RH.obj = null;
    RH.more = null;
  }

  ~RObjecAutoHandler() {
    RULP_DEC_REF(obj);

    if(more != null){
      RULP_DEC_REF(*more);
      delete more;
      more = null;
    }    
  }

private:

  // disable copy constructor
  RObjecAutoHandler(const RObjecAutoHandler& RH) {}

public:

  void addObject(IRObject* ptr) {
    if(ptr == null)
      return;

    RULP_INC_REF(ptr);

    if(obj == null){
      obj = ptr;
    }
    else {
      if(more == null){
        more = new std::vector<IRObject*>();
      }
      more->push_back(ptr);
    }
  }
 
private:

  IRObject* obj = NULL;
  std::vector<IRObject*>* more = null;
};

template<typename _T, typename Enable = void>
struct _rulp_auto_inc_dec{
  inline static RObjecAutoHandler inc_dec(_T obj){
    RObjecAutoHandler handler;
    handler.addObject(obj);
    return std::move(handler);
  }
};

template<typename _T>
struct _rulp_auto_inc_dec<std::vector<_T*>>{
  inline static RObjecAutoHandler inc_dec(std::vector<_T*>& vec){
    RObjecAutoHandler handler;
    for(auto& ptr : vec){
      handler.addObject(ptr);
    }
    return std::move(handler);
  }
};

template<typename _T>
RObjecAutoHandler rulp_auto_inc_dec(_T ptr){
  typedef _rulp_auto_inc_dec<_T> auto_type;
  return auto_type::inc_dec(ptr);
}

#define AUTO_INC_DEC(x) auto AUTO_NAME(AUTO_INC_DEC) = rulp_auto_inc_dec(x)

} // namespace lfc
TRACE_SUB_MODULE_DEF(rulp_util)
#endif //__RULP_LANG_RULPUTIL_H__