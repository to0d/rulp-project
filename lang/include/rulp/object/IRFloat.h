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

#ifndef __RULP_LANG_IRFLOAT_H__
#define __RULP_LANG_IRFLOAT_H__
#include "rulp/object/IRObject.h"
namespace lfc {

class IRFloat : virtual public IRObject {

public:

  virtual RFloat asFloat() const = 0;

};

} // namespace lfc
#endif //__RULP_LANG_IRFLOAT_H__