// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_TRACE_H__
#define __LFC_TRACE_H__


#include "lfc/base/repeat.h"

#ifndef LFC_TRACE_NEED
#ifdef NOT_TRACE_THIS
  #define LFC_TRACE_NEED false
#else
  #define LFC_TRACE_NEED true
#endif    
#endif

#ifndef LFC_TRACE_NAME
  #define LFC_TRACE_NAME ""
#endif

#ifndef LFC_TRACE_ENABLE
  #define LFC_TRACE_ENABLE LFC_TRACE_NEED && get_global_trace()
#endif

#ifndef LFC_TRACE_STREAM
  #include <iostream>
  #define LFC_TRACE_STREAM std::cout
#endif

#define LFC_TRACE1(x)  if( LFC_TRACE_ENABLE ){ LFC_TRACE_STREAM << "[trace]" << LFC_TRACE_NAME << " " << x << "\n"; }
#define LFC_TRACE2(x1, x2)  if( LFC_TRACE_ENABLE ){ LFC_TRACE_STREAM << "[trace]" << LFC_TRACE_NAME << " " << x1 << x2 << "\n"; }
#define LFC_TRACE3(x1, x2, x3)  if( LFC_TRACE_ENABLE ){ LFC_TRACE_STREAM << "[trace]" << LFC_TRACE_NAME << " " << x1 << x2 << x3 << "\n"; }
#define LFC_TRACE4(x1, x2, x3, x4)  if( LFC_TRACE_ENABLE ){ LFC_TRACE_STREAM << "[trace]" << LFC_TRACE_NAME << " " << x1 << x2 << x3 << x4 << "\n"; }
#define LFC_TRACE5(x1, x2, x3, x4, x5)  if( LFC_TRACE_ENABLE ){ LFC_TRACE_STREAM << "[trace]" << LFC_TRACE_NAME << " " << x1 << x2 << x3 << x4 << x5 << "\n"; }
#define LFC_TRACE6(x1, x2, x3, x4, x5, x6)  if( LFC_TRACE_ENABLE ){ LFC_TRACE_STREAM << "[trace]" << LFC_TRACE_NAME << " " << x1 << x2 << x3 << x4 << x5 << x6 << "\n"; }
#define LFC_TRACE7(x1, x2, x3, x4, x5, x6, x7)  if( LFC_TRACE_ENABLE ){ LFC_TRACE_STREAM << "[trace]" << LFC_TRACE_NAME << " " << x1 << x2 << x3 << x4 << x5 << x6 << x7 << "\n"; }
#define LFC_TRACE8(x1, x2, x3, x4, x5, x6, x7, x8)  if( LFC_TRACE_ENABLE ){ LFC_TRACE_STREAM << "[trace]" << LFC_TRACE_NAME << " " << x1 << x2 << x3 << x4 << x5 << x6 << x7 << x8 << "\n"; }
#define LFC_TRACE9(x1, x2, x3, x4, x5, x6, x7, x8, x9)  if( LFC_TRACE_ENABLE ){ LFC_TRACE_STREAM << "[trace]" << LFC_TRACE_NAME << " " << x1 << x2 << x3 << x4 << x5 << x6 << x7 << x8 << x9 << "\n"; }
#define LFC_TRACE10(x1, x2, x3, x4, x5, x6, x7, x8, x9, x10)  if( LFC_TRACE_ENABLE ){ LFC_TRACE_STREAM << "[trace]" << LFC_TRACE_NAME << " " << x1 << x2 << x3 << x4 << x5 << x6 << x7 << x8 << x9 << x10 << "\n"; }
#define LFC_TRACE11(x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11)  if( LFC_TRACE_ENABLE ){ LFC_TRACE_STREAM << "[trace]" << LFC_TRACE_NAME << " " << x1 << x2 << x3 << x4 << x5 << x6 << x7 << x8 << x9 << x10 << x11 << "\n"; }
#define LFC_TRACE12(x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12)  if( LFC_TRACE_ENABLE ){ LFC_TRACE_STREAM << "[trace]" << LFC_TRACE_NAME << " " << x1 << x2 << x3 << x4 << x5 << x6 << x7 << x8 << x9 << x10 << x11 << x12 << "\n"; }
#define LFC_TRACE13(x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13)  if( LFC_TRACE_ENABLE ){ LFC_TRACE_STREAM << "[trace]" << LFC_TRACE_NAME << " " << x1 << x2 << x3 << x4 << x5 << x6 << x7 << x8 << x9 << x10 << x11 << x12 << x13 << "\n"; }
#define LFC_TRACE14(x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14)  if( LFC_TRACE_ENABLE ){ LFC_TRACE_STREAM << "[trace]" << LFC_TRACE_NAME << " " << x1 << x2 << x3 << x4 << x5 << x6 << x7 << x8 << x9 << x10 << x11 << x12 << x13 << x14 << "\n"; }

#define LFC_TRACE_BEGIN  if( LFC_TRACE_ENABLE ) { LFC_TRACE_STREAM
#define LFC_TRACE_END "\n"; }

#define LFC_TRACE_LIST(xx_name, xx_list) \
  {                                                                          \
    int xx_size = (xx_list).size();                                          \
    LFC_TRACE3((xx_name), ": size= ", xx_size);                             \
    if( LFC_TRACE_ENABLE ){                                                 \
      for(auto& XX : (xx_list)){                                              \
        LFC_TRACE_BEGIN << "    " << lfc::to_string(XX) << LFC_TRACE_END; \
      }                                                                      \
    }                                                                        \
  }


namespace lfc {

void set_global_trace(bool trace);
bool get_global_trace();

#ifdef USE_LFC_NEW_TRACE

template <typename T>
void LFC_TRACE_ONE(T value){
  LFC_TRACE_STREAM << value;
}

template <typename T, typename... Args>
void LFC_TRACE_ONE(T value, Args... args){
  LFC_TRACE_STREAM << value;
  LFC_TRACE_ONE(args...);
}

template <typename... Args>
void LFC_TRACE(Args... args){
  if(!LFC_TRACE_ENABLE){
    return;
  }

  LFC_TRACE_STREAM << "[trace]" << LFC_TRACE_NAME << " ";
  LFC_TRACE_ONE(args...);
  LFC_TRACE_STREAM << "\n";
}


#endif // USE_LFC_NEW_TRACE

} // namespace lfc
#endif // __LFC_TRACE_H__

