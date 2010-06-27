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
 *  mdi_tv.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  TV related interface header file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef MDI_TV_H
#define MDI_TV_H

#ifdef __MMI_TVOUT__

#if defined(MT6228) || defined(MT6229) || defined(MT6230)
#define MDI_TVOUT_MT6228_SERIES
#endif

/***************************************************************************** 
* Include
*****************************************************************************/
#include "tv_out.h"

/***************************************************************************** 
* Define
*****************************************************************************/
/* return result */
#define MDI_RES_TV_DISABLE             5002
#define MDI_RES_TV_ENABLE              5001
#define MDI_RES_TV_SUCCEED             0
#define MDI_RES_TV_NOT_READY           -5001
#define MDI_RES_TV_FAILED              -5002
#define MDI_RES_TV_NOT_OWNER           -5003
#define MDI_RES_TV_ALREADY_STOPPED     -5004

/* buffer depth */
#define MDI_TV_BUFFER_DEPTH            2

/* TV-Out mode. */
typedef enum
{
    MDI_TV_MODE_NONE,                   /* Inital mode */
    MDI_TV_MODE_LCD_SCR,                /* TV-Out have same output as LCD screen */
    MDI_TV_MODE_OWNER_DRAW,             /* User can set buffer width and height  */
    MDI_TV_MODE_MULTIMEDIA_HOR_LCD_SCR, /* TV-Out have same output as Horizontal LCD screen for multimedia */
    MDI_TV_MODE_MULTIMEDIA_FULL_SCR     /* Camera preview, video preview and video playback */
} mdi_tv_mode_enum;

/* TV-Out owner, who is responsible for drawing to TV. */
typedef enum
{
    MDI_TV_OWNER_GDI,       /* Owner is GDI. GDI's blt function will also draw to TV */
    MDI_TV_OWNER_CAMERA,    /* Owner is camera. Camera drvier will draw to TV. */
    MDI_TV_OWNER_VIDEO,     /* Owner is video. Video drvier will draw to TV. */
    MDI_TV_OWNER_APP    /* Owner is App. App has to call mdi_tvout_blt to draw to TV. 
                           This is used in ower draw mode. */
} mdi_tv_owner_enum;

/* TV-Out output format. */
typedef enum
{
    MDI_TV_OUTPUT_FORMAT_PAL,   /* PAL */
    MDI_TV_OUTPUT_FORMAT_NTSC,  /* NTSC */
    MDI_TV_OUTPUT_FORMAT_PALM,  /* PALM */
    MDI_TV_OUTPUT_FORMAT_PALC   /* PALC */
} mdi_tv_format_enum;

/* TV-Out Gamma value. */
typedef enum
{
    MDI_TV_OUTPUT_GAMMA_1,  /* Gamma 1 */
    MDI_TV_OUTPUT_GAMMA_2,  /* Gamma 2 */
    MDI_TV_OUTPUT_GAMMA_3,  /* Gamma 3 (Default) */
    MDI_TV_OUTPUT_GAMMA_4,  /* Gamma 4 */
    MDI_TV_OUTPUT_GAMMA_5   /* Gamma 5 */
} mdi_tv_gamma_enum;

/* TV-Out Gamma value. */
typedef enum {
    MDI_TV_AUD_PATH_BOTH,       /* Both audio path (TV, Phone)*/
    MDI_TV_AUD_PATH_TV          /* TV audio path only */  
} mdi_tv_aud_path_enum;

typedef void (*mdi_tv_event_callback) (MDI_RESULT);

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/* MDI_TV context */
typedef struct
{
    mdi_tv_format_enum format;  /* format */
    mdi_tv_mode_enum mode;      /* mode */
    mdi_tv_owner_enum owner;    /* owner */

    /* double buf */
    U8 act_buf_id;          /* buf id that can be used by MMI */
    PU8 buf_1_ptr;          /* buffer 1's pointer */
    PU8 buf_2_ptr;          /* buffer 2's pointer */
    PU8 rotate_buf_1_ptr;   /* rotate buffer 1's pointer - for Mode 4 */
    PU8 rotate_buf_2_ptr;   /* rotate buffer 2's pointer - for Mode 4 */
    S32 buf_width;          /* TV-Out buffer width */
    S32 buf_height;         /* TV-Out buffer height */
    S32 buf_size;           /* TV-Out buffer size (byte) */
    S32 best_buf_width;     /* Buffer width that Fit PAL/NTSC size define in driver */
    S32 best_buf_height;    /* Buffer height that Fit PAL/NTSC size define in driver */

    BOOL is_enable; /* is tvout enable */
    BOOL is_init;   /* is tvout context init */
    BOOL force_disable_vertical_filter;

    gdi_handle layer_1; /* buffer 1's layer handle */
    gdi_handle layer_2; /* buffer 2's layer handle */

    mdi_tv_event_callback event_callback;   /* TV-Out event callback function */

} mdi_tv_cntx_struct;

/*****************************************************************************              
* Extern Global Variable                                                                    
*****************************************************************************/

/*****************************************************************************              
* Extern Global Function                                                                    
*****************************************************************************/

extern MDI_RESULT mdi_tvout_init(mdi_tv_event_callback tv_event_callback);

extern MDI_RESULT mdi_tvout_set_mode(mdi_tv_mode_enum mode, S32 owner_draw_width, S32 owner_draw_height);

extern MDI_RESULT mdi_tvout_start(void);
extern MDI_RESULT mdi_tvout_stop(void);
extern MDI_RESULT mdi_tvout_sleep_in(void);
extern MDI_RESULT mdi_tvout_sleep_out(void);
extern MDI_RESULT mdi_tvout_force_disable_vertical_filter(void);
extern MDI_RESULT mdi_tvout_get_para(
                    mdi_tv_owner_enum owner,
                    U16 *mode_ptr,
                    U16 *buf_width_ptr,
                    U16 *buf_height_ptr,
                    U32 *buf_size_ptr,
                    U8 **buf_1_pp,
                    U8 **buf_2_pp,
                    U8 **rotate_buf_1_pp,
                    U8 **rotate_buf_2_pp);

extern MDI_RESULT mdi_tvout_blt(void);
extern MDI_RESULT mdi_tvout_set_format(mdi_tv_format_enum format);
extern MDI_RESULT mdi_tvout_set_owner(mdi_tv_owner_enum owner);

extern mdi_tv_owner_enum mdi_tvout_get_owner(void);

extern MMI_BOOL mdi_tvout_is_enable(void);
extern GDI_HANDLE mdi_tvout_get_active_layer(void);
extern GDI_HANDLE mdi_tvout_get_and_dupe_active_layer(void);
extern MDI_RESULT mdi_tvout_resize_buffer(S32 buffer_width, S32 buffer_height);
extern MDI_RESULT mdi_tvout_adjust_y_gamma(mdi_tv_gamma_enum y_gamma);
extern MDI_RESULT mdi_tvout_adjust_u(U16 u);
extern MDI_RESULT mdi_tvout_adjust_v(U16 v);
extern MDI_RESULT mdi_tvout_set_aud_path(mdi_tv_aud_path_enum aud_path);
extern MDI_RESULT mdi_tvout_get_owner_draw_best_size(S32 *buf_width, S32 *buf_height);

/* this function is for enginner mode only, for those dont have hw detection */
extern MDI_RESULT mdi_tvout_force_init(void);

/* these functions are for engineer mode - to pause/resume before and after tv-out testing */
extern MDI_RESULT mdi_tvout_pause_for_em_mode(void);
extern MDI_RESULT mdi_tvout_resume_for_em_mode(void);

/* special function for power on procedure */
extern MDI_RESULT mdi_tvout_early_init_before_pwoeron(mdi_tv_event_callback tv_event_callback);

#endif /* __MMI_TVOUT__ */ 
#endif /* MDI_TV_H */ 

