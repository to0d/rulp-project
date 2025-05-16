// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_FACTOR_XIMPL_H__
#define __RULP_FACTOR_XIMPL_H__
#include "rulp/lang.h"
#include "rulp/runtime/IRFactor.h"
#include "rulp/utils/RuntimeUtil.h"
#include "rulp/utils/RObjectHandler.h"
#include "rulp/utils/RFrameHandler.h"
#include "AbsAtomFactorAdapter.h"

#define XRFACTOR_IMPL_BEGIN(NEW_FACTOR) \
class NEW_FACTOR \
  : public AbsAtomFactorAdapter \
  , virtual public IRFactor \
{ \
public: \
  NEW_FACTOR(StrConstRef factorName) : AbsAtomFactorAdapter(factorName) {}; \
  virtual ~NEW_FACTOR() = default; \
public: \
  virtual IRObject* compute(IRList* args, IRInterpreter* interpreter, IRFrame* frame) override {

#define XRFACTOR_IMPL_ARG(minArg, maxArg) \
  } \
  virtual int getMinArgCount() const override {return minArg;} \
  virtual int getMaxArgCount() const override {return maxArg;

#define XRFACTOR_IMPL_END } };

#endif //__RULP_FACTOR_XIMPL_H__