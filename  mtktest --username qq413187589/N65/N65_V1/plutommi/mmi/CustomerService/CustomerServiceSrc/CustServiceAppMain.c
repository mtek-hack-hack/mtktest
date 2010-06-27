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
 * CustSerApp.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file implements menu screen of customer service applications.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_include.h"

#ifdef __MMI_CUSTOMER_SERVICE__

#include "wapadp.h"
#include "Ucs2prot.h"
#include "CommonScreens.h"
#include "settingprofile.h"
#include "nvram_common_defs.h"

#if defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__)
#include "NetworkSetupDefs.h"
#include "VoIPGProt.h"
#endif /* defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__) */ 
#include "ProfileGprots.h"
#include "CallManagementGprot.h"

#include "CustSerResDef.h"
#include "CustSerGProt.h"
#include "CustSerProt.h"

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
static const U8 *const p_sales_url = (U8 *) L"http://wap.monternet.com/?cp22=v22yyt";
static const U8 *const p_monternet_url = (U8 *) L"http://wap.monternet.com/portal/wap/menu.do?menuid=200003";

static void mmi_custser_highlight_guideline(void);
static void mmi_custser_highlight_sale(void);
static void mmi_custser_highlight_mymonternet(void);
static void mmi_custser_highlight_setting(void);
static void mmi_custser_highlight_setting_hotline(void);
static void mmi_custser_highlight_setting_manager(void);
static void mmi_custser_highlight_make_call(void);
static void mmi_custser_highlight_make_call_generic(FuncPtr lskfunc);

static void mmi_custser_entry_mymonternet(void);
static void mmi_custser_mymonternet_callback(S32 selected_idx);
static void mmi_custser_mymonternet_forward_app(void);
static void mmi_custser_monternet_sale_visit(void);
static void mmi_custser_entry_textviewer(void);
static void mmi_custser_entry_monternet_sms(void);
static void mmi_custser_entry_monternet_mms(void);

static void mmi_custser_entry_setting(void);
static void mmi_custser_entry_setting_hotline(void);
static void mmi_custser_exit_setting_hotline(void);
static void mmi_custser_setting_hotline_can_save(void);
static void mmi_custser_entry_setting_save_confirm(void);
static void mmi_custser_setting_save_change(void);
static void mmi_custser_exit_setting_manager(void);
static void mmi_custser_entry_setting_manager(void);
static void mmi_custser_setting_editor_goto_upper_screen(void);
static void mmi_custser_manager_editor_highlight_hdlr(S32 index);
static void mmi_custser_entry_manager_name_edit(void);
static void mmi_custser_entry_manager_name_edit_option(void);
static void mmi_custser_manager_name_edit_option_highlight_hdlr(S32 index);
static void mmi_custser_manager_name_edit_option_LSK(void);
static void mmi_custser_return_editor(void);

/*******************************************************
* Call Management
*******************************************************/
static void mmi_custser_make_call(void);

#if defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__)
static void mmi_custser_make_voip_call(void);
#endif 

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
mmi_custser_context_struct g_custser_context;


/*****************************************************************************
 * FUNCTION
 *  mmi_custser_init
 * DESCRIPTION
 *  Initialize each menu item hilite handler in custser app.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_custser_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_ID_CUSTSER_GUIDELINE, mmi_custser_highlight_guideline);
    SetHiliteHandler(MENU_ID_CUSTSER_SALE, mmi_custser_highlight_sale);
    SetHiliteHandler(MENU_ID_CUSTSER_HOTLINE, mmi_custser_highlight_make_call);
    SetHiliteHandler(MENU_ID_CUSTSER_MANAGER, mmi_custser_highlight_make_call);
    SetHiliteHandler(MENU_ID_CUSTSER_MYMONWAP, mmi_custser_highlight_mymonternet);
    SetHiliteHandler(MENU_ID_CUSTSER_SETTING_MANAGER, mmi_custser_highlight_setting_manager);
    SetHiliteHandler(MENU_ID_CUSTSER_SETTING_HOTLINE, mmi_custser_highlight_setting_hotline);
    SetHiliteHandler(MENU_ID_CUSTSER_SETTING, mmi_custser_highlight_setting);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_custser_entry_main_menu
 * DESCRIPTION
 *  customer service entry screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_custser_entry_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[MAX_SUB_MENUS];
    U16 ItemIcons[MAX_SUB_MENUS];
    U16 nItems;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CUSTSER_LIST, NULL, mmi_custser_entry_main_menu, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_CUSTSER_LIST);
    nItems = GetNumOfChild(MAIN_MENU_CUST_SERVICES_MENUID);
    GetSequenceStringIds(MAIN_MENU_CUST_SERVICES_MENUID, ItemList);
    GetSequenceImageIds(MAIN_MENU_CUST_SERVICES_MENUID, ItemIcons);
    SetParentHandler(MAIN_MENU_CUST_SERVICES_MENUID);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_ID_CUSTSER_TITLE,
        GetRootTitleIcon(MAIN_MENU_CUST_SERVICES_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        ItemList,
        ItemIcons,
        0,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_custser_highlight_guideline
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_custser_highlight_guideline(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_custser_context.textview_data.title_icon_id = GetRootTitleIcon(MAIN_MENU_CUST_SERVICES_MENUID);
    g_custser_context.textview_data.title_str_id = STR_ID_CUSTSER_GUIDELINE;
    g_custser_context.textview_data.content_str_id = STR_ID_CUSTSER_GUIDELINE_CONTENT;
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_custser_entry_textviewer, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_custser_entry_textviewer, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_custser_highlight_sale
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_custser_highlight_sale(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_custser_monternet_sale_visit, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_custser_monternet_sale_visit, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_custser_highlight_setting_manager
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_custser_highlight_setting_manager(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(
        NVRAM_EF_CUSTSER_SETTING_LID,
        1,
        (void*)&g_custser_context.setting_data,
        NVRAM_EF_CUSTSER_SETTING_SIZE,
        &error);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_custser_entry_setting_manager, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_custser_entry_setting_manager, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_custser_highlight_setting_hotline
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_custser_highlight_setting_hotline(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_custser_entry_setting_hotline, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_custser_entry_setting_hotline, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_custser_highlight_mymonternet
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_custser_highlight_mymonternet(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_custser_entry_mymonternet, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_custser_entry_mymonternet, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_custser_highlight_make_call_generic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lskfunc     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_custser_highlight_make_call_generic(FuncPtr lskfunc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    SetLeftSoftkeyFunction(lskfunc, KEY_EVENT_UP);
    SetKeyHandler(lskfunc, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_custser_highlight_make_call
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_custser_highlight_make_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 hilite_menuid = 0;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(
        NVRAM_EF_CUSTSER_SETTING_LID,
        1,
        (void*)&g_custser_context.setting_data,
        NVRAM_EF_CUSTSER_SETTING_SIZE,
        &error);

    hilite_menuid = GetCurrHiliteID();
    switch (hilite_menuid)
    {
        case MMI_CUSTSER_HILITE_HOTLINE:
            g_custser_context.pCurrHiliteNumber = g_custser_context.setting_data.HotlineNumber;
            break;

        case MMI_CUSTSER_HILITE_MANAGER:

            if (g_custser_context.setting_data.ManagerNumber[0] == 0)
            {
                mmi_custser_highlight_make_call_generic(mmi_custser_entry_setting_manager);
                return;
            }
            else
                g_custser_context.pCurrHiliteNumber = g_custser_context.setting_data.ManagerNumber;

            break;

        default:
            break;

    }

#if defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__)
    switch (mmi_netset_get_active_preferred_mode())
    {
        case P_WLAN_ONLY:
            mmi_custser_highlight_make_call_generic(mmi_custser_make_voip_call);

            break;

        case P_GSM_PREFERRED:
        case P_WLAN_PREFERRED:
            if (mmi_bootup_is_sim_valid())
            {
                mmi_custser_highlight_make_call_generic(mmi_netset_entry_dial_mode_selection);

                mmi_netset_register_call_entry_func(mmi_custser_make_call, mmi_custser_make_voip_call);
            }
            else
            {
                mmi_custser_highlight_make_call_generic(mmi_custser_make_voip_call);

            }
            break;

        case P_GSM_ONLY:
        default:
            mmi_custser_highlight_make_call_generic(mmi_custser_make_call);

            break;
    }
#else /* defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__) */ 
    mmi_custser_highlight_make_call_generic(mmi_custser_make_call);
#endif /* defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__) */ 
}

#if defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__)


/*****************************************************************************
 * FUNCTION
 *  mmi_custser_make_voip_call
 * DESCRIPTION
 *  functions to ooxx
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_custser_make_voip_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_voip_app_make_call((PU8) g_custser_context.pCurrHiliteNumber);

}
#endif /* defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_custser_make_call
 * DESCRIPTION
 *  functions to ooxx
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_custser_make_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MakeCall((PS8) g_custser_context.pCurrHiliteNumber);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_custser_monternet_sale_visit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_custser_monternet_sale_visit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wap_start_browser(WAP_BROWSER_GOTO_URL, p_sales_url);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_custser_entry_monternet_sms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_custser_entry_monternet_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_custser_context.textview_data.title_icon_id = GetRootTitleIcon(MAIN_MENU_CUST_SERVICES_MENUID);
    g_custser_context.textview_data.title_str_id = STR_ID_CUSTSER_MONWAP_SMS;
    g_custser_context.textview_data.content_str_id = STR_ID_CUSTSER_MONWAP_SMS_CONTENT;
    mmi_custser_entry_textviewer();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_custser_entry_monternet_mms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_custser_entry_monternet_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_custser_context.textview_data.title_icon_id = GetRootTitleIcon(MAIN_MENU_CUST_SERVICES_MENUID);
    g_custser_context.textview_data.title_str_id = STR_ID_CUSTSER_MONWAP_MMS;
    g_custser_context.textview_data.content_str_id = STR_ID_CUSTSER_MONWAP_MMS_CONTENT;
    mmi_custser_entry_textviewer();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_custser_highlight_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_custser_highlight_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_custser_entry_setting, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_custser_entry_setting, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_custser_entry_setting
 * DESCRIPTION
 *  pim menu list entry screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_custser_entry_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[MAX_SUB_MENUS];
    U16 nItems;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CUSTSER_SETTING_LIST, NULL, mmi_custser_entry_setting, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_CUSTSER_SETTING_LIST);
    nItems = GetNumOfChild(MENU_ID_CUSTSER_SETTING);
    GetSequenceStringIds(MENU_ID_CUSTSER_SETTING, ItemList);
    SetParentHandler(MENU_ID_CUSTSER_SETTING);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_ID_CUSTSER_SETTING,
        GetRootTitleIcon(MAIN_MENU_CUST_SERVICES_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        ItemList,
        (PU16) gIndexIconsImageList,
        0,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_custser_entry_textviewer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_custser_entry_textviewer(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PS8 buffer;
    S32 bufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CUSTSER_TEXTVIEWER, NULL, mmi_custser_entry_textviewer, NULL);
    buffer = GetString(g_custser_context.textview_data.content_str_id);
    bufferSize = mmi_ucs2strlen(buffer);
    ShowCategory74Screen(
        g_custser_context.textview_data.title_str_id,
        g_custser_context.textview_data.title_icon_id,
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) buffer,
        bufferSize,
        NULL);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_custser_entry_mymonternet
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_custser_entry_mymonternet(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *str_buf;
    S8 *text_buf;
    S32 text_size;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CUSTSER_MYMONWAP, NULL, mmi_custser_entry_mymonternet, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_CUSTSER_MYMONWAP);
    if (guiBuffer == NULL)
    {
        g_custser_context.mymonternet_data.selected_hilight_idx = 0;
    }

    text_buf = GetString(STR_ID_CUSTSER_MYMONWAP_CONTENT);
    text_size = mmi_ucs2strlen(text_buf);

    str_buf = GetString(STR_ID_CUSTSER_MONWAP);
    g_custser_context.mymonternet_data.hilite_item[0].str_addr = mmi_ucs2str(text_buf, (S8*) str_buf) + ENCODING_LENGTH;
    g_custser_context.mymonternet_data.hilite_item[0].length = mmi_ucs2strlen(str_buf) - 1;

    str_buf = GetString(STR_ID_CUSTSER_MONWAP_SMS);
    g_custser_context.mymonternet_data.hilite_item[1].str_addr = mmi_ucs2str(text_buf, (S8*) str_buf);
    g_custser_context.mymonternet_data.hilite_item[1].length = mmi_ucs2strlen(str_buf);

    str_buf = GetString(STR_ID_CUSTSER_MONWAP_MMS);
    g_custser_context.mymonternet_data.hilite_item[2].str_addr = mmi_ucs2str(text_buf, (S8*) str_buf);
    g_custser_context.mymonternet_data.hilite_item[2].length = mmi_ucs2strlen(str_buf);

    ShowCategory228Screen(
        STR_ID_CUSTSER_MYMONWAP,
        GetRootTitleIcon(MAIN_MENU_CUST_SERVICES_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (U8*) text_buf,
        text_size,
        g_custser_context.mymonternet_data.hilite_item,
        MMI_CUSTSER_MYMONWAP_TOTAL,
        mmi_custser_mymonternet_callback,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_custser_mymonternet_forward_app, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_custser_mymonternet_callback
 * DESCRIPTION
 *  S32 selected_idx: current selected index
 * PARAMETERS
 *  selected_idx        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_custser_mymonternet_callback(S32 selected_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_custser_context.mymonternet_data.selected_hilight_idx = selected_idx;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_custser_mymonternet_forward_app
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_custser_mymonternet_forward_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_custser_context.mymonternet_data.selected_hilight_idx)
    {
        case MMI_CUSTSER_MYMONWAP_MONWAP:
            wap_start_browser(WAP_BROWSER_GOTO_URL, p_monternet_url);
            break;

        case MMI_CUSTSER_MYMONWAP_SMS:
            mmi_custser_entry_monternet_sms();
            break;

        case MMI_CUSTSER_MYMONWAP_MMS:
            mmi_custser_entry_monternet_mms();
            break;

        default:
            /* shall not enter here */
            MMI_ASSERT(0);
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_custser_entry_setting_manager
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_custser_entry_setting_manager(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CUSTSER_SETTING_MANAGER, mmi_custser_exit_setting_manager, NULL, NULL);
    InitializeCategory57Screen();
    inputBuffer = GetCurrNInputBuffer(SCR_ID_CUSTSER_SETTING_MANAGER, &inputBufferSize);
    RegisterHighlightHandler(mmi_custser_manager_editor_highlight_hdlr);

    if ((guiBuffer = GetCurrGuiBuffer(SCR_ID_CUSTSER_SETTING_MANAGER)) == NULL)
    {
        g_custser_context.name_edit_data.isModified = MMI_FALSE;
    }

    SetInlineItemActivation(&wgui_inline_items[0], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[0], (U8*) (GetString(STR_ID_CUSTSER_SETTING_MANAGER_NAME)));
    SetInlineItemActivation(&wgui_inline_items[2], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[2], (U8*) (GetString(STR_ID_CUSTSER_SETTING_MANAGER_NUM)));

    SetInlineItemActivation(&wgui_inline_items[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemDisplayOnly(&wgui_inline_items[1], (U8*) g_custser_context.setting_data.ManagerName);

    SetInlineItemActivation(&wgui_inline_items[3], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemTextEdit(
        &wgui_inline_items[3],
        (PU8) g_custser_context.setting_data.ManagerNumber,
        MAX_PB_NUMBER_LENGTH + 1,
        INPUT_TYPE_PHONE_NUMBER | INPUT_TYPE_PLUS_CHARACTER_HANDLING);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, 4, inputBuffer);
    }

    DisableCategory57ScreenDone();

    ShowCategory57Screen(
        STR_ID_CUSTSER_MANAGER,
        GetRootTitleIcon(MAIN_MENU_CUST_SERVICES_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        4,
        NULL,
        wgui_inline_items,
        0,
        guiBuffer);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_custser_manager_editor_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_custser_manager_editor_highlight_hdlr(S32 index)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == 1) /* edit channel name */
    {
        ChangeLeftSoftkey(STR_GLOBAL_EDIT, 0);
        SetCategory57LeftSoftkeyFunction(mmi_custser_entry_manager_name_edit);
        if (g_custser_context.name_edit_data.isModified)
        {
            ChangeRightSoftkey(STR_GLOBAL_DONE, 0);
            SetCategory57RightSoftkeyFunctions(
                mmi_custser_entry_setting_save_confirm,
                mmi_custser_entry_setting_save_confirm);
        }
        else
        {
            SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);
        }
    }
    else
    {
        SetCategory57LeftSoftkeyFunction(mmi_custser_entry_setting_save_confirm);
        SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_custser_entry_manager_name_edit
 * DESCRIPTION
 *  manager name full screen editor entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_custser_entry_manager_name_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CUSTSER_SETTING_MANAGER_NAME, NULL, mmi_custser_entry_manager_name_edit, NULL);

    if ((gui_buffer = GetCurrGuiBuffer(SCR_ID_CUSTSER_SETTING_MANAGER_NAME)) == NULL)
    {
        mmi_ucs2cpy(
            (S8*) g_custser_context.name_edit_data.name_text_editor_buffer,
            (S8*) g_custser_context.setting_data.ManagerName);
    }

    ShowCategory5Screen(
        STR_ID_CUSTSER_SETTING_MANAGER_NAME,
        GetRootTitleIcon(MAIN_MENU_CUST_SERVICES_MENUID),
        STR_GLOBAL_OPTIONS,
        0,
        STR_GLOBAL_BACK,
        0,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        (U8*) g_custser_context.name_edit_data.name_text_editor_buffer,
        MAX_PB_NAME_LENGTH + 1,
        gui_buffer);

    SetLeftSoftkeyFunction(mmi_custser_entry_manager_name_edit_option, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    RegisterInputMethodScreenCloseFunction(mmi_custser_return_editor);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_custser_return_editor
 * DESCRIPTION
 *  return to the full editor screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_custser_return_editor(void)
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
 *  mmi_custser_entry_manager_name_edit_option
 * DESCRIPTION
 *  manager name editor option menu list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_custser_entry_manager_name_edit_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    U16 item_texts[] = {STR_GLOBAL_DONE, STR_GLOBAL_INPUT_METHOD};
    U16 item_icons[] = {IMG_GLOBAL_L1, IMG_GLOBAL_L2};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CUSTSER_SETTING_MANAGER_NAME_OPTION, NULL, mmi_custser_entry_manager_name_edit_option, NULL);
    gui_buffer = GetCurrGuiBuffer(SCR_ID_CUSTSER_SETTING_MANAGER_NAME_OPTION);

    RegisterHighlightHandler(mmi_custser_manager_name_edit_option_highlight_hdlr);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MAIN_MENU_CUST_SERVICES_MENUID),
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        2,
        item_texts,
        item_icons,
        NULL,
        0,
        0,
        gui_buffer);

    /* register left, right arrow key handlers */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_custser_manager_name_edit_option_LSK, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* register LSK, RSK handlers */
    SetLeftSoftkeyFunction(mmi_custser_manager_name_edit_option_LSK, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_custser_manager_name_edit_option_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_custser_manager_name_edit_option_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_custser_context.name_edit_data.option_index = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_custser_manager_name_edit_option_LSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_custser_manager_name_edit_option_LSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_custser_context.name_edit_data.option_index)
    {
        case 0:
            mmi_ucs2cpy(
                (S8*) g_custser_context.setting_data.ManagerName,
                (S8*) g_custser_context.name_edit_data.name_text_editor_buffer);
            g_custser_context.name_edit_data.isModified = MMI_TRUE;
            GoBackToHistory(SCR_ID_CUSTSER_SETTING_MANAGER);
            break;
        case 1:
            EntryInputMethodScreen();
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_custser_entry_setting_hotline
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_custser_entry_setting_hotline(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CUSTSER_SETTING_HOTLINE, mmi_custser_exit_setting_hotline, NULL, NULL);
    InitializeCategory57Screen();
    guiBuffer = GetCurrGuiBuffer(SCR_ID_CUSTSER_SETTING_HOTLINE);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_CUSTSER_SETTING_HOTLINE, &inputBufferSize);
    SetInlineItemActivation(&wgui_inline_items[0], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[0], (U8*) (GetString(STR_ID_CUSTSER_SETTING_MANAGER_NUM)));

    ReadRecord(
        NVRAM_EF_CUSTSER_SETTING_LID,
        1,
        (void*)&g_custser_context.setting_data,
        NVRAM_EF_CUSTSER_SETTING_SIZE,
        &error);

    SetInlineItemActivation(&wgui_inline_items[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemTextEdit(
        &wgui_inline_items[1],
        (PU8) g_custser_context.setting_data.HotlineNumber,
        MAX_PB_NUMBER_LENGTH + 1,
        INPUT_TYPE_PHONE_NUMBER | INPUT_TYPE_PLUS_CHARACTER_HANDLING);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, 2, inputBuffer);
    }
    /* if (GetInlineDoneFlag(guiBuffer) == 0)
       {
       SetInlineDoneFlag(guiBuffer);
       } */
    DisableCategory57ScreenDone();

    ShowCategory57Screen(
        STR_ID_CUSTSER_HOTLINE,
        GetRootTitleIcon(MAIN_MENU_CUST_SERVICES_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        2,
        NULL,
        wgui_inline_items,
        0,
        guiBuffer);

    /* SetCategory57RightSoftkeyFunctions(mmi_custser_setting_hotline_can_save, GoBackHistory); */
    SetCategory57LeftSoftkeyFunction(mmi_custser_setting_hotline_can_save);
    SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_custser_exit_setting_manager
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_custser_exit_setting_manager(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    history h;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    h.scrnID = SCR_ID_CUSTSER_SETTING_MANAGER;
    h.entryFuncPtr = mmi_custser_entry_setting_manager;
    GetCategoryHistory(h.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, inputBufferSize);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_custser_exit_setting_hotline
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_custser_exit_setting_hotline(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    history h;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    h.scrnID = SCR_ID_CUSTSER_SETTING_HOTLINE;
    h.entryFuncPtr = mmi_custser_entry_setting_hotline;
    GetCategoryHistory(h.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, inputBufferSize);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_custser_setting_hotline_can_save
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_custser_setting_hotline_can_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_custser_context.setting_data.HotlineNumber[0] == 0)
    {
        DisplayPopup((U8*) GetString(STR_GLOBAL_EMPTY), IMG_GLOBAL_ERROR, 0, 1000, (U8) WARNING_TONE);

    }
    else
    {
        mmi_custser_entry_setting_save_confirm();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_custser_entry_setting_save_confirm
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_custser_entry_setting_save_confirm(void)
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
        get_string(STR_GLOBAL_SAVE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_custser_setting_save_change, KEY_EVENT_UP);

    SetRightSoftkeyFunction(mmi_custser_setting_editor_goto_upper_screen, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_custser_setting_save_change
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_custser_setting_save_change(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stopRequestedTone(WARNING_TONE);

    WriteRecord(
        NVRAM_EF_CUSTSER_SETTING_LID,
        1,
        (void*)&g_custser_context.setting_data,
        NVRAM_EF_CUSTSER_SETTING_SIZE,
        &error);

    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        SUCCESS_TONE);
    DeleteNHistory (1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_custser_setting_editor_goto_upper_screen
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_custser_setting_editor_goto_upper_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stopRequestedTone(WARNING_TONE);

    GoBacknHistory(1);
}
#endif /* __MMI_CUSTOMER_SERVICE__ */ 

