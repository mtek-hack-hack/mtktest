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

#ifndef _brs_siit_h
#define _brs_siit_h

#include "brs_cfg.h"
#ifdef BRS_CONFIG_WMLS

int
brs_si_String2Int (const char *aStr, int *charsUsed, MSF_INT32 *aInt, int *isOverflow);

void
brs_si_Int2String (const MSF_INT32 aInt, char *str);

#endif
#endif
