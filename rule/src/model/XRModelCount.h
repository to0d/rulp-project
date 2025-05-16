// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef XR_MODEL_COUNT_H
#define XR_MODEL_COUNT_H

#include <string>
#include <vector>

class XRModelCount {
public:
  // Constants
  static const std::string CK_ADD_CONSTRAINT;
  static const std::string CK_ADD_LOAD_NODE_LIS;
  static const std::string CK_ADD_RULE;
  static const std::string CK_ADD_RULE_EXEC_LIS;
  static const std::string CK_ADD_RULE_FAIL_LIS;
  static const std::string CK_ADD_SAVE_NODE_LIS;
  static const std::string CK_ADD_STMT;
  static const std::string CK_ADD_STMT_LIS;
  static const std::string CK_ADD_UPDATE_NODE;
  static const std::string CK_ASSUME_STMT;
  static const std::string CK_DO_GC;
  static const std::string CK_EXEC;
  static const std::string CK_FIND_RETE_ENTRY_1;
  static const std::string CK_FIND_RETE_ENTRY_2;
  static const std::string CK_FIX_STMT;
  static const std::string CK_GC_COUNT;
  static const std::string CK_GC_TRIGGER;
  static const std::string CK_GET_VAR;
  static const std::string CK_HALT;
  static const std::string CK_HAS_STMT_CACHE;
  static const std::string CK_HAS_STMT_HIT;
  static const std::string CK_LIST_STMT;
  static const std::string CK_MAX_STACK_EXECUTE;
  static const std::string CK_MAX_STACK_NODE_CONTEXT;
  static const std::string CK_QUERY;
  static const std::string CK_QUERY_ITERATOR;
  static const std::string CK_RMV_CONSTRAINT;
  static const std::string CK_RMV_STMT;
  static const std::string CK_SAVE;
  static const std::string CK_SET_CACHE_PATH;
  static const std::string CK_SET_NODE_LOADER;
  static const std::string CK_SET_NODE_SAVER;
  static const std::string CK_START;
  static const std::string CK_TRY_ADD_STMT;

  // Static methods
  static const std::vector<std::string>& getCounterKeyList();

  // Member variables
  long gcCount = 0;
  long gcTrigger = 0;
  int hasStmtHitCount = 0;
  long mcAddConstraint = 0;
  long mcAddLoadNodeListener = 0;
  long mcAddRule = 0;
  long mcAddRuleExecutedListener = 0;
  long mcAddRuleFailedListener = 0;
  long mcAddSaveNodeListener = 0;
  long mcAddStatement = 0;
  long mcAddStatementListener = 0;
  long mcAddUpdateNode = 0;
  long mcAssumeStatement = 0;
  long mcDoGC = 0;
  long mcExecute = 0;
  long mcFindReteEntry1 = 0;
  long mcFindReteEntry2 = 0;
  long mcFixStatement = 0;
  long mcGetVar = 0;
  long mcHalt = 0;
  long mcListStatements = 0;
  long mcMaxStackDeepExecute = 0;
  long mcMaxStackDeepNodeContext = 0;
  long mcQuery = 0;
  long mcQueryIterator = 0;
  long mcRemoveConstraint = 0;
  long mcRemoveStatement = 0;
  long mcSave = 0;
  long mcSetModelCachePath = 0;
  long mcSetNodeLoader = 0;
  long mcSetNodeSaver = 0;
  long mcStart = 0;
  long mcTryAddStatement = 0;

  // Member functions
  long getCounterValue(const std::string& countkey);
};

#endif // XR_MODEL_COUNT_H