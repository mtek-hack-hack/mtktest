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
 *  FlightMode.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is intends for phone setup application
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/


#include "MMI_include.h"

#include "ProtocolEvents.h"
#include "CommonScreens.h"
#include "SettingsGexdcl.h"
#include "settingGprots.h"
#include "SettingDefs.h"
#include "MainMenuDef.h"        /* MAIN_MENU_TITLE_SETTINGS_ICON */
#include "settingprot.h"        /* PhoneSetup Prototype */
#include "SettingProfile.h"     /* WARNING_TONE */
#include "MessagesExDcl.h"      /* GetChildMenuIDIndexByParentMenuID()  */
#include "PhoneSetup.h"
#include "PhoneSetupGprots.h"
#include "SimDetectionDef.h"    /* for g_pwr_context */
#include "SimDetectionGprot.h"
#include "wgui_status_icons.h"
#include "FlightModeGProt.h"
#include "CallSetUp.h"  /* diamond, 2005/09/28 restore signal icon with line switch */
#ifdef __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__
#endif 

#ifdef __FLIGHT_MODE_SUPPORT__
#include "SimDetectionGexdcl.h"
#include "NetworkSetupGProt.h"
#include "IdleAppProt.h"        /* diamond, 2005/09/21 lock keypad by pressing RSK and # in flight mode */
#ifdef __MMI_BT_SUPPORT__
#include "BTMMIScrGprots.h"
#endif 
#ifdef __MMI_IRDA_SUPPORT__
#include "IrdaMMIGprots.h"
#include "IrdaMMIScr.h"
extern void mmi_irda_exec_close_menu(void);
#endif /* __MMI_IRDA_SUPPORT__ */ 
#include "MessagesMiscell.h"
#include "SMSApi.h"
#include "SMSStruct.h"
#include "Wapadp.h"
#ifdef __MMI_BT_PROFILE__
#include "ProfileGprots.h"
#endif 
#ifdef __MMI_ENGINEER_MODE__
#include "EngineerModeDef.h"
#endif
#ifdef __MMI_WLAN_FEATURES__
#include "DataAccountGProt.h"
#endif

#include "NetworkSetupDefs.h"

#ifdef __SYNCML_SUPPORT__
#include "SyncMLGProt.h"
#endif
#endif /* __FLIGHT_MODE_SUPPORT__ */ 

#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_AD_resdef.h"
#endif/* __MMI_DUAL_SIM_MASTER__ */
/* diamond, 2005/07/05 Flight mode */

/*
 * External Variable
 */
extern PHNSET_CNTX g_phnset_cntx;
extern U8 gSignalStrengthLevel;


/*
 * Local Variable
 */
#ifdef __FLIGHT_MODE_SUPPORT__

typedef struct _phnset_f_mode_req
{
    FuncPtr phnset_flight_mode_req;
    U8 state;
} PHNSETFMODEREQ;

static PHNSETFMODEREQ mmi_phnset_f_mode_req[] = 
{
    {PhnsetFlightModeSelectionReq, 1},
#ifdef __MMI_WLAN_FEATURES__
    {mmi_flight_mode_switch_wlan, 1},
#endif
#ifdef __MMI_BT_SUPPORT__
    {mmi_flight_mode_switch_bluetooth, 1},
#endif
#ifdef __MMI_IRDA_SUPPORT__
    {mmi_flight_mode_switch_irda, 1},
#endif
    {NULL, 0} /* dummy one, please add callbacks before this entity */
};

static U8 gLeaveFlightModeWithFullService = 0;

#endif /* #ifdef __FLIGHT_MODE_SUPPORT__ */


static U32 g_status_icon_display_invisible[MAX_STATUS_ICONS];
static U8 gIsStatusIconHidenCnt = 0; /* prevent from entering SAP mode and then enter WLAN mode */


/*****************************************************************************
 * FUNCTION
 *  PhnsetFlightModeQueryBackground
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetFlightModeQueryBackground(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* diamond, 2006/01/01 Force to draw the background */
    EntryNewScreen(SCR_FLIGHT_MODE_LOGO, NULL, PhnsetFlightModeQueryBackground, NULL);
    ShowCategory61Screen(NULL, IMG_BOOTUP_SCANNING_LOGO, NULL);
}


extern U32 get_status_icon_flag(S16 icon_ID);
extern void set_status_icon_flag(S16 icon_ID, U32 value);


/*****************************************************************************
 * FUNCTION
 *  PhnsetFlightModeSaveStatusIconFlags
 * DESCRIPTION
 *  Save the status icons status before enter flight mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetFlightModeSaveStatusIconFlags(pBOOL nw_mode) /* 1: switch from flight mode, 0: swtich from preferred mode */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 icon_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gIsStatusIconHidenCnt++;
    PRINT_INFORMATION("@@@@@ Save status icon by mode %d and count %d @@@@@", (U8) nw_mode, gIsStatusIconHidenCnt);
    if (gIsStatusIconHidenCnt != 1)
    {
        return;
    }

    for (icon_id = 0; icon_id < MAX_STATUS_ICONS; icon_id++)
    {
        switch (icon_id)
        {
            case STATUS_ICON_ROAMING:
            case STATUS_ICON_CALL_DIVERT_L1L2:
        #ifdef __MMI_CFU_SEPARATE_LINE__
            case STATUS_ICON_CALL_DIVERT_L1:
            case STATUS_ICON_CALL_DIVERT_L2:
        #endif
            case STATUS_ICON_INCOMING_SMS:
            case STATUS_ICON_UNREAD_VOICE_L1L2:
            case STATUS_ICON_UNREAD_VOICE_L1:
            case STATUS_ICON_UNREAD_VOICE_L2:
            case STATUS_ICON_UNREAD_FAX_L1L2:
            case STATUS_ICON_UNREAD_FAX_L1:
            case STATUS_ICON_UNREAD_FAX_L2:
            case STATUS_ICON_SUBLCD_SMS:
            case STATUS_ICON_MMS_UNREAD:
            case STATUS_ICON_MMS_BUSY:
            case STATUS_ICON_CHAT_INDICATION_ROOM1:
            case STATUS_ICON_CHAT_INDICATION_ROOM2:
        #ifndef __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__
            case STATUS_ICON_ALTERNATE_LINE_L1:
            case STATUS_ICON_ALTERNATE_LINE_L2:
        #endif
        #if !defined(OBIGO_Q05A) && defined(__MMI_UNIFIED_MESSAGE__)
            case STATUS_ICON_WAP:
        #endif
        #ifdef __MMI_DUAL_SIM_MASTER__
            case STATUS_ICON_SLAVE_CALLFORWARD:
            case STATUS_ICON_SLAVE_CALLFORWARD_L1:
            case STATUS_ICON_SLAVE_CALLFORWARD_L2:
            case STATUS_ICON_SLAVE_ROAMING:
            case STATUS_ICON_SLAVE_INCOMING_SMS:
            case STATUS_ICON_MMS_UNREAD_SIM_1:
            case STATUS_ICON_MMS_UNREAD_SIM_2:
            case STATUS_ICON_MMS_BUSY_SIM_1:
            case STATUS_ICON_MMS_BUSY_SIM_2:
            case STATUS_ICON_UNREAD_VOICE_L1_MASTER:
            case STATUS_ICON_UNREAD_VOICE_L2_MASTER:
            case STATUS_ICON_UNREAD_VOICE_L1L2_MASTER:
            case STATUS_ICON_UNREAD_FAX_L1_MASTER:
            case STATUS_ICON_UNREAD_FAX_L2_MASTER:
            case STATUS_ICON_UNREAD_FAX_L1L2_MASTER:
            case STATUS_ICON_UNREAD_NET_L1_MASTER:
            case STATUS_ICON_UNREAD_NET_L2_MASTER:
            case STATUS_ICON_UNREAD_NET_L1L2_MASTER:
            case STATUS_ICON_UNREAD_VOICE_L1_SLAVE:
            case STATUS_ICON_UNREAD_VOICE_L2_SLAVE:
            case STATUS_ICON_UNREAD_VOICE_L1L2_SLAVE:
            case STATUS_ICON_UNREAD_FAX_L1_SLAVE:
            case STATUS_ICON_UNREAD_FAX_L2_SLAVE:
            case STATUS_ICON_UNREAD_FAX_L1L2_SLAVE:
            case STATUS_ICON_UNREAD_NET_L1_SLAVE:
            case STATUS_ICON_UNREAD_NET_L2_SLAVE:
            case STATUS_ICON_UNREAD_NET_L1L2_SLAVE:
        #endif /* __MMI_DUAL_SIM_MASTER__ */
                g_status_icon_display_invisible[icon_id] = get_status_icon_flag(icon_id);
                set_status_icon_flag(icon_id, 0);
                break;

        #ifdef __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__
            case STATUS_ICON_SIGNAL_STRENGTH:
	#ifndef __MMI_DUAL_SIM_MASTER__
                ChangeStatusIconImage(icon_id, IMG_SI_SIGNAL_STRENGTH);
	#else	/* else __MMI_DUAL_SIM_MASTER__ */
		  ChangeStatusIconImage(icon_id, IMG_SI_MASTER_SIGNAL_STRENGTH);
	#endif	/* end __MMI_DUAL_SIM_MASTER__ */
                break;
        #endif /* __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__ */

            case STATUS_ICON_MISSED_CALL:
        #ifdef __MMI_DUAL_SIM_MASTER__
            case STATUS_ICON_CARD2MISSED_CALL:
        #endif
        #ifndef __MMI_SUBLCD_SHORT_STATUSICON_LIST__
            case STATUS_ICON_SUBLCD_MISSED_CALL:
        #endif
            case STATUS_ICON_UNREAD_EMAIL_L1L2:
            case STATUS_ICON_UNREAD_EMAIL_L1:
            case STATUS_ICON_UNREAD_EMAIL_L2:
            case STATUS_ICON_UNREAD_EMAIL:
        #ifdef __MMI_DUAL_SIM_MASTER__
            case STATUS_ICON_UNREAD_EMAIL_L1_MASTER:
            case STATUS_ICON_UNREAD_EMAIL_L2_MASTER:
            case STATUS_ICON_UNREAD_EMAIL_L1L2_MASTER:
            case STATUS_ICON_UNREAD_EMAIL_L1_SLAVE:
            case STATUS_ICON_UNREAD_EMAIL_L2_SLAVE:
            case STATUS_ICON_UNREAD_EMAIL_L1L2_SLAVE:
        #endif /* __MMI_DUAL_SIM_MASTER__ */
        #if defined(OBIGO_Q05A) || !defined(__MMI_UNIFIED_MESSAGE__)
            case STATUS_ICON_WAP:
        #endif
        #ifdef __MMI_POC__
            case STATUS_ICON_POC:
        #endif
        #ifdef __MMI_IMPS__
            case STATUS_ICON_IMPS_MSG:
            case STATUS_ICON_IMPS_LOGIN:
        #endif
                if (nw_mode)
                {
                   g_status_icon_display_invisible[icon_id] = get_status_icon_flag(icon_id);
                   set_status_icon_flag(icon_id, 0);
                }
                break;

            default:
                break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetFlightModeRestoreStatusIconFlags
 * DESCRIPTION
 *  Restire the status icons status before enter normal mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetFlightModeRestoreStatusIconFlags(pBOOL nw_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 icon_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gIsStatusIconHidenCnt--;
    PRINT_INFORMATION("@@@@@ Restore status icon by mode %d and count %d @@@@@", (U8) nw_mode, gIsStatusIconHidenCnt);
    if (gIsStatusIconHidenCnt != 0)
    {
        return;
    }

    for (icon_id = 0; icon_id < MAX_STATUS_ICONS; icon_id++)
    {
        switch (icon_id)
        {
            case STATUS_ICON_SIGNAL_STRENGTH:
            #ifdef __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__
                /* diamond, 2005/09/28 restore signal icon with line switch */
                if (mmi_bootup_is_sim_valid())  /* diamond, 2006/02/19 Not update line id if sim is not inserted after mode switch */
                {
                    if (g_callset_context.LineID == LINE1)
                    {
                        #ifndef __MMI_DUAL_SIM_MASTER__
                           ChangeStatusIconImage(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_SIGNAL_STRENGTH_L1);
			#else	/* __MMI_DUAL_SIM_MASTER__ */
			   ChangeStatusIconImage(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_MASTER_SIGNAL_STRENGTH_L1);
			#endif	/* __MMI_DUAL_SIM_MASTER__ */
                    }
                    else
                    {
                        #ifndef __MMI_DUAL_SIM_MASTER__
                           ChangeStatusIconImage(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_SIGNAL_STRENGTH_L2);
			#else	/* __MMI_DUAL_SIM_MASTER__ */
			   ChangeStatusIconImage(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_MASTER_SIGNAL_STRENGTH_L2);
			#endif	/* __MMI_DUAL_SIM_MASTER__ */
                    }
                }
            #endif /* __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__ */
                break;

            case STATUS_ICON_ROAMING:
            case STATUS_ICON_CALL_DIVERT_L1L2:
        #ifdef __MMI_CFU_SEPARATE_LINE__
            case STATUS_ICON_CALL_DIVERT_L1:
            case STATUS_ICON_CALL_DIVERT_L2:
        #endif
            case STATUS_ICON_INCOMING_SMS:
            case STATUS_ICON_UNREAD_VOICE_L1L2:
            case STATUS_ICON_UNREAD_VOICE_L1:
            case STATUS_ICON_UNREAD_VOICE_L2:
            case STATUS_ICON_UNREAD_FAX_L1L2:
            case STATUS_ICON_UNREAD_FAX_L1:
            case STATUS_ICON_UNREAD_FAX_L2:
            case STATUS_ICON_SUBLCD_SMS:
            case STATUS_ICON_MMS_UNREAD:
            case STATUS_ICON_MMS_BUSY:
            case STATUS_ICON_CHAT_INDICATION_ROOM1:
            case STATUS_ICON_CHAT_INDICATION_ROOM2:
        #ifndef __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__
            case STATUS_ICON_ALTERNATE_LINE_L1:
            case STATUS_ICON_ALTERNATE_LINE_L2:
        #endif
        #if !defined(OBIGO_Q05A) && defined(__MMI_UNIFIED_MESSAGE__)
            case STATUS_ICON_WAP:
        #endif
        #ifdef __MMI_DUAL_SIM_MASTER__
            case STATUS_ICON_SLAVE_CALLFORWARD:
            case STATUS_ICON_SLAVE_CALLFORWARD_L1:
            case STATUS_ICON_SLAVE_CALLFORWARD_L2:
            case STATUS_ICON_SLAVE_ROAMING:
            case STATUS_ICON_SLAVE_INCOMING_SMS:
            case STATUS_ICON_MMS_UNREAD_SIM_1:
            case STATUS_ICON_MMS_UNREAD_SIM_2:
            case STATUS_ICON_MMS_BUSY_SIM_1:
            case STATUS_ICON_MMS_BUSY_SIM_2:
            case STATUS_ICON_UNREAD_VOICE_L1_MASTER:
            case STATUS_ICON_UNREAD_VOICE_L2_MASTER:
            case STATUS_ICON_UNREAD_VOICE_L1L2_MASTER:
            case STATUS_ICON_UNREAD_FAX_L1_MASTER:
            case STATUS_ICON_UNREAD_FAX_L2_MASTER:
            case STATUS_ICON_UNREAD_FAX_L1L2_MASTER:
            case STATUS_ICON_UNREAD_NET_L1_MASTER:
            case STATUS_ICON_UNREAD_NET_L2_MASTER:
            case STATUS_ICON_UNREAD_NET_L1L2_MASTER:
            case STATUS_ICON_UNREAD_VOICE_L1_SLAVE:
            case STATUS_ICON_UNREAD_VOICE_L2_SLAVE:
            case STATUS_ICON_UNREAD_VOICE_L1L2_SLAVE:
            case STATUS_ICON_UNREAD_FAX_L1_SLAVE:
            case STATUS_ICON_UNREAD_FAX_L2_SLAVE:
            case STATUS_ICON_UNREAD_FAX_L1L2_SLAVE:
            case STATUS_ICON_UNREAD_NET_L1_SLAVE:
            case STATUS_ICON_UNREAD_NET_L2_SLAVE:
            case STATUS_ICON_UNREAD_NET_L1L2_SLAVE:
        #endif /* __MMI_DUAL_SIM_MASTER__ */
                set_status_icon_flag(icon_id, g_status_icon_display_invisible[icon_id]);
                break;

            case STATUS_ICON_MISSED_CALL:
        #ifdef __MMI_DUAL_SIM_MASTER__
            case STATUS_ICON_CARD2MISSED_CALL:
        #endif/*__MMI_DUAL_SIM_MASTER__*/
        #ifndef __MMI_SUBLCD_SHORT_STATUSICON_LIST__
            case STATUS_ICON_SUBLCD_MISSED_CALL:
        #endif
            case STATUS_ICON_UNREAD_EMAIL_L1L2:
            case STATUS_ICON_UNREAD_EMAIL_L1:
            case STATUS_ICON_UNREAD_EMAIL_L2:
            case STATUS_ICON_UNREAD_EMAIL:
        #ifdef __MMI_DUAL_SIM_MASTER__
            case STATUS_ICON_UNREAD_EMAIL_L1_MASTER:
            case STATUS_ICON_UNREAD_EMAIL_L2_MASTER:
            case STATUS_ICON_UNREAD_EMAIL_L1L2_MASTER:
            case STATUS_ICON_UNREAD_EMAIL_L1_SLAVE:
            case STATUS_ICON_UNREAD_EMAIL_L2_SLAVE:
            case STATUS_ICON_UNREAD_EMAIL_L1L2_SLAVE:
        #endif /* __MMI_DUAL_SIM_MASTER__ */
        #if defined(OBIGO_Q05A) || !defined(__MMI_UNIFIED_MESSAGE__)
            case STATUS_ICON_WAP:
        #endif
        #ifdef __MMI_POC__
            case STATUS_ICON_POC:
        #endif
        #ifdef __MMI_IMPS__
            case STATUS_ICON_IMPS_MSG:
            case STATUS_ICON_IMPS_LOGIN:
        #endif
                if (nw_mode)
                {
                   set_status_icon_flag(icon_id, g_status_icon_display_invisible[icon_id]);
                }
                break;

            default:
                break;
        }
    }
}


#ifdef __FLIGHT_MODE_SUPPORT__

extern void SetCat165TimerExpireFunc(FuncPtr);

#ifndef MMI_ON_HARDWARE_P
#define NVRAM_EF_SYS_CACHE_OCTET_SIZE 8
#endif 

static pBOOL gSetModeFromMenu = MMI_FALSE;
static pBOOL gIsFlightModeSwitching = MMI_FALSE;


/*****************************************************************************
 * FUNCTION
 *  HighlightPhnsetFlightMode
 * DESCRIPTION
 *  This function is highlight handler for Phone Setup -> Flight Mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightPhnsetFlightMode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);

    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetLeftSoftkeyFunction(EntryPhnsetFlightMode, KEY_EVENT_UP);
    SetKeyHandler(EntryPhnsetFlightMode, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HintPhnsetFlightMode
 * DESCRIPTION
 *  This function is hint handling function for Phone Setup -> Flight Mode
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HintPhnsetFlightMode(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 data[NVRAM_EF_SYS_CACHE_OCTET_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_SYS_CACHE_OCTET_LID, 2, &data, NVRAM_EF_SYS_CACHE_OCTET_SIZE, &error);
    g_phnset_cntx.curFlightMode = data[0];

    switch (g_phnset_cntx.curFlightMode)
    {
        case FLIGHTMODE_OFF:    /* 0x00 */
            mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_FLIGHT_MODE_NORMAL));
            break;

        case FLIGHTMODE_SILENT: /* 0x01 */
                mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_FLIGHT_MODE_SILENT));
            break;

        case FLIGHTMODE_QUERY:  /* 0x02 */
            mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_FLIGHT_MODE_QUERY));
            break;

        default:
            data[0] = FLIGHTMODE_OFF;
            data[1] = FLIGHTMODE_OFF;
            data[2] = 0; /* reserve for dual sim */
            g_phnset_cntx.curFlightMode = 0;
        #ifdef __MMI_WLAN_FEATURES__
            g_phnset_cntx.curFlightMode2 = 0;
        #endif
            WriteRecord(NVRAM_EF_SYS_CACHE_OCTET_LID, 2, &data, NVRAM_EF_SYS_CACHE_OCTET_SIZE, &error);
            mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_FLIGHT_MODE_NORMAL));
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  HiliteHandlerFlightMode
 * DESCRIPTION
 *  Highlight handler for mode selection
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HiliteHandlerFlightMode(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phnset_cntx.selFlightMode = (U8) index;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  EntryFlightModeProgress
 * DESCRIPTION
 *  Progressing screen for mode switch
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryFlightModeProgress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_FLIGHT_MODE_PROGRESS, NULL, EntryFlightModeProgress, NULL);
    SetKeyHandler(NULL, KEY_END, KEY_EVENT_DOWN);
    SetKeyHandler(NULL, KEY_END, KEY_EVENT_UP);
    ShowCategory66Screen(
        STR_MENU_FLIGHT_MODE,
        0,
        0,
        0,
        0,
        0,
        (PU8) GetString(STR_FLIGHT_MODE_PROGRESS),
        IMG_FLIGHT_MODE_PROGRESS,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_flight_mode_camp_on_tone_hdlr
 * DESCRIPTION
 *  Timeout handler to play camp on tone after switch to normal mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phnset_flight_mode_camp_on_tone_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_idle_is_on_idle_screen() == MMI_TRUE || g_keylock_context.IsOnKeyLockCallbackScreen == 1)
    {
        playRequestedTone(CAMP_ON_TONE);
        mmi_flight_mode_reset_camp_on_tone_event();
    }
    else
    {
        gLeaveFlightModeWithFullService = 1;
        StartTimer(FLIGHT_MODE_CAMP_ON_TONE_TIMER, 10000, mmi_flight_mode_reset_camp_on_tone_event);
    }
}

#ifdef __MMI_BT_SUPPORT__
static pBOOL btNotReady = MMI_FALSE;
static pBOOL btGotRsp = MMI_FALSE;
#endif /* __MMI_BT_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_flight_mode_selection_finish
 * DESCRIPTION
 *  Finish to perform mode switch
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phnset_flight_mode_selection_finish(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("@@@@@ Flight mode: switch done @@@@@");
    gIsFlightModeSwitching = MMI_FALSE;

#ifdef __MMI_BT_SUPPORT__
    if (!gSetModeFromMenu)
    {
        /* BT always call this callback after set flight mode */
        /* MMI doesn't have screen for set mode in power on period */
        return;
    }

    if (btGotRsp)
    {
        return;
    }

    StopTimer(FLIGHT_MODE_DEACTIVATE_BT_TIMER);
#endif /* __MMI_BT_SUPPORT__ */ 
    /* do not call this fuction for BT power on by init */
    if (GetActiveScreenId() != SCR_FLIGHT_MODE_PROGRESS)
    {
        DeleteScreenIfPresent(SCR_FLIGHT_MODE_PROGRESS);    /* progressing */
        DeleteScreenIfPresent(SCR_FLIGHT_MODE_SELECTION);   /* flight mode menu */
        DeleteScreenIfPresent(SCR9003_INITIALSETUP);        /* phone setup */
        DeleteScreenIfPresent(SCR9000_SETTINGS);            /* setting */
        DeleteScreenIfPresent(MAIN_MENU_SCREENID);          /* main menu */
        DeleteScreenIfPresent(SCR_SIM_OPTION);              /* sim option menu */
        if (mmi_bootup_is_sim_valid() && mmi_idle_is_on_idle_screen())
        {
            /* already in idle screen because mode switch is interrupted by other application */
            EntryIdleScreen();
        }
        if (g_pwr_context.CurrentServiceType == FULL_SERVICE)
        {
            /* play camp on tone */
            mmi_phnset_flight_mode_camp_on_tone_hdlr();
        }
    }
    else
    {
        DisplayPopupCallBack(
            (PU8) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            SUCCESS_TONE,
            DisplayIdleScreen);
        if (IsScreenPresent(SCR_SIM_INSERTION))
        {
            DeleteUptoScrID(SCR_SIM_INSERTION);
        }
        else if (IsScreenPresent(SCR_SIM_BLOCK))
        {
            DeleteUptoScrID(SCR_SIM_BLOCK);
        }
        else
        {
            DeleteUptoScrID(IDLE_SCREEN_ID);
        }

        if (g_pwr_context.CurrentServiceType == FULL_SERVICE)
        {
            /* play camp on tone */
            mmi_phnset_flight_mode_camp_on_tone_hdlr();
        }
    }

    gSetModeFromMenu = MMI_FALSE;
#ifdef __MMI_BT_SUPPORT__
    btGotRsp = MMI_TRUE;
#endif 
}

#ifdef __MMI_BT_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_flight_mode_bt_timeout_hdlr
 * DESCRIPTION
 *  Timeout handler for no response from BT
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phnset_flight_mode_bt_timeout_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("@@@@@ Flight mode: BT deactivation timeout @@@@@");

    /* Temporarily don't set BT not ready flag */
    /* btNotReady = MMI_TRUE; */

    mmi_phnset_switch_flight_mode();
}
#endif /* __MMI_BT_SUPPORT__ */ 



/*****************************************************************************
 * FUNCTION
 *  mmi_flight_mode_switch_bluetooth
 * DESCRIPTION
 *  Switch BT after flight mode switch
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_flight_mode_switch_bluetooth(void)
{
#ifdef __MMI_BT_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 btSimPresent;
    U8 btChipPresent;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BT_SUPPORT__
    btSimPresent = 1; /* always turn on */
#endif /* __MMI_BT_SUPPORT__ */

#ifdef __MMI_BT_SUPPORT__
    btChipPresent = !btNotReady;
#else
    btChipPresent = 1;
#endif

    if (btSimPresent && btChipPresent)
    {
        PRINT_INFORMATION("@@@@@ Flight mode: BT reset @@@@@");

        btGotRsp = MMI_FALSE;
        StartTimer(FLIGHT_MODE_DEACTIVATE_BT_TIMER, 40000, mmi_phnset_flight_mode_bt_timeout_hdlr);

        if (mmi_bootup_get_active_flight_mode() == FLIGHTMODE_OFF)
        {
            mmi_bt_reset_hw_on();
        }
        else
        {
            mmi_bt_reset_hw_off();
        }
    }
    else
    {
        mmi_phnset_switch_flight_mode();
    }
#endif /* __MMI_BT_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_flight_mode_switch_irda
 * DESCRIPTION
 *  Switch IrDA after flight mode switch
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_flight_mode_switch_irda(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_IRDA_SUPPORT__
    if (MMI_IRDASCR_CNTX(irda_state) != MMIR_SCR_IRCLOSE &&
        mmi_bootup_get_active_flight_mode() == FLIGHTMODE_SILENT)
    {
        PRINT_INFORMATION("@@@@@ Flight mode: IrDA disconnect @@@@@");
        if (mmi_irda_is_ircomm_active() == MMI_TRUE)
        {
            mmi_irda_ircomm_disconnect_request();
        }
        mmi_irda_exec_close_menu();
    }
#endif /* __MMI_IRDA_SUPPORT__ */ 

    mmi_phnset_switch_flight_mode();
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetFlightModeSelectionRsp
 * DESCRIPTION
 *  Response of mode switch
 * PARAMETERS
 *  info        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetFlightModeSelectionRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_cfun_state_rsp_struct *cfun_state_rsp;

    extern U8 lastNwStatus;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cfun_state_rsp = (mmi_nw_cfun_state_rsp_struct*) info;

    ClearProtocolEventHandler(PRT_NW_CFUN_STATE_RSP);

    if (cfun_state_rsp->result == KAL_TRUE)
    {
        g_phnset_cntx.curFlightMode = g_phnset_cntx.selFlightMode;       /* update flight mode if it is successfully changed */

        if (g_phnset_cntx.selFlightMode == FLIGHTMODE_SILENT)
        {
            g_pwr_context.PowerOnNWStatus |= MMI_NW_STATUS_FLIGHT_MODE;  /* 0x04: Flight mode */
        }
        else
        {
            g_pwr_context.PowerOnNWStatus &= ~MMI_NW_STATUS_FLIGHT_MODE; /* 0x04: Flight mode */
        }

        if ((g_pwr_context.PowerOnNWStatus & MMI_NW_STATUS_FLIGHT_MODE) == FLIGHTMODE_OFF) /* flight mode to normal mode */
        {
            /* show status icons after switch mode */
            PhnsetFlightModeRestoreStatusIconFlags(MMI_TRUE);
            UpdateStatusIcons();
        }
        else /* normal mode to flight mode */
        {
            lastNwStatus = MMI_RAC_NO_CELL; /* update last network status as no service */
            gSignalStrengthLevel = 0;   /* avoid no signal level indication sent to MMI */

        #if defined(__GSM_RAT__) && defined(__WCDMA_RAT__)
/* under construction !*/
/* under construction !*/
        #endif /* defined(__GSM_RAT__) && defined(__WCDMA_RAT__) */

            /* hide status icons before switch mode */
            PhnsetFlightModeSaveStatusIconFlags(MMI_TRUE);
            UpdateStatusIcons();
        }

        /* diamond, 2005/11/17 Force to draw signal level because signal level indication comes before flight mode switch rsp */
        ChangeStatusIconLevel(STATUS_ICON_SIGNAL_STRENGTH, gSignalStrengthLevel);
    #ifdef __MMI_SUBLCD__
        ChangeStatusIconLevel(STATUS_ICON_SUBLCD_SIGNAL_STRENGTH, gSignalStrengthLevel);
    #endif 

        /* diamond, 2006/02/22 If the camp on tone comes with next network attachment indication, it might be delayed for many seconds */
        g_pwr_context.IsCampOnTonePlayed = 1;
        g_pwr_context.InvalidSimShowed = 1;

        mmi_phnset_switch_flight_mode();
    }
    else
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_NOT_DONE),
            IMG_GLOBAL_UNFINISHED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        DeleteScreenIfPresent(SCR_FLIGHT_MODE_PROGRESS);
        gIsFlightModeSwitching = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetFlightModeSelectionReq
 * DESCRIPTION
 *  Request of mode switch
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetFlightModeSelectionReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_nw_cfun_state_req_struct *cfun_state_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phnset_cntx.selFlightMode == FLIGHTMODE_QUERY)
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) SUCCESS_TONE);
        DeleteScreenIfPresent(SCR_FLIGHT_MODE_SELECTION);   /* flight mode menu */
        /* save it to NVRAM only and not necessary to send request to L4C */
        g_phnset_cntx.curFlightMode = g_phnset_cntx.selFlightMode;
        PhnsetFlightModeSaveMode();
        DeleteScreenIfPresent(SCR_FLIGHT_MODE_PROGRESS);
        return;
    }

    if ((g_phnset_cntx.selFlightMode != FLIGHTMODE_QUERY) &&
        (g_phnset_cntx.curFlightMode == FLIGHTMODE_QUERY) &&
        (mmi_bootup_get_active_flight_mode() == g_phnset_cntx.selFlightMode))
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) SUCCESS_TONE);
        DeleteScreenIfPresent(SCR_FLIGHT_MODE_SELECTION);   /* flight mode menu */
        /* save it to NVRAM only and not necessary to send request to L4C */
        g_phnset_cntx.curFlightMode = g_phnset_cntx.selFlightMode;
        PhnsetFlightModeSaveMode();
        DeleteScreenIfPresent(SCR_FLIGHT_MODE_PROGRESS);
        return;
    }

    cfun_state_req = OslConstructDataPtr(sizeof(mmi_nw_cfun_state_req_struct));

    if (g_phnset_cntx.selFlightMode == FLIGHTMODE_OFF)  /* normal mode */
    {
        cfun_state_req->cfun_state = 1;
    }
    else    /* flight mode */
    {
        cfun_state_req->cfun_state = 4;
    }

    SetProtocolEventHandler(PhnsetFlightModeSelectionRsp, PRT_NW_CFUN_STATE_RSP);

    Message.oslMsgId = PRT_NW_CFUN_STATE_REQ;
    Message.oslDataPtr = (oslParaType*) cfun_state_req;
    Message.oslPeerBuffPtr = NULL;
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;

    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  EntryFlightModeSelectionCnf
 * DESCRIPTION
 *  Confirmation screen of mode switch
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryFlightModeSelectionCnf(void)
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
        get_string(STR_FLIGHT_MODE_CONFIRM),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_phnset_confirm_to_switch_mode, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* Play warning tone */
    playRequestedTone(WARNING_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetFlightModeSelectionOK
 * DESCRIPTION
 *  Handler for the mode selection by user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetFlightModeSelectionOK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phnset_cntx.selFlightMode == g_phnset_cntx.curFlightMode)
    {
        /* select mode is the same as current mode, so not necessary to send request to L4C */
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) SUCCESS_TONE);
        DeleteScreenIfPresent(SCR_FLIGHT_MODE_SELECTION);   /* flight mode menu */
    }
    else
    {
        EntryFlightModeSelectionCnf();
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryPhnsetFlightMode
 * DESCRIPTION
 *  This function is Entry function for Phone Setup -> Flight Mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryPhnsetFlightMode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 nNumofItem = 3;
    U8 *guiBuffer;
    U16 nStrItemList[3] = {STR_FLIGHT_MODE_NORMAL, STR_FLIGHT_MODE_SILENT, STR_FLIGHT_MODE_QUERY};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_FLIGHT_MODE_SELECTION, NULL, EntryPhnsetFlightMode, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_FLIGHT_MODE_SELECTION);
    RegisterHighlightHandler(HiliteHandlerFlightMode);
    ShowCategory11Screen(
        STR_MENU_FLIGHT_MODE,
        MAIN_MENU_TITLE_SETTINGS_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        g_phnset_cntx.curFlightMode,
        guiBuffer);

    SetLeftSoftkeyFunction(PhnsetFlightModeSelectionOK, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetFlightModeSaveMode
 * DESCRIPTION
 *  Save active mode to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetFlightModeSaveMode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data[NVRAM_EF_SYS_CACHE_OCTET_SIZE];
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("@@@@@ Flight mode: save mode @@@@@");
	ReadRecord(NVRAM_EF_SYS_CACHE_OCTET_LID, 2, &data, NVRAM_EF_SYS_CACHE_OCTET_SIZE, &error);
    data[0] = g_phnset_cntx.curFlightMode;
    data[1] = (U8) mmi_bootup_get_active_flight_mode();
#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
    switch (MTPNP_AD_Get_Startup_Mode())
    {
        case MTPNP_AD_NVRAM_CARD1:
    	      data[2] = 0;
    	      break;
        case MTPNP_AD_NVRAM_CARD2:
    	      data[2] = 1;
    	      break;
        case MTPNP_AD_NVRAM_DUALCARD:
        default:
    	      data[2] = 2;
    	      break;
    }
#else
    data[2] = 0;
#endif
    WriteRecord(NVRAM_EF_SYS_CACHE_OCTET_LID, 2, &data, NVRAM_EF_SYS_CACHE_OCTET_SIZE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  PowerOnFlightMode
 * DESCRIPTION
 *  Process of power on in flight mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PowerOnFlightMode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_nw_cfun_state_req_struct *cfun_state_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cfun_state_req = OslConstructDataPtr(sizeof(mmi_nw_cfun_state_req_struct));

#ifndef __MMI_DUAL_SIM_MASTER__
    PhnsetFlightModeSaveStatusIconFlags(MMI_TRUE);
    UpdateStatusIcons();
#endif

    cfun_state_req->cfun_state = 4;
    g_pwr_context.PowerOnNWStatus |= MMI_NW_STATUS_FLIGHT_MODE; /* 0x04: Flight mode */

#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
	if (MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_FLIGHT)
#endif
	{
            if (g_phnset_cntx.curFlightMode != FLIGHTMODE_QUERY)
	    {
                g_phnset_cntx.curFlightMode = FLIGHTMODE_SILENT;
	    }
	}

    Message.oslMsgId = PRT_NW_CFUN_STATE_REQ;
    Message.oslDataPtr = (oslParaType*) cfun_state_req;
    Message.oslPeerBuffPtr = NULL;
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;

    OslMsgSendExtQueue(&Message);

#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
    if (g_pwr_context.PowerOnMMIStatus >= MMI_POWER_ON_ANIMATION)
    {
        return;
    }
#endif /* __MMI_DUAL_SIM_SINGLE_CALL__ */

    mmi_bootup_stop_countdown_screen();
    ClearInputEventHandler(MMI_DEVICE_ALL); /* prevent user press key after mode selection in qurey screen */

    DeleteScreenIfPresent(SCR_FLIGHT_MODE_LOGO);

    if (g_pwr_context.PowerOnMode == POWER_ON_KEYPAD)   /* diamond, 2005/10/21 Do not play animation for exception power on */
    {
        PhnsetFlightModeSaveMode();
        mmi_bootup_exit_flight_mode_query();
    }
}


/*****************************************************************************
 * FUNCTION
 *  PowerOnNormalMode
 * DESCRIPTION
 *  Process of power on in normal mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PowerOnNormalMode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_nw_cfun_state_req_struct *cfun_state_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cfun_state_req = OslConstructDataPtr(sizeof(mmi_nw_cfun_state_req_struct));

    cfun_state_req->cfun_state = 1;
    g_pwr_context.PowerOnNWStatus &= ~MMI_NW_STATUS_FLIGHT_MODE;        /* 0x04 Flight mode */

    if (g_phnset_cntx.curFlightMode != FLIGHTMODE_QUERY)
    {
        g_phnset_cntx.curFlightMode = FLIGHTMODE_OFF;
    }

    Message.oslMsgId = PRT_NW_CFUN_STATE_REQ;
    Message.oslDataPtr = (oslParaType*) cfun_state_req;
    Message.oslPeerBuffPtr = NULL;
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;

    OslMsgSendExtQueue(&Message);

#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
    if (g_pwr_context.PowerOnMMIStatus >= MMI_POWER_ON_ANIMATION)
    {
        return;
    }
#endif /* __MMI_DUAL_SIM_SINGLE_CALL__ */

    mmi_bootup_stop_countdown_screen();
    ClearInputEventHandler(MMI_DEVICE_ALL); /* prevent user press key after mode selection in qurey screen */

    DeleteScreenIfPresent(SCR_FLIGHT_MODE_LOGO);

    if (g_pwr_context.PowerOnMode == POWER_ON_KEYPAD)   /* diamond, 2005/10/21 Do not play animation for exception power on */
    {
        PhnsetFlightModeSaveMode();
        mmi_bootup_exit_flight_mode_query();
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryQueryFlightModeScreen
 * DESCRIPTION
 *  Flight mode query screen before power on animation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryQueryFlightModeScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_FLIGHT_MODE_QUERY;    /* 0x02: Flight mode screen */

    guiBuffer = GetCurrGuiBuffer(SCR_FLIGHT_MODE_QUERY);

    EntryNewScreen(SCR_FLIGHT_MODE_QUERY, NULL, EntryQueryFlightModeScreen, NULL);

    ShowCategory165Screen_ext(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_MENU_FLIGHT_MODE),
        IMG_GLOBAL_QUESTION,
        10,
        guiBuffer);

    SetCat165TimerExpireFunc(PowerOnNormalMode);

    playRequestedTone(WARNING_TONE);

    /* ShowSubLCDScreen(ShowIdleAppSubLcd); */
    /* no sub-lcd exit handler because of no interrupt in this screen */
#ifdef __MMI_SUBLCD_SHOW_ANALOG_CLOCK__
    if (IsClamClose())
    {
        ShowSubLCDAnalogClockScreen();
    }
    else
    {
        ShowSubLCDLogoString();
    }
#else /* __MMI_SUBLCD_SHOW_ANALOG_CLOCK__ */ 
    ShowCategory301Screen((PU8) GetString(STR_MENU_FLIGHT_MODE), 0, NULL);
#endif /* __MMI_SUBLCD_SHOW_ANALOG_CLOCK__ */ 

    g_phnset_cntx.curFlightMode = FLIGHTMODE_QUERY;

    /* No history to go back */
    /* Always enter normal mode unless the flight mode is selected by pressing LSK (Yes) */
    SetKeyHandler(PowerOnNormalMode, KEY_END, KEY_EVENT_DOWN);

#ifdef __MMI_WLAN_FEATURES__
    SetLeftSoftkeyFunction(mmi_phnset_power_on_query_with_flight_mode, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_phnset_power_on_query_with_normal_mode, KEY_EVENT_UP);
#else
    SetLeftSoftkeyFunction(PowerOnFlightMode, KEY_EVENT_UP);
    SetRightSoftkeyFunction(PowerOnNormalMode, KEY_EVENT_UP);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetFlightModeGetLatestActionMode
 * DESCRIPTION
 *  Get latest action mode for exception power on
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 PhnsetFlightModeGetLatestActionMode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data[NVRAM_EF_SYS_CACHE_OCTET_SIZE];
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_SYS_CACHE_OCTET_LID, 2, &data, NVRAM_EF_SYS_CACHE_OCTET_SIZE, &error);
    return data[1];
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetFlightModePowerOnException
 * DESCRIPTION
 *  Process of exception power on mode switch
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetFlightModePowerOnException(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_DUAL_SIM_MASTER__)
	MTPNP_AD_Exception_Bootup();
#elif defined(__MMI_DUAL_SIM_DUAL_CALL_SLAVE__)
	MTPNP_AD_Bootup();
#else	/*__MMI_DUAL_SIM_MASTER__ || __MMI_DUAL_SIM_DUAL_CALL_SLAVE__ */
    if (PhnsetFlightModeGetLatestActionMode() == FLIGHTMODE_OFF)
    {
        PowerOnNormalMode();
    }
    else
    {
        PowerOnFlightMode();
    }
#endif	/*__MMI_DUAL_SIM_MASTER__ || __MMI_DUAL_SIM_DUAL_CALL_SLAVE__ */
}

#ifdef __MMI_ENGINEER_MODE__

static pBOOL gEnterEMWithFlightMode = MMI_FALSE;
static FuncPtr em_flight_mode_callback;

/*****************************************************************************
 * FUNCTION
 *  mmi_em_enter_flight_mode_rsp
 * DESCRIPTION
 *  Enter flight mode from engineering mode
 * PARAMETERS
 *  info
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_enter_flight_mode_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_cfun_state_rsp_struct *cfun_state_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cfun_state_rsp = (mmi_nw_cfun_state_rsp_struct*) info;

    ClearProtocolEventHandler(PRT_NW_CFUN_STATE_RSP);

    if (cfun_state_rsp->result == KAL_TRUE)
    {
        /* update flight mode if it is successfully changed */
        /* g_phnset_cntx.curFlightMode = 1; */
        g_pwr_context.PowerOnNWStatus |= MMI_NW_STATUS_FLIGHT_MODE;     /* 0x04: Flight mode */

        /* refresh status icons */
        gSignalStrengthLevel = 0;
        PhnsetFlightModeSaveStatusIconFlags(MMI_TRUE);
        UpdateStatusIcons();

        /* write current mode to nvram */
        PhnsetFlightModeSaveMode();

        /* force to draw signal level because signal level indication comes before flight mode switch rsp */
        ChangeStatusIconLevel(STATUS_ICON_SIGNAL_STRENGTH, gSignalStrengthLevel);
    #ifdef __MMI_SUBLCD__
        ChangeStatusIconLevel(STATUS_ICON_SUBLCD_SIGNAL_STRENGTH, gSignalStrengthLevel);
    #endif 

        /* enter next menu */
        (*em_flight_mode_callback)();
        DeleteScreenIfPresent(SCR_FLIGHT_MODE_PROGRESS);
    }
    else
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_NOT_DONE),
            IMG_GLOBAL_UNFINISHED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        DeleteScreenIfPresent(SCR_FLIGHT_MODE_PROGRESS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_enter_flight_mode
 * DESCRIPTION
 *  Enter flight mode from engineering mode
 * PARAMETERS
 *  callback        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_enter_flight_mode(FuncPtr callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_nw_cfun_state_req_struct *cfun_state_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gEnterEMWithFlightMode = MMI_FALSE;
    em_flight_mode_callback = callback;

    if (mmi_bootup_get_active_flight_mode() == FLIGHTMODE_SILENT)
    {
        /* already in flight mode */
        gEnterEMWithFlightMode = MMI_TRUE;
        /* directly enter next menu */
        (*em_flight_mode_callback)();
        return;
    }

    cfun_state_req = OslConstructDataPtr(sizeof(mmi_nw_cfun_state_req_struct));
    cfun_state_req->cfun_state = 4; /* flight mode */

    SetProtocolEventHandler(mmi_em_enter_flight_mode_rsp, PRT_NW_CFUN_STATE_RSP);
    EntryFlightModeProgress();  /* show searching screen */

    Message.oslMsgId = PRT_NW_CFUN_STATE_REQ;
    Message.oslDataPtr = (oslParaType*) cfun_state_req;
    Message.oslPeerBuffPtr = NULL;
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;

    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_exit_flight_mode_rsp
 * DESCRIPTION
 *  Exit flight mode from engineering mode
 * PARAMETERS
 *  info
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_exit_flight_mode_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_cfun_state_rsp_struct *cfun_state_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cfun_state_rsp = (mmi_nw_cfun_state_rsp_struct*) info;

    ClearProtocolEventHandler(PRT_NW_CFUN_STATE_RSP);

    if (cfun_state_rsp->result == KAL_TRUE)
    {
        /* update flight mode if it is successfully changed */
        /* g_phnset_cntx.curFlightMode = 0; */
        g_pwr_context.PowerOnNWStatus &= ~MMI_NW_STATUS_FLIGHT_MODE;    /* 0x04: Flight mode */

        /* refresh status icons */
        PhnsetFlightModeRestoreStatusIconFlags(MMI_TRUE);
        UpdateStatusIcons();

        /* write current mode to nvram */
        PhnsetFlightModeSaveMode();

        /* diamond, 2005/11/17 Force to draw signal level because signal level indication comes before flight mode switch rsp */
        ChangeStatusIconLevel(STATUS_ICON_SIGNAL_STRENGTH, gSignalStrengthLevel);
    #ifdef __MMI_SUBLCD__
        ChangeStatusIconLevel(STATUS_ICON_SUBLCD_SIGNAL_STRENGTH, gSignalStrengthLevel);
    #endif 

        /* enter next menu */
        DeleteScreenIfPresent(SCR_FLIGHT_MODE_PROGRESS);
        GoBackToHistory(EM_RF_TEST_TOOL_SCR);   /* the screen of RF test tool is already in the history */
    }
    else
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_NOT_DONE),
            IMG_GLOBAL_UNFINISHED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        DeleteScreenIfPresent(SCR_FLIGHT_MODE_PROGRESS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_exit_flight_mode
 * DESCRIPTION
 *  Exit flight mode from engineering mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_exit_flight_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_nw_cfun_state_req_struct *cfun_state_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gEnterEMWithFlightMode)
    {
        /* directly enter next menu */
        GoBackHistory();
        return;
    }

    cfun_state_req = OslConstructDataPtr(sizeof(mmi_nw_cfun_state_req_struct));
    cfun_state_req->cfun_state = 1; /* normal mode */

    SetProtocolEventHandler(mmi_em_exit_flight_mode_rsp, PRT_NW_CFUN_STATE_RSP);
    EntryFlightModeProgress();  /* show searching screen */

    Message.oslMsgId = PRT_NW_CFUN_STATE_REQ;
    Message.oslDataPtr = (oslParaType*) cfun_state_req;
    Message.oslPeerBuffPtr = NULL;
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;

    OslMsgSendExtQueue(&Message);
}

#endif /* __MMI_ENGINEER_MODE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_flight_mode_set_mode
 * DESCRIPTION
 *  Set mode for power on
 * PARAMETERS
 *  bFlightMode       [IN]     U8
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_flight_mode_set_mode(U8 bFlightMode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_nw_cfun_state_req_struct *cfun_state_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cfun_state_req = OslConstructDataPtr(sizeof(mmi_nw_cfun_state_req_struct));

    if (bFlightMode)
    {
    #ifdef __FLIGHT_MODE_SUPPORT__
        PhnsetFlightModeSaveStatusIconFlags(MMI_TRUE);
        UpdateStatusIcons();
    #endif /* __FLIGHT_MODE_SUPPORT__ */ 

        cfun_state_req->cfun_state = 4;
        g_pwr_context.PowerOnNWStatus |= MMI_NW_STATUS_FLIGHT_MODE; /* 0x04: Flight mode */

    #ifdef __MMI_WLAN_FEATURES__
        if (g_phnset_cntx.curFlightMode == FLIGHTMODE_OFF && mmi_netset_get_active_preferred_mode() == P_WLAN_ONLY)
        {
            /* Not update g_phnset_cntx.curFlightMode */
        }
        else
    #endif /* __MMI_WLAN_FEATURES__ */
        if (g_phnset_cntx.curFlightMode != FLIGHTMODE_QUERY)
        {
            g_phnset_cntx.curFlightMode = FLIGHTMODE_SILENT;
        }

    #ifdef __MMI_WLAN_FEATURES__
        if (g_phnset_cntx.curFlightMode == FLIGHTMODE_SILENT)
        {
            g_phnset_cntx.curFlightMode2 = FLIGHTMODE_SILENT;
        }
        else
        {
            g_phnset_cntx.curFlightMode2 = FLIGHTMODE_OFF;
        }
    #endif
    }
    else
    {
        cfun_state_req->cfun_state = 1;
        g_pwr_context.PowerOnNWStatus &= ~MMI_NW_STATUS_FLIGHT_MODE;        /* 0x04 Flight mode */

        if (g_phnset_cntx.curFlightMode != FLIGHTMODE_QUERY)
        {
            g_phnset_cntx.curFlightMode = FLIGHTMODE_OFF;
        }

   #ifdef __MMI_WLAN_FEATURES__
        if (mmi_netset_get_active_preferred_mode() == P_GSM_ONLY)
        {
            g_phnset_cntx.curFlightMode2 = FLIGHTMODE_SILENT;
        }
        else
        {
            g_phnset_cntx.curFlightMode2 = FLIGHTMODE_OFF;
        }
    #endif /* __MMI_WLAN_FEATURES__ */
    }

#ifndef __MMI_DUAL_SIM_MASTER__
    Message.oslMsgId = PRT_NW_CFUN_STATE_REQ;
    Message.oslDataPtr = (oslParaType*) cfun_state_req;
    Message.oslPeerBuffPtr = NULL;
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;

    OslMsgSendExtQueue(&Message);

    if (g_pwr_context.PowerOnMode == POWER_ON_KEYPAD)   /* diamond, 2005/10/21 Do not play animation for exception power on */
    {
        PhnsetFlightModeSaveMode();
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_flight_mode_hide_menu_items
 * DESCRIPTION
 *  Hide some menus after entering flight mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_flight_mode_hide_menu_items(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
    if (!mmi_sim_error_is_present() &&
        !((MTPNP_AD_Get_Card1Status() == MTPNP_AD_SIMCARD_ABSENT || MTPNP_AD_Get_Card1Status() == MTPNP_AD_SIMCARD_CHVBLOCKED) && (MTPNP_AD_Get_Card2Status() == MTPNP_AD_SIMCARD_ABSENT || MTPNP_AD_Get_Card2Status() == MTPNP_AD_SIMCARD_CHVBLOCKED)))
#else
    if (mmi_bootup_is_sim_valid())
#endif
    {
    #ifdef __MMI_DUAL_SIM_MASTER__
        mmi_frm_hide_menu_item(MENU_MTPNP_DM_SHOW_OWNER_NUMBER);
    #else
        mmi_frm_hide_menu_item(MENU_SETTING_SHOW_OWN_NUMBER);
    #endif
    #if defined(__MMI_OPERATOR_NAME_MENU__)
        mmi_frm_hide_menu_item(MENU_SETTING_SHOW_OPN);
    #endif
    #ifdef __MMI_NITZ__
        mmi_frm_hide_menu_item(MENU9145_SETTIMEANDDATENITZ); /* Hide "Auto update of date and time" in flight mode */
        mmi_frm_hide_menu_item(MENU_SETTING_MENU_TREE);
    #endif /* __MMI_NITZ__ */
    #ifdef __MMI_MAINMENU_STYLE_CHANGE_EN__
        mmi_frm_hide_menu_item(MENU_SETTING_MAINMENU_STYLE);
    #endif  /* __MMI_MAINMENU_STYLE_CHANGE_EN__ */
//        mmi_frm_hide_menu_item(MITEM105_PBOOK_OWNER_NUMBER);
    #ifdef __MMI_VRSD__
        mmi_frm_hide_menu_item(MENU_ID_VRSD_APP);
    #endif
    }
#ifdef __MMI_WLAN_FEATURES__
    mmi_frm_hide_menu_item(MENU9185_NETWORK_SETUP); /* Hide "Network Setup" in flight mode if WLAN is activated */
#endif
#if (defined(__MMI_OP01_MENU_9MATRIX__) && (defined(__MMI_IRDA_SUPPORT__) || defined(__MMI_BT_HP_SUPPORT__) || defined(__MMI_BT_SUPPORT__)))
/* under construction !*/
#endif
#ifdef __MMI_BT_SUPPORT__
    mmi_frm_hide_menu_item(MENU_CONN_BT_MAIN);
#endif
#ifdef __MMI_IRDA_SUPPORT__
    mmi_frm_hide_menu_item(MENU_CONN_IRDA_MAIN);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_flight_mode_unhide_menu_items
 * DESCRIPTION
 *  Recover some menus after leaving flight mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_flight_mode_unhide_menu_items(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
    if (!mmi_sim_error_is_present() &&
        !((MTPNP_AD_Get_Card1Status() == MTPNP_AD_SIMCARD_ABSENT || MTPNP_AD_Get_Card1Status() == MTPNP_AD_SIMCARD_CHVBLOCKED) && (MTPNP_AD_Get_Card2Status() == MTPNP_AD_SIMCARD_ABSENT || MTPNP_AD_Get_Card2Status() == MTPNP_AD_SIMCARD_CHVBLOCKED)))
#else
    if (mmi_bootup_is_sim_valid())
#endif
    {
    #ifdef __MMI_DUAL_SIM_MASTER__
        mmi_frm_unhide_menu_item(MENU_MTPNP_DM_SHOW_OWNER_NUMBER);
    #else
        mmi_frm_unhide_menu_item(MENU_SETTING_SHOW_OWN_NUMBER);
    #endif
    #if defined(__MMI_OPERATOR_NAME_MENU__)
        mmi_frm_unhide_menu_item(MENU_SETTING_SHOW_OPN);
    #endif
    #ifdef __MMI_NITZ__
        mmi_frm_unhide_menu_item(MENU9145_SETTIMEANDDATENITZ); /* Hide "Auto update of date and time" in flight mode */
        mmi_frm_unhide_menu_item(MENU_SETTING_MENU_TREE);
    #endif /* __MMI_NITZ__ */
    #ifdef __MMI_MAINMENU_STYLE_CHANGE_EN__
        mmi_frm_unhide_menu_item(MENU_SETTING_MAINMENU_STYLE);
    #endif  /* __MMI_MAINMENU_STYLE_CHANGE_EN__ */
        mmi_frm_unhide_menu_item(MITEM105_PBOOK_OWNER_NUMBER);
    #ifdef __MMI_VRSD__
        mmi_frm_unhide_menu_item(MENU_ID_VRSD_APP);
    #endif
    }
#ifdef __MMI_WLAN_FEATURES__
    mmi_frm_unhide_menu_item(MENU9185_NETWORK_SETUP); /* Hide "Network Setup" in flight mode if WLAN is activated */
#endif
#if (defined(__MMI_OP01_MENU_9MATRIX__) && (defined(__MMI_IRDA_SUPPORT__) || defined(__MMI_BT_HP_SUPPORT__) || defined(__MMI_BT_SUPPORT__)))
/* under construction !*/
#endif
#ifdef __MMI_BT_SUPPORT__
    mmi_frm_unhide_menu_item(MENU_CONN_BT_MAIN);
#endif
#ifdef __MMI_IRDA_SUPPORT__
    mmi_frm_unhide_menu_item(MENU_CONN_IRDA_MAIN);
#endif
}


#ifdef __MMI_WLAN_FEATURES__


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_entry_preferred_mode_progress
 * DESCRIPTION
 *  Progressing screen for mode switch
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_entry_preferred_mode_progress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_FLIGHT_MODE_PROGRESS, NULL, mmi_netset_entry_preferred_mode_progress, NULL);
    SetKeyHandler(NULL, KEY_END, KEY_EVENT_DOWN);
    SetKeyHandler(NULL, KEY_END, KEY_EVENT_UP);
    ShowCategory66Screen(
        STR_ID_NETSET_PREFERRED_MODE,
        0,
        0,
        0,
        0,
        0,
        (PU8) GetString(STR_FLIGHT_MODE_PROGRESS),
        IMG_FLIGHT_MODE_PROGRESS,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_enter_gsm_flight_mode_rsp
 * DESCRIPTION
 *  Enter flight mode from WLAN preferred mode
 * PARAMETERS
 *  info
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phnset_enter_gsm_flight_mode_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_cfun_state_rsp_struct *cfun_state_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cfun_state_rsp = (mmi_nw_cfun_state_rsp_struct*) info;

    ClearProtocolEventHandler(PRT_NW_CFUN_STATE_RSP);

    if (cfun_state_rsp->result == KAL_TRUE)
    {
        //g_phnset_cntx.curFlightMode = FLIGHTMODE_SILENT;
        g_pwr_context.PowerOnNWStatus |= MMI_NW_STATUS_FLIGHT_MODE;     /* 0x04: Flight mode */
        gSignalStrengthLevel = 0;

        /* write current mode to nvram */
        PhnsetFlightModeSaveMode();

        /* force to draw signal level because signal level indication comes before flight mode switch rsp */
        ChangeStatusIconLevel(STATUS_ICON_SIGNAL_STRENGTH, gSignalStrengthLevel);
    #ifdef __MMI_SUBLCD__
        ChangeStatusIconLevel(STATUS_ICON_SUBLCD_SIGNAL_STRENGTH, gSignalStrengthLevel);
    #endif 

        //DeleteScreenIfPresent(SCR_FLIGHT_MODE_PROGRESS);
        mmi_netset_switch_preferred_mode();
    }
    else
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_NOT_DONE),
            IMG_GLOBAL_UNFINISHED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        DeleteScreenIfPresent(SCR_FLIGHT_MODE_PROGRESS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_enter_gsm_flight_mode
 * DESCRIPTION
 *  Enter flight mode from WLAN preferred mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phnset_enter_gsm_flight_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_nw_cfun_state_req_struct *cfun_state_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cfun_state_req = OslConstructDataPtr(sizeof(mmi_nw_cfun_state_req_struct));
    cfun_state_req->cfun_state = 4; /* flight mode */

    SetProtocolEventHandler(mmi_phnset_enter_gsm_flight_mode_rsp, PRT_NW_CFUN_STATE_RSP);
    mmi_netset_entry_preferred_mode_progress();  /* show searching screen */

    Message.oslMsgId = PRT_NW_CFUN_STATE_REQ;
    Message.oslDataPtr = (oslParaType*) cfun_state_req;
    Message.oslPeerBuffPtr = NULL;
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;

    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_exit_gsm_flight_mode_rsp
 * DESCRIPTION
 *  Exit flight mode from WLAN preferred mode
 * PARAMETERS
 *  info
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phnset_exit_gsm_flight_mode_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_cfun_state_rsp_struct *cfun_state_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cfun_state_rsp = (mmi_nw_cfun_state_rsp_struct*) info;

    ClearProtocolEventHandler(PRT_NW_CFUN_STATE_RSP);

    if (cfun_state_rsp->result == KAL_TRUE)
    {
        //g_phnset_cntx.curFlightMode = FLIGHTMODE_OFF;
        g_pwr_context.PowerOnNWStatus &= ~MMI_NW_STATUS_FLIGHT_MODE;    /* 0x04: Flight mode */

        /* write current mode to nvram */
        PhnsetFlightModeSaveMode();

        /* diamond, 2005/11/17 Force to draw signal level because signal level indication comes before flight mode switch rsp */
        ChangeStatusIconLevel(STATUS_ICON_SIGNAL_STRENGTH, gSignalStrengthLevel);
    #ifdef __MMI_SUBLCD__
        ChangeStatusIconLevel(STATUS_ICON_SUBLCD_SIGNAL_STRENGTH, gSignalStrengthLevel);
    #endif 

        //DeleteScreenIfPresent(SCR_FLIGHT_MODE_PROGRESS);
        mmi_netset_switch_preferred_mode();
    }
    else
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_NOT_DONE),
            IMG_GLOBAL_UNFINISHED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        DeleteScreenIfPresent(SCR_FLIGHT_MODE_PROGRESS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_exit_gsm_flight_mode
 * DESCRIPTION
 *  Exit flight mode from WLAN preferred mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phnset_exit_gsm_flight_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_nw_cfun_state_req_struct *cfun_state_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cfun_state_req = OslConstructDataPtr(sizeof(mmi_nw_cfun_state_req_struct));
    cfun_state_req->cfun_state = 1; /* normal mode */

    SetProtocolEventHandler(mmi_phnset_exit_gsm_flight_mode_rsp, PRT_NW_CFUN_STATE_RSP);
    mmi_netset_entry_preferred_mode_progress();  /* show searching screen */

    Message.oslMsgId = PRT_NW_CFUN_STATE_REQ;
    Message.oslDataPtr = (oslParaType*) cfun_state_req;
    Message.oslPeerBuffPtr = NULL;
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;

    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_flight_mode_switch_wlan
 * DESCRIPTION
 *  Switch WLAN after flight mode switch
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_flight_mode_switch_wlan(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phnset_cntx.curFlightMode2 == FLIGHTMODE_OFF)
    {
        PRINT_INFORMATION("@@@@@ Flight mode: turn off WLAN @@@@@");
        g_phnset_cntx.curFlightMode2 = FLIGHTMODE_SILENT;
        mmi_wlan_reset_hw_off(mmi_phnset_switch_flight_mode);
    }
    else
    {
        PRINT_INFORMATION("@@@@@ Flight mode: turn on WLAN @@@@@");
        g_phnset_cntx.curFlightMode2 = FLIGHTMODE_OFF;
        mmi_wlan_reset_hw_on(mmi_phnset_switch_flight_mode);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_power_on_query_with_flight_mode
 * DESCRIPTION
 *  Query when power on and press No
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phnset_power_on_query_with_normal_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 mode = mmi_netset_get_active_preferred_mode();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mode == P_GSM_ONLY)
    {
        g_phnset_cntx.curFlightMode2 = FLIGHTMODE_SILENT;
        PowerOnNormalMode();
    }
    else if (mode == P_WLAN_ONLY)
    {
        g_phnset_cntx.curFlightMode2 = FLIGHTMODE_OFF;
        PowerOnFlightMode();
    }
    else
    {
        g_phnset_cntx.curFlightMode2 = FLIGHTMODE_OFF;
        PowerOnNormalMode();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_power_on_query_with_flight_mode
 * DESCRIPTION
 *  Query when power on and press Yes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phnset_power_on_query_with_flight_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phnset_cntx.curFlightMode2 = FLIGHTMODE_SILENT;
    PowerOnFlightMode();
    if (mmi_netset_get_active_preferred_mode() != P_GSM_ONLY)
    {
        PRINT_INFORMATION("@@@@@ Flight mode: turn off WLAN @@@@@");
        mmi_wlan_reset_hw_off(NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_flight_mode_update_wlan_only_status_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_flight_mode_update_wlan_only_status_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 icon_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (icon_id = 0; icon_id < MAX_STATUS_ICONS; icon_id++)
    {
         /* WLAN mode to flight mode */
        if (g_phnset_cntx.selFlightMode == FLIGHTMODE_SILENT)
        {
            switch (icon_id)
            { 
                case STATUS_ICON_MISSED_CALL:
	        #ifdef __MMI_DUAL_SIM_MASTER__
        	  case STATUS_ICON_CARD2MISSED_CALL:
            #endif/*__MMI_DUAL_SIM_MASTER__*/
            #ifndef __MMI_SUBLCD_SHORT_STATUSICON_LIST__
                case STATUS_ICON_SUBLCD_MISSED_CALL:
            #endif
                case STATUS_ICON_UNREAD_EMAIL:
                case STATUS_ICON_UNREAD_EMAIL_L1L2:
                case STATUS_ICON_UNREAD_EMAIL_L1:
                case STATUS_ICON_UNREAD_EMAIL_L2:
            #if defined(OBIGO_Q05A) || !defined(__MMI_UNIFIED_MESSAGE__)
                case STATUS_ICON_WAP:
            #endif
            #ifdef __MMI_POC__
                case STATUS_ICON_POC:
            #endif
            #ifdef __MMI_IMPS__
                case STATUS_ICON_IMPS_MSG:
                case STATUS_ICON_IMPS_LOGIN:
            #endif
                    g_status_icon_display_invisible[icon_id] = get_status_icon_flag(icon_id);
                    set_status_icon_flag(icon_id, 0);
                    break;

                default:
                    break;
            }            
        }
        else
        {
            switch (icon_id)
            {
                case STATUS_ICON_MISSED_CALL:
	        #ifdef __MMI_DUAL_SIM_MASTER__
        	  case STATUS_ICON_CARD2MISSED_CALL:
            #endif/*__MMI_DUAL_SIM_MASTER__*/
            #ifndef __MMI_SUBLCD_SHORT_STATUSICON_LIST__
                case STATUS_ICON_SUBLCD_MISSED_CALL:
            #endif
                case STATUS_ICON_UNREAD_EMAIL:
                case STATUS_ICON_UNREAD_EMAIL_L1L2:
                case STATUS_ICON_UNREAD_EMAIL_L1:
                case STATUS_ICON_UNREAD_EMAIL_L2:
            #if defined(OBIGO_Q05A) || !defined(__MMI_UNIFIED_MESSAGE__)
                case STATUS_ICON_WAP:
            #endif
            #ifdef __MMI_POC__
                case STATUS_ICON_POC:
            #endif
            #ifdef __MMI_IMPS__
                case STATUS_ICON_IMPS_MSG:
                case STATUS_ICON_IMPS_LOGIN:
            #endif
                    set_status_icon_flag(icon_id, g_status_icon_display_invisible[icon_id]);
                    break;

            default:
                break;
            }
        }
    }

    UpdateStatusIcons();
}


#endif /* __MMI_WLAN_FEATURES__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_switch_preferred_mode
 * DESCRIPTION
 *  Switch flight mode beginning and callback function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phnset_switch_flight_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("@@@@@ Flight mode: switch mode @@@@@");

    for (i = 0; mmi_phnset_f_mode_req[i].phnset_flight_mode_req != NULL; i++)
    {
        if (mmi_phnset_f_mode_req[i].state)
        {
            mmi_phnset_f_mode_req[i].state = 0;
            (*mmi_phnset_f_mode_req[i].phnset_flight_mode_req)();
            return;
        }
    }

    PhnsetFlightModeSaveMode();
    if (mmi_bootup_get_active_flight_mode() == FLIGHTMODE_OFF)
    {
        mmi_flight_mode_unhide_menu_items();
    }
    else
    {
        mmi_flight_mode_hide_menu_items();
    }
    mmi_phnset_flight_mode_selection_finish();

    for (i = 0; mmi_phnset_f_mode_req[i].phnset_flight_mode_req != NULL; i++)
    {
	mmi_phnset_f_mode_req[i].state = 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_confirm_to_switch_mode
 * DESCRIPTION
 *  Confirm to perform mode switch
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phnset_confirm_to_switch_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_BT_SUPPORT__) || defined(__MMI_IRDA_SUPPORT__)
    U8 i;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phnset_cntx.selFlightMode == FLIGHTMODE_QUERY)
    {
        PhnsetFlightModeSelectionReq();
        return;
    }

    if ((g_phnset_cntx.selFlightMode != FLIGHTMODE_QUERY) &&
        (g_phnset_cntx.curFlightMode == FLIGHTMODE_QUERY) &&
        (mmi_bootup_get_active_flight_mode() == g_phnset_cntx.selFlightMode))
    {
        PhnsetFlightModeSelectionReq();
        return;
    }

#ifdef __MMI_WLAN_FEATURES__
    switch (mmi_netset_get_active_preferred_mode())
    {
        case P_GSM_ONLY:
            mmi_phnset_f_mode_req[0].state = 1;
            mmi_phnset_f_mode_req[1].state = 0;
            break;

        case P_WLAN_ONLY:
            mmi_phnset_f_mode_req[0].state = 0;
            mmi_phnset_f_mode_req[1].state = 1;
            break;

        default:
            mmi_phnset_f_mode_req[0].state = 1;
            mmi_phnset_f_mode_req[1].state = 1;
            break;
    }
#else /* __MMI_WLAN_FEATURES__ */
    mmi_phnset_f_mode_req[0].state = 1; /* GSM always needs to switch */
#endif /* __MMI_WLAN_FEATURES__ */

#ifdef __MMI_BT_SUPPORT__
    for (i = 0; mmi_phnset_f_mode_req[i].phnset_flight_mode_req != NULL; i++)
    {
        if (mmi_phnset_f_mode_req[i].phnset_flight_mode_req == mmi_flight_mode_switch_bluetooth)
        {
            mmi_phnset_f_mode_req[i].state = 1;
            break;
        }
    }
#endif /* __MMI_BT_SUPPORT__ */

#ifdef __MMI_IRDA_SUPPORT__
    for (i = 0; mmi_phnset_f_mode_req[i].phnset_flight_mode_req != NULL; i++)
    {
        if (mmi_phnset_f_mode_req[i].phnset_flight_mode_req == mmi_flight_mode_switch_irda)
        {
            mmi_phnset_f_mode_req[i].state = 1;
            break;
        }
    }
#endif /* __MMI_IRDA_SUPPORT__ */

    gSetModeFromMenu = MMI_TRUE;
    gIsFlightModeSwitching = MMI_TRUE;
    EntryFlightModeProgress();  /* show searching screen */

#ifdef __MMI_WLAN_FEATURES__
    if (mmi_phnset_f_mode_req[0].state == 0)
    {
        g_phnset_cntx.curFlightMode = g_phnset_cntx.selFlightMode;
        mmi_flight_mode_update_wlan_only_status_icon();
    }
#endif /* __MMI_WLAN_FEATURES__ */

#ifdef __SYNCML_SUPPORT__
    if (mmi_syncml_is_phb_sync_now() || mmi_syncml_is_tdl_sync_now())
    {
        mmi_syncml_abort_sync_req();
    }
#endif /* __SYNCML_SUPPORT__ */

    mmi_phnset_switch_flight_mode();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_flight_mode_need_play_camp_on_tone
 * DESCRIPTION
 *  Need to play camp on tone if back to normal mode with full service
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_flight_mode_need_play_camp_on_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gLeaveFlightModeWithFullService)
    {
        mmi_phnset_flight_mode_camp_on_tone_hdlr();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_flight_mode_reset_camp_on_tone_event
 * DESCRIPTION
 *  Camp on tone event is avaliable before timeout
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_flight_mode_reset_camp_on_tone_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gLeaveFlightModeWithFullService = 0;
}


#endif /* __FLIGHT_MODE_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_flight_mode_is_status_icon_visible
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_flight_mode_is_status_icon_visible(S16 icon_id, U32 icon_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pBOOL rtn = 0; // invisible

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* 
     * The desired status icon to display is allowed or not.
     */
    switch (icon_id)
    {
        case STATUS_ICON_ROAMING:
        case STATUS_ICON_CALL_DIVERT_L1L2:
    #ifdef __MMI_CFU_SEPARATE_LINE__
        case STATUS_ICON_CALL_DIVERT_L1:
        case STATUS_ICON_CALL_DIVERT_L2:
    #endif
        case STATUS_ICON_INCOMING_SMS:
       case STATUS_ICON_UNREAD_VOICE_L1L2:
        case STATUS_ICON_UNREAD_VOICE_L1:
        case STATUS_ICON_UNREAD_VOICE_L2:
        case STATUS_ICON_UNREAD_FAX_L1L2:
        case STATUS_ICON_UNREAD_FAX_L1:
        case STATUS_ICON_UNREAD_FAX_L2:
        case STATUS_ICON_SUBLCD_SMS:
        case STATUS_ICON_MMS_UNREAD:
        case STATUS_ICON_MMS_BUSY:
        case STATUS_ICON_CHAT_INDICATION_ROOM1:
        case STATUS_ICON_CHAT_INDICATION_ROOM2:
    #ifndef __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__
        case STATUS_ICON_ALTERNATE_LINE_L1:
        case STATUS_ICON_ALTERNATE_LINE_L2:
    #endif
    #if !defined(OBIGO_Q05A) && defined(__MMI_UNIFIED_MESSAGE__)
        case STATUS_ICON_WAP:
    #endif
    #ifdef __MMI_DUAL_SIM_MASTER__
        case STATUS_ICON_SLAVE_CALLFORWARD:
        case STATUS_ICON_SLAVE_CALLFORWARD_L1:
        case STATUS_ICON_SLAVE_CALLFORWARD_L2:
        case STATUS_ICON_SLAVE_ROAMING:
        case STATUS_ICON_SLAVE_INCOMING_SMS:
        case STATUS_ICON_MMS_UNREAD_SIM_1:
        case STATUS_ICON_MMS_UNREAD_SIM_2:
        case STATUS_ICON_MMS_BUSY_SIM_1:
        case STATUS_ICON_MMS_BUSY_SIM_2:
        case STATUS_ICON_UNREAD_VOICE_L1_MASTER:
        case STATUS_ICON_UNREAD_VOICE_L2_MASTER:
        case STATUS_ICON_UNREAD_VOICE_L1L2_MASTER:
        case STATUS_ICON_UNREAD_FAX_L1_MASTER:
        case STATUS_ICON_UNREAD_FAX_L2_MASTER:
        case STATUS_ICON_UNREAD_FAX_L1L2_MASTER:
        case STATUS_ICON_UNREAD_NET_L1_MASTER:
        case STATUS_ICON_UNREAD_NET_L2_MASTER:
        case STATUS_ICON_UNREAD_NET_L1L2_MASTER:
        case STATUS_ICON_UNREAD_VOICE_L1_SLAVE:
        case STATUS_ICON_UNREAD_VOICE_L2_SLAVE:
        case STATUS_ICON_UNREAD_VOICE_L1L2_SLAVE:
        case STATUS_ICON_UNREAD_FAX_L1_SLAVE:
        case STATUS_ICON_UNREAD_FAX_L2_SLAVE:
        case STATUS_ICON_UNREAD_FAX_L1L2_SLAVE:
        case STATUS_ICON_UNREAD_NET_L1_SLAVE:
        case STATUS_ICON_UNREAD_NET_L2_SLAVE:
        case STATUS_ICON_UNREAD_NET_L1L2_SLAVE:
    #endif /* __MMI_DUAL_SIM_MASTER__ */
#ifndef __MMI_DUAL_SIM_MASTER__
        /* these status icons are invisible in flight mode, WLAN mode or SIM error mode */
        #ifdef __MMI_WLAN_FEATURES__
            if (mmi_bootup_get_active_flight_mode() == FLIGHTMODE_SILENT || mmi_bootup_is_sim_valid() == 0 || mmi_netset_get_active_preferred_mode() == P_WLAN_ONLY)
        #else
            if (mmi_bootup_get_active_flight_mode() == FLIGHTMODE_SILENT || mmi_bootup_is_sim_valid() == 0)
        #endif
#else    /* __MMI_DUAL_SIM_MASTER__ */
        /* these status icons are invisible in flight mode, WLAN mode or SIM error mode */
        #ifdef __MMI_WLAN_FEATURES__
            if (mmi_bootup_get_active_flight_mode() == FLIGHTMODE_SILENT ||
		(mmi_bootup_is_sim_valid() == 0 && MTPNP_PFAL_Is_Card2Absent()) ||
		mmi_netset_get_active_preferred_mode() == P_WLAN_ONLY)
        #else
            if (mmi_bootup_get_active_flight_mode() == FLIGHTMODE_SILENT ||
		(mmi_bootup_is_sim_valid() == 0 && MTPNP_PFAL_Is_Card2Absent()))
        #endif
#endif    /* __MMI_DUAL_SIM_MASTER__ */
               g_status_icon_display_invisible[icon_id] = icon_flag;
            else
               rtn = 1; // visible
            break;

        case STATUS_ICON_MISSED_CALL:
    #ifdef __MMI_DUAL_SIM_MASTER__
        case STATUS_ICON_CARD2MISSED_CALL:
    #endif/*__MMI_DUAL_SIM_MASTER__*/
    #ifndef __MMI_SUBLCD_SHORT_STATUSICON_LIST__
        case STATUS_ICON_SUBLCD_MISSED_CALL:
    #endif
        case STATUS_ICON_UNREAD_EMAIL:
        case STATUS_ICON_UNREAD_EMAIL_L1L2:
        case STATUS_ICON_UNREAD_EMAIL_L1:
        case STATUS_ICON_UNREAD_EMAIL_L2:
    #ifdef __MMI_DUAL_SIM_MASTER__
        case STATUS_ICON_UNREAD_EMAIL_L1_MASTER:
        case STATUS_ICON_UNREAD_EMAIL_L2_MASTER:
        case STATUS_ICON_UNREAD_EMAIL_L1L2_MASTER:
        case STATUS_ICON_UNREAD_EMAIL_L1_SLAVE:
        case STATUS_ICON_UNREAD_EMAIL_L2_SLAVE:
        case STATUS_ICON_UNREAD_EMAIL_L1L2_SLAVE:
    #endif /* __MMI_DUAL_SIM_MASTER__ */
    #if defined(OBIGO_Q05A) || !defined(__MMI_UNIFIED_MESSAGE__)
        case STATUS_ICON_WAP:
    #endif
    #ifdef __MMI_POC__
        case STATUS_ICON_POC:
    #endif
    #ifdef __MMI_IMPS__
        case STATUS_ICON_IMPS_MSG:
        case STATUS_ICON_IMPS_LOGIN:
    #endif
        /* these status icons are invisible in flight mode or GSM only mode without SIM */
#ifndef __MMI_DUAL_SIM_MASTER__
        #ifdef __MMI_WLAN_FEATURES__
            if (mmi_netset_get_active_preferred_mode() != P_GSM_ONLY && mmi_bootup_get_active_flight_mode() != FLIGHTMODE_SILENT)
                rtn = 1; // visible
            else if (mmi_netset_get_active_preferred_mode() == P_GSM_ONLY && mmi_bootup_get_active_flight_mode() == FLIGHTMODE_OFF && mmi_bootup_is_sim_valid() == 1)
                rtn = 1; // visible
            else
                g_status_icon_display_invisible[icon_id] = icon_flag;
        #else
            if (mmi_bootup_get_active_flight_mode() == FLIGHTMODE_SILENT || mmi_bootup_is_sim_valid() == 0)
                g_status_icon_display_invisible[icon_id] = icon_flag;
            else
               rtn = 1; // visible
        #endif /* __MMI_WLAN_FEATURES__ */
#else    /* __MMI_DUAL_SIM_MASTER__ */
        #ifdef __MMI_WLAN_FEATURES__
            if (mmi_netset_get_active_preferred_mode() != P_GSM_ONLY && mmi_bootup_get_active_flight_mode() != FLIGHTMODE_SILENT)
                rtn = 1; // visible
            else if (mmi_netset_get_active_preferred_mode() == P_GSM_ONLY && mmi_bootup_get_active_flight_mode() == FLIGHTMODE_OFF && mmi_bootup_is_sim_valid() == 1)
                rtn = 1; // visible
            else
                g_status_icon_display_invisible[icon_id] = icon_flag;
        #else
            if (mmi_bootup_get_active_flight_mode() == FLIGHTMODE_SILENT || 
		(mmi_bootup_is_sim_valid() == 0 && MTPNP_PFAL_Is_Card2Absent()))
                g_status_icon_display_invisible[icon_id] = icon_flag;
            else
               rtn = 1; // visible
        #endif /* __MMI_WLAN_FEATURES__ */

#endif    /* __MMI_DUAL_SIM_MASTER__ */
            break;

        default:
            rtn = 1; // visible
            break;
    }

    if (!rtn)
    {
        PRINT_INFORMATION("Status icon %d is requested to display but invisible", icon_id);
    }

    return rtn;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_flight_mode_popup_in_dialing_sos
 * DESCRIPTION
 *  Popup "flight mode" when dial SOS from insert SIM screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_flight_mode_popup_in_dialing_sos(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __FLIGHT_MODE_SUPPORT__
    DisplayPopup((U8*) GetString(STR_MENU_FLIGHT_MODE), IMG_GLOBAL_ERROR, 0, 2000, (U8) ERROR_TONE);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_flight_mode_popup_in_dialing_sos
 * DESCRIPTION
 *  Popup "flight mode" when dial SOS from insert SIM screen
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_flight_mode_is_switching(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __FLIGHT_MODE_SUPPORT__
    return (U8)gIsFlightModeSwitching;
#else
    return 0;
#endif /* __FLIGHT_MODE_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_flight_mode_switching_in_idle
 * DESCRIPTION
 *  Popup "flight mode" when dial SOS from insert SIM screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_flight_mode_switching_in_idle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*
     * There is an interrupt breaking the flight mode switching screen.
     * Idle screen will force to enter flight mode switching screen again.
     */
#ifdef __FLIGHT_MODE_SUPPORT__
    EntryFlightModeProgress();
#else
    MMI_ASSERT(0);
#endif
}


#ifdef __MMI_DUAL_SIM_MASTER__
void PowerOnOnlyCloseRFMode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_nw_cfun_state_req_struct *cfun_state_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cfun_state_req = OslConstructDataPtr(sizeof(mmi_nw_cfun_state_req_struct));

    PhnsetFlightModeSaveStatusIconFlags(MMI_TRUE);
    RemoveStatusIconsForSimRemoved();
    UpdateStatusIcons();

    cfun_state_req->cfun_state = 4;
    g_pwr_context.PowerOnNWStatus &= ~MMI_NW_STATUS_FLIGHT_MODE; /* close RF, but do not set Flight mode */

    if (g_phnset_cntx.curFlightMode != FLIGHTMODE_QUERY)
    {
        g_phnset_cntx.curFlightMode = FLIGHTMODE_OFF;
    }

    Message.oslMsgId = PRT_NW_CFUN_STATE_REQ;
    Message.oslDataPtr = (oslParaType*) cfun_state_req;
    Message.oslPeerBuffPtr = NULL;
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;

    OslMsgSendExtQueue(&Message);

    ExitCategory165Screen();                /* StopTimer(POPUP_TIMER); */
    ClearInputEventHandler(MMI_DEVICE_ALL); /* prevent user press key after mode selection in qurey screen */

    /* apply to handphone only */
#if defined(__MMI_BT_HP_SUPPORT__)
    mmi_bt_reset_hw_off();
#endif 

    DeleteScreenIfPresent(GLOBAL_SCR_DUMMY);

    if (g_pwr_context.PowerOnMode == POWER_ON_KEYPAD)   /* diamond, 2005/10/21 Do not play animation for exception power on */
    {
        PhnsetFlightModeSaveMode();
	 mmi_bootup_exit_flight_mode_query();
    }
}
#endif /* __MMI_DUAL_SIM_MASTER__ */

#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
void PowerOnSIM2FlightMode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_cfun_state_req_struct *cfun_state_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cfun_state_req = OslConstructDataPtr(sizeof(mmi_nw_cfun_state_req_struct));
    cfun_state_req->cfun_state = 4;
    MTPNP_PFAL_send_message(MOD_MMI, MOD_L4C_2, 0, PRT_NW_CFUN_STATE_REQ, (oslParaType *) cfun_state_req, MTPNP_NULL);

    if (g_pwr_context_2.PowerOnMMIStatus < MMI_POWER_ON_ANIMATION)
    {
        g_pwr_context_2.PowerOnMMIStatus = MMI_POWER_ON_ANIMATION; /* set SIM2 power on state to animation but not really play it */
    }
    g_pwr_context_2.PowerOnNWStatus |= MMI_NW_STATUS_FLIGHT_MODE; /* 0x04: Flight mode */
}

void PowerOnSIM2NormalMode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_cfun_state_req_struct *cfun_state_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cfun_state_req = OslConstructDataPtr(sizeof(mmi_nw_cfun_state_req_struct));
    cfun_state_req->cfun_state = 1;
    MTPNP_PFAL_send_message(MOD_MMI, MOD_L4C_2, 0, PRT_NW_CFUN_STATE_REQ, (oslParaType *) cfun_state_req, MTPNP_NULL);

    if (g_pwr_context_2.PowerOnMMIStatus < MMI_POWER_ON_ANIMATION)
    {
        g_pwr_context_2.PowerOnMMIStatus = MMI_POWER_ON_ANIMATION; /* set SIM2 power on state to animation but not really play it */
    }
    g_pwr_context_2.PowerOnNWStatus &= ~MMI_NW_STATUS_FLIGHT_MODE;
}


void PhnsetDualModeSaveMode(U8 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data[NVRAM_EF_SYS_CACHE_OCTET_SIZE];
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("@@@@@ Flight mode: save mode @@@@@");
    ReadRecord(NVRAM_EF_SYS_CACHE_OCTET_LID, 2, &data, NVRAM_EF_SYS_CACHE_OCTET_SIZE, &error);

    g_phnset_cntx.curFlightMode = (mode == MTPNP_AD_NVRAM_FLIGHT) ? FLIGHTMODE_SILENT : FLIGHTMODE_OFF;
    data[0] = g_phnset_cntx.curFlightMode;
    data[1] = (U8) mmi_bootup_get_active_flight_mode();

    if (g_phnset_cntx.curFlightMode == FLIGHTMODE_SILENT)
    {
        g_pwr_context.PowerOnNWStatus |= MMI_NW_STATUS_FLIGHT_MODE;
        g_pwr_context_2.PowerOnNWStatus |= MMI_NW_STATUS_FLIGHT_MODE;
    }
    else
    {
        g_pwr_context.PowerOnNWStatus &= ~MMI_NW_STATUS_FLIGHT_MODE;
        g_pwr_context_2.PowerOnNWStatus &= ~MMI_NW_STATUS_FLIGHT_MODE;
    }

    switch (mode)
    {
        case MTPNP_AD_NVRAM_CARD1:
            data[2] = 0;        
            break;
            
        case MTPNP_AD_NVRAM_CARD2:
            data[2] = 1;
            break;

        case MTPNP_AD_NVRAM_FLIGHT:
            break;

        case MTPNP_AD_NVRAM_DUALCARD:            
        default:
            data[2] = 2;        
            break;
    }

    WriteRecord(NVRAM_EF_SYS_CACHE_OCTET_LID, 2, &data, NVRAM_EF_SYS_CACHE_OCTET_SIZE, &error);
}


#endif /* __MMI_DUAL_SIM_SINGLE_CALL__ */


