// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_FUNCTION_LIST_H_08_27_12__
#define __LFC_FUNCTION_LIST_H_08_27_12__

#include "lfc/base/type.h"
#include "lfc/base/function/function_base.h"

namespace lfc {
  namespace _fun{

    template<_L_FUN_TN_A9_VOID, int i = 0>
    struct fun_list{
      typedef impl::list9<_L_FUN_TYPE_A9> list_type;			
    };

    template<>
    struct fun_list<>{
      typedef impl::list0 list_type;			
    };

    template<_L_FUN_TN_A1>
    struct fun_list<_L_FUN_TYPE_A1>{
      typedef impl::list1<_L_FUN_TYPE_A1> list_type;
    };

    template<_L_FUN_TN_A2>
    struct fun_list<_L_FUN_TYPE_A2>{
      typedef impl::list2<_L_FUN_TYPE_A2> list_type;
    };

    template<_L_FUN_TN_A3>
    struct fun_list<_L_FUN_TYPE_A3>{
      typedef impl::list3<_L_FUN_TYPE_A3> list_type;
    };

    template<_L_FUN_TN_A4>
    struct fun_list<_L_FUN_TYPE_A4>{
      typedef impl::list4<_L_FUN_TYPE_A4> list_type;
    };

    template<_L_FUN_TN_A5>
    struct fun_list<_L_FUN_TYPE_A5>{
      typedef impl::list5<_L_FUN_TYPE_A5> list_type;
    };

    template<_L_FUN_TN_A6>
    struct fun_list<_L_FUN_TYPE_A6>{
      typedef impl::list6<_L_FUN_TYPE_A6> list_type;
    };

    template<_L_FUN_TN_A7>
    struct fun_list<_L_FUN_TYPE_A7>{
      typedef impl::list7<_L_FUN_TYPE_A7> list_type;
    };

    template<_L_FUN_TN_A8>
    struct fun_list<_L_FUN_TYPE_A8>{
      typedef impl::list8<_L_FUN_TYPE_A8> list_type;
    };

  } // namespace _fun
} // namespace lfc

#endif // __LFC_FUNCTION_LIST_H_08_27_12__

