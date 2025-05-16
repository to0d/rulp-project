// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "rulp/lang.h"
#include "lfc/base/string.h"
#include "lfc/base/to_string.h"
#include <optional>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <regex>
#include <cmath>

using namespace lfc;
using namespace std;

namespace lfc {

enum class FormatType{
  INVALID, BOOL, STRING, FLOAT, INT
};

struct FormatSpec {

  char        type        = '\0';                     // 类型字符 (b, s, d)
  int         width       = 0;                        // 宽度 (如20)
  int         precision   = -1;                       // 精度 (仅浮点数)
  bool        left_align  = false;                    // 是否左对齐 (-)
  bool        zero_pad    = false;                    // 是否用0填充 (0)
  std::string fmt;

};

std::optional<FormatSpec> parse_format_spec(const std::string& fmt, size_t& pos) {

  if (fmt[pos] != '%' || pos + 1 >= fmt.size()) {
    return FormatSpec();
  }

  FormatSpec spec;
  size_t i = pos + 1; // 跳过%

  // 解析标志
  while (i < fmt.size()) {
    switch (fmt[i]) {
      case '-': spec.left_align = true; break;
      case '0': spec.zero_pad = true; break;
      default: goto width_parse;
    }
    i++;
  }

width_parse:
  // 解析宽度
  while (i < fmt.size() && CHAR_IS_DIGIT(fmt[i])) {
    spec.width = spec.width * 10 + (fmt[i] - '0');
    i++;
  }

  // 解析精度
  if (i < fmt.size() && fmt[i] == '.') {
    i++;
    spec.precision = 0;
    while (i < fmt.size() && CHAR_IS_DIGIT(fmt[i])) {
      spec.precision = spec.precision * 10 + (fmt[i] - '0');
      i++;
    }
  }

  // 解析类型字符
  if (i >= fmt.size()) {
    return FormatSpec();
  }

  spec.type = fmt[i];
  i++;

  // 验证类型字符
  if (spec.type != 'b' && spec.type != 's' && spec.type != 'd' && spec.type != 'f') {
    return FormatSpec();
  }

  pos = i; // 更新位置
  return spec;
}

// 格式化单个参数
string format_arg(const string& arg, const FormatSpec& spec) {
  string result = arg;
  
  // 处理宽度
  if (spec.width > 0 && result.size() < spec.width) {
    string pad(spec.width - result.size(), spec.zero_pad ? '0' : ' ');
    
    if (spec.left_align) {
      result.append(pad);
    } 
    else {
      result.insert(0, pad);
    }
  }
  
  return result;
}

// 格式化浮点数
string format_float(double value, const FormatSpec& spec) {
  ostringstream oss;
  
  if (spec.precision >= 0) {
    oss << fixed << setprecision(spec.precision);
  }
  
  oss << value;
  string result = oss.str();
  
  // 移除多余的尾随零和小数点（如 3.14000 -> 3.14）
  if (spec.precision > 0) {
    size_t dot_pos = result.find('.');
    if (dot_pos != string::npos) {
      size_t last_non_zero = result.find_last_not_of('0');
      if (last_non_zero == dot_pos) {
        result.erase(dot_pos); // 移除小数点
      } 
      else if (last_non_zero != string::npos) {
        result.erase(last_non_zero + 1); // 移除尾随零
      }
    }
  }
  
  return format_arg(result, spec);
}

XRFACTOR_IMPL_BEGIN(XRFactorStrFormat)
  int args_size = args->size();


  ROH format = interpreter->compute(frame, args->get(1));
  auto fmt = format.get()->asString();
  std::string result;
  size_t arg_index = 2;
    
  // 正则表达式匹配浮点数格式说明符 (%[width][.precision]f)
  // std::regex float_regex(R"(%(\d*)\.?(\d*)f)");
  // std::smatch match;
  size_t i = 0;

  // std::cout << "fmt=" << fmt << "\n";

  while (i < fmt.size()) {
    // std::cout << "i=" << i << ", arg_index=" << arg_index << "\n";
    if (fmt[i] == '%') {
      size_t start = i;
      auto spec = parse_format_spec(fmt, i);

      if (!spec) {
        // 不是有效的格式说明符，直接输出%
        result += '%';
        i = start + 1;
        continue;
      }

      if (spec->type == '%') {
        // 转义百分号
        result += '%';
        continue;
      }

      if (arg_index >= args->size()) {
        throw RException("Not enough arguments for format string" + args->asString());
      }

      std::string arg;
      if (spec->type == 'f') {

        ROH obj = interpreter->compute(frame, args->get(arg_index++));
        auto type = TYPE_INDEX_OF(obj.get());
        double value;

        if(type == E_FLOAT){
          value = AS_FLOAT(obj.get())->asFloat();
        }
        else if(type == E_DOUBLE){
          value = AS_DOUBLE(obj.get())->asDouble();
        }
        else {
          throw RException("not float or double type: " + obj.get()->asString());
        }

        arg = format_float(value, *spec);

      }
      else if (spec->type == 'b') {
        ROH obj = interpreter->compute(frame, args->get(arg_index++));
        auto type = TYPE_INDEX_OF(obj.get());
        if(type != E_BOOL){
          throw RException("not bool type: " + obj.get()->asString());
        }

        std::string value = obj.get()->asString();
        arg = format_arg(value, *spec);
      }
      else if (spec->type == 's') {

        ROH obj = interpreter->compute(frame, args->get(arg_index++));
        auto type = TYPE_INDEX_OF(obj.get());
        if(type != E_STRING){
          throw RException("not string type: " + obj.get()->asString());
        }
 
        std::string value = obj.get()->asString();
        arg = format_arg(value, *spec);
      }
      else if (spec->type == 'd') {

        ROH obj = interpreter->compute(frame, args->get(arg_index++));
        auto type = TYPE_INDEX_OF(obj.get());
        std::string value;

        if(type == E_INT){
          value = TO_STR(AS_INT(obj.get())->asInteger());
        }
        else if(type == E_LONG){
          value = TO_STR(AS_LONG(obj.get())->asLong());
        }
        else {
          throw RException("not integer or long type: " + obj.get()->asString());
        }
 
        arg = format_arg(value, *spec);
      }
      else {
        throw RException(std::string("Invalid format specifier: %") + spec->type);
      }
      
      result += arg;
    } 
    else {
      result += fmt[i++];
    }
  }


  // for (size_t i = 0; i < fmt.size(); ) {
  //   if (fmt[i] == '%' && i + 1 < fmt.size()) {
      
  //     if (arg_index >= args->size()) {
  //       throw RException("Not enough arguments for format string" + args->asString());
  //     }

  //     std::string str;
  //     char specifier = fmt[i + 1];
  //     switch (specifier) {
  //       case 'b': {

  //         ROH obj = interpreter->compute(frame, args->get(arg_index++));
  //         auto type = TYPE_INDEX_OF(obj.get());
  //         if(type != E_BOOL){
  //           throw RException("not bool type: " + obj.get()->asString());
  //         }
  //         result += obj.get()->asString();
  //         i += 2;
  //         break;
  //       }
  //       case 's': {

  //         ROH obj = interpreter->compute(frame, args->get(arg_index++));
  //         auto type = TYPE_INDEX_OF(obj.get());
  //         if(type != E_STRING){
  //           throw RException("not string type: " + obj.get()->asString());
  //         }
  //         result += obj.get()->asString();
  //         i += 2;
  //         break;
  //       }
  //       case 'd': {

  //         ROH obj = interpreter->compute(frame, args->get(arg_index++));
  //         auto type = TYPE_INDEX_OF(obj.get());
  //         if(type == E_INT){
  //           result += TO_STR(AS_INT(obj.get())->asInteger());
  //         }
  //         else if(type == E_LONG){
  //           result += TO_STR(AS_LONG(obj.get())->asLong());
  //         }
  //         else {
  //           throw RException("not integer or long type: " + obj.get()->asString());
  //         }

  //         i += 2;
  //         break;
  //       }          
  //       case '%':
  //         result += '%';
  //         i += 2;
  //         break;
        
  //       default:

  //           // 检查是否是浮点数格式说明符
  //           std::string remaining = fmt.substr(i);
  //           if (std::regex_search(remaining, match, float_regex) && match.position() == 0) {

  //             ROH obj = interpreter->compute(frame, args->get(arg_index++));
  //             auto type = TYPE_INDEX_OF(obj.get());
  //           if(type == E_FLOAT){
  //             float value = AS_FLOAT(obj.get())->asFloat();
  //             str    = LFC_STR_FORMAT_BGN match.str().c_str(), value LFC_STR_FORMAT_END;
  //           }
  //           else if(type == E_DOUBLE){
  //             double value = AS_DOUBLE(obj.get())->asDouble();
  //             str    = LFC_STR_FORMAT_BGN match.str().c_str(), value LFC_STR_FORMAT_END;
  //           }
  //           else {
  //             throw RException("not integer or long type: " + obj.get()->asString());
  //           }
                        
  //           // 处理浮点数
  //           result += str;
  //           i += match.length();
  //         }
  //         else {
  //           throw RException(std::string("Invalid format specifier: %") + specifier);
  //         }
  //     }
  //   }
  //   else {
  //     result += fmt[i++];
  //   }
  // }
  
  return RulpFactory::createString(result);

XRFACTOR_IMPL_ARG(3, 11)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorStrFormat, F_STR_FORMAT);

} // namespace lfc