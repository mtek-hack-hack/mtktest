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
 *  NetworkFunctions.c
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
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/


#include "MMI_include.h"

#include "MiscFunctions.h"
#include "ProtocolEvents.h"
#include "SimDetectionGprot.h"
#include "SimDetectionDef.h"
#include "SimDetectionGexdcl.h"

#include "ProtocolEvents.h"
#include "UCS2prot.h"
#include "TaskInit.h"
#include "wgui_status_icons.h"
#include "IdleAppDef.h"
#include "ProfileGprots.h"
#include "gpioInc.h"
#include "bootup.h"
#include "IdleAppProt.h"
#include "SimDetectionHwMapFile.h"
#include "NetworkSetupGProt.h"
#include "NetworkSetupDefs.h"
#include "CustResDef.h"
#include "SettingDefs.h"
#include "SettingsGdcl.h"
#include "PhoneSetupGprots.h"
#include "CallManagementGprot.h"
#include "RightsMgrGProt.h"
#include "EONSGProt.h"

#ifdef _NETWORK_CIPHER_SUPPORT_
#include "mm_mmi_enums.h"
#endif 

#ifdef __MMI_IMPS__
#include "mmi_imps_gprot.h"
#endif 

#ifdef __MMI_POC__
#include "PoCGProt.h"
#endif 

#ifdef __HOMEZONE_SUPPORT__
#include "GSM7BitDefaultAlphabet.h"
#endif 

#ifdef WAP_SUPPORT
#include "wap_ps_struct.h"
#include "wapadp.h"
#endif /* WAP_SUPPORT */

#ifdef __MMI_DUAL_SIM_MASTER__
#include "UCMGprot.h"
#include "MTPNP_AD_master_header.h"
#endif

#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
#include "MTPNP_AD_slave_header.h"
#include "MTPNP_PFAL_Gemini_Network.h"
void MTPNP_PFAL_QOS_Indication(void *inMsg);
void MTPNP_PFAL_NW_Attach_Indication(void *inMag);
#endif

#ifdef __MMI_DUAL_SIM_DUAL_CALL_SLAVE__
#include "MTPNP_AD_slave_header.h"
#include "MTPNP_PFAL_Slave_Network.h"
#endif  /* __MMI_DUAL_SIM_DUAL_CALL_SLAVE__ */

static U8 m_edge_status = 0, m_edge_last_status;
static void mmi_netset_set_edge_status(U8 edge_state);

extern void refresh_status_icon_display(void);  /* in Wgui_status_icons.c */
extern void BatteryStatusRsp(void *);           /* in PwronCharger.c */

#ifdef MMS_SUPPORT
extern void wap_plmn_number_indication_callback(const U8 *curPLMN);
#endif

#ifdef SYNCML_DM_SUPPORT
extern void dm_notify_network_status(kal_bool network_status);
#endif


extern S8 gHomePLMNNum[MAX_PLMN_LEN_MMI + 1];

U8 gGPRSStatusModified = 0;
U8 gSignalStrengthLevel = 0;

U8 gNWProviderName[MAX_LENGTH_DISPLAY_NAME * ENCODING_LENGTH];
U8 gPLMN[MAX_PLMN_LEN_MMI + 1];

#ifdef __MMI_EONS_SUPPORT__
U8 gLAC[2];
#endif

U8 lastNwStatus = MMI_RAC_LIMITED_SERVICE;
U8 lastPLMN[MAX_PLMN_LEN_MMI + 1];

#ifdef __HOMEZONE_SUPPORT__
U8 *gHomezoneText = NULL;
#endif 

#if defined(__MMI_DUAL_SIM_SINGLE_CALL__)
extern U8 gPLMN_2[MAX_PLMN_LEN_MMI + 1];
#endif


/*****************************************************************************
 * FUNCTION
 *  InitNetWorkBootUpEventsCallBack
 * DESCRIPTION
 *  This function initializes all network related protocol handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitNetWorkBootUpEventsCallBack(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_DUAL_SIM_DUAL_CALL_SLAVE__
    SetProtocolEventHandler(NetWorkAttachedIndication, PRT_NW_ATTACH_IND);
    SetProtocolEventHandler(NetWorkSignalLevelIndication, PRT_NW_RX_LEVEL_IND);
    SetProtocolEventHandler(NumberOfPLMNSuported, PRT_PLMN_LIST_IND);
#ifdef _NETWORK_CIPHER_SUPPORT_
    SetProtocolEventHandler(NetWorkCipherIndication, PRT_MMI_SMU_CIPHER_IND);
#endif
#ifdef __MANUAL_MODE_NW_SEL__
    SetProtocolEventHandler(PLMNSelectionModeIndication, MSG_ID_MMI_NW_SEL_MODE_IND);
#endif
#ifdef __MMI_GPRS_FEATURES__
    SetProtocolEventHandler(GPRSStatusUpdateIndication, PRT_MMI_PS_GPRS_STATUS_UPDATE_IND);
#endif 
#endif /* __MMI_DUAL_SIM_DUAL_CALL_SLAVE__ */

    SetProtocolEventHandler(NetWorkServiceTypeIndication, PRT_SERVICE_TYPE_IND);
    SetProtocolEventHandler(RspToTestRoamingEnabled, PRT_GET_IMSI_RSP);
    SetProtocolEventHandler(BatteryStatusRsp, PRT_BATTERY_STATUS_IND);  /* not in this file */
 
#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
    SetSlaveProtocolEventHandler(MTPNP_PFAL_NW_Attach_Indication, PRT_NW_ATTACH_IND);
    SetSlaveProtocolEventHandler(MTPNP_PFAL_QOS_Indication, PRT_NW_RX_LEVEL_IND);
    SetSlaveProtocolEventHandler(MTPNP_PFAL_NumberOfPLMNSuported, PRT_PLMN_LIST_IND);
#ifdef _NETWORK_CIPHER_SUPPORT_
    SetSlaveProtocolEventHandler(MTPNP_PFAL_NW_Cipher_Indication, PRT_MMI_SMU_CIPHER_IND);
#endif
#ifdef __MANUAL_MODE_NW_SEL__
    SetSlaveProtocolEventHandler(MTPNP_PFAL_PLMN_Selection_Mode_Indication, MSG_ID_MMI_NW_SEL_MODE_IND);
#endif
#ifdef __MMI_GPRS_FEATURES__
    SetSlaveProtocolEventHandler(MTPNP_PFAL_GPRS_Status_Update_Indication, PRT_MMI_PS_GPRS_STATUS_UPDATE_IND);
#endif 
    SetProtocolEventHandler(mmi_bootup_rac1_activated_indication, MSG_ID_MMI_NW_RAC_ACTIVATED_IND);
    SetSlaveProtocolEventHandler(mmi_bootup_rac2_activated_indication, MSG_ID_MMI_NW_RAC_ACTIVATED_IND);
    if (MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_DUALCARD)
    {
        SetProtocolEventHandler(mmi_bootup_network_search_finish_ind, MSG_ID_MMI_NW_SEARCH_NORMAL_FINISH_IND);
    }
#endif /* defined(__MMI_DUAL_SIM_DUAL_CALL_SLAVE__) || defined (__MMI_DUAL_SIM_SINGLE_CALL__) */

#ifdef __MMI_DUAL_SIM_DUAL_CALL_SLAVE__
    SetProtocolEventHandler(MTPNP_PFAL_NW_Attach_Indication, PRT_NW_ATTACH_IND);
    SetProtocolEventHandler(MTPNP_PFAL_QOS_Indication, PRT_NW_RX_LEVEL_IND);
    SetProtocolEventHandler(MTPNP_PFAL_NumberOfPLMNSuported, PRT_PLMN_LIST_IND);
#ifdef _NETWORK_CIPHER_SUPPORT_
    SetProtocolEventHandler(MTPNP_PFAL_NW_Cipher_Indication, PRT_MMI_SMU_CIPHER_IND); /* need implementation */
#endif
#ifdef __MANUAL_MODE_NW_SEL__
    SetProtocolEventHandler(MTPNP_PFAL_PLMN_Selection_Mode_Indication, MSG_ID_MMI_NW_SEL_MODE_IND);
#endif
#ifdef __MMI_GPRS_FEATURES__
    SetProtocolEventHandler(MTPNP_PFAL_GPRS_Status_Update_Indication, PRT_MMI_PS_GPRS_STATUS_UPDATE_IND);
#endif 
#endif /* __MMI_DUAL_SIM_DUAL_CALL_SLAVE__ */

#ifdef __HOMEZONE_SUPPORT__
    SetProtocolEventHandler(HomezoneStatusIndication, PRT_MMI_HZ_TAG_IND);
#endif 

    memset(gPLMN, 0, MAX_PLMN_LEN_MMI + 1);
#if defined(__MMI_DUAL_SIM_SINGLE_CALL__)
    memset(gPLMN_2, 0, MAX_PLMN_LEN_MMI + 1);
#endif
}

/**************************************************************************
         API of Network Attachment
**************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  NetWorkAttachedIndication
 * DESCRIPTION
 *  This function is a call back for MSG_ID_MMI_NW_ATTACH_IND
 * PARAMETERS
 *  inMsg       [?]     
 *  void*(?)
 * RETURNS
 *  void
 *****************************************************************************/
void NetworkErrorHandle(void);
void RefreshNwProviderName(U8 *UpdatePlmn);

void NetWorkAttachedIndication(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 plmn_prompt[30]; /* Value is hardcoded as temporarly used */
    S8 current_oper[MAX_PLMN_LEN_MMI + 1];

    MMINWATTACHIND *local_data = (mmi_nw_attach_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("MSG_ID_MMI_NW_ATTACH_INDICATION");

    if (local_data->status == MMI_RAC_SEARCHING)
    {
        return; /* do nothing because L4 is searching network */
    }

#ifdef __MMI_SIMAP_SUPPORT__
    if (mmi_bootup_get_active_bt_access_profile_mode() == MMI_TRUE && local_data->status == MMI_RAC_OK)
    {
        return; /* ignore normal service indication in SAP mode */
    }
#endif /* __MMI_SIMAP_SUPPORT__ */

    /* micha0120 */
    mmi_netset_set_edge_status(local_data->cell_support_egprs);
    UpdateGPRSStatusIcon(local_data->gprs_status);

    /* micha0317 */
    if (mmi_ucs2cmp((PS8) gNWProviderName, (PS8) GetString(STR_ID_NETSET_SEARCHIN_NW)) == 0 ||
        local_data->status != lastNwStatus || memcmp(local_data->plmn, lastPLMN, MAX_PLMN_LEN_MMI))
    {
        gGPRSStatusModified = 1;
    }

    /* diamond, 2006/06/01 Not reset gNWProviderName here to prevent from unable to get EONS PNN file */
#ifdef __MMI_EONS_SUPPORT__
    if (mmi_eons_check_if_plmn_present(gPLMN, gLAC) == 0)
#endif 
        memset(gNWProviderName, 0, MAX_LENGTH_DISPLAY_NAME * ENCODING_LENGTH);

#ifdef __MMI_EONS_SUPPORT__
    if (local_data->status == MMI_RAC_OK)
    {
        memcpy(&gLAC[0], &local_data->lac[0], 2);
    }
    else
    {
        memset(&gLAC[0], 0xFF, 2);
    }
#endif /* __MMI_EONS_SUPPORT__ */

    switch (local_data->status) /* l4c_rac_response_enum */
    {
        case MMI_RAC_OK:    /* normal service */

            /* Required for othe applications to indicate them full service */
            g_pwr_context.CurrentServiceType = FULL_SERVICE;

        #ifdef __MMI_DUAL_SIM_MASTER__
            /* set the network to full service */
            MTPNP_AD_Set_Card1ServiceType(MTPNP_AD_FULL_SERVICE);
        #endif

            ChangeStatusIconLevel(STATUS_ICON_SIGNAL_STRENGTH, gSignalStrengthLevel);
            ChangeStatusIconLevel(STATUS_ICON_SUBLCD_SIGNAL_STRENGTH, gSignalStrengthLevel);

            /* Stop searching screen */
            /* g_pwr_context.NetWorkFlag = 1; */
            g_pwr_context.PowerOnNWStatus |= MMI_NW_STATUS_NETWORK_FLAG;        /* 0x01: receive network attachment */

            memset(current_oper, '\0', sizeof(current_oper));
            memcpy(current_oper, local_data->plmn, MAX_PLMN_LEN_MMI);
            sprintf(plmn_prompt, "PLMN %s", current_oper);
            PRINT_INFORMATION(plmn_prompt);

            /* Copy plmn to global variable to be checked later for displaying roaming signals */
            /* memcpy(gPLMN,local_data->plmn,MAX_PLMN_LEN_MMI); */
            strcpy((S8*) gPLMN, (S8*) local_data->plmn);    /* local_data->plmn is a null-terminated string */
            RefreshNwProviderName(gPLMN);

            /* Send message to check Roaming enabled or not signal */
            if (g_pwr_context.testRoaming == 3) /* Robin 1202, means already get IMSI */
            {
                /* diamond, 2005/09/26 support PNN and OPL */
            #ifdef __MMI_EONS_SUPPORT__
                if (mmi_eons_check_if_plmn_present(gPLMN, gLAC) == 0)
            #endif 
                    ChangeRoamingState();
            }
            else if (g_pwr_context.testRoaming == 1)    /* No body send get IMSI req */
            {
                RequestToTestRoamingEnabled();
            }

            /* Update last network information */
            lastNwStatus = MMI_RAC_OK;
            /* memcpy(lastPLMN, gPLMN, MAX_PLMN_LEN_MMI); */
            strcpy((S8*) lastPLMN, (S8*) gPLMN);

        #if defined(__GSM_RAT__) && defined(__WCDMA_RAT__) && !defined(__MMI_DUAL_MODE_SELF_TEST__)
/* under construction !*/
        #endif

        #ifdef __MMI_IMPS__
            mmi_imps_notify_rac_ready();
        #endif 

        #ifdef SYNCML_DM_SUPPORT
            dm_notify_network_status(1);
        #endif /* SYNCML_DM_SUPPORT */ 

        #ifdef __MMI_POC__
            if (mmi_bootup_is_idle_screen_reached() == MMI_TRUE)
            {
                mmi_poc_poweron_reg();
            }
        #endif /* __MMI_POC__ */ 
            break;

        case MMI_RAC_NO_CELL:   /* no service */

            /* Required for othe applications to indicate them no service */
            g_pwr_context.CurrentServiceType = NO_SERVICE;

        #ifdef __MMI_DUAL_SIM_MASTER__
            /* set the network to no service */
            MTPNP_AD_Set_Card1ServiceType(MTPNP_AD_NO_SERVICE);
        #endif

            PRINT_INFORMATION("No Service");

            IdleResetStatusIcon(STATUS_ICON_ROAMING);
            IdleRefreshServiceIndicationArea();

            /* if(g_pwr_context.idleScreenFirst ) //1211 */
            if (mmi_bootup_is_searching_or_idle_reached() == MMI_TRUE)
            {
                StopLEDPatternNoService();  /* MTK add Robin 1009. Stop LED will trigger the Band led pattern resume mechanism */
            }

            /* Reset the signal level to zero */
            ChangeStatusIconLevel(STATUS_ICON_SIGNAL_STRENGTH, 0);
            ChangeStatusIconLevel(STATUS_ICON_SUBLCD_SIGNAL_STRENGTH, 0);

            lastNwStatus = MMI_RAC_NO_CELL;

        #if defined(__GSM_RAT__) && defined(__WCDMA_RAT__) && !defined(__MMI_DUAL_MODE_SELF_TEST__)
/* under construction !*/
        #endif

            if (mmi_idle_is_on_idle_screen() && mmi_bootup_is_idle_screen_reached())
            {
                IdleSetLRKey();
            }

        #ifdef SYNCML_DM_SUPPORT
            dm_notify_network_status(0);
        #endif /* SYNCML_DM_SUPPORT */ 
            break;

        case MMI_RAC_LIMITED_SERVICE:   /* limit service */

            /* Required for othe applications to indicate them no service */
            g_pwr_context.CurrentServiceType = LIMITED_SERVICE;

        #ifdef __MMI_DUAL_SIM_MASTER__
            /* set the network to limit service */
            MTPNP_AD_Set_Card1ServiceType(MTPNP_AD_LIMITED_SERVICE);
        #endif

            ChangeStatusIconLevel(STATUS_ICON_SIGNAL_STRENGTH, gSignalStrengthLevel);
            ChangeStatusIconLevel(STATUS_ICON_SUBLCD_SIGNAL_STRENGTH, gSignalStrengthLevel);

            PRINT_INFORMATION("Limited Service");

            IdleResetStatusIcon(STATUS_ICON_ROAMING);
            IdleRefreshServiceIndicationArea();

            /* if(g_pwr_context.idleScreenFirst ) //Robin 1211 */
            if (mmi_bootup_is_searching_or_idle_reached() == MMI_TRUE)
            {
                StopLEDPatternLimitService();   /* MTK add Robin 1009. Stop LED will trigger the Band led pattern resume mechanism */
            }

            lastNwStatus = MMI_RAC_LIMITED_SERVICE;

        #if defined(__GSM_RAT__) && defined(__WCDMA_RAT__) && !defined(__MMI_DUAL_MODE_SELF_TEST__)
/* under construction !*/
        #endif

            if (mmi_idle_is_on_idle_screen() && mmi_bootup_is_idle_screen_reached())
            {
                IdleSetLRKey();
            }

        #ifdef SYNCML_DM_SUPPORT
            dm_notify_network_status(0);
        #endif /* SYNCML_DM_SUPPORT */ 
            break;

        case MMI_RAC_ATTEMPT_TO_UPDATE:

            g_pwr_context.CurrentServiceType = LIMITED_SERVICE;
			
        #ifdef __MMI_DUAL_SIM_MASTER__
            /* set the network to limit service */
            MTPNP_AD_Set_Card1ServiceType(MTPNP_AD_LIMITED_SERVICE);
        #endif

            IdleResetStatusIcon(STATUS_ICON_ROAMING);

            PRINT_INFORMATION("Limited Service");

            IdleRefreshServiceIndicationArea();

            /* if( g_pwr_context.idleScreenFirst ) //Robin 1211 */
            if (mmi_bootup_is_searching_or_idle_reached() == MMI_TRUE)
            {
                StopLEDPatternLimitService();   /* MTK add Robin 1009. Stop LED will trigger the Band led pattern resume mechanism */
            }

            lastNwStatus = MMI_RAC_ATTEMPT_TO_UPDATE;

        #if defined(__GSM_RAT__) && defined(__WCDMA_RAT__) && !defined(__MMI_DUAL_MODE_SELF_TEST__)
/* under construction !*/
        #endif

            if (mmi_idle_is_on_idle_screen() && mmi_bootup_is_idle_screen_reached())
            {
                IdleSetLRKey();
            }

            break;

        case MMI_RAC_INVALID_SIM:

            /* g_pwr_context.InvalidSim = 1; */
            g_pwr_context.PowerOnNWStatus |= MMI_NW_STATUS_REG_FAILED;  /* network registration failed */
            g_pwr_context.CurrentServiceType = LIMITED_SERVICE;

        #ifdef __MMI_DUAL_SIM_MASTER__
            /* set the network to limit service */
            MTPNP_AD_Set_Card1ServiceType(MTPNP_AD_LIMITED_SERVICE);
        #endif

            PRINT_INFORMATION("Limited Service");

            IdleRefreshServiceIndicationArea();

            /* if( g_pwr_context.idleScreenFirst ) //Robin 1211 */
            if (mmi_bootup_is_searching_or_idle_reached() == MMI_TRUE)
            {
                StopLEDPatternNoService();  /* MTK add Robin 1009. Stop LED will trigger the Band led pattern resume mechanism */
            }

            lastNwStatus = MMI_RAC_INVALID_SIM;

        #ifdef SYNCML_DM_SUPPORT
            dm_notify_network_status(0);
        #endif /* SYNCML_DM_SUPPORT */ 
            break;

        case MMI_RAC_ERROR:
            NetworkErrorHandle();
            break;
    }

    /* micha0423 */
    if (gGPRSStatusModified)    /* Robin 1128 Enter idle screen after GET IMSI RSP comming */
    {
        if (g_idle_context.IsOnIdleScreen && g_pwr_context.testRoaming == 3)
        {
        #ifdef __MMI_EONS_SUPPORT__
            if (mmi_eons_check_if_plmn_present(gPLMN, gLAC) == 0 || lastNwStatus != MMI_RAC_OK)
        #endif
            {
                if (mmi_bootup_is_idle_screen_reached())
                {
                    IdleRefreshServiceIndicationArea();
                    idle_screen_show_network_details();
                #if defined (__MANUAL_MODE_NW_SEL__) && !defined (__MMI_TOUCH_IDLESCREEN_SHORTCUTS__)
                    if (g_pwr_context.CurrentServiceType != LIMITED_SERVICE && g_keylock_context.gKeyPadLockFlag == 0)
                    {
                    #ifdef __MMI_SWAP_LSK_RSK_IN_IDLE_SCREEN__
                        ChangeLeftSoftkey(IDLE_SCREEN_RSK_TEXT, 0);
                    #else
                        ChangeRightSoftkey(IDLE_SCREEN_RSK_TEXT, 0);
                    #endif
                    }
                #endif /* defined (__MANUAL_MODE_NW_SEL__) && !defined (__MMI_TOUCH_IDLESCREEN_SHORTCUTS__) */
                } 
                else
                {
                    EntryIdleScreen();
                }
            }
        }
        else
        {
            refresh_status_icon_display();
        }

        gGPRSStatusModified = 0;
    }

#ifdef __MMI_DUAL_SIM_MASTER__
    if (!g_pwr_context.IsCampOnTonePlayed && !g_pwr_context_2.IsCampOnTonePlayed && g_pwr_context.CurrentServiceType == FULL_SERVICE)
#else
    if (!g_pwr_context.IsCampOnTonePlayed && g_pwr_context.CurrentServiceType == FULL_SERVICE)  /* Robin 1128 Play camp on tone after enter idle screen */
#endif
    {
        if (g_idle_context.IsOnIdleScreen)  /* Lisen 040406 */
        {
            playRequestedTone(CAMP_ON_TONE);
            g_pwr_context.IsCampOnTonePlayed = 1;
        #ifdef __MMI_DUAL_SIM_MASTER__        
            g_pwr_context_2.IsCampOnTonePlayed = 1;
        #endif
        }
    }

    //micha0923, #169    
    //if( g_pwr_context.InvalidSim  && (g_idle_context.IsOnIdleScreen || IsScreenPresent(IDLE_SCREEN_ID)) &&  !g_pwr_context.InvalidSimShowed) 
    if (mmi_bootup_is_nw_registration_ok() == MMI_FALSE &&
        (g_idle_context.IsOnIdleScreen || IsScreenPresent(IDLE_SCREEN_ID)) && !g_pwr_context.InvalidSimShowed)
    {
        g_pwr_context.InvalidSimShowed = 1;
        DisplayInvalidSimInfo();
    }
}


/*****************************************************************************
 * FUNCTION
 *  NetworkErrorHandle
 * DESCRIPTION
 *  Handler for network attachment case MMI_RAC_ERROR
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void NetworkErrorHandle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (lastNwStatus)
    {
        case MMI_RAC_OK:
            g_pwr_context.CurrentServiceType = FULL_SERVICE;

        #ifdef __MMI_DUAL_SIM_MASTER__
            /* set the network to full service */
            MTPNP_AD_Set_Card1ServiceType(MTPNP_AD_FULL_SERVICE);
        #endif

            /* memcpy(gPLMN,lastPLMN,MAX_PLMN_LEN_MMI); */
            strcpy((S8*) gPLMN, (S8*) lastPLMN);
            RefreshNwProviderName(gPLMN);
            if (mmi_bootup_is_searching_or_idle_reached() == MMI_TRUE)
            {
                StopLEDPatternNoService();
            }
            break;

        case MMI_RAC_NO_CELL:
            g_pwr_context.CurrentServiceType = NO_SERVICE;

        #ifdef __MMI_DUAL_SIM_MASTER__
            /* set the network to no service */
            MTPNP_AD_Set_Card1ServiceType(MTPNP_AD_NO_SERVICE);
        #endif

            /* RefreshNwProviderName(gPLMN); */
            if (mmi_bootup_is_searching_or_idle_reached() == MMI_TRUE)
            {
                StopLEDPatternNoService();
            }
            break;

        case MMI_RAC_LIMITED_SERVICE:
            g_pwr_context.CurrentServiceType = LIMITED_SERVICE;
			
        #ifdef __MMI_DUAL_SIM_MASTER__
            /* set the network to limit service */
            MTPNP_AD_Set_Card1ServiceType(MTPNP_AD_LIMITED_SERVICE);
        #endif

            /* RefreshNwProviderName(gPLMN); */
            if (mmi_bootup_is_searching_or_idle_reached() == MMI_TRUE)
            {
                StopLEDPatternNoService();
            }
            break;

        case MMI_RAC_INVALID_SIM:
            /* g_pwr_context.InvalidSim = 1; */
            g_pwr_context.PowerOnNWStatus |= MMI_NW_STATUS_REG_FAILED;  /* network registration failed */
            g_pwr_context.CurrentServiceType = LIMITED_SERVICE;

        #ifdef __MMI_DUAL_SIM_MASTER__
            /* set the network to limit service */
            MTPNP_AD_Set_Card1ServiceType(MTPNP_AD_LIMITED_SERVICE);
        #endif

            /* RefreshNwProviderName(gPLMN); */
            if (mmi_bootup_is_searching_or_idle_reached() == MMI_TRUE)
            {
                StopLEDPatternNoService();
            }
            break;

        case MMI_RAC_ATTEMPT_TO_UPDATE:
            g_pwr_context.CurrentServiceType = LIMITED_SERVICE;

        #ifdef __MMI_DUAL_SIM_MASTER__
            /* set the network to limit service */
            MTPNP_AD_Set_Card1ServiceType(MTPNP_AD_LIMITED_SERVICE);
        #endif

            /* RefreshNwProviderName(gPLMN); */
            if (mmi_bootup_is_searching_or_idle_reached() == MMI_TRUE)
            {
                StopLEDPatternNoService();  /* MTK add Robin 1009. Stop LED will trigger the Band led pattern resume mechanism */
            }
            break;

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  RefreshNwProviderName
 * DESCRIPTION
 *  Refresh the network provider name
 * PARAMETERS
 *  UpdatePlmn      [?]     
 *  U8*(?)
 * RETURNS
 *  void
 *****************************************************************************/
void RefreshNwProviderName(U8 *UpdatePlmn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EONS_SUPPORT__
    /* diamond, 2005/09/26 support PNN and OPL */
    U8 recordnum = mmi_eons_check_if_plmn_present(UpdatePlmn, gLAC);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (recordnum)
    {
        mmi_eons_get_pnn_record_req(recordnum);
        return;
    }

    if (mmi_eons_is_pnn_present_without_opl() && mmi_netset_plmn_matching_criteria((U8*) gHomePLMNNum, gPLMN))
    {
        mmi_eons_get_pnn_record_req(1);
        return;
    }
#endif /* __MMI_EONS_SUPPORT__ */ 

    /* diamond, 2006/03/08 Get plmn string from gPLMN[MAX_PLMN_LEN_MMI+1] */
    mmi_netset_retrieve_opname_from_plmn(UpdatePlmn, gNWProviderName);

    if (mmi_netset_is_t_mobile_us_sim() == MMI_TRUE && memcmp(gPLMN, "31017", 5) == 0)
    {
        mmi_ucs2cpy((PS8) gNWProviderName, (PS8) L"T-Mobile");
    }
}


/*****************************************************************************
 * FUNCTION
 *  NetWorkSignalLevelIndication
 * DESCRIPTION
 *  This function is a call back for PRT_NW_RX_LEVEL_IND, which is used to update signal strenth icon
 * PARAMETERS
 *  inMsg       [?]     
 *  void*(?)
 * RETURNS
 *  void
 *****************************************************************************/
void NetWorkSignalLevelIndication(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMINWRXLEVELIND *local_data = (MMINWRXLEVELIND*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("Inside NetWorkSignalLevelIndication ");

    g_pwr_context.CurrentCampOnBand = local_data->current_band; /* LED display for different band */

    /* MTK Modified, 030917, Robin, For Signal strength */
    if (local_data->level == SIGNAL_STRENGTH_INVAILD)
    {
        PRINT_INFORMATION("Invalid Signal Indication");
    }
    else if (local_data->level == SIGNAL_STRENGTH_NONE)
    {
        PRINT_INFORMATION("No Signal Indication");
        gSignalStrengthLevel = 0;
    }
    else if (local_data->level < SIGNAL_STRENGTH_LEVEL1)    /* Robin 1116 */
    {
        PRINT_INFORMATION("No Signal Indication");
        gSignalStrengthLevel = 0;
    }
    else if ((local_data->level >= SIGNAL_STRENGTH_LEVEL1) && (local_data->level < SIGNAL_STRENGTH_LEVEL2))
    {
        PRINT_INFORMATION("Show only one bar shaded ");
        gSignalStrengthLevel = 25;
    }
    else if ((local_data->level >= SIGNAL_STRENGTH_LEVEL2) && (local_data->level < SIGNAL_STRENGTH_LEVEL3))
    {
        PRINT_INFORMATION("Show two  bar shaded ");
        gSignalStrengthLevel = 50;
    }
    else if ((local_data->level >= SIGNAL_STRENGTH_LEVEL3) && (local_data->level < SIGNAL_STRENGTH_LEVEL4))
    {
        PRINT_INFORMATION("Show three  bar shaded ");
        gSignalStrengthLevel = 75;
    }
    else if (local_data->level >= SIGNAL_STRENGTH_LEVEL4)
    {
        PRINT_INFORMATION("Show four bar shaded ");
        gSignalStrengthLevel = 100;
    }

    /* Robin 1117, no service shall not display signal level */
    if (g_pwr_context.CurrentServiceType == NO_SERVICE)
    {
        ChangeStatusIconLevel(STATUS_ICON_SIGNAL_STRENGTH, SIGNAL_STRENGTH_NONE);
    }
    else
    {
        ChangeStatusIconLevel(STATUS_ICON_SIGNAL_STRENGTH, gSignalStrengthLevel);
    }

#ifdef __MMI_SUBLCD__
    if (g_pwr_context.CurrentServiceType == NO_SERVICE)
    {
        ChangeStatusIconLevel(STATUS_ICON_SUBLCD_SIGNAL_STRENGTH, SIGNAL_STRENGTH_NONE);
    }
    else
    {
        ChangeStatusIconLevel(STATUS_ICON_SUBLCD_SIGNAL_STRENGTH, gSignalStrengthLevel);
    }
#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  NetWorkServiceTypeIndication
 * DESCRIPTION
 *  This function is a call back for PRT_SERVICE_TYPE_IND
 * PARAMETERS
 *  iMsg        [?]     
 *  void*(?)
 * RETURNS
 *  void
 *****************************************************************************/
void NetWorkServiceTypeIndication(void *iMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* MMINWREGSTATEIND *local_data = (MMINWREGSTATEIND *)iMsg; */
    mmi_nw_reg_state_ind_struct *local_data = (mmi_nw_reg_state_ind_struct*) iMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n NetWorkServiceTypeIndication\n");

    if (local_data->status == MMI_RAC_OK)
    {
        /* micha0120 */
        UpdateGPRSStatusIcon(local_data->gprs_status);

        /* micha0423 */
        if (gGPRSStatusModified)
        {
            refresh_status_icon_display();
            gGPRSStatusModified = 0;
        }
    }
    else
    {
        /* Do nothing, keep original state */
    }
}


/*****************************************************************************
 * FUNCTION
 *  NumberOfPLMNSuported
 * DESCRIPTION
 *  This function is a call back for MSG_ID_MMI_SMU_SUPPORT_PLMN_LIST_IND
 * PARAMETERS
 *  iMsg        [?]     
 *  void*(?)
 * RETURNS
 *  void
 *****************************************************************************/
void NumberOfPLMNSuported(void *iMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMISMUSUPPORTPLMNLISTIND *local_data = (MMISMUSUPPORTPLMNLISTIND*) iMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pwr_context.NoOfPLMNSupported = local_data->length;
    PRINT_INFORMATION("NumberOfPLMNSuported gNoOfPLMNSupported = %d\n", g_pwr_context.NoOfPLMNSupported);
}

/**************************************************************************
            Roaming API
**************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  ChangeRoamingState
 * DESCRIPTION
 *  Change Roaming state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ChangeRoamingState(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* diamond, 2005/08/28 avoid the case VPLMN=OPN */
    if (!mmi_netset_plmn_matching_criteria((U8*) gHomePLMNNum, gPLMN) &&
        mmi_ucs2cmp((S8*) gNWProviderName, (S8*) gOperatorName) != 0 &&
        !(memcmp(gHomePLMNNum, "46002", 5) == 0 && memcmp(gPLMN, "46000", 5) == 0) &&
        !(mmi_netset_is_t_mobile_us_sim() == MMI_TRUE && memcmp(gPLMN, "31017", 5) == 0) &&
    #ifdef __MMI_EONS_SUPPORT__
        mmi_eons_check_roaming() != MMI_TRUE &&
    #endif
        mmi_netset_equivalent_plmn_check() != MMI_TRUE)
    {
        /* Set Roaming Signal to be display on idle screen */
        /* g_pwr_context.RoamingFlag = 1; */
        g_pwr_context.PowerOnSIMStatus |= MMI_SIM_STATUS_ROAMING;
        IdleSetStatusIcon(STATUS_ICON_ROAMING);
        /* if( g_pwr_context.idleScreenFirst ) */
        if (mmi_bootup_is_searching_or_idle_reached() == MMI_TRUE)
        {
            StopLEDPatternRoaming();    /* MTK add Robin 1009. Stop LED will trigger the Band led pattern resume mechanism */
        }

    #ifdef MMS_SUPPORT
        #ifdef __MMI_DUAL_SIM__
        wap_roaming_status_indication_callback(SIM1, (U32) 1);
        #else
        wap_roaming_status_indication_callback((U32) 1);
        #endif
    #endif 
    }
    else
    {
        /* g_pwr_context.RoamingFlag = 0; */
        g_pwr_context.PowerOnSIMStatus &= ~MMI_SIM_STATUS_ROAMING;
        IdleResetStatusIcon(STATUS_ICON_ROAMING);
        /* if( g_pwr_context.idleScreenFirst ) */
        if (mmi_bootup_is_searching_or_idle_reached() == MMI_TRUE)
        {
            StopLEDPatternRoaming();    /* MTK add Robin 1009. Stop LED will trigger the Band led pattern resume mechanism */
        }

    #ifdef MMS_SUPPORT
        #ifdef __MMI_DUAL_SIM__
        wap_roaming_status_indication_callback(SIM1, (U32) 0);
        #else
        wap_roaming_status_indication_callback((U32) 0);
        #endif
    #endif 

    }
}


/*****************************************************************************
 * FUNCTION
 *  RequestToTestRoamingEnabled
 * DESCRIPTION
 *  To send message MSG_ID_MMI_SMU_GET_IMSI_REQ
 *  in response of this message imsi field is returned
 *  compare first 5byte of this arr , if they are not same
 *  with the plmn , means roaming is enabled, display the
 *  roaming icon.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RequestToTestRoamingEnabled(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(RspToTestRoamingEnabled, PRT_GET_IMSI_RSP);
    g_pwr_context.testRoaming = 2;

    PRINT_INFORMATION("@@@@@ RequestToTestRoamingEnabled  @@@@@");
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_GET_IMSI_REQ;
    Message.oslDataPtr = NULL;  /* (oslParaType *)local_data; */
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}

/*****************************************************************************
 * FUNCTION
 *  RspToTestRoamingEnabled
 * DESCRIPTION
 *  To send message MSG_ID_MMI_SMU_GET_IMSI_REQ
 *  in response of this message imsi field is returned
 *  compare first 5byte of this arr , if they are not same
 *  with the plmn , means roaming is enabled, display the
 *  roaming icon.
 * PARAMETERS
 *  inMsg       [?]     
 *  void*(?)
 * RETURNS
 *  void
 *****************************************************************************/
void RspToTestRoamingEnabled(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMISMUGETIMSIRSP *local_data = (MMISMUGETIMSIRSP*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("Inside RspToTestRoamingEnabled");

    if (local_data->result == ST_SUCCESS)
    {
        g_pwr_context.testRoaming = 3;

        memset(gHomePLMNNum, '\0', sizeof(gHomePLMNNum));
        memcpy(gHomePLMNNum, (local_data->imsi) + 1, MAX_PLMN_LEN_MMI); /* always copy 6 digits to gHomePLMNNum no matter they're 5 or 6 digits */

    #ifdef MMS_SUPPORT
        wap_plmn_number_indication_callback((const U8*)gHomePLMNNum);
    #endif 

        mmi_idle_get_spdi_info_req(); /* start to read EF_SPDI and then EONS files */

        if (g_pwr_context.CurrentServiceType == FULL_SERVICE)   /* Robin 1128 */
        {
            ChangeRoamingState();
        }

    #ifdef __DRM_SUPPORT__
        mmi_drm_send_get_imsi_cnf(local_data->imsi, MMI_TRUE);
    #endif

    }
    else
    {
        g_pwr_context.testRoaming = 1;
    }

    if (mmi_idle_is_on_idle_screen() && mmi_bootup_is_idle_screen_reached())
    {
        IdleRefreshServiceIndicationArea();
        idle_screen_show_network_details(); /* EntryIdleScreen(); */
    }
}


/*****************************************************************************
 * FUNCTION
 *  NetWorkCipherIndication
 * DESCRIPTION
 *  Callback function for ciphering indeication
 * PARAMETERS
 *  info        [?]     
 *  void*(?)
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef _NETWORK_CIPHER_SUPPORT_
void NetWorkCipherIndication(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_cipher_ind_struct *local_data = (mmi_smu_cipher_ind_struct*) info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n NetWorkCipherIndication\n");

#ifdef __MMI_DUAL_SIM_MASTER__
    if (local_data->cipher_ind == 1 && local_data->is_gsm_conn_exist == 1 && mmi_ucm_app_total_call(MMI_UCM_SIM1_CALL_TYPE_ALL) != 0)
#else
    if (local_data->cipher_ind == 1 && local_data->is_gsm_conn_exist == 1 && isInCall())
#endif
    {
        if (local_data->gsm_cipher_cond == GMMREG_CIPHER_OFF)
        {
            ShowStatusIcon(STATUS_ICON_NETWORK_CIPHER_GSM); /* warning for insecure network */
        }
        else if (local_data->gsm_cipher_cond == GMMREG_CIPHER_ON ||
                 local_data->gsm_cipher_cond == GMMREG_CIPHER_INVALID)
        {
            HideStatusIcon(STATUS_ICON_NETWORK_CIPHER_GSM); /* warning for insecure network */
        }
        else if (local_data->gprs_cipher_cond == GMMREG_CIPHER_OFF)
        {
            ShowStatusIcon(STATUS_ICON_NETWORK_CIPHER_GPRS);    /* warning for insecure network */
        }
        else if (local_data->gprs_cipher_cond == GMMREG_CIPHER_ON ||
                 local_data->gsm_cipher_cond == GMMREG_CIPHER_INVALID)
        {
            HideStatusIcon(STATUS_ICON_NETWORK_CIPHER_GPRS);    /* warning for insecure network */
        }
    }
    else    /* cipher not supported */
    {
        HideStatusIcon(STATUS_ICON_NETWORK_CIPHER_GSM);
        HideStatusIcon(STATUS_ICON_NETWORK_CIPHER_GPRS);
    }

    UpdateStatusIcons();
}
#endif /* _NETWORK_CIPHER_SUPPORT_ */ 

/**************************************************************************
         API of Manual Mode Network Selection
**************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  PLMNSelectionModeIndication
 * DESCRIPTION
 *  Callback function for PLMN selection mode indication
 * PARAMETERS
 *  info        [?]     
 *  void*(?)
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MANUAL_MODE_NW_SEL__
void PLMNSelectionModeIndication(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_sel_mode_ind_struct *local_data = (mmi_nw_sel_mode_ind_struct*) info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n NetworkSelectionModeIndication\n");

    /* g_pwr_context.PLMNSelectionMode = local_data->network_mode; */
    if (local_data->network_mode == MANUAL_MODE)
    {
        g_pwr_context.PowerOnNWStatus |= MMI_NW_STATUS_PLMNSEL_MODE;    /* 0x08: PLMN selection mode */
    }
    else
    {
        g_pwr_context.PowerOnNWStatus &= ~MMI_NW_STATUS_PLMNSEL_MODE;   /* 0x08: PLMN selection mode */
    }

    IdleRefreshServiceIndicationArea();

    if (mmi_idle_is_on_idle_screen() && mmi_bootup_is_idle_screen_reached())
    {
        IdleSetLRKey();
    }
}


/*****************************************************************************
 * FUNCTION
 *  PLMNGetSelectionModeRsp
 * DESCRIPTION
 *  Response for PLMN selection mode
 * PARAMETERS
 *  info        [?]     
 *  void*(?)
 * RETURNS
 *  void
 *****************************************************************************/
void PLMNGetSelectionModeRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_get_plmn_select_mode_rsp_struct *local_data = (mmi_nw_get_plmn_select_mode_rsp_struct*) info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n PLMNGetSelectionModeRsp\n");

    /* g_pwr_context.PLMNSelectionMode = local_data->mode; */
    if (local_data->mode == MANUAL_MODE)
    {
        g_pwr_context.PowerOnNWStatus |= MMI_NW_STATUS_PLMNSEL_MODE;    /* 0x08: PLMN selection mode */
    }
    else
    {
        g_pwr_context.PowerOnNWStatus &= ~MMI_NW_STATUS_PLMNSEL_MODE;   /* 0x08: PLMN selection mode */
    }

    ClearProtocolEventHandler(MSG_ID_MMI_NW_GET_PLMN_SELECT_MODE_RSP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  PLMNGetSelectionModeReq
 * DESCRIPTION
 *  Request for PLMN selection mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PLMNGetSelectionModeReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE msgStruct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(PLMNGetSelectionModeRsp, MSG_ID_MMI_NW_GET_PLMN_SELECT_MODE_RSP);
    /* format the message to get band selection */
    msgStruct.oslSrcId = MOD_MMI;
    msgStruct.oslDestId = MOD_L4C;
    msgStruct.oslMsgId = (unsigned int)MSG_ID_MMI_NW_GET_PLMN_SELECT_MODE_REQ;
    msgStruct.oslSapId = (unsigned int)0;
    msgStruct.oslDataPtr = NULL;
    msgStruct.oslPeerBuffPtr = NULL;
    /* send req to l4 to get band selection */
    OslMsgSendExtQueue(&msgStruct);
    return;
}
#endif /* __MANUAL_MODE_NW_SEL__ */ 

/**************************************************************************
            GPRS API
**************************************************************************/

#ifdef WAP_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_netset_update_gprs_state_to_wap
 * DESCRIPTION
 *  Send GPRS state to WAP
 * PARAMETERS
 *  state        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_update_gprs_state_to_wap(U8 state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE msgStruct;
    wap_bearer_status_ind_struct *local_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wap_browser_is_open())
    {
        msgStruct.oslSrcId = MOD_MMI;
        msgStruct.oslDestId = MOD_WAP;
        msgStruct.oslMsgId = MSG_ID_WAP_BEARER_STATUS_IND;
        local_data = (wap_bearer_status_ind_struct*) OslConstructDataPtr(sizeof(wap_bearer_status_ind_struct));
        local_data->bearer_type = WAP_BEARER_STATUS_GPRS;
        local_data->status = state;
        msgStruct.oslDataPtr = (oslParaType*) local_data;
        msgStruct.oslPeerBuffPtr = NULL;
        OslMsgSendExtQueue(&msgStruct);	
    }
}
#endif /* WAP_SUPPORT */


/*****************************************************************************
 * FUNCTION
 *  GPRSStatusUpdateIndication
 * DESCRIPTION
 *  Callback function for GPRS status update indication
 * PARAMETERS
 *  info        [?]     
 *  void*(?)
 * RETURNS
 *  void
 *****************************************************************************/
void GPRSStatusUpdateIndication(void *info)
{
#ifdef __MMI_GPRS_FEATURES__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ps_gprs_status_update_ind_struct *local_data = (mmi_ps_gprs_status_update_ind_struct*) info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n GPRSStatusUpdateIndication\n");
    mmi_netset_set_edge_status(local_data->cell_support_egprs);
    UpdateGPRSStatusIcon(local_data->status);

    if (gGPRSStatusModified)
    {
        UpdateStatusIcons();
        gGPRSStatusModified = 0;
    }
#endif /* __MMI_GPRS_FEATURES__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  GPRSStatusGetGPRSModeRsp
 * DESCRIPTION
 *  Response for GPRS mode
 * PARAMETERS
 *  info        [?]     
 *  void*(?)
 * RETURNS
 *  void
 *****************************************************************************/
void GPRSStatusGetGPRSModeRsp(void *info)
{
#ifdef __MMI_GPRS_FEATURES__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_get_gprs_connect_type_rsp_struct *localPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (mmi_nw_get_gprs_connect_type_rsp_struct*) info;

    if (localPtr->result == MMI_TRUE)
    {
        if (localPtr->type == L4C_WHEN_NEEDED)
        {
            GPRSStatusDetachGPRSReq();
        }
    }
#endif /* __MMI_GPRS_FEATURES__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  GPRSStatusGetGPRSModeReq
 * DESCRIPTION
 *  Request for GPRS mode
 * PARAMETERS
 *  void
 *  void*(?)
 * RETURNS
 *  void
 *****************************************************************************/
void GPRSStatusGetGPRSModeReq(void)
{
#ifdef __MMI_GPRS_FEATURES__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE msgStruct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(GPRSStatusGetGPRSModeRsp, MSG_ID_MMI_NW_GET_GPRS_CONNECT_TYPE_RSP);
    /* format the message to get band selection */
    msgStruct.oslSrcId = MOD_MMI;
    msgStruct.oslDestId = MOD_L4C;
    msgStruct.oslMsgId = (unsigned int)MSG_ID_MMI_NW_GET_GPRS_CONNECT_TYPE_REQ;
    msgStruct.oslSapId = (unsigned int)0;
    msgStruct.oslDataPtr = NULL;
    msgStruct.oslPeerBuffPtr = NULL;
    /* send req to l4 to get band selection */
    OslMsgSendExtQueue(&msgStruct);
    return;
#endif /* __MMI_GPRS_FEATURES__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  GPRSStatusDetachGPRSRsp
 * DESCRIPTION
 *  Response for GPRS detachment
 * PARAMETERS
 *  info        [?]     
 *  void*(?)
 * RETURNS
 *  void
 *****************************************************************************/
void GPRSStatusDetachGPRSRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* do nothing */
}


/*****************************************************************************
 * FUNCTION
 *  GPRSStatusDetachGPRSReq
 * DESCRIPTION
 *  Request for GPRS detachment
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GPRSStatusDetachGPRSReq(void)
{
#ifdef __MMI_GPRS_FEATURES__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE msgStruct;
    mmi_nw_set_attach_req_struct *local_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(GPRSStatusDetachGPRSRsp, MSG_ID_MMI_NW_SET_ATTACH_RSP);
    msgStruct.oslSrcId = MOD_MMI;
    msgStruct.oslDestId = MOD_L4C;
    msgStruct.oslMsgId = MSG_ID_MMI_NW_SET_ATTACH_REQ;
    local_data = (mmi_nw_set_attach_req_struct*) OslConstructDataPtr(sizeof(mmi_nw_set_attach_req_struct));
    local_data->is_poweroff = MMI_FALSE;
    local_data->opcode = RAC_DETACH;
    local_data->type = RAC_PS;
    msgStruct.oslDataPtr = (oslParaType*) local_data;
    msgStruct.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&msgStruct);
    return;
#endif /* __MMI_GPRS_FEATURES__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  UpdateGPRSStatusIcon
 * DESCRIPTION
 *  Update GPRS icon
 * PARAMETERS
 *  gprs_state      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UpdateGPRSStatusIcon(U8 gprs_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static U8 gGPRSAttachStatus = 0;
    static U8 gGPRSPDPStatus = 0;
    static U8 gGPRSCellStatus = 0;

    /* micha0202, vito G display issue */
    static U8 LastGPRSStatus = 0;   /* 0: No icon,  1:  only attach,  2: attach+pdp active */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (gprs_state)
    {
        case L4C_GPRS_ATTACHED:
            gGPRSCellStatus = 1;    /* diamond, 2006/04/20 Accept to display if no coverage */
            gGPRSAttachStatus = 1;
        #ifdef WAP_SUPPORT
            mmi_netset_update_gprs_state_to_wap(WAP_GPRS_ATTACHED);
        #endif
            break;
        case L4C_GPRS_DETACHED:
            gGPRSAttachStatus = 0;
        #ifdef WAP_SUPPORT
            mmi_netset_update_gprs_state_to_wap(WAP_GPRS_DETACHED);
        #endif
            break;
        case L4C_PDP_ACTIVED:
            gGPRSPDPStatus = 1;
            break;
        case L4C_PDP_DEACTIVED:
            gGPRSPDPStatus = 0;
            break;
        case L4C_GPRS_COVERAGE:
        #ifdef WAP_SUPPORT
            mmi_netset_update_gprs_state_to_wap(WAP_GPRS_COVERAGE);
        #endif
            gGPRSCellStatus = 1;
            break;
        case L4C_NONE_GPRS:
            gGPRSCellStatus = 0;
            gGPRSAttachStatus = 0;
        #ifdef WAP_SUPPORT
            mmi_netset_update_gprs_state_to_wap(WAP_GPRS_NONE);
        #endif
            break;
        default:
            break;
    }

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[Update G] Att:%d,PDP:%d,Cov:%d,Last:%d", gGPRSAttachStatus,
                         gGPRSPDPStatus, gGPRSCellStatus, LastGPRSStatus);

    /* micha0202, micha0224, vito display issue */
    if (gGPRSAttachStatus && gGPRSPDPStatus && gGPRSCellStatus)
    {
        if (LastGPRSStatus != 2 || (m_edge_last_status != m_edge_status))
        {
            HideStatusIcon(STATUS_ICON_GPRS_ATT_NO_PDP_INDICATOR);
            HideStatusIcon(STATUS_ICON_EDGEC);
            if (mmi_netset_is_cell_support_egprs())
            {
                HideStatusIcon(STATUS_ICON_GPRS_SERVICE);
                ShowStatusIcon(STATUS_ICON_EDGE);
            }
            else
            {
                HideStatusIcon(STATUS_ICON_EDGE);
                ShowStatusIcon(STATUS_ICON_GPRS_SERVICE);
            }
            LastGPRSStatus = 2;
            gGPRSStatusModified = 1;
        }
    }
    else if (gGPRSAttachStatus && !gGPRSPDPStatus && gGPRSCellStatus)
    {
        if (LastGPRSStatus != 1 || (m_edge_last_status != m_edge_status))
        {
            HideStatusIcon(STATUS_ICON_GPRS_SERVICE);
            HideStatusIcon(STATUS_ICON_EDGE);
            if (mmi_netset_is_cell_support_egprs())
            {
                HideStatusIcon(STATUS_ICON_GPRS_ATT_NO_PDP_INDICATOR);
                ShowStatusIcon(STATUS_ICON_EDGEC);
            }
            else
            {
                HideStatusIcon(STATUS_ICON_EDGEC);
                ShowStatusIcon(STATUS_ICON_GPRS_ATT_NO_PDP_INDICATOR);
            }
            LastGPRSStatus = 1;
            gGPRSStatusModified = 1;
        }
    }
    else
    {
        if (LastGPRSStatus != 0 || (m_edge_last_status != m_edge_status))
        {
            HideStatusIcon(STATUS_ICON_GPRS_ATT_NO_PDP_INDICATOR);
            HideStatusIcon(STATUS_ICON_GPRS_SERVICE);
            HideStatusIcon(STATUS_ICON_EDGEC);
            HideStatusIcon(STATUS_ICON_EDGE);
            LastGPRSStatus = 0;
            gGPRSStatusModified = 1;
        }
        UpdateStatusIcons();
    }
}

/**************************************************************************
         API's To Others
**************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  HomezoneStatusIndication
 * DESCRIPTION
 *  This function is a call back for homezone indication
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __HOMEZONE_SUPPORT__
void HomezoneStatusIndication(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 convertOutLen = 0, originalInLen = 0, i;
    mmi_hz_tag_ind_struct *local_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // U8 s[4] = {0x54, 0x65, 0x73, 0x74};
    // gHomezoneText=CovertStringForPlatform((PU8)s, 4, MMI_DEFAULT_DCS, &convertOutLen);

    local_data = (mmi_hz_tag_ind_struct*) info;

    if (local_data->is_hz == MMI_TRUE)  /* homezone case */
    {
        if (local_data->action == MMI_TRUE) /* show icon and display text */
        {
        #if 0
/* under construction !*/
        #endif
            ShowStatusIcon(STATUS_ICON_HOMEZONE);
            if (local_data->tag[0] != 0xFF)
            {
                for (i = 0; i < 12; i++) /* the max HZ length is 12 */
                {
                    if (local_data->tag[i] == 0xFF)
                    {
                        break;
                    }
                    else
                    {
                        originalInLen++;
                    }
                }
                gHomezoneText = CovertStringForPlatform(local_data->tag, originalInLen, MMI_DEFAULT_DCS, &convertOutLen);
            }
            else
            {
                if (gHomezoneText != NULL)
                {
                    OslMfree(gHomezoneText);
                    gHomezoneText = NULL;
                }
            }
        }
        else    /* clear icon and text */
        {
            HideStatusIcon(STATUS_ICON_HOMEZONE);
        #if 0
/* under construction !*/
        #endif
            if (gHomezoneText != NULL)
            {
                OslMfree(gHomezoneText);
                gHomezoneText = NULL;
            }
        }
    }
    else    /* cityzone case */
    {
        if (local_data->action == MMI_TRUE) /* show icon and display text */
        {
            HideStatusIcon(STATUS_ICON_HOMEZONE);
        #if 0
/* under construction !*/
        #endif
            if (local_data->tag[0] != 0xFF)
            {
                for (i = 0; i < 12; i++) /* the max HZ length is 12 */
                {
                    if (local_data->tag[i] == 0xFF)
                    {
                        break;
                    }
                    else
                    {
                        originalInLen++;
                    }
                }
                gHomezoneText = CovertStringForPlatform(local_data->tag, originalInLen, MMI_DEFAULT_DCS, &convertOutLen);
            }
            else
            {
                if (gHomezoneText != NULL)
                {
                    OslMfree(gHomezoneText);
                    gHomezoneText = NULL;
                }
            }
        }
        else    /* clear icon and text */
        {
            HideStatusIcon(STATUS_ICON_HOMEZONE);
        #if 0
/* under construction !*/
        #endif
            if (gHomezoneText != NULL)
            {
                OslMfree(gHomezoneText);
                gHomezoneText = NULL;
            }
        }
    }

    UpdateStatusIcons();
    IdleRefreshServiceIndicationArea();

    if (mmi_idle_is_on_idle_screen() && mmi_bootup_is_idle_screen_reached())
    {
        IdleRefreshServiceIndicationArea();
        idle_screen_show_network_details(); /* EntryIdleScreen(); */
    }
}
#endif /* __HOMEZONE_SUPPORT__ */ 


#ifndef __MTK_TARGET__
/*****************************************************************************
 * FUNCTION
 *  mmi_netset_inject_network_attachment
 * DESCRIPTION
 *  This function is message injection to MMI for network attachment
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_inject_network_attachment(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_attach_ind_struct *nw_attach_ind;
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nw_attach_ind = (mmi_nw_attach_ind_struct*) OslConstructDataPtr(sizeof(mmi_nw_attach_ind_struct));
    
    nw_attach_ind->status = MMI_RAC_OK;
    nw_attach_ind->gprs_status = L4C_GPRS_DETACHED;
    nw_attach_ind->plmn[0] = 0x34;
    nw_attach_ind->plmn[1] = 0x36;
    nw_attach_ind->plmn[2] = 0x36;
    nw_attach_ind->plmn[3] = 0x39;
    nw_attach_ind->plmn[4] = 0x37;
    nw_attach_ind->plmn[5] = 0;
    
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_MMI;
    Message.oslMsgId = PRT_NW_ATTACH_IND;
    Message.oslDataPtr = (oslParaType*) nw_attach_ind;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_write_auto_test_result
 * DESCRIPTION
 *  This function is used for auto power on test on MoDIS
 * PARAMETERS
 *  result         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_netset_write_auto_test_result(pBOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    extern pBOOL AUTO_POWER;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_bootup_is_idle_screen_reached())
    {
        return;
    }

    if (AUTO_POWER)
    {
        if (result)
        {
            w32_modis_poweron_log(MMI_TRUE);
            ShutdownSystemOperation();
        }
        else
        {
            w32_modis_poweron_log(MMI_FALSE);
        }
    }
}

#endif /* __MTK_TARGET__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_set_edge_status
 * DESCRIPTION
 *  This function used to set EDGE status
 * PARAMETERS
 *  edge_state
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_netset_set_edge_status(U8 edge_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[Update G] EDGE:%d", edge_state);

    m_edge_last_status = m_edge_status;
    m_edge_status = edge_state;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_is_cell_support_egprs
 * DESCRIPTION
 *  This function checks whether it supports EDGE or not
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_netset_is_cell_support_egprs(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (m_edge_status == 1)
        return MMI_TRUE;
    else
        return MMI_FALSE;
}

