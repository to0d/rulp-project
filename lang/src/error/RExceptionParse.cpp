// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/error/RExceptionParse.h"
#include "lfc/base/string/format.h"
using namespace lfc;

namespace lfc {

RExceptionParse::RExceptionParse(StrConstRef message, int line, int pos)
  : RException(message)
  , line(line)
  , pos(pos)
{}

RExceptionParse::RExceptionParse(const RExceptionParse& E)
  : RException(E)
{
  line  = E.line;
  pos   = E.pos;
}

RExceptionParse::RExceptionParse(RExceptionParse&& E)
  : RException(E)
{
  line  = E.line;
  pos   = E.pos;

  E.line = -1;
  E.pos  = -1;
}

std::string RExceptionParse::getMessage() const{
  if(_message.empty()){
    
    _message = LFC_STR_FORMAT_BGN 
          "%s, index=%d, pos=%d"
          , exceptionMessage.c_str()
          , line
          , pos
        LFC_STR_FORMAT_END;
    
    if (additionalMessages != null) {
      for (auto msg : *additionalMessages) {
        _message += "\n";
        _message += msg;
      }
    }
  }

  return _message;
}

} // namespace lfc