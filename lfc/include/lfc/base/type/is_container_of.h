// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_IS_CONTAINER_OF_H__
#define __LFC_IS_CONTAINER_OF_H__
#include "lfc/stl/type_traits.h"
#include "lfc/base/type/is_container.h"

namespace lfc {
  namespace impl{

    template <typename _C ,typename _T> 
    struct is_container_of 
      : public MPL_AND<is_container<_C>, is_one_of<_T, typename _C::value_type>>
    {};

  }	
}

#endif // __LFC_IS_CONTAINER_OF_H__
