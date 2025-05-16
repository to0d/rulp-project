// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "lfc/base/string.h"
#include "lfc/base/file.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorOutToFile)

  ROH obj = interpreter->compute(frame, args->get(1));
  auto path = AS_STR(obj.get())->asString();

  int lastPos = STR_LAST_INDEX_OF(path, FS_DIR_SEPARATOR[0]);
  if (lastPos != -1) {
    auto folder = path.substr(0, lastPos);
    if(!FS_FOLDER_EXIST(folder)){
      if(!FS_MKDIR(folder)){
        throw RExceptionIO(frame, "fail to mkdir: " + folder);
      }
    }
  }

  auto oldOut = interpreter->getOut();
  LFC_AUTO_DO([&](){
    if (oldOut != null) {
      interpreter->setOutput(oldOut);
    }
  });

  std::vector<std::string> outLines;
  interpreter->setOutput([&](auto line){
    outLines.push_back(line);
  });

  interpreter->compute(frame, args->get(2));

  SAVE_TXT_FILE(path, outLines);

  return O_Nil;

XRFACTOR_IMPL_ARG(3, 3)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorOutToFile, F_OUT_TO_FILE);

} // namespace lfc