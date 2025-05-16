#include "unitest_base.h"
#include "lfc/base/string/util.h"
#include "help_test.h"

#define IT_PRE_INP        "INP: "
#define IT_PRE_INP_LEN    5
#define IT_PRE_BGN        "BGN: "
#define IT_PRE_BGN_LEN    5
#define IT_PRE_EOF        "EOF"
#define IT_PRE_OUT        "OUT: "

using namespace std;
using namespace lfc;

void _test(std::string input_test_file, lfc::function<std::string(std::string)> func){ 
  
  EXPECT_TRUE(FS_FILE_EXIST(input_test_file));

  auto lines = OPEN_TXT_FILE(input_test_file);
  std::vector<string> outputs;
  
  int multiIndex = -1;
  std::string multiBuf;
  
  for (int index = 0; index < lines.size(); ++index) {

    auto line = lines[index];
    if (str_trim(line).empty() || str_start_With(line, ";")) {
      continue;
    }

    outputs.push_back(line);

    if (str_start_With(line, IT_PRE_INP)) {

      if (multiIndex != -1) {
        std::cout << "multiIndex=" << multiIndex << "\n";
        assert(false && "multi line not end");
      }

      auto input = line.substr(IT_PRE_INP_LEN);
      std::string output = IT_PRE_OUT;
      output += func(input);
      outputs.push_back(output);

    } 
    else if (str_start_With(line, IT_PRE_BGN)) {

      if (multiIndex != -1) {
        std::cout << "multiIndex=" << multiIndex << "\n";
        assert(false && "duplicated multi line");
      }

      multiBuf += line.substr(IT_PRE_BGN_LEN);
      multiIndex = index;

    } 
    else if (str_trim(line) == IT_PRE_EOF) {

      if(multiIndex == -1) {
        std::cout << "multiIndex=" << multiIndex << "\n";
        assert(false && "multi line not begin");
      }

      std::string output = IT_PRE_OUT;
      output += func(multiBuf);
      outputs.push_back(output);

      multiBuf = "";
      multiIndex = -1;

    } 
    else if (multiIndex != -1) {

      multiBuf += '\n';
      multiBuf  += line;

    } 
    else {

      std::cout << "line=" << line << "\n";
      assert(false && "Invalid input line");
    }
  
  }

  std::string output_test_file = input_test_file + ".output";
  test_lines(outputs, output_test_file);
}
