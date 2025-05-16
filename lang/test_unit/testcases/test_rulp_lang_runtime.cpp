#include "unitest_base.h"
#include "runtime/XRFramePool.h"
#include "runtime/XRFrame.h"
#include "runtime/XRTokenPool.h"

using namespace std;
using namespace lfc;

TEST(rulp_lang_runtime, test_framepool_1_freeFrameId)
{
  XRFramePool pool(10);

  EXPECT_EQ(3, pool.getFrameMaxId());
  EXPECT_EQ(0, pool.getFrameFreeIdCount());
  EXPECT_EQ(0, pool.listGlobalFrames().size());

  {
    XRFrame frame("");

    int frameId = pool.allocateFrameId(&frame);
    EXPECT_EQ(3, frameId);
    EXPECT_EQ(4, pool.getFrameMaxId());
    EXPECT_EQ(0, pool.getFrameFreeIdCount());
    EXPECT_EQ(1, pool.listGlobalFrames().size());

    pool.freeFrameId(frameId);
    EXPECT_EQ(4, pool.getFrameMaxId());
    EXPECT_EQ(1, pool.getFrameFreeIdCount());
    EXPECT_EQ(0, pool.listGlobalFrames().size());
  }

  {
    XRFrame frame("");

    int frameId = pool.allocateFrameId(&frame);
    EXPECT_EQ(3, frameId);
    EXPECT_EQ(4, pool.getFrameMaxId());
    EXPECT_EQ(0, pool.getFrameFreeIdCount());
    EXPECT_EQ(1, pool.listGlobalFrames().size());

    pool.freeFrameId(frameId);
    EXPECT_EQ(4, pool.getFrameMaxId());
    EXPECT_EQ(1, pool.getFrameFreeIdCount());
    EXPECT_EQ(0, pool.listGlobalFrames().size());
  }
}

TEST(rulp_lang_runtime, test_tokenpool_1_createRName)
{
  XRTokenPool RC;
  auto rname = RC.createRName("ns", "pre", "sub", "full1");
  EXPECT_TRUE(rname != NULL);
  EXPECT_STREQ("RN(ns=ns, pre=pre, sub=sub, full=full1)", TO_STR(rname).c_str());
}

TEST(rulp_lang_runtime, test_tokenpool_2_createToken_1)
{
  XRTokenPool RC;
  auto token = RC.createToken(TokenType::TT_3NAM, "a", 0);
  EXPECT_TRUE(token != NULL);
  EXPECT_STREQ("TK(type=N, value=a, line=-1, pos=0)", TO_STR(token).c_str());
}

TEST(rulp_lang_runtime, test_tokenpool_2_createToken_2)
{
  XRTokenPool RC;
  auto token1 = RC.createToken(TokenType::TT_9END, "a", 0);
  EXPECT_TRUE(token1 != NULL);
  EXPECT_STREQ("TK(type=U, value=, line=-1, pos=-1)", TO_STR(token1).c_str());

  auto token2 = RC.createToken(TokenType::TT_9END, "b", 0);
  EXPECT_TRUE(token2 != NULL);
  EXPECT_STREQ("TK(type=U, value=, line=-1, pos=-1)", TO_STR(token2).c_str());

  EXPECT_TRUE(token1 == token2);
}

TEST(rulp_lang_runtime, test_tokenpool_2_getStringId_1)
{
  XRTokenPool RC;
  EXPECT_EQ(0, RC.getStringId(""));
  EXPECT_EQ(0, RC.getStringId(""));
  EXPECT_EQ(1, RC.getStringId("a"));
  EXPECT_EQ(2, RC.getStringId("b"));
  EXPECT_EQ(1, RC.getStringId("a"));
}