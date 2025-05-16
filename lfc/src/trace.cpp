#include "lfc/base/trace.h"

namespace lfc {

bool global_trace = false;

void set_global_trace(bool trace){
  global_trace = trace;
}

bool get_global_trace(){
  return global_trace;
}

} // namespace lfc 


