#include "unitest_base.h"

TEST(base_memory, dump_memory_hex_1)
{
  lfc::dump_memory_hex(NULL, 0);
}

TEST(base_memory, dump_memory_hex_2)
{
  char test[10];
  char other[100];
  memset(test , 0, 10);
  memset(other , 0, 100);
  memcpy(test , "ABCDEFGH", 8);
  memcpy(other, "others"  , 6);
  other[88] = 'a'; 

  auto lines = lfc::dump_memory_hex((void*)test, 10);
  test_lines(lines, "data_base/base_memory/dump_memory_hex_2.txt");
}
