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
 *	 resource_camera_skins.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Camera customization file.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _CAMERA_SKIN_H_
#define _CAMERA_SKIN_H_

#include "MMI_features.h"
#include "MMI_features_camera.h"
#ifdef __MMI_CAMERA__


/***************************************************************************** 
* Define
*****************************************************************************/
#if defined(__MMI_CAMERA_HIGH_END__)
	/* for MT6228 / MT6229, use wav, which have better qty */
	#define CAMERA_SOUND_SHUTTER_1_LEN	(4798)
	#define CAMERA_SOUND_SHUTTER_2_LEN	(3532)
	#define CAMERA_SOUND_SHUTTER_3_LEN	(6960)
	#define CAMERA_SOUND_DUMMY_BG_LEN	(94)
	#define CAMERA_SOUND_AF_SUCCEED_LEN (3695)
#else
	#define CAMERA_SOUND_SHUTTER_1_LEN	(1199)
	#define CAMERA_SOUND_SHUTTER_2_LEN	(883)
	#define CAMERA_SOUND_SHUTTER_3_LEN	(1740)
	#define CAMERA_SOUND_DUMMY_BG_LEN	(94)	
#endif 

#if defined(ISP_SUPPORT) 
#define CAMREA_SOUND_COUNTDOWN_LEN	(1374)
#else
#define CAMREA_SOUND_COUNTDOWN_LEN	(164)
#endif

typedef enum {
	CAMERA_TEXT_STYLE_NORMAL,
	CAMERA_TEXT_STYLE_BORDER,
	CAMERA_TEXT_STYLE_SHADOW	
} mmi_camera_text_style;


/***************************************************************************** 
* Struct
*****************************************************************************/
typedef struct
{
	BOOL 	is_show;
	S32	offset_x;
	S32	offset_y;
	U8		group_id;
} camera_osd_icon_struct;

typedef struct
{
	U8 r;
	U8 g;
	U8 b;
} camera_color_struct;

typedef struct {
	U8		r;
	U8		g;	
	U8		b;		
	U8		style_r;
	U8		style_g;	
	U8		style_b;
	U16	style;	
} camera_style_text_struct;

typedef struct
{
	S32 	offset_x;
	S32	offset_y;
	S32	width;
	S32 	height;
} camera_osd_panel_struct;

typedef struct
{
	BOOL	is_draw_mmi_softkey;
	camera_style_text_struct	lsk;
	camera_style_text_struct	rsk;
} camera_osd_softkey_struct;

typedef struct
{
	S32 	offset_x;
	S32	offset_y;
	S32	width;
	S32 	height;
} camera_preview_wnd_struct;


typedef struct
{
	BOOL	is_show;
	S32 	offset_x;
	S32	offset_y;
	S32	width;
	S32 	height;
	camera_style_text_struct style_text;
} camera_osd_hint_box_struct;


typedef struct 
{	
	BOOL 	is_show;
	BOOL	is_right_align;	
	S32 	offset_x;
	S32	    offset_y;
	camera_style_text_struct style_text;
   	U8		group_id;
} camera_osd_storage_struct;

typedef struct 
{	
	BOOL 	is_draw_bg_image;
	BOOL	is_draw_bg_color;
	U8		r;
	U8		g;	
	U8		b;	
} camera_osd_bg_struct;

typedef struct 
{	
	BOOL 	is_draw_mmi_title_bar;
	BOOL	is_draw_mmi_caption;
} camera_osd_title_struct;

typedef struct
{
	S32	offset_x;
	S32	offset_y;
	S32	icon_per_page;
} camera_osd_iconbar_struct;
typedef struct{
	S32 offset_x;
	S32 offset_y;
	S32 width;
	S32 height;
} camera_osd_region_struct;
	

typedef struct {

	/* background */
	camera_osd_bg_struct				bg;

	/* title */
	camera_osd_title_struct			title;

	/* softkey (buttom bar) */
	camera_osd_softkey_struct		softkey;
	
	/* preview wnd */
	camera_preview_wnd_struct		preview_wnd;
	
	/* camera setting */
	camera_osd_icon_struct 			wb;
	camera_osd_icon_struct 			flash;
	camera_osd_icon_struct 			led_highlight;	
	camera_osd_icon_struct 			ev;		
	camera_osd_icon_struct 			ev_inc;		/* for touch screen */
	camera_osd_icon_struct 			ev_dec;		/* for touch screen */
	camera_osd_icon_struct			night;
	camera_osd_icon_struct			closeup;
	
	/* image setting  */ 
	camera_osd_icon_struct			image_size;
	camera_osd_icon_struct			image_qty;
	
	/* others */
	camera_osd_icon_struct			cont_shot;
	camera_osd_icon_struct			delay_timer;
	camera_osd_icon_struct			add_frame;	
	camera_osd_icon_struct			storage;
	camera_osd_icon_struct			effect;
	camera_osd_icon_struct			ae_meter;	
	camera_osd_icon_struct			iso;	
	camera_osd_icon_struct			dsc_mode ;
	camera_osd_icon_struct			af_mode;
	camera_osd_icon_struct			af_meter;
	camera_osd_icon_struct			zoom_mf_toggle;
	camera_osd_icon_struct			capture;	
	camera_osd_icon_struct			zoom;	
	camera_osd_icon_struct 			zoom_inc;		/* for touch screen */
	camera_osd_icon_struct 			zoom_dec;		/* for touch screen */

	camera_osd_icon_struct			mms_icon;
	camera_osd_icon_struct			left_arrow;
	camera_osd_icon_struct			right_arrow;
	camera_osd_icon_struct			flash_charge_status;

	/* icon list */
	camera_osd_iconbar_struct		iconbar;
#if defined(__MMI_CAMERA_5_OSD_LAYER__)
	camera_osd_region_struct		osd_region0;
	camera_osd_region_struct		osd_region1;
	camera_osd_region_struct		osd_region2;
	camera_osd_region_struct		osd_region3;
	camera_osd_region_struct		osd_region4;
#elif defined(__MMI_CAMERA_3_OSD_LAYER__)
	camera_osd_region_struct		osd_region0;
	camera_osd_region_struct		osd_region1;
	camera_osd_region_struct		osd_region2;
#endif
	
	camera_osd_hint_box_struct		hint_box;
	camera_osd_storage_struct		remain_storage;

} camera_osd_layeout_struct;


typedef struct {
	camera_style_text_struct	poplist_title_text;
	camera_style_text_struct	poplist_list_text;
	camera_style_text_struct	poplist_list_highlight_text;

	camera_color_struct			poplist_bg_color;
	camera_color_struct			poplist_highlight_color;
	
	U16								poplist_bg_trans;
	
	S32								poplist_top_margin;
	S32								poplist_bottom_margin;	
	S32								poplist_left_margin;
	S32								poplist_right_margin;
} camera_osd_menu_struct;


/***************************************************************************** 
* Local Variable
*****************************************************************************/
/* camera osd display cntx */
extern camera_osd_layeout_struct g_camera_osd_cntx;

#ifdef __CAMERA_OSD_HORIZONTAL__	
extern camera_osd_layeout_struct g_camera_osd_cntx_270;
#endif


extern camera_osd_menu_struct		g_camera_osd_menu_cntx;

/* camera sound */
#ifndef WIN32
	extern __align(2) const U8 camera_sound_countdown[CAMREA_SOUND_COUNTDOWN_LEN];
	extern __align(2) const U8 camera_sound_shutter_1[CAMERA_SOUND_SHUTTER_1_LEN];
	extern __align(2) const U8 camera_sound_shutter_2[CAMERA_SOUND_SHUTTER_2_LEN];
	extern __align(2) const U8 camera_sound_shutter_3[CAMERA_SOUND_SHUTTER_3_LEN];
	extern __align(2) const U8 camera_sound_dummy_bg[CAMERA_SOUND_DUMMY_BG_LEN];
#if defined(__MMI_CAMERA_HIGH_END__)
	extern __align(2) const U8 camera_af_succeed[CAMERA_SOUND_AF_SUCCEED_LEN];
#endif
#else
	extern const U8 camera_sound_countdown[CAMREA_SOUND_COUNTDOWN_LEN];
	extern const U8 camera_sound_shutter_1[CAMERA_SOUND_SHUTTER_1_LEN];
	extern const U8 camera_sound_shutter_2[CAMERA_SOUND_SHUTTER_2_LEN];
	extern const U8 camera_sound_shutter_3[CAMERA_SOUND_SHUTTER_3_LEN];
	extern const U8 camera_sound_dummy_bg[CAMERA_SOUND_DUMMY_BG_LEN];	
#if defined(__MMI_CAMERA_HIGH_END__)
	extern const U8 camera_af_succeed[CAMERA_SOUND_AF_SUCCEED_LEN];
#endif
#endif 







#endif /* __MMI_CAMERA__ */
#endif /* _CAMERA_SKIN_H_ */


