#ifndef __BASE_H_08_27_12__
#define __BASE_H_08_27_12__

#include <iostream>
#include <assert.h>
#include <list>
#include <queue>
#include <set>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>
#include <string>
#include <math.h>

//==============================================================================
#ifdef  WIN32
	#include <windows.h>
	#include  <cassert>
	#ifdef _DEBUG
		#define _LFC_WIN_ASSERT(f)	(void) ((f) || !_CrtDbgReport(_CRT_ASSERT,__FILE__, __LINE__, "%s", #f) || (DebugBreak(), 0))
	#else 
		#define _LFC_WIN_ASSERT(f)	__noop
	#endif

	#define __SLFC_ASSERT__ _LFC_WIN_ASSERT
#else
	#include <assert.h>
	#define __SLFC_ASSERT__ assert
#endif
//==============================================================================
#define SLFC_MAX_TRACE_BUFFER		8192
//==============================================================================
#define __LFC_NONE
#define __LFC_CHECK_RETURN_FALSE( _v  ) if(!(_v)) return false;
#define __LFC_IF_CHECK_RETURN( _v , _r) if((_v)) return _r;
#define __LFC_IF__NULL_RETURN( _p,  _r) if ((_p) == NULL) return _r;
#define __LFC_FUN_NULL_RETURN( _f,  _r) if ((_f).isNull()) return _r;
//==============================================================================
#define SLFC_JOINT_STR1(a,b)		    a##b	
#define SLFC_JOINT_STR2(a,b)		    SLFC_JOINT_STR1(a,b)	
#define SLFC_AUTO_NAME(_predix)	    SLFC_JOINT_STR2(_predix,__LINE__)
//==============================================================================
#define SLFC_STATIC_ASSERT( expr )		typedef char SLFC_AUTO_NAME(_STATIC)[(expr)? 1:-1];
//=========================================================================
#define SLFC_WIN_CREATE_SINGLE_EVENT(x) (x = CreateEvent(NULL,FALSE,FALSE,NULL))
#define SLFC_WIN_CLOSE_HANDEL(x) \
  if( (x) != NULL) \
  {\
  CloseHandle(x);\
  x = NULL;\
  }

#define SLFC_WIN_WAIT_SINGLE_EVENT(x,timeout) (WAIT_OBJECT_0 == WaitForSingleObject(x,timeout))
//==============================================================================
#define SLFC_ATOMIC_STATE(state)   \
    private:\
    LONG m_l##state;\
  public:\
  void set##state(bool param)\
{\
  if(param)\
{\
  InterlockedCompareExchange(&m_l##state,1,m_l##state);\
}\
  else\
{\
  InterlockedCompareExchange(&m_l##state,0,m_l##state);\
}\
}\
  bool get##state() \
{\
  if(InterlockedCompareExchange(&m_l##state,m_l##state,1))\
{\
  return true;\
}\
  else\
{\
  return false;\
}\
}

#define SLFC_ATOMIC_COUNT(m_node_name)   \
    private:\
    LONG m_l##m_node_name;\
    public:\
    __forceinline LONG inc##m_node_name()\
{\
  __SLFC_ASSERT__(InterlockedExchangeAdd(&m_l##m_node_name, 0) >= 0);\
  return InterlockedIncrement(&m_l##m_node_name);\
}\
  __forceinline LONG add##m_node_name(LONG Delta)\
{\
  __SLFC_ASSERT__(InterlockedExchangeAdd(&m_l##m_node_name, 0) >= 0);\
  return ::InterlockedExchangeAdd(&m_l##m_node_name,Delta);\
}\
  __forceinline bool dec##m_node_name()\
{\
  __SLFC_ASSERT__(InterlockedExchangeAdd(&m_l##m_node_name, 0) >= 0);\
  return InterlockedDecrement(&m_l##m_node_name) == 0;\
}\
  __forceinline void set##m_node_name(LONG m_node_name)\
{\
  __SLFC_ASSERT__(m_node_name >= 0);\
  ::InterlockedExchange(&m_l##m_node_name, m_node_name);\
}\
  __forceinline void reset##m_node_name()\
{\
  ::InterlockedExchange(&m_l##m_node_name, 0);\
}\
  __forceinline LONG get##m_node_name()\
{\
  return InterlockedExchangeAdd(&m_l##m_node_name, 0);\
}


#define SLFC_COUNT(m_node_name)   \
  private:\
  LONG m_l##m_node_name;\
  public:\
  __forceinline void add##m_node_name()\
{\
  __SLFC_ASSERT__(m_l##m_node_name >= 0);\
  ++m_l##m_node_name;\
}\
  __forceinline void inc##m_node_name()\
{\
  __SLFC_ASSERT__(m_l##m_node_name > 0);\
  --m_l##m_node_name;\
}\
  __forceinline void set##m_node_name(LONG m_node_name)\
{\
  m_l##m_node_name = m_node_name;\
}\
  __forceinline void reset##m_node_name()\
{\
  m_l##m_node_name = 0;\
}\
  __forceinline LONG get##m_node_name()\
{\
  return m_l##m_node_name;\
}


#define SLFC_MEM_STATE(T,state)  \
  private:\
  T m_##state;\
  public:\
  T get_##state() { return  m_##state; }\
  void set_##state(T value) { m_##state = value;}

#define SLFC_FREE_POINTER(x)				\
  {								\
  if( (x) != NULL )			\
      {							\
      delete (x);				\
      (x) = NULL;				\
      }							\
  }

#define SLFC_FREE_HANDLE(x)				\
  {								\
  if( (x) != NULL )			\
      {							\
      CloseHandle(x);			\
      (x) = NULL;				\
      }							\
  }

#define SLFC_FREE_ARRAY(x)  \
  {								\
  if( (x) != NULL )			\
    {                   \
    delete [](x);			  \
    (x) = NULL;         \
    }                   \
  }


#endif // __BASE_H_08_27_12__

