// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/error/RExceptionI.h"
#include "lfc/base/auto/auto_free.h"
using namespace lfc;

namespace lfc {

RExceptionI::RExceptionI(IRObject* fromObject, IRFrame* fromFrame) 
  : RException(fromObject)
{
  this->fromFrame = fromFrame;
};

RExceptionI::RExceptionI(IRObject* fromObject, IRFrame* fromFrame, StrConstRef message) 
  : RException(fromObject, message)
{
  this->fromFrame = fromFrame;
};

RExceptionI::RExceptionI(const RExceptionI& E) 
  : RException(E) 
{
  this->fromFrame = E.fromFrame;
  this->handle    = E.handle;
}

RExceptionI::RExceptionI(RExceptionI&& E) 
  : RException(E) 
{
  this->fromFrame = E.fromFrame;
  this->handle    = E.handle;

  E.fromFrame = NULL;
  E.handle    = false;
}

} // namespace lfc