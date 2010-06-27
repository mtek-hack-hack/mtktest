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
 *  EngineerModeProfiling.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Engineer Mode Profiling
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *******************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_ENGINEER_MODE__

#ifdef WIN32
#include <windows.h>
#endif 
#include "MMI_include.h"

/*****************************************************************************
* Include
*****************************************************************************/
#include "mdi_datatype.h"       /* mdi datatype */
#include "SettingDefs.h"        /* ST_NOTIFYDURATION define */
#include "SettingProfile.h"     /* SUCCESS_TONE define */
#include "wgui.h"       /* for GetDateTime() */
#include "CommonScreens.h"      /* DisplayPopup() */
#include "ProfileGprots.h"      /* playRequestedTone */
#include "gpioInc.h"    /* LED */
#include "nvram_data_items.h"
#include "mdi_audio.h"

#include "lcd_sw_rnd.h" /* lcd colro format */
#include "lcd_if.h"     /* lcd interface */

#ifdef __DRM_SUPPORT__
#include "Drm_gprot.h"  /* DRM support */
#endif /* __DRM_SUPPORT__ */ 

#include "fmt_def.h"
#include "FileMgr.h"
#include "FileManagerDef.h"
#include "FileManagerGProt.h"
#include "FileMgrStruct.h"

#if defined(__MMI_VIDEO_PLAYER__) || defined(__MMI_VIDEO_RECORDER__)
#include "mdi_video.h"
#endif 

#ifdef __MMI_CAMERA__
#include "mdi_camera.h"
#endif 

#ifdef __MMI_TVOUT__
#include "mdi_tv.h"
#endif 

#ifdef __MMI_SUBLCD__
#endif 

#include "EngineerModeDef.h"
#include "EngineerModeType.h"
#include "EngineerModeProt.h"

/*****************************************************************************
* Define
*****************************************************************************/
#define MMI_EM_PROF_INLINE_MAX_ITEM_COUNT   (10)       /* each inline has max 10 items */
#define MMI_EM_PROF_LAYER_BUF_SIZE          ((GDI_LCD_WIDTH*GDI_LCD_HEIGHT*GDI_MAINLCD_BIT_PER_PIXEL)>>3)
#define MMI_EM_PROF_CLIP_SCREEN_SPACING     (5)
#define MMI_EM_PROF_CLIP_SCREEN_BOLDER      (15)
#define MMI_EM_PROF_TEXT_MAX_CHAR           (15)
#define MMI_EM_PROF_HORIZONTAL_VIEW         (1)
/*****************************************************************************
* Typedef
*****************************************************************************/
typedef enum
{
    MMI_EM_PROF_TYPE_CAMERA,
    MMI_EM_PROF_TYPE_VDOREC,
    MMI_EM_PROF_TYPE_VDOPLY,

    /* do not remove last element */
    MMI_EM_PROF_TYPE_TOTAL
} mmi_em_prof_type_enum;

typedef enum
{
    MMI_EM_PROF_ROTATE_0,
    MMI_EM_PROF_ROTATE_90,
    MMI_EM_PROF_ROTATE_180,
    MMI_EM_PROF_ROTATE_270,

    /* do not remove last element */
    MMI_EM_PROF_ROTATE_TOTAL
} mmi_em_prof_rotate_enum;

typedef enum
{
    MMI_EM_PROF_SIZE_SQCIF,
    MMI_EM_PROF_SIZE_QCIF,
    MMI_EM_PROF_SIZE_CIF,
    MMI_EM_PROF_SIZE_QQVGA,
    MMI_EM_PROF_SIZE_QVGA,
    MMI_EM_PROF_SIZE_VGA,
    MMI_EM_PROF_SIZE_LCD,

    /* do not remove last element */
    MMI_EM_PROF_SIZE_TOTAL
} mmi_em_prof_size_enum;

typedef enum
{
    MMI_EM_PROF_TV_LCD_SCR,
    MMI_EM_PROF_TV_FULL_SCR,

    /* do not remove last element */
    MMI_EM_PROF_TV_TOTAL
} mmi_em_prof_tv_type_enum;

typedef enum
{
    MMI_EM_PROF_PLAY_TYPE_IMAGE,
    MMI_EM_PROF_PLAY_TYPE_VIDEO,
    MMI_EM_PROF_PLAY_TYPE_AUDIO,

    /* do not remove last element */
    MMI_EM_PROF_PLAY_TYPE_TOTAL
} mmi_em_prof_auto_play_type_enum;

typedef struct
{
    U16 mode;

    /* camera */
    U16 camera_extra_layer;
    U16 camera_rotate;
    U16 camera_preview_size;
    U16 camera_tvout_style;

    /* vdoply */
    U16 vdoply_extra_layer;
    U16 vdoply_rotate;
    U16 vdoply_play_size;
    U16 vdoply_tvout_style;

    /* vdorec */
    U16 vdorec_extra_layer;
    U16 vdorec_rotate;
    U16 vdorec_preview_size;
    U16 vdorec_record_size;
    U16 vdorec_tvout_style;

    /* imgdec*/
    U16 imgdec_file_num;
    U16 imgdec_file_index;
    U32 imgdec_file_size;
    U16 imgdec_decode_time;
    PU8 imgdec_buf_ptr;
    GDI_HANDLE imgdec_layer_handle;
    FS_HANDLE imgdec_fs_handle;
    MMI_BOOL imgdec_is_horz_view_set;

    S8 filepath[FMGR_PATH_BUFFER_SIZE];
    S32 play_time;
    BOOL is_fmgr_init;
    BOOL is_vdo_file_open;
    BOOL is_vdo_recording;
    BOOL is_first_time_enter;

    GDI_HANDLE vdo_play_layer;
    GDI_HANDLE vdo_preview_layer;
    GDI_HANDLE osd_layer;
    GDI_HANDLE base_layer;
    GDI_HANDLE cam_preview_layer;
    GDI_HANDLE extra_layer_1;
    GDI_HANDLE extra_layer_2;
    PU8 extra_layer_2_buf_ptr;
    PU8 extra_layer_1_buf_ptr;

    mmi_em_prof_auto_play_type_enum play_type;

} mmi_em_prof_cntx_struct;

typedef struct
{

    /* strings for inline selection display */
    UI_string_type inline_str_1[MMI_EM_PROF_INLINE_MAX_ITEM_COUNT];
    UI_string_type inline_str_2[MMI_EM_PROF_INLINE_MAX_ITEM_COUNT];
    UI_string_type inline_str_3[MMI_EM_PROF_INLINE_MAX_ITEM_COUNT];
    UI_string_type inline_str_4[MMI_EM_PROF_INLINE_MAX_ITEM_COUNT];
    UI_string_type inline_str_5[MMI_EM_PROF_INLINE_MAX_ITEM_COUNT];
    UI_string_type inline_str_6[MMI_EM_PROF_INLINE_MAX_ITEM_COUNT];

    S32 inline_value_1;
    S32 inline_value_2;
    S32 inline_value_3;
    S32 inline_value_4;
    S32 inline_value_5;
    S32 inline_value_6;

} mmi_em_prof_inline_cntx_struct;

/*****************************************************************************
* Global Variable
*****************************************************************************/

/*****************************************************************************
* Global Function
*****************************************************************************/

/*****************************************************************************
* Local Variable
*****************************************************************************/
mmi_em_prof_cntx_struct mmi_em_prof_cntx;
mmi_em_prof_inline_cntx_struct mmi_em_prof_inline_cntx;

/*****************************************************************************
* Local Function
*****************************************************************************/
static void mmi_em_highlight_profiling(void);
static void mmi_em_entry_profiling_scr(void);

#if defined(__MMI_CAMERA__) || defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_VIDEO_PLAYER__)
static void mmi_em_profiling_highlight_multimedia(void);
static void mmi_em_profiling_highlight_auto_play(void);
static void mmi_em_profiling_entry_multimedia_scr(void);
static void mmi_em_profiling_entry_auto_play_folder_scr(void);
static void mmi_em_profiling_auto_play_folder_selected(void *path, int is_short);
static void mmi_em_profiling_entry_auto_play_scr(void);
static void mmi_em_profiling_auto_play_next_file(void);
static void mmi_em_profiling_stop_auto_play(void);
static void mmi_em_profiling_exit_auto_play_scr(void);
static void mmi_em_profiling_auto_play_audio_callback(MDI_RESULT result);
static void mmi_em_profiling_auto_play_video_callback(MDI_RESULT result);
static void mmi_em_profiling_auto_play_audio_draw_timer(void);
#endif /* defined(__MMI_CAMERA__) || defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_VIDEO_PLAYER__) */ 

#ifdef __MMI_SUBLCD__
static void mmi_em_profiling_entry_sublcd_scr(void);
static void mmi_em_profiling_exit_sublcd_scr(void);
#endif /* __MMI_SUBLCD__ */ 

#ifdef __MMI_CAMERA__
static void mmi_em_profiling_highlight_camera(void);
static void mmi_em_profiling_highlight_camera_setting(void);
static void mmi_em_profiling_highlight_camera_start(void);
static void mmi_em_profiling_entry_camera_option_scr(void);
static void mmi_em_profiling_entry_camera_setting_scr(void);
static void mmi_em_profiling_exit_camera_setting_scr(void);
static void mmi_em_profiling_camera_setting_lsk_done(void);
static void mmi_em_profiling_entry_camera_play_scr(void);
static void mmi_em_profiling_exit_camera_play_scr(void);
static void mmi_em_profiling_camera_setting_highlight_hdlr(S32 index);
#endif /* __MMI_CAMERA__ */ 

#ifdef __MMI_VIDEO_PLAYER__
static void mmi_em_profiling_highlight_vdoply(void);
static void mmi_em_profiling_highlight_vdoply_setting(void);
static void mmi_em_profiling_highlight_vdoply_start(void);
static void mmi_em_profiling_entry_vdoply_file_select_scr(void);
static void mmi_em_profiling_vdoply_file_selected(void *path, int is_short);
static void mmi_em_profiling_entry_vdoply_option_scr(void);
static void mmi_em_profiling_entry_vdoply_setting_scr(void);
static void mmi_em_profiling_exit_vdoply_setting_scr(void);
static void mmi_em_profiling_vdoply_setting_lsk_done(void);
static void mmi_em_profiling_entry_vdoply_play_scr(void);
static void mmi_em_profiling_exit_vdoply_play_scr(void);
static void mmi_em_profiling_vdoply_setting_highlight_hdlr(S32 index);
#endif /* __MMI_VIDEO_PLAYER__ */ 

#ifdef __MMI_VIDEO_RECORDER__
static void mmi_em_profiling_highlight_vdorec(void);
static void mmi_em_profiling_highlight_vdorec_setting(void);
static void mmi_em_profiling_highlight_vdorec_start(void);
static void mmi_em_profiling_entry_vdorec_option_scr(void);
static void mmi_em_profiling_entry_vdorec_setting_scr(void);
static void mmi_em_profiling_exit_vdorec_setting_scr(void);
static void mmi_em_profiling_vdorec_setting_lsk_done(void);
static void mmi_em_profiling_entry_vdorec_play_scr(void);
static void mmi_em_profiling_exit_vdorec_play_scr(void);
static void mmi_em_profiling_vdorec_setting_highlight_hdlr(S32 index);
static void mmi_em_profiling_vdorec_record_key_release(void);
static void mmi_em_profiling_vdorec_record_result_callback(MDI_RESULT result);
#endif /* __MMI_VIDEO_RECORDER__ */ 

#ifdef __MMI_IMG_DEC_PROFILING__
static void mmi_em_profiling_highlight_imgdec(void);
static void mmi_em_profiling_highlight_imgdec_folder(void);
static void mmi_em_profiling_highlight_imgdec_folder_rotate(void); 
static void mmi_em_profiling_imgdec_folder_selected(void *path, int is_short);
static void mmi_em_profiling_entry_imgdec_option_scr(void);
static void mmi_em_profiling_entry_imgdec_gendisp_scr(void);
static void mmi_em_profiling_entry_imgdec_fulldisp_scr(void);
static void mmi_em_profiling_imgdec_folder_select_scr(void);
static void mmi_em_profiling_exit_imgdec_fulldisp_scr(void);
static void mmi_em_profiling_exit_imgdec_gendisp_scr(void);
static void mmi_em_profiling_draw_style_text(PS8 str, S32 offset_x, S32 offset_y);
static void mmi_em_profiling_stop_imgdec_decoding(void);
static void mmi_em_profiling_imgdec_decode_next_file(void);
static void mmi_em_profiling_draw_rsk(PS8 rsk_str);
static void mmi_em_profiling_get_imgtype_string(U16 img_type, PS8 str);
#endif /* __MMI_IMG_DEC_PROFILING__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_em_init_profiling
 * DESCRIPTION
 *  init profiling screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_init_profiling(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_ID_EM_PROFILING, mmi_em_highlight_profiling);

    /* multimedia */
#if defined(__MMI_CAMERA__) || defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_VIDEO_PLAYER__)
    SetHiliteHandler(MENU_ID_EM_PROFILING_MULTIMEDIA, mmi_em_profiling_highlight_multimedia);
    SetHiliteHandler(MENU_ID_EM_PROFILING_AUTO_PLAY, mmi_em_profiling_highlight_auto_play);
#endif /* defined(__MMI_CAMERA__) || defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_VIDEO_PLAYER__) */ 

#ifdef __MMI_CAMERA__
    SetHiliteHandler(MENU_ID_EM_PROFILING_CAMERA, mmi_em_profiling_highlight_camera);
    SetHiliteHandler(MENU_ID_EM_PROFILING_CAMERA_START, mmi_em_profiling_highlight_camera_start);
    SetHiliteHandler(MENU_ID_EM_PROFILING_CAMERA_SETTING, mmi_em_profiling_highlight_camera_setting);
#endif /* __MMI_CAMERA__ */ 

#ifdef __MMI_VIDEO_PLAYER__
    SetHiliteHandler(MENU_ID_EM_PROFILING_VDOPLY, mmi_em_profiling_highlight_vdoply);
    SetHiliteHandler(MENU_ID_EM_PROFILING_VDOPLY_START, mmi_em_profiling_highlight_vdoply_start);
    SetHiliteHandler(MENU_ID_EM_PROFILING_VDOPLY_SETTING, mmi_em_profiling_highlight_vdoply_setting);
#endif /* __MMI_VIDEO_PLAYER__ */ 

#ifdef __MMI_VIDEO_RECORDER__
    SetHiliteHandler(MENU_ID_EM_PROFILING_VDOREC, mmi_em_profiling_highlight_vdorec);
    SetHiliteHandler(MENU_ID_EM_PROFILING_VDOREC_START, mmi_em_profiling_highlight_vdorec_start);
    SetHiliteHandler(MENU_ID_EM_PROFILING_VDOREC_SETTING, mmi_em_profiling_highlight_vdorec_setting);
#endif /* __MMI_VIDEO_RECORDER__ */ 

#ifdef __MMI_IMG_DEC_PROFILING__    
    SetHiliteHandler(MENU_ID_EM_PROFILING_IMAGE_DECODE, mmi_em_profiling_highlight_imgdec);
    SetHiliteHandler(MENU_ID_EM_PROFILING_IMAGE_DECODE_FOLDER, mmi_em_profiling_highlight_imgdec_folder);
    SetHiliteHandler(MENU_ID_EM_PROFILING_IMAGE_DECODE_FOLDER_ROTATE, mmi_em_profiling_highlight_imgdec_folder_rotate);
#endif /* __MMI_IMG_DEC_PROFILING__    */    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_highlight_profiling
 * DESCRIPTION
 *  hilight profiling menuitem
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_highlight_profiling(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_em_entry_profiling_scr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_highlight_multimedia
 * DESCRIPTION
 *  hilight profiling multimedia menuitem
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_CAMERA__) || defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_VIDEO_PLAYER__)
static void mmi_em_profiling_highlight_multimedia(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_em_profiling_entry_multimedia_scr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}
#endif /* defined(__MMI_CAMERA__) || defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_VIDEO_PLAYER__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_highlight_auto_play
 * DESCRIPTION
 *  hilight profiling multimedia auto play menuitem
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_CAMERA__) || defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_VIDEO_PLAYER__)
static void mmi_em_profiling_highlight_auto_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_em_profiling_entry_auto_play_folder_scr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}
#endif /* defined(__MMI_CAMERA__) || defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_VIDEO_PLAYER__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_highlight_camera
 * DESCRIPTION
 *  hilight profiling multimedia camera menuitem
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_CAMERA__
static void mmi_em_profiling_highlight_camera(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_em_profiling_entry_camera_option_scr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}
#endif /* __MMI_CAMERA__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_highlight_camera_start
 * DESCRIPTION
 *  hilight profiling multimedia camera start menuitem
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_CAMERA__
static void mmi_em_profiling_highlight_camera_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_em_profiling_entry_camera_play_scr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}
#endif /* __MMI_CAMERA__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_highlight_camera_setting
 * DESCRIPTION
 *  hilight profiling multimedia camera setting menuitem
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_CAMERA__
static void mmi_em_profiling_highlight_camera_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_em_profiling_entry_camera_setting_scr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}
#endif /* __MMI_CAMERA__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_highlight_vdoply
 * DESCRIPTION
 *  hilight profiling multimedia video player menuitem
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_VIDEO_PLAYER__
static void mmi_em_profiling_highlight_vdoply(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_em_profiling_entry_vdoply_file_select_scr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}
#endif /* __MMI_VIDEO_PLAYER__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_highlight_vdoply_start
 * DESCRIPTION
 *  hilight profiling multimedia video player start menuitem
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_VIDEO_PLAYER__
static void mmi_em_profiling_highlight_vdoply_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_em_profiling_entry_vdoply_play_scr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}
#endif /* __MMI_VIDEO_PLAYER__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_highlight_vdoply_setting
 * DESCRIPTION
 *  hilight profiling multimedia video player setting menuitem
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_VIDEO_PLAYER__
static void mmi_em_profiling_highlight_vdoply_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_em_profiling_entry_vdoply_setting_scr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}
#endif /* __MMI_VIDEO_PLAYER__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_highlight_vdorec
 * DESCRIPTION
 *  hilight profiling multimedia video recorder menuitem
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_VIDEO_RECORDER__
static void mmi_em_profiling_highlight_vdorec(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_em_profiling_entry_vdorec_option_scr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}
#endif /* __MMI_VIDEO_RECORDER__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_highlight_vdorec_start
 * DESCRIPTION
 *  hilight profiling multimedia video recorder start menuitem
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_VIDEO_RECORDER__
static void mmi_em_profiling_highlight_vdorec_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_em_profiling_entry_vdorec_play_scr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}
#endif /* __MMI_VIDEO_RECORDER__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_highlight_vdorec_setting
 * DESCRIPTION
 *  hilight profiling multimedia video recorder setting menuitem
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_VIDEO_RECORDER__
static void mmi_em_profiling_highlight_vdorec_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_em_profiling_entry_vdorec_setting_scr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}
#endif /* __MMI_VIDEO_RECORDER__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_entry_profiling_scr
 * DESCRIPTION
 *  enter profiling screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_entry_profiling_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 item_list[16];
    U16 item_icons[16];
    U16 num_item;
    U8 *gui_buffer;
    U8 *popup_list[16];
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EM_PROFILING, NULL, mmi_em_entry_profiling_scr, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_EM_PROFILING);
    num_item = GetNumOfChild(MENU_ID_EM_PROFILING);

    GetSequenceStringIds(MENU_ID_EM_PROFILING, item_list);
    GetSequenceImageIds(MENU_ID_EM_PROFILING, item_icons);
    SetParentHandler(MENU_ID_EM_PROFILING);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (i = 0; i < num_item; i++)
    {
        item_icons[i] = (U16) (IMG_GLOBAL_L1 + i);
    }

    for (i = 0; i < num_item; i++)
    {
        popup_list[i] = NULL;
    }

    ConstructHintsList(MENU_ID_EM_PROFILING, popup_list);

    ShowCategory52Screen(
        STR_ID_EM_PROFILING,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_item,
        item_list,
        item_icons,
        (U8 **) popup_list,
        0,
        0,
        gui_buffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_entry_multimedia_scr
 * DESCRIPTION
 *  enter profiling multimedia screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_CAMERA__) || defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_VIDEO_PLAYER__)
static void mmi_em_profiling_entry_multimedia_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 item_list[16];
    U16 item_icons[16];
    U16 num_item;
    U8 *gui_buffer;
    U8 *popup_list[16];
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EM_PROFILING_MULTIMEDIA, NULL, mmi_em_profiling_entry_multimedia_scr, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_EM_PROFILING_MULTIMEDIA);
    num_item = GetNumOfChild(MENU_ID_EM_PROFILING_MULTIMEDIA);

    GetSequenceStringIds(MENU_ID_EM_PROFILING_MULTIMEDIA, item_list);
    GetSequenceImageIds(MENU_ID_EM_PROFILING_MULTIMEDIA, item_icons);
    SetParentHandler(MENU_ID_EM_PROFILING_MULTIMEDIA);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (i = 0; i < num_item; i++)
    {
        item_icons[i] = (U16) (IMG_GLOBAL_L1 + i);
    }

    for (i = 0; i < num_item; i++)
    {
        popup_list[i] = NULL;
    }

    ConstructHintsList(MENU_ID_EM_PROFILING_MULTIMEDIA, popup_list);

    ShowCategory52Screen(
        STR_ID_EM_PROFILING_MULTIMEDIA,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_item,
        item_list,
        item_icons,
        (U8 **) popup_list,
        0,
        0,
        gui_buffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}
#endif /* defined(__MMI_CAMERA__) || defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_VIDEO_PLAYER__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_entry_auto_play_folder_scr
 * DESCRIPTION
 *  enter profiling multimedia auto play screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_CAMERA__) || defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_VIDEO_PLAYER__)
static void mmi_em_profiling_entry_auto_play_folder_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //      EntryNewScreen(SCR_ID_EM_PROFILING_AUTO_PLAY_FOLDER,
    //                                              NULL,
    //                                              mmi_em_profiling_entry_auto_play_folder_scr,
    //                                              NULL);

    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);

    mmi_fmgr_select_path_and_enter(
        APP_ENGINEERMODE,
        FMGR_SELECT_FOLDER,
        filter,
        (S8*) L"root",
        mmi_em_profiling_auto_play_folder_selected);

}
#endif /* defined(__MMI_CAMERA__) || defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_VIDEO_PLAYER__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_auto_play_folder_selected
 * DESCRIPTION
 *  folder selected
 * PARAMETERS
 *  path            [IN]        Selected folder path
 *  is_short        [IN]        Is short filename
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_CAMERA__) || defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_VIDEO_PLAYER__)
static void mmi_em_profiling_auto_play_folder_selected(void *path, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (path == NULL)
    {
        DeleteUptoScrID(SCR_ID_EM_PROFILING_AUTO_PLAY_FOLDER);
        GoBackHistory();
        return;
    }

    mmi_ucs2cpy((PS8) mmi_em_prof_cntx.filepath, (PS8) path);

    /* enter auto play screen */
    mmi_em_profiling_entry_auto_play_scr();

}
#endif /* defined(__MMI_CAMERA__) || defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_VIDEO_PLAYER__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_entry_auto_play_scr
 * DESCRIPTION
 *  enter profiling multimedia auto play screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_CAMERA__) || defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_VIDEO_PLAYER__)
static void mmi_em_profiling_entry_auto_play_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(
        SCR_ID_EM_PROFILING_AUTO_PLAY,
        mmi_em_profiling_exit_auto_play_scr,
        mmi_em_profiling_entry_auto_play_scr,
        NULL);

    /* this will force title status to redraw */
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

    /* enable multi-layer */
    gdi_layer_multi_layer_enable();

    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

    mmi_em_prof_cntx.is_fmgr_init = FALSE;

    /*
     * start a time to start play file, we can direct call
     * mmi_em_profiling_auto_play_next_file() since fmgr will
     * deinit after exit function
     */
    gui_start_timer(100, mmi_em_profiling_auto_play_next_file);

    SetKeyHandler(mmi_em_profiling_stop_auto_play, KEY_RSK, KEY_EVENT_UP);

}
#endif /* defined(__MMI_CAMERA__) || defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_VIDEO_PLAYER__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_auto_play_next_file
 * DESCRIPTION
 *  enter profiling multimedia auto play screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_CAMERA__) || defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_VIDEO_PLAYER__)
static void mmi_em_profiling_auto_play_next_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT file_info;
    S32 image_width;
    S32 image_height;
    S32 image_offset_x;
    S32 image_offset_y;
    S32 resized_offset_x;
    S32 resized_offset_y;
    S32 resized_width;
    S32 resized_height;
    S8 filepath[FMGR_PATH_BUFFER_SIZE];
    U16 file_count;
    FMGR_FILTER filter;
    MDI_RESULT mdi_ret;
    GDI_RESULT gdi_ret;

#ifdef __MMI_VIDEO_PLAYER__
    mdi_video_info_struct video_info;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_em_prof_cntx.is_fmgr_init)
    {
        mmi_em_prof_cntx.is_fmgr_init = TRUE;

        /* file handling */
        fmgr_reset_app_select();

        FMGR_FILTER_INIT(&filter);
        FMGR_FILTER_SET_IMAGE(&filter);
        FMGR_FILTER_SET_AUDIO(&filter);
        FMGR_FILTER_SET_VIDEO(&filter);

        /* init */
        mmi_fmgr_kernel_init(mmi_em_prof_cntx.filepath, filter, &file_count);

        if (file_count == 0)
        {
            DisplayPopup((PU8) GetString(STR_GLOBAL_EMPTY), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);
            DeleteUptoScrID(SCR_ID_EM_PROFILING_MULTIMEDIA);
            return;
        }

    }

    mmi_fmgr_kernel_get_file_info((S32) (mmi_fmgr_kernel_get_cur_idx()), &file_info);

    if (FMGR_FILTER_IS_SET_IMAGE(&file_info.file_type))
    {
      /************************/
        /* Image Type           */
      /************************/

        mmi_em_prof_cntx.play_type = MMI_EM_PROF_PLAY_TYPE_IMAGE;

        mmi_ucs2cpy(filepath, mmi_em_prof_cntx.filepath);
        mmi_ucs2cat(filepath, file_info.file_name);
        gdi_image_get_dimension_file(filepath, &image_width, &image_height);

        gdi_layer_reset_clip();
        gdi_layer_clear(GDI_COLOR_BLACK);

        if ((UI_device_width >= image_width) && (UI_device_height >= image_height))
        {
            /* align preview window at the center of screen */
            image_offset_x = (UI_device_width - image_width) >> 1;
            image_offset_y = (UI_device_height - image_height) >> 1;

            gdi_ret = gdi_image_draw_file(image_offset_x, image_offset_y, (PS8) filepath);
        }
        else
        {
            /* resize */
            gdi_image_util_fit_bbox(
                UI_device_width,
                UI_device_height,
                image_width,
                image_height,
                &resized_offset_x,
                &resized_offset_y,
                &resized_width,
                &resized_height);

            gdi_ret = gdi_image_draw_resized_file(
                        resized_offset_x,
                        resized_offset_y,
                        resized_width,
                        resized_height,
                        filepath);
        }

        /* draw "Image" */
        gui_move_text_cursor(5, 5);
        gui_set_text_color(gui_color(0, 0, 0));
        gui_set_text_border_color(gui_color(255, 255, 255));
        gui_print_bordered_text((UI_string_type) L"[ Image ]");

        /* draw file name */
        gui_move_text_cursor(5, 25);
        gui_print_bordered_text((UI_string_type) file_info.file_name);

        if (gdi_ret != GDI_SUCCEED)
        {
            gui_move_text_cursor(5, 45);
            gui_print_bordered_text((UI_string_type) L"!!! ERROR !!!");
        }
        else
        {
            gui_move_text_cursor(5, 45);
            gui_print_bordered_text((UI_string_type) L"!!! DECODE DONE !!!");
        }

        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

        /* show 1 sec */
        gui_start_timer(1000, mmi_em_profiling_auto_play_next_file);

    }
    else if (FMGR_FILTER_IS_SET_AUDIO(&file_info.file_type))
    {
      /************************/
        /* Audio Type           */
      /************************/

        mmi_em_prof_cntx.play_type = MMI_EM_PROF_PLAY_TYPE_AUDIO;

        mmi_ucs2cpy(filepath, mmi_em_prof_cntx.filepath);
        mmi_ucs2cat(filepath, file_info.file_name);

        gdi_layer_reset_clip();
        gdi_layer_clear(GDI_COLOR_BLACK);

        /* draw "Audio" */
        gui_move_text_cursor(5, 5);
        gui_set_text_color(gui_color(0, 0, 0));
        gui_set_text_border_color(gui_color(255, 255, 255));
        gui_print_bordered_text((UI_string_type) L"[ Audio ]");

        /* draw file name */
        gui_move_text_cursor(5, 25);
        gui_print_bordered_text((UI_string_type) file_info.file_name);

        mdi_ret = mdi_audio_play_file(
                    filepath,
                    DEVICE_AUDIO_PLAY_ONCE,
                    NULL,
                    mmi_em_profiling_auto_play_audio_callback);

        mmi_em_prof_cntx.play_time = 0;

        if (mdi_ret != MDI_AUDIO_SUCCESS)
        {
            gui_move_text_cursor(5, 45);
            gui_print_bordered_text((UI_string_type) L"!!! ERROR !!!");

            /* not success, play next */
            gui_start_timer(1000, mmi_em_profiling_auto_play_next_file);
        }
        else
        {
            gui_move_text_cursor(5, 45);
            gui_print_bordered_text((UI_string_type) L"!!! PLAYING !!!");

            /* start draw timer - timer is not accurate */
            mmi_em_profiling_auto_play_audio_draw_timer();
        }

        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

    }
#ifdef __MMI_VIDEO_PLAYER__
    else if (FMGR_FILTER_IS_SET_VIDEO(&file_info.file_type))
    {
      /************************/
        /* Video Type           */
      /************************/

        mmi_em_prof_cntx.play_type = MMI_EM_PROF_PLAY_TYPE_VIDEO;
        mmi_em_prof_cntx.vdo_play_layer = GDI_LAYER_EMPTY_HANDLE;

        mmi_ucs2cpy(filepath, mmi_em_prof_cntx.filepath);
        mmi_ucs2cat(filepath, file_info.file_name);

        mmi_em_prof_cntx.is_vdo_file_open = FALSE;
        mdi_ret = mdi_video_ply_open_clip_file(filepath, &video_info);

        if (mdi_ret >= 0)
        {
            mmi_em_prof_cntx.is_vdo_file_open = TRUE;

            gdi_image_util_fit_bbox(
                UI_device_width,
                UI_device_height,
                video_info.width,
                video_info.height,
                &resized_offset_x,
                &resized_offset_y,
                &resized_width,
                &resized_height);

            gdi_layer_create(
                resized_offset_x,
                resized_offset_y,
                resized_width,
                resized_height,
                &mmi_em_prof_cntx.vdo_play_layer);

            mdi_video_ply_seek_and_get_frame(0, mmi_em_prof_cntx.vdo_play_layer);

            gdi_layer_get_base_handle(&mmi_em_prof_cntx.osd_layer);
            gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
            gdi_layer_clear(GDI_COLOR_BLACK);
            gdi_draw_solid_rect(
                resized_offset_x,
                resized_offset_y,
                resized_offset_x + resized_width - 1,
                resized_offset_y + resized_height - 1,
                GDI_COLOR_TRANSPARENT);

            /* draw "Video" */
            gui_move_text_cursor(5, 5);
            gui_set_text_color(gui_color(0, 0, 0));
            gui_set_text_border_color(gui_color(255, 255, 255));
            gui_print_bordered_text((UI_string_type) L"[ Video ]");

            /* draw file name */
            gui_move_text_cursor(5, 25);
            gui_print_bordered_text((UI_string_type) file_info.file_name);

            gdi_layer_set_blt_layer(mmi_em_prof_cntx.vdo_play_layer, mmi_em_prof_cntx.osd_layer, 0, 0);

            gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

            mdi_ret = mdi_video_ply_play(
                        mmi_em_prof_cntx.vdo_play_layer,
                        GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1,
                        GDI_LAYER_ENABLE_LAYER_0,
                        1,                      /* repeat */
                        TRUE,                   /* visual update */
                        TRUE,                   /* play_audio */
                        MDI_DEVICE_SPEAKER2,    /* speaker & earphone */
                        MDI_VIDEO_LCD_ROTATE_0, /* rotate */
                        100,                    /* 1x play speed */
                        mmi_em_profiling_auto_play_video_callback);    /* hook callback */

            /* play failed - close file */
            if (mdi_ret < 0)
            {
                if (mmi_em_prof_cntx.is_vdo_file_open)
                {
                    mdi_video_ply_close_clip_file();
                    mmi_em_prof_cntx.is_vdo_file_open = FALSE;
                }

                /* free layer */
                gdi_layer_free(mmi_em_prof_cntx.vdo_play_layer);
                mmi_em_prof_cntx.vdo_play_layer = GDI_LAYER_EMPTY_HANDLE;

                /* restore base layer */
                gdi_layer_set_blt_layer(mmi_em_prof_cntx.osd_layer, 0, 0, 0);
            }

        }

        if (mdi_ret >= 0)
        {
            /* no error */
            gui_move_text_cursor(5, 45);
            gui_print_bordered_text((UI_string_type) L"!!! PLAYING !!!");
            gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
        }
        else
        {
            /* has error */
            gui_move_text_cursor(5, 45);
            gui_print_bordered_text((UI_string_type) L"!!! ERROR !!!");
            gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

            /* not success, play next */
            gui_start_timer(1000, mmi_em_profiling_auto_play_next_file);
        }
    }
#endif /* __MMI_VIDEO_PLAYER__ */ 
    else
    {
        /* shall not enter here */
        MMI_ASSERT(0);
    }

    mmi_fmgr_kernel_move_selection_down();

}
#endif /* defined(__MMI_CAMERA__) || defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_VIDEO_PLAYER__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_stop_auto_play
 * DESCRIPTION
 *  stop auto play and exit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_CAMERA__) || defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_VIDEO_PLAYER__)
static void mmi_em_profiling_stop_auto_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteUptoScrID(SCR_ID_EM_PROFILING_MULTIMEDIA);
    GoBackHistory();
}
#endif /* defined(__MMI_CAMERA__) || defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_VIDEO_PLAYER__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_exit_auto_play_scr
 * DESCRIPTION
 *  exit profiling multimedia auto play screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_CAMERA__) || defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_VIDEO_PLAYER__)
static void mmi_em_profiling_exit_auto_play_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_em_profiling_auto_play_next_file);

    switch (mmi_em_prof_cntx.play_type)
    {
        case MMI_EM_PROF_PLAY_TYPE_IMAGE:
            break;

        case MMI_EM_PROF_PLAY_TYPE_AUDIO:
            mdi_audio_stop_file();
            gui_cancel_timer(mmi_em_profiling_auto_play_audio_draw_timer);
            break;

        case MMI_EM_PROF_PLAY_TYPE_VIDEO:
    #ifdef __MMI_VIDEO_PLAYER__
            /* close file */
            if (mmi_em_prof_cntx.is_vdo_file_open)
            {
                mdi_video_ply_stop();
                mdi_video_ply_close_clip_file();
                mmi_em_prof_cntx.is_vdo_file_open = FALSE;
            }

            /* free layer */
            if (mmi_em_prof_cntx.vdo_play_layer != GDI_LAYER_EMPTY_HANDLE)
            {
                gdi_layer_free(mmi_em_prof_cntx.vdo_play_layer);
                mmi_em_prof_cntx.vdo_play_layer = GDI_LAYER_EMPTY_HANDLE;
                gdi_layer_set_blt_layer(mmi_em_prof_cntx.osd_layer, 0, 0, 0);
            }
    #endif /* __MMI_VIDEO_PLAYER__ */ 
            break;
    }

    /* resume alignment timer */
    UI_enable_alignment_timers();

    /* let MMI can sleep */
    TurnOffBacklight();

    /* enable multi-layer */
    gdi_layer_multi_layer_disable();

    /* resume background audio */
    mdi_audio_resume_background_play();

    /* re-enable keypad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);

    /* this will force title status to redraw */
    entry_full_screen();

}
#endif /* defined(__MMI_CAMERA__) || defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_VIDEO_PLAYER__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_auto_play_audio_draw_timer
 * DESCRIPTION
 *  draw timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_CAMERA__) || defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_VIDEO_PLAYER__)
static void mmi_em_profiling_auto_play_audio_draw_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 time_str[30];
    S8 display_str[30];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(time_str, "%02d:%02d", mmi_em_prof_cntx.play_time / 60, mmi_em_prof_cntx.play_time % 60);
    mmi_asc_to_ucs2(display_str, time_str);

    gdi_draw_solid_rect(0, 65, UI_device_width - 1, 85, GDI_COLOR_BLACK);

    gui_move_text_cursor(5, 65);
    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));
    gui_print_bordered_text((UI_string_type) display_str);

    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

    mmi_em_prof_cntx.play_time++;

    gui_start_timer(1000, mmi_em_profiling_auto_play_audio_draw_timer);

}
#endif /* defined(__MMI_CAMERA__) || defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_VIDEO_PLAYER__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_auto_play_audio_callback
 * DESCRIPTION
 *  callback function when play audio
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_CAMERA__) || defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_VIDEO_PLAYER__)
static void mmi_em_profiling_auto_play_audio_callback(MDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_em_profiling_auto_play_audio_draw_timer);

    if (result == MDI_AUDIO_TERMINATED)
    {
        /* this is due to exit function call audio stop */
        return;
    }

    gdi_draw_solid_rect(0, 45, UI_device_width - 1, 65, GDI_COLOR_BLACK);

    gui_move_text_cursor(5, 45);
    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));

    if (result == MDI_AUDIO_END_OF_FILE)
    {
        gui_print_bordered_text((UI_string_type) L"!!! PLAY FINISH !!!");
    }
    else
    {
        gui_print_bordered_text((UI_string_type) L"!!! ERROR !!!");
    }

    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

    gui_start_timer(1000, mmi_em_profiling_auto_play_next_file);

}
#endif /* defined(__MMI_CAMERA__) || defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_VIDEO_PLAYER__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_auto_play_video_callback
 * DESCRIPTION
 *  callback function when play video
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_VIDEO_PLAYER__)
static void mmi_em_profiling_auto_play_video_callback(MDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U64 time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_draw_solid_rect(0, 45, UI_device_width - 1, 65, GDI_COLOR_TRANSPARENT);

    gui_move_text_cursor(5, 45);
    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_text_border_color(gui_color(255, 255, 255));

    if (result >= 0)
    {
        mdi_video_ply_get_cur_play_time(&time);
        mdi_video_ply_seek_and_get_frame(time, mmi_em_prof_cntx.vdo_play_layer);

        gui_print_bordered_text((UI_string_type) L"!!! PLAY FINISH !!!");
    }
    else
    {
        gui_print_bordered_text((UI_string_type) L"!!! ERROR !!!");
    }

    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

    /* close file */
    if (mmi_em_prof_cntx.is_vdo_file_open)
    {
        mdi_video_ply_close_clip_file();
        mmi_em_prof_cntx.is_vdo_file_open = FALSE;
    }

    /* free layer */
    gdi_layer_free(mmi_em_prof_cntx.vdo_play_layer);
    mmi_em_prof_cntx.vdo_play_layer = GDI_LAYER_EMPTY_HANDLE;

    /* set draw base layer only */
    gdi_layer_set_blt_layer(mmi_em_prof_cntx.osd_layer, 0, 0, 0);

    gui_start_timer(1000, mmi_em_profiling_auto_play_next_file);
}
#endif /* defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_VIDEO_PLAYER__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_entry_sublcd_scr
 * DESCRIPTION
 *  entry sublcd screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD__
static void mmi_em_profiling_entry_sublcd_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();
    ShowCategory331Screen();
    SetSubLCDExitHandler(mmi_em_profiling_exit_sublcd_scr);
}
#endif /* __MMI_SUBLCD__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_exit_sublcd_scr
 * DESCRIPTION
 *  exit sublcd screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD__
static void mmi_em_profiling_exit_sublcd_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SubLCDHistoryNode sub_history;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sub_history.entryFuncPtr = mmi_em_profiling_entry_sublcd_scr;
    AddSubLCDHistory(&sub_history);

}
#endif /* __MMI_SUBLCD__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_entry_camera_option_scr
 * DESCRIPTION
 *  enter profiling multimedia camera option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_CAMERA__)
static void mmi_em_profiling_entry_camera_option_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 item_list[16];
    U16 item_icons[16];
    U16 num_item;
    U8 *gui_buffer;
    U8 *popup_list[16];
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EM_PROFILING_CAMERA_OPTION, NULL, mmi_em_profiling_entry_camera_option_scr, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_EM_PROFILING_CAMERA_OPTION);
    num_item = GetNumOfChild(MENU_ID_EM_PROFILING_CAMERA);

    GetSequenceStringIds(MENU_ID_EM_PROFILING_CAMERA, item_list);
    GetSequenceImageIds(MENU_ID_EM_PROFILING_CAMERA, item_icons);
    SetParentHandler(MENU_ID_EM_PROFILING_CAMERA);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (i = 0; i < num_item; i++)
    {
        item_icons[i] = (U16) (IMG_GLOBAL_L1 + i);
    }

    for (i = 0; i < num_item; i++)
    {
        popup_list[i] = NULL;
    }

    ConstructHintsList(MENU_ID_EM_PROFILING_CAMERA, popup_list);

    ShowCategory52Screen(
        STR_ID_EM_PROFILING_CAMERA,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_item,
        item_list,
        item_icons,
        (U8 **) popup_list,
        0,
        0,
        gui_buffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}
#endif /* defined(__MMI_CAMERA__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_entry_camera_setting_scr
 * DESCRIPTION
 *  enter profiling multimedia camera setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_CAMERA__)
static void mmi_em_profiling_entry_camera_setting_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    U8 *input_buffer;
    U16 item_offset;
    U16 input_buffer_size;

    MMI_ID_TYPE item_icons[] = 
    {
        IMG_GLOBAL_L1,
        0,
        IMG_GLOBAL_L2,
        0,
        IMG_GLOBAL_L3,
        0,
        IMG_GLOBAL_L4,
        0,
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Camera Settings:
     * (1) Extra Layer
     * (2) Rotate
     * (3) Preview Size
     * (4) TV-Out Style
     */

    EntryNewScreen(SCR_ID_EM_PROFILING_CAMERA_SETTING, mmi_em_profiling_exit_camera_setting_scr, NULL, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_EM_PROFILING_CAMERA_SETTING);
    input_buffer = GetCurrNInputBuffer(SCR_ID_EM_PROFILING_CAMERA_SETTING, &input_buffer_size);

    /* clear inline item */
    memset((void*)wgui_inline_items, 0, sizeof(InlineItem) * 4 * 2);   /* 4 items, each has two line */
    item_offset = 0;

    /* start of Category 57 */
    InitializeCategory57Screen();

    /* (1) Extra Layer (0, 1, 2) */
    mmi_em_prof_inline_cntx.inline_str_1[0] = (UI_string_type) GetString((U16) (STR_GLOBAL_0));
    mmi_em_prof_inline_cntx.inline_str_1[1] = (UI_string_type) GetString((U16) (STR_GLOBAL_1));
    mmi_em_prof_inline_cntx.inline_str_1[2] = (UI_string_type) GetString((U16) (STR_GLOBAL_2));

    mmi_em_prof_inline_cntx.inline_value_1 = mmi_em_prof_cntx.camera_extra_layer;

    SetInlineItemCaption(&wgui_inline_items[item_offset], (PU8) GetString((U16) (STR_ID_EM_PROFILING_EXTRA_LAYER)));
    item_offset++;

    SetInlineItemActivation(&wgui_inline_items[item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemSelect(
        &wgui_inline_items[item_offset],
        3,
        (U8 **) mmi_em_prof_inline_cntx.inline_str_1,
        &mmi_em_prof_inline_cntx.inline_value_1);
    item_offset++;

    /* (2) Layer Rotate  (0, 90, 180, 270) */
    mmi_em_prof_inline_cntx.inline_str_2[0] = (UI_string_type) GetString((U16) (STR_ID_EM_PROFILING_ROTATE_0));
    mmi_em_prof_inline_cntx.inline_str_2[1] = (UI_string_type) GetString((U16) (STR_ID_EM_PROFILING_ROTATE_90));
    mmi_em_prof_inline_cntx.inline_str_2[2] = (UI_string_type) GetString((U16) (STR_ID_EM_PROFILING_ROTATE_180));
    mmi_em_prof_inline_cntx.inline_str_2[3] = (UI_string_type) GetString((U16) (STR_ID_EM_PROFILING_ROTATE_270));

    mmi_em_prof_inline_cntx.inline_value_2 = mmi_em_prof_cntx.camera_rotate;

    SetInlineItemCaption(&wgui_inline_items[item_offset], (PU8) GetString((U16) (STR_ID_EM_PROFILING_ROTATE)));
    item_offset++;

    SetInlineItemActivation(&wgui_inline_items[item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemSelect(
        &wgui_inline_items[item_offset],
        4,
        (U8 **) mmi_em_prof_inline_cntx.inline_str_2,
        &mmi_em_prof_inline_cntx.inline_value_2);
    item_offset++;

    /* (3) Preview Size (SQCIF, QCIF, CIF, QQVGA, QVGA, VGA, LCD) */
    mmi_em_prof_inline_cntx.inline_str_3[0] = (UI_string_type) GetString((U16) (STR_ID_EM_PROFILING_SIZE_SQCIF));
    mmi_em_prof_inline_cntx.inline_str_3[1] = (UI_string_type) GetString((U16) (STR_ID_EM_PROFILING_SIZE_QCIF));
    mmi_em_prof_inline_cntx.inline_str_3[2] = (UI_string_type) GetString((U16) (STR_ID_EM_PROFILING_SIZE_CIF));
    mmi_em_prof_inline_cntx.inline_str_3[3] = (UI_string_type) GetString((U16) (STR_ID_EM_PROFILING_SIZE_QQVGA));
    mmi_em_prof_inline_cntx.inline_str_3[4] = (UI_string_type) GetString((U16) (STR_ID_EM_PROFILING_SIZE_QVGA));
    mmi_em_prof_inline_cntx.inline_str_3[5] = (UI_string_type) GetString((U16) (STR_ID_EM_PROFILING_SIZE_VGA));
    mmi_em_prof_inline_cntx.inline_str_3[6] = (UI_string_type) GetString((U16) (STR_ID_EM_PROFILING_SIZE_LCD));

    mmi_em_prof_inline_cntx.inline_value_3 = mmi_em_prof_cntx.camera_preview_size;

    SetInlineItemCaption(&wgui_inline_items[item_offset], (PU8) GetString((U16) (STR_ID_EM_PROFILING_PREVIEW_SIZE)));
    item_offset++;

    SetInlineItemActivation(&wgui_inline_items[item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemSelect(
        &wgui_inline_items[item_offset],
        7,
        (U8 **) mmi_em_prof_inline_cntx.inline_str_3,
        &mmi_em_prof_inline_cntx.inline_value_3);
    item_offset++;

    /* (4) TV-Out Styel (Full Screen, LCD Screen) */
    mmi_em_prof_inline_cntx.inline_str_4[0] = (UI_string_type) GetString((U16) (STR_ID_EM_PROFILING_TV_LCD_SCREEN));
    mmi_em_prof_inline_cntx.inline_str_4[1] = (UI_string_type) GetString((U16) (STR_ID_EM_PROFILING_TV_FULL_SCREEN));

    mmi_em_prof_inline_cntx.inline_value_4 = mmi_em_prof_cntx.camera_tvout_style;

    SetInlineItemCaption(&wgui_inline_items[item_offset], (PU8) GetString((U16) (STR_ID_EM_PROFILING_TV_OUT_MODE)));
    item_offset++;

    SetInlineItemActivation(&wgui_inline_items[item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemSelect(
        &wgui_inline_items[item_offset],
        2,
        (U8 **) mmi_em_prof_inline_cntx.inline_str_4,
        &mmi_em_prof_inline_cntx.inline_value_4);
    item_offset++;

    RegisterHighlightHandler(mmi_em_profiling_camera_setting_highlight_hdlr);

    /* show category */
    ShowCategory57Screen(
        STR_ID_EM_PROFILING_CAMERA,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        item_offset,
        item_icons,
        wgui_inline_items,
        0,
        gui_buffer);

    /* set key hdlr */
    SetCategory57LeftSoftkeyFunction(mmi_em_profiling_camera_setting_lsk_done);
    DisableCategory57ScreenDone();
    SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);

}
#endif /* defined(__MMI_CAMERA__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_exit_camera_setting_scr
 * DESCRIPTION
 *  exit profiling multimedia video recorder setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_CAMERA__)
static void mmi_em_profiling_exit_camera_setting_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 input_buffer_size;
    history h;
    S16 n_history = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h.scrnID = SCR_ID_EM_PROFILING_CAMERA_SETTING;
    CloseCategory57Screen();
    h.entryFuncPtr = mmi_em_profiling_entry_camera_setting_scr;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & n_history);
    GetCategory57History(h.guiBuffer);
    input_buffer_size = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, input_buffer_size);

}
#endif /* defined(__MMI_CAMERA__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_camera_setting_highlight_hdlr
 * DESCRIPTION
 *  highlight handler
 * PARAMETERS
 *  index       [IN]        Index
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_CAMERA__)
static void mmi_em_profiling_camera_setting_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetCategory57LeftSoftkeyFunction(mmi_em_profiling_camera_setting_lsk_done);
}
#endif /* defined(__MMI_CAMERA__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_camera_setting_lsk_done
 * DESCRIPTION
 *  lsk done handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_CAMERA__)
static void mmi_em_profiling_camera_setting_lsk_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_em_prof_cntx.camera_extra_layer = mmi_em_prof_inline_cntx.inline_value_1;
    mmi_em_prof_cntx.camera_rotate = mmi_em_prof_inline_cntx.inline_value_2;
    mmi_em_prof_cntx.camera_preview_size = mmi_em_prof_inline_cntx.inline_value_3;
    mmi_em_prof_cntx.camera_tvout_style = mmi_em_prof_inline_cntx.inline_value_4;

    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);
    DeleteNHistory(1);
}
#endif /* defined(__MMI_CAMERA__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_entry_camera_play_scr
 * DESCRIPTION
 *  enter profiling multimedia camera screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_CAMERA__)
static void mmi_em_profiling_entry_camera_play_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = 0;
    S32 height = 0;
    S32 shift = 0;
    PU8 buf_ptr = NULL;
    S32 preview_width = 0;
    S32 preview_height = 0;
    S32 resized_width = 0;
    S32 resized_height = 0;
    S32 resized_offset_x = 0;
    S32 resized_offset_y = 0;
    S32 lcd_width = 0;
    S32 lcd_height = 0;
    U32 blt_layer = 0;
    U16 rotate = 0;

    mdi_camera_setting_struct camera_setting_data;
    mdi_camera_preview_struct camera_preview_data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* entry new screen */
    EntryNewScreen(
        SCR_ID_EM_PROFILING_CAMERA_PLAY,
        mmi_em_profiling_exit_camera_play_scr,
        mmi_em_profiling_entry_camera_play_scr,
        NULL);

    /* entry full screen app */
    entry_full_screen();

    gdi_layer_reset_clip();

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

    /* enable multi-layer */
    gdi_layer_multi_layer_enable();

#ifdef __MMI_SUBLCD__
    ForceSubLCDScreen(mmi_em_profiling_entry_sublcd_scr);
#endif 

    gdi_layer_get_base_handle(&mmi_em_prof_cntx.base_layer);
    gdi_layer_clear(GDI_COLOR_BLACK);

    gdi_layer_set_background(GDI_COLOR_BLACK);

    switch (mmi_em_prof_cntx.camera_rotate)
    {
        case MMI_EM_PROF_ROTATE_0:
            lcd_width = UI_device_width;
            lcd_height = UI_device_height;
            rotate = MDI_CAMERA_PREVIEW_ROTATE_0;
            break;

        case MMI_EM_PROF_ROTATE_90:
            lcd_width = UI_device_height;
            lcd_height = UI_device_width;
            rotate = MDI_CAMERA_PREVIEW_ROTATE_90;
            break;

        case MMI_EM_PROF_ROTATE_180:
            lcd_width = UI_device_width;
            lcd_height = UI_device_height;
            rotate = MDI_CAMERA_PREVIEW_ROTATE_180;
            break;

        case MMI_EM_PROF_ROTATE_270:
            lcd_width = UI_device_height;
            lcd_height = UI_device_width;
            rotate = MDI_CAMERA_PREVIEW_ROTATE_270;
            break;

    }

    switch (mmi_em_prof_cntx.camera_preview_size)
    {
        case MMI_EM_PROF_SIZE_SQCIF:
            preview_width = 128;
            preview_height = 96;
            break;

        case MMI_EM_PROF_SIZE_QCIF:
            preview_width = 176;
            preview_height = 144;
            break;

        case MMI_EM_PROF_SIZE_CIF:
            preview_width = 352;
            preview_height = 288;
            break;

        case MMI_EM_PROF_SIZE_QQVGA:
            preview_width = 160;
            preview_height = 120;
            break;

        case MMI_EM_PROF_SIZE_QVGA:
            preview_width = 320;
            preview_height = 240;
            break;

        case MMI_EM_PROF_SIZE_VGA:
            preview_width = 640;
            preview_height = 480;
            break;

        case MMI_EM_PROF_SIZE_LCD:
            preview_width = lcd_width;
            preview_height = lcd_height;
            break;

    }

    /* rotate lcd */
    gdi_lcd_set_rotate((U8)rotate);

    /* check if size can fit in LCD size */
    if (preview_width > lcd_width || preview_height > lcd_height)
    {
        gdi_image_util_fit_bbox(
            lcd_width,
            lcd_height,
            preview_width,
            preview_height,
            &resized_offset_x,
            &resized_offset_y,
            &resized_width,
            &resized_height);

        preview_width = resized_width;
        preview_height = resized_height;
    }
    else
    {
        resized_width = preview_width;
        resized_height = preview_height;
        resized_offset_x = ((lcd_width - preview_width) >> 1);
        resized_offset_y = ((lcd_height - preview_height) >> 1);
    }

    /* create preview layer */
    gdi_layer_get_buffer_ptr(&buf_ptr);

    gdi_layer_create_using_outside_memory(
        resized_offset_x,
        resized_offset_y,
        resized_width,
        resized_height,
        &mmi_em_prof_cntx.cam_preview_layer,
        (PU8) buf_ptr,
        (S32) MMI_EM_PROF_LAYER_BUF_SIZE);

    /* background color shall set to bottom layer */
    gdi_layer_push_and_set_active(mmi_em_prof_cntx.cam_preview_layer);
    gdi_layer_set_background(GDI_COLOR_BLACK);

    gdi_layer_pop_and_restore_active();

    gdi_layer_set_blt_layer(mmi_em_prof_cntx.cam_preview_layer, 0, 0, 0);
    blt_layer = GDI_LAYER_ENABLE_LAYER_0;

    /* allocate extra layer */
    if (mmi_em_prof_cntx.camera_extra_layer >= 1)
    {
        /* GREEN */
        mmi_em_prof_cntx.extra_layer_1_buf_ptr = (PU8) mmi_frm_scrmem_alloc(MMI_EM_PROF_LAYER_BUF_SIZE);
        ASSERT(mmi_em_prof_cntx.extra_layer_1_buf_ptr != NULL);

        gdi_layer_create_using_outside_memory(
            0,
            0,
            lcd_width,
            lcd_height,
            &mmi_em_prof_cntx.extra_layer_1,
            (PU8) mmi_em_prof_cntx.extra_layer_1_buf_ptr,
            (S32) MMI_EM_PROF_LAYER_BUF_SIZE);

        gdi_layer_push_and_set_active(mmi_em_prof_cntx.extra_layer_1);
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);

        shift = 10;
        width = 100;
        height = 30;

        gdi_draw_rect(shift, shift, lcd_width - 1 - shift, lcd_height - 1 - shift, GDI_COLOR_GREEN);
        gdi_draw_rect(shift - 1, shift - 1, lcd_width - 1 - shift - 1, lcd_height - 1 - shift - 1, GDI_COLOR_GREEN);
        gdi_draw_solid_rect(
            shift,
            lcd_height - 1 - shift - height,
            shift + width,
            lcd_height - 1 - shift,
            GDI_COLOR_GREEN);

        gui_move_text_cursor(shift + 3, lcd_height - 1 - shift - height + 3);
        gui_set_text_color(gui_color(0, 0, 0));
        gui_set_text_border_color(gui_color(255, 255, 255));
        gui_print_bordered_text((UI_string_type) L"LAYER 1");

        gdi_layer_pop_and_restore_active();

        gdi_layer_set_blt_layer(mmi_em_prof_cntx.cam_preview_layer, mmi_em_prof_cntx.extra_layer_1, 0, 0);

        blt_layer = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1;
    }

    if (mmi_em_prof_cntx.camera_extra_layer >= 2)
    {
        /* RED */
        mmi_em_prof_cntx.extra_layer_2_buf_ptr = (PU8) mmi_frm_scrmem_alloc(MMI_EM_PROF_LAYER_BUF_SIZE);
        ASSERT(mmi_em_prof_cntx.extra_layer_2_buf_ptr != NULL);

        gdi_layer_create_using_outside_memory(
            0,
            0,
            lcd_width,
            lcd_height,
            &mmi_em_prof_cntx.extra_layer_2,
            (PU8) mmi_em_prof_cntx.extra_layer_2_buf_ptr,
            (S32) MMI_EM_PROF_LAYER_BUF_SIZE);

        gdi_layer_push_and_set_active(mmi_em_prof_cntx.extra_layer_2);
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);

        shift = 2;
        width = 100;
        height = 30;

        gdi_draw_rect(shift, shift, lcd_width - 1 - shift, lcd_height - 1 - shift, GDI_COLOR_RED);
        gdi_draw_rect(shift - 1, shift - 1, lcd_width - 1 - shift - 1, lcd_height - 1 - shift - 1, GDI_COLOR_RED);
        gdi_draw_solid_rect(shift, shift, shift + width, shift + height, GDI_COLOR_RED);

        gui_move_text_cursor(shift + 3, shift + 3);
        gui_set_text_color(gui_color(0, 0, 0));
        gui_set_text_border_color(gui_color(255, 255, 255));
        gui_print_bordered_text((UI_string_type) L"LAYER 2");

        gdi_layer_pop_and_restore_active();

        gdi_layer_set_blt_layer(
            mmi_em_prof_cntx.cam_preview_layer,
            mmi_em_prof_cntx.extra_layer_1,
            mmi_em_prof_cntx.extra_layer_2,
            0);

        blt_layer = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2;
    }

    gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);

    SetKeyHandler(GoBackHistory, KEY_RSK, KEY_EVENT_UP);

    /* power on and init hardware module */
    mdi_camera_power_on();

    mdi_camera_load_default_setting(&camera_setting_data);

    /* start preview */
    camera_setting_data.zoom = 10;
    camera_setting_data.wb = MDI_CAMERA_WB_AUTO;
    camera_setting_data.manual_wb = FALSE;

    camera_setting_data.ev = MDI_CAMERA_EV_0;
    camera_setting_data.banding = MDI_CAMERA_BANDING_50HZ;

    camera_setting_data.night = FALSE;
    camera_setting_data.flash = MDI_CAMERA_FLASH_OFF;
    camera_setting_data.ae_meter = MDI_CAMERA_AE_METER_AUTO;
    camera_setting_data.iso = MDI_CAMERA_ISO_AUTO;

    camera_setting_data.dsc_mode = MDI_CAMERA_DSC_MODE_AUTO;

    camera_setting_data.effect = MDI_CAMERA_EFFECT_NOMRAL;
    camera_setting_data.brightness = 128;
    camera_setting_data.saturation = 128;
    camera_setting_data.contrast = 128;
    camera_setting_data.hue = 0;

    camera_setting_data.preview_width = preview_width;
    camera_setting_data.preview_height = preview_height;

    /* capture parameters */
    camera_setting_data.image_qty = MDI_CAMERA_JPG_QTY_HIGH;
    camera_setting_data.image_width = preview_width;
    camera_setting_data.image_height = preview_height;

    camera_setting_data.lcm = MDI_CAMERA_PREVIEW_LCM_MAINLCD;
    camera_setting_data.preview_rotate = MDI_CAMERA_LCM_ROTATE_0;
    camera_setting_data.lcm_rotate = rotate;

    camera_setting_data.af_metering_mode = 0;
    camera_setting_data.af_mode = 0;
    camera_setting_data.dsc_mode = 0;
    camera_setting_data.shutter_pri = 0;
    camera_setting_data.aperture_pri = 0;

    camera_setting_data.overlay_frame_mode = FALSE;

    camera_setting_data.af_zone0_x = 0;
    camera_setting_data.af_zone0_y = 0;
    camera_setting_data.af_zone1_x = 0;
    camera_setting_data.af_zone1_y = 0;
    camera_setting_data.af_zone2_x = 0;
    camera_setting_data.af_zone2_y = 0;
    camera_setting_data.af_zone3_x = 0;
    camera_setting_data.af_zone3_y = 0;
    camera_setting_data.af_zone4_x = 0;
    camera_setting_data.af_zone4_y = 0;

#ifdef __MMI_TVOUT__
    if (mdi_tvout_is_enable())
    {
        if (mmi_em_prof_cntx.camera_tvout_style == MMI_EM_PROF_TV_FULL_SCR)
        {
            /* fullscreen */

            /* if is fullscreen, we shall set to owner to video here, to avoid GDI's update */
            mdi_tvout_set_owner(MDI_TV_OWNER_CAMERA);

            /* full screen preview update */
            mdi_tvout_set_mode(MDI_TV_MODE_MULTIMEDIA_FULL_SCR, 0, 0);
        }
    }
#endif /* __MMI_TVOUT__ */ 

    camera_preview_data.preview_layer_handle = mmi_em_prof_cntx.cam_preview_layer;
    camera_preview_data.preview_wnd_offset_x = 0;
    camera_preview_data.preview_wnd_offset_y = 0;
    camera_preview_data.preview_wnd_width = preview_width;
    camera_preview_data.preview_wnd_height = preview_height;
    camera_preview_data.blt_layer_flag = blt_layer;
    camera_preview_data.preview_layer_flag = GDI_LAYER_ENABLE_LAYER_0;
    camera_preview_data.is_lcd_update = TRUE;
    camera_preview_data.src_key_color = GDI_COLOR_TRANSPARENT;
    camera_preview_data.is_tvout = TRUE;
    camera_preview_data.xenon_flash_status_callback = NULL;

    mdi_camera_preview_start(
        &camera_preview_data,
        &camera_setting_data);

}
#endif /* defined(__MMI_CAMERA__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_exit_camera_play_scr
 * DESCRIPTION
 *  enter profiling multimedia camera screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_CAMERA__)
static void mmi_em_profiling_exit_camera_play_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* free resource */
    mdi_camera_preview_stop();
    mdi_camera_power_off();

    gdi_layer_free(mmi_em_prof_cntx.cam_preview_layer);

    if (mmi_em_prof_cntx.camera_extra_layer >= 1)
    {
        gdi_layer_free(mmi_em_prof_cntx.extra_layer_1);

        mmi_frm_scrmem_free((void*)mmi_em_prof_cntx.extra_layer_1_buf_ptr);
        mmi_em_prof_cntx.extra_layer_1_buf_ptr = NULL;
    }

    if (mmi_em_prof_cntx.camera_extra_layer >= 2)
    {
        gdi_layer_free(mmi_em_prof_cntx.extra_layer_2);

        mmi_frm_scrmem_free((void*)mmi_em_prof_cntx.extra_layer_2_buf_ptr);
        mmi_em_prof_cntx.extra_layer_2_buf_ptr = NULL;
    }

    gdi_layer_set_blt_layer(mmi_em_prof_cntx.base_layer, 0, 0, 0);

    /* rotate lcd */
    gdi_lcd_set_rotate(GDI_LAYER_ROTATE_0);

#ifdef __MMI_TVOUT__
    /* tvout */
    if (mmi_em_prof_cntx.vdorec_tvout_style == MMI_EM_PROF_TV_FULL_SCR)
    {
        /* set owner back to GDI */
        mdi_tvout_set_owner(MDI_TV_OWNER_GDI);

        mdi_tvout_set_mode(MDI_TV_MODE_LCD_SCR, 0, 0);
    }
#endif /* __MMI_TVOUT__ */ 

    /* resume alignment timer */
    UI_enable_alignment_timers();

    /* let MMI can sleep */
    TurnOffBacklight();

    /* enable multi-layer */
    gdi_layer_multi_layer_disable();

    /* resume background audio */
    mdi_audio_resume_background_play();

    /* re-enable keypad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);

    /* this will force title status to redraw */
    entry_full_screen();

}
#endif /* defined(__MMI_CAMERA__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_entry_vdoply_file_select_scr
 * DESCRIPTION
 *  enter profiling multimedia video player file selection screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_VIDEO_PLAYER__)
static void mmi_em_profiling_entry_vdoply_file_select_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET_VIDEO(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);

    mmi_fmgr_select_path_and_enter(
        APP_ENGINEERMODE,
        FMGR_SELECT_FILE,
        filter,
        (S8*) L"root",
        mmi_em_profiling_vdoply_file_selected);

}
#endif /* defined(__MMI_VIDEO_PLAYER__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_vdoply_file_selected
 * DESCRIPTION
 *  file selected
 * PARAMETERS
 *  path            [IN]        File path
 *  is_short        [IN]        Is short filename
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_VIDEO_PLAYER__)
static void mmi_em_profiling_vdoply_file_selected(void *path, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (path == NULL)
    {
        /* delete filemgr history */
        DeleteUptoScrID(SCR_ID_EM_PROFILING_MULTIMEDIA);
        GoBackHistory();
        return;
    }

    mmi_ucs2cpy((PS8) mmi_em_prof_cntx.filepath, (PS8) path);

    /* enter video play setting */
    mmi_em_profiling_entry_vdoply_option_scr();

}
#endif /* defined(__MMI_VIDEO_PLAYER__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_entry_vdoply_option_scr
 * DESCRIPTION
 *  enter profiling multimedia video player option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_VIDEO_PLAYER__)
static void mmi_em_profiling_entry_vdoply_option_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 item_list[16];
    U16 item_icons[16];
    U16 num_item;
    U8 *gui_buffer;
    U8 *popup_list[16];
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EM_PROFILING_VDOPLY_OPTION, NULL, mmi_em_profiling_entry_vdoply_option_scr, NULL);

    /* remove filemgr history */
    DeleteUptoScrID(SCR_ID_EM_PROFILING_MULTIMEDIA);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_EM_PROFILING_VDOPLY_OPTION);
    num_item = GetNumOfChild(MENU_ID_EM_PROFILING_VDOPLY);

    GetSequenceStringIds(MENU_ID_EM_PROFILING_VDOPLY, item_list);
    GetSequenceImageIds(MENU_ID_EM_PROFILING_VDOPLY, item_icons);
    SetParentHandler(MENU_ID_EM_PROFILING_VDOPLY);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (i = 0; i < num_item; i++)
    {
        item_icons[i] = (U16) (IMG_GLOBAL_L1 + i);
    }

    for (i = 0; i < num_item; i++)
    {
        popup_list[i] = NULL;
    }

    ConstructHintsList(MENU_ID_EM_PROFILING_VDOREC, popup_list);

    ShowCategory52Screen(
        STR_ID_EM_PROFILING_VDOPLY,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_item,
        item_list,
        item_icons,
        (U8 **) popup_list,
        0,
        0,
        gui_buffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}
#endif /* defined(__MMI_VIDEO_PLAYER__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_entry_vdoply_setting_scr
 * DESCRIPTION
 *  enter profiling multimedia video player setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_VIDEO_PLAYER__)
static void mmi_em_profiling_entry_vdoply_setting_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    U8 *input_buffer;
    U16 item_offset;
    U16 input_buffer_size;

    MMI_ID_TYPE item_icons[] = 
    {
        IMG_GLOBAL_L1,
        0,
        IMG_GLOBAL_L2,
        0,
        IMG_GLOBAL_L3,
        0,
        IMG_GLOBAL_L4,
        0,
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Video Recorder Settings:
     * (1) Extra Layer
     * (2) Rotate
     * (3) Play Size
     * (4) TV-Out Style
     */

    EntryNewScreen(SCR_ID_EM_PROFILING_VDOPLY_SETTING, mmi_em_profiling_exit_vdoply_setting_scr, NULL, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_EM_PROFILING_VDOPLY_SETTING);
    input_buffer = GetCurrNInputBuffer(SCR_ID_EM_PROFILING_VDOPLY_SETTING, &input_buffer_size);

    /* clear inline item */
    memset((void*)wgui_inline_items, 0, sizeof(InlineItem) * 4 * 2);   /* 4 items, each has two line */
    item_offset = 0;

    /* start of Category 57 */
    InitializeCategory57Screen();

    /* (1) Extra Layer (0, 1, 2) */
    mmi_em_prof_inline_cntx.inline_str_1[0] = (UI_string_type) GetString((U16) (STR_GLOBAL_0));
    mmi_em_prof_inline_cntx.inline_str_1[1] = (UI_string_type) GetString((U16) (STR_GLOBAL_1));
    mmi_em_prof_inline_cntx.inline_str_1[2] = (UI_string_type) GetString((U16) (STR_GLOBAL_2));

    mmi_em_prof_inline_cntx.inline_value_1 = mmi_em_prof_cntx.vdoply_extra_layer;

    SetInlineItemCaption(&wgui_inline_items[item_offset], (PU8) GetString((U16) (STR_ID_EM_PROFILING_EXTRA_LAYER)));
    item_offset++;

    SetInlineItemActivation(&wgui_inline_items[item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemSelect(
        &wgui_inline_items[item_offset],
        3,
        (U8 **) mmi_em_prof_inline_cntx.inline_str_1,
        &mmi_em_prof_inline_cntx.inline_value_1);
    item_offset++;

    /* (2) Rotate  (0, 90, 180, 270) */
    mmi_em_prof_inline_cntx.inline_str_2[0] = (UI_string_type) GetString((U16) (STR_ID_EM_PROFILING_ROTATE_0));
    mmi_em_prof_inline_cntx.inline_str_2[1] = (UI_string_type) GetString((U16) (STR_ID_EM_PROFILING_ROTATE_90));
    mmi_em_prof_inline_cntx.inline_str_2[2] = (UI_string_type) GetString((U16) (STR_ID_EM_PROFILING_ROTATE_180));
    mmi_em_prof_inline_cntx.inline_str_2[3] = (UI_string_type) GetString((U16) (STR_ID_EM_PROFILING_ROTATE_270));

    mmi_em_prof_inline_cntx.inline_value_2 = mmi_em_prof_cntx.vdoply_rotate;

    SetInlineItemCaption(&wgui_inline_items[item_offset], (PU8) GetString((U16) (STR_ID_EM_PROFILING_ROTATE)));
    item_offset++;

    SetInlineItemActivation(&wgui_inline_items[item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemSelect(
        &wgui_inline_items[item_offset],
        4,
        (U8 **) mmi_em_prof_inline_cntx.inline_str_2,
        &mmi_em_prof_inline_cntx.inline_value_2);
    item_offset++;

    /* (3) play Size (SQCIF, QCIF, CIF, QQVGA, QVGA, VGA, LCD) */
    mmi_em_prof_inline_cntx.inline_str_3[0] = (UI_string_type) GetString((U16) (STR_ID_EM_PROFILING_SIZE_SQCIF));
    mmi_em_prof_inline_cntx.inline_str_3[1] = (UI_string_type) GetString((U16) (STR_ID_EM_PROFILING_SIZE_QCIF));
    mmi_em_prof_inline_cntx.inline_str_3[2] = (UI_string_type) GetString((U16) (STR_ID_EM_PROFILING_SIZE_CIF));
    mmi_em_prof_inline_cntx.inline_str_3[3] = (UI_string_type) GetString((U16) (STR_ID_EM_PROFILING_SIZE_QQVGA));
    mmi_em_prof_inline_cntx.inline_str_3[4] = (UI_string_type) GetString((U16) (STR_ID_EM_PROFILING_SIZE_QVGA));
    mmi_em_prof_inline_cntx.inline_str_3[5] = (UI_string_type) GetString((U16) (STR_ID_EM_PROFILING_SIZE_VGA));
    mmi_em_prof_inline_cntx.inline_str_3[6] = (UI_string_type) GetString((U16) (STR_ID_EM_PROFILING_SIZE_LCD));

    mmi_em_prof_inline_cntx.inline_value_3 = mmi_em_prof_cntx.vdoply_play_size;

    SetInlineItemCaption(&wgui_inline_items[item_offset], (PU8) GetString((U16) (STR_ID_EM_PROFILING_PLAY_SIZE)));
    item_offset++;

    SetInlineItemActivation(&wgui_inline_items[item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemSelect(
        &wgui_inline_items[item_offset],
        7,
        (U8 **) mmi_em_prof_inline_cntx.inline_str_3,
        &mmi_em_prof_inline_cntx.inline_value_3);
    item_offset++;

    /* (4) TV-Out Styel (Full Screen, LCD Screen) */
    mmi_em_prof_inline_cntx.inline_str_4[0] = (UI_string_type) GetString((U16) (STR_ID_EM_PROFILING_TV_LCD_SCREEN));
    mmi_em_prof_inline_cntx.inline_str_4[1] = (UI_string_type) GetString((U16) (STR_ID_EM_PROFILING_TV_FULL_SCREEN));

    mmi_em_prof_inline_cntx.inline_value_4 = mmi_em_prof_cntx.vdoply_tvout_style;

    SetInlineItemCaption(&wgui_inline_items[item_offset], (PU8) GetString((U16) (STR_ID_EM_PROFILING_TV_OUT_MODE)));
    item_offset++;

    SetInlineItemActivation(&wgui_inline_items[item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemSelect(
        &wgui_inline_items[item_offset],
        2,
        (U8 **) mmi_em_prof_inline_cntx.inline_str_4,
        &mmi_em_prof_inline_cntx.inline_value_4);
    item_offset++;

    RegisterHighlightHandler(mmi_em_profiling_vdoply_setting_highlight_hdlr);

    /* show category */
    ShowCategory57Screen(
        STR_ID_EM_PROFILING_VDOPLY,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        item_offset,
        item_icons,
        wgui_inline_items,
        0,
        gui_buffer);

    /* set key hdlr */
    SetCategory57LeftSoftkeyFunction(mmi_em_profiling_vdoply_setting_lsk_done);
    DisableCategory57ScreenDone();
    SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);

}
#endif /* defined(__MMI_VIDEO_PLAYER__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_exit_vdoply_setting_scr
 * DESCRIPTION
 *  exit profiling multimedia video recorder setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_VIDEO_PLAYER__)
static void mmi_em_profiling_exit_vdoply_setting_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 input_buffer_size;
    history h;
    S16 n_history = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h.scrnID = SCR_ID_EM_PROFILING_VDOPLY_SETTING;
    CloseCategory57Screen();
    h.entryFuncPtr = mmi_em_profiling_entry_vdoply_setting_scr;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & n_history);
    GetCategory57History(h.guiBuffer);
    input_buffer_size = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, input_buffer_size);

}
#endif /* defined(__MMI_VIDEO_PLAYER__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_vdoply_setting_highlight_hdlr
 * DESCRIPTION
 *  highlight handler
 * PARAMETERS
 *  index       [IN]        Index
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_VIDEO_PLAYER__)
static void mmi_em_profiling_vdoply_setting_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetCategory57LeftSoftkeyFunction(mmi_em_profiling_vdoply_setting_lsk_done);
}
#endif /* defined(__MMI_VIDEO_PLAYER__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_vdoply_setting_lsk_done
 * DESCRIPTION
 *  lsk done handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_VIDEO_PLAYER__)
static void mmi_em_profiling_vdoply_setting_lsk_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_em_prof_cntx.vdoply_extra_layer = mmi_em_prof_inline_cntx.inline_value_1;
    mmi_em_prof_cntx.vdoply_rotate = mmi_em_prof_inline_cntx.inline_value_2;
    mmi_em_prof_cntx.vdoply_play_size = mmi_em_prof_inline_cntx.inline_value_3;
    mmi_em_prof_cntx.vdoply_tvout_style = mmi_em_prof_inline_cntx.inline_value_4;

    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);
    DeleteNHistory(1);
}
#endif /* defined(__MMI_VIDEO_PLAYER__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_entry_vdoply_play_scr
 * DESCRIPTION
 *  enter profiling multimedia video player screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_VIDEO_PLAYER__)
static void mmi_em_profiling_entry_vdoply_play_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width;
    S32 height;
    S32 shift;
    PU8 buf_ptr;
    S32 play_width = 0;
    S32 play_height = 0;
    S32 resized_width = 0;
    S32 resized_height = 0;
    S32 resized_offset_x = 0;
    S32 resized_offset_y = 0;
    S32 lcd_width = 0;
    S32 lcd_height = 0;
    U32 blt_layer = 0;
    U16 rotate = 0;
    mdi_video_info_struct video_info;
    MDI_RESULT mdi_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* entry new screen */
    EntryNewScreen(
        SCR_ID_EM_PROFILING_VDOPLY_PLAY,
        mmi_em_profiling_exit_vdoply_play_scr,
        mmi_em_profiling_entry_vdoply_play_scr,
        NULL);

    /* entry full screen app */
    entry_full_screen();

    gdi_layer_reset_clip();

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

    /* enable multi-layer */
    gdi_layer_multi_layer_enable();

#ifdef __MMI_SUBLCD__
    ForceSubLCDScreen(mmi_em_profiling_entry_sublcd_scr);
#endif 

    gdi_layer_get_base_handle(&mmi_em_prof_cntx.base_layer);
    gdi_layer_clear(GDI_COLOR_BLACK);

    gdi_layer_set_background(GDI_COLOR_BLACK);

    switch (mmi_em_prof_cntx.vdoply_rotate)
    {
        case MMI_EM_PROF_ROTATE_0:
            lcd_width = UI_device_width;
            lcd_height = UI_device_height;
            rotate = MDI_VIDEO_LCD_ROTATE_0;
            break;

        case MMI_EM_PROF_ROTATE_90:
            lcd_width = UI_device_height;
            lcd_height = UI_device_width;
            rotate = MDI_VIDEO_LCD_ROTATE_90;
            break;

        case MMI_EM_PROF_ROTATE_180:
            lcd_width = UI_device_width;
            lcd_height = UI_device_height;
            rotate = MDI_VIDEO_LCD_ROTATE_180;
            break;

        case MMI_EM_PROF_ROTATE_270:
            lcd_width = UI_device_height;
            lcd_height = UI_device_width;
            rotate = MDI_VIDEO_LCD_ROTATE_270;
            break;

    }

    switch (mmi_em_prof_cntx.vdoply_play_size)
    {
        case MMI_EM_PROF_SIZE_SQCIF:
            play_width = 128;
            play_height = 96;
            break;

        case MMI_EM_PROF_SIZE_QCIF:
            play_width = 176;
            play_height = 144;
            break;

        case MMI_EM_PROF_SIZE_CIF:
            play_width = 352;
            play_height = 288;
            break;

        case MMI_EM_PROF_SIZE_QQVGA:
            play_width = 160;
            play_height = 120;
            break;

        case MMI_EM_PROF_SIZE_QVGA:
            play_width = 320;
            play_height = 240;
            break;

        case MMI_EM_PROF_SIZE_VGA:
            play_width = 640;
            play_height = 480;
            break;

        case MMI_EM_PROF_SIZE_LCD:
            play_width = lcd_width;
            play_height = lcd_height;
            break;

    }

    /* rotate lcd */
    gdi_lcd_set_rotate((U8)rotate);

    /* check if size can fit in LCD size */
    if (play_width > lcd_width || play_height > lcd_height)
    {
        gdi_image_util_fit_bbox(
            lcd_width,
            lcd_height,
            play_width,
            play_height,
            &resized_offset_x,
            &resized_offset_y,
            &resized_width,
            &resized_height);

        play_width = resized_width;
        play_height = resized_height;
    }
    else
    {
        resized_width = play_width;
        resized_height = play_height;
        resized_offset_x = ((lcd_width - play_width) >> 1);
        resized_offset_y = ((lcd_height - play_height) >> 1);
    }

    mdi_ret = mdi_video_ply_open_clip_file(mmi_em_prof_cntx.filepath, &video_info);

    /* create preview layer */
    gdi_layer_get_buffer_ptr(&buf_ptr);

    gdi_layer_create_using_outside_memory(
        resized_offset_x,
        resized_offset_y,
        resized_width,
        resized_height,
        &mmi_em_prof_cntx.vdo_play_layer,
        (PU8) buf_ptr,
        (S32) MMI_EM_PROF_LAYER_BUF_SIZE);

    /* background color shall set to bottom layer */
    gdi_layer_push_and_set_active(mmi_em_prof_cntx.vdo_play_layer);
    gdi_layer_set_background(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();

    gdi_layer_set_blt_layer(mmi_em_prof_cntx.vdo_play_layer, 0, 0, 0);
    blt_layer = GDI_LAYER_ENABLE_LAYER_0;

    /* allocate extra layer */
    if (mmi_em_prof_cntx.vdoply_extra_layer >= 1)
    {
        /* GREEN */
        mmi_em_prof_cntx.extra_layer_1_buf_ptr = (PU8) mmi_frm_scrmem_alloc(MMI_EM_PROF_LAYER_BUF_SIZE);
        ASSERT(mmi_em_prof_cntx.extra_layer_1_buf_ptr != NULL);

        gdi_layer_create_using_outside_memory(
            0,
            0,
            lcd_width,
            lcd_height,
            &mmi_em_prof_cntx.extra_layer_1,
            (PU8) mmi_em_prof_cntx.extra_layer_1_buf_ptr,
            (S32) MMI_EM_PROF_LAYER_BUF_SIZE);

        gdi_layer_push_and_set_active(mmi_em_prof_cntx.extra_layer_1);
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);

        shift = 10;
        width = 100;
        height = 30;

        gdi_draw_rect(shift, shift, lcd_width - 1 - shift, lcd_height - 1 - shift, GDI_COLOR_GREEN);
        gdi_draw_rect(shift - 1, shift - 1, lcd_width - 1 - shift - 1, lcd_height - 1 - shift - 1, GDI_COLOR_GREEN);
        gdi_draw_solid_rect(
            shift,
            lcd_height - 1 - shift - height,
            shift + width,
            lcd_height - 1 - shift,
            GDI_COLOR_GREEN);

        gui_move_text_cursor(shift + 3, lcd_height - 1 - shift - height + 3);
        gui_set_text_color(gui_color(0, 0, 0));
        gui_set_text_border_color(gui_color(255, 255, 255));
        gui_print_bordered_text((UI_string_type) L"LAYER 1");

        gdi_layer_pop_and_restore_active();

        gdi_layer_set_blt_layer(mmi_em_prof_cntx.vdo_play_layer, mmi_em_prof_cntx.extra_layer_1, 0, 0);

        blt_layer = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1;
    }

    if (mmi_em_prof_cntx.vdoply_extra_layer >= 2)
    {
        /* RED */
        mmi_em_prof_cntx.extra_layer_2_buf_ptr = (PU8) mmi_frm_scrmem_alloc(MMI_EM_PROF_LAYER_BUF_SIZE);
        ASSERT(mmi_em_prof_cntx.extra_layer_2_buf_ptr != NULL);

        gdi_layer_create_using_outside_memory(
            0,
            0,
            lcd_width,
            lcd_height,
            &mmi_em_prof_cntx.extra_layer_2,
            (PU8) mmi_em_prof_cntx.extra_layer_2_buf_ptr,
            (S32) MMI_EM_PROF_LAYER_BUF_SIZE);

        gdi_layer_push_and_set_active(mmi_em_prof_cntx.extra_layer_2);

        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);

        shift = 2;
        width = 100;
        height = 30;

        gdi_draw_rect(shift, shift, lcd_width - 1 - shift, lcd_height - 1 - shift, GDI_COLOR_RED);
        gdi_draw_rect(shift - 1, shift - 1, lcd_width - 1 - shift - 1, lcd_height - 1 - shift - 1, GDI_COLOR_RED);
        gdi_draw_solid_rect(shift, shift, shift + width, shift + height, GDI_COLOR_RED);

        gui_move_text_cursor(shift + 3, shift + 3);
        gui_set_text_color(gui_color(0, 0, 0));
        gui_set_text_border_color(gui_color(255, 255, 255));
        gui_print_bordered_text((UI_string_type) L"LAYER 2");

        gdi_layer_pop_and_restore_active();

        gdi_layer_set_blt_layer(
            mmi_em_prof_cntx.vdo_play_layer,
            mmi_em_prof_cntx.extra_layer_1,
            mmi_em_prof_cntx.extra_layer_2,
            0);

        blt_layer = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2;
    }

    gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);

    SetKeyHandler(GoBackHistory, KEY_RSK, KEY_EVENT_UP);

#ifdef __MMI_TVOUT__
    if (mdi_tvout_is_enable())
    {
        /* tvout */
        if (mmi_em_prof_cntx.vdoply_tvout_style == MMI_EM_PROF_TV_FULL_SCR)
        {
            /* fullscreen */

            /* if is fullscreen, we shall set to owner to video here, to avoid GDI's update */
            mdi_tvout_set_owner(MDI_TV_OWNER_VIDEO);

            /* full screen playback */
            mdi_tvout_set_mode(MDI_TV_MODE_MULTIMEDIA_FULL_SCR, 0, 0);
        }
    }
#endif /* __MMI_TVOUT__ */ 

    mdi_video_ply_seek(0);

    mdi_ret = mdi_video_ply_play(
                mmi_em_prof_cntx.vdo_play_layer,
                blt_layer,
                GDI_LAYER_ENABLE_LAYER_0,
                1,                      /* repeat */
                TRUE,                   /* visual update */
                TRUE,                   /* play_audio */
                MDI_DEVICE_SPEAKER2,    /* speaker & earphone */
                rotate,                 /* rotate */
                100,                    /* 1x play speed */
                NULL);                  /* hook callback */

}
#endif /* defined(__MMI_VIDEO_PLAYER__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_exit_vdoply_play_scr
 * DESCRIPTION
 *  enter profiling multimedia camera screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_VIDEO_PLAYER__)
static void mmi_em_profiling_exit_vdoply_play_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* stop play and close file */
    mdi_video_ply_stop();
    mdi_video_ply_close_clip_file();

    /* free resource */
    gdi_layer_free(mmi_em_prof_cntx.vdo_play_layer);

    if (mmi_em_prof_cntx.vdoply_extra_layer >= 1)
    {
        gdi_layer_free(mmi_em_prof_cntx.extra_layer_1);

        mmi_frm_scrmem_free((void*)mmi_em_prof_cntx.extra_layer_1_buf_ptr);
        mmi_em_prof_cntx.extra_layer_1_buf_ptr = NULL;
    }

    if (mmi_em_prof_cntx.vdoply_extra_layer >= 2)
    {
        gdi_layer_free(mmi_em_prof_cntx.extra_layer_2);

        mmi_frm_scrmem_free((void*)mmi_em_prof_cntx.extra_layer_2_buf_ptr);
        mmi_em_prof_cntx.extra_layer_2_buf_ptr = NULL;
    }

    gdi_layer_set_blt_layer(mmi_em_prof_cntx.base_layer, 0, 0, 0);

    /* rotate lcd */
    gdi_lcd_set_rotate(GDI_LAYER_ROTATE_0);

#ifdef __MMI_TVOUT__
    /* tvout */
    if (mmi_em_prof_cntx.vdoply_tvout_style == MMI_EM_PROF_TV_FULL_SCR)
    {
        /* set owner back to GDI */
        mdi_tvout_set_owner(MDI_TV_OWNER_GDI);

        mdi_tvout_set_mode(MDI_TV_MODE_LCD_SCR, 0, 0);
    }
#endif /* __MMI_TVOUT__ */ 

    /* resume alignment timer */
    UI_enable_alignment_timers();

    /* let MMI can sleep */
    TurnOffBacklight();

    /* enable multi-layer */
    gdi_layer_multi_layer_disable();

    /* resume background audio */
    mdi_audio_resume_background_play();

    /* re-enable keypad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);

    /* this will force title status to redraw */
    entry_full_screen();

}
#endif /* defined(__MMI_VIDEO_PLAYER__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_entry_vdorec_play_scr
 * DESCRIPTION
 *  enter profiling multimedia video player screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_VIDEO_RECORDER__)
static void mmi_em_profiling_entry_vdorec_play_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width;
    S32 height;
    S32 shift;
    PU8 buf_ptr;
    S32 preview_width = 0;
    S32 preview_height = 0;
    S32 resized_width = 0;
    S32 resized_height = 0;
    S32 resized_offset_x = 0;
    S32 resized_offset_y = 0;
    S32 lcd_width = 0;
    S32 lcd_height = 0;
    U32 blt_layer = 0;
    U16 rotate = 0;

    mdi_video_setting_struct video_preview_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* entry new screen */
    EntryNewScreen(
        SCR_ID_EM_PROFILING_VDOREC_PLAY,
        mmi_em_profiling_exit_vdorec_play_scr,
        mmi_em_profiling_entry_vdorec_play_scr,
        NULL);

    /* entry full screen app */
    entry_full_screen();

    gdi_layer_reset_clip();

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

    /* enable multi-layer */
    gdi_layer_multi_layer_enable();

#ifdef __MMI_SUBLCD__
    ForceSubLCDScreen(mmi_em_profiling_entry_sublcd_scr);
#endif 

    gdi_layer_get_base_handle(&mmi_em_prof_cntx.base_layer);
    gdi_layer_clear(GDI_COLOR_BLACK);

    gdi_layer_set_background(GDI_COLOR_BLACK);

    switch (mmi_em_prof_cntx.vdorec_rotate)
    {
        case MMI_EM_PROF_ROTATE_0:
            lcd_width = UI_device_width;
            lcd_height = UI_device_height;
            rotate = MDI_VIDEO_LCD_ROTATE_0;
            break;

        case MMI_EM_PROF_ROTATE_90:
            lcd_width = UI_device_height;
            lcd_height = UI_device_width;
            rotate = MDI_VIDEO_LCD_ROTATE_90;
            break;

        case MMI_EM_PROF_ROTATE_180:
            lcd_width = UI_device_width;
            lcd_height = UI_device_height;
            rotate = MDI_VIDEO_LCD_ROTATE_180;
            break;

        case MMI_EM_PROF_ROTATE_270:
            lcd_width = UI_device_height;
            lcd_height = UI_device_width;
            rotate = MDI_VIDEO_LCD_ROTATE_270;
            break;

    }

    switch (mmi_em_prof_cntx.vdorec_preview_size)
    {
        case MMI_EM_PROF_SIZE_SQCIF:
            preview_width = 128;
            preview_height = 96;
            break;

        case MMI_EM_PROF_SIZE_QCIF:
            preview_width = 176;
            preview_height = 144;
            break;

        case MMI_EM_PROF_SIZE_CIF:
            preview_width = 352;
            preview_height = 288;
            break;

        case MMI_EM_PROF_SIZE_QQVGA:
            preview_width = 160;
            preview_height = 120;
            break;

        case MMI_EM_PROF_SIZE_QVGA:
            preview_width = 320;
            preview_height = 240;
            break;

        case MMI_EM_PROF_SIZE_VGA:
            preview_width = 640;
            preview_height = 480;
            break;

        case MMI_EM_PROF_SIZE_LCD:
            preview_width = lcd_width;
            preview_height = lcd_height;
            break;

    }

    /* rotate lcd */
    gdi_lcd_set_rotate((U8)rotate);

    /* check if size can fit in LCD size */
    if (preview_width > lcd_width || preview_height > lcd_height)
    {
        gdi_image_util_fit_bbox(
            lcd_width,
            lcd_height,
            preview_width,
            preview_height,
            &resized_offset_x,
            &resized_offset_y,
            &resized_width,
            &resized_height);

        preview_width = resized_width;
        preview_height = resized_height;
    }
    else
    {
        resized_width = preview_width;
        resized_height = preview_height;
        resized_offset_x = ((lcd_width - preview_width) >> 1);
        resized_offset_y = ((lcd_height - preview_height) >> 1);
    }

    /* create preview layer */
    gdi_layer_get_buffer_ptr(&buf_ptr);

    gdi_layer_create_using_outside_memory(
        resized_offset_x,
        resized_offset_y,
        resized_width,
        resized_height,
        &mmi_em_prof_cntx.vdo_preview_layer,
        (PU8) buf_ptr,
        (S32) MMI_EM_PROF_LAYER_BUF_SIZE);

    /* background color shall set to bottom layer */
    gdi_layer_push_and_set_active(mmi_em_prof_cntx.vdo_preview_layer);
    gdi_layer_set_background(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();

    gdi_layer_set_blt_layer(mmi_em_prof_cntx.vdo_preview_layer, 0, 0, 0);
    blt_layer = GDI_LAYER_ENABLE_LAYER_0;

    /* allocate extra layer */
    if (mmi_em_prof_cntx.vdorec_extra_layer >= 1)
    {
        /* GREEN */
        mmi_em_prof_cntx.extra_layer_1_buf_ptr = (PU8) mmi_frm_scrmem_alloc(MMI_EM_PROF_LAYER_BUF_SIZE);
        ASSERT(mmi_em_prof_cntx.extra_layer_1_buf_ptr != NULL);

        gdi_layer_create_using_outside_memory(
            0,
            0,
            lcd_width,
            lcd_height,
            &mmi_em_prof_cntx.extra_layer_1,
            (PU8) mmi_em_prof_cntx.extra_layer_1_buf_ptr,
            (S32) MMI_EM_PROF_LAYER_BUF_SIZE);

        gdi_layer_push_and_set_active(mmi_em_prof_cntx.extra_layer_1);

        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);

        shift = 10;
        width = 100;
        height = 30;

        gdi_draw_rect(shift, shift, lcd_width - 1 - shift, lcd_height - 1 - shift, GDI_COLOR_GREEN);
        gdi_draw_rect(shift - 1, shift - 1, lcd_width - 1 - shift - 1, lcd_height - 1 - shift - 1, GDI_COLOR_GREEN);
        gdi_draw_solid_rect(
            shift,
            lcd_height - 1 - shift - height,
            shift + width,
            lcd_height - 1 - shift,
            GDI_COLOR_GREEN);

        gui_move_text_cursor(shift + 3, lcd_height - 1 - shift - height + 3);
        gui_set_text_color(gui_color(0, 0, 0));
        gui_set_text_border_color(gui_color(255, 255, 255));
        gui_print_bordered_text((UI_string_type) L"LAYER 1");

        gdi_layer_pop_and_restore_active();

        gdi_layer_set_blt_layer(mmi_em_prof_cntx.vdo_preview_layer, mmi_em_prof_cntx.extra_layer_1, 0, 0);

        blt_layer = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1;
    }

    if (mmi_em_prof_cntx.vdorec_extra_layer >= 2)
    {
        /* RED */
        mmi_em_prof_cntx.extra_layer_2_buf_ptr = (PU8) mmi_frm_scrmem_alloc(MMI_EM_PROF_LAYER_BUF_SIZE);
        ASSERT(mmi_em_prof_cntx.extra_layer_2_buf_ptr != NULL);

        gdi_layer_create_using_outside_memory(
            0,
            0,
            lcd_width,
            lcd_height,
            &mmi_em_prof_cntx.extra_layer_2,
            (PU8) mmi_em_prof_cntx.extra_layer_2_buf_ptr,
            (S32) MMI_EM_PROF_LAYER_BUF_SIZE);

        gdi_layer_push_and_set_active(mmi_em_prof_cntx.extra_layer_2);

        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);

        shift = 2;
        width = 100;
        height = 30;

        gdi_draw_rect(shift, shift, lcd_width - 1 - shift, lcd_height - 1 - shift, GDI_COLOR_RED);
        gdi_draw_rect(shift - 1, shift - 1, lcd_width - 1 - shift - 1, lcd_height - 1 - shift - 1, GDI_COLOR_RED);
        gdi_draw_solid_rect(shift, shift, shift + width, shift + height, GDI_COLOR_RED);

        gui_move_text_cursor(shift + 3, shift + 3);
        gui_set_text_color(gui_color(0, 0, 0));
        gui_set_text_border_color(gui_color(255, 255, 255));
        gui_print_bordered_text((UI_string_type) L"LAYER 2");

        gdi_layer_pop_and_restore_active();

        gdi_layer_set_blt_layer(
            mmi_em_prof_cntx.vdo_preview_layer,
            mmi_em_prof_cntx.extra_layer_1,
            mmi_em_prof_cntx.extra_layer_2,
            0);

        blt_layer = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2;
    }

    gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);

    SetKeyHandler(GoBackHistory, KEY_RSK, KEY_EVENT_UP);

    /* power on and init hardware module */
    mdi_video_rec_power_on();

    /* start preview */
    video_preview_data.wb = MDI_VIDEO_WB_AUTO;
    video_preview_data.ev = MDI_VIDEO_EV_0;
    video_preview_data.banding = MDI_VIDEO_BANDING_50HZ;
    video_preview_data.video_qty = MDI_VIDEO_REC_QTY_FINE;
    video_preview_data.video_format = MDI_VIDEO_VIDEO_FORMAT_MP4;
    video_preview_data.effect = MDI_VIDEO_EFFECT_NOMRAL;

    video_preview_data.zoom = 10;
    video_preview_data.night = FALSE;
    video_preview_data.brightness = 128;
    video_preview_data.contrast = 128;
    video_preview_data.saturation = 128;
    video_preview_data.hue = 0;
    video_preview_data.preview_rotate = MDI_VIDEO_LCD_ROTATE_0;
    video_preview_data.size_limit = 0;
    video_preview_data.record_aud = TRUE;
    video_preview_data.lcm_rotate = rotate;

    switch (mmi_em_prof_cntx.vdorec_record_size)
    {
        case MMI_EM_PROF_SIZE_SQCIF:
            video_preview_data.video_size = MDI_VIDEO_VIDEO_SIZE_SQCIF;
            break;

        case MMI_EM_PROF_SIZE_QCIF:
            video_preview_data.video_size = MDI_VIDEO_VIDEO_SIZE_QCIF;
            break;

        case MMI_EM_PROF_SIZE_CIF:
            video_preview_data.video_size = MDI_VIDEO_VIDEO_SIZE_CIF;
            break;

        case MMI_EM_PROF_SIZE_QQVGA:
            video_preview_data.video_size = MDI_VIDEO_VIDEO_SIZE_QQVGA;
            break;

        default:
            MMI_ASSERT(0);
            break;
    }

    video_preview_data.overlay_frame_mode = FALSE;
    video_preview_data.overlay_frame_depth = 0;
    video_preview_data.overlay_frame_width = 0;
    video_preview_data.overlay_frame_height = 0;
    video_preview_data.overlay_frame_source_key = 0;
    video_preview_data.overlay_frame_buffer_address = 0;

#ifdef __MMI_TVOUT__
    if (mdi_tvout_is_enable())
    {
        if (mmi_em_prof_cntx.vdorec_tvout_style == MMI_EM_PROF_TV_FULL_SCR)
        {
            /* fullscreen */

            /* if is fullscreen, we shall set to owner to video here, to avoid GDI's update */
            mdi_tvout_set_owner(MDI_TV_OWNER_VIDEO);

            /* full screen  */
            mdi_tvout_set_mode(MDI_TV_MODE_MULTIMEDIA_FULL_SCR, 0, 0);
        }
    }
#endif /* __MMI_TVOUT__ */ 

    mdi_video_rec_preview_start(
        mmi_em_prof_cntx.vdo_preview_layer,
        blt_layer,
        GDI_LAYER_ENABLE_LAYER_0,
        MMI_TRUE,
        &video_preview_data);

    SetKeyHandler(mmi_em_profiling_vdorec_record_key_release, KEY_ENTER, KEY_EVENT_UP);
    SetKeyHandler(mmi_em_profiling_vdorec_record_key_release, KEY_STAR, KEY_EVENT_UP);
    mmi_em_prof_cntx.is_vdo_recording = FALSE;

}
#endif /* defined(__MMI_VIDEO_RECORDER__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_exit_vdorec_play_scr
 * DESCRIPTION
 *  enter profiling multimedia camera screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_VIDEO_RECORDER__)
static void mmi_em_profiling_exit_vdorec_play_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* free resource */
    if (mmi_em_prof_cntx.is_vdo_recording)
    {
        mdi_video_rec_record_stop();
    }

    mdi_video_rec_preview_stop();
    mdi_video_rec_power_off();

    gdi_layer_free(mmi_em_prof_cntx.vdo_preview_layer);

    if (mmi_em_prof_cntx.vdorec_extra_layer >= 1)
    {
        gdi_layer_free(mmi_em_prof_cntx.extra_layer_1);

        mmi_frm_scrmem_free((void*)mmi_em_prof_cntx.extra_layer_1_buf_ptr);
        mmi_em_prof_cntx.extra_layer_1_buf_ptr = NULL;
    }

    if (mmi_em_prof_cntx.vdorec_extra_layer >= 2)
    {
        gdi_layer_free(mmi_em_prof_cntx.extra_layer_2);

        mmi_frm_scrmem_free((void*)mmi_em_prof_cntx.extra_layer_2_buf_ptr);
        mmi_em_prof_cntx.extra_layer_2_buf_ptr = NULL;
    }

    gdi_layer_set_blt_layer(mmi_em_prof_cntx.base_layer, 0, 0, 0);

    /* rotate lcd */
    gdi_lcd_set_rotate(GDI_LAYER_ROTATE_0);

#ifdef __MMI_TVOUT__
    /* tvout */
    if (mmi_em_prof_cntx.vdorec_tvout_style == MMI_EM_PROF_TV_FULL_SCR)
    {
        /* set owner back to GDI */
        mdi_tvout_set_owner(MDI_TV_OWNER_GDI);

        mdi_tvout_set_mode(MDI_TV_MODE_LCD_SCR, 0, 0);
    }
#endif /* __MMI_TVOUT__ */ 

    /* resume alignment timer */
    UI_enable_alignment_timers();

    /* let MMI can sleep */
    TurnOffBacklight();

    /* enable multi-layer */
    gdi_layer_multi_layer_disable();

    /* resume background audio */
    mdi_audio_resume_background_play();

    /* re-enable keypad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);

    /* this will force title status to redraw */
    entry_full_screen();

}
#endif /* defined(__MMI_VIDEO_RECORDER__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_vdorec_record_key_release
 * DESCRIPTION
 *  record key release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_VIDEO_RECORDER__
static void mmi_em_profiling_vdorec_record_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret_drv;
    S8 buf_filename[(FMGR_MAX_FILE_LEN + 1) * ENCODING_LENGTH];
    S8 buf[64];
    S32 string_width = 0;
    S32 string_height = 0;
    S32 offset_x = 0;
    S32 offset_y = 0;
    S32 lcd_width = 0;
    S32 lcd_height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_em_prof_cntx.vdorec_extra_layer >= 1)
    {
        switch (mmi_em_prof_cntx.vdorec_rotate)
        {
            case MMI_EM_PROF_ROTATE_0:
            case MMI_EM_PROF_ROTATE_180:
                lcd_width = UI_device_width;
                lcd_height = UI_device_height;
                break;

            case MMI_EM_PROF_ROTATE_90:
            case MMI_EM_PROF_ROTATE_270:
                lcd_width = UI_device_height;
                lcd_height = UI_device_width;
                break;
        }

        gui_measure_string((UI_string_type) L"Recording", &string_width, &string_height);
        offset_x = (lcd_width - string_width) >> 1;
        offset_y = (lcd_height - string_height) >> 1;
    }

    if (mmi_em_prof_cntx.is_first_time_enter)
    {
        mmi_em_prof_cntx.is_first_time_enter = FALSE;
        ret_drv = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_I_SYSTEM);

        sprintf(buf, "%c:\\", (U8) ret_drv);
        mmi_asc_to_ucs2(buf_filename, buf);

        /* delete if file exist */
        mdi_video_rec_delete_unsaved_file(buf_filename);
        mmi_ucs2cat(buf_filename, (PS8) L"Profiling.3gp");

        mdi_video_rec_record_start(buf_filename, mmi_em_profiling_vdorec_record_result_callback);
        mmi_em_prof_cntx.is_vdo_recording = TRUE;

        if (mmi_em_prof_cntx.vdorec_extra_layer >= 1)
        {
            gdi_layer_push_and_set_active(mmi_em_prof_cntx.extra_layer_1);
            gui_move_text_cursor(offset_x, offset_y);
            gui_set_text_color(gui_color(0, 0, 0));
            gui_set_text_border_color(gui_color(255, 255, 255));
            gui_print_bordered_text((UI_string_type) L"Recording");
            gdi_layer_pop_and_restore_active();

            gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);
        }
    }
    else if (mmi_em_prof_cntx.is_vdo_recording == FALSE)
    {
        mmi_em_prof_cntx.is_vdo_recording = TRUE;
        mdi_video_rec_record_resume();

        if (mmi_em_prof_cntx.vdorec_extra_layer >= 1)
        {
            gdi_layer_push_and_set_active(mmi_em_prof_cntx.extra_layer_1);
            gui_move_text_cursor(offset_x, offset_y);
            gui_set_text_color(gui_color(0, 0, 0));
            gui_set_text_border_color(gui_color(255, 255, 255));
            gui_print_bordered_text((UI_string_type) L"Recording");
            gdi_layer_pop_and_restore_active();
            gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);
        }
    }
    else
    {
        if (mmi_em_prof_cntx.vdorec_extra_layer >= 1)
        {
            gdi_layer_push_and_set_active(mmi_em_prof_cntx.extra_layer_1);
            gdi_draw_solid_rect(
                offset_x - 5,
                offset_y - 5,
                offset_x + string_width + 5,
                offset_y + string_height + 5,
                GDI_COLOR_TRANSPARENT);

            gdi_layer_pop_and_restore_active();
            gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);
        }

        mdi_video_rec_record_pause(KAL_FALSE);
        mmi_em_prof_cntx.is_vdo_recording = FALSE;
    }

}
#endif /* __MMI_VIDEO_RECORDER__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_vdorec_record_result_callback
 * DESCRIPTION
 *  record result handler
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_VIDEO_RECORDER__
static void mmi_em_profiling_vdorec_record_result_callback(MDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result < 0)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);
    }

    mmi_em_prof_cntx.is_vdo_recording = FALSE;
}
#endif /* __MMI_VIDEO_RECORDER__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_entry_vdorec_option_scr
 * DESCRIPTION
 *  enter profiling multimedia video recorder screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_VIDEO_RECORDER__)
static void mmi_em_profiling_entry_vdorec_option_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 item_list[16];
    U16 item_icons[16];
    U16 num_item;
    U8 *gui_buffer;
    U8 *popup_list[16];
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EM_PROFILING_VDOREC_OPTION, NULL, mmi_em_profiling_entry_vdorec_option_scr, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_EM_PROFILING_VDOREC_OPTION);
    num_item = GetNumOfChild(MENU_ID_EM_PROFILING_VDOREC);

    GetSequenceStringIds(MENU_ID_EM_PROFILING_VDOREC, item_list);
    GetSequenceImageIds(MENU_ID_EM_PROFILING_VDOREC, item_icons);
    SetParentHandler(MENU_ID_EM_PROFILING_VDOREC);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (i = 0; i < num_item; i++)
    {
        item_icons[i] = (U16) (IMG_GLOBAL_L1 + i);
    }

    for (i = 0; i < num_item; i++)
    {
        popup_list[i] = NULL;
    }

    ConstructHintsList(MENU_ID_EM_PROFILING_VDOREC, popup_list);

    ShowCategory52Screen(
        STR_ID_EM_PROFILING_VDOREC,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_item,
        item_list,
        item_icons,
        (U8 **) popup_list,
        0,
        0,
        gui_buffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}
#endif /* defined(__MMI_VIDEO_RECORDER__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_entry_vdorec_setting_scr
 * DESCRIPTION
 *  enter profiling multimedia video recorder setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_VIDEO_RECORDER__)
static void mmi_em_profiling_entry_vdorec_setting_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    U8 *input_buffer;
    U16 item_offset;
    U16 input_buffer_size;

    MMI_ID_TYPE item_icons[] = 
    {
        IMG_GLOBAL_L1,
        0,
        IMG_GLOBAL_L2,
        0,
        IMG_GLOBAL_L3,
        0,
        IMG_GLOBAL_L4,
        0,
        IMG_GLOBAL_L5,
        0,
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Video Recorder Settings:
     * (1) Extra Layer
     * (2) Rotate
     * (3) Preview Size
     * (4) Record Size
     * (5) TV-Out Style
     */

    EntryNewScreen(SCR_ID_EM_PROFILING_VDOREC_SETTING, mmi_em_profiling_exit_vdorec_setting_scr, NULL, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_EM_PROFILING_VDOREC_SETTING);
    input_buffer = GetCurrNInputBuffer(SCR_ID_EM_PROFILING_VDOREC_SETTING, &input_buffer_size);

    /* clear inline item */
    memset((void*)wgui_inline_items, 0, sizeof(InlineItem) * 5 * 2);   /* 5 items, each has two line */
    item_offset = 0;

    /* start of Category 57 */
    InitializeCategory57Screen();

    /* (1) Extra Layer (0, 1, 2) */
    mmi_em_prof_inline_cntx.inline_str_1[0] = (UI_string_type) GetString((U16) (STR_GLOBAL_0));
    mmi_em_prof_inline_cntx.inline_str_1[1] = (UI_string_type) GetString((U16) (STR_GLOBAL_1));
    mmi_em_prof_inline_cntx.inline_str_1[2] = (UI_string_type) GetString((U16) (STR_GLOBAL_2));

    mmi_em_prof_inline_cntx.inline_value_1 = mmi_em_prof_cntx.vdorec_extra_layer;

    SetInlineItemCaption(&wgui_inline_items[item_offset], (PU8) GetString((U16) (STR_ID_EM_PROFILING_EXTRA_LAYER)));
    item_offset++;

    SetInlineItemActivation(&wgui_inline_items[item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemSelect(
        &wgui_inline_items[item_offset],
        3,
        (U8 **) mmi_em_prof_inline_cntx.inline_str_1,
        &mmi_em_prof_inline_cntx.inline_value_1);
    item_offset++;

    /* (2) LCM Rotate  (0, 90, 180, 270) */
    mmi_em_prof_inline_cntx.inline_str_2[0] = (UI_string_type) GetString((U16) (STR_ID_EM_PROFILING_ROTATE_0));
    mmi_em_prof_inline_cntx.inline_str_2[1] = (UI_string_type) GetString((U16) (STR_ID_EM_PROFILING_ROTATE_90));
    mmi_em_prof_inline_cntx.inline_str_2[2] = (UI_string_type) GetString((U16) (STR_ID_EM_PROFILING_ROTATE_180));
    mmi_em_prof_inline_cntx.inline_str_2[3] = (UI_string_type) GetString((U16) (STR_ID_EM_PROFILING_ROTATE_270));

    mmi_em_prof_inline_cntx.inline_value_2 = mmi_em_prof_cntx.vdorec_rotate;

    SetInlineItemCaption(&wgui_inline_items[item_offset], (PU8) GetString((U16) (STR_ID_EM_PROFILING_ROTATE)));
    item_offset++;

    SetInlineItemActivation(&wgui_inline_items[item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemSelect(
        &wgui_inline_items[item_offset],
        4,
        (U8 **) mmi_em_prof_inline_cntx.inline_str_2,
        &mmi_em_prof_inline_cntx.inline_value_2);
    item_offset++;

    /* (3) Preview Size (SQCIF, QCIF, CIF, QQVGA, QVGA, VGA, LCD) */
    mmi_em_prof_inline_cntx.inline_str_3[0] = (UI_string_type) GetString((U16) (STR_ID_EM_PROFILING_SIZE_SQCIF));
    mmi_em_prof_inline_cntx.inline_str_3[1] = (UI_string_type) GetString((U16) (STR_ID_EM_PROFILING_SIZE_QCIF));
    mmi_em_prof_inline_cntx.inline_str_3[2] = (UI_string_type) GetString((U16) (STR_ID_EM_PROFILING_SIZE_CIF));
    mmi_em_prof_inline_cntx.inline_str_3[3] = (UI_string_type) GetString((U16) (STR_ID_EM_PROFILING_SIZE_QQVGA));
    mmi_em_prof_inline_cntx.inline_str_3[4] = (UI_string_type) GetString((U16) (STR_ID_EM_PROFILING_SIZE_QVGA));
    mmi_em_prof_inline_cntx.inline_str_3[5] = (UI_string_type) GetString((U16) (STR_ID_EM_PROFILING_SIZE_VGA));
    mmi_em_prof_inline_cntx.inline_str_3[6] = (UI_string_type) GetString((U16) (STR_ID_EM_PROFILING_SIZE_LCD));

    mmi_em_prof_inline_cntx.inline_value_3 = mmi_em_prof_cntx.vdorec_preview_size;

    SetInlineItemCaption(&wgui_inline_items[item_offset], (PU8) GetString((U16) (STR_ID_EM_PROFILING_PREVIEW_SIZE)));
    item_offset++;

    SetInlineItemActivation(&wgui_inline_items[item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemSelect(
        &wgui_inline_items[item_offset],
        7,
        (U8 **) mmi_em_prof_inline_cntx.inline_str_3,
        &mmi_em_prof_inline_cntx.inline_value_3);
    item_offset++;

    /* (4) Record  Size (SQCIF, QCIF, CIF, QQVGA) */
    mmi_em_prof_inline_cntx.inline_str_4[0] = (UI_string_type) GetString((U16) (STR_ID_EM_PROFILING_SIZE_SQCIF));
    mmi_em_prof_inline_cntx.inline_str_4[1] = (UI_string_type) GetString((U16) (STR_ID_EM_PROFILING_SIZE_QCIF));
    mmi_em_prof_inline_cntx.inline_str_4[2] = (UI_string_type) GetString((U16) (STR_ID_EM_PROFILING_SIZE_CIF));
    mmi_em_prof_inline_cntx.inline_str_4[3] = (UI_string_type) GetString((U16) (STR_ID_EM_PROFILING_SIZE_QQVGA));
    //      mmi_em_prof_inline_cntx.inline_str_4[4] = (UI_string_type)GetString((U16)(STR_ID_EM_PROFILING_SIZE_QVGA));
    //      mmi_em_prof_inline_cntx.inline_str_4[5] = (UI_string_type)GetString((U16)(STR_ID_EM_PROFILING_SIZE_VGA));
    //      mmi_em_prof_inline_cntx.inline_str_4[6] = (UI_string_type)GetString((U16)(STR_ID_EM_PROFILING_SIZE_LCD));

    mmi_em_prof_inline_cntx.inline_value_4 = mmi_em_prof_cntx.vdorec_record_size;

    SetInlineItemCaption(&wgui_inline_items[item_offset], (PU8) GetString((U16) (STR_ID_EM_PROFILING_RECORD_SIZE)));
    item_offset++;

    SetInlineItemActivation(&wgui_inline_items[item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemSelect(
        &wgui_inline_items[item_offset],
        4,
        (U8 **) mmi_em_prof_inline_cntx.inline_str_4,
        &mmi_em_prof_inline_cntx.inline_value_4);
    item_offset++;

    /* (6) TV-Out Styel (Full Screen, LCD Screen) */
    mmi_em_prof_inline_cntx.inline_str_5[0] = (UI_string_type) GetString((U16) (STR_ID_EM_PROFILING_TV_LCD_SCREEN));
    mmi_em_prof_inline_cntx.inline_str_5[1] = (UI_string_type) GetString((U16) (STR_ID_EM_PROFILING_TV_FULL_SCREEN));

    mmi_em_prof_inline_cntx.inline_value_5 = mmi_em_prof_cntx.vdorec_tvout_style;

    SetInlineItemCaption(&wgui_inline_items[item_offset], (PU8) GetString((U16) (STR_ID_EM_PROFILING_TV_OUT_MODE)));
    item_offset++;

    SetInlineItemActivation(&wgui_inline_items[item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemSelect(
        &wgui_inline_items[item_offset],
        2,
        (U8 **) mmi_em_prof_inline_cntx.inline_str_5,
        &mmi_em_prof_inline_cntx.inline_value_5);
    item_offset++;

    RegisterHighlightHandler(mmi_em_profiling_vdorec_setting_highlight_hdlr);

    /* show category */
    ShowCategory57Screen(
        STR_ID_EM_PROFILING_VDOREC,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        item_offset,
        item_icons,
        wgui_inline_items,
        0,
        gui_buffer);

    /* set key hdlr */
    SetCategory57LeftSoftkeyFunction(mmi_em_profiling_vdorec_setting_lsk_done);
    DisableCategory57ScreenDone();
    SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);

}
#endif /* defined(__MMI_VIDEO_RECORDER__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_exit_vdorec_setting_scr
 * DESCRIPTION
 *  exit profiling multimedia video recorder setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_VIDEO_RECORDER__)
static void mmi_em_profiling_exit_vdorec_setting_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 input_buffer_size;
    history h;
    S16 n_history = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h.scrnID = SCR_ID_EM_PROFILING_VDOREC_SETTING;
    CloseCategory57Screen();
    h.entryFuncPtr = mmi_em_profiling_entry_vdorec_setting_scr;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & n_history);
    GetCategory57History(h.guiBuffer);
    input_buffer_size = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, input_buffer_size);

}
#endif /* defined(__MMI_VIDEO_RECORDER__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_vdorec_setting_highlight_hdlr
 * DESCRIPTION
 *  highlight handler
 * PARAMETERS
 *  index       [IN]        Index
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_VIDEO_RECORDER__)
static void mmi_em_profiling_vdorec_setting_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetCategory57LeftSoftkeyFunction(mmi_em_profiling_vdorec_setting_lsk_done);
}
#endif /* defined(__MMI_VIDEO_RECORDER__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_vdorec_setting_lsk_done
 * DESCRIPTION
 *  lsk done handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_VIDEO_RECORDER__)
static void mmi_em_profiling_vdorec_setting_lsk_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_em_prof_cntx.vdorec_extra_layer = mmi_em_prof_inline_cntx.inline_value_1;
    mmi_em_prof_cntx.vdorec_rotate = mmi_em_prof_inline_cntx.inline_value_2;
    mmi_em_prof_cntx.vdorec_preview_size = mmi_em_prof_inline_cntx.inline_value_3;
    mmi_em_prof_cntx.vdorec_record_size = mmi_em_prof_inline_cntx.inline_value_4;
    mmi_em_prof_cntx.vdorec_tvout_style = mmi_em_prof_inline_cntx.inline_value_5;

    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);
    DeleteNHistory(1);
}
#endif /* defined(__MMI_VIDEO_RECORDER__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_highlight_imgdec
 * DESCRIPTION
 *  hilight profiling multimedia image decode menuitem
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_IMG_DEC_PROFILING__
static void mmi_em_profiling_highlight_imgdec(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_em_profiling_entry_imgdec_option_scr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
} 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_highlight_imgdec_folder
 * DESCRIPTION
 *  hilight profiling multimedia image decode menuitem
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_profiling_highlight_imgdec_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_em_prof_cntx.imgdec_is_horz_view_set = FALSE;
    SetLeftSoftkeyFunction(mmi_em_profiling_imgdec_folder_select_scr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
} 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_highlight_imgdec_folder_rotate
 * DESCRIPTION
 *  hilight profiling multimedia image decode rotate [landscape view] menuitem
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_profiling_highlight_imgdec_folder_rotate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_em_prof_cntx.imgdec_is_horz_view_set = MMI_EM_PROF_HORIZONTAL_VIEW;
    SetLeftSoftkeyFunction(mmi_em_profiling_imgdec_folder_select_scr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_entry_imgdec_option_scr
 * DESCRIPTION
 *  enter profiling multimedia image decode option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_profiling_entry_imgdec_option_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 item_list[16];
    U16 item_icons[16];
    U16 num_item;
    U8 *gui_buffer;
    U8 *popup_list[16];
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EM_PROFILING_IMGDEC_OPTION, NULL, mmi_em_profiling_entry_imgdec_option_scr, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_EM_PROFILING_IMGDEC_OPTION);
    num_item = GetNumOfChild(MENU_ID_EM_PROFILING_IMAGE_DECODE);

    GetSequenceStringIds(MENU_ID_EM_PROFILING_IMAGE_DECODE, item_list);
    GetSequenceImageIds(MENU_ID_EM_PROFILING_IMAGE_DECODE, item_icons);
    SetParentHandler(MENU_ID_EM_PROFILING_IMAGE_DECODE);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (i = 0; i < num_item; i++)
    {
        item_icons[i] = (U16)(IMG_GLOBAL_L1 + i);
    }

    for (i = 0; i < num_item; i++)
    {
        popup_list[i] = NULL;
    }

    ConstructHintsList(MENU_ID_EM_PROFILING_IMAGE_DECODE, popup_list);

    ShowCategory52Screen(
        STR_ID_EM_PROFILING_IMAGE_DECODE,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_item,
        item_list,
        item_icons,
        (U8 **) popup_list,
        0,
        0,
        gui_buffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_entry_imgdec_gendisp_scr
 * DESCRIPTION
 *  enter profiling multimedia image decode screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_profiling_entry_imgdec_gendisp_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(
        SCR_ID_EM_PROFILING_IMGDEC_GEN_DISP,
        mmi_em_profiling_exit_imgdec_gendisp_scr,
        mmi_em_profiling_entry_imgdec_gendisp_scr,
        NULL);

    /* this will force title status to redraw */
    entry_full_screen();
    
    mmi_em_prof_cntx.is_fmgr_init = FALSE;

    /* stop MMI sleep */
    TurnOnBacklight(0);
    ShowCategory221Screen(
        STR_ID_EM_PROFILING_SINGLE_FOLDER,
        0,
        NULL,
        IMG_GLOBAL_CLEAR,
        STR_GLOBAL_CANCEL,
        IMG_GLOBAL_CLEAR,
        GDI_COLOR_WHITE,
        NULL);
    
    SetRightSoftkeyFunction(mmi_em_profiling_stop_imgdec_decoding, KEY_EVENT_UP);
    
    gui_start_timer(100, mmi_em_profiling_imgdec_decode_next_file);    

} 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_exit_imgdec_gendisp_scr
 * DESCRIPTION
 *  enter profiling multimedia image decode screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_profiling_exit_imgdec_gendisp_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    gui_cancel_timer(mmi_em_profiling_imgdec_decode_next_file);
    gdi_layer_free(mmi_em_prof_cntx.imgdec_layer_handle);
    gdi_layer_multi_layer_disable();

    mmi_frm_scrmem_free((void *)mmi_em_prof_cntx.imgdec_buf_ptr);
    mmi_em_prof_cntx.is_fmgr_init = FALSE;
    FS_Close(mmi_em_prof_cntx.imgdec_fs_handle); 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_entry_imgdec_scr
 * DESCRIPTION
 *  enter profiling multimedia image decode full screen [landscape view]
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_profiling_entry_imgdec_fulldisp_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(
        SCR_ID_EM_PROFILING_IMGDEC_FULL_DISP,
        mmi_em_profiling_exit_imgdec_fulldisp_scr,
        mmi_em_profiling_entry_imgdec_fulldisp_scr,
        NULL);

    entry_full_screen();
    
    mmi_em_prof_cntx.is_fmgr_init = FALSE;

    /* stop MMI sleep */
    TurnOnBacklight(0);
    
    SetRightSoftkeyFunction(mmi_em_profiling_stop_imgdec_decoding, KEY_EVENT_UP);
    
    gui_start_timer(100, mmi_em_profiling_imgdec_decode_next_file);    
} 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_exit_imgdec_fulldisp_scr
 * DESCRIPTION
 *  exit profiling multimedia image decode screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_profiling_exit_imgdec_fulldisp_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    gui_cancel_timer(mmi_em_profiling_imgdec_decode_next_file);
    
    gdi_lcd_set_rotate(GDI_LAYER_ROTATE_0);
    gdi_layer_resize(UI_device_width, UI_device_height);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_lcd_set_rotate_by_layer(FALSE);
    
    gdi_layer_free(mmi_em_prof_cntx.imgdec_layer_handle);
    gdi_layer_multi_layer_disable();

    mmi_frm_scrmem_free((void *)mmi_em_prof_cntx.imgdec_buf_ptr);
    mmi_em_prof_cntx.is_fmgr_init = FALSE;
    FS_Close(mmi_em_prof_cntx.imgdec_fs_handle); 
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_imgdec_decode_next_file
 * DESCRIPTION
 *  profiling multimedia image decode the next file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_profiling_imgdec_decode_next_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 filepath[FMGR_PATH_BUFFER_SIZE];
    S8 logfilename[FMGR_PATH_BUFFER_SIZE];
    S8 str_buf[(MMI_EM_PROF_TEXT_MAX_CHAR + 10) * ENCODING_LENGTH];
    S8 filename[FMGR_PATH_CHAR_COUNT];
    S8 log[100];
    S8 IMG_TYPE_Str[10];
    
    S32 image_width;
    S32 image_height; 
    static S32 display_wnd_width;
    static S32 display_wnd_height;
    static S32 resized_image_offset_x;
    static S32 resized_image_offset_y;
    static S32 resized_image_width;
    static S32 resized_image_height;
    static S32 SCR_WIDTH;
    static S32 SCR_HEIGHT;   
    
    U16 file_count;
    U16 img_type;
    U32 written_length;

    FMGR_FILTER filter;   
    FMGR_FILE_INFO_STRUCT file_info; 
    GDI_RESULT gdi_ret;
    kal_uint32 tick_start,tick_end;
    float tick_elapsed;
    kal_uint32 tick_elapsed_fraction;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_em_prof_cntx.is_fmgr_init)
    {
        mmi_em_prof_cntx.is_fmgr_init = TRUE;

        /* file handling */
        fmgr_reset_app_select();

        FMGR_FILTER_INIT(&filter);
        FMGR_FILTER_SET_IMAGE(&filter);

        /* init */
        mmi_fmgr_kernel_init(mmi_em_prof_cntx.filepath, filter, &file_count);

        if (file_count == 0)
        {
            DisplayPopup((PU8) GetString(STR_GLOBAL_EMPTY), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);
            DeleteUptoScrID(SCR_ID_EM_PROFILING_MULTIMEDIA);
            return;
        }
        mmi_em_prof_cntx.imgdec_file_num = file_count;
        mmi_ucs2cpy(logfilename, mmi_em_prof_cntx.filepath);
                
        mmi_em_prof_cntx.imgdec_fs_handle = FS_Open((PU16)logfilename, (FS_READ_WRITE | FS_CREATE_ALWAYS));
        
        if(mmi_em_prof_cntx.imgdec_is_horz_view_set == MMI_EM_PROF_HORIZONTAL_VIEW)
        {
            SCR_WIDTH = UI_device_height;
            SCR_HEIGHT = UI_device_width;
            /* full screen display window size */
            display_wnd_width = SCR_WIDTH - MMI_EM_PROF_CLIP_SCREEN_BOLDER*2;
            display_wnd_height = SCR_HEIGHT - MMI_EM_PROF_CLIP_SCREEN_BOLDER*2;

            mmi_ucs2cat(logfilename, (PS8) L"\\ImgDec_log_r.csv");
        }
        else
        {
            SCR_WIDTH = UI_device_width;
            SCR_HEIGHT = UI_device_height;            
            /* general display window size */
            display_wnd_width = UI_device_width - MMI_EM_PROF_CLIP_SCREEN_BOLDER * 2;
            display_wnd_height = MMI_content_height - MMI_EM_PROF_CLIP_SCREEN_BOLDER*2;

            mmi_ucs2cat(logfilename, (PS8) L"\\ImgDec_log.csv");
        }
        mmi_em_prof_cntx.imgdec_fs_handle = FS_Open((PU16)logfilename, (FS_READ_WRITE | FS_CREATE_ALWAYS)); 

        sprintf(str_buf, "filename,\tTYPE,\twidth,\theight,\tdec_width,\tdec_height,\tdecode time (ms),\tsize (Byte)\x0D\x0A");
        FS_Write(mmi_em_prof_cntx.imgdec_fs_handle, (void*)str_buf, strlen(str_buf), (U32*) & written_length);        

        /* enable multi-layer */
        gdi_layer_multi_layer_enable();
        
        /* allocate buffer */        
        mmi_em_prof_cntx.imgdec_buf_ptr= (PU8) mmi_frm_scrmem_alloc(UI_device_width*UI_device_height*GDI_COLOR_FORMAT_16);    
        ASSERT(mmi_em_prof_cntx.imgdec_buf_ptr != NULL);

        /* create 16 bit layer */
        gdi_layer_create_cf_using_outside_memory(   
            GDI_COLOR_FORMAT_16,
            0,
            0,
            UI_device_width,
            UI_device_height,
            &mmi_em_prof_cntx.imgdec_layer_handle,
            (PU8) mmi_em_prof_cntx.imgdec_buf_ptr,
            (S32) (UI_device_width*UI_device_height*GDI_COLOR_FORMAT_16));   
       
        mmi_em_prof_cntx.play_type = MMI_EM_PROF_PLAY_TYPE_IMAGE; 
            
        ASSERT(mmi_em_prof_cntx.imgdec_layer_handle != NULL); 
    }
    
    gdi_layer_push_and_set_active(mmi_em_prof_cntx.imgdec_layer_handle);        
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT); 
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_blt_layer(mmi_em_prof_cntx.imgdec_layer_handle, 0, 0, 0);

    if(mmi_em_prof_cntx.imgdec_is_horz_view_set == MMI_EM_PROF_HORIZONTAL_VIEW)
    {
        /* rotate layer 270 for full screen */
        gdi_lcd_set_rotate(GDI_LAYER_ROTATE_270);
        gdi_layer_resize(SCR_WIDTH, SCR_HEIGHT);
        gdi_lcd_set_rotate_by_layer(TRUE); 
    }

    mmi_em_prof_cntx.imgdec_file_index = mmi_fmgr_kernel_get_cur_idx();
    mmi_fmgr_kernel_get_file_info((S32) (mmi_fmgr_kernel_get_cur_idx()), &file_info);  
    mmi_em_prof_cntx.imgdec_file_size = file_info.file_size;
 
    mmi_ucs2cpy(filepath, mmi_em_prof_cntx.filepath);
    mmi_ucs2cat(filepath, file_info.file_name);

    filename[0] = '\"';
    mmi_ucs2_to_asc((S8 *)(filename+1), (PS8) file_info.file_name);
       
    gdi_image_get_dimension_file(filepath, &image_width, &image_height);
    img_type = gdi_image_get_type_from_file((PS8) filepath);   
    
    if ((display_wnd_width >= image_width) && (display_wnd_height >= image_height))
    {
        /* align preview window at the center of screen */
        resized_image_width = image_width;
        resized_image_height = image_height;
        if(mmi_em_prof_cntx.imgdec_is_horz_view_set == MMI_EM_PROF_HORIZONTAL_VIEW)
        {
            resized_image_offset_x =
                ((display_wnd_width - image_width) >> 1) + MMI_EM_PROF_CLIP_SCREEN_BOLDER;
            resized_image_offset_y =
                ((display_wnd_height - image_height) >> 1) + MMI_EM_PROF_CLIP_SCREEN_BOLDER;            
        }
        else
        {
            resized_image_offset_x =
                ((display_wnd_width - image_width) >> 1) + MMI_EM_PROF_CLIP_SCREEN_BOLDER;
            resized_image_offset_y =
                ((display_wnd_height - image_height) >> 1) + MMI_title_height + MMI_title_y +
                MMI_EM_PROF_CLIP_SCREEN_BOLDER;
        }
        kal_get_time(&tick_start);        
        gdi_ret = gdi_image_draw_file(resized_image_offset_x, resized_image_offset_y, (PS8) filepath);
        kal_get_time(&tick_end);              
    }  
    else
    {
        /* fit image to display window */
        gdi_image_util_fit_bbox(
            display_wnd_width,
            display_wnd_height,
            image_width,
            image_height,
            &resized_image_offset_x,
            &resized_image_offset_y,
            &resized_image_width,
            &resized_image_height);    
        
        if (resized_image_width == 0)
        {
            resized_image_width = 1;
            resized_image_offset_x--;
        }

        if (resized_image_height == 0)
        {
            resized_image_height = 1;
            resized_image_offset_y--;
        }
        
        if(mmi_em_prof_cntx.imgdec_is_horz_view_set == MMI_EM_PROF_HORIZONTAL_VIEW)
        {
            resized_image_offset_x += MMI_EM_PROF_CLIP_SCREEN_BOLDER;
            resized_image_offset_y += MMI_EM_PROF_CLIP_SCREEN_BOLDER;            
        }
        else
        {
            resized_image_offset_x += MMI_EM_PROF_CLIP_SCREEN_BOLDER;
            resized_image_offset_y += MMI_title_height + MMI_title_y + MMI_EM_PROF_CLIP_SCREEN_BOLDER;
        }
        
        kal_get_time(&tick_start);        
        gdi_ret = gdi_image_draw_resized_file(
                    resized_image_offset_x,
                    resized_image_offset_y,
                    resized_image_width,
                    resized_image_height,
                    filepath);
        kal_get_time(&tick_end);          
    }
        
    if(gdi_ret >= 0)
    {
        tick_elapsed = (tick_end - tick_start);
        tick_elapsed = ((float)tick_elapsed * 4.615);//msec
        tick_elapsed_fraction = (tick_end - tick_start)*4615 - ((int)tick_elapsed)*1000;
        
        /* log string processing*/
        if(mmi_em_prof_cntx.imgdec_is_horz_view_set == MMI_EM_PROF_HORIZONTAL_VIEW)
        {
            sprintf(log, "%d/%d, decode time = %.1f ms",
                mmi_em_prof_cntx.imgdec_file_index+1,
                mmi_em_prof_cntx.imgdec_file_num,
                tick_elapsed);
        }
        else
        {
            sprintf(log, "%d/%d, decode T = %.1f ms",
                mmi_em_prof_cntx.imgdec_file_index+1,
                mmi_em_prof_cntx.imgdec_file_num,
                tick_elapsed);            
        }
        mmi_asc_to_ucs2((PS8)str_buf, (PS8) log);
        
        sprintf(log, ",\t%d,\t%d,\t%d,\t%d,\t%.2f,\t%d\x0D\x0A",
            image_width, image_height, resized_image_width, resized_image_height, tick_elapsed, mmi_em_prof_cntx.imgdec_file_size);

        mmi_em_profiling_get_imgtype_string(img_type,IMG_TYPE_Str);
        PRINT_INFORMATION(" filename = %s", (filename+1));
        MMI_TRACE(MMI_TRACE_INFO, EM_PROFILING_IMAGE_DEC_INFO,
            mmi_em_prof_cntx.imgdec_file_index+1,
            mmi_em_prof_cntx.imgdec_file_num,
            image_width,
            image_height,
            resized_image_width,
            resized_image_height,
            (int)tick_elapsed,
            tick_elapsed_fraction); 

        strcat(filename,"\"");
        strcat(filename, IMG_TYPE_Str);
        strcat(filename, log);
        FS_Write(mmi_em_prof_cntx.imgdec_fs_handle, (void*)filename, strlen(filename), (U32*)&written_length);
        
    }
    else
    {
        gdi_layer_clear(GDI_COLOR_WHITE);

        /* log string processing */
        sprintf(log, "%d/%d, ", mmi_em_prof_cntx.imgdec_file_index+1, mmi_em_prof_cntx.imgdec_file_num);

        mmi_asc_to_ucs2((PS8)str_buf, (PS8)log);
        mmi_ucs2cat(str_buf, file_info.file_name);
        mmi_ucs2cat(str_buf, (PS8)" ");
        mmi_ucs2cat(str_buf, (PS8)get_string(STR_GLOBAL_ERROR));

        sprintf(IMG_TYPE_Str, ",\tError\x0D\x0A");
        PRINT_INFORMATION(" filename = %s", (filename+1));
        MMI_TRACE(MMI_TRACE_INFO, EM_PROFILING_IMAGE_DEC_FAIL,
            mmi_em_prof_cntx.imgdec_file_index+1,
            mmi_em_prof_cntx.imgdec_file_num); 
            
        strcat(filename,"\"");
        strcat(filename, IMG_TYPE_Str);
        FS_Write(mmi_em_prof_cntx.imgdec_fs_handle, (void*)filename, strlen(filename), (U32*)&written_length);
    }
    
    /* blt the image and draw string */
    if(mmi_em_prof_cntx.imgdec_is_horz_view_set == MMI_EM_PROF_HORIZONTAL_VIEW)
    {
        mmi_em_profiling_draw_style_text(str_buf, MMI_EM_PROF_CLIP_SCREEN_SPACING,
            SCR_HEIGHT - MMI_EM_PROF_CLIP_SCREEN_BOLDER);    
            
        mmi_em_profiling_draw_rsk((PS8)get_string(STR_GLOBAL_CANCEL));
            
        gdi_layer_blt_previous(0, 0, SCR_WIDTH- 1, SCR_HEIGHT-1);
    }
    else
    {
        mmi_em_profiling_draw_style_text(str_buf, MMI_EM_PROF_CLIP_SCREEN_SPACING,
            MMI_STATUS_BAR_HEIGHT+MMI_TITLE_HEIGHT);
        
        gdi_layer_blt_previous(0, MMI_STATUS_BAR_HEIGHT+MMI_TITLE_HEIGHT, 
            SCR_WIDTH- 1,SCR_HEIGHT-MMI_BUTTON_BAR_HEIGHT- 1);
    }    
    
    gdi_layer_pop_and_restore_active();
    gdi_layer_flatten_to_base(mmi_em_prof_cntx.imgdec_layer_handle,0,0,0);

    /*check if the next file is available*/
    if(mmi_fmgr_kernel_get_cur_idx() < mmi_em_prof_cntx.imgdec_file_num - 1)
    {        
        gui_start_timer(1000, mmi_em_profiling_imgdec_decode_next_file);
        mmi_fmgr_kernel_move_selection_down();
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_imgdec_folder_select_scr
 * DESCRIPTION
 *  enter profiling multimedia image decode folder screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_profiling_imgdec_folder_select_scr(void)
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
        APP_ENGINEERMODE,
        FMGR_SELECT_FOLDER | FMGR_SELECT_REPEAT,
        filter,
        (S8*) L"root",
        mmi_em_profiling_imgdec_folder_selected); 
} 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_imgdec_file_selected
 * DESCRIPTION
 *  file selected
 * PARAMETERS
 *  path            [IN]        File path
 *  is_short        [IN]        Is short filename
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_profiling_imgdec_folder_selected(void *path, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (path == NULL)
    {
        /* delete filemgr history */
        DeleteUptoScrID(SCR_ID_EM_PROFILING_MULTIMEDIA);
        GoBackHistory();
        return;
    }

    mmi_ucs2cpy((PS8) mmi_em_prof_cntx.filepath, (PS8) path);

    /* enter image dec setting */
    if(mmi_em_prof_cntx.imgdec_is_horz_view_set == MMI_EM_PROF_HORIZONTAL_VIEW)
    {
        mmi_em_profiling_entry_imgdec_fulldisp_scr();
    }
    else
    {
        mmi_em_profiling_entry_imgdec_gendisp_scr();        
    }
} 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_draw_style_text
 * DESCRIPTION
 *  draw text
 * PARAMETERS
 *  str            [IN]        string pointer
 *  offset_x       [IN]        offset x
 *  offset_y       [IN]        offset y
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_profiling_draw_style_text(PS8 str, S32 offset_x, S32 offset_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    gui_move_text_cursor(offset_x, offset_y);
    gui_set_text_color(gui_color(0, 0, 0));
    gui_print_text((UI_string_type) str);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_stop_imgdec_decoding
 * DESCRIPTION
 *  stop decoding
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_profiling_stop_imgdec_decoding(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteUptoScrID(SCR_ID_EM_PROFILING_MULTIMEDIA);
    GoBackHistory();    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_draw_rsk
 * DESCRIPTION
 *  draw right soft key
 * PARAMETERS
 *  rsk_str         [IN]        Rsk string
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_profiling_draw_rsk(PS8 rsk_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_width;
    S32 str_height;
    S32 offset_x = 0;
    S32 offset_y = 0;
    S32 spacing;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if has softkey need update */
    if (rsk_str == NULL)
    {
        return;
    }
    
    wgui_softkey_get_offset((UI_string_type) rsk_str, &offset_x, &offset_y, MMI_RIGHT_SOFTKEY);
    gui_measure_string((UI_string_type) rsk_str, &str_width, &str_height);        
    if (mmi_em_prof_cntx.imgdec_is_horz_view_set == MMI_EM_PROF_HORIZONTAL_VIEW)
    {
        spacing = (MMI_SOFTKEY_HEIGHT - str_height) >> 1;
        offset_x = UI_device_height - str_width - spacing;
        offset_y = spacing;
    }
    gui_move_text_cursor(offset_x, offset_y);
    gui_set_text_color(gui_color(0, 0, 0));

    gui_set_text_border_color(gui_color(255, 255, 255));
    gui_print_bordered_text((UI_string_type) rsk_str);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_profiling_get_imgtype_string
 * DESCRIPTION
 *  get image type string
 * PARAMETERS
 *  img_type    [IN]        image type enum
 *  str         [OUT]       image type Ansii string
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_profiling_get_imgtype_string(U16 img_type, PS8 str)
{
    if(img_type == GDI_IMAGE_TYPE_JPG_FILE)
    {
        sprintf(str, ",\tJPG");
    }
    else if(img_type == GDI_IMAGE_TYPE_BMP_FILE)
    {
        sprintf(str, ",\tBMP");
    }        
    else if(img_type == GDI_IMAGE_TYPE_PNG_FILE)
    {
        sprintf(str, ",\tPNG");
    }        
    else if(img_type == GDI_IMAGE_TYPE_GIF_FILE)
    {
        sprintf(str, ",\tGIF");
    }    
    else if(img_type == GDI_IMAGE_TYPE_WBMP_FILE)
    {
        sprintf(str, ",\tWBMP");
    }       
    else if(img_type == GDI_IMAGE_TYPE_SVG_FILE)
    {
        sprintf(str, ",\tSVG");
    }     
    else if(img_type == GDI_IMAGE_TYPE_M3D_FILE)
    {
        sprintf(str, ",\tM3D");
    }     
    else
    {
        sprintf(str, ",\t   ");            
    }    
}
#endif /* defined(__MMI_IMG_DEC_PROFILING__) */

#endif /* __MMI_ENGINEER_MODE__ */ 
