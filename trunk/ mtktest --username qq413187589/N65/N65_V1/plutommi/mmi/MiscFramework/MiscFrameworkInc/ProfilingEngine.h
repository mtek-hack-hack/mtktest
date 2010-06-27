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
 *   Profiling.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   MMI performance profiling utilities and framework
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef PROFILING_H
#define PROFILING_H

/***************************************************************************** 
* Include
*****************************************************************************/
#include "EngineerModeDef.h"
#include "gdi_include.h"

/***************************************************************************** 
* Define
*****************************************************************************/

#define MMI_FRM_PROFILING_MASK_1 (0x01)
#define MMI_FRM_PROFILING_MASK_2 (0x02)
#define MMI_FRM_PROFILING_MASK_3 (0x04)

#define MMI_FRM_BENCHMARK_LOG_FILE_NAME ":\\uibench.txt"
#define MMI_FRM_BENCHMARK_TEMP_FILE_NAME_BMP ":\\bench_temp.bmp"
#define MMI_FRM_BENCHMARK_TEMP_FILE_NAME_GIF ":\\bench_temp.gif"
#define MMI_FRM_BENCHMARK_TEMP_FILE_NAME_JPG ":\\bench_temp.jpg"
#define MMI_FRM_BENCHMARK_TEMP_FILE_NAME_PNG ":\\bench_temp.png"

#define MMI_FRM_BENCHMARK_RESULT_LENGTH     64
#define MMI_FRM_BENCHMARK_TIMER_DELAY       500
#define MMI_FRM_BENCHMARK_SCROLLBAR_RANGE   50
#define MMI_FRM_BENCHMARK_LOOP_TIMES        2
#define MMI_FRM_BENCHMARK_MAX_FILENAME_LEN  50
#define MMI_FRM_BENCHMARK_MAX_RULE          32
#define MMI_FRM_BENCHMARK_BG_JPG_LENGTH     (20*1024*1024)


/***************************************************************************** 
* Typedef
*****************************************************************************/

typedef enum
{
    MMI_FRM_PROFILING_DELAY_SCREEN = 0,
    MMI_FRM_PROFILING_DELAY_LIST_HIGHLIGHT,
    MMI_FRM_PROFILING_DELAY_MATRIX_HIGHLIGHT,
    MMI_FRM_PROFILING_DELAY_OFFSET,
    MMI_FRM_PROFILING_DELAY_MAX_TYPE
} mmi_frm_profiling_delay_enum;

typedef enum
{
    MMI_FRM_BENCHMARK_IMAGE_DECODE_FROM_FILE_BMP = 0,           /*Decoding bitmap from file*/
    MMI_FRM_BENCHMARK_IMAGE_DECODE_FROM_FILE_GIF,               /*Decoding GIF from file*/
#ifdef GDI_USING_JPEG
    MMI_FRM_BENCHMARK_IMAGE_DECODE_FROM_FILE_JPG,               /*Decoding JPG from file*/
#endif 
#ifdef GDI_USING_PNG
    MMI_FRM_BENCHMARK_IMAGE_DECODE_FROM_FILE_PNG,               /*Decoding PNG from file*/
#endif 
    MMI_FRM_BENCHMARK_IMAGE_DECODE_FROM_C_ARRAY_BMP,            /*Decoding bitmap from memory*/
    MMI_FRM_BENCHMARK_IMAGE_DECODE_FROM_C_ARRAY_GIF,            /*Decoding GIF from memory*/
#ifdef GDI_USING_JPEG
    MMI_FRM_BENCHMARK_IMAGE_DECODE_FROM_C_ARRAY_JPG,            /*Decoding JPG from memory*/
#endif 
#ifdef GDI_USING_PNG
    MMI_FRM_BENCHMARK_IMAGE_DECODE_FROM_C_ARRAY_PNG,            /*Decoding PNG from memory*/
#endif 
    MMI_FRM_BENCHMARK_IMAGE_DECODE_FROM_C_ARRAY_ABM,            /*Decoding ABM from memory*/
    MMI_FRM_BENCHMARK_IMAGE_DECODE_FROM_FILE_BMP_RESIZED,       /*Decoding resized bitmap from file*/
    MMI_FRM_BENCHMARK_IMAGE_DECODE_FROM_FILE_GIF_RESIZED,       /*Decoding resized GIF from file*/
#ifdef GDI_USING_JPEG
    MMI_FRM_BENCHMARK_IMAGE_DECODE_FROM_FILE_JPG_RESIZED,       /*Decoding resized JPG from file*/
#endif 
#ifdef GDI_USING_PNG
    MMI_FRM_BENCHMARK_IMAGE_DECODE_FROM_FILE_PNG_RESIZED,       /*Decoding resized PNG from file*/
#endif 
    MMI_FRM_BENCHMARK_IMAGE_DECODE_FROM_C_ARRAY_BMP_RESIZED,    /*Decoding resized bitmap from memory*/
    MMI_FRM_BENCHMARK_IMAGE_DECODE_FROM_C_ARRAY_GIF_RESIZED,    /*Decoding resized GIF from memory*/
#ifdef GDI_USING_JPEG
    MMI_FRM_BENCHMARK_IMAGE_DECODE_FROM_C_ARRAY_JPG_RESIZED,    /*Decoding resized JPG from memory*/
#endif 
#ifdef GDI_USING_PNG
    MMI_FRM_BENCHMARK_IMAGE_DECODE_FROM_C_ARRAY_PNG_RESIZED,    /*Decoding resized PNG from memory*/
#endif 
    MMI_FRM_BENCHMARK_STRING_DISPLAY,                           /*Print text*/
    MMI_FRM_BENCHMARK_UI_ELEMENT_TITLE,                         /*Show title*/
    MMI_FRM_BENCHMARK_UI_ELEMENT_SCROLLBAR,                     /*Show scrollbar*/
    MMI_FRM_BENCHMARK_UI_ELEMENT_SOFTKEY,                       /*Show softkey*/
    MMI_FRM_BENCHMARK_UI_ELEMENT_STATUS_ICON,                   /*Show status icon*/
    MMI_FRM_BENCHMARK_UI_ELEMENT_LIST_MENU,                     /*Show list menu*/
    MMI_FRM_BENCHMARK_UI_ELEMENT_VIRTUAL_KEYBOARD,              /*Show virtual keyboard*/
    MMI_FRM_BENCHMARK_UI_ELEMENT_EDITOR,                        /*Show editor*/
    MMI_FRM_BENCHMARK_THEME_IDLE_SCREEN_BG,                     /*Show idle screen background*/
    MMI_FRM_BENCHMARK_THEME_MAIN_MENU_BG,                       /*Show main menu background*/
    MMI_FRM_BENCHMARK_THEME_SUB_MENU_BG,                        /*Show sub menu background*/
    MMI_FRM_BENCHMARK_POWER_ON_ANIMATION,                       /*Show power on animation*/
    MMI_FRM_BENCHMARK_SYSTEM_WALLPAPER,                         /*Show system wallpapaer*/
    MMI_FRM_BENCHMARK_GDI_BLT_PREVIOUS,                         /*Bitblt*/
    MMI_FRM_BENCHMARK_END
}mmi_frm_benchmark_enum;

/*****************************************************************************              
* Extern Global Variable                                                                    
*****************************************************************************/

/*****************************************************************************              
* Extern Global Function                                                                    
*****************************************************************************/

extern MMI_BOOL mmi_frm_profiling_interactive_is_enabled(void);
extern void mmi_frm_profiling_interactive_enable(MMI_BOOL enable);

extern MMI_BOOL mmi_frm_profiling_gdi_profile_is_enabled(void);
extern void mmi_frm_profiling_gdi_profile_enable(MMI_BOOL enable);

extern void mmi_frm_profiling_interactive_start(void);
extern void mmi_frm_profiling_interactive_start2(void);
extern void mmi_frm_profiling_interactive_start3(void);
extern void mmi_frm_profiling_interactive_end(void);
extern void mmi_frm_profiling_interactive_end2(void);
extern void mmi_frm_profiling_interactive_end3(void);
extern void mmi_frm_profiling_interactive_show(U8 *prompt, U32 flags);

extern void mmi_frm_profiling_delay_set(mmi_frm_profiling_delay_enum type, U32 ms);
extern U32 mmi_frm_profiling_delay_get(mmi_frm_profiling_delay_enum type);
extern void mmi_frm_profiling_delay_start_timer(mmi_frm_profiling_delay_enum type);
extern void mmi_frm_profiling_delay_perform(mmi_frm_profiling_delay_enum type);

extern void mmi_frm_benchmark_start(void (*finish_callback)(const U8 *msg));
extern void mmi_frm_benchmark_stop(void);

#endif /* PROFILING_H */ 

