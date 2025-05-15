#ifndef __LFC_STL_TYPE_TRAITS_H__
#define __LFC_STL_TYPE_TRAITS_H__
#include <cstddef>

#define mpl_false_type            lfc::impl::mpl_false
#define mpl_true_type             lfc::impl::mpl_true
#define MPL_VAR                   inline constexpr
#define MPL_TYPE_DEC(T)           template<typename> struct T : public mpl_false_type {};
#define MPL_TYPE_SPE(A, B)        template<> struct A<B> : public mpl_true_type {};
#define MPL_TYPE_SP2(A, B)        MPL_TYPE_SPE(A, B) MPL_TYPE_SPE(A, unsigned B)
#define MPL_TYPE_VAR(A)           template<typename T> MPL_VAR bool A##_v = A<T>::value; 
#define MPL_OR                    lfc::impl::mpl_or
#define MPL_AND                   lfc::impl::mpl_and
#define MPL_NOT                   lfc::impl::mpl_not

namespace lfc {

/// \cond

template<bool, typename T = void>
  struct enable_if
  {};

template<typename T>
  struct enable_if<true, T>
  { using type = T; };

template<bool C, typename T = void>
  using enable_if_t = typename lfc::enable_if<C, T>::type;

template<bool C, typename T, typename F>
  struct conditional
  { typedef T type; };

template<typename T, typename F>
  struct conditional<false, T, F>
  { typedef F type; };
  
template<bool C, typename T, typename F>
  using conditional_t = typename lfc::conditional<C, T, F>::type;

/// \endcond

/// \cond
namespace impl {

template <typename _Ty, _Ty val>
struct mpl_constant{
  typedef mpl_constant<_Ty, val>  type;
  typedef _Ty                     value_type;
  static const _Ty value = val;
};

typedef mpl_constant<bool, true>  mpl_true;
typedef mpl_constant<bool, false> mpl_false;

template<typename...>
  struct mpl_or;

template<>
  struct mpl_or<>
  : public mpl_false_type
  {};

template<typename T>
  struct mpl_or<T>
  : public T
  {};

template<typename T1, typename T2>
  struct mpl_or<T1, T2>
  : public conditional<T1::value, T1, T2>::type
  {};

template<typename T1, typename T2, typename T3, typename... Tn>
  struct mpl_or<T1, T2, T3, Tn...>
  : public conditional<T1::value, T1, mpl_or<T2, T3, Tn...>>::type
  {};

template<typename...>
  struct mpl_and;

template<>
  struct mpl_and<>
  : public mpl_true_type
  {};

template<typename T>
  struct mpl_and<T>
  : public T
  {};

template<typename T1, typename T2>
  struct mpl_and<T1, T2>
  : public conditional<T1::value, T2, T1>::type
  {};

template<typename T1, typename T2, typename T3, typename... Tn>
  struct mpl_and<T1, T2, T3, Tn...>
  : public conditional<T1::value, mpl_and<T2, T3, Tn...>, T1>::type
  {};

template<bool v>
  using mpl_bool_constant = impl::mpl_constant<bool, v>;

template<typename T>
  struct mpl_not : public mpl_bool_constant<!bool(T::value)>
  {};

template<int I> 
struct mpl_int : public mpl_constant<int, I>{};

} // namespace impl
/// \endcond

/**
 * @brief Determines if two types are the same.
 *
 * @tparam T The first type to compare
 * @tparam U The second type to compare
 *
 * @impls
 * Provides the member constant `value` that is equal to `true` if `T` and `U` 
 * are the same type, otherwise `value` is `false`. This is a fundamental type 
 * trait used extensively in template metaprogramming.
 *
 * The comparison is strict - types must be identical, including:
 * - No decay (arrays don't match pointers)
 * - No removal of cv-qualifiers (const T doesn't match T)
 * - No conversion between similar types (int doesn't match long even if same size)
 *
 * @note
 * - Part of the <lfc/stl/type_traits.h> header
 * - Inherits from std::integral_constant (either std::mpl_true_type or std::mpl_false_type)
 * - Can be used in static_assert expressions and SFINAE contexts
 * - Available since C++11
 *
 * @see lfc::decay
 *
 * @code
 * #include <lfc/stl/type_traits.h>
 * #include <iostream>
 *
 * int main() {
 *     std::cout << lfc::is_same<int, int>::value << '\n';    // true
 *     std::cout << lfc::is_same<int, long>::value << '\n';   // false
 *     std::cout << lfc::is_same<int, int const>::value << '\n';  // false
 *     std::cout << lfc::is_same<int[4], int*>::value << '\n';    // false
 * }
 * @endcode
 */
template<typename T, typename U>
  struct is_same;

/// \cond

template<typename T, typename U>
  struct is_same 
  : public mpl_false_type
  {};

template<typename T>
  struct is_same<T, T> 
  : public mpl_true_type 
  {};
/// \endcond

/// \cond
template <typename X, typename... Args>
struct is_one_of : mpl_false_type {};

template <typename X, typename... Args>
struct is_one_of<X, X, Args...> : mpl_true_type {};

template <typename X, typename A, typename... Args>
struct is_one_of<X, A, Args...> : is_one_of<X, Args...> {};
/// \endcond

/**
 * @brief Compile-time type identity checker (variable template).
 * 
 * @tparam T The first type to compare.
 * @tparam U The second type to compare.
 * 
 * @value `true` if `T` and `U` are the same type (ignoring top-level cv-qualifiers),
 *        `false` otherwise.
 *
 * @impls
 * This variable template is the shorthand for `is_same<T, U>::value` and provides
 * a convenient way to perform compile-time type comparison. It is functionally
 * equivalent to:
 * @code
 * (T is the same type as U)
 * @endcode
 * 
 * @note
 * - Works even with incomplete types or types without RTTI.
 * - Ignores top-level `const`/`volatile` qualifiers (e.g., `int` == `const int`).
 * - Available since C++17 as part of the type traits library.
 *
 * @see std::is_same
 *
 * @code
 * // Basic usage
 * static_assert(is_same_v<int, int>);
 * static_assert(!is_same_v<int, double>);
 *
 * // Ignores cv-qualifiers
 * static_assert(is_same_v<int, const int>);
 * @endcode
 */
template <typename T, typename U>
  MPL_VAR
  bool is_same_v = lfc::is_same<T, U>::value;

template<typename T>
  MPL_VAR
  bool is_float_v =
         lfc::is_same_v<T, float> 
      || lfc::is_same_v<T, double>
      || lfc::is_same_v<T, long double>
      ;

template<typename T>
  MPL_VAR
  bool is_bool_v = lfc::is_same_v<T, bool>;

/// \cond
namespace impl {

  template<typename T>
    struct remove_const
    { typedef T     type; };

  template<typename T>
    struct remove_const<T const>
    { typedef T     type; };

  template<typename T>
    struct remove_volatile
    { typedef T     type; };

  template<typename T>
    struct remove_volatile<T volatile>
    { typedef T     type; };

  template<typename T>
    struct remove_cv
    { typedef typename remove_const<typename remove_volatile<T>::type>::type type; };

  template<typename T>
    using mpl_remove_cv_t = typename remove_cv<T>::type;

} // namespace impl
/// \endcond

/// \cond
namespace impl {

MPL_TYPE_DEC(mpl_is_integer);
MPL_TYPE_SPE(mpl_is_integer, bool);
MPL_TYPE_SP2(mpl_is_integer, char);
MPL_TYPE_SPE(mpl_is_integer, signed char);
MPL_TYPE_SP2(mpl_is_integer, short);
MPL_TYPE_SP2(mpl_is_integer, int);
MPL_TYPE_SP2(mpl_is_integer, long);
MPL_TYPE_SP2(mpl_is_integer, long long);

} // namespace impl
/// \endcond

template<typename T>
  struct is_integral;

/// \cond

template<typename T>
  struct is_integral
  : public impl::mpl_is_integer<typename impl::remove_cv<T>::type>::type 
  {};

MPL_TYPE_VAR(is_integral)

/// \endcond

/// \cond
namespace impl {

MPL_TYPE_DEC(mpl_is_float);
MPL_TYPE_SPE(mpl_is_float, float);
MPL_TYPE_SPE(mpl_is_float, double);
MPL_TYPE_SPE(mpl_is_float, long double);

} // namespace impl
/// \endcond

/**
 * @brief Checks whether a type is a floating-point type.
 * 
 * @tparam T The type to check.
 * 
 * This metafunction provides a boolean constant `value` that is `true` if `T` is 
 * a floating-point type (i.e., `float`, `double`, or `long double`), and `false` otherwise.
 * 
 * The implementation follows the same rules as the C++ standard library's 
 * `std::is_floating_point` type trait.
 * 
 * @note This is a type trait and should be used at compile-time.
 * 
 * Example usage:
 * @code
 * static_assert(lfc::is_floating_point<double>::value, "double is floating point");
 * static_assert(!lfc::is_floating_point<int>::value, "int is not floating point");
 * @endcode
 */
template<typename T>
  struct is_floating_point;

/// \cond

template<typename T>
  struct is_floating_point
  : public impl::mpl_is_float<typename impl::remove_cv<T>::type>::type 
  {};

/// \endcond

template<typename T>
  struct is_arithmetic;

/// \cond

template<typename T>
  struct is_arithmetic
  : public MPL_OR<is_integral<T>, is_floating_point<T>>::type 
  {};

namespace impl {

template<typename T, bool = is_arithmetic<T>::value>
  struct _mpl_is_signed 
  : public mpl_false_type 
  {};

template<typename T>
  struct _mpl_is_signed<T, true> 
  : public mpl_constant<bool, T(-1) < T(0)> 
  {};

template<typename T>
  struct mpl_is_signed 
  : public _mpl_is_signed<T>::type 
  {};

template<typename T>
  struct mpl_is_unsigned 
  : public MPL_AND<is_arithmetic<T>, mpl_not<mpl_is_signed<T>>> 
  {};

} // namespace impl
/// \endcond

/// \cond

template <typename T>
  MPL_VAR
  bool is_unsigned_v = impl::mpl_is_unsigned<T>::value;

template <typename T>
  MPL_VAR
  bool is_arithmetic_v = is_arithmetic<T>::value;

/// \endcond

/// \cond
namespace impl {

template<typename>
  struct is_const
  : public mpl_false_type 
  {};

template<typename T>
  struct is_const<T const>
  : public mpl_true_type 
  {};

template<typename T>
  struct is_function
  : public impl::mpl_bool_constant<!is_const<const T>::value> {};

template<typename>
  struct mpl_is_mbr_func
  : public mpl_false_type 
  {};

template<typename F, typename C>
  struct mpl_is_mbr_func<F C::*>
  : public is_function<F>::type 
  {};

} // namespace impl
/// \endcond

/**
 * @brief Checks whether a type is a pointer to non-static member function
 * 
 * @tparam T The type to check
 * 
 * This template provides a compile-time boolean constant `value` that is:
 * - `true` if `T` is a pointer to non-static member function
 * - `false` for all other types (including pointers to static member functions,
 *   pointers to data members, and regular function pointers)
 * 
 * The implementation follows the C++ standard library specification for
 * member function pointer detection, properly handling all cv-qualified and
 * ref-qualified member functions.
 * 
 * @note This differs from `std::is_member_function_pointer` in that it:
 *       - Is part of the `lfc` namespace
 *       - May provide additional implementation-specific guarantees
 * 
 * Example usage:
 * @code
 * struct Foo {
 *     void func() {}
 *     static void static_func() {}
 *     int data;
 * };
 * 
 * static_assert(lfc::is_member_function_pointer<decltype(&Foo::func)>::value);
 * static_assert(!lfc::is_member_function_pointer<decltype(&Foo::static_func)>::value);
 * static_assert(!lfc::is_member_function_pointer<int(Foo::*)>::value); // data member pointer
 * @endcode
 * 
 * @see std::is_member_function_pointer
 * @see lfc::is_member_object_pointer
 * @see lfc::is_member_pointer
 */
template<typename T>
  struct is_member_function_pointer;

/// \cond
template<typename T>
  struct is_member_function_pointer
  : public impl::mpl_is_mbr_func<impl::mpl_remove_cv_t<T>>::type
  {};
/// \endcond

/// \cond
namespace impl {

template<typename T, typename>
  struct mpl_remove_ptr
  { typedef T     type; };

template<typename T, typename U>
  struct mpl_remove_ptr<T, U*>
  { typedef U     type; };

} // namespace impl
/// \endcond

/**
 * @brief Removes pointer qualification from a type
 * 
 * @tparam T The type to remove pointer qualification from
 * 
 * This template provides a member typedef `type` that removes the top-level pointer
 * from the given type:
 * - If `T` is of the form `U*`, then `type` is `U`
 * - If `T` is of the form `U* const`, `U* volatile`, or `U* const volatile`, 
 *   then `type` is `U` (cv-qualifiers on the pointer itself are removed)
 * - Otherwise, `type` is `T` unchanged
 * 
 * The implementation first removes cv-qualifiers before checking for pointer types
 * to properly handle all qualified pointer cases.
 * 
 * @note This differs from `std::remove_pointer` in that it:
 *       - Is part of the `lfc` namespace
 *       - May provide additional implementation-specific guarantees
 * 
 * Example usage:
 * @code
 * static_assert(std::is_same_v<lfc::remove_pointer<int*>::type, int>);
 * static_assert(std::is_same_v<lfc::remove_pointer<int* const>::type, int>);
 * static_assert(std::is_same_v<lfc::remove_pointer<int>::type, int>);
 * @endcode
 * 
 * @see std::remove_pointer
 * @see lfc::remove_cv
 * @see lfc::remove_reference
 */
template<typename T>
  struct remove_pointer;

/// \cond
template<typename T>
  struct remove_pointer
  : public impl::mpl_remove_ptr<T, typename impl::remove_cv<T>::type>
  {};
/// \endcond

/**
 * @brief Convenience alias template for remove_pointer<T>::type
 * 
 * @tparam T The type to remove pointer qualification from
 * 
 * This is a template alias that provides a shorter syntax for accessing the 
 * result of `remove_pointer<T>`. Equivalent to:
 * @code
 * typename remove_pointer<T>::type
 * @endcode
 * 
 * Introduced following the C++14 standard library's convention of `_t` suffix
 * alias templates for type traits.
 * 
 * Example usage:
 * @code
 * lfc::remove_pointer_t<int*> x = 42;  // x has type int
 * @endcode
 * 
 * @see lfc::remove_pointer
 */
template<typename T>
  using remove_pointer_t = typename remove_pointer<T>::type;

/// \cond
namespace impl {

template<typename>
  struct is_array
  : public mpl_false_type 
  {};

template<typename T, std::size_t S>
  struct is_array<T[S]>
  : public mpl_true_type
  {};

template<typename T>
  struct is_array<T[]>
  : public mpl_true_type
  {};

template<typename T>
  struct remove_reference
  { typedef T   type; };

template<typename T>
  struct remove_reference<T&>
  { typedef T   type; };

template<typename T>
  struct remove_reference<T&&>
  { typedef T   type; };

template<typename T,
    bool _IsArray = is_array<T>::value,
    bool _IsFunction = is_function<T>::value>
  struct __decay_selector;

template<typename>
  struct is_reference;

template<typename>
  struct is_lvalue_reference
  : public mpl_false_type 
  {};

template<typename T>
  struct is_lvalue_reference<T&>
  : public mpl_true_type 
  {};

template<typename>
  struct is_rvalue_reference
  : public mpl_false_type 
  {};

template<typename T>
  struct is_rvalue_reference<T&&>
  : public mpl_true_type 
  {};

template<typename T>
  struct is_reference
  : public MPL_OR<is_lvalue_reference<T>, is_rvalue_reference<T>>::type
  {};

template<typename T>
  struct is_object;

template<typename T>
  struct _is_referenceable
  : public MPL_OR<is_object<T>, is_reference<T>>::type
  {};

template<typename R, typename... A >
  struct _is_referenceable<R(A...) >
  : public mpl_true_type
  {};

template<typename>
  struct _is_void_helper
  : public mpl_false_type 
  {};

template<>
  struct _is_void_helper<void>
  : public mpl_true_type
  {};

template<typename T>
  struct is_void
  : public _is_void_helper<typename impl::remove_cv<T>::type>::type
  {};

template<typename T, bool = MPL_OR<_is_referenceable<T>, is_void<T>>::value>
  struct _add_pointer_helper
  { typedef T     type; };

template<typename T>
  struct is_object
  : public MPL_OR<MPL_OR<is_function<T>, is_reference<T>, is_void<T>>>::type
  {};

template<typename T>
  struct _add_pointer_helper<T, true>
  { typedef typename remove_reference<T>::type* type; };

template<typename T>
  struct add_pointer
  : public _add_pointer_helper<T>
  {};

template<typename T>
  struct remove_extent
  { typedef T     type; };

template<typename T, std::size_t S>
  struct remove_extent<T[S]>
  { typedef T     type; };

template<typename T>
  struct remove_extent<T[]>
  { typedef T     type; };

template<typename T>
  struct __decay_selector<T, false, false>
  { typedef typename impl::remove_cv<T>::type __type; };

template<typename T>
  struct __decay_selector<T, true, false>
  { typedef typename remove_extent<T>::type* __type; };

template<typename T>
  struct __decay_selector<T, false, true>
  { typedef typename add_pointer<T>::type __type; };

} // namespace impl
/// \endcond

/**
 * @brief Performs type decay transformation
 * 
 * @tparam T The type to apply decay transformation to
 * 
 * This template provides a member typedef `type` that applies the following transformations:
 * 1. Removes reference qualifiers (both lvalue and rvalue)
 * 2. Converts array types to pointer types
 * 3. Converts function types to function pointer types
 * 4. Removes top-level cv-qualifiers (const/volatile)
 * 
 * The transformation follows the same rules as argument passing in function calls by value.
 * 
 * @note Compared to std::decay, this implementation:
 *       - Belongs to lfc namespace
 *       - May provide additional guarantees for implementation-specific types
 * 
 * Typical use cases:
 * - Simulating pass-by-value type conversion in templates
 * - Storing values in generic containers
 * - Type normalization in metaprogramming
 * 
 * Example usage:
 * @code
 * static_assert(lfc::is_same_v<lfc::decay<int&>::type, int>);
 * static_assert(lfc::is_same_v<lfc::decay<const int[3]>::type, const int*>);
 * static_assert(lfc::is_same_v<lfc::decay<int(double)>::type, int(*)(double)>);
 * @endcode
 * 
 * @see lfc::decay
 * @see lfc::remove_reference
 * @see lfc::remove_cv
 */
template<typename T>
  class decay;

/// \cond
template<typename T>
  class decay
  {
    typedef typename impl::remove_reference<T>::type __remove_type;
  public:
    typedef typename impl::__decay_selector<__remove_type>::__type type;
  };
/// \endcond

/**
 * @brief Convenience alias for lfc::decay<T>::type
 * 
 * @tparam T The type to apply decay transformation to
 * 
 * Provides a concise syntax for accessing the decayed type.
 * Equivalent to typename lfc::decay<T>::type but more readable.
 * 
 * Following C++14 standard library convention for type trait aliases.
 * 
 * Example usage:
 * @code
 * lfc::decay_t<int&&> x = 42;  // x has type int
 * @endcode
 */
template<typename T>
  using decay_t = typename decay<T>::type;

/// \cond
namespace impl {

template<typename T, typename>
  struct is_complete
  : public mpl_false_type
  {};

template<typename T>
  struct is_complete<T, decltype(void(sizeof(T)))> 
  : public mpl_true_type
  {};
  
template<typename>
  struct is_volatile
  : public mpl_false_type
  {};

template<typename T>
  struct is_volatile<T volatile>
  : public mpl_true_type
  {};

MPL_TYPE_DEC(has_trivial_copy);
MPL_TYPE_SPE(has_trivial_copy, char);
MPL_TYPE_SPE(has_trivial_copy, signed char);
MPL_TYPE_SPE(has_trivial_copy, unsigned char);
MPL_TYPE_SPE(has_trivial_copy, short);
MPL_TYPE_SPE(has_trivial_copy, unsigned short);
MPL_TYPE_SPE(has_trivial_copy, int);
MPL_TYPE_SPE(has_trivial_copy, unsigned int);
MPL_TYPE_SPE(has_trivial_copy, long);
MPL_TYPE_SPE(has_trivial_copy, unsigned long);
MPL_TYPE_SPE(has_trivial_copy, float);
MPL_TYPE_SPE(has_trivial_copy, double);

template<typename T>
class has_trivial_copy_constructor {
  template<typename U>
  static auto test(int) -> decltype(
    mpl_constant<bool, has_trivial_copy<U>::type>{}
  );

  template<typename>
  static mpl_false_type test(...);

public:
  static constexpr bool value = decltype(test<T>(0))::value;
};

} // namespace impl
/// \endcond

/// \cond
namespace impl {

MPL_TYPE_DEC(mpl_is_char);
MPL_TYPE_SPE(mpl_is_char, char);
MPL_TYPE_SPE(mpl_is_char, signed char);
MPL_TYPE_SPE(mpl_is_char, unsigned char);

} // namespace impl
/// \endcond

/// \cond
template<typename T>
  struct is_char
  : public impl::mpl_is_char<typename impl::remove_cv<T>::type>::type 
  {};

template<typename T>
  MPL_VAR
  bool is_char_v = lfc::is_char<T>::value;

/// \endcond



template<typename T>
  struct is_pointer;

/// \cond
namespace impl {

template<int N> struct PtrIntToType { using type = void; };
template<> struct PtrIntToType<0> { using type = mpl_false_type; };
template<> struct PtrIntToType<1> { using type = mpl_true_type; };

template<typename T>
  struct is_pointer_impl {
    static constexpr int selector = 
      (sizeof(T*) == sizeof(void*)) ? 1 : 0;
    using type = typename PtrIntToType<selector>::type;
  };

} // namespace impl

template<typename T>
  struct is_pointer : impl::is_pointer_impl<T>::type {};

/// \endcond

MPL_TYPE_VAR(is_pointer)

} // namespace lfc

#endif //__LFC_STL_TYPE_TRAITS_H__