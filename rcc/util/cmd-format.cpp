#define LFC_TRACE_STREAM   std::cout
#include "lfc/base/cmd/arg.h"
#include "lfc/base/trace.h"
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace lfc;
using namespace std;

void show_version();
void show_usage();

#define OPT_TRACE "-t"

// -------------------------------------------------------------------------
//     M A I N
// -------------------------------------------------------------------------

int main(int argc, const char* argv[]) {

  std::vector<std::string> args;
  for(int i=1; i < argc; ++i){
    args.push_back(argv[i]);
  }

  CmdAction CA = lfc::process_cmd(args);
  std::string line = lfc::format_scc_para_list(CA);
  std::cout << line;
  return 0;  
}

namespace lfc {

bool global_trace = false;

void set_global_trace(bool trace){
  global_trace = trace;
}

bool get_global_trace(){
  return global_trace;
}

} // namespace lfc 
