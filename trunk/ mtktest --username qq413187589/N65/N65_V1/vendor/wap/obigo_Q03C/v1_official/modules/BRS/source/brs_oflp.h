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


#ifndef _brs_cfg_h
  #include "brs_cfg.h"
#endif

#ifdef BRS_CFG_OFFLINE_PAGES 

#ifndef _brs_oflp_h
#define _brs_oflp_h

#ifndef _brs_ofli_h
  #include "brs_ofli.h"
#endif

#ifndef _brs_sig_h
  #include "brs_sig.h"
#endif

#ifndef _stk_if_h
  #include "stk_if.h"
#endif



void
brs_ofl_offline_page_init (void);

void
brs_ofl_offline_page_terminate (void);

void
brs_ofl_offline_page_increase_ref_count (long folder);

void
brs_ofl_offline_page_decrease_ref_count (long folder);

void
brs_ofl_offline_page_save_sub_job (brs_ofl_res_list_t *url_list, 
                                      char *content_restriction, long *result);

void
brs_ofl_offline_page_delete_create_job (char *url);

void
brs_ofl_offline_page_load_create_job (brs_ofl_load_url_t *p);


#endif


#endif
