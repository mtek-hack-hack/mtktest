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









#ifndef _brs_simi_h
#define _brs_simi_h

#include "brs_cfg.h"
#ifdef BRS_CONFIG_WMLS

#include "brs_siva.h"





#define BRS_SI_INT8_MIN            (-128)
#define BRS_SI_INT8_MAX            127
#define BRS_SI_UINT8_MAX           0xff
#define BRS_SI_INT16_MIN           (-32768)
#define BRS_SI_INT16_MAX           32767
#define BRS_SI_UINT16_MAX          0xffff
#define BRS_SI_INT32_MIN           (-2147483647L-1)
#define BRS_SI_INT32_MAX           2147483647L
#define BRS_SI_UINT32_MAX          0xffffffffUL

#ifdef BRS_CFG_WMLS_HAS_FLOAT
#define BRS_SI_FLOAT32_MAX              3.402823466e+38F
#define BRS_SI_FLOAT32_MIN              1.17549435e-38F
#define BRS_SI_FLOAT32_INTMAX_AS_FLOAT  2.14748352e9F


#else
#define BRS_SI_FLOAT32_MAX              BRS_SI_INT32_MAX
#define BRS_SI_FLOAT32_MIN              BRS_SI_INT32_MIN
#define BRS_SI_FLOAT32_INTMAX_AS_FLOAT  2147483647L
#endif











int
brs_si_IsNumberChar (char c);

#ifdef BRS_CFG_WMLS_HAS_FLOAT



int brs_si_IsLegalFloatVal (MSF_FLOAT32 a);
int brs_si_IsUnderflow (MSF_FLOAT32 a);
int brs_si_FloatIsZero (MSF_FLOAT32 a);
#endif
#endif
#endif
