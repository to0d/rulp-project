#ifndef UNITEST_BASE_H
#define UNITEST_BASE_H

#include "lfc/base.h"
#include "lfc/base/to_string.h"
#include "lfc/base/macro.h"
#include "lfc/base/string/util.h"
#include <gtest/gtest.h>

template <typename T>
void test_lines(const std::vector<T>& vec, std::string path){
  std::vector<std::string> lines;
  std::for_each(vec.begin(), vec.end(), 
    [&](auto d){
      auto line = STR_TRIM_END_NEWLINE(lfc::to_string(d));
      if(line.empty()){
        lines.push_back(line);
      }
      else {
        for(auto line2 : STR_SPLIT_BY_CHAR(line, '\n')){
          auto line3 = STR_TRIM_END_NEWLINE(line2);
          if(!line3.empty()){
            lines.push_back(line3);
          }
        }
      }
    }
  );

  std::string actual_path = path + ".actual";

  SAVE_TXT_FILE(actual_path, lines);

  EXPECT_STREQ(
    lfc::to_string(OPEN_TXT_FILE(path)).c_str(), 
    lfc::to_string(lines).c_str());
}

#endif // UNITEST_BASE_H

