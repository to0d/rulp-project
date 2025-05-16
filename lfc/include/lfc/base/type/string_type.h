#ifndef __LFC_STRING_TYPE_H_Dec_24_2010__
#define __LFC_STRING_TYPE_H_Dec_24_2010__

#include <slfc/type/enable_if.h>
#include <slfc/type/is_xx.h>
#include <stdlib.h>
#include <string>

namespace lfc {
	namespace impl{

    template <typename T,typename Enable = void> 
    struct string_type{};

    /*template <typename T> 
    struct string_type<T,typename enable_if<typename is_a_type<typename T,char,std::string>>::type>
    {
      typedef char		char_type;
      typedef std::string	str_type;
    };*/

    /*template <typename T> 
    struct string_type<T,typename enable_if<is_a_type<typename T,wchar_t,std::wstring> >::type>
    {	
      typedef wchar_t			char_type;
      typedef std::wstring	str_type;
    };*/

	}
}

#endif // __LFC_STRING_TYPE_H_Dec_24_2010__


