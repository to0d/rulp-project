// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_COLLECTION_IRCOLLECTION_H__
#define __RULP_COLLECTION_IRCOLLECTION_H__
#include "rulp/lang/base.h"
namespace lfc {

class IRCollection  {

public:

	virtual void clear() = 0;
	virtual boolean isEmpty() const = 0;
  virtual	int size() const = 0;

};

} // namespace lfc
#endif //__RULP_COLLECTION_IRCOLLECTION_H__