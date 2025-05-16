// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_RFACTORY_H__
#define __RULP_LANG_RFACTORY_H__
#include "rulp/lang/base.h"
#include "rulp/lang/RName.h"
#include "rulp/object/IRArray.h"
#include "rulp/object/IRBlob.h"
#include "rulp/object/IRConst.h"
#include "rulp/object/IRError.h"
#include "rulp/runtime/IRFactor.h"
#include "rulp/object/IRInstance.h"
#include "rulp/object/IRVar.h"
#include "rulp/object/IRSubject.h"
#include "rulp/object/IRObjectIterator.h"
#include "rulp/parse/IRParser.h"
#include "rulp/runtime/IRTokenPool.h"
#include "rulp/runtime/IRFunction.h"
#include "rulp/runtime/IRFunctionList.h"
#include "rulp/runtime/IRMacro.h"
#include "rulp/runtime/IRNameSpace.h"
#include "rulp/runtime/IRInterpreter.h"
#include "rulp/runtime/IRTemplate.h"
#include "lfc/base/auto/auto_do.h"

#define RULP_FREE(obj)      lfc::rulp_auto_free(obj)
#define RULP_AUTO_FREE(p)   LFC_AUTO_DO([&](){ RULP_FREE(p); })

namespace lfc {

class RulpFactory {
public:
  static IRTokenPool*     createTokenPool();
  static IRTokener*     createTokener();
  static IRParser*      createParser();
  static IRInterpreter* createInterpreter();

public:

  static IRAtom*          createAtom(StrConstRef name);
  static IRAtom*          createAtom(RName* rname);
  static IRBoolean*       createBoolean(boolean value);
  static IRBlob*          createBlob(int length, const char* value);
  static IRBlob*          createBlob(int length);
  static IRClass*         createClassDefClass(StrConstRef className, IRFrame* definedFrame, IRClass* superClass);
  static IRConst*         createConstant(StrConstRef name, IRObject* value);
  static IRArray*         createConstArray(std::vector<IRObject*>&& elements);
  static IRDouble*        createDouble(double value);
  static IRExpr*          createExpression();
  static IRExpr*          createExpression(std::vector<IRObject*>&& elements);
  static IRExpr*          createExpression(IRObject* list, IRIteratorPtr iter);
  static IRExpr*          createExpressionEarly(std::vector<IRObject*>&& elements);
  static IRError*         createError(IRInterpreter* interpreter, IRAtom* id, IRObject* value);
  static IRFactor*        createFactor(StrConstRef name, factor_func body, boolean threadSafe);
  static IRFloat*         createFloat(float value);
  static IRFrame*         createFrame(IRFrame* parentFrame, StrConstRef name = "");
  static IRFrameEntry*    createFrameEntry(IRFrame* frame, StrConstRef name, IRObject* object);
  static IRFrameEntry*    createFrameEntryProtected(IRFrame* frame, StrConstRef name, IRObject* object);
  static IRFrame*         createFrameSubject(IRSubject* subject, IRFrame* parentFrame);
  static IRFunction*      createFunction(IRFrame* defineFrame, StrConstRef funName, std::vector<IRParaAttr*>&& paraAttrs, IRExpr* funBody);
  static IRFunction*      createFunctionLambda(IRFunction* func, IRFrame* definedFrame);
  static IRFunctionList*  createFunctionList(StrConstRef funName);
  static IRInstance*      createInstanceOfDefault(IRClass* rClass, StrConstRef instanceName, IRFrame* definedFrame);
  static IRInteger*       createInteger(int value);
  static IRList*          createList();
  static IRList*          createList(std::vector<IRObject*>&& elements);
  static IRList*          createList(IRObject* list, IRIteratorPtr iter);
  static IRList*          createListOfString(std::vector<std::string>&& elements);
  static IRObjectIterator* createObjectIterator(IRList* list);
  static IRLong*          createLong(long value);
  static IRMacro*         createMacro(StrConstRef macroName, StrList paraNames, IRExpr* macroBody);
  static IRMember*        createMember(IRObject* subject, StrConstRef name, IRObject* value);
  static IRList*          createNamedList(StrConstRef name, std::vector<IRObject*>&& elements);
  static IRList*          createNamedList(StrConstRef name, IRObject* list, IRIteratorPtr iter);
  static IRNameSpace*     createNameSpace(StrConstRef name, IRClass* rclass, IRFrame* frame);
  static IRParaAttr*      createParaAttr(StrConstRef paraName);  
  static IRParaAttr*      createParaAttr(StrConstRef paraName, IRAtom* paraType);  
  static IRString*        createString(StrConstRef value);
  static IRTemplate*      createTemplate(StrConstRef templateName, IRFrame* defineFrame);
  static IRVar*           createVar(StrConstRef name);
  static IRVar*           createVar(StrConstRef name, IRObject* value);
  static IRArray*         createVaryArray();
  static IRArray*         createVaryArray(const std::vector<int>& sizes);
  static IRList*          createVaryList();
  static IRList*          createVaryNamedList(StrConstRef name);
  

  static void free(IRObject*  obj);
  static void free(IRTokenPool* obj);
  static void free(IRTokener* obj);
  static void free(IRParser*  obj);
  static void free(IRInterpreter* obj);

public:

  static std::string createUniqName(StrConstRef name);

public:

  static int getInterpreterCount();
  static int getFrameEntryCreateCount();
  static int getLambdaCount();

public:

  static void reset();

};

template<typename _T, typename Enable = void>
struct _rulp_auto_free{
  inline static void free(_T ptr){
    if (ptr != 0){
      lfc::RulpFactory::free(ptr);
      ptr = 0;
    }
  }
};

template<typename _T>
struct _rulp_auto_free<std::vector<_T*>>{
  inline static void free(const std::vector<_T*>& vec){
    for(_T* ptr : vec){
      if (ptr != 0){
        RulpFactory::free(ptr);
      }
    }
  }
};

template<typename _T>
void rulp_auto_free(_T ptr){
  typedef _rulp_auto_free<_T> auto_free_type;
  auto_free_type::free(ptr);
}

} // namespace lfc
#endif //__RULP_LANG_RFACTORY_H__