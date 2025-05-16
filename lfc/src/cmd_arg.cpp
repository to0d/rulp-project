#include "lfc/base/trace_macro.h"
#define LFC_TRACE_STREAM  std::cout
#include "lfc/base/cmd/arg.h"
#include "lfc/base/string/util.h"
#include "lfc/base/trace.h"
#include "lfc/base/to_string.h"
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace lfc;

#define CMD_NAME_SCC        "scc"
#define OPT_VALUE_C         "c"
#define OPT_VALUE_CXX       "c++"

namespace lfc {

typedef bool (*opt_value_check) (const std::string&);

static bool check_x(const std::string& value){
  return value == OPT_VALUE_C || value == OPT_VALUE_CXX;
}

static bool check_opt_level(const std::string& value){
  if(!STR_IS_INT(value))
    return false;
 
  int level = std::atoi(value.c_str());
  return level >= 0 && level <= 3; 
}

struct CmdOptDef {
  CmdOptionType   cd_type;
  std::string     cd_name;
  std::string     cd_scc_name;
  int             cd_has_value;
  int             cd_combine;
  int             cd_order;
  opt_value_check cd_value_check_func;

  CmdOptDef() = default;
  CmdOptDef(const CmdOptDef&);
  CmdOptDef(const std::string&, int, int, int, int, const std::string&, opt_value_check);
};

struct CmdActionDef {
  CmdActionType   type;
  std::string     scc_name;
  CmdActionDef() = default;
  CmdActionDef(const CmdActionDef&);
  CmdActionDef(const std::string&, int);
};


#define opt_has_value(opt) ((opt).cd_has_value == 1)
#define opt_can_combine(opt) ((opt).cd_has_value == 1)

static std::vector<CmdOptDef> cmd_opt_def_list = {

  // scc commands
  {"c"                    ,  0, 0, 0,  1, ""           , 0},
  {"o"                    ,  1, 1, 0,  2, "o"          , 0},
  {"I"                    ,  2, 1, 1,  3, "I"          , 0},
  {"x"                    ,  3, 1, 0,  4, "x"          , check_x},
  {"L"                    ,  4, 1, 1,  5, "L"          , 0},
  {"l"                    ,  5, 1, 1,  6, "l"          , 0},
  {"D"                    ,  6, 1, 1,  7, "D"          , 0},
  {"O"                    ,  7, 1, 1,  8, "O"          , check_opt_level},
  {"v"                    ,  8, 0, 0,  9, "v"          , 0},
  {"V"                    ,  9, 0, 0, 10, "V"          , 0},
  {"-keep-tmp-files"      , 10, 0, 0, 11, "ktf"        , 0},
  {"ktf"                  , 10, 0, 0, 11, "ktf"        , 0},
  {"t"                    , 11, 0, 0, 12, "t"          , 0},
  {"N"                    , 12, 1, 1, 12, "N"          , 0},
  {"-version"             , 30, 0, 0,  0, ""           , 0},
  {"-help"                , 31, 0, 0,  0, ""           , 0},

  // trans commands
  {"trans"                , 50, 0, 0,  1, ""           , 0},
  {"-clean-all-barrier"   , 51, 0, 0, 13, "cab"        , 0},
  {"-simple-task-reorder" , 52, 0, 0, 14, "str"        , 0},
  {"str"                  , 52, 0, 0, 11, "str"        , 0},
};

static CmdActionDef cmd_act_def_list[6]= {
  {"invalid"  ,  0},
  {"compile"  ,  1},
  {"codegen"  ,  2},
  {"version"  ,  3},
  {"sctrans"  ,  4},
  {"cmdhelp"  ,  5},
};

static bool is_cmd_opt(const std::string& opt){
  return opt.size() >= 2 && opt.at(0) == '-';
}

static bool compare_opt(CmdOption& a, CmdOption& b){
  static std::map<CmdOptionType, int> co_order_map;
  {
    if(co_order_map.empty()){
      for(CmdOptDef& COD : cmd_opt_def_list){
        co_order_map[COD.cd_type] = COD.cd_order;
      }
    }
  }

  return co_order_map[a.opt_type] < co_order_map[b.opt_type];
}

static CmdOption next_opt_def(const std::vector<std::string>& args, int& index){
  static std::map<std::string, CmdOptDef*> opt_def_map;
  {
    if(opt_def_map.empty()){
      for(CmdOptDef& COD : cmd_opt_def_list){
        opt_def_map[COD.cd_name] = &COD;
      }
    }
  }

  int size = args.size();
  std::string key = args[index];
  if(!is_cmd_opt(key)){
    LFC_TRACE2("invalid option key: ", key);
    return CmdOption(CmdOptionType::INVALID, key, "");
  }

  key = key.substr(1); 

  auto it = opt_def_map.find(key);
  if(it != opt_def_map.end()){
    ++index;
    CmdOptDef* CDO = it->second;
    std::string value = "";
    if(index < size && opt_has_value(*CDO) && !is_cmd_opt(args[index])){
      value = args[index++];
    }
    
    if(CDO->cd_value_check_func != NULL && !(CDO->cd_value_check_func)(value)){
      LFC_TRACE4("invalid option value: ", value, ", key=", key);
      return CmdOption(CmdOptionType::INVALID, key, value);
    }

    CmdOption opt = CmdOption(CDO->cd_type, key, value);
    opt.opt_def = CDO;
    return opt;
  }

  std::string opt2 = key.substr(0, 1);
  it = opt_def_map.find(opt2);  
  if(it != opt_def_map.end()){
    ++index;
    CmdOptDef* CDO = it->second;    
    if(!opt_can_combine(*CDO)){
      std::string value = "";
      if(index < size && !is_cmd_opt(args[index])){
        value = args[index++];
      }

      return CmdOption(CmdOptionType::UNKNOWN, key, value);
    }

    std::string value = key.substr(1);
    if(CDO->cd_value_check_func != NULL && !(CDO->cd_value_check_func)(value)){
      LFC_TRACE4("invalid option value: ", value, ", key=", key);
      return CmdOption(CmdOptionType::INVALID, opt2, value);
    }
   
    CmdOption opt = CmdOption(CDO->cd_type, opt2, value);
    opt.opt_def = CDO;
    return opt;
  }  
  
  ++index;
  std::string value = "";
  if(index < size && !is_cmd_opt(args[index])){
    value = args[index++];
  } 


  return CmdOption(CmdOptionType::UNKNOWN, key, value);
}

CmdOptDef::CmdOptDef(const CmdOptDef& COF){
  this->cd_name      = COF.cd_name;
  this->cd_type      = COF.cd_type;
  this->cd_has_value = COF.cd_has_value;
  this->cd_combine   = COF.cd_combine;
  this->cd_order     = COF.cd_order;
  this->cd_scc_name  = COF.cd_scc_name;
  this->cd_value_check_func = COF.cd_value_check_func;
}

CmdOptDef::CmdOptDef( const std::string& name
                    , int type
                    , int has_value
                    , int combine
                    , int order
                    , const std::string& scc_name
                    , opt_value_check value_check_func){
  this->cd_name      = name;
  this->cd_type      = (CmdOptionType) type;
  this->cd_has_value = has_value;
  this->cd_combine   = combine;
  this->cd_order     = order;
  this->cd_scc_name  = scc_name;
  this->cd_value_check_func = value_check_func;
}

CmdActionDef::CmdActionDef(const CmdActionDef& CAD){
  this->scc_name  = CAD.scc_name;
  this->type      = CAD.type;
}

CmdActionDef::CmdActionDef(const std::string& scc_name, int type){
  this->scc_name  = scc_name;
  this->type      = (CmdActionType) type;
}

CmdOption::CmdOption(const CmdOption& CO){
  this->opt_type    = CO.opt_type;
  this->opt_key     = CO.opt_key;
  this->opt_value   = CO.opt_value;
  this->opt_def     = CO.opt_def;
}

CmdOption::CmdOption(CmdOptionType type, const std::string& key, const std::string& value){
  this->opt_type  = type;
  this->opt_key   = key;
  this->opt_value = value;
  this->opt_def   = NULL;
}

CmdAction::CmdAction(const CmdAction& CA){
  this->cmd_name        = CA.cmd_name;
  this->cmd_type        = CA.cmd_type;
  this->cmd_option_list = CA.cmd_option_list;
  this->cmd_para_list   = CA.cmd_para_list;
  this->cmd_def         = CA.cmd_def;
}


CmdAction process_cmd(const std::vector<std::string>& args){
  LFC_TRACE1("process_cmd:");
  if(LFC_TRACE_ENABLE){
    for (auto arg : args){
      LFC_TRACE1(arg);
    }
  }

  /************************************************/
  // Parser default command
  /************************************************/
  CmdAction scc_cmd;
  scc_cmd.cmd_type = CmdActionType::INVALID;
  scc_cmd.cmd_name = CMD_NAME_SCC;

  int source_count    = 0;
  int version_count   = 0;
  int scctrans_count  = 0;
  int cmdhelp_count   = 0;

  int arg_index = 0, arg_size = args.size();
  while(arg_index < arg_size){
    if(is_cmd_opt(args[arg_index])){
      CmdOption CO = next_opt_def(args, arg_index);
      switch (CO.opt_type){
      case CmdOptionType::INVALID:
        LFC_TRACE2("invalid option: ", lfc::to_string(CO));
        scc_cmd.cmd_def = &cmd_act_def_list[(int)scc_cmd.cmd_type];
        return scc_cmd;
      case CmdOptionType::SOURCE:
         ++source_count;
         break;
      case CmdOptionType::VERSION:
         ++version_count;
         break;
      case CmdOptionType::SCCTRANS:
         ++scctrans_count;
         break;
      case CmdOptionType::CMDHELP:
         ++cmdhelp_count;
         break;

      default:
        scc_cmd.cmd_option_list.push_back(CO);
        break;
      }      
    }
    else{
      scc_cmd.cmd_para_list.push_back(args[arg_index++]);
    }
  }

  scc_cmd.cmd_type = [&]() -> CmdActionType {
    if(version_count > 0){
      return CmdActionType::VERSION;
    }
    
    if(cmdhelp_count > 0){
      return CmdActionType::CMDHELP;
    }
    
    if(scctrans_count > 0){
      return CmdActionType::SCTRANS;
    }
    
    if(source_count > 0){
      return CmdActionType::COMPILE;
    }
    
    return CmdActionType::CODEGEN;
  }();

  if(scc_cmd.cmd_option_list.size() > 1){

    std::vector<CmdOption> unknown_opts;
    std::vector<CmdOption> temp_opts;

    for(auto& opt : scc_cmd.cmd_option_list){
      if(opt.opt_type == CmdOptionType::UNKNOWN)
        unknown_opts.push_back(opt);
      else
        temp_opts.push_back(opt);
    }

    std::sort(temp_opts.begin(), temp_opts.end(), [&](auto& a, auto& b){return compare_opt(a, b);});
    scc_cmd.cmd_option_list = temp_opts;
    std::copy(unknown_opts.begin(), unknown_opts.end(), std::back_inserter(scc_cmd.cmd_option_list));
  }

  scc_cmd.cmd_def = &cmd_act_def_list[(int)scc_cmd.cmd_type];

  return scc_cmd;
}

const std::string to_string(CmdOptionType type){
  switch (type){
    case CmdOptionType::INVALID : return "INVALID";
    case CmdOptionType::SOURCE  : return "SOURCE";
    case CmdOptionType::OBJECT  : return "OBJECT";
    case CmdOptionType::INCLDUE : return "INCLDUE";
    case CmdOptionType::SRCTYPE : return "SRCTYPE";
    case CmdOptionType::LIBPATH : return "LIBPATH";
    case CmdOptionType::LIBNAME : return "LIBNAME";
    case CmdOptionType::DEFMACRO: return "DEFMACRO";
    case CmdOptionType::OPTLVL  : return "OPTLVL";
    case CmdOptionType::VERSION : return "VERSION";
    case CmdOptionType::CMDHELP : return "CMDHELP";
    case CmdOptionType::SCCVIEW : return "SCCVIEW";
    case CmdOptionType::CMDVIEW : return "CMDVIEW";
    case CmdOptionType::KEEPTMPF: return "KEEPTMPF";
    case CmdOptionType::SCCTRACE: return "SCCTRACE";
    case CmdOptionType::KELNODE : return "KELNODE";
    case CmdOptionType::CLEANBAR: return "CLEANBAR";
    case CmdOptionType::SIMPLETR: return "SIMPLETR";
    case CmdOptionType::UNKNOWN :
    default     : return "UNKNOWN";
  }
}

const std::string to_string(CmdActionType type){
  switch (type){
    case CmdActionType::INVALID: return "INVALID";
    case CmdActionType::COMPILE: return "COMPILE";
    case CmdActionType::CODEGEN: return "CODEGEN";
    case CmdActionType::VERSION: return "VERSION";
    case CmdActionType::SCTRANS: return "SCTRANS";
    case CmdActionType::CMDHELP: return "CMDHELP";
    default     : return "UNKNOWN";
  }
}

LFC_TO_STRING_IMPL(CmdOption, CO){
  if(!CO)
    return "CO(null)";

  std::string out = "CO(";

  out += "type=";
  out += lfc::to_string(CO->opt_type); 

  out += ", key=";
  out += lfc::to_string(CO->opt_key); 

  out += ", value=";
  out += lfc::to_string(CO->opt_value);
 
  out += ")";

  return out;
}

LFC_TO_STRING_IMPL(CmdAction, CA){
  if(!CA)
    return "CMD(null)";

  std::string out = "CMD(";

  out += "name=";
  out += lfc::to_string(CA->cmd_name);

  out += ", type=";
  out += lfc::to_string(CA->cmd_type);

  out += ", option_list=";
  out += lfc::to_string(CA->cmd_option_list);

  out += ", para_list=";
  out += lfc::to_string(CA->cmd_para_list);
  
  out += ")";

  return out;
}

const std::string format_scc_para_list(const CmdAction& CA){
  std::string out = "";

  CmdActionDef* CAD = (CmdActionDef*) CA.cmd_def;
  if(CAD){
    out += "--" + CAD->scc_name;
  }  

  for(auto& para : CA.cmd_para_list){
    out += " -para " + para;
  }
  
  for(auto& opt : CA.cmd_option_list){
    switch (opt.opt_type){
    case CmdOptionType::OBJECT  :
    case CmdOptionType::INCLDUE :
    case CmdOptionType::SRCTYPE :
    case CmdOptionType::LIBPATH :
    case CmdOptionType::LIBNAME :
    case CmdOptionType::DEFMACRO:
    case CmdOptionType::OPTLVL  :
    case CmdOptionType::SCCVIEW :
    case CmdOptionType::CMDVIEW :
    case CmdOptionType::SCCTRACE:
    case CmdOptionType::KEEPTMPF:
    case CmdOptionType::CLEANBAR:
    case CmdOptionType::SIMPLETR:
    case CmdOptionType::KELNODE:
    {
      CmdOptDef* COD = (CmdOptDef*) opt.opt_def;
      if(COD){
        out += " -";
        out += COD->cd_scc_name;

        if(opt.opt_value != ""){
          out += " ";
          out += opt.opt_value;
        }
      }
      break;
    }
    case CmdOptionType::UNKNOWN :
    {
      out += " -";
      out += opt.opt_key;
      if(opt.opt_value != ""){
        out += " ";
        out += opt.opt_value;
      }
      break;
    }

    case CmdOptionType::SOURCE  :
    case CmdOptionType::VERSION :
    case CmdOptionType::CMDHELP :
    case CmdOptionType::INVALID :
    default:
      break;
    }
  }

  return out;
}


} // namespace lfc