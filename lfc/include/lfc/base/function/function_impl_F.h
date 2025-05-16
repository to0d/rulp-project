// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_FUNCTION_IMPL_F_H_08_27_12__
#define __LFC_FUNCTION_IMPL_F_H_08_27_12__

#define __L_FUN_VIR_F_DECLARE(_typename ,_type , _signature,_instance) \
  template<typename R,typename F,_typename>\
class _function_F<R,F,_type> : \
  public _function_base<R,_type>\
  {\
  public:\
  _function_F(F f): _f(f){}\
  virtual~_function_F(){}\
  virtual R operator() (_signature)\
  {	return _f(_instance);	}\
  private:\
  F _f;\
};


namespace lfc {
  namespace _fun{

    template<typename R,typename F,_L_FUN_TN_A9_VOID>
    class _function_F : public _function_base<R,_L_FUN_TYPE_A9>{
    public:
      _function_F(F f): _f(f){}
      virtual ~_function_F(){};
      virtual R operator() (_L_FUN_SIG_A9){
        return _f(_L_FUN_INS_A9);
      }
    private:
      F _f;
    };

    template<typename R,typename F>
    class _function_F<R,F> : public _function_base<R>{
    public:
      _function_F(F f): _f(f){}
      virtual ~_function_F(){};
      virtual R operator() (){
        return _f();
      }
    private:
      F _f;
    };

    __L_FUN_VIR_F_DECLARE(	_L_FUN_TN_A1,	_L_FUN_TYPE_A1,	_L_FUN_SIG_A1,	_L_FUN_INS_A1	);
    __L_FUN_VIR_F_DECLARE(	_L_FUN_TN_A2,	_L_FUN_TYPE_A2,	_L_FUN_SIG_A2,	_L_FUN_INS_A2	);
    __L_FUN_VIR_F_DECLARE(	_L_FUN_TN_A3,	_L_FUN_TYPE_A3,	_L_FUN_SIG_A3,	_L_FUN_INS_A3	);
    __L_FUN_VIR_F_DECLARE(	_L_FUN_TN_A4,	_L_FUN_TYPE_A4,	_L_FUN_SIG_A4,	_L_FUN_INS_A4	);
    __L_FUN_VIR_F_DECLARE(	_L_FUN_TN_A5,	_L_FUN_TYPE_A5,	_L_FUN_SIG_A5,	_L_FUN_INS_A5	);
    __L_FUN_VIR_F_DECLARE(	_L_FUN_TN_A6,	_L_FUN_TYPE_A6,	_L_FUN_SIG_A6,	_L_FUN_INS_A6	);
    __L_FUN_VIR_F_DECLARE(	_L_FUN_TN_A7,	_L_FUN_TYPE_A7,	_L_FUN_SIG_A7,	_L_FUN_INS_A7	);
    __L_FUN_VIR_F_DECLARE(	_L_FUN_TN_A8,	_L_FUN_TYPE_A8,	_L_FUN_SIG_A8,	_L_FUN_INS_A8	);


  } // namespace _fun
} // namespace lfc

#endif // __LFC_FUNCTION_IMPL_F_H_08_27_12__

