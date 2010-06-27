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
 *	 resource_video_skins.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Video App customization file.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _VIDEO_SKIN_H_
#define _VIDEO_SKIN_H_

#include "MMI_features.h"
#if defined(__MMI_VIDEO_PLAYER__) || defined(__MMI_VIDEO_RECORDER__)



/***************************************************************************** 
* Define
*****************************************************************************/
typedef enum {
	VIDEO_TEXT_STYLE_NORMAL,
	VIDEO_TEXT_STYLE_BORDER,
	VIDEO_TEXT_STYLE_SHADOW	
} mmi_video_text_style;

typedef enum {
	VIDEO_ALIGN_LEFT,
	VIDEO_ALIGN_RIGHT,
	VIDEO_ALIGN_TOP,
	VIDEO_ALIGN_BOTTOM,	
	VIDEO_ALIGN_CENTER
} mmi_video_align_style;
	

/***************************************************************************** 
* Struct
*****************************************************************************/
typedef struct
{
	BOOL is_show;
	S32  offset_x;
	S32	 offset_y;
} video_icon_struct;

typedef struct
{
	S32 offset_x;
	S32	offset_y;
	S32	width;
	S32 height;
} video_rect_struct;

typedef struct
{
	S32	offset_x;
	S32 offset_y;
} video_pos_struct;


typedef struct {
	U8	r;
	U8	g;	
	U8	b;		
	U8	style_r;
	U8	style_g;	
	U8	style_b;
	U16	style;	
} video_style_text_struct;


typedef struct {	
	BOOL is_show;
	S32  offset_x;
	S32	 offset_y;
	video_style_text_struct style_text;
} video_osd_storage_struct;


typedef struct {
	U16	 h_align;
	U16	 v_align;
	BOOL is_draw_app_name;
	BOOL is_draw_filename;
	video_rect_struct 		rect;	
	video_style_text_struct	style_text;
} video_osd_title_struct;


typedef struct {
	video_rect_struct rect;
} video_osd_play_wnd_struct;

typedef struct {
	video_rect_struct region_0;
	video_rect_struct region_1;	
} video_osd_bg_struct;

typedef struct {
	video_rect_struct   rect;
	video_pos_struct    bg;
	BOOL                is_draw_progress;
	video_pos_struct    progress;
} video_osd_loading_struct;

typedef struct {
	video_pos_struct	speed;
	video_pos_struct	speed_inc;
	video_pos_struct	speed_dec;	
	video_pos_struct	volume;
	video_pos_struct	volume_inc;
	video_pos_struct	volume_dec;	
	video_pos_struct	timer;
	video_pos_struct	timer_bg;            
	video_pos_struct	progress_fill;
	video_pos_struct	progress_empty;	
	video_pos_struct	progress_inc;
	video_pos_struct	progress_dec;
	video_pos_struct	snapshot;
	video_pos_struct	fullscreen;	
} video_osd_vodply_panel_struct;

typedef struct {
	video_pos_struct	bg;
	video_pos_struct	speed;
	video_pos_struct	speed_inc;
	video_pos_struct	speed_dec;		
	video_pos_struct	volume;
	video_pos_struct	volume_inc;
	video_pos_struct	volume_dec;		
	video_pos_struct	timer;
	video_pos_struct	timer_bg;        
	video_pos_struct	progress_fill;
	video_pos_struct	progress_empty;
	video_pos_struct	progress_inc;
	video_pos_struct	progress_dec;	
} video_osd_vodply_full_panel_struct;


typedef struct {
	video_pos_struct	ev;
	video_pos_struct	ev_inc;
	video_pos_struct	ev_dec;	
	video_pos_struct	zoom;
	video_pos_struct	zoom_inc;
	video_pos_struct	zoom_dec;		
	video_pos_struct	timer;
	video_pos_struct	timer_bg;      
	video_pos_struct	state;	
} video_osd_vodrec_panel_struct;


typedef struct {
	BOOL					is_lsk_icon;
	BOOL					is_rsk_icon;	
	BOOL					is_ck_icon;		
	video_pos_struct		icon_lsk_pos;
	video_pos_struct		icon_rsk_pos;	
	video_pos_struct		icon_ck_pos;			
	video_rect_struct		rect;
 	video_style_text_struct	lsk_text;
	video_style_text_struct	rsk_text;
} video_osd_softkey_struct;

typedef struct {
	BOOL					is_lsk_icon;
	BOOL					is_rsk_icon;	
	BOOL					is_ck_icon;		
	video_pos_struct		icon_lsk_pos;
	video_pos_struct		icon_rsk_pos;	
	video_pos_struct		icon_ck_pos;		
 	video_style_text_struct	lsk_text;
	video_style_text_struct	rsk_text;
} video_osd_full_softkey_struct;


typedef struct {
	BOOL					is_show;
	video_rect_struct		rect;
 	video_style_text_struct	style_text;
} video_osd_hint_struct;

typedef struct {
	BOOL				is_show;
	video_rect_struct 	rect;
	video_icon_struct	night;
	video_icon_struct	led_highlight;
	video_icon_struct	record_aud;	
	video_icon_struct	size_limit;
	video_icon_struct 	time_limit;
} video_osd_vdorec_status_struct;


	

typedef struct {
    video_osd_bg_struct             bg;
	video_osd_title_struct			title;
	video_osd_play_wnd_struct		preview_wnd;
	video_osd_vodrec_panel_struct	panel;
	video_osd_vdorec_status_struct	status;	
	video_osd_softkey_struct 		softkey;
	video_osd_hint_struct			hint;
} vdorec_osd_vdorec_layout_struct;


typedef struct {
    video_osd_bg_struct             bg;
	video_osd_title_struct			title;
	video_osd_play_wnd_struct		play_wnd;
	video_osd_vodply_panel_struct	panel;
	video_osd_softkey_struct 		softkey;
	video_osd_loading_struct        loading;
} vdoply_osd_vdoply_layout_struct;



typedef struct {
	video_osd_vodply_full_panel_struct	panel;	
	video_osd_full_softkey_struct		softkey;
	video_osd_loading_struct            loading;
} vdoply_osd_fullscr_layout_struct;

/***************************************************************************** 
* Local Variable
*****************************************************************************/
/* video osd display cntx */
extern vdoply_osd_vdoply_layout_struct g_vdoply_osd_cntx;

#ifdef __VDOPLY_FEATURE_FULLSCREEN__
extern vdoply_osd_fullscr_layout_struct g_vdoply_fullscr_osd_cntx;
#endif

extern vdorec_osd_vdorec_layout_struct g_vdorec_osd_cntx;

/* hongzhe.liu add start */
#ifdef ANALOG_TV_SUPPORT
extern vdoply_osd_vdoply_layout_struct g_analog_tv_osd_cntx;
extern vdorec_osd_vdorec_layout_struct g_vdorec_osd_cntx02;
#endif
/* hongzhe.liu add end */

#endif /* __MMI_VIDEO_PLAYER__ || __MMI_VIDEO_RECORDER__ */
#endif /* _VIDEO_SKIN_H_ */


