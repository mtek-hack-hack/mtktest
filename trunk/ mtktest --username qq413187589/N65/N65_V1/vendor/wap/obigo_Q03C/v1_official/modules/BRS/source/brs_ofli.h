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


#ifdef BRS_CFG_OFFLINE_PAGES 

#ifndef _brs_ofli_h
#define _brs_ofli_h

#ifndef _stk_if_h
  #include "stk_if.h"
#endif

#ifndef _brs_oflm_h
  #include "brs_oflm.h"
#endif



typedef struct brs_ofl_res_list_st {
  MSF_UINT32                  hash;
  MSF_UINT32                  hash2;
  int                         req_id;
  char                       *url;
  char                       *url2;
  char                       *headers;
  char                       *contentType;
  char                       *cache_file_name;
  struct brs_ofl_res_list_st *next;
} brs_ofl_res_list_t;



void
brs_ofl_instance_init (void);

void
brs_ofl_instance_terminate (void);

int
brs_ofl_instance_get_offline_mode (int instance_id);

void
brs_ofl_instance_set_offline_mode_create_job (int instance_id, int new_val);

long
brs_ofl_instance_get_offline_folder (int instance_id);

void
brs_ofl_instance_set_offline_folder (int instance_id, long new_val);

void
brs_ofl_instance_new (int instance_id, int offline_mode);

void
brs_ofl_instance_delete (int instance_id);

void
brs_ofl_instance_new_page_create_job (int instance_id);

void
brs_ofl_instance_add_url_create_job (brs_ofl_add_url_t *p);

void
brs_ofl_instance_url_complete_create_job (int instance_id);

void
brs_ofl_instance_abort_create_job (int instance_id);

void
brs_ofl_instance_save_offline_page_create_job (brs_ofl_save_page_t *p);



brs_ofl_res_list_t*
brs_ofl_util_res_list_duplicate (brs_ofl_res_list_t* src);

void
brs_ofl_util_res_list_delete_list (brs_ofl_res_list_t **p);

#endif


#endif
