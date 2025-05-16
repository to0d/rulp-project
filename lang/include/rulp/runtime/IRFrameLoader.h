// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_RUNTIME_IRFRAME_LOADER_H__
#define __RULP_RUNTIME_IRFRAME_LOADER_H__
#include "rulp/runtime/IRFrame.h"
namespace lfc {

class IRFrameLoader 
{
public:
  virtual IRObject* load(StrConstRef name) = 0;

};

} // namespace lfc
#endif //__RULP_RUNTIME_IRFRAME_LOADER_H__