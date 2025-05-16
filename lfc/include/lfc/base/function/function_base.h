// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_FUNCTION_BASE_H_08_27_12__
#define __LFC_FUNCTION_BASE_H_08_27_12__

#include "lfc/base/repeat.h"

#define	_L_FUN_INS_A1	__LFC_X1(a)
#define	_L_FUN_INS_A2	__LFC_X2(a)
#define	_L_FUN_INS_A3	__LFC_X3(a)
#define	_L_FUN_INS_A4	__LFC_X4(a)
#define	_L_FUN_INS_A5	__LFC_X5(a)
#define	_L_FUN_INS_A6	__LFC_X6(a)
#define	_L_FUN_INS_A7	__LFC_X7(a)
#define	_L_FUN_INS_A8	__LFC_X8(a)
#define	_L_FUN_INS_A9	__LFC_X9(a)

#define	_L_FUN_INS_B1	__LFC_X1(b)
#define	_L_FUN_INS_B2	__LFC_X2(b)
#define	_L_FUN_INS_B3	__LFC_X3(b)
#define	_L_FUN_INS_B4	__LFC_X4(b)
#define	_L_FUN_INS_B5	__LFC_X5(b)
#define	_L_FUN_INS_B6	__LFC_X6(b)
#define	_L_FUN_INS_B7	__LFC_X7(b)
#define	_L_FUN_INS_B8	__LFC_X8(b)
#define	_L_FUN_INS_B9	__LFC_X9(b)

#define	_L_FUN_TYPE_A1 __LFC_X1(A)
#define	_L_FUN_TYPE_A2 __LFC_X2(A)
#define	_L_FUN_TYPE_A3 __LFC_X3(A)
#define	_L_FUN_TYPE_A4 __LFC_X4(A)
#define	_L_FUN_TYPE_A5 __LFC_X5(A)
#define	_L_FUN_TYPE_A6 __LFC_X6(A)
#define	_L_FUN_TYPE_A7 __LFC_X7(A)
#define	_L_FUN_TYPE_A8 __LFC_X8(A)
#define	_L_FUN_TYPE_A9 __LFC_X9(A)

#define	_L_FUN_TYPE_B1 __LFC_X1(B)
#define	_L_FUN_TYPE_B2 __LFC_X2(B)
#define	_L_FUN_TYPE_B3 __LFC_X3(B)
#define	_L_FUN_TYPE_B4 __LFC_X4(B)
#define	_L_FUN_TYPE_B5 __LFC_X5(B)
#define	_L_FUN_TYPE_B6 __LFC_X6(B)
#define	_L_FUN_TYPE_B7 __LFC_X7(B)
#define	_L_FUN_TYPE_B8 __LFC_X8(B)
#define	_L_FUN_TYPE_B9 __LFC_X9(B)

#define _L_FUN_TN_A1 __LFC_XY1(typename, A)
#define _L_FUN_TN_A2 __LFC_XY2(typename, A)
#define _L_FUN_TN_A3 __LFC_XY3(typename, A)
#define _L_FUN_TN_A4 __LFC_XY4(typename, A)
#define _L_FUN_TN_A5 __LFC_XY5(typename, A)
#define _L_FUN_TN_A6 __LFC_XY6(typename, A)
#define _L_FUN_TN_A7 __LFC_XY7(typename, A)
#define _L_FUN_TN_A8 __LFC_XY8(typename, A)
#define _L_FUN_TN_A9 __LFC_XY9(typename, A)

#define _L_FUN_TN_B1 __LFC_XY1(typename, B)
#define _L_FUN_TN_B2 __LFC_XY2(typename, B)
#define _L_FUN_TN_B3 __LFC_XY3(typename, B)
#define _L_FUN_TN_B4 __LFC_XY4(typename, B)
#define _L_FUN_TN_B5 __LFC_XY5(typename, B)
#define _L_FUN_TN_B6 __LFC_XY6(typename, B)
#define _L_FUN_TN_B7 __LFC_XY7(typename, B)
#define _L_FUN_TN_B8 __LFC_XY8(typename, B)
#define _L_FUN_TN_B9 __LFC_XY9(typename, B)

#define	_L_FUN_SIG_A1	__LFC_X1Y1(A,a)
#define	_L_FUN_SIG_A2	__LFC_X2Y2(A,a)
#define	_L_FUN_SIG_A3	__LFC_X3Y3(A,a)
#define	_L_FUN_SIG_A4	__LFC_X4Y4(A,a)
#define	_L_FUN_SIG_A5	__LFC_X5Y5(A,a)
#define	_L_FUN_SIG_A6	__LFC_X6Y6(A,a)
#define	_L_FUN_SIG_A7	__LFC_X7Y7(A,a)
#define	_L_FUN_SIG_A8	__LFC_X8Y8(A,a)
#define	_L_FUN_SIG_A9	__LFC_X9Y9(A,a)

#define	_L_FUN_SIG_B1	__LFC_X1Y1(B,b)
#define	_L_FUN_SIG_B2	__LFC_X2Y2(B,b)
#define	_L_FUN_SIG_B3	__LFC_X3Y3(B,b)
#define	_L_FUN_SIG_B4	__LFC_X4Y4(B,b)
#define	_L_FUN_SIG_B5	__LFC_X5Y5(B,b)
#define	_L_FUN_SIG_B6	__LFC_X6Y6(B,b)
#define	_L_FUN_SIG_B7	__LFC_X7Y7(B,b)
#define	_L_FUN_SIG_B8	__LFC_X8Y8(B,b)
#define	_L_FUN_SIG_B9	__LFC_X9Y9(B,b)

#define _L_TN_VOID = void
#define _L_FUN_TN_A9_VOID __LFC_XY9Z(typename, A , _L_TN_VOID)
#define _L_FUN_TN_B9_VOID __LFC_XY9Z(typename, B , _L_TN_VOID)
#define _L_FUN_VOID_9 __LFC_REP9(_L_TN_VOID)

#define _L_FUN_VIR_BASE_DECLARE(_typename ,_type , _signature) \
	template<typename R, _typename>\
class _function_base<R,_type>\
	{\
	public:\
	virtual ~_function_base(){}\
	virtual R operator() (_signature) = 0;\
};


namespace lfc {
  namespace _fun{

    template<typename R, _L_FUN_TN_A9_VOID>
    class _function_base {
    public:
      virtual ~_function_base(){}
      virtual R operator() (_L_FUN_SIG_A9)  = 0;
    };

    template<typename R>
    class _function_base<R>
    {
    public:
      virtual R operator() () = 0;
      virtual ~_function_base(){}
    };

    _L_FUN_VIR_BASE_DECLARE(	_L_FUN_TN_A1,	_L_FUN_TYPE_A1,	_L_FUN_SIG_A1	);
    _L_FUN_VIR_BASE_DECLARE(	_L_FUN_TN_A2,	_L_FUN_TYPE_A2,	_L_FUN_SIG_A2	);
    _L_FUN_VIR_BASE_DECLARE(	_L_FUN_TN_A3,	_L_FUN_TYPE_A3,	_L_FUN_SIG_A3	);
    _L_FUN_VIR_BASE_DECLARE(	_L_FUN_TN_A4,	_L_FUN_TYPE_A4,	_L_FUN_SIG_A4	);
    _L_FUN_VIR_BASE_DECLARE(	_L_FUN_TN_A5,	_L_FUN_TYPE_A5,	_L_FUN_SIG_A5	);
    _L_FUN_VIR_BASE_DECLARE(	_L_FUN_TN_A6,	_L_FUN_TYPE_A6,	_L_FUN_SIG_A6	);
    _L_FUN_VIR_BASE_DECLARE(	_L_FUN_TN_A7,	_L_FUN_TYPE_A7,	_L_FUN_SIG_A7	);
    _L_FUN_VIR_BASE_DECLARE(	_L_FUN_TN_A8,	_L_FUN_TYPE_A8,	_L_FUN_SIG_A8	);
    // _L_FUN_VIR_BASE_DECLARE(	_L_FUN_TN_A9,	_L_FUN_TYPE_A8,	_L_FUN_SIG_A9	);

  } // namespace _fun
} // namespace lfc

#endif // __LFC_FUNCTION_BASE_H_08_27_12__
