// SPDX-FileCopyrightText: 2023 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_STL_STRING_H__
#define __LFC_STL_STRING_H__
#include "lfc/stl/type_traits.h"

namespace lfc {

/// \cond
namespace impl {

inline void
memcpy_impl( unsigned char* dst
           , const unsigned char* src
           , std::size_t count) {
  for (std::size_t i = 0; i < count; ++i) {
    dst[i] = src[i];
  }
}

} // namespace impl
/// \endcond


/**
 * @brief Copies bytes between memory areas.
 * 
 * @details The memcpy() function copies @p n bytes from memory area @p src to
 *          memory area @p dst. The memory areas must not overlap. Use memmove()
 *          if the memory areas do overlap.
 * 
 * @param dst Pointer to the destination array where the content is to be copied.
 * @param src Pointer to the source of data to be copied.
 * @param n Number of bytes to copy.
 * 
 * @return A pointer to the destination memory area (@p dst).
 * 
 * @warning Behavior is undefined if access occurs beyond the end of either array.
 *          Behavior is undefined if either pointer is null.
 */
template <typename T, typename>
T* memcpy(T* dst, const T* src, std::size_t count);

template < typename T
         , typename = lfc::enable_if_t<lfc::is_char_v<T>>>
T* memcpy(T* dst, const T* src, std::size_t count) 
{  
  // Check for null pointers
  if (!dst || !src) {
    return dst;
  }

  unsigned char* _dst = reinterpret_cast<unsigned char*>(dst);
  const unsigned char* _src = reinterpret_cast<const unsigned char*>(src);

  // For small copies, just use the simple implementation
  if (count < 16) {
    impl::memcpy_impl(_dst, _src, count);
    return dst;
  }

  // Check for pointer alignment
  if ((reinterpret_cast<std::uintptr_t>(_dst) % sizeof(std::size_t)) == 0 &&
      (reinterpret_cast<std::uintptr_t>(_src) % sizeof(std::size_t)) == 0)
  {
    // Use word-sized copies for aligned pointers
    std::size_t* d = reinterpret_cast<std::size_t*>(_dst);
    const std::size_t* s = reinterpret_cast<const std::size_t*>(_src);
    
    std::size_t num_words = count / sizeof(std::size_t);
    for (std::size_t i = 0; i < num_words; ++i) {
      d[i] = s[i];
    }
    
    // Copy remaining bytes
    std::size_t remaining = count % sizeof(std::size_t);
    if (remaining > 0) {
      impl::memcpy_impl(
          _dst + num_words * sizeof(std::size_t),
          _src + num_words * sizeof(std::size_t),
          remaining);
    }
    
  }
  else 
  {
    // Fallback to byte copy for unaligned pointers
    impl::memcpy_impl(_dst, _src, count);
  }

  return dst;
}


/**
 * @brief Computes the length of the given null-terminated character string.
 * 
 * @tparam T Character type (char, wchar_t, char16_t, or char32_t)
 * @param src Pointer to the null-terminated character string to examine
 * @return The length of the null-terminated character string pointed to by src
 * 
 * @note The behavior is undefined if src is not a pointer to a null-terminated
 *       character string. This implementation uses SFINAE to ensure it only
 *       accepts valid character types.
 */
template <typename T, typename>
std::size_t strlen(const T* src);

template < typename T
         , typename = lfc::enable_if_t<lfc::is_char_v<T>>>
std::size_t strlen(const T* src) 
{
  if (src == nullptr) {
    return 0;
  }

  const T* p = src;
  while (*p != T()) {
    ++p;
  }
    
  return p - src;
}

/// \cond
namespace impl {

// Basic padding implementation (byte granularity)
template <typename T>
void memset_impl(T* dst, T value, std::size_t count) {
  for (std::size_t i = 0; i < count; ++i) {
    dst[i] = value;
  }
}

// Align memory padding with template specialization optimization
template <typename WordT, typename CharT>
typename lfc::enable_if<
    (sizeof(WordT) > sizeof(CharT)) && 
    (sizeof(WordT) % sizeof(CharT) == 0)
>::type
memset_aligned(CharT* dst, CharT value, std::size_t count) 
{
  // Construct a fill pattern
  WordT pattern = 0;
  CharT* p = reinterpret_cast<CharT*>(&pattern);
  for (std::size_t i = 0; i < sizeof(WordT)/sizeof(CharT); ++i) {
    p[i] = value;
  }

  // Calculate the number of blocks that can be optimized
  const std::size_t word_count = count / (sizeof(WordT)/sizeof(CharT));
  WordT* word_ptr = reinterpret_cast<WordT*>(dst);
    
  // Block filling
  for (std::size_t i = 0; i < word_count; ++i) {
    word_ptr[i] = pattern;
  }

  // The rest
  const std::size_t remaining = count % (sizeof(WordT)/sizeof(CharT));
  if (remaining > 0) {
    memset_impl( dst + word_count * (sizeof(WordT)/sizeof(CharT))
               , value
               , remaining
               );
  }
}

// Memory alignment check
template <typename T>
constexpr bool is_aligned(const void* ptr) noexcept {
  return (reinterpret_cast<std::uintptr_t>(ptr) % alignof(T)) == 0;
}

} // namespace impl
/// \endcond

/**
 * @brief Fills memory with a specified byte value
 * 
 * @tparam T Character type (must be 1-byte integral type, e.g., char, unsigned char)
 * @param[in,out] dst Pointer to the destination memory block to fill
 * @param value Fill value (will be converted to type T)
 * @param count Number of bytes to fill
 * 
 * @return Pointer to the destination memory block (dst)
 * 
 * @details
 * This function provides a type-safe, optimized implementation of memory fill operation:
 * - Performs bounds checking for null pointers and zero-length requests
 * - Automatically selects optimal filling strategy based on:
 *   - Data size (uses simple loop for small blocks <16 bytes)
 *   - Memory alignment (uses word-sized operations for aligned memory)
 * - Guaranteed to preserve the exact bit pattern of the fill value
 * 
 * @note
 * - The function is SFINAE-constrained to only accept 1-byte integral types
 * - For unaligned memory or small blocks, falls back to byte-by-byte filling
 * - Value parameter follows standard memset() convention (int converted to unsigned char)
 * 
 * @warning
 * - Behavior is undefined if dst is not a valid pointer to a memory block of at least count bytes
 * - No memory overlap checking is performed (unlike memmove)
 * 
 * @see memcpy()
 * @see memmove()
 */
template <typename T>
typename lfc::enable_if<
  lfc::is_integral<T>::value && sizeof(T) == 1,
  T*
>::type
memset(T* dst, int value, std::size_t count) 
{
  if (!dst || count == 0) 
  return dst;

  const T val = static_cast<T>(value);

  if (count < 16) {
    impl::memset_impl(dst, val, count);
    return dst;
  }

  // Check the alignment and select an optimization strategy
  if (impl::is_aligned<std::uint64_t>(dst)) {
    impl::memset_aligned<std::uint64_t>(dst, val, count);
  } 
  else if (impl::is_aligned<std::uint32_t>(dst)) {
    impl::memset_aligned<std::uint32_t>(dst, val, count);
  }
  else {
    impl::memset_impl(dst, val, count);
  }

  return dst;
}

/**
 * @brief Copies a null-terminated string from source to destination
 * 
 * @tparam T Character type (char, wchar_t, etc.)
 * @param dst Pointer to destination buffer
 * @param src Pointer to source string
 * @return T* Pointer to destination buffer
 * 
 * @details Copies the null-terminated string from src to dst, including the
 *          terminating null character. Performs null pointer checks.
 * 
 * @warning The destination buffer must be large enough to contain the source
 *          string including the null terminator.
 * 
 * @code
 * char buffer[20];
 * lfc::strcpy(buffer, "Hello");
 * @endcode
 */
template <typename T>
typename lfc::enable_if<
  lfc::is_char_v<T>,
  T*
>::type
strcpy(T* dst, const T* src) 
{
  if (dst == nullptr || src == nullptr) {
    return dst;
  }
  
  T* d = dst;
  while ((*d++ = *src++) != T(0)) {
    // Copy until null terminator is encountered
  }
  
  return dst;
}

/**
 * @brief Compares two null-terminated strings
 * 
 * @tparam T Character type (char, wchar_t, etc.)
 * @param str1 First string to compare
 * @param str2 Second string to compare
 * @return int 
 *         <0 if str1 < str2
 *          0 if str1 == str2
 *         >0 if str1 > str2
 * 
 * @details Performs lexicographical comparison of two strings.
 *          Handles null pointers safely by considering them as "less than"
 *          any non-null string.
 */
template <typename T>
typename lfc::enable_if<
  lfc::is_char_v<T>, 
  int
>::type
strcmp(const T* str1, const T* str2) {
  if (str1 == str2) 
    return 0;
  
  if (str1 == nullptr) 
    return -1;
  
  if (str2 == nullptr) 
    return 1;
  
  while (*str1 && (*str1 == *str2)) {
    ++str1;
    ++str2;
  }
  
  return static_cast<int>(*str1) - static_cast<int>(*str2);
}

} // namespace lfc

#endif //__LFC_STL_STRING_H__