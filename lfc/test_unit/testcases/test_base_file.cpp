#include "unitest_base.h"

using namespace std;
using namespace lfc;

TEST(base_file, FS_FILE_EXIST_1)
{
#ifdef __linux__
  EXPECT_EQ(false, FS_FILE_EXIST("abc.x"));
  EXPECT_EQ(true , FS_FILE_EXIST("data_base/base_string/string_util_get_char_type_1.txt"));
#endif
}

TEST(base_file, get_file_name_1)
{
#ifdef __linux__
  EXPECT_STREQ("abc.x", FS_FILE_NAME("abc.x").c_str());
  EXPECT_STREQ("abc.x", FS_FILE_NAME("p1/abc.x").c_str());
#endif
}

TEST(base_file, read_file_1)
{
  auto input_lines = OPEN_TXT_FILE_IGNORE_TAIL_BLANK("data_base/base_file/read_file_1.txt");
  EXPECT_EQ(2, input_lines.size());
  EXPECT_STREQ("-c -o hello.o test.c", input_lines[0].c_str());
}

void _test_simplify_path(const char* input, const char* expect, int expect_len){
  char output[1024] = {0};
  strcat(output, input);
  int out_len  = simplify_path(output);
  EXPECT_EQ(expect_len, out_len);
  if(expect != NULL){
    EXPECT_STREQ(expect, output);
  }
}

TEST(base_file, simplify_path_1)
{

  _test_simplify_path("", NULL, -1);
  _test_simplify_path("/abc/../", "/", 1);  
  _test_simplify_path("/a/./b/../../c/", "/c", 2);  
  _test_simplify_path("/////x", "/x", 2);  
  _test_simplify_path("/x//////y", "/x/y", 4);
  _test_simplify_path("/x/../y", "/y", 2);
  _test_simplify_path("/x/../../", "/", 1); 
  _test_simplify_path("/..", "/", 1); 
  _test_simplify_path("/a/./b///../c/../././../d/..//../e/./f/.\
/g/././//.//h///././/..///", "/e/f/g", 6); 
  _test_simplify_path("/x/../y\\ \\ ", "/y\\ \\ ", 6);
}

TEST(base_file, FS_RELATIVE_PATH_1)
{
  EXPECT_STREQ("", FS_RELATIVE_PATH("", "").c_str());
  EXPECT_STREQ("def", FS_RELATIVE_PATH("/abc", "/abc/def").c_str());
}

TEST(base_file, IS_ABS_PATH_1)
{
  EXPECT_TRUE(!FS_IS_ABS_PATH(""));

#if (defined _WIN32) || (defined _WIN64)
  EXPECT_TRUE(FS_IS_ABS_PATH("C:\\"));
#endif

#ifdef __linux__
  EXPECT_TRUE(FS_IS_ABS_PATH("/tmp"));
#endif

}


TEST(base_file, IS_FOLDER_EXIST_1)
{

#if (defined _WIN32) || (defined _WIN64)
  EXPECT_TRUE(FS_FOLDER_EXIST("C:\\"));
  EXPECT_TRUE(!FS_FOLDER_EXIST("C:\\not_exist"));
#endif

#ifdef __linux__
  EXPECT_TRUE(FS_FOLDER_EXIST("/tmp"));
  EXPECT_TRUE(!FS_FOLDER_EXIST("/not_exist"));
#endif

}

TEST(base_file, CUR_DIR_1)
{
  EXPECT_TRUE(FS_IS_ABS_PATH(FS_CUR_DIR));
  EXPECT_STREQ("test_unit", FS_FILE_NAME(FS_CUR_DIR).c_str());
}

TEST(base_file, DIR_SEPARATOR_1)
{
#if (defined _WIN32) || (defined _WIN64)
  EXPECT_STREQ("\\", FS_DIR_SEPARATOR.c_str());
#endif

#ifdef __linux__
  EXPECT_STREQ("/", FS_DIR_SEPARATOR.c_str());
#endif
}

TEST(base_file, FS_TO_VALID_PATH_1)
{
#ifdef __linux__
  EXPECT_TRUE(FS_IS_ABS_PATH(FS_TO_VALID_PATH("")));
  EXPECT_STREQ("", FS_FILE_NAME(FS_TO_VALID_PATH("")).c_str());
  EXPECT_STREQ("/xxx/", FS_TO_VALID_PATH("/xxx").c_str());
#endif
}