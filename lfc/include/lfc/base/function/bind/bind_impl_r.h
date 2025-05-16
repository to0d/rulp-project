// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_BIND_IMPL_R_H_Dec_20_2010__
#define __LFC_BIND_IMPL_R_H_Dec_20_2010__

#include "lfc/base/function/bind/bind_fwd.h"

namespace lfc {

  template<typename F>
  _fun::_bind_fwd<typename F::result_type,F>
  bind(F& f){	
    typedef typename F::result_type R;
    return _fun::_bind_fwd<R,F>(f);
  }

  template<typename F,_L_FUN_TN_A1>
  _fun::_bind_fwd<typename F::result_type, F, _L_FUN_TYPE_A1>
  bind(F& f, _L_FUN_SIG_A1){	
    typedef typename F::result_type R;
    return _fun::_bind_fwd<R,F,_L_FUN_TYPE_A1>(f,_L_FUN_INS_A1);
  }

  template<typename F,_L_FUN_TN_A2>
  _fun::_bind_fwd<typename F::result_type,F,_L_FUN_TYPE_A2>
  bind(F& f, _L_FUN_SIG_A2){
    typedef typename F::result_type R;
    return _fun::_bind_fwd<R,F,_L_FUN_TYPE_A2>(f,_L_FUN_INS_A2);
  }

  template<typename F,_L_FUN_TN_A3>
  _fun::_bind_fwd<typename F::result_type,F,_L_FUN_TYPE_A3>
  bind(F& f, _L_FUN_SIG_A3){
    typedef typename F::result_type R;
    return _fun::_bind_fwd<R,F,_L_FUN_TYPE_A3>(f,_L_FUN_INS_A3);
  }

  template<typename F,_L_FUN_TN_A4>
  _fun::_bind_fwd<typename F::result_type,F,_L_FUN_TYPE_A4>
  bind(F& f, _L_FUN_SIG_A4){	
    typedef typename F::result_type R;
    return _fun::_bind_fwd<R,F,_L_FUN_TYPE_A4>(f,_L_FUN_INS_A4);
  }

  template<typename F,_L_FUN_TN_A5>
  _fun::_bind_fwd<typename F::result_type,F,_L_FUN_TYPE_A5>
  bind(F& f, _L_FUN_SIG_A5){
    typedef typename F::result_type R;
    return _fun::_bind_fwd<R,F,_L_FUN_TYPE_A5>(f,_L_FUN_INS_A5);
  }

  template<typename F,_L_FUN_TN_A6>
  _fun::_bind_fwd<typename F::result_type,F,_L_FUN_TYPE_A6>
  bind(F& f, _L_FUN_SIG_A6){
    typedef typename F::result_type R;
    return _fun::_bind_fwd<R,F,_L_FUN_TYPE_A6>(f,_L_FUN_INS_A6);
  }

  template<typename F,_L_FUN_TN_A7>
  _fun::_bind_fwd<typename F::result_type,F,_L_FUN_TYPE_A7>
  bind(F& f, _L_FUN_SIG_A7){
    typedef typename F::result_type R;
    return _fun::_bind_fwd<R,F,_L_FUN_TYPE_A7>(f,_L_FUN_INS_A7);
  }

  template<typename F,_L_FUN_TN_A8>
  _fun::_bind_fwd<typename F::result_type,F,_L_FUN_TYPE_A8>
  bind(F& f, _L_FUN_SIG_A8){
    typedef typename F::result_type R;
    return _fun::_bind_fwd<R,F,_L_FUN_TYPE_A8>(f,_L_FUN_INS_A8);
  }

  template<typename F,_L_FUN_TN_A9>
  _fun::_bind_fwd<typename F::result_type,F,_L_FUN_TYPE_A9>
  bind(F& f, _L_FUN_SIG_A9){
    typedef typename F::result_type R;
    return _fun::_bind_fwd<R,F,_L_FUN_TYPE_A9>(f,_L_FUN_INS_A9);
  }

} // namespace lfc

#endif // __LFC_BIND_IMPL_R_H_Dec_20_2010__
