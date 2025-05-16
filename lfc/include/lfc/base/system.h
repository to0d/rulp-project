#ifndef __LFC_SYSTEM_H__
#define __LFC_SYSTEM_H__


#include <vector>
#include <string>

#define SYS_CPU_NUM         lfc::get_cpu_number()
#define SYS_TIME            lfc::get_system_runtime()
#define SYS_TYPE            lfc::getOSType()
#define SYS_IS_LINUX        (lfc::getOSType() == lfc::OSType::Linux)
#define SYS_ENV_PATHS       lfc::getEnvPaths()

namespace lfc {

enum class OSType {
  Linux, Win
};

int   get_cpu_number();
long  get_system_runtime();
OSType getOSType();
std::vector<std::string> getEnvPaths();

} // namespace lfc
#endif // __LFC_SYSTEM_H__

