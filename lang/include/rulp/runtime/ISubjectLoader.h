// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_RUNTIME_ISUBJECTLOADER_H__
#define __RULP_RUNTIME_ISUBJECTLOADER_H__

namespace lfc {

class IRSubject;
class ISubjectLoader {
 
public:
  ISubjectLoader() = default;
  virtual ~ISubjectLoader() = default;

public:

  virtual void load(IRSubject* subject) = 0;

};

} // namespace lfc
#endif //__RULP_RUNTIME_ISUBJECTLOADER_H__