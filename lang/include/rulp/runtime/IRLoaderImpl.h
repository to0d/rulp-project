// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LOADER_XIMPL_H__
#define __RULP_LOADER_XIMPL_H__
#include "rulp/lang.h"
#include "rulp/runtime/IRLoader.h"

#define XRLOADER_IMPL_BEGIN(LOADER_CLASS) \
class LOADER_CLASS \
  : virtual public IRLoader \
{ \
public: \
  LOADER_CLASS() = default; \
  virtual ~LOADER_CLASS() = default; \
public: \
  virtual void load(IRInterpreter* interpreter, IRFrame* frame) override  {
  
#define XRLOADER_IMPL_END } };

#endif //__RULP_LOADER_XIMPL_H__