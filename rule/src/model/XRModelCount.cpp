// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "XRModelCount.h"
#include <algorithm>

// Initialize constants
const std::string XRModelCount::CK_ADD_CONSTRAINT = "model-addConstraint";
const std::string XRModelCount::CK_ADD_LOAD_NODE_LIS = "model-addLoadNodeListener";
const std::string XRModelCount::CK_ADD_RULE = "model-addRule";
const std::string XRModelCount::CK_ADD_RULE_EXEC_LIS = "model-addRuleExecutedListener";
const std::string XRModelCount::CK_ADD_RULE_FAIL_LIS = "model-addRuleFailedListener";
const std::string XRModelCount::CK_ADD_SAVE_NODE_LIS = "model-addSaveNodeListener";
const std::string XRModelCount::CK_ADD_STMT = "model-addStatement";
const std::string XRModelCount::CK_ADD_STMT_LIS = "model-addStatementListener";
const std::string XRModelCount::CK_ADD_UPDATE_NODE = "model-addUpdateNode";
const std::string XRModelCount::CK_ASSUME_STMT = "model-assumeStatement";
const std::string XRModelCount::CK_DO_GC = "model-doGC";
const std::string XRModelCount::CK_EXEC = "model-execute";
const std::string XRModelCount::CK_FIND_RETE_ENTRY_1 = "model-findReteEntry-1";
const std::string XRModelCount::CK_FIND_RETE_ENTRY_2 = "model-findReteEntry-2";
const std::string XRModelCount::CK_FIX_STMT = "model-fixStatement";
const std::string XRModelCount::CK_GC_COUNT = "model-gc-count";
const std::string XRModelCount::CK_GC_TRIGGER = "model-gc-trigger";
const std::string XRModelCount::CK_GET_VAR = "model-getVar";
const std::string XRModelCount::CK_HALT = "model-halt";
const std::string XRModelCount::CK_HAS_STMT_CACHE = "model-has-stmt-cache";
const std::string XRModelCount::CK_HAS_STMT_HIT = "model-has-stmt-hit";
const std::string XRModelCount::CK_LIST_STMT = "model-listStatements";
const std::string XRModelCount::CK_MAX_STACK_EXECUTE = "model-maxStackExecute";
const std::string XRModelCount::CK_MAX_STACK_NODE_CONTEXT = "model-maxStackNodeContext";
const std::string XRModelCount::CK_QUERY = "model-query";
const std::string XRModelCount::CK_QUERY_ITERATOR = "model-query-iterator";
const std::string XRModelCount::CK_RMV_CONSTRAINT = "model-removeConstraint";
const std::string XRModelCount::CK_RMV_STMT = "model-removeStatement";
const std::string XRModelCount::CK_SAVE = "model-save";
const std::string XRModelCount::CK_SET_CACHE_PATH = "model-setModelCachePath";
const std::string XRModelCount::CK_SET_NODE_LOADER = "model-setNodeLoader";
const std::string XRModelCount::CK_SET_NODE_SAVER = "model-setNodeSaver";
const std::string XRModelCount::CK_START = "model-start";
const std::string XRModelCount::CK_TRY_ADD_STMT = "model-tryAddStatement";

// Initialize static key list
namespace {
  std::vector<std::string> initKeyList() {
    std::vector<std::string> keys;
    keys.push_back(XRModelCount::CK_GC_TRIGGER);
    keys.push_back(XRModelCount::CK_GC_COUNT);
    keys.push_back(XRModelCount::CK_HAS_STMT_CACHE);
    keys.push_back(XRModelCount::CK_HAS_STMT_HIT);
    keys.push_back(XRModelCount::CK_ADD_CONSTRAINT);
    keys.push_back(XRModelCount::CK_ADD_LOAD_NODE_LIS);
    keys.push_back(XRModelCount::CK_ADD_RULE);
    keys.push_back(XRModelCount::CK_ADD_RULE_EXEC_LIS);
    keys.push_back(XRModelCount::CK_ADD_RULE_FAIL_LIS);
    keys.push_back(XRModelCount::CK_ADD_SAVE_NODE_LIS);
    keys.push_back(XRModelCount::CK_ADD_STMT);
    keys.push_back(XRModelCount::CK_ADD_STMT_LIS);
    keys.push_back(XRModelCount::CK_ADD_UPDATE_NODE);
    keys.push_back(XRModelCount::CK_ASSUME_STMT);
    keys.push_back(XRModelCount::CK_DO_GC);
    keys.push_back(XRModelCount::CK_EXEC);
    keys.push_back(XRModelCount::CK_GET_VAR);
    keys.push_back(XRModelCount::CK_HALT);
    keys.push_back(XRModelCount::CK_FIND_RETE_ENTRY_1);
    keys.push_back(XRModelCount::CK_FIND_RETE_ENTRY_2);
    keys.push_back(XRModelCount::CK_LIST_STMT);
    keys.push_back(XRModelCount::CK_QUERY);
    keys.push_back(XRModelCount::CK_QUERY_ITERATOR);
    keys.push_back(XRModelCount::CK_RMV_CONSTRAINT);
    keys.push_back(XRModelCount::CK_RMV_STMT);
    keys.push_back(XRModelCount::CK_SAVE);
    keys.push_back(XRModelCount::CK_SET_CACHE_PATH);
    keys.push_back(XRModelCount::CK_SET_NODE_LOADER);
    keys.push_back(XRModelCount::CK_SET_NODE_SAVER);
    keys.push_back(XRModelCount::CK_START);
    keys.push_back(XRModelCount::CK_TRY_ADD_STMT);
    keys.push_back(XRModelCount::CK_MAX_STACK_NODE_CONTEXT);
    keys.push_back(XRModelCount::CK_MAX_STACK_EXECUTE);
    return keys;
  }

  const std::vector<std::string> MODEL_COUNT_KEY_LIST = initKeyList();
}

const std::vector<std::string>& XRModelCount::getCounterKeyList() {
  return MODEL_COUNT_KEY_LIST;
}

long XRModelCount::getCounterValue(const std::string& countkey) {
  if (countkey == CK_GC_TRIGGER) return gcTrigger;
  if (countkey == CK_GC_COUNT) return gcCount;
  if (countkey == CK_HAS_STMT_HIT) return hasStmtHitCount;
  if (countkey == CK_ADD_CONSTRAINT) return mcAddConstraint;
  if (countkey == CK_ADD_LOAD_NODE_LIS) return mcAddLoadNodeListener;
  if (countkey == CK_ADD_RULE) return mcAddRule;
  if (countkey == CK_ADD_RULE_EXEC_LIS) return mcAddRuleExecutedListener;
  if (countkey == CK_ADD_RULE_FAIL_LIS) return mcAddRuleFailedListener;
  if (countkey == CK_ADD_SAVE_NODE_LIS) return mcAddSaveNodeListener;
  if (countkey == CK_ADD_STMT) return mcAddStatement;
  if (countkey == CK_ADD_STMT_LIS) return mcAddStatementListener;
  if (countkey == CK_ADD_UPDATE_NODE) return mcAddUpdateNode;
  if (countkey == CK_ASSUME_STMT) return mcAssumeStatement;
  if (countkey == CK_DO_GC) return mcDoGC;
  if (countkey == CK_EXEC) return mcExecute;
  if (countkey == CK_GET_VAR) return mcGetVar;
  if (countkey == CK_HALT) return mcHalt;
  if (countkey == CK_FIND_RETE_ENTRY_1) return mcFindReteEntry1;
  if (countkey == CK_FIND_RETE_ENTRY_2) return mcFindReteEntry2;
  if (countkey == CK_LIST_STMT) return mcListStatements;
  if (countkey == CK_QUERY) return mcQuery;
  if (countkey == CK_QUERY_ITERATOR) return mcQueryIterator;
  if (countkey == CK_RMV_CONSTRAINT) return mcRemoveConstraint;
  if (countkey == CK_RMV_STMT) return mcRemoveStatement;
  if (countkey == CK_SAVE) return mcSave;
  if (countkey == CK_SET_CACHE_PATH) return mcSetModelCachePath;
  if (countkey == CK_SET_NODE_LOADER) return mcSetNodeLoader;
  if (countkey == CK_SET_NODE_SAVER) return mcSetNodeSaver;
  if (countkey == CK_START) return mcStart;
  if (countkey == CK_TRY_ADD_STMT) return mcTryAddStatement;
  if (countkey == CK_MAX_STACK_NODE_CONTEXT) return mcMaxStackDeepNodeContext;
  if (countkey == CK_MAX_STACK_EXECUTE) return mcMaxStackDeepExecute;

  return 0;
}