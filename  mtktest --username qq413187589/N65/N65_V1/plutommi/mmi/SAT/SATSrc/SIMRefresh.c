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
 *   SIMRefresh.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#include "MMI_include.h"
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
#include "CSP.h"
#include "IdleAppProt.h"

#ifdef __SAT__

/* External Function */
#ifdef __MMI_EONS_SUPPORT__
extern void mmi_eons_get_opl_file_info_req(void);
#endif

/* External Variable */
extern SATFILECHANGE gSATFileChange;

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)

#define SET_EVENT_2(funcPtr, eventID)   \
{                                   \
    if (gSATFileChange.CMDfromSIM == SAT_CMD_SIM2)      \
    {                               \
        SetSlaveProtocolEventHandler(funcPtr, eventID); \
    }                               \
    else                            \
    {                               \
        SetProtocolEventHandler(funcPtr, eventID);      \
    }                               \
}                                   \

#define CLR_EVENT_2(eventID)        \
{                                   \
    if (gSATFileChange.CMDfromSIM == SAT_CMD_SIM2)  \
    {                               \
        ClearSlaveProtocolEventHandler(eventID);    \
    }                               \
    else                            \
    {                               \
        ClearProtocolEventHandler(eventID);         \
    }                               \
}                                   \

#else /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */

#define SET_EVENT_2(funcPtr, eventID)   \
{                                   \
    SetProtocolEventHandler(funcPtr, eventID);  \
}                                   \

#define CLR_EVENT_2(eventID)        \
{                                   \
    ClearProtocolEventHandler(eventID);         \
}                                   \

#endif /* (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_get_msisdn_data_handler
 * DESCRIPTION
 *  Get MSISDN data response handler
 * PARAMETERS
 *  info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_get_msisdn_data_handler(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_read_sim_rsp_struct *msisdn_data;
    mmi_cphs_mmi_info_ind_struct cphs_mmi_info;

    U8 i, alpha_len, bcd_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msisdn_data = (mmi_smu_read_sim_rsp_struct*) info;

    CLR_EVENT_2(PRT_MMI_SMU_READ_SIM_RSP);

    if (msisdn_data->result.flag == 0)
    {
        memset((void*)&cphs_mmi_info, 0, sizeof(mmi_cphs_mmi_info_ind_struct));

        cphs_mmi_info.no_msisdn = 1;

        if (msisdn_data->data[0] >= 0x80 && msisdn_data->data[0] <= 0x82)
        {
            for (alpha_len = 0; *(msisdn_data->data + 1 + alpha_len) != 0xFF; alpha_len++);
            cphs_mmi_info.msisdn[0].alpha_id_size = alpha_len;
            cphs_mmi_info.msisdn[0].alpha_id_dcs = MMI_UCS2_DCS + msisdn_data->data[0] - 0x80;
            memcpy(cphs_mmi_info.msisdn[0].alpha_id, msisdn_data->data + 1, alpha_len);
        }
        else
        {
            for (alpha_len = 0; *(msisdn_data->data + alpha_len) != 0xFF; alpha_len++);
            cphs_mmi_info.msisdn[0].alpha_id_size = alpha_len;
            cphs_mmi_info.msisdn[0].alpha_id_dcs = MMI_DEFAULT_DCS;
            memcpy(cphs_mmi_info.msisdn[0].alpha_id, msisdn_data->data, alpha_len);
        }
        cphs_mmi_info.msisdn[0].alpha_id[alpha_len] = 0;

        cphs_mmi_info.msisdn[0].ton_npi = *(msisdn_data->data + msisdn_data->length - 13);

        for (bcd_len = 0; *(msisdn_data->data + msisdn_data->length - 12 + bcd_len) != 0xFF; bcd_len++);
        cphs_mmi_info.msisdn[0].digit_size = bcd_len * 2;
        for (i = 0; i < bcd_len; i++)
        {
            cphs_mmi_info.msisdn[0].digit[i * 2] = 0x30 + (*(msisdn_data->data + msisdn_data->length - 12 + i) & 0x0F);
            cphs_mmi_info.msisdn[0].digit[i * 2 + 1] = 0x30 + ((*(msisdn_data->data + msisdn_data->length - 12 + i) & 0xF0) >> 4);
        }

        ServiceIndicationStringDisplay((void*)&cphs_mmi_info);
    }

    mmi_sat_refresh_next_file(); /* refresh next */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_get_msisdn_data
 * DESCRIPTION
 *  Get MSISDN data request
 * PARAMETERS
 *  msisdn_record_size      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_get_msisdn_data(U16 msisdn_record_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_smu_read_sim_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SET_EVENT_2(mmi_sat_get_msisdn_data_handler, PRT_MMI_SMU_READ_SIM_RSP);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_MMI_SMU_READ_SIM_REQ;
    dataPtr = (mmi_smu_read_sim_req_struct*) OslConstructDataPtr(sizeof(mmi_smu_read_sim_req_struct));
    dataPtr->file_idx = (U8) FILE_MSISDN_IDX;
    dataPtr->para = 1;
    dataPtr->length = msisdn_record_size;
    Message.oslDataPtr = (oslParaType*) dataPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_get_msisdn_info_handler
 * DESCRIPTION
 *  Get MSISDN info response handler
 * PARAMETERS
 *  info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_get_msisdn_info_handler(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_read_file_info_rsp_struct *msisdn_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msisdn_info = (mmi_smu_read_file_info_rsp_struct*) (info);

    CLR_EVENT_2(PRT_MMI_SMU_READ_FILE_INFO_RSP);

    if (msisdn_info->result.flag == 0)
    {
        mmi_sat_get_msisdn_data((U16) (msisdn_info->file_size / msisdn_info->num_of_rec));
    }
    else
    {
        mmi_sat_refresh_next_file(); /* failed to get file info so that continue next one */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_get_msisdn_info
 * DESCRIPTION
 *  Get MSISDN info request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_get_msisdn_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_smu_read_file_info_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SET_EVENT_2(mmi_sat_get_msisdn_info_handler, PRT_MMI_SMU_READ_FILE_INFO_RSP);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_MMI_SMU_READ_FILE_INFO_REQ;
    dataPtr = (mmi_smu_read_file_info_req_struct*) OslConstructDataPtr(sizeof(mmi_smu_read_file_info_req_struct));
    dataPtr->file_idx = (U8) FILE_MSISDN_IDX;
    Message.oslDataPtr = (oslParaType*) dataPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_get_spn_data_handler
 * DESCRIPTION
 *  Get SPN data response handler
 * PARAMETERS
 *  info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_get_spn_data_handler(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_read_sim_rsp_struct *spn_data;

    U16 alpha_len;
    U8 *convertedData;
    U16 convertOutLen = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    spn_data = (mmi_smu_read_sim_rsp_struct*) info;

    CLR_EVENT_2(PRT_MMI_SMU_READ_SIM_RSP);

    if (spn_data->result.flag == 0)
    {
        if (spn_data->data[1] != 0)
        {
            gSpnValid = 1;
            g_pwr_context.RequireRPLMN = spn_data->data[0] & 0x01;

            if (spn_data->data[1] >= 0x80 && spn_data->data[1] <= 0x82)
            {
                for (alpha_len = 0; *(spn_data->data + 2 + alpha_len) != 0xFF; alpha_len++);
                convertedData = CovertStringForPlatform(
                                    spn_data->data + 2,
                                    alpha_len,
                                    (U8) (MMI_UCS2_DCS + spn_data->data[1] - 0x80),
                                    &convertOutLen);
            }
            else
            {
                for (alpha_len = 0; *(spn_data->data + 1 + alpha_len) != 0xFF; alpha_len++);
                convertedData = CovertStringForPlatform(
                                    spn_data->data + 1,
                                    alpha_len,
                                    MMI_DEFAULT_DCS,
                                    &convertOutLen);
            }

            mmi_ucs2cpy((PS8) gServProvderName, (PS8) convertedData);
            OslMfree(convertedData);

            if (mmi_idle_is_on_idle_screen() && mmi_bootup_is_idle_screen_reached())
            {
                IdleRefreshServiceIndicationArea();
                idle_screen_show_network_details(); /* EntryIdleScreen(); */
            }
        }
        else
        {
            gSpnValid = 0;
        }
    }

    mmi_sat_refresh_next_file(); /* refresh next */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_get_spn_data
 * DESCRIPTION
 *  Get SPN data request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_get_spn_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_smu_read_sim_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SET_EVENT_2(mmi_sat_get_spn_data_handler, PRT_MMI_SMU_READ_SIM_RSP);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_MMI_SMU_READ_SIM_REQ;
    dataPtr = (mmi_smu_read_sim_req_struct*) OslConstructDataPtr(sizeof(mmi_smu_read_sim_req_struct));
    dataPtr->file_idx = (U8) FILE_SPN_IDX;
    dataPtr->para = 0;
    dataPtr->length = 0x11;
    Message.oslDataPtr = (oslParaType*) dataPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


#ifdef __MANUAL_MODE_NW_SEL__
/*****************************************************************************
 * FUNCTION
 *  mmi_sat_reset_plmn_selection_mode_rsp
 * DESCRIPTION
 *  Reset network seelction mode to automatic
 * PARAMETERS
 *  info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_reset_plmn_selection_mode_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_set_plmn_select_mode_rsp_struct *set_plmn_select_mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_plmn_select_mode = (mmi_nw_set_plmn_select_mode_rsp_struct*) info;

    if (set_plmn_select_mode->result == KAL_TRUE)
    {
        g_pwr_context.PowerOnNWStatus &= ~MMI_NW_STATUS_PLMNSEL_MODE;
        if (mmi_idle_is_on_idle_screen())
        {
            EntryIdleScreen(); /* force to enter idle screen because the network seelction mode might be changed */
        }
    }

    CLR_EVENT_2(PRT_NW_SET_PLMN_SELECT_MODE_RSP);
    mmi_sat_refresh_next_file(); /* refresh next */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_reset_plmn_selection_mode_req
 * DESCRIPTION
 *  Reset network seelction mode to automatic
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_reset_plmn_selection_mode_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_nw_set_plmn_select_mode_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SET_EVENT_2(mmi_sat_reset_plmn_selection_mode_rsp, PRT_NW_SET_PLMN_SELECT_MODE_RSP);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_NW_SET_PLMN_SELECT_MODE_REQ;
    dataPtr = (mmi_nw_set_plmn_select_mode_req_struct*) OslConstructDataPtr(sizeof(mmi_nw_set_plmn_select_mode_req_struct));
    dataPtr->mode = AUTOMATIC_MODE;
    Message.oslDataPtr = (oslParaType*) dataPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}
#endif /* __MANUAL_MODE_NW_SEL__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_get_csp_data_handler
 * DESCRIPTION
 *  Get CSP data response handler
 * PARAMETERS
 *  info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_get_csp_data_handler(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_read_sim_rsp_struct *csp_data;

    U8 csp_temp[22];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    csp_data = (mmi_smu_read_sim_rsp_struct*) info;

    CLR_EVENT_2(PRT_MMI_SMU_READ_SIM_RSP);

    if (csp_data->result.flag == 0)
    {
        /* restore all hidden menu */

        /* call management */
        mmi_frm_unhide_menu_item(MENU8237_SCR8093_MNGCALL_MENU_BARRING);
        mmi_frm_unhide_menu_item(MENU_SETTING_CALL_CLOSED_GP);
        mmi_frm_unhide_menu_item(MENU8237_SCR8093_MNGCALL_MENU_WAIT);
        mmi_frm_unhide_menu_item(MENU_LINE_SWCH);
        /* phone setup */
        mmi_frm_unhide_menu_item(MENU_SETTING_LANGUAGE);
        /* call barring */
        mmi_frm_unhide_menu_item(MENU_CALL_BARRING_OUTGOING);
        mmi_frm_unhide_menu_item(MENU_CALL_BARRING_INCOMING);
        /* call barring outgoing */
        mmi_frm_unhide_menu_item(MENU_BARRING_OUTGOING_ALLCALLS);
        mmi_frm_unhide_menu_item(MENU_BARRING_OUTGOING_INTERCALL);
        mmi_frm_unhide_menu_item(MENU_BARRING_OUTGOING_INTEREXCEPTHOME);
        /* call barring incoming */
        mmi_frm_unhide_menu_item(MENU_BARRING_INCOMING_ALLCALLS);
        mmi_frm_unhide_menu_item(MENU_BARRING_INCOMING_ROAMING);
        /* call forwarding */
        mmi_frm_unhide_menu_item(MENU8238_MNGCALL_CALFWD_VOICECALL);
        mmi_frm_unhide_menu_item(MENU8239_CALFWD_VOICECALL_UNREACHABLE);
        mmi_frm_unhide_menu_item(MENU8239_CALFWD_VOICECALL_NOANSWER);
        mmi_frm_unhide_menu_item(MENU8239_CALFWD_VOICECALL_BUSY);
        mmi_frm_unhide_menu_item(MENU8238_MNGCALL_CALFWD_DATACALL);
    #ifdef __MMI_SS_CF_ALLCOND_MENU__
        mmi_frm_hide_menu_item(MENU8239_CALFWD_VOICECALL_ALLCOND);
    #endif
        /* caller ID */
        mmi_frm_unhide_menu_item(MENU_CID_HIDE_ID);
        mmi_frm_unhide_menu_item(MENU_CID_SHOW_ID);
        /* call history */
        mmi_frm_unhide_menu_item(MENU_CALL_HISTORY_CALLCOST);
        /* network selection */
        mmi_frm_unhide_menu_item(MENU9186_SELECTION_MODE);
        mmi_frm_unhide_menu_item(MENU9188_BAND_SELECTION);
        /* message */
    #ifdef __MMI_UNIFIED_MESSAGE__
        mmi_frm_unhide_menu_item(MENU_ID_UM_INBOX);
        mmi_frm_unhide_menu_item(MENU_ID_UM_WRITE_MSG);
        mmi_frm_unhide_menu_item(MENU_ID_UM_UNSENT);
        mmi_frm_unhide_menu_item(MENU_ID_UM_SENT);
        mmi_frm_unhide_menu_item(MENU_ID_UM_DRAFT);
    #else /* __MMI_UNIFIED_MESSAGE__ */
        mmi_frm_unhide_menu_item(MESSAGES_MENU_INBOX_MENUID);
        mmi_frm_unhide_menu_item(MESSAGES_MENU_WMESSAGE_MENU_ID);
        mmi_frm_unhide_menu_item(MESSAGES_MENU_OUTBOX_MENUID);
    #endif /* __MMI_UNIFIED_MESSAGE__ */
        mmi_frm_unhide_menu_item(MESSAGES_MENU_CB_MENUID);
        mmi_frm_unhide_menu_item(MESSAGES_MENU_VMAIL_MENUID);
        /* message setting */
        mmi_frm_unhide_menu_item(SETUP_MENU_COMMONSETTING_MENUID);
        /* outgoing call management */
        mmi_frm_unhide_menu_item(MITEM2015_CM_CALL_CONFER);
        mmi_frm_unhide_menu_item(MITEM2010_CM_ACTIVE_HOLD);

        memset(csp_temp, 0, 22);
        memcpy(csp_temp, csp_data->data, csp_data->length);
        InitialiseCSPInfoArray(csp_temp);
    }

#ifdef __MANUAL_MODE_NW_SEL__
    if (mmi_bootup_get_plmn_selection_mode() != AUTOMATIC_MODE)
    {
        mmi_sat_reset_plmn_selection_mode_req();
    }
    else
#endif /* __MANUAL_MODE_NW_SEL__ */
    {
        mmi_sat_refresh_next_file(); /* refresh next */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_get_csp_data
 * DESCRIPTION
 *  Get CSP data request
 * PARAMETERS
 *  csp_data_size      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_get_csp_data(U16 csp_data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_smu_read_sim_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SET_EVENT_2(mmi_sat_get_csp_data_handler, PRT_MMI_SMU_READ_SIM_RSP);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_MMI_SMU_READ_SIM_REQ;
    dataPtr = (mmi_smu_read_sim_req_struct*) OslConstructDataPtr(sizeof(mmi_smu_read_sim_req_struct));
    dataPtr->file_idx = (U8) FILE_CSP_IDX;
    dataPtr->para = 0;
    dataPtr->length = csp_data_size; /* EF_CSP: 18 or 20 or 22 bytes */
    Message.oslDataPtr = (oslParaType*) dataPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_get_csp_info_handler
 * DESCRIPTION
 *  Get CSP info response handler
 * PARAMETERS
 *  info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_get_csp_info_handler(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_read_file_info_rsp_struct *csp_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    csp_info = (mmi_smu_read_file_info_rsp_struct*) (info);

    CLR_EVENT_2(PRT_MMI_SMU_READ_FILE_INFO_RSP);

#ifdef __GEMINI__
    if (csp_info->result.flag == 0 && sim_service_table_query(SERVICE_CSP, 0) == SERVICE_SUPPORT)
#else
    if (csp_info->result.flag == 0 && sim_service_table_query(SERVICE_CSP) == SERVICE_SUPPORT)
#endif
    {
        mmi_sat_get_csp_data(csp_info->file_size);
    }
    else
    {
        mmi_sat_refresh_next_file(); /* failed to get file info so that continue next one */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_get_csp_info
 * DESCRIPTION
 *  Get CSP info request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_get_csp_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_smu_read_file_info_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SET_EVENT_2(mmi_sat_get_csp_info_handler, PRT_MMI_SMU_READ_FILE_INFO_RSP);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_MMI_SMU_READ_FILE_INFO_REQ;
    dataPtr = (mmi_smu_read_file_info_req_struct*) OslConstructDataPtr(sizeof(mmi_smu_read_file_info_req_struct));
    dataPtr->file_idx = (U8) FILE_CSP_IDX;
    Message.oslDataPtr = (oslParaType*) dataPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sat_refresh_next_file
 * DESCRIPTION
 *  Next file to refresh
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sat_refresh_next_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tmp_list[120];
    U32 default_flag = 0;

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    if (gSATFileChange.number_of_changes == 0)
    {
        OslMfree(gSATFileChange.file_change_list);
        return;
    }

    switch (*gSATFileChange.file_change_list)
    {
        case FILE_MSISDN_IDX:
            mmi_sat_get_msisdn_info(); /* linear fixed EF, need to get file info and then get data */
            break;

        case FILE_SPN_IDX:
            mmi_sat_get_spn_data(); /* transparent EF, read data directly */
            break;

        case FILE_CSP_IDX:
            mmi_sat_get_csp_info(); /* transparent EF, need to get file info and then get data */
            break;

#ifdef __MMI_EONS_SUPPORT__
        case FILE_PNN_IDX:
            /* MMI alwasy read EF_PNN if the network name needs to update so not necessary to refresh this EF */
            break;

        case FILE_OPL_IDX:
            mmi_eons_get_opl_file_info_req();
            break;
#endif /* __MMI_EONS_SUPPORT__ */

        default:
            default_flag = 1;
            break;
    }

    memcpy(tmp_list, gSATFileChange.file_change_list, gSATFileChange.number_of_changes);
    memcpy(gSATFileChange.file_change_list, &tmp_list[1], gSATFileChange.number_of_changes - 1);
    gSATFileChange.file_change_list[gSATFileChange.number_of_changes - 1] = 0xFF;
    gSATFileChange.number_of_changes--;

    if (default_flag == 1)
    {
        mmi_sat_refresh_next_file();
    }
}

#endif /* __SAT__ */

