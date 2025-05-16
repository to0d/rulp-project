#include "unitest_base.h"
#include "lfc/base/random.h"

using namespace std;
using namespace lfc;

TEST(math_random, random_int_1)
{
  Random<int> R(10, 20);
  R.set_seed(0);

  for(int i = 0; i < 10; ++i){
    int v = R();
    EXPECT_TRUE(v >= 10);
    EXPECT_TRUE(v <= 19);
  }
}

TEST(math_random, random_double_1)
{
  Random<double> R(0.0f, 1.0f);
  R.set_seed(0);

  for(int i = 0; i < 10; ++i){
    auto v = R();
    EXPECT_TRUE(v >= 0.0f);
    EXPECT_TRUE(v <= 1.0f);
  }
}