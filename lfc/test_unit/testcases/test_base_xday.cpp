#include "unitest_base.h"
#include "lfc/base/xday.h"

using namespace lfc;


TEST(XDayTest, TestGetDay) {
  EXPECT_EQ("2015-02-28", XDay::getDay(2015, 2, 28).toString());
}

TEST(XDayTest, TestGetDayOfWeek) {
  EXPECT_EQ(1, XDay::getDay("2015-05-11").getDayOfWeek());
  EXPECT_EQ(2, XDay::getDay("2015-05-12").getDayOfWeek());
  EXPECT_EQ(3, XDay::getDay("2015-05-13").getDayOfWeek());
  EXPECT_EQ(4, XDay::getDay("2015-05-14").getDayOfWeek());
  EXPECT_EQ(5, XDay::getDay("2015-05-15").getDayOfWeek());
  EXPECT_EQ(6, XDay::getDay("2015-05-16").getDayOfWeek());
  EXPECT_EQ(0, XDay::getDay("2015-05-17").getDayOfWeek());
}

TEST(XDayTest, TestGetDiff) {
  EXPECT_EQ(0 , XDay::getDiff(XDay::getDay("2015-12-01"), XDay::getDay("2015-12-01")));
  EXPECT_EQ(-1, XDay::getDiff(XDay::getDay("2015-12-02"), XDay::getDay("2015-12-01")));
  EXPECT_EQ(10, XDay::getDiff(XDay::getDay("2015-12-02"), XDay::getDay("2015-12-12")));
}

TEST(XDayTest, TestGetMinDay) {
  EXPECT_EQ("2015-01-01", XDay::getMinDay(2015, 1).toString());
  EXPECT_EQ("1993-07-01", XDay::getMinDay(1993, 3).toString());
}

TEST(XDayTest, TestGetNumDay) {
  EXPECT_TRUE(XDay::getDay("2012-12-31").isSmallerThan(XDay::getDay("2013-01-01")));
}

TEST(XDayTest, TestGetQuarter) {
  EXPECT_EQ(1, XDay::getDay("2015-01-01").getQuarter());
  EXPECT_EQ(1, XDay::getDay("2015-02-01").getQuarter());
  EXPECT_EQ(1, XDay::getDay("2015-03-01").getQuarter());
  EXPECT_EQ(2, XDay::getDay("2015-04-01").getQuarter());
  EXPECT_EQ(2, XDay::getDay("2015-05-01").getQuarter());
  EXPECT_EQ(2, XDay::getDay("2015-06-01").getQuarter());
  EXPECT_EQ(3, XDay::getDay("2015-07-01").getQuarter());
  EXPECT_EQ(3, XDay::getDay("2015-08-01").getQuarter());
  EXPECT_EQ(3, XDay::getDay("2015-09-01").getQuarter());
  EXPECT_EQ(4, XDay::getDay("2015-10-01").getQuarter());
  EXPECT_EQ(4, XDay::getDay("2015-11-01").getQuarter());
  EXPECT_EQ(4, XDay::getDay("2015-12-01").getQuarter());
}

TEST(XDayTest, TestIsBefore) {
  EXPECT_FALSE(XDay::getDay("1991-12-09").isSmallerThan(XDay::getDay("1991-11-29")));
  EXPECT_FALSE(XDay::getDay("2015-01-01").isSmallerThan(XDay::getDay("2015-01-01")));
  EXPECT_TRUE (XDay::getDay("2015-01-01").isSmallerThan(XDay::getDay("2015-01-02")));
}

TEST(XDayTest, TestListDaysInQuarter) {
  EXPECT_EQ(90, XDay::listDaysInQuarter(2014, 1).size());
  EXPECT_EQ(91, XDay::listDaysInQuarter(2014, 2).size());
  EXPECT_EQ(92, XDay::listDaysInQuarter(2014, 3).size());
  EXPECT_EQ(92, XDay::listDaysInQuarter(2014, 4).size());
}

TEST(XDayTest, TestLastNextDay) {
  EXPECT_EQ("2015-02-28", XDay::getDay("2015-03-01").lastDay().toString());
  EXPECT_EQ("2014-12-31", XDay::getDay("2015-01-01").lastDay().toString());
  EXPECT_EQ("2015-03-01", XDay::getDay("2015-02-28").nextDay().toString());
  EXPECT_EQ("2016-01-01", XDay::getDay("2015-12-31").nextDay().toString());
}

TEST(XDayTest, TestToday) {
  XDay today = XDay::today();
  // Just verify it doesn't throw and returns a valid date
  EXPECT_TRUE(today.isValidDate());
}
