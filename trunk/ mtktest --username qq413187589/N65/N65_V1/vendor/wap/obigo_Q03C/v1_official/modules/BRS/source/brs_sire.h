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


































































#ifndef _brs_sire_h
#define _brs_sire_h

#include "brs_cfg.h"
#ifdef BRS_CONFIG_WMLS
#include "msf_cmmn.h"

#include "brs_sibp.h"
#include "brs_siop.h"
#include "brs_sifr.h"
#include "brs_sifs.h"
#include "brs_siva.h"

typedef struct {
  unsigned char *BP;
  MSF_UINT32         BPend; 

  brs_si_structBPInfo  *BPI;
  brs_si_ops_t      *OpS;
  brs_si_fs_t       *FS;
  MSF_UINT32         IP;    
  brs_si_frame_t    *currF;
} brs_si_re_t;



























brs_si_re_t *
brs_si_RE_NewWithArgString (unsigned char *BP, MSF_UINT32 BPlen, int charset,
                     char *funcname, 
                     char *argString, char *refererUrl, char *baseUrl,
                     int *errCode);





























brs_si_re_t *
brs_si_RE_NewWithArgOpS (unsigned char *BP, MSF_UINT32 BPlen, int charset, char *funcname,
                  brs_si_ops_t **ops, char* refererUrl, char *baseUrl,
                  int *errCode);

















void
brs_si_RE_Delete (brs_si_re_t **pThis);

















brs_si_var_t *
brs_si_RE_GetResult (brs_si_re_t *thisx); 



















int
brs_si_RE_ReadInstruction (brs_si_re_t *thisx, MSF_UINT8 *result);



















int
brs_si_RE_Read8bOperand (brs_si_re_t *thisx, MSF_UINT8 *result);



















int
brs_si_RE_Read16bOperand (brs_si_re_t *thisx, MSF_UINT16 *result);





















int
brs_si_RE_Jump (brs_si_re_t *thisx, MSF_INT32 offset);

















brs_si_var_t *
brs_si_RE_Pop (brs_si_re_t *thisx);

#endif
#endif
