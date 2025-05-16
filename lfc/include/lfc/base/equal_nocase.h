#ifndef __LFC_EQUAL_NOCASE_H__
#define __LFC_EQUAL_NOCASE_H__

#include "lfc/base/type.h"
#include <string>
#include <ctype.h>
#include <wctype.h>

#define  __LFC_EQUAL_NOCASE(x,y) lfc::equal_nocase((x),(y))

namespace lfc {

  template<typename _A, typename _B,typename Enable = void>
  struct _auto_equal_nocase{};

  template<>
  struct _auto_equal_nocase<wchar_t, wchar_t>{
    static bool equal(wchar_t c1, wchar_t c2){
      return towupper(c1) == towupper(c2);
    }
  };

  template<>
  struct _auto_equal_nocase<char, char>{
    static bool equal(char c1, char c2){
      return toupper(c1) == toupper(c2);
    }
  };

  template<typename T>
  struct _auto_equal_nocase<T, T, 
      typename enable_if<MPL_OR< is_one_of<T, std::string>
                               , is_one_of<T, std::wstring>>::value
    >::type>{
		typedef typename T::value_type	char_type;
		typedef _auto_equal_nocase<char_type,char_type> inner_type;
    static bool equal( const T&s1, const T&s2 ){
      int size = s1.length();
      if(size != s2.length()){
        return false;
      }
      for (int i = 0; i < size; ++i){
        if (!inner_type::equal(s1[i], s2[i])){
          return false;
        }          
      }
      return true;
    }
  };
    
  template<typename T, typename C, int i>
  struct _auto_equal_nocase<T, C[i], typename enable_if<
    MPL_AND<
      MPL_OR<is_one_of<T, std::string>, is_one_of<T, std::wstring>>,
      is_one_of<typename T::value_type, C>>::value
    >::type>{
    
    static bool equal(const T& c2, const C* c1){
      return _auto_equal_nocase<T, T>::equal(T(c1), c2);
    }
  };

  template<typename _A, typename _B>
  struct _auto_equal_nocase<_A, _B, typename enable_if<
    MPL_AND<
      MPL_AND<MPL_NOT<is_one_of<_A, std::string>>
             ,MPL_NOT<is_one_of<_A, std::wstring>>>,
      MPL_OR<is_one_of<_B, std::string>, is_one_of<_B, std::wstring>>>::value>::type>{
    static bool equal(const _A& c1, const _B& c2){
      return _auto_equal_nocase<_B, _A>::equal(c2, c1);
    }
  };


  template<typename A, typename B>
  bool equal_nocase(const A& a, const B& b){
    return _auto_equal_nocase<A,B>::equal(a,b);
  }

  template<typename A, typename B>
  struct factor_compare_nocase{
    typedef _auto_equal_nocase<A,B> compare_fun;
    bool operator()(const A& a, const B& b) const{	
      return compare_fun::equal(a,b);			 
    }
  };

}

#endif // __LFC_EQUAL_NOCASE_H__

