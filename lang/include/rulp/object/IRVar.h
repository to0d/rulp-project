// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_IRVAR_H__
#define __RULP_LANG_IRVAR_H__
#include "rulp/object/IRObject.h"
#include "lfc/base/function.h"
namespace lfc {
class IRVar : virtual public IRObject {

public:

	class IRVarChangeListener {

	public:
		virtual ~IRVarChangeListener() = default;
		virtual void change(IRVar* var, IRObject* oldValue, IRObject* newValue) = 0;
		virtual void release() = 0;

	};

	typedef IRVarChangeListener* var_change_listener;
  typedef lfc::function<void(IRVar*, IRObject*, IRObject*)> var_change_func;

public:

	virtual void addVarListener(var_change_listener listener) = 0;

	virtual void addVarListener(var_change_func func) = 0;

	virtual std::string getName() const = 0;

	virtual IRObject* getValue() const = 0;

	virtual void setValue(IRObject* newVal) = 0;

};

} // namespace lfc
#endif //__RULP_LANG_IRVAR_H__