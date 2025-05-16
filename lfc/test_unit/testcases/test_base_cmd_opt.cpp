#include "unitest_base.h"
#include "lfc/base/cmd/opt.h"

using namespace lfc;

TEST(base_cmd_opt, opt_1)
{
  {
    opt<std::string> opt("k1", "def1");
    EXPECT_STREQ("k1", opt.get_key().c_str());
    EXPECT_TRUE(CmdOpt::has_opt("k1"));
    EXPECT_FALSE(CmdOpt::is_set("k1"));
    EXPECT_STREQ("def1", opt.get_value().c_str());

    CmdOpt::set_opt_as_string("k1", "value1");
    EXPECT_TRUE(CmdOpt::is_set("k1"));
    EXPECT_STREQ("value1", opt.get_value().c_str());
  }

  EXPECT_FALSE(CmdOpt::has_opt("k1"));
}

TEST(base_cmd_opt, opt_2)
{

  {
    opt<int> opt("k1", 0);
    EXPECT_STREQ("k1", opt.get_key().c_str());
    EXPECT_TRUE(CmdOpt::has_opt("k1"));
    EXPECT_FALSE(CmdOpt::is_set("k1"));
    EXPECT_EQ(0, opt.get_value());   

    CmdOpt::set_opt_as_int("k1", 123);
    EXPECT_TRUE(CmdOpt::is_set("k1"));
    EXPECT_EQ(123, opt.get_value());   
  }
 
  EXPECT_FALSE(CmdOpt::has_opt("k1"));
}

TEST(base_cmd_opt, opt_3)
{

  {
    opt<bool> opt("k1", false);
    EXPECT_STREQ("k1", opt.get_key().c_str());
    EXPECT_TRUE(CmdOpt::has_opt("k1"));
    EXPECT_FALSE(CmdOpt::is_set("k1"));
    EXPECT_FALSE(opt.get_value());  

    CmdOpt::set_opt_as_bool("k1", true);
    EXPECT_TRUE(CmdOpt::is_set("k1"));
    EXPECT_TRUE(opt.get_value());  
  }
 
  EXPECT_FALSE(CmdOpt::has_opt("k1"));
}

