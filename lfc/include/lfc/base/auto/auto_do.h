#ifndef __LFC_AUTO_DO_H__
#define __LFC_AUTO_DO_H__
#include "lfc/base/macro.h"

#define LFC_AUTO_DO(F)  lfc::auto_do_while_leave AUTO_NAME(AUTO)(F)

namespace lfc {

template<typename _F>
class auto_do_while_leave {
public:
  auto_do_while_leave(_F f): func(f){ };
  ~auto_do_while_leave(){
    func();
  }

private:
  _F func;

};

} // namespace lfc
#endif // __LFC_AUTO_DO_H__

