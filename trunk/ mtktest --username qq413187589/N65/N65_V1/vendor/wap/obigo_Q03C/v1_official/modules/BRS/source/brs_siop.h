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


















#ifndef _brs_siop_h
#define _brs_siop_h

#include "brs_cfg.h"
#ifdef BRS_CONFIG_WMLS
#include "msf_cmmn.h"

#include "brs_siva.h"
#include "brs_silt.h"

typedef struct {
  brs_si_t_head head;
} brs_si_ops_t;





brs_si_ops_t *
brs_si_OpS_New (void);
















brs_si_ops_t *
brs_si_OpS_NewFromOpS (brs_si_ops_t *src, int nbrToMove);



brs_si_ops_t *
brs_si_OpS_NewFromArgString (char* argString);



void
brs_si_OpS_Delete (brs_si_ops_t **pThis);










void
brs_si_OpS_Push (brs_si_ops_t *thisx, brs_si_var_t **pVar);











brs_si_var_t *
brs_si_OpS_Pop (brs_si_ops_t *thisx);







int
brs_si_OpS_GetTopIndex (brs_si_ops_t *thisx);












int
brs_si_OpS_ClearUntilIndex (brs_si_ops_t *thisx, int index);

#endif
#endif
