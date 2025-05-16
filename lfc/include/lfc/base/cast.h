// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_BASE_CAST__
#define __LFC_BASE_CAST__

#include "lfc/base/cast/cast_base.h"
#include "lfc/base/cast/cast_impl_container.h"
#include <string>

#define TO_WSTR(x)          lfc::__to_wstring(x)
#define TO_INT(x)           lfc::__to_int(x)
#define TO_LONG(x)          lfc::__to_long(x)
#define TO_LONG_LONG(x)     lfc::__to_long_long(x)
#define TO_UINT128(x)       lfc::__to_u128(x)
#define TO_FLOAT(x)         lfc::__to_float(x)
#define TO_DOUBLE(x)        lfc::__to_double(x)
#define TO_HEX_STR(x)       lfc::__to_hex_str(x)
#define TO_BIT_STR(x)       lfc::__to_bit_str(x)
#define HEX_STR_TO_BYTES(x) lfc::__hex_str_to_bytes(x)

namespace lfc {

std::string __to_bit_str(uint8_t val);
std::string __to_hex_str(uint64_t val);
std::string __int_to_str(int val);
std::string __long_to_str(long val);
std::string __float_to_str(float val);
std::string __ushort_to_str(unsigned short val);
std::string __short_to_str(short val);

double      __str_to_double (const std::string& str);
float       __str_to_float  (const std::string& str);
int         __str_to_int    (const std::string& str);
long        __str_to_long   (const std::string& str);
long long   __str_to_long2  (const std::string& str);
__uint128_t __str_to_uint128(const std::string& str);

int         __wstr_to_int   (const std::wstring& str);
long        __wstr_to_long  (const std::wstring& str);

std::wstring  __str_to_wstr (const std::string& str);
std::string   __wstr_to_str (const std::wstring& str);

std::vector<uint8_t> __hex_str_to_bytes(const std::string& str);


template<typename _Ty1, typename _Ty2>
bool auto_cast_to(const  _Ty1& from,  _Ty2& to){
  typedef _auto_cast_functor<_Ty1, _Ty2> cast_type;
  return cast_type::_cast(from, to);
}

template <>
struct _auto_cast_functor<std::string, double>{
  inline static bool _cast(const std::string& a, double& b){
    b = __str_to_double(a);
    return true;
  }
};

template <>
struct _auto_cast_functor<std::string, float>{
  inline static bool _cast(const std::string& a, float& b){
    b = __str_to_float(a);
    return true;
  }
};

template <>
struct _auto_cast_functor<std::string, int>{
  inline static bool _cast(const std::string& a ,int & b){
    b = __str_to_int(a);
    return true;
  }
};


template <>
struct _auto_cast_functor< std::string, long>{
  inline static bool _cast(const std::string& a ,long& b){
    b = __str_to_long(a);
    return true;
  }
};

template <>
struct _auto_cast_functor< std::string, long long>{
  inline static bool _cast(const std::string& a, long long& b){
    b = __str_to_long2(a);
    return true;
  }
};

template <>
struct _auto_cast_functor< std::string, __uint128_t>{
  inline static bool _cast(const std::string& a,__uint128_t& b){
    b = __str_to_uint128(a);
    return true;
  }
};

template <>
struct _auto_cast_functor<std::wstring, int>{
  inline static bool _cast(const std::wstring& a, int & b){
    b = __wstr_to_int(a);
    return true;
  }
};

template <>
struct _auto_cast_functor<std::wstring, long>{
  inline static bool _cast(const std::wstring& a, long& b){
    b = __wstr_to_long(a);
    return true;
  }
};


template <>
struct _auto_cast_functor<int, std::string>{
  inline static bool _cast(const int &a , std::string&b){
    b = __int_to_str(a);
    return true;
  }
};



template <>
struct _auto_cast_functor<std::string, std::wstring>{
  static bool _cast(const std::string& a, std::wstring& b){
    b = __str_to_wstr(a);
    return true;
  }
};

template <>
struct _auto_cast_functor<char*, std::wstring>{
  static bool _cast(const char* in_str , std::wstring& out_wstr){
    return _auto_cast_functor<std::string, std::wstring>::_cast(std::string(in_str),out_wstr);
  }
};

template <int i>
struct _auto_cast_functor<char[i], std::wstring>{
  static bool _cast( const char* in_str, std::wstring& out_wstr){
    return _auto_cast_functor<std::string,std::wstring>::_cast(std::string(in_str),out_wstr);
  }
};

template <>
struct _auto_cast_functor<std::wstring, std::string>{
  static bool _cast( const std::wstring& a,std::string & b){
    b = __wstr_to_str(a);
    return true;
  }
};	

template <>
struct _auto_cast_functor<wchar_t*, std::string>{
  static bool _cast( const wchar_t* a , std::string& b){
    return _auto_cast_functor<std::wstring, std::string>::_cast(std::wstring(a),b);
  }
};	

template <int i>
struct _auto_cast_functor<const wchar_t[i], std::string>{
  static bool _cast( const wchar_t* in_str , std::string& out_wstr){
    return _auto_cast_functor<std::wstring,std::string>::_cast(
      std::wstring(in_str),out_wstr);
  }
};


template <>
struct _auto_cast_functor<int, std::wstring>{
  inline static bool _cast( const int & in_value , std::wstring& out_wstr){
    std::string temp;
    _auto_cast_functor<int,std::string>::_cast(in_value,temp);
    _auto_cast_functor<std::string,std::wstring>::_cast(temp,out_wstr);
    return true;
  }
};

template <>
struct _auto_cast_functor<long, std::string>{
  inline static bool _cast(const long & a , std::string& b){
    b = __long_to_str(a);
    return true;
  }
};

template <>
struct _auto_cast_functor<long, std::wstring>{
  inline static bool _cast( const long& a , std::wstring& b){
    std::string temp;
    _auto_cast_functor<long, std::string>::_cast(a,temp);
    _auto_cast_functor<std::string, std::wstring>::_cast(temp,b);
    return true;
  }
};

template <>
struct _auto_cast_functor<float, std::string>{
  inline static bool _cast( const float & a , std::string& b){
    b = __float_to_str(a);
    return true;
  }
};

template <>
struct _auto_cast_functor<float, std::wstring>{
  inline static bool _cast(const float& a , std::wstring& b){
    std::string temp;
    _auto_cast_functor<float,std::string>::_cast(a,temp);
    _auto_cast_functor<std::string,std::wstring>::_cast(temp,b);
    return true;
  }
};

template <>
struct _auto_cast_functor<unsigned short, std::string>{
  inline static bool _cast(const unsigned short & a , std::string& b){
    b = __ushort_to_str(a);
    return true;
  }
};

template <>
struct _auto_cast_functor<unsigned short, std::wstring>{
  inline static bool _cast(const unsigned short & a , std::wstring& b){
    std::string temp;
    _auto_cast_functor<unsigned short,std::string>::_cast(a,temp);
    _auto_cast_functor<std::string,std::wstring>::_cast(temp,b);
    return true;
  }
};

template <>
struct _auto_cast_functor<short, std::string>{
  inline static bool _cast(const short & a , std::string& b){
    b = __short_to_str(a);
    return true;
  }
};

template <>
struct _auto_cast_functor<short, std::wstring>{
  inline static bool _cast(const short & a , std::wstring& b){
    std::string temp;
    _auto_cast_functor<unsigned short, std::string>::_cast(a,temp);
    _auto_cast_functor<std::string, std::wstring>::_cast(temp,b);
    return true;
  }
};


template<typename _Ty>
std::wstring __to_wstring(_Ty x){
  std::wstring ws;
  auto_cast_to(x,ws);
  return ws;
}

template<typename _Ty>
std::string __to_string(_Ty x){
  std::string s;
  auto_cast_to(x,s);
  return s;
}

template<typename _Ty>
int __to_int(_Ty x){
  int value;
  auto_cast_to(x,value);
  return value;
}

template<typename _Ty>
long __to_long(_Ty x){
  long value;
  auto_cast_to(x,value);
  return value;
}

template<typename _Ty>
long __to_long_long(_Ty x){
  long long value;
  auto_cast_to(x,value);
  return value;
}

template<typename _Ty>
__uint128_t __to_u128(_Ty x){
  __uint128_t value;
  auto_cast_to(x,value);
  return value;
}

template<typename _Ty>
float __to_float(_Ty x){
  float value;
  auto_cast_to(x,value);
  return value;
}

template<typename _Ty>
float __to_double(_Ty x){
  float value;
  auto_cast_to(x,value);
  return value;
}


} // namespace lfc
#endif // __LFC_BASE_CAST__
