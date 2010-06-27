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
#ifndef _brs_silt_h
#define _brs_silt_h

#include "brs_cfg.h"
#ifdef BRS_CONFIG_WMLS
#include "msf_cmmn.h"





typedef enum {   
  headkind,
  linkkind
} brs_si_enumKind;

typedef struct element {
  brs_si_enumKind kind;

  struct element *pre, *suc;
  void           *data;
}  brs_si_t_element,
  *brs_si_t_link,
  *brs_si_t_head;





void brs_si_f_lh_newhead (brs_si_t_head *p_h);
void brs_si_f_lh_newlink (brs_si_t_link *p_l);
void brs_si_f_lh_out (brs_si_t_link *p_l);
void brs_si_f_lh_precede (brs_si_t_link *p_l, brs_si_t_link *p_x);
void brs_si_f_lh_follow (brs_si_t_link *p_l, brs_si_t_link *p_x);
void brs_si_f_lh_into (brs_si_t_link *p_l, brs_si_t_head *p_h);
void brs_si_f_lh_into_as_first (brs_si_t_link *p_l, brs_si_t_head *p_h);
brs_si_t_link brs_si_f_lh_lpred (brs_si_t_link p_l);
brs_si_t_link brs_si_f_lh_lsuc (brs_si_t_link p_l);
int brs_si_f_lh_empty (brs_si_t_head p_h);
brs_si_t_link brs_si_f_lh_first (brs_si_t_head p_h);
brs_si_t_link brs_si_f_lh_last (brs_si_t_head p_h);
int brs_si_f_lh_cardinal (brs_si_t_head p_h);
void brs_si_f_lh_disposelink (brs_si_t_link *p_l);
void brs_si_f_lh_clear (brs_si_t_head *p_h);
void brs_si_f_lh_disposehead (brs_si_t_head *p_h);

























































#endif 
#endif
