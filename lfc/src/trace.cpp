// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "lfc/base/trace.h"

namespace lfc {

bool global_trace = false;

void set_global_trace(bool trace){
  global_trace = trace;
}

bool get_global_trace(){
  return global_trace;
}

} // namespace lfc 


