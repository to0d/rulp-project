#include "lfc/base/system.h"
#include "lfc/base/string.h"
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <cstdlib>

#if (defined _WIN32) || (defined _WIN64)
  #include <Windows.h>
  #include <process.h>
  #include <winreg.h>
#else
  #include <sys/sysinfo.h>
#endif

namespace lfc {

int get_cpu_number(){
#if (defined _WIN32) || (defined _WIN64)
  SYSTEM_INFO info = {0};
  GetSystemInfo( &info );
  return info.dwNumberOfProcessors;
#else
  return get_nprocs();
#endif
}


long get_system_runtime(){
#if (defined _WIN32) || (defined _WIN64)
  return GetTickCount();
#else 
	struct timespec times = {0, 0};
	long time;

	clock_gettime(CLOCK_MONOTONIC, &times);
	time = times.tv_sec * 1000 + times.tv_nsec / 1000000;
  return time;
#endif
}

OSType getOSType() {
#if (defined _WIN32) || (defined _WIN64)
  return OSType::Win;
#else 
  return OSType::Linux;
#endif
}

std::vector<std::string> getEnvPaths() {
  const char* path = getenv("PATH");
 
  if (path == nullptr) {
    return {};
  }

  std::string spath(path);

  return STR_SPLIT_BY_CHAR(spath, ':');
}

} // namespace lfc


