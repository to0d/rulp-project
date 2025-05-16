// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "lfc/base/math.h"
#include <cmath>

namespace lfc {

double MathUtil::ceil(double v) {
  return std::ceil(v);
}

double MathUtil::exp(double v) {
  return std::exp(v);
}

double MathUtil::log(double v) {
  return std::log(v);
}

} // namespace lfc