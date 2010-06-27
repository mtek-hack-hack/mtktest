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
 *  FileMgrUI.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  File Manager.
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
 *
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

#include "MMI_include.h"

#include "CommonScreens.h"
#include "PhoneSetupGprots.h"

#include "lcd_sw_rnd.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "Conversions.h"

#include "FileMgr.h"

#ifdef __DRM_SUPPORT__
#include "DRM_gprot.h"
#endif /* __DRM_SUPPORT__ */ 

#include "FileManagerDef.h"
#include "FileManagerGProt.h"
#include "FileMgrStruct.h"

#ifdef __MMI_EBOOK_READER__
#include "EbookGProt.h"
#include "EbookProt.h"
#include "EbookManager.h"
#endif /* __MMI_EBOOK_READER__ */ 

#ifdef __MMI_SWFLASH__
#include "SWFlashDef.h"
#include "SWFlashGProt.h"
#endif /* __MMI_SWFLASH__ */

#ifdef __MMI_FILE_MANAGER__

/***************************************************************************** 
* Define
*****************************************************************************/
#ifdef __MMI_TOUCH_SCREEN__
#define FMGR_UI_DELAY_DECODE_DURATION  (1000)
#else 
#define FMGR_UI_DELAY_DECODE_DURATION  (100)
#endif 
#define FMGR_UI_IMAGE_BOX_SPACING      (2)
#define FMGR_UI_TEXT_SPACING           (5)


/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef enum
{
    FMGR_UI_LIST_STYLE,
    FMGR_UI_INFO_STYLE,
    FMGR_UI_MATRIX_STYLE
} fmgr_ui_style_enum;

/*****************************************************************************
* Global Variable - Extern                                                                 
*****************************************************************************/
extern fmgr_context_struct g_fmgr_context;
extern fmgr_context_struct *fmgr_p;
extern BOOL r2lMMIFlag;
extern MMI_theme *current_MMI_theme;

/*****************************************************************************
* Global Function                                                           
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/
#if defined(FMGR_USING_CACHE)

   /* cache structure */
fmgr_thumb_image_cache_struct image_cache_list_buffer[FMGR_THUMB_IMAGE_CACHE_MAX_COUNT];
fmgr_thumb_image_handle_struct image_handle_list_buffer[FMGR_THUMB_IMAGE_HANDLE_MAX_COUNT];

fmgr_image_cache_struct *fmgr_image_cache_p = &g_fmgr_context.image_cache;
fmgr_delay_decode_struct *fmgr_delay_decoder_p = &g_fmgr_context.delay_decoder[0];
#endif /* defined(FMGR_USING_CACHE) */ 

/* x1 and y1 of the highlight menuitem */
extern S32 GUI_current_fixed_icontext_menuitem_x, GUI_current_fixed_icontext_menuitem_y;

/*****************************************************************************
* Local Function 
*****************************************************************************/
static void mmi_fmgr_draw_free_space_icon(S32 box_x1, S32 box_y1, S32 box_height, U32 ratio);
static BOOL mmi_fmgr_show_thumb_image(
                S32 item_idx,
                S32 menuitem_offset_x,
                S32 menuitem_offset_y,
                S32 box_offset_x,
                S32 box_offset_y,
                S32 box_width,
                S32 box_height,
                PU8 icon_ptr,
                BOOL is_hilighted,
                U16 ui_style);

#if defined(FMGR_USING_CACHE)
static void mmi_fmgr_decode_thumb_image_result_hdlr(GDI_RESULT decode_result, gdi_handle handle);

static void mmi_fmgr_delay_decode_image(
                S32 item_idx,
                S32 menuitem_offset_x,
                S32 menuitem_offset_y,
                S32 box_offset_x,
                S32 box_offset_y,
                S32 box_width,
                S32 box_height,
                S32 icon_offset_x,
                S32 icon_offset_y,
                S32 icon_width,
                S32 icon_height,
                PU8 icon_ptr,
                BOOL is_hilighted,
                U16 ui_style);

static void mmi_fmgr_delay_decode_0(void);
static void mmi_fmgr_delay_decode_1(void);
static void mmi_fmgr_delay_decode_2(void);
static void mmi_fmgr_delay_decode_3(void);
static void mmi_fmgr_delay_decode_4(void);
static void mmi_fmgr_delay_decode_5(void);
static void mmi_fmgr_delay_decode_6(void);
static void mmi_fmgr_delay_decode_7(void);
static void mmi_fmgr_delay_decode_8(void);
static void mmi_fmgr_delay_decode_9(void);
#endif /* defined(FMGR_USING_CACHE) */ 
void mmi_fmgr_draw_hilight_menuitem_bg_callback(S32 x1, S32 y1, S32 x2, S32 y2);
void mmi_fmgr_draw_hilight_menuitem_timer_callback(void);
void mmi_fmgr_draw_hilight_menuitem_bg(S32 x1, S32 y1, S32 x2, S32 y2);

/*****************************************************************************
*
* Thumb Image Caching 
*
*****************************************************************************/

/*****************************************************************************
*
*  [fm_thumb_image_handle_struct] is used to record which image is send to decoder.
*  These information is used when decoder successfully decode the image and used
*  to calcuate which region should be cached.
*
*  BOOL        is_used;       <------ this entry is used or not
*  gdi_handle  handle;        <------ gdi_handle of this image given by decoder
*  S16         menuitem_idx;  <------ menu item index
*  S32         offset_x;      <------ image offset x
*  S32         offset_y;      <------ image offset y
*
*  If decoded image is larger than thumb image size, it will be shrink to fit
*  the thumb image size and persist its ratio (will not distort).
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_create_thumb_image_cache
 * DESCRIPTION
 *  create thumb image cache resource.
 * PARAMETERS
 *  image_size      [IN]        Menuitem height, this is used to caculate image resource.
 * RETURNS
 *  void
 * BOOL
 *****************************************************************************/
void mmi_fmgr_create_thumb_image_cache(S32 image_size)
{
#if defined(FMGR_USING_CACHE)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 cache_size;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* calcuate thumb image size */
    fmgr_image_cache_p->image_size = image_size;
    cache_size = (fmgr_image_cache_p->image_size * fmgr_image_cache_p->image_size * GDI_LAYER.act_bit_per_pixel) >> 3;
    ASSERT(cache_size > 0);

    /* sub 1 for overhead usage */
    fmgr_image_cache_p->image_cache_item_count = (U16) (mmi_frm_scrmem_get_available_size() / cache_size) - 1;

    if (fmgr_image_cache_p->image_cache_item_count > FMGR_THUMB_IMAGE_CACHE_MAX_COUNT)
    {
        fmgr_image_cache_p->image_cache_item_count = FMGR_THUMB_IMAGE_CACHE_MAX_COUNT;
    }

    /* init seq number */
    fmgr_image_cache_p->image_decode_seq_num = 0;

    /* allocate buffer for list data */
    for (i = 0; i < fmgr_image_cache_p->image_cache_item_count; i++)
    {
        fmgr_image_cache_p->image_cache_list[i] = &image_cache_list_buffer[i];
        fmgr_image_cache_p->image_cache_list[i]->is_used = FALSE;
        fmgr_image_cache_p->image_cache_list[i]->unused_duration = 0;
        fmgr_image_cache_p->image_cache_list[i]->bmp.buf_ptr = mmi_frm_scrmem_alloc(cache_size);
    }

    for (i = 0; i < FMGR_THUMB_IMAGE_HANDLE_MAX_COUNT; i++)
    {
        fmgr_image_cache_p->image_handle_list[i] = &image_handle_list_buffer[i];
        fmgr_image_cache_p->image_handle_list[i]->is_used = FALSE;
    }

#endif /* defined(FMGR_USING_CACHE) */ 
}

/*****************************************************************************
 * FUNCTION
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 * BOOL
 *****************************************************************************/
void mmi_fmgr_stop_decode(void)
{
#if defined(FMGR_USING_CACHE)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Close all decode handle, so that GDI will release file handle */
    for (i = 0; i < FMGR_THUMB_IMAGE_HANDLE_MAX_COUNT; i++)
    {
        if (fmgr_image_cache_p->image_handle_list[i] &&
            fmgr_image_cache_p->image_handle_list[i]->is_used &&
            fmgr_image_cache_p->image_handle_list[i]->handle)
        {
            gdi_image_decoder_stop(fmgr_image_cache_p->image_handle_list[i]->handle);
            fmgr_image_cache_p->image_handle_list[i]->handle = 0;
            fmgr_image_cache_p->image_handle_list[i]->is_used = FALSE;
        }
    }
#endif    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_free_thumb_image_cache
 * DESCRIPTION
 *  free thumb image cache resource.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * BOOL
 *****************************************************************************/
void mmi_fmgr_free_thumb_image_cache(void)
{
#if defined(FMGR_USING_CACHE)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset delay decoder */
    g_fmgr_context.delay_decode_index = 0;
    StopTimer(FMGR_DELAY_DECODE_0);
    StopTimer(FMGR_DELAY_DECODE_1);
    StopTimer(FMGR_DELAY_DECODE_2);
    StopTimer(FMGR_DELAY_DECODE_3);
    StopTimer(FMGR_DELAY_DECODE_4);
    StopTimer(FMGR_DELAY_DECODE_5);
    StopTimer(FMGR_DELAY_DECODE_6);
    StopTimer(FMGR_DELAY_DECODE_7);
    StopTimer(FMGR_DELAY_DECODE_8);
    StopTimer(FMGR_DELAY_DECODE_9);

    /* free all allocated memory */
    for (i = 0; i < fmgr_image_cache_p->image_cache_item_count; i++)
    {
        if (fmgr_image_cache_p->image_cache_list[i]->bmp.buf_ptr != NULL)
        {
            mmi_frm_scrmem_free(fmgr_image_cache_p->image_cache_list[i]->bmp.buf_ptr);
            fmgr_image_cache_p->image_cache_list[i]->bmp.buf_ptr = NULL;
        }
        else
        {
            MMI_ASSERT(0);
        }
    }
	fmgr_image_cache_p->image_cache_item_count = 0;

    mmi_fmgr_stop_decode();

#endif /* defined(FMGR_USING_CACHE) */ 
}

/*****************************************************************************
* FUNCTION
*   mmi_fmgr_delay_decode_x()
* DESCRIPTION
*   delay decode callback function for timer expire
* PARAMETERS
*   void
* RETURNS
*   BOOL
* GLOBALS AFFECTED
*   nil
*****************************************************************************/
#if defined(FMGR_USING_CACHE)

   /* start of delay decoder function macro */
#define FMGR_DELAY_DECODE_FUNCTION(_idx_)                                                     \
      static void mmi_fmgr_delay_decode_##_idx_##(void)                                          \
      {                                                                                          \
         mmi_fmgr_delay_decode_image(  g_fmgr_context.delay_decoder[##_idx_##].item_idx,         \
                                       g_fmgr_context.delay_decoder[##_idx_##].menuitem_offset_x,\
                                       g_fmgr_context.delay_decoder[##_idx_##].menuitem_offset_y,\
                                       g_fmgr_context.delay_decoder[##_idx_##].box_offset_x,     \
                                       g_fmgr_context.delay_decoder[##_idx_##].box_offset_y,     \
                                       g_fmgr_context.delay_decoder[##_idx_##].box_width,        \
                                       g_fmgr_context.delay_decoder[##_idx_##].box_height,       \
                                       g_fmgr_context.delay_decoder[##_idx_##].icon_offset_x,    \
                                       g_fmgr_context.delay_decoder[##_idx_##].icon_offset_y,    \
                                       g_fmgr_context.delay_decoder[##_idx_##].icon_width,       \
                                       g_fmgr_context.delay_decoder[##_idx_##].icon_height,      \
                                       g_fmgr_context.delay_decoder[##_idx_##].icon_ptr,         \
                                       g_fmgr_context.delay_decoder[##_idx_##].is_hilighted,     \
                                       g_fmgr_context.delay_decoder[##_idx_##].ui_style);        \
      }
   /* end of macro */

   /* delay decode function */
FMGR_DELAY_DECODE_FUNCTION(0)
FMGR_DELAY_DECODE_FUNCTION(1)
FMGR_DELAY_DECODE_FUNCTION(2)
FMGR_DELAY_DECODE_FUNCTION(3)
FMGR_DELAY_DECODE_FUNCTION(4)
FMGR_DELAY_DECODE_FUNCTION(5)
FMGR_DELAY_DECODE_FUNCTION(6) FMGR_DELAY_DECODE_FUNCTION(7) FMGR_DELAY_DECODE_FUNCTION(8) FMGR_DELAY_DECODE_FUNCTION(9)
#endif /* defined(FMGR_USING_CACHE) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_delay_decode_image
 * DESCRIPTION
 *  decode image for delay decoder, avoid UI hang too long
 * PARAMETERS
 *  item_idx                [IN]        Item index
 *  menuitem_offset_x       [IN]        Menu item's offset x
 *  menuitem_offset_y       [IN]        Menu item's offset y
 *  box_offset_x            [IN]        Image box's offset x
 *  box_offset_y            [IN]        Image box's offset y
 *  box_width               [IN]        Image box's width
 *  box_height              [IN]        Image box's height
 *  icon_offset_x           [IN]        Icon's offset x
 *  icon_offset_y           [IN]        Icon's offset y
 *  icon_width              [IN]        Icon's width
 *  icon_height             [IN]        Icon's height
 *  icon_ptr                [IN]        Image ptr
 *  is_hilighted            [IN]        Is highlight flag
 *  ui_style                [IN]        UI style
 * RETURNS
 *  void
 * BOOL
 *****************************************************************************/
#if defined(FMGR_USING_CACHE)
     static void mmi_fmgr_delay_decode_image(
                    S32 item_idx,
                    S32 menuitem_offset_x,
                    S32 menuitem_offset_y,
                    S32 box_offset_x,
                    S32 box_offset_y,
                    S32 box_width,
                    S32 box_height,
                    S32 icon_offset_x,
                    S32 icon_offset_y,
                    S32 icon_width,
                    S32 icon_height,
                    PU8 icon_ptr,
                    BOOL is_hilighted,
                    U16 ui_style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT file_info;
    S8 buffer_UCS2[FMGR_PATH_BUFFER_SIZE];
    GDI_RESULT ret;
    S32 img_width, img_height;
    S32 resized_width, resized_height;
    S32 resized_offset_x, resized_offset_y;
    S32 handle_idx;
    S32 draw_pos_x, draw_pos_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get file info */
    mmi_fmgr_kernel_get_file_info((U16) (item_idx), &file_info);

    /* check if background decoding finish: yes then start to scroll */    
    if (g_fmgr_context.decoding_count == 0)
        wgui_status_icon_lock_redrawing();    

     g_fmgr_context.decoding_count++;
    
    /* check if has DRM right */
#ifdef __DRM_SUPPORT__
    if (fmgr_check_drm_rights(&file_info, DRM_PERMISSION_DISPLAY) != FMGR_DRM_GRANT_PERMISSION)
    {
        /* do not have permission, skip */
        return;
    }
#endif /* __DRM_SUPPORT__ */ 

    gdi_layer_push_clip();
    gdi_layer_reset_clip();

    /* find a vlid decode handle slot */
    for (handle_idx = 0; handle_idx < FMGR_THUMB_IMAGE_HANDLE_MAX_COUNT; handle_idx++)
    {
        if (fmgr_image_cache_p->image_handle_list[handle_idx]->is_used == FALSE)
        {
            break;
        }
    }

    /* valid handle chcek */
    ASSERT(handle_idx < FMGR_THUMB_IMAGE_HANDLE_MAX_COUNT);

    mmi_fmgr_kernel_get_path_name((PS8) buffer_UCS2);
    mmi_ucs2cat((PS8) buffer_UCS2, (PS8) file_info.file_name);

    /* get jpeg width and height */
    ret = gdi_image_get_dimension_file((PS8) buffer_UCS2, &img_width, &img_height);

    /* check if is a valid image or not */
    /* TODO: Adapt to File limit */
    if ((ret < 0) || (img_width <= 0) || (img_height <= 0) ||   /* invalid image size */
        (file_info.file_size > 2048 * 1024))    /* file too large */
    {
        fmgr_p->file_cache[item_idx - fmgr_p->cache_start_idx].is_able_display = FALSE;
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
        gdi_layer_pop_clip();
        return;
    }

    /* can get dimesion from file, must be a valid jpeg file, then draw it */



    if ( (img_width + 4 < box_width) && (img_height +4 < box_height))
    {
        resized_width = img_width;
        resized_height = img_height;
        resized_offset_x = ((box_width-4-img_width)>>1);
        resized_offset_y = ((box_height-4-img_height)>>1);           
        draw_pos_x = box_offset_x + 2 + resized_offset_x;
        draw_pos_y = box_offset_y + 2 + resized_offset_y;

    }
    else
    {
        /* fit it into a bounding box */
        if (ui_style == FMGR_UI_MATRIX_STYLE)
        {
            /* reserver 2 pixel at each side to draw boundry and highlight rectangle */
            gdi_image_util_fit_bbox(
                box_width - 4,
                box_height - 4,
                img_width,
                img_height,
                &resized_offset_x,
                &resized_offset_y,
                &resized_width,
                &resized_height);

            draw_pos_x = box_offset_x + 2 + resized_offset_x;
            draw_pos_y = box_offset_y + 2 + resized_offset_y;
        }
        else
        {
            /* reserver 1 pixel at each side to draw boundry */
            gdi_image_util_fit_bbox(
                box_width - 2,
                box_height - 2,
                img_width,
                img_height,
                &resized_offset_x,
                &resized_offset_y,
                &resized_width,
                &resized_height);

            draw_pos_x = box_offset_x + 1 + resized_offset_x;
            draw_pos_y = box_offset_y + 1 + resized_offset_y;
            resized_height--;
        }
    }    



    ret = gdi_image_decoder_decode_file(
            draw_pos_x,
            draw_pos_y,
            resized_width,
            resized_height,
            FALSE,
            (PS8) buffer_UCS2,
            &(fmgr_image_cache_p->image_handle_list[handle_idx]->handle));

    if (ret >= 0)
    {
        fmgr_image_cache_p->image_handle_list[handle_idx]->is_used = TRUE;
        fmgr_image_cache_p->image_handle_list[handle_idx]->draw_pos_x = draw_pos_x;
        fmgr_image_cache_p->image_handle_list[handle_idx]->draw_pos_y = draw_pos_y;
        fmgr_image_cache_p->image_handle_list[handle_idx]->resized_offset_x = resized_offset_x;
        fmgr_image_cache_p->image_handle_list[handle_idx]->resized_offset_y = resized_offset_y;
        fmgr_image_cache_p->image_handle_list[handle_idx]->resized_width = resized_width;
        fmgr_image_cache_p->image_handle_list[handle_idx]->resized_height = resized_height;
        fmgr_image_cache_p->image_handle_list[handle_idx]->box_offset_x = box_offset_x;
        fmgr_image_cache_p->image_handle_list[handle_idx]->box_offset_y = box_offset_y;
        fmgr_image_cache_p->image_handle_list[handle_idx]->box_width = box_width;
        fmgr_image_cache_p->image_handle_list[handle_idx]->box_height = box_height;
        fmgr_image_cache_p->image_handle_list[handle_idx]->icon_offset_x = icon_offset_x;
        fmgr_image_cache_p->image_handle_list[handle_idx]->icon_offset_y = icon_offset_y;
        fmgr_image_cache_p->image_handle_list[handle_idx]->icon_width = icon_width;
        fmgr_image_cache_p->image_handle_list[handle_idx]->icon_height = icon_height;
        fmgr_image_cache_p->image_handle_list[handle_idx]->icon_ptr = icon_ptr;
        fmgr_image_cache_p->image_handle_list[handle_idx]->menuitem_idx = (U16) item_idx;
        fmgr_image_cache_p->image_handle_list[handle_idx]->is_hilighted = is_hilighted;
        fmgr_image_cache_p->image_handle_list[handle_idx]->ui_style = ui_style;
    }
    else
    {
        fmgr_p->file_cache[item_idx - fmgr_p->cache_start_idx].is_able_display = FALSE;
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    }

    gdi_layer_pop_clip();
    return;

}
#endif /* defined(FMGR_USING_CACHE) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_show_thumb_image
 * DESCRIPTION
 *  show thumb image
 * PARAMETERS
 *  item_idx                [IN]        Item index
 *  menuitem_offset_x       [IN]        Menu item's offset x
 *  menuitem_offset_y       [IN]        Menu item's offset y
 *  box_offset_x            [IN]        Image box offset x
 *  box_offset_y            [IN]        Image box offset y
 *  box_width               [IN]        Image box width
 *  box_height              [IN]        Image box height
 *  icon_ptr                [IN]        Icon's image ptr
 *  is_hilighted            [IN]        Is highlight flag
 *  ui_style                [IN]        
 * RETURNS
 * BOOL
 *****************************************************************************/
static BOOL mmi_fmgr_show_thumb_image(
                S32 item_idx,
                S32 menuitem_offset_x,
                S32 menuitem_offset_y,
                S32 box_offset_x,
                S32 box_offset_y,
                S32 box_width,
                S32 box_height,
                PU8 icon_ptr,
                BOOL is_hilighted,
                U16 ui_style)
{
#if defined(FMGR_USING_CACHE)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT file_info;
    BOOL is_image_in_cache;
    S32 icon_offset_x, icon_offset_y;
    S32 icon_width, icon_height;
    S32 cache_index;
    S32 draw_pos_x, draw_pos_y;
    S32 i;
    gdi_color bg_color = GDI_COLOR_BLACK;
    color *color_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* create jpeg decoder */
    if (!fmgr_p->is_decoder_create)
    {
        /* max image size is 100x100 */
        gdi_image_decoder_create(100, 100, mmi_fmgr_decode_thumb_image_result_hdlr);
        fmgr_p->is_decoder_create = TRUE;
    }

    gdi_layer_push_clip();
    gdi_layer_reset_clip();

    gdi_image_get_dimension((PU8) icon_ptr, &icon_width, &icon_height);

    icon_offset_x = ((box_width - icon_width) >> 1) + menuitem_offset_x + box_offset_x;
    icon_offset_y = ((box_height - icon_height) >> 1) + menuitem_offset_y + box_offset_y;

    box_offset_x += menuitem_offset_x;
    box_offset_y += menuitem_offset_y;

    /* if is corrupted file, show as icon */
    if (fmgr_p->file_cache[item_idx - fmgr_p->cache_start_idx].is_able_display == FALSE)
    {
        if (is_hilighted)
        {
            gdi_image_draw(icon_offset_x, icon_offset_y, icon_ptr);
        }
        else
        {
            gdi_image_draw(icon_offset_x, icon_offset_y, icon_ptr);
        }

        /* corrupted file */
        gdi_layer_pop_clip();
        return FALSE;
    }

    /* get file info */
    mmi_fmgr_kernel_get_file_info((U16) (item_idx), &file_info);

    /* test if is in the cache */
    is_image_in_cache = FALSE;

    for (cache_index = 0; cache_index < fmgr_image_cache_p->image_cache_item_count; cache_index++)
    {
        if ((fmgr_image_cache_p->image_cache_list[cache_index]->is_used == TRUE) &&
            (fmgr_image_cache_p->image_cache_list[cache_index]->menuitem_idx == item_idx))
        {
            is_image_in_cache = TRUE;
            break;
        }
    }

    /* if can find image in cache, draw it from cache */
    if (is_image_in_cache == TRUE)
    {
        if (ui_style == FMGR_UI_MATRIX_STYLE)
        {
            draw_pos_x = box_offset_x + fmgr_image_cache_p->image_cache_list[cache_index]->resized_offset_x + 2;
            draw_pos_y = box_offset_y + fmgr_image_cache_p->image_cache_list[cache_index]->resized_offset_y + 2;

            /* draw frame */
            gdi_draw_rect(
                draw_pos_x - 1,
                draw_pos_y - 1,
                draw_pos_x + fmgr_image_cache_p->image_cache_list[cache_index]->resized_width,
                draw_pos_y + fmgr_image_cache_p->image_cache_list[cache_index]->resized_height,
                GDI_COLOR_BLACK);

            gdi_image_cache_bmp_draw(draw_pos_x, draw_pos_y, &fmgr_image_cache_p->image_cache_list[cache_index]->bmp);

        }
        else
        {
            draw_pos_x = box_offset_x + fmgr_image_cache_p->image_cache_list[cache_index]->resized_offset_x + 1;
            draw_pos_y = box_offset_y + fmgr_image_cache_p->image_cache_list[cache_index]->resized_offset_y + 1;

            /* draw frame */
            gdi_draw_rect(
                draw_pos_x - 1,
                draw_pos_y - 1,
                draw_pos_x + fmgr_image_cache_p->image_cache_list[cache_index]->resized_width,
                draw_pos_y + fmgr_image_cache_p->image_cache_list[cache_index]->resized_height,
                GDI_COLOR_BLACK);

            gdi_image_cache_bmp_draw(draw_pos_x, draw_pos_y, &fmgr_image_cache_p->image_cache_list[cache_index]->bmp);
        }

        /* make other unused duration increase one */
        for (i = 0; i < fmgr_image_cache_p->image_cache_item_count; i++)
        {
            fmgr_image_cache_p->image_cache_list[i]->unused_duration++;
        }

        fmgr_image_cache_p->image_cache_list[cache_index]->unused_duration = 0;

    }
    else
    {
        /* not in cache */
        if (ui_style == FMGR_UI_LIST_STYLE)
        {
            /* get color from theme */
            if (is_hilighted)
            {
                color_ptr = &(current_MMI_theme->list_selected_item_filler->c);
                bg_color = gdi_act_color_from_rgb(255,color_ptr->r, color_ptr->g, color_ptr->b);
            }
            else
            {
            #if defined(__MMI_WALLPAPER_ON_BOTTOM__) || defined(__MMI_UI_LIST_CACHE_BACKGROUND__)
                bg_color = GDI_COLOR_TRANSPARENT;
            #else /* defined(__MMI_WALLPAPER_ON_BOTTOM__) || defined(__MMI_UI_LIST_CACHE_BACKGROUND__) */ /* __MMI_MAINLCD_240X320__ */
                color_ptr = &(current_MMI_theme->list_background_filler->c);
                bg_color = gdi_act_color_from_rgb(255,color_ptr->r, color_ptr->g, color_ptr->b);
            #endif /* defined(__MMI_WALLPAPER_ON_BOTTOM__) || defined(__MMI_UI_LIST_CACHE_BACKGROUND__) */ /* __MMI_MAINLCD_240X320__ */
            }
        }
        else if (ui_style == FMGR_UI_INFO_STYLE)
        {
            /* this bg color is the same in wgui_categories_fmgr.c's RedrawCategory212Screen() */
            bg_color = gdi_act_color_from_rgb(255,255, 255, 255);
        }
        else if (ui_style == FMGR_UI_MATRIX_STYLE)
        {
            if (is_hilighted)
            {
                color_ptr = &(current_MMI_theme->list_selected_item_filler->c);
                bg_color = gdi_act_color_from_rgb(255,color_ptr->r, color_ptr->g, color_ptr->b);
            }
            else
            {
                color_ptr = &(current_MMI_theme->list_background_filler->c);
                bg_color = gdi_act_color_from_rgb(255,color_ptr->r, color_ptr->g, color_ptr->b);
            }
        }

        if (is_hilighted && (ui_style == FMGR_UI_LIST_STYLE))
        {   /* support image highlight only in the list style */
            mmi_fmgr_draw_hilight_menuitem_bg(
                box_offset_x + 1,
                box_offset_y + 1,
                box_offset_x + box_width - 1,
                box_offset_y + box_height - 1);
        }
        else if (ui_style == FMGR_UI_LIST_STYLE)
        {
            gdi_draw_solid_rect(
                box_offset_x + 1,
                box_offset_y + 1,
                box_offset_x + box_width - 1,
                box_offset_y + box_height - 1,
                bg_color);
        }
        else if (ui_style == FMGR_UI_MATRIX_STYLE)
        {
        #ifdef __MMI_MAINLCD_128X128__
            gdi_draw_solid_rect(
                box_offset_x + 1,
                box_offset_y + 1,
                box_offset_x + box_width - 1,
                box_offset_y + box_height - 1,
                bg_color);
        #else
            FillFullTextBackground(
                box_offset_x + 1,
                box_offset_y + 1,
                box_offset_x + box_width - 1,
                box_offset_y + box_height - 1);
        #endif
        }
        else
        {
        #ifdef __MMI_MAINLCD_128X128__
            gdi_draw_solid_rect(
                box_offset_x + 1,
                box_offset_y + 1,
                box_offset_x + box_width - 1,
                box_offset_y + box_height - 1,
                bg_color);
        #else
            FillFullTextBackground(
                box_offset_x + 1,
                box_offset_y + 1,
                box_offset_x + box_width - 1,
                box_offset_y + box_height - 1);
        #endif

        }
        gdi_image_draw(icon_offset_x, icon_offset_y, icon_ptr);

        /* check file name too long, exceed 260 char */
        if ((mmi_ucs2strlen((PS8) fmgr_p->file_path) + mmi_ucs2strlen((PS8) file_info.file_name)) >= 260)
        {
            /* filename too long */
            gdi_layer_pop_clip();
            return FALSE;
        }

        /* Start of Marco for switch case */
#define FMGR_DELAY_DECODER_SWITCH(_idx_)                                                                    \
         case _idx_:                                                                                              \
         {                                                                                                        \
            StartTimer(FMGR_DELAY_DECODE_##_idx_, FMGR_UI_DELAY_DECODE_DURATION, mmi_fmgr_delay_decode_##_idx_##);\
            g_fmgr_context.delay_decoder[##_idx_##].item_idx            = item_idx;                               \
            g_fmgr_context.delay_decoder[##_idx_##].menuitem_offset_x   = menuitem_offset_x;                      \
            g_fmgr_context.delay_decoder[##_idx_##].menuitem_offset_y   = menuitem_offset_y;                      \
            g_fmgr_context.delay_decoder[##_idx_##].box_offset_x        = box_offset_x;                           \
            g_fmgr_context.delay_decoder[##_idx_##].box_offset_y        = box_offset_y;                           \
            g_fmgr_context.delay_decoder[##_idx_##].box_width           = box_width;                              \
            g_fmgr_context.delay_decoder[##_idx_##].box_height          = box_height;                             \
            g_fmgr_context.delay_decoder[##_idx_##].icon_offset_x       = icon_offset_x;                          \
            g_fmgr_context.delay_decoder[##_idx_##].icon_offset_y       = icon_offset_y;                          \
            g_fmgr_context.delay_decoder[##_idx_##].icon_width          = icon_width;                             \
            g_fmgr_context.delay_decoder[##_idx_##].icon_height         = icon_height;                            \
            g_fmgr_context.delay_decoder[##_idx_##].icon_ptr            = icon_ptr;                               \
            g_fmgr_context.delay_decoder[##_idx_##].is_hilighted        = is_hilighted;                           \
            g_fmgr_context.delay_decoder[##_idx_##].ui_style            = ui_style;                               \
            break;                                                                                                \
         }
        /* end of Macro */

        /* start delay decode timer */
        switch (g_fmgr_context.delay_decode_index)
        {
                FMGR_DELAY_DECODER_SWITCH(0);
                FMGR_DELAY_DECODER_SWITCH(1);
                FMGR_DELAY_DECODER_SWITCH(2);
                FMGR_DELAY_DECODER_SWITCH(3);
                FMGR_DELAY_DECODER_SWITCH(4);
                FMGR_DELAY_DECODER_SWITCH(5);
                FMGR_DELAY_DECODER_SWITCH(6);
                FMGR_DELAY_DECODER_SWITCH(7);
                FMGR_DELAY_DECODER_SWITCH(8);
                FMGR_DELAY_DECODER_SWITCH(9);
            default:
                MMI_ASSERT(0);
        }

        g_fmgr_context.delay_decode_index++;

    }

    gui_pop_clip();
#endif /* defined(FMGR_USING_CACHE) */ 

    return TRUE;
}


#if defined(FMGR_USING_CACHE)
void mmi_fmgr_get_fmgr_cache_struct (void** image_cache_list_buffer_p,
                                     void** image_handle_list_buffer_p,
                                     void** image_cache_p,
                                     void** delay_decoder_p)
{
   *image_cache_list_buffer_p = (void*) &image_cache_list_buffer[0];
   *image_handle_list_buffer_p = (void*) &image_handle_list_buffer[0];
   *image_cache_p = (void*) fmgr_image_cache_p;
   *delay_decoder_p = (void*) fmgr_delay_decoder_p;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_decode_thumb_image_result_hdlr
 * DESCRIPTION
 *  decode image result handler
 * PARAMETERS
 *  decode_result       [IN]        Return cause
 *  handle              [IN]        Image's handle
 * RETURNS
 *  void
 * BOOL
 *****************************************************************************/
static void mmi_fmgr_decode_thumb_image_result_hdlr(GDI_RESULT decode_result, gdi_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    S32 cache_entry_idx = 0;
    S32 max_unused_duration = 0;
    S32 unused_duration;
    S32 min_seq_number;
    BOOL has_cache_entry;
    gdi_color bg_color = GDI_COLOR_BLACK;
    color *color_ptr;
    S32 image_x1, image_y1, image_x2, image_y2;
    S32 clear_x1, clear_y1, clear_x2, clear_y2; /* previous region need to clear */
    S32 blt_x1, blt_y1, blt_x2, blt_y2;

    fmgr_thumb_image_handle_struct *handle_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if decoder is deinited, ignore the decode result hdlr */
    if (fmgr_p->is_decoder_create == FALSE || g_fmgr_context.decoding_count==0)
    {
        return;
    }

    gui_push_clip();
    gui_reset_clip();

    if (decode_result != GDI_JPEG_SUCCEED)
    {
        for (i = 0; i < FMGR_THUMB_IMAGE_HANDLE_MAX_COUNT; i++)
        {
            if ((fmgr_image_cache_p->image_handle_list[i]->is_used == TRUE) &&
                (fmgr_image_cache_p->image_handle_list[i]->handle == handle))
            {
                /* decode failed */
                handle_ptr = fmgr_image_cache_p->image_handle_list[i];

                if (handle_ptr->ui_style == FMGR_UI_LIST_STYLE)
                {
                    /* get color from theme */
                    if (handle_ptr->is_hilighted)
                    {
                        color_ptr = &(current_MMI_theme->list_selected_item_filler->c);
                        bg_color = gdi_act_color_from_rgb(255,color_ptr->r, color_ptr->g, color_ptr->b);
                    }
                    else
                    {
                    #if defined(__MMI_WALLPAPER_ON_BOTTOM__) || defined(__MMI_UI_LIST_CACHE_BACKGROUND__)
                        bg_color = GDI_COLOR_TRANSPARENT;
                    #else /* defined(__MMI_WALLPAPER_ON_BOTTOM__) || defined(__MMI_UI_LIST_CACHE_BACKGROUND__) */ /* __MMI_MAINLCD_240X320__ */
                        color_ptr = &(current_MMI_theme->list_background_filler->c);
                        bg_color = gdi_act_color_from_rgb(255,color_ptr->r, color_ptr->g, color_ptr->b);
                    #endif /* defined(__MMI_WALLPAPER_ON_BOTTOM__) || defined(__MMI_UI_LIST_CACHE_BACKGROUND__) */ /* __MMI_MAINLCD_240X320__ */
                    }
                }
                else if (handle_ptr->ui_style == FMGR_UI_INFO_STYLE)
                {
                    /* this bg color is the same in wgui_categories_fmgr.c's RedrawCategory212Screen() */
                    bg_color = gdi_act_color_from_rgb(255,255, 255, 255);
                }
                else if (handle_ptr->ui_style == FMGR_UI_MATRIX_STYLE)
                {
                    if (handle_ptr->is_hilighted)
                    {
                        color_ptr = &(current_MMI_theme->list_selected_item_filler->c);
                        bg_color = gdi_act_color_from_rgb(255,color_ptr->r, color_ptr->g, color_ptr->b);
                    }
                    else
                    {
                        color_ptr = &(current_MMI_theme->list_background_filler->c);
                        bg_color = gdi_act_color_from_rgb(255,color_ptr->r, color_ptr->g, color_ptr->b);
                    }
                }
                else
                {
                    MMI_ASSERT(0);
                }


                fmgr_p->file_cache[handle_ptr->menuitem_idx - fmgr_p->cache_start_idx].is_able_display = FALSE;
                fmgr_image_cache_p->image_handle_list[i]->is_used = FALSE;

            #ifdef __MMI_MAINLCD_128X128__
                gdi_draw_solid_rect(fmgr_image_cache_p->image_handle_list[i]->draw_pos_x,
                                    fmgr_image_cache_p->image_handle_list[i]->draw_pos_y,
                                    fmgr_image_cache_p->image_handle_list[i]->draw_pos_x + fmgr_image_cache_p->image_handle_list[i]->resized_width,
                                    fmgr_image_cache_p->image_handle_list[i]->draw_pos_y + fmgr_image_cache_p->image_handle_list[i]->resized_height,
                                    bg_color);
            #else
                FillFullTextBackground(fmgr_image_cache_p->image_handle_list[i]->draw_pos_x,
                                       fmgr_image_cache_p->image_handle_list[i]->draw_pos_y,
                                       fmgr_image_cache_p->image_handle_list[i]->draw_pos_x + fmgr_image_cache_p->image_handle_list[i]->resized_width,
                                       fmgr_image_cache_p->image_handle_list[i]->draw_pos_y + fmgr_image_cache_p->image_handle_list[i]->resized_height);
            #endif

                gdi_image_draw(fmgr_image_cache_p->image_handle_list[i]->icon_offset_x,
                               fmgr_image_cache_p->image_handle_list[i]->icon_offset_y,
                               fmgr_image_cache_p->image_handle_list[i]->icon_ptr);                
                break;  /* break the loop */
            }
        }
    }
    else
    {
        for (i = 0; i < FMGR_THUMB_IMAGE_HANDLE_MAX_COUNT; i++)
        {
            if ((fmgr_image_cache_p->image_handle_list[i]->is_used == TRUE) &&
                (fmgr_image_cache_p->image_handle_list[i]->handle == handle))
            {
                /* 
                 * decode success,
                 * (1) Stop animated icon
                 * (1) Wipe out icon by backgroup color.
                 * (2) Draw photo frame.
                 * (3) Find an oldest image cache, and cache the image. 
                 */

                handle_ptr = fmgr_image_cache_p->image_handle_list[i];

                image_x1 = handle_ptr->draw_pos_x;
                image_y1 = handle_ptr->draw_pos_y;
                image_x2 = handle_ptr->draw_pos_x + handle_ptr->resized_width - 1;
                image_y2 = handle_ptr->draw_pos_y + handle_ptr->resized_height - 1;

                /* clear icon by bg color */
                /* since photo is already draw, only draw region not coverd by photo */
                if ((handle_ptr->ui_style == FMGR_UI_LIST_STYLE) || (handle_ptr->ui_style == FMGR_UI_INFO_STYLE))
                {
                    clear_x1 = handle_ptr->icon_offset_x;
                    clear_y1 = handle_ptr->icon_offset_y;
                    clear_x2 = handle_ptr->icon_offset_x + handle_ptr->icon_width - 1;
                    clear_y2 = handle_ptr->icon_offset_y + handle_ptr->icon_height - 1;
                }
                else    /* matrix */
                {
                    clear_x1 = handle_ptr->box_offset_x;
                    clear_y1 = handle_ptr->box_offset_y;
                    clear_x2 = handle_ptr->box_offset_x + handle_ptr->box_width - 1;
                    clear_y2 = handle_ptr->box_offset_y + handle_ptr->box_height - 1;
                }

                /* stop animated icon */
                //                              if(handle_ptr->is_hilighted)
                //                              {
                //                                      gdi_image_stop_animation_all();
                //                              }

                /* clear icon by bg color */
                /* since photo is already draw, only draw region not coverd by photo */
                if (handle_ptr->ui_style == FMGR_UI_LIST_STYLE)
                {
                    /* get color from theme */
                    if (handle_ptr->is_hilighted)
                    {
                        color_ptr = &(current_MMI_theme->list_selected_item_filler->c);
                        bg_color = gdi_act_color_from_rgb(255,color_ptr->r, color_ptr->g, color_ptr->b);
                    }
                    else
                    {
                    #if defined(__MMI_WALLPAPER_ON_BOTTOM__) || defined(__MMI_UI_LIST_CACHE_BACKGROUND__)
                        bg_color = GDI_COLOR_TRANSPARENT;
                    #else /* defined(__MMI_WALLPAPER_ON_BOTTOM__) || defined(__MMI_UI_LIST_CACHE_BACKGROUND__) */ /* __MMI_MAINLCD_240X320__ */
                        color_ptr = &(current_MMI_theme->list_background_filler->c);
                        bg_color = gdi_act_color_from_rgb(255,color_ptr->r, color_ptr->g, color_ptr->b);
                    #endif /* defined(__MMI_WALLPAPER_ON_BOTTOM__) || defined(__MMI_UI_LIST_CACHE_BACKGROUND__) */ /* __MMI_MAINLCD_240X320__ */
                    }
                }
                else if (handle_ptr->ui_style == FMGR_UI_INFO_STYLE)
                {
                    /* this bg color is the same in wgui_categories_fmgr.c's RedrawCategory212Screen() */
                    bg_color = gdi_act_color_from_rgb(255,255, 255, 255);
                }
                else if (handle_ptr->ui_style == FMGR_UI_MATRIX_STYLE)
                {
                    if (handle_ptr->is_hilighted)
                    {
                        color_ptr = &(current_MMI_theme->list_selected_item_filler->c);
                        bg_color = gdi_act_color_from_rgb(255,color_ptr->r, color_ptr->g, color_ptr->b);
                    }
                    else
                    {
                        color_ptr = &(current_MMI_theme->list_background_filler->c);
                        bg_color = gdi_act_color_from_rgb(255,color_ptr->r, color_ptr->g, color_ptr->b);
                    }
                }
                else
                {
                    MMI_ASSERT(0);
                }

                /* left region */
                if (clear_x1 < image_x1 - 1)
                {
                    if (handle_ptr->is_hilighted && (handle_ptr->ui_style == FMGR_UI_LIST_STYLE))
                    {   /* support image highlight only in the list style */
                        mmi_fmgr_draw_hilight_menuitem_bg(clear_x1, clear_y1, image_x1 - 1, clear_y2);
                    }
                    else if (handle_ptr->ui_style == FMGR_UI_LIST_STYLE)
                    {
                        gdi_draw_solid_rect(clear_x1, clear_y1, image_x1 - 1, clear_y2, bg_color);                    
                    }
                    else if (handle_ptr->ui_style == FMGR_UI_MATRIX_STYLE)
                    {
                    #ifdef __MMI_MAINLCD_128X128__
                        gdi_draw_solid_rect(clear_x1, clear_y1, image_x1 - 1, clear_y2, bg_color);
                    #else
                        FillFullTextBackground(clear_x1, clear_y1, image_x1 - 1, clear_y2);
                    #endif
                    }
                    else 
                    {                
                    #ifdef __MMI_MAINLCD_128X128__
                        gdi_draw_solid_rect(clear_x1, clear_y1, image_x1 - 1, clear_y2, bg_color);
                    #else
                        FillFullTextBackground(clear_x1, clear_y1, image_x1 - 1, clear_y2);
                    #endif
                    }
                }

                /* right region */
                if (clear_x2 > image_x2 + 1)
                {
                    if (handle_ptr->is_hilighted && (handle_ptr->ui_style == FMGR_UI_LIST_STYLE))
                    {   /* support image highlight only in the list style */
                        mmi_fmgr_draw_hilight_menuitem_bg(image_x2 + 1, clear_y1, clear_x2, clear_y2);
                    }
                    else if (handle_ptr->ui_style == FMGR_UI_LIST_STYLE)
                    {
                        gdi_draw_solid_rect(image_x2 + 1, clear_y1, clear_x2, clear_y2, bg_color);                    
                    }
                    else if (handle_ptr->ui_style == FMGR_UI_MATRIX_STYLE)
                    {
                    #ifdef __MMI_MAINLCD_128X128__
                        gdi_draw_solid_rect(image_x2 + 1, clear_y1, clear_x2, clear_y2, bg_color);
                    #else
                        FillFullTextBackground(image_x2 + 1, clear_y1, clear_x2, clear_y2);
                    #endif
                    }
                    else
                    {                
                    #ifdef __MMI_MAINLCD_128X128__
                        gdi_draw_solid_rect(image_x2 + 1, clear_y1, clear_x2, clear_y2, bg_color);
                    #else
                        FillFullTextBackground(image_x2 + 1, clear_y1, clear_x2, clear_y2);
                    #endif
                    }
                }

                /* up region */
                if (clear_y1 < image_y1 - 1)
                {
                    if (handle_ptr->is_hilighted && (handle_ptr->ui_style == FMGR_UI_LIST_STYLE))
                    {   /* support image highlight only in the list style */
                        mmi_fmgr_draw_hilight_menuitem_bg(clear_x1, clear_y1, clear_x2, image_y1 - 1);
                    }
                    else if (handle_ptr->ui_style == FMGR_UI_LIST_STYLE)
                    {
                        gdi_draw_solid_rect(clear_x1, clear_y1, clear_x2, image_y1 - 1, bg_color);                    
                    }
                    else if (handle_ptr->ui_style == FMGR_UI_MATRIX_STYLE)
                    {
                    #ifdef __MMI_MAINLCD_128X128__
                        gdi_draw_solid_rect(clear_x1, clear_y1, clear_x2, image_y1 - 1, bg_color);
                    #else
                        FillFullTextBackground(clear_x1, clear_y1, clear_x2, image_y1 - 1);
                    #endif
                    }
                    else
                    {
                    #ifdef __MMI_MAINLCD_128X128__
                        gdi_draw_solid_rect(clear_x1, clear_y1, clear_x2, image_y1 - 1, bg_color);
                    #else
                        FillFullTextBackground(clear_x1, clear_y1, clear_x2, image_y1 - 1);
                    #endif
                    }
                }

                /* down region */
                if (clear_y2 > image_y2 + 1)
                {
                    if (handle_ptr->is_hilighted && (handle_ptr->ui_style == FMGR_UI_LIST_STYLE))
                    {   /* support image highlight only in the list style */
                        mmi_fmgr_draw_hilight_menuitem_bg(clear_x1, image_y2 + 1, clear_x2, clear_y2);
                    }
                    else if (handle_ptr->ui_style == FMGR_UI_LIST_STYLE)
                    {
                        gdi_draw_solid_rect(clear_x1, image_y2 + 1, clear_x2, clear_y2, bg_color);                    
                    }
                    else if (handle_ptr->ui_style == FMGR_UI_MATRIX_STYLE)
                    {
                    #ifdef __MMI_MAINLCD_128X128__
                        gdi_draw_solid_rect(clear_x1, image_y2 + 1, clear_x2, clear_y2, bg_color);
                    #else
                        FillFullTextBackground(clear_x1, image_y2 + 1, clear_x2, clear_y2);
                    #endif
                    }
                    else
                    {
                    #ifdef __MMI_MAINLCD_128X128__
                        gdi_draw_solid_rect(clear_x1, image_y2 + 1, clear_x2, clear_y2, bg_color);
                    #else
                        FillFullTextBackground(clear_x1, image_y2 + 1, clear_x2, clear_y2);
                    #endif
                    }
                }

                /* draw frame */
                gdi_draw_rect(image_x1 - 1, image_y1 - 1, image_x2 + 1, image_y2 + 1, GDI_COLOR_BLACK);

                if (handle_ptr->ui_style == FMGR_UI_MATRIX_STYLE)
                {
                    /* 2 pixels . 1 for border, 1 for spacing */
                    blt_x1 = (image_x1 - 2 > clear_x1) ? clear_x1 : image_x1 - 2;
                    blt_y1 = (image_y1 - 2 > clear_y1) ? clear_y1 : image_y1 - 2;
                    blt_x2 = (image_x2 + 2 > clear_x2) ? image_x2 + 2 : clear_x2;
                    blt_y2 = (image_y2 + 2 > clear_y2) ? image_y2 + 2 : clear_y2;
                }
                else
                {
                    /* calc max blt region (+1 for photo frame) */
                    blt_x1 = (image_x1 - 1 > clear_x1) ? clear_x1 : image_x1 - 1;
                    blt_y1 = (image_y1 - 1 > clear_y1) ? clear_y1 : image_y1 - 1;
                    blt_x2 = (image_x2 + 1 > clear_x2) ? image_x2 + 1 : clear_x2;
                    blt_y2 = (image_y2 + 1 > clear_y2) ? image_y2 + 1 : clear_y2;
                }

                gdi_layer_blt_previous(blt_x1, blt_y1, blt_x2, blt_y2);

                /* check if has valid cache index */
                has_cache_entry = FALSE;
                for (j = 0; j < fmgr_image_cache_p->image_cache_item_count; j++)
                {
                    if (fmgr_image_cache_p->image_cache_list[j]->is_used == FALSE)
                    {
                        has_cache_entry = TRUE;
                        cache_entry_idx = j;
                        break;
                    }
                }

                /* if not in cache, we will replace the oldest one in cache */
                if (!has_cache_entry)
                {
                    /* find max unused counter */
                    max_unused_duration = 0;
                    for (j = 0; j < fmgr_image_cache_p->image_cache_item_count; j++)
                    {
                        if (fmgr_image_cache_p->image_cache_list[j]->is_used == TRUE)
                        {
                            unused_duration = fmgr_image_cache_p->image_cache_list[j]->unused_duration;
                            max_unused_duration =
                                (max_unused_duration > unused_duration) ? max_unused_duration : unused_duration;
                        }
                    }

                    min_seq_number = 65535;
                    /* find the one with max unused duration will the smallest decode seq number */
                    for (j = 0; j < fmgr_image_cache_p->image_cache_item_count; j++)
                    {
                        if ((fmgr_image_cache_p->image_cache_list[j]->is_used == TRUE) &&
                            (fmgr_image_cache_p->image_cache_list[j]->unused_duration == max_unused_duration))
                        {
                            /* find the one with smallest seq number, which means is the oldest */
                            if (fmgr_image_cache_p->image_cache_list[j]->seq_number < min_seq_number)
                            {
                                cache_entry_idx = j;
                                min_seq_number = fmgr_image_cache_p->image_cache_list[j]->seq_number;
                            }
                        }
                    }
                }

                /* increase decode seq number */
                if (fmgr_image_cache_p->image_decode_seq_num >= 65534)
                {
                    fmgr_image_cache_p->image_decode_seq_num = 0;
                }
                else
                {
                    fmgr_image_cache_p->image_decode_seq_num++;
                }

                gdi_image_cache_bmp_get(
                    handle_ptr->draw_pos_x,
                    handle_ptr->draw_pos_y,
                    handle_ptr->draw_pos_x + handle_ptr->resized_width - 1,
                    handle_ptr->draw_pos_y + handle_ptr->resized_height - 1,
                    &fmgr_image_cache_p->image_cache_list[cache_entry_idx]->bmp);

                fmgr_image_cache_p->image_cache_list[cache_entry_idx]->is_used = TRUE;
                fmgr_image_cache_p->image_cache_list[cache_entry_idx]->unused_duration = 0;
                fmgr_image_cache_p->image_cache_list[cache_entry_idx]->menuitem_idx = handle_ptr->menuitem_idx;
                fmgr_image_cache_p->image_cache_list[cache_entry_idx]->resized_offset_x = handle_ptr->resized_offset_x;
                fmgr_image_cache_p->image_cache_list[cache_entry_idx]->resized_offset_y = handle_ptr->resized_offset_y;
                fmgr_image_cache_p->image_cache_list[cache_entry_idx]->resized_width = handle_ptr->resized_width;
                fmgr_image_cache_p->image_cache_list[cache_entry_idx]->resized_height = handle_ptr->resized_height;
                fmgr_image_cache_p->image_cache_list[cache_entry_idx]->seq_number =
                    fmgr_image_cache_p->image_decode_seq_num;

                fmgr_image_cache_p->image_handle_list[i]->is_used = FALSE;

                break;  /* break the for loop */
            }           /* if */
        }               /* for */
    }                   /* if */
    gui_pop_clip();

    ASSERT(g_fmgr_context.decoding_count>0);

    g_fmgr_context.decoding_count--;

    /* check if background decoding finish: unlock wgui status icon*/
    if(g_fmgr_context.decoding_count==0)
        wgui_status_icon_unlock_redrawing();
}
#endif /* defined(FMGR_USING_CACHE) */ 

/*****************************************************************************
*
* File Manager [UI Drawing]
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_draw_free_space_icon
 * DESCRIPTION
 *  draw free space icon
 * PARAMETERS
 *  box_x1          [IN]        Bounding box offset x
 *  box_y1          [IN]        Bounding box offset y
 *  box_height      [IN]        Bounding box's height
 *  ratio           [IN]        Free space %
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fmgr_draw_free_space_icon(S32 box_x1, S32 box_y1, S32 box_height, U32 ratio)
{
#if defined(__MMI_SLIM_FILE_MANAGER__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x_spacing;
    S32 y_spacing;
    S32 offset_x;
    S32 offset_y;
    S32 width;
    S32 height;
    gdi_color green_start_color;
    gdi_color green_end_color;
    gdi_color red_start_color;
    gdi_color red_end_color;
    S32 green_width;
    S32 red_width;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x_spacing = 2;
    y_spacing = 8;
    offset_x = box_x1 + x_spacing;
    offset_y = box_y1 + y_spacing;
    width = box_height;
    height = box_height - 2 * y_spacing;

    green_width = width * ratio / 10;
    red_width = width - green_width;

    green_start_color = gdi_act_color_from_rgb(255,30, 255, 30);
    green_end_color = gdi_act_color_from_rgb(255,200, 255, 200);

    red_start_color = gdi_act_color_from_rgb(255,255, 30, 30);
    red_end_color = gdi_act_color_from_rgb(255,255, 200, 200);

    gdi_draw_gradient_rect(
        offset_x,
        offset_y,
        offset_x + red_width,
        offset_y + height,
        red_start_color,
        red_end_color,
        GDI_COLOR_BLACK,
        1,
        GDI_GRADIENT_RECT_VER);

    gdi_draw_gradient_rect(
        offset_x + red_width,
        offset_y,
        offset_x + width,
        offset_y + height,
        green_start_color,
        green_end_color,
        GDI_COLOR_BLACK,
        1,
        GDI_GRADIENT_RECT_VER);

#else /* defined(__MMI_SLIM_FILE_MANAGER__) */ 
    PU8 icon_ptr;
    S32 img_width, img_height;
    S32 spacing;

    icon_ptr = (PU8) GetImage((U16) (IMG_ID_FMGR_DRIVE_SPACE_0 + ratio));
    gui_measure_image(icon_ptr, &img_width, &img_height);
    spacing = (box_height - img_height) >> 1;

    gui_show_transparent_image(box_x1, box_y1 + spacing + 1, icon_ptr, 0);

#endif /* defined(__MMI_SLIM_FILE_MANAGER__) */ 
}

/******************************************************************************
* Drv UI related callback
******************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_get_drv_item_callback
 * DESCRIPTION
 *  callback function for getting dynamic list item
 * PARAMETERS
 *  item_idx            [IN]        Index
 *  str_buff            [OUT]       String buffer
 *  img_buff_p          [OUT]       Image buffer ptr
 *  str_img_mask        [IN]        Mask
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_fmgr_get_drv_item_callback(S32 item_idx, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    U16 drv_str_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *img_buff_p = NULL;

    /* TODO: FS_GetDrive */
    if (item_idx > fmgr_p->drv_count)
    {
        return FALSE;
    }

    i = fmgr_get_drive_index(item_idx);

    if (i < 0)  /* device not exist */
    {
        return FALSE;
    }

    switch (i)
    {
        case FMGR_NAND_STORAGE:
            drv_str_id = STR_FMGR_NOR_FLASH;
            break;
        case FMGR_NOR_STORAGE:
            drv_str_id = STR_FMGR_NAND_FLASH;
            break;
    #if defined(__DRM_MTK__)
        case FMGR_DRM_RO_STORAGE:
            drv_str_id = STR_FMGR_DRM_RIGHTS;
            break;
    #endif /* __DRM_MTK__ */ 
        case FMGR_REMOVABLE_STORAGE:
    #ifdef __OTG_ENABLE__
        case FMGR_OTG_1_STORAGE:
        case FMGR_OTG_2_STORAGE:
        case FMGR_OTG_3_STORAGE:
        case FMGR_OTG_4_STORAGE:
    #endif /* __OTG_ENABLE__ */ 
            drv_str_id = STR_FMGR_REM_DEVICE;
            break;
    #ifdef __SIM_PLUS__
        case FMGR_SIM_PLUS_1_STORAGE:
        case FMGR_SIM_PLUS_2_STORAGE:
        case FMGR_SIM_PLUS_3_STORAGE:
        case FMGR_SIM_PLUS_4_STORAGE:            
            drv_str_id = STR_FMGR_SIM_PLUS;
            break;        
    #endif
    #ifdef __MSDC2_SD_MMC__
        case FMGR_MSDC2_SD_STORAGE:
            drv_str_id = STR_FMGR_REM_DEVICE;
            break;
    #endif
        default:
            MMI_ASSERT(0);
            break;
    }

    mmi_ucs2cpy((PS8) str_buff, (PS8) (GetString(drv_str_id)));

    if (i == FMGR_NAND_STORAGE || i == FMGR_NOR_STORAGE
#ifdef __DRM_MTK__
        || i == FMGR_DRM_RO_STORAGE
#endif 
        )
    {
        *img_buff_p = (PU8) GetImage(IMG_ID_FMGR_DRIVE_PHONE);
    }
    else if (i == FMGR_REMOVABLE_STORAGE
#ifdef __OTG_ENABLE__
             || i == FMGR_OTG_1_STORAGE || i == FMGR_OTG_2_STORAGE || i == FMGR_OTG_3_STORAGE || i == FMGR_OTG_4_STORAGE
#endif 
#ifdef __SIM_PLUS__
             || i == FMGR_SIM_PLUS_1_STORAGE || i == FMGR_SIM_PLUS_2_STORAGE || i == FMGR_SIM_PLUS_3_STORAGE || i == FMGR_SIM_PLUS_4_STORAGE
#endif
#ifdef __MSDC2_SD_MMC__
             i == FMGR_MSDC2_SD_STORAGE
#endif
        )
    {
        U8 mask;

        mask = fmgr_get_msdc_mask();
        /* test if card is actually present */
        if (mask & (0x01 << (i - FMGR_REMOVABLE_STORAGE)))
        {
            *img_buff_p = (PU8) GetImage(IMG_ID_FMGR_DRIVE_MEM_CARD);
        }
        else
        {
            return FALSE;
        }
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_get_drv_hint_callback
 * DESCRIPTION
 *  callback function for getting dynamic list hint
 * PARAMETERS
 *  item_idx        [IN]        Index
 *  hint_array      [OUT]       Hint string
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_fmgr_get_drv_hint_callback(S32 item_idx, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_draw_drv_info_callback
 * DESCRIPTION
 *  callback function for draw seleted drv info
 * PARAMETERS
 *  item_idx        [IN]        Index
 *  x1              [IN]        X1 string
 *  y1              [IN]        Y1
 *  x2              [IN]        X2
 *  y2              [IN]        Y2
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_draw_drv_info_callback(S32 item_idx, S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 char_height;
    S8 buffer[128];
    S8 buffer_UCS2[128];
    S8 path[128];
    S8 index;
    S32 str_width, str_height;
    S32 box_width, box_height;
    FS_DiskInfo disk_info;
    S32 fs_ret;
    U64 disk_free_space;
    U64 disk_total_space;
    S32 spacing;
    U32 ratio;
    S32 total_size_str_offset_y;
    S32 free_size_str_offset_y;
    S32 total_size_offset_y;
    S32 free_size_offset_y;
    S32 left_align_offset_x;
    S32 right_align_offset_x;

#if !defined(__MMI_SLIM_FILE_MANAGER__)
    S32 image_width;
    S32 image_height;
#endif /* !defined(__MMI_SLIM_FILE_MANAGER__) */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* lock and push clip */
    gui_lock_double_buffer();
    gui_push_text_clip();
    gui_push_clip();

    gui_reset_clip();
    gui_reset_text_clip();

    index = fmgr_get_drive_index(item_idx);
    mmi_asc_to_ucs2((PS8) path, (PS8) fmgr_p->drv_list[index]);

    /*----------------------------------------------------------------*/
    /* Get Drive info                                                 */
    /*----------------------------------------------------------------*/
    fs_ret = FS_GetDiskInfo((PU16) path, &disk_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);

    disk_free_space = 0;
    disk_total_space = 0;
    ratio = 0;

    if (fs_ret >= 0)
    {
        disk_free_space = (U64)disk_info.FreeClusters * disk_info.SectorsPerCluster * disk_info.BytesPerSector;
        disk_total_space = (U64)disk_info.TotalClusters * disk_info.SectorsPerCluster * disk_info.BytesPerSector;

        if (disk_info.TotalClusters > 0)
        {
            ratio = (U32) (disk_info.FreeClusters * 100 / disk_info.TotalClusters);
            ratio += 5;
            ratio /= 10;

            if (ratio > 10)
            {
                ratio = 0;
            }
        }
    }

    /*----------------------------------------------------------------*/
    /* Calcuate text position                                         */
    /*----------------------------------------------------------------*/
    box_height = y2 - y1 + 1;
    box_width = x2 - x1 + 1;

    gui_set_font(&MMI_medium_font);
    char_height = gui_get_string_height((UI_string_type) GetString(STR_ID_FMGR_DRV_FREE_SPACE));
    spacing = (box_height - char_height * 2) / 3;

    total_size_str_offset_y = spacing + MMI_title_height + MMI_title_y + 1;     /* +1 make it looks better */
    free_size_str_offset_y = spacing * 2 + char_height + MMI_title_height + MMI_title_y + 1;    /* +1 make it looks better */

    char_height = gui_get_string_height((UI_string_type) L"1");
    spacing = (box_height - char_height * 2) / 3;

    total_size_offset_y = spacing + MMI_title_height + MMI_title_y + 1; /* +1 make it looks better */
    free_size_offset_y = spacing * 2 + char_height + MMI_title_height + MMI_title_y + 1;        /* +1 make it looks better */

#if !defined(__MMI_SLIM_FILE_MANAGER__)
    gdi_image_get_dimension_id(IMG_ID_FMGR_DRIVE_SPACE_0, &image_width, &image_height);

    left_align_offset_x = x1 + image_width + 8;
    right_align_offset_x = x2 - image_width - 8;
#else /* !defined(__MMI_SLIM_FILE_MANAGER__) */ 
    left_align_offset_x = x1 + box_height + 8;
    right_align_offset_x = x2 - box_height - 8;
#endif /* !defined(__MMI_SLIM_FILE_MANAGER__) */ 

    /*----------------------------------------------------------------*/
    /* Draw Total Size                                                */
    /*----------------------------------------------------------------*/
    gui_reset_text_clip();
    gui_set_text_color(gui_color(0, 0, 0));

    if (r2lMMIFlag)
    {
        gui_move_text_cursor(right_align_offset_x, total_size_str_offset_y);
    }
    else
    {
        gui_move_text_cursor(left_align_offset_x, total_size_str_offset_y);
    }

    gui_print_text((UI_string_type) GetString(STR_ID_FMGR_DRV_TOTAL_SPACE));

    if (disk_total_space > 1024 * 1024 * 10)
    {
        sprintf(buffer, " %dM", (U16) (disk_total_space / (1024 * 1024)));
    }
    else
    {
        sprintf(buffer, " %dK", (U16) (disk_total_space / (1024)));
    }

    mmi_asc_to_ucs2(buffer_UCS2, buffer);
    gui_measure_string((UI_string_type) buffer_UCS2, &str_width, &str_height);

    if (r2lMMIFlag)
    {
        gui_move_text_cursor(x1 + str_width + 4, total_size_offset_y);
    }
    else
    {
        gui_move_text_cursor(x2 - str_width - 4, total_size_offset_y);
    }

    gui_print_text((UI_string_type) buffer_UCS2);

    /*----------------------------------------------------------------*/
    /* Draw Free Size                                                 */
    /*----------------------------------------------------------------*/
    if (r2lMMIFlag)
    {
        gui_move_text_cursor(right_align_offset_x, free_size_str_offset_y);
    }
    else
    {
        gui_move_text_cursor(left_align_offset_x, free_size_str_offset_y);
    }

    gui_print_text((UI_string_type) GetString(STR_ID_FMGR_DRV_FREE_SPACE));

    if (disk_free_space > 1024 * 1024 * 10)
    {
        sprintf(buffer, " %dM", (U16) (disk_free_space / (1024 * 1024)));
    }
    else
    {
        sprintf(buffer, " %dK", (U16) (disk_free_space / (1024)));
    }

    mmi_asc_to_ucs2(buffer_UCS2, buffer);
    gui_measure_string((UI_string_type) buffer_UCS2, &str_width, &str_height);

    if (r2lMMIFlag)
    {
        gui_move_text_cursor(x1 + str_width + 4, free_size_offset_y);
    }
    else
    {
        gui_move_text_cursor(x2 - str_width - 4, free_size_offset_y);
    }

    gui_print_text((UI_string_type) buffer_UCS2);

    /*----------------------------------------------------------------*/
    /* Draw Icon                                                      */
    /*----------------------------------------------------------------*/
    if (r2lMMIFlag)
    {
        mmi_fmgr_draw_free_space_icon(right_align_offset_x + 4, y1, box_height, ratio);
    }
    else
    {
        mmi_fmgr_draw_free_space_icon(x1 + 4, y1, box_height, ratio);
    }

    /* pop clip , unlock and blt */
    gui_pop_clip();
    gui_pop_text_clip();
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_hide_drv_info_callback
 * DESCRIPTION
 *  callback function for stop draw seleted drv info
 *  this shall be called to stop animation, timer or non-blocking decoder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_hide_drv_info_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_draw_drv_menuitem_callback
 * DESCRIPTION
 *  draw drv menitem callback function
 * PARAMETERS
 *  item_idx            [IN]        Index
 *  is_hilighted        [IN]        Hilight flag
 *  x1                  [IN]        X1
 *  y1                  [IN]        Y1
 *  x2                  [IN]        X2
 *  y2                  [IN]        Y2
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_draw_drv_menuitem_callback(S32 item_idx, BOOL is_hilighted, S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_DiskInfo disk_info;
    S32 fs_ret;
    U64 disk_free_space;
    U64 disk_total_space;
    U32 ratio;
    S32 left_align_offset_x;
    S32 right_align_offset_x;
    S8 buffer[128];
    S8 buffer_UCS2[128];
    S32 str_width, str_height;
    S32 small_font_height;
    S32 medium_font_height;
    S32 menuitem_height;
    S32 text_spacing;
    S32 drv_name_offset_y;
    S32 date_size_offset_y;
    color text_color;
    color text_shadow_color;
    S32 text_box_y1;
    S32 text_box_y2;
    S32 drv_index;
    U16 drv_str_id;

#if !defined(__MMI_SLIM_FILE_MANAGER__)
    S32 image_width;
    S32 image_height;
#endif /* !defined(__MMI_SLIM_FILE_MANAGER__) */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* lock and push clip */
    gui_lock_double_buffer();
    gui_push_text_clip();
    gui_push_clip();

    gui_reset_clip();
    gui_reset_text_clip();

    drv_index = fmgr_get_drive_index(item_idx);
    mmi_asc_to_ucs2((PS8) buffer_UCS2, (PS8) fmgr_p->drv_list[drv_index]);

    ASSERT(drv_index >= 0); /* device must exist */

    /*----------------------------------------------------------------*/
    /* Get Drive info                                                 */
    /*----------------------------------------------------------------*/
    fs_ret = FS_GetDiskInfo((PU16) buffer_UCS2, &disk_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);

    disk_free_space = 0;
    disk_total_space = 0;
    ratio = 0;

    if (fs_ret >= 0)
    {
        disk_free_space = disk_info.FreeClusters * disk_info.SectorsPerCluster * disk_info.BytesPerSector;
        disk_total_space = disk_info.TotalClusters * disk_info.SectorsPerCluster * disk_info.BytesPerSector;

        if (disk_info.TotalClusters > 0)
        {
            ratio = (U32) (disk_info.FreeClusters * 100 / disk_info.TotalClusters);
            ratio += 5;
            ratio /= 10;

            if (ratio > 10)
            {
                ratio = 0;
            }
        }
    }

    switch (drv_index)
    {
        case FMGR_NAND_STORAGE:
            drv_str_id = STR_FMGR_NOR_FLASH;
            break;
        case FMGR_NOR_STORAGE:
            drv_str_id = STR_FMGR_NAND_FLASH;
            break;
    #if defined(__DRM_MTK__)
        case FMGR_DRM_RO_STORAGE:
            drv_str_id = STR_FMGR_DRM_RIGHTS;
            break;
    #endif /* defined(__DRM_MTK__)*/ 
        case FMGR_REMOVABLE_STORAGE:
    #ifdef __OTG_ENABLE__
        case FMGR_OTG_1_STORAGE:
        case FMGR_OTG_2_STORAGE:
        case FMGR_OTG_3_STORAGE:
        case FMGR_OTG_4_STORAGE:
    #endif /* __OTG_ENABLE__ */ 
    #ifdef __SIM_PLUS__
        case FMGR_SIM_PLUS_1_STORAGE:
        case FMGR_SIM_PLUS_2_STORAGE:
        case FMGR_SIM_PLUS_3_STORAGE:
        case FMGR_SIM_PLUS_4_STORAGE:            
    #endif

    #ifdef __MSDC2_SD_MMC__
        case FMGR_MSDC2_SD_STORAGE:
    #endif
    
            drv_str_id = STR_FMGR_REM_DEVICE;
            break;
        default:
            MMI_ASSERT(0);
            drv_str_id = 0; /* avoid warning */
            break;
    }

    mmi_ucs2cpy((PS8) buffer_UCS2, (PS8) (GetString(drv_str_id)));

    /*----------------------------------------------------------------*/
    /* Calcuate text position                                         */
    /*----------------------------------------------------------------*/
    text_box_y1 = y1 + 3;
    text_box_y2 = y2 - 1;

    menuitem_height = text_box_y2 - text_box_y1 + 1;

    small_font_height = Get_CharHeightOfAllLang(MMI_small_font.size);
    gui_set_font(&MMI_medium_font);
    medium_font_height = Get_CharHeightOfAllLang(MMI_medium_font.size);

    text_spacing = (menuitem_height - medium_font_height - small_font_height) / 3;

    if (text_spacing < 0)
    {
        text_spacing = 0;
    }

#if !defined(__MMI_SLIM_FILE_MANAGER__)
    gdi_image_get_dimension_id(IMG_ID_FMGR_DRIVE_SPACE_0, &image_width, &image_height);

    left_align_offset_x = x1 + (image_width) + 8;
    right_align_offset_x = x2 - (image_width) - 8;
#else /* !defined(__MMI_SLIM_FILE_MANAGER__) */ 
    left_align_offset_x = x1 + (y2 - y1) + 8;
    right_align_offset_x = x2 - (y2 - y1) - 8;
#endif /* !defined(__MMI_SLIM_FILE_MANAGER__) */ 

    drv_name_offset_y = text_box_y1 + text_spacing - 1;
    date_size_offset_y = text_box_y1 + text_spacing * 2 + medium_font_height;

    if (is_hilighted)
    {
        text_color = current_UI_theme->fixed_text_menuitem_theme->selected_text_color;
        text_shadow_color = current_UI_theme->fixed_text_menuitem_theme->normal_text_color;
    }
    else
    {
        text_color = current_UI_theme->fixed_text_menuitem_theme->normal_text_color;
        text_shadow_color = current_UI_theme->fixed_text_menuitem_theme->selected_text_color;
    }

    /*----------------------------------------------------------------*/
    /* Draw Drvie Name                                                */
    /*----------------------------------------------------------------*/
    gui_set_font(&MMI_medium_font);

    /* set text clip, avoid draw to overlap scroll bar */
    if (r2lMMIFlag)
    {
        gui_set_text_clip(x1 + 1, y1, right_align_offset_x, y2);
    }
    else
    {
        gui_set_text_clip(left_align_offset_x, y1, x2 - 1, y2);
    }

    gui_set_text_color(text_shadow_color);

    if (is_hilighted)
    {
        /* scrolling text has to be stored in global variable */
        /* we use new_file_name buffer since it is not used in this scenario */
        mmi_ucs2cpy((PS8) fmgr_p->new_file_name, (PS8) buffer_UCS2);

        if (r2lMMIFlag)
        {
            gui_create_scrolling_text(
                &fmgr_p->scroll_text,
                x1 ,                                 /* x */
                drv_name_offset_y ,                           /* y */
                right_align_offset_x - x1 ,                            /* width */
                medium_font_height ,                     /* height */
                (UI_string_type) fmgr_p->new_file_name,     /* string */
                mmi_fmgr_draw_hilight_menuitem_timer_callback,    /* timer hdlr */
                mmi_fmgr_draw_hilight_menuitem_bg_callback, /* draw background hdlr */
                text_color,                                 /* text color */
                MMI_fixed_icontext_menuitem.selected_filler->c);     /* bg */
        }
        else
        {
            gui_create_scrolling_text(
                &fmgr_p->scroll_text,
                left_align_offset_x,                        /* x */
                drv_name_offset_y ,                          /* y */
                x2 - left_align_offset_x - 1,               /* width */
                medium_font_height ,                     /* height */
                (UI_string_type) fmgr_p->new_file_name,     /* string */
                mmi_fmgr_draw_hilight_menuitem_timer_callback,    /* timer hdlr */
                mmi_fmgr_draw_hilight_menuitem_bg_callback, /* draw background hdlr */
                text_color,                                 /* text color */
                MMI_fixed_icontext_menuitem.selected_filler->c);     /* bg */
        }
        fmgr_p->scroll_text.text_font = MMI_medium_font;
        gui_show_scrolling_text(&fmgr_p->scroll_text);

    }
    else
    {
        gui_set_text_color(text_color);

        if (r2lMMIFlag)
        {
            gui_move_text_cursor(right_align_offset_x, drv_name_offset_y);
        }
        else
        {
            gui_move_text_cursor(left_align_offset_x, drv_name_offset_y);
        }

        gui_print_text((UI_string_type) buffer_UCS2);
    }
    /*----------------------------------------------------------------*/
    /* Draw Drv Size                                                  */
    /*----------------------------------------------------------------*/
    gui_reset_text_clip();
    gui_set_text_color(text_color);
    gui_set_font(&MMI_small_font);

    if (disk_free_space > 1024 * 1024 * 10)
    {
        sprintf(buffer, "%dM/", (U16) (disk_free_space / (1024 * 1024)));
    }
    else
    {
        sprintf(buffer, "%dK/", (U16) (disk_free_space / (1024)));
    }

    if (disk_total_space > 1024 * 1024 * 10)
    {
        sprintf(buffer_UCS2, "%dM", (U16) (disk_total_space / (1024 * 1024)));
    }
    else
    {
        sprintf(buffer_UCS2, "%dK", (U16) (disk_total_space / (1024)));
    }

    strcat(buffer, buffer_UCS2);

    mmi_asc_to_ucs2((PS8) buffer_UCS2, (PS8) buffer);
    gui_measure_string((UI_string_type) buffer_UCS2, &str_width, &str_height);

    if (r2lMMIFlag)
    {
        gui_move_text_cursor(x1 + str_width + 4, date_size_offset_y);   /* 4 spacing from boundry */
    }
    else
    {
        gui_move_text_cursor(x2 - str_width - 4, date_size_offset_y);   /* 4 spacing from boundry */
    }

    gui_print_text((UI_string_type) buffer_UCS2);

    /* restore default font size */
    gui_set_font(&MMI_medium_font);

    /*----------------------------------------------------------------*/
    /* Draw Icon                                                      */
    /*----------------------------------------------------------------*/
    if (r2lMMIFlag)
    {
        mmi_fmgr_draw_free_space_icon(right_align_offset_x + 4, y1, y2 - y1 + 1, ratio);
    }
    else
    {
        mmi_fmgr_draw_free_space_icon(x1 + 4, y1, y2 - y1 + 1, ratio);
    }

    /* pop clip , unlock and blt */
    gui_pop_clip();
    gui_pop_text_clip();
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_hide_drv_menuitem_callback
 * DESCRIPTION
 *  hide drv menitem's callback function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_hide_drv_menuitem_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* stop scroll text */
    gui_scrolling_text_stop(&fmgr_p->scroll_text);

    /* gdi_image_stop_animation_all(); */
}

/******************************************************************************
* File\Folder UI related callback
******************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_get_small_file_type_icon_image_ptr
 * DESCRIPTION
 *  get small file icon image
 * PARAMETERS
 *  file_info       [IN]        File info
 * RETURNS
 *  void
 *****************************************************************************/
PU8 mmi_fmgr_get_small_file_type_icon_image_ptr(FMGR_FILE_INFO_STRUCT *file_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (file_info->attribute & FS_ATTR_DIR)
    {
        if ((FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_FOLDER_DOT)))
        {
            return (PU8) GetImage(IMG_ID_FMGR_ICON_FILE_TYPE_FOLDERUP);
        }
        else
        {
            return (PU8) GetImage(IMG_ID_FMGR_ICON_FILE_TYPE_FOLDER);
        }
    }
    else
    {
        /* image */
        if ((FMGR_FILTER_IS_SET_IMAGE(&file_info->file_type)))
        {
            return (PU8) GetImage(IMG_ID_FMGR_ICON_FILE_TYPE_IMG);
        }
        /* message */
        else if ((FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_EMS)) ||
                 (FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_ANM)))

        {
            return (PU8) GetImage(IMG_ID_FMGR_ICON_FILE_TYPE_MSG);
        }
        /* audio */
        else if (FMGR_FILTER_IS_SET_AUDIO(&file_info->file_type))
        {
            return (PU8) GetImage(IMG_ID_FMGR_ICON_FILE_TYPE_AUD);
        }
        /* video */
    #ifdef __MMI_VIDEO_PLAYER__
        else if (FMGR_FILTER_IS_SET_VIDEO(&file_info->file_type))
        {
            return (PU8) GetImage(IMG_ID_FMGR_ICON_FILE_TYPE_VDO);
        }
    #endif /* __MMI_VIDEO_PLAYER__ */ 
        else if ((FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_EMS)) ||
                 (FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_ANM)))

        {
            return (PU8) GetImage(IMG_ID_FMGR_ICON_FILE_TYPE_MSG);
        }
    #ifdef __J2ME__
        else if ((FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_JAD)) ||
                 (FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_JAR)))
        {
            return (PU8) GetImage(IMG_ID_FMGR_ICON_FILE_TYPE_JAVA);
        }
    #endif /* __J2ME__ */ 
    #ifdef __MMI_VCARD__
        else if (FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_VCF))
        {
            return (PU8) GetImage(IMG_ID_FMGR_ICON_FILE_TYPE_VCF);
        }
    #endif /* __MMI_VCARD__ */ 
    #ifdef __MMI_VCALENDAR__
        else if (FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_VCS))
        {
            return (PU8) GetImage(IMG_ID_FMGR_ICON_FILE_TYPE_VCS);
        }
    #endif /* __MMI_VCALENDAR__ */ 
    #ifdef __MMI_SVG__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_SVG__ */ 
    #ifdef __MMI_EBOOK_READER__
        else if (FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_EBOOK_TXT))
        {
            return (PU8) GetImage(IMG_EBOOK_FMGR_TXT_SMALL_TYPE);

        }
        else if (FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_EBOOK_PDB))
        {
            return (PU8) GetImage(IMG_EBOOK_FMGR_PDB_SMALL_TYPE);

        }
    #endif /* __MMI_EBOOK_READER__ */ 
    #ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
        else if (FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_THEME))
        {
            return (PU8) GetImage(IMG_ID_FMGR_ICON_FILE_TYPE_THEME);
        }
    #endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 
    #ifdef __MMI_BARCODEREADER__
        else if (FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_MBC))
        {
            return (PU8) GetImage(IMG_ID_FMGR_ICON_FILE_TYPE_MBC);
        }
    #endif /* __MMI_BARCODEREADER__ */
    #ifdef __MMI_VIDEO_STREAM__
        else if (FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_SDP))
        {
            return (PU8)GetImage(IMG_ID_FMGR_ICON_FILE_TYPE_VDO);
        }
        else if (FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_RAM))
        {
            return (PU8)GetImage(IMG_ID_FMGR_ICON_FILE_TYPE_VDO);
        }        
    #endif /* __MMI_VIDEO_STREAM__ */     
    #ifdef __MMI_SWFLASH__
        else if (FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_CMP)||
            FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_VIS)||
            FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_IVIS)||
            FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_KVIS)||
            FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_MVIS)||
            FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_ZDD))
        {
            U16 image_id = 0;
            S32 downloaded = 0;
            S32 category = 0;

            if (mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info->file_name) == TRUE
        #ifndef __MMI_SHOW_FILE_EXT__
                && mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info->file_ext) == TRUE
        #endif 
            )
            {
                category = mmi_swflash_get_category(fmgr_p->file_path, &downloaded,&file_info->file_type);
                switch (category)
                {
                case 1:
                    image_id = (downloaded ? IMG_ID_SWFLASH_CAT1_PL : IMG_ID_SWFLASH_CAT1_DL);
                    break;
                case 2:
                    image_id = (downloaded ? IMG_ID_SWFLASH_CAT2_PL : IMG_ID_SWFLASH_CAT2_DL);
                    break;
                case 3:
                    image_id = (downloaded ? IMG_ID_SWFLASH_CAT3_PL : IMG_ID_SWFLASH_CAT3_DL);
                    break;
                case 4:
                    image_id = (downloaded ? IMG_ID_SWFLASH_CAT4_PL : IMG_ID_SWFLASH_CAT4_DL);
                    break;
                case 5:
                    image_id = (downloaded ? IMG_ID_SWFLASH_CAT5_PL : IMG_ID_SWFLASH_CAT5_DL);
                    break;
                case 6:
                    image_id = (downloaded ? IMG_ID_SWFLASH_CAT6_PL : IMG_ID_SWFLASH_CAT6_DL);
                    break;
                case 7:
                    image_id = (downloaded ? IMG_ID_SWFLASH_CAT7_PL : IMG_ID_SWFLASH_CAT7_DL);
                    break;
                case 8:
                    image_id = (downloaded ? IMG_ID_SWFLASH_CAT8_PL : IMG_ID_SWFLASH_CAT8_DL);
                    break;
                case 9:
                    image_id = (downloaded ? IMG_ID_SWFLASH_CAT9_PL : IMG_ID_SWFLASH_CAT9_DL);
                    break;
                default:
                    image_id = IMG_ID_FMGR_ICON_FILE_TYPE_UNKNOWN;
                    break;
                }
                mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
            }
            return (PU8)GetImage(image_id);
        }
    #endif /* __MMI_SWFLASH__ */ 
    #ifdef __MMI_VBOOKMARK__ 
        else if (FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_URL) ||
                 FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_VBM))
        {
            return (PU8)GetImage(IMG_ID_FMGR_ICON_FILE_TYPE_VBOOKMARK);
        }
    #endif /* #ifdef __MMI_VBOOKMARK__  */

#if defined(__MMI_BROWSER_2__)
        else if ((FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_WML)) ||
                 (FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_HTML)) ||
                 (FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_HTM)) ||
                 (FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_XHTML)))
        {
            return (PU8) GetImage(IMG_ID_FMGR_FILE_TYPE_HTM);
        }
#endif
    #if defined(__DRM_V02__)
        else if (FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_ODF))
        {
            /* ODF small icon/image */
            return (PU8)GetImage(IMG_ID_FMGR_ICON_FILE_TYPE_ODF);
        }
    #endif /* defined(__DRM_V02__) */  
        else
        {
            return (PU8) GetImage(IMG_ID_FMGR_ICON_FILE_TYPE_UNKNOWN);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_get_large_file_type_icon_image_ptr
 * DESCRIPTION
 *  get large file icon image
 * PARAMETERS
 *  file_info       [IN]        File info
 * RETURNS
 *  void
 *****************************************************************************/
PU8 mmi_fmgr_get_large_file_type_icon_image_ptr(FMGR_FILE_INFO_STRUCT *file_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MACRO */
#define FMGR_GET_IMAGE_ICON_ELSEIF(a, b)                \
   else if(FMGR_FILTER_IS_SET(&file_info->file_type, a))\
      return (PU8)GetImage(b);

    if (file_info->attribute & FS_ATTR_DIR)
    {
        return (PU8) GetImage(IMG_ID_FMGR_FILE_TYPE_FOLDER);
    }
    else
    {
        /* image */
        if (FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_BMP))
        {
            return (PU8) GetImage(IMG_ID_FMGR_FILE_TYPE_BMP);
        }
    #ifdef JPG_DECODE
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_JPG, IMG_ID_FMGR_FILE_TYPE_JPG)
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_JPEG, IMG_ID_FMGR_FILE_TYPE_JPG)
    #endif /* JPG_DECODE */ 
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_GIF, IMG_ID_FMGR_FILE_TYPE_GIF)
    #ifdef GDI_USING_PNG
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_PNG, IMG_ID_FMGR_FILE_TYPE_PNG)
    #endif /* GDI_USING_PNG */
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_WBM, IMG_ID_FMGR_FILE_TYPE_WBMP)
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_WBMP, IMG_ID_FMGR_FILE_TYPE_WBMP)
    #ifdef M3D_MMI_SUPPORT
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_M3D, IMG_ID_FMGR_FILE_TYPE_M3D)
    #endif 
            /* message */
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_EMS, IMG_ID_FMGR_FILE_TYPE_EMS)
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_ANM, IMG_ID_FMGR_FILE_TYPE_ANM)
            /* audio */
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_IMY, IMG_ID_FMGR_FILE_TYPE_IMY)
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_MID, IMG_ID_FMGR_FILE_TYPE_MID)
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_MIDI, IMG_ID_FMGR_FILE_TYPE_MID)
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_WAV, IMG_ID_FMGR_FILE_TYPE_WAV)
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_AMR, IMG_ID_FMGR_FILE_TYPE_AMR)
    #ifdef AAC_DECODE
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_AAC, IMG_ID_FMGR_FILE_TYPE_AAC)
    #endif 
    #ifdef DAF_DECODE
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_DAF, IMG_ID_FMGR_FILE_TYPE_DAF)
        #ifdef MUSICAM_DECODE
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_MP2, IMG_ID_FMGR_FILE_TYPE_DAF)
        #endif
    #endif 
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_VM, IMG_ID_FMGR_FILE_TYPE_VM)
    #ifdef AMRWB_DECODE
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_AWB, IMG_ID_FMGR_FILE_TYPE_AWB)
    #endif 
    #ifdef AIFF_DECODE
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_AIF, IMG_ID_FMGR_FILE_TYPE_AIF)
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_AIFF, IMG_ID_FMGR_FILE_TYPE_AIF)
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_AIFC, IMG_ID_FMGR_FILE_TYPE_AIF)
    #endif
    #ifdef AU_DECODE
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_AU, IMG_ID_FMGR_FILE_TYPE_AU)
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_SND, IMG_ID_FMGR_FILE_TYPE_SND)
    #endif
    #ifdef AAC_DECODE
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_M4A, IMG_ID_FMGR_FILE_TYPE_M4A)
    #endif 
    #if defined(YAMAHA_MA3)
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_MMF, IMG_ID_FMGR_FILE_TYPE_DAF)
    #endif 
    #ifdef WMA_DECODE
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_WMA, IMG_ID_FMGR_FILE_TYPE_DAF)
    #endif 
            /* video */
    #if defined(MP4_CODEC) || defined(__MMI_PURE_AUDIO__) ||defined(__SF_MP4_SUPPORT__)
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_3GP, IMG_ID_FMGR_FILE_TYPE_3GP)
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_MP4, IMG_ID_FMGR_FILE_TYPE_MP4)
    #endif
    #if defined(MP4_CODEC) || defined(__SF_MP4_SUPPORT__)            
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_MPG, IMG_ID_FMGR_FILE_TYPE_MP4)
            /* use 3GP icon for 3G2 */
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_3G2, IMG_ID_FMGR_FILE_TYPE_3GP)            
    #endif /* MP4_CODEC */ 
    #ifdef __SF_MP4_SUPPORT__  //UNI@bw_0731_0002 增加6225支持MP4播放功能 
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_3GP, IMG_ID_FMGR_FILE_TYPE_3GP)
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_MP4, IMG_ID_FMGR_FILE_TYPE_MP4)           
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_3G2, IMG_ID_FMGR_FILE_TYPE_3GP) 
    #endif
    #ifdef MJPG_SUPPORT
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_AVI, IMG_ID_FMGR_FILE_TYPE_AVI)
    #endif 
            /* others */
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_FOLDER, IMG_ID_FMGR_FILE_TYPE_FOLDER)
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_FOLDER_DOT, IMG_ID_FMGR_FILE_TYPE_FOLDERUP)
    #ifdef __J2ME__
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_JAD, IMG_ID_FMGR_FILE_TYPE_JAD)
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_JAR, IMG_ID_FMGR_FILE_TYPE_JAR)
    #endif /* __J2ME__ */ 
    #ifdef __MMI_VCARD__
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_VCF, IMG_ID_FMGR_FILE_TYPE_VCF)
    #endif 
    #ifdef __MMI_VCALENDAR__
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_VCS, IMG_ID_FMGR_FILE_TYPE_VCS)
    #endif 
    #ifdef __MMI_SVG__
/* under construction !*/
    #endif 
    #ifdef __MMI_EBOOK_READER__
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_EBOOK_TXT, IMG_EBOOK_FMGR_TXT_LARGE_TYPE)
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_EBOOK_PDB, IMG_EBOOK_FMGR_PDB_LARGE_TYPE)
    #endif /* __MMI_EBOOK_READER__ */ 
    #ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_THEME, IMG_ID_FMGR_FILE_TYPE_THEME)
    #endif 
    #ifdef __MMI_BARCODEREADER__
                FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_MBC, IMG_ID_FMGR_FILE_TYPE_MBC)
        #endif
    #ifdef __MMI_SWFLASH__
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_CMP, IMG_ID_FMGR_FILE_TYPE_UNKNOWN)
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_VIS, IMG_ID_FMGR_FILE_TYPE_VIS)
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_IVIS, IMG_ID_FMGR_FILE_TYPE_IVIS)
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_MVIS, IMG_ID_FMGR_FILE_TYPE_MVIS)
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_KVIS, IMG_ID_FMGR_FILE_TYPE_KVIS)
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_ZDD, IMG_ID_FMGR_FILE_TYPE_ZDD)
    #endif /* __MMI_SWFLASH__ */
    #ifdef __MMI_VIDEO_STREAM__
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_SDP, IMG_ID_FMGR_FILE_TYPE_SDP)
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_RAM, IMG_ID_FMGR_FILE_TYPE_RAM)            
    #endif /* __MMI_VIDEO_STREAM__ */  
    #ifdef __MMI_VBOOKMARK__ 
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_URL, IMG_ID_FMGR_FILE_TYPE_URL)            
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_VBM, IMG_ID_FMGR_FILE_TYPE_VBM)            
    #endif /* #ifdef __MMI_VBOOKMARK__  */
    #if defined(__MMI_BROWSER_2__)
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_WML, IMG_ID_FMGR_BRW_WML_LARGE_TYPE)
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_HTM, IMG_ID_FMGR_BRW_HTM_LARGE_TYPE)
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_HTML, IMG_ID_FMGR_BRW_HTML_LARGE_TYPE)
            FMGR_GET_IMAGE_ICON_ELSEIF(FMGR_TYPE_XHTML, IMG_ID_FMGR_BRW_XHTML_LARGE_TYPE)
    #endif /* __MMI_BROWSER_2__ */

    #if defined(__DRM_V02__)
            else if(FMGR_FILTER_IS_SET(&file_info->file_type, FMGR_TYPE_ODF))
            {
                FMGR_FILE_INFO_STRUCT new_fileinfo;
                S32 file_type = 0;

                mmi_fmgr_kernel_get_file_info(fmgr_p->cur_index, &new_fileinfo);
                
                if (mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info->file_name) == TRUE
            #ifndef __MMI_SHOW_FILE_EXT__
                    || mmi_fmgr_append_file_name((PS8) fmgr_p->file_path, (PS8) file_info->file_ext) == TRUE
            #endif 
                    )
                {

                    file_type = mmi_fmgr_get_drm_file_type_by_path((PS8)fmgr_p->file_path, &new_fileinfo.file_type);
    
                    mmi_fmgr_remove_last_dir((PS8) fmgr_p->file_path);
                    
                    if (file_type == FMGR_TYPE_ODF)
                    {
                        /* Multi Part ODF */
                        return (PU8)GetImage(IMG_ID_FMGR_FILE_TYPE_ODF_MULTI_PART);
                    }
                    else
                    {
                        FMGR_FILTER_CLEAR(&new_fileinfo.file_type, FMGR_TYPE_ODF);
                        
                        /* find out the large icon in singal part content */
                        return mmi_fmgr_get_large_file_type_icon_image_ptr(&new_fileinfo);
                    }
                }
                else
                {
                    return (PU8) GetImage(IMG_ID_FMGR_FILE_TYPE_UNKNOWN);
                }
            }

    #endif /* defined(__DRM_V02__) */  

            else
            {
            return (PU8) GetImage(IMG_ID_FMGR_FILE_TYPE_UNKNOWN);
            }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_get_file_item_callback
 * DESCRIPTION
 *  get large file icon image
 * PARAMETERS
 *  item_idx            [IN]        Index
 *  str_buff            [IN]        String buffer
 *  img_buff_p          [IN]        Image buffer
 *  str_img_mask        [IN]        Mask
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_fmgr_get_file_item_callback(S32 item_idx, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT file_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmgr_kernel_get_file_info(item_idx, &file_info);

    memset(str_buff, 0, sizeof(MAX_SUB_MENU_SIZE));
    if (file_info.is_short)
    {
        mmi_chset_mixed_text_to_ucs2_str(
            (U8*) str_buff,
            (MAX_SUBMENU_CHARACTERS - 1) * ENCODING_LENGTH,
            (U8*) file_info.file_name,
            PhnsetGetDefEncodingType());
    }
    else
        mmi_ucs2ncpy((PS8) str_buff, (PS8) file_info.file_name, MAX_SUBMENU_CHARACTERS - 1);

    /* hide ext name for diaplay */
    mmi_fmgr_kernel_hide_ext_name((PS8) str_buff, &file_info);

    *img_buff_p = mmi_fmgr_get_small_file_type_icon_image_ptr(&file_info);

    return TRUE;
}

#ifdef __MMI_EBOOK_READER__


/*****************************************************************************
 * FUNCTION
 *  ebr_get_file_item_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_idx            [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [?]         
 *  str_img_mask        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
pBOOL ebr_get_file_item_callback(S32 item_idx, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT file_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(str_buff, 0, sizeof(MAX_SUB_MENU_SIZE));
    mmi_fmgr_kernel_get_file_info(item_idx, &file_info);
    if (file_info.is_short)
    {
        mmi_chset_mixed_text_to_ucs2_str(
            (U8*) str_buff,
            (MAX_SUBMENU_CHARACTERS - 1) * ENCODING_LENGTH,
            (U8*) file_info.file_name,
            PhnsetGetDefEncodingType());
    }
    else
	    mmi_ucs2ncpy((PS8) str_buff, (PS8) file_info.file_name, MAX_SUBMENU_CHARACTERS - 1);
    
    ebr_fmgr_kernel_hide_ext_name((PS8) str_buff, &file_info);
	*img_buff_p = mmi_fmgr_get_small_file_type_icon_image_ptr(&file_info);
    return TRUE;
}
#endif /* __MMI_EBOOK_READER__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_get_file_hint_callback
 * DESCRIPTION
 *  callback function for getting dynamic list hint
 * PARAMETERS
 *  item_idx        [IN]        Index
 *  hint_array      [IN]        Hint buffer
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_fmgr_get_file_hint_callback(S32 item_idx, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_draw_file_info_callback
 * DESCRIPTION
 *  callback function for draw seleted drv info
 * PARAMETERS
 *  item_idx        [IN]        Index
 *  x1              [IN]        X1
 *  y1              [IN]        Y1
 *  x2              [IN]        X2
 *  y2              [IN]        Y2
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_draw_file_info_callback(S32 item_idx, S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 char_height;
    S8 buffer[64];
    S8 buffer_UCS2[64];
    S32 str_width, str_height;
    S32 box_width, box_height;
    S32 box_offset_x, box_offset_y;
    S32 img_width, img_height;
    S32 spacing;
    PU8 icon_ptr;
    S32 size_offset_y;
    S32 date_offset_y;
    S32 size_str_offset_y;
    S32 date_str_offset_y;
    S32 left_align_offset_x;
    S32 right_align_offset_x;
    U32 file_size;
    BOOL is_drm;

    FMGR_FILE_INFO_STRUCT file_info;

#if defined(__DRM_SUPPORT__) || defined(FMGR_USING_CACHE)
    S8 buffer_path[FMGR_PATH_BUFFER_SIZE]={0};
#endif

#ifdef __DRM_SUPPORT__
    FS_HANDLE file_h;
#endif /* __DRM_SUPPORT__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    is_drm = FALSE;

    /* lock and push clip */
    gdi_layer_lock_frame_buffer();
    gdi_layer_push_clip();
    gdi_layer_reset_clip();

    /*-------------------------*/
    /* Get File info           */
    /*-------------------------*/
    /* draw Date */

    mmi_fmgr_kernel_get_file_info(item_idx, &file_info);

    if ((fmgr_p->src_application == APP_PROFILES ||
         fmgr_p->src_application == APP_PHONEBOOK || 
         fmgr_p->src_application == APP_SLIDESHOW || 
         fmgr_p->src_application == APP_PHOEDT) && (FMGR_FILTER_IS_SET_AUDIO(&file_info.file_type)))
    {
    #if defined(__DRM_SUPPORT__)
        mmi_fmgr_kernel_get_path_name((PS8) buffer_path);

        if (mmi_fmgr_append_file_name((PS8) buffer_path, (PS8) file_info.file_name) == TRUE
    #ifndef __MMI_SHOW_FILE_EXT__
            || mmi_fmgr_append_file_name((PS8) buffer_path, (PS8) file_info.file_ext) == TRUE
    #endif 
            )
        {
            if (DRM_get_object_method(0, (PU16)buffer_path) != DRM_METHOD_NONE)
            {
                /* is drm file */
                is_drm = TRUE;
            }
        }
    
        if (is_drm!=TRUE)
    #endif /* (__DRM_SUPPORT__) */
        {
            StartTimer(FMGR_AUDIO_TIMER, 1000, fmgr_play_audio_hdlr);
        }
    }

    /*-------------------------*/
    /* Calculate text position */
    /*-------------------------*/
    box_height = y2 - y1 - FMGR_UI_IMAGE_BOX_SPACING * 2 + 1;
    box_width = box_height;

    box_offset_y = FMGR_UI_IMAGE_BOX_SPACING;

    if (r2lMMIFlag)
    {
        box_offset_x = x2 - box_width - FMGR_UI_IMAGE_BOX_SPACING;
    }
    else
    {
        box_offset_x = FMGR_UI_IMAGE_BOX_SPACING;
    }

    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_font(&MMI_medium_font);

    char_height = gui_get_string_height((UI_string_type) GetString(STR_ID_FMGR_FILE_DATE));
    spacing = (y2 - y1 - 1 - char_height * 2) / 3;

    size_str_offset_y = spacing + MMI_title_height + MMI_title_y + 1;   /* +1 make it looks better */
    date_str_offset_y = spacing * 2 + char_height + MMI_title_height + MMI_title_y + 1; /* +1 make it looks better */

    char_height = gui_get_string_height((UI_string_type) L"1");
    spacing = (y2 - y1 - 1 - char_height * 2) / 3;

    size_offset_y = spacing + MMI_title_height + MMI_title_y + 1;       /* +1 make it looks better */
    date_offset_y = spacing * 2 + char_height + MMI_title_height + MMI_title_y + 1;     /* +1 make it looks better */

    left_align_offset_x = x1 + box_width + FMGR_UI_TEXT_SPACING;
    right_align_offset_x = x2 - box_width - FMGR_UI_TEXT_SPACING;

    /*-------------------------*/
    /* Draw Size Text          */
    /*-------------------------*/
    if (!(file_info.attribute & FS_ATTR_DIR))
    {
        if (UI_device_width > 128)
        {
            if (r2lMMIFlag)
            {
                gui_move_text_cursor(right_align_offset_x, size_str_offset_y);
            }
            else
            {
                gui_move_text_cursor(left_align_offset_x, size_str_offset_y);
            }

            gui_print_text((UI_string_type) GetString(STR_ID_FMGR_FILE_SIZE));
        }

        if (file_info.file_size > 1024 * 1024)
        {
            file_size = file_info.file_size / 1024;
            sprintf(buffer, "%d.%dM", (U16) (file_size / 1024), (U16) ((file_size % 1024) / 103));
        }
        else if (file_info.file_size > 1024)
        {
            sprintf(buffer, "%d.%dK", (U16) (file_info.file_size / 1024), (U16) ((file_info.file_size % 1024) / 103));
        }
        else    /* less than 1024 */
        {
            sprintf(buffer, "%dB", (U16) (file_info.file_size));
        }

        mmi_asc_to_ucs2((PS8) buffer_UCS2, (PS8) buffer);
        gui_measure_string((UI_string_type) buffer_UCS2, &str_width, &str_height);

        if (r2lMMIFlag)
        {
            gui_move_text_cursor(x1 + str_width + FMGR_UI_TEXT_SPACING, size_offset_y);
        }
        else
        {
            gui_move_text_cursor(x2 - str_width - FMGR_UI_TEXT_SPACING, size_offset_y);
        }

        gui_print_text((UI_string_type) buffer_UCS2);
    }

    /*----------------------------------------------------------------*/
    /* Draw Date Text                                                 */
    /*----------------------------------------------------------------*/
    gui_set_font(&MMI_medium_font);

    gui_reset_text_clip();

    if (UI_device_width > 128)
    {
        if (r2lMMIFlag)
        {
            gui_move_text_cursor(right_align_offset_x, date_str_offset_y);
        }
        else
        {
            gui_move_text_cursor(left_align_offset_x, date_str_offset_y);
        }

        gui_print_text((UI_string_type) GetString(STR_ID_FMGR_FILE_DATE));
    }

    /* we do not have enough room to put all dat format, we use sub's foramt */
    date_string(&file_info.time, (PU16) buffer, DT_FILEMANAGER);

    gui_measure_string((UI_string_type) buffer, &str_width, &str_height);

    if (r2lMMIFlag)
    {
        gui_move_text_cursor(x1 + str_width + FMGR_UI_TEXT_SPACING, date_offset_y);
    }
    else
    {
        gui_move_text_cursor(x2 - str_width - FMGR_UI_TEXT_SPACING, date_offset_y);
    }

    gui_print_text((UI_string_type) buffer);

    /*-------------------------*/
    /* Draw Large Icon         */
    /*-------------------------*/
    icon_ptr = mmi_fmgr_get_large_file_type_icon_image_ptr(&file_info);

    gdi_image_get_dimension(icon_ptr, &img_width, &img_height);
    spacing = (box_height - img_height) >> 1;

#if defined(__DRM_SUPPORT__)
    if ((FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_JPG) ||
         (FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_JPEG))))
    {
        mmi_fmgr_kernel_get_path_name((PS8) buffer_path);

        if (mmi_fmgr_append_file_name((PS8) buffer_path, (PS8) file_info.file_name) == TRUE
    #ifndef __MMI_SHOW_FILE_EXT__
            || mmi_fmgr_append_file_name((PS8) buffer_path, (PS8) file_info.file_ext) == TRUE
    #endif 
            )
        {
            file_h = DRM_open_file((PU16) buffer_path, FS_READ_ONLY, DRM_PERMISSION_NONE);

            if (DRM_get_object_method(file_h, (PU16)buffer_path) != DRM_METHOD_NONE)
            {
                /* is drm file */
                is_drm = TRUE;
            }
            DRM_close_file(file_h);
        }
    }
#elif defined(FMGR_USING_CACHE)
    mmi_fmgr_kernel_get_path_name((PS8) buffer_path);
    mmi_ucs2cat((PS8) buffer_path, (PS8) file_info.file_name);
#endif /* __DRM_SUPPORT__ */ 

    /* draw thumb image */
#if defined(FMGR_USING_CACHE)
    if (file_info.attribute & FS_ATTR_DIR)
    {
        /* align at center */
        gdi_image_draw(
            x1 + box_offset_x + ((box_height - img_width) >> 1),
            y1 + box_offset_y + ((box_height - img_height) >> 1),
            icon_ptr);
    }
    else if ((!is_drm) && (mmi_ucs2strlen(buffer_path) && gdi_image_get_type_from_file(buffer_path)==GDI_IMAGE_TYPE_JPG_FILE)&&
        (FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_JPG) ||
         FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_JPEG)))
    {
        mmi_fmgr_show_thumb_image(
            item_idx,
            x1,
            y1,
            box_offset_x,
            box_offset_y,
            box_height,
            box_height,
            icon_ptr,
            TRUE,
            FMGR_UI_INFO_STYLE);
    }
    else
    {
        /* align at center */
        gdi_image_draw(
            x1 + box_offset_x + ((box_height - img_width) >> 1),
            y1 + box_offset_y + ((box_height - img_height) >> 1),
            icon_ptr);

    }
#else /* defined(FMGR_USING_CACHE) */ 

    /* align at center */
    gdi_image_draw(
        x1 + box_offset_x + ((box_height - img_width) >> 1),
        y1 + box_offset_y + ((box_height - img_height) >> 1),
        icon_ptr);

#endif /* defined(FMGR_USING_CACHE) */ 

    /* pop clip , unlock and blt */
    gdi_layer_pop_clip();
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_hide_file_info_callback
 * DESCRIPTION
 *  callback function for stop draw seleted drv info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_hide_file_info_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(FMGR_USING_CACHE)
    S32 i;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(FMGR_AUDIO_TIMER);
    if (fmgr_p->audio_state == TRUE)
    {
        fmgr_p->audio_state = FALSE;
        mdi_audio_stop_file();
    }

#if defined(FMGR_USING_CACHE)

    /* stop all decoding jpeg files */
    gdi_image_decoder_stop_all();

    /* reset delay decoder */
    g_fmgr_context.delay_decode_index = 0;

    if(g_fmgr_context.decoding_count>0)
    {
        g_fmgr_context.decoding_count=0;
        wgui_status_icon_unlock_redrawing();
    }

    StopTimer(FMGR_DELAY_DECODE_0);
    StopTimer(FMGR_DELAY_DECODE_1);
    StopTimer(FMGR_DELAY_DECODE_2);
    StopTimer(FMGR_DELAY_DECODE_3);
    StopTimer(FMGR_DELAY_DECODE_4);
    StopTimer(FMGR_DELAY_DECODE_5);
    StopTimer(FMGR_DELAY_DECODE_6);
    StopTimer(FMGR_DELAY_DECODE_7);
    StopTimer(FMGR_DELAY_DECODE_8);
    StopTimer(FMGR_DELAY_DECODE_9);

    /* clear image cache handle entries */
    for (i = 0; i < FMGR_THUMB_IMAGE_HANDLE_MAX_COUNT; i++)
    {
        fmgr_image_cache_p->image_handle_list[i]->is_used = FALSE;
    }

    /* free jpeg decoder */
    if (fmgr_p->is_decoder_create)
    {
        gdi_image_decoder_free();
        fmgr_p->is_decoder_create = FALSE;
    }

#endif /* defined(FMGR_USING_CACHE) */ 

    /* stop all animations */
    /* gdi_image_stop_animation_all(); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_draw_hilight_menuitem_bg
 * DESCRIPTION
 *  call back function for draw hilight menuitem, used by scrolling text
 * PARAMETERS
 *  x1      [IN]        X1
 *  y1      [IN]        Y1
 *  x2      [IN]        X2
 *  y2      [IN]        Y2
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_draw_hilight_menuitem_bg(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if background decoding finish: yes then start to scroll */
    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);
    gui_draw_filled_area(
        GUI_current_fixed_icontext_menuitem_x,
        GUI_current_fixed_icontext_menuitem_y,
        x2,
        y2,
        MMI_fixed_icontext_menuitem.selected_filler);
    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_draw_hilight_menuitem_bg_callback
 * DESCRIPTION
 *  call back function for draw hilight menuitem, used by scrolling text
 * PARAMETERS
 *  x1      [IN]        X1
 *  y1      [IN]        Y1
 *  x2      [IN]        X2
 *  y2      [IN]        Y2
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_draw_hilight_menuitem_bg_callback(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if background decoding finish: yes then start to scroll */
#if defined(FMGR_USING_CACHE)
    if (g_fmgr_context.decoding_count == 0)
#endif
    {
        gui_push_clip();
        gui_set_clip(x1, y1, x2, y2);
        gui_draw_filled_area(
            GUI_current_fixed_icontext_menuitem_x,
            GUI_current_fixed_icontext_menuitem_y,
            x2,
            y2,
            MMI_fixed_icontext_menuitem.selected_filler);
        gui_pop_clip();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_draw_hilight_menuitem_timer_callback
 * DESCRIPTION
 *  draw hilight menuitem text, callback function for scrolling text
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_draw_hilight_menuitem_timer_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(FMGR_USING_CACHE)
    /* check if background decoding finish: yes then start to scroll */
    if (g_fmgr_context.decoding_count == 0)
        gui_handle_scrolling_text(&fmgr_p->scroll_text);
    else
        gui_start_timer(350,mmi_fmgr_draw_hilight_menuitem_timer_callback);
#else
    gui_handle_scrolling_text(&fmgr_p->scroll_text);
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_draw_file_menuitem_callback
 * DESCRIPTION
 *  draw file menuitem callack
 * PARAMETERS
 *  item_idx            [IN]        Index
 *  is_hilighted        [IN]        Hilighted flag
 *  x1                  [IN]        X1
 *  y1                  [IN]        Y1
 *  x2                  [IN]        X2
 *  y2                  [IN]        Y2
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_draw_file_menuitem_callback(S32 item_idx, BOOL is_hilighted, S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buffer[128]; /* this buffer should larger than (FMGR_MAX_FILE_LEN+1)*ENCODING_LENGTH */
    S8 buffer_UCS2[128];
    S32 str_width, str_height;
    S32 img_width, img_height;
    PU8 icon_ptr;
    S32 small_font_height;
    S32 medium_font_height;
    S32 text_spacing;
    S32 left_align_offset_x;
    S32 r2l_x1;
    S32 r2l_x2;
    S32 filename_offset_y;
    S32 date_size_offset_y;
    color text_color;
    color text_shadow_color;
    S32 file_size;
    S32 box_offset_x;
    S32 box_offset_y;
    S32 box_width;
    S32 box_height;
    S32 image_offset_x;
    S32 image_offset_y;
    BOOL is_drm;

    FMGR_FILE_INFO_STRUCT file_info;

#if defined(__DRM_SUPPORT__) || defined(FMGR_USING_CACHE)
    S8 buffer_path[FMGR_PATH_BUFFER_SIZE]={0};
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    is_drm = FALSE;

    /* set index to fm's global index */
    if (is_hilighted)
    {
        fmgr_p->cur_index = item_idx;
    }

    mmi_fmgr_kernel_get_file_info(item_idx, &file_info);

    if (fmgr_p->src_application == APP_PROFILES && (FMGR_FILTER_IS_SET_AUDIO(&file_info.file_type)))
    {
  #if defined(__DRM_SUPPORT__)
        mmi_fmgr_kernel_get_path_name((PS8) buffer_path);

        if (mmi_fmgr_append_file_name((PS8) buffer_path, (PS8) file_info.file_name) == TRUE
    #ifndef __MMI_SHOW_FILE_EXT__
            || mmi_fmgr_append_file_name((PS8) buffer_path, (PS8) file_info.file_ext) == TRUE
    #endif 
            )
        {
            if (DRM_get_object_method(0, (PU16)buffer_path) != DRM_METHOD_NONE)
            {
                /* is drm file */
                is_drm = TRUE;
            }
        }
    
        if (is_drm!=TRUE)
    #endif /* (__DRM_SUPPORT__) */
        {
            StartTimer(FMGR_AUDIO_TIMER, 1000, fmgr_play_audio_hdlr);
        }
    }

    /* lock and push clip */
    gdi_layer_lock_frame_buffer();
    gdi_layer_push_clip();
    gdi_layer_reset_clip();

    /*
     * this function will draw thumb image menuitem .
     *
     * --------------------------------------
     * | ##### FILENAME_HERE.EXT             |    <--- Medium Font
     * | #####                               |
     * | ##### Date                  Size    |    <--- Small Font
     * --------------------------------------
     * Info. (1) Image, it will be the dimension(ex: 640x480) of the file.
     *       (2) Video, Audio. it will be duration of the file.
     */

    box_height = y2 - y1 - FMGR_UI_IMAGE_BOX_SPACING * 2 + 1;
    box_width = box_height;

    box_offset_y = FMGR_UI_IMAGE_BOX_SPACING;

    if (r2lMMIFlag)
    {
        box_offset_x = x2 - box_width - FMGR_UI_IMAGE_BOX_SPACING;
    }
    else
    {
        box_offset_x = FMGR_UI_IMAGE_BOX_SPACING;
    }

    /*----------------------------------------------------------------*/
    /* Calcuate text position here                                    */
    /*----------------------------------------------------------------*/
    small_font_height = Get_CharHeightOfAllLang(MMI_small_font.size);
    
    gui_set_font(&MMI_medium_font);
    medium_font_height = Get_CharHeightOfAllLang(MMI_medium_font.size);

    text_spacing = ((y2 - y1 + 1) - medium_font_height - small_font_height) / 3;

    if (text_spacing < 0)
    {
        text_spacing = 0;
    }

    left_align_offset_x = x1 + box_width + FMGR_UI_TEXT_SPACING;

    r2l_x1 = x1 + MMI_fixed_list_menu.vbar.width + 2;
    r2l_x2 = x2 - (y2 - y1 + 1) - text_spacing;

    filename_offset_y = y1 + text_spacing;
    date_size_offset_y = y1 + text_spacing * 2 + medium_font_height;

    if (is_hilighted)
    {
        text_color = current_UI_theme->fixed_text_menuitem_theme->selected_text_color;
        text_shadow_color = current_UI_theme->fixed_text_menuitem_theme->normal_text_color;
    }
    else
    {
        text_color = current_UI_theme->fixed_text_menuitem_theme->normal_text_color;
        text_shadow_color = current_UI_theme->fixed_text_menuitem_theme->selected_text_color;
    }

    /*----------------------------------------------------------------*/
    /* Draw File Name                                                 */
    /*----------------------------------------------------------------*/
    if (file_info.is_short)
    {
        mmi_chset_mixed_text_to_ucs2_str(
            (U8*) buffer_UCS2,
            sizeof(buffer_UCS2),
            (U8*) file_info.file_name,
            PhnsetGetDefEncodingType());
    }
    else
        mmi_ucs2cpy((PS8) buffer_UCS2, (PS8) file_info.file_name);

    /* hide ext name for diaplay */
    mmi_fmgr_kernel_hide_ext_name((PS8) buffer_UCS2, &file_info);

    if (is_hilighted)
    {
        /* scrolling text has to be stored in global variable */
        /* we use new_file_name buffer since it is not used in this scenario */
        mmi_ucs2cpy((PS8) fmgr_p->new_file_name, (PS8) buffer_UCS2);

        if (r2lMMIFlag)
        {
            gui_create_scrolling_text(
                &fmgr_p->scroll_text,
                r2l_x1 + 4,                                 /* x */
                filename_offset_y,                          /* y */
                r2l_x2 - r2l_x1 - 4,                        /* width */
                medium_font_height ,                     /* height */
                (UI_string_type) fmgr_p->new_file_name,     /* string */
                mmi_fmgr_draw_hilight_menuitem_timer_callback,    /* timer hdlr */
                mmi_fmgr_draw_hilight_menuitem_bg_callback, /* draw background hdlr */
                text_color,                                 /* text color */
                MMI_fixed_icontext_menuitem.selected_filler->c);     /* bg */
        }
        else
        {
            gui_create_scrolling_text(
                &fmgr_p->scroll_text,
                left_align_offset_x,                        /* x */
                filename_offset_y,                          /* y */
                x2 - left_align_offset_x - 1,               /* width */
                medium_font_height ,                     /* height */
                (UI_string_type) fmgr_p->new_file_name,     /* string */
                mmi_fmgr_draw_hilight_menuitem_timer_callback,    /* timer hdlr */
                mmi_fmgr_draw_hilight_menuitem_bg_callback, /* draw background hdlr */
                text_color,                                 /* text color */
                MMI_fixed_icontext_menuitem.selected_filler->c);     /* bg */
        }

        fmgr_p->scroll_text.text_font = MMI_medium_font;
        gui_show_scrolling_text(&fmgr_p->scroll_text);
    }
    else
    {
        S32 sw = 0, sh = 0;

        gui_set_font(&MMI_medium_font);

        /* set text clip, avoid draw to overlap scroll bar */
        gui_set_text_color(text_color);

        if (r2lMMIFlag)
        {
            gui_set_text_clip(r2l_x1, filename_offset_y, r2l_x2, filename_offset_y + medium_font_height + 1);

            gui_move_text_cursor(r2l_x2, filename_offset_y);
        }
        else
        {
            gui_set_text_clip(
                left_align_offset_x,
                filename_offset_y,
                x2 - 1,
                filename_offset_y + medium_font_height + 1);

            gui_move_text_cursor(left_align_offset_x, filename_offset_y);
        }

        gui_measure_string((UI_string_type) buffer_UCS2, &sw, &sh);
        gui_set_line_height(sh);
        gui_print_text((UI_string_type) buffer_UCS2);
    }

    /*----------------------------------------------------------------*/
    /* Draw File Creation Date                                        */
    /*----------------------------------------------------------------*/
    /* if is directory or is file but lcd is large enough to fit date and size on one line  */
    if ((file_info.attribute & FS_ATTR_DIR) || (!(file_info.attribute & FS_ATTR_DIR) && UI_device_width > 128))
    {
        gui_set_font(&MMI_small_font);
        gui_reset_text_clip();
        gui_set_text_color(text_color);

        /* we do not have enough room to put all dat format, we use sub's foramt */
        date_string(&file_info.time, (PU16) buffer, DT_FILEMANAGER);

        if (r2lMMIFlag)
        {
            gui_move_text_cursor(r2l_x2, date_size_offset_y);
        }
        else
        {
            gui_move_text_cursor(left_align_offset_x, date_size_offset_y);
        }

        gui_print_text((UI_string_type) buffer);
    }

    /*----------------------------------------------------------------*/
    /* Draw File Size                                                 */
    /*----------------------------------------------------------------*/
    if (!(file_info.attribute & FS_ATTR_DIR))
    {
        gui_reset_text_clip();
        gui_set_text_color(text_color);
        gui_set_font(&MMI_small_font);

        if (file_info.file_size > 1024 * 1024)
        {
            file_size = file_info.file_size / 1024;
            sprintf(buffer, "%d.%dM", (U16) (file_size / 1024), (U16) ((file_size % 1024) / 103));
        }
        else if (file_info.file_size > 1024)
        {
            sprintf(buffer, "%d.%dK", (U16) (file_info.file_size / 1024), (U16) ((file_info.file_size % 1024) / 103));
        }
        else    /* less than 1024 */
        {
            sprintf(buffer, "%dB", (U16) (file_info.file_size));
        }

        mmi_asc_to_ucs2((PS8) buffer_UCS2, (PS8) buffer);
        gui_measure_string((UI_string_type) buffer_UCS2, &str_width, &str_height);

        if (r2lMMIFlag)
        {
            gui_move_text_cursor(r2l_x1 + str_width, date_size_offset_y);
        }
        else
        {
            gui_move_text_cursor(x2 - str_width - 4, date_size_offset_y);
        }

        gui_print_text((UI_string_type) buffer_UCS2);
    }

    /* restore font to default size */
    gui_set_font(&MMI_medium_font);

    /*----------------------------------------------------------------*/
    /* Draw Large Icon                                                */
    /*----------------------------------------------------------------*/
    icon_ptr = mmi_fmgr_get_large_file_type_icon_image_ptr(&file_info);

    gdi_image_get_dimension(icon_ptr, &img_width, &img_height);
    image_offset_x = (box_width - img_width) >> 1;
    image_offset_y = (box_height - img_height) >> 1;

#if defined(__DRM_SUPPORT__)
    if ((FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_JPG) ||
         (FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_JPEG))))
    {
        mmi_fmgr_kernel_get_path_name((PS8) buffer_path);
        mmi_ucs2cat((PS8) buffer_path, (PS8) file_info.file_name);

        if (DRM_get_object_method(0, (PU16) buffer_path) != DRM_METHOD_NONE)
        {
            /* is drm file */
            is_drm = TRUE;
        }
    }
#elif defined(FMGR_USING_CACHE)
    mmi_fmgr_kernel_get_path_name((PS8) buffer_path);
    mmi_ucs2cat((PS8) buffer_path, (PS8) file_info.file_name);
#endif /* __DRM_SUPPORT__ */ 

    if (is_hilighted)
    {
    #if defined(FMGR_USING_CACHE)
        /* draw thumb image */
        if ((!is_drm) && (mmi_ucs2strlen(buffer_path) && gdi_image_get_type_from_file(buffer_path)==GDI_IMAGE_TYPE_JPG_FILE)&&
            (FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_JPG) ||
             FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_JPEG)))
        {
            if (r2lMMIFlag)
                x1 = 0;        
            mmi_fmgr_show_thumb_image(
                item_idx,
                x1,
                y1,
                box_offset_x,
                box_offset_y,
                box_width,
                box_height,
                icon_ptr,
                is_hilighted,
                FMGR_UI_LIST_STYLE);
        }
        else
        {
            gdi_image_draw(box_offset_x + image_offset_x, y1 + box_offset_y + image_offset_y, icon_ptr);
        }

    #else /* defined(FMGR_USING_CACHE) */ 
        gdi_image_draw(box_offset_x + image_offset_x, y1 + box_offset_y + image_offset_y, icon_ptr);
    #endif /* defined(FMGR_USING_CACHE) */ 

    }
    else
    {

    #if defined(FMGR_USING_CACHE)
        /* draw thumb image */
        if ((!is_drm) && (mmi_ucs2strlen(buffer_path) && gdi_image_get_type_from_file(buffer_path)==GDI_IMAGE_TYPE_JPG_FILE)&&
            (FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_JPG) ||
            FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_JPEG)))
        {
            if (r2lMMIFlag)
                x1 = 0;               
            mmi_fmgr_show_thumb_image(
                item_idx,
                x1,
                y1,
                box_offset_x,
                box_offset_y,
                box_width,
                box_height,
                icon_ptr,
                is_hilighted,
                FMGR_UI_LIST_STYLE);
        }
        else
        {
            gdi_image_draw(box_offset_x + image_offset_x, y1 + box_offset_y + image_offset_y, icon_ptr);
        }
    #else /* defined(FMGR_USING_CACHE) */ 
        gdi_image_draw(box_offset_x + image_offset_x, y1 + box_offset_y + image_offset_y, icon_ptr);
    #endif /* defined(FMGR_USING_CACHE) */ 

    }

    /* pop clip , unlock and blt */
    gdi_layer_pop_clip();
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_hide_file_menuitem_callback
 * DESCRIPTION
 *  hide file menuitem callack
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_hide_file_menuitem_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(FMGR_USING_CACHE)
    S32 i;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(FMGR_AUDIO_TIMER);
    if (fmgr_p->audio_state == TRUE)
    {
        fmgr_p->audio_state = FALSE;
        mdi_audio_stop_file();
    }

    /* stop scroll text */
    gui_scrolling_text_stop(&fmgr_p->scroll_text);

#if defined(FMGR_USING_CACHE)

    /* stop all decoding jpeg files */
    gdi_image_decoder_stop_all();

    /* reset delay decoder */
    g_fmgr_context.delay_decode_index = 0;

    /* check if background decoding finish: yes then unlock wgui status icon */
    if(g_fmgr_context.decoding_count>0)
    {
        g_fmgr_context.decoding_count=0;
        wgui_status_icon_unlock_redrawing();
    }
    
    StopTimer(FMGR_DELAY_DECODE_0);
    StopTimer(FMGR_DELAY_DECODE_1);
    StopTimer(FMGR_DELAY_DECODE_2);
    StopTimer(FMGR_DELAY_DECODE_3);
    StopTimer(FMGR_DELAY_DECODE_4);
    StopTimer(FMGR_DELAY_DECODE_5);
    StopTimer(FMGR_DELAY_DECODE_6);
    StopTimer(FMGR_DELAY_DECODE_7);
    StopTimer(FMGR_DELAY_DECODE_8);
    StopTimer(FMGR_DELAY_DECODE_9);

    /* clear image cache handle entries */
    for (i = 0; i < FMGR_THUMB_IMAGE_HANDLE_MAX_COUNT; i++)
    {
        fmgr_image_cache_p->image_handle_list[i]->is_used = FALSE;
    }

    /* free jpeg decoder */
    if (fmgr_p->is_decoder_create)
    {
        gdi_image_decoder_free();
        fmgr_p->is_decoder_create = FALSE;
    }

#endif /* defined(FMGR_USING_CACHE) */ 

    /* stop all animations */
    /* gdi_image_stop_animation_all(); */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_draw_file_matrix_callback
 * DESCRIPTION
 *  draw matrix file item
 * PARAMETERS
 *  idx                     [IN]        Selected index
 *  page_start_idx          [IN]        Page's start index
 *  page_end_idx            [IN]        Page's end index
 *  is_hilighted            [IN]        
 *  is_need_update          [IN]        Is thie item need update
 *  is_new_page             [IN]        Is first time draw this page
 *  x1                      [IN]        Draw region's x1
 *  y1                      [IN]        Draw region's y1
 *  x2                      [IN]        Draw region's x2
 *  y2                      [IN]        Draw region's y2
 *  is_highlghted(?)        [IN]        Is this selection highlighted
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_draw_file_matrix_callback(
        S32 idx,
        S32 page_start_idx,
        S32 page_end_idx,
        BOOL is_hilighted,
        BOOL is_need_update,
        BOOL is_new_page,
        S32 x1,
        S32 y1,
        S32 x2,
        S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 box_width;
    S32 box_height;
    S32 box_offset_x;
    S32 box_offset_y;
    S32 image_width;
    S32 image_height;
    PU8 icon_ptr;
    BOOL is_image_in_cache;
    BOOL is_prev_image_in_cache;
    BOOL is_corrupted_file;
    BOOL is_drm;

#if defined(FMGR_USING_CACHE)
    S32 prev_idx;
    S32 prev_cache_index;
    S32 cache_index;
#endif /* defined(FMGR_USING_CACHE) */ 

#if defined(__DRM_SUPPORT__) || defined(FMGR_USING_CACHE)
    S8 buffer_path[FMGR_PATH_BUFFER_SIZE]={0};
#endif

    FMGR_FILE_INFO_STRUCT file_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set index to fm's global index */
    if (is_hilighted)
    {
        fmgr_p->cur_index = idx;
    }

    mmi_fmgr_kernel_get_file_info(idx, &file_info);

    is_image_in_cache = FALSE;
    is_prev_image_in_cache = FALSE;
    is_corrupted_file = FALSE;
    is_drm = FALSE;

#if defined(FMGR_USING_CACHE)

    mmi_fmgr_kernel_get_path_name((PS8) buffer_path);
    mmi_ucs2cat((PS8) buffer_path, (PS8) file_info.file_name);

    /* if not need update, and it is not jpeg, the icon shall already draw */
    if ((!is_need_update) && (gdi_image_get_type_from_file(buffer_path)!=GDI_IMAGE_TYPE_JPG_FILE)&&
        !FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_JPG) &&
        !FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_JPEG))
    {
        return;
    }

    for (cache_index = 0; cache_index < fmgr_image_cache_p->image_cache_item_count; cache_index++)
    {
        if ((fmgr_image_cache_p->image_cache_list[cache_index]->is_used == TRUE) &&
            (fmgr_image_cache_p->image_cache_list[cache_index]->menuitem_idx == idx))
        {
            is_image_in_cache = TRUE;
            break;
        }
    }

    /* if this item no need update and is already in cache, no need draw */
    /* if is is_need_update, means hilight is changed or page is changed in cat224 */
    if (!is_need_update && is_image_in_cache)
    {
        return;
    }

    /* if is corrupted file, show as icon */
    if (fmgr_p->file_cache[idx - fmgr_p->cache_start_idx].is_able_display == FALSE)
    {
        is_corrupted_file = TRUE;
    }

    /* if not need update, and it the file is corrupted, the icon shall already draw */
    if (!is_need_update && is_corrupted_file)
    {
        return;
    }

    /* check if previous image is in cache or not */
    /* if previous image not in cache, will remove this image from cache */
    /* 
     * this is used to avoid showing images on a page, some images with larger idx 
     * are decoded aready, and some image with smaller idx are not decoded 
     * 
     * if is_need_update == TRUE, means first time show the matrix page.
     */
    if ((idx > 0) && (idx != page_start_idx) && is_new_page)
    {
        prev_idx = idx - 1;
        for (prev_cache_index = 0; prev_cache_index < fmgr_image_cache_p->image_cache_item_count; prev_cache_index++)
        {
            if ((fmgr_image_cache_p->image_cache_list[prev_cache_index]->is_used == TRUE) &&
                (fmgr_image_cache_p->image_cache_list[prev_cache_index]->menuitem_idx == prev_idx))
            {
                is_prev_image_in_cache = TRUE;
                break;
            }
        }

        if (!is_prev_image_in_cache && is_image_in_cache)
        {
            /* if previous not in cache */
            /* remove this from cache */
            fmgr_image_cache_p->image_cache_list[cache_index]->is_used = FALSE;
        }
    }
#endif /* defined(FMGR_USING_CACHE) */ 

    /* set index to fm's global index */
    if (is_hilighted)
    {
        fmgr_p->cur_index = idx;
    }

    /* lock and push clip */
    gdi_layer_lock_frame_buffer();
    gdi_layer_push_clip();
    gdi_layer_reset_clip();

    /* spare 1 pixel with boundry */
    box_offset_x = x1;
    box_offset_y = y1;
    box_width = x2 - x1 + 1;
    box_height = y2 - y1 + 1;

#if defined(FMGR_USING_CACHE)
    if ( box_width > fmgr_image_cache_p->image_size )
    {
        box_offset_x += ((box_width - fmgr_image_cache_p->image_size)>>1);
        box_width = fmgr_image_cache_p->image_size;
    }
    
    if ( box_height > fmgr_image_cache_p->image_size )
    {
        box_offset_y += ((box_height - fmgr_image_cache_p->image_size)>>1);
        box_height = fmgr_image_cache_p->image_size;
    }
#endif /* defined(FMGR_USING_CACHE) */    

    icon_ptr = (PU8) mmi_fmgr_get_large_file_type_icon_image_ptr(&file_info);

    gdi_image_get_dimension(icon_ptr, &image_width, &image_height);

#ifdef __DRM_SUPPORT__
    if ((FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_JPG) ||
         (FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_JPEG))))
    {
        mmi_fmgr_kernel_get_path_name((PS8) buffer_path);
        mmi_ucs2cat((PS8) buffer_path, (PS8) file_info.file_name);

        if (DRM_get_object_method(0, (PU16) buffer_path) != DRM_METHOD_NONE)
        {
            /* is drm file */
            is_drm = TRUE;
        }
    }
#endif /* __DRM_SUPPORT__ */ 

#if defined(FMGR_USING_CACHE)
    /* draw thumb image */
    if ((!is_drm) && (mmi_ucs2strlen(buffer_path) && gdi_image_get_type_from_file(buffer_path)==GDI_IMAGE_TYPE_JPG_FILE)&&
        (FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_JPG) ||
         FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_JPEG)))
    {
        mmi_fmgr_show_thumb_image(
            idx,
            box_offset_x,
            box_offset_y,
            0,
            0,
            box_width,
            box_height,
            icon_ptr,
            is_hilighted,
            FMGR_UI_MATRIX_STYLE);
    }
    else
    {
        if (is_hilighted)
        {
            gdi_image_draw(
                box_offset_x + ((box_width - image_width) >> 1),
                box_offset_y + ((box_height - image_height) >> 1),
                icon_ptr);
        }
        else
        {
            gdi_image_draw(
                box_offset_x + ((box_width - image_width) >> 1),
                box_offset_y + ((box_height - image_height) >> 1),
                icon_ptr);
        }
    }

#else /* defined(FMGR_USING_CACHE) */ 
    if (is_hilighted)
    {
        gdi_image_draw(
            box_offset_x + ((box_width - image_width) >> 1),
            box_offset_y + ((box_height - image_height) >> 1),
            icon_ptr);
    }
    else
    {
        gdi_image_draw(
            box_offset_x + ((box_width - image_width) >> 1),
            box_offset_y + ((box_height - image_height) >> 1),
            icon_ptr);
    }
#endif /* defined(FMGR_USING_CACHE) */ 

    gdi_layer_pop_clip();
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_hide_file_matrix_callback
 * DESCRIPTION
 *  hide matrix file item
 * PARAMETERS
 *  idx     [IN]        Selected index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_hide_file_matrix_callback(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(FMGR_USING_CACHE)
    S32 i;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(FMGR_AUDIO_TIMER);

    if (fmgr_p->audio_state == TRUE)
    {
        fmgr_p->audio_state = FALSE;
        mdi_audio_stop_file();
    }

#if defined(FMGR_USING_CACHE)

    /* stop all decoding jpeg files */
    gdi_image_decoder_stop_all();

    /* reset delay decoder */
    g_fmgr_context.delay_decode_index = 0;

    /* check if background decoding finish: yes then unlock wgui status icon */
    if(g_fmgr_context.decoding_count>0)
    {
        g_fmgr_context.decoding_count=0;
        wgui_status_icon_unlock_redrawing();
    }

    StopTimer(FMGR_DELAY_DECODE_0);
    StopTimer(FMGR_DELAY_DECODE_1);
    StopTimer(FMGR_DELAY_DECODE_2);
    StopTimer(FMGR_DELAY_DECODE_3);
    StopTimer(FMGR_DELAY_DECODE_4);
    StopTimer(FMGR_DELAY_DECODE_5);
    StopTimer(FMGR_DELAY_DECODE_6);
    StopTimer(FMGR_DELAY_DECODE_7);
    StopTimer(FMGR_DELAY_DECODE_8);
    StopTimer(FMGR_DELAY_DECODE_9);

    /* clear image cache handle entries */
    for (i = 0; i < FMGR_THUMB_IMAGE_HANDLE_MAX_COUNT; i++)
    {
        fmgr_image_cache_p->image_handle_list[i]->is_used = FALSE;
    }

    /* free jpeg decoder */
    if (fmgr_p->is_decoder_create)
    {
        gdi_image_decoder_free();
        fmgr_p->is_decoder_create = FALSE;
    }

#endif /* defined(FMGR_USING_CACHE) */ 

    /* stop all animations */
    /* gdi_image_stop_animation_all(); */

}

#endif /* __MMI_FILE_MANAGER__ */ 

