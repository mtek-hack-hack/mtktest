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
#ifndef _brs_sifl_h
#define _brs_sifl_h

#include "brs_cfg.h"
#ifdef BRS_CONFIG_WMLS
#include "msf_cmmn.h"

#ifdef BRS_CFG_WMLS_HAS_FLOAT

int
brs_si_String2Float (char *aStr, int *charsUsed, MSF_FLOAT32 *pf, int *isOverflow);

void
brs_si_Float2String (MSF_FLOAT32 aFloat, char *str);

#endif
#endif
#endif
