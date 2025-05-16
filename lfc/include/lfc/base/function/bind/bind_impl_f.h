#ifndef __LFC_BIND_IMPL_F_H_Dec_20_2010__
#define __LFC_BIND_IMPL_F_H_Dec_20_2010__

#include "lfc/base/function/bind/bind_fwd.h"

#define __LFC_BIND_FWD_F_SIGNATURE_(_sig)  R (*) (_sig)
#define __LFC_BIND_FWD_F_DECLARE(_sig, _name)  R (*_name) (_sig)

namespace lfc {

  template<typename R>
  _fun::_bind_fwd<R,__LFC_BIND_FWD_F_SIGNATURE_(void)>
  bind(__LFC_BIND_FWD_F_DECLARE(void,f)){
    return _fun::_bind_fwd<R,__LFC_BIND_FWD_F_SIGNATURE_(void)>(f);
  }

  template<typename R, _L_FUN_TN_B1 , _L_FUN_TN_A1>
  _fun::_bind_fwd<R,__LFC_BIND_FWD_F_SIGNATURE_(_L_FUN_TYPE_B1),_L_FUN_TYPE_A1>
  bind(__LFC_BIND_FWD_F_DECLARE(_L_FUN_TYPE_B1,f), _L_FUN_SIG_A1){
    typedef __LFC_BIND_FWD_F_DECLARE(_L_FUN_TYPE_B1,F);
    return _fun::_bind_fwd<R,F,_L_FUN_TYPE_A1>(f,_L_FUN_INS_A1);
  }

  template<typename R, _L_FUN_TN_B2 , _L_FUN_TN_A2>
  _fun::_bind_fwd<R,__LFC_BIND_FWD_F_SIGNATURE_(_L_FUN_TYPE_B2),_L_FUN_TYPE_A2>
  bind(__LFC_BIND_FWD_F_DECLARE(_L_FUN_TYPE_B2,f), _L_FUN_SIG_A2){
    typedef __LFC_BIND_FWD_F_DECLARE(_L_FUN_TYPE_B2,F);
    return _fun::_bind_fwd<R,F,_L_FUN_TYPE_A2>(f,_L_FUN_INS_A2);
  }


  template<typename R, _L_FUN_TN_B3 , _L_FUN_TN_A3>
  _fun::_bind_fwd<R,__LFC_BIND_FWD_F_SIGNATURE_(_L_FUN_TYPE_B3),_L_FUN_TYPE_A3>
  bind(__LFC_BIND_FWD_F_DECLARE(_L_FUN_TYPE_B3,f), _L_FUN_SIG_A3){
    typedef __LFC_BIND_FWD_F_DECLARE(_L_FUN_TYPE_B3,F);
    return _fun::_bind_fwd<R,F,_L_FUN_TYPE_A3>(f,_L_FUN_INS_A3);
  }

  template<typename R, _L_FUN_TN_B4 , _L_FUN_TN_A4>
  _fun::_bind_fwd<R,__LFC_BIND_FWD_F_SIGNATURE_(_L_FUN_TYPE_B4),_L_FUN_TYPE_A4>
  bind(__LFC_BIND_FWD_F_DECLARE(_L_FUN_TYPE_B4,f), _L_FUN_SIG_A4){
    typedef __LFC_BIND_FWD_F_DECLARE(_L_FUN_TYPE_B4,F);
    return _fun::_bind_fwd<R,F,_L_FUN_TYPE_A4>(f,_L_FUN_INS_A4);
  }

  template<typename R, _L_FUN_TN_B5 , _L_FUN_TN_A5>
  _fun::_bind_fwd<R,__LFC_BIND_FWD_F_SIGNATURE_(_L_FUN_TYPE_B5),_L_FUN_TYPE_A5>
  bind(__LFC_BIND_FWD_F_DECLARE(_L_FUN_TYPE_B5,f), _L_FUN_SIG_A5){
    typedef __LFC_BIND_FWD_F_DECLARE(_L_FUN_TYPE_B5,F);
    return _fun::_bind_fwd<R,F,_L_FUN_TYPE_A5>(f,_L_FUN_INS_A5);
  }


  template<typename R, _L_FUN_TN_B6 , _L_FUN_TN_A6>
  _fun::_bind_fwd<R,__LFC_BIND_FWD_F_SIGNATURE_(_L_FUN_TYPE_B6),_L_FUN_TYPE_A6>
  bind(__LFC_BIND_FWD_F_DECLARE(_L_FUN_TYPE_B6,f), _L_FUN_SIG_A6){
    typedef __LFC_BIND_FWD_F_DECLARE(_L_FUN_TYPE_B6,F);
    return _fun::_bind_fwd<R,F,_L_FUN_TYPE_A6>(f,_L_FUN_INS_A6);
  }

  template<typename R, _L_FUN_TN_B7 , _L_FUN_TN_A7>
  _fun::_bind_fwd<R,__LFC_BIND_FWD_F_SIGNATURE_(_L_FUN_TYPE_B7),_L_FUN_TYPE_A7>
  bind(__LFC_BIND_FWD_F_DECLARE(_L_FUN_TYPE_B7,f), _L_FUN_SIG_A7){
    typedef __LFC_BIND_FWD_F_DECLARE(_L_FUN_TYPE_B7,F);
    return _fun::_bind_fwd<R,F,_L_FUN_TYPE_A7>(f,_L_FUN_INS_A7);
  }

  template<typename R, _L_FUN_TN_B8 , _L_FUN_TN_A8>
  _fun::_bind_fwd<R,__LFC_BIND_FWD_F_SIGNATURE_(_L_FUN_TYPE_B8),_L_FUN_TYPE_A8>
  bind(__LFC_BIND_FWD_F_DECLARE(_L_FUN_TYPE_B8,f), _L_FUN_SIG_A8){
    typedef __LFC_BIND_FWD_F_DECLARE(_L_FUN_TYPE_B8,F);
    return _fun::_bind_fwd<R,F,_L_FUN_TYPE_A8>(f,_L_FUN_INS_A8);
  }


  template<typename R, _L_FUN_TN_B9 , _L_FUN_TN_A9>
  _fun::_bind_fwd<R,__LFC_BIND_FWD_F_SIGNATURE_(_L_FUN_TYPE_B9),_L_FUN_TYPE_A9>
  bind(__LFC_BIND_FWD_F_DECLARE(_L_FUN_TYPE_B9,f), _L_FUN_SIG_A9){
    typedef __LFC_BIND_FWD_F_DECLARE(_L_FUN_TYPE_B9,F);
    return _fun::_bind_fwd<R,F,_L_FUN_TYPE_A9>(f,_L_FUN_INS_A9);
  }
}

#endif // __LFC_BIND_IMPL_F_H_Dec_20_2010__

