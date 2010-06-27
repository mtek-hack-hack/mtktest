/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   custom_wap_config.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   The file contains WAP/MMS configuration constant.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef _CUSTOM_WAP_CONFIG_H
#define _CUSTOM_WAP_CONFIG_H

#include "kal_release.h"        /* Basic data type */
#include "custom_wap_cfg.h"


/*Common Settings*/
/* Browser Settings: Start*/
/* Browser Settings: End*/

/* MMS Settings: Start*/
#ifndef WAP_CUSTOM_CFG_MAX_MMS_WARNING_MSG
#define WAP_CUSTOM_CFG_MAX_MMS_WARNING_MSG 95
#endif

#ifndef WAP_CUSTOM_CFG_MAX_NBR_MMS_MSG
#define WAP_CUSTOM_CFG_MAX_NBR_MMS_MSG 101
#endif

#ifndef WAP_CUSTOM_CFG_MAX_MMS_SLIDES
#define WAP_CUSTOM_CFG_MAX_MMS_SLIDES 20
#endif

#ifndef WAP_CUSTOM_CFG_MAX_MMS_ADDRESS
#define WAP_CUSTOM_CFG_MAX_MMS_ADDRESS 20
#endif

#ifndef WAP_CUSTOM_CFG_MAX_MMS_ATTACHMENT
#define WAP_CUSTOM_CFG_MAX_MMS_ATTACHMENT 3
#endif

#ifndef WAP_CUSTOM_CFG_MAX_MMS_GET_RETRY
#define WAP_CUSTOM_CFG_MAX_MMS_GET_RETRY   2
#endif

#ifndef WAP_CUSTOM_CFG_MAX_MMS_POST_MSG_RETRY
#define WAP_CUSTOM_CFG_MAX_MMS_POST_MSG_RETRY   3       /* Customer can reduce this value to zero, if they don't want resend MMS when error occurs. */
#endif

#ifndef WAP_CUSTOM_CFG_MAX_MMS_POST_PDU_RETRY
#define WAP_CUSTOM_CFG_MAX_MMS_POST_PDU_RETRY   2       /* This value isn't recommeded to reduce. */
#endif

#ifndef WAP_CUSTOM_CFG_MMS_GET_TIMEOUT
#define WAP_CUSTOM_CFG_MMS_GET_TIMEOUT   400    /* 40 seconds */
#endif

#ifndef WAP_CUSTOM_CFG_MMS_POST_TIMEOUT
#define WAP_CUSTOM_CFG_MMS_POST_TIMEOUT   1200  /* 120 seconds, this value isn't recommeded to reduce. */
#endif

#ifndef WAP_CUSTOM_CFG_MAX_MMS_CACHE_PUSH_NUM
#define WAP_CUSTOM_CFG_MAX_MMS_CACHE_PUSH_NUM 10
#endif

#ifndef WAP_CUSTOM_CFG_MAX_MMS_MSG_SIZE
#define WAP_CUSTOM_CFG_MAX_MMS_MSG_SIZE   (300*1024)
#endif
/* MMS Settings: End*/




#ifdef JATAAYU_SUPPORT /*The following settings are valid when Jataayu WAP/MMS is enabled*/

/* Browser Settings: Start */
#ifndef WAP_CUSTOM_CFG_MAX_CACHE_SIZE
#define WAP_CUSTOM_CFG_MAX_CACHE_SIZE  (20*1024)
#endif

#ifndef WAP_CUSTOM_CFG_MAX_COOKIES_SIZE
#define WAP_CUSTOM_CFG_MAX_COOKIES_SIZE  20
#endif

#ifndef WAP_CUSTOM_CFG_PUSH_MAX_NO_OF_MSG
#define WAP_CUSTOM_CFG_PUSH_MAX_NO_OF_MSG       15
#endif

#ifndef WAP_CUSTOM_CFG_DEFAULT_UA_HEADER
#define WAP_CUSTOM_CFG_DEFAULT_UA_HEADER  "MAUI WAP Browser"
#endif

#ifndef WAP_CUSTOM_CFG_DEFAULT_UA_PROF_URL
#define WAP_CUSTOM_CFG_DEFAULT_UA_PROF_URL   ""
#endif

#ifndef WAP_CUSTOM_CFG_DEFAULT_BROWSE_TIMEOUT
#define WAP_CUSTOM_CFG_DEFAULT_BROWSE_TIMEOUT   300
#endif

#ifndef WAP_CUSTOM_CFG_DEFAULT_SHOW_IMAGES_ON
#define WAP_CUSTOM_CFG_DEFAULT_SHOW_IMAGES_ON         1
#endif

#ifndef WAP_CUSTOM_CFG_DEFAULT_SHOW_HISTORY_AS_URL
#define WAP_CUSTOM_CFG_DEFAULT_SHOW_HISTORY_AS_URL    0
#endif

#ifndef WAP_CUSTOM_CFG_DEFAULT_SHOW_SERVICE_INBOX_MSG
#define WAP_CUSTOM_CFG_DEFAULT_SHOW_SERVICE_INBOX_MSG	1
#endif

#ifndef WAP_CUSTOM_CFG_DEFAULT_IMAGE_SELECTION_ON
#define WAP_CUSTOM_CFG_DEFAULT_IMAGE_SELECTION_ON		0
#endif

#ifndef CUSTOM_WAP_BKM_TITLE_LEN
#define CUSTOM_WAP_BKM_TITLE_LEN 41
#endif

#ifndef WAP_CUSTOM_CFG_N_NBR_BOOKMARKS
#define WAP_CUSTOM_CFG_N_NBR_BOOKMARKS 20
#endif

#ifndef CUSTOM_WAP_BKM_URL_LEN
#define CUSTOM_WAP_BKM_URL_LEN 129
#endif

#ifndef CUSTOM_WAP_HISTORY_TITLE_LEN
#define CUSTOM_WAP_HISTORY_TITLE_LEN      41
#endif

#ifndef CUSTOM_WAP_CFG_N_NBR_HISTORY
#define CUSTOM_WAP_CFG_N_NBR_HISTORY      10
#endif

#ifndef CUSTOM_WAP_HISTORY_TITLE_LEN
#define CUSTOM_WAP_HISTORY_TITLE_LEN      41
#endif

#ifndef CUSTOM_WAP_HISTORY_URL_LEN
#define CUSTOM_WAP_HISTORY_URL_LEN        129
#endif
/* Browser Settings: End */

/* MMS Settings: Start*/
#ifndef WAP_CUSTOM_CFG_MMS_VERSION
#define WAP_CUSTOM_CFG_MMS_VERSION 1    /* 1: 1.0, 2: 1.1, 3: 1.2, 4:latest version */
#endif

#ifndef WAP_CUSTOM_CFG_DEFAULT_MMS_UA_HEADER
#define WAP_CUSTOM_CFG_DEFAULT_MMS_UA_HEADER "MAUI MMS User Agent"
#endif

#ifndef WAP_CUSTOM_CFG_DEFAULT_MMS_UA_PROF_URL
#define WAP_CUSTOM_CFG_DEFAULT_MMS_UA_PROF_URL   ""     /* New */
#endif

#ifndef WAP_CUSTOM_CFG_MAX_MMS_MSG_SIZE
#define WAP_CUSTOM_CFG_MAX_MMS_MSG_SIZE   (300*1024)
#endif
/* MMS Settings: End*/




/*******************************************************************************
 *   Global function prototype                                                 *
 ******************************************************************************/
/* WAP Browser */
extern kal_uint32 wap_custom_get_browser_max_cache_size(void);
extern kal_uint32 wap_custom_get_browser_max_cookies_size(void);
extern kal_uint16 wap_custom_get_browser_max_push_msg_num(void);
extern const kal_uint8 *wap_custom_get_browser_ua_header(void);
extern const kal_uint8 *wap_custom_get_browser_ua_prof_url(void);
extern const kal_uint8 *wap_custom_get_browser_accept_charset(kal_uint32 index);
extern const kal_uint8 *wap_custom_get_browser_accept_content_type(kal_uint32 index);
extern const kal_uint8 *wap_custom_get_browser_accept_language(kal_uint32 index);

/* MMS Client */
extern kal_uint8 wap_custom_get_mms_version(void);
extern const kal_uint8 *wap_custom_get_mms_user_agent(void);
extern const kal_uint8 *wap_custom_get_mms_ua_prof_url(void);
extern const kal_uint8 *wap_custom_get_mms_accept_charset(kal_uint32 index);
extern const kal_uint8 *wap_custom_get_mms_accept_content_type(kal_uint32 index);
extern const kal_uint8 *wap_custom_get_mms_accept_language(kal_uint32 index);
extern kal_uint16 wap_custom_get_max_mms_num(void);
extern kal_uint32 wap_custom_get_max_mms_msg_size(void);
extern kal_uint16 wap_custom_get_max_mms_warning_num(void);
extern kal_uint32 wap_custom_get_max_mms_get_retry_timeout(void);
extern kal_uint32 wap_custom_get_max_mms_get_retry_nums(void);
extern kal_uint32 wap_custom_get_max_mms_post_retry_timeout(void);
extern kal_uint32 wap_custom_get_max_mms_post_msg_retry_nums(void);
extern kal_uint32 wap_custom_get_max_mms_post_pdu_retry_nums(void);
extern kal_uint8 wap_custom_get_max_mms_slides(void);
extern kal_uint16 wap_custom_get_max_mms_cache_push_num(void);
extern kal_uint8 wap_custom_get_max_mms_address(void);
#endif /* JATAAYU_SUPPORT */

#ifdef OBIGO_Q03C    /* Obigo only */
/* ==================================== Obigo Only ======================================= */

/*
 * WAP supports background image has the defect.
 * The marquee donesn't work well when enable backgound image.
 * The marguee's background color is white and overlap the background image.
 */
//#define WAP_CUSTOM_CFG_SUPPORT_BACKGROUND_IMAGE


/* __CUSTPACK_MULTIBIN     Johnnie   BEGIN */
#define CUSTOM_WAP_PROFILE_PROXY_PORT 9
#define CUSTOM_WAP_PROFILE_PROFILE_NAME 0
#define CUSTOM_WAP_PROFILE_HOMEPAGE_URL 24
#define CUSTOM_WAP_PROFILE_DATA_ACCOUNT 1
#define CUSTOM_WAP_PROFILE_CONN_TYPE 4
#define CUSTOM_WAP_PROFILE_PROXY_IP 7
#define CUSTOM_WAP_PROFILE_USERNAME 12
#define CUSTOM_WAP_PROFILE_PASSWORD 8

#define CUSTOM_WAP_PROFILE_PROFILE_NAME_LEN 41
#define CUSTOM_WAP_PROFILE_HOMEPAGE_URL_LEN 129
#define CUSTOM_WAP_PROFILE_USERNAME_LEN 31
#define CUSTOM_WAP_PROFILE_PASSWORD_LEN 31
#define CUSTOM_WAP_ROOT_CA_CONTENT_LEN 1024
#define CUSTOM_WAP_UA_HEADER_LEN 257
#define CUSTOM_WAP_UA_PROF_URL_LEN 257
#define CUSTOM_MMS_UA_HEADER_LEN 257
#define CUSTOM_WAP_BKM_TITLE_LEN 41
#define CUSTOM_WAP_BKM_URL_LEN 129
#define CUSTOM_WAP_TRUSTLIST_LEN 129

#ifndef WAP_CUSTOM_CFG_N_WAP_PROFILES
#define WAP_CUSTOM_CFG_N_WAP_PROFILES  10
#endif

#ifndef WAP_CUSTOM_CFG_N_MMS_PROFILES
#define WAP_CUSTOM_CFG_N_MMS_PROFILES  10
#endif

#ifndef WAP_CUSTOM_CFG_N_NBR_BOOKMARKS
#define WAP_CUSTOM_CFG_N_NBR_BOOKMARKS 20
#endif

#ifndef WAP_CUSTOM_CFG_N_NBR_TRUSTLISTS
#define WAP_CUSTOM_CFG_N_NBR_TRUSTLISTS 10
#endif

#ifndef CUSTOM_WAP_TRUSTLIST_LEN
#define CUSTOM_WAP_TRUSTLIST_LEN 129
#endif

#ifndef WAP_CUSTOM_CFG_N_ROOT_CA
#define WAP_CUSTOM_CFG_N_ROOT_CA       3
#endif

#ifndef WAP_CUSTOM_CFG_MAX_CACHE_SIZE
#define WAP_CUSTOM_CFG_MAX_CACHE_SIZE  (100*1024)
#endif

#ifndef WAP_CUSTOM_CFG_DEFAULT_UA_HEADER
#define WAP_CUSTOM_CFG_DEFAULT_UA_HEADER  "MAUI_WAP_Browser"
#endif

#ifndef WAP_CUSTOM_CFG_DEFAULT_UA_PROF_URL
#define WAP_CUSTOM_CFG_DEFAULT_UA_PROF_URL   ""
#endif

#ifndef WAP_CUSTOM_CFG_DEFAULT_BROWSE_TIMEOUT
#define WAP_CUSTOM_CFG_DEFAULT_BROWSE_TIMEOUT   300
#endif

#ifndef WAP_CUSTOM_CFG_PUSH_MAX_NO_OF_MSG
#define WAP_CUSTOM_CFG_PUSH_MAX_NO_OF_MSG       15
#endif

#ifndef WAP_CUSTOM_CFG_PUSH_SET_ENABLE_PUSH
#define WAP_CUSTOM_CFG_PUSH_SET_ENABLE_PUSH     1
#endif

#ifndef WAP_CUSTOM_CFG_PUSH_SET_TRUST_SETTING
#define WAP_CUSTOM_CFG_PUSH_SET_TRUST_SETTING   0
#endif

#ifndef WAP_CUSTOM_CFG_PUSH_SET_SL_SETTING
#define WAP_CUSTOM_CFG_PUSH_SET_SL_SETTING      1
#endif

#ifndef WAP_CUSTOM_CFG_DEFAULT_MMS_UA_HEADER
#define WAP_CUSTOM_CFG_DEFAULT_MMS_UA_HEADER "MAUI MMS User Agent"
#endif

#ifndef WAP_CUSTOM_CFG_MAX_MMS_MSG_SIZE
#define WAP_CUSTOM_CFG_MAX_MMS_MSG_SIZE   (300*1024)
#endif


#ifndef WAP_CUSTOM_CFG_MMS_SLIDE_DURATION
#define WAP_CUSTOM_CFG_MMS_SLIDE_DURATION 8000  /* ms (unused) */
#endif

#ifndef WAP_CUSTOM_CFG_MMS_IMMED_RETRIEVAL_MODE
#define WAP_CUSTOM_CFG_MMS_IMMED_RETRIEVAL_MODE 1       /* 0: auto, 1: deferred, 2: restricted (unused) */
#endif

#ifndef WAP_CUSTOM_CFG_MMS_ROAM_RETRIEVAL_MODE
#define WAP_CUSTOM_CFG_MMS_ROAM_RETRIEVAL_MODE 1        /* 0: auto, 1: deferred, 2: restricted (unused) */
#endif

#ifndef WAP_CUSTOM_CFG_MMS_ALLOW_ADVERTIMSEMENT
#define WAP_CUSTOM_CFG_MMS_ALLOW_ADVERTIMSEMENT 1       /* 0: no, 1: yes (unused) */
#endif

#ifndef WAP_CUSTOM_CFG_MMS_ALLOW_ANONYMOUS
#define WAP_CUSTOM_CFG_MMS_ALLOW_ANONYMOUS 1    /* 0: no, 1: yes (unused) */
#endif

#ifndef WAP_CUSTOM_CFG_MMS_REQ_DELIVERY_REPORT
#define WAP_CUSTOM_CFG_MMS_REQ_DELIVERY_REPORT 1        /* 0: no, 1: yes (unused) */
#endif

#ifndef WAP_CUSTOM_CFG_MMS_REQ_READ_REPORT
#define WAP_CUSTOM_CFG_MMS_REQ_READ_REPORT 1    /* 0: no, 1: yes (unused) */
#endif

#ifndef WAP_CUSTOM_CFG_MMS_SEND_DELIVERY_REPORT
#define WAP_CUSTOM_CFG_MMS_SEND_DELIVERY_REPORT 1       /* 0: no, 1: yes (unused) */
#endif

#ifndef WAP_CUSTOM_CFG_MMS_SEND_READ_REPORT
#define WAP_CUSTOM_CFG_MMS_SEND_READ_REPORT 1   /* 0: no, 1: yes (unused) */
#endif

#ifndef WAP_CUSTOM_CFG_MMS_VERSION
#define WAP_CUSTOM_CFG_MMS_VERSION 1    /* 0: default, 1: 1.0, 2: 1.1, 3: latest version (unused) */
#endif

#ifndef WAP_CUSTOM_CFG_MMS_RETR_SIZE_FILTER
#define WAP_CUSTOM_CFG_MMS_RETR_SIZE_FILTER  0  /* 0: disable, 1: enable */
#endif

/* the following 2 constant are deserved from constant above and unnecessary to to modify */
#define WAP_CUSTOM_CFG_PROFILE_FILE_SIZE  ((WAP_CUSTOM_CFG_N_WAP_PROFILES+WAP_CUSTOM_CFG_N_MMS_PROFILES)*256)
#define WAP_CUSTOM_CFG_BOOKMARK_FILE_SIZE (WAP_CUSTOM_CFG_N_NBR_BOOKMARKS*256)
#define WAP_CUSTOM_CFG_TRUSTLIST_FILE_SIZE (WAP_CUSTOM_CFG_N_NBR_TRUSTLISTS*256)

/* the following are macro to access wap default and unnecessary to modify */
#define CUST_WAP_PROFILE_DEFAULT (custpack_wap_default.wap_profile_default)
#define CUST_MMS_PROFILE_DEFAULT (custpack_wap_default.mms_profile_default)
#define CUST_WAP_BKM_DEFAULT     (custpack_wap_default.wap_bkm_default)
#define CUST_WAP_TRUSTLIST_DEFAULT     (wap_config_default.wap_trustList_default)
#define CUST_WAP_ROOT_CA_DEFAULT (custpack_wap_default.wap_root_ca_default)
#define CUST_WAP_CONFIG_DEFAULT  (custpack_wap_default.wap_config_default)
#define CUST_MMS_CONFIG_DEFAULT  (custpack_wap_default.mms_config_default)

typedef struct
{
    kal_uint8 editable;
    kal_uint8 empty;
    kal_uint16 proxy_port;
    kal_uint8 profile_name[CUSTOM_WAP_PROFILE_PROFILE_NAME_LEN];
    kal_uint8 homepage_url[CUSTOM_WAP_PROFILE_HOMEPAGE_URL_LEN];
    kal_uint8 data_account;
    kal_uint8 conn_type;
    kal_uint8 proxy_ip[4];
    kal_uint8 username[CUSTOM_WAP_PROFILE_USERNAME_LEN];
    kal_uint8 password[CUSTOM_WAP_PROFILE_PASSWORD_LEN];
} custom_profile_content_struct;

typedef struct
{
    kal_uint8 n_wap_profiles;
    custom_profile_content_struct profile[WAP_CUSTOM_CFG_N_WAP_PROFILES];
} custom_wap_profile_struct;

typedef struct
{
    kal_uint8 n_mms_profiles;
    custom_profile_content_struct profile[WAP_CUSTOM_CFG_N_MMS_PROFILES];
} custom_mms_profile_struct;

typedef struct
{
    kal_uint8 editable;
    kal_uint8 empty;
    kal_uint8 bkm_name[CUSTOM_WAP_BKM_TITLE_LEN];
    kal_uint8 bkm_url[CUSTOM_WAP_BKM_URL_LEN];
} custom_bkm_content_struct;

typedef struct
{
    kal_uint16 max_n_bkms;
    custom_bkm_content_struct bkm[WAP_CUSTOM_CFG_N_NBR_BOOKMARKS];
} custom_wap_bkm_struct;

typedef struct
{
    kal_uint8 empty;
    kal_uint32 tl_type;
    kal_uint8 tl_address[CUSTOM_WAP_TRUSTLIST_LEN];
} custom_trustList_content_struct;

typedef struct
{
    kal_uint16 max_n_trustLists;
    custom_trustList_content_struct trustList[WAP_CUSTOM_CFG_N_NBR_TRUSTLISTS];
} custom_wap_trustList_struct;

typedef struct
{
    kal_uint8 editable;
    kal_uint8 empty;
    kal_uint8 root_ca_type;
    kal_uint8 root_ca_content[CUSTOM_WAP_ROOT_CA_CONTENT_LEN];
    kal_uint32 root_ca_content_len;
} custom_root_ca_content_struct;

typedef struct
{
    kal_uint8 n_root_ca;
    custom_root_ca_content_struct root_ca[WAP_CUSTOM_CFG_N_ROOT_CA];
} custom_wap_root_ca_struct;

typedef struct
{
    kal_uint32 max_cache_size;
    kal_uint32 browse_timeout;
    kal_uint16 max_n_push_msg;
    kal_uint16 set_push_enable_push;
    kal_uint16 set_push_trust_setting;
    kal_uint16 set_push_SL_setting;
    kal_uint8 ua_header[CUSTOM_WAP_UA_HEADER_LEN];
    kal_uint8 ua_prof_url[CUSTOM_WAP_UA_PROF_URL_LEN];
    custom_wap_trustList_struct const *wap_trustList_default;
} custom_wap_config_struct;

typedef struct
{
    kal_uint32 max_mms_size;
    kal_uint16 max_n_mms_msg;
    kal_uint16 max_n_msg_warning;
    kal_uint8 ua_header[CUSTOM_MMS_UA_HEADER_LEN];
    kal_uint8 max_n_get_retry;
    kal_uint8 max_n_post_msg_retry;
    kal_uint8 max_n_post_pdu_retry;
    kal_uint32 get_timeout;
    kal_uint32 post_timeout;
    kal_uint32 slide_duration;
    kal_uint8 immed_retrieval_mode;
    kal_uint8 roam_retrieval_mode;
    kal_uint8 allow_advertimsement;
    kal_uint8 allow_anonymous;
    kal_uint8 req_delivery_report;
    kal_uint8 req_read_report;
    kal_uint8 send_delivery_report;
    kal_uint8 send_read_report;
    kal_uint8 mms_version;
    kal_uint8 max_n_slide;
    kal_uint8 max_n_address;
    kal_uint8 max_n_attachment;
} custom_mms_config_struct;

typedef struct
{
    kal_uint8 version;
    custom_wap_profile_struct const *wap_profile_default;
    custom_mms_profile_struct const *mms_profile_default;
    custom_wap_bkm_struct const *wap_bkm_default;
    custom_wap_root_ca_struct const *wap_root_ca_default;
    custom_wap_config_struct const *wap_config_default;
    custom_mms_config_struct const *mms_config_default;
} wap_custpack_header;

/*******************************************************************************
 *   Global function prototype                                                 *
 ******************************************************************************/
extern kal_uint8 wap_custom_get_max_wap_prof_num(void);
extern kal_uint8 wap_custom_get_max_mms_prof_num(void);
extern kal_uint32 wap_custom_get_max_cache_size(void);
extern kal_uint16 wap_custom_get_max_bookmark_num(void);
extern kal_uint16 wap_custom_get_max_trustList_num(void);
extern const kal_uint8 *wap_custom_get_ua_header(void);
extern const kal_uint8 *wap_custom_get_ua_prof_url(void);
extern kal_uint16 wap_custom_get_max_push_msg_num(void);
extern kal_uint16 wap_custom_get_set_push_enable_push(void);
extern kal_uint16 wap_custom_get_set_push_trust_setting(void);
extern kal_uint16 wap_custom_get_set_push_SL_setting(void);
extern kal_uint32 wap_custom_get_default_browse_timeout(void);
extern const kal_uint8 *wap_custom_get_mms_user_agent(void);
extern kal_uint16 wap_custom_get_max_mms_num(void);
extern kal_uint32 wap_custom_get_max_mms_msg_size(void);
extern kal_uint16 wap_custom_get_max_mms_warning_num(void);
extern kal_uint32 wap_custom_get_max_mms_get_retry_timeout(void);
extern kal_uint32 wap_custom_get_max_mms_get_retry_nums(void);
extern kal_uint32 wap_custom_get_max_mms_post_retry_timeout(void);
extern kal_uint32 wap_custom_get_max_mms_post_msg_retry_nums(void);
extern kal_uint32 wap_custom_get_max_mms_post_pdu_retry_nums(void);
extern kal_uint32 wap_custom_get_mms_slide_duration(void);
extern kal_uint8 wap_custom_get_mms_immed_retrieval_mode(void);
extern kal_uint8 wap_custom_get_mms_roam_retrieval_mode(void);
extern kal_uint8 wap_custom_get_mms_allow_advertimsement(void);
extern kal_uint8 wap_custom_get_mms_allow_anonymous(void);
extern kal_uint8 wap_custom_get_mms_req_delivery_report(void);
extern kal_uint8 wap_custom_get_mms_req_read_report(void);
extern kal_uint8 wap_custom_get_mms_send_delivery_report(void);
extern kal_uint8 wap_custom_get_mms_send_read_report(void);
extern kal_uint8 wap_custom_get_mms_version(void);
extern kal_uint8 wap_custom_get_max_mms_slide(void);
extern kal_uint8 wap_custom_get_max_mms_address(void);
extern kal_uint8 wap_custom_get_max_mms_attachment(void);

extern const custom_wap_profile_struct wap_profile_default;
extern const custom_mms_profile_struct mms_profile_default;
extern const custom_wap_bkm_struct wap_bkm_default;
extern const custom_wap_trustList_struct wap_trustList_default;
extern const custom_wap_root_ca_struct wap_root_ca_default;
extern const custom_wap_config_struct wap_config_default;
extern const custom_mms_config_struct mms_config_default;
extern const wap_custpack_header custpack_wap_ptr;
extern wap_custpack_header custpack_wap_default;

/* __CUSTPACK_MULTIBIN     Johnnie   END */
#endif /* OBIGO_Q03C */

#ifdef OBIGO_Q05A  /* Obigo Q05A only */

#ifndef WAP_CUSTOM_CFG_DEFAULT_UA_HEADER
#define WAP_CUSTOM_CFG_DEFAULT_UA_HEADER  "MAUI_WAP_Browser"
#endif

#ifndef WAP_CUSTOM_CFG_DEFAULT_MMS_UA_HEADER
#define WAP_CUSTOM_CFG_DEFAULT_MMS_UA_HEADER  "MAUI MMS User Agent"
#endif

#ifndef WAP_CUSTOM_CFG_DEFAULT_UA_PROF_URL
#define WAP_CUSTOM_CFG_DEFAULT_UA_PROF_URL   ""
#endif

#ifndef WAP_CUSTOM_CFG_PUSH_MAX_NO_OF_MSG
#define WAP_CUSTOM_CFG_PUSH_MAX_NO_OF_MSG       15
#endif

#ifndef WAP_CUSTOM_CFG_DEFAULT_BROWSE_TIMEOUT
#define WAP_CUSTOM_CFG_DEFAULT_BROWSE_TIMEOUT   300
#endif

#ifndef WAP_CUSTOM_CFG_MMS_VERSION
#define WAP_CUSTOM_CFG_MMS_VERSION 1    /* 1: 1.0, 2: 1.1, 3: 1.2, 4:latest version */
#endif

#define WAP_CUSTOM_CFG_MAX_CACHE_SIZE  (100*1024)
#define WAP_CUSTOM_CFG_MAX_COOKIES_SIZE  20
#define CUSTOM_WAP_CFG_N_NBR_HISTORY      10
#define WAP_CUSTOM_CFG_DEFAULT_SHOW_IMAGE			0 //wap_bam_setting_val_images_always
#define WAP_CUSTOM_CFG_DEFAULT_SHOW_VIDEO			0 //wap_bam_setting_val_movies_always
#define WAP_CUSTOM_CFG_DEFAULT_PLAY_SOUND			0 //wap_bam_setting_val_sounds_always
#define WAP_CUSTOM_CFG_DEFAULT_HOMEPAGE				1 //Active Profile Homepage
#define WAP_CUSTOM_CFG_DEFAULT_RENDER_MODE			0 //Standard
#define WAP_CUSTOM_CFG_DEFAULT_NAVIGATE_MODE		0x04 //wap_bam_setting_val_nav_4_way = 0x04
#define WAP_CUSTOM_CFG_DEFAULT_FONT_SIZE			100 /*Medium*/
#define WAP_CUSTOM_CFG_DEFAULT_THUMBNAIL			0 //ON
#define WAP_CUSTOM_CFG_DEFAULT_SCREEN_SIZE			0 //Normal
#define WAP_CUSTOM_CFG_DEFAULT_ENCODE_METHOD_INDEX	0
#define WAP_CUSTOM_CFG_DEFAULT_LOAD_UNKOWN_MEDIA	0 //wap_bam_setting_val_no_mime_always
#define WAP_CUSTOM_CFG_DEFAULT_CSS					1 //wap_bam_setting_val_css_enable
#define WAP_CUSTOM_CFG_DEFAULT_SCRIPTS				1 //wap_bam_setting_val_script_enable
#define WAP_CUSTOM_CFG_DEFAULT_CACHE				1 //wap_bam_setting_val_cache_enable
#define WAP_CUSTOM_CFG_DEFAULT_COOKIE				1 //wap_bam_setting_val_cookies_enable
#define WAP_CUSTOM_CFG_DEFAULT_SHORTCUTS			1 //wap_bam_setting_val_shortcuts_enable
#define WAP_CUSTOM_CFG_DEFAULT_SECURITY_WARNINGS	3 //wap_bam_setting_val_sec_warning_enable
#define WAP_CUSTOM_CFG_DEFAULT_SEND_DEVICE_ID		0 //wap_bam_setting_val_imei_enable
#define WAP_CUSTOM_CFG_DEFAULT_SORTING_METHOD		0 //By Last Accessed

#ifndef WAP_CUSTOM_CFG_BROWSER_MEM_SIZE
#define WAP_CUSTOM_CFG_BROWSER_MEM_SIZE             600 * 1024
#endif
#define WAP_CUSTOM_DEFAULT_BRW_CONTENT_INDEX		0
#define WAP_CUSTOM_DEFAULT_MMS_CONTENT_INDEX		0

#ifdef GDI_USING_PNG

#define WAP_COMMON_CFG_ACCEPT_OBJECT_HEADER \
  "image/vnd.wap.wbmp, image/gif, image/bmp, image/jpeg, image/png, audio/amr, audio/imelody, audio/midi, audio/wav, */*"

#else

#define WAP_COMMON_CFG_ACCEPT_OBJECT_HEADER \
  "image/vnd.wap.wbmp, image/gif, image/bmp, image/jpeg, audio/amr, audio/imelody, audio/midi, audio/wav, */*"

#endif

/*
 *  Defines the image types that can be directly shown in the browser.
 *  This feature can be disabled if BRS_CFG_SUPPORTED_IMAGE_MIME is defined
 *  as the following:
 *
 *  #define WAP_COMMON_CFG_SUPPORTED_IMAGE_MIME ""
 */
#ifdef GDI_USING_PNG
#define WAP_COMMON_CFG_SUPPORTED_IMAGE_MIME \
  "image/vnd.wap.wbmp," \
  "image/gif," \
  "image/bmp," \
  "image/png," \
  "image/jpeg"
#else
#define WAP_COMMON_CFG_SUPPORTED_IMAGE_MIME \
  "image/vnd.wap.wbmp," \
  "image/gif," \
  "image/bmp," \
  "image/jpeg"
#endif

/*
 *  Defines the set of natural languages that are preferred by the browser.
 *  This information will be sent in HTTP ACCEPT-LANGUAGE header which is useful
 *  to multilingual sites for deciding the best language to serve to the client.
 *
 *  If no Accept-Language header is present in the request, the server
 *  may assume that all languages are equally acceptable, e.g.
 *
 *  #define WAP_COMMON_CFG_ACCEPT_LANGUAGE_HEADER	NULL
 *
 *  Reference: Section 14.4 Accept-Language in RFC2616
 */
#define WAP_COMMON_CFG_ACCEPT_LANGUAGE_HEADER  "zh-TW, en, zh;q=0.9"

/* Default "Accept-Charset:" header, sent by browser when retrieving a document. */
#define WAP_CUSTOM_CFG_ACCEPT_CHARSET_HEADER   "utf-8, iso-8859-1, us-ascii, iso-10646-ucs-2"

/* WAP MMS Settings  */


/*******************************************************************************
 *   Global function prototype                                                 *
 ******************************************************************************/
/*extern kal_uint32 wap_custom_get_browser_max_cache_size(void);
extern kal_uint32 wap_custom_get_browser_max_cookies_size(void);
extern kal_uint16 wap_custom_get_browser_max_push_msg_num(void);
extern const kal_uint8 *wap_custom_get_browser_ua_header(void);
extern const kal_uint8 *wap_custom_get_browser_ua_prof_url(void);
extern const kal_uint8 *wap_custom_get_browser_accept_charset(kal_uint32 index);
extern const kal_uint8 *wap_custom_get_browser_accept_content_type(kal_uint32 index);
extern const kal_uint8 *wap_custom_get_browser_accept_language(kal_uint32 index);*/
#define CUSTOM_WAP_TRUSTLIST_LEN 129

#ifndef CUSTOM_WAP_BKM_TITLE_LEN
#define CUSTOM_WAP_BKM_TITLE_LEN 41
#endif

#ifndef WAP_CUSTOM_CFG_N_NBR_BOOKMARKS
#define WAP_CUSTOM_CFG_N_NBR_BOOKMARKS 20
#endif

#ifndef CUSTOM_WAP_BKM_URL_LEN
#define CUSTOM_WAP_BKM_URL_LEN 129
#endif

typedef struct
{
    kal_uint8 editable;
    kal_uint8 empty;
    kal_uint8 bkm_name[CUSTOM_WAP_BKM_TITLE_LEN];
    kal_uint8 bkm_url[CUSTOM_WAP_BKM_URL_LEN];
} custom_bkm_content_struct;

typedef struct
{
    kal_uint16 max_n_bkms;
    custom_bkm_content_struct bkm[WAP_CUSTOM_CFG_N_NBR_BOOKMARKS];
} custom_wap_bkm_struct;

typedef struct
{
    kal_uint8 empty;
    kal_uint32 tl_type;
    kal_uint8 tl_address[CUSTOM_WAP_TRUSTLIST_LEN];
} custom_trustList_content_struct;

#endif /* OBIGO_Q05A */

#ifndef __OPTR_NONE__
    #include "op_custom_wap_config.h"
#endif

#endif /* _CUSTOM_WAP_CONFIG_H */

