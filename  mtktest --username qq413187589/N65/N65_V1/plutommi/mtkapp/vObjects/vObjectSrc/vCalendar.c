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
 * vCalendar.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file is implements vCalendar application.
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef _MMI_VCALENDAR_C
#define _MMI_VCALENDAR_C
/*  Include: MMI header file */
#if defined(__MMI_VCALENDAR__)

#include "CommonScreens.h"
#include "Asciiprot.h"

#include "vCalendar.h"
#include "vObjects.h"
#include "ToDoListDef.h"
#include "AlarmFrameworkProt.h"
#include "DateTimeGprot.h"
#include "ToDoListEnum.h"
#include "ToDoListDef.h"
#include "EmsMiscell.h"
#include "IrdaMMIGprots.h"
#include "FileMgr.h"
#include "FileManagerGProt.h"
#include "fmt_struct.h"
#include "MessagesExDcl.h"
#include "SimDetectionGexdcl.h"

#if defined(MMS_SUPPORT)
#include "Wapadp.h"
#endif 

#define VCLNDR_TEST_CODE
#include "Conversions.h"
#include "app_qp.h"
#include "PhoneSetupGprots.h"

#ifdef __MMI_OPP_SUPPORT__
#include "OPPMMIGprots.h"
#include "ExtDeviceDefs.h"
#endif /* __MMI_OPP_SUPPORT__ */ 
#include "datetimetype.h"
#include "app_datetime.h"

#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#endif /* __USB_IN_NORMAL_MODE__ */ 

#include "SimDetectionGprot.h" /* mmi_bootup_is_sim_valid, mmi_bootup_get_active_flight_mode */

#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_AD_master_header.h"
#include "MTPNP_AD_resdef.h"
#include "MTPNP_PFAL_Master_Msgs.h"
#include "MTPNP_PFAL_resource.h"

#if (!defined (__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__))
#include "SMSApi.h"
#endif

#endif /* __MMI_DUAL_SIM_MASTER__ */

/* 
 * Typedef 
 */

/* 
 * Define
 */

#define  VCLNDR_MAX_DT_LEN          24
#define  VCLNDR_NUM_OF_DAYS            7
#define  VCLNDR_MIN_RECURR_LEN         5
#define  VCLNDR_MAX_PARAM_LEN       24

#define  VCLNDR_DT_SEP_CHAR            'T'      /* seperator of date and time */
#define  VCLNDR_UTC_CHAR               'Z'
#define  VCLNDR_POUND_CHAR          '#'
#define  VCLNDR_PARA_SEP_CHAR       ';'
#define  VCLNDR_VALUE_SEP_CHAR         ':'

#define  VCLNDR_ES_CHAR             0x5C        /* "\" */
#define  VCLNDR_LWSP_CHAR           0x20
#define  VCLNDR_TAB_CHAR               0x09

#define  VCLNDR_R_FOREVER_STR       " #0"
#define  VCLNDR_PARA_SEP_STR           ";"
#define  VCLNDR_VALUE_SEP_STR         ":"
#define  VCLNDR_EQUAL_STR           "="
#define  VCLNDR_CHARSET_UTF8        "UTF-8"

#define VCLNDR_REMOVE_PRE_WS    0
#define VCLNDR_REMOVE_POST_WS    1
#define VCLNDR_REMOVE_BOTH_WS    2

#ifdef __MMI_ADVANCED_TODO__
#define VCLNDR_CATEGORY_REMINDER    "Reminder"    
#define VCLNDR_CATEGORY_MEETING     "Meeting"    
#define VCLNDR_CATEGORY_COURSE      "Course"    
#define VCLNDR_CATEGORY_DATE        "Date"    
#define VCLNDR_CATEGORY_CALL        "Call"    
#define VCLNDR_CATEGORY_ANNIVERSARY "Anniversary"    
#endif
/* 
 * Local Variable
 */

/* 
 * Local Function
 */
extern S32 mmi_vclndr_writer(ToDoListNode *, S8 *);
extern BOOL mmi_vlcndr_uti_flush_to_file(FS_HANDLE, S8 *);
extern S32 mmi_vclndr_reader(S8 *, ToDoListNode *);
extern S32 mmi_vobj_uti_get_line(S8 *strOutput, FS_HANDLE fh);

/* 
 * Global Variable
 */
extern const S8 *g_vobj_charset[];
vclndr_context_struct g_vclndr_cntx;

const S8 *const g_vclndr_fileds[VCLNDR_TOTAL_FILEDS] = 
{
    "BEGIN:VCALENDAR",
    "VERSION:1.0",
    "BEGIN:VEVENT",
    "BEGIN:VTODO",
    "DTSTART",
    "DTEND",
    "DUE",
    "SUMMARY",
    "DESCRIPTION",
    "RRULE",
    "DALARM",
    "AALARM",
    "END:VTODO",
    "END:VEVENT",
    "END:VCALENDAR",
    "CLASS",
    "LOCATION",
    "PRIORITY",
    "COMPLETED",
    "LAST-MODIFIED",
    "CATEGORIES",
    "UID",
    "X-",
    "PRODID"
};

const S8 *const g_vclndr_days[VCLNDR_NUM_OF_DAYS] = 
{
    "SU", "MO", "TU", "WE", "TH", "FR", "SA"
};

const S8 *const g_vclndr_recurr[VCLNDR_RECURR_TOTAL] = 
{
    "D1",
    "W1",
    "MD1",
    "YM1"
};
extern const S8 *g_vobj_encoding[];
extern const S8 *g_vobj_paras[];

/* 
 * Global Function
 */
extern U8 TDLGetTotalItem(void);
extern FLOAT GetTimeZone(U8);
extern U8 PhnsetGetHomeCity(void);
extern BOOL GetUCS2Flag(S8 *);

#define VCLNDR_INITIALIZATION


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_init
 * DESCRIPTION
 *  Init function of vCalendar.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vclndr_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_VCLNDR_FORWARD, mmi_vclndr_highlight_forward);

    SetHiliteHandler(MENU_VCLNDR_RECV_OPT_TDL, mmi_vclndr_highlight_recv_opt_save_to_tdl);

#if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
    SetHiliteHandler(MENU_VCLNDR_SEND_BY_SMS, mmi_vclndr_sms_highlight_forward);
#endif 

#if defined(__MMI_MMS__)
    SetHiliteHandler(MENU_VCLNDR_SEND_BY_MMS, mmi_vclndr_mms_highlight_forward);
#endif 

#if defined(__MMI_IRDA_SUPPORT__)
    SetHiliteHandler(MENU_VCLNDR_SEND_BY_IRDA, mmi_vclndr_irda_highlight_forward);
#endif 

#if defined(__MMI_OPP_SUPPORT__)
    SetHiliteHandler(MENU_VCLNDR_SEND_BY_BT, mmi_vclndr_opp_highlight_forward);
#endif 

#if defined(EMAIL_APP_SUPPORT)
    SetHiliteHandler(MENU_VCLNDR_SEND_BY_EMAIL, mmi_vclndr_email_highlight_forward);
#endif 

#if defined(__MMI_FILE_MANAGER__)
    SetHiliteHandler(MENU_VCLNDR_OPT_INPUT_METHOD, mmi_vclndr_highlight_opt_input_method);
    SetHiliteHandler(MENU_VCLNDR_OPT_DONE, mmi_vclndr_highlight_opt_done);
#if defined(__FS_MOVE_SUPPORT__)
    SetHiliteHandler(MENU_VCLNDR_RECV_OPT_FMGR, mmi_vclndr_highlight_recv_opt_save_to_file);
#endif 
    SetHiliteHandler(MENU_VCLNDR_SEND_BY_FILEMGR, mmi_vclndr_fmgr_highlight_forward);
#endif /* defined(__MMI_FILE_MANAGER__) */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_deinit
 * DESCRIPTION
 *  Deinit vCalendar applicatoin
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vclndr_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vclndr_free_buffer();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_free_buffer
 * DESCRIPTION
 *  Release all dynamic allocated memory used in vCalendar.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vclndr_free_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vclndr_cntx.FilePathPtr)
    {
        OslMfree(g_vclndr_cntx.FilePathPtr);
        g_vclndr_cntx.FilePathPtr = NULL;
    }

    if (g_vclndr_cntx.FileNamePtr)
    {
        OslMfree(g_vclndr_cntx.FileNamePtr);
        g_vclndr_cntx.FileNamePtr = NULL;
    }
}

#define VCLNDR_SCREENS


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_highlight_forward
 * DESCRIPTION
 *  Highlight handler of Forward option in To Do List application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vclndr_highlight_forward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vclndr_entry_forward, KEY_EVENT_UP);
    SetKeyHandler(mmi_vclndr_entry_forward, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_entry_forward
 * DESCRIPTION
 *  Entry function of Forward option in To Do List application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vclndr_entry_forward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[6];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;         /* Stores no of children in the submenu */
#ifdef __USB_IN_NORMAL_MODE__
    S8 path[VOBJ_MAX_PATH_LENGTH];
#endif /* __USB_IN_NORMAL_MODE__ */
    U8 sim_check = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ExecuteCurrExitHandler(); */

#ifdef __USB_IN_NORMAL_MODE__
    mmi_vobj_get_full_path_name(0, path, MMI_VOBJ_UNRECOGNIZED);   

    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */

        if (mmi_usb_check_path_exported((PS8) path))
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 
    EntryNewScreen(SCR_ID_VCLNDR_FORWARD, NULL, mmi_vclndr_entry_forward, NULL);
    SetDelScrnIDCallbackHandler(SCR_ID_VCLNDR_FORWARD, (HistoryDelCBPtr)mmi_vclndr_forward_option_delete_cb);

    if (g_tdl_cntx.TotalListedTask != 0)
    {
        g_tdl_cntx.CurrTaskIndex = g_tdl_cntx.SortedList[g_tdl_cntx.CurrSelectedTask];
    }
    
    /* if sim is invalid, hide SMS, MMS, Email, else unhide them. */
    /* if it is in flight mode, hide BT, irda, else unhide them. */
#if defined(__MMI_VCALENDAR__) && defined(MMI_ON_HARDWARE_P)
#ifdef __MMI_DUAL_SIM_MASTER__
    switch (MTPNP_AD_Get_Startup_Mode())
    {
        case MTPNP_AD_NVRAM_CARD1:
            if (mmi_bootup_is_sim_valid() == MMI_FALSE)
            {
                sim_check = MMI_FALSE; 
            }
    	    break;
        case MTPNP_AD_NVRAM_CARD2:
            if (mmi_bootup_is_sim2_valid() == MMI_FALSE)
            {
                sim_check = MMI_FALSE; 
            }
    	    break;
        case MTPNP_AD_NVRAM_DUALCARD:
            if (mmi_bootup_is_sim_valid() == MMI_FALSE && mmi_bootup_is_sim2_valid() == MMI_FALSE)
            {
                sim_check = MMI_FALSE; 
            }        
    	    break;
    }

    #ifdef __FLIGHT_MODE_SUPPORT__
        if (mmi_bootup_get_active_flight_mode() == 1)
        {
            sim_check = MMI_FALSE; 
        }
    #endif    
#else /*__MMI_DUAL_SIM_MASTER__*/
    if (mmi_bootup_is_sim_valid() == MMI_FALSE
    #ifdef __FLIGHT_MODE_SUPPORT__
        || mmi_bootup_get_active_flight_mode() == 1
    #endif 
        )  
    {
        sim_check = MMI_FALSE;
    }
#endif /*__MMI_DUAL_SIM_MASTER__*/

    if (sim_check == MMI_FALSE)
    {
    #if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)	
        mmi_frm_hide_menu_item(MENU_VCLNDR_SEND_BY_SMS);
    #endif
    #if defined(__MMI_MMS__)
        mmi_frm_hide_menu_item(MENU_VCLNDR_SEND_BY_MMS);
    #endif
    #if  defined(EMAIL_APP_SUPPORT)
        mmi_frm_hide_menu_item(MENU_VCLNDR_SEND_BY_EMAIL);                
    #endif        
    }
    else
    {
    #if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)	
        mmi_frm_unhide_menu_item(MENU_VCLNDR_SEND_BY_SMS);
    #endif
    #if defined(__MMI_MMS__)
        mmi_frm_unhide_menu_item(MENU_VCLNDR_SEND_BY_MMS);
    #endif
    #if  defined(EMAIL_APP_SUPPORT)
        mmi_frm_unhide_menu_item(MENU_VCLNDR_SEND_BY_EMAIL);                
    #endif
    }
    
#ifdef __FLIGHT_MODE_SUPPORT__
    if (mmi_bootup_get_active_flight_mode() == 1)
    {
    #if  defined(__MMI_IRDA_SUPPORT__)
       mmi_frm_hide_menu_item(MENU_VCLNDR_SEND_BY_IRDA);
    #endif
    #if  defined(__MMI_OPP_SUPPORT__)
        mmi_frm_hide_menu_item(MENU_VCLNDR_SEND_BY_BT);
    #endif
    }
    else
    {
    #if  defined(__MMI_IRDA_SUPPORT__)
        mmi_frm_unhide_menu_item(MENU_VCLNDR_SEND_BY_IRDA);
    #endif
    #if  defined(__MMI_OPP_SUPPORT__)
        mmi_frm_unhide_menu_item(MENU_VCLNDR_SEND_BY_BT);
    #endif
    }
#endif   

#if (defined(__MMI_DUAL_SIM_MASTER__)) && (!defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__))	
    if (mmi_frm_sms_is_hide_send_sms_menu_item() == TRUE)
    {
    	mmi_frm_hide_menu_item(MENU_VCLNDR_SEND_BY_SMS);        
    }
    else
    {    	
    	mmi_frm_unhide_menu_item(MENU_VCLNDR_SEND_BY_SMS);
    }
#endif

#endif /* defined(__MMI_VCALENDAR__) && defined(MMI_ON_HARDWARE_P) */

	nNumofItem = GetNumOfChild_Ext(MENU_VCLNDR_FORWARD);
    GetSequenceStringIds_Ext(MENU_VCLNDR_FORWARD, nStrItemList);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_VCLNDR_FORWARD);

    SetParentHandler(MENU_VCLNDR_FORWARD);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler_Ext);
    
    /* 8 Display Category Screen */
    ShowCategory15Screen(
        STR_ID_VCLNDR_FORWARD,
        GetRootTitleIcon(ORGANIZER_TODOLIST_MENU),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);

   /* SetRightSoftkeyFunction(mmi_tdl_task_list_goback, KEY_EVENT_UP); */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    /* SetGenericExitHandler(SCR_ID_VCLNDR_FORWARD, NULL, mmi_vclndr_entry_forward); */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_forward_option_delete_cb
 * DESCRIPTION
 *  Delete callback function of forward option, screen.
 *  Delete temp file.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/    
U8 mmi_vclndr_forward_option_delete_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 path[VOBJ_MAX_PATH_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vclndr_uti_get_default_filename(path);   
    FS_Delete((U16*) path);
    
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_recv_file_pre_entry_options
 * DESCRIPTION
 *  pre entry func for showing vcalendar options after receiving via SMS/BT/IRDA
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vclndr_recv_file_pre_entry_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	mmi_vclndr_entry_recv_option();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_entry_recv_option
 * DESCRIPTION
 *  Display option screen when receiving an vCalendar object
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vclndr_entry_recv_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[VCLNDR_OPT_TOTAL]; /* Stores the strings id of submenus returned */
    U16 nNumofItem;                     /* Stores no of children in the submenu */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ExecuteCurrExitHandler(); */
    EntryNewScreen(SCR_ID_VCLNDR_RECV_OPT, NULL, mmi_vclndr_entry_recv_option, NULL);

    nNumofItem = GetNumOfChild(MENU_VCLNDR_RECV_OPTION);
    GetSequenceStringIds(MENU_VCLNDR_RECV_OPTION, nStrItemList);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_VCLNDR_RECV_OPT);

    SetParentHandler(MENU_VCLNDR_RECV_OPTION);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* 8 Display Category Screen */
    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(ORGANIZER_TODOLIST_MENU),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    /* SetGenericExitHandler(SCR_ID_VCLNDR_RECV_OPT, NULL, mmi_vclndr_entry_recv_option); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_highlight_recv_opt_save_to_tdl
 * DESCRIPTION
 *  Highlight handler of save to to do list option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vclndr_highlight_recv_opt_save_to_tdl(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vclndr_recv_save_to_tdl, KEY_EVENT_UP);
    SetKeyHandler(mmi_vclndr_recv_save_to_tdl, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_recv_save_to_tdl
 * DESCRIPTION
 *  Handler of Save To To Do List option when receiving a vCalendar.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vclndr_recv_save_to_tdl(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result = VOBJ_ERR_NO_ERROR;
    S8 path_name[VOBJ_MAX_PATH_LENGTH];
    ToDoListNode task;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vobj_get_full_path_name(g_vobj_cntx.buffer_begin, path_name, MMI_VOBJ_VCLNDR);

    g_vclndr_cntx.vcalendar_encoding = (mmi_chset_enum)PhnsetGetDefEncodingType();
    if ((result = mmi_vclndr_reader(path_name, &task)) == VOBJ_ERR_NO_ERROR)
    {
        if (TdlInsertTask(&task, TODO_FROM_NETWORK))
        {
            result = VOBJ_ERR_NO_ERROR;
        }
        else
        {
            result = VOBJ_ERR_MEMORY_FULL;
        }
    }

    switch (result)
    {
        case VOBJ_ERR_NO_ERROR:
            break;
        case VOBJ_ERR_MEMORY_FULL:
            DisplayPopup(
                (U8*) GetString(STR_ID_VCLNDR_TASK_FULL),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
            break;
        case VOBJ_ERR_UNSUPPORT_FORMAT:
            DisplayPopup(
                (U8*) GetString(STR_ID_VOBJ_FORMAT_NOT_SUPPORT),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
            break;
        default:    /* case VOBJ_ERR_NO_ERROR: */
            DisplayPopup(
                (PU8) GetString(GetFileSystemErrorString(result)),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_popup_not_support
 * DESCRIPTION
 *  Popup not supported screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vclndr_popup_not_support(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup(
        (U8*) GetString(STR_ID_VOBJ_FUNC_NOT_SUPPORTED),
        IMG_GLOBAL_ERROR,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        ERROR_TONE);
}

#define  VCLNDR_SAVE_FILE


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_entry_filename
 * DESCRIPTION
 *  Full screen editor to edit filename
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vclndr_entry_filename(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ExecuteCurrExitHandler(); */
    EntryNewScreen(SCR_ID_VCLNDR_FILENAME, NULL, mmi_vclndr_entry_filename, NULL);

    SetParentHandler(0);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_VCLNDR_FILENAME);

    ShowCategory5Screen(
        STR_ID_VOBJ_FILENAME,
        GetRootTitleIcon(ORGANIZER_TODOLIST_MENU),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,   /* |INPUT_TYPE_USE_ENCODING_BASED_LENGTH */
        (U8*) g_vclndr_cntx.FileNamePtr,
        VOBJ_MAX_FILENAME_LENGTH / ENCODING_LENGTH,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_vclndr_entry_filename_option, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* SetGenericExitHandler(SCR_ID_VCLNDR_FILENAME, NULL, mmi_vclndr_entry_filename); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_entry_filename_option
 * DESCRIPTION
 *  Display option screen for filename
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vclndr_entry_filename_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 ItemList[2];
    U16 nItems;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ExecuteCurrExitHandler(); */
    EntryNewScreen(SCR_ID_VCLNDR_FILENAME_OPT, NULL, mmi_vclndr_entry_filename_option, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_VCLNDR_FILENAME_OPT);
    SetParentHandler(MENU_VCLNDR_FILENAME_OPT);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    nItems = GetNumOfChild(MENU_VCLNDR_FILENAME_OPT);
    GetSequenceStringIds(MENU_VCLNDR_FILENAME_OPT, ItemList);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(ORGANIZER_TODOLIST_MENU),
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

    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    /* SetGenericExitHandler(SCR_ID_VCLNDR_FILENAME_OPT, NULL, mmi_vclndr_entry_filename_option); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_goback_1_history
 * DESCRIPTION
 *  Go back 1 history.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vclndr_goback_1_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBacknHistory(1);
}

#define VCLNDR_COMMON_INTERFACE
#if defined(__MMI_IRDA_SUPPORT__)


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_irda_highlight_forward
 * DESCRIPTION
 *  Highlight handler of Send To Irda option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vclndr_irda_highlight_forward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vclndr_irda_forward, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_irda_forward
 * DESCRIPTION
 *  Forward a task to Irda
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vclndr_irda_forward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 path[VOBJ_MAX_PATH_LENGTH];
    U8 i;
    S32 check_result = mmi_vobj_fs_check_folder();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (check_result == FS_NO_ERROR)
    {
        S32 result;

        mmi_vclndr_uti_get_default_filename(path);

        i = g_tdl_cntx.CurrTaskIndex;
        FS_Delete((U16*) path);
        result = mmi_vclndr_writer(&g_tdl_cntx.TaskList[i], path);

        if (result != VOBJ_ERR_NO_ERROR)
        {
            FS_Delete((U16*) path);
            DisplayPopup(
                (PU8) GetString(GetFileSystemErrorString(result)),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            return;
        }

        if (MMI_IRDA_ERR_SUCCESS == mmi_irda_send_file_obj(path, mmi_vclndr_irda_forward_callback))
        {
            mmi_vobj_entry_irda_processing_screen();
        }

    }
    else
    {
        /* display popup screen for error */
        DisplayPopup(
            (PU8) GetString(GetFileSystemErrorString(check_result)),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_irda_forward_callback
 * DESCRIPTION
 *  Callback function for Irda application when sending via Irda.
 * PARAMETERS
 *  buf_p       [IN]        Unknown
 *  result      [IN]        Result state for sending
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vclndr_irda_forward_callback(void *buf_p, U32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (buf_p != NULL)
    {
        OslMfree(buf_p);
        buf_p = NULL;
    }

    mmi_vclndr_uti_del_default_file();

    if (result == MMI_IRDA_ERR_SUCCESS)
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            SUCCESS_TONE);
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_ERROR,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
    }

    DeleteBetweenScreen(SCR_ID_VCLNDR_FORWARD, SCR_ID_VOBJ_IRDA_FORWARD_PROCESSING);

    /* DeleteUptoScrID(SCR_TDL_TASK_LIST); */
}
#endif /* defined(__MMI_IRDA_SUPPORT__) */ // #if  defined(__MMI_IRDA_SUPPORT__)

#if defined(__MMI_OPP_SUPPORT__)


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_opp_highlight_forward
 * DESCRIPTION
 *  Highlight handler of Send To Bluetooth option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vclndr_opp_highlight_forward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vclndr_opp_forward, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_opp_forward
 * DESCRIPTION
 *  Forward a task to Bluetooth
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vclndr_opp_forward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 path[VOBJ_MAX_PATH_LENGTH];
    U8 i;
    S32 check_result = mmi_vobj_fs_check_folder();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (check_result == FS_NO_ERROR)
    {
        S32 result;

        mmi_vclndr_uti_get_default_filename(path);

        i = g_tdl_cntx.CurrTaskIndex;
        FS_Delete((U16*) path);
        result = mmi_vclndr_writer(&g_tdl_cntx.TaskList[i], path);

        if (result != VOBJ_ERR_NO_ERROR)
        {
            FS_Delete((U16*) path);
            DisplayPopup(
                (PU8) GetString(GetFileSystemErrorString(result)),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            return;
        }
        if (MMI_OPP_ERR_SUCCESS == mmi_opp_discovery_device((PS8) path, mmi_vclndr_opp_forward_callback))
        {
            mmi_opp_entry_opp_device_discovery();
        }

    }
    else
    {
        /* display popup screen for error */
        DisplayPopup(
            (PU8) GetString(GetFileSystemErrorString(check_result)),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_opp_forward_callback
 * DESCRIPTION
 *  Callback function for Opp application when sending via Bluetooth.
 * PARAMETERS
 *  buf_p       [IN]        Unknown
 *  result      [IN]        Result state for sending
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vclndr_opp_forward_callback(void *buf_p, U32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (buf_p != NULL)
    {
        OslMfree(buf_p);
        buf_p = NULL;
    }

    mmi_vclndr_uti_del_default_file();

    if (result == MMI_OPP_ERR_SUCCESS)
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            SUCCESS_TONE);
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_ERROR,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
    }

    DeleteBetweenScreen(SCR_ID_VCLNDR_FORWARD, SCR_OPP_SENDING);

    /* DeleteUptoScrID(SCR_TDL_TASK_LIST); */
}
#endif /* defined(__MMI_OPP_SUPPORT__) */ // #if  defined(__MMI_OPP_SUPPORT__)

#if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_sms_forward_callback
 * DESCRIPTION
 *  Callback function used by sending SMS. Delete temporary file.
 * PARAMETERS
 *  flag        [IN]        Unknown
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vclndr_sms_forward_callback(void *flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vclndr_uti_del_default_file();

    /* DeleteUptoScrID(SCR_TDL_TASK_LIST); */

    DeleteScreenIfPresent(SCR_ID_VCLNDR_FORWARD);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_sms_forward
 * DESCRIPTION
 *  Forward a task to SMS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vclndr_sms_forward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 check_result = mmi_vobj_fs_check_folder();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (check_result == FS_NO_ERROR)
    {
        S32 result;
        S8 path[VOBJ_MAX_PATH_LENGTH];
        U8 i;

        mmi_vclndr_uti_get_default_filename(path);

        i = g_tdl_cntx.CurrTaskIndex;

        result = mmi_vclndr_writer(&g_tdl_cntx.TaskList[i], path);
        if (result != VOBJ_ERR_NO_ERROR)
        {
            FS_Delete((U16*) path);
            DisplayPopup(
                (PU8) GetString(GetFileSystemErrorString(result)),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            return;
        }
        mmi_ems_vobject_send_by_ems(0x0000, VOBJ_VCLNDR_PORT, path, mmi_vclndr_sms_forward_callback);
    }
    else
    {
        /* display popup screen for error */
        DisplayPopup(
            (PU8) GetString(GetFileSystemErrorString(check_result)),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_sms_highlight_forward
 * DESCRIPTION
 *  Highlight handler of Send To SMS option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vclndr_sms_highlight_forward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vclndr_sms_forward, KEY_EVENT_UP);
    SetKeyHandler(mmi_vclndr_sms_forward, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
#endif /* !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__) */ // #if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)

#if defined(__MMI_MMS__)


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_mms_highlight_forward
 * DESCRIPTION
 *  Highlight handler of Send To MMS option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vclndr_mms_highlight_forward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vclndr_mms_forward, KEY_EVENT_UP);
    SetKeyHandler(mmi_vclndr_mms_forward, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_mms_forward
 * DESCRIPTION
 *  Create temporary file and forward to MMS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vclndr_mms_forward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 check_result = mmi_vobj_fs_check_folder();
    S8 file_path_name[MAX_TODO_LIST_NOTE]; 
    S8 *new_path;  

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (check_result == FS_NO_ERROR)
    {
        mms_content_entry_struct data;
        S8 ascii_path[VOBJ_MAX_PATH_LENGTH / ENCODING_LENGTH];
        S8* path;
        U8 i;
        S32 result;
        
        i = g_tdl_cntx.CurrTaskIndex;        
        memset(&data, 0x00, sizeof(mms_content_entry_struct));
        path = OslMalloc(VOBJ_MAX_PATH_LENGTH);

        sprintf(ascii_path, "%c:\\%s\\", VOBJ_DRV, VOBJ_FILE_PATH);
        mmi_asc_to_ucs2(path, ascii_path);
        if (!mmi_fmgr_is_filename_valid((S8*)g_tdl_cntx.TaskList[i].Note))
        {
            mmi_vclndr_uti_get_default_filename(path);        
        }
        else
        {
            /* Skip white space in front of the file name */
            mmi_ucs2cpy((S8*)file_path_name, (S8*)g_tdl_cntx.TaskList[i].Note);
            new_path = mmi_fmgr_skip_space((S8*)file_path_name);
            
            mmi_ucs2cat((S8*)path, (S8*)new_path);
            mmi_ucs2cat(path, (S8*)L".vcs");
        }

		result = mmi_vclndr_writer(&g_tdl_cntx.TaskList[i], path);
        if (result != VOBJ_ERR_NO_ERROR)
        {
            FS_Delete((U16*) path);
			OslMfree(path);
            DisplayPopup(
                (PU8) GetString(GetFileSystemErrorString(result)),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            return;
        }

        data.mode = MEA_NEW_FILE;
        data.file_path = path;
        data.callback = mmi_vclndr_forward_mms_cb;
        data.callback_param = path;
        mms_content_insert_hdlr_with_callback(&data);
    }
    else
    {
        /* display popup screen for error */
        DisplayPopup(
            (PU8) GetString(GetFileSystemErrorString(check_result)),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_forward_mms_cb
 * DESCRIPTION
 *  callback function of forwarding MMS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vclndr_forward_mms_cb(void *param)
{
    if (param != NULL)
    {
        OslMfree(param);
    }
    FS_Delete((U16*) param);
    DeleteScreenIfPresent(SCR_ID_VCLNDR_FORWARD);
}


#endif /* defined(__MMI_MMS__) */ // #if defined(__MMI_MMS__)

#if defined(EMAIL_APP_SUPPORT)


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_email_highlight_forward
 * DESCRIPTION
 *  Highlight handler of Send To Email option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vclndr_email_highlight_forward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vclndr_popup_not_support, KEY_EVENT_UP);
    SetKeyHandler(mmi_vclndr_popup_not_support, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
#endif /* defined(EMAIL_APP_SUPPORT) */ // #if defined(EMAIL_APP_SUPPORT)

#if defined(__MMI_FILE_MANAGER__)


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_fmgr_highlight_forward
 * DESCRIPTION
 *  Highlight handler of Send To File Manager option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vclndr_fmgr_highlight_forward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vclndr_cntx.SrcType = VCLNDR_SAVE_FROM_TDL;
    SetLeftSoftkeyFunction(mmi_vclndr_fmgr_forward, KEY_EVENT_UP);
    SetKeyHandler(mmi_vclndr_fmgr_forward, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_fmgr_forward
 * DESCRIPTION
 *  Forward file to file manager
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vclndr_fmgr_forward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);

    mmi_fmgr_select_path_and_enter(
        APP_TODOLIST,
        FMGR_SELECT_FOLDER,
        filter,
        (S8*) L"root",
        mmi_vclndr_fmgr_select_path_done);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_highlight_recv_opt_save_to_file
 * DESCRIPTION
 *  Highlight handler of save to file option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vclndr_highlight_recv_opt_save_to_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vclndr_cntx.SrcType = VCLNDR_SAVE_FROM_RECV;
    SetLeftSoftkeyFunction(mmi_vclndr_fmgr_forward, KEY_EVENT_UP);
    SetKeyHandler(mmi_vclndr_fmgr_forward, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_fmgr_select_path_done
 * DESCRIPTION
 *  Callback function for file manager when path selection finished.
 * PARAMETERS
 *  path            [IN]        User selected path
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vclndr_fmgr_select_path_done(void *path, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (path)
    {
        U8 i;

        i = g_tdl_cntx.CurrTaskIndex;

        if (g_vclndr_cntx.FilePathPtr == NULL)
        {
            g_vclndr_cntx.FilePathPtr = OslMalloc(VOBJ_MAX_PATH_LENGTH);
        }

        if (g_vclndr_cntx.FileNamePtr == NULL)
        {
            g_vclndr_cntx.FileNamePtr = OslMalloc(MAX_TODO_LIST_NOTE);
        }

        mmi_ucs2cpy(g_vclndr_cntx.FilePathPtr, (S8*) path);

        if (g_vclndr_cntx.SrcType == VCLNDR_SAVE_FROM_TDL)
        {
            mmi_ucs2cpy(g_vclndr_cntx.FileNamePtr, (S8*) g_tdl_cntx.TaskList[i].Note);
        }
        else
        {
            memset(g_vclndr_cntx.FileNamePtr, 0, ENCODING_LENGTH);
        }

        mmi_vclndr_entry_filename();

        /* to delete all screens for selecting path */
        if (g_vclndr_cntx.SrcType == VCLNDR_SAVE_FROM_TDL)
        {
            DeleteUptoScrID(SCR_ID_VCLNDR_FORWARD);
        }
        else
        {
            DeleteUptoScrID(SCR_ID_VCLNDR_RECV_OPT);
        }
    }
    else
    {
        if (g_vclndr_cntx.SrcType == VCLNDR_SAVE_FROM_TDL)
        {
            GoBackToHistory(SCR_ID_VCLNDR_FORWARD);
        }
        else
        {
            GoBackToHistory(SCR_ID_VCLNDR_RECV_OPT);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_save_tdl_to_file
 * DESCRIPTION
 *  Save to do list to file
 * PARAMETERS
 *  void
 * RETURNS
 *  Error cause
 *****************************************************************************/
S32 mmi_vclndr_save_tdl_to_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = VOBJ_ERR_UNKNOWN;
    S8 *file_path_name;
    S8 file_ext[VOBJ_MAX_FILENAME_LENGTH];
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = g_tdl_cntx.CurrTaskIndex;

    file_path_name = OslMalloc(VOBJ_MAX_PATH_LENGTH + MAX_TODO_LIST_NOTE);

    mmi_ucs2cpy(file_path_name, (S8*) g_vclndr_cntx.FilePathPtr);
    mmi_ucs2cat(file_path_name, (S8*) g_vclndr_cntx.FileNamePtr);
    mmi_asc_to_ucs2(file_ext, (S8*) VOBJ_VCLNDR_FILE_EXT);
    mmi_ucs2cat(file_path_name, file_ext);

    if (mmi_vclndr_uti_is_file_exist(file_path_name))
    {
        result = VOBJ_ERR_DUPLICATE_NAME;
    }
    else
    {
        result = mmi_vclndr_writer(&g_tdl_cntx.TaskList[i], file_path_name);
    }

    OslMfree(file_path_name);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_save_obj_to_file
 * DESCRIPTION
 *  Save receiving vCalendar object to file.
 * PARAMETERS
 *  void
 * RETURNS
 *  Error codes
 *****************************************************************************/
S32 mmi_vclndr_save_obj_to_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = VOBJ_ERR_UNKNOWN;
    S8 *src_path_name;
    S8 *dest_path_name;
    S8 file_ext[VOBJ_MAX_FILENAME_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_vobj_get_file_buffer_size() > 0)
    {
        src_path_name = OslMalloc(VOBJ_MAX_PATH_LENGTH + MAX_TODO_LIST_NOTE);
        mmi_vobj_get_full_path_name(g_vobj_cntx.buffer_begin, src_path_name, MMI_VOBJ_VCLNDR);

        dest_path_name = OslMalloc(VOBJ_MAX_PATH_LENGTH + MAX_TODO_LIST_NOTE);
        mmi_ucs2cpy(dest_path_name, (S8*) g_vclndr_cntx.FilePathPtr);
        mmi_ucs2cat(dest_path_name, (S8*) g_vclndr_cntx.FileNamePtr);
        mmi_asc_to_ucs2(file_ext, (S8*) VOBJ_VCLNDR_FILE_EXT);
        mmi_ucs2cat(dest_path_name, file_ext);

        /* Use move instead of rename because user may save to card. */
        /* result = pfrename(src_path_name,dest_path_name); */
    #if defined(__FS_MOVE_SUPPORT__)
        mmi_fmgr_send_copy_req(
            FMGR_ACTION_MOVE,
            (U8*) src_path_name,
            (U8*) dest_path_name,
            mmi_vclndr_save_obj_to_file_callback);
        result = VOBJ_ERR_NO_ERROR;
    #else /* defined(__FS_MOVE_SUPPORT__) */ 
        result = VOBJ_ERR_UNKNOWN;  /* Should hine menu when MOVE not support. */
    #endif /* defined(__FS_MOVE_SUPPORT__) */ 

        OslMfree(src_path_name);
        OslMfree(dest_path_name);
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_save_obj_to_file_callback
 * DESCRIPTION
 *  Save receiving vCalendar object to file.
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  Error codes(?)
 *****************************************************************************/
void mmi_vclndr_save_obj_to_file_callback(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fmt_copy_rsp_strcut *msgPtr;
    S8 *dest_path_name;
    S8 file_ext[VOBJ_MAX_FILENAME_LENGTH];   
    U8 attr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgPtr = (mmi_fmt_copy_rsp_strcut*) info;

    if (msgPtr->result >= 0)
    {
        /* Unhide vCalendar file */
        dest_path_name = OslMalloc(VOBJ_MAX_PATH_LENGTH);
        mmi_ucs2cpy(dest_path_name, (S8*) g_vclndr_cntx.FilePathPtr);
        mmi_ucs2cat(dest_path_name, (S8*) g_vclndr_cntx.FileNamePtr);
        mmi_asc_to_ucs2(file_ext, (S8*) VOBJ_VCLNDR_FILE_EXT);
        mmi_ucs2cat(dest_path_name, file_ext);
        attr = (U8)FS_GetAttributes((const WCHAR *)dest_path_name);     
        attr &= (~FS_ATTR_HIDDEN);
        FS_SetAttributes((const WCHAR *)dest_path_name, (U8)attr);
        OslMfree(dest_path_name);    

        mmi_vclndr_save_file_done(VOBJ_ERR_NO_ERROR);
    }
    else
    {
        mmi_vclndr_save_file_done(msgPtr->result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_fmgr_recv
 * DESCRIPTION
 *  Receive vCalendar object from file manager.
 * PARAMETERS
 *  file_path_name      [IN]        Filename and path of selected file.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vclndr_fmgr_recv(S8 *file_path_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ToDoListNode task;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (file_path_name == NULL)
    {
        return;
    }

    g_vclndr_cntx.vcalendar_encoding = (mmi_chset_enum)PhnsetGetDefEncodingType();
    if (mmi_vclndr_reader(file_path_name, &task) == VOBJ_ERR_NO_ERROR)
    {
        if (TdlInsertTask(&task, TODO_FROM_FMGR))
        {
            return;
        }
        else
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_VCLNDR_TASK_FULL),
                IMG_GLOBAL_ERROR,
                TRUE,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
        }
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_VOBJ_FORMAT_NOT_SUPPORT),
            IMG_GLOBAL_ERROR,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_fmgr_sms_forward
 * DESCRIPTION
 *  Forward a vCalendar object from file manager via SMS
 * PARAMETERS
 *  path        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vclndr_fmgr_sms_forward(S8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
    mmi_ems_vobject_send_by_ems(0x0000, VOBJ_VCLNDR_PORT, path, NULL);
#endif 
}

 


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_highlight_opt_done
 * DESCRIPTION
 *  Highlight handler for "Done" option when editing filename.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vclndr_highlight_opt_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_vclndr_save_file, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_save_file
 * DESCRIPTION
 *  Save vCalendar object to file.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vclndr_save_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    S8 file_path_name[MAX_TODO_LIST_NOTE];
    S8 *new_path;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
	result = mmi_fmgr_is_filename_valid((S8*)g_vclndr_cntx.FileNamePtr);
    
	if (result == MMI_TRUE)    
    {			
        /* Skip white space in front of the file name */
        mmi_ucs2cpy((S8*)file_path_name, (S8*)g_vclndr_cntx.FileNamePtr);
        new_path = mmi_fmgr_skip_space((S8*)file_path_name);
        mmi_ucs2cpy((S8*)g_vclndr_cntx.FileNamePtr, (S8*)new_path);
        
        if (g_vclndr_cntx.SrcType == VCLNDR_SAVE_FROM_TDL)
        {
            result = mmi_vclndr_save_tdl_to_file();
        }
        else    /* if(g_vclndr_cntx.SrcType == VCLNDR_SAVE_FROM_RECV) */
        {
            result = mmi_vclndr_save_obj_to_file();
            if (result == VOBJ_ERR_NO_ERROR)
            {
                return; /* Handle copy result in callback */
            }
        }
    }
    else
    {
        new_path = mmi_fmgr_skip_space(g_vclndr_cntx.FileNamePtr);
        if (mmi_ucs2strlen((S8*)new_path) == 0)
        {
            result = VOBJ_ERR_EMPTY_NAME;
        }        
        else
        {
            result = VOBJ_ERR_INVALID_FILENAME;
        }
    }

    mmi_vclndr_save_file_done(result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_save_file_done
 * DESCRIPTION
 *  Save vCalendar object to file.
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vclndr_save_file_done(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (result)
    {
        case VOBJ_ERR_NO_ERROR:
        {
            mmi_vclndr_free_buffer();
            DisplayPopup(
                (PU8) GetString(STR_GLOBAL_SAVED),
                IMG_GLOBAL_ACTIVATED,
                TRUE,
                UI_POPUP_NOTIFYDURATION_TIME,
                SUCCESS_TONE);
            if (g_vclndr_cntx.SrcType == VCLNDR_SAVE_FROM_TDL)
            {
                DeleteUptoScrID(SCR_TDL_TASK_LIST);
            }
            else
            {
                mmi_vobj_clear_one_file_buffer();
                DeleteNScrId(SCR_ID_VCLNDR_RECV_OPT);
                DeleteScreenIfPresent(SCR_ID_VOBJ_RECV_OBJECT);            
            }

            break;
        }
		case VOBJ_ERR_INVALID_FILENAME:
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_VOBJ_INVALID_FILENAME),
                IMG_GLOBAL_ERROR,
                TRUE,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
            DeleteUptoScrID(SCR_ID_VCLNDR_FILENAME);

            break;
        }
        case VOBJ_ERR_SELECT_PATH_TOO_LONG:
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_VOBJ_FILE_PATH_TOO_LONG),
                IMG_GLOBAL_ERROR,
                TRUE,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
            DeleteUptoScrID(SCR_ID_VCLNDR_FILENAME);

            break;
        }
        case VOBJ_ERR_DUPLICATE_NAME:
        case FS_FILE_EXISTS:
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_VOBJ_DUPLICATE_FILENAME),
                IMG_GLOBAL_ERROR,
                TRUE,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
            DeleteUptoScrID(SCR_ID_VCLNDR_FILENAME);

            break;
        }
        case VOBJ_ERR_EMPTY_NAME:
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_VOBJ_EMPTY_FILENAME),
                IMG_GLOBAL_ERROR,
                TRUE,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
            DeleteUptoScrID(SCR_ID_VCLNDR_FILENAME);

            break;
        }
        case VOBJ_ERR_UNKNOWN:
        {
            DisplayPopup(
                (PU8) GetString(STR_GLOBAL_UNFINISHED),
                IMG_GLOBAL_ERROR,
                TRUE,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
            if (g_vclndr_cntx.SrcType == VCLNDR_SAVE_FROM_TDL)
            {
                DeleteUptoScrID(SCR_ID_VCLNDR_FORWARD);
            }
            else
            {
                DeleteUptoScrID(SCR_ID_VCLNDR_RECV_OPT);
            }

            break;
        }
        default:
        {
            DisplayPopup(
                (PU8) GetString(GetFileSystemErrorString(result)),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            if (g_vclndr_cntx.SrcType == VCLNDR_SAVE_FROM_TDL)
            {
                DeleteUptoScrID(SCR_ID_VCLNDR_FORWARD);
            }
            else
            {
                DeleteUptoScrID(SCR_ID_VCLNDR_RECV_OPT);
            }

            break;
        }

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_highlight_opt_input_method
 * DESCRIPTION
 *  Highlight handler for "Input Method" option when editing filename.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vclndr_highlight_opt_input_method(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryInputMethodScreen, KEY_EVENT_UP);
    SetKeyHandler(EntryInputMethodScreen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    RegisterInputMethodScreenCloseFunction(mmi_vclndr_goback_1_history);
}

#endif /* defined(__MMI_FILE_MANAGER__) */ /* #if defined(__MMI_FILE_MANAGER__) */

#define VCLNDR_UTILITY

/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_uti_convert_to_upper
 * DESCRIPTION
 *  CCase Conversion
 * PARAMETERS
 *  decoded_buffer      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vclndr_uti_convert_para_to_upper(S8 *decoded_buffer, U16 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  
    for (i = 0; i < length; i++)
    {
        if ((decoded_buffer[i] >= 97) && (decoded_buffer[i] <= 122))
        {
            decoded_buffer[i] = decoded_buffer[i] - 32;
        }        
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_uti_get_line
 * DESCRIPTION
 *  Get a line from file system, excluding the escape characters.
 *  Handle SUMMARY & DESCRIPTION fileds specially.
 * PARAMETERS
 *  strOutput       [IN/OUT]        Storage location for data
 *  fh              [IN]            File handle
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_vclndr_uti_get_line(S8 *strOutput, FS_HANDLE fh)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nBytes = 0;
    S8 *buffer = OslMalloc(VOBJ_READ_BUFF_LEN);
    S32 i;
    S32 strLen;
    S8 *curr_cursor;
    S8 *cursor = NULL;
    BOOL removeCRLF = MMI_FALSE;
    U8 fieldType = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FS_Read(fh, buffer, VOBJ_READ_BUFF_LEN - 1, (UINT *)&nBytes);
    strncpy(strOutput, buffer, nBytes);
    buffer[nBytes] = '\0';

    if (!nBytes)
    {
        OslMfree(buffer);
        return 0;
    }

    mmi_vclndr_uti_convert_para_to_upper(buffer, VOBJ_READ_BUFF_LEN);

    for (i = VCLNDR_BEGIN; i<VCLNDR_TOTAL_FILEDS; i++)
    {
        if (strncmp(g_vclndr_fileds[i], buffer, strlen(g_vclndr_fileds[i])) == 0)
        {
            fieldType = i;
        }
    }

    for (i = VCLNDR_BEGIN; i < VCLNDR_TOTAL_FILEDS; i++)
    {
        if (fieldType == i)
        {
            continue;
        }

        curr_cursor = strstr(buffer, g_vclndr_fileds[i]);

        if (curr_cursor == (S8*) NULL)
        {
            continue;
        }
        /* Fix the issue AALARM;X-.....*/
        else if (*(curr_cursor-2) != 0x0D && *(curr_cursor-1) != 0x0A)
        {
            curr_cursor = cursor;
        }
        else if (cursor == (S8*) NULL)
        {
            cursor = curr_cursor;
        }
        else
        {
            if ((S32) cursor > (S32) curr_cursor)
            {
                cursor = curr_cursor;
            }
        }
    }
    if (cursor == NULL)
    {
        OslMfree(buffer);
        return 0;
    }

    /* Remove end of line "\r\n" */
    if (strncmp((S8*) (cursor - strlen(VOBJ_CRLF_STR)), (S8*) VOBJ_CRLF_STR, strlen(VOBJ_CRLF_STR)) == 0)
    {
        cursor -= strlen(VOBJ_CRLF_STR);
        removeCRLF = MMI_TRUE;
    }

    strLen = (S32) cursor - (S32) buffer;
    strOutput[strLen] = VOBJ_NULL;

    if (removeCRLF)
    {
        FS_Seek(fh, (S32) (strLen + strlen(VOBJ_CRLF_STR) - nBytes), SEEK_CUR);
    }
    else
    {
        FS_Seek(fh, (S32) (strLen - nBytes), SEEK_CUR);
    }

    OslMfree(buffer);
    return strLen;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_uti_get_clndr_type
 * DESCRIPTION
 *  Determine the type of a To Do List task.
 * PARAMETERS
 *  TDLNode     [?]     
 * RETURNS
 *  type of the task.
 *****************************************************************************/
U8 mmi_vclndr_uti_get_clndr_type(ToDoListNode *TDLNode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_ADVANCED_TODO__
    switch (TDLNode->Type)
    {
        case TDL_TASK_MEETING:
        case TDL_TASK_COURSE:
        case TDL_TASK_REMINDER:
            return VCLNDR_TYPE_EVENT;

        case TDL_TASK_DATE:
        case TDL_TASK_CALL:
        case TDL_TASK_ANNIVERSARY:
            return VCLNDR_TYPE_TODO;

        default:
            ASSERT(0);
            return 0;
    }
#else /* __MMI_ADVANCED_TODO__ */ 
    if ((TDLNode->EndHour < TDLNode->StartTime.nHour)
        || (TDLNode->EndHour == TDLNode->StartTime.nHour && TDLNode->EndMin == TDLNode->StartTime.nMin))
    {
        return VCLNDR_TYPE_TODO;
    }
    else
    {
        return VCLNDR_TYPE_EVENT;
    }
#endif /* __MMI_ADVANCED_TODO__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_writer
 * DESCRIPTION
 *  Generate a task to a vCalendar object.
 * PARAMETERS
 *  TDLNode             [IN]        Task to be convert
 *  file_path_name      [IN]        File path to store the vCalendar object.
 * RETURNS
 *  Error codes.
 *****************************************************************************/
S32 mmi_vclndr_writer(ToDoListNode *TDLNode, S8 *file_path_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 wByte;
    S32 result;
    FS_HANDLE fh;
    S8 strDateTime[VCLNDR_MAX_DT_LEN];
    S8 strBuff[MAX_TODO_LIST_NOTE * 2];
    S8 *qpBuff;
    U8 vType;
    S8 *vClndrBuff;
    S32 len;
    MYTIME utcTime;
    FLOAT home_tz = GetTimeZone(PhnsetGetHomeCity());

#ifdef __MMI_ADVANCED_TODO__
    MYTIME incTime, preReminder;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fh = FS_Open((U16*) file_path_name, FS_READ_WRITE | FS_CREATE_ALWAYS);

    if (fh <= 0)
#ifdef MMI_ON_HARDWARE_P
        return fh;
#else 
        return VOBJ_ERR_UNKNOWN;
#endif 

    vClndrBuff = OslMalloc(VOBJ_WRITE_BUFF_LEN);

    /* BEGIN:VCALENDAR */
    strcpy(vClndrBuff, (S8*) g_vclndr_fileds[VCLNDR_BEGIN]);
    strcat(vClndrBuff, (S8*) VOBJ_CRLF_STR);

    /* VERSION */
    strcat(vClndrBuff, (S8*) g_vclndr_fileds[VCLNDR_VERSION]);
    strcat(vClndrBuff, (S8*) VOBJ_CRLF_STR);

    /* BEGIN:VEVENT/VTODO */
    vType = mmi_vclndr_uti_get_clndr_type(TDLNode);

    if (vType == VCLNDR_TYPE_EVENT)
    {
        strcat(vClndrBuff, (S8*) g_vclndr_fileds[VCLNDR_VEVENT_BEGIN]);
    }
    else
    {
        strcat(vClndrBuff, (S8*) g_vclndr_fileds[VCLNDR_VTODO_BEGIN]);
    }

    strcat(vClndrBuff, (S8*) VOBJ_CRLF_STR);

    /* DTSTART: */
    /* Make start time to utc time */
    home_tz = 0 -(home_tz);
    mmi_dt_utc_to_rtc(home_tz,TDLNode->StartTime, utcTime);

    strcat(vClndrBuff, (S8*) g_vclndr_fileds[VCLNDR_DTSTART]);
    strcat(vClndrBuff, (S8*) VOBJ_VALUE_SEP_STR);
    sprintf(
        strDateTime,
        "%d%02d%02d%c%02d%02d%02dZ",
        utcTime.nYear,
        utcTime.nMonth,
        utcTime.nDay,
        VCLNDR_DT_SEP_CHAR,
        utcTime.nHour,
        utcTime.nMin,
        utcTime.nSec);
    strcat(vClndrBuff, (S8*) strDateTime);
    strcat(vClndrBuff, (S8*) VOBJ_CRLF_STR);

    /* DTEND */
    if (vType == VCLNDR_TYPE_TODO)
    {
    #ifdef __MMI_ADVANCED_TODO__
        strcat(vClndrBuff, (S8*) g_vclndr_fileds[VCLNDR_DUE]);
    #else 
        strcat(vClndrBuff, (S8*) g_vclndr_fileds[VCLNDR_DTEND]);
    #endif 
        strcat(vClndrBuff, (S8*) VOBJ_VALUE_SEP_STR);
        strcat(vClndrBuff, (S8*) strDateTime);
        strcat(vClndrBuff, (S8*) VOBJ_CRLF_STR);
    }
    else
    {
        strcat(vClndrBuff, (S8*) g_vclndr_fileds[VCLNDR_DTEND]);
        strcat(vClndrBuff, (S8*) VOBJ_VALUE_SEP_STR);
    #ifdef __MMI_ADVANCED_TODO__        
        memcpy(&utcTime, &(TDLNode->EndTime), sizeof(MYTIME));
    #else /* __MMI_ADVANCED_TODO__ */
        memcpy(&utcTime, &(TDLNode->StartTime), sizeof(MYTIME));
        utcTime.nHour = TDLNode->EndHour;
        utcTime.nMin= TDLNode->EndMin;
    #endif /* __MMI_ADVANCED_TODO__ */ 
        mmi_dt_utc_to_rtc(home_tz,  utcTime, utcTime);
        sprintf(
            strDateTime,
            "%d%02d%02d%c%02d%02d%02dZ",
            utcTime.nYear,
            utcTime.nMonth,
            utcTime.nDay,
            VCLNDR_DT_SEP_CHAR,
            utcTime.nHour,
            utcTime.nMin,
            utcTime.nSec); 

        strcat(vClndrBuff, (S8*) strDateTime);
        strcat(vClndrBuff, (S8*) VOBJ_CRLF_STR);
    }

    /* Alarm */
    if (TDLNode->Alarm >= TODO_LIST_ALARM_ON)
    {
    #ifdef __MMI_ADVANCED_TODO__
        if (TDLNode->Alarm > TODO_LIST_ALARM_ON)
        {
            memset(&incTime, 0, sizeof(MYTIME));
            mmi_tdl_compute_reminder_time(TDLNode, &incTime);
            DecrementTime(TDLNode->StartTime, incTime, &preReminder);

            memcpy(&utcTime, &preReminder, sizeof(MYTIME));            
        }
        else
    #endif /* __MMI_ADVANCED_TODO__ */ 
        {
            memcpy(&utcTime, &(TDLNode->StartTime), sizeof(MYTIME));            
        }
        mmi_dt_utc_to_rtc(home_tz,  utcTime, utcTime);
        sprintf(
            strDateTime,
            "%d%02d%02d%c%02d%02d%02dZ",
            utcTime.nYear,
            utcTime.nMonth,
            utcTime.nDay,
            VCLNDR_DT_SEP_CHAR,
            utcTime.nHour,
            utcTime.nMin,
            utcTime.nSec);             
        
        /* DALARM */
        strcat(vClndrBuff, (S8*) g_vclndr_fileds[VCLNDR_DALARM]);
        strcat(vClndrBuff, (S8*) VOBJ_VALUE_SEP_STR);
        strcat(vClndrBuff, (S8*) strDateTime);
        strcat(vClndrBuff, (S8*) VOBJ_CRLF_STR);

        /* AALARM */
        strcat(vClndrBuff, (S8*) g_vclndr_fileds[VCLNDR_AALARM]);
        strcat(vClndrBuff, (S8*) VOBJ_VALUE_SEP_STR);
        strcat(vClndrBuff, (S8*) strDateTime);
        strcat(vClndrBuff, (S8*) VOBJ_CRLF_STR);
    }

    /* SUMMARY: */
    strcat(vClndrBuff, (S8*) g_vclndr_fileds[VCLNDR_SUMMARY]);
    qpBuff = OslMalloc(VOBJ_WRITE_BUFF_LEN);
    mmi_chset_convert(MMI_CHSET_UCS2, MMI_CHSET_UTF8, (S8*) TDLNode->Note, strBuff, sizeof(strBuff));
    applib_qprint_encode_ext(strBuff, strlen(strBuff), qpBuff, VOBJ_WRITE_BUFF_LEN, KAL_TRUE);
    strcat(vClndrBuff, (S8*) VCLNDR_PARA_SEP_STR);  /* ";" */
    strcat(vClndrBuff, (S8*) g_vobj_paras[VOBJ_PARA_ENCODING]);        /* ENCODING */
    strcat(vClndrBuff, (S8*) VCLNDR_EQUAL_STR);     /* "=" */
    strcat(vClndrBuff, (S8*) g_vobj_encoding[2]);   /* "QP" */
    strcat(vClndrBuff, (S8*) VCLNDR_PARA_SEP_STR);  /* ";" */
    strcat(vClndrBuff, (S8*) g_vobj_paras[VOBJ_PARA_CHARSET]); /* CHARSET */
    strcat(vClndrBuff, (S8*) VCLNDR_EQUAL_STR);     /* "=" */
    strcat(vClndrBuff, (S8*) VCLNDR_CHARSET_UTF8);  /* "UTF-8" */

    strcat(vClndrBuff, (S8*) VOBJ_VALUE_SEP_STR);
    strcat(vClndrBuff, (S8*) qpBuff);
    strcat(vClndrBuff, (S8*) VOBJ_CRLF_STR);
    OslMfree(qpBuff);

    /* RRULE: */
    if (g_tdl_freq_set[TDLNode->Repeat] != ALM_FREQ_ONCE)
    {
        strcat(vClndrBuff, (S8*) g_vclndr_fileds[VCLNDR_RRULE]);
        strcat(vClndrBuff, (S8*) VOBJ_VALUE_SEP_STR);

        switch (g_tdl_freq_set[TDLNode->Repeat])
        {
            case ALM_FREQ_EVERYDAY:
            {
                strcat(vClndrBuff, (S8*) g_vclndr_recurr[VCLNDR_DAILY]);
                break;
            }
            case ALM_FREQ_DAYS:
            {
                S32 i;

                strcat(vClndrBuff, (S8*) g_vclndr_recurr[VCLNDR_WEEKLY]);
                memset(strBuff, 0, sizeof(strBuff));
                for (i = 0; i < VCLNDR_NUM_OF_DAYS; i++)
                {
                    if (TDLNode->Days & (0x1 << i))
                    {
                        sprintf(strDateTime, " %s", g_vclndr_days[i]);
                        strcat(strBuff, strDateTime);
                    }
                }
                strcat(vClndrBuff, (S8*) strBuff);
                break;
            }
            case ALM_FREQ_WEEKLY:
            {
                strcat(vClndrBuff, (S8*) g_vclndr_recurr[VCLNDR_WEEKLY]);
                break;
            }
            case ALM_FREQ_MONTHLY:
            {
                strcat(vClndrBuff, (S8*) g_vclndr_recurr[VCLNDR_MONTHLY]);
            #ifdef __MMI_ADVANCED_TODO__
                sprintf(strBuff, " %d", TDLNode->StartTime.nDay);
            #else 
                sprintf(strBuff, " %d", TDLNode->StartTime.nDay);
            #endif 
                strcat(vClndrBuff, (S8*) strBuff);
                break;
            }
        #ifdef __MMI_ADVANCED_TODO__
            case ALM_FREQ_YEARLY:
            {
                strcat(vClndrBuff, (S8*) g_vclndr_recurr[VCLNDR_YEARLY]);
                break;
            }
        #endif
        }
        /* #0 and CRLF */
        strcat(vClndrBuff, (S8*) VCLNDR_R_FOREVER_STR);
        strcat(vClndrBuff, (S8*) VOBJ_CRLF_STR);
    }

#ifdef __MMI_ADVANCED_TODO__
    /* Category */
    strcat(vClndrBuff, (S8*) g_vclndr_fileds[VCLNDR_CATEGORY]);
    strcat(vClndrBuff, (S8*) VOBJ_VALUE_SEP_STR);

    memset(strBuff, 0, MAX_TODO_LIST_NOTE * 2);
    switch (TDLNode->Type)
    {
        case TDL_TASK_REMINDER:
            strcat(vClndrBuff, (S8*) VCLNDR_CATEGORY_REMINDER);
            break;
        case TDL_TASK_MEETING:
            strcat(vClndrBuff, (S8*) VCLNDR_CATEGORY_MEETING);
            break;
        case TDL_TASK_COURSE:
            strcat(vClndrBuff, (S8*) VCLNDR_CATEGORY_COURSE);
            break;
        case TDL_TASK_DATE:
            strcat(vClndrBuff, (S8*) VCLNDR_CATEGORY_DATE);
            break;
        case TDL_TASK_CALL:
            strcat(vClndrBuff, (S8*) VCLNDR_CATEGORY_CALL);
            break;
        case TDL_TASK_ANNIVERSARY:
            strcat(vClndrBuff, (S8*) VCLNDR_CATEGORY_ANNIVERSARY);
            break;
    }
    strcat(vClndrBuff, (S8*) VOBJ_CRLF_STR);

    /* Priority */
    strcat(vClndrBuff, (S8*) g_vclndr_fileds[VCLNDR_PRIORITY]);
    strcat(vClndrBuff, (S8*) VOBJ_VALUE_SEP_STR);
    sprintf(strBuff, "%d\0", TDLNode->Priority + 1);
    strcat(vClndrBuff, (S8*) strBuff);  /* priority 0 present an undefined priority */
    strcat(vClndrBuff, (S8*) VOBJ_CRLF_STR);

    /* Location */
    if (mmi_ucs2strlen((S8*) TDLNode->Location) != 0)
    {
        strcat(vClndrBuff, (S8*) g_vclndr_fileds[VCLNDR_LOCATION]);
        qpBuff = OslMalloc(VOBJ_WRITE_BUFF_LEN);
        mmi_chset_convert(MMI_CHSET_UCS2, MMI_CHSET_UTF8, (S8*) TDLNode->Location, strBuff, sizeof(strBuff));
        applib_qprint_encode_ext(strBuff, strlen(strBuff), qpBuff, VOBJ_WRITE_BUFF_LEN, KAL_TRUE);
        strcat(vClndrBuff, (S8*) VCLNDR_PARA_SEP_STR);  /* ";" */
        strcat(vClndrBuff, (S8*) g_vobj_paras[VOBJ_PARA_ENCODING]);    /* ENCODING */
        strcat(vClndrBuff, (S8*) VCLNDR_EQUAL_STR);     /* "=" */
        strcat(vClndrBuff, (S8*) g_vobj_encoding[2]);   /* "QP" */
        strcat(vClndrBuff, (S8*) VCLNDR_PARA_SEP_STR);  /* ";" */
        strcat(vClndrBuff, (S8*) g_vobj_paras[VOBJ_PARA_CHARSET]);     /* CHARSET */
        strcat(vClndrBuff, (S8*) VCLNDR_EQUAL_STR);     /* "=" */
        strcat(vClndrBuff, (S8*) VCLNDR_CHARSET_UTF8);  /* "UTF-8" */

        strcat(vClndrBuff, (S8*) VOBJ_VALUE_SEP_STR);
        strcat(vClndrBuff, (S8*) qpBuff);
        strcat(vClndrBuff, (S8*) VOBJ_CRLF_STR);
        OslMfree(qpBuff);
    }
#endif /* __MMI_ADVANCED_TODO__ */ 

    /* END:VEVENT/VTODO */
    if (vType == VCLNDR_TYPE_EVENT)
    {
        strcat(vClndrBuff, (S8*) g_vclndr_fileds[VCLNDR_VEVENT_END]);
    }
    else
    {
        strcat(vClndrBuff, (S8*) g_vclndr_fileds[VCLNDR_VTODO_END]);
    }

    strcat(vClndrBuff, (S8*) VOBJ_CRLF_STR);

    /* END:VCALENDAR */
    strcat(vClndrBuff, (S8*) g_vclndr_fileds[VCLNDR_END]);
    strcat(vClndrBuff, (S8*) VOBJ_CRLF_STR);

    len = strlen(vClndrBuff);
    MMI_ASSERT(len <= VOBJ_WRITE_BUFF_LEN);

    result = FS_Write(fh, vClndrBuff, len, (UINT *)&wByte);
    FS_Close(fh);

    if (result < 0)
    {
        FS_Delete((U16*) file_path_name);
    }

    OslMfree(vClndrBuff);

    return result;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_dt_is_valid
 * DESCRIPTION
 *  To compute is the date/time is within reasonable range (1970 ~ 2030)
 * PARAMETERS
 *  t       [?]     Time to be computed
 * RETURNS
 *  TURE if date/time valid; otherwise, FALSE
 *****************************************************************************/
U8 mmi_vclndr_dt_is_valid(MYTIME *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* error handling */
    if (t->nYear > 2030 || t->nYear < 1970)
    {
        return FALSE;
    }

    if (t->nMonth > 12)
    {
        return FALSE;
    }

    if (t->nDay > LastDayOfMonth(t->nMonth, t->nYear))
    {
        return FALSE;
    }

    if (t->nHour > 23)
    {
        return FALSE;
    }

    if (t->nMin > 59)
    {
        return FALSE;
    }

    if (t->nSec > 59)
    {
        return FALSE;
    }

    return TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_reader
 * DESCRIPTION
 *  Parse a vCalendar file
 * PARAMETERS
 *  file_path_name      [IN]            Filename including whole path
 *  TdlNode             [IN/OUT]        Task buffer to store the result
 * RETURNS
 *  Error cause
 *****************************************************************************/
S32 mmi_vclndr_reader(S8 *file_path_name, ToDoListNode *TdlNode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fh = 0;                     /* file handle */
    S8 inBuff[VOBJ_READ_BUFF_LEN];          /* buffer to store input */
    S8 DescritionBuff[MAX_TODO_LIST_NOTE];  /* buffer to store input */
    S8 *strValue;                           /* pointer to value of filed */

    U8 filedType;
    U8 IsDTValid = FALSE;
    U8 IsObjValid = FALSE;
    U8 vType = 0;

    MYTIME DTStart, DTEnd, DTDue;

#ifdef __MMI_ADVANCED_TODO__
    MYTIME DTAlarm, DTpreReminder;
#endif 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&DTStart, 0, sizeof(MYTIME));
    memset(&DTDue, 0, sizeof(MYTIME));
    memset(&DTEnd, 0, sizeof(MYTIME));
#ifdef __MMI_ADVANCED_TODO__
    memset(&DTAlarm, 0, sizeof(MYTIME));
    memset(&DTpreReminder, 0, sizeof(MYTIME));

#endif /* __MMI_ADVANCED_TODO__ */ 
    memset(TdlNode, 0, sizeof(ToDoListNode));
    memset(DescritionBuff, 0, sizeof(DescritionBuff));

    fh = FS_Open((U16*) file_path_name, FS_READ_ONLY);
    if (fh <= 0)
    {
        return fh;
    }

    /* BEGIN:VCALENDAR */
    if (mmi_vclndr_uti_get_line(inBuff, fh) != 0)
    {
        mmi_vclndr_uti_remove_ws(inBuff, (S8*) VOBJ_VALUE_SEP_STR, VCLNDR_REMOVE_BOTH_WS);
        if (mmi_vclndr_uti_check_field(inBuff) != VCLNDR_BEGIN)
        {
            FS_Close(fh);
            return VOBJ_ERR_UNSUPPORT_FORMAT;
        }
    }

    /* VERSION */
    while (mmi_vclndr_uti_get_line(inBuff, fh) != 0)
    {
        mmi_vclndr_uti_remove_ws(inBuff, (S8*) VOBJ_VALUE_SEP_STR, VCLNDR_REMOVE_BOTH_WS);
        if (mmi_vclndr_uti_check_field(inBuff) == VCLNDR_VERSION)
        {
            break;
        }
    }

    /* VEVENT or VTODO */
    while (mmi_vclndr_uti_get_line(inBuff, fh) != 0)
    {
        mmi_vclndr_uti_remove_ws(inBuff, (S8*) VOBJ_VALUE_SEP_STR, VCLNDR_REMOVE_BOTH_WS);
        filedType = mmi_vclndr_uti_check_field(inBuff);
        if (filedType == VCLNDR_VEVENT_BEGIN)
        {
            vType = VCLNDR_VEVENT_BEGIN;
            break;
        }
        else if (filedType == VCLNDR_VTODO_BEGIN)
        {
            vType = VCLNDR_VTODO_BEGIN;
            break;
        }
    }

    /* DTSTART, DTEND, SUMMARY, DESCRIPTION, DUE, RRULE */
    while (mmi_vclndr_uti_get_line(inBuff, fh) != 0)
    {
        mmi_vclndr_uti_remove_ws(inBuff, (S8*) VOBJ_VALUE_SEP_STR, VCLNDR_REMOVE_PRE_WS);
        filedType = mmi_vclndr_uti_check_field(inBuff);

        /* To keep the white space in the notes */
        if (filedType != VCLNDR_SUMMARY && filedType != VCLNDR_DESCRIPTION
    #ifdef __MMI_ADVANCED_TODO__
            && filedType != VCLNDR_LOCATION
    #endif 
            )
        {
            mmi_vclndr_uti_remove_ws(inBuff, (S8*) VOBJ_VALUE_SEP_STR, VCLNDR_REMOVE_POST_WS);
        }
        strValue = (S8*) mmi_vobj_uti_get_value(inBuff);

        switch (filedType)
        {
            case VCLNDR_DTSTART:
                DTStart = mmi_vclndr_uti_get_time(strValue);
                break;
            case VCLNDR_DTEND:
                DTEnd = mmi_vclndr_uti_get_time(strValue);
                break;
            case VCLNDR_DUE:
                DTDue = mmi_vclndr_uti_get_time(strValue);
                break;
            case VCLNDR_SUMMARY:
            case VCLNDR_DESCRIPTION:
        #ifdef __MMI_ADVANCED_TODO__
            case VCLNDR_LOCATION:
        #endif 
            {
                // S8   Langbuff[VCLNDR_MAX_PARAM_LEN]; /* buffer to store language */
                S8 *Encodebuff = OslMalloc(VCLNDR_MAX_PARAM_LEN);       /* buffer to store encoding type */
                S8 *Charsetebuff = OslMalloc(VCLNDR_MAX_PARAM_LEN);     /* buffer to store charset */
                S8 *ResultBuff = OslMalloc(2048);       /* for UTF-8 case */

                /* currently not supported */
            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif /* 0 */ 

                /* encoding type */
                strcpy(ResultBuff, strValue);
                if (mmi_vclndr_uti_get_param
                    (inBuff, (S8*) g_vobj_paras[VOBJ_PARA_ENCODING], Encodebuff, VCLNDR_MAX_PARAM_LEN))
                {
                    if (mmi_vclndr_uti_get_encoding_type(Encodebuff) == VOBJ_EN_QP)
                    {
                        applib_qprint_decode(strValue, strlen(strValue), ResultBuff, 2048);
                    }
                }

                /* charset */
                if (mmi_vclndr_uti_get_param
                    (inBuff, (S8*) g_vobj_paras[VOBJ_PARA_CHARSET], Charsetebuff, VCLNDR_MAX_PARAM_LEN))
                {
                    if (mmi_vclndr_uti_get_charset(Charsetebuff) == VOBJ_CH_UTF8)
                    {
                        mmi_chset_convert(
                            MMI_CHSET_UTF8,
                            MMI_CHSET_UCS2,
                            ResultBuff,
                            DescritionBuff,
                            MAX_TODO_LIST_NOTE);
                    }
                    else
                    {

                        mmi_chset_convert(
                            (mmi_chset_enum) g_vclndr_cntx.vcalendar_encoding,
                            MMI_CHSET_UCS2,
                            ResultBuff,
                            DescritionBuff,
                            MAX_TODO_LIST_NOTE);
                        /* mmi_asc_n_to_ucs2((S8*)DescritionBuff, ResultBuff, MAX_TODO_NOTE_LEN-1); */
                    }
                }
                else
                {

                    mmi_chset_convert(
                        (mmi_chset_enum) g_vclndr_cntx.vcalendar_encoding,
                        MMI_CHSET_UCS2,
                        ResultBuff,
                        DescritionBuff,
                        MAX_TODO_LIST_NOTE);
                    /* mmi_asc_n_to_ucs2((S8*)DescritionBuff, ResultBuff, MAX_TODO_NOTE_LEN-1); */
                }

                if (filedType == VCLNDR_SUMMARY || (filedType == VCLNDR_DESCRIPTION && mmi_ucs2strlen((S8*) TdlNode->Note) == 0))
                {
                    mmi_ucs2cpy((S8*) TdlNode->Note, DescritionBuff);
                }
            #ifdef __MMI_ADVANCED_TODO__
                else if (filedType == VCLNDR_LOCATION)
                {
                    mmi_ucs2cpy((S8*) TdlNode->Location, DescritionBuff);
                }
            #endif /* __MMI_ADVANCED_TODO__ */ 

                OslMfree(Encodebuff);
                OslMfree(Charsetebuff);
                OslMfree(ResultBuff);
                break;
            }
            case VCLNDR_RRULE:
            {
                /* RRULE */
                vclndr_recurr_struct recurr;
                S8 *ResultBuff = OslMalloc(2048);

                applib_qprint_decode(strValue, strlen(strValue), ResultBuff, 2048);

                if (mmi_vclndr_uti_get_recurr(ResultBuff, &recurr))
                {
                    TdlNode->Repeat = recurr.Repeat;
                    TdlNode->Days = recurr.Days;
                }
                else
                {
                    TdlNode->Repeat = mmi_alm_get_freq_order(TODO_FREQ_NUM, g_tdl_freq_set, ALM_FREQ_ONCE);
                }
                OslMfree(ResultBuff);
                break;
            }
            case VCLNDR_AALARM:
            case VCLNDR_DALARM:
        #ifdef __MMI_ADVANCED_TODO__
                DTAlarm = mmi_vclndr_uti_get_time(strValue);
                applib_get_time_difference(
                    (applib_time_struct*) & DTStart,
                    (applib_time_struct*) & DTAlarm,
                    (applib_time_struct*) & DTpreReminder);

                switch (DTpreReminder.nMin)
                {
                    case 5:
                        TdlNode->Alarm = TODO_LIST_ALARM_BEFORE_5_MINS;
                        break;
                    case 15:
                        TdlNode->Alarm = TODO_LIST_ALARM_BEFORE_15_MINS;
                        break;
                    case 30:
                        TdlNode->Alarm = TODO_LIST_ALARM_BEFORE_30_MINS;
                        break;
                    default:
                        TdlNode->Alarm = TODO_LIST_ALARM_ON;
                        break;
                }
        #else /* __MMI_ADVANCED_TODO__ */ 
                TdlNode->Alarm = TRUE;
        #endif /* __MMI_ADVANCED_TODO__ */ 
                break;
            #ifdef __MMI_ADVANCED_TODO__
            case VCLNDR_CATEGORY:
                if (!strcmp(strValue, VCLNDR_CATEGORY_MEETING))
                {
                    TdlNode->Type = TDL_TASK_MEETING;
                }
                else if (!strcmp(strValue, VCLNDR_CATEGORY_COURSE))
                {
                    TdlNode->Type = TDL_TASK_COURSE;
                }
                else if (!strcmp(strValue, VCLNDR_CATEGORY_DATE))
                {
                    TdlNode->Type = TDL_TASK_DATE;
                }
                else if (!strcmp(strValue, VCLNDR_CATEGORY_CALL))
                {
                    TdlNode->Type = TDL_TASK_CALL;
                }
                else if (!strcmp(strValue, VCLNDR_CATEGORY_ANNIVERSARY))
                {
                    TdlNode->Type = TDL_TASK_ANNIVERSARY;
                }
                else    /* if (strcmp(strValue, GetString((U16)STR_TODO_REMINDER))) */
                {
                    TdlNode->Type = TDL_TASK_REMINDER;
                }

                break;

            case VCLNDR_PRIORITY:
                TdlNode->Priority = (U8) (atof(strValue) - 1);  /* priority 0 present an undefined priority */
                break;
            #endif /* __MMI_ADVANCED_TODO__ */ 

            case VCLNDR_VEVENT_END:
            case VCLNDR_VTODO_END:
            case VCLNDR_END:
                break;
            default:
                break;
        }
    }

    FS_Close(fh);

#ifdef __MMI_ADVANCED_TODO__

    if (vType == VCLNDR_VEVENT_BEGIN)
    {
        if (mmi_vclndr_dt_is_valid(&DTStart) && mmi_vclndr_dt_is_valid(&DTEnd))
        {
            TdlNode->StartTime = DTStart;
            TdlNode->EndTime = DTEnd;
            IsDTValid = TRUE;
        }
    }
    else if (vType == VCLNDR_VTODO_BEGIN)
    {
        if (mmi_vclndr_dt_is_valid(&DTDue))
        {
            TdlNode->StartTime = DTDue;
			TdlNode->EndTime = DTDue;
            IsDTValid = TRUE;
        }
    }
#else /* __MMI_ADVANCED_TODO__ */ 
    /* store date and time */
    if (mmi_vclndr_dt_is_valid(&DTStart))
    {
        TdlNode->StartTime = DTStart;

        /* if end date is the same date */
        if (DTStart.nYear == DTEnd.nYear && DTStart.nMonth == DTEnd.nMonth && DTStart.nDay == DTEnd.nDay)
        {
            TdlNode->EndHour = DTEnd.nHour;
            TdlNode->EndMin = DTEnd.nMin;
        }
        IsDTValid = TRUE;
    }
    else if (mmi_vclndr_dt_is_valid(&DTDue))
    {
        TdlNode->StartTime = DTDue;
        IsDTValid = TRUE;
    }
#endif /* __MMI_ADVANCED_TODO__ */ 

    if (mmi_ucs2strlen((S8*) TdlNode->Note))
    {
        IsObjValid = TRUE;
    }
    else if (mmi_ucs2strlen((S8*) DescritionBuff))
    {
        mmi_ucs2ncpy((S8*) TdlNode->Note, (S8*) DescritionBuff, MAX_TODO_NOTE_LEN - 1);
        IsObjValid = TRUE;
    }

    if (IsDTValid && IsObjValid)
    {
        return VOBJ_ERR_NO_ERROR;
    }
    else
    {
        return VOBJ_ERR_UNSUPPORT_FORMAT;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_uti_check_field
 * DESCRIPTION
 *  Compute the filed name of a given string.s
 * PARAMETERS
 *  String      [IN]        String to be checked
 * RETURNS
 *  Type of the filed
 *****************************************************************************/
U8 mmi_vclndr_uti_check_field(S8 *String)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strlen(String) == 0)
    {
        return VCLNDR_TOTAL_FILEDS;
    }

    for (i = 0; i < VCLNDR_TOTAL_FILEDS; i++)
        if (mmi_vobj_uti_cmp_filed(String, g_vclndr_fileds[i]))
        {
            break;
        }

    return i;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_uti_remove_ws
 * DESCRIPTION
 *  Remove white sapce of a string.
 * PARAMETERS
 *  String          [IN/OUT]        String to be converted
 *  Seperator       [IN]            WS before and next to this Seperator will be removed.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vclndr_uti_remove_ws(S8 *String, S8 *Seperator, U8 Position)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *sCursor;    /* position of start seperator */
    S8 *eCursor;    /* position of end of seperator */
    S8 *currCursor;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* locate to Seperator */
    if ((sCursor = strstr(String, Seperator)) != NULL)
    {
        if (sCursor == String)  /* to prevent abnormal case */
        {
            return;
        }

        /* remove ws after seperator */
        if (Position != VCLNDR_REMOVE_PRE_WS)
        {
            currCursor = eCursor = sCursor + strlen(Seperator);
            while ((currCursor[0] == VCLNDR_LWSP_CHAR || currCursor[0] == VCLNDR_TAB_CHAR) && (currCursor[0] != '\0'))
            {
                currCursor++;
            }

            if (currCursor != eCursor)
            {
                strcpy(eCursor, currCursor);
            }
        }

        /* remove ws before seperator */
        if (Position != VCLNDR_REMOVE_POST_WS)
        {
            currCursor = sCursor - 1;
            while ((currCursor[0] == VCLNDR_LWSP_CHAR || currCursor[0] == VCLNDR_TAB_CHAR) && (currCursor != String))
            {
                currCursor--;
            }

            currCursor++;
            if (currCursor != sCursor)
            {
                strcpy(currCursor, sCursor);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_uti_get_time
 * DESCRIPTION
 *  Get time value from a date/time string
 * PARAMETERS
 *  strTime     [IN]        Date/time string in yyyymmddThhmmssZ format.
 * RETURNS
 *  void
 *****************************************************************************/
MYTIME mmi_vclndr_uti_get_time(S8 *strTime)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME result;
    S8 *strCursor = strTime;
    S8 strBuff[VCLNDR_MAX_DT_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&result, 0, sizeof(MYTIME));

    /* year */
    memset(strBuff, 0, VCLNDR_MAX_DT_LEN);
    mmi_asc_n_to_ucs2(strBuff, strCursor, 4);
    result.nYear = (U16) gui_atoi((U16*) strBuff);
    strCursor += 4;

    /* month */
    memset(strBuff, 0, VCLNDR_MAX_DT_LEN);
    mmi_asc_n_to_ucs2(strBuff, strCursor, 2);
    result.nMonth = (U16) gui_atoi((U16*) strBuff);
    strCursor += 2;

    /* day */
    memset(strBuff, 0, VCLNDR_MAX_DT_LEN);
    mmi_asc_n_to_ucs2(strBuff, strCursor, 2);
    result.nDay = (U16) gui_atoi((U16*) strBuff);
    strCursor += 2;

    /* ignore 'T' */
    if (strCursor[0] != VCLNDR_DT_SEP_CHAR)
    {
        /* Because DT format of vCalendar from HP phone may be YYYYMMDD */
        if (strCursor[0] == 0)
		{        
            return result;    
        }
        memset(&result, 0, sizeof(MYTIME));
        return result;
    }

    strCursor++;

    /* hour */
    memset(strBuff, 0, VCLNDR_MAX_DT_LEN);
    mmi_asc_n_to_ucs2(strBuff, strCursor, 2);
    result.nHour = (U16) gui_atoi((U16*) strBuff);
    strCursor += 2;

    /* minute */
    memset(strBuff, 0, VCLNDR_MAX_DT_LEN);
    mmi_asc_n_to_ucs2(strBuff, strCursor, 2);
    result.nMin = (U16) gui_atoi((U16*) strBuff);
    strCursor += 2;

    /* second */
    memset(strBuff, 0, VCLNDR_MAX_DT_LEN);
    mmi_asc_n_to_ucs2(strBuff, strCursor, 2);
    result.nSec = (U16) gui_atoi((U16*) strBuff);
    strCursor += 2;

    if (strCursor[0] == VCLNDR_UTC_CHAR)    /* UTC time */
    {
        S16 TimeZone;
        U8 Neglect = FALSE;
        MYTIME incTime;

        memset(&incTime, 0, sizeof(MYTIME));
        /* convert to local time */
        TimeZone = (S16) (GetTimeZone(PhnsetGetHomeCity()) * 60);
        if (TimeZone < 0)
        {
            Neglect = TRUE;
            TimeZone = 0 - TimeZone;
        }

        incTime.nHour = TimeZone / 60;
        incTime.nMin = TimeZone % 60;

        if (Neglect)
        {
            DecrementTime(result, incTime, &result);
        }
        else
        {
            IncrementTime(result, incTime, &result);
        }
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_uti_get_recurr
 * DESCRIPTION
 *  Get recurrence of a vCalendar object from an RRULE string
 * PARAMETERS
 *  strRRule        [IN]            String represents the RRULE
 *  recurr          [IN/OUT]        Struct variable the store the result of converting
 * RETURNS
 *  TURE if the RRULE supported, otherwise, FALSE
 *****************************************************************************/
U8 mmi_vclndr_uti_get_recurr(S8 *strRRule, vclndr_recurr_struct *recurr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *tmpString = strRRule;
    S8 compString[VCLNDR_MAX_DT_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    recurr->Days = 0;

    if (strlen(tmpString) < VCLNDR_MIN_RECURR_LEN)  /* string too short */
    {
        return FALSE;
    }

    /* Daily */
    sprintf(compString, "%s %c", g_vclndr_recurr[VCLNDR_DAILY], VCLNDR_POUND_CHAR);
    if (mmi_vobj_uti_cmp_filed(tmpString, compString))
    {
        recurr->Repeat = mmi_alm_get_freq_order(TODO_FREQ_NUM, g_tdl_freq_set, ALM_FREQ_EVERYDAY);
        return TRUE;
    }

    /* Weekly */
    sprintf(compString, "%s %c", g_vclndr_recurr[VCLNDR_WEEKLY], VCLNDR_POUND_CHAR);
    if (mmi_vobj_uti_cmp_filed(tmpString, compString))
    {
        recurr->Repeat = mmi_alm_get_freq_order(TODO_FREQ_NUM, g_tdl_freq_set, ALM_FREQ_WEEKLY);
        return TRUE;
    }

    /* Days */
    if (mmi_vobj_uti_cmp_filed(tmpString, (S8*) g_vclndr_recurr[VCLNDR_WEEKLY]))
    {
        /* get week days */
        tmpString += 3; /* move to starting point */

        recurr->Days = mmi_vclndr_uti_get_days(tmpString);
        if (recurr->Days)
        {
            recurr->Repeat = mmi_alm_get_freq_order(TODO_FREQ_NUM, g_tdl_freq_set, ALM_FREQ_DAYS);
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }

    /* Monthly */
    sprintf(compString, "%s %c", g_vclndr_recurr[VCLNDR_MONTHLY], VCLNDR_POUND_CHAR);
    if (mmi_vobj_uti_cmp_filed(tmpString, g_vclndr_recurr[VCLNDR_MONTHLY]))
    {
        recurr->Repeat = mmi_alm_get_freq_order(TODO_FREQ_NUM, g_tdl_freq_set, ALM_FREQ_MONTHLY);
        return TRUE;
    }

#ifdef __MMI_ADVANCED_TODO__
    /* Yearly */
    sprintf(compString, "%s %c", g_vclndr_recurr[VCLNDR_YEARLY], VCLNDR_POUND_CHAR);
    if (mmi_vobj_uti_cmp_filed(tmpString, compString))
    {
        /* Yearly is a special case for TDL repeat type */
        recurr->Repeat = mmi_alm_get_freq_order(TODO_FREQ_NUM + 1, g_tdl_freq_set, ALM_FREQ_YEARLY); 
        return TRUE;
    }
#endif    
    
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_uti_get_days
 * DESCRIPTION
 *  Get the day of week value from string
 * PARAMETERS
 *  strDays     [IN]        String to be converted
 * RETURNS
 *  the value of days if found, otherwise 0;
 *****************************************************************************/
U8 mmi_vclndr_uti_get_days(S8 *strDays)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result = 0;
    S8 *tmpString = strDays;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (tmpString[0] == VCLNDR_LWSP_CHAR)
    {
        tmpString++;
    }

    while (tmpString[0] != VOBJ_NULL && tmpString[0] != VCLNDR_POUND_CHAR)
    {
        for (i = 0; i < VCLNDR_NUM_OF_DAYS; i++)
        {
            if (!mmi_vobj_uti_strnicmp(tmpString, (S8*) g_vclndr_days[i], 2))
            {
                result |= (0x1 << i);
                tmpString += 2;
                break;
            }
        }

        if (i == VCLNDR_NUM_OF_DAYS)
        {
            return 0;
        }

        if (tmpString[0] != VCLNDR_LWSP_CHAR)
        {
            return 0;
        }

        tmpString++;

    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vlcndr_uti_flush_to_file
 * DESCRIPTION
 *  Write string buffer to file.
 * PARAMETERS
 *  fh          [IN]        File handle
 *  strBuff     [IN]        String to be write
 * RETURNS
 *  TRUE if success; otherwise FALSE
 *****************************************************************************/
BOOL mmi_vlcndr_uti_flush_to_file(FS_HANDLE fh, S8 *strBuff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 wByte;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (FS_Write(fh, strBuff, AsciiStrlen((const S8*)strBuff), (UINT *)&wByte) == FS_NO_ERROR)
    {
        return TRUE;
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_uti_get_param
 * DESCRIPTION
 *  To retrieve the parameter value from a string
 * PARAMETERS
 *  source          [IN]            Source string to be computed.
 *  para_name       [IN]            Parameter to be retrieve.
 *  result          [IN/OUT]        Value of parameter
 *  max_len         [IN]            Maximum length to be convert
 * RETURNS
 *  TRUE if parameter found; otherwise FALSE
 *****************************************************************************/
U8 mmi_vclndr_uti_get_param(S8 *source, S8 *para_name, S8 *result, S32 max_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *cursor, *para_end;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    para_end = strstr(source, (S8*) VCLNDR_VALUE_SEP_STR);

    if ((cursor = strstr(source, para_name)) == NULL)
    {
        return FALSE;
    }

    /*encoding keyword may appear in value of parameter */
    if (cursor >= para_end)
    {
        return FALSE;
    }

    if ((cursor = strstr(cursor, (S8*) VCLNDR_EQUAL_STR)) == NULL)     /* move cursor next to "=" */
    {
        return FALSE;
    }

    cursor++;

    for (i = 0; i < max_len; cursor++)
    {
        if (cursor[0] == VCLNDR_VALUE_SEP_CHAR || cursor[0] == VCLNDR_PARA_SEP_CHAR || cursor[0] == VOBJ_NULL)
        {
            break;
        }
		else if (cursor[0] == VCLNDR_LWSP_CHAR)
		{
			continue;
		}

        result[i] = cursor[0];
		i++;
    }

    result[i] = VOBJ_NULL;

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_uti_get_charset
 * DESCRIPTION
 *  To retrieve the charset
 * PARAMETERS
 *  string      [IN]        String to be parsed
 * RETURNS
 *  Enum value of charset.
 *****************************************************************************/
U8 mmi_vclndr_uti_get_charset(S8 *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* currently only support UTF-8 */
    if (!mmi_vobj_uti_strnicmp((S8*) string, (S8*) g_vobj_charset[0], strlen(g_vobj_charset[0])))
    {
        return VOBJ_CH_UTF8;
    }
    else
    {
        return 0xff;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_uti_get_encoding_type
 * DESCRIPTION
 *  To retrieve the coding type
 * PARAMETERS
 *  string      [IN]        String to be parsed
 * RETURNS
 *  Enum value of encoding type.
 *****************************************************************************/
U8 mmi_vclndr_uti_get_encoding_type(S8 *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < VOBJ_EN_TOTAL; i++)
    {
        if (!mmi_vobj_uti_strnicmp((S8*) string, (S8*) g_vobj_encoding[i], strlen(g_vobj_encoding[i])))
        {
            break;
        }
    }

    return i;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_uti_is_file_exist
 * DESCRIPTION
 *  To check if file is already exist
 * PARAMETERS
 *  file_path_name      [IN]        File path and name
 * RETURNS
 *  TURE of file exists; otherwise FALSE.
 *****************************************************************************/
U8 mmi_vclndr_uti_is_file_exist(S8 *file_path_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fh;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if file already exist */
    fh = FS_Open((U16*) file_path_name, FS_READ_ONLY);

    if (fh > 0)
    {
        FS_Close(fh);
        return TRUE;
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_uti_get_default_filename
 * DESCRIPTION
 *  To generate default file name used for other application
 * PARAMETERS
 *  result      [IN/OUT]        Pointer to the result
 * RETURNS
 *  TURE of file exists; otherwise FALSE.(?)
 *****************************************************************************/
void mmi_vclndr_uti_get_default_filename(S8 *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 ascii_path[VOBJ_MAX_PATH_LENGTH / ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(ascii_path, "%c:\\%s\\%s", VOBJ_DRV, VOBJ_FILE_PATH, VOBJ_VCLNDR_DEFAULT_FILE_NAME);
    mmi_asc_to_ucs2(result, ascii_path);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_uti_get_default_at_command_filename
 * DESCRIPTION
 *  To generate default file name used for AT command
 * PARAMETERS
 *  result      [IN/OUT]        Pointer to the result
 * RETURNS
 *  TURE of file exists; otherwise FALSE.(?)
 *****************************************************************************/
void mmi_vclndr_uti_get_default_at_command_filename(S8 *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 ascii_path[VOBJ_MAX_PATH_LENGTH / ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(ascii_path, "%c:\\%s\\%s", VOBJ_DRV, VOBJ_FILE_PATH, VOBJ_VCLNDR_DEFAULT_FILE_NAME_FOR_AT);
    mmi_asc_to_ucs2(result, ascii_path);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vclndr_uti_del_default_file
 * DESCRIPTION
 *  To delete default file buffer used for other application
 * PARAMETERS
 *  void
 * RETURNS
 *  TURE of file exists; otherwise FALSE.(?)
 *****************************************************************************/
void mmi_vclndr_uti_del_default_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 path[VOBJ_MAX_PATH_LENGTH];
    S8 ascii_path[VOBJ_MAX_PATH_LENGTH / ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(ascii_path, "%c:\\%s\\%s", VOBJ_DRV, VOBJ_FILE_PATH, VOBJ_VCLNDR_DEFAULT_FILE_NAME);
    mmi_asc_to_ucs2(path, ascii_path);

    FS_Delete((U16*) path);
}

#define  VCLNDR_TEMP_USAGE
static const unsigned char widget_utf8_bytes_per_character[16] = 
{
    1, 1, 1, 1, 1, 1, 1, 1,
    0, 0, 0, 0, 2, 2, 3, 0  /* we don't support UCS4 */
};


/*****************************************************************************
 * FUNCTION
 *  utf8_strlen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 utf8_strlen(const U8 *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int count = 0;
    int rawlen;
    int d;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (s == 0)
    {
        return 0;
    }

    rawlen = strlen((const char*)s);

    while (*s != '\0' && rawlen > 0)
    {
        d = widget_utf8_bytes_per_character[*s >> 4];
        if (d == 0)
        {
            return count;
        }
        rawlen -= d;
        s += d;

        count++;
    }

    return count;
}


/*****************************************************************************
 * FUNCTION
 *  utf8_to_ucs2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ucs2        [?]     
 *  utf8        [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 utf8_to_ucs2(U16 *ucs2, U8 *utf8)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    unsigned char c = utf8[0];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (c < 0x80)
    {
        *ucs2 = c;
        return 1;
    }
    else if (c < 0xe0)
    {
        *ucs2 = ((U16) (c & 0x1f) << 6) | (U16) (utf8[1] ^ 0x80);
        return 2;
    }
    else
    {
        *ucs2 = ((U16) (c & 0x0f) << 12) | ((U16) (utf8[1] ^ 0x80) << 6) | (U16) (utf8[2] ^ 0x80);
        return 3;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ucs2_to_utf8
 * DESCRIPTION
 *  
 * PARAMETERS
 *  utf8        [?]         
 *  ucs2        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 ucs2_to_utf8(U8 *utf8, U16 ucs2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ucs2 < 0x80)
    {
        count = 1;
    }
    else if (ucs2 < 0x800)
    {
        count = 2;
    }
    else
    {
        count = 3;
    }
    switch (count)
    {
        case 3:
            utf8[2] = 0x80 | (ucs2 & 0x3f);
            ucs2 = ucs2 >> 6;
            ucs2 |= 0x800;
        case 2:
            utf8[1] = 0x80 | (ucs2 & 0x3f);
            ucs2 = ucs2 >> 6;
            ucs2 |= 0xc0;
        case 1:
            utf8[0] = (U8) ucs2;
    }
    return count;
}


/*****************************************************************************
 * FUNCTION
 *  ucs2_to_utf8_len
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ucs2        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 ucs2_to_utf8_len(U16 ucs2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ucs2 < 0x80)
    {
        return 1;
    }
    else if (ucs2 < 0x800)
    {
        return 2;
    }
    else
    {
        return 3;
    }
}


/*****************************************************************************
 * FUNCTION
 *  utf8_to_ucs2_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest            [?]         
 *  dest_size       [IN]        
 *  src             [?]         
 * RETURNS
 *  
 *****************************************************************************/
S32 utf8_to_ucs2_string(U8 *dest, int dest_size, U8 *src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int pos = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // FIXME     1. we should check the sanity of the UTF8 string 
    //                   2. this check is not correct when dest_size < 2 or dest_size is odd
    while (*src)
    {
        src += utf8_to_ucs2((U16*) (dest + pos), src);
        pos += 2;
        if (pos >= dest_size - 2)
        {
            break;
        }
    }
    dest[pos] = 0;
    dest[pos + 1] = 0;
    return pos + 2;
}


/*****************************************************************************
 * FUNCTION
 *  ucs2_to_utf8_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest            [?]         
 *  dest_size       [IN]        
 *  src             [?]         
 * RETURNS
 *  
 *****************************************************************************/
S32 ucs2_to_utf8_string(U8 *dest, S32 dest_size, U8 *src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 pos = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (src[0] || src[1])
    {
        if (pos + ucs2_to_utf8_len(*(U16*) src) >= dest_size)  /* leave space of '\0' */
        {
            break;
        }

        pos += ucs2_to_utf8(dest + pos, (*(U16*) src));
        src += 2;
        if (pos >= dest_size - 1)
        {
            break;
        }
    }
    if (pos >= dest_size)
    {
        dest[dest_size - 1] = 0;
    }
    else
    {
        dest[pos] = 0;
    }
    return pos + 1;
}

#endif /* defined(__MMI_VCALENDAR__) */ /* #if defined(__MMI_VCALENDAR__) */
#endif /* _MMI_VCALENDAR_C */ /* END #define _MMI_VCALENDAR_C */

