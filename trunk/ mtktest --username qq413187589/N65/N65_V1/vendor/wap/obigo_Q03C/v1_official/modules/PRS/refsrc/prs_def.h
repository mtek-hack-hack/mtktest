/*
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2003.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Teleca Mobile Technologies AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Teleca Mobile Technologies AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */
/*
 * prs_def.h
 *
 * Provisioning defines: defining supported elements and fields.
 */

#ifndef _prs_def_h
#define _prs_def_h

#ifndef _prs_type_h
#include "prs_type.h"
#endif


/**********************************************************************
 * Constants
 **********************************************************************/

/* Strings used for output in signals */ 
extern const char* const prs_Str_resources[];

typedef enum
{
/* OTA Bookmark */
   PRS_PATH_HOMEPAGE,
   PRS_PATH_OTA_BOOKMARK,
   PRS_STR_NAME,
   PRS_STR_URL,
/* WAP gateway and proxy */
   PRS_PATH_OTA_PROXY,
   PRS_PATH_WAP_PROXY,
   PRS_STR_HOMEURL,
   PRS_STR_MMSURL,
   PRS_STR_PROFILE_NAME,
   PRS_STR_PX_NAME,
   PRS_STR_PX_ADDRESS,
   PRS_STR_PX_PORT,
   PRS_STR_PX_SERVICE,
   PRS_STR_PX_TYPE,
   PRS_STR_PX_AUTH_NAME,
   PRS_STR_PX_AUTH_SECRET,
/* Bearer setting */
   PRS_PATH_OTA_BEARER,
   PRS_PATH_WAP_BEARER,
   PRS_STR_ADR_BEARER,
   PRS_STR_ISP_NAME,
   PRS_STR_PPP_AUTHTYPE,
   PRS_STR_PPP_AUTHNAME,
   PRS_STR_PPP_AUTHPW,
   PRS_STR_CSD_CALLTYPE,
   PRS_STR_CSD_CALLSPEED,
/* Bearer setting -- OTA setting only */
   PRS_STR_CSD_DAILSTRING,
   PRS_STR_GPRS_APN,
/* Bearer setting -- WAP setting only */
   PRS_STR_WAP_NAP_ADDR,
   PRS_STR_WAP_NAP_ADDRTYPE,
   PRS_PATH_WAP_APP,
   PRS_STR_WAP_APP_APPID,
   PRS_STR_WAP_APP_ADDR,
   PRS_STR_WAP_APP_RES_URI,
   PRS_STR_WAP_APP_RES_NAME,
/* for Dual SIM */
   PRS_PATH_MTK_INFO,
   PRS_STR_MTK_SIM_ID
} prs_str_res_enum; 

/* Destination list */
extern const prs_dest_list_t* const prs_Dest_list[];

/* Destination list names */
#define PRS_DEST_BRA             0x00
  

/*************************************
 * User data element node
 *************************************/

/*
 * User data element. Can exist in all types of node lists:
 *
 * #define PRS_USER_DATA         0
 */

/* Fields in the user data node */
#define PRS_USER_DATA_SIZE       1
  #define PRS_USR_NET_ACCOUNT    0
/*
 * Add more fields here and update PRS_USER_DATA_SIZE to the number of fields:
 * #define FIELD_1               1
 * #define FIELD_2               2
 * #define FIELD_3               3
 */

#define PRS_USER_DATA_IS_STRING_LOW \
  (PRS_INTEGER (PRS_USR_NET_ACCOUNT))
#define PRS_USER_DATA_IS_STRING_HIGH \
  (0)
/*
 * Add new fields to tell if they are strings or ints:
 * (PRS_INTEGER (FIELD_1) | \
 *  PRS_STRING  (FIELD_2) | \
 *  PRS_STRING  (FIELD_3))
 */

#define PRS_USER_DATA_IS_MULTI_LOW \
  (0)
#define PRS_USER_DATA_IS_MULTI_HIGH \
  (0)
/*
 * Add new fields to tell if they are of multi data type:
 * (PRS_MULTI (FIELD_1) | \
 *  PRS_MULTI  (FIELD_2) | \
 *  PRS_MULTI  (FIELD_3))
 */


extern const prs_field_def_t prs_user_data_Field_def[];


/**********************************************************************/
/*                            OTA Settings                            */
/*                Browser Settings & Browser Bookmarks                */
/**********************************************************************/

/*************************************
 * Definition tables
 *************************************/

extern MSF_INT8 prs_br_Element_action [];
extern const prs_field_def_t prs_br_usr_Field_def[];
extern const prs_field_def_t prs_br_adr_Field_def[];
extern const prs_field_def_t prs_br_url_Field_def[];
extern const prs_field_def_t prs_br_mmsurl_Field_def[];
extern const prs_field_def_t prs_br_nm_Field_def[];
extern const prs_field_def_t prs_br_bkm_Field_def[];
extern const prs_field_def_t prs_br_id_Field_def[];
  

/*************************************
 * Function defines
 *************************************/

#define PRS_BR_PROCESS_LIST_PRE            prs_br_process_list_pre
#define PRS_BR_PROCESS_NODE                NULL
#define PRS_BR_PROCESS_LIST_POST           prs_br_process_list_post


/*************************************
 * Element and field constants
 *************************************/

/* Address */
#define PRS_BR_ADDRESS_SIZE                18
  #define PRS_BR_ADR_BEARER                0
  #define PRS_BR_ADR_PROXY                 1
  #define PRS_BR_ADR_PORT                  2
  #define PRS_BR_ADR_PROXY_TYPE            3
  #define PRS_BR_ADR_PROXY_LOGINTYPE       4
  #define PRS_BR_ADR_PROXY_AUTHNAME        5
  #define PRS_BR_ADR_PROXY_AUTHSECRET      6
  #define PRS_BR_ADR_SMS_SMSC_ADDRESS      7
  #define PRS_BR_ADR_USSD_SERVICE_CODE     8
  #define PRS_BR_ADR_GPRS_ACCESSPOINTNAME  9
  #define PRS_BR_ADR_PPP_LOGINTYPE         10
  #define PRS_BR_ADR_PPP_AUTHTYPE          11
  #define PRS_BR_ADR_PPP_AUTHNAME          12
  #define PRS_BR_ADR_PPP_AUTHSECRET        13
  #define PRS_BR_ADR_CSD_DIALSTRING        14
  #define PRS_BR_ADR_CSD_CALLTYPE          15
  #define PRS_BR_ADR_CSD_CALLSPEED         16
  #define PRS_BR_ADR_ISP_NAME              17

/* URL */
#define PRS_BR_URL_SIZE                    1
  #define PRS_BR_URL_URL                   0 /* always included */

/* MMS URL */
#define PRS_BR_MMSURL_SIZE                 1
  #define PRS_BR_MMSURL_URL                0 /* always included */

/* Name */
#define PRS_BR_NAME_SIZE                   1
  #define PRS_BR_NM_NAME                   0 /* always included */

/* Bookmark */
#define PRS_BR_BOOKMARK_SIZE               2
  #define PRS_BR_BKM_URL                   0 /* always included */
  #define PRS_BR_BKM_NAME                  1 /* always included */

/* Id */
#define PRS_BR_ID_SIZE                     1
  #define PRS_BR_ID_NAME                   0 /* always included */


/*************************************
 * Default values
 *************************************/

/* BEARER */
#define PRS_BR_DEFAULT_BEARER              PRS_VAL_BR_GSM_CSD

/* PPP_AUTHTYPE */
#define PRS_BR_DEFAULT_PPP_AUTHTYPE        PRS_VAL_BR_PAP

/* PPP_LOGINTYPE */
#define PRS_BR_DEFAULT_PPP_LOGINTYPE       PRS_VAL_BR_AUTOMATIC

/* PROXY_TYPE */
#define PRS_BR_DEFAULT_PROXY_TYPE          PRS_VAL_BR_MSISDN_NO

/* PORT */
#define PRS_BR_DEFAULT_PORT                PRS_VAL_BR_9201

/* CSD_CALLTYPE */
#define PRS_BR_DEFAULT_CSD_CALLTYPE        PRS_VAL_BR_ANALOGUE

/* CSD_CALLSPEED */
/* Used if CSD_CALLTYPE is ANALOGUE */
#define PRS_BR_DEFAULT_CSD_CALLSPEED_A     PRS_VAL_BR_AUTO
/* Used if CSD_CALLTYPE is ISDN */
#define PRS_BR_DEFAULT_CSD_CALLSPEED_I     PRS_VAL_BR_9600



/**********************************************************************/
/*                            OTA Settings                            */
/*                           SyncML settings                          */
/**********************************************************************/

/*************************************
 * Definition tables
 *************************************/

extern MSF_INT8 prs_syn_Element_action [];


/*************************************
 * Function defines
 *************************************/

#define PRS_SYN_PROCESS_LIST_PRE           NULL
#define PRS_SYN_PROCESS_NODE               NULL
#define PRS_SYN_PROCESS_LIST_POST          NULL


/*************************************
 * Element support defines
 *************************************/

/* SynSettings */
#define PRS_SYN_SYNSETTINGS_SIZE           4
  #define PRS_SYN_SSET_VERSION             0
  #define PRS_SYN_SSET_HOSTADDR            1
  #define PRS_SYN_SSET_PORT                2
  #define PRS_SYN_SSET_NAME                3

/* RemoteDB */
#define PRS_SYN_REMOTEDB_SIZE              8

  #define PRS_SYN_RDB_CTTYPE               0
  #define PRS_SYN_RDB_CTVER                1
  #define PRS_SYN_RDB_URI                  2
  #define PRS_SYN_RDB_NAME                 3
  #define PRS_SYN_RDB_AUTHLEVEL            4
  #define PRS_SYN_RDB_AUTHSCHEME           5
  #define PRS_SYN_RDB_USERNAME             6
  #define PRS_SYN_RDB_CRED                 7

/* Auth */
#define PRS_SYN_AUTH_SIZE                  4

  #define PRS_SYN_AUTH_AUTHLEVEL           0
  #define PRS_SYN_AUTH_AUTHSCHEME          1
  #define PRS_SYN_AUTH_USERNAME            2
  #define PRS_SYN_AUTH_CRED                3

/* ConRef */
#define PRS_SYN_CONREF_SIZE                5

  #define PRS_SYN_CREF_CONTYPE             0
  #define PRS_SYN_CREF_BEARER              1
  #define PRS_SYN_CREF_ADDR                2
  #define PRS_SYN_CREF_ADDRTYPE            3
  #define PRS_SYN_CREF_REFID               4



/**********************************************************************/
/*                          WAP Provisioning                          */
/**********************************************************************/

/*************************************
 * Definition tables
 *************************************/

extern MSF_INT8 prs_wap_Element_action [];
extern const prs_field_def_t prs_wap_usr_Field_def[];
extern const prs_field_def_t prs_wap_px_Field_def[];
extern const prs_field_def_t prs_wap_nap_Field_def[];
extern const prs_field_def_t prs_wap_bts_Field_def[];
extern const prs_field_def_t prs_wap_cid_Field_def[];
extern const prs_field_def_t prs_wap_vdc_Field_def[];
extern const prs_field_def_t prs_wap_app_Field_def[];
extern const prs_field_def_t prs_wap_acc_Field_def[];
#ifdef WAP_SUPPORT
extern const prs_field_def_t prs_wap_napauthinfo_Field_def[];
extern const prs_field_def_t prs_wap_validity_Field_def[];
extern const prs_field_def_t prs_wap_appaddr_Field_def[];
extern const prs_field_def_t prs_wap_appauth_Field_def[];
extern const prs_field_def_t prs_wap_resource_Field_def[];
#endif  /* WAP_SUPPORT */
#ifdef MTK_TMP_PATCH /* CR27923 */
#ifdef PRS_CONFIG_DMP_SUPPORT
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  /* PRS_CONFIG_DMP_SUPPORT */
/* OMA Extension */
extern const prs_field_def_t prs_wap_wlan_Field_def[];
extern const prs_field_def_t prs_wap_secssid_Field_def[];
extern const prs_field_def_t prs_wap_eap_Field_def[];
extern const prs_field_def_t prs_wap_cert_Field_def[];
extern const prs_field_def_t prs_wap_wepkey_Field_def[];
#endif  /* MTK_TMP_PATCH CR27923 */
 
/*************************************
 * Function defines
 *************************************/

#define PRS_WAP_PROCESS_LIST_PRE           prs_wap_process_list_pre
#define PRS_WAP_PROCESS_NODE               NULL
#define PRS_WAP_PROCESS_LIST_POST          NULL


/*************************************
 * Element support defines
 *************************************/

/* PROXY */
#define PRS_WAP_PROXY_SIZE                 26
  /* PXLOGICAL */
  #define PRS_WAP_PX_PROXY_ID              0
  #define PRS_WAP_PX_PROXY_PW              1
  #define PRS_WAP_PX_PPGAUTH_TYPE          2
  #define PRS_WAP_PX_PROXY_PROVIDER_ID     3
  #define PRS_WAP_PX_NAME                  4
  #define PRS_WAP_PX_TRUST                 5
  #define PRS_WAP_PX_MASTER                6
  #define PRS_WAP_PX_STARTPAGE             7
  #define PRS_WAP_PX_BASAUTH_ID            8
  #define PRS_WAP_PX_BASAUTH_PW            9
  #define PRS_WAP_PX_WSP_VERSION           10
  #define PRS_WAP_PX_PUSHENABLED           11
  #define PRS_WAP_PX_PULLENABLED           12
  /* PXAUTHINFO */                             /* Restriction: only one PXAUTHINFO */
  #define PRS_WAP_PX_PXAUTH_TYPE           13
  #define PRS_WAP_PX_PXAUTH_ID             14
  #define PRS_WAP_PX_PXAUTH_PW             15
  /* PXPHYSICAL */
  #define PRS_WAP_PX_PHYSICAL_PROXY_ID     16
/*#define PRS_WAP_PX_DOMAIN               -1    * Restriction: no DOMAIN */
  #define PRS_WAP_PX_PXADDR                17
  #define PRS_WAP_PX_PXADDRTYPE            18
  #define PRS_WAP_PX_PXADDR_FQDN           19
  #define PRS_WAP_PX_TO_NAPID              20
  /* PORT */                                   /* Restriction: only one PORT */
  #define PRS_WAP_PX_PORTNBR               21
  #define PRS_WAP_PX_SERVICE               22

#ifdef WAP_SUPPORT
/* NAPDEF */
#define PRS_WAP_NAPDEF_SIZE                29
  #define PRS_WAP_NAP_NAPID                0
  #define PRS_WAP_NAP_BEARER               1
  #define PRS_WAP_NAP_NAME                 2
  #define PRS_WAP_NAP_INTERNET             3
  #define PRS_WAP_NAP_NAP_ADDRESS          4
  #define PRS_WAP_NAP_NAP_ADDRTYPE         5
  #define PRS_WAP_NAP_DNS_ADDR             6
  #define PRS_WAP_NAP_CALLTYPE             7
  #define PRS_WAP_NAP_LOCAL_ADDR           8
  #define PRS_WAP_NAP_LOCAL_ADDRTYPE       9
  #define PRS_WAP_NAP_LINKSPEED            10
  #define PRS_WAP_NAP_DNLINKSPEED          11
  #define PRS_WAP_NAP_LINGER               12
  #define PRS_WAP_NAP_DELIVERY_ERR_SDU     13
  #define PRS_WAP_NAP_DELIVERY_ORDER       14
  #define PRS_WAP_NAP_TRAFFIC_CLASS        15
  #define PRS_WAP_NAP_MAX_SDU_SIZE         16
  #define PRS_WAP_NAP_MAX_BITRATE_UPLINK   17
  #define PRS_WAP_NAP_MAX_BITRATE_DNLINK   18
  #define PRS_WAP_NAP_RESIDUAL_BER         19
  #define PRS_WAP_NAP_SDU_ERROR_RATIO      20
  #define PRS_WAP_NAP_TRAFFIC_HAND_PRIO    21
  #define PRS_WAP_NAP_TRANSFER_DELAY       22
  #define PRS_WAP_NAP_GUARANTEED_RATE_UP   23
  #define PRS_WAP_NAP_GUARANTEED_RATE_DN   24
  #define PRS_WAP_NAP_MAX_NUM_RETRY        25
  #define PRS_WAP_NAP_FIRST_RETRY_TIMEOUT  26
  #define PRS_WAP_NAP_REREG_THRESHOLD      27
  #define PRS_WAP_NAP_T_BIT                28
/* NAPAUTHINFO */
#define PRS_WAP_NAPAUTHINFO_SIZE           5
  #define PRS_WAP_NAP_AUTHTYPE             0
  #define PRS_WAP_NAP_AUTHNAME             1
  #define PRS_WAP_NAP_AUTHSECRET           2
  #define PRS_WAP_NAP_AUTH_ENTITY          3
  #define PRS_WAP_NAP_SPI                  4
/* VALIDITY */
#define PRS_WAP_VALIDITY_SIZE              5
  #define PRS_WAP_NAP_COUNTRY              0
  #define PRS_WAP_NAP_NETWORK              1
  #define PRS_WAP_NAP_SID                  2
  #define PRS_WAP_NAP_SOC                  3
  #define PRS_WAP_NAP_VALIDUNTIL           4
#else   /* WAP_SUPPORT */
/* NAPDEF */
#define PRS_WAP_NAPDEF_SIZE                34
  #define PRS_WAP_NAP_NAPID                0
  #define PRS_WAP_NAP_BEARER               1
  #define PRS_WAP_NAP_NAME                 2
  #define PRS_WAP_NAP_INTERNET             3
  #define PRS_WAP_NAP_NAP_ADDRESS          4
  #define PRS_WAP_NAP_NAP_ADDRTYPE         5
  #define PRS_WAP_NAP_DNS_ADDR             6
  #define PRS_WAP_NAP_CALLTYPE             7
  #define PRS_WAP_NAP_LOCAL_ADDR           8
  #define PRS_WAP_NAP_LOCAL_ADDRTYPE       9
  #define PRS_WAP_NAP_LINKSPEED            10
  #define PRS_WAP_NAP_DNLINKSPEED          11
  #define PRS_WAP_NAP_LINGER               12
  #define PRS_WAP_NAP_DELIVERY_ERR_SDU     13
  #define PRS_WAP_NAP_DELIVERY_ORDER       14
  #define PRS_WAP_NAP_TRAFFIC_CLASS        15
  #define PRS_WAP_NAP_MAX_SDU_SIZE         16
  #define PRS_WAP_NAP_MAX_BITRATE_UPLINK   17
  #define PRS_WAP_NAP_MAX_BITRATE_DNLINK   18
  #define PRS_WAP_NAP_RESIDUAL_BER         19
  #define PRS_WAP_NAP_SDU_ERROR_RATIO      20
  #define PRS_WAP_NAP_TRAFFIC_HAND_PRIO    21
  #define PRS_WAP_NAP_TRANSFER_DELAY       22
  #define PRS_WAP_NAP_GUARANTEED_RATE_UP   23
  #define PRS_WAP_NAP_GUARANTEED_RATE_DN   24
  #define PRS_WAP_NAP_MAX_NUM_RETRY        25
  #define PRS_WAP_NAP_FIRST_RETRY_TIMEOUT  26
  #define PRS_WAP_NAP_REREG_THRESHOLD      27
  #define PRS_WAP_NAP_T_BIT                28
  /* NAPAUTHINFO */                            /* Restriction: only one NAPAUTHINFO */
  #define PRS_WAP_NAP_AUTHTYPE             29
  #define PRS_WAP_NAP_AUTHNAME             30
  #define PRS_WAP_NAP_AUTHSECRET           31
  #define PRS_WAP_NAP_AUTH_ENTITY          32
  #define PRS_WAP_NAP_SPI                  33
  /* VALIDITY */                               /* Restriction: only one VALIDITY */
  #define PRS_WAP_NAP_COUNTRY             -1
  #define PRS_WAP_NAP_NETWORK             -1
  #define PRS_WAP_NAP_SID                 -1
  #define PRS_WAP_NAP_SOC                 -1
  #define PRS_WAP_NAP_VALIDUNTIL          -1
#endif  /* WAP_SUPPORT */

/* BOOTSTRAP */
#define PRS_WAP_BOOTSTRAP_SIZE             2 
  #define PRS_WAP_BTS_NAME                 0
  #define PRS_WAP_BTS_NETWORK             -1
  #define PRS_WAP_BTS_COUNTRY             -1
  #define PRS_WAP_BTS_PROXY_ID             1
/*#define PRS_WAP_BTS_PROVURL             -1    * Restriction: no PROVURL */
/*#define PRS_WAP_BTS_CONTEXT_ALLOW       -1    * Restriction: no CONTEXT-ALLOW */

/* CLIENTIDENTITY */
#define PRS_WAP_CLIENTIDENTITY_SIZE        1      
  #define PRS_WAP_CID_CLIENT_ID            0

/* VENDORCONFIG */
#define PRS_WAP_VENDORCONFIG_SIZE          1    
  #define PRS_WAP_VDC_NAME                 0
                                               /* Restriction: no user defined entries  */


#ifdef WAP_SUPPORT
/* APPLICATION */
#define PRS_WAP_APPLICATION_SIZE           13
  #define PRS_WAP_APP_APPID                0
  #define PRS_WAP_APP_PROVIDER_ID          1
  #define PRS_WAP_APP_NAME                 2
  #define PRS_WAP_APP_AACCEPT              3
  #define PRS_WAP_APP_APROTOCOL            4
  #define PRS_WAP_APP_TO_PROXY             5
  #define PRS_WAP_APP_TO_NAPID             6
  #define PRS_WAP_APP_ADDR                 7
  /* IMPS */
  #define PRS_WAP_APP_SERVICES             8
  #define PRS_WAP_APP_CIDPREFIX            9
  /* SMTP */
  #define PRS_WAP_APP_FROM                 10
  #define PRS_WAP_APP_RT_ADDR              11
  /* SyncML-DM */
  #define PRS_WAP_APP_INIT                 12

/* APPADDR */
#define PRS_WAP_APPADDR_SIZE               4
  #define PRS_WAP_APP_ADDR2                0
  #define PRS_WAP_APP_ADDRTYPE             1
  #define PRS_WAP_APP_PORTNBR              2
  #define PRS_WAP_APP_SERVICE              3

/* APPAUTH */
#define PRS_WAP_APPAUTH_SIZE               5
  #define PRS_WAP_APP_AAUTHLEVEL           0
  #define PRS_WAP_APP_AAUTHTYPE            1
  #define PRS_WAP_APP_AAUTHNAME            2
  #define PRS_WAP_APP_AAUTHSECRET          3
  #define PRS_WAP_APP_AAUTHDATA            4

/* RESOURCE */
#define PRS_WAP_RESOURCE_SIZE              10
  #define PRS_WAP_APP_RES_URI              0
  #define PRS_WAP_APP_RES_NAME             1
  #define PRS_WAP_APP_RES_AACCEPT          2
  #define PRS_WAP_APP_RES_AAUTHTYPE        3
  #define PRS_WAP_APP_RES_AAUTHNAME        4
  #define PRS_WAP_APP_RES_AAUTHSECRET      5
  #define PRS_WAP_APP_RES_AAUTHDATA        6
  #define PRS_WAP_APP_RES_STARTPAGE        7
  /* SyncML-DS */
  #define PRS_WAP_APP_RES_CLIURI           8
  #define PRS_WAP_APP_RES_SYNCTYPE         9

#else   /* WAP_SUPPORT  */
/* APPLICATION */
#define PRS_WAP_APPLICATION_SIZE           24   
  #define PRS_WAP_APP_APPID                0
  #define PRS_WAP_APP_PROVIDER_ID          1
  #define PRS_WAP_APP_NAME                 2
  #define PRS_WAP_APP_AACCEPT              3
  #define PRS_WAP_APP_APROTOCOL            4
  #define PRS_WAP_APP_TO_PROXY             5
  #define PRS_WAP_APP_TO_NAPID             6
  #define PRS_WAP_APP_ADDR                 7
  /* APPADDR */                                /* Restriction: only one APPADDR */
  #define PRS_WAP_APP_ADDRTYPE             8
  /* PORT */                                   /* Restriction: only one PORT */
  #define PRS_WAP_APP_PORTNBR              9
  #define PRS_WAP_APP_SERVICE              10
  /* APPAUTH */                                /* Restriction: only one APPAUTH */
  #define PRS_WAP_APP_AAUTHLEVEL           11
  #define PRS_WAP_APP_AAUTHTYPE            12
  #define PRS_WAP_APP_AAUTHNAME            13
  #define PRS_WAP_APP_AAUTHSECRET          14
  #define PRS_WAP_APP_AAUTHDATA            15
  /* RESOURCE */                               /* Restriction: only one RESOURCE */
  #define PRS_WAP_APP_RES_URI              16
  #define PRS_WAP_APP_RES_NAME             17
  #define PRS_WAP_APP_RES_AACCEPT          18
  #define PRS_WAP_APP_RES_AAUTHTYPE        19
  #define PRS_WAP_APP_RES_AAUTHNAME        20
  #define PRS_WAP_APP_RES_AAUTHSECRET      21
  #define PRS_WAP_APP_RES_AAUTHDATA        22
  #define PRS_WAP_APP_RES_STARTPAGE        23
#endif  /* WAP_SUPPORT  */


/* ACCESS */
#define PRS_WAP_ACCESS_SIZE                6
  #define PRS_WAP_ACC_RULE                 0
  #define PRS_WAP_ACC_APPID                1
  #define PRS_WAP_ACC_PORTNBR              2
  #define PRS_WAP_ACC_DOMAIN               3
  #define PRS_WAP_ACC_TO_NAPID             4
  #define PRS_WAP_ACC_TO_PROXY             5

#ifdef MTK_TMP_PATCH /* CR27923 */
#ifdef PRS_CONFIG_DMP_SUPPORT
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  /* PRS_CONFIG_DMP_SUPPORT */

/* OMA Extension */
/* WLAN */
#define PRS_WAP_WLAN_SIZE                   13
  #define PRS_WAP_WLAN_PRI_SSID             0
  #define PRS_WAP_WLAN_PRI_U_SSID           1
  #define PRS_WAP_WLAN_PRI_H_SSID           2
  #define PRS_WAP_WLAN_NETMODE              3
  #define PRS_WAP_WLAN_SECMODE              4
  #define PRS_WAP_WLAN_WPA_PRES_KEY_ASC     5
  #define PRS_WAP_WLAN_WPA_PRES_KEY_HEX     6
  #define PRS_WAP_WLAN_WEPKEYIND            7
  #define PRS_WAP_WLAN_WEPAUTHMODE          8
  #define PRS_WAP_WLAN_WLANHAND             9
  #define PRS_WAP_WLAN_EDIT_SET             10
  #define PRS_WAP_WLAN_VIEW_SET             11
  #define PRS_WAP_WLAN_FORW_SET             12

/* SEC-SSID */
#define PRS_WAP_SEC_SSID_SIZE               2
  #define PRS_WAP_SEC_SSID_S_SSID           0
  #define PRS_WAP_SEC_SSID_S_U_SSID         1

/* EAP */
#define PRS_WAP_EAP_SIZE                    14
  #define PRS_WAP_EAP_EAPTYPE               0
  #define PRS_WAP_EAP_USERNAME              1
  #define PRS_WAP_EAP_PASSWORD              2
  #define PRS_WAP_EAP_REALM                 3
  #define PRS_WAP_EAP_USE_PSEUD             4
  #define PRS_WAP_EAP_MAXAUTHS              5
  #define PRS_WAP_EAP_ENCAPS                6
  #define PRS_WAP_EAP_VER_SER_REALM         7
  #define PRS_WAP_EAP_CLIENT_AUTH           8
  #define PRS_WAP_EAP_SES_VAL_TIME          9
  #define PRS_WAP_EAP_CIP_SUIT              10
  #define PRS_WAP_EAP_PEAP_V0               11
  #define PRS_WAP_EAP_PEAP_V1               12
  #define PRS_WAP_EAP_PEAP_V2               13

/* CERT */
#define PRS_WAP_CERT_SIZE                   6
  #define PRS_WAP_CERT_ISS_NAME             0
  #define PRS_WAP_CERT_SUB_NAME             1
  #define PRS_WAP_CERT_CERT_TYPE            2
  #define PRS_WAP_CERT_SER_NUM              3
  #define PRS_WAP_CERT_SUB_KEY_ID           4
  #define PRS_WAP_CERT_THUMBPRINT           5

/* WEPKEY */
#define PRS_WAP_WEPKEY_SIZE                 3
  #define PRS_WAP_WEPKEY_LENGTH             0
  #define PRS_WAP_WEPKEY_INDEX              1
  #define PRS_WAP_WEPKEY_DATA               2
#endif  /* MTK_TMP_PATCH CR27923 */



/*************************************
 * Default values
 *************************************/

/* PXADDRTYPE */
#define PRS_WAP_DEFAULT_PXADDRTYPE         PRS_VAL_WAP_IPV4

/* NAP-ADDRTYPE */
#define PRS_WAP_DEFAULT_NAP_ADDRTYPE       PRS_VAL_WAP_E164

/* CALLTYPE */
#define PRS_WAP_DEFAULT_CALLTYPE           PRS_VAL_WAP_ANALOG_MODEM

/* LOCAL-ADDRTYPE */
#define PRS_WAP_DEFAULT_LOCAL_ADDRTYPE     PRS_VAL_WAP_IPV6

/* PORT*/
#define PRS_WAP_DEFAULT_PORT               "9201"



/**********************************************************************/
/*                          IOTA Provisioning                         */
/**********************************************************************/

/*************************************
 * Definition tables
 *************************************/

 
/*************************************
 * Function defines
 *************************************/


/*************************************
 * Element support defines
 *************************************/


#endif


