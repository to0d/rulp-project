// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "XRDefClass.h"
#include "rulp/lang.h"
#include "lfc/base/auto/auto_free.h"
#include "lfc/base/container.h"
#include <algorithm>

using namespace lfc;
using namespace lfc;

namespace lfc {

IRInstance* XRDefClass::newInstance(StrConstRef instanceName, IRList* args, IRInterpreter* interpreter, IRFrame* frame) {
  return RulpFactory::createInstanceOfDefault(this, instanceName, getSubjectFrame());
}

} // namespace lfc