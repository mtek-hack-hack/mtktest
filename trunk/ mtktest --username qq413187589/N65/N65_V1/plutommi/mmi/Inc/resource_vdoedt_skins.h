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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _VIDEOEDT_SKIN_H_
#define _VIDEOEDT_SKIN_H_

#include "MMI_features.h"
#if defined(__MMI_VIDEO_EDITOR__)
#include "resource_video_skins.h"


/***************************************************************************** 
* Define
*****************************************************************************/


/***************************************************************************** 
* Struct
*****************************************************************************/
typedef struct
{
    BOOL is_show;
    S32  offset_x;
    S32  offset_y;
} vdoedt_icon_struct;

typedef struct
{
    S32 offset_x;
    S32 offset_y;
    S32 width;
    S32 height;
} vdoedt_rect_struct, vdoedt_osd_play_wnd_struct;

typedef struct
{
    S32 offset_x;
    S32 offset_y;
} vdoedt_pos_struct;

/*
typedef struct {
	vdoedt_rect_struct rect;
} vdoedt_osd_play_wnd_struct;
*/

typedef struct
{
    BOOL is_show;
    S32 x;
    S32 y;
    S32 w;
    S32 h;
}vdoedt_movable_icon_struct;

typedef struct{
    vdoedt_rect_struct bg;
    vdoedt_rect_struct fill;
    vdoedt_rect_struct progress;
//    vdoedt_icon_struct out;
    vdoedt_movable_icon_struct out;
    vdoedt_icon_struct out_icon;
    vdoedt_icon_struct out_lak;
    vdoedt_icon_struct out_rak;
//    vdoedt_icon_struct in;
    vdoedt_movable_icon_struct in;
    vdoedt_icon_struct in_icon;
    vdoedt_icon_struct in_lak;
    vdoedt_icon_struct in_rak;
} vdoedt_osd_cutbar_layout_struct;

typedef struct{
    vdoedt_rect_struct    empty;
    vdoedt_rect_struct    full;
    vdoedt_icon_struct   seek_forward;
    vdoedt_icon_struct   seek_rewind;    
} vdoedt_osd_progress_layout_struct;

typedef struct{
    vdoedt_icon_struct h1;
    vdoedt_icon_struct h2;
    vdoedt_icon_struct c1;
    vdoedt_icon_struct m1;
    vdoedt_icon_struct m2;
    vdoedt_icon_struct c2;
    vdoedt_icon_struct s1;
    vdoedt_icon_struct s2;
} vdoedt_osd_time_layout_struct;

typedef struct{
    vdoedt_icon_struct   audio;
    vdoedt_icon_struct   have_frame;
    vdoedt_icon_struct   in_effect;
    vdoedt_icon_struct   out_effect;    
} vdoedt_osd_status_layout_struct;

typedef struct{
    vdoedt_rect_struct bg;
    vdoedt_rect_struct fill;
    vdoedt_rect_struct shot[5];
} vdoedt_osd_editbar_layout_struct;

typedef struct{
    vdoedt_pos_struct                bg;
    vdoedt_osd_play_wnd_struct       play_wnd;
    vdoedt_osd_cutbar_layout_struct cutbar;
    video_osd_softkey_struct        softkey;
} vdoedt_osd_cut_layout_struct;

typedef struct{
    vdoedt_pos_struct                bg;
    vdoedt_osd_play_wnd_struct       play;
    vdoedt_icon_struct               prev;
    vdoedt_icon_struct               next;
    video_osd_softkey_struct        softkey;
} vdoedt_osd_frm_sel_layout_struct;

typedef struct{
    vdoedt_pos_struct                bg;
    vdoedt_osd_play_wnd_struct       play_wnd;
    video_osd_softkey_struct        softkey;
    vdoedt_osd_progress_layout_struct progress;
    vdoedt_osd_status_layout_struct status;
    vdoedt_osd_editbar_layout_struct editbar;
    vdoedt_osd_time_layout_struct    time;
} vdoedt_osd_main_wnd_layout_sturct;

/***************************************************************************** 
* Local Variable
*****************************************************************************/
extern vdoedt_osd_main_wnd_layout_sturct    g_vdoedt_main_osd_cntx;
extern vdoedt_osd_cut_layout_struct         g_vdoedt_cut_osd_cntx;
extern vdoedt_osd_frm_sel_layout_struct     g_vdoedt_frm_sel_osd_cntx;


#endif /* __MMI_VIDEO_EDITOR_ */
#endif /* _VIDEOEDT_SKIN_H_ */


