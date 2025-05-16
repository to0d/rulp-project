// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_IRARRAY_H__
#define __RULP_LANG_IRARRAY_H__
#include "rulp/object/IRObject.h"
namespace lfc {

class IRArray : virtual public IRObject {

public:

	virtual void add(IRObject* obj) = 0;

	virtual IRArray* cloneArray() const = 0;

	virtual IRObject* get(int index) const = 0;

	virtual IRObject* get(const std::vector<int>& indexs) const = 0;

	virtual int getDimension() const = 0;

	virtual int getElementCount() const = 0;

	virtual bool isConst() const = 0;

	virtual bool isEmpty() const = 0;

	virtual void set(int index, IRObject* obj) = 0;

	virtual int size() const = 0;

	virtual int size(int dim) const = 0;

};

} // namespace lfc
#endif //__RULP_LANG_IRARRAY_H__