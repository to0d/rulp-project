#ifndef __LFC_CAST_IMPL_CONTAINER_H__
#define __LFC_CAST_IMPL_CONTAINER_H__
#include "lfc/base/cast/cast_base.h"
#include "lfc/base/type.h"
namespace lfc {

template <typename _CA, typename _CB>
struct _auto_cast_functor<_CA, _CB, enable_if<
    MPL_AND< impl::is_container<_CA>
           , impl::is_container<_CB>
           , is_one_of<typename _CA::value_type,typename _CB::value_type>>::type>>
{

  template<typename _TC>
  struct Out_C{
    static inline void _resize(_TC& _c,unsigned long _size){
      _c.clear();
    }
  };

  template<typename _T>
  struct Out_C<std::vector<_T>>{
    static inline void _resize(std::vector<_T>& _c,unsigned long _size){
      _c.clear();
      _c.reserve(_size);
    }
  };

  typedef typename _CA::value_type value_type;

  inline static bool _cast( const _CA & in_c , _CB& out_c){
    typedef Out_C<_CB> out_c_type;
    out_c_type::_resize(out_c,in_c.size());
    typename _CA::const_iterator pos = in_c.begin();
    for (; pos != in_c.end() ; ++pos){
      out_c.push_back(*pos);
    }
    return true;

  }
};

} // namespace lfc
#endif // __LFC_CAST_IMPL_CONTAINER_H__
