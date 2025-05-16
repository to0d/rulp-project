// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "lfc/base/cast.h"
#include "lfc/base/trace.h"
#include <cassert>
#include <stdio.h>
#include <string.h>
#include <string>
#include <codecvt>
#include <locale>

namespace lfc {

static void _to_bit(uint8_t val, char buf[10]){
  for(int i = 0; i < 8; ++i){
    buf[7-i] = '0' + (val & 1);
    val = val >> 1;
  }
  buf[8] = 0;
}

std::string __to_bit_str(uint8_t val){
  char buf[10];
  _to_bit(val, buf);
  return std::string(buf);
}

static char __hex_to_char(char v){
  if( v <= 9 ){  
    return '0' + v;
  }
  return 'A' + v - 10;
}

std::string __to_hex_str(uint64_t val){
  char buf[17];
  int len = 0;
  char* p = (char*) &val;
  for(int i = 7; i >=0; --i){
    char c = *(p+i);
    buf[len++] = __hex_to_char((c&0xF0) >> 4 );
    buf[len++] = __hex_to_char((c&0x0F) );
  }
  buf[len] = '\0';
  return std::string(buf, len);
}

static uint8_t _hex_to_int(char c){
  switch (c)  {
  case '0' : return 0;
  case '1' : return 1;
  case '2' : return 2;
  case '3' : return 3;
  case '4' : return 4;
  case '5' : return 5;
  case '6' : return 6;
  case '7' : return 7;
  case '8' : return 8;
  case '9' : return 9;
  case 'A' : return 10;
  case 'B' : return 11;
  case 'C' : return 12;
  case 'D' : return 13;
  case 'E' : return 14;
  case 'F' : return 15;  
  default:
    LFC_TRACE2("char=", std::string(1, c));
    assert(false && "invalid hex character");
  }
}

std::vector<uint8_t> __hex_str_to_bytes(const std::string& str){

  assert(str.size() % 2 == 0);

  std::vector<uint8_t> bytes;

  int len = str.size() / 2; 
  
  for(int j = 0; j < len; ++j){
    uint8_t high  = _hex_to_int(str[2*j]);
    uint8_t low   = _hex_to_int(str[2*j+1]);
    uint8_t byte = (high << 4) | low;
    bytes.push_back(byte);
  }

  return std::move(bytes);
}

double __str_to_double(const std::string& str){
  return std::stod(str.c_str());
}

float __str_to_float(const std::string& str){
  return atof(str.c_str());
}

int __str_to_int(const std::string& str){
  return atoi(str.c_str());
}

int __wstr_to_int(const std::wstring& str){
  return std::wcstol(str.c_str(), nullptr, 10);;
}

long __str_to_long(const std::string& str){
  return atol(str.c_str());
}

long long __str_to_long2(const std::string& str){
  return std::stoll(str);
}

__uint128_t __str_to_uint128(const std::string& str){
  __uint128_t result = 0;
  for (char c : str) {
    assert(c >= '0' && c <= '9' && "Invalid character");
    result = result * 10 + (c - '0');
  }
  return result;
}

long __wstr_to_long(const std::wstring& str){
  return std::wcstol(str.c_str(), nullptr, 10);
}

std::string __int_to_str(int val){
  char tmp[64]={0};
  sprintf(tmp,"%d",val);
  return std::string(tmp);
}

std::string __long_to_str(long val){
  char tmp[64]={0};
  sprintf(tmp,"%ld",val);
  return std::string(tmp);
}

std::string __float_to_str(float val){
  char tmp[64]={0};
  sprintf(tmp,"%2.2f",val);
  return std::string(tmp);
}

std::string __ushort_to_str(unsigned short val){
  char tmp[64]={0};
  sprintf(tmp,"%d",val);
  return std::string(tmp);
}

std::string __short_to_str(short val){
  char tmp[64]={0};
  sprintf(tmp,"%d",val);
  return std::string(tmp);
}


std::wstring  __str_to_wstr(const std::string& str){

#if (defined _WIN32) || (defined _WIN64)
    out_wstr.clear();
    size_t len = in_str.length();

    if(len <= 0){
      return true;
    }

    len *= 2;
    len += 1;

    wchar_t* wstr = new wchar_t[len];
    //[Mark]__LFC_AUTO_RELEASE_ARRAY(wstr);

    memset(wstr,0,len);

    if(0 == MultiByteToWideChar(GetACP(),0,in_str.c_str(),-1,wstr,(int)len)){
      return false;
    }

    out_wstr = wstr;

    if (wstr != NULL){
      delete [] wstr; //[Mark]
    }

    return true;
  
#else
    std::wstring wstr(str.size(), L' ');
    std::mbstowcs(&wstr[0], str.c_str(), str.size());
    return wstr;
#endif

}

std::string __wstr_to_str(const std::wstring& str){
#if (defined _WIN32) || (defined _WIN64)
  out_str.clear();
    size_t len = in_wstr.length();

    if( len  <= 0)
    {
      return true;
    }

    len *= 2; 
    len += 1;

    char* str = new char[len]; 
    __LFC_ASSERT__(str != NULL);			

    memset(str,0,len);

    if(0 == WideCharToMultiByte (GetACP(), 0, in_wstr.c_str(), -1, str, (int)len, NULL, NULL))
    {
      return false;
    }

    out_str = str;

    if (str != NULL)
    {
      delete [] str;
    }
    
    return true;
#else
  std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
  return converter.to_bytes(str);
#endif
}

} // namespace lfc