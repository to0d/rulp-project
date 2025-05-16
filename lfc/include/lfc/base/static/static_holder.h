#ifndef __LFC_STATIC_HOLDER_H__
#define __LFC_STATIC_HOLDER_H__

#include <atomic>
#include <cstddef>
namespace lfc {

/*********************************************/
// The following codes are copied from 
// StaticHolder in LLVM
/*********************************************/


/// object_creator - Helper method for StaticHolder.
template <class C> struct object_creator {
  static void *call() { return new C(); }
};

/// object_deleter - Helper method for StaticHolder.
///
template <typename T> struct object_deleter {
  static void call(void *Ptr) { delete (T *)Ptr; }
};
template <typename T, size_t N> struct object_deleter<T[N]> {
  static void call(void *Ptr) { delete[](T *)Ptr; }
};

// StaticHolder must be initialized to zero, and it must *not* have a dynamic
// initializer because managed statics are often created while running other
// dynamic initializers. In standard C++11, the best way to accomplish this is
// with a constexpr default constructor. However, different versions of the
// Visual C++ compiler have had bugs where, even though the constructor may be
// constexpr, a dynamic initializer may be emitted depending on optimization
// settings. For the affected versions of MSVC, use the old linker
// initialization pattern of not providing a constructor and leaving the fields
// uninitialized. See http://llvm.org/PR41367 for details.
#if !defined(_MSC_VER) || (_MSC_VER >= 1925) || defined(__clang__)
#define LLVM_USE_CONSTEXPR_CTOR
#endif

/// StaticHolderBase - Common base class for StaticHolder instances.
class StaticHolderBase {
protected:
#ifdef LLVM_USE_CONSTEXPR_CTOR
  mutable std::atomic<void *> Ptr{};
  mutable void (*DeleterFn)(void *) = nullptr;
  mutable const StaticHolderBase *Next = nullptr;
#else
  // This should only be used as a static variable, which guarantees that this
  // will be zero initialized.
  mutable std::atomic<void *> Ptr;
  mutable void (*DeleterFn)(void *);
  mutable const StaticHolderBase *Next;
#endif

  void RegisterManagedStatic(void *(*creator)(), void (*deleter)(void*)) const;

public:
#ifdef LLVM_USE_CONSTEXPR_CTOR
  constexpr StaticHolderBase() = default;
#endif

  /// isConstructed - Return true if this object has not been created yet.
  bool isConstructed() const { return Ptr != nullptr; }

  void destroy() const;
};

/// StaticHolder - This transparently changes the behavior of global statics to
/// be lazily constructed on demand (good for reducing startup times of dynamic
/// libraries that link in LLVM components) and for making destruction be
/// explicit through the llvm_shutdown() function call.
///
template <class C, class Creator = object_creator<C>,
          class Deleter = object_deleter<C>>
class StaticHolder : public StaticHolderBase {
public:
  // Accessors.
  C &operator*() {
    void *Tmp = Ptr.load(std::memory_order_acquire);
    if (!Tmp)
      RegisterManagedStatic(Creator::call, Deleter::call);

    return *static_cast<C *>(Ptr.load(std::memory_order_relaxed));
  }

  C *operator->() { return &**this; }

  const C &operator*() const {
    void *Tmp = Ptr.load(std::memory_order_acquire);
    if (!Tmp)
      RegisterManagedStatic(Creator::call, Deleter::call);

    return *static_cast<C *>(Ptr.load(std::memory_order_relaxed));
  }

  const C *operator->() const { return &**this; }

  // Extract the instance, leaving the StaticHolder uninitialized. The
  // user is then responsible for the lifetime of the returned instance.
  C *claim() {
    return static_cast<C *>(Ptr.exchange(nullptr));
  }
};

} // namespace lfc
#endif //__LFC_STATIC_HOLDER_H__