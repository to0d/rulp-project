#include "atom/XRAtomRef.h"
#include "bool/XRBooleanGlobal.h"
#include "scalar/XRDoubleRef.h"
#include "scalar/XRDoubleGlobal.h"
#include "scalar/XRFloatRef.h"
#include "scalar/XRFloatGlobal.h"
#include "scalar/XRIntegerRef.h"
#include "scalar/XRIntegerGlobal.h"
#include "scalar/XRLongRef.h"
#include "scalar/XRLongGlobal.h"
#include "list/XRListConst.h"
#include "var/XRVarRef.h"
#include "rulp/lang/RGlobal.h"
#include "string/XRStringRef.h"
#include "unitest_base.h"
#include "unitest_rulp.h"

using namespace std;
using namespace lfc;


TEST(rulp_lang_object, XRAtomRef_1)
{
  XRAtomRef obj("obj1");
  EXPECT_STREQ("obj1", lfc::to_string(obj).c_str());
  EXPECT_TRUE(obj.getType() == T_ATOM);
  EXPECT_TRUE(obj.getRName() == NULL);  
}

TEST(rulp_lang_object, XRBooleanGlobal_1)
{
  XRBooleanGlobal obj1(true);
  EXPECT_STREQ("", lfc::to_string(obj1).c_str());
  EXPECT_TRUE(obj1.getType() == T_BOOL);
  EXPECT_TRUE(obj1.asBoolean());
  obj1.setString("xxx");
  EXPECT_STREQ("xxx", lfc::to_string(obj1).c_str());

  XRBooleanGlobal obj2(false);
  EXPECT_TRUE(obj2.getType() == T_BOOL);
  EXPECT_STREQ("", lfc::to_string(obj2).c_str());
  EXPECT_FALSE(obj2.asBoolean());
}

TEST(rulp_lang_object, XRDoubleRef_1)
{
  XRDoubleRef obj1(0);
  EXPECT_STREQ("0.0D", lfc::to_string(obj1).c_str());
  EXPECT_TRUE(obj1.getType() == T_DOUBLE);
  EXPECT_TRUE(0 == obj1.asDouble());

  XRDoubleRef obj2(1);
  EXPECT_STREQ("1.000000D", lfc::to_string(obj2).c_str());
  EXPECT_TRUE(obj2.getType() == T_DOUBLE);
  EXPECT_TRUE(1 == obj2.asDouble());
}

TEST(rulp_lang_object, XRDoubleGlobal_1)
{
  XRDoubleGlobal obj1(0);
  EXPECT_STREQ("", lfc::to_string(obj1).c_str());
  EXPECT_TRUE(obj1.getType() == T_DOUBLE);
  EXPECT_TRUE(0 == obj1.asDouble());
  obj1.setString("xxx");
  EXPECT_STREQ("xxx", lfc::to_string(obj1).c_str());

  XRDoubleGlobal obj2(1);
  EXPECT_STREQ("", lfc::to_string(obj2).c_str());
  EXPECT_TRUE(obj2.getType() == T_DOUBLE);
  EXPECT_TRUE(1 == obj2.asDouble());
}

TEST(rulp_lang_object, XRFloatRef_1)
{
  XRFloatRef obj1(0);
  EXPECT_STREQ("0.0", lfc::to_string(obj1).c_str());
  EXPECT_TRUE(obj1.getType() == T_FLOAT);
  EXPECT_TRUE(0 == obj1.asFloat());

  XRFloatRef obj2(1);
  EXPECT_STREQ("1.000000", lfc::to_string(obj2).c_str());
  EXPECT_TRUE(obj2.getType() == T_FLOAT);
  EXPECT_TRUE(1 == obj2.asFloat());
}

TEST(rulp_lang_object, XRFloatGlobal_1)
{
  XRFloatGlobal obj1(0);
  EXPECT_STREQ("", lfc::to_string(obj1).c_str());
  EXPECT_TRUE(obj1.getType() == T_FLOAT);
  EXPECT_TRUE(0 == obj1.asFloat());
  obj1.setString("xxx");
  EXPECT_STREQ("xxx", lfc::to_string(obj1).c_str());

  XRFloatGlobal obj2(1);
  EXPECT_STREQ("", lfc::to_string(obj2).c_str());
  EXPECT_TRUE(obj2.getType() == T_FLOAT);
  EXPECT_TRUE(1 == obj2.asFloat());
}


TEST(rulp_lang_object, XRIntegerRef_1)
{
  XRIntegerRef obj1(0);
  EXPECT_STREQ("0", lfc::to_string(obj1).c_str());
  EXPECT_TRUE(obj1.getType() == T_INT);
  EXPECT_TRUE(0 == obj1.asInteger());

  XRIntegerRef obj2(1);
  EXPECT_STREQ("1", lfc::to_string(obj2).c_str());
  EXPECT_TRUE(obj2.getType() == T_INT);
  EXPECT_TRUE(1 == obj2.asInteger());
}

TEST(rulp_lang_object, XRIntegerGlobal_1)
{
  XRIntegerGlobal obj1(0);
  EXPECT_STREQ("", lfc::to_string(obj1).c_str());
  EXPECT_TRUE(obj1.getType() == T_INT);
  EXPECT_TRUE(0 == obj1.asInteger());
  obj1.setString("xxx");
  EXPECT_STREQ("xxx", lfc::to_string(obj1).c_str());

  XRIntegerGlobal obj2(1);
  EXPECT_STREQ("", lfc::to_string(obj2).c_str());
  EXPECT_TRUE(obj2.getType() == T_INT);
  EXPECT_TRUE(1 == obj2.asInteger());
}

TEST(rulp_lang_object, XRLongRef_1)
{
  XRLongRef obj1(0);
  EXPECT_STREQ("0L", lfc::to_string(obj1).c_str());
  EXPECT_TRUE(obj1.getType() == T_LONG);
  EXPECT_TRUE(0 == obj1.asLong());

  XRLongRef obj2(1);
  EXPECT_STREQ("1L", lfc::to_string(obj2).c_str());
  EXPECT_TRUE(obj2.getType() == T_LONG);
  EXPECT_TRUE(1 == obj2.asLong());
}

TEST(rulp_lang_object, XRLongGlobal_1)
{
  XRLongGlobal obj1(0);
  EXPECT_STREQ("", lfc::to_string(obj1).c_str());
  EXPECT_TRUE(obj1.getType() == T_LONG);
  EXPECT_TRUE(0 == obj1.asLong());
  obj1.setString("xxx");
  EXPECT_STREQ("xxx", lfc::to_string(obj1).c_str());

  XRLongGlobal obj2(1);
  EXPECT_STREQ("", lfc::to_string(obj2).c_str());
  EXPECT_TRUE(obj2.getType() == T_LONG);
  EXPECT_TRUE(1 == obj2.asLong());
}


TEST(rulp_lang_object, XRListConst_1)
{
  XRListConst obj1(T_LIST);
  EXPECT_STREQ("'()", lfc::to_string(obj1).c_str());
  EXPECT_STREQ("", lfc::to_string(obj1.getNamedName()).c_str());
  EXPECT_TRUE(T_LIST == obj1.getType());
  EXPECT_TRUE(0 == obj1.size());
  EXPECT_TRUE(obj1.isEmpty());
  EXPECT_TRUE(obj1.isConst());
  EXPECT_FALSE(obj1.isEarly());
}

TEST(rulp_lang_object, XRListConst_2)
{
  RULP_AUTO_DUMP("data/rulp_lang_object/XRListConst_2_ginfo.txt");

  std::vector<IRObject*> objs = {O_Nil, O_Nil, O_Nil};
  XRListConst obj1(T_LIST, "obj1", std::move(objs), false);
  EXPECT_STREQ("obj1:'(nil nil nil)", lfc::to_string(obj1).c_str());
  EXPECT_STREQ("obj1", lfc::to_string(obj1.getNamedName()).c_str());
  EXPECT_TRUE(T_LIST == obj1.getType());
  EXPECT_EQ(3, obj1.size());
  EXPECT_FALSE(obj1.isEmpty());
  EXPECT_TRUE(obj1.isConst());
  EXPECT_FALSE(obj1.isEarly());

  EXPECT_TRUE(obj1.get(0) != NULL);
  EXPECT_STREQ("nil", lfc::to_string(obj1.get(0)).c_str());
}

TEST(rulp_lang_object, XRListConst_3)
{
  RULP_AUTO_DUMP("data/rulp_lang_object/XRListConst_3_ginfo.txt");

  std::vector<IRObject*> objs = {O_Nil, O_Nil, O_Nil};
  XRListConst obj1(T_EXPR, "", std::move(objs), true);
  EXPECT_STREQ("$(nil nil nil)", lfc::to_string(obj1).c_str());
  EXPECT_STREQ("", lfc::to_string(obj1.getNamedName()).c_str());
  EXPECT_TRUE(T_EXPR == obj1.getType());
  EXPECT_EQ(3, obj1.size());
  EXPECT_FALSE(obj1.isEmpty());
  EXPECT_TRUE(obj1.isConst());
  EXPECT_TRUE(obj1.isEarly());

  EXPECT_TRUE(obj1.get(0) != NULL);
  EXPECT_STREQ("nil", lfc::to_string(obj1.get(0)).c_str());
}

TEST(rulp_lang_object, XRStringRef_1)
{
  XRStringRef obj1("abc");
  EXPECT_STREQ("abc", lfc::to_string(obj1).c_str());
  EXPECT_TRUE(T_STRING == obj1.getType());
}

TEST(rulp_lang_object, XRVarRef_1)
{
  XRVarRef obj1("var1");
  EXPECT_STREQ("var1:\"nil\"", lfc::to_string(obj1).c_str());
  EXPECT_TRUE(obj1.getType() == T_VAR);
  EXPECT_STREQ("var1", obj1.getName().c_str());
  EXPECT_STREQ("nil", lfc::to_string(obj1.getValue()).c_str());

  EXPECT_TRUE(O_INT_0 != NULL);

  obj1.setValue(O_INT_0);
  EXPECT_STREQ("0", lfc::to_string(obj1.getValue()).c_str());
}