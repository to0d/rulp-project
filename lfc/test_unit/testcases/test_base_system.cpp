#include "unitest_base.h"
#include "lfc/base/system.h"

TEST(base_system, SYS_CPU_NUM_1)
{
  // EXPECT_EQ(4, lfc::system::get_cpu_number());
  EXPECT_TRUE(SYS_CPU_NUM >= 1);
}

TEST(base_system, SYS_TIME_1)
{
  EXPECT_TRUE(SYS_TIME > 0);
}

TEST(base_system, SYS_TYPE_1)
{

#if (defined _WIN32) || (defined _WIN64)
  EXPECT_TRUE(SYS_TYPE == lfc::OSType::Win);
#endif

#ifdef __linux__
  EXPECT_TRUE(SYS_TYPE == lfc::OSType::Linux);
  EXPECT_TRUE(SYS_IS_LINUX);
#endif

}

TEST(base_system, SYS_ENV_PATHS_1)
{
  auto paths = SYS_ENV_PATHS;
  EXPECT_TRUE(paths.size() > 0);

  for(auto path : paths){
    EXPECT_TRUE(FS_IS_ABS_PATH(path));
  }
}