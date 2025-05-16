// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_BASE_MATH__
#define __LFC_BASE_MATH__


#define MATH_EXP(v)                 lfc::MathUtil::exp(v)
#define MATH_LOG(v)                 lfc::MathUtil::log(v)
#define MATH_CEIL(v)                lfc::MathUtil::ceil(v)

namespace lfc {


class MathUtil{

public:

  static double ceil(double v);
  static double exp(double v);
  static double log(double v);


};

} // namespace lfc
#endif // __LFC_BASE_MATH__
