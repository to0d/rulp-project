// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_FUNCTION_LIST_CALL_H_08_27_12__
#define __LFC_FUNCTION_LIST_CALL_H_08_27_12__

#include "lfc/base/function/function_list.h"

#define __LFC_FUN_LIST_CALL_DECLARE_BEAGIN \
	template<typename  R  ,typename F, _L_FUN_TN_A9 , _L_FUN_TN_B9_VOID>\
struct call_type\
  {\
  static R call(	F& f, \
  typename fun_list<_L_FUN_TYPE_A9>::list_type & list_a,\
  typename fun_list<_L_FUN_TYPE_B9>::list_type & list_b)\
  {\
  typedef typename fun_list<_L_FUN_TYPE_A9>::list_type A_list_type;\
  typedef typename fun_list<_L_FUN_TYPE_B9>::list_type B_list_type;\
  return f( 

#define __LFC_FUN_LIST_CALL_DECLARE_END ); }	};

namespace lfc {
  namespace _fun{

    template<int i = 0>
    struct _list_call{
      __LFC_FUN_LIST_CALL_DECLARE_BEAGIN	
      __LFC_FUN_LIST_CALL_DECLARE_END
    };

    template<>
    struct _list_call<1>{
      __LFC_FUN_LIST_CALL_DECLARE_BEAGIN 
        B_list_type:: template _get_value<A1>::get(list_b,list_a._va1)							
      __LFC_FUN_LIST_CALL_DECLARE_END
    };


    template<>
    struct _list_call<2>{
      __LFC_FUN_LIST_CALL_DECLARE_BEAGIN 
        B_list_type:: template _get_value<A1>::get(list_b,list_a._va1),
        B_list_type:: template _get_value<A2>::get(list_b,list_a._va2)				
      __LFC_FUN_LIST_CALL_DECLARE_END
    };



    template<>
    struct _list_call<3>{
      __LFC_FUN_LIST_CALL_DECLARE_BEAGIN \
        B_list_type:: template _get_value<A1 >::get(list_b,list_a._va1 ),
        B_list_type:: template _get_value<A2 >::get(list_b,list_a._va2 ),
        B_list_type:: template _get_value<A3 >::get(list_b,list_a._va3 )
      __LFC_FUN_LIST_CALL_DECLARE_END
    };

    template<>
    struct _list_call<4>{
      __LFC_FUN_LIST_CALL_DECLARE_BEAGIN 
        B_list_type:: template _get_value<A1>::get(list_b,list_a._va1),
        B_list_type:: template _get_value<A2>::get(list_b,list_a._va2),
        B_list_type:: template _get_value<A3>::get(list_b,list_a._va3),
        B_list_type:: template _get_value<A4>::get(list_b,list_a._va4)
      __LFC_FUN_LIST_CALL_DECLARE_END
    };

    template<>
    struct _list_call<5>{
      __LFC_FUN_LIST_CALL_DECLARE_BEAGIN 
        B_list_type:: template _get_value<A1>::get(list_b,list_a._va1),
        B_list_type:: template _get_value<A2>::get(list_b,list_a._va2),
        B_list_type:: template _get_value<A3>::get(list_b,list_a._va3),
        B_list_type:: template _get_value<A4>::get(list_b,list_a._va4),
        B_list_type:: template _get_value<A5>::get(list_b,list_a._va5)
      __LFC_FUN_LIST_CALL_DECLARE_END
    };

    template<>
    struct _list_call<6>{
      __LFC_FUN_LIST_CALL_DECLARE_BEAGIN 
        B_list_type:: template _get_value<A1>::get(list_b,list_a._va1),
        B_list_type:: template _get_value<A2>::get(list_b,list_a._va2),
        B_list_type:: template _get_value<A3>::get(list_b,list_a._va3),
        B_list_type:: template _get_value<A4>::get(list_b,list_a._va4),
        B_list_type:: template _get_value<A5>::get(list_b,list_a._va5),
        B_list_type:: template _get_value<A6>::get(list_b,list_a._va6)
      __LFC_FUN_LIST_CALL_DECLARE_END
    };

    template<>
    struct _list_call<7>{
      __LFC_FUN_LIST_CALL_DECLARE_BEAGIN 
        B_list_type:: template _get_value<A1>::get(list_b,list_a._va1),
        B_list_type:: template _get_value<A2>::get(list_b,list_a._va2),
        B_list_type:: template _get_value<A3>::get(list_b,list_a._va3),
        B_list_type:: template _get_value<A4>::get(list_b,list_a._va4),
        B_list_type:: template _get_value<A5>::get(list_b,list_a._va5),
        B_list_type:: template _get_value<A6>::get(list_b,list_a._va6),
        B_list_type:: template _get_value<A7>::get(list_b,list_a._va7)
      __LFC_FUN_LIST_CALL_DECLARE_END
    };

    template<>
    struct _list_call<8>{
      __LFC_FUN_LIST_CALL_DECLARE_BEAGIN 
        B_list_type:: template _get_value<A1>::get(list_b,list_a._va1),
        B_list_type:: template _get_value<A2>::get(list_b,list_a._va2),
        B_list_type:: template _get_value<A3>::get(list_b,list_a._va3),
        B_list_type:: template _get_value<A4>::get(list_b,list_a._va4),
        B_list_type:: template _get_value<A5>::get(list_b,list_a._va5),
        B_list_type:: template _get_value<A6>::get(list_b,list_a._va6),
        B_list_type:: template _get_value<A7>::get(list_b,list_a._va7),
        B_list_type:: template _get_value<A8>::get(list_b,list_a._va8)
      __LFC_FUN_LIST_CALL_DECLARE_END
    };

    template<>
    struct _list_call<9>{
      __LFC_FUN_LIST_CALL_DECLARE_BEAGIN 
        B_list_type:: template _get_value<A1>::get(list_b,list_a._va1),
        B_list_type:: template _get_value<A2>::get(list_b,list_a._va2),
        B_list_type:: template _get_value<A3>::get(list_b,list_a._va3),
        B_list_type:: template _get_value<A4>::get(list_b,list_a._va4),
        B_list_type:: template _get_value<A5>::get(list_b,list_a._va5),
        B_list_type:: template _get_value<A6>::get(list_b,list_a._va6),
        B_list_type:: template _get_value<A7>::get(list_b,list_a._va7),
        B_list_type:: template _get_value<A8>::get(list_b,list_a._va8),
        B_list_type:: template _get_value<A9>::get(list_b,list_a._va9)
      __LFC_FUN_LIST_CALL_DECLARE_END
    };

  } // namespace _fun
} // namespace lfc

#endif // __LFC_FUNCTION_LIST_CALL_H_08_27_12__
