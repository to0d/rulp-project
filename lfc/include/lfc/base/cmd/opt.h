// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_CMD_ARG_H__
#define __LFC_CMD_ARG_H__

#include "lfc/base/to_string_macro.h"
#include <cassert>
namespace lfc {

class CmdOpt{
public:

  static void declare_opt(const std::string& key);
  static void remove_opt(const std::string& key);
  static void clear();
  
  static bool has_opt(const std::string& key);
  static bool is_set(const std::string& key);

  static void set_opt_as_string(const std::string& key, const std::string& value);
  static void set_opt_as_bool(const std::string& key, bool value);
  static void set_opt_as_int(const std::string& key, int value);

  static std::string get_opt_as_string(const std::string& key);
  static bool get_opt_as_bool(const std::string& key);
  static int  get_opt_as_int(const std::string& key);

};

namespace _opt{

  template <typename _T>
  struct _opt_util{};

  template <>
  struct _opt_util<std::string>{

    static void set(const std::string& key, const std::string& value){
      CmdOpt::set_opt_as_string(key, value);
    }

    static std::string get(const std::string& key) {
      return CmdOpt::get_opt_as_string(key);
    }

  };

  template <>
  struct _opt_util<bool>{

    static void set(const std::string& key, const bool& value){
      CmdOpt::set_opt_as_bool(key, value);
    }

    static bool get(const std::string& key) {
      return CmdOpt::get_opt_as_bool(key);
    }

  };

  template <>
  struct _opt_util<int>{

    static void set(const std::string& key, const int& value){
      CmdOpt::set_opt_as_int(key, value);
    }

    static int get(const std::string& key) {
      return CmdOpt::get_opt_as_int(key);
    }
  };

}

template <typename _T>
class opt{

  typedef _opt::_opt_util<_T> _opt_util_t;

public:
  opt(const std::string& key)
    : key(key)
    , has_def(false) 
  {
    CmdOpt::declare_opt(key);
  }
  
  opt(const std::string& key, const _T& def_value)
    : key(key)
    , has_def(true)
    , def_value(def_value) 
  {
    CmdOpt::declare_opt(key);
  }

  ~opt(){
    CmdOpt::remove_opt(key);
  }

  std::string get_key(){
    return key;
  }

  _T get_value() {
   
    if(CmdOpt::is_set(key)){
      return _opt_util_t::get(key);
    }

    assert(has_def && "not default value be set");
    return def_value;
  }

  void set(const _T& value){
    _opt_util_t::set(key, value);
  }

private:
  std::string key;
  _T def_value;
  bool has_def;
};


} // namespace lfc
#endif // __LFC_CMD_ARG_H__
