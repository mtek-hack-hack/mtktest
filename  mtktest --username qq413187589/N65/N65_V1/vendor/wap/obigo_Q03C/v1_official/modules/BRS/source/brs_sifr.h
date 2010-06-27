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
































#ifndef _brs_sifr_h
#define _brs_sifr_h

#include "brs_cfg.h"
#ifdef BRS_CONFIG_WMLS
#include "msf_cmmn.h"

#include "brs_siva.h"
#include "brs_sibp.h"
#include "brs_siop.h"

typedef struct {
  MSF_UINT8      funcIndex;  

  brs_si_var_t **variables;  
  MSF_UINT32     returnIP;   
  MSF_UINT16     returnSP;   
} brs_si_frame_t;

brs_si_frame_t *
brs_si_Frame_New (MSF_UINT8 funcIndex, brs_si_structBPInfo *BPI, brs_si_ops_t *OpS);

void
brs_si_Frame_Delete (brs_si_frame_t **pThis, brs_si_structBPInfo *BPI);

#endif
#endif
