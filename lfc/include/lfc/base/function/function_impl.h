#ifndef __LFC_FUNCTION_IMPL_H_Dec_8_2010__
#define __LFC_FUNCTION_IMPL_H_Dec_8_2010__

#include "lfc/base/function/function_base.h"
#include "lfc/base/function/function_fwd.h"
#include "lfc/base/function/function_impl_F.h"
#include "lfc/base/function/function_impl_bind.h"
#include "lfc/base/function/bind/bind_fwd.h"

namespace lfc {

  template<typename R ,_L_FUN_TN_A9_VOID>
  class function 
    : public function_fwd<R, _fun::_function_base<R,_L_FUN_TYPE_A9>,_L_FUN_TYPE_A9>{
  public:	

    typedef function<R,_L_FUN_TYPE_A9> this_type;
    typedef _fun::_function_base<R,_L_FUN_TYPE_A9> base_type;

    template<typename F, class Enable = void>
    struct buider{
      typedef _fun::_function_F<R,F,_L_FUN_TYPE_A9> impl_fun_type;
      static void buid(this_type& _this, F& _f){
        _this.m_p.reset(new impl_fun_type(_f));
      }
    };

    template<typename F>
    struct buider<F,typename enable_if<_fun::is_bind_fwd<F>::value>::type>{
      typedef _fun::_function_bind_t<R,F,_L_FUN_TYPE_A9> impl_fun_type;
      static void buid(this_type& _this, F& _f){
        _this.m_p.reset(new impl_fun_type(_f));
      }
    };

    template<>
    struct buider<std::nullptr_t>{
      static void buid(this_type& _this, std::nullptr_t&){
        _this.m_p = nullptr;
      }
    };


  public:

    function(){};

    virtual ~function(){}

    template<typename F>
    function(F _f){
      buider<F>::buid(*this,_f);
    }
    
    function(const this_type& other){
      this->m_p = other.m_p;
    }

    bool operator == (const void* ptr) const {
      return this->m_p.get() == (base_type*)ptr; 
    }

    bool operator != (const void* ptr) const {
      return this->m_p.get() != (base_type*)ptr; 
    }

    this_type& operator = (const this_type& other){
      this->m_p = other.m_p;
      return *this;
    };

    // this_type& operator = (std::nullptr_t){
    //   this->m_p.reset(NULL);
    //   return *this;
    // };

    template<typename F>
    this_type& operator = (F _f){
      reset();
      buider<F>::buid(*this,_f);		
      return *this;
    }

    inline bool isNull(){
      return this->m_p == 0;
    }

    inline void reset(){
      this->m_p = 0;;
    }
  };

} // namespace lfc

#endif // __LFC_FUNCTION_IMPL_H_Dec_8_2010__
