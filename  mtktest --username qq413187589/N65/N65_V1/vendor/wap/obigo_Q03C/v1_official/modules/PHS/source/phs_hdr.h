/*
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2004.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Teleca Mobile Technologies AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Teleca Mobile Technologies AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */










#ifndef _phs_hdr_h
#define _phs_hdr_h

#ifndef _phs_cfg_h
#include "phs_cfg.h"
#endif

#ifdef PHS_CONFIG_MULTIPART 

int 
phs_hdr_create_hdr_string_from_bin_hdrs (msf_hdr_t *table, unsigned char *headers, int headers_len);

#endif

#endif


