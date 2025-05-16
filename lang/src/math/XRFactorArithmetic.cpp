// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/lang.h"
#include "rulp/runtime/AbsAtomFactorAdapter.h"
#include <sstream>

using namespace lfc;

namespace lfc {

class XRFactorArithmetic 
  : public AbsAtomFactorAdapter
  , virtual public IRFactor
{

public:
  XRFactorArithmetic(StrConstRef factorName, RArithmeticOperator type);
 
  virtual ~XRFactorArithmetic();

public:

  virtual IRObject* compute(IRList* args, IRInterpreter* interpreter, IRFrame* frame) override;

private:

  RArithmeticOperator type;

};

XRFactorArithmetic::XRFactorArithmetic(StrConstRef factorName, RArithmeticOperator type)
  : AbsAtomFactorAdapter(factorName)
  , type(type)
{}

XRFactorArithmetic::~XRFactorArithmetic(){}
 
IRObject* XRFactorArithmetic::compute(IRList* args, IRInterpreter* interpreter, IRFrame* frame) {

  if (args->size() < 2) {
    throw RException("Invalid parameters: " + args->asString());
  }

  auto it = args->listIterator(1);
  auto rst = interpreter->compute(frame, it->next());

  if (type == RArithmeticOperator::ADD && rst->getType()->getIndex() == E_STRING) {

    if (!it->hasNext()) {
      return rst;
    }

    std::stringstream ss;
    ss << rst->asString();

    while (it->hasNext()) {
      ROH next = interpreter->compute(frame, it->next()); 
      ROH obj  = RulpUtil::toString(next, interpreter);
      ss << RulpUtil::asString(obj)->asString();
    }

    rst = RulpFactory::createString(ss.str());
  } 
  else {

    while (it->hasNext()) {

      // (* 0 ...) ==> 0
      if (RulpOptUtil::isConstNumber(rst, 0)) {
        switch (type) {
          case RArithmeticOperator::BY:
          case RArithmeticOperator::MOD:
          case RArithmeticOperator::DIV:
            return O_INT_0;
          default:
            break;
        }
      }

      // (power 1 a) ==> 1
      if (RulpOptUtil::isConstNumber(rst, 1)) {
        if(type == RArithmeticOperator::POWER) {
          return O_INT_1;
        }
      }

      ROH next = interpreter->compute(frame, it->next());
      rst = RulpMathUtil::computeArithmeticExpression(type, rst, next);
    }
  }

  return rst;
}

XRFACTOR_IMPL_EXTERN(XRFactorArithmeticADD, XRFactorArithmetic, RArithmeticOperator::ADD)
XRFACTOR_IMPL_EXTERN(XRFactorArithmeticSUB, XRFactorArithmetic, RArithmeticOperator::SUB)
XRFACTOR_IMPL_EXTERN(XRFactorArithmeticBY , XRFactorArithmetic, RArithmeticOperator::BY)
XRFACTOR_IMPL_EXTERN(XRFactorArithmeticDIV, XRFactorArithmetic, RArithmeticOperator::DIV)
XRFACTOR_IMPL_EXTERN(XRFactorArithmeticMOD, XRFactorArithmetic, RArithmeticOperator::MOD)
XRFACTOR_IMPL_EXTERN(XRFactorArithmeticPOW, XRFactorArithmetic, RArithmeticOperator::POWER)
XRFACTOR_IMPL_EXTERN(XRFactorArithmeticAND, XRFactorArithmetic, RArithmeticOperator::AND)
XRFACTOR_IMPL_EXTERN(XRFactorArithmeticOR , XRFactorArithmetic, RArithmeticOperator::OR)
XRFACTOR_IMPL_EXTERN(XRFactorArithmeticXOR, XRFactorArithmetic, RArithmeticOperator::XOR)


STATIC_FACTOR_REGISTER(XRFactorArithmeticADD, F_O_ADD);
STATIC_FACTOR_REGISTER(XRFactorArithmeticSUB, F_O_SUB);
STATIC_FACTOR_REGISTER(XRFactorArithmeticBY , F_O_BY );

STATIC_FACTOR_REGISTER(XRFactorArithmeticDIV, F_O_DIV);
STATIC_FACTOR_REGISTER(XRFactorArithmeticMOD, F_O_MOD);
STATIC_FACTOR_REGISTER(XRFactorArithmeticPOW, F_O_POWER);
STATIC_FACTOR_REGISTER(XRFactorArithmeticAND, F_O_AND);
STATIC_FACTOR_REGISTER(XRFactorArithmeticOR , F_O_OR );
STATIC_FACTOR_REGISTER(XRFactorArithmeticXOR, F_O_XOR);

} // namespace lfc