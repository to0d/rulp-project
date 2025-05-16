// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_BASE_STRING_UTIL_H__
#define __LFC_BASE_STRING_UTIL_H__

#include <string>
#include <vector>
#include <memory>

#define STR_COMPARE(a, b)                 lfc::StringUtil::compare(a, b)
#define STR_END_WITH(s1, s2)              lfc::str_end_with((s1), (s2))
#define STR_INDEX_OF(s, c)                lfc::StringUtil::indexOf(s, c)
#define STR_INDEX_OF_FROM(s, c, f)        lfc::StringUtil::indexOf(s, c, f)
#define STR_IS_EMPTY(s)                   lfc::str_is_empty(s)
#define STR_IS_INT(s)                     lfc::str_is_integer(s)
#define STR_IS_FLOAT(s)                   lfc::str_is_float(s)
#define STR_TRIM(s)                       lfc::str_trim(s)
#define STR_TRIM_END_NEWLINE(s)           lfc::str_trim_end_new_line(s)
#define STR_LAST_INDEX_OF(s, c)           lfc::StringUtil::lastIndexOf(s, c)
#define STR_LAST_INDEX_OF_FROM(s, c, f)   lfc::StringUtil::lastIndexOf(s, c, f)
#define STR_REPLACE_ALL(s, f, t)          lfc::StringUtil::replaceAll(s, f, t)
#define STR_SPLIT_BY_CHAR(s, c)           lfc::StringUtil::splitStringByChar(s, c)
#define STR_SPLIT_BY_MULTI_CHAR(s1, s2)   lfc::StringUtil::splitStringMultiChars(s1, s2)
#define STR_SPLIT_BY_STR(s1, s2)          lfc::StringUtil::splitStringByStr(s1, s2)
#define STR_START_WITH(s1, s2)            lfc::str_start_With((s1), (s2))
#define STR_TO_UPPER(str)                 lfc::StringUtil::toUpper(str)
#define STR_MATCH(mode, str)              lfc::StringUtil::matchFormat(mode, str)

#define CHAR_IS_DIGIT(c)                  std::isdigit(c)
#define CHAR_TO_LOWER(c)                  std::tolower(c)

namespace lfc {

std::string str_get_empty_head(const std::string& line);

inline bool str_is_integer(const std::string& str){
  for (char c : str) {
    if (c != '-' && c != '+' && !CHAR_IS_DIGIT(c)) {
      return false;
    }
  }
  return true;
}

bool str_is_float(const std::string& str);

bool str_is_empty(const std::string& line);

bool str_start_With(const std::string& str, const std::string prefix);

bool str_end_with(const std::string& str, const std::string suffix);

std::string str_trim(const std::string& str);

std::string str_trim_end_new_line(const std::string& str);

/*********************************************************************/
// scans the first n bytes of the memory area pointed to by s for the
// character c. Does not like memchr, ch_memrchr will try to find
// the last location
/*********************************************************************/
const char *ch_memrchr(const char *s, char c, int count);

bool ch_is_empty(char c);

int simplify_path(char* path);


enum class CharType {
  NUMBER    = 0  // number
, EN_CHAR   = 10 // English char
, EN_SYMBOL = 11 // English symbol
, CN_CHAR   = 20 // Chinese char
, CN_SYMBOL = 21 // Chinese symbol
, TW_ZHUYIN = 33 // TW zhuyin
, JP_SYMBOL = 41 // JP symbol
, ROMAN_NUM = 53 // Roman number
, OTHER     = 99 // other
};

class IMatchParser {
public: 
  virtual ~IMatchParser() = default;
  virtual bool match(const std::string& content, std::vector<std::string>& values, bool ignoreCase) = 0;
};

typedef std::shared_ptr<IMatchParser> IMatchParserPtr;

class StringUtil {

public:

  static std::string addEscape(const std::string& str);

  static int compare(const std::string& a, const std::string& b);

  static CharType getCharType(wchar_t c);
  
  static CharType getCharType(char c);

  static int  indexOf(const std::string& str, char c, int from = 0);

  static int  indexOf(const std::string& str, const std::string& sub, int from = 0);  
  
  static bool isEscapeChar(char c);

  static int  lastIndexOf(const std::string& str, char c, int from = 0);

  static int  lastIndexOf(const std::string& str, const std::string& sub, int from = 0);

  static bool needEscape(char c);

  static std::string replaceAll(const std::string& str, const std::string& from, const std::string& to);

  static std::string removeEscape(const std::string& str);

  static std::vector<std::string> splitStringByChar(const std::string& line, char c);

   static std::vector<std::string> splitStringMultiChars(const std::string& line, const std::string& sep);

  static std::vector<std::string> splitStringByStr(const std::string& line, const std::string& sep);

  static std::string trimHead(const std::string& line, std::initializer_list<char> s);

  static std::string trimTail(const std::string& line, std::initializer_list<char> s);

  static std::string toUpper(const std::string& str);

  static IMatchParserPtr getMatchParser(const std::string& matchMode);

  static bool matchFormat(const std::string& matchMode, const std::string& content);

  static bool matchFormat(const std::string& matchMode, const std::string& content, std::vector<std::string>& values);

};


} // namespace lfc
#endif // __LFC_BASE_STRING_UTIL_H__