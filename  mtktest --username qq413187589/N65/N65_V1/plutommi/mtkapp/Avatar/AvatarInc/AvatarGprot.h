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
 *  AvatarGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Avatar external functions and variables
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#ifndef _AVATAR_GPROT_H_
#define _AVATAR_GPROT_H_

#ifdef __MMI_AVATAR__

#ifndef _GDI_INCLUDE_H_
#include "gdi_include.h"
#endif 


#if ((LCD_WIDTH == 128) && (LCD_HEIGHT == 128))
#elif ((LCD_WIDTH == 128) && (LCD_HEIGHT == 160))
#elif ( (LCD_WIDTH == 176) && (LCD_HEIGHT == 220) )
/***********************************
* Facial texture offset
************************************/
#define MMI_AVATAR_TEXTURE_OFFSET_PIXEL 3

#define MMI_AVATAR_L_EYE_OFFSET_X  0
#define MMI_AVATAR_L_EYE_OFFSET_Y  32
#define MMI_AVATAR_R_EYE_OFFSET_X  64
#define MMI_AVATAR_R_EYE_OFFSET_Y  32
#define MMI_AVATAR_L_BROW_OFFSET_X 0
#define MMI_AVATAR_L_BROW_OFFSET_Y 8
#define MMI_AVATAR_R_BROW_OFFSET_X 64
#define MMI_AVATAR_R_BROW_OFFSET_Y 8
#define MMI_AVATAR_LIP_OFFSET_X 0
#define MMI_AVATAR_LIP_OFFSET_Y 77
#define MMI_AVATAR_DECORATION_OFFSET_X 0
#define MMI_AVATAR_DECORATION_OFFSET_Y 32

#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 320) )
/***********************************
* Facial texture offset
************************************/
#define MMI_AVATAR_TEXTURE_OFFSET_PIXEL 3

#define MMI_AVATAR_L_EYE_OFFSET_X  0
#define MMI_AVATAR_L_EYE_OFFSET_Y  32
#define MMI_AVATAR_R_EYE_OFFSET_X  64
#define MMI_AVATAR_R_EYE_OFFSET_Y  32
#define MMI_AVATAR_L_BROW_OFFSET_X 0
#define MMI_AVATAR_L_BROW_OFFSET_Y 8
#define MMI_AVATAR_R_BROW_OFFSET_X 64
#define MMI_AVATAR_R_BROW_OFFSET_Y 8
#define MMI_AVATAR_LIP_OFFSET_X 0
#define MMI_AVATAR_LIP_OFFSET_Y 77
#define MMI_AVATAR_DECORATION_OFFSET_X 0
#define MMI_AVATAR_DECORATION_OFFSET_Y 32

#elif ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 240) )
/***********************************
* Facial texture offset
************************************/
#define MMI_AVATAR_TEXTURE_OFFSET_PIXEL 3

#define MMI_AVATAR_L_EYE_OFFSET_X  0
#define MMI_AVATAR_L_EYE_OFFSET_Y  32
#define MMI_AVATAR_R_EYE_OFFSET_X  64
#define MMI_AVATAR_R_EYE_OFFSET_Y  32
#define MMI_AVATAR_L_BROW_OFFSET_X 0
#define MMI_AVATAR_L_BROW_OFFSET_Y 8
#define MMI_AVATAR_R_BROW_OFFSET_X 64
#define MMI_AVATAR_R_BROW_OFFSET_Y 8
#define MMI_AVATAR_LIP_OFFSET_X 0
#define MMI_AVATAR_LIP_OFFSET_Y 77
#define MMI_AVATAR_DECORATION_OFFSET_X 0
#define MMI_AVATAR_DECORATION_OFFSET_Y 32
#endif /* (LCD_WIDTH == XXX && LCD_HEIGHT == xxx) */

#define MMI_AVATAR_SUCCEED (0)
#define MMI_AVATAR_FAILED (-1)
#define MMI_AVATAR_MEMORY_NOT_ENOUGH (-2)
#define MMI_AVATAR_M3D_RESOURCE_NOT_ENOUGH (-3)
#define MMI_AVATAR_M3D_IMAGE_TOO_LARGE (-4)

//#define MMI_AVATAR_M3D_MEMORY_SIZE (450*1024)
#define MMI_AVATAR_APP_MEMORY_SIZE (240*320*2)
#define MMI_AVATAR_NAME_LENGTH (23*ENCODING_LENGTH)

//extern S32 avatar_mem_size;
#define MMI_AVATAR_TEXTURE_BUFFER_SIZE (128*128*2)
#define MMI_AVATAR_OSD_BUFFER_SIZE (((LCD_WIDTH*LCD_HEIGHT*GDI_MAINLCD_BIT_PER_PIXEL)>>3)*2)
#define MMI_AVATAR_SCR_MEM_SIZE (MMI_AVATAR_TEXTURE_BUFFER_SIZE + MMI_AVATAR_OSD_BUFFER_SIZE)


/****************************************************************************
* Extern Global Variable                                                            
*****************************************************************************/


/****************************************************************************
* Extern Global Function                                                            
*****************************************************************************/
extern void mmi_avatar_init_app(void);
extern void mmi_avatar_init(void);
/****************************************************************************
* For phonebook and phone settings to use.
*****************************************************************************/
typedef enum{
    MMI_AVATAR_APP_EDITOR,
    MMI_AVATAR_APP_CALLER_PICTURE,
    MMI_AVATAR_APP_CALLER_VIDEO,
    MMI_AVATAR_APP_WALLPAPER,
    MMI_AVATAR_APP_SCREENSAVER,
    MMI_AVATAR_APP_POWERON_ANIMATION,
    MMI_AVATAR_APP_POWEROFF_ANIMATION,
    MMI_AVATAR_APP_TOTAL_COUNT
} mmi_avatar_app_type_enum;

typedef struct
{
    S16 selected_animation;
    S16 selected_head;
    S16 selected_hair;
    S16 selected_eye;
    S16 selected_brow;
    S16 selected_lip;
    S16 selected_face;
    S16 selected_dress;
    S16 selected_decoration;
    S16 selected_body;

    S16 offset_eye_x;
    S16 offset_eye_y;
    S16 offset_brow_x;
    S16 offset_brow_y;
    S16 offset_lip_y;
    S16 offset_decoration_y;

    S16 s_level_eye;
    S16 s_level_brow;
    S16 s_level_lip;
    S16 s_level_decoration;
        
    S8  filename[MMI_AVATAR_NAME_LENGTH];
}mmi_avatar_avatar_struct;


typedef void (*avatar_callback) (U32 callback_id, U32 serial_num);
extern void mmi_avatar_select_path_and_enter (
        	mmi_avatar_app_type_enum app_type,
        	avatar_callback func_ptr);

extern pBOOL mmi_avatar_is_avatar_existed(U32 id);
extern void mmi_avater_get_name_by_avatarid(U32 id, PS8 name);

extern pBOOL mmi_avatar_is_avatar_valid(U32 id, U32 serial_num);

/****************************************************************************
* For GDI user interface
*****************************************************************************/
extern GDI_RESULT mmi_avatar_draw_before_handler(
                    U32 flag,
                    U32 frame_pos,
                    S32 x,
                    S32 y,
                    S32 w,
                    S32 h,
                    U8 *data_ptr,
                    U32 img_size);
extern GDI_RESULT mmi_avatar_draw_handler(
                    U32 flag,
                    U32 frame_pos,
                    S32 x,
                    S32 y,
                    S32 w,
                    S32 h,
                    U8 *data_ptr,
                    U32 img_size);
extern GDI_RESULT mmi_avatar_draw_after_handler(
                    U32 flag,
                    U32 frame_pos,
                    S32 x,
                    S32 y,
                    S32 w,
                    S32 h,
                    U8 *data_ptr,
                    U32 img_size);
extern GDI_RESULT mmi_avatar_get_dimension_handler(U32 flag, U8 *data_ptr, U32 img_size, S32 *width, S32 *height);
extern GDI_RESULT mmi_avatar_get_pos_info_handler(
                    U32 flag,
                    U8 *data_ptr,
                    U32 img_size,
                    BOOL quick_mode,
                    S32 *total_pos,
                    gdi_anim_pos_type_enum *pos_type);


#endif /* __MMI_AVATAR__ */ 
#endif /* _AVATAR_GPROT_H_ */ 
