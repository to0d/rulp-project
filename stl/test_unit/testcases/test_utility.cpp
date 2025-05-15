#include <gtest/gtest.h>
#include "lfc/stl/utility.h"
#include "lfc/ut/gtest_helper.h"

TEST(lfc_utility, test_move_1)
{
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

  // Test MoveConstructor
  {
    Foo_construct_count = 0;
    Foo_copy_construct_count = 0;
    Foo_move_construct_count = 0;
    Foo_move_operator_count = 0;

    Foo o1;
    o1.data = 1;
  
    EXPECT_EQ(o1.data, 1);

    Foo o2 = lfc::move(o1);
    EXPECT_EQ(o1.data, 0);
    EXPECT_EQ(o2.data, 1);

    EXPECT_EQ(Foo_construct_count, 1);
    EXPECT_EQ(Foo_copy_construct_count, 0);
    EXPECT_EQ(Foo_move_construct_count, 1);
    EXPECT_EQ(Foo_move_operator_count, 0);
  }

  // Test MoveAssignment
  {
    Foo_construct_count = 0;
    Foo_copy_construct_count = 0;
    Foo_move_construct_count = 0;
    Foo_move_operator_count = 0;

    Foo o1, o2;
    o1.data = 1;
  
    EXPECT_EQ(o1.data, 1);
    EXPECT_EQ(o2.data, 0);

    o2 = lfc::move(o1);
    EXPECT_EQ(o1.data, 0);
    EXPECT_EQ(o2.data, 1);

    EXPECT_EQ(Foo_construct_count, 2);
    EXPECT_EQ(Foo_copy_construct_count, 0);
    EXPECT_EQ(Foo_move_construct_count, 0);
    EXPECT_EQ(Foo_move_operator_count, 1);
  }

}

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

TEST(lfc_utility, test_forward_1)
{
  _forward_lvalue_count = 0;
  _forward_rvalue_count = 0;

  int a = 10;
  
  _forward_wrapper(a);  // lvalue
  EXPECT_EQ(_forward_lvalue_count, 1);
  EXPECT_EQ(_forward_rvalue_count, 0);

  _forward_wrapper(10); // rvalue
  EXPECT_EQ(_forward_lvalue_count, 1);
  EXPECT_EQ(_forward_rvalue_count, 1);

  _forward_wrapper(lfc::move(a)); // rvalue
  EXPECT_EQ(_forward_lvalue_count, 1);
  EXPECT_EQ(_forward_rvalue_count, 2);
}