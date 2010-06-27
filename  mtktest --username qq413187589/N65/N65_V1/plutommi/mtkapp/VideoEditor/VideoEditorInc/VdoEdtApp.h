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
 *   VdoEdtApp.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Expose function and variable.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef __VDOEDTAPP_H__
#define __VDOEDTAPP_H__


#include "MMI_features.h"
#ifdef __MMI_VIDEO_EDITOR__

/***************************************************************************** 
* Define
*****************************************************************************/
#if 0
/* under construction !*/
/* under construction !*/
#ifdef __MMI_VDOEDT_CUSTOM_AUD__
/* under construction !*/
#endif /* __MMI_VDOEDT_CUSTOM_AUD__ */
#endif
#define MMI_VDOEDT_VDO_WIDTH            (176)
#define MMI_VDOEDT_VDO_HEIGHT           (144)

#define MMI_VDOEDT_MAX_CLIP_NUM         (5)
#define MMI_VDOEDT_BAR_HILIGHT_COLOR    GDI_COLOR_RED
#define MMI_VDOEDT_PREV_BUF_SIZE        (51200)               /* 50K */
#define MMI_VDOEDT_KEY_TRIG_DELAY       (300)                 /* key trigger delay*/
#define MMI_VDOEDT_SHOT_UPDATE_INTERVAL (50)                 /* shot updater timer interval while playing */
#define MMI_VDOEDT_FRAME_STY_CNT        (IMG_ID_VDOEDT_VIEWER - IMG_ID_VDOEDT_FRAME1)
#define MMI_VDOEDT_PWIN_BORDER          (2)                   /* the border for drawing txt */
#define MMI_VDOEDT_TMP_SETTING_NUM      (4)

#define MMI_VDOEDT_EFFECT_MAX           (255)
#define MMI_VDOEDT_EFFECT_MIN           (0)
#define MMI_VDOEDT_EFFECT_LVL           (5)
#define MMI_VDOEDT_EFFECT_INTERVAL      (200)                 /* transition effect apply interval, shouldn't be smaller than 200 ms*/

/* minium cutable length */
#define MMI_VDOEDT_MIN_CUTABLE_LEN      (MMI_VDOEDT_EFFECT_LVL * MMI_VDOEDT_EFFECT_INTERVAL * 2)
#define MMI_VDOEDT_IMG_DUR_DEFAULT      (5)                   /* 5 sec */

#define MMI_VDOEDT_INS_VDO_MAX_DUR      (1800000)           /* max insertable vdo */
#define MMI_VDOEDT_INS_VDO_MIN_DUR      (MMI_VDOEDT_MIN_CUTABLE_LEN - 200)

#define MMI_VDOEDT_CACHE_SPACE          (MMI_VDOEDT_PREV_BUF_SIZE*5)

#define MMI_VDOEDT_BYTE_PER_SEC         (30960)                /* estimation, 30k*/

#define MMI_VDOEDT_TMP_PATH_BUF_SIZE    (64)
#define MMI_VDOEDT_TMP_PATH             L"Vetmp\\"
#define MMI_VDOEDT_TMP_FNAME            L"Shot"
#define MMI_VDOEDT_MAX_SNAME_MAX_LEN    FMGR_MAX_FILE_LEN + 9      /* 9 = "x:\Video\" */

#define MMI_VDOEDT_DEFAULT_AUIDO_VOL    (3)

#define MMI_VDOEDT_CACHE_FNAME_SIZE     (10 * ENCODING_LENGTH)
#define MMI_VDOEDT_FRM_TXT_SIZE         (20 * ENCODING_LENGTH)

/* encode */
#define MMI_VDOEDT_ENCODE_DELAY         (100)               /* 100ms */
#define MMI_VDOEDT_MAX_SLICE_LEN        (3000)              /* 3 sec */
#define MMI_VDOEDT_MIN_APPEND_LEN       (50)               /* if the slice left is < 50 ms, drop it. */

#define MMI_VDOEDT_ENC_RES_POPUP_DELAY  (500)               /* 500 ms */
#define MMI_VDOEDT_ENC_MERGE_DELAY      (1000)              /* the delay of final merge, 1 sec */

#define MMI_VDOEDT_MAX_C4M_STRLEN       (9)                /* max text num in addframe text */
#define MMI_VDOEDT_SAVENAME_PREFIX      "VIDEO"
/***********************************************************************/
/* drawing flags                                                       */
/***********************************************************************/
/* main screen redraw flags */
#define MMI_VDOEDT_R4W_NONE         0x00
#define MMI_VDOEDT_R4W_BG           0x01                    /* R4W == REDRAW*/
#define MMI_VDOEDT_R4W_TIME         0x02                   
#define MMI_VDOEDT_R4W_PBAR         0x04                    /* progress bar */
#define MMI_VDOEDT_R4W_EBAR         0x08                    /* edit bar bg and hilight    */
#define MMI_VDOEDT_R4W_PWIN         0x10                    /* preview win  */
#define MMI_VDOEDT_R4W_SKEY         0x20                    /* soft key     */
#define MMI_VDOEDT_R4W_STAT         0x40                    /* status icons */
#define MMI_VDOEDT_R4W_KEYFRMS      0x80                    /* keyframes on editbar*/
#define MMI_VDOEDT_R4W_ALL          0xFF                    /* all          */
/* cut/frame screen redraw flags */
#define MMI_VDOEDT_R4W_OUT_BTN      0x40                    /* cut out button */
#define MMI_VDOEDT_R4W_IN_BTN       0x80                    /* cut in button  */
/* frame sel redraw flag */
#define MMI_VDOEDT_R4W_FRAME        0x40                    /* frame */
#define MMI_VDOEDT_R4W_FRM_SEL_BTN  0x80                    /* frame sel button */

/* layer creation flag */
//#define MMI_VDOEDT_LAYER_NONE       0x00
#define MMI_VDOEDT_LAYER_OSD        0x01
#define MMI_VDOEDT_LAYER_PLAY       0x02
#define MMI_VDOEDT_LAYER_FRM        0x04
#define MMI_VDOEDT_LAYER_EFFECT     0x08
#define MMI_VDOEDT_LAYER_KEYFRM     0x10
#define MMI_VDOEDT_LAYER_ALL        0xFF



/***************************************************************************** 
* Typedef 
*****************************************************************************/
/********************************************** 
* Enums
***********************************************/
typedef enum
{
    MMI_VDOEDT_POP_ERR,
    MMI_VDOEDT_POP_WARNING,
    MMI_VDOEDT_POP_SUCCESS,
    MMI_VDOEDT_POP_INFO,

    MMI_VDOEDT_POP_TOTAL
}mmi_vdoedt_pop_type_enum;

typedef enum
{
    MMI_VDOEDT_S_EXIT = 0,
    MMI_VDOEDT_S_RESTORE,        
    MMI_VDOEDT_S_EMPTY,
    MMI_VDOEDT_S_EDIT,                   /* edit state */
    MMI_VDOEDT_S_EDIT_IDLE,
    MMI_VDOEDT_S_EDIT_FRAME,             /* in frame edit screen */
    MMI_VDOEDT_S_EDIT_FRAME_SEL,
    MMI_VDOEDT_S_EDIT_FRAME_IN,
    MMI_VDOEDT_S_EDIT_FRAME_OUT,
    MMI_VDOEDT_S_EDIT_FRAME_TXT,
    MMI_VDOEDT_S_EDIT_CUT,               /* cut screen */
    MMI_VDOEDT_S_EDIT_CUT_IN,
    MMI_VDOEDT_S_EDIT_CUT_OUT,
    MMI_VDOEDT_S_PLAY,
    MMI_VDOEDT_S_PREVIEW_PLAY,
    MMI_VDOEDT_S_EDIT_PLAY,
    MMI_VDOEDT_S_CUT_PLAY,
    MMI_VDOEDT_S_FRM_PLAY,
    MMI_VDOEDT_S_SEEK,                   /* seek is only available in PREVIEW_PLAY/PREVIEW state */
    MMI_VDOEDT_S_SEEK_UPDATING,
    MMI_VDOEDT_S_SEEK_DONE,
    MMI_VDOEDT_S_PLAY_SEEK,
    MMI_VDOEDT_S_PLAY_SEEK_UPDATING,
    MMI_VDOEDT_S_PLAY_SEEK_DONE,
    MMI_VDOEDT_S_PREVIEW,
    MMI_VDOEDT_S_SAVING,
    MMI_VDOEDT_S_CONFIRM_SAVE
}vdoedt_state_enum;

typedef enum
{
    MMI_VDOEDT_DRIVE_NONE = 0,
    MMI_VDOEDT_PHONE,
    MMI_VDOEDT_CARD,
    MMI_VDOEDT_BOTH
}vdoedt_drive_enum;

typedef enum
{
    VDOEDT_IN_EFFECT = 0,
    VDOEDT_OUT_EFFECT,
    VDOEDT_VIDEO_EFFECT,                /* the effect during playing */
    VDOEDT_EFFECT_TYPE_COUNT
}vdoedt_effect_type_enum;

typedef enum
{
    MMI_VDOEDT_EFFECT_IN_NONE = 0,
    MMI_VDOEDT_EFFECT_IN_FROM_BLACK,
    MMI_VDOEDT_EFFECT_IN_FROM_WHITE,
    MMI_VDOEDT_EFFECT_IN_COUNT
}mmi_vdoedt_effect_in_enum;

typedef enum
{
    MMI_VDOEDT_EFFECT_OUT_NONE = 0,
    MMI_VDOEDT_EFFECT_OUT_2_BLACK,
    MMI_VDOEDT_EFFECT_OUT_2_WHITE,
    MMI_VDOEDT_EFFECT_OUT_COUNT
}mmi_vdoedt_effect_out_enum;

typedef enum
{
    VDOEDT_SRC_RESERVED = 0,
    VDOEDT_SRC_VIDEO,
    VDOEDT_SRC_IMG_FILE,                    /* img - from file  */
    VDOEDT_SRC_LAST_FRAME,                  /* img - last frame of previous video */
    VDOEDT_SRC_FIRST_FRAME,                 /* img - first frame of next video */
    VDOEDT_SRC_COLOR                        /* img - color      */
} vdoedt_shot_src_type;

typedef enum
{
    VDOEDT_OBJ_RESERVED = 0,
    VDOEDT_OBJ_LSK,
    VDOEDT_OBJ_RSK,
    VDOEDT_OBJ_CK,                          /* center key   */
    VDOEDT_OBJ_PBAR,                        /* progress bar */
    VDOEDT_OBJ_EBAR,                        /* edit bar     */
    VDOEDT_OBJ_SHOT1,
    VDOEDT_OBJ_SHOT2,
    VDOEDT_OBJ_SHOT3,
    VDOEDT_OBJ_SHOT4,
    VDOEDT_OBJ_SHOT5,    
    VDOEDT_OBJ_FFK,                          /* fast forward key */
    VDOEDT_OBJ_RWK,                          /* rewind key   */
    VDOEDT_OBJ_CBAR,                        /* cut bar in frame/cut screen */
    VDOEDT_OBJ_CUT_IN,
    VDOEDT_OBJ_CUT_OUT,    
    VDOEDT_OBJ_IN_LAK,                      /* LeftArrowKey */
    VDOEDT_OBJ_IN_RAK,                      /* RightArrowKey*/
    VDOEDT_OBJ_OUT_LAK,
    VDOEDT_OBJ_OUT_RAK,
    VDOEDT_OBJ_FRAME_NEXT,
    VDOEDT_OBJ_FRAME_PREV,

    VDOEDT_OBJ_TOTAL
} vdoedt_touch_obj_enum;

typedef enum
{
    VDOEDT_AUDIO_IDLE = 0,
    VDOEDT_AUDIO_PLY_FILE,
    VDOEDT_AUDIO_PLY_ID,
    VDOEDT_AUDIO_INVALID,
    VDOEDT_AUDIO_INTERRUPT,
    
    VDOEDT_AUDIO_TOTAL
} vdoedt_audio_ply_state;

typedef enum
{
    MMI_VDOEDT_TXT_ALIGN_TOP =0,
    MMI_VDOEDT_TXT_ALIGN_BOTTOM,
    MMI_VDOEDT_TXT_ALIGN_CENTER,
    
    MMI_VDOEDT_TXT_ALIGN_COUNT
} mmi_vdoedt_cust_text_align;


typedef enum
{
    MMI_VDOEDT_TXT_SIZE_S = 0,
    MMI_VDOEDT_TXT_SIZE_M,
    MMI_VDOEDT_TXT_SIZE_L,

    MMI_VDOEDT_TXT_SIZE_COUNT
}mmi_vdoedt_cust_text_size;


/********************************************** 
* structures 
***********************************************/
typedef struct
{
    U32 hh;
    U32 mm;
    U32 ss;
} mmi_vdoedt_time_struct;

typedef struct
{
    BOOL pressed;
#ifdef __MMI_TOUCH_SCREEN__
    S32 x;
    S32 y;
    S32 w;
    S32 h;
#endif /* __MMI_TOUCH_SCREEN__ */
} vdoedt_ui_obj_struct;

typedef struct{
    S32 event;
    vdoedt_ui_obj_struct lsk;
    vdoedt_ui_obj_struct rsk;
    vdoedt_ui_obj_struct ck;
    vdoedt_ui_obj_struct pbar;
    vdoedt_ui_obj_struct ebar;
    vdoedt_ui_obj_struct shot[MMI_VDOEDT_MAX_CLIP_NUM];
    vdoedt_ui_obj_struct ffk;
    vdoedt_ui_obj_struct rwk;
    vdoedt_ui_obj_struct in_lak;
    vdoedt_ui_obj_struct in_rak;
    vdoedt_ui_obj_struct out_lak;
    vdoedt_ui_obj_struct out_rak;
    vdoedt_ui_obj_struct frame_n;
    vdoedt_ui_obj_struct frame_pre;
    vdoedt_ui_obj_struct cbar;
    vdoedt_ui_obj_struct cut_in;
    vdoedt_ui_obj_struct cut_out;
    S32 x_cut_in;   /* for moving keys */
    S32 x_cut_out;
} vdoedt_ui_key_struct;

typedef struct
{
    BOOL used;                      /* this memeory is used or not.         */    
    mdi_handle h_video;
    color const *c_shot;

    /* cache file */
    S8 ustr_fname[MMI_VDOEDT_CACHE_FNAME_SIZE];
   
    /* duration, cut */
    U8      s_img_dur;
    U64     ms_cut_in;            /* start time in this video clip        */
    U64     ms_cut_out;           /* end time in this video clip          */

    /* source info */
    vdoedt_shot_src_type src_type;      /* the type of source file of this shot.*/
    U64 ms_vdo_src_len;                 /* source video length (original)       */    
    S32 src_w;                          /* source width and height (img/video)  */
    S32 src_h;
    
    /* frame/text */
    U16     choosed_frame;              /* the frame user choosed (not video frame) */
    U64     ms_frm_in;
    U64     ms_frm_out;
    
    S8      p_txt[MMI_VDOEDT_FRM_TXT_SIZE];   
    S32 text_align;
    S32 size_txt;

    S32 i_txt_color;

    /* effect */
    S32 in_effect;
    S32 out_effect;
    /* 137 bytes */
}vdoedt_shot_struct, *p_vdoedt_shot_struct;

typedef struct
{
    vdoedt_state_enum state;            /* current state    */
    vdoedt_state_enum old_state;        /* last state       */
    
    gdi_handle h_play;
    gdi_handle h_osd;                   /* osd layer handle             */
    gdi_handle h_keyframe;              /* layer of key frames of shot  */
    gdi_handle h_frmtxt;                /* frame/ text layer            */
    gdi_handle h_effect;                /* effect layer */
    
    PU8        p_scrmem;                /* buffer memory */

    p_vdoedt_shot_struct p_shot[MMI_VDOEDT_MAX_CLIP_NUM];
    p_vdoedt_shot_struct p_shot_mem[MMI_VDOEDT_MAX_CLIP_NUM];    
#ifndef __MMI_VDOEDT_USE_APPMEM__
    vdoedt_shot_struct shot_mem[MMI_VDOEDT_MAX_CLIP_NUM];   /* ToDo: change to AppBased Memory */   
#endif /* ndef __MMI_VDOEDT_USE_APPMEM__ */
    
    S8  i_act_shot;                     /* hilighted shot index [0,4]               */
    U8  shot_count;                     /* total shots in this edit bar now. [0,5]  */
    BOOL    audio_selected;    
#ifdef __MMI_VDOEDT_CUSTOM_AUD__
    /* audio */
    U32     ms_aud_d6n;
    // PU8  p_aud_filename;
    U8      p_aud_filename[FMGR_MAX_PATH_LEN*ENCODING_LENGTH];
    U16     default_audio_no;              /* change to enum */
    U16     audio_id_2_set;                /* the id to be set */
#endif

    U32 aud_ply_stat;
    S8 fname_buff[(MMI_VDOEDT_MAX_SNAME_MAX_LEN + 1) * ENCODING_LENGTH];
    
    /****** UI ******/
    UI_string_type pstr_in_eff[MMI_VDOEDT_EFFECT_IN_COUNT];
    UI_string_type pstr_out_eff[MMI_VDOEDT_EFFECT_OUT_COUNT];

    UI_string_type ps_txt_size[MMI_VDOEDT_TXT_SIZE_COUNT];
    UI_string_type ps_txt_align[MMI_VDOEDT_TXT_ALIGN_COUNT];

    UI_string_type ps_txt_color[2];         /* black & white */
    
    U8 flg_main_r4w;        /* main screen redraw flag      */
    U8 flg_cut_r4w;         /* cut/frame scr redraw flag    */
    U8 flg_frm_sel_r4w;      /* frame scr redraw flag */
    S32 movecount;          /* use for UI update stepping */
    S32 i_playing_shot;     /* for sequence playback        */
    U32 time_start;         /* for updating time osd, encoding        */
    U32 time_now;           /* current time position of result video (in ms) */
    U32 time_base;          /* time_base of each shot. (if shot 3 is playing, time_base = Tshot1 +Tshot2)*/
    U32 ms_t_total;         /* total duration of result video (ms)*/
    U8 percent_pbar;        /* percentage of progress */
    /* playshot */
    U32 ms_shot_start;
    BOOL frmtxt_shown;
    BOOL frmtxt_hidden;
    BOOL eff_in;
    BOOL eff_out;
    BOOL full_eff_out;
    /* encode */
    U8  n_pathstr_len;
    U32 ms_slice_start;
    U32 ms_slice_end;
    U32 ms_timeline[4];     /* frm_in/out, eff_in/out */

    /* setting */
    U8 a_volume;
    U64 t_in_old;
    U64 t_out_old;
    S32 old_value;          /* used in setting and encoding */
    U16 old_s5g[MMI_VDOEDT_TMP_SETTING_NUM];

    S8 cache_path[32];
}vdoedt_context_struct,*p_vdoedt_context_struct;


#endif /* __MMI_VIDEO_EDITOR__ */
#endif /* __VDOEDTAPP_H__ */

