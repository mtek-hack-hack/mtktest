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
 *	resource_vt_skins.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Video Telephony customization file.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef RESOURCE_VT_SKIN_H
#define RESOURCE_VT_SKIN_H

#include "MMI_features.h"
#if defined(__MMI_VIDEO_TELEPHONY__) 

/***************************************************************************** 
 * Define
 *****************************************************************************/
typedef enum {
	MMI_VTCS_TEXT_STYLE_NORMAL,
	MMI_VTCS_TEXT_STYLE_BORDER,
	MMI_VTCS_TEXT_STYLE_SHADOW	
} mmi_vtcs_text_style;


/***************************************************************************** 
 * Struct
 *****************************************************************************/
typedef struct
{
	S32 offset_x;
	S32	offset_y;
	S32	width;
	S32 height;
} mmi_vtcs_rect_struct;


typedef struct
{
	S32	offset_x;
	S32 offset_y;
} mmi_vtcs_pos_struct;


typedef struct {
	U8	r;
	U8	g;	
	U8	b;		
	U8	style_r;
	U8	style_g;	
	U8	style_b;
	mmi_vtcs_text_style style;	
} mmi_vtcs_style_text_struct;


typedef struct {
    /* title */
    mmi_vtcs_rect_struct  status_rect;    
    mmi_vtcs_rect_struct  title_rect;
    mmi_vtcs_rect_struct  body_rect; 
    
    /* video window */
    mmi_vtcs_rect_struct  main_wnd_rect; 
    mmi_vtcs_rect_struct  sub_wnd_rect; 

    /* panels */
    mmi_vtcs_rect_struct  time_panel_rect;
    mmi_vtcs_rect_struct  ctrl_panel_rect;

    /* sk */
    mmi_vtcs_rect_struct  softkey_rect;

    /* time panel */
    mmi_vtcs_pos_struct  money_icon_pos;
    mmi_vtcs_pos_struct  time_icon_pos;

    /* status panel */ 
    mmi_vtcs_pos_struct  icon_1_pos;
    mmi_vtcs_pos_struct  icon_2_pos;
    mmi_vtcs_pos_struct  icon_3_pos;    
    mmi_vtcs_pos_struct  icon_4_pos;
    mmi_vtcs_pos_struct  icon_5_pos;
    mmi_vtcs_pos_struct  icon_6_pos;    
 
    /* contol panel */
    mmi_vtcs_pos_struct  ctrl_icon_pos;      
    mmi_vtcs_pos_struct  inc_icon_pos;
    mmi_vtcs_pos_struct  dec_icon_pos;    
    mmi_vtcs_pos_struct  scroll_bar_pos;

    /* text sytle */
    mmi_vtcs_style_text_struct title_text_style;
    mmi_vtcs_style_text_struct sk_text_style;    
} mmi_vtcs_skin_struct;


/***************************************************************************** 
 * Extern
 *****************************************************************************/
extern mmi_vtcs_skin_struct g_mmi_vtcs_skin_cntx;


#endif /* __MMI_VIDEO_TELEPHONY__ */
#endif /* RESOURCE_VT_SKIN_H */


