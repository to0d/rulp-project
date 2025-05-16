// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "lfc/base/string/util.h"
#include "lfc/base/string/contant.h"
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cassert>

namespace lfc {

CharType StringUtil::getCharType(wchar_t c){

  switch (c) {
  case CN_CHAR_COMMNA:    // CN ','
  case CN_CHAR_DUN_HAO:   // CN '、'
  case CN_CHAR_PERIOD:    // '。':
  case CN_CHAR_QUESTION_MARK:   // '？'
  case CN_CHAR_EXCLAMATION:     // '！'
  case CN_CHAR_COLON:   // CN ':'
  case CN_CHAR_COLON2:  // CN '∶'
  case CN_CHAR_LEFT_BRACKET:      // CN '['
  case CN_CHAR_LEFT_PARENTHESIS:  // CN '('
  case CN_CHAR_LEFT_QUOTE:        // CN '“'
  case CN_CHAR_LEFT_SHU_MING:     // CN '<'
  case CN_CHAR_RIGHT_BRACKET:     // CN ']'
  case CN_CHAR_RIGHT_PARENTHESIS: // CN ')'
  case CN_CHAR_RIGHT_QUOTE:       // CN '”'
  case CN_CHAR_RIGHT_SHU_MIN:     // CN '>'
  case CN_CHAR_SEMICOLON:         // CN ';'
  case CN_CHAR_LEFT_KUOHU:        // CN '「'
  case CN_CHAR_RIGHTT_KUOHU:      // CN '」'
  case CN_CHAR_LEFT_PIE:          // CN '‘'
  case CN_CHAR_RIGHTT_PIE:        // CN '’'
  case CN_CHAR_LONG_HORIZONTAL_LINE:  // CN '━'
  case CN_CHAR_LONG_HORIZONTAL_LINE2: // CN '─'
  case CN_CHAR_UNAME_1:         // CN '○'
  case CN_CHAR_UNAME_2:         // CN '×'
  case CN_CHAR_UNAME_4:         // CN '□'
  // case CN_CHAR_UNAME_5:         // CN '~'
  case CN_CHAR_UNAME_6:         // CN '◆'
  case CN_CHAR_UNAME_7:         // CN '●'
  case CN_CHAR_UNAME_8:         // CN '■'
  case CN_CHAR_UNAME_9:         // CN '℃'
  case CN_CHAR_UNAME_10:        // CN '⊙'
  case CN_CHAR_UNAME_11:        // CN '▲'
  case CN_CHAR_UNAME_12:        // CN '▼'
  case CN_CHAR_UNAME_13:        // CN 'Χ'
  case CN_CHAR_UNAME_14:        // CN '★'
  case CN_CHAR_UNAME_15:        // CN 'о'
  case CN_CHAR_UNAME_16:
  case CN_CHAR_UNAME_17:
  case CN_CHAR_UNAME_18:
  case CN_CHAR_UNAME_19:
  case CN_CHAR_UNAME_21:
  case CN_CHAR_UNAME_22:
  case CN_CHAR_UNAME_23:
  case CN_CHAR_UNAME_24:
  case CN_CHAR_UNAME_25:
  case CN_CHAR_UNAME_26:
  case CN_CHAR_UNAME_27:
  case CN_CHAR_UNAME_28:
  case CN_CHAR_UNAME_29:
  case CN_CHAR_UNAME_30:
  case CN_CHAR_UNAME_31:
  case CN_CHAR_UNAME_32:
    return CharType::CN_SYMBOL;

  default:

    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
      return CharType::EN_CHAR;
    }

    if (c >= '0' && c <= '9') {
      return CharType::NUMBER;
    }

    if ((c >= 0x21 && c <= 0x2f) || (c >= 0x3a && c <= 0x40) || (c >= 0x5b && c <= 0x60)
        || (c >= 0x7b && c <= 0x7e)) {
      return CharType::EN_SYMBOL;
    }

    if(c == EN_SEPARATION_DOT){
      return CharType::EN_SYMBOL;
    }

    if (c >= 0x2160 && c <= 0x216b) {
      return CharType::ROMAN_NUM;
    }

    if (c >= 0x3105 && c <= 0x312d) {
      return CharType::TW_ZHUYIN;
    }

    if (c >= 0x3041 && c <= 0x3096) {
      return CharType::JP_SYMBOL;
    }

    // #TODO: how to porting this

    // Character.UnicodeBlock ub = Character.UnicodeBlock.of(c);
    // if (ub == Character.UnicodeBlock.CJK_UNIFIED_IDEOGRAPHS
    //     || ub == Character.UnicodeBlock.CJK_COMPATIBILITY_IDEOGRAPHS
    //     || ub == Character.UnicodeBlock.CJK_UNIFIED_IDEOGRAPHS_EXTENSION_A
    //     || ub == Character.UnicodeBlock.CJK_UNIFIED_IDEOGRAPHS_EXTENSION_B
    //     || ub == Character.UnicodeBlock.CJK_SYMBOLS_AND_PUNCTUATION
    //     || ub == Character.UnicodeBlock.HALFWIDTH_AND_FULLWIDTH_FORMS
    //     || ub == Character.UnicodeBlock.GENERAL_PUNCTUATION) {
    //   return CharType.CN_CHAR;
    // }
  }

  return CharType::OTHER;

}

int StringUtil::compare(const std::string& a, const std::string& b){
  int d = a.compare(b);
  if( d == 0 )
    return 0;
  return d > 0 ? 1 : -1;
}

CharType StringUtil::getCharType(char c){

  switch (c) {

  case EN_SEPARATION_DOT: // '·'
  case EN_CHAR_UNAME_5  : // CN '~'
    return CharType::EN_SYMBOL;

  default:

    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
      return CharType::EN_CHAR;
    }

    if (c >= '0' && c <= '9') {
      return CharType::NUMBER;
    }

    if ((c >= 0x21 && c <= 0x2f) || (c >= 0x3a && c <= 0x40) || (c >= 0x5b && c <= 0x60)
        || (c >= 0x7b && c <= 0x7e)) {
      return CharType::EN_SYMBOL;
    }

  }

  return CharType::OTHER;
}

bool StringUtil::needEscape(char c){
  switch (c) {
  case '\\':
  case '"':
    return true;
  }

  return false;
}

std::string StringUtil::addEscape(const std::string& str){
  std::string* sb = NULL;
  int size = str.length();

  for (int i = 0; i < size; ++i) {
    char c = str[i];
    if (needEscape(c)) {
      if (sb == NULL) {
        sb = new std::string();
        if (i > 0) {
          *sb += str.substr(0, i);
        }
      }
      *sb += '\\';
    }

    if (sb != NULL) {
      *sb += c;
    }
  }

  if(sb == NULL){
    return str;
  }

  std::string rst = *sb;
  delete sb;
  return rst;
}

bool StringUtil::isEscapeChar(char c){
  switch (c) {
  case '\\':
  case 'n':
  case 'r':
  case '"':
    return true;
  }
  return false;
}

static char convertEscapeCharToReal(char c) {

  switch (c) {
  case 'n':
    return '\n';

  case 'r':
    return '\r';

  default:
    return c;
  }
}

std::string StringUtil::replaceAll(const std::string& str, const std::string& from, const std::string& to) {
  std::string result;
  size_t start_pos = 0;
  size_t found_pos;
  while ((found_pos = str.find(from, start_pos)) != std::string::npos) {
      result.append(str, start_pos, found_pos - start_pos); // 添加未匹配部分
      result += to; // 添加替换字符串
      start_pos = found_pos + from.length(); // 更新查找起始位置
  }
  result.append(str, start_pos, str.length() - start_pos); // 添加剩余部分
  return result;
}

std::string StringUtil::removeEscape(const std::string& value){
  char buf[256];
  int pos = 0, size = value.length(), update = 0;
  char* tmp = buf;
  if(size*2 > sizeof(buf)){
    int buf_size = 2*size;
    tmp = (char*) malloc(buf_size);
    assert(tmp && "invalid tmp pointer");
  }

  for (int i = 0; i < size; ++i) {
    char c = value.at(i);
    if ((i + 1) < size && c == '\\') {
      char c2 = value.at(i + 1);
      if (isEscapeChar(c2)) {       
        c2 = convertEscapeCharToReal(c2);
        tmp[pos++] = c2;
        ++update;
      } 
      else {
        tmp[pos++] = c;
        tmp[pos++] = c2;
      }
      ++i;
    } 
    else{
      tmp[pos++] = c;
    }
  }

  tmp[pos] = 0;
  if(update == 0)
    return value;

  std::string rst = std::string(tmp, pos);
  if(tmp != buf){
    free(tmp);
  }

  return rst;
}

std::vector<std::string> StringUtil::splitStringByChar(const std::string& line, char c){
  std::vector<std::string> vars;
  std::stringstream ss(line);
  std::string var;
  while (getline(ss, var, c)) {
    if(!var.empty())
      vars.push_back(var);
  }
  return vars;
}

std::vector<std::string> StringUtil::splitStringMultiChars(const std::string& input, const std::string& s){

  if (input.empty()) {
    return {};
  }
  
  if (s.length() == 0) {
    return {input};
  }

  char cmap[256] = {0};
  for(char c : s){
    cmap[c]++;
  }

  std::vector<std::string> subStrs;

  std::stringstream ss;
  for(char c : input) {
    if(cmap[c] > 0){
      auto sub = ss.str();
      if(!sub.empty()){
        subStrs.push_back(sub);
      }
      ss.str("");
    }
    // Separator character not found
    else {
      ss << c;
    }
  }

  auto sub = ss.str();
  if(!sub.empty()){
    subStrs.push_back(sub);
  }

  return subStrs;
}


int StringUtil::indexOf(const std::string& str, char c, int from){
  if(from >= str.length()){
    return -1;
  }

  if(from < 0){
    from = 0;
  }

  auto pos = str.find_first_of(c, from);
  if(pos == std::string::npos){
    return -1;
  }

  return pos;
}

int StringUtil::indexOf(const std::string& str, const std::string& sub, int from){
  auto pos = str.find(sub, from);
  if(pos == std::string::npos){
    return -1;
  }

  return pos;
}

int StringUtil::lastIndexOf(const std::string& str, char c, int from){
  if(from < 0){
    return -1;
  }

  if(from == 0){
    from = str.length();
  }
  else if(from >= str.length()){
    from = str.length();
  }

  for(; from > 0; --from){
    if(str[from-1] == c){
      return from-1;
    }
  }

  return -1;
}

int StringUtil::lastIndexOf(const std::string& str, const std::string& sub, int from){
  if(from < 0){
    return -1;
  }

  if(from == 0){
    from = str.length();
  }
  else if(from >= str.length()){
    from = str.length();
  }

  auto pos = str.rfind(sub, from);
  if(pos == std::string::npos){
    return -1;
  }

  return pos;
}

std::vector<std::string> StringUtil::splitStringByStr(const std::string& input, const std::string& sep){
  if (input.empty()) {
    return {};
  }
  if (sep.length() == 0) {
    return {input};
  }

  std::vector<std::string> subStrs;

  std::string line = input;
  int sep_len = sep.length();

  while (!line.empty()) {
    int mPos = STR_INDEX_OF(line, sep);
    if (mPos > 0) {
      subStrs.push_back(line.substr(0, mPos));
      line = line.substr(mPos + sep_len);
    } 
    else {
      subStrs.push_back(line);
      line = "";
    }
  }

  return subStrs;
}

std::string StringUtil::trimHead(const std::string& line, std::initializer_list<char> s){
  if (s.size() == 0) {
    return line;
  }

  int slen = s.size();
  int pos = 0;

  for (; pos < line.length(); ++pos) {

    bool found = false;
    char c = line.at(pos);
    for (int i = 0; i < slen; ++i) {
      // trim
      if (c == *(s.begin() + i)) {
        found = true;
        break;
      }
    }

    if(found)
      continue;

    // not found any character
    break;
  }

  return line.substr(pos);
}

std::string StringUtil::trimTail(const std::string& line, std::initializer_list<char> s){

  if (s.size() == 0) {
    return line;
  }

  int slen = s.size();
  int pos = line.length() - 1;

  for (; pos >= 0; --pos) {

    bool found = false;
    char c = line.at(pos);
    for (int i = 0; i < slen; ++i) {
      // trim
      if (c == *(s.begin() + i)) {
        found = true;
        break;
      }
    }

    if(found)
      continue;

    // not found any character
    break;
  }

  return line.substr(0, pos + 1);
}

std::string StringUtil::toUpper(const std::string& str){
  bool found = false;
  for(char c : str){
    if(std::islower(c)){
      found = true;
      break;
    }
  }

  if(!found){
    return str;
  }

  char* buf = new char[str.size() + 1];
  char* p = buf;
  std::transform(str.begin(), str.end(), p, ::toupper);
  std::string new_str(buf, str.size());
  delete []buf;
  return new_str;
}

} // namespace lfc