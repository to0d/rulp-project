#include "unitest_base.h"
#include "lfc/base/type.h"

using namespace lfc;

TEST(base_type, mpl_store_1)
{
  impl::_store<int,0> s0;

  impl::_store<int,1> s1(1); 
  EXPECT_EQ(s1._va1,1);

  impl::_store<int,2> s2(2);	
  EXPECT_EQ(s2._va2,2);

  impl::_store<int,3> s3(3);	
  EXPECT_EQ(s3._va3,3);

  impl::_store<int,4> s4(4);	
  EXPECT_EQ(s4._va4,4);

  impl::_store<int,5> s5(5);	
  EXPECT_EQ(s5._va5,5);

  impl::_store<int,6> s6(6);	
  EXPECT_EQ(s6._va6,6);

  impl::_store<int,7> s7(7);	
  EXPECT_EQ(s7._va7,7);

  impl::_store<int,8> s8(8);	
  EXPECT_EQ(s8._va8,8);

  impl::_store<int,9> s9(9);	
  EXPECT_EQ(s9._va9,9);
}

TEST(base_type, mpl_list_1)
{
  impl::list1<__LFC_REP1(int)> list1(__LFC_REP1(1)); 	
  EXPECT_EQ(list1._va1,1);

  impl::list2<__LFC_REP2(int)> list2(__LFC_REP2(1)); 	
  EXPECT_EQ(list2._va1,1);
  EXPECT_EQ(list2._va2,1);

  impl::list3<__LFC_REP3(int)> list3(__LFC_REP3(1)); 	
  EXPECT_EQ(list3._va1,1);
  EXPECT_EQ(list3._va2,1);
  EXPECT_EQ(list3._va3,1);

  impl::list4<__LFC_REP4(int)> list4(__LFC_REP4(1)); 	
  EXPECT_EQ(list4._va1,1);
  EXPECT_EQ(list4._va2,1);
  EXPECT_EQ(list4._va3,1);
  EXPECT_EQ(list4._va4,1);

  impl::list5<__LFC_REP5(int)> list5(__LFC_REP5(1)); 	
  EXPECT_EQ(list5._va1,1);
  EXPECT_EQ(list5._va2,1);
  EXPECT_EQ(list5._va3,1);
  EXPECT_EQ(list5._va4,1);
  EXPECT_EQ(list5._va5,1);

  impl::list6<__LFC_REP6(int)> list6(__LFC_REP6(1)); 	
  EXPECT_EQ(list6._va1,1);
  EXPECT_EQ(list6._va2,1);
  EXPECT_EQ(list6._va3,1);
  EXPECT_EQ(list6._va4,1);
  EXPECT_EQ(list6._va5,1);
  EXPECT_EQ(list6._va6,1);

  impl::list7<__LFC_REP7(int)> list7(__LFC_REP7(1)); 	
  EXPECT_EQ(list7._va1,1);
  EXPECT_EQ(list7._va2,1);
  EXPECT_EQ(list7._va3,1);
  EXPECT_EQ(list7._va4,1);
  EXPECT_EQ(list7._va5,1);
  EXPECT_EQ(list7._va6,1);
  EXPECT_EQ(list7._va7,1);

  impl::list8<__LFC_REP8(int)> list8(__LFC_REP8(1)); 	
  EXPECT_EQ(list8._va1,1);
  EXPECT_EQ(list8._va2,1);
  EXPECT_EQ(list8._va3,1);
  EXPECT_EQ(list8._va4,1);
  EXPECT_EQ(list8._va5,1);
  EXPECT_EQ(list8._va6,1);
  EXPECT_EQ(list8._va7,1);
  EXPECT_EQ(list8._va8,1);

  impl::list9<__LFC_REP9(int)> list9(__LFC_REP9(1)); 	
  EXPECT_EQ(list9._va1,1);
  EXPECT_EQ(list9._va2,1);
  EXPECT_EQ(list9._va3,1);
  EXPECT_EQ(list9._va4,1);
  EXPECT_EQ(list9._va5,1);
  EXPECT_EQ(list9._va6,1);
  EXPECT_EQ(list9._va7,1);
  EXPECT_EQ(list9._va8,1);
  EXPECT_EQ(list9._va9,1);
}

