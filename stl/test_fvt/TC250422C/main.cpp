#include "lfc/stl/algorithm.h"
#include "lfc/stl/math.h"
#include "lfc/stl/limits.h"
#include "lfc/stl/type_traits.h"
#include "lfc/stl/utility.h"
#include "lfc/ut/test.h"

static int _forward_lvalue_count = 0;
static int _forward_rvalue_count = 0;

void _forward_process(int& x) {
  ++_forward_lvalue_count;
}
void _forward_process(int&& x) { 
  ++_forward_rvalue_count;
}

template<typename T>
void _forward_wrapper(T&& param) {
  _forward_process(lfc::forward<T>(param));
}

int main() 
{
  RUT_START;

  RUT_TEST(lfc::abs)
  {
    RUT_RUN(lfc::abs(0.0));
    RUT_RUN(lfc::abs(3.0));
    RUT_RUN(lfc::abs(123.456));
    RUT_RUN(lfc::abs(-123.456));
  }

  RUT_TEST(lfc::ceil)
  {
    RUT_RUN(lfc::ceil(3.0));
    RUT_RUN(lfc::ceil(3.5));
    RUT_RUN(lfc::ceil(3.9));
    RUT_RUN(lfc::ceil(123456.789));
  }

  RUT_TEST(lfc::floor)
  {
    RUT_RUN(lfc::floor(3.0));
    RUT_RUN(lfc::floor(3.5));
    RUT_RUN(lfc::floor(3.9));
    RUT_RUN(lfc::floor(123456.789));
  }

  RUT_TEST(lfc::max)
  {
    RUT_RUN(lfc::max(3.0, 2.0));
    RUT_RUN(lfc::max(5, 3));
  }

  RUT_TEST(lfc::min)
  {
    RUT_RUN(lfc::min(3.0, 2.0));
    RUT_RUN(lfc::min(5, 3));
  }

  RUT_TEST(lfc::isnan)
  {
    RUT_RUN(lfc::isnan(0.0));
    RUT_RUN(lfc::isnan(3.14159));
    RUT_RUN(lfc::isnan(0.0 / 0.0));
  }

  RUT_TEST(lfc::numeric_limits)
  {
    RUT_RUN(lfc::numeric_limits<int>::max());
    RUT_RUN(lfc::numeric_limits<int>::min());
    RUT_RUN(lfc::numeric_limits<int>::epsilon());

    RUT_RUN(lfc::numeric_limits<float>::max());
    RUT_RUN(lfc::numeric_limits<float>::min());
    RUT_RUN(lfc::numeric_limits<float>::epsilon());
  }

  RUT_TEST(lfc::decay)
  {
    RUT_RUN((lfc::is_same_v<lfc::decay<int&>::type, int>));
    RUT_RUN((lfc::is_same_v<lfc::decay<const int[3]>::type, const int*>));
    RUT_RUN((lfc::is_same_v<lfc::decay<int(double)>::type, int(*)(double)>));
  }

  RUT_TEST(lfc::is_same)
  {
    RUT_RUN((lfc::is_same<float, float>::value));
    RUT_RUN((lfc::is_same<float, int>::value));
  }

  RUT_TEST(lfc::is_same_v)
  {
    RUT_RUN((lfc::is_same_v<float, float>));
    RUT_RUN((lfc::is_same_v<float, int>));
  }

  RUT_TEST(lfc::is_float_v)
  {
    RUT_RUN((lfc::is_float_v<float>));
    RUT_RUN((lfc::is_float_v<int>));
  }

  RUT_TEST(lfc::is_floating_point)
  {
    RUT_RUN((lfc::is_floating_point<float>::value));
    RUT_RUN((lfc::is_floating_point<int>::value));
  }

  RUT_TEST(lfc::is_integral_v)
  {
    RUT_RUN((lfc::is_integral_v<float>));
    RUT_RUN((lfc::is_integral_v<int>));
  }

  RUT_TEST(lfc::is_member_function_pointer)
  {
    struct Foo {
      void func() {}
      static void static_func() {}
      int data;
    };

    RUT_RUN((lfc::is_member_function_pointer<decltype(&Foo::func)>::value));
    RUT_RUN((lfc::is_member_function_pointer<decltype(&Foo::static_func)>::value));
    RUT_RUN((lfc::is_member_function_pointer<int(Foo::*)>::value));
  }

  RUT_TEST(lfc::remove_pointer)
  {
    RUT_RUN((lfc::is_same_v<lfc::remove_pointer<int*>::type, int>));
    RUT_RUN((lfc::is_same_v<lfc::remove_pointer<int* const>::type, int>));
    RUT_RUN((lfc::is_same_v<lfc::remove_pointer<int>::type, int>));
  }

  RUT_TEST(lfc::decay_t)
  {
    RUT_RUN((lfc::is_same_v<lfc::decay_t<int&>, int>));
    RUT_RUN((lfc::is_same_v<lfc::decay_t<const int[3]>, const int*>));
    RUT_RUN((lfc::is_same_v<lfc::decay_t<int(double)>, int(*)(double)>));
  }

  static int Foo_construct_count = 0;
  static int Foo_copy_construct_count = 0;
  static int Foo_move_construct_count = 0;
  static int Foo_move_operator_count  = 0;

  struct Foo {

    Foo() {
      ++Foo_construct_count;
    }

    Foo(const Foo& other) {
      ++Foo_copy_construct_count;
      this->data = other.data;
    }

    Foo(Foo&& other) {
      ++Foo_move_construct_count;
      this->data = other.data;
      other.data = 0;
    }

    Foo& operator = (Foo&& other) {
      ++Foo_move_operator_count;
      this->data = other.data;
      other.data = 0;

      return *this;
    }

    int data = 0;
  };

  RUT_TEST(lfc::move::MoveConstructor)
  {
    Foo_construct_count = 0;
    Foo_copy_construct_count = 0;
    Foo_move_construct_count = 0;
    Foo_move_operator_count = 0;

    Foo o1;
    o1.data = 1;
  
    RUT_RUN(o1.data);

    Foo o2 = lfc::move(o1);
    RUT_RUN(o1.data);
    RUT_RUN(o2.data);

    RUT_RUN(Foo_construct_count);
    RUT_RUN(Foo_copy_construct_count);
    RUT_RUN(Foo_move_construct_count);
    RUT_RUN(Foo_move_operator_count);
  }

  RUT_TEST(lfc::move::MoveAssignment)
  {
    Foo_construct_count = 0;
    Foo_copy_construct_count = 0;
    Foo_move_construct_count = 0;
    Foo_move_operator_count = 0;

    Foo o1, o2;
    o1.data = 1;
  
    RUT_RUN(o1.data);
    RUT_RUN(o2.data);

    o2 = lfc::move(o1);
    RUT_RUN(o1.data);
    RUT_RUN(o2.data);

    RUT_RUN(Foo_construct_count);
    RUT_RUN(Foo_copy_construct_count);
    RUT_RUN(Foo_move_construct_count);
    RUT_RUN(Foo_move_operator_count);
  }

  RUT_TEST(lfc::forward)
  {
    _forward_lvalue_count = 0;
    _forward_rvalue_count = 0;

    int a = 10;
    
    _forward_wrapper(a);  // lvalue
    RUT_RUN(_forward_lvalue_count);
    RUT_RUN(_forward_rvalue_count);

    _forward_wrapper(10); // rvalue
    RUT_RUN(_forward_lvalue_count);
    RUT_RUN(_forward_rvalue_count);

    _forward_wrapper(lfc::move(a)); // rvalue
    RUT_RUN(_forward_lvalue_count);
    RUT_RUN(_forward_rvalue_count);
  }

  RUT_TEST(lfc::memcpy)
  {
    char src1[] = "Hello, world!";
    char dst1[20] = {0};
    lfc::memcpy(dst1, src1, lfc::strlen(src1) + 1);

    RUT_RUN(reinterpret_cast<char*>(dst1));
  }

  RUT_TEST(lfc::memset)
  {
    char buf1[20] = "Hello, world!";
    lfc::memset(buf1, 'x', 5);

    RUT_RUN(reinterpret_cast<char*>(buf1));
  }

  RUT_TEST(lfc::strcpy)
  {
    char dest1[20];
    const char* src1 = "Hello, world!";
    lfc::strcpy(dest1, src1);

    RUT_RUN(reinterpret_cast<char*>(dest1));
  }

  RUT_TEST(lfc::strcpy)
  {
    RUT_RUN(lfc::strcmp("Hello", "Hello"));
    RUT_RUN(lfc::strcmp("Apple", "Banana"));
    RUT_RUN(lfc::strcmp("Banana", "Apple"));
  }

  RUT_FINISH;
  return 0;
}