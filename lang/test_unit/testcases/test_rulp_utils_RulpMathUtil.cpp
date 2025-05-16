#include "unitest_base.h"
#include "rulp/utils/RulpMathUtil.h"

using namespace std;
using namespace lfc;

TEST(rulp_utils_RulpMathUtil, getTypeConvert_1)
{
  EXPECT_TRUE(RTypeIndex::E_NIL     == RulpMathUtil::getTypeConvert(RTypeIndex::E_NIL   , RTypeIndex::E_NIL));

  EXPECT_TRUE(RTypeIndex::E_ATOM    == RulpMathUtil::getTypeConvert(RTypeIndex::E_ATOM  , RTypeIndex::E_ATOM));
  
  EXPECT_TRUE(RTypeIndex::E_INT     == RulpMathUtil::getTypeConvert(RTypeIndex::E_INT   , RTypeIndex::E_INT));
  EXPECT_TRUE(RTypeIndex::E_LONG    == RulpMathUtil::getTypeConvert(RTypeIndex::E_INT   , RTypeIndex::E_LONG));
  EXPECT_TRUE(RTypeIndex::E_FLOAT   == RulpMathUtil::getTypeConvert(RTypeIndex::E_INT   , RTypeIndex::E_FLOAT));
  EXPECT_TRUE(RTypeIndex::E_DOUBLE  == RulpMathUtil::getTypeConvert(RTypeIndex::E_INT   , RTypeIndex::E_DOUBLE));

  EXPECT_TRUE(RTypeIndex::E_LONG    == RulpMathUtil::getTypeConvert(RTypeIndex::E_LONG  , RTypeIndex::E_INT));
  EXPECT_TRUE(RTypeIndex::E_LONG    == RulpMathUtil::getTypeConvert(RTypeIndex::E_LONG  , RTypeIndex::E_LONG));
  EXPECT_TRUE(RTypeIndex::E_FLOAT   == RulpMathUtil::getTypeConvert(RTypeIndex::E_LONG  , RTypeIndex::E_FLOAT));
  EXPECT_TRUE(RTypeIndex::E_DOUBLE  == RulpMathUtil::getTypeConvert(RTypeIndex::E_LONG  , RTypeIndex::E_DOUBLE));

  EXPECT_TRUE(RTypeIndex::E_FLOAT   == RulpMathUtil::getTypeConvert(RTypeIndex::E_FLOAT , RTypeIndex::E_INT));
  EXPECT_TRUE(RTypeIndex::E_FLOAT   == RulpMathUtil::getTypeConvert(RTypeIndex::E_FLOAT , RTypeIndex::E_LONG));
  EXPECT_TRUE(RTypeIndex::E_FLOAT   == RulpMathUtil::getTypeConvert(RTypeIndex::E_FLOAT , RTypeIndex::E_FLOAT));
  EXPECT_TRUE(RTypeIndex::E_DOUBLE  == RulpMathUtil::getTypeConvert(RTypeIndex::E_FLOAT , RTypeIndex::E_DOUBLE));

  EXPECT_TRUE(RTypeIndex::E_DOUBLE  == RulpMathUtil::getTypeConvert(RTypeIndex::E_DOUBLE, RTypeIndex::E_INT));
  EXPECT_TRUE(RTypeIndex::E_DOUBLE  == RulpMathUtil::getTypeConvert(RTypeIndex::E_DOUBLE, RTypeIndex::E_LONG));
  EXPECT_TRUE(RTypeIndex::E_DOUBLE  == RulpMathUtil::getTypeConvert(RTypeIndex::E_DOUBLE, RTypeIndex::E_FLOAT));
  EXPECT_TRUE(RTypeIndex::E_DOUBLE  == RulpMathUtil::getTypeConvert(RTypeIndex::E_DOUBLE, RTypeIndex::E_DOUBLE));

  EXPECT_TRUE(RTypeIndex::E_BOOL    == RulpMathUtil::getTypeConvert(RTypeIndex::E_BOOL  , RTypeIndex::E_BOOL));

  EXPECT_TRUE(RTypeIndex::E_EXPR    == RulpMathUtil::getTypeConvert(RTypeIndex::E_EXPR  , RTypeIndex::E_EXPR));

}