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
 *  wgui_categories_calendar.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  Calendar related categories.
 *
 *  Author:
 * -------
 *  Siyin Liu (MBJ06076)
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __WGUI_CATEGORIES_CALENDAR_H__
#define __WGUI_CATEGORIES_CALENDAR_H__

#include "wgui.h"
#include "lcd_sw_rnd.h"
#include "gdi_include.h"
#include "wgui_calendar.h"
#include "gui_calendar.h"
#include "wgui_asyncdynamic_menuitems.h"

#define  CLNDR_TITLE_LEN            12*ENCODING_LENGTH
#define  CLNDR_HINT_LEN             8*ENCODING_LENGTH
#define  CLNDR_MAX_DAYS             31
#define  CLNDR_LAST_NAVI_YEAR       2030
#define  CLNDR_FIRST_NAVI_YEAR      1970

#define CAL_SNAPSHOT_RET_SUCCESS    (0)
#define CAL_SNAPSHOT_RET_BUFFER_ERR (-1)
#define CAL_SNAPSHOT_RET_GDI_ERR    (-2)
#define CAL_SNAPSHOT_RET_NO_MEM_ERR (-3)


extern void ShowCategory83Screen(
                UI_image_ID_type bg_id,
                U8 **horizon_string_list,
                gui_calendar_cell_struct *cell,
                U32 num_of_row,
                U32 num_of_column,
                U32 current_row,
                U32 current_column,
                U32 highlighted_row,
                U32 highlighted_column,
                U8 cell_bg_fill_type,
                U8 cell_text_display_type,
                U8 cell_icon_display_type,
                MMI_BOOL is_status_bar,
                U8 *str_LeftSoftkey,
                U8 *str_rightSoftkey);

extern S32 wgui_cat83_save_snapshot(U8* layer_buffer, U32 buf_size, U8* filename); 

#endif /* __WGUI_CATEGORIES_CALENDAR_H__ */ 

