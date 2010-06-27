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









#ifndef _brs_oflm_h
#define _brs_oflm_h

#ifndef _brs_cfg_h
  #include "brs_cfg.h"
#endif

#ifndef _msf_cmmn_h
  #include "msf_cmmn.h"
#endif








#define BRS_OFL_MAX_CONCURRENT_OFFLINE 5

#define BRS_OFL_RESULT_OK     0
#define BRS_OFL_RESULT_ERROR  -1
#define BRS_OFL_MODE_OFFLINE  0
#define BRS_OFL_MODE_ONLINE   1





#define BRS_OFFLINE_SIG_NEW_INSTANCE              BRS_MODULE_OFFLINE + 1
#define BRS_OFFLINE_SIG_DELETE_INSTANCE           BRS_MODULE_OFFLINE + 2
#define BRS_OFFLINE_SIG_NEW_PAGE                  BRS_MODULE_OFFLINE + 3
#define BRS_OFFLINE_SIG_ADD_URL_REQ               BRS_MODULE_OFFLINE + 4
#define BRS_OFFLINE_SIG_ADD_URL_REPLY             BRS_MODULE_OFFLINE + 5
#define BRS_OFFLINE_SIG_SET_OFFLINE_MODE          BRS_MODULE_OFFLINE + 6
#define BRS_OFFLINE_SIG_CONTINUE                  BRS_MODULE_OFFLINE + 7
#define BRS_OFFLINE_SIG_SAVE_PAGE                 BRS_MODULE_OFFLINE + 8
#define BRS_OFFLINE_SIG_REMOVE_PAGE               BRS_MODULE_OFFLINE + 9
#define BRS_OFFLINE_SIG_REMOVE_ALL_PAGES          BRS_MODULE_OFFLINE + 10
#define BRS_OFFLINE_SIG_LOAD_URL                  BRS_MODULE_OFFLINE + 11

#define BRS_OFFLINE_SIG_FILE_NOTIFY               BRS_MODULE_OFFLINE + 12
#define BRS_OFFLINE_SIG_PIPE_NOTIFY               BRS_MODULE_OFFLINE + 13

#define BRS_OFFLINE_SIG_ABORT                     BRS_MODULE_OFFLINE + 14





typedef struct {
  int    instance_id;
  int    req_id;
  char  *url;
  char  *new_url; 
  char  *headers;
  char  *contentType;
  char  *cache_file_name;
} brs_ofl_add_url_t;

typedef struct {
  int    instance_id;
  char  *content_restriction;
  int    req_id;
} brs_ofl_save_page_t;

typedef struct {
  int    instance_id;
  char  *url;
  int    req_id;
} brs_ofl_load_url_t;





void
brs_ofl_init (void);

void
brs_ofl_terminate (void);

void
brs_ofl_new_instance (int instance_id, int offline_mode);

void
brs_ofl_delete_instance (int instance_id);

void
brs_ofl_new_page (int instance_id);

void
brs_ofl_add_url_request (int instance_id, int req_id, const char *url);

void
brs_ofl_add_url_reply (int instance_id, int req_id, const char *headers, 
                       const char *content_type, const char *cache_file_name, char *new_url);

void
brs_ofl_set_offline_mode (int instance_id, int mode);

void
brs_ofl_save_page (int instance_id, const char *content_restriction, int req_id);

void
brs_ofl_load_url (int instance_id, const char *url, int req_id);

void
brs_ofl_delete_page (const char *url);





#define BRS_STRDUP(a) msf_cmmn_strdup ( MSF_MODID_BRS, a )

#ifndef UNREFERENCED_PARAMETER
  #define UNREFERENCED_PARAMETER(P)          \
       \
      { \
          (P) = (P); \
      } \
      
#endif

#ifdef MSF_LOG_MODULE

  #define BRS_LOG_FILE_IF(cond,func, fileop, res) \
  {if (cond){                                                        \
        MSF_LOG_MSG((MSF_LOG_DETAIL_LOW, MSF_MODID_BRS,                  \
        "BRS: " #fileop " failed (result = %i) [" #func "]\n",res));      \
  }}

  #define BRS_LOG_FILE_ERROR(func,fileop,res) BRS_LOG_FILE_IF(((res)<0),func,fileop,res)
  #define BRS_LOG_FILE_ERROR_ASYNC(func,fileop,res) \
    BRS_LOG_FILE_IF( (res<0 && res!=MSF_FILE_ERROR_DELAYED),func,fileop,res)

#else
  #define BRS_LOG_FILE_IF(cond,func, fileop, res) UNREFERENCED_PARAMETER(res)
  #define BRS_LOG_FILE_ERROR(func,fileop,res) UNREFERENCED_PARAMETER(res)
  #define BRS_LOG_FILE_ERROR_ASYNC(func,fileop,res) UNREFERENCED_PARAMETER(res)
#endif

#endif 
