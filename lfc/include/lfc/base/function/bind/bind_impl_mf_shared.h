// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __BASE_funND_IMPL_MF_SHARED_H_Dec_20_2010__
#define __BASE_funND_IMPL_MF_SHARED_H_Dec_20_2010__

#include "lfc/base/function/bind/bind_impl_mf.h"
#include <memory>

namespace lfc {

  template<typename R,typename T >
  _fun::_bind_fwd<R, typename _fun::_ptr_wraper<R,T,std::shared_ptr<T>>>
  bind(R (T::*p) (),std::shared_ptr<T> st){
    assert(st != 0);
    typedef typename _fun::_ptr_wraper<R,T,std::shared_ptr<T>> wrapper_type;
    return _fun::_bind_fwd<R,wrapper_type>(wrapper_type(st,p));			
  }	

  template<typename R,typename T, _L_FUN_TN_B1 , _L_FUN_TN_A1>
  _fun::_bind_fwd<R, typename _fun::_ptr_wraper<R,T,std::shared_ptr<T>,_L_FUN_TYPE_B1>,_L_FUN_TYPE_A1>
  bind(R (T::*p) (_L_FUN_TYPE_B1),std::shared_ptr<T> st, _L_FUN_SIG_A1){
    assert(st != 0);
    typedef typename _fun::_ptr_wraper<R,T,std::shared_ptr<T>,_L_FUN_TYPE_B1> wrapper_type;
    return _fun::_bind_fwd<R,wrapper_type,_L_FUN_TYPE_A1>(wrapper_type(st,p),_L_FUN_INS_A1); 		
  }

  template<typename R,typename T, _L_FUN_TN_B2 , _L_FUN_TN_A2>
  _fun::_bind_fwd<R, typename _fun::_ptr_wraper<R,T,std::shared_ptr<T>,_L_FUN_TYPE_B2>,_L_FUN_TYPE_A2>
  bind(R (T::*p) (_L_FUN_TYPE_B2),std::shared_ptr<T> st, _L_FUN_SIG_A2){
    assert(st != 0);
    typedef typename _fun::_ptr_wraper<R,T,std::shared_ptr<T>,_L_FUN_TYPE_B2> wrapper_type;
    return _fun::_bind_fwd<R,wrapper_type,_L_FUN_TYPE_A2>(wrapper_type(st,p),_L_FUN_INS_A2); 		
  }

  template<typename R,typename T, _L_FUN_TN_B3 , _L_FUN_TN_A3>
  _fun::_bind_fwd<R, typename _fun::_ptr_wraper<R,T,std::shared_ptr<T>,_L_FUN_TYPE_B3>,_L_FUN_TYPE_A3>
  bind(R (T::*p) (_L_FUN_TYPE_B3),std::shared_ptr<T> st, _L_FUN_SIG_A3){
    assert(st != 0);
    typedef typename _fun::_ptr_wraper<R,T,std::shared_ptr<T>,_L_FUN_TYPE_B3> wrapper_type;
    return _fun::_bind_fwd<R,wrapper_type,_L_FUN_TYPE_A3>(wrapper_type(st,p),_L_FUN_INS_A3); 		
  }

  template<typename R,typename T, _L_FUN_TN_B4 , _L_FUN_TN_A4>
  _fun::_bind_fwd<R, typename _fun::_ptr_wraper<R,T,std::shared_ptr<T>,_L_FUN_TYPE_B4>,_L_FUN_TYPE_A4>
  bind(R (T::*p) (_L_FUN_TYPE_B4),std::shared_ptr<T> st, _L_FUN_SIG_A4){
    assert(st != 0);
    typedef typename _fun::_ptr_wraper<R,T,std::shared_ptr<T>,_L_FUN_TYPE_B4> wrapper_type;
    return _fun::_bind_fwd<R,wrapper_type,_L_FUN_TYPE_A4>(wrapper_type(st,p),_L_FUN_INS_A4); 		
  }

  template<typename R,typename T, _L_FUN_TN_B5 , _L_FUN_TN_A5>
  _fun::_bind_fwd<R, typename _fun::_ptr_wraper<R,T,std::shared_ptr<T>,_L_FUN_TYPE_B5>,_L_FUN_TYPE_A5>
  bind(R (T::*p) (_L_FUN_TYPE_B5),std::shared_ptr<T> st, _L_FUN_SIG_A5){
    assert(st != 0);
    typedef typename _fun::_ptr_wraper<R,T,std::shared_ptr<T>,_L_FUN_TYPE_B5> wrapper_type;
    return _fun::_bind_fwd<R,wrapper_type,_L_FUN_TYPE_A5>(wrapper_type(st,p),_L_FUN_INS_A5); 		
  }

  template<typename R,typename T, _L_FUN_TN_B6 , _L_FUN_TN_A6>
  _fun::_bind_fwd<R, typename _fun::_ptr_wraper<R,T,std::shared_ptr<T>,_L_FUN_TYPE_B6>,_L_FUN_TYPE_A6>
  bind(R (T::*p) (_L_FUN_TYPE_B6),std::shared_ptr<T> st, _L_FUN_SIG_A6){
    assert(st != 0);
    typedef typename _fun::_ptr_wraper<R,T,std::shared_ptr<T>,_L_FUN_TYPE_B6> wrapper_type;
    return _fun::_bind_fwd<R,wrapper_type,_L_FUN_TYPE_A6>(wrapper_type(st,p),_L_FUN_INS_A6); 		
  }

  template<typename R,typename T, _L_FUN_TN_B7 , _L_FUN_TN_A7>
  _fun::_bind_fwd<R, typename _fun::_ptr_wraper<R,T,std::shared_ptr<T>,_L_FUN_TYPE_B7>,_L_FUN_TYPE_A7>
  bind(R (T::*p) (_L_FUN_TYPE_B7),std::shared_ptr<T> st, _L_FUN_SIG_A7){
    assert(st != 0);
    typedef typename _fun::_ptr_wraper<R,T,std::shared_ptr<T>,_L_FUN_TYPE_B7> wrapper_type;
    return _fun::_bind_fwd<R,wrapper_type,_L_FUN_TYPE_A7>(wrapper_type(st,p),_L_FUN_INS_A7); 		
  }

  template<typename R,typename T, _L_FUN_TN_B8 , _L_FUN_TN_A8>
  _fun::_bind_fwd<R, typename _fun::_ptr_wraper<R,T,std::shared_ptr<T>,_L_FUN_TYPE_B8>,_L_FUN_TYPE_A8>
  bind(R (T::*p) (_L_FUN_TYPE_B8),std::shared_ptr<T> st, _L_FUN_SIG_A8){
    assert(st != 0);
    typedef typename _fun::_ptr_wraper<R,T,std::shared_ptr<T>,_L_FUN_TYPE_B8> wrapper_type;
    return _fun::_bind_fwd<R,wrapper_type,_L_FUN_TYPE_A8>(wrapper_type(st,p),_L_FUN_INS_A8); 		
  }

  template<typename R,typename T, _L_FUN_TN_B9 , _L_FUN_TN_A9>
  _fun::_bind_fwd<R, typename _fun::_ptr_wraper<R,T,std::shared_ptr<T>,_L_FUN_TYPE_B9>,_L_FUN_TYPE_A9>
  bind(R (T::*p) (_L_FUN_TYPE_B9),std::shared_ptr<T> st, _L_FUN_SIG_A9){
    assert(st != 0);
    typedef typename _fun::_ptr_wraper<R,T,std::shared_ptr<T>,_L_FUN_TYPE_B9> wrapper_type;
    return _fun::_bind_fwd<R,wrapper_type,_L_FUN_TYPE_A9>(wrapper_type(st,p),_L_FUN_INS_A9); 		
  }

}

#endif // __BASE_funND_IMPL_MF_SHARED_H_Dec_20_2010__

