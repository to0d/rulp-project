#include "unitest_base.h"
#include "lfc/base/function.h"
#include "lfc/base/function_impl.h"

using namespace lfc;

TEST(base_function, test_function_lambda_1)
{
  lfc::function<int(int)> f = [](int x){return x;}; 
  EXPECT_EQ(2, f(2));
}