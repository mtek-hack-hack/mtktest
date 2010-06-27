// Copyright (C) 2001 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 2, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING.  If not, write to the Free
// Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307,
// USA.

// As a special exception, you may use this file as part of a free software
// library without restriction.  Specifically, if other files instantiate
// templates or use macros or inline functions from this file, or you compile
// this file and link it with other files to produce an executable, this
// file does not by itself cause the resulting executable to be covered by
// the GNU General Public License.  This exception does not however
// invalidate any other reasons why the executable file might be covered by
// the GNU General Public License.

#ifndef _GLIBCPP_CPU_LIMITS
#define _GLIBCPP_CPU_LIMITS 1

#define __glibcpp_long_double_bits 80

// These constants are selected to be consistent with native
//   (msvcrt.dll)  representation of NaNs 	

#define __FLOAT_INF_REP { 0, 0x7f80 }
#define __FLOAT_QNAN_REP { 0, 0xffc0 }  // { 0, 0x7fc0 }
#define __FLOAT_SNAN_REP { 0, 0xff80 }  // { 1, 0x7f80 }
#define __FLOAT_DENORM_REP {1,0}

#define __DOUBLE_INF_REP { 0, 0, 0, 0x7ff0 }
#define __DOUBLE_QNAN_REP { 0, 0, 0, 0xfff8 }  // { 0, 0, 0, 0x7ff8 }
#define __DOUBLE_SNAN_REP { 0, 0, 0, 0xfff0 }  // { 1, 0, 0, 0x7ff0 }
#define __DOUBLE_DENORM_REP {1, 0, 0, 0 }

/* This assumes no implicit (hidden) bit in extended mode */

#define __LONG_DOUBLE_INF_REP { 0, 0, 0, 0x8000, 0x7fff, 0 }
#define __LONG_DOUBLE_QNAN_REP { 0, 0, 0, 0xc000, 0xffff, 0 }
#define __LONG_DOUBLE_SNAN_REP { 0, 0, 0, 0x8000, 0xffff, 0 }
#define __LONG_DOUBLE_DENORM_REP {1, 0, 0, 0, 0, 0 }

template <class __dummy>
class _iec559_consts
{
  public:
  union _rep
    {
      unsigned short word[6];
      float float_val;
      double double_val;
      long double ldouble_val;	
    } ;
  static const union _rep _S_QNaNF; 
  static const union _rep _S_SNaNF; 
  static const union _rep _S_InfF; 
  static const union _rep _S_DenormF; 
  static const union _rep _S_QNaN;
  static const union _rep _S_SNaN;
  static const union _rep _S_Inf;
  static const union _rep _S_Denorm;
  static const union _rep _S_QNaNL; 
  static const union _rep _S_SNaNL; 
  static const union _rep _S_InfL; 
  static const union _rep _S_DenormL; 
};

// Static const initialization
// float

template <class __dummy>
  const typename _iec559_consts<__dummy>::_rep
  _iec559_consts<__dummy>::_S_QNaNF = { __FLOAT_QNAN_REP };

template <class __dummy>
  const typename _iec559_consts<__dummy>::_rep
  _iec559_consts<__dummy>::_S_SNaNF = { __FLOAT_SNAN_REP };

template <class __dummy>
  const typename _iec559_consts<__dummy>::_rep
  _iec559_consts<__dummy>::_S_InfF = { __FLOAT_INF_REP }; 

template <class __dummy>
  const typename _iec559_consts<__dummy>::_rep
  _iec559_consts<__dummy>::_S_DenormF = { __FLOAT_DENORM_REP };

// double
template <class __dummy>
  const typename _iec559_consts<__dummy>::_rep
  _iec559_consts<__dummy>::_S_QNaN = { __DOUBLE_QNAN_REP };

template <class __dummy>
  const typename _iec559_consts<__dummy>::_rep
  _iec559_consts<__dummy>::_S_SNaN = { __DOUBLE_SNAN_REP };

template <class __dummy>
  const typename _iec559_consts<__dummy>::_rep
  _iec559_consts<__dummy>::_S_Inf = { __DOUBLE_INF_REP };

template <class __dummy>
  const typename _iec559_consts<__dummy>::_rep
  _iec559_consts<__dummy>::_S_Denorm  = { __DOUBLE_DENORM_REP };

// long double
template <class __dummy>
  const typename _iec559_consts<__dummy>::_rep
  _iec559_consts<__dummy>::_S_QNaNL = { __LONG_DOUBLE_QNAN_REP };

template <class __dummy>
  const typename _iec559_consts<__dummy>::_rep
  _iec559_consts<__dummy>::_S_SNaNL = { __LONG_DOUBLE_SNAN_REP };

template <class __dummy>
  const typename _iec559_consts<__dummy>::_rep
  _iec559_consts<__dummy>::_S_InfL = { __LONG_DOUBLE_INF_REP };

template <class __dummy>
  const typename _iec559_consts<__dummy>::_rep
  _iec559_consts<__dummy>::_S_DenormL  = { __LONG_DOUBLE_DENORM_REP };


// float

#define __glibcpp_float_has_infinity true
#define __glibcpp_float_has_quiet_NaN true
#define __glibcpp_float_has_signaling_NaN true
#define __glibcpp_float_has_denorm denorm_present
#define __glibcpp_float_has_denorm_loss true
#define __glibcpp_float_infinity \
	_iec559_consts<bool>::_S_InfF.float_val
#define __glibcpp_float_quiet_NaN \
	_iec559_consts<bool>::_S_QNaNF.float_val
#define __glibcpp_float_signaling_NaN \
	_iec559_consts<bool>::_S_SNaNF.float_val
#define __glibcpp_float_denorm_min \
	_iec559_consts<bool>::_S_DenormF.float_val
#define __glibcpp_float_is_iec559 true
#define __glibcpp_float_is_bounded true
#define __glibcpp_float_is_modulo false
#define __glibcpp_float_traps true
#define __glibcpp_float_tinyness_before true
#define __glibcpp_float_round_style round_to_nearest

// double

#define __glibcpp_double_has_infinity true
#define __glibcpp_double_has_quiet_NaN true
#define __glibcpp_double_has_signaling_NaN true
#define __glibcpp_double_has_denorm denorm_present
#define __glibcpp_double_has_denorm_loss true
#define __glibcpp_double_infinity \
	_iec559_consts<bool>::_S_Inf.double_val
#define __glibcpp_double_quiet_NaN \
	_iec559_consts<bool>::_S_QNaN.double_val
#define __glibcpp_double_signaling_NaN \
	_iec559_consts<bool>::_S_SNaN.double_val
#define __glibcpp_double_denorm_min \
	_iec559_consts<bool>::_S_Denorm.double_val
#define __glibcpp_double_is_iec559 true
#define __glibcpp_double_is_bounded true
#define __glibcpp_double_is_modulo false
#define __glibcpp_double_traps true
#define __glibcpp_double_tinyness_before true
#define __glibcpp_double_round_style round_to_nearest

// long double

#define __glibcpp_long_double_has_infinity true
#define __glibcpp_long_double_has_quiet_NaN true
#define __glibcpp_long_double_has_signaling_NaN true
#define __glibcpp_long_double_has_denorm denorm_present
#define __glibcpp_long_double_has_denorm_loss true
#define __glibcpp_long_double_infinity \
	_iec559_consts<bool>::_S_InfL.ldouble_val
#define __glibcpp_long_double_quiet_NaN \
	_iec559_consts<bool>::_S_QNaNL.ldouble_val
#define __glibcpp_long_double_signaling_NaN \
	_iec559_consts<bool>::_S_SNaNL.ldouble_val
#define __glibcpp_long_double_denorm_min \
	_iec559_consts<bool>::_S_DenormL.ldouble_val
#define __glibcpp_long_double_is_iec559 true
#define __glibcpp_long_double_is_bounded true
#define __glibcpp_long_double_is_modulo false
#define __glibcpp_long_double_traps true
#define __glibcpp_long_double_tinyness_before true
#define __glibcpp_long_double_round_style round_to_nearest

#endif
