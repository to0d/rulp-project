// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "lfc/base/file.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorOpenTxtFile)

  int size = args->size();

  ROH obj = interpreter->compute(frame, args->get(1));
  auto path = AS_STR(obj.get())->asString();

  std::string charset;
  if (size == 3) {
    ROH obj2 = interpreter->compute(frame, args->get(2));
    charset = AS_STR(obj2.get())->asString();
  }

  std::vector<std::string> lines = lfc::openTxtFile(path, charset);

  // try {
    return RulpFactory::createListOfString(std::move(lines));
  // } 
  // catch (IOException e) {
  //   if (RulpUtil.isTrace(frame)) {
  //     e.printStackTrace();
  //   }
  //   throw RException(e.toString());
  // }

XRFACTOR_IMPL_ARG(2, 3)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorOpenTxtFile, F_OPEN_TXT_FILE);

} // namespace lfc