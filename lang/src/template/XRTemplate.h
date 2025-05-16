// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_TEMPLATE_XRTEMPLATE_H__
#define __RULP_TEMPLATE_XRTEMPLATE_H__
#include "rulp/runtime/IRTemplate.h"
#include "rulp/runtime/AbsRefCallableAdapter.h"
namespace lfc {

class XRTemplate 
  : public AbsRefCallableAdapter
  , virtual public IRTemplate
{

public:

  XRTemplate(StrConstRef templateName, IRFrame* defineFrame);

  virtual ~XRTemplate() = default;

public:

  virtual void addEntry(const TemplateParaEntry& entry) override;

  virtual const std::string& asString() const override;

  virtual IRObject* compute(IRList* args, IRInterpreter* interpreter, IRFrame* frame) override;

  virtual IRFrame* getDefineFrame() const override;

  virtual std::string getName() const override;

  virtual std::string getSignature() const override;

  virtual RType getType() const override;

  virtual const std::vector<TemplateParaEntry>& getTemplateParaEntryList() const override;

protected:

  virtual void  _delete() override;


protected:

  IRFrame* defineFrame = null;

  mutable std::string signature;

	std::string templateName;

  std::vector<TemplateParaEntry> templateParaEntryList;
};

} // namespace lfc
#endif //__RULP_TEMPLATE_XRTEMPLATE_H__