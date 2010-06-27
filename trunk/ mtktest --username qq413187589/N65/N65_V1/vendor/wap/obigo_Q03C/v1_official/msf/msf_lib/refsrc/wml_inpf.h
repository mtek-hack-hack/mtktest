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
/*
 * wml_inpf.h
 *
 * Created by Henrik Olsson
 *
 * Revision history:
 *
 */
#ifndef _wml_inpf_h
#define _wml_inpf_h

#ifndef _msf_def_h
#include "msf_def.h"
#endif

#ifndef _msf_int_h
#include "msf_int.h"
#endif


int 
wml_input_make_valid(const char* inStr,
                     int startSel,
                     int endSel,
                     char* newChars,
                     const char* formatStr,
                     int inputRequired,
                     char* outStr,
                     int* outStrSize);

#endif  /*_wml_inpf_h*/
