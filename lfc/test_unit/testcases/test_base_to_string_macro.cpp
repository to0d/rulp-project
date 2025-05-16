#include "lfc/base/to_string_macro.h"

namespace lfc {

struct TestStruct {
  std::string a;
  int b;

  TestStruct();
  TestStruct(const TestStruct& TS){
    this->a = TS.a;
    this->b = TS.b;
  }
  TestStruct(std::string a, int b){
    this->a = a;
    this->b = b;
  }
};

}

LFC_TO_STRING_DEF(TestStruct);

#include "unitest_base.h"

TEST(base_to_string, macro_DEF_IMPL_1)
{
  lfc::TestStruct TS ("a", 1);
  EXPECT_STREQ("TS(a=a, b=1)", lfc::to_string(TS).c_str());

  lfc::TestStruct* pTS = NULL;
  EXPECT_STREQ("TS(null)", lfc::to_string(pTS).c_str());

  pTS = &TS;
  EXPECT_STREQ("TS(a=a, b=1)", lfc::to_string(pTS).c_str());
}

TEST(base_to_string, macro_DEF_IMPL_2)
{
  lfc::TestStruct t1 ("a1", 1);
  lfc::TestStruct t2 ("a2", 2);
  std::vector<lfc::TestStruct> TS_vec = {t1, t2};
  EXPECT_STREQ("{TS(a=a1, b=1),TS(a=a2, b=2)}", lfc::to_string(TS_vec).c_str());
}

namespace lfc {

LFC_TO_STRING_IMPL(TestStruct, TS){
  if( !TS )
    return "TS(null)";

  std::string out = "TS(";

  out += "a=";
  out += TS->a;

  out += ", b=";
  out += std::to_string(TS->b);
  
  out += ")";

  return out;
}

}
