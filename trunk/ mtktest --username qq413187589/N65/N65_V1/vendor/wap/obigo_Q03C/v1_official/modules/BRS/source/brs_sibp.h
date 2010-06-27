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























#ifndef _brs_sibp_h
#define _brs_sibp_h

#include "brs_cfg.h"
#ifdef BRS_CONFIG_WMLS
#include "msf_cmmn.h"

#include "brs_siva.h"








enum brs_si_ConstType {
  CONST_TYPE_INT8                       = 0,
  CONST_TYPE_INT16                      = 1,
  CONST_TYPE_INT32                      = 2,
  CONST_TYPE_FLOAT32                    = 3,
  CONST_TYPE_UTF8                       = 4,
  CONST_TYPE_ES                         = 5,
  CONST_TYPE_EXT_CHARSET                = 6,
  CONST_TYPE_MAX
};



enum brs_si_PragmaType {
  PRAGMA_ACCESS_DOMAIN                  = 0,
  PRAGMA_ACCESS_PATH                    = 1,
  PRAGMA_UA_PROP                        = 2,
  PRAGMA_UA_PROP_SCHEME                 = 3,            
  PRAGMA_MAX
};






typedef enum brs_si_ConstType  brs_si_enumConstType;
typedef enum brs_si_PragmaType brs_si_enumPragmaType;

typedef struct {
  MSF_UINT32 funcNamePos;    

  MSF_UINT8  nbrOfArgs;
  MSF_UINT8  nbrOfVars;
  MSF_UINT32 startPos;
  MSF_UINT32 endPos;
} brs_si_structFuncInfo, *brs_si_pstructFuncInfo;

typedef struct {
  brs_si_enumConstType type;
  MSF_UINT32        pos;     


} brs_si_structConstInfo, *brs_si_pstructConstInfo;

typedef struct {
  brs_si_enumPragmaType type;
  MSF_UINT32         pos;
} brs_si_structPragmaInfo, *brs_si_pstructPragmaInfo;

typedef struct {
  char              version;
  MSF_UINT16            nbrOfConstants;
  int               charset;    


  brs_si_structConstInfo  *constants;     
  MSF_UINT16            nbrOfPragmas;
  brs_si_structPragmaInfo *pragmas;       
  MSF_UINT8             nbrOfFunctions;
  brs_si_structFuncInfo   *functions;     
} brs_si_structBPInfo;
























brs_si_structBPInfo *
brs_si_BPI_New (unsigned char *BP, MSF_UINT32 BPlen, int charset);
















void
brs_si_BPI_Delete (brs_si_structBPInfo **pThis);

















int
brs_si_BPI_AccessCheck (brs_si_structBPInfo *thisx, unsigned char *BP, MSF_UINT32 BPend,
                 char *funcName,
                 MSF_UINT8 nbrOfArgs, char *refererUrl, char *baseUrl,
                 MSF_UINT8 *funcIndexResult);










































int
brs_si_BPI_GetConstantType (brs_si_structBPInfo *thisx, MSF_UINT16 constIndex,
                     brs_si_enumConstType *constType);

















brs_si_var_t *
brs_si_BPI_GetConstant (brs_si_structBPInfo *thisx, unsigned char *BP, MSF_UINT32 BPend,
                 MSF_UINT16 constIndex);


















char *
brs_si_BPI_GetRawUTF8Constant (brs_si_structBPInfo *thisx, unsigned char *BP, MSF_UINT32 BPend,
                        MSF_UINT16 constIndex);

#endif
#endif
