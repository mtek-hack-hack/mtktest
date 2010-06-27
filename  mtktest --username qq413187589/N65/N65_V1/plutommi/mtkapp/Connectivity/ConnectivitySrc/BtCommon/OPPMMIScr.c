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
 * OPPMMIScr.c
 *
 * Project:
 * --------
 *   MMI
 *
 * Description:
 * ------------
 *   This file is for MMI OPP service.
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!

 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#if defined __MMI_OPP_SUPPORT__ || defined __MMI_BIP_SUPPORT__

/*  Include: MMI header file */
#include "CommonScreens.h"      /* DisplayPopup */
#include "ProtocolEvents.h"
#include "SettingProfile.h"     /* for tone ID */
#include "MainMenuDef.h"        /* for MAIN_MENU_TITLE_EXTRA_APP_ICON  */
#include "wgui_status_icons.h"  /* for STATUS_ICON_IR */
#include "IdleAppDef.h" /* g_idle_context */
#include "IdleAppProt.h"        /* EntryIdleScreen() */
#include "ProfileGprots.h"      /* PlayRequestTone */
#include "gpioInc.h"    /* TurnOnBacklight */
/* Leo add for DLT */
/* Leo end */

/* External Device Header Files */
#include "FileMgr.h"    /* max file path size. */
#include "OPPMMIGprots.h"
/* Leo add for DLT */
#include "FileManagerDef.h"
/* Leo end */
#include "CallManagementGprot.h"
#include "BTMMIBipGprot.h"

#if defined(__MMI_BT_MTK_SUPPORT__)   
#include "bluetooth_struct.h"
#include "btmmicm.h"
#include "BTMMIScr.h"
#include "BTMMIScrGprots.h"
#include "BTMMIOpp.h"
#include "OPPMMIScr.h"
#include "BTMMIOppGprots.h"
#endif

#include "ExtDeviceDefs.h"

#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#endif 

#include "BTMMIFtpGprots.h"
#include "BTMMIFtpScr.h"//sergeycao
#include "BTMMIFtp.h" //sergeycao

MMI_OPP_SCR_CONTEX mmi_opp_scr_cntx;
MMI_OPP_SCR_CONTEX *mmi_opp_scr_cntx_p = &mmi_opp_scr_cntx;

extern MMI_BOOL mmi_bt_ftp_check_folder_existed_external(U8* absolute_path);
/***************************************************************************** 
 * External Variable
 *****************************************************************************/
extern S8 nPrintableStr[];  /* for file name buffer */

/***************************************************************************** 
 * External Functions
 *****************************************************************************/
extern void PlayMessageArrivalTone(void);

/***************************************************************************** 
* Marco
*****************************************************************************/
#define MMI_OPP_BUILD_ABORTING_NOTY_STR()                                                \
{                                                                                        \
   kal_wstrcpy( (U16 *)mmi_opp_idle_notify_str, (U16 *)GetString(STR_BT_CANCELLING) ); \
}

U8 mmi_opp_recv_notify_str[64];


#define MMI_OPP_RECV_IND_STR()                                                                \
{                                                                                               \
   S8 temp_path[128]; \
   kal_wstrcpy( (U16 *)mmi_opp_recv_notify_str, (U16 *)GetString(STR_OPP_RECV_FILE_IND) ); \
   mmi_ucs2cat( (S8*)mmi_opp_recv_notify_str,  (S8*)L" '"); \
   MMI_OPP_MAKE_RECV_PATH( temp_path ); \
   mmi_ucs2cat( (S8*)mmi_opp_recv_notify_str,  (S8*)  temp_path /*ftps_cntx_p->root_folder*/); \
   mmi_ucs2cat( (S8*)mmi_opp_recv_notify_str,  (S8*) L"' "); \
   mmi_ucs2cat( (S8*)mmi_opp_recv_notify_str,  (S8*)GetString(STR_OPP_NOTY_RECV_FOLDER) );  \
                                                                                                \
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_scr_data_transfer_ind
 * DESCRIPTION
 *  This function is to indicate the user OPP data is transferring
 * PARAMETERS
 *  opp_role        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_opp_scr_data_transfer_ind(MMI_BT_PROFILE_ROLE opp_role)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bt_status_icon_start_blinking(MMI_BT_OBEX_OBJECT_PUSH_SERVICE_UUID, opp_role);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_scr_data_stop_ind
 * DESCRIPTION
 *  This function is to indicate the user OPP data transferring  is stopped
 * PARAMETERS
 *  opp_role        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_opp_scr_data_stop_ind(MMI_BT_PROFILE_ROLE opp_role)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bt_status_icon_stop_blinking(MMI_BT_OBEX_OBJECT_PUSH_SERVICE_UUID, opp_role);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_obj_receive_ind
 * DESCRIPTION
 *  This function is to notify user that opp received a unrecognized object
 * PARAMETERS
 *  path_src        [?]     
 *  filename        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
MMI_OPP_NFY_TYPE mmi_opp_obj_receive_ind(void *path_src, void *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 fcnt = 0;
    U8 *path_buf;
    FS_HANDLE h;
    U8 recv_cnt = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Get total pending objects */
    recv_cnt = mmi_opp_get_recv_files_cnt();
    if (recv_cnt == 0xFF)
    {
        mmi_opp_set_recv_files_cnt(0xFF);
    }
    else
    {
        MMI_OPP_CTX(cur_recv_file_cnt) ++;
        mmi_opp_set_recv_files_cnt((U8) (recv_cnt + 1));
    }

    /* Get file path buffer */
    path_buf = OslMalloc(FMGR_MAX_PATH_LEN * ENCODING_LENGTH);
    MMI_OPP_ASSERT(path_buf != NULL);

    /* Build actually file name */
	    MMI_OPP_MAKE_RECV_PATH(path_buf);
	//sergeycao
        //mmi_ucs2cpy((PS8) path_buf, (PS8) ftps_cntx_p->root_folder);
   
    /* kal_wstrcat( (kal_uint16 *)path_buf, L"\\" ); */
    kal_wstrcat((kal_uint16*) path_buf, (kal_uint16*) filename);

    /* Rename temp file name to actually object name as file name */
    h = FS_Rename((kal_uint16*) path_src, (kal_uint16*) path_buf);
    /* Check if file exist */
    if (h < FS_NO_ERROR)
    {
        fcnt++;
        while (fcnt < 0xFF)
        {
           MMI_OPP_MAKE_RECV_PATH(path_buf);
//sergeycao
//        mmi_ucs2cpy((PS8) path_buf, (PS8) ftps_cntx_p->root_folder);
            kal_wsprintf((kal_uint16*) nPrintableStr, "Dup(%d)", fcnt);
            kal_wstrcat((kal_uint16*) nPrintableStr, (kal_uint16*) filename);
            kal_wstrcat((kal_uint16*) path_buf, (kal_uint16*) nPrintableStr);

            h = FS_Rename((kal_uint16*) path_src, (kal_uint16*) path_buf);
            if (h < FS_NO_ERROR)
            {
                fcnt++;
            }
            else
            {
                break;
            }
        }
    }

    /* free path buffer */
    OslMfree(path_buf);

    return MMI_OPP_NFY_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_scr_recv_obj_ind
 * DESCRIPTION
 *  This function is to display popup sceren when receiving file
 * PARAMETERS
 *  cause       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_opp_scr_recv_obj_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
     if (opp_suppress_popup_flag == MMI_TRUE ||
       (isInCall() && !GetWapCallPresent()) )
    {
        /*
         * If the applications won't want to show the WAP/MMS popup or
         * the handset has the voice call, 
         * we return here directly.
         */
        return ;
    }
    
    MMI_OPP_RECV_IND_STR()  ;

    if ((isInCall() != MMI_TRUE) || (IsWapCallPresent()) ||opp_suppress_popup_flag==MMI_FALSE)
    {
        /* Play warning tone to notify file saved */
        DisplayPopup(mmi_opp_recv_notify_str, IMG_GLOBAL_ACTIVATED, 1, UI_POPUP_NOTIFYDURATION_TIME, WARNING_TONE);
    }

    if (g_idle_context.IsOnIdleScreen || GetActiveScreenId() == SCR_OPP_NOTY_FILE_RECV)
    {
        EntryIdleScreen();
    }

    TurnOnBacklight(1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_notify_recv_err
 * DESCRIPTION
 *  This function is to display popup sceren when receiving error
 * PARAMETERS
 *  cause       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_opp_notify_recv_err(MMI_OPP_NFY_TYPE cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cause == MMI_OPP_NFY_DISK_FULL)
    {
        DisplayPopup(
            (PU8) GetString(STR_OPP_RECV_DISK_FULL),
            IMG_GLOBAL_ERROR,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
    }
    else if (cause == MMI_OPP_NFY_CONNECTION_DISCONNECTED)
    {
        DisplayPopup(
            (PU8) GetString(STR_OPP_CON_DISCONNECTED),
            IMG_GLOBAL_ERROR,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
    }
    else if (cause == MMI_OPP_NFY_CONNECTION_BUSY)
    {
        DisplayPopup(
            (PU8) GetString(STR_OPP_NOTY_CON_BUSY),
            IMG_GLOBAL_ERROR,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_UNFINISHED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            WARNING_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_entry_idle_notify_scr
 * DESCRIPTION
 *  This function is to display notify screen in idle screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_opp_idle_notify_str[32];

#define MMI_OPP_BUILD_RECV_ACCEPT_NOTY_STR()                                                  \
{                                                                                             \
   kal_wstrcpy( (U16 *)mmi_opp_idle_notify_str, (U16 *)GetString(STR_OPP_NOTY_RECV_ACCEPT) ); \
}

#define MMI_OPP_BUILD_NOTY_STR()                                                                \
{                                                                                               \
   U16 cnt[8];                                                                                  \
                                                                                                \
   kal_wstrcpy( (U16 *)mmi_opp_idle_notify_str, (U16 *)GetString(STR_OPP_NOTY_RECV_FILE_HED) ); \
   kal_wsprintf( (U16 *)cnt, " %d ", mmi_opp_get_recv_files_cnt() );                            \
   kal_wstrcat( (U16 *)mmi_opp_idle_notify_str,  (U16*) cnt);                                   \
   if (mmi_opp_get_recv_files_cnt()==1)      \
   {                        \
       kal_wstrcat( (U16 *)mmi_opp_idle_notify_str,  (U16*) GetString(STR_OPP_NOTY_RECV_FILE_TIL)); \
    }                 \
    else             \
   {                                \
        kal_wstrcat( (U16 *)mmi_opp_idle_notify_str,  (U16*) GetString(STR_OPP_NOTY_RECV_MULTI_FILE_TIL)); \
   }                                \
                                                                                                \
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_add_history_before_cm_marker
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrn_id: current screen ID,
 *  func_ptr: current entry new screen function
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_opp_add_history_before_cm_marker(U16 scrn_id, FuncPtr func_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Scr.scrnID = scrn_id;
    Scr.entryFuncPtr = func_ptr;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) L"");

    InsertHistoryBeforeThisScrn(GetCmMarkerScrnID(), Scr);
}



void mmi_opp_entry_idle_notify_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_OPP_BUILD_NOTY_STR();

    if (mmi_opp_get_recv_files_cnt() == 0)
    {
        EntryIdleScreen();
        return;
    }

    EntryNewScreen(SCR_OPP_NOTY_FILE_RECV, NULL, NULL, NULL);

    if (g_keylock_context.gKeyPadLockFlag == 0)
    {
        ShowCategory154Screen(
            0,
            0,
            STR_OPP_NOTY_RECV_FILE_BROWSE,
            0,
            STR_GLOBAL_BACK,
            0,
            (U8*) mmi_opp_idle_notify_str,
            NULL,
            IMG_GLOBAL_INFO,
            NULL);

        SetLeftSoftkeyFunction(mmi_opp_notify_scr_browse, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_opp_notify_scr_goback_func, KEY_EVENT_UP);
        SetKeyHandler(mmi_opp_notify_scr_endkey_func, KEY_END, KEY_EVENT_DOWN);
    }
    else
    {
        ShowCategory154Screen(
            0,
            0,
            g_keylock_context.KeyLockLSKStringID,
            g_keylock_context.KeyLockLSKIconID,
            g_keylock_context.KeyLockRSKStringID,
            g_keylock_context.KeyLockRSKIconID,
            (U8*) mmi_opp_idle_notify_str,
            NULL,
            IMG_GLOBAL_INFO,
            NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_entry_recv_confirm_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_opp_entry_recv_confirm_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (isIncomingCall() )
    {
        mmi_opp_add_history_before_cm_marker(SCR_OPP_NOTY_RECV_ACCEPT,mmi_opp_entry_recv_confirm_scr);
        return;
    }
        
    MMI_OPP_BUILD_RECV_ACCEPT_NOTY_STR();

    EntryNewScreen(SCR_OPP_NOTY_RECV_ACCEPT, NULL, mmi_opp_entry_recv_confirm_scr, NULL);

    SetDelScrnIDCallbackHandler(SCR_OPP_NOTY_RECV_ACCEPT, (HistoryDelCBPtr) NULL);
    DeleteScreenIfPresent(SCR_OPP_NOTY_RECV_ACCEPT);

    ShowCategory165Screen(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (UI_string_type) mmi_opp_idle_notify_str,
        IMG_GLOBAL_QUESTION,
        NULL);

    SetLeftSoftkeyFunction(mmi_opp_accept_file_recv, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_opp_reject_file_recv, KEY_EVENT_UP);
    SetDelScrnIDCallbackHandler(SCR_OPP_NOTY_RECV_ACCEPT, (HistoryDelCBPtr) mmi_opp_confirm_del_cb);

    TurnOnBacklight(1);
}

/* Attar : Seems no one use this function */


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_entry_idle_notify_scr_keylock
 * DESCRIPTION
 *  This function is to display notify screen in idle screen
 * PARAMETERS
 *  lsk_img_id      [IN]        
 *  lsk_str_id      [IN]        
 *  rsk_img_id      [IN]        
 *  rsk_str_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_opp_entry_idle_notify_scr_keylock(U16 lsk_img_id, U16 lsk_str_id, U16 rsk_img_id, U16 rsk_str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_OPP_BUILD_NOTY_STR();

    ShowCategory154Screen(
        0,
        0,
        lsk_str_id,
        lsk_img_id,
        rsk_str_id,
        rsk_img_id,
        (U8*) mmi_opp_idle_notify_str,
        NULL,
        IMG_GLOBAL_INFO,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_notify_scr_browse
 * DESCRIPTION
 *  This function is to browse the received folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_opp_notify_scr_browse(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *path_tmpbuf;
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET_ALL(&filter);

    path_tmpbuf = (S8*) OslMalloc(FMGR_PATH_BUFFER_SIZE);
    ASSERT(path_tmpbuf != NULL);

    MMI_OPP_MAKE_RECV_PATH(path_tmpbuf);
//sergeycao
//        mmi_ucs2cpy((PS8) path_tmpbuf, (PS8) ftps_cntx_p->root_folder);

#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (mmi_usb_check_path_exported(path_tmpbuf))
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            OslMfree(path_tmpbuf);
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    mmi_fmgr_select_path_and_enter(
        APP_EXTDEVICE,
        FMGR_SELECT_BROWSE,
        filter,
        path_tmpbuf,    /* (PS8)L"D:\\Received", */
        mmi_opp_notify_scr_browse_cb);
    OslMfree(path_tmpbuf);

    mmi_opp_set_recv_files_cnt(0);  /* After take action */
#ifdef __MMI_BIP_SUPPORT__    
    mmi_bt_bip_set_recv_images_cnt(0);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_notify_scr_browse_cb
 * DESCRIPTION
 *  This function is to browse received folder callback func
 * PARAMETERS
 *  filename        [?]         
 *  isShort         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_opp_notify_scr_browse_cb(void *filename, int isShort)
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
 *  mmi_opp_notify_scr_goback_func
 * DESCRIPTION
 *  This function is to go back history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_opp_notify_scr_goback_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_opp_set_recv_files_cnt(0);  /* After take action */
#ifdef __MMI_BIP_SUPPORT__    
    mmi_bt_bip_set_recv_images_cnt(0);
#endif

    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_notify_scr_endkey_func
 * DESCRIPTION
 *  This function is to back to idle screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_opp_notify_scr_endkey_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_opp_set_recv_files_cnt(0);  /* After take action */
#ifdef __MMI_BIP_SUPPORT__    
    mmi_bt_bip_set_recv_images_cnt(0);
#endif

    DisplayIdleScreen();
}

/* PMT PANKAJ START- Moved the OPP code from FileMgr.c to OPPMMIScr.c */

/*****************************************************************************
* FUNCTION
*  mmi_opp_entry_fmgr_fwd
* DESCRIPTION
*   This function is to send an object through OPP when it has been forwared from File Manager
*
* PARAMETERS
*  NONE.
* RETURNS
*  NONE.
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/

#define OPP_PROG_UPD_DUR  2000
#define OPP_REQ_TIMEOUT   15000
static U16 opp_fmgr_send_str_buf[64];

#define OPP_UDPADE_STR() {                                                                                                                          \
       U16 fmgr_opp_send_per_str_buf[32];                                                                                                           \
       if( (mmi_ucs2strlen( (S8*)  GetString(STR_GLOBAL_SENT) )+1) > ((sizeof(opp_fmgr_send_str_buf)/2) -(sizeof(fmgr_opp_send_per_str_buf)/2)) ) \
         ASSERT(MMI_FALSE);                                                                                                                         \
   kal_wsprintf( (U16*)fmgr_opp_send_per_str_buf, "(%d%c) ", mmi_opp_retrieve_put_prog_percentage(),'%' );                                          \
      mmi_ucs2cpy((S8*)opp_fmgr_send_str_buf, GetString(STR_GLOBAL_SENT) );                                                                    \
      mmi_ucs2cat((S8*)opp_fmgr_send_str_buf, (S8*)fmgr_opp_send_per_str_buf);                                                                 \
}

 
U16 mmi_opp_notify_str[32];

#define MMI_OPP_BUILD_DISCONNCTING_NOTY_STR()         \
{                                                      \
    kal_wstrcpy( (U16 *) mmi_opp_notify_str, (U16 *) GetString(STR_OPP_NOTY_DISCONNECTING));    \
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
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_opp_disconnecting_screen_del_cb
 * DESCRIPTION
 *  This function is the callback funcion for deleting disconnecting screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_bt_opp_disconnecting_screen_del_cb(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == mmi_opp_disconncting())
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
 *  mmi_opp_entry_disconnting
 * DESCRIPTION
 *  This function is to entry disconnecting screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_opp_entry_disconnting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_OPP_DISCONNECTING, NULL, mmi_opp_entry_disconnting, NULL);

    /* clear all key handlers so as to restrict duplicate reqs */
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);

    MMI_OPP_BUILD_DISCONNCTING_NOTY_STR();

    ShowCategory66Screen(
        STR_OPP_NOTY_DISCONNECTING,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        0,
        0,
        0,
        0,
        (U8*) mmi_opp_notify_str,
        IMG_GLOBAL_PROGRESS,
        NULL);

    SetDelScrnIDCallbackHandler(SCR_OPP_DISCONNECTING, mmi_bt_opp_disconnecting_screen_del_cb);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_exit_fmgr_fwd
 * DESCRIPTION
 *  This function is the exit function for the send through file manager screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_opp_exit_fmgr_fwd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(FMGR_PROG_UPDATE_TIMER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_stop_req_timer
 * DESCRIPTION
 *  This function is the exit function for the stop the OPP request timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_opp_stop_req_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(BT_OPP_REQ_TIMER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_sending_screen_del_cb
 * DESCRIPTION
 *  This function is the callback funcion for deleting sending screen
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_opp_sending_screen_del_cb(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == mmi_opp_is_sending())
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
 *  mmi_opp_aborting_screen_del_cb
 * DESCRIPTION
 *  This function is the callback funcion for deleting aborting screen
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_opp_aborting_screen_del_cb(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == mmi_opp_is_aborting())
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
 *  mmi_opp_update_prog_tohdlr
 * DESCRIPTION
 *  This function is the handler for showing the progress of transfer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_opp_update_prog_tohdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    OPP_UDPADE_STR();
    cat66_update_progress_string();
    StartTimer(FMGR_PROG_UPDATE_TIMER, OPP_PROG_UPD_DUR, mmi_opp_update_prog_tohdlr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_entry_fmgr_fwd
 * DESCRIPTION
 *  This function is the handler for showing the progress of transfer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_opp_entry_fmgr_fwd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Call Exit Handler */
    EntryNewScreen(SCR_OPP_SENDING, mmi_opp_exit_fmgr_fwd, mmi_opp_entry_fmgr_fwd, NULL);
#if 0
/* under construction !*/
#endif
    /* clear all key handlers so as to restrict duplicate reqs */
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);

    /* Show Sending screen */
    OPP_UDPADE_STR();
    ShowCategory66Screen(
        STR_OPP_SEND,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        0,
        0,
        STR_GLOBAL_CANCEL,
        0,
        (U8*) opp_fmgr_send_str_buf,
        IMG_GLOBAL_PROGRESS,
        NULL);

    /* Set Right softkey function to abort sending */    
    SetRightSoftkeyFunction(mmi_bt_opp_snd_abort, KEY_EVENT_UP);
    
    SetKeyHandler(mmi_opp_end_key_press_hdler, KEY_END, KEY_EVENT_DOWN);
    SetDelScrnIDCallbackHandler(SCR_OPP_SENDING, (HistoryDelCBPtr) mmi_opp_sending_screen_del_cb);

    StartTimer(FMGR_PROG_UPDATE_TIMER, OPP_PROG_UPD_DUR, mmi_opp_update_prog_tohdlr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_entry_abort_fwd
 * DESCRIPTION
 *  This function is the handler for showing the aborting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_opp_entry_abort_fwd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Call Exit Handler */
    EntryNewScreen(SCR_OPP_ABORTING, mmi_opp_stop_req_timer, mmi_opp_entry_abort_fwd, NULL);

    /* clear all key handlers so as to restrict duplicate reqs */
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);

    MMI_OPP_BUILD_ABORTING_NOTY_STR();

    ShowCategory66Screen(STR_BT_CANCELLING, GetRootTitleIcon(MENU_CONN_BT_MAIN), 0, 0, 0, 0, (U8*) mmi_opp_idle_notify_str, IMG_GLOBAL_PROGRESS, NULL);

    SetDelScrnIDCallbackHandler(SCR_OPP_ABORTING, (HistoryDelCBPtr) mmi_opp_aborting_screen_del_cb);
    /* While MTK BT, no need to send disconnect because OBEX stack will guard this */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_fmgr_forward_to_opp_callback
 * DESCRIPTION
 *  This function is the call back used when the transfer gets completed
 * PARAMETERS
 *  buf_p       [?]         
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_opp_fmgr_forward_to_opp_callback(void *buf_p, U32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (buf_p)
    {
        OslMfree(buf_p);
    }

    if (result == MMI_OPP_ERR_SUCCESS)
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            SUCCESS_TONE);
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_UNFINISHED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            WARNING_TONE);
    }
    DeleteScreenIfPresent(SCR_OPP_SENDING);

    StopTimer(FMGR_PROG_UPDATE_TIMER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_request_timeout_callback
 * DESCRIPTION
 *  This function is the call back used the request timeout
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_opp_request_timeout_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((MMI_OPP_CTX(opc_state) == MMI_OPC_DISCONNECTING) || (MMI_OPP_CTX(opc_state) == MMI_OPC_ABORTING))
    {
        if (MMI_OPP_CTX(opc_state) == MMI_OPC_ABORTING)
        {
 
        }
        mmi_opp_opc_connection_terminated(MMI_OPP_ERR_SUCCESS);
    }
    else if (MMI_OPP_CTX(opc_state) != MMI_OPC_IDLE)
    {    
        mmi_opp_opc_connection_terminated(MMI_OPP_ERR_DISCONNECT);
    }
    DeleteScreenIfPresent(SCR_OPP_SENDING);
    DeleteScreenIfPresent(SCR_OPP_ABORTING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_entry_opp_device_discovery
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_opp_entry_opp_device_discovery(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_BT_MTK_SUPPORT__)
    mmi_bt_entry_obex_device_select_screen();
#endif

}

#endif /* __MMI_OPP_SUPPORT__ */ 


#if defined __MMI_OPP_SUPPORT__ || defined __MMI_BIP_SUPPORT__
U8 mmi_bt_get_recv_files_cnt(void)
{
    U8 recv_file_cnt = 0;

#ifdef __MMI_OPP_SUPPORT__    
    recv_file_cnt = mmi_opp_get_recv_files_cnt();
#endif

#ifdef __MMI_BIP_SUPPORT__    
    recv_file_cnt += mmi_bt_bip_get_recv_images_cnt();
#endif

    return recv_file_cnt;
}


void mmi_bt_entry_idle_notify_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 cnt[8];
    U8 num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get received file count */
#ifdef __MMI_OPP_SUPPORT__    
    num = mmi_opp_get_recv_files_cnt();
#endif

#ifdef __MMI_BIP_SUPPORT__    
    num += mmi_bt_bip_get_recv_images_cnt();
#endif

    if (num == 0)
    {
        EntryIdleScreen();
        return;
    }

    /* build notify string */    
    kal_wstrcpy( (U16 *)mmi_opp_idle_notify_str, (U16 *)GetString(STR_OPP_NOTY_RECV_FILE_HED) ); 
    kal_wsprintf( (U16 *)cnt, " %d ", num );                            
    kal_wstrcat( (U16 *)mmi_opp_idle_notify_str,  (U16*) cnt);                                   
    if ( num == 1)         
    {                       
        kal_wstrcat( (U16 *)mmi_opp_idle_notify_str,  (U16*) GetString(STR_OPP_NOTY_RECV_FILE_TIL)); 
    }         
    else     
    {          
        kal_wstrcat( (U16 *)mmi_opp_idle_notify_str,  (U16*) GetString(STR_OPP_NOTY_RECV_MULTI_FILE_TIL)); 
    }     
    
    EntryNewScreen(SCR_OPP_NOTY_FILE_RECV, NULL, NULL, NULL);

    if (g_keylock_context.gKeyPadLockFlag == 0)
    {
        ShowCategory154Screen(
            0,
            0,
            STR_OPP_NOTY_RECV_FILE_BROWSE,
            0,
            STR_GLOBAL_BACK,
            0,
            (U8*) mmi_opp_idle_notify_str,
            NULL,
            IMG_GLOBAL_INFO,
            NULL);

        SetLeftSoftkeyFunction(mmi_opp_notify_scr_browse, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_opp_notify_scr_goback_func, KEY_EVENT_UP);
        SetKeyHandler(mmi_opp_notify_scr_endkey_func, KEY_END, KEY_EVENT_DOWN);
    }
    else
    {
        ShowCategory154Screen(
            0,
            0,
            g_keylock_context.KeyLockLSKStringID,
            g_keylock_context.KeyLockLSKIconID,
            g_keylock_context.KeyLockRSKStringID,
            g_keylock_context.KeyLockRSKIconID,
            (U8*) mmi_opp_idle_notify_str,
            NULL,
            IMG_GLOBAL_INFO,
            NULL);
    }
}

#endif

