// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_UTILS_RLIST_HANDLER_H__
#define __RULP_UTILS_RLIST_HANDLER_H__

#include "rulp/object/IRObject.h"
namespace lfc {

class RListHandler{

public:

  RListHandler() = default;
  RListHandler(const RListHandler& RST);
  RListHandler(RListHandler&& RST);
  
  ~RListHandler();

  void addResult(IRObject* rst);
  void free();

  RListHandler& operator=(const RListHandler &RST);
  RListHandler& operator=(RListHandler &&RST);

  template<typename T>
  RListHandler& operator=(std::vector<T*> &list) {
    for(T* v : list) {
      addResult(v);
    }
    return *this;
  }

public:

  std::vector<IRObject*> results;

};

typedef RListHandler RLH;

} // namespace lfc
#endif //__RULP_UTILS_RLIST_HANDLER_H__