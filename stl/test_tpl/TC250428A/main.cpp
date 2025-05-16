#include <type_traits>
#include <cassert>
#include <cstddef>
#include <stdio.h>
#include "lfc/ut/test.h"

/**
 * @brief 定长容器包装类（类模板）
 * @tparam T 元素类型
 * @tparam N 容器大小（非类型模板参数）
 * 
 * @details 演示类型参数 + 非类型参数的组合使用
 */
template <typename T, size_t N = 10>  // 默认大小10
class FixedContainer {
public:
  // 参数化成员类型
  using value_type = T;
  using container_type = T [N];
  using reference = T&;
  using const_reference = const T&;
  using size_type = size_t;

private:
  container_type m_data;
  size_type m_size = 0;  // 当前元素数量

public:
  // 编译期获取容量
  constexpr size_type capacity() const noexcept { 
    return N; 
  }

  // 成员方法参数化
  void push_back(const value_type& value) {
    assert(m_size < N && "Container overflow");
    m_data[m_size++] = value;
  }

  // 访问元素
  reference at(size_type pos) {
    assert(pos < m_size && "Out of range");
    return m_data[pos];
  }

  const_reference at(size_type pos) const {
    assert(pos < m_size && "Out of range");
    return m_data[pos];
  }

  // 模板成员方法（嵌套参数化）
  template <typename U>
  void fill_from(const U* begin, const U* end) {
    static_assert(std::is_convertible_v<U, T>,
        "Source type must be convertible to target type");
    m_size = 0;
    for (auto it = begin; it != end && m_size < N; ++it) {
      push_back(static_cast<T>(*it));
    }
  }

  // 编译期类型检测
  void print_type_info() const {
    if constexpr (std::is_integral_v<T>) {
      printf("Container of integral type (size=%zu)\n", N);
    } 
    else if constexpr (std::is_floating_point_v<T>) {
      printf("Container of floating-point type (size=%zu)\n", N);
    }
    else {
      printf("Container of user-defined type (size=%zu)\n", N);
    }
  }
};

/**
 * @brief 类模板特化（每个bool占1bit）
 */
template <size_t N>
class FixedContainer<bool, N> {
private:
  using StorageType = unsigned char;
  static constexpr size_t BitsPerByte = 8;
  static constexpr size_t StorageSize = (N + BitsPerByte - 1) / BitsPerByte;
  using container_type = bool [StorageSize];

  container_type m_data;
  size_t m_size = 0;

public:
  void push_back(bool value) {
    assert(m_size < N && "Container overflow");
    const size_t byte_pos = m_size / BitsPerByte;
    const size_t bit_pos = m_size % BitsPerByte;
    if (value) {
      m_data[byte_pos] |= (1 << bit_pos);
    } 
    else {
      m_data[byte_pos] &= ~(1 << bit_pos);
    }
    ++m_size;
  }

  bool at(size_t pos) const {
    assert(pos < m_size && "Out of range");
    const size_t byte_pos = pos / BitsPerByte;
    const size_t bit_pos = pos % BitsPerByte;
    return (m_data[byte_pos] >> bit_pos) & 1;
  }

  // 特化专属方法
  void flip_all() {
    for (auto& byte : m_data) {
      byte ^= 0xFF;
    }
  }
};

int main() {


  RUT_START;

  RUT_TEST(FixedContainer<int>)
  {
    FixedContainer<int> intContainer;
    for (int i = 0; i < 10; ++i) {
      intContainer.push_back(i * 2);
    }
    RUT_PRINT(intContainer.at(3));
    intContainer.print_type_info(); 
  }

  RUT_TEST((FixedContainer<float, 4>))
  {
    // 模板成员方法
    double arr[] = {1.1, 2.2, 3.3};
    FixedContainer<float, 4> floatContainer;
    floatContainer.fill_from(arr, arr + 3);   // 自动转换double->float
    RUT_PRINT(floatContainer.at(0));
    floatContainer.print_type_info();    
  }

  RUT_TEST((FixedContainer<bool, 20>))
  {
    // 特化版本用法
    FixedContainer<bool, 20> boolContainer;
    boolContainer.push_back(true);
    boolContainer.push_back(false);    
    boolContainer.flip_all();  // 反转所有bit
    RUT_PRINT(boolContainer.at(0));
    // boolContainer.print_type_info();
  }

  RUT_FINISH;

}