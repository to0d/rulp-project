#include "unitest_base.h"
#include "lfc/base/cast.h"
#include "lfc/base/equal.h"

using namespace lfc;

void _test_str_to_wstring(std::string A, std::wstring B)
{	
  std::string A2;
  std::wstring B2;

  EXPECT_EQ(true, lfc::auto_cast_to(A, B2));
  EXPECT_EQ(true, lfc::auto_cast_to(B, A2));

  EXPECT_EQ(true, lfc::equal(A,A2));
  EXPECT_EQ(true, lfc::equal(B,B2));
}

TEST(base_cast, auto_cast_1_str_to_wstr)
{
  _test_str_to_wstring("",L"");
  _test_str_to_wstring("a",L"a");	
  _test_str_to_wstring("ab",L"ab");	
  _test_str_to_wstring("abc",L"abc");
}

void _test_cast_int_string(const int A, const std::string B) 
{
  int A2;
  std::string B2;

  EXPECT_EQ(true, lfc::auto_cast_to(A, B2));
  EXPECT_EQ(true, lfc::auto_cast_to(B, A2));

  EXPECT_EQ(A, A2);
  EXPECT_EQ(true, lfc::equal(B,B2));
} 

TEST(base_cast, auto_cast_2_int_to_str)
{
  _test_cast_int_string(0,"0");
  _test_cast_int_string(1,"1");
  _test_cast_int_string(-1,"-1");
  _test_cast_int_string(1024,"1024");
}

void _test_cast_int_wstring(const int A, const std::wstring B) 
{
  int A2;
  std::wstring B2;

  EXPECT_EQ(true, lfc::auto_cast_to(A, B2));
  EXPECT_EQ(true, lfc::auto_cast_to(B, A2));

  EXPECT_EQ(A, A2);
  EXPECT_EQ(true, lfc::equal(B,B2));
} 

TEST(base_cast, auto_cast_3_int_to_wstr)
{
  _test_cast_int_wstring(0,L"0");
  _test_cast_int_wstring(1,L"1");
  _test_cast_int_wstring(-1,L"-1");
  _test_cast_int_wstring(1024,L"1024");
}

void _test_cast_long_string(const long A, const std::string B) 
{
  long A2;
  std::string B2;

  EXPECT_EQ(true, lfc::auto_cast_to(A, B2));
  EXPECT_EQ(true, lfc::auto_cast_to(B, A2));

  EXPECT_EQ(A,A2);
  EXPECT_EQ(true, lfc::equal(B,B2));
}


TEST(base_cast, auto_cast_4_long_to_str)
{
  _test_cast_long_string(0,"0");
  _test_cast_long_string(1,"1");
  _test_cast_long_string(-1,"-1");
  _test_cast_long_string(1024,"1024");
}

void _test_cast_long_wstring(const long A, const std::wstring B) 
{
  long A2;
  std::wstring B2;

  EXPECT_EQ(true, lfc::auto_cast_to(A, B2));
  EXPECT_EQ(true, lfc::auto_cast_to(B, A2));

  EXPECT_EQ(A,A2);
  EXPECT_EQ(true, lfc::equal(B,B2));
}

TEST(base_cast, auto_cast_5_long_wstr)
{
  _test_cast_long_wstring(0,L"0");
  _test_cast_long_wstring(1,L"1");
  _test_cast_long_wstring(-1,L"-1");
  _test_cast_long_wstring(1024,L"1024");
}

// void _test_cast_float_wstring(const float A, const std::wstring B) 
// {
//   float A2;
//   std::wstring B2;

//   EXPECT_EQ(true, lfc::auto_cast_to(A, B2));
//   EXPECT_EQ(true, lfc::auto_cast_to(B, A2));   
// }

// TEST(base_help, auto_cast_6)
// {
//   _test_cast_float_wstring(0,L"0");
//   _test_cast_float_wstring(1,L"1");
//   _test_cast_float_wstring((float)0.1,L"0.1");
//   _test_cast_float_wstring(-111.1f,L"-111.1");
// }
