#include "unitest_base.h"
#include "lfc/base/cmd/arg.h"

using namespace lfc;

static std::string _process_cmd(std::string line){
  auto args = STR_SPLIT_BY_CHAR(line, ' ');
  return lfc::to_string(lfc::process_cmd(args));
}

static void _test_process_cmd(std::string input_path, std::string output_path){
  auto input_lines = OPEN_TXT_FILE_IGNORE_TAIL_BLANK(input_path);
  std::vector<std::string> output_lines;

  for(std::string line : input_lines){
    line = str_trim(line);
    if(line.empty())
      continue;
    if(!str_start_With(line, "#")){
      output_lines.push_back("in : " + line);
      auto out = _process_cmd(line);
      output_lines.push_back("out: " + out);
      output_lines.push_back("");
    }
  }

  test_lines(output_lines, output_path);
}

TEST(base_cmd_arg, process_cmd_1)
{
  _test_process_cmd( "data_base/base_cmd/process_cmd_1_in.txt", "data_base/base_cmd/process_cmd_1_out.txt");
}

TEST(base_cmd_arg, process_cmd_2)
{
  // scc hello.c -lstdc++ -lscc
  EXPECT_STREQ("CMD(name=scc, type=COMPILE, option_list={CO(type=SCCTRACE, key=t, value=),CO(type=UNKNOWN, key=dump-dfg-simd, value=),CO(type=UNKNOWN, key=-simplify-dfg-dot, value=)}, para_list={test_1.ll})", _process_cmd(
               "-c test_1.ll -t -dump-dfg-simd --simplify-dfg-dot"
               ).c_str());
}

static void _test_format_scc_para_list(std::string input_path, std::string output_path){
  auto input_lines = OPEN_TXT_FILE_IGNORE_TAIL_BLANK(input_path);
  std::vector<std::string> output_lines;

  for(std::string line : input_lines){
    line = str_trim(line);
    if(line.empty())
      continue;
    if(!str_start_With(line, "#")){
      auto args = STR_SPLIT_BY_CHAR(line, ' ');
      output_lines.push_back("in : " + line);
      auto out = lfc::format_scc_para_list(lfc::process_cmd(args));
      output_lines.push_back("out: " + out);
      output_lines.push_back("");
    }
  }

  test_lines(output_lines, output_path);
}

TEST(base_cmd_arg, format_scc_para_list_1)
{
  _test_format_scc_para_list( "data_base/base_cmd/format_para_list_1_in.txt", "data_base/base_cmd/format_para_list_1_out.txt");
}

TEST(base_cmd_arg, format_scc_para_list_2)
{
  // scc -trans input.c -o output.c
  EXPECT_STREQ("--sctrans -para input.c -o output.c", 
  lfc::format_scc_para_list(lfc::process_cmd({"-trans", "input.c", "-o", "output.c"})).c_str());
}


