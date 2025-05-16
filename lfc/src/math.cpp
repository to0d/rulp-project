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