#ifndef __LFC_BIND_IMPL_MF_H_Dec_20_2010__
#define __LFC_BIND_IMPL_MF_H_Dec_20_2010__

#include "lfc/base/function/bind/bind_fwd.h"
#include "lfc/base/function/bind/bind_impl_r.h"

namespace lfc {

#define _L_FUN_PTR_WRAPER_TYPE(_TN) \
  typedef _ptr_wraper<R,T,T_ptr ,_TN> this_type;\
  typedef R (T::* Pm)(_TN);

#define _L_FUN_PTR_WRAPER_DEC \
public: \
  typedef R result_type;\
  _ptr_wraper(T_ptr st,Pm _p) : m_st(st),m_p(_p){}\
  virtual ~_ptr_wraper(){};\
  _ptr_wraper(this_type& other)\
  {\
  m_st = other.m_st;\
  m_p = other.m_p;\
}\
  this_type& operator = (const this_type& other)\
  {\
  m_st = other.m_st;\
  m_p = other.m_p;\
  return *this;\
}\
protected:\
  T_ptr		m_st;\
  Pm			m_p;

#define	_L_FUN_PTR_WRAPER_OP(_SIG,_INS) \
public:\
  R operator()(_SIG)\
  {	return ((*m_st).*m_p)(_INS);}


  namespace _fun{

    template<typename R,typename T ,typename T_ptr = T* , _L_FUN_TN_B9_VOID>
    class _ptr_wraper{
      typedef _ptr_wraper<R,T,T_ptr ,_L_FUN_TYPE_B9> this_type;
      typedef R (T::* Pm)(_L_FUN_TYPE_B9);	

      _L_FUN_PTR_WRAPER_DEC;
      _L_FUN_PTR_WRAPER_OP(_L_FUN_SIG_B9,_L_FUN_INS_B9);
    };

    template<typename R,typename T ,typename T_ptr>
    class _ptr_wraper<R,T,T_ptr>{
      typedef _ptr_wraper<R,T,T_ptr> this_type;
      typedef R (T::* Pm)();	

    public:
      R operator()(){	
        return ((*m_st).*m_p)();
      }

      _L_FUN_PTR_WRAPER_DEC;
    };

    template<typename R, typename T, typename T_ptr, _L_FUN_TN_B1>
    class _ptr_wraper<R,T,T_ptr,_L_FUN_TYPE_B1>{
      _L_FUN_PTR_WRAPER_TYPE(_L_FUN_TYPE_B1);
      _L_FUN_PTR_WRAPER_DEC;
      _L_FUN_PTR_WRAPER_OP(_L_FUN_SIG_B1,_L_FUN_INS_B1);
    };

    template<typename R, typename T, typename T_ptr, _L_FUN_TN_B2>
    class _ptr_wraper<R,T,T_ptr,_L_FUN_TYPE_B2>{
      _L_FUN_PTR_WRAPER_TYPE(_L_FUN_TYPE_B2);
      _L_FUN_PTR_WRAPER_DEC;
      _L_FUN_PTR_WRAPER_OP(_L_FUN_SIG_B2,_L_FUN_INS_B2);
    };

    template<typename R,typename T ,typename T_ptr,_L_FUN_TN_B3>
    class _ptr_wraper<R,T,T_ptr,_L_FUN_TYPE_B3>{
      _L_FUN_PTR_WRAPER_TYPE(_L_FUN_TYPE_B3);
      _L_FUN_PTR_WRAPER_DEC;
      _L_FUN_PTR_WRAPER_OP(_L_FUN_SIG_B3,_L_FUN_INS_B3);
    };

    template<typename R,typename T ,typename T_ptr,_L_FUN_TN_B4>
    class _ptr_wraper<R,T,T_ptr,_L_FUN_TYPE_B4>{
      _L_FUN_PTR_WRAPER_TYPE(_L_FUN_TYPE_B4);
      _L_FUN_PTR_WRAPER_DEC;
      _L_FUN_PTR_WRAPER_OP(_L_FUN_SIG_B4,_L_FUN_INS_B4);
    };

    template<typename R,typename T ,typename T_ptr,_L_FUN_TN_B5>
    class _ptr_wraper<R,T,T_ptr,_L_FUN_TYPE_B5>{
      _L_FUN_PTR_WRAPER_TYPE(_L_FUN_TYPE_B5);
      _L_FUN_PTR_WRAPER_DEC;
      _L_FUN_PTR_WRAPER_OP(_L_FUN_SIG_B5,_L_FUN_INS_B5);
    };

    template<typename R,typename T ,typename T_ptr,_L_FUN_TN_B6>
    class _ptr_wraper<R,T,T_ptr,_L_FUN_TYPE_B6>{
      _L_FUN_PTR_WRAPER_TYPE(_L_FUN_TYPE_B6);
      _L_FUN_PTR_WRAPER_DEC;
      _L_FUN_PTR_WRAPER_OP(_L_FUN_SIG_B6,_L_FUN_INS_B6);
    };

    template<typename R,typename T ,typename T_ptr,_L_FUN_TN_B7>
    class _ptr_wraper<R,T,T_ptr,_L_FUN_TYPE_B7>{
      _L_FUN_PTR_WRAPER_TYPE(_L_FUN_TYPE_B7);
      _L_FUN_PTR_WRAPER_DEC;
      _L_FUN_PTR_WRAPER_OP(_L_FUN_SIG_B7,_L_FUN_INS_B7);
    };

    template<typename R,typename T ,typename T_ptr,_L_FUN_TN_B8>
    class _ptr_wraper<R,T,T_ptr,_L_FUN_TYPE_B8>{
      _L_FUN_PTR_WRAPER_TYPE(_L_FUN_TYPE_B8);
      _L_FUN_PTR_WRAPER_DEC;
      _L_FUN_PTR_WRAPER_OP(_L_FUN_SIG_B8,_L_FUN_INS_B8);
    };

  } // namespace _fun

  template<typename R,typename T >
  _fun::_bind_fwd<R, typename _fun::_ptr_wraper<R,T,T*>> 
  bind(R (T::*p) (),T* st){
    assert(st != 0);
    typedef typename _fun::_ptr_wraper<R,T,T*> wrapper_type;
    return _fun::_bind_fwd<R,wrapper_type>(wrapper_type(st,p));			
  }	

  template<typename R,typename T, _L_FUN_TN_B1 , _L_FUN_TN_A1>
  _fun::_bind_fwd<R, typename _fun::_ptr_wraper<R,T,T*,_L_FUN_TYPE_B1>,_L_FUN_TYPE_A1>
  bind(R (T::*p) (_L_FUN_TYPE_B1),T* st, _L_FUN_SIG_A1){
    assert(st != 0);
    typedef typename _fun::_ptr_wraper<R,T,T*,_L_FUN_TYPE_B1> wrapper_type;
    return _fun::_bind_fwd<R,wrapper_type,_L_FUN_TYPE_A1>(wrapper_type(st,p),_L_FUN_INS_A1);
  }

  template<typename R,typename T, _L_FUN_TN_B2 , _L_FUN_TN_A2>
  _fun::_bind_fwd<R, typename _fun::_ptr_wraper<R,T,T*,_L_FUN_TYPE_B2>,_L_FUN_TYPE_A2>
  bind(R (T::*p) (_L_FUN_TYPE_B2),T* st, _L_FUN_SIG_A2){
    assert(st != 0);
    typedef typename _fun::_ptr_wraper<R,T,T*,_L_FUN_TYPE_B2> wrapper_type;
    return _fun::_bind_fwd<R,wrapper_type,_L_FUN_TYPE_A2>(wrapper_type(st,p),_L_FUN_INS_A2); 		
  }

  template<typename R,typename T, _L_FUN_TN_B3 , _L_FUN_TN_A3>
  _fun::_bind_fwd<R, typename _fun::_ptr_wraper<R,T,T*,_L_FUN_TYPE_B3>,_L_FUN_TYPE_A3>
  bind(R (T::*p) (_L_FUN_TYPE_B3),T* st, _L_FUN_SIG_A3){
    assert(st != 0);
    typedef typename _fun::_ptr_wraper<R,T,T*,_L_FUN_TYPE_B3> wrapper_type;
    return  _fun::_bind_fwd<R,wrapper_type,_L_FUN_TYPE_A3>(wrapper_type(st,p),_L_FUN_INS_A3); 		
  }

  template<typename R,typename T, _L_FUN_TN_B4 , _L_FUN_TN_A4>
  _fun::_bind_fwd<R, typename _fun::_ptr_wraper<R,T,T*,_L_FUN_TYPE_B4>,_L_FUN_TYPE_A4>
  bind(R (T::*p) (_L_FUN_TYPE_B4),T* st, _L_FUN_SIG_A4){
    assert(st != 0);
    typedef typename _fun::_ptr_wraper<R,T,T*,_L_FUN_TYPE_B4> wrapper_type;
    return _fun::_bind_fwd<R,wrapper_type,_L_FUN_TYPE_A4>(wrapper_type(st,p),_L_FUN_INS_A4); 		
  }

  template<typename R,typename T, _L_FUN_TN_B5 , _L_FUN_TN_A5>
  _fun::_bind_fwd<R, typename _fun::_ptr_wraper<R,T,T*,_L_FUN_TYPE_B5>,_L_FUN_TYPE_A5>
  bind(R (T::*p) (_L_FUN_TYPE_B5),T* st, _L_FUN_SIG_A5){
    assert(st != 0);
    typedef typename _fun::_ptr_wraper<R,T,T*,_L_FUN_TYPE_B5> wrapper_type;
    return _fun::_bind_fwd<R,wrapper_type,_L_FUN_TYPE_A5>(wrapper_type(st,p),_L_FUN_INS_A5); 		
  }

  template<typename R,typename T, _L_FUN_TN_B6 , _L_FUN_TN_A6>
  _fun::_bind_fwd<R, typename _fun::_ptr_wraper<R,T,T*,_L_FUN_TYPE_B6>,_L_FUN_TYPE_A6>
  bind(R (T::*p) (_L_FUN_TYPE_B6),T* st, _L_FUN_SIG_A6){
    assert(st != 0);
    typedef typename _fun::_ptr_wraper<R,T,T*,_L_FUN_TYPE_B6> wrapper_type;
    return _fun::_bind_fwd<R,wrapper_type,_L_FUN_TYPE_A6>(wrapper_type(st,p),_L_FUN_INS_A6); 		
  }

  template<typename R,typename T, _L_FUN_TN_B7 , _L_FUN_TN_A7>
  _fun::_bind_fwd<R, typename _fun::_ptr_wraper<R,T,T*,_L_FUN_TYPE_B7>,_L_FUN_TYPE_A7>
  bind(R (T::*p) (_L_FUN_TYPE_B7),T* st, _L_FUN_SIG_A7){
    assert(st != 0);
    typedef typename _fun::_ptr_wraper<R,T,T*,_L_FUN_TYPE_B7> wrapper_type;
    return _fun::_bind_fwd<R,wrapper_type,_L_FUN_TYPE_A7>(wrapper_type(st,p),_L_FUN_INS_A7); 		
  }

  template<typename R,typename T, _L_FUN_TN_B8 , _L_FUN_TN_A8>
  _fun::_bind_fwd<R, typename _fun::_ptr_wraper<R,T,T*,_L_FUN_TYPE_B8>,_L_FUN_TYPE_A8>
  bind(R (T::*p) (_L_FUN_TYPE_B8),T* st, _L_FUN_SIG_A8){
    assert(st != 0);
    typedef typename _fun::_ptr_wraper<R,T,T*,_L_FUN_TYPE_B8> wrapper_type;
    return _fun::_bind_fwd<R,wrapper_type,_L_FUN_TYPE_A8>(wrapper_type(st,p),_L_FUN_INS_A8); 		
  }

  template<typename R,typename T, _L_FUN_TN_B9 , _L_FUN_TN_A9>
  _fun::_bind_fwd<R, typename _fun::_ptr_wraper<R,T,T*,_L_FUN_TYPE_B9>,_L_FUN_TYPE_A9>
  bind(R (T::*p) (_L_FUN_TYPE_B9),T* st, _L_FUN_SIG_A9){
    assert(st != 0);
    typedef typename _fun::_ptr_wraper<R,T,T*,_L_FUN_TYPE_B9> wrapper_type;
    return _fun::_bind_fwd<R,wrapper_type,_L_FUN_TYPE_A9>(wrapper_type(st,p),_L_FUN_INS_A9); 		
  }

}

#endif // __LFC_BIND_IMPL_MF_H_Dec_20_2010__

