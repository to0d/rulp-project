#ifndef UNITEST_RULP_H
#define UNITEST_RULP_H
#include "rulp/utils/TraceUtil.h"
#include "rulp/utils/RulpUtil.h"
#include "rulp/utils/RuntimeUtil.h"
#include "lfc/base/file.h"
#include "lfc/base/auto/auto_do.h"

#define RULP_AUTO_DUMP(path)  \
lfc::RulpUtil::reset(); \
LFC_AUTO_DO([&](){ dump_rulp_info(path); });

inline void dump_rulp_info(std::string path){
  auto line = lfc::TraceUtil::printGlobalInfo();
  SAVE_TXT_FILE(path, {line});
}


#endif // UNITEST_RULP_H
