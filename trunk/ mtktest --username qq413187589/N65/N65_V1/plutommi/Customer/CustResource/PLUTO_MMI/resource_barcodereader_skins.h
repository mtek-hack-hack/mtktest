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
 *  Resource_barcodereader_skins.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  QR Code Reader Applications v0.1
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#ifndef BARCODEREADER_SKIN_H
#define BARCODEREADER_SKIN_H

#include "mmi_features.h"
#ifdef __MMI_BARCODEREADER__

typedef struct
{
    BOOL is_show;
    S32 offset_x;
    S32 offset_y;
} barcodereader_osd_icon_struct;

typedef enum
{
    MMI_BARCODEREADER_TEXT_STYLE_NORMAL,
    MMI_BARCODEREADER_TEXT_STYLE_BORDER,
    MMI_BARCODEREADER_TEXT_STYLE_SHADOW
} mmi_barcodereader_text_style;

typedef struct
{
    U8 r;
    U8 g;
    U8 b;
    U8 style_r;
    U8 style_g;
    U8 style_b;
    U16 style;
} barcodereader_style_text_struct;

typedef struct
{
    BOOL is_draw_mmi_softkey;
    barcodereader_style_text_struct lsk;
    barcodereader_style_text_struct rsk;
} barcodereader_osd_softkey_struct;

typedef struct
{
    S32 offset_x;
    S32 offset_y;
    S32 width;
    S32 height;
} barcodereader_preview_wnd_struct;

typedef struct
{
    BOOL is_show;
    S32 offset_x;
    S32 offset_y;
    S32 width;
    S32 height;
    barcodereader_style_text_struct style_text;
} barcodereader_osd_hint_box_struct;

typedef struct
{
    BOOL is_show;
    BOOL is_right_align;
    S32 offset_x;
    S32 offset_y;
    barcodereader_style_text_struct style_text;
} barcodereader_osd_storage_struct;

typedef struct
{
    BOOL is_draw_bg_image;
    BOOL is_draw_bg_color;
    U8 r;
    U8 g;
    U8 b;
} barcodereader_osd_bg_struct;

typedef struct
{
    MMI_BOOL is_draw_mmi_title_bar;
    MMI_BOOL is_draw_mmi_caption;
} barcodereader_osd_title_struct;

typedef struct
{
    /* background */
    barcodereader_osd_bg_struct bg;

    /* title */
    barcodereader_osd_title_struct title;

    /* softkey (buttom bar) */
    barcodereader_osd_softkey_struct softkey;

    /* preview wnd */
    barcodereader_preview_wnd_struct preview_wnd;

    /* barcodereader setting */
    barcodereader_osd_icon_struct flash;
    barcodereader_osd_icon_struct ev;
    barcodereader_osd_icon_struct ev_inc;
    barcodereader_osd_icon_struct ev_dec;
    barcodereader_osd_icon_struct mf;
    barcodereader_osd_icon_struct mf_inc;
    barcodereader_osd_icon_struct mf_dec;
    barcodereader_osd_icon_struct storage;
    barcodereader_osd_icon_struct af_mode;
    barcodereader_osd_icon_struct zoom_mf_toggle;
    barcodereader_osd_icon_struct capture;

    barcodereader_osd_hint_box_struct hint_box;
    barcodereader_osd_storage_struct remain_storage;
} barcodereader_osd_layeout_struct;

extern barcodereader_osd_layeout_struct g_barcodereader_osd_cntx;

#ifdef __MMI_HORIZONTAL_BARCODEREADER__
extern barcodereader_osd_layeout_struct g_barcodereader_osd_cntx_270;
#endif 

#endif /* __MMI_BARCODEREADER__ */ 
#endif /* _BARCODEREADER_SKIN_H_ */

