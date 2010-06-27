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








#ifndef _brs_str_h
#define _brs_str_h





































#define BRS_STR_TYPE_CHAR                         1
#define BRS_STR_TYPE_STRING                       2
#define BRS_STR_TYPE_STRING_LITERAL               3






typedef struct brs_str_st {
  struct brs_str_st *next;
  
  char  type;   
  int   len;    
  union {
    char *s;
    char  c;
  } _u;
} brs_str_t;










void
brs_str_delete (brs_str_t *str);







brs_str_t *
brs_str_append_string (brs_str_t *str, char *s, int type);







brs_str_t *
brs_str_append_stringn (brs_str_t *str, char *s, int len, int type);






brs_str_t *
brs_str_append_char (brs_str_t *str, char c);






brs_str_t *
brs_str_concatenate (brs_str_t *str1, brs_str_t *str2);






brs_str_t *
brs_str_prepend_string (brs_str_t *str, char *s, int type);





brs_str_t *
brs_str_prepend_char (brs_str_t *str, char c);








char *
brs_str_make_string (brs_str_t *str);












brs_str_t *
brs_str_split_string (char *s, char sep);

#endif
