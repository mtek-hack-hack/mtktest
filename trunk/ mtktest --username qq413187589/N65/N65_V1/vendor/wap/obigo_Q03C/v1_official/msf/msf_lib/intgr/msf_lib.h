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
#ifndef _msf_lib_h
#define _msf_lib_h

/************************************************************
 * Includes for ANSI-C standard libraries
 ************************************************************/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <setjmp.h>

#ifndef _msf_def_h
#include "msf_def.h"
#endif
#ifdef CFG_MSF_HAS_FLOAT
#include <math.h>
#include <errno.h>
#endif

#endif
