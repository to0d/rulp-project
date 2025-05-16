// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/lang.h"
#include "rulp/utils/FormatUtil.h"
#include "rulp/utils/RObjectHandler.h"
#include "lfc/base/auto/auto_free.h"
#include "lfc/base/string.h"
#include <map>
#include <sstream>

using namespace lfc;
using namespace lfc;
namespace lfc {

struct Loc {
  int deep;
  int num;
  int width;

  Loc()
    : deep(0)
    , num(0)
    , width(0)
  {}

  Loc(int deep, int num, int width)
    : deep(deep)
    , num(num)
    , width(width)
  {}

  Loc(const Loc& loc)
    : deep(loc.deep)
    , num(loc.num)
    , width(loc.width)
  {}
  
};

#define MAX_LEN  256
static Loc loc(0, 1, 3);

static std::string toString(IRObject* obj) {
  return RulpUtil::toStringAttr(obj, true);
}

struct RFrmater {

  ~RFrmater() {
    LFC_FREE_ARRAY(auto_released);
  }

  std::map<IRObject*, Loc*> objLocMap;
  std::vector<Loc*> auto_released;

  Loc* _getLoc(IRObject* obj);
  void _output(IRObject* obj, std::vector<std::string>& outLines);
  void _output(IRObject* obj, std::vector<std::string>& outLines, int level);
  void _output_if(IRList* expr, std::vector<std::string>& outLines, int level);
  void _output_defun(IRList* expr, std::vector<std::string>& outLines, int level);
  void _output_loop(IRList* expr, std::vector<std::string>& outLines, int level);
  void _output_add_rule(IRList* expr, std::vector<std::string>& outLines, int level);
  void _output_factor1(IRList* expr, std::vector<std::string>& outLines, int level);
};

Loc* RFrmater::_getLoc(IRObject* obj) {
  if (obj == null) {
    throw RException("null obj");
  }

  Loc* loc = objLocMap[obj];
  if (loc == null) {
    switch (TYPE_INDEX_OF(obj)) {
    case E_EXPR:
    case E_LIST: {

      int deep = 0;
      int num = 0;
      int width = 2;

      auto it = AS_LIST(obj)->iterator();
      while (it->hasNext()) {
        auto cLoc = _getLoc(it->next());
        deep = std::max(deep, cLoc->deep);
        width += cLoc->width + 1;
        num++;
      }

      loc = new Loc(deep + 1, num, width);
      auto_released.push_back(loc);

      break;
    }
    
    default: {
      
      loc = new Loc(0, 1, toString(obj).length());
      auto_released.push_back(loc);

      break;
    }
    }

    objLocMap[obj] = loc;
  }

  return loc;
}

void RFrmater::_output(IRObject* obj, std::vector<std::string>& outLines) {
  objLocMap.clear();
  _output(obj, outLines, 0);
}

void RFrmater::_output(IRObject* obj, std::vector<std::string>& outLines, int level) {
  if (TYPE_INDEX_OF(obj) == E_EXPR) {

    auto list   = AS_LIST(obj);
    auto factor = list->get(0)->asString();

    if(factor == F_IF) {
      _output_if(list, outLines, level);
      return;
    }

    if(factor == F_DEFUN) {
      _output_defun(list, outLines, level);
      return;
    }

    if(factor == F_LOOP || factor == F_TRY || factor == A_DO) {
      _output_loop(list, outLines, level);
      return;
    }

    if(factor == "add-rule") {
      _output_add_rule(list, outLines, level);
      return;
    }
  }

  boolean outputOneLine = false;

  auto cLoc = _getLoc(obj);
  switch (TYPE_INDEX_OF(obj)) {
  case E_EXPR:
  case E_LIST:
    if (cLoc->width < MAX_LEN) {
      outputOneLine = true;
    } 
    else {
      outputOneLine = false;
    }
    break;
  default:
    outputOneLine = true;
  }

  if (outputOneLine) {
    outLines.push_back(RulpUtil::getSpaceLine(level) + toString(obj));
    return;
  }

  auto list = AS_LIST(obj);
  auto e0   = list->get(0);
  auto l0   = _getLoc(e0);

  std::string head = TYPE_INDEX_OF(obj) == E_EXPR ? "(" : "'(";
  IRIteratorPtr it;
  // first element is simple
  if (l0->num == 1 || (l0->width < MAX_LEN)) {
    outLines.push_back(RulpUtil::getSpaceLine(level) + head + toString(e0));
    it = list->listIterator(1);
  } 
  else {
    outLines.push_back(RulpUtil::getSpaceLine(level) + head);
    it = list->listIterator(0);
  }

  while (it->hasNext()) {
    _output(it->next(), outLines, level + 1);
  }

  outLines.push_back(RulpUtil::getSpaceLine(level) + ")");
}

void RFrmater::_output_if(IRList* expr, std::vector<std::string>& outLines, int level) {
  // (if condition
  // true-expr
  // )
  if (RulpUtil::isIf1(expr)) {

    std::string line1 = RulpUtil::getSpaceLine(level) + "(" + toString(expr->get(0)) + " " + toString(expr->get(1));
    outLines.push_back(line1);
    _output(expr->get(2), outLines, level + 1);
    outLines.push_back(RulpUtil::getSpaceLine(level) + ")");

    return;
  }

  // (if condition
  // true-expr
  // false-expr
  // )
  if (RulpUtil::isIf2(expr)) {

    std::string line1 = RulpUtil::getSpaceLine(level) + "(" + toString(expr->get(0)) + " " + toString(expr->get(1));
    outLines.push_back(line1);
    _output(expr->get(2), outLines, level + 1);
    _output(expr->get(3), outLines, level + 1);
    outLines.push_back(RulpUtil::getSpaceLine(level) + ")");

    return;
  }

  // (if condition do
  // expr1
  // expr2
  // expr3
  // ...
  // )
  if (RulpUtil::isIf3(expr)) {

    std::string line1 = RulpUtil::getSpaceLine(level) + "(" + toString(expr->get(0)) + " " + toString(expr->get(1))
        + " " + toString(expr->get(2));
    outLines.push_back(line1);

    int size = expr->size();
    for (int i = 3; i < size; ++i) {
      _output(expr->get(i), outLines, level + 1);
    }
    outLines.push_back(RulpUtil::getSpaceLine(level) + ")");

    return;
  }

  _output_factor1(expr, outLines, level);
}

void RFrmater::_output_defun(IRList* expr, std::vector<std::string>& outLines, int level) {
  std::string firsLine = "(";
  int size = expr->size();
  for (int index = 0; index < size - 1; ++index) {
    if (index != 0) {
      firsLine += " ";
    }
    firsLine += toString(expr->get(index));
  }

  outLines.push_back(RulpUtil::getSpaceLine(level) + firsLine);
  _output(expr->get(size - 1), outLines, level + 1);
  outLines.push_back(RulpUtil::getSpaceLine(level) + ")");
}

void RFrmater::_output_loop(IRList* expr, std::vector<std::string>& outLines, int level) {
  // (loop for x in '(1 2 3) do
  // action
  // )
  if (RulpUtil::isLoop1(expr)) {

    int size = expr->size();

    std::string line1 = RulpUtil::getSpaceLine(level) + "(" + toString(expr->get(0));
    for (int i = 1; i < 6; ++i) {
      line1 += " " + toString(expr->get(i));
    }
    outLines.push_back(line1);

    for (int i = 6; i < size; ++i) {
      _output(expr->get(i), outLines, level + 1);
    }
    outLines.push_back(RulpUtil::getSpaceLine(level) + ")");

    return;
  }

  // (loop for x from 1 to 3 do
  // action
  // )
  if (RulpUtil::isLoop2(expr)) {

    int size = expr->size();

    std::string line1 = RulpUtil::getSpaceLine(level) + "(" + toString(expr->get(0));
    for (int i = 1; i < 8; ++i) {
      line1 += " " + toString(expr->get(i));
    }
    outLines.push_back(line1);

    for (int i = 8; i < size; ++i) {
      _output(expr->get(i), outLines, level + 1);
    }
    outLines.push_back(RulpUtil::getSpaceLine(level) + ")");

    return;
  }

  // (loop for x from 1 to 3 by 2 do
  // action
  // )
  if (RulpUtil::isLoop4(expr)) {

    int size = expr->size();

    std::string line1 = RulpUtil::getSpaceLine(level) + "(" + toString(expr->get(0));
    for (int i = 1; i < 10; ++i) {
      line1 += " " + toString(expr->get(i));
    }
    outLines.push_back(line1);

    for (int i = 10; i < size; ++i) {
      _output(expr->get(i), outLines, level + 1);
    }
    outLines.push_back(RulpUtil::getSpaceLine(level) + ")");

    return;
  }

  // (loop
  // action
  // )
  _output_factor1(expr, outLines, level);
}

void RFrmater::_output_add_rule(IRList* expr, std::vector<std::string>& outLines, int level) {
  std::string firsLine = "(";
  int size = expr->size();
  int index = 0;

  // syntax: (add-rule ["name"] model if cond1 cond2 .. do action1 action2)

  int formatType = 0;

  for (; index < size; ++index) {

    auto obj = expr->get(index);

    if (TYPE_INDEX_OF(obj) == E_EXPR) {
      formatType = 1;
      break;
    }

    if (RulpUtil::isAtom(obj, F_IF)) {
      formatType = 2;
      break;
    }

    if (index != 0) {
      firsLine += " ";
    }

    firsLine += toString(obj);
  }

  outLines.push_back(RulpUtil::getSpaceLine(level) + firsLine);
  for (; index < size; ++index) {

    auto obj = expr->get(index);
    if (RulpUtil::isAtom(obj, F_IF) || RulpUtil::isAtom(obj, A_DO)) {
      _output(obj, outLines, level + 1);
    }
    else {
      _output(obj, outLines, level + 2);
    }

  }

  outLines.push_back(RulpUtil::getSpaceLine(level) + ")");
}

void RFrmater::_output_factor1(IRList* expr, std::vector<std::string>& outLines, int level) {
  outLines.push_back(RulpUtil::getSpaceLine(level) + "(" + toString(expr->get(0)));

  for (int i = 1; i < expr->size(); ++i) {
    _output(expr->get(i), outLines, level + 1);
  }

  outLines.push_back(RulpUtil::getSpaceLine(level) + ")");
}

void FormatUtil::format(IRObject* obj, std::vector<std::string>& outLines, int level) {
  RFrmater formater;
  formater._output(obj, outLines, level);
}

std::vector<std::string> FormatUtil::format(std::vector<std::string>& lines) {
  std::vector<std::string> outLines;

  auto parser = RulpFactory::createParser();
  RULP_AUTO_FREE(parser);

  int size = lines.size();
  int index = 0;

  std::stringstream ss;
  int lastInCompletedIndex = -1;

  NEXT_LINE: for (; index < size; ++index) {

    auto line = lines[index];
    auto trim_line = STR_TRIM(line);
    if (trim_line.empty()) {
      continue;
    }

    if (STR_START_WITH(trim_line, ";")) {
      if (lastInCompletedIndex == -1) {
        outLines.push_back(line);
        continue;
      }
      else {        
        throw RException( LFC_STR_FORMAT_BGN 
                              "Not support internal comment yet: line=%d, %s"
                            , index
                            , line.c_str()
                          LFC_STR_FORMAT_END);
      }
    }

    if (lastInCompletedIndex != -1) {
      ss << "\n";
    }

    ss << line;

    std::vector<IRObject*> objs;

    try {
      objs = parser->parse(ss.str());
    } 
    catch (RException e) {
      // statements maybe not in-completed
      if (lastInCompletedIndex == -1) {
        lastInCompletedIndex = index;
      }

      continue;
    }

    RListHandler rsultList;
    for (auto obj : objs) {
      rsultList.addResult(obj);
      RFrmater formater;
      formater._output(obj, outLines);
    }

    lastInCompletedIndex = -1;
    ss.str("");
  }

  if (lastInCompletedIndex != -1) {
    throw RException( LFC_STR_FORMAT_BGN 
                          "Incomplete line found: line=%d, %s"
                        , lastInCompletedIndex
                        , lines[lastInCompletedIndex].c_str()
                      LFC_STR_FORMAT_END );
  }

  return outLines;
}

} // namespace lfc