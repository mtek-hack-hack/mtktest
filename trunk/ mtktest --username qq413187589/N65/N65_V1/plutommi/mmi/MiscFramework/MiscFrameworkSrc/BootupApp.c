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
 *  BootupApp.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/


#include "MMI_include.h"

#include "SimDetectionDef.h"
#include "SimDetectionGprot.h"
#include "SettingDefs.h"
#include "SettingProfile.h"
#include "ProfileGprots.h"
#include "FlightModeGProt.h"
#include "ProtocolEvents.h"

#ifdef __MMI_TOUCH_SCREEN__
#include "gui_data_types.h"
#include "PhoneSetupGProts.h"
#endif /* __MMI_TOUCH_SCREEN__ */ 

#include "IdleAppProt.h"
#include "FileManagerDef.h"
#include "AlarmFrameworkProt.h"

#ifdef __MMI_WLAN_FEATURES__
#include "NetworkSetupDefs.h"
#include "PhoneSetup.h"
extern PHNSET_CNTX g_phnset_cntx;
#endif /* __MMI_WLAN_FEATURES__ */

#if defined(__MMI_DUAL_SIM_MASTER__)
#include "MTPNP_AD_master_header.h"
#include "MTPNP_PFAL_Master_MM.h"
#include "wgui_status_icons.h"
#endif  /* __MMI_DUAL_SIM_MASTER__ */

#if defined(__MMI_DUAL_SIM_DUAL_CALL_SLAVE__)
#include "MTPNP_AD_slave_header.h"
#endif

/**************************************************************************
            Global Variables
**************************************************************************/

/* diamond, 2005/08/16 bootup revise */
pwr_context_struct g_pwr_context = 
{
    0,                  /* g_pwr_context.IsCampOnTonePlayed; */
    1,                  /* g_pwr_context.testRoaming; */
    /* diamond, 2005/12/28 Even if __MANUAL_MODE_NW_SEL__ is on, idle screen also need to show something. This value cannot be set to 5. */
    LIMITED_SERVICE,    /* g_pwr_context.CurrentServiceType; */
    0,                  /* g_pwr_context.AbnormalReset; */
    0,                  /* g_pwr_context.NoOfPLMNSupported; */
    0,                  /* g_pwr_context.PrevScreenIndicator; */
    0,                  /* g_pwr_context.ForCMToIdentifySOSCall; */
#ifdef __MMI_DUAL_SIM_MASTER__
    1,
#else
    0,                  /* g_pwr_context.InvalidSimShowed; */
#endif
    0,                  /* g_pwr_context.CurrentCampOnBand; */
    1,                  /* g_pwr_context.RequireRPLMN; */
    0,                  /* g_pwr_context.SOSCallFlagTOAvoidHistorySave; */
    0,                  /* g_pwr_context.PowerOnMode; */
    0,                  /* g_pwr_context.NandIdCheckRes */

#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
    0,
    0,
#endif

    /* new design for power on status */
    0,  /* g_pwr_context.PowerOnMMIStatus */
    1,  /* g_pwr_context.PowerOnSIMStatus (invalid SIM as default) */
    0,  /* g_pwr_context.PowerOnNWStatus */
    0   /* g_pwr_context.PowerOffMMIStatus */
};

/* end, diamond */

#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
pwr_context_struct g_pwr_context_2 = 
{
    0,                  /* g_pwr_context.IsCampOnTonePlayed; */
    1,                  /* g_pwr_context.testRoaming; */
    /* diamond, 2005/12/28 Even if __MANUAL_MODE_NW_SEL__ is on, idle screen also need to show something. This value cannot be set to 5. */
    LIMITED_SERVICE,    /* g_pwr_context.CurrentServiceType; */
    0,                  /* g_pwr_context.AbnormalReset; */
    0,                  /* g_pwr_context.NoOfPLMNSupported; */
    0,                  /* g_pwr_context.PrevScreenIndicator; */
    0,                  /* g_pwr_context.ForCMToIdentifySOSCall; */
#ifdef __MMI_DUAL_SIM_MASTER__
    1,
#else
    0,                  /* g_pwr_context.InvalidSimShowed; */
#endif
    0,                  /* g_pwr_context.CurrentCampOnBand; */
    1,                  /* g_pwr_context.RequireRPLMN; */
    0,                  /* g_pwr_context.SOSCallFlagTOAvoidHistorySave; */
    0,                  /* g_pwr_context.PowerOnMode; */
    0,                  /* g_pwr_context.NandIdCheckRes */

#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
    0,
    0,
#endif

    /* new design for power on status */
    0,  /* g_pwr_context.PowerOnMMIStatus */
    1,  /* g_pwr_context.PowerOnSIMStatus (invalid SIM as default) */
    0,  /* g_pwr_context.PowerOnNWStatus */
    0   /* g_pwr_context.PowerOffMMIStatus */
};

MMI_BOOL sim2_status_finish = MMI_FALSE;
MMI_BOOL power_on_mode_finish = MMI_TRUE;
extern U8 gSignalStrengthLevel;

#endif /* __MMI_DUAL_SIM_SINGLE_CALL__ */

/**************************************************************************
            Code
**************************************************************************/

/* diamond, 2005/08/16 bootup revise */
/* please refer to SimDetectionDef.h to get detailed MMI power on status */


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_is_before_power_on
 * DESCRIPTION
 *  Check MMI is in the before power on status or not
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_bootup_is_before_power_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* replace isBeforePowerOn */
    if (g_pwr_context.PowerOnMMIStatus == MMI_POWER_ON_DEFAULT)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_is_in_power_on_period
 * DESCRIPTION
 *  Check MMI is in the period of power on or not
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_bootup_is_in_power_on_period(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pwr_context.PowerOnMode == POWER_ON_CHARGER_IN
#ifdef __MMI_USB_SUPPORT__
        || g_pwr_context.PowerOnMode == POWER_ON_USB
#endif 
        )
        return MMI_FALSE;

    /* replace g_pwr_context.PowerOnPeriod */
    if (g_pwr_context.PowerOnMMIStatus <= MMI_POWER_ON_SECURITY_NO_PSWD
        || g_pwr_context.PowerOnMMIStatus == MMI_POWER_ON_WELCOME
#ifdef __MMI_APHORISM__
/* under construction !*/
#endif 
        )
        return MMI_TRUE;
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_is_power_on_animation_complete
 * DESCRIPTION
 *  Check power on animation is complete or not
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_bootup_is_power_on_animation_complete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* replace g_pwr_context.PowerOnAnimationComplete */
    if (g_pwr_context.PowerOnMMIStatus >= MMI_POWER_ON_LOW_BATTERY)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_is_in_security_check
 * DESCRIPTION
 *  Check MMI is in the status of security check or not
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_bootup_is_in_security_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* replace g_pwr_context.PowerOnTillIdleApp */
    if (g_pwr_context.PowerOnMMIStatus & MMI_POWER_ON_SECURITY_NO_PSWD)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_is_searching_or_idle_reached
 * DESCRIPTION
 *  Check MMI has entered idle screen (including searching screen) or not
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_bootup_is_searching_or_idle_reached(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* replace g_pwr_context.idleScreenFirst */
    if (g_pwr_context.PowerOnMMIStatus >= MMI_POWER_ON_NW_SEARCHING)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_is_idle_screen_reached
 * DESCRIPTION
 *  Check MMI has entered idle screen or not
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_bootup_is_idle_screen_reached(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pwr_context.PowerOnMMIStatus >= MMI_POWER_ON_IDLE)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_is_playing_power_on_animation
 * DESCRIPTION
 *  Check MMI is playing power on animation or not
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_bootup_is_playing_power_on_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pwr_context.PowerOnMMIStatus & MMI_POWER_ON_ANIMATION)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_is_sim_valid
 * DESCRIPTION
 *  Check SIM card is valid or not (with MSG_ID_SIM_CARD_FAILURE)
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_bootup_is_sim_valid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* replace g_pwr_context.IsSimValid */
    if (g_pwr_context.PowerOnSIMStatus & MMI_SIM_STATUS_INVALID)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_is_sim_removed
 * DESCRIPTION
 *  Check SIM is inserted or not (with MSG_ID_SIM_CARD_FAILURE)
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_bootup_is_sim_removed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* replace g_pwr_context.SimRemovedFlag */
    if (g_pwr_context.PowerOnSIMStatus & MMI_SIM_STATUS_NOT_INSERT)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_is_sim_refresh
 * DESCRIPTION
 *  Check SIM is refreshing or not (with MSG_ID_SIM_CARD_FAILURE)
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_bootup_is_sim_refresh(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* gSIMRefresh */
    if (g_pwr_context.PowerOnSIMStatus & MMI_SIM_STATUS_REFRESH)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_is_sim_need_security_check
 * DESCRIPTION
 *  Check SIM needs to pass security check or not (with MSG_ID_GET_PIN_RES)
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_bootup_is_sim_need_security_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* replace g_pwr_context.PasswdReqIndFlag */
    if (g_pwr_context.PowerOnSIMStatus & MMI_SIM_STATUS_SECURITY_CHECK)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_is_sim_failure_received
 * DESCRIPTION
 *  Check SIM failure response is received or not (with MSG_ID_SIM_CARD_FAILURE)
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_bootup_is_sim_failure_received(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* replace g_pwr_context.SimQueryFailIndFlag */
    if (g_pwr_context.PowerOnSIMStatus & MMI_SIM_STATUS_FAILURE_RSP)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_is_roaming
 * DESCRIPTION
 *  Check SIM is roaming or not
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_bootup_is_roaming(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* replace g_pwr_context.RoamingFlag */
    if (g_pwr_context.PowerOnSIMStatus & MMI_SIM_STATUS_ROAMING)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_is_network_searching_complete
 * DESCRIPTION
 *  Check network searching is done/timeout or not
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_bootup_is_network_searching_complete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* replace g_pwr_context.NetWorkFlag */
    if (g_pwr_context.PowerOnNWStatus & MMI_NW_STATUS_NETWORK_FLAG)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_is_nw_registration_ok
 * DESCRIPTION
 *  Check network registration is successful or not
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_bootup_is_nw_registration_ok(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* replace g_pwr_context.InvalidSim */
    if (g_pwr_context.PowerOnNWStatus & MMI_NW_STATUS_REG_FAILED)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_get_plmn_selection_mode
 * DESCRIPTION
 *  Get PLMN selection is automatic or manual
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_bootup_get_plmn_selection_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* replace g_pwr_context.PLMNSelectionMode */
#ifdef __MANUAL_MODE_NW_SEL__
    if (g_pwr_context.PowerOnNWStatus & MMI_NW_STATUS_PLMNSEL_MODE)
    {
    #ifdef __MMI_WLAN_FEATURES__
        if (mmi_bootup_is_sim_valid() == MMI_FALSE)
            return AUTOMATIC_MODE;
    #endif /* __MMI_WLAN_FEATURES__ */
            return MANUAL_MODE;
    }
    else
    {
        return AUTOMATIC_MODE;
    }
#else /* __MANUAL_MODE_NW_SEL__ */ 
    return AUTOMATIC_MODE;
#endif /* __MANUAL_MODE_NW_SEL__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_get_active_flight_mode
 * DESCRIPTION
 *  Get active mode is flight or normal
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_bootup_get_active_flight_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* replace g_pwr_context.actFlightMode */
#ifdef __FLIGHT_MODE_SUPPORT__
    if ((g_pwr_context.PowerOnNWStatus & MMI_NW_STATUS_FLIGHT_MODE)
#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
    && (g_pwr_context_2.PowerOnNWStatus & MMI_NW_STATUS_FLIGHT_MODE)
#endif
#ifdef __MMI_WLAN_FEATURES__
    && (g_phnset_cntx.curFlightMode2 == 1)
#endif
    )
    {
        return FLIGHTMODE_SILENT;
    }
    else
    {
        return FLIGHTMODE_OFF;
    }
#else /* __FLIGHT_MODE_SUPPORT__ */ 
    return 0;
#endif /* __FLIGHT_MODE_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_is_wcdma_service
 * DESCRIPTION
 *  Get active service is WCDMA or GSM/GPRS
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_bootup_is_wcdma_service(void)
{
#if defined(__GSM_RAT__) && defined(__WCDMA_RAT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__GSM_RAT__) && defined(__WCDMA_RAT__) */ 
        return MMI_FALSE;
}

/* end, diamond */


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_get_active_bt_access_profile_mode
 * DESCRIPTION
 *  Get BT access profile is active or not
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_bootup_get_active_bt_access_profile_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SIMAP_SUPPORT__
    if (g_pwr_context.PowerOnSIMStatus & MMI_SIM_STATUS_BT_ACCESS)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
#else /* __MMI_SIMAP_SUPPORT__ */ 
    return 0;
#endif /* __MMI_SIMAP_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_is_network_service_available
 * DESCRIPTION
 *  Check if network service for GPRS/WiFi is available
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_bootup_is_network_service_available(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_WLAN_FEATURES__
    if (mmi_bootup_is_sim_valid())
    {
        return MMI_TRUE;
    }
    else if (mmi_netset_get_active_preferred_mode() != 0)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE; /* preferred mode is GSM only without SIM */
    }
#else /* __MMI_WLAN_FEATURES__ */
    return mmi_bootup_is_sim_valid();
#endif /* __MMI_WLAN_FEATURES__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_disk_check_entry_warning_screen
 * DESCRIPTION
 *  Bootup screen flow control
 * PARAMETERS
 *  string_id    U16
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_disk_check_entry_warning_screen(U16 string_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_DISK_CHECK;    /* 0x02: Flight mode screen */

    guiBuffer = GetCurrGuiBuffer(SCR_BOOTUP_CHECK_DISK);

    EntryNewScreen(SCR_BOOTUP_CHECK_DISK, NULL, NULL, NULL);

    ShowCategory165Screen_ext(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        0,
        0,
        get_string(string_id),
        IMG_GLOBAL_WARNING,
        10,
        guiBuffer);

    SetCat165TimerExpireFunc(mmi_bootup_exit_disk_check);

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
    ShowCategory301Screen((PU8) GetString(string_id), 0, NULL);
#endif /* __MMI_SUBLCD_SHOW_ANALOG_CLOCK__ */ 

    /* No history to go back */
    /* Always enter normal mode unless the flight mode is selected by pressing LSK (Yes) */
    SetKeyHandler(mmi_bootup_exit_disk_check, KEY_END, KEY_EVENT_DOWN);

    SetLeftSoftkeyFunction(mmi_bootup_exit_disk_check, KEY_EVENT_UP);
}


static int recover_device_type;
/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_start_to_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bootup_start_to_format(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);
    ShowCategory66Screen(
        STR_FMGR_TITLE,
        GetRootTitleIcon(MAIN_MENU_FILE_MNGR_MENUID),
        0,
        0,
        0,
        0,
        (PU8) GetString(STR_FMGR_FORMATING),
        IMG_GLOBAL_PROGRESS,
        NULL);

    FS_RecoverDevice(recover_device_type);
    AlmATPowerReset(0, 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_disk_check_entry_format_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  string_id       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_disk_check_entry_format_screen(U16 string_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_DISK_CHECK;

    guiBuffer = GetCurrGuiBuffer(SCR_BOOTUP_CHECK_DISK);

    EntryNewScreen(SCR_BOOTUP_CHECK_DISK, NULL, NULL, NULL);

    ShowCategory165Screen_ext(
        STR_GLOBAL_YES,
        0,
        STR_GLOBAL_NO,
        0,
        get_string(string_id),
        0,//IMG_GLOBAL_QUESTION,
        5,
        guiBuffer);

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
    ShowCategory301Screen((PU8) GetString(string_id), 0, NULL);
#endif /* __MMI_SUBLCD_SHOW_ANALOG_CLOCK__ */ 

    /* No history to go back */
    /* Always enter normal mode unless the flight mode is selected by pressing LSK (Yes) */
    SetLeftSoftkeyFunction(mmi_bootup_start_to_format, KEY_EVENT_UP);
    SetKeyHandler(mmi_bootup_start_to_format, KEY_SEND, KEY_EVENT_DOWN);
    SetCat165TimerExpireFunc(mmi_bootup_start_to_format);

    if (string_id == STR_ID_NAND_USER_DRIVE_CORRUPT)
    {
        SetRightSoftkeyFunction(mmi_bootup_exit_disk_check, KEY_EVENT_UP);
        SetKeyHandler(mmi_bootup_exit_disk_check, KEY_END, KEY_EVENT_DOWN);
    }
    else if (string_id == STR_ID_NAND_SYSTEM_DRIVE_CORRUPT)
    {
       SetRightSoftkeyFunction(QuitSystemOperation, KEY_EVENT_UP);
       SetKeyHandler(QuitSystemOperation, KEY_END, KEY_EVENT_DOWN);
    }
    else
    {
        MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_disk_check_entry_version_mismatch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_disk_check_entry_version_mismatch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    guiBuffer = GetCurrGuiBuffer(SCR_BOOTUP_CHECK_DISK);

    EntryNewScreen(SCR_BOOTUP_CHECK_DISK, NULL, NULL, NULL);

    ShowCategory165Screen_ext(
        STR_GLOBAL_OK,
        0,
        0,
        0,
        get_string(STR_ID_NAND_VERSION_MISMATCH),
        IMG_GLOBAL_WARNING,
        5,
        guiBuffer);

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
    ShowCategory301Screen((PU8) GetString(STR_ID_NAND_VERSION_MISMATCH), 0, NULL);
#endif /* __MMI_SUBLCD_SHOW_ANALOG_CLOCK__ */ 

#if defined (_NAND_FLASH_BOOTING_) || defined(__FS_SYSDRV_ON_NAND__)
    SetCat165TimerExpireFunc(QuitSystemOperation);
    SetKeyHandler(QuitSystemOperation, KEY_END, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(QuitSystemOperation, KEY_EVENT_UP);
#else /* defined (_NAND_FLASH_BOOTING_) || defined(__FS_SYSDRV_ON_NAND__) */
    SetCat165TimerExpireFunc(mmi_bootup_exit_disk_check);
    SetKeyHandler(mmi_bootup_exit_disk_check, KEY_END, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_bootup_exit_disk_check, KEY_EVENT_UP);
#endif /* defined (_NAND_FLASH_BOOTING_) || defined(__FS_SYSDRV_ON_NAND__) */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_stop_countdown_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bootup_stop_countdown_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
#endif
    if (ExitCategoryFunction != NULL)
    {
        ExitCategoryFunction();
    }
}


/* diamond, 2005/09/12 new bootup screen flows */

extern void FlightModeCheckBeforeAnimation(void);
extern void mmi_pwron_entry_animation_screen(void);
extern void PowerOnBatteryIndicationComplete(void);
extern void mmi_pwron_stop_animation(void);
extern void mmi_ready_to_idle_screen_ind(void);
extern void EntryIdleScreen(void);
extern void BatteryCheckAfterPowerOnAnimation(void);

/* mmi_bootup_entry_disk_check          -> mmi_bootup_exit_disk_check          -> */
/* mmi_bootup_entry_flight_mode_query   -> mmi_bootup_exit_flight_mode_query   -> */
/* mmi_bootup_entry_animation           -> mmi_bootup_exit_animation           -> */
/* mmi_bootup_entry_low_battery_warning -> mmi_bootup_exit_low_battery_warning -> */
/* mmi_bootup_entry_nand_check_query    -> mmi_bootup_exit_nand_check_query    -> */
/* mmi_bootup_entry_security_check      -> mmi_bootup_exit_security_check      -> */
/* mmi_bootup_entry_welcome_screen      -> mmi_bootup_exit_welcome_screen      -> */
/* mmi_bootup_entry_aphorism_screen     -> mmi_bootup_exit_aphorism_screen     -> */
/* mmi_bootup_entry_network_searching   -> mmi_bootup_exit_network_searching   -> */
/* mmi_bootup_entry_idle_screen                                                   */


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_entry_disk_check
 * DESCRIPTION
 *  Bootup screen flow control
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bootup_entry_disk_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 result = FS_SanityCheck();
    S32 fh;
    WCHAR DriveName[5] = L"X:\\";

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == FS_NO_ERROR)
    {
        /* quota is okay */
        DriveName[0] = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_ONLY_ALT_SERIAL);
        fh = FS_Open(DriveName, FS_READ_ONLY | FS_OPEN_DIR);

        if (fh >= 0)
        {
        	g_pwr_context.NandIdCheckRes = 1;
            FS_Close(fh);
            mmi_bootup_exit_disk_check();
        }
        else if (fh == FS_FDM_USER_DRIVE_BROKEN)
        {
            mmi_frm_power_on_init_procedure();
            PhnsetFlightModeQueryBackground();
            recover_device_type = FS_GetDevType(DriveName);
            mmi_disk_check_entry_format_screen(STR_ID_NAND_USER_DRIVE_CORRUPT);
        }
        else if (result == FS_FDM_VERSION_MISMATCH)
        {
            mmi_frm_power_on_init_procedure();
            PhnsetFlightModeQueryBackground();
            mmi_disk_check_entry_version_mismatch();
        }
        else if (fh == FS_NAND_DEVICE_NOT_SUPPORTED) /* -122 */
        {
            mmi_frm_power_on_init_procedure();
            PhnsetFlightModeQueryBackground();
            mmi_disk_check_entry_warning_screen(STR_ID_NAND_DEVICE_NOT_SUPPORTED);
        }
        else
        {
            mmi_bootup_exit_disk_check();
        }
    }
    else if (result == FS_FDM_SYS_DRIVE_BROKEN || result == FS_FDM_MULTIPLE_BROKEN || result == FS_FDM_USER_DRIVE_BROKEN)
    {
        mmi_frm_power_on_init_procedure();
        PhnsetFlightModeQueryBackground();
        recover_device_type = FS_GetDevType(L"Z:\\");
        mmi_disk_check_entry_format_screen(STR_ID_NAND_SYSTEM_DRIVE_CORRUPT);
    }
    else if (result == FS_FDM_VERSION_MISMATCH)
    {
        mmi_frm_power_on_init_procedure();
        PhnsetFlightModeQueryBackground();
        mmi_disk_check_entry_version_mismatch();
    }
    else if (result == FS_QUOTA_OVER_DISK_SPACE)
    {
        /* quota setting is wrong or unreasonable */
        /* for example: qmax entry is larger than disk space -or- sum of qmin is larger than disk space */
        mmi_frm_power_on_init_procedure();
        PhnsetFlightModeQueryBackground();
        mmi_disk_check_entry_warning_screen(STR_ID_NAND_QUOTA_OVER_DISK);
    }
    else if (result == FS_QUOTA_USAGE_WARNING)
    {
        /* quota usage abnormal, application may fail to write data on system drive */
        /* for example: total application minial reserse space 70 , total application current usage 50, but current free space is less than 20, even after sweep */
        mmi_frm_power_on_init_procedure();
        PhnsetFlightModeQueryBackground();
        mmi_disk_check_entry_warning_screen(STR_ID_NAND_QUOTA_USAGE_WARNING);
    }
    else
    {
        mmi_bootup_exit_disk_check();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_exit_disk_check
 * DESCRIPTION
 *  Bootup screen flow control
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bootup_exit_disk_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bootup_stop_countdown_screen();
    ClearInputEventHandler(MMI_DEVICE_ALL); /* prevent user press key after leave the screen */

    mmi_frm_power_on_set_mode();
    mmi_frm_power_on_init_procedure();
    mmi_bootup_entry_flight_mode_query();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_entry_flight_mode_query
 * DESCRIPTION
 *  Bootup screen flow control
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bootup_entry_flight_mode_query(void)
{
    FlightModeCheckBeforeAnimation();   /* check if it is necessary to enter flight mode query screen */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_exit_flight_mode_query
 * DESCRIPTION
 *  Bootup screen flow control
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bootup_exit_flight_mode_query(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* add callbacks here after flight mode query complete */

    /* re-direct the bootup flow to next screen */
    mmi_bootup_entry_animation();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_entry_animation
 * DESCRIPTION
 *  Bootup screen flow control
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bootup_entry_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_pwron_entry_animation_screen(); /*  to display power on animation */

    DeleteScreenIfPresent(SCR_BOOTUP_CHECK_DISK);
    DeleteScreenIfPresent(SCR_FLIGHT_MODE_QUERY);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_exit_animation
 * DESCRIPTION
 *  Bootup screen flow control
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bootup_exit_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* add callbacks here after flight mode query complete */

    /* re-direct the bootup flow to next screen */
    mmi_bootup_entry_low_battery_warning();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_entry_low_battery_warning
 * DESCRIPTION
 *  Bootup screen flow control
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bootup_entry_low_battery_warning(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // CallBackPowerOnAnimationComplete();  /* low power shutdown or low battery warning */
    BatteryCheckAfterPowerOnAnimation();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_exit_low_battery_warning
 * DESCRIPTION
 *  Bootup screen flow control
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bootup_exit_low_battery_warning(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* add callbacks here after flight mode query complete */

    /* re-direct the bootup flow to next screen */
    mmi_bootup_entry_nand_check_query();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_entry_nand_check_query
 * DESCRIPTION
 *  Bootup screen flow control
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bootup_entry_nand_check_query(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PowerOnBatteryIndicationComplete(); /* NAND check or not */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_exit_nand_check_query
 * DESCRIPTION
 *  Bootup screen flow control
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bootup_exit_nand_check_query(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* add callbacks here after flight mode query complete */

    /* re-direct the bootup flow to next screen */
    mmi_bootup_entry_security_check();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_entry_security_check
 * DESCRIPTION
 *  Bootup screen flow control
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bootup_entry_security_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PowerOnBatteryIndicationCompletePhase2();   /* password indication or SIM failure indication */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_exit_security_check
 * DESCRIPTION
 *  Bootup screen flow control
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bootup_exit_security_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
    extern U16 simErrorDisplayString;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* add callbacks here after flight mode query complete */

    /* re-direct the bootup flow to next screen */
#ifndef __MMI_DUAL_SIM_MASTER__
    mmi_bootup_entry_welcome_screen();  /* send message to it slef notify ready to go to idle */
#else /* __MMI_DUAL_SIM_MASTER__ */
    if (MTPNP_AD_Slave_Is_Plugged() && MTPNP_PFAL_Is_Popup_Card_Removed())
	{
        simErrorDisplayString = STR_SIM_INSERTION_MSG;
        InitSimErrorScreen();
	}
	else
	{
	    mmi_bootup_entry_welcome_screen();   /* send message to it slef notify ready to go to idle */
	}
#endif /* __MMI_DUAL_SIM_MASTER__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_entry_welcome_screen
 * DESCRIPTION
 *  Bootup screen flow control
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bootup_entry_welcome_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ready_to_idle_screen_ind();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_exit_welcome_screen
 * DESCRIPTION
 *  Bootup screen flow control
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bootup_exit_welcome_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* add callbacks here after flight mode query complete */

    /* re-direct the bootup flow to next screen */
#ifdef __MMI_APHORISM__
/* under construction !*/
#else 
    mmi_bootup_entry_network_searching();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_entry_aphorism_screen
 * DESCRIPTION
 *  Bootup screen flow control
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bootup_entry_aphorism_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_APHORISM__
/* under construction !*/
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_exit_aphorism_screen
 * DESCRIPTION
 *  Bootup screen flow control
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bootup_exit_aphorism_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* add callbacks here after flight mode query complete */

    /* re-direct the bootup flow to next screen */
    mmi_bootup_entry_network_searching();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_entry_network_searching
 * DESCRIPTION
 *  Bootup screen flow control
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bootup_entry_network_searching(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    BeforeEntryIdleScr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_exit_network_searching
 * DESCRIPTION
 *  Bootup screen flow control
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bootup_exit_network_searching(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* add callbacks here after flight mode query complete */

    /* re-direct the bootup flow to next screen */
    mmi_bootup_entry_idle_screen(); /* from SearchingSrceenTimeOutHandler() or NetWorkAttachedIndication() */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_entry_idle_screen
 * DESCRIPTION
 *  Bootup screen flow control
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bootup_entry_idle_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryIdleScreen();
}


#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_is_sim_valid
 * DESCRIPTION
 *  Check SIM card is valid or not (with MSG_ID_SIM_CARD_FAILURE)
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_bootup_is_sim2_valid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* replace g_pwr_context.IsSimValid */
    if (g_pwr_context_2.PowerOnSIMStatus & MMI_SIM_STATUS_INVALID)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_is_sim2_removed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_bootup_is_sim2_removed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* replace g_pwr_context.SimRemovedFlag */
    if (g_pwr_context_2.PowerOnSIMStatus & MMI_SIM_STATUS_NOT_INSERT)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_is_sim2_refresh
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_bootup_is_sim2_refresh(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* gSIMRefresh */
    if (g_pwr_context_2.PowerOnSIMStatus & MMI_SIM_STATUS_REFRESH)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_is_sim2_roaming
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_bootup_is_sim2_roaming(void)
{
    return 0;
}


pBOOL mmi_bootup_is_in_sim2_security_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pwr_context_2.PowerOnMMIStatus & MMI_POWER_ON_SECURITY_NO_PSWD)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

pBOOL mmi_bootup_is_sim2_power_on_animation_complete(void)
{
    if (g_pwr_context_2.PowerOnMMIStatus >= MMI_POWER_ON_LOW_BATTERY)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

pBOOL mmi_bootup_is_sim2_searching_or_idle_reached(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* replace g_pwr_context.idleScreenFirst */
    if (g_pwr_context_2.PowerOnMMIStatus >= MMI_POWER_ON_NW_SEARCHING)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


pBOOL mmi_bootup_is_sim2_network_searching_complete(void)
{
    if (g_pwr_context_2.PowerOnNWStatus & MMI_NW_STATUS_NETWORK_FLAG)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

pBOOL mmi_bootup_is_sim2_nw_registration_ok(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* replace g_pwr_context.InvalidSim */
    if (g_pwr_context_2.PowerOnNWStatus & MMI_NW_STATUS_REG_FAILED)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}

void mmi_bootup_update_sim1_status(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_sim_status_update_ind_struct *local_data = (mmi_smu_sim_status_update_ind_struct*) info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (local_data->is_sim_inserted)
    {
        MTPNP_AD_Set_Card1Status(MTPNP_AD_SIMCARD_INVALID);
    }
    else
    {
        MTPNP_AD_Set_Card1Status(MTPNP_AD_SIMCARD_ABSENT);
    }
}


void mmi_bootup_update_sim2_status(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_sim_status_update_ind_struct *local_data = (mmi_smu_sim_status_update_ind_struct*) info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (local_data->is_sim_inserted)
    {
        MTPNP_AD_Set_Card2Status(MTPNP_AD_SIMCARD_INVALID);
        if (MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_DUALCARD)
        {
            power_on_mode_finish = MMI_FALSE;
        }
    }
    else
    {
        MTPNP_AD_Set_Card2Status(MTPNP_AD_SIMCARD_ABSENT);
    }
}


pBOOL mmi_bootup_is_power_on_mode_change_finish(void)
{
    return power_on_mode_finish;
}


void mmi_bootup_power_on_sim1_flight_mode(void) /* case 11 */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static MMI_BOOL sim1_activated = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim1_activated)
    {
        return;
    }

    if (g_pwr_context.IsRacActivated)
    {
        MTPNP_PFAL_Master_Startup_Flightmode();
        MTPNP_AD_Set_Card1RFStatus(MTPNP_AD_RF_POWEROFF);
        MTPNP_AD_Bootup_Completed();
        sim1_activated = MMI_TRUE;
        gSignalStrengthLevel = 0;
        ChangeStatusIconLevel(STATUS_ICON_SIGNAL_STRENGTH, gSignalStrengthLevel);
        UpdateStatusIcons();
    }
    else
    {
        StartTimer(RAC_ACTIVATION_TIMER, 1500, mmi_bootup_power_on_sim1_flight_mode);
    }
}


void mmi_bootup_power_on_sim2_normal_mode(void) /* case 11, 12 */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static MMI_BOOL sim2_activated = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim2_activated)
    {
        return;
    }

    if (g_pwr_context_2.IsRacActivated)
    {
        U8 mode;
        mode = MTPNP_SLAVE_STARTUP_NORMAL;
        MTPNP_CB_startup_req(&mode);
        sim2_activated = MMI_TRUE;
        SetSlaveProtocolEventHandler(mmi_bootup_power_on_sim2_normal_mode_rsp, PRT_NW_CFUN_STATE_RSP);
    }
    else
    {
        StartTimer(RAC_ACTIVATION_TIMER, 1500, mmi_bootup_power_on_sim2_normal_mode);
    }
}


void mmi_bootup_rac1_activated_indication(void *info)
{
    g_pwr_context.IsRacActivated = 1;
}


void mmi_bootup_rac2_activated_indication(void *info)
{
    g_pwr_context_2.IsRacActivated = 1;
}


void mmi_bootup_dual_sim_power_on(void)
{
    if (MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_DUALCARD &&
        MTPNP_AD_Get_Card1Status() != MTPNP_AD_SIMCARD_ABSENT &&
        MTPNP_AD_Get_Card2Status() != MTPNP_AD_SIMCARD_ABSENT)
    {
        if (sim2_status_finish) 
        {
            mmi_bootup_power_on_sim2_normal_mode();
        }
        else
        {
            StartTimer(DUAL_SIM_ON_TIMER, 1500, mmi_bootup_dual_sim_power_on);
        }
    }
}


void mmi_bootup_network_search_finish_ind(void *info)
{
    mmi_bootup_dual_sim_power_on();
}


void mmi_bootup_power_on_sim1_flight_mode_rsp(void *info)
{
    mmi_bootup_power_on_sim2_normal_mode();
    ClearProtocolEventHandler(PRT_NW_CFUN_STATE_RSP);
}


void mmi_bootup_power_on_sim2_normal_mode_rsp(void *info)
{
    power_on_mode_finish = MMI_TRUE;
    ClearSlaveProtocolEventHandler(PRT_NW_CFUN_STATE_RSP);
}


void mmi_bootup_set_sim_block_string(void)
{
    extern U16 simErrorDisplayString;
    simErrorDisplayString = STR_SIM_BLOCK_MSG;
}


MMI_BOOL mmi_bootup_is_sim1_no_passeord_required(void)
{
    return (g_pwr_context.PowerOnMMIStatus == MMI_POWER_ON_SECURITY_NO_PSWD);
}


#endif /* __MMI_DUAL_SIM_SINGLE_CALL__ */

