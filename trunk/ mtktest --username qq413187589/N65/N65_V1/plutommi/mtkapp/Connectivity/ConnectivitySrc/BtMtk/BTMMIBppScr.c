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
 * BTMMIBppScr.c
 *
 * Project:
 * --------
 *   MMI
 *
 * Description:
 * ------------
 *   This file is for MMI BPP service.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifdef __MMI_BT_MTK_SUPPORT__
#if defined(__MMI_BPP_SUPPORT__)
/*  Include: MMI header file */
#include "CommonScreens.h"          /* DisplayPopup */
#include "SettingProfile.h"         /* for tone ID */
#include "MainMenuDef.h"            /* for MAIN_MENU_TITLE_EXTRA_APP_ICON  */
#include "wgui_status_icons.h"      /* for STATUS_ICON_IR */
#include "IdleAppDef.h"             /* g_idle_context */
#include "IdleAppProt.h"            /* EntryIdleScreen() */
#include "ProfileGprots.h"          /* PlayRequestTone */
#include "gpioInc.h"                /* TurnOnBacklight */
//#include "FileSystemDef.h"          /* MMI_PUBLIC_DRV */
#include "Conversions.h"            /* char set conversion */
#include "FileManagerGProt.h"

/* External Device Header Files */
/* File Type Categories (sync with file manager) */
#include "xml_def.h"
#include "FileMgr.h"
#include "BTMMIScrGprots.h"
#include "BTMMICm.h"
#include "Bluetooth_struct.h"
#include "BTMMIBppGprot.h"
#include "BTMMIBppXhtmlGprot.h"
#include "BTMMIBppScr.h"
#include "BTMMIBpp.h"
#include "BTMMIScr.h"
/* BT mmiresource def */
#include "ExtDeviceDefs.h"
#include "FileManagerDef.h"
#include "BTMMICustDef.h"
#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#endif 


/***************************************************************************** 
* CONTEXT
*****************************************************************************/
mmi_bpp_scr_cntx_struct g_mmi_bpp_scr_cntx;
mmi_bpp_scr_cntx_struct *mmi_bpp_scr_cntx_p = &g_mmi_bpp_scr_cntx;

/***************************************************************************** 
* Local Variable & Functions
*****************************************************************************/
static U16 bpp_printing_prog_str_buf[64];
const U16 bpp_print_setting_inline_icons [MMI_BPP_PRINT_SETTING_ICONS] = 
{
    IMG_GLOBAL_L1, 0,
    IMG_GLOBAL_L2, 0,
    IMG_GLOBAL_L3, 0,
    IMG_GLOBAL_L4, 0,
    IMG_GLOBAL_L5, 0,
    IMG_GLOBAL_L6, 0,
};

static void mmi_bt_bpp_update_str(void);
static U8 mmi_bt_bpp_dummy_del_cb(void *p);
static U8 mmi_bt_bpp_connect_del_cb(void *p);
static U8 mmi_bt_bpp_auth_del_cb(void *p);
static U8 mmi_bt_bpp_getting_del_cb(void *p);
static U8 mmi_bt_bpp_composing_del_cb(void *p);
static U8 mmi_bt_bpp_print_setting_del_cb(void *p);
static U8 mmi_bt_bpp_disconnect_del_cb(void *p);
static U8 mmi_bt_bpp_creating_del_cb(void *p);
static U8 mmi_bt_bpp_printing_del_cb(void *p);
static void mmi_bt_bpp_print_setting_disconnect(void);
static void mmi_bt_bpp_create_job_disconnect(void);
static void mmi_bt_bpp_composing_disconnect(void);
static void mmi_bt_bpp_printing_disconnect(void);
static void mmi_bt_bpp_disconnect(void);
static void mmi_bt_bpp_print_setting_check(void);
static void mmi_bt_bpp_print_setting_fill_inline_default(void);
static void mmi_bt_bpp_auth_input_validation_func(U8 *text, U8 *cursor, S32 length);
static U16 mmi_bt_bpp_select_preview_img(void);
static void mmi_bt_bpp_prog_update_hdlr(void);

/***************************************************************************** 
 * MACROS
 *****************************************************************************/

/***************************************************************************** 
 * External Variables & Functions
 *****************************************************************************/
extern byte wgui_inline_list_menu_changed;
extern pBOOL IsBackHistory;
extern int isInCall(void);

#define GLOBAL_API

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_entry_terminated
 * DESCRIPTION
 *  This function is show error and terminate print 
 * PARAMETERS
 *  mmi_bpp_popup_cause_enum cause: terminate reason
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_entry_terminated(mmi_bpp_popup_cause_enum cause)
{
    /* notify user */
     if(!isInCall()
#ifdef __USB_IN_NORMAL_MODE__
        && mmi_usb_is_in_mass_storage_mode()!= MMI_TRUE
#endif
       )
     {
          mmi_bt_bpp_popup(cause);
     }

#ifdef __USB_IN_NORMAL_MODE__
     if(mmi_usb_is_in_mass_storage_mode()!= MMI_TRUE)
     {
          mmi_bt_bpp_add_history(SCR_BPP_DISCONNECTING);
     }
#endif
     mmi_bt_bpp_disconnect_clear_scrs();

     mmi_bt_bpp_set_status(MMI_BPP_STATUS_DISCONNECTING);

     mmi_bt_bpp_send_disconnect();

}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_busy_popup
 * DESCRIPTION
 *  This function is to popup the busy info to user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_busy_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_BUSY_POPUP);
    mmi_bt_bpp_popup(MMI_BPP_POPUP_CAUSE_PRINTER_BUSY);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_format_warning_popup
 * DESCRIPTION
 *  This function is to popup the format warning to user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_format_warning_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bt_bpp_popup(MMI_BPP_POPUP_CAUSE_FORMAT_WARNING);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_del_scr
 * DESCRIPTION
 *  This function is a delete screen if present wrapper function
 * PARAMETERS
 *  U16
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_del_scr(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG1(MMI_BPP_DEL_SCR, scr_id);
    DeleteScreenIfPresent(scr_id);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_clear_scr_db
 * DESCRIPTION
 *  This function is a clear the callback function of given scr_id
 * PARAMETERS
 *  U16
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_clear_scr_db(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearDelScrnIDCallbackHandler(scr_id, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_go_back_history
 * DESCRIPTION
 *  This function is a GoBackHistory wrapper function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_go_back_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackHistory();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_display_idle
 * DESCRIPTION
 *  This function is a DisplayIdleScreen wrapper function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_display_idle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayIdleScreen();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_add_history
 * DESCRIPTION
 *  This function is a AddHistory wrapper function
 * PARAMETERS
 *  U16
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_add_history(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    S16 nHistory = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h.scrnID = scr_id;

    switch (scr_id)
    {
        case SCR_BPP_PRINTING:
            h.entryFuncPtr = mmi_bt_bpp_entry_printing;
            break;
        case SCR_BPP_DISCONNECTING:
            h.entryFuncPtr = mmi_bt_bpp_entry_disconnecting;
            break;
        default:
            ASSERT(0);
            break;
    }
    mmi_ucs2cpy((PS8) h.inputBuffer, (PS8) & nHistory);
    GetCategoryHistory(h.guiBuffer);
    AddHistory(h);    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_add_history
 * DESCRIPTION
 *  This function is a AddHistory wrapper function
 * PARAMETERS
 *  U16
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_history_replace(U16 out_scr, U16 in_scr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    switch(in_scr)
    {
        case SCR_BPP_COMPOSING:
            HistoryReplace(out_scr, in_scr, mmi_bt_bpp_entry_composing);
            SetDelScrnIDCallbackHandler(SCR_BPP_COMPOSING, mmi_bt_bpp_composing_del_cb); 
            break;

        case SCR_BPP_PRINTING:
            HistoryReplace(out_scr, in_scr, mmi_bt_bpp_entry_printing);
            SetDelScrnIDCallbackHandler(SCR_BPP_PRINTING, mmi_bt_bpp_printing_del_cb);            
            break;

        case SCR_BPP_DISCONNECTING:
            HistoryReplace(out_scr, in_scr, mmi_bt_bpp_entry_disconnecting);
            SetDelScrnIDCallbackHandler(SCR_BPP_DISCONNECTING, mmi_bt_bpp_disconnect_del_cb);    
            break;

        case SCR_BPP_GETTING:
            HistoryReplace(out_scr, in_scr, mmi_bt_bpp_entry_getting);
            SetDelScrnIDCallbackHandler(SCR_BPP_GETTING, mmi_bt_bpp_getting_del_cb);    
            break;

        default:
            ASSERT(0);
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_insert_before_history
 * DESCRIPTION
 *  This function is a InserBeforeHistory wrapper function
 * PARAMETERS
 *  U16
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_insert_before_history(U16 ref_scr, U16 in_scr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    S16 nHistory = 0;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/        
    h.scrnID = in_scr;
    mmi_ucs2cpy((PS8) h.inputBuffer, (PS8) & nHistory);
    GetCategoryHistory(h.guiBuffer);    

    switch(in_scr)
    {
        case SCR_BPP_AUTHENTICATING:
            h.entryFuncPtr = mmi_bt_bpp_entry_authenticating;
            break;

        case SCR_BPP_TROUBLE:
            h.entryFuncPtr = mmi_bt_bpp_entry_trouble;
            break;

        default:
            ASSERT(0);
    }
    InsertHistoryBeforeThisScrnReference(ref_scr, &h);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_get_auth_buff
 * DESCRIPTION
 *  This function is uesd to get the pointer of authentication input buff
 * PARAMETERS
 *  void
 * RETURNS
 *  U8*
 *****************************************************************************/
PU8 mmi_bt_bpp_get_auth_buff(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_bpp_scr_cntx_p->auth_scr_input_buff;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_get_preview_img
 * DESCRIPTION
 *  This function is uesd to get the preview image resource id
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_bt_bpp_get_preview_img(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_bpp_scr_cntx_p->img_id;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_get_copies_setting
 * DESCRIPTION
 *  This function is uesd to get the copies setting from user
 * PARAMETERS
 *  void
 * RETURNS
 *  PU16
 *****************************************************************************/
PU16 mmi_bt_bpp_get_copies_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_bpp_scr_cntx_p->print_setting->Copies;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_get_media_setting
 * DESCRIPTION
 *  This function is uesd to get the media setting from user
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_bt_bpp_get_media_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (U8)mmi_bpp_scr_cntx_p->Media;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_get_quality_setting
 * DESCRIPTION
 *  This function is uesd to get the quality setting from user
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_bt_bpp_get_quality_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (U8)mmi_bpp_scr_cntx_p->Quality;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_scr_cntx_init
 * DESCRIPTION
 *  This function is to init the bpp context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_scr_cntx_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_SCR_CNTX_INIT);

    /* free ctrl buffer */
    if(mmi_bpp_scr_cntx_p->print_setting)
    {
        OslMfree(mmi_bpp_scr_cntx_p->print_setting);
    }

    memset(mmi_bpp_scr_cntx_p, 0, sizeof(mmi_bpp_scr_cntx_struct));
}

#define INTERNAL_API
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_update_str
 * DESCRIPTION
 *  This function is to update the string of printing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_update_str(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 bpp_printing_prog_per_str_buf[32];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(bpp_printing_prog_str_buf, 0, sizeof(bpp_printing_prog_str_buf));    

    if((mmi_ucs2strlen((S8*)GetString(STR_BT_BPP_PRINTING))+1) > ((sizeof(bpp_printing_prog_str_buf)/2) -(sizeof(bpp_printing_prog_per_str_buf)/2)))
        ASSERT(MMI_FALSE);

    memset(bpp_printing_prog_per_str_buf, 0, sizeof(bpp_printing_prog_per_str_buf));
    kal_wsprintf((U16*)bpp_printing_prog_per_str_buf, "(%d%c) ", mmi_bt_bpp_retrieve_prog_percentage(), '%');
    mmi_ucs2cpy((S8*)bpp_printing_prog_str_buf, GetString(STR_BT_BPP_PRINTING) );
    mmi_ucs2cat((S8*)bpp_printing_prog_str_buf, (S8*)bpp_printing_prog_per_str_buf);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_dummy_del_cb
 * DESCRIPTION
 *  This function is the delete callback function for dummy screen
 * PARAMETERS
 *  void*
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_bt_bpp_dummy_del_cb(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_DUMMY_DEL_CB);
    mmi_bt_bpp_set_status(MMI_BPP_STATUS_NONE);
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_connect_del_cb
 * DESCRIPTION
 *  This function is the delete callback function for connecting screen
 * PARAMETERS
 *  void*
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_bt_bpp_connect_del_cb(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL usb_mode = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_CONNECT_DEL_CB);
    if (mmi_bt_bpp_is_connecting())
    {
        usb_mode = mmi_bt_bpp_usb_handle();
        return usb_mode;
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_getting_del_cb
 * DESCRIPTION
 *  This function is the delete callback function for getting screen
 * PARAMETERS
 *  void*
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_bt_bpp_getting_del_cb(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL usb_mode = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_GETTING_DEL_CB);
    if (mmi_bt_bpp_get_status() == MMI_BPP_STATUS_GETTING)
    {
        usb_mode = mmi_bt_bpp_usb_handle();
        return usb_mode;
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_auth_del_cb
 * DESCRIPTION
 *  This function is the delete callback function for authenticating screen
 * PARAMETERS
 *  void*
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_bt_bpp_auth_del_cb(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_AUTH_DEL_CB);
    if (mmi_bt_bpp_get_status() == MMI_BPP_STATUS_CHALLENGE)
    {
        bt_bpp_authentication_rsp_struct* rsp;
        rsp = (bt_bpp_authentication_rsp_struct*)OslConstructDataPtr(sizeof(bt_bpp_authentication_rsp_struct));
        rsp->cancel = MMI_TRUE;
    
        /* send authentication response to BT */
        mmi_bt_bpp_send_msg(MSG_ID_BT_BPP_AUTHENTICATION_RSP, rsp);
    
        /* clear cntx */
        mmi_bt_bpp_reset();
    
        /* clear screen */
        mmi_bt_bpp_del_scr(SCR_BPP_CONNECTING);        
    }
    return MMI_FALSE;   
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_print_setting_del_cb
 * DESCRIPTION
 *  This function is the delete callback function for print setting screen
 * PARAMETERS
 *  void*
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_bt_bpp_print_setting_del_cb(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    MMI_BOOL replace;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_PRINT_SETTING_DEL_CB);
    
    if (mmi_bt_bpp_get_status() == MMI_BPP_STATUS_SETTING)
    {        
        /* disconnect */
        //mmi_bt_bpp_print_setting_disconnect();
        
        /* free ctrl buffer */
        if(mmi_bpp_scr_cntx_p->print_setting)
        {
            OslMfree(mmi_bpp_scr_cntx_p->print_setting);
            mmi_bpp_scr_cntx_p->print_setting = NULL;
        }
        
        /* disconnect case implies the del callback can be removed */
        ClearDelScrnIDCallbackHandler(SCR_BPP_PRINT_SETTING, NULL);

        /* disconnect */
        mmi_bt_bpp_send_disconnect();

        replace = mmi_bt_bpp_usb_handle();
        /* replace disconnect screen */    
        if (replace)
        {
            HistoryReplace(SCR_BPP_PRINT_SETTING, SCR_BPP_DISCONNECTING, mmi_bt_bpp_entry_disconnecting);
            /* clear bpp screens */
            mmi_bt_bpp_disconnect_clear_scrs();
            return MMI_TRUE;
        }
    }
    else
    {
        /* free ctrl buffer */
        if(mmi_bpp_scr_cntx_p->print_setting)
        {
            OslMfree(mmi_bpp_scr_cntx_p->print_setting);
            mmi_bpp_scr_cntx_p->print_setting = NULL;
        }   
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_disconnect_del_cb
 * DESCRIPTION
 *  This function is the delete callback function for disconnecting screen
 * PARAMETERS
 *  void*
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_bt_bpp_disconnect_del_cb(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL usb_mode = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_DISCONNECT_DEL_CB);
    if (mmi_bt_bpp_get_status() != MMI_BPP_STATUS_NONE)
    {
        usb_mode = mmi_bt_bpp_usb_handle();
        return usb_mode;
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_creating_del_cb
 * DESCRIPTION
 *  This function is the delete callback function for creating screen
 * PARAMETERS
 *  void*
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_bt_bpp_creating_del_cb(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL replace;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_CREATING_DEL_CB);
    if (mmi_bt_bpp_get_status() == MMI_BPP_STATUS_CREATING)
    {
        //mmi_bt_bpp_create_job_disconnect();
        ClearProtocolEventHandler(MSG_ID_BT_BPP_CREATE_JOB_CNF);

        /* disconnect case implies the del callback can be removed */
        ClearDelScrnIDCallbackHandler(SCR_BPP_CREATING, NULL);

        /* disconnect */
        mmi_bt_bpp_send_disconnect();

        replace = mmi_bt_bpp_usb_handle();
        /* replace disconnect screen */    
        if (replace)
        {
            HistoryReplace(SCR_BPP_CREATING, SCR_BPP_DISCONNECTING, mmi_bt_bpp_entry_disconnecting);
            /* clear bpp screens */
            mmi_bt_bpp_disconnect_clear_scrs();
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_composing_del_cb
 * DESCRIPTION
 *  This function is the delete callback function for composing screen
 * PARAMETERS
 *  void*
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_bt_bpp_composing_del_cb(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL replace;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_COMPOSING_DEL_CB);
    if (mmi_bt_bpp_get_status() == MMI_BPP_STATUS_COMPOSING)
    {
         /* cancel composing process */
        bpp_cancel_xhtml_composing();
            
        mmi_bt_bpp_entry_terminated(MMI_BPP_POPUP_CAUSE_UNKNOW);
#ifdef __USB_IN_NORMAL_MODE__    
        if(mmi_usb_is_in_mass_storage_mode()== MMI_FALSE)
        {
            return MMI_TRUE;
        }
#endif
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_printing_del_cb
 * DESCRIPTION
 *  This function is the delete callback function for printing screen
 * PARAMETERS
 *  void*
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_bt_bpp_printing_del_cb(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bpp_status_enum status;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_PRINTING_DEL_CB);
    status = mmi_bt_bpp_get_status();

    switch(status)
    {
        /* disconnect case */
        case MMI_BPP_STATUS_PRINTED:
        case MMI_BPP_STATUS_FORE_GROUND_PRINT:
        case MMI_BPP_STATUS_FORE_GROUND_STOPPED:           
            mmi_bt_bpp_printing_disconnect();
        default:
            break;
    }
    StopTimer(FMGR_PROG_UPDATE_TIMER);
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_exit_authenticating
 * DESCRIPTION
 *  This function is used to exit the authenticating screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_exit_authenticating(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr;    /* hold the history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_EXIT_AUTHENTICATING);

    Scr.scrnID = SCR_BPP_AUTHENTICATING;
    Scr.entryFuncPtr = mmi_bt_bpp_entry_authenticating;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*)mmi_bpp_scr_cntx_p->auth_scr_input_buff);
    GetCategoryHistory(Scr.guiBuffer);
    AddHistory(Scr);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_exit_print_setting
 * DESCRIPTION
 *  This function is used to exit the print setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_exit_print_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_EXIT_PRINT_SETTING);

    /* add history node for inline screen */
    GenericExitInlineScreen(SCR_BPP_PRINT_SETTING, mmi_bt_bpp_entry_print_setting);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_exit_printing
 * DESCRIPTION
 *  This function is used to exit the printing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_exit_printing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_EXIT_PRINTING);
    StopTimer(FMGR_PROG_UPDATE_TIMER);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_auth_input_validation_func
 * DESCRIPTION
 *  This function is to check the input buffer of authenticating screen
 * PARAMETERS
 *  text        [?]             
 *  cursor      [?]             
 *  length      [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_auth_input_validation_func(U8 *text, U8 *cursor, S32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((length) < 1)
    {
        ChangeLeftSoftkey(0, 0);
    }
    else
    {
        EnableLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_print_setting_fill_inline_struct
 * DESCRIPTION
 *  This function is used to fill the inline struct of print setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_print_setting_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bpp_printer_struct* printer;
    U8  media_idx = 0;
    U8  sides_idx = 0;
    U8  num_idx = 0;
    U8  orien_idx = 0;
    U8  qual_idx = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_PRINT_SETTING_FILL_INLINE_STRUCT);

    /* check got_attr flag */
    printer = mmi_bt_bpp_get_printer();
    if ( printer->got_attr == MMI_FALSE)
    {
        mmi_bt_bpp_print_setting_fill_inline_default();
        goto SCREEN_SETTING;
    }

    /* prepare Paper Size options for inline editor */    
    if (BPP_GET_FLAG(printer->Media, BPP_ADP_MEDIA_MASK_A4))
        mmi_bpp_scr_cntx_p->print_setting->Media_list[media_idx++] = (U8*)GetString(STR_BT_BPP_SETTING_PAPER_A4);
    if (BPP_GET_FLAG(printer->Media, BPP_ADP_MEDIA_MASK_US))
        mmi_bpp_scr_cntx_p->print_setting->Media_list[media_idx++] = (U8*)GetString(STR_BT_BPP_SETTING_PAPER_US);
    if ((BPP_GET_FLAG(printer->Media, BPP_ADP_MEDIA_MASK_4X6))|| 
        (BPP_GET_FLAG(printer->Media, BPP_ADP_MEDIA_MASK_4X6_IOT)))
        mmi_bpp_scr_cntx_p->print_setting->Media_list[media_idx++] = (U8*)GetString(STR_BT_BPP_SETTING_PAPER_4X6);

    /* prepare Sides options for inline editor */
    if (BPP_GET_FLAG(printer->Sides, BPP_ADP_SIDES_MASK_ONE))
        mmi_bpp_scr_cntx_p->print_setting->sides_list[sides_idx++] = (U8*)GetString(STR_BT_BPP_SETTING_SIDES_ONE);
    if (BPP_GET_FLAG(printer->Sides, BPP_ADP_SIDES_MASK_TWO_LONG) ||
        BPP_GET_FLAG(printer->Sides, BPP_ADP_SIDES_MASK_TWO_SHORT) )
        mmi_bpp_scr_cntx_p->print_setting->sides_list[sides_idx++] = (U8*)GetString(STR_BT_BPP_SETTING_SIDES_TWO);

    /* prepare Pages per sheet for inline editor */
    if (BPP_GET_FLAG(printer->NumberUp, BPP_ADP_NUMBER_UP_MASK_1))
        mmi_bpp_scr_cntx_p->print_setting->NumberUp_list[num_idx++] = (U8*)GetString(STR_GLOBAL_1);
    if (BPP_GET_FLAG(printer->NumberUp, BPP_ADP_NUMBER_UP_MASK_2))
        mmi_bpp_scr_cntx_p->print_setting->NumberUp_list[num_idx++] = (U8*)GetString(STR_GLOBAL_2);
    if (BPP_GET_FLAG(printer->NumberUp, BPP_ADP_NUMBER_UP_MASK_4))
        mmi_bpp_scr_cntx_p->print_setting->NumberUp_list[num_idx++] = (U8*)GetString(STR_GLOBAL_4);

    /* prepare Orientation for inline editor */
    if (BPP_GET_FLAG(printer->Orientation, BPP_ADP_ORIENTATION_MASK_P))
        mmi_bpp_scr_cntx_p->print_setting->Orientation_list[orien_idx++] = (U8*)GetString(STR_BT_BPP_SETTING_ORIENTATION_PORTRAIT);
    if (BPP_GET_FLAG(printer->Orientation, BPP_ADP_ORIENTATION_MASK_L))
        mmi_bpp_scr_cntx_p->print_setting->Orientation_list[orien_idx++] = (U8*)GetString(STR_BT_BPP_SETTING_ORIENTATION_LANDSCAP);

    /* prepare quality options for inline editor */
    if (BPP_GET_FLAG(printer->Quality, BPP_ADP_QUALITY_MASK_HIGH))
        mmi_bpp_scr_cntx_p->print_setting->Quality_list[qual_idx++] = (U8*)GetString(STR_BT_BPP_SETTING_QUALITY_HIGH);
    if (BPP_GET_FLAG(printer->Quality, BPP_ADP_QUALITY_MASK_NORMAL))
        mmi_bpp_scr_cntx_p->print_setting->Quality_list[qual_idx++] = (U8*)GetString(STR_BT_BPP_SETTING_QUALITY_NORMAL);
    if (BPP_GET_FLAG(printer->Quality, BPP_ADP_QUALITY_MASK_DRAFT))
        mmi_bpp_scr_cntx_p->print_setting->Quality_list[qual_idx++] = (U8*)GetString(STR_BT_BPP_SETTING_QUALITY_DRAFT);

SCREEN_SETTING:
    /* Paper Size */        
    SetInlineItemActivation (&wgui_inline_items[0], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[0], (U8*) (U8*)GetString (STR_BT_BPP_SETTING_PAPER));
    SetInlineItemActivation (&wgui_inline_items[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    if (media_idx)
    {
        SetInlineItemSelect (&wgui_inline_items[1], (S32)media_idx, 
                            mmi_bpp_scr_cntx_p->print_setting->Media_list,
                            &(mmi_bpp_scr_cntx_p->Media));
    }
    else
    {
        SetInlineItemSelect (&wgui_inline_items[1], (S32)MMI_BPP_MEDIA_LIST, 
                            mmi_bpp_scr_cntx_p->print_setting->Media_list,
                            &(mmi_bpp_scr_cntx_p->Media));        
    }

    /* Sides */        
    SetInlineItemActivation (&wgui_inline_items[2], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[2], (U8*) GetString (STR_BT_BPP_SETTING_SIDES));
    SetInlineItemActivation (&wgui_inline_items[3], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    if (sides_idx)
    {
        SetInlineItemSelect (&wgui_inline_items[3], (S32)sides_idx, 
                            mmi_bpp_scr_cntx_p->print_setting->sides_list,
                            &(mmi_bpp_scr_cntx_p->Sides));
    }
    else
    {
        SetInlineItemSelect (&wgui_inline_items[3], (S32)MMI_BPP_SIDES_LIST, 
                            mmi_bpp_scr_cntx_p->print_setting->sides_list,
                            &(mmi_bpp_scr_cntx_p->Sides));        
    }

    /* Pages per sheet */        
    SetInlineItemActivation (&wgui_inline_items[4], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[4], (U8*) GetString (STR_BT_BPP_SETTING_PAGES));
    SetInlineItemActivation (&wgui_inline_items[5], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    if (num_idx)
    {
        SetInlineItemSelect (&wgui_inline_items[5], (S32)num_idx, 
                            mmi_bpp_scr_cntx_p->print_setting->NumberUp_list,
                            &(mmi_bpp_scr_cntx_p->NumberUp));
    }
    else
    {
        SetInlineItemSelect (&wgui_inline_items[5], (S32)MMI_BPP_NUMBER_UP_LIST, 
                            mmi_bpp_scr_cntx_p->print_setting->NumberUp_list,
                            &(mmi_bpp_scr_cntx_p->NumberUp));        
    }

    /* Orientation */        
    SetInlineItemActivation (&wgui_inline_items[6], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[6], (U8*) GetString (STR_BT_BPP_SETTING_ORIENTATION));
    SetInlineItemActivation (&wgui_inline_items[7], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    if (orien_idx)
    {
        SetInlineItemSelect (&wgui_inline_items[7], (S32)orien_idx, 
                            mmi_bpp_scr_cntx_p->print_setting->Orientation_list,
                            &(mmi_bpp_scr_cntx_p->Orientation));
    }
    else
    {
        SetInlineItemSelect (&wgui_inline_items[7], (S32)MMI_BPP_ORIENTATION_LIST, 
                            mmi_bpp_scr_cntx_p->print_setting->Orientation_list,
                            &(mmi_bpp_scr_cntx_p->Orientation));        
    }

    /* Copies */
    SetInlineItemActivation (&wgui_inline_items[8], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption (&wgui_inline_items[8], (U8*) GetString (STR_BT_BPP_SETTING_COPIES));
    SetInlineItemActivation (&wgui_inline_items[9], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    mmi_asc_to_ucs2((S8*)mmi_bpp_scr_cntx_p->print_setting->Copies,(S8*)"1");
    SetInlineItemTextEdit(&wgui_inline_items[9], (U8*)mmi_bpp_scr_cntx_p->print_setting->Copies, MMI_BPP_MAX_COPIES, INPUT_TYPE_NUMERIC);
    RightJustifyInlineItem(&wgui_inline_items[9]);
    EnableInlineItemBoundary(&wgui_inline_items[9]);
    DisableInlineItemHighlight(&wgui_inline_items[9]);

    /* quality */        
    SetInlineItemActivation (&wgui_inline_items[10], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[10], (U8*) GetString (STR_BT_BPP_SETTING_QUALITY));
    SetInlineItemActivation (&wgui_inline_items[11], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    if (qual_idx)
    {
        SetInlineItemSelect (&wgui_inline_items[11], (S32)qual_idx, 
                            mmi_bpp_scr_cntx_p->print_setting->Quality_list,
                            &(mmi_bpp_scr_cntx_p->Quality));
    }
    else
    {
        SetInlineItemSelect (&wgui_inline_items[11], (S32)MMI_BPP_QUALITY_LIST, 
                            mmi_bpp_scr_cntx_p->print_setting->Quality_list,
                            &(mmi_bpp_scr_cntx_p->Quality));        
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_print_setting_fill_inline_default
 * DESCRIPTION
 *  This function is used to set default inline setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_print_setting_fill_inline_default(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_PRINT_SETTING_FILL_INLINE_DEFAULT);

    /* prepare Paper Size options for inline editor */    
    mmi_bpp_scr_cntx_p->print_setting->Media_list[0] = (U8*)GetString(STR_BT_BPP_SETTING_PAPER_A4);
    mmi_bpp_scr_cntx_p->print_setting->Media_list[1] = (U8*)GetString(STR_BT_BPP_SETTING_PAPER_US);
    mmi_bpp_scr_cntx_p->print_setting->Media_list[2] = (U8*)GetString(STR_BT_BPP_SETTING_PAPER_4X6);

    /* prepare Sides options for inline editor */
    mmi_bpp_scr_cntx_p->print_setting->sides_list[0] = (U8*)GetString(STR_BT_BPP_SETTING_SIDES_ONE);
    mmi_bpp_scr_cntx_p->print_setting->sides_list[1] = (U8*)GetString(STR_BT_BPP_SETTING_SIDES_TWO);

    /* prepare Pages per sheet for inline editor */
    mmi_bpp_scr_cntx_p->print_setting->NumberUp_list[0] = (U8*)GetString(STR_GLOBAL_1);
    mmi_bpp_scr_cntx_p->print_setting->NumberUp_list[1] = (U8*)GetString(STR_GLOBAL_2);
    mmi_bpp_scr_cntx_p->print_setting->NumberUp_list[2] = (U8*)GetString(STR_GLOBAL_4);

    /* prepare Orientation for inline editor */
    mmi_bpp_scr_cntx_p->print_setting->Orientation_list[0] = (U8*)GetString(STR_BT_BPP_SETTING_ORIENTATION_PORTRAIT);
    mmi_bpp_scr_cntx_p->print_setting->Orientation_list[1] = (U8*)GetString(STR_BT_BPP_SETTING_ORIENTATION_LANDSCAP);

    /* prepare Paper Size options for inline editor */    
    mmi_bpp_scr_cntx_p->print_setting->Quality_list[0] = (U8*)GetString(STR_BT_BPP_SETTING_QUALITY_HIGH);
    mmi_bpp_scr_cntx_p->print_setting->Quality_list[1] = (U8*)GetString(STR_BT_BPP_SETTING_QUALITY_NORMAL);
    mmi_bpp_scr_cntx_p->print_setting->Quality_list[2] = (U8*)GetString(STR_BT_BPP_SETTING_QUALITY_DRAFT);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_print_setting_check
 * DESCRIPTION
 *  This function is used to check print settings from user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_print_setting_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16   Copies;
    mmi_bpp_printer_struct* printer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_PRINT_SETTING_CHECK);

    printer = mmi_bt_bpp_get_printer();
    Copies = (U16)gui_atoi(mmi_bpp_scr_cntx_p->print_setting->Copies);

    if (printer->got_attr)
    {
        /* check printer settings */
        if((printer->Copies == 0) && (Copies != 0))
        {
            mmi_bt_bpp_entry_preview();
            return;
        }
        
        /* check user settings */
        if (Copies == 0)
        {
            U16 notify_str[34]; /* STR_BT_BPP_SETTING_COPIES_ERROR */

            kal_wstrcpy((U16 *)notify_str, (U16 *)GetString(STR_BT_BPP_SETTING_COPIES_ERROR));
            TurnOnBacklight(MMI_TRUE);
            DisplayPopup((U8*)notify_str,
                           IMG_GLOBAL_ERROR, 
                           1, UI_POPUP_NOTIFYDURATION_TIME, (U8)ERROR_TONE);
            return;
        }
        
        if (Copies > printer->Copies)
        {
            U16 max_copies[6];      /* " 999 '\0'" */
            U16 notify_str[36];     /* STR_BT_BPP_SETTING_COPIES_EXCEED + max_copies + 
                                       STR_BT_BPP_SETTING_COPIES_EXCEED_END */
            
            kal_wstrcpy((U16 *)notify_str, (U16 *)GetString(STR_BT_BPP_SETTING_COPIES_EXCEED) );
            kal_wsprintf((U16 *)max_copies, " %d ", printer->Copies);
            kal_wstrcat((U16 *)notify_str, (U16*)max_copies);  
            kal_wstrcat((U16 *)notify_str, (U16*)GetString(STR_BT_BPP_SETTING_COPIES_EXCEED_END));

            TurnOnBacklight(MMI_TRUE);
            DisplayPopup((U8*)notify_str,
                           IMG_GLOBAL_ERROR, 
                           1, UI_POPUP_NOTIFYDURATION_TIME, (U8)ERROR_TONE);
            return;
        }
    }
    mmi_bt_bpp_entry_preview();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_select_preview_img
 * DESCRIPTION
 *  This function is select preview image for bpp layout preview screen
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_bt_bpp_select_preview_img(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bpp_printer_struct* printer;
    int  img_id = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    printer = mmi_bt_bpp_get_printer();

    /* select img id from settings */
    /*-----------------------------------*/
    /*          /         \              */
    /*        L            P             */
    /*      /    \       /    \          */
    /*    S1     S2     S1     S2        */
    /*   / | \  / | \  / | \  / | \      */
    /*  0  1 2  3 4 5 6  7 8 9 10 11     */
    /*-----------------------------------*/

    /* Orientation -> only count portrait setting */       
    if ((printer->got_attr == MMI_FALSE) || (BPP_GET_FLAG(printer->Orientation, BPP_ADP_ORIENTATION_MASK_P)))
    {
        if (mmi_bpp_scr_cntx_p->Orientation == 0)
        {
            /* protrait */
            img_id += 6;
            MMI_BPP_LOG(MMI_BPP_SELECT_PREVIEW_IMG_PORTRAIT_SETTING);
        }
    }

    /* Sides -> only count two-sided setting*/
    if (mmi_bpp_scr_cntx_p->Sides == 1)
    {
        /* two cases */
        /* 1. got_attr, 1 implies two-sided */
        /* 1. not_got_attr, 1 implies two-sided */
        img_id += 3;
        MMI_BPP_LOG(MMI_BPP_SELECT_PREVIEW_IMG_SIDES_SETTING);
    }
    if ((printer->got_attr == MMI_TRUE) && !(BPP_GET_FLAG(printer->Sides, BPP_ADP_SIDES_MASK_ONE)))
    {
        if (mmi_bpp_scr_cntx_p->Sides == 0)
        {
            /* got_attr, but no one-sided setting, 0 implies two-sided */
            img_id += 3;
            MMI_BPP_LOG(MMI_BPP_SELECT_PREVIEW_IMG_SIDES_SETTING);
        }
    }

    /* Pages per sheet -> only count multiple pages setting*/
    if ((printer->got_attr == MMI_FALSE) || (mmi_bpp_scr_cntx_p->NumberUp == 2))
    {
        /* 4 pages no matter got_attr */
        if (mmi_bpp_scr_cntx_p->NumberUp == 2)
            goto INCRE_2;
        /* 2 pages of not got_attr */
        if (mmi_bpp_scr_cntx_p->NumberUp == 1)
            goto INCRE_1;
        goto SELECT;
    }
    else
    {
        switch(printer->NumberUp)
        {
            case 0x02:   /* implies only option 2 pages could be set */
                goto INCRE_1;
            case 0x03:   /* implies option 1,2 pages could be set */
                if (mmi_bpp_scr_cntx_p->NumberUp == 1)
                    goto INCRE_1;
            case 0x04:   /* implies only option 4 pages could be set */
                goto INCRE_2;
            case 0x05:   /* implies option 1,4 pages could be set */             
                if (mmi_bpp_scr_cntx_p->NumberUp == 1)
                    goto INCRE_2;
            case 0x06:   /* implies option 2,4 pages could be set */             
                if (mmi_bpp_scr_cntx_p->NumberUp == 0) // option 2 pages
                    goto INCRE_1;
                goto INCRE_2;       //option 4 pages
            case 0x07:   /* implies option 1,2,4 pages could be set */             
                if (mmi_bpp_scr_cntx_p->NumberUp == 1) // option 2 pages
                    goto INCRE_1;
            default:
                goto SELECT;
        }
    }
INCRE_1:
    img_id += 1;
    MMI_BPP_LOG(MMI_BPP_SELECT_PREVIEW_IMG_PAGES_2_SETTING);
    goto SELECT;
INCRE_2:
    img_id += 2;
    MMI_BPP_LOG(MMI_BPP_SELECT_PREVIEW_IMG_PAGES_4_SETTING);
    
SELECT:     
    switch(img_id)
    {
        case 0:   /* L_S1_1page */
            return (U16)IMG_BPP_LAYOUT_L_S1_C1;
        case 1:   /* L_S1_2page */
            return (U16)IMG_BPP_LAYOUT_L_S1_C2;
        case 2:   /* L_S1_4page */
            return (U16)IMG_BPP_LAYOUT_L_S1_C4;
        case 3:   /* L_S2_1page */
            return (U16)IMG_BPP_LAYOUT_L_S2_C1;
        case 4:   /* L_S2_2page */
            return (U16)IMG_BPP_LAYOUT_L_S2_C2;
        case 5:   /* L_S2_4page */             
            return (U16)IMG_BPP_LAYOUT_L_S2_C4;
        case 6:   /* P_S1_1page */
            return (U16)IMG_BPP_LAYOUT_P_S1_C1;
        case 7:   /* L_S1_2page */
            return (U16)IMG_BPP_LAYOUT_P_S1_C2;
        case 8:   /* L_S1_4page */
            return (U16)IMG_BPP_LAYOUT_P_S1_C4;
        case 9:   /* L_S2_1page */
            return (U16)IMG_BPP_LAYOUT_P_S2_C1;
        case 10:   /* L_S2_2page */
            return (U16)IMG_BPP_LAYOUT_P_S2_C2;
        case 11:   /* L_S2_4page */             
            return (U16)IMG_BPP_LAYOUT_P_S2_C4;                
        default:
            break;    
    }
    ASSERT(0);
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_prog_update_hdlr
 * DESCRIPTION
 *  This function is the handler for showing the progress of printing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_prog_update_hdlr(void)
{   
    mmi_bt_bpp_update_str();
    cat66_update_progress_string();
    StartTimer(FMGR_PROG_UPDATE_TIMER, MMI_BPP_PROG_UPD_DUR, mmi_bt_bpp_prog_update_hdlr);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_print_setting_disconnect
 * DESCRIPTION
 *  This function is used to disconnect printer in setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_print_setting_disconnect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_PRINT_SETTING_DISCONNECT);

    /* free ctrl buffer */
    if(mmi_bpp_scr_cntx_p->print_setting)
    {
        OslMfree(mmi_bpp_scr_cntx_p->print_setting);
        mmi_bpp_scr_cntx_p->print_setting = NULL;
    }

    /* disconnect case implies the del callback can be removed */
    ClearDelScrnIDCallbackHandler(SCR_BPP_PRINT_SETTING, NULL);

    /* disconnect process */
    mmi_bt_bpp_disconnect();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_create_job_disconnect
 * DESCRIPTION
 *  This function is used to disconnect printer in creating screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_create_job_disconnect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_CREATE_JOB_DISCONNECT);

    ClearProtocolEventHandler(MSG_ID_BT_BPP_CREATE_JOB_CNF);

    /* disconnect case implies the del callback can be removed */
    ClearDelScrnIDCallbackHandler(SCR_BPP_CREATING, NULL);
    mmi_bt_bpp_disconnect();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_composing_disconnect
 * DESCRIPTION
 *  This function is used to disconnect printer in composing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_composing_disconnect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_COMPOSING_DISCONNECT);

    /* cancel composing process */
    bpp_cancel_xhtml_composing();
    
    /* disconnect case implies the del callback can be removed */
    ClearDelScrnIDCallbackHandler(SCR_BPP_COMPOSING, NULL);
    /* disconnect process */
    mmi_bt_bpp_disconnect();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_printing_disconnect
 * DESCRIPTION
 *  This function is used to disconnect printer in printing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_printing_disconnect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_PRINTING_DISCONNECT);
    
    /* disconnect case implies the del callback can be removed */
    ClearDelScrnIDCallbackHandler(SCR_BPP_PRINTING, NULL);

    /* check status first */
    if (mmi_bt_bpp_get_status() == MMI_BPP_STATUS_PRINTED)
    {
        /* wait the disconnect ind to finish print job */
        if (mmi_bt_bpp_usb_handle())
        {
            mmi_bt_bpp_entry_disconnecting();
        }
        mmi_bt_bpp_disconnect_clear_scrs();
    }
    else
    {
        /* cancel case */
        mmi_bt_bpp_set_status(MMI_BPP_STATUS_CANCELED);
       
        if (mmi_bt_bpp_get_timer())
        {
            StopTimer(BT_BPP_PRINTING_TIMER);
        }
        else
        {
            ClearProtocolEventHandler(MSG_ID_BT_BPP_EVENT_IND);
        }
        ClearProtocolEventHandler(MSG_ID_BT_BPP_PROG_UPDATE_IND);
        mmi_bt_bpp_disconnect();            
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_disconnect
 * DESCRIPTION
 *  This function is handle disconnect process for bpp screen operation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_disconnect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL entry = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_DISCONNECT);

    /* disconnect */
    mmi_bt_bpp_send_disconnect();

    entry = mmi_bt_bpp_usb_handle();

    /* entry disconnect screen */    
    if (entry)
        mmi_bt_bpp_entry_disconnecting();

    /*notify app to free the resource*/
    if(mmi_bpp_cntx_p->app_callback)
    {
        mmi_bpp_cntx_p->app_callback(MMI_BPP_XHTML_RSP_CANCELED);
    }

    /* clear bpp screens */
    mmi_bt_bpp_disconnect_clear_scrs();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_plug_out_hdlr
 * DESCRIPTION
 *  This function is to handle the memory card plug out event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_plug_out_hdlr(void)
{
/*remove by mbj06053 for MAUI_00103272*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_print_setting_exit_confirm
 * DESCRIPTION
 *  This function is ask the confirmation of exiting the printing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
//void mmi_bt_bpp_print_setting_exit_confirm(void)
//{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//  MMI_BPP_LOG(MMI_BPP_PRINT_SETTING_EXIT_CNF);
/*
    DisplayConfirm(STR_GLOBAL_YES, IMG_GLOBAL_YES,
                   STR_GLOBAL_NO, IMG_GLOBAL_NO,
                   (UI_string_type)GetString(STR_GLOBAL_CANCEL), IMG_GLOBAL_QUESTION, WARNING_TONE); 
    
    SetRightSoftkeyFunction (GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction (mmi_bt_bpp_print_setting_disconnect, KEY_EVENT_UP);
*/
//    SetRightSoftkeyFunction (mmi_bt_bpp_print_setting_check, KEY_EVENT_UP);
//    SetLeftSoftkeyFunction (mmi_bt_bpp_print_setting_disconnect, KEY_EVENT_UP);
//}

#define SCREEN_API
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_pre_entry_printer_device_select_screen
 * DESCRIPTION
 *  This function is used to add a dummy screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_pre_entry_printer_device_select_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_PRE_ENTRY_DEV_SEL);
    /* if gobackhistory -> means the printer selecting process interrupted */
    if (IsBackHistory)
    {
        /* change state to idle and goback history */
        mmi_bt_bpp_set_status(MMI_BPP_STATUS_NONE);
        //GoBackHistory();
        EntryNewScreen(SCR_BPP_DUMMY, NULL, NULL, NULL); /* To enter dummy screen function */
	    ShowCategoryDummyScreen();

	 /* start a timer to goback */	 
    	StartTimer(BT_BPP_PRINTING_TIMER, 5, mmi_bt_bpp_cm_timer_expire_hdlr);
    }
    /* else -> starting printer selecting process */
    else
    {
        EntryNewScreen(SCR_BPP_DUMMY, NULL, mmi_bt_pre_entry_printer_device_select_screen, NULL);
        SetDelScrnIDCallbackHandler(SCR_BPP_DUMMY, mmi_bt_bpp_dummy_del_cb);
    }    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_entry_connecting
 * DESCRIPTION
 *  This function is used to entry the connecting printer screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_entry_connecting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_ENTRY_CONNECTING);
    EntryNewScreen(SCR_BPP_CONNECTING, NULL, mmi_bt_bpp_entry_connecting, NULL);
    
    /* clear all key handlers so as to restrict duplicate reqs */
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
       
    /* Show Connecting screen */
    ShowCategory66Screen(
        STR_BT_BPP_BT_PRINTING,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        0,
        0,
        0,
        0,
        (U8*) GetString(STR_BT_CONNECTING),
        IMG_GLOBAL_PROGRESS,
        NULL);
    
    /* Set delete callback function */
    SetDelScrnIDCallbackHandler(SCR_BPP_CONNECTING, mmi_bt_bpp_connect_del_cb);

    /* delete summy screen */
    ClearDelScrnIDCallbackHandler(SCR_BPP_DUMMY, NULL);
    DeleteScreenIfPresent(SCR_BPP_DUMMY);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_entry_authenticating
 * DESCRIPTION
 *  This function is used to entry the authenticating screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_entry_authenticating(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  utf8_char_cnt = 0, ucs2_str_len = 0;
    U16 curr_screen_id;
    U8  *guiBuffer;  
    U8  *inputBuffer;
    U8  ui_tmp[4];
    U8  dev_name_tmp[MMI_BT_SCR_BD_NAME_LEN];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_ENTRY_AUTHENTICATING);

    /* two cases that this entry fuction will be called */
    /* one is authentication indication */
    /* for above case, shall entry new screen or insert screen depends */
    /* second is that this entry is called by ExecutePopHistory while interrup screen is finished */
    /* for second case, IsBackHistory shall be TRUE */
    curr_screen_id = GetActiveScreenId();
    switch (curr_screen_id)
    {
        /* first case -> entry new screen */
        case SCR_BPP_CONNECTING:
            goto ENTRY_NEW_SCR;
            break;
        /* other screens */
        default:
            /* interrupt screen on connecting screen -> insert history */
            if ((IsBackHistory == MMI_FALSE) || (isInCall() == MMI_TRUE))
            {
                mmi_bt_bpp_insert_before_history(SCR_BPP_CONNECTING, SCR_BPP_AUTHENTICATING);
                break;
            }
            /* GoBackHistory case */
            goto ENTRY_NEW_SCR;
            break;
    }
    return;
    
ENTRY_NEW_SCR:
    /* turn off backlight first before TurnOnBacklight(1) */
    /* it is to avoid that TurnOnBacklight(0) is called, if TurnOnBacklight(0) is called, TurnOnBacklight(1) doesnot work */
    /* so have to TurnOffBacklight() first */
    TurnOffBacklight();
    TurnOnBacklight(1);
    EntryNewScreen(SCR_BPP_AUTHENTICATING, mmi_bt_bpp_exit_authenticating, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_BPP_AUTHENTICATING);
    inputBuffer = GetCurrInputBuffer(SCR_BPP_AUTHENTICATING);

    if (inputBuffer == NULL)
    {
        memset(mmi_bpp_scr_cntx_p->auth_scr_input_buff, 0, MMI_BPP_AUTH_INPUT_BUFF_SIZE);
        memset(mmi_bpp_scr_cntx_p->auth_scr_ui_buff, 0, MMI_BPP_AUTH_UI_BUFF_SIZE);
        memset(dev_name_tmp, 0, MMI_BT_SCR_BD_NAME_LEN);
        
        /* display printer name */        
        /* Fill device name list */
        /* get byte count for convert utf8 string to UCS2 string */
        /* get character count of utf8 string */
        /* +1 is for UCS2 NULL terminate */
        /* *ENCODING_LENGTH is for byte count of one UCS2 character */
        utf8_char_cnt = (U8) ((mmi_chset_utf8_strlen(mmi_bt_bpp_get_printer_name()) + 1) * ENCODING_LENGTH);
        if (utf8_char_cnt > MMI_BT_SCR_BD_NAME_LEN)
        {
            ucs2_str_len =
                (U8) mmi_chset_utf8_to_ucs2_string(
                        (kal_uint8*) dev_name_tmp,
                        MMI_BT_SCR_BD_NAME_LEN,
                        mmi_bt_bpp_get_printer_name());
        }
        else
        {
            ucs2_str_len =
                (U8) mmi_chset_utf8_to_ucs2_string((kal_uint8*) dev_name_tmp, utf8_char_cnt, mmi_bt_bpp_get_printer_name());
        }
		/* allow (MMI_BT_BD_NAME_LEN/3) chinese characters or (MMI_BT_BD_NAME_LEN/3)*2 english characters  */
		/* so for UCS2 encoding, need MMI_BT_SCR_BD_NAME_LEN bytes */

		/* shall check if there is any two_byte character mixed in one_bye UCS2 string */
		/* if yes, then truncate the string to meet above rules((MMI_BT_BD_NAME_LEN/3) chinese characters or (MMI_BT_BD_NAME_LEN/3)*2 english characters)*/	
		if(mmi_bt_test_ucs2((U16*)dev_name_tmp, (U16)(ucs2_str_len/ENCODING_LENGTH)) )
		{ 
			mmi_bt_truncate_ucs2_string((U16*)dev_name_tmp, 
		    							(U16)(ucs2_str_len/ENCODING_LENGTH),
		    							(U16)((MMI_BT_BD_NAME_LEN-2)/3));		    
		}

        /* STR_BT_BPP_AUTHENTICATING */
        mmi_ucs2cpy((S8*) mmi_bpp_scr_cntx_p->auth_scr_ui_buff, (const S8*)GetString(STR_BT_BPP_AUTHENTICATING));
        /* "(" string + "Device name" + ")" string*/
        if (dev_name_tmp[0]!= 0)
        {
            mmi_asc_to_ucs2((S8*)ui_tmp,(S8*)"(");         
            mmi_ucs2cat((S8*) mmi_bpp_scr_cntx_p->auth_scr_ui_buff, (const S8*)ui_tmp);            
            mmi_ucs2cat((S8*) mmi_bpp_scr_cntx_p->auth_scr_ui_buff, (const S8*)dev_name_tmp);
            mmi_asc_to_ucs2((S8*)ui_tmp,(S8*)")");         
            mmi_ucs2cat((S8*) mmi_bpp_scr_cntx_p->auth_scr_ui_buff, (const S8*)ui_tmp);
        }
        /* ":" string */
        mmi_asc_to_ucs2((S8*)ui_tmp,(S8*)":");         
        mmi_ucs2cat((S8*) mmi_bpp_scr_cntx_p->auth_scr_ui_buff, (const S8*)ui_tmp);        
    }
    /* inputbuffer != NULL */
    else
    {
        mmi_ucs2cpy((S8*) mmi_bpp_scr_cntx_p->auth_scr_input_buff, (S8*) inputBuffer);
        /* donot need to update ui_buffer */
    }

    RegisterInputBoxValidationFunction(mmi_bt_bpp_auth_input_validation_func);
    ShowCategory111Screen_ext(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_bpp_scr_cntx_p->auth_scr_ui_buff,
        INPUT_TYPE_NUMERIC_PASSWORD,
        (U8*) (mmi_bpp_scr_cntx_p->auth_scr_input_buff),
        (GOEP_MAX_PASSWD_SIZE + 1),
        NULL,
        0,
        guiBuffer);
    SetLeftSoftkeyFunction(mmi_bt_bpp_auth_send, KEY_EVENT_UP);    
    if (mmi_ucs2strlen((S8*) (mmi_bpp_scr_cntx_p->auth_scr_input_buff)) < 1)
    {
        ChangeLeftSoftkey(0, 0);
    }

    SetCategory111RightSoftkeyFunction(mmi_bt_bpp_auth_reject, KEY_EVENT_UP);
    SetKeyHandler(mmi_bt_bpp_auth_reject, KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);

    SetDelScrnIDCallbackHandler(SCR_BPP_AUTHENTICATING, (HistoryDelCBPtr) mmi_bt_bpp_auth_del_cb);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_entry_getting
 * DESCRIPTION
 *  This function is used to entry the getting printer attribute screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_entry_getting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_ENTRY_GETTING);
    
    EntryNewScreen(SCR_BPP_GETTING, NULL, mmi_bt_bpp_entry_getting, NULL);
    
    /* clear all key handlers so as to restrict duplicate reqs */
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
  
    /* Show Connecting screen */
    ShowCategory66Screen(
        STR_BT_BPP_NEGOTIATING,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        0,
        0,
        0,
        0,
        (U8*) GetString(STR_BT_BPP_GETTING_CAPABILITY),
        IMG_GLOBAL_PROGRESS,
        NULL);
    
    /* Set delete callback function */
    SetDelScrnIDCallbackHandler(SCR_BPP_GETTING, mmi_bt_bpp_getting_del_cb);    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_pre_entry_print_setting
 * DESCRIPTION
 *  This function is pre entry function of print setting screen
 * PARAMETERS
 *  MMI_BOOL
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_pre_entry_print_setting(MMI_BOOL got_printer_attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG1(MMI_BPP_PRE_ENTRY_PRINT_SETTING, got_printer_attr);
    
    /* allocate memory for print setting screen */
    if(mmi_bpp_scr_cntx_p->print_setting == NULL)
    {
      mmi_bpp_scr_cntx_p->print_setting = (mmi_bpp_print_setting_struct*)OslMalloc(sizeof(mmi_bpp_print_setting_struct));
      memset(mmi_bpp_scr_cntx_p->print_setting, 0, sizeof(mmi_bpp_print_setting_struct));
    }

    if (isInCall() != MMI_TRUE)
    {
        if (got_printer_attr == MMI_TRUE)
        {
            mmi_bt_bpp_entry_print_setting();
        }
        else
        {
            goto ADD_HISTORY;
        }
    }
    else
    {
        if (got_printer_attr == MMI_TRUE)
        {
            if (IsScreenPresent(SCR_BPP_CONNECTING))
	            HistoryReplace(SCR_BPP_CONNECTING, SCR_BPP_PRINT_SETTING, mmi_bt_bpp_entry_print_setting);
	        else
                HistoryReplace(SCR_BPP_GETTING, SCR_BPP_PRINT_SETTING, mmi_bt_bpp_entry_print_setting);    
        }
        else
        {            
            //goto ADD_HISTORY;
      	     /* popup failed to user */
            mmi_bt_bpp_popup(MMI_BPP_POPUP_CAUSE_GET_ATTR_FAILED);
    	    if (IsScreenPresent(SCR_BPP_CONNECTING))
	            HistoryReplace(SCR_BPP_CONNECTING, SCR_BPP_PRINT_SETTING, mmi_bt_bpp_entry_print_setting);
	        else
                HistoryReplace(SCR_BPP_GETTING, SCR_BPP_PRINT_SETTING, mmi_bt_bpp_entry_print_setting);    
        }
        SetDelScrnIDCallbackHandler (SCR_BPP_PRINT_SETTING, 
                                 (HistoryDelCBPtr)mmi_bt_bpp_print_setting_del_cb);

    }
    return;
    
ADD_HISTORY:
{
    history h;
    S16 nHistory = 0;
    
    /* popup failed to user */
    mmi_bt_bpp_popup(MMI_BPP_POPUP_CAUSE_GET_ATTR_FAILED);
    
    /* add print setting screen to history */
    h.scrnID = SCR_BPP_PRINT_SETTING;
    h.entryFuncPtr = mmi_bt_bpp_entry_print_setting;
    mmi_ucs2cpy((PS8) h.inputBuffer, (PS8) & nHistory);
    GetCategoryHistory(h.guiBuffer);
    AddHistory(h);
}
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_entry_print_setting
 * DESCRIPTION
 *  This function is used to entry the print setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_entry_print_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* guiBuffer;
    U8* inputBuffer;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_ENTRY_PRINT_SETTING);

    EntryNewScreen(SCR_BPP_PRINT_SETTING, mmi_bt_bpp_exit_print_setting, NULL, NULL);        

    InitializeCategory57Screen();
    mmi_bt_bpp_print_setting_fill_inline_struct();

    guiBuffer = GetCurrGuiBuffer (SCR_BPP_PRINT_SETTING);
    inputBuffer = GetCurrNInputBuffer (SCR_BPP_PRINT_SETTING, &inputBufferSize);

    if(inputBuffer!=NULL)
    {
        SetCategory57Data(wgui_inline_items, MMI_BPP_PRINT_SETTING_ICONS, inputBuffer);  
    }
    /* trick to set done flag for protocol setting inline screen*/
    wgui_inline_list_menu_changed = 1;

    ShowCategory57Screen (STR_BT_BPP_PRINT_SETTING, GetRootTitleIcon(MENU_CONN_BT_MAIN),    
                    STR_BT_BPP_LAYOUT_PREVIEW, IMG_GLOBAL_OK,
                    STR_BT_BPP_LAYOUT_PREVIEW, IMG_GLOBAL_BACK,
                    MMI_BPP_PRINT_SETTING_ICONS, (U16*)bpp_print_setting_inline_icons, 
                    wgui_inline_items, 0, guiBuffer);
//  SetCategory57RightSoftkeyFunctions (mmi_bt_bpp_print_setting_check, mmi_bt_bpp_print_setting_exit_confirm);
    SetCategory57RightSoftkeyFunctions (mmi_bt_bpp_print_setting_check, mmi_bt_bpp_print_setting_check);

    /* Set delete call back function and end key function for release allocated memory */
    SetDelScrnIDCallbackHandler (SCR_BPP_PRINT_SETTING, 
                                 (HistoryDelCBPtr)mmi_bt_bpp_print_setting_del_cb);

    SetKeyHandler(mmi_bt_bpp_print_setting_disconnect, KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_entry_disconnecting
 * DESCRIPTION
 *  This function is used to entry the disconnecting printer screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_entry_disconnecting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* string_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_ENTRY_DISCONNECTING);
    EntryNewScreen(SCR_BPP_DISCONNECTING, NULL, mmi_bt_bpp_entry_disconnecting, NULL);
    
    /* clear all key handlers so as to restrict duplicate reqs */
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);

    switch (mmi_bt_bpp_get_status())
    {
        case MMI_BPP_STATUS_CREATING:
        case MMI_BPP_STATUS_COMPOSING:
        case MMI_BPP_STATUS_CANCELED:            
            string_id = (U8*) GetString(STR_BT_BPP_CANCEL);
            break;
        default:
            string_id = (U8*) GetString(STR_BT_DISCONNECTING);
            break;            
    }
       
    /* Show Connecting screen */
    ShowCategory66Screen(
        STR_BT_DISCONNECTING,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        0,
        0,
        0,
        0,
        string_id,
        IMG_GLOBAL_PROGRESS,
        NULL);
    
    /* Set delete callback function */
    SetDelScrnIDCallbackHandler(SCR_BPP_DISCONNECTING, mmi_bt_bpp_disconnect_del_cb);    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_entry_preview
 * DESCRIPTION
 *  This function is used to preview the layout set by user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_entry_preview(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 img_id;
    U8* guiBuffer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_ENTRY_PREVIEW);

    /* get preview image */
    mmi_bpp_scr_cntx_p->img_id = img_id = mmi_bt_bpp_select_preview_img();

    EntryNewScreen(SCR_BPP_LAYOUT_PREVIEW, NULL, mmi_bt_bpp_entry_preview, NULL);        

    guiBuffer = GetCurrGuiBuffer (SCR_BPP_LAYOUT_PREVIEW);
    
    ShowCategory132Screen(
        (U8*) GetString(STR_BT_BPP_LAYOUT_PREVIEW), /* title string */
        GetRootTitleIcon(MENU_CONN_BT_MAIN), /* image ID of title icon */
        STR_BT_BPP_PRINT,   /* string ID of LSK */
        IMG_GLOBAL_OK,      /* image ID of LSK */
        STR_GLOBAL_BACK,    /* string ID of RSK */
        IMG_GLOBAL_BACK,    /* image ID of RSK */
        img_id,             /* image ID, displayed at the center */
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_bt_bpp_print, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_bt_bpp_print_setting_disconnect, KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);

    /* Set delete call back function and end key function for release allocated memory */
    SetDelScrnIDCallbackHandler (SCR_BPP_PRINT_SETTING, 
                                 (HistoryDelCBPtr)mmi_bt_bpp_print_setting_del_cb);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_entry_creating
 * DESCRIPTION
 *  This function is used to entry the creating job screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_entry_creating(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_ENTRY_CREATING);
    EntryNewScreen(SCR_BPP_CREATING, NULL, mmi_bt_bpp_entry_creating, NULL);
           
    /* Show Connecting screen */
    ShowCategory66Screen(
        STR_BT_BPP_PRINTING,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        0,
        0,
        STR_GLOBAL_CANCEL,
        0,
        (U8*) GetString(STR_BT_BPP_PRINT_JOB_CREATING),
        IMG_GLOBAL_PROGRESS,
        NULL);
    

    /* Set Right softkey function to abort creating */
    SetRightSoftkeyFunction(mmi_bt_bpp_create_job_disconnect,KEY_EVENT_UP); 

    /* Set End key function to abort creating */
    SetKeyHandler(mmi_bt_bpp_create_job_disconnect, KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);

    /* Set delete callback function */
    SetDelScrnIDCallbackHandler(SCR_BPP_CREATING, mmi_bt_bpp_creating_del_cb); 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_entry_composing
 * DESCRIPTION
 *  This function is used to entry the composing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_entry_composing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_ENTRY_COMPOSING);
    EntryNewScreen(SCR_BPP_COMPOSING, NULL, mmi_bt_bpp_entry_composing, NULL);
           
    /* Show Connecting screen */
    ShowCategory66Screen(
        STR_BT_BPP_PRINTING,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        0,
        0,
        STR_GLOBAL_CANCEL,
        0,
        (U8*) GetString(STR_BT_BPP_PRINT_DOCUMENT_COMPOSING),
        IMG_GLOBAL_PROGRESS,
        NULL);
    

    /* Set Right softkey function to abort composing */
    SetRightSoftkeyFunction(mmi_bt_bpp_composing_disconnect,KEY_EVENT_UP); 

    /* Set End key function to abort composing */
    SetKeyHandler(mmi_bt_bpp_composing_disconnect, KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);

    /* Set delete callback function */
    SetDelScrnIDCallbackHandler(SCR_BPP_COMPOSING, mmi_bt_bpp_composing_del_cb); 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_entry_printing
 * DESCRIPTION
 *  This function is used to entry the printing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_entry_printing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_ENTRY_PRINTING);

    /* Call Exit Handler */
    EntryNewScreen(SCR_BPP_PRINTING, mmi_bt_bpp_exit_printing, mmi_bt_bpp_entry_printing, NULL);

    /* clear all key handlers so as to restrict duplicate reqs */
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);

    mmi_bt_bpp_update_str();  
    /* Show Receiving screen */
    ShowCategory66Screen(
        STR_BT_BPP_PRINTING,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        STR_BT_BPP_BACKGROUND,
        IMG_GLOBAL_OK,
        STR_GLOBAL_CANCEL,
        0,
        (U8*) bpp_printing_prog_str_buf,
        IMG_GLOBAL_PROGRESS,
        NULL);

    StartTimer(FMGR_PROG_UPDATE_TIMER, MMI_BPP_PROG_UPD_DUR, mmi_bt_bpp_prog_update_hdlr);    

    /* Set Left softkey function to abort sending */
    SetLeftSoftkeyFunction(mmi_bt_bpp_background_print, KEY_EVENT_UP);

    /* Set Endkey / Right softkey function to abort composing */
    SetRightSoftkeyFunction(mmi_bt_bpp_printing_disconnect, KEY_EVENT_UP);
    SetKeyHandler(mmi_bt_bpp_printing_disconnect, KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);

    SetDelScrnIDCallbackHandler(SCR_BPP_PRINTING, mmi_bt_bpp_printing_del_cb);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_entry_trouble
 * DESCRIPTION
 *  This function is used to entry the trouble screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_entry_trouble(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* string;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_ENTRY_TROUBLE);
    EntryNewScreen(SCR_BPP_TROUBLE, NULL, mmi_bt_bpp_entry_trouble, NULL);

    switch(mmi_bt_bpp_get_stopped_reason())
    {
        case BT_BPP_PRINTER_REASON_JAM:
            string = (U8*) GetString(STR_BT_BPP_TROUBLE_JAM); 
            break;
        case BT_BPP_PRINTER_REASON_PAUSED:
            string = (U8*) GetString(STR_BT_BPP_TROUBLE_PAUSED); 
            break;
        case BT_BPP_PRINTER_REASON_DOOR:
            string = (U8*) GetString(STR_BT_BPP_TROUBLE_DOOR);                 
            break;
        case BT_BPP_PRINTER_REASON_MARKER:
            string = (U8*) GetString(STR_BT_BPP_TROUBLE_MARKER);                 
            break;
        case BT_BPP_PRINTER_REASON_MEDIA:
            string = (U8*) GetString(STR_BT_BPP_TROUBLE_MEDIA);                 
            break;
        default:
            string = (U8*) GetString(STR_BT_BPP_TROUBLE_NOTICE);
            break;
    }
           
    /* Show Connecting screen */
    ShowCategory66Screen(
        STR_BT_BPP_TROUBLE,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        0,
        0,
        STR_GLOBAL_CANCEL,
        0,
        string,
        IMG_GLOBAL_PROGRESS,
        NULL);
    
    /* Set Right softkey function to abort print job */
    SetRightSoftkeyFunction(mmi_bt_bpp_printing_disconnect,KEY_EVENT_UP); 

    /* Set End key function to abort print job */
    SetKeyHandler(mmi_bt_bpp_printing_disconnect, KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_disconnect_clear_scrs
 * DESCRIPTION
 *  This function is clear bpp screens while disconnecting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_disconnect_clear_scrs(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_DISCONNECT_CLEAR_SCRS);
                              
    switch (mmi_bt_bpp_get_status())
    {
        case MMI_BPP_STATUS_SETTING:
			ClearDelScrnIDCallbackHandler(SCR_BPP_PRINT_SETTING, NULL);
			ClearDelScrnIDCallbackHandler(SCR_BPP_LAYOUT_PREVIEW, NULL);
            DeleteScreenIfPresent(SCR_BPP_PRINT_SETTING);
    		DeleteScreenIfPresent(SCR_BPP_LAYOUT_PREVIEW);
    		break; 
        case MMI_BPP_STATUS_CREATING:
			ClearDelScrnIDCallbackHandler(SCR_BPP_CREATING, NULL);
            DeleteScreenIfPresent(SCR_BPP_CREATING);
			break;
        case MMI_BPP_STATUS_COMPOSING:
			ClearDelScrnIDCallbackHandler(SCR_BPP_COMPOSING, NULL);
            DeleteScreenIfPresent(SCR_BPP_COMPOSING);
			break;
            
        case MMI_BPP_STATUS_GETTING:
			ClearDelScrnIDCallbackHandler(SCR_BPP_GETTING, NULL);
            DeleteScreenIfPresent(SCR_BPP_GETTING);            
            break;
            
		case MMI_BPP_STATUS_DISCONNECTING:        
        case MMI_BPP_STATUS_NONE:
			ClearDelScrnIDCallbackHandler(SCR_BPP_GETTING, NULL);
			ClearDelScrnIDCallbackHandler(SCR_BPP_PRINT_SETTING, NULL);
			ClearDelScrnIDCallbackHandler(SCR_BPP_LAYOUT_PREVIEW, NULL);
			ClearDelScrnIDCallbackHandler(SCR_BPP_CREATING, NULL);
			ClearDelScrnIDCallbackHandler(SCR_BPP_COMPOSING, NULL);
			ClearDelScrnIDCallbackHandler(SCR_BPP_DISCONNECTING, NULL);
            DeleteScreenIfPresent(SCR_BPP_GETTING);
		    DeleteScreenIfPresent(SCR_BPP_PRINT_SETTING);
		    DeleteScreenIfPresent(SCR_BPP_LAYOUT_PREVIEW);
		    DeleteScreenIfPresent(SCR_BPP_CREATING);
		    DeleteScreenIfPresent(SCR_BPP_COMPOSING);
			DeleteScreenIfPresent(SCR_BPP_DISCONNECTING);
        case MMI_BPP_STATUS_PRINTED:
        case MMI_BPP_STATUS_CANCELED:
        case MMI_BPP_STATUS_JOB_CANCELED:
			ClearDelScrnIDCallbackHandler(SCR_BPP_PRINTING, NULL);
			ClearDelScrnIDCallbackHandler(SCR_BPP_TROUBLE, NULL);
		    DeleteScreenIfPresent(SCR_BPP_PRINTING);
		    DeleteScreenIfPresent(SCR_BPP_TROUBLE);
			break;
        default:
            ClearDelScrnIDCallbackHandler(SCR_BPP_GETTING, NULL);
			ClearDelScrnIDCallbackHandler(SCR_BPP_PRINT_SETTING, NULL);
			ClearDelScrnIDCallbackHandler(SCR_BPP_LAYOUT_PREVIEW, NULL);
			ClearDelScrnIDCallbackHandler(SCR_BPP_CREATING, NULL);
			ClearDelScrnIDCallbackHandler(SCR_BPP_COMPOSING, NULL);
			ClearDelScrnIDCallbackHandler(SCR_BPP_DISCONNECTING, NULL);
            ClearDelScrnIDCallbackHandler(SCR_BPP_PRINTING, NULL);
			ClearDelScrnIDCallbackHandler(SCR_BPP_TROUBLE, NULL);
            DeleteScreenIfPresent(SCR_BPP_GETTING);
		    DeleteScreenIfPresent(SCR_BPP_PRINT_SETTING);
		    DeleteScreenIfPresent(SCR_BPP_LAYOUT_PREVIEW);
		    DeleteScreenIfPresent(SCR_BPP_CREATING);
		    DeleteScreenIfPresent(SCR_BPP_COMPOSING);
			DeleteScreenIfPresent(SCR_BPP_DISCONNECTING);
		    DeleteScreenIfPresent(SCR_BPP_PRINTING);
		    DeleteScreenIfPresent(SCR_BPP_TROUBLE);

            return;            
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_deinit_clear_scrs
 * DESCRIPTION
 *  This function is clear bpp screens while bt panic reset
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_deinit_clear_scrs(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 cur_scr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_DEINIT_CLEAR_SCRS);

    /* clear all bpp screens in history */                              
    DeleteScreenIfPresent(SCR_BPP_CONNECTING);
    DeleteScreenIfPresent(SCR_BPP_AUTHENTICATING);
    DeleteScreenIfPresent(SCR_BPP_GETTING);
    DeleteScreenIfPresent(SCR_BPP_PRINT_SETTING);
    DeleteScreenIfPresent(SCR_BPP_LAYOUT_PREVIEW);
    DeleteScreenIfPresent(SCR_BPP_CREATING);
    DeleteScreenIfPresent(SCR_BPP_COMPOSING);
    DeleteScreenIfPresent(SCR_BPP_PRINTING);
    DeleteScreenIfPresent(SCR_BPP_TROUBLE);
    DeleteScreenIfPresent(SCR_BPP_DISCONNECTING);

    /* check active screen for goback or not */
    cur_scr_id = GetActiveScreenId();
    switch (cur_scr_id)
    {
        case SCR_BPP_CONNECTING:
        case SCR_BPP_AUTHENTICATING:
        case SCR_BPP_GETTING:
        case SCR_BPP_PRINT_SETTING:
        case SCR_BPP_LAYOUT_PREVIEW:
        case SCR_BPP_CREATING:
        case SCR_BPP_COMPOSING:
        case SCR_BPP_PRINTING:
        case SCR_BPP_TROUBLE:
        case SCR_BPP_DISCONNECTING:
            GoBackHistory();
        default:
            return;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_popup
 * DESCRIPTION
 *  This function is an popup utility function
 * PARAMETERS
 *  mmi_bpp_popup_cause_enum
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_popup(mmi_bpp_popup_cause_enum cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 string; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG1(MMI_BPP_POPUP, cause);
    
    switch(cause)
    {
        case MMI_BPP_POPUP_CAUSE_PRINTER_BUSY:
            string = (PU8) GetString(STR_BT_BPP_POPUP_PRINTER_BUSY);
            DisplayPopup(string, IMG_GLOBAL_WARNING, 0, UI_POPUP_NOTIFYDURATION_TIME, (U8) WARNING_TONE);
            return;
        case MMI_BPP_POPUP_CAUSE_AUTH_FAILED:
            string = (PU8) GetString(STR_BT_BPP_POPUP_AUTH_FAILED);
            break;
        case MMI_BPP_POPUP_CAUSE_CONNECT_FAILED:
            string = (PU8) GetString(STR_BT_BPP_POPUP_CONNECT_FAILED);
            break;
        case MMI_BPP_POPUP_CAUSE_GET_ATTR_FAILED:
            string = (PU8) GetString(STR_BT_BPP_POPUP_GET_ATTR_FAILED);
            break;
        case MMI_BPP_POPUP_CAUSE_CREATE_JOB_FAILED:
            string = (PU8) GetString(STR_BT_BPP_POPUP_CREATE_JOB_FAILED);
            break;
        case MMI_BPP_POPUP_CAUSE_COMPOSE_FAILED:
            string = (PU8) GetString(STR_BT_BPP_POPUP_COMPOSE_FAILED);
            break;            
        case MMI_BPP_POPUP_CAUSE_READ_FILE_FAILED:
            string = (PU8) GetString(STR_BT_BPP_POPUP_READ_FILE_FAILED);
            break;            
        case MMI_BPP_POPUP_CAUSE_TROUBLE:
            switch(mmi_bt_bpp_get_stopped_reason())
            {
                case BT_BPP_PRINTER_REASON_JAM:
                    string = (U8*) GetString(STR_BT_BPP_TROUBLE_JAM); 
                    break;
                case BT_BPP_PRINTER_REASON_PAUSED:
                    string = (U8*) GetString(STR_BT_BPP_TROUBLE_PAUSED); 
                    break;
                case BT_BPP_PRINTER_REASON_DOOR:
                    string = (U8*) GetString(STR_BT_BPP_TROUBLE_DOOR);                 
                    break;
                case BT_BPP_PRINTER_REASON_MARKER:
                    string = (U8*) GetString(STR_BT_BPP_TROUBLE_MARKER);                 
                    break;
                case BT_BPP_PRINTER_REASON_MEDIA:
                    string = (U8*) GetString(STR_BT_BPP_TROUBLE_MEDIA);                 
                    break;
                default:
                    string = (U8*) GetString(STR_BT_BPP_TROUBLE_NOTICE);
                    break;
            }
            DisplayPopup(string, IMG_GLOBAL_WARNING, 0, UI_POPUP_NOTIFYDURATION_TIME, (U8) WARNING_TONE);
            return;
        case MMI_BPP_POPUP_CAUSE_CANCELED:
            string = (PU8) GetString(STR_BT_BPP_POPUP_CANCELED);
            break;                        
        case MMI_BPP_POPUP_CAUSE_DISCONNECTED:
            string = (PU8) GetString(STR_BT_BPP_POPUP_DISCONNECTED);
            break;            
        case MMI_BPP_POPUP_CAUSE_FORMAT_WARNING:
            string = (PU8) GetString(STR_BT_BPP_POPUP_FORMAT_WARNING);
            DisplayPopup(string, IMG_GLOBAL_WARNING, 0, UI_POPUP_NOTIFYDURATION_TIME, (U8) WARNING_TONE);
            return;
        case MMI_BPP_POPUP_CAUSE_PRINTING:
            string = (PU8) GetString(STR_BT_BPP_PRINTING);
            DisplayPopup(string, IMG_GLOBAL_ACTIVATED, 0, UI_POPUP_NOTIFYDURATION_TIME, (U8) WARNING_TONE);
            return;
        case MMI_BPP_POPUP_CAUSE_BACKGROUND_PRINTING:
            string = (PU8) GetString(STR_BT_BPP_POPUP_BACKGROUND_PRINTING);
            DisplayPopup(string, IMG_GLOBAL_ACTIVATED, 0, UI_POPUP_NOTIFYDURATION_TIME, (U8) WARNING_TONE);
            return;
        case MMI_BPP_POPUP_CAUSE_PRINTED:
            string = (PU8) GetString(STR_BT_BPP_POPUP_PRINTED);            
            DisplayPopup(string, IMG_GLOBAL_ACTIVATED, 0, UI_POPUP_NOTIFYDURATION_TIME, (U8) WARNING_TONE);
            return;
        default:
        	  string = (PU8)GetString(STR_GLOBAL_UNFINISHED); 
        	  break;
        	/*
            ASSERT(0);
            return;
          */
        }
    DisplayPopup(string, IMG_GLOBAL_ERROR, 0, UI_POPUP_NOTIFYDURATION_TIME, (U8) ERROR_TONE);
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_popup
 * DESCRIPTION
 *  This function is an popup utility function
 * PARAMETERS
 *  mmi_bpp_popup_cause_enum
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_bt_bpp_blinking(mmi_bpp_blink_enum action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG1(MMI_BPP_BLINKING, action);

    switch(action)
    {
        case MMI_BPP_BLINK_START:
            mmi_bt_status_icon_start_blinking(MMI_BTH_BASIC_PRINTING, MMI_BT_CLIENT_ROLE);                                                        
            return;
        /* MMI_BPP_BLINK_STOP */
        default:                        
            mmi_bt_status_icon_stop_blinking(MMI_BTH_BASIC_PRINTING, MMI_BT_CLIENT_ROLE);
            return;
    }                 
}


#endif /* defined(__MMI_BPP_SUPPORT__) */ 
#endif /* __MMI_BT_MTK_SUPPORT__ */
