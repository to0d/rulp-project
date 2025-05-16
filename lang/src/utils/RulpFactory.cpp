// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/lang.h"
#include "rulp/utils/LoadUtil.h"
#include "rulp/runtime/AbsAtomFactorAdapter.h"
#include "rulp/runtime/AbsRefFactorAdapter.h"
#include "../atom/XRAtomRef.h"
#include "../array/XRArrayConst.h"
#include "../array/XRArrayVary.h"
#include "../blob/XRBlobRef.h"
#include "../const/XRConstRef.h"
#include "../class/XRNoClass.h"
#include "../class/XRDefClass.h"
#include "../class/XRDefInstance.h"
#include "../class/XRMemberRef.h"
#include "../class/XRError.h"
#include "../runtime/XRTokenPool.h"
#include "../runtime/XRInterpreter.h"
#include "../runtime/XRFrameProtected.h"
#include "../runtime/XRFrameEntry.h"
#include "../runtime/XRFrame.h"
#include "../function/XRFunction.h"
#include "../function/XRFunctionLambda.h"
#include "../function/XRFunctionList.h"
#include "../parse/XRTokener.h"
#include "../parse/XRParser.h"
#include "../scalar/XRIntegerRef.h"
#include "../scalar/XRLongRef.h"
#include "../scalar/XRFloatRef.h"
#include "../scalar/XRDoubleRef.h"
#include "../list/XRListConst.h"
#include "../list/XRListVary.h"
#include "../list/XRListIteratorR.h"
#include "../list/XRListBuilderIterator.h"
#include "../iterator/XRObjectIteratorListWrapper.h"
#include "../var/XRVarRef.h"
#include "../var/XRParaAttr.h"
#include "../template/XRTemplate.h"
#include "../subject/XRSubjectFrame.h"
#include "../macro/XRMacro.h"
#include "../namespace/XRNameSpaceClass.h"
#include "../namespace/XRNameSpace.h"
#include "../string/XRStringRef.h"
#include "lfc/base/container.h"
#include "lfc/base/string/format.h"
#include "lfc/base/to_string.h"
#include <iostream>


namespace lfc {

using namespace lfc;

static std::string BLANK_NAME = "";

IRTokener* RulpFactory::createTokener(){
  return new XRTokener();
}

IRParser* RulpFactory::createParser(){
  return new XRParser();
}

IRTokenPool* RulpFactory::createTokenPool(){
  return new XRTokenPool();
}

static int interpreterCount = 0;
static int frameUnNameCount = 0;
static int frameEntryDefaultMaxId = 0;
static int frameEntryProtectedMaxId = 0;
static int lambdaCount = 0;
static int uniqNameCount = 0;

int RulpFactory::getInterpreterCount() {
  return interpreterCount;
}

int RulpFactory::getFrameEntryCreateCount() {
  return frameEntryProtectedMaxId + frameEntryDefaultMaxId;
}

int RulpFactory::getLambdaCount() {
  return lambdaCount;
}

IRInterpreter* RulpFactory::createInterpreter(){
  interpreterCount++;

  /******************************************************/
  // Root Frame
  /******************************************************/
  XRFrame* rootFrame = new XRFrameProtected(A_ROOT);
  rootFrame->setFrameId(I_FRAME_ROOT_ID);
  rootFrame->setEntry(A_ROOT, rootFrame);
  RULP_INC_OBJ_CREATE_COUNT(T_FRAME);

  /******************************************************/
  // System Frame
  /******************************************************/
  XRFrame* systemFrame = new XRFrameProtected(A_SYSTEM);
  systemFrame->setFrameId(I_FRAME_SYSTEM_ID);
  systemFrame->setParentFrame(rootFrame);
  systemFrame->setEntry(A_ROOT, rootFrame);
  systemFrame->setEntry(A_SYSTEM, systemFrame);
  RULP_INC_OBJ_CREATE_COUNT(T_FRAME);

  /******************************************************/
  // Main Frame
  /******************************************************/
  XRFrame* mainFrame = new XRFrame(A_MAIN);
  mainFrame->setFrameId(I_FRAME_MAIN_ID);
  mainFrame->setParentFrame(systemFrame);
  mainFrame->setEntry(A_ROOT, rootFrame);
  mainFrame->setEntry(A_SYSTEM, systemFrame);
  mainFrame->setEntry(A_MAIN, mainFrame);
  RULP_INC_OBJ_CREATE_COUNT(T_FRAME);

  /******************************************************/
  // Main Frame
  /******************************************************/
  XRInterpreter* interpreter = new XRInterpreter();
  interpreter->setMainFrame(mainFrame);
  interpreter->setSystemFrame(systemFrame);
  interpreter->setRootFrame(rootFrame);

  auto context = RulpFactory::createTokenPool();
  auto tokener = RulpFactory::createTokener();
  auto parser  = RulpFactory::createParser();

  tokener->setContext(context);

  parser->setContext(context);
  parser->setTokener(tokener);

  interpreter->setContext(context);
  interpreter->setTokener(tokener);
  interpreter->setParser(parser);

  RuntimeUtil::loadAllRegisterObject(interpreter, rootFrame);


  // RuntimeUtil::addFrameObject(frame, new XRFactorLoadClass(F_LOAD_CLASS));
// 		RuntimeUtil::addFrameObject(frame, new XRFactorIsThreadSafe(F_IS_THREAD_SAFE));
// 		RuntimeUtil::addFrameObject(frame, new XRFactorSleep(F_SLEEP));
// 		RuntimeUtil::addFrameObject(frame, new XRFactorDoParallel(F_DO_Parallel));


// 		RuntimeUtil::addFrameObject(frame, new XRFactorStrdbg(F_STRDBG));
// 		RuntimeUtil::addFrameObject(frame, new XRFactorEnddbg(F_ENDDBG));

  RuntimeUtil::addFrameObject(rootFrame, new XRNoClass(A_NOCLASS, rootFrame));
  RuntimeUtil::addFrameObject(rootFrame, new XRNameSpaceClass(A_NAMESPACE, rootFrame));
  RULP_INC_OBJ_CREATE_COUNT(T_CLASS);

  LoadUtil::initSystemVars(interpreter, systemFrame);
  LoadUtil::initSystemClass(interpreter, systemFrame);
  LoadUtil::initSystemScript(interpreter, systemFrame);

  // RuntimeUtil::loadAllRegisterLoader(interpreter, systemFrame);

  return interpreter;
}


IRAtom* RulpFactory::createAtom(StrConstRef name){

  // if(!RulpUtil::isValidAtomName(name)){
  //   assert(false && "invalid atom name");
  // }
  assert(RulpUtil::isValidAtomName(name) && "invalid atom name");

  auto obj = O_ATOM_OF(name);
  if(obj == NULL){
    RULP_INC_OBJ_CREATE_COUNT(T_ATOM);
    obj = new XRAtomRef(name);
  }

  return obj;
}

IRAtom* RulpFactory::createAtom(RName* rname){
  RULP_INC_OBJ_CREATE_COUNT(T_ATOM);
  return new XRAtomRef(rname->fullName, rname);
}

IRBoolean* RulpFactory::createBoolean(boolean value){
  return value ? O_True : O_False;
}

IRBlob* RulpFactory::createBlob(int length, const char* value){
  RULP_INC_OBJ_CREATE_COUNT(T_BLOB);
  return new XRBlobRef(length, value);
}

IRBlob* RulpFactory::createBlob(int length){
  RULP_INC_OBJ_CREATE_COUNT(T_BLOB);
  return new XRBlobRef(length);
}

IRClass* RulpFactory::createClassDefClass(StrConstRef className, IRFrame* definedFrame, IRClass* superClass) {
  RULP_INC_OBJ_CREATE_COUNT(T_CLASS);
  return new XRDefClass(className, definedFrame, superClass);
}

IRConst* RulpFactory::createConstant(StrConstRef name, IRObject* value){
  RULP_INC_OBJ_CREATE_COUNT(T_CONSTANT);
  return new XRConstRef(name, value);
}

IRArray* RulpFactory::createConstArray(std::vector<IRObject*>&& elements){
  RULP_INC_OBJ_CREATE_COUNT(T_ARRAY);
  return XRArrayConst::build(std::move(elements));
}


IRDouble* RulpFactory::createDouble(double value){
  if(value == 0)
    return O_DOUBLE_0;

  RULP_INC_OBJ_CREATE_COUNT(T_DOUBLE);
  return new XRDoubleRef(value);
}


IRFloat* RulpFactory::createFloat(float value){
  if(value == 0)
    return O_FLOAT_0;

  RULP_INC_OBJ_CREATE_COUNT(T_FLOAT);
  return new XRFloatRef(value);
}


IRFrame* RulpFactory::createFrame(IRFrame* parentFrame, StrConstRef name){

  std::string frameName = name;
  if (frameName.empty()){
    frameName = LFC_STR_FORMAT_BGN "F-%d", frameUnNameCount++ LFC_STR_FORMAT_END;
  }

  XRFrame* frame = new XRFrame(frameName);
  frame->setParentFrame(parentFrame);
  frame->setThreadContext(parentFrame->getThreadContext());

  int frameId = O_FRAME_POOL->allocateFrameId(frame);
  frame->setFrameId(frameId);
  RULP_INC_OBJ_CREATE_COUNT(T_FRAME); 
  
  return frame;
}

IRExpr* RulpFactory::createExpression(){
  return O_EMPTY_EXPR;
}

IRExpr* RulpFactory::createExpression(std::vector<IRObject*>&& elements){
  if(elements.empty())
    return O_EMPTY_EXPR;

  RULP_INC_OBJ_CREATE_COUNT(T_EXPR);
  return new XRListConst(T_EXPR, BLANK_NAME, std::move(elements), false);
}

IRExpr* RulpFactory::createExpression(IRObject* list, IRIteratorPtr iter) {
  if(iter == null || !iter->hasNext())
    return O_EMPTY_EXPR;

  RULP_INC_OBJ_CREATE_COUNT(T_EXPR);
  return new XRListIteratorR(list, iter, T_EXPR, "");
}

IRExpr* RulpFactory::createExpressionEarly(std::vector<IRObject*>&& elements){
  if(elements.empty())
    return O_EMPTY_EXPR;

  RULP_INC_OBJ_CREATE_COUNT(T_EXPR);
  return new XRListConst(T_EXPR, BLANK_NAME, std::move(elements), true);
}

IRError* RulpFactory::createError(IRInterpreter* interpreter, IRAtom* id, IRObject* value) {
  RULP_INC_OBJ_CREATE_COUNT(T_INSTANCE);
  return new XRError(RuntimeUtil::getNoClass(interpreter), id, value);
}

class XRFactorFuncWrapper 
  : public AbsRefFactorAdapter
  , virtual public IRFactor
{

public:

  XRFactorFuncWrapper(StrConstRef factorName, factor_func factorBody, boolean threadSafe)
    : AbsRefFactorAdapter(factorName)
    , factorBody(factorBody)
    , threadSafe(threadSafe)  
   {}

   virtual ~XRFactorFuncWrapper() = default;

   virtual IRObject* compute(IRList* args, IRInterpreter* interpreter, IRFrame* frame) override {
    return factorBody(args, interpreter, frame);
   }

private:
  
  factor_func factorBody = nullptr;
  boolean threadSafe;

};

IRFactor* RulpFactory::createFactor(StrConstRef name, factor_func body, boolean threadSafe) {
  RULP_INC_OBJ_CREATE_COUNT(T_FACTOR);
  return new XRFactorFuncWrapper(name, body, threadSafe);
}

IRFrameEntry* RulpFactory::createFrameEntry(IRFrame* frame, StrConstRef name, IRObject* object) {
  int entryId = ++frameEntryDefaultMaxId;
  RULP_INC_OBJ_CREATE_COUNT(T_MEMBER);
  return new XRFrameEntry(entryId, frame, name, object);
}

IRFrameEntry* RulpFactory::createFrameEntryProtected(IRFrame* frame, StrConstRef name, IRObject* object) {
  int entryId = -(++frameEntryProtectedMaxId);
  RULP_INC_OBJ_CREATE_COUNT(T_MEMBER);
  return new XRFrameEntry(entryId, frame, name, object);
}

static std::string FRAME_PRE_SUBJECT = "SF";

IRFrame* RulpFactory::createFrameSubject(IRSubject* subject, IRFrame* parentFrame){

  std::string frameName = LFC_STR_FORMAT_BGN 
                              "%s-%s-%d"
                            , FRAME_PRE_SUBJECT.c_str()
                            , subject->getSubjectName().c_str()
                            ,frameUnNameCount++
                          LFC_STR_FORMAT_END;
  RULP_INC_OBJ_CREATE_COUNT(T_FRAME);
  XRSubjectFrame* frame = new XRSubjectFrame(frameName);
  frame->setParentFrame(parentFrame);
  frame->setSubject(subject);
  frame->setThreadContext(parentFrame->getThreadContext());
  int frameId = O_FRAME_POOL->allocateFrameId(frame);
  frame->setFrameId(frameId);
  return frame;
}

IRFunction* RulpFactory::createFunction(IRFrame* defineFrame, StrConstRef funName, std::vector<IRParaAttr*>&& paraAttrs, IRExpr* funBody){
  RULP_INC_OBJ_CREATE_COUNT(T_FUNC);
  return new XRFunction(defineFrame, funName, std::move(paraAttrs), funBody);
}

IRFunction* RulpFactory::createFunctionLambda(IRFunction* func, IRFrame* definedFrame){
  RULP_INC_OBJ_CREATE_COUNT(T_FUNC);
  int lambdaId = lambdaCount++;
  return new XRFunctionLambda(func, definedFrame, lambdaId);
}

IRFunctionList* RulpFactory::createFunctionList(StrConstRef funName){
  RULP_INC_OBJ_CREATE_COUNT(T_FUNC);
  return new XRFunctionList(funName);
}

// IRExpr* RulpFactory::createExpression(std::initializer_list<IRObject*> elements){
//   if(elements.size() == 0)
//     return O_EMPTY_EXPR;

//   std::vector<IRObject*> objs;
//   for(auto obj : elements){
//     objs.push_back(obj);
//   }

//   RULP_INC_OBJ_CREATE_COUNT(T_EXPR);
//   return new XRListConst(T_EXPR, BLANK_NAME, std::move(objs), false);
// }

IRInstance* RulpFactory::createInstanceOfDefault(IRClass* rClass, StrConstRef instanceName, IRFrame* definedFrame) {
  RULP_INC_OBJ_CREATE_COUNT(T_INSTANCE);
  return new XRDefInstance(rClass, instanceName, definedFrame);
}

IRMacro* RulpFactory::createMacro(StrConstRef macroName, StrList paraNames, IRExpr* macroBody){
  RULP_INC_OBJ_CREATE_COUNT(T_MACRO);
  return new XRMacro(macroName, paraNames, macroBody);
}

IRInteger* RulpFactory::createInteger(int value){
  auto obj = O_INT_OF(value);
  if(obj == NULL){
    RULP_INC_OBJ_CREATE_COUNT(T_INT);
    obj = new XRIntegerRef(value);
  }

  return obj;
}


IRLong* RulpFactory::createLong(long value){
  auto obj = O_LONG_OF(value);
  if(obj == NULL){
    RULP_INC_OBJ_CREATE_COUNT(T_LONG);
    obj = new XRLongRef(value);
  }

  return obj;
}

IRList* RulpFactory::createList(){;
  return O_EMPTY_LIST;
}

IRList* RulpFactory::createList(std::vector<IRObject*>&& elements){;
  if(elements.empty())
    return O_EMPTY_LIST;

  RULP_INC_OBJ_CREATE_COUNT(T_LIST);
  return new XRListConst(T_LIST, BLANK_NAME, std::move(elements), false);
}

IRList* RulpFactory::createList(IRObject* list, IRIteratorPtr iter){;
  if(iter == null || !iter->hasNext())
    return O_EMPTY_LIST;

  RULP_INC_OBJ_CREATE_COUNT(T_LIST);
  return new XRListIteratorR(list, iter, T_LIST, "");
}

IRList* RulpFactory::createListOfString(std::vector<std::string>&& elements) {
  
  if(elements.empty())
    return O_EMPTY_LIST;

  RULP_INC_OBJ_CREATE_COUNT(T_LIST);
  return new XRListBuilderIterator(T_LIST, "", std::move(elements), [](auto& str) {
			return RulpFactory::createString(str);
		});
}

IRObjectIterator* RulpFactory::createObjectIterator(IRList* list) {
  RULP_INC_OBJ_CREATE_COUNT(T_ITERATOR);
  return new XRObjectIteratorListWrapper(list);
}

IRMember* RulpFactory::createMember(IRObject* subject, StrConstRef name, IRObject* value){
  RULP_INC_OBJ_CREATE_COUNT(T_MEMBER);
  return new XRMemberRef(subject, name, value);
}

IRList* RulpFactory::createNamedList(StrConstRef name, std::vector<IRObject*>&& elements){
  RULP_INC_OBJ_CREATE_COUNT(T_LIST);
  return new XRListConst(T_LIST, name, std::move(elements), false);
}

IRList* RulpFactory::createNamedList(StrConstRef name, IRObject* list, IRIteratorPtr iter) {
  if (name.length() == 0) {
    return createList(list, iter);
  }

  if (iter == null || !iter->hasNext()) {
    RULP_INC_OBJ_CREATE_COUNT(T_LIST);
    return new XRListConst(T_LIST, name, {}, true);
  }

  RULP_INC_OBJ_CREATE_COUNT(T_LIST);
  return new XRListIteratorR(list, iter, T_LIST, name);
}

IRNameSpace* RulpFactory::createNameSpace(StrConstRef name, IRClass* rclass, IRFrame* frame) {
	RULP_INC_OBJ_CREATE_COUNT(T_INSTANCE);
  return new XRNameSpace(name, rclass, frame);
}

IRParaAttr* RulpFactory::createParaAttr(StrConstRef paraName){
  return createParaAttr(paraName, O_Nil);
}

IRParaAttr* RulpFactory::createParaAttr(StrConstRef paraName, IRAtom* paraType){
  if (paraType == null) {
    paraType = O_Nil;
  }
  
  RULP_INC_OBJ_CREATE_COUNT(T_VAR);
  // std::cout << "createParaAttr: " << paraName << "\n";
  return new XRParaAttr(paraName, paraType);
}

IRString* RulpFactory::createString(StrConstRef value){
  if (value.length() == 0) {
    return O_EMPTY_STR;
  }

  RULP_INC_OBJ_CREATE_COUNT(T_STRING);
  return new XRStringRef(value);
}

IRTemplate* RulpFactory::createTemplate(StrConstRef templateName, IRFrame* defineFrame) {
  RULP_INC_OBJ_CREATE_COUNT(T_TEMPLATE);
  return new XRTemplate(templateName, defineFrame);
}

IRVar* RulpFactory::createVar(StrConstRef name){
  RULP_INC_OBJ_CREATE_COUNT(T_VAR);
  // std::cout << "createVar: " << name << "\n";
  // if(name == "x1") {
  //   std::cout << "createVar: " << name << "\n";
  // }
  return new XRVarRef(name);
}

IRVar* RulpFactory::createVar(StrConstRef name, IRObject* value){
  auto var = createVar(name);
  var->setValue(value);
  return var;
}

IRArray* RulpFactory::createVaryArray() {
  RULP_INC_OBJ_CREATE_COUNT(T_ARRAY);
  return XRArrayVary::build({0});
}

IRArray* RulpFactory::createVaryArray(const std::vector<int>& sizes){
  RULP_INC_OBJ_CREATE_COUNT(T_ARRAY);
  return XRArrayVary::build(sizes);
}

IRList* RulpFactory::createVaryList() {
  RULP_INC_OBJ_CREATE_COUNT(T_LIST);
  return new XRListVary(T_LIST, "");
}

IRList* RulpFactory::createVaryNamedList(StrConstRef name) {
  RULP_INC_OBJ_CREATE_COUNT(T_LIST);
  return new XRListVary(T_LIST, name);
}

void RulpFactory::free(IRObject* obj){
  if(!obj)
    return;

  if(RGlobal::is_global_object(obj)){
    return;
  }

  // if(TYPE_INDEX_OF(obj) == E_FUNC && AS_FUNC(obj)->getName() =="lambda" ){
  //   std::cout << "free lambda\n";
  // }

  // if(TYPE_INDEX_OF(obj) == E_MEMBER){
  //   std::cout << "free " << obj->asString() << ", ptr=" << obj << "\n";
  // }

  // std::cout << "free:" << obj->asString() << "\n";

  RULP_INC_OBJ_DELETE_COUNT(obj->getType());
  obj->_delete();  
  delete obj;  
}


void RulpFactory::free(IRTokenPool* obj){
  if(!obj)
    return;

  delete obj; 
}

void RulpFactory::free(IRTokener* obj){
  if(!obj)
    return;

  delete obj; 
}

void RulpFactory::free(IRParser*  obj){
  if(!obj)
    return;

  delete obj; 
}

void RulpFactory::free(IRInterpreter* obj){
  if(!obj)
    return;

  delete obj; 
}

std::string RulpFactory::createUniqName(StrConstRef name) {
  int id = uniqNameCount++;
  return name + TO_STR(id);
}

void RulpFactory::reset(){

  for(auto t : ALL_RTYPE){
    t->reset();
  }

  frameUnNameCount          = 0;
  frameEntryDefaultMaxId    = 0;
  frameEntryProtectedMaxId  = 0;
  // unusedNameCount.set(0);
  interpreterCount          = 0;
  lambdaCount               = 0;
  uniqNameCount             = 0;
}

} // namespace lfc
