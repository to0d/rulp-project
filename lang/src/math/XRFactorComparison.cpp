// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/lang.h"
#include "rulp/runtime/AbsAtomFactorAdapter.h"
#include <sstream>

using namespace lfc;

namespace lfc {

class XRFactorComparison 
  : public AbsAtomFactorAdapter
  , virtual public IRFactor
{

public:
  XRFactorComparison(StrConstRef factorName, RRelationalOperator op);
 
  virtual ~XRFactorComparison();

public:

  virtual IRObject* compute(IRList* args, IRInterpreter* interpreter, IRFrame* frame) override;

private:

  RRelationalOperator op;

};

XRFactorComparison::XRFactorComparison(StrConstRef factorName, RRelationalOperator op)
  : AbsAtomFactorAdapter(factorName)
  , op(op)
{}

XRFactorComparison::~XRFactorComparison(){}
 
IRObject* XRFactorComparison::compute(IRList* args, IRInterpreter* interpreter, IRFrame* frame) {

  if (args->size() != 3) {
    throw RException("Invalid parameters: " + args->asString());
  }

  ROH a = interpreter->compute(frame, args->get(1));
  ROH b = interpreter->compute(frame, args->get(2));

  return RulpFactory::createBoolean(RulpMathUtil::computeRelationalExpression(op, a, b));
}

XRFACTOR_IMPL_EXTERN(XRFactorComparisonEQ, XRFactorComparison, RRelationalOperator::EQ) // =
XRFACTOR_IMPL_EXTERN(XRFactorComparisonNE, XRFactorComparison, RRelationalOperator::NE) // !=
XRFACTOR_IMPL_EXTERN(XRFactorComparisonGT, XRFactorComparison, RRelationalOperator::GT) // >
XRFACTOR_IMPL_EXTERN(XRFactorComparisonLT, XRFactorComparison, RRelationalOperator::LT) // <
XRFACTOR_IMPL_EXTERN(XRFactorComparisonGE, XRFactorComparison, RRelationalOperator::GE) // >=
XRFACTOR_IMPL_EXTERN(XRFactorComparisonLE, XRFactorComparison, RRelationalOperator::LE) // <=

STATIC_FACTOR_REGISTER(XRFactorComparisonEQ, F_O_EQ);
STATIC_FACTOR_REGISTER(XRFactorComparisonNE, F_O_NE);
STATIC_FACTOR_REGISTER(XRFactorComparisonGT, F_O_GT);
STATIC_FACTOR_REGISTER(XRFactorComparisonLT, F_O_LT);
STATIC_FACTOR_REGISTER(XRFactorComparisonGE, F_O_GE);
STATIC_FACTOR_REGISTER(XRFactorComparisonLE, F_O_LE);

} // namespace lfc