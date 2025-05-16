// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_UTILS_RUNTIME_UTIL_H__
#define __RULP_UTILS_RUNTIME_UTIL_H__
#include "lfc/base/trace_macro.h"
#include "lfc/base/macro.h"
#include "rulp/object/IRClass.h"
#include "rulp/runtime/IRFactor.h"
#include "rulp/object/IRObject.h"
#include "rulp/object/IRVar.h"
#include "rulp/runtime/IRInterpreter.h"
#include "rulp/runtime/IRFrameEntry.h"
#include "rulp/runtime/IRCallable.h"
#include "rulp/runtime/IRFunction.h"
#include "rulp/runtime/IRLoader.h"
#include "rulp/runtime/IRTemplate.h"
#include "rulp/utils/RListHandler.h"
#include <map>
#include <iostream>
namespace lfc {

class RuntimeUtil {

public:

  static void addFrameObject(IRFrame* frame, IRObject* obj);
  
  static void addFactor(IRFrame* frame, StrConstRef factorName, factor_func factorBody, boolean threadSafe = false);
  
  static IRTemplate* addTemplate(IRFrame* frame, StrConstRef templateName, const TemplateParaEntry& paraEntry);

  static IRTemplate* addTemplate(IRFrame* frame, StrConstRef templateName, IRCallable* templateBody, int totalParaCount, const std::vector<std::string>& fixedParaNames);

  static IRVar* addVar(IRFrame* frame, StrConstRef name);

  static boolean  canAccess(IRObject* obj, IRInterpreter* interpreter, IRFrame* frame);

  static IRObject* compute(IRObject* obj, IRInterpreter* interpreter, IRFrame* frame);

  static IRObject* computeCallable(IRCallable* callObject, IRList* args, IRInterpreter* interpreter, IRFrame* frame);

  static IRObject* computeFun(IRFunction* fun, IRList* expr, IRInterpreter* interpreter, IRFrame* frame);

  static IRObject* computeFun2(IRFunction* fun, IRInterpreter* interpreter, IRFrame* frame, std::vector<IRObject*>&& objs);

  static RListHandler compute(IRInterpreter* interpreter, StrConstRef input);

  static IRMember* getActualMember(IRMember* mbr, IRInterpreter* interpreter, IRFrame* frame);

  static IRVar* getActualVar(IRVar* var, IRInterpreter* interpreter, IRFrame* frame);

  static int getCallStatsId();

  static int getFrameMaxLevel();

  static int getExprComputeCount(RTypeIndex type);

  static IRClass* getNoClass(IRInterpreter* interpreter);

  static std::map<IRObject*, DeCounter*> getObjecCallCount(IRFrame* frame);

  static void init(IRFrame* frame);

  static boolean isComputable(IRFrame* curFrame, IRObject* obj);

  static boolean isInstanceOf(IRSubject* child, IRSubject* parent);

  static boolean isSubjectFrame(IRFrame* frame);

  static IRFrameEntry* lookupFrameEntry(IRFrame* frame, StrConstRef name);  
 
  static boolean matchParaType(IRObject* paraValue, IRAtom* paraTypeAtom);

  static IRObject* rebuild(IRObject* obj, const std::map<std::string, IRObject*>& replaceMap);

  static IRList* rebuildFuncExpr(IRFunction* fun, IRList* expr, IRInterpreter* interpreter, IRFrame* frame); 

  static IRVar* setVar(IRObject* obj, IRObject* val, IRInterpreter* interpreter, IRFrame* frame);

  static void registryFactor(IRFactor* object);

  static void registryObject(IRObject* object, StrConstRef name);

  static void registryLoader(IRLoader* loader, StrConstRef name);

  static IRLoader* findLoader(StrConstRef name);

  static IRLoader* removeLoader(StrConstRef name);

  static void loadAllRegisterObject(IRInterpreter* interpreter, IRFrame* frame);

  // static void loadAllRegisterLoader(IRInterpreter* interpreter, IRFrame* frame);

  static void reset();

};

template <typename _CLASS> 
struct StaticFactorRegister {
  StaticFactorRegister(std::string _name) {
    static _CLASS _object(_name);
    RuntimeUtil::registryFactor(&_object);
  }
};

template <typename _CLASS> 
struct StaticObjectRegister {
  StaticObjectRegister(_CLASS* _object, std::string _name) {
    RuntimeUtil::registryObject(_object, _name);
  }
};

template <typename _CLASS> 
struct StaticLoaderRegister {
  StaticLoaderRegister(std::string _name) {
    static _CLASS _loader;
    RuntimeUtil::registryLoader(&_loader, _name);
  }
};

#define STATIC_FACTOR_REGISTER(_class, _name) \
  static lfc::StaticFactorRegister<_class> AUTO_NAME(factor) (_name);

#define STATIC_OBJECT_REGISTER(_object, _name) \
  static lfc::StaticObjectRegister<IRObject> AUTO_NAME(object) (_object, _name);

#define STATIC_LOADER_REGISTER(_class, _name) \
  static lfc::StaticLoaderRegister<_class> AUTO_NAME(loader) (_name);

#define XRFACTOR_IMPL_EXTERN(C, B, A) \
class C : public B \
{ \
public: \
  C(StrConstRef factorName) : B(factorName, A) {} \
  virtual ~C() = default; \
};

} // namespace lfc
TRACE_SUB_MODULE_DEF(rt_util)
#endif //__RULP_UTILS_RUNTIME_UTIL_H__