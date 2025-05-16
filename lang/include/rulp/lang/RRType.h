// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_RRTYPE_H__
#define __RULP_LANG_RRTYPE_H__

#include "lfc/base/trace_macro.h"
#include "rulp/lang/base.h"
#include "rulp/lang/RConstant.h"
#include "lfc/base/to_string_macro.h"
#include <string>
#include <vector>

namespace lfc {

enum RTypeIndex {
    E_NIL = 0
  , E_ATOM
  , E_BOOL
  , E_INT
  , E_LONG
  , E_FLOAT
  , E_DOUBLE
  , E_STRING
  , E_BLOB
  , E_LIST
  , E_EXPR
  , E_ARRAY
  , E_VAR
  , E_CONSTANT
  , E_FACTOR
  , E_FUNC
  , E_TEMPLATE
  , E_MACRO
  , E_INSTANCE
  , E_CLASS
  , E_NATIVE
  , E_MEMBER
  , E_FRAME
  , E_ITERATOR
};

class IRAtom;
IRAtom* toObject(RTypeIndex type);

class RRType final{
public:
  RRType(RTypeIndex index, std::string name);

private: // make the type object noncopyable
  RRType( const RRType& );
  const RRType& operator=( const RRType& );

public:

	RTypeIndex getIndex();
	const std::string& getName();

public:

	int getCreateCount();
	int getDeleteCount();

	int incCreateCount();
	void incDeleteCount();
	void reset();

public:

  static RRType* toType(const std::string& name);
  static const std::vector<RRType*>& get_all_rtypes();

public:
  static RRType* type_of_NIL     ();
  static RRType* type_of_ATOM    ();
  static RRType* type_of_BOOL    ();
  static RRType* type_of_INT     ();
  static RRType* type_of_LONG    ();
  static RRType* type_of_FLOAT   ();
  static RRType* type_of_DOUBLE  ();
  static RRType* type_of_STRING  ();
  static RRType* type_of_BLOB    ();
  static RRType* type_of_LIST    ();
  static RRType* type_of_EXPR    ();
  static RRType* type_of_ARRAY   ();
  static RRType* type_of_VAR     ();
  static RRType* type_of_CONSTANT();
  static RRType* type_of_FACTOR  ();
  static RRType* type_of_FUNC    ();
  static RRType* type_of_TEMPLATE();
  static RRType* type_of_MACRO   ();
  static RRType* type_of_INSTANCE();
  static RRType* type_of_CLASS   ();
  static RRType* type_of_NATIVE  ();
  static RRType* type_of_MEMBER  ();
  static RRType* type_of_FRAME   ();
  static RRType* type_of_ITERATOR();

private:
  
  RTypeIndex index;
  int createCount;
  int deleteCount;
  std::string name;

};

} // namespace lfc
namespace lfc {
std::string to_string(lfc::RRType* type);
} // namespace lfc

#endif //__RULP_LANG_RRTYPE_H__
