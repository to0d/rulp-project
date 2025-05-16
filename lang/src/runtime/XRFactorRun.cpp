// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "lfc/base/file.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorRun)

  int size = args->size();

  std::string path = AS_STR(interpreter->compute(frame, args->get(1)))->asString();
  std::string charset = "utf-8";
  if (size == 3) {
    charset = AS_STR(interpreter->compute(frame, args->get(2)))->asString();
  }

  auto absPath = LoadUtil::lookupFile(path, interpreter, frame);
  if (absPath == "") {
    throw RException("file not found: " + path);
  }

  if (RulpUtil::isTrace(frame)) {
    std::cout << "running: " + absPath;
  }

  RFH runFrame = RulpFactory::createFrame(frame, F_RUN);
  
  try {
    auto rstList = RulpFactory::createVaryList();
    for (auto obj : interpreter->getParser()->parse(RulpUtil::toOneLine(lfc::openTxtFile(path, charset)))) {
      auto rst = interpreter->compute(runFrame, obj);
      rstList->add(rst);
    }

    return O_Nil;
  }
  catch (RExceptionReturn& r) {
    return r.returnValue(frame);
  }

XRFACTOR_IMPL_ARG(2, 3)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorRun, F_RUN);

} // namespace lfc