// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "lfc/base/trace_macro.h"
#define LFC_TRACE_NAME   "[llvm_util]"
#define LFC_TRACE_NEED   TRACE_GET_TRACE(llvm_util)()
#define LFC_TRACE_STREAM llvm::errs()
#include "lfc/llvm/llvm_util.h"
#include "lfc/base/string/util.h"
#include "lfc/base/trace.h"
#include "lfc/base/to_string.h"
#include "llvm/Pass.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/Dominators.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Metadata.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Analysis/AliasAnalysis.h"
#include "llvm/Support/Casting.h"
#include "llvm/Support/raw_ostream.h"
#include <map>
#include <set>
#include <vector>
#include <iostream>

using namespace llvm;

namespace lfc {

bool is_all_in_dom_path(const std::vector<BasicBlock*>& blocks){
  LFC_TRACE2("is_all_in_dom_path: ", lfc::to_string(to_llvm_block_names(blocks)));
  if(blocks.size() <= 1){
    LFC_TRACE1("no need check dom.");
    return true;
  }

  static DominatorTree  last_DT;
  static Function*      last_F = NULL;

  Function* F = blocks[0]->getParent();
  assert(F != NULL);

  if(F != last_F){
    last_DT = DominatorTree(*F);
    last_F  = F;
  }  

  int pos = blocks.size() -1;
  BasicBlock* last_block = blocks[pos];
  DomTreeNodeBase<BasicBlock> * last_dom = last_DT.getNode(last_block);

  while(pos >= 0 && last_dom != NULL){
    LFC_TRACE4("Search dom: block=", lfc::get_llvm_block_name(last_block), ", dom=", lfc::get_llvm_block_name(last_dom->getBlock()));
    if(last_dom->getBlock() == last_block ){
      if( pos == 0 ){
        LFC_TRACE1("all dom found, succ.");
        return true;
      }
      last_block = blocks[--pos];    
    }
    last_dom = last_dom->getIDom();
  }
   
  LFC_TRACE2("dom not found: block=", lfc::get_llvm_block_name(last_block));
  return false;
}


} // namespace lfc 


