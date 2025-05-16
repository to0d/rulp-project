// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "lfc/base/abi.h"
#include <string.h>
#include <cxxabi.h>

namespace lfc {
 
std::string demangle_func_name(const std::string& mangled_name) {
  int status;
  const char* str = mangled_name.c_str();
  char* demangled_name = abi::__cxa_demangle(str, nullptr, nullptr, &status);    
  if (status != 0 || demangled_name == NULL || strlen(demangled_name) == 0) {
    return mangled_name;
  }

  std::string result;
  const char* pos = strchr(demangled_name, '(');
  if( pos != NULL )
      result = std::string(demangled_name, 0, pos - demangled_name);
  else
      result = demangled_name;

  std::free(demangled_name);
  return result;
}

} // namespace lfc 


