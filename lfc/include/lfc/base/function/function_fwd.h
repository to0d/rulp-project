#ifndef __LFC_FUNCTION_FWD_H_08_27_12__
#define __LFC_FUNCTION_FWD_H_08_27_12__

#include "lfc/base/function/function_base.h"
#include <memory>

namespace lfc {

  template<typename R , typename P, _L_FUN_TN_A9_VOID>
  struct function_fwd{
    typedef std::shared_ptr<P> pointer_type;
    pointer_type m_p;
    R operator()(_L_FUN_SIG_A9){
      return (*m_p)(_L_FUN_INS_A9);
    }
  };

  template<typename R,typename P>
  struct function_fwd<R,P>{
    std::shared_ptr<P> m_p;
    R operator()(){
      return (*m_p)();
    }		
  };

  template<typename R , typename P ,_L_FUN_TN_A1>
  struct function_fwd<R, P ,_L_FUN_TYPE_A1 >{
    std::shared_ptr<P> m_p;
    R operator()(_L_FUN_SIG_A1){
      return (*m_p)(_L_FUN_INS_A1);
    }
  };

  template<typename R , typename P ,_L_FUN_TN_A2>
  struct function_fwd<R, P ,_L_FUN_TYPE_A2 >{
    std::shared_ptr<P> m_p;
    R operator()(_L_FUN_SIG_A2){
      return (*m_p)(_L_FUN_INS_A2);
    }
  };

  template<typename R , typename P ,_L_FUN_TN_A3>
  struct function_fwd<R, P ,_L_FUN_TYPE_A3 >{
    std::shared_ptr<P> m_p;
    R operator()(_L_FUN_SIG_A3){
      return (*m_p)(_L_FUN_INS_A3);
    }
  };

  template<typename R , typename P ,_L_FUN_TN_A4>
  struct function_fwd<R, P ,_L_FUN_TYPE_A4 >{
    std::shared_ptr<P> m_p;
    R operator()(_L_FUN_SIG_A4){
      return (*m_p)(_L_FUN_INS_A4);
    }
  };

  template<typename R , typename P ,_L_FUN_TN_A5>
  struct function_fwd<R, P ,_L_FUN_TYPE_A5 >{
    std::shared_ptr<P> m_p;
    R operator()(_L_FUN_SIG_A5){
      return (*m_p)(_L_FUN_INS_A5);
    }
  };

  template<typename R , typename P ,_L_FUN_TN_A6>
  struct function_fwd<R, P ,_L_FUN_TYPE_A6 >{
    std::shared_ptr<P> m_p;
    R operator()(_L_FUN_SIG_A6){
      return (*m_p)(_L_FUN_INS_A6);
    }
  };

  template<typename R , typename P ,_L_FUN_TN_A7>
  struct function_fwd<R, P ,_L_FUN_TYPE_A7 >{
    std::shared_ptr<P> m_p;
    R operator()(_L_FUN_SIG_A7){
      return (*m_p)(_L_FUN_INS_A7);
    }
  };

  template<typename R , typename P ,_L_FUN_TN_A8>
  struct function_fwd<R, P ,_L_FUN_TYPE_A8 >{
    std::shared_ptr<P> m_p;
    R operator()(_L_FUN_SIG_A8){
      return (*m_p)(_L_FUN_INS_A8);
    }
  };

}

#endif // __LFC_FUNCTION_FWD_H_08_27_12__
