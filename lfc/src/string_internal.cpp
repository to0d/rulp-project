// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include <string.h>
#include <sstream>
#include "lfc/base/string/util.h"
namespace lfc {


std::string str_get_empty_head(const std::string& line){
  std::string head = "";
  for(char c : line){
    if( c == ' ' || c == '\t' )
      head += c;
    else
      break;
  }
  return head;
}

const char *ch_memrchr(const char *s, char c, int count){

#define MAX_CHECK_LENGTH 65535

  const char*  pStart   = (char*) s;
  const char*  pLoc     = NULL;
  const char*  pFindLoc = NULL;
  int nFindLen = 0;
  
  if( s == NULL ){
    return NULL;
  }
  
  if( count > MAX_CHECK_LENGTH ){
    count = MAX_CHECK_LENGTH;
  }
  
  pLoc = (char*) memchr( pStart, c, count);
  if( pLoc != NULL ){
    pFindLoc = pLoc;
    nFindLen = pLoc - pStart + 1;       
    while( pFindLoc != NULL && nFindLen < count ){
      pFindLoc = (char*) memchr(pStart + nFindLen, c, count - nFindLen);
      if( pFindLoc != NULL ){  
        pLoc     = pFindLoc;
        nFindLen = pFindLoc - pStart + 1;
      }
    }
  }

  return pLoc;
}


bool str_is_float(const std::string& str){
  for (char c : str) {
    if (c != '-' && c != '+' && c != '.' && !CHAR_IS_DIGIT(c)) {
      return false;
    }
  }
  return true;
}

bool str_is_empty(const std::string& line){
  int len = line.length();
  for(int i = 0; i < len; ++i){
    char c = line.at(i);
    if( ch_is_empty(c))
      continue;
    return false;
  }
  return true;
}


bool ch_is_empty(char c){
  return c == ' ' || c == '\n' || c == '\r' || c == '\t';
}

static std::string EMPTY_STR  = "";

std::string str_trim(const std::string& str){
  if(str.empty()){
    return EMPTY_STR;
  }

  int begin = 0, end = str.length() - 1;
  for( ; begin <= end; ++begin ){
    if(!ch_is_empty(str.at(begin)))
      break;
  }
  
  for( ; begin <= end; --end ){
    if(!ch_is_empty(str.at(end)))
      break;
  }

  if(begin > end)
    return EMPTY_STR;

  return str.substr(begin, end - begin + 1);
}

std::string str_trim_end_new_line(const std::string& str){
  int len = str.length();
  while(len > 0){
    if(len > 0 && str.at(len-1) == '\n'){
      --len;
      continue;
    }

    if(len > 0 && str.at(len-1) == '\r'){
      --len;
      continue;
    }
    break;
  }

  if(len == str.length())
    return str;
  
  return str.substr(0, len);
}

bool str_start_With(const std::string& str, const std::string prefix) {
  return (str.rfind(prefix, 0) == 0);
}

bool str_end_with(const std::string& str, const std::string suffix) {
  if (suffix.length() > str.length()) { 
    return false; 
  }
  
  return (str.rfind(suffix) == (str.length() - suffix.length()));
}


} // namespace lfc


