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

/*******************************************************************************
 * Filename:
 * ---------
 * JProvWap.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is common file for OMA & NE OTA provisioning settings.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _JPROVWAP_H
#define _JPROVWAP_H

#include "MMI_features.h"
#if defined (JATAAYU_SUPPORT)

#include <ddl.h>
#include <jcal.h>
#include <jdi_XML.h>
#include <jdi_WBXML.h>
#include <xmltag.h>
#include "stdC.h"
#include "L4Dr1.h"
#include "MMIDataType.h"

#include "custom_nvram_editor_data_item.h"
#include "ucs2prot.h"
#include "KeyBrd.h"
#include "IdleAppProt.h"
#include "DataAccountCommon.h"
#include "CommonScreens.h"
#include "wgui_categories_popup.h"
#include "GlobalDefs.h"
#include "ProtocolEvents.h"
#include "settingprofile.h"
#include "wap_ps_struct.h"
#include "JProvisioningResDef.h"
#include "JProvProts.h"

#include "l4a.h"

typedef S8 PROV_RETCODE;

#define  PROV_BRS_SETTINGS             (0x01)
#define  PROV_MMS_SETTINGS             (0x02)

extern U8 g_prov_pend_set;
extern U8 *g_prov_profile_name_p;
extern U16 g_prov_newsetting_stringID;

typedef enum
{
    PROV_OK,
    PROV_BKM_FULL,
    PROV_BKM_INVALID,
    PROV_BKM_OK,
    PROV_SETTING_SKIPPED,
    PROV_MEM_FULL,
    PROV_ERR,
    PROV_ERR_UNSUPPORTED_SETTING
} prov_ret_code_enum;

#define PROV_PROFILE_PROFILE_NAME_LEN     (NVRAM_WAP_PROFILE_PROFILE_NAME_LEN)
#define PROV_PROFILE_HOMEPAGE_URL_LEN     (NVRAM_WAP_PROFILE_HOMEPAGE_URL_LEN)
#define PROV_PROFILE_MMSC_URL_LEN         (NVRAM_MMS_PROFILE_MMSC_URL_LEN)
#define PROV_PROFILE_USERNAME_LEN         (NVRAM_WAP_PROFILE_USERNAME_LEN)
#define PROV_PROFILE_PASSWORD_LEN         (NVRAM_WAP_PROFILE_PASSWORD_LEN)
#define PROV_BKM_TITLE_LEN             (NVRAM_BRW_BKM_MAX_TITLE_LENGTH)
#define PROV_BKM_URL_LEN               (NVRAM_BRW_BKM_MAX_URL_LENGTH)
#define PROV_IP_PART_MAX_VALUE            (255)

#ifndef __MMI_JATAAYU_CCA_SUPPORT__

#define TEXT_VND_WAP_CONNECTIVITY_XML           "text/vnd.wap.connectivity-xml" /* Presently not supported */
#define APPLICATION_VND_WAP_CONNECTIVITY_WBXML     "application/vnd.wap.connectivity-wbxml"

/* Defines the content type used for Nokia\Ericsson provisioning. */
// #define TEXT_X_WAP_PROV_BROWSER_SETTINGS                     "text/x-wap-prov.browser-settings"/*Presently not supported*/
#define APPLICATION_X_WAP_PROV_BROWSER_SETTINGS    "application/x-wap-prov.browser-settings"

// #define TEXT_X_WAP_PROV_BROWSER_BOOKMARKS                    "text/x-wap-prov.browser-bookmarks"/*Presently not supported*/
#define APPLICATION_X_WAP_PROV_BROWSER_BOOKMARKS   "application/x-wap-prov.browser-bookmarks"

#define WSP_PUSH_HEADER             (0x06)

#define PARM      "parm"
#define NAME      "name"
#define PROV_VALUE     "value"
#define TYPE      "type"
#define PAP       "PAP"
#define CHAP      "CHAP"

#define PROV_MAX_NBR_DOCUMENTS            (5)
#define PROV_MAX_NBR_BRS_PROFILE       (NVRAM_WAP_PROFILE_MAX)
#define PROV_MAX_NBR_MMS_PROFILE       (NVRAM_MMS_PROFILE_MAX

#define PROV_MAX_QUE_SIZE_TIMEOUT         (1000)
#define PROV_INV_BEARER_TIMEOUT           (1000)
#define PROV_INVALID_SETTINGS_TIMEOUT     (1000)
#define PROV_DATA_ACCOUNT_NOTIFY_TIMEOUT  (1000)
#define PROV_AUTHENTICATION_DONE_TIMEOUT  (1000)

#define PROV_MAX_GPRS_DATAACCOUNT_NAME    (MAX_GPRS_DATAACCOUNT_NAME)
#define PROV_MAX_GPRS_USERPASSWD       (MAX_GPRS_USERPASSWD)
#define PROV_MAX_GPRS_USERNAME            (MAX_GPRS_USERNAME)
#define PROV_MAX_GPRS_MMI_APN_LEN         (MAX_GPRS_MMI_APN_LEN)

#define PROV_MAX_DATA_ACCOUNT_NAME_LEN    (MAX_DATA_ACCOUNT_NAME_LEN)
#define PROV_MAX_USER_LEN              (MAX_USER_LEN)
#define PROV_MAX_PASSWD_LEN               (MAX_PASSWD_LEN)
#define PROV_MAX_DIAL_NUM_LEN          (MAX_DIAL_NUM_LEN - 1)   /* As the screen allow only 20 chars to input */

#define PROV_TAG_NAME_MAX_LENGHT       (30)

#define PROV_MIN_SIZE_REQ              (64)

#define  PROV_BOOKMARK_SETTINGS           (0x04)
#define  PROV_NOKIA_SETTINGS              (0x08)
#define  PROV_OMA_SETTINGS             (0x10)

#define PROV_DEFAULT_HTTP_PORT            (8080)

typedef enum
{
    PROV_GPRS_BEARER,
    PROV_CSD_BEARER,
    PROV_INVALID_BEARER
} prov_bearer_enum;

/* dara will be removed start */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
typedef enum
{
    PROV_AUTHTYPE_PAP,
    PROV_AUTHTYPE_CHAP
} prov_nap_authtype_enum;

typedef enum
{
    PROV_CONN_TYPE_HTTP = 1,
    PROV_CONN_TYPE_CO,
    PROV_CONN_TYPE_CO_SEC
} prov_conn_type_enum;

typedef struct
{
    S8 *pbuffer;
    U32 plength;
    U16 instal_stringID;
} prov_queue_data_struct;

typedef struct
{
    S8 characteristic_tags[PROV_TAG_NAME_MAX_LENGHT];
      PROV_RETCODE(*characteristic_tag_hdlr) (TAG **next_node);
} characteristic_tag_handler_struct;

/*****************************************************************************/
extern ETaskID g_activated_task_id;
extern S8 g_prov_data_queue_size;
extern U8 g_prov_bearer;
extern U8 g_prov_setting_type;
extern U8 g_prov_appl_flag;
extern FuncPtr g_prov_timeout_hdlr;
extern mmi_cc_set_csd_profile_req_struct *g_prov_set_csd_req_p;

#ifdef __MMI_GPRS_FEATURES__
extern mmi_ps_set_gprs_data_account_req_struct *g_prov_set_gprs_req_p;
#endif 

extern pBOOL isInCall(void);

#endif /* __MMI_JATAAYU_CCA_SUPPORT__ */ 
#endif /* defined (JATAAYU_SUPPORT) */ // #if defined (JATAAYU_SUPPORT)
#endif /* _JPROVWAP_H */ 

