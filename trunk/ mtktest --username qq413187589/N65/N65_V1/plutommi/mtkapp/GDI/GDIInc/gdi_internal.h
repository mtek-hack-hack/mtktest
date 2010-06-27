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
 *  gdi_internal.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  internal Include file for full set GDI function.
 *
 * Author:
 * -------
 * -------
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _GDI_INTERNAL_H_
#define _GDI_INTERNAL_H_

#define GDI_VERSION              0x06B
#undef  GDI_USING_LFS

/* for PC_SIMULATOR to pass some system call */
#define __NEWSIMULATOR

#include "kal_non_specific_general_types.h"     /* include this for kal data type */
#include "kal_release.h"

#include "lcd_if.h"
#include "lcd_sw_rnd.h"
#include "MMI_features.h"
#include "MMIDataType.h"
#include "setjmp.h"
#include "fat_fs.h"

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* local/peer struct */
#include "stack_ltlcom.h"
#include "stack_config.h"
#include "task_main_func.h"
#include "stack_timer.h"
#include "syscomp_config.h"
#include "task_config.h"
#include "stack_init.h"
#include "stacklib.h"
#include "event_shed.h"
#include "DebugInitDef.h"
#include "mmi_trc.h"

#include "gdi_include.h"

#include "timerevents.h"
////////////////////////////////////////////////////
// GDI animator ,  how many animating at the same time ( include main lcd / sub lcd )
#if defined(JATAAYU_SUPPORT)
#define GDI_ANIM_COUNT                                25
#elif defined(MT6228) || defined(MT6229) || defined(MT6230)
#define GDI_ANIM_COUNT                                8
#else 
#define GDI_ANIM_COUNT                                4
#endif 
/* ////////////////////////////////////////////////// */
enum
{
    GDI_TIMER_ANIM_BASE = GDI_TIMER_BASE,
    GDI_TIMER_ANIM_END = GDI_TIMER_ANIM_BASE + GDI_ANIM_COUNT - 1,

    GDI_TIMER_ANIM_CALLBACK_BASE = GDI_TIMER_ANIM_BASE + GDI_ANIM_COUNT,
    GDI_TIMER_ANIM_CALLBACK_END = GDI_TIMER_ANIM_CALLBACK_BASE + GDI_ANIM_COUNT - 1,

    GDI_TIMER_ESD_RECOVERY = GDI_TIMER_ANIM_CALLBACK_BASE + GDI_ANIM_COUNT,
    GDI_TIMER_ANIM_DUMMY
};

#if defined(__MMI_MAIN_BASE_LAYER_FORMAT__)
#define GDI_MAIN_BASE_LAYER_FORMAT __MMI_MAIN_BASE_LAYER_FORMAT__
#else
#define GDI_MAIN_BASE_LAYER_FORMAT GDI_COLOR_FORMAT_MAINLCD
#endif

#if defined(__MMI_MAIN_BASE_LAYER_FORMAT__)
#define GDI_SUB_BASE_LAYER_FORMAT __MMI_SUB_BASE_LAYER_FORMAT__
#else
#define GDI_SUB_BASE_LAYER_FORMAT GDI_COLOR_FORMAT_SUBLCD
#endif

#define GDI_WORK_BUFFER_FORMAT GDI_MAIN_BASE_LAYER_FORMAT


#include "gdi_lfs.h"

#include "gdi_image.h"
#include "gdi_animate.h"
#include "gdi_mutex.h"
#include "gdi_primitive.h"
#include "gdi_lcd.h"

#include "gdi_image_dev_bmp.h"
#include "gdi_image_bmp.h"
#include "gdi_image_gif.h"
#include "gdi_image_jpeg.h"
#include "gdi_image_png.h"
#include "gdi_image_wbmp.h"
#include "gdi_image_sequence.h"
#include "gdi_image_virtualfile.h"
#include "gdi_image_decoder.h"
#include "gdi_image_m3d.h"
#include "gdi_image_svg.h"
#include "gdi_image_avatar.h"
#include "gdi_image_alpha_bmp.h"

#include "gdi_layer.h"
#include "gdi_util.h"

#include "gdi_2d_engine.h"
#include "gdi_bytestream.h"
#include "gdi_font.h"
#include "gd_primitive_arm.h"

#if defined(DEMO_PROJECT)
 #define GDI_MUTEX_DEBUG
#endif 

#if defined(DEMO_PROJECT) && defined(__MMI_INTERACTIVE_PROFILNG__)
 #define GDI_IMAGE_PROFILE
#endif 

#if defined(GDI_MUTEX_DEBUG) && defined(GDI_USING_MUTEX)
#define GDI_RETURN_TYPE(T,X)     do{T x=X;GDI_ASSERT(gdi_mutex_level == gdi_mutex.cnt);GDI_UNLOCK; return x;}while(0)
#define GDI_RETURN(X)      do{GDI_RESULT x=X;GDI_ASSERT(gdi_mutex_level == gdi_mutex.cnt);GDI_UNLOCK; return x;}while(0)
#define GDI_RETURN_VOID do{GDI_ASSERT(gdi_mutex_level == gdi_mutex.cnt);GDI_UNLOCK; return ;}while(0)
#define GDI_ENTER_CRITICAL_SECTION(func)  GDI_LOCK; do {int gdi_mutex_level = gdi_mutex.cnt;
#define GDI_EXIT_CRITICAL_SECTION(func)      GDI_ASSERT(gdi_mutex_level == gdi_mutex.cnt);}while(0); GDI_UNLOCK;
#else /* defined(GDI_MUTEX_DEBUG) && defined(GDI_USING_MUTEX) */ 
#define GDI_RETURN_TYPE(T,X)                 do{T x=X;GDI_UNLOCK; return x;}while(0)
#define GDI_RETURN(X)                  do{GDI_RESULT x=X;GDI_UNLOCK; return x;}while(0)
#define GDI_RETURN_VOID             do{GDI_UNLOCK; return ;}while(0)
#define GDI_ENTER_CRITICAL_SECTION(func)  GDI_LOCK; do{
#define GDI_EXIT_CRITICAL_SECTION(func)   }while(0); GDI_UNLOCK;
#endif /* defined(GDI_MUTEX_DEBUG) && defined(GDI_USING_MUTEX) */ 

#define TOBOOL(X) (BOOL)(((X)?MMI_TRUE:MMI_FALSE))
#define GDI_ABS(x)   ((x)<0?-(x):(x))
#define GDI_TRC		    TRACE_GROUP_10

#if defined(WAP_SUPPORT) && defined(JPG_ENCODE)
    #define GDI_NEED_RESIZER_BUFFER     640
#else
    #define GDI_NEED_RESIZER_BUFFER		0
#endif
#if GDI_NEED_RESIZER_BUFFER         < GDI_LCD_WIDTH
#undef GDI_NEED_RESIZER_BUFFER
#define GDI_NEED_RESIZER_BUFFER GDI_LCD_WIDTH
#endif /* GDI_NEED_RESIZER_BUFFER         < GDI_LCD_WIDTH */ 
#if GDI_NEED_RESIZER_BUFFER         < GDI_LCD_HEIGHT
#undef GDI_NEED_RESIZER_BUFFER
#define GDI_NEED_RESIZER_BUFFER GDI_LCD_HEIGHT
#endif /* GDI_NEED_RESIZER_BUFFER         < GDI_LCD_HEIGHT */ 

#ifdef __MMI_SUBLCD__
#if GDI_NEED_RESIZER_BUFFER         < GDI_SUBLCD_WIDTH
#undef GDI_NEED_RESIZER_BUFFER
#define GDI_NEED_RESIZER_BUFFER GDI_SUBLCD_WIDTH
#endif /* GDI_NEED_RESIZER_BUFFER         < GDI_SUBLCD_WIDTH */ 

#if GDI_NEED_RESIZER_BUFFER         < GDI_SUBLCD_HEIGHT
#undef GDI_NEED_RESIZER_BUFFER
#define GDI_NEED_RESIZER_BUFFER GDI_SUBLCD_HEIGHT
#endif /* GDI_NEED_RESIZER_BUFFER         < GDI_SUBLCD_HEIGHT */ 
#endif /* __MMI_SUBLCD__ */ 

///////////////////////////////////////////////////
// GDI DEBUG FLAG
extern void gdi_debug_handler(S32 index,U8* string);

#define GDI_DEBUG_FLAG_IMAGE_DUMP      1

extern U32 GDI_DEBUG_FLAG;
extern U32 GDI_DEBUG_CNT;
extern U8 GDI_DEBUG_ARG[];

#endif /* _GDI_INTERNAL_H_ */ 

