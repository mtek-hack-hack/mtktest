/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
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
 * bra_cfg.h
 *
 * Created by: Mats Tedenvall
 *
 * Revision history:
 *	20020709	PA1		MTV		First Revision	
 *
 */
#ifndef _bra_cfg_h
#define _bra_cfg_h

#ifndef _msf_cfg_h
#include "msf_cfg.h"
#endif

#ifndef _msf_mem_h
#include "msf_mem.h"
#endif

#ifndef _bra_str_h
#include "bra_str.h"
#endif

#ifndef _CUSTOM_WAP_CONFIG_H
#include "custom_wap_config.h"
#endif

/*Memory macros used in the BRA module*/
#define BRA_ALLOC(s)      MSF_MEM_ALLOC(MSF_MODID_BRA,s)
#define BRA_ALLOCTYPE(t)  MSF_MEM_ALLOCTYPE(MSF_MODID_BRA,t)
#define BRA_FREE(p)       MSF_MEM_FREE(MSF_MODID_BRA,p)
#define BRA_UNUSED(p)     ((void)(p))




/*------------------------------compile option-----------------------------------------*/



#ifdef WAP2
//#define BRA_CONFIG_HTTP
#define BRA_CONFIG_HTTP_EXT
#endif

#define BRA_USE_CTK_INLINE
#define BRA_CFG_USE_SPLASH


#if defined(BRA_CONFIG_HTTP) || defined(BRA_CONFIG_HTTP_EXT)
  #ifndef BRA_USE_CTK_INLINE
    #define BRA_USE_CTK_INLINE
  #endif
#endif

#ifdef MMS_SUPPORT
#define BRA_CONFIG_MMS
#endif

#ifdef WAP_SEC_SUPPORT
#define BRA_CONFIG_SECURITY
#endif

#define BRA_CONFIG_PUSH
#ifdef BRA_CONFIG_PUSH
#define BRA_CONFIG_UIS_PUSH_SL
#endif

#if defined (BRA_CONFIG_PUSH) && defined (__UNIFIED_MSG_SUPPORT__)
#define BRA_CONFIG_DOUBLE_PUSH_BOX
#endif

#if defined(BRA_CONFIG_PUSH) && (MSF_CFG_PUSH_ADDRESS_OPTION == 2)
#define BRA_CONFIG_PUSH_TRUSTLIST
#endif

#define BRA_CONFIG_PROVISIONING
#define BRA_CFG_SELECT_MODE


#if defined (__MMI_CCA_SUPPORT__) && defined (BRA_CONFIG_PROVISIONING) && defined (BRA_USE_CTK_INLINE)
#define BRA_CFG_CCA
#endif 

#if defined (SYNCML_DM_SUPPORT) && defined (BRA_CFG_CCA)
#define BRA_CFG_DM
#endif


#if defined(__PS_SERVICE__) && defined(__CS_SERVICE__)
//  #define BRA_CFG_PROF_FALLBACK
//  #define BRA_CFG_PROV_MULTI_BEARER
#endif

#if defined(BRA_CFG_PROV_MULTI_BEARER) && !defined(BRA_CFG_PROF_FALLBACK)
#error BRA_CFG_PROV_MULTI_BEARER must be defined with BRA_CFG_PROF_FALLBACK
#endif

#if defined(MMS_CFG_FALLBACK_SUPPORT) && !defined(BRA_CFG_PROF_FALLBACK)
#error MMS_CFG_FALLBACK_SUPPORT must be defined with BRA_CFG_PROF_FALLBACK
#endif

#define BRA_CFG_CANCEL_PROV_CONF

#define BRA_CFG_PROMPT_CSD_ERROR_CAUSE
/* Define this constant to enable offline pages */
/* NOTE! BRS_CFG_OFFLINE_PAGES in brs_cfg.h must be defined */
#define BRA_CFG_OFFLINE_PAGES

#define BRA_CFG_ENABLE_FILE_SCHEME

/* This define is used to enable some menu option useful for testing*/
/*#define BRA_CONFIG_TEST*/


/*Define this constant to use the common data account select screen*/
#ifdef  BRA_USE_CTK_INLINE 
#define BRA_CFG_USE_DTCNT_SELECT_SCREEN   
#endif



#if defined(BRA_USE_CTK_INLINE) && defined(__MMI_DUAL_SIM__) 
#define BRA_CFG_DUAL_SIM   
#endif

#if defined(BRA_CFG_DUAL_SIM) && defined (__MMS_DUAL_SIM_SUPPORT__)
#define BRA_CFG_DUAL_SIM_FOR_MMS 
#endif

#if defined(BRA_USE_CTK_INLINE) && defined (__CBM_ALWAYS_ASK_FEATURE__)
#define BRA_CFG_CONN_ALWAYS_ASK
#endif




/*------------------------------constant-----------------------------------------*/






#ifdef BRA_CFG_USE_SPLASH
#define BRA_CFG_SPLASH_TIME               40
#endif

#define BRA_CFG_DISPLAY_TITLE                                   /*Define this if the content title should be displayed in viewport*/

#define BRA_CFG_CONTENT_SCHEME            "http,https"        

#define BRA_CFG_URL_DEFAULT_SCHEME        BRA_STR_HTTP_URL      /*Define the default scheme used in url input "http://"*/

#define BRA_CFG_N_ADDRESS_ITEMS           10                    /*Number of addresses in "Enter Address" list*/

#define BRA_CFG_HISTORY_FILE_PATH         "/bra/history.dat"    /*Path to History file*/

#define BRA_CFG_MAX_RPL_ITEMS             10/*20*/

#define BRA_CFG_RECENT_LIST_FILE_PATH     "/BRA/History2.dat"    /*Path to History2 file*/

#define BRA_CFG_BOOKMARK_FILE_PATH        "/bra/bkm.dat"        /*Path to bookmarks file*/

#define BRA_CFG_BMK_BUFFER_SIZE           512                   /*Number of bytes to be read/written in each file operation*/

#define BRA_CFG_MAX_NBR_BOOKMARKS         (wap_custom_get_max_bookmark_num())/*20*//*100*/                   /*Maximum number of bookmarks, MAX < MAX_INT_16*/

#define	BRA_CFG_MAX_NBR_CHARS_URL	        0xFF/*0x80*/                  /*Max length of url string, MAX < BRA_CFG_BMK_BUFFER_SIZE - BRA_CFG_MAX_NBR_CHARS_TITLE*/
#define	BRA_CFG_MAX_NBR_CHARS_TITLE	      0x28                  /*Max length of title string, MAX < MAX_UINT_8*/                                                              

#define BRA_CFG_MAX_NBR_PX_AUTH_NAME       30                   /*Max length of proxy auth name*/
#define BRA_CFG_MAX_NBR_PX_AUTH_PWD        30                   /*Max length of proxy auth password*/



#ifdef BRA_CFG_DUAL_SIM
#define BRA_CFG_MAX_SIM_NUM                 (2)
#endif


#define BRA_CFG_MAX_CACHE_SIZE            (wap_custom_get_max_cache_size())/*20000*//*2000000*/               /*Max Cache size*/


/*Profiles specific*/
#define BRA_CFG_N_WAP_PROFILES            (wap_custom_get_max_wap_prof_num())
#define BRA_CFG_N_MMS_PROFILES            (wap_custom_get_max_mms_prof_num())
#define BRA_CFG_N_PROFILES                (BRA_CFG_N_WAP_PROFILES + BRA_CFG_N_MMS_PROFILES)                    /*Numbere of profiles availabe*/

#ifdef BRA_CFG_DUAL_SIM
#define BRA_CFG_N_ALL_SIM_PROFILES        (BRA_CFG_N_PROFILES * BRA_CFG_MAX_SIM_NUM)
#else
#define BRA_CFG_N_ALL_SIM_PROFILES          BRA_CFG_N_PROFILES
#endif

#define BRA_CFG_PROFILE_FILE_PATH         "/bra/profiles.dat"   /*Path to profile file*/

#ifdef BRA_CFG_PROF_FALLBACK
#define BRA_CFG_PROF_DEFAULT_NET_ID_DUAL  0  // 0: no dual bearer (ie, NET_ID in effect)
                                             // 1: dual bearer (NET_ID_GPRS and NET_ID_GSM stores data acct ids, NET_ID=currently used id)
#define BRA_CFG_PROF_DEFAULT_NET_ID_GPRS  10 //(wap_custom_get_max_wap_prof_num()-1)                     /*Default profile values*/
#define BRA_CFG_PROF_DEFAULT_NET_ID_GSM   0
#define BRA_CFG_PROF_DEFAULT_NET_ID       BRA_CFG_PROF_DEFAULT_NET_ID_GPRS
#else
#define BRA_CFG_PROF_DEFAULT_NET_ID       10 //(wap_custom_get_max_wap_prof_num()-1)                     /*Default profile values*/
#endif

#define BRA_CFG_PROF_DEFAULT_HISTSIZE     10
#ifdef __OP01_WAP_DATACFG__
#undef BRA_CFG_PROF_DEFAULT_HISTSIZE
#define	BRA_CFG_PROF_DEFAULT_HISTSIZE     21
#endif

#define BRA_CFG_PROF_DEFAULT_REFRESH      1
#define BRA_CFG_PROF_DEFAULT_USE_CSS      1
#define BRA_CFG_PROF_DEFAULT_CON_TYPE     3                     /*HTTP = 1; WSP_CL = 2; WSP_CO = 3*/
#define BRA_CFG_PROF_DEFAULT_PRX_ADDR     ""
#define BRA_CFG_PROF_DEFAULT_PRX_PORT     0
#define BRA_CFG_PROF_DEFAULT_PRX_UID      NULL
#define BRA_CFG_PROF_DEFAULT_PRX_PWD      NULL
#define BRA_CFG_PROF_DEFAULT_PRX_RLM      NULL
#define BRA_CFG_PROF_DEFAULT_LDNOMIME     1/*0 ask, 1 load, 2 don't load*/
#define BRA_CFG_PROF_DEFAULT_IMODE_UA     NULL
#define BRA_CFG_PROF_DEFAULT_SYLESHEET    NULL
#define BRA_CFG_PROF_DEFAULT_CACHESIZE    BRA_CFG_MAX_CACHE_SIZE
#define BRA_CFG_PROF_DEFAULT_USE_CACHE    1
#define BRA_CFG_PROF_DEFAULT_COOKIES      1
#define BRA_CFG_PROF_DEFAULT_UA_HEADER    ((char*)wap_custom_get_ua_header()) //"MAUI WAP Browser"
#define BRA_CFG_PROF_DEFAULT_UA_PROF      ((char*)wap_custom_get_ua_prof_url())/*"http://210.61.82.71/uaprof/Cannon_R100.xml"*/
#define BRA_CFG_PROF_DEFAULT_MMS_UA_HEADER ((char*)wap_custom_get_mms_user_agent()) //"MediaTek Maui MMS Agent"
#define BRA_CFG_PROF_DEFAULT_INLINE_DO    0

#ifdef BRA_CONFIG_UIS_PUSH_SL
#define BRA_CFG_PROF_DEFAULT_LOAD_SL      0                 
#endif
#ifdef BRA_CONFIG_PUSH
#define BRA_CFG_PROF_DEFAULT_PUSH_SECURITY        0
#define BRA_CFG_PROF_DEFAULT_PUSH_C_TYPE          2
#define BRA_CFG_PROF_DEFAULT_PUSH_NET_ID          1
#endif

#define BRA_CFG_DEFAULT_HOMPAGE_TITLE     BRA_STR_HOMEPAGE      /*Default homepage title*/
#define BRA_CFG_DEFAULT_HOMPAGE_URL       "http://"             /*Default homepage url*/

#define BRA_CFG_DEFAULT_BRS_TIMEOUT       90
#define BRA_CFG_DEFAULT_TIMEOUT           wap_custom_get_default_browse_timeout()/*45*/
#define BRA_CFG_DEFAULT_OBJ_LOAD          "image/*,audio/amr,audio/imelody,audio/mid,audio/wav" /* Cannot contain space character */
#define BRA_CFG_DEFAULT_OBJ_ASK           NULL
#define BRA_CFG_DEFAULT_PUSH_ON           (wap_custom_get_set_push_enable_push())
#define BRA_CFG_DEFAULT_PUSH_TRUSTSETTING (wap_custom_get_set_push_trust_setting())
#define BRA_CFG_DEFAULT_PUSH_SLSETTING    (wap_custom_get_set_push_SL_setting())

#define BRA_CFG_TRUSTLIST_FILE_PATH        "/bra/trustList.dat"        /*Path to trust list file*/

#define BRA_CFG_PROF_INITIAL_SIZE         WAP_CUSTOM_CFG_PROFILE_FILE_SIZE
#define BRA_CFG_BKM_INITIAL_SIZE          WAP_CUSTOM_CFG_BOOKMARK_FILE_SIZE
#define BRA_CFG_RPL_INITIAL_SIZE          2000
#define BRA_CFG_HIST_INITIAL_SIZE         2000
#endif


/* the max number of the data account which belong to the same bearer, such as GPRS,
   if customer want to enlarge the number of the data account of one bearer, 
   please enlarge this constant to: 
   MAX(custom_get_csd_profile_num(), custom_get_csd_profile_num()) */ 

#define  BRA_CFG_ONE_BEARER_MAX_NET_ID_NUM  (10)   





