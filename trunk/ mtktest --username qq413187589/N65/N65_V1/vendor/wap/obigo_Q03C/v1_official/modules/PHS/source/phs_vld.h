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








 
#ifndef _phd_hvld_h
#define _phd_hvld_h

#ifndef _phs_cfg_h
#include "phs_cfg.h"
#endif
#ifdef PHS_CONFIG_WAP_PUSH_MESSAGES

#ifndef _msf_prsr_h
#include "msf_prsr.h"
#endif




typedef struct {
  int                  instanceId;
  int                  state;
  int                  doc_type;
  int                  charset;
  int                  content_type;
  int                  stream_handle;
} phs_hvld_user_data_t;















int
phs_hvld_init_parser_object (msf_prsr_parserData_t*  p,
                             msf_prsr_decoderData_t* d,
                             const char*             doctype_str,
                             int                     len,
                             int                     doctype_int,
                             int                     charset);


#endif
#endif


