// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_ROBJECT_H__
#define __RULP_LANG_ROBJECT_H__
#include "rulp/object/IRAtom.h"
#include "rulp/object/IRBoolean.h"
#include "rulp/object/IRDouble.h"
#include "rulp/object/IRExpr.h"
#include "rulp/object/IRFloat.h"
#include "rulp/object/IRInteger.h"
#include "rulp/object/IRMember.h"
#include "rulp/object/IRLong.h"
#include "rulp/object/IRList.h"
#include "rulp/object/IRString.h"
#include "rulp/runtime/IRFramePool.h"

#define _R_GET_NAME(_type, _name) \
  get_global_object_##_type##_of_##_name

#define _R_GET_OBJ_DEC(_type, _name) \
  static _type* _R_GET_NAME(_type, _name)()

#define _R_GET_OBJ_IMPL(_type, _name) \
  _type* RGlobal::_R_GET_NAME(_type, _name)()

#define MAX_GLOBAL_INT                 128
#define MIN_GLOBAL_INT                 -127
#define MAX_GLOBAL_LONG                128
#define MIN_GLOBAL_LONG                -127

#define IS_GLOBAL_OBJECT(obj)     RGlobal::is_global_object(obj)

#define O_B_AND                   RGlobal::_R_GET_NAME(IRAtom     , B_AND)()
#define O_COMPUTE                 RGlobal::_R_GET_NAME(IRAtom     , compute)()
#define O_CONST                   RGlobal::_R_GET_NAME(IRAtom     , const)()
#define O_Default                 RGlobal::_R_GET_NAME(IRAtom     , default)()
#define O_EMPTY                   RGlobal::_R_GET_NAME(IRAtom     , empty)()
#define O_Final                   RGlobal::_R_GET_NAME(IRAtom     , final)()
#define O_From                    RGlobal::_R_GET_NAME(IRAtom     , from)()
#define O_LAMBDA                  RGlobal::_R_GET_NAME(IRAtom     , lambda)()
#define O_LINUX                   RGlobal::_R_GET_NAME(IRAtom     , linux)()
#define O_Nan                     RGlobal::_R_GET_NAME(IRAtom     , nan)()
#define O_Nil                     RGlobal::_R_GET_NAME(IRAtom     , nil)()
#define O_OPT_ID                  RGlobal::_R_GET_NAME(IRAtom     , opt_id)()
#define O_Public                  RGlobal::_R_GET_NAME(IRAtom     , public)()
#define O_Private                 RGlobal::_R_GET_NAME(IRAtom     , private)()
#define O_QUESTION_LIST           RGlobal::_R_GET_NAME(IRAtom     , QUESTION_LIST)()
#define O_RETURN                  RGlobal::_R_GET_NAME(IRAtom     , return)()
#define O_RETURN_TYPE             RGlobal::_R_GET_NAME(IRAtom     , RETURN_TYPE)()
#define O_Static                  RGlobal::_R_GET_NAME(IRAtom     , static)()
#define O_STABLE                  RGlobal::_R_GET_NAME(IRAtom     , stable)()
#define O_THREAD_UNSAFE           RGlobal::_R_GET_NAME(IRAtom     , THREAD_UNSAFE)()
#define O_WIN                     RGlobal::_R_GET_NAME(IRAtom     , win)()

#define O_True                    RGlobal::_R_GET_NAME(IRBoolean  , true)()
#define O_False                   RGlobal::_R_GET_NAME(IRBoolean  , false)()

#define O_INT_0                   RGlobal::_R_GET_NAME(IRInteger  , int_0)()
#define O_INT_1                   RGlobal::_R_GET_NAME(IRInteger  , int_1)()
#define O_FLOAT_0                 RGlobal::_R_GET_NAME(IRFloat    , float_0)()
#define O_DOUBLE_0                RGlobal::_R_GET_NAME(IRDouble   , double_0)()
#define O_LONG_0                  RGlobal::_R_GET_NAME(IRLong     , long_0)()

#define O_EMPTY_LIST              RGlobal::_R_GET_NAME(IRList     , empty)()
#define O_EMPTY_EXPR              RGlobal::_R_GET_NAME(IRExpr     , empty)()
#define O_EMPTY_STR               RGlobal::_R_GET_NAME(IRString   , empty)()

#define O_ATOM_OF(value)          RGlobal::get_global_object_atom_of(value)
#define O_INT_OF(value)           RGlobal::get_global_object_int_of(value)
#define O_LONG_OF(value)          RGlobal::get_global_object_long_of(value)

#define O_FRAME_POOL              RGlobal::get_global_frame_pool()

#define T_Array                   RGlobal::_R_GET_NAME(IRAtom , Array   )()
#define T_Atom                    RGlobal::_R_GET_NAME(IRAtom , Atom    )()
#define T_Blob                    RGlobal::_R_GET_NAME(IRAtom , Blob    )()
#define T_Bool                    RGlobal::_R_GET_NAME(IRAtom , Bool    )()
#define T_Class                   RGlobal::_R_GET_NAME(IRAtom , Class   )()
#define T_Constant                RGlobal::_R_GET_NAME(IRAtom , Constant)()
#define T_Double                  RGlobal::_R_GET_NAME(IRAtom , Double  )()
#define T_Expr                    RGlobal::_R_GET_NAME(IRAtom , Expr    )()
#define T_Factor                  RGlobal::_R_GET_NAME(IRAtom , Factor  )()
#define T_Float                   RGlobal::_R_GET_NAME(IRAtom , Float   )()
#define T_Frame                   RGlobal::_R_GET_NAME(IRAtom , Frame   )()
#define T_Func                    RGlobal::_R_GET_NAME(IRAtom , Func    )()
#define T_Instance                RGlobal::_R_GET_NAME(IRAtom , Instance)()
#define T_Int                     RGlobal::_R_GET_NAME(IRAtom , Int     )()
#define T_Iterator                RGlobal::_R_GET_NAME(IRAtom , Iterator)()
#define T_List                    RGlobal::_R_GET_NAME(IRAtom , List    )()
#define T_Long                    RGlobal::_R_GET_NAME(IRAtom , Long    )()
#define T_Macro                   RGlobal::_R_GET_NAME(IRAtom , Macro   )()
#define T_Member                  RGlobal::_R_GET_NAME(IRAtom , Member  )()
#define T_Native                  RGlobal::_R_GET_NAME(IRAtom , Native  )()
#define T_String                  RGlobal::_R_GET_NAME(IRAtom , String  )()
#define T_Template                RGlobal::_R_GET_NAME(IRAtom , Template)()
#define T_Var                     RGlobal::_R_GET_NAME(IRAtom , Var     )()


namespace lfc {
class RGlobal {

public:

  static bool is_global_object(const IRObject* obj);

public:

  _R_GET_OBJ_DEC(IRAtom   , B_AND     );
  _R_GET_OBJ_DEC(IRAtom   , compute   );
  _R_GET_OBJ_DEC(IRAtom   , const     );
  _R_GET_OBJ_DEC(IRAtom   , default   );
  _R_GET_OBJ_DEC(IRAtom   , empty     );
  _R_GET_OBJ_DEC(IRAtom   , final     );
  _R_GET_OBJ_DEC(IRAtom   , from      );
  _R_GET_OBJ_DEC(IRAtom   , lambda    );
  _R_GET_OBJ_DEC(IRAtom   , linux     );
  _R_GET_OBJ_DEC(IRAtom   , nan       );
  _R_GET_OBJ_DEC(IRAtom   , nil       );
  _R_GET_OBJ_DEC(IRAtom   , opt_id    );
  _R_GET_OBJ_DEC(IRAtom   , public    );
  _R_GET_OBJ_DEC(IRAtom   , private   );
  _R_GET_OBJ_DEC(IRAtom   , QUESTION_LIST   );
  _R_GET_OBJ_DEC(IRAtom   , return    );
  _R_GET_OBJ_DEC(IRAtom   , RETURN_TYPE );
  _R_GET_OBJ_DEC(IRAtom   , static    );
  _R_GET_OBJ_DEC(IRAtom   , stable    );
  _R_GET_OBJ_DEC(IRAtom   , THREAD_UNSAFE );
  _R_GET_OBJ_DEC(IRAtom   , win       );

  _R_GET_OBJ_DEC(IRAtom   , Array     );
  _R_GET_OBJ_DEC(IRAtom   , Atom      );
  _R_GET_OBJ_DEC(IRAtom   , Blob      );
  _R_GET_OBJ_DEC(IRAtom   , Bool      );
  _R_GET_OBJ_DEC(IRAtom   , Class     );
  _R_GET_OBJ_DEC(IRAtom   , Constant  );
  _R_GET_OBJ_DEC(IRAtom   , Double    );
  _R_GET_OBJ_DEC(IRAtom   , Expr      );
  _R_GET_OBJ_DEC(IRAtom   , Factor    );
  _R_GET_OBJ_DEC(IRAtom   , Float     );
  _R_GET_OBJ_DEC(IRAtom   , Frame     );
  _R_GET_OBJ_DEC(IRAtom   , Func      );
  _R_GET_OBJ_DEC(IRAtom   , Instance  );
  _R_GET_OBJ_DEC(IRAtom   , Int       );
  _R_GET_OBJ_DEC(IRAtom   , Iterator  );
  _R_GET_OBJ_DEC(IRAtom   , List      );
  _R_GET_OBJ_DEC(IRAtom   , Long      );
  _R_GET_OBJ_DEC(IRAtom   , Macro     );
  _R_GET_OBJ_DEC(IRAtom   , Member    );
  _R_GET_OBJ_DEC(IRAtom   , Native    );
  _R_GET_OBJ_DEC(IRAtom   , String    );
  _R_GET_OBJ_DEC(IRAtom   , Template  );
  _R_GET_OBJ_DEC(IRAtom   , Var       );

  _R_GET_OBJ_DEC(IRBoolean, true);
  _R_GET_OBJ_DEC(IRBoolean, false);
  _R_GET_OBJ_DEC(IRInteger, int_0);
  _R_GET_OBJ_DEC(IRInteger, int_1);
  _R_GET_OBJ_DEC(IRLong   , long_0);
  _R_GET_OBJ_DEC(IRFloat  , float_0);
  _R_GET_OBJ_DEC(IRDouble , double_0);
  _R_GET_OBJ_DEC(IRList   , empty);
  _R_GET_OBJ_DEC(IRExpr   , empty);
  _R_GET_OBJ_DEC(IRString , empty);

  static IRAtom*      get_global_object_atom_of(const std::string& name);
  static IRInteger*   get_global_object_int_of(int value);
  static IRLong*      get_global_object_long_of(long value);
  static IRFramePool* get_global_frame_pool();

  static const std::vector<IRAtom*>&  get_global_object_all_atoms();

  static int getFrameMaxId();
  static int getFrameFreeIdCount();
  static std::vector<IRFrame*> listGlobalFrames();

public:

  // static const std::string& get_global_string_true();
  // static const std::string& get_global_string_false();

  static void reset();

};


} // namespace lfc

#endif //__RULP_LANG_ROBJECT_H__