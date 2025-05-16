#include "unitest_base.h"
#include "rulp/lang.h"
#include "collection/XRCollection.h"

using namespace std;
using namespace lfc;

TEST(rulp_utils_XRCollection, test_XRCollection_1)
{
  XRCollection c1;
  c1.add(O_INT_0);
  c1.add(O_True);  

  auto L1 = c1.toList();
  AUTO_INC_DEC(L1);
  EXPECT_STREQ("'(true 0)", TO_STR(L1).c_str());

  auto L2 = RulpFactory::createList({O_False, O_INT_1});
  AUTO_INC_DEC(L2);
  c1.add(L2);

  auto L3 = c1.toList();
  AUTO_INC_DEC(L3);  
  EXPECT_STREQ("'(true false 0 1)", TO_STR(L3).c_str());

  EXPECT_EQ(1, c1.remove(O_INT_0));
  EXPECT_EQ(0, c1.remove(O_INT_0));

  auto L4 = c1.toList();
  AUTO_INC_DEC(L4);  
  EXPECT_STREQ("'(true false 1)", TO_STR(L4).c_str());

  EXPECT_EQ(2, c1.remove(L2));

  auto L5 = c1.toList();
  AUTO_INC_DEC(L5);  
  EXPECT_STREQ("'(true)", TO_STR(L5).c_str());
}

TEST(rulp_utils_XRCollection, test_XRCollection_1_retainAll)
{

  XRCollection c1;
  c1.add(O_INT_0);
  c1.add(O_True);  
  
  XRCollection c2;
  c2.add(O_INT_1);
  c2.add(O_True);  

  c1.retainAll(c2);

  auto L1 = c1.toList();
  AUTO_INC_DEC(L1);
  EXPECT_STREQ("'(true)", TO_STR(L1).c_str());

}

