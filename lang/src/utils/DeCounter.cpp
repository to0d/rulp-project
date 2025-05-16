// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/utils/DeCounter.h"
#include "lfc/base/string/format.h"
#include "lfc/base/to_string.h"
#include <sstream>

using namespace lfc;
namespace lfc {

DeCounter::DeCounter(int size)
  : countArray(size, 0)
{
  maxId = unit * size;
}

DeCounter::DeCounter(const DeCounter& D){
  this->countArray  = D.countArray;
  this->maxId       = D.maxId;
  this->totalCount  = D.totalCount;
  this->unit        = D.unit;
}

void DeCounter::add(int id){
  // Need expend?
  while (id >= getMaxId()) {
    expand();
  }

  int idx = id / unit;
  countArray[idx]++;
  ++totalCount;
}

void DeCounter::expand(){
  if (totalCount != 0) {

    int size = countArray.size();
    std::vector<int> newCountArray(size, 0);

    for (int i = 0; i < size / 2; ++i) {
      newCountArray[i] = countArray[2 * i] + countArray[2 * i + 1];
    }

    countArray = newCountArray;
  }

  unit *= 2;
  maxId *= 2;
}

int DeCounter::getCount(int index){
  return countArray[index];
}

int DeCounter::getMaxId(){
  return maxId;
}

int DeCounter::getSize(){
  return countArray.size();
}

int DeCounter::getTotalCount(){
  return totalCount;
}

int DeCounter::getUnit(){
  return unit;
}

std::string DeCounter::toString(){
  
  std::stringstream ss;
  int size = getSize();

  ss << LFC_STR_FORMAT_BGN "total=%d,size=%d,unit=%d,values=[", totalCount, size, unit LFC_STR_FORMAT_END;

  int endIndex = size - 1;
  for (; endIndex >= 0; --endIndex) {
    if (countArray[endIndex] > 0) {
      break;
    }
  }

  for (int i = 0; i <= endIndex; ++i) {

    if (i != 0) {
      ss << ',';
    }

    ss << TO_STR(countArray[i]);
  }

  ss << ']';

  return ss.str();
}

} // namespace lfc