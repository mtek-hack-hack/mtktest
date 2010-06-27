/*******************************************************************************
 * Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.,
 * All rights reserved.
 * This is unpublished proprietary source code of MobileSoft Technology
 *
 * The copyright notice above does not evidence any actual or intended
 * publication of such source code  
 *******************************************************************************
 */
/*========================================================================
 * Module Name: cms_wap_custom_config.h
 *
 * Module Function: 
 * Author Name: 
 * Create Date: 08/29/2005
 *
 *========================================================================
 */
#ifdef	CMS_NEW_APP
#ifndef _CMS_CUSTOM_WAP_CONFIG_H
#define _CMS_CUSTOM_WAP_CONFIG_H

//#include "kal_release.h"      	/* Basic data type */
#include "kal_non_specific_general_types.h"
#define CMS_CFG_N_WAP_PROFILES  10
#define CMS_CFG_N_MMS_PROFILES  10
#define CMS_CFG_N_NBR_BOOKMARKS 20

#define CMS_WAP_BOOKMARK_TITLE_LEN	64	
#define CMS_WAP_BOOKMARK_URL_LEN	(128*3+2)

#define CMS_WAP_UA_HEADER_LEN	(128*3+2)
#define CMS_WAP_UA_PROF_URL_LEN	(128*3+2)
#define GoBack2History GoBackHistory
/* the following are macro to access wap default and unnecessary to modify */
#if 0
#define CUST_CMS_WAP_PROFILE_DEFAULT	(cms_config_default.cms_wap_profile_default)
#define CUST_CMS_MMS_PROFILE_DEFAULT	(cms_config_default.cms_mms_profile_default)
#define CUST_CMS_WAP_BOOKMARK_DEFAULT	(cms_config_default.cms_wap_bookmark_default)
#define CUST_CMS_WAP_CONFIG_DEFAULT		(cms_config_default.cms_wap_config_default)
#define CUST_CMS_MMS_CONFIG_DEFAULT		(cms_config_default.cms_mms_config_default)
#endif
#define CMS_MAX_SERVICE_ID_LENGTH 64
#define CMS_MAX_CENTRE_ADDR_LENGTH (128*3+2)
#define CMS_MAX_GATEWAY_LENGTH 32
#define CMS_MAX_PORT_LENGTH 16

typedef struct
{        
   kal_uint8 empty;
   kal_uint8 profile_name[CMS_MAX_SERVICE_ID_LENGTH];
   kal_uint8 homepage_url[CMS_MAX_CENTRE_ADDR_LENGTH];
   kal_uint8 proxy_ip[CMS_MAX_GATEWAY_LENGTH];
   kal_uint8 proxy_port[CMS_MAX_PORT_LENGTH];    
   kal_uint8 data_account;
   kal_uint8 conn_type;
}  cms_profile_content_struct; 
   

typedef struct
{
   kal_uint8 n_wap_profiles;
   cms_profile_content_struct profile[CMS_CFG_N_WAP_PROFILES];
} cms_wap_profile_struct;


typedef struct
{
   kal_uint8 n_mms_profiles;         
   cms_profile_content_struct profile[CMS_CFG_N_MMS_PROFILES];
} cms_mms_profile_struct;

typedef struct
{
   kal_uint8 empty;
   kal_uint8 bkm_name[CMS_WAP_BOOKMARK_TITLE_LEN];
   kal_uint8 bkm_url[CMS_WAP_BOOKMARK_URL_LEN];
} cms_bookmark_content_struct;

typedef struct
{
   kal_uint16 max_n_bkms;      
   cms_bookmark_content_struct bkm[CMS_CFG_N_NBR_BOOKMARKS];
} cms_wap_bookmark_struct;


typedef struct
{
   kal_uint8 ua_header[CMS_WAP_UA_HEADER_LEN];
   kal_uint8 ua_prof_url[CMS_WAP_UA_PROF_URL_LEN];
   kal_uint32 max_cache_size;
   kal_uint32 browse_timeout;
   kal_uint16 max_n_push_msg;
} cms_wap_config_struct;

typedef struct
{
   kal_uint8 expires;
   kal_uint8 allow_anonymous;
   kal_uint8 send_delivery_report;
   kal_uint8 send_read_report;   
   kal_uint8 prior;
   kal_uint8 auto_receive;
   kal_uint32 frame_time;
   kal_uint8 max_mms_size;
   kal_uint8 mms_version;   
} cms_mms_config_struct;

typedef struct
{
   kal_uint8 version;
   cms_wap_profile_struct	const * cms_wap_profile_default;
   cms_mms_profile_struct	const * cms_mms_profile_default;
   cms_wap_bookmark_struct	const * cms_wap_bookmark_default;
   cms_wap_config_struct	const * cms_wap_config_default;
   cms_mms_config_struct	const * cms_mms_config_default;
} cms_mmswap_config_struct;

#endif /* _CMS_WAP_CONFIG_H */
#endif /* CMS_NEW_APP*/

