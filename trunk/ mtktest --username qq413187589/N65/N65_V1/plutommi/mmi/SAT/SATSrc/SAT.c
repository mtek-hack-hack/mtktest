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
 * SAT.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   SIM application toolkit related functions
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

   FILENAME : SAT.c

   PURPOSE     : SAT Application

   REMARKS     : nil

   AUTHOR      : NEERAJ SHARMA

   DATE     : Mar 24,03

**************************************************************/

#include "MMI_include.h"
#include "Gui_Setting.h"
#include "SATDefs.h"
#include "SATStruct.h"
#include "SATGProts.h"
#include "SATProts.h"
#include "ProtocolEvents.h"
#include "CallManagementStruct.h"
#include "CallManagementGprot.h"
#include "GSM7BitDefaultAlphabet.h"
#include "CommonScreens.h"
#include "SSCStringHandle.h"
#include "lcd_sw_rnd.h"
#include "BootUp.h"
#include "PowerOnChargerProt.h"
#include "SimDetectionDef.h"
#include "SimDetectionGexdcl.h"
#include "SimDetectionGprot.h"
#include "sat_def.h"
#include "CallStructureManagementProt.h"
#include "AlarmFrameworkProt.h"
#include "gpioInc.h"
#include "CallHistoryGProts.h"
#include "PhoneBookGprot.h"
#include "ProfileGprots.h"
#include "SettingGenum.h"
#include "SecuritySetup.h"  /* SECSETGetFdlBdlModeReq */
#include "Service.h"        /* GoToServicesMenu */
#include "ServiceDefs.h"    /* SERVICES_MAIN_MENU_SCREEN_ID */
#include "IdleAppProt.h"

#ifdef WAP_SUPPORT
#include "wap_ps_struct.h"
#include "wapadp.h"
#endif /* WAP_SUPPORT */

#ifdef __USAT__
#include "DateTimeGprot.h"
#endif 

#ifdef __MMI_WLAN_FEATURES__
#include "NetworkSetupDefs.h"
#endif

#ifdef __MMI_OP01_MENU_9MATRIX__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP01_MENU_9MATRIX__ */

#ifdef __MMI_UCM__
#include "UCMGProt.h"
#endif

#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_AD_master_header.h"
#include "MTPNP_AD_resdef.h"
#include "MTPNP_PFAL_Master_Msgs.h"
#include "MTPNP_PFAL_resource.h"
#include "MTPNP_PFAL_CC.h"
#include "MTPNP_PFAL_Master_Callhistory.h"
#include "MTPNP_PFAL_Master_ADN.h"
#endif /* __MMI_DUAL_SIM_MASTER__ */

#ifdef __SAT__

SATSETUPMENU gSATMainMenu;
SATSUBMENU gSATSubMenu;
SATDISPLAYTEXT gSATDisplayText;
SATGETINPUT gSATGetInput;
SATGETINKEY gSATGetInkey;
SATCALLSETUP gSATCallSetup;
SATSENDSMS gSATSendSMS;
SATSENDSS gSATSendSS;
SATSENDUSSD gSATSendUSSD;
SATPLAYTONE gSATPlayTone;

SATLAUNCHBROWSER gSATLaunchBrowser;
SATSENDDTMF gSATSendDTMF;
SATFILECHANGE gSATFileChange;
SATDISPLAYIDLETEXT gSATDisplayIdleText;
SATRUNATCOMMAND gSATRunATCommand;

SATIMAGERECORD gSATImageRecord;
SATCONTEXT gSATContext;

#ifdef __MMI_SAT_LARGE_ICON_SUPPORT__
static U8 g_sat_cmd_icon[MAX_ICON_SUPPORT][4096];
static U8 g_sat_idle_icon[4096];
#endif /* __MMI_SAT_LARGE_ICON_SUPPORT__ */

#ifdef __SATCE__
SATOPENCHANNEL satOpenChannel;
SATCLOSECHANNEL satCloseChannel;
SATSENDDATA satSendData;
SATRECVDATA satRecvData;
#endif /* __SATCE__ */ 

void (*SATGetIconCompleteCallBack) (void);

#define ALLOCATE_ITM(src_mod)       allocate_ilm(src_mod)

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)

#define SEND_MSG(Message)           \
{                                   \
    Message->oslDestId =            \
        (gSATContext.CMDfromSIM == SAT_CMD_SIM2 || gSATContext.satIndex == SAT_CMD_SIM2) ?  \
        MOD_L4C_2 :                 \
        MOD_L4C;                    \
    Message->sap_id = INVALID_SAP;  \
    msg_send_ext_queue(Message);    \
}                                   \

#define SEND_MSG_DISPTEXT(Message)  \
{                                   \
    Message->oslDestId =            \
        (gSATDisplayText.CMDfromSIM == SAT_CMD_SIM2) ? MOD_L4C_2 : MOD_L4C; \
    gSATDisplayText.CMDfromSIM = SAT_CMD_NONE;  \
    Message->sap_id = INVALID_SAP;  \
    msg_send_ext_queue(Message);    \
}                                   \

#define SEND_MSG_TONE(Message)      \
{                                   \
    Message->oslDestId =            \
        (gSATPlayTone.CMDfromSIM == SAT_CMD_SIM2) ? MOD_L4C_2 : MOD_L4C;    \
    gSATPlayTone.CMDfromSIM = SAT_CMD_NONE;     \
    Message->sap_id = INVALID_SAP;  \
    msg_send_ext_queue(Message);    \
}                                   \

#define SEND_MSG_SUBMENU(Message)   \
{                                   \
    Message->oslDestId =            \
        (gSATSubMenu.CMDfromSIM == SAT_CMD_SIM2) ? MOD_L4C_2 : MOD_L4C;     \
    gSATSubMenu.CMDfromSIM = SAT_CMD_NONE;      \
    Message->sap_id = INVALID_SAP;  \
    msg_send_ext_queue(Message);    \
}                                   \

#define SEND_MSG_ICON(Message)      \
{                                   \
    Message->oslDestId =            \
        ((gSATContext.CMDfromSIM == SAT_CMD_SIM2 || gSATContext.satIndex == SAT_CMD_SIM2) || \
        (gSATDisplayText.CMDfromSIM == SAT_CMD_SIM2) || \
        (gSATPlayTone.CMDfromSIM == SAT_CMD_SIM2) ||    \
        (gSATSubMenu.CMDfromSIM == SAT_CMD_SIM2)) ? MOD_L4C_2 : MOD_L4C;    \
    Message->sap_id = INVALID_SAP;  \
    msg_send_ext_queue(Message);    \
}                                   \

#define SET_EVENT(funcPtr, eventID) \
{                                   \
    if ((gSATContext.CMDfromSIM == SAT_CMD_SIM2 || gSATContext.satIndex == SAT_CMD_SIM2) || \
        (gSATDisplayText.CMDfromSIM == SAT_CMD_SIM2) || \
        (gSATPlayTone.CMDfromSIM == SAT_CMD_SIM2) ||    \
        (gSATSubMenu.CMDfromSIM == SAT_CMD_SIM2))       \
    {                               \
        SetSlaveProtocolEventHandler(funcPtr, eventID); \
    }                               \
    else                            \
    {                               \
        SetProtocolEventHandler(funcPtr, eventID);      \
    }                               \
}                                   \

#define CLR_EVENT(eventID)          \
{                                   \
    if ((gSATContext.CMDfromSIM == SAT_CMD_SIM2 || gSATContext.satIndex == SAT_CMD_SIM2) || \
        (gSATDisplayText.CMDfromSIM == SAT_CMD_SIM2) || \
        (gSATPlayTone.CMDfromSIM == SAT_CMD_SIM2) ||    \
        (gSATSubMenu.CMDfromSIM == SAT_CMD_SIM2))       \
    {                               \
        ClearSlaveProtocolEventHandler(eventID);        \
    }                               \
    else                            \
    {                               \
        ClearProtocolEventHandler(eventID);             \
    }                               \
}                                   \

#else /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */

#define SEND_MSG(Message)           \
{                                   \
    Message->oslDestId = MOD_L4C;   \
    Message->sap_id = INVALID_SAP;  \
    msg_send_ext_queue(Message);    \
}                                   \

#define SEND_MSG_DISPTEXT(Message)  \
{                                   \
    Message->oslDestId = MOD_L4C;   \
    Message->sap_id = INVALID_SAP;  \
    msg_send_ext_queue(Message);    \
}                                   \

#define SEND_MSG_TONE(Message)      \
{                                   \
    Message->oslDestId = MOD_L4C;   \
    Message->sap_id = INVALID_SAP;  \
    msg_send_ext_queue(Message);    \
}                                   \

#define SEND_MSG_SUBMENU(Message)   \
{                                   \
    Message->oslDestId = MOD_L4C;   \
    Message->sap_id = INVALID_SAP;  \
    msg_send_ext_queue(Message);    \
}                                   \

#define SEND_MSG_ICON(Message)      \
{                                   \
    Message->oslDestId = MOD_L4C;   \
    Message->sap_id = INVALID_SAP;  \
    msg_send_ext_queue(Message);    \
}                                   \

#define SET_EVENT(funcPtr, eventID) \
{                                   \
    SetProtocolEventHandler(funcPtr, eventID);  \
}                                   \

#define CLR_EVENT(eventID)          \
{                                   \
    ClearProtocolEventHandler(eventID);         \
}                                   \

#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */


#define MMI_SAT_INIT
/*****************************************************************************
 * FUNCTION
 *  InitSimAppToolkit
 * DESCRIPTION
 *  Initialises variables & Protocol Handlers for SAT
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitSimAppToolkit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    SetProtocolEventHandler(SATSetupMenuSIM1Ind, PRT_MMI_SAT_SETUP_MENU_IND);
    SetSlaveProtocolEventHandler(SATSetupMenuSIM2Ind, PRT_MMI_SAT_SETUP_MENU_IND);
#else
    SetProtocolEventHandler(SATSetupMenuInd, PRT_MMI_SAT_SETUP_MENU_IND);
#endif
    SetProtocolEventHandler(SATSetupMenuRsp, PRT_MMI_SAT_SETUP_MENU_RES_RSP);
    SetProtocolEventHandler(SATMenuSelectRsp, PRT_MMI_SAT_MENU_SELECT_RSP);
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    SetSlaveProtocolEventHandler(SATSetupMenuRsp, PRT_MMI_SAT_SETUP_MENU_RES_RSP);
    SetSlaveProtocolEventHandler(SATMenuSelectRsp, PRT_MMI_SAT_MENU_SELECT_RSP);
#endif

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    SetProtocolEventHandler(SATSelectItemSIM1Ind, PRT_MMI_SAT_SELECT_ITEM_IND);
    SetSlaveProtocolEventHandler(SATSelectItemSIM2Ind, PRT_MMI_SAT_SELECT_ITEM_IND);
#else
    SetProtocolEventHandler(SATSelectItemInd, PRT_MMI_SAT_SELECT_ITEM_IND);
#endif
    SetProtocolEventHandler(SATSelectItemRsp, PRT_MMI_SAT_SELECT_ITEM_RES_RSP);
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    SetSlaveProtocolEventHandler(SATSelectItemRsp, PRT_MMI_SAT_SELECT_ITEM_RES_RSP);
#endif

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    SetProtocolEventHandler(SATDisplayTextSIM1Ind, PRT_MMI_SAT_DISPLAY_TEXT_IND);
    SetSlaveProtocolEventHandler(SATDisplayTextSIM2Ind, PRT_MMI_SAT_DISPLAY_TEXT_IND);
#else
    SetProtocolEventHandler(SATDisplayTextInd, PRT_MMI_SAT_DISPLAY_TEXT_IND);
#endif
    SetProtocolEventHandler(SATDisplayTextRsp, PRT_MMI_SAT_DISPLAY_TEXT_RES_RSP);
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    SetSlaveProtocolEventHandler(SATDisplayTextRsp_2, PRT_MMI_SAT_DISPLAY_TEXT_RES_RSP);
#endif

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    SetProtocolEventHandler(SATGetInputSIM1Ind, PRT_MMI_SAT_GET_INPUT_IND);
    SetSlaveProtocolEventHandler(SATGetInputSIM2Ind, PRT_MMI_SAT_GET_INPUT_IND);
#else
    SetProtocolEventHandler(SATGetInputInd, PRT_MMI_SAT_GET_INPUT_IND);
#endif
    SetProtocolEventHandler(SATGetInputRsp, PRT_MMI_SAT_GET_INPUT_RES_RSP);
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    SetSlaveProtocolEventHandler(SATGetInputRsp, PRT_MMI_SAT_GET_INPUT_RES_RSP);
#endif

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    SetProtocolEventHandler(SATGetInkeySIM1Ind, PRT_MMI_SAT_GET_INKEY_IND);
    SetSlaveProtocolEventHandler(SATGetInkeySIM2Ind, PRT_MMI_SAT_GET_INKEY_IND);
#else
    SetProtocolEventHandler(SATGetInkeyInd, PRT_MMI_SAT_GET_INKEY_IND);
#endif
    SetProtocolEventHandler(SATGetInkeyRsp, PRT_MMI_SAT_GET_INKEY_RES_RSP);
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    SetSlaveProtocolEventHandler(SATGetInkeyRsp, PRT_MMI_SAT_GET_INKEY_RES_RSP);
#endif

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    SetProtocolEventHandler(SATCallSetupSIM1Ind, PRT_MMI_SAT_CALL_SETUP_IND);
    SetSlaveProtocolEventHandler(SATCallSetupSIM2Ind, PRT_MMI_SAT_CALL_SETUP_IND);
#else
    SetProtocolEventHandler(SATCallSetupInd, PRT_MMI_SAT_CALL_SETUP_IND);
#endif
    SetProtocolEventHandler(SATCallSetupStage1Rsp, PRT_MMI_SAT_CALL_SETUP_STAGE1_RSP);
    SetProtocolEventHandler(SATCallSetupStage2Rsp, PRT_MMI_SAT_CALL_SETUP_STAGE2_RSP);
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    SetSlaveProtocolEventHandler(SATCallSetupStage1Rsp, PRT_MMI_SAT_CALL_SETUP_STAGE1_RSP);
    SetSlaveProtocolEventHandler(SATCallSetupStage2Rsp, PRT_MMI_SAT_CALL_SETUP_STAGE2_RSP);
#endif

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    SetProtocolEventHandler(SATSendSMSSIM1Ind, PRT_MMI_SAT_SEND_SMS_IND);
    SetSlaveProtocolEventHandler(SATSendSMSSIM2Ind, PRT_MMI_SAT_SEND_SMS_IND);
#else
    SetProtocolEventHandler(SATSendSMSInd, PRT_MMI_SAT_SEND_SMS_IND);
#endif
    SetProtocolEventHandler(SATSendSMSStage1Rsp, PRT_MMI_SAT_SEND_SMS_STAGE1_RSP);
    SetProtocolEventHandler(SATSendSMSStage2Rsp, PRT_MMI_SAT_SEND_SMS_STAGE2_RSP);
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    SetSlaveProtocolEventHandler(SATSendSMSStage1Rsp, PRT_MMI_SAT_SEND_SMS_STAGE1_RSP);
    SetSlaveProtocolEventHandler(SATSendSMSStage2Rsp, PRT_MMI_SAT_SEND_SMS_STAGE2_RSP);
#endif

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    SetProtocolEventHandler(SATSendSSSIM1Ind, PRT_MMI_SAT_SEND_SS_IND);
    SetSlaveProtocolEventHandler(SATSendSSSIM2Ind, PRT_MMI_SAT_SEND_SS_IND);
#else
    SetProtocolEventHandler(SATSendSSInd, PRT_MMI_SAT_SEND_SS_IND);
#endif
    SetProtocolEventHandler(SATSendSSStage1Rsp, PRT_MMI_SAT_SEND_SS_STAGE1_RSP);
    SetProtocolEventHandler(SATSendSSStage2Rsp, PRT_MMI_SAT_SEND_SS_STAGE2_RSP);
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    SetSlaveProtocolEventHandler(SATSendSSStage1Rsp, PRT_MMI_SAT_SEND_SS_STAGE1_RSP);
    SetSlaveProtocolEventHandler(SATSendSSStage2Rsp, PRT_MMI_SAT_SEND_SS_STAGE2_RSP);
#endif

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    SetProtocolEventHandler(SATSendUSSDSIM1Ind, PRT_MMI_SAT_SEND_USSD_IND);
    SetSlaveProtocolEventHandler(SATSendUSSDSIM2Ind, PRT_MMI_SAT_SEND_USSD_IND);
#else
    SetProtocolEventHandler(SATSendUSSDInd, PRT_MMI_SAT_SEND_USSD_IND);
#endif
    SetProtocolEventHandler(SATSendUSSDStage1Rsp, PRT_MMI_SAT_SEND_USSD_STAGE1_RSP);
    SetProtocolEventHandler(SATSendUSSDStage2Rsp, PRT_MMI_SAT_SEND_USSD_STAGE2_RSP);
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    SetSlaveProtocolEventHandler(SATSendUSSDStage1Rsp, PRT_MMI_SAT_SEND_USSD_STAGE1_RSP);
    SetSlaveProtocolEventHandler(SATSendUSSDStage2Rsp, PRT_MMI_SAT_SEND_USSD_STAGE2_RSP);
#endif

    SetProtocolEventHandler(SATMMIInfoInd, PRT_MMI_SAT_MMI_INFO_IND);
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    SetSlaveProtocolEventHandler(SATMMIInfoInd, PRT_MMI_SAT_MMI_INFO_IND);
#endif

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    SetProtocolEventHandler(SATPlayToneSIM1Ind, PRT_MMI_SAT_PLAY_TONE_IND);
    SetSlaveProtocolEventHandler(SATPlayToneSIM2Ind, PRT_MMI_SAT_PLAY_TONE_IND);
#else
    SetProtocolEventHandler(SATPlayToneInd, PRT_MMI_SAT_PLAY_TONE_IND);
#endif
    SetProtocolEventHandler(SATPlayToneRsp, PRT_MMI_SAT_PLAY_TONE_RES_RSP);
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    SetSlaveProtocolEventHandler(SATPlayToneRsp, PRT_MMI_SAT_PLAY_TONE_RES_RSP);
#endif

    SetProtocolEventHandler(SATEVDLBrowserTerminationInd, PRT_WAP_MMI_BROWSER_TERMINATION_IND);
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    SetSlaveProtocolEventHandler(SATEVDLBrowserTerminationInd, PRT_WAP_MMI_BROWSER_TERMINATION_IND);
#endif

    SetProtocolEventHandler(SATLangNotifyInd, PRT_MMI_SAT_LANG_NOTIFY_IND);
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    SetSlaveProtocolEventHandler(SATLangNotifyInd, PRT_MMI_SAT_LANG_NOTIFY_IND);
#endif

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    SetProtocolEventHandler(SATLaunchBrowserSIM1Ind, PRT_MMI_SAT_LAUNCH_BROWSER_IND);
    SetSlaveProtocolEventHandler(SATLaunchBrowserSIM2Ind, PRT_MMI_SAT_LAUNCH_BROWSER_IND);
#else
    SetProtocolEventHandler(SATLaunchBrowserInd, PRT_MMI_SAT_LAUNCH_BROWSER_IND);
#endif
#ifdef WAP_SUPPORT
    SetProtocolEventHandler(WAPLaunchBrowserRsp, PRT_WAP_MMI_LAUNCH_BROWSER_RSP);
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    SetSlaveProtocolEventHandler(WAPLaunchBrowserRsp, PRT_WAP_MMI_LAUNCH_BROWSER_RSP);
#endif
#endif
    SetProtocolEventHandler(SATLaunchBrowserRsp, PRT_MMI_SAT_LAUNCH_BROWSER_RES_RSP);
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    SetSlaveProtocolEventHandler(SATLaunchBrowserRsp, PRT_MMI_SAT_LAUNCH_BROWSER_RES_RSP);
#endif

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    SetProtocolEventHandler(SATSendDTMFSIM1Ind, PRT_MMI_SAT_SEND_DTMF_IND);
    SetSlaveProtocolEventHandler(SATSendDTMFSIM2Ind, PRT_MMI_SAT_SEND_DTMF_IND);
#else
    SetProtocolEventHandler(SATSendDTMFInd, PRT_MMI_SAT_SEND_DTMF_IND);
#endif
    SetProtocolEventHandler(SATSendDTMFStage1Rsp, PRT_MMI_SAT_SEND_DTMF_STAGE1_RSP);
    SetProtocolEventHandler(SATSendDTMFStage2Rsp, PRT_MMI_SAT_SEND_DTMF_STAGE2_RSP);
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    SetSlaveProtocolEventHandler(SATSendDTMFStage1Rsp, PRT_MMI_SAT_SEND_DTMF_STAGE1_RSP);
    SetSlaveProtocolEventHandler(SATSendDTMFStage2Rsp, PRT_MMI_SAT_SEND_DTMF_STAGE2_RSP);
#endif

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    SetProtocolEventHandler(SATSIMFileChangeSIM1Ind, PRT_MMI_SAT_SIM_FILE_CHANGE_IND);
    SetSlaveProtocolEventHandler(SATSIMFileChangeSIM2Ind, PRT_MMI_SAT_SIM_FILE_CHANGE_IND);
#else
    SetProtocolEventHandler(SATSIMFileChangeInd, PRT_MMI_SAT_SIM_FILE_CHANGE_IND);
#endif

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    SetProtocolEventHandler(SATSetupIdleDisplaySIM1Ind, PRT_MMI_SAT_SETUP_IDLE_DISPLAY_IND);
    SetSlaveProtocolEventHandler(SATSetupIdleDisplaySIM2Ind, PRT_MMI_SAT_SETUP_IDLE_DISPLAY_IND);
#else
    SetProtocolEventHandler(SATSetupIdleDisplayInd, PRT_MMI_SAT_SETUP_IDLE_DISPLAY_IND);
#endif

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    SetProtocolEventHandler(SATRunATCommandSIM1Ind, PRT_MMI_SAT_RUN_AT_COMMAND_IND);
    SetSlaveProtocolEventHandler(SATRunATCommandSIM2Ind, PRT_MMI_SAT_RUN_AT_COMMAND_IND);
#else
    SetProtocolEventHandler(SATRunATCommandInd, PRT_MMI_SAT_RUN_AT_COMMAND_IND);
#endif

    SetProtocolEventHandler(SATNoFurtherCommandInd, PRT_MMI_SAT_NO_OTHER_CMD_IND);
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    SetSlaveProtocolEventHandler(SATNoFurtherCommandInd, PRT_MMI_SAT_NO_OTHER_CMD_IND);
#endif

#ifdef __SATCE__
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    SetProtocolEventHandler(SATOpenChannelSIM1Ind, MSG_ID_MMI_SAT_OPEN_CHANNEL_IND);
    SetSlaveProtocolEventHandler(SATOpenChannelSIM2Ind, MSG_ID_MMI_SAT_OPEN_CHANNEL_IND);
#else
    SetProtocolEventHandler(SATOpenChannelInd, MSG_ID_MMI_SAT_OPEN_CHANNEL_IND);
#endif
    SetProtocolEventHandler(SATOpenChannelRes, MSG_ID_MMI_SAT_OPEN_CHANNEL_RSP);
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    SetSlaveProtocolEventHandler(SATOpenChannelRes, MSG_ID_MMI_SAT_OPEN_CHANNEL_RSP);
#endif

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    SetProtocolEventHandler(SATCloseChannelSIM1Ind, MSG_ID_MMI_SAT_CLOSE_CHANNEL_IND);
    SetSlaveProtocolEventHandler(SATCloseChannelSIM2Ind, MSG_ID_MMI_SAT_CLOSE_CHANNEL_IND);
#else
    SetProtocolEventHandler(SATCloseChannelInd, MSG_ID_MMI_SAT_CLOSE_CHANNEL_IND);
#endif

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    SetProtocolEventHandler(SATSendDataSIM1Ind, MSG_ID_MMI_SAT_SEND_DATA_IND);
    SetSlaveProtocolEventHandler(SATSendDataSIM2Ind, MSG_ID_MMI_SAT_SEND_DATA_IND);
#else
    SetProtocolEventHandler(SATSendDataInd, MSG_ID_MMI_SAT_SEND_DATA_IND);
#endif

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    SetProtocolEventHandler(SATRecvDataSIM1Ind, MSG_ID_MMI_SAT_RECV_DATA_IND);
    SetSlaveProtocolEventHandler(SATRecvDataSIM2Ind, MSG_ID_MMI_SAT_RECV_DATA_IND);
#else
    SetProtocolEventHandler(SATRecvDataInd, MSG_ID_MMI_SAT_RECV_DATA_IND);
#endif

    SetProtocolEventHandler(SATNotifyMMIInd, MSG_ID_MMI_SAT_NOTIFY_MMI_IND);
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    SetSlaveProtocolEventHandler(SATNotifyMMIInd, MSG_ID_MMI_SAT_NOTIFY_MMI_IND);
#endif
#endif /* __SATCE__ */ 

    gSATContext.getImageStage = (U16) SAT_IMAGE_IDLE_CMD;
    gSATContext.gotStage1Rsp = 1;
    gSATContext.lastSATCmd = SAT_NONE_CMD;

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    gSATDisplayText.CMDfromSIM = SAT_CMD_NONE;
    gSATPlayTone.CMDfromSIM = SAT_CMD_NONE;
    gSATSubMenu.CMDfromSIM = SAT_CMD_NONE;
    gSATFileChange.CMDfromSIM = SAT_CMD_NONE;
    gSATContext.CMDfromSIM = SAT_CMD_NONE;
    gSATContext.satIndex = SAT_CMD_NONE;
#endif

    gSATContext.simFuncPtr[0] = mmi_sat_clear_idle_display_text; /* max 3 callbacks for SIM file changed indication */
    gSATContext.simFuncPtr[1] = mmi_sat_refresh_to_update_imsi;
}


/*****************************************************************************
 * FUNCTION
 *  ExitVariables
 * DESCRIPTION
 *  Reinitialises the global varibales of SAT while
 *  exiting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitVariables(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gSATContext.isInSATMenu = 0;
    gSATMainMenu.selectedMenuItem = 0;
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    gSATMainMenu.selectedMenuItem_2 = 0;
#endif
    ClearIsInSATScreen();
}


/*****************************************************************************
 * FUNCTION
 *  ExitSATToIdle
 * DESCRIPTION
 *  Takes the user back to Idle Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitSATToIdle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (isInCall())
    {
        HangupAllCalls();
    }
    else
    {
        gSATContext.isInSATMenu = 0;
        ClearIsInSATScreen();
        DisplayIdleScreen();
    }
}


#define MMI_SAT_NO_OTHER_CMD
/*****************************************************************************
 * FUNCTION
 *  SATNoFurtherCommandInd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATNoFurtherCommandInd(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    gSATContext.CMDfromSIM = SAT_CMD_NONE;
#endif

    if (!gSATContext.waitTimeExpired
#ifdef __SATCE__
        || gSATContext.lastSATCmd == SAT_OPEN_CHANNEL_CMD
        || gSATContext.lastSATCmd == SAT_CLOSE_CHANNEL_CMD
        || gSATContext.lastSATCmd == SAT_RECEIVE_DATA_CMD
        || gSATContext.lastSATCmd == SAT_SEND_DATA_CMD
#endif /* __SATCE__ */ 
        )
    {
        gSATMainMenu.isSentRsp = 1; /* diamond, 2006/04/06 Avoid to add SAT main menu to history if no furthur command comes in SAT screen more than 1 times */
        SATMessageWaitTimer();
    }
}


#define MMI_SAT_FILE_CHANGE
/*****************************************************************************
 * FUNCTION
 *  SATFileChangePhbCheck
 * DESCRIPTION
 *  
 * PARAMETERS
 *  simChange   [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static pBOOL SATFileChangePhbCheck(mmi_sat_sim_file_change_ind_struct *simChange)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    pBOOL rtn = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (simChange->is_full_changed)
    {
        return MMI_TRUE;
    }

    for (i = 0; i < simChange->num_of_file; i++)
    {
        if (simChange->file_list[i] == FILE_ADN_IDX
            || simChange->file_list[i] == FILE_FDN_IDX
            || simChange->file_list[i] == FILE_LND_IDX
            || simChange->file_list[i] == FILE_SDN_IDX
            || simChange->file_list[i] == FILE_EXT1_IDX
            || simChange->file_list[i] == FILE_EXT2_IDX
            || simChange->file_list[i] == FILE_EXT3_IDX
            || simChange->file_list[i] == FILE_BDN_IDX
            || simChange->file_list[i] == FILE_EXT4_IDX)
        {
            rtn = MMI_TRUE;
            break;
        }
    }

    return rtn;
}


/*****************************************************************************
 * FUNCTION
 *  SATFileChangeSmsCheck
 * DESCRIPTION
 *  
 * PARAMETERS
 *  simChange   [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static pBOOL SATFileChangeSmsCheck(mmi_sat_sim_file_change_ind_struct *simChange)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    pBOOL rtn = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (simChange->is_full_changed)
    {
        return MMI_TRUE;
    }

    for (i = 0; i < simChange->num_of_file; i++)
    {
        if (simChange->file_list[i] == FILE_SMSS_IDX
            || simChange->file_list[i] == FILE_SMSP_IDX
            || simChange->file_list[i] == FILE_SMS_IDX
            || simChange->file_list[i] == FILE_CBMI_IDX
            || simChange->file_list[i] == FILE_CBMID_IDX || simChange->file_list[i] == FILE_CBMIR_IDX
    #ifdef __CPHS__
            || simChange->file_list[i] == FILE_VM_WAIT_IDX || simChange->file_list[i] == FILE_MAILBOX_NUM_IDX
    #endif 
            || simChange->file_list[i] == FILE_ELP_IDX || simChange->file_list[i] == FILE_LP_IDX)
        {
            rtn = MMI_TRUE;
            break;
        }
    }

    return rtn;
}


#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
/*****************************************************************************
 * FUNCTION
 *  SATSIMFileChangeSIM1Ind
 * DESCRIPTION
 *  Protocol Handler for FILE CHANGE IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4-1
 * RETURNS
 *  void
 *****************************************************************************/
void SATSIMFileChangeSIM1Ind(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gSATFileChange.CMDfromSIM == SAT_CMD_SIM2)
    {
        return;
    }
    else
    {
        gSATFileChange.CMDfromSIM = SAT_CMD_SIM1;
        SATSIMFileChangeInd(msgPtr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  SATSIMFileChangeSIM2Ind
 * DESCRIPTION
 *  Protocol Handler for FILE CHANGE IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4-2
 * RETURNS
 *  void
 *****************************************************************************/
void SATSIMFileChangeSIM2Ind(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gSATFileChange.CMDfromSIM == SAT_CMD_SIM1)
    {
        return;
    }
    else
    {
        gSATFileChange.CMDfromSIM = SAT_CMD_SIM2;
        SATSIMFileChangeInd(msgPtr);
    }
}

#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */


/*****************************************************************************
 * FUNCTION
 *  SATSIMFileChangeInd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATSIMFileChangeInd(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    mmi_sat_sim_file_change_ind_struct *simChange;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    simChange = (mmi_sat_sim_file_change_ind_struct*) msgPtr;

    if (simChange->refresh_type == TYPE_SIM_RESET)
    {
    #ifdef __SIM_RESET_BY_SIM__
    	if (!IsInSATScreen())
    	{
            DisplayPopup(
                (U8*) GetString(STR_ID_SIM_REFRESH),
                IMG_GLOBAL_WARNING,
                0,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) WARNING_TONE);
        }
    #else /* __SIM_RESET_BY_SIM__ */
        GoToSATRebootScreen();
    #endif /*__SIM_RESET_BY_SIM__ */
        return;
    }
    /* diamond, 2005/05/31 sim file change notification */
    else
    {
        if (IsInSATScreen())
        {
            gSATContext.waitTimeExpired = 1;
            SATPleaseWaitScreen(STR_ID_SIM_REFRESH, SAT_WAIT_IMAGE_ID);
            mmi_sat_restart_please_wait_timer(SAT_MESSAGE_WAIT_TIMER_DURATION * 2);
        }

        for (i = 0; i < MAX_FILE_CHANGE_NOTIFY_CALLBACK; i++)
        {
            if (gSATContext.simFuncPtr[i] != NULL)
            {
                gSATContext.simFuncPtr[i] (simChange->refresh_type);
            }
        }
    }

    /* diamond, 2006/01/06 sim file change for sms */
    if (SATFileChangeSmsCheck(simChange))
    {
    #if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
        if (gSATFileChange.CMDfromSIM == SAT_CMD_SIM2)
        {
            if (MTPNP_AD_Card2_SMS_Is_Ready())
            {
                mmi_frm_sms_sim_refresh_ind(simChange->refresh_type);
            }
        }
        else
        {
            mmi_frm_sms_sim_refresh_ind(simChange->refresh_type);
        }
    #else /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
        mmi_frm_sms_sim_refresh_ind(simChange->refresh_type);
    #endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
    }

    /* PHB & Call Log */
    if (SATFileChangePhbCheck(simChange))
    {
    #if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
        if (gSATFileChange.CMDfromSIM == SAT_CMD_SIM2)
        {
            if (MTPNP_PFAL_Phb_IsReady())
            {
                MTPNP_PFAL_CHIST_SAT_Handler();
                MTPNP_PFAL_ADN_SAT_Handler(TRUE);
            }
            MTPNP_AD_FDN_Get_STATE();
        }
        else
        {
            if (g_phb_cntx.phb_ready)
            {
                CHISTSatHandler();
                mmi_phb_sat_handler(TRUE);
            }
            SECSETGetFdlBdlModeReq();
        }
    #else /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
        if (g_phb_cntx.phb_ready)
        {
            CHISTSatHandler();
            mmi_phb_sat_handler(TRUE);
        }
        SECSETGetFdlBdlModeReq();
    #endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
    }

    /* single file refresh */
    if (simChange->refresh_type == TYPE_FILE_CHANGE)
    {
        gSATFileChange.number_of_changes = simChange->num_of_file;
        gSATFileChange.file_change_list = OslMalloc(120);
        memcpy(gSATFileChange.file_change_list, simChange->file_list, 120);
        mmi_sat_refresh_next_file();
    }
}


/*****************************************************************************
 * FUNCTION
 *  GoToSATRebootScreen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoToSATRebootScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SAT_WAITSCREEN, NULL, GoToSATRebootScreen, NULL);

    ClearInputEventHandler(MMI_DEVICE_ALL); /* go to reboot now and no input can be accepted*/
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);

    DisplayPopup(
        (U8*) GetString(STR_ID_SIM_REFRESH),
        IMG_GLOBAL_WARNING,
        0,
        UI_POPUP_NOTIFYDURATION_TIME * 2,
        (U8) WARNING_TONE);

    mmi_sat_nw_detach_before_reboot();
    StartTimer(SAT_REFRESH_REBOOT_TIMER, 3000, SATRefreshRebootTimeOut);
}


/*****************************************************************************
 * FUNCTION
 *  SATRefreshRebootTimeOut
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SATRefreshRebootTimeOut(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    if (gSATFileChange.CMDfromSIM == SAT_CMD_SIM2)
    {
        ClearSlaveProtocolEventHandler(MSG_ID_MMI_NW_PWROFF_DETACH_RSP);
    }
    else
    {
        ClearProtocolEventHandler(MSG_ID_MMI_NW_PWROFF_DETACH_RSP);
    }
#else /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
    ClearProtocolEventHandler(MSG_ID_MMI_NW_PWROFF_DETACH_RSP);
#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
    AlmATPowerReset(0, 0);
}


#define MMI_SAT_EXTERN_INTERFACE
/*****************************************************************************
 * FUNCTION
 *  IsInSATScreen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 IsInSATScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (gSATContext.isInSATScreen);
}


/*****************************************************************************
 * FUNCTION
 *  IsInSATCall
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 IsInSATCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (gSATContext.isInSATCall);
}


/*****************************************************************************
 * FUNCTION
 *  SATCallTerminate
 * DESCRIPTION
 *  Called by Call Manage
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SATCallTerminate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gSATContext.isInSATCall)
    {
        gSATContext.isInSATCall = 0;
        if (!gSATCallSetup.isSentRsp)
        {
            if (gSATCallSetup.exitCause == SAT_CALL_DISCONNECT_BEFORE_CONNECT)
            {
                TerminalResponseCallSetup(
                    SAT_USER_CLEAR_DOWN_CALL_BEFORE_CONNECTION_RELEASE,
                    0,
                    gSATCallSetup.cmdDetail);
                RemoveOutgoingIndicationScreen();
            }
            else
            {
                TerminalResponseCallSetup(SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, 0, gSATCallSetup.cmdDetail);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  GetSATIdleText
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U8*
 *****************************************************************************/
U8 *GetSATIdleText(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (gSATContext.idleTextPtr);
}


/*****************************************************************************
 * FUNCTION
 *  GetSATIdleIcon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U8*
 *****************************************************************************/
U8 *GetSATIdleIcon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (gSATContext.idleIconPtr);
}


/*****************************************************************************
 * FUNCTION
 *  GetPostponedSATScreen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  FuncPtr
 *****************************************************************************/
FuncPtr GetPostponedSATScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (gSATContext.postponedSATScreen);
}


/*****************************************************************************
 * FUNCTION
 *  ClearPostponedSATScreen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ClearPostponedSATScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gSATContext.postponedSATScreen = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  GetSATMainMenuAlphaID
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U8*
 *****************************************************************************/
U8 *GetSATMainMenuAlphaID(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (mmi_ucs2strlen((S8*) gSATMainMenu.alphaId) == 0) ? (PU8) get_string(SAT_MENU_STRING_ID) : gSATMainMenu.alphaId;
}


#define MMI_SAT_WAIT_TIMER
/*****************************************************************************
 * FUNCTION
 *  SATMessageWaitTimer
 * DESCRIPTION
 *  Timer CallBack Function called by when the SAT dows not recieve any
 *  command from SIM for 3 secs
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SATMessageWaitTimer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SATStopWaitTimer();

    //PRINT_INFORMATION("[SAT] please wait timer expires: isInSATScreen = %d, isInSATMenu = %d", gSATContext.isInSATScreen, gSATContext.isInSATMenu);

    if (gSATContext.isInSATScreen)
    {
    #ifdef __MMI_CLAMCLOSE_BACK2IDLE__
        if (IsClamClose())
        {
            DisplayIdleScreen();
            return;
        }
    #endif /* __MMI_CLAMCLOSE_BACK2IDLE__ */ 

        if (gSATContext.isInSATMenu)
        {
        #if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
            if (gSATContext.satIndex == SAT_CMD_SIM2)
            {
                gSATContext.historyFuncPtr = GoToSATMainMenu_2;
            }
            else
            {
                gSATContext.historyFuncPtr = GoToSATMainMenu;
            }
        #else /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
            gSATContext.historyFuncPtr = GoToSATMainMenu;
        #endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
            if (isInCall() && !IsInSATCall())
            {
                /* diamond, 2006/05/30 SAT -> call -> SAT -> Terminal Response then go back to call screen not SAT screen */
                if (!IsScreenPresent(SCR_ID_SAT_HISTORY))
                {
                    mmi_frm_add_history_before_cm_marker(SCR_ID_SAT_HISTORY, SATHistoryHandler);
                }
                GoBackHistory();
            }
            else if (IsScreenPresent(SCR_ID_SAT_HISTORY))
            {
                GoBackToHistory(SCR_ID_SAT_HISTORY);
            }
            else
            {
            #if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
                if (gSATContext.satIndex == SAT_CMD_SIM2)
                {
                    GoToSATMainMenu_2();
                }
                else
                {
                    GoToSATMainMenu();
                }
            #else /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
                GoToSATMainMenu();
            #endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
            }
        }
        else
        {
            if (IsScreenPresent(SCR_ID_SAT_HISTORY))
            {
                GoBackToHistory(SCR_ID_SAT_HISTORY);
            }
            else
            {
                ClearIsInSATScreen();
                GoBackHistory();
            }
        }
    }
    else
    {
    #if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
        if (gSATContext.satIndex == SAT_CMD_SIM2)
        {
            gSATContext.historyFuncPtr = GoToSATMainMenu_2;
        }
        else
        {
            gSATContext.historyFuncPtr = GoToSATMainMenu;
        }
    #else /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
        gSATContext.historyFuncPtr = GoToSATMainMenu;
    #endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
        if (!gSATContext.isInSATMenu)
        {
            ClearIsInSATScreen();
            DeleteScreenIfPresent(SCR_ID_SAT_HISTORY);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  SATStopWaitTimer
 * DESCRIPTION
 *  Stops Please Wait Timer, Timer is started when Please
 *  Wait Screen is called
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SATStopWaitTimer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AlmEnableExpiryHandler();
    StopTimer(SAT_MESSAGE_WAIT_TIMER);
#ifndef __MTK_TARGET__
    StopTimer(SAT_REFRESH_REBOOT_TIMER);
    gSATContext.gotStage1Rsp = 1;
#endif
    gSATContext.waitTimeExpired = 1;
}


/*****************************************************************************
 * FUNCTION
 *  SATPleaseWaitScreen
 * DESCRIPTION
 *  Displays Please Wait Screen just sets the variables
 * PARAMETERS
 *  string      [IN]    String to be displayed in Please Wait Screen
 *  image       [IN]    Image to be displayed in Please Wait Screen
 * RETURNS
 *  void
 *****************************************************************************/
void SATPleaseWaitScreen(U16 string, U16 image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gSATContext.waitString = string;
    gSATContext.waitImage = image;
    PleaseWaitActualScreen();
#ifndef __MTK_TARGET__
    StartTimer(SAT_REFRESH_REBOOT_TIMER, 3000, SATMessageWaitTimer); /* diamond, 2006/05/30 Send NO FURTHER CMD to MMI */
#endif
}


/*****************************************************************************
 * FUNCTION
 *  PleaseWaitActualScreen
 * DESCRIPTION
 *  Displays Wait Screen on MMI, Entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PleaseWaitActualScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //PRINT_INFORMATION("[SAT] please wait screen: isInSATScreen = %d", gSATContext.isInSATScreen);

    if (gSATContext.isInSATScreen)
    {
        gSATContext.exitCondition = &gSATContext.waitTimeExpired;
        EntryNewScreen(SCR_ID_SAT_WAITSCREEN, SATGenericExitHandler, NULL, NULL);

        ClearHighlightHandler();
    #ifdef __MMI_SAT_PLEASE_WAIT_ONLY_TEXT__
        ShowCategory151Screen(0, 0, 0, 0, 0, 0, (PU8) GetString(gSATContext.waitString), 0, NULL);
    #else /* __MMI_SAT_PLEASE_WAIT_ONLY_TEXT__ */ 
        /* diamond, 2005/06/15 change screen style to be the same as DISPLAY TEXT if no image is assigned */
        if (gSATContext.waitImage == 0)
        {
            ShowCategory151Screen(0, 0, 0, 0, 0, 0, (PU8) GetString(gSATContext.waitString), 0, NULL);
        }
        else
            /* end, diamond */
        {
            ShowCategory9Screen(gSATContext.waitString, gSATContext.waitImage, NULL);
        }
    #endif /* __MMI_SAT_PLEASE_WAIT_ONLY_TEXT__ */ 

        SetKeyHandler(0, KEY_END, KEY_EVENT_DOWN);
    }
    gSATContext.historyFuncPtr = PleaseWaitActualScreen;
    AlmDisableExpiryHandler();
    StartTimer(SAT_MESSAGE_WAIT_TIMER, SAT_MESSAGE_WAIT_TIMER_DURATION, SATMessageWaitTimer);
    gSATContext.waitTimeExpired = 0;
}


/*****************************************************************************
 * FUNCTION
 *  StartSATTimerNoResponsefromUser
 * DESCRIPTION
 *  Starts No Response Timer and calls the passed
 *  function if no key is pressed in that duration
 * PARAMETERS
 *  FuncPtr     [IN]    To be called on Timer Expiry
 * RETURNS
 *  void
 *****************************************************************************/
void StartSATTimerNoResponsefromUser(FuncPtr FuncPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gSATContext.noResponseFuncPtr = FuncPtr;

#ifdef __USAT__
    if (gSATContext.lastSATCmd == SAT_DISPLAY_TEXT_CMD && gSATDisplayText.duration != 0)
    {
        if (!gSATDisplayText.countdownStarted)
        {
            StartTimer(SAT_TERMINAL_RESP_TIMER, gSATDisplayText.duration, gSATContext.noResponseFuncPtr);
            gSATDisplayText.countdownStarted = 1;
        }
        return;
    }

    if (gSATContext.lastSATCmd == SAT_GET_INKEY && gSATGetInkey.duration != 0)
    {
        if (!gSATGetInkey.countdownStarted)
        {
            StartTimer(SAT_TERMINAL_RESP_TIMER, gSATGetInkey.duration, gSATContext.noResponseFuncPtr);
            gSATGetInkey.countdownStarted = 1;
        }
        return;
    }
#endif /* __USAT__ */ 

    /* diamond, 2005/07/11 duration for DISPLAY TEXT "clear after a delay" case */
    if (gSATContext.lastSATCmd == SAT_DISPLAY_TEXT_CMD && gSATDisplayText.clearTextType == SAT_CLEAR_AFTER_DELAY)
    {
        StartTimer(SAT_TERMINAL_RESP_TIMER, SAT_DISPLAY_TEXT_DELAY_DURATION, gSATContext.noResponseFuncPtr);
        return;
    }
    /* end, diamond */

#ifdef __GEMINI__
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    if (gSATContext.CMDfromSIM == SAT_CMD_SIM2 ||
        gSATDisplayText.CMDfromSIM == SAT_CMD_SIM2 ||
        gSATPlayTone.CMDfromSIM == SAT_CMD_SIM2 ||
        gSATSubMenu.CMDfromSIM == SAT_CMD_SIM2)
    {
        result = is_test_sim(SIM2);
    }
    else
    {
        result = is_test_sim(SIM1);
    }
#else /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
    result = is_test_sim(SIM1);
#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
#else /* __GEMINI__ */
    result = is_test_sim();
#endif /* __GEMINI__ */
    if (result)
    {
        StartTimer(SAT_TERMINAL_RESP_TIMER, 60000, gSATContext.noResponseFuncPtr);
    }
    else
    {
        StartTimer(SAT_TERMINAL_RESP_TIMER, SAT_NO_RESPONSE_TIMER_DURATION, gSATContext.noResponseFuncPtr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  StopSATTimerNoResponsefromUser
 * DESCRIPTION
 *  Stops No Response Timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void StopSATTimerNoResponsefromUser(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(SAT_TERMINAL_RESP_TIMER);
}


/*****************************************************************************
 * FUNCTION
 *  TemporaryStopSATTimerNoResponsefromUser
 * DESCRIPTION
 *  Stops No Response Timer when any key is pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void TemporaryStopSATTimerNoResponsefromUser(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(SAT_TERMINAL_RESP_TIMER);
}


/*****************************************************************************
 * FUNCTION
 *  RestartSATTimerNoResponsefromUser
 * DESCRIPTION
 *  ResStarts No Response Timer when any key is released
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RestartSATTimerNoResponsefromUser(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* diamond, 2005/07/25 SAT timer */
    if (gSATContext.noResponseFuncPtr != NULL)
    {
        /* diamond, 2005/07/11 duration for DISPLAY TEXT "clear after a delay" case */
        if (gSATContext.lastSATCmd == SAT_DISPLAY_TEXT_CMD && gSATDisplayText.clearTextType == SAT_CLEAR_AFTER_DELAY)
        {
            StartTimer(SAT_TERMINAL_RESP_TIMER, SAT_DISPLAY_TEXT_DELAY_DURATION, gSATContext.noResponseFuncPtr);
            return;
        }
        /* end, diamond */

    #ifdef __GEMINI__
    #if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
        if (gSATContext.CMDfromSIM == SAT_CMD_SIM2 ||
            gSATDisplayText.CMDfromSIM == SAT_CMD_SIM2 ||
            gSATPlayTone.CMDfromSIM == SAT_CMD_SIM2 ||
            gSATSubMenu.CMDfromSIM == SAT_CMD_SIM2)
        {
            result = is_test_sim(SIM2);
        }
        else
        {
            result = is_test_sim(SIM1);
        }
    #else /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
        result = is_test_sim(SIM1);
    #endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
    #else /* __GEMINI__ */
        result = is_test_sim();
    #endif /* __GEMINI__ */
        if (result)
        {
            StartTimer(SAT_TERMINAL_RESP_TIMER, 60000, gSATContext.noResponseFuncPtr);
        }
        else
        {
            StartTimer(SAT_TERMINAL_RESP_TIMER, SAT_NO_RESPONSE_TIMER_DURATION, gSATContext.noResponseFuncPtr);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  StartSATTimerHelp
 * DESCRIPTION
 *  Starts Help Timer and calls the passed
 *  function if no key is pressed in that duration
 * PARAMETERS
 *  FuncPtr     [IN]    To be called on Timer Expiry
 * RETURNS
 *  void
 *****************************************************************************/
void StartSATTimerHelp(FuncPtr FuncPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gSATContext.helpFuncPtr = FuncPtr;
    StartTimer(SAT_HELP_TIMER, SAT_HELP_TIMER_DURATION, gSATContext.helpFuncPtr);
}


/*****************************************************************************
 * FUNCTION
 *  StopSATTimerHelp
 * DESCRIPTION
 *  Stops Help Timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void StopSATTimerHelp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(SAT_HELP_TIMER);
}


/*****************************************************************************
 * FUNCTION
 *  TemporaryStopSATTimerHelp
 * DESCRIPTION
 *  Stops Help Timer when any key is pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void TemporaryStopSATTimerHelp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(SAT_HELP_TIMER);
}


/*****************************************************************************
 * FUNCTION
 *  RestartSATTimerHelp
 * DESCRIPTION
 *  Restarts Help Timer when any key is released
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RestartSATTimerHelp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* diamond, 2005/07/25 SAT timer */
    if (gSATContext.helpFuncPtr != NULL)
    {
        StartTimer(SAT_HELP_TIMER, SAT_HELP_TIMER_DURATION, gSATContext.helpFuncPtr);
    }
}


#define MMI_SAT_ICON_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  SATAddIconIDToList
 * DESCRIPTION
 *  
 * PARAMETERS
 *  IconID      [IN]    
 * RETURNS
 *  void
 *****************************************************************************/
void SATAddIconIDToList(U8 IconID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_ICON_SUPPORT; i++)
    {
        if (gSATContext.iconList[i].iconID == IconID)
        {
            return;
        }
        if (gSATContext.iconList[i].iconID == 0)
        {
            gSATContext.iconList[i].iconID = IconID;
            return;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  SATGetIconFromList
 * DESCRIPTION
 *  
 * PARAMETERS
 *  IconID      [IN]    
 * RETURNS
 *  U8*
 *****************************************************************************/
U8 *SATGetIconFromList(U8 IconID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_ICON_SUPPORT; i++)
    {
        if (gSATContext.iconList[i].iconID == IconID && gSATContext.iconList[i].gotFromSIM == MMI_TRUE)
        {
            gSATContext.isCMDIconSupported = (gSATContext.iconList[i].iconAvailable == MMI_TRUE) ? MMI_TRUE : MMI_FALSE;        /* diamond 2005/05/24 icon */
            return (gSATContext.iconList[i].iconData);
        }
        if (gSATContext.iconList[i].iconID == 0)
        {
            return (NULL);
        }
    }
    return (NULL);
}


/*****************************************************************************
 * FUNCTION
 *  SATCheckAllIconGot
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL SATCheckAllIconGot(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_ICON_SUPPORT; i++)
    {
        if (gSATContext.iconList[i].iconID == 0)
        {
            return (MMI_TRUE);
        }

        if (gSATContext.iconList[i].gotFromSIM != MMI_TRUE)
        {
            return (MMI_FALSE);
        }
    }
    return (MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  SATClearAllIcons
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SATClearAllIcons(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_ICON_SUPPORT; i++)
    {
        if (gSATContext.iconList[i].iconID == 0)
        {
            return;
        }
        if (gSATContext.iconList[i].gotFromSIM == MMI_TRUE)
        {
            if (gSATContext.iconList[i].iconData != NULL)
            {
            #ifndef __MMI_SAT_LARGE_ICON_SUPPORT__
                if (gSATContext.iconList[i].iconAvailable == MMI_TRUE)  /* diamond, 2005/06/03 icon */
                {
                    OslMfree(gSATContext.iconList[i].iconData);
                    gSATContext.iconList[i].iconData = NULL;
                }
            #endif /* __MMI_SAT_LARGE_ICON_SUPPORT__ */
                gSATContext.iconList[i].iconData = NULL;
            }
            gSATContext.iconList[i].iconID = 0;
            gSATContext.iconList[i].gotFromSIM = 0;
            gSATContext.iconList[i].iconAvailable = 0;  /* diamond, 2005/06/03 icon */
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  SATGetIconDataToList
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SATGetIconDataToList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_ICON_SUPPORT; i++)
    {
        if (gSATContext.iconList[i].iconID == 0)
        {
            gSATContext.currGetIconIndex = 0;
            SATGetIconCompleteCallBack();
            return;
        }
        if (gSATContext.iconList[i].gotFromSIM == MMI_FALSE)
        {
            gSATContext.currGetIconIndex = i;
            SendImageLenRecordReq(gSATContext.iconList[i].iconID);
            return;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  SATGetIconDataCallBack
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SATGetIconDataCallBack(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 dataSize, totalImageSize, rawBytes, width_height;
    U32 i;   /* diamond, 2006/05/22 Handle the large icon */
    U8 j, bitPerRasterPoint, currBitIndex, bitMask, bitMask1, bitMask2, CLUTIndex;
    PU8 dataPointer, currColorImgByte;
    U16 c_black, c_white, pixData;

#ifdef __MMI_SAT_LARGE_ICON_SUPPORT__
    U32 maxImageSize = 4096;
#else
    U32 maxImageSize = 2048;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gSATContext.iconList[gSATContext.currGetIconIndex].gotFromSIM = MMI_TRUE;

    if (gSATImageRecord.noOfImages && (gSATImageRecord.imageData != NULL))
    {
        width_height = ((gSATImageRecord.imageInst->width & 0xFFF) << 12) | (gSATImageRecord.imageInst->height & 0xFFF);
        totalImageSize = (U32) (gSATImageRecord.imageInst->width * gSATImageRecord.imageInst->height * 2 + 8 /* image header */ + 13 /* bmp header */);

        /* diamond, 2005/05/24, If the icon is too large to allocate memory, the icon will be ignored. */
        gSATContext.iconList[gSATContext.currGetIconIndex].iconData = NULL;

        if (totalImageSize <= maxImageSize && /* the max size of OslMalloc */
            gSATImageRecord.imageInst->width == gSATImageRecord.imageData[0] &&
            gSATImageRecord.imageInst->height == gSATImageRecord.imageData[1])
        {
            gSATContext.iconList[gSATContext.currGetIconIndex].iconAvailable = MMI_TRUE;
            /* end, diamond */
        #ifdef __MMI_SAT_LARGE_ICON_SUPPORT__
            gSATContext.iconList[gSATContext.currGetIconIndex].iconData = (U8*) g_sat_cmd_icon[gSATContext.currGetIconIndex];
        #else
            gSATContext.iconList[gSATContext.currGetIconIndex].iconData = OslMalloc(totalImageSize * sizeof(U8));
        #endif
            memset(gSATContext.iconList[gSATContext.currGetIconIndex].iconData, 0, totalImageSize * sizeof(U8));

            gSATContext.iconList[gSATContext.currGetIconIndex].iconData[0] = 4 /* IMAGE_TYPE_DEVICE_BITMAP */ ;
            gSATContext.iconList[gSATContext.currGetIconIndex].iconData[1] = 1;
            
            /* data size */
            gSATContext.iconList[gSATContext.currGetIconIndex].iconData[2] = (U8) ((totalImageSize - 8 /* image header */) & 0x000000ff);
            gSATContext.iconList[gSATContext.currGetIconIndex].iconData[3] =
                (U8) (((totalImageSize - 8 /* image header */) >> 8) & 0x000000ff);
            gSATContext.iconList[gSATContext.currGetIconIndex].iconData[4] =
                (U8) (((totalImageSize - 8 /* image header */) >> 16) & 0x000000ff);

            /* width & height */
            gSATContext.iconList[gSATContext.currGetIconIndex].iconData[5] = (width_height & 0x000000ff);
            gSATContext.iconList[gSATContext.currGetIconIndex].iconData[6] = (width_height & 0x0000ff00) >> 8;
            gSATContext.iconList[gSATContext.currGetIconIndex].iconData[7] = (width_height & 0x00ff0000) >> 16;
            
            gSATContext.iconList[gSATContext.currGetIconIndex].iconData[8] = gSATImageRecord.imageInst->width;
            gSATContext.iconList[gSATContext.currGetIconIndex].iconData[12] = gSATImageRecord.imageInst->height;
            gSATContext.iconList[gSATContext.currGetIconIndex].iconData[16] = 0x10;
            rawBytes = (U32) (gSATImageRecord.imageInst->width * 2);
            gSATContext.iconList[gSATContext.currGetIconIndex].iconData[17] = (U8) (rawBytes & 0x000000ff);
            gSATContext.iconList[gSATContext.currGetIconIndex].iconData[18] = (U8) ((rawBytes >> 8) & 0x000000ff);

            dataPointer = gSATContext.iconList[gSATContext.currGetIconIndex].iconData + 8 /* image header */ + 13 /* bmp header */;

            dataSize = (U32) gSATImageRecord.imageInst->width * (U32) gSATImageRecord.imageInst->height;

            if (gSATImageRecord.imageInst->coding == SAT_BASIC_IMAGE)
            {
                c_white = gdi_act_color_from_rgb(255, 255, 255, 255);   /* GDI_RGB_TO_BUFFER_FORMAT(255,255,255); */
                c_black = gdi_act_color_from_rgb(255, 0, 0, 0); /* GDI_RGB_TO_BUFFER_FORMAT(0,0,0); */
                for (i = 0; i < dataSize; i++)
                {
                    pixData = (*(gSATImageRecord.imageData + 2 + i / 8) >> (7 - (i % 8))) & 0x01 ? c_black : c_white;
                    *(dataPointer + 2 * i) = (U8) (pixData & 0x00ff);
                    *(dataPointer + 2 * i + 1) = (U8) ((pixData >> 8) & 0x00ff);
                }
            }
            else if (gSATImageRecord.imageInst->coding == SAT_COLOR_IMAGE || gSATImageRecord.imageInst->coding == SAT_COLOR_IMAGE_TRANSPARENCY)
            {
                bitPerRasterPoint = (U8) * (gSATImageRecord.imageData + 2);
                currBitIndex = 0;
                currColorImgByte = gSATImageRecord.imageData + 6;
                bitMask = 0x01;
                for (i = 0; i < bitPerRasterPoint; i++)
                {
                    bitMask = 2 * bitMask;
                }
                bitMask = bitMask - 1;

                for (i = 0; i < dataSize; i++)
                {
                    if ((currBitIndex + bitPerRasterPoint) < 8)
                    {
                        CLUTIndex = ((*currColorImgByte) >> (8 - currBitIndex - bitPerRasterPoint)) & bitMask;
                        currBitIndex = currBitIndex + bitPerRasterPoint;
                    }
                    else
                    {
                        bitMask1 = 0x01;
                        for (j = 0; j < 8 - currBitIndex; j++)
                        {
                            bitMask1 = 2 * bitMask1;
                        }
                        bitMask1 = bitMask1 - 1;

                        if ((8 - bitPerRasterPoint - currBitIndex) == 0)
                        {
                            CLUTIndex = (*currColorImgByte) & bitMask1;
                        }
                        else
                        {
                            bitMask2 = 0x01;
                            for (j = 0; j < bitPerRasterPoint + currBitIndex - 8; j++)
                            {
                                bitMask2 = 2 * bitMask2;
                            }
                            bitMask2 = bitMask2 - 1;
                            CLUTIndex = ((*currColorImgByte) & bitMask1) +
                                (((*currColorImgByte + 1) >> (8 - (bitPerRasterPoint + currBitIndex - 8))) & bitMask2);
                        }
                        currColorImgByte++;
                        currBitIndex = (currBitIndex + bitPerRasterPoint) % 8;
                    }

                    if (gSATImageRecord.imageInst->coding == SAT_COLOR_IMAGE_TRANSPARENCY && CLUTIndex == gSATImageRecord.noOfCLUT - 1)
                    {
                        pixData = DEVICE_BMP_TRANSPARENT_COLOR_16;
                    }
                    else
                    {
                        pixData = gdi_act_color_from_rgb(
                                255,
                                gSATImageRecord.CLUTData[CLUTIndex].red,
                                gSATImageRecord.CLUTData[CLUTIndex].green,
                                gSATImageRecord.CLUTData[CLUTIndex].blue);
                    }

                    *(dataPointer + 2 * i) = (U8) (pixData & 0x00ff);
                    *(dataPointer + 2 * i + 1) = (U8) ((pixData >> 8) & 0x00ff);
                }
            }
        }
        /* diamond, 2005/05/24 icon */
        else
        {
            gSATContext.iconList[gSATContext.currGetIconIndex].iconAvailable = MMI_FALSE;
            gSATContext.iconList[gSATContext.currGetIconIndex].iconData = NULL; /* (PU8)GetImage(IMG_GLOBAL_DEFAULT); */
        }
        /* end, diamond */
    }
    else
    {
        /* diamond, 2006/05/22 Prevent from getting icon image unsuccessfully */
        gSATContext.iconList[gSATContext.currGetIconIndex].iconAvailable = MMI_FALSE;
        gSATContext.iconList[gSATContext.currGetIconIndex].iconData = NULL;
    }

    gSATImageRecord.iconId = 0;
    gSATImageRecord.noOfImages = 0;
    gSATImageRecord.noOfCLUT = 0;
    gSATImageRecord.locOfCLUT = 0;
    if (gSATImageRecord.imageInst != NULL)
    {
        OslMfree(gSATImageRecord.imageInst);
        gSATImageRecord.imageInst = NULL;
    }
    if (gSATImageRecord.imageData != NULL)
    {
        OslMfree(gSATImageRecord.imageData);
        gSATImageRecord.imageData = NULL;
    }
    if (gSATImageRecord.CLUTData != NULL)
    {
        OslMfree(gSATImageRecord.CLUTData);
        gSATImageRecord.CLUTData = NULL;
    }
    SATGetIconDataToList();
}


#define MMI_SAT_SETUP_MENU
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
/*****************************************************************************
 * FUNCTION
 *  SendTerminalResponseSetupMenuEx
 * DESCRIPTION
 *  Sends SETUP MENU REQ to L4 or L4_2 by destId
 * PARAMETERS
 *  destId      [IN]    L4/L4_2
 *  res         [IN]    Response type
 *  cmdDetail   [IN]    Cmd detail to be sent
 * RETURNS
 *  void
 *****************************************************************************/
void SendTerminalResponseSetupMenuEx(U8 destId, U8 res, U8* cmdDetail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    mmi_sat_setup_menu_res_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message = allocate_ilm(MOD_MMI);
    Message->oslSrcId = MOD_MMI;
    Message->oslDestId = destId;
    Message->oslMsgId = PRT_MMI_SAT_SETUP_MENU_RES_REQ;
    dataPtr = (mmi_sat_setup_menu_res_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_setup_menu_res_req_struct));
    dataPtr->res = res;
    memcpy(dataPtr->cmd_detail, (void*)cmdDetail, 5 * sizeof(U8));
    Message->oslDataPtr = (oslParaType*) dataPtr;
    Message->oslPeerBuffPtr = NULL;
    Message->sap_id = INVALID_SAP;
    msg_send_ext_queue(Message);
}


/*****************************************************************************
 * FUNCTION
 *  SATSetupMenuSIM1Ind
 * DESCRIPTION
 *  Protocol Handler for SETUP MENU IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4-1
 * RETURNS
 *  void
 *****************************************************************************/
void SATSetupMenuSIM1Ind(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_setup_menu_ind_struct *setupMenu;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setupMenu = (mmi_sat_setup_menu_ind_struct*) msgPtr;

    /*
    if (gSATContext.CMDfromSIM == SAT_CMD_SIM2)
    {
        SendTerminalResponseSetupMenuEx(MOD_L4C, SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, setupMenu->cmd_detail);
    }
    else
    */
    {
        gSATContext.CMDfromSIM = SAT_CMD_SIM1;
        SATSetupMenuInd(msgPtr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  SATSetupMenuSIM2Ind
 * DESCRIPTION
 *  Protocol Handler for SETUP MENU IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4-2
 * RETURNS
 *  void
 *****************************************************************************/
void SATSetupMenuSIM2Ind(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_setup_menu_ind_struct *setupMenu;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setupMenu = (mmi_sat_setup_menu_ind_struct*) msgPtr;

    /*
    if (gSATContext.CMDfromSIM == SAT_CMD_SIM1)
    {
        SendTerminalResponseSetupMenuEx(MOD_L4C_2, SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, setupMenu->cmd_detail);
    }
    else
    */
    {
        gSATContext.CMDfromSIM = SAT_CMD_SIM2;
        SATSetupMenuInd_2(msgPtr);
    }
}

#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */


/*****************************************************************************
 * FUNCTION
 *  SATSetupMenuInd
 * DESCRIPTION
 *  Protocol Handler for SETUP MENU IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATSetupMenuInd(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U8 *tempDataPtr;
    SATMENUITEM *menuItem;
    mmi_sat_setup_menu_ind_struct *setupMenu;
    U16 convertedLen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setupMenu = (mmi_sat_setup_menu_ind_struct*) msgPtr;

    if (gSATContext.isSATPresent)
    {
        FreeMainMenu(&gSATMainMenu);
    }

    /* diamond, 2005/08/28 record the last selected item for backward move to SAT main menu */
    gSATMainMenu.selectedMenuItem = 0;

    memcpy(gSATMainMenu.cmdDetail, setupMenu->cmd_detail, 5 * sizeof(U8));

    gSATMainMenu.isHelpInfoAvailable = setupMenu->is_help_info_available;
    gSATMainMenu.numOfItem = setupMenu->num_of_item;

    gSATMainMenu.noItemIconIdList = setupMenu->no_item_icon_id_list;
    gSATMainMenu.itemIconListAttr = setupMenu->item_icon_list_attr;

#ifdef __GEMINI__
    if (is_test_sim(0))
#else
    if (is_test_sim())
#endif
    {
        gSATMainMenu.noNextActionIndList = setupMenu->no_next_action_ind_list;
    }
    else
    {
        gSATMainMenu.noNextActionIndList = 0;
    }

    gSATMainMenu.isIconAvailable = setupMenu->is_icon_available;
    if (gSATMainMenu.isIconAvailable)
    {
        gSATMainMenu.IconID = setupMenu->icon_info.icon_id;
        gSATMainMenu.iconAttr = setupMenu->icon_info.icon_attr;
    }

    gSATMainMenu.dcsOfAlphaId = setupMenu->dcs_of_alpha_id;
    /* diamond, 2006/05/22 Prevent from getting icon image unsuccessfully */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    {
        gSATMainMenu.alphaIdLen = setupMenu->no_alpha_id;
        gSATMainMenu.alphaId = CovertStringForPlatform(
                                setupMenu->alpha_id,
                                gSATMainMenu.alphaIdLen,
                                gSATMainMenu.dcsOfAlphaId,
                                &gSATMainMenu.alphaIdLen);
    }

#ifdef __USAT__
    gSATMainMenu.noTextAttribute = setupMenu->no_text_attribute;
    if (gSATMainMenu.noTextAttribute != 0)
    {
        gSATMainMenu.textFormatting = OslMalloc(gSATMainMenu.noTextAttribute * 4);
        memcpy(gSATMainMenu.textFormatting, setupMenu->text_formatting, gSATMainMenu.noTextAttribute * 4);
    }
#endif /* __USAT__ */ 

    if (gSATMainMenu.numOfItem == 0)
    {
        SendTerminalResponseSetupMenu(SAT_CMD_PERFORMED_SUCCESSFULLY, gSATMainMenu.cmdDetail);
        FreeMainMenu(&gSATMainMenu);
        gSATContext.isSATPresent = 0;
        if (gSATContext.isInSATMenu)
        {
            SATStopWaitTimer();
            DeleteScreenIfPresent(SCR_ID_SAT_HISTORY);
            if (GetExitScrnID() == SCR_ID_SAT_HISTORY)
            {
                ClearExitHandler();
            }
            GoToSATMainMenu();
        }
        return;
    }

    if (gSATMainMenu.numOfItem > 0)
    {
        gSATMainMenu.menuItems = OslMalloc(gSATMainMenu.numOfItem * sizeof(SATMENUITEM));
        memset(gSATMainMenu.menuItems, 0, gSATMainMenu.numOfItem * sizeof(SATMENUITEM));

        menuItem = gSATMainMenu.menuItems;
        tempDataPtr = setupMenu->item_data;
        for (i = 0; i < gSATMainMenu.numOfItem; i++, menuItem++)
        {
            menuItem->itemLen = (U16) (*(tempDataPtr + 1));
            tempDataPtr += 2;
            menuItem->itemId = *tempDataPtr++;
            menuItem->itemDcs = *tempDataPtr++;
            if (menuItem->itemLen != 0)
            {
                menuItem->itemData = CovertStringForPlatform(tempDataPtr, menuItem->itemLen, menuItem->itemDcs, &convertedLen);
                tempDataPtr += menuItem->itemLen;
                menuItem->itemLen = convertedLen;
            }
            else
            {
                /* diamond, 2006/03/19 Keep the menu item if its content is nothing */
                menuItem->itemData = NULL;
                menuItem->itemLen = 0;
            }

            if (gSATMainMenu.noItemIconIdList)
                menuItem->IconID = *(setupMenu->item_icon_id_list + i);
    
            /* diamond, 2006/05/22 Prevent from getting icon image unsuccessfully */
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif

            if (gSATMainMenu.noNextActionIndList)
                menuItem->nextAction = setupMenu->next_action_ind_list[i];

        #ifdef __USAT__
            if (setupMenu->no_item_attribute)
            {
                memcpy(menuItem->itemTextFormatting, setupMenu->item_formatting + 4 * i, 4);
            }
            else
            {
                memset(menuItem->itemTextFormatting, 0, 4);
            }
        #endif /* __USAT__ */ 
        }
    }

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    SendTerminalResponseSetupMenuEx(MOD_L4C, SAT_CMD_PERFORMED_SUCCESSFULLY, gSATMainMenu.cmdDetail);
#else
    SendTerminalResponseSetupMenu(SAT_CMD_PERFORMED_SUCCESSFULLY, gSATMainMenu.cmdDetail);
#endif
    gSATContext.isSATPresent = 1;
}


#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
/*****************************************************************************
 * FUNCTION
 *  SATSetupMenuInd_2
 * DESCRIPTION
 *  Protocol Handler for SETUP MENU IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATSetupMenuInd_2(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U8 *tempDataPtr;
    SATMENUITEM *menuItem;
    mmi_sat_setup_menu_ind_struct *setupMenu;
    U16 convertedLen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setupMenu = (mmi_sat_setup_menu_ind_struct*) msgPtr;

    if (gSATContext.isSATPresent_2)
    {
        FreeMainMenu_2(&gSATMainMenu);
    }

    /* diamond, 2005/08/28 record the last selected item for backward move to SAT main menu */
    gSATMainMenu.selectedMenuItem_2 = 0;

    memcpy(gSATMainMenu.cmdDetail_2, setupMenu->cmd_detail, 5 * sizeof(U8));

    gSATMainMenu.isHelpInfoAvailable_2 = setupMenu->is_help_info_available;
    gSATMainMenu.numOfItem_2 = setupMenu->num_of_item;

    gSATMainMenu.noItemIconIdList_2 = setupMenu->no_item_icon_id_list;
    gSATMainMenu.itemIconListAttr_2 = setupMenu->item_icon_list_attr;

#ifdef __GEMINI__
    if (is_test_sim(0))
#else
    if (is_test_sim())
#endif
    {
        gSATMainMenu.noNextActionIndList_2 = setupMenu->no_next_action_ind_list;
    }
    else
    {
        gSATMainMenu.noNextActionIndList_2 = 0;
    }

    gSATMainMenu.isIconAvailable_2 = setupMenu->is_icon_available;
    if (gSATMainMenu.isIconAvailable_2)
    {
        gSATMainMenu.IconID_2 = setupMenu->icon_info.icon_id;
        gSATMainMenu.iconAttr_2 = setupMenu->icon_info.icon_attr;
    }

    gSATMainMenu.dcsOfAlphaId = setupMenu->dcs_of_alpha_id;
    /* diamond, 2006/05/22 Prevent from getting icon image unsuccessfully */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    {
        gSATMainMenu.alphaIdLen = setupMenu->no_alpha_id;
        gSATMainMenu.alphaId_2 = CovertStringForPlatform(
                                setupMenu->alpha_id,
                                gSATMainMenu.alphaIdLen,
                                gSATMainMenu.dcsOfAlphaId,
                                &gSATMainMenu.alphaIdLen);
    }

#ifdef __USAT__
    gSATMainMenu.noTextAttribute = setupMenu->no_text_attribute;
    if (gSATMainMenu.noTextAttribute != 0)
    {
        gSATMainMenu.textFormatting = OslMalloc(gSATMainMenu.noTextAttribute * 4);
        memcpy(gSATMainMenu.textFormatting, setupMenu->text_formatting, gSATMainMenu.noTextAttribute * 4);
    }
#endif /* __USAT__ */ 

    if (gSATMainMenu.numOfItem_2 == 0)
    {
        SendTerminalResponseSetupMenu(SAT_CMD_PERFORMED_SUCCESSFULLY, gSATMainMenu.cmdDetail_2);
        FreeMainMenu_2(&gSATMainMenu);
        gSATContext.isSATPresent_2 = 0;
        if (gSATContext.isInSATMenu)
        {
            SATStopWaitTimer();
            DeleteScreenIfPresent(SCR_ID_SAT_HISTORY);
            if (GetExitScrnID() == SCR_ID_SAT_HISTORY)
            {
                ClearExitHandler();
            }
            GoToSATMainMenu_2();
        }
        return;
    }

    if (gSATMainMenu.numOfItem_2 > 0)
    {
        gSATMainMenu.menuItems_2 = OslMalloc(gSATMainMenu.numOfItem_2 * sizeof(SATMENUITEM));
        memset(gSATMainMenu.menuItems_2, 0, gSATMainMenu.numOfItem_2 * sizeof(SATMENUITEM));

        menuItem = gSATMainMenu.menuItems_2;
        tempDataPtr = setupMenu->item_data;
        for (i = 0; i < gSATMainMenu.numOfItem_2; i++, menuItem++)
        {
            menuItem->itemLen = (U16) (*(tempDataPtr + 1));
            tempDataPtr += 2;
            menuItem->itemId = *tempDataPtr++;
            menuItem->itemDcs = *tempDataPtr++;
            if (menuItem->itemLen != 0)
            {
                menuItem->itemData = CovertStringForPlatform(tempDataPtr, menuItem->itemLen, menuItem->itemDcs, &convertedLen);
                tempDataPtr += menuItem->itemLen;
                menuItem->itemLen = convertedLen;
            }
            else
            {
                /* diamond, 2006/03/19 Keep the menu item if its content is nothing */
                menuItem->itemData = NULL;
                menuItem->itemLen = 0;
            }

            if (gSATMainMenu.noItemIconIdList_2)
                menuItem->IconID = *(setupMenu->item_icon_id_list + i);
    
            /* diamond, 2006/05/22 Prevent from getting icon image unsuccessfully */
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif

            if (gSATMainMenu.noNextActionIndList_2)
                menuItem->nextAction = setupMenu->next_action_ind_list[i];

        #ifdef __USAT__
            if (setupMenu->no_item_attribute)
            {
                memcpy(menuItem->itemTextFormatting, setupMenu->item_formatting + 4 * i, 4);
            }
            else
            {
                memset(menuItem->itemTextFormatting, 0, 4);
            }
        #endif /* __USAT__ */ 
        }
    }

    SendTerminalResponseSetupMenuEx(MOD_L4C_2, SAT_CMD_PERFORMED_SUCCESSFULLY, gSATMainMenu.cmdDetail_2);
    gSATContext.isSATPresent_2 = 1;
}

#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */


/*****************************************************************************
 * FUNCTION
 *  SendTerminalResponseSetupMenu
 * DESCRIPTION
 *  Sends SETUP MENU REQ to L4
 * PARAMETERS
 *  res         [IN]    Response type
 *  cmdDetail   [IN]    Cmd detail to be sent
 * RETURNS
 *  void
 *****************************************************************************/
void SendTerminalResponseSetupMenu(U8 res, U8 *cmdDetail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    mmi_sat_setup_menu_res_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message = ALLOCATE_ITM(MOD_MMI);
    Message->oslSrcId = MOD_MMI;
    Message->oslMsgId = PRT_MMI_SAT_SETUP_MENU_RES_REQ;
    dataPtr = (mmi_sat_setup_menu_res_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_setup_menu_res_req_struct));
    memcpy(dataPtr->cmd_detail, (void*)cmdDetail, 5 * sizeof(U8));
    dataPtr->res = res;
    Message->oslDataPtr = (oslParaType*) dataPtr;
    Message->oslPeerBuffPtr = NULL;
    SEND_MSG(Message);
    gSATContext.lastSATCmd = SAT_NONE_CMD;

    if (gSATContext.isInSATMenu)
    {
        SATPleaseWaitScreen(SAT_WAIT_STRING_ID, SAT_WAIT_IMAGE_ID);
    }
}


/*****************************************************************************
 * FUNCTION
 *  SATSetupMenuRsp
 * DESCRIPTION
 *  Protocol Handler for SETUP MENU RES
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATSetupMenuRsp(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_setup_menu_res_rsp_struct *setupMenuRes;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setupMenuRes = (mmi_sat_setup_menu_res_rsp_struct*) msgPtr;

    if (setupMenuRes->result == MMI_TRUE)
    {
        if (gSATContext.isInSATMenu)
        {
            SATStopWaitTimer();
            DeleteScreenIfPresent(SCR_ID_SAT_HISTORY);
            if (GetExitScrnID() == SCR_ID_SAT_HISTORY)
            {
                ClearExitHandler();
            }
        #if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
            if (gSATContext.satIndex == SAT_CMD_SIM2)
            {
                GoToSATMainMenu_2();
            }
            else
            {
                GoToSATMainMenu();
            }
        #else /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
            GoToSATMainMenu();
        #endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
        }

    #ifdef __MMI_OP01_MENU_9MATRIX__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #else /* __MMI_OP01_MENU_9MATRIX__ */
        if (GetActiveScreenId() == SERVICES_MAIN_MENU_SCREEN_ID)
        {
            GoToServicesMenu();
            DeleteScreenIfPresent(SERVICES_MAIN_MENU_SCREEN_ID);
        }
    #endif /* __MMI_OP01_MENU_9MATRIX__ */
    }
}


/*****************************************************************************
 * FUNCTION
 *  SimBusyPleaseWait
 * DESCRIPTION
 *  Display SIM busy screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SimBusyPleaseWait(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup(
        (U8*) GetString(SAT_WAIT_STRING_ID),
        IMG_GLOBAL_WARNING,
        0,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) WARNING_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  GoToSATMainMenu
 * DESCRIPTION
 *  Displays SAT Main Menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoToSATMainMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *listItems[64];
    U8 *listItemsIcons[64];
    U8 *listNextAction[64];
    U8 *titleText;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    gSATContext.satIndex = SAT_CMD_SIM1;
#endif
    if ((MTPNP_AD_Get_Status() != MTPNP_AD_CARD1) &&
        (MTPNP_AD_Get_Status() != MTPNP_AD_DUALCARD))
    {
        DisplayPopup(
            (PU8) GetString(SERVICES_NOT_PROVIDED_STRING_ID),
            IMG_GLOBAL_WARNING,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        return;
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */

    memset(listItems, 0, sizeof(listItems));
    memset(listItemsIcons, 0, sizeof(listItemsIcons));
    memset(listNextAction, 0, sizeof(listNextAction));

    if (gSATMainMenu.isIconAvailable)
    {
        SATAddIconIDToList(gSATMainMenu.IconID);
    }

    for (i = 0; i < gSATMainMenu.noItemIconIdList; i++)
    {
        SATAddIconIDToList(gSATMainMenu.menuItems[i].IconID);
    }

    if (gSATMainMenu.isIconAvailable || gSATMainMenu.noItemIconIdList)
    {
        if (!SATCheckAllIconGot())
        {
            SATGetIconCompleteCallBack = GoToSATMainMenu;
            SATGetIconDataToList();
            ClearInputEventHandler(MMI_DEVICE_ALL);
            return;
        }
    }

    for (i = 0; i < gSATMainMenu.numOfItem; i++)
    {
        listItems[i] = gSATMainMenu.menuItems[i].itemData;
        if (gSATMainMenu.noItemIconIdList)
        {
            listItemsIcons[i] = SATGetIconFromList(gSATMainMenu.menuItems[i].IconID);
        }
        if (gSATMainMenu.noNextActionIndList)
        {
            listNextAction[i] = SATReturnNextAction(gSATMainMenu.menuItems[i].nextAction);
        }

        /* diamond, 2006/05/22 Prevent from getting icon image unsuccessfully */
        if (gSATMainMenu.noItemIconIdList != 0 && gSATMainMenu.itemIconListAttr == SAT_ICON_SELF_EX &&
            listItemsIcons[i] != NULL)
        {
            listItems[i] = NULL;
        }
    }

    if (gSATMainMenu.isIconAvailable && gSATMainMenu.iconAttr == SAT_ICON_SELF_EX &&
        SATGetIconFromList(gSATMainMenu.IconID) != NULL)
    {
        titleText = NULL;
    }
    else
    {
        titleText = (mmi_ucs2strlen((S8*) gSATMainMenu.alphaId) == 0) ? (PU8) get_string(SAT_MENU_STRING_ID) : gSATMainMenu.alphaId;
    }

    if (!gSATContext.isSATPresent)
    {
        DeleteScreenIfPresent(SCR_ID_SAT_MAINMENU);
        ExitSATMainMenu();
        return;
    }

    gSATContext.exitCondition = &gSATMainMenu.isSentRsp;
    EntryNewScreen(SCR_ID_SAT_MAINMENU, SATGenericExitHandler, NULL, NULL);

    SetIsInSATScreen();
    gSATContext.historyFuncPtr = GoToSATMainMenu;
    gSATMainMenu.isSentRsp = 0;

    RegisterHighlightHandler(SATMenuIndex);

    ShowCategory174Screen(
        titleText,
        SATGetIconFromList(gSATMainMenu.IconID),
        (PU8) GetString(STR_GLOBAL_OK),
        (PU8) GetImage(IMG_GLOBAL_OK),
        (PU8) GetString(STR_GLOBAL_BACK),
        (PU8) GetImage(IMG_GLOBAL_BACK),
        gSATMainMenu.numOfItem,
        listItems,
        listItemsIcons,
        listNextAction,
        0,
        gSATMainMenu.selectedMenuItem,
        gSATContext.guiBufferPointer);

    SATCompletePreviousTransaction();

    SetKeyHandler(ExitSATToIdle, KEY_END, KEY_EVENT_DOWN);

    if (gSATMainMenu.isHelpInfoAvailable)
    {
        SetKeyHandler(EnvelopeSetupMenuHelp, KEY_SEND, KEY_EVENT_UP);
    }

    if (gSATContext.gotStage1Rsp)
    {
        SetLeftSoftkeyFunction(EnvelopeSetupMenuOK, KEY_EVENT_UP);
        SetRightSoftkeyFunction(ExitSATMainMenu, KEY_EVENT_UP);
        SetKeyHandler(EnvelopeSetupMenuOK, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(ExitSATMainMenu, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {
        SetLeftSoftkeyFunction(SimBusyPleaseWait, KEY_EVENT_UP);
        SetRightSoftkeyFunction(ExitSATMainMenu, KEY_EVENT_UP);
        SetKeyHandler(SimBusyPleaseWait, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(ExitSATMainMenu, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }

    gSATContext.isInSATMenu = 1;
}


#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
/*****************************************************************************
 * FUNCTION
 *  GoToSATMainMenu_2
 * DESCRIPTION
 *  Displays SAT Main Menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoToSATMainMenu_2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *listItems[64];
    U8 *listItemsIcons[64];
    U8 *listNextAction[64];
    U8 *titleText;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    gSATContext.satIndex = SAT_CMD_SIM2;
#endif
    if ((MTPNP_AD_Get_Status() != MTPNP_AD_CARD2) &&
        (MTPNP_AD_Get_Status() != MTPNP_AD_DUALCARD))
    {
        DisplayPopup(
            (PU8) GetString(SERVICES_NOT_PROVIDED_STRING_ID),
            IMG_GLOBAL_WARNING,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        return;
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */

    memset(listItems, 0, sizeof(listItems));
    memset(listItemsIcons, 0, sizeof(listItemsIcons));
    memset(listNextAction, 0, sizeof(listNextAction));

    if (gSATMainMenu.isIconAvailable_2)
    {
        SATAddIconIDToList(gSATMainMenu.IconID_2);
    }

    for (i = 0; i < gSATMainMenu.noItemIconIdList_2; i++)
    {
        SATAddIconIDToList(gSATMainMenu.menuItems_2[i].IconID);
    }

    if (gSATMainMenu.isIconAvailable_2 || gSATMainMenu.noItemIconIdList_2)
    {
        if (!SATCheckAllIconGot())
        {
            SATGetIconCompleteCallBack = GoToSATMainMenu_2;
            SATGetIconDataToList();
            ClearInputEventHandler(MMI_DEVICE_ALL);
            return;
        }
    }

    for (i = 0; i < gSATMainMenu.numOfItem_2; i++)
    {
        listItems[i] = gSATMainMenu.menuItems_2[i].itemData;
        if (gSATMainMenu.noItemIconIdList_2)
        {
            listItemsIcons[i] = SATGetIconFromList(gSATMainMenu.menuItems_2[i].IconID);
        }
        if (gSATMainMenu.noNextActionIndList_2)
        {
            listNextAction[i] = SATReturnNextAction(gSATMainMenu.menuItems_2[i].nextAction);
        }

        /* diamond, 2006/05/22 Prevent from getting icon image unsuccessfully */
        if (gSATMainMenu.noItemIconIdList_2 != 0 && gSATMainMenu.itemIconListAttr_2 == SAT_ICON_SELF_EX &&
            listItemsIcons[i] != NULL)
        {
            listItems[i] = NULL;
        }
    }

    if (gSATMainMenu.isIconAvailable_2 && gSATMainMenu.iconAttr_2 == SAT_ICON_SELF_EX &&
        SATGetIconFromList(gSATMainMenu.IconID_2) != NULL)
    {
        titleText = NULL;
    }
    else
    {
        titleText = (mmi_ucs2strlen((S8*) gSATMainMenu.alphaId_2) == 0) ? (PU8) get_string(SAT_MENU_STRING_ID) : gSATMainMenu.alphaId_2;
    }

    if (!gSATContext.isSATPresent_2)
    {
        DeleteScreenIfPresent(SCR_ID_SAT_MAINMENU);
        ExitSATMainMenu();
        return;
    }

    gSATContext.exitCondition = &gSATMainMenu.isSentRsp;
    EntryNewScreen(SCR_ID_SAT_MAINMENU, SATGenericExitHandler, NULL, NULL);

    SetIsInSATScreen();
    gSATContext.historyFuncPtr = GoToSATMainMenu_2;
    gSATMainMenu.isSentRsp = 0;

    RegisterHighlightHandler(SATMenuIndex_2);

    ShowCategory174Screen(
        titleText,
        SATGetIconFromList(gSATMainMenu.IconID_2),
        (PU8) GetString(STR_GLOBAL_OK),
        (PU8) GetImage(IMG_GLOBAL_OK),
        (PU8) GetString(STR_GLOBAL_BACK),
        (PU8) GetImage(IMG_GLOBAL_BACK),
        gSATMainMenu.numOfItem_2,
        listItems,
        listItemsIcons,
        listNextAction,
        0,
        gSATMainMenu.selectedMenuItem_2,
        gSATContext.guiBufferPointer);

    SATCompletePreviousTransaction();

    SetKeyHandler(ExitSATToIdle, KEY_END, KEY_EVENT_DOWN);

    if (gSATMainMenu.isHelpInfoAvailable_2)
    {
        SetKeyHandler(EnvelopeSetupMenuHelp_2, KEY_SEND, KEY_EVENT_UP);
    }

    if (gSATContext.gotStage1Rsp)
    {
        SetLeftSoftkeyFunction(EnvelopeSetupMenuOK_2, KEY_EVENT_UP);
        SetRightSoftkeyFunction(ExitSATMainMenu, KEY_EVENT_UP);
        SetKeyHandler(EnvelopeSetupMenuOK_2, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(ExitSATMainMenu, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {
        SetLeftSoftkeyFunction(SimBusyPleaseWait, KEY_EVENT_UP);
        SetRightSoftkeyFunction(ExitSATMainMenu, KEY_EVENT_UP);
        SetKeyHandler(SimBusyPleaseWait, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(ExitSATMainMenu, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }

    gSATContext.isInSATMenu = 1;
}

#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */


/*****************************************************************************
 * FUNCTION
 *  SATReturnNextAction
 * DESCRIPTION
 *  SAT next action indication
 * PARAMETERS
 *  NextActionID    [IN]    
 * RETURNS
 *  PU8
 *****************************************************************************/
PU8 SATReturnNextAction(U8 NextActionID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (NextActionID)
    {
        case SAT_NEXT_ACTION_SETUP_CALL:
            return ((PU8) GetString(SAT_NEXT_ACTION_SETUP_CALL_STRING_ID));

        case SAT_NEXT_ACTION_SEND_SS:
            return ((PU8) GetString(SAT_NEXT_ACTION_SEND_SS_STRING_ID));

        case SAT_NEXT_ACTION_SEND_USSD:
            return ((PU8) GetString(SAT_NEXT_ACTION_SEND_USSD_STRING_ID));

        case SAT_NEXT_ACTION_SEND_SMS:
            return ((PU8) GetString(SAT_NEXT_ACTION_SEND_SMS_STRING_ID));

        case SAT_NEXT_ACTION_PLAY_TONE:
            return ((PU8) GetString(SAT_NEXT_ACTION_PLAY_TONE_STRING_ID));

        case SAT_NEXT_ACTION_DISPLAY_TEXT:
            return ((PU8) GetString(SAT_NEXT_ACTION_DISPLAY_TEXT_STRING_ID));

        case SAT_NEXT_ACTION_GET_INKEY:
            return ((PU8) GetString(SAT_NEXT_ACTION_GET_INKEY_STRING_ID));

        case SAT_NEXT_ACTION_GET_INPUT:
            return ((PU8) GetString(SAT_NEXT_ACTION_GET_INPUT_STRING_ID));

        case SAT_NEXT_ACTION_SELECT_ITEM:
            return ((PU8) GetString(SAT_NEXT_ACTION_SELECT_ITEM_STRING_ID));

        case SAT_NEXT_ACTION_SETUP_MENU:
            return ((PU8) GetString(SAT_NEXT_ACTION_SETUP_MENU_STRING_ID));

        case SAT_NEXT_ACTION_SETUP_IDLE_TEXT:
            return ((PU8) GetString(SAT_NEXT_ACTION_SETUP_IDLE_TEXT_STRING_ID));

        case SAT_NEXT_ACTION_PERFORM_CARD_APDU:
            return ((PU8) GetString(SAT_NEXT_ACTION_PERFORM_CARD_APDU_STRING_ID));

        case SAT_NEXT_ACTION_POWER_ON_CARD:
            return ((PU8) GetString(SAT_NEXT_ACTION_POWER_ON_CARD_STRING_ID));

        case SAT_NEXT_ACTION_POWER_OFF_CARD:
            return ((PU8) GetString(SAT_NEXT_ACTION_POWER_OFF_CARD_STRING_ID));

        case SAT_NEXT_ACTION_GET_READER_STATUS:
            return ((PU8) GetString(SAT_NEXT_ACTION_GET_READER_STATUS_STRING_ID));

        case SAT_NEXT_ACTION_OPEN_CHANNEL:
            return ((PU8) GetString(SAT_NEXT_ACTION_OPEN_CHANNEL_STRING_ID));

        case SAT_NEXT_ACTION_CLOSE_CHANNEL:
            return ((PU8) GetString(SAT_NEXT_ACTION_CLOSE_CHANNEL_STRING_ID));

        case SAT_NEXT_ACTION_RECEIVE_DATA:
            return ((PU8) GetString(SAT_NEXT_ACTION_RECEIVE_DATA_STRING_ID));

        case SAT_NEXT_ACTION_SEND_DATA:
            return ((PU8) GetString(SAT_NEXT_ACTION_SEND_DATA_STRING_ID));

        case SAT_NEXT_ACTION_GET_CHANNEL_STATUS:
            return ((PU8) GetString(SAT_NEXT_ACTION_GET_CHANNEL_STATUS_STRING_ID));

        case SAT_NEXT_ACTION_RESERVED_FOR_TIA:
            return ((PU8) GetString(SAT_NEXT_ACTION_RESERVED_FOR_TIA_STRING_ID));

        case SAT_NEXT_ACTION_END_SESSION:
            return ((PU8) GetString(SAT_NEXT_ACTION_END_SESSION_STRING_ID));

        default:
            return (NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  SATCompletePreviousTransaction
 * DESCRIPTION
 *  Prevent screen delete by others
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SATCompletePreviousTransaction(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (gSATContext.lastSATCmd)
    {
        case SAT_SELECT_ITEM_CMD:
            TerminalResponseSelectItem(SAT_PROACTIVE_CMD_TERMINATED_BY_USER, 0, gSATSubMenu.cmdDetail);
            break;
        case SAT_DISPLAY_TEXT_CMD:
            TerminalResponseDisplayText(SAT_PROACTIVE_CMD_TERMINATED_BY_USER, gSATDisplayText.cmdDetail);
            break;
        case SAT_GET_INPUT:
            TerminalResponseGetInput(SAT_PROACTIVE_CMD_TERMINATED_BY_USER, gSATGetInput.cmdDetail);
            break;
        case SAT_GET_INKEY:
            TerminalResponseGetInkey(SAT_PROACTIVE_CMD_TERMINATED_BY_USER, 0, gSATGetInkey.cmdDetail);
            break;
        case SAT_CALL_SETUP_CMD:
            TerminalResponseCallSetup(SAT_PROACTIVE_CMD_TERMINATED_BY_USER, 0, gSATCallSetup.cmdDetail);        /* Avoid re-try by SIM */
            break;
        case SAT_PLAY_TONE_CMD:
            TerminalResponsePlayTone(SAT_PROACTIVE_CMD_TERMINATED_BY_USER, gSATPlayTone.cmdDetail);
            break;
        case SAT_LAUNCH_BROWSER_CMD:
            TerminalResponseLaunchBrowser(SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, 0, gSATLaunchBrowser.cmdDetail);
            break;
        case SAT_SEND_DTMF_CMD:
            TerminalResponseSendDTMF(SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, 0, gSATSendDTMF.cmdDetail);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitSATMainMenu
 * DESCRIPTION
 *  Exit Handler for SAT Main Menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitSATMainMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExitVariables();
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  FreeMainMenu
 * DESCRIPTION
 *  Frees memory of various elements of SATSETUPMENU struct
 * PARAMETERS
 *  mainMenu    [IN]    Pointer to SATSETUPMENU struct to be freed
 * RETURNS
 *  void
 *****************************************************************************/
void FreeMainMenu(SATSETUPMENU *mainMenu)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SATClearAllIcons();

    for (i = 0; i < mainMenu->numOfItem; i++)
    {
        if (mainMenu->menuItems[i].itemData)
        {
            OslMfree(mainMenu->menuItems[i].itemData);
            mainMenu->menuItems[i].itemData = NULL;
        }
    }
    mainMenu->numOfItem = 0;
    if (mainMenu->menuItems != NULL)
    {
        OslMfree(mainMenu->menuItems);
        mainMenu->menuItems = NULL;
    }
    if (mainMenu->alphaId)
    {
        OslMfree(mainMenu->alphaId);
        mainMenu->alphaId = NULL;
    }

#ifdef __USAT__
    if (mainMenu.textFormatting)
    {
        OslMfree(mainMenu.textFormatting);
    }
    mainMenu.noTextAttribute = 0;
    mainMenu.textFormatting = NULL;
#endif /* __USAT__ */ 
}


#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
/*****************************************************************************
 * FUNCTION
 *  FreeMainMenu_2
 * DESCRIPTION
 *  Frees memory of various elements of SATSETUPMENU struct
 * PARAMETERS
 *  mainMenu    [IN]    Pointer to SATSETUPMENU struct to be freed
 * RETURNS
 *  void
 *****************************************************************************/
void FreeMainMenu_2(SATSETUPMENU *mainMenu)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SATClearAllIcons();

    for (i = 0; i < mainMenu->numOfItem_2; i++)
    {
        if (mainMenu->menuItems_2[i].itemData)
        {
            OslMfree(mainMenu->menuItems_2[i].itemData);
            mainMenu->menuItems_2[i].itemData = NULL;
        }
    }
    mainMenu->numOfItem_2 = 0;
    if (mainMenu->menuItems_2 != NULL)
    {
        OslMfree(mainMenu->menuItems_2);
        mainMenu->menuItems_2 = NULL;
    }
    if (mainMenu->alphaId_2)
    {
        OslMfree(mainMenu->alphaId_2);
        mainMenu->alphaId_2 = NULL;
    }

#ifdef __USAT__
    if (mainMenu.textFormatting)
    {
        OslMfree(mainMenu.textFormatting);
    }
    mainMenu.noTextAttribute = 0;
    mainMenu.textFormatting = NULL;
#endif /* __USAT__ */ 
}

#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */


/*****************************************************************************
 * FUNCTION
 *  SATMenuIndex
 * DESCRIPTION
 *  Highlight Handler for various menus in SAT
 * PARAMETERS
 *  index       [IN]    Index of item highlighted
 * RETURNS
 *  void
 *****************************************************************************/
void SATMenuIndex(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gSATContext.highlightedIndex = (U8) index;

    /* diamond, 2006/03/22 record the last selected item for backward move to SAT main menu */
    if (gSATContext.historyFuncPtr == GoToSATMainMenu)
    {
        gSATMainMenu.selectedMenuItem = gSATContext.highlightedIndex;
    }
}


#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
/*****************************************************************************
 * FUNCTION
 *  SATMenuIndex_2
 * DESCRIPTION
 *  Highlight Handler for various menus in SAT
 * PARAMETERS
 *  index       [IN]    Index of item highlighted
 * RETURNS
 *  void
 *****************************************************************************/
void SATMenuIndex_2(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gSATContext.highlightedIndex = (U8) index;

    /* diamond, 2006/03/22 record the last selected item for backward move to SAT main menu */
    if (gSATContext.historyFuncPtr == GoToSATMainMenu_2)
    {
        gSATMainMenu.selectedMenuItem_2 = gSATContext.highlightedIndex;
    }
}

#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */


/*****************************************************************************
 * FUNCTION
 *  EnvelopeSetupMenuOK
 * DESCRIPTION
 *  Key Handler for LSK of Main Menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EnvelopeSetupMenuOK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!gSATContext.gotStage1Rsp)
    {
        /* prevent from entry SAT screen first then get SEND SMS indication */
        SimBusyPleaseWait();
        return;
    }

    EnvelopeSetupMenu(gSATMainMenu.menuItems[gSATContext.highlightedIndex].itemId, FALSE);
    SATPleaseWaitScreen(SAT_WAIT_STRING_ID, SAT_WAIT_IMAGE_ID);
}


#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
/*****************************************************************************
 * FUNCTION
 *  EnvelopeSetupMenuOK_2
 * DESCRIPTION
 *  Key Handler for LSK of Main Menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EnvelopeSetupMenuOK_2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!gSATContext.gotStage1Rsp)
    {
        /* prevent from entry SAT screen first then get SEND SMS indication */
        SimBusyPleaseWait();
        return;
    }

    EnvelopeSetupMenu(gSATMainMenu.menuItems_2[gSATContext.highlightedIndex].itemId, FALSE);
    SATPleaseWaitScreen(SAT_WAIT_STRING_ID, SAT_WAIT_IMAGE_ID);
}

#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */


/*****************************************************************************
 * FUNCTION
 *  EnvelopeSetupMenuHelp
 * DESCRIPTION
 *  Key Handler for Hotkey of Main Menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EnvelopeSetupMenuHelp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EnvelopeSetupMenu(gSATMainMenu.menuItems[gSATContext.highlightedIndex].itemId, TRUE);
    SATPleaseWaitScreen(SAT_WAIT_STRING_ID, SAT_WAIT_IMAGE_ID);
}


#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
/*****************************************************************************
 * FUNCTION
 *  EnvelopeSetupMenuHelp_2
 * DESCRIPTION
 *  Key Handler for Hotkey of Main Menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EnvelopeSetupMenuHelp_2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EnvelopeSetupMenu(gSATMainMenu.menuItems_2[gSATContext.highlightedIndex].itemId, TRUE);
    SATPleaseWaitScreen(SAT_WAIT_STRING_ID, SAT_WAIT_IMAGE_ID);
}

#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */


/*****************************************************************************
 * FUNCTION
 *  EnvelopeSetupMenu
 * DESCRIPTION
 *  Sends ENVELOPE MENU SELECT to L4
 * PARAMETERS
 *  itemId                  [IN]    Item id of selcted item
 *  isHelpInfoRequested     [IN]    Is help Rquested (TRUE/FALSE)
 * RETURNS
 *  void
 *****************************************************************************/
void EnvelopeSetupMenu(U8 itemId, U8 isHelpInfoRequested)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    mmi_sat_menu_select_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gSATContext.gotStage1Rsp = 0;
    gSATMainMenu.isSentRsp = 1;

    Message = ALLOCATE_ITM(MOD_MMI);
    Message->oslSrcId = MOD_MMI;
    Message->oslMsgId = PRT_MMI_SAT_MENU_SELECT_REQ;
    dataPtr = (mmi_sat_menu_select_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_menu_select_req_struct));
    dataPtr->item_id = itemId;
    dataPtr->is_help_info_requested = isHelpInfoRequested;
    Message->oslDataPtr = (oslParaType*) dataPtr;
    Message->oslPeerBuffPtr = NULL;
    SEND_MSG(Message);
    gSATContext.lastSATCmd = SAT_NONE_CMD;
}


/*****************************************************************************
 * FUNCTION
 *  SATMenuSelectRsp
 * DESCRIPTION
 *  Protocol Handler for menu select
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATMenuSelectRsp(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gSATContext.gotStage1Rsp = 1;
}


#define MMI_SAT_SELECT_ITEM
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
/*****************************************************************************
 * FUNCTION
 *  TerminalResponseSelectItemEx
 * DESCRIPTION
 *  Send SELECT ITEM REQ to L4 or L4_2 by destId
 * PARAMETERS
 *  destId      [IN]    L4/L4_2
 *  res         [IN]    Response type
 *  itemId      [IN]    Item id of selcted item
 *  cmdDetail   [IN]    Cmd detail to be sent
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseSelectItemEx(U8 destId, U8 res, U8 itemId, U8 *cmdDetail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    mmi_sat_select_item_res_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message = allocate_ilm(MOD_MMI);
    Message->oslSrcId = MOD_MMI;
    Message->oslDestId = destId;
    Message->oslMsgId = PRT_MMI_SAT_SELECT_ITEM_RES_REQ;
    dataPtr =
        (mmi_sat_select_item_res_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_select_item_res_req_struct));
    dataPtr->res = res;
    dataPtr->item_id = itemId;
    memcpy(dataPtr->cmd_detail, (void*)cmdDetail, 5 * sizeof(U8));
    Message->oslDataPtr = (oslParaType*) dataPtr;
    Message->oslPeerBuffPtr = NULL;
    Message->sap_id = INVALID_SAP;
    msg_send_ext_queue(Message);
}


/*****************************************************************************
 * FUNCTION
 *  SATSelectItemSIM1Ind
 * DESCRIPTION
 *  Protocol Handler for SELECT ITEM IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4-1
 * RETURNS
 *  void
 *****************************************************************************/
void SATSelectItemSIM1Ind(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_select_item_ind_struct *selectItem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    selectItem = (mmi_sat_select_item_ind_struct*) msgPtr;

    if (gSATSubMenu.CMDfromSIM == SAT_CMD_SIM2)
    {
        TerminalResponseSelectItemEx(MOD_L4C, SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, 1, selectItem->cmd_detail);
    }
    else
    {
        gSATSubMenu.CMDfromSIM = SAT_CMD_SIM1;
        SATSelectItemInd(msgPtr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  SATSelectItemSIM2Ind
 * DESCRIPTION
 *  Protocol Handler for SELECT ITEM IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4-2
 * RETURNS
 *  void
 *****************************************************************************/
void SATSelectItemSIM2Ind(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_select_item_ind_struct *selectItem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    selectItem = (mmi_sat_select_item_ind_struct*) msgPtr;

    if (gSATSubMenu.CMDfromSIM == SAT_CMD_SIM1)
    {
        TerminalResponseSelectItemEx(MOD_L4C_2, SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, 1, selectItem->cmd_detail);
    }
    else
    {
        gSATSubMenu.CMDfromSIM = SAT_CMD_SIM2;
        SATSelectItemInd(msgPtr);
    }
}

#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */


/*****************************************************************************
 * FUNCTION
 *  SATSelectItemInd
 * DESCRIPTION
 *  Protocol Handler for SELECT ITEM IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATSelectItemInd(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U8 *tempDataPtr;
    SATMENUITEM *menuItem;
    mmi_sat_select_item_ind_struct *selectItem;
    U16 convertLen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    selectItem = (mmi_sat_select_item_ind_struct*) msgPtr;

    FreeSubMenu();

    gSATContext.lastSATCmd = SAT_SELECT_ITEM_CMD;
    gSATContext.guiBufferPointer = NULL;
    gSATSubMenu.isSentRsp = 0;

#ifndef __MMI_SAT_SHOW_ITEM_IN_CALL__
    if (isInCall() || IsInSATCall())
    {
        /* additional info is necessary for SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD so that the item id field is temporarily used for this cause */
        TerminalResponseSelectItem(SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, 1, selectItem->cmd_detail);
        return;
    }
#endif /* __MMI_SAT_SHOW_ITEM_IN_CALL__ */

    if ((isIncomingCall() || isOutgoingCall()) && GetDisconnectingCallHandle() == -1)
    {
        /* additional info is necessary for SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD so that the item id field is temporarily used for this cause */
        TerminalResponseSelectItem(SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, 1, selectItem->cmd_detail);
        return;
    }

    memcpy(gSATSubMenu.cmdDetail, selectItem->cmd_detail, 5 * sizeof(U8));

    gSATSubMenu.isHelpInfoAvailable = selectItem->is_help_info_available;
    gSATSubMenu.numOfItem = selectItem->num_of_item;

    gSATSubMenu.noItemIconIdList = selectItem->no_item_icon_id_list;
    gSATSubMenu.itemIconListAttr = selectItem->item_icon_list_attr;

#ifdef __GEMINI__
    if (is_test_sim(0))
#else
    if (is_test_sim())
#endif
    {
        gSATSubMenu.noNextActionIndList = selectItem->no_next_action_ind_list;
    }
    else
    {
        gSATSubMenu.noNextActionIndList = 0;
    }

    gSATSubMenu.isIconAvailable = selectItem->is_icon_available;
    if (gSATSubMenu.isIconAvailable)
    {
        gSATSubMenu.IconID = selectItem->icon_info.icon_id;
        gSATSubMenu.iconAttr = selectItem->icon_info.icon_attr;
    }

    gSATSubMenu.dcsOfAlphaId = selectItem->dcs_of_alpha_id;
    if (gSATSubMenu.isIconAvailable && gSATSubMenu.iconAttr == SAT_ICON_SELF_EX)
    {
        gSATSubMenu.alphaIdLen = 0;
        gSATSubMenu.alphaId = NULL;
    }
    else
    {
        gSATSubMenu.alphaIdLen = selectItem->no_alpha_id;
        gSATSubMenu.alphaId = CovertStringForPlatform(
                                selectItem->alpha_id,
                                gSATSubMenu.alphaIdLen,
                                gSATSubMenu.dcsOfAlphaId,
                                &gSATSubMenu.alphaIdLen);
    }

#ifdef __USAT__
    gSATMainMenu.noTextAttribute = selectItem->no_text_attribute;
    if (gSATMainMenu.noTextAttribute != 0)
    {
        gSATMainMenu.textFormatting = OslMalloc(gSATMainMenu.noTextAttribute * 4);
        memcpy(gSATMainMenu.textFormatting, selectItem->text_formatting, gSATMainMenu.noTextAttribute * 4);
    }
#endif /* __USAT__ */ 

    if (gSATSubMenu.numOfItem == 0)
    {
        SelectItemWrongData();
        return;
    }

    if (gSATSubMenu.numOfItem > 0)
    {
        gSATSubMenu.menuItems = OslMalloc(gSATSubMenu.numOfItem * sizeof(SATMENUITEM));
        memset(gSATSubMenu.menuItems, 0, gSATSubMenu.numOfItem * sizeof(SATMENUITEM));

        menuItem = gSATSubMenu.menuItems;
        tempDataPtr = selectItem->item_data;
        for (i = 0; i < gSATSubMenu.numOfItem; i++, menuItem++)
        {
            menuItem->itemLen = (U16) (*(tempDataPtr + 1));
            tempDataPtr += 2;
            menuItem->itemId = *tempDataPtr++;
            menuItem->itemDcs = *tempDataPtr++;
            if (menuItem->itemLen != 0)
            {
                menuItem->itemData = CovertStringForPlatform(tempDataPtr, menuItem->itemLen, menuItem->itemDcs, &convertLen);
                tempDataPtr += menuItem->itemLen;
                menuItem->itemLen = convertLen;
            }
            else
            {
                menuItem->itemData = NULL;
                menuItem->itemLen = 0;
            }

            if (gSATSubMenu.noItemIconIdList)
                menuItem->IconID = *(selectItem->item_icon_id_list + i);

            if (gSATSubMenu.noItemIconIdList && gSATSubMenu.itemIconListAttr == SAT_ICON_SELF_EX)
            {
                if (menuItem->itemData)
                {
                    OslMfree(menuItem->itemData);
                    menuItem->itemData = NULL;
                }
            }

            if (gSATSubMenu.noNextActionIndList)
                menuItem->nextAction = selectItem->next_action_ind_list[i];

        #ifdef __USAT__
            if (selectItem->no_item_attribute)
            {
                memcpy(menuItem->itemTextFormatting, selectItem->item_formatting + 4 * i, 4);
            }
            else
            {
                memset(menuItem->itemTextFormatting, 0, 4);
            }
        #endif /* __USAT__ */ 
        }
    }

    gSATSubMenu.defaultIndex = 0;
    if (selectItem->is_item_id_available)
    {
        for (i = 0; i < gSATSubMenu.numOfItem; i++)
        {
            if (gSATSubMenu.menuItems[i].itemId == selectItem->item_id)
            {
                gSATSubMenu.defaultIndex = i;
                break;
            }
        }
    }

    SATStopWaitTimer();
    DeleteScreenIfPresent(SCR_ID_SAT_HISTORY);
    if (GetExitScrnID() == SCR_ID_SAT_HISTORY)
    {
        ClearExitHandler();
    }

    if (isInCall() || IsScreenPresent(GetCmMarkerScrnID()))
    {
        SetCMScrnFlag(FALSE);
    }

    GoToSATSubMenu();
}


/*****************************************************************************
 * FUNCTION
 *  SelectItemWrongData
 * DESCRIPTION
 *  Displays SAT Sub Menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SelectItemWrongData(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TerminalResponseSelectItem(
        SAT_CMD_DATA_NOT_UNDERSTAND_BY_ME,
        1, /* gSATSubMenu.menuItems[gSATContext.highlightedIndex].itemId, */
        gSATSubMenu.cmdDetail);
}


/*****************************************************************************
 * FUNCTION
 *  GoToSATSubMenu
 * DESCRIPTION
 *  Displays SAT Sub Menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoToSATSubMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *listItems[64];
    U8 *listItemsIcons[64];
    U8 *listNextAction[64];
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(listItems, 0, sizeof(listItems));
    memset(listItemsIcons, 0, sizeof(listItemsIcons));
    memset(listNextAction, 0, sizeof(listNextAction));

    if (gSATSubMenu.isIconAvailable)
    {
        SATAddIconIDToList(gSATSubMenu.IconID);
    }

    for (i = 0; i < gSATSubMenu.noItemIconIdList; i++)
    {
        SATAddIconIDToList(gSATSubMenu.menuItems[i].IconID);
    }

    if (gSATSubMenu.isIconAvailable || gSATSubMenu.noItemIconIdList)
    {
        if (!SATCheckAllIconGot())
        {
            SATGetIconCompleteCallBack = GoToSATSubMenu;
            SATGetIconDataToList();
            return;
        }
    }

    for (i = 0; i < gSATSubMenu.numOfItem; i++)
    {
        listItems[i] = gSATSubMenu.menuItems[i].itemData;
        if (gSATSubMenu.noItemIconIdList)
        {
            listItemsIcons[i] = SATGetIconFromList(gSATSubMenu.menuItems[i].IconID);
        }
        if (gSATSubMenu.noNextActionIndList)
        {
            listNextAction[i] = SATReturnNextAction(gSATSubMenu.menuItems[i].nextAction);
        }
    }

    gSATContext.exitCondition = &gSATSubMenu.isSentRsp;
    EntryNewScreen(SCR_ID_SAT_SUBMENU, SATGenericExitHandler, NULL, NULL);

    SetIsInSATScreen();
    gSATContext.historyFuncPtr = GoToSATSubMenu;

    RegisterHighlightHandler(SATMenuIndex);

    ShowCategory174Screen(
        gSATSubMenu.alphaId,
        SATGetIconFromList(gSATSubMenu.IconID),
        (PU8) GetString(STR_GLOBAL_OK),
        (PU8) GetImage(IMG_GLOBAL_OK),
        (PU8) GetString(STR_GLOBAL_BACK),
        (PU8) GetImage(IMG_GLOBAL_BACK),
        gSATSubMenu.numOfItem,
        listItems,
        listItemsIcons,
        listNextAction,
        0,
        gSATSubMenu.defaultIndex,
        gSATContext.guiBufferPointer);

    if (gSATSubMenu.isHelpInfoAvailable)
    {
        SetKeyHandler(TerminalResponseSelectItemHelp, KEY_SEND, KEY_EVENT_UP);
    }

    SetKeyHandler(TerminalResponseSelectItemExpire, KEY_END, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(TerminalResponseSelectItemOK, KEY_EVENT_UP);
    SetRightSoftkeyFunction(TerminalResponseSelectItemMoveBack, KEY_EVENT_UP);
    SetKeyHandler(TerminalResponseSelectItemOK, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(TerminalResponseSelectItemMoveBack, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    StartSATTimerNoResponsefromUser(SelectItemTimer);
}


/*****************************************************************************
 * FUNCTION
 *  SelectItemTimer
 * DESCRIPTION
 *  Callback function called whn the user shows no activity on
 *  Select Item Screen for 30 secs
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SelectItemTimer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TerminalResponseSelectItem(
        SAT_NO_RESPONSE_FROM_USER,
        gSATSubMenu.menuItems[gSATContext.highlightedIndex].itemId,
        gSATSubMenu.cmdDetail);

    if (gSATContext.isInSATMenu)
    {
    #if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
        if (gSATContext.satIndex == SAT_CMD_SIM2)
        {
            gSATContext.historyFuncPtr = GoToSATMainMenu_2;
        }
        else
        {
            gSATContext.historyFuncPtr = GoToSATMainMenu;
        }
    #else /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
        gSATContext.historyFuncPtr = GoToSATMainMenu;
    #endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
        if (gSATContext.isInSATScreen)
        {
            if (IsScreenPresent(SCR_ID_SAT_HISTORY))
            {
                GoBackToHistory(SCR_ID_SAT_HISTORY);
            }
            else
            {
            #if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
                if (gSATContext.satIndex == SAT_CMD_SIM2)
                {
                    GoToSATMainMenu_2();
                }
                else
                {
                    GoToSATMainMenu();
                }
            #else /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
                GoToSATMainMenu();
            #endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
            }
        }
    }
    else
    {
        if (gSATContext.isInSATScreen)
        {
            GoBackHistory();
        }
        else
        {
            DeleteScreenIfPresent(SCR_ID_SAT_HISTORY);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  TerminalResponseSelectItemOK
 * DESCRIPTION
 *  Key Handler for LSK of SAT Sub Menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseSelectItemOK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TerminalResponseSelectItem(
        SAT_CMD_PERFORMED_SUCCESSFULLY,
        gSATSubMenu.menuItems[gSATContext.highlightedIndex].itemId,
        gSATSubMenu.cmdDetail);
    SATPleaseWaitScreen(SAT_WAIT_STRING_ID, SAT_WAIT_IMAGE_ID);
}


/*****************************************************************************
 * FUNCTION
 *  TerminalResponseSelectItemMoveBack
 * DESCRIPTION
 *  Key Handler for RSK of SAT Sub Menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseSelectItemMoveBack(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TerminalResponseSelectItem(
        SAT_BACKWARD_MOVE_IN_PROACTIVE_SESSION_BY_USER,
        gSATSubMenu.menuItems[gSATContext.highlightedIndex].itemId,
        gSATSubMenu.cmdDetail);
    SATPleaseWaitScreen(SAT_WAIT_STRING_ID, SAT_WAIT_IMAGE_ID);
}


/*****************************************************************************
 * FUNCTION
 *  TerminalResponseSelectItemHelp
 * DESCRIPTION
 *  Key Handler for Hotkey of SAT Sub Menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseSelectItemHelp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TerminalResponseSelectItem(
        SAT_HELP_INFO_REQUEST_BY_USER,
        gSATSubMenu.menuItems[gSATContext.highlightedIndex].itemId,
        gSATSubMenu.cmdDetail);
    SATPleaseWaitScreen(SAT_WAIT_STRING_ID, SAT_WAIT_IMAGE_ID);
}


/*****************************************************************************
 * FUNCTION
 *  TerminalResponseSelectItemExpire
 * DESCRIPTION
 *  Key Handler for End Key of SAT Sub Menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseSelectItemExpire(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TerminalResponseSelectItem(
        SAT_PROACTIVE_CMD_TERMINATED_BY_USER,
        gSATSubMenu.menuItems[gSATContext.highlightedIndex].itemId,
        gSATSubMenu.cmdDetail);
    ExitSATToIdle();
}


/*****************************************************************************
 * FUNCTION
 *  TerminalResponseSelectItem
 * DESCRIPTION
 *  Send SELECT ITEM REQ to L4
 * PARAMETERS
 *  res         [IN]    Response type
 *  itemId      [IN]    Item id of selcted item
 *  cmdDetail   [IN]    Cmd detail to be sent
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseSelectItem(U8 res, U8 itemId, U8 *cmdDetail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    mmi_sat_select_item_res_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!gSATSubMenu.isSentRsp)
    {
        StopSATTimerNoResponsefromUser();
        gSATContext.noResponseFuncPtr = NULL;   /* diamond, 2005/07/25 SAT timer */
        gSATSubMenu.isSentRsp = 1;

        Message = ALLOCATE_ITM(MOD_MMI);
        Message->oslSrcId = MOD_MMI;
        Message->oslMsgId = PRT_MMI_SAT_SELECT_ITEM_RES_REQ;
        dataPtr =
            (mmi_sat_select_item_res_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_select_item_res_req_struct));
        dataPtr->item_id = itemId;

        /* diamond, 2005/05/24 icon */
        if (res == SAT_CMD_PERFORMED_SUCCESSFULLY && gSATSubMenu.isIconAvailable == 1 &&
            gSATContext.isCMDIconSupported == MMI_FALSE)
        {
            dataPtr->res = SAT_CMD_PERFORMED_BUT_ICON_COULD_NOT_DSPL;
        }
        else
        {
            /* end, diamond */
            dataPtr->res = res;
        }

        memcpy(dataPtr->cmd_detail, (void*)cmdDetail, 5 * sizeof(U8));
        Message->oslDataPtr = (oslParaType*) dataPtr;
        Message->oslPeerBuffPtr = NULL;
        SEND_MSG_SUBMENU(Message);
        gSATContext.lastSATCmd = SAT_NONE_CMD;
    }
}


/*****************************************************************************
 * FUNCTION
 *  SATSelectItemRsp
 * DESCRIPTION
 *  Protocol Handler for SELECT ITEM RES
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATSelectItemRsp(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FreeSubMenu();
}


/*****************************************************************************
 * FUNCTION
 *  FreeSubMenu
 * DESCRIPTION
 *  Frees memory of varios elements of SAT Sub Menu Structure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FreeSubMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SATClearAllIcons();

    for (i = 0; i < gSATSubMenu.numOfItem; i++)
    {
        if (gSATSubMenu.menuItems[i].itemData)
        {
            OslMfree(gSATSubMenu.menuItems[i].itemData);
            gSATSubMenu.menuItems[i].itemData = NULL;
        }
    }
    gSATSubMenu.numOfItem = 0;
    if (gSATSubMenu.menuItems != NULL)
    {
        OslMfree(gSATSubMenu.menuItems);
        gSATSubMenu.menuItems = NULL;
    }
    if (gSATSubMenu.alphaId)
    {
        OslMfree(gSATSubMenu.alphaId);
        gSATSubMenu.alphaId = NULL;
    }

#ifdef __USAT__
    if (gSATSubMenu.textFormatting)
    {
        OslMfree(gSATSubMenu.textFormatting);
    }
    gSATSubMenu.noTextAttribute = 0;
    gSATSubMenu.textFormatting = NULL;
#endif /* __USAT__ */ 
}


#define MMI_SAT_DISPLAY_TEXT
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
/*****************************************************************************
 * FUNCTION
 *  TerminalResponseDisplayTextEx
 * DESCRIPTION
 *  Send DISPLAY TEXT REQ to L4 or L4_2 by destId
 * PARAMETERS
 *  destId      [IN]    L4/L4_2
 *  res         [IN]    Response type
 *  cmdDetail   [IN]    Cmd detail to be sent
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseDisplayTextEx(U8 destId, U8 res, U8 *cmdDetail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    mmi_sat_display_text_res_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message = allocate_ilm(MOD_MMI);
    Message->oslSrcId = MOD_MMI;
    Message->oslDestId = destId;
    Message->oslMsgId = PRT_MMI_SAT_DISPLAY_TEXT_RES_REQ;
    dataPtr =
        (mmi_sat_display_text_res_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_display_text_res_req_struct));
    dataPtr->res = res;
    if (dataPtr->res == SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD)
    {
        dataPtr->additional_info = SAT_SCREEN_BUSY;
    }
    memcpy(dataPtr->cmd_detail, (void*)cmdDetail, 5 * sizeof(U8));
    Message->oslDataPtr = (oslParaType*) dataPtr;
    Message->oslPeerBuffPtr = NULL;
    Message->sap_id = INVALID_SAP;
    msg_send_ext_queue(Message);
}


/*****************************************************************************
 * FUNCTION
 *  SATDisplayTextSIM1Ind
 * DESCRIPTION
 *  Protocol Handler for DISPLAY TEXT IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4-1
 * RETURNS
 *  void
 *****************************************************************************/
void SATDisplayTextSIM1Ind(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_display_text_ind_struct *displayText;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    displayText = (mmi_sat_display_text_ind_struct*) msgPtr;

    if (gSATDisplayText.CMDfromSIM == SAT_CMD_SIM2)
    {
        TerminalResponseDisplayTextEx(MOD_L4C, SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, displayText->cmd_detail);
    }
    else
    {
        gSATDisplayText.CMDfromSIM = SAT_CMD_SIM1;
        SATDisplayTextInd(msgPtr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  SATDisplayTextSIM2Ind
 * DESCRIPTION
 *  Protocol Handler for DISPLAY TEXT IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4-2
 * RETURNS
 *  void
 *****************************************************************************/
void SATDisplayTextSIM2Ind(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_display_text_ind_struct *displayText;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    displayText = (mmi_sat_display_text_ind_struct*) msgPtr;

    if (gSATDisplayText.CMDfromSIM == SAT_CMD_SIM1)
    {
        TerminalResponseDisplayTextEx(MOD_L4C_2, SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, displayText->cmd_detail);
    }
    else
    {
        gSATDisplayText.CMDfromSIM = SAT_CMD_SIM2;
        SATDisplayTextInd(msgPtr);
    }
}

#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */


/*****************************************************************************
 * FUNCTION
 *  SATDisplayTextInd
 * DESCRIPTION
 *  Protocol Handler for DISPLAY TEXT IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATDisplayTextInd(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_display_text_ind_struct *displayText;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    displayText = (mmi_sat_display_text_ind_struct*) msgPtr;

    FreeDisplayText();

    gSATContext.lastSATCmd = SAT_DISPLAY_TEXT_CMD;
    gSATContext.guiBufferPointer = NULL;
    gSATDisplayText.sentRsp = 0;

    if ((mmi_bootup_get_active_flight_mode() == 1) ||
        (!gSATContext.isInSATMenu && !g_idle_context.IsOnIdleScreen && !gSATContext.isInSATScreen && displayText->priority == SAT_PRI_NORMAL) ||
        (gSATContext.isInSATCall == 1 && displayText->priority == SAT_PRI_NORMAL) ||
        (isIncomingCall() || isOutgoingCall()))
    {
        TerminalResponseDisplayText(SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, displayText->cmd_detail);
        return;
    }

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    if ((gSATDisplayText.CMDfromSIM == SAT_CMD_SIM1 &&
         (MTPNP_AD_Get_Status() & MTPNP_AD_CARD1) != MTPNP_AD_CARD1) ||
        (gSATDisplayText.CMDfromSIM == SAT_CMD_SIM2 &&
         (MTPNP_AD_Get_Status() & MTPNP_AD_CARD2) != MTPNP_AD_CARD2))
    {
        TerminalResponseDisplayText(SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, displayText->cmd_detail);
        return;
    }
#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */

    if (displayText->is_icon_available && !displayText->no_text_string)
    {
        TerminalResponseDisplayText(SAT_CMD_DATA_NOT_UNDERSTAND_BY_ME, displayText->cmd_detail);
        return;
    }

    memcpy(gSATDisplayText.cmdDetail, (void*)displayText->cmd_detail, 5 * sizeof(U8));

    gSATDisplayText.clearTextType = displayText->clear_text_type;
    gSATDisplayText.immediateRes = displayText->immediate_res;

#ifdef __USAT__
    gSATDisplayText.countdownStarted = 0;
    gSATDisplayText.duration = displayText->duration;
    gSATDisplayText.noTextAttribute = displayText->no_text_attribute;
    if (gSATDisplayText.noTextAttribute != 0)
    {
        gSATDisplayText.textFormatting = OslMalloc(gSATDisplayText.noTextAttribute * 4);
        memcpy(gSATDisplayText.textFormatting, displayText->text_formatting, gSATDisplayText.noTextAttribute * 4);
    }
#endif /* __USAT__ */ 

    gSATDisplayText.textStringLen = displayText->no_text_string;
    gSATDisplayText.dcsOfTextString = displayText->dcs_of_text_string;
    /* Spec 12.15, always gsm default encoding */
    if (gSATDisplayText.dcsOfTextString == MMI_8BIT_DCS)
    {
        gSATDisplayText.dcsOfTextString = MMI_DEFAULT_DCS;
    }

    mmi_sat_remove_text_pending_characters(
        displayText->text_string,
        &gSATDisplayText.textStringLen,
        gSATDisplayText.dcsOfTextString);

    gSATDisplayText.textString = CovertStringForPlatform(
                                    displayText->text_string,
                                    gSATDisplayText.textStringLen,
                                    gSATDisplayText.dcsOfTextString,
                                    &gSATDisplayText.textStringLen);

    gSATDisplayText.isIconAvailable = displayText->is_icon_available;
    if (gSATDisplayText.isIconAvailable)
    {
        gSATDisplayText.iconInfo.iconId = displayText->icon_info.icon_id;
        gSATDisplayText.iconInfo.iconAttr = displayText->icon_info.icon_attr;
    }

    if (gSATDisplayText.isIconAvailable && gSATDisplayText.iconInfo.iconAttr == SAT_ICON_SELF_EX)
    {
        if (gSATDisplayText.textString)
        {
            OslMfree(gSATDisplayText.textString);
            gSATDisplayText.textString = NULL;
        }
    }

    if (mmi_bootup_is_searching_or_idle_reached() == MMI_TRUE)
    {
        SATStopWaitTimer();
        DeleteScreenIfPresent(SCR_ID_SAT_HISTORY);
        if (GetExitScrnID() == SCR_ID_SAT_HISTORY)
        {
            ClearExitHandler();
        }
    #ifdef __MMI_SAT_DISPLAY_TEXT_WITH_KEYPAD_LOCK__
        if (g_idle_context.IsOnIdleScreen)
        {
            gSATContext.idleSATCmd = 1;
            gSATContext.historyFuncPtr = GoToSATDisplayTextScreen;
            EntryIdleScreen();
            return;
        }
    #endif /* __MMI_SAT_DISPLAY_TEXT_WITH_KEYPAD_LOCK__ */
        GoToSATDisplayTextScreen();
    }
    else if (gSATContext.postponedSATScreen == NULL)
    {
        SATStopWaitTimer();
        gSATContext.postponedSATScreen = GoToSATDisplayTextScreen;
    }
    else
    {
        TerminalResponseDisplayText(SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, displayText->cmd_detail);
        ClearPostponedSATScreen(); /* only one postponed SAT screen is allowed */
    }
}


/*****************************************************************************
 * FUNCTION
 *  GoToSATDisplayTextScreen
 * DESCRIPTION
 *  Displays DISPLAY TEXT Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoToSATDisplayTextScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *iconData = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gSATDisplayText.isIconAvailable)
    {
        SATAddIconIDToList(gSATDisplayText.iconInfo.iconId);
    }

    if (gSATDisplayText.isIconAvailable)
    {
        if (!SATCheckAllIconGot())
        {
            SATGetIconCompleteCallBack = GoToSATDisplayTextScreen;
            SATGetIconDataToList();
            return;
        }
    }

    iconData = SATGetIconFromList(gSATDisplayText.iconInfo.iconId);
    gSATContext.exitCondition = &gSATDisplayText.sentRsp;
    EntryNewScreen(SCR_ID_SAT_DISPLAYTEXT, SATGenericExitHandler, NULL, NULL);

    TurnOnBacklight(1);

    SetIsInSATScreen();
    gSATContext.historyFuncPtr = GoToSATDisplayTextScreen;
#ifdef __MMI_SAT_DISPLAY_TEXT_WITH_KEYPAD_LOCK__
    if (g_keylock_context.gKeyPadLockFlag)
    {
        ShowCategory151Screen(
            0,
            0,
            g_keylock_context.KeyLockLSKStringID,
            g_keylock_context.KeyLockLSKIconID,
            g_keylock_context.KeyLockRSKStringID,
            g_keylock_context.KeyLockRSKIconID,
            gSATDisplayText.textString,
            iconData,
            gSATContext.guiBufferPointer);
    }
    else
    {
#endif /* __MMI_SAT_DISPLAY_TEXT_WITH_KEYPAD_LOCK__ */
        ShowCategory151Screen(
            0,
            0,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            gSATDisplayText.textString,
            iconData,
            gSATContext.guiBufferPointer);

        SetKeyHandler(TerminalResponseDisplayTextExpire, KEY_END, KEY_EVENT_DOWN);
        SetLeftSoftkeyFunction(TerminalResponseDisplayTextOK, KEY_EVENT_UP);
        SetRightSoftkeyFunction(TerminalResponseDisplayTextMoveBack, KEY_EVENT_UP);
#ifdef __MMI_SAT_DISPLAY_TEXT_WITH_KEYPAD_LOCK__
    }
#endif

    if (gSATDisplayText.immediateRes)
    {
        TerminalResponseDisplayText(SAT_CMD_PERFORMED_SUCCESSFULLY, gSATDisplayText.cmdDetail);
    }

    StartSATTimerNoResponsefromUser(DisplayTextTimer);
}


/*****************************************************************************
 * FUNCTION
 *  DisplayTextTimer
 * DESCRIPTION
 *  Callback function called whn the user shows no activity on
 *  Display Text Screen for 30 secs
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DisplayTextTimer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gSATDisplayText.clearTextType == SAT_CLEAR_AFTER_DELAY)
    {
        TerminalResponseDisplayText(SAT_CMD_PERFORMED_SUCCESSFULLY, gSATDisplayText.cmdDetail);
        SATPleaseWaitScreen(SAT_WAIT_STRING_ID, SAT_WAIT_IMAGE_ID);
    }
    else
    {
        TerminalResponseDisplayText(SAT_NO_RESPONSE_FROM_USER, gSATDisplayText.cmdDetail);

        if (gSATContext.isInSATMenu)
        {
        #if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
            if (gSATContext.satIndex == SAT_CMD_SIM2)
            {
                gSATContext.historyFuncPtr = GoToSATMainMenu_2;
            }
            else
            {
                gSATContext.historyFuncPtr = GoToSATMainMenu;
            }
        #else /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
            gSATContext.historyFuncPtr = GoToSATMainMenu;
        #endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
            if (gSATContext.isInSATScreen)
            {
                if (IsScreenPresent(SCR_ID_SAT_HISTORY))
                {
                    GoBackToHistory(SCR_ID_SAT_HISTORY);
                }
                else
                {
                #if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
                    if (gSATContext.satIndex == SAT_CMD_SIM2)
                    {
                        GoToSATMainMenu_2();
                    }
                    else
                    {
                        GoToSATMainMenu();
                    }
                #else /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
                    GoToSATMainMenu();
                #endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
                }
            }
        }
        else
        {
            if (gSATContext.isInSATScreen)
            {
                GoBackHistory();
            }
            else
            {
                DeleteScreenIfPresent(SCR_ID_SAT_HISTORY);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  TerminalResponseDisplayTextOK
 * DESCRIPTION
 *  Key Handler for LSK of Display Text Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseDisplayTextOK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TerminalResponseDisplayText(SAT_CMD_PERFORMED_SUCCESSFULLY, gSATDisplayText.cmdDetail);
    SATPleaseWaitScreen(SAT_WAIT_STRING_ID, SAT_WAIT_IMAGE_ID);
}


/*****************************************************************************
 * FUNCTION
 *  TerminalResponseDisplayTextMoveBack
 * DESCRIPTION
 *  Key Handler for RSK of Display Text Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseDisplayTextMoveBack(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TerminalResponseDisplayText(SAT_BACKWARD_MOVE_IN_PROACTIVE_SESSION_BY_USER, gSATDisplayText.cmdDetail);
    SATPleaseWaitScreen(SAT_WAIT_STRING_ID, SAT_WAIT_IMAGE_ID);
}


/*****************************************************************************
 * FUNCTION
 *  TerminalResponseDisplayTextExpire
 * DESCRIPTION
 *  Key Handler for End Key of Display Text Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseDisplayTextExpire(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TerminalResponseDisplayText(SAT_PROACTIVE_CMD_TERMINATED_BY_USER, gSATDisplayText.cmdDetail);
    ExitSATToIdle();
}


/*****************************************************************************
 * FUNCTION
 *  TerminalResponseDisplayText
 * DESCRIPTION
 *  Send DISPLAY TEXT REQ to L4
 * PARAMETERS
 *  res         [IN]    Response type
 *  cmdDetail   [IN]    Cmd detail to be sent
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseDisplayText(U8 res, U8 *cmdDetail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    mmi_sat_display_text_res_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopSATTimerNoResponsefromUser();
    gSATContext.noResponseFuncPtr = NULL;   /* diamond, 2005/07/25 SAT timer */

#ifdef __MMI_SAT_DISPLAY_TEXT_WITH_KEYPAD_LOCK__
    gSATContext.idleSATCmd = 0;
#endif

    if (!gSATDisplayText.sentRsp)
    {
        gSATDisplayText.sentRsp = 1;
        Message = ALLOCATE_ITM(MOD_MMI);
        Message->oslSrcId = MOD_MMI;
        Message->oslMsgId = PRT_MMI_SAT_DISPLAY_TEXT_RES_REQ;
        dataPtr =
            (mmi_sat_display_text_res_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_display_text_res_req_struct));

        /* diamond, 2005/05/24 icon */
        if (res == SAT_CMD_PERFORMED_SUCCESSFULLY && gSATDisplayText.isIconAvailable == 1 &&
            gSATContext.isCMDIconSupported == MMI_FALSE)
        {
            dataPtr->res = SAT_CMD_PERFORMED_BUT_ICON_COULD_NOT_DSPL;
        }
        else
        {
            /* end, diamond */
            dataPtr->res = res;
        }

        if (dataPtr->res == SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD)
        {
            dataPtr->additional_info = SAT_SCREEN_BUSY;
        }

        memcpy(dataPtr->cmd_detail, (void*)cmdDetail, 5 * sizeof(U8));
        Message->oslDataPtr = (oslParaType*) dataPtr;
        Message->oslPeerBuffPtr = NULL;
        SEND_MSG_DISPTEXT(Message);
        gSATContext.lastSATCmd = SAT_NONE_CMD;
    }
}


/*****************************************************************************
 * FUNCTION
 *  SATDisplayTextRsp
 * DESCRIPTION
 *  Protocol Handler for DISPLAY TEXT RES
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATDisplayTextRsp(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    if (gSATDisplayText.CMDfromSIM != SAT_CMD_SIM2)
#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
    {
        FreeDisplayText();
    }
}


#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
/*****************************************************************************
 * FUNCTION
 *  SATDisplayTextRsp_2
 * DESCRIPTION
 *  Protocol Handler for DISPLAY TEXT RES
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATDisplayTextRsp_2(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gSATDisplayText.CMDfromSIM != SAT_CMD_SIM1)
    {
        FreeDisplayText();
    }
}

#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */


/*****************************************************************************
 * FUNCTION
 *  FreeDisplayText
 * DESCRIPTION
 *  Frees memory of varios elements of Display Text
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FreeDisplayText(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SATClearAllIcons();
    if (gSATDisplayText.textString)
    {
        OslMfree(gSATDisplayText.textString);
        gSATDisplayText.textString = NULL;
    }

#ifdef __USAT__
    if (gSATDisplayText.textFormatting)
    {
        OslMfree(gSATDisplayText.textFormatting);
    }
    gSATDisplayText.noTextAttribute = 0;
    gSATDisplayText.textFormatting = NULL;
#endif /* __USAT__ */ 
}


#define MMI_SAT_GET_INPUT
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
/*****************************************************************************
 * FUNCTION
 *  TerminalResponseGetInputEx
 * DESCRIPTION
 *  Send GET INPUT REQ to L4 or L4_2 by destId
 * PARAMETERS
 *  destId      [IN]    L4/L4_2
 *  res         [IN]    Response type
 *  cmdDetail   [IN]    Cmd detail to be sent
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseGetInputEx(U8 destId, U8 res, U8 *cmdDetail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    mmi_sat_get_input_res_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message = allocate_ilm(MOD_MMI);
    Message->oslSrcId = MOD_MMI;
    Message->oslDestId = destId;
    Message->oslMsgId = PRT_MMI_SAT_GET_INPUT_RES_REQ;
    dataPtr = (mmi_sat_get_input_res_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_get_input_res_req_struct));
    dataPtr->res = res;
    dataPtr->no_text_string = 0;
    dataPtr->dcs_of_text_string = 0;
    dataPtr->text_string[0] = 0;
    memcpy(dataPtr->cmd_detail, (void*)cmdDetail, 5 * sizeof(U8));
    Message->oslDataPtr = (oslParaType*) dataPtr;
    Message->oslPeerBuffPtr = NULL;
    Message->sap_id = INVALID_SAP;
    msg_send_ext_queue(Message);
}


/*****************************************************************************
 * FUNCTION
 *  SATGetInputSIM1Ind
 * DESCRIPTION
 *  Protocol Handler for GET INPUT IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4-1
 * RETURNS
 *  void
 *****************************************************************************/
void SATGetInputSIM1Ind(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_get_input_ind_struct *satGetInputInd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    satGetInputInd = (mmi_sat_get_input_ind_struct*) msgPtr;

    if (gSATContext.CMDfromSIM == SAT_CMD_SIM2)
    {
        TerminalResponseGetInputEx(MOD_L4C, SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, satGetInputInd->cmd_detail);
    }
    else
    {
        gSATContext.CMDfromSIM = SAT_CMD_SIM1;
        SATGetInputInd(msgPtr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  SATGetInputSIM2Ind
 * DESCRIPTION
 *  Protocol Handler for GET INPUT IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4-2
 * RETURNS
 *  void
 *****************************************************************************/
void SATGetInputSIM2Ind(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_get_input_ind_struct *satGetInputInd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    satGetInputInd = (mmi_sat_get_input_ind_struct*) msgPtr;

    if (gSATContext.CMDfromSIM == SAT_CMD_SIM1)
    {
        TerminalResponseGetInputEx(MOD_L4C_2, SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, satGetInputInd->cmd_detail);
    }
    else
    {
        gSATContext.CMDfromSIM = SAT_CMD_SIM2;
        SATGetInputInd(msgPtr);
    }
}

#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */

/*****************************************************************************
 * FUNCTION
 *  SATGetInputInd
 * DESCRIPTION
 *  Protocol Handler for GET INPUT IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATGetInputInd(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_get_input_ind_struct *satGetInputInd;
    U16 defaultLen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    satGetInputInd = (mmi_sat_get_input_ind_struct*) msgPtr;

    FreeGetInput();

    gSATContext.lastSATCmd = SAT_GET_INPUT;
    gSATContext.guiBufferPointer = NULL;
    gSATGetInput.sentRsp = 0;

    /* Reject SAT proactive cmd if there is a call which breaks the "please wait" screen */
    if (isIncomingCall() || isOutgoingCall())
    {
        TerminalResponseGetInput(SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, satGetInputInd->cmd_detail);
        return;
    }

    /* Check confliction between max length and default text length */
    if ((satGetInputInd->dcs_of_default_text == MMI_UCS2_DCS && satGetInputInd->no_default_text/2 > satGetInputInd->len_of_max_input) ||
         (satGetInputInd->dcs_of_default_text != MMI_UCS2_DCS && satGetInputInd->no_default_text > satGetInputInd->len_of_max_input))
    {
        TerminalResponseGetInput(SAT_CMD_DATA_NOT_UNDERSTAND_BY_ME, satGetInputInd->cmd_detail);
        return;
    }

    memcpy(gSATGetInput.cmdDetail, satGetInputInd->cmd_detail, 5 * sizeof(U8));

    gSATGetInput.isHelpInfoAvailable = satGetInputInd->is_help_info_available;
    if (satGetInputInd->type_of_input == TYPE_ONLY_DIGIT || satGetInputInd->type_of_input == TYPE_ONLY_DIGIT_UCS2)
    {
        if (satGetInputInd->is_input_revealed_to_user)
        {
            gSATGetInput.typeOfInput = INPUT_TYPE_PHONE_NUMBER;
        }
        else
        {
            gSATGetInput.typeOfInput = INPUT_TYPE_SAT_NUMERIC_PASSWORD;
        }
    }
    else /* TYPE_SMS_DEFAULT_SET or TYPE_UCS2 */
    {
        if (satGetInputInd->is_input_revealed_to_user)
        {
            gSATGetInput.typeOfInput = INPUT_TYPE_ALPHANUMERIC_LOWERCASE;
        }
        else
        {
            gSATGetInput.typeOfInput = INPUT_TYPE_ALPHANUMERIC_PASSWORD;
        }
    }

    gSATGetInput.lenOfMinInput = satGetInputInd->len_of_min_input;
    /* diamond, 2006/01/03 GET INPUT max length of UCS2 type */
    if (satGetInputInd->type_of_input == TYPE_UCS2 && satGetInputInd->len_of_max_input > 70)
    {
        /* conflict with spec 11.10-4, regard it as byte length */
        gSATGetInput.lenOfMaxInput = satGetInputInd->len_of_max_input / 2;
    }
    else
    {
        /* according to spec 11.10-4, it is character length */
        gSATGetInput.lenOfMaxInput = satGetInputInd->len_of_max_input;
    }

    gSATGetInput.lenOfTextString = satGetInputInd->no_text_string;
    gSATGetInput.dcsOfTextString = satGetInputInd->dcs_of_text_string;
    /* Spec 12.15, always gsm default encoding */
    if (gSATGetInput.dcsOfTextString == MMI_8BIT_DCS)
    {
        gSATGetInput.dcsOfTextString = MMI_DEFAULT_DCS;
    }

    mmi_sat_remove_text_pending_characters(
        satGetInputInd->text_string,
        &gSATGetInput.lenOfTextString,
        gSATGetInput.dcsOfTextString);

    gSATGetInput.textString = CovertStringForPlatform(
                                satGetInputInd->text_string,
                                gSATGetInput.lenOfTextString,
                                gSATGetInput.dcsOfTextString,
                                &gSATGetInput.lenOfTextString);

    gSATGetInput.lenOfDefaultText = satGetInputInd->no_default_text;
    gSATGetInput.dcsOfDefaultText = satGetInputInd->dcs_of_default_text;
    /* Spec 12.15, always gsm default encoding */
    if (gSATGetInput.dcsOfDefaultText == MMI_8BIT_DCS)
    {
        gSATGetInput.dcsOfDefaultText = MMI_DEFAULT_DCS;
    }

    mmi_sat_remove_text_pending_characters(
        satGetInputInd->default_text,
        &gSATGetInput.lenOfDefaultText,
        gSATGetInput.dcsOfDefaultText);

    gSATGetInput.defaultText = CovertStringForPlatform(
                                satGetInputInd->default_text,
                                gSATGetInput.lenOfDefaultText,
                                gSATGetInput.dcsOfDefaultText,
                                &defaultLen);
    gSATGetInput.lenOfDefaultText = defaultLen;

    gSATGetInput.lenOfInputString = gSATGetInput.lenOfMaxInput * ENCODING_LENGTH + ENCODING_LENGTH;
    gSATGetInput.inputString = (U8*) OslMalloc(gSATGetInput.lenOfInputString);
    if (gSATGetInput.defaultText != NULL && gSATGetInput.lenOfDefaultText <= gSATGetInput.lenOfInputString)
    {
        memcpy(gSATGetInput.inputString, gSATGetInput.defaultText, gSATGetInput.lenOfDefaultText);
    }
    else
    {
        memset((void*)gSATGetInput.inputString, 0, ENCODING_LENGTH);
    }

    if (!(gSATGetInput.cmdDetail[4] & 0x01))                    /* Bit 1 is 0 */
    {
        if (!(gSATGetInput.cmdDetail[4] & 0x02))                /* Bit 2 is 0 */
        {
            if (!(gSATGetInput.cmdDetail[4] & 0x08))
            {
                gSATGetInput.dcsOfInputString = MMI_8BIT_DCS;   /* user input to be in unpacked format */
            }
            else
            {
                gSATGetInput.dcsOfInputString = MMI_DEFAULT_DCS;
            }
        }
        else    /* 010b */
        {
            gSATGetInput.dcsOfInputString = MMI_UCS2_DCS;       /* input UCS2 chars */
        }
    }
    else
    {
        if (!(gSATGetInput.cmdDetail[4] & 0x02))                /* Bit 2 is 0 */
        {
            if (!(gSATGetInput.cmdDetail[4] & 0x08))
            {
                gSATGetInput.dcsOfInputString = MMI_8BIT_DCS;   /* user input to be in unpacked format */
            }
            else
            {
                gSATGetInput.dcsOfInputString = MMI_DEFAULT_DCS;
            }
        }
        else    /* 011b */
        {
            gSATGetInput.dcsOfInputString = MMI_UCS2_DCS;       /* input UCS2 chars */
        }
    }

#ifdef __USAT__
    gSATGetInput.noTextAttribute = satGetInputInd->no_text_attribute;
    if (gSATGetInput.noTextAttribute != 0)
    {
        gSATGetInput.textFormatting = OslMalloc(gSATGetInput.noTextAttribute * 4);
        memcpy(gSATGetInput.textFormatting, satGetInputInd->text_formatting, gSATGetInput.noTextAttribute * 4);
    }
#endif /* __USAT__ */ 

    gSATGetInput.isIconAvailable = satGetInputInd->is_icon_available;
    if (gSATGetInput.isIconAvailable)
    {
        gSATGetInput.iconInfo.iconId = satGetInputInd->icon_info.icon_id;
        gSATGetInput.iconInfo.iconAttr = satGetInputInd->icon_info.icon_attr;
    }

    if (gSATGetInput.isIconAvailable && gSATGetInput.iconInfo.iconAttr == SAT_ICON_SELF_EX)
    {
        if (gSATGetInput.textString)
        {
            OslMfree(gSATGetInput.textString);
            gSATGetInput.textString = NULL;
        }
    }

    SATStopWaitTimer();
    DeleteScreenIfPresent(SCR_ID_SAT_HISTORY);
    if (GetExitScrnID() == SCR_ID_SAT_HISTORY)
    {
        ClearExitHandler();
    }
    GoToGetInput();
}


/*****************************************************************************
 * FUNCTION
 *  GoToGetInput
 * DESCRIPTION
 *  Displays Get Input Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoToGetInput(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *iconData = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gSATGetInput.isIconAvailable)
    {
        SATAddIconIDToList(gSATGetInput.iconInfo.iconId);
    }

    if (gSATGetInput.isIconAvailable)
    {
        if (!SATCheckAllIconGot())
        {
            SATGetIconCompleteCallBack = GoToGetInput;
            SATGetIconDataToList();
            return;
        }
    }

    iconData = SATGetIconFromList(gSATGetInput.iconInfo.iconId);
    gSATContext.exitCondition = &gSATGetInput.sentRsp;
    EntryNewScreen(SCR_ID_SAT_GETINPUT, SATGenericExitHandler, NULL, NULL);

    SetIsInSATScreen();
    gSATContext.historyFuncPtr = GoToGetInput;

    if (gSATGetInput.dcsOfInputString != MMI_UCS2_DCS)
    {
        gSATGetInput.typeOfInput |= INPUT_TYPE_USE_ONLY_ENGLISH_MODES;
    }

    if ((gSATGetInput.typeOfInput & INPUT_TYPE_MASK) == INPUT_TYPE_PHONE_NUMBER ||
        (gSATGetInput.typeOfInput & INPUT_TYPE_MASK) == INPUT_TYPE_SAT_NUMERIC_PASSWORD)
    {
        /* diamond, 2005/07/22 GET INPUT numeric input without 'p' and 'w' */
        if ((gSATGetInput.typeOfInput & INPUT_TYPE_MASK) == INPUT_TYPE_PHONE_NUMBER)
        {
            MMI_current_input_ext_type |= INPUT_TYPE_EXT_SIM_NUMERIC;
        }
        /* end, diamond */

        ShowCategory171Screen(
            (PU8) GetString(STR_GLOBAL_OK),
            (PU8) GetImage(IMG_GLOBAL_OK),
            (PU8) GetString(STR_GLOBAL_BACK),
            (PU8) GetImage(IMG_GLOBAL_BACK),
            gSATGetInput.textString,
            iconData,
            gSATGetInput.typeOfInput,
            gSATGetInput.inputString,
            gSATGetInput.lenOfMaxInput + 1,
            gSATContext.guiBufferPointer);

        SetLeftSoftkeyFunction(TerminalResponseGetInputOK, KEY_EVENT_UP);
    }
    else
    {
        ShowCategory171Screen(
            (PU8) GetString(STR_GLOBAL_OPTIONS),
            (PU8) GetImage(IMG_GLOBAL_OPTIONS),
            (PU8) GetString(STR_GLOBAL_BACK),
            (PU8) GetImage(IMG_GLOBAL_BACK),
            gSATGetInput.textString,
            iconData,
            gSATGetInput.typeOfInput,
            gSATGetInput.inputString,
            gSATGetInput.lenOfMaxInput + 1,
            gSATContext.guiBufferPointer);

        /* ChangeLeftSoftkey (STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS); */
        SetLeftSoftkeyFunction(SATEntryScrForInputMethodAndDone, KEY_EVENT_UP);
    }

    if (gSATGetInput.isHelpInfoAvailable)
    {
        SetKeyHandler(TerminalResponseGetInputHelp, KEY_SEND, KEY_EVENT_UP);
    }

    SetKeyHandler(TerminalResponseGetInputExpire, KEY_END, KEY_EVENT_DOWN);
    SetCategory171RightSoftkeyFunction(TerminalResponseGetInputMoveBack, KEY_EVENT_UP);

    StartSATTimerNoResponsefromUser(GetInputTimer);
}


/*****************************************************************************
 * FUNCTION
 *  SATEntryScrForInputMethodAndDone
 * DESCRIPTION
 *  Displays Input Method And Done Screen from Get Input Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SATEntryScrForInputMethodAndDone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[10];
    U16 numItems;
    U16 itemIcons[10];
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SAT_SCR_INPUT_METHOD_AND_DONE, NULL, SATEntryScrForInputMethodAndDone, NULL);

    guiBuffer = GetCurrGuiBuffer(SAT_SCR_INPUT_METHOD_AND_DONE);
    numItems = GetNumOfChild(MENU_INPUT_METHOD_AND_DONE_OPTION_ID);
    GetSequenceStringIds(MENU_INPUT_METHOD_AND_DONE_OPTION_ID, nStrItemList);
    SetParentHandler(MENU_INPUT_METHOD_AND_DONE_OPTION_ID);

    RegisterHighlightHandler(SATInputMethodAndDoneHiliteHandler);

    for (i = 0; ((i < numItems) && (i < 10)); i++)
    {
        itemIcons[i] = IMG_GLOBAL_L1 + i;
    }

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
    #ifdef __MMI_OP01_MENU_9MATRIX__
/* under construction !*/
    #else
        GetRootTitleIcon(MAIN_MENU_SERVICES_MENUID),
    #endif
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        itemIcons,
        NULL,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  SATInputMethodAndDoneHiliteHandler
 * DESCRIPTION
 *  Hilite Handler for Input Method And Done Screen
 * PARAMETERS
 *  index       [IN]    
 * RETURNS
 *  void
 *****************************************************************************/
void SATInputMethodAndDoneHiliteHandler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == 0)
    {
        if (gSATContext.lastSATCmd == SAT_GET_INPUT)
        {
            SetLeftSoftkeyFunction(TerminalResponseGetInputOKDone, KEY_EVENT_UP);
            SetKeyHandler(TerminalResponseGetInputOKDone, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        }
        else if (gSATContext.lastSATCmd == SAT_GET_INKEY)
        {
            SetLeftSoftkeyFunction(TerminalResponseGetInkeyOKDone, KEY_EVENT_UP);
            SetKeyHandler(TerminalResponseGetInkeyOKDone, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        }
    }
    else
    {
        SetLeftSoftkeyFunction(EntryInputMethodScreen, KEY_EVENT_UP);
        SetKeyHandler(EntryInputMethodScreen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        RegisterInputMethodScreenCloseFunction(SATGoBacknHistoryFromInputMethod);
    }
}


/*****************************************************************************
 * FUNCTION
 *  TerminalResponseGetInputOKDone
 * DESCRIPTION
 *  Function for sending Terminal Response when Done is pressed
 *  from Input Method & Done Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseGetInputOKDone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetIsInSATScreen();
    if ((U16) (mmi_ucs2strlen((PS8) gSATGetInput.inputString)) >= gSATGetInput.lenOfMinInput)
    {
        ClearExitHandler();
    }
    TerminalResponseGetInputOK();
    if (gSATGetInput.sentRsp)
    {
        DeleteScreenIfPresent(SCR_ID_SAT_HISTORY);
    }
}


/*****************************************************************************
 * FUNCTION
 *  SATGoBacknHistoryFromInputMethod
 * DESCRIPTION
 *  Takes back the user from Input Method & Done Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SATGoBacknHistoryFromInputMethod(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBacknHistory(1);
}


/*****************************************************************************
 * FUNCTION
 *  GetInputTimer
 * DESCRIPTION
 *  Callback function called whn the user shows no activity on
 *  Select Item Screen for 30 secs
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GetInputTimer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TerminalResponseGetInput(SAT_NO_RESPONSE_FROM_USER, gSATGetInput.cmdDetail);

    if (gSATContext.isInSATMenu)
    {
    #if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
        if (gSATContext.satIndex == SAT_CMD_SIM2)
        {
            gSATContext.historyFuncPtr = GoToSATMainMenu_2;
        }
        else
        {
            gSATContext.historyFuncPtr = GoToSATMainMenu;
        }
    #else /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
        gSATContext.historyFuncPtr = GoToSATMainMenu;
    #endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
        if (gSATContext.isInSATScreen)
        {
            if (IsScreenPresent(SCR_ID_SAT_HISTORY))
            {
                GoBackToHistory(SCR_ID_SAT_HISTORY);
            }
            else
            {
            #if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
                if (gSATContext.satIndex == SAT_CMD_SIM2)
                {
                    GoToSATMainMenu_2();
                }
                else
                {
                    GoToSATMainMenu();
                }
            #else /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
                GoToSATMainMenu();
            #endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
            }
        }
    }
    else
    {
        if (gSATContext.isInSATScreen)
        {
            GoBackHistory();
        }
        else
        {
            DeleteScreenIfPresent(SCR_ID_SAT_HISTORY);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  TerminalResponseGetInputOK
 * DESCRIPTION
 *  Key Handler of LSK of Get Input Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseGetInputOK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    mmi_sat_get_input_res_req_struct *dataPtr;
    U16 len;
    U16 inputLen;
    U8 *input = NULL;
    U8 display_info[64], temp_info[16];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len = (U16) (mmi_ucs2strlen((PS8) gSATGetInput.inputString));
    if (len >= gSATGetInput.lenOfMinInput)
    {
        gSATGetInput.sentRsp = 1;
        StopSATTimerNoResponsefromUser();
        gSATContext.noResponseFuncPtr = NULL;   /* diamond, 2005/07/25 SAT timer */

        Message = ALLOCATE_ITM(MOD_MMI);
        Message->oslSrcId = MOD_MMI;
        Message->oslMsgId = PRT_MMI_SAT_GET_INPUT_RES_REQ;
        dataPtr =
            (mmi_sat_get_input_res_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_get_input_res_req_struct) +
                                                                     (len * ENCODING_LENGTH) - 1);

        /* diamond, 2005/05/24 icon */
        if (gSATGetInput.isIconAvailable == 1 && gSATContext.isCMDIconSupported == MMI_FALSE)
        {
            dataPtr->res = SAT_CMD_PERFORMED_BUT_ICON_COULD_NOT_DSPL;
        }
        else
        {
            /* end, diamond */
            dataPtr->res = SAT_CMD_PERFORMED_SUCCESSFULLY;
        }

        memcpy(dataPtr->cmd_detail, (void*)gSATGetInput.cmdDetail, 5 * sizeof(U8));
        dataPtr->dcs_of_text_string = gSATGetInput.dcsOfInputString;
        if (gSATGetInput.dcsOfInputString == MMI_8BIT_DCS)
        {
            input = CovertStringForSIM(gSATGetInput.inputString, (U16) (len * ENCODING_LENGTH), MMI_DEFAULT_DCS, &inputLen);
        }
        else
        {
            input = CovertStringForSIM(
                        gSATGetInput.inputString,
                        (U16) (len * ENCODING_LENGTH),
                        dataPtr->dcs_of_text_string,
                        &inputLen);
        }

        if (dataPtr->dcs_of_text_string == MMI_UCS2_DCS)
        {
            dataPtr->no_text_string = (U8) inputLen - 2;
        }
        else
        {
            dataPtr->no_text_string = (U8) inputLen - 1;
        }

        if (dataPtr->no_text_string > 0xFF)
        {
            dataPtr->no_text_string = 0xFF;
            memcpy(dataPtr->text_string, input, 0xFF);
        }
        else
        {
            memcpy(dataPtr->text_string, input, dataPtr->no_text_string);
        }

        if (input)
        {
            OslMfree(input);
        }

        Message->oslDataPtr = (oslParaType*) dataPtr;
        Message->oslPeerBuffPtr = NULL;
        SEND_MSG(Message);
        gSATContext.lastSATCmd = SAT_NONE_CMD;
        SATPleaseWaitScreen(SAT_WAIT_STRING_ID, SAT_WAIT_IMAGE_ID);
    }
    else
    {
        /* display at least necessary input length */
        mmi_ucs2cpy((PS8) display_info, (PS8) get_string(SAT_GET_INPUT_LENGTH_NOT_ENOUGH));
        kal_wsprintf((PU16) temp_info, ": %d", gSATGetInput.lenOfMinInput);
        mmi_ucs2cat((PS8) display_info, (PS8)temp_info);

        DisplayPopup(
            display_info,
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        DeleteScreenIfPresent(SAT_SCR_INPUT_METHOD_AND_DONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  TerminalResponseGetInputMoveBack
 * DESCRIPTION
 *  Key Handler of RSK of Get Input Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseGetInputMoveBack(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TerminalResponseGetInput(SAT_BACKWARD_MOVE_IN_PROACTIVE_SESSION_BY_USER, gSATGetInput.cmdDetail);
    SATPleaseWaitScreen(SAT_WAIT_STRING_ID, SAT_WAIT_IMAGE_ID);
}


/*****************************************************************************
 * FUNCTION
 *  TerminalResponseGetInputHelp
 * DESCRIPTION
 *  Key Handler of Hot Key of Get Input Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseGetInputHelp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TerminalResponseGetInput(SAT_HELP_INFO_REQUEST_BY_USER, gSATGetInput.cmdDetail);
    SATPleaseWaitScreen(SAT_WAIT_STRING_ID, SAT_WAIT_IMAGE_ID);
}


/*****************************************************************************
 * FUNCTION
 *  TerminalResponseGetInputExpire
 * DESCRIPTION
 *  Key Handler of End Key of Get Input Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseGetInputExpire(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TerminalResponseGetInput(SAT_PROACTIVE_CMD_TERMINATED_BY_USER, gSATGetInput.cmdDetail);
    ExitSATToIdle();
}


/*****************************************************************************
 * FUNCTION
 *  TerminalResponseGetInput
 * DESCRIPTION
 *  Send GET INPUT REQ to L4
 * PARAMETERS
 *  res         [IN]    Response type
 *  cmdDetail   [IN]    Cmd detail to be sent
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseGetInput(U8 res, U8 *cmdDetail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    mmi_sat_get_input_res_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gSATGetInput.sentRsp = 1;
    StopSATTimerNoResponsefromUser();
    gSATContext.noResponseFuncPtr = NULL;   /* diamond, 2005/07/25 SAT timer */

    Message = ALLOCATE_ITM(MOD_MMI);
    Message->oslSrcId = MOD_MMI;
    Message->oslMsgId = PRT_MMI_SAT_GET_INPUT_RES_REQ;
    dataPtr = (mmi_sat_get_input_res_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_get_input_res_req_struct));
    dataPtr->res = res;
    memcpy(dataPtr->cmd_detail, (void*)cmdDetail, 5 * sizeof(U8));
    dataPtr->no_text_string = 0;
    dataPtr->dcs_of_text_string = 0;
    dataPtr->text_string[0] = 0;
    Message->oslDataPtr = (oslParaType*) dataPtr;
    Message->oslPeerBuffPtr = NULL;
    SEND_MSG(Message);
    gSATContext.lastSATCmd = SAT_NONE_CMD;
}


/*****************************************************************************
 * FUNCTION
 *  SATGetInputRsp
 * DESCRIPTION
 *  Protocol Handler for GET INPUT RES
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATGetInputRsp(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FreeGetInput();
}


/*****************************************************************************
 * FUNCTION
 *  FreeGetInput
 * DESCRIPTION
 *  Frees various elements of Get Input Structure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FreeGetInput(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SATClearAllIcons();
    if (gSATGetInput.textString)
    {
        OslMfree(gSATGetInput.textString);
        gSATGetInput.textString = NULL;
    }

    if (gSATGetInput.defaultText)
    {
        OslMfree(gSATGetInput.defaultText);
        gSATGetInput.defaultText = NULL;
    }

    if (gSATGetInput.inputString)
    {
        OslMfree(gSATGetInput.inputString);
        gSATGetInput.inputString = NULL;
    }

#ifdef __USAT__
    if (gSATGetInput.textFormatting)
    {
        OslMfree(gSATGetInput.textFormatting);
    }
    gSATGetInput.noTextAttribute = 0;
    gSATGetInput.textFormatting = NULL;
#endif /* __USAT__ */ 
}


#define MMI_SAT_GET_INKEY
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
/*****************************************************************************
 * FUNCTION
 *  TerminalResponseGetInkeyEx
 * DESCRIPTION
 *  Send GET INKEY REQ to L4 or L4_2 by destId
 * PARAMETERS
 *  destId          [IN]    L4/L4_2
 *  res             [IN]    Response type
 *  isYesSelected   [IN]    Is Yes Selected on Get Inkey Screen (TRUE/FALSE)
 *  cmdDetail       [IN]    Cmd detail to be sent
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseGetInkeyEx(U8 destId, U8 res, U8 isYesSelected, U8 *cmdDetail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    mmi_sat_get_inkey_res_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message = allocate_ilm(MOD_MMI);
    Message->oslSrcId = MOD_MMI;
    Message->oslDestId = destId;
    Message->oslMsgId = PRT_MMI_SAT_GET_INKEY_RES_REQ;
    dataPtr = (mmi_sat_get_inkey_res_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_get_inkey_res_req_struct));
    dataPtr->res = res;
    dataPtr->is_yes_selected = isYesSelected;
    dataPtr->no_text_string = 0;
    dataPtr->dcs_of_text_string = 0;
    dataPtr->text_string[0] = 0;
#ifdef __USAT__
    dataPtr->duration = mmi_sat_count_get_inkey_user_rsp();
#endif 
    memcpy(dataPtr->cmd_detail, (void*)cmdDetail, 5 * sizeof(U8));
    Message->oslDataPtr = (oslParaType*) dataPtr;
    Message->oslPeerBuffPtr = NULL;
    Message->sap_id = INVALID_SAP;
    msg_send_ext_queue(Message);
}


/*****************************************************************************
 * FUNCTION
 *  SATGetInkeySIM1Ind
 * DESCRIPTION
 *  Protocol Handler for GET INKEY IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4-1
 * RETURNS
 *  void
 *****************************************************************************/
void SATGetInkeySIM1Ind(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_get_inkey_ind_struct *satGetInkeyInd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    satGetInkeyInd = (mmi_sat_get_inkey_ind_struct*) msgPtr;

    if (gSATContext.CMDfromSIM == SAT_CMD_SIM2)
    {
        TerminalResponseGetInkeyEx(MOD_L4C, SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, 0, satGetInkeyInd->cmd_detail);
    }
    else
    {
        gSATContext.CMDfromSIM = SAT_CMD_SIM1;
        SATGetInkeyInd(msgPtr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  SATGetInkeySIM2Ind
 * DESCRIPTION
 *  Protocol Handler for GET INKEY IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4-2
 * RETURNS
 *  void
 *****************************************************************************/
void SATGetInkeySIM2Ind(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_get_inkey_ind_struct *satGetInkeyInd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    satGetInkeyInd = (mmi_sat_get_inkey_ind_struct*) msgPtr;

    if (gSATContext.CMDfromSIM == SAT_CMD_SIM1)
    {
        TerminalResponseGetInkeyEx(MOD_L4C_2, SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, 0, satGetInkeyInd->cmd_detail);
    }
    else
    {
        gSATContext.CMDfromSIM = SAT_CMD_SIM2;
        SATGetInkeyInd(msgPtr);
    }
}

#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */


/*****************************************************************************
 * FUNCTION
 *  SATGetInkeyInd
 * DESCRIPTION
 *  Protocol Handler for GET INKEY IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATGetInkeyInd(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_get_inkey_ind_struct *satGetInkeyInd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    satGetInkeyInd = (mmi_sat_get_inkey_ind_struct*) msgPtr;

    FreeGetInkey();

    gSATContext.lastSATCmd = SAT_GET_INKEY;
    gSATContext.guiBufferPointer = NULL;
    gSATGetInkey.sentRsp = 0;

    /* Reject SAT proactive cmd if there is a call which breaks the "please wait" screen */
    if (isIncomingCall() || isOutgoingCall())
    {
        TerminalResponseGetInkey(SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, 0, satGetInkeyInd->cmd_detail);
        return;
    }

    memcpy(gSATGetInkey.cmdDetail, satGetInkeyInd->cmd_detail, 5 * sizeof(U8));

    gSATGetInkey.isHelpInfoAvailable = satGetInkeyInd->is_help_info_available;
    if (satGetInkeyInd->type_of_input == TYPE_ONLY_DIGIT || satGetInkeyInd->type_of_input == TYPE_ONLY_DIGIT_UCS2)
    {
        gSATGetInkey.typeOfInput = INPUT_TYPE_PHONE_NUMBER;
    }
    else if (satGetInkeyInd->type_of_input == TYPE_YES_NO)
    {
        gSATGetInkey.typeOfInput = INPUT_TYPE_YES_NO;
    }
    else /* TYPE_SMS_DEFAULT_SET or TYPE_UCS2 */
    {
        gSATGetInkey.typeOfInput = INPUT_TYPE_ALPHANUMERIC_LOWERCASE;
    }

    gSATGetInkey.lenOfTextString = satGetInkeyInd->no_text_string;
    gSATGetInkey.dcsOfTextString = satGetInkeyInd->dcs_of_text_string;
    /* Spec 12.15, always gsm default encoding */
    if (gSATGetInkey.dcsOfTextString == MMI_8BIT_DCS)
    {
        gSATGetInkey.dcsOfTextString = MMI_DEFAULT_DCS;
    }

    mmi_sat_remove_text_pending_characters(
        satGetInkeyInd->text_string,
        &gSATGetInkey.lenOfTextString,
        gSATGetInkey.dcsOfTextString);

    gSATGetInkey.textString = CovertStringForPlatform(
                                satGetInkeyInd->text_string,
                                gSATGetInkey.lenOfTextString,
                                gSATGetInkey.dcsOfTextString,
                                &gSATGetInkey.lenOfTextString);

    memset(gSATGetInkey.inputString, 0, ENCODING_LENGTH);

    if (!(gSATGetInkey.cmdDetail[4] & 0x04))                    /* Bit 1 is 0 i.e. character sets defined by bit 1 and bit 2 are enabled */
    {
        if (!(gSATGetInkey.cmdDetail[4] & 0x01))                /* Bit 1 is 0 */
        {
            if (!(gSATGetInkey.cmdDetail[4] & 0x02))            /* Bit 2 is 0 */
            {
                gSATGetInkey.dcsOfInputString = MMI_8BIT_DCS;   /* input ascii chars */
            }
            else    /* 010b */
            {
                gSATGetInkey.dcsOfInputString = MMI_UCS2_DCS;   /* input UCS2 chars */
            }
        }
        else
        {
            if (!(gSATGetInkey.cmdDetail[4] & 0x02))            /* Bit 2 is 0 */
            {
                gSATGetInkey.dcsOfInputString = MMI_8BIT_DCS;   /* input ascii chars */
            }
            else    /* 011b */
            {
                gSATGetInkey.dcsOfInputString = MMI_UCS2_DCS;   /* input UCS2 chars */
            }
        }
    }
    else
    {
        gSATGetInkey.dcsOfInputString = MMI_8BIT_DCS;           /* input 0x01 or 0x00 by ACCEPT key as "Yes" and END key as "No" */
    }

#ifdef __USAT__
    gSATGetInkey.duration = (satGetInkeyInd->duration == 0) ? SAT_NO_RESPONSE_TIMER_DURATION : satGetInkeyInd->duration;
    gSATGetInkey.immediateDigitRes = satGetInkeyInd->immediate_digit_res;
    gSATGetInkey.countdownStarted = 0;
    gSATGetInkey.noTextAttribute = satGetInkeyInd->no_text_attribute;
    if (gSATGetInkey.noTextAttribute != 0)
    {
        gSATGetInkey.textFormatting = OslMalloc(gSATGetInkey.noTextAttribute * 4);
        memcpy(gSATGetInkey.textFormatting, satGetInkeyInd->text_formatting, gSATGetInkey.noTextAttribute * 4);
    }
#endif /* __USAT__ */ 

    gSATGetInkey.isIconAvailable = satGetInkeyInd->is_icon_available;
    if (gSATGetInkey.isIconAvailable)
    {
        gSATGetInkey.iconInfo.iconId = satGetInkeyInd->icon_info.icon_id;
        gSATGetInkey.iconInfo.iconAttr = satGetInkeyInd->icon_info.icon_attr;
    }

    if (gSATGetInkey.isIconAvailable && gSATGetInkey.iconInfo.iconAttr == SAT_ICON_SELF_EX)
    {
        if (gSATGetInkey.textString)
        {
            OslMfree(gSATGetInkey.textString);
            gSATGetInkey.textString = NULL;
        }
    }

    SATStopWaitTimer();
    DeleteScreenIfPresent(SCR_ID_SAT_HISTORY);
    if (GetExitScrnID() == SCR_ID_SAT_HISTORY)
    {
        ClearExitHandler();
    }
    GoToGetInkey();
}


/*****************************************************************************
 * FUNCTION
 *  GoToGetInkey
 * DESCRIPTION
 *  Displays Get Inkey Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoToGetInkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *iconData = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gSATGetInkey.isIconAvailable)
    {
        SATAddIconIDToList(gSATGetInkey.iconInfo.iconId);
    }

    if (gSATGetInkey.isIconAvailable)
    {
        if (!SATCheckAllIconGot())
        {
            SATGetIconCompleteCallBack = GoToGetInkey;
            SATGetIconDataToList();
            return;
        }
    }

    iconData = SATGetIconFromList(gSATGetInkey.iconInfo.iconId);
    gSATContext.exitCondition = &gSATGetInkey.sentRsp;
    EntryNewScreen(SCR_ID_SAT_GETINKEY, SATGenericExitHandler, NULL, NULL);

    SetIsInSATScreen();
    gSATContext.historyFuncPtr = GoToGetInkey;

    if (gSATGetInkey.typeOfInput == INPUT_TYPE_YES_NO)
    {
        U8 *option_list[2];

        option_list[0] = (PU8) GetString(STR_GLOBAL_YES);
        option_list[1] = (PU8) GetString(STR_GLOBAL_NO);

        RegisterHighlightHandler(SATHiliteYesNo);

        ShowCategory172Screen(
            gSATGetInkey.textString,
            iconData,
            (U8*) GetString(STR_GLOBAL_OK),
            NULL,
            (U8*) GetString(STR_GLOBAL_BACK),
            NULL,
            2,
            option_list,
            0,
            0,
            gSATContext.guiBufferPointer);

        SetLeftSoftkeyFunction(TerminalResponseGetInkeyYesNo, KEY_EVENT_UP);
        SetRightSoftkeyFunction(TerminalResponseGetInkeyMoveBack, KEY_EVENT_UP);
        SetKeyHandler(TerminalResponseGetInkeyExpire, KEY_END, KEY_EVENT_DOWN);
    }
#ifdef __USAT__
    else if (gSATGetInkey.immediateDigitRes == 1)
    {
        // It's assumed that gSATGetInkey.typeOfInput == INPUT_TYPE_DIGIT
        // Touch screen neeeds a new category with vitual keypad
        U16 SATDigitKeys[] =
            {KEY_0, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_STAR, KEY_POUND};

        ShowCategory151Screen(
            0,
            0,
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            gSATGetInkey.textString,
            iconData,
            gSATContext.guiBufferPointer);

        SetGroupKeyHandler(
            mmi_sat_terminal_response_get_inkey_digit,
            SATDigitKeys,
            (U8) MAX_IDLE_SCREEN_DIGITS - 1,
            KEY_EVENT_UP);

        SetRightSoftkeyFunction(TerminalResponseGetInkeyMoveBack, KEY_EVENT_UP);
        SetKeyHandler(TerminalResponseGetInkeyExpire, KEY_END, KEY_EVENT_DOWN);
    }
#endif /* __USAT__ */ 
    else
    {
        if (gSATGetInkey.dcsOfInputString != MMI_UCS2_DCS)
        {
            gSATGetInkey.typeOfInput |= INPUT_TYPE_USE_ONLY_ENGLISH_MODES;
        }

        if ((gSATGetInkey.typeOfInput & INPUT_TYPE_MASK) == INPUT_TYPE_PHONE_NUMBER)
        {
            /* diamond, 2005/07/22 GET INPUT numeric input without 'p' and 'w' */
            if ((gSATGetInkey.typeOfInput & INPUT_TYPE_MASK) == INPUT_TYPE_PHONE_NUMBER)
            {
                MMI_current_input_ext_type |= INPUT_TYPE_EXT_SIM_NUMERIC;
            }
            /* end, diamond */

            ShowCategory171Screen(
                (PU8) GetString(STR_GLOBAL_OK),
                (PU8) GetImage(IMG_GLOBAL_OK),
                (PU8) GetString(STR_GLOBAL_BACK),
                (PU8) GetImage(IMG_GLOBAL_BACK),
                gSATGetInkey.textString,
                iconData,
                gSATGetInkey.typeOfInput,
                gSATGetInkey.inputString,
                2,
                gSATContext.guiBufferPointer);

            SetLeftSoftkeyFunction(TerminalResponseGetInkeyOK, KEY_EVENT_UP);
        }
        else
        {
            ShowCategory171Screen(
                (PU8) GetString(STR_GLOBAL_OPTIONS),
                (PU8) GetImage(IMG_GLOBAL_OPTIONS),
                (PU8) GetString(STR_GLOBAL_BACK),
                (PU8) GetImage(IMG_GLOBAL_BACK),
                gSATGetInkey.textString,
                iconData,
                gSATGetInkey.typeOfInput,
                gSATGetInkey.inputString,
                2,
                gSATContext.guiBufferPointer);

            /* ChangeLeftSoftkey (STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS); */
            SetLeftSoftkeyFunction(SATEntryScrForInputMethodAndDone, KEY_EVENT_UP);
        }

        SetCategory171RightSoftkeyFunction(TerminalResponseGetInkeyMoveBack, KEY_EVENT_UP);
        SetKeyHandler(TerminalResponseGetInkeyExpire, KEY_END, KEY_EVENT_DOWN);
    }

    if (gSATGetInkey.isHelpInfoAvailable)
    {
        SetKeyHandler(TerminalResponseGetInkeyHelp, KEY_SEND, KEY_EVENT_UP);
    }

    StartSATTimerNoResponsefromUser(GetInkeyTimer);
#ifdef __USAT__
    DTGetRTCTime(&gSATGetInkey.startTime);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  GetInkeyTimer
 * DESCRIPTION
 *  Callback function called whn the user shows no activity on
 *  Select Item Screen for 30 secs
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GetInkeyTimer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TerminalResponseGetInkey(SAT_NO_RESPONSE_FROM_USER, FALSE, gSATGetInkey.cmdDetail);

    if (gSATContext.isInSATMenu)
    {
    #if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
        if (gSATContext.satIndex == SAT_CMD_SIM2)
        {
            gSATContext.historyFuncPtr = GoToSATMainMenu_2;
        }
        else
        {
            gSATContext.historyFuncPtr = GoToSATMainMenu;
        }
    #else /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
        gSATContext.historyFuncPtr = GoToSATMainMenu;
    #endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
        if (gSATContext.isInSATScreen)
        {
            if (IsScreenPresent(SCR_ID_SAT_HISTORY))
            {
                GoBackToHistory(SCR_ID_SAT_HISTORY);
            }
            else
            {
            #if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
                if (gSATContext.satIndex == SAT_CMD_SIM2)
                {
                    GoToSATMainMenu_2();
                }
                else
                {
                    GoToSATMainMenu();
                }
            #else /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
                GoToSATMainMenu();
            #endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
            }
        }
    }
    else
    {
        if (gSATContext.isInSATScreen)
        {
            GoBackHistory();
        }
        else
        {
            DeleteScreenIfPresent(SCR_ID_SAT_HISTORY);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  SATHiliteYesNo
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]    
 * RETURNS
 *  void
 *****************************************************************************/
void SATHiliteYesNo(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gSATContext.highlightedIndex = (U8) index;
}


/*****************************************************************************
 * FUNCTION
 *  TerminalResponseGetInkeyYesNo
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseGetInkeyYesNo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gSATContext.highlightedIndex)
    {
        TerminalResponseGetInkeyNo();
    }
    else
    {
        TerminalResponseGetInkeyYes();
    }
}


/*****************************************************************************
 * FUNCTION
 *  TerminalResponseGetInkeyOKDone
 * DESCRIPTION
 *  Function for sending Terminal Response when Done is pressed
 *  from Input Method & Done Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseGetInkeyOKDone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetIsInSATScreen();
    if ((U16) (mmi_ucs2strlen((PS8) gSATGetInkey.inputString)) >= 1)
    {
        ClearExitHandler();
    }
    TerminalResponseGetInkeyOK();
    if (gSATGetInkey.sentRsp)
    {
        DeleteScreenIfPresent(SCR_ID_SAT_HISTORY);
    }
}


/*****************************************************************************
 * FUNCTION
 *  TerminalResponseGetInkeyOK
 * DESCRIPTION
 *  Key Handler of LSK of Get Inkey Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseGetInkeyOK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    mmi_sat_get_inkey_res_req_struct *dataPtr;
    U16 len;
    U16 inputLen;
    U8 *input = NULL;
    U8 display_info[64], temp_info[16];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len = (U16) mmi_ucs2strlen((PS8) gSATGetInkey.inputString);
    if (len == 1)
    {
        gSATGetInkey.sentRsp = 1;
        StopSATTimerNoResponsefromUser();
        gSATContext.noResponseFuncPtr = NULL;   /* diamond, 2005/07/25 SAT timer */

        Message = ALLOCATE_ITM(MOD_MMI);
        Message->oslSrcId = MOD_MMI;
        Message->oslMsgId = PRT_MMI_SAT_GET_INKEY_RES_REQ;
        dataPtr =
            (mmi_sat_get_inkey_res_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_get_inkey_res_req_struct) + len);

        /* diamond, 2005/05/24 icon */
        if (gSATGetInkey.isIconAvailable == 1 && gSATContext.isCMDIconSupported == MMI_FALSE)
        {
            dataPtr->res = SAT_CMD_PERFORMED_BUT_ICON_COULD_NOT_DSPL;
        }
        else
        {
            /* end, diamond */
            dataPtr->res = SAT_CMD_PERFORMED_SUCCESSFULLY;
        }

        memcpy(dataPtr->cmd_detail, (void*)gSATGetInkey.cmdDetail, 5 * sizeof(U8));
        dataPtr->is_yes_selected = FALSE;
        dataPtr->dcs_of_text_string = gSATGetInkey.dcsOfInputString;

        if (gSATGetInkey.dcsOfInputString == MMI_8BIT_DCS)
        {
            input = CovertStringForSIM(gSATGetInkey.inputString, (U16) (len * ENCODING_LENGTH), MMI_DEFAULT_DCS, &inputLen);
        }
        else
        {
            input = CovertStringForSIM(
                        gSATGetInkey.inputString,
                        (U16) (len * ENCODING_LENGTH),
                        dataPtr->dcs_of_text_string,
                        &inputLen);
        }

        if (dataPtr->dcs_of_text_string == MMI_UCS2_DCS)
        {
            dataPtr->no_text_string = (U8) inputLen - 2;
        }
        else
        {
            dataPtr->no_text_string = (U8) inputLen - 1;
        }

        memcpy(dataPtr->text_string, input, dataPtr->no_text_string);
        OslMfree(input);

    #ifdef __USAT__
        dataPtr->duration = mmi_sat_count_get_inkey_user_rsp();
    #endif 

        Message->oslDataPtr = (oslParaType*) dataPtr;
        Message->oslPeerBuffPtr = NULL;
        SEND_MSG(Message);
        gSATContext.lastSATCmd = SAT_NONE_CMD;
        SATPleaseWaitScreen(SAT_WAIT_STRING_ID, SAT_WAIT_IMAGE_ID);
    }
    else
    {
        /* display at least necessary input length */
        mmi_ucs2cpy((PS8) display_info, (PS8) get_string(SAT_GET_INPUT_LENGTH_NOT_ENOUGH));
        kal_wsprintf((PU16) temp_info, ": %d", 1);
        mmi_ucs2cat((PS8) display_info, (PS8)temp_info);

        DisplayPopup(
            display_info,
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        DeleteScreenIfPresent(SAT_SCR_INPUT_METHOD_AND_DONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  TerminalResponseGetInkeyYes
 * DESCRIPTION
 *  Key Handler of Send Key of Get Inkey Screen if Yes/No Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseGetInkeyYes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TerminalResponseGetInkey(SAT_CMD_PERFORMED_SUCCESSFULLY, TRUE, gSATGetInkey.cmdDetail);
    SATPleaseWaitScreen(SAT_WAIT_STRING_ID, SAT_WAIT_IMAGE_ID);
}


/*****************************************************************************
 * FUNCTION
 *  TerminalResponseGetInkeyNo
 * DESCRIPTION
 *  Key Handler of Send Key of Get Inkey Screen id Yes/No Scree
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseGetInkeyNo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TerminalResponseGetInkey(SAT_CMD_PERFORMED_SUCCESSFULLY, FALSE, gSATGetInkey.cmdDetail);
    SATPleaseWaitScreen(SAT_WAIT_STRING_ID, SAT_WAIT_IMAGE_ID);
}


/*****************************************************************************
 * FUNCTION
 *  TerminalResponseGetInkeyMoveBack
 * DESCRIPTION
 *  Key Handler of RSK of Get Inkey Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseGetInkeyMoveBack(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TerminalResponseGetInkey(SAT_BACKWARD_MOVE_IN_PROACTIVE_SESSION_BY_USER, FALSE, gSATGetInkey.cmdDetail);
    SATPleaseWaitScreen(SAT_WAIT_STRING_ID, SAT_WAIT_IMAGE_ID);
}


/*****************************************************************************
 * FUNCTION
 *  TerminalResponseGetInkeyHelp
 * DESCRIPTION
 *  Key Handler of Hot Key of Get Inkey Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseGetInkeyHelp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TerminalResponseGetInkey(SAT_HELP_INFO_REQUEST_BY_USER, FALSE, gSATGetInkey.cmdDetail);
    SATPleaseWaitScreen(SAT_WAIT_STRING_ID, SAT_WAIT_IMAGE_ID);
}


/*****************************************************************************
 * FUNCTION
 *  TerminalResponseGetInkeyExpire
 * DESCRIPTION
 *  Key Handler of End Key of Get Inkey Screen if noy Yes/No Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseGetInkeyExpire(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TerminalResponseGetInkey(SAT_PROACTIVE_CMD_TERMINATED_BY_USER, FALSE, gSATGetInkey.cmdDetail);
    ExitSATToIdle();
}


/*****************************************************************************
 * FUNCTION
 *  TerminalResponseGetInkey
 * DESCRIPTION
 *  Send GET INKEY REQ to L4
 * PARAMETERS
 *  res             [IN]    Response type
 *  isYesSelected   [IN]    Is Yes Selected on Get Inkey Screen (TRUE/FALSE)
 *  cmdDetail       [IN]    Cmd detail to be sent
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseGetInkey(U8 res, U8 isYesSelected, U8 *cmdDetail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    mmi_sat_get_inkey_res_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gSATGetInkey.sentRsp = 1;
    StopSATTimerNoResponsefromUser();
    gSATContext.noResponseFuncPtr = NULL;   /* diamond, 2005/07/25 SAT timer */

    Message = ALLOCATE_ITM(MOD_MMI);
    Message->oslSrcId = MOD_MMI;
    Message->oslMsgId = PRT_MMI_SAT_GET_INKEY_RES_REQ;
    dataPtr = (mmi_sat_get_inkey_res_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_get_inkey_res_req_struct));
    dataPtr->res = res;
    dataPtr->is_yes_selected = isYesSelected;
    memcpy(dataPtr->cmd_detail, (void*)cmdDetail, 5 * sizeof(U8));
    dataPtr->no_text_string = 0;
    dataPtr->dcs_of_text_string = 0;
    dataPtr->text_string[0] = 0;
#ifdef __USAT__
    dataPtr->duration = mmi_sat_count_get_inkey_user_rsp();
#endif 
    Message->oslDataPtr = (oslParaType*) dataPtr;
    Message->oslPeerBuffPtr = NULL;
    SEND_MSG(Message);
    gSATContext.lastSATCmd = SAT_NONE_CMD;
}


/*****************************************************************************
 * FUNCTION
 *  SATGetInkeyRsp
 * DESCRIPTION
 *  Protocol Handler for GET INKEY RES
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATGetInkeyRsp(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FreeGetInkey();
}


/*****************************************************************************
 * FUNCTION
 *  FreeGetInkey
 * DESCRIPTION
 *  Frees various elements of Get Inkey Structure.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FreeGetInkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SATClearAllIcons();
    if (gSATGetInkey.textString)
    {
        OslMfree(gSATGetInkey.textString);
        gSATGetInkey.textString = NULL;
    }

#ifdef __USAT__
    if (gSATGetInkey.textFormatting)
    {
        OslMfree(gSATGetInkey.textFormatting);
    }
    gSATGetInkey.noTextAttribute = 0;
    gSATGetInkey.textFormatting = NULL;
#endif /* __USAT__ */ 
}


#define MMI_SAT_SETUP_CALL
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
/*****************************************************************************
 * FUNCTION
 *  TerminalResponseCallSetupEx
 * DESCRIPTION
 *  Send CALL SETUP STAGE 2 REQ to L4 or L4_2 by destId
 * PARAMETERS
 *  destId      [IN]    L4/L4_2
 *  res         [IN]    Response type
 *  addInfo     [IN]    Additional info
 *  cmdDetail   [IN]    Cmd detail to be sent
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseCallSetupEx(U8 destId, U8 res, U8 addInfo, U8 *cmdDetail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    mmi_sat_call_setup_stage2_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message = allocate_ilm(MOD_MMI);
    Message->oslSrcId = MOD_MMI;
    Message->oslDestId = destId;
    Message->oslMsgId = PRT_MMI_SAT_CALL_SETUP_STAGE2_REQ;
    dataPtr =
        (mmi_sat_call_setup_stage2_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_call_setup_stage2_req_struct));
    dataPtr->res = res;
    dataPtr->cause = addInfo;
    memcpy(dataPtr->cmd_detail, (void*)cmdDetail, 5 * sizeof(U8));
    Message->oslDataPtr = (oslParaType*) dataPtr;
    Message->oslPeerBuffPtr = NULL;
    Message->sap_id = INVALID_SAP;
    msg_send_ext_queue(Message);
}


/*****************************************************************************
 * FUNCTION
 *  SATCallSetupSIM1Ind
 * DESCRIPTION
 *  Protocol Handler for CALL SETUP IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4-1
 * RETURNS
 *  void
 *****************************************************************************/
void SATCallSetupSIM1Ind(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_call_setup_ind_struct *callSetupInd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    callSetupInd = (mmi_sat_call_setup_ind_struct*) msgPtr;

    if (gSATContext.CMDfromSIM == SAT_CMD_SIM2)
    {
        TerminalResponseCallSetupEx(MOD_L4C, SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, 0, callSetupInd->cmd_detail);
    }
    else
    {
        gSATContext.CMDfromSIM = SAT_CMD_SIM1;
        SATCallSetupInd(msgPtr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  SATCallSetupSIM2Ind
 * DESCRIPTION
 *  Protocol Handler for CALL SETUP IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4-2
 * RETURNS
 *  void
 *****************************************************************************/
void SATCallSetupSIM2Ind(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_call_setup_ind_struct *callSetupInd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    callSetupInd = (mmi_sat_call_setup_ind_struct*) msgPtr;

    if (gSATContext.CMDfromSIM == SAT_CMD_SIM1)
    {
        TerminalResponseCallSetupEx(MOD_L4C_2, SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, 0, callSetupInd->cmd_detail);
    }
    else
    {
        gSATContext.CMDfromSIM = SAT_CMD_SIM2;
        SATCallSetupInd(msgPtr);
    }
}

#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */


/*****************************************************************************
 * FUNCTION
 *  SATCallSetupInd
 * DESCRIPTION
 *  Protocol Handler for CALL SETUP IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATCallSetupInd(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_call_setup_ind_struct *callSetupInd;
    pBOOL result;
    U8 *asciiNumber;
    U8 *number;
    U16 numLength;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    callSetupInd = (mmi_sat_call_setup_ind_struct*) msgPtr;

    FreeCallSetup();

    gSATContext.lastSATCmd = SAT_CALL_SETUP_CMD;
    gSATContext.guiBufferPointer = NULL;

    if (isIncomingCall() || isOutgoingCall())
    {
        TerminalResponseCallSetup(SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, 0, callSetupInd->cmd_detail);
        return;
    }

    if (isInCall() && (callSetupInd->condition == SETUP_CALL_IF_NO_ANOTHER_CALL || callSetupInd->condition == SETUP_CALL_WITH_REDIAL_IF_NO_ANOTHER_CALL))
    {
        TerminalResponseCallSetup(SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, SAT_ME_CURRENTLY_BUSY_ON_CALL, callSetupInd->cmd_detail);
        return;
    }

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    if (gSATContext.CMDfromSIM == SAT_CMD_SIM2)
    {
        result = mmi_bootup_is_sim2_nw_registration_ok();
    }
    else
    {
        result = mmi_bootup_is_nw_registration_ok();
    }
#else /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
    result = mmi_bootup_is_nw_registration_ok();
#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
    if (result == MMI_FALSE)
    {
        TerminalResponseCallSetup(SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, 0, callSetupInd->cmd_detail);
        return;
    }

    if (!CHECK_MO_ALLOW())
    {
        ChgrPlayLowBatTone();
        BatteryIndicationPopup(STR_LOW_BATTERY_MT_PROHIBIT);
        TerminalResponseCallSetup(SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, 0, callSetupInd->cmd_detail);
        return;
    }
    else
    {
        SATStopWaitTimer();
    }

    if (IS_LOW_BATTERY())
    {
        ChgrPlayLowBatTone();
        if (g_charbat_context.LowBatteryTxProhibitFlag)
        {
            SET_LOW_BATTERY_ALARM_THRESHOLD(LBAT_TALK_DURCNT_PROHIBIT);
        }
        else
        {
            SET_LOW_BATTERY_ALARM_THRESHOLD(LBAT_TALK_DURCNT_NORMAL);
        }
    }

    memcpy(gSATCallSetup.cmdDetail, callSetupInd->cmd_detail, 5 * sizeof(U8));

    gSATCallSetup.typeOfModification = callSetupInd->type_of_modification;
    gSATCallSetup.duration = callSetupInd->duration;
    gSATCallSetup.condition = callSetupInd->condition;
    
    gSATCallSetup.noAddr = callSetupInd->no_addr;
    if (gSATCallSetup.noAddr > 41)
    {
        gSATCallSetup.noAddr = 41;
    }
    memcpy(gSATCallSetup.addr, callSetupInd->addr, gSATCallSetup.noAddr);

    gSATCallSetup.noSubaddr = callSetupInd->size_of_subaddr;
    if (gSATCallSetup.noSubaddr > 21)
    {
        gSATCallSetup.noSubaddr = 21;
    }
    memcpy(gSATCallSetup.subAddr, callSetupInd->subaddr, gSATCallSetup.noSubaddr);

    gSATCallSetup.noCcp = callSetupInd->size_of_ccp;
    if (gSATCallSetup.noCcp > 15)
    {
        gSATCallSetup.noCcp = 15;
    }
    memcpy(gSATCallSetup.ccp, callSetupInd->ccp, gSATCallSetup.noCcp);

    asciiNumber = ConvertBCDToString(gSATCallSetup.addr, (U16) gSATCallSetup.noAddr, &numLength);
    number = CovertStringForPlatform(asciiNumber, (U16) strlen((PS8) asciiNumber), MMI_8BIT_DCS, NULL);
    OslMfree(asciiNumber);
    gSATCallSetup.number = number;

    gSATCallSetup.alphaId1Present = 0;
    if (callSetupInd->is_alpha_id1_present)
    {
        if (callSetupInd->no_alpha_id1)
        {
            gSATCallSetup.noAlphaId1 = callSetupInd->no_alpha_id1;
            gSATCallSetup.dcsOfAlphaId1 = callSetupInd->dcs_of_alpha_id1;
            gSATCallSetup.alphaId1 = CovertStringForPlatform(
                                        callSetupInd->alpha_id1,
                                        gSATCallSetup.noAlphaId1,
                                        gSATCallSetup.dcsOfAlphaId1,
                                        &gSATCallSetup.noAlphaId1);
            gSATCallSetup.alphaId1Present = 1;
        }
    }
    if (!gSATCallSetup.alphaId1Present)
    {
        gSATCallSetup.noAlphaId1 = mmi_ucs2strlen((PS8) (PU8) GetString(SAT_SETUP_CALL_CONF_STRING_ID)) * ENCODING_LENGTH;
        gSATCallSetup.alphaId1 = (PU8) OslMalloc(gSATCallSetup.noAlphaId1 + ENCODING_LENGTH);
        memcpy(
            gSATCallSetup.alphaId1,
            (PU8) GetString(SAT_SETUP_CALL_CONF_STRING_ID),
            gSATCallSetup.noAlphaId1 + ENCODING_LENGTH);
    }

    gSATCallSetup.alphaId2Present = 0;
    if (callSetupInd->is_alpha_id2_present)
    {
        if (callSetupInd->no_alpha_id2)
        {
            gSATCallSetup.noAlphaId2 = callSetupInd->no_alpha_id2;
            gSATCallSetup.dcsOfAlphaId2 = callSetupInd->dcs_of_alpha_id2;
            gSATCallSetup.alphaId2 = CovertStringForPlatform(
                                        callSetupInd->alpha_id2,
                                        gSATCallSetup.noAlphaId2,
                                        gSATCallSetup.dcsOfAlphaId2,
                                        &gSATCallSetup.noAlphaId2);
            gSATCallSetup.alphaId2Present = 1;
        }
    }
    if (!gSATCallSetup.alphaId2Present)
    {
        gSATCallSetup.noAlphaId2 = 0;
        gSATCallSetup.dcsOfAlphaId2 = 0;
        gSATCallSetup.alphaId2 = NULL;
    }

    gSATCallSetup.isIcon1Available = callSetupInd->is_icon1_available;
    if (gSATCallSetup.isIcon1Available)
    {
        gSATCallSetup.iconInfo1.iconId = callSetupInd->icon_info1.icon_id;
        gSATCallSetup.iconInfo1.iconAttr = callSetupInd->icon_info1.icon_attr;
    }

    gSATCallSetup.isIcon2Available = callSetupInd->is_icon2_available;
    if (gSATCallSetup.isIcon2Available)
    {
        gSATCallSetup.iconInfo2.iconId = callSetupInd->icon_info2.icon_id;
        gSATCallSetup.iconInfo2.iconAttr = callSetupInd->icon_info2.icon_attr;
    }

    if (gSATCallSetup.isIcon1Available && gSATCallSetup.iconInfo1.iconAttr == SAT_ICON_SELF_EX)
    {
        if (gSATCallSetup.alphaId1)
        {
            OslMfree(gSATCallSetup.alphaId1);
            gSATCallSetup.alphaId1 = NULL;
        }
    }

    if (gSATCallSetup.isIcon2Available && gSATCallSetup.iconInfo2.iconAttr == SAT_ICON_SELF_EX)
    {
        if (gSATCallSetup.alphaId2)
        {
            OslMfree(gSATCallSetup.alphaId2);
            gSATCallSetup.alphaId2 = NULL;
        }
    }

    DeleteScreenIfPresent(SCR_ID_SAT_HISTORY);
    if (GetExitScrnID() == SCR_ID_SAT_HISTORY)
    {
        ClearExitHandler();
    }
    GoToCallConformationScreen();
}


/*****************************************************************************
 * FUNCTION
 *  GoToCallConformationScreen
 * DESCRIPTION
 *  Displays Call Conformation Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoToCallConformationScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *iconData = NULL;
    GDI_HANDLE temp_layer;
    GDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gSATCallSetup.isIcon1Available)
    {
        SATAddIconIDToList(gSATCallSetup.iconInfo1.iconId);
    }

    if (gSATCallSetup.isIcon2Available)
    {
        SATAddIconIDToList(gSATCallSetup.iconInfo2.iconId);
    }

    if (gSATCallSetup.isIcon1Available || gSATCallSetup.isIcon2Available)
    {
        if (!SATCheckAllIconGot())
        {
            SATGetIconCompleteCallBack = GoToCallConformationScreen;
            SATGetIconDataToList();
            return;
        }

        if (gSATCallSetup.isIcon2Available)
        {
            /* save icon to file for CM's reference */
            iconData = SATGetIconFromList(gSATCallSetup.iconInfo2.iconId);

            ret = gdi_layer_create_cf_using_outside_memory(
		              GDI_COLOR_FORMAT_16,
		              0,
		              0,
		              *(iconData + 8),
		              *(iconData + 12),
		              &temp_layer,
		              iconData + 8 + 13,
		              (*(iconData + 8)) * (*(iconData + 12)) * 2);

            MMI_ASSERT(ret == GDI_SUCCEED);

            ret = gdi_layer_save_pbm_file(temp_layer, (PS8) SAT_ICON2_FILEPATH);
            gdi_layer_free(temp_layer);

            if (ret != GDI_SUCCEED)
            {
                gSATCallSetup.isIcon2Available = 0; /* prevent from save file error */
            }
        }
    }

    iconData = SATGetIconFromList(gSATCallSetup.iconInfo1.iconId);
    gSATContext.exitCondition = &gSATCallSetup.passedConfirmScreen;
    EntryNewScreen(SCR_ID_SAT_CMCALLBACK, SATGenericExitHandler, NULL, NULL);

    SetIsInSATScreen();
    gSATContext.historyFuncPtr = GoToCallConformationScreen;
    gSATCallSetup.passedConfirmScreen = 0;
    ShowCategory151Screen(
        0,
        0,
        STR_GLOBAL_YES,
        0,
        STR_GLOBAL_NO,
        0,
        gSATCallSetup.alphaId1,
        iconData,
        gSATContext.guiBufferPointer);

    SetKeyHandler(TerminalResponseCallSetupExpire, KEY_END, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(SATCallSetupTerminalResponseMoveBack, KEY_EVENT_UP);
#ifdef __MMI_UCM__
    SetLeftSoftkeyFunction(mmi_sat_call_setup_ucm_request, KEY_EVENT_UP);
    SetKeyHandler(mmi_sat_call_setup_ucm_request, KEY_SEND, KEY_EVENT_UP);
#else /* __MMI_UCM__ */
    SetLeftSoftkeyFunction(SATCallSetupStage1Req, KEY_EVENT_UP);
    SetKeyHandler(SATCallSetupStage1Req, KEY_SEND, KEY_EVENT_UP);
#endif /* __MMI_UCM__ */
}


/*****************************************************************************
 * FUNCTION
 *  TerminalResponseCallSetupExpire
 * DESCRIPTION
 *  Key Handler of End Key of Call Conformation Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseCallSetupExpire(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TerminalResponseCallSetup(SAT_PROACTIVE_CMD_TERMINATED_BY_USER, 0, gSATCallSetup.cmdDetail);
    ExitSATToIdle();
}


/*****************************************************************************
 * FUNCTION
 *  SATCallSetupTerminalResponseMoveBack
 * DESCRIPTION
 *  Key Handler of RSK Key of Call Conformation Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SATCallSetupTerminalResponseMoveBack(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TerminalResponseCallSetup(SAT_USER_DID_NOT_ACCEPT_THE_PROACTIVE_CMD, 0, gSATCallSetup.cmdDetail);
    SATPleaseWaitScreen(SAT_WAIT_STRING_ID, SAT_WAIT_IMAGE_ID);
}


/*****************************************************************************
 * FUNCTION
 *  TerminalResponseCallSetup
 * DESCRIPTION
 *  Send CALL SETUP STAGE 2 REQ to L4
 * PARAMETERS
 *  res         [IN]    Response type
 *  addInfo     [IN]    Additional info
 *  cmdDetail   [IN]    Cmd detail to be sent
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseCallSetup(U8 res, U8 addInfo, U8 *cmdDetail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    mmi_sat_call_setup_stage2_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gSATCallSetup.isSentRsp = 1;
    gSATCallSetup.passedConfirmScreen = 1;

    Message = ALLOCATE_ITM(MOD_MMI);
    Message->oslSrcId = MOD_MMI;
    Message->oslMsgId = PRT_MMI_SAT_CALL_SETUP_STAGE2_REQ;
    dataPtr =
        (mmi_sat_call_setup_stage2_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_call_setup_stage2_req_struct));

    /* diamond, 2005/05/24 icon */
    if (res == SAT_CMD_PERFORMED_SUCCESSFULLY && gSATCallSetup.isIcon1Available == 1 &&
        gSATContext.isCMDIconSupported == MMI_FALSE)
    {
        dataPtr->res = SAT_CMD_PERFORMED_BUT_ICON_COULD_NOT_DSPL;
    }
    else
    {
        /* end, diamond */
        dataPtr->res = res;
    }
    dataPtr->cause = addInfo;

    memcpy(dataPtr->cmd_detail, (void*)cmdDetail, 5 * sizeof(U8));
    Message->oslDataPtr = (oslParaType*) dataPtr;
    Message->oslPeerBuffPtr = NULL;
    SEND_MSG(Message);
    gSATContext.lastSATCmd = SAT_NONE_CMD;
}


/*****************************************************************************
 * FUNCTION
 *  SATCallSetupStage1Req
 * DESCRIPTION
 *  Send CALL SETUP STAGE 1 REQ to L4.
 *  Key Handler of LSK Key of Call Conformation Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SATCallSetupStage1Req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_call_setup_stage1_req_struct *dataPtr;
    MYQUEUE *Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gSATCallSetup.passedConfirmScreen = 1;
    gSATContext.isInSATCall = 1;

    Message = ALLOCATE_ITM(MOD_MMI);
    Message->oslSrcId = MOD_MMI;
    Message->oslMsgId = PRT_MMI_SAT_CALL_SETUP_STAGE1_REQ;
    dataPtr =
        (mmi_sat_call_setup_stage1_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_call_setup_stage1_req_struct));

    dataPtr->type_of_modification = gSATCallSetup.typeOfModification;
    dataPtr->sat_call_type = gSATCallSetup.condition;

    dataPtr->no_addr = gSATCallSetup.noAddr;
    memcpy(dataPtr->addr, gSATCallSetup.addr, gSATCallSetup.noAddr);
    dataPtr->no_ccp = gSATCallSetup.noCcp;
    memcpy(dataPtr->ccp, gSATCallSetup.ccp, gSATCallSetup.noCcp);
    dataPtr->no_sub_addr = gSATCallSetup.noSubaddr;
    memcpy(dataPtr->sub_addr, gSATCallSetup.subAddr, gSATCallSetup.noSubaddr);

    Message->oslDataPtr = (oslParaType*) dataPtr;
    Message->oslPeerBuffPtr = NULL;
    SEND_MSG(Message);
    gSATCallSetup.isFromHistory = 0;
    gSATCallSetup.isSentRsp = 0;
#ifndef __MMI_UCM__
    if (gSATCallSetup.condition == SETUP_CALL_PUT_ANOTHER_HOLD ||
        gSATCallSetup.condition == SETUP_CALL_WITH_REDIAL_PUT_ANOTHER_HOLD)
    {
        MakeHold();
        SetCurrentState(CM_HOLD_STATE);
    }
#endif /* __MMI_UCM__ */
    SATCMCallBackScreen();
}


/*****************************************************************************
 * FUNCTION
 *  SATCMCallBackScreen
 * DESCRIPTION
 *  Screen called from history when the contol returns to
 *  SAT Application from CM.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SATCMCallBackScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* diamond, 2006/05/26 Prevent from small screen */
#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    if (mmi_is_redrawing_bk_screens())
    {
        EntryNewScreen(SCR_ID_SAT_CMCALLBACK, SATCMCallBackScreenExitHandler, SATCMCallBackScreen, NULL);
        ShowCategory9Screen(SAT_WAIT_STRING_ID, SAT_WAIT_IMAGE_ID, NULL);
        return;
    }
#endif /* __MMI_UI_SMALL_SCREEN_SUPPORT__ */

    SetIsInSATScreen();

    if (!gSATCallSetup.isFromHistory)
    {
        EntryNewScreen(SCR_ID_SAT_CMCALLBACK, SATCMCallBackScreenExitHandler, SATCMCallBackScreen, NULL);

        ClearHighlightHandler();
        ShowCategory9Screen(SAT_WAIT_STRING_ID, SAT_WAIT_IMAGE_ID, NULL);

        if (mmi_ucs2strlen((PS8) gSATCallSetup.number) * 2 > MAX_NUMBER)
        {
            /* test case 27.22.4.13 max display calling 40 digits to sync as the call from dial pad */
            *(gSATCallSetup.number + MAX_NUMBER - 2) = 0;
        }
    #ifdef __MMI_UCM__
        SetDelScrnIDCallbackHandler(SCR_ID_SAT_CMCALLBACK, (HistoryDelCBPtr) mmi_sat_call_setup_screen_delete_callback);
    #else
        ShowOutgoingIndicationScreen(gSATCallSetup.number);
    #endif
        gSATCallSetup.isFromHistory = 1;
    }
    else
    {
        gSATContext.isInSATCall = 0;
    #ifdef __MMI_UCM__
        SetDelScrnIDCallbackHandler(SCR_ID_SAT_CMCALLBACK, (HistoryDelCBPtr) NULL);
    #endif

        if (gSATCallSetup.isSentRsp)
        {
            gSATContext.waitString = SAT_WAIT_STRING_ID;
            gSATContext.waitImage = SAT_WAIT_IMAGE_ID;
            gSATContext.exitCondition = &gSATContext.waitTimeExpired;
            EntryNewScreen(SCR_ID_SAT_WAITSCREEN, SATGenericExitHandler, NULL, NULL);

            ClearHighlightHandler();
            ShowCategory9Screen(gSATContext.waitString, gSATContext.waitImage, NULL);
            SetKeyHandler(0, KEY_END, KEY_EVENT_DOWN);
            gSATContext.historyFuncPtr = PleaseWaitActualScreen;
            StartTimer(SAT_MESSAGE_WAIT_TIMER, 2000, SATMessageWaitTimer);
            gSATContext.waitTimeExpired = 0;
        }
        else
        {
            if (gSATCallSetup.exitCause == SAT_CALL_DISCONNECT_BEFORE_CONNECT)
            {
                TerminalResponseCallSetup(
                    SAT_USER_CLEAR_DOWN_CALL_BEFORE_CONNECTION_RELEASE,
                    0,
                    gSATCallSetup.cmdDetail);
                RemoveOutgoingIndicationScreen();
                SATPleaseWaitScreen(SAT_WAIT_STRING_ID, SAT_WAIT_IMAGE_ID);
            }
            else
            {
                TerminalResponseCallSetup(SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, 0, gSATCallSetup.cmdDetail);
                SATPleaseWaitScreen(SAT_WAIT_STRING_ID, SAT_WAIT_IMAGE_ID);
            }
        }
        gSATCallSetup.isFromHistory = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  SATCMCallBackScreenExitHandler
 * DESCRIPTION
 *  Exit Handler of CallBack Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SATCMCallBackScreenExitHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearIsInSATScreen();
}


/*****************************************************************************
 * FUNCTION
 *  SATCallExitCause
 * DESCRIPTION
 *  Function called by Call Management Application to
 *  convet to SAT Application the cause of Call End
 * PARAMETERS
 *  cause       [IN]    
 * RETURNS
 *  void
 *****************************************************************************/
void SATCallExitCause(U8 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gSATCallSetup.exitCause = cause;
}


/*****************************************************************************
 * FUNCTION
 *  SATGetCallDisplay
 * DESCRIPTION
 *  This is used by CM to get
 *  Display Information while in Call
 * PARAMETERS
 *  dcs     [OUT]       
 * RETURNS
 *  PU8
 *****************************************************************************/
PU8 SATGetCallDisplay(PU8 dcs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *dcs = gSATCallSetup.dcsOfAlphaId2;
    return gSATCallSetup.alphaId2;
}


/*****************************************************************************
 * FUNCTION
 *  SATCallRedialStatus
 * DESCRIPTION
 *  This is used by CM to indicate to Redial Status of SAT Call
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 SATCallRedialStatus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gSATCallSetup.condition == SETUP_CALL_WITH_REDIAL_IF_NO_ANOTHER_CALL ||
        gSATCallSetup.condition == SETUP_CALL_WITH_REDIAL_PUT_ANOTHER_HOLD ||
        gSATCallSetup.condition == SETUP_CALL_WITH_REDIAL_DISCON_ANOTHER)
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
 *  SATCallSetupStage1Rsp
 * DESCRIPTION
 *  Protocol Handler for SETUP CALL STAGE 1 RES
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATCallSetupStage1Rsp(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!gSATCallSetup.isSentRsp)
    {
        mmi_sat_call_setup_stage1_rsp_struct *callSetupStage1Res;

        callSetupStage1Res = (mmi_sat_call_setup_stage1_rsp_struct*) msgPtr;

        TerminalResponseCallSetup(
            callSetupStage1Res->terminal_res,
            callSetupStage1Res->additional_res,
            gSATCallSetup.cmdDetail);
        if ((callSetupStage1Res->terminal_res != SAT_CMD_PERFORMED_SUCCESSFULLY &&
             callSetupStage1Res->terminal_res != SAT_CMD_PERFORMED_WITH_PARTIAL_COMPREHENSION &&
             callSetupStage1Res->terminal_res != SAT_CMD_PERFORMED_WITH_MISSING_INFO) ||
            callSetupStage1Res->result.flag == L4C_ERROR)
        {
            RemoveOutgoingIndicationScreen();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  SATCallSetupStage2Rsp
 * DESCRIPTION
 *  Protocol Handler for SETUP CALL STAGE 2 RES
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATCallSetupStage2Rsp(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FreeCallSetup();
}


/*****************************************************************************
 * FUNCTION
 *  FreeCallSetup
 * DESCRIPTION
 *  Protocol Handler for SETUP CALL STAGE 2 RES
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FreeCallSetup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SATClearAllIcons();

    if (gSATCallSetup.alphaId1)
    {
        OslMfree(gSATCallSetup.alphaId1);
        gSATCallSetup.alphaId1 = NULL;
    }

    if (gSATCallSetup.alphaId2)
    {
        OslMfree(gSATCallSetup.alphaId2);
        gSATCallSetup.alphaId2 = NULL;
    }

    if (gSATCallSetup.number)
    {
        OslMfree(gSATCallSetup.number);
        gSATCallSetup.number = NULL;
    }

    if (gSATCallSetup.isIcon2Available)
    {
        FS_Delete((U16*) SAT_ICON2_FILEPATH);
    }
}


#define MMI_SAT_SEND_SMS
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
/*****************************************************************************
 * FUNCTION
 *  TerminalResponseSendSMS_2
 * DESCRIPTION
 *  Send SEND SMS STAGE2 REQ to L4 or L4_2 by destId
 * PARAMETERS
 *  destId      [IN]    L4/L4_2
 *  res         [IN]    Response type
 *  cause       [IN]    Returned in SEND SMS STAGE 1 RES
 *  cmdDetail   [IN]    Cmd detail to be sent
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseSendSMS_2(U8 destId, U8 res, U8 cause, U8 *cmdDetail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    mmi_sat_send_sms_stage2_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message = allocate_ilm(MOD_MMI);
    Message->oslSrcId = MOD_MMI;
    Message->oslDestId = destId;
    Message->oslMsgId = PRT_MMI_SAT_SEND_SMS_STAGE2_REQ;
    dataPtr = (mmi_sat_send_sms_stage2_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_send_sms_stage2_req_struct));
    dataPtr->res = res;
    dataPtr->cause = cause;
    memcpy(dataPtr->cmd_detail, cmdDetail, 5 * sizeof(U8));
    Message->oslDataPtr = (oslParaType*) dataPtr;
    Message->oslPeerBuffPtr = NULL;
    Message->sap_id = INVALID_SAP;
    msg_send_ext_queue(Message);
}


/*****************************************************************************
 * FUNCTION
 *  SATSendSMSSIM1Ind
 * DESCRIPTION
 *  Protocol Handler for SEND SMS IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4-1
 * RETURNS
 *  void
 *****************************************************************************/
void SATSendSMSSIM1Ind(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_send_sms_ind_struct *sendSMSInd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sendSMSInd = (mmi_sat_send_sms_ind_struct*) msgPtr;

    if (gSATContext.CMDfromSIM == SAT_CMD_SIM2)
    {
        TerminalResponseSendSMS_2(MOD_L4C, SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, 0, sendSMSInd->cmd_detail);
    }
    else
    {
        gSATContext.CMDfromSIM = SAT_CMD_SIM1;
        SATSendSMSInd(msgPtr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  SATSendSMSSIM2Ind
 * DESCRIPTION
 *  Protocol Handler for SEND SMS IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4-2
 * RETURNS
 *  void
 *****************************************************************************/
void SATSendSMSSIM2Ind(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_send_sms_ind_struct *sendSMSInd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sendSMSInd = (mmi_sat_send_sms_ind_struct*) msgPtr;

    if (gSATContext.CMDfromSIM == SAT_CMD_SIM1)
    {
        TerminalResponseSendSMS_2(MOD_L4C_2, SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, 0, sendSMSInd->cmd_detail);
    }
    else
    {
        gSATContext.CMDfromSIM = SAT_CMD_SIM2;
        SATSendSMSInd(msgPtr);
    }
}

#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */


/*****************************************************************************
 * FUNCTION
 *  SATSendSMSInd
 * DESCRIPTION
 *  Protocol Handler for SEND SMS IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATSendSMSInd(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_send_sms_ind_struct *sendSMSInd;
    pBOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sendSMSInd = (mmi_sat_send_sms_ind_struct*) msgPtr;

    FreeSendSms();

    gSATContext.lastSATCmd = SAT_SEND_SMS_CMD;
    gSATContext.guiBufferPointer = NULL;
    gSATSendSMS.stage1Res = 0;

    /* diamond, 2006/05/14 Not launch SEND SMS in call */
    if (isIncomingCall() || isOutgoingCall())
    {
        TerminalResponseSendSMS(SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, 0, sendSMSInd->cmd_detail);
        return;
    }

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    if (gSATContext.CMDfromSIM == SAT_CMD_SIM2)
    {
        result = mmi_bootup_is_sim2_nw_registration_ok();
    }
    else
    {
        result = mmi_bootup_is_nw_registration_ok();
    }
#else /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
    result = mmi_bootup_is_nw_registration_ok();
#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
    if (result == MMI_FALSE)
    {
        TerminalResponseSendSMS(SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, 0, sendSMSInd->cmd_detail);
        return;
    }

    memcpy(gSATSendSMS.cmdDetail, sendSMSInd->cmd_detail, 5 * sizeof(U8));

    gSATSendSMS.dcsOfAlphaId = sendSMSInd->dcs_of_alpha_id;
    gSATSendSMS.noAlphaId = sendSMSInd->no_alpha_id;
    if (sendSMSInd->is_alpha_id_present)
    {
        if (gSATSendSMS.noAlphaId)
        {
            gSATSendSMS.alphaId = CovertStringForPlatform(
                                    sendSMSInd->alpha_id,
                                    gSATSendSMS.noAlphaId,
                                    gSATSendSMS.dcsOfAlphaId,
                                    &gSATSendSMS.noAlphaId);
            gSATSendSMS.informUser = 1;
        }
        else
        {
            gSATSendSMS.informUser = 0;
        }
    }
    else
    {
        /* One china SIM would initiate another send sms if previous one failed. Remove inform user solves this problem */
        gSATSendSMS.informUser = 0;
    }

    gSATSendSMS.isSmsPackedRequired = sendSMSInd->is_sms_packed_required;
    gSATSendSMS.noAddr = sendSMSInd->size_of_addr;
    if (gSATSendSMS.noAddr <= 41)
    {
        memcpy(gSATSendSMS.addr, sendSMSInd->addr, gSATSendSMS.noAddr);
    }
    else
    {
        memcpy(gSATSendSMS.addr, sendSMSInd->addr, 41);
    }

    gSATSendSMS.tpduLength = sendSMSInd->no_sms_tpdu;
    if (gSATSendSMS.tpduLength <= 175)
    {
        memcpy(gSATSendSMS.tpdu, sendSMSInd->sms_tpdu, gSATSendSMS.tpduLength);
    }
    else
    {
        memcpy(gSATSendSMS.tpdu, sendSMSInd->sms_tpdu, 175);
    }

    gSATSendSMS.isIconAvailable = sendSMSInd->is_icon_available;
    if (gSATSendSMS.isIconAvailable)
    {
        gSATSendSMS.iconInfo.iconId = sendSMSInd->icon_info.icon_id;
        gSATSendSMS.iconInfo.iconAttr = sendSMSInd->icon_info.icon_attr;
    }

    if (gSATSendSMS.isIconAvailable && gSATSendSMS.iconInfo.iconAttr == SAT_ICON_SELF_EX)
    {
        if (gSATSendSMS.alphaId)
        {
            OslMfree(gSATSendSMS.alphaId);
            gSATSendSMS.alphaId = NULL;
        }
    }

    if (mmi_bootup_is_idle_screen_reached() == MMI_FALSE)
    {
        gSATSendSMS.informUser = 0;
    }

    if (gSATSendSMS.informUser)
    {
        SATStopWaitTimer();
        DeleteScreenIfPresent(SCR_ID_SAT_HISTORY);
        if (GetExitScrnID() == SCR_ID_SAT_HISTORY)
        {
            ClearExitHandler();
        }
        SATSendSMSStage1Req();
    }
    else
    {
        /* diamond, 2006/01/14 restart please wait timer if SEND SMS is running in the background */
        mmi_sat_restart_please_wait_timer(SAT_MESSAGE_WAIT_TIMER_DURATION * 2);
        SATSendSMSStage1Req();
    }
}


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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


/*****************************************************************************
 * FUNCTION
 *  SATSendSmsTerminalResponseExpire
 * DESCRIPTION
 *  Send Terminal Response  for Send SMS
 *  if END Key pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SATSendSmsTerminalResponseExpire(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TerminalResponseSendSMS(SAT_PROACTIVE_CMD_TERMINATED_BY_USER, 0, gSATSendSMS.cmdDetail);
    ExitSATToIdle();
}


/*****************************************************************************
 * FUNCTION
 *  SATSendSmsTerminalResponseUnable
 * DESCRIPTION
 *  Send Terminal Response for Send SMS
 *  when Unable to process command
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SATSendSmsTerminalResponseUnable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TerminalResponseSendSMS(SAT_BACKWARD_MOVE_IN_PROACTIVE_SESSION_BY_USER, 0, gSATSendSMS.cmdDetail);
    SATPleaseWaitScreen(SAT_WAIT_STRING_ID, SAT_WAIT_IMAGE_ID);
}


/*****************************************************************************
 * FUNCTION
 *  SATSendSMSStage1Req
 * DESCRIPTION
 *  Send SEND SMS STAGE1 REQ
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SATSendSMSStage1Req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    mmi_sat_send_sms_stage1_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gSATSendSMS.passedConf = 1;
    if (gSATSendSMS.informUser)
    {
        DisplaySMSWindow();
    }
    gSATContext.gotStage1Rsp = 0;

    Message = ALLOCATE_ITM(MOD_MMI);
    Message->oslSrcId = MOD_MMI;
    Message->oslMsgId = PRT_MMI_SAT_SEND_SMS_STAGE1_REQ;
    dataPtr = (mmi_sat_send_sms_stage1_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_send_sms_stage1_req_struct));
    dataPtr->is_sms_packed_required = gSATSendSMS.isSmsPackedRequired;
    dataPtr->no_addr = gSATSendSMS.noAddr;
    if (dataPtr->no_addr <= 41)
    {
        memcpy(dataPtr->addr, gSATSendSMS.addr, dataPtr->no_addr);
    }
    else
    {
        memcpy(dataPtr->addr, gSATSendSMS.addr, 41);
    }
    dataPtr->tpdu_length = gSATSendSMS.tpduLength;
    if (dataPtr->tpdu_length <= 175)
    {
        memcpy(dataPtr->tpdu, gSATSendSMS.tpdu, dataPtr->tpdu_length);
    }
    else
    {
        memcpy(dataPtr->tpdu, gSATSendSMS.tpdu, 175);
    }
    Message->oslDataPtr = (oslParaType*) dataPtr;
    Message->oslPeerBuffPtr = NULL;
    SEND_MSG(Message);
}


/*****************************************************************************
 * FUNCTION
 *  DisplaySMSWindow
 * DESCRIPTION
 *  Displays Sending SMS Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DisplaySMSWindow(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *iconData = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gSATSendSMS.isIconAvailable)
    {
        SATAddIconIDToList(gSATSendSMS.iconInfo.iconId);
    }

    if (gSATSendSMS.isIconAvailable)
    {
        if (!SATCheckAllIconGot())
        {
            SATGetIconCompleteCallBack = DisplaySMSWindow;
            SATGetIconDataToList();
            return;
        }
    }

    TurnOnBacklight(1);

    iconData = SATGetIconFromList(gSATSendSMS.iconInfo.iconId);
    gSATContext.exitCondition = &gSATSendSMS.stage1Res;
    EntryNewScreen(SCR_ID_SAT_SENDSMS, SATGenericExitHandler, NULL, NULL);

    SetIsInSATScreen();
    gSATContext.historyFuncPtr = DisplaySMSWindow;
    ClearHighlightHandler();
    ShowCategory151Screen(0, 0, 0, 0, 0, 0, gSATSendSMS.alphaId, iconData, gSATContext.guiBufferPointer);

    /* SetKeyHandler(ExitSATToIdle, KEY_END, KEY_EVENT_DOWN); */
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN); /* diamond, 2006/05/24 Not allow press END to idle on sending SMS screen */
}


/*****************************************************************************
 * FUNCTION
 *  SATSendSMSStage1Rsp
 * DESCRIPTION
 *  Protocol Handler for SEND SMS STAGE 1 RES
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATSendSMSStage1Rsp(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_send_sms_stage1_rsp_struct *sendSMSStage1Res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sendSMSStage1Res = (mmi_sat_send_sms_stage1_rsp_struct*) msgPtr;
    gSATSendSMS.stage1Res = 1;
    gSATContext.gotStage1Rsp = 1;

    if (gSATContext.lastSATCmd == SAT_NONE_CMD)
    {
        return;
    }

    TerminalResponseSendSMS(sendSMSStage1Res->res, (U8) sendSMSStage1Res->cause, gSATSendSMS.cmdDetail);
    if (gSATSendSMS.informUser)
    {
        SATPleaseWaitScreen(SAT_WAIT_STRING_ID, SAT_WAIT_IMAGE_ID);
    #if 0 /* spec says: If an alpha identifier was provided by SIM, ME should not give any information to the user at the reception of SMS RP-ACK or RP-Error */
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
    }
}


/*****************************************************************************
 * FUNCTION
 *  TerminalResponseSendSMS
 * DESCRIPTION
 *  Send SEND SMS STAGE2 REQ to L4
 * PARAMETERS
 *  res         [IN]    Response type
 *  cause       [IN]    Returned in SEND SMS STAGE 1 RES
 *  cmdDetail   [IN]    Cmd detail to be sent
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseSendSMS(U8 res, U8 cause, U8 *cmdDetail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    mmi_sat_send_sms_stage2_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gSATSendSMS.passedConf = 1;

    Message = ALLOCATE_ITM(MOD_MMI);
    Message->oslSrcId = MOD_MMI;
    Message->oslMsgId = PRT_MMI_SAT_SEND_SMS_STAGE2_REQ;
    dataPtr = (mmi_sat_send_sms_stage2_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_send_sms_stage2_req_struct));

    /* diamond, 2005/05/24 icon */
    if (res == SAT_CMD_PERFORMED_SUCCESSFULLY && gSATSendSMS.isIconAvailable == 1 &&
        gSATContext.isCMDIconSupported == MMI_FALSE)
    {
        dataPtr->res = SAT_CMD_PERFORMED_BUT_ICON_COULD_NOT_DSPL;
    }
    else
    {
        /* end, diamond */
        dataPtr->res = res;
    }

    dataPtr->cause = cause;
    memcpy(dataPtr->cmd_detail, cmdDetail, 5 * sizeof(U8));
    Message->oslDataPtr = (oslParaType*) dataPtr;
    Message->oslPeerBuffPtr = NULL;
    SEND_MSG(Message);
    gSATContext.lastSATCmd = SAT_NONE_CMD;
}


/*****************************************************************************
 * FUNCTION
 *  SATSendSMSStage2Rsp
 * DESCRIPTION
 *  Protocol Handler for SEND SMS STAGE 2 RES
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATSendSMSStage2Rsp(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FreeSendSms();
}


/*****************************************************************************
 * FUNCTION
 *  FreeSendSms
 * DESCRIPTION
 *  Frees various elements of Send SMS Structure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FreeSendSms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SATClearAllIcons();
    if (gSATSendSMS.alphaId)
    {
        OslMfree(gSATSendSMS.alphaId);
        gSATSendSMS.alphaId = NULL;
    }
}


#define MMI_SAT_SEND_SS
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
/*****************************************************************************
 * FUNCTION
 *  TerminalResponseSendSS_2
 * DESCRIPTION
 *  Send SEND SS STAGE2 REQ to L4 or L4_2 by destId
 * PARAMETERS
 *  destId      [IN]    L4/L4_2
 *  res         [IN]    Response type
 *  len         [IN]    Len of additional info, returned in SEND SS STAGE 1 RES
 *  info        [IN]    Additional info, returned in SEND SS STAGE 1 RES
 *  cmdDetail   [IN]    Cmd detail to be sent
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseSendSS_2(U8 destId, U8 res, U8 len, U8 *info, U8 *cmdDetail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    mmi_sat_send_ss_stage2_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message = allocate_ilm(MOD_MMI);
    Message->oslSrcId = MOD_MMI;
    Message->oslDestId = destId;
    Message->oslMsgId = PRT_MMI_SAT_SEND_SS_STAGE2_REQ;
    dataPtr = (mmi_sat_send_ss_stage2_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_send_ss_stage2_req_struct));
    dataPtr->res = res;
    dataPtr->size_of_additional_info = len;
    if (dataPtr->size_of_additional_info > 255)
    {
        dataPtr->size_of_additional_info = 255;
    }
    memcpy(dataPtr->additional_info, info, dataPtr->size_of_additional_info);
    memcpy(dataPtr->cmd_detail, (void*)cmdDetail, 5 * sizeof(U8));
    Message->oslDataPtr = (oslParaType*) dataPtr;
    Message->oslPeerBuffPtr = NULL;
    Message->sap_id = INVALID_SAP;
    msg_send_ext_queue(Message);
}


/*****************************************************************************
 * FUNCTION
 *  SATSendSSSIM1Ind
 * DESCRIPTION
 *  Protocol Handler for SEND SS IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4-1
 * RETURNS
 *  void
 *****************************************************************************/
void SATSendSSSIM1Ind(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_send_ss_ind_struct *sendSSInd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sendSSInd = (mmi_sat_send_ss_ind_struct*) msgPtr;

    if (gSATContext.CMDfromSIM == SAT_CMD_SIM2)
    {
        TerminalResponseSendSS_2(MOD_L4C, SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, 0, NULL, sendSSInd->cmd_detail);
    }
    else
    {
        gSATContext.CMDfromSIM = SAT_CMD_SIM1;
        SATSendSSInd(msgPtr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  SATSendSSSIM2Ind
 * DESCRIPTION
 *  Protocol Handler for SEND SS IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4-2
 * RETURNS
 *  void
 *****************************************************************************/
void SATSendSSSIM2Ind(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_send_ss_ind_struct *sendSSInd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sendSSInd = (mmi_sat_send_ss_ind_struct*) msgPtr;

    if (gSATContext.CMDfromSIM == SAT_CMD_SIM1)
    {
        TerminalResponseSendSS_2(MOD_L4C_2, SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, 0, NULL, sendSSInd->cmd_detail);
    }
    else
    {
        gSATContext.CMDfromSIM = SAT_CMD_SIM2;
        SATSendSSInd(msgPtr);
    }
}

#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */


/*****************************************************************************
 * FUNCTION
 *  SATSendSSInd
 * DESCRIPTION
 *  Protocol Handler for SEND SS IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATSendSSInd(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_send_ss_ind_struct *sendSSInd;
    pBOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sendSSInd = (mmi_sat_send_ss_ind_struct*) msgPtr;

    FreeSendSS();

    gSATContext.lastSATCmd = SAT_SEND_SS_CMD;
    gSATContext.guiBufferPointer = NULL;
    gSATSendSS.stage1Res = 0;

    if (sendSSInd->is_icon_available && sendSSInd->icon_info.icon_attr != SAT_ICON_SELF_EX && !sendSSInd->is_alpha_id_present)
    {
        TerminalResponseSendSS(SAT_CMD_DATA_NOT_UNDERSTAND_BY_ME, 0, NULL, sendSSInd->cmd_detail);
        return;
    }

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    if (gSATContext.CMDfromSIM == SAT_CMD_SIM2)
    {
        result = mmi_bootup_is_sim2_nw_registration_ok();
    }
    else
    {
        result = mmi_bootup_is_nw_registration_ok();
    }
#else /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
    result = mmi_bootup_is_nw_registration_ok();
#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
    if (result == MMI_FALSE)
    {
        TerminalResponseSendSS(SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, 0, NULL, sendSSInd->cmd_detail);
        return;
    }

    gSATSendSS.dcsOfAlphaId = sendSSInd->dcs_of_alpha_id;
    gSATSendSS.noAlphaId = sendSSInd->no_alpha_id;
    if (sendSSInd->is_alpha_id_present)
    {
        if (gSATSendSS.noAlphaId)
        {
            gSATSendSS.alphaId = CovertStringForPlatform(
                                    sendSSInd->alpha_id,
                                    gSATSendSS.noAlphaId,
                                    gSATSendSS.dcsOfAlphaId,
                                    &gSATSendSS.noAlphaId);
            gSATSendSS.informUser = 1;
        }
        else
        {
            gSATSendSS.informUser = 0;
        }
    }
    else
    {
        gSATSendSS.noAlphaId = mmi_ucs2strlen((PS8) (PU8) GetString(SAT_SEND_SS_STRING_ID)) * ENCODING_LENGTH;
        gSATSendSS.alphaId = (PU8) OslMalloc(gSATSendSS.noAlphaId + ENCODING_LENGTH);
        memcpy(gSATSendSS.alphaId, (PU8) GetString(SAT_SEND_SS_STRING_ID), gSATSendSS.noAlphaId + ENCODING_LENGTH);
        gSATSendSS.informUser = 1;
    }

    gSATSendSS.isIconAvailable = sendSSInd->is_icon_available;
    if (gSATSendSS.isIconAvailable)
    {
        gSATSendSS.iconInfo.iconId = sendSSInd->icon_info.icon_id;
        gSATSendSS.iconInfo.iconAttr = sendSSInd->icon_info.icon_attr;
    }

    if (gSATSendSS.isIconAvailable && gSATSendSS.iconInfo.iconAttr == SAT_ICON_SELF_EX)
    {
        if (gSATSendSS.alphaId)
        {
            OslMfree(gSATSendSS.alphaId);
            gSATSendSS.alphaId = NULL;
        }
    }

    if (gSATSendSS.informUser)
    {
        SATStopWaitTimer();
        DeleteScreenIfPresent(SCR_ID_SAT_HISTORY);
        if (GetExitScrnID() == SCR_ID_SAT_HISTORY)
        {
            ClearExitHandler();
        }
        DisplaySSWindow();
    }

    SATSendSSStage1Req(sendSSInd);
}


/*****************************************************************************
 * FUNCTION
 *  SATSendSSStage1Req
 * DESCRIPTION
 *  Send SEND SS STAGE1 REQ
 * PARAMETERS
 *  sendSSInd   [IN]    Pointer to recieved SATSENDSSIND struct from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATSendSSStage1Req(mmi_sat_send_ss_ind_struct *sendSSInd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    mmi_sat_send_ss_stage1_req_struct *dataPtr;
    int len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gSATContext.gotStage1Rsp = 0;

    CLR_EVENT(PRT_USSDVSS_RSP);

    memcpy(gSATSendSS.cmdDetail, sendSSInd->cmd_detail, 5 * sizeof(U8));
    Message = ALLOCATE_ITM(MOD_MMI);
    Message->oslSrcId = MOD_MMI;
    Message->oslMsgId = PRT_MMI_SAT_SEND_SS_STAGE1_REQ;
    dataPtr = (mmi_sat_send_ss_stage1_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_send_ss_stage1_req_struct));
    if (sendSSInd->no_ss_string >= MAX_DIGITS_USSD)
    {
        len = MAX_DIGITS_USSD - 1;
    }
    else
    {
        len = sendSSInd->no_ss_string;
    }
    memcpy(dataPtr->input, sendSSInd->ss_string, len);
    dataPtr->input[len] = 0;
    dataPtr->dcs = 0x1;
    dataPtr->length = len;
    dataPtr->type_of_modification = sendSSInd->type_of_modification;
    Message->oslDataPtr = (oslParaType*) dataPtr;
    Message->oslPeerBuffPtr = NULL;
    SEND_MSG(Message);
}


/*****************************************************************************
 * FUNCTION
 *  DisplaySSWindow
 * DESCRIPTION
 *  Displays Sending SS Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DisplaySSWindow(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *iconData = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gSATSendSS.isIconAvailable)
    {
        SATAddIconIDToList(gSATSendSS.iconInfo.iconId);
    }

    if (gSATSendSS.isIconAvailable)
    {
        if (!SATCheckAllIconGot())
        {
            SATGetIconCompleteCallBack = DisplaySSWindow;
            SATGetIconDataToList();
            return;
        }
    }

    iconData = SATGetIconFromList(gSATSendSS.iconInfo.iconId);
    gSATContext.exitCondition = &gSATSendSS.stage1Res;
    EntryNewScreen(SCR_ID_SAT_SENDSS, SATGenericExitHandler, NULL, NULL);

    SetIsInSATScreen();
    gSATContext.historyFuncPtr = DisplaySSWindow;
    ClearHighlightHandler();
    ShowCategory151Screen(0, 0, 0, 0, 0, 0, gSATSendSS.alphaId, iconData, gSATContext.guiBufferPointer);

    /* SetKeyHandler(ExitSATToIdle, KEY_END, KEY_EVENT_DOWN); */
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  TerminalResponseSATDisplaySSStage1MoveBack
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseSATDisplaySSStage1MoveBack(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!gSATSendSS.sentRsp)
    {
        gSATSendSS.sentRsp = 1;
        TerminalResponseSendSS(
            SAT_CMD_PERFORMED_SUCCESSFULLY,
            gSATSendSS.ssStringLen,
            gSATSendSS.ssString,
            gSATSendSS.cmdDetail);
    }

    if (gSATSendSS.textString)
    {
        OslMfree(gSATSendSS.textString);
        gSATSendSS.textString = NULL;
    }
    if (gSATSendSS.ssString)
    {
        OslMfree(gSATSendSS.ssString);
        gSATSendSS.ssString = NULL;
    }

    SetIsInSATScreen();
    SATPleaseWaitScreen(SAT_WAIT_STRING_ID, SAT_WAIT_IMAGE_ID);
}


/*****************************************************************************
 * FUNCTION
 *  TerminalResponseSATDisplaySSStage1Expire
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseSATDisplaySSStage1Expire(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!gSATSendSS.sentRsp)
    {
        gSATSendSS.sentRsp = 1;
        TerminalResponseSendSS(
            SAT_CMD_PERFORMED_SUCCESSFULLY,
            gSATSendSS.ssStringLen,
            gSATSendSS.ssString,
            gSATSendSS.cmdDetail);
    }

    if (gSATSendSS.textString)
    {
        OslMfree(gSATSendSS.textString);
        gSATSendSS.textString = NULL;
    }
    if (gSATSendSS.ssString)
    {
        OslMfree(gSATSendSS.ssString);
        gSATSendSS.ssString = NULL;
    }

    ExitSATToIdle();
}


/*****************************************************************************
 * FUNCTION
 *  SendSSTimer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SendSSTimer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TerminalResponseSendSS(
        SAT_CMD_PERFORMED_SUCCESSFULLY,
        gSATSendSS.ssStringLen,
        gSATSendSS.ssString,
        gSATSendSS.cmdDetail);

    if (gSATContext.isInSATMenu)
    {
    #if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
        if (gSATContext.satIndex == SAT_CMD_SIM2)
        {
            gSATContext.historyFuncPtr = GoToSATMainMenu_2;
        }
        else
        {
            gSATContext.historyFuncPtr = GoToSATMainMenu;
        }
    #else /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
        gSATContext.historyFuncPtr = GoToSATMainMenu;
    #endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
        if (gSATContext.isInSATScreen)
        {
            if (IsScreenPresent(SCR_ID_SAT_HISTORY))
            {
                GoBackToHistory(SCR_ID_SAT_HISTORY);
            }
            else
            {
            #if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
                if (gSATContext.satIndex == SAT_CMD_SIM2)
                {
                    GoToSATMainMenu_2();
                }
                else
                {
                    GoToSATMainMenu();
                }
            #else /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
                GoToSATMainMenu();
            #endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
            }
        }
    }
    else
    {
        if (gSATContext.isInSATScreen)
        {
            GoBackHistory();
        }
        else
        {
            DeleteScreenIfPresent(SCR_ID_SAT_HISTORY);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  GoToSATDisplaySSStage1Rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoToSATDisplaySSStage1Rsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gSATContext.exitCondition = &gSATSendSS.sentRsp;
    EntryNewScreen(SCR_ID_SAT_DISPLAY_SS, SATGenericExitHandler, NULL, NULL);

    SetIsInSATScreen();
    gSATContext.historyFuncPtr = GoToSATDisplaySSStage1Rsp;
    ClearHighlightHandler();
    ShowCategory151Screen(
        0,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        0,
        0,  /* STR_GLOBAL_BACK, IMG_GLOBAL_BACK, */
        gSATSendSS.textString,
        NULL,
        gSATContext.guiBufferPointer);

    SetKeyHandler(TerminalResponseSATDisplaySSStage1Expire, KEY_END, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(TerminalResponseSATDisplaySSStage1MoveBack, KEY_EVENT_UP);
    /* SetRightSoftkeyFunction(TerminalResponseSATDisplaySSStage1MoveBack, KEY_EVENT_UP); */
    StartSATTimerNoResponsefromUser(SendSSTimer);
}


/*****************************************************************************
 * FUNCTION
 *  SATSendSSStage1Rsp
 * DESCRIPTION
 *  Protocol Handler for SEND SS STAGE 1 RES
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATSendSSStage1Rsp(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_send_ss_stage1_rsp_struct *sendSSStage1Res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sendSSStage1Res = (mmi_sat_send_ss_stage1_rsp_struct*) msgPtr;

    gSATContext.gotStage1Rsp = 1;

    if (gSATContext.lastSATCmd == SAT_NONE_CMD)
    {
        return;
    }

    if (gSATContext.lastSATCmd != SAT_SEND_SS_CMD)
    {
        SATSendSSUSSDError();
        gSATContext.lastSATCmd = SAT_NONE_CMD;
        return;
    }
    else
    {
        gSATContext.lastSATCmd = SAT_NONE_CMD;
    }

    gSATSendSS.stage1Res = 1;

    /* diamond, 2005/12/12 Display SS reponse */
    if ((sendSSStage1Res->res == SAT_CMD_PERFORMED_SUCCESSFULLY)
        && (sendSSStage1Res->length > 8) && (sendSSStage1Res->addition_info[0] == 0x3B))
    {
        /* expected sms 7-bit packed ss string: 0x3B 0x.. (0x81) 0x.. 0x.. 0x.. 0x.. 0x.. length data...... */
        U8 tempss[256];

        gSATSendSS.ssString = OslMalloc(sendSSStage1Res->length);
        gSATSendSS.textString = OslMalloc(512);
        memset(gSATSendSS.textString, 0, 512);
        memset(tempss, 0, 256);

        /* copy the sms 7-bit packed ss for terminal response */
        gSATSendSS.ssStringLen = sendSSStage1Res->length;
        memcpy(gSATSendSS.ssString, sendSSStage1Res->addition_info, sendSSStage1Res->length);

        /* ss format check */
        /* unpack it and then transfer to unicode for display */
        if (sendSSStage1Res->addition_info[2] == 0x81)
        {
            smsal_gsm7_unpack(
                (PU8) (&sendSSStage1Res->addition_info[9]),
                tempss,
                smsal_msg_len_in_character(SMSAL_DEFAULT_DCS, sendSSStage1Res->addition_info[8], sendSSStage1Res->addition_info[8 + sendSSStage1Res-> addition_info[8]]),
                0);
        }
        else
        {
            smsal_gsm7_unpack(
                (PU8) (&sendSSStage1Res->addition_info[8]),
                tempss,
                smsal_msg_len_in_character(SMSAL_DEFAULT_DCS, sendSSStage1Res->addition_info[7], sendSSStage1Res->addition_info[7 + sendSSStage1Res-> addition_info[7]]),
                0);
        }

        mmi_asc_to_ucs2((PS8) gSATSendSS.textString, (PS8) tempss);

        /* show the unpacked ss string */
        gSATSendSS.sentRsp = 0;
        SATStopWaitTimer();
        GoToSATDisplaySSStage1Rsp();
    }
    else
    {
        TerminalResponseSendSS(
            sendSSStage1Res->res,
            sendSSStage1Res->length,
            sendSSStage1Res->addition_info,
            gSATSendSS.cmdDetail);
        if (gSATSendSS.informUser)
        {
            if (sendSSStage1Res->res == SAT_CMD_PERFORMED_SUCCESSFULLY ||
                sendSSStage1Res->res == SAT_CMD_PERFORMED_WITH_PARTIAL_COMPREHENSION ||
                sendSSStage1Res->res == SAT_CMD_PERFORMED_WITH_MISSING_INFO)
            {

                SATPleaseWaitScreen(SAT_SS_SUCCESS_STRING_ID, 0);
            }
            else
            {

                SATPleaseWaitScreen(SAT_SS_ERROR_STRING_ID, 0);
            }
        }
    }
    /* end, diamond */
}


/*****************************************************************************
 * FUNCTION
 *  TerminalResponseSendSS
 * DESCRIPTION
 *  Send SEND SS STAGE2 REQ to L4
 * PARAMETERS
 *  res         [IN]    Response type
 *  len         [IN]    Len of additional info, returned in SEND SS STAGE 1 RES
 *  info        [IN]    Additional info, returned in SEND SS STAGE 1 RES
 *  cmdDetail   [IN]    Cmd detail to be sent
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseSendSS(U8 res, U8 len, U8 *info, U8 *cmdDetail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    mmi_sat_send_ss_stage2_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message = ALLOCATE_ITM(MOD_MMI);
    Message->oslSrcId = MOD_MMI;
    Message->oslMsgId = PRT_MMI_SAT_SEND_SS_STAGE2_REQ;
    dataPtr = (mmi_sat_send_ss_stage2_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_send_ss_stage2_req_struct));

    StopSATTimerNoResponsefromUser();
    gSATContext.noResponseFuncPtr = NULL;

    /* diamond, 2005/05/24 icon */
    if (res == SAT_CMD_PERFORMED_SUCCESSFULLY && gSATSendSS.isIconAvailable == 1 &&
        gSATContext.isCMDIconSupported == MMI_FALSE)
    {
        dataPtr->res = SAT_CMD_PERFORMED_BUT_ICON_COULD_NOT_DSPL;
    }
    else
    {
        /* end, diamond */
        dataPtr->res = res;
    }

    dataPtr->size_of_additional_info = len;
    if (dataPtr->size_of_additional_info > 255)
    {
        dataPtr->size_of_additional_info = 255;
    }
    memcpy(dataPtr->additional_info, info, dataPtr->size_of_additional_info);

    memcpy(dataPtr->cmd_detail, (void*)cmdDetail, 5 * sizeof(U8));
    Message->oslDataPtr = (oslParaType*) dataPtr;
    Message->oslPeerBuffPtr = NULL;
    SEND_MSG(Message);
    gSATContext.lastSATCmd = SAT_NONE_CMD;
}


/*****************************************************************************
 * FUNCTION
 *  SATSendSSStage2Rsp
 * DESCRIPTION
 *  Protocol Handler for SEND SS STAGE 2 RES
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATSendSSStage2Rsp(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FreeSendSS();
}


/*****************************************************************************
 * FUNCTION
 *  FreeSendSS
 * DESCRIPTION
 *  Frees various elements of Send SS Structure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FreeSendSS(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SATClearAllIcons();
    if (gSATSendSS.alphaId)
    {
        OslMfree(gSATSendSS.alphaId);
        gSATSendSS.alphaId = NULL;
    }
}


#define MMI_SAT_SEND_USSD
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
/*****************************************************************************
 * FUNCTION
 *  TerminalResponseSendUSSD_2
 * DESCRIPTION
 *  Send SEND USSD STAGE2 REQ to L4 or L4_2 by destId
 * PARAMETERS
 *  destId      [IN]    L4/L4_2
 *  res         [IN]    Response type
 *  len         [IN]    Len of additional info, returned in SEND USSD STAGE 1 RES
 *  info        [IN]    Additional info, returned in SEND USSD STAGE 1 RES
 *  cmdDetail   [IN]    Cmd detail to be sent
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseSendUSSD_2(U8 destId, U8 res, U8 len, U8 *info, U8 *cmdDetail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    mmi_sat_send_ussd_stage2_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message = allocate_ilm(MOD_MMI);
    Message->oslSrcId = MOD_MMI;
    Message->oslDestId = destId;
    Message->oslMsgId = PRT_MMI_SAT_SEND_USSD_STAGE2_REQ;
    dataPtr = (mmi_sat_send_ussd_stage2_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_send_ussd_stage2_req_struct));
    dataPtr->res = res;
    dataPtr->size_of_additional_info = len;
    if (dataPtr->size_of_additional_info > 255)
    {
        dataPtr->size_of_additional_info = 255;
    }
    memcpy(dataPtr->additional_info, info, dataPtr->size_of_additional_info);
    memcpy(dataPtr->cmd_detail, (void*)cmdDetail, 5 * sizeof(U8));
    Message->oslDataPtr = (oslParaType*) dataPtr;
    Message->oslPeerBuffPtr = NULL;
    Message->sap_id = INVALID_SAP;
    msg_send_ext_queue(Message);
}


/*****************************************************************************
 * FUNCTION
 *  SATSendUSSDSIM1Ind
 * DESCRIPTION
 *  Protocol Handler for SEND USSD IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4-1
 * RETURNS
 *  void
 *****************************************************************************/
void SATSendUSSDSIM1Ind(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_send_ussd_ind_struct *sendUSSDInd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sendUSSDInd = (mmi_sat_send_ussd_ind_struct*) msgPtr;

    if (gSATContext.CMDfromSIM == SAT_CMD_SIM2)
    {
        TerminalResponseSendUSSD_2(MOD_L4C, SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, 0, NULL, sendUSSDInd->cmd_detail);
    }
    else
    {
        gSATContext.CMDfromSIM = SAT_CMD_SIM1;
        SATSendUSSDInd(msgPtr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  SATSendUSSDSIM2Ind
 * DESCRIPTION
 *  Protocol Handler for SEND USSD IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4-2
 * RETURNS
 *  void
 *****************************************************************************/
void SATSendUSSDSIM2Ind(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_send_ussd_ind_struct *sendUSSDInd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sendUSSDInd = (mmi_sat_send_ussd_ind_struct*) msgPtr;

    if (gSATContext.CMDfromSIM == SAT_CMD_SIM1)
    {
        TerminalResponseSendUSSD_2(MOD_L4C_2, SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, 0, NULL, sendUSSDInd->cmd_detail);
    }
    else
    {
        gSATContext.CMDfromSIM = SAT_CMD_SIM2;
        SATSendUSSDInd(msgPtr);
    }
}

#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */


/*****************************************************************************
 * FUNCTION
 *  SATSendUSSDInd
 * DESCRIPTION
 *  Protocol Handler for SEND USSD IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATSendUSSDInd(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_send_ussd_ind_struct *sendUSSDInd;
    pBOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sendUSSDInd = (mmi_sat_send_ussd_ind_struct*) msgPtr;

    FreeSendUSSD();

    gSATContext.lastSATCmd = SAT_SEND_USSD_CMD;
    gSATContext.guiBufferPointer = NULL;
    gSATSendUSSD.stage1Res = 0;

    if (sendUSSDInd->is_icon_available && sendUSSDInd->icon_info.icon_attr != SAT_ICON_SELF_EX && !sendUSSDInd->is_alpha_id_present)
    {
        TerminalResponseSendUSSD(SAT_CMD_DATA_NOT_UNDERSTAND_BY_ME, 0, NULL, sendUSSDInd->cmd_detail);
        return;
    }

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    if (gSATContext.CMDfromSIM == SAT_CMD_SIM2)
    {
        result = mmi_bootup_is_sim2_nw_registration_ok();
    }
    else
    {
        result = mmi_bootup_is_nw_registration_ok();
    }
#else /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
    result = mmi_bootup_is_nw_registration_ok();
#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
    if (result == MMI_FALSE)
    {
        TerminalResponseSendUSSD(SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, 0, NULL, sendUSSDInd->cmd_detail);
        return;
    }

    gSATSendUSSD.dcsOfAlphaId = sendUSSDInd->dcs_of_alpha_id;
    gSATSendUSSD.noAlphaId = sendUSSDInd->no_alpha_id;
    if (sendUSSDInd->is_alpha_id_present)
    {
        if (gSATSendUSSD.noAlphaId)
        {
            gSATSendUSSD.alphaId = CovertStringForPlatform(
                                    sendUSSDInd->alpha_id,
                                    gSATSendUSSD.noAlphaId,
                                    gSATSendUSSD.dcsOfAlphaId,
                                    &gSATSendUSSD.noAlphaId);
            gSATSendUSSD.informUser = 1;
        }
        else
        {
            gSATSendUSSD.informUser = 0;
        }
    }
    else
    {
        gSATSendUSSD.noAlphaId = mmi_ucs2strlen((PS8) (PU8) GetString(SAT_SEND_USSD_STRING_ID)) * ENCODING_LENGTH;
        gSATSendUSSD.alphaId = (PU8) OslMalloc(gSATSendUSSD.noAlphaId + ENCODING_LENGTH);
        memcpy(
            gSATSendUSSD.alphaId,
            (PU8) GetString(SAT_SEND_USSD_STRING_ID),
            gSATSendUSSD.noAlphaId + ENCODING_LENGTH);
        gSATSendUSSD.informUser = 1;
    }

    gSATSendUSSD.isIconAvailable = sendUSSDInd->is_icon_available;
    if (gSATSendUSSD.isIconAvailable)
    {
        gSATSendUSSD.iconInfo.iconId = sendUSSDInd->icon_info.icon_id;
        gSATSendUSSD.iconInfo.iconAttr = sendUSSDInd->icon_info.icon_attr;
    }

    if (gSATSendUSSD.isIconAvailable && gSATSendUSSD.iconInfo.iconAttr == SAT_ICON_SELF_EX)
    {
        if (gSATSendUSSD.alphaId)
        {
            OslMfree(gSATSendUSSD.alphaId);
            gSATSendUSSD.alphaId = NULL;
        }
    }

    if (gSATSendUSSD.informUser)
    {
        SATStopWaitTimer();
        DeleteScreenIfPresent(SCR_ID_SAT_HISTORY);
        if (GetExitScrnID() == SCR_ID_SAT_HISTORY)
        {
            ClearExitHandler();
        }
        DisplayUSSDWindow();
    }

    SATSendUSSDStage1Req(sendUSSDInd);
}


/*****************************************************************************
 * FUNCTION
 *  SATSendUSSDStage1Req
 * DESCRIPTION
 *  Send SEND USSD STAGE1 REQ
 * PARAMETERS
 *  sendUSSDInd     [IN]    Pointer to recieved SATSENDUSSDIND struct from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATSendUSSDStage1Req(mmi_sat_send_ussd_ind_struct *sendUSSDInd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    mmi_sat_send_ussd_stage1_req_struct *dataPtr;
    int len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* remove any USSD screen in the history to ensure that the coming USSD is displayed in the top screen */
    RemoveSSReqScr();

    gSATContext.gotStage1Rsp = 0;

    CLR_EVENT(PRT_USSDVSS_RSP);

    memcpy(gSATSendUSSD.cmdDetail, sendUSSDInd->cmd_detail, 5 * sizeof(U8));
    Message = ALLOCATE_ITM(MOD_MMI);
    Message->oslSrcId = MOD_MMI;
    Message->oslMsgId = PRT_MMI_SAT_SEND_USSD_STAGE1_REQ;
    dataPtr = (mmi_sat_send_ussd_stage1_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_send_ussd_stage1_req_struct));
    if (sendUSSDInd->no_ussd_string >= MAX_DIGITS_USSD)
    {
        len = MAX_DIGITS_USSD - 1;
    }
    else
    {
        len = sendUSSDInd->no_ussd_string;
    }
    memcpy(dataPtr->input, sendUSSDInd->ussd_string, len);
    dataPtr->input[len] = 0;
    dataPtr->dcs = sendUSSDInd->dcs_of_ussd_string;
    dataPtr->length = len;
    dataPtr->type_of_modification = sendUSSDInd->type_of_modification;
    Message->oslDataPtr = (oslParaType*) dataPtr;
    Message->oslPeerBuffPtr = NULL;
    SEND_MSG(Message);
}


/*****************************************************************************
 * FUNCTION
 *  DisplayUSSDWindow
 * DESCRIPTION
 *  Displays Sending USSD Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DisplayUSSDWindow(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *iconData = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gSATSendUSSD.isIconAvailable)
    {
        SATAddIconIDToList(gSATSendUSSD.iconInfo.iconId);
    }

    if (gSATSendUSSD.isIconAvailable)
    {
        if (!SATCheckAllIconGot())
        {
            SATGetIconCompleteCallBack = DisplayUSSDWindow;
            SATGetIconDataToList();
            return;
        }
    }

    iconData = SATGetIconFromList(gSATSendUSSD.iconInfo.iconId);
    gSATContext.exitCondition = &gSATSendUSSD.stage1Res;
    EntryNewScreen(SCR_ID_SAT_SENDUSSD, SATGenericExitHandler, NULL, NULL);

    SetIsInSATScreen();
    gSATContext.historyFuncPtr = DisplayUSSDWindow;
    ClearHighlightHandler();
    ShowCategory151Screen(0, 0, 0, 0, 0, 0, gSATSendUSSD.alphaId, iconData, gSATContext.guiBufferPointer);

    /* SetKeyHandler(ExitSATToIdle, KEY_END, KEY_EVENT_DOWN); */
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  SATSendUSSDStage1Rsp
 * DESCRIPTION
 *  Protocol Handler for SEND USSD STAGE 1 RES
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATSendUSSDStage1Rsp(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_send_ussd_stage1_rsp_struct *sendUSSDStage1Res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sendUSSDStage1Res = (mmi_sat_send_ussd_stage1_rsp_struct*) msgPtr;

    gSATContext.gotStage1Rsp = 1;

    if (gSATContext.lastSATCmd == SAT_NONE_CMD)
    {
        return;
    }

    if (gSATContext.lastSATCmd != SAT_SEND_USSD_CMD)
    {
        SATSendSSUSSDError();
        gSATContext.lastSATCmd = SAT_NONE_CMD;
        return;
    }
    else
    {
        gSATContext.lastSATCmd = SAT_NONE_CMD;
    }

    gSATSendUSSD.stage1Res = 1;

    TerminalResponseSendUSSD(
        sendUSSDStage1Res->res,
        sendUSSDStage1Res->length,
        sendUSSDStage1Res->addition_info,
        gSATSendUSSD.cmdDetail);
    if (gSATSendUSSD.informUser)
    {
        if (sendUSSDStage1Res->res == SAT_CMD_PERFORMED_SUCCESSFULLY ||
            sendUSSDStage1Res->res == SAT_CMD_PERFORMED_WITH_PARTIAL_COMPREHENSION ||
            sendUSSDStage1Res->res == SAT_CMD_PERFORMED_WITH_MISSING_INFO)
        {
            SATPleaseWaitScreen(SAT_USSD_SUCCESS_STRING_ID, 0);
        }
        else if (sendUSSDStage1Res->res == SAT_USSD_SS_TRANSACTION_TERMINATION_BY_USER)
        {
            SATPleaseWaitScreen(SAT_USSD_ABORT_STRING_ID, 0);
        }
        else
        {
            SATPleaseWaitScreen(SAT_USSD_ERROR_STRING_ID, 0);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  SATSendSSUSSDError
 * DESCRIPTION
 *  Sends USSD Error
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SATSendSSUSSDError(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (gSATContext.lastSATCmd)
    {
        case SAT_SEND_SS_CMD:
            TerminalResponseSendSS(SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, 0, NULL, gSATSendSS.cmdDetail);
            if (gSATSendSS.informUser)
            {
                SATPleaseWaitScreen(SAT_SS_ERROR_STRING_ID, 0);
            }
            break;
        case SAT_SEND_USSD_CMD:
            TerminalResponseSendUSSD(SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, 0, NULL, gSATSendUSSD.cmdDetail);
            if (gSATSendUSSD.informUser)
            {
                SATPleaseWaitScreen(SAT_USSD_ERROR_STRING_ID, 0);
            }
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  TerminalResponseSendUSSD
 * DESCRIPTION
 *  Send SEND USSD STAGE2 REQ to L4
 * PARAMETERS
 *  res         [IN]    Response type
 *  len         [IN]    Len of additional info, returned in SEND USSD STAGE 1 RES
 *  info        [IN]    Additional info, returned in SEND USSD STAGE 1 RES
 *  cmdDetail   [IN]    Cmd detail to be sent
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseSendUSSD(U8 res, U8 len, U8 *info, U8 *cmdDetail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    mmi_sat_send_ussd_stage2_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message = ALLOCATE_ITM(MOD_MMI);
    Message->oslSrcId = MOD_MMI;
    Message->oslMsgId = PRT_MMI_SAT_SEND_USSD_STAGE2_REQ;
    dataPtr = (mmi_sat_send_ussd_stage2_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_send_ussd_stage2_req_struct));

    /* diamond, 2005/05/24 icon */
    if (res == SAT_CMD_PERFORMED_SUCCESSFULLY && gSATSendUSSD.isIconAvailable == 1 &&
        gSATContext.isCMDIconSupported == MMI_FALSE)
    {
        dataPtr->res = SAT_CMD_PERFORMED_BUT_ICON_COULD_NOT_DSPL;
    }
    else
    {
        /* end, diamond */
        dataPtr->res = res;
    }

    dataPtr->size_of_additional_info = len;
    if (dataPtr->size_of_additional_info > 255)
    {
        dataPtr->size_of_additional_info = 255;
    }
    memcpy(dataPtr->additional_info, info, dataPtr->size_of_additional_info);

    memcpy(dataPtr->cmd_detail, (void*)cmdDetail, 5 * sizeof(U8));
    Message->oslDataPtr = (oslParaType*) dataPtr;
    Message->oslPeerBuffPtr = NULL;
    SEND_MSG(Message);
    gSATContext.lastSATCmd = SAT_NONE_CMD;
}


/*****************************************************************************
 * FUNCTION
 *  SATSendUSSDStage2Rsp
 * DESCRIPTION
 *  Protocol Handler for SEND USSD STAGE 2 RES
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATSendUSSDStage2Rsp(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FreeSendUSSD();
}


/*****************************************************************************
 * FUNCTION
 *  FreeSendUSSD
 * DESCRIPTION
 *  Frees various elements of Send USSD Structure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FreeSendUSSD(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SATClearAllIcons();
    if (gSATSendUSSD.alphaId)
    {
        OslMfree(gSATSendUSSD.alphaId);
        gSATSendUSSD.alphaId = NULL;
    }
}


#define MMI_SAT_MMI_INFO
/*****************************************************************************
 * FUNCTION
 *  SATMMIInfoInd
 * DESCRIPTION
 *  Protocol Handler for MMI INFO IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATMMIInfoInd(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_mmi_info_ind_struct *mmiInfoInd;
    U8 *Isd;
    U8 *message;
    U8 *number;
    U8 *displayNumber;
    U16 numberLength = 0;
    U16 messageLen;
    U16 finalLen;
    U8 *finalMessage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gSATContext.guiBufferPointer = NULL;
    mmiInfoInd = (mmi_sat_mmi_info_ind_struct*) msgPtr;
    if (mmiInfoInd->is_alpha_id_present)
    {
        message = CovertStringForPlatform(
                    mmiInfoInd->alpha_id,
                    mmiInfoInd->no_alpha_id,
                    mmiInfoInd->dcs_of_alpha_id,
                    &messageLen);
    }
    else
    {
        if (!mmiInfoInd->len_of_address)
        {
            return;
        }
        messageLen =
            (mmi_ucs2strlen((PS8) (PU8) GetString(SAT_NUM_CHANGED_BY_SIM_STRING_ID)) * ENCODING_LENGTH) +
            ENCODING_LENGTH;
        message = (PU8) OslMalloc(messageLen);
        memcpy(message, (PU8) GetString(SAT_NUM_CHANGED_BY_SIM_STRING_ID), messageLen);
    }

    number = CovertStringForPlatform(mmiInfoInd->address, (U16) mmiInfoInd->len_of_address, MMI_8BIT_DCS, &numberLength);

    if (mmiInfoInd->ton == 0x91 && mmiInfoInd->len_of_address)
    {
        Isd = CovertStringForPlatform((PU8) "+", 1, MMI_8BIT_DCS, NULL);
        displayNumber = OslMalloc(numberLength + ENCODING_LENGTH);
        mmi_ucs2cpy((PS8) displayNumber, (PS8) Isd);
        mmi_ucs2cat((PS8) displayNumber, (PS8) number);
        finalLen = messageLen + numberLength;
        OslMfree(Isd);
    }
    else
    {
        displayNumber = OslMalloc(numberLength + ENCODING_LENGTH);
        mmi_ucs2cpy((PS8) displayNumber, (PS8) number);
        finalLen = messageLen + numberLength - ENCODING_LENGTH;
    }

    finalMessage = OslMalloc(finalLen);
    mmi_ucs2cpy((PS8) finalMessage, (PS8) message);
    mmi_ucs2cat((PS8) finalMessage, (PS8) displayNumber);

    OslMfree(displayNumber);
    OslMfree(message);
    NotifyMONumberChange(number, finalMessage);
    OslMfree(number);
    OslMfree(finalMessage);
}


#define MMI_SAT_PLAY_TONE
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
/*****************************************************************************
 * FUNCTION
 *  TerminalResponsePlayToneEx
 * DESCRIPTION
 *  Send PLAY TONE REQ to L4 or L4_2 by destId
 * PARAMETERS
 *  destId      [IN]    L4/L4_2
 *  res         [IN]    Response type
 *  cmdDetail   [IN]    Cmd detail to be sent
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponsePlayToneEx(U8 destId, U8 res, U8 *cmdDetail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    mmi_sat_play_tone_res_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message = allocate_ilm(MOD_MMI);
    Message->oslSrcId = MOD_MMI;
    Message->oslDestId = destId;
    Message->oslMsgId = PRT_MMI_SAT_PLAY_TONE_RES_REQ;
    dataPtr = (mmi_sat_play_tone_res_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_play_tone_res_req_struct));
    dataPtr->res = res;
    memcpy(dataPtr->cmd_detail, (void*)cmdDetail, 5 * sizeof(U8));
    Message->oslDataPtr = (oslParaType*) dataPtr;
    Message->oslPeerBuffPtr = NULL;
    Message->sap_id = INVALID_SAP;
    msg_send_ext_queue(Message);
}


/*****************************************************************************
 * FUNCTION
 *  SATPlayToneSIM1Ind
 * DESCRIPTION
 *  Protocol Handler for PLAY TONE IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4-2
 * RETURNS
 *  void
 *****************************************************************************/
void SATPlayToneSIM1Ind(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_play_tone_ind_struct *playToneInd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    playToneInd = (mmi_sat_play_tone_ind_struct*) msgPtr;

    if (gSATPlayTone.CMDfromSIM == SAT_CMD_SIM2)
    {
        TerminalResponsePlayToneEx(MOD_L4C, SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, playToneInd->cmd_detail);
    }
    else
    {
        gSATPlayTone.CMDfromSIM = SAT_CMD_SIM1;
        SATPlayToneInd(msgPtr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  SATPlayToneSIM2Ind
 * DESCRIPTION
 *  Protocol Handler for PLAY TONE IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4-2
 * RETURNS
 *  void
 *****************************************************************************/
void SATPlayToneSIM2Ind(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_play_tone_ind_struct *playToneInd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    playToneInd = (mmi_sat_play_tone_ind_struct*) msgPtr;

    if (gSATPlayTone.CMDfromSIM == SAT_CMD_SIM1)
    {
        TerminalResponsePlayToneEx(MOD_L4C_2, SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, playToneInd->cmd_detail);
    }
    else
    {
        gSATPlayTone.CMDfromSIM = SAT_CMD_SIM2;
        SATPlayToneInd(msgPtr);
    }
}

#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */


/*****************************************************************************
 * FUNCTION
 *  SATPlayToneInd
 * DESCRIPTION
 *  Protocol Handler for PLAY TONE IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATPlayToneInd(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_play_tone_ind_struct *playToneInd;
    U8 callState;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    playToneInd = (mmi_sat_play_tone_ind_struct*) msgPtr;

    FreePlayTone();

    gSATContext.lastSATCmd = SAT_PLAY_TONE_CMD;
    gSATContext.guiBufferPointer = NULL;
    gSATPlayTone.sentRsp = 0;

    callState = FALSE;
    if (!isIncomingCall() && !isOutgoingCall() &&
#ifdef __MMI_UCM__
    mmi_ucm_app_active_call(MMI_UCM_CALL_TYPE_ALL) > 0
#else /* __MMI_UCM__ */
    GetTotalActiveCallCount() > 0
#endif /* __MMI_UCM__ */
    )
    {
        callState = TRUE;
    }

    memcpy(gSATPlayTone.cmdDetail, playToneInd->cmd_detail, 5 * sizeof(U8));

    if (callState)
    {
        switch (playToneInd->tone_id)
        {
            case SAT_TONE_DIAL:
                gSATPlayTone.toneId = TONE_DIAL_CALL_GSM;
                break;
            case SAT_TONE_CALLED_SUBSCRIBER_BUSY:
                gSATPlayTone.toneId = TONE_BUSY_CALL_GSM;
                break;
            case SAT_TONE_CONGESTION:
                gSATPlayTone.toneId = TONE_CONGESTION_GSM;
                break;
            case SAT_TONE_RADIO_PATH_ACK:
                gSATPlayTone.toneId = TONE_RADIO_PATH;
                break;
            case SAT_TONE_RADIO_NO_PATH:
                gSATPlayTone.toneId = TONE_RADIO_NA;
                break;
            case SAT_TONE_ERROR:
                gSATPlayTone.toneId = TONE_ERROR_INFO;
                break;
            case SAT_TONE_CALL_WAITING:
                gSATPlayTone.toneId = TONE_CALL_WAITING;
                break;
            case SAT_TONE_RING:
                gSATPlayTone.toneId = TONE_RINGING_CALL_GSM;
                break;
            case SAT_TONE_GENERAL_BEEP:
                gSATPlayTone.toneId = TONE_KEY_NORMAL;
                break;
            case SAT_TONE_POS_ACK:
                gSATPlayTone.toneId = TONE_POSITIVE_ACK;
                break;
            case SAT_TONE_NEG_ACK:
                gSATPlayTone.toneId = TONE_NEGATIVE_ACK;
                break;
            default:
                TerminalResponsePlayTone(SAT_CMD_DATA_NOT_UNDERSTAND_BY_ME, playToneInd->cmd_detail);
                return;
                break;
        }
    }
    else
    {
        switch (playToneInd->tone_id)
        {
            case SAT_TONE_DIAL:
                gSATPlayTone.toneId = TONE_DIAL_CALL_GSM_STK;
                break;
            case SAT_TONE_CALLED_SUBSCRIBER_BUSY:
                gSATPlayTone.toneId = TONE_BUSY_CALL_GSM_STK;
                break;
            case SAT_TONE_CONGESTION:
                gSATPlayTone.toneId = TONE_CONGESTION_GSM_STK;
                break;
            case SAT_TONE_RADIO_PATH_ACK:
                gSATPlayTone.toneId = TONE_RADIO_PATH_STK;
                break;
            case SAT_TONE_RADIO_NO_PATH:
                gSATPlayTone.toneId = TONE_RADIO_NA_STK;
                break;
            case SAT_TONE_ERROR:
                gSATPlayTone.toneId = TONE_ERROR_INFO_STK;
                break;
            case SAT_TONE_CALL_WAITING:
                gSATPlayTone.toneId = TONE_CALL_WAITING_STK;
                break;
            case SAT_TONE_RING:
                gSATPlayTone.toneId = TONE_RINGING_CALL_GSM_STK;
                break;
            case SAT_TONE_GENERAL_BEEP:
                gSATPlayTone.toneId = TONE_KEY_NORMAL;
                break;
            case SAT_TONE_POS_ACK:
                gSATPlayTone.toneId = TONE_POSITIVE_ACK_STK;
                break;
            case SAT_TONE_NEG_ACK:
                gSATPlayTone.toneId = TONE_NEGATIVE_ACK_STK;
                break;
            default:
                TerminalResponsePlayTone(SAT_CMD_DATA_NOT_UNDERSTAND_BY_ME, playToneInd->cmd_detail);
                return;
                break;
        }
    }

    gSATPlayTone.duration = playToneInd->duration;
#ifdef __USAT__
    gSATPlayTone.vibration = playToneInd->sound_with_vibration;
    gSATPlayTone.noTextAttribute = playToneInd->no_text_attribute;
    if (gSATPlayTone.noTextAttribute != 0)
    {
        gSATPlayTone.textFormatting = OslMalloc(gSATPlayTone.noTextAttribute * 4);
        memcpy(gSATPlayTone.textFormatting, playToneInd->text_formatting, gSATPlayTone.noTextAttribute * 4);
    }
#endif /* __USAT__ */ 

    gSATPlayTone.dcsOfAlphaId = playToneInd->dcs_of_alpha_id;
    gSATPlayTone.noAlphaId = playToneInd->no_alpha_id;
    if (playToneInd->is_alpha_id_present)
    {
        if (gSATPlayTone.noAlphaId)
        {
            gSATPlayTone.alphaId = CovertStringForPlatform(
                                    playToneInd->alpha_id,
                                    gSATPlayTone.noAlphaId,
                                    gSATPlayTone.dcsOfAlphaId,
                                    &gSATPlayTone.noAlphaId);
            gSATPlayTone.informUser = 1;
        }
        else
        {
            gSATPlayTone.informUser = 0;
        }
    }
    else
    {
        gSATPlayTone.noAlphaId = mmi_ucs2strlen((PS8) (PU8) GetString(SAT_PLAY_TONE_STRING_ID)) * ENCODING_LENGTH;
        gSATPlayTone.alphaId = (PU8) OslMalloc(gSATPlayTone.noAlphaId + ENCODING_LENGTH);
        memcpy(
            gSATPlayTone.alphaId,
            (PU8) GetString(SAT_PLAY_TONE_STRING_ID),
            gSATPlayTone.noAlphaId + ENCODING_LENGTH);
        gSATPlayTone.informUser = 1;
    }

    gSATPlayTone.isIconAvailable = playToneInd->is_icon_available;
    if (gSATPlayTone.isIconAvailable)
    {
        gSATPlayTone.iconInfo.iconId = playToneInd->icon_info.icon_id;
        gSATPlayTone.iconInfo.iconAttr = playToneInd->icon_info.icon_attr;
    }

    if (gSATPlayTone.isIconAvailable && gSATPlayTone.iconInfo.iconAttr == SAT_ICON_SELF_EX)
    {
        if (gSATPlayTone.alphaId)
        {
            OslMfree(gSATPlayTone.alphaId);
            gSATPlayTone.alphaId = NULL;
        }
    }

    if (gSATPlayTone.informUser)
    {
        SATStopWaitTimer();
        DeleteScreenIfPresent(SCR_ID_SAT_HISTORY);
        if (GetExitScrnID() == SCR_ID_SAT_HISTORY)
        {
            ClearExitHandler();
        }
        DisplayPlayToneWindow();
    }
    else
    {
    #ifdef __MMI_SILENT_MEETING_PROFILE__
        if (!IsSilentModeActivated() && !IsMeetingModeActivated())
    #else 
        if (!IsSilentModeActivated())
    #endif 
        {
            /* not play tone in slient mode */
            AudioPlayReq(gSATPlayTone.toneId, DEVICE_AUDIO_PLAY_INFINITE);
        }

    #ifdef __USAT__
        if (gSATPlayTone.vibration)
        {
            VibratorOn();
        }
    #endif /* __USAT__ */ 
    }

    StartTimer(SAT_PLAY_TONE_TIMER, playToneInd->duration, SATPlayToneTimer);
}


/*****************************************************************************
 * FUNCTION
 *  SATPlayToneTimer
 * DESCRIPTION
 *  CallBAck Function called when the timer to Plat the Tone Expires
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SATPlayToneTimer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AudioStopReq(gSATPlayTone.toneId);
    TerminalResponsePlayTone(SAT_CMD_PERFORMED_SUCCESSFULLY, gSATPlayTone.cmdDetail);
    if (gSATPlayTone.informUser)
    {
        SATPleaseWaitScreen(SAT_WAIT_STRING_ID, SAT_WAIT_IMAGE_ID);
    }
}


/*****************************************************************************
 * FUNCTION
 *  DisplayPlayToneWindow
 * DESCRIPTION
 *  Display Play Tone Window
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DisplayPlayToneWindow(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *iconData = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gSATPlayTone.isIconAvailable)
    {
        SATAddIconIDToList(gSATPlayTone.iconInfo.iconId);
    }

    if (gSATPlayTone.isIconAvailable)
    {
        if (!SATCheckAllIconGot())
        {
            SATGetIconCompleteCallBack = DisplayPlayToneWindow;
            SATGetIconDataToList();
            return;
        }
    }

    iconData = SATGetIconFromList(gSATPlayTone.iconInfo.iconId);
    EntryNewScreen(SCR_ID_SAT_PLAYTONE, ExitPlayTone, NULL, NULL);

    SetIsInSATScreen();
    gSATContext.historyFuncPtr = DisplayPlayToneWindow;

#ifdef __MMI_SILENT_MEETING_PROFILE__
    if (!IsSilentModeActivated() && !IsMeetingModeActivated())
#else 
    if (!IsSilentModeActivated())
#endif 
    {
        /* not play tone in slient mode */
        AudioPlayReq(gSATPlayTone.toneId, DEVICE_AUDIO_PLAY_INFINITE);
    }

#ifdef __USAT__
    if (gSATPlayTone.vibration)
    {
        VibratorOn();
    }
#endif /* __USAT__ */ 

    ClearHighlightHandler();
    /* micha0726, add abort for test case */
    ShowCategory151Screen(
        0,
        0,
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        gSATPlayTone.alphaId,
        iconData,
        gSATContext.guiBufferPointer);

    SetRightSoftkeyFunction(TerminalResponsePlayToneBackward, KEY_EVENT_UP);
    SetKeyHandler(TerminalResponsePlayToneExpire, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  ExitPlayTone
 * DESCRIPTION
 *  Exit Handler of Play Tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitPlayTone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!gSATPlayTone.sentRsp)
    {
        AudioStopReq(gSATPlayTone.toneId);
    #ifdef __USAT__
        if (gSATPlayTone.vibration)
        {
            VibratorOff();
        }
    #endif /* __USAT__ */ 
        SATSaveHistory();
    }
}


/*****************************************************************************
 * FUNCTION
 *  TerminalResponsePlayToneBackward
 * DESCRIPTION
 *  Key Handler of RSK of Play Tone Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponsePlayToneBackward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AudioStopReq(gSATPlayTone.toneId);
    StopTimer(SAT_PLAY_TONE_TIMER);

    TerminalResponsePlayTone(SAT_PROACTIVE_CMD_TERMINATED_BY_USER, gSATPlayTone.cmdDetail);
    SATPleaseWaitScreen(SAT_WAIT_STRING_ID, SAT_WAIT_IMAGE_ID);
}


/*****************************************************************************
 * FUNCTION
 *  TerminalResponsePlayToneExpire
 * DESCRIPTION
 *  Key Handler of End Key of Play Tone Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponsePlayToneExpire(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AudioStopReq(gSATPlayTone.toneId);
    StopTimer(SAT_PLAY_TONE_TIMER);

    TerminalResponsePlayTone(SAT_PROACTIVE_CMD_TERMINATED_BY_USER, gSATPlayTone.cmdDetail);
    ExitSATToIdle();
}


/*****************************************************************************
 * FUNCTION
 *  TerminalResponsePlayTone
 * DESCRIPTION
 *  Send PLAY TONE REQ to L4
 * PARAMETERS
 *  res         [IN]    Response type
 *  cmdDetail   [IN]    Cmd detail to be sent
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponsePlayTone(U8 res, U8 *cmdDetail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    mmi_sat_play_tone_res_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gSATPlayTone.sentRsp = 1;

    Message = ALLOCATE_ITM(MOD_MMI);
    Message->oslSrcId = MOD_MMI;
    Message->oslMsgId = PRT_MMI_SAT_PLAY_TONE_RES_REQ;
    dataPtr = (mmi_sat_play_tone_res_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_play_tone_res_req_struct));

#ifdef __USAT__
    if (gSATPlayTone.vibration)
    {
        VibratorOff();
    }
#endif /* __USAT__ */ 

    /* diamond, 2005/05/24 icon */
    if (res == SAT_CMD_PERFORMED_SUCCESSFULLY && gSATPlayTone.isIconAvailable == 1 &&
        gSATContext.isCMDIconSupported == MMI_FALSE)
    {
        dataPtr->res = SAT_CMD_PERFORMED_BUT_ICON_COULD_NOT_DSPL;
    }
    else
    {
        /* end, diamond */
        dataPtr->res = res;
    }

    memcpy(dataPtr->cmd_detail, (void*)cmdDetail, 5 * sizeof(U8));
    Message->oslDataPtr = (oslParaType*) dataPtr;
    Message->oslPeerBuffPtr = NULL;
    SEND_MSG_TONE(Message);
    gSATContext.lastSATCmd = SAT_NONE_CMD;
}


/*****************************************************************************
 * FUNCTION
 *  SATPlayToneRsp
 * DESCRIPTION
 *  Protocol Handler for PLAY TONE RES
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATPlayToneRsp(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FreePlayTone();
}


/*****************************************************************************
 * FUNCTION
 *  FreePlayTone
 * DESCRIPTION
 *  Frees various elements of Play Tone structure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FreePlayTone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SATClearAllIcons();
    if (gSATPlayTone.alphaId)
    {
        OslMfree(gSATPlayTone.alphaId);
        gSATPlayTone.alphaId = NULL;
    }

#ifdef __USAT__
    if (gSATPlayTone.textFormatting)
    {
        OslMfree(gSATPlayTone.textFormatting);
    }
    gSATPlayTone.noTextAttribute = 0;
    gSATPlayTone.textFormatting = NULL;
#endif /* __USAT__ */ 
}


#define MMI_SAT_IMAGE_INSTANCE
/*****************************************************************************
 * FUNCTION
 *  SendImageLenRecordReq
 * DESCRIPTION
 *  Sends Request to L4 to Read Image Record Length
 * PARAMETERS
 *  iconId      [IN]    Icon data to be read
 * RETURNS
 *  void
 *****************************************************************************/
void SendImageLenRecordReq(U8 iconId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gSATContext.getImageStage = SAT_IMAGE_READLEN_CMD;
    gSATImageRecord.iconId = iconId;
    SATSendReadSimFileReq(FILE_IMG_IDX, iconId, 1);
}


/*****************************************************************************
 * FUNCTION
 *  SendImageInstRecordReq
 * DESCRIPTION
 *  Reads Image Instance from EFIMG
 * PARAMETERS
 *  satReadSimRes   [IN]    Pointer to SATREADSIMFILERES structure
 * RETURNS
 *  void
 *****************************************************************************/
void SendImageInstRecordReq(mmi_smu_read_sim_rsp_struct *satReadSimRes)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (satReadSimRes->result.flag == L4C_OK)
    {
        if (!satReadSimRes->length)
        {
            gSATImageRecord.noOfImages = 0;
        }
        else
        {
            gSATImageRecord.noOfImages = satReadSimRes->data[0];
        }
        if (gSATImageRecord.noOfImages)
        {
            gSATContext.getImageStage = SAT_IMAGE_READINST_CMD;
            SATSendReadSimFileReq(FILE_IMG_IDX, gSATImageRecord.iconId, 10);
        }
        else
        {
            gSATContext.getImageStage = SAT_IMAGE_IDLE_CMD;
            SATGetIconDataCallBack();
        }
    }
    else
    {
        gSATImageRecord.noOfImages = 0;
        gSATContext.getImageStage = SAT_IMAGE_IDLE_CMD;
        SATGetIconDataCallBack();
    }
}


/*****************************************************************************
 * FUNCTION
 *  SendImageDataRecordReq
 * DESCRIPTION
 *  Reads Image Data from Actual Image File
 * PARAMETERS
 *  satReadSimRes   [IN]    Pointer to SATREADSIMFILERES structure
 * RETURNS
 *  void
 *****************************************************************************/
void SendImageDataRecordReq(mmi_smu_read_sim_rsp_struct *satReadSimRes)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 path[6] = {0x7F, 0x10, 0x5F, 0x50, 0x4F, 0x01}; /* new read sim file interface */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (satReadSimRes->result.flag == L4C_OK)
    {
        if (!satReadSimRes->length)
        {
            gSATImageRecord.noOfImages = 0;
        }
        else
        {
            gSATImageRecord.noOfImages = satReadSimRes->data[0];
        }

        if (gSATImageRecord.noOfImages)
        {
            gSATImageRecord.imageInst = (SATIMAGEINSTANCE*) OslMalloc(sizeof(SATIMAGEINSTANCE));
            gSATImageRecord.noOfImages = 1; /* currently get only the first image */
            gSATImageRecord.imageInst->width = satReadSimRes->data[1];
            gSATImageRecord.imageInst->height = satReadSimRes->data[2];
            gSATImageRecord.imageInst->coding = satReadSimRes->data[3];

            if (gSATImageRecord.imageInst->width == 0 || gSATImageRecord.imageInst->height == 0)
            {
                gSATContext.getImageStage = SAT_IMAGE_IDLE_CMD;
                SATGetIconDataCallBack();
                return;
            }

            gSATImageRecord.imageInst->instance = satReadSimRes->data[4];
            gSATImageRecord.imageInst->instance = (gSATImageRecord.imageInst->instance << 8) + satReadSimRes->data[5];

            gSATImageRecord.imageInst->offset = satReadSimRes->data[6];
            gSATImageRecord.imageInst->offset = (gSATImageRecord.imageInst->offset << 8) + satReadSimRes->data[7];

            gSATImageRecord.imageInst->length = satReadSimRes->data[8];
            gSATImageRecord.imageInst->length = (gSATImageRecord.imageInst->length << 8) + satReadSimRes->data[9];

            if (gSATImageRecord.imageInst->length == 0)
            {
                gSATContext.getImageStage = SAT_IMAGE_IDLE_CMD;
                SATGetIconDataCallBack();
                return;
            }

            if ((gSATImageRecord.imageInst->length % 256) == 0 && (gSATImageRecord.imageInst->length / 256) > 0)
            {
                gSATImageRecord.imageInst->cycle = gSATImageRecord.imageInst->length / 256 - 1;
            }
            else
            {
                gSATImageRecord.imageInst->cycle = gSATImageRecord.imageInst->length / 256;
            }

            if (gSATImageRecord.imageInst->cycle == 0)
            {
                gSATImageRecord.imageInst->reqlength = gSATImageRecord.imageInst->length;
            }
            else
            {
                gSATImageRecord.imageInst->reqlength = 256;
            }

            gSATImageRecord.imageInst->curcycle = 0;

            gSATContext.getImageStage = SAT_IMAGE_READDATA_CMD;

            /* read from EF path, total 6 bytes for path */
            path[5] += (gSATImageRecord.imageInst->instance - 0x4F01);
            mmi_sat_read_sim_file_with_path(
                gSATImageRecord.imageInst->offset,
                gSATImageRecord.imageInst->reqlength,
                path);
        }
        else
        {
            gSATContext.getImageStage = SAT_IMAGE_IDLE_CMD;
            SATGetIconDataCallBack();
        }
    }
    else
    {
        gSATImageRecord.noOfImages = 0;
        gSATContext.getImageStage = SAT_IMAGE_IDLE_CMD;
        SATGetIconDataCallBack();
    }
}


/*****************************************************************************
 * FUNCTION
 *  SendImageDataCallBack
 * DESCRIPTION
 *  CallBack function called when the Image Data has been read &
 *  sends request for color data
 * PARAMETERS
 *  satReadSimRes   [IN]    Pointer to SATREADSIMFILERES structure
 * RETURNS
 *  void
 *****************************************************************************/
void SendImageDataCallBack(mmi_smu_read_sim_rsp_struct *satReadSimRes)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 path[6] = {0x7F, 0x10, 0x5F, 0x50, 0x4F, 0x01}; /* new read sim file interface */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (satReadSimRes->result.flag == L4C_OK)
    {
        if (gSATImageRecord.imageData == NULL)
        {
            gSATImageRecord.imageData = OslMalloc(gSATImageRecord.imageInst->length);
        }

        if (gSATImageRecord.imageInst->cycle == gSATImageRecord.imageInst->curcycle)
        {
            memcpy(
                gSATImageRecord.imageData + ((gSATImageRecord.imageInst->curcycle) * 256),
                satReadSimRes->data,
                satReadSimRes->length);
            if (gSATImageRecord.imageInst->coding != SAT_BASIC_IMAGE)
            {
                gSATImageRecord.noOfCLUT = gSATImageRecord.imageData[3];
                gSATImageRecord.locOfCLUT = gSATImageRecord.imageData[4];
                gSATImageRecord.locOfCLUT = (gSATImageRecord.locOfCLUT << 8) + gSATImageRecord.imageData[5];
                //gSATImageRecord.CLUTData = (SATCOLORDATA*) (gSATImageRecord.imageData + gSATImageRecord.locOfCLUT);
                gSATImageRecord.CLUTData = (SATCOLORDATA*) OslMalloc(gSATImageRecord.noOfCLUT * sizeof(SATCOLORDATA));
                gSATContext.getImageStage = SAT_IMAGE_IDLE_CMD;
                mmi_sat_get_color_lookup_table_req();
            }
            else
            {
                gSATContext.getImageStage = SAT_IMAGE_IDLE_CMD;
                SATGetIconDataCallBack();
            }
        }
        else
        {
            memcpy(
                gSATImageRecord.imageData + ((gSATImageRecord.imageInst->curcycle) * 256),
                satReadSimRes->data,
                satReadSimRes->length);

            gSATImageRecord.imageInst->reqlength = gSATImageRecord.imageInst->length - (256 * (gSATImageRecord.imageInst->curcycle + 1));
            if (gSATImageRecord.imageInst->reqlength > 256)
            {
                gSATImageRecord.imageInst->reqlength = 256;
            }

            gSATImageRecord.imageInst->curcycle = gSATImageRecord.imageInst->curcycle + 1;

            gSATContext.getImageStage = SAT_IMAGE_READDATA_CMD;
            /* read from EF path, total 6 bytes for path */
            path[5] += (gSATImageRecord.imageInst->instance - 0x4F01);
            mmi_sat_read_sim_file_with_path(
                (U16) (gSATImageRecord.imageInst->offset + (gSATImageRecord.imageInst->curcycle) * 256),
                gSATImageRecord.imageInst->reqlength,
                path);
        }
    }
    else
    {
        gSATImageRecord.noOfImages = 0;
        gSATContext.getImageStage = SAT_IMAGE_IDLE_CMD;
        SATGetIconDataCallBack();
    }
}


/*****************************************************************************
 * FUNCTION
 *  SATSendReadSimFileReq
 * DESCRIPTION
 *  Send READ SIM REQ
 * PARAMETERS
 *  fileIdx     [IN]    File Id to be read
 *  recordNo    [IN]    Record No to be read
 *  length      [IN]    Length of record to be read
 * RETURNS
 *  void
 *****************************************************************************/
void SATSendReadSimFileReq(U16 fileIdx, U16 recordNo, U16 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    mmi_smu_read_sim_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SET_EVENT(SATSendReadSimFileRsp, PRT_MMI_SMU_READ_SIM_RSP);

    Message = ALLOCATE_ITM(MOD_MMI);
    Message->oslSrcId = MOD_MMI;
    Message->oslMsgId = PRT_MMI_SMU_READ_SIM_REQ;
    dataPtr = (mmi_smu_read_sim_req_struct*) OslConstructDataPtr(sizeof(mmi_smu_read_sim_req_struct));
    dataPtr->file_idx = (U8) fileIdx;
    dataPtr->para = recordNo;       /* diamond, 2006/05/22 Icon image offset might be larger than 256 */
    dataPtr->length = length;
    memset(dataPtr->path, 0, 6);    /* read from EF path, total 6 bytes for path */
    Message->oslDataPtr = (oslParaType*) dataPtr;
    Message->oslPeerBuffPtr = NULL;
    SEND_MSG_ICON(Message);
}


/*****************************************************************************
 * FUNCTION
 *  SATSendReadSimFileRsp
 * DESCRIPTION
 *  Protocol Handler for SEND SIM RES
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATSendReadSimFileRsp(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_read_sim_rsp_struct *satReadSimRes;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    satReadSimRes = (mmi_smu_read_sim_rsp_struct*) msgPtr;

    CLR_EVENT(PRT_MMI_SMU_READ_SIM_RSP);

    switch (gSATContext.getImageStage)
    {
        case SAT_IMAGE_READLEN_CMD:
            SendImageInstRecordReq(satReadSimRes);
            break;
        case SAT_IMAGE_READINST_CMD:
            SendImageDataRecordReq(satReadSimRes);
            break;
        case SAT_IMAGE_READDATA_CMD:
            SendImageDataCallBack(satReadSimRes);
            break;
    }
}


#define MMI_SAT_EVENT_DOWNLOAD
/*****************************************************************************
 * FUNCTION
 *  SATEVDLIdleScreenAvaliable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SATEVDLIdleScreenAvaliable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SIMAP_SUPPORT__
    if (!g_idle_context.SimReady)
    {
        return;
    }
#endif /* __MMI_SIMAP_SUPPORT__ */

    if (!mmi_bootup_is_sim_removed())
    {
        Message = ALLOCATE_ITM(MOD_MMI);
        Message->oslSrcId = MOD_MMI;
        Message->oslDestId = MOD_L4C;
        Message->oslMsgId = PRT_MMI_SAT_EVDL_IDLE_SCREEN_AVAILABLE_REQ;
        Message->oslDataPtr = NULL;
        Message->oslPeerBuffPtr = NULL;
        Message->sap_id = INVALID_SAP;
        msg_send_ext_queue(Message);
    }

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    if (!mmi_bootup_is_sim2_removed())
    {
        Message = ALLOCATE_ITM(MOD_MMI);
        Message->oslSrcId = MOD_MMI;
        Message->oslDestId = MOD_L4C_2;
        Message->oslMsgId = PRT_MMI_SAT_EVDL_IDLE_SCREEN_AVAILABLE_REQ;
        Message->oslDataPtr = NULL;
        Message->oslPeerBuffPtr = NULL;
        Message->sap_id = INVALID_SAP;
        msg_send_ext_queue(Message);
    }
#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */

    /* diamond, 2005/08/28 record the last selected item for backward move to SAT main menu */
    gSATMainMenu.selectedMenuItem = 0;
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    gSATMainMenu.selectedMenuItem_2 = 0;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  SATEVDLLangSel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lang        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void SATEVDLLangSel(U8 *lang)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    mmi_sat_language_selection_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_bootup_is_sim_removed())
    {
        Message = ALLOCATE_ITM(MOD_MMI);
        Message->oslSrcId = MOD_MMI;
        Message->oslDestId = MOD_L4C;
        Message->oslMsgId = PRT_MMI_SAT_LANGUAGE_SELECTION_REQ;
        dataPtr =
            (mmi_sat_language_selection_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_language_selection_req_struct));
        memcpy(dataPtr->iso639_language, (void*)lang, 2 * sizeof(U8));
        Message->oslDataPtr = (oslParaType*) dataPtr;
        Message->oslPeerBuffPtr = NULL;
        Message->sap_id = INVALID_SAP;
        msg_send_ext_queue(Message);
    }

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    if (!mmi_bootup_is_sim2_removed())
    {
        Message = ALLOCATE_ITM(MOD_MMI);
        Message->oslSrcId = MOD_MMI;
        Message->oslDestId = MOD_L4C_2;
        Message->oslMsgId = PRT_MMI_SAT_LANGUAGE_SELECTION_REQ;
        dataPtr =
            (mmi_sat_language_selection_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_language_selection_req_struct));
        memcpy(dataPtr->iso639_language, (void*)lang, 2 * sizeof(U8));
        Message->oslDataPtr = (oslParaType*) dataPtr;
        Message->oslPeerBuffPtr = NULL;
        Message->sap_id = INVALID_SAP;
        msg_send_ext_queue(Message);
    }
#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
}


/*****************************************************************************
 * FUNCTION
 *  SATEVDLBrowserTerminationInd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATEVDLBrowserTerminationInd(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_evdl_browser_termination_rsp_struct *BrowserTerminationInd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    BrowserTerminationInd = (mmi_sat_evdl_browser_termination_rsp_struct*) msgPtr;

    SATEVDLBrowserTermination((U8) BrowserTerminationInd->result);
}


/*****************************************************************************
 * FUNCTION
 *  SATEVDLBrowserTermination
 * DESCRIPTION
 *  
 * PARAMETERS
 *  res         [IN]    Response type
 * RETURNS
 *  void
 *****************************************************************************/
void SATEVDLBrowserTermination(U8 res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    mmi_sat_evdl_browser_termination_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message = ALLOCATE_ITM(MOD_MMI);
    Message->oslSrcId = MOD_MMI;
    Message->oslMsgId = PRT_MMI_SAT_EVDL_BROWSER_TERMINATION_REQ;
    dataPtr =
        (mmi_sat_evdl_browser_termination_req_struct*)
        OslConstructDataPtr(sizeof(mmi_sat_evdl_browser_termination_req_struct));
    dataPtr->browser_termination_cause = res;
    Message->oslDataPtr = (oslParaType*) dataPtr;
    Message->oslPeerBuffPtr = NULL;
    SEND_MSG(Message);
}


#define MMI_SAT_LANGUAGE_NOTIFICATION
/*****************************************************************************
 * FUNCTION
 *  SATLangNotifyInd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATLangNotifyInd(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_lang_notify_ind_struct *LangNotifyInd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    LangNotifyInd = (mmi_sat_lang_notify_ind_struct*) msgPtr;

    if (LangNotifyInd->is_language_specified == MMI_TRUE)
    {
        SATSetLanguage(LangNotifyInd->iso639_language);
    }
    else
    {
        SATSetLanguage((U8*) "en");
    }

    TerminalResponseLangNotify(SAT_CMD_PERFORMED_SUCCESSFULLY, LangNotifyInd->cmd_detail);
}


/*****************************************************************************
 * FUNCTION
 *  SATSetLanguage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  Lang        [IN]    
 * RETURNS
 *  void
 *****************************************************************************/
void SATSetLanguage(PU8 Lang)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 lang_sel = (U8)GetLanguageIndexByLangCode((S8*) Lang);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strncmp((PS8) Lang, SAT_LANG_ENGLISH, 2) == 0 && gCurrLangIndex != 0)
    {
        lang_sel = 0;
        SetCurrentLanguage(lang_sel);
        WriteValue(NVRAM_SETTING_LANG, &lang_sel, DS_BYTE, &error);
        RefreshNwProviderName(gPLMN);
        DisplayPopup(
            (U8*) GetString(SSC_SCR_LANGUAGE_ENGLISH_STR_ID),
            IMG_GLOBAL_ACTIVATED,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) SUCCESS_TONE);
    }
#ifdef __MMI_LANG_TR_CHINESE__
    else if (strncmp((PS8) Lang, SAT_LANG_CHINESE, 2) == 0 && gCurrLangIndex != lang_sel)
    {
        SetCurrentLanguage(lang_sel);
        WriteValue(NVRAM_SETTING_LANG, &lang_sel, DS_BYTE, &error);
        RefreshNwProviderName(gPLMN);
        DisplayPopup(
            (U8*) GetString(SSC_SCR_LANGUAGE_TCHINESE_STR_ID),
            IMG_GLOBAL_ACTIVATED,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) SUCCESS_TONE);
    }
#endif /* __MMI_LANG_TR_CHINESE__ */
}


/*****************************************************************************
 * FUNCTION
 *  TerminalResponseLangNotify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  res         [IN]    Response type
 *  cmdDetail   [IN]    Cmd detail to be sent
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseLangNotify(U8 res, U8 *cmdDetail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    mmi_sat_lang_notify_res_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message = ALLOCATE_ITM(MOD_MMI);
    Message->oslSrcId = MOD_MMI;
    Message->oslMsgId = PRT_MMI_SAT_LANG_NOTIFY_RES_REQ;
    dataPtr = (mmi_sat_lang_notify_res_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_lang_notify_res_req_struct));
    dataPtr->res = res;
    memcpy(dataPtr->cmd_detail, (void*)cmdDetail, 5 * sizeof(U8));
    Message->oslDataPtr = (oslParaType*) dataPtr;
    Message->oslPeerBuffPtr = NULL;
    SEND_MSG(Message);
}


#define MMI_SAT_LAUNCH_BROWSER
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
/*****************************************************************************
 * FUNCTION
 *  TerminalResponseLaunchBrowserEx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  destId      [IN]    L4/L4_2
 *  res         [IN]    Response type
 *  add_info    [IN]    Additional info
 *  cmdDetail   [IN]    Cmd detail to be sent      
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseLaunchBrowserEx(U8 destId, U8 res, U8 add_info, U8 *cmdDetail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    mmi_sat_launch_browser_res_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message = allocate_ilm(MOD_MMI);
    Message->oslSrcId = MOD_MMI;
    Message->oslDestId = destId;
    Message->oslMsgId = PRT_MMI_SAT_LAUNCH_BROWSER_RES_REQ;
    dataPtr =
        (mmi_sat_launch_browser_res_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_launch_browser_res_req_struct));
    dataPtr->res = res;
    dataPtr->size_of_additional_info = add_info;
    memcpy(dataPtr->cmd_detail, (void*)cmdDetail, 5 * sizeof(U8));
    Message->oslDataPtr = (oslParaType*) dataPtr;
    Message->oslPeerBuffPtr = NULL;
    Message->sap_id = INVALID_SAP;
    msg_send_ext_queue(Message);
}


/*****************************************************************************
 * FUNCTION
 *  SATLaunchBrowserSIM1Ind
 * DESCRIPTION
 *  Protocol Handler for LAUNCH BROWSER IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4-1
 * RETURNS
 *  void
 *****************************************************************************/
void SATLaunchBrowserSIM1Ind(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_launch_browser_ind_struct *LaunchBrowserInd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    LaunchBrowserInd = (mmi_sat_launch_browser_ind_struct*) msgPtr;

    if (gSATContext.CMDfromSIM == SAT_CMD_SIM2)
    {
        TerminalResponseLaunchBrowserEx(MOD_L4C, SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, 0, LaunchBrowserInd->cmd_detail);
    }
    else
    {
        gSATContext.CMDfromSIM = SAT_CMD_SIM1;
        SATLaunchBrowserInd(msgPtr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  SATLaunchBrowserSIM2Ind
 * DESCRIPTION
 *  Protocol Handler for LAUNCH BROWSER IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4-2
 * RETURNS
 *  void
 *****************************************************************************/
void SATLaunchBrowserSIM2Ind(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_launch_browser_ind_struct *LaunchBrowserInd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    LaunchBrowserInd = (mmi_sat_launch_browser_ind_struct*) msgPtr;

    if (gSATContext.CMDfromSIM == SAT_CMD_SIM1)
    {
        TerminalResponseLaunchBrowserEx(MOD_L4C_2, SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, 0, LaunchBrowserInd->cmd_detail);
    }
    else
    {
        gSATContext.CMDfromSIM = SAT_CMD_SIM2;
        SATLaunchBrowserInd(msgPtr);
    }
}

#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */


/*****************************************************************************
 * FUNCTION
 *  SATLaunchBrowserInd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATLaunchBrowserInd(void *msgPtr)
{
#ifdef WAP_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_launch_browser_ind_struct *LaunchBrowserInd;
    pBOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    LaunchBrowserInd = (mmi_sat_launch_browser_ind_struct*) msgPtr;

    FreeLaunchBrowser();

    gSATContext.lastSATCmd = SAT_LAUNCH_BROWSER_CMD;
    gSATContext.guiBufferPointer = NULL;

    if (LaunchBrowserInd->browser_mode == SAT_LAUNCH_BROWSER_IF_NOT_ALREADY_LAUNCHED && wap_browser_is_open())
    {
        TerminalResponseLaunchBrowser(SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, SAT_LAUNCH_BROWSER_BROWSER_UNAVALIABLE, LaunchBrowserInd->cmd_detail);
        return;
    }

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    if (gSATContext.CMDfromSIM == SAT_CMD_SIM2)
    {
        result = mmi_bootup_is_sim2_nw_registration_ok();
    }
    else
    {
        result = mmi_bootup_is_nw_registration_ok();
    }
#else /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
    result = mmi_bootup_is_nw_registration_ok();
#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
    if (result == MMI_FALSE)
    {
        TerminalResponseLaunchBrowser(SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, 0, LaunchBrowserInd->cmd_detail);
        return;
    }

    memcpy(gSATLaunchBrowser.cmdDetail, LaunchBrowserInd->cmd_detail, 5 * sizeof(U8));

    gSATLaunchBrowser.browserMode = LaunchBrowserInd->browser_mode;
    gSATLaunchBrowser.browserIdentity = LaunchBrowserInd->browser_identity;
    memcpy(gSATLaunchBrowser.provisionFileId, LaunchBrowserInd->provision_file_id, 10 * sizeof(U8));

    gSATLaunchBrowser.noAlphaId = LaunchBrowserInd->no_alpha_id;
    gSATLaunchBrowser.dcsOfAlphaId = LaunchBrowserInd->dcs_of_alpha_id;

    gSATLaunchBrowser.isIconAvailable = LaunchBrowserInd->is_icon_available;
    if (gSATLaunchBrowser.isIconAvailable)
    {
        gSATLaunchBrowser.iconInfo.iconId = LaunchBrowserInd->icon_info.icon_id;
        gSATLaunchBrowser.iconInfo.iconAttr = LaunchBrowserInd->icon_info.icon_attr;
    }

    gSATLaunchBrowser.noUrl = LaunchBrowserInd->no_url;
    gSATLaunchBrowser.noBearer = LaunchBrowserInd->no_bearer;
    gSATLaunchBrowser.noGateway = LaunchBrowserInd->no_gateway;
    gSATLaunchBrowser.dcsOfGateway = LaunchBrowserInd->dcs_of_gateway;

    gSATLaunchBrowser.isAlphaIdPresent = LaunchBrowserInd->is_alpha_id_present;
    if (gSATLaunchBrowser.isAlphaIdPresent && gSATLaunchBrowser.noAlphaId)
    {
        gSATLaunchBrowser.alphaId = CovertStringForPlatform(
                                        LaunchBrowserInd->alpha_id,
                                        gSATLaunchBrowser.noAlphaId,
                                        gSATLaunchBrowser.dcsOfAlphaId,
                                        &gSATLaunchBrowser.noAlphaId);
    }
    else
    {
        /* diamond, 2005/01/11 LAUNCH BROWSER confirmation string */
        gSATLaunchBrowser.noAlphaId = mmi_ucs2strlen((PS8) (PU8) GetString(SAT_LAUNCH_BROWSER_CONF_STRING_ID)) * ENCODING_LENGTH;
        gSATLaunchBrowser.alphaId = (PU8) OslMalloc(gSATLaunchBrowser.noAlphaId + ENCODING_LENGTH);
        memcpy(
            gSATLaunchBrowser.alphaId,
            (PU8) GetString(SAT_LAUNCH_BROWSER_CONF_STRING_ID),
            gSATLaunchBrowser.noAlphaId + ENCODING_LENGTH);
    }

    if (gSATLaunchBrowser.noUrl)
    {
        gSATLaunchBrowser.url = CovertStringForPlatform(
                                    LaunchBrowserInd->url,
                                    gSATLaunchBrowser.noUrl,
                                    MMI_DEFAULT_DCS,
                                    &gSATLaunchBrowser.noUrl);
    }

    if (gSATLaunchBrowser.noBearer)
    {
        gSATLaunchBrowser.bearer = CovertStringForPlatform(
                                    LaunchBrowserInd->bearer,
                                    gSATLaunchBrowser.noBearer,
                                    MMI_DEFAULT_DCS,
                                    &gSATLaunchBrowser.noBearer);
    }

    if (gSATLaunchBrowser.noGateway)
    {
        gSATLaunchBrowser.gateway = CovertStringForPlatform(
                                        LaunchBrowserInd->gateway,
                                        gSATLaunchBrowser.noGateway,
                                        gSATLaunchBrowser.dcsOfGateway,
                                        &gSATLaunchBrowser.noGateway);
    }

    SATStopWaitTimer();
    DeleteScreenIfPresent(SCR_ID_SAT_HISTORY);
    if (GetExitScrnID() == SCR_ID_SAT_HISTORY)
    {
        ClearExitHandler();
    }
    GoToLaunchBrowserConformationScreen();
#else /* WAP_SUPPORT */ 
    /* ME cannot support WAP */
    TerminalResponseLaunchBrowser(SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, SAT_LAUNCH_BROWSER_BEARER_UNAVALIABLE, gSATLaunchBrowser.cmdDetail);
#endif /* WAP_SUPPORT */ 
}


#ifdef WAP_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  GoToLaunchBrowserConformationScreen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoToLaunchBrowserConformationScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *iconData = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gSATLaunchBrowser.isIconAvailable)
    {
        SATAddIconIDToList(gSATLaunchBrowser.iconInfo.iconId);
    }

    if (gSATLaunchBrowser.isIconAvailable)
    {
        if (!SATCheckAllIconGot())
        {
            SATGetIconCompleteCallBack = GoToLaunchBrowserConformationScreen;
            SATGetIconDataToList();
            return;
        }
    }

    iconData = SATGetIconFromList(gSATLaunchBrowser.iconInfo.iconId);
    gSATContext.exitCondition = &gSATLaunchBrowser.passedConf;
    EntryNewScreen(SCR_ID_SAT_LAUNCH_BROWSER_CONF, SATGenericExitHandler, NULL, NULL);

    SetIsInSATScreen();
    gSATContext.historyFuncPtr = GoToLaunchBrowserConformationScreen;
    gSATLaunchBrowser.passedConf = 0;
    ShowCategory151Screen(
        0,
        0,
        STR_GLOBAL_YES,
        0,
        STR_GLOBAL_NO,
        0,
        gSATLaunchBrowser.alphaId,
        iconData,
        gSATContext.guiBufferPointer);

    SetKeyHandler(SATSendLaunchBrowserTerminalResponseExpire, KEY_END, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(LaunchBrowserConformationOK, KEY_EVENT_UP);
    SetRightSoftkeyFunction(SATSendLaunchBrowserTerminalResponseUnable, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  LaunchBrowserConformationOK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void LaunchBrowserConformationOK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    wap_mmi_lauch_browser_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gSATLaunchBrowser.passedConf = 1;

    ClearIsInSATScreen();
    Message = ALLOCATE_ITM(MOD_MMI);
    Message->oslSrcId = MOD_MMI;
    Message->oslDestId = wap_get_service_module(PRT_WAP_MMI_LAUNCH_BROWSER_REQ);
    Message->oslMsgId = PRT_WAP_MMI_LAUNCH_BROWSER_REQ;
    dataPtr = (wap_mmi_lauch_browser_req_struct*) OslConstructDataPtr(sizeof(wap_mmi_lauch_browser_req_struct)
                                                          + (gSATLaunchBrowser.noUrl) * ENCODING_LENGTH * sizeof(U8)
                                                          + (gSATLaunchBrowser.noBearer) * ENCODING_LENGTH * sizeof(U8)
                                                          + (gSATLaunchBrowser.noGateway) * ENCODING_LENGTH * sizeof(U8));
    dataPtr->url = (PU8) dataPtr + sizeof(wap_mmi_lauch_browser_req_struct);
    memcpy(dataPtr->url, gSATLaunchBrowser.url, (gSATLaunchBrowser.noUrl) * ENCODING_LENGTH * sizeof(U8));
    dataPtr->bearer = (PU8) dataPtr->url + (gSATLaunchBrowser.noUrl) * ENCODING_LENGTH * sizeof(U8);
    memcpy(dataPtr->bearer, gSATLaunchBrowser.bearer, (gSATLaunchBrowser.noBearer) * ENCODING_LENGTH * sizeof(U8));
    dataPtr->gateway = (PU8) dataPtr->bearer + (gSATLaunchBrowser.noBearer) * ENCODING_LENGTH * sizeof(U8);
    memcpy(dataPtr->gateway, gSATLaunchBrowser.gateway, (gSATLaunchBrowser.noGateway) * ENCODING_LENGTH * sizeof(U8));

    dataPtr->browserMode = gSATLaunchBrowser.browserMode;
    dataPtr->browserIdentity = gSATLaunchBrowser.browserIdentity;
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    if (gSATContext.CMDfromSIM == SAT_CMD_SIM2)
    {
        dataPtr->sim_id = WAP_SIM_ID_SIM2;
    }
    else
    {
        dataPtr->sim_id = WAP_SIM_ID_SIM1;
    }
#else /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
    dataPtr->sim_id = WAP_SIM_ID_DEFAULT;
#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
    dataPtr->noUrl = gSATLaunchBrowser.noUrl;
    dataPtr->noBearer = gSATLaunchBrowser.noBearer;
    dataPtr->noGateway = gSATLaunchBrowser.noGateway;
    Message->oslDataPtr = (oslParaType*) dataPtr;
    Message->oslPeerBuffPtr = NULL;
    Message->sap_id = INVALID_SAP;
    msg_send_ext_queue(Message);

    if ((gSATLaunchBrowser.browserMode == SAT_USE_EXISTING_BROWSER || gSATLaunchBrowser.browserMode == SAT_CLOSE_EXISTING_BROWSER_AND_LAUNCH_NEW) &&
        wap_browser_is_open())
    {
    	GoBackHistory();
    }
}


/*****************************************************************************
 * FUNCTION
 *  WAPLaunchBrowserRsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void WAPLaunchBrowserRsp(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmi_lauch_browser_rsp_struct *wapLaunchBrowserRes;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wapLaunchBrowserRes = (wap_mmi_lauch_browser_rsp_struct*) msgPtr;

    if (wapLaunchBrowserRes->res != SAT_CMD_PERFORMED_SUCCESSFULLY)
    {
        SetIsInSATScreen();
    }
    else
    {
    #if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
        if (gSATContext.satIndex == SAT_CMD_SIM2)
        {
            gSATContext.historyFuncPtr = GoToSATMainMenu_2;
        }
        else
        {
            gSATContext.historyFuncPtr = GoToSATMainMenu;
        }
    #else /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
        gSATContext.historyFuncPtr = GoToSATMainMenu;
    #endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
        GenericExitScreen(SCR_ID_SAT_HISTORY, SATHistoryHandler); /* there should be a WAP browser on top */
    }

    TerminalResponseLaunchBrowser(
        wapLaunchBrowserRes->res,
        wapLaunchBrowserRes->additionalInfo,
        gSATLaunchBrowser.cmdDetail);
    SATPleaseWaitScreen(SAT_WAIT_STRING_ID, SAT_WAIT_IMAGE_ID);
}


/*****************************************************************************
 * FUNCTION
 *  SATSendLaunchBrowserTerminalResponseExpire
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SATSendLaunchBrowserTerminalResponseExpire(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TerminalResponseLaunchBrowser(SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, 0, gSATLaunchBrowser.cmdDetail);
    ExitSATToIdle();
}


/*****************************************************************************
 * FUNCTION
 *  SATSendLaunchBrowserTerminalResponseUnable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SATSendLaunchBrowserTerminalResponseUnable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TerminalResponseLaunchBrowser(SAT_USER_DID_NOT_ACCEPT_THE_PROACTIVE_CMD, 0, gSATLaunchBrowser.cmdDetail);
    SATPleaseWaitScreen(SAT_WAIT_STRING_ID, SAT_WAIT_IMAGE_ID);
}

#endif /* WAP_SUPPORT */


/*****************************************************************************
 * FUNCTION
 *  TerminalResponseLaunchBrowser
 * DESCRIPTION
 *  
 * PARAMETERS
 *  res         [IN]    Response type
 *  add_info    [IN]    Additional info
 *  cmdDetail   [IN]    Cmd detail to be sent      
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseLaunchBrowser(U8 res, U8 add_info, U8 *cmdDetail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    mmi_sat_launch_browser_res_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gSATLaunchBrowser.passedConf = 1;

    Message = ALLOCATE_ITM(MOD_MMI);
    Message->oslSrcId = MOD_MMI;
    Message->oslMsgId = PRT_MMI_SAT_LAUNCH_BROWSER_RES_REQ;
    dataPtr =
        (mmi_sat_launch_browser_res_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_launch_browser_res_req_struct));

    /* diamond, 2005/05/24 icon */
    if (res == SAT_CMD_PERFORMED_SUCCESSFULLY && gSATLaunchBrowser.isIconAvailable == 1 &&
        gSATContext.isCMDIconSupported == MMI_FALSE)
    {
        dataPtr->res = SAT_CMD_PERFORMED_BUT_ICON_COULD_NOT_DSPL;
    }
    else
    {
        /* end, diamond */
        dataPtr->res = res;
    }
    dataPtr->size_of_additional_info = add_info;

    memcpy(dataPtr->cmd_detail, (void*)cmdDetail, 5 * sizeof(U8));
    Message->oslDataPtr = (oslParaType*) dataPtr;
    Message->oslPeerBuffPtr = NULL;
    SEND_MSG(Message);
    gSATContext.lastSATCmd = SAT_NONE_CMD;
}


/*****************************************************************************
 * FUNCTION
 *  SATLaunchBrowserRsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATLaunchBrowserRsp(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FreeLaunchBrowser();
}


/*****************************************************************************
 * FUNCTION
 *  FreeLaunchBrowser
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FreeLaunchBrowser(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SATClearAllIcons();
    if (gSATLaunchBrowser.alphaId)
    {
        OslMfree(gSATLaunchBrowser.alphaId);
        gSATLaunchBrowser.alphaId = NULL;
    }

    if (gSATLaunchBrowser.url)
    {
        OslMfree(gSATLaunchBrowser.url);
        gSATLaunchBrowser.url = NULL;
    }

    if (gSATLaunchBrowser.bearer)
    {
        OslMfree(gSATLaunchBrowser.bearer);
        gSATLaunchBrowser.bearer = NULL;
    }

    if (gSATLaunchBrowser.gateway)
    {
        OslMfree(gSATLaunchBrowser.gateway);
        gSATLaunchBrowser.gateway = NULL;
    }
}


#define MMI_SAT_SEND_DTMF
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
/*****************************************************************************
 * FUNCTION
 *  TerminalResponseSendDTMF_2
 * DESCRIPTION
 *  Send SEND DTMF STAGE2 REQ to L4 or L4_2 by destId
 * PARAMETERS
 *  destId      [IN]    L4/L4_2
 *  res         [IN]    Response type
 *  addInfo     [IN]    Additional info
 *  cmdDetail   [IN]    Cmd detail to be sent
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseSendDTMF_2(U8 destId, U8 res, U8 addInfo, U8 *cmdDetail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    mmi_sat_send_dtmf_stage2_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message = allocate_ilm(MOD_MMI);
    Message->oslSrcId = MOD_MMI;
    Message->oslDestId = destId;
    Message->oslMsgId = PRT_MMI_SAT_SEND_DTMF_STAGE2_REQ;
    dataPtr = (mmi_sat_send_dtmf_stage2_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_send_dtmf_stage2_req_struct));
    dataPtr->res = res;
    dataPtr->additional_info = addInfo;
    memcpy(dataPtr->cmd_detail, cmdDetail, 5 * sizeof(U8));
    Message->oslDataPtr = (oslParaType*) dataPtr;
    Message->oslPeerBuffPtr = NULL;
    Message->sap_id = INVALID_SAP;
    msg_send_ext_queue(Message);
}


/*****************************************************************************
 * FUNCTION
 *  SATSendDTMFSIM1Ind
 * DESCRIPTION
 *  Protocol Handler for SEND DTMF IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4-1
 * RETURNS
 *  void
 *****************************************************************************/
void SATSendDTMFSIM1Ind(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_send_dtmf_ind_struct *sendDTMFInd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sendDTMFInd = (mmi_sat_send_dtmf_ind_struct*) msgPtr;

    if (gSATContext.CMDfromSIM == SAT_CMD_SIM2)
    {
        TerminalResponseSendDTMF_2(MOD_L4C, SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, 0, sendDTMFInd->cmd_detail);
    }
    else
    {
        gSATContext.CMDfromSIM = SAT_CMD_SIM1;
        SATSendDTMFInd(msgPtr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  SATSendDTMFSIM2Ind
 * DESCRIPTION
 *  Protocol Handler for SEND DTMF IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4-2
 * RETURNS
 *  void
 *****************************************************************************/
void SATSendDTMFSIM2Ind(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_send_dtmf_ind_struct *sendDTMFInd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sendDTMFInd = (mmi_sat_send_dtmf_ind_struct*) msgPtr;

    if (gSATContext.CMDfromSIM == SAT_CMD_SIM1)
    {
        TerminalResponseSendDTMF_2(MOD_L4C_2, SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, 0, sendDTMFInd->cmd_detail);
    }
    else
    {
        gSATContext.CMDfromSIM = SAT_CMD_SIM2;
        SATSendDTMFInd(msgPtr);
    }
}

#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */


/*****************************************************************************
 * FUNCTION
 *  SATSendDTMFInd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATSendDTMFInd(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_send_dtmf_ind_struct *sendDTMFInd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sendDTMFInd = (mmi_sat_send_dtmf_ind_struct*) msgPtr;

    FreeSendDTMF();

    gSATContext.lastSATCmd = SAT_SEND_DTMF_CMD;
    gSATContext.guiBufferPointer = NULL;
    gSATSendDTMF.stage1Res = 0;

    if (isIncomingCall() || isOutgoingCall() ||
#ifdef __MMI_UCM__
    mmi_ucm_app_active_call(MMI_UCM_CALL_TYPE_ALL) == 0
#else /* __MMI_UCM__ */
    GetTotalActiveCallCount() == 0
#endif /* __MMI_UCM__ */
    )
    {
        TerminalResponseSendDTMF(
            SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD,
            SAT_NOT_IN_SPEECH_MODE,
            sendDTMFInd->cmd_detail);
        return;
    }

    memcpy(gSATSendDTMF.cmdDetail, sendDTMFInd->cmd_detail, 5 * sizeof(U8));

    gSATSendDTMF.dcsOfAlphaId = sendDTMFInd->dcs_of_alpha_id;
    gSATSendDTMF.noAlphaId = sendDTMFInd->no_alpha_id;

    if (sendDTMFInd->is_alpha_id_present)
    {
        if (gSATSendDTMF.noAlphaId)
        {
            gSATSendDTMF.alphaId = CovertStringForPlatform(
                                       sendDTMFInd->alpha_id,
                                       gSATSendDTMF.noAlphaId,
                                       gSATSendDTMF.dcsOfAlphaId,
                                       &gSATSendDTMF.noAlphaId);
            gSATSendDTMF.informUser = 1;
        }
        else
        {
            gSATSendDTMF.informUser = 0;
        }
    }
    else
    {
        gSATSendDTMF.noAlphaId = mmi_ucs2strlen((PS8) (PU8) GetString(SAT_SEND_DTMF_STRING_ID)) * ENCODING_LENGTH;
        gSATSendDTMF.alphaId = (PU8) OslMalloc(gSATSendDTMF.noAlphaId + ENCODING_LENGTH);
        memcpy(
            gSATSendDTMF.alphaId,
            (PU8) GetString(SAT_SEND_DTMF_STRING_ID),
            gSATSendDTMF.noAlphaId + ENCODING_LENGTH);
        gSATSendDTMF.informUser = 1;
    }

    gSATSendDTMF.noDtmf = sendDTMFInd->no_dtmf;
    gSATSendDTMF.dtmf = (PU8) OslMalloc(gSATSendDTMF.noDtmf * sizeof(U8) + 1);
    memcpy(gSATSendDTMF.dtmf, sendDTMFInd->dtmf, gSATSendDTMF.noDtmf * sizeof(U8) + 1);

    gSATSendDTMF.isIconAvailable = sendDTMFInd->is_icon_available;
    if (gSATSendDTMF.isIconAvailable)
    {
        gSATSendDTMF.iconInfo.iconId = sendDTMFInd->icon_info.icon_id;
        gSATSendDTMF.iconInfo.iconAttr = sendDTMFInd->icon_info.icon_attr;
    }

    if (gSATSendDTMF.isIconAvailable && gSATSendDTMF.iconInfo.iconAttr == SAT_ICON_SELF_EX)
    {
        if (gSATSendDTMF.alphaId)
        {
            OslMfree(gSATSendDTMF.alphaId);
            gSATSendDTMF.alphaId = NULL;
        }
    }

    if (gSATSendDTMF.informUser)
    {
        SATStopWaitTimer();
        DeleteScreenIfPresent(SCR_ID_SAT_HISTORY);
        if (GetExitScrnID() == SCR_ID_SAT_HISTORY)
        {
            ClearExitHandler();
        }
        gSATSendDTMF.passedConf = 0;
        StartTimer(SAT_SEND_DTMF_TIMER, 1000, DisplayDTMFWindow);
    }
    else
    {
        SATSendDTMFStage1Req();
    }
}


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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


/*****************************************************************************
 * FUNCTION
 *  SATSendDTMFTerminalResponseExpire
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SATSendDTMFTerminalResponseExpire(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TerminalResponseSendDTMF(SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, 0, gSATSendDTMF.cmdDetail);
    ExitSATToIdle();
}


/*****************************************************************************
 * FUNCTION
 *  SATSendDTMFTerminalResponseUnable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SATSendDTMFTerminalResponseUnable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TerminalResponseSendDTMF(SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, 0, gSATSendDTMF.cmdDetail);
    SATPleaseWaitScreen(SAT_WAIT_STRING_ID, SAT_WAIT_IMAGE_ID);
}


/*****************************************************************************
 * FUNCTION
 *  SATSendDTMFStage1Req
 * DESCRIPTION
 *  Send SEND DTMF STAGE1 REQ
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SATSendDTMFStage1Req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    mmi_sat_send_dtmf_stage1_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gSATSendDTMF.passedConf = 1;
    gSATContext.gotStage1Rsp = 0;

    Message = ALLOCATE_ITM(MOD_MMI);
    Message->oslSrcId = MOD_MMI;
    Message->oslMsgId = PRT_MMI_SAT_SEND_DTMF_STAGE1_REQ;
    dataPtr = (mmi_sat_send_dtmf_stage1_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_send_dtmf_stage1_req_struct));

    dataPtr->no_digit = gSATSendDTMF.noDtmf;
    if (dataPtr->no_digit <= MAX_CC_ADDR_BCD_LEN)
    {
        memcpy(dataPtr->dtmf_digit, gSATSendDTMF.dtmf, dataPtr->no_digit);
    }
    else
    {
        memcpy(dataPtr->dtmf_digit, gSATSendDTMF.dtmf, MAX_CC_ADDR_BCD_LEN);
    }

    Message->oslDataPtr = (oslParaType*) dataPtr;
    Message->oslPeerBuffPtr = NULL;
    SEND_MSG(Message);
}


/*****************************************************************************
 * FUNCTION
 *  DisplayDTMFWindow
 * DESCRIPTION
 *  Displays Sending DTMF Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DisplayDTMFWindow(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *iconData = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gSATSendDTMF.isIconAvailable)
    {
        SATAddIconIDToList(gSATSendDTMF.iconInfo.iconId);
    }

    if (gSATSendDTMF.isIconAvailable)
    {
        if (!SATCheckAllIconGot())
        {
            SATGetIconCompleteCallBack = DisplayDTMFWindow;
            SATGetIconDataToList();
            return;
        }
    }

    /* Get icon data first then play DTMF */
    if (gSATSendDTMF.passedConf == 0)
    {
        /* press OK to send DTMF but not send the request yet */
        SATSendDTMFStage1Req();
    }

    iconData = SATGetIconFromList(gSATSendDTMF.iconInfo.iconId);
    gSATContext.exitCondition = &gSATSendDTMF.stage1Res;
    EntryNewScreen(SCR_ID_SAT_SENDDTMF, SATGenericExitHandler, NULL, NULL);

    SetIsInSATScreen();
    gSATContext.historyFuncPtr = DisplayDTMFWindow;
    ClearHighlightHandler();
    ShowCategory151Screen(
        0,
        0,
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        gSATSendDTMF.alphaId,
        iconData,
        gSATContext.guiBufferPointer);

    SetRightSoftkeyFunction(SATSendDTMFAbortReq, KEY_EVENT_UP);
    SetKeyHandler(SATSendDTMFAbortReq, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  SATSendDTMFAbortReq
 * DESCRIPTION
 *  Send SEND DTMF Abort REQ
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SATSendDTMFAbortReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message = ALLOCATE_ITM(MOD_MMI);
    Message->oslSrcId = MOD_MMI;
    Message->oslMsgId = PRT_MMI_SAT_ABORT_DTMF_REQ;
    Message->oslDataPtr = NULL;
    Message->oslPeerBuffPtr = NULL;
    SEND_MSG(Message);
}


/*****************************************************************************
 * FUNCTION
 *  SATSendDTMFStage1Rsp
 * DESCRIPTION
 *  Protocol Handler for SEND DTMF STAGE 1 RES
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATSendDTMFStage1Rsp(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_send_dtmf_stage1_rsp_struct *sendDTMFStage1Res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sendDTMFStage1Res = (mmi_sat_send_dtmf_stage1_rsp_struct*) msgPtr;
    gSATSendDTMF.stage1Res = 1;
    gSATContext.gotStage1Rsp = 1;

    if (gSATContext.lastSATCmd == SAT_NONE_CMD)
    {
        return;
    }

    TerminalResponseSendDTMF(sendDTMFStage1Res->terminal_res, (U8) sendDTMFStage1Res->cause, gSATSendDTMF.cmdDetail);

    if (gSATSendDTMF.informUser)
    {
        if (sendDTMFStage1Res->terminal_res == SAT_CMD_PERFORMED_SUCCESSFULLY ||
            sendDTMFStage1Res->terminal_res == SAT_CMD_PERFORMED_WITH_PARTIAL_COMPREHENSION ||
            sendDTMFStage1Res->terminal_res == SAT_CMD_PERFORMED_WITH_MISSING_INFO)
        {
            SATPleaseWaitScreen(SAT_DTMF_SUCCESS_STRING_ID, 0);
        }
        else
        {
            SATPleaseWaitScreen(SAT_DTMF_ERROR_STRING_ID, 0);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  TerminalResponseSendDTMF
 * DESCRIPTION
 *  Send SEND DTMF STAGE2 REQ to L4
 * PARAMETERS
 *  res         [IN]    Response type
 *  addInfo     [IN]    Additional info
 *  cmdDetail   [IN]    Cmd detail to be sent
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseSendDTMF(U8 res, U8 addInfo, U8 *cmdDetail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    mmi_sat_send_dtmf_stage2_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gSATSendDTMF.passedConf = 1;

    Message = ALLOCATE_ITM(MOD_MMI);
    Message->oslSrcId = MOD_MMI;
    Message->oslMsgId = PRT_MMI_SAT_SEND_DTMF_STAGE2_REQ;
    dataPtr = (mmi_sat_send_dtmf_stage2_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_send_dtmf_stage2_req_struct));

    /* diamond, 2005/05/24 icon */
    if (res == SAT_CMD_PERFORMED_SUCCESSFULLY && gSATSendDTMF.isIconAvailable == 1 &&
        gSATContext.isCMDIconSupported == MMI_FALSE)
    {
        dataPtr->res = SAT_CMD_PERFORMED_BUT_ICON_COULD_NOT_DSPL;
    }
    else
    {
        /* end, diamond */
        dataPtr->res = res;
    }
    dataPtr->additional_info = addInfo;

    memcpy(dataPtr->cmd_detail, cmdDetail, 5 * sizeof(U8));
    Message->oslDataPtr = (oslParaType*) dataPtr;
    Message->oslPeerBuffPtr = NULL;
    SEND_MSG(Message);
    gSATContext.lastSATCmd = SAT_NONE_CMD;
}


/*****************************************************************************
 * FUNCTION
 *  SATSendDTMFStage2Rsp
 * DESCRIPTION
 *  Protocol Handler for SEND DTMF STAGE 2 RES
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATSendDTMFStage2Rsp(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FreeSendDTMF();
}


/*****************************************************************************
 * FUNCTION
 *  FreeSendDTMF
 * DESCRIPTION
 *  Frees various elements of Send DTMF Structure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FreeSendDTMF(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SATClearAllIcons();
    if (gSATSendDTMF.alphaId)
    {
        OslMfree(gSATSendDTMF.alphaId);
        gSATSendDTMF.alphaId = NULL;
    }

    if (gSATSendDTMF.dtmf)
    {
        OslMfree(gSATSendDTMF.dtmf);
        gSATSendDTMF.dtmf = NULL;
    }
}


#define MMI_SAT_SETUP_IDLE_DISPLAY
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
/*****************************************************************************
 * FUNCTION
 *  TerminalResponseSetupIdleDisplayEx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  destId      [IN]    L4/L4_2
 *  res         [IN]    Response type
 *  cmdDetail   [IN]    Cmd detail to be sent
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseSetupIdleDisplayEx(U8 destId, U8 res, U8 *cmdDetail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    mmi_sat_setup_idle_display_res_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message = allocate_ilm(MOD_MMI);
    Message->oslSrcId = MOD_MMI;
    Message->oslDestId = destId;
    Message->oslMsgId = PRT_MMI_SAT_SETUP_IDLE_DISPLAY_RES_REQ;
    dataPtr =
        (mmi_sat_setup_idle_display_res_req_struct*)
        OslConstructDataPtr(sizeof(mmi_sat_setup_idle_display_res_req_struct));
    dataPtr->res = res;
    memcpy(dataPtr->cmd_detail, cmdDetail, 5 * sizeof(U8));
    Message->oslDataPtr = (oslParaType*) dataPtr;
    Message->oslPeerBuffPtr = NULL;
    Message->sap_id = INVALID_SAP;
    msg_send_ext_queue(Message);
}


/*****************************************************************************
 * FUNCTION
 *  SATSetupIdleDisplaySIM1Ind
 * DESCRIPTION
 *  Protocol Handler for SETUP IDLE DISPLAY IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4-1
 * RETURNS
 *  void
 *****************************************************************************/
void SATSetupIdleDisplaySIM1Ind(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_setup_idle_display_ind_struct *setupIdleDisplayInd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setupIdleDisplayInd = (mmi_sat_setup_idle_display_ind_struct*) msgPtr;

    if (gSATContext.CMDfromSIM == SAT_CMD_SIM2)
    {
        TerminalResponseSetupIdleDisplayEx(MOD_L4C, SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, setupIdleDisplayInd->cmd_detail);
    }
    else
    {
        gSATContext.CMDfromSIM = SAT_CMD_SIM1;
        SATSetupIdleDisplayInd(msgPtr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  SATSetupIdleDisplaySIM2Ind
 * DESCRIPTION
 *  Protocol Handler for SETUP IDLE DISPLAY IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4-2
 * RETURNS
 *  void
 *****************************************************************************/
void SATSetupIdleDisplaySIM2Ind(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_setup_idle_display_ind_struct *setupIdleDisplayInd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setupIdleDisplayInd = (mmi_sat_setup_idle_display_ind_struct*) msgPtr;

    if (gSATContext.CMDfromSIM == SAT_CMD_SIM1)
    {
        TerminalResponseSetupIdleDisplayEx(MOD_L4C_2, SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, setupIdleDisplayInd->cmd_detail);
    }
    else
    {
        gSATContext.CMDfromSIM = SAT_CMD_SIM2;
        SATSetupIdleDisplayInd(msgPtr);
    }
}

#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */


/*****************************************************************************
 * FUNCTION
 *  SATSetupIdleDisplayInd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATSetupIdleDisplayInd(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_setup_idle_display_ind_struct *setupIdleDisplayInd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setupIdleDisplayInd = (mmi_sat_setup_idle_display_ind_struct*) msgPtr;

    if (setupIdleDisplayInd->is_icon_available && !setupIdleDisplayInd->no_text_string)
    {
        TerminalResponseSetupIdleDisplay(SAT_CMD_DATA_NOT_UNDERSTAND_BY_ME, setupIdleDisplayInd->cmd_detail);
        return;
    }

    SATClearAllIcons();
    if (gSATContext.idleTextPtr != NULL)
    {
        OslMfree(gSATContext.idleTextPtr);
        gSATContext.idleTextPtr = NULL;
    }

#ifndef __MMI_SAT_LARGE_ICON_SUPPORT__
    if (gSATContext.idleIconPtr != NULL)
    {
        OslMfree(gSATContext.idleIconPtr);
        gSATContext.idleIconPtr = NULL;
    }
#endif /* __MMI_SAT_LARGE_ICON_SUPPORT__ */

    memcpy(gSATDisplayIdleText.cmdDetail, (void*)setupIdleDisplayInd->cmd_detail, 5 * sizeof(U8));

    gSATDisplayIdleText.noTextString = setupIdleDisplayInd->no_text_string;
    gSATDisplayIdleText.dcsOfTextString = setupIdleDisplayInd->dcs_of_text_string;

    /* Spec 12.15, always gsm default encoding */
    if (gSATDisplayIdleText.dcsOfTextString == MMI_8BIT_DCS)
    {
        gSATDisplayIdleText.dcsOfTextString = MMI_DEFAULT_DCS;
    }

    mmi_sat_remove_text_pending_characters(
        setupIdleDisplayInd->text_string,
        &gSATDisplayIdleText.noTextString,
        gSATDisplayIdleText.dcsOfTextString);

    if (gSATDisplayIdleText.noTextString)
    {
        gSATDisplayIdleText.textString = CovertStringForPlatform(
                                            setupIdleDisplayInd->text_string,
                                            gSATDisplayIdleText.noTextString,
                                            gSATDisplayIdleText.dcsOfTextString,
                                            &gSATDisplayIdleText.noTextString);
    }
    else
    {
        if (mmi_idle_is_on_idle_screen())
        {
            idle_screen_show_network_details(); /* EntryIdleScreen(); */
        }
        TerminalResponseSetupIdleDisplay(SAT_CMD_PERFORMED_SUCCESSFULLY, gSATDisplayIdleText.cmdDetail);
        return;
    }

    gSATDisplayIdleText.isIconAvailable = setupIdleDisplayInd->is_icon_available;
    if (gSATDisplayIdleText.isIconAvailable)
    {
        gSATDisplayIdleText.iconInfo.iconId = setupIdleDisplayInd->icon_info.icon_id;
        gSATDisplayIdleText.iconInfo.iconAttr = setupIdleDisplayInd->icon_info.icon_attr;
    }

    GoToSATSetupIdleDisplay();
}


/*****************************************************************************
 * FUNCTION
 *  GoToSATSetupIdleDisplay
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoToSATSetupIdleDisplay(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *iconData = NULL;
    U32 iconSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gSATDisplayIdleText.isIconAvailable)
    {
        SATAddIconIDToList(gSATDisplayIdleText.iconInfo.iconId);
    }

    if (gSATDisplayIdleText.isIconAvailable)
    {
        if (!SATCheckAllIconGot())
        {
            SATGetIconCompleteCallBack = GoToSATSetupIdleDisplay;
            SATGetIconDataToList();
            return;
        }
    }

    /* no limitation for the characters of SET UP IDLE DISPLAY */
    gSATContext.idleTextPtr = OslMalloc(sizeof(U8) * gSATDisplayIdleText.noTextString);
    memset(gSATContext.idleTextPtr, 0, gSATDisplayIdleText.noTextString);
    mmi_ucs2cpy((PS8) gSATContext.idleTextPtr, (PS8) gSATDisplayIdleText.textString);

    if (gSATDisplayIdleText.isIconAvailable)
    {
        iconData = SATGetIconFromList(gSATDisplayIdleText.iconInfo.iconId);
        if (iconData != NULL)
        {
            iconSize =
                (U32) iconData[2] + (((U32) iconData[3]) << 8) + (((U32) iconData[4]) << 16) + 22;
        #ifdef __MMI_SAT_LARGE_ICON_SUPPORT__
            gSATContext.idleIconPtr = (U8*) g_sat_idle_icon;
            memcpy(g_sat_idle_icon, iconData, iconSize);
        #else
            gSATContext.idleIconPtr = OslMalloc(sizeof(U8) * iconSize);
            memcpy(gSATContext.idleIconPtr, iconData, iconSize);
        #endif
        }
    }

    if (gSATDisplayIdleText.isIconAvailable && gSATDisplayIdleText.iconInfo.iconAttr == SAT_ICON_SELF_EX && iconData != NULL)
    {
        if (gSATContext.idleTextPtr)
        {
            OslMfree(gSATContext.idleTextPtr);
            gSATContext.idleTextPtr = NULL;
        }
    }

    if (mmi_idle_is_on_idle_screen())
    {
        idle_screen_show_network_details(); /* EntryIdleScreen(); */
    }

    TerminalResponseSetupIdleDisplay(SAT_CMD_PERFORMED_SUCCESSFULLY, gSATDisplayIdleText.cmdDetail);

    if (gSATDisplayIdleText.textString)
    {
        OslMfree(gSATDisplayIdleText.textString);
        gSATDisplayIdleText.textString = NULL;
    }
    SATClearAllIcons();
}


/*****************************************************************************
 * FUNCTION
 *  TerminalResponseSetupIdleDisplay
 * DESCRIPTION
 *  
 * PARAMETERS
 *  res         [IN]    Response type
 *  cmdDetail   [IN]    Cmd detail to be sent
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseSetupIdleDisplay(U8 res, U8 *cmdDetail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    mmi_sat_setup_idle_display_res_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message = ALLOCATE_ITM(MOD_MMI);
    Message->oslSrcId = MOD_MMI;
    Message->oslMsgId = PRT_MMI_SAT_SETUP_IDLE_DISPLAY_RES_REQ;
    dataPtr =
        (mmi_sat_setup_idle_display_res_req_struct*)
        OslConstructDataPtr(sizeof(mmi_sat_setup_idle_display_res_req_struct));

    /* diamond, 2005/05/24 icon */
    if (res == SAT_CMD_PERFORMED_SUCCESSFULLY && gSATDisplayIdleText.isIconAvailable == 1 &&
        gSATContext.isCMDIconSupported == MMI_FALSE)
    {
        dataPtr->res = SAT_CMD_PERFORMED_BUT_ICON_COULD_NOT_DSPL;
    }
    else
    {
        /* end, diamond */
        dataPtr->res = res;
    }

    memcpy(dataPtr->cmd_detail, cmdDetail, 5 * sizeof(U8));
    Message->oslDataPtr = (oslParaType*) dataPtr;
    Message->oslPeerBuffPtr = NULL;
    SEND_MSG(Message);
}


#define MMI_SAT_RUN_AT_COMMAND
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
/*****************************************************************************
 * FUNCTION
 *  SATRunATCommandSIM1Ind
 * DESCRIPTION
 *  Protocol Handler for RUN AT COMMAND IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4-1
 * RETURNS
 *  void
 *****************************************************************************/
void SATRunATCommandSIM1Ind(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gSATContext.CMDfromSIM == SAT_CMD_SIM2)
    {
        return;
    }
    else
    {
        gSATContext.CMDfromSIM = SAT_CMD_SIM1;
        SATRunATCommandInd(msgPtr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  SATRunATCommandSIM2Ind
 * DESCRIPTION
 *  Protocol Handler for RUN AT COMMAND IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4-2
 * RETURNS
 *  void
 *****************************************************************************/
void SATRunATCommandSIM2Ind(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gSATContext.CMDfromSIM == SAT_CMD_SIM1)
    {
        return;
    }
    else
    {
        gSATContext.CMDfromSIM = SAT_CMD_SIM2;
        SATRunATCommandInd(msgPtr);
    }
}

#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */


/*****************************************************************************
 * FUNCTION
 *  SATRunATCommandInd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATRunATCommandInd(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_run_at_command_ind_struct *displayATCommand;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    displayATCommand = (mmi_sat_run_at_command_ind_struct*) msgPtr;

    if (isIncomingCall() || isOutgoingCall())
    {
        return;
    }

    SATClearAllIcons();
    if (gSATRunATCommand.alphaID)
    {
        OslMfree(gSATRunATCommand.alphaID);
        gSATRunATCommand.alphaID = NULL;
    }

    memcpy(gSATRunATCommand.cmdDetail, (void*)displayATCommand->cmd_detail, 5 * sizeof(U8));

    gSATRunATCommand.isIconAvailable = displayATCommand->is_icon_available;
    if (gSATRunATCommand.isIconAvailable)
    {
        gSATRunATCommand.iconInfo.iconId = displayATCommand->icon_info.icon_id;
        gSATRunATCommand.iconInfo.iconAttr = displayATCommand->icon_info.icon_attr;
    }

    gSATRunATCommand.noAlphaId = displayATCommand->no_alpha_id;
    gSATRunATCommand.dcsOfAlphaId = displayATCommand->dcs_of_alpha_id;

    gSATRunATCommand.isAlphaIdPresent = displayATCommand->is_alpha_id_present;
    if (gSATRunATCommand.isAlphaIdPresent)
    {
        if (gSATRunATCommand.noAlphaId)
        {
            gSATRunATCommand.alphaID = CovertStringForPlatform(
                                        displayATCommand->alpha_id,
                                        gSATRunATCommand.noAlphaId,
                                        gSATRunATCommand.dcsOfAlphaId,
                                        &gSATRunATCommand.noAlphaId);
            gSATRunATCommand.informUser = 1;
        }
        else
        {
            gSATRunATCommand.informUser = 0;
        }
    }
    else
    {
        gSATRunATCommand.informUser = 0;
    }

    if (gSATRunATCommand.isIconAvailable && gSATRunATCommand.iconInfo.iconAttr == SAT_ICON_SELF_EX)
    {
        if (gSATRunATCommand.alphaID)
        {
            OslMfree(gSATRunATCommand.alphaID);
            gSATRunATCommand.alphaID = NULL;
        }
    }

    if (gSATRunATCommand.informUser)
    {
        SATStopWaitTimer();
        DeleteScreenIfPresent(SCR_ID_SAT_HISTORY);
        if (GetExitScrnID() == SCR_ID_SAT_HISTORY)
        {
            ClearExitHandler();
        }
        DisplayATCommandScreen();
    }
    else
    {
        if (gSATRunATCommand.alphaID)
        {
            OslMfree(gSATRunATCommand.alphaID);
            gSATRunATCommand.alphaID = NULL;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  DisplayATCommandScreen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DisplayATCommandScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *iconData = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gSATRunATCommand.isIconAvailable)
    {
        SATAddIconIDToList(gSATRunATCommand.iconInfo.iconId);
    }

    if (gSATRunATCommand.isIconAvailable)
    {
        if (!SATCheckAllIconGot())
        {
            SATGetIconCompleteCallBack = DisplayATCommandScreen;
            SATGetIconDataToList();
            return;
        }
    }

    iconData = SATGetIconFromList(gSATRunATCommand.iconInfo.iconId);
    EntryNewScreen(SCR_ID_SAT_SEND_AT_CMD, ExitDisplayATCommandScreen, NULL, NULL);

    ShowCategory151Screen(0, 0, 0, 0, 0, 0, gSATRunATCommand.alphaID, iconData, NULL);
    StartTimer(POPUP_TIMER, 1000, DisplayATCommandTimerOver);
}


/*****************************************************************************
 * FUNCTION
 *  ExitDisplayATCommandScreen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitDisplayATCommandScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SATClearAllIcons();
    if (gSATRunATCommand.alphaID)
    {
        OslMfree(gSATRunATCommand.alphaID);
        gSATRunATCommand.alphaID = NULL;
    }
    StopTimer(POPUP_TIMER);
}


/*****************************************************************************
 * FUNCTION
 *  DisplayATCommandTimerOver
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DisplayATCommandTimerOver(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SATClearAllIcons();
    if (gSATRunATCommand.alphaID)
    {
        OslMfree(gSATRunATCommand.alphaID);
        gSATRunATCommand.alphaID = NULL;
    }
    StopTimer(POPUP_TIMER);
    GoBackHistory();
}


#define MMI_SAT_SAVE_HISTORY
/*****************************************************************************
 * FUNCTION
 *  SATHistoryHandler
 * DESCRIPTION
 *  Calls Corresponding Function in History
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SATHistoryHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetIsInSATScreen();
    gSATContext.guiBufferPointer = GetCurrGuiBuffer(SCR_ID_SAT_HISTORY);
    (*gSATContext.historyFuncPtr) ();
}


/*****************************************************************************
 * FUNCTION
 *  SATSaveHistory
 * DESCRIPTION
 *  Saves SAT in History
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SATSaveHistory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GenericExitScreen(SCR_ID_SAT_HISTORY, SATHistoryHandler);
    ClearIsInSATScreen();
}


/*****************************************************************************
 * FUNCTION
 *  SATGenericExitHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SATGenericExitHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* diamond, 2005/07/22 GET INPUT numeric input without 'p' and 'w' */
    MMI_current_input_ext_type &= ~INPUT_TYPE_EXT_SIM_NUMERIC;

#ifdef __MMI_SAT_DISPLAY_TEXT_WITH_KEYPAD_LOCK__
    if (gSATContext.idleSATCmd)
    {
        //PRINT_INFORMATION("[SAT] NOT save SAT screen to the history");
    }
    else
#endif /* __MMI_SAT_DISPLAY_TEXT_WITH_KEYPAD_LOCK__ */
    if (!(*gSATContext.exitCondition))
    {
        //PRINT_INFORMATION("[SAT] save SAT screen to the history");
        SATSaveHistory();
    }
    else
    {
        //PRINT_INFORMATION("[SAT] NOT save SAT screen to the history");
    }
}


/*****************************************************************************
 * FUNCTION
 *  SATScrKeyHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  eventKey    [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U8 SATScrKeyHandler(KEYBRD_MESSAGE *eventKey)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USAT__
    if ((gSATContext.lastSATCmd == SAT_DISPLAY_TEXT_CMD && gSATDisplayText.clearTextType == SAT_CLEAR_AFTER_DELAY)
        || (gSATContext.lastSATCmd == SAT_DISPLAY_TEXT_CMD && gSATDisplayText.duration != 0)
        || (gSATContext.lastSATCmd == SAT_DISPLAY_TEXT_CMD && gSATDisplayText.duration != 0))
    {
        return MMI_TRUE;    /* not need to restart timer in these cases */
    }
#endif /* __USAT__ */ 

    if (eventKey->nMsgType == KEY_EVENT_DOWN)
    {
        TemporaryStopSATTimerNoResponsefromUser();
        TemporaryStopSATTimerHelp();
    }
    if (eventKey->nMsgType == KEY_EVENT_UP)
    {
        RestartSATTimerNoResponsefromUser();
        RestartSATTimerHelp();
    }
    return (MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  SetIsInSATScreen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetIsInSATScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //PRINT_INFORMATION("[SAT] set in SAT screen");

    gSATContext.isInSATScreen = 1;
    mmi_frm_kbd_reg_pre_key_hdlr(SATScrKeyHandler);
}


/*****************************************************************************
 * FUNCTION
 *  ClearIsInSATScreen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ClearIsInSATScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //PRINT_INFORMATION("[SAT] clear in SAT screen");

    gSATContext.isInSATScreen = 0;
    mmi_frm_kbd_reg_pre_key_hdlr(NULL);
}


#ifdef __SATCE__
#define MMI_SAT_OPEN_CHANNEL
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
/*****************************************************************************
 * FUNCTION
 *  TerminalResponseOpenChannelEx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  destId      [IN]    L4/L4_2
 *  res         [IN]    Response type
 *  addInfo     [IN]    Additional info
 *  cmdDetail   [IN]    Cmd detail to be sent
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseOpenChannelEx(U8 destId, U8 res, U8 addInfo, U8 *cmdDetail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    mmi_sat_open_channel_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message = allocate_ilm(MOD_MMI);
    Message->oslSrcId = MOD_MMI;
    Message->oslDestId = destId;
    Message->oslMsgId = MSG_ID_MMI_SAT_OPEN_CHANNEL_REQ;
    dataPtr = (mmi_sat_open_channel_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_open_channel_req_struct));
    dataPtr->res = res;
    dataPtr->additional_info = addInfo;
    memcpy(dataPtr->cmd_detail, cmdDetail, 5 * sizeof(U8));
    Message->oslDataPtr = (oslParaType*) dataPtr;
    Message->oslPeerBuffPtr = NULL;
    Message->sap_id = INVALID_SAP;
    msg_send_ext_queue(Message);
}


/*****************************************************************************
 * FUNCTION
 *  SATOpenChannelSIM1Ind
 * DESCRIPTION
 *  Protocol Handler for OPEN CHANNEL IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4-1
 * RETURNS
 *  void
 *****************************************************************************/
void SATOpenChannelSIM1Ind(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_open_channel_ind_struct *openChannelInd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    openChannelInd = (mmi_sat_open_channel_ind_struct*) msgPtr;

    if (gSATContext.CMDfromSIM == SAT_CMD_SIM2)
    {
        TerminalResponseOpenChannelEx(MOD_L4C, SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, 0, openChannelInd->cmd_detail);
    }
    else
    {
        gSATContext.CMDfromSIM = SAT_CMD_SIM1;
        SATOpenChannelInd(msgPtr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  SATOpenChannelSIM2Ind
 * DESCRIPTION
 *  Protocol Handler for OPEN CHANNEL IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4-2
 * RETURNS
 *  void
 *****************************************************************************/
void SATOpenChannelSIM2Ind(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_open_channel_ind_struct *openChannelInd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    openChannelInd = (mmi_sat_open_channel_ind_struct*) msgPtr;

    if (gSATContext.CMDfromSIM == SAT_CMD_SIM1)
    {
        TerminalResponseOpenChannelEx(MOD_L4C_2, SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, 0, openChannelInd->cmd_detail);
    }
    else
    {
        gSATContext.CMDfromSIM = SAT_CMD_SIM2;
        SATOpenChannelInd(msgPtr);
    }
}

#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */


/*****************************************************************************
 * FUNCTION
 *  SATOpenChannelInd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATOpenChannelInd(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_open_channel_ind_struct *openChannelInd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    openChannelInd = (mmi_sat_open_channel_ind_struct*) msgPtr;

    if (isInCall())
    {
        TerminalResponseOpenChannel(
            SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD,
            SAT_ME_CURRENTLY_BUSY_ON_CALL,
            openChannelInd->cmd_detail);
        return;
    }

    FreeOpenChannel();

    gSATContext.lastSATCmd = SAT_OPEN_CHANNEL_CMD;
    gSATContext.guiBufferPointer = NULL;
    satOpenChannel.Stage1Res = 0;

    memcpy(satOpenChannel.cmdDetail, openChannelInd->cmd_detail, 5 * sizeof(U8));

    satOpenChannel.dcsOfAlphaId = openChannelInd->dcs_of_alpha_id;
    satOpenChannel.noAlphaId = openChannelInd->no_alpha_id;

    satOpenChannel.isAlphaIdPresent = openChannelInd->is_alpha_id_present;
    if (satOpenChannel.isAlphaIdPresent)
    {
        if (satOpenChannel.noAlphaId)
        {
            satOpenChannel.alphaID = CovertStringForPlatform(
                                        openChannelInd->alpha_id,
                                        satOpenChannel.noAlphaId,
                                        satOpenChannel.dcsOfAlphaId,
                                        &satOpenChannel.noAlphaId);
            satOpenChannel.informUser = 1;
        }
        else
        {
            satOpenChannel.informUser = 0;
        }
    }
    else
    {
        satOpenChannel.noAlphaId = mmi_ucs2strlen((PS8) (PU8) GetString(SAT_OPEN_CHANNEL_CONF_STRING_ID)) * ENCODING_LENGTH;
        satOpenChannel.alphaID = (PU8) OslMalloc(satOpenChannel.noAlphaId + ENCODING_LENGTH);
        memcpy(
            satOpenChannel.alphaID,
            (PU8) GetString(SAT_OPEN_CHANNEL_CONF_STRING_ID),
            satOpenChannel.noAlphaId + ENCODING_LENGTH);
        satOpenChannel.informUser = 1;
    }

    satOpenChannel.isIconAvailable = openChannelInd->is_icon_available;
    if (satOpenChannel.isIconAvailable)
    {
        satOpenChannel.iconInfo.iconId = openChannelInd->icon_info.icon_id;
        satOpenChannel.iconInfo.iconAttr = openChannelInd->icon_info.icon_attr;
    }

    if (satOpenChannel.isIconAvailable && satOpenChannel.iconInfo.iconAttr == SAT_ICON_SELF_EX)
    {
        if (satOpenChannel.alphaID)
        {
            OslMfree(satOpenChannel.alphaID);
            satOpenChannel.alphaID = NULL;
        }
    }

    if (satOpenChannel.informUser)
    {
        SATStopWaitTimer();
        DeleteScreenIfPresent(SCR_ID_SAT_HISTORY);
        if (GetExitScrnID() == SCR_ID_SAT_HISTORY)
        {
            ClearExitHandler();
        }
        GoToOpenChannelConformationScreen();
    }
    else
    {
        SATOpenChannelReq();
    }
}


/*****************************************************************************
 * FUNCTION
 *  GoToOpenChannelConformationScreen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoToOpenChannelConformationScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *iconData = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (satOpenChannel.isIconAvailable)
    {
        SATAddIconIDToList(satOpenChannel.iconInfo.iconId);
    }

    if (satOpenChannel.isIconAvailable)
    {
        if (!SATCheckAllIconGot())
        {
            SATGetIconCompleteCallBack = GoToOpenChannelConformationScreen;
            SATGetIconDataToList();
            return;
        }
    }

    iconData = SATGetIconFromList(satOpenChannel.iconInfo.iconId);
    gSATContext.exitCondition = &satOpenChannel.Stage1Res;
    EntryNewScreen(SAT_OPEN_CHANNEL_CONF_SCREENID, SATGenericExitHandler, NULL, NULL);

    SetIsInSATScreen();
    gSATContext.historyFuncPtr = GoToOpenChannelConformationScreen;
    ClearHighlightHandler();
    ShowCategory151Screen(
        0,
        0,
        STR_GLOBAL_YES,
        0,
        STR_GLOBAL_NO,
        0,
        satOpenChannel.alphaID,
        iconData,
        gSATContext.guiBufferPointer);

    SetKeyHandler(SATOpenChannelTerminalResponseExpire, KEY_END, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(SATOpenChannelReq, KEY_EVENT_UP);
    SetKeyHandler(SATOpenChannelReq, KEY_SEND, KEY_EVENT_UP);
    SetRightSoftkeyFunction(SATOpenChannelTerminalResponseUnable, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  SATOpenChannelTerminalResponseExpire
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SATOpenChannelTerminalResponseExpire(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TerminalResponseOpenChannel(SAT_PROACTIVE_CMD_TERMINATED_BY_USER, 0, satOpenChannel.cmdDetail);
    ExitSATToIdle();
}


/*****************************************************************************
 * FUNCTION
 *  SATOpenChannelTerminalResponseUnable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SATOpenChannelTerminalResponseUnable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TerminalResponseOpenChannel(SAT_USER_DID_NOT_ACCEPT_THE_PROACTIVE_CMD, 0, satOpenChannel.cmdDetail);
    SATPleaseWaitScreen(SAT_WAIT_STRING_ID, SAT_WAIT_IMAGE_ID);
}


/*****************************************************************************
 * FUNCTION
 *  TerminalResponseOpenChannel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  res         [IN]    Response type
 *  addInfo     [IN]    Additional info
 *  cmdDetail   [IN]    Cmd detail to be sent
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseOpenChannel(U8 res, U8 addInfo, U8 *cmdDetail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    mmi_sat_open_channel_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    satOpenChannel.Stage1Res = 1;
    Message = ALLOCATE_ITM(MOD_MMI);
    Message->oslSrcId = MOD_MMI;
    Message->oslMsgId = MSG_ID_MMI_SAT_OPEN_CHANNEL_REQ;
    dataPtr = (mmi_sat_open_channel_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_open_channel_req_struct));

    if (res == SAT_CMD_PERFORMED_SUCCESSFULLY && satOpenChannel.isIconAvailable == 1 &&
        gSATContext.isCMDIconSupported == MMI_FALSE)
    {
        dataPtr->res = SAT_CMD_PERFORMED_BUT_ICON_COULD_NOT_DSPL;
    }
    else
    {
        dataPtr->res = res;
    }
    dataPtr->additional_info = addInfo;

    memcpy(dataPtr->cmd_detail, cmdDetail, 5 * sizeof(U8));
    Message->oslDataPtr = (oslParaType*) dataPtr;
    Message->oslPeerBuffPtr = NULL;
    SEND_MSG(Message);
    gSATContext.lastSATCmd = SAT_NONE_CMD;
}


/*****************************************************************************
 * FUNCTION
 *  SATOpenChannelReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SATOpenChannelReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    satOpenChannel.Stage2Res = 0;
    TerminalResponseOpenChannel(SAT_CMD_PERFORMED_SUCCESSFULLY, 0, satOpenChannel.cmdDetail);
    if (satOpenChannel.informUser)
    {
        SATStopWaitTimer();
        DeleteScreenIfPresent(SCR_ID_SAT_HISTORY);
        if (GetExitScrnID() == SCR_ID_SAT_HISTORY)
        {
            ClearExitHandler();
        }
        DisplayOpenChannelWindow();
    }
}


/*****************************************************************************
 * FUNCTION
 *  DisplayOpenChannelWindow
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DisplayOpenChannelWindow(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gSATContext.exitCondition = &satOpenChannel.Stage2Res;
    EntryNewScreen(SAT_OPEN_CHANNEL_SCREENID, SATGenericExitHandler, NULL, NULL);

    gSATContext.waitTimeExpired = 0;

    SetIsInSATScreen();
    gSATContext.historyFuncPtr = DisplayOpenChannelWindow;
    ClearHighlightHandler();
    ShowCategory151Screen(
        0,
        0,
        0,
        0,
        0,
        0,
        (PU8) GetString(SAT_OPEN_CHANNEL_STRING_ID),
        0,
        gSATContext.guiBufferPointer);

    SetKeyHandler(0, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  SATOpenChannelRes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATOpenChannelRes(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_open_channel_rsp_struct *openChannelRes;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    openChannelRes = (mmi_sat_open_channel_rsp_struct*) msgPtr;
    satOpenChannel.Stage2Res = 1;

    FreeOpenChannel();
}


/*****************************************************************************
 * FUNCTION
 *  FreeOpenChannel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FreeOpenChannel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SATClearAllIcons();
    if (satOpenChannel.alphaID)
    {
        OslMfree(satOpenChannel.alphaID);
        satOpenChannel.alphaID = NULL;
    }
}


#define MMI_SAT_CLOSE_CHANNEL
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
/*****************************************************************************
 * FUNCTION
 *  TerminalResponseCloseChannelEx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  destId      [IN]    L4/L4_2
 *  res         [IN]    Response type
 *  cmdDetail   [IN]    Cmd detail to be sent
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseCloseChannelEx(U8 destId, U8 res, U8 *cmdDetail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    mmi_sat_close_channel_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message = allocate_ilm(MOD_MMI);
    Message->oslSrcId = MOD_MMI;
    Message->oslDestId = destId;
    Message->oslMsgId = MSG_ID_MMI_SAT_CLOSE_CHANNEL_REQ;
    dataPtr = (mmi_sat_close_channel_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_close_channel_req_struct));
    dataPtr->res = res;
    memcpy(dataPtr->cmd_detail, cmdDetail, 5 * sizeof(U8));
    Message->oslDataPtr = (oslParaType*) dataPtr;
    Message->oslPeerBuffPtr = NULL;
    Message->sap_id = INVALID_SAP;
    msg_send_ext_queue(Message);
}


/*****************************************************************************
 * FUNCTION
 *  SATCloseChannelSIM1Ind
 * DESCRIPTION
 *  Protocol Handler for CLOSE CHANNEL IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4-1
 * RETURNS
 *  void
 *****************************************************************************/
void SATCloseChannelSIM1Ind(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_close_channel_ind_struct *closeChannelInd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    closeChannelInd = (mmi_sat_close_channel_ind_struct*) msgPtr;

    if (gSATContext.CMDfromSIM == SAT_CMD_SIM2)
    {
        TerminalResponseCloseChannelEx(MOD_L4C, SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, closeChannelInd->cmd_detail);
    }
    else
    {
        gSATContext.CMDfromSIM = SAT_CMD_SIM1;
        SATCloseChannelInd(msgPtr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  SATCloseChannelSIM2Ind
 * DESCRIPTION
 *  Protocol Handler for CLOSE CHANNEL IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4-2
 * RETURNS
 *  void
 *****************************************************************************/
void SATCloseChannelSIM2Ind(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_close_channel_ind_struct *closeChannelInd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    closeChannelInd = (mmi_sat_close_channel_ind_struct*) msgPtr;

    if (gSATContext.CMDfromSIM == SAT_CMD_SIM1)
    {
        TerminalResponseCloseChannelEx(MOD_L4C_2, SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, closeChannelInd->cmd_detail);
    }
    else
    {
        gSATContext.CMDfromSIM = SAT_CMD_SIM2;
        SATCloseChannelInd(msgPtr);
    }
}

#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */


/*****************************************************************************
 * FUNCTION
 *  SATCloseChannelInd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATCloseChannelInd(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_close_channel_ind_struct *closeChannelInd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    closeChannelInd = (mmi_sat_close_channel_ind_struct*) msgPtr;

    FreeCloseChannel();

    gSATContext.lastSATCmd = SAT_CLOSE_CHANNEL_CMD;
    gSATContext.guiBufferPointer = NULL;
    satCloseChannel.StageRes = 0;

    memcpy(satCloseChannel.cmdDetail, (void*)closeChannelInd->cmd_detail, 5 * sizeof(U8));

    satCloseChannel.dcsOfAlphaId = closeChannelInd->dcs_of_alpha_id;
    satCloseChannel.noAlphaId = closeChannelInd->no_alpha_id;

    satCloseChannel.isAlphaIdPresent = closeChannelInd->is_alpha_id_present;
    if (satCloseChannel.isAlphaIdPresent)
    {
        if (satCloseChannel.noAlphaId)
        {
            satCloseChannel.alphaID = CovertStringForPlatform(
                                        closeChannelInd->alpha_id,
                                        satCloseChannel.noAlphaId,
                                        satCloseChannel.dcsOfAlphaId,
                                        &satCloseChannel.noAlphaId);
            satCloseChannel.informUser = 1;
        }
        else
        {
            satCloseChannel.informUser = 0;
        }
    }
    else
    {
        satCloseChannel.informUser = 0;
    }

    satCloseChannel.isIconAvailable = closeChannelInd->is_icon_available;
    if (satCloseChannel.isIconAvailable)
    {
        satCloseChannel.iconInfo.iconId = closeChannelInd->icon_info.icon_id;
        satCloseChannel.iconInfo.iconAttr = closeChannelInd->icon_info.icon_attr;
    }

    if (satCloseChannel.isIconAvailable && satCloseChannel.iconInfo.iconAttr == SAT_ICON_SELF_EX)
    {
        if (satCloseChannel.alphaID)
        {
            OslMfree(satCloseChannel.alphaID);
            satCloseChannel.alphaID = NULL;
        }
    }

    if (satCloseChannel.informUser)
    {
        SATStopWaitTimer();
        DeleteScreenIfPresent(SCR_ID_SAT_HISTORY);
        if (GetExitScrnID() == SCR_ID_SAT_HISTORY)
        {
            ClearExitHandler();
        }
        DisplayCloseChannelWindow();
    }
    else
    {
        if (satCloseChannel.alphaID)
        {
            OslMfree(satCloseChannel.alphaID);
            satCloseChannel.alphaID = NULL;
        }
    }
}


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
#endif


/*****************************************************************************
 * FUNCTION
 *  DisplayCloseChannelWindow
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DisplayCloseChannelWindow(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *iconData = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (satCloseChannel.isIconAvailable)
    {
        SATAddIconIDToList(satCloseChannel.iconInfo.iconId);
    }

    if (satCloseChannel.isIconAvailable)
    {
        if (!SATCheckAllIconGot())
        {
            SATGetIconCompleteCallBack = DisplayCloseChannelWindow;
            SATGetIconDataToList();
            return;
        }
    }

    gSATContext.waitTimeExpired = 0;

    iconData = SATGetIconFromList(satCloseChannel.iconInfo.iconId);
    gSATContext.exitCondition = &satCloseChannel.StageRes;
    EntryNewScreen(SAT_CLOSE_CHANNEL_SCREENID, SATGenericExitHandler, NULL, NULL);

    SetIsInSATScreen();
    gSATContext.historyFuncPtr = DisplayCloseChannelWindow;
    ClearHighlightHandler();
    ShowCategory151Screen(
        0,
        0,
        0,
        0,
        0,
        0,
        satCloseChannel.alphaID,
        iconData,
        gSATContext.guiBufferPointer);

    SetKeyHandler(SATCloseChannelTerminalResponseExpire, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  SATCloseChannelTerminalResponseExpire
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SATCloseChannelTerminalResponseExpire(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TerminalResponseCloseChannel(SAT_PROACTIVE_CMD_TERMINATED_BY_USER, satCloseChannel.cmdDetail);
    ExitSATToIdle();
}


/*****************************************************************************
 * FUNCTION
 *  TerminalResponseCloseChannel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  res         [IN]    Response type
 *  cmdDetail   [IN]    Cmd detail to be sent
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseCloseChannel(U8 res, U8 *cmdDetail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    mmi_sat_close_channel_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    satCloseChannel.StageRes = 1;
    Message = ALLOCATE_ITM(MOD_MMI);
    Message->oslSrcId = MOD_MMI;
    Message->oslMsgId = MSG_ID_MMI_SAT_CLOSE_CHANNEL_REQ;
    dataPtr = (mmi_sat_close_channel_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_close_channel_req_struct));

    if (res == SAT_CMD_PERFORMED_SUCCESSFULLY && satCloseChannel.isIconAvailable == 1 &&
        gSATContext.isCMDIconSupported == MMI_FALSE)
    {
        dataPtr->res = SAT_CMD_PERFORMED_BUT_ICON_COULD_NOT_DSPL;
    }
    else
    {
        dataPtr->res = res;
    }

    memcpy(dataPtr->cmd_detail, cmdDetail, 5 * sizeof(U8));
    Message->oslDataPtr = (oslParaType*) dataPtr;
    Message->oslPeerBuffPtr = NULL;
    SEND_MSG(Message);
    gSATContext.lastSATCmd = SAT_NONE_CMD;
}


/*****************************************************************************
 * FUNCTION
 *  SATCloseChannelRes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATCloseChannelRes(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FreeCloseChannel();
}


/*****************************************************************************
 * FUNCTION
 *  FreeCloseChannel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FreeCloseChannel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SATClearAllIcons();
    if (satCloseChannel.alphaID)
    {
        OslMfree(satCloseChannel.alphaID);
        satCloseChannel.alphaID = NULL;
    }
}


#define MMI_SAT_SEND_DATA
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
/*****************************************************************************
 * FUNCTION
 *  TerminalResponseSendDataEx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  destId      [IN]    L4/L4_2
 *  res         [IN]    Response type
 *  cmdDetail   [IN]    Cmd detail to be sent
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseSendDataEx(U8 destId, U8 res, U8 *cmdDetail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    mmi_sat_send_data_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message = allocate_ilm(MOD_MMI);
    Message->oslSrcId = MOD_MMI;
    Message->oslDestId = destId;
    Message->oslMsgId = MSG_ID_MMI_SAT_SEND_DATA_REQ;
    dataPtr = (mmi_sat_send_data_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_send_data_req_struct));
    dataPtr->res = res;
    memcpy(dataPtr->cmd_detail, cmdDetail, 5 * sizeof(U8));
    Message->oslDataPtr = (oslParaType*) dataPtr;
    Message->oslPeerBuffPtr = NULL;
    Message->sap_id = INVALID_SAP;
    msg_send_ext_queue(Message);
}


/*****************************************************************************
 * FUNCTION
 *  SATSendDataSIM1Ind
 * DESCRIPTION
 *  Protocol Handler for SEND DATA IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4-1
 * RETURNS
 *  void
 *****************************************************************************/
void SATSendDataSIM1Ind(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_send_data_ind_struct *sendDataInd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sendDataInd = (mmi_sat_send_data_ind_struct*) msgPtr;

    if (gSATContext.CMDfromSIM == SAT_CMD_SIM2)
    {
        TerminalResponseSendDataEx(MOD_L4C, SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, sendDataInd->cmd_detail);
    }
    else
    {
        gSATContext.CMDfromSIM = SAT_CMD_SIM1;
        SATSendDataInd(msgPtr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  SATSendDataSIM2Ind
 * DESCRIPTION
 *  Protocol Handler for SEND DATA IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4-2
 * RETURNS
 *  void
 *****************************************************************************/
void SATSendDataSIM2Ind(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_send_data_ind_struct *sendDataInd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sendDataInd = (mmi_sat_send_data_ind_struct*) msgPtr;

    if (gSATContext.CMDfromSIM == SAT_CMD_SIM1)
    {
        TerminalResponseSendDataEx(MOD_L4C_2, SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, sendDataInd->cmd_detail);
    }
    else
    {
        gSATContext.CMDfromSIM = SAT_CMD_SIM2;
        SATSendDataInd(msgPtr);
    }
}

#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */


/*****************************************************************************
 * FUNCTION
 *  SATSendDataInd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATSendDataInd(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_send_data_ind_struct *sendDataInd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sendDataInd = (mmi_sat_send_data_ind_struct*) msgPtr;

    FreeSendData();

    gSATContext.lastSATCmd = SAT_SEND_DATA_CMD;
    gSATContext.guiBufferPointer = NULL;
    satSendData.StageRes = 0;

    memcpy(satSendData.cmdDetail, sendDataInd->cmd_detail, 5 * sizeof(U8));

    satSendData.dcsOfAlphaId = sendDataInd->dcs_of_alpha_id;
    satSendData.noAlphaId = sendDataInd->no_alpha_id;

    satSendData.isAlphaIdPresent = sendDataInd->is_alpha_id_present;
    if (satSendData.isAlphaIdPresent)
    {
        if (satSendData.noAlphaId)
        {
            satSendData.alphaID = CovertStringForPlatform(
                                    sendDataInd->alpha_id,
                                    satSendData.noAlphaId,
                                    satSendData.dcsOfAlphaId,
                                    &satSendData.noAlphaId);
            satSendData.informUser = 1;
        }
        else
        {
            satSendData.informUser = 0;
        }
    }
    else
    {
        satSendData.noAlphaId = mmi_ucs2strlen((PS8) (PU8) GetString(SAT_SEND_DATA_CONF_STRING_ID)) * ENCODING_LENGTH;
        satSendData.alphaID = (PU8) OslMalloc(satSendData.noAlphaId + ENCODING_LENGTH);
        memcpy(
            satSendData.alphaID,
            (PU8) GetString(SAT_SEND_DATA_CONF_STRING_ID),
            satSendData.noAlphaId + ENCODING_LENGTH);
        satSendData.informUser = 1;
    }

    satSendData.isIconAvailable = sendDataInd->is_icon_available;
    if (satSendData.isIconAvailable)
    {
        satSendData.iconInfo.iconId = sendDataInd->icon_info.icon_id;
        satSendData.iconInfo.iconAttr = sendDataInd->icon_info.icon_attr;
    }

    if (satSendData.isIconAvailable && satSendData.iconInfo.iconAttr == SAT_ICON_SELF_EX)
    {
        if (satSendData.alphaID)
        {
            OslMfree(satSendData.alphaID);
            satSendData.alphaID = NULL;
        }
    }

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
#endif

    SATSendDataReq();
}


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
#endif


/*****************************************************************************
 * FUNCTION
 *  SATSendDataTerminalResponseExpire
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SATSendDataTerminalResponseExpire(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TerminalResponseSendData(SAT_PROACTIVE_CMD_TERMINATED_BY_USER, satSendData.cmdDetail);
    ExitSATToIdle();
}


/*****************************************************************************
 * FUNCTION
 *  SATSendDataTerminalResponseUnable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SATSendDataTerminalResponseUnable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TerminalResponseSendData(SAT_USER_DID_NOT_ACCEPT_THE_PROACTIVE_CMD, satSendData.cmdDetail);
    SATPleaseWaitScreen(SAT_WAIT_STRING_ID, SAT_WAIT_IMAGE_ID);
}


/*****************************************************************************
 * FUNCTION
 *  TerminalResponseSendData
 * DESCRIPTION
 *  
 * PARAMETERS
 *  res         [IN]    Response type
 *  cmdDetail   [IN]    Cmd detail to be sent
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseSendData(U8 res, U8 *cmdDetail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    mmi_sat_send_data_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    satSendData.StageRes = 1;
    Message = ALLOCATE_ITM(MOD_MMI);
    Message->oslSrcId = MOD_MMI;
    Message->oslMsgId = MSG_ID_MMI_SAT_SEND_DATA_REQ;
    dataPtr = (mmi_sat_send_data_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_send_data_req_struct));

    if (res == SAT_CMD_PERFORMED_SUCCESSFULLY && satSendData.isIconAvailable == 1 &&
        gSATContext.isCMDIconSupported == MMI_FALSE)
    {
        dataPtr->res = SAT_CMD_PERFORMED_BUT_ICON_COULD_NOT_DSPL;
    }
    else
    {
        dataPtr->res = res;
    }

    memcpy(dataPtr->cmd_detail, cmdDetail, 5 * sizeof(U8));
    Message->oslDataPtr = (oslParaType*) dataPtr;
    Message->oslPeerBuffPtr = NULL;
    SEND_MSG(Message);
    gSATContext.lastSATCmd = SAT_NONE_CMD;
}


/*****************************************************************************
 * FUNCTION
 *  SATSendDataReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SATSendDataReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (satSendData.informUser)
    {
        SATStopWaitTimer();
        DeleteScreenIfPresent(SCR_ID_SAT_HISTORY);
        if (GetExitScrnID() == SCR_ID_SAT_HISTORY)
        {
            ClearExitHandler();
        }
        DisplaySendDataWindow();
    }
    else
    {
        if (satSendData.alphaID)
        {
            OslMfree(satSendData.alphaID);
            satSendData.alphaID = NULL;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  DisplaySendDataWindow
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DisplaySendDataWindow(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *iconData = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (satSendData.isIconAvailable)
    {
        SATAddIconIDToList(satSendData.iconInfo.iconId);
    }

    if (satSendData.isIconAvailable)
    {
        if (!SATCheckAllIconGot())
        {
            SATGetIconCompleteCallBack = DisplaySendDataWindow;
            SATGetIconDataToList();
            return;
        }
    }

    iconData = SATGetIconFromList(satSendData.iconInfo.iconId);
    gSATContext.exitCondition = &satSendData.StageRes;
    EntryNewScreen(SAT_SEND_DATA_SCREENID, SATGenericExitHandler, NULL, NULL);

    gSATContext.waitTimeExpired = 0;

    SetIsInSATScreen();
    gSATContext.historyFuncPtr = DisplaySendDataWindow;
    ClearHighlightHandler();
    ShowCategory151Screen(
        0,
        0,
        0,
        0,
        0,
        0,
        satSendData.alphaID,
        iconData,
        gSATContext.guiBufferPointer);

    SetKeyHandler(SATSendDataTerminalResponseExpire, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  SATSendDataRes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATSendDataRes(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FreeSendData();
}


/*****************************************************************************
 * FUNCTION
 *  FreeSendData
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FreeSendData(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SATClearAllIcons();
    if (satSendData.alphaID)
    {
        OslMfree(satSendData.alphaID);
        satSendData.alphaID = NULL;
    }
}


#define MMI_SAT_RECV_DATA
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
/*****************************************************************************
 * FUNCTION
 *  TerminalResponseRecvDataEx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  destId      [IN]    L4/L4_2
 *  res         [IN]    Response type
 *  cmdDetail   [IN]    Cmd detail to be sent
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseRecvDataEx(U8 destId, U8 res, U8 *cmdDetail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    mmi_sat_recv_data_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message = allocate_ilm(MOD_MMI);
    Message->oslSrcId = MOD_MMI;
    Message->oslDestId = destId;
    Message->oslMsgId = MSG_ID_MMI_SAT_RECV_DATA_REQ;
    dataPtr = (mmi_sat_recv_data_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_recv_data_req_struct));
    dataPtr->res = res;
    memcpy(dataPtr->cmd_detail, cmdDetail, 5 * sizeof(U8));
    Message->oslDataPtr = (oslParaType*) dataPtr;
    Message->oslPeerBuffPtr = NULL;
    Message->sap_id = INVALID_SAP;
    msg_send_ext_queue(Message);
}


/*****************************************************************************
 * FUNCTION
 *  SATRecvDataSIM1Ind
 * DESCRIPTION
 *  Protocol Handler for RECV DATA IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4-1
 * RETURNS
 *  void
 *****************************************************************************/
void SATRecvDataSIM1Ind(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_recv_data_ind_struct *recvDataInd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    recvDataInd = (mmi_sat_recv_data_ind_struct*) msgPtr;

    if (gSATContext.CMDfromSIM == SAT_CMD_SIM2)
    {
        TerminalResponseRecvDataEx(MOD_L4C, SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, recvDataInd->cmd_detail);
    }
    else
    {
        gSATContext.CMDfromSIM = SAT_CMD_SIM1;
        SATRecvDataInd(msgPtr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  SATRecvDataSIM2Ind
 * DESCRIPTION
 *  Protocol Handler for RECV DATA IND
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4-2
 * RETURNS
 *  void
 *****************************************************************************/
void SATRecvDataSIM2Ind(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_recv_data_ind_struct *recvDataInd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    recvDataInd = (mmi_sat_recv_data_ind_struct*) msgPtr;

    if (gSATContext.CMDfromSIM == SAT_CMD_SIM1)
    {
        TerminalResponseRecvDataEx(MOD_L4C_2, SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, recvDataInd->cmd_detail);
    }
    else
    {
        gSATContext.CMDfromSIM = SAT_CMD_SIM2;
        SATRecvDataInd(msgPtr);
    }
}

#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */


/*****************************************************************************
 * FUNCTION
 *  SATRecvDataInd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATRecvDataInd(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_recv_data_ind_struct *recvDataInd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    recvDataInd = (mmi_sat_recv_data_ind_struct*) msgPtr;

    FreeRecvData();

    gSATContext.lastSATCmd = SAT_RECEIVE_DATA_CMD;
    gSATContext.guiBufferPointer = NULL;
    satRecvData.StageRes = 0;

    memcpy(satRecvData.cmdDetail, recvDataInd->cmd_detail, 5 * sizeof(U8));

    satRecvData.dcsOfAlphaId = recvDataInd->dcs_of_alpha_id;
    satRecvData.noAlphaId = recvDataInd->no_alpha_id;

    satRecvData.isAlphaIdPresent = recvDataInd->is_alpha_id_present;
    if (satRecvData.isAlphaIdPresent)
    {
        if (satRecvData.noAlphaId)
        {
            satRecvData.alphaID = CovertStringForPlatform(
                                    recvDataInd->alpha_id,
                                    satRecvData.noAlphaId,
                                    satRecvData.dcsOfAlphaId,
                                    &satRecvData.noAlphaId);
            satRecvData.informUser = 1;
        }
        else
        {
            satRecvData.informUser = 0;
        }
    }
    else
    {
        satRecvData.noAlphaId = mmi_ucs2strlen((PS8) (PU8) GetString(SAT_RECV_DATA_CONF_STRING_ID)) * ENCODING_LENGTH;
        satRecvData.alphaID = (PU8) OslMalloc(satRecvData.noAlphaId + ENCODING_LENGTH);
        memcpy(
            satRecvData.alphaID,
            (PU8) GetString(SAT_RECV_DATA_CONF_STRING_ID),
            satRecvData.noAlphaId + ENCODING_LENGTH);
        satRecvData.informUser = 1;
    }

    satRecvData.isIconAvailable = recvDataInd->is_icon_available;
    if (satRecvData.isIconAvailable)
    {
        satRecvData.iconInfo.iconId = recvDataInd->icon_info.icon_id;
        satRecvData.iconInfo.iconAttr = recvDataInd->icon_info.icon_attr;
    }

    if (satRecvData.isIconAvailable && satRecvData.iconInfo.iconAttr == SAT_ICON_SELF_EX)
    {
        if (satRecvData.alphaID)
        {
            OslMfree(satRecvData.alphaID);
            satRecvData.alphaID = NULL;
        }
    }

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
#endif

    SATRecvDataReq();
}


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
#endif


/*****************************************************************************
 * FUNCTION
 *  SATRecvDataTerminalResponseExpire
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SATRecvDataTerminalResponseExpire(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TerminalResponseRecvData(SAT_PROACTIVE_CMD_TERMINATED_BY_USER, satRecvData.cmdDetail);
    ExitSATToIdle();
}


/*****************************************************************************
 * FUNCTION
 *  SATRecvDataTerminalResponseUnable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SATRecvDataTerminalResponseUnable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TerminalResponseRecvData(SAT_USER_DID_NOT_ACCEPT_THE_PROACTIVE_CMD, satRecvData.cmdDetail);
    SATPleaseWaitScreen(SAT_WAIT_STRING_ID, SAT_WAIT_IMAGE_ID);
}


/*****************************************************************************
 * FUNCTION
 *  TerminalResponseRecvData
 * DESCRIPTION
 *  
 * PARAMETERS
 *  res         [IN]    Response type
 *  cmdDetail   [IN]    Cmd detail to be sent
 * RETURNS
 *  void
 *****************************************************************************/
void TerminalResponseRecvData(U8 res, U8 *cmdDetail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    mmi_sat_recv_data_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    satRecvData.StageRes = 1;
    Message = ALLOCATE_ITM(MOD_MMI);
    Message->oslSrcId = MOD_MMI;
    Message->oslMsgId = MSG_ID_MMI_SAT_RECV_DATA_REQ;
    dataPtr = (mmi_sat_recv_data_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_recv_data_req_struct));

    if (res == SAT_CMD_PERFORMED_SUCCESSFULLY && satRecvData.isIconAvailable == 1 &&
        gSATContext.isCMDIconSupported == MMI_FALSE)
    {
        dataPtr->res = SAT_CMD_PERFORMED_BUT_ICON_COULD_NOT_DSPL;
    }
    else
    {
        dataPtr->res = res;
    }

    memcpy(dataPtr->cmd_detail, cmdDetail, 5 * sizeof(U8));
    Message->oslDataPtr = (oslParaType*) dataPtr;
    Message->oslPeerBuffPtr = NULL;
    SEND_MSG(Message);
    gSATContext.lastSATCmd = SAT_NONE_CMD;
}


/*****************************************************************************
 * FUNCTION
 *  SATRecvDataReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SATRecvDataReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (satRecvData.informUser)
    {
        SATStopWaitTimer();
        DeleteScreenIfPresent(SCR_ID_SAT_HISTORY);
        if (GetExitScrnID() == SCR_ID_SAT_HISTORY)
        {
            ClearExitHandler();
        }
        DisplayRecvDataWindow();
    }
    else
    {
        if (satRecvData.alphaID)
        {
            OslMfree(satRecvData.alphaID);
            satRecvData.alphaID = NULL;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  DisplayRecvDataWindow
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DisplayRecvDataWindow(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *iconData = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (satRecvData.isIconAvailable)
    {
        SATAddIconIDToList(satRecvData.iconInfo.iconId);
    }

    if (satRecvData.isIconAvailable)
    {
        if (!SATCheckAllIconGot())
        {
            SATGetIconCompleteCallBack = DisplayRecvDataWindow;
            SATGetIconDataToList();
            return;
        }
    }

    iconData = SATGetIconFromList(satRecvData.iconInfo.iconId);
    gSATContext.exitCondition = &satRecvData.StageRes;
    EntryNewScreen(SAT_RECV_DATA_SCREENID, SATGenericExitHandler, NULL, NULL);

    gSATContext.waitTimeExpired = 0;

    SetIsInSATScreen();
    gSATContext.historyFuncPtr = DisplayRecvDataWindow;
    ClearHighlightHandler();
    ShowCategory151Screen(
        0,
        0,
        0,
        0,
        0,
        0,
        satRecvData.alphaID,
        iconData,
        gSATContext.guiBufferPointer);

    SetKeyHandler(SATRecvDataTerminalResponseExpire, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  SATRecvDataRes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATRecvDataRes(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FreeRecvData();
}


/*****************************************************************************
 * FUNCTION
 *  FreeRecvData
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FreeRecvData(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SATClearAllIcons();
    if (satRecvData.alphaID)
    {
        OslMfree(satRecvData.alphaID);
        satRecvData.alphaID = NULL;
    }
}


#define MMI_SAT_NOTIFY_MMI
/*****************************************************************************
 * FUNCTION
 *  SATNotifyMMIInd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void SATNotifyMMIInd(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sat_notify_mmi_ind_struct *mmiInfoInd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gSATContext.guiBufferPointer = NULL;
    mmiInfoInd = (mmi_sat_notify_mmi_ind_struct*) msgPtr;
}

#endif /* __SATCE__ */ 


#define MMI_SAT_ADVANCED_FUNCTION
/*****************************************************************************
 * FUNCTION
 *  mmi_sat_restart_please_wait_timer
 * DESCRIPTION
 *  Restart please wait timer
 * PARAMETERS
 *  please_wait_time    [IN]    
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_restart_please_wait_timer(U32 please_wait_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gSATContext.waitTimeExpired == 0)
    {
        StopTimer(SAT_MESSAGE_WAIT_TIMER);
        StartTimer(SAT_MESSAGE_WAIT_TIMER, please_wait_time, SATMessageWaitTimer);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_read_sim_file_with_path
 * DESCRIPTION
 *  Read SIM file with EF path
 * PARAMETERS
 *  offset      [IN]    
 *  length      [IN]    
 *  path        [IN]    
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_read_sim_file_with_path(U16 offset, U16 length, U8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    mmi_smu_read_sim_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SET_EVENT(SATSendReadSimFileRsp, PRT_MMI_SMU_READ_SIM_RSP);

    Message = ALLOCATE_ITM(MOD_MMI);
    Message->oslSrcId = MOD_MMI;
    Message->oslMsgId = PRT_MMI_SMU_READ_SIM_REQ;
    dataPtr = (mmi_smu_read_sim_req_struct*) OslConstructDataPtr(sizeof(mmi_smu_read_sim_req_struct));
    dataPtr->file_idx = FILE_NONE;
    dataPtr->para = offset;         /* icon image offset might be larger than 256 */
    dataPtr->length = length;
    memcpy(dataPtr->path, path, 6); /* read from EF path, total 6 bytes for path */
    Message->oslDataPtr = (oslParaType*) dataPtr;
    Message->oslPeerBuffPtr = NULL;
    SEND_MSG_ICON(Message);
}


#ifdef __USAT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sat_terminal_response_get_inkey_digit
 * DESCRIPTION
 *  Key handler of digit fro GET INKEY screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_terminal_response_get_inkey_digit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *Message;
    mmi_sat_get_inkey_res_req_struct *dataPtr;
    U16 Keycode, Keytype;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gSATGetInkey.sentRsp = 1;
    StopSATTimerNoResponsefromUser();
    gSATContext.noResponseFuncPtr = NULL;   /* diamond, 2005/07/25 SAT timer */

    Message = ALLOCATE_ITM(MOD_MMI);
    Message->oslSrcId = MOD_MMI;
    Message->oslMsgId = PRT_MMI_SAT_GET_INKEY_RES_REQ;
    dataPtr = (mmi_sat_get_inkey_res_req_struct*) OslConstructDataPtr(sizeof(mmi_sat_get_inkey_res_req_struct) + 1);

    /* diamond, 2005/05/24 icon */
    if (gSATGetInkey.isIconAvailable == 1 && gSATContext.isCMDIconSupported == MMI_FALSE)
    {
        dataPtr->res = SAT_CMD_PERFORMED_BUT_ICON_COULD_NOT_DSPL;
    }
    else
    {
        /* end, diamond */
        dataPtr->res = SAT_CMD_PERFORMED_SUCCESSFULLY;
    }

    memcpy(dataPtr->cmd_detail, (void*)gSATGetInkey.cmdDetail, 5 * sizeof(U8));
    dataPtr->is_yes_selected = FALSE;
    dataPtr->dcs_of_text_string = gSATGetInkey.dcsOfInputString;
    dataPtr->no_text_string = 1;

    GetkeyInfo(&Keycode, &Keytype);
    dataPtr->text_string = Keycode;
    dataPtr->duration = mmi_sat_count_get_inkey_user_rsp();

    Message->oslDataPtr = (oslParaType*) dataPtr;
    Message->oslPeerBuffPtr = NULL;
    SEND_MSG(Message);
    gSATContext.lastSATCmd = SAT_NONE_CMD;
    SATPleaseWaitScreen(SAT_WAIT_STRING_ID, SAT_WAIT_IMAGE_ID);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_count_get_inkey_user_rsp
 * DESCRIPTION
 *  Count user response time for GET INKEY proactive command
 * PARAMETERS
 *  void
 * RETURNS
 *  U32
 *****************************************************************************/
U32 mmi_sat_count_get_inkey_user_rsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME diff;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DTGetRTCTime(&gSATGetInkey.stopTime);
    GetTimeDifference(&gSATGetInkey.stopTime, &gSATGetInkey.startTime, &diff);

    /* user response should in several minutes */
    return (diff.nMin * 60 + diff.nSec);
}

#endif /* __USAT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_clear_idle_display_text
 * DESCRIPTION
 *  Clear display text if SIM refresh indication is received
 * PARAMETERS
 *  refresh_type    [IN]    
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_clear_idle_display_text(U16 refresh_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (refresh_type != TYPE_FILE_CHANGE)
    {
        if (gSATContext.idleTextPtr != NULL)
        {
            OslMfree(gSATContext.idleTextPtr);
            gSATContext.idleTextPtr = NULL;
        }

        if (gSATContext.idleIconPtr != NULL)
        {
            OslMfree(gSATContext.idleIconPtr);
            gSATContext.idleIconPtr = NULL;
        }

        if (mmi_idle_is_on_idle_screen() && mmi_bootup_is_idle_screen_reached())
        {
            idle_screen_show_network_details(); /* EntryIdleScreen(); */
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_refresh_to_update_imsi
 * DESCRIPTION
 *  Update IMSI if SIM refresh indication is received
 * PARAMETERS
 *  refresh_type    [IN]    
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_refresh_to_update_imsi(U16 refresh_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (refresh_type != TYPE_FILE_CHANGE)
    {
        RequestToTestRoamingEnabled();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_nw_detach_before_reboot_hdlr
 * DESCRIPTION
 *  Detach network handler before SAT reboot
 * PARAMETERS
 *  info        [IN]    
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_nw_detach_before_reboot_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(SAT_REFRESH_REBOOT_TIMER);
    SATRefreshRebootTimeOut();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_nw_detach_before_reboot
 * DESCRIPTION
 *  Detach network before SAT reboot
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_nw_detach_before_reboot(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    if (gSATFileChange.CMDfromSIM == SAT_CMD_SIM2)
    {
        SetSlaveProtocolEventHandler(mmi_sat_nw_detach_before_reboot_hdlr, MSG_ID_MMI_NW_PWROFF_DETACH_RSP);
    }
    else
    {
        SetProtocolEventHandler(mmi_sat_nw_detach_before_reboot_hdlr, MSG_ID_MMI_NW_PWROFF_DETACH_RSP);
    }
#else /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
    SetProtocolEventHandler(mmi_sat_nw_detach_before_reboot_hdlr, MSG_ID_MMI_NW_PWROFF_DETACH_RSP);
#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */

    Message.oslSrcId = MOD_MMI;
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    if (gSATFileChange.CMDfromSIM == SAT_CMD_SIM2)
    {
        Message.oslDestId = MOD_L4C_2;
    }
    else
    {
        Message.oslDestId = MOD_L4C;
    }
#else /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
    Message.oslDestId = MOD_L4C;
#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
    Message.oslMsgId = MSG_ID_MMI_NW_PWROFF_DETACH_REQ;
    Message.oslDataPtr = (oslParaType*) NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_remove_text_pending_characters
 * DESCRIPTION
 *  Remove pending characters for DISPLAY TEXT and GET INPUT
 * PARAMETERS
 *  text_string     [IN]        
 *  text_length     [IN/OUT]    
 *  text_dcs        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_remove_text_pending_characters(U8 *text_string, U16 *text_length, U8 text_dcs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (text_dcs == MMI_UCS2_DCS)
    {
        for (i = 0; i < *text_length; i += 2)
        {
            if (*(U16*) (text_string + i) == 0xFFFF)
            {
                *text_length = i;
                break;
            }
        }
    }
    else if (text_dcs == MMI_DEFAULT_DCS)
    {
        for (i = 0; i < *text_length; i++)
        {
            if (*(text_string + i) == 0xFF)
            {
                *text_length = i;
                break;
            }
        }
    }
    else
    {
        /* no action */
    }
}


#ifdef __MMI_SAT_DISPLAY_TEXT_WITH_KEYPAD_LOCK__
/*****************************************************************************
 * FUNCTION
 *  mmi_sat_is_pending_idle_sat_cmd
 * DESCRIPTION
 *  SAT pending command for idle screen callback
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_sat_is_pending_idle_sat_cmd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gSATContext.idleSATCmd;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_execute_idle_sat_cmd
 * DESCRIPTION
 *  SAT pending command for idle screen callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_execute_idle_sat_cmd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    (*gSATContext.historyFuncPtr) ();   
}

#endif /* __MMI_SAT_DISPLAY_TEXT_WITH_KEYPAD_LOCK__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_calculate_screen_capability
 * DESCRIPTION
 *  Export to SMU to calculate screen capability for profile download
 * PARAMETERS
 *  max_char_down       [OUT]
 *  max_char_accross    [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_calculate_screen_capability(unsigned char *max_char_down, unsigned char *max_char_accross)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type m_str[2] =  {'W', 0};
    S32 m_width, m_height, p_width, p_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_measure_string(m_str, &m_width, &m_height);

    /* refer to coordinate_set151[] */
#ifdef __MMI_MAINLCD_240X320__
	p_width = MMI_POP_UP_DIALOG_WIDTH - 12;
	p_height = MMI_POP_UP_DIALOG_HEIGHT - 12;
#else /* __MMI_MAINLCD_240X320__ */
	p_width = MMI_POP_UP_DIALOG_WIDTH - 4;
	p_height = MMI_POP_UP_DIALOG_HEIGHT - 8;
#endif /* __MMI_MAINLCD_240X320__ */

    *max_char_down = (U8) (p_height / m_height) - 1;  /* minus the border and space between two words */
    *max_char_accross = (U8) (p_width / m_width) - 3; /* minus the border and space between two words */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_get_color_lookup_table_req
 * DESCRIPTION
 *  Read SIM file with EF path
 * PARAMETERS
 *  void         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_get_color_lookup_table_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 path[6] = {0x7F, 0x10, 0x5F, 0x50, 0x4F, 0x01}; /* new read sim file interface */

    MYQUEUE *Message;
    mmi_smu_read_sim_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    path[5] += (gSATImageRecord.imageInst->instance - 0x4F01);

    SET_EVENT(mmi_sat_get_color_lookup_table_rsp, PRT_MMI_SMU_READ_SIM_RSP);

    Message = ALLOCATE_ITM(MOD_MMI);
    Message->oslSrcId = MOD_MMI;
    Message->oslMsgId = PRT_MMI_SMU_READ_SIM_REQ;
    dataPtr = (mmi_smu_read_sim_req_struct*) OslConstructDataPtr(sizeof(mmi_smu_read_sim_req_struct));
    dataPtr->file_idx = FILE_NONE;
    dataPtr->para = gSATImageRecord.locOfCLUT;
    dataPtr->length = gSATImageRecord.noOfCLUT * sizeof(SATCOLORDATA);
    memcpy(dataPtr->path, path, 6);
    Message->oslDataPtr = (oslParaType*) dataPtr;
    Message->oslPeerBuffPtr = NULL;
    SEND_MSG_ICON(Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_get_color_lookup_table_rsp
 * DESCRIPTION
 *  Protocol Handler for SEND SIM RES
 * PARAMETERS
 *  msgPtr      [IN]    Pointer to data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_get_color_lookup_table_rsp(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_read_sim_rsp_struct *satReadSimRes;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    satReadSimRes = (mmi_smu_read_sim_rsp_struct*) msgPtr;

    CLR_EVENT(PRT_MMI_SMU_READ_SIM_RSP);

    memcpy((void *) gSATImageRecord.CLUTData, satReadSimRes->data, gSATImageRecord.noOfCLUT * sizeof(SATCOLORDATA));
    SATGetIconDataCallBack();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_is_icon2_available
 * DESCRIPTION
 *  Export function to CM to check if icon2 is available
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_sat_is_icon2_available(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MMI_BOOL) gSATCallSetup.isIcon2Available;
}


#ifdef __MMI_UCM__
/*****************************************************************************
 * FUNCTION
 *  mmi_sat_call_setup_ucm_request
 * DESCRIPTION
 *  SET UP CALL command requests to dial from UCM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_call_setup_ucm_request(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    if (gSATContext.CMDfromSIM == SAT_CMD_SIM2)
    {
        result = mmi_ucm_app_make_call_with_source(MMI_UCM_FROM_SAT, MMI_UCM_VOICE_CALL_TYPE_SIM2, gSATCallSetup.number);
    }
    else
    {
        result = mmi_ucm_app_make_call_with_source(MMI_UCM_FROM_SAT, MMI_UCM_VOICE_CALL_TYPE, gSATCallSetup.number);
    }
#else /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
    result = mmi_ucm_app_make_call_with_source(MMI_UCM_FROM_SAT, MMI_UCM_VOICE_CALL_TYPE, gSATCallSetup.number);
#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */
    if (!result)
    {
        /* UCM doesn't allow to make SAT call now */
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_NOT_DONE),
            IMG_GLOBAL_WARNING,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);

        TerminalResponseCallSetup(SAT_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD, 0, gSATCallSetup.cmdDetail);
        SATPleaseWaitScreen(SAT_WAIT_STRING_ID, SAT_WAIT_IMAGE_ID);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_call_setup_dial_from_ucm
 * DESCRIPTION
 *  SET UP CALL command requests to dial from UCM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_call_setup_dial_from_ucm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SATCallSetupStage1Req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_call_setup_screen_delete_callback
 * DESCRIPTION
 *  SET UP CALL screen delete callback
 * PARAMETERS
 *  p       [IN]    
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_sat_call_setup_screen_delete_callback(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SATCallTerminate();
    return 0;
}

#endif /* __MMI_UCM__ */

#endif /* __SAT__ */


/*****************************************************************************
 * FUNCTION
 *  IsSATPresent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 IsSATPresent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SAT__
#ifdef __MMI_WLAN_FEATURES__
    if (mmi_netset_get_active_preferred_mode() == P_WLAN_ONLY)
    {
        return 0;
    }
#endif /* __MMI_WLAN_FEATURES__ */

#ifdef __MMI_SIMAP_SUPPORT__
    if (mmi_bootup_get_active_bt_access_profile_mode())
    {
        return 0;
    }
#endif /* __MMI_SIMAP_SUPPORT__ */

    return (gSATContext.isSATPresent);
#else /* __SAT__ */
    return 0;
#endif /* __SAT__ */
}


#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
/*****************************************************************************
 * FUNCTION
 *  IsSAT2Present
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 IsSAT2Present(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SAT__
#ifdef __MMI_WLAN_FEATURES__
    if (mmi_netset_get_active_preferred_mode() == P_WLAN_ONLY)
    {
        return 0;
    }
#endif /* __MMI_WLAN_FEATURES__ */

#ifdef __MMI_SIMAP_SUPPORT__
    if (mmi_bootup_get_active_bt_access_profile_mode())
    {
        return 0;
    }
#endif /* __MMI_SIMAP_SUPPORT__ */

    return (gSATContext.isSATPresent_2);
#else /* __SAT__ */
    return 0;
#endif /* __SAT__ */
}

#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */

