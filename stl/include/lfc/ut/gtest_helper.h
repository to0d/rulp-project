// SPDX-FileCopyrightText: 2023 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __GTEST_HELPER_H__
#define __GTEST_HELPER_H__

#define TPL_EXPECT_TRUE(...) \
  { \
    auto val = __VA_ARGS__; \
    EXPECT_TRUE(true == val); \
  }

#define TPL_EXPECT_FALSE(...) \
  { \
    auto val = __VA_ARGS__; \
    EXPECT_TRUE(false == val); \
  }

#endif // __GTEST_HELPER_H__