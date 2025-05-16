// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "XRFrameProtected.h"
#include "rulp/utils/RulpFactory.h"
#include <cassert> 

using namespace lfc;

namespace lfc {

IRFrameEntry* XRFrameProtected::createFrameEntry(StrConstRef name, IRObject* object) {
  return RulpFactory::createFrameEntryProtected(this, name, object);  
}

int XRFrameProtected::getRef() const {
  return 0;
}

void XRFrameProtected::decRef(){

}

void XRFrameProtected::incRef() {
  
}

IRFrameEntry* XRFrameProtected::removeEntry(StrConstRef name) {
  throw RException("unable to remove object in this frame: " + name);
}

// bool XRFrameProtected::isDeleted() const {
//   return false;
// }

// void XRFrameProtected::_delete() {
//   // assert(false && "unable to destructor this frame");
// }

} // namespace lfc