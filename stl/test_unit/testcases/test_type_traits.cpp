#include <gtest/gtest.h>
#include "lfc/stl/type_traits.h"
#include "lfc/ut/gtest_helper.h"

namespace {

template<typename _A, typename _B, typename Enable = void >
struct _add_impl {
  static int _add(const _A& a, const _B& b){
    return 0;
  }
};

template<typename _A, typename _B>
int add(const  _A& a, const _B& b){
  typedef _add_impl<_A, _B> _impl;
  return _impl::_add(a, b);
}

template<typename _A, typename _B>
struct _add_impl<_A, _B, typename lfc::enable_if<MPL_AND<lfc::is_integral<_A>, lfc::is_integral<_B>>::value >::type> {
  static int _add(const  _A& a, const _B& b){
    return (int)a + (int)b;
  }
};

struct X{
  X() = default;
};

TEST(lfc_type_traits, test_and_1)
{
  X a;
  int int_b = 1, short_c = 2;
  EXPECT_EQ(0, add(a, a));
  EXPECT_EQ(3, add(int_b, short_c));
}

}

namespace test_is_integral {

template<typename _A, typename _B, typename Enable = void >
struct _add_impl {
  static int _add(const _A& a, const _B& b){
    return 0;
  }
};

template<typename _A, typename _B>
int add(const  _A& a, const _B& b){
  typedef _add_impl<_A, _B> _impl;
  return _impl::_add(a, b);
}

template<typename T>
struct _add_impl<T, T, typename lfc::enable_if<lfc::is_integral<T>::value>::type> {
  static int _add(const  T& a, const T& b){
    return (int)a + (int)b;
  }
};

struct X{
  X() = default;
};

TEST(lfc_type_traits, test_is_integral_1)
{
  X a;
  int int_b = 1, int_c = 2;
  short short_b = 1, short_c = 2;
  long long_b = 1, long_c = 2;
  unsigned int uint_b = 1, uint_c = 2;
  unsigned short ushort_b = 1, ushort_c = 2;
  unsigned long ulong_b = 1, ulong_c = 2;

  EXPECT_EQ(0, add(a, a));
  EXPECT_EQ(3, add(int_b, int_c));
  EXPECT_EQ(3, add(short_b, short_c));
  EXPECT_EQ(3, add(long_b, long_c));
  EXPECT_EQ(3, add(uint_b, uint_c));
  EXPECT_EQ(3, add(ushort_b, ushort_c));
  EXPECT_EQ(3, add(ulong_b, ulong_c));
}

}

namespace test_enable_if {

template<int N, typename Enable = void>
class TC
{
public:
  static int getSpec() { return 0; }           
};

template<int N>
class TC<N, typename lfc::enable_if<(N>0)>::type>
{
public:
  static int getSpec() { return 1; }            
};

template<int N>
class TC<N, typename lfc::enable_if<(N<0)>::type>
{
public:                 
  static int getSpec() { return 2; }            
};  

TEST(lfc_type_traits, test_enable_if_1)
{
  EXPECT_EQ(0, TC<0>::getSpec());
  EXPECT_EQ(1, TC<1>::getSpec());
  EXPECT_EQ(2, TC<-1>::getSpec());
}

}

TEST(lfc_type_traits, mpl_constrant_1)
{
  TPL_EXPECT_TRUE((lfc::impl::mpl_constant<int, 0>::value) ==  0);
  TPL_EXPECT_TRUE((lfc::impl::mpl_constant<int, 5>::value) ==  5);
  TPL_EXPECT_TRUE((lfc::impl::mpl_constant<int,-1>::value) == -1);
}

TEST(lfc_type_traits, mpl_int_1)
{
  TPL_EXPECT_TRUE((lfc::impl::mpl_int<0>::value) == 0);
  TPL_EXPECT_TRUE((lfc::impl::mpl_int<1>::value) == 1);
  TPL_EXPECT_TRUE((lfc::impl::mpl_int<-1>::value)== -1);
}

TEST(lfc_type_traits, test_decay_1)
{
  TPL_EXPECT_TRUE (lfc::is_same_v<lfc::decay<int&>::type, int>);
  TPL_EXPECT_TRUE (lfc::is_same_v<lfc::decay<const int[3]>::type, const int*>);
  TPL_EXPECT_TRUE (lfc::is_same_v<lfc::decay<int(double)>::type, int(*)(double)>);
}

TEST(lfc_type_traits, test_is_same_1)
{
  TPL_EXPECT_TRUE (lfc::is_same<float, float>::value);
  TPL_EXPECT_FALSE(lfc::is_same<float, int>::value);
}

TEST(lfc_type_traits, test_is_same_v_1)
{
  TPL_EXPECT_TRUE (lfc::is_same_v<float, float>);
  TPL_EXPECT_FALSE(lfc::is_same_v<float, int>);
}

TEST(lfc_type_traits, test_is_one_of)
{
  TPL_EXPECT_TRUE(lfc::is_one_of<int, float, double, int>::value);
  TPL_EXPECT_FALSE(lfc::is_one_of<int, float, double, char>::value);
}

TEST(lfc_type_traits, test_is_float_v_1)
{
  TPL_EXPECT_TRUE (lfc::is_float_v<float>);
  TPL_EXPECT_FALSE(lfc::is_float_v<int>);
}

TEST(lfc_type_traits, test_is_floating_point_1)
{
  TPL_EXPECT_TRUE (lfc::is_floating_point<float>::value);
  TPL_EXPECT_FALSE(lfc::is_floating_point<int>::value);
}

TEST(lfc_type_traits, test_is_integral_v_1)
{
  TPL_EXPECT_FALSE(lfc::is_integral_v<float>);
  TPL_EXPECT_TRUE (lfc::is_integral_v<int>);
}

struct Foo {
  void func() {}
  static void static_func() {}
  int data;
};

TEST(lfc_type_traits, test_is_member_function_pointer_1)
{
  TPL_EXPECT_TRUE (lfc::is_member_function_pointer<decltype(&Foo::func)>::value);
  TPL_EXPECT_FALSE(lfc::is_member_function_pointer<decltype(&Foo::static_func)>::value);
  TPL_EXPECT_FALSE(lfc::is_member_function_pointer<int(Foo::*)>::value); 
}

TEST(lfc_type_traits, test_remove_pointer_1)
{
  TPL_EXPECT_TRUE (lfc::is_same_v<lfc::remove_pointer<int*>::type, int>);
  TPL_EXPECT_TRUE (lfc::is_same_v<lfc::remove_pointer<int* const>::type, int>);
  TPL_EXPECT_TRUE (lfc::is_same_v<lfc::remove_pointer<int>::type, int>);
}

TEST(lfc_type_traits, test_decay_t_1)
{
  TPL_EXPECT_TRUE (lfc::is_same_v<lfc::decay_t<int&>, int>);
  TPL_EXPECT_TRUE (lfc::is_same_v<lfc::decay_t<const int[3]>, const int*>);
  TPL_EXPECT_TRUE (lfc::is_same_v<lfc::decay_t<int(double)>, int(*)(double)>);
}


