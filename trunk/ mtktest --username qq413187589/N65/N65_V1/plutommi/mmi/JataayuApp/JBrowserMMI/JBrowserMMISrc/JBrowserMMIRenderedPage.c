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
 * JBrowserMMIRenderedPage.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intended for rendered page options implementation.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"
#ifndef _MMI_JBROWSERMMIRENDEREDPAGE_C
#define _MMI_JBROWSERMMIRENDEREDPAGE_C

/*  Include: MMI header file */
#if defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT)
#include "SettingProfile.h"
#include "CommonScreens.h"
#include "wgui_inputs.h"
#include "OrganizerDef.h"
#include "DateTimeGprot.h"
#include "settingGprots.h"
#include "wgui_status_icons.h"
#include "JBrowserResDef.h"
#include "JBrowserMMIProts.h"
#include "JBrowserMMITypes.h"
#include "JBrowserMMIGprots.h"
#include "JProfileHandlerTypes.h"
#include "JProfileHandlerProts.h"
#include "FileManagerGProt.h"
#include "sat_def.h"
#include "USBDeviceGprot.h"
#ifdef __MMI_FILE_MANAGER__
#include "FileMgr.h"
#endif 
#ifdef __MMI_IRDA_SUPPORT__
#include "IrdaMMIGprots.h"
#endif 

/*  Include: NVRAM header file */

/* Included for file system */
#include "drm_gprot.h"
#include "ServiceDefs.h"        /* Added by Sandeep for Services menu Screen ID */

/*  Include: Jataayu header file */
#include "ddl.h"
#include "jcal.h"
#include "jdd_memapi.h"
#include "jdd_ui_datatypes.h"
#include "jdd_ui_window.h"
#include "jdd_ui_ResDef.h"

/* Vivek - 30082006 */
#ifdef __MMI_UNIFIED_MESSAGE__
#include "UnifiedMessageResDef.h"
#endif 

#ifdef __MMI_JATAAYU_BRW_ADVANCED_RENDERED_PAGE_OPTIONS__
#include "SMSApi.h"
#include "smsal_l4c_enum.h"
#include "MessagesMiscell.h"
#endif /* __MMI_JATAAYU_BRW_ADVANCED_RENDERED_PAGE_OPTIONS__ */ 

/* local */
static U8 g_mmi_brw_goto_menu_count = 0;
static U8 g_mmi_brw_select_menu_count = 0;

/* extern void jdd_MemSetActiveModuleID(ETaskID taskId); */


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_rendered_page_init
 * DESCRIPTION
 *  Set highlight handler for rendered page menu items
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_rendered_page_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* SetHiliteHandler(MENU_ID_BRW_REN_PAGE_GOTO, mmi_brw_ren_page_goto_highlight_hdlr); */
    SetHiliteHandler(MENU_ID_BRW_REN_PAGE_GOTO_HOMEPAGE, mmi_brw_ren_page_goto_homepage_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_REN_PAGE_REFRESH, mmi_brw_refresh_menu_highlight_hdlr);

    SetHiliteHandler(MENU_ID_BRW_DOWNLOAD, mmi_brw_download_menu_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_REN_PAGE_BOOKMARK, mmi_brw_bookmark_menu_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_REN_PAGE_RECENT_PAGES, mmi_brw_recent_pages_menu_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_REN_PAGE_ENTER_ADDRESS, mmi_brw_enter_address_menu_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_REN_PAGE_SET_AS_HOMEPAGE, mmi_brw_ren_page_set_as_homepage_menu_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_REN_PAGE_SERVICE_INBOX, mmi_brw_service_inbox_menu_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_REN_PAGE_SETTINGS, mmi_brw_ren_page_setting_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_REN_PAGE_EXIT, mmi_brw_exit_menu_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_REN_PAGE_ADD_TO_BOOKMARKS, mmi_brw_ren_page_add_to_bmk_highlight_hdlr);

#ifdef __MMI_JATAAYU_BRW_ADVANCED_RENDERED_PAGE_OPTIONS__
    SetHiliteHandler(MENU_ID_BRW_REN_PAGE_DISPLAY_CURRENT_URL, mmi_brw_ren_page_display_curr_url_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_REN_PAGE_SEND_LINK_VIA_SMS, mmi_brw_ren_page_send_link_via_sms_highlight_hdlr);
#endif /* __MMI_JATAAYU_BRW_ADVANCED_RENDERED_PAGE_OPTIONS__ */ 

#if defined WAP_SEC_SUPPORT
    SetHiliteHandler(MENU_ID_BRW_VIEW_CERTIFICATE, mmi_brw_view_server_certificate_highlight_hdlr);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_rendered_page_options
 * DESCRIPTION
 *  Deinitialize the browser application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_rendered_page_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret;
    JC_CTRL_INFO brw_ctrl_info_p;
    JC_MIME_INFO pmime_info;
    U16 parent_menu_id;
    U16 *uc_list_of_items;
    U8 *gui_buffer_p;
    S32 n_num_of_item;
    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jdd_MemSetActiveModuleID(E_TASK_BROWSER_UI);

    g_mmi_brw_goto_menu_count = 0;
    g_mmi_brw_select_menu_count = 0;
    /* Get the Control type */
    ret = jdi_BrowserGetCurrentControlInfo(g_mmi_brw_pbrowser_ctxt, &brw_ctrl_info_p);
    if (ret != JC_OK)
    {
        return;
    }

    if (brw_ctrl_info_p.uiControlID == 0)   /* No control is selected */
    {
    #ifdef WAP_SEC_SUPPORT
        if (g_mmi_brw_cert_ctxt.session_status == BRW_SECURE_SESSION_IN_PROGRESS)
        {
            parent_menu_id = MENU_ID_BRW_RENDERED_PAGE_OPTIONS_3;
        }
        else
        {
            parent_menu_id = MENU_ID_BRW_RENDERED_PAGE_OPTIONS_4;
        }
    #else /* WAP_SEC_SUPPORT */ 
        parent_menu_id = MENU_ID_BRW_RENDERED_PAGE_OPTIONS_4;
    #endif /* WAP_SEC_SUPPORT */ 
    }
    else
    {
        if ((brw_ctrl_info_p.eControlType == E_IMAGE) && g_mmi_brw_cntx.show_images)
        {
            if (g_mmi_brw_cntx.image_selection)
            {
            #ifdef WAP_SEC_SUPPORT
                if (g_mmi_brw_cert_ctxt.session_status == BRW_SECURE_SESSION_IN_PROGRESS)
                {
                    parent_menu_id = MENU_ID_BRW_RENDERED_PAGE_OPTIONS_2;
                }
                else
                {
                    parent_menu_id = MENU_ID_BRW_RENDERED_PAGE_OPTIONS_1;
                }
            #else /* WAP_SEC_SUPPORT */ 
                parent_menu_id = MENU_ID_BRW_RENDERED_PAGE_OPTIONS_1;
            #endif /* WAP_SEC_SUPPORT */ 
                if (brw_ctrl_info_p.bIsSelectable)
                {
                    g_mmi_brw_goto_menu_count = 1;
                }
            }
            else
            {
            #ifdef WAP_SEC_SUPPORT
                if (g_mmi_brw_cert_ctxt.session_status == BRW_SECURE_SESSION_IN_PROGRESS)
                {
                    parent_menu_id = MENU_ID_BRW_RENDERED_PAGE_OPTIONS_3;
                }
                else
                {
                    parent_menu_id = MENU_ID_BRW_RENDERED_PAGE_OPTIONS_4;
                }
            #else /* WAP_SEC_SUPPORT */ 
                parent_menu_id = MENU_ID_BRW_RENDERED_PAGE_OPTIONS_4;
            #endif /* WAP_SEC_SUPPORT */ 
                if (brw_ctrl_info_p.bIsSelectable)
                {
                    g_mmi_brw_goto_menu_count = 1;
                }
            }
        }
        else if ((brw_ctrl_info_p.eControlType == E_TEXT_BOX) || (brw_ctrl_info_p.eControlType == E_IMAGE_TEXT) ||
                 (brw_ctrl_info_p.eControlType == E_BUTTON))
        {
        #ifdef WAP_SEC_SUPPORT
            if (g_mmi_brw_cert_ctxt.session_status == BRW_SECURE_SESSION_IN_PROGRESS)
            {
                parent_menu_id = MENU_ID_BRW_RENDERED_PAGE_OPTIONS_3;
            }
            else
            {
                parent_menu_id = MENU_ID_BRW_RENDERED_PAGE_OPTIONS_4;
            }
        #else /* WAP_SEC_SUPPORT */ 
            parent_menu_id = MENU_ID_BRW_RENDERED_PAGE_OPTIONS_4;
        #endif /* WAP_SEC_SUPPORT */ 
            if (brw_ctrl_info_p.bIsSelectable)
            {
                g_mmi_brw_goto_menu_count = 1;
            }
        }
        else if (brw_ctrl_info_p.eControlType == E_INPUT_BOX || brw_ctrl_info_p.eControlType == E_RADIO_BOX ||
                 brw_ctrl_info_p.eControlType == E_CHECK_BOX)
        {
        #ifdef WAP_SEC_SUPPORT
            if (g_mmi_brw_cert_ctxt.session_status == BRW_SECURE_SESSION_IN_PROGRESS)
            {
                parent_menu_id = MENU_ID_BRW_RENDERED_PAGE_OPTIONS_3;
            }
            else
            {
                parent_menu_id = MENU_ID_BRW_RENDERED_PAGE_OPTIONS_4;
            }
        #else /* WAP_SEC_SUPPORT */ 
            parent_menu_id = MENU_ID_BRW_RENDERED_PAGE_OPTIONS_4;
        #endif /* WAP_SEC_SUPPORT */ 
            g_mmi_brw_select_menu_count = 1;
        }
        else if (brw_ctrl_info_p.eControlType == E_COMBO_BOX || brw_ctrl_info_p.eControlType == E_LIST_BOX)
        {
        #ifdef WAP_SEC_SUPPORT
            if (g_mmi_brw_cert_ctxt.session_status == BRW_SECURE_SESSION_IN_PROGRESS)
            {
                parent_menu_id = MENU_ID_BRW_RENDERED_PAGE_OPTIONS_3;
            }
            else
            {
                parent_menu_id = MENU_ID_BRW_RENDERED_PAGE_OPTIONS_4;
            }
        #else /* WAP_SEC_SUPPORT */ 
            parent_menu_id = MENU_ID_BRW_RENDERED_PAGE_OPTIONS_4;
        #endif /* WAP_SEC_SUPPORT */ 
            if (jdi_BrowserGetNumberOfItemOfCtrl(g_mmi_brw_pbrowser_ctxt, brw_ctrl_info_p.uiControlID) > 0)
            {
                g_mmi_brw_select_menu_count = 1;
            }
        }
        else
        {
        #ifdef WAP_SEC_SUPPORT
            if (g_mmi_brw_cert_ctxt.session_status == BRW_SECURE_SESSION_IN_PROGRESS)
            {
                parent_menu_id = MENU_ID_BRW_RENDERED_PAGE_OPTIONS_3;
            }
            else
            {
                parent_menu_id = MENU_ID_BRW_RENDERED_PAGE_OPTIONS_4;
            }
        #else /* WAP_SEC_SUPPORT */ 
            parent_menu_id = MENU_ID_BRW_RENDERED_PAGE_OPTIONS_4;
        #endif /* WAP_SEC_SUPPORT */ 
        }
    }
    jdi_BrowserGetCurrentControlMimeInfo(g_mmi_brw_pbrowser_ctxt, &pmime_info);
    g_mmi_brw_cntx.used_do_element_count = g_mmi_brw_cntx.do_element_count;
    n_num_of_item =
        g_mmi_brw_select_menu_count + g_mmi_brw_goto_menu_count + GetNumOfChild(parent_menu_id) +
        g_mmi_brw_cntx.used_do_element_count;
    if (n_num_of_item > MMI_BRW_MAX_DO_ELEMENTS)
    {
        g_mmi_brw_cntx.used_do_element_count =
            MMI_BRW_MAX_DO_ELEMENTS - (GetNumOfChild(parent_menu_id) + g_mmi_brw_goto_menu_count +
                                       g_mmi_brw_select_menu_count);
        n_num_of_item = MMI_BRW_MAX_DO_ELEMENTS;
    }

    uc_list_of_items = (U16*) jdd_MemAlloc(n_num_of_item, sizeof(U16));
    if (uc_list_of_items == NULL)
    {
        jdd_MMINotificationMessage((JC_INT32) JC_ERR_MEMORY_ALLOCATION, E_NOTIFICATION_ERR, NULL, NULL);
        return;
    }
    GetSequenceStringIds(parent_menu_id, uc_list_of_items);
    /* This variable was set when we try to fetch a page through EnterAddress Option
       screen. Reset this flag to 0 when second page fetch from render page's Eneter Adress throws error. */
    g_mmi_brw_cntx.enter_add_hist_flag = 0;
    /*
     * nStrItemList = (PU8*) jdd_MemAlloc((n_num_of_item + 1), sizeof(PU8));
     * if (nStrItemList == NULL)
     * {
     * if (uc_list_of_items != NULL)
     * {
     * jdd_MemFree(uc_list_of_items);
     * uc_list_of_items = NULL;
     * }
     * jdd_MMINotificationMessage((JC_INT32) JC_ERR_MEMORY_ALLOCATION, E_NOTIFICATION_ERR, NULL, NULL);
     * return;
     * 
     * }
     */
    EntryNewScreen(SCR_ID_BRW_RENDERED_PAGE_OPTIONS, NULL, mmi_brw_rendered_page_options, NULL);
    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_BRW_RENDERED_PAGE_OPTIONS);
    SetParentHandler(parent_menu_id);

    memset(subMenuDataPtrs, 0, sizeof(subMenuDataPtrs));

    /* for Select or Edit menu */
    if (g_mmi_brw_select_menu_count != 0)
    {
        if (brw_ctrl_info_p.eControlType == E_INPUT_BOX)
        {
            subMenuDataPtrs[0] = (PU8) GetString(STR_ID_BRW_REN_PAGE_EDIT);
        }
        else
        {
            subMenuDataPtrs[0] = (PU8) GetString(STR_ID_BRW_REN_PAGE_SELECT);
        }
    }

    /* for GoTo menu */
    if (g_mmi_brw_goto_menu_count != 0)
    {
        subMenuDataPtrs[g_mmi_brw_select_menu_count + g_mmi_brw_goto_menu_count - 1] = (PU8) GetString(STR_ID_BRW_GOTO);
    }

    /* Do elements have to be shown in the begining of the list if exist on the page */
    for (count = g_mmi_brw_select_menu_count + g_mmi_brw_goto_menu_count;
         count < (g_mmi_brw_cntx.used_do_element_count + g_mmi_brw_goto_menu_count + g_mmi_brw_select_menu_count);
         count++)
    {
        subMenuDataPtrs[count] =
            (PU8) g_mmi_brw_cntx.do_element_list[count - g_mmi_brw_goto_menu_count -
                                                 g_mmi_brw_select_menu_count]->pDoLabel;
    }

    for (count = (g_mmi_brw_cntx.used_do_element_count + g_mmi_brw_goto_menu_count + g_mmi_brw_select_menu_count);
         count < n_num_of_item; count++)
    {
        subMenuDataPtrs[count] =
            (PU8)
            GetString(uc_list_of_items
                      [count -
                       (g_mmi_brw_cntx.used_do_element_count + g_mmi_brw_goto_menu_count +
                        g_mmi_brw_select_menu_count)]);
    }
    if (uc_list_of_items != NULL)
    {
        jdd_MemFree(uc_list_of_items);
        uc_list_of_items = NULL;
    }

    RegisterHighlightHandler(mmi_brw_rendered_page_highlight_hdlr);

    ShowCategory84Screen(
        STR_ID_BRW_OPTION,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        n_num_of_item,
        subMenuDataPtrs,
        (U16*) gIndexIconsImageList,
        0,
        0,
        gui_buffer_p);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    mmi_brw_ren_page_handle_do_element();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_rendered_page_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for rendered page are registered with this function
 * PARAMETERS
 *  index       [IN]        Index of highlighted item
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_rendered_page_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index < g_mmi_brw_select_menu_count)
    {
        SetLeftSoftkeyFunction(mmi_brw_ren_page_select, KEY_EVENT_UP);
    }
    else if (index < g_mmi_brw_select_menu_count + g_mmi_brw_goto_menu_count)
    {
        /* Do Nothing, Do element is present at the index */
        SetLeftSoftkeyFunction(mmi_brw_ren_page_goto, KEY_EVENT_UP);
    }
    else if (index < (g_mmi_brw_select_menu_count + g_mmi_brw_goto_menu_count + g_mmi_brw_cntx.used_do_element_count))
    {
        /* Do Nothing, Do element is present at the index */
        SetLeftSoftkeyFunction(mmi_brw_ren_page_process_do_element, KEY_EVENT_UP);
    }
    else
    {
        ExecuteCurrHiliteHandler(index -
                                 (g_mmi_brw_cntx.used_do_element_count + g_mmi_brw_goto_menu_count +
                                  g_mmi_brw_select_menu_count));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_select
 * DESCRIPTION
 *  Function to handle Edit/Select menu option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Rendered Page Option Screen should not go into history when we select/edit */
    ClearExitHandler();
    mmi_jdd_ui_wap_key_hdlr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_download_menu_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for download option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_download_menu_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_ren_page_download_image, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_ren_page_download_image, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
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
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_goto
 * DESCRIPTION
 *  Function to fetch link from rendered page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_goto(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_fill_control_info_and_send_event_to_queue();
    g_mmi_brw_page_cntx.brw_is_refresh_display = MMI_TRUE;
    mmi_brw_clear_brw_soft_keys();
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_goto_homepage_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for goto homepage option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_goto_homepage_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_entry_ren_page_goto_homepage, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_entry_ren_page_goto_homepage
 * DESCRIPTION
 *  Highlight handler for goto homepage option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_entry_ren_page_goto_homepage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_valid_url = MMI_FALSE;
    U8 curr_act_profile_url[MMI_BRW_WAP_PROFILE_HOMEPAGE_URL_LEN * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jc_strcpy(curr_act_profile_url, mmi_ph_brw_get_activated_profile_homepage());
    mmi_asc_to_ucs2((S8*) g_mmi_brw_cntx.brw_current_url, (S8*) curr_act_profile_url);
    is_valid_url = mmi_brw_validate_url(g_mmi_brw_cntx.brw_current_url);
    if (is_valid_url == MMI_TRUE)
    {
        mmi_brw_set_current_url((S8*) g_mmi_brw_cntx.brw_current_url);
        g_mmi_brw_page_cntx.brw_is_refresh_display = MMI_TRUE;
        mmi_brw_clear_brw_soft_keys();
        g_mmi_brw_page_cntx.brw_option_refresh_page = TRUE; /* This flag prevents to refresh the controls on current page */
        GoBackHistory();
        g_mmi_brw_page_cntx.brw_option_refresh_page = FALSE;
        mmi_brw_goto_url();
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_ID_BRW_INVALID_URL), IMG_GLOBAL_ERROR, 1, MMI_BRW_POPUP_TIME, ERROR_TONE);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_refresh_menu_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for refresh option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_refresh_menu_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_refresh_page, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_refresh_page
 * DESCRIPTION
 *  Handler for refresh option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_refresh_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_brw_page_cntx.brw_option_refresh_page = TRUE;
    g_mmi_brw_page_cntx.brw_is_refresh_display = MMI_TRUE;
    mmi_brw_clear_brw_soft_keys();
    GoBackHistory();
    g_mmi_brw_page_cntx.brw_option_refresh_page = FALSE;
    mmi_brw_jbrowser_refresh_page();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_is_refresh_page_pressed
 * DESCRIPTION
 *  Handler for refresh option
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mmi_brw_is_refresh_page_pressed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_brw_page_cntx.brw_option_refresh_page;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_set_as_homepage_menu_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler set as homepage option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_set_as_homepage_menu_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_ren_page_set_as_hompage, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_set_as_hompage
 * DESCRIPTION
 *  Handler for set as homepage option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_set_as_hompage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_PAGE_INFO brw_page_info;
    U32 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jdi_BrowserGetCurrentPageInfo(g_mmi_brw_pbrowser_ctxt, &brw_page_info);
    if (brw_page_info.psUrl)
    {
        len = mmi_ucs2strlen((S8*) brw_page_info.psUrl);
        if (len >= NVRAM_WAP_PROFILE_HOMEPAGE_URL_LEN)
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_BRW_URL_LEN_EXCEED),
                IMG_GLOBAL_ERROR,
                1,
                MMI_BRW_POPUP_TIME,
                ERROR_TONE);
        }
        else
        {
            mmi_ucs2cpy((S8*) g_mmi_brw_cntx.brw_current_url, (S8*) brw_page_info.psUrl);

            if (mmi_brw_validate_url(g_mmi_brw_cntx.brw_current_url))
            {
                mmi_brw_set_as_homepage(g_mmi_brw_cntx.brw_current_url);
            }
            else
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_BRW_INVALID_URL),
                    IMG_GLOBAL_ERROR,
                    1,
                    MMI_BRW_POPUP_TIME,
                    ERROR_TONE);
            }

        }
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_ID_BRW_INVALID_URL), IMG_GLOBAL_ERROR, 1, MMI_BRW_POPUP_TIME, ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_exit_menu_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for exit option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_exit_menu_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_entry_exit_menu, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_entry_exit_menu
 * DESCRIPTION
 *  Exit menu handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_entry_exit_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_wap_deinit();
    /* Free the DO List for last rendered page */
    mmi_brw_free_do_list();
    if (!(GetActiveScreenId() == SCR_ID_BRW_JBROWSER_MAIN))
    {
        /* Delete the rendered page from history */
        DeleteNHistory(1);
    }

#ifdef __SAT__
    if (g_mmi_brw_cntx.is_saturl == E_TRUE)
    {
        mmi_brw_send_termination_to_mmi(SAT_BROWSER_USER_TERMINATION);
    }
#endif /* __SAT__ */ 

    if (IsScreenPresent(SCR_ID_BRW_INTERNET_SERVICES))
    {
        DeleteNScrId(SCR_ID_BRW_INTERNET_SERVICES);
    }

    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_handle_do_element
 * DESCRIPTION
 *  Handle do tag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_handle_do_element()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 curr_highlighted_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curr_highlighted_item = GetHighlightedItem();

    if ((curr_highlighted_item >= g_mmi_brw_goto_menu_count + g_mmi_brw_select_menu_count) &&
        (curr_highlighted_item <
         (g_mmi_brw_cntx.used_do_element_count + g_mmi_brw_goto_menu_count + g_mmi_brw_select_menu_count)))
    {
        SetLeftSoftkeyFunction(mmi_brw_ren_page_process_do_element, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_process_do_element
 * DESCRIPTION
 *  process the do element on the page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_process_do_element()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 curr_highlighted_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curr_highlighted_index = GetHighlightedItem();
    g_mmi_brw_page_cntx.brw_is_refresh_display = MMI_TRUE;
    mmi_brw_clear_brw_soft_keys();

    GoBackHistory();

    jdi_BrowserProcessDoElement(
        g_mmi_brw_pbrowser_ctxt,
        g_mmi_brw_cntx.do_element_list[(curr_highlighted_index - g_mmi_brw_goto_menu_count - g_mmi_brw_select_menu_count)]);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_free_do_list
 * DESCRIPTION
 *  Free the do element list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_free_do_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_brw_cntx.do_element_list != NULL)
    {
        for (count = 0; count < g_mmi_brw_cntx.do_element_count; count++)
        {
            if (g_mmi_brw_cntx.do_element_list[count] != NULL)
            {
                if (g_mmi_brw_cntx.do_element_list[count]->pDoLabel != NULL)
                {
                    jdd_MemFree(g_mmi_brw_cntx.do_element_list[count]->pDoLabel);
                    g_mmi_brw_cntx.do_element_list[count]->pDoLabel = NULL;
                }

                if (g_mmi_brw_cntx.do_element_list[count]->pDoType != NULL)
                {
                    jdd_MemFree(g_mmi_brw_cntx.do_element_list[count]->pDoType);
                    g_mmi_brw_cntx.do_element_list[count]->pDoType = NULL;
                }

                jdd_MemFree(g_mmi_brw_cntx.do_element_list[count]);
                g_mmi_brw_cntx.do_element_list[count] = NULL;
            }
        }

        jdd_MemFree(g_mmi_brw_cntx.do_element_list);
        g_mmi_brw_cntx.do_element_list = NULL;
        g_mmi_brw_cntx.do_element_count = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_download_image
 * DESCRIPTION
 *  Function to doanload the embedded image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_download_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret;
    JC_MIME_INFO pmime_info;
    JC_MIME_INFO pmime_info_dl;
    JC_CHAR *filename_p = NULL;
    JDD_FSHANDLE fs_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        mmi_usb_app_unavailable_popup(0);
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    jdi_BrowserGetCurrentControlMimeInfo(g_mmi_brw_pbrowser_ctxt, &pmime_info);
    jdd_FSGetDownloadFileName(&filename_p);

    if ((ret = jdd_FSInitialize(&fs_handle)) == JC_OK)
    {
        JC_CHAR *content_fname;

        content_fname = (JC_CHAR*) jdd_FSFileNameTranslate(fs_handle, (JC_CHAR*) pmime_info.psFileName);
        if (content_fname == NULL)
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_JATAAYU_JDD_BROWSER_NOT_ENOUGH_MEMORY),
                IMG_GLOBAL_ERROR,
                0,
                MMI_BRW_POPUP_TIME,
                ERROR_TONE);
            jdd_FSDeinitialize(fs_handle);
            return;
        }
        else
        {
            ret = jdd_FSMoveExt(NULL, (JC_UINT16*) content_fname, NULL, (JC_UINT16*) filename_p, E_MOVE_COPY);
            if (ret != JC_OK)
            {
                ret = jdd_GetFSLastErrCode(jdd_MemGetActiveModuleID());
                if (ret == JC_ERR_FILE_FULL)
                {
                    /* changes for memory card */
                    if (fmgr_is_msdc_present()) /* Memory Card present */
                    {
                        PRINT_INFORMATION_2(MMI_TRACE_INFO, "Memory Card Present");
                        if (filename_p != NULL)
                        {
                            jdd_MemFree(filename_p);
                            filename_p = NULL;
                        }

                        filename_p = mmi_brw_get_temp_path_on_ext_mem(pmime_info.psUrl);
                        if (filename_p == NULL)
                        {
                            jdd_FSDeinitialize(fs_handle);
                            jdd_MemFree(content_fname);
                            return;
                        }

                        ret = jdd_FSMoveExt(
                                NULL,
                                (JC_UINT16*) content_fname,
                                NULL,
                                (JC_UINT16*) filename_p,
                                E_MOVE_COPY);
                        jdd_FSDeinitialize(fs_handle);
                        jdd_MemFree(content_fname);

                        if (ret != JC_OK)
                        {
                            ret = jdd_GetFSLastErrCode(jdd_MemGetActiveModuleID());
                            if (ret == JC_ERR_FILE_FULL)
                            {
                                DisplayPopup(
                                    (PU8) GetString(STR_ID_JATAAYU_JDD_BROWSER_FILE_SYSTEM_FULL),
                                    IMG_GLOBAL_ERROR,
                                    0,
                                    MMI_BRW_POPUP_TIME,
                                    ERROR_TONE);
                            }
                            else
                            {
                                DisplayPopup(
                                    (PU8) GetString(STR_ID_BRW_FILE_SAVE_FAILED),
                                    IMG_GLOBAL_ERROR,
                                    0,
                                    MMI_BRW_POPUP_TIME,
                                    ERROR_TONE);
                            }
                            if (filename_p != NULL)
                            {
                                jdd_MemFree(filename_p);
                                filename_p = NULL;
                            }
                            return;
                        }
                    }
                    else
                    {
                        PRINT_INFORMATION_2(MMI_TRACE_INFO, "Memory Card Not Present");
                        jdd_FSDeinitialize(fs_handle);
                        jdd_MemFree(content_fname);

                        if (filename_p != NULL)
                        {
                            jdd_MemFree(filename_p);
                            filename_p = NULL;
                        }

                        DisplayPopup(
                            (PU8) GetString(STR_ID_JATAAYU_JDD_BROWSER_FILE_SYSTEM_FULL),
                            IMG_GLOBAL_ERROR,
                            0,
                            MMI_BRW_POPUP_TIME,
                            ERROR_TONE);

                        return;
                    }
                }
                else
                {
                    jdd_FSDeinitialize(fs_handle);
                    jdd_MemFree(content_fname);

                    if (filename_p != NULL)
                    {
                        jdd_MemFree(filename_p);
                        filename_p = NULL;
                    }

                    DisplayPopup(
                        (PU8) GetString(STR_ID_BRW_FILE_SAVE_FAILED),
                        IMG_GLOBAL_ERROR,
                        0,
                        MMI_BRW_POPUP_TIME,
                        ERROR_TONE);
                    return;
                }
            }
            else
            {
                jdd_FSDeinitialize(fs_handle);
                jdd_MemFree(content_fname);
            }
        }
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_BRW_FILE_SYSTEM_ERROR),
            IMG_GLOBAL_ERROR,
            0,
            MMI_BRW_POPUP_TIME,
            ERROR_TONE);
        if (filename_p != NULL)
        {
            jdd_MemFree(filename_p);
            filename_p = NULL;
        }
        return;
    }

    memset((void*)&pmime_info_dl, 0, sizeof(JC_MIME_INFO));

    pmime_info_dl.psContentType = pmime_info.psContentType;
    pmime_info_dl.psUrl = pmime_info.psUrl;
    pmime_info_dl.iBufferLen = pmime_info.iBufferLen;
    pmime_info_dl.psFileName = filename_p;

    ret = jdd_MimeHandler(&pmime_info_dl);
    if (filename_p != NULL)
    {
        jdd_MemFree(filename_p);
    }
    if (ret != JC_OK)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 0, MMI_BRW_POPUP_TIME, ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_get_temp_path_on_ext_mem
 * DESCRIPTION
 *  Function to get temp file path on memory card
 * PARAMETERS
 *  url     [?]     [?]
 * RETURNS
 *  JC_CHAR *
 *****************************************************************************/
JC_CHAR *mmi_brw_get_temp_path_on_ext_mem(JC_CHAR *url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_UINT16 path_buf[(FMGR_MAX_PATH_LEN + 1)] = {0};
    JC_UINT32 fname_len = 0;
    JC_CHAR *filename = NULL;
    JC_CHAR *filepath = NULL;
    JDD_FSHANDLE filesyshandle = NULL;
    JC_RETCODE ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jdd_FSInitialize(&filesyshandle) == JC_OK)
    {
        /* Delete @temp folder on external drive */
        kal_wsprintf(path_buf, "%c:\\@temp\\", MMI_CARD_DRV);
        jdd_FSDelDir(filesyshandle, path_buf);

        /* Create @temp folder on external drive */
        ret = jdd_FSMakeDir(filesyshandle, path_buf);
        if (ret == FS_NO_ERROR || ret == JC_ERR_FILE_DIR_ALREADY_EXIST)
        {
            FS_SetAttributes(path_buf, FS_ATTR_DIR | FS_ATTR_HIDDEN | FS_RECURSIVE_TYPE);
            ASSERT(jdd_FSDeinitialize(filesyshandle) == JC_OK);
        }
        else if (ret == JC_ERR_FILE_FULL)
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_JATAAYU_JDD_BROWSER_FILE_SYSTEM_FULL),
                IMG_GLOBAL_ERROR,
                0,
                MMI_BRW_POPUP_TIME,
                ERROR_TONE);

            ASSERT(jdd_FSDeinitialize(filesyshandle) == JC_OK);
            return NULL;
        }
        else
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_BRW_FILE_SAVE_FAILED),
                IMG_GLOBAL_ERROR,
                0,
                MMI_BRW_POPUP_TIME,
                ERROR_TONE);

            ASSERT(jdd_FSDeinitialize(filesyshandle) == JC_OK);
            return NULL;
        }

        kal_wsprintf(path_buf, "%c:\\@temp\\", MMI_CARD_DRV);
        filename = mmi_brw_get_file_name((S8*) url, '/');
        mmi_ucs2cat((S8*) path_buf, (const S8*)filename);

        fname_len = (kal_wstrlen(path_buf) + 1) * ENCODING_LENGTH;
        filepath = (JC_CHAR*) jdd_MemAlloc(1, fname_len);
        jc_memcpy(filepath, path_buf, fname_len);
        jdd_MemFree(filename);
        return filepath;
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_BRW_FILE_SYSTEM_ERROR),
            IMG_GLOBAL_ERROR,
            0,
            MMI_BRW_POPUP_TIME,
            ERROR_TONE);

        return NULL;
    }
}

#ifdef __MMI_JATAAYU_BRW_ADVANCED_RENDERED_PAGE_OPTIONS__


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_display_curr_url_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for display curr url
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_display_curr_url_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_ren_page_display_current_url, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_ren_page_display_current_url, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_display_current_url
 * DESCRIPTION
 *  Function to display curr url
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_display_current_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_PAGE_INFO brw_page_nfo;
    U8 *gui_buffer_p;
    JC_RETCODE ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = jdi_BrowserGetCurrentPageInfo(g_mmi_brw_pbrowser_ctxt, &brw_page_nfo);
    if (ret != JC_OK)
    {
        ASSERT(0);
    }

    if (brw_page_nfo.psUrl)
    {
        EntryNewScreen(SCR_ID_BRW_CURRENT_URL, NULL, mmi_brw_ren_page_display_current_url, NULL);
        gui_buffer_p = GetCurrGuiBuffer(SCR_ID_BRW_CURRENT_URL);

        ShowCategory74Screen(
            STR_ID_BRW_CURRENT_URL,
            GetRootTitleIcon(SERVICES_WAP_MENU_ID),
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            0,
            0,
            (PU8) brw_page_nfo.psUrl,
            mmi_ucs2strlen((PS8) brw_page_nfo.psUrl),
            gui_buffer_p);

        SetLeftSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_ID_BRW_INVALID_URL), IMG_GLOBAL_ERROR, 1, MMI_BRW_POPUP_TIME, ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_send_link_via_sms_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for send link via sms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_send_link_via_sms_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_ren_page_send_link_via_sms, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_ren_page_send_link_via_sms, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_send_link_via_sms
 * DESCRIPTION
 *  Function to send link via sms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_send_link_via_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_PAGE_INFO brw_page_nfo;
    S8 ascii_addr[MAX_DIGITS_SMS] = {0};
    mmi_frm_sms_api_entry_write_struct *send_data = NULL;
    JC_RETCODE ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = jdi_BrowserGetCurrentPageInfo(g_mmi_brw_pbrowser_ctxt, &brw_page_nfo);
    if (ret != JC_OK)
    {
        ASSERT(0);
    }

    send_data = jdd_MemAlloc(sizeof(mmi_frm_sms_api_entry_write_struct), 1);

    send_data->stringlength = mmi_ucs2strlen((PS8) brw_page_nfo.psUrl);
    send_data->string = jdd_MemAlloc((send_data->stringlength + 1) * ENCODING_LENGTH, 1);
    mmi_ucs2cpy((PS8) send_data->string, (PS8) brw_page_nfo.psUrl);

    send_data->dcs = SMSAL_UCS2_DCS;
    send_data->flag = MMI_FRM_SMS_ENTRY_WRITE_REPLY;
    send_data->ascii_addr = (U8*) ascii_addr;
    mmi_frm_sms_api_entry_write_msg(send_data);

    if (send_data != NULL)
    {
        if (send_data->string != NULL)
        {
            jdd_MemFree(send_data->string);
        }
        jdd_MemFree(send_data);
        send_data = NULL;
    }
}
#endif /* __MMI_JATAAYU_BRW_ADVANCED_RENDERED_PAGE_OPTIONS__ */ 

#endif /* defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT) */ 
#endif /* _MMI_JBROWSERMMIRENDEREDPAGE_C */ 

