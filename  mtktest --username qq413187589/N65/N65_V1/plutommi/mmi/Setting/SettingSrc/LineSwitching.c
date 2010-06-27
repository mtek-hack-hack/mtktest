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
 * LineSwitching.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   <file description>.
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

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : LineSwitching.c


   PURPOSE     : 

   REMARKS     : nil

   AUTHOR      : Ashish Gupta, Vanita Jain

   DATE     : 

**************************************************************/
#include "MMI_include.h"

#include "ProtocolEvents.h"
#include "CallSetUp.h"
#include "PhoneBookTypes.h"
#include "SimDetectionDef.h"
#include "SimDetectionGprot.h"
#include "wgui_status_icons.h"
#include "IdleAppProt.h"
#include "IdleAppDef.h"
#include "CallSetUpEnum.h"
#include "wgui_fixed_menus.h"
#include "LineSwitchGprot.h"
#include "wgui_touch_screen.h"

#ifdef __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__      /* 022505 Calvin added */
#endif 

#ifdef __MMI_WLAN_FEATURES__
#include "NetworkSetupDefs.h"
#endif

#ifdef __MMI_UCM__
#include "UCMResDef.h"
#endif /* __MMI_UCM__ */

#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_AD_master_header.h"
#endif  /* __MMI_DUAL_SIM_MASTER__ */

#include "MTPNP_AD_resdef.h"

/*****************************************************************************
 * FUNCTION
 *  InitLineSwitch
 * DESCRIPTION
 *  initialization function for line switching
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitLineSwitch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set hilite handlers for the individual menu items */
    SetHiliteHandler(MENU_LINE_SWCH, HighlightCALLSETLineSwitch);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCALLSETLineSwitch
 * DESCRIPTION
 *  hilite handler for line selection option
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCALLSETLineSwitch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_callset_context.LineIDInput = (U8) GetCurrHiliteID();
    /* Change left soft key icon and label */
    ChangeLeftSoftkey(STR_SETTING_LINE_SEL, 0);
    /* Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    /* set the left/right soft key functions handlers */

    SetLeftSoftkeyFunction(MakePsSelectLine, KEY_EVENT_UP);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* set the left/right arrow key function handlers */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  MakePsSelectLine
 * DESCRIPTION
 *  Sends Clip request to stack
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MakePsSelectLine(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_cphs_update_als_req_struct *msg = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = (mmi_cphs_update_als_req_struct*) OslConstructDataPtr(sizeof(mmi_cphs_update_als_req_struct));
    ClearInputEventHandler(MMI_DEVICE_ALL);
    SetKeyHandler(0, KEY_END, KEY_EVENT_DOWN);
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;

    if (g_callset_context.LineID == LINE1)
    {
        msg->line_id = LINE2;
    }
    else
    {
        msg->line_id = LINE1;
    }

    SetProtocolEventHandler(CALLSETLineSwitchRsp, PRT_MMI_CPHS_UPDATE_ALS_RSP);
    Message.oslMsgId = PRT_LINE_SET_REQ;
    Message.oslDataPtr = (oslParaType*) msg;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  CALLSETLineSwitchRsp
 * DESCRIPTION
 *  response handler for set line1 req
 * NA
 *  
 * PARAMETERS
 *  info            [?]         
 *  response(?)     [IN]        Buffer void *
 * RETURNS
 *  void
 *****************************************************************************/
void CALLSETLineSwitchRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cphs_update_als_rsp_struct *local;

#ifdef __MMI_LINE_SWITCH_SHOW_NUMBER__
    S8 tempstr[10];
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local = (mmi_cphs_update_als_rsp_struct*) info;
    if (local->res == MMI_TRUE)
    {
        if (g_callset_context.LineID == LINE1)
        {
            /* 101805 ChangeStatusIconImage Calvin Start */
            /* ChangeStatusIconImage will not call UpdateStatusIcon */
        #if 0
		#ifdef __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__ //022505 Calvin added
/* under construction !*/
		#else
/* under construction !*/
/* under construction !*/
		#endif
        #endif /* 0 */ 
        #ifdef __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__      /* 022505 Calvin added */

        #ifndef __MMI_DUAL_SIM_MASTER__
            ChangeStatusIconImage(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_SIGNAL_STRENGTH_L2);
        #else
            if (MTPNP_AD_Get_Startup_Mode() != MTPNP_AD_NVRAM_CARD2)
            {
                ChangeStatusIconImage(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_MASTER_SIGNAL_STRENGTH_L2);
            }
        #endif
        #else /* __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__ */ 
            HideStatusIcon(STATUS_ICON_ALTERNATE_LINE_L1);
            ShowStatusIcon(STATUS_ICON_ALTERNATE_LINE_L2);
        #endif /* __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__ */ 
            /* 101805 ChangeStatusIconImage Calvin End */
            g_callset_context.LineID = LINE2;

        #ifdef __MMI_DUAL_SIM_MASTER__
            MTPNP_AD_Set_Card1CurrLineID(MTPNP_AD_LINE_2);
        #endif /* __MMI_DUAL_SIM_MASTER__ */
            mmi_ucs2cpy((S8*) g_callset_context.LineInfo, (S8*) GetString(STR_LSW_LINE2));
        #ifdef __MMI_LINE_SWITCH_SHOW_NUMBER__
            if (mmi_ucs2strlen((S8*) gDispOwnerNumber[1].name) > 0)
            {
                mmi_asc_to_ucs2((S8*) tempstr, (S8*) ",");
                mmi_ucs2cat((S8*) g_callset_context.LineInfo, (S8*) tempstr);
                mmi_ucs2cat((S8*) g_callset_context.LineInfo, (S8*) gDispOwnerNumber[1].name);
            }
            else if (mmi_ucs2strlen((S8*) gDispOwnerNumber[1].number) > 0)
            {
                mmi_asc_to_ucs2((S8*) tempstr, (S8*) ",");
                mmi_ucs2cat((S8*) g_callset_context.LineInfo, (S8*) tempstr);
                mmi_ucs2cat((S8*) g_callset_context.LineInfo, (S8*) gDispOwnerNumber[1].number);
            }
        #endif /* __MMI_LINE_SWITCH_SHOW_NUMBER__ */ 

        }
        else
        {
            /* 101805 ChangeStatusIconImage Calvin Start */
            /* ChangeStatusIconImage will not call UpdateStatusIcon */
        #if 0
		#ifdef __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__ //022505 Calvin added
/* under construction !*/
		#else
/* under construction !*/
/* under construction !*/
		#endif
        #endif /* 0 */ 
        #ifdef __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__      /* 022505 Calvin added */

        #ifndef __MMI_DUAL_SIM_MASTER__
            ChangeStatusIconImage(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_SIGNAL_STRENGTH_L1);
        #else
            if (MTPNP_AD_Get_Startup_Mode() != MTPNP_AD_NVRAM_CARD2)
            {
                ChangeStatusIconImage(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_MASTER_SIGNAL_STRENGTH_L1);
            }
        #endif
        #else /* __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__ */ 
            HideStatusIcon(STATUS_ICON_ALTERNATE_LINE_L2);
            ShowStatusIcon(STATUS_ICON_ALTERNATE_LINE_L1);
        #endif /* __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__ */ 
            /* 101805 ChangeStatusIconImage Calvin End */
            g_callset_context.LineID = LINE1;
        #ifdef __MMI_DUAL_SIM_MASTER__
            MTPNP_AD_Set_Card1CurrLineID(MTPNP_AD_LINE_1);
        #endif /* __MMI_DUAL_SIM_MASTER__ */
            mmi_ucs2cpy((S8*) g_callset_context.LineInfo, (S8*) GetString(STR_LSW_LINE1));
        #ifdef __MMI_LINE_SWITCH_SHOW_NUMBER__
            if (mmi_ucs2strlen((S8*) gDispOwnerNumber[0].name) > 0)
            {
                mmi_asc_to_ucs2((S8*) tempstr, (S8*) ",");
                mmi_ucs2cat((S8*) g_callset_context.LineInfo, (S8*) tempstr);
                mmi_ucs2cat((S8*) g_callset_context.LineInfo, (S8*) gDispOwnerNumber[0].name);
            }
            else if (mmi_ucs2strlen((S8*) gDispOwnerNumber[0].number) > 0)
            {
                mmi_asc_to_ucs2((S8*) tempstr, (S8*) ",");
                mmi_ucs2cat((S8*) g_callset_context.LineInfo, (S8*) tempstr);
                mmi_ucs2cat((S8*) g_callset_context.LineInfo, (S8*) gDispOwnerNumber[0].number);
            }
        #endif /* __MMI_LINE_SWITCH_SHOW_NUMBER__ */ 
        }

        RefreshDisplayOwnerNumber((U8) g_callset_context.LineID);
        
    #ifdef __MMI_UCM__
    #ifdef __MMI_DUAL_SIM_MASTER__
        if (GetActiveScreenId() == SCR_ID_UCM_GENERAL_CALL_SETTING_SIM1)
    #else /* __MMI_DUAL_SIM_MASTER__ */
        if (GetActiveScreenId() == SCR_ID_UCM_GENERAL_CALL_SETTING_MORE)
    #endif /* __MMI_DUAL_SIM_MASTER__ */
    #else /* __MMI_UCM__ */
        if (GetActiveScreenId() == SCR_ID_CALLSET_MAIN)
    #endif /* __MMI_UCM__ */ 
        {
            mmi_ucs2cpy((S8*) hintData[g_callset_context.LineIDInput], (PS8) g_callset_context.LineInfo);
            Category52ChangeItemDescription(g_callset_context.LineIDInput, (U8*) g_callset_context.LineInfo);
            RedrawCategoryFunction();
            ClearInputEventHandler(MMI_DEVICE_KEY);
            register_fixed_list_keys();
#ifdef __MMI_TOUCH_SCREEN__
            wgui_register_general_pen_handler();
#endif            
            HighlightCALLSETLineSwitch();
        }
        else    /* 101805 ChangeStatusIconImage Calvin add: ChangeStatusIconImage will not call UpdateStatusIcon */
        {
            UpdateStatusIcons();
        }
    }
    else
    {
        ShowCategory2Screen(
            STR_LINE_SET_TITLE,
            IMG_LINE_SET_TITLE,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            0,
            0,
            STR_LINE1_SET_ERR,
            NULL);
        SetLeftSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  RefreshDisplayOwnerNumber
 * DESCRIPTION
 *  Owner number associate with Line ID
 * NA
 *  
 * PARAMETERS
 *  lineid      [IN]        
 *  line(?)     [IN]        Id
 * RETURNS
 *  void
 *****************************************************************************/
extern void UI_set_font(UI_font_type f);
void RefreshDisplayOwnerNumber(U8 lineid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 idx = 0, iCnt = 0;
    S32 StringWidth, StringHeight;
    stFontAttribute prev_f;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (lineid == LINE1)
    {
        idx = 0;
    }
    else
    {
        idx = 1;
    }

    memset(gOwnerName, 0, sizeof(gOwnerName));
    if (gDispOwnerNumber[idx].name[0] != 0x0 || gDispOwnerNumber[idx].name[1] != 0x0)   /* not null string */
    {
        iCnt = ((MAX_PB_NAME_LENGTH) > MAX_DISPLAY_CHAR) ? MAX_DISPLAY_CHAR : (MAX_PB_NAME_LENGTH);
        mmi_ucs2ncpy(gOwnerName, (PS8) gDispOwnerNumber[idx].name, iCnt);
    }
    else if (gDispOwnerNumber[idx].number[0] != 0x0 || gDispOwnerNumber[idx].number[1] != 0x0)  /* not null string */
    {
        iCnt = ((MAX_PB_NUMBER_LENGTH + 1) > MAX_DISPLAY_CHAR) ? MAX_DISPLAY_CHAR : (MAX_PB_NUMBER_LENGTH + 1);
        mmi_ucs2ncpy(gOwnerName, (PS8) gDispOwnerNumber[idx].number, iCnt);
    }

    memcpy(&prev_f, UI_font, sizeof(stFontAttribute));
    //      UI_set_font(&MMI_default_font); 
    // lisen: to calculate based on the current font size
    UI_set_font(&UI_DEFAULT_FONT);
    for (iCnt = (U8) mmi_ucs2strlen((PS8) gOwnerName); iCnt > 0; iCnt--)
    {
        Get_StringWidthHeight((U8*) gOwnerName, &StringWidth, &StringHeight);
        /* Add one pixel for border text */
        if ((StringWidth + 1) >= MAIN_LCD_device_width - (MMI_IDLE_STRING_MARGIN_GAP << 1))
        {
            gOwnerName[iCnt * ENCODING_LENGTH] = 0x0;
            /* micha0305 */
            gOwnerName[iCnt * ENCODING_LENGTH + 1] = 0x0;
        }
        else
        {
            break;
        }
    }
    UI_set_font(&prev_f);

}


/*****************************************************************************
 * FUNCTION
 *  CALLSETLineInUseRsp
 * DESCRIPTION
 *  response handler to set the line in use
 * NA
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void CALLSETLineInUseRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cphs_display_als_ind_struct *localPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check the response struct for set line in use */
    localPtr = (mmi_cphs_display_als_ind_struct*) info;
    if (localPtr->line == LINE1)
    {
        /* update the status icon the menu items */
    #ifdef __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__      /* 022505 Calvin added */
        if (mmi_bootup_get_active_flight_mode() == 0
    #ifdef __MMI_WLAN_FEATURES__
        && mmi_netset_get_active_preferred_mode() != P_WLAN_ONLY
    #endif /* __MMI_WLAN_FEATURES__ */
        )
        {
        #ifndef __MMI_DUAL_SIM_MASTER__
            ChangeStatusIconImage(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_SIGNAL_STRENGTH_L1);
        #else
            if (MTPNP_AD_Get_Startup_Mode() != MTPNP_AD_NVRAM_CARD2)
            {
                ChangeStatusIconImage(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_MASTER_SIGNAL_STRENGTH_L1);
            }
        #endif
            UpdateStatusIcons();    /* 101805 ChangeStatusIconImage Calvin: ChangeStatusIconImage will not call UpdateStatusIcon */
        }
    #else /* __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__ */ 
        IdleResetStatusIcon(STATUS_ICON_ALTERNATE_LINE_L2);
        IdleSetStatusIcon(STATUS_ICON_ALTERNATE_LINE_L1);
    #endif /* __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__ */ 
        g_callset_context.LineID = LINE1;

    #ifdef __MMI_DUAL_SIM_MASTER__
        MTPNP_AD_Set_Card1CurrLineID(MTPNP_AD_LINE_1);
    #endif  /* __MMI_DUAL_SIM_MASTER__ */
    }
    else
    {
        /* update the status icon the menu items */
    #ifdef __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__      /* 022505 Calvin added */
        if (mmi_bootup_get_active_flight_mode() == 0
    #ifdef __MMI_WLAN_FEATURES__
        && mmi_netset_get_active_preferred_mode() != P_WLAN_ONLY
    #endif /* __MMI_WLAN_FEATURES__ */
        )
        {
        #ifndef __MMI_DUAL_SIM_MASTER__
            ChangeStatusIconImage(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_SIGNAL_STRENGTH_L2);
        #else
            if (MTPNP_AD_Get_Startup_Mode() != MTPNP_AD_NVRAM_CARD2)
            {
                ChangeStatusIconImage(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_MASTER_SIGNAL_STRENGTH_L2);
            }
        #endif
            UpdateStatusIcons();    /* 101805 ChangeStatusIconImage Calvin: ChangeStatusIconImage will not call UpdateStatusIcon */
        }
    #else /* __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__ */ 
        IdleResetStatusIcon(STATUS_ICON_ALTERNATE_LINE_L1);
        IdleSetStatusIcon(STATUS_ICON_ALTERNATE_LINE_L2);
    #endif /* __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__ */ 
        g_callset_context.LineID = LINE2;

    #ifdef __MMI_DUAL_SIM_MASTER__
        MTPNP_AD_Set_Card1CurrLineID(MTPNP_AD_LINE_2);
    #endif /* __MMI_DUAL_SIM_MASTER__*/
    }
    /* Owner number associate with Line ID */
    RefreshDisplayOwnerNumber((U8) g_callset_context.LineID);
    return;
}

/* PMT HIMANSHU START 20050625 */
#if defined(__MMI_UI_TECHNO_STATUS_ICON__)


/*****************************************************************************
 * FUNCTION
 *  set_vertical_signal_status_icons
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void set_vertical_signal_status_icons(void)
{

#ifdef __MMI_DUAL_SIM_MASTER__
#ifdef __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_callset_context.LineID == LINE1)
    {
        ChangeStatusIconImageWithoutReArrange(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_SIGNAL_STRENGTH_IDLE_L1);
    }
    else if (g_callset_context.LineID == LINE2)
    {
        ChangeStatusIconImageWithoutReArrange(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_SIGNAL_STRENGTH_IDLE_L2);
    }
#endif /* __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__ */ 
#else	/* __MMI_DUAL_SIM_MASTER__ */
#ifdef __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__
    if (g_callset_context.LineID == LINE1)
    {
        ChangeStatusIconImageWithoutReArrange(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_MASTER_SIGNAL_STRENGTH_L1);
    }
    else if (g_callset_context.LineID == LINE2)
    {
        ChangeStatusIconImageWithoutReArrange(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_MASTER_SIGNAL_STRENGTH_L2);
    }
#endif /* __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__ */ 
#endif	/* __MMI_DUAL_SIM_MASTER__ */
}


/*****************************************************************************
 * FUNCTION
 *  set_horizontal_signal_status_icons
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void set_horizontal_signal_status_icons(void)
{
#ifdef __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_callset_context.LineID == LINE1)
    {
    #ifdef __MMI_DUAL_SIM_MASTER__
        ChangeStatusIconImageWithoutReArrange(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_SIGNAL_STRENGTH_L1);
    #else	/* __MMI_DUAL_SIM_MASTER__ */
	    ChangeStatusIconImageWithoutReArrange(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_MASTER_SIGNAL_STRENGTH_L1);
    #endif	/* __MMI_DUAL_SIM_MASTER__ */
    }
    else if (g_callset_context.LineID == LINE2)
    {
    //#ifndef __MERCURY_MASTER__
    #ifdef __MMI_DUAL_SIM_MASTER__
        ChangeStatusIconImageWithoutReArrange(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_SIGNAL_STRENGTH_L2);
    #else	/* __MMI_DUAL_SIM_MASTER__ */
	    ChangeStatusIconImageWithoutReArrange(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_MASTER_SIGNAL_STRENGTH_L2);
    #endif	/* __MMI_DUAL_SIM_MASTER__ */
    }
#endif /* __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__ */ 
}
#endif /* defined(__MMI_UI_TECHNO_STATUS_ICON__) */ 
/* PMT HIMANSHU END */

