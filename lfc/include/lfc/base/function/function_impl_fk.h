// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_FUNCTION_IMPL_FK_H_Dec_20_2010__
#define __LFC_FUNCTION_IMPL_FK_H_Dec_20_2010__

#include "lfc/base/function/function_impl.h"

#define  _LFC_FUN_DECLARE_FK(_TN, _TYPE) \
	template<typename R ,_TN>\
class function <R(_TYPE)>: public function<R,_TYPE>\
  {\
  typedef function <R(_TYPE)> this_type;\
  typedef function<R,_TYPE> base_type;\
  public:\
  function(): base_type(){}\
  template<typename F>function(F _f) : base_type(_f){}\
  this_type& operator = (const this_type& other)\
    {\
    this->m_p = other.m_p;\
    return *this;\
    };\
  function(const this_type& other)\
    { this->m_p = other.m_p; };\
  };


namespace lfc {

  template<typename R>
  class function <R()>: public function<R>{
    typedef function <R()> this_type;
    typedef function<R> base_type;

  public:
    function(): base_type(){}
    template<typename F>function(F _f) : base_type(_f){}

    this_type& operator = (const this_type& other){
      this->m_p = other.m_p;
      return *this;
    };

    function(const this_type& other){
      this->m_p = other.m_p;
    };

    bool operator == (const void* ptr) const {
      typedef typename base_type::base_type base_type2;
      return this->m_p.get() == (base_type2*)ptr; 
    }

    bool operator != (const void* ptr) const {
      typedef typename base_type::base_type base_type2;
      return this->m_p.get() != (base_type2*)ptr; 
    }

  };

  _LFC_FUN_DECLARE_FK(_L_FUN_TN_A1,_L_FUN_TYPE_A1);
  _LFC_FUN_DECLARE_FK(_L_FUN_TN_A2,_L_FUN_TYPE_A2);
  _LFC_FUN_DECLARE_FK(_L_FUN_TN_A3,_L_FUN_TYPE_A3);
  _LFC_FUN_DECLARE_FK(_L_FUN_TN_A4,_L_FUN_TYPE_A4);
  _LFC_FUN_DECLARE_FK(_L_FUN_TN_A5,_L_FUN_TYPE_A5);
  _LFC_FUN_DECLARE_FK(_L_FUN_TN_A6,_L_FUN_TYPE_A6);
  _LFC_FUN_DECLARE_FK(_L_FUN_TN_A7,_L_FUN_TYPE_A7);
  _LFC_FUN_DECLARE_FK(_L_FUN_TN_A8,_L_FUN_TYPE_A8);
  _LFC_FUN_DECLARE_FK(_L_FUN_TN_A9,_L_FUN_TYPE_A9);

}

#endif // __LFC_FUNCTION_IMPL_FK_H_Dec_20_2010__
