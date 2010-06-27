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
 * msf_xmim.h
 * 
 * Additional Mime type support
 *
 */
#ifndef _msf_xmim_h
#define _msf_xmim_h

#ifndef _msf_def_h 
#include "msf_def.h"
#endif

/*
 * Define this constant to be the number of additional mime types
 * that are supported, or 0 if none are supported.
 */
#define MSF_NUMBER_OF_ADDITIONAL_MIME_TYPES  34

typedef struct {
  MSF_INT32             value;
  const char            *mime;
  const char            *extension;
} msf_xmim_entry_t;

#if MSF_NUMBER_OF_ADDITIONAL_MIME_TYPES > 0
extern const msf_xmim_entry_t msf_xmim_table[MSF_NUMBER_OF_ADDITIONAL_MIME_TYPES];
#endif

#endif

