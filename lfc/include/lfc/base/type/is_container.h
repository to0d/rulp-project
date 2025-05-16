// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_IS_CONTAINER_H__
#define __LFC_IS_CONTAINER_H__

#include "lfc/stl/type_traits.h"

#include <list>
#include <vector>
#include <set>

namespace lfc {
  namespace impl{	

    template <typename _T> 
    struct is_container : public mpl_false{};

    template <typename _T> 
    struct is_container <std::vector<_T>> : public mpl_true{};

    template <typename _T> 
    struct is_container<std::set<_T> > : public mpl_true{};

    template <typename _T> 
    struct is_container<std::list<_T> > : public mpl_true{};

  }
}

#endif // __LFC_IS_CONTAINER_H__
