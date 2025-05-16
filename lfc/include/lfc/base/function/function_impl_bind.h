// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_FUNCTION_IMPL_BIND_H_Dec_20_2010__
#define __LFC_FUNCTION_IMPL_BIND_H_Dec_20_2010__

#include "lfc/base/function/function_list.h"
#include "lfc/base/function/function_list_call.h"

#define __L_FUN_BIND_F_DECLARE(_typename ,_type , _signature,_instance)\
	template<typename R,typename F,_typename>\
class _function_bind_t<R,F,_type>\
	: public _function_base<R,_type>\
		{\
		typedef typename fun_list<_type>::list_type out_list_type;\
		public:\
		_function_bind_t(F& f): _f(f){}\
		virtual ~_function_bind_t(){};\
		virtual R operator() (_signature)\
			{\
			out_list_type list_av (_instance);\
			return F::template list_call<out_list_type,_type>::_call(_f,list_av);\
			}\
		private:\
		F _f;\
		};

namespace lfc {
  namespace _fun{

    template<typename R,typename F,_L_FUN_TN_A9_VOID>
    class _function_bind_t 
      : public _function_base<R,_L_FUN_TYPE_A9>{
      typedef typename fun_list<_L_FUN_TYPE_A9>::list_type out_list_type;
    public:
      _function_bind_t(F f): _f(f){}
      virtual ~_function_bind_t(){};
      virtual R operator() (_L_FUN_SIG_A9){
        out_list_type list_av (_L_FUN_INS_A9);
        return F::template list_call<F,out_list_type,_L_FUN_TYPE_A9>::_call(_f,list_av);		
      }
    private:
      F _f;
    };

    template<typename R,typename F>
    class _function_bind_t<R,F>: public _function_base<R>{
      typedef typename fun_list<>::list_type out_list_type;

    public:
      _function_bind_t(F& f): _f(f){}
      virtual ~_function_bind_t(){};
      virtual R operator()(){
        return _f();
      }
    private:
      F _f;
    };

    __L_FUN_BIND_F_DECLARE(_L_FUN_TN_A1,_L_FUN_TYPE_A1,_L_FUN_SIG_A1,_L_FUN_INS_A1);
    __L_FUN_BIND_F_DECLARE(_L_FUN_TN_A2,_L_FUN_TYPE_A2,_L_FUN_SIG_A2,_L_FUN_INS_A2);
    __L_FUN_BIND_F_DECLARE(_L_FUN_TN_A3,_L_FUN_TYPE_A3,_L_FUN_SIG_A3,_L_FUN_INS_A3);
    __L_FUN_BIND_F_DECLARE(_L_FUN_TN_A4,_L_FUN_TYPE_A4,_L_FUN_SIG_A4,_L_FUN_INS_A4);
    __L_FUN_BIND_F_DECLARE(_L_FUN_TN_A5,_L_FUN_TYPE_A5,_L_FUN_SIG_A5,_L_FUN_INS_A5);
    __L_FUN_BIND_F_DECLARE(_L_FUN_TN_A6,_L_FUN_TYPE_A6,_L_FUN_SIG_A6,_L_FUN_INS_A6);
    __L_FUN_BIND_F_DECLARE(_L_FUN_TN_A7,_L_FUN_TYPE_A7,_L_FUN_SIG_A7,_L_FUN_INS_A7);
    __L_FUN_BIND_F_DECLARE(_L_FUN_TN_A8,_L_FUN_TYPE_A8,_L_FUN_SIG_A8,_L_FUN_INS_A8);
    // __L_FUN_BIND_F_DECLARE(_L_FUN_TN_A9,_L_FUN_TYPE_A9,_L_FUN_SIG_A8,_L_FUN_INS_A9);

  } // namespace _fun
} // namespace lfc

#endif // __LFC_FUNCTION_IMPL_BIND_H_Dec_20_2010__
