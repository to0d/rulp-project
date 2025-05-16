#ifndef __LFC_BASE_FUNCTION_IMPL__
#define __LFC_BASE_FUNCTION_IMPL__

#include "lfc/base/function.h"
#include "lfc/base/function/function_fwd.h"
#include "lfc/base/function/function_impl_F.h"
#include "lfc/base/function/function_list_call.h"

#define __LFC_MPL_FUN_DECLARE( FUN_TYPE )	\
private:\
	FUN_TYPE m_fun_##FUN_TYPE;	\
public:\
	template<typename F>\
	inline void set_##FUN_TYPE(F& _f)	{	m_fun_##FUN_TYPE = _f;		}\
	inline FUN_TYPE& get_##FUN_TYPE()	{	return m_fun_##FUN_TYPE;	}\
	inline bool has_##FUN_TYPE()		{	return !m_fun_##FUN_TYPE.isNull();}


#include "lfc/base/function/function_impl_bind.h"
#include "lfc/base/function/function_impl.h"
#include "lfc/base/function/function_impl_fk.h"
#include "lfc/base/function/bind/bind_fwd.h"
#include "lfc/base/function/bind/bind_impl_r.h"
#include "lfc/base/function/bind/bind_impl_f.h"
#include "lfc/base/function/bind/bind_impl_mf.h"
#include "lfc/base/function/bind/bind_impl_mf_shared.h"

#endif // __LFC_BASE_FUNCTION_IMPL__

