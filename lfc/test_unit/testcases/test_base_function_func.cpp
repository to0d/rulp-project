#include "unitest_base.h"
#include "lfc/base/function.h"
#include "lfc/base/function_impl.h"

using namespace lfc;

static int _test_bind_1(int x){
  return x + 1;
}

TEST(base_function, test_function_1)
{
  lfc::function<int(int)> f = _test_bind_1;
  EXPECT_EQ(2, f(1));
}

TEST(base_function, test_function_2)
{
  lfc::function<int(int)> f;
  EXPECT_TRUE(f == NULL);
  
  f = _test_bind_1;
  EXPECT_TRUE(f != NULL);

  f = nullptr;
  EXPECT_TRUE(f == NULL);
}

int _test_func_3(int x, function<int(int)> func = nullptr){
  if(func == nullptr){
    return x;
  }
  return func(x);
}

TEST(base_function, test_function_3)
{
  EXPECT_EQ(0, _test_func_3(0));
  EXPECT_EQ(1, _test_func_3(0, [](int x){return x + 1;}));
}

