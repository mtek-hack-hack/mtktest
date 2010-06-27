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
 *  PhotoEditor.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  PhotoEditor Header
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _PHOTOEDITOR_H_
#define _PHOTOEDITOR_H_

#include "MMI_features.h"

#ifdef __MMI_PHOTOEDITOR__

/***************************************************************************** 
* Define
*****************************************************************************/
/* shall move to feature define files */
#define __PHOEDT_FEATURE_PHOART__
// #define __PHOEDT_FEATURE_SCENMAST__
/*if defined(ISP_SUPPORT) && defined(MJPG_SUPPORT), don't support post processing */
#if defined(ISP_SUPPORT)
    #if !defined(MJPG_SUPPORT)
        #define __MMI_PHOART_EFFECT_SUPPORT__
    #endif /* !defined(MJPG_SUPPORT) */
#endif /* defined(ISP_SUPPORT) */


#if (defined(__MMI_ALPHA_LAYER_SUPPORT__) || __MMI_MAIN_BASE_LAYER_FORMAT__ != GDI_COLOR_FORMAT_16 )
    #define __MMI_PHOEDT_USE_FAKE_BASELAYER__
#endif

/* if this is defined, photoeditor will use app-based memory */
/* do not define this before 06A branch                      */
#define __PHOEDT_USE_APP_ASM__


#define PHOEDT_NOTIFY_DURATION         2000
#define PHOEDT_NOTIFY_SHORT_DURATION   ST_NOTIFYDURATION

/***************************************************************************** 
* Define
*****************************************************************************/
#define PHOEDT_FRAME_BUFFER_SIZE    ((GDI_LCD_WIDTH*GDI_LCD_HEIGHT*GDI_MAINLCD_BIT_PER_PIXEL)>>3)

#if (defined(MT6228) || defined(MT6229) || defined(MT6230))
#define PHOEDT_IMAGE_MT6228_SERIES
#endif /* #if (defined(MT6228) || defined(MT6229) || defined(MT6230)) */



/***************************************************************************** 
* Typedef
*****************************************************************************/
typedef enum
{
#ifdef __PHOEDT_FEATURE_PHOART__
    PHOEDT_PHOART,
#endif 

#ifdef __PHOEDT_FEATURE_SCENMAST__
    PHOEDT_SCENMAST,
#endif 

#ifdef __PHOEDT_FEATURE_IMGTILE__
    PHOEDT_IMGTILE,
#endif 
    PHOEDT_APP_COUNT    /* how many app in photo editor */
} phoedt_app_enum;

/* 200 byte */
typedef struct
{
    /* Photo Artist - 100 byte */
    S8 pa_add_text_string[80];  /* 80 byte *//* text string *//* reserve more than needed */
    S32 pa_text_color;
    S32 pa_border_color;
    S32 pa_shadow_color;
    S32 pa_text_size;           /* text size */
    S32 pa_text_italic;

    /* Slide Show - 28 byte */
    S32 ss_type_of_play;
    S32 ss_speed;
    S32 ss_effect;
    S32 ss_bgm; /* text size */
    S32 ss_horz;
    S32 ss_sound_effect;
    S32 ss_is_bgm_path_short;

    /* reserve 72 byte for future app */
    U8 reserve[72];

} phoedt_nvram_data_struct;

typedef struct
{
    phoedt_nvram_data_struct setting_data;
    S8 filename_buf[1024];
} phoedt_cntx_struct;

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/
#ifdef __PHOEDT_USE_APP_ASM__
extern PU8 g_phoedt_interrupt_buffer;
extern PU8 g_phoedt_original_buffer;
#else  /* __PHOEDT_USE_APP_ASM__ */
extern U8 g_phoedt_interrupt_buffer[PHOEDT_FRAME_BUFFER_SIZE];
extern U8 g_phoedt_original_buffer[PHOEDT_FRAME_BUFFER_SIZE];
#endif /* __PHOEDT_USE_APP_ASM__*/

#endif /* __MMI_PHOTOEDITOR__ */ 
#endif /* _PHOTOEDITOR_H_ */ 

