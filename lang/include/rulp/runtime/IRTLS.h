// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_RUNTIME_IRTLS_H__
#define __RULP_RUNTIME_IRTLS_H__

namespace lfc {

class IRTLS {
 
public:
  IRTLS() = default;
  virtual ~IRTLS() = default;

public:

  virtual int getCallLevel() const = 0;

};

} // namespace lfc
#endif //__RULP_RUNTIME_IRTLS_H__