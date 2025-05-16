#include "lfc/base/static/static_holder.h"
#include <cassert>
#include <mutex>
namespace lfc {

static const StaticHolderBase *StaticList = nullptr;

static std::recursive_mutex *getManagedStaticMutex() {
  static std::recursive_mutex m;
  return &m;
}

void StaticHolderBase::RegisterManagedStatic(void *(*Creator)(),
                                              void (*Deleter)(void*)) const {
  assert(Creator);
  // if (llvm_is_multithreaded()) {
    std::lock_guard<std::recursive_mutex> Lock(*getManagedStaticMutex());

    if (!Ptr.load(std::memory_order_relaxed)) {
      void *Tmp = Creator();

      Ptr.store(Tmp, std::memory_order_release);
      DeleterFn = Deleter;

      // Add to list of managed statics.
      Next = StaticList;
      StaticList = this;
    }
  // } else {
  //   assert(!Ptr && !DeleterFn && !Next &&
  //          "Partially initialized StaticHolder!?");
  //   Ptr = Creator();
  //   DeleterFn = Deleter;

  //   // Add to list of managed statics.
  //   Next = StaticList;
  //   StaticList = this;
  // }
}

void StaticHolderBase::destroy() const {
  assert(DeleterFn && "StaticHolder not initialized correctly!");
  assert(StaticList == this &&
         "Not destroyed in reverse order of construction?");
  // Unlink from list.
  StaticList = Next;
  Next = nullptr;

  // Destroy memory.
  DeleterFn(Ptr);

  // Cleanup.
  Ptr = nullptr;
  DeleterFn = nullptr;
}

} // namespace lfc