// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_BASE_BIND_FWD_H_Dec_20_2010__
#define __LFC_BASE_BIND_FWD_H_Dec_20_2010__
#include "lfc/stl/type_traits.h"
#include "lfc/base/function/function_base.h"
#include "lfc/base/function/function_list.h"
#include "lfc/base/function/function_list_call.h"

#define _L_FUN_BIND_FWD_CALL(_typename ,impl , _signature,_instance) \
template<_typename> \
R operator ()(_signature) \
{\
	typedef typename fun_list<impl>::list_type out_list_type; \
	out_list_type list_av (_instance); \
	return list_call<out_list_type,impl>::_call(*this,list_av); \
}

namespace lfc {
  namespace _fun{

template<typename T> 
struct is_nor_void_num : impl::arg<1>{};

  template<> 
  struct is_nor_void_num<void> : impl::arg<0>{};

  template<
    typename A1 = void,
    typename A2 = void,
    typename A3 = void,
    typename A4 = void,
    typename A5 = void,
    typename A6 = void,
    typename A7 = void,
    typename A8 = void,
    typename A9 = void> 
  struct get_num_of_nor_void : public impl::arg<
      is_nor_void_num<A1>::value 
    +is_nor_void_num<A2>::value
    +is_nor_void_num<A3>::value
    +is_nor_void_num<A4>::value
    +is_nor_void_num<A5>::value
    +is_nor_void_num<A6>::value
    +is_nor_void_num<A7>::value
    +is_nor_void_num<A8>::value
    +is_nor_void_num<A9>::value>
  {};


    struct _bind_fwd_type{};

    template<typename R ,typename F, _L_FUN_TN_A9_VOID>
    class _bind_fwd 
      : protected	_list_call<get_num_of_nor_void<_L_FUN_TYPE_A9>::value>{
      typedef typename fun_list<_L_FUN_TYPE_A9>::list_type list_type;
      typedef _bind_fwd<R,F,_L_FUN_TYPE_A9>		 this_type;

    public:
      typedef	_bind_fwd_type  bind_fwd_type;

    public:
      _bind_fwd(F f ):_f(f),_list(){}
      virtual ~_bind_fwd(){}
      template<_L_FUN_TN_B1 >_bind_fwd(F f,_L_FUN_SIG_B1 ):_f(f),_list(_L_FUN_INS_B1 ){}
      template<_L_FUN_TN_B2 >_bind_fwd(F f,_L_FUN_SIG_B2 ):_f(f),_list(_L_FUN_INS_B2 ){}
      template<_L_FUN_TN_B3 >_bind_fwd(F f,_L_FUN_SIG_B3 ):_f(f),_list(_L_FUN_INS_B3 ){}
      template<_L_FUN_TN_B4 >_bind_fwd(F f,_L_FUN_SIG_B4 ):_f(f),_list(_L_FUN_INS_B4 ){}
      template<_L_FUN_TN_B5 >_bind_fwd(F f,_L_FUN_SIG_B5 ):_f(f),_list(_L_FUN_INS_B5 ){}
      template<_L_FUN_TN_B6 >_bind_fwd(F f,_L_FUN_SIG_B6 ):_f(f),_list(_L_FUN_INS_B6 ){}
      template<_L_FUN_TN_B7 >_bind_fwd(F f,_L_FUN_SIG_B7 ):_f(f),_list(_L_FUN_INS_B7 ){}
      template<_L_FUN_TN_B8 >_bind_fwd(F f,_L_FUN_SIG_B8 ):_f(f),_list(_L_FUN_INS_B8 ){}
      template<_L_FUN_TN_B9 >_bind_fwd(F f,_L_FUN_SIG_B9 ):_f(f),_list(_L_FUN_INS_B9 ){}	
   
      template<typename _L, _L_FUN_TN_B9_VOID>
      struct list_call{
        static R _call(this_type& _this, _L& _l){
          return this_type::template call_type<R, F,_L_FUN_TYPE_A9 ,_L_FUN_TYPE_B9>::call(
            _this._f,_this._list,_l);	
        }
      };

      R operator ()(){			
        impl::list0 list_av ;
        return this_type::template call_type<R, F,_L_FUN_TYPE_A9>::call(_f,_list,list_av);				
      }

      template<_L_FUN_TN_B1> 
      R operator ()(_L_FUN_SIG_B1){
        typedef typename fun_list<_L_FUN_TYPE_B1>::list_type out_list_type; 
        out_list_type list_av (_L_FUN_INS_B1); 
        return this_type::template list_call<out_list_type,_L_FUN_TYPE_B1>::_call(*this,list_av); 
      }

      //_L_FUN_BIND_FWD_CALL(_L_FUN_TN_B1,_L_FUN_TYPE_B1,_L_FUN_SIG_B1,_L_FUN_INS_B1);
      _L_FUN_BIND_FWD_CALL(_L_FUN_TN_B2,_L_FUN_TYPE_B2,_L_FUN_SIG_B2,_L_FUN_INS_B2);
      _L_FUN_BIND_FWD_CALL(_L_FUN_TN_B3,_L_FUN_TYPE_B3,_L_FUN_SIG_B3,_L_FUN_INS_B3);
      _L_FUN_BIND_FWD_CALL(_L_FUN_TN_B4,_L_FUN_TYPE_B4,_L_FUN_SIG_B4,_L_FUN_INS_B4);
      _L_FUN_BIND_FWD_CALL(_L_FUN_TN_B5,_L_FUN_TYPE_B5,_L_FUN_SIG_B5,_L_FUN_INS_B5);
      _L_FUN_BIND_FWD_CALL(_L_FUN_TN_B6,_L_FUN_TYPE_B6,_L_FUN_SIG_B6,_L_FUN_INS_B6);
      _L_FUN_BIND_FWD_CALL(_L_FUN_TN_B7,_L_FUN_TYPE_B7,_L_FUN_SIG_B7,_L_FUN_INS_B7);
      _L_FUN_BIND_FWD_CALL(_L_FUN_TN_B8,_L_FUN_TYPE_B8,_L_FUN_SIG_B8,_L_FUN_INS_B8);
      _L_FUN_BIND_FWD_CALL(_L_FUN_TN_B9,_L_FUN_TYPE_B9,_L_FUN_SIG_B9,_L_FUN_INS_B9);

    private:
      F _f;
      list_type _list;
    };

    template <typename F ,typename T = void> 
    struct is_bind_fwd_type : public impl::mpl_false{};

    template <typename F> 
    struct is_bind_fwd_type<F,_bind_fwd_type> : public impl::mpl_true{};

    template<typename F, class  Enable  = void>
    struct is_bind_fwd : public impl::mpl_false{};

    template<typename F>
    struct is_bind_fwd<F, typename enable_if<is_bind_fwd_type<F, typename F::bind_fwd_type>::value>::type>
      : public impl::mpl_true{};

  }

}

#endif // __LFC_BASE_BIND_FWD_H_Dec_20_2010__

