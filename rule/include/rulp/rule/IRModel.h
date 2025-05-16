// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_RULE_IRMODEL_H__
#define __RULP_RULE_IRMODEL_H__
#include "rulp/object/IRInstance.h"
#include "rulp/rule/IRRunnable.h"
#include "rulp/rule/IRRule.h"
#include "rulp/rule/Constant.h"
namespace lfc {

class IRModel 
  : virtual public IRInstance
  , virtual public IRRunnable
{
public:

  virtual ~IRModel() = default;

public:

  // static class RNodeContext {

  //     public int actualAddStmt = 0;

  //     public IRReteEntry currentEntry;

  //     public IRReteNode currentNode;

  //     public int tryAddStmt = 0;

  // }

  // boolean addConstraint(IRReteNode node, IRConstraint1 constraint) throws RException;

  // void addLoadNodeListener(IRListener1<IRReteNode> listener);

  virtual IRRule* addRule(StrConstRef ruleName, IRList* condList, IRList* actionList) = 0;

  // void addRuleExecutedListener(IRListener1<IRRule> listener);

  // void addRuleFailedListener(IRListener1<IRRule> listener);

  // void addSaveNodeListener(IRListener1<IRReteNode> listener);

  // boolean addStatement(IRList stmt) throws RException;

  // void addStatementListener(IRList condList, IRListener1<IRList> listener) throws RException;

  // void addUpdateNode(IRReteNode node) throws RException;

  // boolean assumeStatement(IRList stmt) throws RException;

  // IRIterator<? extends IRList> buildStatementIterator(IRList filter) throws RException;

  // int doGC() throws RException;

  // int execute(IRReteNode node, int limit) throws RException;

  // IRReteNode findNode(IRList condList) throws RException;

  // IRReteEntry findReteEntry(IRList filter) throws RException;

  // IRReteEntry findReteEntry(IRList filter, List<OrderEntry> orderList) throws RException;

  // boolean fixStatement(IRList stmt) throws RException;

  // String getCachePath();

  // IRModelCounter getCounter();

  // List<String> getCounterKeyList();

  // long getCounterValue(String countkey);

  // IREntryTable getEntryTable();

  // String getModelName();

  // IRNodeGraph getNodeGraph();

  // IRNodeUpdateQueue getNodeUpdateQueue();

  // IRReteNode getTopExecuteNode();

  // IRVar getVar(String name) throws RException;

  // boolean isBufferEnable();

  // List<? extends IRBufferWorker> listCacheWorkers();

  // int listStatements(IRList filter, int statusMask, int limit, boolean reverse, IREntryIteratorBuilder builder,
  //         IREntryAction action) throws RException;

  // void query(IREntryAction result, IRList condList, Map<String, IRObject> whereVarMap, int limit,
  //         boolean backward, boolean gc) throws RException;

  // IRIterator<IRReteEntry> query(IRList condList, int limit, boolean backward) throws RException;

  // IRObject removeConstraint(IRReteNode node, IRConstraint1 constraint) throws RException;

  // IRRule removeRule(String ruleName) throws RException;

  // boolean removeStatement(IRList stmt) throws RException;

  // int save() throws RException;

  // void setModelBufferPath(String bufferPath) throws RException;

  // void pushNodeContext(RNodeContext nodeContext);

  // void popNodeContext(RNodeContext nodeContext) throws RException;

  // void setNodeLoader(IRReteNode node, IRStmtLoader loader) throws RException;

  // void setNodeSaver(IRReteNode node, IRStmtSaver saver) throws RException;

  // boolean tryAddStatement(IRList stmt) throws RException;

};

} // namespace lfc
#endif //__RULP_RULE_IRCONTEXT_H__