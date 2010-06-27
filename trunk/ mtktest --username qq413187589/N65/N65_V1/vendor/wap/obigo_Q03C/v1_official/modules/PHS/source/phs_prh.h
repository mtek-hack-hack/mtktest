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








 
#ifndef _phs_prs_h
#define _phs_prs_h

#include "phs_cfg.h"
#ifdef PHS_CONFIG_WAP_PUSH_MESSAGES

#ifndef _phs_sig_h
#include "phs_sig.h"
#endif








#define PHS_PRH_SIG_START_PARSING                    PHS_MODULE_PARSER + 1







#define PHS_PRH_SIG_PARSING_ABORTED                  PHS_MODULE_PARSER + 2
#define PHS_PRH_SIG_PARSING_COMPLETED                PHS_MODULE_PARSER + 3













#define PHS_PRH_SIG_PARSE_NEXT                       PHS_MODULE_PARSER + 4 











typedef struct {
  int                  instance_id;       
  int                  content_type_int;  
  int                  data_type;         
  unsigned char       *data;              

  MSF_INT32            data_len;
  int                  charset;           
} phs_start_parsing_t;





void
phs_prh_init (void);

void
phs_prh_terminate (void);

void
phs_prh_main (phs_signal_t* signal);


#endif
#endif


