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









#ifndef _brs_var_h
#define _brs_var_h















typedef struct brs_var_st {
  struct brs_var_st *next;

  int   var_id;
  char *name;
  char *value;
} brs_var_t;












void
brs_var_set_variable (brs_var_t **vlist, int var_id, char *name, char *value);







char *
brs_var_get_variable (brs_var_t *vlist, int var_id, char *name);








void
brs_var_move_variables (brs_var_t **vlist, brs_var_t **src);






void
brs_var_delete_variables (brs_var_t **vlist);

#endif
