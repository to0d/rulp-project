// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/utils/RListHandler.h"
#include "rulp/utils/RulpUtil.h"

using namespace lfc;

namespace lfc {

static void _copy(const RListHandler& A, RListHandler& B){
  for(auto rst : A.results){
    B.addResult(rst);
  }
}

static void _move(RListHandler& A, RListHandler& B){
  B.results = std::move(A.results);
}

RListHandler::RListHandler(const RListHandler& RST){
  _copy(RST, *this);
}

RListHandler::RListHandler(RListHandler&& RST){
  _move(RST, *this);
}

RListHandler& RListHandler::operator=(const RListHandler &RST){
  _copy(RST, *this);
  return *this;
}

RListHandler& RListHandler::operator=(RListHandler &&RST){
  _move(RST, *this);
  return *this;
}

RListHandler::~RListHandler(){
  free();
}

void RListHandler::addResult(IRObject* rst){
  RULP_INC_REF(rst);
  results.push_back(rst);
}

void RListHandler::free(){
  RULP_DEC_REF(results);
}


} // namespace lfc