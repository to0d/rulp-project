// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "lfc/base/container.h"
#include "lfc/base/string/util.h"
namespace lfc {

static void buildCastTypes(IRObject* toTypeObj, std::vector<RTypeIndex>& toTypes){

  switch (TYPE_INDEX_OF(toTypeObj)){
    case E_ATOM:{
      RType toType = RRType::toType(AS_ATOM(toTypeObj)->asString());
      auto toTypeIndex = toType->getIndex();
      switch (toTypeIndex) {
      case E_INT:
      case E_FLOAT:
        if(!lfc::find(toTypes, toTypeIndex)){
          toTypes.push_back(toTypeIndex);
        }
        return;

      default:
        throw RException("not support type: " + toTypeObj->asString());
      }
    
      break;
    }
    case E_LIST:{
      auto typeList = AS_LIST(toTypeObj);
      if (typeList->isEmpty()) {
        throw RException("not support type: " + toTypeObj->asString());
      }

      auto it = typeList->iterator();
      while (it->hasNext()) {
        buildCastTypes(it->next(), toTypes);
      }

      break;
    }
    default:
      throw RException("not support type: " + toTypeObj->asString());
  }

}

static boolean can_cast_int(IRObject* obj) {

  if (obj == null) {
    return false;
  }

  switch (TYPE_INDEX_OF(obj)) {
  case E_INT:
  case E_LONG:
    return true;

  case E_STRING:
    return STR_IS_INT(AS_STR(obj)->asString());

  case E_VAR:
    return can_cast_int(AS_VAR(obj)->getValue());

  default:
    return false;
  }
}

static boolean can_cast_float(IRObject* obj) {

  if (obj == null) {
    return false;
  }

  switch (TYPE_INDEX_OF(obj)) {
  case E_INT:
  case E_LONG:
  case E_FLOAT:
    return true;

  case E_STRING:
    return STR_IS_FLOAT(AS_STR(obj)->asString());

  case E_VAR:
    return can_cast_float(AS_VAR(obj)->getValue());

  default:
    return false;
  }
}

XRFACTOR_IMPL_BEGIN(XRFactorCanCast)

  ROH toTypeObj = interpreter->compute(frame, args->get(1));
  ROH val       = interpreter->compute(frame, args->get(2));
  
  std::vector<RTypeIndex> toTypes;
  buildCastTypes(toTypeObj, toTypes);
  if (toTypes.empty()) {
    throw RException("not cast type found: " + toTypeObj.get() ->asString());
  }

  boolean rc = false;

  for (RTypeIndex toType : toTypes) {

    switch (toType) {

    case E_INT:
      rc = can_cast_int(val);
      break;

    case E_FLOAT:
      rc = can_cast_float(val);
      break;

    default:
      throw RException("not support type: " + toObject(toType)->asString());
    }

    if (rc) {
      break;
    }
  }

  return RulpFactory::createBoolean(rc);

XRFACTOR_IMPL_ARG(3, 3)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorCanCast, F_CAN_CAST);

} // namespace lfc
