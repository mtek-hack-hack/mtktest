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
 *  CPHSProtocolHandlers.c
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

   FILENAME : CPHSProtocolHandlers.c

   PURPOSE     : COMMON PCN HANDSET SPECIFICATION

   REMARKS     : nil

   AUTHOR      : NEERAJ SHARMA

   DATE     : Aug 6,03

**************************************************************/
#include "MMI_include.h"
#include "CSP.h"
#include "InfoNum.h"
#include "ProtocolEvents.h"
#include "CPHSProtocolHandlers.h"
#include "SimDetectionGprot.h"
#include "wgui_status_icons.h"
#include "SettingGprots.h"
#include "IdleAppDef.h"
#include "CallSetup.h"
#include "EONSGProt.h"

#ifdef __MMI_SML_MENU__
#include "PersonalizationDef.h"
#include "PersonalizationProt.h"
extern mmi_sml_menu_struct g_sml_context;
#endif /* __MMI_SML_MENU__ */

#ifdef __MMI_DUAL_SIM_DUAL_CALL_SLAVE__
#include "MTPNP_PFAL_Slave_Network.h"
#include "MTPNP_PFAL_Slave_CC.h"
#endif /* __MMI_DUAL_SIM_DUAL_CALL_SLAVE__ */

#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
#include "MTPNP_PFAL_Gemini_Network.h"
#include "MTPNP_PFAL_Gemini_CC.h"
#endif /* __MMI_DUAL_SIM_SINGLE_CALL__ */

#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
void MTPNP_PFAL_CFU_STATUS_IND(void *MsgStruct);
void MTPNP_PFAL_NW_Idle_Info_Indication(void *inMsg);
void MTPNP_PFAL_Network_Report_Line_Info_Indication(void *inMsg);
#endif /* __MMI_DUAL_SIM_SINGLE_CALL__ */

extern void InitialiseInformationArray(U8 noInfoNum, l4csmu_info_num_struct *infoNum);

/* void testcsp(void)
   {
   U8 csp[22];
   csp[0]=0x01;
   csp[1]=0xFF;
   csp[2]=0x02;
   csp[3]=0xFF;
   csp[4]=0x03;
   csp[5]=0xFF;
   csp[6]=0x04;
   csp[7]=0xFF;
   csp[8]=0x05;
   csp[9]=0x10;
   csp[10]=0x06;
   csp[11]=0x7F;
   csp[12]=0x07;
   csp[13]=0xFF;
   csp[14]=0x08;
   csp[15]=0xFF;
   csp[16]=0x09;
   csp[17]=0xF8;
   csp[18]=0xC0;
   csp[19]=0x0E;
   csp[20]=0xD5;
   csp[21]=0xFF;
   InitialiseCSPInfoArray(csp);
   } */
/*
 * void testInfoNum(void)
 * {
 * l4csmu_info_num_struct info[12];
 * memset(info,0,sizeof(info));
 * info[0].alpha_id_size=strlen("TRAVEL");
 * memcpy(info[0].alpha_id,"TRAVEL",info[0].alpha_id_size);
 * info[0].ton_npi=0xFF;
 * info[0].index_level=1;
 * 
 * info[1].alpha_id_size=strlen("TAXIS");
 * memcpy(info[1].alpha_id,"TAXIS",info[1].alpha_id_size);
 * info[1].ton_npi=0xFF;
 * info[1].index_level=2;
 * 
 * info[2].alpha_id_size=strlen("Computercabs");
 * memcpy(info[2].alpha_id,"Computercabs",info[2].alpha_id_size);
 * info[2].ton_npi=1;
 * info[2].digit_size=4;
 * strcpy(info[2].digit,"111");
 * info[2].index_level=3;
 * info[2].network_specific=1;
 * info[2].premium_rate=1;
 * 
 * 
 * info[3].alpha_id_size=strlen("Dial-a-cab");
 * memcpy(info[3].alpha_id,"Dial-a-cab",info[3].alpha_id_size);
 * info[3].ton_npi=1;
 * info[3].digit_size=4;
 * strcpy(info[3].digit,"132");
 * info[3].index_level=3;
 * info[3].network_specific=1;
 * 
 * info[4].alpha_id_size=strlen("AIRPORTS");
 * memcpy(info[4].alpha_id,"AIRPORTS",info[4].alpha_id_size);
 * info[4].ton_npi=0xFF;
 * info[4].index_level=2;
 * 
 * 
 * info[5].alpha_id_size=strlen("Heathrow");
 * memcpy(info[5].alpha_id,"Heathrow",info[5].alpha_id_size);
 * info[5].ton_npi=0x1;
 * info[5].digit_size=4;
 * strcpy(info[5].digit,"345");
 * info[5].index_level=3;
 * 
 * info[6].alpha_id_size=strlen("Gatwick");
 * memcpy(info[6].alpha_id,"Gatwick",strlen("info[6].alpha_id_size"));
 * info[6].ton_npi=0x1;
 * info[6].digit_size=4;
 * strcpy(info[6].digit,"651");
 * info[6].index_level=3;
 * 
 * info[7].alpha_id_size=strlen("WEATHER");
 * memcpy(info[7].alpha_id,"WEATHER",info[7].alpha_id_size);
 * info[7].ton_npi=0xFF;
 * info[7].index_level=1;
 * 
 * info[8].alpha_id_size=strlen("North");
 * memcpy(info[8].alpha_id,"North",info[8].alpha_id_size);
 * info[8].ton_npi=0x1;
 * info[8].digit_size=4;
 * strcpy(info[8].digit,"323");
 * info[8].index_level=2;
 * 
 * info[9].alpha_id_size=strlen("South");
 * memcpy(info[9].alpha_id,"South",info[9].alpha_id_size);
 * info[9].ton_npi=0x1;
 * info[9].digit_size=4;
 * strcpy(info[9].digit,"597");
 * info[9].index_level=2;
 * 
 * info[10].alpha_id_size=strlen("ENTERTAINMENT");
 * memcpy(info[10].alpha_id,"ENTERTAINMENT",info[10].alpha_id_size);
 * info[10].ton_npi=0xFF;
 * info[10].index_level=1;
 * 
 * info[11].alpha_id_size=strlen("Ticketmaster");
 * memcpy(info[11].alpha_id,"Ticketmaster",info[11].alpha_id_size);
 * info[11].ton_npi=0x1;
 * info[11].digit_size=4;
 * strcpy(info[11].digit,"562");
 * info[11].index_level=2;
 * 
 * InitialiseInformationArray(12, info);
 * }
 */


/*****************************************************************************
 * FUNCTION
 *  InitCPHS
 * DESCRIPTION
 *  Initialises CPHS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitCPHS(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearCSPArray();

#ifndef __MMI_DUAL_SIM_DUAL_CALL_SLAVE__
    SetProtocolEventHandler(CPHSDisplayCFUInd, PRT_MSG_ID_MMI_CPHS_DISPLAY_CFU_IND);
    SetProtocolEventHandler(CPHSMMInfoInd, PRT_MSG_ID_MMI_CPHS_MMI_INFO_IND);
    SetProtocolEventHandler(CALLSETLineInUseRsp, PRT_MMI_CPHS_DISPLAY_ALS_IND);
#else /* __MMI_DUAL_SIM_DUAL_CALL_SLAVE__ */
    SetProtocolEventHandler(MTPNP_PFAL_CFU_STATUS_IND, PRT_MSG_ID_MMI_CPHS_DISPLAY_CFU_IND);
    SetProtocolEventHandler(MTPNP_PFAL_NW_Idle_Info_Indication, PRT_MSG_ID_MMI_CPHS_MMI_INFO_IND);
    SetProtocolEventHandler(MTPNP_PFAL_Network_Report_Line_Info_Indication, PRT_MMI_CPHS_DISPLAY_ALS_IND);
#endif /* __MMI_DUAL_SIM_DUAL_CALL_SLAVE__ */

#if defined(__MMI_DUAL_SIM_SINGLE_CALL__)
    SetSlaveProtocolEventHandler(MTPNP_PFAL_CFU_STATUS_IND, PRT_MSG_ID_MMI_CPHS_DISPLAY_CFU_IND);
    SetSlaveProtocolEventHandler(MTPNP_PFAL_NW_Idle_Info_Indication, PRT_MSG_ID_MMI_CPHS_MMI_INFO_IND);
    SetSlaveProtocolEventHandler(MTPNP_PFAL_Network_Report_Line_Info_Indication, PRT_MMI_CPHS_DISPLAY_ALS_IND);
#endif /* __MMI_DUAL_SIM_SINGLE_CALL__ */
}


/*****************************************************************************
 * FUNCTION
 *  CPHSDisplayCFUInd
 * DESCRIPTION
 *  Protocol Handler for CFU Ind
 * PARAMETERS
 *  msgPtr      [IN]        Data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void CPHSDisplayCFUInd(void *msgPtr)
{
#ifdef __MMI_CFU_SEPARATE_LINE__        /* MTK 1111, Robin CFU regardless Line ID */
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static U8 StatusCFULine1 = 0;
    static U8 StatusCFULine2 = 0;
#endif /* __MMI_CFU_SEPARATE_LINE__ */ 

    mmi_cphs_display_cfu_ind_struct *MsgCfuInd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
    if (MTPNP_AD_Get_Card1Status() != MTPNP_AD_SIMCARD_VALID)
    {
        return; /* ignore CFU indication if there is no SIM */
    }
#endif /*__DUAL_SIM_MASTER__ */

    MsgCfuInd = (mmi_cphs_display_cfu_ind_struct*) msgPtr;

#ifdef __MMI_CFU_SEPARATE_LINE__        /* MTK 1111, Robin CFU regardless Line ID */
    if (MsgCfuInd != NULL)
    {
        HideStatusIcon(STATUS_ICON_CALL_DIVERT_L1);
        HideStatusIcon(STATUS_ICON_CALL_DIVERT_L2);
        HideStatusIcon(STATUS_ICON_CALL_DIVERT_L1L2);

        if (MsgCfuInd->action == 1)
        {
            if (MsgCfuInd->line_num == 0)
            {
                StatusCFULine1 = 1;
            }
            else if (MsgCfuInd->line_num == 1)
            {
                StatusCFULine2 = 1;
            }
        }
        else
        {
            if (MsgCfuInd->line_num == 0)
            {
                StatusCFULine1 = 0;
            }
            else if (MsgCfuInd->line_num == 1)
            {
                StatusCFULine2 = 0;
            }
        }
    }

#ifdef __MMI_DUAL_SIM_MASTER__
    if (MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_CARD2)
    {
        /* only keep the status and not show category if the mode is not matched to SIM */
        return;
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */

    if ((StatusCFULine1) && (!StatusCFULine2))
    {
        ShowStatusIcon(STATUS_ICON_CALL_DIVERT_L1);
    }
    else if ((!StatusCFULine1) && (StatusCFULine2))
    {
        ShowStatusIcon(STATUS_ICON_CALL_DIVERT_L2);
    }
    else if ((StatusCFULine1) && (StatusCFULine2))
    {
        ShowStatusIcon(STATUS_ICON_CALL_DIVERT_L1L2);
    }
    UpdateStatusIcons();

#else /* __MMI_CFU_SEPARATE_LINE__ */ 
    if (MsgCfuInd != NULL)
    {
        if (MsgCfuInd->action == 1)
        {
            ShowStatusIcon(STATUS_ICON_CALL_DIVERT_L1L2);
        }
        UpdateStatusIcons();
    }
#endif /* __MMI_CFU_SEPARATE_LINE__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  CPHSMMInfoInd
 * DESCRIPTION
 *  Protocol Handler for MMI Info Ind
 * PARAMETERS
 *  msgPtr      [IN]        Data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void CPHSMMInfoInd(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cphs_mmi_info_ind_struct *mmiIndoInd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmiIndoInd = (mmi_cphs_mmi_info_ind_struct*) msgPtr;

    //PRINT_INFORMATION("<<CPHS>> Recieved CPHS MMI Info Ind");

#ifdef __MMI_SIMAP_SUPPORT__
    g_idle_context.SimReady = MMI_TRUE;
#endif

#ifndef __MMI_DUAL_SIM_MASTER__
#ifdef __CPHS_FEATURE_DEFAULT_OFF__
    mmi_frm_hide_menu_item(MENU_LINE_SWCH);
#endif

#ifdef __MMI_SS_CF_ALLCOND_MENU__
    mmi_frm_hide_menu_item(MENU8239_CALFWD_VOICECALL_ALLCOND);
#endif
#endif /* __MMI_DUAL_SIM_MASTER__ */

#ifdef __GEMINI__
    if (mmiIndoInd->is_valid_csp && sim_service_table_query(SERVICE_CSP, 0) == SERVICE_SUPPORT)
#else
    if (mmiIndoInd->is_valid_csp && sim_service_table_query(SERVICE_CSP) == SERVICE_SUPPORT)
#endif
    {
        InitialiseCSPInfoArray(mmiIndoInd->csp);
    }

#ifdef __GEMINI__
    if (mmiIndoInd->no_info_num && sim_service_table_query(SERVICE_INFO_NUM, 0) == SERVICE_SUPPORT)
#else
    if (mmiIndoInd->no_info_num && sim_service_table_query(SERVICE_INFO_NUM) == SERVICE_SUPPORT)
#endif
    {
        InitialiseInformationArray(mmiIndoInd->no_info_num, mmiIndoInd->info_num);
    }

#ifndef __MMI_DUAL_SIM_MASTER__
    /* diamond, 2006/03/14 Additional check for sim service table */
    mmi_cphs_puct_check(mmiIndoInd->is_puct_valid);
    mmi_cphs_sim_lock_check();
#endif /* __MMI_DUAL_SIM_MASTER__ */

    if (mmi_eons_is_service_available())
    {
        mmiIndoInd->is_opname_valid = 0;
        mmiIndoInd->is_sopname_valid = 0;
    }

    ServiceIndicationStringDisplay(mmiIndoInd);

#ifdef __MMI_SML_MENU__
    /* SIM-ME-Lock auto lock check */
    g_sml_context.autolock_nibble = 0;
    if (mmiIndoInd->is_autolock_enable)
    {
        g_sml_context.autolock_nibble |= 0x01;
        if (mmiIndoInd->autolock_result)
        {
            g_sml_context.autolock_nibble |= 0x10;
        }
    }
    if (mmi_bootup_is_searching_or_idle_reached())
    {
        /* Prevent from entering idle screen then receive CPHS indication */
        mmi_sml_display_auto_locked_notification();
    }
#endif /* __MMI_SML_MENU__ */

    GetSettingOptionsStatus();
}

