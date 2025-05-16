#include "lfc/base/function.h"
#include "runtime/XRInterpreter.h"
#include <string>

void _test(std::string input_test_file, lfc::function<std::string(std::string)> func);

namespace lfc {

class RulpTestBase;
typedef lfc::function<std::string, RulpTestBase*, std::string> test_action;

class RulpTestBase {

public:
  RulpTestBase();

  ~RulpTestBase();

  IRInterpreter*  getInterpreter();
  IRParser*       getParser();
  
  void run_script(StrConstRef inputScriptPath);
  void run_action(StrConstRef inputPath, test_action action);

protected:

  bool run_stmt( StrConstRef inputStmt
               , bool expectError
               , StrConstRef expectResult
               , StrConstRef expectErrorMessage
               , const std::vector<std::string>& inLines
               , std::vector<std::string>& outLines
               , IRInterpreter* interpreter
               );


protected:

  std::stringstream _out;
  
  IRInterpreter*  interpreter = NULL; 

};

void run_rulp_script(StrConstRef inputScriptPath, lfc::function<void(IRInterpreter*)> init_func = nullptr);
  

} // namespace lfc