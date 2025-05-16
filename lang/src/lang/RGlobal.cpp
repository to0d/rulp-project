// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/lang/RGlobal.h"
#include "rulp/lang/RConstant.h"
#include "rulp/utils/RulpUtil.h"
#include "rulp/utils/RuntimeUtil.h"
#include "../atom/XRAtomGlobal.h"
#include "../bool/XRBooleanGlobal.h"
#include "../scalar/XRIntegerGlobal.h"
#include "../scalar/XRLongGlobal.h"
#include "../scalar/XRFloatGlobal.h"
#include "../scalar/XRDoubleGlobal.h"
#include "../string/XRStringGlobal.h"
#include "../list/XRListConst.h"
#include "../runtime/XRFramePool.h"
#include "lfc/base/to_string.h"
#include <map>
#include <string.h>
#include <iostream>

namespace lfc {

using namespace lfc;

#define FRAME_POOL_1_MAX  256

#define COMMON_ATOM_VEC \
{ \
    F_ACCESS\
  , F_ADD_ATTRIBUTE \
  , F_ADD_ARRAY_TO_LIST \
  , F_ADD_LIST_TO_ARRAY \
  , F_ADD_LIST_TO_LIST \
  , F_ADD_SEARCH_FRAME\
  , F_ATTRIBUTE_OF  \
  , F_ALIAS         \
  , F_B_AND         \
  , F_B_NOT         \
  , F_B_OR          \
  , F_BREAK         \
  , F_BLOB_LENGTH   \
  , F_CASE          \
  , F_CAN_CAST      \
  , F_CMP_DEF       \
  , F_CLASS_OF      \
  , F_CLONE         \
  , F_COMPUTE       \
  , A_CONST         \
  , F_CONTINUE      \
  , F_DATE          \
  , F_DAY_OF_WEEK   \
  , F_DAY_NUMBER    \
  , A_DEFAULT       \
  , F_DEFCLASS      \
  , F_DEFUN         \
  , F_DEFMACRO      \
  , F_DEFTEMPLATE   \
  , F_DEFVAR        \
  , F_DEF_CONST     \
  , F_DELETE        \
  , A_DO            \
  , F_DO_WHEN_VAR_CHANGED \
  , F_DO_WHEN_OBJ_DELETED \
  , F_E_ERROR_VALUE \
  , A_EMPTY         \
  , F_EQUAL_DEFAULT \
  , A_FINAL         \
  , F_FREAME_OF     \
  , A_FROM          \
  , F_FOREACH       \
  , F_FORMAT        \
  , F_FILE_DELETE   \
  , F_FILE_EXIST    \
  , F_FILE_IS_FOLDER \
  , F_FILE_MKDIRS   \
  , F_FILE_PARENT   \
  , F_GET_ATTRIBUTE \
  , F_GET_OF_ARRAY  \
  , F_GET_OF_LIST   \
  , F_HAS_MBR       \
  , F_HAS_NEXT      \
  , F_IF            \
  , F_INIT_LOADER   \
  , F_IS_CONST      \
  , F_IS_DEBUG_ACTIBE \
  , F_IS_RECURSIVE  \
  , F_IS_STABLE     \
  , F_JOIN          \
  , F_LAMBDA        \
  , A_LINUX         \
  , F_LOAD          \
  , F_LET           \
  , F_LIST_OF       \
  , F_LOOP          \
  , F_MAKE_ARRAY    \
  , F_MAKE_BLOB     \
  , F_MAKE_STRING   \
  , F_MAKE_LIST     \
  , F_MAKE_LIST_ITERATOR\
  , A_NAN           \
  , F_NAME_OF       \
  , F_NEW           \
  , F_NEXT          \
  , A_OPT_ID        \
  , F_O_ADD         \
  , F_O_SUB         \
  , F_O_BY          \
  , F_O_DIV         \
  , F_O_MOD         \
  , F_O_POWER       \
  , F_O_AND         \
  , F_O_OR          \
  , F_O_XOR         \
  , F_O_EQ          \
  , F_O_MBR         \
  , F_O_NE          \
  , F_O_NOT         \
  , F_O_GT          \
  , F_O_LT          \
  , F_O_GE          \
  , F_O_LE          \
  , F_OUT_TO_FILE   \
  , F_OPT_STATUS    \
  , F_PRINT         \
  , F_PRINT_FRAME_TREE  \
  , F_PRINT_GLOBAL_INFO \
  , F_PRINT_IMPL    \
  , F_PRINT_OBJECT  \
  , F_PARENT_OF     \
  , A_PUBLIC        \
  , A_PRIVATE       \
  , F_PROPERTY_OF   \
  , A_QUESTION_LIST \
  , F_RETURN        \
  , F_RETURN_TYPE_OF\
  , F_WHEN          \
  , F_RANDOM        \
  , F_RANDOM_DOUBLE \
  , F_RANDOM_FLOAT  \
  , F_READ_LINE     \
  , A_RETURN_TYPE   \
  , F_REMOVE_ALL_LIST \
  , F_REVERSE       \
  , F_REF           \
  , F_RULP_OBJ_COUNT \
  , F_RUN           \
  , F_RUNTIME_CALL_COUNT \
  , F_SAVE_TXT_FILE \
  , F_SETQ          \
  , F_SETA          \
  , F_SIZE_OF_ARRAY \
  , F_SIZE_OF_LIST  \
  , F_SORT_LIST     \
  , A_STATIC        \
  , ATTR_STABLE        \
  , F_STMT_COUNT_OF \
  , F_STRCAT        \
  , F_STR_CHAR_AT   \
  , F_STR_END_WITH  \
  , F_STR_EQUAL     \
  , F_STR_EQUAL_NOCASE\
  , F_STR_FORMAT    \
  , F_STR_MATCH     \
  , F_STR_INDEX_OF  \
  , F_STR_LAST_INDEX_OF \
  , F_STR_LENGTH    \
  , F_STR_REPLACE   \
  , F_STR_START_WITH \
  , F_STR_SUBSTR    \
  , F_STR_SPLIT_BY_CHAR \
  , F_STR_TRIM      \
  , F_STR_TRIM_HEAD \
  , F_STR_TRIM_TAIL \
  , F_STR_UPPER     \
  , F_SUBJECT_OF    \
  , F_SEARCH_FRAEM_OF \
  , F_SYS_OS_TYPE   \
  , F_SYS_TIME      \
  , A_THREAD_UNSAFE \
  , F_THROW         \
  , F_TRY           \
  , F_TYPE_OF       \
  , F_TO_STRING     \
  , F_TO_ATOM       \
  , F_TO_CONST      \
  , F_TO_DOUBLE     \
  , F_TO_EXPR       \
  , F_TO_FLOAT      \
  , F_TO_INT        \
  , F_TO_LONG       \
  , F_TO_NAMED_LIST \
  , F_TO_NONAMED_LIST \
  , F_TO_VARY       \
  , F_TRACE         \
  , F_UNION         \
  , F_UNIQ          \
  , F_VALUE_OF      \
  , F_VALUE_TYPE_OF \
  , A_WIN           \
  , F_WRITE_BLOB    \
  , A_ARRAY         \
  , A_ATOM          \
  , A_BLOB          \
  , A_BOOL          \
  , A_CLASS         \
  , A_CONSTANT      \
  , A_DOUBLE        \
  , A_EXPRESSION    \
  , A_FACTOR        \
  , A_FLOAT         \
  , A_FRAME         \
  , A_FUNCTION      \
  , A_INSTANCE      \
  , A_INTEGER       \
  , A_ITERATOR      \
  , A_LIST          \
  , A_LONG          \
  , A_MACRO         \
  , A_MEMBER        \
  , A_NATIVE        \
  , A_STRING        \
  , A_TEMPLATE      \
  , A_VAR           \
  , "?a0"           \
  , "?a1"           \
  , "?a2"           \
  , "?a3"           \
  , "?a4"           \
  , "?a5"           \
  , "?a6"           \
  , "?a7"           \
  , "?a8"           \
  , "?a9"           \
  , "?0"            \
  , "?1"            \
  , "?2"            \
}

constexpr 
const char* CONSTEXPR_COMMON_ATOM_NAMES[] = COMMON_ATOM_VEC;
constexpr bool _isEqual(const char* a, const char* b) {
  while (*a != '\0' && *b != '\0') {
    if (*a != *b) {
      return false; 
    }
    ++a;
    ++b;
  }
  return *a == '\0' && *b == '\0';
}

constexpr int _countOfCommonAtom() {
  int count = 0;
  for(auto name : CONSTEXPR_COMMON_ATOM_NAMES){
    ++count;
  }
  return count;
}

constexpr int _indexOfCommonAtom(const char* name) {
  const int count = _countOfCommonAtom();
  for(int i = 0; i < count; ++i){
    if(_isEqual(CONSTEXPR_COMMON_ATOM_NAMES[i], name))
      return i;
  }

  return -1;
}


static_assert(_indexOfCommonAtom(F_ACCESS) == 0);
static_assert(_countOfCommonAtom() == 208);

#define COMMON_ATOM_LEN     _countOfCommonAtom()
#define ATOM_INDEX_OF(x)    _indexOfCommonAtom(x)

std::string COMMON_ATOM_NAMES[COMMON_ATOM_LEN] = COMMON_ATOM_VEC;

// class XRNilAtom : public XRAtomGlobal {
// public:
//   XRNilAtom() : XRAtomGlobal(A_NIL) {};
//   virtual ~XRNilAtom() = default;
  
//   virtual RType getType() const override {return T_NIL;};
// };

struct G_Object{
  XRAtomGlobal      ATOM_COMMON_LIST[COMMON_ATOM_LEN];
  XRAtomGlobal      NIL;

  XRBooleanGlobal   BOOL_TRUE;
  XRBooleanGlobal   BOOL_FALSE;
  
  XRIntegerGlobal   INT_VALUES[MAX_GLOBAL_INT - MIN_GLOBAL_INT + 1];
  XRIntegerGlobal*  INT_0 = NULL;
  XRIntegerGlobal*  INT_1 = NULL;

  XRLongGlobal      LONG_VALUES[MAX_GLOBAL_LONG - MIN_GLOBAL_LONG + 1];
  XRLongGlobal*     LONG_0 = NULL;

  XRFloatGlobal     FLOAT_0;  
  XRDoubleGlobal    DOUBLE_0;

  XRStringGlobal    STRING_EMPTY;  
  XRListConst       LIST_EMPTY;
  XRListConst       EXPR_EMPTY;

  std::string       STR_TRUE    = A_TRUE;
  std::string       STR_FALSE   = A_FALSE;
 
  std::map<std::string, IRAtom*>  all_atom_map;
  std::vector<IRAtom*>            all_atom_list;

  XRFramePool       framePool;

  G_Object()
    : NIL           (A_NIL)
    , BOOL_TRUE     (true)
    , BOOL_FALSE    (false)
    , FLOAT_0       (0)
    , DOUBLE_0      (0)
    , STRING_EMPTY  ("")
    , LIST_EMPTY    (T_LIST)
    , EXPR_EMPTY    (T_EXPR)
    , framePool     (FRAME_POOL_1_MAX)
  {
    all_atom_map[NIL.getName()] = &NIL;

    {
      for(int i = 0; i < COMMON_ATOM_LEN; ++i ){
        auto& ATOM = ATOM_COMMON_LIST[i];
        ATOM.setName(COMMON_ATOM_NAMES[i]);

        all_atom_map[ATOM.getName()] = &ATOM;
        all_atom_list.push_back(&ATOM);
      }
    }
    
    {
      for(int i = MIN_GLOBAL_INT; i <= MAX_GLOBAL_INT; ++i ){
        auto& VAL = INT_VALUES[i - MIN_GLOBAL_INT];
        VAL.setValue(i);
        VAL.setString(RulpUtil::formatInt(i));
      }

      INT_0 = &INT_VALUES[0 - MIN_GLOBAL_INT];
      INT_1 = &INT_VALUES[1 - MIN_GLOBAL_INT];
    }

    {
      for(long i = MIN_GLOBAL_LONG; i <= MAX_GLOBAL_LONG; ++i ){
        auto& VAL = LONG_VALUES[i - MIN_GLOBAL_INT];
        VAL.setValue(i);
        VAL.setString(RulpUtil::formatLong(i));
      }

      LONG_0 = &LONG_VALUES[0 - MIN_GLOBAL_INT];
    }

    FLOAT_0.setString(RulpUtil::formatFloat(0));
    DOUBLE_0.setString(RulpUtil::formatDouble(0));

    {
      BOOL_TRUE.setString(STR_TRUE);
      BOOL_FALSE.setString(STR_FALSE);
    }

  }
};


static G_Object _G;

_R_GET_OBJ_IMPL(IRAtom    , B_AND   ){ return &_G.ATOM_COMMON_LIST[ATOM_INDEX_OF(F_B_AND)]; }
_R_GET_OBJ_IMPL(IRAtom    , compute ){ return &_G.ATOM_COMMON_LIST[ATOM_INDEX_OF(F_COMPUTE)]; }
_R_GET_OBJ_IMPL(IRAtom    , const   ){ return &_G.ATOM_COMMON_LIST[ATOM_INDEX_OF(A_CONST)]; }
_R_GET_OBJ_IMPL(IRAtom    , default ){ return &_G.ATOM_COMMON_LIST[ATOM_INDEX_OF(A_DEFAULT)]; }
_R_GET_OBJ_IMPL(IRAtom    , empty   ){ return &_G.ATOM_COMMON_LIST[ATOM_INDEX_OF(A_EMPTY)]; }
_R_GET_OBJ_IMPL(IRAtom    , final   ){ return &_G.ATOM_COMMON_LIST[ATOM_INDEX_OF(A_FINAL)]; }
_R_GET_OBJ_IMPL(IRAtom    , from    ){ return &_G.ATOM_COMMON_LIST[ATOM_INDEX_OF(A_FROM)]; }
_R_GET_OBJ_IMPL(IRAtom    , lambda  ){ return &_G.ATOM_COMMON_LIST[ATOM_INDEX_OF(F_LAMBDA)]; }
_R_GET_OBJ_IMPL(IRAtom    , linux   ){ return &_G.ATOM_COMMON_LIST[ATOM_INDEX_OF(A_LINUX)]; }
_R_GET_OBJ_IMPL(IRAtom    , nan     ){ return &_G.ATOM_COMMON_LIST[ATOM_INDEX_OF(A_NAN)]; }
_R_GET_OBJ_IMPL(IRAtom    , nil     ){ return &_G.NIL; }
_R_GET_OBJ_IMPL(IRAtom    , opt_id  ){ return &_G.ATOM_COMMON_LIST[ATOM_INDEX_OF(A_OPT_ID)]; }
_R_GET_OBJ_IMPL(IRAtom    , public  ){ return &_G.ATOM_COMMON_LIST[ATOM_INDEX_OF(A_PUBLIC)]; }
_R_GET_OBJ_IMPL(IRAtom    , private ){ return &_G.ATOM_COMMON_LIST[ATOM_INDEX_OF(A_PRIVATE)]; }
_R_GET_OBJ_IMPL(IRAtom    , QUESTION_LIST ){ return &_G.ATOM_COMMON_LIST[ATOM_INDEX_OF(A_QUESTION_LIST)]; }
_R_GET_OBJ_IMPL(IRAtom    , return  ){ return &_G.ATOM_COMMON_LIST[ATOM_INDEX_OF(F_RETURN)]; }
_R_GET_OBJ_IMPL(IRAtom    , RETURN_TYPE  ){ return &_G.ATOM_COMMON_LIST[ATOM_INDEX_OF(A_RETURN_TYPE)];   ; }
_R_GET_OBJ_IMPL(IRAtom    , static  ){ return &_G.ATOM_COMMON_LIST[ATOM_INDEX_OF(A_STATIC)]; }
_R_GET_OBJ_IMPL(IRAtom    , stable  ){ return &_G.ATOM_COMMON_LIST[ATOM_INDEX_OF(ATTR_STABLE)]; }
_R_GET_OBJ_IMPL(IRAtom    , THREAD_UNSAFE  ){ return &_G.ATOM_COMMON_LIST[ATOM_INDEX_OF(A_THREAD_UNSAFE)]; }
_R_GET_OBJ_IMPL(IRAtom    , win     ){ return &_G.ATOM_COMMON_LIST[ATOM_INDEX_OF(A_WIN)]; }
_R_GET_OBJ_IMPL(IRAtom    , Array   ){ return &_G.ATOM_COMMON_LIST[ATOM_INDEX_OF(A_ARRAY      )]; }
_R_GET_OBJ_IMPL(IRAtom    , Atom    ){ return &_G.ATOM_COMMON_LIST[ATOM_INDEX_OF(A_ATOM       )]; }
_R_GET_OBJ_IMPL(IRAtom    , Blob    ){ return &_G.ATOM_COMMON_LIST[ATOM_INDEX_OF(A_BLOB       )]; }
_R_GET_OBJ_IMPL(IRAtom    , Bool    ){ return &_G.ATOM_COMMON_LIST[ATOM_INDEX_OF(A_BOOL       )]; }
_R_GET_OBJ_IMPL(IRAtom    , Class   ){ return &_G.ATOM_COMMON_LIST[ATOM_INDEX_OF(A_CLASS      )]; }
_R_GET_OBJ_IMPL(IRAtom    , Constant){ return &_G.ATOM_COMMON_LIST[ATOM_INDEX_OF(A_CONSTANT   )]; }
_R_GET_OBJ_IMPL(IRAtom    , Double  ){ return &_G.ATOM_COMMON_LIST[ATOM_INDEX_OF(A_DOUBLE     )]; }
_R_GET_OBJ_IMPL(IRAtom    , Expr    ){ return &_G.ATOM_COMMON_LIST[ATOM_INDEX_OF(A_EXPRESSION )]; }
_R_GET_OBJ_IMPL(IRAtom    , Factor  ){ return &_G.ATOM_COMMON_LIST[ATOM_INDEX_OF(A_FACTOR     )]; }
_R_GET_OBJ_IMPL(IRAtom    , Float   ){ return &_G.ATOM_COMMON_LIST[ATOM_INDEX_OF(A_FLOAT      )]; }
_R_GET_OBJ_IMPL(IRAtom    , Frame   ){ return &_G.ATOM_COMMON_LIST[ATOM_INDEX_OF(A_FRAME      )]; }
_R_GET_OBJ_IMPL(IRAtom    , Func    ){ return &_G.ATOM_COMMON_LIST[ATOM_INDEX_OF(A_FUNCTION   )]; }
_R_GET_OBJ_IMPL(IRAtom    , Instance){ return &_G.ATOM_COMMON_LIST[ATOM_INDEX_OF(A_INSTANCE   )]; }
_R_GET_OBJ_IMPL(IRAtom    , Int     ){ return &_G.ATOM_COMMON_LIST[ATOM_INDEX_OF(A_INTEGER    )]; }
_R_GET_OBJ_IMPL(IRAtom    , Iterator){ return &_G.ATOM_COMMON_LIST[ATOM_INDEX_OF(A_ITERATOR   )]; }
_R_GET_OBJ_IMPL(IRAtom    , List    ){ return &_G.ATOM_COMMON_LIST[ATOM_INDEX_OF(A_LIST       )]; }
_R_GET_OBJ_IMPL(IRAtom    , Long    ){ return &_G.ATOM_COMMON_LIST[ATOM_INDEX_OF(A_LONG       )]; }
_R_GET_OBJ_IMPL(IRAtom    , Macro   ){ return &_G.ATOM_COMMON_LIST[ATOM_INDEX_OF(A_MACRO      )]; }
_R_GET_OBJ_IMPL(IRAtom    , Member  ){ return &_G.ATOM_COMMON_LIST[ATOM_INDEX_OF(A_MEMBER     )]; }
_R_GET_OBJ_IMPL(IRAtom    , Native  ){ return &_G.ATOM_COMMON_LIST[ATOM_INDEX_OF(A_NATIVE     )]; }
_R_GET_OBJ_IMPL(IRAtom    , String  ){ return &_G.ATOM_COMMON_LIST[ATOM_INDEX_OF(A_STRING     )]; }
_R_GET_OBJ_IMPL(IRAtom    , Template){ return &_G.ATOM_COMMON_LIST[ATOM_INDEX_OF(A_TEMPLATE   )]; }
_R_GET_OBJ_IMPL(IRAtom    , Var     ){ return &_G.ATOM_COMMON_LIST[ATOM_INDEX_OF(A_VAR        )]; }
_R_GET_OBJ_IMPL(IRBoolean , true    ){ return &_G.BOOL_TRUE     ; }
_R_GET_OBJ_IMPL(IRBoolean , false   ){ return &_G.BOOL_FALSE    ; }
_R_GET_OBJ_IMPL(IRInteger , int_0   ){ return _G.INT_0          ; }
_R_GET_OBJ_IMPL(IRInteger , int_1   ){ return _G.INT_1          ; }
_R_GET_OBJ_IMPL(IRFloat   , float_0 ){ return &_G.FLOAT_0       ; }
_R_GET_OBJ_IMPL(IRDouble  , double_0){ return &_G.DOUBLE_0      ; }
_R_GET_OBJ_IMPL(IRLong    , long_0  ){ return _G.LONG_0         ; }
_R_GET_OBJ_IMPL(IRList    , empty   ){ return &_G.LIST_EMPTY    ; }
_R_GET_OBJ_IMPL(IRExpr    , empty   ){ return &_G.EXPR_EMPTY    ; }
_R_GET_OBJ_IMPL(IRString  , empty   ){ return &_G.STRING_EMPTY  ; }


IRAtom* RGlobal::get_global_object_atom_of(const std::string& name){
  auto it = _G.all_atom_map.find(name);
  if(it == _G.all_atom_map.end())
    return NULL;

  return it->second;
}

IRInteger* RGlobal::get_global_object_int_of(int value){
  if(value >= MIN_GLOBAL_INT && value <= MAX_GLOBAL_INT){
    return &_G.INT_VALUES[value - MIN_GLOBAL_INT];
  }

  return NULL;
}

IRLong* RGlobal::get_global_object_long_of(long value){
  if(value >= MIN_GLOBAL_LONG && value <= MAX_GLOBAL_LONG){
    return &_G.LONG_VALUES[value - MIN_GLOBAL_LONG];
  }

  return NULL;
}

IRFramePool* RGlobal::get_global_frame_pool(){
  return &_G.framePool;
}

const std::vector<IRAtom*>& RGlobal::get_global_object_all_atoms(){
  return _G.all_atom_list;
}

std::vector<IRFrame*> RGlobal::listGlobalFrames(){
  return _G.framePool.listGlobalFrames();
}

bool RGlobal::is_global_object(const IRObject* obj){
  
  char* ptr = (char*) obj;

  char* begin = (char*) &_G;
  char* end   = begin + sizeof(_G); 

  return ptr >= begin && ptr < end; 
}

int RGlobal::getFrameMaxId() {
  return _G.framePool.getFrameMaxId();
}

int RGlobal::getFrameFreeIdCount() {
  return _G.framePool.getFrameFreeIdCount();
}

void RGlobal::reset(){
  _G.framePool.reset();
}

STATIC_OBJECT_REGISTER(O_Nil      , A_NIL);
STATIC_OBJECT_REGISTER(O_Nan      , A_NAN);
STATIC_OBJECT_REGISTER(O_True     , A_TRUE);
STATIC_OBJECT_REGISTER(O_False    , A_FALSE);
STATIC_OBJECT_REGISTER(O_Public   , A_PUBLIC);
STATIC_OBJECT_REGISTER(O_Private  , A_PRIVATE);
STATIC_OBJECT_REGISTER(O_Default  , A_DEFAULT);
STATIC_OBJECT_REGISTER(O_Final    , A_FINAL);
STATIC_OBJECT_REGISTER(O_Static   , A_STACK);
STATIC_OBJECT_REGISTER(O_From     , A_FROM);

STATIC_OBJECT_REGISTER(T_Atom     , A_ATOM);
STATIC_OBJECT_REGISTER(T_Bool     , A_BOOL);
STATIC_OBJECT_REGISTER(T_Int      , A_INTEGER);
STATIC_OBJECT_REGISTER(T_Long     , A_LONG);
STATIC_OBJECT_REGISTER(T_Float    , A_FLOAT);
STATIC_OBJECT_REGISTER(T_Double   , A_DOUBLE);
STATIC_OBJECT_REGISTER(T_String   , A_STRING);
STATIC_OBJECT_REGISTER(T_Blob     , A_BLOB);
STATIC_OBJECT_REGISTER(T_List     , A_LIST);
STATIC_OBJECT_REGISTER(T_Expr     , A_EXPRESSION);
STATIC_OBJECT_REGISTER(T_Array    , A_ARRAY);
STATIC_OBJECT_REGISTER(T_Var      , A_VAR);
STATIC_OBJECT_REGISTER(T_Constant , A_CONSTANT);
STATIC_OBJECT_REGISTER(T_Factor   , A_FACTOR);
STATIC_OBJECT_REGISTER(T_Func     , A_FUNCTION);
STATIC_OBJECT_REGISTER(T_Template , A_TEMPLATE);
STATIC_OBJECT_REGISTER(T_Macro    , A_MACRO);
STATIC_OBJECT_REGISTER(T_Instance , A_INSTANCE);
STATIC_OBJECT_REGISTER(T_Class    , A_CLASS);
STATIC_OBJECT_REGISTER(T_Native   , A_NATIVE);
STATIC_OBJECT_REGISTER(T_Member   , A_MEMBER);
STATIC_OBJECT_REGISTER(T_Frame    , A_FRAME);
STATIC_OBJECT_REGISTER(T_Iterator , A_ITERATOR);





} // namespace lfc
