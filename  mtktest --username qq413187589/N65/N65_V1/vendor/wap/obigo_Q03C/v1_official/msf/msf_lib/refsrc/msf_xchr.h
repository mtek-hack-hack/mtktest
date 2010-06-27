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
 * msf_xchr.h
 * 
 * Additional Character Set Support
 *
 */
#ifndef _msf_xchr_h
#define _msf_xchr_h

#ifndef _msf_def_h 
#include "msf_def.h"
#endif

#ifndef _msf_chrs_h 
#include "msf_chrs.h"
#endif

/*
 * Define this constant to be the number of additional character sets
 * that are supported, or 0 if none are supported.
 */
#include "Conversions.h"

#define MSF_NUMBER_OF_ADDITIONAL_CHARACTER_SETS   8

typedef struct {
  int                    character_set;
  const char            *preferred_name;
  const char            *aliases;
  msf_charset_convert_t *cvt_to_utf8;  
  msf_charset_convert_t *cvt_from_utf8;  
} msf_xchr_entry_t;

#if MSF_NUMBER_OF_ADDITIONAL_CHARACTER_SETS > 0
extern const msf_xchr_entry_t msf_xchr_table[MSF_NUMBER_OF_ADDITIONAL_CHARACTER_SETS];
#endif

#endif
