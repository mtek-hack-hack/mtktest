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











#ifndef _brs_hist_h
#define _brs_hist_h

#ifndef _msf_def_h
#include "msf_def.h"
#endif
#ifndef _brs_var_h
#include "brs_var.h"
#endif






typedef struct brs_hist_element_st {
  struct brs_hist_element_st *fwd, *back;

  int         in_list;
  int         id;              
  char       *url;             
  char       *fragment;        
  char       *orig_url;        
  int         referrer;        
  char       *title;
  int         num_fragments;
  int         sendreferer;
  int         doctype;
  int         method;
  char       *enctype;
  char       *type;
  int         accept_charset;
  int         cache_control;
  brs_var_t  *controls;
  brs_var_t  *local_variables;
  MSF_INT32   size;
  MSF_UINT32  last_modified;
  int         socket_id;
  MSF_INT32   security_id;
  int         protocol;
  int         screen_pos_x;
  int         screen_pos_y;
  int         screen_node_id;
  char        *cacheFileName; 
} brs_hist_element_t;

typedef struct {
  brs_hist_element_t *elements;
  brs_hist_element_t *current_element;
  int                 num_elements;
  int                 max_size;
} brs_hist_t;






void
brs_hist_init (brs_hist_t *history, int max_size);

void
brs_hist_check_size (brs_hist_t *history, int push);

void
brs_hist_clear (brs_hist_t *history);

void
brs_hist_clear_all_but_current (brs_hist_t *history);

brs_hist_element_t *
brs_hist_new_element (void);

void
brs_hist_push (brs_hist_t *history, brs_hist_element_t *history_elt);

void
brs_hist_back_to (brs_hist_t *history, brs_hist_element_t *history_elt);

void
brs_hist_delete_element (brs_hist_element_t *history_elt);

brs_hist_element_t *
brs_hist_get_current (brs_hist_t *history);

brs_hist_element_t *
brs_hist_move_fwd (brs_hist_element_t *history_elt, int steps);

brs_hist_element_t *
brs_hist_move_back (brs_hist_element_t *history_elt, int steps);

brs_hist_element_t *
brs_hist_find_referrer (brs_hist_t *history, brs_hist_element_t *history_elt);

#endif
