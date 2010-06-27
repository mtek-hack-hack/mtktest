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















#ifndef _stk_hdr_h
#define _stk_hdr_h

#ifndef  _msf_def_h
#include "msf_def.h"
#endif

#ifndef  _msf_cmmn_h
#include "msf_cmmn.h"
#endif










#define NO_CACHE_FLAG                   0x8000
#define NO_STORE_FLAG                   0x4000
#define MAX_AGE_FLAG                    0x2000
#define MAX_STALE_FLAG                  0x1000
#define MIN_FRESH_FLAG                  0x0800
#define NO_TRANSFORM_FLAG               0x0400
#define ONLY_IF_CACHED_FLAG             0x0200
#define PUBLIC_FLAG                     0x0100
#define PRIVATE_FLAG                    0x0080
#define MUST_REVALIDATE_FLAG            0x0040
#define PROXY_REVALIDATE_FLAG           0x0020
#define S_MAX_AGE_FLAG                  0x0010


#define X_WAP_APPLICATION               0x00
#define X_WAP_APPLICATION_PUSH_SIA      0x01
#define X_WAP_APPLICATION_WML_UA        0x02
#define X_WAP_APPLICATION_WTA_UA        0x03
#define X_WAP_APPLICATION_MMS_UA        0x04
#define X_WAP_APPLICATION_PUSH_SYNCML   0x05
#define X_WAP_APPLICATION_LOC_UA        0x06


#define X_WAP_MICROSOFT_LOCALCONTENT_UA 0x8000
#define X_WAP_MICROSOFT_IMCLIENT_UA     0x8001
#define X_WAP_DOCOMO_IMODE_MAIL_UA      0x8002
#define X_WAP_DOCOMO_IMODE_MR_UA        0x8003
#define X_WAP_DOCOMO_IMODE_MF_UA        0x8004




#define UTYPE_MSF_UINT8                     1
#define UTYPE_MSF_UINT32                    2
#define UTYPE_STRING_LIT                3  
#define UTYPE_STRING                    4  
#define UTYPE_DATE                      5  
#define UTYPE_DATA_STRING               6
#define UTYPE_NONE                      9

#define HDR_DIGEST_SCHEME               1
#define HDR_BASIC_SCHEME                0

#define HDR_PRAGMA_NO_CACHE             0x00













typedef struct {
  MSF_UINT16  flags;
  MSF_UINT32  secage;
  MSF_UINT32  secstale;
  MSF_UINT32  secfresh;
  MSF_UINT32  secS_maxage;
} hdr_cachecontrol_t;







typedef struct hdr_params_st {
  struct hdr_params_st *next;

  char *name;
  char *value;
} hdr_params_t;



 
typedef struct hdr_element_st {
  struct hdr_element_st *next;

  int field_name;
  int utype; 
  union {
    char   *str;
    MSF_UINT8   uint8;
    MSF_UINT32  uint32;
  } _u;
  void   *extras;
} hdr_element_t;

typedef struct {
  hdr_element_t *hdr_fields;
  hdr_element_t *last_added; 
} hdr_table_t;


typedef struct cookie_st {
  struct cookie_st * next;
  char* name;
  char* value;
  char* domain;
  char* path;
  char* portList;
  MSF_UINT32 maxage;
  MSF_UINT8 version_major; 
  MSF_UINT8 version_minor; 

  int discard;   
  int port;
  int secure; 
} cookie_t;

typedef struct {
  cookie_t *cookies;
  cookie_t *last_cookie;
  cookie_t *next_to_retrieve;
} cookie_list_t;






 
hdr_table_t*
hdr_table_new (void);



 
hdr_table_t* 
hdr_table_copy (hdr_table_t* hdr_table);






void
hdr_update_fields (hdr_table_t *dst, hdr_table_t *src);




void
hdr_delete_table (hdr_table_t* table);




void
hdr_delete_field (hdr_table_t *table, int field_name);




hdr_params_t *
hdr_new_params (void);






hdr_element_t *
hdr_element_find (hdr_table_t *table, int field_name);










int 
hdr_add_binary_headers (hdr_table_t* table, unsigned char *headers, int headers_len,
                        int is_connect_headers);




hdr_element_t *
hdr_add_uint8 (hdr_table_t* table, int field_name, MSF_UINT8 value);





hdr_element_t *
hdr_add_uint32 (hdr_table_t* table, int field_name, MSF_UINT32 value);





hdr_element_t *
hdr_add_date (hdr_table_t* table, int field_name, MSF_UINT32 value);







hdr_element_t *
hdr_add_string (hdr_table_t* table, int field_name, const char* str);







hdr_element_t *
hdr_add_string_literal (hdr_table_t* table, int field_name, const char* str);






hdr_element_t *
hdr_add_authorization (hdr_table_t* table, int field_name,
                       const char* userid, const char* pwd);




hdr_element_t *
hdr_add_cache_control (hdr_table_t* table, MSF_UINT16 flag);





hdr_element_t *
hdr_add_data_string (hdr_table_t* table, int field_name, int length, unsigned char* data);







hdr_element_t *
hdr_add_parameter (hdr_table_t *table, int field_name,
                   const char *param_name, const char *param_value);




void
hdr_add_parameter_to_element (hdr_element_t *elt,
                              const char *param_name,
                              const char *param_value);








int
hdr_add_header_from_text_line (hdr_table_t *table, char *text_line);







int
hdr_add_headers_from_text (hdr_table_t *table, const char *text);








int
hdr_build_binary (hdr_table_t* table, unsigned char **headers, int *headers_len, 
                  int encoding_version);





int
hdr_build_textual (hdr_table_t *table, char **headers);





int 
hdr_get_uint8 (hdr_table_t *table, int field_name, MSF_UINT8 *value);





int
hdr_get_uint32 (hdr_table_t *table, int field_name, MSF_UINT32 *value);






const char *
hdr_get_string (hdr_table_t *table, int field_name);






int
hdr_get_cachecontrol (hdr_table_t *table, hdr_cachecontrol_t *cachestruct);






int 
hdr_get_data_string (hdr_table_t *table, int field_name, int *length, unsigned char **data);






char *
hdr_get_parameter (hdr_table_t *table, int field_name,
                   char *param_name);










int
hdr_get_authentication_method (char* string);








cookie_t*
hdr_cookie_new (void);




void
hdr_cookie_delete (cookie_t* cookie);




cookie_list_t*
hdr_cookie_list_new (void);




void
hdr_cookie_list_delete (cookie_list_t* cookie_list);







cookie_t*
hdr_get_cookie_from_list (cookie_list_t* cookie_list);




cookie_t*
hdr_add_cookie_to_list (cookie_list_t* cookie_list, cookie_t* cookie);







int
hdr_get_cookie_string (cookie_list_t* cookie_list, char** string);






int
hdr_get_set_cookie_list (hdr_table_t *table, cookie_list_t** set_cookie_list);












void
stk_hdr_uint322string (MSF_UINT32 i, char **s);







void
stk_hdr_uint82string (MSF_UINT8 i, char **s);





void
stk_hdr_string2uint32 (char *s, MSF_UINT32 *i);




int
stk_hdr_get_uint32_string_len (MSF_UINT32 i);




int
stk_hdr_get_uint8_string_len (MSF_UINT8 i);










void
stk_hdr_encuint322string (MSF_UINT32 i, char **s);








void
stk_hdr_string2encuint32 (char *s, MSF_UINT32 *i);




int
stk_hdr_get_encuint32_string_len (MSF_UINT32 i);

#endif
