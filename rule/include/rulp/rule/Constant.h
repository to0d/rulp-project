// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_RULE_CONS_H__
#define __RULP_RULE_CONS_H__

#define A_Asc  "asc"
#define A_Assumed  "assumed"
#define A_BackSearch  "back-search"
#define A_Backward  "backward"
#define A_BS_TRACE  "?bs-trace"
#define A_CMP_ENTRY_INDEX  "cmp-entry-index"
#define A_CMP_ENTRY_VALUE  "cmp-entry-value"
#define A_CMP_ENTRY_VAR  "cmp-entry-var"
#define A_CMP_VAR_VALUE  "cmp-var-value"
#define A_CMP_VAR_VAR  "cmp-var-var"
#define A_Completed  "completed"
#define A_DEEP_FIRST  "deep-first"
#define A_DEFAULT_MODEL  "default_model"
#define A_Defined  "defined"
#define A_Desc  "desc"
#define A_Dup  "dup"
#define A_ENTRY  "entry"

#define A_ENTRY_LEN  "entry-len"
#define A_ENTRY_ORDER  "entry-order"
#define A_Explain  "explain"
#define A_Failed  "failed"
#define A_Forward  "forward"
#define A_GC  "gc"
#define A_Halting  "halting"
#define A_HIGH_PRIORITY  "high-priority"
#define A_Index  "index"
#define A_Inherit  "inherit"
#define A_Limit  "limit"
#define A_M_TRACE  "?model-trace"
#define A_Max  "max"
#define A_Min  "min"
#define A_MODEL  "model"
#define A_Name  "name"
#define A_NOT_NIL  "not-nil"
#define A_On  "on"
#define A_One_Of  "one-of"
#define A_Order  "order"
#define A_Order_by  "order by"
#define A_Partial  "partial"
#define A_Priority  "priority"
#define A_Reasoned  "reasoned"

#define A_Removed  "removed"
#define A_RETE_TYPE  "rete-type"
#define A_Reverse  "reverse"
#define A_RULE  "rule"
#define A_Runnable  "runnable"
#define A_Running  "running"
#define A_SCHEMA  "schema"
#define A_SCOPE  "scope"
#define A_SELECT  "select"
#define A_SINGLE  "single"
#define A_State  "state"
#define A_Type  "type"
#define A_Uniq  "uniq"
#define A_Where  "where"
// IRAtom C_ENTRY = RulpFactory.createAtom(A_ENTRY);
// IRAtom C_RULE = RulpFactory.createAtom(A_RULE);
// long DEF_GC_CAPACITY = 2048;
// int DEF_GC_INACTIVE_LEAF = 30;
#define F_ADD_CONSTRAINT  "add-constraint"
#define F_ADD_INDEX  "add-index"
#define F_ADD_LAZY_STMT  "add-lazy-stmt"
#define F_ADD_NODE  "add-node"
#define F_ADD_NODE_FUNC  "add-node-func"
#define F_ADD_RULE  "add-rule"
#define F_ADD_STMT  "add-stmt"
#define F_ASSUME_STMT  "assume-stmt"
#define F_COMPUTE_STMT  "compute-stmt"
#define F_CREATE  "create"
#define F_DEF_QUERY_COUNTER  "def-query-counter"
#define F_DEFR  "defr"
#define F_DEFS  "defs"
#define F_DEFS_S  "->"
#define F_DUMP_ENTRY_INFO  "dump-entry-info"
#define F_DUMP_NODE_INFO  "dump-node-info"
#define F_DUMP_STATUS  "dump-status"
#define F_EXEC_RULE  "execute-rule"
#define F_FIX_STMT  "fix-stmt"
#define F_GC_MODEL  "gc-model"
#define F_GET_RETE_ENTRY  "get-rete-entry"
#define F_GET_RULE  "get-rule"
#define F_HAS_STMT  "has-stmt"
#define F_LIST_CONSTRAINT  "list-constraint"
#define F_LIST_SOURCE_NODE  "list-source-node"
#define F_LIST_STMT  "list-stmt"
#define F_LIST_STMT_ITERATOR  "list-stmt-iterator"
#define F_LIST_SUBGRAPH_FOR_QUERY  "list-subgraph-for-query"
#define F_LOAD_STMT  "load-stmt"
#define F_MAKE_REF_TREE  "make-ref-tree"
#define F_MBR_RULE_GROUP_NAMES  "$RG-names$"
#define F_MBR_RULE_GROUP_PRE  "$RG$"
#define F_MODEL_OF  "model-of"
#define F_OPT_MODEL  "opt-model"
#define F_PRINT_MODEL_STATUS  "print-model-status"
#define F_PRINT_RUNNABLE_COUNTER  "print-runnable-counter"
#define F_PRINT_TREE  "print-tree"
#define F_PRIORITY_OF  "priority-of"
#define F_QUERY_STMT  "query-stmt"
#define F_QUERY_STMT_ITERATOR  "query-stmt-iterator"
#define F_REMOVE_CONSTRAINT  "remove-constraint"
#define F_REMOVE_STMT  "remove-stmt"
#define F_RETE_ENTRY_COUNT_OF  "rete-entry-count-of"
#define F_RETE_NODE_OF  "rete-node-of"
#define F_RETE_QUEUE_TYPE_OF  "rete-queue-type-of"
#define F_SAVE_MODEL  "save-model"
#define F_SET  "set"
#define F_SET_DEFAULT_MODEL  "set-default-model"
#define F_SET_MODEL_CACHE_PATH  "set-model-cache-path"
#define F_SET_NODE_CACHE_PATH  "set-node-cache-path"
#define F_SET_NODE_QUEUE_TYPE  "set-node-queue-type"
#define F_SET_PRIORITY  "set-priority"
#define F_SIZE_OF_MODEL  "size-of-model"
#define F_START  "start"
#define F_STATE_OF  "state-of"
//      #define F_UPDATE_STMT  "update-stmt"
#define F_TRACE_RULE  "trace-rule"
//      #define F_TRY_ADD_STMT  "try-add-stmt"
#define F_TRAVEL_RETE_NODE  "travel-rete-node"
#define F_TRY_ADD_STMT  "try-add-stmt"
#define F_VAR_CHANGED  "var-changed"
// IRAtom O_Assumed = RulpFactory.createAtom(A_Assumed);
// IRAtom O_Completed = RulpFactory.createAtom(A_Completed);
// IRAtom O_Defined = RulpFactory.createAtom(A_Defined);
// IRAtom O_Failed = RulpFactory.createAtom(A_Failed);
// IRAtom O_Halting = RulpFactory.createAtom(A_Halting);
// IRAtom O_Limit = RulpFactory.createAtom(A_Limit);
// IRAtom O_On = RulpFactory.createAtom(A_On);
// IRAtom O_Partial = RulpFactory.createAtom(A_Partial);
// IRAtom O_Priority = RulpFactory.createAtom(A_Priority);
// IRAtom O_QUERY_STMT = RulpFactory.createAtom(F_QUERY_STMT);
// IRAtom O_Reasoned = RulpFactory.createAtom(A_Reasoned);
// IRAtom O_Removed = RulpFactory.createAtom(A_Removed);
// IRAtom O_Runnable = RulpFactory.createAtom(A_Runnable);
// IRAtom O_Running = RulpFactory.createAtom(A_Running);
// IRAtom O_State = RulpFactory.createAtom(A_State);
// IRAtom O_Type = RulpFactory.createAtom(A_Type);
// IRAtom O_Where = RulpFactory.createAtom(A_Where);
#define RETE_PRIORITY_ASSUMED       9
#define RETE_PRIORITY_DEAD          -99
#define RETE_PRIORITY_DEFAULT       99
#define RETE_PRIORITY_DISABLED      -9
#define RETE_PRIORITY_INACTIVE      0
#define RETE_PRIORITY_MAXIMUM       499 // maximum
#define RETE_PRIORITY_PARTIAL_MAX   599
#define RETE_PRIORITY_PARTIAL_MIN   500
#define RETE_PRIORITY_QUERY         199
#define RETE_PRIORITY_ROOT          900
#define RETE_PRIORITY_SYSTEM        999
#define STMT_MAX_LEN                1000
#define STMT_MIN_LEN                1
#define V_M_CST_INIT  "?cst-init"
#define V_M_GC_CAPACITY  "?model-gc-capacity"
#define V_M_GC_INACTIVE_LEAF  "?model-gc-inactive-leaf"
#define V_M_GC_INTERVAL  "?model-gc-interval"
#define V_M_GC_MAX_CACHE_NODE  "?model-gc-max-cache-node"
#define V_M_STATE  "?model-state"

#endif //__RULP_RULE_CONS_H__