#include "unitest_base.h"
#include "lfc/base/string/util.h"
#include "lfc/base/auto/auto_do.h"
#include "lfc/base/string/format.h"
#include "rulp/utils/RulpFactory.h"
#include "rulp/utils/RulpUtil.h"
#include "rulp/utils/RuntimeUtil.h"
#include "rulp/lang/RException.h"
#include "help_test.h"
#include "unitest_rulp.h"

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

namespace lfc {

RulpTestBase::RulpTestBase(){
  RulpUtil::reset();
}

RulpTestBase::~RulpTestBase(){
  RULP_FREE(interpreter);
}

IRInterpreter* RulpTestBase::getInterpreter(){
  if (interpreter == null) {
    interpreter = RulpFactory::createInterpreter();
    interpreter->setOutput([&](auto line){
      _out << line;
    });
  }

  return interpreter;
}

IRParser* RulpTestBase::getParser(){
  return getInterpreter()->getParser();
}

#define KEY_COMMENT   ";;;"
#define KEY_RESULT    ";=>"
#define KEY_EOF       ";eof"
#define KEY_ERR       ";err"
#define KEY_ERR2      ";err:"
#define KEY_IN        ";in:"
#define KEY_OUT       ";out:"

#define IT_PRE_ERR    "ERR: "
#define V_SCRIPT_PATH "?script-path"

bool RulpTestBase::run_stmt(
    StrConstRef inputStmt
  , bool expectError
  , StrConstRef expectResult
  , StrConstRef expectErrorMessage
  , const std::vector<std::string>& inLines
  , std::vector<std::string>& outLines
  , IRInterpreter* interpreter
  )
{
  RListHandler rsultList;

  // init output
  _out.str("");

  // init input
  RInput oldIn = nullptr;
  int input_idx = 0;

  LFC_AUTO_DO([&](){
    if (oldIn != null) {
      interpreter->setInput(oldIn);
    }
  });

  try {

    if (!inLines.empty()) {

      oldIn = interpreter->getInput();

      interpreter->setInput([&](){

        if (input_idx >= inLines.size()) {
          throw RExceptionEOF();
        }

        auto line = inLines[input_idx++];
        _out << line;
        _out << "\n";

        return line;
      });
    }

    outLines.push_back(inputStmt);
    if (!inLines.empty()) {
      outLines.push_back(KEY_IN);
      for (auto inLine : inLines) {
        outLines.push_back(inLine);
      }
      outLines.push_back(KEY_EOF);
    }

    rsultList = RuntimeUtil::compute(interpreter, inputStmt);
    // std::cout << "inputStmt: " << inputStmt << "\n";

    auto result = RulpUtil::toString(rsultList.results);
    outLines.push_back(KEY_RESULT + result);

    auto output = _out.str();
    _out.str("");
    if (!output.empty()) {
      outLines.push_back(KEY_OUT);
      outLines.push_back(output);
      outLines.push_back(KEY_EOF);
    }

    outLines.push_back("");

    if (!expectResult.empty() && result != expectResult) {
      return false;
    }

    if (expectError) {
      return false;
    }

  } 
  catch (RException& e) {

    outLines.push_back(KEY_ERR2);
    outLines.push_back(e.getMessage());
    outLines.push_back(KEY_EOF);
    outLines.push_back("");

    if (!expectError) {
      // e.printStackTrace();
      return false;
    }

    if (!expectErrorMessage.empty() && expectErrorMessage != e.getMessage()) {
      // e.printStackTrace();
      return false;
    }

  }
  catch (const std::runtime_error& e) {
    std::string msg = "runtime_error:";
    msg += e.what();
    std::cerr << msg;

    outLines.push_back(KEY_ERR2);
    outLines.push_back(msg);
    outLines.push_back(KEY_EOF);
    outLines.push_back("");

    if (!expectError) {
      // e.printStackTrace();
      return false;
    }

    if (!expectErrorMessage.empty() &&  expectErrorMessage != msg) {
      // e.printStackTrace();
      return false;
    }
  }
  catch (const std::exception& e) {
    std::string msg = "exception:";
    msg += e.what();
    std::cerr << msg;

    outLines.push_back(KEY_ERR2);
    outLines.push_back(msg);
    outLines.push_back(KEY_EOF);
    outLines.push_back("");

    if (!expectError) {
      // e.printStackTrace();
      return false;
    }

    if (!expectErrorMessage.empty() &&  expectErrorMessage != msg) {
      // e.printStackTrace();
      return false;
    }
  }

  // catch (...) {

  //   // // e.printStackTrace();

  //   // outLines.push_back(KEY_ERR2);
  //   // outLines.apush_backdd(e.toString());
  //   // outLines.push_back(KEY_EOF);
  //   // outLines.push_back("");

  //   // if (expectError != null && !expectError) {
  //   //   // e.printStackTrace();
  //   //   return false;
  //   // }

  //   // if (expectErrorMessage != null && !expectErrorMessage.equals(e.toString())) {
  //   //   // e.printStackTrace();
  //   //   return false;
  //   // }

  //   // assert(false);

  //   return false;
  // }

  return true;
}

void run_rulp_script(StrConstRef inputScriptPath, lfc::function<void(IRInterpreter*)> init_func){
  {
    std::string path = inputScriptPath + ".ginfo.txt";
    lfc::RulpUtil::reset();
    std::string info;

    {
      RulpTestBase test;
      auto interpreter = test.getInterpreter();
      if(init_func != nullptr){
        init_func(interpreter);
      }

      test.run_script(inputScriptPath);
      info += TraceUtil::printInterpreterInfo(interpreter);

      info += "\n\n";
    }

    info += TraceUtil::printGlobalInfo();
    SAVE_TXT_FILE(path, {info});
  }

  int diff = 0;
  
  for(auto& type : RRType::get_all_rtypes()){
    
    if(type->getCreateCount() != type->getDeleteCount()){
      std::cout << inputScriptPath 
                << ": type=" << TO_STR(type) 
                << ", create=" << type->getCreateCount()
                << ", delete=" << type->getDeleteCount()
                << "\n";
      ++diff;
    }    
  }

  assert(diff == 0);
}

void RulpTestBase::run_script(StrConstRef inputScriptPath){

  try {

    auto lines = OPEN_TXT_FILE(inputScriptPath);
    std::vector<std::string> inLines, outLines;
    bool rc = true;
    std::string sb;

    int size = lines.size();
    int index = 0;
    std::string inputStmt;
    auto interpreter = getInterpreter();

      // LoadUtil.loadScript(interpreter, interpreter.getMainFrame(), "test/itest", "utf-8");
    RulpUtil::setLocalVar(MAIN_FRAME(interpreter), V_SCRIPT_PATH, RulpFactory::createString(inputScriptPath));
    RulpUtil::addPathVar(MAIN_FRAME(interpreter),"load");

    for (; rc && index < size; ++index) {

       auto line = lines[index];

      if (str_trim(line) == KEY_COMMENT) {// ;;;
        inputStmt = sb;
        sb = "";
        rc = run_stmt(inputStmt, false, "", "", inLines, outLines, interpreter);
        inLines.clear();

      } 
      else if (str_start_With(line, KEY_RESULT)) {// ;=>
        inputStmt = sb;
        sb = "";
        auto expectResult = line.substr(3);
        if (str_trim(expectResult).empty()) {
          expectResult = "";
        }

        rc = run_stmt(inputStmt, false, expectResult, "", inLines, outLines, interpreter);
        inLines.clear();

      } 
      else if (str_trim(line) == KEY_ERR) {// ;err

        inputStmt = sb;
        sb = "";

        rc = run_stmt(inputStmt, true, "", "", inLines, outLines, interpreter);
        inLines.clear();

      }
      else if (str_trim(line) == KEY_ERR2) {// ;err:

        inputStmt = sb;
        sb = "";

        std::string expectSb;

        while (++index < size) {

          auto nextLine = lines[index];
          if(str_trim(nextLine) == KEY_EOF){
            break;
          }

          if(expectSb.length() > 0) {
            expectSb += '\n';
          }
          expectSb += nextLine;
        }

        rc = run_stmt(inputStmt, true, "", expectSb, inLines, outLines, interpreter);
        inLines.clear();

      } 
      else if (str_trim(line) == KEY_IN) {// ;in:

        while (++index < size) {
          auto nextLine = lines[index];
          if(str_trim(nextLine) == KEY_EOF){
            break;
          }
          inLines.push_back(nextLine);
        }

      } 
      else {

        if(sb.length() != 0) {
          sb += '\n';
        }

        sb += line;
      }
    }

    if (rc && sb.length() != 0) {
      inputStmt = sb;
      sb = "";
      rc = run_stmt(inputStmt, false, "", "", inLines, outLines, interpreter);
      inLines.clear();
    }

    SAVE_TXT_FILE(inputScriptPath + ".output", outLines);

    if (!rc) {
      std::string msg =  LFC_STR_FORMAT_BGN "error found in line: %d, file=%s", index, inputScriptPath.c_str() LFC_STR_FORMAT_END;
      std::cerr << msg << std::endl;
      EXPECT_TRUE(rc);
    }

  } 
  catch (std::runtime_error& e) {
    std::cerr << "runtime_error:" << e.what() << std::endl;
    EXPECT_TRUE(false);
  }
  catch (std::exception& e) {
    std::cerr << "exception:" << e.what() << std::endl;
    EXPECT_TRUE(false);
  }
  catch (RException & e) {
    std::cerr << "exception:" << e.what() << std::endl;
    EXPECT_TRUE(false);
  }
  catch (...) {
    std::string msg = LFC_STR_FORMAT_BGN "Unknown exception occurred, file=%s", inputScriptPath.c_str() LFC_STR_FORMAT_END;
    std::cerr << msg << "\n";
    EXPECT_TRUE(false);
  }
}

void RulpTestBase::run_action(StrConstRef inputPath, test_action action){

  std::vector<std::string> outLines;

  try{
    
    auto lines = OPEN_TXT_FILE(inputPath);
    
    std::string multiBuf;
    int multiIndex = -1;

    for (int index = 0; index < lines.size(); ++index) {

      auto line = lines[index];
      if (str_trim(line).empty() || str_start_With(line, ";")) {
        continue;
      }    

      if (str_start_With(line, IT_PRE_INP)) {

        if (multiIndex != -1) {
          throw std::runtime_error("multi line not end: " + TO_STR(multiIndex));
        }

        std::string input = line.substr(strlen(IT_PRE_INP));
        std::string output = "";

        try {
          output =  IT_PRE_OUT;
          output += action(this, input);
        } 
        catch (RException& e) {
          output = IT_PRE_ERR;
          output += e.what();
        }

        outLines.push_back(output);
      }      
      else if (str_start_With(line, IT_PRE_BGN)) {

        if (multiIndex != -1) {
          throw std::runtime_error("duplicated multi line: " + TO_STR(index));
        }

        multiBuf += line.substr(strlen(IT_PRE_BGN));
        multiIndex = index;

      } 
      else if (str_trim(line) == IT_PRE_EOF) {

        if (multiIndex == -1) {
          throw std::runtime_error("multi line not begin: " + TO_STR(index));
        }

        std::string input = multiBuf;
        std::string output = "";

        try {
          output  = IT_PRE_OUT;
          output += action(this, input);
        } 
        catch (RException& e) {
          output = IT_PRE_ERR;
          output += e.what();
        }

        outLines.push_back(output);
        multiBuf = "";
        multiIndex = -1;

      } 
      else if (multiIndex != -1) {

        multiBuf += '\n';
        multiBuf += line;

      } 
      else {
        throw std::runtime_error("Invalid input line: " + line);
      }
    }

    if (multiIndex != -1) {
      throw std::runtime_error("multi line not end: " + TO_STR(multiIndex));
    }

    SAVE_TXT_FILE(inputPath + ".output", outLines);
  } 
  catch (std::runtime_error& e) {
    std::cerr << e.what() << "\n";
    EXPECT_TRUE(false);
  }
}


} // namespace lfc