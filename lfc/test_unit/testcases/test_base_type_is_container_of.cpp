#include "unitest_base.h"
#include "lfc/base/type.h"

using namespace lfc;

template<typename _A, typename _B, typename Enable = void >
struct _add_impl {
  static int _add(const _A& a, const _B& b){
    return 0;
  }
};

template<typename _A, typename _B>
int add(const  _A& a, const _B& b){
  typedef _add_impl<_A, _B> _impl;
  return _impl::_add(a, b);
}

template<typename T>
struct _add_impl<T, T, typename lfc::enable_if<lfc::is_integral<T>::value>> {
  static int _add(const  T& a, const T& b){
    return (int)a + (int)b;
  }
};


// template<typename _C, typename _T>
// struct _add_impl<_C, _C, typename _type::enable_if<_type::is_container_of<_C, _T>>::type> {
//   static int _add(const  _C& a, const _T& c){
//     typedef typename _C::const_iterator _IT;
//     _IT a_begin  = a.begin();
//     _IT a_end    = a.end();
//     int val = static_cast<int> (c);
//     for(_IT pos = a_begin; pos != a_end; ++pos){
//       val += static_cast<int> (*pos);
//     }    

//     return val;
//   }
// };


TEST(base_type, is_container_of_1)
{
  const bool rc = impl::is_container_of<std::vector<int>, int>::value;
  EXPECT_EQ(true, rc);
}

// #TODO - compile fail - 2024/04/24
// TEST(base_type, is_container_of_2)
// {
//   std::vector<int> vec = {1, 2, 3};
//   int int_b = 1;
//   EXPECT_EQ(0, add(vec, int_b));
// }
