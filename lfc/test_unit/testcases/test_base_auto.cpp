#include "unitest_base.h"
#include "lfc/base/auto/auto_do.h"
#include "lfc/base/auto/auto_free.h"

TEST(base_auto, auto_do_while_leave_1)
{
  int val = 0;
  {
    EXPECT_EQ(0, val);
    LFC_AUTO_DO([&val](){val = 1;});
    EXPECT_EQ(0, val);
  }
  EXPECT_EQ(1, val);
}

static int TEST_COUNT = 0;

class TestCounter{
public:
  TestCounter(){
    ++TEST_COUNT;
  }

  ~TestCounter(){
    --TEST_COUNT;
  }
};

TEST(base_auto, auto_free_1)
{
  TEST_COUNT = 0;

  TestCounter* ptr = new TestCounter();
  EXPECT_EQ(1, TEST_COUNT);

  {
    LFC_AUTO_FREE(ptr);
    EXPECT_EQ(1, TEST_COUNT);
  }

  EXPECT_EQ(0, TEST_COUNT);

}

TEST(base_auto, auto_free_2)
{
  TEST_COUNT = 0;

  {
    std::shared_ptr<TestCounter> ptr(new TestCounter());
    EXPECT_EQ(1, TEST_COUNT);

    LFC_AUTO_FREE(ptr);
    EXPECT_EQ(1, TEST_COUNT);
  }

  EXPECT_EQ(0, TEST_COUNT);

}

TEST(base_auto, auto_free_array_1)
{
  TEST_COUNT = 0;

  TestCounter* arr = new TestCounter[2];
  EXPECT_EQ(2, TEST_COUNT);

  {
    LFC_AUTO_FREE_ARRAY(arr);
    EXPECT_EQ(2, TEST_COUNT);
  }

  EXPECT_EQ(0, TEST_COUNT);

}


TEST(base_auto, auto_free_array_2)
{
  TEST_COUNT = 0;

  std::vector<TestCounter*> arr = {new TestCounter(), new TestCounter()};
  EXPECT_EQ(2, TEST_COUNT);

  {
    LFC_AUTO_FREE_ARRAY(arr);
    EXPECT_EQ(2, TEST_COUNT);
  }

  EXPECT_EQ(0, TEST_COUNT);
  EXPECT_EQ(0, arr.size());

}

TEST(base_auto, auto_free_array_3)
{
  TEST_COUNT = 0;

  typedef std::shared_ptr<TestCounter> TestCounterPtr;

  std::vector<TestCounterPtr> arr = {TestCounterPtr(new TestCounter()), TestCounterPtr(new TestCounter())};
  EXPECT_EQ(2, TEST_COUNT);

  {
    LFC_AUTO_FREE_ARRAY(arr);
    EXPECT_EQ(2, TEST_COUNT);
  }

  EXPECT_EQ(0, TEST_COUNT);
  EXPECT_EQ(0, arr.size());

}
