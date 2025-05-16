// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_MPL_LIST_H__
#define __LFC_MPL_LIST_H__

#include "lfc/base/repeat.h"
#include "lfc/stl/type_traits.h"
      
#define _L_LI_INS_A1    __LFC_X1(a)
#define _L_LI_INS_A2    __LFC_X2(a)
#define _L_LI_INS_A3    __LFC_X3(a)
#define _L_LI_INS_A4    __LFC_X4(a)
#define _L_LI_INS_A5    __LFC_X5(a)
#define _L_LI_INS_A6    __LFC_X6(a)
#define _L_LI_INS_A7    __LFC_X7(a)
#define _L_LI_INS_A8    __LFC_X8(a)
#define _L_LI_INS_A9    __LFC_X9(a)

#define _L_LI_TYPE_A1   __LFC_X1(A)
#define _L_LI_TYPE_A2   __LFC_X2(A)
#define _L_LI_TYPE_A3   __LFC_X3(A)
#define _L_LI_TYPE_A4   __LFC_X4(A)
#define _L_LI_TYPE_A5   __LFC_X5(A)
#define _L_LI_TYPE_A6   __LFC_X6(A)
#define _L_LI_TYPE_A7   __LFC_X7(A)
#define _L_LI_TYPE_A8   __LFC_X8(A)
#define _L_LI_TYPE_A9   __LFC_X9(A)

#define _L_LI_TN_A1     __LFC_XY1(typename, A)
#define _L_LI_TN_A2     __LFC_XY2(typename, A)
#define _L_LI_TN_A3     __LFC_XY3(typename, A)
#define _L_LI_TN_A4     __LFC_XY4(typename, A)
#define _L_LI_TN_A5     __LFC_XY5(typename, A)
#define _L_LI_TN_A6     __LFC_XY6(typename, A)
#define _L_LI_TN_A7     __LFC_XY7(typename, A)
#define _L_LI_TN_A8     __LFC_XY8(typename, A)
#define _L_LI_TN_A9     __LFC_XY9(typename, A)

#define __LFC_MPL_LIST_BEG(N, M) \
    template<_L_LI_TN_A##N> \
    class list##N : public list##M<_L_LI_TYPE_A##M>, public _store<A##N,N>{ \
      typedef list##N<_L_LI_TYPE_A##N> this_type; \
      typedef _store<A##N,N> store_type; \
    public: \
      list##N(__LFC_X##N##Y##N(A,a)) : list##M<_L_LI_TYPE_A##M>(_L_LI_INS_A##M),store_type(a##N){} \
      virtual ~list##N(){}; \
__LFC_MPL_LIST_GET_VALUE_FUN_BASE

#define __LFC_MPL_LIST_END \
    };

#define __LFC_MPL_LIST_GET_VALUE_FUN_BASE \
  template<typename B,typename S = void>\
  struct _get_value\
    {\
    static B get(this_type& list, B b)\
      {\
      list;\
      return b;\
      }\
    };

#define __LFC_MPL_LIST_GET_VALUE_FUN_DECLARE(i) \
  template<typename S>\
  struct _get_value<typename lfc::impl::arg<i>, S >\
    {\
    static  A##i get(this_type& list ,lfc::impl::arg<i>&)\
      {\
      return list._va##i;\
      }\
    };

#define _STORE( i ) \
	template<typename _T> \
  struct _store<_T,i>\
  {\
    _store(_T v):_va##i(v){}\
    virtual ~_store(){};\
    _T _va##i;\
  };
namespace lfc {

namespace impl {
template<typename T> 
struct is_placeholder : mpl_int<0> {};

template< int I > 
struct arg : public mpl_int<I>{
  constexpr arg() = default;

  template< class T > 
  arg( T const & /* t */ ){			
    static_assert(I == is_placeholder<T>::value, 
                  "T must be a placeholder with the same index");
  }
};

template< int I > 
struct is_placeholder< arg<I> > : mpl_int<I> {};

template< int I > 
struct is_placeholder< arg<I> (*) () > : mpl_int<I> {};

} // namespace impl

#define IMPL_ARG(I) inline constexpr impl::arg<I> _##I{}; 
IMPL_ARG(1) IMPL_ARG(2) IMPL_ARG(3) IMPL_ARG(4) IMPL_ARG(5) IMPL_ARG(6) IMPL_ARG(7) IMPL_ARG(8) IMPL_ARG(9)

namespace impl {

template<typename _T,int index = 0>
struct _store{
  virtual ~_store(){};
};

_STORE(1);
_STORE(2);
_STORE(3);
_STORE(4);
_STORE(5);
_STORE(6);
_STORE(7);
_STORE(8);
_STORE(9);

class list0{
  typedef list0 this_type;
public:
  list0() {}
  virtual ~list0(){};
  __LFC_MPL_LIST_GET_VALUE_FUN_BASE;    
};

template<_L_LI_TN_A1>
class list1 : public _store<_L_LI_TYPE_A1,1>{            
  typedef list1<_L_LI_TYPE_A1> this_type;
  typedef _store<_L_LI_TYPE_A1,1> store_type;
    
public:
  list1(A1 a1) : store_type(_L_LI_INS_A1){}
  virtual ~list1(){};

  __LFC_MPL_LIST_GET_VALUE_FUN_BASE;        
  __LFC_MPL_LIST_GET_VALUE_FUN_DECLARE(1);    
};    

template<typename _Ty, _L_LI_TN_A1>
struct list1_get{
  typedef list1<_L_LI_TYPE_A1> this_list_type;
  static _Ty get(_Ty& v, this_list_type& list){
    return v;
  }
};

template<_L_LI_TN_A1>
struct list1_get<lfc::impl::arg<1>,_L_LI_TYPE_A1>{
  typedef list1<_L_LI_TYPE_A1> this_list_type;
  typedef lfc::impl::arg<1> _Ty;
  static A1 get(_Ty& v, this_list_type& list){
    return list.va1;
  }
};

__LFC_MPL_LIST_BEG(2, 1)      
  __LFC_MPL_LIST_GET_VALUE_FUN_DECLARE(1);    
  __LFC_MPL_LIST_GET_VALUE_FUN_DECLARE(2);
__LFC_MPL_LIST_END

__LFC_MPL_LIST_BEG(3, 2)      
  __LFC_MPL_LIST_GET_VALUE_FUN_DECLARE(1);    
  __LFC_MPL_LIST_GET_VALUE_FUN_DECLARE(2);
  __LFC_MPL_LIST_GET_VALUE_FUN_DECLARE(3);
__LFC_MPL_LIST_END

__LFC_MPL_LIST_BEG(4, 3)       
  __LFC_MPL_LIST_GET_VALUE_FUN_DECLARE(1);
  __LFC_MPL_LIST_GET_VALUE_FUN_DECLARE(2);
  __LFC_MPL_LIST_GET_VALUE_FUN_DECLARE(3);
  __LFC_MPL_LIST_GET_VALUE_FUN_DECLARE(4);
__LFC_MPL_LIST_END

__LFC_MPL_LIST_BEG(5, 4)
  __LFC_MPL_LIST_GET_VALUE_FUN_DECLARE(1);
  __LFC_MPL_LIST_GET_VALUE_FUN_DECLARE(2);
  __LFC_MPL_LIST_GET_VALUE_FUN_DECLARE(3);
  __LFC_MPL_LIST_GET_VALUE_FUN_DECLARE(4);
  __LFC_MPL_LIST_GET_VALUE_FUN_DECLARE(5);
__LFC_MPL_LIST_END

__LFC_MPL_LIST_BEG(6, 5)
  __LFC_MPL_LIST_GET_VALUE_FUN_DECLARE(1);
  __LFC_MPL_LIST_GET_VALUE_FUN_DECLARE(2);
  __LFC_MPL_LIST_GET_VALUE_FUN_DECLARE(3);
  __LFC_MPL_LIST_GET_VALUE_FUN_DECLARE(4);
  __LFC_MPL_LIST_GET_VALUE_FUN_DECLARE(5);
  __LFC_MPL_LIST_GET_VALUE_FUN_DECLARE(6);
__LFC_MPL_LIST_END

__LFC_MPL_LIST_BEG(7, 6)
  __LFC_MPL_LIST_GET_VALUE_FUN_DECLARE(1);
  __LFC_MPL_LIST_GET_VALUE_FUN_DECLARE(2);
  __LFC_MPL_LIST_GET_VALUE_FUN_DECLARE(3);
  __LFC_MPL_LIST_GET_VALUE_FUN_DECLARE(4);
  __LFC_MPL_LIST_GET_VALUE_FUN_DECLARE(5);
  __LFC_MPL_LIST_GET_VALUE_FUN_DECLARE(6);
  __LFC_MPL_LIST_GET_VALUE_FUN_DECLARE(7);
__LFC_MPL_LIST_END

__LFC_MPL_LIST_BEG(8, 7)
  __LFC_MPL_LIST_GET_VALUE_FUN_DECLARE(1);
  __LFC_MPL_LIST_GET_VALUE_FUN_DECLARE(2);
  __LFC_MPL_LIST_GET_VALUE_FUN_DECLARE(3);
  __LFC_MPL_LIST_GET_VALUE_FUN_DECLARE(4);
  __LFC_MPL_LIST_GET_VALUE_FUN_DECLARE(5);
  __LFC_MPL_LIST_GET_VALUE_FUN_DECLARE(6);
  __LFC_MPL_LIST_GET_VALUE_FUN_DECLARE(7);
  __LFC_MPL_LIST_GET_VALUE_FUN_DECLARE(8);
__LFC_MPL_LIST_END

__LFC_MPL_LIST_BEG(9, 8)
  __LFC_MPL_LIST_GET_VALUE_FUN_DECLARE(1);
  __LFC_MPL_LIST_GET_VALUE_FUN_DECLARE(2);
  __LFC_MPL_LIST_GET_VALUE_FUN_DECLARE(3);
  __LFC_MPL_LIST_GET_VALUE_FUN_DECLARE(4);
  __LFC_MPL_LIST_GET_VALUE_FUN_DECLARE(5);
  __LFC_MPL_LIST_GET_VALUE_FUN_DECLARE(6);
  __LFC_MPL_LIST_GET_VALUE_FUN_DECLARE(7);
  __LFC_MPL_LIST_GET_VALUE_FUN_DECLARE(8);
  __LFC_MPL_LIST_GET_VALUE_FUN_DECLARE(9);
__LFC_MPL_LIST_END

} // namespace impl

} // namespace lfc

#endif // __LFC_MPL_LIST_H__
