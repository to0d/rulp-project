// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "XRNameSpaceClass.h"
#include "rulp/lang.h"


using namespace lfc;
using namespace lfc;

namespace lfc {

IRInstance* XRNameSpaceClass::newInstance(StrConstRef nameSpaceName, IRList* args, IRInterpreter* interpreter, IRFrame* frame) {
  if (args->size() != 3) {
    throw RException("Invalid construct parameters: " + args->asString());
  }

  return RulpFactory::createNameSpace(nameSpaceName, this, frame);
}

} // namespace lfc