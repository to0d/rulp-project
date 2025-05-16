// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_UTILS_DECOUNTER_H__
#define __RULP_UTILS_DECOUNTER_H__

#include <string>
#include <vector>
namespace lfc {

class DeCounter {

public:

  DeCounter(int size);
  DeCounter(const DeCounter& D);
  
  ~DeCounter() = default;

public:

  void add(int id);

  void expand();

  int getCount(int index);

  int getMaxId();

  int getSize();

  int getTotalCount();

  int getUnit();

  std::string toString();

private:

  std::vector<int> countArray;

  int maxId;

  int totalCount = 0;

  int unit = 1;

};

} // namespace lfc
#endif //__RULP_UTILS_DECOUNTER_H__