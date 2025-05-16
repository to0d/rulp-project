// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_RNMAE_H__
#define __RULP_LANG_RNMAE_H__
#include "rulp/lang/base.h"
namespace lfc {

class RName{

public:
	const std::string fullName;
	const std::string nameSpace;
	const std::string prefix;
	const std::string subName;

  RName(std::string nameSpace, std::string prefix, std::string subName, std::string fullName);
  RName(const RName& R);

  const std::string& getShorName() const;

private:
  
  std::string shortName;

};

} // namespace lfc
LFC_TO_STRING_DEF(lfc::RName);
#endif //__RULP_LANG_RNMAE_H__