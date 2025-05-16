// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_TRACE_MACRO_H__
#define __LFC_TRACE_MACRO_H__



#define TRACE_SET_TRACE(xx) set_##xx##_trace
#define TRACE_GET_TRACE(xx) get_##xx##_trace

#define TRACE_SUB_MODULE_IMPL(xx) \
bool _##xx##_trace = false;\
void TRACE_SET_TRACE(xx)(bool trace){\
  _##xx##_trace = trace;\
}\
bool TRACE_GET_TRACE(xx)(){\
  return _##xx##_trace;\
}

#define UPDATE_TRACE(xx, v) \
    bool old_##xx##_trace = TRACE_GET_TRACE(xx)();\
    TRACE_SET_TRACE(xx)(v);\
    auto_do_while_leave AUTO_NAME(xx) ([&old_##xx##_trace](){TRACE_SET_TRACE(xx)(old_##xx##_trace);});

#define TRACE_SUB_MODULE_DEF(xx) \
void TRACE_SET_TRACE(xx)(bool trace);\
bool TRACE_GET_TRACE(xx)();

#endif // __LFC_TRACE_MACRO_H__

