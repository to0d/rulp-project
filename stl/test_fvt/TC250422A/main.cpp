#include <stdio.h>
#include <vector>
#include "lfc/ut/test.h"

int main() 
{
  RUT_START;

  RUT_TEST(std::vector)
  {
    std::vector<int >v;
    for(int i = 0; i < 10000; ++i) {
      v.push_back(i);
    }

    RUT_PRINT(v[999]);
  }

  RUT_FINISH;
  return 0;
}