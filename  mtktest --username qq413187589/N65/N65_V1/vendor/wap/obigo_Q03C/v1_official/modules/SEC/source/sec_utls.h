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







#ifndef _sec_utls_h
#define _sec_utls_h

#ifndef _msf_def_h
#include "msf_def.h"
#endif

void AUCERT_UTILS_getUINT16(const unsigned char *str, MSF_UINT16 *uint);
void AUCERT_UTILS_getUINT32(const unsigned char *str, MSF_UINT32 *uint);
void AUCERT_UTILS_putUINT16(MSF_UINT16 *uint, unsigned char *str);
void AUCERT_UTILS_putUINT32(MSF_UINT32 *uint, unsigned char *str);

#endif
