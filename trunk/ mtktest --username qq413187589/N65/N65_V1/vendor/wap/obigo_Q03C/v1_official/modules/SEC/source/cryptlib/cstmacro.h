/*
 * Copyright (C) Obigo AB, 2002-2006.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Obigo AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Obigo AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */

#ifndef _CSTMACRO_H
#define _CSTMACRO_H


#include "cstlib.h"



/* 
 * Handy macros:
 */


#define DISPOSE_MEM_IF_THERE(victim) \
   if((victim)) {\
     ut_dispose_mem((victim));\
     (victim) = 0;\
   }

#define DISPOSE_MBLK_F_IF_THERE(vict) \
   if((vict)) {\
     ut_dispose_mblk_f((vict));\
     (vict) = 0;\
   }

#define COPY_MBLK_F_IF_THERE(dest,src) \
   { if(src) {\
     if(!((dest) = ut_new_mblk_f((src)->used))) {\
       ut_log0(0UL, UT_ACONTINUE, "out of memory");\
       goto fail;\
     }\
     if(ut_copy_mblk((dest),(src))) {\
       ut_log0(0UL, UT_ACONTINUE, "out of memory");\
       ut_dispose_mblk_f((dest));\
       goto fail;\
     }\
     (dest)->used = (src)->used;\
   }\
   else\
     (dest) = 0; }
       
/* Handy macro. Note that all functions that use it must have an int
 * rval and a label called fail.
 */

/* check that two integer variables are the same size */

#ifndef NDEBUG
#define CHECK_INTS_ARE_SAME_SIZE(vble, type) \
  {\
    if (sizeof (vble) != sizeof (type)) \
      ut_log2(0UL, UT_AABORT, "checking on wrong-size variable: size of "\
        #vble " is %d, size of " #type " is %d", sizeof (vble), \
        sizeof (type));\
  }
#else
#define CHECK_INTS_ARE_SAME_SIZE(vble, type)
#endif

/* check if data in an off_t will fit in a size_t */

#define CHECK_FIT_IN_TYPE(vble, vbletype, type) \
  { \
    CHECK_INTS_ARE_SAME_SIZE (vble, vbletype) \
    if (sizeof (vble) > sizeof (type) && \
      (vble) > (type) ~0) { \
      ut_log2(0UL, UT_ACONTINUE, "given data length (%l) is too long to "\
        "fit in " #type " (%d bytes)", (vble), sizeof(type));\
      tryfunc_rval = 1;\
      goto fail;\
    }\
  }

#define CHECK_OFF_T_FITS_IN_SIZE_T(vble) \
  {\
    if (vble < 0) {\
      ut_log0(0UL, UT_ACONTINUE, "Attempting to put negative "\
        "variable " #vble " into size_t");\
      goto fail;\
    }\
    CHECK_FIT_IN_TYPE(vble, sec_off_t, size_t) \
  }

/* check for null argument. Arguments are:
   - parameter to check for nullness
   - return value
 */

#define CHECK_FOR_NULL_ARG(arg,err) \
  { if (!(arg)) { \
      ut_log0 (0UL, UT_ACONTINUE, "argument " #arg " is null"); \
      return err; \
    } \
  }

#define CHECK_FOR_NULL_ARG_GOTO_FAIL(arg, err) \
  { if (!(arg)) { \
      ut_log0 (0UL, UT_ACONTINUE, "argument " #arg " is null"); \
      rv = err; \
      goto fail; \
    } \
  }
  

#define CST_TRYFUNC(func)\
  { tryfunc_rval = (int) (func); \
    if (tryfunc_rval) {\
      ut_log1(UT_EBASE + __LINE__, UT_ACONTINUE, #func " returned %d",\
        tryfunc_rval);\
      goto fail;\
    } \
  }

#define _UTB_TRY(func)\
  if ((func) == UT_FALSE) {\
    ut_log0(UT_EBASE + __LINE__, UT_ACONTINUE, "failure in " #func);\
    goto fail;\
  }

#define _MPM_TRY(func,mid)\
  { (func); \
    if (mpm_flag_set((mid), MPM_OVERFLOW)) { \
      ut_log0(0UL, UT_ACONTINUE, "overflow in " #func); \
      goto fail; \
    } \
  }

#define _MPM_TRY_RVAL(func,mid)\
  { (func); \
    if (mpm_flag_set((mid), MPM_OVERFLOW)) { \
      ut_log0(0UL, UT_ACONTINUE, "overflow in " #func); \
      tryfunc_rval = 1; \
      goto fail; \
    } \
  }

/* Handier macro. Note that setting error = 0 tells the macro to inherit
 * whatever error was passed from func. Of course, so does simply using
 * CST_TRYFUNC.
 */

#define CST_TRYFUNC1(func,error)\
  if((tryfunc_rval = (func))) {\
    ut_log1(UT_EBASE + __LINE__, UT_ACONTINUE, #func " returned %d",\
      tryfunc_rval);\
    if(error) \
      tryfunc_rval = error; \
    goto fail;\
  }

/* The equivalent of the above, for memory allocation */

#define _TRYMEM(func) \
  if(!((func))) {\
    ut_log0(UT_EBASE + __LINE__, UT_ACONTINUE, "failure on "\
      #func " -- out of memory"); \
    tryfunc_rval = PKCS12_NOMEM; \
    goto fail; \
  }

/* Handy memory-allocation macro. Again, all functions must have a goto
 * label called fail.  */

#define _NEWOBJ(obj)\
  { if(!((obj) = ut_new_mem(sizeof(*(obj))))) {\
    ut_log0(UT_EBASE + __LINE__, UT_ACONTINUE, "out of memory for " \
      #obj); \
    goto fail;\
  }\
  memset((obj), 0, sizeof(*(obj))); }

#define _DISPOSE_MBLK_F_IF_THERE(victim)\
  if((victim)){\
    ut_dispose_mblk_f((victim));\
    (victim) = 0;\
  }

/* Macro to copy data to a pointer location and move the pointer to the
 * byte after the copied data */
#define _MEMCPY_AND_MOVE(dest,src,len) \
  { memcpy((dest),(src),(len));\
  (dest)+=(len); }


/* Macro. Copy srcblk->used bytes from srcblk->data to dest and
 * increment dest by srcblk->used.
 */
#define _MBLKCPY_AND_MOVE(dest,srcblk) \
  { memcpy((dest), (srcblk)->data, (srcblk)->used);\
  (dest) += (srcblk)->used; }

#endif  /* ndef _CSTMACRO_H */

