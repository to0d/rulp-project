// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_RUNTIME_IRITERATOR_H__
#define __RULP_RUNTIME_IRITERATOR_H__

#include "rulp/object/IRObject.h"
#include <memory>
namespace lfc {

class IRIterator{
 
public:
  IRIterator() = default;
  virtual ~IRIterator() = default;

public:

  virtual bool hasNext() const = 0;

  virtual IRObject* next() const = 0;

};

typedef std::shared_ptr<IRIterator> IRIteratorPtr;

} // namespace lfc
#endif //__RULP_RUNTIME_IRITERATOR_H__