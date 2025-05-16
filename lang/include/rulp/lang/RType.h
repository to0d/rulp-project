// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_RTYPE_H__
#define __RULP_LANG_RTYPE_H__
#include "rulp/lang/RRType.h"

#define ALL_RTYPE       RRType::get_all_rtypes()

#define T_NIL           RRType::type_of_NIL     ()
#define T_ATOM          RRType::type_of_ATOM    ()
#define T_BOOL          RRType::type_of_BOOL    ()
#define T_INT           RRType::type_of_INT     ()
#define T_LONG          RRType::type_of_LONG    ()
#define T_FLOAT         RRType::type_of_FLOAT   ()
#define T_DOUBLE        RRType::type_of_DOUBLE  ()
#define T_STRING        RRType::type_of_STRING  ()
#define T_BLOB          RRType::type_of_BLOB    ()
#define T_LIST          RRType::type_of_LIST    ()
#define T_EXPR          RRType::type_of_EXPR    ()
#define T_ARRAY         RRType::type_of_ARRAY   ()
#define T_VAR           RRType::type_of_VAR     ()
#define T_CONSTANT      RRType::type_of_CONSTANT()
#define T_FACTOR        RRType::type_of_FACTOR  ()
#define T_FUNC          RRType::type_of_FUNC    ()
#define T_TEMPLATE      RRType::type_of_TEMPLATE()
#define T_MACRO         RRType::type_of_MACRO   ()
#define T_INSTANCE      RRType::type_of_INSTANCE()
#define T_CLASS         RRType::type_of_CLASS   ()
#define T_NATIVE        RRType::type_of_NATIVE  ()
#define T_MEMBER        RRType::type_of_MEMBER  ()
#define T_FRAME         RRType::type_of_FRAME   ()
#define T_ITERATOR      RRType::type_of_ITERATOR()

#define RULP_INC_OBJ_CREATE_COUNT(type)    (type)->incCreateCount()
#define RULP_INC_OBJ_DELETE_COUNT(type)    (type)->incDeleteCount()
#define RULP_GET_OBJ_CREATE_COUNT(type)    (type)->getCreateCount()
#define RULP_GET_OBJ_DELETE_COUNT(type)    (type)->getDeleteCount()

#define TYPE_INDEX_OF(obj)                ((obj)->getType()->getIndex())
#define IS_TYPE_INDEX_OF(obj, type)       ((obj) != NULL && TYPE_INDEX_OF(obj) == (type))

namespace lfc {

typedef RRType*     RType;
typedef long long   RLong;
typedef int         RInt;
typedef float       RFloat;
typedef double      RDouble;

constexpr int TYPE_NUM = 24;

                            
} // namespace lfc
#endif //__RULP_LANG_RRTYPE_H__