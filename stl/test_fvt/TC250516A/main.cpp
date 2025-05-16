#include "lfc/stl/ostream.h"
#include "lfc/ut/test.h"

int main() 
{
  RUT_START;

  RUT_TEST(lfc::cout)
  {
    RUT_RUN((lfc::cout << 123))
    RUT_RUN((lfc::cout << 123 << lfc::endl ))
    RUT_RUN((lfc::cout << 1.1f))
    RUT_RUN((lfc::cout << "abc"))    
  }
 
  RUT_FINISH;
  return 0;
}