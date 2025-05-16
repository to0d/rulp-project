#include "lfc/base/trace_macro.h"
#include "lfc/base/cmd/opt.h"
#include "lfc/base/static/static_holder.h"
#include "lfc/base/to_string.h"
#include "lfc/base/cast.h"
#include <map>
#include <cassert>
namespace lfc {

#define OPT_KEY_TRUE    "true"
#define OPT_KEY_FALSE   "false"

static StaticHolder<std::map<std::string, std::string>> cmdOptHolder;

void CmdOpt::clear(){
  cmdOptHolder->clear();
}

static bool _has_opt(const std::string& key){
  return cmdOptHolder->find(key) != cmdOptHolder->end();
}

static std::string _lookup_opt(const std::string& key){
  assert(_has_opt(key) && "opt key not found");
  return cmdOptHolder->find(key)->second;
}

static void _set_opt(const std::string& key, const std::string& value){
  assert(!key.empty() && "invalid opt key");
  assert(_has_opt(key) && "opt key not found");

  (*cmdOptHolder)[key] = value;
}

void CmdOpt::declare_opt(const std::string& key){
  assert(!key.empty() && "invalid opt key");
  assert(!_has_opt(key) && "duplicated opt key");

  cmdOptHolder->try_emplace(key, "");
}

void CmdOpt::remove_opt(const std::string& key){
  assert(!key.empty() && "invalid opt key");
  assert(_has_opt(key) && "opt key not found");

  cmdOptHolder->erase(key);
}

void CmdOpt::set_opt_as_string(const std::string& key, const std::string& value){
  _set_opt(key, value);
}

void CmdOpt::set_opt_as_bool(const std::string& key, bool value){
  _set_opt(key, value ? OPT_KEY_TRUE : OPT_KEY_FALSE);
}

void CmdOpt::set_opt_as_int(const std::string& key, int value){
  _set_opt(key, lfc::to_string(value));
}


std::string CmdOpt::get_opt_as_string(const std::string& key){
  return _lookup_opt(key);
}

bool CmdOpt::get_opt_as_bool(const std::string& key){
  auto val = _lookup_opt(key);

  if(val == OPT_KEY_TRUE)
    return true;

  if(val == OPT_KEY_FALSE)
    return false;

  assert(false && "invalid bool value");
  return false;
}

int CmdOpt::get_opt_as_int(const std::string& key){
  auto val = _lookup_opt(key);
  return TO_INT(val);
}

bool CmdOpt::has_opt(const std::string& key){
  return _has_opt(key);
}

bool CmdOpt::is_set(const std::string& key){
  return !_lookup_opt(key).empty();
}

} // namespace lfc