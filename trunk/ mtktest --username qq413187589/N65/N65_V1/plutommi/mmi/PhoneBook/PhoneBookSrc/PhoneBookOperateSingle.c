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

/*****************************************************************************
 *
 * Filename:
 * ---------
 * PhoneBookOperateSingle.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for phonebook single entry operation.
 *   Such as Add, Delete, Edit.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifndef _PHONEBOOKOPERATESINGLE_C
#define _PHONEBOOKOPERATESINGLE_C

#include "ProtocolEvents.h"
#include "Thrdosinterface.h"
#include "PhonebookDef.h"
#include "PhoneBookTypes.h"
#include "PhonebookProt.h"
#include "PhonebookGprot.h"
#include "mainmenudef.h"
#include "SettingGprots.h"
#include "SettingDefs.h"        /* For FDN on Message */
#include "SettingsGdcl.h"
#include "CommonScreens.h"
#include "datetimetype.h"
#include "app_datetime.h"
#include "SimDetectionDef.h"
#include "MessagesExDcl.h"
#include "CallManagementGProt.h"
#include "OutgoingCallHelperProt.h"

#if defined(__MMI_FILE_MANAGER__)
#include "FileManagerDef.h"     /* error string id */
#endif 

#include "FileMgr.h"    /* Should include FileMgr.h before ProfileMgrGprot.h */
#include "FileManagerGProt.h"

#if defined(__MMI_PROFILE_EXTMELODY_SUPPORT__)
#include "ProfileMgrGProt.h"
#endif 

#if defined(__MMI_VRSD_DIAL__)
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "VRSDDial.h"
#endif /* defined(__MMI_VRSD_DIAL__) */ 

#if defined(__MMI_VRSI__)
#include "Mdi_datatype.h"
#include "VRSIResDef.h"
#include "VRSIType.h"
#include "VRSIProt.h"
#endif /* defined(__MMI_VRSI__) */ 

#ifdef __J2ME__
#include "j2me_custom_option.h"
#endif
#if defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC)
#include "PhoneBookJavaHandler.h"
#endif 

#if defined(__MMI_INCOMING_CALL_VIDEO__)
#include "DataMgr.h"
#include "VdoPlyGProt.h"
#include "VdoPlyResDef.h"		/* Video Player String ID Enum */
#include "Mdi_datatype.h"
#endif /* defined(__MMI_INCOMING_CALL_VIDEO__) */ 

#if defined(__MMI_VCARD__)
#include "vObjects.h"
#endif /* defined(__MMI_VCARD__) */ 

#include "SimDetectionGprot.h"  /* for mmi_bootup_get_active_flight_mode */
#ifdef __MMI_PHB_SEND_SMS_FROM_PHB__
#include "MessagesMiscell.h"    /* for IsMessagesReEntering */
#include "MessagesResourceData.h"       /* for STR_SMS_MSG_NOT_READY_YET */
#include "SMSApi.h"
#endif /* __MMI_PHB_SEND_SMS_FROM_PHB__ */ 

#if defined(__MMI_PHB_SEND_MMS_FROM_PHB__)
#include "Wapadp.h"
#endif /* defined(__MMI_PHB_SEND_MMS_FROM_PHB__) */

#if defined(__MMI_TOUCH_SCREEN__)
#endif

#if defined(JATAAYU_SUPPORT) && defined(WAP_SUPPORT)
#include "ddl.h"
#include "jcutils.h"
#include "jcerror.h"
#endif /* defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT) */ 

#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#endif

#ifdef __SYNCML_SUPPORT__
#include "SyncMLDef.h"
#include "SyncMLGProt.h"
#endif /* __SYNCML_SUPPORT__ */

#if defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__)
#include "DownloadDefs.h"
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */

#if defined(__MMI_PHB_UPDATE_CALL_LOG_AFTER_SAVE__)     /* Update Call Log after save number */
#include "CallHistoryGProts.h"
#endif /* defined(__MMI_PHB_UPDATE_CALL_LOG_AFTER_SAVE__) */

#if defined(__MMI_AVATAR__)
#include "AvatarGProt.h"
#endif

#if defined(__MMI_BPP_SUPPORT__)
#include "Conversions.h" /* for value buffer conversion */
#include "mdi_datatype.h"
#include "BTMMICm.h"
#include "BTMMIBppGprot.h"
#include "BTMMIBppXhtmlGprot.h"
#endif /* defined(__MMI_BPP_SUPPORT__) */

#ifdef __DRM_SUPPORT__
#include "drm_gprot.h"
#endif

#if defined(__MMI_UCM__)
#include "UCMGprot.h"
#endif

#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_PFAL_Master_ADN.h"
#include "MTPNP_AD_resdef.h"
#include "MTPNP_PFAL_CC.h"
#endif	/* __MMI_DUAL_SIM_MASTER__ */

/*
 * Type Define
 */

#if defined(__MMI_BPP_SUPPORT__)
#define PHB_BPP_FIELD_TITLE_BUFFER_LENGTH 60
#define PHB_BPP_FIELD_VALUE_BUFFER_LENGTH 160
#endif

/*
 * Local Variable
 */

U8 gRingtoneItemIndex;
U8 *myCallerGrpnames[MAX_PB_CALLER_GROUPS + 1];
pBOOL viewOnce = FALSE;

static BOOL copyEntry = FALSE;
static BOOL moveEntry = FALSE;
static BOOL duplicateEntry = FALSE;
static U16 moveEntryStoreIndex;
static U8 moveModified = 0;

#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
static BOOL bday_modified;
static U16 bday_inline_index;
#endif /* defined(__MMI_PHB_BIRTHDAY_FIELD__) */ 

#if defined(__MMI_FILE_MANAGER__)
#ifdef __MTK_TARGET__
__align(2) S8 g_phb_file_path[FMGR_MAX_PATH_LEN * ENCODING_LENGTH + ENCODING_LENGTH];      /* Select file from file manager */
#else
S8 g_phb_file_path[FMGR_MAX_PATH_LEN * ENCODING_LENGTH + ENCODING_LENGTH];      /* Select file from file manager */
#endif
extern S8 nPrintableStr[];  /* Temp global buffer for convert name */
#ifdef __MMI_AVATAR__
BOOL g_phb_avatar_image_view = FALSE;
#endif
#endif /* defined(__MMI_FILE_MANAGER__) */ 

#if defined(__MMI_INCOMING_CALL_VIDEO__)
U8 g_phb_video_item_index = 0xff;
#ifdef __MTK_TARGET__
__align(2) S8 g_phb_video_file_path[FMGR_MAX_PATH_LEN * ENCODING_LENGTH + ENCODING_LENGTH];        /* Select file from file manager */
#else
S8 g_phb_video_file_path[FMGR_MAX_PATH_LEN * ENCODING_LENGTH + ENCODING_LENGTH];        /* Select file from file manager */
#endif
static S8 *phb_video_tmp_file_path = NULL;
static FuncPtr phb_video_endkey_handler = NULL;
BOOL g_phb_video_view = FALSE;
#ifdef __MMI_SWFLASH__
BOOL g_phb_swflash_view = FALSE;
#endif
#ifdef __MMI_AVATAR__
BOOL g_phb_avatar_video_view = FALSE;
#endif
static mmi_data_record_store_type g_phb_video_record_store; /* Video Path Object */
#ifdef __MTK_TARGET__
__align(2) static S8 phb_caller_video_file_path[FMGR_MAX_PATH_LEN * ENCODING_LENGTH + ENCODING_LENGTH];    /* caller video */
#else
static S8 phb_caller_video_file_path[FMGR_MAX_PATH_LEN * ENCODING_LENGTH + ENCODING_LENGTH];    /* caller video */
#endif
#endif /* defined(__MMI_INCOMING_CALL_VIDEO__) */ 
#if defined(__MMI_PHB_IMPS_FIELD__)
U8 phb_imps_item_index = 0xff;
#endif 
#ifdef __MMI_VOIP__
static U8 phb_add_entry_history_data[1100];
#endif

U16 g_phb_image_type_id;

#if defined(__MMI_BPP_SUPPORT__)
typedef enum
{
    MMI_PHB_BPP_N,
    MMI_PHB_BPP_TEL_CELL,
    MMI_PHB_BPP_TEL_HOME,
    MMI_PHB_BPP_TEL_WORK,
    MMI_PHB_BPP_TEL_FAX,
    MMI_PHB_BPP_EMAIL,
    MMI_PHB_BPP_ORG,
    MMI_PHB_BPP_BDAY,
    MMI_PHB_BPP_TITLE,
    MMI_PHB_BPP_URL,                    
    MMI_PHB_BPP_NOTE,
    MMI_PHB_BPP_ADR,
    MMI_PHB_BPP_VOIP,
    MMI_PHB_BPP_IMPS,
    MMI_PHB_BPP_FIELD_TOTAL
} mmi_phb_bpp_field_enum;

const S8 *g_phb_bpp_field[MMI_PHB_BPP_FIELD_TOTAL] = 
{
    "Name",
    "Cell Number",
    "Home Number",
    "Office Number",
    "Fax Number",
    "Email Address",
    "Company Name",
    "Birthday",
    "Title",
    "Url",
    "Note",
    "Address",
    "Voip",
    "Imps",
};
#endif /* defined(__MMI_BPP_SUPPORT__) */

/*
 * Global Variable
 */
#if defined(__MMI_TOUCH_SCREEN__)
const UI_character_type mmi_phb_e_mail_allowed[] = L"+_\\-.@A-Za-z0-9";
#endif
extern U16 PhoneBookEntryCount;
extern S8 pbName[];
extern S8 pbNumber[];
#if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) || defined(__MMI_PHB_USIM_FIELD__)
extern S8 pbHomeNumber[];
extern S8 pbCompanyName[];
extern S8 pbEmailAddress[];
extern S8 pbOfficeNumber[];
extern S8 pbFaxNumber[];
#endif /* !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) || defined(__MMI_PHB_USIM_FIELD__) */

#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
extern S8 pbBday[];
extern S8 pbDay[];
extern S8 pbMon[];
extern S8 pbYear[];
#endif /* defined(__MMI_PHB_BIRTHDAY_FIELD__) */ 

#if defined(__MMI_INCOMING_CALL_VIDEO__)
extern pBOOL IsSilentModeActivated(void);
#endif 

#if defined(__MMI_PHB_INFO_FIELD__)
extern PHB_INFO_FIELDS_STRUCT PhoneBookInfoFields;
extern S8 pbTitle[];
extern S8 pbUrl[];
extern S8 pbAddress[];
extern S8 pbNote[];
#endif /* defined(__MMI_PHB_INFO_FIELD__) */ 
#if defined(__MMI_PHB_IMPS_FIELD__)
extern S8 PhoneBookImpsField[];
extern S8 pbImps[];
#endif /* defined(__MMI_PHB_IMPS_FIELD__) */ 

#if defined(__MMI_VOIP__)
extern S8 PhoneBookVoipField[VOIP_URI_LEN];
extern S8 pbVoip[(VOIP_URI_LEN) * ENCODING_LENGTH];
#endif /* defined(__MMI_VOIP__) */ 

#ifdef __MMI_PHB_USIM_FIELD__
extern S8 pbNickName[];
extern MMI_PHB_EMAIL_STRUCT phb_email[];
#endif /* __MMI_PHB_USIM_FIELD__ */ 

extern MMI_PHB_ENTRY_BCD_STRUCT PhoneBook[];

extern wgui_inline_item wgui_inline_items[];
extern U8 gPictureItemIndex;

#if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
extern PHB_OPTIONAL_FIELDS_STRUCT PhoneBookOptionalFields;
#endif 

extern U16 TitleStrings[];
extern U16 g_phb_name_index[];
extern U8 g_phb_enter_from;

#if defined(__MMI_PHB_EMAIL_SORT__)
U8 g_phb_email_sorted = 0;
#endif 
#if defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT)
extern void mmi_jdd_tapi_get_phb_name_number(PS8 name, PS8 number, U8 storage);
#endif

#if defined(__MMI_INCOMING_CALL_VIDEO__)
#if defined(__MMI_SWFLASH__) && defined(__MMI_AVATAR__)
U8 g_phb_swflash_video_minus = 3;
U8 g_phb_avatar_video_minus = 2;
#elif defined(__MMI_SWFLASH__) /* defined(__MMI_SWFLASH__) && defined(__MMI_AVATAR__) */
U8 g_phb_swflash_video_minus = 2;
#elif defined(__MMI_AVATAR__)
U8 g_phb_avatar_video_minus = 2;
#endif /* defined(__MMI_SWFLASH__) && defined(__MMI_AVATAR__) */
#endif /* defined(__MMI_INCOMING_CALL_VIDEO__) */

/*
 * Global Function
 */
#if defined(__IP_NUMBER__)
extern void SetTempUseIPNumber(pBOOL flag);
#endif

#if defined(__MMI_BARCODEREADER__) || defined(__MMI_BROWSER_2__)
extern mmi_phb_save_entry_from_others_callback_type mmi_phb_add_new_entry_callback;
#endif /* defined(__MMI_BARCODEREADER__) || defined(__MMI_BROWSER_2__) */

#if defined(__MMI_BPP_SUPPORT__)
extern void mmi_phb_highlight_op_print(void);
extern void mmi_phb_bpp_print(void);
extern void mmi_phb_bpp_prepare_field(mmi_bpp_xhtml_rsp_enum rsp_code);
extern void mmi_phb_bpp_xhtml_table_constructor(void);
extern void mmi_phb_bpp_image_file_callback(mmi_bpp_xhtml_rsp_enum rsp_code);
extern mmi_bpp_xhtml_rsp_enum mmi_phb_bpp_compose_attrs(void);
#endif /* defined(__MMI_BPP_SUPPORT__) */

/*
 * Static Function
 */

#if defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__)
static BOOL mmi_phb_image_check_image_file(void);
#endif

#ifdef __MMI_PHB_BIRTHDAY_FIELD__
static void mmi_phb_bday_changed_callback(U16 index);
#endif 

#ifdef __MMI_PHB_INFO_FIELD__
/* Entry Option - Edit Detail */
static void mmi_phb_exit_op_edit_detail(void);
static pBOOL mmi_phb_op_view_fill_extra_item(
                U8 field_index,
                U8 item_index,
                S8 **entry_list,
                U16 *title_list,
                U16 *image_list);
static void mmi_phb_highlight_op_edit_detail(void);
#endif /* __MMI_PHB_INFO_FIELD__ */ 

#if defined(__MMI_PHB_IMPS_FIELD__) || defined(__MMI_PHB_POC_FIELD__) || defined(__MMI_VOIP__)
/* Entry Option - Edit Service Field */
static void mmi_phb_exit_op_edit_service_field(void);
static pBOOL mmi_phb_op_view_fill_service_item(
                U8 field_index,
                U8 item_index,
                S8 **entry_list,
                U16 *title_list,
                U16 *image_list);
static void mmi_phb_highlight_op_edit_service_field(void);
static void mmi_phb_service_read_data_to_buff(U16 store_index);
static void mmi_phb_op_fill_inline_service_item(U8 field_index, U16 *string_list, U16 *image_list);
#endif /* defined(__MMI_PHB_IMPS_FIELD__) || defined(__MMI_PHB_POC_FIELD__) || defined(__MMI_VOIP__) */ 

#if defined(__MMI_PHB_IMPS_FIELD__)
static void mmi_phb_imps_send_message(void);
#endif 

#ifdef __MMI_SWFLASH__
static void mmi_phb_entry_swflash_default_option(void);
static void mmi_phb_swflash_pre_entry_file_option(void);
static void mmi_phb_entry_swflash_file_option(U8 type);
#endif /* __MMI_SWFLASH__ */

#ifdef __MMI_VOIP__
static void* mmi_phb_allocate_history_data_dummy(U32 size);
static void mmi_phb_free_history_data_dummy(void* param1);
#endif /* __MMI_VOIP__ */
#if defined(__MMI_PHB_IMPS_FIELD__) || defined(__MMI_VOIP__)
static void mmi_phb_service_update_field(U16 store_index);
#endif /* defined(__MMI_PHB_IMPS_FIELD__) || defined(__MMI_VOIP__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_clear_old_add_history
 * DESCRIPTION
 *  Deletes old PHB add screens from history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_clear_old_add_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/        
    DeleteScreenIfPresent(SCR_IN_PROGRESS_PHB);
    DeleteScreenIfPresent(SCR_ADD_NEW_ENTRY);    
    DeleteScreenIfPresent(SCR_STORAGE_LOCATION_MENU);
    DeleteScreenIfPresent(SCR_ID_PHB_FMGR_SAVE_OPTION);
    if (!IsScreenPresent(SCR_PBOOK_MAIN_MENU))
    {
        mmi_phb_reset_scr_id();        
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_clear_old_edit_history
 * DESCRIPTION
 *  Deletes old PHB edit screens from history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_clear_old_edit_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     
    DeleteScreenIfPresent(SCR_IN_PROGRESS_PHB);
    DeleteScreenIfPresent(SCR_INLINE_EDIT);    
    if (IsScreenPresent(SCR_ID_PHB_FMGR_SAVE_OPTION))
    {
        DeleteScreenIfPresent(SCR_PBOOK_LIST);
    }
    DeleteScreenIfPresent(SCR_PBOOK_ENTRY_OPTIONS);
    DeleteScreenIfPresent(SCR_ID_PHB_FMGR_SAVE_OPTION);    
#ifdef __MMI_MULTITAP_FOR_STAR_AND_POUND__
    DeleteScreenIfPresent(SCR_ID_PHB_QUICK_SEARCH_OPTION);
#endif   
    if (!IsScreenPresent(SCR_PBOOK_MAIN_MENU))
    {
        mmi_phb_reset_scr_id();        
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_operate_single_init
 * DESCRIPTION
 *  Register highlight handler and intialization for phonebook single entry operation.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_operate_single_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_operate_single_init.>\n", __FILE__,
                         __LINE__);

    /* Add Entry */
    SetHiliteHandler(MITEM102_PBOOK_NEW_ENTRY, mmi_phb_highlight_op_add_entry);
    SetHiliteHandler(MITEM102_PBOOK_NEW_ENTRY_NO_SIM, mmi_phb_highlight_op_add_entry);
    SetHiliteHandler(MITEM_ADD_ENTRY_TO_SIM, mmi_phb_highlight_op_add_entry_to_sim);
    SetHiliteHandler(MITEM_ADD_ENTRY_TO_PHONE, mmi_phb_highlight_op_add_entry_to_phone);
    SetHintHandler(MITEM_ADD_ENTRY_TO_SIM, mmi_phb_hint_op_add_entry_to_sim);
    SetHintHandler(MITEM_ADD_ENTRY_TO_PHONE, mmi_phb_hint_op_add_entry_to_phone);

    /* View, Edit, Delete, Copy, Move, Duplicate */
    SetHiliteHandler(MITEM1010_PBOOK_VIEW, mmi_phb_highlight_op_view_entry);
    SetHiliteHandler(MITEM1011_PBOOK_EDIT, mmi_phb_highlight_op_edit_entry);
#if defined(__MMI_PHB_INFO_FIELD__)
    SetHiliteHandler(MENU_ID_PHB_OPTION_EDIT_DETAIL, mmi_phb_highlight_op_edit_detail);
#endif 
#if defined(__MMI_PHB_IMPS_FIELD__) || defined(__MMI_PHB_POC_FIELD__) || defined(__MMI_VOIP__)
    SetHiliteHandler(MENU_ID_PHB_OPTION_EDIT_SERVICE_FIELD, mmi_phb_highlight_op_edit_service_field);
#endif 
    SetHiliteHandler(MITEM1012_PBOOK_DELETE, mmi_phb_highlight_op_delete_entry);
#ifdef __MMI_DUAL_SIM_MASTER__
    SetHiliteHandler(MITEM1013_PBOOK_COPY_ENTRY, MTPNP_PFAL_PHB_op_copy_menu);
    SetHiliteHandler(MITEM1014_PBOOK_MOVE, MTPNP_PFAL_PHB_op_move_menu);
#else   /* __MMI_DUAL_SIM_MASTER__ */
    SetHiliteHandler(MITEM1013_PBOOK_COPY_ENTRY, mmi_phb_highlight_op_copy_entry);
    SetHiliteHandler(MITEM1014_PBOOK_MOVE, mmi_phb_highlight_op_move_entry);
#endif  /* __MMI_DUAL_SIM_MASTER__ */
    SetHiliteHandler(MITEM1015_PBOOK_DUPLICATE, mmi_phb_highlight_op_duplicate_entry);

    /* Optional Operation */
#if defined(__MMI_PHB_COMBINE_COPY_DUPLICATE__) /* Combine copy and duplicate into one option. */
    SetHiliteHandler(MENU_ID_PHB_OPTION_COPY_DUPLICATE, mmi_phb_highlight_op_copy_duplicate);
#endif 

#if defined(__MMI_PHB_DIAL_FROM_PHB__)       /* Dial from phonebook entry option menu. */
    SetHiliteHandler(MENU_ID_PHB_OPTION_DIAL, mmi_phb_highlight_op_dial_number);
#endif

#if defined(__MMI_PHB_IP_DIAL_FROM_PHB__)       /* IP Dial from phonebook entry option menu. */
#if defined(__MMI_DUAL_SIM_MASTER__)
    SetHiliteHandler(MENU_MTPNP_PHB_OPTION_IP_DIAL_SIM1, mmi_phb_highlight_op_ip_number);
    SetHiliteHandler(MENU_MTPNP_PHB_OPTION_IP_DIAL_SIM2, MTPNP_PFAL_PHB_op_SIM2_ip_number);
#else	/* __MMI_DUAL_SIM_MASTER__ */
    SetHiliteHandler(MENU_ID_PHB_OPTION_IP_DIAL, mmi_phb_highlight_op_ip_number);
#endif /*__MMI_DUAL_SIM_MASTER__*/
#endif 

#if defined(__MMI_PHB_SEND_SMS_FROM_PHB__)      /* Send SMS from phonebook entry option menu. */
    SetHiliteHandler(MENU_ID_PHB_OPTION_SEND_SMS, mmi_phb_highlight_op_send_sms);
#endif 
#ifdef __MMI_PHB_SEND_MMS_FROM_PHB__
    SetHiliteHandler(MENU_ID_PHB_OPTION_SEND_MMS, mmi_phb_highlight_op_send_mms);
#endif 

#if defined(__MMI_VCARD__)      /* Send vCard */
    SetHiliteHandler(MENU_ID_PHB_VCARD_SEND_ENTRY, mmi_phb_highlight_vcard_send_select_card);
#endif 

#if defined(__MMI_BPP_SUPPORT__) 
    SetHiliteHandler(MENU_ID_PHB_PRINT, mmi_phb_highlight_op_print);
#endif
#if defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__)
    /* Associate Images Handling */
    SetHiliteHandler(MENU_ID_PHB_IMAGE_OPTION_VIEW, mmi_phb_highlight_image_view);
    SetHiliteHandler(MENU_ID_PHB_IMAGE_OPTION_SELECT, mmi_phb_highlight_image_select);
    SetHiliteHandler(MENU_ID_PHB_IMAGE_OPTION_DELETE, mmi_phb_highlight_image_delete);

    /* Save Image From File Manager */
    SetHiliteHandler(MENU_ID_PHB_FMGR_SAVE_NEW, mmi_phb_highlight_fmgr_add_entry);
    SetHiliteHandler(MENU_ID_PHB_FMGR_SAVE_LIST, mmi_phb_highlight_fmgr_edit_entry);
    SetHiliteHandler(MENU_ID_PHB_FMGR_SAVE_CALLGRP, mmi_phb_highlight_edit_callergroup);
    mmi_phb_image_init_folder();
#if defined(__MMI_AVATAR__)
    /* Associate 3D Avatar Images Handling */
    SetHiliteHandler(MENU_ID_PHB_AVATAR_IMAGE_OPTION_VIEW, mmi_phb_highlight_avatar_image_view);
    SetHiliteHandler(MENU_ID_PHB_AVATAR_IMAGE_OPTION_SELECT, mmi_phb_highlight_avatar_image_select);
    SetHiliteHandler(MENU_ID_PHB_AVATAR_IMAGE_OPTION_DELETE, mmi_phb_highlight_avatar_image_delete);
#endif /* defined(__MMI_AVATAR__) */

#endif /* defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__) */ 

#if defined(__MMI_VRSD_DIAL__)
    SetHiliteHandler(MENU_ID_VRSD_DIAL_PHB_OPTION, mmi_phb_highlight_op_voice_dial);
#endif 

#if defined(__MMI_INCOMING_CALL_VIDEO__)
    mmi_phb_video_init_data_store();
#ifdef __MMI_SWFLASH__
	SetHiliteHandler(MENU_ID_PHB_SWFLASH_DEFAULT_VIEW		,mmi_phb_highlight_video_default_view);
	SetHiliteHandler(MENU_ID_PHB_SWFLASH_DEFAULT_SETTING	,mmi_phb_highlight_video_setting);
	SetHiliteHandler(MENU_ID_PHB_SWFLASH_FILE_VIEW		,mmi_phb_highlight_video_file_view);
	SetHiliteHandler(MENU_ID_PHB_SWFLASH_FILE_SELECT		,mmi_phb_highlight_swflash_file_select);
	SetHiliteHandler(MENU_ID_PHB_SWFLASH_FILE_DELETE		,mmi_phb_highlight_video_file_delete);
	SetHiliteHandler(MENU_ID_PHB_SWFLASH_FILE_SETTING		,mmi_phb_highlight_video_setting);

	SetHintHandler(MENU_ID_PHB_SWFLASH_DEFAULT_SETTING	,mmi_phb_hint_video_setting);
	SetHintHandler(MENU_ID_PHB_SWFLASH_FILE_SETTING		,mmi_phb_hint_video_setting);
#endif /* __MMI_SWFLASH__ */

    SetHiliteHandler(MENU_ID_PHB_VIDEO_DEFAULT_VIEW, mmi_phb_highlight_video_default_view);
    SetHiliteHandler(MENU_ID_PHB_VIDEO_DEFAULT_SETTING, mmi_phb_highlight_video_setting);
    SetHiliteHandler(MENU_ID_PHB_VIDEO_FILE_VIEW, mmi_phb_highlight_video_file_view);
    SetHiliteHandler(MENU_ID_PHB_VIDEO_FILE_SELECT, mmi_phb_highlight_video_file_select);
    SetHiliteHandler(MENU_ID_PHB_VIDEO_FILE_DELETE, mmi_phb_highlight_video_file_delete);
    SetHiliteHandler(MENU_ID_PHB_VIDEO_FILE_SETTING, mmi_phb_highlight_video_setting);

    SetHintHandler(MENU_ID_PHB_VIDEO_DEFAULT_SETTING, mmi_phb_hint_video_setting);
    SetHintHandler(MENU_ID_PHB_VIDEO_FILE_SETTING, mmi_phb_hint_video_setting);

#if defined(__MMI_AVATAR__)
    SetHiliteHandler(MENU_ID_PHB_AVATAR_VIDEO_FILE_VIEW, mmi_phb_highlight_avatar_video_file_view);
    SetHiliteHandler(MENU_ID_PHB_AVATAR_VIDEO_FILE_SELECT, mmi_phb_highlight_avatar_video_file_select);
    SetHiliteHandler(MENU_ID_PHB_AVATAR_VIDEO_FILE_DELETE, mmi_phb_highlight_avatar_video_file_delete);
#endif /* defined(__MMI_AVATAR__) */
#endif /* defined(__MMI_INCOMING_CALL_VIDEO__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_op_option
 * DESCRIPTION
 *  Draws the Entry Options menu
 * PARAMETERS
 *  void
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_phb_entry_op_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[MMI_PHB_OPTION_ENUM_TOTAL];        /* Need Expand when has more options. */
    U16 nNumofItem;
#ifdef __MMI_DUAL_SIM_MASTER__
    E_MTPNP_AD_SIMCARD_USABLE_SIDE state = MTPNP_AD_Get_UsableSide();
#endif /* __MMI_DUAL_SIM_MASTER__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_entry_op_option.>\n", __FILE__, __LINE__);
    mmi_phb_operate_single_init();  /* Regiser highlight handler again. */

    EntryNewScreen(SCR_PBOOK_ENTRY_OPTIONS, mmi_phb_exit_op_option, mmi_phb_entry_op_option, NULL);

    // unhide all the menu that could be hidden
#if defined(__MMI_PHB_DIAL_FROM_PHB__)
    mmi_frm_unhide_menu_item(MENU_ID_PHB_OPTION_DIAL);
#endif
#if defined(__MMI_PHB_IP_DIAL_FROM_PHB__)
#ifdef __MMI_DUAL_SIM_MASTER__
    mmi_frm_unhide_menu_item(MENU_MTPNP_PHB_OPTION_IP_DIAL_SIM1);
    mmi_frm_unhide_menu_item(MENU_MTPNP_PHB_OPTION_IP_DIAL_SIM2);
#else /* __MMI_DUAL_SIM_MASTER__ */
    mmi_frm_unhide_menu_item(MENU_ID_PHB_OPTION_IP_DIAL);
#endif /*__MMI_DUAL_SIM_MASTER__*/
#endif
#if defined(__MMI_PHB_SEND_SMS_FROM_PHB__)
    mmi_frm_unhide_menu_item(MENU_ID_PHB_OPTION_SEND_SMS);
#endif
#if defined(__MMI_PHB_SEND_MMS_FROM_PHB__)
    mmi_frm_unhide_menu_item(MENU_ID_PHB_OPTION_SEND_MMS);
#endif
#if defined(__MMI_PHB_INFO_FIELD__)
    mmi_frm_unhide_menu_item(MENU_ID_PHB_OPTION_EDIT_DETAIL);
#endif
#if defined(__MMI_IMPS__) || defined(__MMI_PHB_POC_FIELD__) || defined(__MMI_VOIP__)
    mmi_frm_unhide_menu_item(MENU_ID_PHB_OPTION_EDIT_SERVICE_FIELD);
#endif
#if defined(__MMI_PHB_COMBINE_COPY_DUPLICATE__)
    mmi_frm_unhide_menu_item(MENU_ID_PHB_OPTION_COPY_DUPLICATE);
#else
    mmi_frm_unhide_menu_item(MITEM1013_PBOOK_COPY_ENTRY);
#endif
    mmi_frm_unhide_menu_item(MITEM1014_PBOOK_MOVE);

#if defined(__MMI_VCARD__)
    mmi_frm_unhide_menu_item(MENU_ID_PHB_VCARD_SEND_ENTRY);
#endif
#if defined(__MMI_VRSD_DIAL__)
    mmi_frm_unhide_menu_item(MENU_ID_VRSD_DIAL_PHB_OPTION);
#endif
#if defined(__MMI_BPP_SUPPORT__)
    mmi_frm_unhide_menu_item(MENU_ID_PHB_PRINT);
#endif

    // hide menu that should be hidden
#ifndef __MMI_DUAL_SIM_MASTER__
    if (mmi_bootup_is_sim_valid())
    {
        if (mmi_bootup_get_active_flight_mode() == 1)
        {
        #if defined(__MMI_PHB_DIAL_FROM_PHB__)
            mmi_frm_hide_menu_item(MENU_ID_PHB_OPTION_DIAL);
        #endif
        #if defined(__MMI_PHB_IP_DIAL_FROM_PHB__)
            mmi_frm_hide_menu_item(MENU_ID_PHB_OPTION_IP_DIAL);
        #endif /* defined(__MMI_PHB_IP_DIAL_FROM_PHB__) */
         
        #if defined(__MMI_VRSD_DIAL__)
            mmi_frm_hide_menu_item(MENU_ID_VRSD_DIAL_PHB_OPTION);
        #endif /* defined(__MMI_VRSD_DIAL__) */
        }
    #if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_WGUI_CSK_ENABLE__)
        else
        {
            EnableCenterSoftkey(0, IMG_CSK_DIAL_ICON);
        }
    #endif /* defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_WGUI_CSK_ENABLE__) */ 
   
    #if defined(__MMI_VRSD_DIAL__)
        if (isInCall())
        {
            mmi_frm_hide_menu_item(MENU_ID_VRSD_DIAL_PHB_OPTION);        
        }
    #endif /* defined(__MMI_VRSD_DIAL__) */
    }
    else
    {
    #if defined(__MMI_PHB_DIAL_FROM_PHB__)
        mmi_frm_hide_menu_item(MENU_ID_PHB_OPTION_DIAL);
    #endif 
    #if defined(__MMI_PHB_IP_DIAL_FROM_PHB__)
        mmi_frm_hide_menu_item(MENU_ID_PHB_OPTION_IP_DIAL);
    #endif
    #if defined(__MMI_PHB_COMBINE_COPY_DUPLICATE__)
        mmi_frm_hide_menu_item(MENU_ID_PHB_OPTION_COPY_DUPLICATE);
    #else
        mmi_frm_hide_menu_item(MITEM1013_PBOOK_COPY_ENTRY);
    #endif
        mmi_frm_hide_menu_item(MITEM1014_PBOOK_MOVE);
    #if defined(__MMI_VRSD_DIAL__)
        mmi_frm_hide_menu_item(MENU_ID_VRSD_DIAL_PHB_OPTION);
    #endif                                           
    }
#else /* __MMI_DUAL_SIM_MASTER__ */
    if (!(mmi_bootup_is_sim_valid() || mmi_bootup_is_sim2_valid()))
    {
    #if defined(__MMI_PHB_COMBINE_COPY_DUPLICATE__)
        mmi_frm_hide_menu_item(MENU_ID_PHB_OPTION_COPY_DUPLICATE);
    #else
        mmi_frm_hide_menu_item(MITEM1013_PBOOK_COPY_ENTRY);
    #endif
        mmi_frm_hide_menu_item(MITEM1014_PBOOK_MOVE);    
    }

    if (state!= MTPNP_AD_DUALSIM_USABLE && state != MTPNP_AD_SIMCARD1_USABLE && state != MTPNP_AD_SIMCARD2_USABLE)
    {
    #if defined(__MMI_PHB_DIAL_FROM_PHB__)
        mmi_frm_hide_menu_item(MENU_ID_PHB_OPTION_DIAL);
    #endif
    #if defined(__MMI_VRSD_DIAL__)
        mmi_frm_hide_menu_item(MENU_ID_VRSD_DIAL_PHB_OPTION);
    #endif /* defined(__MMI_VRSD_DIAL__) */
    }
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_WGUI_CSK_ENABLE__)
    else
    {
        EnableCenterSoftkey(0, IMG_CSK_DIAL_ICON);
    }
#endif /* defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_WGUI_CSK_ENABLE__) */ 
    switch (state)
    {
        case MTPNP_AD_DUALSIM_USABLE:
        {       
            /* do nothing */
        }
        break;
        
        case MTPNP_AD_SIMCARD1_USABLE:
        {
            mmi_frm_hide_menu_item(MENU_MTPNP_PHB_OPTION_IP_DIAL_SIM2);
        }
        break;
        
        case MTPNP_AD_SIMCARD2_USABLE:
        {
            mmi_frm_hide_menu_item(MENU_MTPNP_PHB_OPTION_IP_DIAL_SIM1);
        }
        break;

        default:
        {
            mmi_frm_hide_menu_item(MENU_MTPNP_PHB_OPTION_IP_DIAL_SIM1);
            mmi_frm_hide_menu_item(MENU_MTPNP_PHB_OPTION_IP_DIAL_SIM2);
        }
        break;
    }
#if defined(__MMI_VRSD_DIAL__)
    if (isInCall())
    {
        mmi_frm_hide_menu_item(MENU_ID_VRSD_DIAL_PHB_OPTION);        
    }
#endif /* defined(__MMI_VRSD_DIAL__) */
#endif /* __MMI_DUAL_SIM_MASTER__ */

#if defined(__MMI_PHB_SEND_SMS_FROM_PHB__)
    if (mmi_frm_sms_is_hide_send_sms_menu_item() == TRUE)
    {
        mmi_frm_hide_menu_item(MENU_ID_PHB_OPTION_SEND_SMS);
    }
#endif

#if defined(__MMI_PHB_SEND_MMS_FROM_PHB__)
    if (!mms_is_ready())
    {
        mmi_frm_hide_menu_item(MENU_ID_PHB_OPTION_SEND_MMS);
    }
#endif

#if defined(__MMI_PHB_INFO_FIELD__)
    if (g_phb_name_index[g_phb_cntx.active_index] >= MAX_PB_PHONE_ENTRIES)
    {
        mmi_frm_hide_menu_item(MENU_ID_PHB_OPTION_EDIT_DETAIL);
    }
#endif /* defined(__MMI_PHB_INFO_FIELD__) */


#if defined(__MMI_IMPS__) || defined(__MMI_PHB_POC_FIELD__) || defined(__MMI_VOIP__)
    if (g_phb_name_index[g_phb_cntx.active_index] >= MAX_PB_PHONE_ENTRIES)
    {
        mmi_frm_hide_menu_item(MENU_ID_PHB_OPTION_EDIT_SERVICE_FIELD);
    }
#endif /* defined(__MMI_IMPS__) || defined(__MMI_PHB_POC_FIELD__) || defined(__MMI_VOIP__) */ 

#if defined(__MMI_VCARD__) && !defined(__MMI_OPP_SUPPORT__) && !defined(__MMI_FILE_MANAGER__) /* OPP BT could send vCard without SIM */
    mmi_frm_hide_menu_item(MENU_ID_PHB_VCARD_SEND_ENTRY)
#endif /* defined(__MMI_VCARD__) && !defined(__MMI_OPP_SUPPORT__) */ 

#if defined(__MMI_BPP_SUPPORT__)
    if (isInCall() || (mmi_bootup_get_active_flight_mode() == 1))
    {
        mmi_frm_hide_menu_item(MENU_ID_PHB_PRINT);
    }
#endif

#ifdef  __MMI_DUAL_SIM_MASTER__
    MTPNP_PFAL_PB_Option_Menu_Handle();
#endif /* __MMI_DUAL_SIM_MASTER__ */

    guiBuffer = GetCurrGuiBuffer(SCR_PBOOK_ENTRY_OPTIONS);
    nNumofItem = GetNumOfChild_Ext(MITEM101_PBOOK_VIEW_OPTIONS);
    GetSequenceStringIds_Ext(MITEM101_PBOOK_VIEW_OPTIONS, nStrItemList);
    SetParentHandler(MITEM101_PBOOK_VIEW_OPTIONS);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_WGUI_CSK_ENABLE__)
#ifdef __MMI_DUAL_SIM_MASTER__
    MTPNP_PFAL_CC_SetCenterFunc(mmi_phb_choose_number_normal);
    SetCenterSoftkeyFunction(MTPNP_PFAL_CC_CSKHandler, KEY_EVENT_UP);
#else  /* __MMI_DUAL_SIM_MASTER__ */
    SetCenterSoftkeyFunction(mmi_phb_choose_number_normal, KEY_EVENT_UP);
#endif   /* __MMI_DUAL_SIM_MASTER__ */
#endif /* defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_WGUI_CSK_ENABLE__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_op_option
 * DESCRIPTION
 *  Exit function for mmi_phb_entry_op_option()
 * PARAMETERS
 *  void
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_phb_exit_op_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.end_scr_id = SCR_PBOOK_ENTRY_OPTIONS;
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_WGUI_CSK_ENABLE__)
    ResetCenterSoftkey();
#endif /* defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_WGUI_CSK_ENABLE__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_op_add_entry
 * DESCRIPTION
 *  Highlight handler for "Add New Entry" in PHB main menu
 * PARAMETERS
 *  void
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_phb_highlight_op_add_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(pbNumber, 0, ENCODING_LENGTH);
    g_phb_cntx.set_done_flag = 0;

    SetLeftSoftkeyFunction(mmi_phb_op_add_pre_entry, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_op_add_pre_entry, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_op_add_entry_to_sim
 * DESCRIPTION
 *  Highlight handler for "To SIM" in Add Entry menu
 * PARAMETERS
 *  void
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_phb_highlight_op_add_entry_to_sim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    g_phb_cntx.selected_storage = MMI_SIM;

    if (g_phb_cntx.sim_used >= g_phb_cntx.sim_total)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(mmi_phb_pre_entry_op_add_entry, KEY_EVENT_UP);
        SetKeyHandler(mmi_phb_pre_entry_op_add_entry, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_op_add_entry_to_phone
 * DESCRIPTION
 *  Highlight handler for "To Phone" in Add Entry menu
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_phb_highlight_op_add_entry_to_phone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    g_phb_cntx.selected_storage = MMI_NVRAM;

    if (g_phb_cntx.phone_used >= g_phb_cntx.phone_total)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(mmi_phb_pre_entry_op_add_entry, KEY_EVENT_UP);
        SetKeyHandler(mmi_phb_pre_entry_op_add_entry, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_hint_op_add_entry_to_sim
 * DESCRIPTION
 *  Hint handler for "To SIM" in Add Entry menu
 * PARAMETERS
 *  index       [IN]        Current index
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_phb_hint_op_add_entry_to_sim(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 simStatus[40];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[index], 0, sizeof(hintData[index]));
    mmi_phb_memory_status_get_sim(simStatus);
    mmi_ucs2cpy((S8*) hintData[index], simStatus);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_hint_op_add_entry_to_phone
 * DESCRIPTION
 *  Hint handler for "To Phone" in Add Entry menu
 * PARAMETERS
 *  index       [IN]        Current index
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_phb_hint_op_add_entry_to_phone(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 phoneStatus[40];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[index], 0, sizeof(hintData[index]));
    mmi_phb_memory_status_get_phone(phoneStatus);
    mmi_ucs2cpy((S8*) hintData[index], phoneStatus);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_add_pre_entry
 * DESCRIPTION
 *  Checks the phone book list is empty or not
 * PARAMETERS
 *  void
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_phb_op_add_pre_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_op_add_pre_entry.>\n", __FILE__,
                         __LINE__);

#ifdef __MMI_DUAL_SIM_MASTER__
    if (MTPNP_PFAL_Phb_IsReady() == MTPNP_FALSE)
#else   /* __MMI_DUAL_SIM_MASTER__ */
    if (!g_phb_cntx.phb_ready || g_phb_cntx.processing)
#endif  /* __MMI_DUAL_SIM_MASTER__ */
    {
        mmi_phb_entry_not_ready(STR_PROCESSING_PHONEBOOK);
    }
#ifdef __SYNCML_SUPPORT__
    else if (mmi_syncml_is_phb_sync_now())
    {
        mmi_phb_entry_not_ready(STR_ID_SYNC_PLEASE_WAIT);
    }
#endif /* __SYNCML_SUPPORT__ */
#ifdef __MMI_DUAL_SIM_MASTER__
    else if (PhoneBookEntryCount == g_phb_cntx.sim_total + g_phb_cntx.phone_total+MTPNP_AD_ADN_SIM2GetCapacity())
#else   /* __MMI_DUAL_SIM_MASTER__ */
    else if (PhoneBookEntryCount == (g_phb_cntx.sim_total + g_phb_cntx.phone_total))
#endif  /* __MMI_DUAL_SIM_MASTER__ */
    {
        DisplayPopup((PU8) GetString(STR_PBOOK_FULL_MSG), IMG_GLOBAL_ERROR, FALSE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
    }
#ifdef __MMI_PHB_USIM_FIELD__
    else if (g_phb_cntx.is_usim && g_phb_cntx.usim_ready_stage != MMI_PHB_USIM_READY)
    {
        mmi_phb_entry_not_ready(STR_ID_PHB_PROCESSING_USIM);
    }
#endif /* __MMI_PHB_USIM_FIELD__ */
    else
    {
        if (g_phb_cntx.set_done_flag)   /* save number from idle screen shouldn't clear the phNumber */
        {
            mmi_phb_util_clear_buffer(FALSE);
        }
        else
        {
            mmi_phb_util_clear_buffer(TRUE);
        }
        mmi_phb_entry_op_add_choose_storage();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_op_add_choose_storage
 * DESCRIPTION
 *  Draws the storage location menu for user to choose storage for new entry.
 * PARAMETERS
 *  void
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_phb_entry_op_add_choose_storage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
#ifdef __MMI_DUAL_SIM_MASTER__
    U16 nStrItemList[3];
    U16 nImgIltemList[3];
    U8 *nHintList[3];
    U8 hilight_SlaveSIM;
#else	/* __MMI_DUAL_SIM_MASTER__ */
    U16 nStrItemList[2];
    U16 nImgIltemList[2];
    U8 *nHintList[2];
#endif	/* __MMI_DUAL_SIM_MASTER__ */
    U16 nNumofItem;
    U8 hilitedStorage;
    U8 hilight_sim, highlight_phone;
    MMI_BOOL get_hilight = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
    if (MTPNP_PFAL_Phb_IsReady() == MTPNP_FALSE)
#else/* __MMI_DUAL_SIM_MASTER__ */
    if (!g_phb_cntx.phb_ready || g_phb_cntx.processing)
#endif/* __MMI_DUAL_SIM_MASTER__ */
    {
        mmi_phb_entry_not_ready(STR_PROCESSING_PHONEBOOK);
    }
#ifdef __MMI_PHB_USIM_FIELD__
    else if (g_phb_cntx.is_usim && g_phb_cntx.usim_ready_stage != MMI_PHB_USIM_READY)
    {
        mmi_phb_entry_not_ready(STR_ID_PHB_PROCESSING_USIM);
    }
#endif /* __MMI_PHB_USIM_FIELD__ */
#ifdef __SYNCML_SUPPORT__
    else if (mmi_syncml_is_phb_sync_now())
    {
        mmi_phb_entry_not_ready(STR_ID_SYNC_PLEASE_WAIT);
    }
#endif /* __SYNCML_SUPPORT__ */
    else
    {
        EntryNewScreen(
            SCR_STORAGE_LOCATION_MENU,
            mmi_phb_exit_op_add_choose_storage,
            mmi_phb_entry_op_add_choose_storage,
            NULL);
       
        mmi_frm_unhide_menu_item(MITEM_ADD_ENTRY_TO_SIM);
    #ifdef __MMI_DUAL_SIM_MASTER__        
        mmi_frm_unhide_menu_item(MENU_MTPNP_PB_ADD_SIM2);
    #endif

        if (!mmi_bootup_is_sim_valid())
        {
            mmi_frm_hide_menu_item(MITEM_ADD_ENTRY_TO_SIM);        
        }

    #ifdef __MMI_DUAL_SIM_MASTER__
        if(!mmi_bootup_is_sim2_valid())
        {
            mmi_frm_hide_menu_item(MENU_MTPNP_PB_ADD_SIM2);        
        }
    #endif /* __MMI_DUAL_SIM_MASTER__ */

        hilight_sim = GetIndexOfStringId_Ext(MITEM102_PBOOK_NEW_ENTRY, MITEM_ADD_ENTRY_TO_SIM);
        highlight_phone = GetIndexOfStringId_Ext(MITEM102_PBOOK_NEW_ENTRY, MITEM_ADD_ENTRY_TO_PHONE);
    #ifdef __MMI_DUAL_SIM_MASTER__
	    hilight_SlaveSIM = GetIndexOfStringId_Ext(MITEM102_PBOOK_NEW_ENTRY, MENU_MTPNP_PB_ADD_SIM2);
    #endif /* __MMI_DUAL_SIM_MASTER__ */
    
        if (mmi_bootup_is_sim_valid())
        {
            if (g_phb_cntx.prefer_storage == MMI_SIM)
            {
            #ifdef __MMI_DUAL_SIM_MASTER__
                hilitedStorage = hilight_sim;
            #else /* __MMI_DUAL_SIM_MASTER__ */
                if ((g_phb_cntx.sim_used < g_phb_cntx.sim_total) || (g_phb_cntx.phone_used == g_phb_cntx.phone_total))
                {
                    hilitedStorage = hilight_sim;
                }
                else
                {
                    hilitedStorage = highlight_phone;
                }
            #endif /* __MMI_DUAL_SIM_MASTER__ */
				get_hilight = MMI_TRUE;        
            }
        }

    #ifdef __MMI_DUAL_SIM_MASTER__
        if (mmi_bootup_is_sim2_valid())
        {
            if (g_phb_cntx.prefer_storage == MMI_SIM2)
            {
                hilitedStorage = hilight_SlaveSIM;
                get_hilight = MMI_TRUE;
            }        
        }
    #endif /* __MMI_DUAL_SIM_MASTER__ */

        if (g_phb_cntx.prefer_storage == MMI_NVRAM)
        {
        #ifdef __MMI_DUAL_SIM_MASTER__
            hilitedStorage = highlight_phone;
        #else /* __MMI_DUAL_SIM_MASTER__ */
            if (!mmi_bootup_is_sim_valid() || (g_phb_cntx.phone_used < g_phb_cntx.phone_total) || (g_phb_cntx.sim_used == g_phb_cntx.sim_total))
            {
                hilitedStorage = highlight_phone;
            }
            else
            {
                hilitedStorage = hilight_sim;
            }  
        #endif /* __MMI_DUAL_SIM_MASTER__ */
            get_hilight = MMI_TRUE;            
        }
        
        guiBuffer = GetCurrGuiBuffer(SCR_STORAGE_LOCATION_MENU);
        nNumofItem = GetNumOfChild_Ext(MITEM102_PBOOK_NEW_ENTRY);
        GetSequenceStringIds_Ext(MITEM102_PBOOK_NEW_ENTRY, nStrItemList);
        GetSequenceImageIds_Ext(MITEM102_PBOOK_NEW_ENTRY, nImgIltemList);
        SetParentHandler(MITEM102_PBOOK_NEW_ENTRY);
        RegisterHighlightHandler(ExecuteCurrHiliteHandler);
        ConstructHintsList(MITEM102_PBOOK_NEW_ENTRY, nHintList);
        
        ShowCategory52Screen(
            STR_CHOOSE_STORAGE_CAPTION,
            IMG_SCR_PBOOK_CAPTION,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            nNumofItem,
            nStrItemList,
            nImgIltemList,
            nHintList,
            0,
            (get_hilight == MMI_TRUE) ? hilitedStorage : 0,
            guiBuffer);

        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_op_add_choose_storage
 * DESCRIPTION
 *  Exit function for mmi_phb_entry_op_add_choose_storage()
 * PARAMETERS
 *  void
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_phb_exit_op_add_choose_storage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.end_scr_id = SCR_STORAGE_LOCATION_MENU;
}


#if defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
* FUNCTION
*  mmi_phb_op_email_custom_function
* DESCRIPTION
*
*
* PARAMETERS
*  void
* RETURNS
 *  the description of return value, if any.(?)
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void mmi_phb_op_email_custom_function(void)
{
    mmi_pen_editor_set_vk_keys(MMI_TRUE, mmi_phb_e_mail_allowed, NULL);
}
#endif /* defined(__MMI_TOUCH_SCREEN__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_fill_inline_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  field_index     [IN]            
 *  item_index      [IN]            
 *  store_index     [IN]            
 *  string_list     [?]             
 *  image_list      [?]             
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_phb_op_fill_inline_item(U8 field_index, U8 item_index, U16 store_index, U16 *string_list, U16 *image_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 nameLength;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (field_index)
    {
      /*--- Name Field ---*/
        case MMI_PHB_FIELD_NAME:

            /* Assign name length */
            if ((store_index == MAX_PB_ENTRIES && g_phb_cntx.selected_storage == MMI_SIM) ||    /* Add SIM */
                (store_index < MAX_PB_ENTRIES && store_index >= MAX_PB_PHONE_ENTRIES))  /* Edit Entry */
            {
                nameLength = g_phb_cntx.sim_name_len;
            }
            else
            {
                nameLength = MAX_PB_NAME_LENGTH;
            }

            SetInlineItemActivation(&wgui_inline_items[item_index], KEY_LSK, KEY_EVENT_UP);
        #if defined(__PHB_0x81_SUPPORT__)
            SetInlineItemFullScreenEdit_ext(
                &wgui_inline_items[item_index],
                STR_ID_PHB_NAME,
                IMG_SCR_PBOOK_CAPTION,
                (PU8) pbName,
                nameLength + 1,
                (INPUT_TYPE_ALPHANUMERIC_UPPERCASE | INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ONE_LESS_CHARACTER | INPUT_TYPE_GSM_EXTENDED_HANDLING),
                INPUT_TYPE_EXT_USE_0x81_ENCODING | INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
        #else /* defined(__PHB_0x81_SUPPORT__) */ 
            SetInlineItemFullScreenEdit_ext(
                &wgui_inline_items[item_index],
                STR_ID_PHB_NAME,
                IMG_SCR_PBOOK_CAPTION,
                (PU8) pbName,
                nameLength + 1,
                (INPUT_TYPE_ALPHANUMERIC_UPPERCASE | INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ONE_LESS_CHARACTER | INPUT_TYPE_GSM_EXTENDED_HANDLING),
                INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
        #endif /* defined(__PHB_0x81_SUPPORT__) */ 
            SetInlineFullScreenEditCustomFunction(&wgui_inline_items[item_index], mmi_phb_set_full_scr_lsk);
            string_list[item_index] = STR_ID_PHB_NAME;
            image_list[item_index] = IMG_NAME;
        #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[item_index], string_list[item_index]);
        #endif 

            break;

      /*--- Mobile Number Field ---*/
        case MMI_PHB_FIELD_NUMBER:
            SetInlineItemActivation(&wgui_inline_items[item_index], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemTextEdit(
                &wgui_inline_items[item_index],
                (PU8) pbNumber,
                MAX_PB_NUMBER_LENGTH + 1,
                INPUT_TYPE_PHONE_NUMBER | INPUT_TYPE_PLUS_CHARACTER_HANDLING);
            DisableInlineItemHighlight(&wgui_inline_items[item_index]);
            string_list[item_index] = STR_ID_PHB_MOBILE_NUMBER;
            image_list[item_index] = IMG_MOBILE_NUMBER;
        #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[item_index], string_list[item_index]);
        #endif 

            break;

        #if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
      /*--- Home Number Field ---*/
        case MMI_PHB_FIELD_HOME:
            SetInlineItemActivation(&wgui_inline_items[item_index], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemTextEdit(
                &wgui_inline_items[item_index],
                (PU8) pbHomeNumber,
                MAX_PB_NUMBER_LENGTH + 1,
                INPUT_TYPE_PHONE_NUMBER | INPUT_TYPE_PLUS_CHARACTER_HANDLING);
            DisableInlineItemHighlight(&wgui_inline_items[item_index]);
            string_list[item_index] = STR_HOME_NUMBER;
            image_list[item_index] = IMG_HOME_NUMBER;
        #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[item_index], string_list[item_index]);
        #endif 

            break;

      /*--- Company Name Field ---*/
        case MMI_PHB_FIELD_COMPANY_NAME:
            SetInlineItemActivation(&wgui_inline_items[item_index], KEY_LSK, KEY_EVENT_UP);
            SetInlineItemFullScreenEdit(
                &wgui_inline_items[item_index],
                STR_COMPNAY_NAME,
                IMG_SCR_PBOOK_CAPTION,
                (PU8) pbCompanyName,
                MAX_PB_COMPANY_LENGTH + 1,
                INPUT_TYPE_ALPHANUMERIC_UPPERCASE);
            SetInlineFullScreenEditCustomFunction(&wgui_inline_items[item_index], mmi_phb_set_full_scr_lsk);
            string_list[item_index] = STR_COMPNAY_NAME;
            image_list[item_index] = IMG_COMPANY_NAME;
        #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[item_index], string_list[item_index]);
        #endif 

            break;

      /*--- Email Field ---*/
        case MMI_PHB_FIELD_EMAIL:
            SetInlineItemActivation(&wgui_inline_items[item_index], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemTextEdit(
                &wgui_inline_items[item_index],
                (PU8) pbEmailAddress,
                MAX_PB_EMAIL_LENGTH + 1,
                INPUT_TYPE_ALPHANUMERIC_LOWERCASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES);
        #if defined(__MMI_TOUCH_SCREEN__)
            SetInlineTextEditCustomFunction(&wgui_inline_items[item_index], mmi_phb_op_email_custom_function);
        #endif
            DisableInlineItemHighlight(&wgui_inline_items[item_index]);
            string_list[item_index] = STR_EMAIL_ADRESS;
            image_list[item_index] = IMG_EMAIL_ADDRESS;
        #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[item_index], string_list[item_index]);
        #endif 

            break;
      /*--- Office Number Field ---*/
        case MMI_PHB_FIELD_OFFICE:
            SetInlineItemActivation(&wgui_inline_items[item_index], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemTextEdit(
                &wgui_inline_items[item_index],
                (PU8) pbOfficeNumber,
                MAX_PB_NUMBER_LENGTH + 1,
                INPUT_TYPE_PHONE_NUMBER | INPUT_TYPE_PLUS_CHARACTER_HANDLING);
            DisableInlineItemHighlight(&wgui_inline_items[item_index]);
            string_list[item_index] = STR_OFFICE_NUMBER;
            image_list[item_index] = IMG_OFFICE_NUMBER;
        #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[item_index], string_list[item_index]);
        #endif 

            break;
      /*--- Fax Number Field ---*/
        case MMI_PHB_FIELD_FAX:
            SetInlineItemActivation(&wgui_inline_items[item_index], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemTextEdit(
                &wgui_inline_items[item_index],
                (PU8) pbFaxNumber,
                MAX_PB_NUMBER_LENGTH + 1,
                INPUT_TYPE_PHONE_NUMBER | INPUT_TYPE_PLUS_CHARACTER_HANDLING);
            DisableInlineItemHighlight(&wgui_inline_items[item_index]);
            string_list[item_index] = STR_FAX_NUMBER;
            image_list[item_index] = IMG_FAX_NUMBER;
        #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[item_index], string_list[item_index]);
        #endif 

            break;
        #endif /* !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */ /* END #if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */

      /*--- Caller Picture Field ---*/
        case MMI_PHB_FIELD_PIC:
            SetInlineItemActivation(&wgui_inline_items[item_index], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemSelect(
                &wgui_inline_items[item_index],
                g_phb_cntx.total_image_id,
                g_phb_cntx.image_name_list,
                &g_phb_cntx.selected_pic_index);
        #if defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__)
            RegisterInlineSelectHighlightHandler(&wgui_inline_items[item_index], mmi_phb_image_highlight_hdlr);
        #endif 
            string_list[item_index] = STR_ASSOCIATE_PICTURE;
            image_list[item_index] = IMG_PICTURE;

            gPictureItemIndex = item_index;

            break;
      /*--- Caller Ring Tone Field ---*/
        case MMI_PHB_FIELD_RING:
            SetInlineItemActivation(&wgui_inline_items[item_index], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemSelect(
                &wgui_inline_items[item_index],
                g_phb_cntx.total_ring_tone,
                g_phb_cntx.ring_tone_name_list,
                &g_phb_cntx.selected_ring_index);
            RegisterInlineSelectHighlightHandler(&wgui_inline_items[item_index], mmi_phb_ring_tone_highlight_hdlr);
            string_list[item_index] = STR_ASSOCIATE_SOUND;
            image_list[item_index] = IMG_RING_TONE;

            break;
      /*--- Caller Group Field ---*/
        case MMI_PHB_FIELD_GROUP:
            SetInlineItemActivation(&wgui_inline_items[item_index], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemSelect(
                &wgui_inline_items[item_index],
                MAX_PB_CALLER_GROUPS + 1,
                myCallerGrpnames,
                &g_phb_cntx.selected_grp_index);
            string_list[item_index] = STR_CALLER_GROUP;
            image_list[item_index] = IMG_CALLER_GROUP;

            break;
        #if defined(__MMI_INCOMING_CALL_VIDEO__)
      /*--- Caller Video Field ---*/
        case MMI_PHB_FIELD_VIDEO:
            SetInlineItemActivation(&wgui_inline_items[item_index], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemSelect(
                &wgui_inline_items[item_index],
                g_phb_cntx.total_video_id,
                g_phb_cntx.video_name_list,
                &g_phb_cntx.selected_video_index);
            RegisterInlineSelectHighlightHandler(&wgui_inline_items[item_index], mmi_phb_video_highlight_hdlr);
            string_list[item_index] = STR_ID_PHB_ASSOCIATE_VIDEO;
            image_list[item_index] = IMG_ID_PHB_ASSOCIATE_VIDEO;

            g_phb_video_item_index = item_index;

            break;
        #endif /* defined(__MMI_INCOMING_CALL_VIDEO__) */ 
        #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
      /*--- Birthday Field ---*/
        case MMI_PHB_FIELD_BIRTHDAY:
            RegisterInlineItemChangedNotification(mmi_phb_bday_changed_callback);
            bday_inline_index = item_index;
            SetInlineItemActivation(&wgui_inline_items[item_index], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            if (bday_modified == FALSE)
            {
                MYTIME current_time;
                S8 time_string[6];

                GetDateTime(&current_time);
                sprintf((S8*) time_string, "%04d", current_time.nYear);
                mmi_asc_to_ucs2((S8*) pbYear, time_string);
                sprintf((S8*) time_string, "%02d", current_time.nMonth);
                mmi_asc_to_ucs2((S8*) pbMon, time_string);
                sprintf((S8*) time_string, "%02d", current_time.nDay);
                mmi_asc_to_ucs2((S8*) pbDay, time_string);
            }
            SetInlineItemDate(
                &wgui_inline_items[item_index],
                (U8*) pbDay,
                (U8*) pbMon,
                (U8*) pbYear,
                mmi_phb_bday_editor_callback);
            DisableInlineItemHighlight(&wgui_inline_items[item_index]);
            set_inline_date_boundary(MMI_PHB_BDAY_MAX_YEAR_INT, 1900, 12, 1);

            string_list[item_index] = STR_ID_PHB_BIRTHDAY;
            image_list[item_index] = IMG_ID_PHB_BIRTHDAY;
            break;
        #endif /* defined(__MMI_PHB_BIRTHDAY_FIELD__) */ 
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_reconfig_inline_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  guiBuffer       [?]             
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_phb_op_reconfig_inline_item(U8 *guiBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Reconfig picture field */
    if ((gPictureItemIndex != MAX_PB_PICTURES_TAGS) && viewOnce)        /* Reconfig only if view fields has turned on */
    {
        viewOnce = FALSE;

    #if defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__)
        /* If select from file but no image selected, clear it to default */
        if ((g_phb_cntx.selected_pic_index == g_phb_cntx.total_image_id - 1) &&
            (g_phb_cntx.image_location == MMI_PHB_IMAGE_NO_SELECT 
        #ifdef __MMI_AVATAR__
            || g_phb_cntx.image_location == MMI_PHB_AVATAR_SELECT_PATH
        #endif
            ))
        {
            g_phb_cntx.selected_pic_index = 0;
            g_phb_cntx.image_location = MMI_PHB_IMAGE_NO_SELECT;
        }
        else if (g_phb_cntx.selected_pic_index != g_phb_cntx.total_image_id - 1
        #ifdef __MMI_AVATAR__
                && g_phb_cntx.selected_pic_index != g_phb_cntx.total_image_id - 2
        #endif
            )
        {
            g_phb_cntx.selected_pic_index = g_phb_cntx.selected_pic_in_view;
        }
    #else /* defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__) */
        g_phb_cntx.selected_pic_index = g_phb_cntx.selected_pic_in_view;
    #endif /* defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__) */
        ReConfigureInlineItemSelect(
            &wgui_inline_items[gPictureItemIndex],
            g_phb_cntx.total_image_id,
            g_phb_cntx.image_name_list,
            &g_phb_cntx.selected_pic_index);
    #if defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__)
        RegisterInlineSelectHighlightHandler(&wgui_inline_items[gPictureItemIndex], mmi_phb_image_highlight_hdlr);
    #endif 
        SetInlineDoneFlag(guiBuffer);
    }

#ifdef __MMI_AVATAR__
    if ((gPictureItemIndex != MAX_PB_PICTURES_TAGS) && g_phb_avatar_image_view)        /* Reconfig only if view fields has turned on */
    {
        g_phb_avatar_image_view = FALSE;

        if ((g_phb_cntx.selected_pic_index == g_phb_cntx.total_image_id - 2) &&
            (g_phb_cntx.image_location != MMI_PHB_AVATAR_SELECT_PATH) &&
            (g_phb_cntx.image_location != MMI_PHB_IMAGE_FOR_ENTRY))
        {
            g_phb_cntx.selected_pic_index = 0;
            g_phb_cntx.image_location = MMI_PHB_IMAGE_NO_SELECT;
        }

        ReConfigureInlineItemSelect(
            &wgui_inline_items[gPictureItemIndex],
            g_phb_cntx.total_image_id,
            g_phb_cntx.image_name_list,
            &g_phb_cntx.selected_pic_index);
    #if defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__)
        RegisterInlineSelectHighlightHandler(&wgui_inline_items[gPictureItemIndex], mmi_phb_image_highlight_hdlr);
    #endif 
        SetInlineDoneFlag(guiBuffer);
    }
#endif /* def __MMI_AVATAR__ */

    /* Reconfig video field */
#if defined(__MMI_INCOMING_CALL_VIDEO__)
    if ((g_phb_video_item_index != MAX_PB_VIDEO_TAGS) && g_phb_video_view)      /* Reconfig only if view fields has turned on */
    {
        g_phb_video_view = FALSE;

        if ((g_phb_cntx.selected_video_index == g_phb_cntx.total_video_id - 1) &&
            (g_phb_cntx.video_location == MMI_PHB_IMAGE_NO_SELECT ||
             g_phb_cntx.video_location == MMI_PHB_SWFLASH_SELECT_PATH ||
             g_phb_cntx.video_location == MMI_PHB_AVATAR_SELECT_PATH))
        {
            g_phb_cntx.selected_video_index = 0;
            g_phb_cntx.video_location = MMI_PHB_IMAGE_NO_SELECT;
        }

        ReConfigureInlineItemSelect(
            &wgui_inline_items[g_phb_video_item_index],
            g_phb_cntx.total_video_id,
            g_phb_cntx.video_name_list,
            &g_phb_cntx.selected_video_index);
        RegisterInlineSelectHighlightHandler(&wgui_inline_items[g_phb_video_item_index], mmi_phb_video_highlight_hdlr);
        SetInlineDoneFlag(guiBuffer);
    }
#ifdef __MMI_AVATAR__
    if ((g_phb_video_item_index != MAX_PB_VIDEO_TAGS) && g_phb_avatar_video_view)      /* Reconfig only if view fields has turned on */
    {
        g_phb_avatar_video_view = FALSE;

        if ((g_phb_cntx.selected_video_index == g_phb_cntx.total_video_id - g_phb_avatar_video_minus) &&
            (g_phb_cntx.video_location != MMI_PHB_AVATAR_SELECT_PATH))
        {
            g_phb_cntx.selected_video_index = 0;
            g_phb_cntx.video_location = MMI_PHB_IMAGE_NO_SELECT;
        }

        ReConfigureInlineItemSelect(
            &wgui_inline_items[g_phb_video_item_index],
            g_phb_cntx.total_video_id,
            g_phb_cntx.video_name_list,
            &g_phb_cntx.selected_video_index);
        RegisterInlineSelectHighlightHandler(&wgui_inline_items[g_phb_video_item_index], mmi_phb_video_highlight_hdlr);
        SetInlineDoneFlag(guiBuffer);
    }
#endif /* __MMI_AVATAR__ */
#ifdef __MMI_SWFLASH__
    if ((g_phb_video_item_index != MAX_PB_VIDEO_TAGS) && g_phb_swflash_view)      /* Reconfig only if view fields has turned on */
    {
        g_phb_swflash_view = FALSE;

        if ((g_phb_cntx.selected_video_index == g_phb_cntx.total_video_id - g_phb_swflash_video_minus) &&
            (g_phb_cntx.video_location != MMI_PHB_SWFLASH_SELECT_PATH))
        {
            g_phb_cntx.selected_video_index = 0;
            g_phb_cntx.video_location = MMI_PHB_IMAGE_NO_SELECT;
        }

        ReConfigureInlineItemSelect(
            &wgui_inline_items[g_phb_video_item_index],
            g_phb_cntx.total_video_id,
            g_phb_cntx.video_name_list,
            &g_phb_cntx.selected_video_index);
        RegisterInlineSelectHighlightHandler(&wgui_inline_items[g_phb_video_item_index], mmi_phb_video_highlight_hdlr);
        SetInlineDoneFlag(guiBuffer);
    }
#endif /* __MMI_SWFLASH__ */
#endif /* defined(__MMI_INCOMING_CALL_VIDEO__) */ 
}


#ifdef __MMI_PHB_USIM_FIELD__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_view_fill_usim_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  field_index     [IN]            Field index for the enum value
 *  item_index      [IN]            Item index for the inline editor
 *  entry_list      [IN]            String list for the data of the field
 *  title_list      [OUT]           String list for title
 *  image_list      [OUT]           Image list
 * RETURNS
 *  Return TRUE if non-empty field.
 *****************************************************************************/
static pBOOL mmi_phb_op_view_fill_usim_item(
                U8 field_index,
                U8 item_index,
                S8 **entry_list,
                U16 *title_list,
                U16 *image_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (field_index)
    {
        case MMI_PHB_USIM_FIELD_ANRA:
            if (g_phb_cntx.usim_ready_stage != MMI_PHB_USIM_READY)
            {
                *entry_list = GetString(STR_ID_PHB_PROCESSING_USIM);
            }
            else
            {
                *entry_list = pbHomeNumber;
            }
            title_list[item_index] = STR_ID_PHB_ANR_1;
            image_list[item_index] = IMG_ID_PHB_ANR;
            break;

        case MMI_PHB_USIM_FIELD_EMAIL:
            if (g_phb_cntx.usim_ready_stage != MMI_PHB_USIM_READY)
            {
                *entry_list = GetString(STR_ID_PHB_PROCESSING_USIM);
            }
            else
            {
                *entry_list = pbEmailAddress;
            }
            title_list[item_index] = STR_EMAIL_ADRESS;
            image_list[item_index] = IMG_EMAIL_ADDRESS;
            break;

        case MMI_PHB_USIM_FIELD_ANRB:
            if (g_phb_cntx.usim_ready_stage != MMI_PHB_USIM_READY)
            {
                *entry_list = GetString(STR_ID_PHB_PROCESSING_USIM);
            }
            else
            {
                *entry_list = pbOfficeNumber;
            }
            title_list[item_index] = STR_ID_PHB_ANR_2;
            image_list[item_index] = IMG_ID_PHB_ANR;
            break;

        case MMI_PHB_USIM_FIELD_ANRC:
            if (g_phb_cntx.usim_ready_stage != MMI_PHB_USIM_READY)
            {
                *entry_list = GetString(STR_ID_PHB_PROCESSING_USIM);
            }
            else
            {
                *entry_list = pbFaxNumber;
            }
            title_list[item_index] = STR_ID_PHB_ANR_3;
            image_list[item_index] = IMG_ID_PHB_ANR;
            break;

        case MMI_PHB_USIM_FIELD_GROUP:
            if (g_phb_cntx.usim_ready_stage != MMI_PHB_USIM_READY)
            {
                *entry_list = GetString(STR_ID_PHB_PROCESSING_USIM);
            }
            else if (g_phb_cntx.selected_grp_index == 0)
            {
                return FALSE;
            }
            else
            {
                *entry_list = (PS8) myCallerGrpnames[g_phb_cntx.selected_grp_index];
            }
            title_list[item_index] = STR_CALLER_GROUP;
            image_list[item_index] = IMG_CALLER_GROUP;
            return TRUE;

      /*--- SNE Field ---*/
        case MMI_PHB_USIM_FIELD_SNE:
            if (g_phb_cntx.usim_ready_stage != MMI_PHB_USIM_READY)
            {
                *entry_list = GetString(STR_ID_PHB_PROCESSING_USIM);
            }
            else
            {
                *entry_list = pbNickName;
            }
            title_list[item_index] = STR_ID_PHB_SNE;
            image_list[item_index] = IMG_ID_PHB_SNE;
            break;

    }
    if (*entry_list && mmi_ucs2strlen(*entry_list) > 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_fill_usim_inline_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  field_index     [IN]            
 *  item_index      [IN]            
 *  store_index     [IN]            
 *  string_list     [?]             
 *  image_list      [?]             
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  add this item or not.(?)
 *****************************************************************************/
void mmi_phb_op_fill_usim_inline_item(
        U8 field_index,
        U8 item_index,
        U16 store_index,
        U16 *string_list,
        U16 *image_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 nameLength;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (field_index)
    {
            // #if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)*/
      /*--- ANRA Field ---*/
        case MMI_PHB_USIM_FIELD_ANRA:
            SetInlineItemActivation(&wgui_inline_items[item_index], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemTextEdit(
                &wgui_inline_items[item_index],
                (PU8) pbHomeNumber,
                MAX_PB_NUMBER_LENGTH + 1,
                INPUT_TYPE_PHONE_NUMBER | INPUT_TYPE_PLUS_CHARACTER_HANDLING);
            DisableInlineItemHighlight(&wgui_inline_items[item_index]);
            string_list[item_index] = STR_ID_PHB_ANR_1;
            image_list[item_index] = IMG_ID_PHB_ANR;
    #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[item_index], string_list[item_index]);
    #endif 

            break;

      /*--- Email Field ---*/
        case MMI_PHB_USIM_FIELD_EMAIL:
            SetInlineItemActivation(&wgui_inline_items[item_index], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemTextEdit(
                &wgui_inline_items[item_index],
                (PU8) pbEmailAddress,
                g_phb_cntx.email_length + 1,
                INPUT_TYPE_ALPHANUMERIC_LOWERCASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES);
    #if defined(__MMI_TOUCH_SCREEN__)
            SetInlineTextEditCustomFunction(&wgui_inline_items[item_index], mmi_phb_op_email_custom_function);
    #endif
            DisableInlineItemHighlight(&wgui_inline_items[item_index]);
            string_list[item_index] = STR_EMAIL_ADRESS;
            image_list[item_index] = IMG_EMAIL_ADDRESS;
    #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[item_index], string_list[item_index]);
    #endif 

            break;
      /*--- ANRB Field ---*/
        case MMI_PHB_USIM_FIELD_ANRB:
            SetInlineItemActivation(&wgui_inline_items[item_index], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemTextEdit(
                &wgui_inline_items[item_index],
                (PU8) pbOfficeNumber,
                MAX_PB_NUMBER_LENGTH + 1,
                INPUT_TYPE_PHONE_NUMBER | INPUT_TYPE_PLUS_CHARACTER_HANDLING);
            DisableInlineItemHighlight(&wgui_inline_items[item_index]);
            string_list[item_index] = STR_ID_PHB_ANR_2;
            image_list[item_index] = IMG_ID_PHB_ANR;
    #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[item_index], string_list[item_index]);
    #endif 

            break;
      /*--- ANRC Field ---*/
        case MMI_PHB_USIM_FIELD_ANRC:
            SetInlineItemActivation(&wgui_inline_items[item_index], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemTextEdit(
                &wgui_inline_items[item_index],
                (PU8) pbFaxNumber,
                MAX_PB_NUMBER_LENGTH + 1,
                INPUT_TYPE_PHONE_NUMBER | INPUT_TYPE_PLUS_CHARACTER_HANDLING);
            DisableInlineItemHighlight(&wgui_inline_items[item_index]);
            string_list[item_index] = STR_ID_PHB_ANR_3;
            image_list[item_index] = IMG_ID_PHB_ANR;
    #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[item_index], string_list[item_index]);
    #endif 

            break;
            // #endif /* #if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)*/

      /*--- Caller Group Field ---*/
        case MMI_PHB_USIM_FIELD_GROUP:
            SetInlineItemActivation(&wgui_inline_items[item_index], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemSelect(
                &wgui_inline_items[item_index],
                g_phb_cntx.gas_total + 1,
                myCallerGrpnames,
                &g_phb_cntx.selected_grp_index);
            string_list[item_index] = STR_CALLER_GROUP;
            image_list[item_index] = IMG_CALLER_GROUP;

            break;

      /*--- SNE Field ---*/
        case MMI_PHB_USIM_FIELD_SNE:
            /* Assign name length */
            if ((store_index == MAX_PB_ENTRIES && g_phb_cntx.selected_storage == MMI_SIM) ||    /* Add */
                (store_index < MAX_PB_ENTRIES && store_index >= MAX_PB_PHONE_ENTRIES))  /* Edit */
            {
                nameLength = g_phb_cntx.sim_name_len;
            }
            else
            {
                nameLength = MAX_PB_NAME_LENGTH;
            }

            SetInlineItemActivation(&wgui_inline_items[item_index], KEY_LSK, KEY_EVENT_UP);
        #if defined(__PHB_0x81_SUPPORT__)
            SetInlineItemFullScreenEdit_ext(
                &wgui_inline_items[item_index],
                STR_ID_PHB_NAME,
                IMG_SCR_PBOOK_CAPTION,
                (PU8) pbNickName,
                nameLength + 1,
                (INPUT_TYPE_ALPHANUMERIC_UPPERCASE | INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ONE_LESS_CHARACTER | INPUT_TYPE_GSM_EXTENDED_HANDLING),
                INPUT_TYPE_EXT_USE_0x81_ENCODING);
        #else /* defined(__PHB_0x81_SUPPORT__) */ 
            SetInlineItemFullScreenEdit(
                &wgui_inline_items[item_index],
                STR_ID_PHB_NAME,
                IMG_SCR_PBOOK_CAPTION,
                (PU8) pbNickName,
                nameLength + 1,
                (INPUT_TYPE_ALPHANUMERIC_UPPERCASE | INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ONE_LESS_CHARACTER | INPUT_TYPE_GSM_EXTENDED_HANDLING));
        #endif /* defined(__PHB_0x81_SUPPORT__) */ 
            SetInlineFullScreenEditCustomFunction(&wgui_inline_items[item_index], mmi_phb_set_full_scr_lsk);
            string_list[item_index] = STR_ID_PHB_SNE;
            image_list[item_index] = IMG_ID_PHB_SNE;
        #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[item_index], string_list[item_index]);
        #endif 
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_add_usim_entry_rsp
 * DESCRIPTION
 *  Handles the response from stack after the entry is saved.
 * PARAMETERS
 *  info        [IN]        Response structure
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_phb_op_add_usim_entry_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index, src_store_index = 0;
    MSG_PHB_SET_USIM_ENRTY_RSP_STRUCT *localPtr;
    U8 flag = 0;
    U8 num_ascii[MAX_PB_NUMBER_LENGTH + 1 + 1];
    U8 modified = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (MSG_PHB_SET_USIM_ENRTY_RSP_STRUCT*) info;
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_op_add_usim_entry_rsp.>\n", __FILE__,
                         __LINE__);

    if (localPtr->result.flag == 0) /* Set Entry Success */
    {
        store_index = mmi_phb_op_get_store_index_and_increase_counter(localPtr->list.storage, localPtr->list.record_index);

        mmi_ucs2_to_asc((PS8) num_ascii, (PS8) pbNumber);
        /* mmi_phb_op_update_optional_field(store_index, MMI_NVRAM, 1); */
        mmi_ucs2_to_asc((PS8) PhoneBookOptionalFields.homeNumber, pbHomeNumber);
        mmi_ucs2_to_asc((PS8) PhoneBookOptionalFields.officeNumber, pbOfficeNumber);
        mmi_ucs2_to_asc((PS8) PhoneBookOptionalFields.emailAddress, pbEmailAddress);

        /* Populate Number and ANR Field */
        flag = mmi_phb_op_increase_lookup_table(
                store_index,
                (S8*) num_ascii,
                (S8*) PhoneBookOptionalFields.faxNumber,
                (S8*) PhoneBookOptionalFields.homeNumber,
                (S8*) PhoneBookOptionalFields.officeNumber);

        if (flag)
        {
            mmi_phb_lookup_table_sort();
        }

        mmi_phb_op_set_entry_rsp_name_number(&localPtr->list, store_index);
        mmi_phb_op_set_entry_usim_fields(&PhoneBookOptionalFields, store_index);

        mmi_phb_op_update_usim_field_flag(
            store_index,
            (S8*) localPtr->list.tel.number,
            (S8*) PhoneBookOptionalFields.homeNumber,
            (S8*) PhoneBookOptionalFields.officeNumber,
            (S8*) PhoneBookOptionalFields.faxNumber,
            (S8*) PhoneBookOptionalFields.emailAddress,
            TRUE);
        if (duplicateEntry || copyEntry || moveEntry)
        {
            src_store_index = g_phb_name_index[g_phb_cntx.active_index];
            modified = PhoneBook[src_store_index].alpha_id.name_length - localPtr->list.alpha_id.name_length;
        }
        if (duplicateEntry)
        {
            g_phb_cntx.group_type[store_index - MAX_PB_PHONE_ENTRIES] =
                g_phb_cntx.group_type[g_phb_name_index[g_phb_cntx.active_index] - MAX_PB_PHONE_ENTRIES];
        }
        else if (!copyEntry && !moveEntry)
        {
            g_phb_cntx.group_type[store_index - MAX_PB_PHONE_ENTRIES] = g_phb_cntx.selected_grp_index;
        }
        else
        {
            g_phb_cntx.group_type[store_index - MAX_PB_PHONE_ENTRIES] = 0;
        }

        /* Update Pinyin Cache for sort */
    #if defined(__MMI_PHB_PINYIN_SORT__)
        mmi_phb_util_make_pinyin_cache(store_index);
    #endif 

        /* Insert name to name mapping table. */
        mmi_phb_sort_insert_name_index(store_index);

        /* Insert email to email mapping table */
    #if defined(__MMI_PHB_EMAIL_SORT__)
        if (g_phb_email_sorted == 1)
        {
            mmi_phb_sort_email_insert_index(store_index);
        }
    #endif /* defined(__MMI_PHB_EMAIL_SORT__) */ 

        /* add central command for vrsi. */
    #if defined(__MMI_VRSI__)
        mmi_vrsi_ndial_central_add_single(store_index);
    #endif 

        mmi_phb_clear_old_add_history();

    #if defined(__MMI_PHB_UPDATE_CALL_LOG_AFTER_SAVE__)     /* Update Call Log after save number */
        mmi_phb_convert_get_ucs2_number(pbNumber, store_index);
        if (g_phb_enter_from == MMI_PHB_ENTER_FROM_CALL_LOG &&
            CHISTSyncCallLogNeeded(PhoneBook[store_index].tel.length, PhoneBook[store_index].tel.type, (U8*) pbNumber))
        {
            ReqUpdateCallLogName(
                PhoneBook[store_index].alpha_id.name_length,
                PhoneBook[store_index].alpha_id.name_dcs,
                PhoneBook[store_index].alpha_id.name);
        }
        else    /* Not Enter From Call Log */
    #endif /* defined(__MMI_PHB_UPDATE_CALL_LOG_AFTER_SAVE__) */ 
        {
        #if defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC)
            if (g_phb_enter_from == MMI_PHB_ENTER_FROM_JAVA)
            {
                mmi_phb_java_write_rsp(MMI_PHB_JAVA_SUCCESS, store_index);
            }
            else
        #endif /* defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC) */ 
            {
                if (moveEntry)
                {
                    moveModified = modified;
                    mmi_phb_op_move_req();
                }
                else
                {
                #ifndef __MMI_MAINLCD_128X128__
                    if (modified)
                    {
                        DisplayPopup(
                            (PU8) GetString(STR_COPIED_NAME_MODIFIED),
                            IMG_GLOBAL_ACTIVATED,
                            TRUE,
                            PHB_NOTIFY_TIMEOUT,
                            SUCCESS_TONE);
                    }
                    else if (duplicateEntry || copyEntry)
                #else
                    if (duplicateEntry || copyEntry)
                #endif
                    {
                        DisplayPopup(
                            (PU8) GetString(STR_COPIED_TO_SIM_DONE),
                            IMG_GLOBAL_ACTIVATED,
                            TRUE,
                            PHB_NOTIFY_TIMEOUT,
                            SUCCESS_TONE);
                    }
                    else
                    {
                        DisplayPopup(
                            (PU8) GetString(STR_GLOBAL_DONE),
                            IMG_GLOBAL_ACTIVATED,
                            TRUE,
                            PHB_NOTIFY_TIMEOUT,
                            SUCCESS_TONE);
                    }
                }
            }
        }
        g_phb_cntx.refresh_list = MMI_PHB_ENTRY_REFRESH;

    #if defined(__MMI_VCARD__)
        if (g_phb_enter_from == MMI_PHB_ENTER_FROM_IDLE_SCREEN)
        {
            DeleteScreenIfPresent(SCR_ID_VCARD_RECV_VIEW_DETAIL);
            DeleteScreenIfPresent(SCR_ID_VCARD_RECV_OPT);
            DeleteScreenIfPresent(SCR_ID_VOBJ_RECV_OBJECT);
            mmi_vobj_clear_one_file_buffer();
        }
    #endif /* defined(__MMI_VCARD__) */ 
    }
#if defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC)
    else if (g_phb_enter_from == MMI_PHB_ENTER_FROM_JAVA)
    {
        if (localPtr->result.cause >= MMI_PHB_USIM_ANR_FULL && localPtr->result.cause <= MMI_PHB_USIM_SNE_FULL)
        {
            mmi_phb_java_write_rsp(MMI_PHB_JAVA_STORAGE_FULL, 0xffff);
        }
        else
        {
            mmi_phb_java_write_rsp(localPtr->result.cause, 0xffff);
        }
    }
#endif /* defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC) */ 
    else    /* Set Record Fail. */
    {
        if (localPtr->result.cause == MMI_SIM_EF_RECORD_FULL)   /* Number Too Long */
        {
            if (copyEntry)
            {
                DisplayPopup(
                    (PU8) GetString(STR_NOT_COPIED_NUMBER_TOO_LONG),
                    IMG_GLOBAL_ERROR,
                    FALSE,
                    PHB_NOTIFY_TIMEOUT,
                    ERROR_TONE);
            }
            else if (moveEntry)
            {
                DisplayPopup(
                    (PU8) GetString(STR_NOT_MOVED_NUMBER_TOO_LONG),
                    IMG_GLOBAL_ERROR,
                    FALSE,
                    PHB_NOTIFY_TIMEOUT,
                    ERROR_TONE);
            }
            else if (duplicateEntry)
            {
                DisplayPopup(
                    (PU8) GetString(STR_NOT_DUPLICATED_NUMBER_TOO_LONG),
                    IMG_GLOBAL_ERROR,
                    FALSE,
                    PHB_NOTIFY_TIMEOUT,
                    ERROR_TONE);
            }
            else
            {
                DisplayPopup(
                    (PU8) GetString(STR_NOT_SAVED_NUMBER_TOO_LONG),
                    IMG_GLOBAL_ERROR,
                    FALSE,
                    PHB_NOTIFY_TIMEOUT,
                    ERROR_TONE);
            }
        #if defined(__MMI_VCARD__)
            if (g_phb_enter_from == MMI_PHB_ENTER_FROM_IDLE_SCREEN)
            {
                DeleteUptoScrID(SCR_ID_VCARD_RECV_OPT);
            }
            else
        #endif /* defined(__MMI_VCARD__) */ 
                DeleteUptoScrID(SCR_ADD_NEW_ENTRY);
        }
        else if (localPtr->result.cause == MMI_PHB_USIM_EMAIL_FULL)     /* Email Full */
        {
            if (duplicateEntry)
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_PHB_NOT_DUPLICATED_EMAIL_FULL),
                    IMG_GLOBAL_ERROR,
                    FALSE,
                    PHB_NOTIFY_TIMEOUT,
                    ERROR_TONE);
            }
            else
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_PHB_NOT_SAVED_EMAIL_FULL),
                    IMG_GLOBAL_ERROR,
                    FALSE,
                    PHB_NOTIFY_TIMEOUT,
                    ERROR_TONE);
            }
        #if defined(__MMI_VCARD__)
            if (g_phb_enter_from == MMI_PHB_ENTER_FROM_IDLE_SCREEN)
            {
                DeleteUptoScrID(SCR_ID_VCARD_RECV_OPT);
            }
            else
        #endif /* defined(__MMI_VCARD__) */ 
                DeleteUptoScrID(SCR_ADD_NEW_ENTRY);
        }
        else if (localPtr->result.cause == MMI_PHB_USIM_ANR_FULL)       /* ANR Number Full */
        {
            if (duplicateEntry)
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_PHB_NOT_DUPLICATED_ANR_FULL),
                    IMG_GLOBAL_ERROR,
                    FALSE,
                    PHB_NOTIFY_TIMEOUT,
                    ERROR_TONE);
            }
            else
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_PHB_NOT_SAVED_ANR_FULL),
                    IMG_GLOBAL_ERROR,
                    FALSE,
                    PHB_NOTIFY_TIMEOUT,
                    ERROR_TONE);
            }
        #if defined(__MMI_VCARD__)
            if (g_phb_enter_from == MMI_PHB_ENTER_FROM_IDLE_SCREEN)
            {
                DeleteScreenIfPresent(SCR_ID_VCARD_RECV_VIEW_DETAIL);
                DeleteScreenIfPresent(SCR_ID_VCARD_RECV_OPT);
                DeleteScreenIfPresent(SCR_ID_VOBJ_RECV_OBJECT);
            }
            else
        #endif /* defined(__MMI_VCARD__) */ 
                DeleteUptoScrID(SCR_ADD_NEW_ENTRY);
        }
        else if (gSecuritySetupContext.FdlStatus)   /* For FDN is on, can't set entry */
        {
            DisplayPopup((PU8) GetString(STR_FDL_IS_ON), IMG_GLOBAL_UNFINISHED, TRUE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
            mmi_phb_clear_old_add_history();
        }
        else    /* Unknown Error */
        {
            DisplayPopup(
                (PU8) GetString(STR_GLOBAL_UNFINISHED),
                IMG_GLOBAL_UNFINISHED,
                TRUE,
                PHB_NOTIFY_TIMEOUT,
                ERROR_TONE);
            mmi_phb_clear_old_add_history();
        }
    }
    g_phb_enter_from = MMI_PHB_ENTER_NONE;
    copyEntry = duplicateEntry = moveEntry = FALSE;
    g_phb_cntx.current_op = MMI_PHB_OP_NONE;  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_edit_usim_entry_rsp
 * DESCRIPTION
 *  Response handler for entry edit request
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_edit_usim_entry_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_SET_USIM_ENRTY_RSP_STRUCT *localPtr;
    U16 deletedCnt = 0;
    U8 flag = 0;
    U16 store_index;
    U16 record_index;
    U8 storage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (MSG_PHB_SET_USIM_ENRTY_RSP_STRUCT*) info;
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_op_edit_usim_entry_rsp.>\n", __FILE__,
                         __LINE__);

    if (localPtr->result.flag == 0) /* Edit Entry OK */
    {
        store_index = g_phb_name_index[g_phb_cntx.active_index];
        storage = (store_index >= MAX_PB_PHONE_ENTRIES) ? MMI_SIM : MMI_NVRAM;
        record_index = (storage == MMI_SIM) ? (store_index + 1) - MAX_PB_PHONE_ENTRIES : (store_index + 1);

        PhbUpdateSpeedDial(storage, record_index, MMI_PHB_PHONEBOOK, (U8*) pbName, (U8*) pbNumber);

        /* Clear lookup table first, add later if exists. */
        deletedCnt = mmi_phb_op_clear_lookup_table_by_index(store_index);

        mmi_ucs2_to_asc((PS8) PhoneBookOptionalFields.homeNumber, pbHomeNumber);
        mmi_ucs2_to_asc((PS8) PhoneBookOptionalFields.officeNumber, pbOfficeNumber);
        mmi_ucs2_to_asc((PS8) PhoneBookOptionalFields.emailAddress, pbEmailAddress);

        /* Populate Number and ANR Field */
        flag += mmi_phb_op_increase_lookup_table(
                    store_index,
                    (S8*) localPtr->list.tel.number,
                    (S8*) PhoneBookOptionalFields.faxNumber,
                    (S8*) PhoneBookOptionalFields.homeNumber,
                    (S8*) PhoneBookOptionalFields.officeNumber);

        if (deletedCnt || flag)
        {
            mmi_phb_lookup_table_sort();
            g_phb_cntx.lookup_table_count -= deletedCnt;
        }

        mmi_phb_op_set_entry_rsp_name_number(&localPtr->list, store_index);
        mmi_phb_op_set_entry_usim_fields(&PhoneBookOptionalFields, store_index);

        /* Update is column exists flag. */
        mmi_phb_op_update_usim_field_flag(
            store_index,
            (S8*) localPtr->list.tel.number,
            (S8*) PhoneBookOptionalFields.homeNumber,
            (S8*) PhoneBookOptionalFields.officeNumber,
            (S8*) PhoneBookOptionalFields.faxNumber,
            (S8*) PhoneBookOptionalFields.emailAddress,
            TRUE);
        if (PhoneBook[store_index].alpha_id.name_length)
        {
            PhoneBook[store_index].field |= MMI_PHB_ENTRY_FIELD_NAME;
        }
        g_phb_cntx.group_type[store_index - MAX_PB_PHONE_ENTRIES] = g_phb_cntx.selected_grp_index;

    #if defined(__MMI_PHB_PINYIN_SORT__)    /* Update Pinyin Cache for sort */
        mmi_phb_util_make_pinyin_cache(store_index);
    #endif 

        /* Name sorting mapping table should Re-Sort HERE, and get the new highlight position!!! */
        mmi_phb_op_delete_update_index(store_index);
        g_phb_cntx.new_highlight_entry = mmi_phb_sort_insert_name_index(store_index);
        g_phb_cntx.refresh_list = MMI_PHB_ENTRY_REFRESH;

        /* Update email sorting mapping table */
    #if defined(__MMI_PHB_EMAIL_SORT__)
        if (g_phb_email_sorted == 1)
        {
            mmi_phb_sort_email_delete_index(store_index);
            mmi_phb_sort_email_insert_index(store_index);
        }
    #endif /* defined(__MMI_PHB_EMAIL_SORT__) */ 

        /* add central command for vrsi. */
    #if defined(__MMI_VRSI__)
        mmi_vrsi_ndial_central_change_single(store_index);
    #endif 

    #if defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC)
        if (g_phb_enter_from == MMI_PHB_ENTER_FROM_JAVA)
        {
            mmi_phb_java_write_rsp(MMI_PHB_JAVA_SUCCESS, store_index);
            g_phb_enter_from = MMI_PHB_ENTER_NONE;
        }
        else
    #endif /* defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC) */ 
        {
            DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, TRUE, PHB_NOTIFY_TIMEOUT, SUCCESS_TONE);
            mmi_phb_clear_old_edit_history();
        }
    }
#if defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC)
	else if(g_phb_enter_from == MMI_PHB_ENTER_FROM_JAVA )
	{
			mmi_phb_java_write_rsp(localPtr->result.cause, 0xffff);
            g_phb_enter_from = MMI_PHB_ENTER_NONE;
	}
#endif
    else if (localPtr->result.cause == MMI_SIM_EF_RECORD_FULL)
    {
        DisplayPopup(
            (PU8) GetString(STR_NOT_SAVED_NUMBER_TOO_LONG),
            IMG_GLOBAL_ERROR,
            FALSE,
            PHB_NOTIFY_TIMEOUT,
            ERROR_TONE);
        DeleteUptoScrID(SCR_INLINE_EDIT);
    }
    else if (localPtr->result.cause == MMI_PHB_USIM_EMAIL_FULL)     /* Email Full */
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_PHB_NOT_SAVED_EMAIL_FULL),
            IMG_GLOBAL_ERROR,
            FALSE,
            PHB_NOTIFY_TIMEOUT,
            ERROR_TONE);
        DeleteUptoScrID(SCR_INLINE_EDIT);
    }
    else if (localPtr->result.cause == MMI_PHB_USIM_ANR_FULL)       /* ANR Number Full */
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_PHB_NOT_SAVED_ANR_FULL),
            IMG_GLOBAL_ERROR,
            FALSE,
            PHB_NOTIFY_TIMEOUT,
            ERROR_TONE);
        DeleteUptoScrID(SCR_INLINE_EDIT);
    }
    else
    {
        if (gSecuritySetupContext.FdlStatus)    /* For FDN on Message */
        {
            DisplayPopup(
                (PU8) GetString(STR_FDL_IS_ON),
                IMG_GLOBAL_UNFINISHED,
                TRUE,
                PHB_NOTIFY_TIMEOUT,
                ERROR_TONE);
        }
        else
        {
            DisplayPopup(
                (PU8) GetString(STR_GLOBAL_UNFINISHED),
                IMG_GLOBAL_UNFINISHED,
                TRUE,
                PHB_NOTIFY_TIMEOUT,
                ERROR_TONE);
        }
        mmi_phb_clear_old_edit_history();
    }
    g_phb_cntx.current_op = MMI_PHB_OP_NONE;  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_add_usim_entry_req
 * DESCRIPTION
 *  Sends the request to the stack to save the information of a phonebook entry.
 * PARAMETERS
 *  void
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_phb_op_add_usim_entry_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_SET_USIM_ENRTY_REQ_STRUCT *myMsgPtr;
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_op_add_usim_entry_req.>\n", __FILE__,
                         __LINE__);

#if defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC)
    if (g_phb_enter_from != MMI_PHB_ENTER_FROM_JAVA)
#endif 
    {
        g_phb_cntx.current_op = MMI_PHB_OP_ADD;  
        mmi_phb_show_in_progress(STR_GLOBAL_SAVING, IMG_GLOBAL_SAVE);
    }

    myMsgPtr = (MSG_PHB_SET_USIM_ENRTY_REQ_STRUCT*) OslConstructDataPtr(sizeof(MSG_PHB_SET_USIM_ENRTY_REQ_STRUCT));
    myMsgPtr->type = MMI_PHB_PHONEBOOK;
    myMsgPtr->no_data = 1;
    myMsgPtr->list.index = 0xFFFF;
    myMsgPtr->list.record_index = 0xFFFF;
    myMsgPtr->list.storage = g_phb_cntx.selected_storage;
    myMsgPtr->anra.record_index = 0xFFFF;
    myMsgPtr->anrb.record_index = 0xFFFF;
    myMsgPtr->anrc.record_index = 0xFFFF;
    myMsgPtr->email.adn_record_index = 0xFFFF;

    mmi_phb_op_set_entry_prepare_name_number(&myMsgPtr->list, pbName, pbNumber);
    mmi_phb_op_set_entry_prepare_usim_data(
        myMsgPtr,
        pbNickName,
        pbHomeNumber,
        pbOfficeNumber,
        pbFaxNumber,
        pbEmailAddress);
    myMsgPtr->group_type = g_phb_cntx.selected_grp_index;
    /* myMsgPtr->hidden_info = ; */
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_PHB_WRITE_USIM_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler(mmi_phb_op_add_usim_entry_rsp, PRT_PHB_WRITE_USIM_RSP);
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_edit_usim_entry_req
 * DESCRIPTION
 *  Sends the request to L4 to save the entry
 *  edited by the user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_edit_usim_entry_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_SET_USIM_ENRTY_REQ_STRUCT *myMsgPtr;
    MYQUEUE Message;
    U16 store_index;
    U8 storage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_op_edit_usim_entry_req.>\n", __FILE__,
                         __LINE__);

#if defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC)
    if (g_phb_enter_from == MMI_PHB_ENTER_FROM_JAVA)
    {
        store_index = g_phb_cntx.java_store_index;
    }
    else
#endif /* defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC) */
    {
        g_phb_cntx.current_op = MMI_PHB_OP_EDIT;  
        mmi_phb_show_in_progress(STR_GLOBAL_SAVING, IMG_GLOBAL_SAVE);
        store_index = g_phb_name_index[g_phb_cntx.active_index];
    }
    storage = (store_index >= MAX_PB_PHONE_ENTRIES) ? MMI_SIM : MMI_NVRAM;

    myMsgPtr = (MSG_PHB_SET_USIM_ENRTY_REQ_STRUCT*) OslConstructDataPtr(sizeof(MSG_PHB_SET_USIM_ENRTY_REQ_STRUCT));
    myMsgPtr->type = MMI_PHB_PHONEBOOK;
    myMsgPtr->no_data = 1;
    myMsgPtr->list.storage = storage;
    myMsgPtr->list.index = 0xffff;
    myMsgPtr->list.record_index = (storage == MMI_SIM) ? (store_index + 1) - MAX_PB_PHONE_ENTRIES : (store_index + 1);

    mmi_phb_op_set_entry_prepare_name_number(&myMsgPtr->list, pbName, pbNumber);
    mmi_phb_op_set_entry_prepare_usim_data(
        myMsgPtr,
        pbNickName,
        pbHomeNumber,
        pbOfficeNumber,
        pbFaxNumber,
        pbEmailAddress);

    myMsgPtr->group_type = g_phb_cntx.selected_grp_index;
    // TODO: hidden info
    //myMsgPtr->hidden_info = ;
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_PHB_WRITE_USIM_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler(mmi_phb_op_edit_usim_entry_rsp, PRT_PHB_WRITE_USIM_RSP);
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_copy_move_dup_usim_req
 * DESCRIPTION
 *  Sends the request to the stack to copy/move/duplicate an entry that the user selects from the phonebook list.
 *  that the user selects from the phonebook list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_copy_move_dup_usim_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_SET_USIM_ENRTY_REQ_STRUCT *myMsgPtr;
    MYQUEUE Message;
    U16 store_index;
    U8 storage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_op_copy_move_dup_usim_req.>\n", __FILE__,
                         __LINE__);

    store_index = g_phb_name_index[g_phb_cntx.active_index];
    storage = (store_index >= MAX_PB_PHONE_ENTRIES) ? MMI_SIM : MMI_NVRAM;

    myMsgPtr = (MSG_PHB_SET_USIM_ENRTY_REQ_STRUCT*) OslConstructDataPtr(sizeof(MSG_PHB_SET_USIM_ENRTY_REQ_STRUCT));
    myMsgPtr->type = MMI_PHB_PHONEBOOK;
    myMsgPtr->no_data = 1;
    myMsgPtr->list.index = 0xFFFF;
    myMsgPtr->list.record_index = 0xFFFF;

    if (copyEntry)
    {
        mmi_phb_show_in_progress(STR_GLOBAL_COPYING, IMG_COPIED);
        if (storage == MMI_SIM)
        {
            myMsgPtr->list.storage = MMI_NVRAM;
        }
        else
        {
            myMsgPtr->list.storage = MMI_SIM;
        }
    }
    else if (duplicateEntry)
    {
        mmi_phb_show_in_progress(STR_PHB_DUPLICATING, IMG_ENTRY_DUPLICATED_MSG);
        myMsgPtr->list.storage = storage;
    }
    else if (moveEntry)
    {
        moveEntryStoreIndex = store_index;

        mmi_phb_show_in_progress(STR_GLOBAL_MOVING, IMG_ENTRY_MOVED_MSG);
        if (storage == MMI_SIM)
        {
            myMsgPtr->list.storage = MMI_NVRAM;
        }
        else
        {
            myMsgPtr->list.storage = MMI_SIM;
        }
    }

    mmi_phb_op_set_entry_prepare_name_number_by_index(&myMsgPtr->list, store_index);
    mmi_phb_op_set_entry_prepare_usim_data_by_index(store_index);
    mmi_phb_op_set_entry_prepare_usim_data(
        myMsgPtr,
        pbNickName,
        pbHomeNumber,
        pbOfficeNumber,
        pbFaxNumber,
        pbEmailAddress);

    if (duplicateEntry)
    {
        myMsgPtr->group_type = g_phb_cntx.group_type[store_index - MAX_PB_PHONE_ENTRIES];
    }
    else
    {
        myMsgPtr->group_type = 0;
    }

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_PHB_WRITE_USIM_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler(mmi_phb_op_add_usim_entry_rsp, PRT_PHB_WRITE_USIM_RSP);
    OslMsgSendExtQueue(&Message);
    DeleteNScrId(SCR_PBOOK_ENTRY_OPTIONS);
}
#endif /* __MMI_PHB_USIM_FIELD__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_pre_entry_op_add_entry
 * DESCRIPTION
 *  check before add entry.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_pre_entry_op_add_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_PRE_ENTRY_OP_ADD_ENTRY);

    if (((g_phb_cntx.selected_storage == MMI_SIM) && (gSecuritySetupContext.FdlStatus))
#ifdef __MMI_DUAL_SIM_MASTER__
        || (g_phb_cntx.selected_storage == MMI_SIM2) && (MTPNP_AD_FDN_GetStatus())
#endif
        )
    {
        DisplayPopup((PU8) GetString(STR_FDL_IS_ON), IMG_GLOBAL_UNFINISHED, TRUE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
        return;
    }
    else
    {
        mmi_phb_entry_op_add_entry();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_op_add_entry
 * DESCRIPTION
 *  Draws the new entry screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_op_add_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;
    U16 DetailPbNameImageList[MAX_PB_FIELDS];
    U16 image_id;
    U8 field_index, item_index = 0;;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_entry_op_add_entry.>\n", __FILE__,
                         __LINE__);
#if defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT)
    if (g_phb_enter_from == MMI_PHB_ENTER_FROM_WAP)
    {
        mmi_jdd_tapi_get_phb_name_number(pbName, pbNumber, g_phb_cntx.selected_storage);
    }
#endif /* defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT) */

    EntryNewScreen(SCR_ADD_NEW_ENTRY, mmi_phb_exit_op_add_entry, NULL, NULL);
    InitializeCategory57Screen();
    guiBuffer = GetCurrGuiBuffer(SCR_ADD_NEW_ENTRY);
    inputBuffer = GetCurrNInputBuffer(SCR_ADD_NEW_ENTRY, &inputBufferSize);

    RegisterHighlightHandler(mmi_phb_op_edit_highlight_hdlr);

#ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
    EnableInlineItemDefaultText();
#endif 
    if (g_phb_cntx.selected_storage == MMI_SIM && g_phb_cntx.sim_name_len < MAX_PB_NAME_LENGTH)
    {
        mmi_phb_truncate_pbname_buffer(MMI_SIM);
    }
#ifdef __MMI_DUAL_SIM_MASTER__
   if (g_phb_cntx.selected_storage == MMI_SIM2)
   {    
        U16 store_index;
        card2_mmi_phb_op_fill_inline_item(MMI_PHB_FIELD_NAME, item_index++, store_index, TitleStrings, DetailPbNameImageList);
        card2_mmi_phb_op_fill_inline_item(MMI_PHB_FIELD_NUMBER, item_index++, store_index, TitleStrings, DetailPbNameImageList);
   }
   else
   {
#endif	/* __MMI_DUAL_SIM_MASTER__ */
    mmi_phb_op_fill_inline_item(MMI_PHB_FIELD_NAME, item_index++, MAX_PB_ENTRIES, TitleStrings, DetailPbNameImageList);
    mmi_phb_op_fill_inline_item(
        MMI_PHB_FIELD_NUMBER,
        item_index++,
        MAX_PB_ENTRIES,
        TitleStrings,
        DetailPbNameImageList);
#ifdef __MMI_DUAL_SIM_MASTER__
   }
#endif	/* __MMI_DUAL_SIM_MASTER__ */
    gPictureItemIndex = 0xff;   /* Set to default before use. */
    gRingtoneItemIndex = 0xff;
#if defined(__MMI_INCOMING_CALL_VIDEO__)
    g_phb_video_item_index = 0xff;
#endif 

    if (g_phb_cntx.selected_storage == MMI_SIM)
    {
    #if defined(__MMI_PHB_CALLERGROUP_IN_SIM__)     /* Associate caller group in SIM card entry */
        mmi_phb_build_caller_group_list();
        mmi_phb_op_fill_inline_item(
            MMI_PHB_FIELD_GROUP,
            item_index++,
            MAX_PB_ENTRIES,
            TitleStrings,
            DetailPbNameImageList);
    #elif defined(__MMI_PHB_USIM_FIELD__)
        mmi_phb_build_usim_group_list();
        /* Fill inline item for each field */
        for (field_index = (MMI_PHB_USIM_FIELD_ANRA); field_index < MMI_PHB_USIM_FIELD_TOTAL; field_index++)
        {
            if (g_phb_cntx.support_field[field_index])
            {
                mmi_phb_op_fill_usim_inline_item(
                    field_index,
                    item_index++,
                    MAX_PB_ENTRIES,
                    TitleStrings,
                    DetailPbNameImageList);
            }
        }
    #endif 
        if (inputBuffer != NULL)
        {
            SetCategory57Data(wgui_inline_items, item_index, inputBuffer);
        }
    #ifdef __MMI_DUAL_SIM_MASTER__
        image_id = IMG_ID_CARD1_PHB_STORAGE_SIM;    
    #else /* __MMI_DUAL_SIM_MASTER__ */
        image_id = IMG_STORAGE_SIM;
    #endif /* __MMI_DUAL_SIM_MASTER__ */
    }
#ifdef __MMI_DUAL_SIM_MASTER__
   else if (g_phb_cntx.selected_storage == MMI_SIM2)
   {  
        if(inputBuffer!=NULL)
        {
        SetCategory57Data(wgui_inline_items, item_index, inputBuffer);
        }
        image_id = IMG_ID_CARD2_PHB_STORAGE_SIM;
   }
#endif	/* __MMI_DUAL_SIM_MASTER__ */

    else
    {
        mmi_phb_build_ring_tone_list();
        mmi_phb_build_image_list();
        mmi_phb_build_caller_group_list();
    #if defined(__MMI_INCOMING_CALL_VIDEO__)
        mmi_phb_build_video_list();

        if (guiBuffer == NULL)  /* First Time Enter */
        {
            if (g_phb_cntx.set_done_flag != 2)  /* Not Enter From File Manager */
            {
                g_phb_cntx.video_location = MMI_PHB_IMAGE_NO_SELECT;
            }
            g_phb_cntx.video_audio = 1;
            g_phb_video_view = FALSE;
        }

        if (g_phb_cntx.video_location != MMI_PHB_IMAGE_NO_SELECT)       /* Change Inline select prompt message. */
        {
        #if defined(__MMI_AVATAR__) || defined(__MMI_SWFLASH__)
        #ifdef __MMI_AVATAR__
            if (g_phb_cntx.selected_video_index == (g_phb_cntx.total_video_id - g_phb_avatar_video_minus) &&
                g_phb_cntx.video_location == MMI_PHB_AVATAR_SELECT_PATH)
            {
                g_phb_cntx.video_name_list[g_phb_cntx.total_video_id - g_phb_avatar_video_minus] = 
                    (U8*)GetString(STR_ID_PHB_AVATAR_SELECTED);
                g_phb_cntx.video_location = MMI_PHB_AVATAR_SELECT_PATH;
            }
            else
        #endif /* __MMI_AVATAR__ */
        #ifdef __MMI_SWFLASH__
            if (g_phb_cntx.selected_video_index == (g_phb_cntx.total_video_id - g_phb_swflash_video_minus) &&
                g_phb_cntx.video_location == MMI_PHB_SWFLASH_SELECT_PATH)
            {
                g_phb_cntx.video_name_list[g_phb_cntx.total_video_id - g_phb_swflash_video_minus] = 
                    (U8*)GetString(STR_ID_PHB_FMGR_IMAGE_SELECTED);
                g_phb_cntx.video_location = MMI_PHB_SWFLASH_SELECT_PATH;
            }
            else
        #endif /* __MMI_SWFLASH__ */
             if (g_phb_cntx.selected_video_index == (g_phb_cntx.total_video_id - 1)
        #ifdef __MMI_AVATAR__             
                && g_phb_cntx.video_location != MMI_PHB_AVATAR_SELECT_PATH
        #endif
        #ifdef __MMI_SWFLASH__             
                && g_phb_cntx.video_location != MMI_PHB_SWFLASH_SELECT_PATH
        #endif
                )
        #endif /* defined(__MMI_AVATAR__) || defined(__MMI_SWFLASH__) */
            {
                g_phb_cntx.video_name_list[g_phb_cntx.total_video_id - 1] =
                    (U8*) GetString(STR_ID_PHB_FMGR_IMAGE_SELECTED);
            }
        }
    #endif /* defined(__MMI_INCOMING_CALL_VIDEO__) */ 

    #if defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__)
        if ((guiBuffer == NULL) && (g_phb_cntx.set_done_flag != 2))     /* First Time Enter and Not Enter From File Manager */
        {
            g_phb_cntx.image_location = MMI_PHB_IMAGE_NO_SELECT;
        }

    #ifdef __MMI_AVATAR__
        if (g_phb_cntx.selected_pic_index == (g_phb_cntx.total_image_id - 2) &&
            g_phb_cntx.image_location == MMI_PHB_AVATAR_SELECT_PATH)   
        {
            g_phb_cntx.image_name_list[g_phb_cntx.total_image_id - 2] = 
                (U8*)GetString(STR_ID_PHB_AVATAR_SELECTED);
            g_phb_cntx.image_location = MMI_PHB_AVATAR_SELECT_PATH;
        }
        else
    #endif  /* ifdef __MMI_AVATAR__ */
        if (g_phb_cntx.selected_pic_index == (g_phb_cntx.total_image_id - 1) 
    #ifdef __MMI_AVATAR__
            && g_phb_cntx.image_location != MMI_PHB_AVATAR_SELECT_PATH
    #endif /* def __MMI_AVATAR__ */
            && g_phb_cntx.image_location != MMI_PHB_IMAGE_NO_SELECT) /* Change Inline select prompt message. */
        {
            g_phb_cntx.image_name_list[g_phb_cntx.total_image_id - 1] =
                (U8*) GetString(STR_ID_PHB_FMGR_IMAGE_SELECTED);
        }
    #endif /* defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__) */ 

        /* Fill inline item for each field */
        for (field_index = (MMI_PHB_FIELD_NUMBER + 1); field_index < MMI_PHB_FIELD_TOTAL; field_index++)
        {
            if (g_phb_cntx.view_field[field_index - (MMI_PHB_FIELD_NUMBER + 1)])
            {
                mmi_phb_op_fill_inline_item(
                    field_index,
                    item_index++,
                    MAX_PB_ENTRIES,
                    TitleStrings,
                    DetailPbNameImageList);
            }
        }
    #ifdef __MMI_VOIP__
        if (g_phb_enter_from == MMI_PHB_ENTER_FROM_VOIP)
        {
            SetInlineItemActivation(&wgui_inline_items[item_index], KEY_LSK, KEY_EVENT_UP);
            SetInlineItemFullScreenEdit(
                &wgui_inline_items[item_index],
                STR_ID_PHB_VOIP_ID,
                IMG_SCR_PBOOK_CAPTION,
                (PU8) pbVoip,
                VOIP_URI_LEN, /* already has 1 byte NULL terminate */
                INPUT_TYPE_ALPHANUMERIC_LOWERCASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_OVERRIDE_DEFAULT);
            SetInlineFullScreenEditCustomFunction(
                &wgui_inline_items[item_index], mmi_phb_set_full_scr_lsk);
            TitleStrings[item_index] = STR_ID_PHB_VOIP_ID;
            DetailPbNameImageList[item_index] = IMG_ID_PHB_VOIP;
    #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[item_index], TitleStrings[item_index]);
    #endif 
            item_index++;
        }
    #endif /* __MMI_VOIP__ */
        if (inputBuffer != NULL)
        {
            SetCategory57Data(wgui_inline_items, item_index, inputBuffer);
            mmi_phb_op_reconfig_inline_item(guiBuffer);
        }

        image_id = IMG_STORAGE_HANDSET;
    }
    /* if title bar is thick, then use the root title icon */ 
#ifdef GUI_SUBMENU_USE_THICK_TITLE
    image_id = GetRootTitleIcon(MAIN_MENU_PHONEBOOK_MENUID);
#endif
    ShowCategory57Screen(
        STR_SCR_ADD_NEW_ENTRY_CAPTION,
        image_id,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        item_index,
        DetailPbNameImageList,
        wgui_inline_items,
        0,
        guiBuffer);

    if (g_phb_cntx.set_done_flag)
    {
        g_phb_cntx.set_done_flag = 0;
        set_wgui_inline_list_menu_changed();
    }
    SetCategory57RightSoftkeyFunctions(mmi_phb_entry_op_add_entry_confirm, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_op_add_entry
 * DESCRIPTION
 *  Exit function for mmi_phb_entry_op_add_entry()
 * PARAMETERS
 *  void
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_phb_exit_op_add_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_VOIP__
    history h;
    U16 inputBufferSize;
#endif /* !__MMI_VOIP__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.end_scr_id = SCR_ADD_NEW_ENTRY;

    mmi_phb_stop_ring_tone_id();
    CloseCategory57Screen();
#ifdef __MMI_VOIP__
    AddHistoryEx(
        SCR_ADD_NEW_ENTRY,
        mmi_phb_entry_op_add_entry,
        GetCategoryHistory,
        GetCategory57DataSize,
        GetCategory57Data,
        mmi_phb_allocate_history_data_dummy,
        mmi_phb_free_history_data_dummy);
#else
    h.scrnID = SCR_ADD_NEW_ENTRY;
    h.entryFuncPtr = mmi_phb_entry_op_add_entry;
    GetCategoryHistory(h.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, inputBufferSize);
#endif /* __MMI_VOIP__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_check_valid_number
 * DESCRIPTION
 *  Check if number fields contain invalid '+' character.
 * PARAMETERS
 *  number      [IN]        Input number string
 * RETURNS
 *  TRUE, if number format is correct.
 *****************************************************************************/
BOOL mmi_phb_op_check_valid_number(S8 *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen(number) == 0)
    {
        return TRUE;
    }
#ifdef __MMI_DUAL_SIM_MASTER__
    if (CheckValidEmergencyNo1(number, SIM1) || CheckValidEmergencyNo1(number, SIM2))
#else
    if (CheckValidEmergencyNo1(number))
#endif
    {
        return TRUE;
    }
    else
    {
        return ((UCS2StrFirstPositionSearch(number)) &
            (UCS2StrNoFirstPositionSearch(number, 'p')) &
            (UCS2StrNoFirstPositionSearch(number, 'w')));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_check_pre_save
 * DESCRIPTION
 *  Checks for mandatory fields for phonebook entry
 * PARAMETERS
 *  popup_error      [IN]        Popup error string
 * RETURNS
 *  the description of return value, if any.
 *****************************************************************************/
BOOL mmi_phb_op_check_pre_save(BOOL popup_error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Require both name "and" numbe fields */
#if defined(__MMI_PHB_NAME_AND_NUM_REQUIRE__)
    if (!mmi_ucs2strlen(pbName) && !mmi_phb_calculate_number_valid_length(pbNumber))
    {
        str_id = STR_ID_PHB_NAME_NUM_REQUIRE;
    }
    else if (!mmi_ucs2strlen(pbName))
    {
        str_id = STR_ID_PHB_NAME_REQUIRE;
    }
    else if (!mmi_phb_calculate_number_valid_length(pbNumber))
    {
        str_id = STR_ID_PHB_NUM_REQUIRE;
    }
#else /* defined(__MMI_PHB_NAME_AND_NUM_REQUIRE__) */ /* Require Name "or" Number field */
    if (!mmi_ucs2strlen(pbName) && !mmi_phb_calculate_number_valid_length(pbNumber))
    {
        str_id = STR_ID_PHB_NAME_NUM_REQUIRE;
    }
#endif /* defined(__MMI_PHB_NAME_AND_NUM_REQUIRE__) */ 
    else if (!mmi_phb_op_check_valid_number(pbNumber)
    #if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) || defined(__MMI_PHB_USIM_FIELD__)
        || !mmi_phb_op_check_valid_number(pbHomeNumber)
        || !mmi_phb_op_check_valid_number(pbOfficeNumber)
        || !mmi_phb_op_check_valid_number(pbFaxNumber)
    #endif /* !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) || defined(__MMI_PHB_USIM_FIELD__) */
        )
    {
        str_id = STR_ID_PHB_NUM_INVALID;
    }

    if (str_id != 0)
    {
        if (popup_error)
        {
            DisplayPopup((PU8) GetString(str_id), IMG_GLOBAL_ERROR, FALSE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
        }
        return FALSE;
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_add_pre_save
 * DESCRIPTION
 *  Checks for mandatory fields in a new entry
 * PARAMETERS
 *  void
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_phb_op_add_pre_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_phb_op_check_pre_save(TRUE))
    {
        return;
    }

#ifdef __MMI_PHB_USIM_FIELD__
    if (g_phb_cntx.is_usim && g_phb_cntx.selected_storage == PHB_SIM)
    {
        mmi_phb_op_add_usim_entry_req();
    }
    else
#endif /* __MMI_PHB_USIM_FIELD__ */ 
    {
        mmi_phb_op_add_entry_req();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_op_add_entry_confirm
 * DESCRIPTION
 *  Confirms before saving new entry
 * PARAMETERS
 *  void
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_phb_entry_op_add_entry_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_GLOBAL_SAVE_ASK),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_phb_op_add_pre_save, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_phb_go_back_3_history_and_clear, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_add_entry_req
 * DESCRIPTION
 *  Sends the request to the stack to save the information of a phonebook entry.
 * PARAMETERS
 *  void
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_phb_op_add_entry_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_SET_ENRTY_REQ_STRUCT *myMsgPtr;
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_op_add_entry_req.>\n", __FILE__,
                         __LINE__);

    if (g_phb_enter_from != MMI_PHB_ENTER_FROM_JAVA && g_phb_enter_from != MMI_PHB_ENTER_FROM_SYNCML)
    {
        g_phb_cntx.current_op = MMI_PHB_OP_ADD;
        mmi_phb_show_in_progress(STR_GLOBAL_SAVING, IMG_GLOBAL_SAVE);
    }
#ifdef __MMI_DUAL_SIM_MASTER__
    if (g_phb_cntx.selected_storage == MMI_SIM2)
    {
        MTPNP_PFAL_ADN_AddEntry();
        return;
    }
#endif	/* __MMI_DUAL_SIM_MASTER__ */
    myMsgPtr = (MSG_PHB_SET_ENRTY_REQ_STRUCT*) OslConstructDataPtr(sizeof(MSG_PHB_SET_ENRTY_REQ_STRUCT));
    myMsgPtr->type = MMI_PHB_PHONEBOOK;
    myMsgPtr->no_data = 1;
    myMsgPtr->list.storage = g_phb_cntx.selected_storage;
    myMsgPtr->list.index = 0xFFFF;
    myMsgPtr->list.record_index = 0xFFFF;

    mmi_phb_op_set_entry_prepare_name_number(&myMsgPtr->list, pbName, pbNumber);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_PHB_SET_ENTRY_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler(mmi_phb_op_add_entry_rsp, PRT_PHB_SET_ENTRY_RSP);
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_add_entry_rsp
 * DESCRIPTION
 *  Handles the response from stack after the entry is saved.
 * PARAMETERS
 *  info        [IN]        Response structure
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_phb_op_add_entry_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index;
    MSG_PHB_SET_ENRTY_RSP_STRUCT *localPtr;
    U8 flag = 0;
    U8 num_ascii[MAX_PB_NUMBER_LENGTH + 1 + 1];
    BOOL copy_image = TRUE, copy_video = TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (MSG_PHB_SET_ENRTY_RSP_STRUCT*) info;
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_op_add_entry_rsp.>\n", __FILE__,
                         __LINE__);

    if (localPtr->result.flag == 0) /* Set Entry Success */
    {
        store_index = mmi_phb_op_get_store_index_and_increase_counter(localPtr->list[0].storage, localPtr->list[0].record_index);

        if (localPtr->list[0].storage == MMI_NVRAM)
        {
        #if defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__)
            if ((g_phb_cntx.selected_pic_index != g_phb_cntx.total_image_id - 1) /* De-select the file if selection is not from file. */
            #ifdef __MMI_AVATAR__
                && (g_phb_cntx.selected_pic_index != g_phb_cntx.total_image_id - 2)
            #endif
                )
            {
                g_phb_cntx.image_location = MMI_PHB_IMAGE_NO_SELECT;
            }
            else if (g_phb_cntx.image_location == MMI_PHB_IMAGE_NO_SELECT)      /* Set selection to none if not select picture from file */
            {
                g_phb_cntx.selected_pic_index = 0;
            }

            copy_image = mmi_phb_image_update_by_index((U16) (store_index + 1));        /* Copy to folder in file system */
            if (!copy_image)    /* Add image fail. */
            {
                g_phb_cntx.selected_pic_index = 0;
            }
        #endif /* defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__) */ 
        #if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
            if (mmi_ucs2strlen(pbHomeNumber))
            {
                mmi_phb_number_remove_invalid_character(pbHomeNumber);
            }
            if (mmi_ucs2strlen(pbOfficeNumber))
            {
                mmi_phb_number_remove_invalid_character(pbOfficeNumber);
            }
            if (mmi_ucs2strlen(pbFaxNumber))
            {
                mmi_phb_number_remove_invalid_character(pbFaxNumber);
            }
        #endif /* !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */
            mmi_phb_op_update_optional_field(store_index, MMI_NVRAM, 1);

            /* Populate Optional Field Number */
        #if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
            flag = mmi_phb_op_increase_lookup_table(
                    store_index,
                    NULL,
                    (S8*) PhoneBookOptionalFields.faxNumber,
                    (S8*) PhoneBookOptionalFields.homeNumber,
                    (S8*) PhoneBookOptionalFields.officeNumber);
        #endif /* !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */ 
            /* Incoming call video setting */
        #if defined(__MMI_INCOMING_CALL_VIDEO__)
            copy_video = mmi_phb_video_update_by_index(store_index);
        #endif 
        }
    #if defined(__MMI_PHB_CALLERGROUP_IN_SIM__)     /* Associate caller group in SIM card entry */
        else    /* in MMI_SIM */
        {
            mmi_phb_op_update_optional_field(store_index, MMI_SIM, 1);
        }
    #endif /* defined(__MMI_PHB_CALLERGROUP_IN_SIM__) */ 

        /* Populate Number Field */
        mmi_ucs2_to_asc((PS8) num_ascii, (PS8) pbNumber);
        flag += mmi_phb_op_increase_lookup_table(store_index, (S8*) num_ascii, NULL, NULL, NULL);

        if (flag)
        {
            mmi_phb_lookup_table_sort();
        }

        mmi_phb_op_set_entry_rsp_name_number(&localPtr->list[0], store_index);

        if (localPtr->list[0].storage == MMI_SIM)
        {
            mmi_phb_op_update_field_flag(
                store_index,
                (S8*) localPtr->list[0].tel.number,
                NULL,
                NULL,
                NULL,
                NULL,
                TRUE);
        }
        else /* In NVRAM */
        {
        #if defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
            mmi_phb_op_update_field_flag(
                store_index,
                (S8*) localPtr->list[0].tel.number,
                NULL,
                NULL,
                NULL,
                NULL,
                TRUE);
        #else /* defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */ 
            mmi_phb_op_update_field_flag(
                store_index,
                (S8*) localPtr->list[0].tel.number,
                (S8*) PhoneBookOptionalFields.homeNumber,
                (S8*) PhoneBookOptionalFields.officeNumber,
                (S8*) PhoneBookOptionalFields.faxNumber,
                (S8*) PhoneBookOptionalFields.emailAddress,
                TRUE);
        #endif /* defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */ 

            /* Save birthday field */
        #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
            if (!bday_modified)
            {
                mmi_phb_util_clear_bday_buffer();
            }
            mmi_phb_bday_update_field(store_index, (S8*) pbYear, (S8*) pbMon, (S8*) pbDay);
            ResetInlineItemChangedNotification();
        #endif /* defined(__MMI_PHB_BIRTHDAY_FIELD__) */ 
        #if defined(__MMI_PHB_INFO_FIELD__)
            mmi_phb_info_update_field(store_index);
        #endif 
        #if defined(__MMI_PHB_IMPS_FIELD__) || defined(__MMI_PHB_POC_FIELD__) || defined(__MMI_VOIP__)
            mmi_phb_service_update_field(store_index);
        #endif 
        #ifdef __SYNCML_SUPPORT__
            mmi_syncml_phb_data_changed_notification(SYNCML_RECORD_ADD, store_index);
        #endif
        }
        if (PhoneBook[store_index].alpha_id.name_length)
        {
            PhoneBook[store_index].field |= MMI_PHB_ENTRY_FIELD_NAME;
        }
        /* Update Pinyin Cache for sort */
    #if defined(__MMI_PHB_PINYIN_SORT__)
        mmi_phb_util_make_pinyin_cache(store_index);
    #endif 

        /* Insert name to name mapping table. */
        mmi_phb_sort_insert_name_index(store_index);

        /* Insert email to email mapping table */
    #if defined(__MMI_PHB_EMAIL_SORT__)
        if ((localPtr->list[0].storage == MMI_NVRAM) && (g_phb_email_sorted == 1))
        {
            mmi_phb_sort_email_insert_index(store_index);
        }
    #endif /* defined(__MMI_PHB_EMAIL_SORT__) */ 

        /* add central command for vrsi. */
    #if defined(__MMI_VRSI__)
        mmi_vrsi_ndial_central_add_single(store_index);
    #endif 

    #if defined(__MMI_PHB_UPDATE_CALL_LOG_AFTER_SAVE__)     /* Update Call Log after save number */
        mmi_phb_convert_get_ucs2_number(pbNumber, store_index);
        if (g_phb_enter_from == MMI_PHB_ENTER_FROM_CALL_LOG &&
            CHISTSyncCallLogNeeded(PhoneBook[store_index].tel.length, PhoneBook[store_index].tel.type, (U8*) pbNumber))
        {
            ReqUpdateCallLogName(
                PhoneBook[store_index].alpha_id.name_length,
                PhoneBook[store_index].alpha_id.name_dcs,
                PhoneBook[store_index].alpha_id.name);
        }
        else    /* Not Enter From Call Log */
    #endif /* defined(__MMI_PHB_UPDATE_CALL_LOG_AFTER_SAVE__) */ 
    #if defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC)
        if (g_phb_enter_from == MMI_PHB_ENTER_FROM_JAVA)
        {
            mmi_phb_java_write_rsp(MMI_PHB_JAVA_SUCCESS, store_index);
        }
        else
    #endif /* defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC) */
    #if defined(__SYNCML_SUPPORT__)
        if (g_phb_enter_from == MMI_PHB_ENTER_FROM_SYNCML)
        {
            mmi_syncml_phb_sync_rsp(MMI_PHB_SYNC_SUCCESS, store_index);
        }
        else
    #endif /* __SYNCML_SUPPORT__ */ 
        {
        #if defined(__MMI_BARCODEREADER__) || defined(__MMI_BROWSER_2__) 
            if (g_phb_enter_from == MMI_PHB_ENTER_FROM_OTHERS)
            {
                if (mmi_phb_add_new_entry_callback != NULL)
                {
                    mmi_phb_add_new_entry_callback(MMI_PHB_OTHERS_SUCCESS, store_index);
                }
            }
        #endif /* defined(__MMI_BARCODEREADER__) || defined(__MMI_BROWSER_2__) */
            /* Data add success, but image or video add fail */
            if (!copy_image || !copy_video)
            {
                S8 str_buff[64 * 2];

                memset(str_buff, 0, 2);

                if (!copy_image)
                {
                    mmi_ucs2cat(str_buff, GetString(STR_ID_PHB_OP_IMAGE_FAIL));
                }

                if (!copy_video)
                {
                    if (!copy_image)
                    {
                        mmi_ucs2cat(str_buff, GetString(STR_ID_PHB_OP_COMMA));
                    }
                    mmi_ucs2cat(str_buff, GetString(STR_ID_PHB_OP_VIDEO_FAIL));
                }

                mmi_ucs2cat(str_buff, GetString(STR_ID_PHB_ADD_FAIL));
                DisplayPopup((U8*) str_buff, IMG_GLOBAL_ERROR, TRUE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
            }
            else
            {
                DisplayPopup(
                    (PU8) GetString(STR_GLOBAL_SAVED),
                    IMG_GLOBAL_ACTIVATED,
                    TRUE,
                    PHB_NOTIFY_TIMEOUT,
                    SUCCESS_TONE);
            }
        }
        mmi_phb_clear_old_add_history();

        g_phb_cntx.refresh_list = MMI_PHB_ENTRY_REFRESH;

    #if defined(__MMI_VCARD__)
        if (g_phb_enter_from == MMI_PHB_ENTER_FROM_IDLE_SCREEN)
        {
            DeleteScreenIfPresent(SCR_ID_VCARD_RECV_VIEW_DETAIL);
            DeleteScreenIfPresent(SCR_ID_VCARD_RECV_OPT);
            DeleteScreenIfPresent(SCR_ID_VOBJ_RECV_OBJECT);
            mmi_vobj_clear_one_file_buffer();
        }
    #endif /* defined(__MMI_VCARD__) */ 
    #if defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT)
        {
            extern void mmi_jdd_tapi_add_phonebook_result(JC_RETCODE ret_code);
            mmi_jdd_tapi_add_phonebook_result(JC_OK);
        }
    #endif /* defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT) */ 
    }
#if defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC)
    else if (g_phb_enter_from == MMI_PHB_ENTER_FROM_JAVA)
    {
        mmi_phb_java_write_rsp(localPtr->result.cause, 0xffff);
    }
#endif /* defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC) */ 
#if defined(__SYNCML_SUPPORT__)
    else if (g_phb_enter_from == MMI_PHB_ENTER_FROM_SYNCML)
    {
        mmi_syncml_phb_sync_rsp(MMI_PHB_SYNC_ERROR, 0xFFFF);
    }
#endif /* __SYNCML_SUPPORT__ */ 
    else    /* Set Record Fail. */
    {
    #if defined(__MMI_BARCODEREADER__) || defined(__MMI_BROWSER_2__)
        if (g_phb_enter_from == MMI_PHB_ENTER_FROM_OTHERS)
        {
            g_phb_enter_from = MMI_PHB_ENTER_NONE;
            if (mmi_phb_add_new_entry_callback != NULL)
            {
                mmi_phb_add_new_entry_callback(MMI_PHB_OTHERS_ERROR, 0xFFFF);
            }
        }
    #endif /* defined(__MMI_BARCODEREADER__) || defined(__MMI_BROWSER_2__) */
        if (localPtr->result.cause == MMI_SIM_EF_RECORD_FULL)   /* Number To Long */
        {
            DisplayPopup(
                (PU8) GetString(STR_NOT_SAVED_NUMBER_TOO_LONG),
                IMG_GLOBAL_ERROR,
                FALSE,
                PHB_NOTIFY_TIMEOUT,
                ERROR_TONE);
        #if defined(__MMI_VCARD__)
            if (g_phb_enter_from == MMI_PHB_ENTER_FROM_IDLE_SCREEN)
            {
                DeleteUptoScrID(SCR_ID_VCARD_RECV_OPT);
            }
            else
        #endif /* defined(__MMI_VCARD__) */ 
                DeleteUptoScrID(SCR_ADD_NEW_ENTRY);
        }

        else if (gSecuritySetupContext.FdlStatus)   /* For FDN is on, can't set entry */
        {
            DisplayPopup((PU8) GetString(STR_FDL_IS_ON), IMG_GLOBAL_UNFINISHED, TRUE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
            mmi_phb_clear_old_add_history();
        }
        else    /* Unknown Error */
        {
            DisplayPopup(
                (PU8) GetString(STR_GLOBAL_UNFINISHED),
                IMG_GLOBAL_UNFINISHED,
                TRUE,
                PHB_NOTIFY_TIMEOUT,
                ERROR_TONE);
            mmi_phb_clear_old_add_history();
        }
    #if defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT)
		{
			extern void mmi_jdd_tapi_add_phonebook_result(JC_RETCODE ret_code);
			mmi_jdd_tapi_add_phonebook_result(JC_ERR_TAPI_PHONEBOOK_ENTRY);
		}
    #endif /* defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT) */ 
    }

    g_phb_enter_from = MMI_PHB_ENTER_NONE;
    g_phb_cntx.current_op = MMI_PHB_OP_NONE;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_op_view_entry
 * DESCRIPTION
 *  Highlight handler for "View" in Entry options menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_op_view_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_phb_entry_op_view_entry, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_phb_entry_op_view_entry, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_view_fill_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  field_index     [IN]            Field index for the enum value
 *  item_index      [IN]            Item index for the inline editor
 *  entry_list      [OUT]           String list for the data of the field
 *  title_list      [OUT]           String list for title
 *  image_list      [OUT]           Image list
 * RETURNS
 *  Return TRUE if non-empty field.
 *****************************************************************************/
static pBOOL mmi_phb_op_view_fill_item(
                U8 field_index,
                U8 item_index,
                S8 **entry_list,
                U16 *title_list,
                U16 *image_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (field_index)
    {
        case MMI_PHB_FIELD_NAME:
            *entry_list = pbName;
            title_list[item_index] = STR_ID_PHB_NAME;
            image_list[item_index] = IMG_NAME;
            break;

        case MMI_PHB_FIELD_NUMBER:
            *entry_list = pbNumber;
            title_list[item_index] = STR_ID_PHB_MOBILE_NUMBER;
            image_list[item_index] = IMG_MOBILE_NUMBER;
            break;

    #if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
        case MMI_PHB_FIELD_HOME:
            *entry_list = pbHomeNumber;
            title_list[item_index] = STR_HOME_NUMBER;
            image_list[item_index] = IMG_HOME_NUMBER;
            break;

        case MMI_PHB_FIELD_COMPANY_NAME:
            *entry_list = pbCompanyName;   
            title_list[item_index] = STR_COMPNAY_NAME;
            image_list[item_index] = IMG_COMPANY_NAME;
            break;

        case MMI_PHB_FIELD_EMAIL:
            *entry_list = pbEmailAddress;
            title_list[item_index] = STR_EMAIL_ADRESS;
            image_list[item_index] = IMG_EMAIL_ADDRESS;
            break;

        case MMI_PHB_FIELD_OFFICE:
            *entry_list = pbOfficeNumber;
            title_list[item_index] = STR_OFFICE_NUMBER;
            image_list[item_index] = IMG_OFFICE_NUMBER;
            break;

        case MMI_PHB_FIELD_FAX:
            *entry_list = pbFaxNumber;
            title_list[item_index] = STR_FAX_NUMBER;
            image_list[item_index] = IMG_FAX_NUMBER;
            break;
    #endif /* !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */ 
        case MMI_PHB_FIELD_PIC:
            if (g_phb_cntx.selected_pic_index == 0)
            {
                return FALSE;
            }
            *entry_list = (PS8) g_phb_cntx.image_name_list[g_phb_cntx.selected_pic_index];
            title_list[item_index] = STR_ASSOCIATE_PICTURE;
            image_list[item_index] = IMG_PICTURE;
            gPictureItemIndex = item_index;
            return TRUE;

        case MMI_PHB_FIELD_RING:
            if (g_phb_cntx.selected_ring_index == 0)
            {
                return FALSE;
            }
            *entry_list = (PS8) g_phb_cntx.ring_tone_name_list[g_phb_cntx.selected_ring_index];
            title_list[item_index] = STR_ASSOCIATE_SOUND;
            image_list[item_index] = IMG_RING_TONE;
            gRingtoneItemIndex = item_index;
            return TRUE;

        case MMI_PHB_FIELD_GROUP:
            if (g_phb_cntx.selected_grp_index == 0)
            {
                return FALSE;
            }
            *entry_list = (PS8) myCallerGrpnames[g_phb_cntx.selected_grp_index];
            title_list[item_index] = STR_CALLER_GROUP;
            image_list[item_index] = IMG_CALLER_GROUP;
            return TRUE;

        #if defined(__MMI_INCOMING_CALL_VIDEO__)
        case MMI_PHB_FIELD_VIDEO:
            if (g_phb_cntx.selected_video_index == 0)
            {
                return FALSE;
            }
            *entry_list = (S8*) g_phb_cntx.video_name_list[g_phb_cntx.selected_video_index];
            title_list[item_index] = STR_ID_PHB_ASSOCIATE_VIDEO;
            image_list[item_index] = IMG_ID_PHB_ASSOCIATE_VIDEO;
            g_phb_video_item_index = item_index;
            return TRUE;
        #endif /* defined(__MMI_INCOMING_CALL_VIDEO__) */ 
        #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
        case MMI_PHB_FIELD_BIRTHDAY:
            if (mmi_ucs2cmp((const S8*)pbYear, (const S8*)MMI_PHB_BDAY_YEAR_STR) == 0 &&
                mmi_ucs2cmp((const S8*)pbMon, (const S8*)MMI_PHB_BDAY_MON_STR) == 0 &&
                mmi_ucs2cmp((const S8*)pbDay, (const S8*)MMI_PHB_BDAY_DAY_STR) == 0)
            {
                return FALSE;
            }
            else
            {
                bday_modified = TRUE;
                mmi_phb_bday_editor_callback((U8*) pbBday, (U8*) pbDay, (U8*) pbMon, (U8*) pbYear);
                *entry_list = (S8*) pbBday;
                title_list[item_index] = STR_ID_PHB_BIRTHDAY;
                image_list[item_index] = IMG_ID_PHB_BIRTHDAY;
                return TRUE;
            }
        #endif /* defined(__MMI_PHB_BIRTHDAY_FIELD__) */ 
    }
    if (field_index == MMI_PHB_FIELD_NAME || field_index == MMI_PHB_FIELD_NUMBER ||
        (*entry_list && mmi_ucs2strlen(*entry_list) > 0))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_op_view_entry
 * DESCRIPTION
 *  Displays the details of the selected phonebook entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_op_view_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *pbEntry[MAX_PB_FIELDS];
    U16 DetailPbNameImageList[MAX_PB_FIELDS];
    U8 *guiBuffer;
    U8 field_index, item_index = 0;
#if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)    
    S16 pError;
#endif
    U16 store_index;
    U16 image_id;
    PHB_OPTIONAL_IDS_STRUCT *opt_ids = NULL;
#if defined(__MMI_INCOMING_CALL_VIDEO__)
    U16 video_id;
#endif 
#if defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__)
    BOOL found_theme_tone = TRUE;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_entry_op_view_entry.>\n", __FILE__,
                         __LINE__);

    EntryNewScreen(SCR_ENTRY_VIEW, mmi_phb_exit_op_view_entry, mmi_phb_entry_op_view_entry, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ENTRY_VIEW);

    RegisterHighlightHandler(mmi_phb_view_entry_highlight_hdlr);

    store_index = g_phb_name_index[g_phb_cntx.active_index];

    mmi_ucs2cpy(pbName, (PS8) PhoneBook[store_index].alpha_id.name);
    mmi_phb_convert_get_ucs2_number(pbNumber, store_index);

    mmi_phb_op_view_fill_item(
        MMI_PHB_FIELD_NAME,
        item_index,
        &pbEntry[item_index],
        TitleStrings,
        DetailPbNameImageList);
    item_index++;
    mmi_phb_op_view_fill_item(
        MMI_PHB_FIELD_NUMBER,
        item_index,
        &pbEntry[item_index],
        TitleStrings,
        DetailPbNameImageList);
    item_index++;

    gPictureItemIndex = 0xff;                   /* Set to default before use. */
    g_phb_cntx.selected_pic_index = 0;
    gRingtoneItemIndex = 0xff;
    g_phb_cntx.selected_ring_index = 0;
#if defined(__MMI_INCOMING_CALL_VIDEO__)
    g_phb_video_item_index = 0xff;
#endif 
#if defined(__MMI_PHB_IMPS_FIELD__)
    phb_imps_item_index = 0xff;
#endif 
    if (store_index >= MAX_PB_PHONE_ENTRIES)    /* Record store in SIM, SIM index is begin from "MAX_PB_PHONE_ENTRIES" */
    {
    #if defined(__MMI_PHB_CALLERGROUP_IN_SIM__)     /* Associate caller group in SIM card entry */
        mmi_phb_build_caller_group_list();
        mmi_phb_read_optional_ids(store_index);
        opt_ids = (PHB_OPTIONAL_IDS_STRUCT*) g_phb_cntx.optional_ids;
        g_phb_cntx.selected_grp_index = opt_ids->callerGroupID;

        if (mmi_phb_op_view_fill_item
            (MMI_PHB_FIELD_GROUP, item_index, &pbEntry[item_index], TitleStrings, DetailPbNameImageList))
        {
            item_index++;
        }
    #elif defined(__MMI_PHB_USIM_FIELD__)
        if (guiBuffer == NULL)  /* First Time Enter */
        {
            mmi_phb_convert_get_ucs2_anr(pbHomeNumber, pbOfficeNumber, pbFaxNumber, store_index);
            mmi_asc_to_ucs2(pbEmailAddress, (S8*) phb_email[store_index - MAX_PB_PHONE_ENTRIES].email_address);
        }
        mmi_phb_build_usim_group_list();
        g_phb_cntx.selected_grp_index = g_phb_cntx.group_type[store_index - MAX_PB_PHONE_ENTRIES];
        /* Fill inline item for each field */
        for (field_index = (MMI_PHB_USIM_FIELD_ANRA); field_index < MMI_PHB_USIM_FIELD_TOTAL; field_index++)
        {
            if (g_phb_cntx.support_field[field_index])
            {
                if (mmi_phb_op_view_fill_usim_item
                    (field_index, item_index, &pbEntry[item_index], TitleStrings, DetailPbNameImageList))
                {
                    item_index++;
                }
            }
        }
    #endif 
    #ifdef __MMI_DUAL_SIM_MASTER__
        if (store_index >= (MAX_PB_PHONE_ENTRIES + MAX_PB_SIM_ENTRIES))
        {
            image_id = IMG_ID_CARD2_PHB_STORAGE_SIM;         
        }
        else
        {
            image_id = IMG_ID_CARD1_PHB_STORAGE_SIM;    
        }
    #else /* __MMI_DUAL_SIM_MASTER__ */
        image_id = IMG_STORAGE_SIM;
    #endif /* __MMI_DUAL_SIM_MASTER__ */    
    }
    else
    {
        mmi_phb_build_ring_tone_list();
        mmi_phb_build_image_list();
        mmi_phb_build_caller_group_list();
        mmi_phb_read_optional_ids(store_index);
        opt_ids = (PHB_OPTIONAL_IDS_STRUCT*) g_phb_cntx.optional_ids;

    #if defined(__MMI_INCOMING_CALL_VIDEO__)
        mmi_phb_build_video_list();
    #endif 

    #if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
        ReadRecord(
            NVRAM_EF_PHB_FIELDS_LID,
            (U16) (store_index + 1),
            (void*)&PhoneBookOptionalFields,
            OPTIONAL_FIELDS_RECORD_SIZE,
            &pError);
        mmi_asc_to_ucs2(pbHomeNumber, (PS8) PhoneBookOptionalFields.homeNumber);
        mmi_ucs2cpy(pbCompanyName, (PS8) PhoneBookOptionalFields.companyName);
        mmi_asc_to_ucs2(pbEmailAddress, (PS8) PhoneBookOptionalFields.emailAddress);
        mmi_asc_to_ucs2(pbOfficeNumber, (PS8) PhoneBookOptionalFields.officeNumber);
        mmi_asc_to_ucs2(pbFaxNumber, (PS8) PhoneBookOptionalFields.faxNumber);
    #endif /* !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */ 

        g_phb_cntx.selected_pic_index = mmi_phb_get_image_index(opt_ids->pictureTagID);
    #if defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__)
        if (opt_ids->pictureTagID == 1) /* Change Inline select prompt message. */
        {
            if (g_phb_cntx.selected_pic_index == g_phb_cntx.total_image_id - 1)
            {
            g_phb_cntx.image_name_list[g_phb_cntx.total_image_id - 1] =
                (U8*) GetString(STR_ID_PHB_FMGR_IMAGE_SELECTED);
                g_phb_cntx.image_location = MMI_PHB_IMAGE_SELECT_PATH;
            }
        }
    #ifdef __MMI_AVATAR__
        else if (opt_ids->pictureTagID == 2)
        {
            if(g_phb_cntx.selected_pic_index == g_phb_cntx.total_image_id - 2)
            {
                g_phb_cntx.image_name_list[g_phb_cntx.total_image_id - 2] = 
                    (U8*)GetString(STR_ID_PHB_AVATAR_SELECTED);
                g_phb_cntx.image_location = MMI_PHB_AVATAR_SELECT_PATH;
            }
        }
    #endif /* __MMI_AVATAR__ */
    #endif /* defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__) */ 

    #if defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__)
        if (opt_ids->ringToneID == CURRENT_THEME_INCOMING_CALL_TONE && mmi_tm_get_current_theme_ringtone() == 0)
        {
            g_phb_cntx.selected_ring_index = 0;
            found_theme_tone = FALSE;
        }
        else
    #endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */
        {
            g_phb_cntx.selected_ring_index = mmi_phb_get_ring_tone_index(opt_ids->ringToneID);
        }
        g_phb_cntx.selected_grp_index = opt_ids->callerGroupID;

    #if defined(__MMI_INCOMING_CALL_VIDEO__)
        video_id = mmi_phb_video_get_id_by_index(store_index);
        g_phb_cntx.selected_video_index = mmi_phb_get_video_index(video_id);

        /* Change Inline select prompt message. */
        if (g_phb_cntx.selected_video_index == g_phb_cntx.total_video_id - 1)
        {
            g_phb_cntx.video_name_list[g_phb_cntx.total_video_id - 1] =
                (U8*) GetString(STR_ID_PHB_FMGR_IMAGE_SELECTED);
            g_phb_cntx.video_location = MMI_PHB_IMAGE_SELECT_PATH;
        }
    #ifdef __MMI_AVATAR__
        else if(g_phb_cntx.selected_video_index == g_phb_cntx.total_video_id - g_phb_avatar_video_minus)
        {
            g_phb_cntx.video_name_list[g_phb_cntx.total_video_id - g_phb_avatar_video_minus] = 
                (U8*)GetString(STR_ID_PHB_AVATAR_SELECTED);
            g_phb_cntx.video_location = MMI_PHB_AVATAR_SELECT_PATH;
        }
    #endif /* __MMI_AVATAR__ */
    #ifdef __MMI_SWFLASH__
        else if(g_phb_cntx.selected_video_index == g_phb_cntx.total_video_id - g_phb_swflash_video_minus)
        {
            g_phb_cntx.video_name_list[g_phb_cntx.total_video_id - g_phb_swflash_video_minus] = 
                (U8*)GetString(STR_ID_PHB_FMGR_IMAGE_SELECTED);
            g_phb_cntx.video_location = MMI_PHB_SWFLASH_SELECT_PATH;
        }
    #endif /* __MMI_SWFLASH__ */

        /* Check if can load video path */
        if (!mmi_phb_video_get_path_by_index(video_id))
        {
            g_phb_cntx.video_location = MMI_PHB_IMAGE_NO_SELECT;
        }
    #endif /* defined(__MMI_INCOMING_CALL_VIDEO__) */ 

    #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
        mmi_phb_bday_read_data_to_buff(store_index);
    #endif 

        /* Fill inline item for each field */
        for (field_index = (MMI_PHB_FIELD_NUMBER + 1); field_index < MMI_PHB_FIELD_TOTAL; field_index++)
        {
            if (g_phb_cntx.view_field[field_index - (MMI_PHB_FIELD_NUMBER + 1)])
            {
                if (mmi_phb_op_view_fill_item
                    (field_index, item_index, &pbEntry[item_index], TitleStrings, DetailPbNameImageList))
                {
                    item_index++;
                }
            }
        }
    #if defined(__MMI_PHB_INFO_FIELD__)
        mmi_phb_info_read_data_to_buff(store_index);
        /* Fill inline item for each information field */
        for (field_index = 0; field_index < MMI_PHB_EXTRA_FIELD_TOTAL; field_index++)
        {
            if (mmi_phb_op_view_fill_extra_item
                (field_index, item_index, &pbEntry[item_index], TitleStrings, DetailPbNameImageList))
            {
                item_index++;
            }
        }
    #endif /* defined(__MMI_PHB_INFO_FIELD__) */ 
    #if defined(__MMI_PHB_IMPS_FIELD__) || defined(__MMI_PHB_POC_FIELD__) || defined(__MMI_VOIP__)
        mmi_phb_service_read_data_to_buff(store_index);
        /* Fill inline item for each service field */
        for (field_index = 0; field_index < MMI_PHB_SERVICE_FIELD_TOTAL; field_index++)
        {
            if (mmi_phb_op_view_fill_service_item
                (field_index, item_index, &pbEntry[item_index], TitleStrings, DetailPbNameImageList))
            {
                item_index++;
            }
        }
    #endif /* defined(__MMI_PHB_IMPS_FIELD__) || defined(__MMI_PHB_POC_FIELD__) || defined(__MMI_VOIP__) */ 

        image_id = IMG_STORAGE_HANDSET;
    }

    /* if title bar is thick, then use the root title icon */ 
#ifdef GUI_SUBMENU_USE_THICK_TITLE
    image_id = GetRootTitleIcon(MAIN_MENU_PHONEBOOK_MENUID);
#endif

#if (defined __MMI_TOUCH_SCREEN__) && (defined __MMI_WGUI_CSK_ENABLE__)
    EnableCenterSoftkey(0, IMG_CSK_DIAL_ICON);
#endif /* (defined __MMI_TOUCH_SCREEN__) && (defined __MMI_WGUI_CSK_ENABLE__) */ 

    ShowCategory84Screen(
        STR_SCR_ENTRY_VIEW_CAPTION,
        image_id,
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        item_index,
        (U8 **) pbEntry,
        DetailPbNameImageList,
        0,
        0,
        guiBuffer);

    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

#ifdef __MMI_DUAL_SIM_MASTER__
    MTPNP_PFAL_CC_HandleSendKeys(mmi_phb_choose_number_normal,KEY_EVENT_UP);
#else   /* __MMI_DUAL_SIM_MASTER__ */
    SetKeyHandler(mmi_phb_choose_number_normal, KEY_SEND, KEY_EVENT_UP);
#endif  /* __MMI_DUAL_SIM_MASTER__ */     
#if (defined __MMI_TOUCH_SCREEN__) && (defined __MMI_WGUI_CSK_ENABLE__)
#ifdef __MMI_DUAL_SIM_MASTER__
    MTPNP_PFAL_CC_SetCenterFunc(mmi_phb_choose_number_normal);
    SetCenterSoftkeyFunction(MTPNP_PFAL_CC_CSKHandler, KEY_EVENT_UP);
#else  /* __MMI_DUAL_SIM_MASTER__ */
    SetCenterSoftkeyFunction(mmi_phb_choose_number_normal, KEY_EVENT_UP);
#endif  /* __MMI_DUAL_SIM_MASTER__ */
#endif 
#if defined(__IP_NUMBER__) && defined(__MMI_IP_KEY__)
/* under construction !*/
#endif 

    /* Check if associate audio in file system exists. */
#if defined(__MMI_PROFILE_EXTMELODY_SUPPORT__)
    /* If first time get in and record store in NVRAM */
    if ((guiBuffer == NULL) && (store_index < MAX_PB_PHONE_ENTRIES))
    {
        if ((opt_ids->ringToneID >= PMG_EXT_MELODY_BEGIN) &&
            (opt_ids->ringToneID <= PMG_EXT_MELODY_END) && !PmgQueryFileExistById(opt_ids->ringToneID))
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_PHB_AUDIO_ID_NOT_EXIST),
                IMG_GLOBAL_ERROR,
                FALSE,
                PHB_NOTIFY_TIMEOUT,
                ERROR_TONE);
        }
    }
#endif /* defined(__MMI_PROFILE_EXTMELODY_SUPPORT__) */ 

#if defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__)
    if ( guiBuffer == NULL && found_theme_tone == FALSE )
    {
        DisplayPopup(
          (PU8) GetString(STR_ID_PHB_THEME_TONE_NOT_FOUND),
          IMG_GLOBAL_ERROR,
          FALSE,
          PHB_NOTIFY_TIMEOUT,
          ERROR_TONE);
    }
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_op_view_entry
 * DESCRIPTION
 *  Exit function for mmi_phb_entry_op_view_entry()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_exit_op_view_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_stop_ring_tone_id();
    g_phb_cntx.end_scr_id = SCR_ENTRY_VIEW;
#if (defined __MMI_TOUCH_SCREEN__) && (defined __MMI_WGUI_CSK_ENABLE__)
    ResetCenterSoftkey();
#endif /* (defined __MMI_TOUCH_SCREEN__) && (defined __MMI_WGUI_CSK_ENABLE__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_op_view_picture
 * DESCRIPTION
 *  view select picture.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_op_view_picture(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.selected_pic_in_view = 0;    /* No Use in Entry View Screen */

    EntryNewScreen(SCR_VIEW_PICTURE, NULL, mmi_phb_entry_op_view_picture, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_VIEW_PICTURE);

    ShowCategory142Screen(
        (PU8) GetString(STR_VIEW_PICTURE_CAPTION),
        IMG_SCR_PBOOK_CAPTION,
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        NULL,
        &g_phb_cntx.image_id_list[g_phb_cntx.selected_pic_index],
        NULL,
        1,
        &g_phb_cntx.selected_pic_in_view,
        guiBuffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_view_entry_highlight_hdlr
 * DESCRIPTION
 *  view entry highlight handler.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_view_entry_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_stop_ring_tone_id();
    ChangeTitleString((PU8) GetString(TitleStrings[index]));
    draw_title();

#if defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__)
    /* View Image In File Folder */
    if (index == gPictureItemIndex)
    {
        if (g_phb_cntx.selected_pic_index == (g_phb_cntx.total_image_id - 1))
        {
            ChangeLeftSoftkey(STR_VIEW_LSK, IMG_VIEW_LSK);
            g_phb_cntx.image_location = MMI_PHB_IMAGE_FOR_ENTRY;
            SetLeftSoftkeyFunction(mmi_phb_image_view_from_phb_folder, KEY_EVENT_UP);
        }
#ifdef __MMI_AVATAR__
        else if (g_phb_cntx.selected_pic_index == (g_phb_cntx.total_image_id - 2))
        {
            ChangeLeftSoftkey(STR_VIEW_LSK, IMG_VIEW_LSK);
            g_phb_cntx.image_location = MMI_PHB_IMAGE_FOR_ENTRY;
            SetLeftSoftkeyFunction(mmi_phb_image_view_from_phb_folder, KEY_EVENT_UP);
        }
#endif /* __MMI_AVATAR__ */
        /* View Default Image ID through Category screen */
        else
        {
            ChangeLeftSoftkey(STR_VIEW_LSK, IMG_VIEW_LSK);
            SetLeftSoftkeyFunction(mmi_phb_entry_op_view_picture, KEY_EVENT_UP);
        }
    }
#else /* defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__) */ 
    if (index == gPictureItemIndex)     /* Highlight on Image Field */
    {
        ChangeLeftSoftkey(STR_VIEW_LSK, IMG_VIEW_LSK);
        SetLeftSoftkeyFunction(mmi_phb_entry_op_view_picture, KEY_EVENT_UP);
    }
#endif /* defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__) */ 
    /* Play Ring Tone if highlight on ringtone field. */
    else if (index == gRingtoneItemIndex)
    {
        ChangeLeftSoftkey(0, 0);
        mmi_phb_ring_tone_highlight_hdlr(g_phb_cntx.selected_ring_index);
    }

    /* Highlight on incoming call video item */
#if defined(__MMI_INCOMING_CALL_VIDEO__)
    else if (index == g_phb_video_item_index)
    {
        if (g_phb_cntx.selected_video_index == (g_phb_cntx.total_video_id - 1))
        {
            ChangeLeftSoftkey(STR_GLOBAL_VIEW, IMG_GLOBAL_OPTIONS);
            SetLeftSoftkeyFunction(mmi_phb_video_view_from_file, KEY_EVENT_UP);
        }
#ifdef __MMI_AVATAR__
        else if(g_phb_cntx.selected_video_index == (g_phb_cntx.total_video_id - g_phb_avatar_video_minus))
        {
            ChangeLeftSoftkey(STR_GLOBAL_VIEW, IMG_GLOBAL_OPTIONS);
            SetLeftSoftkeyFunction(mmi_phb_video_view_from_file, KEY_EVENT_UP);
        }
#endif /* __MMI_AVATAR__ */
#ifdef __MMI_SWFLASH__
        else if(g_phb_cntx.selected_video_index == (g_phb_cntx.total_video_id - g_phb_swflash_video_minus))
        {
            ChangeLeftSoftkey(STR_GLOBAL_VIEW, IMG_GLOBAL_OPTIONS);
            SetLeftSoftkeyFunction(mmi_phb_video_view_from_file, KEY_EVENT_UP);
        }
#endif /* __MMI_SWFLASH__ */
        else if (g_phb_cntx.selected_video_index != 0)
        {
            ChangeLeftSoftkey(STR_GLOBAL_VIEW, IMG_GLOBAL_OPTIONS);
            SetLeftSoftkeyFunction(mmi_phb_video_view_from_default, KEY_EVENT_UP);
        }
        else
        {
            ChangeLeftSoftkey(0, 0);
            ClearKeyHandler(KEY_LSK, KEY_EVENT_UP);
        }
    }
#endif /* defined(__MMI_INCOMING_CALL_VIDEO__) */ 
#if defined(__MMI_PHB_IMPS_FIELD__)
    else if (index == phb_imps_item_index)
    {
        ChangeLeftSoftkey(STR_GLOBAL_SEND, IMG_GLOBAL_OPTIONS);
        SetLeftSoftkeyFunction(mmi_phb_imps_send_message, KEY_EVENT_UP);
    }
#endif /* defined(__MMI_PHB_IMPS_FIELD__) */ 
    else
    {
        ChangeLeftSoftkey(0, 0);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_op_edit_entry
 * DESCRIPTION
 *  Highlight handler for "Edit" in Entry options menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_op_edit_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_phb_op_edit_pre_entry, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_phb_op_edit_pre_entry, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_edit_pre_entry
 * DESCRIPTION
 *  Pre Entry function for phonebook edit.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_edit_pre_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_util_clear_buffer(TRUE);
    g_phb_cntx.set_done_flag = 0;
#ifdef __MMI_DUAL_SIM_MASTER__
    {
        U16 store_index;
        store_index = g_phb_name_index[g_phb_cntx.active_index];
        if(store_index>=MAX_PB_PHONE_ENTRIES+MAX_PB_SIM_ENTRIES)
        {
            Card2_ADN_entry_op_edit_entry();
            return;
        }
    }
#endif	/* __MMI_DUAL_SIM_MASTER__ */
    mmi_phb_entry_op_edit_entry();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_op_edit_entry
 * DESCRIPTION
 *  Inline edit screen to edit an entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_op_edit_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;
    U8 field_index, item_index = 0;
#if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)    
    S16 pError;
#endif
    U16 DetailPbNameImageList[MAX_PB_FIELDS];
    U16 store_index;
    U16 image_id;
    PHB_OPTIONAL_IDS_STRUCT *opt_ids = NULL;
#if defined __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    BOOL found_theme_tone = TRUE;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_entry_op_edit_entry.>\n", __FILE__,
                         __LINE__);

    store_index = g_phb_name_index[g_phb_cntx.active_index];

    EntryNewScreen(SCR_INLINE_EDIT, mmi_phb_exit_op_edit_entry, NULL, NULL);
    InitializeCategory57Screen();
    guiBuffer = GetCurrGuiBuffer(SCR_INLINE_EDIT);
    inputBuffer = GetCurrNInputBuffer(SCR_INLINE_EDIT, &inputBufferSize);

    RegisterHighlightHandler(mmi_phb_op_edit_highlight_hdlr);

    /* Fill name and number field */
    if (guiBuffer == NULL)  /* First Time Enter */
    {
        mmi_ucs2cpy(pbName, (PS8) PhoneBook[store_index].alpha_id.name);
        mmi_phb_convert_get_ucs2_number(pbNumber, store_index);
    }

#ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
    EnableInlineItemDefaultText();
#endif 

    mmi_phb_op_fill_inline_item(MMI_PHB_FIELD_NAME, item_index++, store_index, TitleStrings, DetailPbNameImageList);
    mmi_phb_op_fill_inline_item(MMI_PHB_FIELD_NUMBER, item_index++, store_index, TitleStrings, DetailPbNameImageList);

    if (store_index >= MAX_PB_PHONE_ENTRIES)    /* Record store in SIM, SIM index is begin from "MAX_PB_PHONE_ENTRIES" */
    {
    #if defined(__MMI_PHB_CALLERGROUP_IN_SIM__)     /* Associate caller group in SIM card entry */
        mmi_phb_build_caller_group_list();
        mmi_phb_read_optional_ids(store_index);
        opt_ids = (PHB_OPTIONAL_IDS_STRUCT*) g_phb_cntx.optional_ids;
        g_phb_cntx.selected_grp_index = opt_ids->callerGroupID;

        mmi_phb_op_fill_inline_item(
            MMI_PHB_FIELD_GROUP,
            item_index++,
            store_index,
            TitleStrings,
            DetailPbNameImageList);
    #elif defined(__MMI_PHB_USIM_FIELD__)
        if (guiBuffer == NULL)  /* First Time Enter */
        {
            mmi_phb_convert_get_ucs2_anr(pbHomeNumber, pbOfficeNumber, pbFaxNumber, store_index);
            mmi_asc_to_ucs2(pbEmailAddress, (S8*) phb_email[store_index - MAX_PB_PHONE_ENTRIES].email_address);
        }
        mmi_phb_build_usim_group_list();
        g_phb_cntx.selected_grp_index = g_phb_cntx.group_type[store_index - MAX_PB_PHONE_ENTRIES];
        /* Fill inline item for each field */
        for (field_index = (MMI_PHB_USIM_FIELD_ANRA); field_index < MMI_PHB_USIM_FIELD_TOTAL; field_index++)
        {
            if (g_phb_cntx.support_field[field_index])
            {
                mmi_phb_op_fill_usim_inline_item(
                    field_index,
                    item_index++,
                    MAX_PB_ENTRIES,
                    TitleStrings,
                    DetailPbNameImageList);
            }
        }
    #endif 
        if (inputBuffer != NULL)
        {
            SetCategory57Data(wgui_inline_items, item_index, inputBuffer);
        }

    #ifdef __MMI_DUAL_SIM_MASTER__
        image_id = IMG_ID_CARD1_PHB_STORAGE_SIM;    
    #else /* __MMI_DUAL_SIM_MASTER__ */
        image_id = IMG_STORAGE_SIM;
    #endif /* __MMI_DUAL_SIM_MASTER__ */    
    }
    else
    {
        gPictureItemIndex = MAX_PB_PICTURES_TAGS;   /* Set to default before use. */
    #if defined(__MMI_INCOMING_CALL_VIDEO__)
        g_phb_video_item_index = MAX_PB_VIDEO_TAGS;
    #endif 
        mmi_phb_build_ring_tone_list();
        mmi_phb_build_image_list();
        mmi_phb_build_caller_group_list();
        mmi_phb_read_optional_ids(store_index);
        opt_ids = (PHB_OPTIONAL_IDS_STRUCT*) g_phb_cntx.optional_ids;

    #if defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__)
        if (opt_ids->ringToneID == CURRENT_THEME_INCOMING_CALL_TONE && mmi_tm_get_current_theme_ringtone() == 0)
        {
            g_phb_cntx.selected_ring_index = 0;
            found_theme_tone = FALSE;
        }
        else
    #endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */
        {
            g_phb_cntx.selected_ring_index = mmi_phb_get_ring_tone_index(opt_ids->ringToneID);
        }
        g_phb_cntx.selected_grp_index = opt_ids->callerGroupID;

    #if defined(__MMI_INCOMING_CALL_VIDEO__)
        mmi_phb_build_video_list();

        if (guiBuffer == NULL)  /* First Time Enter */
        {
            U16 video_id = mmi_phb_video_get_id_by_index(store_index);

            g_phb_cntx.selected_video_index = mmi_phb_get_video_index(video_id);

            g_phb_cntx.video_audio = ((video_id == 0) || (video_id & 0x4000)) ? 1 : 0;

            /* Check if can load video path */
            if (mmi_phb_video_get_path_by_index(video_id))
            {
            #ifdef __MMI_AVATAR__
                if ((video_id & 0x9000) == 0x9000)
                {
                    g_phb_cntx.video_location = MMI_PHB_AVATAR_SELECT_PATH;
                }
                else
            #endif /* def __MMI_AVATAR__ */
            #ifdef __MMI_SWFLASH__
                if ((video_id & 0xA000) == 0xA000)
                {
                    g_phb_cntx.video_location = MMI_PHB_SWFLASH_SELECT_PATH;
                }
                else
            #endif /*def __MMI_SWFLASH__ */
                {
                    g_phb_cntx.video_location = MMI_PHB_IMAGE_SELECT_PATH;
                }
            }
            else
            {
                g_phb_cntx.video_location = MMI_PHB_IMAGE_NO_SELECT;
            }
        }

        if (g_phb_cntx.video_location != MMI_PHB_IMAGE_NO_SELECT)       /* Change Inline select prompt message. */
        {
        #if defined(__MMI_AVATAR__) || defined(__MMI_SWFLASH__)
        #ifdef __MMI_AVATAR__
            if (g_phb_cntx.selected_video_index == (g_phb_cntx.total_video_id - g_phb_avatar_video_minus) &&
                g_phb_cntx.video_location == MMI_PHB_AVATAR_SELECT_PATH)
            {
                g_phb_cntx.video_name_list[g_phb_cntx.total_video_id - g_phb_avatar_video_minus] =
                    (U8*) GetString(STR_ID_PHB_AVATAR_SELECTED);
                g_phb_cntx.video_location = MMI_PHB_AVATAR_SELECT_PATH;
            }
            else
        #endif /* __MMI_AVATAR__ */
        #ifdef __MMI_SWFLASH__
            if (g_phb_cntx.selected_video_index == (g_phb_cntx.total_video_id - g_phb_swflash_video_minus) &&
                g_phb_cntx.video_location == MMI_PHB_SWFLASH_SELECT_PATH)
            {
                g_phb_cntx.video_name_list[g_phb_cntx.total_video_id - g_phb_swflash_video_minus] =
                    (U8*) GetString(STR_ID_PHB_FMGR_IMAGE_SELECTED);
                g_phb_cntx.video_location = MMI_PHB_SWFLASH_SELECT_PATH;
            }
            else
        #endif /* __MMI_SWFLASH__ */
            if (g_phb_cntx.selected_video_index == (g_phb_cntx.total_video_id - 1)
        #ifdef __MMI_AVATAR__ 
               && g_phb_cntx.video_location != MMI_PHB_AVATAR_SELECT_PATH
        #endif /* __MMI_AVATAR__ */
        #ifdef __MMI_SWFLASH__
               && g_phb_cntx.video_location != MMI_PHB_SWFLASH_SELECT_PATH
        #endif /* __MMI_SWFLASH__ */
               )
        #endif /* defined(__MMI_AVATAR__) || defined(__MMI_SWFLASH__) */
            {
                g_phb_cntx.video_name_list[g_phb_cntx.total_video_id - 1] =
                    (U8*) GetString(STR_ID_PHB_FMGR_IMAGE_SELECTED);
            }
        }	
    #endif /* defined(__MMI_INCOMING_CALL_VIDEO__) */ 

    #if defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__)
        if (guiBuffer == NULL)
        {
            g_phb_cntx.selected_pic_index = mmi_phb_get_image_index(opt_ids->pictureTagID);
            g_phb_image_type_id = opt_ids->pictureTagID;
            /* Check if image folder was hidden by USB mode */
            if ((opt_ids->pictureTagID == 1 || opt_ids->pictureTagID == 2) && mmi_phb_image_check_image_file())
            {
                g_phb_cntx.image_location = MMI_PHB_IMAGE_FOR_ENTRY;
            }
            else
            {
                g_phb_cntx.image_location = MMI_PHB_IMAGE_NO_SELECT;
            }
            if (g_phb_cntx.image_location != MMI_PHB_IMAGE_NO_SELECT)       /* Change Inline select prompt message. */
            {
            #ifdef __MMI_AVATAR__
                if (g_phb_cntx.selected_pic_index == (g_phb_cntx.total_image_id - 2))
                {
                    g_phb_cntx.image_name_list[g_phb_cntx.total_image_id - 2] =
                        (U8*) GetString(STR_ID_PHB_AVATAR_SELECTED);
                }
                else
            #endif /* __MMI_AVATAR__ */
                if (g_phb_cntx.selected_pic_index == (g_phb_cntx.total_image_id - 1))
                {
                    g_phb_cntx.image_name_list[g_phb_cntx.total_image_id - 1] =
                        (U8*) GetString(STR_ID_PHB_FMGR_IMAGE_SELECTED);
                }
            }
        }
        else
        {
            opt_ids->pictureTagID = g_phb_image_type_id;
            g_phb_cntx.selected_pic_index = mmi_phb_get_image_index(g_phb_image_type_id);
            if (g_phb_cntx.image_location != MMI_PHB_IMAGE_NO_SELECT)       /* Change Inline select prompt message. */
            {
            #ifdef __MMI_AVATAR__
                if (g_phb_cntx.selected_pic_index == (g_phb_cntx.total_image_id - 2))
                {
                    g_phb_cntx.image_name_list[g_phb_cntx.total_image_id - 2] =
                        (U8*) GetString(STR_ID_PHB_AVATAR_SELECTED);
                }
                else
            #endif /* __MMI_AVATAR__ */
                if (g_phb_cntx.selected_pic_index == (g_phb_cntx.total_image_id - 1))
                {
                    g_phb_cntx.image_name_list[g_phb_cntx.total_image_id - 1] =
                        (U8*) GetString(STR_ID_PHB_FMGR_IMAGE_SELECTED);
                }
            }
        }
    #else /* defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__) */
        if (guiBuffer == NULL)
        {
            g_phb_cntx.selected_pic_index = mmi_phb_get_image_index(opt_ids->pictureTagID);
            g_phb_image_type_id = opt_ids->pictureTagID;
            g_phb_cntx.image_location = MMI_PHB_IMAGE_NO_SELECT;
        }
        else
        {
            opt_ids->pictureTagID = g_phb_image_type_id;
            g_phb_cntx.selected_pic_index = mmi_phb_get_image_index(g_phb_image_type_id);
        }
    #endif /* defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__) */ 

    #if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
        if (guiBuffer == NULL)  /* First Time Enter */
        {
            ReadRecord(
                NVRAM_EF_PHB_FIELDS_LID,
                (U16) (store_index + 1),
                (void*)&PhoneBookOptionalFields,
                OPTIONAL_FIELDS_RECORD_SIZE,
                &pError);

            mmi_asc_to_ucs2(pbHomeNumber, (PS8) PhoneBookOptionalFields.homeNumber);
            mmi_ucs2cpy(pbCompanyName, (PS8) PhoneBookOptionalFields.companyName);
            mmi_asc_to_ucs2(pbEmailAddress, (PS8) PhoneBookOptionalFields.emailAddress);
            mmi_asc_to_ucs2(pbOfficeNumber, (PS8) PhoneBookOptionalFields.officeNumber);
            mmi_asc_to_ucs2(pbFaxNumber, (PS8) PhoneBookOptionalFields.faxNumber);
        }
    #endif /* !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */ 

    #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
        mmi_phb_bday_read_data_to_buff(store_index);
    #endif 

        /* Fill inline item for each field */
        for (field_index = (MMI_PHB_FIELD_NUMBER + 1); field_index < MMI_PHB_FIELD_TOTAL; field_index++)
        {
            if (g_phb_cntx.view_field[field_index - (MMI_PHB_FIELD_NUMBER + 1)])
            {
                mmi_phb_op_fill_inline_item(
                    field_index,
                    item_index++,
                    store_index,
                    TitleStrings,
                    DetailPbNameImageList);
            }
        }

        if (inputBuffer != NULL)
        {
            SetCategory57Data(wgui_inline_items, item_index, inputBuffer);
            mmi_phb_op_reconfig_inline_item(guiBuffer);

        }

        image_id = IMG_STORAGE_HANDSET;
    }

    /* if title bar is thick, then use the root title icon */ 
#ifdef GUI_SUBMENU_USE_THICK_TITLE
    image_id = GetRootTitleIcon(MAIN_MENU_PHONEBOOK_MENUID);
#endif

    ShowCategory57Screen(
        STR_SCR_INLINE_EDIT_CAPTION,
        image_id,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        item_index,
        DetailPbNameImageList,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_phb_entry_op_edit_save_confirm, GoBackHistory);

    if (g_phb_cntx.set_done_flag)
    {
        g_phb_cntx.set_done_flag = 0;
        set_wgui_inline_list_menu_changed();
    }

    /* Check if associate audio in file system exists. */
#if defined(__MMI_PROFILE_EXTMELODY_SUPPORT__)
    /* If first time get in and record store in NVRAM */
    if ((guiBuffer == NULL) && (store_index < MAX_PB_PHONE_ENTRIES))
    {
        if ((opt_ids->ringToneID >= PMG_EXT_MELODY_BEGIN) &&
            (opt_ids->ringToneID <= PMG_EXT_MELODY_END) && !PmgQueryFileExistById(opt_ids->ringToneID))
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_PHB_AUDIO_ID_NOT_EXIST),
                IMG_GLOBAL_ERROR,
                FALSE,
                PHB_NOTIFY_TIMEOUT,
                ERROR_TONE);
        }
    }
#endif /* defined(__MMI_PROFILE_EXTMELODY_SUPPORT__) */ 
#if defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__)
    if (guiBuffer == NULL && found_theme_tone == FALSE)
    {
        DisplayPopup(
          (PU8) GetString(STR_ID_PHB_THEME_TONE_NOT_FOUND),
          IMG_GLOBAL_ERROR,
          FALSE,
          PHB_NOTIFY_TIMEOUT,
          ERROR_TONE);
    }
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_op_edit_entry
 * DESCRIPTION
 *  Exit function for mmi_phb_entry_op_edit_entry()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_exit_op_edit_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.end_scr_id = SCR_INLINE_EDIT;

    mmi_phb_stop_ring_tone_id();
    CloseCategory57Screen();
    h.scrnID = SCR_INLINE_EDIT;
    h.entryFuncPtr = mmi_phb_entry_op_edit_entry;
    GetCategoryHistory(h.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, inputBufferSize);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_edit_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for inline edit screen
 *  
 *  Mainly to set the LSK of image list to "View"
 *  and stopping the Ringtone & LED pattern
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_edit_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_stop_ring_tone_id();
    mmi_phb_stop_led_pattern_id();  /* But Not LED in phonebook inline setting */
    ChangeTitleString((PU8) GetString(TitleStrings[index]));

    draw_title();

    /* Highlight on assoicate picture item */
#if defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__)
    if (index == gPictureItemIndex)
	{
        if (g_phb_cntx.selected_pic_index == (g_phb_cntx.total_image_id - 1))     /* View Image File */
        {
            ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
            SetLeftSoftkeyFunction(mmi_phb_image_pre_entry_option, KEY_EVENT_UP);
        }
    #ifdef _MMI_AVATAR__
        else if (g_phb_cntx.selected_pic_index == (g_phb_cntx.total_image_id - 2))     /* View Avatar Image File */
        {
            ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
            SetLeftSoftkeyFunction(mmi_phb_avatar_image_pre_entry_option, KEY_EVENT_UP);
        }
    #endif
        else /* View Image ID through Category screen */
        {
            ChangeLeftSoftkey(STR_VIEW_LSK, IMG_VIEW_LSK);
            SetLeftSoftkeyFunction(mmi_phb_entry_op_edit_view_picture, KEY_EVENT_UP);
        }
    }
#else /* defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__) */ 
    if (index == gPictureItemIndex)
    {
        ChangeLeftSoftkey(STR_VIEW_LSK, IMG_VIEW_LSK);
        SetLeftSoftkeyFunction(mmi_phb_entry_op_edit_view_picture, KEY_EVENT_UP);
    }
#endif /* defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__) */ 

    /* Highlight on incoming call video item */
#if defined(__MMI_INCOMING_CALL_VIDEO__)
    if (index == g_phb_video_item_index)
    {
        if (g_phb_cntx.selected_video_index == (g_phb_cntx.total_video_id - 1))
        {
            ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
            SetLeftSoftkeyFunction(mmi_phb_video_pre_entry_file_option, KEY_EVENT_UP);
        }
#ifdef __MMI_AVATAR__
		 else if(g_phb_cntx.selected_video_index == (g_phb_cntx.total_video_id - g_phb_avatar_video_minus))
		 {
			ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
			SetLeftSoftkeyFunction(mmi_phb_avatar_video_pre_entry_file_option, KEY_EVENT_UP);
		 }
#endif /* __MMI_AVATAR__ */
#ifdef __MMI_SWFLASH__
		 else if(g_phb_cntx.selected_video_index == (g_phb_cntx.total_video_id - g_phb_swflash_video_minus))
		 {
			ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
			SetLeftSoftkeyFunction(mmi_phb_swflash_pre_entry_file_option, KEY_EVENT_UP);
		 }
		 else if(g_phb_cntx.selected_video_index != 0 && g_phb_cntx.selected_video_index <= MMI_PHB_SWFLASH_TOTAL)
		 {
			ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
			SetLeftSoftkeyFunction(mmi_phb_entry_swflash_default_option, KEY_EVENT_UP);
		 }
#endif /* __MMI_SWFLASH__ */
        else if (g_phb_cntx.selected_video_index != 0)
        {
            ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
            SetLeftSoftkeyFunction(mmi_phb_entry_video_default_option, KEY_EVENT_UP);
        }
        else
        {
            ChangeLeftSoftkey(0, 0);
            ClearKeyHandler(KEY_LSK, KEY_EVENT_UP);
        }
    }
#endif /* defined(__MMI_INCOMING_CALL_VIDEO__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_op_edit_view_picture
 * DESCRIPTION
 *  Shows the preview of images in the list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_op_edit_view_picture(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 total_image_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.selected_pic_in_view = g_phb_cntx.selected_pic_index;
    viewOnce = TRUE;

    EntryNewScreen(SCR_VIEW_PICTURE, mmi_phb_exit_op_edit_view_picture, mmi_phb_entry_op_edit_view_picture, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_VIEW_PICTURE);

    /* The last index is select from File Manager, just show total image - 1 files */
#if defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__)
#if defined(__MMI_AVATAR__)
    total_image_id = g_phb_cntx.total_image_id - 2;
#else /* defined(__MMI_AVATAR__) */
    total_image_id = g_phb_cntx.total_image_id - 1;    
#endif /* defined(__MMI_AVATAR__) */
#else /* defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__) */
    total_image_id = g_phb_cntx.total_image_id;
#endif /* defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__) */ 

    ShowCategory142Screen(
        (PU8) GetString(STR_VIEW_PICTURE_CAPTION),
        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        0,
        0,
        NULL,
        g_phb_cntx.image_id_list,
        NULL,
        total_image_id,
        &g_phb_cntx.selected_pic_in_view,
        guiBuffer);

    SetLeftSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_op_edit_view_picture
 * DESCRIPTION
 *  Exit function for mmi_phb_entry_op_edit_view_picture()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_exit_op_edit_view_picture(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.end_scr_id = SCR_VIEW_PICTURE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_edit_pre_save
 * DESCRIPTION
 *  Checks if the entry can be saved
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_edit_pre_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_phb_op_check_pre_save(TRUE))
    {
        return;
    }
#ifdef __MMI_PHB_USIM_FIELD__
    if (g_phb_cntx.is_usim &&
        (g_phb_name_index[g_phb_cntx.active_index] < MAX_PB_ENTRIES
         && g_phb_name_index[g_phb_cntx.active_index] >= MAX_PB_PHONE_ENTRIES))
    {
        mmi_phb_op_edit_usim_entry_req();
    }
    else
#endif /* __MMI_PHB_USIM_FIELD__ */ 
    {
        mmi_phb_op_edit_entry_req();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_op_edit_save_confirm
 * DESCRIPTION
 *  Confirms before saving the entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_op_edit_save_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_GLOBAL_SAVE_ASK),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_phb_op_edit_pre_save, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_phb_go_back_2_history, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_edit_entry_req
 * DESCRIPTION
 *  Sends the request to L4 to save the entry
 *  edited by the user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_edit_entry_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_SET_ENRTY_REQ_STRUCT *myMsgPtr;
    MYQUEUE Message;
    U16 store_index = 0;
    U8 storage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_op_edit_entry_req.>\n", __FILE__,
                         __LINE__);

    myMsgPtr = (MSG_PHB_SET_ENRTY_REQ_STRUCT*) OslConstructDataPtr(sizeof(MSG_PHB_SET_ENRTY_REQ_STRUCT));
    if (g_phb_enter_from == MMI_PHB_ENTER_FROM_JAVA)
    {
        ASSERT(g_phb_cntx.java_store_index < MAX_PB_ENTRIES)
    #if defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC)
        store_index = g_phb_cntx.java_store_index;
    #endif /* defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC) */
    }
#ifdef __SYNCML_SUPPORT__
    else if (g_phb_enter_from == MMI_PHB_ENTER_FROM_SYNCML)
    {
        store_index = g_phb_cntx.active_index;
    }
#endif /* __SYNCML_SUPPORT__ */
    else
    {
        g_phb_cntx.current_op = MMI_PHB_OP_EDIT;  
        mmi_phb_show_in_progress(STR_GLOBAL_SAVING, IMG_GLOBAL_SAVE);
        store_index = g_phb_name_index[g_phb_cntx.active_index];
    }
    storage = (store_index >= MAX_PB_PHONE_ENTRIES) ? MMI_SIM : MMI_NVRAM;
    myMsgPtr->type = MMI_PHB_PHONEBOOK;
    myMsgPtr->no_data = 1;
    myMsgPtr->list.storage = storage;
    myMsgPtr->list.index = 0xffff;
    myMsgPtr->list.record_index = (storage == MMI_SIM) ? (store_index + 1) - MAX_PB_PHONE_ENTRIES : (store_index + 1);

    mmi_phb_op_set_entry_prepare_name_number(&myMsgPtr->list, pbName, pbNumber);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_PHB_SET_ENTRY_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler(mmi_phb_op_edit_entry_rsp, PRT_PHB_SET_ENTRY_RSP);
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_edit_entry_rsp
 * DESCRIPTION
 *  Response handler for entry edit request
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_edit_entry_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_SET_ENRTY_RSP_STRUCT *localPtr;
    U16 deletedCnt = 0;
    U8 flag = 0;
    BOOL copy_image = TRUE, copy_video = TRUE;
    U16 store_index;
    U16 record_index;
    U8 storage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (MSG_PHB_SET_ENRTY_RSP_STRUCT*) info;
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_op_edit_entry_rsp.>\n", __FILE__,
                         __LINE__);

    if (localPtr->result.flag == 0) /* Edit Entry OK */
    {
    #if defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC)
        if (g_phb_enter_from == MMI_PHB_ENTER_FROM_JAVA)
        {
            store_index = g_phb_cntx.java_store_index;
        }
        else
    #endif /* defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC) */ 
    #if defined(__SYNCML_SUPPORT__)
        if (g_phb_enter_from == MMI_PHB_ENTER_FROM_SYNCML)
        {
            store_index = g_phb_cntx.active_index;
        }
        else
    #endif /* defined(__SYNCML_SUPPORT__) */ 
        {
            store_index = g_phb_name_index[g_phb_cntx.active_index];
        }
        storage = (store_index >= MAX_PB_PHONE_ENTRIES) ? MMI_SIM : MMI_NVRAM;
        record_index = (storage == MMI_SIM) ? (store_index + 1) - MAX_PB_PHONE_ENTRIES : (store_index + 1);

        PhbUpdateSpeedDial(storage, record_index, MMI_PHB_PHONEBOOK, (U8*) pbName, (U8*) pbNumber);

        /* Clear lookup table first, add later if exists. */
        deletedCnt = mmi_phb_op_clear_lookup_table_by_index(store_index);

        if (storage == MMI_NVRAM)
        {
        #if defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__)
        #if defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC)
            if (g_phb_enter_from != MMI_PHB_ENTER_FROM_JAVA)
        #endif
            {
                if ((g_phb_cntx.selected_pic_index != g_phb_cntx.total_image_id - 1) /* De-select the file if selection is not from file. */
                #ifdef __MMI_AVATAR__
                    && (g_phb_cntx.selected_pic_index != g_phb_cntx.total_image_id - 2)
                #endif
                    )
                {
                    g_phb_cntx.image_location = MMI_PHB_IMAGE_NO_SELECT;
                }
                else if ((g_phb_cntx.selected_pic_index == g_phb_cntx.total_image_id - 1) &&
                    (g_phb_cntx.image_location == MMI_PHB_IMAGE_NO_SELECT 
                #ifdef __MMI_AVATAR__
                    || g_phb_cntx.image_location == MMI_PHB_AVATAR_SELECT_PATH
                    || g_phb_image_type_id == 2
                #endif
                    ))
                {
                    g_phb_cntx.selected_pic_index = 0;
                    g_phb_cntx.image_location = MMI_PHB_IMAGE_NO_SELECT;
                }
            #ifdef __MMI_AVATAR__
                else if ((g_phb_cntx.selected_pic_index == g_phb_cntx.total_image_id - 2) &&
                    (g_phb_cntx.image_location == MMI_PHB_IMAGE_NO_SELECT
                    || g_phb_image_type_id == 1))
                {
                    g_phb_cntx.selected_pic_index = 0;
                    g_phb_cntx.image_location = MMI_PHB_IMAGE_NO_SELECT;
                }
            #endif /* def __MMI_AVATAR__ */
                else if (g_phb_cntx.image_location == MMI_PHB_IMAGE_NO_SELECT)      /* Set selection to none if not select picture from file */
                {
                    g_phb_cntx.selected_pic_index = 0;
                }
                
                copy_image = mmi_phb_image_update_by_index(record_index);   /* Update from file manager */
                if (!copy_image)    /* Update image fail. */
                {
                    g_phb_cntx.selected_pic_index = 0;
                }
            }
        #endif /* defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__) */
        #if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) 
            if (mmi_ucs2strlen(pbHomeNumber))
            {
                mmi_phb_number_remove_invalid_character(pbHomeNumber);
            }
            if (mmi_ucs2strlen(pbOfficeNumber))
            {
                mmi_phb_number_remove_invalid_character(pbOfficeNumber);
            }
            if (mmi_ucs2strlen(pbFaxNumber))
            {
                mmi_phb_number_remove_invalid_character(pbFaxNumber);
            }
        #endif /* !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */
        #if defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC)
            if (g_phb_enter_from == MMI_PHB_ENTER_FROM_JAVA)
            {
                /* don't change caller pic, ringtone, but group id should be changed */
                mmi_phb_op_update_optional_field(store_index, MMI_NVRAM, 0);
            }
            else
        #endif /* defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC) */ 
        #ifdef __SYNCML_SUPPORT__
            if (g_phb_enter_from == MMI_PHB_ENTER_FROM_SYNCML)
            {
                mmi_phb_op_update_optional_field(store_index, MMI_NVRAM, 0);
            }
            else
        #endif /* __SYNCML_SUPPORT__ */
            {
                mmi_phb_op_update_optional_field(store_index, MMI_NVRAM, 2);
            }
        #if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
            flag = mmi_phb_op_increase_lookup_table(
                    store_index,
                    NULL,
                    (S8*) PhoneBookOptionalFields.faxNumber,
                    (S8*) PhoneBookOptionalFields.homeNumber,
                    (S8*) PhoneBookOptionalFields.officeNumber);
        #endif /* !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */ 

            /* Incoming call video setting */
        #if defined(__MMI_INCOMING_CALL_VIDEO__)
        #if defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC)
            if (g_phb_enter_from == MMI_PHB_ENTER_FROM_JAVA)
            {}
            else
        #endif
        #ifdef __SYNCML_SUPPORT__
            if (g_phb_enter_from == MMI_PHB_ENTER_FROM_SYNCML)
            {}
            else
        #endif /* __SYNCML_SUPPORT__ */
            {
                if ((g_phb_cntx.selected_video_index != g_phb_cntx.total_video_id - 1) /* De-select the file if selection is not from file. */
                #ifdef __MMI_AVATAR__
                    && (g_phb_cntx.selected_video_index != g_phb_cntx.total_video_id - g_phb_avatar_video_minus)
                #endif
                #ifdef __MMI_SWFLASH__
                    && (g_phb_cntx.selected_video_index != g_phb_cntx.total_video_id - g_phb_swflash_video_minus)
                #endif
                    )
                {
                    g_phb_cntx.video_location = MMI_PHB_IMAGE_NO_SELECT;
                }
                else if ((g_phb_cntx.selected_video_index == g_phb_cntx.total_video_id - 1) &&
                    (g_phb_cntx.video_location == MMI_PHB_IMAGE_NO_SELECT 
                #ifdef __MMI_AVATAR__
                    || g_phb_cntx.video_location == MMI_PHB_AVATAR_SELECT_PATH
                #endif
                #ifdef __MMI_SWFLASH__
                    || g_phb_cntx.video_location == MMI_PHB_SWFLASH_SELECT_PATH
                #endif
                    ))
                {
                    g_phb_cntx.selected_video_index = 0;
                    g_phb_cntx.video_location = MMI_PHB_IMAGE_NO_SELECT;
                }
            #ifdef __MMI_AVATAR__
                else if ((g_phb_cntx.selected_video_index == g_phb_cntx.total_video_id - g_phb_avatar_video_minus) &&
                    (g_phb_cntx.video_location != MMI_PHB_AVATAR_SELECT_PATH))
                {
                    g_phb_cntx.selected_video_index = 0;
                    g_phb_cntx.video_location = MMI_PHB_IMAGE_NO_SELECT;
                }
            #endif /* def __MMI_AVATAR__ */
            #ifdef __MMI_SWFLASH__
                else if ((g_phb_cntx.selected_video_index == g_phb_cntx.total_video_id - g_phb_swflash_video_minus) &&
                    (g_phb_cntx.video_location != MMI_PHB_SWFLASH_SELECT_PATH))
                {
                    g_phb_cntx.selected_video_index = 0;
                    g_phb_cntx.video_location = MMI_PHB_IMAGE_NO_SELECT;
                }
            #endif /* def __MMI_AVATAR__ */
                else if (g_phb_cntx.video_location == MMI_PHB_IMAGE_NO_SELECT)      /* Set selection to none if not select picture from file */
                {
                    g_phb_cntx.selected_video_index = 0;
                }
                copy_video = mmi_phb_video_update_by_index(store_index);
                if (!copy_video)    /* Update video fail. */
                {
                    g_phb_cntx.selected_video_index = 0;
                }
            }
        #endif /* __MMI_INCOMING_CALL_VIDEO__ */
        #ifdef __SYNCML_SUPPORT__
            mmi_syncml_phb_data_changed_notification(SYNCML_RECORD_MODIFY, store_index);
        #endif
        }
    #if defined(__MMI_PHB_CALLERGROUP_IN_SIM__)     /* Associate caller group in SIM card entry */
        else    /* in MMI_SIM */
        {
        #if defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC)
            if (g_phb_enter_from == MMI_PHB_ENTER_FROM_JAVA)
            {
                mmi_phb_op_update_optional_field(store_index, MMI_SIM, 0);
            }
            else
        #endif /* defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC) */ 
            mmi_phb_op_update_optional_field(store_index, MMI_SIM, 2);
        }
    #endif /* defined(__MMI_PHB_CALLERGROUP_IN_SIM__) */ 

        flag += mmi_phb_op_increase_lookup_table(store_index, (S8*) localPtr->list[0].tel.number, NULL, NULL, NULL);

        if (deletedCnt || flag)
        {
            mmi_phb_lookup_table_sort();
            g_phb_cntx.lookup_table_count -= deletedCnt;
        }

        mmi_phb_op_set_entry_rsp_name_number(&localPtr->list[0], store_index);

        /* Update is column exists flag. */
        if (localPtr->list[0].storage == MMI_SIM)
        {
            mmi_phb_op_update_field_flag(
                store_index,
                (S8*) localPtr->list[0].tel.number,
                NULL,
                NULL,
                NULL,
                NULL,
                FALSE);
        }
        else
        {
        #if defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
            mmi_phb_op_update_field_flag(
                store_index,
                (S8*) localPtr->list[0].tel.number,
                NULL,
                NULL,
                NULL,
                NULL,
                FALSE);
        #else /* defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */ 
            mmi_phb_op_update_field_flag(
                store_index,
                (S8*) localPtr->list[0].tel.number,
                (S8*) PhoneBookOptionalFields.homeNumber,
                (S8*) PhoneBookOptionalFields.officeNumber,
                (S8*) PhoneBookOptionalFields.faxNumber,
                (S8*) PhoneBookOptionalFields.emailAddress,
                FALSE);
        #endif /* defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */ 

            /* Save birthday field */
        #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
            if (!bday_modified)
            {
                mmi_phb_util_clear_bday_buffer();
            }
            mmi_phb_bday_update_field(store_index, (S8*) pbYear, (S8*) pbMon, (S8*) pbDay);
            ResetInlineItemChangedNotification();
        #endif /* defined(__MMI_PHB_BIRTHDAY_FIELD__) */ 
        }

        if (PhoneBook[store_index].alpha_id.name_length)
        {
            PhoneBook[store_index].field |= MMI_PHB_ENTRY_FIELD_NAME;
        }
    #if defined(__MMI_PHB_PINYIN_SORT__)    /* Update Pinyin Cache for sort */
        mmi_phb_util_make_pinyin_cache(store_index);
    #endif 

        /* Name sorting mapping table should Re-Sort HERE, and get the new highlight position!!! */
        mmi_phb_op_delete_update_index(store_index);
        g_phb_cntx.new_highlight_entry = mmi_phb_sort_insert_name_index(store_index);
        g_phb_cntx.refresh_list = MMI_PHB_ENTRY_REFRESH;

        /* Update email sorting mapping table */
    #if defined(__MMI_PHB_EMAIL_SORT__)
        if ((localPtr->list[0].storage == MMI_NVRAM) && (g_phb_email_sorted == 1))
        {
            mmi_phb_sort_email_delete_index(store_index);
            mmi_phb_sort_email_insert_index(store_index);
        }
    #endif /* defined(__MMI_PHB_EMAIL_SORT__) */ 

        /* add central command for vrsi. */
    #if defined(__MMI_VRSI__)
        mmi_vrsi_ndial_central_change_single(store_index);
    #endif 

    #if defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC)
        if (g_phb_enter_from == MMI_PHB_ENTER_FROM_JAVA)
        {
            mmi_phb_java_write_rsp(MMI_PHB_JAVA_SUCCESS, store_index);
            g_phb_enter_from = MMI_PHB_ENTER_NONE;
        }
        else
    #endif /* defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC) */ 
    #if defined(__SYNCML_SUPPORT__)
        if (g_phb_enter_from == MMI_PHB_ENTER_FROM_SYNCML)
        {
            mmi_syncml_phb_sync_rsp(MMI_PHB_SYNC_SUCCESS, store_index);
            g_phb_enter_from = MMI_PHB_ENTER_NONE;
        }
        else
    #endif /* __SYNCML_SUPPORT__ */ 
        /* Data update success, but image or video add fail */
        {
            if (!copy_image || !copy_video)
            {
                S8 str_buff[64 * 2];

                memset(str_buff, 0, 2);

                if (!copy_image)
                {
                    mmi_ucs2cat(str_buff, GetString(STR_ID_PHB_OP_IMAGE_FAIL));
                }

                if (!copy_video)
                {
                    if (!copy_image)
                    {
                        mmi_ucs2cat(str_buff, GetString(STR_ID_PHB_OP_COMMA));
                    }
                    mmi_ucs2cat(str_buff, GetString(STR_ID_PHB_OP_VIDEO_FAIL));
                }

                mmi_ucs2cat(str_buff, GetString(STR_ID_PHB_EDIT_FAIL));
                DisplayPopup((U8*) str_buff, IMG_GLOBAL_ERROR, TRUE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
            }
            else
            {
                DisplayPopup(
                    (PU8) GetString(STR_GLOBAL_SAVED),
                    IMG_GLOBAL_ACTIVATED,
                    TRUE,
                    PHB_NOTIFY_TIMEOUT,
                    SUCCESS_TONE);
            }
            mmi_phb_clear_old_edit_history();
        }
    }
#if defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC)
	else if(g_phb_enter_from == MMI_PHB_ENTER_FROM_JAVA )
	{
		mmi_phb_java_write_rsp(localPtr->result.cause, 0xffff);
        g_phb_enter_from = MMI_PHB_ENTER_NONE;
	}
#endif /* defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC) */
#if defined(__SYNCML_SUPPORT__)
    else if (g_phb_enter_from == MMI_PHB_ENTER_FROM_SYNCML)
    {
        mmi_syncml_phb_sync_rsp(MMI_PHB_SYNC_ERROR, 0xFFFF);
        g_phb_enter_from = MMI_PHB_ENTER_NONE;
    }
#endif /* __SYNCML_SUPPORT__ */ 
    else if (localPtr->result.cause == MMI_SIM_EF_RECORD_FULL)
    {
        DisplayPopup(
            (PU8) GetString(STR_NOT_SAVED_NUMBER_TOO_LONG),
            IMG_GLOBAL_ERROR,
            FALSE,
            PHB_NOTIFY_TIMEOUT,
            ERROR_TONE);
        DeleteUptoScrID(SCR_INLINE_EDIT);
    }
    else
    {
        if (gSecuritySetupContext.FdlStatus)    /* For FDN on Message */
        {
            DisplayPopup(
                (PU8) GetString(STR_FDL_IS_ON),
                IMG_GLOBAL_UNFINISHED,
                TRUE,
                PHB_NOTIFY_TIMEOUT,
                ERROR_TONE);
        }
        else
        {
            DisplayPopup(
                (PU8) GetString(STR_GLOBAL_UNFINISHED),
                IMG_GLOBAL_UNFINISHED,
                TRUE,
                PHB_NOTIFY_TIMEOUT,
                ERROR_TONE);
        }

        mmi_phb_clear_old_edit_history();
    }
    g_phb_cntx.current_op = MMI_PHB_OP_NONE;  
}


#define MMI_PHB_OP_DELETE
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_op_delete_entry
 * DESCRIPTION
 *  Highlight handler for "Delete" in Entry options menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_op_delete_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_phb_entry_op_delete_confirm, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_op_delete_confirm
 * DESCRIPTION
 *  Confirms before deleting a phone book entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_op_delete_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_DELETE_QUERY_MSG),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_phb_op_delete_entry_req, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_delete_entry_req
 * DESCRIPTION
 *  Sends the request to stack to delete
 *  a phone book entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_delete_entry_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_DELETE_ENTRY_REQ_STRUCT *myMsgPtr;
    MYQUEUE Message;
    U16 store_index;
    U8 storage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_op_delete_entry_req.>\n", __FILE__,
                         __LINE__);

#if defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC)
    if (g_phb_enter_from == MMI_PHB_ENTER_FROM_JAVA)
    {
        ASSERT(g_phb_cntx.java_store_index < MAX_PB_ENTRIES)
        store_index = g_phb_cntx.java_store_index;
    }
    else
#endif /* defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC) */
#ifdef __SYNCML_SUPPORT__
    if (g_phb_enter_from == MMI_PHB_ENTER_FROM_SYNCML)
    {
        store_index = g_phb_cntx.active_index;
    }
    else
#endif /* __SYNCML_SUPPORT__ */
    {
        mmi_phb_show_in_progress(STR_GLOBAL_DELETING, IMG_GLOBAL_DELETED);
        store_index = g_phb_name_index[g_phb_cntx.active_index];
#ifdef __MMI_DUAL_SIM_MASTER__
        if (store_index >= MAX_PB_PHONE_ENTRIES+MAX_PB_SIM_ENTRIES)
        {
             MTPNP_AD_DELETE_ADN_Record((unsigned short)(store_index + 1 - MAX_PB_PHONE_ENTRIES - MAX_PB_SIM_ENTRIES));
             return;                     
        }
#endif	/* __MMI_DUAL_SIM_MASTER__ */
    }

    myMsgPtr = (MSG_PHB_DELETE_ENTRY_REQ_STRUCT*) OslConstructDataPtr(sizeof(MSG_PHB_DELETE_ENTRY_REQ_STRUCT));
    storage = (store_index >= MAX_PB_PHONE_ENTRIES) ? MMI_SIM : MMI_NVRAM;

    myMsgPtr->storage = storage;
    myMsgPtr->del_all = MMI_FALSE;
    myMsgPtr->no_data = 1;
    myMsgPtr->type = MMI_PHB_PHONEBOOK;
    /*
     *The index means "record_index" here. This change only for MMI_PHB_PHONEBOOK(ADN) type
     * for other type( BDN ,FDN, MSISDN...) This field still need to use index as parameter.
     */
    myMsgPtr->index = (storage == MMI_SIM) ? (store_index + 1) - MAX_PB_PHONE_ENTRIES : (store_index + 1);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_PHB_DEL_ENTRY_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler(mmi_phb_op_delete_entry_rsp, PRT_PHB_DEL_ENTRY_RSP);
    OslMsgSendExtQueue(&Message);
    DeleteNScrId(SCR_PBOOK_ENTRY_OPTIONS);
#ifdef __MMI_MULTITAP_FOR_STAR_AND_POUND__
    DeleteScreenIfPresent(SCR_ID_PHB_QUICK_SEARCH_OPTION);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_delete_entry_rsp
 * DESCRIPTION
 *  Handles the response from stack after
 *  the entry is deleted
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_delete_entry_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_DELETE_ENTRY_RSP_STRUCT *localPtr;
    U16 deletedCnt = 0;
    U16 store_index;
    U16 record_index;
    U8 storage;
#if defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__)    
    PHB_OPTIONAL_IDS_STRUCT *opt_ids;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* PHB_CALLER_GROUP_STRUCT* callerGroups; */

    localPtr = (MSG_PHB_DELETE_ENTRY_RSP_STRUCT*) info;
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_op_delete_entry_rsp.>\n", __FILE__,
                         __LINE__);

    if (localPtr->result.flag == 0 /* OK */ )
    {

    #if defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC)
        if (g_phb_enter_from == MMI_PHB_ENTER_FROM_JAVA)
        {
            store_index = g_phb_cntx.java_store_index;
        }
        else
    #endif /* defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC) */ 
    #if defined(__SYNCML_SUPPORT__)
        if (g_phb_enter_from == MMI_PHB_ENTER_FROM_SYNCML)
        {
            store_index = g_phb_cntx.active_index;
        }
        else
    #endif /* defined(__SYNCML_SUPPORT__) */ 
        {
            store_index = g_phb_name_index[g_phb_cntx.active_index];
        }
        storage = (store_index >= MAX_PB_PHONE_ENTRIES) ? MMI_SIM : MMI_NVRAM;
        record_index = (storage == MMI_SIM) ? (store_index + 1) - MAX_PB_PHONE_ENTRIES : (store_index + 1);

        PhbUpdateSpeedDial(storage, record_index, MMI_PHB_PHONEBOOK, NULL, NULL);

        if (store_index >= MAX_PB_PHONE_ENTRIES)    /* Record store in SIM, SIM index is begin from "MAX_PB_PHONE_ENTRIES" */
        {
            g_phb_cntx.sim_used--;
        #if defined(__MMI_PHB_EMAIL_SORT__) && defined(__MMI_PHB_USIM_FIELD__)
            if (g_phb_email_sorted == 1)
            {
                mmi_phb_sort_email_delete_index(store_index);
            }
        #endif /* defined(__MMI_PHB_EMAIL_SORT__) && defined(__MMI_PHB_USIM_FIELD__) */ 
        }
        else
        {
            g_phb_cntx.phone_used--;
        #if defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__)
            /* Delete image file in file folder */
            mmi_phb_read_optional_ids(store_index);
            opt_ids = (PHB_OPTIONAL_IDS_STRUCT*) g_phb_cntx.optional_ids;

            if ((opt_ids->pictureTagID == 1)
            #ifdef __MMI_AVATAR__
                || (opt_ids->pictureTagID == 2)
            #endif
                )
            {
                mmi_phb_image_delete_by_index(record_index);
            }
        #endif /* defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__) */ 
            /* Delete incoming call video */
        #if defined(__MMI_INCOMING_CALL_VIDEO__)
            mmi_phb_video_delete_by_index(store_index);
        #endif 
            /* Clear birthday field */
        #if defined(__MMI_PHB_BIRTHDAY_FIELD__) && defined(__MMI_BIRTHDAY_REMINDER__)
            mmi_phb_bday_delete_field(store_index);
        #endif 

            /* Remove email entry from email sort mapping table */
        #if defined(__MMI_PHB_EMAIL_SORT__)
            if (g_phb_email_sorted == 1)
            {
                mmi_phb_sort_email_delete_index(store_index);
            }
        #endif /* defined(__MMI_PHB_EMAIL_SORT__) */ 
        #ifdef __SYNCML_SUPPORT__
            mmi_syncml_phb_data_changed_notification(SYNCML_RECORD_DELETE, store_index);
        #endif
        }

        /* Remove lookup table entry */
        deletedCnt = mmi_phb_op_clear_lookup_table_by_index(store_index);

        if (deletedCnt)
        {
            mmi_phb_lookup_table_sort();
            g_phb_cntx.lookup_table_count -= deletedCnt;
        }

    #if defined(__MMI_VRSD_DIAL__)
        /* remove voice dial tag if exists. */
        mmi_vrsddial_delete_tag_by_store_index(store_index);
    #endif /* defined(__MMI_VRSD_DIAL__) */ 

    #if defined(__MMI_VRSI__)
        /* remove voice dial tag if exists. */
        mmi_vrsi_ndial_central_delete_single(store_index);
    #endif /* defined(__MMI_VRSI__) */ 

        /* clear phonebook entry and remove from index */
        mmi_phb_op_delete_update_index(store_index);

        g_phb_cntx.refresh_list = MMI_PHB_ENTRY_REFRESH;
    #if defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC)
        if (g_phb_enter_from == MMI_PHB_ENTER_FROM_JAVA)
        {
            mmi_phb_java_write_rsp(MMI_PHB_JAVA_SUCCESS, store_index);
            g_phb_enter_from = MMI_PHB_ENTER_NONE;
        }
        else
    #endif /* defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC) */ 
    #if defined(__SYNCML_SUPPORT__)
        if (g_phb_enter_from == MMI_PHB_ENTER_FROM_SYNCML)
        {
            g_phb_enter_from = MMI_PHB_ENTER_NONE;
            mmi_syncml_phb_sync_rsp(MMI_PHB_SYNC_SUCCESS, store_index);
        }
        else
    #endif /* __SYNCML_SUPPORT__ */ 
        {
            DisplayPopup((PU8) GetString(STR_GLOBAL_DELETED), IMG_GLOBAL_ACTIVATED, TRUE, PHB_NOTIFY_TIMEOUT, SUCCESS_TONE);
            if (!PhoneBookEntryCount)
            {
                DeleteNScrId(SCR_PBOOK_LIST);
            }
        }

        /* Change highlight position for deleting the last one */
        if (g_phb_cntx.active_index > (PhoneBookEntryCount - 1))
        {
            g_phb_cntx.new_highlight_entry = 0;
        }
    }
#if defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC)
    else if(g_phb_enter_from == MMI_PHB_ENTER_FROM_JAVA )
    {
        mmi_phb_java_write_rsp(localPtr->result.cause, 0xffff);
        g_phb_enter_from = MMI_PHB_ENTER_NONE;
    }
#endif /* defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC) */
#if defined(__SYNCML_SUPPORT__)
    else if (g_phb_enter_from == MMI_PHB_ENTER_FROM_SYNCML)
    {
        mmi_syncml_phb_sync_rsp(MMI_PHB_SYNC_ERROR, 0xFFFF);
        g_phb_enter_from = MMI_PHB_ENTER_NONE;
    }
#endif /* __SYNCML_SUPPORT__ */ 

    else if (gSecuritySetupContext.FdlStatus)   /* For FDN on Message */
   {
        DisplayPopup((PU8) GetString(STR_FDL_IS_ON), IMG_GLOBAL_UNFINISHED, TRUE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_UNFINISHED,
            TRUE,
            PHB_NOTIFY_TIMEOUT,
            ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_delete_update_index
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  store_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_delete_update_index(U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 pos, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* It is no need to clear entry here, because all entry display depends on name index */
    /* memset(&PhoneBook[store_index], 0, sizeof(MMI_PHB_ENTRY_BCD_STRUCT)); */

    for (pos = 0; pos < PhoneBookEntryCount; pos++)
    {
        if (g_phb_name_index[pos] == store_index)
        {
            PhoneBookEntryCount--;
            break;
        }
    }

    for (i = pos; i < PhoneBookEntryCount; i++)
    {
        g_phb_name_index[i] = g_phb_name_index[i + 1];
    }

}

#define MMI_PHB_OP_COPY_MOVE_DUP


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_op_copy_entry
 * DESCRIPTION
 *  Highlight handler for "Copy" in Entry options menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_op_copy_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_phb_entry_op_copy_confirm, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_op_move_entry
 * DESCRIPTION
 *  Highlight handler for "Move" in Entry Options menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_op_move_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_phb_entry_op_move_confirm, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_op_duplicate_entry
 * DESCRIPTION
 *  Highlight handler for "Duplicate" in Entry Options menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_op_duplicate_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
    if (g_phb_name_index[g_phb_cntx.active_index] >= MAX_PB_PHONE_ENTRIES+MAX_PB_SIM_ENTRIES)
    {
         SetLeftSoftkeyFunction (MTPNP_Slave_PB_Duplicate_confirm, KEY_EVENT_UP);
    }
    else
#endif/* __MMI_DUAL_SIM_MASTER__ */
    SetLeftSoftkeyFunction(mmi_phb_entry_op_dulicate_confirm, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_op_copy_confirm
 * DESCRIPTION
 *  Confirms before copying entry from one
 *  location to another
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_op_copy_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_entry_op_copy_confirm.>\n", __FILE__,
                         __LINE__);

    copyEntry = TRUE;
    moveEntry = FALSE;
    duplicateEntry = FALSE;

    if ((g_phb_name_index[g_phb_cntx.active_index] < MAX_PB_PHONE_ENTRIES) &&
        (g_phb_cntx.sim_used == g_phb_cntx.sim_total))
    {
    #ifdef __MMI_DUAL_SIM_MASTER__
        DisplayPopup((PU8) GetString(STRING_MTPNP_SIM1_STORAGE_FULL), IMG_GLOBAL_ERROR, FALSE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);    
    #else /* __MMI_DUAL_SIM_MASTER__ */
        DisplayPopup((PU8) GetString(STR_SIM_FULL_MSG), IMG_GLOBAL_ERROR, FALSE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
    #endif /* __MMI_DUAL_SIM_MASTER__ */
    }
    else if ((g_phb_name_index[g_phb_cntx.active_index] >= MAX_PB_PHONE_ENTRIES) &&
             (g_phb_cntx.phone_used == g_phb_cntx.phone_total))
    {
        DisplayPopup((PU8) GetString(STR_PHONE_FULL_MSG), IMG_GLOBAL_ERROR, FALSE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
    }
    else
    {
        DisplayConfirm(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(STR_COPY_QUERY_MSG),
            IMG_GLOBAL_QUESTION,
            WARNING_TONE);

        SetLeftSoftkeyFunction(mmi_phb_op_copy_move_dup_pre_req, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_op_move_confirm
 * DESCRIPTION
 *  Confirms before moving the entry which
 *  the user selects from the PHB list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_op_move_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_entry_op_move_confirm.>\n", __FILE__,
                         __LINE__);
    moveEntry = TRUE;
    copyEntry = FALSE;
    duplicateEntry = FALSE;

    if ((g_phb_name_index[g_phb_cntx.active_index] < MAX_PB_PHONE_ENTRIES) &&
        (g_phb_cntx.sim_used == g_phb_cntx.sim_total))
    {
    #ifdef __MMI_DUAL_SIM_MASTER__
        DisplayPopup((PU8) GetString(STRING_MTPNP_SIM1_STORAGE_FULL), IMG_GLOBAL_ERROR, FALSE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);    
    #else /* __MMI_DUAL_SIM_MASTER__ */
        DisplayPopup((PU8) GetString(STR_SIM_FULL_MSG), IMG_GLOBAL_ERROR, FALSE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
    #endif /* __MMI_DUAL_SIM_MASTER__ */
    }
    else if ((g_phb_name_index[g_phb_cntx.active_index] >= MAX_PB_PHONE_ENTRIES) &&
             (g_phb_cntx.phone_used == g_phb_cntx.phone_total))
    {
        DisplayPopup((PU8) GetString(STR_PHONE_FULL_MSG), IMG_GLOBAL_ERROR, FALSE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
    }
    else
    {
        DisplayConfirm(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(STR_MOVE_QUERY_MSG),
            IMG_GLOBAL_QUESTION,
            WARNING_TONE);

        SetLeftSoftkeyFunction(mmi_phb_op_copy_move_dup_pre_req, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_op_dulicate_confirm
 * DESCRIPTION
 *  Confirms before duplicating the entry which
 *  the user selects from the PHB list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_op_dulicate_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index;
    U16 str_id = 0;

#if defined(__MMI_FILE_MANAGER__)
    PHB_OPTIONAL_IDS_STRUCT *opt_ids;
#endif 
#if defined(__MMI_INCOMING_CALL_VIDEO__)
    U16 video_id;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    duplicateEntry = TRUE;
    copyEntry = FALSE;
    moveEntry = FALSE;

    store_index = g_phb_name_index[g_phb_cntx.active_index];

    if ((store_index >= MAX_PB_PHONE_ENTRIES) && (g_phb_cntx.sim_used == g_phb_cntx.sim_total))
    {
    #ifdef __MMI_DUAL_SIM_MASTER__
        str_id = STRING_MTPNP_SIM1_STORAGE_FULL;    
    #else /* __MMI_DUAL_SIM_MASTER__ */
        str_id = STR_SIM_FULL_MSG;
    #endif /* __MMI_DUAL_SIM_MASTER__ */
    }
    else if ((store_index < MAX_PB_PHONE_ENTRIES) && (g_phb_cntx.phone_used == g_phb_cntx.phone_total))
    {
        str_id = STR_PHONE_FULL_MSG;
    }
    else if (store_index < MAX_PB_PHONE_ENTRIES)
    {
        /* Check disc space before copy image */
    #if defined(__MMI_FILE_MANAGER__)
        mmi_phb_read_optional_ids(store_index);
        opt_ids = (PHB_OPTIONAL_IDS_STRUCT*) g_phb_cntx.optional_ids;

        if (opt_ids->pictureTagID == 1)
        {
            mmi_phb_image_get_full_path_by_index((U16) (store_index + 1), g_phb_file_path);

            if ((mmi_ucs2strlen(g_phb_file_path) > 0) && (!mmi_phb_image_check_valid_image(g_phb_file_path)))
            {
                return;
            }
        }
    #endif /* defined(__MMI_FILE_MANAGER__) */ 

        /* Check data store space before copy video */
    #if defined(__MMI_INCOMING_CALL_VIDEO__)
        video_id = mmi_phb_video_get_id_by_index(store_index);

        if ((video_id & 0x8000) && (!mmi_phb_video_check_data_space(NULL)))
        {
            return;
        }
    #endif /* defined(__MMI_INCOMING_CALL_VIDEO__) */ 

    }

    if (str_id != 0)
    {
        DisplayPopup((PU8) GetString(str_id), IMG_GLOBAL_ERROR, FALSE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
        return;
    }

    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_DUPLICATE_QUERY_MSG),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_phb_op_copy_move_dup_pre_req, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

#if defined(__MMI_PHB_COMBINE_COPY_DUPLICATE__)


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_op_copy_duplicate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_op_copy_duplicate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_phb_entry_op_copy_duplicate, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_op_copy_duplicate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_op_copy_duplicate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[2];
    U16 nImgIltemList[2];
    U16 nNumofItem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_entry_op_copy_duplicate.>\n", __FILE__,
                         __LINE__);

    EntryNewScreen(SCR_ID_OPTION_COPY_DUPLICATE, mmi_phb_exit_op_copy_duplicate, mmi_phb_entry_op_copy_duplicate, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_OPTION_COPY_DUPLICATE);
    nNumofItem = GetNumOfChild(MENU_ID_PHB_OPTION_COPY_DUPLICATE);
    GetSequenceStringIds(MENU_ID_PHB_OPTION_COPY_DUPLICATE, nStrItemList);
    nImgIltemList[0] = IMG_STORAGE_HANDSET;
#ifdef __MMI_DUAL_SIM_MASTER__
    nImgIltemList[1] = IMG_ID_CARD1_PHB_STORAGE_SIM; 
#else /* __MMI_DUAL_SIM_MASTER__ */
    nImgIltemList[1] = IMG_STORAGE_SIM;
#endif /* __MMI_DUAL_SIM_MASTER__ */

    SetParentHandler(MENU_ID_PHB_OPTION_COPY_DUPLICATE);

    if (g_phb_name_index[g_phb_cntx.active_index] >= MAX_PB_PHONE_ENTRIES)      /* Entry in SIM */
    {
        SetHiliteHandler(MITEM1013_PBOOK_COPY_ENTRY, mmi_phb_highlight_op_copy_entry);
        SetHiliteHandler(MITEM1015_PBOOK_DUPLICATE, mmi_phb_highlight_op_duplicate_entry);
    }
    else    /* Entry in NVRAM */
    {
        SetHiliteHandler(MITEM1015_PBOOK_DUPLICATE, mmi_phb_highlight_op_copy_entry);
        SetHiliteHandler(MITEM1013_PBOOK_COPY_ENTRY, mmi_phb_highlight_op_duplicate_entry);
    }

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory15Screen(
        STR_ID_PHB_OPTION_COPY_DUPLICATE,
        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        nImgIltemList,
        LIST_MENU,
        0,
        guiBuffer);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_op_copy_duplicate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_exit_op_copy_duplicate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.end_scr_id = SCR_ID_OPTION_COPY_DUPLICATE;
}
#endif /* defined(__MMI_PHB_COMBINE_COPY_DUPLICATE__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_copy_move_dup_pre_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_copy_move_dup_pre_req(void)
{
#ifdef __MMI_PHB_USIM_FIELD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.is_usim && duplicateEntry && g_phb_name_index[g_phb_cntx.active_index] >= MAX_PB_PHONE_ENTRIES)
    {
        mmi_phb_op_copy_move_dup_usim_req();
    }
    else if (g_phb_cntx.is_usim && (moveEntry || copyEntry) && g_phb_name_index[g_phb_cntx.active_index] < MAX_PB_PHONE_ENTRIES)        /* copy/move from nvram to usim */
    {
        /* mmi_phb_op_copy_move_usim_req(); */
        mmi_phb_op_copy_move_dup_usim_req();
    }
    else
#endif /* __MMI_PHB_USIM_FIELD__ */ 
    {
        mmi_phb_op_copy_move_dup_req();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_copy_move_dup_req
 * DESCRIPTION
 *  Sends the request to the stack to copy/move/duplicate an entry that the user selects from the phonebook list.
 *  that the user selects from the phonebook list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_copy_move_dup_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_SET_ENRTY_REQ_STRUCT *myMsgPtr;
    MYQUEUE Message;
    U16 store_index;
    U8 storage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_op_copy_move_dup_req.>\n", __FILE__,
                         __LINE__);

    store_index = g_phb_name_index[g_phb_cntx.active_index];
    storage = (store_index >= MAX_PB_PHONE_ENTRIES) ? MMI_SIM : MMI_NVRAM;

    myMsgPtr = (MSG_PHB_SET_ENRTY_REQ_STRUCT*) OslConstructDataPtr(sizeof(MSG_PHB_SET_ENRTY_REQ_STRUCT));
    myMsgPtr->type = MMI_PHB_PHONEBOOK;
    myMsgPtr->no_data = 1;
    myMsgPtr->list.index = 0xFFFF;
    myMsgPtr->list.record_index = 0xFFFF;

    if (copyEntry)
    {
        mmi_phb_show_in_progress(STR_GLOBAL_COPYING, IMG_COPIED);
        if (storage == MMI_SIM)
        {
            myMsgPtr->list.storage = MMI_NVRAM;
        }
        else
        {
            myMsgPtr->list.storage = MMI_SIM;
        }
    }
    else if (duplicateEntry)
    {
        mmi_phb_show_in_progress(STR_PHB_DUPLICATING, IMG_ENTRY_DUPLICATED_MSG);
        myMsgPtr->list.storage = storage;
    }
    else if (moveEntry)
    {
        moveEntryStoreIndex = store_index;

        mmi_phb_show_in_progress(STR_GLOBAL_MOVING, IMG_ENTRY_MOVED_MSG);
        if (storage == MMI_SIM)
        {
            myMsgPtr->list.storage = MMI_NVRAM;
        }
        else
        {
            myMsgPtr->list.storage = MMI_SIM;
        }
    }

    mmi_phb_op_set_entry_prepare_name_number_by_index(&myMsgPtr->list, store_index);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_PHB_SET_ENTRY_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler(mmi_phb_op_copy_move_dup_rsp, PRT_PHB_SET_ENTRY_RSP);
    OslMsgSendExtQueue(&Message);
    DeleteNScrId(SCR_PBOOK_ENTRY_OPTIONS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_copy_move_dup_rsp
 * DESCRIPTION
 *  Handles the response from stack after the entry is copied/moved/duplicated.
 * PARAMETERS
 *  info        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_copy_move_dup_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_SET_ENRTY_RSP_STRUCT *localPtr;
    U8 modified;
    U8 flag = 0;
    U8 num_ascii[MAX_PB_NUMBER_LENGTH + 1 + 1];
#if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) || defined(__MMI_PHB_INFO_FIELD__) || defined(__MMI_PHB_IMPS_FIELD__) || defined(__MMI_VOIP__)
    S16 pError;
#endif
    BOOL copy_image = TRUE, copy_video = TRUE;
    U16 store_index, src_store_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (MSG_PHB_SET_ENRTY_RSP_STRUCT*) info;
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_op_copy_move_dup_rsp.>\n", __FILE__,
                         __LINE__);

    if (localPtr->result.flag == 0 /* OK */ )
    {

        src_store_index = g_phb_name_index[g_phb_cntx.active_index];

        store_index = mmi_phb_op_get_store_index_and_increase_counter(localPtr->list[0].storage, localPtr->list[0].record_index);

        if (copyEntry || moveEntry)
        {
            if (localPtr->list[0].storage == MMI_NVRAM) /* From SIM to NVRAM */
            {
            #if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
                /* Optional Fields */
                memset(&PhoneBookOptionalFields, 0, sizeof(PhoneBookOptionalFields));
            #ifdef __MMI_PHB_USIM_FIELD__
                mmi_phb_op_set_option_data_by_usim_index(src_store_index, &PhoneBookOptionalFields);
            #endif 
                WriteRecord(
                    NVRAM_EF_PHB_FIELDS_LID,
                    (U16) (localPtr->list[0].record_index),
                    (void*)&PhoneBookOptionalFields,
                    OPTIONAL_FIELDS_RECORD_SIZE,
                    &pError);
            #endif /* !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */ 
                /* Clear Optional Selection Fields */
                mmi_phb_clear_optional_ids(store_index);

                /* Clear video field. */
            #if defined(__MMI_INCOMING_CALL_VIDEO__)
                mmi_phb_video_delete_by_index(store_index);
            #endif 
                /* Clear birthday field */
            #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
                mmi_phb_bday_delete_field(store_index);
            #endif 
            #if defined(__MMI_PHB_INFO_FIELD__)
                /* Information Fields */
                mmi_phb_info_delete_field(store_index);
            #endif /* defined(__MMI_PHB_INFO_FIELD__) */ 
            #if defined(__MMI_PHB_IMPS_FIELD__) || defined(__MMI_PHB_POC_FIELD__) || defined(__MMI_VOIP__)
                mmi_phb_service_delete_field(store_index);
            #endif 
            #ifdef __SYNCML_SUPPORT__
                mmi_syncml_phb_data_changed_notification(SYNCML_RECORD_ADD, store_index);
            #endif
            }
        #if defined(__MMI_PHB_CALLERGROUP_IN_SIM__)     /* Associate caller group in SIM card entry */
            mmi_phb_copy_optional_ids(store_index, src_store_index);

            if (localPtr->list[0].storage == MMI_SIM)
            {
                mmi_phb_clear_optional_ids_for_sim(store_index);
            }
        #endif /* defined(__MMI_PHB_CALLERGROUP_IN_SIM__) */ 
        }
        else /* Duplicate Entry */
        {
        #if !defined(__MMI_PHB_CALLERGROUP_IN_SIM__)    /* Associate caller group in SIM card entry */
            if (localPtr->list[0].storage == MMI_NVRAM)
        #endif 
            {
                copy_image = mmi_phb_copy_optional_ids(store_index, src_store_index);
            }

            if (localPtr->list[0].storage == MMI_NVRAM)
            {
            #if defined(__MMI_INCOMING_CALL_VIDEO__)
                copy_video = mmi_phb_video_duplicate_by_index(store_index, src_store_index);
            #endif 

            #if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
                /* Optional Fields */
                ReadRecord(
                    NVRAM_EF_PHB_FIELDS_LID,
                    (U16) (src_store_index + 1),
                    (void*)&PhoneBookOptionalFields,
                    OPTIONAL_FIELDS_RECORD_SIZE,
                    &pError);
                WriteRecord(
                    NVRAM_EF_PHB_FIELDS_LID,
                    (U16) (localPtr->list[0].record_index),
                    (void*)&PhoneBookOptionalFields,
                    OPTIONAL_FIELDS_RECORD_SIZE,
                    &pError);

                flag = mmi_phb_op_increase_lookup_table(
                        store_index,
                        NULL,
                        (S8*) PhoneBookOptionalFields.faxNumber,
                        (S8*) PhoneBookOptionalFields.homeNumber,
                        (S8*) PhoneBookOptionalFields.officeNumber);
            #endif /* !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */ 
                /* Duplicate birthday field */
            #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
                mmi_phb_bday_duplicate_field(store_index, src_store_index);
            #endif 
            #if defined(__MMI_PHB_INFO_FIELD__)
                /* Information Fields */
                ReadRecord(
                    NVRAM_EF_PHB_INFO_LID,
                    (U16) (src_store_index + 1),
                    (void*)&PhoneBookInfoFields,
                    MMI_PHB_INFO_RECORD_SIZE,
                    &pError);
                WriteRecord(
                    NVRAM_EF_PHB_INFO_LID,
                    (U16) (localPtr->list[0].record_index),
                    (void*)&PhoneBookInfoFields,
                    MMI_PHB_INFO_RECORD_SIZE,
                    &pError);
            #endif /* defined(__MMI_PHB_INFO_FIELD__) */ 
            #if defined(__MMI_PHB_IMPS_FIELD__)
                /* IMPS Fields */
                ReadRecord(
                    NVRAM_EF_PHB_IMPS_LID,
                    (U16) (src_store_index + 1),
                    (void*)&PhoneBookImpsField,
                    MAX_PB_IMPS_LENGTH + 1,
                    &pError);
                WriteRecord(
                    NVRAM_EF_PHB_IMPS_LID,
                    (U16) (localPtr->list[0].record_index),
                    (void*)&PhoneBookImpsField,
                    MAX_PB_IMPS_LENGTH + 1,
                    &pError);
            #endif /* defined(__MMI_PHB_IMPS_FIELD__) */ 
            #if defined(__MMI_VOIP__)
                /* VOIP Fields */
                ReadRecord(
                    NVRAM_EF_PHB_VOIP_LID,
                    (U16) (src_store_index + 1),
                    (void*)&PhoneBookVoipField,
                    VOIP_URI_LEN,
                    &pError);
                WriteRecord(
                    NVRAM_EF_PHB_VOIP_LID,
                    (U16) (localPtr->list[0].record_index),
                    (void*)&PhoneBookVoipField,
                    VOIP_URI_LEN,
                    &pError);
            #endif /* defined(__MMI_VOIP__) */ 
            #ifdef __SYNCML_SUPPORT__
                mmi_syncml_phb_data_changed_notification(SYNCML_RECORD_ADD, store_index);
            #endif
            }
        }

        modified = PhoneBook[src_store_index].alpha_id.name_length - localPtr->list[0].alpha_id.name_length;

        mmi_phb_convert_to_digit(num_ascii, PhoneBook[src_store_index].tel.number, MAX_PB_NUMBER_LENGTH + 1);
        flag += mmi_phb_op_increase_lookup_table(store_index, (S8*) num_ascii, NULL, NULL, NULL);

        if (flag)
        {
            mmi_phb_lookup_table_sort();
        }

        mmi_phb_op_set_entry_rsp_name_number(&localPtr->list[0], store_index);

        if (localPtr->list[0].storage == MMI_SIM)
        {
            mmi_phb_op_update_field_flag(
                store_index,
                (S8*) localPtr->list[0].tel.number,
                NULL,
                NULL,
                NULL,
                NULL,
                TRUE);
        }
        else
        {
        #if defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
            mmi_phb_op_update_field_flag(
                store_index,
                (S8*) localPtr->list[0].tel.number,
                NULL,
                NULL,
                NULL,
                NULL,
                TRUE);
        #else /* defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */ 
            mmi_phb_op_update_field_flag(
                store_index,
                (S8*) localPtr->list[0].tel.number,
                (S8*) PhoneBookOptionalFields.homeNumber,
                (S8*) PhoneBookOptionalFields.officeNumber,
                (S8*) PhoneBookOptionalFields.faxNumber,
                (S8*) PhoneBookOptionalFields.emailAddress,
                TRUE);
        #endif /* defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */ 
        }
        if (PhoneBook[store_index].alpha_id.name_length)
        {
            PhoneBook[store_index].field |= MMI_PHB_ENTRY_FIELD_NAME;
        }
    #if defined(__MMI_PHB_PINYIN_SORT__)    /* Update Pinyin Cache for sort */
        mmi_phb_util_make_pinyin_cache(store_index);
    #endif 

        /* Insert name index to name sorting mapping table. */
        mmi_phb_sort_insert_name_index(store_index);
        g_phb_cntx.refresh_list = MMI_PHB_ENTRY_REFRESH;

        /* Insert email index to email sorting mapping table */
    #if defined(__MMI_PHB_EMAIL_SORT__)
        if ((localPtr->list[0].storage == MMI_NVRAM) && (g_phb_email_sorted == 1))      /* From SIM to NVRAM */
        {
            mmi_phb_sort_email_insert_index(store_index);
        }
    #endif /* defined(__MMI_PHB_EMAIL_SORT__) */ 

        /* add central command for vrsi. */
    #if defined(__MMI_VRSI__)
        mmi_vrsi_ndial_central_add_single(store_index);
    #endif 

        if (moveEntry)
        {
            moveModified = modified;
            mmi_phb_op_move_req();
        }
        else
        {
        #ifndef __MMI_MAINLCD_128X128__
            if (modified)
            {
                DisplayPopup(
                    (PU8) GetString(STR_COPIED_NAME_MODIFIED),
                    IMG_GLOBAL_ACTIVATED,
                    TRUE,
                    PHB_NOTIFY_TIMEOUT,
                    SUCCESS_TONE);
            }
            /* Data duplicate success, but image or video add fail */
            else if (!copy_image || !copy_video)
        #else
            if (!copy_image || !copy_video)
        #endif
            {
                S8 str_buff[64 * 2];

                memset(str_buff, 0, 2);

                if (!copy_image)
                {
                    mmi_ucs2cat(str_buff, GetString(STR_ID_PHB_OP_IMAGE_FAIL));
                }

                if (!copy_video)
                {
                    if (!copy_image)
                    {
                        mmi_ucs2cat(str_buff, GetString(STR_ID_PHB_OP_COMMA));
                    }
                    mmi_ucs2cat(str_buff, GetString(STR_ID_PHB_OP_VIDEO_FAIL));
                }

                mmi_ucs2cat(str_buff, GetString(STR_ID_PHB_DUPLICATE_FAIL));
                DisplayPopup((U8*) str_buff, IMG_GLOBAL_ERROR, TRUE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
            }
            else
            {
                if ((copyEntry || duplicateEntry) && localPtr->list[0].storage == MMI_NVRAM)
                {
                    DisplayPopup(
                        (PU8) GetString(STR_COPIED_TO_PHONE_DONE),
                        IMG_GLOBAL_ACTIVATED,
                        TRUE,
                        PHB_NOTIFY_TIMEOUT,
                        SUCCESS_TONE);
                }
                else if ((copyEntry || duplicateEntry) && localPtr->list[0].storage == MMI_SIM)
                {
                    DisplayPopup(
                    #ifdef __MMI_DUAL_SIM_MASTER__
                        (PU8) GetString(STRING_MTPNP_PHB_COPY_TO_SIM1_DONE),
                    #else /* __MMI_DUAL_SIM_MASTER__ */
                        (PU8) GetString(STR_COPIED_TO_SIM_DONE),
                    #endif /*  __MMI_DUAL_SIM_MASTER__ */
                        IMG_GLOBAL_ACTIVATED,
                        TRUE,
                        PHB_NOTIFY_TIMEOUT,
                        SUCCESS_TONE);
                }
                else
                {
                    DisplayPopup(
                        (PU8) GetString(STR_GLOBAL_DONE),
                        IMG_GLOBAL_ACTIVATED,
                        TRUE,
                        PHB_NOTIFY_TIMEOUT,
                        SUCCESS_TONE);
                }
            }
        }
    }
    else
    {
        if (localPtr->result.cause == MMI_SIM_EF_RECORD_FULL)
        {
            if (copyEntry)
            {
                DisplayPopup(
                    (PU8) GetString(STR_NOT_COPIED_NUMBER_TOO_LONG),
                    IMG_GLOBAL_ERROR,
                    FALSE,
                    PHB_NOTIFY_TIMEOUT,
                    ERROR_TONE);
            }
            else if (moveEntry)
            {
                DisplayPopup(
                    (PU8) GetString(STR_NOT_MOVED_NUMBER_TOO_LONG),
                    IMG_GLOBAL_ERROR,
                    FALSE,
                    PHB_NOTIFY_TIMEOUT,
                    ERROR_TONE);
            }
            else if (duplicateEntry)
            {
                DisplayPopup(
                    (PU8) GetString(STR_NOT_DUPLICATED_NUMBER_TOO_LONG),
                    IMG_GLOBAL_ERROR,
                    FALSE,
                    PHB_NOTIFY_TIMEOUT,
                    ERROR_TONE);
            }
        }
        else if (gSecuritySetupContext.FdlStatus)   /* For FDN on Message */
        {
            DisplayPopup((PU8) GetString(STR_FDL_IS_ON), IMG_GLOBAL_UNFINISHED, TRUE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
        }
        else
        {
            DisplayPopup(
                (PU8) GetString(STR_GLOBAL_UNFINISHED),
                IMG_GLOBAL_UNFINISHED,
                TRUE,
                PHB_NOTIFY_TIMEOUT,
                ERROR_TONE);
        }
    }
    copyEntry = duplicateEntry = moveEntry = FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_move_req
 * DESCRIPTION
 *  This function performs the 2nd step of the
 *  'Move' operation. It sends the request to
 *  L4 to delete the entry, which is already added
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_move_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_DELETE_ENTRY_REQ_STRUCT *myMsgPtr;
    MYQUEUE Message;
    U8 storage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_op_move_req.>\n", __FILE__, __LINE__);

    myMsgPtr = (MSG_PHB_DELETE_ENTRY_REQ_STRUCT*) OslConstructDataPtr(sizeof(MSG_PHB_DELETE_ENTRY_REQ_STRUCT));

    storage = (moveEntryStoreIndex >= MAX_PB_PHONE_ENTRIES) ? MMI_SIM : MMI_NVRAM;

    myMsgPtr->storage = storage;
    myMsgPtr->del_all = MMI_FALSE;
    myMsgPtr->no_data = 1;
    myMsgPtr->type = MMI_PHB_PHONEBOOK;
    /*
     *The index means "record_index" here. This change only for MMI_PHB_PHONEBOOK(ADN) type
     * for other type( BDN ,FDN, MSISDN...) This field still need to use index as parameter.
     */
    myMsgPtr->index =
        (storage == MMI_SIM) ? (moveEntryStoreIndex + 1) - MAX_PB_PHONE_ENTRIES : (moveEntryStoreIndex + 1);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_PHB_DEL_ENTRY_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;

    SetProtocolEventHandler(mmi_phb_op_move_rsp, PRT_PHB_DEL_ENTRY_RSP);
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_move_rsp
 * DESCRIPTION
 *  Response handler for mmi_phb_op_move_req().
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_move_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSG_PHB_DELETE_ENTRY_RSP_STRUCT *localPtr;
    U16 deletedCnt = 0;

    //U8 grpIndex;
    //S16 pError;
    U8 storage;
    U16 record_index;
#if defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__)    
    PHB_OPTIONAL_IDS_STRUCT *opt_ids;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* PHB_CALLER_GROUP_STRUCT* callerGroups; */

    localPtr = (MSG_PHB_DELETE_ENTRY_RSP_STRUCT*) info;
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_op_move_rsp.>\n", __FILE__, __LINE__);

    if (localPtr->result.flag == 0 /* OK */ )
    {

        storage = (moveEntryStoreIndex >= MAX_PB_PHONE_ENTRIES) ? MMI_SIM : MMI_NVRAM;
        record_index =
            (storage == MMI_SIM) ? (moveEntryStoreIndex + 1) - MAX_PB_PHONE_ENTRIES : (moveEntryStoreIndex + 1);

        PhbUpdateSpeedDial(storage, record_index, MMI_PHB_PHONEBOOK, NULL, NULL);

        if (moveEntryStoreIndex >= MAX_PB_PHONE_ENTRIES)    /* Record store in SIM, SIM index is begin from "MAX_PB_PHONE_ENTRIES" */
        {
            g_phb_cntx.sim_used--;
        #if defined(__MMI_PHB_EMAIL_SORT__) && defined(__MMI_PHB_USIM_FIELD__)
            if (g_phb_email_sorted == 1)
            {
                mmi_phb_sort_email_delete_index(moveEntryStoreIndex);
            }
        #endif /* defined(__MMI_PHB_EMAIL_SORT__) && defined(__MMI_PHB_USIM_FIELD__) */ 
        }
        else
        {
            g_phb_cntx.phone_used--;
        #if defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__)
            mmi_phb_read_optional_ids(moveEntryStoreIndex);
            opt_ids = (PHB_OPTIONAL_IDS_STRUCT*) g_phb_cntx.optional_ids;

            /* Delete image file in file folder */
            if (opt_ids->pictureTagID == 1)
            {
                mmi_phb_image_delete_by_index((U16) (moveEntryStoreIndex + 1));
            }
        #endif /* defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__) */ 

        #if defined(__MMI_INCOMING_CALL_VIDEO__)
            mmi_phb_video_delete_by_index(moveEntryStoreIndex); /* Clear video field. */
        #endif 
            /* Clear birthday field */
        #if defined(__MMI_PHB_BIRTHDAY_FIELD__) && defined(__MMI_BIRTHDAY_REMINDER__)
            mmi_phb_bday_delete_field(moveEntryStoreIndex);
        #endif 

            /* Remove email entry from email sort mapping table */
        #if defined(__MMI_PHB_EMAIL_SORT__)
            if (g_phb_email_sorted == 1)
            {
                mmi_phb_sort_email_delete_index(moveEntryStoreIndex);
            }
        #endif /* defined(__MMI_PHB_EMAIL_SORT__) */ 
        #ifdef __SYNCML_SUPPORT__
            mmi_syncml_phb_data_changed_notification(SYNCML_RECORD_DELETE, moveEntryStoreIndex);
        #endif
        }

        /* Remove lookup table entry */
        deletedCnt = mmi_phb_op_clear_lookup_table_by_index(moveEntryStoreIndex);

        if (deletedCnt)
        {
            mmi_phb_lookup_table_sort();
            g_phb_cntx.lookup_table_count -= deletedCnt;
        }

    #if defined(__MMI_VRSD_DIAL__)
        /* remove voice dial tag if exists. */
        mmi_vrsddial_delete_tag_by_store_index(moveEntryStoreIndex);
    #endif /* defined(__MMI_VRSD_DIAL__) */ 

    #if defined(__MMI_VRSI__)
        /* remove voice dial tag if exists. */
        mmi_vrsi_ndial_central_delete_single(moveEntryStoreIndex);
    #endif /* defined(__MMI_VRSI__) */ 

        /* clear phonebook entry and remove from index */
        mmi_phb_op_delete_update_index(moveEntryStoreIndex);

        if (moveModified)
        {
            moveModified = 0;
            DisplayPopup(
                (PU8) GetString(STR_MOVED_NAME_MODIFIED),
                IMG_GLOBAL_ACTIVATED,
                TRUE,
                PHB_NOTIFY_TIMEOUT,
                SUCCESS_TONE);
        }
        else
        {
            if (storage == MMI_SIM)
            {
                DisplayPopup(
                    (PU8) GetString(STR_MOVED_TO_PHONE_DONE),
                    IMG_GLOBAL_ACTIVATED,
                    TRUE,
                    PHB_NOTIFY_TIMEOUT,
                    SUCCESS_TONE);
            }
            else
            {
                DisplayPopup(
                #ifdef __MMI_DUAL_SIM_MASTER__
                    (PU8) GetString(STRING_MTPNP_PHB_MOVE_TO_SIM1_DONE),
                #else /* __MMI_DUAL_SIM_MASTER__ */
                    (PU8) GetString(STR_MOVED_TO_SIM_DONE),
                #endif /* __MMI_DUAL_SIM_MASTER__ */
                    IMG_GLOBAL_ACTIVATED,
                    TRUE,
                    PHB_NOTIFY_TIMEOUT,
                    SUCCESS_TONE);
            }
        }
    }
    else if (gSecuritySetupContext.FdlStatus)   /* For FDN on Message */
    {
        DisplayPopup((PU8) GetString(STR_FDL_IS_ON), IMG_GLOBAL_UNFINISHED, TRUE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_UNFINISHED,
            TRUE,
            PHB_NOTIFY_TIMEOUT,
            ERROR_TONE);
    }
}

#define MMI_PHB_OP_EXTRA_OPERATION


/* Dial from phonebook entry option menu. */
#if defined(__MMI_PHB_DIAL_FROM_PHB__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_list_choose_number_option_dial
 * DESCRIPTION
 *  dial the number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_list_choose_number_option_dial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_list_pre_choose_number_from_option_dial();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_op_dial_number
 * DESCRIPTION
 *  Highlight handler for "Dial" in Entry options menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_op_dial_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_phb_entry_list_choose_number_option_dial, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}
#endif /* defined(__MMI_PHB_DIAL_FROM_PHB__) */ 


/* IP Dial from phonebook entry option menu. */
#if defined(__MMI_PHB_IP_DIAL_FROM_PHB__)


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_list_choose_number_ip_dial
 * DESCRIPTION
 *  Set IP dial to TRUE, then dial the number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_list_choose_number_ip_dial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__IP_NUMBER__)      /* Set IP Dial option to TRUE */
    SetTempUseIPNumber(TRUE);
#endif 

#ifdef __MMI_DUAL_SIM_MASTER__
    MTPNP_AD_Free_Channel(MTPNP_AD_CALL_CHANNEL);
    MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_MASTER);
#endif	/* __MMI_DUAL_SIM_MASTER__ */

    mmi_phb_list_pre_choose_number();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_op_ip_number
 * DESCRIPTION
 *  Highlight handler for "IP Dial" in Entry options menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_op_ip_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_phb_entry_list_choose_number_ip_dial, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}
#endif /* defined(__MMI_PHB_IP_DIAL_FROM_PHB__) */ 

/* Send SMS from phonebook entry option menu. */
#if defined(__MMI_PHB_SEND_SMS_FROM_PHB__)
extern MMI_PHB_LIST_VIEW phbListView;


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sms_pre_send_data_for_entry
 * DESCRIPTION
 *  Prepare data to send sms through PHB
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sms_pre_send_data_for_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsMessagesReEntering())
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_MSG_NOT_READY_YET),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
        return;
    }

    mmi_msg_set_phb_send_case(MMI_SEND_SMS_FROM_PHB);
    g_phb_cntx.active_index_second = g_phb_cntx.active_index;

    phbListView = MMI_PHB_LIST_FOR_SMS;
    mmi_phb_sms_send_data_choose_entry();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_op_send_sms
 * DESCRIPTION
 *  Highlight handler for "Send SMS" in Entry options menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_op_send_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_phb_sms_pre_send_data_for_entry, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_phb_sms_pre_send_data_for_entry, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}
#endif /* defined(__MMI_PHB_SEND_SMS_FROM_PHB__) */ 

/* Send MMS from phonebook entry option menu. */
#if defined(__MMI_PHB_SEND_MMS_FROM_PHB__)


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_mms_pre_send_data_for_entry
 * DESCRIPTION
 *  Highlight handler for "Send SMS" in Entry options menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_mms_pre_send_data_for_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.active_index_second = g_phb_cntx.active_index;
    mmi_phb_mms_send_data_choose_entry();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_op_send_mms
 * DESCRIPTION
 *  Highlight handler for "Send SMS" in Entry options menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_op_send_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_phb_mms_pre_send_data_for_entry, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_phb_mms_pre_send_data_for_entry, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}
#endif /* defined(__MMI_PHB_SEND_MMS_FROM_PHB__) */ 

#define MMI_PHB_IMAGE
/*------------------------------------------------- Image from File Manager------------------------------------------------------------*/
#if defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__)


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_image_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of inline editor image field. Used when file manager exists.
 * PARAMETERS
 *  index       [IN]        Current inline selection index.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_image_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == (g_phb_cntx.total_image_id - 1))
    {
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
        SetLeftSoftkeyFunction(mmi_phb_image_pre_entry_option, KEY_EVENT_UP);
    }
#ifdef __MMI_AVATAR__
    else if (index == (g_phb_cntx.total_image_id - 2)) /* 3D Avatar */
    {
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
        SetLeftSoftkeyFunction(mmi_phb_avatar_image_pre_entry_option, KEY_EVENT_UP);        
    }
#endif /* def __MMI_AVATAR__ */
    else
    {
        ChangeLeftSoftkey(STR_VIEW_LSK, IMG_VIEW_LSK);
        SetLeftSoftkeyFunction(mmi_phb_entry_op_edit_view_picture, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_image_pre_entry_option
 * DESCRIPTION
 *  Phonebook associate image operation: View, select, delete.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_image_pre_entry_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_phb_cntx.image_location == MMI_PHB_IMAGE_NO_SELECT)
    #ifdef __MMI_AVATAR__
        || (g_phb_cntx.image_location == MMI_PHB_AVATAR_SELECT_PATH)
    #endif
        || ((g_phb_cntx.image_location == MMI_PHB_IMAGE_FOR_ENTRY) && (g_phb_image_type_id != 1))
        || ((g_phb_cntx.image_location == MMI_PHB_IMAGE_CALLER_GROUP) && (g_phb_image_type_id  != 1))
        )
    {
        g_phb_image_type_id = 1;
        mmi_phb_entry_image_option(2);
    }
    else
    {
        mmi_phb_entry_image_option(1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_image_option
 * DESCRIPTION
 *  Phonebook associate image operation: View, select, delete.
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_image_option(U8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[5];
    U16 nNumofItem;
    U32 HideItemId = -1, HideItemId1 = -1;
    U32 maskingByte = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_PHB_IMAGE_OPTION, mmi_phb_exit_image_option, mmi_phb_image_pre_entry_option, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_PHB_IMAGE_OPTION);
    nNumofItem = GetNumOfChild(MENU_ID_PHB_IMAGE_OPTION);
    GetSequenceStringIds(MENU_ID_PHB_IMAGE_OPTION, nStrItemList);
    SetParentHandler(MENU_ID_PHB_IMAGE_OPTION);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* Hide menu item play and delete when file not selected. */
    /* Regiser highlight handler again. */
    mmi_phb_operate_single_init();

    /* File not selected */
    if (type == 2)
    {
        HideItemId = GetChildMenuIDIndexByParentMenuID(MENU_ID_PHB_IMAGE_OPTION, MENU_ID_PHB_IMAGE_OPTION_VIEW);
        HideItemId1 = GetChildMenuIDIndexByParentMenuID(MENU_ID_PHB_IMAGE_OPTION, MENU_ID_PHB_IMAGE_OPTION_DELETE);
        if ((HideItemId != -1) && (HideItemId != -1))
        {
            ResetBit(maskingByte, HideItemId);
            ResetBit(maskingByte, HideItemId1);
            MaskHiliteItems(MENU_ID_PHB_IMAGE_OPTION, maskingByte);
            nNumofItem = MaskItems(nStrItemList, (U8) nNumofItem, maskingByte);
        }
    }

    ShowCategory15Screen(
        STR_ASSOCIATE_PICTURE,
        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);

    /* g_phb_cntx.set_done_flag = 1; */
    viewOnce = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_image_option
 * DESCRIPTION
 *  screen exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_exit_image_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.end_scr_id = SCR_ID_PHB_IMAGE_OPTION;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_image_view
 * DESCRIPTION
 *  Highlight function of image option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_image_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_phb_image_view_from_phb_folder, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_phb_image_view_from_phb_folder, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_image_select
 * DESCRIPTION
 *  Highlight function of image option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_image_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_phb_image_select_from_file_mamager, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_phb_image_select_from_file_mamager, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_image_delete
 * DESCRIPTION
 *  Highlight function of image option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_image_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_phb_image_delete_from_phb_folder, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_image_view_from_phb_folder
 * DESCRIPTION
 *  view image from selected file path
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_image_view_from_phb_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 rid;
    FS_HANDLE fh = 0;
    S16 drive;
    S8 path[MMI_PHB_MAX_PATH_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_phb_cntx.image_location == MMI_PHB_IMAGE_FOR_ENTRY)          /* An Image in Phonebook folder */
        || (g_phb_cntx.image_location == MMI_PHB_IMAGE_SELECT_PATH)     /* An Image in select path */
        || (g_phb_cntx.image_location == MMI_PHB_IMAGE_CALLER_GROUP)    /* An Image in Caller Group Folder */
    #ifdef __MMI_AVATAR__
        || (g_phb_cntx.image_location == MMI_PHB_AVATAR_SELECT_PATH)    /* An Image in avatar */
    #endif
        )       
    {
        if (g_phb_cntx.image_location == MMI_PHB_IMAGE_FOR_ENTRY ||
            g_phb_cntx.image_location == MMI_PHB_IMAGE_CALLER_GROUP)
        {
            drive = MMI_PHB_DRV;
            if (drive > 0)
            {
                if (g_phb_cntx.image_location == MMI_PHB_IMAGE_FOR_ENTRY)
                {
                    rid = g_phb_name_index[g_phb_cntx.active_index] + 1;        /* For Edit Option Only */
                    MMI_ASSERT(rid <= MAX_PB_PHONE_ENTRIES);    /* Image should be associate to NVRAM record. */
                }
                else
                {
                    rid = 5000 + g_phb_cntx.active_index + 1;   /* Current Caller Group, image id strat from 5000 */
                }

                mmi_phb_image_get_full_path_by_index(rid, path);

                fh = FS_Open((U16*) path, FS_READ_ONLY);
            }
        }
        else
        {
            fh = FS_Open((U16*) g_phb_file_path, FS_READ_ONLY);
        }

        if (fh > 0) /* file exists */
        {
            FS_Close(fh);

            /* ExecuteCurrExitHandler(); */
            EntryNewScreen(SCR_ID_PHB_IMAGE_VIEW_IMAGE, NULL, mmi_phb_image_view_from_phb_folder, NULL);

            /* entry cat222 to decode and display a image from file */
            if (g_phb_cntx.image_location == MMI_PHB_IMAGE_SELECT_PATH
            #ifdef __MMI_AVATAR__
                || g_phb_cntx.image_location == MMI_PHB_AVATAR_SELECT_PATH
            #endif
                )
            {
                ShowCategory222Screen(
                    STR_ASSOCIATE_PICTURE,
                    IMG_SCR_PBOOK_CAPTION,
                    0,
                    0,
                    STR_GLOBAL_BACK,
                    IMG_GLOBAL_BACK,
                    GDI_COLOR_BLACK,
                    (PS8) NULL,
                    (PS8) g_phb_file_path,
                    FALSE,
                    NULL,
                    GDI_IMAGE_SRC_FROM_FILE);
            }
            else
            {
                ShowCategory222Screen(
                    STR_ASSOCIATE_PICTURE,
                    IMG_SCR_PBOOK_CAPTION,
                    0,
                    0,
                    STR_GLOBAL_BACK,
                    IMG_GLOBAL_BACK,
                    GDI_COLOR_BLACK,
                    (PS8) NULL,
                    (PS8) path,
                    FALSE,
                    NULL,
                    GDI_IMAGE_SRC_FROM_FILE);
            }
            SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
            /* SetGenericExitHandler(SCR_ID_PHB_IMAGE_VIEW_IMAGE, NULL, mmi_phb_image_view_from_phb_folder); */

            return;
        }
    }
    g_phb_cntx.image_location = MMI_PHB_IMAGE_NO_SELECT;    /* Can't open file or not select file yet. */
    DisplayPopup(
        (U8*) GetString(STR_ID_PHB_FMGR_IMAGE_NO_SELECT),
        IMG_GLOBAL_ERROR,
        FALSE,
        PHB_NOTIFY_TIMEOUT,
        ERROR_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_image_select_from_file_mamager
 * DESCRIPTION
 *  select image from file manager. enter file manager screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_image_select_from_file_mamager(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (mmi_usb_check_path_exported((S8*)L"root"))
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 
    FMGR_FILTER_INIT(&filter);
#if defined(__GDI_MEMORY_PROFILE_2__)   /* Able to select jpeg file if supported */
    FMGR_FILTER_SET(&filter, FMGR_TYPE_JPG);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_JPEG);
#endif 
    FMGR_FILTER_SET(&filter, FMGR_TYPE_GIF);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_BMP);
#if defined(GDI_USING_PNG)
    FMGR_FILTER_SET(&filter, FMGR_TYPE_PNG);
#endif 
#if defined(GDI_USING_M3D)
    FMGR_FILTER_SET(&filter, FMGR_TYPE_M3D);
#endif
/* .SVG file is now not supported due to stack overflow */
//#ifdef __MMI_SVG__
//    FMGR_FILTER_SET(&filter, FMGR_TYPE_SVG);
//#endif
#if defined(__DRM_V02__)
    FMGR_FILTER_SET(&filter, FMGR_TYPE_ODF);
#endif /* defined(__DRM_V02__) */
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);

    mmi_fmgr_select_path_and_enter(
        APP_PHONEBOOK,
        FMGR_SELECT_FILE | FMGR_SELECT_REPEAT,
        filter,
        (S8*) L"root",
        (PsExtFuncPtr) mmi_phb_image_select_path_from_file_mamager);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_image_preview
 * DESCRIPTION
 *  phb image preview function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_image_preview(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ExecuteCurrExitHandler(); */
    EntryNewScreen(SCR_ID_PHB_IMAGE_VIEW_IMAGE, NULL, mmi_phb_image_preview, NULL);

    /* entry cat222 to decode and display a image from file */

    ShowCategory222Screen(
        STR_ASSOCIATE_PICTURE,
        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        GDI_COLOR_BLACK,
        (PS8) NULL,
        (PS8) g_phb_file_path,
        FALSE,
        mmi_phb_image_preview_callback,
        GDI_IMAGE_SRC_FROM_FILE);
    SetLeftSoftkeyFunction(mmi_phb_image_select_from_file_mamager_done, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_image_select_path_from_file_mamager
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path            [IN]        Path return by file manager.
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_image_select_path_from_file_mamager(void *path, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (path == NULL)   /* User does not select file and go back directly. */
    {
        GoBackToHistory(SCR_ID_PHB_IMAGE_OPTION);
        return;
    }

    /* Check image content. */
    if (mmi_phb_image_check_valid_image((S8*) path))
    {
        mmi_ucs2cpy((S8*) g_phb_file_path, (S8*) path);
		mmi_phb_image_preview();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_image_select_from_file_mamager_done
 * DESCRIPTION
 *  call back of select image from file manager.
 * PARAMETERS
 *  path            [IN]        Path return by file manager.
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_image_select_from_file_mamager_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.image_location = MMI_PHB_IMAGE_SELECT_PATH;

    fmgr_reset_app_select();    /* Use select_repeat, so clear by application itself. */
    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, TRUE, PHB_NOTIFY_TIMEOUT, SUCCESS_TONE);
    DeleteUptoScrID(SCR_ID_PHB_IMAGE_OPTION);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_image_delete_from_phb_folder
 * DESCRIPTION
 *  delete reference of selected image.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_image_delete_from_phb_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.image_location == MMI_PHB_IMAGE_NO_SELECT)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_PHB_FMGR_IMAGE_NO_SELECT),
            IMG_GLOBAL_ERROR,
            FALSE,
            PHB_NOTIFY_TIMEOUT,
            ERROR_TONE);
    }
    else
    {
        g_phb_cntx.image_location = MMI_PHB_IMAGE_NO_SELECT;
        DisplayPopup((U8*) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, TRUE, PHB_NOTIFY_TIMEOUT, SUCCESS_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_image_update_by_index
 * DESCRIPTION
 *  Update image by record_index
 * PARAMETERS
 *  record_index        [IN]        Index of image
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mmi_phb_image_update_by_index(U16 record_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 drive;
    S8 path[MMI_PHB_MAX_PATH_LENGTH];
    S8 *file_ext;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G4_PHB, MMI_PHB_IMAGE_UPDATE_BY_INDEX, record_index);

    /* Delete Image if not select image */
    if (g_phb_cntx.image_location == MMI_PHB_IMAGE_NO_SELECT)
    {
        mmi_phb_image_delete_by_index(record_index);
    }
    else if (g_phb_cntx.image_location == MMI_PHB_IMAGE_SELECT_PATH
    #ifdef __MMI_AVATAR__
            || g_phb_cntx.image_location == MMI_PHB_AVATAR_SELECT_PATH
    #endif
            )
    {
        /* Delete all image with same file name before update. */
        mmi_phb_image_delete_by_index(record_index);

        /* Make a copy of the selected file to phonebook folder. */
        drive = MMI_PHB_DRV;
        if (drive > 0)
        {
            /* Create Path */
            sprintf(nPrintableStr, "%c:\\%s", (S8) drive, MMI_PHB_IMAGE_FOLDER);
            mmi_asc_to_ucs2(path, nPrintableStr);

            /* Check if folder exist first, if not create folder. */
            if (mmi_phb_fs_check_image_folder(path) == FS_NO_ERROR)
            {
                /* Create file name */
                sprintf(nPrintableStr, "%c:\\%s\\%d.", (S8) drive, MMI_PHB_IMAGE_FOLDER, record_index);
                mmi_asc_to_ucs2(path, nPrintableStr);

                /* Create file extension - from source file extension */
                file_ext = mmi_fmgr_extract_ext_file_name(g_phb_file_path);
                mmi_ucs2cat(path, file_ext);

                if (mmi_phb_image_copy(path, g_phb_file_path))
                {
                    g_phb_cntx.image_location = MMI_PHB_IMAGE_FOR_ENTRY;
                    return TRUE;
                }
            }
        }
        /* Copy Fail, clear to zero */
        g_phb_cntx.image_location = MMI_PHB_IMAGE_NO_SELECT;
        /* DisplayPopup((U8*)GetString(STR_ID_PHB_FMGR_IMAGE_COPY_FAIL), IMG_GLOBAL_ERROR, FALSE, PHB_NOTIFY_TIMEOUT, ERROR_TONE); */
        return FALSE;
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_image_delete_by_index
 * DESCRIPTION
 *  Delete phonebook associate picture by index.
 *  Note that all file name with different extensions should be deleted
 * PARAMETERS
 *  record_index        [IN]        Index of image
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_image_delete_by_index(U16 record_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fh_cur;
    FS_DOSDirEntry file_info;
    S8 path[MMI_PHB_MAX_PATH_LENGTH];
    S8 filename[MMI_PHB_MAX_PATH_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(nPrintableStr, "%c:\\%s\\%d.?*", MMI_PHB_DRV, MMI_PHB_IMAGE_FOLDER, record_index);
    mmi_asc_to_ucs2(path, nPrintableStr);

    if ((fh_cur = FS_FindFirst((U16*) path, 0, 0, &file_info, (U16*) filename, MMI_PHB_MAX_PATH_LENGTH)) >= 0)
    {
        /* Loop through all file with different extension. */
        do
        {
            /* filter out folder results */
            if (!(file_info.Attributes & FS_ATTR_DIR))
            {
                sprintf(nPrintableStr, "%c:\\%s\\", MMI_PHB_DRV, MMI_PHB_IMAGE_FOLDER);
                mmi_asc_to_ucs2(path, nPrintableStr);
                mmi_ucs2cat(path, filename);

                /* Delete the file */
                FS_Delete((U16*) path);
            }
        } while (FS_FindNext(fh_cur, &file_info, (U16*) filename, MMI_PHB_MAX_PATH_LENGTH) == FS_NO_ERROR);
        FS_FindClose(fh_cur);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_image_duplicate_by_index
 * DESCRIPTION
 *  Duplicate image by source record_index and destination record_index.
 * PARAMETERS
 *  dst_record      [IN]        Index of destination picture
 *  src_record      [IN]        Index of source picture
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mmi_phb_image_duplicate_by_index(U16 dst_record, U16 src_record)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 drive;
    S8 src_path[MMI_PHB_MAX_PATH_LENGTH];
    S8 dst_path[MMI_PHB_MAX_PATH_LENGTH];
    S8 *file_ext;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G4_PHB, MMI_PHB_IMAGE_DUPLICATE_BY_INDEX, dst_record, src_record);

    drive = MMI_PHB_DRV;
    if (drive > 0)
    {
        /* Get source file path */
        mmi_phb_image_get_full_path_by_index(src_record, src_path);

        /* Get destination file path */
        sprintf(nPrintableStr, "%c:\\%s", (S8) drive, MMI_PHB_IMAGE_FOLDER);
        mmi_asc_to_ucs2(dst_path, nPrintableStr);
        /* Check if folder exist first, if not create folder. */
        if (mmi_phb_fs_check_image_folder(dst_path) != FS_NO_ERROR)
        {
            return FALSE;
        }

        sprintf(nPrintableStr, "%c:\\%s\\%d.", (S8) drive, MMI_PHB_IMAGE_FOLDER, dst_record);
        mmi_asc_to_ucs2(dst_path, nPrintableStr);

        file_ext = mmi_fmgr_extract_ext_file_name(src_path);
        mmi_ucs2cat(dst_path, file_ext);

        if (mmi_phb_image_copy(dst_path, src_path))
        {
            return TRUE;
        }
    }

    /* DisplayPopup((U8*)GetString(STR_ID_PHB_FMGR_IMAGE_COPY_FAIL), IMG_GLOBAL_ERROR, FALSE, PHB_NOTIFY_TIMEOUT, ERROR_TONE); */
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_image_copy
 * DESCRIPTION
 *  Copy image to destination folder. Make sure the destination folder exists.
 * PARAMETERS
 *  dst     [?]     
 *  src     [?]     
 * RETURNS
 *  TRUE if copy successfully, else FALSE.
 *****************************************************************************/
BOOL mmi_phb_image_copy(S8 *dst, S8 *src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fh_src, fh_dst;
    U8 buf[256];
    U32 read_len, write_len;
    S32 read_result = 0, write_result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G4_PHB, MMI_PHB_IMAGE_COPY);

    /* Source and Destination can't be the same. */
    if (mmi_ucs2cmp(dst, src) == 0)
    {
        MMI_TRACE(MMI_TRACE_G4_PHB, MMI_PHB_IMAGE_COPY_1);
        return FALSE;
    }

    fh_src = FS_Open((U16*) src, FS_READ_ONLY);
    if (fh_src <= 0)
    {
        MMI_TRACE(MMI_TRACE_G4_PHB, MMI_PHB_IMAGE_COPY_2);
        return FALSE;
    }

    fh_dst = FS_Open((U16*) dst, FS_CREATE_ALWAYS | FS_READ_WRITE);
    if (fh_dst <= 0)
    {
        MMI_TRACE(MMI_TRACE_G4_PHB, MMI_PHB_IMAGE_COPY_3);
        FS_Close(fh_src);
        return FALSE;
    }

    FS_Seek(fh_dst, 0, FS_FILE_BEGIN);

    for (;;)
    {
        if ((read_result = FS_Read(fh_src, buf, 256, (U32*) & read_len)) == FS_NO_ERROR)
        {

            if (read_len < 256) /* End of File */
            {
                if ((write_result = FS_Write(fh_dst, buf, read_len, (U32*) & write_len)) == FS_NO_ERROR)
                {
                    FS_Close(fh_dst);
                    FS_Close(fh_src);
                    return TRUE;
                }
                else
                {
                    break;
                }

            }
            else if (read_len == 256)
            {
                if ((write_result = FS_Write(fh_dst, buf, read_len, (U32*) & write_len)) != FS_NO_ERROR)
                {
                    break;
                }
            }
            else
            {
                break;
            }

        }
        else
        {
            break;
        }
    }

    /* Copy Fail */
    MMI_TRACE(MMI_TRACE_G4_PHB, MMI_PHB_IMAGE_COPY_4, read_result, write_result);
    FS_Close(fh_dst);
    FS_Close(fh_src);
    FS_Delete((U16*) dst);
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_image_check_image_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static BOOL mmi_phb_image_check_image_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_filepath[MMI_PHB_MAX_PATH_LENGTH];
    S16 drive;
    U16 rid;
    FS_HANDLE fh = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Get image file path */
    drive = MMI_PHB_DRV;
    if (drive > 0)
    {
        sprintf(nPrintableStr, "%c:\\%s", (S8) drive, MMI_PHB_IMAGE_FOLDER);
        mmi_asc_to_ucs2(buf_filepath, nPrintableStr);
    #ifdef __USB_IN_NORMAL_MODE__
        if (mmi_usb_is_in_mass_storage_mode())
        {
            /* in mass storage mode */
            if (mmi_usb_check_path_exported((S8*) buf_filepath))
            {
                return FALSE;
            }
        }
    #endif /* __USB_IN_NORMAL_MODE__ */
        rid = g_phb_name_index[g_phb_cntx.active_index] + 1;        /* For Edit Option Only */
        MMI_ASSERT(rid <= MAX_PB_PHONE_ENTRIES);    /* Image should be associate to NVRAM record. */

        mmi_phb_image_get_full_path_by_index(rid, buf_filepath);

        fh = FS_Open((U16*) buf_filepath, FS_READ_ONLY);
    }

    if (fh > 0) /* file exists */
    {
        FS_Close(fh);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


#ifdef __MMI_AVATAR__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_avatar_image_pre_entry_option
 * DESCRIPTION
 *  Phonebook associate image operation: View, select, delete.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_avatar_image_pre_entry_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_phb_cntx.image_location == MMI_PHB_IMAGE_NO_SELECT)
        || (g_phb_cntx.image_location == MMI_PHB_IMAGE_SELECT_PATH)
        || ((g_phb_cntx.image_location == MMI_PHB_IMAGE_FOR_ENTRY) && (g_phb_image_type_id != 2)) /*from file case */
        || ((g_phb_cntx.image_location == MMI_PHB_IMAGE_CALLER_GROUP) && (g_phb_image_type_id  != 2))) /*from file case */
    {
        g_phb_image_type_id = 2;
        mmi_phb_entry_avatar_image_option(2); 
    }
    else
    {
        mmi_phb_entry_avatar_image_option(1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_avatar_image_option
 * DESCRIPTION
 *  Phonebook associate image operation: View, select, delete.
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_avatar_image_option(U8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[5];
    U16 nNumofItem;
    U32 HideItemId = -1, HideItemId1 = -1;
    U32 maskingByte = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_PHB_AVATAR_IMAGE_OPTION, mmi_phb_exit_avatar_image_option, mmi_phb_avatar_image_pre_entry_option, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_PHB_AVATAR_IMAGE_OPTION);
    nNumofItem = GetNumOfChild(MENU_ID_PHB_AVATAR_IMAGE_OPTION);
    GetSequenceStringIds(MENU_ID_PHB_AVATAR_IMAGE_OPTION, nStrItemList);
    SetParentHandler(MENU_ID_PHB_AVATAR_IMAGE_OPTION);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* Hide menu item play and delete when file not selected. */
    /* Regiser highlight handler again. */
    mmi_phb_operate_single_init();

    /* File not selected */
    if (type == 2)
    {
        HideItemId = GetChildMenuIDIndexByParentMenuID(MENU_ID_PHB_AVATAR_IMAGE_OPTION, MENU_ID_PHB_AVATAR_IMAGE_OPTION_VIEW);
        HideItemId1 = GetChildMenuIDIndexByParentMenuID(MENU_ID_PHB_AVATAR_IMAGE_OPTION, MENU_ID_PHB_AVATAR_IMAGE_OPTION_DELETE);
        if ((HideItemId != -1) && (HideItemId != -1))
        {
            ResetBit(maskingByte, HideItemId);
            ResetBit(maskingByte, HideItemId1);
            MaskHiliteItems(MENU_ID_PHB_AVATAR_IMAGE_OPTION, maskingByte);
            nNumofItem = MaskItems(nStrItemList, (U8) nNumofItem, maskingByte);
        }
    }

    ShowCategory15Screen(
        STR_ASSOCIATE_PICTURE,
        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);

    g_phb_avatar_image_view = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_avatar_image_option
 * DESCRIPTION
 *  screen exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_exit_avatar_image_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.end_scr_id = SCR_ID_PHB_AVATAR_IMAGE_OPTION;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_avatar_image_view
 * DESCRIPTION
 *  Highlight function of image option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_avatar_image_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_phb_image_view_from_phb_folder, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_phb_image_view_from_phb_folder, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_avatar_image_select
 * DESCRIPTION
 *  Highlight function of image option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_avatar_image_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_phb_avatar_image_select_from_file_manager, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_phb_avatar_image_select_from_file_manager, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_avatar_image_delete
 * DESCRIPTION
 *  Highlight function of image option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_avatar_image_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_phb_image_delete_from_phb_folder, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_avatar_image_select_from_file_manager
 * DESCRIPTION
 *  select image from file manager. enter file manager screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_avatar_image_select_from_file_manager(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (mmi_usb_check_path_exported((S8*)L"root"))
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    mmi_avatar_select_path_and_enter(
        MMI_AVATAR_APP_CALLER_PICTURE,
        mmi_phb_avatar_image_select_from_file_manager_done);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_avatar_image_select_from_file_manager_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path            [IN]        Path return by file manager.
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_avatar_image_select_from_file_manager_done(U32 path_address, U32 serial_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 length = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((PS8)path_address == NULL)   /* User does not select file and go back directly. */
    {
        GoBackToHistory(SCR_ID_PHB_AVATAR_IMAGE_OPTION);
        return;
    }

    /* Check image content. */
    if (mmi_phb_image_check_valid_image((S8*) path_address)) /* avatar is a kind of *.jpg file */
    {
        length = mmi_ucs2strlen((S8*)path_address);
        mmi_ucs2ncpy((S8*) g_phb_file_path, (S8*) path_address, length);
        g_phb_cntx.image_location = MMI_PHB_AVATAR_SELECT_PATH;

        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, TRUE, PHB_NOTIFY_TIMEOUT, SUCCESS_TONE);
        DeleteUptoScrID(SCR_ID_PHB_AVATAR_IMAGE_OPTION);
    }
}
#endif /* def __MMI_AVATAR__ */
#endif /* defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__) */ 


#if defined(__MMI_FILE_MANAGER__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_fs_check_disc_space
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dir_name        [?]         
 *  free_byte       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
BOOL mmi_phb_fs_check_disc_space(S16 *dir_name, kal_uint32 free_byte)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;
    FS_DiskInfo disc_info;
    kal_wchar dir[3];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(dir, 0, 6);
    memcpy(dir, dir_name, 4);
    /* check the available free space */
    result = FS_GetDiskInfo((kal_wchar*) dir, &disc_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);

#ifdef __MTK_TARGET__
    if (result > 0 && result & (FS_DI_BASIC_INFO | FS_DI_FREE_SPACE))
#else 
    if (result >= 0)
#endif 
    {
        if ((disc_info.FreeClusters * disc_info.SectorsPerCluster * disc_info.BytesPerSector) < free_byte)
        {
            return FALSE;
        }
        else
        {
            return TRUE;
        }
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_image_check_valid_image
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path        [?]     
 * RETURNS
 *  
 *****************************************************************************/
BOOL mmi_phb_image_check_valid_image(S8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fh;
    kal_uint32 f_size = 0;  /* U32 f_size = 0 */
    S8 dir_name[10];
    U16 image_type;
    S8 *error_str_ptr;
    S8 dir_path[MMI_PHB_MAX_PATH_LENGTH];
    S32 result;
#ifdef __DRM_SUPPORT__
    BOOL drm_ret = TRUE;
#endif /* def __DRM_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check image file extension in advance. */
#ifdef __DRM_SUPPORT__
    fh = DRM_open_file((kal_wchar *)path, FS_READ_ONLY, DRM_PERMISSION_DISPLAY);

    if (fh >= FS_NO_ERROR)
    {
        drm_ret = DRM_validate_forward_rule(fh, DRM_PERMISSION_DISPLAY);
        DRM_close_file(fh);
    }

    if (drm_ret == FALSE)
        return FALSE;
#endif /* def __DRM_SUPPORT__ */

    image_type = gdi_image_get_type_from_file((S8*) path);
    if ((image_type != GDI_IMAGE_TYPE_JPG_FILE) && (image_type != GDI_IMAGE_TYPE_GIF_FILE) &&
#if defined(GDI_USING_PNG)
        (image_type != GDI_IMAGE_TYPE_PNG_FILE) &&
#endif 
#if defined(GDI_USING_M3D)
        (image_type != GDI_IMAGE_TYPE_M3D_FILE) &&
#endif 
/* .SVG file is now not supported due to stack overflow */
//#if defined(__MMI_SVG__)
//        (image_type != GDI_IMAGE_TYPE_SVG_FILE) &&
//#endif
        (image_type != GDI_IMAGE_TYPE_BMP_FILE))
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_PHB_FMGR_IMAGE_NOT_SUPPORT),
            IMG_GLOBAL_ERROR,
            FALSE,
            PHB_NOTIFY_TIMEOUT,
            ERROR_TONE);
        return FALSE;
    }

    /* Check if image folder exists */
    sprintf(nPrintableStr, "%c:\\%s", (S8) MMI_PHB_DRV, MMI_PHB_IMAGE_FOLDER);
    mmi_asc_to_ucs2(dir_path, nPrintableStr);

    if ((result = mmi_phb_fs_check_image_folder(dir_path)) != FS_NO_ERROR)
    {
        DisplayPopup(
            (PU8) GetString(GetFileSystemErrorString(result)),
            IMG_GLOBAL_ERROR,
            1,
            PHB_NOTIFY_TIMEOUT,
            (U8) ERROR_TONE);
        return FALSE;
    }

    /*
     * Check image content, check if the image header can be parsed correctly
     * Check image "size", "width", "height", value can be customize in file manage app.
     */
    if (!mmi_fmgr_util_file_limit_check(FMGR_LIMIT_CALLER_PICTURE, path, &error_str_ptr))
    {
        DisplayPopup((U8*) error_str_ptr, IMG_GLOBAL_ERROR, FALSE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
        return FALSE;
    }

    /* Check disk free space for copy */
    fh = FS_Open((U16*) path, FS_READ_ONLY);

    if (fh && (FS_GetFileSize(fh, &f_size) == FS_NO_ERROR))
    {
        FS_Close(fh);

        sprintf(dir_name, "%c:\\", MMI_PHB_DRV);
        mmi_asc_to_ucs2(dir_path, dir_name);
        if (!mmi_phb_fs_check_disc_space((S16*) dir_path, f_size))
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_PHB_FMGR_DISC_FULL),
                IMG_GLOBAL_ERROR,
                FALSE,
                PHB_NOTIFY_TIMEOUT,
                (U8) ERROR_TONE);
            return FALSE;
        }
    }
    else
    {
        if (fh)
        {
            FS_Close(fh);
        }

        DisplayPopup((U8*) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, FALSE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
        return FALSE;
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_image_preview_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path            [IN]        Path return by file manager.
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_image_preview_callback(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result < 0)
    {
        ChangeLeftSoftkey(0, 0);
        ChangeRightSoftkey(0, 0);
        DisplayPopup(
            (U8*) GetString(STR_ID_PHB_FMGR_IMAGE_NOT_SUPPORT),
            IMG_GLOBAL_ERROR,
            FALSE,
            PHB_NOTIFY_TIMEOUT,
            ERROR_TONE);
        /* delete to file select screen again */
        DeleteNHistory(1);
        SetLeftSoftkeyFunction(UI_dummy_function, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_image_get_full_path_by_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  record_index        [IN]        
 *  path                [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_image_get_full_path_by_index(U16 record_index, S8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fh_cur;
    FS_DOSDirEntry file_info;
    S8 filename[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(nPrintableStr, "%c:\\%s\\%d.?*", MMI_PHB_DRV, MMI_PHB_IMAGE_FOLDER, record_index);
    mmi_asc_to_ucs2(path, nPrintableStr);

    if ((fh_cur = FS_FindFirst((U16*) path, 0, 0, &file_info, (U16*) filename, 20)) >= 0)
    {
        /* filter out folder results */
        if (!(file_info.Attributes & FS_ATTR_DIR))
        {
            sprintf(nPrintableStr, "%c:\\%s\\", MMI_PHB_DRV, MMI_PHB_IMAGE_FOLDER);
            mmi_asc_to_ucs2(path, nPrintableStr);
            mmi_ucs2cat(path, filename);
        }
        else
        {
            memset(path, 0, ENCODING_LENGTH);
        }

        FS_FindClose(fh_cur);
        return;
    }

    memset(path, 0, ENCODING_LENGTH);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_image_init_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_image_init_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
    S16 drive;
    S8 path[MMI_PHB_MAX_PATH_LENGTH];
    FS_HANDLE fh;
    S32 result = FS_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Make a copy of the selected file to phonebook folder. */
    drive = MMI_PHB_DRV;
    if (drive > 0)
    {
        /* Create Path */
        sprintf(nPrintableStr, "%c:\\%s", (S8) drive, MMI_PHB_IMAGE_FOLDER);
        mmi_asc_to_ucs2(path, nPrintableStr);
    
        fh = FS_Open((U16*) path, FS_OPEN_DIR | FS_READ_ONLY);

        /* Folder Exists */
        if (fh > 0)
        {
            FS_SetAttributes((U16*) path, FS_ATTR_DIR | FS_ATTR_HIDDEN);
            FS_Close(fh);
        }
        /* Folder Does Not Exist */
        else
        {
            result = FS_CreateDir((U16*) path);
            /* Create Success */
            if (result == FS_NO_ERROR)
            {
                FS_SetAttributes((U16*) path, FS_ATTR_DIR | FS_ATTR_HIDDEN);
            }
        }
    }
}
#endif /* defined(__MMI_FILE_MANAGER__) */ 
/*----------------------------------------------END of Image from File Manager------------------------------------------------*/


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_fs_check_image_folder
 * DESCRIPTION
 *  Check if folder exists, if not create it.
 * PARAMETERS
 *  path        [IN]        Full UCS2 path of desire folder.
 * RETURNS
 *  TRUE if exists or create successfully, else FALSE.
 *****************************************************************************/
S32 mmi_phb_fs_check_image_folder(S8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fh;
    S32 result = FS_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fh = FS_Open((U16*) path, FS_OPEN_DIR | FS_READ_ONLY);

    /* Folder Exists */
    if (fh > 0)
    {
        FS_SetAttributes((U16*) path, FS_ATTR_DIR | FS_ATTR_HIDDEN);
        FS_Close(fh);
    }
    /* Folder Does Not Exist */
    else
    {
        result = FS_CreateDir((U16*) path);
        /* Create Success */
        if (result == FS_NO_ERROR)
        {
            FS_SetAttributes((U16*) path, FS_ATTR_DIR | FS_ATTR_HIDDEN);
        }
    }
    return result;
}

#if 1
//Huyanwei Move it From __MMI_INCOMING_CALL_VIDEO__


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_video_delete_by_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  store_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_video_delete_by_index(U16 store_index)
{
	#if 0
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;
    U8 vid_record;
    U16 vid_index;
    U16 video_ids[NVRAM_EF_PHB_VIDEO_COUNT];
    U16 video_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Delete Video ID from NVRAM */
    vid_record = (store_index / NVRAM_EF_PHB_VIDEO_COUNT) + 1;
    vid_index = (U16)(store_index - (vid_record - 1) * NVRAM_EF_PHB_VIDEO_COUNT);

    ReadRecord(NVRAM_EF_PHB_VIDEO_LID, vid_record, (void*)video_ids, NVRAM_EF_PHB_VIDEO_SIZE, &pError);
    video_id = video_ids[vid_index];

    if (video_id != 0)
    {
        video_ids[vid_index] = 0;

        WriteRecord(NVRAM_EF_PHB_VIDEO_LID, vid_record, (void*)video_ids, NVRAM_EF_PHB_VIDEO_SIZE, &pError);

        /* Delete data record if video from file path */
        if (video_id & 0x8000)
        {
            video_id &= 0xFFF;
            mmi_data_delete_record(&g_phb_video_record_store, video_id);
        }
    }
    #endif
}



#endif

#define MMI_PHB_INCOMING_CALL_VIDEO
#if defined(__MMI_INCOMING_CALL_VIDEO__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_video_init_data_store
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_video_init_data_store(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 ascii_disc[10];
    S8 path[MMI_PHB_MAX_PATH_LENGTH];
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_phb_cntx.init_video)
    {
        sprintf(ascii_disc, "%c:\\", (S8) MMI_PHB_DRV);
        mmi_asc_to_ucs2(path, ascii_disc);
        mmi_ucs2cat(path, (S8*) MMI_PHB_VIDEO_DATA_FILE);

        /* May need to check if init successfully here. */
        result = mmi_data_init_record_store(
                    &g_phb_video_record_store,
                    (S8*) path,
                    FMGR_MAX_PATH_LEN * ENCODING_LENGTH + ENCODING_LENGTH);

        if (result == 0)
        {
            g_phb_cntx.init_video = 1;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_video_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_video_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == (g_phb_cntx.total_video_id - 1))
    {
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
        SetLeftSoftkeyFunction(mmi_phb_video_pre_entry_file_option, KEY_EVENT_UP);
    }
#ifdef __MMI_AVATAR__
	 else if (index == (g_phb_cntx.total_video_id - g_phb_avatar_video_minus))
	 {
		ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
		SetLeftSoftkeyFunction(mmi_phb_avatar_video_pre_entry_file_option, KEY_EVENT_UP);
	 }
#endif /* __MMI_AVATAR__ */
#ifdef __MMI_SWFLASH__
	 else if (index == (g_phb_cntx.total_video_id - g_phb_swflash_video_minus))
	 {
		ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
		SetLeftSoftkeyFunction(mmi_phb_swflash_pre_entry_file_option, KEY_EVENT_UP);
	 }
	 else if (index != 0 && index <= MMI_PHB_SWFLASH_TOTAL)
	 {
		ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
		SetLeftSoftkeyFunction(mmi_phb_entry_swflash_default_option, KEY_EVENT_UP);
	 }
#endif /* __MMI_SWFLASH__ */
    else if (index != 0)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
        SetLeftSoftkeyFunction(mmi_phb_entry_video_default_option, KEY_EVENT_UP);
    }
    else
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_LSK, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_video_default_view
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_video_default_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);

    SetLeftSoftkeyFunction(mmi_phb_video_view_from_default, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_video_view_from_default, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_video_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_video_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.video_audio)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OFF, IMG_GLOBAL_OK);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_ON, IMG_GLOBAL_OK);
    }

    SetLeftSoftkeyFunction(mmi_phb_video_toggle_setting, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_hint_video_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_hint_video_setting(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.video_audio)
    {
        mmi_ucs2cpy((S8*) hintData[index], GetString(STR_GLOBAL_ON));
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[index], GetString(STR_GLOBAL_OFF));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_video_file_view
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_video_file_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);

    SetLeftSoftkeyFunction(mmi_phb_video_view_from_file, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_video_view_from_file, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_video_file_select
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_video_file_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);

    SetLeftSoftkeyFunction(mmi_phb_video_select_from_file_mamager, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_video_select_from_file_mamager, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_video_file_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_video_file_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);

    SetLeftSoftkeyFunction(mmi_phb_video_delete_file_reference, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_video_default_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_video_default_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[5];
    U16 nNumofItem;
    U8 *hintList[5];    /* Array for hint */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_PHB_VIDEO_OPTION, NULL, mmi_phb_entry_video_default_option, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_PHB_VIDEO_OPTION);  /* Getting the Index from history */

    nNumofItem = GetNumOfChild(MENU_ID_PHB_VIDEO_DEFAULT_OPTION);
    GetSequenceStringIds(MENU_ID_PHB_VIDEO_DEFAULT_OPTION, nStrItemList);
    SetParentHandler(MENU_ID_PHB_VIDEO_DEFAULT_OPTION);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* Construct List To Show Hint */
    ConstructHintsList(MENU_ID_PHB_VIDEO_DEFAULT_OPTION, hintList);

    /* Screen with hint */
    ShowCategory52Screen(
        STR_ID_PHB_ASSOCIATE_VIDEO,
        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        hintList,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    g_phb_video_view = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_video_pre_entry_file_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_video_pre_entry_file_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.video_location == MMI_PHB_IMAGE_NO_SELECT
#ifdef __MMI_AVATAR__
        || g_phb_cntx.video_location == MMI_PHB_AVATAR_SELECT_PATH
#endif
#ifdef __MMI_SWFLASH__
        || g_phb_cntx.video_location == MMI_PHB_SWFLASH_SELECT_PATH
#endif
    )
    {
        mmi_phb_entry_video_file_option(2);
    }
    else
    {
        mmi_phb_entry_video_file_option(1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_video_file_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_video_file_option(U8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[5];
    U16 nNumofItem;
    U8 *hintList[5];    /* Array for hint */
    U32 HideItemId = -1, HideItemId1 = -1, HideItemId2 = -1;
    U32 maskingByte = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_PHB_VIDEO_OPTION, NULL, mmi_phb_video_pre_entry_file_option, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_PHB_VIDEO_OPTION);  /* Getting the Index from history */

    nNumofItem = GetNumOfChild(MENU_ID_PHB_VIDEO_FILE_OPTION);
    GetSequenceStringIds(MENU_ID_PHB_VIDEO_FILE_OPTION, nStrItemList);
    SetParentHandler(MENU_ID_PHB_VIDEO_FILE_OPTION);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* Construct List To Show Hint */
    ConstructHintsList(MENU_ID_PHB_VIDEO_FILE_OPTION, hintList);

    /* Hide menu item play and delete when file not selected. */
    /* Regiser highlight handler again. */
    mmi_phb_operate_single_init();

    /* File not selected */
    if (type == 2)
    {
        HideItemId = GetChildMenuIDIndexByParentMenuID(MENU_ID_PHB_VIDEO_FILE_OPTION, MENU_ID_PHB_VIDEO_FILE_VIEW);
        HideItemId1 = GetChildMenuIDIndexByParentMenuID(MENU_ID_PHB_VIDEO_FILE_OPTION, MENU_ID_PHB_VIDEO_FILE_DELETE);
        HideItemId2 = GetChildMenuIDIndexByParentMenuID(MENU_ID_PHB_VIDEO_FILE_OPTION, MENU_ID_PHB_VIDEO_FILE_SETTING);
        if ((HideItemId != -1) && (HideItemId1 != -1) && (HideItemId2 != -1))
        {
            ResetBit(maskingByte, HideItemId);
            ResetBit(maskingByte, HideItemId1);
            ResetBit(maskingByte, HideItemId2);
            MaskHiliteItems(MENU_ID_PHB_VIDEO_FILE_OPTION, maskingByte);
            MaskStringItems(hintList, (U8) nNumofItem, maskingByte);
            nNumofItem = MaskItems(nStrItemList, (U8) nNumofItem, maskingByte);
        }
    }

    /* Screen with hint */
    ShowCategory52Screen(
        STR_ID_PHB_ASSOCIATE_VIDEO,
        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        hintList,
        0,
        0,
        guiBuffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    g_phb_video_view = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_video_view_from_default
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_video_view_from_default(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 video_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    video_id = g_phb_cntx.video_id_list[g_phb_cntx.selected_video_index];

    if (isInCall()) /* Can not preview video during call. */
    {
    #ifdef __MMI_SWFLASH__
        if (video_id > (MFH_ID_PHB_MTCALL_1-1) && video_id < (MFH_ID_PHB_MTCALL_1 + MMI_PHB_SWFLASH_TOTAL))
        {
            DisplayPopup((U8*)GetString(STR_ID_PHB_CANT_VIEW_SWFLASH_IN_CALL), IMG_GLOBAL_WARNING, FALSE, PHB_NOTIFY_TIMEOUT, WARNING_TONE);
        }
        else
    #endif /* __MMI_SWFLASH__ */
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_PHB_CANT_VIEW_VIDEO_IN_CALL),
                IMG_GLOBAL_WARNING,
                FALSE,
                PHB_NOTIFY_TIMEOUT,
                WARNING_TONE);
        }
    }
    else if ((video_id != 0) && !(video_id & 0x8000))
    {
        PU8 gui_buffer;
        EntryNewScreen(SCR_ID_PHB_VIDEO_VIEW, NULL, mmi_phb_video_view_from_default, NULL);
        gui_buffer = GetCurrGuiBuffer(SCR_ID_PHB_VIDEO_VIEW);
    #ifdef __MMI_SWFLASH__
        if (video_id > (MFH_ID_PHB_MTCALL_1-1) && video_id < (MFH_ID_PHB_MTCALL_1 + MMI_PHB_SWFLASH_TOTAL))
        {
            ShowCategory229Screen(
                (U8*)GetString(STR_GLOBAL_VIEW),    /* title_str */
                IMG_SCR_PBOOK_CAPTION,              /* title_icon */
                0,                                  /* lsk_str */
                0,                                  /* lsk_icon */
                STR_GLOBAL_BACK,                    /* rsk_str */
                IMG_GLOBAL_BACK,                    /* rsk_icon */
                video_id,                           /* video_id */
                NULL,                               /* video_filename */
                1,                                  /* repeat_count */
                (BOOL) ! IsSilentModeActivated(),   /* is_play_audio */
                TRUE,                               /* is_vibrate_on */
                TRUE,                               /* is_interaction_on */
                TRUE,                               /* is_lcd_no_sleep */
                0,                                  /* is_full_screen */
                GDI_COLOR_WHITE,                    /* bg_color */
                mmi_phb_video_view_callback,
                gui_buffer);
        }
        else
    #endif /* __MMI_SWFLASH__ */
        {
            ShowCategory225Screen(
                STR_GLOBAL_VIEW,                    /* title_str */
                IMG_SCR_PBOOK_CAPTION,              /* title_icon */
                0,                                  /* lsk_str */
                0,                                  /* lsk_icon */
                STR_GLOBAL_BACK,                    /* rsk_str */
                IMG_GLOBAL_BACK,                    /* rsk_icon */
                video_id,                           /* video_id */
                NULL,                               /* video_filename */
                1,                                  /* repeat_count */
                TRUE,                               /* is_visual_update */
                (BOOL) ! IsSilentModeActivated(),   /* is_play_audio */
                TRUE,                               /* is_lcd_no_sleep */
                GDI_COLOR_WHITE,                    /* bg_color */
                mmi_phb_video_view_callback,
                gui_buffer);
        }
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
    else
    {
        DisplayPopup((U8*) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, FALSE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_video_view_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        Play result
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_video_view_callback(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result < 0)
    {
        ChangeLeftSoftkey(0, 0);
        ChangeRightSoftkey(0, 0);

        if (result == MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED)
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_VDOPLY_NOTIFY_INVALID_VIDEO_FILE),
                IMG_GLOBAL_WARNING,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                WARNING_TONE);
        }
        else
        {
            DisplayPopup(
                (PU8) GetString(STR_FMGR_INVALID_FORMAT),
                IMG_GLOBAL_WARNING,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                WARNING_TONE);
        }

        /* delete to file select screen again */
        DeleteNHistory(1);
        SetLeftSoftkeyFunction(UI_dummy_function, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_video_view_from_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_video_view_from_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer;
#ifdef __MMI_AVATAR__
    U32 avatar_id;  
    U32 avatar_serial_num;
    S8 temp_buff[FMGR_MAX_PATH_LEN + 1];    
    S8* avatar_serial_num_str;
    U16 i;
    MMI_BOOL is_avatar_serial_num_found = MMI_FALSE;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (isInCall()) /* Can not preview video during call. */
    {
    #ifdef __MMI_AVATAR__
        if (g_phb_cntx.selected_video_index == g_phb_cntx.total_video_id - g_phb_avatar_video_minus)
        {
            DisplayPopup((U8*)GetString(STR_ID_PHB_CANT_VIEW_AVATAR_IN_CALL), IMG_GLOBAL_WARNING, FALSE, PHB_NOTIFY_TIMEOUT, WARNING_TONE);
        }
        else
    #endif /* __MMI_SWFLASH__ */
    #ifdef __MMI_SWFLASH__
        if (g_phb_cntx.selected_video_index == g_phb_cntx.total_video_id - g_phb_swflash_video_minus)
        {
            DisplayPopup((U8*)GetString(STR_ID_PHB_CANT_VIEW_SWFLASH_IN_CALL), IMG_GLOBAL_WARNING, FALSE, PHB_NOTIFY_TIMEOUT, WARNING_TONE);
        }
        else
    #endif /* __MMI_SWFLASH__ */
        {
        DisplayPopup(
            (U8*) GetString(STR_ID_PHB_CANT_VIEW_VIDEO_IN_CALL),
            IMG_GLOBAL_WARNING,
            FALSE,
            PHB_NOTIFY_TIMEOUT,
            WARNING_TONE);
        }
    }
    else if ((g_phb_cntx.selected_video_index == g_phb_cntx.total_video_id - 1
            && g_phb_cntx.video_location == MMI_PHB_IMAGE_SELECT_PATH)
    #ifdef __MMI_AVATAR__
            || (g_phb_cntx.selected_video_index == g_phb_cntx.total_video_id - g_phb_avatar_video_minus
            && g_phb_cntx.video_location == MMI_PHB_AVATAR_SELECT_PATH)
    #endif /* __MMI_AVATAR__ */
#ifdef __MMI_SWFLASH__
            || (g_phb_cntx.selected_video_index == g_phb_cntx.total_video_id - g_phb_swflash_video_minus
            && g_phb_cntx.video_location == MMI_PHB_SWFLASH_SELECT_PATH)
#endif /* __MMI_SWFLASH__ */
           ) 
    {
    #ifdef __MMI_AVATAR__
        if (g_phb_cntx.selected_video_index == g_phb_cntx.total_video_id - g_phb_avatar_video_minus)
        {
            mmi_ucs2_to_asc(temp_buff, g_phb_video_file_path);
            for (i = 0; temp_buff[i] != '\0'; i++)
            {
                if (temp_buff[i] == '-')
                {
                    is_avatar_serial_num_found = MMI_TRUE;
                    break;
                }
            }
            if (is_avatar_serial_num_found == MMI_TRUE)
            {
                avatar_serial_num_str = temp_buff + i + 1;
                avatar_serial_num = (U32)atoi(avatar_serial_num_str);
                temp_buff[i] =  '\0';
            }
            else
            {
                avatar_serial_num = 0;
            }
            avatar_id = (U32)atoi(temp_buff);
            if (mmi_avatar_is_avatar_valid(avatar_id, avatar_serial_num))
            {
                EntryNewScreen(SCR_ID_PHB_VIDEO_VIEW, NULL, mmi_phb_video_view_from_file, NULL);
                gui_buffer = GetCurrGuiBuffer(SCR_ID_PHB_VIDEO_VIEW);
                ShowCategory222Screen(
                    STR_GLOBAL_VIEW,
                    IMG_SCR_PBOOK_CAPTION,
                    0,
                    0,
                    STR_GLOBAL_BACK,
                    IMG_GLOBAL_BACK,
                    GDI_COLOR_BLACK,
                    (PS8) NULL,
                    (PS8) avatar_id,
                    FALSE,
                    NULL,
                    GDI_IMAGE_SRC_FROM_MEMORY);
                SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
            }
            else
            {
                DisplayPopup(
                    (U8*) GetString(STR_ID_PHB_AVATAR_NOT_EXISTED),
                    IMG_GLOBAL_ERROR,
                    FALSE,
                    PHB_NOTIFY_TIMEOUT,
                    ERROR_TONE);
            }
        }
        else
    #endif /* __MMI_AVATAR__ */
        {
            FS_HANDLE file_handle = FS_Open((kal_uint16*) g_phb_video_file_path, FS_READ_ONLY);
            if (file_handle >= 0)
            {
                FS_Close(file_handle);

                EntryNewScreen(SCR_ID_PHB_VIDEO_VIEW, NULL, mmi_phb_video_view_from_file, NULL);
                gui_buffer = GetCurrGuiBuffer(SCR_ID_PHB_VIDEO_VIEW);

            #ifdef __MMI_SWFLASH__
                if (g_phb_cntx.selected_video_index == g_phb_cntx.total_video_id - g_phb_swflash_video_minus)
                {
                    ShowCategory229Screen((U8*)GetString(STR_GLOBAL_VIEW),		/* title_str */
                                           IMG_SCR_PBOOK_CAPTION,	                /* title_icon */
                                           0,				/* lsk_str */
                                           0,				/* lsk_icon */
                                           STR_GLOBAL_BACK,			/* rsk_str */
                                           IMG_GLOBAL_BACK,			/* rsk_icon */
                                           0,								/* video_id */
                                           (S8*)g_phb_video_file_path,	/* video_filename */
                                           1,								/* repeat_count */
                                           (BOOL)!IsSilentModeActivated(),	/* is_play_audio */
                                           TRUE,                           /* is_vibrate_on */
                                           TRUE,                           /* is_interaction_on */
                                           TRUE,							/* is_lcd_no_sleep */
                                           0,							    /* is_full_screen */
                                           GDI_COLOR_WHITE,			/* bg_color */
                                           mmi_phb_video_view_callback,
                                           gui_buffer);
                }
                else
            #endif /* __MMI_SWFLASH__ */
                {
                    ShowCategory225Screen(
                        STR_GLOBAL_VIEW,                    /* title_str */
                        IMG_SCR_PBOOK_CAPTION,              /* title_icon */
                        0,                                  /* lsk_str */
                        0,                                  /* lsk_icon */
                        STR_GLOBAL_BACK,                    /* rsk_str */
                        IMG_GLOBAL_BACK,                    /* rsk_icon */
                        0,                                  /* video_id */
                        (S8*) g_phb_video_file_path,        /* video_filename */
                        1,                                  /* repeat_count */
                        TRUE,                               /* is_visual_update */
                        (BOOL) ! IsSilentModeActivated(),   /* is_play_audio */
                        TRUE,                               /* is_lcd_no_sleep */
                        GDI_COLOR_WHITE,                    /* bg_color */
                        mmi_phb_video_view_callback,
                        gui_buffer);
                }
                SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
            }
            else
            {
                DisplayPopup(
                    (U8*) GetString(GetFileSystemErrorString(file_handle)),
                    IMG_GLOBAL_ERROR,
                    FALSE,
                    PHB_NOTIFY_TIMEOUT,
                    ERROR_TONE);
            }
        }
    }
    else
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_PHB_FMGR_IMAGE_NO_SELECT),
            IMG_GLOBAL_ERROR,
            FALSE,
            PHB_NOTIFY_TIMEOUT,
            ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_video_play_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        Play result
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_video_play_callback(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result >= 0)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(mmi_phb_video_select_from_file_mamager_done, KEY_EVENT_UP);
    }
    else
    {
        ChangeLeftSoftkey(0, 0);
        ChangeRightSoftkey(0, 0);
        if (result == MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED)
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_VDOPLY_NOTIFY_INVALID_VIDEO_FILE),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
            mmi_phb_video_free_buf();
        }
        else
        {
            DisplayPopup(
                (PU8) GetString(STR_FMGR_INVALID_FORMAT),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
            mmi_phb_video_free_buf();
        }

        /* delete to file select screen again */
        DeleteNHistory(1);
        SetLeftSoftkeyFunction(UI_dummy_function, KEY_EVENT_UP);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_video_select_from_file_mamager_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_video_select_from_file_mamager_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) g_phb_video_file_path, phb_video_tmp_file_path);
    g_phb_cntx.video_location = MMI_PHB_IMAGE_SELECT_PATH;
    fmgr_reset_app_select();    /* Use select_repeat, so clear by application itself. */
    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, TRUE, PHB_NOTIFY_TIMEOUT, SUCCESS_TONE);
    DeleteUptoScrID(SCR_ID_PHB_VIDEO_OPTION);
    mmi_phb_video_free_buf();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_video_free_buf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_video_free_buf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (phb_video_tmp_file_path)
    {
        OslMfree(phb_video_tmp_file_path);
        phb_video_tmp_file_path = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_video_preview_endkey_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_video_preview_endkey_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Has to free the file name string buffer  */
    mmi_phb_video_free_buf();

    /* Execute the stored END key handler */
    if (phb_video_endkey_handler)
    {
        (*phb_video_endkey_handler) ();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_video_preview_go_back
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_video_preview_go_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Has to free the file name string buffer  */
    mmi_phb_video_free_buf();
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_video_preview
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_video_preview(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_PHB_VIDEO_PREVIEW, NULL, mmi_phb_video_preview, NULL);
    gui_buffer = GetCurrGuiBuffer(SCR_ID_PHB_VIDEO_PREVIEW);

    ShowCategory225Screen(
        STR_ID_PHB_ASSOCIATE_VIDEO,                    /* title_str */
        IMG_SCR_PBOOK_CAPTION,              /* title_icon */
        STR_GLOBAL_OK,                      /* lsk_str */
        IMG_GLOBAL_OK,                      /* lsk_icon */
        STR_GLOBAL_BACK,                    /* rsk_str */
        IMG_GLOBAL_BACK,                    /* rsk_icon */
        0,                                  /* video_id */
        (S8*) phb_video_tmp_file_path,      /* video_filename */
        1,                                  /* repeat_count */
        TRUE,                               /* is_visual_update */
        (BOOL) ! IsSilentModeActivated(),   /* is_play_audio */
        TRUE,                               /* is_lcd_no_sleep */
        GDI_COLOR_WHITE,                    /* bg_color */
        mmi_phb_video_play_callback,
        gui_buffer);

    phb_video_endkey_handler = GetKeyHandler(KEY_END, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_phb_video_preview_endkey_handler, KEY_END, KEY_EVENT_DOWN);

    SetLeftSoftkeyFunction(mmi_phb_video_select_from_file_mamager_done, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_phb_video_preview_go_back, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_video_select_from_file_mamager
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_video_select_from_file_mamager(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (mmi_usb_check_path_exported((S8*)L"root"))
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    if (isInCall()) /* Can not preview video during call. */
    {
        //fmgr_reset_app_select();    /* Use select_repeat, so clear by application itself. */
        DisplayPopup(
            (U8*) GetString(STR_ID_PHB_CANT_SELECT_CALLER_VIDEO_IN_CALL),
            IMG_GLOBAL_WARNING,
            FALSE,
            PHB_NOTIFY_TIMEOUT,
            WARNING_TONE);
        DeleteUptoScrID(SCR_ID_PHB_VIDEO_OPTION);
        return;
    }

    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET_VIDEO(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
#if defined(__DRM_V02__)
    FMGR_FILTER_SET(&filter, FMGR_TYPE_ODF);
#endif /* defined(__DRM_V02__) */

    mmi_fmgr_select_path_and_enter(
        APP_PHONEBOOK,
        FMGR_SELECT_FILE | FMGR_SELECT_REPEAT,
        filter,
        (S8*) L"root",
        (PsExtFuncPtr) mmi_phb_video_select_path_from_file_mamager);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_video_select_path_from_file_mamager
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path            [IN]         
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_video_select_path_from_file_mamager(void *path, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (path == NULL)   /* User does not select file and go back directly. */
    {
        GoBackToHistory(SCR_ID_PHB_VIDEO_OPTION);
        return;
    }

    /* Check File Path Length */
    if (mmi_phb_video_check_data_space((S8*) path))
    {
        phb_video_tmp_file_path = OslMalloc(FMGR_MAX_PATH_LEN * ENCODING_LENGTH + ENCODING_LENGTH);
        if (phb_video_tmp_file_path)
        {
            mmi_ucs2cpy((S8*) phb_video_tmp_file_path, (S8*) path);
        }
        else
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_NOT_DONE),
                IMG_GLOBAL_ERROR,
                FALSE,
                PHB_NOTIFY_TIMEOUT,
                ERROR_TONE);
            mmi_phb_video_free_buf();
            return;
        }
        mmi_ucs2cpy(phb_video_tmp_file_path, (S8*) path);
        mmi_phb_video_preview();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_video_delete_file_reference
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_video_delete_file_reference(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.video_location == MMI_PHB_IMAGE_NO_SELECT)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_PHB_FMGR_IMAGE_NO_SELECT),
            IMG_GLOBAL_ERROR,
            FALSE,
            PHB_NOTIFY_TIMEOUT,
            ERROR_TONE);
    }
    else
    {
        g_phb_cntx.video_location = MMI_PHB_IMAGE_NO_SELECT;
        DisplayPopup((U8*) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, TRUE, PHB_NOTIFY_TIMEOUT, SUCCESS_TONE);
    }
    g_phb_cntx.video_audio = 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_video_toggle_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_video_toggle_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;
    U16 str_LSK = STR_GLOBAL_OFF, str_hint = STR_GLOBAL_ON;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = GetCurrHiliteID();

    if (g_phb_cntx.video_audio)
    {
        g_phb_cntx.video_audio = 0;
        str_LSK = STR_GLOBAL_ON;
        str_hint = STR_GLOBAL_OFF;
        /* DisplayPopup((U8*)GetString(STR_GLOBAL_OFF), IMG_GLOBAL_ACTIVATED,  TRUE, UI_POPUP_NOTIFYDURATION_TIME, SUCCESS_TONE); */
    }
    else
    {
        g_phb_cntx.video_audio = 1;
        /* DisplayPopup((U8*)GetString(STR_GLOBAL_ON), IMG_GLOBAL_ACTIVATED,  TRUE, UI_POPUP_NOTIFYDURATION_TIME, SUCCESS_TONE); */
    }

    ChangeLeftSoftkey(str_LSK, IMG_GLOBAL_OK);
    mmi_ucs2cpy((S8*) hintData[index], GetString(str_hint));
    Category52ChangeItemDescription(index, hintData[index]);

    /* Redraw the Category Screen As Hint Handler and LSK are going to Chnage */
    RedrawCategoryFunction();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_video_get_id_by_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  store_index     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_phb_video_get_id_by_index(U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;
    U8 vid_record;
    U8 vid_index;
    U16 video_ids[NVRAM_EF_PHB_VIDEO_COUNT];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Save Video ID to NVRAM */
    vid_record = (store_index / NVRAM_EF_PHB_VIDEO_COUNT) + 1;
    vid_index = store_index - (vid_record - 1) * NVRAM_EF_PHB_VIDEO_COUNT;

    ReadRecord(NVRAM_EF_PHB_VIDEO_LID, vid_record, (void*)video_ids, NVRAM_EF_PHB_VIDEO_SIZE, &pError);

    return video_ids[vid_index];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_video_get_path_by_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  video_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
BOOL mmi_phb_video_get_path_by_index(U16 video_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 data_id;
    S32 data_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if an external resource id */
    if (video_id & 0x8000)
    {
        /* Get data record id and load the path */
        data_id = video_id & 0x3FFF;
    #ifdef __MMI_AVATAR__
        if (data_id & 0x1000)
        {
            data_id = data_id & ~0x1000;
        }
    #endif /* __MMI_AVATAR__ */
    #ifdef __MMI_SWFLASH__
        if (data_id & 0x2000)
        {
            data_id = data_id & ~0x2000;
        }
    #endif /* __MMI_SWFLASH__ */
        data_result = mmi_data_get_record(&g_phb_video_record_store, data_id, (void*)g_phb_video_file_path);

        if (data_result == 0)
        {
            return TRUE;
        }
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_caller_video_get_path_by_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  video_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S8 *mmi_phb_caller_video_get_path_by_index(U16 video_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 data_id;
    U16 data_original_id;
    S32 data_result;
#ifdef __MMI_AVATAR__
    U32 avatar_id;  
    U32 avatar_serial_num;
    S8 temp_buff[FMGR_MAX_PATH_LEN + 1];
    S8* avatar_serial_num_str;
    U16 i;
    MMI_BOOL is_avatar_serial_num_found = MMI_FALSE;
#endif /* def __MMI_AVATAR__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if an external resource id */
    if (video_id & 0x8000)
    {
        /* Get data record id and load the path */
        data_id = video_id & 0x3FFF;
        data_original_id = data_id;
    #ifdef __MMI_AVATAR__
        if (data_id & 0x1000)
        {
            data_id = data_id & ~0x1000;
        }
    #endif /* __MMI_AVATAR__ */
    #ifdef __MMI_SWFLASH__
        if (data_id & 0x2000)
        {
            data_id = data_id & ~0x2000;
        }
    #endif /* __MMI_SWFLASH__ */
        data_result = mmi_data_get_record(&g_phb_video_record_store, data_id, (void*)phb_caller_video_file_path);

        if (data_result == 0)
        {
        #ifdef __MMI_AVATAR__
            if (data_original_id & 0x1000) //avatar type
            {
                mmi_ucs2_to_asc(temp_buff, phb_caller_video_file_path);
                for (i = 0; temp_buff[i] != '\0'; i++)
				{
                    if (temp_buff[i] == '-')
                    {
                        is_avatar_serial_num_found = MMI_TRUE;
                        break;
                    }
                }
                if (is_avatar_serial_num_found == MMI_TRUE)
                {
                    avatar_serial_num_str = temp_buff + i + 1;
                    avatar_serial_num = (U32)atoi(avatar_serial_num_str);
                    temp_buff[i] =  '\0';
                }
                else
                {
                    avatar_serial_num = 0;
                }
                avatar_id = (U32)atoi(temp_buff);
                if (mmi_avatar_is_avatar_valid(avatar_id, avatar_serial_num))
                {
                    return (S8*)avatar_id;
                }
                else
                {
                    return NULL;
                }
            }
            else
        #endif /* def __MMI_AVATAR__ */
            {
                return (S8*) phb_caller_video_file_path;
            }
        }
    }
    return NULL;
}

#if 0
//Huyanwei Move it From __MMI_INCOMING_CALL_VIDEO__ to Outside


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_video_delete_by_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  store_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_video_delete_by_index(U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;
    U8 vid_record;
    U16 vid_index;
    U16 video_ids[NVRAM_EF_PHB_VIDEO_COUNT];
    U16 video_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Delete Video ID from NVRAM */
    vid_record = (store_index / NVRAM_EF_PHB_VIDEO_COUNT) + 1;
    vid_index = (U16)(store_index - (vid_record - 1) * NVRAM_EF_PHB_VIDEO_COUNT);

    ReadRecord(NVRAM_EF_PHB_VIDEO_LID, vid_record, (void*)video_ids, NVRAM_EF_PHB_VIDEO_SIZE, &pError);
    video_id = video_ids[vid_index];

    if (video_id != 0)
    {
        video_ids[vid_index] = 0;

        WriteRecord(NVRAM_EF_PHB_VIDEO_LID, vid_record, (void*)video_ids, NVRAM_EF_PHB_VIDEO_SIZE, &pError);

        /* Delete data record if video from file path */
        if (video_id & 0x8000)
        {
            video_id &= 0xFFF;
            mmi_data_delete_record(&g_phb_video_record_store, video_id);
        }
    }
}



#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_video_duplicate_by_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest_index      [IN]        
 *  src_index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
BOOL mmi_phb_video_duplicate_by_index(U16 dest_index, U16 src_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;
    U8 src_vid_record, dst_vid_record;
    U8 vid_index;
    U16 video_ids[NVRAM_EF_PHB_VIDEO_COUNT];
    U16 video_id;
    S32 data_result;
    U16 data_id;
    BOOL is_success = TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* read source video id */
    src_vid_record = (src_index / NVRAM_EF_PHB_VIDEO_COUNT) + 1;
    vid_index = src_index - (src_vid_record - 1) * NVRAM_EF_PHB_VIDEO_COUNT;
    ReadRecord(NVRAM_EF_PHB_VIDEO_LID, src_vid_record, (void*)video_ids, NVRAM_EF_PHB_VIDEO_SIZE, &pError);
    video_id = video_ids[vid_index];

    /* Read Destination video id */
    dst_vid_record = (dest_index / NVRAM_EF_PHB_VIDEO_COUNT) + 1;
    vid_index = dest_index - (dst_vid_record - 1) * NVRAM_EF_PHB_VIDEO_COUNT;
    if (dst_vid_record != src_vid_record)
    {
        ReadRecord(NVRAM_EF_PHB_VIDEO_LID, dst_vid_record, (void*)video_ids, NVRAM_EF_PHB_VIDEO_SIZE, &pError);
    }

    /* Duplicate File, an external file path */
    if (video_id & 0x8000)
    {
        /* Get source path */
        data_id = video_id & 0xFFF;
        data_result = mmi_data_get_record(&g_phb_video_record_store, data_id, (void*)g_phb_video_file_path);

        /* Get external file and video's audio bits */
        video_id &= 0xF000;

        /* Write to destination record and get data id */
        if ((data_result == 0) &&
            (mmi_data_add_record(&g_phb_video_record_store, &data_id, (void*)g_phb_video_file_path) == 0))
        {
            video_id |= data_id;    /* Set the new data id into bits */
        }
        else
        {
            video_id = 0;
            is_success = FALSE; /* data record add fail */
        }
    }

    /* Duplicate ID */
    video_ids[vid_index] = video_id;
    WriteRecord(NVRAM_EF_PHB_VIDEO_LID, dst_vid_record, (void*)video_ids, NVRAM_EF_PHB_VIDEO_SIZE, &pError);

    return is_success;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_video_update_by_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  store_index     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
BOOL mmi_phb_video_update_by_index(U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;
    U8 vid_record;
    U8 vid_index;
    U16 video_ids[NVRAM_EF_PHB_VIDEO_COUNT];
    BOOL update_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Retrieve video id list from NVRAM */
    vid_record = (store_index / NVRAM_EF_PHB_VIDEO_COUNT) + 1;
    vid_index = store_index - (vid_record - 1) * NVRAM_EF_PHB_VIDEO_COUNT;
    ReadRecord(NVRAM_EF_PHB_VIDEO_LID, vid_record, (void*)video_ids, NVRAM_EF_PHB_VIDEO_SIZE, &pError);

    /* Wrtie to data record file */
    video_ids[vid_index] = mmi_phb_video_update_by_index_for_path(video_ids[vid_index], &update_result);

    /* Write back to NVRAM */
    WriteRecord(NVRAM_EF_PHB_VIDEO_LID, vid_record, (void*)video_ids, NVRAM_EF_PHB_VIDEO_SIZE, &pError);

    /* If data to data record structure fail. */
    return update_result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_video_update_by_index_for_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  original_id         [IN]        
 *  update_result       [?]         
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_phb_video_update_by_index_for_path(U16 original_id, BOOL *update_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 data_id;
    U16 video_id;
    S32 data_result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *update_result = TRUE;

    /* Remove data record first, then check if need to add it back */
    if (original_id & 0x8000)
    {
        data_id = original_id & 0xFFF;
        mmi_data_delete_record(&g_phb_video_record_store, data_id);
    }

    /* Assign new selected video id */
    video_id = g_phb_cntx.video_id_list[g_phb_cntx.selected_video_index];

    /* Video From Outside Path, Save path to data record structure */
    if (g_phb_cntx.selected_video_index == g_phb_cntx.total_video_id - 1
    #ifdef __MMI_AVATAR__
        || g_phb_cntx.selected_video_index == g_phb_cntx.total_video_id - g_phb_avatar_video_minus
    #endif
    #ifdef __MMI_SWFLASH__
        || g_phb_cntx.selected_video_index == g_phb_cntx.total_video_id - g_phb_swflash_video_minus
    #endif
    )
    {
        if (g_phb_cntx.video_location == MMI_PHB_IMAGE_SELECT_PATH
        #ifdef __MMI_AVATAR__
            || g_phb_cntx.video_location == MMI_PHB_AVATAR_SELECT_PATH
        #endif
        #ifdef __MMI_SWFLASH__
            || g_phb_cntx.video_location == MMI_PHB_SWFLASH_SELECT_PATH
        #endif
        )
        {
            data_result = mmi_data_add_record(&g_phb_video_record_store, &data_id, (void*)g_phb_video_file_path);
            if (data_result == FS_FILE_NOT_FOUND)
            {
                data_result = mmi_data_add_record(&g_phb_video_record_store, &data_id, (void*)g_phb_video_file_path);
            }

            if (data_result == 0)
            {
                video_id |= data_id;
            }
            else    /* Save path to file fail */
            {
                video_id = 0;
                *update_result = FALSE;
            }
        }
        else    /* didn't select the file path */
        {
            video_id = 0;
        }
    }

    /* Assign Video's Audio bit */
    if (video_id != 0)
    {
        if ((g_phb_cntx.video_audio) && (!(video_id & 0x1000))) //avatar video has no audio
        {
            video_id |= 0x4000;
        }
        else
        {
            video_id &= 0xBFFF;
        }
    }

    return video_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_video_check_data_space
 * DESCRIPTION
 *  Check free space in data record before save to phonebook.
 * PARAMETERS
 *  path        [?]     
 * RETURNS
 *  
 *****************************************************************************/
BOOL mmi_phb_video_check_data_space(S8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *error_str_ptr;
    S32 result;
#ifdef __DRM_SUPPORT__
    BOOL drm_ret = TRUE;
    FS_HANDLE fh;
#endif /* def __DRM_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DRM_SUPPORT__
    fh = DRM_open_file((kal_wchar *)path, FS_READ_ONLY, DRM_PERMISSION_PLAY);

    if (fh >= FS_NO_ERROR)
    {
        drm_ret = DRM_validate_forward_rule(fh, DRM_PERMISSION_PLAY);
        DRM_close_file(fh);
    }

    if (drm_ret == FALSE)
        return FALSE;
#endif /* def __DRM_SUPPORT__ */

    result = mmi_data_check_space_for_add_record(&g_phb_video_record_store);
    if (result != 0)
    {
        if (result < 0)
        {
            DisplayPopup(
                (U8*) GetString(GetFileSystemErrorString(result)),
                IMG_GLOBAL_ERROR,
                FALSE,
                PHB_NOTIFY_TIMEOUT,
                ERROR_TONE);
        }
        else
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_PHB_FMGR_DISC_FULL),
                IMG_GLOBAL_ERROR,
                FALSE,
                PHB_NOTIFY_TIMEOUT,
                ERROR_TONE);
        }
        return FALSE;
    }
    if (path && !mmi_fmgr_util_file_limit_check(FMGR_LIMIT_CALLER_VIDEO, path, &error_str_ptr))
    {
        DisplayPopup((U8*) error_str_ptr, IMG_GLOBAL_ERROR, FALSE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
        return FALSE;
    }
    return TRUE;
}


#ifdef __MMI_AVATAR__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_avatar_video_pre_entry_file_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_avatar_video_pre_entry_file_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.video_location != MMI_PHB_AVATAR_SELECT_PATH)
	{
        mmi_phb_entry_avatar_video_file_option(2);
    }
    else
    {
        mmi_phb_entry_avatar_video_file_option(1);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_avatar_video_file_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_avatar_video_file_option(U8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[5];
    U16 nNumofItem;
    U8 *hintList[5];    /* Array for hint */
    U32 HideItemId = -1, HideItemId1 = -1;
    U32 maskingByte = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_PHB_AVATAR_VIDEO_OPTION, NULL, mmi_phb_avatar_video_pre_entry_file_option, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_PHB_AVATAR_VIDEO_OPTION);  /* Getting the Index from history */

    nNumofItem = GetNumOfChild(MENU_ID_PHB_AVATAR_VIDEO_FILE_OPTION);
    GetSequenceStringIds(MENU_ID_PHB_AVATAR_VIDEO_FILE_OPTION, nStrItemList);
    SetParentHandler(MENU_ID_PHB_AVATAR_VIDEO_FILE_OPTION);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* Construct List To Show Hint */
    ConstructHintsList(MENU_ID_PHB_AVATAR_VIDEO_FILE_OPTION, hintList);

    /* Hide menu item play and delete when file not selected. */
    /* Regiser highlight handler again. */
    mmi_phb_operate_single_init();

    /* File not selected */
    if (type == 2)
    {
        HideItemId = GetChildMenuIDIndexByParentMenuID(MENU_ID_PHB_AVATAR_VIDEO_FILE_OPTION, MENU_ID_PHB_AVATAR_VIDEO_FILE_VIEW);
        HideItemId1 = GetChildMenuIDIndexByParentMenuID(MENU_ID_PHB_AVATAR_VIDEO_FILE_OPTION, MENU_ID_PHB_AVATAR_VIDEO_FILE_DELETE);
        if ((HideItemId != -1) && (HideItemId1 != -1))
        {
            ResetBit(maskingByte, HideItemId);
            ResetBit(maskingByte, HideItemId1);
            MaskHiliteItems(MENU_ID_PHB_AVATAR_VIDEO_FILE_OPTION, maskingByte);
            MaskStringItems(hintList, (U8) nNumofItem, maskingByte);
            nNumofItem = MaskItems(nStrItemList, (U8) nNumofItem, maskingByte);
        }
    }

    /* Screen with hint */
    ShowCategory52Screen(
        STR_ID_PHB_ASSOCIATE_VIDEO,
        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        hintList,
        0,
        0,
        guiBuffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    g_phb_avatar_video_view = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_avatar_video_file_view
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_avatar_video_file_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);

    SetLeftSoftkeyFunction(mmi_phb_video_view_from_file, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_video_view_from_file, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_avatar_video_file_select
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_avatar_video_file_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);

    SetLeftSoftkeyFunction(mmi_phb_avatar_video_select_from_file_manager, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_avatar_video_select_from_file_manager, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_avatar_video_file_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_avatar_video_file_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);

    SetLeftSoftkeyFunction(mmi_phb_video_delete_file_reference, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_avatar_video_select_from_file_manager
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_avatar_video_select_from_file_manager(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (mmi_usb_check_path_exported((S8*)L"root"))
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    if (isInCall()) /* Can not preview video during call. */
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_PHB_CANT_SELECT_CALLER_VIDEO_IN_CALL),
            IMG_GLOBAL_WARNING,
            FALSE,
            PHB_NOTIFY_TIMEOUT,
            WARNING_TONE);
        DeleteUptoScrID(SCR_ID_PHB_AVATAR_VIDEO_OPTION);
        return;
    }
    mmi_avatar_select_path_and_enter (MMI_AVATAR_APP_CALLER_VIDEO, 
        mmi_phb_avatar_video_select_path_from_file_manager);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_avatar_video_select_path_from_file_manager
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id            [IN]               
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_avatar_video_select_path_from_file_manager(U32 id, U32 serial_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S8 temp_buff[FMGR_MAX_PATH_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check Video Data Space */
    if (mmi_phb_video_check_data_space(NULL))
    {
        sprintf(temp_buff, "%d-%d", id, serial_num);
        phb_video_tmp_file_path = OslMalloc(FMGR_MAX_PATH_LEN * ENCODING_LENGTH + ENCODING_LENGTH);
        if (phb_video_tmp_file_path)
        {
            mmi_asc_to_ucs2((S8*) phb_video_tmp_file_path, temp_buff);  
        }
        else
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_NOT_DONE),
                IMG_GLOBAL_ERROR,
                FALSE,
                PHB_NOTIFY_TIMEOUT,
                ERROR_TONE);
            return;
        }
        mmi_phb_avatar_video_select_from_file_manager_done();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_avatar_video_select_from_file_manager_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_avatar_video_select_from_file_manager_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_phb_video_file_path, 0, (FMGR_MAX_PATH_LEN * ENCODING_LENGTH + ENCODING_LENGTH));
    mmi_ucs2cpy(g_phb_video_file_path ,phb_video_tmp_file_path);
    g_phb_cntx.video_location = MMI_PHB_AVATAR_SELECT_PATH;
    DeleteUptoScrID(SCR_ID_PHB_AVATAR_VIDEO_OPTION);
	DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, TRUE, PHB_NOTIFY_TIMEOUT, SUCCESS_TONE);
    mmi_phb_video_free_buf();
}
#endif /* __MMI_AVATAR__ */


#ifdef __MMI_SWFLASH__
/*****************************************************************************
* FUNCTION
*  mmi_phb_entry_swflash_default_option
* DESCRIPTION
*
*
* PARAMETERS
*  void
* RETURNS
*
* GLOBALS AFFECTED
*   none
*****************************************************************************/
static void mmi_phb_entry_swflash_default_option(void)
{
	U8* guiBuffer;
	U16 nStrItemList[5];
	U16 nNumofItem;
	U8 *hintList[5]; /* Array for hint */

	EntryNewScreen(SCR_ID_PHB_SWFLASH_OPTION, NULL, mmi_phb_entry_swflash_default_option,NULL);
	guiBuffer = GetCurrGuiBuffer(SCR_ID_PHB_SWFLASH_OPTION);		/* Getting the Index from history */

	nNumofItem = GetNumOfChild(MENU_ID_PHB_SWFLASH_DEFAULT_OPTION);
	GetSequenceStringIds(MENU_ID_PHB_SWFLASH_DEFAULT_OPTION, nStrItemList);
	SetParentHandler(MENU_ID_PHB_SWFLASH_DEFAULT_OPTION);

	RegisterHighlightHandler(ExecuteCurrHiliteHandler);

	/* Construct List To Show Hint */
	ConstructHintsList(MENU_ID_PHB_SWFLASH_DEFAULT_OPTION, hintList);

	/* Screen with hint */
	ShowCategory52Screen(STR_ID_PHB_ASSOCIATE_SWFLASH,
								   IMG_SCR_PBOOK_CAPTION,
								   STR_GLOBAL_OK,
								   IMG_GLOBAL_OK,
								   STR_GLOBAL_BACK,
								   IMG_GLOBAL_BACK,
								   nNumofItem,
								   nStrItemList,
								   (U16*)gIndexIconsImageList,
								   hintList,
								   0,
								   0,
								   guiBuffer);

	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	SetKeyHandler(GoBackHistory,KEY_LEFT_ARROW,KEY_EVENT_DOWN);
    g_phb_swflash_view = TRUE;
}

/*****************************************************************************
* FUNCTION
*  mmi_phb_swflash_pre_entry_file_option
* DESCRIPTION
*
*
* PARAMETERS
*  void
* RETURNS
*
* GLOBALS AFFECTED
*   none
*****************************************************************************/
static void mmi_phb_swflash_pre_entry_file_option(void)
{
	if(g_phb_cntx.video_location == MMI_PHB_SWFLASH_SELECT_PATH)
		mmi_phb_entry_swflash_file_option(1);
	else
		mmi_phb_entry_swflash_file_option(2);
}

/*****************************************************************************
* FUNCTION
*  mmi_phb_entry_swflash_file_option
* DESCRIPTION
*
*
* PARAMETERS
*  void
* RETURNS
*
* GLOBALS AFFECTED
*   none
*****************************************************************************/
static void mmi_phb_entry_swflash_file_option(U8 type)
{
	U8* guiBuffer;
	U16 nStrItemList[5];
	U16 nNumofItem;
	U8 *hintList[5]; /*Array for hint*/
	U32 HideItemId = -1, HideItemId1 = -1, HideItemId2 = -1;
	U32 maskingByte = -1;


	EntryNewScreen(SCR_ID_PHB_SWFLASH_OPTION, NULL, mmi_phb_swflash_pre_entry_file_option,NULL);
	guiBuffer = GetCurrGuiBuffer(SCR_ID_PHB_SWFLASH_OPTION);		/* Getting the Index from history */

	nNumofItem = GetNumOfChild(MENU_ID_PHB_SWFLASH_FILE_OPTION);
	GetSequenceStringIds(MENU_ID_PHB_SWFLASH_FILE_OPTION, nStrItemList);
	SetParentHandler(MENU_ID_PHB_SWFLASH_FILE_OPTION);

	RegisterHighlightHandler(ExecuteCurrHiliteHandler);

	/* Construct List To Show Hint*/
	ConstructHintsList(MENU_ID_PHB_SWFLASH_FILE_OPTION, hintList);

	/*Hide menu item play and delete when file not selected.*/
	/*Regiser highlight handler again.*/
	mmi_phb_operate_single_init();

	/*File not selected*/
	if(type == 2)
	{
		HideItemId = GetChildMenuIDIndexByParentMenuID(MENU_ID_PHB_SWFLASH_FILE_OPTION,MENU_ID_PHB_SWFLASH_FILE_VIEW);
		HideItemId1=	GetChildMenuIDIndexByParentMenuID(MENU_ID_PHB_SWFLASH_FILE_OPTION,MENU_ID_PHB_SWFLASH_FILE_DELETE);
		HideItemId2=	GetChildMenuIDIndexByParentMenuID(MENU_ID_PHB_SWFLASH_FILE_OPTION,MENU_ID_PHB_SWFLASH_FILE_SETTING);
		if((HideItemId != -1) && (HideItemId1 != -1) && (HideItemId2 != -1))
		{
			ResetBit(maskingByte,HideItemId);
			ResetBit(maskingByte,HideItemId1);
			ResetBit(maskingByte,HideItemId2);
			MaskHiliteItems(MENU_ID_PHB_SWFLASH_FILE_OPTION, maskingByte);
			MaskStringItems(hintList,(U8)nNumofItem,maskingByte);
			nNumofItem=MaskItems(nStrItemList,(U8)nNumofItem,maskingByte);
		}
	}

	/*Screen with hint*/
	ShowCategory52Screen(STR_ID_PHB_ASSOCIATE_SWFLASH,
								   IMG_SCR_PBOOK_CAPTION,
								   STR_GLOBAL_OK,
								   IMG_GLOBAL_OK,
								   STR_GLOBAL_BACK,
								   IMG_GLOBAL_BACK,
								   nNumofItem,
								   nStrItemList,
								   (U16*)gIndexIconsImageList,
								   hintList,
								   0,
								   0,
								   guiBuffer);
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	SetKeyHandler(GoBackHistory,KEY_LEFT_ARROW,KEY_EVENT_DOWN);
    g_phb_swflash_view = TRUE;
}


/*****************************************************************************
* FUNCTION
*
* DESCRIPTION
*
*
* PARAMETERS
*  void
* RETURNS
*
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mmi_phb_swflash_select_from_file_mamager_done(void)
{
	mmi_ucs2cpy((S8*)g_phb_video_file_path, phb_video_tmp_file_path);
	g_phb_cntx.video_location = MMI_PHB_SWFLASH_SELECT_PATH;
	fmgr_reset_app_select();	/*Use select_repeat, so clear by application itself.*/
	DisplayPopup((PU8)GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, TRUE, PHB_NOTIFY_TIMEOUT, SUCCESS_TONE);
	DeleteUptoScrID(SCR_ID_PHB_SWFLASH_OPTION);
	mmi_phb_video_free_buf();
}


/*****************************************************************************
* FUNCTION
*   mmi_phb_swflash_play_callback
* DESCRIPTION
*   
* PARAMETERS
* 	 result	  IN		play result     
* RETURNS
*   void
* GLOBALS AFFECTED
*   NULL
*****************************************************************************/
void mmi_phb_swflash_play_callback(S32 result)
{
	/*----------------------------------------------------------------*/
	/* Code Body																		*/
	/*----------------------------------------------------------------*/
	
    if(result>=0)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(mmi_phb_swflash_select_from_file_mamager_done,KEY_EVENT_UP);
    }
    else
    {
        ChangeLeftSoftkey(0,0);
        ChangeRightSoftkey(0,0);
		
        DisplayPopup(
            (PU8)GetString(STR_FMGR_INVALID_FORMAT),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            WARNING_TONE);
        mmi_phb_video_free_buf();
        /* delete to file select screen again */
        DeleteNHistory(1);
        SetLeftSoftkeyFunction(UI_dummy_function,KEY_EVENT_UP);
	}

}


/*****************************************************************************
* FUNCTION
*
* DESCRIPTION
*
*
* PARAMETERS
*  void
* RETURNS
*
* GLOBALS AFFECTED
*   none
*****************************************************************************/
static void mmi_phb_swflash_preview(void)
{
    PU8	gui_buffer;

    EntryNewScreen(SCR_ID_PHB_SWFLASH_PREVIEW, NULL, mmi_phb_swflash_preview, NULL);
    gui_buffer = GetCurrGuiBuffer(SCR_ID_PHB_SWFLASH_PREVIEW);

    ShowCategory229Screen(
        (U8*)GetString(STR_GLOBAL_VIEW),        /* title_str */
        IMG_SCR_PBOOK_CAPTION,	                /* title_icon */
        STR_GLOBAL_OK,                          /* lsk_str */
        IMG_GLOBAL_OK,                          /* lsk_icon */
        STR_GLOBAL_BACK,                        /* rsk_str */
        IMG_GLOBAL_BACK,                        /* rsk_icon */
        0,                                      /* video_id */
        (S8*)phb_video_tmp_file_path,	        /* video_filename */
        1,                                      /* repeat_count */
        (BOOL)!IsSilentModeActivated(),		    /* is_play_audio */
        TRUE,                                   /* is_vibrate_on */
        TRUE,                                   /* is_interaction_on */
        TRUE,                                   /* is_lcd_no_sleep */
        0,                                      /* is_full_screen */
        GDI_COLOR_WHITE,                        /* bg_color */
        mmi_phb_swflash_play_callback,
        gui_buffer);

    phb_video_endkey_handler = GetKeyHandler( KEY_END, KEY_EVENT_DOWN );
    SetKeyHandler (mmi_phb_video_preview_endkey_handler, KEY_END, KEY_EVENT_DOWN);

    SetLeftSoftkeyFunction(mmi_phb_swflash_select_from_file_mamager_done,KEY_EVENT_UP);
    SetRightSoftkeyFunction (mmi_phb_video_preview_go_back, KEY_EVENT_UP);
}


/*****************************************************************************
* FUNCTION
*
* DESCRIPTION
*
*
* PARAMETERS
*  void
* RETURNS
*
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mmi_phb_swflash_select_path_from_file_mamager(void* path, int is_short)
{

    if(path == NULL) 	/*User does not select file and go back directly.*/
    {
        GoBackToHistory(SCR_ID_PHB_SWFLASH_OPTION);
        return;
    }

    /*Check File Path Length*/
    if(mmi_phb_video_check_data_space((S8*)path))
    {
        phb_video_tmp_file_path = OslMalloc( FMGR_MAX_PATH_LEN*ENCODING_LENGTH+ENCODING_LENGTH );
        if( phb_video_tmp_file_path )
        {
            mmi_ucs2cpy((S8 *)phb_video_tmp_file_path, (S8*)path);
        }
        else
        {
            DisplayPopup((U8*)GetString(STR_GLOBAL_NOT_DONE), IMG_GLOBAL_ERROR, FALSE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
            mmi_phb_video_free_buf();
            return;
        }
        mmi_ucs2cpy(phb_video_tmp_file_path, (S8*)path);
        mmi_phb_swflash_preview();
    }
}



/*****************************************************************************
* FUNCTION
*
* DESCRIPTION
*
*
* PARAMETERS
*  void
* RETURNS
*
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mmi_phb_swflash_select_from_file_mamager(void)
{
    FMGR_FILTER filter;

    if(isInCall())	/*Can not preview video during call.*/
    {
        //fmgr_reset_app_select();	/*Use select_repeat, so clear by application itself.*/
        DisplayPopup((U8*)GetString(STR_ID_PHB_CANT_VIEW_SWFLASH_IN_CALL), IMG_GLOBAL_WARNING, FALSE, PHB_NOTIFY_TIMEOUT, WARNING_TONE);
        DeleteUptoScrID(SCR_ID_PHB_SWFLASH_OPTION);
        return;
    }
	
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET_SWFLASH(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_CLEAR(&filter, FMGR_TYPE_ZDD);
    mmi_fmgr_select_path_and_enter(APP_PHONEBOOK,
        FMGR_SELECT_FILE|FMGR_SELECT_REPEAT,
        filter,
        (S8*)L"root",
        (PsExtFuncPtr)mmi_phb_swflash_select_path_from_file_mamager);
}


/*****************************************************************************
* FUNCTION
*
* DESCRIPTION
*
*
* PARAMETERS
*  void
* RETURNS
*
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mmi_phb_highlight_swflash_file_select(void)
{
	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);

	SetLeftSoftkeyFunction(mmi_phb_swflash_select_from_file_mamager,KEY_EVENT_UP);
	SetKeyHandler(mmi_phb_swflash_select_from_file_mamager,KEY_RIGHT_ARROW,KEY_EVENT_DOWN);
}
#endif /* __MMI_SWFLASH__ */

#endif /* defined(__MMI_INCOMING_CALL_VIDEO__) */ 

#if defined(__MMI_PHB_BIRTHDAY_FIELD__)


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_util_clear_bday_buffer
 * DESCRIPTION
 *  Clears birthday buffers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_util_clear_bday_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(pbYear, (S8*) MMI_PHB_BDAY_YEAR_STR);
    mmi_ucs2cpy(pbMon, (S8*) MMI_PHB_BDAY_MON_STR);
    mmi_ucs2cpy(pbDay, (S8*) MMI_PHB_BDAY_DAY_STR);
    bday_modified = FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_bday_set_changed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_phb_bday_set_changed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bday_modified = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_bday_changed_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  a(?)        [IN]        Changed item index
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
static void mmi_phb_bday_changed_callback(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == bday_inline_index)
    {
        bday_modified = TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_bday_editor_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  DateStr     [?]             
 *  day         [?]             
 *  month       [?]             
 *  year        [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_phb_bday_editor_callback(U8 *DateStr, U8 *day, U8 *month, U8 *year)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bday_modified)
    {
        mmi_ucs2cpy((S8*) DateStr, (S8*) year);
        mmi_ucs2cat((S8*) DateStr, (S8*) "/");
        mmi_ucs2cat((S8*) DateStr, (S8*) month);
        mmi_ucs2cat((S8*) DateStr, (S8*) "/");
        mmi_ucs2cat((S8*) DateStr, (S8*) day);
    }
    else
    {
        mmi_ucs2cpy((S8*) DateStr, (S8*) (PU8) GetString(STR_GLOBAL_NONE));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_bday_read_data_to_buff
 * DESCRIPTION
 *  
 * PARAMETERS
 *  store_index     [IN]        
 *  a(?)            [IN]        Store index
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_phb_bday_read_data_to_buff(U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 bday_record, bday_index;
    S16 pError;
    S8 ascii_buff[6];
    MMI_PHB_BDAY_STRUCT bday_data[NVRAM_EF_PHB_BIRTHDAY_COUNT];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bday_record = (store_index / NVRAM_EF_PHB_BIRTHDAY_COUNT) + 1;
    bday_index = store_index - (bday_record - 1) * NVRAM_EF_PHB_BIRTHDAY_COUNT;

    ReadRecord(NVRAM_EF_PHB_BIRTHDAY_LID, bday_record, (void*)bday_data, NVRAM_EF_PHB_BIRTHDAY_SIZE, &pError);

    /* Year */
    if (bday_data[bday_index].bYear <= MMI_PHB_BDAY_MAX_YEAR_INT)
    {
        sprintf(ascii_buff, "%04d", bday_data[bday_index].bYear);
        mmi_asc_to_ucs2(pbYear, ascii_buff);
    }
    else
    {
        mmi_ucs2cpy(pbYear, (S8*) MMI_PHB_BDAY_YEAR_STR);
    }

    /* Month */
    if (bday_data[bday_index].bMonth <= 12)
    {
        sprintf(ascii_buff, "%02d", bday_data[bday_index].bMonth);
        mmi_asc_to_ucs2(pbMon, ascii_buff);
    }
    else
    {
        mmi_ucs2cpy(pbMon, (S8*) MMI_PHB_BDAY_MON_STR);
    }

    /* Day */
    if (bday_data[bday_index].bDay <= 31)
    {
        sprintf(ascii_buff, "%02d", bday_data[bday_index].bDay);
        mmi_asc_to_ucs2(pbDay, ascii_buff);
    }
    else
    {
        mmi_ucs2cpy(pbDay, (S8*) MMI_PHB_BDAY_DAY_STR);
    }

    if (mmi_ucs2cmp((const S8*)pbYear, (const S8*)MMI_PHB_BDAY_YEAR_STR) != 0 ||
        mmi_ucs2cmp((const S8*)pbMon, (const S8*)MMI_PHB_BDAY_MON_STR) != 0 ||
        mmi_ucs2cmp((const S8*)pbDay, (const S8*)MMI_PHB_BDAY_DAY_STR) != 0)
    {
        bday_modified = TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_bday_update_field
 * DESCRIPTION
 *  
 * PARAMETERS
 *  store_index     [IN]            
 *  b_year          [?]             
 *  b_mon           [?]             
 *  b_day           [?]             
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_phb_bday_update_field(U16 store_index, S8 *b_year, S8 *b_mon, S8 *b_day)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 bday_record, bday_index;
    S16 pError;
    U16 year, month, day;
    S8 ascii_buff[6];
    MMI_PHB_BDAY_STRUCT bday_data[NVRAM_EF_PHB_BIRTHDAY_COUNT];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc(ascii_buff, b_year);
    year = atoi(ascii_buff);
    mmi_ucs2_to_asc(ascii_buff, b_mon);
    month = atoi(ascii_buff);
    mmi_ucs2_to_asc(ascii_buff, b_day);
    day = atoi(ascii_buff);

    bday_record = (store_index / NVRAM_EF_PHB_BIRTHDAY_COUNT) + 1;
    bday_index = store_index - (bday_record - 1) * NVRAM_EF_PHB_BIRTHDAY_COUNT;

    ReadRecord(NVRAM_EF_PHB_BIRTHDAY_LID, bday_record, (void*)bday_data, NVRAM_EF_PHB_BIRTHDAY_SIZE, &pError);

    bday_data[bday_index].bYear = year;
    bday_data[bday_index].bMonth = (U8) month;
    bday_data[bday_index].bDay = (U8) day;

    WriteRecord(NVRAM_EF_PHB_BIRTHDAY_LID, bday_record, (void*)bday_data, NVRAM_EF_PHB_BIRTHDAY_SIZE, &pError);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_bday_delete_field
 * DESCRIPTION
 *  
 * PARAMETERS
 *  store_index     [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_phb_bday_delete_field(U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 bday_record, bday_index;
    S16 pError;
    MMI_PHB_BDAY_STRUCT bday_data[NVRAM_EF_PHB_BIRTHDAY_COUNT];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bday_record = (store_index / NVRAM_EF_PHB_BIRTHDAY_COUNT) + 1;
    bday_index = store_index - (bday_record - 1) * NVRAM_EF_PHB_BIRTHDAY_COUNT;

    ReadRecord(NVRAM_EF_PHB_BIRTHDAY_LID, bday_record, (void*)bday_data, NVRAM_EF_PHB_BIRTHDAY_SIZE, &pError);

    memset(&bday_data[bday_index], 0, sizeof(MMI_PHB_BDAY_STRUCT));

    WriteRecord(NVRAM_EF_PHB_BIRTHDAY_LID, bday_record, (void*)bday_data, NVRAM_EF_PHB_BIRTHDAY_SIZE, &pError);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_bday_duplicate_field
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest_index      [IN]            
 *  src_index       [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_phb_bday_duplicate_field(U16 dest_index, U16 src_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;
    U16 src_record, dst_record;
    U16 bday_index;
    MMI_PHB_BDAY_STRUCT bday_data[NVRAM_EF_PHB_BIRTHDAY_COUNT];
    MMI_PHB_BDAY_STRUCT bday_record;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* read source bday field */
    src_record = (src_index / NVRAM_EF_PHB_BIRTHDAY_COUNT) + 1;
    bday_index = src_index - (src_record - 1) * NVRAM_EF_PHB_BIRTHDAY_COUNT;
    ReadRecord(NVRAM_EF_PHB_BIRTHDAY_LID, src_record, (void*)bday_data, NVRAM_EF_PHB_BIRTHDAY_SIZE, &pError);

    memcpy(&bday_record, &bday_data[bday_index], sizeof(MMI_PHB_BDAY_STRUCT));

    /* Read Destination video id */
    dst_record = (dest_index / NVRAM_EF_PHB_BIRTHDAY_COUNT) + 1;
    bday_index = dest_index - (dst_record - 1) * NVRAM_EF_PHB_BIRTHDAY_COUNT;
    if (dst_record != src_record)
    {
        ReadRecord(NVRAM_EF_PHB_BIRTHDAY_LID, dst_record, (void*)bday_data, NVRAM_EF_PHB_BIRTHDAY_SIZE, &pError);
    }

    /* Duplicate ID */
    memcpy(&bday_data[bday_index], &bday_record, sizeof(MMI_PHB_BDAY_STRUCT));
    WriteRecord(NVRAM_EF_PHB_BIRTHDAY_LID, dst_record, (void*)bday_data, NVRAM_EF_PHB_BIRTHDAY_SIZE, &pError);
}

#endif /* defined(__MMI_PHB_BIRTHDAY_FIELD__) */ 

#if defined(__MMI_PHB_INFO_FIELD__)


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_util_clear_info_buffer
 * DESCRIPTION
 *  Clears extra buffers used for editing entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_util_clear_info_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(pbTitle, 0, ENCODING_LENGTH);
    memset(pbUrl, 0, ENCODING_LENGTH);
    memset(pbAddress, 0, ENCODING_LENGTH);
    memset(pbNote, 0, ENCODING_LENGTH);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_info_read_data_to_buff
 * DESCRIPTION
 *  
 * PARAMETERS
 *  store_index     [IN]        
 *  a(?)            [IN]        Stored index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_info_read_data_to_buff(U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(
        NVRAM_EF_PHB_INFO_LID,
        (U16) (store_index + 1),
        (void*)&PhoneBookInfoFields,
        MMI_PHB_INFO_RECORD_SIZE,
        &pError);
    mmi_ucs2cpy(pbTitle, (PS8) PhoneBookInfoFields.title);
    mmi_asc_to_ucs2(pbUrl, (PS8) PhoneBookInfoFields.url);
    mmi_ucs2cpy(pbAddress, (PS8) PhoneBookInfoFields.address);
    mmi_ucs2cpy(pbNote, (PS8) PhoneBookInfoFields.note);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_info_delete_field
 * DESCRIPTION
 *  Delete information fields of a Phone entry on NVRAM
 * PARAMETERS
 *  store_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_info_delete_field(U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Delete information fields. */
    memset(&PhoneBookInfoFields, 0, sizeof(PhoneBookInfoFields));
    WriteRecord(
        NVRAM_EF_PHB_INFO_LID,
        (U16) (store_index + 1),
        (void*)&PhoneBookInfoFields,
        MMI_PHB_INFO_RECORD_SIZE,
        &pError);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_info_update_field
 * DESCRIPTION
 *  Saves information fields of a Phone entry on NVRAM
 * PARAMETERS
 *  store_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_info_update_field(U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Update information fields. */
    mmi_ucs2cpy((PS8) PhoneBookInfoFields.title, pbTitle);
    mmi_ucs2_to_asc((PS8) PhoneBookInfoFields.url, pbUrl);
    mmi_ucs2cpy((PS8) PhoneBookInfoFields.address, pbAddress);
    mmi_ucs2cpy((PS8) PhoneBookInfoFields.note, pbNote);
    WriteRecord(
        NVRAM_EF_PHB_INFO_LID,
        (U16) (store_index + 1),
        (void*)&PhoneBookInfoFields,
        MMI_PHB_INFO_RECORD_SIZE,
        &pError);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_view_fill_extra_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  field_index     [IN]            
 *  item_index      [IN]            
 *  entry_list      [IN]            
 *  title_list      [?]             
 *  image_list      [?]             
 *  a(?)            [IN]            Field index for the enum value
 *  d(?)            [IN/OUT]        String list for title
 *  e(?)            [IN/OUT]        Image list
 *  c(?)            [IN/OUT]        String list for the data of the field
 *  b(?)            [IN]            Item index for the inline editor
 * RETURNS
 *  Return TRUE if non-empty field.
 *****************************************************************************/
static pBOOL mmi_phb_op_view_fill_extra_item(
                U8 field_index,
                U8 item_index,
                S8 **entry_list,
                U16 *title_list,
                U16 *image_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (field_index)
    {
        case MMI_PHB_FIELD_TITLE:
            *entry_list = (PS8) PhoneBookInfoFields.title;;
            title_list[item_index] = STR_ID_PHB_TITLE;
            image_list[item_index] = IMG_ID_PHB_TITLE;
            break;

        case MMI_PHB_FIELD_URL:
            *entry_list = pbUrl;
            title_list[item_index] = STR_ID_PHB_URL;
            image_list[item_index] = IMG_ID_PHB_URL;
            break;

        case MMI_PHB_FIELD_ADDRESS:
            *entry_list = (PS8) PhoneBookInfoFields.address;
            title_list[item_index] = STR_ID_PHB_ADDRESS;
            image_list[item_index] = IMG_ID_PHB_ADDRESS;
            break;

        case MMI_PHB_FIELD_NOTE:
            *entry_list = (PS8) PhoneBookInfoFields.note;
            title_list[item_index] = STR_ID_PHB_NOTE;
            image_list[item_index] = IMG_ID_PHB_NOTE;
            break;
    }
    if (*entry_list && mmi_ucs2strlen(*entry_list) > 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_fill_inline_extra_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  field_index     [IN]            
 *  string_list     [?]             
 *  image_list      [?]             
 *  a(?)            [IN]            Field index
 *  c(?)            [IN/OUT]        Image list
 *  b(?)            [IN/OUT]        String list
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_phb_op_fill_inline_extra_item(U8 field_index, U16 *string_list, U16 *image_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInlineItemActivation(&wgui_inline_items[field_index], KEY_LSK, KEY_EVENT_UP);
    switch (field_index)
    {
      /*--- Title Field ---*/
        case MMI_PHB_FIELD_TITLE:
            SetInlineItemFullScreenEdit(
                &wgui_inline_items[field_index],
                STR_ID_PHB_TITLE,
                IMG_SCR_PBOOK_CAPTION,
                (PU8) pbTitle,
                MAX_PB_TITLE_LENGTH + 1,
                INPUT_TYPE_ALPHANUMERIC_UPPERCASE);
            string_list[field_index] = STR_ID_PHB_TITLE;
            image_list[field_index] = IMG_ID_PHB_TITLE;
            break;

      /*--- URL Field ---*/
        case MMI_PHB_FIELD_URL:
            SetInlineItemFullScreenEdit(
                &wgui_inline_items[field_index],
                STR_ID_PHB_URL,
                IMG_SCR_PBOOK_CAPTION,
                (PU8) pbUrl,
                MAX_PB_URL_LENGTH + 1,
                INPUT_TYPE_ALPHANUMERIC_LOWERCASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_OVERRIDE_DEFAULT);
            string_list[field_index] = STR_ID_PHB_URL;
            image_list[field_index] = IMG_ID_PHB_URL;
            break;

      /*--- Address Field ---*/
        case MMI_PHB_FIELD_ADDRESS:
            SetInlineItemFullScreenEdit(
                &wgui_inline_items[field_index],
                STR_ID_PHB_ADDRESS,
                IMG_SCR_PBOOK_CAPTION,
                (PU8) pbAddress,
                MAX_PB_ADDRESS_LENGTH + 1,
                INPUT_TYPE_ALPHANUMERIC_UPPERCASE);
            string_list[field_index] = STR_ID_PHB_ADDRESS;
            image_list[field_index] = IMG_ID_PHB_ADDRESS;
            break;

      /*--- Note Field ---*/
        case MMI_PHB_FIELD_NOTE:
            SetInlineItemFullScreenEdit(
                &wgui_inline_items[field_index],
                STR_ID_PHB_NOTE,
                IMG_SCR_PBOOK_CAPTION,
                (PU8) pbNote,
                MAX_PB_NOTE_LENGTH + 1,
                INPUT_TYPE_ALPHANUMERIC_UPPERCASE);
            string_list[field_index] = STR_ID_PHB_NOTE;
            image_list[field_index] = IMG_ID_PHB_NOTE;
            break;
    }
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[field_index], mmi_phb_set_full_scr_lsk);
    #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
        SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[field_index], string_list[field_index]);
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_op_edit_detail_save
 * DESCRIPTION
 *  Save the extra field of the entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_op_edit_detail_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_entry_op_edit_detail_save.>\n", __FILE__,
                         __LINE__);

    store_index = g_phb_name_index[g_phb_cntx.active_index];

    /* Save info field */
    mmi_phb_info_update_field(store_index);
    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, TRUE, PHB_NOTIFY_TIMEOUT, SUCCESS_TONE);
    if (DeleteNScrId(SCR_PBOOK_ENTRY_OPTIONS));         /* Enter From Edit Option */
    // else DeleteNScrId(SCR_ID_PHB_FMGR_SAVE_OPTION);  /*Enter From Save image from file manager*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_op_edit_detail_save_confirm
 * DESCRIPTION
 *  Confirms before saving the entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_op_edit_detail_save_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_GLOBAL_SAVE_ASK),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_phb_entry_op_edit_detail_save, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_phb_go_back_2_history, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_edit_detail_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for inline edit screen
 *  
 *  Mainly to set the LSK of image list to "View"
 *  and stopping the Ringtone & LED pattern
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_edit_detail_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeTitleString((PU8) GetString(TitleStrings[index]));
    draw_title();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_op_edit_detail
 * DESCRIPTION
 *  Inline edit screen to edit an entry detail
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_op_edit_detail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;
    U8 field_index;
    U16 DetailPbNameImageList[MMI_PHB_EXTRA_FIELD_TOTAL];
    U16 store_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_entry_op_edit_detail.>\n", __FILE__,
                         __LINE__);

    store_index = g_phb_name_index[g_phb_cntx.active_index];

    EntryNewScreen(SCR_ID_PHB_EDIT_DETAIL, mmi_phb_exit_op_edit_detail, NULL, NULL);
    InitializeCategory57Screen();
    guiBuffer = GetCurrGuiBuffer(SCR_ID_PHB_EDIT_DETAIL);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_PHB_EDIT_DETAIL, &inputBufferSize);

    RegisterHighlightHandler(mmi_phb_op_edit_detail_highlight_hdlr);

#ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
    EnableInlineItemDefaultText();
#endif

    if (store_index >= MAX_PB_PHONE_ENTRIES)    /* Record store in SIM, SIM index is begin from "MAX_PB_PHONE_ENTRIES" */
    {
        ASSERT(0);
    }
    if (guiBuffer == NULL)
    {
        mmi_phb_info_read_data_to_buff(store_index);
    }

    /* Fill inline item for each field */
    for (field_index = 0; field_index < MMI_PHB_EXTRA_FIELD_TOTAL; field_index++)
    {
        mmi_phb_op_fill_inline_extra_item(field_index, TitleStrings, DetailPbNameImageList);
    }

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, MMI_PHB_FIELD_TOTAL, inputBuffer);
        mmi_phb_op_reconfig_inline_item(guiBuffer);
    }

    ShowCategory57Screen(
        STR_SCR_INLINE_EDIT_CAPTION,
        IMG_STORAGE_HANDSET,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MMI_PHB_EXTRA_FIELD_TOTAL,
        DetailPbNameImageList,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_phb_entry_op_edit_detail_save_confirm, GoBackHistory);

    if (g_phb_cntx.set_done_flag)
    {
        g_phb_cntx.set_done_flag = 0;
        set_wgui_inline_list_menu_changed();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_op_edit_detail
 * DESCRIPTION
 *  Exit function for mmi_phb_exit_op_edit_detail.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_exit_op_edit_detail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.end_scr_id = SCR_ID_PHB_EDIT_DETAIL;
    CloseCategory57Screen();
    h.scrnID = SCR_ID_PHB_EDIT_DETAIL;
    h.entryFuncPtr = mmi_phb_entry_op_edit_detail;
    GetCategoryHistory(h.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, inputBufferSize);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_edit_detail_pre_entry
 * DESCRIPTION
 *  Pre Entry function for phonebook edit detail.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_edit_detail_pre_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_util_clear_info_buffer();
    g_phb_cntx.set_done_flag = 0;
    mmi_phb_entry_op_edit_detail();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_op_edit_detail
 * DESCRIPTION
 *  Highlight handler for "Edit Detail" in Entry options menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_highlight_op_edit_detail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_phb_op_edit_detail_pre_entry, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_phb_op_edit_detail_pre_entry, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}
#endif /* defined(__MMI_PHB_INFO_FIELD__) */ 


#if defined(__MMI_PHB_IMPS_FIELD__) || defined(__MMI_PHB_POC_FIELD__) || defined(__MMI_VOIP__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_util_clear_service_buffer
 * DESCRIPTION
 *  Clears extra buffers used for editing entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_util_clear_service_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_PHB_IMPS_FIELD__)
    memset(pbImps, 0, ENCODING_LENGTH);
#endif 
#if defined(__MMI_VOIP__)
    memset(pbVoip, 0, ENCODING_LENGTH);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_service_read_data_to_buff
 * DESCRIPTION
 *  
 * PARAMETERS
 *  store_index     [IN]        
 *  a(?)            [IN]        Stored index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_service_read_data_to_buff(U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_PHB_IMPS_FIELD__)
    ReadRecord(
        NVRAM_EF_PHB_IMPS_LID,
        (U16) (store_index + 1),
        (void*)&PhoneBookImpsField,
        MAX_PB_IMPS_LENGTH + 1,
        &pError);
    mmi_asc_to_ucs2(pbImps, (PS8) PhoneBookImpsField);
#endif /* defined(__MMI_PHB_IMPS_FIELD__) */ 
#if defined(__MMI_VOIP__)
    ReadRecord(
        NVRAM_EF_PHB_VOIP_LID,
        (U16) (store_index + 1),
        (void*)&PhoneBookVoipField,
        VOIP_URI_LEN,
        &pError);
    mmi_asc_to_ucs2(pbVoip, (PS8) PhoneBookVoipField);
#endif /* defined(__MMI_VOIP__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_service_delete_field
 * DESCRIPTION
 *  Delete information fields of a Phone entry on NVRAM
 * PARAMETERS
 *  store_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_service_delete_field(U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_PHB_IMPS_FIELD__)
    /* Delete IMPS field. */
    memset(&PhoneBookImpsField, 0, MAX_PB_IMPS_LENGTH + 1);
    WriteRecord(
        NVRAM_EF_PHB_IMPS_LID,
        (U16) (store_index + 1),
        (void*)&PhoneBookImpsField,
        MAX_PB_IMPS_LENGTH + 1,
        &pError);
#endif /* defined(__MMI_PHB_IMPS_FIELD__) */ 
#if defined(__MMI_VOIP__)
    /* Delete VOIP field. */
    memset(&PhoneBookVoipField, 0, VOIP_URI_LEN);
    WriteRecord(
        NVRAM_EF_PHB_VOIP_LID,
        (U16) (store_index + 1),
        (void*)&PhoneBookVoipField,
        VOIP_URI_LEN,
        &pError);
#endif /* defined(__MMI_VOIP__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_service_update_field
 * DESCRIPTION
 *  Saves service fields of a Phone entry on NVRAM
 * PARAMETERS
 *  store_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_service_update_field(U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_PHB_IMPS_FIELD__)
    /* Update IMPS fields. */
    mmi_ucs2_to_asc((PS8) PhoneBookImpsField, pbImps);
    WriteRecord(
        NVRAM_EF_PHB_IMPS_LID,
        (U16) (store_index + 1),
        (void*)&PhoneBookImpsField,
        MAX_PB_IMPS_LENGTH + 1,
        &pError);
#endif /* defined(__MMI_PHB_IMPS_FIELD__) */ 
#if defined(__MMI_VOIP__)
    /* Update VOIP fields. */
    mmi_ucs2_to_asc((PS8) PhoneBookVoipField, pbVoip);
    WriteRecord(
        NVRAM_EF_PHB_VOIP_LID,
        (U16) (store_index + 1),
        (void*)&PhoneBookVoipField,
        VOIP_URI_LEN,
        &pError);
#endif /* defined(__MMI_VOIP__) */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_view_fill_service_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  field_index     [IN]            
 *  item_index      [IN]            
 *  entry_list      [IN]            
 *  title_list      [?]             
 *  image_list      [?]             
 * RETURNS
 *  Return TRUE if non-empty field.
 *****************************************************************************/
static pBOOL mmi_phb_op_view_fill_service_item(
                U8 field_index,
                U8 item_index,
                S8 **entry_list,
                U16 *title_list,
                U16 *image_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (field_index)
    {
    #if defined(__MMI_PHB_IMPS_FIELD__)
        case MMI_PHB_FIELD_IMPS:
            *entry_list = (PS8) pbImps;
            title_list[item_index] = STR_ID_PHB_IMPS_ID;
            image_list[item_index] = IMG_ID_PHB_IMPS;
            phb_imps_item_index = item_index;
            break;
    #endif /* defined(__MMI_PHB_IMPS_FIELD__) */ 
    #if defined(__MMI_VOIP__)
        case MMI_PHB_FIELD_VOIP:
            *entry_list = (PS8) pbVoip;
            title_list[item_index] = STR_ID_PHB_VOIP_ID;
            image_list[item_index] = IMG_ID_PHB_VOIP;
            break;
    #endif /* defined(__MMI_VOIP__) */ 
    }
    if (*entry_list && mmi_ucs2strlen(*entry_list) > 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_fill_inline_service_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  field_index     [IN]            
 *  string_list     [IN/OUT]             
 *  image_list      [IN/OUT]             
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_phb_op_fill_inline_service_item(U8 field_index, U16 *string_list, U16 *image_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInlineItemActivation(&wgui_inline_items[field_index], KEY_LSK, KEY_EVENT_UP);
    switch (field_index)
    {
    #if defined(__MMI_PHB_IMPS_FIELD__)
        case MMI_PHB_FIELD_IMPS:
            SetInlineItemFullScreenEdit(
                &wgui_inline_items[field_index],
                STR_ID_PHB_IMPS_ID,
                IMG_SCR_PBOOK_CAPTION,
                (PU8) pbImps,
                MAX_PB_IMPS_LENGTH + 1,
                INPUT_TYPE_ALPHANUMERIC_LOWERCASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_OVERRIDE_DEFAULT);
            string_list[field_index] = STR_ID_PHB_IMPS_ID;
            image_list[field_index] = IMG_ID_PHB_IMPS;
            break;
    #endif /* defined(__MMI_PHB_IMPS_FIELD__) */ 
    #if defined(__MMI_VOIP__)
        case MMI_PHB_FIELD_VOIP:
            SetInlineItemFullScreenEdit_ext(
                &wgui_inline_items[field_index],
                STR_ID_PHB_VOIP_ID,
                IMG_SCR_PBOOK_CAPTION,
                (PU8) pbVoip,
                VOIP_URI_LEN, /* already has 1 byte NULL terminate */
                INPUT_TYPE_ALPHANUMERIC_LOWERCASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_OVERRIDE_DEFAULT,
                INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
            string_list[field_index] = STR_ID_PHB_VOIP_ID;
            image_list[field_index] = IMG_ID_PHB_VOIP;
            break;
    #endif /* defined(__MMI_VOIP__) */ 
    }
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[field_index], mmi_phb_set_full_scr_lsk);
    #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[field_index], string_list[field_index]);
    #endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_op_edit_service_field_save
 * DESCRIPTION
 *  Save the extra field of the entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_op_edit_service_field_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_entry_op_edit_detail_save.>\n", __FILE__,
                         __LINE__);

    store_index = g_phb_name_index[g_phb_cntx.active_index];

    /* Save service field */
    mmi_phb_service_update_field(store_index);
    DisplayPopup((PU8) GetString(STR_GLOBAL_SAVED), IMG_GLOBAL_ACTIVATED, TRUE, PHB_NOTIFY_TIMEOUT, SUCCESS_TONE);
    if (DeleteNScrId(SCR_PBOOK_ENTRY_OPTIONS));         /* Enter From Edit Option */
    // else DeleteNScrId(SCR_ID_PHB_FMGR_SAVE_OPTION);  /*Enter From Save image from file manager*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_op_edit_service_field_save_confirm
 * DESCRIPTION
 *  Confirms before saving the entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_op_edit_service_field_save_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_GLOBAL_SAVE_ASK),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_phb_entry_op_edit_service_field_save, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_phb_go_back_2_history, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_edit_service_field_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for inline edit screen
 *  
 *  Mainly to set the LSK of image list to "View"
 *  and stopping the Ringtone & LED pattern
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_edit_service_field_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeTitleString((PU8) GetString(TitleStrings[index]));
    draw_title();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_op_edit_service_field
 * DESCRIPTION
 *  Inline edit screen to edit an entry detail
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_op_edit_service_field(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;

    /* U8 field_index, item_index = 0 ; */
    U8 field_index;
    U16 DetailPbNameImageList[MMI_PHB_SERVICE_FIELD_TOTAL];
    U16 store_index;

    //U16 image_id;
    //PHB_OPTIONAL_IDS_STRUCT* opt_ids = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_entry_op_edit_detail.>\n", __FILE__,
                         __LINE__);

    store_index = g_phb_name_index[g_phb_cntx.active_index];

    EntryNewScreen(SCR_ID_PHB_EDIT_SERVICE_FIELD, mmi_phb_exit_op_edit_service_field, NULL, NULL);
    InitializeCategory57Screen();
    guiBuffer = GetCurrGuiBuffer(SCR_ID_PHB_EDIT_SERVICE_FIELD);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_PHB_EDIT_SERVICE_FIELD, &inputBufferSize);

    RegisterHighlightHandler(mmi_phb_op_edit_service_field_highlight_hdlr);

#ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
    EnableInlineItemDefaultText();
#endif 

    if (store_index >= MAX_PB_PHONE_ENTRIES)    /* Record store in SIM, SIM index is begin from "MAX_PB_PHONE_ENTRIES" */
    {
        ASSERT(0);
    }
    mmi_phb_service_read_data_to_buff(store_index);

    /* Fill inline item for each field */
    for (field_index = 0; field_index < MMI_PHB_SERVICE_FIELD_TOTAL; field_index++)
    {
        mmi_phb_op_fill_inline_service_item(field_index, TitleStrings, DetailPbNameImageList);
    }

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, MMI_PHB_FIELD_TOTAL, inputBuffer);
        mmi_phb_op_reconfig_inline_item(guiBuffer);
    }

    ShowCategory57Screen(
        STR_SCR_INLINE_EDIT_CAPTION,
        IMG_STORAGE_HANDSET,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MMI_PHB_SERVICE_FIELD_TOTAL,
        DetailPbNameImageList,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_phb_entry_op_edit_service_field_save_confirm, GoBackHistory);

    if (g_phb_cntx.set_done_flag)
    {
        g_phb_cntx.set_done_flag = 0;
        set_wgui_inline_list_menu_changed();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_op_edit_service_field
 * DESCRIPTION
 *  Exit function for mmi_phb_exit_op_edit_service_field.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_exit_op_edit_service_field(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.end_scr_id = SCR_ID_PHB_EDIT_SERVICE_FIELD;
    CloseCategory57Screen();
    h.scrnID = SCR_ID_PHB_EDIT_SERVICE_FIELD;
    h.entryFuncPtr = mmi_phb_entry_op_edit_service_field;
    GetCategoryHistory(h.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, inputBufferSize);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_edit_service_field_pre_entry
 * DESCRIPTION
 *  Pre Entry function for phonebook edit detail.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_edit_service_field_pre_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_util_clear_service_buffer();
    g_phb_cntx.set_done_flag = 0;
    mmi_phb_entry_op_edit_service_field();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_op_edit_service_field
 * DESCRIPTION
 *  Highlight handler for "Edit Detail" in Entry options menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_highlight_op_edit_service_field(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_phb_op_edit_service_field_pre_entry, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_phb_op_edit_service_field_pre_entry, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}
#endif /* defined(__MMI_PHB_IMPS_FIELD__) || defined(__MMI_PHB_POC_FIELD__) || defined(__MMI_VOIP__) */ 


#if defined(__MMI_PHB_IMPS_FIELD__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_imps_send_message
 * DESCRIPTION
 *  Highlight handler for IMPS field in View options menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_imps_send_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (isInCall()) /* Can not send imps during call. */
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_PHB_CANT_VIEW_VIDEO_IN_CALL),
            IMG_GLOBAL_WARNING,
            FALSE,
            PHB_NOTIFY_TIMEOUT,
            WARNING_TONE);
    }
    else
    {
        DisplayPopup((U8*) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, FALSE, PHB_NOTIFY_TIMEOUT, ERROR_TONE);
    }

}
#endif /* defined(__MMI_PHB_IMPS_FIELD__) */ 


#ifdef __MMI_VOIP__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_free_history_data_dummy
 * DESCRIPTION
 *  dummy function for free history data
 * PARAMETERS
 *  param1    [IN]    dummy parameter
 * RETURNS
 *  void
 *****************************************************************************/
static void* mmi_phb_allocate_history_data_dummy(U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (void*)phb_add_entry_history_data;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_free_history_data_dummy
 * DESCRIPTION
 *  dummy function for free history data
 * PARAMETERS
 *  param1    [IN]    dummy parameter
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_free_history_data_dummy(void* param1)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}
#endif /* __MMI_VOIP__ */


#if defined(__MMI_BPP_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_op_print
 * DESCRIPTION
 *  Highlight function of entry option -> prints
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_op_print(void)
{
#if defined(MMI_ON_HARDWARE_P)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_phb_bpp_print, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_bpp_print, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#else /* defined(MMI_ON_HARDWARE_P) */ 
    SetLeftSoftkeyFunction(PopupNoSupport, KEY_EVENT_UP);
    SetKeyHandler(PopupNoSupport, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#endif /* defined(MMI_ON_HARDWARE_P) */ 

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_bpp_print
 * DESCRIPTION
 *  Entry Option -> Print handler function
 * PARAMETERS
 *  path        [IN]        Destination path
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_bpp_print(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    if (mmi_bt_bpp_app_is_printing() == MMI_BPP_PRINT_STATUS_BUSY)
    {
        mmi_bt_bpp_busy_popup();   
    }
    else
    {
        mmi_bt_bpp_app_print(MMI_BPP_APP_PHB, mmi_phb_bpp_prepare_field);    
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_bpp_prepare_field
 * DESCRIPTION
 *  write select phonebook entry into vcard format into destination file.
 * PARAMETERS
 *  path        [IN]        Destination path
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_bpp_prepare_field(mmi_bpp_xhtml_rsp_enum rsp_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index;
#if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)    
    S16 pError;
#endif
    PHB_OPTIONAL_IDS_STRUCT *opt_ids;
    S8* img_temp_path;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp_code != MMI_BPP_XHTML_RSP_DONE)
    {       
        return;
    }
    store_index = g_phb_name_index[g_phb_cntx.active_index];
    mmi_phb_util_clear_buffer(TRUE);
    memset(g_phb_file_path, 0, (FMGR_MAX_PATH_LEN * ENCODING_LENGTH + ENCODING_LENGTH)); 
    
    mmi_ucs2cpy(pbName, (PS8) PhoneBook[store_index].alpha_id.name);
    mmi_phb_convert_get_ucs2_number(pbNumber, store_index);

    if (store_index < MAX_PB_PHONE_ENTRIES) /* In NVRAM */
    {
    #if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
        ReadRecord(
            NVRAM_EF_PHB_FIELDS_LID,
            (U16) (store_index + 1),
            (void*)&PhoneBookOptionalFields,
            OPTIONAL_FIELDS_RECORD_SIZE,
            &pError);
        mmi_asc_to_ucs2(pbHomeNumber, (PS8) PhoneBookOptionalFields.homeNumber);
        mmi_ucs2cpy(pbCompanyName, (PS8) PhoneBookOptionalFields.companyName);
        mmi_asc_to_ucs2(pbEmailAddress, (PS8) PhoneBookOptionalFields.emailAddress);
        mmi_asc_to_ucs2(pbOfficeNumber, (PS8) PhoneBookOptionalFields.officeNumber);
        mmi_asc_to_ucs2(pbFaxNumber, (PS8) PhoneBookOptionalFields.faxNumber);
    #endif /* !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */

    #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
        mmi_phb_bday_read_data_to_buff(store_index);
        mmi_phb_bday_editor_callback((U8*)pbBday, (U8*)pbDay, (U8*)pbMon, (U8*)pbYear);
    #endif

    #if defined(__MMI_PHB_INFO_FIELD__)
        mmi_phb_info_read_data_to_buff(store_index);
    #endif

    #if defined(__MMI_PHB_IMPS_FIELD__) || defined(__MMI_PHB_POC_FIELD__) || defined(__MMI_VOIP__)
        mmi_phb_service_read_data_to_buff(store_index);
    #endif
    #if defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__)
        /* get call pic */
        mmi_phb_read_optional_ids(store_index); /* i is store index */
        opt_ids = (PHB_OPTIONAL_IDS_STRUCT*) g_phb_cntx.optional_ids;
        if ((opt_ids->pictureTagID == 1)
    #ifdef __MMI_AVATAR__
            || (opt_ids->pictureTagID == 2)
    #endif
            )    
        {
            img_temp_path = mmi_phb_image_get_path_from_id((U16) (store_index + 1));
			mmi_ucs2cpy(g_phb_file_path, img_temp_path);
        }
    #endif /* defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__) */
    }
    /* start to compose xhtml file */
    mmi_phb_bpp_xhtml_table_constructor();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_bpp_xhtml_table_constructor
 * DESCRIPTION
 *  phone_book_xhtml_table_constructer
 * PARAMETERS
 *  path        [IN]        Destination path
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_bpp_xhtml_table_constructor(void)
{
    mmi_bpp_xhtml_rsp_enum              rsp;
    mmi_bpp_xhtml_table_css_struct*     tab_css;
    mmi_bpp_xhtml_style_class_struct*   cell_css;
    mmi_bpp_xhtml_data_element_struct*  data;    
    S8 cell_1_css_name[] = "title";
    S8 cell_2_css_name[] = "value";
    U8 phb_caption[] = "PhoneBook";
    U8 photo_title[] = "Photo";

    S32 image_width = 0, image_height = 0;
    U16 image_type;
    U8 image_resource = 0; /* 0: image resource, 1: image file */

    /* config table css */
    tab_css = (mmi_bpp_xhtml_table_css_struct*)get_ctrl_buffer(sizeof(mmi_bpp_xhtml_table_css_struct));
    
    /* the attributes should be set as 0 if not used */
    memset(tab_css, 0, sizeof(mmi_bpp_xhtml_table_css_struct));
    /* set css */
    tab_css->caption_side = MMI_BPP_XHTML_ALIGN_TOP;
    tab_css->text_align = MMI_BPP_XHTML_ALIGN_CENTER;
    tab_css->text_color = MMI_BPP_XHTML_COLOR_BLACK;
    
    rsp = app_config_table_css(tab_css);
    free_ctrl_buffer(tab_css);
    if (rsp != MMI_BPP_XHTML_RSP_DONE)
    {       
        return;
    }
    
    /* config cell_1_css css */
    cell_css = (mmi_bpp_xhtml_style_class_struct*)get_ctrl_buffer(sizeof(mmi_bpp_xhtml_style_class_struct));
    /* the attributes should be set as 0 if not used */
    memset(cell_css, 0, sizeof(mmi_bpp_xhtml_style_class_struct));
    
    /* prepare style class name cell_1_css_name[]*/
    strcpy((S8*)cell_css->class_name, cell_1_css_name);
    
    /* set cell_1_css (common data cell) */
    cell_css->txt_v_align = MMI_BPP_XHTML_ALIGN_MIDDLE;
    cell_css->txt_h_align = MMI_BPP_XHTML_ALIGN_LEFT;   
    cell_css->left_border.border_color = MMI_BPP_XHTML_COLOR_GRAY;
    cell_css->left_border.border_width = 1;  //px
    cell_css->right_border.border_color = MMI_BPP_XHTML_COLOR_GRAY;
    cell_css->right_border.border_width = 1;  //px
    cell_css->top_border.border_color = MMI_BPP_XHTML_COLOR_GRAY;
    cell_css->top_border.border_width = 1;  //px
    cell_css->bottom_border.border_color = MMI_BPP_XHTML_COLOR_GRAY;
    cell_css->bottom_border.border_width = 1;  //px
    cell_css->text_color = MMI_BPP_XHTML_COLOR_BLACK;        
    
    rsp = app_config_style_class(cell_css);
    if (rsp != MMI_BPP_XHTML_RSP_DONE)
    {        
        free_ctrl_buffer(cell_css);
        return;
    }
    
    /* prepare style class name cell_2_css_name[]*/
    strcpy((S8*)cell_css->class_name, cell_2_css_name);
    
    /* set cell_2_css (image data cell)*/
    cell_css->txt_v_align = MMI_BPP_XHTML_ALIGN_BOTTOM;
    cell_css->txt_h_align = MMI_BPP_XHTML_ALIGN_LEFT;   
    cell_css->padding_left = 2; //%
    cell_css->text_color = MMI_BPP_XHTML_COLOR_NONE;
    
    rsp = app_config_style_class(cell_css);
    free_ctrl_buffer(cell_css);
    if (rsp != MMI_BPP_XHTML_RSP_DONE)
    {                
        return;
    }
    
    /* inline image data from file */
    rsp = app_compose_xhtml_file_start();
    if (rsp != MMI_BPP_XHTML_RSP_DONE)
    {       
        return;
    }
    
    /* prepare caption[] */
    rsp = app_compose_xhtml_table_element_start(phb_caption, (kal_uint8) strlen((S8*)phb_caption));    //utf-8(ascii) encoded
    if (rsp != MMI_BPP_XHTML_RSP_DONE)
    {       
        return;
    }

    /* for first row of the image data */    
    rsp = app_compose_xhtml_row_element_start();
    if (rsp != MMI_BPP_XHTML_RSP_DONE)
    {       
        return;
    }
    
    rsp = app_compose_xhtml_data_element_start();
    if (rsp != MMI_BPP_XHTML_RSP_DONE)
    {       
        return;
    }
    
    /* compose function */
    /* compose data element structure */
    data = (mmi_bpp_xhtml_data_element_struct*)get_ctrl_buffer(sizeof(mmi_bpp_xhtml_data_element_struct));
    /* the attributes should be set as 0 if not used */
    memset(data, 0, sizeof(mmi_bpp_xhtml_data_element_struct));
    
    /* set cell 1 attributes */
    sprintf((S8*)data->class_name, cell_1_css_name);
    data->name_len = strlen(cell_1_css_name);            
    
    /* prepare the empty first cell */
    data->data_element = photo_title;
    data->obj_len = strlen((S8*)photo_title);
    data->app_callback = NULL;
    data->type = MMI_BPP_XHTML_TYPE_TXT;
    rsp = app_compose_xhtml_data_element_from_buff(data);
    if (rsp != MMI_BPP_XHTML_RSP_DONE)
    {
        free_ctrl_buffer(data);
        return;
    }
    
	rsp = app_compose_xhtml_data_element_end();
    if (rsp != MMI_BPP_XHTML_RSP_DONE)
    {       
        return;
    }
    
	rsp = app_compose_xhtml_data_element_start();
    if (rsp != MMI_BPP_XHTML_RSP_DONE)
    {       
        return;
    }

    /* set cell 2 attributes */
    sprintf((S8*)data->class_name, cell_2_css_name);
    data->name_len = strlen(cell_2_css_name);            
    
    /* prepare the second image cell */    
    data->app_callback = mmi_phb_bpp_image_file_callback;
    /* prepare the FS_HANDLE open by DRM API */
#if defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__)
    /* Get image from file */
#ifdef __USB_IN_NORMAL_MODE__ 
    if (mmi_usb_is_in_mass_storage_mode())
    {	
        data->data_element = gdi_image_get_buf_ptr_from_id(IMG_ID_PHB_LIST_ICON1);
        data->obj_len = gdi_image_get_buf_len_from_id(IMG_ID_PHB_LIST_ICON1);
        image_type = gdi_image_get_type_from_id(IMG_ID_PHB_LIST_ICON1);
        image_resource = 0;
    }
    else
#endif /* __USB_IN_NORMAL_MODE */
    {
    	if ((g_phb_file_path != NULL) && (gdi_image_get_dimension_file(g_phb_file_path, &image_width, &image_height) >= 0)
            && ((image_type = gdi_image_get_type_from_file(g_phb_file_path)) != GDI_IMAGE_TYPE_M3D_FILE))
        {
            data->file_element = FS_Open((U16*)g_phb_file_path, FS_READ_ONLY);
            FS_GetFileSize(data->file_element, &data->obj_len);
            image_resource = 1;
        }
        else
        {
            data->data_element = gdi_image_get_buf_ptr_from_id(IMG_ID_PHB_LIST_ICON1);
            data->obj_len = gdi_image_get_buf_len_from_id(IMG_ID_PHB_LIST_ICON1);
            image_type = gdi_image_get_type_from_id(IMG_ID_PHB_LIST_ICON1);
            image_resource = 0;
		}
    }
#else /* defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__) */
    data->data_element = gdi_image_get_buf_ptr_from_id(IMG_ID_PHB_LIST_ICON1);
    data->obj_len = gdi_image_get_buf_len_from_id(IMG_ID_PHB_LIST_ICON1);
    image_type = gdi_image_get_type_from_id(IMG_ID_PHB_LIST_ICON1);
    image_resource = 0;
#endif /* defined(__MMI_FILE_MANAGER__) && !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__) */

    switch(image_type)
    {
        case GDI_IMAGE_TYPE_JPG_FILE:
        case GDI_IMAGE_TYPE_JPG:
            data->type = MMI_BPP_XHTML_TYPE_JPG;
            break;
        case GDI_IMAGE_TYPE_GIF_FILE:
            data->type = MMI_BPP_XHTML_TYPE_GIF;
            break;
        case GDI_IMAGE_TYPE_BMP_FILE:
            data->type = MMI_BPP_XHTML_TYPE_BMP;
            break;
        case GDI_IMAGE_TYPE_PNG_FILE:
            data->type = MMI_BPP_XHTML_TYPE_PNG;
            break;            
    }

    /* set the image_height and image_width in a paper */
    data->img_box = 10;
    if (image_resource == 0)
    {
        rsp = app_compose_xhtml_data_element_from_buff(data);        
    }
    else
    {
        rsp = app_compose_xhtml_data_element_from_file(data);
    }
    free_ctrl_buffer(data);    
    switch (rsp)
    {
        case MMI_BPP_XHTML_RSP_WRITING:
            return;
        case MMI_BPP_XHTML_RSP_DONE:
            mmi_phb_bpp_image_file_callback(rsp);
            return;
        default:
            return;
    }
}    


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_bpp_image_file_callback
 * DESCRIPTION
 *  print phb_image_file_callback
 * PARAMETERS
 *  path        [IN]        Destination path
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_bpp_image_file_callback(mmi_bpp_xhtml_rsp_enum rsp_code)
{
    mmi_bpp_xhtml_rsp_enum              rsp;    

    if (rsp_code != MMI_BPP_XHTML_RSP_DONE)
    {
        return;
    }
    
    rsp = app_compose_xhtml_data_element_end();
    if (rsp != MMI_BPP_XHTML_RSP_DONE)
    {       
        return;
    }    
    
    rsp = app_compose_xhtml_row_element_end();
    if (rsp != MMI_BPP_XHTML_RSP_DONE)
    {       
        return;
    }

    rsp = mmi_phb_bpp_compose_attrs();
    if (rsp != MMI_BPP_XHTML_RSP_DONE)
    {       
        return;
    }
    
    rsp = app_compose_xhtml_table_element_end();
    if (rsp != MMI_BPP_XHTML_RSP_DONE)
    {       
        return;
    }        
    rsp = app_compose_xhtml_file_end();       
    return;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_bpp_compose_attrs
 * DESCRIPTION
 *   phb_compose_attrs
 * PARAMETERS
 *  path        [IN]        Destination path
 * RETURNS
 *  void
 *****************************************************************************/
mmi_bpp_xhtml_rsp_enum mmi_phb_bpp_compose_attrs(void)
{
    U8 i = 0;
    S8 value_buffer[PHB_BPP_FIELD_VALUE_BUFFER_LENGTH];
    S8 title_buffer[PHB_BPP_FIELD_TITLE_BUFFER_LENGTH];
    mmi_bpp_xhtml_rsp_enum rsp = MMI_BPP_XHTML_RSP_DONE;
    mmi_bpp_xhtml_data_element_struct* data;    
    
    for (i = 0; i < MMI_PHB_BPP_FIELD_TOTAL; i++)
    {
        memset(title_buffer, 0, PHB_BPP_FIELD_TITLE_BUFFER_LENGTH);
        memset(value_buffer, 0, PHB_BPP_FIELD_VALUE_BUFFER_LENGTH);
        switch (i)
        {
            case MMI_PHB_BPP_N:
                if (GetUCS2Flag(pbName))
                {
                    mmi_chset_convert(MMI_CHSET_UCS2, MMI_CHSET_UTF8, (char*)pbName, (char*)value_buffer, PHB_BPP_FIELD_VALUE_BUFFER_LENGTH);
                }
                else
                {
                    mmi_ucs2_to_asc(value_buffer, pbName);
                }
                break;              
            case MMI_PHB_BPP_TEL_CELL:
                mmi_ucs2_to_asc(value_buffer, pbNumber);
                break;
        #if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)                
            case MMI_PHB_BPP_TEL_HOME:
                mmi_ucs2_to_asc(value_buffer, pbHomeNumber);
                break;            
            case MMI_PHB_BPP_TEL_WORK:
                mmi_ucs2_to_asc(value_buffer, pbOfficeNumber);
                break;            
            case MMI_PHB_BPP_TEL_FAX:
                mmi_ucs2_to_asc(value_buffer, pbFaxNumber);
                break;            
            case MMI_PHB_BPP_EMAIL:
                mmi_ucs2_to_asc(value_buffer, pbEmailAddress);
                break;            
            case MMI_PHB_BPP_ORG:
                if (GetUCS2Flag(pbCompanyName))
                {
                    mmi_chset_convert(MMI_CHSET_UCS2, MMI_CHSET_UTF8, (char*)pbCompanyName, (char*)value_buffer, PHB_BPP_FIELD_VALUE_BUFFER_LENGTH);
                }
                else
                {
                    mmi_ucs2_to_asc(value_buffer, pbCompanyName);
                }
                break;
        #endif /* !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */  
        #if defined(__MMI_PHB_BIRTHDAY_FIELD__)                      
            case MMI_PHB_BPP_BDAY:
                if (mmi_ucs2cmp(pbBday, (S8*)(PU8)GetString(STR_GLOBAL_NONE)) != 0)
                {
                    mmi_ucs2_to_asc(value_buffer, pbBday);
                }
                break;         
        #endif /* defined(__MMI_PHB_BIRTHDAY_FIELD__) */                
        #if defined(__MMI_PHB_INFO_FIELD__)        
            case MMI_PHB_BPP_TITLE:
                if (GetUCS2Flag(pbTitle))
                {
                    mmi_chset_convert(MMI_CHSET_UCS2, MMI_CHSET_UTF8, (char*)pbTitle, (char*)value_buffer, PHB_BPP_FIELD_VALUE_BUFFER_LENGTH);
                }
                else
                {
                    mmi_ucs2_to_asc(value_buffer, pbTitle);
                }
                break;            
            case MMI_PHB_BPP_URL:
                mmi_ucs2_to_asc(value_buffer, pbUrl);
                break;           
            case MMI_PHB_BPP_NOTE:
                if (GetUCS2Flag(pbNote))
                {
                    mmi_chset_convert(MMI_CHSET_UCS2, MMI_CHSET_UTF8, (char*)pbNote, (char*)value_buffer, PHB_BPP_FIELD_VALUE_BUFFER_LENGTH);
                }
                else
                {
                    mmi_ucs2_to_asc(value_buffer, pbNote);
                }
                break;            
            case MMI_PHB_BPP_ADR:
                if (GetUCS2Flag(pbAddress))
                {
                    mmi_chset_convert(MMI_CHSET_UCS2, MMI_CHSET_UTF8, (char*)pbAddress, (char*)value_buffer, PHB_BPP_FIELD_VALUE_BUFFER_LENGTH);
                }
                else
                {
                    mmi_ucs2_to_asc(value_buffer, pbAddress);
                }           
                break;
        #endif /* defined(__MMI_PHB_INFO_FIELD__) */  
        #if defined(__MMI_VOIP__)                      
            case MMI_PHB_BPP_VOIP:
                mmi_ucs2_to_asc(value_buffer, pbVoip);
                break;
        #endif /* defined(__MMI_VOIP__) */
        #if defined(__MMI_PHB_IMPS_FIELD__)              
            case MMI_PHB_BPP_IMPS:
                mmi_ucs2_to_asc(value_buffer, pbImps);            
                break;
        #endif /* defined(__MMI_PHB_IMPS_FIELD__) */
            default:
                break;
        }

    	if(value_buffer && strlen(value_buffer) != 0)
    	{
    	    strcpy(title_buffer, g_phb_bpp_field[i]);        
            rsp = app_compose_xhtml_row_element_start();
            if (rsp != MMI_BPP_XHTML_RSP_DONE)
            {       
                return rsp;
            }
        
            rsp = app_compose_xhtml_data_element_start();
            if (rsp != MMI_BPP_XHTML_RSP_DONE)
            {       
                return rsp;
            }
     
            /* compose data element structure */
            data = (mmi_bpp_xhtml_data_element_struct*)get_ctrl_buffer(sizeof(mmi_bpp_xhtml_data_element_struct));
            /* the attributes should be set as 0 if not used */
            memset(data, 0, sizeof(mmi_bpp_xhtml_data_element_struct));
        
            /* set cell 1 attributes */
            sprintf((S8*)data->class_name, "title");
            data->name_len = strlen("title");            
        
            /* prepare the data buffer */
            data->data_element = title_buffer;    
            data->obj_len = strlen(title_buffer);
            data->app_callback = NULL;
            data->type = MMI_BPP_XHTML_TYPE_TXT;
            rsp = app_compose_xhtml_data_element_from_buff(data);
            if (rsp != MMI_BPP_XHTML_RSP_DONE)
            {
                free_ctrl_buffer(data);
                return rsp;
            }
        
            rsp = app_compose_xhtml_data_element_end();
            if (rsp != MMI_BPP_XHTML_RSP_DONE)
            {   
                free_ctrl_buffer(data);    
                return rsp;
            }
        
            rsp = app_compose_xhtml_data_element_start();
            if (rsp != MMI_BPP_XHTML_RSP_DONE)
            {   
                free_ctrl_buffer(data);    
                return rsp;
            }
        
            /* prepare the data buffer */
            sprintf((S8*)data->class_name, "value");
            data->name_len = strlen("value");  
            data->data_element = value_buffer;    
            data->obj_len = strlen(value_buffer);                
            rsp = app_compose_xhtml_data_element_from_buff(data);
            free_ctrl_buffer(data);
            if (rsp != MMI_BPP_XHTML_RSP_DONE)
            {        
                return rsp;
            } 
        
            rsp = app_compose_xhtml_data_element_end();
            if (rsp != MMI_BPP_XHTML_RSP_DONE)
            {       
                return rsp;
            }
        
            rsp = app_compose_xhtml_row_element_end();
            if (rsp != MMI_BPP_XHTML_RSP_DONE)
            {       
                return rsp;
            }
        }
    }
    return rsp;
}
#endif /* defined(__MMI_BPP_SUPPORT__) */ 
#endif /* _PHONEBOOKOPERATESINGLE_C */ 

