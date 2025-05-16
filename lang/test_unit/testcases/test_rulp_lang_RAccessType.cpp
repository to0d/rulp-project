#include "rulp/lang/RAccessType.h"
#include "rulp/lang/RGlobal.h"
#include "unitest_base.h"

using namespace std;
using namespace lfc;

TEST(rulp_lang_RAccessType, toAccessType_1)
{
  EXPECT_TRUE(RAccessType::PUBLIC  == toAccessType("public"));
  EXPECT_TRUE(RAccessType::PRIVATE == toAccessType("private"));
  EXPECT_TRUE(RAccessType::DEFAULT == toAccessType("default"));
}

TEST(rulp_lang_RAccessType, toObject_1)
{
  EXPECT_TRUE(O_Public   == toObject(RAccessType::PUBLIC));
  EXPECT_TRUE(O_Private  == toObject(RAccessType::PRIVATE));
  EXPECT_TRUE(O_Default  == toObject(RAccessType::DEFAULT));
}

