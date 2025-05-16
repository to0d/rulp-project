// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "lfc/base/to_string.h"
#include "lfc/base/string.h"

using namespace lfc;

#define TP_TMP_VAR_NAME   "?_TTVN_"

namespace lfc {

static IRObject* defTemplate(IRList* args, StrConstRef templateName, IRInterpreter* interpreter, IRFrame* frame) {

  /*****************************************************/
  // Template parameter list
  /*****************************************************/
  auto paraAttrs = AttrUtil::buildAttrList(args->get(2), interpreter, frame);
  RListHandler RLH;
  RLH = paraAttrs;

  int fixedParaCount = paraAttrs.size();

  // Add entry
  TemplateParaEntry paraEntry;
  paraEntry.isVary = false;

  // Check parameters
  if (paraAttrs.size() > 1) {

    std::set<std::string> paraNames;

    int i = 0;
    for(auto pa : paraAttrs) {

      // Check duplicated name
      auto paraName = pa->getParaName();
      if (paraNames.count(paraName) != 0) {
        throw RException("duplicate parameter: " + paraName);
      }
      paraNames.insert(paraName);

      IRAtom*   paraType = pa->getParaType();
      IRObject* paraValue = null;
      boolean   isVar = false;

      // var para
      if (RulpUtil::isVarName(paraName)) {
        isVar = true;
      }
      // atom para
      else {

        isVar = false;

        if (paraType == null || paraType == O_Nil) {

          auto fixParaEntry = RuntimeUtil::lookupFrameEntry(frame, paraName);
          if (fixParaEntry != null) {

            auto fixParaObj = fixParaEntry->getObject();
            paraType        = RulpUtil::getObjectType(fixParaObj);
            paraValue       = fixParaObj;

          } 
          else {
            paraType = T_Atom;
            paraValue = RulpFactory::createAtom(paraName);
          }

        }
        else if (paraType == T_Atom) {

          paraType = O_Nil;
          paraValue = RulpFactory::createAtom(paraName);

        }
        else {

          auto val = interpreter->compute(frame, RulpFactory::createAtom(paraName));
          if (RulpUtil::getObjectType(val) != pa->getParaType()) {
            throw RException( LFC_STR_FORMAT_BGN 
                                  "unmatch parameter type: value=%s, type=%s"
                                , val->asString().c_str()
                                , pa->getParaType()->asString().c_str()
                              LFC_STR_FORMAT_END);
          }

          paraType  = pa->getParaType();
          paraValue = val;
        }

        auto newPa = RulpFactory::createParaAttr(RulpFactory::createUniqName(TP_TMP_VAR_NAME), paraType);
        paraAttrs[i] = newPa;

      } // atom para

      TemplatePara tp;
      tp.isVar      = isVar;
      tp.paraValue  = paraValue;
      tp.paraType   = paraType;

      paraEntry.fixedParas.push_back(tp);
    } // for

  } // Check parameters

  /*****************************************************/
  // Template body
  /*****************************************************/
  IRExpr* templateBody = null;
  if (args->size() == 4) {
    templateBody = AS_EXPR(args->get(3));

  } 
  else if (args->size() > 4) {
    templateBody = RulpUtil::toDoExpr(args->listIterator(3));
  }
  else {
    throw RException("Invalid args size: " + TO_STR(args->size()));
  }

  paraEntry.body = RulpFactory::createFunction(frame, templateName, std::move(paraAttrs), templateBody);

  return RuntimeUtil::addTemplate(frame, templateName, paraEntry);
}

XRFACTOR_IMPL_BEGIN(XRFactorDefTemplate)

  if (args->size() < 4) {
    throw RException("Invalid parameters: " + args->asString());
  }

  auto nameObj = args->get(1);

  if (TYPE_INDEX_OF(nameObj) == E_ATOM) {
    return defTemplate(args, AS_ATOM(args->get(1))->getName(), interpreter, frame);
  }

  if (TYPE_INDEX_OF(nameObj) == E_MEMBER) {

    auto funMbr = AS_MEMBER(args->get(1));
    auto sub    = AS_SUBJECT(interpreter->compute(frame, funMbr->getSubject()));

    IRFrame* templateFrame;
    if (TYPE_INDEX_OF(sub) == E_FRAME) {
      templateFrame = AS_FRAME(sub);
    } 
    else {
      templateFrame = sub->getSubjectFrame();
    }

    return defTemplate(args, funMbr->getName(), interpreter, templateFrame);
  }

  throw RException("Invalid parameters: " + args->asString());

XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorDefTemplate, F_DEFTEMPLATE);

} // namespace lfc