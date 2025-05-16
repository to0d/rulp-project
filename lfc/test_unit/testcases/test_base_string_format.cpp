#include "unitest_base.h"
#include "lfc/base/string/format.h"
#include "lfc/base/function.h"
#include "help_test.h"

using namespace std;
using namespace lfc;

TEST(base_string_format, LFC_STR_FORMAT_1)
{
  EXPECT_STREQ( "       RType:       Create       Delete        Exist"
              , (LFC_STR_FORMAT_BGN "%12s: %12s %12s %12s", "RType", "Create", "Delete", "Exist" LFC_STR_FORMAT_END).c_str());

  EXPECT_STREQ( "TEST010HELL"
              , (LFC_STR_FORMAT_BGN "TEST%03dHELL", 10 LFC_STR_FORMAT_END).c_str());

}