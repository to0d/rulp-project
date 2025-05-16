#ifndef __LFC_CMD_ARG_H__
#define __LFC_CMD_ARG_H__

#include "lfc/base/to_string_macro.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>

namespace lfc {

enum class CmdOptionType{
  UNKNOWN   = -2,
  INVALID   = -1,
  SOURCE    = 0,
  OBJECT,   /* 1 */
  INCLDUE,  /* 2 */
  SRCTYPE,  /* 3 */
  LIBPATH,  /* 4 */
  LIBNAME,  /* 5 */
  DEFMACRO, /* 6 */
  OPTLVL,   /* 7 */
  SCCVIEW,  /* 8 */
  CMDVIEW,  /* 9 */
  KEEPTMPF, /* 10 */
  SCCTRACE, /* 11 */
  KELNODE,  /* 12 */
  VERSION   = 30,
  CMDHELP   = 31,

  SCCTRANS  = 50,
  CLEANBAR, /* 51 */
  SIMPLETR, /* 55 */
};

struct CmdOption {
  CmdOptionType opt_type;
  std::string   opt_key;
  std::string   opt_value;
  void*         opt_def;
  CmdOption() = default;
  CmdOption(const CmdOption&);
  CmdOption(CmdOptionType type, const std::string& key, const std::string& value);
};

enum class CmdActionType{
  INVALID    = 0,  
  COMPILE,  /* 1 */
  CODEGEN,  /* 2 */
  VERSION,  /* 3 */
  SCTRANS,  /* 4 */
  CMDHELP,  /* 5 */
};

struct CmdAction {
  std::string               cmd_name;
  CmdActionType             cmd_type;
  std::vector<CmdOption>    cmd_option_list;
  std::vector<std::string>  cmd_para_list;
  void*                     cmd_def;
  CmdAction() = default;
  CmdAction(const CmdAction&);
};

const std::string to_string(CmdOptionType type);
const std::string to_string(CmdActionType type);
const std::string format_scc_para_list(const CmdAction& CA);

CmdAction process_cmd(const std::vector<std::string>& args);

} // namespace lfc
LFC_TO_STRING_DEF(CmdOption);
LFC_TO_STRING_DEF(CmdAction);
#endif // __LFC_CMD_ARG_H__

