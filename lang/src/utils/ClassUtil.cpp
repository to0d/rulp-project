// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/lang.h"
#include "rulp/utils/ClassUtil.h"
#include "lfc/base/string/util.h"
#include "lfc/base/string/format.h"

using namespace lfc;
using namespace lfc;
namespace lfc {

IRClass* ClassUtil::findClass(IRObject* obj, IRFrame* frame) {
  switch (TYPE_INDEX_OF(obj)) {

  case E_ATOM: {
    auto entry = frame->getEntry(AS_ATOM(obj)->getName());
    if (entry != null && entry->getObject() != obj) {
      return findClass(entry->getObject(), frame);
    }

    return null;
  }

  case E_INSTANCE:
    return AS_INSTANCE(obj)->getRClass();

  case E_CLASS:
    return AS_CLASS(obj);

  default:
    return null;
  }
}

IRInstance* ClassUtil::newInstance(IRList* args, IRInterpreter* interpreter, IRFrame* frame) {
  // (new class1 o3 '(1 2))
  // (new class1 o3))
  // (new class1 '(1 2))
  // (new class1)
  if (args->size() > 4) {
    throw RException("Invalid parameters: " + args->asString());
  }

  int argIndex = 1;
  IRObject* argObj = null;
  IRFrame*  definedFrame = frame;

  /******************************************/
  // Class
  /******************************************/
  IRClass* rClass = AS_CLASS(interpreter->compute(frame, args->get(argIndex++)));

  /******************************************/
  // Instance Name
  /******************************************/
  std::string instanceName;
  if (argIndex < args->size()) {

    argObj = args->get(argIndex);

    switch (TYPE_INDEX_OF(argObj)) {
    case E_ATOM: {
      instanceName = AS_ATOM(argObj)->getName();
      ++argIndex;
      break;
    }

    // Create instance in the frame of the specified subject
    case E_MEMBER: {

      auto mbr = AS_MEMBER(argObj);

      auto subObj = RuntimeUtil::compute(mbr->getSubject(), interpreter, frame);
      if (subObj == null) {
        throw RException("subject<" + mbr->getSubject()->asString() + "> not found");
      }
   
      auto sub = AS_SUBJECT(subObj);
      definedFrame = sub->getSubjectFrame();
      instanceName = mbr->getName();
      ++argIndex;

      break;
    }

    // Create instance in member expression: '(:: sub mbr)
    case E_EXPR: {

      auto subExpr = AS_EXPR(argObj);
      auto e0 = subExpr->get(0);

      if ( e0->asString() == F_O_MBR 
          && subExpr->size() == 3
          && (TYPE_INDEX_OF(e0) == E_ATOM || TYPE_INDEX_OF(e0) == E_FACTOR)
          && TYPE_INDEX_OF(subExpr->get(2)) == E_ATOM) {

        auto sub = AS_SUBJECT(interpreter->compute(frame, subExpr->get(1)));
        definedFrame = sub->getSubjectFrame();
        instanceName = AS_ATOM(subExpr->get(2))->getName();
        ++argIndex;
      }

      break;
    }

    default:
      break;

    }

  }

  /******************************************/
  // check object in frame
  /******************************************/
  if (!instanceName.empty()) {

    // Check instance exist
    auto oldEntry = definedFrame->getEntry(instanceName);
    if (oldEntry != null && oldEntry->getFrame() == definedFrame) {
      throw RException( LFC_STR_FORMAT_BGN 
                            "duplicate object<%s> found: %s"
                          , instanceName.c_str()
                          , oldEntry->getObject()->asString().c_str()
                        LFC_STR_FORMAT_END);
    }
  }


  /******************************************/
  // argument list
  /******************************************/
  IRList* initArgs = null;
  if (argIndex < args->size()) {
    initArgs = AS_LIST(interpreter->compute(frame, args->get(argIndex++)));

    if (argIndex != args->size()) {
      throw RException("Invalid parameters: " + args->asString());
    }
  
  } 
  else {
    initArgs = O_EMPTY_LIST;
  }

  /******************************************/
  // Create instance
  /******************************************/
  IRInstance* instance = null;
  try
  {
    instance = rClass->newInstance(instanceName, args, interpreter, definedFrame);
    RulpUtil::setMember(instance, F_MBR_THIS, instance);

    /******************************************/
    // Call Initialization member
    /******************************************/
    instance->init(initArgs, interpreter, frame);

    /******************************************/
    // Add into frame
    /******************************************/
    definedFrame->setEntry(instanceName, instance);

    return instance;
  }
  catch(RException& e)
  {
    AUTO_INC_DEC(instance);
    throw e;
  }
}

} // namespace lfc