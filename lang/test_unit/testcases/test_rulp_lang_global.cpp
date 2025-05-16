#include "rulp/lang/RGlobal.h"
#include "lfc/base/string/util.h"
#include "unitest_base.h"

using namespace std;
using namespace lfc;

#define TEST_GLOBAL_OBJ(obj, str) \
  EXPECT_TRUE((obj) != NULL); \
  EXPECT_TRUE(IS_GLOBAL_OBJECT(obj)); \
  EXPECT_STREQ(str, lfc::to_string(obj).c_str());


TEST(rulp_lang_global, global_objects_1)
{
  test_lines(RGlobal::get_global_object_all_atoms(), "data/rulp_lang_global/global_objects_1.txt");
}

TEST(rulp_lang_global, global_objects_2)
{
  std::vector<IRObject*> global_objects = {
      O_EMPTY_LIST   
    , O_EMPTY_EXPR   
    , O_False          
    , O_True         
    , O_INT_0        
    , O_INT_OF(128)  
    , O_INT_OF(-127) 
    , O_LONG_0       
    , O_LONG_OF(128) 
    , O_LONG_OF(-127)
    , O_FLOAT_0      
    , O_DOUBLE_0         
    };

  test_lines(global_objects, "data/rulp_lang_global/global_objects_2.txt");
}

