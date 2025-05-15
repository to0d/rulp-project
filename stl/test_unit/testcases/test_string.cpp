#include <gtest/gtest.h>
#include "lfc/stl/string.h"

TEST(lfc_string, test_memcpy_basic)
{
  // BasicCopy
  char src1[] = "Hello, world!";
  char dst1[20] = {0};

  lfc::memcpy(dst1, src1, lfc::strlen(src1) + 1);
  EXPECT_STREQ("Hello, world!", static_cast<char*>(dst1));

  // PartialCopy
  int src2[] = {1, 2, 3, 4, 5};
  int dst2[5] = {0};

  lfc::memcpy(reinterpret_cast<char*>(dst2), reinterpret_cast<char*>(src2), sizeof(int) * 2);
  EXPECT_EQ(1, *(static_cast<int*>(dst2)));
  EXPECT_EQ(1, dst2[0]);
  EXPECT_EQ(2, dst2[1]);
  EXPECT_EQ(0, dst2[2]);  // Rest should remain unchanged
}

TEST(lfc_string, test_memcpy_edge_cases)
{
  // ZeroLengthCopy
  char src3[] = "Should not copy";
  char dst3[20] = "Original";
  EXPECT_STREQ("Original", static_cast<char*>(lfc::memcpy(dst3, src3, 0)));

  // MaxSizeCopy (not testing actual max due to time constraints)
  unsigned char src4[256];
  unsigned char dst4[256];
  
  for (int i = 0; i < 256; ++i) {
    src4[i] = static_cast<unsigned char>(i);
  }
  
  lfc::memcpy(dst4, src4, 256);
  
  for (int i = 0; i < 256; ++i) {
    EXPECT_EQ(src4[i], dst4[i]);
  }
}

TEST(lfc_string, test_strlen_1) {

  // BasicChar
  {
    const char* str = "Hello";
    EXPECT_EQ(5, lfc::strlen(str));
  }

  // EmptyString
  {
    const char* str = "";
    EXPECT_EQ(0, lfc::strlen(str));
  }

  // NullPointer
  {
    EXPECT_EQ(0, lfc::strlen(static_cast<const char*>(nullptr)));
  }

}

TEST(lfc_string, test_memset_basic) 
{
  // BasicFill
  char buf1[20] = "Hello, world!";
  lfc::memset(buf1, 'x', 5);
  EXPECT_STREQ("xxxxx, world!", buf1);

  // PartialFill
  int arr1[5] = {1, 2, 3, 4, 5};
  lfc::memset(reinterpret_cast<char*>(arr1), 0, sizeof(int) * 2);
  EXPECT_EQ(0, arr1[0]);
  EXPECT_EQ(0, arr1[1]);
  EXPECT_EQ(3, arr1[2]);  // Rest should remain unchanged
}

TEST(lfc_string, test_memset_edge_cases) 
{
  // ZeroLengthFill
  char buf2[10] = "Original";
  EXPECT_STREQ("Original", static_cast<char*>(lfc::memset(buf2, 'x', 0)));

  // NullTerminatorPreserve
  char buf3[10] = "Hello";
  lfc::memset(buf3, '!', 3);
  EXPECT_STREQ("!!!lo", buf3);  // Null terminator should remain

  // MaxValueFill
  unsigned char buf4[256];
  lfc::memset(buf4, 0xFF, 256);
  for (int i = 0; i < 256; ++i) {
    EXPECT_EQ(0xFF, buf4[i]);
  }

  // NegativeValueFill
  signed char buf5[10];
  lfc::memset(buf5, -1, 10);
  for (int i = 0; i < 10; ++i) {
    EXPECT_EQ(-1, buf5[i]);
  }
}

TEST(lfc_string, test_memset_alignment) 
{
  // UnalignedFill
  struct TestStruct {
    char pad;
    int values[4];
  } s;

  s.values[0] = 1;
  s.values[1] = 2;
  s.values[2] = 3;
  s.values[3] = 4;

  // Fill only 3 elements (partial word)
  lfc::memset(reinterpret_cast<char*>(s.values), 0, sizeof(int)*3);
  EXPECT_EQ(0, s.values[0]);
  EXPECT_EQ(0, s.values[1]);
  EXPECT_EQ(0, s.values[2]);
  EXPECT_EQ(4, s.values[3]);  // Last element unchanged
}

TEST(lfc_string, test_strcpy_basic) 
{
  // BasicCopy
  char dest1[20];
  const char* src1 = "Hello, world!";
  EXPECT_STREQ("Hello, world!", lfc::strcpy(dest1, src1));

  // SelfCopy
  char buf2[20] = "Self copy";
  EXPECT_STREQ("Self copy", lfc::strcpy(buf2, buf2));

  // EmptyString
  char dest3[10] = "original";
  EXPECT_STREQ("", lfc::strcpy(dest3, ""));
}


TEST(lfc_string, test_strcmp_basic) 
{
  // BasicComparison
  EXPECT_EQ(lfc::strcmp("Hello", "Hello") , 0);
  EXPECT_LT(lfc::strcmp("Apple", "Banana"), 0);
  EXPECT_GT(lfc::strcmp("Banana", "Apple"), 0);

  // EmptyString
  EXPECT_EQ(lfc::strcmp("", "") , 0);
  EXPECT_LT(lfc::strcmp("", "a"), 0);
  EXPECT_GT(lfc::strcmp("a", ""), 0);

  // SelfComparison
  const char* str = "Self";
  EXPECT_EQ(lfc::strcmp(str, str), 0);
}

