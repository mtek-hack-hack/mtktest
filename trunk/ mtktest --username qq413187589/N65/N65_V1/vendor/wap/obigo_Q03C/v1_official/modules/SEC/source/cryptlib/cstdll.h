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

#ifdef THIS_WAS_A_SPOOF
#include "cstlib.h"
#else

#ifndef _CSTDLL_H /* prevent multiple inclusion */
#define _CSTDLL_H

#define _CST_LINK_TO_DLL

#ifdef WIN32
#  define _CST_LINK_TO_32BIT_DLL
#else
#  define _CST_LINK_TO_16BIT_DLL
#  ifndef _CSTFORWIN16DLL
#    define _CSTFORWIN16DLL
#  endif
#endif

#include "cstfiles.h"

#endif /* ndef _CSTDLL_H */

#endif /* def THIS_WAS_A_SPOOF */
