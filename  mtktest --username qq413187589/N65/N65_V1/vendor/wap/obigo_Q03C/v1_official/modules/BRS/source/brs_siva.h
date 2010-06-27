/*
 * Copyright (C) Obigo AB, 2002-2007.
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
#ifndef _brs_siva_h
#define _brs_siva_h

#include "brs_cfg.h"
#ifdef BRS_CONFIG_WMLS
#include "msf_def.h"

typedef enum enumVarType {
  typeInteger = 0,
  typeFloat = 1,
  typeString = 2,
  typeBool = 3,
  typeInvalid = 4
} brs_si_var_type_t;


typedef struct {
  brs_si_var_type_t type;
  union {
    MSF_INT32       theInt;
#ifdef BRS_CFG_WMLS_HAS_FLOAT
    MSF_FLOAT32     theFloat;
#endif
    char       *theString;
  } val;
  int           theStringLen;
} brs_si_var_t;

typedef enum { 
  CONVERT_BOOLS,
  CONVERT_INTS,
  CONVERT_FLOATS,
  CONVERT_STRINGS,
  CONVERT_INT_FLOAT,
  CONVERT_INTS_FLOATS,
  CONVERT_INTS_FLOATS_STRINGS
} brs_si_enumConvertMethod;

typedef enum {
  VCR_OK,       
  VCR_NOT_OK,   
  VCR_OVERFLOW  


} brs_si_enumVarConvertResult;


brs_si_var_t *brs_si_Var_New (void);
void brs_si_Var_Delete (brs_si_var_t **pThis);

int brs_si_Var_ConvertMethod (brs_si_enumConvertMethod method,
                       brs_si_var_t *op1, brs_si_var_t *op2);
brs_si_enumVarConvertResult brs_si_Var_Convert (brs_si_var_t *thisx, brs_si_var_type_t toType);

void brs_si_Var_AssignVar (brs_si_var_t *thisx, brs_si_var_t *src);
void brs_si_Var_AssignInt (brs_si_var_t *thisx, MSF_INT32 val);
void brs_si_Var_AssignString (brs_si_var_t *thisx, int len, char* str);
void brs_si_Var_AssignStringDirect (brs_si_var_t *thisx, int len, char** str);
void brs_si_Var_NewString (brs_si_var_t *thisx, int len);
void brs_si_Var_AssignBool (brs_si_var_t *thisx, int val);
void brs_si_Var_AssignInvalid (brs_si_var_t *thisx);
#ifdef BRS_CFG_WMLS_HAS_FLOAT
void brs_si_Var_AssignFloat (brs_si_var_t *thisx, MSF_FLOAT32 val);
#endif







int brs_si_Var_INCR (brs_si_var_t *thisx);
int brs_si_Var_DECR (brs_si_var_t *thisx);



brs_si_var_t *brs_si_Var_UMINUS (const brs_si_var_t *a);
brs_si_var_t *brs_si_Var_ADD (const brs_si_var_t *a, const brs_si_var_t *b);
brs_si_var_t *brs_si_Var_SUB (const brs_si_var_t *a, const brs_si_var_t *b);
brs_si_var_t *brs_si_Var_MUL (const brs_si_var_t *a, const brs_si_var_t *b);
brs_si_var_t *brs_si_Var_DIV (const brs_si_var_t *a, const brs_si_var_t *b);
brs_si_var_t *brs_si_Var_IDIV (const brs_si_var_t *a, const brs_si_var_t *b);
brs_si_var_t *brs_si_Var_REM (const brs_si_var_t *a, const brs_si_var_t *b);
brs_si_var_t *brs_si_Var_B_AND (const brs_si_var_t *a, const brs_si_var_t *b);
brs_si_var_t *brs_si_Var_B_OR (const brs_si_var_t *a, const brs_si_var_t *b);
brs_si_var_t *brs_si_Var_B_XOR (const brs_si_var_t *a, const brs_si_var_t *b);
brs_si_var_t *brs_si_Var_B_NOT (const brs_si_var_t *a);
brs_si_var_t *brs_si_Var_B_LSHIFT (const brs_si_var_t *a, const brs_si_var_t *b);
brs_si_var_t *brs_si_Var_B_RSSHIFT (const brs_si_var_t *a, const brs_si_var_t *b);
brs_si_var_t *brs_si_Var_B_RSZSHIFT (const brs_si_var_t *a, const brs_si_var_t *b);
brs_si_var_t *brs_si_Var_EQ (const brs_si_var_t *a, const brs_si_var_t *b);
brs_si_var_t *brs_si_Var_LE (const brs_si_var_t *a, const brs_si_var_t *b);
brs_si_var_t *brs_si_Var_LT (const brs_si_var_t *a, const brs_si_var_t *b);
brs_si_var_t *brs_si_Var_GE (const brs_si_var_t *a, const brs_si_var_t *b);
brs_si_var_t *brs_si_Var_GT (const brs_si_var_t *a, const brs_si_var_t *b);

int
brs_si_IntMUL_no_overflow (MSF_INT32 originala, MSF_INT32 originalb, MSF_INT32 *res);

#endif
#endif
