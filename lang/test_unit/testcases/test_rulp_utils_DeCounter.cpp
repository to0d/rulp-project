#include "unitest_base.h"
#include "rulp/utils/DeCounter.h"

using namespace std;
using namespace lfc;

TEST(rulp_utils_DeCounter, test_1)
{
  DeCounter c(16);  
  EXPECT_STREQ("total=0,size=16,unit=1,values=[]", c.toString().c_str());

  c.add(1);
  c.add(1);
  c.add(2);
  c.add(2);
  c.add(2);
  c.add(2);
  c.add(10);
  EXPECT_STREQ("total=7,size=16,unit=1,values=[0,2,4,0,0,0,0,0,0,0,1]", c.toString().c_str());

  c.add(18);
  c.add(17);
  c.add(18);
  c.add(1);
  EXPECT_STREQ("total=11,size=16,unit=2,values=[3,4,0,0,0,1,0,0,1,2]", c.toString().c_str());

  c.add(1024);
  EXPECT_STREQ("total=12,size=16,unit=128,values=[11,0,0,0,0,0,0,0,1]", c.toString().c_str());
}