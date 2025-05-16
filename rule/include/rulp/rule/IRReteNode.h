// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_RULE_IRRETENODE_H__
#define __RULP_RULE_IRRETENODE_H__
#include "rulp/object/IRInstance.h"
#include "rulp/rule/IRRunnable.h"
#include "rulp/rule/IRContext.h"
namespace lfc {

class IRReteNode 
  : virtual public IRInstance
  , virtual public IRRunnable
  , virtual public IRContext
{

public:

	// static class InheritIndex {

	// 	final int elementIndex;

	// 	final int parentIndex;

	// 	InheritIndex(int parentIndex, int elementIndex) {
	// 		super();
	// 		this.parentIndex = parentIndex;
	// 		this.elementIndex = elementIndex;
	// 	}

	// 	String toString() {
	// 		return String.format("%d/%d", parentIndex, elementIndex);
	// 	}
	// }

	// static class JoinIndex {

	// 	final int leftIndex;

	// 	final int rightIndex;

	// 	JoinIndex(int leftIndex, int rightIndex) {
	// 		super();
	// 		this.leftIndex = leftIndex;
	// 		this.rightIndex = rightIndex;
	// 	}

	// 	@Override
	// 	String toString() {
	// 		return String.format("join(%d/%d)", leftIndex, rightIndex);
	// 	}
	// }

	// void addChildNode(IRReteNode child);

	// boolean addConstraint1(IRConstraint1 constraint) throws RException;

	// void addQueryMatchCount(int add);

	// boolean addReteEntry(IRReteEntry entry) throws RException;

	// int doGC();

	// void doGCEntry() throws RException;

	// int getAddEntryFailCount();

	// IRBufferWorker getBufferWorker();

	// String getCacheInfo();

	// List<IRReteNode> getChildNodes();

	// List<IRReteNode> getChildNodes(boolean onlyAutoUpdate);

	// IRConstraint1 getConstraint1(int index);

	// int getConstraint1Count();

	// int getEntryCreateCount();

	// int getEntryDeleteCount();

	// int getEntryLength();

	// IREntryQueue getEntryQueue();

	// IGraphInfo getGraphInfo();

	// InheritIndex[] getInheritIndex();

	// IRError getLastError();

	// IRConstraint1 getLastFailedConstraint1();

	// String getNamedName();

	// int getNodeExecCount();

	// int getNodeFailedCount();

	// int getNodeId();

	// int getNodeIdleCount();

	// int getNodeMatchCount();

	// String getNodeName();

	// int getParentCount();

	// IRReteNode[] getParentNodes();

	// int getParentVisitIndex(int index);

	// int getPriority();

	// int getQueryMatchCount();

	// int getReteLevel();

	// RReteStage getReteStage();

	// IRList getReteTree();

	// RReteType getReteType();

	// String getUniqName();

	// DeCounter getUpdateCounter();

	// IRObject[] getVarEntry();

	// void incAddEntryFailCount();

	// void incEntryCreateCount();

	// void incEntryDeleteCount();

	// void incExecCount(int execId);

	// void incNodeMatchCount();

	// boolean isAutoGC();

	// boolean isNodeFresh();

	// List<IRConstraint1Uniq> listUniqConstraints();

	// List<RUniqInfo> listUniqInfos() throws RException;

	// void removeChildNode(IRReteNode child);

	// IRConstraint1 removeConstraint(String constraintExpression);

	// void resetAutoGCBeginPos();

	// void setAutoGC(boolean autoGc);

	// void setBufferWorker(IRBufferWorker cache);

	// void setChildNodeUpdateMode(IRReteNode child, boolean auto) throws RException;

	// void setEntryQueue(IREntryQueue entryQueue);

	// void setGraphInfo(IGraphInfo graphInfo);

	// void setPriority(int priority) throws RException;

	// void setReteStage(RReteStage stage);

	// void setReteTree(IRList reteTree);

	// void setTrace(boolean trace);

	// void setUniqName(String uniqName);

	// int update(int limit) throws RException;
};

} // namespace lfc
#endif //__RULP_RULE_IRRETENODE_H__