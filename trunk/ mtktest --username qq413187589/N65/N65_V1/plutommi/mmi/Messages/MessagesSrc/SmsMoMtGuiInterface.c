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
 * SmsMoMtGuiInterface.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for MMI SMS APP.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : SmsGuiHandler.c

   PURPOSE     : SMS GUI handlers 

   REMARKS     : nil

   AUTHOR      : Manu Vikram and Magesh k, Hiran.

   DATE     : 01-01-2003

**************************************************************/

#include "MMI_include.h"
#ifdef __MOD_SMSAL__
/*  Include: MMI header file */

/* Manish MMS */
#if (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT))
#include "JMMSMainMMS.h"
#include "JMMSResDef.h"
#endif /* (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT)) */ 
#if (defined (JATAAYU_SUPPORT) && defined(WAP_SUPPORT))
#include "JBrowserResDef.h"
#include "JProvWap.h"
#endif /* (defined (JATAAYU_SUPPORT) && defined(WAP_SUPPORT)) */ 
/* ... Add More MMI header */
#include "CommonScreens.h"
#include "ProtocolEvents.h"

/* ...Add MSG header */
#include "customer_ps_inc.h"
#include "mmi_msg_context.h"
#include "MessagesL4Def.h"
#include "MessagesResourceData.h"
#include "MessagesMiscell.h"
#include "MessagesExDcl.h"
#include "SmsGuiInterfaceProt.h"
#include "SmsGuiInterfaceType.h"
#include "SmsPsHandler.h"
#include "CellBroadcastType.h"
#ifdef __MMI_MESSAGES_CHAT__
#include "ChatAppGprot.h"
#include "ChatAppResDef.h"
#include "ChatGtype.h"
#include "ChatAppGexdcl.h"
#endif /* __MMI_MESSAGES_CHAT__ */ 

#include "Gui_ems.h"
#include "wgui_ems.h"
#include "GSM7BitDefaultAlphabet.h"
#include "SimDetectionGProt.h"
/*  */
#include "smsal_l4c_enum.h"
/*  */
/*  */
#include "CSP.h"
#include "MainMenuDef.h"
#include "CallHistoryGProts.h"
#include "CallManagementGprot.h"
#include "CallhistoryEnum.h"
#include "MiscFunctions.h"
#include "SettingProfile.h"
#include "ProfileGprots.h"
#include "PhoneBookGprot.h"
#include "PhoneBookDef.h"
#include "IdleAppProt.h"
#include "AlarmFrameworkProt.h"

#include "wgui_status_icons.h"
#include "gpioInc.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "conversions.h"

#include "SMSApi.h"
#include "SMSStruct.h"
#include "SMSFunc.h"

#ifdef __MMI_EMAIL__
#include "EmailAppGProt.h"
#include "App_usedetails.h"
#endif 

#ifdef __MMI_IMPS__
#include "mmi_imps_gprot.h"
#endif 

#ifdef __MMI_MMS_2__
#include "MMSAppResDef.h"
#endif

#ifdef WAP_SUPPORT
#include "wap_ps_struct.h"
#endif /* WAP_SUPPORT */

#ifdef __MMI_BROWSER_2__
#include "PushInboxResDef.h"
#endif

#ifdef __MMI_CCA_SUPPORT__
#include "CentralConfigAgentGProt.h"
#endif

#if defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__)
#include "NetworkSetupDefs.h"
#include "VoIPGProt.h"
#endif /* defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__) */

#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_AD_master_header.h"
#include "MTPNP_AD_resdef.h"
#include "MTPNP_PFAL_Master_Msgs.h"
#include "MTPNP_PFAL_MessageSetup.h"
#include "MTPNP_PFAL_resource.h"
#include "MTPNP_PFAL_dualprof.h"
#include "MTPNP_PFAL_CC.h"
#endif /* __MMI_DUAL_SIM_MASTER__ */

#if defined(__MMI_SMART_MESSAGE_MT__) || (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) || defined(__MMI_MYPICTURE__)
#include "wgui_tab_bars.h"
#include "PicMsgApiToOthers.h"
#include "FileManagerDef.h"
#include "FileMgr.h"
#include "MyTone.h"
#include "FileManagerGProt.h"

#include "MyPicture.h"
#include "SMRTRingToneConverter.h"
#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_PFAL_CC.h"
#endif/*__MMI_DUAL_SIM_MASTER__*/


S8 RingtoneNameBuffer[NSM_FILE_NAME_BUFF];
S8 PictureNameBuffer[NSM_FILE_NAME_BUFF];
U8 *gPictureDataBuffer = NULL;
U16 gSelected_Item = 0;
U16 gConvertFlag = FALSE;
U8 gPictureMessageError = 0;
U8 TextBuffer[(MAX_PICMSG_DEFAULT_DCS_TEXT_LEN * ENCODING_LENGTH) + (10 * ENCODING_LENGTH)];
extern U8 gaddtext_buffer[];

#if defined(__MMI_MYPICTURE__)
extern U8 gfilecount;
#endif 

extern U8 gNSMBuffer[1024];
extern S8 g_pmsg_TextInMessage[];

U8 *pnsmMessageAsciibuff = NULL;
U16 RemoveZerosInBetween(U8 *pOutBuffer, U8 *pInBuffer, U16 size);

#if defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)
nsm_msg_struct g_nsm_msg_context;

U16 ManufacturerSYSPictureStrIDs[] =    /* ManufacturerPicture Str IDs */
{
    STR_ID_NSM2_PIC1,
    STR_ID_NSM2_PIC2,
    STR_ID_NSM2_PIC3,
    STR_ID_NSM2_PIC4,
    STR_ID_NSM2_PIC5,
    STR_ID_NSM2_PIC6,
    STR_ID_NSM2_PIC7,
    STR_ID_NSM2_PIC8,
    STR_ID_NSM2_PIC9,
    STR_ID_NSM2_PIC10
};

U16 ManufacturerSYSPictureImageIDs[] = 
{
    IMG_NSM01_PIC,
    IMG_NSM02_PIC,
    IMG_NSM03_PIC,
    IMG_NSM04_PIC,
    IMG_NSM05_PIC,
    IMG_NSM06_PIC,
    IMG_NSM07_PIC,
    IMG_NSM08_PIC,
    IMG_NSM09_PIC,
    IMG_NSM010_PIC
};

#define NSM_MANUFACTURER_PICTURE_NUM 10
U8 static currMaxSYSObjectList = 0;

#define PREDEFINED_PIC_BUFF_SIZE 404
#endif /* defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__) */ 
#endif /* defined(__MMI_SMART_MESSAGE_MT__) || (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) || defined(__MMI_MYPICTURE__) */ 

#ifdef __MMI_MESSAGES_USE_URL__
#include "WapResDef.h"

#ifdef __MMI_VIDEO_STREAM__
#include "VdoPlyGProt.h"

#define MAX_NUM_VALID_RTSP_PREFIX   3
#define MAX_NUM_URL_PATTERN   4

S8 urlRtsp[10] = {0x72, 0x74, 0x73, 0x70, 0x3a, 0x1b, 0x5c, 0x1b, 0x5c, 0x00};
const PS8 urlValidRtspPrefix[MAX_NUM_VALID_RTSP_PREFIX] = { "rtsp://", "rtsp:\\\\", urlRtsp, };
const PS8 urlPattern[MAX_NUM_URL_PATTERN] = { "http", "www.", "wap.", "rtsp" };
#else /* __MMI_VIDEO_STREAM__ */ 
#define MAX_NUM_URL_PATTERN   3
const PS8 urlPattern[MAX_NUM_URL_PATTERN] = { "http", "www.", "wap." };
#endif /* __MMI_VIDEO_STREAM__ */ 

#define MAX_NUM_VALID_HTTP_PREFIX   6
#define MAX_LEN_URL_PATTERN   15
S8 urlHttp[10] = {0x68, 0x74, 0x74, 0x70, 0x3a, 0x1b, 0x5c, 0x1b, 0x5c, 0x00};
S8 urlHttps[11] = {0x68, 0x74, 0x74, 0x70, 0x73, 0x3a, 0x1b, 0x5c, 0x1b, 0x5c, 0x00};
const PS8 urlValidHttpPrefix[MAX_NUM_VALID_HTTP_PREFIX] =
    { "http://", "http:\\\\", urlHttp, "https://", "https:\\\\", urlHttps};
#endif /* __MMI_MESSAGES_USE_URL__ */ 

#include "wapadp.h"

#if defined(__MMI_SMART_MESSAGE_MT__)
nsm_picmsg_text_struct picmsg_text_struct;
#endif 

#ifdef __MMI_UNIFIED_MESSAGE__
#include "UnifiedMessageResDef.h"
#include "UnifiedMessageGProt.h"
#endif /* __MMI_UNIFIED_MESSAGE__ */

#ifdef __MMI_UNIFIED_COMPOSER__
#include "UnifiedComposerResDef.h"
#include "UnifiedComposerGProt.h"
#endif /* __MMI_UNIFIED_MESSAGE__ */

extern kal_uint16 wap_get_screen_id(void);


/*  */
#define ONE_DIGIT(value)                  ((value) % 10)
extern EMSData *GetEMSDataForView(EMSData **p, U8 force);
extern EMSData *GetEMSDataForEdit(EMSData **p, U8 force);
extern U8 DeInitMessagesEMSBuffer(msg_ems_data_struct *pE);

#ifdef WAP_SUPPORT
extern int wap_entry_select_bookmark(void);
#endif /* WAP_SUPPORT */

//
//////////////////////////////////////////////////////////////////////////////////////
// local variables
//////////////////////////////////////////////////////////////////////////////////////

/********************************************************************

                  variables

********************************************************************/
msg_context_struct g_msg_cntx;

static U16 msg_popup_strID;
static U16 msg_popup_imgID;
static U8 msg_popup_tonID;

static U8 backgroundaudioresume = FALSE;

static U16 msg_confirm_strID = STR_GLOBAL_OK;
static FuncPtr msg_confirm_lskFuncPtr = NULL;
static FuncPtr msg_confirm_rskFuncPtr = NULL;

static FuncPtr msg_common_funcPtr = NULL;

S16 processCaptionStrId;
S16 processBodyStrId;
U16 processAnimationImageId;
U16 processRSKStrId;
static FuncPtr leftKeyFuncPtr = NULL;
static FuncPtr rightKeyFuncPtr = NULL;

static msg_in_out_struct TotalInboxOutboxStatus;

msg_active_profile_struct activeProfile;

msg_msgbox_info_struct msgbox_info;
extern PendingSaveSendDataStruct PendingSaveSendData;

/****************************************************************

            generic functions

****************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_set_msg_icon
 * DESCRIPTION
 *  Set msg icon for unread/full message.
 * PARAMETERS
 *  blink       [IN]        
 *  unblink     [IN]        
 *  a(?)        [IN]        Blink
 *  b(?)        [IN]        Unblink
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_set_msg_icon(U8 blink, U8 unblink)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0;
    U16 totalinbox = mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_INBOX);
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    U16 totalsimbox = mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_SIM);
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*-------[SmsMoMtGuiInterface.c] mmi_msg_set_msg_icon -------*\n");

    if (blink == TRUE)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                             "*-------[SmsMoMtGuiInterface.c] mmi_msg_set_msg_icon blink==TRUE -------*\n");

        HideStatusIcon(STATUS_ICON_INCOMING_SMS);
        HideStatusIcon(STATUS_ICON_SUBLCD_SMS);
        BlinkStatusIcon(STATUS_ICON_INCOMING_SMS);
        BlinkStatusIcon(STATUS_ICON_SUBLCD_SMS);
        UpdateStatusIcons();
        return;
    }
    if (unblink == TRUE)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                             "*-------[SmsMoMtGuiInterface.c] mmi_msg_set_msg_icon unblink==TRUE -------*\n");

        HideStatusIcon(STATUS_ICON_INCOMING_SMS);
        HideStatusIcon(STATUS_ICON_SUBLCD_SMS);
    }
    if (g_msg_cntx.msg_full_ind == FALSE)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                             "*-------[SmsMoMtGuiInterface.c] mmi_msg_set_msg_icon g_msg_cntx.msg_full_ind==FALSE -------*\n");

        if (totalinbox != MMI_FRM_SMS_INVALID_INDEX)
        {

            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                 "*-------[SmsMoMtGuiInterface.c] mmi_msg_set_msg_icon totalinbox: %d -------*\n",
                                 totalinbox);

            while (i < totalinbox)
            {
                if ((mmi_frm_sms_get_status(MMI_FRM_SMS_APP_INBOX, i) & 0x0f) == MMI_FRM_SMS_APP_UNREAD)
                {
                    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                         "*-------[SmsMoMtGuiInterface.c] mmi_msg_set_msg_icon UNREAD found -------*\n");

                    ShowStatusIcon(STATUS_ICON_INCOMING_SMS);
                    ShowStatusIcon(STATUS_ICON_SUBLCD_SMS);
                    UpdateStatusIcons();
                    return;
                }
                i++;
            }
        #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
            i = 0;
            while (i < totalsimbox)
            {
                if ((mmi_frm_sms_get_status(MMI_FRM_SMS_APP_SIM, i) & 0x0f) == MMI_FRM_SMS_APP_UNREAD)
                {
                    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                         "*-------[SmsMoMtGuiInterface.c] mmi_msg_set_msg_icon SIM MESSAGE UNREAD found -------*\n");

                    ShowStatusIcon(STATUS_ICON_INCOMING_SMS);
                    ShowStatusIcon(STATUS_ICON_SUBLCD_SMS);
                    UpdateStatusIcons();
                    return;
                }
                i++;
            }
        #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

        }

        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                             "*-------[SmsMoMtGuiInterface.c] mmi_msg_set_msg_icon NO UNREAD found -------*\n");

        HideStatusIcon(STATUS_ICON_INCOMING_SMS);
        HideStatusIcon(STATUS_ICON_SUBLCD_SMS);
    }
    UpdateStatusIcons();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_set_funcptr
 * DESCRIPTION
 *  Set function pointer for later usage
 * PARAMETERS
 *  funcptr     [IN]        Function pointer for later usage
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_set_funcptr(FuncPtr funcptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_common_funcPtr = funcptr;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_exec_funcptr
 * DESCRIPTION
 *  Execute function pointer set earlier
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_exec_funcptr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_common_funcPtr != NULL)
    {
        (*msg_common_funcPtr) ();
    }
    msg_common_funcPtr = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_set_msg_waiting_icon
 * DESCRIPTION
 *  Set msg icon for waiting vm/email/fax
 * PARAMETERS
 *  line        [IN]        
 *  type        [IN]        
 *  set         [IN]        
 *  a(?)        [IN]        Line
 *  c(?)        [IN]        Set/unset
 *  b(?)        [IN]        Type
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_set_msg_waiting_icon(U8 line, U8 type, U8 set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    U8 otherline = (line == 0 ? 1 : 0);
    U16 icon[] = 
    {
    #ifndef __MMI_DUAL_SIM_MASTER__
        STATUS_ICON_UNREAD_VOICE_L1,
        STATUS_ICON_UNREAD_VOICE_L2,
        STATUS_ICON_UNREAD_VOICE_L1L2,
        STATUS_ICON_UNREAD_FAX_L1,
        STATUS_ICON_UNREAD_FAX_L2,
        STATUS_ICON_UNREAD_FAX_L1L2,
        STATUS_ICON_UNREAD_EMAIL_L1,
        STATUS_ICON_UNREAD_EMAIL_L2,
        STATUS_ICON_UNREAD_EMAIL_L1L2,
	#else /* __MMI_DUAL_SIM_MASTER__ */
        STATUS_ICON_UNREAD_VOICE_L1_MASTER,
        STATUS_ICON_UNREAD_VOICE_L2_MASTER,
        STATUS_ICON_UNREAD_VOICE_L1L2_MASTER,
        STATUS_ICON_UNREAD_FAX_L1_MASTER,
        STATUS_ICON_UNREAD_FAX_L2_MASTER,
        STATUS_ICON_UNREAD_FAX_L1L2_MASTER,
        STATUS_ICON_UNREAD_EMAIL_L1_MASTER,
        STATUS_ICON_UNREAD_EMAIL_L2_MASTER,
        STATUS_ICON_UNREAD_EMAIL_L1L2_MASTER,
        STATUS_ICON_UNREAD_NET_L1_MASTER,
        STATUS_ICON_UNREAD_NET_L2_MASTER,
        STATUS_ICON_UNREAD_NET_L1L2_MASTER,
    #endif /* __MMI_DUAL_SIM_MASTER__ */
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type >= (MAX_WAITING_TYPE_NUM))
    {
        return;
    }
        
    for (i = 0; i < (MAX_WAITING_LINE_NUM + 1); i++)
    {
		IdleResetStatusIcon(icon[(type * (MAX_WAITING_LINE_NUM + 1)) + i]);
	#ifdef __MMI_DUAL_SIM_MASTER__
		MTPNP_PFAL_Reset_SMS_Waiting_Icon(icon[(type * (MAX_WAITING_LINE_NUM + 1)) + i]);
	#endif	
    }
    if ((set > 0) && (g_msg_cntx.msg_waiting_info[otherline].number[type]))
    {
    	if (mmi_frm_sms_is_sms_valid() && mmi_bootup_is_sim_valid())
    	{
        	IdleSetStatusIcon(icon[(type * (MAX_WAITING_LINE_NUM + 1)) + MAX_WAITING_LINE_NUM]);
    	}
	#ifdef __MMI_DUAL_SIM_MASTER__	
		MTPNP_PFAL_Set_SMS_Waiting_Icon(icon[(type * (MAX_WAITING_LINE_NUM + 1)) + MAX_WAITING_LINE_NUM]);
	#endif	
    }
    else if (set > 0)
    {
		if (mmi_frm_sms_is_sms_valid() && mmi_bootup_is_sim_valid())
		{
			IdleSetStatusIcon(icon[(type * (MAX_WAITING_LINE_NUM + 1)) + line]);
		}        
	#ifdef __MMI_DUAL_SIM_MASTER__	
		MTPNP_PFAL_Set_SMS_Waiting_Icon(icon[(type * (MAX_WAITING_LINE_NUM + 1)) + line]);
	#endif	
    }
    else if (g_msg_cntx.msg_waiting_info[otherline].number[type])
    {
		if (mmi_frm_sms_is_sms_valid() && mmi_bootup_is_sim_valid())
		{		
			IdleSetStatusIcon(icon[(type * (MAX_WAITING_LINE_NUM + 1)) + otherline]);
		}
	#ifdef __MMI_DUAL_SIM_MASTER__	
		MTPNP_PFAL_Set_SMS_Waiting_Icon(icon[(type * (MAX_WAITING_LINE_NUM + 1)) + otherline]);
	#endif	
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_exit_generic
 * DESCRIPTION
 *  Exit generic function for MSG app.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_exit_generic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_msg_cntx.MessagesScrnIdDelUptoHistoryNodes = GetMessagesCurrScrnID();
    SetMessagesCurrScrnID(0);   /* messagesCurrScrnID */
    /* MTK Leo add, mini_tab_bar */
#ifdef __MMI_WGUI_MINI_TAB_BAR__
    wgui_disable_mini_tab_bar();
#endif 
    /* MTK Leo end */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_generic
 * DESCRIPTION
 *  Highlight generic function for MSG app
 * PARAMETERS
 *  lskstr      [IN]        
 *  lskimg      [IN]        
 *  rskstr      [IN]        
 *  rskimg      [IN]        
 *  lskfunc     [IN]        
 *  rskfunc     [IN]        
 *  a(?)        [IN]        Left soft key string
 *  d(?)        [IN]        Right soft key image
 *  f(?)        [IN]        Right soft key function
 *  e(?)        [IN]        Left soft key function
 *  c(?)        [IN]        Right soft key string
 *  b(?)        [IN]        Left soft key image
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_generic(U16 lskstr, U16 lskimg, U16 rskstr, U16 rskimg, FuncPtr lskfunc, FuncPtr rskfunc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(lskstr, lskimg);
    ChangeRightSoftkey(rskstr, rskimg);
    SetLeftSoftkeyFunction(lskfunc, KEY_EVENT_UP);
    SetKeyHandler(lskfunc, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(rskfunc, KEY_EVENT_UP);
    SetKeyHandler(rskfunc, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_set_confirm_screen
 * DESCRIPTION
 *  Set string and function for MSG confirmation screen
 * PARAMETERS
 *  id          [IN]        
 *  lskfunc     [IN]        
 *  rskfunc     [IN]        
 *  a(?)        [IN]        String ID
 *  c(?)        [IN]        Right soft key function
 *  b(?)        [IN]        Left soft key function
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_set_confirm_screen(U16 id, FuncPtr lskfunc, FuncPtr rskfunc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_confirm_strID = id;
    msg_confirm_lskFuncPtr = lskfunc;
    msg_confirm_rskFuncPtr = rskfunc;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_confirm_generic
 * DESCRIPTION
 *  Entry MSG generic confirmation screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_confirm_generic(void)
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
        get_string(msg_confirm_strID),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(msg_confirm_lskFuncPtr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(msg_confirm_rskFuncPtr, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_exit_confirm_generic
 * DESCRIPTION
 *  Exit MSG generic confirmation screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_exit_confirm_generic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stopRequestedTone(WARNING_TONE);
    SetMessagesCurrScrnID(0);   /* messagesCurrScrnID */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_set_processing_screen
 * DESCRIPTION
 *  Set string and image for MSG processing screen
 * PARAMETERS
 *  captionStrId            [IN]        
 *  bodyStrId               [IN]        
 *  animationImageId        [IN]        
 *  rskStrId                [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_set_processing_screen(U16 captionStrId, U16 bodyStrId, U16 animationImageId, U16 rskStrId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    processCaptionStrId = captionStrId;
    processBodyStrId = bodyStrId;
    processAnimationImageId = animationImageId;
    processRSKStrId = rskStrId;
    leftKeyFuncPtr = NULL;
    rightKeyFuncPtr = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_set_processing_screen_ext
 * DESCRIPTION
 *  Set string and image and left,right key function for MSG processing screen
 * PARAMETERS
 *  captionStrId            [IN]        
 *  bodyStrId               [IN]        
 *  animationImageId        [IN]        
 *  rskStrId                [IN]
 *  leftKeyFunc             [IN] 
 *  rightKeyFunc            [IN] 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_set_processing_screen_ext(U16 captionStrId, U16 bodyStrId, U16 animationImageId, U16 rskStrId,
                                       FuncPtr leftKeyFunc, FuncPtr rightKeyFunc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    processCaptionStrId = captionStrId;
    processBodyStrId = bodyStrId;
    processAnimationImageId = animationImageId;
    processRSKStrId = rskStrId;
    leftKeyFuncPtr = leftKeyFunc;
    rightKeyFuncPtr = rightKeyFunc;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_end_key_from_processing
 * DESCRIPTION
 *  Reset display list type before go to idle.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_end_key_from_processing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!isInCall())
    {
        g_msg_cntx.toDisplayMessageList = TO_DISPLAY_MESSAGE_LIST_NONE;
    }
    ExecCurrEndKeyDownHandler();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_go_back_from_processing
 * DESCRIPTION
 *  Reset display list type before go back screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_go_back_from_processing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_msg_cntx.toDisplayMessageList = TO_DISPLAY_MESSAGE_LIST_NONE;
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_call_handle_from_processing
 * DESCRIPTION
 *  Reset current screen before enter call screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_call_handle_from_processing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetMessagesCurrScrnID(0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_processing_generic
 * DESCRIPTION
 *  Entry MSG generic processing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_processing_generic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_PROCESSING, mmi_msg_exit_processing_generic, mmi_msg_entry_processing_generic, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_processing_generic *\n");

    SetMessagesCurrScrnID(SCR_ID_MSG_PROCESSING);   /* may be temp func... */
    GetCurrEndKeyDownHandler();
    /* PMT HIMANSHU START 20050920 */
#ifdef __MMI_MAINLCD_240X320__
    /* passing 0xffff for Title string and Title icon for the disbling the status bar and title display. */
    ShowCategory8Screen(0xffff, 0xffff, 0, 0, processRSKStrId, 0, processBodyStrId, processAnimationImageId, NULL);
#else /* __MMI_MAINLCD_240X320__ */ 
    ShowCategory8Screen(
        processCaptionStrId,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        0,
        0,
        processRSKStrId,
        0,
        processBodyStrId,
        processAnimationImageId,
        NULL);
#endif /* __MMI_MAINLCD_240X320__ */ 
    /* PMT HIMANSHU END 20050920 */

    ClearAllKeyHandler();
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_END, KEY_REPEAT);    
    
    if (processRSKStrId == 0)
    {
        StartTimer(MESSAGES_INPROGRESS_TIMER_ID, MESSAGES_INPROGRESS_TIME_OUT, mmi_msg_time_out_processing_generic);
    }

    if (rightKeyFuncPtr != NULL)
    {
        SetKeyHandler(rightKeyFuncPtr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetRightSoftkeyFunction(rightKeyFuncPtr, KEY_EVENT_UP);   
    }
    /* rigth key default handle: go back the pre window */
    else if (processRSKStrId != 0)
    {
        SetKeyHandler(mmi_msg_go_back_from_processing, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetRightSoftkeyFunction(mmi_msg_go_back_from_processing, KEY_EVENT_UP);       
		SetKeyHandler(mmi_msg_end_key_from_processing, KEY_END, KEY_EVENT_DOWN);    
    }
    if (leftKeyFuncPtr != NULL)
    {
        SetLeftSoftkeyFunction(leftKeyFuncPtr, KEY_EVENT_UP);
    }
    
    if (isInCall())
    {
        SetKeyHandler(HangupAllCalls, KEY_END, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_exit_processing_generic
 * DESCRIPTION
 *  Exit MSG generic processing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_exit_processing_generic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_msg_cntx.MessagesScrnIdDelUptoHistoryNodes = GetMessagesCurrScrnID();
    SetMessagesCurrScrnID(0);   /* NOTE!!!!! do not set to zero for incoming call reason */
    StopTimer(MESSAGES_INPROGRESS_TIMER_ID);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_time_out_processing_generic
 * DESCRIPTION
 *  Time out call back of processing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_time_out_processing_generic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(MESSAGES_INPROGRESS_TIMER_ID);
    if (GetMessagesCurrScrnID() == SCR_ID_MSG_PROCESSING)
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
    }
    DeleteMessagesHistoryNodes();
    DeleteScreenIfPresent(SCR_ID_MSG_PROCESSING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_set_popup_generic
 * DESCRIPTION
 *  Set popup screen.
 * PARAMETERS
 *  strID       [IN]        
 *  imgID       [IN]        
 *  toneID      [IN]        
 *  a(?)        [IN]        String ID
 *  c(?)        [IN]        Tone ID
 *  b(?)        [IN]        Image ID
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_set_popup_generic(U16 strID, U16 imgID, U8 toneID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_popup_strID = strID;
    msg_popup_imgID = imgID;
    msg_popup_tonID = toneID;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_display_popup_generic
 * DESCRIPTION
 *  Display popup screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_display_popup_generic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup((PU8) GetString(msg_popup_strID), msg_popup_imgID, 1, MESSAGES_POPUP_TIME_OUT, (U8) msg_popup_tonID);
    DeleteMessagesHistoryNodes();
    AlmEnableSPOF();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_new_msg_popup
 * DESCRIPTION
 *  Entry new message popup.
 * PARAMETERS
 *  type        [IN]        
 *  a(?)        [IN]        New message type
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_new_msg_popup(U8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 indstr = STR_RECEIVED_SMS;
    MMI_ALERT_TYPE alertType;
    U8 pp_flag;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pp_flag = GetInterruptPopupDisplay();
    alertType = GetMtCallAlertTypeEnum();
    
    if ((pp_flag & POPUP_DSPL_ON) == 0)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                             "*-------[SmsMoMtGuiInterface.c] mmi_msg_entry_new_msg_popup POPUP_DSPL_ON == 0 -------*\n");
		if ((pp_flag & POPUP_TONE_ON) == POPUP_TONE_ON)
		{
			if ((alertType == MMI_VIBRATION_ONLY) || (alertType == MMI_VIBRATION_AND_RING)
				|| (alertType == MMI_VIBRATION_THEN_RING))
			{
				if (!AlmIsTonePlaying())
				{
					PlaySmsVibratorOnce();
				}
			}
			playRequestedTone(SMS_IN_CALL_TONE);
		}
	#ifdef __MMI_DUAL_SIM_MASTER__
		g_msg_cntx.isSlave = FALSE;
	#endif
        return;
    }

    EntryNewScreen(SCR_POPUP_SCREEN, mmi_msg_exit_new_msg_popup, NULL, NULL);
    switch (type)
    {
        case MSG_NEW_VOICEMAIL:
		#ifndef __MMI_DUAL_SIM_MASTER__
            indstr = STR_VOICEMAIL_IND;
		#else /* __MMI_DUAL_SIM_MASTER__ */
			if (g_msg_cntx.isSlave == FALSE)
			{
				indstr = STRING_MTPNP_MASTER_VOICEMAIL_IND;
			}
			else
			{
				indstr = STRING_MTPNP_SLAVE_VOICEMAIL_IND;
			}
		#endif /* __MMI_DUAL_SIM_MASTER__ */
            break;
        case MSG_NEW_FAX:
		#ifndef __MMI_DUAL_SIM_MASTER__
            indstr = STR_FAX_IND;
		#else /* __MMI_DUAL_SIM_MASTER__ */
			if (g_msg_cntx.isSlave == FALSE)
			{
				indstr = STRING_MTPNP_MASTER_FAX_IND;
			}
			else
			{
				indstr = STRING_MTPNP_SLAVE_FAX_IND;
			}
		#endif /* __MMI_DUAL_SIM_MASTER__ */
			break;
        case MSG_NEW_EMAIL:            
		#ifndef __MMI_DUAL_SIM_MASTER__
            indstr = STR_EMAIL_IND;
		#else /* __MMI_DUAL_SIM_MASTER__ */
			if (g_msg_cntx.isSlave == FALSE)
			{
				indstr = STRING_MTPNP_MASTER_EMAIL_IND;
			}
			else
			{
				indstr = STRING_MTPNP_SLAVE_EMAIL_IND;
			}
		#endif /* __MMI_DUAL_SIM_MASTER__ */
            break;
        case MSG_NEW_NETOTHER:            
		#ifndef __MMI_DUAL_SIM_MASTER__
            indstr = STR_VOICEMAIL_IND;
		#else /* __MMI_DUAL_SIM_MASTER__ */
			if (g_msg_cntx.isSlave == FALSE)
			{
				indstr = STRING_MTPNP_MASTER_NET_OTHER_IND;
			}
			else
			{
				indstr = STRING_MTPNP_SLAVE_NET_OTHER_IND;
			}
		#endif /* __MMI_DUAL_SIM_MASTER__ */
            break;
#ifndef __MMI_DUAL_SIM_MASTER__
        case MSG_NEW_MSG_NORMAL:
            indstr = STR_RECEIVED_SMS;
            break;
#else /* __MMI_DUAL_SIM_MASTER__ */
	case MSG_NEW_MSG_NORMAL:
		if (g_msg_cntx.isSlave == FALSE)
		{			
            indstr = STRING_MTPNP_MASTER_RECEIVED_SMS;
		}
		else
		{
			indstr = STRING_MTPNP_SLAVE_RECEIVED_SMS;
		}
        break;
#endif /* __MMI_DUAL_SIM_MASTER__ */
    #if (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT))
        case MSG_NEW_JMMS_MMS:
            indstr = STR_ID_JMMS_NEW_MMS;
            break;
        case MSG_NEW_JMMS_JAVA_MMS:
            indstr = STR_ID_JMMS_NEW_JAVA_MMS;
            break;
    #endif /* (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT)) */ 
    #if (defined (JATAAYU_SUPPORT) && defined(WAP_SUPPORT))
        case MSG_NEW_PUSH:
            indstr = STR_ID_BRW_SERVICE_MESSAGE_RCVD;
            break;
        case MSG_NEW_PROV_SETTING:
            indstr = g_prov_newsetting_stringID ; /*STR_ID_PROV_NEW_SETTINGS*/
            break;
    #endif /* (defined (JATAAYU_SUPPORT) && defined(WAP_SUPPORT)) */ 
#ifdef __MMI_MMS_2__
		case MSG_UMMS_NEW_MMS:
			indstr = STR_ID_UMMS_NEW_MMS;
			break;
		case MSG_UMMS_NEW_JAVA_MMS:
			indstr = STR_ID_UMMS_NEW_JAVA_MMS;
			break;
#endif /* __MMI_MMS_2__ */

        case MSG_NEW_MSG_CLASS0:
            indstr = STR_CLASS0_MESSAGE_CAPTION;
            break;
	#ifndef __MMI_DUAL_SIM_MASTER__
        case MSG_NEW_DELIVERY_REPORT:
            indstr = STR_DELIVERY_REPORT_MENUENTRY;
            break;
	#else /* __MMI_DUAL_SIM_MASTER__ */
		case MSG_NEW_DELIVERY_REPORT:
		     if (g_msg_cntx.isSlave == FALSE)
		     {
	         	indstr = STRING_MTPNP_MASTER_DELIVERY_REPORT_MENUENTRY;
		     }
		     else
		     {
		     	 indstr = STRING_MTPNP_SLAVE_DELIVERY_REPORT_MENUENTRY;
		     }
            break;
	#endif /* __MMI_DUAL_SIM_MASTER__ */
    #if defined(__MMI_SMART_MESSAGE_MT__) || (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))
        case MSG_NEW_MSG_PICTURE:
            indstr = STR_ID_NSM_NEW_PICTURE_MESSAGE;
            break;
        case MSG_NEW_MSG_RINGTONE:
            indstr = STR_ID_NSM_NEW_RINGTONE_MESSAGE;
            break;
    #endif /* defined(__MMI_SMART_MESSAGE_MT__) || (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) */ 
    #ifdef __MMI_BROWSER_2__
        case MSG_BRW_NEW_PUSH:
            indstr = STR_ID_BRW_NEW_PUSH_MESSAGE;
            break;
		case MSG_BRW_NEW_MESSAGE:
			indstr = STR_ID_BRW_NEW_MESSAGE;
            break;
    #endif  /* __MMI_BROWSER_2__ */
    #ifdef __MMI_CCA_SUPPORT__
        case MSG_NEW_CCA_SETTING:
        #ifndef __MMI_DUAL_SIM_MASTER__
            indstr = STR_ID_CCA_NEW_SETTING;
        #else /*__MMI_DUAL_SIM_MASTER__*/
            if (g_msg_cntx.isSlave == FALSE)
            {
                indstr = STR_ID_CCA_NEW_SIM1_SETTING;
            }
            else
            {
                indstr = STR_ID_CCA_NEW_SIM2_SETTING;
            }
        #endif /*__MMI_DUAL_SIM_MASTER__*/
            break;
    #endif  /* __MMI_CCA_SUPPORT__ */

        default:
            indstr = STR_RECEIVED_SMS;
            break;
    }
    GetCurrEndKeyDownHandler();
    ShowCategory65Screen((PU8) GetString(indstr), IMG_NEW_MESSAGE_NOTIFICATION_MSG, NULL);
    SetGroupKeyHandler(NULL, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, KEY_EVENT_DOWN);
    SetGroupKeyHandler(GoBackHistory, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    SetKeyHandler(ExecCurrEndKeyDownHandler, KEY_END, KEY_EVENT_DOWN);

    /* show the new msg popup on subLCD */
    ForceSubLCDScreen(mmi_msg_start_msg_sub_anm);
    
    msg_popup_tonID = 0;

    if (alertType == MMI_VIBRATION_AND_RING || alertType == MMI_VIBRATION_THEN_RING || alertType == MMI_RING)
    {
        if (!(isInCall() && !GetWapCallPresent()))
        {
        #ifndef __MMI_DUAL_SIM_MASTER__
            msg_popup_tonID = (U8) MESSAGE_TONE;
		#else /* __MMI_DUAL_SIM_MASTER__ */
		#ifdef __MMI_DUAL_PROFILE_SUPPORT__
			if (g_msg_cntx.isSlave == FALSE)
			{
				msg_popup_tonID = (U8) MESSAGE_TONE;
			}
			else
			{
				msg_popup_tonID = (U8) CARD2_MESSAGE_TONE;
			}
		#else	/* __MMI_DUAL_PROFILE_SUPPORT__ */
			msg_popup_tonID = (U8) MESSAGE_TONE;
		#endif	/* __MMI_DUAL_PROFILE_SUPPORT__ */
		#endif /* __MMI_DUAL_SIM_MASTER__ */
        }
        else
        {
            msg_popup_tonID = (U8) SMS_IN_CALL_TONE;
        }
    }
    if ((alertType == MMI_VIBRATION_ONLY) || (alertType == MMI_VIBRATION_AND_RING)
        || (alertType == MMI_VIBRATION_THEN_RING))
    {
        if (!AlmIsTonePlaying())
        {
            PlaySmsVibratorOnce();
        }
    }

    if ((pp_flag & POPUP_TONE_ON) == 0)
    {
	#ifdef __MMI_DUAL_SIM_MASTER__
		g_msg_cntx.isSlave = FALSE;
	#endif
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                             "*-------[SmsMoMtGuiInterface.c] mmi_msg_entry_new_msg_popup POPUP_TONE_ON == 0 -------*\n");    
        return;
    }

    if (msg_popup_tonID)
    {
        if ((
		#ifdef __MMI_DUAL_PROFILE_SUPPORT__
			(msg_popup_tonID == (U8) CARD2_MESSAGE_TONE) || 
		#endif
			(msg_popup_tonID == (U8) MESSAGE_TONE)) && !(mdi_audio_is_background_play_suspended()))
        {
            mdi_audio_suspend_background_play();
            backgroundaudioresume = TRUE;
        }
        playRequestedTone(msg_popup_tonID);
    }
	#ifdef __MMI_DUAL_SIM_MASTER__
		g_msg_cntx.isSlave = FALSE;
	#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_exit_new_msg_popup
 * DESCRIPTION
 *  Exit new message popup.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_exit_new_msg_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_popup_tonID)
    {
        stopRequestedTone(msg_popup_tonID);
        if (backgroundaudioresume)
        {
            mdi_audio_resume_background_play();
            backgroundaudioresume = FALSE;
        }
    }
    /* active goback subLCD history to return the previous screen */
    GoBackSubLCDHistory();
}

/*****************************************************************************
* FUNCTION
*  mmi_msg_entry_sending
* DESCRIPTION
*   Entry sending screen.
*
* PARAMETERS
*  none
* RETURNS
*  none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
/*
 * void mmi_msg_entry_sending (void)
 * {
 * EntryNewScreen(SCR_ID_MSG_SENDING, mmi_msg_exit_generic, mmi_msg_entry_sending, NULL);
 * PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_sending *\n");
 * 
 * SetMessagesCurrScrnID (SCR_ID_MSG_SENDING);  // may be temp func...
 * 
 * ShowCategory8Screen (STR_SENDING_SMS, 0, 0,0, STR_GLOBAL_CANCEL, IMG_SMS_COMMON_NOIMAGE, 
 * STR_SENDIING_SMS_BODY, IMG_NEW_SMS_SEND, NULL);
 * 
 * ClearInputEventHandler(MMI_DEVICE_ALL);
 * ClearKeyHandler(KEY_END, KEY_EVENT_UP);
 * ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
 * ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
 * ClearKeyHandler(KEY_END, KEY_REPEAT);
 * SetKeyHandler(mmi_msg_abort_msg, KEY_END, KEY_EVENT_DOWN);  
 * SetRightSoftkeyFunction (mmi_msg_abort_msg, KEY_EVENT_UP);
 * }
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_set_msg_num_hint
 * DESCRIPTION
 *  Set message number hint
 * PARAMETERS
 *  totalInbox          [IN]        
 *  totalOutbox         [IN]        
 *  totalDraftbox       [IN]        
 *  a(?)                [IN]        Total inbox
 *  c(?)                [IN]        Total draftbox
 *  b(?)                [IN]        Total outbox
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_set_msg_num_hint(U16 totalInbox, U16 totalOutbox, U16 totalDraftbox)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 LocalData1[10];
    S8 LocalData2[10];
    S8 LocalData3[10];
    S8 LocalData1_unicode[10 * 2];
    S8 LocalData2_unicode[10 * 2];
    S8 LocalData3_unicode[10 * 2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(LocalData1, "%d ", totalInbox);
    sprintf(LocalData2, "%d ", totalOutbox);
    sprintf(LocalData3, "%d ", totalDraftbox);

    mmi_asc_to_ucs2(LocalData1_unicode, LocalData1);
    mmi_asc_to_ucs2(LocalData2_unicode, LocalData2);
    mmi_asc_to_ucs2(LocalData3_unicode, LocalData3);
    mmi_ucs2cpy((PS8) TotalInboxOutboxStatus.totalInboxStr, LocalData1_unicode);
    mmi_ucs2ncat(
        (PS8) TotalInboxOutboxStatus.totalInboxStr,
        GetString(STR_SMS_COUNT_POPUP_SUFFIX),
        MAX_SUBMENU_CHARACTERS);

    mmi_ucs2cpy((PS8) TotalInboxOutboxStatus.totalOutboxStr, LocalData2_unicode);
    mmi_ucs2ncat(
        (PS8) TotalInboxOutboxStatus.totalOutboxStr,
        GetString(STR_SMS_COUNT_POPUP_SUFFIX),
        MAX_SUBMENU_CHARACTERS);

#ifdef __MMI_MESSAGES_DRAFT_BOX__
    mmi_ucs2cpy((PS8) TotalInboxOutboxStatus.totalDraftboxStr, LocalData3_unicode);
    mmi_ucs2ncat(
        (PS8) TotalInboxOutboxStatus.totalDraftboxStr,
        GetString(STR_SMS_COUNT_POPUP_SUFFIX),
        MAX_SUBMENU_CHARACTERS);
#endif /* __MMI_MESSAGES_DRAFT_BOX__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_inline_generic_custom_function
 * DESCRIPTION
 *  Set LSK handle for inline full screen edit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_inline_generic_custom_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInputMethodAndDoneCaptionIcon(IMG_SMS_ENTRY_SCRN_CAPTION);
    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
    SetLeftSoftkeyFunction(EntryScrForInputMethodAndDone, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_inline_generic_done
 * DESCRIPTION
 *  Highlight inline done handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_inline_generic_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        ConfirmInlineFullScreenEdit,
        GoBackHistory);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  GetFirstSemiOctetTarget
 * DESCRIPTION
 *  Get first semi octet
 * PARAMETERS
 *  ch          [IN]        
 *  a(?)        [IN]        Input character
 * RETURNS
 *  first semi octet of input
 *****************************************************************************/
U8 GetFirstSemiOctetTarget(U8 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (ch & 0xf0) >> 4;
}


/*****************************************************************************
 * FUNCTION
 *  GetSecondSemiOctetTarget
 * DESCRIPTION
 *  Get second semi octet
 * PARAMETERS
 *  ch          [IN]        
 *  a(?)        [IN]        Input character
 * RETURNS
 *  second semi octet of input
 *****************************************************************************/
U8 GetSecondSemiOctetTarget(U8 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (ch & 0x0f);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_init_msg_data
 * DESCRIPTION
 *  Init message data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_init_msg_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&TotalInboxOutboxStatus, 0, sizeof(msg_in_out_struct));
    memset(&activeProfile, 0, sizeof(msg_active_profile_struct));
    g_msg_cntx.msg_init = FALSE;    /* init to be false */
    g_msg_cntx.number_from_phb = 0; /* init to be 0 */
    g_msg_cntx.msg_ind_index = SMSAL_INVALID_INDEX;
    g_msg_cntx.msg_ind_in_idle = FALSE;
    g_msg_cntx.msg_ind_after_call = FALSE;
    g_msg_cntx.msg_class0_ind = FALSE;
    g_msg_cntx.msg_full_ind = FALSE;
    g_msg_cntx.msg_exceed_ind = FALSE;
    g_msg_cntx.msg_deliver_ind = FALSE;
    g_msg_cntx.msg_waiting_ind = FALSE;
#ifdef __MMI_UNIFIED_MESSAGE__
    g_msg_cntx.is_background_process = KAL_FALSE;
#endif 
    g_msg_cntx.toDisplayMessageList = TO_DISPLAY_MESSAGE_LIST_NONE;
    g_msg_cntx.sendSaveStatus = SEND_SAVE_NIL;
    g_msg_cntx.sendMessageCase = SEND_CASE_SEND_ONLY;
    g_msg_cntx.PhbSmsInterfaceState = MMI_PHB_SMS_INTERFACE_NONE;
    g_msg_cntx.msg_status = MSG_STATUS_IDLE;
    g_msg_cntx.msg_class0_p = NULL;
    /* g_msg_cntx.msg_class0_p->data=NULL; */
    for (i = 0; i < MAX_STATUS_REPORT_NUM; i++)
    {
        g_msg_cntx.msg_deliver_report[i] = NULL;
    }
    memset(g_msg_cntx.smsPhoneNumber, 0, (MAX_DIGITS + 1) * ENCODING_LENGTH);
    memset(&g_msg_cntx.msg_waiting_info, 0, MAX_WAITING_LINE_NUM * sizeof(msg_waiting_ind_struct));
#if defined(__MMI_MESSAGES_SEND_BY_GROUP__) || defined(__MMI_MESSAGES_SEND_TO_MANY__)
    memset(&(g_msg_cntx.msg_send_info), 0, sizeof(msg_send_many_struct));
#endif 
#ifdef __MMI_MESSAGES_TEMPLATE__
    for (i = 0; i < NUM_TEMPLATES; i++)
    {
        g_msg_cntx.templates[i] = NULL;
    }
    memset(g_msg_cntx.scratchTemplRec, 0, NVRAM_SMS_TEMPL_RECORD_SIZE + ENCODING_LENGTH);
#endif /* __MMI_MESSAGES_TEMPLATE__ */ 
#ifdef __MMI_MESSAGES_USE_URL__
    memset(g_msg_cntx.URLlist, 0x00, sizeof(g_msg_cntx.URLlist));
    g_msg_cntx.URLCount = 0;
#endif /* __MMI_MESSAGES_USE_URL__ */

#ifdef __MMI_EMAIL__
    memset(g_msg_cntx.EmailAddrList, 0x00, sizeof(g_msg_cntx.EmailAddrList));
    g_msg_cntx.EmailAddrCount = 0;
#endif /* __MMI_EMAIL__ */
 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_deinit_msg_data
 * DESCRIPTION
 *  Deinit message data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_deinit_msg_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_msg_cntx.msg_class0_p != NULL)
    {
        OslMfree(g_msg_cntx.msg_class0_p);
        g_msg_cntx.msg_class0_p = NULL;
    }
    for (i = 0; i < MAX_STATUS_REPORT_NUM; i++)
    {
        if (g_msg_cntx.msg_deliver_report[i] != NULL)
        {
            OslMfree(g_msg_cntx.msg_deliver_report[i]);
        }
        g_msg_cntx.msg_deliver_report[i] = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_go_back_from_write_msg
 * DESCRIPTION
 *  Enable schedule power off before go back screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_go_back_from_write_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AlmEnableSPOF();
    GoBackHistory();
}

#if (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))


/*****************************************************************************
 * FUNCTION
 *  mmi_nsm2_exit_write_msg
 * DESCRIPTION
 *  Exit write message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_nsm2_exit_write_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_nsm2_add_text_in_pEMS(&g_nsm_msg_context);
    mmi_msg_exit_generic();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nsm2_add_text_in_pEMS
 * DESCRIPTION
 *  Save textbuffer in pEMS
 * PARAMETERS
 *  nsm_msg_context     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_nsm2_add_text_in_pEMS(nsm_msg_struct *nsm_msg_context)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSData *pEMS;
    U8 dcs = SMSAL_DEFAULT_DCS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pEMS = GetEMSDataForEdit(0, 1);

    if (nsm_msg_context->UCS2_count)    /* JP : 20050625 for trackre issue 429 */
    {
        dcs = SMSAL_UCS2_DCS;
    }

    EMSSetDCS(pEMS, dcs);   /* Set DCS before AddString : for Issue 429 */
    AddString(
        pEMS,
        (U8*) nsm_msg_context->textbuffer,
        (U16) mmi_ucs2strlen((S8*) nsm_msg_context->textbuffer),
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_write_msg
 * DESCRIPTION
 *  Entry write message.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_write_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    EMSData *pEMS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* disallow re-entering SMS application when there is a pending SMS job running in the background */
    if (mmi_frm_sms_check_action_pending())
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_MSG_NOT_READY_YET),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
        return;
    }
    EntryNewScreen(SCR_ID_MSG_WRITE, mmi_nsm2_exit_write_msg, mmi_msg_entry_write_msg, NULL);

    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_write_msg*\n");

    AlmDisableSPOF();

    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_WRITE);

    SetMessagesCurrScrnID(SCR_ID_MSG_WRITE);

    GetEMSDataForEdit(&pEMS, 0);

    SetMessagesCurrScrnID(SCR_ID_MSG_WRITE);

    /* Check previously picture present and set height and header fptr */
    if (g_nsm_msg_context.is_picmsg == TRUE)
    {
        g_nsm_msg_context.pic_height = MAX_NSM_PIC_HEIGHT;
        g_nsm_msg_context.header_fptr = mmi_nsm2_category275_draw_header;
    }
    else
    {
        g_nsm_msg_context.pic_height = 0;
        g_nsm_msg_context.header_fptr = NULL;
    }

    memset(g_nsm_msg_context.textbuffer, '\0', sizeof(g_nsm_msg_context.textbuffer));
    if ((*pEMS).textLength > 0)
    {
        mmi_ucs2ncpy(
            (S8*) g_nsm_msg_context.textbuffer,
            (S8*) (*pEMS).textBuffer,
            (U32) (((*pEMS).textLength) / 2));
    }

    ShowCategoryNSM275Screen(
        STR_WMESSAGE_MENUENTRY,
        STR_GLOBAL_OPTIONS,
        IMG_SMS_COMMON_NOIMAGE,
        STR_GLOBAL_BACK,
        IMG_SMS_COMMON_NOIMAGE,
        INPUT_TYPE_ALPHANUMERIC_LOWERCASE | INPUT_TYPE_USE_ENCODING_BASED_LENGTH,
        g_nsm_msg_context.textbuffer,
        (g_nsm_msg_context.remaining_length + 1),
        4,
        mmi_nsm2_category275_draw_tile,
        (U16) g_nsm_msg_context.pic_height,
        g_nsm_msg_context.header_fptr,
        0,
        NULL,
        guiBuffer);

#ifdef __MMI_DUAL_SIM_MASTER__
	if (!MTPNP_AD_Dual_Card_Reply_SMS())
	{
		if (g_msg_cntx.sendMessageCase == SEND_CASE_REPLY)
		{
			if (MTPNP_AD_SDK_Is_Startup_Finished() &&
				MTPNP_AD_Get_UsableSide() == MTPNP_AD_DUALSIM_USABLE)
			{
				if (!MTPNP_PFAL_Active_SMS_Is_Slave())
				{
					MTPNP_PFAL_Show_Menu(EMS_ED_OPT_DONE);
					MTPNP_PFAL_Hide_Menu(MENU_MTPNP_EMS_ED_OPT_DONE);
					MTPNP_PFAL_Update_Menu_Item_String(EMS_ED_OPT_DONE, 
														STR_GLOBAL_DONE);
				}
				else
				{
					MTPNP_PFAL_Show_Menu(MENU_MTPNP_EMS_ED_OPT_DONE);
					MTPNP_PFAL_Hide_Menu(EMS_ED_OPT_DONE);
					MTPNP_PFAL_Update_Menu_Item_String(MENU_MTPNP_EMS_ED_OPT_DONE, 
															STR_GLOBAL_DONE);
				}
			}
		}
	}
#endif /* __MMI_DUAL_SIM_MASTER__ */
    SetKeyHandler(mmi_msg_entry_send_option, KEY_SEND, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_msg_entry_option_write, KEY_EVENT_UP);
    SetCategory275RightSoftkeyFunction(mmi_msg_go_back_from_write_msg, KEY_EVENT_UP);

}

#else /* (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_write_msg
 * DESCRIPTION
 *  Entry write message.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_write_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    EMSData *pEMS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* disallow re-entering SMS application when there is a pending SMS job running in the background */
    if (mmi_frm_sms_check_action_pending())
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_MSG_NOT_READY_YET),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
        return;
    }
    EntryNewScreen(SCR_ID_MSG_WRITE, mmi_msg_exit_generic, mmi_msg_entry_write_msg, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_write_msg*\n");

    AlmDisableSPOF();

    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_WRITE);

    SetMessagesCurrScrnID(SCR_ID_MSG_WRITE);

    GetEMSDataForEdit(&pEMS, 0);

    SetMessagesCurrScrnID(SCR_ID_MSG_WRITE);

    ShowCategory28Screen(
        STR_WMESSAGE_MENUENTRY,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OPTIONS,
        IMG_SMS_COMMON_NOIMAGE,
        STR_GLOBAL_BACK,
        IMG_SMS_COMMON_NOIMAGE,
        pEMS,
        guiBuffer);

#ifdef __MMI_DUAL_SIM_MASTER__
	if (!MTPNP_AD_Dual_Card_Reply_SMS())
	{
		if (g_msg_cntx.sendMessageCase == SEND_CASE_REPLY)
		{
			if (MTPNP_AD_SDK_Is_Startup_Finished() &&
				MTPNP_AD_Get_UsableSide() == MTPNP_AD_DUALSIM_USABLE)
			{
				if (!MTPNP_PFAL_Active_SMS_Is_Slave())
				{
					MTPNP_PFAL_Show_Menu(EMS_ED_OPT_DONE);
					MTPNP_PFAL_Hide_Menu(MENU_MTPNP_EMS_ED_OPT_DONE);
					MTPNP_PFAL_Update_Menu_Item_String(EMS_ED_OPT_DONE, 
														STR_GLOBAL_DONE);
				}
				else
				{
					MTPNP_PFAL_Show_Menu(MENU_MTPNP_EMS_ED_OPT_DONE);
					MTPNP_PFAL_Hide_Menu(EMS_ED_OPT_DONE);
					MTPNP_PFAL_Update_Menu_Item_String(MENU_MTPNP_EMS_ED_OPT_DONE, 
															STR_GLOBAL_DONE);
				}
			}
		}
	}
	
#ifdef __SENDKEY2_SUPPORT__
    if (!mmi_frm_test_menu_item_hide(EMS_ED_OPT_DONE) && !mmi_frm_test_menu_item_hide(MENU_MTPNP_EMS_ED_OPT_DONE))
    {
        SetKeyHandler(mmi_msg_entry_master_send_option, KEY_SEND1, KEY_EVENT_UP);
		SetKeyHandler(mmi_msg_entry_slave_send_option, KEY_SEND2, KEY_EVENT_UP);
    }
    else
#endif /* __SENDKEY2_SUPPORT__ */
    {
        if (!mmi_frm_test_menu_item_hide(EMS_ED_OPT_DONE))
        {
            SetKeyHandler(mmi_msg_entry_master_send_option, KEY_SEND, KEY_EVENT_UP);
        }
        else if (!mmi_frm_test_menu_item_hide(MENU_MTPNP_EMS_ED_OPT_DONE))
        {
            SetKeyHandler(mmi_msg_entry_slave_send_option, KEY_SEND, KEY_EVENT_UP);
        }
    }
#else /* __MMI_DUAL_SIM_MASTER__ */
	SetKeyHandler(mmi_msg_entry_send_option, KEY_SEND, KEY_EVENT_UP);
#endif /* __MMI_DUAL_SIM_MASTER__ */

    SetLeftSoftkeyFunction(mmi_msg_entry_option_write, KEY_EVENT_UP);
    RegisterInputMethodScreenCloseFunction(Messages2GoBackHistory);
    SetCategory28RightSoftkeyFunction(mmi_msg_go_back_from_write_msg, KEY_EVENT_UP);

}

#endif /* (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_option_write
 * DESCRIPTION
 *  Entry write option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_option_write(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];

#if defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)
    U16 ParentID;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_WRITE_OPTION, mmi_msg_exit_generic, mmi_msg_entry_option_write, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_option_write *\n");

#if defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)

    if (g_nsm_msg_context.is_picmsg == TRUE)
    {
        ParentID = NSM2_ED_OPTIONS_MENU_ID;
    }
    else
    {
        ParentID = EMS_ED_OPTIONS_MENU_ID;
    }

    numItems = GetNumOfChild(ParentID);
    GetSequenceStringIds(ParentID, nStrItemList);
    SetParentHandler(ParentID);

#else /* defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__) */ 

#if defined(WAP_SUPPORT)

#ifndef __MMI_UNIFIED_MESSAGE__
    /* Hide Insert Bookmark menu item if in-call. */
    /* Before UM, WAP widget is not allowed to be entered if in-call. */
    if (isInCall())        
    {
        mmi_frm_hide_menu_item(EMS_ED_OPT_INS_BOOKMARK);
    }
    else        
#endif /* __MMI_UNIFIED_MESSAGE__ */              
    {
        mmi_frm_unhide_menu_item(EMS_ED_OPT_INS_BOOKMARK);
    }
#else /* defined(WAP_SUPPORT) */

    mmi_frm_hide_menu_item(EMS_ED_OPT_INS_BOOKMARK);

#endif /* defined(WAP_SUPPORT) */

    numItems = GetNumOfChild_Ext(EMS_ED_OPTIONS_MENU_ID);
    GetSequenceStringIds_Ext(EMS_ED_OPTIONS_MENU_ID, nStrItemList);
    SetParentHandler(EMS_ED_OPTIONS_MENU_ID);

#endif /* defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__) */ 

    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_WRITE_OPTION);

    SetMessagesCurrScrnID(SCR_ID_MSG_WRITE_OPTION);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_phone_number_empty
 * DESCRIPTION
 *  Set LSK handle for number screen when input empty
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_phone_number_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_SMS_COMMON_SEARCH, IMG_SMS_COMMON_NOIMAGE);
    SetLeftSoftkeyFunction(mmi_msg_search_phb, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_phone_number_not_empty
 * DESCRIPTION
 *  Set LSK handle for number screen when input non empty
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_phone_number_not_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
#ifdef __MMI_MESSAGES_SEND_TO_MANY__
    if (IsScreenPresent(SCR_ID_MSG_SEND_MANY_LIST))
    {
        SetLeftSoftkeyFunction(mmi_msg_save_phone_number, KEY_EVENT_UP);
    }
    else
#endif /* __MMI_MESSAGES_SEND_TO_MANY__ */ 
        SetLeftSoftkeyFunction(mmi_msg_send_msg_to_only_entry, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_phone_number
 * DESCRIPTION
 *  Entry phone number screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_phone_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_NUMBER, mmi_msg_exit_generic, mmi_msg_entry_phone_number, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_phone_number *\n");

    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_NUMBER);    /* maybe assign NULL directly */

    RegisterInputBoxEmptyFunction(mmi_msg_phone_number_empty);
    RegisterInputBoxNotEmptyFunction(mmi_msg_phone_number_not_empty);
    SetMessagesCurrScrnID(SCR_ID_MSG_NUMBER);
    ShowCategory5Screen(
        STR_ENTER_PHONE_NUMBER_CAPTION,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_SMS_COMMON_NOIMAGE,
        STR_GLOBAL_BACK,
        IMG_SMS_COMMON_NOIMAGE,
        INPUT_TYPE_PHONE_NUMBER /* |INPUT_TYPE_PLUS_CHARACTER_HANDLING */ ,
        (U8*) g_msg_cntx.smsPhoneNumber,
        MAX_DIGITS_SMS,
        guiBuffer);

    SetKeyHandler(mmi_msg_send_msg_to_only_entry, KEY_SEND, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_popup_generic
 * DESCRIPTION
 *  Set LSK handle for number screen when input non empty
 * PARAMETERS
 *  string              [?]         
 *  imageId             [IN]        
 *  imageOnBottom       [IN]        
 *  popupDuration       [IN]        
 *  toneId              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_popup_generic(U8 *string, U16 imageId, U8 imageOnBottom, U32 popupDuration, U8 toneId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_POPUP, mmi_msg_exit_popup_generic, NULL, NULL);
    ShowCategory65Screen(string, imageId, NULL);
    SetGroupKeyHandler(NULL, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, KEY_EVENT_DOWN);
    SetGroupKeyHandler(mmi_msg_popup_timeout, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, KEY_EVENT_UP);

    StartTimer(POPUP_TIMER, popupDuration, mmi_msg_popup_timeout);
    msg_popup_tonID = toneId;
    if (msg_popup_tonID)
    {
        playRequestedTone(msg_popup_tonID);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_exit_popup_generic
 * DESCRIPTION
 *  Set LSK handle for number screen when input non empty
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_exit_popup_generic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(POPUP_TIMER);
    if (msg_popup_tonID)
    {
        stopRequestedTone(msg_popup_tonID);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_popup_timeout
 * DESCRIPTION
 *  Set LSK handle for number screen when input non empty
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_popup_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(POPUP_TIMER);
    if (msg_popup_tonID)
    {
        stopRequestedTone(msg_popup_tonID);
    }
    mmi_msg_exec_funcptr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_send_option
 * DESCRIPTION
 *  Entry send option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_send_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_msg_cntx.sendMessageCase == SEND_CASE_REPLY)
    {
        mmi_msg_reply_msg();
        return;
    }
    else if (g_msg_cntx.sendMessageCase == SEND_CASE_SEND_FROM_PHB)
    {
        mmi_msg_send_msg_to_only_entry();
        return;
    }
    else if (g_msg_cntx.sendMessageCase == SEND_CASE_REPLY_FROM_OTHER_APP || 
		     (g_msg_cntx.sendMessageCase == SEND_CASE_SEND_FROM_USE_NUMBER))
    {
        g_msg_cntx.msg_send_info.CurrSendSmsNumbers = 0;
        g_msg_cntx.msg_send_info.TotalSendSmsNumbers = 1;
        mmi_msg_send_msg_req((U8*) g_msg_cntx.smsPhoneNumber, MMI_FRM_SMS_INVALID_INDEX, 1);
        return;
    }

    EntryNewScreen(SCR_ID_MSG_SEND_OPTION, mmi_msg_exit_generic, mmi_msg_entry_send_option, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_send_option *\n");

	if (g_msg_cntx.sendMessageCase != SEND_CASE_SEND_FROM_OTHER_APP)
	{
		g_msg_cntx.sendMessageCase = SEND_CASE_SEND_ONLY;   /* reset */
	}
	
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_SEND_OPTION);

#ifndef __MMI_DUAL_SIM_MASTER__
    numItems = GetNumOfChild(EMS_ED_OPT_DONE);
    GetSequenceStringIds(EMS_ED_OPT_DONE, nStrItemList);
    SetParentHandler(EMS_ED_OPT_DONE);
#else /* else not define __MMI_DUAL_SIM_MASTER__ */	
	switch (MTPNP_AD_Get_Channel(MTPNP_AD_SMS_CHANNEL))
	{
	    case MTPNP_AD_CHANNEL_MASTER:
		    numItems = GetNumOfChild_Ext(EMS_ED_OPT_DONE);
    		GetSequenceStringIds_Ext(EMS_ED_OPT_DONE, nStrItemList);
    		SetParentHandler(EMS_ED_OPT_DONE);
		    break;
	    case MTPNP_AD_CHANNEL_SLAVE:
	        numItems = GetNumOfChild_Ext(MENU_MTPNP_EMS_ED_OPT_DONE);
	    	GetSequenceStringIds_Ext(MENU_MTPNP_EMS_ED_OPT_DONE, nStrItemList);
	    	SetParentHandler(MENU_MTPNP_EMS_ED_OPT_DONE);
		    break;
	    case MTPNP_AD_CHANNEL_DEFAULT_MASTER:
	    case MTPNP_AD_CHANNEL_DEFAULT_SLAVE:
	    default:
		    numItems = GetNumOfChild_Ext(EMS_ED_OPT_DONE);
    		GetSequenceStringIds_Ext(EMS_ED_OPT_DONE, nStrItemList);
    		SetParentHandler(EMS_ED_OPT_DONE);
		    break;	
	}	
#endif /* end define __MMI_DUAL_SIM_MASTER__ */

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    SetMessagesCurrScrnID(SCR_ID_MSG_SEND_OPTION);

#ifdef __MMI_UNIFIED_MESSAGE__
    if ((IsScreenPresent(SCR_ID_MSG_WRITE)) || 
        (IsScreenPresent(SCR_ID_UM_INBOX)) || 
        (IsScreenPresent(SCR_ID_UM_UNSENT)) || 
        (IsScreenPresent(SCR_ID_UM_SENT)) 
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__        
        ||(IsScreenPresent(SCR_ID_UM_ARCHIVE)) 
    #endif        
        ) 
    {
        int i = 0;

        for (i = 0; i < MAX_SUB_MENUS; i++)
        {
            if (nStrItemList[i] == STR_GLOBAL_SAVE)
            {
                nStrItemList[i] = STR_SMS_SAVE_TO_DRAFTS_MENU_ITEM;
                break;
            }
        }
    }
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

#ifndef __MMI_DUAL_SIM_MASTER__
    ShowCategory52Screen(
        STR_SEND_OPTIONS_CAPTION,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
#else /* else not define __MMI_DUAL_SIM_MASTER__ */
	{
	switch (MTPNP_AD_Get_Channel(MTPNP_AD_SMS_CHANNEL))
	{
		case MTPNP_AD_CHANNEL_MASTER:
			ShowCategory52Screen(
			        STRING_MTPNP_MASTER_SEND_OPTIONS_CAPTION,
			        IMG_SMS_ENTRY_SCRN_CAPTION,
			        STR_GLOBAL_OK,
			        IMG_GLOBAL_OK,
			        STR_GLOBAL_BACK,
			        IMG_GLOBAL_BACK,
			        numItems,
			        nStrItemList,
			        (U16*) gIndexIconsImageList,
			        NULL,
			        0,
			        0,
			        guiBuffer);
			break;
		case MTPNP_AD_CHANNEL_SLAVE:
			ShowCategory52Screen(
			        STRING_MTPNP_SLAVE_SEND_OPTIONS_CAPTION,
			        IMG_SMS_ENTRY_SCRN_CAPTION,
			        STR_GLOBAL_OK,
			        IMG_GLOBAL_OK,
			        STR_GLOBAL_BACK,
			        IMG_GLOBAL_BACK,
			        numItems,
			        nStrItemList,
			        (U16*) gIndexIconsImageList,
			        NULL,
			        0,
			        0,
			        guiBuffer);
			break;
		case MTPNP_AD_CHANNEL_DEFAULT_MASTER:
		case MTPNP_AD_CHANNEL_DEFAULT_SLAVE:
		default:
			ShowCategory52Screen(
			        STR_SEND_OPTIONS_CAPTION,
			        IMG_SMS_ENTRY_SCRN_CAPTION,
			        STR_GLOBAL_OK,
			        IMG_GLOBAL_OK,
			        STR_GLOBAL_BACK,
			        IMG_GLOBAL_BACK,
			        numItems,
			        nStrItemList,
			        (U16*) gIndexIconsImageList,
			        NULL,
			        0,
			        0,
			        guiBuffer);
			break;	
	}
	}
#endif	/* end define __MMI_DUAL_SIM_MASTER__ */
}


#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
//the API is called when user press LSK-option in "content page"
void mmi_msg_entry_option_archive_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];

#ifdef __MMI_MESSAGES_EMS__ 
    EMSData *pEms;   
    EMSObject *object_p = NULL;
#endif /* __MMI_MESSAGES_EMS__ */ 


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_INBOX_OPTION, mmi_msg_exit_generic, mmi_msg_entry_option_archive_inbox, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_option_archive_inbox *\n");
    
    /* the deleting screen start point has to be reset to inbox msg screen if inbox option is entered */
#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
    if (IsScreenPresent(SCR_ID_MSG_ARCHIVE_LIST_OPTION))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_ARCHIVE_LIST_OPTION);
    }
    else
#endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_ARCHIVE_INBOX_MSG);
    }
        
    g_msg_cntx.sendMessageCase = SEND_CASE_SEND_ONLY;   /* reset */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_INBOX_OPTION);

    //hidden SMS_INBOX_OPT_MOVE_TO_ARCHIVE_MENUID, SMS_INBOX_OPT_CHAT_MENUID and SMS_INBOX_OPT_ADVANCED_MENUID here
    mmi_frm_hide_menu_item(SMS_INBOX_OPT_MOVE_TO_ARCHIVE_MENUID);
#ifdef __MMI_MESSAGES_CHAT__
    mmi_frm_hide_menu_item(SMS_INBOX_OPT_CHAT_MENUID);
#endif
#ifdef __MMI_MESSAGES_COPY__
    mmi_frm_hide_menu_item(SMS_INBOX_OPT_ADVANCED_MENUID);
#endif


#if defined(__MMI_MESSAGES_USE_URL__)
    /* Hide USE URL menu item if incall or wap screen is present */
    if (isInCall() || IsScreenPresent(wap_get_screen_id()))
    {
        mmi_frm_hide_menu_item(MENU_ID_SMS_INBOX_OPT_USE_URL);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_SMS_INBOX_OPT_USE_URL);
    }
#endif /* defined(__MMI_MESSAGES_USE_URL__) */ 

#ifdef __MMI_MESSAGES_EMS__
    /* Hide USE object menu item if no object in the message */
    GetEMSDataForView(&pEms, 0);
    object_p = pEms->listHead;
    mmi_frm_hide_menu_item(SMS_INBOX_OPT_SAVE_OBJECT_MENUID);
    while (object_p)
    {
        if ((object_p->Type == EMS_TYPE_PIC) || (object_p->Type == EMS_TYPE_USERDEF_ANM) ||
    #if defined(__MMI_IMELODY_SUPPORT__)
            (object_p->Type == EMS_TYPE_USERDEF_SND) ||
    #endif 
            KAL_FALSE)
        {
            mmi_frm_unhide_menu_item(SMS_INBOX_OPT_SAVE_OBJECT_MENUID);
            break;
        }
        object_p = object_p->next;
    }
#endif /* __MMI_MESSAGES_EMS__ */ 

#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
    mmi_frm_hide_menu_item(SMS_INBOX_OPT_VIEW_MENUID);
#endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */

    numItems = GetNumOfChild_Ext(SMS_INBOX_OPTIONS_MENUID);
    GetSequenceStringIds_Ext(SMS_INBOX_OPTIONS_MENUID, nStrItemList);

    SetParentHandler(SMS_INBOX_OPTIONS_MENUID);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    SetMessagesCurrScrnID(SCR_ID_MSG_INBOX_OPTION);

    ShowCategory52Screen(
        STR_SCR6028_CAPTION,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
}


void mmi_msg_entry_option_archive_outbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_OUTBOX_OPTION, mmi_msg_exit_generic, mmi_msg_entry_option_archive_outbox, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_option_archive_outbox*\n");

    /* the deleting screen start point has to be reset to outbox msg screen if outbox option is entered */
#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
    if (IsScreenPresent(SCR_ID_MSG_ARCHIVE_LIST_OPTION))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_ARCHIVE_LIST_OPTION);
    }
    else
#endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_ARCHIVE_OUTBOX_MSG);
    }    
    
    g_msg_cntx.sendMessageCase = SEND_CASE_SEND_ONLY;   /* reset */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_OUTBOX_OPTION);

    //hidden SMS_OUTBOX_OPT_MOVE_TO_ARCHIVE_MENUID, SMS_OUTBOX_OPT_ADVANCED_MENUID here
    mmi_frm_hide_menu_item(SMS_OUTBOX_OPT_MOVE_TO_ARCHIVE_MENUID);
#ifdef __MMI_MESSAGES_COPY__
    mmi_frm_hide_menu_item(SMS_OUTBOX_OPT_ADVANCED_MENUID);
#endif


#if defined(__MMI_MESSAGES_USE_URL__)
    /* Hide USE URL menu item if incall or wap screen is present */
    if (isInCall() || IsScreenPresent(wap_get_screen_id()))
    {
        mmi_frm_hide_menu_item(MENU_ID_SMS_OUTBOX_OPT_USE_URL);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_SMS_OUTBOX_OPT_USE_URL);
    }
#endif /* defined(__MMI_MESSAGES_USE_URL__) */ 

#ifdef __MMI_UNIFIED_MESSAGE__
    mmi_frm_hide_menu_item(SMS_OUTBOX_OPT_SEND_MENUID);
    mmi_frm_unhide_menu_item(SMS_OUTBOX_OPT_FORWARD_MENUID);
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
    mmi_frm_hide_menu_item(SMS_OUTBOX_OPT_VIEW_MENUID);
#endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */

    numItems = GetNumOfChild_Ext(SMS_OUTBOX_OPTIONS_MENUID);
    GetSequenceStringIds_Ext(SMS_OUTBOX_OPTIONS_MENUID, nStrItemList);

    SetParentHandler(SMS_OUTBOX_OPTIONS_MENUID);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    SetMessagesCurrScrnID(SCR_ID_MSG_OUTBOX_OPTION);

    ShowCategory52Screen(
        STR_SCR6028_CAPTION,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
}


#endif /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/



/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_option_inbox
 * DESCRIPTION
 *  Entry inbox option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_option_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];
    U8 *pNumber = NULL;
#if defined (__MMI_MESSAGES_COPY__) && !defined(__MMI_UNIFIED_MESSAGE__)
    U8 storageType;
#endif 

    EMSData *pEms;
#ifdef __MMI_MESSAGES_EMS__
    EMSObject *object_p = NULL;
#endif /* __MMI_MESSAGES_EMS__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_INBOX_OPTION, mmi_msg_exit_generic, mmi_msg_entry_option_inbox, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_option_inbox *\n");
    
    /* the deleting screen start point has to be reset to inbox msg screen if inbox option is entered */
#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
    if (IsScreenPresent(SCR_ID_MSG_INBOX_LIST_OPTION))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_INBOX_LIST_OPTION);
    }
    else
#endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_INBOX_MSG);
    }
        
    g_msg_cntx.sendMessageCase = SEND_CASE_SEND_ONLY;   /* reset */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_INBOX_OPTION);

#if defined(__MMI_MESSAGES_USE_URL__)
    /* Hide USE URL menu item if incall or wap screen is present */
    if (isInCall() || IsScreenPresent(wap_get_screen_id()))
    {
        mmi_frm_hide_menu_item(MENU_ID_SMS_INBOX_OPT_USE_URL);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_SMS_INBOX_OPT_USE_URL);
    }
#endif /* defined(__MMI_MESSAGES_USE_URL__) */ 


    /* Hide USE object menu item if no object in the message */
    GetEMSDataForView(&pEms, 0);
#ifdef __MMI_MESSAGES_EMS__
    object_p = pEms->listHead;
    mmi_frm_hide_menu_item(SMS_INBOX_OPT_SAVE_OBJECT_MENUID);
    while (object_p)
    {
        if ((object_p->Type == EMS_TYPE_PIC) || (object_p->Type == EMS_TYPE_USERDEF_ANM) ||
    #if defined(__MMI_IMELODY_SUPPORT__)
            (object_p->Type == EMS_TYPE_USERDEF_SND) ||
    #endif 
            KAL_FALSE)
        {
            mmi_frm_unhide_menu_item(SMS_INBOX_OPT_SAVE_OBJECT_MENUID);
            break;
        }
        object_p = object_p->next;
    }
#endif /* __MMI_MESSAGES_EMS__ */ 


    // hide "move to archive" if the msg is chat invite msg, but no need, because only not invite msg will run the path
    //mmi_msg_entry_inbox_msg <<<   but in the api, overwrite , both paths run this API,still need check here   
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    mmi_frm_unhide_menu_item(SMS_INBOX_OPT_MOVE_TO_ARCHIVE_MENUID);
#ifdef __MMI_MESSAGES_CHAT__
    if (pEms->listHead == NULL)
    {
        if ( (CheckForInvitationMsg(pEms->textBuffer, (S32) pEms->textLength, TRUE) !=FALSE)  || 
            (gChatInvitation != 0))  //mean it is a invite msg
            mmi_frm_hide_menu_item(SMS_INBOX_OPT_MOVE_TO_ARCHIVE_MENUID);	
        else
            mmi_frm_unhide_menu_item(SMS_INBOX_OPT_MOVE_TO_ARCHIVE_MENUID);			
    }
#endif	
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/

#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
    mmi_frm_unhide_menu_item(SMS_INBOX_OPT_CHAT_MENUID);
    mmi_frm_hide_menu_item(SMS_INBOX_OPT_VIEW_MENUID);
#endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */

#ifdef __MMI_DUAL_SIM_MASTER__	
	numItems = GetNumOfChild_Ext(SMS_INBOX_OPT_FORWARD_MENUID);			
	if (numItems == 0)
	{
		mmi_frm_hide_menu_item(SMS_INBOX_OPT_FORWARD_MENUID);
		mmi_frm_hide_menu_item(SMS_INBOX_OPT_REPLY_MENUID);
	}
	else
	{
		mmi_frm_unhide_menu_item(SMS_INBOX_OPT_FORWARD_MENUID);
		mmi_frm_unhide_menu_item(SMS_INBOX_OPT_REPLY_MENUID);
	}
#endif /* __MMI_DUAL_SIM_MASTER__ */

   /* if SMS is not ready */
    if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_INBOX) == MMI_FRM_SMS_INVALID_INDEX)
    {
        pNumber = mmi_frm_sms_get_address(MMI_FRM_SMS_APP_NOBOX, g_msg_cntx.msg_ind_index);
    }
    else
    {
        pNumber = mmi_frm_sms_get_address(MMI_FRM_SMS_APP_INBOX, (U16) g_msg_cntx.currBoxIndex);
    }
	if (mmi_frm_sms_check_dst_number(pNumber, (U8)strlen((const char*)pNumber)) == TRUE)
	{
		mmi_frm_unhide_menu_item(SMS_INBOX_OPT_REPLY_MENUID);
	#ifdef __MMI_MESSAGES_CHAT__
		mmi_frm_unhide_menu_item(SMS_INBOX_OPT_CHAT_MENUID);
	#endif
	}
	else
	{
		mmi_frm_hide_menu_item(SMS_INBOX_OPT_REPLY_MENUID);
	#ifdef __MMI_MESSAGES_CHAT__
		mmi_frm_hide_menu_item(SMS_INBOX_OPT_CHAT_MENUID);
	#endif
	}

#if defined (__MMI_DUAL_SIM_MASTER__) && defined (__MMI_MESSAGES_COPY__) && !defined(__MMI_UNIFIED_MESSAGE__)
	{
		BOOL isMaster = mmi_frm_msg_is_from_master_sim((U16)g_msg_cntx.currBoxIndex);		
		mmi_frm_unhide_menu_item(SMS_INBOX_OPT_COPY_MENUID);
		mmi_frm_unhide_menu_item(SMS_INBOX_OPT_COPY_ALL_MENUID);
		mmi_frm_unhide_menu_item(SMS_INBOX_OPT_MOVE_MENUID);
		mmi_frm_unhide_menu_item(SMS_INBOX_OPT_MOVE_ALL_MENUID);
		if ((isMaster && !mmi_bootup_is_sim_valid()) || (!isMaster && !mmi_bootup_is_sim2_valid()))
		{
			mmi_frm_hide_menu_item(SMS_INBOX_OPT_COPY_MENUID);
			mmi_frm_hide_menu_item(SMS_INBOX_OPT_COPY_ALL_MENUID);
			mmi_frm_hide_menu_item(SMS_INBOX_OPT_MOVE_MENUID);
			mmi_frm_hide_menu_item(SMS_INBOX_OPT_MOVE_ALL_MENUID);
		}
	}
#endif /* defined (__MMI_DUAL_SIM_MASTER__) && defined (__MMI_MESSAGES_COPY__) && !defined(__MMI_UNIFIED_MESSAGE__) */

    numItems = GetNumOfChild_Ext(SMS_INBOX_OPTIONS_MENUID);
    GetSequenceStringIds_Ext(SMS_INBOX_OPTIONS_MENUID, nStrItemList);
#if defined (__MMI_MESSAGES_COPY__) && !defined(__MMI_UNIFIED_MESSAGE__)
    storageType = mmi_frm_sms_get_storage(MMI_FRM_SMS_INBOX, (U16) g_msg_cntx.currBoxIndex);

    /* default : copy_to_phone */
    if (storageType == SMSAL_ME)
    {
        int i = 0;

        for (i = 0; i < MAX_SUB_MENUS; i++)
        {
            if (nStrItemList[i] == STR_SMS_COPY_TO_PHONE)
            {
                nStrItemList[i] = STR_SMS_COPY_TO_SIM;
                break;
            }
        }
        for (i = 0; i < MAX_SUB_MENUS; i++)
        {
            if (nStrItemList[i] == STR_SMS_MOVE_TO_PHONE)
            {
                nStrItemList[i] = STR_SMS_MOVE_TO_SIM;
                break;
            }
        }
    }
#endif /* defined (__MMI_MESSAGES_COPY__) && !defined(__MMI_UNIFIED_MESSAGE__) */ 
    SetParentHandler(SMS_INBOX_OPTIONS_MENUID);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    SetMessagesCurrScrnID(SCR_ID_MSG_INBOX_OPTION);

    ShowCategory52Screen(
        STR_SCR6028_CAPTION,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_option_outbox
 * DESCRIPTION
 *  Entry outbox option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_option_outbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];

#if defined (__MMI_MESSAGES_COPY__) && !defined(__MMI_UNIFIED_MESSAGE__)
    U8 storageType = 0;
#ifdef __MMI_DUAL_SIM_MASTER__
    U16 msgbox_type = 0;
#endif /* __MMI_DUAL_SIM_MASTER__ */
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_OUTBOX_OPTION, mmi_msg_exit_generic, mmi_msg_entry_option_outbox, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_option_outbox*\n");

    /* the deleting screen start point has to be reset to outbox msg screen if outbox option is entered */
#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
    if (IsScreenPresent(SCR_ID_MSG_OUTBOX_LIST_OPTION))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_LIST_OPTION);
    }
    else
#endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_MSG);
    }    
    
    g_msg_cntx.sendMessageCase = SEND_CASE_SEND_ONLY;   /* reset */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_OUTBOX_OPTION);

#if defined(__MMI_MESSAGES_USE_URL__)
    /* Hide USE URL menu item if incall or wap screen is present */
    if (isInCall() || IsScreenPresent(wap_get_screen_id()))
    {
        mmi_frm_hide_menu_item(MENU_ID_SMS_OUTBOX_OPT_USE_URL);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_SMS_OUTBOX_OPT_USE_URL);
    }
#endif /* defined(__MMI_MESSAGES_USE_URL__) */ 

#ifdef __MMI_UNIFIED_MESSAGE__
    if (mmi_um_get_current_msg_box_type() == UM_MSG_BOX_TYPE_SENT)
    {
        mmi_frm_hide_menu_item(SMS_OUTBOX_OPT_SEND_MENUID);
        mmi_frm_unhide_menu_item(SMS_OUTBOX_OPT_FORWARD_MENUID);
        #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        mmi_frm_unhide_menu_item(SMS_OUTBOX_OPT_MOVE_TO_ARCHIVE_MENUID);
        #endif
    }
    else    /* UNSENT or DRAFT  */
    {
        mmi_frm_hide_menu_item(SMS_OUTBOX_OPT_FORWARD_MENUID);
        mmi_frm_unhide_menu_item(SMS_OUTBOX_OPT_SEND_MENUID);
        #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        mmi_frm_hide_menu_item(SMS_OUTBOX_OPT_MOVE_TO_ARCHIVE_MENUID);
        #endif
    }
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
    mmi_frm_hide_menu_item(SMS_OUTBOX_OPT_VIEW_MENUID);
#endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */

#if defined (__MMI_DUAL_SIM_MASTER__) && defined (__MMI_MESSAGES_COPY__) && !defined(__MMI_UNIFIED_MESSAGE__)
	{
		BOOL isMaster = mmi_frm_msg_is_from_master_sim((U16)g_msg_cntx.currBoxIndex);		
		mmi_frm_unhide_menu_item(SMS_OUTBOX_OPT_COPY_MENUID);
		mmi_frm_unhide_menu_item(SMS_OUTBOX_OPT_COPY_ALL_MENUID);
		mmi_frm_unhide_menu_item(SMS_OUTBOX_OPT_MOVE_MENUID);
		mmi_frm_unhide_menu_item(SMS_OUTBOX_OPT_MOVE_ALL_MENUID);
		if ((isMaster && !mmi_bootup_is_sim_valid()) || (!isMaster && !mmi_bootup_is_sim2_valid()))
		{
			mmi_frm_hide_menu_item(SMS_OUTBOX_OPT_COPY_MENUID);
			mmi_frm_hide_menu_item(SMS_OUTBOX_OPT_COPY_ALL_MENUID);
			mmi_frm_hide_menu_item(SMS_OUTBOX_OPT_MOVE_MENUID);
			mmi_frm_hide_menu_item(SMS_OUTBOX_OPT_MOVE_ALL_MENUID);
		}
	}
#endif /* defined (__MMI_DUAL_SIM_MASTER__) && defined (__MMI_MESSAGES_COPY__) && !defined(__MMI_UNIFIED_MESSAGE__) */

    numItems = GetNumOfChild_Ext(SMS_OUTBOX_OPTIONS_MENUID);
    GetSequenceStringIds_Ext(SMS_OUTBOX_OPTIONS_MENUID, nStrItemList);

#if defined (__MMI_MESSAGES_COPY__) && !defined(__MMI_UNIFIED_MESSAGE__)
    if (g_msg_cntx.toDisplayMessageList == TO_DISPLAY_MESSAGE_LIST_OUTBOX)
    {
    #ifdef __MMI_DUAL_SIM_MASTER__
        msgbox_type = MMI_FRM_SMS_OUTBOX;
    #endif /* __MMI_DUAL_SIM_MASTER__ */
        storageType = mmi_frm_sms_get_storage(MMI_FRM_SMS_OUTBOX, (U16) g_msg_cntx.currBoxIndex);
    }

#ifdef __MMI_UNIFIED_MESSAGE__
	else if (g_msg_cntx.toDisplayMessageList == TO_DISPLAY_MESSAGE_LIST_UNSENTBOX)
	{
        storageType = mmi_frm_sms_get_storage(MMI_FRM_SMS_UNSENT, (U16) g_msg_cntx.currBoxIndex);
	}
#endif /* __MMI_UNIFIED_MESSAGE__ */
	
#ifdef __MMI_MESSAGES_DRAFT_BOX__
    else
    {
    #ifdef __MMI_DUAL_SIM_MASTER__
        msgbox_type = MMI_FRM_SMS_DRAFTS;
    #endif /* __MMI_DUAL_SIM_MASTER__ */
        storageType = mmi_frm_sms_get_storage(MMI_FRM_SMS_DRAFTS, (U16) g_msg_cntx.currBoxIndex);
    }
#endif /* __MMI_MESSAGES_DRAFT_BOX__ */ 

    /* default : copy_to_phone */
    if (storageType == SMSAL_ME)
    {
        int i = 0;

        for (i = 0; i < MAX_SUB_MENUS; i++)
        {
            if (nStrItemList[i] == STR_SMS_COPY_TO_PHONE)
            {
                nStrItemList[i] = STR_SMS_COPY_TO_SIM;
                break;
            }
        }
        for (i = 0; i < MAX_SUB_MENUS; i++)
        {
            if (nStrItemList[i] == STR_SMS_MOVE_TO_PHONE)
            {
                nStrItemList[i] = STR_SMS_MOVE_TO_SIM;
                break;
            }
        }
    }
#endif /* defined (__MMI_MESSAGES_COPY__) && !defined(__MMI_UNIFIED_MESSAGE__) */ 
    SetParentHandler(SMS_OUTBOX_OPTIONS_MENUID);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    SetMessagesCurrScrnID(SCR_ID_MSG_OUTBOX_OPTION);

    ShowCategory52Screen(
        STR_SCR6028_CAPTION,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_option_default
 * DESCRIPTION
 *  Entry default option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_option_default(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_DEFAULT_OPTION, mmi_msg_exit_generic, mmi_msg_entry_option_default, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_option_default *\n");

    /* the deleting screen start point has to be reset to msg screen if msg option is entered */
#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
    if (IsScreenPresent(SCR_ID_MSG_DEFAULT_LIST_OPTION))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_LIST_OPTION);
    }
    else
#endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_MSG);
    }    
        
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_DEFAULT_OPTION);

#ifdef __MMI_UNIFIED_MESSAGE__
    if (mmi_um_get_current_msg_box_type() != UM_MSG_BOX_TYPE_INBOX)
#else /* __MMI_UNIFIED_MESSAGE__ */
#ifdef __MMI_MESSAGES_DRAFT_BOX__
    if (IsScreenPresent(SCR_ID_MSG_OUTBOX_LIST) || IsScreenPresent(SCR_ID_MSG_DRAFTBOX_LIST))
#else 
    if (IsScreenPresent(SCR_ID_MSG_OUTBOX_LIST))
#endif 
#endif /* __MMI_UNIFIED_MESSAGE__ */
    {
    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        if (mmi_um_get_current_msg_box_type() == UM_MSG_BOX_TYPE_SIM)
        {
         #ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
            mmi_frm_hide_menu_item(SMS_SIM_OPT_VIEW_MENUID);
         #endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */
            numItems = GetNumOfChild_Ext(SMS_SIM_OPTIONS_MENUID);    
            GetSequenceStringIds_Ext(SMS_SIM_OPTIONS_MENUID, nStrItemList);
            SetParentHandler(SMS_SIM_OPTIONS_MENUID);
        }
        else
    #endif
        {
        #ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
            mmi_frm_hide_menu_item(SMS_DEFAULT_OPT_VIEW_MENUID);
        #endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */
                
            numItems = GetNumOfChild_Ext(SMS_OUTBOX_DEFAULT_OPTIONS_MENUID);
            GetSequenceStringIds_Ext(SMS_OUTBOX_DEFAULT_OPTIONS_MENUID, nStrItemList);
            SetParentHandler(SMS_OUTBOX_DEFAULT_OPTIONS_MENUID);
        }
    }
    else
    {

    #ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
        mmi_frm_hide_menu_item(SMS_SR_OPT_VIEW_MENUID);
    #endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */

        numItems = GetNumOfChild_Ext(SMS_INBOX_SR_OPTIONS_MENUID);
        GetSequenceStringIds_Ext(SMS_INBOX_SR_OPTIONS_MENUID, nStrItemList);
        SetParentHandler(SMS_INBOX_SR_OPTIONS_MENUID);
    }
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    SetMessagesCurrScrnID(SCR_ID_MSG_DEFAULT_OPTION);

    ShowCategory52Screen(
        STR_SCR6028_CAPTION,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
}

#ifdef __MMI_MESSAGES_CHAT__


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_option_chat
 * DESCRIPTION
 *  Entry chat message option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_option_chat(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_CHAT_INVITATION, mmi_msg_exit_generic, mmi_msg_entry_option_chat, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_option_chat *\n");
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_CHAT_INVITATION);

    numItems = GetNumOfChild(SMS_CHAT_INVITATION_MENUID);
    GetSequenceStringIds(SMS_CHAT_INVITATION_MENUID, nStrItemList);
    SetParentHandler(SMS_CHAT_INVITATION_MENUID);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    SetMessagesCurrScrnID(SCR_ID_MSG_CHAT_INVITATION);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
}
#endif /* __MMI_MESSAGES_CHAT__ */ 

#ifdef __MMI_UNIFIED_COMPOSER__
/*****************************************************************************
 * FUNCTION
 *  mmi_msg_forward_by_uc
 * DESCRIPTION
 *  Forward msg by unified composer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_forward_msg_by_uc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_entry_uc(NULL , MMI_UC_STATE_FORWARD, (U16)g_msg_cntx.currBoxIndex, MMI_UC_MSG_TYPE_DEFAULT);

#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
    if (IsScreenPresent(SCR_ID_MSG_INBOX_LIST_OPTION))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_INBOX_LIST_OPTION);
    }
    else if (IsScreenPresent(SCR_ID_MSG_OUTBOX_LIST_OPTION))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_LIST_OPTION);
    }
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    else if (IsScreenPresent(SCR_ID_MSG_ARCHIVE_LIST_OPTION))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_ARCHIVE_LIST_OPTION);
    }
#endif
    else if (IsScreenPresent(SCR_ID_MSG_DEFAULT_LIST_OPTION))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_LIST_OPTION);
    }
    else
#endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */

    if (IsScreenPresent(SCR_ID_MSG_INBOX_MSG))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_INBOX_MSG);
    }
    else if (IsScreenPresent(SCR_ID_MSG_OUTBOX_MSG))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_MSG);
    }        
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    else if (IsScreenPresent(SCR_ID_MSG_ARCHIVE_INBOX_MSG))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_ARCHIVE_INBOX_MSG);
    }  
    else if (IsScreenPresent(SCR_ID_MSG_ARCHIVE_OUTBOX_MSG))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_ARCHIVE_OUTBOX_MSG);
    }  
#endif
    else
    {
        MMI_ASSERT(0);
    }    
    DeleteMessagesHistoryNodes();
}
#endif /* __MMI_UNIFIED_COMPOSER__ */ 

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_send_option_outbox
 * DESCRIPTION
 *  Entry outbox send option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_send_option_outbox(void)
{
#ifdef __MMI_UNIFIED_COMPOSER__
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result = EMS_OK;
    EMSData *pEMS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    result = CopyEMSViewToEditBuffer();
    /* copy view content to edit buffer maybe fail due to EMS LIB virtual pack fail */
    if (result != EMS_OK)
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_FAILURE_MSG_LEN_EXCEEDED),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
        return;
    }

    GetEMSDataForEdit(&pEMS, 0);
    
    if (pEMS->listHead)
    {
        mmi_msg_set_confirm_screen(STR_SMS_REMOVE_EMS_OBJECT_QUERY_ID, mmi_msg_forward_msg_by_uc, GoBackHistory);
        mmi_msg_entry_confirm_generic();
    }
    else
    {
        mmi_msg_forward_msg_by_uc();
    }
    
#else /* __MMI_UNIFIED_COMPOSER__ */


    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result = EMS_OK;
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SMART_MESSAGE_MT__) || defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)

    if (mmi_nsm_get_msg_type() == PICTURE_MESSAGE)
    {
        if (gPictureMessageError == MMI_NSM_PIC_FORMAT_ERROR)
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_NSM_RINGTOEN_FORMAT_NOT_SUPPORTED_MSG),
                IMG_GLOBAL_ERROR,
                FALSE,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
            return;
        }
    }
#endif /* defined(__MMI_SMART_MESSAGE_MT__) || defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__) */ 

    EntryNewScreen(SCR_ID_MSG_OUTBOX_SEND_OPTION, mmi_msg_exit_generic, mmi_msg_entry_send_option_outbox, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_send_option_outbox*\n");

    result = CopyEMSViewToEditBuffer();
    /* copy view content to edit buffer maybe fail due to EMS LIB virtual pack fail */
    if (result != EMS_OK)
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_FAILURE_MSG_LEN_EXCEEDED),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
        DeleteScreenIfPresent(SCR_ID_MSG_OUTBOX_SEND_OPTION);
        return;
    }
    g_msg_cntx.sendMessageCase = SEND_CASE_SEND_ONLY;   /* reset */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_OUTBOX_SEND_OPTION);

    numItems = GetNumOfChild(SMS_OUTBOX_OPT_SEND_MENUID);
    GetSequenceStringIds(SMS_OUTBOX_OPT_SEND_MENUID, nStrItemList);
    SetParentHandler(SMS_OUTBOX_OPT_SEND_MENUID);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    SetMessagesCurrScrnID(SCR_ID_MSG_OUTBOX_SEND_OPTION);

#if defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)

    /* Copy picbuffer and text buffer to send pic msg */
    if (IsScreenPresent(SCR_ID_PICMSG_OPTION))
    {
        S32 tmp_ucs2_count = g_nsm_msg_context.UCS2_count;

        mmi_nsm2_init_nsm_msg_struct(&g_nsm_msg_context);
        g_nsm_msg_context.is_picmsg = TRUE;
        mmi_ucs2cpy((S8*) g_nsm_msg_context.textbuffer, (S8*) TextBuffer);
        memcpy(g_nsm_msg_context.picbuffer, gNSMBuffer, sizeof(g_nsm_msg_context.picbuffer));
        g_nsm_msg_context.UCS2_count = tmp_ucs2_count;
    }
    else
    {
        S32 tmp_ucs2_count = g_nsm_msg_context.UCS2_count;

        /* Jp for tracker issue 429 20050625 for normal sms */
        mmi_nsm2_init_nsm_msg_struct(&g_nsm_msg_context);
        g_nsm_msg_context.UCS2_count = tmp_ucs2_count;
    }
#endif /* defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__) */ 

#if defined(__MMI_SMART_MESSAGE_MT__)

    if (IsScreenPresent(SCR_ID_PICMSG_OPTION))
    {
        S32 tmp_ucs2_count = picmsg_text_struct.ucs2_count;

        memset(&picmsg_text_struct, 0x00, sizeof(picmsg_text_struct));
        mmi_ucs2cpy(picmsg_text_struct.pic_textbuff, (S8*) TextBuffer);
        picmsg_text_struct.ucs2_count = tmp_ucs2_count;
    }
#endif /* defined(__MMI_SMART_MESSAGE_MT__) */ 

    ShowCategory52Screen(
        STR_SEND_OPTIONS_CAPTION,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);

#endif /* __MMI_UNIFIED_COMPOSER__ */

}

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_forward_option_inbox
 * DESCRIPTION
 *  Entry inbox send option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_forward_option_inbox(void)
{
#ifdef __MMI_UNIFIED_COMPOSER__

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result = EMS_OK;
    EMSData *pEMS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    result = CopyEMSViewToEditBuffer();
    /* copy view content to edit buffer maybe fail due to EMS LIB virtual pack fail */
    if (result != EMS_OK)
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_FAILURE_MSG_LEN_EXCEEDED),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
        return;
    }

    GetEMSDataForEdit(&pEMS, 0);
    
    if (pEMS->listHead)
    {
        mmi_msg_set_confirm_screen(STR_SMS_REMOVE_EMS_OBJECT_QUERY_ID, mmi_msg_forward_msg_by_uc, GoBackHistory);
        mmi_msg_entry_confirm_generic();
    }
    else
    {
        mmi_msg_forward_msg_by_uc();
    }
    
#else /* __MMI_UNIFIED_COMPOSER__ */

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result = EMS_OK;
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SMART_MESSAGE_MT__) || defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)

    if (mmi_nsm_get_msg_type() == PICTURE_MESSAGE)
    {
        if (gPictureMessageError == MMI_NSM_PIC_FORMAT_ERROR)
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_NSM_RINGTOEN_FORMAT_NOT_SUPPORTED_MSG),
                IMG_GLOBAL_ERROR,
                FALSE,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
            return;
        }
    }
#endif /* defined(__MMI_SMART_MESSAGE_MT__) || defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__) */ 

    EntryNewScreen(SCR_ID_MSG_INBOX_FORWARD_OPTION, mmi_msg_exit_generic, mmi_msg_entry_forward_option_inbox, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_forward_option_inbox*\n");

    result = CopyEMSViewToEditBuffer();
    /* copy view content to edit buffer maybe fail due to EMS LIB virtual pack fail */
    if (result != EMS_OK)
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_FAILURE_MSG_LEN_EXCEEDED),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
        DeleteScreenIfPresent(SCR_ID_MSG_INBOX_FORWARD_OPTION);
        return;
    }
    g_msg_cntx.sendMessageCase = SEND_CASE_SEND_ONLY;   /* reset */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_INBOX_FORWARD_OPTION);

#ifndef __MMI_DUAL_SIM_MASTER__
    numItems = GetNumOfChild(SMS_INBOX_OPT_FORWARD_MENUID);
    GetSequenceStringIds(SMS_INBOX_OPT_FORWARD_MENUID, nStrItemList);
    SetParentHandler(SMS_INBOX_OPT_FORWARD_MENUID);
#else /* __MMI_DUAL_SIM_MASTER__ */
	switch (MTPNP_AD_Get_Channel(MTPNP_AD_SMS_CHANNEL))
	{
		case MTPNP_AD_CHANNEL_SLAVE:
		case MTPNP_AD_CHANNEL_DEFAULT_SLAVE:
			numItems = GetNumOfChild_Ext(MENU_MTPNP_MSGBOX_OPT_SLAVE_FORWARD);
    		GetSequenceStringIds_Ext(MENU_MTPNP_MSGBOX_OPT_SLAVE_FORWARD, nStrItemList);
    		SetParentHandler(MENU_MTPNP_MSGBOX_OPT_SLAVE_FORWARD);
			break;
		case MTPNP_AD_CHANNEL_MASTER:
		case MTPNP_AD_CHANNEL_DEFAULT_MASTER:
		default:
			numItems = GetNumOfChild_Ext(MENU_MTPNP_MSGBOX_OPT_MASTER_FORWARD);
    		GetSequenceStringIds_Ext(MENU_MTPNP_MSGBOX_OPT_MASTER_FORWARD, nStrItemList);
    		SetParentHandler(MENU_MTPNP_MSGBOX_OPT_MASTER_FORWARD);
			break;
	}
#endif /* __MMI_DUAL_SIM_MASTER__ */

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    SetMessagesCurrScrnID(SCR_ID_MSG_INBOX_FORWARD_OPTION);

#if defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)

    /* Copy picbuffer and text buffer to send pic msg */
    if (IsScreenPresent(SCR_ID_PICMSG_OPTION))
    {
        S32 tmp_ucs2_count = g_nsm_msg_context.UCS2_count;

        mmi_nsm2_init_nsm_msg_struct(&g_nsm_msg_context);
        g_nsm_msg_context.is_picmsg = TRUE;
        mmi_ucs2cpy((S8*) g_nsm_msg_context.textbuffer, (S8*) TextBuffer);
        memcpy(g_nsm_msg_context.picbuffer, gNSMBuffer, sizeof(g_nsm_msg_context.picbuffer));
        g_nsm_msg_context.UCS2_count = tmp_ucs2_count;
    }
    else
    {
        S32 tmp_ucs2_count = g_nsm_msg_context.UCS2_count;

        /* Jp for tracker issue 429 20050625 for normal sms */
        mmi_nsm2_init_nsm_msg_struct(&g_nsm_msg_context);
        g_nsm_msg_context.UCS2_count = tmp_ucs2_count;
    }
#endif /* defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__) */ 

#if defined(__MMI_SMART_MESSAGE_MT__)

    if (IsScreenPresent(SCR_ID_PICMSG_OPTION))
    {
        S32 tmp_ucs2_count = picmsg_text_struct.ucs2_count;

        memset(&picmsg_text_struct, 0x00, sizeof(picmsg_text_struct));
        mmi_ucs2cpy(picmsg_text_struct.pic_textbuff, (S8*) TextBuffer);
        picmsg_text_struct.ucs2_count = tmp_ucs2_count;
    }
#endif /* defined(__MMI_SMART_MESSAGE_MT__) */ 

    ShowCategory52Screen(
        STR_FORWARD_MENUENTRY,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);

#endif /* __MMI_UNIFIED_COMPOSER__ */
}

#ifdef __MMI_SEND_BY_SEARCH_NAME__


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_send_only
 * DESCRIPTION
 *  Entry send only screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_send_only(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_SEND_ONLY_OPTION, mmi_msg_exit_generic, mmi_msg_entry_send_only, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_send_only*\n");

    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_SEND_ONLY_OPTION);

    numItems = GetNumOfChild(SEND_OPT_SEND_ONLY_MENUID);
    GetSequenceStringIds(SEND_OPT_SEND_ONLY_MENUID, nStrItemList);
    SetParentHandler(SEND_OPT_SEND_ONLY_MENUID);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    SetMessagesCurrScrnID(SCR_ID_MSG_SEND_ONLY_OPTION);

    ShowCategory52Screen(
        STR_SEND_ONLY_MENU_ITEM,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
}
#endif /* __MMI_SEND_BY_SEARCH_NAME__ */ 

#if defined (__MMI_MESSAGES_SEND_TO_MANY__)


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_send_to_many_list_option
 * DESCRIPTION
 *  Entry send to many list option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_send_to_many_list_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(
        SCR_ID_MSG_SEND_MANY_LIST_OPTION,
        mmi_msg_exit_generic,
        mmi_msg_entry_send_to_many_list_option,
        NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_SEND_MANY_LIST_OPTION);

    numItems = GetNumOfChild(SEND_OPT_SEND_TO_MANY_BY_LIST_OPTION);
    GetSequenceStringIds(SEND_OPT_SEND_TO_MANY_BY_LIST_OPTION, nStrItemList);
    SetParentHandler(SEND_OPT_SEND_TO_MANY_BY_LIST_OPTION);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    SetMessagesCurrScrnID(SCR_ID_MSG_SEND_MANY_LIST_OPTION);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_send_to_many
 * DESCRIPTION
 *  Entry send to many screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_send_to_many(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_SEND_MANY_OPTION, mmi_msg_exit_generic, mmi_msg_entry_send_to_many, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_send_to_many *\n");

    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_SEND_MANY_OPTION);

    numItems = GetNumOfChild(SEND_OPT_SEND_TO_MANY_MENUID);
    GetSequenceStringIds(SEND_OPT_SEND_TO_MANY_MENUID, nStrItemList);
    SetParentHandler(SEND_OPT_SEND_TO_MANY_MENUID);

    g_msg_cntx.sendMessageCase = SEND_CASE_SEND_TO_MANY;
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    SetMessagesCurrScrnID(SCR_ID_MSG_SEND_MANY_OPTION);

    ShowCategory52Screen(
        STR_SENDTOMANY_MENUENTRY,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_send_to_many_list
 * DESCRIPTION
 *  Entry send to many list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_send_to_many_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    S32 hiliteitem = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_SEND_MANY_LIST, mmi_msg_exit_generic, mmi_msg_entry_send_to_many_list, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_send_to_many_list *\n");

    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_SEND_MANY_LIST);

    if (guiBuffer != NULL)
    {
        hiliteitem = (g_msg_cntx.currSendNumIndex < MAX_SEND_TO_MANY_ITEMS) ? g_msg_cntx.currSendNumIndex : 0;
    }

    SetMessagesCurrScrnID(SCR_ID_MSG_SEND_MANY_LIST);

    RegisterHighlightHandler(GetSendNumIndex);

    ShowCategory184Screen(
        STR_SENDTOMANY_MENUENTRY,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OPTIONS,
        IMG_SMS_COMMON_NOIMAGE,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MAX_SEND_TO_MANY_ITEMS,
        mmi_msg_send_to_many_list_get_item,
        mmi_msg_send_to_many_list_get_hint,
        hiliteitem,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_msg_entry_send_to_many_list_option, KEY_EVENT_UP);
    SetKeyHandler(mmi_msg_entry_send_to_many_list_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_send_to_many_list_get_item
 * DESCRIPTION
 *  Get send to many list item
 * PARAMETERS
 *  item_index          [IN]            
 *  str_buff            [IN]            
 *  img_buff_p          [?]             
 *  str_img_mask        [IN]            
 *  a(?)                [IN]            Item index
 *  c(?)                [IN/OUT]        Image buffer pointer
 *  b(?)                [IN/OUT]        String image mask
 * RETURNS
 * TRUE
 *****************************************************************************/
pBOOL mmi_msg_send_to_many_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 temp[MAX_DIGITS * ENCODING_LENGTH];
    S8 *name;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((item_index < 0) || (item_index > MAX_SEND_TO_MANY_ITEMS))
    {
        return FALSE;
    }

    mmi_ucs2cpy(temp, (S8*) g_msg_cntx.msg_send_info.PhbNumber[item_index]);
    name = lookUpNumber(temp);
    if (mmi_ucs2strlen(name))
    {
        mmi_ucs2cpy((S8*) str_buff, name);
    }
    else if (mmi_ucs2strlen(temp))
    {
        mmi_ucs2cpy((S8*) str_buff, temp);
    }
    else
    {
        mmi_ucs2cpy((S8*) str_buff, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
    }

    *img_buff_p = get_image(gIndexIconsImageList[item_index]);
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_send_to_many_list_get_hint
 * DESCRIPTION
 *  Get send to many list hint
 * PARAMETERS
 *  item_index      [IN]            
 *  hint_array      [?]             
 *  a(?)            [IN]            Item index
 *  b(?)            [IN/OUT]        Hint array
 * RETURNS
 *  TRUE: hint display, FALSE: hint not display
 *****************************************************************************/
S32 mmi_msg_send_to_many_list_get_hint(S32 item_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((item_index < 0) || (item_index > MAX_SEND_TO_MANY_ITEMS))
    {
        return FALSE;
    }

    /* do not show name in send to many list in case of duplicated entries in the phonebook */
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_phone_number_from_send_to_many
 * DESCRIPTION
 *  Entry phone number from send to many list edit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_phone_number_from_send_to_many(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) g_msg_cntx.smsPhoneNumber, 0, ENCODING_LENGTH);
    mmi_ucs2cpy(
        (S8*) g_msg_cntx.smsPhoneNumber,
        (S8*) g_msg_cntx.msg_send_info.PhbNumber[g_msg_cntx.currSendNumIndex]);
    mmi_msg_entry_phone_number();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_save_phone_number
 * DESCRIPTION
 *  Save phone number for send to many list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_save_phone_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 len = 0;
    S8 tempAnssiiNumber[MAX_DIGITS + 1];	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc(tempAnssiiNumber, g_msg_cntx.smsPhoneNumber);
    len = mmi_ucs2strlen(g_msg_cntx.smsPhoneNumber);

    if (len == 0)
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_NUM_CANNOT_BE_EMPTY),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
    }
    else if (mmi_frm_sms_check_dst_number((U8*)tempAnssiiNumber, len) == KAL_FALSE)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_PHB_NUM_INVALID),
            IMG_GLOBAL_ERROR,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
    }
	else
	{
		memset((S8*) g_msg_cntx.msg_send_info.PhbNumber[g_msg_cntx.currSendNumIndex], 0, ENCODING_LENGTH);
	    mmi_ucs2cpy(
	        (S8*) g_msg_cntx.msg_send_info.PhbNumber[g_msg_cntx.currSendNumIndex],
	        (S8*) g_msg_cntx.smsPhoneNumber);
	    Messages2GoBackHistory();
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_erase_phone_number
 * DESCRIPTION
 *  Erase phone number for send to many list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_erase_phone_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) g_msg_cntx.msg_send_info.PhbNumber[g_msg_cntx.currSendNumIndex], 0, ENCODING_LENGTH);
    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_SEND_MANY_LIST_OPTION);
    DisplayPopup(
        (PU8) GetString(STR_MESSAGES_ERACED_ID),
        IMG_GLOBAL_ACTIVATED,
        1,
        MESSAGES_POPUP_TIME_OUT,
        (U8) SUCCESS_TONE);
    DeleteMessagesHistoryNodes();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_pre_erase_phone_number
 * DESCRIPTION
 *  Before erase phone number, see if it is empty
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_pre_erase_phone_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*) g_msg_cntx.msg_send_info.PhbNumber[g_msg_cntx.currSendNumIndex]) == 0)
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_SEND_MANY_LIST_OPTION);
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_EMPTY,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) EMPTY_LIST_TONE);
        DeleteMessagesHistoryNodes();
    }
    else
    {
        mmi_msg_set_confirm_screen(STR_MESSAGES_ERACE_Q_ID, mmi_msg_erase_phone_number, Messages2GoBackHistory);
        mmi_msg_entry_confirm_generic();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_send_to_many_list_edit
 * DESCRIPTION
 *  Highlight send to many list edit handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_send_to_many_list_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_entry_phone_number_from_send_to_many,
        GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_send_to_many_list_erase
 * DESCRIPTION
 *  Highlight send to many list erase handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_send_to_many_list_erase(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_pre_erase_phone_number,
        GoBackHistory);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

#endif /* defined (__MMI_MESSAGES_SEND_TO_MANY__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_msg_date_time
 * DESCRIPTION
 *  Get message date time
 * PARAMETERS
 *  dateStr     [?]             
 *  timeStr     [?]             
 *  scts        [?]             
 *  a(?)        [IN/OUT]        Date string
 *  c(?)        [IN]            Scts
 *  b(?)        [IN/OUT]        Time string
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_get_msg_date_time(S8 *dateStr, S8 *timeStr, U8 scts[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type d[MAX_TIMESTAMP_SIZE * ENCODING_LENGTH];
    UI_character_type t[MAX_TIMESTAMP_SIZE * ENCODING_LENGTH];
    UI_time datetime;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dateStr)
    {
        datetime.nDay = scts[2];
        datetime.nMonth = scts[1];
        datetime.nYear = scts[0] + 2000;
        if (datetime.nYear > 2090)
        {
            datetime.nYear = datetime.nYear - 100;
        }
        date_string(&datetime, (UI_string_type) d, DT_IDLE_SCREEN);
        memset(dateStr, 0, (MAX_TIMESTAMP_SIZE + 1) * ENCODING_LENGTH);
        memcpy(dateStr, (S8*) d, MAX_TIMESTAMP_SIZE * ENCODING_LENGTH);
    }

    if (timeStr)
    {
        datetime.nHour = scts[3];
        datetime.nMin = scts[4];
        datetime.nSec = scts[5];
        time_string(&datetime, (UI_string_type) t, DT_IDLE_SCREEN);
        memset(timeStr, 0, (MAX_TIMESTAMP_SIZE + 1) * ENCODING_LENGTH);
        memcpy(timeStr, (S8*) t, MAX_TIMESTAMP_SIZE * ENCODING_LENGTH);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_pre_entry_inbox_list
 * DESCRIPTION
 *  Before enter inbox list, check if reget list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/*
 * U8 mmi_msg_handle_ready_ind_inbox(void* dummy)
 * {
 * mmi_msg_entry_inbox_list();
 * DeleteScreenIfPresent(SCR_ID_MSG_PROCESSING);
 * return FALSE;
 * }
 */
void mmi_msg_pre_entry_inbox_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
	MTPNP_AD_SMS_Set_Filter_Rule(MTPNP_AD_FILTER_ALL);
#endif /* __MMI_DUAL_SIM_MASTER__ */

    if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_INBOX) == 0)
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_EMPTY,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) EMPTY_LIST_TONE);
    }
    else if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_INBOX) == MMI_FRM_SMS_INVALID_INDEX)
    {
        mmi_msg_set_processing_screen(
            STR_MESSAGE_MAIN_MENU_CAPTION,
            STR_LOADING_SMS,
            IMG_GLOBAL_PROGRESS,
            STR_LOADING_INBOX_BACK);
        mmi_msg_entry_processing_generic();
        /* SetInterruptEventHandler(mmi_msg_handle_ready_ind_inbox, NULL, PRT_MSG_ID_MMI_SMS_READY_IND); */
    }
    /* disallow re-entering SMS application when there is a pending SMS job running in the background */
    else if (mmi_frm_sms_check_action_pending())
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_MSG_NOT_READY_YET),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
    }
    else
    {
        mmi_msg_entry_inbox_list();
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_msg_go_back_to_inbox_list
* DESCRIPTION
*   Go back to inbox list
*
* PARAMETERS
*  none
* RETURNS
*  none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
/*
 * void mmi_msg_go_back_to_inbox_list (void)
 * {
 * if(g_msg_cntx.get_inbox_list_needed)
 * {
 * g_msg_cntx.toDisplayMessageList = TO_DISPLAY_MESSAGE_LIST_INBOX;  
 * mmi_msg_set_processing_screen(STR_MESSAGE_MAIN_MENU_CAPTION, STR_LOADING_SMS, IMG_GLOBAL_PROGRESS, 0);
 * mmi_msg_entry_processing_generic();
 * if (g_msg_cntx.msg_init)
 * mmi_msg_get_msg_list_inbox();
 * }
 * else
 * mmi_msg_entry_inbox_list();
 * }
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_inbox_list
 * DESCRIPTION
 *  Entry inbox list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_inbox_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    S32 hiliteitem = 0;
#ifdef __MMI_DUAL_SIM_MASTER__
    U16 title;
    U16 left_softkey;
    U16 left_softkey_icon;
    S32 numitem = MTPNP_PFAL_SMS_Get_SMS_List_Size(MMI_FRM_SMS_APP_INBOX);
#else /* __MMI_DUAL_SIM_MASTER__ */
    S32 numitem = mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_INBOX);
#endif /* __MMI_DUAL_SIM_MASTER__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_ID_MSG_PROCESSING))
    {
        HistoryReplace(SCR_ID_MSG_PROCESSING, SCR_ID_MSG_INBOX_LIST, mmi_msg_entry_inbox_list);
        g_msg_cntx.MessagesScrnIdDelUptoHistoryNodes = SCR_ID_MSG_INBOX_LIST;
        return;
    }

	if(numitem == 0)
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_EMPTY,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) EMPTY_LIST_TONE);
        return;
    }
    /* Most cases of entering inbox list while SMS not ready are checked in mmi_msg_pre_entry_inbox_list.
       However, If new MT SMS comes during SMS not ready, after deleting/saving/copying/moving SMS, 
       inbox list cannot be entered and user should go back to idle screen. */
    else if (numitem == MMI_FRM_SMS_INVALID_INDEX)
    {
        DeleteScreenIfPresent(SCR_ID_MSG_INBOX_LIST);
        GoBackHistory();
        return;
    }

    /* Update the totalinbox value in order to get the current inbox list size  */
    msgbox_info.totalinbox = mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_INBOX);

    EntryNewScreen(SCR_ID_MSG_INBOX_LIST, mmi_msg_exit_generic, mmi_msg_entry_inbox_list, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_inbox_list *\n");
    g_msg_cntx.msg_ind_after_call = FALSE;
    SetMessagesCurrScrnID(SCR_ID_MSG_INBOX_LIST);
    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_INBOX_LIST);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_INBOX_LIST);
    RegisterHighlightHandler(GetMsgIndex);
    if (guiBuffer != NULL)
    {
#ifdef __MMI_DUAL_SIM_MASTER__
        S32 currBoxIndex = MTPNP_PFAL_SMS_Get_Current_Index();

        hiliteitem=(currBoxIndex < numitem) ? currBoxIndex : 0;
#else /* __MMI_DUAL_SIM_MASTER__ */
        hiliteitem = (g_msg_cntx.currBoxIndex < numitem) ? g_msg_cntx.currBoxIndex : 0;
#endif /* __MMI_DUAL_SIM_MASTER__ */
        /* change gui buffer content */
        change_cat184_list_menu_history_highlighted_item(hiliteitem, guiBuffer);
    }

#ifndef __MMI_DUAL_SIM_MASTER__
    ShowCategory184Screen(
        STR_SCR6010_CAPTION,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numitem,
        mmi_msg_inbox_list_get_item,
        mmi_msg_inbox_list_get_hint,
        hiliteitem,
        guiBuffer);
#else /* __MMI_DUAL_SIM_MASTER__ */
    switch (MTPNP_AD_SMS_Get_Filter_Rule())
	{
	    case MTPNP_AD_FILTER_MASTER:
		    title = STRING_MTPNP_SMS_MASTER_INBOX;
		    break;

	    case MTPNP_AD_FILTER_SLAVE:
		    title = STRING_MTPNP_SMS_SLAVE_INBOX;
		    break;

	    case MTPNP_AD_FILTER_ALL:
		    title = STR_SCR6010_CAPTION;
		    break;
    }

    if (numitem == 0)
    {
        left_softkey = MTPNP_NULL;
        left_softkey_icon = MTPNP_NULL;
    }
    else
    {
        left_softkey = STR_GLOBAL_OK;
        left_softkey_icon = IMG_GLOBAL_OK;
    }

	ShowCategory184Screen(
        title,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        left_softkey,
        left_softkey_icon,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numitem,
        (GetItemFuncPtr)MTPNP_PFAL_Msg_Inbox_List_Get_Item,
        MTPNP_PFAL_Msg_Inbox_List_Get_Hint,
        hiliteitem,
        guiBuffer);
#endif /* __MMI_DUAL_SIM_MASTER__ */

    SetLeftSoftkeyFunction(mmi_msg_get_msg_inbox, KEY_EVENT_UP);
    SetKeyHandler(mmi_msg_get_msg_inbox, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

#if (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) || defined(__MMI_SMART_MESSAGE_MT__)
    SetRightSoftkeyFunction(mmi_msg_go_to_msg_menu, KEY_EVENT_UP);
    SetKeyHandler(mmi_msg_go_to_msg_menu, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
#else /* (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) || defined(__MMI_SMART_MESSAGE_MT__) */ 
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
#endif /* (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) || defined(__MMI_SMART_MESSAGE_MT__) */ 

#ifdef __MMI_DUAL_SIM_MASTER__
	if (MTPNP_AD_SMS_Get_Show_Style() == MTPNP_AD_SHOW_MIXED)
	{
		switch (MTPNP_AD_SMS_Get_Filter_Rule())
		{
			case MTPNP_AD_FILTER_MASTER:
				SetKeyHandler (mmi_msg_pre_entry_slave_inbox_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
				break;

			case MTPNP_AD_FILTER_SLAVE:
				SetKeyHandler (mmi_msg_pre_entry_master_inbox_list, KEY_LEFT_ARROW, KEY_EVENT_DOWN);				
				break;
		}
	}
	DeleteScreenIfPresent(SCR_ID_MSG_INBOX_LIST);	
#endif /* __MMI_DUAL_SIM_MASTER__ */

}

#if (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) || defined(__MMI_SMART_MESSAGE_MT__)


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_go_to_msg_menu
 * DESCRIPTION
 *  Go back to Messages Menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_go_to_msg_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_nsm_set_msg_type(NORMAL_MESSAGE);   /* Reset message type */
    GoBackHistory();
}

#if (0)
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
#endif /* (0) */ 

#endif /* (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) || defined(__MMI_SMART_MESSAGE_MT__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_inbox_list_get_item
 * DESCRIPTION
 *  Get inbox list item
 * PARAMETERS
 *  item_index          [IN]            
 *  str_buff            [IN]            
 *  img_buff_p          [?]             
 *  str_img_mask        [IN]            
 *  a(?)                [IN]            Item index
 *  d(?)                [IN/OUT]        String image mask
 *  c(?)                [IN/OUT]        Image buffer
 *  b(?)                [IN/OUT]        String buffer
 * RETURNS
 * TRUE
 *****************************************************************************/
pBOOL mmi_msg_inbox_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 temp[(MAX_DIGITS_SMS + 1) * ENCODING_LENGTH];
    S8 *name;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (((mmi_frm_sms_get_status(MMI_FRM_SMS_APP_INBOX, (U16) item_index) & 0xf000) >> 12) == SMSAL_MTI_STATUS_REPORT)
    {
        mmi_ucs2cpy((S8*) str_buff, (S8*) GetString(STR_INBOX_REPORT_ID));
    }
    else
    {
        memset(temp, 0, (MAX_DIGITS_SMS + 1) * ENCODING_LENGTH);
        mmi_asc_n_to_ucs2(temp,
        	(S8*)mmi_frm_sms_get_address(MMI_FRM_SMS_APP_INBOX, (U16)item_index),
        	MAX_DIGITS_SMS);

        name = lookUpNumber(temp);
        if (mmi_ucs2strlen(name))
        {
            mmi_ucs2cpy((S8*) str_buff, name);
        }
        else
        {
            mmi_ucs2cpy((S8*) str_buff, temp);
        }
    }

    if ((mmi_frm_sms_get_status(MMI_FRM_SMS_APP_INBOX, (U16) item_index) & 0x0f) == MMI_FRM_SMS_APP_UNREAD)
    {
        *img_buff_p = get_image(IMG_MESSAGE_UNREAD);
    }
    else
    {
        if (mmi_frm_sms_check_complete(MMI_FRM_SMS_APP_INBOX, (U16) item_index) == TRUE)
        {
            *img_buff_p = get_image(IMG_MESSAGE_READ);
        }
        else
        {
            *img_buff_p = get_image(IMG_MESSAGE_SS_NCOMP);
        }
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_inbox_list_get_hint
 * DESCRIPTION
 *  Get inbox list hint
 * PARAMETERS
 *  item_index      [IN]            
 *  hint_array      [?]             
 *  a(?)            [IN]            Item index
 *  b(?)            [IN/OUT]        Hint array
 * RETURNS
 *  TRUE: display hint, FALSE: not display hint
 *****************************************************************************/
S32 mmi_msg_inbox_list_get_hint(S32 item_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_get_msg_date_time(
        (S8*) hint_array[0],
        NULL,
        mmi_frm_sms_get_timestamp(MMI_FRM_SMS_APP_INBOX, (U16) item_index));
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_pre_entry_outbox_list
 * DESCRIPTION
 *  Before entry outbox list, check if progressing screen is needed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/*
 * U8 mmi_msg_handle_ready_ind_outbox(void* dummy)
 * {
 * mmi_msg_entry_outbox_list();
 * DeleteScreenIfPresent(SCR_ID_MSG_PROCESSING);
 * return FALSE;
 * }
 */
void mmi_msg_pre_entry_outbox_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
	MTPNP_AD_SMS_Set_Filter_Rule(MTPNP_AD_FILTER_ALL);
#endif /* __MMI_DUAL_SIM_MASTER__ */

    if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_OUTBOX) == 0)
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_EMPTY,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) EMPTY_LIST_TONE);
    }
    else if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_OUTBOX) == MMI_FRM_SMS_INVALID_INDEX)
    {
        mmi_msg_set_processing_screen(
            STR_MESSAGE_MAIN_MENU_CAPTION,
            STR_LOADING_SMS,
            IMG_GLOBAL_PROGRESS,
            STR_LOADING_OUTBOX_BACK);
        mmi_msg_entry_processing_generic();
        /* SetInterruptEventHandler(mmi_msg_handle_ready_ind_outbox, NULL, PRT_MSG_ID_MMI_SMS_READY_IND); */
    }
    /* disallow re-entering SMS application when there is a pending SMS job running in the background */
    else if (mmi_frm_sms_check_action_pending())
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_MSG_NOT_READY_YET),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
    }
    else
    {
        mmi_msg_entry_outbox_list();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_outbox_list
 * DESCRIPTION
 *  Entry outbox list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_outbox_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    S32 hiliteitem = 0;
#ifdef __MMI_DUAL_SIM_MASTER__
    U16 title;
    U16 left_softkey;
    U16 left_softkey_icon;
    S32 numitem = MTPNP_PFAL_SMS_Get_SMS_List_Size(MMI_FRM_SMS_APP_OUTBOX);
#else /* __MMI_DUAL_SIM_MASTER__ */
    S32 numitem = mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_OUTBOX);
#endif /* __MMI_DUAL_SIM_MASTER__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_ID_MSG_PROCESSING))
    {
        HistoryReplace(SCR_ID_MSG_PROCESSING, SCR_ID_MSG_OUTBOX_LIST, mmi_msg_entry_outbox_list);
        g_msg_cntx.MessagesScrnIdDelUptoHistoryNodes = SCR_ID_MSG_OUTBOX_LIST;
        return;
    }

	if(numitem == 0)
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_EMPTY,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) EMPTY_LIST_TONE);
        return;
    }
    EntryNewScreen(SCR_ID_MSG_OUTBOX_LIST, mmi_msg_exit_generic, mmi_msg_entry_outbox_list, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*-------[SmsMoMtGuiInterface.c] mmi_msg_entry_outbox_list -------*\n");
    SetMessagesCurrScrnID(SCR_ID_MSG_OUTBOX_LIST);
    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_LIST);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_OUTBOX_LIST);
    RegisterHighlightHandler(GetMsgIndex);
    if (guiBuffer != NULL)
    {
#ifdef __MMI_DUAL_SIM_MASTER__
        S32 currBoxIndex = MTPNP_PFAL_SMS_Get_Current_Index();

        hiliteitem=(currBoxIndex < numitem) ? currBoxIndex : 0;
#else /* __MMI_DUAL_SIM_MASTER__ */
        hiliteitem = (g_msg_cntx.currBoxIndex < numitem) ? g_msg_cntx.currBoxIndex : 0;
#endif /* __MMI_DUAL_SIM_MASTER__ */
        /* change gui buffer content */
        change_cat184_list_menu_history_highlighted_item(hiliteitem, guiBuffer);
    }

#ifndef __MMI_DUAL_SIM_MASTER__
    ShowCategory184Screen(
        STR_SCR6026_CAPTION,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numitem,
        mmi_msg_outbox_list_get_item,
        NULL,
        hiliteitem,
        guiBuffer);
#else /* __MMI_DUAL_SIM_MASTER__ */
    switch (MTPNP_AD_SMS_Get_Filter_Rule())
	{
	    case MTPNP_AD_FILTER_MASTER:
		    title = STRING_MTPNP_SMS_MASTER_OUTBOX;
		    break;

	    case MTPNP_AD_FILTER_SLAVE:
		    title = STRING_MTPNP_SMS_SLAVE_OUTBOX;
		    break;

	    case MTPNP_AD_FILTER_ALL:
		    title = STR_SCR6026_CAPTION;
		    break;
    }

    if (numitem == 0) {
        left_softkey = MTPNP_NULL;
        left_softkey_icon = MTPNP_NULL;
    } else {
        left_softkey = STR_GLOBAL_OK;
        left_softkey_icon = IMG_GLOBAL_OK;
    }

	ShowCategory184Screen(
        title,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        left_softkey,
        left_softkey_icon,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numitem,
        (GetItemFuncPtr)MTPNP_PFAL_Msg_Outbox_List_Get_Item,
        NULL,
        hiliteitem,
        guiBuffer);
#endif /* __MMI_DUAL_SIM_MASTER__ */

    SetLeftSoftkeyFunction(mmi_msg_get_msg_outbox, KEY_EVENT_UP);
    SetKeyHandler(mmi_msg_get_msg_outbox, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

#ifdef __MMI_DUAL_SIM_MASTER__
	if (MTPNP_AD_SMS_Get_Show_Style() == MTPNP_AD_SHOW_MIXED)
	{
		switch (MTPNP_AD_SMS_Get_Filter_Rule())
		{
			case MTPNP_AD_FILTER_MASTER:				
				SetKeyHandler (mmi_msg_pre_entry_slave_outbox_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
				break;

			case MTPNP_AD_FILTER_SLAVE:
				SetKeyHandler (mmi_msg_pre_entry_master_outbox_list, KEY_LEFT_ARROW, KEY_EVENT_DOWN);				
				break;
		}
	}
	DeleteScreenIfPresent(SCR_ID_MSG_OUTBOX_LIST);	
#endif /* __MMI_DUAL_SIM_MASTER__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_outbox_list_get_item
 * DESCRIPTION
 *  Get outbox list item
 * PARAMETERS
 *  item_index          [IN]            
 *  str_buff            [IN]            
 *  img_buff_p          [?]             
 *  str_img_mask        [IN]            
 *  a(?)                [IN]            Item index
 *  b(?)                [IN/OUT]        String image mask
 * RETURNS
 * TRUE
 *****************************************************************************/
pBOOL mmi_msg_outbox_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 temp[(MAX_DIGITS_SMS + 1) * ENCODING_LENGTH];
    S8 *name;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strlen((S8*) mmi_frm_sms_get_address(MMI_FRM_SMS_APP_OUTBOX, (U16) item_index)))
    {
        memset(temp, 0, (MAX_DIGITS_SMS + 1) * ENCODING_LENGTH);
        mmi_asc_n_to_ucs2(temp, 
        	(S8*)mmi_frm_sms_get_address(MMI_FRM_SMS_APP_OUTBOX, (U16)item_index),
        	MAX_DIGITS_SMS);

        name = lookUpNumber(temp);
        if (mmi_ucs2strlen(name))
        {
            mmi_ucs2cpy((S8*) str_buff, name);
        }
        else
        {
            mmi_ucs2cpy((S8*) str_buff, temp);
        }
    }
    else
    {
        mmi_ucs2cpy((S8*) str_buff, (S8*) GetString(STR_OUTBOX_LIST_MESSAGE));
    }

    if (mmi_frm_sms_check_complete(MMI_FRM_SMS_APP_OUTBOX, (U16) item_index) == FALSE)
    {
        *img_buff_p = get_image(IMG_MESSAGE_SS_NCOMP);
    }
    else
    {
        if ((mmi_frm_sms_get_status(MMI_FRM_SMS_APP_OUTBOX, (U16) item_index) & 0x0f) == MMI_FRM_SMS_APP_OUTBOX)
        {
            *img_buff_p = get_image(IMG_MESSAGE_SENT);
        }
        else
        {
            *img_buff_p = get_image(IMG_MESSAGE_UNSENT);
        }
    }

    return TRUE;
}

#ifdef __MMI_MESSAGES_DRAFT_BOX__


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_pre_entry_draftbox_list
 * DESCRIPTION
 *  Before entry draftbox list, check if progressing screen is needed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/*
 * U8 mmi_msg_handle_ready_ind_draftbox(void* dummy)
 * {
 * mmi_msg_entry_draftbox_list();
 * DeleteScreenIfPresent(SCR_ID_MSG_PROCESSING);
 * return FALSE;
 * }
 */
void mmi_msg_pre_entry_draftbox_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_DRAFTS) == 0)
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_EMPTY,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) EMPTY_LIST_TONE);
    }
    else if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_DRAFTS) == MMI_FRM_SMS_INVALID_INDEX)
    {
        mmi_msg_set_processing_screen(
            STR_MESSAGE_MAIN_MENU_CAPTION,
            STR_LOADING_SMS,
            IMG_GLOBAL_PROGRESS,
            STR_LOADING_DRAFTBOX_BACK);
        mmi_msg_entry_processing_generic();
        /* SetInterruptEventHandler(mmi_msg_handle_ready_ind_draftbox, NULL, PRT_MSG_ID_MMI_SMS_READY_IND); */
    }
    /* disallow re-entering SMS application when there is a pending SMS job running in the background */
    else if (mmi_frm_sms_check_action_pending())
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_MSG_NOT_READY_YET),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
    }
    else
    {
        mmi_msg_entry_draftbox_list();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_draftbox_list
 * DESCRIPTION
 *  Entry draftbox list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_draftbox_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    S32 hiliteitem = 0;
    S32 numitem = mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_DRAFTS);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_ID_MSG_PROCESSING))
    {
        HistoryReplace(SCR_ID_MSG_PROCESSING, SCR_ID_MSG_DRAFTBOX_LIST, mmi_msg_entry_draftbox_list);
        g_msg_cntx.MessagesScrnIdDelUptoHistoryNodes = SCR_ID_MSG_DRAFTBOX_LIST;
        return;
    }
    if (numitem == 0)
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_EMPTY,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) EMPTY_LIST_TONE);
        return;
    }
    EntryNewScreen(SCR_ID_MSG_DRAFTBOX_LIST, mmi_msg_exit_generic, mmi_msg_entry_draftbox_list, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_draftbox_list *\n");
    SetMessagesCurrScrnID(SCR_ID_MSG_DRAFTBOX_LIST);
    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DRAFTBOX_LIST);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_DRAFTBOX_LIST);
    RegisterHighlightHandler(GetMsgIndex);
    if (guiBuffer != NULL)
    {
        hiliteitem = (g_msg_cntx.currBoxIndex < numitem) ? g_msg_cntx.currBoxIndex : 0;
        /* change gui buffer content */
        change_cat184_list_menu_history_highlighted_item(hiliteitem, guiBuffer);
    }
    ShowCategory184Screen(
        STR_DRAFTBOX_MENUENTRY,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numitem,
        mmi_msg_draftbox_list_get_item,
        NULL,
        hiliteitem,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_msg_get_msg_draftbox, KEY_EVENT_UP);
    SetKeyHandler(mmi_msg_get_msg_draftbox, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_draftbox_list_get_item
 * DESCRIPTION
 *  Get draftbox list item
 * PARAMETERS
 *  item_index          [IN]            
 *  str_buff            [IN]            
 *  img_buff_p          [?]             
 *  str_img_mask        [IN]            
 *  a(?)                [IN]            Item index
 *  b(?)                [IN/OUT]        String image mask
 * RETURNS
 * TRUE
 *****************************************************************************/
pBOOL mmi_msg_draftbox_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 temp[(MAX_DIGITS_SMS + 1) * ENCODING_LENGTH];
    S8 *name;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strlen((S8*) mmi_frm_sms_get_address(MMI_FRM_SMS_APP_DRAFTS, (U16) item_index)))
    {
        memset(temp, 0, (MAX_DIGITS_SMS + 1) * ENCODING_LENGTH);
        mmi_asc_n_to_ucs2(temp,
        	(S8*)mmi_frm_sms_get_address(MMI_FRM_SMS_APP_DRAFTS, (U16)item_index),
        	MAX_DIGITS_SMS);

        name = lookUpNumber(temp);
        if (mmi_ucs2strlen(name))
        {
            mmi_ucs2cpy((S8*) str_buff, name);
        }
        else
        {
            mmi_ucs2cpy((S8*) str_buff, temp);
        }
    }
    else
    {
        mmi_ucs2cpy((S8*) str_buff, (S8*) GetString(STR_OUTBOX_LIST_MESSAGE));
    }

    if (mmi_frm_sms_check_complete(MMI_FRM_SMS_APP_DRAFTS, (U16) item_index) == FALSE)
    {
        *img_buff_p = get_image(IMG_MESSAGE_SS_NCOMP);
    }
    else
    {
        *img_buff_p = get_image(IMG_MESSAGE_UNSENT);
    }

    return TRUE;
}
#endif /* __MMI_MESSAGES_DRAFT_BOX__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_inbox_header
 * DESCRIPTION
 *  Get inbox message header
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 *mmi_msg_get_inbox_header(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static S8 buffer[120 * ENCODING_LENGTH];
    S8 buf2[10];
    S8 temp[MAX_DIGITS * ENCODING_LENGTH];
    S8 number[(MAX_DIGITS_SMS + 1) * ENCODING_LENGTH];
    S8 *name;
    S8 ts_date[(MAX_TIMESTAMP_SIZE + 1) * ENCODING_LENGTH];
    S8 ts_time[(MAX_TIMESTAMP_SIZE + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_to_ucs2(buf2, "\n");
    if (PendingSaveSendData.mti == SMSAL_MTI_STATUS_REPORT)
    {
        if (PendingSaveSendData.st == ST_COMP_MSG_RECV_BY_SME)
        {
            mmi_ucs2cpy(buffer, GetString(STR_SR_DELIVERD_ID));
        }
        else
        {
            mmi_ucs2cpy(buffer, GetString(STR_SR_PENDING_ID));
        }
    }
    else
    {
        mmi_ucs2cpy(buffer, GetString(STR_SMS_MESSAGE_HEADER_FROM));
    }
    mmi_ucs2cat(buffer, buf2);

    memset(number, 0, (MAX_DIGITS_SMS + 1) * ENCODING_LENGTH);
    /* if SMS is not ready */
    if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_INBOX) == MMI_FRM_SMS_INVALID_INDEX)
    {
        mmi_asc_n_to_ucs2(number,
        	(S8*)mmi_frm_sms_get_address(MMI_FRM_SMS_APP_NOBOX, g_msg_cntx.msg_ind_index),
        	MAX_DIGITS_SMS);
    }
    else
    {
        mmi_asc_n_to_ucs2(
            number,
            (S8*) mmi_frm_sms_get_address(MMI_FRM_SMS_APP_INBOX, (U16)g_msg_cntx.currBoxIndex),
            MAX_DIGITS_SMS);
    }
    mmi_ucs2cpy(temp, number);
    name = lookUpNumber(temp);
    if (mmi_ucs2strlen(name))
    {
        mmi_ucs2cat(buffer, name);
    }
    else
    {
        mmi_ucs2cat(buffer, temp);
    }

    /* if SMS is not ready */
    if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_INBOX) == MMI_FRM_SMS_INVALID_INDEX)
    {
        mmi_msg_get_msg_date_time(
            ts_date,
            ts_time,
            mmi_frm_sms_get_timestamp(MMI_FRM_SMS_APP_NOBOX, g_msg_cntx.msg_ind_index));
    }
    else
    {
        mmi_msg_get_msg_date_time(
            ts_date,
            ts_time,
            mmi_frm_sms_get_timestamp(MMI_FRM_SMS_APP_INBOX, (U16) g_msg_cntx.currBoxIndex));
    }
    mmi_ucs2cat(buffer, buf2);
    mmi_ucs2cat(buffer, ts_date);
    mmi_ucs2cat(buffer, buf2);
    mmi_ucs2cat(buffer, ts_time);
    mmi_ucs2cat(buffer, buf2);

    return (U8*) buffer;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_go_back_from_inbox_msg
 * DESCRIPTION
 *  Entry inbox message screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_go_back_from_inbox_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_INBOX) != MMI_FRM_SMS_INVALID_INDEX)
    {
        GoBackHistory();
    }
    else
    {
        ExecCurrEndKeyDownHandler();
    }
}


#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
U8 *mmi_msg_get_archive_inbox_header(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static S8 buffer[120 * ENCODING_LENGTH];
    S8 buf2[10];
    S8 temp[MAX_DIGITS * ENCODING_LENGTH];
    S8 number[(MAX_DIGITS_SMS + 1) * ENCODING_LENGTH];
    S8 *name;
    S8 ts_date[(MAX_TIMESTAMP_SIZE + 1) * ENCODING_LENGTH];
    S8 ts_time[(MAX_TIMESTAMP_SIZE + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_to_ucs2(buf2, "\n");
        mmi_ucs2cpy(buffer, GetString(STR_SMS_MESSAGE_HEADER_FROM));
    mmi_ucs2cat(buffer, buf2);

    memset(number, 0, (MAX_DIGITS_SMS + 1) * ENCODING_LENGTH);
    mmi_asc_n_to_ucs2(
    		number,
            (S8*)mmi_frm_sms_get_address(MMI_FRM_SMS_APP_ARCHIVE, (U16)g_msg_cntx.currBoxIndex),
            MAX_DIGITS_SMS);
   
    mmi_ucs2cpy(temp, number);
    name = lookUpNumber(temp);
    if (mmi_ucs2strlen(name))
    {
        mmi_ucs2cat(buffer, name);
    }
    else
    {
        mmi_ucs2cat(buffer, temp);
    }

    mmi_msg_get_msg_date_time(
            ts_date,
            ts_time,
            mmi_frm_sms_get_timestamp(MMI_FRM_SMS_APP_ARCHIVE, (U16) g_msg_cntx.currBoxIndex));
    
    mmi_ucs2cat(buffer, buf2);
    mmi_ucs2cat(buffer, ts_date);
    mmi_ucs2cat(buffer, buf2);
    mmi_ucs2cat(buffer, ts_time);
    mmi_ucs2cat(buffer, buf2);

    return (U8*) buffer;
}


U8 *mmi_msg_get_archive_outbox_header(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static S8 buffer[100 * ENCODING_LENGTH];
    S8 buf2[10];
    S8 temp[MAX_DIGITS * ENCODING_LENGTH];
    S8 number[(MAX_DIGITS_SMS + 1) * ENCODING_LENGTH];
    S8 *name;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_asc_to_ucs2(buf2, "\n");
        mmi_ucs2cpy(buffer, GetString(STR_SMS_MESSAGE_HEADER_TO));
        mmi_asc_to_ucs2(buf2, "\n");
        mmi_ucs2cat(buffer, buf2);

    if (mmi_ucs2strlen((S8*) mmi_frm_sms_get_address(MMI_FRM_SMS_APP_ARCHIVE, (U16) g_msg_cntx.currBoxIndex)))
    {
    	memset(number, 0, (MAX_DIGITS_SMS + 1) * ENCODING_LENGTH);
        mmi_asc_n_to_ucs2(number,
        	(S8*) mmi_frm_sms_get_address(MMI_FRM_SMS_APP_ARCHIVE, (U16) g_msg_cntx.currBoxIndex),
        	MAX_DIGITS_SMS);
        mmi_ucs2cpy(temp, number);

        name = lookUpNumber(temp);
        if (mmi_ucs2strlen(name))
        {
            mmi_ucs2cat(buffer, name);
        }
        else
        {
            mmi_ucs2cat(buffer, temp);
        }
    }
    else
    {
        mmi_ucs2cpy(temp, GetString(STR_OUTBOX_LIST_MESSAGE));
        mmi_ucs2cat(buffer, temp);
    }

    mmi_ucs2cat(buffer, buf2);

    return (U8*) buffer;
}


void mmi_msg_entry_archive_msg_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 *pHeader;
    EMSData *pEms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* in case there is an interrupt cut in before displaying message content */
    if (IsScreenPresent(SCR_ID_MSG_PROCESSING))
    {
        HistoryReplace(SCR_ID_MSG_PROCESSING, SCR_ID_MSG_ARCHIVE_INBOX_MSG, mmi_msg_entry_archive_msg_inbox);
        return;
    }
    EntryNewScreen(SCR_ID_MSG_ARCHIVE_INBOX_MSG, mmi_msg_exit_generic, mmi_msg_entry_archive_msg_inbox, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_archive_msg_inbox *\n");

#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
    if (IsScreenPresent(SCR_ID_MSG_ARCHIVE_LIST_OPTION))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_ARCHIVE_LIST_OPTION);
    }
    else
#endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_ARCHIVE_INBOX_MSG);
    }

    SetMessagesCurrScrnID(SCR_ID_MSG_ARCHIVE_INBOX_MSG);
    GetCurrEndKeyDownHandler();

    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_ARCHIVE_INBOX_MSG);
    GetEMSDataForView(&pEms, 0);
    pHeader = mmi_msg_get_archive_inbox_header();
    g_msg_cntx.number_from_phb = 0;
#if defined(__MMI_MESSAGES_EMS__)
    EnableDisableAudioPlayback();
#endif 

    ShowCategory39Screen(
        STR_SCR6024_CAPTION,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OPTIONS,
        IMG_SMS_COMMON_NOIMAGE,
        STR_GLOBAL_BACK,
        IMG_SMS_COMMON_NOIMAGE,
        pEms,
        pHeader,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_msg_entry_option_archive_inbox, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_archive_msg_outbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_msg_entry_archive_msg_outbox(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 *pHeader;
    EMSData *pEms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* in case there is an interrupt cut in before displaying message content */
    if (IsScreenPresent(SCR_ID_MSG_PROCESSING))
    {
        HistoryReplace(SCR_ID_MSG_PROCESSING, SCR_ID_MSG_ARCHIVE_OUTBOX_MSG, mmi_msg_entry_archive_msg_outbox);
        return;
    }
    EntryNewScreen(SCR_ID_MSG_ARCHIVE_OUTBOX_MSG, mmi_msg_exit_generic, mmi_msg_entry_archive_msg_outbox, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_archive_msg_outbox*\n");

#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
    if (IsScreenPresent(SCR_ID_MSG_ARCHIVE_LIST_OPTION))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_ARCHIVE_LIST_OPTION);
    }
    else
#endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_ARCHIVE_OUTBOX_MSG);
    }
    
    SetMessagesCurrScrnID(SCR_ID_MSG_ARCHIVE_OUTBOX_MSG);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_ARCHIVE_OUTBOX_MSG);
    GetEMSDataForView(&pEms, 0);
    pHeader = mmi_msg_get_archive_outbox_header();
    g_msg_cntx.number_from_phb = 0;

#if defined(__MMI_MESSAGES_EMS__)
    EnableDisableAudioPlayback();
#endif 
    ShowCategory39Screen(
        STR_SCR6024_CAPTION,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OPTIONS,
        IMG_SMS_COMMON_NOIMAGE,
        STR_GLOBAL_BACK,
        IMG_SMS_COMMON_NOIMAGE,
        pEms,
        pHeader,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_msg_entry_option_archive_outbox, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_inbox_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_inbox_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 *pHeader;
    EMSData *pEms;
    U16 strtitle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* in case there is an interrupt cut in before displaying message content */
    if (IsScreenPresent(SCR_ID_MSG_PROCESSING))
    {
        HistoryReplace(SCR_ID_MSG_PROCESSING, SCR_ID_MSG_INBOX_MSG, mmi_msg_entry_inbox_msg);
        return;
    }
    EntryNewScreen(SCR_ID_MSG_INBOX_MSG, mmi_msg_exit_generic, mmi_msg_entry_inbox_msg, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_inbox_msg *\n");

#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
    if (IsScreenPresent(SCR_ID_MSG_INBOX_LIST_OPTION))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_INBOX_LIST_OPTION);
    }
    else
#endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_INBOX_MSG);
    }

    SetMessagesCurrScrnID(SCR_ID_MSG_INBOX_MSG);
    GetCurrEndKeyDownHandler();

    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_INBOX_MSG);
    GetEMSDataForView(&pEms, 0);
    pHeader = mmi_msg_get_inbox_header();
    g_msg_cntx.number_from_phb = 0;
#if defined(__MMI_MESSAGES_EMS__)
    EnableDisableAudioPlayback();
#endif 
#ifdef __MMI_MESSAGES_CHAT__
    if (pEms->listHead == NULL)
    {
    	if (gChatInvitation)
    	{
            SetChatInboxIndex(PendingSaveSendData.msgboxindex);
            strtitle = STR_CHAT_INVITATION;
		}
		else if (CheckForInvitationMsg(pEms->textBuffer, (S32) pEms->textLength, TRUE) == TRUE)
		{
            SetChatInboxIndex(PendingSaveSendData.msgboxindex);
            strtitle = STR_CHAT_INVITATION;		

			if (guiBuffer == NULL)
			{
				RemoveInvitationChar();
			}
		}
        else
        {
            strtitle = STR_SCR6024_CAPTION;
            gChatInvitation = 0;
        }
    }
    else
    {
        strtitle = STR_SCR6024_CAPTION;
        gChatInvitation = 0;
    }
#else /* __MMI_MESSAGES_CHAT__ */ 
    strtitle = STR_SCR6024_CAPTION;
#endif /* __MMI_MESSAGES_CHAT__ */ 
    ShowCategory39Screen(
        (U16) strtitle,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OPTIONS,
        IMG_SMS_COMMON_NOIMAGE,
        STR_GLOBAL_BACK,
        IMG_SMS_COMMON_NOIMAGE,
        pEms,
        pHeader,
        guiBuffer);
#ifdef __MMI_MESSAGES_CHAT__
    if (strtitle == STR_CHAT_INVITATION)
    {
        SetLeftSoftkeyFunction(mmi_msg_entry_option_chat, KEY_EVENT_UP);
    }
    else
    {
        SetLeftSoftkeyFunction(mmi_msg_entry_option_inbox, KEY_EVENT_UP);
    }
#else /* __MMI_MESSAGES_CHAT__ */ 
    SetLeftSoftkeyFunction(mmi_msg_entry_option_inbox, KEY_EVENT_UP);
#endif /* __MMI_MESSAGES_CHAT__ */ 

    SetLeftSoftkeyFunction(mmi_msg_entry_option_inbox, KEY_EVENT_UP);  // TODO: smsnote: overwrite LSK func?? (Tony said: old bug. keep it)
    SetRightSoftkeyFunction(mmi_msg_go_back_from_inbox_msg, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_outbox_header
 * DESCRIPTION
 *  Get outbox message header
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 *mmi_msg_get_outbox_header(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static S8 buffer[100 * ENCODING_LENGTH];
    S8 buf2[10];
    S8 temp[MAX_DIGITS * ENCODING_LENGTH];
    S8 number[(MAX_DIGITS_SMS + 1) * ENCODING_LENGTH];
    S8 *name;
    U16 msgtype = MMI_FRM_SMS_APP_OUTBOX;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UNIFIED_MESSAGE__
    if (g_msg_cntx.toDisplayMessageList == TO_DISPLAY_MESSAGE_LIST_UNSENTBOX)
    {
        msgtype = MMI_FRM_SMS_APP_UNSENT;
    }
#endif /* __MMI_UNIFIED_MESSAGE__ */

#ifdef __MMI_MESSAGES_DRAFT_BOX__
    if (g_msg_cntx.toDisplayMessageList == TO_DISPLAY_MESSAGE_LIST_DRAFTBOX)
    {
        msgtype = MMI_FRM_SMS_APP_DRAFTS;
    }
#endif /* __MMI_MESSAGES_DRAFT_BOX__ */

    mmi_asc_to_ucs2(buf2, "\n");
    if (PendingSaveSendData.mti == SMSAL_MTI_UNSPECIFIED)
    {
        mmi_ucs2cpy(buffer, GetString(STR_SMS_DOES_NOT_SUPPORT));
    }

    else
    {
        mmi_ucs2cpy(buffer, GetString(STR_SMS_MESSAGE_HEADER_TO));
        mmi_asc_to_ucs2(buf2, "\n");
        mmi_ucs2cat(buffer, buf2);

        if (mmi_ucs2strlen((S8*) mmi_frm_sms_get_address(msgtype, (U16) g_msg_cntx.currBoxIndex)))
        {
    		memset(number, 0, (MAX_DIGITS_SMS + 1) * ENCODING_LENGTH);
            mmi_asc_n_to_ucs2(number,
            	(S8*)mmi_frm_sms_get_address(msgtype, (U16)g_msg_cntx.currBoxIndex),
            	MAX_DIGITS_SMS);
            mmi_ucs2cpy(temp, number);

            name = lookUpNumber(temp);
            if (mmi_ucs2strlen(name))
            {
                mmi_ucs2cat(buffer, name);
            }
            else
            {
                mmi_ucs2cat(buffer, temp);
            }
        }
        else
        {
            mmi_ucs2cpy(temp, GetString(STR_OUTBOX_LIST_MESSAGE));
            mmi_ucs2cat(buffer, temp);
        }
    }

    mmi_ucs2cat(buffer, buf2);

    return (U8*) buffer;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_outbox_msg
 * DESCRIPTION
 *  Entry outbox message screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_outbox_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 *pHeader;
    EMSData *pEms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* in case there is an interrupt cut in before displaying message content */
    if (IsScreenPresent(SCR_ID_MSG_PROCESSING))
    {
        HistoryReplace(SCR_ID_MSG_PROCESSING, SCR_ID_MSG_OUTBOX_MSG, mmi_msg_entry_outbox_msg);
        return;
    }
    EntryNewScreen(SCR_ID_MSG_OUTBOX_MSG, mmi_msg_exit_generic, mmi_msg_entry_outbox_msg, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_outbox_msg*\n");

#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
    if (IsScreenPresent(SCR_ID_MSG_OUTBOX_LIST_OPTION))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_LIST_OPTION);
    }
    else
#endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_MSG);
    }
    
    SetMessagesCurrScrnID(SCR_ID_MSG_OUTBOX_MSG);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_OUTBOX_MSG);
    GetEMSDataForView(&pEms, 0);
    pHeader = mmi_msg_get_outbox_header();
    g_msg_cntx.number_from_phb = 0;

#if defined(__MMI_MESSAGES_EMS__)
    EnableDisableAudioPlayback();
#endif 
    ShowCategory39Screen(
        STR_SCR6024_CAPTION,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OPTIONS,
        IMG_SMS_COMMON_NOIMAGE,
        STR_GLOBAL_BACK,
        IMG_SMS_COMMON_NOIMAGE,
        pEms,
        pHeader,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_msg_entry_option_outbox, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_default_msg
 * DESCRIPTION
 *  Entry default message screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_default_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 *pHeader;
    U8 lHeader;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* in case there is an interrupt cut in before displaying message content */
    if (IsScreenPresent(SCR_ID_MSG_PROCESSING))
    {
        HistoryReplace(SCR_ID_MSG_PROCESSING, SCR_ID_MSG_DEFAULT_MSG, mmi_msg_entry_default_msg);
        return;
    }
    EntryNewScreen(SCR_ID_MSG_DEFAULT_MSG, mmi_msg_exit_generic, mmi_msg_entry_default_msg, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_default_msg*\n");

    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_DEFAULT_MSG);

#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
    if (IsScreenPresent(SCR_ID_MSG_DEFAULT_LIST_OPTION))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_LIST_OPTION);
    }
    else
#endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_MSG);
    }    
    
    SetMessagesCurrScrnID(SCR_ID_MSG_DEFAULT_MSG);

    if (PendingSaveSendData.mti == SMSAL_MTI_STATUS_REPORT)
    {
        pHeader = mmi_msg_get_inbox_header();
    }
    else
    {
        pHeader = mmi_msg_get_outbox_header();
    }
    lHeader = (mmi_ucs2strlen((S8*) pHeader) + 1) * ENCODING_LENGTH;
    ShowCategory74Screen(
        STR_SCR6024_CAPTION,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OPTIONS,
        IMG_SMS_COMMON_NOIMAGE,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        pHeader,
        lHeader,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_msg_entry_option_default, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_save_use_number
 * DESCRIPTION
 *  Save use number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_save_use_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_save_use_number*\n");
    if (mmi_ucs2strlen(g_msg_cntx.numbersList[g_msg_cntx.currHiliteIndex]))
    {
        SaveNumberFromIdleScrn(g_msg_cntx.numbersList[g_msg_cntx.currHiliteIndex], 0);
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
    }
}

#ifdef __MMI_DUAL_SIM_MASTER__
/*****************************************************************************
 * FUNCTION
 *  mmi_msg_dial_use_number_dial
 * DESCRIPTION
 *  Dial use number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_dial_use_number_dial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_dial_use_number_dial*\n");
    MakeCall(g_msg_cntx.numbersList[g_msg_cntx.currHiliteIndex]);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_dial_use_number
 * DESCRIPTION
 *  Dial use number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_dial_use_number_ext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_dial_use_number_ext *\n");
    if (mmi_ucs2strlen(g_msg_cntx.numbersList[g_msg_cntx.currHiliteIndex]))
    { 
        mmi_ucm_app_entry_dial_option((U8 *)g_msg_cntx.numbersList[g_msg_cntx.currHiliteIndex], NULL, NULL);
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
    }
}
#endif /* __MMI_DUAL_SIM_MASTER__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_dial_use_number
 * DESCRIPTION
 *  Dial use number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_dial_use_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_dial_use_number *\n");
    if (mmi_ucs2strlen(g_msg_cntx.numbersList[g_msg_cntx.currHiliteIndex]))
    {
        MakeCall(g_msg_cntx.numbersList[g_msg_cntx.currHiliteIndex]);
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_send_sms_use_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  name        [?]     
 *  number      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_send_sms_use_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	PS8 number = (PS8)g_msg_cntx.numbersList[g_msg_cntx.currHiliteIndex]; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_send_sms_use_number *\n");	

	if (mmi_ucs2strlen(number))
    {
	    if (mmi_ucs2strlen((PS8) number) > (MAX_DIGITS_SMS - 1))
	    {
	        DisplayPopup(
	            (PU8) GetString(STR_SMS_NUM_LEN_EXCEEDED),
	            IMG_GLOBAL_UNFINISHED,
	            1,
	            PHB_NOTIFY_TIMEOUT,
	            (U8) ERROR_TONE);
	        return;
	    } 
		
		memset(g_msg_cntx.smsPhoneNumber, 0, (MAX_DIGITS + 1) * ENCODING_LENGTH);
	    if (number)
	    {
	        mmi_ucs2_n_to_asc(
	            (S8*) g_msg_cntx.smsPhoneNumber,
	            (S8*) number,
	            (MAX_DIGITS + 1) * ENCODING_LENGTH);
	    }
		
    	ReleaseEMSEditBuffer();
		
	#ifdef __MMI_UNIFIED_COMPOSER__
		mmi_msg_entry_uc((U8*)g_msg_cntx.smsPhoneNumber , (U16)MMI_UC_STATE_WRITE_NEW_MSG, (U16)g_msg_cntx.currBoxIndex, (U16)MMI_UC_MSG_TYPE_SMS_ONLY);
    #else /* __MMI_UNIFIED_COMPOSER__ */
        g_msg_cntx.sendMessageCase = SEND_CASE_SEND_FROM_USE_NUMBER;
        mmi_msg_entry_write_msg();
    #endif /* __MMI_UNIFIED_COMPOSER__ */		
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
    }
}

#if defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__)
/*****************************************************************************
 * FUNCTION
 *  mmi_msg_dial_use_voip_number
 * DESCRIPTION
 *  Dial use number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_dial_use_voip_number(void)
{
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_dial_use_number_by_wlan*\n");
    if (mmi_ucs2strlen(g_msg_cntx.numbersList[g_msg_cntx.currHiliteIndex]))
    {
        mmi_voip_app_make_call((PU8) g_msg_cntx.numbersList[g_msg_cntx.currHiliteIndex]);
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
    }
}
#endif /* defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_use_number
 * DESCRIPTION
 *  Entry use number list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_use_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 numbersCount = 0;
    U8 *guiBuffer = NULL;
    EMSData *pEMS;
    S8 number[(MAX_DIGITS_SMS + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_use_number *\n");

    pEMS = GetEMSDataForView(0, 0);
#ifdef __MMI_MESSAGES_CHAT__
    if (IsScreenPresent(CHAT_ROOM_SCREEN_ID))
    {
        numbersCount = ChatUseNumberScreen();
    }
    else
#endif /* __MMI_MESSAGES_CHAT__ */ 
    {
        U16 type = MMI_FRM_SMS_APP_NOBOX;

        if (g_msg_cntx.toDisplayMessageList == TO_DISPLAY_MESSAGE_LIST_INBOX)
        {
            type = MMI_FRM_SMS_APP_INBOX;
        }
        else if (g_msg_cntx.toDisplayMessageList == TO_DISPLAY_MESSAGE_LIST_OUTBOX)
        {
            type = MMI_FRM_SMS_APP_OUTBOX;
        }
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        else if (g_msg_cntx.toDisplayMessageList == TO_DISPLAY_MESSAGE_LIST_ARCHIVE)
        {
            type = MMI_FRM_SMS_APP_ARCHIVE;
        }
#endif

#ifdef __MMI_UNIFIED_MESSAGE__
	    else if (g_msg_cntx.toDisplayMessageList == TO_DISPLAY_MESSAGE_LIST_UNSENTBOX)
	    {
	        type = MMI_FRM_SMS_APP_UNSENT;
	    }
#endif /* __MMI_UNIFIED_MESSAGE__ */

    #ifdef __MMI_MESSAGES_DRAFT_BOX__
        else
        {
            type = MMI_FRM_SMS_APP_DRAFTS;
        }
    #endif /* __MMI_MESSAGES_DRAFT_BOX__ */ 

    	memset(number, 0, (MAX_DIGITS_SMS + 1) * ENCODING_LENGTH);
        /* if SMS is not ready */
        if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_INBOX) == MMI_FRM_SMS_INVALID_INDEX)
        {
            mmi_asc_n_to_ucs2(
                number,
                (S8*)mmi_frm_sms_get_address(MMI_FRM_SMS_APP_NOBOX, g_msg_cntx.msg_ind_index),
                MAX_DIGITS_SMS);
        }
        else
        {
            mmi_asc_n_to_ucs2(number,
            	(S8*)mmi_frm_sms_get_address(type, (U16)g_msg_cntx.currBoxIndex),
            	MAX_DIGITS_SMS);
        }

    #ifdef __MMI_SMART_MESSAGE_MT__
        if (mmi_nsm_get_msg_type() == PICTURE_MESSAGE)  /* JP patch for tracker issue 929 */
        {
            numbersCount = ObtainNumbersFromMessageText((S8*) number, TextBuffer, sizeof(TextBuffer), 0);
        }
        else
    #endif /* __MMI_SMART_MESSAGE_MT__ */

        if (PendingSaveSendData.mti == SMSAL_MTI_UNSPECIFIED)
        {
            /* For unsupport content, do not parse msg content. */
            numbersCount = ObtainNumbersFromMessageText((S8*) number, NULL, 0, 0);
        }
        else
        {
            numbersCount = ObtainNumbersFromMessageText((S8*) number, pEMS->textBuffer, pEMS->textLength, 0);
        }
    }

    if (numbersCount > 0)
    {
        EntryNewScreen(SCR_ID_MSG_USE_NUMBER_LIST, mmi_msg_exit_generic, mmi_msg_entry_use_number, NULL);

        guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_USE_NUMBER_LIST);
        RegisterHighlightHandler(GetHiliteIndex);
        SetMessagesCurrScrnID(SCR_ID_MSG_USE_NUMBER_LIST);

        ShowCategory53Screen(
            STR_USE_NUMBER_CAPTION,
            IMG_SMS_ENTRY_SCRN_CAPTION,
            STR_GLOBAL_OPTIONS,
            IMG_SMS_COMMON_NOIMAGE,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            numbersCount,
            (U8 **) g_msg_cntx.numbersList,
            (U16*) gIndexIconsImageList,
            NULL,
            0,
            0,
            guiBuffer);
        SetLeftSoftkeyFunction(mmi_msg_entry_use_number_option, KEY_EVENT_UP);
        SetKeyHandler(mmi_msg_entry_use_number_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    #if defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__)
        if (mmi_netset_get_active_preferred_mode() == P_WLAN_ONLY || mmi_netset_get_active_preferred_mode() == P_WLAN_PREFERRED)
            SetKeyHandler(mmi_msg_dial_use_voip_number, KEY_SEND, KEY_EVENT_UP);
        else
    #endif /* defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__) */
		#ifdef __MMI_DUAL_SIM_MASTER__
   	     	MTPNP_PFAL_CC_HandleSendKeys(mmi_msg_dial_use_number,KEY_EVENT_UP);
		#else /* __MMI_DUAL_SIM_MASTER__ */
            SetKeyHandler(mmi_msg_dial_use_number, KEY_SEND, KEY_EVENT_UP);
		#endif /* __MMI_DUAL_SIM_MASTER__ */
		#ifdef __LSK_KEYSEND2_IN_ONE__
       		MTPNP_PFAL_CC_RegShareKeyHandler(KEY_EVENT_UP);
        #endif/*__LSK_KEYSEND2_IN_ONE__*/
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_NONUMBER_NOTIFICATION),
            IMG_GLOBAL_EMPTY,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) EMPTY_LIST_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_use_number_option
 * DESCRIPTION
 *  Entry use number list option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_use_number_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_USE_NUMBER_OPTION, mmi_msg_exit_generic, mmi_msg_entry_use_number_option, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_use_number_option*\n");
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_USE_NUMBER_OPTION);

    numItems = GetNumOfChild(SMS_USE_NUMBER_OPTIONS_MENUID);
    GetSequenceStringIds(SMS_USE_NUMBER_OPTIONS_MENUID, nStrItemList);
    SetParentHandler(SMS_USE_NUMBER_OPTIONS_MENUID);

    mmi_ucs2cpy(g_msg_cntx.smsPhoneNumber, (S8*) g_msg_cntx.numbersList[g_msg_cntx.currHiliteIndex]);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    SetMessagesCurrScrnID(SCR_ID_MSG_USE_NUMBER_OPTION);
    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_USE_NUMBER_OPTION);

    ShowCategory52Screen(
        STR_USE_NUMBER_OPT_CAPTION,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_save_use_number
 * DESCRIPTION
 *  Highlight save use number handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_save_use_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_save_use_number,
        GoBackHistory);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_send_sms_use_number
 * DESCRIPTION
 *  Highlight send sms use number handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_send_sms_use_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_send_sms_use_number,
        GoBackHistory);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_dial_use_number
 * DESCRIPTION
 *  Highlight dial use number handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_dial_use_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__)
    switch (mmi_netset_get_active_preferred_mode())
    {
        case P_WLAN_ONLY:
            mmi_msg_highlight_generic(
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                mmi_msg_dial_use_voip_number,
                GoBackHistory);
            ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            break;

        case P_GSM_PREFERRED:
        case P_WLAN_PREFERRED:
            mmi_msg_highlight_generic(
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                mmi_netset_entry_dial_mode_selection,
                GoBackHistory);
            ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
		#ifndef __MMI_DUAL_SIM_MASTER__
            mmi_netset_register_call_entry_func(mmi_msg_dial_use_number, mmi_msg_dial_use_voip_number);
		#else /* __MMI_DUAL_SIM_MASTER__ */
	     	mmi_netset_register_call_entry_func(mmi_msg_dial_use_number_ext, mmi_msg_dial_use_voip_number);
		#endif /* __MMI_DUAL_SIM_MASTER__ */
            break;

        case P_GSM_ONLY:
        default:
            mmi_msg_highlight_generic(
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
          #ifndef __MMI_DUAL_SIM_MASTER__
            mmi_msg_dial_use_number,
          #else /* __MMI_DUAL_SIM_MASTER__ */
		  	mmi_msg_dial_use_number_ext,
          #endif /* __MMI_DUAL_SIM_MASTER__ */
                GoBackHistory);
            ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            break;
    }
#else /* defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__) */
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
  #ifndef __MMI_DUAL_SIM_MASTER__
        mmi_msg_dial_use_number,
  #else /* __MMI_DUAL_SIM_MASTER__ */
        mmi_msg_dial_use_number_ext,
  #endif /* __MMI_DUAL_SIM_MASTER__ */
        GoBackHistory);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#endif /* defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__) */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_use_number
 * DESCRIPTION
 *  Highlight use number handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_use_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_entry_use_number,
        GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  RefreshMessagesMenuList
 * DESCRIPTION
 *  Refresh message menu list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RefreshMessagesMenuList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] RefreshMessagesMenuList *\n");
#ifdef __MMI_DUAL_SIM_MASTER__
	RefreshSMSDividedMenuList();
	if (MTPNP_AD_SMS_Get_Show_Style() != MTPNP_AD_SHOW_DIVIDED)
	{
#endif /* __MMI_DUAL_SIM_MASTER__ */
#ifdef __MMI_MESSAGES_MULTI_APP__
	    if (GetMessagesCurrScrnID() == SCR_ID_MSG_SMS_MAIN_MENU)
	    {
	        S32 menuItemId = -1;

	        menuItemId = GetChildMenuIDIndexByParentMenuID(MESSAGES_MENU_SMS_MENUID, MESSAGES_MENU_INBOX_MENUID);
	        if (menuItemId != -1)
	        {
	            Category52ChangeItemDescriptionNoAnimation(menuItemId, TotalInboxOutboxStatus.totalInboxStr);
	        }
	        menuItemId = GetChildMenuIDIndexByParentMenuID(MESSAGES_MENU_SMS_MENUID, MESSAGES_MENU_OUTBOX_MENUID);
	        if (menuItemId != -1)
	        {
	            Category52ChangeItemDescriptionNoAnimation(menuItemId, TotalInboxOutboxStatus.totalOutboxStr);
	        }
	    #ifdef __MMI_MESSAGES_DRAFT_BOX__
	        menuItemId = GetChildMenuIDIndexByParentMenuID(MESSAGES_MENU_SMS_MENUID, MESSAGES_MENU_DRAFTBOX_MENUID);
	        if (menuItemId != -1)
	        {
	            Category52ChangeItemDescriptionNoAnimation(menuItemId, TotalInboxOutboxStatus.totalDraftboxStr);
	        }
	    #endif /* __MMI_MESSAGES_DRAFT_BOX__ */ 
	        RedrawCategoryFunction();
	    }
#else /* __MMI_MESSAGES_MULTI_APP__ */ 
	    if (GetMessagesCurrScrnID() == SCR_ID_MSG_MAIN_MENU)
	    {
	        S32 menuItemId = -1;

	        menuItemId = GetChildMenuIDIndexByParentMenuID(MAIN_MENU_MESSAGES_MENUID, MESSAGES_MENU_INBOX_MENUID);
	        if (menuItemId != -1)
	        {
	            Category52ChangeItemDescriptionNoAnimation(menuItemId, TotalInboxOutboxStatus.totalInboxStr);
	        }
	        menuItemId = GetChildMenuIDIndexByParentMenuID(MAIN_MENU_MESSAGES_MENUID, MESSAGES_MENU_OUTBOX_MENUID);
	        if (menuItemId != -1)
	        {
	            Category52ChangeItemDescriptionNoAnimation(menuItemId, TotalInboxOutboxStatus.totalOutboxStr);
	        }
	    #ifdef __MMI_MESSAGES_DRAFT_BOX__
	        menuItemId = GetChildMenuIDIndexByParentMenuID(MAIN_MENU_MESSAGES_MENUID, MESSAGES_MENU_DRAFTBOX_MENUID);
	        if (menuItemId != -1)
	        {
	            Category52ChangeItemDescriptionNoAnimation(menuItemId, TotalInboxOutboxStatus.totalDraftboxStr);
	        }
	    #endif /* __MMI_MESSAGES_DRAFT_BOX__ */ 
	        RedrawCategoryFunction();
	    }
#endif /* __MMI_MESSAGES_MULTI_APP__ */

#ifdef __MMI_DUAL_SIM_MASTER__
	}
#endif /* __MMI_DUAL_SIM_MASTER__ */
}

#if defined(__MMI_MESSAGES_TEMPLATE__)


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_insert_template
 * DESCRIPTION
 *  Insert template
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_insert_template(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *templ;
    EMSData *pEMS;
    history temphistory;
    historyNode *History;
	U16 templateCharNum = 0;

#if defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)
    S32 remain_len, text_len;
    U8 ucs2_count;
    S32 cursor_p;
#else /* defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__) */ 
    U8 result = 1;
#endif /* defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__) */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_insert_template *\n");

    templ = g_msg_cntx.templates[g_msg_cntx.currTemplateIndex];

#if defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)
    if (templ)
    {
        text_len = mmi_ucs2strlen((S8*) templ);
        /* ucs2_count=Is_UCS2_char_present(templ,text_len); */
        ucs2_count = mmi_frm_sms_check_UCS2((U16*) templ, (U16) text_len);

        if (ucs2_count > 0)
        {
            g_nsm_msg_context.UCS2_count = ucs2_count;
        }

        remain_len = mmi_nsm2_get_remaining_len();

        if (((MMI_multiline_inputbox.text_length + (text_len * 2)) > remain_len))
        {
            GoBackToHistory(SCR_ID_MSG_WRITE);
            DisplayPopup(
                (U8*) GetString(STR_NO_SPACE_TO_INSERT_OBJECT),
                IMG_GLOBAL_ERROR,
                TRUE,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
        }
        else
        {

            cursor_p = (MMI_multiline_inputbox.cursor_p - MMI_multiline_inputbox.text);
            memset(&temphistory, 0, sizeof(temphistory));
            GetHistory(SCR_ID_MSG_WRITE, &temphistory);

            AppendCategory5String(
                INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
                g_nsm_msg_context.textbuffer,
                remain_len,
                (U8*) templ,
                temphistory.guiBuffer);

            g_nsm_msg_context.UCS2_count = MMI_multiline_inputbox.UCS2_count;   /* To fix template bug */

            pEMS = GetEMSDataForEdit(0, 0);
            ((*pEMS).CurrentPosition).OffsetToText = cursor_p;
            AddString(pEMS, (U8*) templ, (U16) mmi_ucs2strlen(templ), NULL);

            if (GetHistoryScrID(SCR_ID_MSG_WRITE, &History) == ST_SUCCESS)
            {
                memcpy(History->guiBuffer, temphistory.guiBuffer, MAX_GUI_BUFFER);
            }

            /* To fix template cursor position.Get reset in RedrawCate275 */
            g_nsm_msg_context.is_template_insert = TRUE;
            g_nsm_msg_context.cursor_pos_after_template = cursor_p + (text_len * 2);

            Messages2GoBackHistory();
        }
    }
#else /* defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__) */
	if (templ != NULL)
	{
		templateCharNum = mmi_ucs2strlen((PS8) templ);
	}

    if (templateCharNum > 0)
    {
        BOOL isUcs2Char = 0;

        isUcs2Char = mmi_frm_sms_check_UCS2((U16*) templ, templateCharNum);

        memset(&temphistory, 0, sizeof(temphistory));
        GetHistory(SCR_ID_MSG_WRITE, &temphistory);
        pEMS = GetEMSDataForEdit(0, 0);

        if (pEMS->dcs == SMSAL_UCS2_DCS || isUcs2Char)
        {
            result = AppendCategory28String(
                        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
                        pEMS,
                        (U8*) templ,
                        temphistory.guiBuffer);
        }
        else    /* SMSAL_DEFAULT_DCS */
        {
            U8 *handledBuffer;

            handledBuffer = OslMalloc((templateCharNum * 2 + 1) * ENCODING_LENGTH);
            memset((S8*) handledBuffer, 0, ((templateCharNum * 2 + 1) * ENCODING_LENGTH));
            mmi_frm_sms_handle_extension_char((U16*) handledBuffer, (U16*) templ, templateCharNum);
            result = AppendCategory28String(
                        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
                        pEMS,
                        (U8*) handledBuffer,
                        temphistory.guiBuffer);

            OslMfree(handledBuffer);
        }
        if (GetHistoryScrID(SCR_ID_MSG_WRITE, &History) == ST_SUCCESS)
        {
            memcpy(History->guiBuffer, temphistory.guiBuffer, MAX_GUI_BUFFER);
        }

        if (!result)
        {
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                 "*[SmsMoMtGuiInterface.c] mmi_msg_insert_template - ERROR in inserting template-*\n");
        }
    }
    if (result == 0)
    {
        GoBackToHistory(SCR_ID_MSG_WRITE);
        DisplayPopup(
            (PU8) GetString(STR_NO_SPACE_TO_INSERT_OBJECT),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
    }
    else
    {
        Messages2GoBackHistory();
    }
#endif /* defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__) */ 
    DeInitTemplates();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_save_template
 * DESCRIPTION
 *  Save template
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_save_template(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (StoreTemplate(g_msg_cntx.currTemplateIndex))
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_SAVED),
            IMG_GLOBAL_ACTIVATED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) SAVE_TONE);
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
    }
    DeleteMessagesHistoryNodes();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_erase_template
 * DESCRIPTION
 *  Erase template
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_erase_template(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (DeleteTemplate(g_msg_cntx.currTemplateIndex))
    {
        DisplayPopup(
            (PU8) GetString(STR_MESSAGES_ERACED_ID),
            IMG_GLOBAL_ACTIVATED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) SUCCESS_TONE);
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
    }
    DeleteMessagesHistoryNodes();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_pre_erase_template
 * DESCRIPTION
 *  Before erase template, check if it is empty
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_pre_erase_template(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_ucs2strlen(g_msg_cntx.templates[g_msg_cntx.currTemplateIndex]))
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_EMPTY,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) EMPTY_LIST_TONE);
        DeleteMessagesHistoryNodes();
    }
    else
    {
        mmi_msg_set_confirm_screen(STR_MESSAGES_ERACE_Q_ID, mmi_msg_erase_template, Messages2GoBackHistory);
        mmi_msg_entry_confirm_generic();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_go_back_from_template
 * DESCRIPTION
 *  Deinit template before go back screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_go_back_from_template(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeInitTemplates();
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_end_key_from_template
 * DESCRIPTION
 *  Deinit template before go to idle
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_end_key_from_template(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!isInCall())
    {
        DeInitTemplates();
    }
    ExecCurrEndKeyDownHandler();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_insert_template_to_chat
 * DESCRIPTION
 *  Insert template to chat message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_MESSAGES_CHAT__
void mmi_msg_insert_template_to_chat(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    InsertTemplateToChat(g_msg_cntx.templates[g_msg_cntx.currTemplateIndex]);
}
#endif /* __MMI_MESSAGES_CHAT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_template_list
 * DESCRIPTION
 *  Entry template list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_template_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    S32 hiliteitem = 0;
    U16 lsk_str_id = 0;
    U16 lsk_img_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_template_list *\n");

    if (InitTemplates() == FALSE)
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_DOES_NOT_SUPPORT),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
        return;
    }

    EntryNewScreen(SCR_ID_MSG_TEMPLATE_LIST, mmi_msg_exit_generic, mmi_msg_entry_template_list, NULL);
    LoadTemplatesInDisplayList();

    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_TEMPLATE_LIST);
    if (guiBuffer != NULL)
    {
        hiliteitem = (g_msg_cntx.currTemplateIndex < NUM_TEMPLATES) ? g_msg_cntx.currTemplateIndex : 0;
    }
    RegisterHighlightHandler(GetTemplateIndex);
    SetMessagesCurrScrnID(SCR_ID_MSG_TEMPLATE_LIST);
    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_TEMPLATE_LIST);

    GetCurrEndKeyDownHandler();

    if ((IsScreenPresent(SCR_ID_MSG_WRITE)) ||
#ifdef __MMI_MESSAGES_CHAT__
        (IsScreenPresent(CHAT_SCREEN_START_NEW_ID)) ||
#endif /* __MMI_MESSAGES_CHAT__ */		
#ifdef __MMI_UNIFIED_COMPOSER__
        (IsScreenPresent(SCR_ID_UC_OPT_INSERT)) ||
#endif /* __MMI_UNIFIED_COMPOSER__ */     
        MMI_FALSE)
    {
        lsk_str_id = STR_GLOBAL_OK;
        lsk_img_id = IMG_GLOBAL_OK;
    }
	else
    {
        lsk_str_id = STR_GLOBAL_OPTIONS;
        lsk_img_id = IMG_GLOBAL_OPTIONS;	
    }
	
    ShowCategory184Screen(
        STR_SCRN_T0_CAPTION,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        lsk_str_id,
        lsk_img_id,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        NUM_TEMPLATES,
        mmi_msg_template_list_get_item,
        NULL,
        hiliteitem,
        guiBuffer);

    SetRightSoftkeyFunction(mmi_msg_go_back_from_template, KEY_EVENT_UP);
    SetKeyHandler(mmi_msg_go_back_from_template, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    if (IsScreenPresent(SCR_ID_MSG_WRITE))
    {
        SetLeftSoftkeyFunction(mmi_msg_insert_template, KEY_EVENT_UP);
        SetKeyHandler(mmi_msg_insert_template, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
#ifdef __MMI_MESSAGES_CHAT__
    else if (IsScreenPresent(CHAT_SCREEN_START_NEW_ID))
    {
        SetLeftSoftkeyFunction(mmi_msg_insert_template_to_chat, KEY_EVENT_UP);
        SetKeyHandler(mmi_msg_insert_template_to_chat, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
#endif /* __MMI_MESSAGES_CHAT__ */
#ifdef __MMI_UNIFIED_COMPOSER__
    else if (IsScreenPresent(SCR_ID_UC_OPT_INSERT))
    {
        SetLeftSoftkeyFunction(mmi_uc_insert_text_template, KEY_EVENT_UP);
        SetKeyHandler(mmi_uc_insert_text_template, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
#endif /* __MMI_UNIFIED_COMPOSER__ */ 
    else
    {
        SetLeftSoftkeyFunction(mmi_msg_entry_template_option, KEY_EVENT_UP);
        SetKeyHandler(mmi_msg_entry_template_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }

    SetKeyHandler(mmi_msg_end_key_from_template, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_template_list_get_item
 * DESCRIPTION
 *  Get template list item
 * PARAMETERS
 *  item_index          [IN]            
 *  str_buff            [IN]            
 *  img_buff_p          [?]             
 *  str_img_mask        [IN]            
 *  a(?)                [IN]            Item index
 *  d(?)                [IN/OUT]        String image mask
 *  c(?)                [IN/OUT]        Image buffer
 *  b(?)                [IN/OUT]        String buffer
 * RETURNS
 * TRUE
 *****************************************************************************/
pBOOL mmi_msg_template_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((item_index < 0) || (item_index >= NUM_TEMPLATES))
    {
        return FALSE;
    }

    if (mmi_ucs2strlen(g_msg_cntx.templates[item_index]) == 0)
    {
        mmi_ucs2cpy((S8*) str_buff, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
    }
    else
    {
        mmi_ucs2cpy((S8*) str_buff, (S8*) g_msg_cntx.templates[item_index]);
    }

    *img_buff_p = get_image(gIndexIconsImageList[item_index]);
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_template_option
 * DESCRIPTION
 *  Entry template option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_template_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_TEMPLATE_OPTION, mmi_msg_exit_generic, mmi_msg_entry_template_option, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_template_option *\n");
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_TEMPLATE_OPTION);

    numItems = GetNumOfChild(TEMPLATES_OPTIONS_MENUENTRY);
    GetSequenceStringIds(TEMPLATES_OPTIONS_MENUENTRY, nStrItemList);
    SetParentHandler(TEMPLATES_OPTIONS_MENUENTRY);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    SetMessagesCurrScrnID(SCR_ID_MSG_TEMPLATE_OPTION);
    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_TEMPLATE_OPTION);

    GetCurrEndKeyDownHandler();
    ShowCategory52Screen(
        STR_SCRN_T1_OPTIONS_CAPTION,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
    SetKeyHandler(mmi_msg_end_key_from_template, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_template_edit
 * DESCRIPTION
 *  Entry template edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_template_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_TEMPLATE_EDIT, mmi_msg_exit_generic, mmi_msg_entry_template_edit, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_template_edit *\n");
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_TEMPLATE_EDIT);
    if (!guiBuffer)
    {
        GetTemplatesToEdit(g_msg_cntx.scratchTemplRec, g_msg_cntx.currTemplateIndex);
    }
    SetMessagesCurrScrnID(SCR_ID_MSG_TEMPLATE_EDIT);

    GetCurrEndKeyDownHandler();
    ShowCategory5Screen(
        STR_SCRN_T4_EDIT_TEMPLATE_CAPTION,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OPTIONS,
        IMG_SMS_COMMON_NOIMAGE,
        STR_GLOBAL_BACK,
        IMG_SMS_COMMON_NOIMAGE,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        (U8*) g_msg_cntx.scratchTemplRec,
        MAX_TEMPLATE_LENGTH + 1,
        guiBuffer);
    SetLeftSoftkeyFunction(mmi_msg_entry_template_edit_option, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_msg_end_key_from_template, KEY_END, KEY_EVENT_DOWN);

    RegisterInputMethodScreenCloseFunction(Messages2GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_template_edit_option
 * DESCRIPTION
 *  Entry template edit option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_template_edit_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_TEMPLATE_EDIT_OPTION, mmi_msg_exit_generic, mmi_msg_entry_template_edit_option, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_template_edit_option *\n");
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_TEMPLATE_EDIT_OPTION);

    numItems = GetNumOfChild(SMS_ED_TEMPL_OPTIONS_MENU_ID);
    GetSequenceStringIds(SMS_ED_TEMPL_OPTIONS_MENU_ID, nStrItemList);
    SetParentHandler(SMS_ED_TEMPL_OPTIONS_MENU_ID);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    SetMessagesCurrScrnID(SCR_ID_MSG_TEMPLATE_EDIT_OPTION);

    GetCurrEndKeyDownHandler();
    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
    SetKeyHandler(mmi_msg_end_key_from_template, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_template_write_msg
 * DESCRIPTION
 *  entry write msg with the template content
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_template_write_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *templ;
    EMSData *pEMS;
    history temphistory;
    U8 result = 1;
	U16 templateCharNum = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_template_write_msg *\n");

    templ = g_msg_cntx.templates[g_msg_cntx.currTemplateIndex];
    pEMS = GetEMSDataForEdit(0, 1);

	if (templ != NULL)
	{
		templateCharNum = mmi_ucs2strlen((PS8) templ);
	}

    if (templateCharNum > 0)
    {
        BOOL isUcs2Char = 0;

        isUcs2Char = mmi_frm_sms_check_UCS2((U16*) templ, templateCharNum);

        memset(&temphistory, 0, sizeof(temphistory));

        if (pEMS->dcs == SMSAL_UCS2_DCS || isUcs2Char)
        {
            result = AppendCategory28String(
                        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
                        pEMS,
                        (U8*) templ,
                        temphistory.guiBuffer);
        }
        else    /* SMSAL_DEFAULT_DCS */
        {
            U8 *handledBuffer;

            handledBuffer = OslMalloc((templateCharNum * 2 + 1) * ENCODING_LENGTH);
            memset((S8*) handledBuffer, 0, ((templateCharNum * 2 + 1) * ENCODING_LENGTH));
            mmi_frm_sms_handle_extension_char((U16*) handledBuffer, (U16*) templ, templateCharNum);
            result = AppendCategory28String(
                        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
                        pEMS,
                        (U8*) handledBuffer,
                        temphistory.guiBuffer);

            OslMfree(handledBuffer);
        }

        /* GoToEndPosition (pEMS); */

        if (!result)
        {
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                 "*[SmsMoMtGuiInterface.c] mmi_msg_insert_template - ERROR in inserting template-*\n");
        }
    }
    if (result == 0)
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_ERROR),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
    }
    else
    {
    #ifdef __MMI_UNIFIED_COMPOSER__
        mmi_msg_entry_uc(NULL, MMI_UC_STATE_WRITE_NEW_MSG, 0, MMI_UC_MSG_TYPE_DEFAULT);
    #else /* __MMI_UNIFIED_COMPOSER__ */
		g_msg_cntx.sendMessageCase = SEND_CASE_SEND_ONLY;
        mmi_msg_entry_write_msg();
    #endif /* __MMI_UNIFIED_COMPOSER__ */   
    }

    DeleteScreenIfPresent(SCR_ID_MSG_TEMPLATE_OPTION);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_save_template
 * DESCRIPTION
 *  Highlight save template handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_save_template(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_set_confirm_screen(STR_GLOBAL_SAVE_ASK, mmi_msg_save_template, Messages4GoBackHistory);

    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_entry_confirm_generic,
        GoBackHistory);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_erase_template
 * DESCRIPTION
 *  Highlight erase template handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_erase_template(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_pre_erase_template,
        GoBackHistory);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_edit_template
 * DESCRIPTION
 *  Highlight edit template handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_edit_template(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_entry_template_edit,
        GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_template_write_msg
 * DESCRIPTION
 *  Highlight template write msg handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_template_write_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_entry_template_write_msg,
        GoBackHistory);

}
#endif /* defined(__MMI_MESSAGES_TEMPLATE__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_insert_number_from_phb
 * DESCRIPTION
 *  Insert phonebook number into write msg
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_insert_number_from_phb(S8* name, S8* number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSData *pEMS;
    history temphistory;
    historyNode *History;

    U8 result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_insert_number_from_phb *\n");

    if (mmi_ucs2strlen(number))
    {
        U16 number_chars_num;
        BOOL is_ucs2_char = 0;

        number_chars_num = mmi_ucs2strlen((PS8) number);
        is_ucs2_char = mmi_frm_sms_check_UCS2((U16*) number, number_chars_num);

        memset(&temphistory, 0, sizeof(temphistory));
        GetHistory(SCR_ID_MSG_WRITE, &temphistory);
        pEMS = GetEMSDataForEdit(0, 0);

        if (pEMS->dcs == SMSAL_UCS2_DCS || is_ucs2_char)
        {
            result = AppendCategory28String(
                        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
                        pEMS,
                        (U8*) number,
                        temphistory.guiBuffer);
        }
        else    /* SMSAL_DEFAULT_DCS */
        {
            U8 *handledBuffer;

            handledBuffer = OslMalloc((number_chars_num * 2 + 1) * ENCODING_LENGTH);
            memset((S8*) handledBuffer, 0, ((number_chars_num * 2 + 1) * ENCODING_LENGTH));
            mmi_frm_sms_handle_extension_char((U16*) handledBuffer, (U16*) number, number_chars_num);
            result = AppendCategory28String(
                        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
                        pEMS,
                        (U8*) handledBuffer,
                        temphistory.guiBuffer);

            OslMfree(handledBuffer);
        }
        if (GetHistoryScrID(SCR_ID_MSG_WRITE, &History) == ST_SUCCESS)
        {
            memcpy(History->guiBuffer, temphistory.guiBuffer, MAX_GUI_BUFFER);
        }

        if (!result)
        {
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                 "*[SmsMoMtGuiInterface.c] mmi_msg_insert_number_from_phb - ERROR in inserting phb number-*\n");
        }

        if (IsScreenPresent(SCR_ID_MSG_WRITE))
        {
            GoBackToHistory(SCR_ID_MSG_WRITE);
        }
        else
        {
            MMI_ASSERT(0);
        }
                   
        if (result == 0)
        {            
            DisplayPopup(
                (PU8) GetString(STR_NO_SPACE_TO_INSERT_OBJECT),
                IMG_GLOBAL_UNFINISHED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
        }
    }
    else
    {
        DisplayPopup(
                (PU8) GetString(STR_SMS_NUM_CANNOT_BE_EMPTY),
                IMG_GLOBAL_UNFINISHED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_insert_name_from_phb
 * DESCRIPTION
 *  Insert phonebook name into write msg
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_insert_name_from_phb(S8* name, S8* number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSData *pEMS;
    history temphistory;
    historyNode *History;

    U8 result = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_insert_name_from_phb *\n");

    if (mmi_ucs2strlen(name))
    {
        U16 name_chars_num;
        BOOL is_ucs2_char = 0;

        name_chars_num = mmi_ucs2strlen((PS8) name);
        is_ucs2_char = mmi_frm_sms_check_UCS2((U16*) name, name_chars_num);

        memset(&temphistory, 0, sizeof(temphistory));
        GetHistory(SCR_ID_MSG_WRITE, &temphistory);
        pEMS = GetEMSDataForEdit(0, 0);

        if (pEMS->dcs == SMSAL_UCS2_DCS || is_ucs2_char)
        {
            result = AppendCategory28String(
                        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
                        pEMS,
                        (U8*) name,
                        temphistory.guiBuffer);
        }
        else    /* SMSAL_DEFAULT_DCS */
        {
            U8 *handledBuffer;

            handledBuffer = OslMalloc((name_chars_num * 2 + 1) * ENCODING_LENGTH);
            memset((S8*) handledBuffer, 0, ((name_chars_num * 2 + 1) * ENCODING_LENGTH));
            mmi_frm_sms_handle_extension_char((U16*) handledBuffer, (U16*) name, name_chars_num);
			
			if (mmi_ucs2strlen((S8*)handledBuffer) > 0)
			{
				result = AppendCategory28String(
	                        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
	                        pEMS,
	                        (U8*) handledBuffer,
	                        temphistory.guiBuffer);
			}

            OslMfree(handledBuffer);
        }
        if (GetHistoryScrID(SCR_ID_MSG_WRITE, &History) == ST_SUCCESS)
        {
            memcpy(History->guiBuffer, temphistory.guiBuffer, MAX_GUI_BUFFER);
        }

        if (!result)
        {
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                 "*[SmsMoMtGuiInterface.c] mmi_msg_insert_name_from_phb - ERROR in inserting phb name-*\n");
        }

        if (IsScreenPresent(SCR_ID_MSG_WRITE))
        {
            GoBackToHistory(SCR_ID_MSG_WRITE);
        }
        else
        {
            MMI_ASSERT(0);
        }
                   
        if (result == 0)
        {            
            DisplayPopup(
                (PU8) GetString(STR_NO_SPACE_TO_INSERT_OBJECT),
                IMG_GLOBAL_UNFINISHED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
        }
    }
    else
    {
        DisplayPopup(
                (PU8) GetString(STR_SMS_NAME_CANNOT_BE_EMPTY),
                IMG_GLOBAL_UNFINISHED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
    }    
}


   
/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_insert_phb_number
 * DESCRIPTION
 *  Highlight Insert PHB number handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_insert_phb_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_list_pre_entry_for_number_and_email(MMI_PHB_ENTRY_FIELD_ALL_NUMBER, mmi_msg_insert_number_from_phb);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_insert_phb_name
 * DESCRIPTION
 *  Highlight Insert PHB name handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_insert_phb_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_list_pre_entry_for_number_and_email(MMI_PHB_ENTRY_FIELD_NAME, mmi_msg_insert_name_from_phb);
}


#ifdef WAP_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_msg_handle_select_bookmark_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_handle_select_bookmark_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_select_bookmark_rsp_struct *msg_rsp = (wap_select_bookmark_rsp_struct*) (inMsg);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_handle_select_bookmark_rsp *\n");
    
    if (msg_rsp->result == 1)
    {
        EMSData *pEMS;
        history temphistory;
        historyNode *History;
        U16 chars_num = mmi_chset_utf8_strlen((const kal_uint8 *)msg_rsp->url);
        U8 result = 0;

        if (chars_num > 0)
        {
            U8 *ucs2_buffer = OslMalloc((chars_num<<1 + 1) * ENCODING_LENGTH);
            BOOL is_ucs2_char = FALSE;

            memset(ucs2_buffer, 0x00, (chars_num<<1 + 1) * ENCODING_LENGTH);
            if ((strlen((const char *) msg_rsp->url)!= chars_num))
            {
                mmi_chset_utf8_to_ucs2_string((kal_uint8 *) ucs2_buffer, (kal_int32) (chars_num<<1 + 1), (kal_uint8 *) msg_rsp->url);
                is_ucs2_char = TRUE;
            }
            else
            {
            mmi_asc_n_to_ucs2((S8*) ucs2_buffer, (S8*) msg_rsp->url, chars_num);
            }
            memset(&temphistory, 0, sizeof(temphistory));
            GetHistory(SCR_ID_MSG_WRITE, &temphistory);
            pEMS = GetEMSDataForEdit(0, 0);

            if (pEMS->dcs == SMSAL_UCS2_DCS || is_ucs2_char)
            {
                result = AppendCategory28String(
                            INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
                            pEMS,
                            (U8*) ucs2_buffer,
                            temphistory.guiBuffer);
            }
            else    /* SMSAL_DEFAULT_DCS */
            {
                U8 *handledBuffer;

                handledBuffer = OslMalloc((chars_num * 2 + 1) * ENCODING_LENGTH);
                memset((S8*) handledBuffer, 0, ((chars_num * 2 + 1) * ENCODING_LENGTH));
                mmi_frm_sms_handle_extension_char((U16*) handledBuffer, (U16*) ucs2_buffer, chars_num);
                result = AppendCategory28String(
                            INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
                            pEMS,
                            (U8*) handledBuffer,
                            temphistory.guiBuffer);

                OslMfree(handledBuffer);
            }

            OslMfree(ucs2_buffer);
            
            if (GetHistoryScrID(SCR_ID_MSG_WRITE, &History) == ST_SUCCESS)
            {
                memcpy(History->guiBuffer, temphistory.guiBuffer, MAX_GUI_BUFFER);
            }

            if (!result)
            {
                PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                     "*[SmsMoMtGuiInterface.c] mmi_msg_handle_select_bookmark_rsp - ERROR in inserting bookmark-*\n");
            }

            if (MMI_TRUE == mmi_msg_check_interrupt())
            {                
                if (IsScreenPresent(SCR_ID_MSG_WRITE))
                {
                    DeleteUptoScrID(SCR_ID_MSG_WRITE);
                }
                else
                {
                    MMI_ASSERT(0);
                }
            }
            else
            {
                if (IsScreenPresent(SCR_ID_MSG_WRITE))
                {
                    GoBackToHistory(SCR_ID_MSG_WRITE);
                }
                else
                {
                    MMI_ASSERT(0);
                }
                       
                if (result == 0)
                {            
                    DisplayPopup(
                        (PU8) GetString(STR_NO_SPACE_TO_INSERT_OBJECT),
                        IMG_GLOBAL_UNFINISHED,
                        1,
                        MESSAGES_POPUP_TIME_OUT,
                        (U8) ERROR_TONE);
                }
            }            
        }
        else
        {
            if (MMI_TRUE == mmi_msg_check_interrupt())
            {                
                if (IsScreenPresent(SCR_ID_MSG_WRITE))
                {
                    DeleteUptoScrID(SCR_ID_MSG_WRITE);
                }
                else
                {
                    MMI_ASSERT(0);
                }
            }
            else
            {
                if (IsScreenPresent(SCR_ID_MSG_WRITE))
                {
                    GoBackToHistory(SCR_ID_MSG_WRITE);
                }
                else
                {
                    MMI_ASSERT(0);
                }
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_insert_bookmark
 * DESCRIPTION
 *  Highlight Insert bookmark handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_insert_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_msg_handle_select_bookmark_rsp, MSG_ID_WAP_SELECT_BOOKMARK_RSP);
    wap_entry_select_bookmark();
}
#endif /* WAP_SUPPORT */


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_done
 * DESCRIPTION
 *  Highlight done handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
	/* update channel status */
	MTPNP_AD_Free_Channel(MTPNP_AD_SMS_CHANNEL);
	MTPNP_AD_Set_Channel(MTPNP_AD_SMS_CHANNEL, MTPNP_AD_CHANNEL_MASTER);
	/* update channel status */
#endif /* __MMI_DUAL_SIM_MASTER__ */
	
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_entry_send_option,
        GoBackHistory);
    if ((g_msg_cntx.sendMessageCase == SEND_CASE_REPLY) || (g_msg_cntx.sendMessageCase == SEND_CASE_SEND_FROM_PHB))
    {
        ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_input_method
 * DESCRIPTION
 *  Highlight input method handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_input_method(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInputMethodAndDoneCaptionIcon(IMG_SMS_ENTRY_SCRN_CAPTION);
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        EntryInputMethodScreen,
        GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_input_method_generic
 * DESCRIPTION
 *  Highlight input method generic handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_input_method_generic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInputMethodAndDoneCaptionIcon(IMG_SMS_ENTRY_SCRN_CAPTION);
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        EntryInputMethodScreen,
        GoBackHistory);
    RegisterInputMethodScreenCloseFunction(Messages2GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_send_only
 * DESCRIPTION
 *  Highlight send only handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_send_only(void)
{
#ifdef __MMI_SEND_BY_SEARCH_NAME__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_entry_send_only,
        GoBackHistory);
#else /* __MMI_SEND_BY_SEARCH_NAME__ */ 
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_send_msg_to_only_entry,
        GoBackHistory);
#endif /* __MMI_SEND_BY_SEARCH_NAME__ */ 
}

#ifdef __MMI_SEND_BY_SEARCH_NAME__


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_send_only_number
 * DESCRIPTION
 *  Highlight send only number handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_send_only_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_send_msg_to_only_entry,
        GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_send_only_name
 * DESCRIPTION
 *  Highlight send only name handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_send_only_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_send_msg_to_only_name_entry,
        GoBackHistory);
}
#endif /* __MMI_SEND_BY_SEARCH_NAME__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_send_and_save
 * DESCRIPTION
 *  Highlight send and save handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_send_and_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_send_and_save_to_entry,
        GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_save
 * DESCRIPTION
 *  Highlight save handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_save_msg_to_entry,
        GoBackHistory);
}

#if defined(__MMI_MESSAGES_SEND_TO_MANY__)


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_send_to_many
 * DESCRIPTION
 *  Highlight send to many handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_send_to_many(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_entry_send_to_many,
        GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_send_to_many_list
 * DESCRIPTION
 *  Highlight send to many list handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_send_to_many_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_entry_send_to_many_list,
        GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_send_to_many_now
 * DESCRIPTION
 *  Highlight send to many now handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_send_to_many_now(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_send_msg_to_many,
        GoBackHistory);
}
#endif /* defined(__MMI_MESSAGES_SEND_TO_MANY__) */ 
#ifdef __MMI_MESSAGES_SEND_BY_GROUP__


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_send_by_group
 * DESCRIPTION
 *  Highlight send by group
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_send_by_group(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_send_msg_by_group,
        GoBackHistory);
}
#endif /* __MMI_MESSAGES_SEND_BY_GROUP__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_reply
 * DESCRIPTION
 *  Highlight replay handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_reply(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_reply_msg_to_entry,
        GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_send_outbox
 * DESCRIPTION
 *  Highlight outbox send handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_send_outbox(void)
{
#if defined(__MMI_DUAL_SIM_MASTER__)
    MTPNP_AD_Free_Channel(MTPNP_AD_SMS_CHANNEL);
    MTPNP_AD_Set_Channel(MTPNP_AD_SMS_CHANNEL, MTPNP_AD_CHANNEL_MASTER);
#endif /* __MMI_DUAL_SIM_MASTER__ */

#ifdef __MMI_UNIFIED_MESSAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    {
        U8 msg_box_type = mmi_um_get_current_msg_box_type();

        /*----------------------------------------------------------------*/
        /* Code Body                                                      */
        /*----------------------------------------------------------------*/
        if ( (msg_box_type == UM_MSG_BOX_TYPE_SENT) 
            #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__            
            || (msg_box_type == UM_MSG_BOX_TYPE_ARCHIVE)
            #endif            
        )  
        {

            mmi_msg_highlight_generic(
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                mmi_msg_entry_send_option_outbox,
                GoBackHistory);
        }
        else if (msg_box_type == UM_MSG_BOX_TYPE_UNSENT || msg_box_type == UM_MSG_BOX_TYPE_DRAFT)
        {
            mmi_msg_highlight_generic(
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                mmi_msg_pre_resend_msg_to_only_entry,
                GoBackHistory);
        }
        else
        {
            MMI_ASSERT(0);
        }
    }
#else /* __MMI_UNIFIED_MESSAGE__ */ 
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_entry_send_option_outbox,
        GoBackHistory);
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
}

#ifdef __MMI_UNIFIED_MESSAGE__


#ifdef __MMI_UNIFIED_COMPOSER__
/*****************************************************************************
 * FUNCTION
 *  mmi_msg_send_msg_by_uc
 * DESCRIPTION
 *  Send msg by unified composer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_send_msg_by_uc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 msg_box_type;
	U8 ascii_number[MAX_DIGITS_SMS + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	memset((S8*)ascii_number, 0, (MAX_DIGITS_SMS + 1));

    msg_box_type = mmi_um_get_current_msg_box_type();
    if (msg_box_type == UM_MSG_BOX_TYPE_DRAFT)
    {   
    	memcpy((S8*)ascii_number, 
			(S8*)mmi_frm_sms_get_address(MMI_FRM_SMS_DRAFTS, (U16) g_msg_cntx.currBoxIndex),
			MAX_DIGITS_SMS);
	}

	mmi_msg_entry_uc(ascii_number, MMI_UC_STATE_SEND, (U16)g_msg_cntx.currBoxIndex, MMI_UC_MSG_TYPE_DEFAULT);

#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
    if (IsScreenPresent(SCR_ID_MSG_INBOX_LIST_OPTION))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_INBOX_LIST_OPTION);
    }
    else if (IsScreenPresent(SCR_ID_MSG_OUTBOX_LIST_OPTION))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_LIST_OPTION);
    }
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    else if (IsScreenPresent(SCR_ID_MSG_ARCHIVE_LIST_OPTION))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_ARCHIVE_LIST_OPTION);
    }
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
    else if (IsScreenPresent(SCR_ID_MSG_DEFAULT_LIST_OPTION))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_LIST_OPTION);
    }
    else
#endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */

    if (IsScreenPresent(SCR_ID_MSG_INBOX_MSG))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_INBOX_MSG);
    }
    else if (IsScreenPresent(SCR_ID_MSG_OUTBOX_MSG))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_MSG);
    }        
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    else if (IsScreenPresent(SCR_ID_MSG_ARCHIVE_INBOX_MSG))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_ARCHIVE_INBOX_MSG);
    }  
    else if (IsScreenPresent(SCR_ID_MSG_ARCHIVE_OUTBOX_MSG))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_ARCHIVE_OUTBOX_MSG);
    }  	
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
    else
    {
        MMI_ASSERT(0);
    }    
    DeleteMessagesHistoryNodes();
}

extern void mmi_msg_send_msg_rsp(void *number, module_type mod, U16 result);

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_send_msg_with_only_text
 * DESCRIPTION
 *  Send msg without EMS object
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_send_msg_with_only_text(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_send_struct *sendData = OslMalloc(sizeof(mmi_frm_sms_send_struct));
    EMSData *pEMS;    
    U8 *addr = NULL;
    U8* temp_buffer = NULL;
    U16 text_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) sendData, 0, sizeof(mmi_frm_sms_send_struct));
    GetEMSDataForEdit(&pEMS, 0);

    sendData->dcs = pEMS->dcs;

    addr = mmi_frm_sms_get_sms_address(MMI_FRM_SMS_UNSENT , (U16)g_msg_cntx.currBoxIndex);
    strcpy((char*)sendData->number, (const char*)addr);
  
    temp_buffer = (U8*)applib_mem_screen_alloc(MMI_UC_UTF8_TEXT_BUFFER_SIZE);        
    memset(temp_buffer, 0, MMI_UC_UTF8_TEXT_BUFFER_SIZE);
    text_size = pEMS->textLength; 
    MMI_ASSERT(text_size <= MMI_UC_UTF8_TEXT_BUFFER_SIZE);
    memcpy(temp_buffer, pEMS->textBuffer, text_size);

    GetEMSDataForEdit(&pEMS, 1);
    AddString(pEMS, temp_buffer, (U16)(text_size / ENCODING_LENGTH), NULL);
    EMSSetDCS(pEMS, sendData->dcs);
    
    applib_mem_screen_free(temp_buffer);

    g_msg_cntx.msg_send_info.CurrSendSmsNumbers = 0;
    g_msg_cntx.msg_send_info.TotalSendSmsNumbers = 1;
    g_msg_cntx.sendMessageCase = SEND_CASE_SEND_ONLY;
    mmi_frm_sms_send_sms(mmi_msg_send_msg_rsp, MOD_MMI, sendData);
    OslMfree(sendData);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_resend_msg_without_ems_object
 * DESCRIPTION
 *  Resend msg without EMS object
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_resend_msg_without_ems_object(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_send_msg_with_only_text();
}
#endif /* __MMI_UNIFIED_COMPOSER__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_pre_resend_msg_to_only_entry
 * DESCRIPTION
 *  Pre entry outbox re-send option function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_pre_resend_msg_to_only_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result = EMS_OK;
#ifdef __MMI_UNIFIED_COMPOSER__    
    U8 msg_box_type = mmi_um_get_current_msg_box_type();
    EMSData *pEMS;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = CopyEMSViewToEditBuffer();
    /* copy view content to edit buffer maybe fail due to EMS LIB virtual pack fail */
    if (result != EMS_OK)
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_FAILURE_MSG_LEN_EXCEEDED),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
        DeleteScreenIfPresent(SCR_ID_MSG_OUTBOX_SEND_OPTION);
        return;
    }

#ifdef __MMI_UNIFIED_COMPOSER__
    GetEMSDataForEdit(&pEMS, 0);

    if (msg_box_type == UM_MSG_BOX_TYPE_DRAFT)
    {        
        if (pEMS->listHead)
        {
            mmi_msg_set_confirm_screen(STR_SMS_REMOVE_EMS_OBJECT_QUERY_ID, mmi_msg_send_msg_by_uc, GoBackHistory);
            mmi_msg_entry_confirm_generic();
        }
        else
        {
            mmi_msg_send_msg_by_uc();
        }
    }
    else /* UM_MSG_BOX_TYPE_UNSENT */
    {
        if (pEMS->listHead)
        {
            mmi_msg_set_confirm_screen(STR_SMS_REMOVE_EMS_OBJECT_QUERY_ID, mmi_msg_resend_msg_without_ems_object, GoBackHistory);
            mmi_msg_entry_confirm_generic();            
        }
        else
        {
            mmi_msg_resend_msg_without_ems_object();
        }
    }    
#else /* __MMI_UNIFIED_COMPOSER__ */
    mmi_msg_send_msg_to_only_entry();
#endif /* __MMI_UNIFIED_COMPOSER__ */

}
#endif /* __MMI_UNIFIED_MESSAGE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_edit
 * DESCRIPTION
 *  Highlight edit handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SMART_MESSAGE_MT__) || defined(__MMI_MYPICTURE__)
    if (mmi_nsm_get_msg_type() == PICTURE_MESSAGE)
    {

        //mmi_nsm_init_picmsg_txt_struct(&picmsg_text_struct);
        //   mmi_ucs2cpy((S8*)picmsg_text_struct.pic_textbuff,(S8*)g_pmsg_TextInMessage);
    #if defined(__MMI_MYPICTURE__)
        if (IsScreenPresent(SCR_ID_MSG_OUTBOX_LIST))
        {
            highlight_mypic_addtext_handler();
        }
        else
    #endif /* defined(__MMI_MYPICTURE__) */ 
            highlight_picmsg_edit_text();
    }
    else
#endif /* defined(__MMI_SMART_MESSAGE_MT__) || defined(__MMI_MYPICTURE__) */ 
        mmi_msg_highlight_generic(
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            mmi_msg_edit_msg_from_view,
            GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_forward
 * DESCRIPTION
 *  Highlight forward handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_forward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_entry_forward_option_inbox,
        GoBackHistory);
}

#ifdef __MMI_MESSAGES_COPY__


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_copy
 * DESCRIPTION
 *  Highlight copy handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_copy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 dst_storage = SMSAL_ME;
#ifdef __MMI_DUAL_SIM_MASTER__
    U16 msgbox_type = 0;
#endif /* __MMI_DUAL_SIM_MASTER__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_msg_cntx.toDisplayMessageList)
    {
        case TO_DISPLAY_MESSAGE_LIST_INBOX:
        #ifdef __MMI_DUAL_SIM_MASTER__
            msgbox_type = MMI_FRM_SMS_APP_INBOX;
        #endif /* __MMI_DUAL_SIM_MASTER__ */
            if (mmi_frm_sms_get_storage(MMI_FRM_SMS_APP_INBOX, (U16) g_msg_cntx.currBoxIndex) == SMSAL_ME)
            {
                dst_storage = SMSAL_SM;
            }
            break;
        case TO_DISPLAY_MESSAGE_LIST_OUTBOX:
        #ifdef __MMI_DUAL_SIM_MASTER__
            msgbox_type = MMI_FRM_SMS_APP_OUTBOX;
        #endif /* __MMI_DUAL_SIM_MASTER__ */
            if (mmi_frm_sms_get_storage(MMI_FRM_SMS_APP_OUTBOX, (U16) g_msg_cntx.currBoxIndex) == SMSAL_ME)
            {
                dst_storage = SMSAL_SM;
            }
            break;

#ifdef __MMI_UNIFIED_MESSAGE__
		case TO_DISPLAY_MESSAGE_LIST_UNSENTBOX:
            if (mmi_frm_sms_get_storage(MMI_FRM_SMS_APP_UNSENT, (U16) g_msg_cntx.currBoxIndex) == SMSAL_ME)
            {
                dst_storage = SMSAL_SM;
            }
            break;
#endif /* __MMI_UNIFIED_MESSAGE__ */
			
        #ifdef __MMI_MESSAGES_DRAFT_BOX__
        case TO_DISPLAY_MESSAGE_LIST_DRAFTBOX:
        #ifdef __MMI_DUAL_SIM_MASTER__
            msgbox_type = MMI_FRM_SMS_APP_DRAFTS;
        #endif /* __MMI_DUAL_SIM_MASTER__ */
            if (mmi_frm_sms_get_storage(MMI_FRM_SMS_APP_DRAFTS, (U16) g_msg_cntx.currBoxIndex) == SMSAL_ME)
            {
                dst_storage = SMSAL_SM;
            }
            break;
        #endif /* __MMI_MESSAGES_DRAFT_BOX__ */ 
    }

    if (dst_storage == SMSAL_SM)
    {
        mmi_msg_set_confirm_screen(STR_SMS_COPY_TO_SIM_QUERY_ID, mmi_msg_copy_msg, GoBackHistory);
    }
    else
    {
        mmi_msg_set_confirm_screen(STR_SMS_COPY_TO_PHONE_QUERY_ID, mmi_msg_copy_msg, GoBackHistory);
    }

    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_entry_confirm_generic,
        GoBackHistory);

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

}


#ifndef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_copy_all_inbox
 * DESCRIPTION
 *  Highlight copy all inbox handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_copy_all_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_entry_copy_all_inbox,
        GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_copy_all_inbox
 * DESCRIPTION
 *  Entry copy all list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_copy_all_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_INBOX) == MMI_FRM_SMS_INVALID_INDEX)
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_MSG_NOT_READY_YET),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
    }
    else
    {
        EntryNewScreen(SCR_ID_MSG_INBOX_COPY_ALL_OPTION, mmi_msg_exit_generic, mmi_msg_entry_copy_all_inbox, NULL);
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_copy_all_inbox *\n");

        guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_INBOX_COPY_ALL_OPTION);

        numItems = GetNumOfChild(SMS_INBOX_OPT_COPY_ALL_MENUID);
        GetSequenceStringIds(SMS_INBOX_OPT_COPY_ALL_MENUID, nStrItemList);

        SetParentHandler(SMS_INBOX_OPT_COPY_ALL_MENUID);

        RegisterHighlightHandler(ExecuteCurrHiliteHandler);
        SetMessagesCurrScrnID(SCR_ID_MSG_INBOX_COPY_ALL_OPTION);

        ShowCategory52Screen(
            STR_SMS_COPY_ALL,
            IMG_SMS_ENTRY_SCRN_CAPTION,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            numItems,
            nStrItemList,
            (U16*) gIndexIconsImageList,
            NULL,
            0,
            0,
            guiBuffer);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_copy_all_from_sim_inbox
 * DESCRIPTION
 *  highlight copy all from sim handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_copy_all_from_sim_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_set_confirm_screen(STR_SMS_FROM_SIM_QUERY_ID, mmi_msg_copy_msg_all_from_sim_inbox, GoBackHistory);
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_entry_confirm_generic,
        GoBackHistory);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_copy_all_from_phone_inbox
 * DESCRIPTION
 *  highlight copy all from phone handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_copy_all_from_phone_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_set_confirm_screen(STR_SMS_FROM_PHONE_QUERY_ID, mmi_msg_copy_msg_all_from_phone_inbox, GoBackHistory);
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_entry_confirm_generic,
        GoBackHistory);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_copy_all_outbox
 * DESCRIPTION
 *  Entry copy all outbox list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_copy_all_outbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_OUTBOX) == MMI_FRM_SMS_INVALID_INDEX)
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_MSG_NOT_READY_YET),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
    }
    else
    {
        EntryNewScreen(SCR_ID_MSG_OUTBOX_COPY_ALL_OPTION, mmi_msg_exit_generic, mmi_msg_entry_copy_all_outbox, NULL);
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_copy_all_outbox *\n");

        guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_OUTBOX_COPY_ALL_OPTION);

        numItems = GetNumOfChild(SMS_OUTBOX_OPT_COPY_ALL_MENUID);
        GetSequenceStringIds(SMS_OUTBOX_OPT_COPY_ALL_MENUID, nStrItemList);

        SetParentHandler(SMS_OUTBOX_OPT_COPY_ALL_MENUID);

        RegisterHighlightHandler(ExecuteCurrHiliteHandler);
        SetMessagesCurrScrnID(SCR_ID_MSG_OUTBOX_COPY_ALL_OPTION);

        ShowCategory52Screen(
            STR_SMS_COPY_ALL,
            IMG_SMS_ENTRY_SCRN_CAPTION,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            numItems,
            nStrItemList,
            (U16*) gIndexIconsImageList,
            NULL,
            0,
            0,
            guiBuffer);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_copy_all_outbox
 * DESCRIPTION
 *  Highlight copy all outbox handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_copy_all_outbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_entry_copy_all_outbox,
        GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_copy_all_from_sim_outbox
 * DESCRIPTION
 *  highlight copy all from sim handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_copy_all_from_sim_outbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_msg_cntx.toDisplayMessageList == TO_DISPLAY_MESSAGE_LIST_OUTBOX)
    {
        mmi_msg_set_confirm_screen(STR_SMS_FROM_SIM_QUERY_ID, mmi_msg_copy_msg_all_from_sim_outbox, GoBackHistory);
    }

#ifdef __MMI_UNIFIED_MESSAGE__
    else if (g_msg_cntx.toDisplayMessageList == TO_DISPLAY_MESSAGE_LIST_UNSENTBOX)
    {
        mmi_msg_set_confirm_screen(STR_SMS_FROM_SIM_QUERY_ID, mmi_msg_copy_msg_all_from_sim_unsentbox, GoBackHistory);
    }
#endif /* __MMI_UNIFIED_MESSAGE__ */

#ifdef __MMI_MESSAGES_DRAFT_BOX__
    else if (g_msg_cntx.toDisplayMessageList == TO_DISPLAY_MESSAGE_LIST_DRAFTBOX)
    {
        mmi_msg_set_confirm_screen(STR_SMS_FROM_SIM_QUERY_ID, mmi_msg_copy_msg_all_from_sim_draftbox, GoBackHistory);
    }
#endif /* __MMI_MESSAGES_DRAFT_BOX__ */ 

    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_entry_confirm_generic,
        GoBackHistory);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_copy_all_from_phone_outbox
 * DESCRIPTION
 *  highlight copy all from phone handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_copy_all_from_phone_outbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_msg_cntx.toDisplayMessageList == TO_DISPLAY_MESSAGE_LIST_OUTBOX)
    {
        mmi_msg_set_confirm_screen(STR_SMS_FROM_PHONE_QUERY_ID, mmi_msg_copy_msg_all_from_phone_outbox, GoBackHistory);
    }

#ifdef __MMI_UNIFIED_MESSAGE__
    else if (g_msg_cntx.toDisplayMessageList == TO_DISPLAY_MESSAGE_LIST_UNSENTBOX)
    {
        mmi_msg_set_confirm_screen(STR_SMS_FROM_PHONE_QUERY_ID, mmi_msg_copy_msg_all_from_phone_unsentbox, GoBackHistory);
    }
#endif /* __MMI_UNIFIED_MESSAGE__ */

#ifdef __MMI_MESSAGES_DRAFT_BOX__
    else if (g_msg_cntx.toDisplayMessageList == TO_DISPLAY_MESSAGE_LIST_DRAFTBOX)
    {
        mmi_msg_set_confirm_screen(STR_SMS_FROM_PHONE_QUERY_ID, mmi_msg_copy_msg_all_from_phone_draftbox, GoBackHistory);
    }
#endif /* __MMI_MESSAGES_DRAFT_BOX__ */ 

    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_entry_confirm_generic,
        GoBackHistory);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

}

#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_move
 * DESCRIPTION
 *  Highlight move handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_move(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 dst_storage = SMSAL_ME;
#ifdef __MMI_DUAL_SIM_MASTER__
    U16 msgbox_type = 0;
#endif /* __MMI_DUAL_SIM_MASTER__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_msg_cntx.toDisplayMessageList)
    {
        case TO_DISPLAY_MESSAGE_LIST_INBOX:
        #ifdef __MMI_DUAL_SIM_MASTER__
            msgbox_type = MMI_FRM_SMS_APP_INBOX;
        #endif /* __MMI_DUAL_SIM_MASTER__ */
            if (mmi_frm_sms_get_storage(MMI_FRM_SMS_APP_INBOX, (U16) g_msg_cntx.currBoxIndex) == SMSAL_ME)
            {
                dst_storage = SMSAL_SM;
            }
            break;
        case TO_DISPLAY_MESSAGE_LIST_OUTBOX:
        #ifdef __MMI_DUAL_SIM_MASTER__
            msgbox_type = MMI_FRM_SMS_APP_OUTBOX;
        #endif /* __MMI_DUAL_SIM_MASTER__ */
            if (mmi_frm_sms_get_storage(MMI_FRM_SMS_APP_OUTBOX, (U16) g_msg_cntx.currBoxIndex) == SMSAL_ME)
            {
                dst_storage = SMSAL_SM;
            }
            break;

#ifdef __MMI_UNIFIED_MESSAGE__
        case TO_DISPLAY_MESSAGE_LIST_UNSENTBOX:
            if (mmi_frm_sms_get_storage(MMI_FRM_SMS_APP_UNSENT, (U16) g_msg_cntx.currBoxIndex) == SMSAL_ME)
            {
                dst_storage = SMSAL_SM;
            }
            break;
#endif /* __MMI_UNIFIED_MESSAGE__ */

        #ifdef __MMI_MESSAGES_DRAFT_BOX__
        case TO_DISPLAY_MESSAGE_LIST_DRAFTBOX:
        #ifdef __MMI_DUAL_SIM_MASTER__
            msgbox_type = MMI_FRM_SMS_APP_DRAFTS;
        #endif /* __MMI_DUAL_SIM_MASTER__ */
            if (mmi_frm_sms_get_storage(MMI_FRM_SMS_APP_DRAFTS, (U16) g_msg_cntx.currBoxIndex) == SMSAL_ME)
            {
                dst_storage = SMSAL_SM;
            }
            break;
        #endif /* __MMI_MESSAGES_DRAFT_BOX__ */ 
    }

    if (dst_storage == SMSAL_SM)
    {
        mmi_msg_set_confirm_screen(STR_SMS_MOVE_TO_SIM_QUERY_ID, mmi_msg_move_msg, GoBackHistory);
    }
    else
    {
        mmi_msg_set_confirm_screen(STR_SMS_MOVE_TO_PHONE_QUERY_ID, mmi_msg_move_msg, GoBackHistory);
    }

    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_entry_confirm_generic,
        GoBackHistory);

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

}


#ifndef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_move_all_inbox
 * DESCRIPTION
 *  Highlight move all inbox handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_move_all_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_entry_move_all_inbox,
        GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_move_all_inbox
 * DESCRIPTION
 *  Entry move all list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_move_all_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_INBOX) == MMI_FRM_SMS_INVALID_INDEX)
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_MSG_NOT_READY_YET),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
    }
    else
    {
        EntryNewScreen(SCR_ID_MSG_INBOX_MOVE_ALL_OPTION, mmi_msg_exit_generic, mmi_msg_entry_move_all_inbox, NULL);
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_move_all_inbox *\n");

        guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_INBOX_MOVE_ALL_OPTION);

        numItems = GetNumOfChild(SMS_INBOX_OPT_MOVE_ALL_MENUID);
        GetSequenceStringIds(SMS_INBOX_OPT_MOVE_ALL_MENUID, nStrItemList);

        SetParentHandler(SMS_INBOX_OPT_MOVE_ALL_MENUID);

        RegisterHighlightHandler(ExecuteCurrHiliteHandler);
        SetMessagesCurrScrnID(SCR_ID_MSG_INBOX_MOVE_ALL_OPTION);

        ShowCategory52Screen(
            STR_SMS_MOVE_ALL,
            IMG_SMS_ENTRY_SCRN_CAPTION,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            numItems,
            nStrItemList,
            (U16*) gIndexIconsImageList,
            NULL,
            0,
            0,
            guiBuffer);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_move_all_from_sim_inbox
 * DESCRIPTION
 *  highlight move all from sim handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_move_all_from_sim_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_set_confirm_screen(STR_SMS_FROM_SIM_QUERY_ID, mmi_msg_move_msg_all_from_sim_inbox, GoBackHistory);
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_entry_confirm_generic,
        GoBackHistory);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_move_all_from_phone_inbox
 * DESCRIPTION
 *  highlight move all from phone handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_move_all_from_phone_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_set_confirm_screen(STR_SMS_FROM_PHONE_QUERY_ID, mmi_msg_move_msg_all_from_phone_inbox, GoBackHistory);
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_entry_confirm_generic,
        GoBackHistory);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_move_all_outbox
 * DESCRIPTION
 *  Entry move all outbox list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_move_all_outbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_OUTBOX) == MMI_FRM_SMS_INVALID_INDEX)
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_MSG_NOT_READY_YET),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
    }
    else
    {
        EntryNewScreen(SCR_ID_MSG_OUTBOX_MOVE_ALL_OPTION, mmi_msg_exit_generic, mmi_msg_entry_move_all_outbox, NULL);
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_move_all_outbox *\n");

        guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_OUTBOX_MOVE_ALL_OPTION);

        numItems = GetNumOfChild(SMS_OUTBOX_OPT_MOVE_ALL_MENUID);
        GetSequenceStringIds(SMS_OUTBOX_OPT_MOVE_ALL_MENUID, nStrItemList);

        SetParentHandler(SMS_OUTBOX_OPT_MOVE_ALL_MENUID);

        RegisterHighlightHandler(ExecuteCurrHiliteHandler);
        SetMessagesCurrScrnID(SCR_ID_MSG_OUTBOX_MOVE_ALL_OPTION);

        ShowCategory52Screen(
            STR_SMS_MOVE_ALL,
            IMG_SMS_ENTRY_SCRN_CAPTION,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            numItems,
            nStrItemList,
            (U16*) gIndexIconsImageList,
            NULL,
            0,
            0,
            guiBuffer);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_move_all_outbox
 * DESCRIPTION
 *  Highlight move all outbox handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_move_all_outbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_entry_move_all_outbox,
        GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_move_all_from_sim_outbox
 * DESCRIPTION
 *  highlight move all from sim handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_move_all_from_sim_outbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_msg_cntx.toDisplayMessageList == TO_DISPLAY_MESSAGE_LIST_OUTBOX)
    {
        mmi_msg_set_confirm_screen(STR_SMS_FROM_SIM_QUERY_ID, mmi_msg_move_msg_all_from_sim_outbox, GoBackHistory);
    }

#ifdef __MMI_UNIFIED_MESSAGE__
    else if (g_msg_cntx.toDisplayMessageList == TO_DISPLAY_MESSAGE_LIST_UNSENTBOX)
    {
        mmi_msg_set_confirm_screen(STR_SMS_FROM_SIM_QUERY_ID, mmi_msg_move_msg_all_from_sim_unsentbox, GoBackHistory);
    }
#endif /* __MMI_UNIFIED_MESSAGE__ */

#ifdef __MMI_MESSAGES_DRAFT_BOX__
    else if (g_msg_cntx.toDisplayMessageList == TO_DISPLAY_MESSAGE_LIST_DRAFTBOX)
    {
        mmi_msg_set_confirm_screen(STR_SMS_FROM_SIM_QUERY_ID, mmi_msg_move_msg_all_from_sim_draftbox, GoBackHistory);
    }
#endif /* __MMI_MESSAGES_DRAFT_BOX__ */ 

    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_entry_confirm_generic,
        GoBackHistory);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_move_all_from_phone_outbox
 * DESCRIPTION
 *  highlight move all from phone handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_move_all_from_phone_outbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_msg_cntx.toDisplayMessageList == TO_DISPLAY_MESSAGE_LIST_OUTBOX)
    {
        mmi_msg_set_confirm_screen(STR_SMS_FROM_PHONE_QUERY_ID, mmi_msg_move_msg_all_from_phone_outbox, GoBackHistory);
    }

#ifdef __MMI_UNIFIED_MESSAGE__
    else if (g_msg_cntx.toDisplayMessageList == TO_DISPLAY_MESSAGE_LIST_UNSENTBOX)
    {
        mmi_msg_set_confirm_screen(STR_SMS_FROM_PHONE_QUERY_ID, mmi_msg_move_msg_all_from_phone_unsentbox, GoBackHistory);
    }
#endif /* __MMI_UNIFIED_MESSAGE__ */

#ifdef __MMI_MESSAGES_DRAFT_BOX__
    else if (g_msg_cntx.toDisplayMessageList == TO_DISPLAY_MESSAGE_LIST_DRAFTBOX)
    {
        mmi_msg_set_confirm_screen(STR_SMS_FROM_PHONE_QUERY_ID, mmi_msg_move_msg_all_from_phone_draftbox, GoBackHistory);
    }
#endif /* __MMI_MESSAGES_DRAFT_BOX__ */ 

    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_entry_confirm_generic,
        GoBackHistory);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

}

#ifdef __MMI_UNIFIED_MESSAGE__


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_advanced
 * DESCRIPTION
 *  Highlight advanced handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_advanced(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_entry_advanced,
        GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_advanced
 * DESCRIPTION
 *  Entry advanced option menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_advanced(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 screen_id = 0;
    U16 menu_id = 0;
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];

    U8 dst_storage = SMSAL_ME;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_msg_cntx.toDisplayMessageList)
    {
        case TO_DISPLAY_MESSAGE_LIST_INBOX:
            screen_id = SCR_ID_MSG_INBOX_ADVANCED_OPTION;
            menu_id = SMS_INBOX_OPT_ADVANCED_MENUID;
            if (mmi_frm_sms_get_storage(MMI_FRM_SMS_APP_INBOX, (U16) g_msg_cntx.currBoxIndex) == SMSAL_ME)
            {
                dst_storage = SMSAL_SM;
            }
            break;

        case TO_DISPLAY_MESSAGE_LIST_UNSENTBOX:
            screen_id = SCR_ID_MSG_OUTBOX_ADVANCED_OPTION;
            menu_id = SMS_OUTBOX_OPT_ADVANCED_MENUID;
            if (mmi_frm_sms_get_storage(MMI_FRM_SMS_APP_UNSENT, (U16) g_msg_cntx.currBoxIndex) == SMSAL_ME)
            {
                dst_storage = SMSAL_SM;
            }
            break;
			
        case TO_DISPLAY_MESSAGE_LIST_OUTBOX:
            screen_id = SCR_ID_MSG_OUTBOX_ADVANCED_OPTION;
            menu_id = SMS_OUTBOX_OPT_ADVANCED_MENUID;
            if (mmi_frm_sms_get_storage(MMI_FRM_SMS_APP_OUTBOX, (U16) g_msg_cntx.currBoxIndex) == SMSAL_ME)
            {
                dst_storage = SMSAL_SM;
            }
            break;
        case TO_DISPLAY_MESSAGE_LIST_DRAFTBOX:
            screen_id = SCR_ID_MSG_OUTBOX_ADVANCED_OPTION;
            menu_id = SMS_OUTBOX_OPT_ADVANCED_MENUID;
            if (mmi_frm_sms_get_storage(MMI_FRM_SMS_APP_DRAFTS, (U16) g_msg_cntx.currBoxIndex) == SMSAL_ME)
            {
                dst_storage = SMSAL_SM;
            }
            break;
    }

    EntryNewScreen(screen_id, mmi_msg_exit_generic, mmi_msg_entry_advanced, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_advanced *\n");

    guiBuffer = GetCurrGuiBuffer(screen_id);

    numItems = GetNumOfChild(menu_id);
    GetSequenceStringIds(menu_id, nStrItemList);

    /* default : copy_to_phone */
    if (dst_storage == SMSAL_SM)
    {
        int i = 0;

        for (i = 0; i < MAX_SUB_MENUS; i++)
        {
            if (nStrItemList[i] == STR_SMS_COPY_TO_PHONE)
            {
                nStrItemList[i] = STR_SMS_COPY_TO_SIM;
                break;
            }
        }
        for (i = 0; i < MAX_SUB_MENUS; i++)
        {
            if (nStrItemList[i] == STR_SMS_MOVE_TO_PHONE)
            {
                nStrItemList[i] = STR_SMS_MOVE_TO_SIM;
                break;
            }
        }
    }

    SetParentHandler(menu_id);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    SetMessagesCurrScrnID(screen_id);

    ShowCategory52Screen(
        STR_SMS_MESSAGES_ADVANCED,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
}

#endif /* __MMI_UNIFIED_MESSAGE__ */ 

#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

#endif /* __MMI_MESSAGES_COPY__ */ /* __MMI_MESSAGES_COPY_ */


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_delete
 * DESCRIPTION
 *  Highlight delete handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_set_confirm_screen(STR_DELETE_SMS_QUERY_ID, mmi_msg_delete_msg, GoBackHistory);

    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_entry_confirm_generic,
        GoBackHistory);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
void mmi_msg_highlight_move_to_archive(void)
{
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_pre_move_msg_to_archive,
        GoBackHistory);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_delete_all_inbox
 * DESCRIPTION
 *  Highlight inbox delete all handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_delete_all_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    if( g_msg_cntx.toDisplayMessageList == TO_DISPLAY_MESSAGE_LIST_ARCHIVE)
    {
        mmi_msg_highlight_generic(
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            mmi_msg_pre_delete_msg_all_archive,
            GoBackHistory);
    }
    else
#endif        
    {

        mmi_msg_highlight_generic(
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            mmi_msg_pre_delete_msg_all_inbox,
            GoBackHistory);
    }
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_delete_all_outbox
 * DESCRIPTION
 *  Highlight outbox delete all handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_delete_all_outbox(void)
{
#if defined(__MMI_MESSAGES_DELETE_ALL_MENU__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    if (g_msg_cntx.toDisplayMessageList == TO_DISPLAY_MESSAGE_LIST_ARCHIVE)
    {
        mmi_msg_highlight_generic(
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            mmi_msg_pre_delete_msg_all_archive,
            GoBackHistory);
    }
    else
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/      
    {
        mmi_msg_highlight_generic(
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            mmi_msg_pre_delete_msg_all_outbox,
            GoBackHistory);
    }
#else /* defined(__MMI_MESSAGES_DELETE_ALL_MENU__) */ 
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    if (g_msg_cntx.toDisplayMessageList == TO_DISPLAY_MESSAGE_LIST_ARCHIVE)
    {
        mmi_msg_highlight_generic(
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            mmi_msg_pre_delete_msg_all_archive,
            GoBackHistory);
    }
    else
#endif 
    if (g_msg_cntx.toDisplayMessageList == TO_DISPLAY_MESSAGE_LIST_OUTBOX)

    {
        mmi_msg_highlight_generic(
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            mmi_msg_pre_delete_msg_all_outbox,
            GoBackHistory);
    }

#ifdef __MMI_UNIFIED_MESSAGE__
    else if (g_msg_cntx.toDisplayMessageList == TO_DISPLAY_MESSAGE_LIST_UNSENTBOX)
    {
        mmi_msg_highlight_generic(
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            mmi_msg_pre_delete_msg_all_unsentbox,
            GoBackHistory);
    }
#endif /* __MMI_UNIFIED_MESSAGE__ */
	
#ifdef __MMI_MESSAGES_DRAFT_BOX__
    else
    {
        mmi_msg_highlight_generic(
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            mmi_msg_pre_delete_msg_all_draftbox,
            GoBackHistory);
    }
#endif /* __MMI_MESSAGES_DRAFT_BOX__ */ 
#endif /* defined(__MMI_MESSAGES_DELETE_ALL_MENU__) */ 
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

#if defined(__MMI_MESSAGES_DELETE_ALL_MENU__) && defined(__MMI_MESSAGES_DRAFT_BOX__)


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_delete_all_draftbox
 * DESCRIPTION
 *  Highlight delete all draftbox handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_delete_all_draftbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_pre_delete_msg_all_draftbox,
        GoBackHistory);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
#endif /* defined(__MMI_MESSAGES_DELETE_ALL_MENU__) && defined(__MMI_MESSAGES_DRAFT_BOX__) */ 

#if defined(__MMI_MESSAGES_EMS__)


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_save_object
 * DESCRIPTION
 *  Highlight save object handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_save_object(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_highlight_save_object *\n");
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);
    SetLeftSoftkeyFunction(EntryScrSaveObjectList, KEY_EVENT_UP);
    SetKeyHandler(EntryScrSaveObjectList, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmsTextSizeHandler
 * DESCRIPTION
 *  Highlight Ems TextS ize Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmsTextSizeHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);
    SetLeftSoftkeyFunction(EntryScrFmtTextSizeMenu, KEY_EVENT_UP);
    SetKeyHandler(EntryScrFmtTextSizeMenu, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmsTextStyleHandler
 * DESCRIPTION
 *  Highlight Ems Text Style Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmsTextStyleHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);
    SetLeftSoftkeyFunction(EntryScrFmtTextStyleMenu, KEY_EVENT_UP);
    SetKeyHandler(EntryScrFmtTextStyleMenu, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmsAlignmentHandler
 * DESCRIPTION
 *  Highlight Ems Alignment Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmsAlignmentHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);
    SetLeftSoftkeyFunction(EntryScrFmtAlignmentMenu, KEY_EVENT_UP);
    SetKeyHandler(EntryScrFmtAlignmentMenu, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmsNewParagraphHandler
 * DESCRIPTION
 *  Highlight Ems New Paragraph Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmsNewParagraphHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);

    SetLeftSoftkeyFunction(EntryScrFmtNewParagraphMenu, KEY_EVENT_UP);
    SetKeyHandler(EntryScrFmtNewParagraphMenu, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmsTextSizeSmallHandler
 * DESCRIPTION
 *  Highlight Ems Text Size Small Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmsTextSizeSmallHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);
    SetLeftSoftkeyFunction(SetFmtTextSize, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmsTextSizeMediumHandler
 * DESCRIPTION
 *  Highlight Ems Text Size Medium Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmsTextSizeMediumHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);
    SetLeftSoftkeyFunction(SetFmtTextSize, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmsTextSizeLargeHandler
 * DESCRIPTION
 *  Highlight Ems Text Size Large Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmsTextSizeLargeHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);
    SetLeftSoftkeyFunction(SetFmtTextSize, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmsTextStyleBoldHandler
 * DESCRIPTION
 *  Highlight Ems Text Style Bold Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmsTextStyleBoldHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);
    SetLeftSoftkeyFunction(SetFmtTextStyle, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmsTextStyleItalicsHandler
 * DESCRIPTION
 *  Highlight Ems Text Style Italics Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmsTextStyleItalicsHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);
    SetLeftSoftkeyFunction(SetFmtTextStyle, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmsTextStyleUnderlineHandler
 * DESCRIPTION
 *  Highlight Ems Text Style Underline Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmsTextStyleUnderlineHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);
    SetLeftSoftkeyFunction(SetFmtTextStyle, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmsTextStyleStrikethroughHandler
 * DESCRIPTION
 *  Highlight Ems Text Style Strikethrough Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmsTextStyleStrikethroughHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);
    SetLeftSoftkeyFunction(SetFmtTextStyle, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmsAlignmentAutomaticHandler
 * DESCRIPTION
 *  Highlight Ems Alignment Automatic Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmsAlignmentAutomaticHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);
    SetLeftSoftkeyFunction(SetFmtTextAlignment, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmsAlignmentLeftHandler
 * DESCRIPTION
 *  Highlight Ems Alignment Left Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmsAlignmentLeftHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);
    SetLeftSoftkeyFunction(SetFmtTextAlignment, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmsAlignmentCenterHandler
 * DESCRIPTION
 *  Highlight Ems Alignment Center Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmsAlignmentCenterHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);
    SetLeftSoftkeyFunction(SetFmtTextAlignment, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmsAlignmentRightHandler
 * DESCRIPTION
 *  Highlight Ems Alignment Right Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmsAlignmentRightHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);
    SetLeftSoftkeyFunction(SetFmtTextAlignment, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmsNewParagraphAutomaticHandler
 * DESCRIPTION
 *  Highlight Ems New Paragraph Automatic Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmsNewParagraphAutomaticHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);
    SetLeftSoftkeyFunction(SetFmtTextNewParagraph, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmsNewParagraphLeftHandler
 * DESCRIPTION
 *  Highlight Ems New Paragraph Left Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmsNewParagraphLeftHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);
    SetLeftSoftkeyFunction(SetFmtTextNewParagraph, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmsNewParagraphCenterHandler
 * DESCRIPTION
 *  Highlight Ems New Paragraph Center Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmsNewParagraphCenterHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);
    SetLeftSoftkeyFunction(SetFmtTextNewParagraph, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmsNewParagraphRightHandler
 * DESCRIPTION
 *  Highlight Ems New Paragraph Right Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmsNewParagraphRightHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);
    SetLeftSoftkeyFunction(SetFmtTextNewParagraph, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}
#endif /* defined(__MMI_MESSAGES_EMS__) */ 

#ifdef __MMI_MESSAGES_DELETE_ALL_MENU__


/*****************************************************************************
 * FUNCTION
 *  HighlightSMSDeleteHandler
 * DESCRIPTION
 *  Highlight SMS delete handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightSMSDeleteHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_entry_delete,
        GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_delete
 * DESCRIPTION
 *  Entry delete screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_DELETE, mmi_msg_exit_generic, mmi_msg_entry_delete, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_delete *\n");
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_DELETE);

    numItems = GetNumOfChild(MESSAGES_MENU_DELETE_MENUID);
    GetSequenceStringIds(MESSAGES_MENU_DELETE_MENUID, nStrItemList);
    SetParentHandler(MESSAGES_MENU_DELETE_MENUID);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DELETE);
    SetMessagesCurrScrnID(SCR_ID_MSG_DELETE);

    ShowCategory52Screen(
        STR_GLOBAL_DELETE,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_delete_all
 * DESCRIPTION
 *  Highlight delete all handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_delete_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_pre_delete_msg_all,
        GoBackHistory);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
#endif /* __MMI_MESSAGES_DELETE_ALL_MENU__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_insert_phb_number
 * DESCRIPTION
 *  Highlight SMS editor insert PHB number handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_insert_phb_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_entry_insert_phb_number,
        GoBackHistory);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_insert_phb_name
 * DESCRIPTION
 *  Highlight SMS editor insert PHB name handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_insert_phb_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_entry_insert_phb_name,
        GoBackHistory);
}

#ifdef WAP_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_insert_bookmark
 * DESCRIPTION
 *  Highlight SMS editor insert bookmark handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_insert_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_entry_insert_bookmark,
        GoBackHistory);
}
#endif /* WAP_SUPPORT */

/* MTK Add By Jo for MMS 20030822 */
#ifdef __MMI_MESSAGES_MULTI_APP__

/*****************************************************************************
 * FUNCTION
 *  HighlightSMSHandler
 * DESCRIPTION
 *  Highlight SMS handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightSMSHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] HighlightSMSHandler*\n");
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);
    SetLeftSoftkeyFunction(EntrySMSMainMenuList, KEY_EVENT_UP);
    SetKeyHandler(EntrySMSMainMenuList, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
#endif /* __MMI_MESSAGES_MULTI_APP__ */ 

#ifdef MMS_SUPPORT


/*****************************************************************************
 * FUNCTION
 *  HighlightMMSHandler
 * DESCRIPTION
 *  Highlight MMS handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void goto_mms_screen(void);
extern void mmi_jmms_templates_view(void);
void HighlightMMSHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] HighlightMMSHandler*\n");
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);
#ifdef WAP_SUPPORT

  //  SetLeftSoftkeyFunction(mmi_jmms_templates_view, KEY_EVENT_UP);
 //  SetKeyHandler(mmi_jmms_templates_view, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

#endif /* WAP_SUPPORT */ 
}
#endif /* MMS_SUPPORT */ 

#ifdef __MMI_MESSAGES_MULTI_APP__


/*****************************************************************************
 * FUNCTION
 *  EntrySMSMainMenuList
 * DESCRIPTION
 *  Entry SMS main menu screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntrySMSMainMenuList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 numItems;
    U16 itemIcons[MAX_SUB_MENUS];
    U8 *popUpList[MAX_SUB_MENUS];

    /* S32 menuItemId=-1;
       S32 menuItemId1=-1;  
       S32 maskingByte=-1; */
    U8 **pPopUpList = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_SMS_MAIN_MENU, mmi_msg_exit_generic, EntrySMSMainMenuList, NULL);

#if (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) || defined(__MMI_SMART_MESSAGE_MT__)
    mmi_nsm_set_msg_type(NORMAL_MESSAGE);
#endif 
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] EntrySMSMainMenuList *\n");
    SetMessagesCurrScrnID(SCR_ID_MSG_SMS_MAIN_MENU);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_SMS_MAIN_MENU);
    SetParentHandler(MESSAGES_MENU_SMS_MENUID);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* diamond, 2005/07/01 add _Ext to menu item functions */
    numItems = GetNumOfChild_Ext(MESSAGES_MENU_SMS_MENUID);
    GetSequenceStringIds_Ext(MESSAGES_MENU_SMS_MENUID, nStrItemList);
    GetSequenceImageIds_Ext(MESSAGES_MENU_SMS_MENUID, itemIcons);

    if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_NOBOX) != MMI_FRM_SMS_INVALID_INDEX)
    {
        msgbox_info.totalinbox = mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_INBOX);
        msgbox_info.totaloutbox = mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_OUTBOX);
        msgbox_info.totaldraftbox = mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_DRAFTS);
        mmi_msg_set_msg_num_hint(msgbox_info.totalinbox, msgbox_info.totaloutbox, msgbox_info.totaldraftbox);
        RefreshMessagesMenuList();
    }

    ConstructHintsList(MESSAGES_MENU_SMS_MENUID, popUpList);
    mmi_msg_set_msg_menu_highlight_handler();

    if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_NOBOX) != MMI_FRM_SMS_INVALID_INDEX)
    {
        pPopUpList = popUpList;
    }
    else
    {
        pPopUpList = NULL;
    }

    /* diamond, 2005/07/01 removed for new menu item architecture to CPHS */
#if 0
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
#endif /* 0 */ 

    g_msg_cntx.currBoxIndex = 0;

    ShowCategory52Screen(
        STR_SMS_MENUENTRY,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_SMS_COMMON_NOIMAGE,
        STR_GLOBAL_BACK,
        IMG_SMS_COMMON_NOIMAGE,
        numItems,
        nStrItemList,
        itemIcons,
        (U8 **) pPopUpList,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);   /* MTK Jo */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

#endif /* __MMI_MESSAGES_MULTI_APP__ */ 


/*****************************************************************************
 * FUNCTION
 *  HighlightWMessageHandler
 * DESCRIPTION
 *  Highlight write message handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightWMessageHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);
    SetLeftSoftkeyFunction(mmi_msg_entry_write_msg, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_msg_entry_write_msg, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    g_msg_cntx.sendMessageCase = SEND_CASE_SEND_ONLY;
    g_msg_cntx.PhbSmsInterfaceState = MMI_SEND_ONLY;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightInboxHandler
 * DESCRIPTION
 *  Highlight inbox handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightInboxHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);
    SetLeftSoftkeyFunction(mmi_msg_pre_entry_inbox_list, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_msg_pre_entry_inbox_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HintInboxHandler
 * DESCRIPTION
 *  Hint inbox handler
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HintInboxHandler(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((PS8) hintData[index], 0, sizeof(hintData[index]));
    mmi_ucs2cpy((PS8) hintData[index], (PS8) TotalInboxOutboxStatus.totalInboxStr);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightOutboxHandler
 * DESCRIPTION
 *  Highlight outbox handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightOutboxHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);
    SetLeftSoftkeyFunction(mmi_msg_pre_entry_outbox_list, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_msg_pre_entry_outbox_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HintOutboxHandler
 * DESCRIPTION
 *  Hint outbox handler
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HintOutboxHandler(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((PS8) hintData[index], 0, sizeof(hintData[index]));
    mmi_ucs2cpy((PS8) hintData[index], (PS8) TotalInboxOutboxStatus.totalOutboxStr);
}

#ifdef __MMI_MESSAGES_DRAFT_BOX__


/*****************************************************************************
 * FUNCTION
 *  HighlightDraftboxHandler
 * DESCRIPTION
 *  Highlight draftbox handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightDraftboxHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);
    SetLeftSoftkeyFunction(mmi_msg_pre_entry_draftbox_list, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_msg_pre_entry_draftbox_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HintDraftboxHandler
 * DESCRIPTION
 *  Hint draftbox handler
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HintDraftboxHandler(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((PS8) hintData[index], 0, sizeof(hintData[index]));
    mmi_ucs2cpy((PS8) hintData[index], (PS8) TotalInboxOutboxStatus.totalDraftboxStr);
}
#endif /* __MMI_MESSAGES_DRAFT_BOX__ */ 

#if defined(__MMI_MESSAGES_TEMPLATE__)


/*****************************************************************************
 * FUNCTION
 *  HighlightTemplatesHandler
 * DESCRIPTION
 *  Highlight template handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightTemplatesHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_msg_entry_template_list, KEY_EVENT_UP);
    SetKeyHandler(mmi_msg_entry_template_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_insert_template
 * DESCRIPTION
 *  Highlight insert template handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_insert_template(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_entry_template_list,
        GoBackHistory);
}
#endif /* defined(__MMI_MESSAGES_TEMPLATE__) */ 


/*****************************************************************************
 * FUNCTION
 *  HighlightVoiceMailHandler
 * DESCRIPTION
 *  Highlight voice madil handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightVoiceMailHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_msg_pre_entry_voice_mail_server, KEY_EVENT_UP);
    SetKeyHandler(mmi_msg_pre_entry_voice_mail_server, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCBHandler
 * DESCRIPTION
 *  Highlight CB Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCBHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_msg_pre_entry_cb_main_menu, KEY_EVENT_UP);
    SetKeyHandler(mmi_msg_pre_entry_cb_main_menu, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

#ifdef __MMI_MESSAGES_CHAT__


/*****************************************************************************
 * FUNCTION
 *  HighlightChatMenu
 * DESCRIPTION
 *  Highlight Chat Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightChatMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);
    SetLeftSoftkeyFunction(EntryChatApp, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntryChatApp, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

/* Added By Alok */


/*****************************************************************************
 * FUNCTION
 *  EnterSmsChatRoom
 * DESCRIPTION
 *  Entry Chat application screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EnterSmsChatRoom(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *number;
    S8 *unicodenumber = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_NOBOX) == MMI_FRM_SMS_INVALID_INDEX)
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_MSG_NOT_READY_YET),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
        return;
    }
    number = (S8*) mmi_frm_sms_get_sms_address(MMI_FRM_SMS_INBOX, (U16) g_msg_cntx.currBoxIndex);
    if (number)
    {
        unicodenumber = OslMalloc((strlen(number) + 1) * ENCODING_LENGTH);
        mmi_asc_n_to_ucs2(unicodenumber, number, strlen(number));
        memset(unicodenumber + strlen(number) * ENCODING_LENGTH, 0, ENCODING_LENGTH);
        ChatInboxInterface((U8*) unicodenumber);
    }
    else
    {
        PRINT_INFORMATION("*-------[SmsMoMtGuiInterface.c] EntryScrUseNumbers (numbersCount <= 0) -------*\n");
        DisplayPopup(
            (PU8) GetString(STR_NONUMBER_NOTIFICATION),
            IMG_GLOBAL_EMPTY,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) EMPTY_LIST_TONE);
        /* DeleteMessagesHistoryNodes (); */
    }
    if (unicodenumber != NULL)
    {
        OslMfree(unicodenumber);
        unicodenumber = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  HilightChatInboxMenu
 * DESCRIPTION
 *  Highlight Inbox Chat Option Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HilightChatInboxMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);
    SetLeftSoftkeyFunction(EnterSmsChatRoom, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EnterSmsChatRoom, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
#endif /* __MMI_MESSAGES_CHAT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_set_msg_menu_highlight_handler
 * DESCRIPTION
 *  Set message menu highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_set_msg_menu_highlight_handler(void)
{
#ifdef __MMI_MESSAGES_MULTI_APP__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UNIFIED_MESSAGE__
    SetHiliteHandler(MENU_ID_UM_MAIN, mmi_um_highlight_main_menu);
#else /* __MMI_UNIFIED_MESSAGE__ */ 
    SetHiliteHandler(MESSAGES_MENU_SMS_MENUID, HighlightSMSHandler);
#ifdef MMS_SUPPORT
    SetHiliteHandler(MESSAGES_MENU_MMS_MENUID, HighlightMMSHandler);
#endif 
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

#ifdef __MMI_MESSAGES_CHAT__
    SetHiliteHandler(MENU_CHATAPP_ID, HighlightChatMenu);
#endif 

#ifdef __MMI_SMARTMESSAGE__
    SetHiliteHandler(MENU_ID_MY_PICTURE, highlight_mypic_handler);
#endif 

#ifdef __MMI_EMAIL__
    SetHiliteHandler(MENU_ID_EMAIL_MAIN, mmi_email_highlight_main_menu);
#endif 

#ifdef __MMI_IMPS__
    SetHiliteHandler(MENU_ID_IMPS_MAIN, mmi_imps_hilite_main);
#endif 

    SetHiliteHandler(MESSAGES_MENU_VMAIL_MENUID, HighlightVoiceMailHandler);
    SetHiliteHandler(MESSAGES_MENU_CB_MENUID, HighlightCBHandler);

#else /* __MMI_MESSAGES_MULTI_APP__ */ 

#ifndef __MMI_UNIFIED_MESSAGE__
    SetHiliteHandler(MESSAGES_MENU_WMESSAGE_MENU_ID, HighlightWMessageHandler);

#if !defined(__MMI_DUAL_SIM_MASTER__)
    SetHiliteHandler(MESSAGES_MENU_INBOX_MENUID, HighlightInboxHandler);
    SetHintHandler(MESSAGES_MENU_INBOX_MENUID, HintInboxHandler);
    SetHiliteHandler(MESSAGES_MENU_OUTBOX_MENUID, HighlightOutboxHandler);
    SetHintHandler(MESSAGES_MENU_OUTBOX_MENUID, HintOutboxHandler);
#else /* __MMI_DUAL_SIM_MASTER__ */
    MTPNP_PFAL_SMS_Init_Show_Style();
#endif /* __MMI_DUAL_SIM_MASTER__ */

#ifdef __MMI_MESSAGES_DRAFT_BOX__
    SetHiliteHandler(MESSAGES_MENU_DRAFTBOX_MENUID, HighlightDraftboxHandler);
    SetHintHandler(MESSAGES_MENU_DRAFTBOX_MENUID, HintDraftboxHandler);
#endif /* __MMI_MESSAGES_DRAFT_BOX__ */ 
#if defined(__MMI_MESSAGES_DELETE_ALL_MENU__)
    SetHiliteHandler(MESSAGES_MENU_DELETE_MENUID, HighlightSMSDeleteHandler);
#endif 
#if defined(__MMI_MESSAGES_TEMPLATE__)
    SetHiliteHandler(MESSAGES_MENU_TEMPLATES_MENUID, HighlightTemplatesHandler);
#endif 
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
    SetHiliteHandler(MESSAGES_MENU_MSG_SETTINGS_MENUID, mmi_msg_highlight_msg_settings);
    SetHiliteHandler(MESSAGES_MENU_VMAIL_MENUID, HighlightVoiceMailHandler);
    SetHiliteHandler(MESSAGES_MENU_CB_MENUID, HighlightCBHandler);
#endif /* __MMI_MESSAGES_MULTI_APP__ */ 

    SetHiliteHandler(SETUP_MENU_PROFILE_SETTING_MENUID, mmi_msg_highlight_profile_settings);
    SetHiliteHandler(SETUP_MENU_COMMONSETTING_MENUID, mmi_msg_highlight_common_settings);
#if defined(__MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__)
    SetHiliteHandler(MESSAGES_MENU_MEMSTATUS_MENUID, mmi_msg_highlight_memory_status);
#ifndef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    SetHiliteHandler(SETUP_MENU_PREFEREDSTORAGE_MENUID, mmi_msg_highlight_preferred_storage);
    SetHintHandler(SETUP_MENU_PREFEREDSTORAGE_MENUID, mmi_msg_hint_preferred_storage);
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
#endif /* defined(__MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__) */ 
    /* MTK Joy added for GPRS support, 1216 */
#if defined(__MMI_GPRS_FEATURES__) && (!defined(__MMI_DUAL_SIM_MASTER__))
    SetHiliteHandler(SETUP_MENU_PREFEREDBEARER_MENUID, mmi_msg_highlight_bearer_settings);
    SetHintHandler(SETUP_MENU_PREFEREDBEARER_MENUID, mmi_msg_hint_bearer_settings);
#endif /* defined(__MMI_GPRS_FEATURES__) && (!defined(__MMI_DUAL_SIM_MASTER__)) */ 
    /* MTK end */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_set_highlight_handler
 * DESCRIPTION
 *  Set message highlight handler, for masking menu item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_set_highlight_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_UNIFIED_MESSAGE__
#ifdef __MMI_MESSAGES_MULTI_APP__
    SetHiliteHandler(MESSAGES_MENU_SMS_MENUID, HighlightSMSHandler);
#endif 
#ifdef MMS_SUPPORT
    SetHiliteHandler(MESSAGES_MENU_MMS_MENUID, HighlightMMSHandler);
#endif // #ifdef MMS_SUPPORT
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

#ifdef __MMI_MESSAGES_CHAT__
    SetHiliteHandler(MENU_CHATAPP_ID, HighlightChatMenu);
#endif 
#ifdef __MMI_EMAIL__
    SetHiliteHandler(MENU_ID_EMAIL_MAIN, mmi_email_highlight_main_menu);
#endif 

#ifndef __MMI_UNIFIED_MESSAGE__
    SetHiliteHandler(MESSAGES_MENU_WMESSAGE_MENU_ID, HighlightWMessageHandler);

#if !defined(__MMI_DUAL_SIM_MASTER__)
    SetHiliteHandler(MESSAGES_MENU_INBOX_MENUID, HighlightInboxHandler);
    SetHintHandler(MESSAGES_MENU_INBOX_MENUID, HintInboxHandler);
    SetHiliteHandler(MESSAGES_MENU_OUTBOX_MENUID, HighlightOutboxHandler);
    SetHintHandler(MESSAGES_MENU_OUTBOX_MENUID, HintOutboxHandler);
#else /* __MMI_DUAL_SIM_MASTER__ */
    MTPNP_PFAL_SMS_Init_Show_Style();
#endif /* __MMI_DUAL_SIM_MASTER__ */

#ifdef __MMI_MESSAGES_DRAFT_BOX__
    SetHiliteHandler(MESSAGES_MENU_DRAFTBOX_MENUID, HighlightDraftboxHandler);
    SetHintHandler(MESSAGES_MENU_DRAFTBOX_MENUID, HintDraftboxHandler);
#endif /* __MMI_MESSAGES_DRAFT_BOX__ */ 
#if defined(__MMI_MESSAGES_TEMPLATE__)
    SetHiliteHandler(MESSAGES_MENU_TEMPLATES_MENUID, HighlightTemplatesHandler);
#endif 
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

    SetHiliteHandler(MESSAGES_MENU_MSG_SETTINGS_MENUID, mmi_msg_highlight_msg_settings);
    SetHiliteHandler(MESSAGES_MENU_VMAIL_MENUID, HighlightVoiceMailHandler);
    SetHiliteHandler(MESSAGES_MENU_CB_MENUID, HighlightCBHandler);
#ifdef __MMI_MESSAGES_DELETE_ALL_MENU__
    SetHiliteHandler(MESSAGES_MENU_DELETE_MENUID, HighlightSMSDeleteHandler);
    SetHiliteHandler(MESSAGES_MENU_DELETE_INBOX_MENUID, mmi_msg_highlight_delete_all_inbox);
    SetHiliteHandler(MESSAGES_MENU_DELETE_OUTBOX_MENUID, mmi_msg_highlight_delete_all_outbox);
#ifdef __MMI_MESSAGES_DRAFT_BOX__
    SetHiliteHandler(MESSAGES_MENU_DELETE_DRAFTBOX_MENUID, mmi_msg_highlight_delete_all_draftbox);
#endif 
    SetHiliteHandler(MESSAGES_MENU_DELETE_ALL_MENUID, mmi_msg_highlight_delete_all);
#endif /* __MMI_MESSAGES_DELETE_ALL_MENU__ */ 
    SetHiliteHandler(SEND_OPT_SEND_ONLY_MENUID, mmi_msg_highlight_send_only);
#ifdef __MMI_SEND_BY_SEARCH_NAME__
    SetHiliteHandler(SEND_OPT_SEND_BY_NUMBER, mmi_msg_highlight_send_only_number);
    SetHiliteHandler(SEND_OPT_SEND_BY_NAME, mmi_msg_highlight_send_only_name);
#endif /* __MMI_SEND_BY_SEARCH_NAME__ */ 
    SetHiliteHandler(SEND_OPT_SAVE_AND_SEND_MENUID, mmi_msg_highlight_send_and_save);
    SetHiliteHandler(SEND_OPT_SAVE_MENUID, mmi_msg_highlight_save);
#if defined(__MMI_MESSAGES_SEND_TO_MANY__)
    SetHiliteHandler(SEND_OPT_SEND_TO_MANY_MENUID, mmi_msg_highlight_send_to_many);
#endif 
#if defined(__MMI_MESSAGES_SEND_BY_GROUP__)
    SetHiliteHandler(SEND_OPT_SEND_BY_GROUP_MENUID, mmi_msg_highlight_send_by_group);
#endif 

#if defined(__MMI_MESSAGES_SEND_TO_MANY__)
    SetHiliteHandler(SEND_OPT_SEND_TO_MANY_BY_LIST, mmi_msg_highlight_send_to_many_list);
    SetHiliteHandler(SEND_OPT_SEND_TO_MANY_NOW, mmi_msg_highlight_send_to_many_now);
    SetHiliteHandler(SEND_OPT_SEND_TO_MANY_BY_LIST_EDIT, mmi_msg_highlight_send_to_many_list_edit);
    SetHiliteHandler(SEND_OPT_SEND_TO_MANY_BY_LIST_ERASE, mmi_msg_highlight_send_to_many_list_erase);
#endif /* defined(__MMI_MESSAGES_SEND_TO_MANY__) */ 

#ifdef __MMI_MESSAGES_CHAT__
    SetHiliteHandler(SMS_INBOX_OPT_CHAT_MENUID, HilightChatInboxMenu);
#endif 

#ifdef __MMI_UNIFIED_MESSAGE__
#ifdef __MMI_MESSAGES_COPY__
#ifndef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    SetHiliteHandler(SMS_INBOX_OPT_ADVANCED_MENUID, mmi_msg_highlight_advanced);
    SetHiliteHandler(SMS_OUTBOX_OPT_ADVANCED_MENUID, mmi_msg_highlight_advanced);
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */ 
#endif /* __MMI_MESSAGES_COPY__ */
#ifndef __MMI_DUAL_SIM_MASTER__
    SetHiliteHandler(SMS_OUTBOX_OPT_FORWARD_MENUID, mmi_msg_highlight_forward);
#endif /* __MMI_DUAL_SIM_MASTER__ */

#endif /* __MMI_UNIFIED_MESSAGE__ */ 

#if defined(__MMI_MYPICTURE__)
    SetHiliteHandler(MENU_ID_MY_PICTURE, highlight_mypic_handler);
    SetHiliteHandler(MENU_ID_MYPIC_INSERT_TEXT_DONE, highlight_mypic_insert_text_done);
    SetHiliteHandler(MENU_ID_MYPIC_DONE, highlight_mypic_done_handler);
#endif /* defined(__MMI_MYPICTURE__) */ 
#if defined(__MMI_MYPICTURE__) || defined(__MMI_SMART_MESSAGE_MT__)
    SetHiliteHandler(MENU_ID_MYPIC_INSERT_TEXT_DONE, highlight_mypic_insert_text_done);
    SetHiliteHandler(MENU_ID_MYPIC_ADDTEXT, highlight_mypic_addtext_handler);
    /* SetHiliteHandler(    MENU_ID_MYPIC_SEND_ONLY,        highlight_mypic_send_handler); */
    SetHiliteHandler(MENU_ID_MYPIC_SEND_ONLY, mmi_msg_highlight_send_only);
#if defined(__MMI_MESSAGES_SEND_TO_MANY__)
    SetHiliteHandler(MENU_ID_MYPIC_SEND_TO_MANY, mmi_msg_highlight_send_to_many);
#endif 
#if defined(__MMI_MESSAGES_SEND_BY_GROUP__)
    SetHiliteHandler(MENU_ID_MYPIC_SEND_BY_GROUP, mmi_msg_highlight_send_by_group);
#endif 
    SetHiliteHandler(MENU_ID_MYPIC_INSERT_TEXT_INPUT_METHOD, mmi_msg_highlight_input_method_generic);
    SetHiliteHandler(MENU_ID_PIC_MSG_EDIT_TEXT_DONE, highlight_pic_msg_edit_text_done);
    SetHiliteHandler(MENU_ID_PIC_MSG_EDIT_TEXT_INPUT_METHOD, mmi_msg_highlight_input_method_generic);

#endif /* defined(__MMI_MYPICTURE__) || defined(__MMI_SMART_MESSAGE_MT__) */ 

#if defined(__MMI_SMART_MESSAGE_MT__) || (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))
    SetHiliteHandler(MENU_ID_NSM_RINGTONE_PLAY, HighlightNsmRingtoneoptionplayHandler);
    SetHiliteHandler(MENU_ID_NSM_RINGTONE_REPLY, mmi_msg_highlight_reply);
    SetHiliteHandler(MENU_ID_NSM_RINGTONE_SAVE, HighlightNsmRingtoneoptionsaveHandler);
    SetHiliteHandler(MENU_ID_SAVE_PIC_DONE, highlight_save_pic_msg_done);
    SetHiliteHandler(MENU_ID_SAVE_PIC_INPUT_METHOD, mmi_msg_highlight_input_method_generic);
    SetHiliteHandler(MENU_ID_SAVE_RINGTONE_DONE, highlight_save_ringtone_done);
    SetHiliteHandler(MENU_ID_SAVE_RINGTONE_INPUT_METHOD, mmi_msg_highlight_input_method_generic);
    SetHiliteHandler(MENU_ID_NSM_RINGTONE_DELETE, mmi_msg_highlight_delete);
    SetHiliteHandler(MENU_ID_NSM_PICMSG_REPLY, mmi_msg_highlight_reply);
    SetHiliteHandler(MENU_ID_NSM_PICMSG_USE_NUMBER, mmi_msg_highlight_use_number);
    SetHiliteHandler(MENU_ID_NSM_PICMSG_EDIT, mmi_msg_highlight_edit);
    SetHiliteHandler(MENU_ID_NSM_PICMSG_DELETE, mmi_msg_highlight_delete);
    SetHiliteHandler(MENU_ID_NSM_PICMSG_FORWARD, mmi_msg_highlight_edit);
    SetHiliteHandler(MENU_ID_NSM_PICMSG_SAVE_PICTURE, HighlightPicmsgSavePictureHandler);

    SetHiliteHandler(MENU_ID_NSM_RTONE_USE_NUMBER, mmi_msg_highlight_use_number);

    SetHiliteHandler(MENU_ID_NSM_RTONE_DELETE_ALL, mmi_msg_highlight_delete_all_inbox);
    SetHiliteHandler(MENU_ID_NSM_PICMSG_DELETE_ALL, mmi_msg_highlight_delete_all_inbox);

#ifdef __MMI_MESSAGES_CHAT__
    SetHiliteHandler(MENUID_INBOX_PICMSG_OPT_CHAT, HilightChatInboxMenu);
#endif 

#if (defined( __MMI_MESSAGES_COPY__) && !defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__))
    SetHiliteHandler(MENUID_NSM_RTONE_COPY_TO_PHONE, mmi_msg_highlight_copy);
    SetHiliteHandler(MENUID_NSM_RTONE_MOVE_TO_PHONE, mmi_msg_highlight_move);
    SetHiliteHandler(MENUID_NSM_RTONE_COPY_ALL, mmi_msg_highlight_copy_all_inbox);
    SetHiliteHandler(MENUID_NSM_RTONE_COPY_ALL_FROM_SIM, mmi_msg_highlight_copy_all_from_sim_inbox);
    SetHiliteHandler(MENUID_NSM_RTONE_COPY_ALL_FROM_PHONE, mmi_msg_highlight_copy_all_from_phone_inbox);
    SetHiliteHandler(MENUID_NSM_RTONE_MOVE_ALL, mmi_msg_highlight_move_all_inbox);
    SetHiliteHandler(MENUID_NSM_RTONE_MOVE_ALL_FROM_SIM, mmi_msg_highlight_move_all_from_sim_inbox);
    SetHiliteHandler(MENUID_NSM_RTONE_MOVE_ALL_FROM_PHONE, mmi_msg_highlight_move_all_from_phone_inbox);

    SetHiliteHandler(MENUID_INBOX_PICMSG_OPT_COPY_TO_PHONE, mmi_msg_highlight_copy);
    SetHiliteHandler(MENUID_INBOX_PICMSG_OPT_MOVE_TO_PHONE, mmi_msg_highlight_move);
    SetHiliteHandler(MENUID_INBOX_PICMSG_OPT_COPY_ALL, mmi_msg_highlight_copy_all_inbox);
    SetHiliteHandler(MENUID_INBOX_PICMSG_COPY_ALL_FROM_SIM, mmi_msg_highlight_copy_all_from_sim_inbox);
    SetHiliteHandler(MENUID_INBOX_PICMSG_COPY_ALL_FROM_PHONE, mmi_msg_highlight_copy_all_from_phone_inbox);
    SetHiliteHandler(MENUID_INBOX_PICMSG_OPT_MOVE_ALL, mmi_msg_highlight_move_all_inbox);
    SetHiliteHandler(MENUID_INBOX_PICMSG_MOVE_ALL_FROM_SIM, mmi_msg_highlight_move_all_from_sim_inbox);
    SetHiliteHandler(MENUID_INBOX_PICMSG_MOVE_ALL_FROM_PHONE, mmi_msg_highlight_move_all_from_phone_inbox);

#endif /* __MMI_MESSAGES_COPY__ */ 

#if defined(__MMI_MESSAGES_USE_URL__)
    SetHiliteHandler(MENU_ID_RINGTONE_OPT_USE_URL, mmi_msg_highlight_use_url);
    SetHiliteHandler(MENU_ID_PICMSG_OPT_USE_URL, mmi_msg_highlight_use_url);
#endif /* defined(__MMI_MESSAGES_USE_URL__) */ 

#if defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)
    SetHiliteHandler(MENU_ID_NSM2_INSERT_PIC, highlight_nsm2_insert_picture_handler);

    SetHiliteHandler(MENU_ID_NSM2_REMOVE_PIC, highlight_nsm_remove_picture);

#if !defined(__MMI_MESSAGES_EMS__)
    SetHiliteHandler(EMS_ED_OPT_INS_OBJ, HighlightEditOptionInsertObject);
    SetHiliteHandler(EMS_INS_OBJ_PICTURE, Highlight_nsm_insert_SYS_Picture);
#endif /* !defined(__MMI_MESSAGES_EMS__) */ 

    SetHiliteHandler(EMS_INS_OBJ_MY_PICTURE, highlight_nsm2_insert_picture_handler);

#endif /* defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__) */ 
#endif /* defined(__MMI_SMART_MESSAGE_MT__) || (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) */ 

    SetHiliteHandler(EMS_ED_OPT_INS_PHB_NUMBER, mmi_msg_highlight_insert_phb_number);
    SetHiliteHandler(EMS_ED_OPT_INS_PHB_NAME, mmi_msg_highlight_insert_phb_name);
#ifdef WAP_SUPPORT    
    SetHiliteHandler(EMS_ED_OPT_INS_BOOKMARK, mmi_msg_highlight_insert_bookmark);
#endif /* WAP_SUPPORT */    

    SetHiliteHandler(SMS_INBOX_OPT_REPLY_MENUID, mmi_msg_highlight_reply);
    SetHiliteHandler(SMS_INBOX_OPT_EDIT_MENUID, mmi_msg_highlight_edit);
	
#ifndef __MMI_DUAL_SIM_MASTER__
    SetHiliteHandler(SMS_INBOX_OPT_FORWARD_MENUID, mmi_msg_highlight_forward);
#endif /* __MMI_DUAL_SIM_MASTER__ */

#if (defined( __MMI_MESSAGES_COPY__) && !defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__))
    SetHiliteHandler(SMS_INBOX_OPT_COPY_MENUID, mmi_msg_highlight_copy);
    SetHiliteHandler(SMS_INBOX_OPT_COPY_ALL_MENUID, mmi_msg_highlight_copy_all_inbox);
    SetHiliteHandler(SMS_INBOX_OPT_COPY_ALL_FROM_SIM_MENUID, mmi_msg_highlight_copy_all_from_sim_inbox);
    SetHiliteHandler(SMS_INBOX_OPT_COPY_ALL_FROM_PHONE_MENUID, mmi_msg_highlight_copy_all_from_phone_inbox);
    SetHiliteHandler(SMS_INBOX_OPT_MOVE_MENUID, mmi_msg_highlight_move);
    SetHiliteHandler(SMS_INBOX_OPT_MOVE_ALL_MENUID, mmi_msg_highlight_move_all_inbox);
    SetHiliteHandler(SMS_INBOX_OPT_MOVE_ALL_FROM_SIM_MENUID, mmi_msg_highlight_move_all_from_sim_inbox);
    SetHiliteHandler(SMS_INBOX_OPT_MOVE_ALL_FROM_PHONE_MENUID, mmi_msg_highlight_move_all_from_phone_inbox);
#endif /* __MMI_MESSAGES_COPY__ */ /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
    SetHiliteHandler(SMS_INBOX_OPT_DELETE_MENUID, mmi_msg_highlight_delete);
    SetHiliteHandler(SMS_INBOX_OPT_DELETE_ALL_MENUID, mmi_msg_highlight_delete_all_inbox);
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__    
    SetHiliteHandler(SMS_INBOX_OPT_MOVE_TO_ARCHIVE_MENUID, mmi_msg_highlight_move_to_archive);  
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
    SetHiliteHandler(SMS_INBOX_OPT_USE_NUMBER_MENUID, mmi_msg_highlight_use_number);
#if defined(__MMI_MESSAGES_USE_URL__)
    SetHiliteHandler(MENU_ID_SMS_INBOX_OPT_USE_URL, mmi_msg_highlight_use_url);
    SetHiliteHandler(MENU_ID_SMS_OUTBOX_OPT_USE_URL, mmi_msg_highlight_use_url);
#endif /* defined(__MMI_MESSAGES_USE_URL__) */ 

#ifdef __MMI_EMAIL__
    SetHiliteHandler(MENU_ID_SMS_INBOX_OPT_USE_EMAIL_ADDRESS, mmi_msg_highlight_use_email_address);
    SetHiliteHandler(MENU_ID_SMS_OUTBOX_OPT_USE_EMAIL_ADDRESS, mmi_msg_highlight_use_email_address);
	SetHiliteHandler(MENU_ID_SMS_USE_EMAIL_ADDR_OPT_SEND, mmi_msg_highlight_use_email_addr_opt_send);
	SetHiliteHandler(MENU_ID_SMS_USE_EMAIL_ADDR_OPT_SAVE, mmi_msg_highlight_use_email_addr_opt_save);
#endif /* __EMAIL__ */ 

#if defined(__MMI_MESSAGES_EMS__)
    SetHiliteHandler(SMS_INBOX_OPT_SAVE_OBJECT_MENUID, mmi_msg_highlight_save_object);
#endif 

    SetHiliteHandler(SMS_OUTBOX_OPT_SEND_MENUID, mmi_msg_highlight_send_outbox);
    SetHiliteHandler(SMS_OUTBOX_OPT_EDIT_MENUID, mmi_msg_highlight_edit);
#if (defined( __MMI_MESSAGES_COPY__) && !defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__))
    SetHiliteHandler(SMS_OUTBOX_OPT_COPY_MENUID, mmi_msg_highlight_copy);
    SetHiliteHandler(SMS_OUTBOX_OPT_COPY_ALL_MENUID, mmi_msg_highlight_copy_all_outbox);
    SetHiliteHandler(SMS_OUTBOX_OPT_COPY_ALL_FROM_SIM_MENUID, mmi_msg_highlight_copy_all_from_sim_outbox);
    SetHiliteHandler(SMS_OUTBOX_OPT_COPY_ALL_FROM_PHONE_MENUID, mmi_msg_highlight_copy_all_from_phone_outbox);
    SetHiliteHandler(SMS_OUTBOX_OPT_MOVE_MENUID, mmi_msg_highlight_move);
    SetHiliteHandler(SMS_OUTBOX_OPT_MOVE_ALL_MENUID, mmi_msg_highlight_move_all_outbox);
    SetHiliteHandler(SMS_OUTBOX_OPT_MOVE_ALL_FROM_SIM_MENUID, mmi_msg_highlight_move_all_from_sim_outbox);
    SetHiliteHandler(SMS_OUTBOX_OPT_MOVE_ALL_FROM_PHONE_MENUID, mmi_msg_highlight_move_all_from_phone_outbox);
#endif /* __MMI_MESSAGES_COPY__ */ /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
    SetHiliteHandler(SMS_OUTBOX_OPT_DELETE_MENUID, mmi_msg_highlight_delete);
    SetHiliteHandler(SMS_OUTBOX_OPT_DELETE_ALL_MENUID, mmi_msg_highlight_delete_all_outbox);
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    SetHiliteHandler(SMS_OUTBOX_OPT_MOVE_TO_ARCHIVE_MENUID, mmi_msg_highlight_move_to_archive); 	
#endif/* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
    SetHiliteHandler(SMS_OUTBOX_OPT_USE_NUMBERS_MENUID, mmi_msg_highlight_use_number);
    SetHiliteHandler(SMS_USE_NUM_OPT_DIAL, mmi_msg_highlight_dial_use_number);
    SetHiliteHandler(SMS_USE_NUM_OPT_SAVE, mmi_msg_highlight_save_use_number);
	SetHiliteHandler(SMS_USE_NUM_OPT_SEND_SMS, mmi_msg_highlight_send_sms_use_number);

#if defined(__MMI_MESSAGES_TEMPLATE__)
    SetHiliteHandler(TEMPLATES_OPTIONS_ERASE_MENUENTRY, mmi_msg_highlight_erase_template);
    SetHiliteHandler(TEMPLATES_OPTIONS_EDIT_MENUENTRY, mmi_msg_highlight_edit_template);
    SetHiliteHandler(TEMPLATES_OPTIONS_WRITE_MESSAGE_MENUENTRY, mmi_msg_highlight_template_write_msg);

    SetHiliteHandler(SMS_ED_TEMPL_OPT_DONE_MENU, mmi_msg_highlight_save_template);
    SetHiliteHandler(SMS_ED_TEMPL_OPT_INPUT_METHODS_MENU, mmi_msg_highlight_input_method_generic);
#endif /* defined(__MMI_MESSAGES_TEMPLATE__) */ 

#if defined(__MMI_MESSAGES_EMS__)
    /* For NOn-Inline Edit screen */
    SetHiliteHandler(SMS_INBOX_OPT_SAVE_OPTION_DONE, HighlightEmsSaveObjectDone);
    SetHiliteHandler(SMS_INBOX_OPT_SAVE_OPTION_INPUT_METHOD, mmi_msg_highlight_input_method_generic);
#endif /* defined(__MMI_MESSAGES_EMS__) */ 

    SetHiliteHandler(SETUP_MENU_PROFILE_SETTING_MENUID, mmi_msg_highlight_profile_settings);
    SetHiliteHandler(SETUP_MENU_COMMONSETTING_MENUID, mmi_msg_highlight_common_settings);
#if defined(__MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__)
    SetHiliteHandler(MESSAGES_MENU_MEMSTATUS_MENUID, mmi_msg_highlight_memory_status);
#ifndef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    SetHiliteHandler(SETUP_MENU_PREFEREDSTORAGE_MENUID, mmi_msg_highlight_preferred_storage);
    SetHintHandler(SETUP_MENU_PREFEREDSTORAGE_MENUID, mmi_msg_hint_preferred_storage);
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
#endif /* defined(__MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__) */ 
#if defined(__MMI_GPRS_FEATURES__) && (!defined(__MMI_DUAL_SIM_MASTER__))
    SetHiliteHandler(SETUP_MENU_PREFEREDBEARER_MENUID, mmi_msg_highlight_bearer_settings);
    SetHintHandler(SETUP_MENU_PREFEREDBEARER_MENUID, mmi_msg_hint_bearer_settings);
#endif /* defined(__MMI_GPRS_FEATURES__) && (!defined(__MMI_DUAL_SIM_MASTER__)) */ 

    SetHiliteHandler(SMS_CLSASS0_OPT_USE_NUMBER_MENUID, mmi_msg_highlight_class0_opt_use_number);
#ifdef __MMI_MESSAGES_USE_URL__
    SetHiliteHandler(SMS_CLSASS0_OPT_USE_URL_MENUID, mmi_msg_highlight_class0_opt_use_url);
#endif /* __MMI_MESSAGES_USE_URL__ */

    SetHiliteHandler(MENU_ITEM_VM_1_EDIT, mmi_msg_highlight_voice_mail_server_edit);
    SetHiliteHandler(MENU_ITEM_VM_3_CONNECT_TO_VOICE, mmi_msg_highlight_voice_mail_server_dial);

    /* Set EMS Hilight Hanglers */
    SetHiliteHandler(EMS_ED_OPT_DONE, mmi_msg_highlight_done);
#if defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)
    SetHiliteHandler(EMS_ED_OPT_INPUT_METHOD, mmi_msg_highlight_input_method_generic);
#else 
    SetHiliteHandler(EMS_ED_OPT_INPUT_METHOD, mmi_msg_highlight_input_method);
#endif 

#if defined(__MMI_MESSAGES_TEMPLATE__)
    SetHiliteHandler(EMS_ED_OPT_USE_TEMPLATES, mmi_msg_highlight_insert_template);
#endif 

#if defined(__MMI_MESSAGES_EMS__)
    SetHiliteHandler(EMS_ED_OPT_INS_OBJ, HighlightEditOptionInsertObject);
#endif 

#if defined(__MMI_MESSAGES_EMS__)
    SetHiliteHandler(EMS_INS_OBJ_PICTURE, HighlightInsObjPicture);
    SetHiliteHandler(EMS_INS_OBJ_MY_PICTURE, HighlightInsObjMyPicture);
    SetHiliteHandler(EMS_INS_OBJ_PRED_ANIMATION, HighlightInsObjPredefinedAnimation);
    SetHiliteHandler(EMS_INS_OBJ_MY_ANIMATION, HighlightInsObjMyAnimation);
#if defined(__MMI_IMELODY_SUPPORT__)
    SetHiliteHandler(EMS_INS_OBJ_MELODY, HighlightInsObjMelody);
    SetHiliteHandler(EMS_INS_OBJ_MY_MELODY, HighlightInsObjMyMelody);
#endif /* defined(__MMI_IMELODY_SUPPORT__) */ 
    SetHiliteHandler(EMS_INS_OBJ_PRED_SOUND, HighlightInsObjPredefinedSound);

    SetHiliteHandler(MENU_EMS_FORMATING_TEXT_ID, HighlightEmsFormattingTextHandler);
    SetHiliteHandler(MENU_EMS_TEXT_SIZE_ID, HighlightEmsTextSizeHandler);
    SetHiliteHandler(MENU_EMS_TEXT_STYLE_ID, HighlightEmsTextStyleHandler);
    SetHiliteHandler(MENU_EMS_ALIGNMENT_ID, HighlightEmsAlignmentHandler);
    SetHiliteHandler(MENU_EMS_NEW_PARAGRAPH_ID, HighlightEmsNewParagraphHandler);
    SetHiliteHandler(MENU_EMS_TEXT_SIZE_SMALL_ID, HighlightEmsTextSizeSmallHandler);
    SetHiliteHandler(MENU_EMS_TEXT_SIZE_MEDIUM_ID, HighlightEmsTextSizeMediumHandler);
    SetHiliteHandler(MENU_EMS_TEXT_SIZE_LARGE_ID, HighlightEmsTextSizeLargeHandler);
    SetHiliteHandler(MENU_EMS_TEXT_STYLE_BOLD_ID, HighlightEmsTextStyleBoldHandler);
    SetHiliteHandler(MENU_EMS_TEXT_STYLE_ITALICS_ID, HighlightEmsTextStyleItalicsHandler);
    SetHiliteHandler(MENU_EMS_TEXT_STYLE_UNDERLINE_ID, HighlightEmsTextStyleUnderlineHandler);
    SetHiliteHandler(MENU_EMS_TEXT_STYLE_STRIKETHROUGH_ID, HighlightEmsTextStyleStrikethroughHandler);
    SetHiliteHandler(MENU_EMS_ALIGNMENT_AUTOMATIC_ID, HighlightEmsAlignmentAutomaticHandler);
    SetHiliteHandler(MENU_EMS_ALIGNMENT_LEFT_ID, HighlightEmsAlignmentLeftHandler);
    SetHiliteHandler(MENU_EMS_ALIGNMENT_CENTER_ID, HighlightEmsAlignmentCenterHandler);
    SetHiliteHandler(MENU_EMS_ALIGNMENT_RIGHT_ID, HighlightEmsAlignmentRightHandler);
    SetHiliteHandler(MENU_EMS_NEW_PARAGRAPH_AUTOMATIC_ID, HighlightEmsNewParagraphAutomaticHandler);
    SetHiliteHandler(MENU_EMS_NEW_PARAGRAPH_LEFT_ID, HighlightEmsNewParagraphLeftHandler);
    SetHiliteHandler(MENU_EMS_NEW_PARAGRAPH_CENTER_ID, HighlightEmsNewParagraphCenterHandler);
    SetHiliteHandler(MENU_EMS_NEW_PARAGRAPH_RIGHT_ID, HighlightEmsNewParagraphRightHandler);
#endif /* defined(__MMI_MESSAGES_EMS__) */ 
#ifdef __MMI_MESSAGES_USE_URL__
    SetHiliteHandler(MENU_ID_SMS_USE_URL_CONNECT, HighlightUseURLOptConnectHandler);
    SetHiliteHandler(MENU_ID_SMS_USE_URL_ADD_TO_BOOKMARK, mmi_msg_highlight_use_url_add_to_bookmark);
#endif /* __MMI_MESSAGES_USE_URL__ */ 

#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__

    SetHiliteHandler(SMS_INBOX_OPT_VIEW_MENUID, mmi_msg_highlight_view);
    SetHiliteHandler(SMS_OUTBOX_OPT_VIEW_MENUID, mmi_msg_highlight_view);
    SetHiliteHandler(SMS_SR_OPT_VIEW_MENUID, mmi_msg_highlight_view);
    SetHiliteHandler(SMS_DEFAULT_OPT_VIEW_MENUID, mmi_msg_highlight_view);

#endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */

#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
    SetHiliteHandler(SMS_SIM_OPT_VIEW_MENUID, mmi_msg_highlight_view);
#endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */
    SetHiliteHandler(SMS_SIM_OPT_DELETE_MENUID, mmi_msg_highlight_delete);
    SetHiliteHandler(SMS_SIM_OPT_DELETE_ALL_MENUID, mmi_msg_highlight_delete_all_simbox);
#ifdef __MMI_MESSAGES_COPY__
    SetHiliteHandler(SMS_SIM_OPT_COPY_MENUID, mmi_msg_highlight_copy);
    SetHiliteHandler(SMS_SIM_OPT_COPY_ALL_MENUID, mmi_msg_highlight_copy_all_simbox);
    SetHiliteHandler(SMS_SIM_OPT_MOVE_MENUID, mmi_msg_highlight_move);
    SetHiliteHandler(SMS_SIM_OPT_MOVE_ALL_MENUID, mmi_msg_highlight_move_all_simbox);
#endif /* __MMI_MESSAGES_COPY__ */
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    SetHiliteHandler(MENU_ID_SMS_UNSENTBOX_OPT_SEND, mmi_msg_highlight_unsent_opt_send);
    SetHiliteHandler(MENU_ID_SMS_UNSENTBOX_OPT_CANCEL_SEND, mmi_msg_highlight_unsent_opt_cancel_send);
    SetHiliteHandler(MENU_ID_SMS_UNSENTBOX_OPT_DELETE, mmi_msg_highlight_unsent_opt_delete);
    SetHiliteHandler(MENU_ID_SMS_UNSENTBOX_OPT_DELETE_ALL, mmi_msg_highlight_unsent_opt_delete_all);
    SetHiliteHandler(MENU_ID_SMS_UNSENTBOX_OPT_MOVE_TO_DRAFT, mmi_msg_highlight_unsent_opt_move_to_draft);	
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
}

#if defined(__MMI_SMART_MESSAGE_MT__) || (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))


/*****************************************************************************
 * FUNCTION
 *  PrepareEntryNsmRingtoneoption
 * DESCRIPTION
 *  Convert OTA Data to MIDI and store MIDI Data in global buffer
 * PARAMETERS
 *  void
 * CALLS
 *  EntryNsmRingtoneoption
 * RETURNS
 *  void
 *****************************************************************************/
void PrepareEntryNsmRingtoneoption(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *pnsmMessagebuff;
    U32 index;
    EMSData *pEms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetEMSDataForView(&pEms, 0);
    pnsmMessagebuff = (U8*) OslMalloc((pEms->textLength / 2) + 1);
    memset(pnsmMessagebuff, '\0', ((pEms->textLength / 2) + 1));

    index = RemoveZerosInBetween(pnsmMessagebuff, pEms->textBuffer, pEms->textLength);

    memset(gNSMBuffer, '\0', sizeof(gNSMBuffer));

    gConvertFlag = mmi_smrt_midi_handler(pnsmMessagebuff, gNSMBuffer);

    OslMfree(pnsmMessagebuff);

    EntryNsmRingtoneoption();
}


/*****************************************************************************
 * FUNCTION
 *  EntryNsmRingtoneoption
 * DESCRIPTION
 *  Display ringtone options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryNsmRingtoneoption(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 NumOfItems = 0;
    U8 *guiBuffer = NULL;
    U16 nStrItemsList[MAX_SUB_MENUS];   /* Temorary hardcoded size */

#ifdef __MMI_MESSAGES_COPY__
    U8 storageType;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* in case there is an interrupt cut in before displaying message content */
    if (IsScreenPresent(SCR_ID_MSG_PROCESSING))
    {
        HistoryReplace(SCR_ID_MSG_PROCESSING, SCR_ID_MSG_INBOX_MSG, EntryNsmRingtoneoption);
        return;
    }
    /* DeleteScreenIfPresent(SCR_ID_MSG_INBOX_MSG); // amit delete */
    EntryNewScreen(SCR_ID_MSG_INBOX_MSG, NULL, EntryNsmRingtoneoption, NULL);
    DeleteScreenIfPresent(SCR_ID_MSG_PROCESSING);

#if defined(__MMI_MESSAGES_USE_URL__)
    /* Hide USE URL menu item if incall or wap screen is present */
    if (isInCall() || IsScreenPresent(wap_get_screen_id()))
    {
        mmi_frm_hide_menu_item(MENU_ID_RINGTONE_OPT_USE_URL);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_RINGTONE_OPT_USE_URL);
    }
#endif /* defined(__MMI_MESSAGES_USE_URL__) */ 

    SetParentHandler(MENU_ID_NSM_RINGTONE);
    SetMessagesCurrScrnID(SCR_ID_MSG_INBOX_MSG);
    NumOfItems = GetNumOfChild_Ext(MENU_ID_NSM_RINGTONE);
    GetSequenceStringIds_Ext(MENU_ID_NSM_RINGTONE, nStrItemsList);
#ifdef __MMI_MESSAGES_COPY__

    /* Ringtone NSM is always inbox msg in current design. */
    switch (g_msg_cntx.toDisplayMessageList)
    {
        case TO_DISPLAY_MESSAGE_LIST_INBOX:
            storageType = mmi_frm_sms_get_storage(MMI_FRM_SMS_APP_INBOX, (U16) g_msg_cntx.currBoxIndex);
            break;
        case TO_DISPLAY_MESSAGE_LIST_OUTBOX:
            storageType = mmi_frm_sms_get_storage(MMI_FRM_SMS_APP_OUTBOX, (U16) g_msg_cntx.currBoxIndex);
            break;
    #ifdef __MMI_MESSAGES_DRAFT_BOX__
        case TO_DISPLAY_MESSAGE_LIST_DRAFTBOX:
            storageType = mmi_frm_sms_get_storage(MMI_FRM_SMS_APP_DRAFTS, (U16) g_msg_cntx.currBoxIndex);
            break;
    #endif /* __MMI_MESSAGES_DRAFT_BOX__ */ 
    }

    /* default : copy_to_phone */
    if (storageType == SMSAL_ME)
    {
        int i = 0;

        for (i = 0; i < MAX_SUB_MENUS; i++)
        {
            if (nStrItemsList[i] == STR_SMS_COPY_TO_PHONE)
            {
                nStrItemsList[i] = STR_SMS_COPY_TO_SIM;
                break;
            }
        }
        for (i = 0; i < MAX_SUB_MENUS; i++)
        {
            if (nStrItemsList[i] == STR_SMS_MOVE_TO_PHONE)
            {
                nStrItemsList[i] = STR_SMS_MOVE_TO_SIM;
                break;
            }
        }
    }
#endif /* __MMI_MESSAGES_COPY__ */ 
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_INBOX_MSG);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        NumOfItems,
        nStrItemsList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);

}


/*****************************************************************************
 * FUNCTION
 *  HighlightNsmRingtoneoptionplayHandler
 * DESCRIPTION
 *  Highligh handler for ringtone option - Play
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightNsmRingtoneoptionplayHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryNsmRingtoneoptionplay, KEY_EVENT_UP);
    SetKeyHandler(EntryNsmRingtoneoptionplay, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightNsmRingtoneoptionsaveHandler
 * DESCRIPTION
 *  Highligh handler for ringtone option - Save
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightNsmRingtoneoptionsaveHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(RingtoneNameBuffer, '\0', NSM_FILE_NAME_BUFF);
    SetLeftSoftkeyFunction(PreEntryNsmRingtoneoptionsave, KEY_EVENT_UP);
    SetKeyHandler(PreEntryNsmRingtoneoptionsave, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  EntryNsmRingtoneoptionplay
 * DESCRIPTION
 *  Play a ringtone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryNsmRingtoneoptionplay(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 *guiBuffer = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gConvertFlag == 1)
    {
        EntryNewScreen(SCR_ID_NSM_RINGTONE_PLAY, mmi_nsm_ringtone_exit_play, EntryNsmRingtoneoptionplay, NULL);
        SetMessagesCurrScrnID(SCR_ID_NSM_RINGTONE_PLAY);
        SetParentHandler(MENU_ID_NSM_RINGTONE_PLAY);
        RegisterHighlightHandler(ExecuteCurrHiliteHandler);
        guiBuffer = GetCurrGuiBuffer(SCR_ID_NSM_RINGTONE_PLAY);

        ShowCategory8Screen(
            STR_ID_NSM_RINGTONE_PLAY_MSG,
            0,
            0,
            0,
            STR_ID_NSM_RINGTONE_STOP,
            0,
            0,
            IMG_GLOBAL_PROGRESS,
            guiBuffer);

        SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
        SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetRightSoftkeyFunction(mmi_nsm_stop_and_goback, KEY_EVENT_UP);
        SetKeyHandler(mmi_nsm_stop_and_goback, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

        SetKeyHandler(mmi_nsm_stop_and_goto_idlescreen, KEY_END, KEY_EVENT_DOWN);
        PlayAudioMidiStream(gNSMBuffer, (U16) mmi_smrt_midi_file_size(gNSMBuffer), 1);
    }
    else
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_NSM_RINGTOEN_FORMAT_NOT_SUPPORTED_MSG),
            IMG_GLOBAL_WARNING,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nsm_ringtone_exit_play
 * DESCRIPTION
 *  Stop playing ringtone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_nsm_ringtone_exit_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopAudioMidiStream();
}


/*****************************************************************************
 * FUNCTION
 *  PreEntryNsmRingtoneoptionsave
 * DESCRIPTION
 *  Display an editor to save a picture
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 IsPopUpShownRingTone = FALSE;

void PreEntryNsmRingtoneoptionsave(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gConvertFlag != 1)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_NSM_RINGTOEN_FORMAT_NOT_SUPPORTED_MSG),
            IMG_GLOBAL_WARNING,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
    }
    else
    {
        if (IsPopUpShownRingTone)
        {
            mmi_msg_set_confirm_screen(STR_DELETE_SMS_QUERY_ID, mmi_msg_delete_msg, GoBackHistory);
            mmi_msg_entry_confirm_generic();
            IsPopUpShownRingTone = FALSE;
        }
        else
        {
            EntryNsmRingtoneoptionsave();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryNsmRingtoneoptionsave
 * DESCRIPTION
 *  Save a ringtone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryNsmRingtoneoptionsave(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_NSM_RINGTONE_SAVE, NULL, PreEntryNsmRingtoneoptionsave, NULL);

    SetMessagesCurrScrnID(SCR_ID_NSM_RINGTONE_SAVE);
    g_msg_cntx.MessagesScrnIdDelUptoHistoryNodes = GetMessagesCurrScrnID();     /* delete history up to here */
    SetParentHandler(MENU_ID_NSM_RINGTONE_SAVE);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_NSM_RINGTONE_SAVE);

    ShowCategory5Screen(
        STR_GLOBAL_FILENAME,
        0,
        STR_GLOBAL_OPTIONS,
        0,
        STR_GLOBAL_BACK,
        0,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        (U8*) RingtoneNameBuffer,
        MAX_NSM_FILENAME_LEN,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_save_ringtone_options, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nsm_save_ringtone
 * DESCRIPTION
 *  Save ringtone in My Tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_nsm_save_ringtone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 flag = 0;
    S8 DirPathInUnicode[NSM_DIRECTORY_BUFF];
    S8 temp[NSM_DIRECTORY_BUFF];
    S8 fullfilenameInUnicode[NSM_FILE_PLUS_DIRECTORY_BUFF];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* S8 filename[NSM_FILE_NAME_BUFF]; */

    /* if ringtone name is empty  */
    if (!mmi_ucs2strlen(RingtoneNameBuffer))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_EDIT_OPTIONS);
        DisplayPopup((U8*) GetString(STR_GLOBAL_EMPTY), IMG_GLOBAL_EMPTY, 1, MESSAGES_POPUP_TIME_OUT, EMPTY_LIST_TONE);
        DeleteMessagesHistoryNodes();
        return;
    }
#if defined(__MMI_FILE_MANAGER__)

    /* memset( filename,'\0', NSM_FILE_NAME_BUFF); */
    memset(DirPathInUnicode, '\0', NSM_DIRECTORY_BUFF);
    memset(fullfilenameInUnicode, '\0', NSM_FILE_PLUS_DIRECTORY_BUFF);
    memset(temp, '\0', NSM_DIRECTORY_BUFF);

    sprintf(temp, "%c:\\%s", MMI_PUBLIC_DRV, (S8*) MY_TONE_PATH);

    mmi_asc_to_ucs2(DirPathInUnicode, temp);

    mmi_ucs2cpy(fullfilenameInUnicode, DirPathInUnicode);
    mmi_ucs2cat(fullfilenameInUnicode, RingtoneNameBuffer);

    memset(temp, '\0', NSM_DIRECTORY_BUFF);

    //mmi_ucs2_to_asc((S8*)filename,(S8*)RingtoneNameBuffer );
    //sprintf(fullfilenameInAnsii,"%s%s",(S8*)DirPathInAnsii,(S8*)filename );

    mmi_asc_to_ucs2(temp, (S8*) ".mid");
    mmi_ucs2cat(fullfilenameInUnicode, temp);

    flag = mmi_nsm_save_buffer_in_file(fullfilenameInUnicode);

    if (flag == NSM_SPACE_FULL_3)   /* Phew!! ,Space full */
    {
        memset(RingtoneNameBuffer, '\0', NSM_FILE_NAME_BUFF);
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_NSM_RINGTONE_SAVE);
        DisplayPopup(
            (U8*) GetString(FMGR_FS_DISK_FULL_TEXT),
            IMG_GLOBAL_ERROR,
            FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        DeleteMessagesHistoryNodes();
    }
    else
    {
        if (flag == NSM_DUPLICATE_FILE_4)   /* Aaha!!, file name already exist */
        {
            DisplayPopup(
                (U8*) GetString(FMGR_FS_FILE_EXISTS_TEXT),
                IMG_GLOBAL_ERROR,
                FALSE,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
        }
        else
        {
            if (flag == NSM_FILE_ERROR_5)   /* aa ha ha haaaa!!! , Unable to open file */
            {
                DisplayPopup(
                    (U8*) GetString(FMGR_FS_INVALID_FILENAME_TEXT),   /* For Issue 542 */
                    IMG_GLOBAL_ERROR,
                    FALSE,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    ERROR_TONE);
            }
            else
            {
                if (flag == NSM_COMMOM_ERROR_6)
                {
                    DisplayPopup(
                        (PU8) GetString(STR_GLOBAL_UNFINISHED),
                        IMG_GLOBAL_UNFINISHED,
                        1,
                        UI_POPUP_NOTIFYDURATION_TIME,
                        (U8) ERROR_TONE);
                }
                else
                {
                    /* Alas !!! At last file saved */
                    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_NSM_RINGTONE_SAVE);
                    DisplayPopup(
                        (U8*) GetString(STR_GLOBAL_SAVED),
                        IMG_GLOBAL_SAVE,
                        1,
                        MESSAGES_POPUP_TIME_OUT,
                        SUCCESS_TONE);
                    DeleteMessagesHistoryNodes();
                }
            }
        }
    }

#endif /* defined(__MMI_FILE_MANAGER__) */ 

}   /* End mmi_nam_save_ringtone */

#if 0   /* PMT JAI 25-11-2004 : My Tone remove */
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
#endif /* 0 */ /* END PMT JAI 25-11-2004 :: My Tone remove */


/*****************************************************************************
 * FUNCTION
 *  PrepareEntryNsmPicturemsg
 * DESCRIPTION
 *  COnvert OTA data to BMP data and store in global buffer
 * PARAMETERS
 *  void
 * CALLS
 *  EntryNsmPicturemsg
 * RETURNS
 *  void
 *****************************************************************************/
void PrepareEntryNsmPicturemsg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *pnsmMessagebuff = NULL;
    U32 index;
    EMSData *pEms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetEMSDataForView(&pEms, 0);
    pnsmMessagebuff = (U8*) OslMalloc((pEms->textLength / 2) + 1);

    ASSERT(pnsmMessagebuff != NULL);

    memset(pnsmMessagebuff, '\0', ((pEms->textLength / 2) + 1));

    index = RemoveZerosInBetween(pnsmMessagebuff, pEms->textBuffer, pEms->textLength);

    memset(gNSMBuffer, '\0', sizeof(gNSMBuffer));

    gPictureMessageError = MMI_NSM_PIC_SUCCESS;
    gPictureDataBuffer = mmi_pmsg_convert_ota_to_bmp(pnsmMessagebuff);

    if (pnsmMessagebuff != NULL)
    {
        OslMfree(pnsmMessagebuff);
    }

    if (gPictureDataBuffer == NULL)
    {
        gPictureMessageError = MMI_NSM_PIC_FORMAT_ERROR;
    }
    else
    {
        memcpy((void*)gNSMBuffer, (const void*)gPictureDataBuffer, mmi_pmsg_get_size_bmp_data(gPictureDataBuffer));

        if (gPictureDataBuffer != NULL)
        {
            OslMfree(gPictureDataBuffer);
        }
    }
    EntryNsmPicturemsg();
}


/*****************************************************************************
 * FUNCTION
 *  EntryNsmPicturemsg
 * DESCRIPTION
 *  Display a picture
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryNsmPicturemsg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 ScrID;
    U8 tmparr[2] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ScrID = 0;
    if (IsScreenPresent(SCR_ID_MSG_OUTBOX_LIST))
    {
        ScrID = SCR_ID_MSG_OUTBOX_MSG;
    }
    else
    {
        ScrID = SCR_ID_MYPIC_DISPLAY;   /* JAI 06-12-2004 */
    }

    /* in case there is an interrupt cut in before displaying message content */
    if (IsScreenPresent(SCR_ID_MSG_PROCESSING))
    {
        HistoryReplace(SCR_ID_MSG_PROCESSING, ScrID, EntryNsmPicturemsg);
        return;
    }
    /* DeleteScreenIfPresent(ScrID); //amit delete */
    EntryNewScreen(ScrID, mmi_msg_exit_generic, EntryNsmPicturemsg, NULL);
    DeleteScreenIfPresent(SCR_ID_MSG_PROCESSING);
    SetMessagesCurrScrnID(ScrID);
    memset(TextBuffer, '\0', sizeof(TextBuffer));
    memset(tmparr, 0x00, sizeof(tmparr));

    if (gPictureMessageError == MMI_NSM_PIC_SUCCESS)
    {
    #if defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)

        /* 
         * Here we reset pEMS so dest_port becomes zero : JP 20050610
         */
        EMSData *pEMS;

        ReleaseEMSViewBuffer();
        GetEMSDataForView(&pEMS, 1);
        AddString(pEMS, (U8*) g_pmsg_TextInMessage, (U16) mmi_ucs2strlen((S8*) g_pmsg_TextInMessage), NULL);

        if (memcmp(g_pmsg_TextInMessage, tmparr, 2))    /* Is it empty? */
        {
            mmi_ucs2cpy((S8*) TextBuffer, (S8*) g_pmsg_TextInMessage);
        }
    #endif /* defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__) */ 

    #if defined(__MMI_SMART_MESSAGE_MT__)
        /* g_pmsg_TextInMessage is always unicode */
        if (memcmp(g_pmsg_TextInMessage, tmparr, 2))    /* Is it empty? */
        {
            mmi_ucs2cpy((S8*) TextBuffer, (S8*) g_pmsg_TextInMessage);
        }
        //mmi_asc_to_ucs2( (S8*)TextBuffer,       (S8*)g_pmsg_TextInMessage );
        //TextBuffer[318]='\0';
        //TextBuffer[319]='\0';
    #endif /* defined(__MMI_SMART_MESSAGE_MT__) */ 
    }

    else if (gPictureMessageError == MMI_NSM_PIC_FORMAT_ERROR)
    {
        mmi_ucs2cpy((S8*) TextBuffer, (S8*) GetString(STR_ID_NSM_RINGTOEN_FORMAT_NOT_SUPPORTED_MSG));
        gPictureDataBuffer = NULL;
    }
    else if (gPictureMessageError == MMI_NSM_PIC_MEMORY_ERROR)
    {
        mmi_ucs2cpy((S8*) TextBuffer, (S8*) GetString(STR_ID_NSM_SPACE_FULL));
        gPictureDataBuffer = NULL;
    }

    guiBuffer = GetCurrGuiBuffer(ScrID);
    /* Category screen is changed in NSM2 for smart pic msg */
    ShowCategoryNSM2Screen(
        STR_SCR6024_CAPTION,
        0,
        STR_GLOBAL_OPTIONS,
        IMG_SMS_COMMON_NOIMAGE,
        STR_GLOBAL_BACK,
        IMG_SMS_COMMON_NOIMAGE,
        NULL,
        (S8*) gNSMBuffer,
        0,
        0,
        NULL,
        NULL,
        0,
        NULL,
        NULL,
        (U8*) TextBuffer,
        sizeof(TextBuffer),
        guiBuffer);
    SetLeftSoftkeyFunction(mmi_nsm_entry_option_picturemsg, KEY_EVENT_UP);
    SetKeyHandler(mmi_nsm_entry_option_picturemsg, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nsm_entry_option_picturemsg
 * DESCRIPTION
 *  Entry picture message option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_nsm_entry_option_picturemsg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 ParentId = 0;
    EMSData *pEms;

#ifdef __MMI_MESSAGES_COPY__
    U8 storageType;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_PICMSG_OPTION, mmi_msg_exit_generic, mmi_nsm_entry_option_picturemsg, NULL);
    g_msg_cntx.sendMessageCase = SEND_CASE_SEND_ONLY;   /* reset : JAI 27-11-2004 */
    SetMessagesCurrScrnID(SCR_ID_PICMSG_OPTION);

    mmi_nsm_set_msg_type(PICTURE_MESSAGE);

    GetEMSDataForView(&pEms, 0);

    if ((IsScreenPresent(SCR_ID_MSG_OUTBOX_LIST)))
        /* ParentId = MENUID_OUTBOX_PICMSG_OPT; */
    {
        ParentId = SMS_OUTBOX_OPTIONS_MENUID;
    }
    else
    {
        switch (pEms->PortNum.dst_port)
        {
            case MMI_PIC_MSG_PORT_NUM:
        #if defined(__MMI_CLI_ICON__) || defined(__MMI_OPERATOR_LOGO__)
            case MMI_OPLOGO_MSG_PORT_NUM:
            case MMI_CLI_ICON_MSG_PORT_NUM:
        #endif /* defined(__MMI_CLI_ICON__) || defined(__MMI_OPERATOR_LOGO__) */ 
                ParentId = MENU_ID_NSM_PICTURE_MESSAGE;
                break;

            default:
                /*
                 * JP : Changes for MO NSM 20050610 
                 * since we release pEMS before this 
                 * function call and
                 * pEms->PortNum.dst_port becomes zero
                 */
        #ifdef __MMI_SMART_MESSAGE_MO__
                ParentId = MENU_ID_NSM_PICTURE_MESSAGE; /* Hack : We already know it is a picture message So display PicMsg Option */
        #else 
                ParentId = 0;
        #endif 
                break;
        }

    }

    SetParentHandler(ParentId);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_PICMSG_OPTION);

#if defined(__MMI_MESSAGES_USE_URL__)
    /* Hide USE URL menu item if incall or wap screen is present */
    if (isInCall() || IsScreenPresent(wap_get_screen_id()))
    {
        mmi_frm_hide_menu_item(MENU_ID_PICMSG_OPT_USE_URL);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_PICMSG_OPT_USE_URL);
    }
#endif /* defined(__MMI_MESSAGES_USE_URL__) */ 

    numItems = GetNumOfChild_Ext(ParentId);
    GetSequenceStringIds_Ext(ParentId, nStrItemList);
#ifdef __MMI_MESSAGES_COPY__
    switch (g_msg_cntx.toDisplayMessageList)
    {
        case TO_DISPLAY_MESSAGE_LIST_INBOX:
            storageType = mmi_frm_sms_get_storage(MMI_FRM_SMS_APP_INBOX, (U16) g_msg_cntx.currBoxIndex);
            break;
        case TO_DISPLAY_MESSAGE_LIST_OUTBOX:
            storageType = mmi_frm_sms_get_storage(MMI_FRM_SMS_APP_OUTBOX, (U16) g_msg_cntx.currBoxIndex);
            break;
    #ifdef __MMI_MESSAGES_DRAFT_BOX__
        case TO_DISPLAY_MESSAGE_LIST_DRAFTBOX:
            storageType = mmi_frm_sms_get_storage(MMI_FRM_SMS_APP_DRAFTS, (U16) g_msg_cntx.currBoxIndex);
            break;
    #endif /* __MMI_MESSAGES_DRAFT_BOX__ */ 
    }

    /* default : copy_to_phone */
    if (storageType == SMSAL_ME)
    {
        int i = 0;

        for (i = 0; i < MAX_SUB_MENUS; i++)
        {
            if (nStrItemList[i] == STR_SMS_COPY_TO_PHONE)
            {
                nStrItemList[i] = STR_SMS_COPY_TO_SIM;
                break;
            }
        }
        for (i = 0; i < MAX_SUB_MENUS; i++)
        {
            if (nStrItemList[i] == STR_SMS_MOVE_TO_PHONE)
            {
                nStrItemList[i] = STR_SMS_MOVE_TO_SIM;
                break;
            }
        }
    }
#endif /* __MMI_MESSAGES_COPY__ */ /* __MMI_MESSAGES_COPY_ */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightPicmsgSavePictureHandler
 * DESCRIPTION
 *  Highlight handler for Save picture
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightPicmsgSavePictureHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(PictureNameBuffer, '\0', NSM_FILE_NAME_BUFF);
    if (gPictureMessageError == MMI_NSM_PIC_SUCCESS)
    {
        SetLeftSoftkeyFunction(EntryPicmsgSavepic, KEY_EVENT_UP);
        SetKeyHandler(EntryPicmsgSavepic, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {
        SetLeftSoftkeyFunction(ShowPictureErrorMessage, KEY_EVENT_UP);
        SetKeyHandler(ShowPictureErrorMessage, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  ShowPictureErrorMessage
 * DESCRIPTION
 *  Display error message for  a picture message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ShowPictureErrorMessage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 StrId = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gPictureMessageError == MMI_NSM_PIC_FORMAT_ERROR)
    {
        StrId = STR_ID_NSM_RINGTOEN_FORMAT_NOT_SUPPORTED_MSG;
    }
    else
    {
        StrId = STR_ID_NSM_SPACE_FULL;
    }

    DisplayPopup((U8*) GetString(StrId), IMG_GLOBAL_ERROR, FALSE, UI_POPUP_NOTIFYDURATION_TIME, ERROR_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  EntryPicmsgSavepic
 * DESCRIPTION
 *  Save a picture
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryPicmsgSavepic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_NSM_RINGTONE_SAVE, NULL, EntryPicmsgSavepic, NULL);
    SetMessagesCurrScrnID(SCR_ID_NSM_RINGTONE_SAVE);
    g_msg_cntx.MessagesScrnIdDelUptoHistoryNodes = GetMessagesCurrScrnID();     /* delete history up to here */
    SetParentHandler(MENU_ID_NSM_PICMSG_SAVE_PICTURE);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_NSM_RINGTONE_SAVE);
    ShowCategory5Screen(
        STR_GLOBAL_FILENAME,
        0,
        STR_GLOBAL_OPTIONS,
        0,
        STR_GLOBAL_BACK,
        0,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        (U8*) PictureNameBuffer,
        MAX_NSM_FILENAME_LEN,
        guiBuffer);

    /* SetLeftSoftkeyFunction( mmi_nsm_save_picmsg, KEY_EVENT_UP);  //PMT JAI : 23122004 */
    SetLeftSoftkeyFunction(mmi_save_pic_options, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nsm_save_picmsg
 * DESCRIPTION
 *  Save a picture in My Picture
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_nsm_save_picmsg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U16 flag = 0;
    S8 DirPathInUnicode[NSM_DIRECTORY_BUFF];
    S8 temp[NSM_DIRECTORY_BUFF];
    S8 fullfilenameInUnicode[NSM_FILE_PLUS_DIRECTORY_BUFF];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* S8 filename[NSM_FILE_NAME_BUFF]; */

    /* if picture name is empty  */
    if (!mmi_ucs2strlen(PictureNameBuffer))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_EDIT_OPTIONS);
        DisplayPopup((U8*) GetString(STR_GLOBAL_EMPTY), IMG_GLOBAL_EMPTY, 1, MESSAGES_POPUP_TIME_OUT, EMPTY_LIST_TONE);
        DeleteMessagesHistoryNodes();
        return;
    }
#if defined(__MMI_FILE_MANAGER__)

    /* memset( filename,'\0', NSM_FILE_NAME_BUFF); */
    memset(temp, 0x00, NSM_DIRECTORY_BUFF);
    memset(DirPathInUnicode, '\0', NSM_DIRECTORY_BUFF);
    memset(fullfilenameInUnicode, '\0', NSM_FILE_PLUS_DIRECTORY_BUFF);
    sprintf(temp, "%c:\\%s", MMI_PUBLIC_DRV, (S8*) MYPICTURE_DIR_PATH);

    //mmi_ucs2_to_asc((S8*)filename,(S8*)PictureNameBuffer );
    //                      mmi_nsm_create_dir(DirPathInAnsii);
    //sprintf(fullfilenameInAnsii,"%s%s",(S8*)DirPathInAnsii,(S8*)filename );
    //      strcat((S8*)fullfilenameInAnsii, (S8*)".bmp");

    mmi_asc_to_ucs2(DirPathInUnicode, temp);

    mmi_ucs2cpy(fullfilenameInUnicode, DirPathInUnicode);
    mmi_ucs2cat(fullfilenameInUnicode, PictureNameBuffer);

    memset(temp, 0x00, NSM_DIRECTORY_BUFF);

    mmi_asc_to_ucs2(temp, (S8*) ".bmp");
    mmi_ucs2cat(fullfilenameInUnicode, temp);

    flag = mmi_nsm_save_buffer_in_file(fullfilenameInUnicode);

    if (flag == NSM_SPACE_FULL_3)   /* Phew!! ,Space full */
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_NSM_RINGTONE_SAVE);
        DisplayPopup(
            (U8*) GetString(FMGR_FS_DISK_FULL_TEXT),
            IMG_GLOBAL_ERROR,
            FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        DeleteMessagesHistoryNodes();
    }
    else
    {
        if (flag == NSM_DUPLICATE_FILE_4)   /* Aaha!!, file name already exist */
        {
            DisplayPopup(
                (U8*) GetString(FMGR_FS_FILE_EXISTS_TEXT),
                IMG_GLOBAL_ERROR,
                FALSE,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
        }
        else
        {
            if (flag == NSM_FILE_ERROR_5)   /* aa ha ha haaaa!!! , Unable to open file */
            {
                DisplayPopup(
                    (U8*) GetString(FMGR_FS_INVALID_FILENAME_TEXT),   /* For Issue 542 */
                    IMG_GLOBAL_ERROR,
                    FALSE,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    ERROR_TONE);
            }
            else if (flag == NSM_COMMOM_ERROR_6)
            {

                DisplayPopup(
                    (PU8) GetString(STR_GLOBAL_UNFINISHED),
                    IMG_GLOBAL_UNFINISHED,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    (U8) ERROR_TONE);
            }
            else
            {
                /* Alas !!! At last file saved */
                SetMessagesScrnIdToDelHistoryNodes(SCR_ID_NSM_RINGTONE_SAVE);
                DisplayPopup(
                    (U8*) GetString(STR_GLOBAL_SAVED),
                    IMG_GLOBAL_SAVE,
                    1,
                    MESSAGES_POPUP_TIME_OUT,
                    SUCCESS_TONE);
                DeleteMessagesHistoryNodes();
            }
        }
    }

#endif /* defined(__MMI_FILE_MANAGER__) */ 

}


/*****************************************************************************
 * FUNCTION
 *  PreEntryNsmPicturemsg
 * DESCRIPTION
 *  Insert a dummy inbox list and display a picture
 * PARAMETERS
 *  void
 * CALLS
 *  PrepareEntryNsmPicturemsg
 * RETURNS
 *  void
 *****************************************************************************/
void PreEntryNsmPicturemsg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_exit_inbox_list_dummy();
    g_msg_cntx.msg_ind_in_idle = FALSE;
    PrepareEntryNsmPicturemsg();
}


/*****************************************************************************
 * FUNCTION
 *  PreEntryNsmRingtoneoption
 * DESCRIPTION
 *  Insert a dummy inbox list and display a rigntone option
 * PARAMETERS
 *  void
 * CALLS
 *  PrepareEntryNsmRingtoneoption
 * RETURNS
 *  void
 *****************************************************************************/
void PreEntryNsmRingtoneoption(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_exit_inbox_list_dummy();
    g_msg_cntx.msg_ind_in_idle = FALSE;
    PrepareEntryNsmRingtoneoption();
}


/*****************************************************************************
 * FUNCTION
 *  RemoveZerosInBetween
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pOutBuffer      [?]         
 *  pInBuffer       [?]         
 *  size            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 RemoveZerosInBetween(U8 *pOutBuffer, U8 *pInBuffer, U16 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S16 count = -1;
    U16 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (index < size)
    {
        /* mmi_ucs2_to_wc((U16)*pInBuffer,arrOut); */
        pOutBuffer[++count] = *pInBuffer;
        pInBuffer++;
        pInBuffer++;
        index++;
        index++;
    }

    pOutBuffer[++count] = '\0';
    return count + 1;
}


/*****************************************************************************
 * FUNCTION
 *  ExecuteMyHandler
 * DESCRIPTION
 *  Store index of current selected item in a global
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ExecuteMyHandler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gSelected_Item = (U16) index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nsm_stop_and_goback
 * DESCRIPTION
 *  Entry function to stop ringtone and Go back to previous screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_nsm_stop_and_goback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopAudioMidiStream();
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nsm_stop_and_goto_idlescreen
 * DESCRIPTION
 *  Entry function to stop ringtone and Go back to Idle screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_nsm_stop_and_goto_idlescreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopAudioMidiStream();
    DisplayIdleScreen();
}

#if defined(__MMI_SMART_MESSAGE_MT__)


/*****************************************************************************
 * FUNCTION
 *  highlight_picmsg_edit_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_picmsg_edit_text(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_picmsg_edit_text, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_picmsg_edit_text
 * DESCRIPTION
 *  Edit picutre message text
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_picmsg_edit_text(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* For unsupported picture message */
    if (MMI_NSM_PIC_FORMAT_ERROR == gPictureMessageError)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_NSM_RINGTOEN_FORMAT_NOT_SUPPORTED_MSG),
            IMG_GLOBAL_ERROR,
            FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        return;
    }

    EntryNewScreen(SCR_ID_NSM_EDITOR, mmi_msg_exit_generic, mmi_picmsg_edit_text, NULL);

    SetMessagesCurrScrnID(SCR_ID_NSM_EDITOR);
    SetParentHandler(MENU_ID_NSM_PICMSG_USE_NUMBER);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_NSM_EDITOR);

    /* start : JP to fix outbox send option junk chinese character bug */
    if (guiBuffer == NULL)
    {   /* For issue 140 */
        mmi_nsm_init_picmsg_txt_struct(&picmsg_text_struct);
        mmi_ucs2cpy((S8*) picmsg_text_struct.pic_textbuff, (S8*) g_pmsg_TextInMessage);
        /* End : JP to fix outbox send option junk chinese character bug */
    }

    ShowCategoryNSM275Screen(
        STR_ID_PICMSG_EDIT_TEXT,
        STR_GLOBAL_OPTIONS,
        IMG_SMS_COMMON_NOIMAGE,
        STR_GLOBAL_BACK,
        IMG_SMS_COMMON_NOIMAGE,
        INPUT_TYPE_ALPHANUMERIC_LOWERCASE | INPUT_TYPE_USE_ENCODING_BASED_LENGTH,
        (PU8) picmsg_text_struct.pic_textbuff,
        picmsg_text_struct.Infobar_max_limit + 1,
        4,
        mmi_nsm2_category275_draw_tile,
        0,
        NULL,
        0,
        NULL,
        guiBuffer);
    //ShowCategory5Screen(       STR_ID_PICMSG_EDIT_TEXT,        NULL,   STR_GLOBAL_OPTIONS,     NULL,
    //                                           STR_GLOBAL_BACK ,       NULL,   INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
    //                                           gaddtext_buffer,MAX_PICMSG_TEXT_SIZE+1,guiBuffer );

    /* SetLeftSoftkeyFunction( mmi_mypic_entry_done_option, KEY_EVENT_UP); //PMT JAI 23122004 */
    SetLeftSoftkeyFunction(mmi_pic_msg_edit_text_options, KEY_EVENT_UP);        /* PMT JAI 23122004 */
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_mypic_entry_done_option, KEY_SEND, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nsm_init_picmsg_txt_struct
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text_struct     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_nsm_init_picmsg_txt_struct(nsm_picmsg_text_struct *text_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(text_struct->pic_textbuff, 0x00, sizeof(text_struct->pic_textbuff));
    text_struct->ucs2_count = 0;
    text_struct->Infobar_max_limit = MAX_PICMSG_TEXT_LEN;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nsm_get_infobar_maxlen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_nsm_get_infobar_maxlen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (picmsg_text_struct.ucs2_count > 0)
    {
        picmsg_text_struct.Infobar_max_limit = (MAX_PICMSG_TEXT_LEN >> 1) + 1;
    }
    else
    {
        picmsg_text_struct.Infobar_max_limit = MAX_PICMSG_TEXT_LEN + 1;
    }

    return picmsg_text_struct.Infobar_max_limit * 2;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pic_msg_edit_text_options
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pic_msg_edit_text_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U16 NumOfItems = 0;
    U8 *guiBuffer = NULL;
    U16 nStrItemsList[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EDIT_OPTIONS, mmi_msg_exit_generic, mmi_pic_msg_edit_text_options, NULL);

    SetParentHandler(MENU_ID_PIC_MSG_EDIT_TEXT_OPTION);
    SetMessagesCurrScrnID(SCR_ID_EDIT_OPTIONS);
    NumOfItems = GetNumOfChild(MENU_ID_PIC_MSG_EDIT_TEXT_OPTION);
    GetSequenceStringIds(MENU_ID_PIC_MSG_EDIT_TEXT_OPTION, nStrItemsList);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_EDIT_OPTIONS);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        NumOfItems,
        nStrItemsList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);

}


/*****************************************************************************
 * FUNCTION
 *  highlight_pic_msg_edit_text_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_pic_msg_edit_text_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_mypic_entry_done_option, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

#endif /* defined(__MMI_SMART_MESSAGE_MT__) */ 
/* SAVE PICTURE */


/*****************************************************************************
 * FUNCTION
 *  mmi_save_pic_options
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_save_pic_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U16 NumOfItems = 0;
    U8 *guiBuffer = NULL;
    U16 nStrItemsList[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EDIT_OPTIONS, mmi_msg_exit_generic, mmi_save_pic_options, NULL);

    SetParentHandler(MENU_ID_SAVE_PIC_OPTION);
    SetMessagesCurrScrnID(SCR_ID_EDIT_OPTIONS);
    NumOfItems = GetNumOfChild(MENU_ID_SAVE_PIC_OPTION);
    GetSequenceStringIds(MENU_ID_SAVE_PIC_OPTION, nStrItemsList);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_EDIT_OPTIONS);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        NumOfItems,
        nStrItemsList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);

}


/*****************************************************************************
 * FUNCTION
 *  highlight_save_pic_msg_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_save_pic_msg_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_nsm_save_picmsg, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

/* SAVE RINGTONE */


/*****************************************************************************
 * FUNCTION
 *  mmi_save_ringtone_options
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_save_ringtone_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U16 NumOfItems = 0;
    U8 *guiBuffer = NULL;
    U16 nStrItemsList[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EDIT_OPTIONS, mmi_msg_exit_generic, mmi_save_ringtone_options, NULL);

    SetParentHandler(MENU_ID_SAVE_RINGTONE_OPTION);
    SetMessagesCurrScrnID(SCR_ID_EDIT_OPTIONS);
    NumOfItems = GetNumOfChild(MENU_ID_SAVE_RINGTONE_OPTION);
    GetSequenceStringIds(MENU_ID_SAVE_RINGTONE_OPTION, nStrItemsList);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_EDIT_OPTIONS);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        NumOfItems,
        nStrItemsList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);

}


/*****************************************************************************
 * FUNCTION
 *  highlight_save_ringtone_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_save_ringtone_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_nsm_save_ringtone, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

#endif /* defined(__MMI_SMART_MESSAGE_MT__) || (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) */ 

#if (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))


/*****************************************************************************
 * FUNCTION
 *  mmi_nsm2_init_nsm_msg_struct
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nsm_msg_context     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_nsm2_init_nsm_msg_struct(nsm_msg_struct *nsm_msg_context)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset nsm message glObal struct */
    nsm_msg_context->is_picmsg = FALSE; /* Normal message :Default */
    memset(nsm_msg_context->textbuffer, 0x00, sizeof(nsm_msg_context->textbuffer));
    nsm_msg_context->textlength = -1;
    nsm_msg_context->max_textlength = 0;
    memset(nsm_msg_context->picbuffer, 0x00, sizeof(nsm_msg_context->picbuffer));
    nsm_msg_context->picbuffer_length = 0;
    nsm_msg_context->pic_height = 0;
    nsm_msg_context->pic_width = 0;
    nsm_msg_context->dcs = 0x00;        /* Default : 7 BIT GSM */
    nsm_msg_context->UCS2_count = 0;
    nsm_msg_context->remaining_length = (DEFAULT_DCS_ALLOCATED_LENGTH);
    nsm_msg_context->header_fptr = NULL;
    nsm_msg_context->is_template_insert = FALSE;
    nsm_msg_context->cursor_pos_after_template = 0;
}


/*****************************************************************************
 * FUNCTION
 *  Highlight_nsm_insert_SYS_Picture
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Highlight_nsm_insert_SYS_Picture(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(PictureSYSList, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nsm2_entry_show_picture
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_nsm2_entry_show_picture(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_NSM2_SHOW_PIC, NULL, mmi_nsm2_entry_show_picture, NULL);
    SetMessagesCurrScrnID(SCR_ID_NSM2_SHOW_PIC);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_NSM2_SHOW_PIC);

    ShowCategory620Screen(
        STR_ID_NSM_PICTURE,
        0,
        STR_ID_NSM2_INSERT,
        0,
        STR_GLOBAL_BACK,
        0,
        (U8*) NULL,
        (U8*) NULL,
        g_nsm_msg_context.picbuffer,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_nsm2_insert_pic_in_editor, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nsm2_insert_pic_in_editor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_nsm2_insert_pic_in_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 remaining_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_nsm_msg_context.is_picmsg = TRUE;
    /* Find remaing length after inserting pic */
    remaining_len = mmi_nsm2_get_remaining_len();
    fmgr_reset_app_select();

    if ((g_nsm_msg_context.textlength >> 1) > (remaining_len >> 1))
    {
        g_nsm_msg_context.is_picmsg = FALSE;
        GoBackToHistory(SCR_ID_MSG_WRITE);
        DisplayPopup(
            (U8*) GetString(STR_NO_SPACE_TO_INSERT_OBJECT),
            IMG_GLOBAL_ERROR,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        return;
    }
    else
    {
        g_nsm_msg_context.is_picmsg = TRUE;
        g_nsm_msg_context.header_fptr = mmi_nsm2_category275_draw_header;
        g_nsm_msg_context.pic_height = MAX_NSM_PIC_HEIGHT;
        g_nsm_msg_context.dcs = 0x04;   /* 8-bit GSM  for picture message */
    }

    GoBackToHistory(SCR_ID_MSG_WRITE);
}


/*****************************************************************************
 * FUNCTION
 *  highlight_nsm_remove_picture
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_nsm_remove_picture(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_nsm_remove_picture, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nsm_remove_picture
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_nsm_remove_picture(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_nsm_msg_context.is_picmsg = FALSE;    /* Normal message :Default */
    memset(g_nsm_msg_context.picbuffer, 0x00, sizeof(g_nsm_msg_context.picbuffer));
    g_nsm_msg_context.picbuffer_length = 0;
    g_nsm_msg_context.pic_height = 0;
    g_nsm_msg_context.pic_width = 0;
    g_nsm_msg_context.header_fptr = NULL;
    GoBackHistory();
}

extern S8 PictureMessageDir[];


/*****************************************************************************
 * FUNCTION
 *  highlight_nsm2_insert_picture_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_nsm2_insert_picture_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_entry_get_insert_pic_list, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_entry_get_insert_pic_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_entry_get_insert_pic_list(void)
{
#if defined(__MMI_FILE_MANAGER__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 DirPath[64];
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(PictureMessageDir, 0x00, NSM_FILE_NAME_BUFF);

    /* Get directory path for My Picture */
    sprintf(DirPath, "%c:\\%s", MMI_PUBLIC_DRV, (S8*) "Images\\");

    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_BMP);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER_DOT);

    mmi_asc_to_ucs2((S8*) PictureMessageDir, (S8*) DirPath);     // DirPath/*.*
    mmi_fmgr_select_path_and_enter(
        APP_MESSAGES,
        FMGR_SELECT_FILE | FMGR_SELECT_REPEAT,
        filter,
        (PS8) PictureMessageDir,
        (PsExtFuncPtr) mmi_nsm2_pre_entry_show_pic);

#endif /* defined(__MMI_FILE_MANAGER__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nsm2_pre_entry_show_pic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filePath        [IN]        
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_nsm2_pre_entry_show_pic(PU16 filePath, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle = 0;
    INT wByte = 0;
    U32 read_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filePath == NULL)
    {
        GoBackHistory();
        return;
    }

    file_handle = FS_Open(filePath, FS_READ_ONLY);

    if (file_handle >= 0)
    {
        memset(g_nsm_msg_context.picbuffer, '\0', sizeof(g_nsm_msg_context.picbuffer));
        FS_Read(file_handle, (void*)g_nsm_msg_context.picbuffer, sizeof(g_nsm_msg_context.picbuffer), &read_len);
        FS_Close(file_handle);
    }

    if (mmi_pmsg_add_bmp_header_info(g_nsm_msg_context.picbuffer) == -1)
    {
        g_nsm_msg_context.is_picmsg = FALSE;
        DisplayPopup(
            (U8*) GetString(STR_ID_NSM_INVALID_PIC),
            IMG_GLOBAL_ERROR,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
        return;
    }
    else
    {
        mmi_nsm2_entry_show_picture();
    }
}



/*****************************************************************************
 * FUNCTION
 *  PictureSYSList
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PictureSYSList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 index;
    U16 *nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MYPIC_LIST, NULL, PictureSYSList, NULL);
    SetMessagesCurrScrnID(SCR_ID_MYPIC_LIST);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_MYPIC_LIST);
    SetParentHandler(0);
    currMaxSYSObjectList = NSM_MANUFACTURER_PICTURE_NUM;
    for (index = 0; index < currMaxSYSObjectList; index++)
    {
        nStrItemList[index] = (PU16) GetString((U16) ManufacturerSYSPictureStrIDs[index]);
    }
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory53Screen(
        STR_ID_NSM2_INSERT_PICTURE,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_VIEW,
        0,
        STR_GLOBAL_BACK,
        0,
        currMaxSYSObjectList,
        (PU8*) nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
    SetLeftSoftkeyFunction(mmi_sys_get_picture_image, KEY_EVENT_UP);
    SetKeyHandler(mmi_sys_get_picture_image, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sys_get_picture_image
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sys_get_picture_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *data;
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = GetHighlightedItem();
    data = (U8*) GetImage(ManufacturerSYSPictureImageIDs[index]);
    memcpy(g_nsm_msg_context.picbuffer, data, PREDEFINED_PIC_BUFF_SIZE);
    /* Start :JP for Predefined NSM error checking */
    if (mmi_pmsg_is_smart_picture((g_nsm_msg_context.picbuffer + 6)) == FALSE)
    {
        g_nsm_msg_context.is_picmsg = FALSE;
        DisplayPopup(
            (U8*) GetString(STR_ID_NSM_INVALID_PIC),
            IMG_GLOBAL_ERROR,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
        return;
    }
    else
    {
        mmi_nsm2_entry_show_picture();
    }
    /* End : JP for Predefined NSM error checking */
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEditOptionInsertObject
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEditOptionInsertObject(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);
    SetLeftSoftkeyFunction(EntryScrInsertObjectMenu, KEY_EVENT_UP);
    SetKeyHandler(EntryScrInsertObjectMenu, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrInsertObjectMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrInsertObjectMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 numItems = 0;
    PU8 guiBuffer = NULL;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_EMS_INSERT_OBJECT, mmi_msg_exit_generic, EntryScrInsertObjectMenu, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_EMS_INSERT_OBJECT);
    SetParentHandler(EMS_ED_OPT_INS_OBJ);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    numItems = GetNumOfChild(EMS_ED_OPT_INS_OBJ);
    GetSequenceStringIds(EMS_ED_OPT_INS_OBJ, nStrItemList);
    SetMessagesCurrScrnID(SCR_ID_MSG_EMS_INSERT_OBJECT);
    ShowCategory52Screen(
        STR_OPT_INS_OBJECT_MENUENTRY,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nsm2_is_valid_picmsg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_nsm2_is_valid_picmsg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gPictureMessageError;
}

#endif /* (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) */ 

#if defined(__MMI_MESSAGES_USE_URL__)
static U8 mmi_msg_check_gsm_char(PU16 ch);
static void mmi_msg_to_lower_case(PS8 ptr, PS16 U16);
static S8 *pfnUnicodeStristr(S8 *text, S8 *pattern);

extern kal_bool applib_is_valid_url_char(char ch);

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_use_url
 * DESCRIPTION
 *  Highlight use URL handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_msg_highlight_use_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_entry_use_url,
        GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_use_url
 * DESCRIPTION
 *  Entry use URL list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_msg_entry_use_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    EMSData *pEMS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_use_url *\n");

    pEMS = GetEMSDataForView(0, 0);

#if defined (__MMI_SMART_MESSAGE_MT__) || (defined (__MMI_SMART_MESSAGE_MO__) && !defined (__MMI_MESSAGES_EMS__))
    switch (mmi_nsm_get_msg_type())
    {
        case PICTURE_MESSAGE:
            g_msg_cntx.URLCount = mmi_msg_get_url_list_from_msgtxt((S8*) TextBuffer);
            break;
        case NORMAL_MESSAGE:
            g_msg_cntx.URLCount = mmi_msg_get_url_list_from_msgtxt((S8*) pEMS->textBuffer, pEMS->textLength);
            break;
        default:                        /* RINGTONE_MESSAGE */
            g_msg_cntx.URLCount = 0;    /* EMPTY LIST */
            break;
    }
#else /* defined (__MMI_SMART_MESSAGE_MT__) || (defined (__MMI_SMART_MESSAGE_MO__) && !defined (__MMI_MESSAGES_EMS__)) */ 
  	g_msg_cntx.URLCount = mmi_msg_get_url_list_from_msgtxt((S8*) pEMS->textBuffer, pEMS->textLength);
#endif /* defined (__MMI_SMART_MESSAGE_MT__) || (defined (__MMI_SMART_MESSAGE_MO__) && !defined (__MMI_MESSAGES_EMS__)) */ 

    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] URL List count : %d *\n", g_msg_cntx.URLCount);

    if (g_msg_cntx.URLCount > 0)
    {
        EntryNewScreen(SCR_ID_MSG_USE_URL_LIST, mmi_msg_exit_generic, mmi_msg_entry_use_url, NULL);

        guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_USE_URL_LIST);
        RegisterHighlightHandler(GetHiliteIndex);
        SetMessagesCurrScrnID(SCR_ID_MSG_USE_URL_LIST);

        ShowCategory53Screen(
            STR_USE_URL_LIST_CAPTION,
            IMG_SMS_ENTRY_SCRN_CAPTION,
            STR_GLOBAL_OPTIONS,
            IMG_SMS_COMMON_NOIMAGE,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            g_msg_cntx.URLCount,
            (U8 **) g_msg_cntx.URLlist,
            (U16*) gIndexIconsImageList,
            NULL,
            0,
            0,
            guiBuffer);
        SetLeftSoftkeyFunction(mmi_msg_entry_use_url_option, KEY_EVENT_UP);
        SetKeyHandler(mmi_msg_entry_use_url_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_msg_entry_open_url, KEY_SEND, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_msg_go_back_use_url_list, KEY_EVENT_UP);
        SetKeyHandler(mmi_msg_go_back_use_url_list, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_msg_end_key_from_use_url, KEY_END, KEY_EVENT_DOWN);
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_NOURL_NOTIFICATION),
            IMG_GLOBAL_EMPTY,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) EMPTY_LIST_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_check_gsm_char
 * DESCRIPTION
 *  Check if it is a gsm character
 * PARAMETERS
 *  ch          [IN]        
 *  a(?)        [IN]        Char
 * RETURNS
 *  TRUE if it is a gsm character; FALSE otherwise
 *****************************************************************************/
static U8 mmi_msg_check_gsm_char(PU16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ascii_min = 0x0000;
    U16 ascii_max = 0x007f;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (*ch >= ascii_min && *ch <= ascii_max)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_to_lower_case
 * DESCRIPTION
 *  Convert ascii upper case character to unicode lower case
 * PARAMETERS
 *  ptr         [IN]            
 *  U16         [IN]            
 *  a(?)        [IN]            Ptr   a pointer points to an ascii character
 *  b(?)        [IN/OUT]        Word  a pointer points to an unicode character
 * RETURNS
 *  a pointer points to an unicode character(?)
 *****************************************************************************/
static void mmi_msg_to_lower_case(PS8 ptr, PS16 U16)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 two_byte_A = 0x0041;
    S16 two_byte_Z = 0x005A;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (*((S16*) ptr) >= two_byte_A && *((S16*) ptr) <= two_byte_Z)
    {
        *U16 = (S16) ('a' + (*ptr) - 'A');
    }
    else
    {
        *U16 = *((S16*) (ptr));
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_is_end_of_URL_string
 * DESCRIPTION
 *  Check if end of URL string
 * PARAMETERS
 * 
 * RETURNS
 *  
 *****************************************************************************/
static BOOL mmi_msg_is_end_of_URL_string(PS8 ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 escape_char = 0x1b;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_msg_check_gsm_char((PU16) ptr))
    {
        return MMI_TRUE;
    }
    else if (mmi_ucs2ncmp((S8*)ptr, "\\", 1) == 0)
    {
        return MMI_FALSE;
    }
    else if (mmi_ucs2ncmp((S8*)ptr, (S8*)&escape_char, 1) == 0)
    {
        return MMI_FALSE;
    }    
    else 
    {
    	U8 ascii_char[2] = {0,0};
    	mmi_ucs2_n_to_asc((S8*)ascii_char, (S8*)ptr, ENCODING_LENGTH);
    	
    	if (!applib_is_valid_url_char(ascii_char[0]))
    	{
    		return MMI_TRUE;
    	}
    	else
    	{
    		return MMI_FALSE;    		
    	}
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_check_duplicate_url
 * DESCRIPTION
 *  Extract all URL from message text
 * PARAMETERS
 *  url_count      [IN]        URL count in  g_msg_cntx.URLlist
 *  url_string     [IN]        URL to be matched
 * RETURNS
 *  Total URL count in message text
 *****************************************************************************/
static MMI_BOOL mmi_msg_check_duplicate_url( U8 url_count, S8* url_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VIDEO_STREAM__
    U8 url_initCount;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(url_string != NULL);

#ifdef __MMI_VIDEO_STREAM__
    url_initCount = url_count;
#endif 
    while (url_count > 0)
    {
    #ifdef __MMI_VIDEO_STREAM__
        if (g_msg_cntx.is_rtspUrl[url_initCount] == g_msg_cntx.is_rtspUrl[url_count - 1]
            && mmi_ucs2cmp((S8*) g_msg_cntx.URLlist[url_count - 1], (S8*) url_string) == 0)
    #else /* __MMI_VIDEO_STREAM__ */ 
        if (mmi_ucs2cmp((S8*) g_msg_cntx.URLlist[url_count - 1], (S8*) url_string) == 0)
    #endif /* __MMI_VIDEO_STREAM__ */ 
        {
            return MMI_TRUE;
        }
        url_count--;
    }

    return MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_url_list_from_msgtxt
 * DESCRIPTION
 *  Extract all URL from message text
 * PARAMETERS
 *  MsgTxt      [?]         
 *  a(?)        [IN]        Message text
 * RETURNS
 *  Total URL count in message text
 *****************************************************************************/
U8 mmi_msg_get_url_list_from_msgtxt(S8 *pText, U16 txtLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    S8 Pattern[MAX_LEN_URL_PATTERN * ENCODING_LENGTH];
    PS8 ptr = NULL;
    PS8 min_ptr = NULL;
    PS8 start_ptr = NULL;
    U16 URLlen = 0;
    U8 URLCount = 0;
    kal_bool valid_URL_prefix = KAL_TRUE;
	PS8 pTmpBuffer = NULL;
	S8 *MsgTxt = pText;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VIDEO_STREAM__
    for (i = 0; i < MAX_USE_NUMBERS; i++)
    {
        g_msg_cntx.is_rtspUrl[i] = FALSE;
    }
#endif /* __MMI_VIDEO_STREAM__ */ 
	if(mmi_ucs2strlen(MsgTxt)<<1 != txtLen)
	{
		pTmpBuffer = OslMalloc(txtLen + 2);
		mmi_msg_skip_end_char(pTmpBuffer, MsgTxt, txtLen);
		MsgTxt = pTmpBuffer;
	}
    while (mmi_ucs2cmp(MsgTxt, "\0"))
    {
        /* Get a valid url of  http */
        for (i = 0; i < MAX_NUM_URL_PATTERN; i++)
        {
            mmi_asc_to_ucs2(Pattern, urlPattern[i]);
            /* search the pattern in the MsgTxt */
            ptr = pfnUnicodeStristr(MsgTxt, Pattern);
            /* select the minimum one, i.e. http://www.mtk.com "http://" will be selected instead of "www." */
            if (ptr != NULL && (min_ptr == NULL || ptr < min_ptr))
            {

                /* Determine if the http prefix is valid. For example, "http:##" is not valid. */
                if ((strncmp(urlPattern[i], "http", 4)) == 0)
                {
                    int j = 0;
                    S16 http_prefix[MAX_LEN_URL_PATTERN];
                    S16 http_prefix_in_msg[MAX_LEN_URL_PATTERN];

                    for (; j < MAX_NUM_VALID_HTTP_PREFIX; j++)
                    {
                        int k = 0;

                        int http_prefix_len = strlen((S8*) urlValidHttpPrefix[j]);

                        mmi_asc_n_to_ucs2((S8*) http_prefix, urlValidHttpPrefix[j], http_prefix_len);
                        mmi_ucs2ncpy((S8*) http_prefix_in_msg, ptr, http_prefix_len);
                        http_prefix_in_msg[http_prefix_len] = 0;

                        for (; k < http_prefix_len; k++)
                        {
                            S16 c = 0;

                            mmi_msg_to_lower_case((S8*) & http_prefix_in_msg[k], &c);
                            http_prefix_in_msg[k] = c;
                        }

                        if (mmi_ucs2ncmp((S8*) http_prefix_in_msg, (S8*) http_prefix, http_prefix_len) == 0)
                        {
                            /* Skip the http prefix, according to reference phone design */
                            /* Only Skip http prefix. https prefix should not be ignored */
                            if ((strncmp(urlValidHttpPrefix[j], "https", 5)) != 0)
                            {
                                ptr = ptr + http_prefix_len * ENCODING_LENGTH;
                            }
                            break;
                        }
                    }

                    if (j == MAX_NUM_VALID_HTTP_PREFIX)
                    {
                        valid_URL_prefix = KAL_FALSE;
                    }
                }
            #ifdef __MMI_VIDEO_STREAM__
                /* Determine if the rtsp prefix is valid. For example, "rtsp:##" is not valid. */
                else if ((strncmp(urlPattern[i], "rtsp", 4)) == 0)
                {
                    int j = 0;
                    S16 rtsp_prefix[MAX_LEN_URL_PATTERN];
                    S16 rtsp_prefix_in_msg[MAX_LEN_URL_PATTERN];

                    /* check the validity of rtsp */
                    for (j = 0; j < MAX_NUM_VALID_RTSP_PREFIX; j++)
                    {
                        int k = 0;

                        int rtsp_prefix_len = strlen((S8*) urlValidRtspPrefix[j]);

                        mmi_asc_n_to_ucs2((S8*) rtsp_prefix, urlValidRtspPrefix[j], rtsp_prefix_len);
                        mmi_ucs2ncpy((S8*) rtsp_prefix_in_msg, ptr, rtsp_prefix_len);
                        rtsp_prefix_in_msg[rtsp_prefix_len] = 0;

                        for (; k < rtsp_prefix_len; k++)
                        {
                            S16 c = 0;

                            mmi_msg_to_lower_case((S8*) & rtsp_prefix_in_msg[k], &c);
                            rtsp_prefix_in_msg[k] = c;
                        }

                        if (mmi_ucs2ncmp((S8*) rtsp_prefix_in_msg, (S8*) rtsp_prefix, rtsp_prefix_len) == 0)
                        {
                            break;
                        }
                    }

                    if (j == MAX_NUM_VALID_RTSP_PREFIX)
                    {
                        valid_URL_prefix = KAL_FALSE;
                    }
                    else if (URLCount < MAX_USE_NUMBERS)
                    {
                        valid_URL_prefix = KAL_TRUE;
                        g_msg_cntx.is_rtspUrl[URLCount] = TRUE;
                    }
                }
            #endif /* __MMI_VIDEO_STREAM__ */ 
                else
                {
                    valid_URL_prefix = KAL_TRUE;
                }

                min_ptr = ptr;
                ptr = NULL;
            }
        }

        if (URLCount < MAX_USE_NUMBERS && min_ptr != NULL)
        {
            start_ptr = min_ptr;
            /* move MsgTxt pointer from last url terminator to this url starter */
            MsgTxt += (min_ptr - MsgTxt);
            URLlen = 0;

            /* Only extract URL string if the protocol prefix is valid */
            if (valid_URL_prefix)
            {
                if (g_msg_cntx.URLlist[URLCount])
                {
                    OslMfree(g_msg_cntx.URLlist[URLCount]);
                }
                g_msg_cntx.URLlist[URLCount] = (S8*) OslMalloc(MAX_URL_LEN);
                memset(g_msg_cntx.URLlist[URLCount], 0x00, MAX_URL_LEN);

                /* get one url until end of URL string */
                while (!mmi_msg_is_end_of_URL_string(start_ptr))
                {
                    /* must reserve two bytes for null terminator */
                    if (URLlen < MAX_URL_LEN - 2)
                    {
                        /* skip extension character 0x1b */
                        if (*(PU16) start_ptr != 0x001b)
                        {
                            /* convert reverse solidus to solidus */
                            if (mmi_ucs2ncmp((S8*) start_ptr, "\\", 1) == 0)
                            {
                                U16 solidus = '/';

                                mmi_ucs2ncpy(g_msg_cntx.URLlist[URLCount] + URLlen, (S8*) & solidus, 1);
                            }
                            else
                            {
                                mmi_ucs2ncpy(g_msg_cntx.URLlist[URLCount] + URLlen, start_ptr, 1);
                            }
                            URLlen += 2;
                        }
                        start_ptr += 2;
                    }
                    /* over max url length */
                    else
                    {
                        break;
                    }
                }

                if (mmi_ucs2strlen(g_msg_cntx.URLlist[URLCount]) &&
                    (!mmi_msg_check_duplicate_url(URLCount, g_msg_cntx.URLlist[URLCount])))
                {
                    URLCount++;
                }
                else
                {
                #ifdef __MMI_VIDEO_STREAM__
                    if (g_msg_cntx.is_rtspUrl[URLCount] == TRUE)
                    {
                        g_msg_cntx.is_rtspUrl[URLCount] = FALSE;
                    }
                #endif /* __MMI_VIDEO_STREAM__ */ 
                    OslMfree(g_msg_cntx.URLlist[URLCount]);
                    g_msg_cntx.URLlist[URLCount] = NULL;
                }
            }
            else    /* Skip the string following the invalid prefix. The same design with reference phone */
            {
                /*  Skip string until end of URL string */
                while (!mmi_msg_is_end_of_URL_string(start_ptr))
                {
                    start_ptr += 2;
                }
            }

            MsgTxt = start_ptr;
            start_ptr = NULL;
            min_ptr = NULL;
        }
        /* over max url number or the content contains no url */
        else
        {
            break;
        }

        valid_URL_prefix = KAL_TRUE;
    }
	if (pTmpBuffer != NULL)
	{
		OslMfree(pTmpBuffer);
	}
	
    return URLCount;
}


/*****************************************************************************
 * FUNCTION
 *  pfnUnicodeStristr
 * DESCRIPTION
 *  finds pattern in given text
 * PARAMETERS
 *  text        [?]         
 *  pattern     [?]         
 *  a(?)        [IN]        Text
 *  b(?)        [IN]        Pattern
 * RETURNS
 *  a  SUCCESS     Starting address of pattern in text
 * B  FAIL     NULL
 *****************************************************************************/
static S8 *pfnUnicodeStristr(S8 *text, S8 *pattern)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *ptr = NULL;
    S8 *ret_addr = NULL;
    BOOL pattern_found = FALSE;
    S16 text_lower_case_char = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr = pattern;
    while (mmi_ucs2cmp(text, "\0"))
    {
        ret_addr = text;
        mmi_msg_to_lower_case(text, &text_lower_case_char);
        while (!mmi_ucs2ncmp((S8*) & text_lower_case_char, ptr, 1))
        {
            ptr += 2;
            text += 2;
            mmi_msg_to_lower_case(text, &text_lower_case_char);

            if (!mmi_ucs2ncmp(text, "\0", 1))
            {
                break;
            }
        }   /* while... */

        if (!mmi_ucs2ncmp(ptr, "\0", 1))
        {
            pattern_found = TRUE;
            break;
        }

        if (ptr != pattern)
        {
            ptr = pattern;
        }
        else
        {
            text += 2;
        }
    }   /* while... */

    if (!pattern_found)
    {
        ret_addr = NULL;
    }

    return (S8*) ret_addr;
}   /* func().... */


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_use_url_option
 * DESCRIPTION
 *  Entry Use URL Options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_msg_entry_use_url_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_USE_URL_OPTION, mmi_msg_exit_generic, mmi_msg_entry_use_url_option, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_use_url_option*\n");
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_USE_URL_OPTION);

    numItems = GetNumOfChild(MENU_ID_SMS_USE_URL_OPTIONS);
    GetSequenceStringIds(MENU_ID_SMS_USE_URL_OPTIONS, nStrItemList);
    SetParentHandler(MENU_ID_SMS_USE_URL_OPTIONS);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_URL_OPT_CAPTION,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightUseURLOptConnectHandler
 * DESCRIPTION
 *  Highlight Use URL Connect handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void HighlightUseURLOptConnectHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_entry_open_url,
        GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_open_url
 * DESCRIPTION
 *  Entry open an URL in WAP BROWSERS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_msg_entry_open_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_msg_cntx.URLlist[g_msg_cntx.currHiliteIndex] == NULL ||
        mmi_ucs2strlen((S8*) g_msg_cntx.URLlist[g_msg_cntx.currHiliteIndex]) == 0)
    {
        MMI_ASSERT(0);
    }

    if (!isInCall() && !IsScreenPresent(wap_get_screen_id()))
    {
    #ifdef __MMI_VIDEO_STREAM__
        if (g_msg_cntx.is_rtspUrl[g_msg_cntx.currHiliteIndex] == TRUE)
        {
            mmi_vdoply_entry_player_screen_from_rtsp_link(g_msg_cntx.URLlist[g_msg_cntx.currHiliteIndex]);
        }
        else
    #endif /* __MMI_VIDEO_STREAM__ */ 
        {
            wap_start_browser(WAP_BROWSER_GOTO_URL, (U8*) g_msg_cntx.URLlist[g_msg_cntx.currHiliteIndex]);
        }
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_CONNECT_FAILED),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_use_url_add_to_bookmark
 * DESCRIPTION
 *  Highlight Use URL Add to bookmark  handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_use_url_add_to_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_entry_add_url,
        GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_add_url
 * DESCRIPTION
 *  Entry Add an URL to WAP bookmark
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_add_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_msg_cntx.URLlist[g_msg_cntx.currHiliteIndex] == NULL ||
        mmi_ucs2strlen((S8*)g_msg_cntx.URLlist[g_msg_cntx.currHiliteIndex]) == 0)
    {
        MMI_ASSERT(0);
    }

    if (!isInCall() && !IsScreenPresent(wap_get_screen_id()))
    {
        wap_start_browser(WAP_BROWSER_ADD_BOOKMARK, (U8*)g_msg_cntx.URLlist[g_msg_cntx.currHiliteIndex]);
    }
    else
    {   /* Should not happen because the use URL menu item would be hidden if WAP screen is present */
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_end_key_from_use_url
 * DESCRIPTION
 *  Free URL list and  return to Idle Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_msg_end_key_from_use_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_free_url_list();
    DisplayIdleScreen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_go_back_use_url_list
 * DESCRIPTION
 *  Free URL list and  go back
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_msg_go_back_use_url_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_free_url_list();
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_free_url_list
 * DESCRIPTION
 *  Free URl list and reset URL count
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_free_url_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < g_msg_cntx.URLCount; ++count)
    {
        if (g_msg_cntx.URLlist[count])
        {
            OslMfree(g_msg_cntx.URLlist[count]);
        }
    }
    memset(g_msg_cntx.URLlist, 0x00, sizeof(g_msg_cntx.URLlist));
    g_msg_cntx.URLCount = 0;

}
#endif /* defined(__MMI_MESSAGES_USE_URL__) */ 

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_skip_end_char
 * DESCRIPTION
 *  if current sms is hiden sms, we will skip the header, as normal sms handle
 * PARAMETERS
 *  MsgTxt      [IN]        Message text         
 *  length       [IN]        The length of Message text
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_msg_skip_end_char(S8 *pOut, S8 *pIn, U16 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 tmpLen = 0;
	U16 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(pOut == NULL || pIn == NULL)
	{
		return 0;
	}	
	while(tmpLen < length)
	{		
		if(mmi_ucs2cmp(pIn + tmpLen, "\0"))
		{
			*(pOut + i++) = *(pIn + tmpLen);
			*(pOut + i++) = *(pIn + tmpLen + 1);			
		}
		tmpLen += 2;		
	}
	*(pOut + i) = '\0';
	*(pOut + i + 1) = '\0';
	
	return i>>1;
}

/* /////////////////////////////////////////////////////////////////////////////////// */


#ifdef __MMI_EMAIL__
static void mmi_msg_use_email_address_send_email(void);
static void mmi_msg_use_email_address_save(void);
static MMI_BOOL mmi_msg_is_valib_email_local_part_char(U16 ch);
static MMI_BOOL mmi_msg_is_valib_email_domain_part_char(U16 ch);
static U8 mmi_msg_get_email_address_list_from_msgtxt(S8 *MsgTxt, U16 msgTxtLen);
static void mmi_msg_go_back_email_address_list(void);
static void mmi_msg_end_key_from_email_address(void);
static void mmi_msg_free_email_address_list(void);
#endif /* __MMI_EMAIL__ */

#ifdef __MMI_EMAIL__
/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_use_email_address
 * DESCRIPTION
 *  Highlight use Email Address Item handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_use_email_address(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_entry_email_address_list,
        GoBackHistory);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_use_email_addr_opt_send
 * DESCRIPTION
 *  Highlight Email Address Option Item "Send" handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_use_email_addr_opt_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_use_email_address_send_email,
        GoBackHistory);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_use_email_addr_opt_save
 * DESCRIPTION
 *  Highlight Email Address Option Item "Save" handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_use_email_addr_opt_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_use_email_address_save,
        GoBackHistory);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_email_address_list
 * DESCRIPTION
 *  Entry Use Email Address List Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_email_address_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    EMSData *pEMS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_email_address_list *\n");

    pEMS = GetEMSDataForView(0, 0);

   	g_msg_cntx.EmailAddrCount = mmi_msg_get_email_address_list_from_msgtxt((S8*) pEMS->textBuffer, pEMS->textLength);

    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] email address count : %d *\n", g_msg_cntx.EmailAddrCount);

    if (g_msg_cntx.EmailAddrCount > 0)
    {
        EntryNewScreen(SCR_ID_MSG_USE_EMAIL_ADDRESS_LIST, mmi_msg_exit_generic, mmi_msg_entry_email_address_list, NULL);

        guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_USE_EMAIL_ADDRESS_LIST);
        RegisterHighlightHandler(GetHiliteIndex);
        SetMessagesCurrScrnID(SCR_ID_MSG_USE_EMAIL_ADDRESS_LIST);

        ShowCategory53Screen(
            STR_USE_EMAIL_ADDRESS_LIST_CAPTION,
            IMG_SMS_ENTRY_SCRN_CAPTION,
            STR_GLOBAL_OPTIONS,
            IMG_SMS_COMMON_NOIMAGE,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            g_msg_cntx.EmailAddrCount,
            (U8 **) g_msg_cntx.EmailAddrList,
            (U16*) gIndexIconsImageList,
            NULL,
            0,
            0,
            guiBuffer);
        SetLeftSoftkeyFunction(mmi_msg_entry_use_email_address_option, KEY_EVENT_UP);
        SetKeyHandler(mmi_msg_entry_use_email_address_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetRightSoftkeyFunction(mmi_msg_go_back_email_address_list, KEY_EVENT_UP);
        SetKeyHandler(mmi_msg_go_back_email_address_list, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_msg_use_email_address_send_email, KEY_SEND, KEY_EVENT_UP);		
        SetKeyHandler(mmi_msg_end_key_from_email_address, KEY_END, KEY_EVENT_DOWN);
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_NO_EMAIL_ADDRESS_NOTIFICATION),
            IMG_GLOBAL_EMPTY,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) EMPTY_LIST_TONE);
    }	
}

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_use_email_address_option
 * DESCRIPTION
 *  Entry email address option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_use_email_address_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_USE_EMAIL_ADDRESS_OPTION, mmi_msg_exit_generic, mmi_msg_entry_use_email_address_option, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_use_email_address_option*\n");
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_USE_EMAIL_ADDRESS_OPTION);

    numItems = GetNumOfChild(MENU_ID_SMS_USE_EMAIL_ADDRESS_OPTIONS);
    GetSequenceStringIds(MENU_ID_SMS_USE_EMAIL_ADDRESS_OPTIONS, nStrItemList);
    SetParentHandler(MENU_ID_SMS_USE_EMAIL_ADDRESS_OPTIONS);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    SetMessagesCurrScrnID(SCR_ID_MSG_USE_EMAIL_ADDRESS_OPTION);
    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_USE_EMAIL_ADDRESS_OPTION);
	
    ShowCategory52Screen(
        STR_USE_EMAIL_ADDRESS_OPTION_CAPTION,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_email_address_list_from_msgtxt
 * DESCRIPTION
 *  Extract email address from message text
 * PARAMETERS
 *  MsgTxt      [IN]        Message text         
 *  msgTxtLen   [IN]        The length of Message text
 * RETURNS
 *  Total URL count in message text
 *****************************************************************************/
static U8 mmi_msg_get_email_address_list_from_msgtxt(S8 *MsgTxt, U16 msgTxtLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
    U16 len = 0;
	U16* input_data = (U16*)MsgTxt;
    U16 *data = NULL;
	U8 email_addr_count = 0;
	PS8 pTmpBuffer = NULL;
		
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(MsgTxt == NULL)
	{
		return 0;
	}
	len = msgTxtLen;
	if (mmi_ucs2strlen(MsgTxt)<<1 != msgTxtLen)
	{
		pTmpBuffer = OslMalloc(msgTxtLen + 2);
		len = mmi_msg_skip_end_char(pTmpBuffer, MsgTxt, msgTxtLen);
		input_data = (U16*)pTmpBuffer;
	}
    data = input_data;  
	
    while (data - input_data < msgTxtLen)
    {
        U16 *start = NULL;
        U16 *end = NULL;
		
        start = (U16 *)mmi_ucs2chr((S8*)data, L'@');
        end = start + 1;
		
        if (start == NULL)  /* not found */
        {
        	return email_addr_count;
        }
        else if (start == data || mmi_msg_is_valib_email_local_part_char(*(start - 1)) == MMI_FALSE || 
            	 *(start - 1) == L'.')  /* '.' should not be the last character in the local part */
        {
            data = start + 1;  /* continue from the end of the pattern */
            len = msgTxtLen - (data - input_data);
            continue;
        }
        else
        {
        	/*we get the end of local part string and go to find its begining*/
            while ((start - 1 >= data) && mmi_msg_is_valib_email_local_part_char(*(start - 1)))
            {
                start--;
            }
            ASSERT(start >= data);

            while (*start == L'.')  /* '.' should not be the first character in the local-part */
            {
                start++;
            }
            
            /*we get the begining of domain part string and go to find its end*/
            while ((end - data) < len &&  mmi_msg_is_valib_email_domain_part_char(*end))
            {
                end++;
            }
            while (*(end - 1) == L'.')  /* removing trailing dot(s)*/
            {
                end--;
            }

            if (end == ((U16*)mmi_ucs2chr((S8*)data, L'@') + 1))  /* Domain part string is NULL */
            {
                if ((end - data) < len)
                {
                    data = end;  /* continue from the following char */
                    len = msgTxtLen - (end - input_data);
                    continue;
                }
                else
                {
                    return email_addr_count;
                }
            }
            else if ((end - data) <= len)
            {
            	MMI_BOOL is_duplicate = MMI_FALSE;
                U16 tmp = *end;
                
                *end = L'\0';

				if (email_addr_count == 0)
				{
					if (g_msg_cntx.EmailAddrList[email_addr_count] != NULL)
					{
						OslMfree(g_msg_cntx.EmailAddrList[email_addr_count]);
					}
					g_msg_cntx.EmailAddrList[email_addr_count] = OslMalloc((mmi_ucs2strlen((S8*)start)+ 1) * 2);
					mmi_ucs2cpy(g_msg_cntx.EmailAddrList[email_addr_count], (S8*)start);
					email_addr_count++;
				}
				else
				{
					U8 i;
					
					for (i = 0; i < email_addr_count; i++)
					{
						if (mmi_ucs2cmp(g_msg_cntx.EmailAddrList[i], (S8*)start) == 0)
						{
							is_duplicate = MMI_TRUE;
							break;
						}
					}

					if (is_duplicate == MMI_FALSE)
					{
						if (g_msg_cntx.EmailAddrList[email_addr_count] != NULL)
						{
							OslMfree(g_msg_cntx.EmailAddrList[email_addr_count]);
						}
						g_msg_cntx.EmailAddrList[email_addr_count] = OslMalloc((mmi_ucs2strlen((S8*)start)+ 1) * 2);
						mmi_ucs2cpy(g_msg_cntx.EmailAddrList[email_addr_count], (S8*)start);
						email_addr_count++;
					}

					if (email_addr_count == MAX_USE_NUMBERS)
					{
					    *end = tmp;
						return email_addr_count;
					}
				}

                *end = tmp;

                data = end;  /* continue from the following char */
                len = msgTxtLen - (end - input_data);
				
                continue;
            }
            else
            {
				if (pTmpBuffer != NULL)
				{
					OslMfree(pTmpBuffer);
				}
                return email_addr_count;
            }
        }
    }
	if (pTmpBuffer != NULL)
	{
		OslMfree(pTmpBuffer);
	}
    return email_addr_count;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_is_valib_email_local_part_char
 * DESCRIPTION
 *  check the unicode char is a valib email domain part char
 * PARAMETERS
 *  ch        [IN]        unicode char
 * RETURNS
 *  if valib, return MMI_TRUE, else return MM_FALSE
 *****************************************************************************/
static MMI_BOOL mmi_msg_is_valib_email_local_part_char(U16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((ch >= L'a' && ch <= L'z') ||
        (ch >= L'A' && ch <= L'Z') || (ch >= L'0' && ch <= L'9'))
    {
        return MMI_TRUE;
    }
    switch (ch)
    {
        /* Reference RFC 2822 */
        case L'.':
        case L'!':
        case L'#':
        case L'$':
        case L'%':
        case L'&':
        case L'\'':
        case L'*':
        case L'+':
        case L'-':
        case L'/':
        case L'=':
        case L'?':
        case L'^':
        case L'_':
        case L'`':
        case L'{':
        case L'|':
        case L'}':
        case L'~':
            return MMI_TRUE;
        default:
            return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_is_valib_email_domain_part_char
 * DESCRIPTION
 *  check the unicode char is a valib email domain part char
 * PARAMETERS
 *  ch        [IN]        unicode char
 * RETURNS
 *  if valib, return MMI_TRUE, else return MM_FALSE
 *****************************************************************************/
static MMI_BOOL mmi_msg_is_valib_email_domain_part_char(U16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (!((ch >= L'a' && ch <= L'z') ||
          (ch >= L'A' && ch <= L'Z') ||
          (ch >= L'0' && ch <= L'9') || (ch == L'-') || (ch == L'.')))
    {
        return MMI_FALSE;
    }

    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_go_back_use_email_address_list
 * DESCRIPTION
 *  Free Email Address List and  Go Back Email Address List Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_msg_go_back_email_address_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_free_email_address_list();
    GoBackHistory();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_end_key_from_use_email_address
 * DESCRIPTION
 *  Free Email Address List and  Return to Idle Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_msg_end_key_from_email_address(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_free_email_address_list();
    DisplayIdleScreen();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_free_email_address_list
 * DESCRIPTION
 *  Free Email Address List and Reset Email Address Count
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_msg_free_email_address_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < g_msg_cntx.EmailAddrCount; ++count)
    {
        if (g_msg_cntx.EmailAddrList[count])
        {
            OslMfree(g_msg_cntx.EmailAddrList[count]);
			g_msg_cntx.EmailAddrList[count] = NULL;
        }
    }
    memset(g_msg_cntx.EmailAddrList, 0x00, sizeof(g_msg_cntx.EmailAddrList));
    g_msg_cntx.EmailAddrCount = 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_use_email_address_send_email
 * DESCRIPTION
 *  Enter Edit Email Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_msg_use_email_address_send_email(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_email_app_send_to(g_msg_cntx.EmailAddrList[g_msg_cntx.currHiliteIndex]);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_use_email_address_save
 * DESCRIPTION
 *  save email address to phone book
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_msg_use_email_address_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_email_save_entry_to_phb(NULL, 
    					g_msg_cntx.EmailAddrList[g_msg_cntx.currHiliteIndex]);
}

#endif /* __MMI_EMAIL__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_on_enter_idle_screen
 * DESCRIPTION
 *  Callback when idle screen is entered
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_on_enter_idle_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    SetMessagesScrnIdToDelHistoryNodes(MESSAGES_SCR_ID_DEFINES_MAX);
    SetMessagesScrnIdDelUpToHistoryNodes(MESSAGES_SCR_ID_DEFINES_MAX);
    
#if defined(__MMI_MESSAGES_USE_URL__)
    mmi_msg_free_url_list();    
#endif /* defined(__MMI_MESSAGES_USE_URL__) */ 

    return;
}

#ifdef __MMI_UNIFIED_COMPOSER__
/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_uc
 * DESCRIPTION
 *  Entry unified composer editor
 * PARAMETERS
 *  type: mmi_uc_done_type_enum, 
 *  caller_msg_type: mmi_uc_msg_type_enum 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_uc(U8* ascii_num, U16 type, U16 msg_index, U16 caller_msg_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_entry_write_struct* data = OslMalloc(sizeof(mmi_uc_entry_write_struct));
    U8 num_len = 0;
    U8* number = NULL;
    EMSData *pEMS;
    U16 index = msg_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset (data, 0 , sizeof(mmi_uc_entry_write_struct));
    
    if (ascii_num && strlen((char*)ascii_num))
    {
        num_len = strlen((char*)ascii_num);
        number = OslMalloc((num_len + 1) * ENCODING_LENGTH);
        data->addr = OslMalloc(sizeof(mmi_uc_addr_struct));

        memset(number, 0, (num_len + 1) * ENCODING_LENGTH);
        memset(data->addr, 0, sizeof(mmi_uc_addr_struct));

        mmi_asc_n_to_ucs2((S8*)number, (S8*)ascii_num, num_len);

        data->addr->addr = number;
        data->addr->type = MMI_UC_ADDRESS_TYPE_PHONE_NUMBER;
        data->addr->group = MMI_UC_ADDRESS_GROUP_TYPE_TO;

        data->addr_num = 1;
    }
    else
    {
        data->addr = NULL;
        data->addr_num = 0;
    }

    data->msg_type = caller_msg_type;
    data->file_path = NULL;

    GetEMSDataForEdit(&pEMS, 0);

    if (pEMS->textLength)
    {
        data->text_buffer = pEMS->textBuffer;
        data->text_num = pEMS->textLength / ENCODING_LENGTH;
    }
    else
    {
        data->text_buffer = NULL;
        data->text_num = 0;
    }

    data->subject = NULL;

    data->info_type = MMI_UC_INFO_TYPE_SMS;

    data->info = &index;

    mmi_uc_entry_write_msg_with_content( type, data);

    if (data->addr)
    {
        OslMfree(data->addr->addr);
        OslMfree(data->addr);
    }
    OslMfree(data);
    
}

#endif /* __MMI_UNIFIED_COMPOSER__ */


#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__


#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
void mmi_msg_entry_archive_list_inbox_opt(void)
{
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];
	U8 *pNumber = NULL;
#ifdef __MMI_MESSAGES_EMS__
    EMSData *pEms;
    EMSObject *object_p = NULL;
#endif /* __MMI_MESSAGES_EMS__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* in case there is an interrupt cut in during getting msg content */
    if (IsScreenPresent(SCR_ID_MSG_PROCESSING))
    {
        HistoryReplace(SCR_ID_MSG_PROCESSING, SCR_ID_MSG_ARCHIVE_LIST_OPTION, mmi_msg_entry_archive_list_inbox_opt);
        return;
    }

    EntryNewScreen(SCR_ID_MSG_ARCHIVE_LIST_OPTION, mmi_msg_exit_generic, mmi_msg_entry_archive_list_inbox_opt, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_archive_list_inbox_opt *\n");
    
    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_ARCHIVE_LIST_OPTION);
    g_msg_cntx.sendMessageCase = SEND_CASE_SEND_ONLY;   /* reset */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_ARCHIVE_LIST_OPTION);

#if defined(__MMI_MESSAGES_USE_URL__)
    /* Hide USE URL menu item if incall or wap screen is present */
    if (isInCall() || IsScreenPresent(wap_get_screen_id()))
    {
        mmi_frm_hide_menu_item(MENU_ID_SMS_INBOX_OPT_USE_URL);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_SMS_INBOX_OPT_USE_URL);
    }
#endif /* defined(__MMI_MESSAGES_USE_URL__) */ 

#ifdef __MMI_MESSAGES_EMS__
    /* Hide USE object menu item if no object in the message */
    GetEMSDataForView(&pEms, 0);
    object_p = pEms->listHead;
    mmi_frm_hide_menu_item(SMS_INBOX_OPT_SAVE_OBJECT_MENUID);
    while (object_p)
    {
        if ((object_p->Type == EMS_TYPE_PIC) || (object_p->Type == EMS_TYPE_USERDEF_ANM) ||
    #if defined(__MMI_IMELODY_SUPPORT__)
            (object_p->Type == EMS_TYPE_USERDEF_SND) ||
    #endif 
            KAL_FALSE)
        {
            mmi_frm_unhide_menu_item(SMS_INBOX_OPT_SAVE_OBJECT_MENUID);
            break;
        }
        object_p = object_p->next;
    }
#endif /* __MMI_MESSAGES_EMS__ */ 

     //hidden SMS_INBOX_OPT_MOVE_TO_ARCHIVE_MENUID, SMS_INBOX_OPT_CHAT_MENUID and SMS_INBOX_OPT_ADVANCED_MENUID here
    mmi_frm_hide_menu_item(SMS_INBOX_OPT_MOVE_TO_ARCHIVE_MENUID);
#ifdef __MMI_MESSAGES_CHAT__
    mmi_frm_hide_menu_item(SMS_INBOX_OPT_CHAT_MENUID);
#endif
#ifdef __MMI_MESSAGES_COPY__
    mmi_frm_hide_menu_item(SMS_INBOX_OPT_ADVANCED_MENUID);
#endif
    mmi_frm_unhide_menu_item(SMS_INBOX_OPT_VIEW_MENUID);

	pNumber = mmi_frm_sms_get_address(MMI_FRM_SMS_APP_ARCHIVE, (U16) g_msg_cntx.currBoxIndex);
    if (mmi_frm_sms_check_dst_number(pNumber, (U8)strlen((const char*)pNumber)) == TRUE)
	{
		mmi_frm_unhide_menu_item(SMS_INBOX_OPT_REPLY_MENUID);
	}
	else
	{
		mmi_frm_hide_menu_item(SMS_INBOX_OPT_REPLY_MENUID);
	}
    numItems = GetNumOfChild_Ext(SMS_INBOX_OPTIONS_MENUID);
    GetSequenceStringIds_Ext(SMS_INBOX_OPTIONS_MENUID, nStrItemList);    
    SetParentHandler(SMS_INBOX_OPTIONS_MENUID);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    SetMessagesCurrScrnID(SCR_ID_MSG_ARCHIVE_LIST_OPTION);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);

}


void mmi_msg_entry_archive_list_outbox_opt(void)
{

    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* in case there is an interrupt cut in during getting msg content */
    if (IsScreenPresent(SCR_ID_MSG_PROCESSING))
    {
        HistoryReplace(SCR_ID_MSG_PROCESSING, SCR_ID_MSG_ARCHIVE_LIST_OPTION, mmi_msg_entry_archive_list_outbox_opt);
        return;
    }
    
    EntryNewScreen(SCR_ID_MSG_ARCHIVE_LIST_OPTION, mmi_msg_exit_generic, mmi_msg_entry_archive_list_outbox_opt, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_archive_list_outbox_opt *\n");

    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_ARCHIVE_LIST_OPTION);
    g_msg_cntx.sendMessageCase = SEND_CASE_SEND_ONLY;   /* reset */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_ARCHIVE_LIST_OPTION);

#if defined(__MMI_MESSAGES_USE_URL__)
    /* Hide USE URL menu item if incall or wap screen is present */
    if (isInCall() || IsScreenPresent(wap_get_screen_id()))
    {
        mmi_frm_hide_menu_item(MENU_ID_SMS_OUTBOX_OPT_USE_URL);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_SMS_OUTBOX_OPT_USE_URL);
    }
#endif /* defined(__MMI_MESSAGES_USE_URL__) */ 

    //hidden SMS_INBOX_OPT_MOVE_TO_ARCHIVE_MENUID and SMS_OUTBOX_OPT_ADVANCED_MENUID here
    mmi_frm_hide_menu_item(SMS_OUTBOX_OPT_MOVE_TO_ARCHIVE_MENUID);
#ifdef __MMI_MESSAGES_COPY__
    mmi_frm_hide_menu_item(SMS_OUTBOX_OPT_ADVANCED_MENUID);
#endif

    mmi_frm_hide_menu_item(SMS_OUTBOX_OPT_SEND_MENUID);
    mmi_frm_unhide_menu_item(SMS_OUTBOX_OPT_FORWARD_MENUID);

    mmi_frm_unhide_menu_item(SMS_OUTBOX_OPT_VIEW_MENUID);

    numItems = GetNumOfChild_Ext(SMS_OUTBOX_OPTIONS_MENUID);
    GetSequenceStringIds_Ext(SMS_OUTBOX_OPTIONS_MENUID, nStrItemList);

    SetParentHandler(SMS_OUTBOX_OPTIONS_MENUID);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    SetMessagesCurrScrnID(SCR_ID_MSG_ARCHIVE_LIST_OPTION);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
}
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_inbox_list_opt
 * DESCRIPTION
 *  Entry inbox list option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_inbox_list_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];
	U8 *pNumber = NULL;

    EMSData *pEms;
#ifdef __MMI_MESSAGES_EMS__    //modify     
    EMSObject *object_p = NULL;
#endif /* __MMI_MESSAGES_EMS__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* in case there is an interrupt cut in during getting msg content */
    if (IsScreenPresent(SCR_ID_MSG_PROCESSING))
    {
        HistoryReplace(SCR_ID_MSG_PROCESSING, SCR_ID_MSG_INBOX_LIST_OPTION, mmi_msg_entry_inbox_list_opt);
        return;
    }

    EntryNewScreen(SCR_ID_MSG_INBOX_LIST_OPTION, mmi_msg_exit_generic, mmi_msg_entry_inbox_list_opt, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_inbox_list_opt *\n");
    
    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_INBOX_LIST_OPTION);
    g_msg_cntx.sendMessageCase = SEND_CASE_SEND_ONLY;   /* reset */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_INBOX_LIST_OPTION);

#if defined(__MMI_MESSAGES_USE_URL__)
    /* Hide USE URL menu item if incall or wap screen is present */
    if (isInCall() || IsScreenPresent(wap_get_screen_id()))
    {
        mmi_frm_hide_menu_item(MENU_ID_SMS_INBOX_OPT_USE_URL);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_SMS_INBOX_OPT_USE_URL);
    }
#endif /* defined(__MMI_MESSAGES_USE_URL__) */ 


    /* Hide USE object menu item if no object in the message */
    GetEMSDataForView(&pEms, 0);
#ifdef __MMI_MESSAGES_EMS__   
    object_p = pEms->listHead;
    mmi_frm_hide_menu_item(SMS_INBOX_OPT_SAVE_OBJECT_MENUID);
    while (object_p)
    {
        if ((object_p->Type == EMS_TYPE_PIC) || (object_p->Type == EMS_TYPE_USERDEF_ANM) ||
    #if defined(__MMI_IMELODY_SUPPORT__)
            (object_p->Type == EMS_TYPE_USERDEF_SND) ||
    #endif 
            KAL_FALSE)
        {
            mmi_frm_unhide_menu_item(SMS_INBOX_OPT_SAVE_OBJECT_MENUID);
            break;
        }
        object_p = object_p->next;
    }
#endif /* __MMI_MESSAGES_EMS__ */ 

    mmi_frm_hide_menu_item(SMS_INBOX_OPT_CHAT_MENUID); // TODO: smsnote: not sync with "not define lit option "
    mmi_frm_unhide_menu_item(SMS_INBOX_OPT_VIEW_MENUID);

#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    mmi_frm_unhide_menu_item(SMS_INBOX_OPT_MOVE_TO_ARCHIVE_MENUID);
    mmi_frm_unhide_menu_item(SMS_INBOX_OPT_ADVANCED_MENUID);
#ifdef __MMI_MESSAGES_CHAT__  
    if (pEms->listHead == NULL)   
    {
        if ( (CheckForInvitationMsg(pEms->textBuffer, (S32) pEms->textLength, TRUE) !=FALSE)  ||  
            (gChatInvitation != 0)) 
            mmi_frm_hide_menu_item(SMS_INBOX_OPT_MOVE_TO_ARCHIVE_MENUID);	
        else
            mmi_frm_unhide_menu_item(SMS_INBOX_OPT_MOVE_TO_ARCHIVE_MENUID);				
    }
#endif	
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/

   /* if SMS is not ready */
    if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_INBOX) == MMI_FRM_SMS_INVALID_INDEX)
    {
        pNumber = mmi_frm_sms_get_address(MMI_FRM_SMS_APP_NOBOX, g_msg_cntx.msg_ind_index);
    }
    else
    {
        pNumber = mmi_frm_sms_get_address(MMI_FRM_SMS_APP_INBOX, (U16) g_msg_cntx.currBoxIndex);
    }
	if (mmi_frm_sms_check_dst_number(pNumber, (U8)strlen((const char*)pNumber)) == TRUE)
	{
		mmi_frm_unhide_menu_item(SMS_INBOX_OPT_REPLY_MENUID);
	#ifdef __MMI_MESSAGES_CHAT__
		mmi_frm_unhide_menu_item(SMS_INBOX_OPT_CHAT_MENUID);
	#endif
	}
	else
	{
		mmi_frm_hide_menu_item(SMS_INBOX_OPT_REPLY_MENUID);
	#ifdef __MMI_MESSAGES_CHAT__
		mmi_frm_hide_menu_item(SMS_INBOX_OPT_CHAT_MENUID);
	#endif
	}

    numItems = GetNumOfChild_Ext(SMS_INBOX_OPTIONS_MENUID);
    GetSequenceStringIds_Ext(SMS_INBOX_OPTIONS_MENUID, nStrItemList);    
    SetParentHandler(SMS_INBOX_OPTIONS_MENUID);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    SetMessagesCurrScrnID(SCR_ID_MSG_INBOX_LIST_OPTION);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_outbox_list_opt
 * DESCRIPTION
 *  Entry outbox list option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_outbox_list_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* in case there is an interrupt cut in during getting msg content */
    if (IsScreenPresent(SCR_ID_MSG_PROCESSING))
    {
        HistoryReplace(SCR_ID_MSG_PROCESSING, SCR_ID_MSG_OUTBOX_LIST_OPTION, mmi_msg_entry_outbox_list_opt);
        return;
    }
    
    EntryNewScreen(SCR_ID_MSG_OUTBOX_LIST_OPTION, mmi_msg_exit_generic, mmi_msg_entry_outbox_list_opt, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_outbox_list_opt *\n");

    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_OUTBOX_LIST_OPTION);
    g_msg_cntx.sendMessageCase = SEND_CASE_SEND_ONLY;   /* reset */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_OUTBOX_LIST_OPTION);

#if defined(__MMI_MESSAGES_USE_URL__)
    /* Hide USE URL menu item if incall or wap screen is present */
    if (isInCall() || IsScreenPresent(wap_get_screen_id()))
    {
        mmi_frm_hide_menu_item(MENU_ID_SMS_OUTBOX_OPT_USE_URL);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_SMS_OUTBOX_OPT_USE_URL);
    }
#endif /* defined(__MMI_MESSAGES_USE_URL__) */ 

    if (mmi_um_get_current_msg_box_type() == UM_MSG_BOX_TYPE_SENT) /*mean SENT (=sms's outbox)*/
    {
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__        
        mmi_frm_unhide_menu_item(SMS_OUTBOX_OPT_MOVE_TO_ARCHIVE_MENUID);
#endif
        mmi_frm_hide_menu_item(SMS_OUTBOX_OPT_SEND_MENUID);
        mmi_frm_unhide_menu_item(SMS_OUTBOX_OPT_FORWARD_MENUID);
    }
    else    /* UNSENT or DRAFT  */
    {
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__    
        //add hide "move to archive" when user not enter UM sent box 
        mmi_frm_hide_menu_item(SMS_OUTBOX_OPT_MOVE_TO_ARCHIVE_MENUID);
        mmi_frm_unhide_menu_item(SMS_INBOX_OPT_ADVANCED_MENUID);
#endif
        mmi_frm_hide_menu_item(SMS_OUTBOX_OPT_FORWARD_MENUID);
        mmi_frm_unhide_menu_item(SMS_OUTBOX_OPT_SEND_MENUID);
    }

    mmi_frm_unhide_menu_item(SMS_OUTBOX_OPT_VIEW_MENUID);

    numItems = GetNumOfChild_Ext(SMS_OUTBOX_OPTIONS_MENUID);
    GetSequenceStringIds_Ext(SMS_OUTBOX_OPTIONS_MENUID, nStrItemList);

    SetParentHandler(SMS_OUTBOX_OPTIONS_MENUID);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    SetMessagesCurrScrnID(SCR_ID_MSG_OUTBOX_LIST_OPTION);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_default_list_opt
 * DESCRIPTION
 *  Entry default list option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_default_list_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* in case there is an interrupt cut in during getting msg content */
    if (IsScreenPresent(SCR_ID_MSG_PROCESSING))
    {
        HistoryReplace(SCR_ID_MSG_PROCESSING, SCR_ID_MSG_DEFAULT_LIST_OPTION, mmi_msg_entry_default_list_opt);
        return;
    }    
    
    EntryNewScreen(SCR_ID_MSG_DEFAULT_LIST_OPTION, mmi_msg_exit_generic, mmi_msg_entry_default_list_opt, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_default_list_opt *\n");

    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_DEFAULT_LIST_OPTION);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_DEFAULT_LIST_OPTION);

    if (mmi_um_get_current_msg_box_type() != UM_MSG_BOX_TYPE_INBOX)
    {
    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        if (mmi_um_get_current_msg_box_type() == UM_MSG_BOX_TYPE_SIM)
        {
        #ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
            mmi_frm_unhide_menu_item(SMS_SIM_OPT_VIEW_MENUID);
        #endif
            numItems = GetNumOfChild_Ext(SMS_SIM_OPTIONS_MENUID);
            GetSequenceStringIds_Ext(SMS_SIM_OPTIONS_MENUID, nStrItemList);
            SetParentHandler(SMS_SIM_OPTIONS_MENUID);
        }
        else
    #endif
        {
        #ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__    
            mmi_frm_unhide_menu_item(SMS_DEFAULT_OPT_VIEW_MENUID);
        #endif
            numItems = GetNumOfChild_Ext(SMS_OUTBOX_DEFAULT_OPTIONS_MENUID);
            GetSequenceStringIds_Ext(SMS_OUTBOX_DEFAULT_OPTIONS_MENUID, nStrItemList);
            SetParentHandler(SMS_OUTBOX_DEFAULT_OPTIONS_MENUID);
        }
    }
    else
    {
    #ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
        mmi_frm_unhide_menu_item(SMS_SR_OPT_VIEW_MENUID);
    #endif

        numItems = GetNumOfChild_Ext(SMS_INBOX_SR_OPTIONS_MENUID);
        GetSequenceStringIds_Ext(SMS_INBOX_SR_OPTIONS_MENUID, nStrItemList);
        SetParentHandler(SMS_INBOX_SR_OPTIONS_MENUID);
    }
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    SetMessagesCurrScrnID(SCR_ID_MSG_DEFAULT_LIST_OPTION);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_view
 * DESCRIPTION
 *  Highlight list option view menu itme
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_entry_view_msg,
        GoBackHistory);
}

extern void mmi_msg_get_msg_rsp(void *data, module_type mod, U16 result);    
/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_view_msg
 * DESCRIPTION
 *  Entry list option view msg
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_view_msg(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    UmMsgBoxType type = mmi_um_get_current_msg_box_type();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_view_msg *\n");

    switch (type)
    {
        case UM_MSG_BOX_TYPE_INBOX:
        {
            U16 status = mmi_frm_sms_get_sms_status(MMI_FRM_SMS_INBOX, (U16)g_msg_cntx.currBoxIndex);
            
            /* Update the totalinbox value in order to get the current inbox list size  */
            msgbox_info.totalinbox = mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_INBOX);

            if ((status & MMI_FRM_SMS_UNREAD) == MMI_FRM_SMS_UNREAD)
            {
                /* set status from unread to read */
                mmi_msg_get_msg_inbox();
            }
            else
            {
                if (GetExitScrnID() == SCR_ID_MSG_INBOX_LIST_OPTION)
                {
#ifdef __MMI_MESSAGES_CHAT__
                	gChatInvitation = FALSE;
#endif /* __MMI_MESSAGES_CHAT__ */                    
                    mmi_msg_entry_inbox_msg();
                }
                else if (GetExitScrnID() == SCR_ID_MSG_DEFAULT_LIST_OPTION)
                {
                    mmi_msg_entry_default_msg();
                }            
                else
                {
                   MMI_ASSERT(0);
                }
            }
            break;
        }
        case UM_MSG_BOX_TYPE_SENT:
        case UM_MSG_BOX_TYPE_UNSENT:
        case UM_MSG_BOX_TYPE_DRAFT:
        {
            if (GetExitScrnID() == SCR_ID_MSG_OUTBOX_LIST_OPTION)
            {
                mmi_msg_entry_outbox_msg();
            }
            else if (GetExitScrnID() == SCR_ID_MSG_DEFAULT_LIST_OPTION)
            {
                mmi_msg_entry_default_msg();
            }            
            else
            {
                   MMI_ASSERT(0);
            }
            break;
        }

#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case UM_MSG_BOX_TYPE_ARCHIVE:
        {
            mmi_frm_sms_msgbox_enum srcBoxType= mmi_frm_sms_get_archive_src_box_type(MMI_FRM_SMS_ARCHIVE, (U16) g_msg_cntx.currBoxIndex);			
            if (GetExitScrnID() == SCR_ID_MSG_ARCHIVE_LIST_OPTION)
            {
                if ( (srcBoxType == MMI_FRM_SMS_INBOX) || (srcBoxType == MMI_FRM_SMS_UNREAD) )
                {
                    if (srcBoxType == MMI_FRM_SMS_UNREAD)
                    {
                        mmi_frm_sms_archive_change_status_to_read((U8)MMI_FRM_SMS_ARCHIVE,  (U16)(g_msg_cntx.currBoxIndex)); 
                    }                  
                    mmi_msg_entry_archive_msg_inbox();                
                }
                else if (srcBoxType == MMI_FRM_SMS_OUTBOX)		
                {
                    mmi_msg_entry_archive_msg_outbox();                
                }
                else
                {
                    MMI_ASSERT(0);
                }
            }
			
            break;			
        }
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/

    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        case UM_MSG_BOX_TYPE_SIM:
        {
            U16 status = mmi_frm_sms_get_sms_status(MMI_FRM_SMS_SIM, (U16)g_msg_cntx.currBoxIndex);

            if ((status & MMI_FRM_SMS_UNREAD) == MMI_FRM_SMS_UNREAD)
            {
                /* set status from unread to read */
                mmi_msg_get_msg_simbox();

                return;
            }            
            if (GetExitScrnID() == SCR_ID_MSG_SIMBOX_LIST_OPTION)
            {
                mmi_msg_entry_simbox_msg();
            }
            else if (GetExitScrnID() == SCR_ID_MSG_DEFAULT_LIST_OPTION)
            {
                mmi_msg_entry_default_msg();
            }            
            else
            {
                /* Do nothing */
            }
            break;
        }
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
        default:
        {
            MMI_ASSERT(0);
            break;
        }    
    }
}

#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_sim_list_opt
 * DESCRIPTION
 *  Entry SIM Message list option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_sim_list_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* in case there is an interrupt cut in during getting msg content */
    if (IsScreenPresent(SCR_ID_MSG_PROCESSING))
    {
        HistoryReplace(SCR_ID_MSG_PROCESSING, SCR_ID_MSG_SIMBOX_LIST_OPTION, mmi_msg_entry_sim_list_opt);
        return;
    }
    
    EntryNewScreen(SCR_ID_MSG_SIMBOX_LIST_OPTION, mmi_msg_exit_generic, mmi_msg_entry_sim_list_opt, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_simbox_list_opt *\n");

    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_SIMBOX_LIST_OPTION);    
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_SIMBOX_LIST_OPTION);    

    mmi_frm_unhide_menu_item(SMS_SIM_OPT_VIEW_MENUID);
    numItems = GetNumOfChild_Ext(SMS_SIM_OPTIONS_MENUID);
    GetSequenceStringIds_Ext(SMS_SIM_OPTIONS_MENUID, nStrItemList);    

    SetParentHandler(SMS_SIM_OPTIONS_MENUID);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    SetMessagesCurrScrnID(SCR_ID_MSG_SIMBOX_LIST_OPTION);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
}
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

#endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */

#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_option_simbox
 * DESCRIPTION
 *  Entry SIM Message option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_option_simbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* in case there is an interrupt cut in during getting msg content */
    if (IsScreenPresent(SCR_ID_MSG_PROCESSING))
    {
        HistoryReplace(SCR_ID_MSG_PROCESSING, SCR_ID_MSG_SIMBOX_OPTION, mmi_msg_entry_option_simbox);
        return;
    }
    
    EntryNewScreen(SCR_ID_MSG_SIMBOX_OPTION, mmi_msg_exit_generic, mmi_msg_entry_option_simbox, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_simbox_list_opt *\n");

/* the deleting screen start point has to be reset to sim messagescreen if sim msg option is entered */
#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
    if (IsScreenPresent(SCR_ID_MSG_SIMBOX_LIST_OPTION))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_SIMBOX_LIST_OPTION);
    }
    else
#endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_SIMBOX_MSG);
    }       
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_SIMBOX_OPTION);    

#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
    mmi_frm_hide_menu_item(SMS_SIM_OPT_VIEW_MENUID);
#endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */
    numItems = GetNumOfChild_Ext(SMS_SIM_OPTIONS_MENUID);    
    GetSequenceStringIds_Ext(SMS_SIM_OPTIONS_MENUID, nStrItemList);
    

    SetParentHandler(SMS_SIM_OPTIONS_MENUID);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    SetMessagesCurrScrnID(SCR_ID_MSG_SIMBOX_OPTION);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_simbox_header
 * DESCRIPTION
 *  Get simbox message header
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 *mmi_msg_get_simbox_header(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static S8 buffer[120 * ENCODING_LENGTH];
    S8 buf2[10];
    S8 temp[MAX_DIGITS * ENCODING_LENGTH];
    S8 number[(MAX_DIGITS_SMS + 1) * ENCODING_LENGTH];
    S8 *name;
    S8 ts_date[(MAX_TIMESTAMP_SIZE + 1) * ENCODING_LENGTH];
    S8 ts_time[(MAX_TIMESTAMP_SIZE + 1) * ENCODING_LENGTH];
    U16 type = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_asc_to_ucs2(buf2, "\n");
    type = mmi_frm_sms_get_status(MMI_FRM_SMS_APP_SIM, (U16)g_msg_cntx.currBoxIndex) & 0x0f;
    if (PendingSaveSendData.mti == SMSAL_MTI_STATUS_REPORT)
    {
        if (PendingSaveSendData.st == ST_COMP_MSG_RECV_BY_SME)
        {
            mmi_ucs2cpy(buffer, GetString(STR_SR_DELIVERD_ID));
        }
        else
        {
            mmi_ucs2cpy(buffer, GetString(STR_SR_PENDING_ID));
        }
    }
    else if (PendingSaveSendData.mti == SMSAL_MTI_UNSPECIFIED)
    {
        mmi_ucs2cpy(buffer, GetString(STR_SMS_DOES_NOT_SUPPORT));
    }
    else
    {      
        if (type == MMI_FRM_SMS_UNREAD || type == MMI_FRM_SMS_INBOX)
        {
            mmi_ucs2cpy(buffer, GetString(STR_SMS_MESSAGE_HEADER_FROM));
        }
        else
        {
            mmi_ucs2cpy(buffer, GetString(STR_SMS_MESSAGE_HEADER_TO));
        }
    }
    mmi_ucs2cat(buffer, buf2);

    memset(number, 0, (MAX_DIGITS_SMS + 1) * ENCODING_LENGTH);
    /* if SMS is not ready */
    if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_INBOX) == MMI_FRM_SMS_INVALID_INDEX)
    {
        mmi_asc_n_to_ucs2(number,
        	(S8*)mmi_frm_sms_get_address(MMI_FRM_SMS_APP_NOBOX, g_msg_cntx.msg_ind_index),
        	MAX_DIGITS_SMS);
    }
    else
    {
        mmi_asc_n_to_ucs2(number,
            (S8*)mmi_frm_sms_get_address(MMI_FRM_SMS_APP_SIM, (U16)g_msg_cntx.currBoxIndex),
            MAX_DIGITS_SMS);
    }
    mmi_ucs2cpy(temp, number);
    name = lookUpNumber(temp);
    if (mmi_ucs2strlen(name))
    {
        mmi_ucs2cat(buffer, name);
    }
    else
    {
        mmi_ucs2cat(buffer, temp);
    }

    if (type == MMI_FRM_SMS_UNREAD || type == MMI_FRM_SMS_INBOX)
    {
        /* if SMS is not ready */
        if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_INBOX) == MMI_FRM_SMS_INVALID_INDEX)
        {
            mmi_msg_get_msg_date_time(
                ts_date,
                ts_time,
                mmi_frm_sms_get_timestamp(MMI_FRM_SMS_APP_NOBOX, g_msg_cntx.msg_ind_index));
        }
        else
        {
            mmi_msg_get_msg_date_time(
                ts_date,
                ts_time,
                mmi_frm_sms_get_timestamp(MMI_FRM_SMS_APP_SIM, (U16) g_msg_cntx.currBoxIndex));
        }
        mmi_ucs2cat(buffer, buf2);
        mmi_ucs2cat(buffer, ts_date);
        mmi_ucs2cat(buffer, buf2);
        mmi_ucs2cat(buffer, ts_time);        
    }
    mmi_ucs2cat(buffer, buf2);
    
    return (U8*) buffer;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_simbox_msg
 * DESCRIPTION
 *  Entry simbox message screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_simbox_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 *pHeader;
    EMSData *pEms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* in case there is an interrupt cut in before displaying message content */
    if (IsScreenPresent(SCR_ID_MSG_PROCESSING))
    {
        HistoryReplace(SCR_ID_MSG_PROCESSING, SCR_ID_MSG_SIMBOX_MSG, mmi_msg_entry_simbox_msg);
        return;
    }
    EntryNewScreen(SCR_ID_MSG_SIMBOX_MSG, mmi_msg_exit_generic, mmi_msg_entry_simbox_msg, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_simbox_msg*\n");

#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
    if (IsScreenPresent(SCR_ID_MSG_SIMBOX_LIST_OPTION))
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_SIMBOX_LIST_OPTION);
    }
    else
#endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_SIMBOX_MSG);
    }
    
    SetMessagesCurrScrnID(SCR_ID_MSG_SIMBOX_MSG);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_SIMBOX_MSG);
    GetEMSDataForView(&pEms, 0);
    pHeader = mmi_msg_get_simbox_header();
    g_msg_cntx.number_from_phb = 0;

#if defined(__MMI_MESSAGES_EMS__)
    EnableDisableAudioPlayback();
#endif 
    ShowCategory39Screen(
        STR_SCR6024_CAPTION,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OPTIONS,
        IMG_SMS_COMMON_NOIMAGE,
        STR_GLOBAL_BACK,
        IMG_SMS_COMMON_NOIMAGE,
        pEms,
        pHeader,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_msg_entry_option_simbox, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_copy_all_simbox
 * DESCRIPTION
 *  highlight copy all from sim handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_copy_all_simbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_set_confirm_screen(STR_SMS_COPY_ALL_QUERY_ID, mmi_msg_copy_msg_all_simbox, GoBackHistory);
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_entry_confirm_generic,
        GoBackHistory);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_move_all_simbox
 * DESCRIPTION
 *  highlight move all from sim handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_move_all_simbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_set_confirm_screen(STR_SMS_MOVE_ALL_QUERY_ID, mmi_msg_move_msg_all_simbox, GoBackHistory);
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_entry_confirm_generic,
        GoBackHistory);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

}

#endif /* __MMI_SIM_MESSAGE__ */

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
static U16 mmi_msg_get_unsent_sms_l4_index(void);
static void mmi_msg_set_unsent_status_callback(void *dummy, module_type mod, U16 result);
static void mmi_msg_unsent_msg_move_to_draft_callback(void *dummy, module_type mod, U16 result);
static BOOL mmi_msg_check_unsent_sms_exist(void);

static U8 currHiliteSendStatus;
static U16 currHiliteL4Index = MMI_FRM_SMS_INVALID_NUM;
mmi_msg_unsent_state_enum currUnsentOperateState = UNSENT_IDLE_STATE;


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_unsent_operate_state
 * DESCRIPTION
 *  Get Unsent box operate state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_msg_get_unsent_operate_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return currUnsentOperateState;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_update_unsent_icon
 * DESCRIPTION
 *  update idle top bar unsent box icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_update_unsent_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 totalunsent;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    totalunsent = mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_UNSENT);

	if (totalunsent == MMI_FRM_SMS_INVALID_INDEX)
	{
		return;
	}
	
	if (totalunsent > 0)
	{
        ShowStatusIcon(STATUS_ICON_OUTBOX_INDICATOR);
		UpdateStatusIcons();
	}
	else
	{
        HideStatusIcon(STATUS_ICON_OUTBOX_INDICATOR);
		UpdateStatusIcons();
    }	
}

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_unsent_sms_l4_index
 * DESCRIPTION
 *  Get current highlight unsent sms l4 index 
 * PARAMETERS
 *  void
 * RETURNS
 *  L4 Index of the unsent sms
 *****************************************************************************/
static U16 mmi_msg_get_unsent_sms_l4_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 currL4IndexArr[MMI_SMS_MAX_MSG_SEG];
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_frm_sms_get_sms_index(MMI_FRM_SMS_UNSENT, (U16)g_msg_cntx.currBoxIndex, currL4IndexArr);
	return currL4IndexArr[0];
}

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_check_unsent_sms_exist
 * DESCRIPTION
 *  check the current highlight unsent sms is exist
 * PARAMETERS
 *  void
 * RETURNS
 *  If exist return TRUE, else return FALSE
 *****************************************************************************/
static BOOL mmi_msg_check_unsent_sms_exist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 currL4Index;
	U8 send_status;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	currL4Index = mmi_msg_get_unsent_sms_l4_index();
	send_status = mmi_frm_sms_get_unsent_status((U16)g_msg_cntx.currBoxIndex);
	
	if ((currL4Index == currHiliteL4Index) && (send_status == currHiliteSendStatus))
	{
		return TRUE;
	}
	else
	{
		if (currL4Index != currHiliteL4Index)
		{
			DisplayPopup(
	            (PU8) GetString(STR_SMS_BACKGROUND_NOT_EXIST_ID),
	            IMG_GLOBAL_WARNING,
	            1,
	            MESSAGES_POPUP_TIME_OUT,
	            (U8) WARNING_TONE);
		}
		else if (send_status != currHiliteSendStatus)
		{
			DisplayPopup(
	            (PU8) GetString(STR_SMS_BACKGROUND_STATUS_CHANGED_ID),
	            IMG_GLOBAL_WARNING,
	            1,
	            MESSAGES_POPUP_TIME_OUT,
	            (U8) WARNING_TONE);
		}

		DeleteScreenIfPresent(SCR_ID_MSG_UNSENTBOX_OPTION);		

		return FALSE;
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_pre_entry_option_unsent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_pre_entry_option_unsent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	currHiliteL4Index = mmi_msg_get_unsent_sms_l4_index();
	currHiliteSendStatus = mmi_frm_sms_get_unsent_status((U16)g_msg_cntx.currBoxIndex);
	currUnsentOperateState = UNSENT_IDLE_STATE;
	mmi_msg_entry_option_unsent();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_option_unsent
 * DESCRIPTION
 *  Entry unsentbox option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_option_unsent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_UNSENTBOX_OPTION, mmi_msg_exit_generic, mmi_msg_entry_option_unsent, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_option_unsent*\n");

    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_UNSENTBOX_OPTION);

    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_UNSENTBOX_OPTION);

	g_msg_cntx.toDisplayMessageList = TO_DISPLAY_MESSAGE_LIST_UNSENTBOX;

	switch (currHiliteSendStatus)
	{	
	case MMI_FRM_SMS_APP_WAITING:
		mmi_frm_hide_menu_item(MENU_ID_SMS_UNSENTBOX_OPT_SEND);
		mmi_frm_unhide_menu_item(MENU_ID_SMS_UNSENTBOX_OPT_CANCEL_SEND);
		mmi_frm_unhide_menu_item(MENU_ID_SMS_UNSENTBOX_OPT_DELETE);
		mmi_frm_unhide_menu_item(MENU_ID_SMS_UNSENTBOX_OPT_DELETE_ALL);
		mmi_frm_unhide_menu_item(MENU_ID_SMS_UNSENTBOX_OPT_MOVE_TO_DRAFT);		
		break;
		
    case MMI_FRM_SMS_APP_FAILTOSEND:
		mmi_frm_hide_menu_item(MENU_ID_SMS_UNSENTBOX_OPT_CANCEL_SEND);
		mmi_frm_unhide_menu_item(MENU_ID_SMS_UNSENTBOX_OPT_SEND);
		mmi_frm_unhide_menu_item(MENU_ID_SMS_UNSENTBOX_OPT_DELETE);
		mmi_frm_unhide_menu_item(MENU_ID_SMS_UNSENTBOX_OPT_DELETE_ALL);
		mmi_frm_unhide_menu_item(MENU_ID_SMS_UNSENTBOX_OPT_MOVE_TO_DRAFT);		
		break;
		
    case MMI_FRM_SMS_APP_SENDING:
		mmi_frm_hide_menu_item(MENU_ID_SMS_UNSENTBOX_OPT_SEND);
		mmi_frm_hide_menu_item(MENU_ID_SMS_UNSENTBOX_OPT_DELETE);
		mmi_frm_hide_menu_item(MENU_ID_SMS_UNSENTBOX_OPT_DELETE_ALL);
		mmi_frm_hide_menu_item(MENU_ID_SMS_UNSENTBOX_OPT_MOVE_TO_DRAFT);
		mmi_frm_unhide_menu_item(MENU_ID_SMS_UNSENTBOX_OPT_CANCEL_SEND);		
		break;
		
	default:
		MMI_ASSERT(0);
		break;
			
	}

    numItems = GetNumOfChild_Ext(MENU_ID_SMS_UNSENTBOX_OPTIONS);
    GetSequenceStringIds_Ext(MENU_ID_SMS_UNSENTBOX_OPTIONS, nStrItemList);

    SetParentHandler(MENU_ID_SMS_UNSENTBOX_OPTIONS);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    SetMessagesCurrScrnID(SCR_ID_MSG_UNSENTBOX_OPTION);

    ShowCategory52Screen(
        STR_SCR6028_CAPTION,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_unsent_opt_send
 * DESCRIPTION
 *  Highlight unsentbox option item "Send" handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_unsent_opt_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_unsent_send,
        GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_unsent_opt_cancel_send
 * DESCRIPTION
 *  Highlight unsentbox option item "Cancel Send" handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_unsent_opt_cancel_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_unsent_cancel_send,
        GoBackHistory);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_unsent_opt_delete
 * DESCRIPTION
 *  Highlight unsentbox option item "Delete" handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_unsent_opt_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_unsent_delete,
        GoBackHistory);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_unsent_opt_delete_all
 * DESCRIPTION
 *  Highlight unsentbox option item "Delete All" handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_unsent_opt_delete_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_unsent_delete_all,
        GoBackHistory);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_unsent_opt_move_to_draft
 * DESCRIPTION
 *  Highlight unsentbox option item "Move To draft" handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_unsent_opt_move_to_draft(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_unsent_move_to_draft,
        GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_unsent_send
 * DESCRIPTION
 *  SMS Background send Support : Send unsent sms  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_unsent_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (mmi_msg_check_unsent_sms_exist() == TRUE)
	{
		currUnsentOperateState = UNSENT_SEND_STATE;

		mmi_frm_sms_set_unsent_status(
				mmi_msg_set_unsent_status_callback,
				(U16)g_msg_cntx.currBoxIndex,
				MMI_FRM_SMS_APP_SENDING);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_unsent_cancel_send
 * DESCRIPTION
 *  SMS Background send Support : Cancel Send unsent sms  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_unsent_cancel_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (mmi_msg_check_unsent_sms_exist() == TRUE)
	{
		currUnsentOperateState = UNSENT_CANCEL_SEND_STATE;

		mmi_msg_set_processing_screen(STR_OUTBOX_MENUENTRY, STR_GLOBAL_ABORTING, IMG_GLOBAL_PROGRESS, 0);
       	mmi_msg_entry_processing_generic();

		mmi_frm_sms_set_unsent_status(
				mmi_msg_set_unsent_status_callback,
				(U16)g_msg_cntx.currBoxIndex,
				MMI_FRM_SMS_APP_FAILTOSEND);
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_unsent_delete
 * DESCRIPTION
 *  SMS Background send Support : Delete unsent sms 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_unsent_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (mmi_msg_check_unsent_sms_exist() == TRUE)
	{
		mmi_msg_set_confirm_screen(STR_DELETE_SMS_QUERY_ID, mmi_msg_delete_msg, GoBackHistory);
		mmi_msg_entry_confirm_generic();
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_unsent_delete_all
 * DESCRIPTION
 *  SMS Background send Support : Delete All unsent sms 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_unsent_delete_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (mmi_msg_check_unsent_sms_exist() == TRUE)
	{
		mmi_msg_pre_delete_msg_all_unsentbox();
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_unsent_move_to_draft
 * DESCRIPTION
 *  SMS Background send Support : move unsent sms to draft box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_unsent_move_to_draft(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (mmi_msg_check_unsent_sms_exist() == TRUE)
	{
    	mmi_msg_set_confirm_screen(STR_SMS_BACKGROUND_MOVETO_DRAFT_QUERY_ID, mmi_msg_unsent_msg_move_to_draft, GoBackHistory);
    	mmi_msg_entry_confirm_generic();
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_unsent_msg_move_to_draft
 * DESCRIPTION
 *  move unsent sms to draft box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_unsent_msg_move_to_draft(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_msg_set_processing_screen(STR_OUTBOX_MENUENTRY, STR_SMS_MOVING, IMG_GLOBAL_PROGRESS, 0);
   	mmi_msg_entry_processing_generic();

	mmi_frm_sms_move_sms_to_otherbox(
			mmi_msg_unsent_msg_move_to_draft_callback,
	        MOD_MMI, 
	        MMI_FRM_SMS_APP_UNSENT,
	        (U16)g_msg_cntx.currBoxIndex, 
	        MMI_FRM_SMS_APP_DRAFTS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_set_unsent_status_callback
 * DESCRIPTION
 *  set unsent sms status callback function
 * PARAMETERS
 *  dummy       [?]         
 *  mod         [IN]        
 *  result      [IN] 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_msg_set_unsent_status_callback(void *dummy, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (result == MMI_FRM_SMS_OK)
	{
		switch (currUnsentOperateState)
		{
		case UNSENT_SEND_STATE:
			if (GetExitScrnID() == SCR_ID_MSG_UNSENTBOX_OPTION)
			{
				GoBackHistory();
			}
			else
			{
				DeleteScreenIfPresent(SCR_ID_MSG_UNSENTBOX_OPTION);
			}
			break;
			
		case UNSENT_CANCEL_SEND_STATE:
			DisplayPopup(
	        (PU8) GetString(STR_GLOBAL_DONE),
	        IMG_GLOBAL_ACTIVATED,
	        1,
	        MESSAGES_POPUP_TIME_OUT,
	        (U8) SUCCESS_TONE);
	
			DeleteScreenIfPresent(SCR_ID_MSG_PROCESSING);
			DeleteScreenIfPresent(SCR_ID_MSG_UNSENTBOX_OPTION);
			break;

		case UNSENT_DELETE_STATE:
		case UNSENT_MOVE_TO_DRAFT_STATE:
		case UNSENT_IDLE_STATE:
		case UNSENT_DELETE_ALL_STATE:
		default:
			break;
		}
	}
	else
	{
        DisplayPopup(
        (PU8) GetString(STR_GLOBAL_UNFINISHED),
        IMG_GLOBAL_ERROR,
        1,
        MESSAGES_POPUP_TIME_OUT,
        (U8) ERROR_TONE);
        
		DeleteScreenIfPresent(SCR_ID_MSG_PROCESSING);
		DeleteScreenIfPresent(SCR_ID_MSG_UNSENTBOX_OPTION);
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_unsent_msg_move_to_draft_callback
 * DESCRIPTION
 *  move unsent sms to draft callback function
 * PARAMETERS
 *  dummy       [?]         
 *  mod         [IN]        
 *  result      [IN] 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_msg_unsent_msg_move_to_draft_callback(void *dummy, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (result == MMI_FRM_SMS_OK)
	{
        DisplayPopup(
	        (PU8) GetString(STR_GLOBAL_DONE),
	        IMG_GLOBAL_ACTIVATED,
	        1,
	        MESSAGES_POPUP_TIME_OUT,
	        (U8) SUCCESS_TONE);
		
		mmi_msg_update_unsent_icon();
	}
	else
	{
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_ERROR,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
	}

	DeleteScreenIfPresent(SCR_ID_MSG_PROCESSING);
	DeleteScreenIfPresent(SCR_ID_MSG_UNSENTBOX_OPTION);
}

#endif /*__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__*/


#ifdef __MMI_DUAL_SIM_MASTER__
/*****************************************************************************
 * FUNCTION
 *  mmi_msg_set_msg_type_as_slave
 * DESCRIPTION
 *  Set current message type
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_set_msg_type_as_slave(void)
{
	g_msg_cntx.isSlave = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_master_send_option
 * DESCRIPTION
 *  enter master send option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_master_send_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
	MTPNP_AD_Free_Channel(MTPNP_AD_SMS_CHANNEL);
	MTPNP_AD_Set_Channel(MTPNP_AD_SMS_CHANNEL, MTPNP_AD_CHANNEL_MASTER);	
    
    mmi_msg_entry_send_option();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_slave_send_option
 * DESCRIPTION
 *  enter master send option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_slave_send_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
	MTPNP_AD_Free_Channel(MTPNP_AD_SMS_CHANNEL);
	MTPNP_AD_Set_Channel(MTPNP_AD_SMS_CHANNEL, MTPNP_AD_CHANNEL_SLAVE);	
    
    mmi_msg_entry_send_option();
}
#endif /* __MMI_DUAL_SIM_MASTER__ */

#endif /* __MOD_SMSAL__ */

