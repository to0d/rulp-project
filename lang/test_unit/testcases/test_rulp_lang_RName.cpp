#include "rulp/lang/RName.h"
#include "unitest_base.h"

using namespace std;
using namespace lfc;

TEST(rulp_lang_RName, RName_1)
{
  RName r1("ns1", "pre1", "name1", "fullname1");
  EXPECT_STREQ("RN(ns=ns1, pre=pre1, sub=name1, full=fullname1)", lfc::to_string(r1).c_str());
}

