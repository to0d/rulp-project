#include "unitest_base.h"
#include "lfc/base/abi.h"

TEST(base_abi, demangle_func_name_1)
{
  // EXPECT_STREQ("_ZSt4ceilIiEN9__gnu_cxx11__enable_ifIXsr12__is_integerIT_EE7__valueEdE6__typeES2_"
  //   , lfc::demangle_func_name("_ZSt4ceilIiEN9__gnu_cxx11__enable_ifIXsr12__is_integerIT_EE7__valueEdE6__typeES2_").c_str());

  // EXPECT_STREQ("__gnu_cxx::__enable_if<__is_integer<int>::__value, double>::__type std::ceil<int>"  // #TODO fix this
  //   , lfc::demangle_func_name("_ZSt4ceilIiEN9__gnu_cxx11__enable_ifIXsr12__is_integerIT_EE7__valueEdE6__typeES2_").c_str());
}


