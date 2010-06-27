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
 *  MobileTVPlayer.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Mobile TV Player Applications v0.1
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "MMI_include.h"

#if defined(__MMI_MOBILE_TV_PLAYER__)

#include "SettingDefs.h"        /* ST_NOTIFYDURATION define */
#include "SettingProfile.h"
#include "gui.h"                /* Gui functions */
#include "FileManagerGprot.h"
#include "ScreenRotationGprot.h"
#include "CommonScreens.h" 
#include "FileManagerGProt.h"   /* file path / file error */
#include "FileManagerDef.h"     /* for ImageViewer's Screen ID - SCR_FMGR_EXPLORER */
#include "FileMgr.h"
#include "mmiapi_enum.h"                /* Stop LED */
#include "AlarmFrameworkProt.h"
#include "CallManagementGprot.h"
#include "gpioInc.h"


#if defined(__MMI_MTV_A2DP_SUPPORT__)
#include "SimDetectionGprot.h"
#include "BTMMIScrGprots.h"
#include "av_bt.h"
#include "app_str.h"
#include "AudioPlayerProt.h"
#endif /* __MMI_MTV_A2DP_SUPPORT__ */

#if defined(__MMI_MTV_AVRCP_SUPPORT__)
#if defined(__MMI_BT_BCHS_SUPPORT__
#include "BCHSMMIAVRCPGProt.h"
#elif defined(__MMI_BT_MTK_SUPPORT__)
#include "BTMMICM.h"
#include "BTMMIAVRCPGProt.h"
#endif 
#endif /* __MMI_MTV_AVRCP_SUPPORT__ */ 

#ifdef __MMI_TOUCH_SCREEN__
#include "wgui_touch_screen.h"
#endif /* __MMI_TOUCH_SCREEN__ */


#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "mdi_mtv.h"


#include "MobileTVPlayerEnum.h"
#include "MobileTVPlayerResDef.h"
#include "MobileTVPlayerGprot.h"
#include "MobileTVPlayer.h"

#include "MMI_media_app_trc.h"
/* removable */
#include "MainMenuDef.h"        /* Multimedia icon */

#if defined(__MMI_MTV_A2DP_SUPPORT__)
extern mmi_bt_dev_struct *mmi_audply_get_bt_headset(void); /* tmp use audio player's */
#endif


static mmi_mtv_player_context_struct g_mmi_mtv_player_cntx;
mmi_mtv_player_context_struct *mtv_player_p = &g_mmi_mtv_player_cntx;
static mtv_player_menu_context_struct g_mmi_mtv_player_setting_cntx;
mtv_player_menu_context_struct *mtv_player_setting_p = &g_mmi_mtv_player_setting_cntx;


static mtv_player_layout_struct g_mtv_player_osd_cntx =
{
    {TRUE,  0,   50, 240,  27},    /* title */
    {TRUE,   0, 110, 240,  70},    /* hint */
    {TRUE, 123, 265,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* channel number */
    {TRUE, 188, 228,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* volume */

    {TRUE, 102, 296,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* play */
    {TRUE, 184, 260,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* record */
    {TRUE,  48, 260,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* play_speed */
    {TRUE,  19, 260,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* fullscreen */
    {TRUE, 136, 230,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* forward */
    {TRUE,  12, 230,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* rewind */
    {TRUE, 214, 230,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_inc */
    {TRUE, 169, 230,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_dec */
    {TRUE, 141, 259,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_next */
    {TRUE,  93, 259,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_prev */

    {TRUE,   0,   0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* ts_ind */
    {TRUE,   0,   0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* ts_bar */

};

#define TIMESHIFT_BAR_OFFSET_X 33
#define TIMESHIFT_BAR_OFFSET_Y 233
#define TIMESHIFT_BAR_OFFSET_X_ROTATED 54
#define TIMESHIFT_BAR_OFFSET_Y_ROTATED 199

static mtv_player_layout_struct g_mtv_player_osd_cntx_270 =
{
    {TRUE,  0,   0, 290,  27},   /* title */
    {TRUE,  80,  50, 160, 140},   /* hint */
    {TRUE,  99, 215,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* channel number */
    {TRUE, 179, 199,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* volume */
    
    {TRUE, 135, 215,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* play */
    {TRUE,  40, 215,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* record */
    {TRUE,   9, 215,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* play_speed */
    {TRUE,   9, 196,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* fullscreen */
    {TRUE, 157, 196,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* forward */
    {TRUE,  36, 196,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* rewind */
    {TRUE, 196, 199,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_inc */
    {TRUE, 196, 216,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* vol_dec */
    {TRUE, 113, 215,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_next */
    {TRUE,  73, 215,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* channel_prev */

    {TRUE,   0,   0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* ts_ind */
    {TRUE,   0,   0,   0,   0, MTV_PLAYER_ICON_STATUS_ENABLE},    /* ts_bar */

};


#define MTV_ENTER_STATE(a,_MOD_,_NEXT_STATE_)\
        do{\
            mtv_player_p->##a##_next_state=_NEXT_STATE_;\
            mmi_mtv_player_exit_current_state(_MOD_);\
            mmi_mtv_player_enter_state(_MOD_);\
        }while(0)\

#define KERNEL_STATE_IN(_STATE_) (mtv_player_p->kernel_state==_STATE_)
#define PLAYER_STATE_IN(_STATE_) (mtv_player_p->player_state==_STATE_)
#define RECORDER_STATE_IN(_STATE_) (mtv_player_p->recorder_state==_STATE_)

/***************************************************************************** 
* External Functions Implementation
*****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_usb_mode_hdlr
 * DESCRIPTION
 *  usb mode handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_player_usb_mode_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mtv_player_p->is_saving)
    {
        //mdi_mtv_player_rec_stop_save();
        mtv_player_p->is_saving = FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_init_app
 * DESCRIPTION
 *  Mobile TV Player init function, 
 *  which is called when MMI Task is initializing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_player_init_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_mtv_player_init_highlight_hdlr();

    applib_mem_ap_register(APPLIB_MEM_AP_ID_MTV_PLAYER,STR_ID_MOBILE_TV_PLAYER_APP_NAME 
                ,IMG_ID_MOBILE_TV_PLAYER_APP_ICON ,mmi_mtv_player_app_mem_stop_callback);

    mtv_player_p->storage_status = MTV_PLAYER_STORAGE_MOUNTED;  

    mtv_player_p->ui_rotate = MMI_FRM_SCREEN_ROTATE_0;
    mtv_player_p->active_osd_cntx_p = &g_mtv_player_osd_cntx;

    mmi_mtv_player_reset_all_state();

    mtv_player_p->is_initializing = FALSE;
    mtv_player_p->is_discarding_file = FALSE;
    mtv_player_p->is_updating_channel_list = FALSE;
    mtv_player_p->is_recorder_error = FALSE;
    
    mmi_mtv_player_init_icon_info();


    /* init banding str */
    for (i = 0; i < MMI_MOBILE_TV_PLAYER_BAND_TOTAL_COUNT; i++)
    {
        mtv_player_setting_p->band_str[i] =
            (UI_string_type) GetString((U16) (STR_ID_MOBILE_TV_PLAYER_BAND_START+ i + 1));
    }

    /* temp setting */
    mtv_player_p->setting.max_timeshift_delay = 100;
    mtv_player_p->setting.num_services = 0;
    mtv_player_p->signal_strength = 0;
}


/***************************************************************************** 
* Static Functions Implementation
*****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_reset_all_state
 * DESCRIPTION
 *  reset all modules' states.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_reset_all_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->kernel_prev_state = MTV_KERNEL_CLOSED;
    mtv_player_p->kernel_state = MTV_KERNEL_CLOSED;
    mtv_player_p->kernel_next_state = MTV_KERNEL_CLOSED;

    mtv_player_p->player_prev_state = MTV_PLAYER_STOPPED;
    mtv_player_p->player_state = MTV_PLAYER_STOPPED;
    mtv_player_p->player_next_state = MTV_PLAYER_STOPPED;    

    mtv_player_p->recorder_prev_state = MTV_RECORDER_STOPPED;
    mtv_player_p->recorder_state = MTV_RECORDER_STOPPED;
    mtv_player_p->recorder_next_state = MTV_RECORDER_STOPPED;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_entry_option_menu_screen
 * DESCRIPTION
 *  mobile tv player option menu screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_entry_option_menu_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[16];
    U16 ItemIcons[16];
    U16 nItems;
    U8 *guiBuffer;
    U8 *PopUpList[32];
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MOBILE_TV_PLAYER_OPTION_MENU, NULL, mmi_mtv_player_entry_option_menu_screen, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_MOBILE_TV_PLAYER_OPTION_MENU);

    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
    }

    /* restore correct avatar id */
    nItems = GetNumOfChild_Ext(MENU_ID_MOBILE_TV_PLAYER_OPTION);
    GetSequenceStringIds_Ext(MENU_ID_MOBILE_TV_PLAYER_OPTION, ItemList);
    GetSequenceImageIds_Ext(MENU_ID_MOBILE_TV_PLAYER_OPTION, ItemIcons);
    SetParentHandler(MENU_ID_MOBILE_TV_PLAYER_OPTION);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (i = 0; i < nItems; i++)
    {
        PopUpList[i] = NULL;
    }

    ConstructHintsList(MENU_ID_MOBILE_TV_PLAYER_OPTION, PopUpList);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        IMG_ID_MOBILE_TV_PLAYER_APP_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        ItemList,
        (PU16) gIndexIconsImageList,
        (U8 **) PopUpList,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_pre_highlight_handler
 * DESCRIPTION
 *  channel list pre-highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_pre_highlight_handler(void)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* when first time enter category265, do not execute pre_highlight_handler */
    if(mtv_player_p->is_before_cat265 == TRUE)
        return;
    
    /* when changing channel, we stop service here */
    if (KERNEL_STATE_IN(MTV_KERNEL_READY) 
        && !RECORDER_STATE_IN(MTV_RECORDER_RECORD))
    {
        if (PLAYER_STATE_IN(MTV_PLAYER_PLAY)||PLAYER_STATE_IN(MTV_PLAYER_BT_CONNECT))
            MTV_ENTER_STATE(player,MMI_MTV_PLAYER,MTV_PLAYER_STOPPED);    

        MTV_ENTER_STATE(kernel,MMI_MTV_KERNEL, MTV_KERNEL_OPENED); 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_redraw_preview
 * DESCRIPTION
 *  channel list callback for redraw preview screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_redraw_preview(gdi_handle preview_handle, U32 blt_layer_flag, U32 preview_layer_flag, S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(preview_handle);
    gdi_draw_solid_rect(0, 0, width-1, height-1, GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();
    gdi_layer_blt_previous(x, y, x+width-1, y+height-1);

    if (KERNEL_STATE_IN(MTV_KERNEL_SCANNING))
    {
        /* for first time enter channel list screen */
        MTV_ENTER_STATE(kernel,MMI_MTV_KERNEL,MTV_KERNEL_OPENED);    
    }
    else if (KERNEL_STATE_IN(MTV_KERNEL_OPENED))
    {
        /* when changing channel, we start a new service here */
        MTV_ENTER_STATE(kernel,MMI_MTV_KERNEL, MTV_KERNEL_INIT);
    }
    else if (KERNEL_STATE_IN(MTV_KERNEL_READY) 
             && !RECORDER_STATE_IN(MTV_RECORDER_RECORD)
             && PLAYER_STATE_IN(MTV_PLAYER_STOPPED))
    {
    #if defined(__MMI_MTV_A2DP_SUPPORT__)
        MTV_ENTER_STATE(player,MMI_MTV_PLAYER,MTV_PLAYER_BT_CONNECT);
    #else
        MTV_ENTER_STATE(player,MMI_MTV_PLAYER,MTV_PLAYER_PLAY);
    #endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_cat265_get_async_items
 * DESCRIPTION
 *  ?
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_mtv_player_cat265_get_async_items(S32 start_indx, gui_iconlist_menu_item *menuData, S32 num_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* fill data */
    for (i = 0; i < num_item; ++i)
    {
        S8 buffer[8];
        S8 UCS2_buffer[16];

        sprintf((PS8) buffer, "CH%2d", i+1);
        mmi_asc_to_ucs2((PS8) UCS2_buffer, (PS8) buffer);


        /* subject */
        mmi_ucs2ncpy((S8*) menuData[i].item_list[0], (S8*) &UCS2_buffer[0], 10);
        mmi_ucs2cpy((S8*) menuData[i].item_list[1], (S8*) mtv_player_p->service_names[(start_indx+i)]);

        /* status icon */
        menuData[i].image_list[0] = (PU8) GetImage(GetRootTitleIcon(ORGANIZER_ALARM_MENU));
    }
    return num_item;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_highlight_channel_hdlr
 * DESCRIPTION
 *  high light handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_highlight_channel_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat265_set_title((U8*)mtv_player_p->service_names[index]);
    mtv_player_p->selected_channel = (U8)index;

    // tmp
    ClearKeyEvents();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_select_channel_to_play
 * DESCRIPTION
 *  mobile tv player channel list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_select_channel_to_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->setting.selected_channel = mtv_player_p->selected_channel;

    if (PLAYER_STATE_IN(MTV_PLAYER_PLAY)||PLAYER_STATE_IN(MTV_PLAYER_BT_CONNECT))
        MTV_ENTER_STATE(player,MMI_MTV_PLAYER,MTV_PLAYER_STOPPED);
    

    if (mtv_player_p->setting.is_channel_seleted == FALSE)
    {
        mtv_player_p->setting.is_channel_seleted = TRUE;
        mmi_mtv_player_store_setting();
    }


    if (IsScreenPresent(SCR_ID_MOBILE_TV_PLAYER_APP))
	{
        DeleteScreenIfPresent(SCR_ID_MOBILE_TV_PLAYER_CHANNEL_LIST);
        DeleteScreenIfPresent(SCR_ID_MOBILE_TV_PLAYER_OPTION_MENU);
        DeleteScreenIfPresent(SCR_ID_MOBILE_TV_PLAYER_CHANNEL_LIST_OPTION);
        GoBackHistory();
    }
    else
    {
        mmi_mtv_player_entry_app_screen();

        DeleteScreenIfPresent(SCR_ID_MOBILE_TV_PLAYER_CHANNEL_LIST);
        DeleteScreenIfPresent(SCR_ID_MOBILE_TV_PLAYER_OPTION_MENU);
        DeleteScreenIfPresent(SCR_ID_MOBILE_TV_PLAYER_CHANNEL_LIST_OPTION);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_cancel_select_channel
 * DESCRIPTION
 *  back from mobile tv player channel list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_cancel_select_channel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!PLAYER_STATE_IN(MTV_PLAYER_STOPPED))
        MTV_ENTER_STATE(player,MMI_MTV_PLAYER,MTV_PLAYER_STOPPED);

    /* handle if first time enter channel list screen */
    if (!IsScreenPresent(SCR_ID_MOBILE_TV_PLAYER_OPTION_MENU))
    {
        if (!RECORDER_STATE_IN(MTV_RECORDER_RECORD))
        {
            MTV_ENTER_STATE(kernel,MMI_MTV_KERNEL,MTV_KERNEL_CLOSED);
        }
    }

    if (mtv_player_p->selected_channel != mtv_player_p->setting.selected_channel)
    {
        if (KERNEL_STATE_IN(MTV_KERNEL_READY))
            MTV_ENTER_STATE(kernel,MMI_MTV_KERNEL, MTV_KERNEL_OPENED);        
    }
    GoBackHistory();
}



/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_exit_channel_list_screen
 * DESCRIPTION
 *  mobile tv player channel list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_exit_channel_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PLAYER_STATE_IN(MTV_PLAYER_PLAY)||PLAYER_STATE_IN(MTV_PLAYER_BT_CONNECT))
        MTV_ENTER_STATE(player,MMI_MTV_PLAYER,MTV_PLAYER_STOPPED);

    mmi_mtv_player_store_setting();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_entry_cl_option_screen
 * DESCRIPTION
 *  mobile tv player channel list option menu screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_entry_cl_option_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[16];
    U16 ItemIcons[16];
    U16 nItems;
    U8 *guiBuffer;
    U8 *PopUpList[32];
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MOBILE_TV_PLAYER_CHANNEL_LIST_OPTION, mmi_mtv_player_exit_cl_option_screen, mmi_mtv_player_entry_cl_option_screen, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MOBILE_TV_PLAYER_CHANNEL_LIST_OPTION);

    /* restore correct avatar id */
    nItems = GetNumOfChild_Ext(MENU_ID_MOBILE_TV_PLAYER_CL_OPTION);
    GetSequenceStringIds_Ext(MENU_ID_MOBILE_TV_PLAYER_CL_OPTION, ItemList);
    GetSequenceImageIds_Ext(MENU_ID_MOBILE_TV_PLAYER_CL_OPTION, ItemIcons);
    SetParentHandler(MENU_ID_MOBILE_TV_PLAYER_CL_OPTION);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (i = 0; i < nItems; i++)
    {
        PopUpList[i] = NULL;
    }

    ConstructHintsList(MENU_ID_MOBILE_TV_PLAYER_CL_OPTION, PopUpList);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        IMG_ID_MOBILE_TV_PLAYER_APP_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        ItemList,
        (PU16) gIndexIconsImageList,
        (U8 **) PopUpList,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_exit_cl_option_screen
 * DESCRIPTION
 *  mobile tv player exit channel list option menu screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_exit_cl_option_screen(void)
{

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_entry_channel_list_screen
 * DESCRIPTION
 *  mobile tv player channel list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_entry_channel_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 lsk_str,lsk_img;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MOBILE_TV_PLAYER_CHANNEL_LIST, mmi_mtv_player_exit_channel_list_screen, mmi_mtv_player_entry_channel_list_screen, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_MOBILE_TV_PLAYER_CHANNEL_LIST);
    ClearInputEventHandler(MMI_DEVICE_KEY);

    RegisterHighlightHandler(mmi_mtv_player_highlight_channel_hdlr); // set title

    if (RECORDER_STATE_IN(MTV_RECORDER_RECORD))
    {
        lsk_str = 0;
        lsk_img = 0;
    }
    else
    {
        lsk_str = STR_GLOBAL_OPTIONS;
        lsk_img = IMG_GLOBAL_OPTIONS;
    }

    /* backup current selected channel when first in */
    if (guiBuffer == NULL)
    {
        mtv_player_p->selected_channel = mtv_player_p->setting.selected_channel;
    }

    /* it is used for pre_highlight_handler to check if it is changing channel or not */
    mtv_player_p->is_before_cat265 = TRUE;

    ShowCategory265Screen(
        NULL,
        lsk_str,
        lsk_img,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mtv_player_p->setting.num_services,
        mmi_mtv_player_cat265_get_async_items, 
        NULL,
        mmi_mtv_player_pre_highlight_handler, // stop last preview
        mmi_mtv_player_redraw_preview, // start current preview
        mtv_player_p->setting.selected_channel,
        guiBuffer);

    mtv_player_p->is_before_cat265 = FALSE;

    //SetLeftSoftkeyFunction(mmi_mtv_player_select_channel_to_play, KEY_EVENT_UP);
    if (!RECORDER_STATE_IN(MTV_RECORDER_RECORD))
    {
        SetLeftSoftkeyFunction(mmi_mtv_player_entry_cl_option_screen, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_mtv_player_cancel_select_channel, KEY_EVENT_UP);
        SetKeyHandler(mmi_mtv_player_cancel_select_channel, KEY_LEFT_ARROW, KEY_EVENT_DOWN); 
        SetKeyHandler(mmi_mtv_player_select_channel_to_play, KEY_ENTER, KEY_EVENT_DOWN); 
    }
    else
    {
        SetLeftSoftkeyFunction(mmi_mtv_player_dummy, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_mtv_player_cancel_select_channel, KEY_EVENT_UP);
        SetKeyHandler(mmi_mtv_player_cancel_select_channel, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }
    //if (!RECORDER_STATE_IN(MTV_RECORDER_RECORD))
    //SetKeyHandler(mmi_mtv_player_select_channel_to_play, KEY_ENTER, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_option_setting_set_value
 * DESCRIPTION
 *  set MTV PLAYER setting values
 * PARAMETERS
 *  void
 *  idx(?)
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_option_setting_set_value(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mtv_player_p->setting.brightness = mtv_player_setting_p->brightness_selected;
    mtv_player_p->setting.contrast = mtv_player_setting_p->contrast_selected;
    mmi_mtv_player_store_setting();
    mmi_mtv_player_display_done_popup();
    DeleteNHistory(1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_option_setting_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for MTV PLAYER setting menu
 * PARAMETERS
 *  index       [IN]        Highlighted item index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_option_setting_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetCategory57LeftSoftkeyFunction(mmi_mtv_player_option_setting_set_value);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_exit_settings_screen
 * DESCRIPTION
 *  exit function of mobile tv player settings screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_exit_settings_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    currHistory.scrnID = SCR_ID_MOBILE_TV_PLAYER_OPTION_MENU_SETTING;
    currHistory.entryFuncPtr = mmi_mtv_player_entry_settings_screen;
    GetCategoryHistory(currHistory.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) currHistory.inputBuffer);
    AddNHistory(currHistory, inputBufferSize);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_entry_settings_screen
 * DESCRIPTION
 *  mobile tv player settings screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_entry_settings_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;
    S32 item_offset = 0;
    S32 i;
    
    MMI_ID_TYPE item_icons[MTV_PLAYER_SETTING_ITEM_COUNT * 2] =
    {
        IMG_GLOBAL_L1,
        0,
        IMG_GLOBAL_L2,
        0,
    };
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(
        SCR_ID_MOBILE_TV_PLAYER_OPTION_MENU_SETTING,
        mmi_mtv_player_exit_settings_screen,
        NULL,
        NULL);

    InitializeCategory57Screen();

    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
    }

    InitializeCategory57Screen();

    mtv_player_setting_p->brightness_selected = mtv_player_p->setting.brightness;
    mtv_player_setting_p->contrast_selected= mtv_player_p->setting.contrast;

    /* brightness */
    for (i = 0; i < MMI_MOBILE_TV_PLAYER_BRIGHTNESS_ADJ_LEVEL_COUNT; i++)
    {
        mtv_player_setting_p->brightness_str[i] =
            (UI_string_type) GetString((U16) (STR_ID_MOBILE_TV_PLAYER_ADJUST_START + i + 1));
    }

    /* contrast */
    for (i = 0; i < MMI_MOBILE_TV_PLAYER_CONTRAST_ADJ_LEVEL_COUNT; i++)
    {
        mtv_player_setting_p->contrast_str[i] =
            (UI_string_type) GetString((U16) (STR_ID_MOBILE_TV_PLAYER_ADJUST_START + i + 1));
    }

   /******************************************************************
   *  MACRO to create inline selection. 
   ******************************************************************/
#define MTV_PLAYER_SETTING_INLINE_SELECT(a, A)\
   {\
      SetInlineItemCaption(&wgui_inline_items[item_offset++],\
                            (PU8)GetString((U16)(STR_ID_MOBILE_TV_PLAYER_SETTING_##A)));\
      SetInlineItemActivation(&wgui_inline_items[item_offset],\
                              INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,\
                              0 );\
      SetInlineItemSelect( &wgui_inline_items[item_offset++],\
                           MMI_MOBILE_TV_PLAYER_##A##_ADJ_LEVEL_COUNT,\
                           (U8**)mtv_player_setting_p->##a##_str,\
                           &mtv_player_setting_p->##a##_selected);\
   }

   /****************************************************************************
   *  Create inline selection                                                               
   *****************************************************************************/
    MTV_PLAYER_SETTING_INLINE_SELECT(brightness, BRIGHTNESS);
    MTV_PLAYER_SETTING_INLINE_SELECT(contrast, CONTRAST);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_MOBILE_TV_PLAYER_OPTION_MENU_SETTING);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_MOBILE_TV_PLAYER_OPTION_MENU_SETTING, &inputBufferSize);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, MTV_PLAYER_SETTING_ITEM_COUNT * 2, inputBuffer);
    }

    RegisterHighlightHandler(mmi_mtv_player_option_setting_highlight_hdlr);

    /* show category */
    ShowCategory57Screen(
        STR_GLOBAL_OPTIONS,
        MAIN_MENU_TITLE_MULTIMEDIA_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        item_offset,
        item_icons,
        wgui_inline_items,
        0,
        guiBuffer);

    /* set key hdlr */
    SetCategory57LeftSoftkeyFunction(mmi_mtv_player_option_setting_set_value);
    DisableCategory57ScreenDone();
    SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_set_storage_value
 * DESCRIPTION
 *  set storage value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_player_set_storage_value(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 drv_letter;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmgr_get_drive_letter_by_inline_index((U8)mtv_player_setting_p->storage_selected, (S8*)&drv_letter);
    mmi_mtv_player_set_storage_callback(drv_letter);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_check_and_restore_valid_drv
 * DESCRIPTION
 *  Check if desired path is ready or not. If not, will restore to valid path.
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
static BOOL mmi_mtv_player_check_and_restore_valid_drv(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (FS_NO_ERROR == FS_GetDevStatus(mtv_player_p->setting.storage,FS_MOUNT_STATE_ENUM))
    {
        return TRUE;
    }
    else
    {
        mtv_player_p->setting.storage = (U16) MMI_PUBLIC_DRV;
        if (FS_NO_ERROR == FS_GetDevStatus(mtv_player_p->setting.storage,FS_MOUNT_STATE_ENUM))
        {
            //mtv_player_p->is_storage_path_changed = TRUE;
            mmi_mtv_player_store_setting();
            return TRUE;
        }
        else
        {
        #ifdef __USB_IN_NORMAL_MODE__
            if (mmi_usb_is_in_mass_storage_mode())
            {            
                /* user driver is mass storage mode */
                return FALSE;
            }
            else
            {
                MMI_ASSERT(0);
            }
        #else /* __USB_IN_NORMAL_MODE__ */
            MMI_ASSERT(0);
        #endif /* __USB_IN_NORMAL_MODE__ */
        }
        return TRUE;
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_highlight_storage_hdlr
 * DESCRIPTION
 *  mobile tv player storage menu hilight handler 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_highlight_storage_hdlr(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_setting_p->storage_selected = idx;
    SetLeftSoftkeyFunction(mmi_mtv_player_set_storage_value, KEY_EVENT_UP);
    SetKeyHandler(mmi_mtv_player_set_storage_value, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_entry_storage_screen
 * DESCRIPTION
 *  mobile tv player storage setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_entry_storage_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 icon_list[FMGR_TOTAL_STORAGE];
    PU8 pop_ptr_list[FMGR_TOTAL_STORAGE];
    U8 *guiBuffer;
    U8 storage_total_num;
    U32 *drv_inline_list_p;
    U8 highlight_idx;
    S32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MOBILE_TV_PLAYER_STORAGE, NULL, mmi_mtv_player_entry_storage_screen, NULL);

    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
    }

    guiBuffer = GetCurrGuiBuffer(SCR_ID_MOBILE_TV_PLAYER_STORAGE);

    mmi_fmgr_get_exist_storage_inline_list(
        (S8)mtv_player_p->setting.storage,
        &storage_total_num,
        (PU32)&drv_inline_list_p,
        &highlight_idx);

    RegisterHighlightHandler(mmi_mtv_player_highlight_storage_hdlr);

    for (i = 0; i < storage_total_num; i++)
    {
        icon_list[i] = (U16) (IMG_GLOBAL_L1 + i);
    }

    for (i = 0; i < storage_total_num; i++)
    {
        pop_ptr_list[i] = NULL;
    }

    ShowCategory353Screen(
        (U8*) GetString(STR_ID_MOBILE_TV_PLAYER_STORAGE),
        MAIN_MENU_TITLE_MULTIMEDIA_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        storage_total_num,
        (PU8*)drv_inline_list_p,
        icon_list,
        pop_ptr_list,
        0,
        (S32)highlight_idx,
        guiBuffer);

    SetRightSoftkeyFunction(mmi_mtv_player_exit_select_storage_screen_without_selecting, KEY_EVENT_UP);
    SetKeyHandler(mmi_mtv_player_exit_select_storage_screen_without_selecting, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    SetLeftSoftkeyFunction(mmi_mtv_player_set_storage_value, KEY_EVENT_UP);
    SetKeyHandler(mmi_mtv_player_set_storage_value, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_exit_select_storage_screen_without_selecting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_exit_select_storage_screen_without_selecting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    /***************************************************
     * for new storage error handling machenism 
     ***************************************************/
    if (IsScreenPresent(SCR_ID_MOBILE_TV_PLAYER_OPTION_MENU)==MMI_FALSE)
    {
        DeleteScreenIfPresent(SCR_ID_MOBILE_TV_PLAYER_APP);
        mtv_player_p->storage_status = MTV_PLAYER_STORAGE_NEED_TO_MOUNT;
    }

    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_update_channel_list
 * DESCRIPTION
 *  command: update channel list from channel list 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_update_channel_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->is_updating_channel_list = TRUE;
    mmi_mtv_player_entry_init_channel_list_screen();  
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_highlight_cl
 * DESCRIPTION
 *  mobile tv player menu item highlight handler for channel list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_highlight_cl(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_mtv_player_entry_channel_list_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_mtv_player_entry_channel_list_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_highlight_settings
 * DESCRIPTION
 *  mobile tv player menu item highlight handler for settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_highlight_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_mtv_player_entry_settings_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_mtv_player_entry_settings_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_highlight_storage
 * DESCRIPTION
 *  mobile tv player menu item highlight handler for storage
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_highlight_storage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_mtv_player_entry_storage_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_mtv_player_entry_storage_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_highlight_band
 * DESCRIPTION
 *  mobile tv player menu item highlight handler for band
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_highlight_band(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_mtv_player_entry_band_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_mtv_player_entry_band_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_highlight_play
 * DESCRIPTION
 *  mobile tv player menu item highlight handler for play item in cl
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_highlight_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_mtv_player_select_channel_to_play, KEY_EVENT_UP);
    SetKeyHandler(mmi_mtv_player_select_channel_to_play, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_highlight_update_list
 * DESCRIPTION
 *  mobile tv player menu item highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_highlight_update_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_mtv_player_update_channel_list, KEY_EVENT_UP);
    SetKeyHandler(mmi_mtv_player_update_channel_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_highlight_app
 * DESCRIPTION
 *  mobile tv player menu item highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_highlight_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_mtv_player_entry_app_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_mtv_player_entry_app_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_dummy
 * DESCRIPTION
 *  dummy function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_dummy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_register_key_hdlr
 * DESCRIPTION
 *  register key event hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_register_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_KEY);
    ClearKeyEvents();

    SetKeyHandler(mmi_mtv_player_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_mtv_player_rsk_release, KEY_RSK, KEY_EVENT_UP);

    SetKeyHandler(mmi_mtv_player_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_mtv_player_lsk_release, KEY_LSK, KEY_EVENT_UP);

    SetKeyHandler(mmi_mtv_player_play_icon_press, KEY_ENTER, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_mtv_player_play_icon_release, KEY_ENTER, KEY_EVENT_UP);       

    SetKeyHandler(mmi_mtv_player_record_icon_press, KEY_CAMERA, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_mtv_player_record_icon_release, KEY_CAMERA, KEY_EVENT_UP);   
    SetKeyHandler(mmi_mtv_player_fullscreen_icon_press, KEY_STAR, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_mtv_player_fullscreen_icon_release, KEY_STAR, KEY_EVENT_UP);
    //TMP
    //SetKeyHandler(mmi_mtv_player_play_speed_icon_press, KEY_POUND, KEY_EVENT_DOWN);
    //SetKeyHandler(mmi_mtv_player_play_speed_icon_release, KEY_POUND, KEY_EVENT_UP);
    SetKeyHandler(mmi_mtv_player_play_icon_press, KEY_POUND, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_mtv_player_play_icon_release, KEY_POUND, KEY_EVENT_UP);
    SetKeyHandler(mmi_mtv_player_dummy, KEY_POUND, KEY_EVENT_LONG_PRESS);
    SetKeyHandler(mmi_mtv_player_dummy, KEY_POUND, KEY_EVENT_REPEAT);

    SetKeyHandler(mmi_mtv_player_vol_inc_icon_press, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_mtv_player_vol_inc_icon_release, KEY_VOL_UP, KEY_EVENT_UP);
    SetKeyHandler(mmi_mtv_player_vol_dec_icon_press, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_mtv_player_vol_dec_icon_release, KEY_VOL_DOWN, KEY_EVENT_UP);

    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        SetKeyHandler(mmi_mtv_player_rewind_icon_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_mtv_player_rewind_icon_release, KEY_UP_ARROW, KEY_EVENT_UP);   
        SetKeyHandler(mmi_mtv_player_forward_icon_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_mtv_player_forward_icon_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
        SetKeyHandler(mmi_mtv_player_channel_next_icon_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_mtv_player_channel_next_icon_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
        SetKeyHandler(mmi_mtv_player_channel_prev_icon_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_mtv_player_channel_prev_icon_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
    }
    else
    {
        SetKeyHandler(mmi_mtv_player_channel_next_icon_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_mtv_player_channel_next_icon_release, KEY_UP_ARROW, KEY_EVENT_UP);   
        SetKeyHandler(mmi_mtv_player_channel_prev_icon_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_mtv_player_channel_prev_icon_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
        SetKeyHandler(mmi_mtv_player_forward_icon_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_mtv_player_forward_icon_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
        SetKeyHandler(mmi_mtv_player_rewind_icon_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_mtv_player_rewind_icon_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
    }

    SetKeyHandler(mmi_mtv_player_key_1_press,KEY_1,KEY_EVENT_DOWN);
    SetKeyHandler(mmi_mtv_player_key_2_press,KEY_2,KEY_EVENT_DOWN);
    SetKeyHandler(mmi_mtv_player_key_3_press,KEY_3,KEY_EVENT_DOWN);
    SetKeyHandler(mmi_mtv_player_key_4_press,KEY_4,KEY_EVENT_DOWN);
    SetKeyHandler(mmi_mtv_player_key_5_press,KEY_5,KEY_EVENT_DOWN);
    SetKeyHandler(mmi_mtv_player_key_6_press,KEY_6,KEY_EVENT_DOWN);
    SetKeyHandler(mmi_mtv_player_key_7_press,KEY_7,KEY_EVENT_DOWN);
    SetKeyHandler(mmi_mtv_player_key_8_press,KEY_8,KEY_EVENT_DOWN);
    SetKeyHandler(mmi_mtv_player_key_9_press,KEY_9,KEY_EVENT_DOWN);
    SetKeyHandler(mmi_mtv_player_key_0_press,KEY_0,KEY_EVENT_DOWN);

    /* register AVRCP */
#ifdef __MMI_MTV_AVRCP_SUPPORT__
    PRINT_INFORMATION("mobile tv player set avrcp cmd hdlr\n");
    mmi_bt_avrcp_set_cmd_hdlr(mmi_mtv_player_bt_avrcp_cmd_hdlr);
#endif 


        
#ifdef __MMI_TOUCH_SCREEN__
    /* register pen down/up/move event */
    wgui_register_pen_down_handler(mmi_mtv_player_pen_down_hdlr);
    wgui_register_pen_up_handler(mmi_mtv_player_pen_up_hdlr);
    wgui_register_pen_move_handler(mmi_mtv_player_pen_move_hdlr);
#endif /* __MMI_TOUCH_SCREEN__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_exit_init_channel_list_screen
 * DESCRIPTION
 *  for first time init channel list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_exit_init_channel_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* resume background play */
    mdi_audio_resume_background_play();
}


static void mmi_mtv_player_stop_init_cl(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mtv_player_p->is_live_scan_complete == FALSE)
    {
        mdi_mtv_abort_scan_services(mtv_player_p->mtv_handle);
    }

    mdi_mtv_close(mtv_player_p->mtv_handle);
    mtv_player_p->is_live_scanning = FALSE;
    GoBackHistory();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_entry_init_channel_list_screen
 * DESCRIPTION
 *  for first time init channel list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_entry_init_channel_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    SetDelScrnIDCallbackHandler(SCR_ID_MOBILE_TV_PLAYER_INIT_CHANNEL_LIST, mmi_mtv_player_init_cl_screen_del_hdlr);

    /* suspend background play */
    mdi_audio_suspend_background_play();

    EntryNewScreen(SCR_ID_MOBILE_TV_PLAYER_INIT_CHANNEL_LIST, mmi_mtv_player_exit_init_channel_list_screen, mmi_mtv_player_entry_init_channel_list_screen, NULL);

    ShowCategory66Screen(
        STR_ID_MOBILE_TV_PLAYER_APP_NAME,
        MAIN_MENU_TITLE_MULTIMEDIA_ICON,
        0,
        0,
        STR_GLOBAL_CANCEL,
        0,
        (PU8) GetString(STR_ID_MOBILE_TV_PLAYER_NOTIFY_INITIALIZING),
        IMG_GLOBAL_PROGRESS,
        NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_MOBILE_TV_PLAYER_INIT_CHANNEL_LIST);

    if (guiBuffer == NULL)
    {
        
        if (KERNEL_STATE_IN(MTV_KERNEL_CLOSED))
        {
            /**************************************** 
             * should be coming from entry_app_screen 
             ****************************************/
            mtv_player_p->last_error = mmi_mtv_player_open_engine();
            mtv_player_p->setting.num_services = 0;
            mtv_player_p->is_live_scanning = TRUE;
            mtv_player_p->is_live_scan_complete = FALSE;

            if (mtv_player_p->last_error == MDI_RES_MTV_SUCCEED)
            {
                MTV_ENTER_STATE(kernel,MMI_MTV_KERNEL,MTV_KERNEL_SCANNING);
            }
        }
        else if (KERNEL_STATE_IN(MTV_KERNEL_READY))
        {
            /******************************************** 
             * should be coming from update channel list 
             ********************************************/
            MTV_ENTER_STATE(player,MMI_MTV_PLAYER,MTV_PLAYER_STOPPED);
            MTV_ENTER_STATE(kernel,MMI_MTV_KERNEL,MTV_KERNEL_OPENED);

            mtv_player_p->setting.num_services = 0;
            mtv_player_p->is_live_scanning = TRUE;
            mtv_player_p->is_live_scan_complete = FALSE;

            MTV_ENTER_STATE(kernel,MMI_MTV_KERNEL,MTV_KERNEL_SCANNING);
        }
    }

    SetRightSoftkeyFunction(mmi_mtv_player_stop_init_cl, KEY_EVENT_UP);
    SetKeyHandler(mmi_mtv_player_stop_init_cl, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    /* clear end key, this action cant be abort */
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_set_band_value
 * DESCRIPTION
 *  mobile tv player set band value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_set_band_value(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->setting.band = mtv_player_p->selected_band;
    mmi_mtv_player_store_setting();
    mmi_mtv_player_display_done_popup();
    DeleteNHistory(1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_highlight_band_hdlr
 * DESCRIPTION
 *  mobile tv player band setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_player_highlight_band_hdlr(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->selected_band = idx;
    SetLeftSoftkeyFunction(mmi_mtv_player_set_band_value, KEY_EVENT_UP);
    SetKeyHandler(mmi_mtv_player_set_band_value, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_entry_band_screen
 * DESCRIPTION
 *  mobile tv player band setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_entry_band_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 selected_band;
    U16 icon_list[FMGR_TOTAL_STORAGE];
    PU8 pop_ptr_list[FMGR_TOTAL_STORAGE];
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MOBILE_TV_PLAYER_BAND, NULL, mmi_mtv_player_entry_band_screen, NULL);

    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
    }

    guiBuffer = GetCurrGuiBuffer(SCR_ID_MOBILE_TV_PLAYER_BAND);

    if (guiBuffer==NULL)
    {
        selected_band = mtv_player_p->setting.band;
    }
    else
    {
        selected_band = mtv_player_p->selected_band;
    }

    RegisterHighlightHandler(mmi_mtv_player_highlight_band_hdlr);

    for (i = 0; i < MMI_MOBILE_TV_PLAYER_BAND_TOTAL_COUNT; i++)
    {
        icon_list[i] = (U16) (IMG_GLOBAL_L1 + i);
    }

    for (i = 0; i < MMI_MOBILE_TV_PLAYER_BAND_TOTAL_COUNT; i++)
    {
        pop_ptr_list[i] = NULL;
    }

    ShowCategory353Screen(
        (U8*) GetString(STR_ID_MOBILE_TV_PLAYER_BAND),
        GetRootTitleIcon(MENU_ID_MOBILE_TV_PLAYER_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MMI_MOBILE_TV_PLAYER_BAND_TOTAL_COUNT,
        (PU8*)&(mtv_player_setting_p->band_str[0]),
        icon_list,
        pop_ptr_list,
        0,
        (S32)selected_band,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    SetLeftSoftkeyFunction(mmi_mtv_player_set_band_value, KEY_EVENT_UP);
    SetKeyHandler(mmi_mtv_player_set_band_value, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_entry_app_screen
 * DESCRIPTION
 *  mobile tv player entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_entry_app_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* allocate memory from App-Based ASM */
    if (mtv_player_p->app_mem_pool==NULL)
    {
        mtv_player_p->app_mem_pool
            = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_MTV_PLAYER, MMI_MTV_PLAYER_APP_MEM_SIZE);

        if (mtv_player_p->app_mem_pool== NULL)
        {
            mmi_frm_appmem_prompt_to_release_mem(
                APPLIB_MEM_AP_ID_MTV_PLAYER,
                IMG_ID_MOBILE_TV_PLAYER_APP_ICON,
                MMI_MTV_PLAYER_APP_MEM_SIZE,
                mmi_mtv_player_app_mem_success_callback);
            return;
        }
    }

    /* load setting */
    mmi_mtv_player_load_setting();

    /* allocate storage path buffer */
    mtv_player_p->storage_filepath = gui_malloc(FMGR_PATH_BUFFER_SIZE);
    memset(mtv_player_p->storage_filepath ,0 ,FMGR_PATH_BUFFER_SIZE);

    /* check storage */
    if (mmi_mtv_player_check_and_restore_valid_drv() && mtv_player_p->storage_status != MTV_PLAYER_STORAGE_NOT_AVAILABLE)
    {
        S32 create_result;

        /* drv is valid, create directory */
        mmi_mtv_player_get_storage_file_path(mtv_player_p->storage_filepath);
        create_result = mmi_mtv_player_create_file_dir(mtv_player_p->storage_filepath);


        mtv_player_p->storage_status = MTV_PLAYER_STORAGE_NOT_AVAILABLE;
        /* create directory failed */
        if (create_result == FS_WRITE_PROTECTION)
        {
            mtv_player_p->last_error = MDI_RES_MTV_ERR_WRITE_PROTECTION;
        }
        else if (create_result == FS_DISK_FULL)
        {
            mtv_player_p->last_error  = MDI_RES_MTV_ERR_CARD_DISK_FULL;
        }
        else if (create_result == FS_ROOT_DIR_FULL)
        {
            mtv_player_p->last_error  = MDI_RES_MTV_ERR_ROOT_DIR_FULL;
        }
        else
        {
            mtv_player_p->storage_status = MTV_PLAYER_STORAGE_MOUNTED;
            mtv_player_p->last_error = MDI_RES_MTV_SUCCEED;
        }
    }  
    else
    {
        /* drv no valid, means card is plugged out (or phone FAT corrupted) */
        mtv_player_p->storage_status = MTV_PLAYER_STORAGE_NEED_TO_MOUNT;
        mtv_player_p->last_error = MDI_RES_MTV_ERR_CORRUPT_FAT;
    }

    /* enter channel list first */
    if ((mtv_player_p->setting.is_channel_list_init == FALSE || mtv_player_p->setting.is_channel_seleted == FALSE)
        && mtv_player_p->storage_status == MTV_PLAYER_STORAGE_MOUNTED)
    {   
        mmi_mtv_player_entry_init_channel_list_screen();
        return ;
    }

    EntryNewScreen(SCR_ID_MOBILE_TV_PLAYER_APP, mmi_mtv_player_exit_app_screen, mmi_mtv_player_entry_app_screen, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MOBILE_TV_PLAYER_APP);
    SetDelScrnIDCallbackHandler(SCR_ID_MOBILE_TV_PLAYER_APP, mmi_mtv_player_del_scr_callback);

    /* check storage */
    if (mtv_player_p->storage_status == MTV_PLAYER_STORAGE_NEED_TO_MOUNT)
    {
        mmi_mtv_player_entry_storage_screen();
        return ;
    }

    /* initialize flags */
    mtv_player_p->is_show_hint = FALSE;
    mtv_player_p->is_key_pressed = FALSE;
    mtv_player_p->is_ts_bar_enable = TRUE;
    mtv_player_p->anim_handle = 0;
    mtv_player_p->fullscr_osd_opacity = 255;
    mtv_player_p->is_changing_channel_by_key = FALSE;
    mtv_player_p->is_updating_channel_list = FALSE;
    #ifdef __MMI_TOUCH_SCREEN__
    mtv_player_p->is_pen_down = FALSE;
    #endif
    mtv_player_p->scrolling_label_state= MTV_PLAYER_SCROLLING_TEXT_OFF;

    mmi_frm_screen_rotate(mtv_player_p->ui_rotate);


    /* entry full screen app */
    entry_full_screen();

    /* stop bg music */
    mdi_audio_suspend_background_play();

    /* stop MMI sleep */
    TurnOnBacklight(0);

    /* force all playing keypad tone off */
    AudioStopReq(GetCurKeypadTone());

    /* disable key pad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);

    /* disalbe align timer  */
    UI_disable_alignment_timers();

    /* stop LED patten */
    GpioCtrlReq(MMIAPI_DEV_CTRL_GET);

    /* enable multi-layer */
    gdi_layer_multi_layer_enable();

    /* init adm related resource */
    mmi_mtv_player_create_adm();    
    mmi_mtv_player_init_adm_resource();

    /* init screen-based related resource */
    mmi_mtv_player_create_resource();

    /* clear drawing layer if player not in pause state */
    if (!PLAYER_STATE_IN(MTV_PLAYER_PAUSE))
    {
        gdi_layer_push_and_set_active(mtv_player_p->preview_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
    }
    
    /* blt application first time */
    gdi_layer_set_blt_layer(mtv_player_p->preview_layer_handle, mtv_player_p->osd_layer_handle, mtv_player_p->dls_layer_handle, 0);
    mmi_mtv_player_draw_osd();
    gdi_lcd_blt(mtv_player_p->preview_layer_handle, mtv_player_p->osd_layer_handle, mtv_player_p->dls_layer_handle, 0);

    /* if there is any error, popup then exit application */
    if(mtv_player_p->last_error != MDI_RES_MTV_SUCCEED)
    {
        U16 string_id = mmi_mtv_player_get_error_string_by_error_enum(mtv_player_p->last_error);

        if (mtv_player_p->storage_status == MTV_PLAYER_STORAGE_NOT_AVAILABLE)
            mtv_player_p->storage_status = MTV_PLAYER_STORAGE_NEED_TO_MOUNT;
        
        mmi_mtv_player_display_error_popup(string_id);
        return;
    }
    /*--- start to check state from here ---*/
    if (KERNEL_STATE_IN(MTV_KERNEL_CLOSED))
    {
        mtv_player_p->max_delay = 0;
        mtv_player_p->play_delay = 0;

        /* check player and recorder state, should be stopped */
        if (!PLAYER_STATE_IN(MTV_PLAYER_STOPPED)
           || !RECORDER_STATE_IN(MTV_RECORDER_STOPPED))
        {
            ASSERT(0);
        }
        
        mtv_player_p->last_error = mmi_mtv_player_open_engine();

        if (mtv_player_p->last_error == MDI_RES_MTV_UNSAVE_RECORDING_IND)
        {
            // enter save confirm
            MTV_ENTER_STATE(kernel,MMI_MTV_KERNEL,MTV_KERNEL_SAVE_CONFIRM);
            return;
        }
        else if (mtv_player_p->last_error == MDI_RES_MTV_SUCCEED)
        {
            // enter scanning
            MTV_ENTER_STATE(kernel,MMI_MTV_KERNEL,MTV_KERNEL_SCANNING);
            mmi_mtv_player_register_key_hdlr();
            return;
        }
        else
        {
            ASSERT(0);
        }
    }
    else if (KERNEL_STATE_IN(MTV_KERNEL_SAVING))
    {
        if (mtv_player_p->is_saving == FALSE)
        {
            // enter scanning state
            MTV_ENTER_STATE(kernel,MMI_MTV_KERNEL,MTV_KERNEL_SCANNING);
            mmi_mtv_player_register_key_hdlr();
            return;
        }
        else
        {
            // should not go here
            ASSERT(0);
        }
    }
    else if (KERNEL_STATE_IN(MTV_KERNEL_SCANNING))
    {
        MTV_ENTER_STATE(kernel,MMI_MTV_KERNEL,MTV_KERNEL_OPENED);    
    }
    else if (KERNEL_STATE_IN(MTV_KERNEL_READY))
    {
        // keep in ready state
        // and it depents on player and recorder states.
        if (mtv_player_p->is_recorder_error == TRUE)
        {
            MTV_ENTER_STATE(recorder,MMI_MTV_RECORDER,MTV_RECORDER_SAVING);
            mtv_player_p->is_recorder_error = FALSE;
            return;
        }

        mmi_mtv_player_kernel_entry_ready_state();
        mmi_mtv_player_register_key_hdlr();
    }
    else if (KERNEL_STATE_IN(MTV_KERNEL_OPENED))
    {
        // enter initialize state
        MTV_ENTER_STATE(kernel,MMI_MTV_KERNEL,MTV_KERNEL_INIT);
    }
    else if (KERNEL_STATE_IN(MTV_KERNEL_SAVE_CONFIRM))
    {
        if (mtv_player_p->is_discarding_file == TRUE)
        {
            MTV_ENTER_STATE(kernel,MMI_MTV_KERNEL,MTV_KERNEL_SCANNING);    
        }
        else
        {
            // Keep in save confirm state
            mmi_mtv_player_kernel_entry_save_confirm_state();        
        }
    }
    else if (KERNEL_STATE_IN(MTV_KERNEL_INIT))
    {       
        MTV_ENTER_STATE(kernel,MMI_MTV_KERNEL,MTV_KERNEL_READY);
        mmi_mtv_player_register_key_hdlr();
        return;
    }    
    else 
    {
        /* kernel is in wrong state when entering mtv player */
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_exit_app_screen
 * DESCRIPTION
 *  mobile tv player exit screen handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_exit_app_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (PLAYER_STATE_IN(MTV_PLAYER_PLAY)||PLAYER_STATE_IN(MTV_PLAYER_BT_CONNECT))
        MTV_ENTER_STATE(player,MMI_MTV_PLAYER,MTV_PLAYER_STOPPED);

    gui_cancel_timer(mmi_mtv_player_hide_hint);
    gui_cancel_timer(mmi_mtv_player_jump_to_channel);

    gdi_anim_stop(mtv_player_p->anim_handle);

    if (mtv_player_p->scrolling_label_state == MTV_PLAYER_SCROLLING_TEXT_SCROLLING)
    {
        gui_scrolling_text_stop(&mtv_player_p->scrolling_label);
    }

    gdi_layer_flatten_to_base(mtv_player_p->preview_layer_handle,mtv_player_p->osd_layer_handle,mtv_player_p->dls_layer_handle,0);

#ifdef __MMI_MTV_AVRCP_SUPPORT__
    PRINT_INFORMATION("Mobile tv player clear avrcp cmd hdlr\n");
    mmi_bt_avrcp_clear_cmd_hdlr();
#endif 

    /* resume alignment timer */
    UI_enable_alignment_timers();

    /* resume LED patten */
    GpioCtrlReq(MMIAPI_DEV_CTRL_RELEASE);

    /* let MMI can sleep */
    TurnOffBacklight();

    /* enable multi-layer */
    gdi_layer_multi_layer_disable();

    /* resume background audio */
    mdi_audio_resume_background_play();

    /* re-enable keypad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);

    mmi_mtv_player_free_resource();
    mmi_mtv_player_store_setting();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_display_error_popup
 * DESCRIPTION
 *  display error popup funcions
 * PARAMETERS
 *  S16     IN      stringid
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_display_error_popup(U16 stringid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    DisplayPopupRotated(
        (PU8) GetString(stringid),
        IMG_GLOBAL_WARNING,
        0,
        ST_NOTIFYDURATION,
        WARNING_TONE,
        mtv_player_p->ui_rotate);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_display_done_popup
 * DESCRIPTION
 *  display error popup funcions
 * PARAMETERS
 *  S16     IN      stringid
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_display_done_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    DisplayPopupRotated(
        (PU8) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        1,
        ST_NOTIFYDURATION,
        SUCCESS_TONE,
        mtv_player_p->ui_rotate);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_get_storage_file_path
 * DESCRIPTION
 *  get current active storage file path.
 * PARAMETERS
 *  filepath        [OUT]       File path
 * RETURNS
 * BOOL
 *****************************************************************************/
static BOOL mmi_mtv_player_get_storage_file_path(PS8 filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 drv_buf[8];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_mtv_player_get_storage_disk_path(drv_buf))
    {
        mmi_ucs2cpy((PS8) filepath, (PS8) drv_buf);
        mmi_ucs2cat((PS8) filepath, (PS8) MMI_MTV_PLAYER_STORAGE_FILEPATH);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_get_storage_disk_path
 * DESCRIPTION
 *  get current active storage disk path.
 * PARAMETERS
 *  drv_buf     [OUT]       Drive path buffer
 * RETURNS
 *  void
 *****************************************************************************/
static BOOL mmi_mtv_player_get_storage_disk_path(PS8 drv_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf[64];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (FS_NO_ERROR == FS_GetDevStatus(mtv_player_p->setting.storage ,FS_MOUNT_STATE_ENUM))
    {
        sprintf(buf, "%c:\\", (U8)mtv_player_p->setting.storage);
        mmi_asc_to_ucs2(drv_buf, buf);
        return TRUE;
    }
    else
    {
        mtv_player_p->setting.storage = (U16) MMI_PUBLIC_DRV;

        if (FS_NO_ERROR != FS_GetDevStatus(mtv_player_p->setting.storage ,FS_MOUNT_STATE_ENUM))
            return FALSE;

        sprintf(buf, "%c:\\", (U8)mtv_player_p->setting.storage);
        mmi_asc_to_ucs2(drv_buf, buf);
        return TRUE;
    }   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_create_file_dir
 * DESCRIPTION
 *  create directly from a file path (resursivly)
 * PARAMETERS
 *  filepath        [IN]        File path to create
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_mtv_player_create_file_dir(PS8 filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_createpath[128];
    S8 buf_filepath[FMGR_PATH_BUFFER_SIZE];
    S32 fs_ret;
    S32 str_len;
    S32 cmp_ret;
    S32 i;
    FS_HANDLE file_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fs_ret = 0;

    file_handle = FS_Open((kal_uint16*) filepath, FS_OPEN_DIR | FS_READ_ONLY);

    /* path already exist */
    if (file_handle >= 0)
    {
        FS_Close(file_handle);
        return 0;   /* already exist , 0 measn success in FS */
    }

    /* create directory if it is not there */
    mmi_ucs2cpy((PS8) buf_filepath, (PS8) filepath);

    str_len = mmi_ucs2strlen((PS8) buf_filepath);
    str_len *= ENCODING_LENGTH;

    /* skip drive. "C:\" */
    for (i = 3 * ENCODING_LENGTH; i < str_len; i += 2)
    {
        cmp_ret = mmi_ucs2ncmp((PS8) & buf_filepath[i], (PS8) L"\\", 1);
        if (cmp_ret == 0)
        {
            /* create dir */

            mmi_ucs2ncpy((PS8) buf_createpath, (PS8) buf_filepath, i / ENCODING_LENGTH);
            buf_createpath[i] = '\0';
            buf_createpath[i + 1] = '\0';

            fs_ret = FS_CreateDir((PU16) buf_createpath);

            if (fs_ret < 0)
            {
                return fs_ret;
            }
        }
    }

    return fs_ret;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_set_storage_callback
 * DESCRIPTION
 *  set storage callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_set_storage_callback(S8 drv_letter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_filepath[FMGR_PATH_BUFFER_SIZE];
    S32 create_result;
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /***************************************************
     * for new storage error handling machenism 
     ***************************************************/
    if (drv_letter == 0 && !IsScreenPresent(SCR_ID_MOBILE_TV_PLAYER_OPTION_MENU))
    {
        mtv_player_p->storage_status = MTV_PLAYER_STORAGE_NOT_AVAILABLE;
        DeleteScreenIfPresent(SCR_ID_MOBILE_TV_PLAYER_STORAGE);
        DeleteScreenIfPresent(SCR_ID_MOBILE_TV_PLAYER_APP);
        return;
    }
    else if (drv_letter != 0)
    {
        mtv_player_p->setting.storage = (U16) drv_letter;
        mtv_player_p->storage_status = MTV_PLAYER_STORAGE_NEED_TO_MOUNT;
            
        if (TRUE == mmi_mtv_player_get_storage_file_path(buf_filepath))
        {
            create_result = mmi_mtv_player_create_file_dir(buf_filepath);

            if (create_result == FS_WRITE_PROTECTION)
            {
                mmi_mtv_player_display_error_popup(FMGR_FS_WRITE_PROTECTION_TEXT);
            }
            else if (create_result == FS_DISK_FULL)
            {
                mmi_mtv_player_display_error_popup(FMGR_FS_DISK_FULL_TEXT);
            }
            else if (create_result == FS_ROOT_DIR_FULL)
            {
                mmi_mtv_player_display_error_popup(FMGR_FS_ROOT_DIR_FULL_TEXT);
            }
            else
            {
                mtv_player_p->storage_status = MTV_PLAYER_STORAGE_MOUNTED;
                mmi_mtv_player_display_done_popup();
            }
        }
        else
            mmi_mtv_player_display_error_popup(FMGR_FS_DRIVE_NOT_READY_TEXT);

        /* storge setting to NVRAM */
        WriteRecord(NVRAM_EF_MOBILE_TV_PLAYER_SETTING_LID, 1, (void*)&mtv_player_p->setting, NVRAM_EF_MOBILE_TV_PLAYER_SETTING_SIZE, &error);
    }

    DeleteScreenIfPresent(SCR_ID_MOBILE_TV_PLAYER_STORAGE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_rsk_press
 * DESCRIPTION
 *  mobile tv player rsk press handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_rsk_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->touch_object = MTV_PLAYER_TOUCH_RSK;
    mtv_player_p->rsk.status = MTV_PLAYER_ICON_STATUS_CLICKED;
    mmi_mtv_player_fullscr_reset_osd_fade(FALSE);
    gdi_lcd_blt(mtv_player_p->preview_layer_handle, mtv_player_p->osd_layer_handle, mtv_player_p->dls_layer_handle, 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_rsk_release
 * DESCRIPTION
 *  mobile tv player rsk release handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_rsk_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->rsk.status = MTV_PLAYER_ICON_STATUS_ENABLE;

    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
        mmi_mtv_player_fullscr_reset_osd_fade(TRUE);
    else
        mmi_mtv_player_fullscr_reset_osd_fade(FALSE);

    gdi_lcd_blt(mtv_player_p->preview_layer_handle, mtv_player_p->osd_layer_handle, mtv_player_p->dls_layer_handle, 0);


    /* Go Back History */
    if (!RECORDER_STATE_IN(MTV_RECORDER_RECORD))
    {
        MTV_ENTER_STATE(kernel,MMI_MTV_KERNEL,MTV_KERNEL_CLOSED);
    }
    else
    {
        
    }


    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_lsk_press
 * DESCRIPTION
 *  mobile tv player lsk press handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_lsk_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->touch_object = MTV_PLAYER_TOUCH_LSK;
    mtv_player_p->lsk.status = MTV_PLAYER_ICON_STATUS_CLICKED;
    mmi_mtv_player_fullscr_reset_osd_fade(FALSE);
    gdi_lcd_blt(mtv_player_p->preview_layer_handle, mtv_player_p->osd_layer_handle, mtv_player_p->dls_layer_handle, 0);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_lsk_release
 * DESCRIPTION
 *  mobile tv player lsk release handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_lsk_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->lsk.status = MTV_PLAYER_ICON_STATUS_ENABLE;

    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
        mmi_mtv_player_fullscr_reset_osd_fade(TRUE);
    else
        mmi_mtv_player_fullscr_reset_osd_fade(FALSE);

    gdi_lcd_blt(mtv_player_p->preview_layer_handle, mtv_player_p->osd_layer_handle, mtv_player_p->dls_layer_handle, 0);

    if (PLAYER_STATE_IN(MTV_PLAYER_PLAY)||PLAYER_STATE_IN(MTV_PLAYER_BT_CONNECT))
        MTV_ENTER_STATE(player, MMI_MTV_PLAYER, MTV_PLAYER_STOPPED);

    mmi_mtv_player_entry_option_menu_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_play_icon_press
 * DESCRIPTION
 *  mobile tv player play icon press handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_play_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mtv_player_p->is_changing_channel_by_key == TRUE)
    {
        mmi_mtv_player_jump_to_channel();
        ClearKeyEvents();
    }
    else if (PLAYER_STATE_IN(MTV_PLAYER_PAUSE) ||PLAYER_STATE_IN(MTV_PLAYER_PLAY)||PLAYER_STATE_IN(MTV_PLAYER_BT_CONNECT))
    {
        mtv_player_p->touch_object = MTV_PLAYER_TOUCH_PLAY;
        mtv_player_p->active_osd_cntx_p->play.status = MTV_PLAYER_ICON_STATUS_CLICKED;
        mmi_mtv_player_fullscr_reset_osd_fade(FALSE);
        gdi_lcd_blt(mtv_player_p->preview_layer_handle, mtv_player_p->osd_layer_handle, mtv_player_p->dls_layer_handle, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_play_icon_release
 * DESCRIPTION
 *  mobile tv player play icon release handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_play_icon_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PLAYER_STATE_IN(MTV_PLAYER_PAUSE) ||PLAYER_STATE_IN(MTV_PLAYER_PLAY) ||PLAYER_STATE_IN(MTV_PLAYER_BT_CONNECT))
    {
        if (PLAYER_STATE_IN(MTV_PLAYER_PAUSE))
        {
        #if defined(__MMI_MTV_A2DP_SUPPORT__)
            MTV_ENTER_STATE(player,MMI_MTV_PLAYER,MTV_PLAYER_BT_CONNECT);
        #else
            MTV_ENTER_STATE(player,MMI_MTV_PLAYER,MTV_PLAYER_PLAY);
        #endif
        }
        else 
        {
            MTV_ENTER_STATE(player,MMI_MTV_PLAYER,MTV_PLAYER_PAUSE);        
        }

        mtv_player_p->active_osd_cntx_p->play.status  = MTV_PLAYER_ICON_STATUS_ENABLE;
        if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
            mmi_mtv_player_fullscr_reset_osd_fade(TRUE);
        else
            mmi_mtv_player_fullscr_reset_osd_fade(FALSE);
        gdi_lcd_blt(mtv_player_p->preview_layer_handle, mtv_player_p->osd_layer_handle, mtv_player_p->dls_layer_handle, 0);
        mtv_player_p->touch_object = MTV_PLAYER_TOUCH_NONE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_record_icon_press
 * DESCRIPTION
 *  mobile tv player record icon press handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_record_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (RECORDER_STATE_IN(MTV_RECORDER_STOPPED) || RECORDER_STATE_IN(MTV_RECORDER_RECORD))
    {
        mtv_player_p->touch_object = MTV_PLAYER_TOUCH_RECORD;
        mtv_player_p->active_osd_cntx_p->record.status = MTV_PLAYER_ICON_STATUS_CLICKED;
        mmi_mtv_player_fullscr_reset_osd_fade(FALSE);
        gdi_lcd_blt(mtv_player_p->preview_layer_handle, mtv_player_p->osd_layer_handle, mtv_player_p->dls_layer_handle, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_record_icon_release
 * DESCRIPTION
 *  mobile tv player record icon release handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_record_icon_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (RECORDER_STATE_IN(MTV_RECORDER_STOPPED) || RECORDER_STATE_IN(MTV_RECORDER_RECORD))
    {
        if (RECORDER_STATE_IN(MTV_RECORDER_STOPPED))
        {
            MTV_ENTER_STATE(recorder,MMI_MTV_RECORDER,MTV_RECORDER_RECORD);

            mtv_player_p->active_osd_cntx_p->record.status  = MTV_PLAYER_ICON_STATUS_ENABLE;
            if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
                mmi_mtv_player_fullscr_reset_osd_fade(TRUE);
            else
                mmi_mtv_player_fullscr_reset_osd_fade(FALSE);
            gdi_lcd_blt(mtv_player_p->preview_layer_handle, mtv_player_p->osd_layer_handle, mtv_player_p->dls_layer_handle, 0);
            mtv_player_p->touch_object = MTV_PLAYER_TOUCH_NONE;
        }
        else 
        {
            mtv_player_p->active_osd_cntx_p->record.status  = MTV_PLAYER_ICON_STATUS_ENABLE;
            if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
                mmi_mtv_player_fullscr_reset_osd_fade(TRUE);
            else
                mmi_mtv_player_fullscr_reset_osd_fade(FALSE);
            gdi_lcd_blt(mtv_player_p->preview_layer_handle, mtv_player_p->osd_layer_handle, mtv_player_p->dls_layer_handle, 0);
            mtv_player_p->touch_object = MTV_PLAYER_TOUCH_NONE;

            MTV_ENTER_STATE(player,MMI_MTV_PLAYER,MTV_PLAYER_STOPPED);
            MTV_ENTER_STATE(recorder,MMI_MTV_RECORDER,MTV_RECORDER_SAVE_CONFIRM);          
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_play_speed_icon_press
 * DESCRIPTION
 *  mobile tv player play_speed icon press handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_play_speed_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[256];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mtv_player_p->setting.play_speed + 1 < MTV_PLAYER_PLAY_SPEED_TOTAL_COUNT)
    {
        mtv_player_p->setting.play_speed++;
    }
    else
    {
        mtv_player_p->setting.play_speed = MTV_PLAYER_PLAY_SPEED_10X;
    }

    mmi_ucs2cpy((PS8) str_buf, (PS8) L"[ ");
    mmi_ucs2cat((PS8) str_buf, (PS8) GetString(STR_ID_MOBILE_TV_PLAYER_SETTING_PLAY_SPEED));
    mmi_ucs2cat((PS8) str_buf, (PS8) L" ]");

    mmi_mtv_player_set_hint(
        (PS8) str_buf,
        (PS8) GetString((U16) (mtv_player_p->setting.play_speed+ STR_ID_MTV_PLAYER_PLAY_SPEED_10X)),
        MMI_MOBILE_TV_PLAYER_HINT_POPUP_FADE_TIME);


    mmi_mtv_player_fullscr_reset_osd_fade(FALSE);
    gdi_lcd_blt(mtv_player_p->preview_layer_handle, mtv_player_p->osd_layer_handle, mtv_player_p->dls_layer_handle, 0);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_play_speed_icon_release
 * DESCRIPTION
 *  mobile tv player play_speed icon release handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_play_speed_icon_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_fullscreen_icon_press
 * DESCRIPTION
 *  mobile tv player fullscreen icon press handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_fullscreen_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->touch_object = MTV_PLAYER_TOUCH_FULLSCREEN;
    mtv_player_p->active_osd_cntx_p->fullscreen.status = MTV_PLAYER_ICON_STATUS_CLICKED;
    mmi_mtv_player_fullscr_reset_osd_fade(FALSE);
    gdi_lcd_blt(mtv_player_p->preview_layer_handle, mtv_player_p->osd_layer_handle, mtv_player_p->dls_layer_handle, 0);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_fullscreen_icon_release
 * DESCRIPTION
 *  mobile tv player fullscreen icon release handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_fullscreen_icon_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->active_osd_cntx_p->fullscreen.status  = MTV_PLAYER_ICON_STATUS_ENABLE;
    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
        mmi_mtv_player_fullscr_reset_osd_fade(TRUE);
    else
        mmi_mtv_player_fullscr_reset_osd_fade(FALSE);
    gdi_lcd_blt(mtv_player_p->preview_layer_handle, mtv_player_p->osd_layer_handle, mtv_player_p->dls_layer_handle, 0);
    mtv_player_p->touch_object = MTV_PLAYER_TOUCH_NONE;

    /* PLAYER SHOULD GO TO STOPPED STATE */
    MTV_ENTER_STATE(player,MMI_MTV_PLAYER,MTV_PLAYER_STOPPED);

    mtv_player_p->ui_rotate =(mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)?MMI_FRM_SCREEN_ROTATE_270:MMI_FRM_SCREEN_ROTATE_0;
    mmi_mtv_player_config_osd_and_dls_layer();

    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        mmi_mtv_player_fullscr_reset_osd_fade(TRUE);       
    }
    else
    {
        mmi_mtv_player_fullscr_reset_osd_fade(FALSE);
    }


    mmi_frm_screen_rotate(mtv_player_p->ui_rotate);
    mmi_mtv_player_register_key_hdlr();
    
    gdi_lcd_blt(mtv_player_p->preview_layer_handle, mtv_player_p->osd_layer_handle, mtv_player_p->dls_layer_handle, 0);

    if (mtv_player_p->player_prev_state == MTV_PLAYER_PLAY)
    {
    #if defined(__MMI_MTV_A2DP_SUPPORT__)
        MTV_ENTER_STATE(player,MMI_MTV_PLAYER,MTV_PLAYER_BT_CONNECT);
    #else
        MTV_ENTER_STATE(player,MMI_MTV_PLAYER,MTV_PLAYER_PLAY);
    #endif
    }
    else if (mtv_player_p->player_prev_state == MTV_PLAYER_PAUSE)
    {
        MTV_ENTER_STATE(player,MMI_MTV_PLAYER,MTV_PLAYER_PAUSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_forward_icon_press
 * DESCRIPTION
 *  mobile tv player forward icon press handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_forward_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_mtv_player_status_struct status;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->touch_object = MTV_PLAYER_TOUCH_FORWARD;

    mdi_mtv_player_get_status(mtv_player_p->mtv_handle, &status);

    mtv_player_p->max_delay = status.max_delay;
    mtv_player_p->play_delay = status.play_delay;

    if (mtv_player_p->play_delay == 0)
        return;

    if (mtv_player_p->play_delay <= 8)
        mtv_player_p->play_delay = 0;
    else
        mtv_player_p->play_delay -= 8;    

    mdi_mtv_recorder_seek(mtv_player_p->mtv_handle,mtv_player_p->play_delay);

    if (mtv_player_p->play_delay != MTV_PLAYER_VOL_16)
    {
        if (mtv_player_p->is_key_pressed)
        {
            gui_start_timer(100, mmi_mtv_player_forward_icon_press);
        }
        else
        {
            /* first time press up arrow, use longer time */
            gui_start_timer(300, mmi_mtv_player_forward_icon_press);
            mtv_player_p->is_key_pressed = TRUE;
        }
    }

    mtv_player_p->active_osd_cntx_p->forward.status = MTV_PLAYER_ICON_STATUS_CLICKED;
    mmi_mtv_player_fullscr_reset_osd_fade(FALSE);
    gdi_lcd_blt(mtv_player_p->preview_layer_handle, mtv_player_p->osd_layer_handle, mtv_player_p->dls_layer_handle, 0);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_forward_icon_release
 * DESCRIPTION
 *  mobile tv player forward icon release handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_forward_icon_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_mtv_player_forward_icon_press);
    mtv_player_p->is_key_pressed = FALSE;
    mtv_player_p->active_osd_cntx_p->forward.status  = MTV_PLAYER_ICON_STATUS_ENABLE;
    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
        mmi_mtv_player_fullscr_reset_osd_fade(TRUE);
    else
        mmi_mtv_player_fullscr_reset_osd_fade(FALSE);
    gdi_lcd_blt(mtv_player_p->preview_layer_handle, mtv_player_p->osd_layer_handle, mtv_player_p->dls_layer_handle, 0);
    mtv_player_p->touch_object = MTV_PLAYER_TOUCH_NONE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_rewind_icon_press
 * DESCRIPTION
 *  mobile tv player rewind icon press handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_rewind_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_mtv_player_status_struct status;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->touch_object = MTV_PLAYER_TOUCH_REWIND;

    mdi_mtv_player_get_status(mtv_player_p->mtv_handle, &status);

    mtv_player_p->max_delay = status.max_delay;
    mtv_player_p->play_delay = status.play_delay;

    if (mtv_player_p->play_delay == mtv_player_p->max_delay)
        return;

    mtv_player_p->play_delay+=8; 

    if (mtv_player_p->play_delay >mtv_player_p->max_delay)
        mtv_player_p->play_delay = mtv_player_p->max_delay;

    mdi_mtv_recorder_seek(mtv_player_p->mtv_handle,mtv_player_p->play_delay);

    if (mtv_player_p->play_delay > mtv_player_p->max_delay)
        mtv_player_p->play_delay = mtv_player_p->max_delay;

	if (mtv_player_p->play_delay != mtv_player_p->max_delay)
    {
        if (mtv_player_p->is_key_pressed)
        {
            gui_start_timer(100, mmi_mtv_player_rewind_icon_press);
        }
        else
        {
            /* first time press up arrow, use longer time */
            gui_start_timer(300, mmi_mtv_player_rewind_icon_press);
            mtv_player_p->is_key_pressed = TRUE;
        }
    }

    mtv_player_p->active_osd_cntx_p->rewind.status = MTV_PLAYER_ICON_STATUS_CLICKED;
    mmi_mtv_player_fullscr_reset_osd_fade(FALSE);
    gdi_lcd_blt(mtv_player_p->preview_layer_handle, mtv_player_p->osd_layer_handle, mtv_player_p->dls_layer_handle, 0);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_rewind_icon_release
 * DESCRIPTION
 *  mobile tv player rewind icon release handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_rewind_icon_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_mtv_player_rewind_icon_press);
    mtv_player_p->is_key_pressed = FALSE;

    mtv_player_p->active_osd_cntx_p->rewind.status  = MTV_PLAYER_ICON_STATUS_ENABLE;
    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
        mmi_mtv_player_fullscr_reset_osd_fade(TRUE);
    else
        mmi_mtv_player_fullscr_reset_osd_fade(FALSE);
    gdi_lcd_blt(mtv_player_p->preview_layer_handle, mtv_player_p->osd_layer_handle, mtv_player_p->dls_layer_handle, 0);
    mtv_player_p->touch_object = MTV_PLAYER_TOUCH_NONE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_vol_inc_icon_press
 * DESCRIPTION
 *  mobile tv player vol_inc icon press handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_vol_inc_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->touch_object = MTV_PLAYER_TOUCH_VOL_INC;


    if (mtv_player_p->setting.vol_level < MTV_PLAYER_VOL_16)
    {
        mtv_player_p->setting.vol_level++;
        mdi_audio_set_volume(MDI_VOLUME_MEDIA, MDI_AUD_VOL_EX(mtv_player_p->setting.vol_level));
    }
    else if (mtv_player_p->setting.vol_level == MTV_PLAYER_VOL_MUTE)
    {
        mtv_player_p->setting.vol_level = MTV_PLAYER_VOL_1;
        mdi_audio_set_mute(MDI_VOLUME_MEDIA, FALSE);
        mdi_audio_set_volume(MDI_VOLUME_MEDIA, MDI_AUD_VOL_EX(mtv_player_p->setting.vol_level));
    }


	if (mtv_player_p->setting.vol_level != MTV_PLAYER_VOL_16)
    {
        if (mtv_player_p->is_key_pressed)
        {
            gui_start_timer(100, mmi_mtv_player_vol_inc_icon_press);
        }
        else
        {
            /* first time press up arrow, use longer time */
            gui_start_timer(300, mmi_mtv_player_vol_inc_icon_press);
            mtv_player_p->is_key_pressed = TRUE;
        }
    }

    mtv_player_p->active_osd_cntx_p->vol_inc.status = MTV_PLAYER_ICON_STATUS_CLICKED;
    mmi_mtv_player_fullscr_reset_osd_fade(FALSE);
    gdi_lcd_blt(mtv_player_p->preview_layer_handle, mtv_player_p->osd_layer_handle, mtv_player_p->dls_layer_handle, 0);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_vol_inc_icon_release
 * DESCRIPTION
 *  mobile tv player vol_inc icon release handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_vol_inc_icon_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_mtv_player_vol_inc_icon_press);
    mtv_player_p->is_key_pressed = FALSE;
    mtv_player_p->active_osd_cntx_p->vol_inc.status  = MTV_PLAYER_ICON_STATUS_ENABLE;
    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
        mmi_mtv_player_fullscr_reset_osd_fade(TRUE);
    else
        mmi_mtv_player_fullscr_reset_osd_fade(FALSE);
    gdi_lcd_blt(mtv_player_p->preview_layer_handle, mtv_player_p->osd_layer_handle, mtv_player_p->dls_layer_handle, 0);
    mtv_player_p->touch_object = MTV_PLAYER_TOUCH_NONE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_vol_dec_icon_press
 * DESCRIPTION
 *  mobile tv player vol_dec icon press handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_vol_dec_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->touch_object = MTV_PLAYER_TOUCH_VOL_DEC;
    
    if (mtv_player_p->setting.vol_level > MTV_PLAYER_VOL_1 && mtv_player_p->setting.vol_level != MTV_PLAYER_VOL_MUTE)
    {
        mtv_player_p->setting.vol_level--;
        mdi_audio_set_volume(MDI_VOLUME_MEDIA, MDI_AUD_VOL_EX(mtv_player_p->setting.vol_level));
    }
    else if (mtv_player_p->setting.vol_level == MTV_PLAYER_VOL_1)
    {
		mtv_player_p->setting.vol_level = MTV_PLAYER_VOL_MUTE;
          mdi_audio_set_mute(MDI_VOLUME_MEDIA, TRUE);
    }
    
    if (mtv_player_p->setting.vol_level != MTV_PLAYER_VOL_MUTE)
    {
		if (mtv_player_p->is_key_pressed)
        {
            gui_start_timer(100, mmi_mtv_player_vol_dec_icon_press);
        }
        else
        {
            /* first time press up arrow, use longer time */
            gui_start_timer(300, mmi_mtv_player_vol_dec_icon_press);
            mtv_player_p->is_key_pressed = TRUE;
        }
    }


    mtv_player_p->active_osd_cntx_p->vol_dec.status = MTV_PLAYER_ICON_STATUS_CLICKED;
    mmi_mtv_player_fullscr_reset_osd_fade(FALSE);
    gdi_lcd_blt(mtv_player_p->preview_layer_handle, mtv_player_p->osd_layer_handle, mtv_player_p->dls_layer_handle, 0);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_vol_dec_icon_release
 * DESCRIPTION
 *  mobile tv player vol_dec icon release handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_vol_dec_icon_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_mtv_player_vol_dec_icon_press);
    mtv_player_p->is_key_pressed = FALSE;
    mtv_player_p->active_osd_cntx_p->vol_dec.status = MTV_PLAYER_ICON_STATUS_ENABLE;
    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
        mmi_mtv_player_fullscr_reset_osd_fade(TRUE);
    else
        mmi_mtv_player_fullscr_reset_osd_fade(FALSE);
    gdi_lcd_blt(mtv_player_p->preview_layer_handle, mtv_player_p->osd_layer_handle, mtv_player_p->dls_layer_handle, 0);
    mtv_player_p->touch_object = MTV_PLAYER_TOUCH_NONE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_channel_next_icon_press
 * DESCRIPTION
 *  mobile tv player channel_next icon press handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_channel_next_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->touch_object = MTV_PLAYER_TOUCH_CHANNEL_NEXT;

    MTV_ENTER_STATE(player,MMI_MTV_PLAYER,MTV_PLAYER_STOPPED);    
    MTV_ENTER_STATE(kernel,MMI_MTV_KERNEL,MTV_KERNEL_OPENED);

    if (mtv_player_p->setting.selected_channel==mtv_player_p->setting.num_services - 1)
        mtv_player_p->setting.selected_channel=0;
    else
        mtv_player_p->setting.selected_channel++;

    if (mtv_player_p->is_key_pressed)
    {
        gui_start_timer(300, mmi_mtv_player_channel_next_icon_press);
    }
    else
    {
        /* first time press up arrow, use longer time */
        gui_start_timer(500, mmi_mtv_player_channel_next_icon_press);
        mtv_player_p->is_key_pressed = TRUE;
    }

    mtv_player_p->active_osd_cntx_p->channel_next.status = MTV_PLAYER_ICON_STATUS_CLICKED;
    mmi_mtv_player_fullscr_reset_osd_fade(FALSE);
    gdi_lcd_blt(mtv_player_p->preview_layer_handle, mtv_player_p->osd_layer_handle, mtv_player_p->dls_layer_handle, 0);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_channel_next_icon_release
 * DESCRIPTION
 *  mobile tv player channel_next icon release handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_channel_next_icon_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[20];
    S8 buffer[25];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->is_key_pressed = FALSE;
    gui_cancel_timer(mmi_mtv_player_channel_next_icon_press);
    mtv_player_p->active_osd_cntx_p->channel_next.status  = MTV_PLAYER_ICON_STATUS_ENABLE;

    mmi_mtv_player_clear_dls_layer();

    MTV_ENTER_STATE(kernel,MMI_MTV_KERNEL,MTV_KERNEL_INIT);

    sprintf((PS8) buffer, "Channel %2d", mtv_player_p->setting.selected_channel+1);
    mmi_asc_to_ucs2((PS8) str_buf, (PS8) buffer);

    mmi_mtv_player_set_hint(
        (PS8) str_buf,
        (PS8) NULL,
        MMI_MOBILE_TV_PLAYER_HINT_POPUP_FADE_TIME);        

    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
        mmi_mtv_player_fullscr_reset_osd_fade(TRUE);
    else
        mmi_mtv_player_fullscr_reset_osd_fade(FALSE);
    gdi_lcd_blt(mtv_player_p->preview_layer_handle, mtv_player_p->osd_layer_handle, mtv_player_p->dls_layer_handle, 0);
    mtv_player_p->touch_object = MTV_PLAYER_TOUCH_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_channel_prev_icon_press
 * DESCRIPTION
 *  mobile tv player channel_prev icon press handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_channel_prev_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->touch_object = MTV_PLAYER_TOUCH_CHANNEL_PREV;

    MTV_ENTER_STATE(player,MMI_MTV_PLAYER,MTV_PLAYER_STOPPED);    
    MTV_ENTER_STATE(kernel,MMI_MTV_KERNEL,MTV_KERNEL_OPENED);
    
    if(mtv_player_p->setting.selected_channel==0)
        mtv_player_p->setting.selected_channel = mtv_player_p->setting.num_services - 1;
    else
        mtv_player_p->setting.selected_channel--;

    if (mtv_player_p->is_key_pressed)
    {
        gui_start_timer(300, mmi_mtv_player_channel_prev_icon_press);
    }
    else
    {
        /* first time press up arrow, use longer time */
        gui_start_timer(500, mmi_mtv_player_channel_prev_icon_press);
        mtv_player_p->is_key_pressed = TRUE;
    }

    mtv_player_p->active_osd_cntx_p->channel_prev.status = MTV_PLAYER_ICON_STATUS_CLICKED;
    mmi_mtv_player_fullscr_reset_osd_fade(FALSE);
    gdi_lcd_blt(mtv_player_p->preview_layer_handle, mtv_player_p->osd_layer_handle, mtv_player_p->dls_layer_handle, 0);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_channel_prev_icon_release
 * DESCRIPTION
 *  mobile tv player channel_prev icon release handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_channel_prev_icon_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[20];
    S8 buffer[25];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->is_key_pressed = FALSE;
    gui_cancel_timer(mmi_mtv_player_channel_prev_icon_press);
    mtv_player_p->active_osd_cntx_p->channel_prev.status  = MTV_PLAYER_ICON_STATUS_ENABLE;

    mmi_mtv_player_clear_dls_layer();
    
    MTV_ENTER_STATE(kernel,MMI_MTV_KERNEL,MTV_KERNEL_INIT);
   
    sprintf((PS8) buffer, "Channel %2d", mtv_player_p->setting.selected_channel+1);
    mmi_asc_to_ucs2((PS8) str_buf, (PS8) buffer);

    mmi_mtv_player_set_hint(
        (PS8) str_buf,
        (PS8) NULL,
        MMI_MOBILE_TV_PLAYER_HINT_POPUP_FADE_TIME);        

    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
        mmi_mtv_player_fullscr_reset_osd_fade(TRUE);
    else
        mmi_mtv_player_fullscr_reset_osd_fade(FALSE);
    gdi_lcd_blt(mtv_player_p->preview_layer_handle, mtv_player_p->osd_layer_handle, mtv_player_p->dls_layer_handle, 0);
    mtv_player_p->touch_object = MTV_PLAYER_TOUCH_NONE;

}

static void mmi_mtv_player_switch_ts_bar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->is_ts_bar_enable = ~mtv_player_p->is_ts_bar_enable;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_key_1_press
 * DESCRIPTION
 *  mobile tv player key 1 pressed handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_key_1_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->is_changing_channel_by_key = TRUE;

    mtv_player_p->change_to_channel = (mtv_player_p->change_to_channel*10 + 1) % 100;
    gui_cancel_timer(mmi_mtv_player_jump_to_channel);
    gui_start_timer(MMI_MTV_JUMP_TO_CHANNEL_DELAY, mmi_mtv_player_jump_to_channel);

    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
        mmi_mtv_player_fullscr_reset_osd_fade(TRUE);
    else
        mmi_mtv_player_fullscr_reset_osd_fade(FALSE);
    gdi_lcd_blt(mtv_player_p->preview_layer_handle, mtv_player_p->osd_layer_handle, mtv_player_p->dls_layer_handle, 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_key_2_press
 * DESCRIPTION
 *  mobile tv player key 2 pressed handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_key_2_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->is_changing_channel_by_key = TRUE;

    mtv_player_p->change_to_channel = (mtv_player_p->change_to_channel*10 + 2) % 100;
    gui_cancel_timer(mmi_mtv_player_jump_to_channel);
    gui_start_timer(MMI_MTV_JUMP_TO_CHANNEL_DELAY, mmi_mtv_player_jump_to_channel);

    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
        mmi_mtv_player_fullscr_reset_osd_fade(TRUE);
    else
        mmi_mtv_player_fullscr_reset_osd_fade(FALSE);
    gdi_lcd_blt(mtv_player_p->preview_layer_handle, mtv_player_p->osd_layer_handle, mtv_player_p->dls_layer_handle, 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_key_3_press
 * DESCRIPTION
 *  mobile tv player key 3 pressed handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_key_3_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->is_changing_channel_by_key = TRUE;

    mtv_player_p->change_to_channel = (mtv_player_p->change_to_channel*10 + 3) % 100;
    gui_cancel_timer(mmi_mtv_player_jump_to_channel);
    gui_start_timer(MMI_MTV_JUMP_TO_CHANNEL_DELAY, mmi_mtv_player_jump_to_channel);

    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
        mmi_mtv_player_fullscr_reset_osd_fade(TRUE);
    else
        mmi_mtv_player_fullscr_reset_osd_fade(FALSE);
    gdi_lcd_blt(mtv_player_p->preview_layer_handle, mtv_player_p->osd_layer_handle, mtv_player_p->dls_layer_handle, 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_key_4_press
 * DESCRIPTION
 *  mobile tv player key 4 pressed handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_key_4_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->is_changing_channel_by_key = TRUE;

    mtv_player_p->change_to_channel = (mtv_player_p->change_to_channel*10 + 4) % 100;
    gui_cancel_timer(mmi_mtv_player_jump_to_channel);
    gui_start_timer(MMI_MTV_JUMP_TO_CHANNEL_DELAY, mmi_mtv_player_jump_to_channel);

    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
        mmi_mtv_player_fullscr_reset_osd_fade(TRUE);
    else
        mmi_mtv_player_fullscr_reset_osd_fade(FALSE);
    gdi_lcd_blt(mtv_player_p->preview_layer_handle, mtv_player_p->osd_layer_handle, mtv_player_p->dls_layer_handle, 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_key_5_press
 * DESCRIPTION
 *  mobile tv player key 5 pressed handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_key_5_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->is_changing_channel_by_key = TRUE;

    mtv_player_p->change_to_channel = (mtv_player_p->change_to_channel*10 + 5) % 100;
    gui_cancel_timer(mmi_mtv_player_jump_to_channel);
    gui_start_timer(MMI_MTV_JUMP_TO_CHANNEL_DELAY, mmi_mtv_player_jump_to_channel);

    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
        mmi_mtv_player_fullscr_reset_osd_fade(TRUE);
    else
        mmi_mtv_player_fullscr_reset_osd_fade(FALSE);
    gdi_lcd_blt(mtv_player_p->preview_layer_handle, mtv_player_p->osd_layer_handle, mtv_player_p->dls_layer_handle, 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_key_6_press
 * DESCRIPTION
 *  mobile tv player key 6 pressed handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_key_6_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->is_changing_channel_by_key = TRUE;

    mtv_player_p->change_to_channel = (mtv_player_p->change_to_channel*10 + 6) % 100;
    gui_cancel_timer(mmi_mtv_player_jump_to_channel);
    gui_start_timer(MMI_MTV_JUMP_TO_CHANNEL_DELAY, mmi_mtv_player_jump_to_channel);

    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
        mmi_mtv_player_fullscr_reset_osd_fade(TRUE);
    else
        mmi_mtv_player_fullscr_reset_osd_fade(FALSE);
    gdi_lcd_blt(mtv_player_p->preview_layer_handle, mtv_player_p->osd_layer_handle, mtv_player_p->dls_layer_handle, 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_key_7_press
 * DESCRIPTION
 *  mobile tv player key 7 pressed handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_key_7_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->is_changing_channel_by_key = TRUE;

    mtv_player_p->change_to_channel = (mtv_player_p->change_to_channel*10 + 7) % 100;
    gui_cancel_timer(mmi_mtv_player_jump_to_channel);
    gui_start_timer(MMI_MTV_JUMP_TO_CHANNEL_DELAY, mmi_mtv_player_jump_to_channel);

    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
        mmi_mtv_player_fullscr_reset_osd_fade(TRUE);
    else
        mmi_mtv_player_fullscr_reset_osd_fade(FALSE);
    gdi_lcd_blt(mtv_player_p->preview_layer_handle, mtv_player_p->osd_layer_handle, mtv_player_p->dls_layer_handle, 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_key_8_press
 * DESCRIPTION
 *  mobile tv player key 8 pressed handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_key_8_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->is_changing_channel_by_key = TRUE;

    mtv_player_p->change_to_channel = (mtv_player_p->change_to_channel*10 + 8) % 100;
    gui_cancel_timer(mmi_mtv_player_jump_to_channel);
    gui_start_timer(MMI_MTV_JUMP_TO_CHANNEL_DELAY, mmi_mtv_player_jump_to_channel);

    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
        mmi_mtv_player_fullscr_reset_osd_fade(TRUE);
    else
        mmi_mtv_player_fullscr_reset_osd_fade(FALSE);
    gdi_lcd_blt(mtv_player_p->preview_layer_handle, mtv_player_p->osd_layer_handle, mtv_player_p->dls_layer_handle, 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_key_9_press
 * DESCRIPTION
 *  mobile tv player key 9 pressed handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_key_9_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->is_changing_channel_by_key = TRUE;

    mtv_player_p->change_to_channel = (mtv_player_p->change_to_channel*10 + 9) % 100;
    gui_cancel_timer(mmi_mtv_player_jump_to_channel);
    gui_start_timer(MMI_MTV_JUMP_TO_CHANNEL_DELAY, mmi_mtv_player_jump_to_channel);

    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
        mmi_mtv_player_fullscr_reset_osd_fade(TRUE);
    else
        mmi_mtv_player_fullscr_reset_osd_fade(FALSE);
    gdi_lcd_blt(mtv_player_p->preview_layer_handle, mtv_player_p->osd_layer_handle, mtv_player_p->dls_layer_handle, 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_key_0_press
 * DESCRIPTION
 *  mobile tv player key 0 pressed handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_key_0_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->is_changing_channel_by_key = TRUE;

    mtv_player_p->change_to_channel = (mtv_player_p->change_to_channel*10) % 100;
    gui_cancel_timer(mmi_mtv_player_jump_to_channel);
    gui_start_timer(MMI_MTV_JUMP_TO_CHANNEL_DELAY, mmi_mtv_player_jump_to_channel);

    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
        mmi_mtv_player_fullscr_reset_osd_fade(TRUE);
    else
        mmi_mtv_player_fullscr_reset_osd_fade(FALSE);
    gdi_lcd_blt(mtv_player_p->preview_layer_handle, mtv_player_p->osd_layer_handle, mtv_player_p->dls_layer_handle, 0);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_jump_to_channel
 * DESCRIPTION
 *  mobile tv player : jump to channel input by keypad.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_jump_to_channel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[20];
    S8 buffer[25];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->is_changing_channel_by_key = FALSE;
    if (mtv_player_p->change_to_channel > 0 
        && mtv_player_p->change_to_channel <= mtv_player_p->setting.num_services
        && (mtv_player_p->change_to_channel - 1) != mtv_player_p->setting.selected_channel)
    {
        MTV_ENTER_STATE(player,MMI_MTV_PLAYER,MTV_PLAYER_STOPPED);    
        MTV_ENTER_STATE(kernel,MMI_MTV_KERNEL,MTV_KERNEL_OPENED);

        mtv_player_p->setting.selected_channel = mtv_player_p->change_to_channel - 1;

        mmi_mtv_player_clear_dls_layer();
        MTV_ENTER_STATE(kernel,MMI_MTV_KERNEL,MTV_KERNEL_INIT);

        sprintf((PS8) buffer, "Channel %2d", mtv_player_p->change_to_channel);
        mmi_asc_to_ucs2((PS8) str_buf, (PS8) buffer);
        //mmi_ucs2cpy((PS8) str_buf, (PS8) L"Channel %d", mtv_player_p->change_to_channel);

        mmi_mtv_player_set_hint(
            (PS8) str_buf,
            (PS8) NULL,
            MMI_MOBILE_TV_PLAYER_HINT_POPUP_FADE_TIME);        
   
        if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
            mmi_mtv_player_fullscr_reset_osd_fade(TRUE);
        else
            mmi_mtv_player_fullscr_reset_osd_fade(FALSE);
        gdi_lcd_blt(mtv_player_p->preview_layer_handle, mtv_player_p->osd_layer_handle, mtv_player_p->dls_layer_handle, 0);
    }

    /* reset "change_to_channel" variable */
    mtv_player_p->change_to_channel = 0; 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_draw_osd
 * DESCRIPTION
 *  mobile tv player draw osd handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_init_icon_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #define INIT_OSD_TOUCH_ICON(a,A)\
    do {\
        if(mtv_player_p->active_osd_cntx_p->##a##.is_show)\
        {\
            gdi_image_get_dimension_id((U16)(IMG_ID_MTV_PLAYER_##A##_UP),\
                                        &(mtv_player_p->active_osd_cntx_p->##a##.width),\
                                        &(mtv_player_p->active_osd_cntx_p->##a##.height)) ;\
        }\
    }while(0)


    INIT_OSD_TOUCH_ICON(play,PLAY);
    INIT_OSD_TOUCH_ICON(record,RECORD);
    if(mtv_player_p->active_osd_cntx_p->play_speed.is_show)
    {
        gdi_image_get_dimension_id((U16)(IMG_ID_MTV_PLAYER_PLAY_SPEED_10X),
                                    &(mtv_player_p->active_osd_cntx_p->play_speed.width),
                                    &(mtv_player_p->active_osd_cntx_p->play_speed.height)) ;
    }

    if(mtv_player_p->active_osd_cntx_p->channel_number.is_show)
    {
        gdi_image_get_dimension_id((U16)(IMG_ID_MTV_PLAYER_NUM_0),
                                    &(mtv_player_p->active_osd_cntx_p->channel_number.width),
                                    &(mtv_player_p->active_osd_cntx_p->channel_number.height)) ;
    }

    INIT_OSD_TOUCH_ICON(fullscreen,FULLSCREEN);
    INIT_OSD_TOUCH_ICON(forward,FORWARD);
    INIT_OSD_TOUCH_ICON(rewind,REWIND);
    INIT_OSD_TOUCH_ICON(vol_inc,VOL_INC);
    INIT_OSD_TOUCH_ICON(vol_dec,VOL_DEC);
    INIT_OSD_TOUCH_ICON(channel_next,CHANNEL_NEXT);
    INIT_OSD_TOUCH_ICON(channel_prev,CHANNEL_PREV);

    if(mtv_player_p->active_osd_cntx_p->ts_bar.is_show)
    {
        if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
        {
            mtv_player_p->active_osd_cntx_p->ts_bar.offset_x = TIMESHIFT_BAR_OFFSET_X;
            mtv_player_p->active_osd_cntx_p->ts_bar.offset_y = TIMESHIFT_BAR_OFFSET_Y;
        }
        else
        {
            mtv_player_p->active_osd_cntx_p->ts_bar.offset_x = TIMESHIFT_BAR_OFFSET_X_ROTATED;
            mtv_player_p->active_osd_cntx_p->ts_bar.offset_y = TIMESHIFT_BAR_OFFSET_Y_ROTATED;
        }
            
        gdi_image_get_dimension_id((U16)(IMG_ID_MTV_PROGRESS_BAR),
                                    &(mtv_player_p->active_osd_cntx_p->ts_bar.width),
                                    &(mtv_player_p->active_osd_cntx_p->ts_bar.height)) ;
    }

    if(mtv_player_p->active_osd_cntx_p->ts_ind.is_show)
    {
        gdi_image_get_dimension_id((U16)(IMG_ID_MTV_PROGRESS_IND),
                                    &(mtv_player_p->active_osd_cntx_p->ts_ind.width),
                                    &(mtv_player_p->active_osd_cntx_p->ts_ind.height)) ;
    }

}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_ts_bar_icon_press
 * DESCRIPTION
 *  mobile tv player channel_prev icon release handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_ts_bar_icon_press(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_width;
    S16 ts_idx;
    S16 ts_buf_idx;
    S16 offset_x,offset_y;
    mdi_mtv_player_status_struct status;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->touch_object = MTV_PLAYER_TOUCH_TS_BAR;
    gui_start_timer(300, mmi_mtv_player_switch_ts_bar);

    if (mtv_player_p->is_ts_bar_enable)
    {
        buf_width = mtv_player_p->active_osd_cntx_p->ts_bar.width/100;
        ts_idx = (mtv_player_p->max_delay - mtv_player_p->play_delay)*100/mtv_player_p->setting.max_timeshift_delay;
        ts_buf_idx = mtv_player_p->max_delay*100/mtv_player_p->setting.max_timeshift_delay;
                

        if ((mtv_player_p->max_delay > mtv_player_p->play_delay)// could rewind
            && x < ts_idx*buf_width)
        {
            mdi_mtv_player_get_status(mtv_player_p->mtv_handle, &status);

            mtv_player_p->max_delay = status.max_delay;
            mtv_player_p->play_delay = status.play_delay;
       
            mtv_player_p->play_delay+=2; 

            mdi_mtv_recorder_seek(mtv_player_p->mtv_handle,mtv_player_p->play_delay);
        }
        else if ((mtv_player_p->play_delay > 0)
            && x > ts_idx*buf_width)
        {
            mdi_mtv_player_get_status(mtv_player_p->mtv_handle, &status);

            mtv_player_p->max_delay = status.max_delay;
            mtv_player_p->play_delay = status.play_delay;

            mtv_player_p->play_delay-=2; 

            mdi_mtv_recorder_seek(mtv_player_p->mtv_handle,mtv_player_p->play_delay);
        }
        mtv_player_p->active_osd_cntx_p->channel_next.status = MTV_PLAYER_ICON_STATUS_CLICKED;
        mmi_mtv_player_fullscr_reset_osd_fade(FALSE);
        gdi_lcd_blt(mtv_player_p->preview_layer_handle, mtv_player_p->osd_layer_handle, mtv_player_p->dls_layer_handle, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_ts_bar_icon_release
 * DESCRIPTION
 *  mobile tv player channel_prev icon release handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_ts_bar_icon_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
        mmi_mtv_player_fullscr_reset_osd_fade(TRUE);

    gui_cancel_timer(mmi_mtv_player_switch_ts_bar);
    mtv_player_p->is_ts_bar_enable = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_touch_scr_hit_test
 * DESCRIPTION
 *  mobile tv player check if icon is pressed 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static BOOL mmi_mtv_player_touch_scr_hit_test(S32 pos_x, S32 pos_y, mtv_player_osd_icon_struct *touch_obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((pos_x >= touch_obj->offset_x) &&
        (pos_x < touch_obj->offset_x + touch_obj->width) &&
        (pos_y >= touch_obj->offset_y) && (pos_y < touch_obj->offset_y + touch_obj->height))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_pen_down_hdlr_fullscreen
 * DESCRIPTION
 *  mobile tv player pen down event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_pen_down_hdlr_fullscreen(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_mtv_player_fullscr_osd_show_up();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_pen_down_hdlr
 * DESCRIPTION
 *  mobile tv player pen down event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#define ICON_TOUCH_TEST(a,A)\
    do {\
        if(mtv_player_p->active_osd_cntx_p->##a##.status==MTV_PLAYER_ICON_STATUS_ENABLE)\
        {\
            if(mmi_mtv_player_touch_scr_hit_test(pos.x, pos.y, &(mtv_player_p->active_osd_cntx_p->##a##)) == MMI_TRUE)\
            {\
                mmi_mtv_player_##a##_icon_press();\
                mtv_player_p->touch_object = MTV_PLAYER_TOUCH_##A;\
                return;\
            }\
        }\
    } while(0)
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        S32 tmp;

        tmp = pos.x;
        pos.x = pos.y;
        pos.y = (LCD_WIDTH - 1) - tmp;
    }

    mtv_player_p->is_pen_down = TRUE;
    mtv_player_p->pen_down_x = pos.x;
    mtv_player_p->pen_down_y = pos.y;
    mtv_player_p->touch_object = MTV_PLAYER_TOUCH_NONE;

    /* LSK */
    if (mmi_mtv_player_touch_scr_hit_test(pos.x, pos.y, &(mtv_player_p->lsk)) == MMI_TRUE)
    {   
        mmi_mtv_player_lsk_press();
        return;
    }

    /* RSK */
    if (mmi_mtv_player_touch_scr_hit_test(pos.x, pos.y, &(mtv_player_p->rsk)) == MMI_TRUE)
    {
        mmi_mtv_player_rsk_press();
        return;
    }

    ICON_TOUCH_TEST(play,PLAY);
    ICON_TOUCH_TEST(record,RECORD);
    ICON_TOUCH_TEST(play_speed,PLAY_SPEED);
    ICON_TOUCH_TEST(fullscreen,FULLSCREEN);
    ICON_TOUCH_TEST(forward,FORWARD);
    ICON_TOUCH_TEST(rewind,REWIND);
    ICON_TOUCH_TEST(vol_inc,VOL_INC);
    ICON_TOUCH_TEST(vol_dec,VOL_DEC);
    ICON_TOUCH_TEST(channel_next,CHANNEL_NEXT);
    ICON_TOUCH_TEST(channel_prev,CHANNEL_PREV);

    /* bar */
    if(mtv_player_p->active_osd_cntx_p->ts_bar.status==MTV_PLAYER_ICON_STATUS_ENABLE)
    {
        if(mmi_mtv_player_touch_scr_hit_test(pos.x, pos.y, &(mtv_player_p->active_osd_cntx_p->ts_bar)) == MMI_TRUE)
        {
            mmi_mtv_player_ts_bar_icon_press(pos.x,pos.y);
            return;
        }
    }
    


}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_pen_up_hdlr
 * DESCRIPTION
 *  mobile tv player pen up event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->is_pen_down = FALSE;

    switch(mtv_player_p->touch_object)
    {
        case MTV_PLAYER_TOUCH_RSK:
            mmi_mtv_player_rsk_release();
            break;
        case MTV_PLAYER_TOUCH_LSK:
            mmi_mtv_player_lsk_release();
            break;
        case MTV_PLAYER_TOUCH_PLAY:
            mmi_mtv_player_play_icon_release();
            break;
        case MTV_PLAYER_TOUCH_RECORD:
            mmi_mtv_player_record_icon_release();
            break;
        case MTV_PLAYER_TOUCH_PLAY_SPEED:
            mmi_mtv_player_play_speed_icon_release();
            break;
        case MTV_PLAYER_TOUCH_FULLSCREEN:
            mmi_mtv_player_fullscreen_icon_release();
            break;
        case MTV_PLAYER_TOUCH_FORWARD:
            mmi_mtv_player_forward_icon_release();
            break;
        case MTV_PLAYER_TOUCH_REWIND:
            mmi_mtv_player_rewind_icon_release();
            break;
        case MTV_PLAYER_TOUCH_VOL_INC:
            mmi_mtv_player_vol_inc_icon_release();
            break;
        case MTV_PLAYER_TOUCH_VOL_DEC:
            mmi_mtv_player_vol_dec_icon_release();
            break;
        case MTV_PLAYER_TOUCH_CHANNEL_NEXT:
            mmi_mtv_player_channel_next_icon_release();
            break;
        case MTV_PLAYER_TOUCH_CHANNEL_PREV:
            mmi_mtv_player_channel_prev_icon_release();
            break;
        default:
            break;        
    }

    mtv_player_p->touch_object = MTV_PLAYER_TOUCH_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_pen_move_hdlr
 * DESCRIPTION
 *  mobile tv player pen move event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#define ICON_MOVE_TEST(a,A)\
    do {\
        if(mmi_mtv_player_touch_scr_hit_test(pos.x, pos.y, &(mtv_player_p->active_osd_cntx_p->##a##)) != MMI_TRUE)\
        {\
            mtv_player_p->active_osd_cntx_p->##a##.status = MTV_PLAYER_ICON_STATUS_ENABLE;\
            mmi_mtv_player_draw_osd();\
            gdi_lcd_blt(mtv_player_p->preview_layer_handle, mtv_player_p->osd_layer_handle, mtv_player_p->dls_layer_handle, 0);\
            mtv_player_p->touch_object = MTV_PLAYER_TOUCH_NONE;\
            return;\
        }\
    } while(0)
#define ICON_MOVE_TEST2(a,A)\
    do {\
        if(mmi_mtv_player_touch_scr_hit_test(pos.x, pos.y, &(mtv_player_p->active_osd_cntx_p->##a##)) != MMI_TRUE)\
        {\
            mtv_player_p->active_osd_cntx_p->##a##.status = MTV_PLAYER_ICON_STATUS_ENABLE;\
            mmi_mtv_player_draw_osd();\
            gdi_lcd_blt(mtv_player_p->preview_layer_handle, mtv_player_p->osd_layer_handle, mtv_player_p->dls_layer_handle, 0);\
            mtv_player_p->touch_object = MTV_PLAYER_TOUCH_NONE;\
            mmi_mtv_player_##a##_icon_release();\
            return;\
        }\
    } while(0)


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        S32 tmp;

        tmp = pos.x;
        pos.x = pos.y;
        pos.y = (LCD_WIDTH - 1) - tmp;
    }

    switch(mtv_player_p->touch_object)
    {
        case MTV_PLAYER_TOUCH_RSK:
            if (mmi_mtv_player_touch_scr_hit_test(pos.x, pos.y, &(mtv_player_p->rsk)) != MMI_TRUE)
            {   
                mtv_player_p->rsk.status = MTV_PLAYER_ICON_STATUS_ENABLE;
                mtv_player_p->touch_object = MTV_PLAYER_TOUCH_NONE;
                mmi_mtv_player_draw_osd();
                gdi_lcd_blt(mtv_player_p->preview_layer_handle, mtv_player_p->osd_layer_handle, mtv_player_p->dls_layer_handle, 0);
                return;
            }
            break;
        case MTV_PLAYER_TOUCH_LSK:
            if (mmi_mtv_player_touch_scr_hit_test(pos.x, pos.y, &(mtv_player_p->lsk)) != MMI_TRUE)
            {   
                mtv_player_p->lsk.status = MTV_PLAYER_ICON_STATUS_ENABLE;
                mtv_player_p->touch_object = MTV_PLAYER_TOUCH_NONE;
                mmi_mtv_player_draw_osd();
                gdi_lcd_blt(mtv_player_p->preview_layer_handle, mtv_player_p->osd_layer_handle, mtv_player_p->dls_layer_handle, 0);
                return;
            }
            break;
        case MTV_PLAYER_TOUCH_PLAY:
            ICON_MOVE_TEST(play,PLAY);
            break;
        case MTV_PLAYER_TOUCH_RECORD:
            ICON_MOVE_TEST(record,RECORD);
            break;
        case MTV_PLAYER_TOUCH_PLAY_SPEED:
            ICON_MOVE_TEST(play_speed,PLAY_SPEED);
            break;
        case MTV_PLAYER_TOUCH_FULLSCREEN:
            ICON_MOVE_TEST(fullscreen,FULLSCREEN);
            break;
        case MTV_PLAYER_TOUCH_FORWARD:
            ICON_MOVE_TEST(forward,FORWARD);
            break;
        case MTV_PLAYER_TOUCH_REWIND:
            ICON_MOVE_TEST(rewind,REWIND);
            break;
        case MTV_PLAYER_TOUCH_VOL_INC:
            ICON_MOVE_TEST2(vol_inc,VOL_INC);
            break;
        case MTV_PLAYER_TOUCH_VOL_DEC:
            ICON_MOVE_TEST2(vol_dec,VOL_DEC);
            break;
        case MTV_PLAYER_TOUCH_CHANNEL_NEXT:
            ICON_MOVE_TEST2(channel_next,CHANNEL_NEXT);
            break;
        case MTV_PLAYER_TOUCH_CHANNEL_PREV:
            ICON_MOVE_TEST2(channel_prev,CHANNEL_PREV);
            break;
        case MTV_PLAYER_TOUCH_TS_BAR:
            if(mmi_mtv_player_touch_scr_hit_test(pos.x, pos.y, &(mtv_player_p->active_osd_cntx_p->ts_bar)) != MMI_TRUE)
            {
                mtv_player_p->touch_object = MTV_PLAYER_TOUCH_NONE;
                mmi_mtv_player_ts_bar_icon_release();
                return;
            }
            else
                mmi_mtv_player_ts_bar_icon_press(pos.x,pos.y);
        default:
            break;        
    }
    
#undef ICON_MOVE_TEST

}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_draw_style_text
 * DESCRIPTION
 *  draw style text 
 * PARAMETERS
 *  str          [IN]        String to be draw    
 *  offset_x     [IN]        x position
 *  offset_y     [IN]        y position
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_draw_style_text(PS8 str, S32 offset_x, S32 offset_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (r2lMMIFlag)
    {
        offset_x += gui_get_string_width((UI_string_type) str);
    }

    gui_move_text_cursor(offset_x, offset_y);
    gui_set_text_color(gui_color(67,87,153));
    gui_set_text_border_color(gui_color(255,255,255));
    gui_print_bordered_text((UI_string_type) str);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_draw_osd_softkey
 * DESCRIPTION
 *  mobile tv player draw osd softkey handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_draw_osd_softkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 lsk_offset_x = 0;
    S32 lsk_offset_y = 0;
    S32 rsk_offset_x = 0;
    S32 rsk_offset_y = 0;
    S32 str_width;
    S32 str_height;
    PS8 str_ptr;
    U16 lsk_id = 0;
    U16 rsk_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsk_id = STR_GLOBAL_BACK;
    lsk_id = STR_GLOBAL_OPTIONS;

    gdi_layer_reset_clip();
    gdi_layer_reset_text_clip();

    /* if is fullscreen display, or normal display but without mmi_softkey */
    gui_set_font(&MMI_medium_font);

    /* lsk */
    str_ptr = (PS8) GetString(lsk_id);

    gui_measure_string((UI_string_type) str_ptr, &str_width, &str_height);

    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        lsk_offset_x = MMI_ROTATED_BUTTON_BAR_X + (MMI_ROTATED_BUTTON_BAR_WIDTH - str_width) - 1;
        lsk_offset_y = MMI_ROTATED_BUTTON_BAR_Y + MMI_ROTATED_BUTTON_BAR_HEIGHT - str_height - 2;
    }
    else
    {
        lsk_offset_x = 2;
        lsk_offset_y =
            (LCD_HEIGHT - MMI_button_bar_height) +
            ((MMI_button_bar_height - str_height) >> 1) + 1;
    }

    if (mtv_player_p->lsk.status == MTV_PLAYER_ICON_STATUS_CLICKED)
    {
        lsk_offset_x++;
        lsk_offset_y++;
    }

    mmi_mtv_player_draw_style_text(
        str_ptr,
        lsk_offset_x ,
        lsk_offset_y );


    mtv_player_p->lsk.offset_x = lsk_offset_x;
    mtv_player_p->lsk.offset_y = lsk_offset_y;
    mtv_player_p->lsk.width = str_width;
    mtv_player_p->lsk.height = str_height;

    /* rsk */
    str_ptr = (PS8) GetString(rsk_id);

    gui_measure_string((UI_string_type) str_ptr, &str_width, &str_height);

    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        rsk_offset_x = MMI_ROTATED_BUTTON_BAR_X + (MMI_ROTATED_BUTTON_BAR_WIDTH - str_width) - 1;
        rsk_offset_y = 2;
    }
    else
    {
        rsk_offset_x = (LCD_WIDTH- str_width - 2);
        rsk_offset_y =
            (LCD_HEIGHT - MMI_button_bar_height) +
            ((MMI_button_bar_height - str_height) >> 1) + 1;
    }

    if (mtv_player_p->rsk.status == MTV_PLAYER_ICON_STATUS_CLICKED)
    {
        rsk_offset_x++;
        rsk_offset_y++;
    }

    mmi_mtv_player_draw_style_text(
        str_ptr,
        rsk_offset_x,
        rsk_offset_y);

    mtv_player_p->rsk.offset_x = rsk_offset_x;
    mtv_player_p->rsk.offset_y = rsk_offset_y;
    mtv_player_p->rsk.width = str_width;
    mtv_player_p->rsk.height = str_height;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_fullscr_osd_show_up
 * DESCRIPTION
 *  fade fullscr osd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_fullscr_osd_show_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_mtv_player_register_key_hdlr();
    mmi_mtv_player_fullscr_reset_osd_fade(TRUE);
    gdi_lcd_blt(mtv_player_p->preview_layer_handle, mtv_player_p->osd_layer_handle, mtv_player_p->dls_layer_handle, 0);
    ClearKeyEvents();
}



/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_fullscr_osd_fade_cyclic
 * DESCRIPTION
 *  fade fullscr osd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_fullscr_osd_fade_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset fullscreen osd fade out timer */
    if (mtv_player_p->fullscr_osd_opacity > MMI_MOBILE_TV_PLAYER_OSD_FADE_OUT_VALUE)
    {
        mtv_player_p->fullscr_osd_opacity -= MMI_MOBILE_TV_PLAYER_OSD_FADE_OUT_VALUE;

        gui_start_timer(100, mmi_mtv_player_fullscr_osd_fade_cyclic);
    }
    else
    {
        mtv_player_p->lsk.status = MTV_PLAYER_ICON_STATUS_ENABLE;
        mtv_player_p->rsk.status = MTV_PLAYER_ICON_STATUS_ENABLE;
        
        mtv_player_p->fullscr_osd_opacity = 0;

        /* if totally fade out, use any key to wake up */
        ClearInputEventHandler(MMI_DEVICE_ALL);
    
        SetKeyHandler(mmi_mtv_player_fullscr_osd_show_up, KEY_1, KEY_EVENT_UP);
        SetKeyHandler(mmi_mtv_player_fullscr_osd_show_up, KEY_2, KEY_EVENT_UP);
        SetKeyHandler(mmi_mtv_player_fullscr_osd_show_up, KEY_3, KEY_EVENT_UP);
        SetKeyHandler(mmi_mtv_player_fullscr_osd_show_up, KEY_4, KEY_EVENT_UP);
        SetKeyHandler(mmi_mtv_player_fullscr_osd_show_up, KEY_5, KEY_EVENT_UP);
        SetKeyHandler(mmi_mtv_player_fullscr_osd_show_up, KEY_6, KEY_EVENT_UP);
        SetKeyHandler(mmi_mtv_player_fullscr_osd_show_up, KEY_7, KEY_EVENT_UP);
        SetKeyHandler(mmi_mtv_player_fullscr_osd_show_up, KEY_8, KEY_EVENT_UP);
        SetKeyHandler(mmi_mtv_player_fullscr_osd_show_up, KEY_9, KEY_EVENT_UP);
        SetKeyHandler(mmi_mtv_player_fullscr_osd_show_up, KEY_0, KEY_EVENT_UP);
        SetKeyHandler(mmi_mtv_player_fullscr_osd_show_up, KEY_POUND, KEY_EVENT_UP);
        SetKeyHandler(mmi_mtv_player_fullscr_osd_show_up, KEY_STAR, KEY_EVENT_UP);
        SetKeyHandler(mmi_mtv_player_fullscr_osd_show_up, KEY_LSK, KEY_EVENT_UP);
        SetKeyHandler(mmi_mtv_player_fullscr_osd_show_up, KEY_RSK, KEY_EVENT_UP);
        SetKeyHandler(mmi_mtv_player_fullscr_osd_show_up, KEY_ENTER, KEY_EVENT_UP);
        SetKeyHandler(mmi_mtv_player_fullscr_osd_show_up, KEY_LEFT_ARROW, KEY_EVENT_UP);
        SetKeyHandler(mmi_mtv_player_fullscr_osd_show_up, KEY_RIGHT_ARROW, KEY_EVENT_UP);
        SetKeyHandler(mmi_mtv_player_fullscr_osd_show_up, KEY_UP_ARROW, KEY_EVENT_UP);
        SetKeyHandler(mmi_mtv_player_fullscr_osd_show_up, KEY_DOWN_ARROW, KEY_EVENT_UP);
        SetKeyHandler(mmi_mtv_player_fullscr_osd_show_up, KEY_CLEAR, KEY_EVENT_UP);

        SetKeyHandler(mmi_mtv_player_fullscr_osd_show_up, KEY_VOL_UP, KEY_EVENT_UP);
        SetKeyHandler(mmi_mtv_player_fullscr_osd_show_up, KEY_VOL_DOWN, KEY_EVENT_UP);

        /* start still use for toggle screen */
        SetKeyHandler(mmi_mtv_player_play_speed_icon_release, KEY_STAR, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
        wgui_register_pen_down_handler(mmi_mtv_player_pen_down_hdlr_fullscreen);
#endif
    }

    gdi_layer_push_and_set_active(mtv_player_p->osd_layer_handle);
    gdi_layer_set_opacity(TRUE, (U8) mtv_player_p->fullscr_osd_opacity);
    gdi_layer_pop_and_restore_active();

    gdi_lcd_blt(mtv_player_p->preview_layer_handle, mtv_player_p->osd_layer_handle, mtv_player_p->dls_layer_handle, 0);

}



/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_fullscr_reset_osd_fade
 * DESCRIPTION
 *  fade fullscr osd
 * PARAMETERS
 *  sleep       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_fullscr_reset_osd_fade(BOOL sleep)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_mtv_player_fullscr_osd_fade_cyclic);

    if (mtv_player_p->fullscr_osd_opacity != 255)
    {
        U16 prev_fullscr_osd_opacity = mtv_player_p->fullscr_osd_opacity;
    
        mtv_player_p->fullscr_osd_opacity = 255;

        /* fade in from totally trasnparent */
        if (prev_fullscr_osd_opacity == 0)
        {
            if (!PLAYER_STATE_IN(MTV_PLAYER_STOPPED))
                mmi_mtv_player_player_update_cyclic();
            else
                mmi_mtv_player_draw_osd();
        }

        gdi_layer_push_and_set_active(mtv_player_p->osd_layer_handle);
        gdi_layer_set_opacity(TRUE, (U8) mtv_player_p->fullscr_osd_opacity);
        gdi_layer_pop_and_restore_active();
    }
    else
        mmi_mtv_player_draw_osd();


    if (sleep)
    {
        /* start fade out timer */
        gui_start_timer(MMI_MOBILE_TV_PLAYER_OSD_FADE_OUT_TIME, mmi_mtv_player_fullscr_osd_fade_cyclic);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_draw_osd_and_blt_check
 * DESCRIPTION
 *  mobile tv player draw osd handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_draw_osd_and_blt_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (GetActiveScreenId() == SCR_ID_MOBILE_TV_PLAYER_APP)
    {
        mmi_mtv_player_draw_osd();
        gdi_lcd_blt(mtv_player_p->preview_layer_handle, mtv_player_p->osd_layer_handle, mtv_player_p->dls_layer_handle, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_draw_dls
 * DESCRIPTION
 *  mobile tv player draw dls handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_draw_dls(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(mtv_player_p->dls_layer_handle);
    gdi_layer_toggle_double();
    /* toggle double buffer */
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);

    /*************************
     * Dynamic label
     *************************/
    if (mtv_player_p->label_str != NULL && mtv_player_p->scrolling_label_state == MTV_PLAYER_SCROLLING_TEXT_ON)
    {
        S32 str_width, str_height;
        gui_measure_string((UI_string_type) mtv_player_p->label_str, &str_width, &str_height);
        gdi_draw_solid_rect(0,
                            0,
                            0+mtv_player_p->active_osd_cntx_p->title.width,
                            0+mtv_player_p->active_osd_cntx_p->title.height,
                            GDI_COLOR_TRANSPARENT);

        offset_x = (mtv_player_p->active_osd_cntx_p->title.width - str_width)>>1;

        mmi_mtv_player_draw_style_text(
            mtv_player_p->label_str,
            0+offset_x,
            0);
    }

    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_draw_osd
 * DESCRIPTION
 *  mobile tv player draw osd handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_draw_osd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 offset = 0;
    U16 play_speed_id = 0;
    U16 play_pause_id;
    U16 volume_id = 0;
    S16 tmp_digit;
    S16 tmp_channel_number;
    S16 position_x;
    S16 ts_idx;
    S16 ts_buf_idx;

    S8 i = 0;
    S8 buf_width;
    S16 offset_x = 0,offset_y = 0;
    U16 bar_id=0,ind_id=0,buf_id=0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    #define DRAW_OSD_ICON(a,A)\
    do {\
    if(mtv_player_p->active_osd_cntx_p->##a##.is_show == TRUE)\
    {\
        if(mtv_player_p->active_osd_cntx_p->##a##.status == MTV_PLAYER_ICON_STATUS_ENABLE )\
        {\
            gdi_image_draw_id(mtv_player_p->active_osd_cntx_p->##a##.offset_x,mtv_player_p->active_osd_cntx_p->##a##.offset_y,(U16)(IMG_ID_MTV_PLAYER_##A##_UP+offset));\
        }\
        else if(mtv_player_p->active_osd_cntx_p->##a##.status == MTV_PLAYER_ICON_STATUS_CLICKED )\
        {\
            gdi_image_draw_id(mtv_player_p->active_osd_cntx_p->##a##.offset_x,mtv_player_p->active_osd_cntx_p->##a##.offset_y,(U16)(IMG_ID_MTV_PLAYER_##A##_DOWN+offset));\
        }\
    }\
    } while(0)


    gdi_layer_push_and_set_active(mtv_player_p->osd_layer_handle);
    gdi_layer_toggle_double();
    /* toggle double buffer */
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);

    buf_width = mtv_player_p->active_osd_cntx_p->ts_bar.width/100;

    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {
 
        gdi_image_draw_id(0, 0, IMG_ID_MOBILE_TV_PLAYER_BG);
        if (mtv_player_p->is_initializing & mtv_player_p->anim_handle == 0)
            gdi_anim_draw_id(100,100,IMG_ID_MOBILE_TV_LOADING,&mtv_player_p->anim_handle);
   
        offset = 0;
        play_speed_id = IMG_ID_MTV_PLAYER_PLAY_SPEED_10X;
        volume_id = IMG_ID_MTV_PLAYER_VOL_LEVEL_1;
        offset_x = TIMESHIFT_BAR_OFFSET_X;
        offset_y = TIMESHIFT_BAR_OFFSET_Y;
        bar_id = IMG_ID_MTV_PROGRESS_BAR;
        ind_id = IMG_ID_MTV_PROGRESS_IND;
        buf_id = IMG_ID_MTV_PROGRESS_FILL;        
    }
    else if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
    {
        gdi_image_draw_id(5, 193, IMG_ID_MOBILE_TV_PLAYER_BG_H);
        if (mtv_player_p->is_initializing & mtv_player_p->anim_handle == 0)
            gdi_anim_draw_id(100,100,IMG_ID_MOBILE_TV_LOADING,&mtv_player_p->anim_handle);

        offset = 2;
        play_speed_id = IMG_ID_MTV_PLAYER_PLAY_SPEED_10X_H;
        volume_id = IMG_ID_MTV_PLAYER_VOL_H_LEVEL_1;
        offset_x = TIMESHIFT_BAR_OFFSET_X_ROTATED;
        offset_y = TIMESHIFT_BAR_OFFSET_Y_ROTATED;
        bar_id = IMG_ID_MTV_PROGRESS_BAR_H;
        ind_id = IMG_ID_MTV_PROGRESS_IND_H;
        buf_id = IMG_ID_MTV_PROGRESS_FILL_H;
    }

    /*************************
     * Soft Key 
     *************************/
    mmi_mtv_player_draw_osd_softkey();


    /*************************
     * Control Panel
     *************************/
    /* play icon */
    if(mtv_player_p->active_osd_cntx_p->play.is_show == TRUE)
    {
        if (PLAYER_STATE_IN(MTV_PLAYER_PAUSE))
            play_pause_id = IMG_ID_MTV_PLAYER_PLAY_UP;
        else
            play_pause_id = IMG_ID_MTV_PLAYER_PAUSE_UP;
   
        if(mtv_player_p->active_osd_cntx_p->play.status == MTV_PLAYER_ICON_STATUS_ENABLE )
        {
            gdi_image_draw_id(mtv_player_p->active_osd_cntx_p->play.offset_x,mtv_player_p->active_osd_cntx_p->play.offset_y,(U16)(play_pause_id+offset));
        }
        else if(mtv_player_p->active_osd_cntx_p->play.status == MTV_PLAYER_ICON_STATUS_CLICKED )
        {
            gdi_image_draw_id(mtv_player_p->active_osd_cntx_p->play.offset_x,mtv_player_p->active_osd_cntx_p->play.offset_y,(U16)(play_pause_id+offset+1));
        }
    }

    /* record icon */
    if(mtv_player_p->active_osd_cntx_p->record.is_show == TRUE)
    {
        if (RECORDER_STATE_IN(MTV_RECORDER_RECORD))
            play_pause_id = IMG_ID_MTV_PLAYER_STOP_UP;
        else
            play_pause_id = IMG_ID_MTV_PLAYER_RECORD_UP;
   
        if(mtv_player_p->active_osd_cntx_p->record.status == MTV_PLAYER_ICON_STATUS_ENABLE )
        {
            gdi_image_draw_id(mtv_player_p->active_osd_cntx_p->record.offset_x,mtv_player_p->active_osd_cntx_p->record.offset_y,(U16)(play_pause_id+offset));
        }
        else if(mtv_player_p->active_osd_cntx_p->record.status == MTV_PLAYER_ICON_STATUS_CLICKED )
        {
            gdi_image_draw_id(mtv_player_p->active_osd_cntx_p->record.offset_x,mtv_player_p->active_osd_cntx_p->record.offset_y,(U16)(play_pause_id+offset+1));
        }
    }

    /* timeshift bar */
    ts_idx = (mtv_player_p->max_delay - mtv_player_p->play_delay)*100/mtv_player_p->setting.max_timeshift_delay;
    ts_buf_idx = mtv_player_p->max_delay*100/mtv_player_p->setting.max_timeshift_delay;
    
    gdi_image_draw_id (offset_x,offset_y, bar_id);
    /* draw buffer */
    for (i=0;i<ts_buf_idx;i++)
    {
        gdi_image_draw_id(offset_x+i*buf_width,offset_y,buf_id);
    }

    /* draw indicator */
    gdi_image_draw_id(offset_x+ts_idx*buf_width,offset_y,ind_id);
 

    DRAW_OSD_ICON(fullscreen,FULLSCREEN);
    DRAW_OSD_ICON(vol_inc,VOL_INC);
    DRAW_OSD_ICON(vol_dec,VOL_DEC);
    DRAW_OSD_ICON(channel_next,CHANNEL_NEXT);
    DRAW_OSD_ICON(channel_prev,CHANNEL_PREV);
    DRAW_OSD_ICON(forward,FORWARD);
    DRAW_OSD_ICON(rewind,REWIND);    
    /* play speed */
    if(mtv_player_p->active_osd_cntx_p->play_speed.is_show == TRUE)
    {
        gdi_image_draw_id(mtv_player_p->active_osd_cntx_p->play_speed.offset_x,
                          mtv_player_p->active_osd_cntx_p->play_speed.offset_y,
                          (U16)(play_speed_id+mtv_player_p->setting.play_speed));
    }

    /* volume level */
    gdi_image_draw_id(mtv_player_p->active_osd_cntx_p->volume.offset_x,
                      mtv_player_p->active_osd_cntx_p->volume.offset_y,
                      (U16)(volume_id + mtv_player_p->setting.vol_level));

    if (KERNEL_STATE_IN(MTV_KERNEL_READY))
    {
        gdi_image_draw_id(5,5,IMG_ID_MTV_PLAYER_SIGNAL_LEVEL_1 + mtv_player_p->signal_strength);
    }
    else
    {
        gdi_image_draw_id(5,5,IMG_ID_MTV_PLAYER_SIGNAL_LEVEL_1);
    }

    /*************************
     * Hint 
     *************************/
    if (mtv_player_p->is_show_hint == TRUE)
    {
        mmi_mtv_player_draw_hint();
    }


    /**************************
     * Channel Number
     *************************/
    position_x = mtv_player_p->active_osd_cntx_p->channel_number.offset_x;
    if (mtv_player_p->is_changing_channel_by_key == TRUE)
        tmp_channel_number = mtv_player_p->change_to_channel;
    else
        tmp_channel_number = mtv_player_p->setting.selected_channel + 1;
    do
    {
        tmp_digit = tmp_channel_number % 10;
        tmp_channel_number = tmp_channel_number / 10;

        gdi_image_draw_id(
            position_x,
            mtv_player_p->active_osd_cntx_p->channel_number.offset_y,
            (U16) (IMG_ID_MTV_PLAYER_NUM_0 + tmp_digit));
        position_x = position_x - mtv_player_p->active_osd_cntx_p->channel_number.width;
    } while (tmp_channel_number > 0);



    gdi_layer_pop_and_restore_active();

    #undef DRAW_OSD_ICON
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_app_mem_success_callback
 * DESCRIPTION
 *  mobile tv player app mem callback function, it is called after 
 *  succeed allocating memory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_app_mem_success_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->app_mem_pool 
        = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_MTV_PLAYER, MMI_MTV_PLAYER_APP_MEM_SIZE);

    /* It should provide enough memory */
    ASSERT(mtv_player_p->app_mem_pool != NULL); 
    mmi_mtv_player_entry_app_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_app_mem_stop_callback
 * DESCRIPTION
 *  callback function used by applib to free APP-Based Memory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_app_mem_stop_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Free Memory */
    mmi_mtv_player_deinit_adm_resource();
    ASSERT(mtv_player_p->app_mem_pool != NULL);

    /* free app-based memory */
    applib_mem_ap_free((void*)mtv_player_p->app_mem_pool);
    mtv_player_p->app_mem_pool = NULL;    

    /* Notify MMI that this application is already stopped */
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_MTV_PLAYER, KAL_TRUE);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_create_adm
 * DESCRIPTION
 *  Delete ADM memory pool and free memory allocated from ASM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_create_adm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef  __MTK_TARGET__
    /* Create MemoryPool */
    if (mtv_player_p->app_mem_pool != NULL && mtv_player_p->adm_pool_id == NULL)
    {
        mtv_player_p->adm_pool_id = kal_adm_create((void*)mtv_player_p->app_mem_pool, 
                                                    MMI_MTV_PLAYER_APP_MEM_SIZE, 
                                                    NULL, 
                                                    KAL_FALSE);
        ASSERT(mtv_player_p->adm_pool_id != NULL);   
    }
#endif /* __MTK_TARGET__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_delete_adm
 * DESCRIPTION
 *  callback function used by applib to free APP-Based Memory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_delete_adm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_status ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__ 
    if (mtv_player_p->adm_pool_id)
    {
        mmi_mtv_player_deinit_adm_resource();

        /* Delete ADM */
        ret = kal_adm_delete(mtv_player_p->adm_pool_id);

        ASSERT(ret == KAL_SUCCESS);
        mtv_player_p->adm_pool_id = NULL;
    }
#endif /* __MTK_TARGET__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_init_adm_resource
 * DESCRIPTION
 *  Delete ADM memory pool and free memory allocated from ASM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_init_adm_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef  __MTK_TARGET__
    if (mtv_player_p->preview_layer_buf_ptr == NULL)
    {
        mtv_player_p->preview_layer_buf_ptr = (U8*) kal_adm_alloc(mtv_player_p->adm_pool_id,
                                                                  MMI_MTV_PLAYER_PREVIEW_BUFFER_SIZE);
        ASSERT(mtv_player_p->preview_layer_buf_ptr != NULL);       

        result = gdi_layer_create_using_outside_memory(
            0,
            0,
            GDI_LCD_WIDTH,
            GDI_LCD_HEIGHT,
            &mtv_player_p->preview_layer_handle,
            (PU8) mtv_player_p->preview_layer_buf_ptr,
            MMI_MTV_PLAYER_PREVIEW_BUFFER_SIZE);

        ASSERT (result != GDI_FAILED);

        gdi_layer_push_and_set_active(mtv_player_p->preview_layer_handle);
    #ifdef GDI_USING_LAYER_BACKGROUND
        gdi_layer_set_background(GDI_COLOR_BLACK);
    #endif 
        gdi_layer_pop_and_restore_active();

    }
#else
    if (mtv_player_p->preview_layer_handle == GDI_LAYER_EMPTY_HANDLE)
    {
        result = gdi_layer_create_using_outside_memory(
            0,
            0,
            GDI_LCD_WIDTH,
            GDI_LCD_HEIGHT,
            &mtv_player_p->preview_layer_handle,
            (PU8) mtv_player_p->preview_layer_buf_ptr,
            MMI_MTV_PLAYER_PREVIEW_BUFFER_SIZE);

        ASSERT (result != GDI_FAILED);

        gdi_layer_push_and_set_active(mtv_player_p->preview_layer_handle);
#ifdef GDI_USING_LAYER_BACKGROUND
        gdi_layer_set_background(GDI_COLOR_BLACK);
#endif 
        gdi_layer_pop_and_restore_active();
    }
#endif /* __MTK_TARGET__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_deinit_adm_resource
 * DESCRIPTION
 *  callback function used by applib to free APP-Based Memory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_deinit_adm_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__ 
    if (mtv_player_p->adm_pool_id)
    {
        /* Free preview layer related resource */
        if (mtv_player_p->preview_layer_handle != GDI_LAYER_EMPTY_HANDLE)
        {
            gdi_layer_free(mtv_player_p->preview_layer_handle);
            mtv_player_p->preview_layer_handle = GDI_LAYER_EMPTY_HANDLE;
        }

        if (mtv_player_p->preview_layer_buf_ptr != NULL)
        {
            kal_adm_free(mtv_player_p->adm_pool_id,(void *) mtv_player_p->preview_layer_buf_ptr);
            mtv_player_p->preview_layer_buf_ptr = NULL;
        }
    }
#endif /* __MTK_TARGET__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_create_resource
 * DESCRIPTION
 *  this function creates scr-based resource for mtv player
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_create_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* create loading layer */
    gdi_layer_create(
        110,
        98,
        100,
        43,
        &mtv_player_p->process_layer_handle);

    gdi_layer_push_and_set_active(mtv_player_p->process_layer_handle);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();


    /* OSD LAYER */
    mtv_player_p->osd_layer_buf_ptr = (PU8) mmi_frm_scrmem_alloc(MMI_MTV_PLAYER_OSD_BUFFER_SIZE);
    ASSERT(mtv_player_p->osd_layer_buf_ptr != NULL);

    gdi_layer_create_double_using_outside_memory(
        0,
        0,
        LCD_WIDTH,
        LCD_HEIGHT,
        &mtv_player_p->osd_layer_handle,
        (PU8) mtv_player_p->osd_layer_buf_ptr,
        (S32) (MMI_MTV_PLAYER_OSD_BUFFER_SIZE));


    /* DLS LAYER */
    mtv_player_p->dls_layer_buf_ptr = (PU8) mmi_frm_scrmem_alloc(MMI_MTV_PLAYER_DLS_BUFFER_SIZE);
    ASSERT(mtv_player_p->dls_layer_buf_ptr != NULL);

    gdi_layer_create_double_using_outside_memory(
        0,
        0,
        MTV_PLAYER_DLS_LAYER_WIDTH,
        MTV_PLAYER_DLS_LAYER_HEIGHT,
        &mtv_player_p->dls_layer_handle,
        (PU8) mtv_player_p->dls_layer_buf_ptr,
        (S32) (MMI_MTV_PLAYER_DLS_BUFFER_SIZE));

    mmi_mtv_player_config_osd_and_dls_layer();

    /* HINT STRING BUFFER */
    mtv_player_p->hint1_buf= (S8*)mmi_frm_scrmem_alloc(MMI_MTV_PLAYER_HINT_BUF_SIZE);
    ASSERT(mtv_player_p->hint1_buf!= NULL);
    mtv_player_p->hint2_buf= (S8*)mmi_frm_scrmem_alloc(MMI_MTV_PLAYER_HINT_BUF_SIZE);
    ASSERT(mtv_player_p->hint2_buf!= NULL);

    memset(mtv_player_p->hint1_buf, 0, MMI_MTV_PLAYER_HINT_BUF_SIZE);
    memset(mtv_player_p->hint2_buf, 0, MMI_MTV_PLAYER_HINT_BUF_SIZE);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_free_resource
 * DESCRIPTION
 *  this function frees scr-based resource for mtv player
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_free_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    /* free process layer resource */
    if (mtv_player_p->process_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(mtv_player_p->process_layer_handle);
        mtv_player_p->process_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    }

    /* free osd layer resource */
    if (mtv_player_p->osd_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(mtv_player_p->osd_layer_handle);
        mtv_player_p->osd_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    }

    if (mtv_player_p->osd_layer_buf_ptr != NULL)
    {
        mmi_frm_scrmem_free((void*)mtv_player_p->osd_layer_buf_ptr);
        mtv_player_p->osd_layer_buf_ptr = NULL;
    }

    /* free dls layer resource */
    if (mtv_player_p->dls_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(mtv_player_p->dls_layer_handle);
        mtv_player_p->dls_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    }

    if (mtv_player_p->dls_layer_buf_ptr != NULL)
    {
        mmi_frm_scrmem_free((void*)mtv_player_p->dls_layer_buf_ptr);
        mtv_player_p->dls_layer_buf_ptr = NULL;
    }

    /* free hint related resource */    
    if (mtv_player_p->hint1_buf != NULL)
    {
        mmi_frm_scrmem_free((void*)mtv_player_p->hint1_buf);
        mtv_player_p->hint1_buf= NULL;

    }

    if (mtv_player_p->hint2_buf != NULL)
    {
        mmi_frm_scrmem_free((void*)mtv_player_p->hint2_buf);
        mtv_player_p->hint2_buf= NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_del_scr_callback
 * DESCRIPTION
 *  delete screen id callback handler of mtv player applications
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_mtv_player_del_scr_callback(void* ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!RECORDER_STATE_IN(MTV_RECORDER_RECORD))
    {
        MTV_ENTER_STATE(kernel,MMI_MTV_KERNEL,MTV_KERNEL_CLOSED);
    }

    /* reset service num */
    mtv_player_p->setting.num_services = 0;
    mmi_mtv_player_store_setting();

    /* deinit adm related resource */
    mmi_mtv_player_delete_adm();

    #ifndef __MTK_TARGET__
        /* Free preview layer related resource */
        if (mtv_player_p->preview_layer_handle != GDI_LAYER_EMPTY_HANDLE)
        {
            gdi_layer_free(mtv_player_p->preview_layer_handle);
            mtv_player_p->preview_layer_handle = GDI_LAYER_EMPTY_HANDLE;
        }
    #endif

    /* free app-based memory */
    if (mtv_player_p->app_mem_pool != NULL)
    {
        applib_mem_ap_free((void*)mtv_player_p->app_mem_pool);
        mtv_player_p->app_mem_pool = NULL;    
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_store_setting
 * DESCRIPTION
 *  set mobile tv player settings from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_store_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteRecord(
        NVRAM_EF_MOBILE_TV_PLAYER_SETTING_LID,
        1,
        (void*)&(mtv_player_p->setting),
        NVRAM_EF_MOBILE_TV_PLAYER_SETTING_SIZE,
        &error);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_load_setting
 * DESCRIPTION
 *  load mobile tv player settings from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_load_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if setting is already loaded from NVRAM, it is already exist in memory, do not loaded again */
    if (!mtv_player_p->is_setting_loaded)
    {
        ReadRecord(
            NVRAM_EF_MOBILE_TV_PLAYER_SETTING_LID,
            1,
            (void*)&mtv_player_p->setting,
            NVRAM_EF_MOBILE_TV_PLAYER_SETTING_SIZE,
            &error);

        /* first time init */
        if (mtv_player_p->setting.storage == 0xffff)
        {
            mmi_mtv_player_restore_setting();
        }

        mtv_player_p->is_setting_loaded = TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_restore_setting
 * DESCRIPTION
 *  restore mobile tv player default settings 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_restore_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->setting.brightness = MDI_MTV_BRIGHTNESS_0;
    mtv_player_p->setting.contrast = MDI_MTV_CONTRAST_0;
    mtv_player_p->setting.selected_channel = 0;
    mtv_player_p->setting.storage = MMI_PUBLIC_DRV;
    mtv_player_p->setting.vol_level = MTV_PLAYER_VOL_7;
    mtv_player_p->setting.play_speed = MTV_PLAYER_PLAY_SPEED_10X;
    mtv_player_p->setting.band = 0;

    mtv_player_p->setting.max_timeshift_delay = 100;
    mtv_player_p->setting.max_timeshift_bf_size = 100;
    mtv_player_p->setting.is_channel_list_init = FALSE;
    mtv_player_p->setting.is_channel_seleted = FALSE;
    mtv_player_p->setting.num_services = 0;


    WriteRecord(NVRAM_EF_MOBILE_TV_PLAYER_SETTING_LID, 1, (void*)&mtv_player_p->setting, NVRAM_EF_MOBILE_TV_PLAYER_SETTING_SIZE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_restore_setting
 * DESCRIPTION
 *  restore mobile tv player default settings 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_set_hint(PS8 hint_str1, PS8 hint_str2, U16 fade_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(mtv_player_p->hint1_buf, 0, MMI_MTV_PLAYER_HINT_BUF_SIZE);
    memset(mtv_player_p->hint2_buf, 0, MMI_MTV_PLAYER_HINT_BUF_SIZE);

    if (hint_str1 != NULL)
    {
        mmi_ucs2ncpy((PS8) mtv_player_p->hint1_buf, (PS8) hint_str1, MMI_MTV_PLAYER_HINT_BUF_SIZE);
    }

    if (hint_str2 != NULL)
    {
        mmi_ucs2ncpy((PS8) mtv_player_p->hint2_buf, (PS8) hint_str2, MMI_MTV_PLAYER_HINT_BUF_SIZE);
    }
    mtv_player_p->is_show_hint = TRUE;
    mtv_player_p->fade_time = fade_time;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_draw_hint
 * DESCRIPTION
 *  draw preview OSD panel
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_draw_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str1_width;
    S32 str1_height;
    S32 str2_width;
    S32 str2_height;
    S32 str1_offset_x = 0;
    S32 str1_offset_y = 0;
    S32 str2_offset_x = 0;
    S32 str2_offset_y = 0;
    S32 spacing = 5;
    PS8 hint_str1;
    PS8 hint_str2;

    S32 offset_x = 0;
    S32 offset_y = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hint_str1 = mtv_player_p->hint1_buf;
    hint_str2 = mtv_player_p->hint2_buf;

    /* be removed : clear hint backgounrd */

    gdi_layer_reset_clip();
    gdi_layer_reset_text_clip();
 
    /* if is fullscreen display, or normal display but without mmi_softkey */
    gui_set_font(&MMI_medium_font);

    if(hint_str1!=NULL)
    {
        gui_measure_string((UI_string_type) hint_str1, &str1_width, &str1_height);
        str1_offset_x = (mtv_player_p->active_osd_cntx_p->hint_box.width - str1_width) >> 1;
        str1_offset_y = spacing;
        mmi_mtv_player_draw_style_text(
            hint_str1,
            mtv_player_p->active_osd_cntx_p->hint_box.offset_x + str1_offset_x - offset_x,
            mtv_player_p->active_osd_cntx_p->hint_box.offset_y + str1_offset_y - offset_y);
    }

    if(hint_str2!=NULL)
    {
        gui_measure_string((UI_string_type) hint_str2, &str2_width, &str2_height);

        if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_270)
        {
            str2_offset_y = str1_offset_y + spacing + str1_height;
            str2_offset_x = (mtv_player_p->active_osd_cntx_p->hint_box.width - str2_width) >> 1;
        }
        else
        {
            str2_offset_y = str1_offset_y + spacing + str1_height;
            str2_offset_x = (mtv_player_p->active_osd_cntx_p->hint_box.width - str2_width) >> 1;
        }
        mmi_mtv_player_draw_style_text(
            hint_str2,
            mtv_player_p->active_osd_cntx_p->hint_box.offset_x + str2_offset_x - offset_x,
            mtv_player_p->active_osd_cntx_p->hint_box.offset_y + str2_offset_y - offset_y);
    }

    if (mtv_player_p->fade_time != 0 && mtv_player_p->is_show_hint == TRUE)
    {
        gui_start_timer(mtv_player_p->fade_time , mmi_mtv_player_hide_hint);
        mtv_player_p->fade_time = 0;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_restore_setting
 * DESCRIPTION
 *  restore mobile tv player default settings 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_hide_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtv_player_p->is_show_hint = FALSE;
    mmi_mtv_player_draw_osd();
    gdi_lcd_blt(mtv_player_p->preview_layer_handle, mtv_player_p->osd_layer_handle, mtv_player_p->dls_layer_handle, 0);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_init_highlight_hdlr
 * DESCRIPTION
 *  initialize menu high light handler functions
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_init_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    SetHiliteHandler(MENU_ID_MOBILE_TV_PLAYER_APP, mmi_mtv_player_highlight_app);

    SetHiliteHandler(MENU_ID_MOBILE_TV_PLAYER_OPTION_CHANNEL_LIST, mmi_mtv_player_highlight_cl);
    SetHiliteHandler(MENU_ID_MOBILE_TV_PLAYER_OPTION_SETTING, mmi_mtv_player_highlight_settings);
    SetHiliteHandler(MENU_ID_MOBILE_TV_PLAYER_OPTION_STORAGE, mmi_mtv_player_highlight_storage);
    SetHiliteHandler(MENU_ID_MOBILE_TV_PLAYER_OPTION_BAND, mmi_mtv_player_highlight_band);


    SetHiliteHandler(MENU_ID_MOBILE_TV_PLAYER_CL_OPTION_PLAY, mmi_mtv_player_highlight_play);
    SetHiliteHandler(MENU_ID_MOBILE_TV_PLAYER_CL_OPTION_UPDATE, mmi_mtv_player_highlight_update_list);

#if defined(__MMI_MTV_A2DP_SUPPORT__)
    SetHiliteHandler(MENU_ID_MOBILE_TV_PLAYER_BLUETOOTH_SETTING, mmi_mtv_player_highlight_bluetooth_setting);    
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_clear_dls_layer
 * DESCRIPTION
 *  clear dls layer (called when 1.exit app 2.change channel
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_clear_dls_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mtv_player_p->scrolling_label_state == MTV_PLAYER_SCROLLING_TEXT_SCROLLING)
    {
        gui_scrolling_text_stop(&mtv_player_p->scrolling_label);
        mtv_player_p->scrolling_label_state= MTV_PLAYER_SCROLLING_TEXT_OFF;
    }
    
    gdi_layer_push_and_set_active(mtv_player_p->dls_layer_handle);
    gdi_layer_toggle_double();
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_config_osd_and_dls_layer
 * DESCRIPTION
 *  config osd layer's size / rotation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_config_osd_and_dls_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 rotate_value = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mtv_player_p->ui_rotate == MMI_FRM_SCREEN_ROTATE_0)
    {
        mtv_player_p->active_osd_cntx_p = &g_mtv_player_osd_cntx;
        mtv_player_p->osd_layer_width = LCD_WIDTH;
        mtv_player_p->osd_layer_height = LCD_HEIGHT;
        rotate_value = GDI_LAYER_ROTATE_0;
    }
    else
    {
        mtv_player_p->active_osd_cntx_p = &g_mtv_player_osd_cntx_270;
        mtv_player_p->osd_layer_width = LCD_HEIGHT;
        mtv_player_p->osd_layer_height = LCD_WIDTH;
        rotate_value = GDI_LAYER_ROTATE_90;
    }

    /* Rotate and Resize OSD Layer */
    gdi_layer_push_and_set_active(mtv_player_p->osd_layer_handle);
    gdi_layer_resize(mtv_player_p->osd_layer_width,mtv_player_p->osd_layer_height);
    //gdi_layer_set_rotate(rotate_value);
    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();

    /* Rotate and Resize DLS layer */
    gdi_layer_push_and_set_active(mtv_player_p->dls_layer_handle);
    gdi_layer_resize(mtv_player_p->active_osd_cntx_p->title.width,mtv_player_p->active_osd_cntx_p->title.height);
    gdi_layer_set_position(mtv_player_p->active_osd_cntx_p->title.offset_x,mtv_player_p->active_osd_cntx_p->title.offset_y);
    //gdi_layer_set_rotate(rotate_value);
    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();


    /* Initialize icon position for touch */
    //#ifdef __MMI_TOUCH_SCREEN__
    mmi_mtv_player_init_icon_info();    
    //#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_on_service_found_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT 
 *****************************************************************************/
static void mmi_mtv_player_on_service_found_hdlr(mdi_mtv_service_info_struct *service_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mtv_player_p->setting.num_services < MMI_MTV_MAX_SERVICES 
       && (service_info->service_type == MEDIA_MTV_SERVICE_DIGITAL_RADIO ||service_info->service_type == MEDIA_MTV_SERVICE_DIGITAL_TV))
    {
        S32 i = mtv_player_p->setting.num_services;

        mtv_player_p->setting.services[i].service_id = service_info->service_id;
        memset(mtv_player_p->service_names[i],0x0,MMI_MTV_SERVICES_NAME_LENGTH*sizeof(S8));
        mtv_player_p->setting.services[i].service_name = mtv_player_p->service_names[i];
		if (service_info->service_name!=NULL)
            mmi_ucs2cpy((PS8)mtv_player_p->setting.services[i].service_name ,(PS8)service_info->service_name);
        mtv_player_p->setting.services[i].service_number = service_info->service_number;
        mtv_player_p->setting.services[i].service_flags = service_info->service_flags;
        mtv_player_p->setting.services[i].service_type = service_info->service_type;   

        mtv_player_p->setting.num_services++;
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_player_event_callback
 * DESCRIPTION
 *  callback function when any player event ind
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_player_event_callback(U32 event_id, S32 param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (event_id == MDI_MTV_PLAYER_DYNAMIC_LABEL)
    {
        //check if it is on mobile tv application screen
        if (GetActiveScreenId() != SCR_ID_MOBILE_TV_PLAYER_APP)
        {
            return;
        }
        
        //set dynamic label and update osd label region
        mmi_mtv_player_set_dynamic_label_and_draw((PS8)param, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_recorder_event_callback
 * DESCRIPTION
 *  callback function when any recorder event ind
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_recorder_event_callback(U32 event_id, S32 param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (event_id == MDI_MTV_RECORDER_STOPPED)
    {
        if (param == MDI_RES_MTV_COMPLETE_SAVING)
        {
            if (RECORDER_STATE_IN(MTV_RECORDER_SAVING))
                MTV_ENTER_STATE(recorder,MMI_MTV_RECORDER,MTV_RECORDER_STOPPED);

            g_mtv_player_osd_cntx.record.status =  MTV_PLAYER_ICON_STATUS_ENABLE;
            g_mtv_player_osd_cntx_270.record.status =  MTV_PLAYER_ICON_STATUS_ENABLE;
            mmi_mtv_player_draw_osd_and_blt_check();
        }
    }
    else if (event_id == MDI_MTV_RECORDER_ERROR)
    {
        /* Recorder error: e.g. Storage is not enough */ 
        if (!RECORDER_STATE_IN(MTV_RECORDER_RECORD))
        ASSERT(0);

        /* Set recorder error flag */
        mtv_player_p->is_recorder_error = TRUE;

        /* display popup callback */
        DisplayPopupRotated((PU8) GetString(STR_ID_MOBILE_TV_PLAYER_NOTIFY_RECORDER_ERROR),
                IMG_GLOBAL_WARNING, 
                1, 
                ST_NOTIFYDURATION, 
                0, 
                mtv_player_p->ui_rotate);
    }
    else if (event_id == MDI_MTV_RECORDER_SAVING_FAILED)
    {
        MTV_ENTER_STATE(recorder,MMI_MTV_RECORDER,MTV_RECORDER_STOPPED);
        DisplayPopupRotated((PU8) GetString(STR_ID_MOBILE_TV_PLAYER_NOTIFY_SAVE_FILE_ERROR),
                IMG_GLOBAL_WARNING, 
                1, 
                ST_NOTIFYDURATION, 
                0, 
                mtv_player_p->ui_rotate);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_on_search_progress_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT 
 *****************************************************************************/
static void mmi_mtv_player_on_search_progress_ind_hdlr(S32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (value == 100 && mtv_player_p->is_live_scanning == TRUE)
    {
        /***********************************************************
         * if scanning 0 channels, popup 0 channels, exit application
         ************************************************************/
        if (mtv_player_p->setting.num_services == 0)
        {
            MTV_ENTER_STATE(kernel,MMI_MTV_KERNEL,MTV_KERNEL_CLOSED);
            mmi_mtv_player_display_error_popup(STR_ID_MOBILE_TV_PLAYER_NOTIFY_NO_CHANNELS_SCANNED);
            DeleteUptoScrID(SCR_ID_MOBILE_TV_PLAYER_APP);
            DeleteScreenIfPresent(SCR_ID_MOBILE_TV_PLAYER_APP);
            DeleteScreenIfPresent(SCR_ID_MOBILE_TV_PLAYER_INIT_CHANNEL_LIST);
            return;
        }
    
        mtv_player_p->is_live_scan_complete = TRUE;
        mtv_player_p->setting.is_channel_list_init = TRUE;
        mtv_player_p->is_live_scanning = FALSE;

        WriteRecord(NVRAM_EF_MOBILE_TV_PLAYER_SETTING_LID, 1, (void*)&mtv_player_p->setting, NVRAM_EF_MOBILE_TV_PLAYER_SETTING_SIZE, &error);

        if (mtv_player_p->setting.is_channel_seleted == FALSE)
        {
            mmi_mtv_player_entry_channel_list_screen();
        }
        else
        {
			// Todo: set param.
			MTV_ENTER_STATE(kernel,MMI_MTV_KERNEL,MTV_KERNEL_OPENED);
        }

        #ifdef __MTK_TARGET__
        /* Alarm playing */
        if (AlmIsTonePlaying())
        {
            return;
        }
        #endif

        DeleteScreenIfPresent(SCR_ID_MOBILE_TV_PLAYER_INIT_CHANNEL_LIST);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_on_complete_saving_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT 
 *****************************************************************************/
static void mmi_mtv_player_on_complete_saving_ind_hdlr(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result != MDI_RES_MTV_SUCCEED)
        ASSERT(0);

    mtv_player_p->is_saving = FALSE;

    MTV_ENTER_STATE(recorder,MMI_MTV_RECORDER,MTV_RECORDER_STOPPED);

    /* if mobile tv player is already removed from history , do not show popup */
    if (GetActiveScreenId() != SCR_ID_MOBILE_TV_PLAYER_APP)
    {
        return;
    }
                          
    #ifdef __MTK_TARGET__
    /* Alarm playing */
    if (AlmIsTonePlaying())
    {
        return;
    }
    #endif

    /* is in call, they have higher priority, do not show popup */
    if (isInCall())
    {
        return;
    }

    if (result >= 0)
    {            
        mmi_mtv_player_display_done_popup();
    }
    else        
    {
        U16 string_id = mmi_mtv_player_get_error_string_by_error_enum(result);
        mtv_player_p->last_error = result;
        /* enter only not in call */
        mmi_mtv_player_display_error_popup(string_id);
        DeleteUptoScrID(SCR_ID_MOBILE_TV_PLAYER_APP);
        DeleteScreenIfPresent(SCR_ID_MOBILE_TV_PLAYER_APP);
    }

    //DeleteScreenIfPresent(SCR_ID_MOBILE_TV_PLAYER_SAVING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_open_engine
 * DESCRIPTION
 *  open mtv engine
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT 
 *****************************************************************************/
static MDI_RESULT mmi_mtv_player_open_engine(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_mtv_setting_struct mtv_setting;
    mdi_mtv_service_config_struct mtv_service_config;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mtv_setting.brightness = mtv_player_p->setting.brightness;
    mtv_setting.contrast = mtv_player_p->setting.contrast;
    mtv_setting.is_timeshift_enabled = TRUE;
    mtv_setting.record_dir = (PU8)mtv_player_p->storage_filepath;
    mtv_setting.volume_level = mtv_player_p->setting.vol_level;

    mtv_service_config.on_complete_saving_ind_hdlr = mmi_mtv_player_on_complete_saving_ind_hdlr ;
    mtv_service_config.on_search_progress_ind_hdlr = mmi_mtv_player_on_search_progress_ind_hdlr;
    mtv_service_config.on_service_found_hdlr = mmi_mtv_player_on_service_found_hdlr;
    mtv_service_config.on_service_event_callback = mmi_mtv_player_service_event_callback;
    mtv_service_config.on_recorder_event_callback = mmi_mtv_player_recorder_event_callback;
    mtv_service_config.on_player_event_callback = mmi_mtv_player_player_event_callback;

    return mdi_mtv_open(&mtv_player_p->mtv_handle, 
                        mtv_player_p->preview_layer_handle, 
                        &mtv_setting, 
                        &mtv_service_config);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_enter_state
 * DESCRIPTION
 *  enter state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT 
 *****************************************************************************/
static void mmi_mtv_player_enter_state(mmi_mtv_player_module_enum module)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (module == MMI_MTV_KERNEL)
    {
        mtv_player_p->kernel_prev_state = mtv_player_p->kernel_state;
        mtv_player_p->kernel_state = mtv_player_p->kernel_next_state;
        mtv_player_p->kernel_next_state = MTV_KERNEL_NULL;

        MMI_TRACE(MMI_TRACE_G8_MEDIA,MMI_TRC_MTV_KERNEL_ENTER_STATE,mtv_player_p->kernel_prev_state,mtv_player_p->kernel_state);

        switch (mtv_player_p->kernel_state)
        {
            case MTV_KERNEL_CLOSED:
                mmi_mtv_player_kernel_entry_closed_state();
                break;
            case MTV_KERNEL_SAVE_CONFIRM:
                mmi_mtv_player_kernel_entry_save_confirm_state();
                break;
            case MTV_KERNEL_SAVING:
                mmi_mtv_player_kernel_entry_saving_state();
                break;
            case MTV_KERNEL_SCANNING:
                mmi_mtv_player_kernel_entry_scanning_state();
                break;
            case MTV_KERNEL_OPENED:
                mmi_mtv_player_kernel_entry_opened_state();
                break;
            case MTV_KERNEL_INIT:
                mmi_mtv_player_kernel_entry_init_state();
                break;
            case MTV_KERNEL_READY:
                mmi_mtv_player_kernel_entry_ready_state();
                break;
            default:
                break;

        }

        
    }
    else if (module == MMI_MTV_PLAYER)
    {
        mtv_player_p->player_prev_state = mtv_player_p->player_state;
        mtv_player_p->player_state = mtv_player_p->player_next_state;
        mtv_player_p->player_next_state = MTV_PLAYER_NULL;

        MMI_TRACE(MMI_TRACE_G8_MEDIA,MMI_TRC_MTV_PLAYER_ENTER_STATE,mtv_player_p->player_prev_state,mtv_player_p->player_state);

        switch (mtv_player_p->player_state)
        {
            case MTV_PLAYER_STOPPED:
                mmi_mtv_player_player_entry_stopped_state();
                break;
            case MTV_PLAYER_PLAY:
                mmi_mtv_player_player_entry_play_state();
                break;
            case MTV_PLAYER_PAUSE:
                mmi_mtv_player_player_entry_pause_state();
                break;
            case MTV_PLAYER_BT_CONNECT:
                mmi_mtv_player_player_entry_bt_connect_state();
                break;
        }


    }
    else if (module == MMI_MTV_RECORDER)
    {
        mtv_player_p->recorder_prev_state = mtv_player_p->recorder_state;
        mtv_player_p->recorder_state = mtv_player_p->recorder_next_state;
        mtv_player_p->recorder_next_state = MTV_RECORDER_NULL;
        MMI_TRACE(MMI_TRACE_G8_MEDIA,MMI_TRC_MTV_RECORDER_ENTER_STATE,mtv_player_p->recorder_prev_state,mtv_player_p->recorder_state);
        
        switch (mtv_player_p->recorder_state)
        {
            case MTV_RECORDER_STOPPED:
                mmi_mtv_player_recorder_entry_stopped_state();
                break;
            case MTV_RECORDER_RECORD:
                mmi_mtv_player_recorder_entry_record_state();
                break;
            case MTV_RECORDER_SAVE_CONFIRM:
                mmi_mtv_player_recorder_entry_save_confirm_state();
                break;
            case MTV_RECORDER_SAVING:
                mmi_mtv_player_recorder_entry_saving_state();
                break;
        }


    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_exit_current_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT 
 *****************************************************************************/
static void mmi_mtv_player_exit_current_state(mmi_mtv_player_module_enum module)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (module == MMI_MTV_KERNEL)
    {
        switch (mtv_player_p->kernel_state)
        {
            case MTV_KERNEL_CLOSED:
                //mmi_mtv_player_kernel_exit_closed_state();
                break;
            case MTV_KERNEL_SAVE_CONFIRM:
                mmi_mtv_player_kernel_exit_save_confirm_state();
                break;
            case MTV_KERNEL_SAVING:
                mmi_mtv_player_kernel_exit_saving_state();
                break;
            case MTV_KERNEL_SCANNING:
                mmi_mtv_player_kernel_exit_scanning_state();
                break;
            case MTV_KERNEL_OPENED:
                mmi_mtv_player_kernel_exit_opened_state();
                break;
            case MTV_KERNEL_INIT:
                mmi_mtv_player_kernel_exit_init_state();
                break;
            case MTV_KERNEL_READY:
                mmi_mtv_player_kernel_exit_ready_state();
                break;
            default:
                break;
        }       
    }
    else if (module == MMI_MTV_PLAYER)
    {
        switch (mtv_player_p->player_state)
        {
            case MTV_PLAYER_STOPPED:
                mmi_mtv_player_player_exit_stopped_state();
                break;
            case MTV_PLAYER_PLAY:
                mmi_mtv_player_player_exit_play_state();
                break;
            case MTV_PLAYER_PAUSE:
                mmi_mtv_player_player_exit_pause_state();
                break;
            case MTV_PLAYER_BT_CONNECT:
                mmi_mtv_player_player_exit_bt_connect_state();
                break;
        }
    }
    else if (module == MMI_MTV_RECORDER)
    {
        switch (mtv_player_p->recorder_state)
        {
            case MTV_RECORDER_STOPPED:
                mmi_mtv_player_recorder_exit_stopped_state();
                break;
            case MTV_RECORDER_RECORD:
                mmi_mtv_player_recorder_exit_record_state();
                break;
            case MTV_RECORDER_SAVE_CONFIRM:
                mmi_mtv_player_recorder_exit_save_confirm_state();
                break;
            case MTV_RECORDER_SAVING:
                mmi_mtv_player_recorder_exit_saving_state();
                break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_exit_current_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT 
 *****************************************************************************/
static void mmi_mtv_player_kernel_entry_closed_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PLAYER_STATE_IN(MTV_PLAYER_PLAY)||PLAYER_STATE_IN(MTV_PLAYER_BT_CONNECT))
        MTV_ENTER_STATE(player,MMI_MTV_PLAYER,MTV_PLAYER_STOPPED);

    switch (mtv_player_p->kernel_prev_state)
    {
        case MTV_KERNEL_READY:
            i = mmi_mtv_player_get_active_channel(); 
            mtv_player_p->last_error = mdi_mtv_stop_service(mtv_player_p->mtv_handle,mtv_player_p->setting.services[i].service_id);
            if (mtv_player_p->last_error >= MDI_RES_MTV_SUCCEED)
                mtv_player_p->last_error = mdi_mtv_close(mtv_player_p->mtv_handle);

            if (mtv_player_p->last_error != MDI_RES_MTV_SUCCEED)
            {
                U16 string_id = mmi_mtv_player_get_error_string_by_error_enum(mtv_player_p->last_error);
                mmi_mtv_player_display_error_popup(string_id);                
                mmi_mtv_player_reset_all_state();
                DeleteUptoScrID(SCR_ID_MOBILE_TV_PLAYER_APP);
                DeleteScreenIfPresent(SCR_ID_MOBILE_TV_PLAYER_APP);
            }
            break;
        case MTV_KERNEL_INIT:
            break;        
        case MTV_KERNEL_OPENED:
        case MTV_KERNEL_SCANNING:
            mtv_player_p->last_error = mdi_mtv_close(mtv_player_p->mtv_handle);
            if (mtv_player_p->last_error != MDI_RES_MTV_SUCCEED)
            {
                U16 string_id = mmi_mtv_player_get_error_string_by_error_enum(mtv_player_p->last_error);
                mmi_mtv_player_display_error_popup(string_id);                
                mmi_mtv_player_reset_all_state();
                DeleteUptoScrID(SCR_ID_MOBILE_TV_PLAYER_APP);
                DeleteScreenIfPresent(SCR_ID_MOBILE_TV_PLAYER_APP);
            }
            break;
        case MTV_KERNEL_SAVING:
            break;
        case MTV_KERNEL_SAVE_CONFIRM:
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_kernel_exit_closed_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT 
 *****************************************************************************/
static void mmi_mtv_player_kernel_exit_closed_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_kernel_entry_scanning_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT 
 *****************************************************************************/
static void mmi_mtv_player_kernel_entry_scanning_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mtv_player_p->setting.is_channel_list_init == FALSE || mtv_player_p->is_updating_channel_list == TRUE)
        mtv_player_p->last_error = mdi_mtv_scan_services_on_air(mtv_player_p->mtv_handle);
    else // if (mtv_player_p->setting.is_channel_seleted == FALSE)
        mtv_player_p->last_error = mdi_mtv_scan_services_from_database(mtv_player_p->mtv_handle);
      
    if (mtv_player_p->last_error == MDI_RES_MTV_SUCCEED)
    {
        mtv_player_p->is_live_scanning = TRUE;
        /* it will automatically enter opened state while finished scanning */
    }
    else
    {
        mmi_mtv_player_display_error_popup(STR_ID_MOBILE_TV_PLAYER_NOTIFY_ERROR);
        mmi_mtv_player_reset_all_state();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_kernel_exit_scanning_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT 
 *****************************************************************************/
static void mmi_mtv_player_kernel_exit_scanning_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_kernel_entry_save_confirm_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT 
 *****************************************************************************/
static void mmi_mtv_player_kernel_entry_save_confirm_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayConfirmRotated(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_ID_MOBILE_TV_PLAYER_SAVE_UNSAVED_RECORDING),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE,
        mtv_player_p->ui_rotate);

    SetRightSoftkeyFunction(mmi_mtv_player_discard_unsaved_recording, KEY_EVENT_UP);

    /* save recording is a blocking function call */
    SetLeftSoftkeyFunction(mmi_mtv_player_save_recording, KEY_EVENT_UP);   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_kernel_exit_save_confirm_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT 
 *****************************************************************************/
static void mmi_mtv_player_kernel_exit_save_confirm_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_kernel_entry_saving_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT 
 *****************************************************************************/
static void mmi_mtv_player_kernel_entry_saving_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!KERNEL_STATE_IN(MTV_KERNEL_SAVING)
        ||!PLAYER_STATE_IN(MTV_PLAYER_STOPPED)
        ||!RECORDER_STATE_IN(MTV_RECORDER_STOPPED))
        ASSERT(0);

    /* set saving flag avoid screen deletion */
    mtv_player_p->is_saving = TRUE;
    SetDelScrnIDCallbackHandler(SCR_ID_MOBILE_TV_PLAYER_SAVING, mmi_mtv_player_saving_screen_del_hdlr);

    /* suspend background play */
    mdi_audio_suspend_background_play();
    EntryNewScreen(SCR_ID_MOBILE_TV_PLAYER_SAVING, mmi_mtv_player_kernel_exit_saving_state, mmi_mtv_player_kernel_entry_saving_state, NULL);

    /* rotate UI */
    mmi_frm_screen_rotate(mtv_player_p->ui_rotate);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_MOBILE_TV_PLAYER_SAVING);

    if (guiBuffer == NULL)
    {
        mtv_player_p->last_error = mdi_mtv_restore_unsaved_recording(mtv_player_p->mtv_handle);

        if (mtv_player_p->last_error != MDI_RES_MTV_SUCCEED)
        {
            mmi_mtv_player_display_error_popup(STR_ID_MOBILE_TV_PLAYER_NOTIFY_SAVE_FILE_ERROR);
            /* if has error, cant save, delete temp file */
            mdi_mtv_discard_unsaved_recording(mtv_player_p->mtv_handle);
            return;
        }
        else if (mtv_player_p->last_error == MDI_RES_MTV_SUCCEED)
        {
            ShowCategory66Screen(
                STR_ID_MOBILE_TV_PLAYER_APP_NAME,
                MAIN_MENU_TITLE_MULTIMEDIA_ICON,
                0,
                0,
                0,
                0,
                (PU8) GetString(STR_GLOBAL_SAVING),
                IMG_GLOBAL_PROGRESS,
                NULL);
        }
    }
    else 
    {
        MTV_ENTER_STATE(kernel,MMI_MTV_KERNEL,MTV_KERNEL_SCANNING);
    }

    /* clear end key, this action cant be abort */
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_kernel_exit_saving_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT 
 *****************************************************************************/
static void mmi_mtv_player_kernel_exit_saving_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* resume background play */
    mdi_audio_resume_background_play();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_kernel_entry_opened_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT 
 *****************************************************************************/
static void mmi_mtv_player_kernel_entry_opened_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */	
    /*----------------------------------------------------------------*/
    S32 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (mtv_player_p->kernel_prev_state)
    {
        case MTV_KERNEL_SCANNING:
            MTV_ENTER_STATE(kernel,MMI_MTV_KERNEL, MTV_KERNEL_INIT);
            break;
        case MTV_KERNEL_READY:
            i = mmi_mtv_player_get_active_channel(); 
            mtv_player_p->last_error = mdi_mtv_stop_service(mtv_player_p->mtv_handle,mtv_player_p->setting.services[i].service_id);
            if (mtv_player_p->last_error!=MDI_RES_MTV_SUCCEED)
            {
                mmi_mtv_player_display_error_popup(STR_ID_MOBILE_TV_PLAYER_NOTIFY_ERROR);
                DeleteUptoScrID(SCR_ID_MOBILE_TV_PLAYER_APP);
                DeleteScreenIfPresent(SCR_ID_MOBILE_TV_PLAYER_APP);
                mmi_mtv_player_reset_all_state();
            }
            break;
        default:
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_kernel_exit_opened_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT 
 *****************************************************************************/
static void mmi_mtv_player_kernel_exit_opened_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_kernel_entry_init_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT 
 *****************************************************************************/
static void mmi_mtv_player_kernel_entry_init_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!KERNEL_STATE_IN(MTV_KERNEL_INIT)
        ||!PLAYER_STATE_IN(MTV_PLAYER_STOPPED)
        ||!RECORDER_STATE_IN(MTV_RECORDER_STOPPED))
        ASSERT(0);


    i = mmi_mtv_player_get_active_channel();
    if((mtv_player_p->last_error = mdi_mtv_start_service(mtv_player_p->mtv_handle,
                                                         mtv_player_p->setting.services[i].service_id))==MDI_RES_MTV_SUCCEED)
    {
        mtv_player_p->is_initializing = TRUE;
    }
    else
    {
        mtv_player_p->is_initializing = FALSE;
        mmi_mtv_player_display_error_popup(STR_ID_MOBILE_TV_PLAYER_NOTIFY_ERROR);
        mmi_mtv_player_reset_all_state();
    }
    mmi_mtv_player_draw_osd_and_blt_check();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_kernel_exit_init_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT 
 *****************************************************************************/
static void mmi_mtv_player_kernel_exit_init_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    if (mtv_player_p->is_initializing == TRUE)
    {
        // if interrupt: stop service and back to open state && delete self screen
        i = mmi_mtv_player_get_active_channel(); 
        mdi_mtv_stop_service(mtv_player_p->mtv_handle, mtv_player_p->setting.services[i].service_id);

        if(KERNEL_STATE_IN(MTV_KERNEL_INIT))
        {
            mtv_player_p->kernel_prev_state = MTV_KERNEL_INIT;
            mtv_player_p->kernel_state = MTV_KERNEL_OPENED;
        }

        mtv_player_p->is_initializing = FALSE; 
    }
    else
    {
        //if not interrupt but result callback: do nothing
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_kernel_entry_ready_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT 
 *****************************************************************************/
static void mmi_mtv_player_kernel_entry_ready_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (RECORDER_STATE_IN(MTV_RECORDER_SAVE_CONFIRM))
    {
        if(PLAYER_STATE_IN(MTV_PLAYER_STOPPED))
        {
            mmi_mtv_player_recorder_entry_save_confirm_state();
        }
        else
            ASSERT(0);
    }
    else 
    {
        if (PLAYER_STATE_IN(MTV_PLAYER_STOPPED))
        {
        #if defined(__MMI_MTV_A2DP_SUPPORT__)
            MTV_ENTER_STATE(player,MMI_MTV_PLAYER,MTV_PLAYER_BT_CONNECT);
        #else
            MTV_ENTER_STATE(player,MMI_MTV_PLAYER,MTV_PLAYER_PLAY); 
        #endif
        }
        else if (PLAYER_STATE_IN(MTV_PLAYER_PAUSE))
        {
            if (RECORDER_STATE_IN(MTV_RECORDER_SAVING))
            {
            #if defined(__MMI_MTV_A2DP_SUPPORT__)
                MTV_ENTER_STATE(player,MMI_MTV_PLAYER,MTV_PLAYER_BT_CONNECT);
            #else
                MTV_ENTER_STATE(player,MMI_MTV_PLAYER,MTV_PLAYER_PLAY);
            #endif
            }
        }
        else 
            ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_kernel_exit_ready_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT 
 *****************************************************************************/
static void mmi_mtv_player_kernel_exit_ready_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

}


/*player state management*/
/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_player_entry_stopped_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT 
 *****************************************************************************/
static void mmi_mtv_player_player_entry_stopped_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MTV_A2DP_SUPPORT__)
    if (mtv_player_p->player_prev_state == MTV_PLAYER_BT_CONNECT)
    {
        mmi_mtv_player_disconnect_bt();
    }
    else if (mtv_player_p->player_prev_state == MTV_PLAYER_PLAY)
    {
        mmi_mtv_player_bt_close_codec();
        mmi_mtv_player_disconnect_bt();
    }
#endif

    mtv_player_p->last_error = mdi_mtv_player_stop_play(mtv_player_p->mtv_handle);

    if (mtv_player_p->last_error != MDI_RES_MTV_SUCCEED)    
    {
        mmi_mtv_player_display_error_popup(STR_ID_MOBILE_TV_PLAYER_NOTIFY_ERROR);
        DeleteUptoScrID(SCR_ID_MOBILE_TV_PLAYER_APP);
        DeleteScreenIfPresent(SCR_ID_MOBILE_TV_PLAYER_APP);
        mmi_mtv_player_reset_all_state();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_player_exit_stopped_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT 
 *****************************************************************************/
static void mmi_mtv_player_player_exit_stopped_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_player_entry_bt_connect_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT 
 *****************************************************************************/
static void mmi_mtv_player_player_entry_bt_connect_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MTV_A2DP_SUPPORT__)
    if (mmi_mtv_player_is_output_to_bt())
    {
        /* if connecting is not start in 600ms, we will show bt connecting anim */
        gui_start_timer(600, mmi_mtv_player_draw_bt_connecting_anim);

        //if (g_vdoply_cntx.video_info.aud_channel_no == 2)
        //{
        //    is_stereo = MMI_TRUE;
        //}
        //else
        //{
        //    is_stereo = MMI_FALSE;
        //}
        //MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_CALLING_AV_BT_OPEN_EX, __LINE__);  

        av_bt_open_ex(
            mmi_mtv_player_get_bt_headset(),
            g_vdoply_cntx.video_info.aud_sample_rate,
            (kal_bool)is_stereo,
            mmi_mtv_player_bt_open_callback,
            TRUE);   

        return;
    }
    else
    {
        /* shall not enter here */
        MMI_ASSERT(0);
    }
#else
    ASSERT(0);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_player_exit_bt_connect_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT 
 *****************************************************************************/
static void mmi_mtv_player_player_exit_bt_connect_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_player_entry_play_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT 
 *****************************************************************************/
static void mmi_mtv_player_player_entry_play_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PLAYER_STATE_IN(MTV_PLAYER_PLAY))
    {
        if (mtv_player_p->player_prev_state == MTV_PLAYER_PAUSE)
        {
            mtv_player_p->last_error = mdi_mtv_player_resume(mtv_player_p->mtv_handle);

            if (mtv_player_p->last_error != MDI_RES_MTV_SUCCEED)
            {           
            #if defined(__MMI_MTV_A2DP_SUPPORT__)
                if (mmi_mtv_player_is_output_to_bt())
                {
                    //MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_CALLING_AV_BT_CLOSE_CODEC, __LINE__);                   
                    av_bt_close_codec();
                }
            #endif /* __MMI_MTV_A2DP_SUPPORT__ */
                mmi_mtv_player_display_error_popup(STR_ID_MOBILE_TV_PLAYER_NOTIFY_ERROR);
                DeleteUptoScrID(SCR_ID_MOBILE_TV_PLAYER_APP);
                DeleteScreenIfPresent(SCR_ID_MOBILE_TV_PLAYER_APP);             
                mmi_mtv_player_reset_all_state();
            }
        }
        else if (mtv_player_p->player_prev_state == MTV_PLAYER_STOPPED)
        {
            mtv_player_p->last_error = mdi_mtv_player_start_play(mtv_player_p->mtv_handle);

            if (mtv_player_p->last_error != MDI_RES_MTV_SUCCEED)
            {
            #if defined(__MMI_MTV_A2DP_SUPPORT__)
                if (mmi_mtv_player_is_output_to_bt())
                {
                    //MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_CALLING_AV_BT_CLOSE_CODEC, __LINE__);                   
                    av_bt_close_codec();
                }
            #endif /* __MMI_MTV_A2DP_SUPPORT__ */
                mmi_mtv_player_display_error_popup(STR_ID_MOBILE_TV_PLAYER_NOTIFY_ERROR);
                DeleteUptoScrID(SCR_ID_MOBILE_TV_PLAYER_APP);
                DeleteScreenIfPresent(SCR_ID_MOBILE_TV_PLAYER_APP);
                mmi_mtv_player_reset_all_state();
            }
        }

        if (GetActiveScreenId() == SCR_ID_MOBILE_TV_PLAYER_APP)
            gui_start_timer(100,mmi_mtv_player_player_update_cyclic);
    }
    else 
        ASSERT(0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_player_exit_play_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT 
 *****************************************************************************/
static void mmi_mtv_player_player_exit_play_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_mtv_player_player_update_cyclic);
    gui_cancel_timer(mmi_mtv_player_fullscr_osd_fade_cyclic);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_player_entry_pause_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT 
 *****************************************************************************/
static void mmi_mtv_player_player_entry_pause_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mtv_player_p->player_prev_state == MTV_PLAYER_PLAY)
    {
        mtv_player_p->last_error = mdi_mtv_player_pause(mtv_player_p->mtv_handle);
        gui_cancel_timer(mmi_mtv_player_player_update_cyclic);

        if (mtv_player_p->last_error != MDI_RES_MTV_SUCCEED)
        {
            mmi_mtv_player_display_error_popup(STR_ID_MOBILE_TV_PLAYER_NOTIFY_ERROR);
            DeleteUptoScrID(SCR_ID_MOBILE_TV_PLAYER_APP);
            DeleteScreenIfPresent(SCR_ID_MOBILE_TV_PLAYER_APP);
            mmi_mtv_player_reset_all_state();
        }
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_player_exit_pause_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT 
 *****************************************************************************/
static void mmi_mtv_player_player_exit_pause_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

}


/*recorder state management*/
/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_recorder_entry_stopped_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT 
 *****************************************************************************/
static void mmi_mtv_player_recorder_entry_stopped_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_recorder_exit_stopped_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT 
 *****************************************************************************/
static void mmi_mtv_player_recorder_exit_stopped_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_recorder_entry_record_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT 
 *****************************************************************************/
static void mmi_mtv_player_recorder_entry_record_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    mtv_player_p->last_error = mdi_mtv_recorder_start_record(mtv_player_p->mtv_handle);

    if (mtv_player_p->last_error != MDI_RES_MTV_SUCCEED)
    {
        mmi_mtv_player_display_error_popup(STR_ID_MOBILE_TV_PLAYER_NOTIFY_ERROR);
        DeleteUptoScrID(SCR_ID_MOBILE_TV_PLAYER_APP);
        DeleteScreenIfPresent(SCR_ID_MOBILE_TV_PLAYER_APP);
        return;
    }
    //if (PLAYER_STATE_IN(MTV_PLAYER_STOPPED)||PLAYER_STATE_IN(MTV_PLAYER_PAUSE))
    //{
    //    MTV_ENTER_STATE(MMI_MTV_PLAYER,MTV_PLAYER_PLAY);      
    //}

    mtv_player_p->active_osd_cntx_p->channel_next.status = MTV_PLAYER_ICON_STATUS_DISABLE;
    mtv_player_p->active_osd_cntx_p->channel_prev.status = MTV_PLAYER_ICON_STATUS_DISABLE;



}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_recorder_exit_record_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT 
 *****************************************************************************/
static void mmi_mtv_player_recorder_exit_record_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mtv_player_p->recorder_next_state == MTV_RECORDER_SAVE_CONFIRM)
    {
        mtv_player_p->last_error = mdi_mtv_recorder_stop_record(mtv_player_p->mtv_handle);
        mtv_player_p->active_osd_cntx_p->channel_next.status = MTV_PLAYER_ICON_STATUS_ENABLE;
        mtv_player_p->active_osd_cntx_p->channel_prev.status = MTV_PLAYER_ICON_STATUS_ENABLE;

        if (mtv_player_p->last_error != MDI_RES_MTV_SUCCEED)
        {
            mmi_mtv_player_display_error_popup(STR_ID_MOBILE_TV_PLAYER_NOTIFY_ERROR);
            DeleteUptoScrID(SCR_ID_MOBILE_TV_PLAYER_APP);
            DeleteScreenIfPresent(SCR_ID_MOBILE_TV_PLAYER_APP);
            return;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_recorder_entry_save_confirm_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT 
 *****************************************************************************/
static void mmi_mtv_player_recorder_entry_save_confirm_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    DisplayConfirmRotated(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_ID_MOBILE_TV_PLAYER_SAVE_UNSAVED_RECORDING),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE,
        mtv_player_p->ui_rotate);

    SetRightSoftkeyFunction(mmi_mtv_player_discard_unsaved_recording, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_mtv_player_save_recording, KEY_EVENT_UP);   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_recorder_exit_save_confirm_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT 
 *****************************************************************************/
static void mmi_mtv_player_recorder_exit_save_confirm_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_recorder_entry_saving_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT 
 *****************************************************************************/
static void mmi_mtv_player_recorder_entry_saving_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!KERNEL_STATE_IN(MTV_KERNEL_READY)
        ||!(PLAYER_STATE_IN(MTV_PLAYER_STOPPED)||PLAYER_STATE_IN(MTV_PLAYER_PAUSE))
        ||!RECORDER_STATE_IN(MTV_RECORDER_SAVING))
        ASSERT(0);

    mtv_player_p->is_saving = TRUE;
    /* recorder saving is a non-blocking call */
    mtv_player_p->last_error = mdi_mtv_recorder_save_recording(mtv_player_p->mtv_handle);

    if (mtv_player_p->last_error != TRUE) 
    {
        mmi_mtv_player_display_error_popup(STR_ID_MOBILE_TV_PLAYER_NOTIFY_SAVE_FILE_ERROR);
        /* if has error, cant save, delete temp file */
        mdi_mtv_discard_unsaved_recording(mtv_player_p->mtv_handle);
        //g_mtv_player_osd_cntx.record.status =  MTV_PLAYER_ICON_STATUS_DISABLE;
        //g_mtv_player_osd_cntx_270.record.status =  MTV_PLAYER_ICON_STATUS_DISABLE;
        MTV_ENTER_STATE(recorder,MMI_MTV_RECORDER,MTV_RECORDER_STOPPED);
        return;
    }
    else
    {
        U16 str_id = 0;
        if (mtv_player_p->is_recorder_error == TRUE)
            str_id = STR_ID_MOBILE_TV_PLAYER_NOTIFY_SAVING;
        else 
            str_id = STR_GLOBAL_SAVING;
        DisplayPopupRotated((PU8) GetString(str_id), 
                            IMG_GLOBAL_ACTIVATED, 
                            1, 
                            ST_NOTIFYDURATION, 
                            0, 
                            mtv_player_p->ui_rotate);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_recorder_exit_saving_state
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT 
 *****************************************************************************/
static void mmi_mtv_player_recorder_exit_saving_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_discarding_callback
 * DESCRIPTION
 *  DISCARD RECORDING DONE CALLBACK
 * PARAMETERS
 *  VOID
 * RETURNS
 *  VOID
 *****************************************************************************/
static void mmi_mtv_player_discarding_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mtv_player_p->last_error == MDI_RES_MTV_SUCCEED)
    {
        DisplayPopupRotated((PU8) GetString(STR_GLOBAL_DONE), 
                            IMG_GLOBAL_ACTIVATED, 
                            1, 
                            ST_NOTIFYDURATION, 
                            0, 
                            mtv_player_p->ui_rotate);

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_discard_unsaved_recording
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT 
 *****************************************************************************/
static void mmi_mtv_player_discard_unsaved_recording(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((!KERNEL_STATE_IN(MTV_KERNEL_SAVE_CONFIRM)
        ||!PLAYER_STATE_IN(MTV_PLAYER_STOPPED)
        ||!RECORDER_STATE_IN(MTV_RECORDER_STOPPED))
        &&
        (!KERNEL_STATE_IN(MTV_KERNEL_READY)
         ||!PLAYER_STATE_IN(MTV_PLAYER_STOPPED)
         ||!RECORDER_STATE_IN(MTV_RECORDER_SAVE_CONFIRM)))
        ASSERT(0);

    mtv_player_p->is_discarding_file = TRUE;

    /* Blocking Call */
    if (KERNEL_STATE_IN(MTV_KERNEL_SAVE_CONFIRM))
        mtv_player_p->last_error = mdi_mtv_discard_unsaved_recording(mtv_player_p->mtv_handle);
    else if (RECORDER_STATE_IN(MTV_RECORDER_SAVE_CONFIRM))
    {
        mtv_player_p->last_error = mdi_mtv_recorder_discard_recording(mtv_player_p->mtv_handle);
        if (mtv_player_p->last_error == MDI_RES_MTV_SUCCEED)
            MTV_ENTER_STATE(recorder,MMI_MTV_RECORDER,MTV_RECORDER_STOPPED);
    }
    mmi_frm_screen_rotate(mtv_player_p->ui_rotate);

    DisplayPopupCallBack((PU8) GetString(STR_ID_MOBILE_TV_PLAYER_DISCARDING),
                    IMG_GLOBAL_ACTIVATED, 
                    1, 
                    ST_NOTIFYDURATION, 
                    0, 
                    mmi_mtv_player_discarding_callback);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_entry_save_recording_screen
 * DESCRIPTION
 *  exit state handler
 * PARAMETERS
 *  mmi_mtv_player_module_enum IN modele_type
 * RETURNS
 *  MDI_RESULT 
 *****************************************************************************/
static void mmi_mtv_player_save_recording(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /********************************************
     * for kernel, it is blocking saving 
     * for recorder, it is non-blocking saving 
     ********************************************/
    if (KERNEL_STATE_IN(MTV_KERNEL_SAVE_CONFIRM))
        MTV_ENTER_STATE(kernel,MMI_MTV_KERNEL,MTV_KERNEL_SAVING);
    else if (RECORDER_STATE_IN(MTV_RECORDER_SAVE_CONFIRM))
        MTV_ENTER_STATE(recorder,MMI_MTV_RECORDER,MTV_RECORDER_SAVING);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_init_cl_screen_del_hdlr
 * DESCRIPTION
 *  Del screen callback function
 * PARAMETERS
 *  dummy_ptr       [?]     
 * RETURNS
 *  U8
 *****************************************************************************/
static U8 mmi_mtv_player_init_cl_screen_del_hdlr(void *dummy_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mtv_player_p->is_live_scanning)
    {
        return TRUE;    /* if is scanning , will not delete this screen from history */
    }
    else
    {
        return FALSE;
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_saving_screen_del_hdlr
 * DESCRIPTION
 *  Del screen callback function
 * PARAMETERS
 *  dummy_ptr       [?]     
 * RETURNS
 *  U8
 *****************************************************************************/
static U8 mmi_mtv_player_saving_screen_del_hdlr(void *dummy_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mtv_player_p->is_saving)
    {
        return TRUE;    /* if is saving, will not delete this screen from history */
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_service_event_callback
 * DESCRIPTION
 *  callback function when save is done
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_service_event_callback (U32 event_id, S32 param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (event_id == MDI_MTV_SERVICE_STARTED)
    {
        mtv_player_p->last_error = param;
        mtv_player_p->is_initializing = FALSE;

        if (mtv_player_p->anim_handle != 0)
        {
            gdi_anim_stop(mtv_player_p->anim_handle);
            mtv_player_p->anim_handle = 0;
            mmi_mtv_player_draw_osd_and_blt_check();
        }
                                  
        #ifdef __MTK_TARGET__
        /* Alarm playing */
        if (AlmIsTonePlaying())
        {
            return;
        }
        #endif
        
        /* is in call, they have higher priority, do not show popup */
        if (!isInCall())
        {
            if (param >= 0)
            {
                MTV_ENTER_STATE(kernel,MMI_MTV_KERNEL,MTV_KERNEL_READY);          
                if (GetActiveScreenId()==SCR_ID_MOBILE_TV_PLAYER_APP)
                    mmi_mtv_player_register_key_hdlr();
            }
            else        
            {
                /* enter only not in call and wap not in call */
                mmi_mtv_player_display_error_popup(STR_ID_MOBILE_TV_PLAYER_NOTIFY_INITIALIZING_ERROR);
                DeleteUptoScrID(SCR_ID_MOBILE_TV_PLAYER_APP);
                DeleteScreenIfPresent(SCR_ID_MOBILE_TV_PLAYER_APP);
                mmi_mtv_player_reset_all_state();
            }

            #ifdef __MTK_TARGET__
            /* if clam is close, delete one more screen, avoid enter video recorder */
            if (IsClamClose())
            {
                DeleteScreenIfPresent(SCR_ID_MOBILE_TV_PLAYER_APP);
            }
            #endif
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_player_update_cyclic
 * DESCRIPTION
 *  display error popup.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_player_update_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_mtv_player_status_struct player_status;
    mdi_mtv_service_status_struct service_status;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_mtv_player_player_update_cyclic);

    if (KERNEL_STATE_IN(MTV_KERNEL_READY) && mtv_player_p->fullscr_osd_opacity != 0)
    {
        mdi_mtv_service_get_status(mtv_player_p->mtv_handle, &service_status);

        mtv_player_p->signal_strength = service_status.signal_strength;

        if (PLAYER_STATE_IN(MTV_PLAYER_PLAY))
        {
            mdi_mtv_player_get_status(mtv_player_p->mtv_handle, &player_status);
            mtv_player_p->max_delay = player_status.max_delay;
            mtv_player_p->play_delay = player_status.play_delay;
        }

        mmi_mtv_player_draw_osd_and_blt_check();
        gui_start_timer(1100,mmi_mtv_player_player_update_cyclic);
    }
//    else if (mtv_player_p->scrolling_label_state == MTV_PLAYER_SCROLLING_TEXT_SCROLLING)
//    {       
//        if (GetActiveScreenId() == SCR_ID_MOBILE_TV_PLAYER_APP)
//        {
//            gdi_lcd_blt(mtv_player_p->preview_layer_handle, mtv_player_p->osd_layer_handle, mtv_player_p->dls_layer_handle, 0);
//            gui_start_timer(1100,mmi_mtv_player_player_update_cyclic);            
//        }
//    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_get_active_channel
 * DESCRIPTION
 *  get current active channel index
 * PARAMETERS
 *  void
 * RETURNS
 *  S32 active channel idx
 *****************************************************************************/
static S32 mmi_mtv_player_get_active_channel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_screen_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    active_screen_id = GetActiveScreenId();

    if (active_screen_id == SCR_ID_MOBILE_TV_PLAYER_APP)
        return mtv_player_p->setting.selected_channel;
    else if (active_screen_id == SCR_ID_MOBILE_TV_PLAYER_CHANNEL_LIST)
        return mtv_player_p->selected_channel;
    else
    {
        EXT_ASSERT(0,0,0,0);
        return 0;        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_scrolling_text_redraw_bg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_scrolling_text_redraw_bg(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_scrolling_text_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_scrolling_text_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(mtv_player_p->dls_layer_handle);
    gdi_layer_toggle_double();
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gui_handle_scrolling_text(&mtv_player_p->scrolling_label);
    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_set_dynamic_label_and_draw
 * DESCRIPTION
 *  
 * PARAMETERS
 *  PS8
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_set_dynamic_label_and_draw(PS8 str, U16 duration)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_width, str_height;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_ucs2cmp((PS8)mtv_player_p->label_str,(PS8)str) == 0)
    return;
    

    mmi_ucs2ncpy((PS8)mtv_player_p->label_str,(PS8)str,127);
    gui_set_font(&MMI_medium_font);
    gui_measure_string((UI_string_type) mtv_player_p->label_str, &str_width, &str_height);

    if (mtv_player_p->scrolling_label_state == MTV_PLAYER_SCROLLING_TEXT_SCROLLING)
    {
        gui_scrolling_text_stop(&mtv_player_p->scrolling_label);
        mtv_player_p->scrolling_label_state= MTV_PLAYER_SCROLLING_TEXT_OFF;
    }

    if ( str_width > mtv_player_p->active_osd_cntx_p->title.width )
    {
        gdi_layer_push_and_set_active(mtv_player_p->dls_layer_handle);
        gdi_layer_toggle_double();
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
        gui_create_scrolling_text(
            &mtv_player_p->scrolling_label,
            0,
            0,
            mtv_player_p->active_osd_cntx_p->title.width,
            mtv_player_p->active_osd_cntx_p->title.height,
            (UI_string_type) mtv_player_p->label_str,
            mmi_mtv_player_scrolling_text_handle,
            mmi_mtv_player_scrolling_text_redraw_bg,
            gui_color(67,87,153),
            gui_color(255, 255, 255));

        mtv_player_p->scrolling_label.flags |=UI_SCROLLING_TEXT_BORDERED_TEXT;
        gui_show_scrolling_text(&mtv_player_p->scrolling_label);
        mtv_player_p->scrolling_label_state= MTV_PLAYER_SCROLLING_TEXT_SCROLLING;
        gdi_layer_pop_and_restore_active();
    }
    else
    {
        mtv_player_p->scrolling_label_state= MTV_PLAYER_SCROLLING_TEXT_ON;
        mmi_mtv_player_draw_dls();
        gdi_lcd_blt(mtv_player_p->preview_layer_handle, mtv_player_p->osd_layer_handle, mtv_player_p->dls_layer_handle, 0);
    }
}


#if defined(__MMI_MTV_A2DP_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_highlight_bluetooth_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  PS8
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_highlight_bluetooth_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_audply_entry_bluetooth_settings, KEY_EVENT_UP);
    SetKeyHandler(mmi_audply_entry_bluetooth_settings, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
}
#endif


#if defined(__MMI_MTV_A2DP_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_is_output_to_bt
 * DESCRIPTION
 *  a callback function invoked by av_bt_open apis
 * PARAMETERS
 *  result
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_mtv_player_is_output_to_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
   
    if (mmi_audply_is_output_to_bt())
    {
        //MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_RET, MMI_TRUE);
        return MMI_TRUE;
    }
    else
    {
        //MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_RET, MMI_FALSE);
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_stop_bt_connecting_anim
 * DESCRIPTION
 *  draw title
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_stop_bt_connecting_anim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdoply_cntx.bt_connecting_anim != GDI_NULL_HANDLE)
    {    
        gdi_image_stop_animation(mtv_player_p->bt_connect_amin_handle);
        mtv_player_p->bt_connect_amin_handle = GDI_NULL_HANDLE;  
        
        gdi_layer_push_and_set_active(mtv_player_p->process_layer_handle);
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
        gdi_layer_pop_and_restore_active();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_draw_bt_connecting_anim
 * DESCRIPTION
 *  draw bt connecting animation if wait > 600ms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_draw_bt_connecting_anim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mtv_player_p->bt_connect_amin_handle!= GDI_NULL_HANDLE)
    {
        gdi_layer_push_and_set_active(mtv_player_p->process_layer_handle);   
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
        gdi_anim_draw_id(0,0,IMG_ID_MOBILE_TV_LOADING,&mtv_player_p->bt_connect_amin_handle);
        gdi_layer_pop_and_restore_active();
    }
    else
        ASSERT(0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_get_bt_headset
 * DESCRIPTION
 *  retrieve the user selected bt headset
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_bt_dev_struct*
 *****************************************************************************/
static mmi_bt_dev_struct *mmi_mtv_player_get_bt_headset(void)
{
    return mmi_audply_get_bt_headset();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_bt_open_callback
 * DESCRIPTION
 *  a callback function invoked by av_bt_open apis
 * PARAMETERS
 *  result
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_bt_open_callback(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/      
    //MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_BT_OPEN_CALLBACK, result);       
    
    gui_cancel_timer(mmi_mtv_player_draw_bt_connecting_anim);
    mmi_mtv_player_stop_bt_connecting_anim();
    
    switch (result)
    {
        case AV_BT_CALLBACK_EVENT_OPEN_OK:
            /* 
             *  NOTICE: even after receive EVENT_OPEN_FAILED or EVENT_OPEN_STOPPED,
             *          bt driver may still send EVENT_OPEN_OK, this is due to driver 
             *          has retry mechanism.
             */           
            if (PLAYER_STATE_IN(MTV_PLAYER_BT_CONNECT))
            {
                //MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_CALLING_AV_BT_OPEN_CODEC, __LINE__);                   
                av_bt_open_codec(KAL_FALSE);                
                MTV_ENTER_STATE(player,MMI_MTV_PLAYER,MTV_PLAYER_PLAY);
            }    
            else if (PLAYER_STATE_IN(MTV_PLAYER_PLAY))
            {
                /* 
                 * since it is already play, we may set TRUE, which will directly
                 * change output to BT 
                 */
                //MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_CALLING_AV_BT_OPEN_CODEC, __LINE__);                    
                av_bt_open_codec(KAL_TRUE);
            }            
            break;

        case AV_BT_CALLBACK_EVENT_OPEN_FAILED:
        case AV_BT_CALLBACK_EVENT_OPEN_STOPPED:
            if (PLAYER_STATE_IN(MTV_PLAYER_BT_CONNECT))
            {
                 /* connect failed - play the video */
                 mmi_vdoply_enter_state(VDOPLY_STATE_PLAY);
            }
            else
            {
                /* already connected, driver abort */
                //MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_CALLING_AV_BT_CLOSE_CODEC, __LINE__);                   
                av_bt_close_codec();
            }
            break;
            
        case AV_BT_CALLBACK_EVENT_OPEN_CANCELED:
            MMI_ASSERT(0);
            break;
            
        case AV_BT_CALLBACK_EVENT_STREAM_ABORT_IND:
        case AV_BT_CALLBACK_EVENT_STREAM_CLOSE_IND:
        case AV_BT_CALLBACK_EVENT_STREAM_SUSPEND_IND:
        case AV_BT_CALLBACK_EVENT_UNEXPECTED_DISCONNECT_IND:
            /* TODO: display popup to show BT disconnect */
            //MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_CALLING_AV_BT_CLOSE_CODEC, __LINE__);   
            av_bt_close_codec();
            break;
        
        case AV_BT_CALLBACK_EVENT_STREAM_START_IND:
        case AV_BT_CALLBACK_EVENT_INQUIRY_START_IND:        
        case AV_BT_CALLBACK_EVENT_INQUIRY_STOP_IND:        
            /* ignore */
            break;

        default:
            MMI_ASSERT(0);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_disconnect_bt
 * DESCRIPTION
 *  start play video
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_disconnect_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_DISCONNECT_BT);      

    gui_cancel_timer(mmi_mtv_player_draw_bt_connecting_anim);
    mmi_mtv_player_stop_bt_connecting_anim();

    if (mmi_mtv_player_is_output_to_bt())
    {
        //MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_CALLING_AV_BT_CLOSE, __LINE__);             
        av_bt_close(FALSE);
    }
    /* TODO: stop anim */
}



/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_bt_close_codec
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_player_bt_close_codec(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_BT_CLOSE_CODEC);      
    
    if (mmi_mtv_player_is_output_to_bt())
    {
        //MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_CALLING_AV_BT_CLOSE_CODEC, __LINE__);          
        av_bt_close_codec();
    }
 
}
#endif /* __MMI_MTV_A2DP_SUPPORT__ */


#ifdef __MMI_MTV_AVRCP_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_bt_avrcp_cmd_hdlr
 * DESCRIPTION
 *  ACRCP command handler
 * PARAMETERS
 *  command     [IN]     command type
 *  event       [IN]     key event
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static U8 mmi_mtv_player_bt_avrcp_cmd_hdlr(U8 command, mmi_avrcp_key_events event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result = MMI_AVRCP_CR_ACCEPT;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/




    switch (command)
    {
        case MMI_AVRCP_POP_PLAY:
        case MMI_AVRCP_POP_PAUSE:    
            PRINT_INFORMATION("[MTV_AVRCP] command: PLAY or POP, line:%d", __LINE__);    
                    
            /* full screen */
            if (event == MMI_AVRCP_KEY_UP)
            {
                PRINT_INFORMATION("[MTV_AVRCP] event: KEY_UP, line:%d", __LINE__);    
                //mmi_vdoply_ck_release();
            }
            else if (event == MMI_AVRCP_KEY_DOWN)
            {
                PRINT_INFORMATION("[MTV_AVRCP] event: KEY_DOWN, line:%d", __LINE__);                        
                //mmi_vdoply_ck_press();
            }
            else if (event == MMI_AVRCP_KEY_CANCELED)
            {
                PRINT_INFORMATION("[MTV_AVRCP] event: KEY_CANCELED, line:%d", __LINE__);                      
                //g_vdoply_cntx.touch_ck.is_press = FALSE;
                //mmi_vdoply_draw_fullscr_osd();
                //mmi_vdoply_blt_screen();
            }
            else
            {
                /* ingore others */
            }        

            break;

        case MMI_AVRCP_POP_STOP:
            PRINT_INFORMATION("[MTV_AVRCP] command: STOP, line:%d", __LINE__);   

           if (g_vdoply_cntx.state == VDOPLY_STATE_FULLSCR_PLAY || 
                g_vdoply_cntx.state == VDOPLY_STATE_FULLSCR_PAUSE ||
                g_vdoply_cntx.state == VDOPLY_STATE_FULLSCR_BT_CONNECTING ||
                g_vdoply_cntx.state == VDOPLY_STATE_FULLSCR_SEEKING || 
                g_vdoply_cntx.state == VDOPLY_STATE_FULLSCR_PLAY_SEEKING ||
                g_vdoply_cntx.state == VDOPLY_STATE_STREAM_FULLSCR_PLAY ||
                g_vdoply_cntx.state == VDOPLY_STATE_STREAM_FULLSCR_CONNECTING ||
                g_vdoply_cntx.state == VDOPLY_STATE_STREAM_FULLSCR_INTERRUPTED_CONNECTING ||
                g_vdoply_cntx.state == VDOPLY_STATE_STREAM_FULLSCR_BUFFERING ||
                g_vdoply_cntx.state == VDOPLY_STATE_STREAM_FULLSCR_BT_CONNECTING)
            {
                /* full screen */
                if (event == MMI_AVRCP_KEY_UP)
                {
                    PRINT_INFORMATION("[MTV_AVRCP] event: KEY_UP, line:%d", __LINE__);                            
                    //mmi_vdoply_rsk_release();
                }
                else if (event == MMI_AVRCP_KEY_DOWN)
                {
                    PRINT_INFORMATION("[MTV_AVRCP] event: KEY_DOWN, line:%d", __LINE__);                            
                    //mmi_vdoply_rsk_press();
                }
                else if (event == MMI_AVRCP_KEY_CANCELED)
                {
                    PRINT_INFORMATION("[MTV_AVRCP] event: KEY_CANCELED, line:%d", __LINE__);                             
                    //g_vdoply_cntx.touch_rsk.is_press = FALSE;
                    //mmi_vdoply_draw_fullscr_osd();
                    //mmi_vdoply_blt_screen();
                }
                else
                {
                    /* ingore others */
                }   
            }
            break;

        default:
            result = MMI_AVRCP_CR_NOT_IMPLEMENT;
            break;
    }

    return result;

}
#endif /* __MMI_AVRCP_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_player_get_error_string_by_error_enum
 * DESCRIPTION
 *  Get error string by error code.
 * PARAMETERS
 *  err_code
 * RETURNS
 *  error string id
 *****************************************************************************/
MMI_ID_TYPE mmi_mtv_player_get_error_string_by_error_enum(S32 err_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID_TYPE string_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (err_code)
        switch (mtv_player_p->last_error)
        {

            case MDI_RES_MTV_ERR_CORRUPT_FAT:
                string_id = FMGR_FS_FAT_ALLOC_ERROR_TEXT;
                break;
            case MDI_RES_MTV_ERR_ROOT_DIR_FULL:
                string_id = FMGR_FS_ROOT_DIR_FULL_TEXT;
                break;                
            case MDI_RES_MTV_ERR_DISK_FULL:
            case MDI_RES_MTV_ERR_PHONE_DISK_FULL:
            case MDI_RES_MTV_ERR_CARD_DISK_FULL:
                string_id = FMGR_FS_DISK_FULL_TEXT;
                break;
            case MDI_RES_MTV_ERR_NO_DISK:
                string_id = STR_ID_MOBILE_TV_PLAYER_NOTIFY_STORAGE_NOT_READY;
                break;
            case MDI_RES_MTV_ERR_WRITE_PROTECTION:
                string_id = STR_ID_MOBILE_TV_PLAYER_NOTIFY_WRITE_PROTECTION;
                break;
                /* followings are serious error, has to exit app */
            case MDI_RES_MTV_ERR_POWER_ON_FAILED:
                string_id = STR_ID_MOBILE_TV_PLAYER_NOTIFY_HW_NOT_READY;
                break;

            case MDI_RES_MTV_ERR_PREVIEW_FAILED:
            case MDI_RES_MTV_ERR_RESUME_FAILED:
            case MDI_RES_MTV_ERR_PAUSE_FAILED:
            case MDI_RES_MTV_ERR_SAVE_FILE_FAILED:
            case MDI_RES_MTV_ERR_RECORD_FAILED:
            case MDI_RES_MTV_ERR_FAILED:
            default:
                string_id = STR_ID_MOBILE_TV_PLAYER_NOTIFY_ERROR;
                break;
        }

    return string_id;
}


#endif /* __MMI_MOBILE_TV_PLAYER__ */ 

