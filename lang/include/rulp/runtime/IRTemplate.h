// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_RUNTIME_IRTEMPLATE_H__
#define __RULP_RUNTIME_IRTEMPLATE_H__

#include "rulp/object/IRObject.h"
#include "rulp/runtime/IRCallable.h"
#include "rulp/runtime/IRFrame.h"
namespace lfc {

struct TemplatePara {

  boolean   isVar;
  IRAtom*   paraType;
  IRObject* paraValue;

  TemplatePara() = default;
  TemplatePara(const TemplatePara& para);

  std::string toString() const;
};

struct TemplateParaEntry {
  
  IRCallable*               body;
  std::vector<TemplatePara> fixedParas;
  boolean                   isVary;

  std::string toString() const;
};

class IRTemplate 
  : virtual public IRObject
  , virtual public IRCallable 
{
public:
 
  virtual void addEntry(const TemplateParaEntry& entry) = 0;

  virtual IRFrame *getDefineFrame() const = 0;

  virtual std::string getName() const = 0;

  virtual std::string getSignature() const = 0;

  virtual const std::vector<TemplateParaEntry>& getTemplateParaEntryList() const = 0;
};


} // namespace lfc
#endif //__RULP_RUNTIME_IRTEMPLATE_H__