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
 *   FunAndGamesSrc.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Fun And Game source file
 *
 * Author:
 * -------
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"


#include "MainMenuDef.h"

#include "wgui_inline_edit.h"

#include "FunAndGamesDefs.h"    /* app header files */
#include "FunAndGamesProts.h"
#include "GameProts.h"
#include "MMIThemes.h"
#include "DownloadProtos.h"
#include "ComposeRingToneProts.h"
#include "VoiceMemoProt.h"
#include "SettingProfile.h"     /* SUCCESS_TONE */
#include "SettingDefs.h"        /* ST_NOTIFCATION */
#include "CommonScreens.h"      /* popup */
#include "wapadp.h"
#include "SimDetectionGprot.h"
#include "CommonScreens.h"

#if defined(__MMI_GAME__)
#include "GameFramework.h"
#endif 

#if defined(__MMI_3D_GAME__)
#include "Game3DGprot.h"
#endif 

#if defined(__MMI_PICTURE_EDITOR_SUPPORT__)
#include "PictureEditorProts.h"
#endif 

#if defined(__J2ME__)
#include "JavaAgencyDef.h"
#include "JavaAgencyGprot.h"
#include "wapadp.h"
#include "wap_ps_struct.h"
#include "jam_msg_handler.h"
#include "jvm_interface.h"
#include "j2me_custom.h"
#include "j2me_custom_option.h"
#include "j2me_custom_param.h"
#include "j2me_custom.h"
#endif /* defined(__J2ME__) */ 

#if defined(__MMI_RING_COMPOSER__) && defined(__MMI_IMELODY_SUPPORT__)
#include "ComposeRingToneProts.h"
#endif 

#if defined(__MMI_VOICE_MEMO__)
#include "VoiceMemoProt.h"
#endif 

#if defined(__MMI_AUDIO_PLAYER__)
#include "mdi_datatype.h"       /* dependent headers for AudioPlayerProt.h" */
#include "AudioPlayerProt.h"
#endif /* defined(__MMI_AUDIO_PLAYER__) */ 


#if defined(__MMI_IMAGE_VIEWER__)
#include "FileManagerGprot.h"
#include "filemgr.h"
#include "ImageViewer.h"
#endif 

#if defined(__MMI_AVATAR__)
#include "AVATARGPROT.h"
#endif /* defined(__MMI_AVATAR__) */ 

#if defined(__MMI_MOBILE_TV_PLAYER__)
#include "MobileTVPlayerGprot.h"
#endif


#if defined(__MMI_CAMERA__)
#include "mdi_datatype.h"       /* dependent headers for mdi_camera.h" */
#include "mdi_camera.h"
#include "CameraApp.h"
#endif /* defined(__MMI_CAMERA__) */ 

#if defined( __MMI_BARCODEREADER__)
#include "barcodereadergprot.h"
#endif /* __MMI_BARCODEREADER__ */


#if defined(__MMI_VIDEO_PLAYER__)
#include "VdoPlyGProt.h"
#endif 

#if defined(__MMI_VIDEO_RECORDER__)
#include "VdoRecGProt.h"
#endif 

#if defined(__MMI_PHOTOEDITOR__)
#include "PhotoEditorGProt.h"
#endif 

#if defined(__MMI_VIDEO_EDITOR__)
#include "VdoEdtGProt.h"
#endif

#ifdef __MMI_FM_RADIO__
#include "FMRadioProt.h"
#ifdef __MMI_FM_RADIO_CHECK_CHIP_OR_HIDE__
extern void mmi_fmrdo_skip_highlight_hdlr(S32 index);   /* defined in FMRadioSrc.c */
extern U16 mmi_fmrdo_check_chip_or_hide(U16 n_items, U16 *string_ids, U16 *icon_ids); /* defined in FMRadioSrc.c */
#endif /* __MMI_FM_RADIO_CHECK_CHIP_OR_HIDE__ */ 
#endif /* __MMI_FM_RADIO__ */ 

#if defined(__MMI_PHB_CALLER_RES_SETTING__)
#include "MessagesEXDcl.h"
#include "SimDetectionGexdcl.h"
#endif /* defined(__MMI_PHB_CALLER_RES_SETTING__) */ 

#ifdef __MMI_AB_REPEATER__
#include "mdi_datatype.h"
#include "ABRepeaterProt.h"
#endif /* __MMI_AB_REPEATER__ */ 

#ifdef __MMI_SLIDESHOW__
#include "SlideShowGProt.h"
#endif

#if defined(__MMI_DUAL_SIM_MASTER__)
#include "MTPNP_AD_master_header.h"
#endif  /* __MERCURY_MASTER__ */



/***************************************************************************** 
* Constance
*****************************************************************************/
#define MAX_MEMORY_SIZE 16

/***************************************************************************** 
* Struct
*****************************************************************************/

#if defined (__J2ME__)

typedef enum
{
    FNG_SETTING_JAVA_AUD,
    FNG_SETTING_JAVA_VIB,
#ifdef SUPPORT_JAVA_NET_ICON_SETTING
    FNG_SETTING_JAVA_NET_ICON,
#endif
#ifdef __MMI_FOURWAYS_KEY_DISABLE__
    FNG_SETTING_JAVA_VK,
#endif
    FNG_SETTING_JAVA_PROF,
#ifdef JAVA_SETTING_SHOW_FREE_STORAGE
    FNG_SETTING_JAVA_STORAGE,
#endif
    FNG_SETTING_JAVA_HEAP,
    FNG_SETTING_JAVA_ITEM_COUNT
} fng_setting_java_inline_enum;

typedef struct
{

#define MAX_WAP_PROF_SUM 16

    UI_string_type java_aud_str[8];
    S32 java_aud_selected;

    UI_string_type java_vib_str[2];
    S32 java_vib_selected;

#ifdef SUPPORT_JAVA_NET_ICON_SETTING
    UI_string_type java_net_icon_str[2];
    S32 java_net_icon_selected;
#endif

#ifdef __MMI_FOURWAYS_KEY_DISABLE__
    UI_string_type java_vk_permission_str[3];
    S32 java_vk_permission_selected;
#endif /* __MMI_FOURWAYS_KEY_DISABLE__ */ 

    U8 java_prof_id[MAX_WAP_PROF_SUM + 2];              /* default + disable + profiles */
    UI_string_type java_prof_str[MAX_WAP_PROF_SUM + 2]; /* default + disable + profiles */
    S32 java_prof_selected;
    S32 java_prof_sum;
    UI_character_type java_prof_strs[MAX_WAP_PROF_SUM][WAP_PROF_MAX_NAME_SIZE];

#ifdef JAVA_SETTING_SHOW_FREE_STORAGE
    UI_string_type java_storage_str[1];
    S32 java_storage_selected;
    UI_character_type java_storage_strs[1][MAX_MEMORY_SIZE];
#endif

    UI_string_type java_heap_str[1];
    S32 java_heap_selected;
    UI_character_type java_heap_strs[1][MAX_MEMORY_SIZE];

    /* inline selection item */
    InlineItem inline_java_items[FNG_SETTING_JAVA_ITEM_COUNT *2];      /* one for caption, one for selection */

} fng_setting_inline_data_struct;

typedef struct
{
    fng_setting_inline_data_struct setting_inline;
    #ifdef OGDR_SECURITY_SETTING
    S32 domain_selected;
    S32 total_domain;
    U16 domains[11][30];  /* 10+1 (Reset) */
    #endif
} fng_cntx_struct;

#endif /* defined (__J2ME__) */ 

/***************************************************************************** 
* Global Variable
*****************************************************************************/
extern wgui_inline_item wgui_inline_items[];

/***************************************************************************** 
* Local Variable
*****************************************************************************/
#if defined (__J2ME__)
fng_cntx_struct g_fng_cntx;
#endif 

/***************************************************************************** 
* Local Function
*****************************************************************************/
void mmi_fng_highlight_setting_java(void);
void mmi_fng_real_entry_setting_java_screen(void);
#ifdef OGDR_SECURITY_SETTING
void mmi_fng_highlight_security_java(void);
void mmi_fng_real_entry_security_java(void);
#endif

/***************************************************************************** 
* External Function
*****************************************************************************/
extern kal_uint32 get_mids_avail_storage(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_fng_entry_screen
 * DESCRIPTION
 *  entry FunAndGame menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fng_entry_screen(void)
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
    EntryNewScreen(SCR3000_FUNANDGAMES, NULL, mmi_fng_entry_screen, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR3000_FUNANDGAMES);
    nItems = GetNumOfChild(MAIN_MENU_FUNANDGAMES_MENUID);
    GetSequenceStringIds(MAIN_MENU_FUNANDGAMES_MENUID, ItemList);
    GetSequenceImageIds(MAIN_MENU_FUNANDGAMES_MENUID, ItemIcons);
    SetParentHandler(MAIN_MENU_FUNANDGAMES_MENUID);
#if defined(__MMI_FM_RADIO__) && defined(__MMI_FM_RADIO_CHECK_CHIP_OR_HIDE__)
    RegisterHighlightHandler(mmi_fmrdo_skip_highlight_hdlr);
    nItems = mmi_fmrdo_check_chip_or_hide(nItems, ItemList, ItemIcons);
#else /* defined(__MMI_FM_RADIO__) && defined(__MMI_FM_RADIO_CHECK_CHIP_OR_HIDE__) */ 
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
#endif /* defined(__MMI_FM_RADIO__) && defined(__MMI_FM_RADIO_CHECK_CHIP_OR_HIDE__) */ 

#if defined(__MMI_PHB_CALLER_RES_SETTING__)
    /* No SIM, remove caller picture menu items */
#if !defined(__MMI_DUAL_SIM_MASTER__)
    if (mmi_bootup_is_sim_valid() == MMI_FALSE)
#else   /* __MMI_DUAL_SIM_MASTER__ */
    if (mmi_bootup_is_sim_valid() == MMI_FALSE && MTPNP_PFAL_Is_Card2Absent())
#endif  /* __MMI_DUAL_SIM_MASTER__ */
    {
        S32 MenuItemId;

        MenuItemId = GetChildMenuIDIndexByParentMenuID(MAIN_MENU_FUNANDGAMES_MENUID, MENU_ID_PHB_CALLER_RING_1);
        if (MenuItemId != -1)   /* Menu Exists. */
        {
            nItems -= 1;
        }
    }
#endif /* defined(__MMI_PHB_CALLER_RES_SETTING__) */ 
    /* MTK Leo add, mini_tab_bar */
#ifdef __MMI_WGUI_MINI_TAB_BAR__
    wgui_enable_mini_tab_bar(MAIN_MENU_FUNANDGAMES_MENUID);
#endif 
    /* MTK Leo end */

    ShowCategory52Screen(
        STR_SCR3000_FUNANDGAMES_CAPTION,
    #if defined(__MMI_OP01_MENU_NOSIM_LIST__) && defined(__MMI_OP01_MENU_9MATRIX__)
/* under construction !*/
    #else
        GetRootTitleIcon(MAIN_MENU_FUNANDGAMES_MENUID),
    #endif
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
 *  mmi_fng_no_support_java
 * DESCRIPTION
 *  FunAndGame intilize funtion for each app and hilite hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if !defined(__J2ME__)
#if !defined(__MTK_TARGET__)
void mmi_fng_no_support_java(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(PopupNoSupport, KEY_EVENT_UP);
    SetKeyHandler(PopupNoSupport, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
#endif /* !defined(__MTK_TARGET__) */ 
#endif /* !defined(__J2ME__) */ 



/*****************************************************************************
 * FUNCTION
 *  mmi_fng_no_support_java
 * DESCRIPTION
 *  FunAndGame intilize funtion for each app and hilite hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if !defined(__MTK_TARGET__)
void mmi_fng_no_support_eureka(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(PopupNoSupport, KEY_EVENT_UP);
    SetKeyHandler(PopupNoSupport, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
#endif /* !defined(__MTK_TARGET__) */ 



/*****************************************************************************
 * FUNCTION
 *  mmi_fng_init_app
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fng_init_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VOICE_MEMO__)
    InitVoiceMemoApp();
#endif 

#if defined(__MMI_GAME__)
    SetHiliteHandler(MENU3105_GAMES, mmi_game_highlight_app);
#endif

#if defined(__MMI_3D_GAME__)
    SetHiliteHandler(MENU_ID_FNG_3D_GAME, mmi_game3d_highlight_app);
#endif 

#if defined(__MMI_MOTION_APP__)
    SetHiliteHandler(MENU_ID_MOTION_APP, mmi_motion_highlight_app);

    mmi_motion_init();
#endif /* defined(__MMI_MOTION_APP__) */ /* __MMI_GAME__ */

#if defined(__MMI_AUDIO_PLAYER__)
    InitAudioPlayerApp();
#endif 

#if defined( __MMI_BARCODEREADER__)
    mmi_barcodereader_init_app();
#endif /* __MMI_BARCODEREADER__ */

#if defined(__MMI_MOBILE_TV_PLAYER__)
    mmi_mtv_player_init_app();
#endif

#if defined(__MMI_AVATAR__)
    mmi_avatar_init_app();
#endif

#ifdef __MMI_AB_REPEATER__
    InitABRepeaterApp();
#endif 

#if defined(__MMI_CAMERA__)
    mmi_camera_init_app();
#endif 

#if defined(__MMI_IMAGE_VIEWER__)
    mmi_imgview_init_app();
#endif 

#if defined(__MMI_VIDEO_PLAYER__)
    mmi_vdoply_init_app();
#endif 

#if defined(__MMI_VIDEO_RECORDER__)
    mmi_vdorec_init_app();
#endif 

#if defined(__MMI_VIDEO_EDITOR__)
    mmi_vdoedt_init_app();
#endif

/* hongzhe.liu add start */
#if defined(ANALOG_TV_SUPPORT)
    mmi_analog_tv_init_app();
#endif
/* hongzhe.liu add end */

#if defined(__MMI_PHOTOEDITOR__)
    mmi_phoedt_init_app();
#endif 

    /* [Tim][FM Radio] begin */
#ifdef __MMI_FM_RADIO__
    mmi_fmrdo_init_app();
#endif 
    /* [Tim][FM Radio] end */

#if defined(__MMI_PICTURE_EDITOR_SUPPORT__)
    SetHiliteHandler(MENU_PICTURE_EDITOR, Highlight_MENU_PICTURE_EDITOR);
    InitPictureEditor();
#endif /* defined(__MMI_PICTURE_EDITOR_SUPPORT__) */

#if defined(__J2ME__)
    SetHiliteHandler(MENU3108_JAVA, mmi_java_highlight_menu);
    SetHiliteHandler(MENU_ID_FNG_SETTING_JAVA, mmi_fng_highlight_setting_java);

    InitJAVA();

    #ifdef OGDR_SECURITY_SETTING
    SetHiliteHandler(MENU_ID_FNG_SECURITY_JAVA, mmi_fng_highlight_security_java);
    #endif

    #ifdef __SUPPORT_INFUSIO__
    SetHiliteHandler(MENU_ID_FNG_JAVA_EUREKA, mmi_java_highlight_eureka);
    #endif
#elif !defined(__MTK_TARGET__) /* for PC simulator */
    SetHiliteHandler(MENU3108_JAVA, mmi_fng_no_support_java);
    SetHiliteHandler(MENU_ID_FNG_SETTING_JAVA, mmi_fng_no_support_java);
    #ifdef OGDR_SECURITY_SETTING
    SetHiliteHandler(MENU_ID_FNG_SECURITY_JAVA, mmi_fng_no_support_java);
    #endif

    #ifdef __SUPPORT_INFUSIO__
    SetHiliteHandler(MENU_ID_FNG_JAVA_EUREKA, mmi_fng_no_support_eureka);
    #endif
#endif 

#if defined(__MMI_SLIDESHOW__)
    mmi_slidshow_init_app();
#endif

}

#if defined(__J2ME__)
/*****************************************************************************
 * FUNCTION
 *  mmi_fng_setting_java_done_hdlr
 * DESCRIPTION
 *  done hdlr for java setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fng_setting_java_done_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* java effect */
    g_mmi_java_aud_volume_level = g_fng_cntx.setting_inline.java_aud_selected;
    g_mmi_java_is_vib_on = g_fng_cntx.setting_inline.java_vib_selected;

#ifdef SUPPORT_JAVA_NET_ICON_SETTING
    g_mmi_java_is_net_icon_on = g_fng_cntx.setting_inline.java_net_icon_selected;
#endif

#ifdef __MMI_FOURWAYS_KEY_DISABLE__
    g_mmi_java_vk_permission = g_fng_cntx.setting_inline.java_vk_permission_selected;
#endif 
    g_mmi_java_wap_prof_id = g_fng_cntx.setting_inline.java_prof_id[g_fng_cntx.setting_inline.java_prof_selected];
    mmi_java_store_setting();

    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);
    DeleteNHistory(1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fng_setting_java_highlight_hdlr
 * DESCRIPTION
 *  highlight hdlr
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fng_highlight_setting_java_item(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetCategory57LeftSoftkeyFunction(mmi_fng_setting_java_done_hdlr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fng_exit_setting_java_screen
 * DESCRIPTION
 *  exit point for java setting screen
 * PARAMETERS
 *  void
 *  viud(?)     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fng_exit_setting_java_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 inputBufferSize;
    history h;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h.scrnID = SCR_ID_FNG_SETTING_JAVA;
    CloseCategory57Screen();
    h.entryFuncPtr = mmi_fng_real_entry_setting_java_screen;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategory57History(h.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, inputBufferSize);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fng_recv_wap_prof_list_rsp
 * DESCRIPTION
 *  response handler of recv_wap_prof_list_req
 * PARAMETERS
 *  MSG     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fng_recv_wap_prof_list_rsp(void *MSG)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    wap_get_prof_list_rsp_struct *msg = (wap_get_prof_list_rsp_struct*) MSG;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_bootup_is_network_service_available() && msg->result != WAP_PROF_SUCCESS)
    {
        mmi_java_display_is_busy();
        return;
    }
    g_fng_cntx.setting_inline.java_prof_sum = msg->number+1;


    /* the first item is "Default" */
    mmi_ucs2cpy((S8*)g_fng_cntx.setting_inline.java_prof_strs[0], GetString(STR_JAVA_NETWORK_SETTING_DEFAULT));
    g_fng_cntx.setting_inline.java_prof_str[0] = g_fng_cntx.setting_inline.java_prof_strs[0];
    g_fng_cntx.setting_inline.java_prof_id[0] = 0xFF;

    /* real profiles start from second item */
    for (i = 0; i < g_fng_cntx.setting_inline.java_prof_sum && i < MAX_WAP_PROF_SUM; i++)
    {
        memcpy(g_fng_cntx.setting_inline.java_prof_strs[i+1], msg->prof_list[i].name.value, msg->prof_list[i].name.len);

        g_fng_cntx.setting_inline.java_prof_strs[i+1][msg->prof_list[i].name.len / 2] = L'\0';
        g_fng_cntx.setting_inline.java_prof_str[i+1] = g_fng_cntx.setting_inline.java_prof_strs[i+1];
        g_fng_cntx.setting_inline.java_prof_id[i+1] = msg->prof_list[i].id;
    }
    if (msg->prof_list)
    {
        OslMfree(msg->prof_list);
    }

    mmi_fng_real_entry_setting_java_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fng_entry_setting_java_screen
 * DESCRIPTION
 *  entry point for java setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fng_entry_setting_java_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_fng_recv_wap_prof_list_rsp, MSG_ID_WAP_GET_PROF_LIST_RSP);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = wap_get_service_module(MSG_ID_WAP_GET_PROF_LIST_REQ);
    Message.oslMsgId = MSG_ID_WAP_GET_PROF_LIST_REQ;
    Message.oslDataPtr = (local_para_struct*) NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fng_real_entry_setting_java_screen
 * DESCRIPTION
 *  real entry point for java setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fng_real_entry_setting_java_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;
    S32 item_offset = 0;
    S8 javaTempString[2][MAX_MEMORY_SIZE];

    MMI_ID_TYPE item_icons[] = 
    {
        IMG_ID_FNG_SETTING_JAVA_AUD,
        0,
        IMG_ID_FNG_SETTING_JAVA_VIB,
        0,
    #ifdef SUPPORT_JAVA_NET_ICON_SETTING
        IMG_ID_FNG_SETTING_JAVA_NET_ICON,
        0,
    #endif

    #ifdef __MMI_FOURWAYS_KEY_DISABLE__
        IMG_ID_FNG_SETTING_JAVA_VK,
        0,
    #endif /* __MMI_FOURWAYS_KEY_DISABLE__ */ 
        IMG_ID_FNG_SETTING_JAVA_PROF_ID,
        0,
    #ifdef JAVA_SETTING_SHOW_FREE_STORAGE
        IMG_ID_FNG_SETTING_JAVA_STORAGE,
        0,
    #endif
        IMG_ID_FNG_SETTING_JAVA_HEAP,
        0,

    #ifdef __SUPPORT_INFUSIO__
        IMG_ID_FNG_JAVA_EUREKA,	
        0,
    #endif /* __SUPPORT_INFUSIO__ */

    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_java_check_and_display_is_busy())
    {
        return;
    }

    EntryNewScreen(SCR_ID_FNG_SETTING_JAVA, mmi_fng_exit_setting_java_screen, NULL, NULL);

   /***************************************************************************** 
   * JAVA  
   *****************************************************************************/
    /* JAVA TODO: Set value here */

    g_fng_cntx.setting_inline.java_aud_selected = g_mmi_java_aud_volume_level;
    g_fng_cntx.setting_inline.java_vib_selected = g_mmi_java_is_vib_on;
#ifdef SUPPORT_JAVA_NET_ICON_SETTING
    g_fng_cntx.setting_inline.java_net_icon_selected = g_mmi_java_is_net_icon_on;
#endif

#ifdef __MMI_FOURWAYS_KEY_DISABLE__
    g_fng_cntx.setting_inline.java_vk_permission_selected = g_mmi_java_vk_permission;
#endif 
    if( g_mmi_java_wap_prof_id == 0xFF) /* default */
        g_fng_cntx.setting_inline.java_prof_selected = 0;
    else
        g_fng_cntx.setting_inline.java_prof_selected = g_mmi_java_wap_prof_id+1;
#ifdef JAVA_SETTING_SHOW_FREE_STORAGE
    g_fng_cntx.setting_inline.java_storage_selected = 0;
#endif
    g_fng_cntx.setting_inline.java_heap_selected = 0;

    g_fng_cntx.setting_inline.java_aud_str[0] = (UI_string_type) GetString((U16) (STR_GLOBAL_OFF));
    g_fng_cntx.setting_inline.java_aud_str[1] = (UI_string_type) L"1";
    g_fng_cntx.setting_inline.java_aud_str[2] = (UI_string_type) L"2";
    g_fng_cntx.setting_inline.java_aud_str[3] = (UI_string_type) L"3";
    g_fng_cntx.setting_inline.java_aud_str[4] = (UI_string_type) L"4";
    g_fng_cntx.setting_inline.java_aud_str[5] = (UI_string_type) L"5";
    g_fng_cntx.setting_inline.java_aud_str[6] = (UI_string_type) L"6";
    g_fng_cntx.setting_inline.java_aud_str[7] = (UI_string_type) L"7";

    g_fng_cntx.setting_inline.java_vib_str[0] = (UI_string_type) GetString((U16) (STR_GLOBAL_OFF));
    g_fng_cntx.setting_inline.java_vib_str[1] = (UI_string_type) GetString((U16) (STR_GLOBAL_ON));

#ifdef SUPPORT_JAVA_NET_ICON_SETTING
    g_fng_cntx.setting_inline.java_net_icon_str[0] = (UI_string_type) GetString((U16) (STR_GLOBAL_OFF));
    g_fng_cntx.setting_inline.java_net_icon_str[1] = (UI_string_type) GetString((U16) (STR_GLOBAL_ON));
#endif

#ifdef __MMI_FOURWAYS_KEY_DISABLE__
    g_fng_cntx.setting_inline.java_vk_permission_str[0] = (UI_string_type) GetString((U16) STR_JAVA_PERM_BLANKET);
    g_fng_cntx.setting_inline.java_vk_permission_str[1] = (UI_string_type) GetString((U16) STR_JAVA_PERM_ONESHOT);
    g_fng_cntx.setting_inline.java_vk_permission_str[2] = (UI_string_type) GetString((U16) STR_JAVA_PERM_USERDENY);
#endif /* __MMI_FOURWAYS_KEY_DISABLE__ */ 

#ifdef JAVA_SETTING_SHOW_FREE_STORAGE
    memset(javaTempString[0], 0, sizeof(javaTempString[0]));
    sprintf(javaTempString[0], "%u ", get_mids_avail_storage());
    mmi_asc_to_ucs2((S8*) g_fng_cntx.setting_inline.java_storage_strs[0], (S8*) javaTempString[0]);
    mmi_ucs2cat((S8*) g_fng_cntx.setting_inline.java_storage_strs[0], GetString((U16) STR_JAVA_INFO_BYTE));
    g_fng_cntx.setting_inline.java_storage_str[0] = g_fng_cntx.setting_inline.java_storage_strs[0];
#endif

    memset(javaTempString[1], 0, sizeof(javaTempString[1]));
    sprintf(javaTempString[1], "%u ", jvm_get_heap_size());
    mmi_asc_to_ucs2((S8*) g_fng_cntx.setting_inline.java_heap_strs[0], (S8*) javaTempString[1]);
    mmi_ucs2cat((S8*) g_fng_cntx.setting_inline.java_heap_strs[0], GetString((U16) STR_JAVA_INFO_BYTE));
    g_fng_cntx.setting_inline.java_heap_str[0] = g_fng_cntx.setting_inline.java_heap_strs[0];

    memset(
        (void*)g_fng_cntx.setting_inline.inline_java_items,
        0,
        sizeof(InlineItem) * FNG_SETTING_JAVA_ITEM_COUNT * 2);

    InitializeCategory57Screen();

    /* java audio */
    SetInlineItemCaption(
        &g_fng_cntx.setting_inline.inline_java_items[item_offset++],
        (PU8) GetString((U16) (STR_ID_FNG_SETTING_JAVA_AUD)));

    SetInlineItemActivation(
        &g_fng_cntx.setting_inline.inline_java_items[item_offset],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);

    SetInlineItemSelect(
        &g_fng_cntx.setting_inline.inline_java_items[item_offset++],
        8,
        (U8 **) g_fng_cntx.setting_inline.java_aud_str,
        &g_fng_cntx.setting_inline.java_aud_selected);

    /* java vibration */
    SetInlineItemCaption(
        &g_fng_cntx.setting_inline.inline_java_items[item_offset++],
        (PU8) GetString((U16) (STR_ID_FNG_SETTING_JAVA_VIB)));

    SetInlineItemActivation(
        &g_fng_cntx.setting_inline.inline_java_items[item_offset],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);

    SetInlineItemSelect(
        &g_fng_cntx.setting_inline.inline_java_items[item_offset++],
        2,
        (U8 **) g_fng_cntx.setting_inline.java_vib_str,
        &g_fng_cntx.setting_inline.java_vib_selected);

#ifdef SUPPORT_JAVA_NET_ICON_SETTING
    /* java vibration */
    SetInlineItemCaption(
        &g_fng_cntx.setting_inline.inline_java_items[item_offset++],
        (PU8) GetString((U16) (STR_ID_FNG_SETTING_JAVA_NET_ICON)));

    SetInlineItemActivation(
        &g_fng_cntx.setting_inline.inline_java_items[item_offset],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);

    SetInlineItemSelect(
        &g_fng_cntx.setting_inline.inline_java_items[item_offset++],
        2,
        (U8 **) g_fng_cntx.setting_inline.java_net_icon_str,
        &g_fng_cntx.setting_inline.java_net_icon_selected);
#endif

#ifdef __MMI_FOURWAYS_KEY_DISABLE__
    /* java vk permission */
    SetInlineItemCaption(
        &g_fng_cntx.setting_inline.inline_java_items[item_offset++],
        (PU8) GetString((U16) (STR_ID_FNG_SETTING_JAVA_VK)));

    SetInlineItemActivation(
        &g_fng_cntx.setting_inline.inline_java_items[item_offset],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);

    SetInlineItemSelect(
        &g_fng_cntx.setting_inline.inline_java_items[item_offset++],
        3,
        (U8 **) g_fng_cntx.setting_inline.java_vk_permission_str,
        &g_fng_cntx.setting_inline.java_vk_permission_selected);

#endif /* __MMI_FOURWAYS_KEY_DISABLE__ */ 

    /* java prof */
    if (mmi_bootup_is_network_service_available())
    {
        SetInlineItemCaption(
            &g_fng_cntx.setting_inline.inline_java_items[item_offset++],
            (PU8) GetString((U16) (STR_ID_FNG_SETTING_JAVA_PROF_ID)));

        SetInlineItemActivation(
            &g_fng_cntx.setting_inline.inline_java_items[item_offset],
            INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
            0);

        SetInlineItemSelect(
            &g_fng_cntx.setting_inline.inline_java_items[item_offset++],
            g_fng_cntx.setting_inline.java_prof_sum,
            (U8 **) g_fng_cntx.setting_inline.java_prof_str,
            &g_fng_cntx.setting_inline.java_prof_selected);
    }
#ifdef JAVA_SETTING_SHOW_FREE_STORAGE
    /* java storage */
    SetInlineItemCaption(
        &g_fng_cntx.setting_inline.inline_java_items[item_offset++],
        (PU8) GetString((U16) (STR_ID_FNG_SETTING_JAVA_STORAGE)));

    SetInlineItemActivation(
        &g_fng_cntx.setting_inline.inline_java_items[item_offset],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);

    SetInlineItemDisplayOnly(
        &g_fng_cntx.setting_inline.inline_java_items[item_offset++],
        (U8*) g_fng_cntx.setting_inline.java_storage_str[0]);
#endif

    /* java heap */
    SetInlineItemCaption(
        &g_fng_cntx.setting_inline.inline_java_items[item_offset++],
        (PU8) GetString((U16) (STR_ID_FNG_SETTING_JAVA_HEAP)));

    SetInlineItemActivation(
        &g_fng_cntx.setting_inline.inline_java_items[item_offset],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);

    SetInlineItemDisplayOnly(
        &g_fng_cntx.setting_inline.inline_java_items[item_offset++],
        (U8*) g_fng_cntx.setting_inline.java_heap_str[0]);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_FNG_SETTING_JAVA);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_FNG_SETTING_JAVA, &inputBufferSize);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(g_fng_cntx.setting_inline.inline_java_items, FNG_SETTING_JAVA_ITEM_COUNT * 2, inputBuffer);
    }

    RegisterHighlightHandler(mmi_fng_highlight_setting_java_item);

    /* show category */
    ShowCategory57Screen(
        STR_ID_FNG_SETTING_JAVA,
        mmi_java_get_title_icon(),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        item_offset,
        item_icons,
        g_fng_cntx.setting_inline.inline_java_items,
        0,
        guiBuffer);

    /* set key hdlr */
    SetCategory57LeftSoftkeyFunction(mmi_fng_setting_java_done_hdlr);
    SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);
    DisableCategory57ScreenDone();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fng_highlight_setting_java
 * DESCRIPTION
 *  highlight java setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fng_highlight_setting_java(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_fng_entry_setting_java_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_fng_entry_setting_java_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

#ifdef OGDR_SECURITY_SETTING

/*****************************************************************************
 * FUNCTION
 *
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
void mmi_fng_recv_reset_default_setting_cnf(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_reset_default_domain_cnf_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    msg = (mmi_java_reset_default_domain_cnf_struct *) MsgStruct;

    if (msg->error_code != J2ME_NO_ERROR)
    {
        mmi_java_display_is_busy();
        return;
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fng_send_get_domain_list_req
 * DESCRIPTION
 *  Get Java Domain List
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fng_send_reset_default_setting_req(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    mmi_java_reset_default_domain_req_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ClearInputEventHandler(MMI_DEVICE_ALL);

    msg = (mmi_java_reset_default_domain_req_struct*) OslConstructDataPtr(sizeof(mmi_java_reset_default_domain_req_struct));

    msg->type = GAMETYPE_JAVA_GAME;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_J2ME;
    Message.oslMsgId = MSG_ID_MMI_JAVA_RESET_DEFAULT_DOMAIN_REQ;
    Message.oslDataPtr = (local_para_struct*) msg;
    Message.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&Message);
}

/*****************************************************************************
 * FUNCTION
 *
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
void mmi_fng_recv_get_domain_list_cnf(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	S32 i;
    mmi_java_get_domain_list_cnf_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    msg = (mmi_java_get_domain_list_cnf_struct *) MsgStruct;

    if (msg->error_code != J2ME_NO_ERROR)
    {

        DisplayPopup(
            (PU8) GetString(STR_JAVA_ERROR_CODE_UNKNOWN_FAILURE),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);

        return;
    }

    ASSERT(msg->total_domain < 10 && msg->total_domain > 0);

    g_fng_cntx.total_domain = msg->total_domain;

    for(i = 0 ;i < g_fng_cntx.total_domain ;i ++)
    {
        mmi_ucs2cpy( (S8*) g_fng_cntx.domains[i], (S8*) msg->domains[i] );
    }

    mmi_fng_real_entry_security_java();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fng_send_get_domain_list_req
 * DESCRIPTION
 *  Get Java Domain List
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fng_send_get_domain_list_req(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    mmi_java_get_domain_list_req_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ClearInputEventHandler(MMI_DEVICE_ALL);

    msg = (mmi_java_get_domain_list_req_struct*) OslConstructDataPtr(sizeof(mmi_java_get_domain_list_req_struct));

    msg->type = GAMETYPE_JAVA_GAME;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_J2ME;
    Message.oslMsgId = MSG_ID_MMI_JAVA_GET_DOMAIN_LIST_REQ;
    Message.oslDataPtr = (local_para_struct*) msg;
    Message.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&Message);
}

/*****************************************************************************
 * FUNCTION
 *
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fng_security_java_item_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_java_entry_default_domain_setting(g_fng_cntx.domain_selected);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_fng_highlight_security_java_item
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fng_highlight_security_java_item(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_fng_cntx.domain_selected = index;

    if( index == g_fng_cntx.total_domain)
    {
        SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetProtocolEventHandler(mmi_fng_recv_reset_default_setting_cnf, MSG_ID_MMI_JAVA_RESET_DEFAULT_DOMAIN_CNF);
        SetLeftSoftkeyFunction(mmi_fng_send_reset_default_setting_req, KEY_EVENT_UP);
    }
    else
    {
        SetKeyHandler(mmi_fng_security_java_item_lsk_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetLeftSoftkeyFunction(mmi_fng_security_java_item_lsk_hdlr, KEY_EVENT_UP);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fng_entry_setting_java_screen
 * DESCRIPTION
 *  entry point for java setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fng_entry_secuiry_java(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_java_check_and_display_is_busy())
    {
        return;
    }

    SetProtocolEventHandler(mmi_fng_recv_get_domain_list_cnf, MSG_ID_MMI_JAVA_GET_DOMAIN_LIST_CNF);

    mmi_fng_send_get_domain_list_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fng_real_entry_security_java_screen
 * DESCRIPTION
 *  real entry point for java setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fng_real_entry_security_java(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 i;
    U8 *item[MAX_SUB_MENUS];
    U8 *icon[MAX_SUB_MENUS];
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy( (S8*) g_fng_cntx.domains[g_fng_cntx.total_domain],
        (S8*) GetString(STR_ID_FNG_SECURITY_JAVA_RESTORE));
    for (i = 0; i < g_fng_cntx.total_domain +1; i++)
    {
        item[i] = (PU8) g_fng_cntx.domains[i];
        icon[i] = (PU8) GetImage(gIndexIconsImageList[i]);
    }
    guiBuffer = GetCurrGuiBuffer(SCR_ID_FNG_SECURITY_JAVA);
    EntryNewScreen(SCR_ID_FNG_SECURITY_JAVA, NULL, mmi_fng_real_entry_security_java, NULL);
    RegisterHighlightHandler(mmi_fng_highlight_security_java_item);

    ShowCategory170Screen(
        (PU8) GetString(STR_ID_FNG_SECURITY_JAVA),
        (PU8) GetImage(mmi_java_get_title_icon()),
        (PU8) GetString(STR_GLOBAL_OK),
        (PU8) GetImage(IMG_GLOBAL_OK),
        (PU8) GetString(STR_GLOBAL_BACK),
        (PU8) GetImage(IMG_GLOBAL_BACK),
        g_fng_cntx.total_domain + 1 ,
        item,
        icon,
        0,
        0,
        guiBuffer);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fng_highlight_security_java
 * DESCRIPTION
 *  highlight java security
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fng_highlight_security_java(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_fng_entry_secuiry_java, KEY_EVENT_UP);
    SetKeyHandler(mmi_fng_entry_secuiry_java, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
#endif

#endif /* __J2ME__ */

/* NOTICE */
/* THIS FUNCTION should move to picture_editor's source, shall not put here */


/*****************************************************************************
 * FUNCTION
 *  Highlight_MENU_PICTURE_EDITOR
 * DESCRIPTION
 *  highlight picture editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* Yogesh 01032004:  Added for Image Editor */
#ifdef __MMI_PICTURE_EDITOR_SUPPORT__
void Highlight_MENU_PICTURE_EDITOR(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryScr4PicEditSelectMenu, KEY_EVENT_UP);
    SetKeyHandler(EntryScr4PicEditSelectMenu, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
#endif /* __MMI_PICTURE_EDITOR_SUPPORT__ */ 
/* End Added Yogesh 01032004 */
