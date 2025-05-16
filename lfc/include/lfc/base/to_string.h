#ifndef __LFC_TO_STRING_H__
#define __LFC_TO_STRING_H__
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>


#define TO_STR(x)               lfc::to_string(x)

namespace lfc {

inline std::string to_string(char c){
  return std::string(1, c);
}

inline std::string to_string(int val){
  return std::to_string(val);
}

inline std::string to_string(float val){
  return std::to_string(val);
}

inline std::string to_string(double val){
  return std::to_string(val);
}

inline std::string to_string(int64_t val){
  return std::to_string(val);
}

inline std::string to_string(long long val){
  return std::to_string(val);
}

inline std::string to_string(size_t val){
  return std::to_string(val);
}

inline std::string to_string(__uint128_t val){

  if (val == 0) {
    return "0";
  }

  std::string rst;
  while (val > 0) {
    rst.insert(rst.begin(), '0' + (val % 10));
    val /= 10;
  }

  return rst;
}

inline const std::string& to_string(const std::string& val){
  return val;
}

template <typename T>
inline std::string to_string(const std::vector<T>& vec){
  std::string out = "{";
  int i = 0, size = vec.size();;
  for(const T& val : vec){
    out += lfc::to_string(val);
    if(++i != size)
      out += ",";
  }
  out += "}";
  return out;
}

template <typename T>
inline std::string to_string(const std::vector<std::vector<T>>& arr){
  std::string out = "{";
  int i = 0, size = arr.size();
  for(auto& vec : arr){
    out += lfc::to_string(vec);
    if(++i != size)
      out += ",";
  }
  out += "}";
  return out;
}

template <typename T>
inline std::string to_string(const std::vector<std::vector<std::vector<T>>>& arr){
  std::string out = "{";
  int i = 0, size = arr.size();;
  for(auto& vec : arr){
    out += lfc::to_string(vec);
    if(++i != size)
      out += ",";
  }
  out += "}";
  return out;
}

template <typename T>
inline std::string to_string(const std::set<T>& set){
  std::string out = "[";
  int i = 0, size = set.size();
  for(const T& val : set){
    out += lfc::to_string(val);
    if(++i != size)
      out += ",";
  }
  out += "]";
  return out;
}

template <typename T>
inline std::string to_string(const std::map<std::string, T>& map){
  std::string out = "{";

  std::vector<std::string> keys;
  for(auto it = map.begin(), end = map.end(); it != end; ++it){
    auto& k = it->first;
    keys.push_back(k);
  }

  std::sort(keys.begin(), keys.end());
  
  int i = 0, size = keys.size();
  for(const std::string& key : keys){
    const T& val = map.at(key);
    out += lfc::to_string(key);
    out += "=";
    out += lfc::to_string(val);
    if(++i != size)
      out += ",";
  }

  out += "}";
  return out;
}

} // namespace lfc
#endif // __LFC_TO_STRING_H__