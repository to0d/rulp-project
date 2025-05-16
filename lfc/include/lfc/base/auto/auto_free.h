#ifndef __LFC_AUTO_FREE_H__
#define __LFC_AUTO_FREE_H__
#include <memory>
#include <vector>

#include "lfc/base/auto/auto_do.h"


#define LFC_FREE(p)             lfc::_auto_free(p)
#define LFC_FREE_ARRAY(p)       lfc::_auto_free_array(p)

#define LFC_AUTO_FREE(p)        LFC_AUTO_DO([&](){ LFC_FREE(p); })
#define LFC_AUTO_FREE_ARRAY(p)  LFC_AUTO_DO([&](){ LFC_FREE_ARRAY(p); })

namespace lfc {

template<typename _T, typename Enable = void>
struct lfc_auto_free{};

template<typename _T>
struct lfc_auto_free<_T*>{
  typedef _T* pointer_type;

  inline static void free(pointer_type& ptr){
    if (ptr != 0){
      delete ptr;
      ptr = 0;
    }
  }

  inline void static free_array(pointer_type& ptr){
    if (ptr != 0){
      delete[] ptr;
      ptr = 0;
    }
  }

  inline void static free_array(std::vector<pointer_type>& arr){
    for(pointer_type ptr : arr){
      if (ptr != 0){
        delete ptr;
      }
    }
    arr.clear();
  }

};

template<typename _T>
struct lfc_auto_free<std::shared_ptr<_T>>{
  typedef std::shared_ptr<_T> pointer_type;

  inline static void free(pointer_type& ptr){
    ptr = NULL;
  }

  inline void static free_array(std::vector<pointer_type>& arr){
    for(pointer_type ptr : arr){
      ptr = NULL;
    }
    arr.clear();
  }
};



template<typename _T>
void _auto_free(_T* ptr){
  typedef lfc_auto_free<_T*> auto_free_type;
  auto_free_type::free(ptr);
}

template<typename _T>
void _auto_free(std::shared_ptr<_T> ptr){
  typedef lfc_auto_free<std::shared_ptr<_T>> auto_free_type;
  auto_free_type::free(ptr);
}

template<typename _T>
void _auto_free_array(_T* arr){
  typedef lfc_auto_free<_T*> auto_free_type;
  auto_free_type::free_array(arr);
}

template<typename _T>
void _auto_free_array(std::vector<_T*>& arr){
  typedef lfc_auto_free<_T*> auto_free_type;
  auto_free_type::free_array(arr);
}

template<typename _T>
void _auto_free_array(std::vector<std::shared_ptr<_T>>& arr){
  typedef lfc_auto_free<std::shared_ptr<_T>> auto_free_type;
  auto_free_type::free_array(arr);
}

} // namespace lfc
#endif // __LFC_AUTO_FREE_H__
