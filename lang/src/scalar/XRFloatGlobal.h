// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
/* Copyright Prolog                                  */
/*                                                   */
/* RULP(Run a Lisp Processer)                        */
/* 													 */
/* Copyright (C) 2020 Todd (to0d@outlook.com)        */
/* This program comes with ABSOLUTELY NO WARRANTY;   */
/* This is free software, and you are welcome to     */
/* redistribute it under certain conditions.         */
#ifndef __RULP_LANG_XRFLOAT_GLOBAL
#define __RULP_LANG_XRFLOAT_GLOBAL
#include "rulp/object/IRFloat.h"
#include "rulp/lang/RGlobal.h"
#include "rulp/object/AbsAtomObject.h"
namespace lfc {

class XRFloatGlobal 
  : public AbsAtomObject
  , virtual public IRFloat 
{

public:

  XRFloatGlobal(float value);
  virtual ~XRFloatGlobal() = default;

public:

  virtual float asFloat() const override;
  virtual const std::string& asString() const override;
  virtual RType getType() const override;

public:

  void setString(std::string str);

private:

  float value;
  std::string _string;

};

} // namespace lfc
#endif //__RULP_LANG_XRFLOAT_GLOBAL