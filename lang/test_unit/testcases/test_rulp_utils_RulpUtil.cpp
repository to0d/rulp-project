#include "unitest_base.h"
#include "rulp/utils/RulpUtil.h"

using namespace std;
using namespace lfc;

TEST(rulp_utils_RulpUtil, isValidAtomName_1)
{
  EXPECT_TRUE(RulpUtil::isValidAtomName("a"));
  EXPECT_FALSE(RulpUtil::isValidAtomName(""));
  EXPECT_FALSE(RulpUtil::isValidAtomName("a "));
}