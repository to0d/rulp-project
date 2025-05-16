#include "rulp/lang/RType.h"
#include "unitest_base.h"
#include "lfc/base/to_string.h"

using namespace std;
using namespace lfc;

TEST(rulp_lang_type, type_1_getIndex)
{
  EXPECT_EQ(0,  (int)T_NIL      ->getIndex());
  EXPECT_EQ(1,  (int)T_ATOM     ->getIndex());
  EXPECT_EQ(2,  (int)T_BOOL     ->getIndex());
  EXPECT_EQ(3,  (int)T_INT      ->getIndex());
  EXPECT_EQ(4,  (int)T_LONG     ->getIndex());
  EXPECT_EQ(5,  (int)T_FLOAT    ->getIndex());
  EXPECT_EQ(6,  (int)T_DOUBLE   ->getIndex());
  EXPECT_EQ(7,  (int)T_STRING   ->getIndex());
  EXPECT_EQ(8,  (int)T_BLOB     ->getIndex());
  EXPECT_EQ(9,  (int)T_LIST     ->getIndex());
  EXPECT_EQ(10, (int)T_EXPR     ->getIndex());
  EXPECT_EQ(11, (int)T_ARRAY    ->getIndex());
  EXPECT_EQ(12, (int)T_VAR      ->getIndex());
  EXPECT_EQ(13, (int)T_CONSTANT ->getIndex());
  EXPECT_EQ(14, (int)T_FACTOR   ->getIndex());
  EXPECT_EQ(15, (int)T_FUNC     ->getIndex());
  EXPECT_EQ(16, (int)T_TEMPLATE ->getIndex());
  EXPECT_EQ(17, (int)T_MACRO    ->getIndex());
  EXPECT_EQ(18, (int)T_INSTANCE ->getIndex());
  EXPECT_EQ(19, (int)T_CLASS    ->getIndex());
  EXPECT_EQ(20, (int)T_NATIVE   ->getIndex());
  EXPECT_EQ(21, (int)T_MEMBER   ->getIndex());
  EXPECT_EQ(22, (int)T_FRAME    ->getIndex());
  EXPECT_EQ(23, (int)T_ITERATOR ->getIndex());
}


TEST(rulp_lang_type, type_2_type_num)
{
  EXPECT_EQ(24, TYPE_NUM);
}


TEST(rulp_lang_type, type_3_all_rtype)
{
  EXPECT_STREQ("{nil,atom,bool,int,long,float,double,string,blob,\
list,expr,array,var,constant,factor,func,template,macro,instance,\
class,native,member,frame,iterator}", lfc::to_string(ALL_RTYPE).c_str());
}

TEST(rulp_lang_type, type_4_toType)
{
  EXPECT_TRUE(T_NIL      == RRType::toType( A_NIL        ));
  EXPECT_TRUE(T_ATOM     == RRType::toType( A_ATOM       ));
  EXPECT_TRUE(T_BOOL     == RRType::toType( A_BOOL       ));
  EXPECT_TRUE(T_INT      == RRType::toType( A_INTEGER    ));
  EXPECT_TRUE(T_LONG     == RRType::toType( A_LONG       ));
  EXPECT_TRUE(T_FLOAT    == RRType::toType( A_FLOAT      ));
  EXPECT_TRUE(T_DOUBLE   == RRType::toType( A_DOUBLE     ));
  EXPECT_TRUE(T_STRING   == RRType::toType( A_STRING     ));
  EXPECT_TRUE(T_BLOB     == RRType::toType( A_BLOB       ));
  EXPECT_TRUE(T_LIST     == RRType::toType( A_LIST       ));
  EXPECT_TRUE(T_EXPR     == RRType::toType( A_EXPRESSION ));
  EXPECT_TRUE(T_ARRAY    == RRType::toType( A_ARRAY      ));
  EXPECT_TRUE(T_VAR      == RRType::toType( A_VAR        ));
  EXPECT_TRUE(T_CONSTANT == RRType::toType( A_CONSTANT   ));
  EXPECT_TRUE(T_FACTOR   == RRType::toType( A_FACTOR     ));
  EXPECT_TRUE(T_FUNC     == RRType::toType( A_FUNCTION   ));
  EXPECT_TRUE(T_TEMPLATE == RRType::toType( A_TEMPLATE   ));
  EXPECT_TRUE(T_MACRO    == RRType::toType( A_MACRO      ));
  EXPECT_TRUE(T_INSTANCE == RRType::toType( A_INSTANCE   ));
  EXPECT_TRUE(T_CLASS    == RRType::toType( A_CLASS      ));
  EXPECT_TRUE(T_NATIVE   == RRType::toType( A_NATIVE     ));
  EXPECT_TRUE(T_MEMBER   == RRType::toType( A_MEMBER     ));
  EXPECT_TRUE(T_FRAME    == RRType::toType( A_FRAME      ));
  EXPECT_TRUE(T_ITERATOR == RRType::toType( A_ITERATOR   ));
}