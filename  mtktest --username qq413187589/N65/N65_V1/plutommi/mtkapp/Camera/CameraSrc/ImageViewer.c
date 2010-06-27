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
 *  ImageViewer.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Image Viewer.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"



#include "gui.h"        /* Gui functions */
#include "FileManagerGProt.h"
#include "SettingDefs.h"        /* ST_NOTIFYDURATION define */
#ifdef __MMI_MESSAGES_EMS__
#include "MessagesExDcl.h"
#endif 
#include "CommonScreens.h"      /* popup */
#include "MainMenuDef.h"        /* Multi-media icon */

#include "lcd_sw_rnd.h" /* for LCD size */

#include "mdi_datatype.h"
#include "mdi_camera.h" /* camera lib */
#include "gui_setting.h"
#include "SettingProfile.h"     /* warning tone */
#include "FileManagerDef.h"     /* error string id */
#include "FileMgr.h"
#include "Gdi_util.h"
#include "SimDetectionGprot.h"

#if defined(__MMI_BPP_SUPPORT__)
#include "BTMMICm.h"
#include "BTMMIBppGprot.h"
#include "BTMMIBppXhtmlGprot.h"
#endif

#include "MMI_features_camera.h"        /* features - in custom folder */
#include "CameraResDef.h"
#include "CameraApp.h"  /* for storage file path */
#include "ImageViewer.h"        /* Iamge Viewer header */
#include "ImageViewerResDef.h" /* Image Viewer Res IDs */

#ifdef __MMI_TVOUT__
#include "mdi_datatype.h"
#include "mdi_tv.h"
#endif /* __MMI_TVOUT__ */ 

#include "Drm_gprot.h"  /* DRM support */

#if defined(__MMI_SCREEN_ROTATE__)
#include "ScreenRotationGprot.h"
#endif 
#include "USBDeviceGprot.h"


#if defined(__MMI_IMAGEVIEWER_ADV__) || defined(__MMI_BPP_SUPPORT__)
#include "conversions.h"
#include "phonesetupgprots.h"
#endif


#if defined(__MMI_IMAGE_VIEWER__) || defined(__MMI_FILE_MANAGER__)

#ifdef __MMI_IMAGEVIEWER_ADV__
typedef enum
{
    IMGADV_TOUCH_RSK = 0,
    IMGADV_TOUCH_LSK,
    IMGADV_TOUCH_ZOOMIN,
    IMGADV_TOUCH_ZOOMOUT,
    IMGADV_TOUCH_ROTATE,
    IMGADV_TOUCH_LEFT_ARROW,
    IMGADV_TOUCH_RIGHT_ARROW,

    IMGADV_TOUCH_NONE
} imgadv_touch_obj_enum;

imgadv_context_struct g_imgadv_cntx;

#if ((LCD_WIDTH == 128) && (LCD_HEIGHT == 128))
#elif ((LCD_WIDTH == 128) && (LCD_HEIGHT == 160))
#elif ( (LCD_WIDTH == 176) && (LCD_HEIGHT == 220) )
    #define MMI_IMGADV_MAP_WIDTH        40
    #define MMI_IMGADV_MAP_HEIGHT       40
    #define MMI_IMGADV_MAP_POSITION_X   4
    #define MMI_IMGADV_MAP_POSITION_Y   157
    #define MMI_IMGADV_ROTATED_MAP_POSITION_X   170
    #define MMI_IMGADV_ROTATED_MAP_POSITION_Y   110

	imgadv_osd_layout_struct g_imgadv_osd_cntx =
	{
		/****** title ******/
		{TRUE,20, 2, (MAIN_LCD_DEVICE_WIDTH - 40), 20},		
		{TRUE,50,25,76, 20},		
		{TRUE,25,23,0,0,FALSE},	    /* left arrow */
		{TRUE,130,23,0,0,FALSE},	/* right arrow */
		{TRUE,52,176,0,0,FALSE},		/* zoom in */
		{TRUE,78,176,0,0,FALSE},		/* zoom out */			
		{TRUE,104,176,0,0,FALSE},		/* rotate  */
	};

   
	imgadv_osd_layout_struct g_imgadv_osd_cntx_270 =
	{
		/****** title ******/
		{TRUE,5, 5, (MMI_ROTATED_LCD_WIDTH - MMI_ROTATED_SOFTKEY_WIDTH ), 16},		
		{TRUE,45, 24, ((MMI_ROTATED_LCD_WIDTH - MMI_ROTATED_SOFTKEY_WIDTH-90)), 20},		
		{TRUE,16, 24,0,0,FALSE},		/* left arrow */
		{TRUE,144, 24,0,0,FALSE},		/* right arrow */
		{TRUE,52,152,0,0,FALSE},		/* zoom in */
		{TRUE,80,152,0,0,FALSE},		/* zoom out */			
		{TRUE,107,152,0,0,FALSE},		/* rotate  */
	};

#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 320) )

    #define MMI_IMGADV_MAP_WIDTH        50
    #define MMI_IMGADV_MAP_HEIGHT       50
    #define MMI_IMGADV_MAP_POSITION_X   187
    #define MMI_IMGADV_MAP_POSITION_Y   240
    #define MMI_IMGADV_ROTATED_MAP_POSITION_X   267
    #define MMI_IMGADV_ROTATED_MAP_POSITION_Y   160


	imgadv_osd_layout_struct g_imgadv_osd_cntx =
	{
		/****** title ******/
		{TRUE,50, 23, 140, 24},		
		{TRUE,50, 2, 140, 20},		
		{TRUE,25, 25,0,0,FALSE},	/* left arrow */
		{TRUE,195,25,0,0,FALSE},		/* right arrow */
		{TRUE,56,255,0,0,FALSE},		/* zoom in */
		{TRUE,104,255,0,0,FALSE},		/* zoom out */			
		{TRUE,152,255,0,0,FALSE},		/* rotate  */
	};

	imgadv_osd_layout_struct g_imgadv_osd_cntx_270 =
	{
		/****** title ******/
		{TRUE,66, 31, 140, 24},		
		{TRUE,66, 2, 140, 24},		
		{TRUE,37, 35,0,0,FALSE},		/* left arrow */
		{TRUE,212, 35,0,0,FALSE},		/* right arrow */
		{TRUE,54,192,0,0,FALSE},		/* zoom in */
		{TRUE,113,192,0,0,FALSE},		/* zoom out */			
		{TRUE,172,192,0,0,FALSE},		/* rotate  */
	};
#elif ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 240) )

    #define MMI_IMGADV_MAP_WIDTH        50
    #define MMI_IMGADV_MAP_HEIGHT       50
    #define MMI_IMGADV_MAP_POSITION_X   267
    #define MMI_IMGADV_MAP_POSITION_Y   160
    #define MMI_IMGADV_ROTATED_MAP_POSITION_X   187
    #define MMI_IMGADV_ROTATED_MAP_POSITION_Y   240


	imgadv_osd_layout_struct g_imgadv_osd_cntx =
	{
		/****** title ******/
		{TRUE,73, 3, 174, 28},		
		{TRUE,140, 35, 40, 28},		
		{TRUE,52, 9,0,0,FALSE},	/* left arrow */
		{TRUE,249,9,0,0,FALSE},		/* right arrow */
		{TRUE,109,209,0,0,FALSE},		/* zoom in */
		{TRUE,146,209,0,0,FALSE},		/* zoom out */			
		{TRUE,184,209,0,0,FALSE},		/* rotate  */
	};

	imgadv_osd_layout_struct g_imgadv_osd_cntx_270 =
	{
		/****** title ******/
		{TRUE,50, 23, 140, 24},		
		{TRUE,50, 2, 140, 20},		
		{TRUE,25, 25,0,0,FALSE},	/* left arrow */
		{TRUE,195,25,0,0,FALSE},		/* right arrow */
		{TRUE,56,255,0,0,FALSE},		/* zoom in */
		{TRUE,104,255,0,0,FALSE},		/* zoom out */			
		{TRUE,152,255,0,0,FALSE},		/* rotate  */
	};

#endif /* (LCD_WIDTH == XXX && LCD_HEIGHT == xxx) */

static void mmi_imgadv_create_resource(void);
static void mmi_imgadv_free_resource(void);
static void mmi_imgadv_display_error(void);
static void mmi_imgadv_get_active_osd_cntx(void);
static void mmi_imgadv_draw_osd(void);

#ifdef __MMI_TVOUT__
static void mmi_imgadv_tvout_decode(void);
static void mmi_imgadv_tvout_clear_bg(void);
#endif

static void mmi_imgadv_start_decode(void);
static void mmi_imgadv_init_image_info(void);
static void mmi_imgadv_extract_image_to_cache_layer(void);
static void mmi_imgadv_extract_image_to_thumbnail_layer(void);
static void mmi_imgadv_init_osd_icon_position(void);
static void mmi_imgadv_init_key_handler(void);
static void mmi_imgadv_init_default_touch_and_key_handler(void);

#ifdef __MMI_TOUCH_SCREEN__
static BOOL mmi_imgadv_touch_scr_hit_test(S32 pos_x, S32 pos_y, imgadv_osd_icon_struct  *touch_obj);
static void mmi_imgadv_pen_down_hdlr(mmi_pen_point_struct pos);
static void mmi_imgadv_pen_up_hdlr(mmi_pen_point_struct pos);
static void mmi_imgadv_pen_move_hdlr(mmi_pen_point_struct pos);
#endif /* __MMI_TOUCH_SCREEN__ */ 

static void mmi_imgadv_translate(S32 x, S32 y);
static void mmi_imgadv_move_down_press(void);
static void mmi_imgadv_move_left_press(void);
static void mmi_imgadv_move_up_press(void);
static void mmi_imgadv_move_right_press(void);
static void mmi_imgadv_next_image_press(void);
static void mmi_imgadv_previous_image_press(void);
static void mmi_imgadv_next_image_release(void);
static void mmi_imgadv_previous_image_release(void);


static void mmi_imgadv_zoomin_press(void);
static void mmi_imgadv_zoomin_release(void);
static void mmi_imgadv_zoomout_press(void);
static void mmi_imgadv_zoomout_release(void);
static void mmi_imgadv_rotate_press(void);
static void mmi_imgadv_rotate_release(void);
static void mmi_imgadv_lsk_press(void);
static void mmi_imgadv_lsk_release(void);
static void mmi_imgadv_rsk_press(void);
static void mmi_imgadv_rsk_release(void);
#ifdef __MMI_TVOUT__
static void mmi_imgadv_anim_callback(GDI_RESULT result);
#endif

static void mmi_imgadv_scrolling_text_handle(void);

static void mmi_imgadv_draw_style_text(PS8 str, S32 offset_x, S32 offset_y);
static void mmi_imgadv_draw_softkey(void);
static void mmi_imgadv_draw_num_count(void);

static void mmi_imgadv_init_map_box(void);
static void mmi_imgadv_draw_map(void);

static BOOL mmi_imgadv_zoomin(void);
static BOOL mmi_imgadv_zoomout(void);
static void mmi_imgadv_reenter(void);

#if defined(__MMI_BPP_SUPPORT__)
static void mmi_imgadv_bpp_print(void);
#endif

#if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
static void mmi_imgadv_decode_done_callback(GDI_RESULT result, gdi_handle handle);
#endif


#ifdef __DRM_SUPPORT__ 
static imgadv_drm_ret_enum mmi_imgadv_process_drm_hdlr(void);
static void mmi_imgadv_pause_drm_consume_if_need(void);
#endif

#endif

/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Global Variable
*****************************************************************************/
extern BOOL r2lMMIFlag;
/***************************************************************************** 
* Global Function
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/
imgview_context_struct g_imgview_context;


/***************************************************************************** 
* Local Function
*****************************************************************************/
/* view detail image screen */
void mmi_imgview_entry_view_detail_screen(void);
void mmi_imgview_exit_view_detail_screen(void);
void mmi_imgview_view_detail_press_up(void);
void mmi_imgview_view_detail_press_down(void);
static void mmi_imgview_exit_view_detail_release(void);

/* storage setting */
void mmi_imgview_entry_set_storage_screen(void);
void mmi_imgview_hint_set_storage(U16 index);
void mmi_imgview_highlight_set_storage(void);
void mmi_imgview_set_storage_value(void);

/* view style */
void mmi_imgview_entry_set_view_style_screen(void);
void mmi_imgview_set_view_style_value(void);

static void mmi_imgview_display_popup(PU8 str_ptr, U16 img_id, U16 image_on_bottom, U16 tone_duration, U16 tone_id);

/* image util funtion */
static BOOL mmi_imgview_get_storage_disk_path(PS8 drv_buf);
static void mmi_imgview_view_image_hdlr_ext(void);
static void mmi_imgview_exit_view_image_hdlr(void);
static void mmi_imgview_exit_image_screen(void);

#ifdef __DRM_SUPPORT__
static void mmi_imgview_drm_print_callback_hdlr(kal_int32 result, kal_int32 id);
static void mmi_imgview_drm_callback_hdlr(kal_int32 result, kal_int32 id);
static imgview_drm_ret_enum mmi_imgview_process_drm_hdlr(void);
static void mmi_imgview_preprocess_drm_right(void);
#endif


void mmi_imgview_cat222_decode_result_hdlr(GDI_RESULT result);

#if defined(__MMI_BPP_SUPPORT__)
/* bpp static print function */
static void mmi_imgview_xhtml_table_constructor(mmi_bpp_xhtml_rsp_enum rsp_code);
static void mmi_imgview_bpp_callback(mmi_bpp_xhtml_rsp_enum rsp_code);


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_bpp_callback
 * DESCRIPTION
 *  BPP print callback function, called by bpp to give event of print job
 * PARAMETERS
 *  mmi_bpp_xhtml_rsp_enum rsp_code Response Code
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgview_bpp_callback(mmi_bpp_xhtml_rsp_enum rsp_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bpp_xhtml_rsp_enum              rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_imgview_context.is_printing = FALSE;

    if (g_imgview_context.bpp_caption != NULL)
    {
        gui_free(g_imgview_context.bpp_caption);
        g_imgview_context.bpp_caption = NULL;
    }

    if (g_imgview_context.bpp_filepath != NULL)
    {
        gui_free(g_imgview_context.bpp_filepath);    
        g_imgview_context.bpp_filepath = NULL;
    }

    if (rsp_code != MMI_BPP_XHTML_RSP_DONE)
    {
        return;
    }
    
    rsp = app_compose_xhtml_data_element_end();
    if (rsp != MMI_BPP_XHTML_RSP_DONE)
    {       
        return;
    }    
    rsp = app_compose_xhtml_row_element_end();
    if (rsp != MMI_BPP_XHTML_RSP_DONE)
    {       
        return;
    }        
    rsp = app_compose_xhtml_table_element_end();
    if (rsp != MMI_BPP_XHTML_RSP_DONE)
    {       
        return;
    }        
    rsp = app_compose_xhtml_file_end();

#ifdef __DRM_SUPPORT__
    if (rsp == MMI_BPP_XHTML_RSP_DONE)
    {
        if (DRM_get_object_method(NULL,(PU16) g_imgview_context.bpp_filepath) != DRM_METHOD_NONE)
        {
            if (DRM_validate_permission(NULL, (PU16)g_imgview_context.bpp_filepath, DRM_PERMISSION_PRINT))
            {
                U32 drm_id = 0;
                FS_HANDLE bpp_file_handle;

                if ((bpp_file_handle = DRM_open_file((PU16) g_imgview_context.bpp_filepath, FS_READ_ONLY, DRM_PERMISSION_PRINT)) < FS_NO_ERROR)
                ASSERT(0)
                
                kal_prompt_trace(MOD_MMI, "bpp_file_handle = %d\n", bpp_file_handle);
                drm_id = DRM_consume_rights(bpp_file_handle , DRM_PERMISSION_PRINT, mmi_imgview_drm_print_callback_hdlr);
                kal_prompt_trace(MOD_MMI, "drm_id= %d\n", drm_id);
                DRM_stop_consume(drm_id);
                DRM_close_file(bpp_file_handle);
            }
        }            
    }
#endif
    return;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_xhtml_table_constructor
 * DESCRIPTION
 *  BPP print function, forward to BPP Engine 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgview_xhtml_table_constructor(mmi_bpp_xhtml_rsp_enum rsp_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bpp_xhtml_rsp_enum              rsp;
    mmi_bpp_xhtml_table_css_struct*     tab_css;
    mmi_bpp_xhtml_style_class_struct*   cell_css;
    mmi_bpp_xhtml_data_element_struct*  data;
    FS_HANDLE bpp_file_handle;
    S8 css_name[]= "one image only";
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (rsp_code != MMI_BPP_XHTML_RSP_DONE)
    {
        return;
    }    
    
    /* config table css */
    tab_css = (mmi_bpp_xhtml_table_css_struct*)get_ctrl_buffer(sizeof(mmi_bpp_xhtml_table_css_struct));
    
    /* the attributes should be set as 0 if not used */
    memset(tab_css, 0, sizeof(mmi_bpp_xhtml_table_css_struct));
    /* set css */
    tab_css->caption_side = MMI_BPP_XHTML_ALIGN_TOP;
    tab_css->text_align = MMI_BPP_XHTML_ALIGN_CENTER;
    tab_css->text_color = MMI_BPP_XHTML_COLOR_BLACK;
    tab_css->caption_margin = 2;
    
    rsp = app_config_table_css(tab_css);
    free_ctrl_buffer(tab_css);
    if (rsp != MMI_BPP_XHTML_RSP_DONE)
    {       
        return;
    }
    
    /* config cell css */
    cell_css = (mmi_bpp_xhtml_style_class_struct*)get_ctrl_buffer(sizeof(mmi_bpp_xhtml_style_class_struct));
    /* the attributes should be set as 0 if not used */
    memset(cell_css, 0, sizeof(mmi_bpp_xhtml_style_class_struct));
    
    /* prepare style class name name[]*/
    sprintf((PS8)cell_css->class_name, "%s",(PS8)css_name);

    /* set css */
    cell_css->txt_v_align = MMI_BPP_XHTML_ALIGN_TOP;
    cell_css->txt_h_align = MMI_BPP_XHTML_ALIGN_CENTER;   
    
    rsp = app_config_style_class(cell_css);
    free_ctrl_buffer(cell_css);
    if (rsp != MMI_BPP_XHTML_RSP_DONE)
    {        
        return;
    }
    
    /* inline image data from file */
    rsp = app_compose_xhtml_file_start();
    if (rsp != MMI_BPP_XHTML_RSP_DONE)
    {       
        return;
    }
    
    /* prepare caption[] */
    rsp = app_compose_xhtml_table_element_start(g_imgview_context.bpp_caption, strlen((PS8)g_imgview_context.bpp_caption));    //utf-8(ascii) encoded
    if (rsp != MMI_BPP_XHTML_RSP_DONE)
    {       
        return;
    }
    
    rsp = app_compose_xhtml_row_element_start();
    if (rsp != MMI_BPP_XHTML_RSP_DONE)
    {       
        return;
    }
    
    rsp = app_compose_xhtml_data_element_start();
    if (rsp != MMI_BPP_XHTML_RSP_DONE)
    {       
        return;
    }
    
    /* compose function */
    /* compose data element structure */
    data = (mmi_bpp_xhtml_data_element_struct*)get_ctrl_buffer(sizeof(mmi_bpp_xhtml_data_element_struct));
    /* the attributes should be set as 0 if not used */
    memset(data, 0, sizeof(mmi_bpp_xhtml_data_element_struct));
    
    /* set attributes */
    sprintf((PS8)data->class_name, "%s",(PS8)css_name);

    data->name_len = strlen((PS8)css_name);
    
    if ((bpp_file_handle = DRM_open_file((PU16) g_imgview_context.bpp_filepath, FS_READ_ONLY, DRM_PERMISSION_PRINT)) < FS_NO_ERROR)
    {
        mmi_imgview_display_popup(
            (PU8) GetString(FMGR_FS_FILE_NOT_FOUND_TEXT),
                IMG_GLOBAL_WARNING,
                1,
                ST_NOTIFYDURATION,
                WARNING_TONE);
        DeleteUptoScrID(SCR_ID_IMGVIEW_VIEW);
        DeleteScreenIfPresent(SCR_ID_IMGVIEW_VIEW);
        DeleteUptoScrID(SCR_ID_IMGVIEW_FROM_FMGR);
        DeleteScreenIfPresent(SCR_ID_IMGVIEW_FROM_FMGR);
        return;
    }
    
    /* prepare the image FS_HANDLE open by DRM API */    
    data->file_element = bpp_file_handle;
    
    /* prepare the image file size*/
    data->obj_len = g_imgview_context.file_size;
    data->app_callback = mmi_imgview_bpp_callback;
    
    switch(g_imgview_context.image_type)
    {
        case GDI_IMAGE_TYPE_JPG :
        case GDI_IMAGE_TYPE_JPG_FILE :
            data->type = MMI_BPP_XHTML_TYPE_JPG;
            break;
        case GDI_IMAGE_TYPE_GIF :
        case GDI_IMAGE_TYPE_GIF_FILE :
            data->type = MMI_BPP_XHTML_TYPE_GIF;
            break;
        case GDI_IMAGE_TYPE_BMP :
        case GDI_IMAGE_TYPE_BMP_FILE :
            data->type = MMI_BPP_XHTML_TYPE_BMP;
            break;
        case GDI_IMAGE_TYPE_PNG :
        case GDI_IMAGE_TYPE_PNG_FILE:
            data->type = MMI_BPP_XHTML_TYPE_PNG;            
            break;            
        case GDI_IMAGE_TYPE_WBMP :
        case GDI_IMAGE_TYPE_WBMP_FILE:
            data->type = MMI_BPP_XHTML_TYPE_WBMP;            
            break;            
        case GDI_IMAGE_TYPE_SVG :
        case GDI_IMAGE_TYPE_SVG_FILE:
            data->type = MMI_BPP_XHTML_TYPE_SVG;            
            break;            
    }
    data->img_box = 80; //80% width of paper
    rsp = app_compose_xhtml_data_element_from_file(data);
    free_ctrl_buffer(data);    
    switch (rsp)
    {
        case MMI_BPP_XHTML_RSP_WRITING:
            return;
        case MMI_BPP_XHTML_RSP_DONE:
            mmi_imgview_bpp_callback(rsp);
            return;
        default:
            return;
    }
}    


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_bpp_print_file
 * DESCRIPTION
 *  external BPP print function, forward to BPP Engine 
 * PARAMETERS
 *  filepath IN filepath of printed file
 *  is_short IN one property of filepath 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_bpp_print_file(PS8 filepath,BOOL is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* allocate string buffer */
    g_imgview_context.filepath = gui_malloc(FMGR_PATH_BUFFER_SIZE);

    mmi_ucs2cpy((PS8) g_imgview_context.filepath , (PS8) filepath);
    g_imgview_context.image_type = gdi_image_get_type_from_file(g_imgview_context.filepath);
    g_imgview_context.is_short = is_short;

    mmi_imgview_bpp_print();
    /* free string buffer */
    if (g_imgview_context.filepath != NULL)
    {
        gui_free(g_imgview_context.filepath);
        g_imgview_context.filepath = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_bpp_print
 * DESCRIPTION
 *  BPP print function, forward to BPP Engine 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_bpp_print(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fs_handle;
    S32 str_len,index;
    U8 filename_no_ext[FMGR_PATH_BUFFER_SIZE];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imgview_context.is_printing == TRUE)
        ASSERT(0);

    switch(g_imgview_context.image_type)
    {
        case GDI_IMAGE_TYPE_JPG :
        case GDI_IMAGE_TYPE_JPG_FILE :
        case GDI_IMAGE_TYPE_GIF :
        case GDI_IMAGE_TYPE_GIF_FILE :
        case GDI_IMAGE_TYPE_BMP :
        case GDI_IMAGE_TYPE_BMP_FILE :
        case GDI_IMAGE_TYPE_PNG :
        case GDI_IMAGE_TYPE_PNG_FILE:
        case GDI_IMAGE_TYPE_WBMP :
        case GDI_IMAGE_TYPE_WBMP_FILE:
        case GDI_IMAGE_TYPE_SVG :
        case GDI_IMAGE_TYPE_SVG_FILE:
            break;            
        default:
            mmi_imgview_display_popup(
                (PU8) GetString(STR_ID_IMGVIEW_PRINT_NOT_SUPPORT),
                    IMG_GLOBAL_WARNING,
                    1,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);
            return;
            break;
    }


    if (mmi_bt_bpp_app_is_printing() == MMI_BPP_PRINT_STATUS_BUSY)
    {
        mmi_bt_bpp_busy_popup();   
    }
    else
    {
        g_imgview_context.is_printing = TRUE;

        g_imgview_context.bpp_caption = gui_malloc(FMGR_PATH_BUFFER_SIZE);
        g_imgview_context.bpp_filepath = gui_malloc(FMGR_PATH_BUFFER_SIZE);

        /* get file size and is_short */
        fs_handle = DRM_open_file((U16*)g_imgview_context.filepath, FS_READ_ONLY, DRM_PERMISSION_PRINT);

        if (fs_handle < 0)
        {
            mmi_imgview_display_popup(
                (PU8) GetString(GetFileSystemErrorString(fs_handle)),
                IMG_GLOBAL_WARNING,
                1,
                ST_NOTIFYDURATION,
                WARNING_TONE);

            if (fs_handle == FS_PATH_NOT_FOUND || fs_handle == FS_ACCESS_DENIED)
            {
                U16 scrnid;
                for(scrnid= SCR_ID_IMGVIEW_VIEW; scrnid <= SCR_ID_IMGVIEW_FROM_FMGR; scrnid++)
                {
                    DeleteScreenIfPresent(scrnid);
                }
            }
            return;
        }
        else
        {
            DRM_file_size(fs_handle, (kal_uint32*) &(g_imgview_context.file_size));
            DRM_close_file(fs_handle);
        }
   
        mmi_ucs2cpy((PS8) g_imgview_context.bpp_filepath , (PS8) g_imgview_context.filepath);

        str_len = mmi_ucs2strlen(g_imgview_context.filepath);

        /* find file name - by finding "\\" */
        for (index = str_len * 2 - 2; index >= 2; index -= 2)
        {
            if (mmi_ucs2ncmp((PS8) & g_imgview_context.filepath[index], (PS8) L"\\", 1) == 0)
            {
                index += 2;
                break;
            }
        }

        if (g_imgview_context.is_short)
        {
            mmi_chset_mixed_text_to_ucs2_str(
                (U8*) filename_no_ext,
                FMGR_PATH_BUFFER_SIZE,
                (U8*) (&(g_imgview_context.filepath[index])),
                PhnsetGetDefEncodingType());
        }
        else
        {   
            mmi_ucs2cpy((PS8) filename_no_ext, (PS8) (&(g_imgview_context.filepath[index])));
        }
        mmi_fmgr_hide_ext_name((PS8)filename_no_ext);
        mmi_chset_convert(MMI_CHSET_UCS2, MMI_CHSET_UTF8,(char*)filename_no_ext, (char*)g_imgview_context.bpp_caption, FMGR_PATH_BUFFER_SIZE );

        mmi_bt_bpp_app_print(MMI_BPP_APP_IMG, mmi_imgview_xhtml_table_constructor);    
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_is_printing
 * DESCRIPTION
 *  query if there is any print request
 * PARAMETERS
 *  void
 * RETURNS
 *  BOOL is there any printing job.
 *****************************************************************************/
BOOL mmi_imgview_is_printing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return g_imgview_context.is_printing;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_cancel_printing
 * DESCRIPTION
 *  de-init print resource
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_cancel_printing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imgview_context.bpp_caption != NULL)
    {
        gui_free(g_imgview_context.bpp_caption);
        g_imgview_context.bpp_caption = NULL;
    }

    if (g_imgview_context.bpp_filepath != NULL)
    {
        gui_free(g_imgview_context.bpp_filepath);    
        g_imgview_context.bpp_filepath = NULL;
    }

    g_imgview_context.is_printing = FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_deinitial_printing
 * DESCRIPTION
 *  release resource and reset print variables
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_deinitial_printing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imgview_context.filepath != NULL)
    {
        gui_free(g_imgview_context.filepath);
        g_imgview_context.filepath = NULL;
    }
}

#endif


/*****************************************************************************
*
* Image Viewer View Large Image                                                                
*
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_exit_view_image_hdlr
 * DESCRIPTION
 *  event hdlr: call this to exit imgview 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgview_exit_view_image_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_BPP_SUPPORT__)
    mmi_imgview_deinitial_printing();
#endif

#ifdef __DRM_SUPPORT__
    mmi_imgview_pause_drm_consume_if_need();
#endif

    GoBackHistory();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_exit_image_screen
 * DESCRIPTION
 *  exit imgview (fmgr) screen function: should sub drm right counts.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgview_exit_image_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __DRM_SUPPORT__   
    /* based on DEL SCR will do first */
    if (g_imgview_context.drm_state == IMGVIEW_DRM_STATE_CONSUME)
    {
        DRM_pause_consume(g_imgview_context.drm_id);
        g_imgview_context.drm_state = IMGVIEW_DRM_STATE_PAUSE;
    }
    #endif
    g_imgview_context.result = MMI_IMGVIEW_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_view_image_hdlr_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgview_view_image_hdlr_ext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer=NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_IMGVIEW_FROM_FMGR, mmi_imgview_exit_image_screen, mmi_imgview_view_image_hdlr_ext, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMGVIEW_FROM_FMGR);
    SetDelScrnIDCallbackHandler(SCR_ID_IMGVIEW_FROM_FMGR, mmi_imgview_view_from_fmgr_del_scr_callback);


    if (g_imgview_context.filepath != NULL)
    g_imgview_context.image_type = gdi_image_get_type_from_file(g_imgview_context.filepath);

    /* check DRM rights */
#ifdef __DRM_SUPPORT__
    mmi_imgview_preprocess_drm_right();
#endif 


#ifdef __MMI_MESSAGES_EMS__
    if (FMGR_FILTER_IS_SET(&g_imgview_context.file_type, FMGR_TYPE_EMS))
    {
        ShowCategory144Screen(
            0,
            g_imgview_context.title_icon,
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            EMS_OBJECT_MY_PICTURE_STATE | CATEGORY144_FMGR_PREVIEW,
            1,
            NULL,
            (U16*) g_imgview_context.filepath,
            g_imgview_context.is_short,
            NULL,
            0,
            NULL);
    }
    else if (FMGR_FILTER_IS_SET(&g_imgview_context.file_type, FMGR_TYPE_ANM))
    {
        ShowCategory144Screen(
            0,
            g_imgview_context.title_icon,
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            EMS_OBJECT_MY_ANIMATION_STATE | CATEGORY144_FMGR_PREVIEW,
            1,
            NULL,
            (U16*) g_imgview_context.filepath,
            g_imgview_context.is_short,
            NULL,
            0,
            NULL);
    }
    else
#endif /* __MMI_MESSAGES_EMS__ */ 
    {
        /* entry cat222 to decode and display a image from file */
#if defined(__MMI_BPP_SUPPORT__)
        #ifdef __DRM_SUPPORT__
        if (mmi_bootup_get_active_flight_mode() == 0 && (IMGVIEW_DRM_PRINT_VALID & g_imgview_context.drm_valid)!=0 )
        #else
        if (mmi_bootup_get_active_flight_mode() == 0)
        #endif
        {
        #ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
            if (mmi_is_redrawing_bk_screens() == FALSE && mmi_imgview_is_printing())
        #else
            if (mmi_imgview_is_printing())
        #endif /* __MMI_UI_SMALL_SCREEN_SUPPORT__ */
            {
                mmi_imgview_cancel_printing();
            }

            ShowCategory222Screen(
                    0,                                              /* title */
                    g_imgview_context.title_icon,                   /* title icon */
                    STR_ID_IMGVIEW_PRINT,
                    IMG_GLOBAL_OPTIONS, 
                    STR_GLOBAL_BACK,
                    IMG_GLOBAL_BACK,                                /* right soft key */
                    GDI_COLOR_WHITE,                                /* content BG color */
                    (PS8) NULL,                                     /* button bar string */
                    (PS8) g_imgview_context.filepath,                        /* image file name */
                    g_imgview_context.is_short,                             /* is_short */
                    mmi_imgview_cat222_decode_result_hdlr,/* result callback */
                    GDI_IMAGE_SRC_FROM_FILE);
            
            SetLeftSoftkeyFunction(mmi_imgview_bpp_print,KEY_EVENT_UP);
            SetRightSoftkeyFunction(mmi_imgview_exit_view_image_hdlr, KEY_EVENT_UP);
            return;
        }
        else
#endif
        {
            ShowCategory222Screen(
                    0,                                              /* title */
                    g_imgview_context.title_icon,                   /* title icon */
                    0,
                    0, 
                    STR_GLOBAL_BACK,
                    IMG_GLOBAL_BACK,                                /* right soft key */
                    GDI_COLOR_WHITE,                                /* content BG color */
                    (PS8) NULL,                                     /* button bar string */
                    (PS8) g_imgview_context.filepath,                        /* image file name */
                    g_imgview_context.is_short,                             /* is_short */
                    mmi_imgview_cat222_decode_result_hdlr,/* result callback */
                    GDI_IMAGE_SRC_FROM_FILE);                       /* result callback */
        }
    }
    SetRightSoftkeyFunction(mmi_imgview_exit_view_image_hdlr, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_view_image_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_view_image_hdlr(PS8 file_path,BOOL is_short,FMGR_FILTER file_type, U16 title_icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_imgview_context.filepath = gui_malloc(FMGR_PATH_BUFFER_SIZE); 
    mmi_ucs2cpy((PS8) g_imgview_context.filepath , (PS8) file_path);
    g_imgview_context.is_short = is_short;
    g_imgview_context.file_type = file_type;
    g_imgview_context.title_icon = title_icon;
    mmi_imgview_view_image_hdlr_ext();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_remove_screen_if_present
 * DESCRIPTION
 *  remove screen if screnn exist in history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_remove_screen_if_present(U8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrnid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (app_id != APP_IMAGEVIEWER)
    {
        for(scrnid= SCR_ID_IMGVIEW_VIEW; scrnid <= SCR_ID_IMGVIEW_VIEW_STYLE; scrnid++)
        {
            DeleteScreenIfPresent(scrnid);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_highlight_view_detail
 * DESCRIPTION
 *  highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_highlight_view_detail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_IMAGEVIEWER_ADV__
    SetLeftSoftkeyFunction(mmi_imgadv_entry_app_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_imgadv_entry_app_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#else /* __MMI_IMAGEVIEWER_ADV__ */ 
    SetLeftSoftkeyFunction(mmi_imgview_entry_view_detail_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_imgview_entry_view_detail_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#endif /* __MMI_IMAGEVIEWER_ADV__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_view_detail_press_up
 * DESCRIPTION
 *  press up in view detail screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_view_detail_press_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;
    S32 cur_index;
    FMGR_FILE_INFO_STRUCT file_info;
    S32 counter;
    S32 file_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DRM_SUPPORT__
    mmi_imgview_pause_drm_consume_if_need();
#endif

    /* exit and clear previous screen for history - then enter again */
    cur_index = mmi_fmgr_kernel_get_cur_idx();
    file_count = mmi_fmgr_kernel_get_file_count();
    counter = 0;

    if (file_count > 1)
    {
        do
        {
            mmi_fmgr_kernel_move_selection_up();
            index = mmi_fmgr_kernel_get_cur_idx();
            mmi_fmgr_kernel_get_file_info(index, &file_info);

            counter++;

            if (!(file_info.attribute & FS_ATTR_DIR))
            {
                EntryNewScreen(SCR_ID_IMGVIEW_VIEW, NULL, NULL, NULL);
                DeleteScreenIfPresent(SCR_ID_IMGVIEW_VIEW);
            #ifdef __MMI_IMAGEVIEWER_ADV__
                mmi_imgadv_entry_app_screen();
            #else 
                mmi_imgview_entry_view_detail_screen();
            #endif 
                return;
            }

            if (counter >= (file_count - 1))
            {
                return;
            }

        } while (1);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_view_detail_press_down
 * DESCRIPTION
 *  press down in view detail screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_view_detail_press_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;
    S32 cur_index;
    FMGR_FILE_INFO_STRUCT file_info;
    S32 counter;
    S32 file_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DRM_SUPPORT__
    mmi_imgview_pause_drm_consume_if_need();
#endif

    /* exit and clear previous screen for history - then enter again */
    cur_index = mmi_fmgr_kernel_get_cur_idx();
    file_count = mmi_fmgr_kernel_get_file_count();
    counter = 0;

    if (file_count > 1)
    {
        do
        {
            mmi_fmgr_kernel_move_selection_down();
            index = mmi_fmgr_kernel_get_cur_idx();
            mmi_fmgr_kernel_get_file_info(index, &file_info);

            counter++;

            if (!(file_info.attribute & FS_ATTR_DIR))
            {
                EntryNewScreen(SCR_ID_IMGVIEW_VIEW, NULL, NULL, NULL);
                DeleteScreenIfPresent(SCR_ID_IMGVIEW_VIEW);
            #ifdef __MMI_IMAGEVIEWER_ADV__
                mmi_imgadv_entry_app_screen();
            #else 
                mmi_imgview_entry_view_detail_screen();
            #endif 

                return;
            }

            if (counter >= (file_count - 1))
            {
                return;
            }

        } while (1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_exit_view_detail_screen
 * DESCRIPTION
 *  exit view detail screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_exit_view_detail_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* free buffer */
    if (g_imgview_context.filepath != NULL)
    {
        gui_free(g_imgview_context.filepath);
        g_imgview_context.filepath = NULL;
    }

    if (g_imgview_context.count_str != NULL)
    {
        gui_free(g_imgview_context.count_str);
        g_imgview_context.count_str = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_exit_view_detail_release
 * DESCRIPTION
 *  imgview view exit function handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgview_exit_view_detail_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __DRM_SUPPORT__
    mmi_imgview_pause_drm_consume_if_need();
    #endif

    g_imgview_context.result = MMI_IMGVIEW_OK;
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_view_detail_del_scr_callback
 * DESCRIPTION
 *  imgview view detail delete screen callback handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_imgview_view_detail_del_scr_callback(void* ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_imgview_context.filepath != NULL)
    {
        gui_free(g_imgview_context.filepath);
        g_imgview_context.filepath = NULL;
    }

    #ifdef __DRM_SUPPORT__
        mmi_imgview_pause_drm_consume_if_need();
    #endif

    #if defined(__MMI_BPP_SUPPORT__)
        mmi_imgview_deinitial_printing();
    #endif

    g_imgview_context.result = MMI_IMGVIEW_OK;
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_entry_view_detail_screen
 * DESCRIPTION
 *  entry view detail screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_entry_view_detail_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT file_info;
    S32 index;
    S32 total_count;
    S8 buffer[30];  /* for xxxx/xxxx */
    U8 *guiBuffer;
    S8 *buf_filepath;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* exit previous screen */
    EntryNewScreen(
        SCR_ID_IMGVIEW_VIEW,
        mmi_imgview_exit_view_detail_screen,
        mmi_imgview_entry_view_detail_screen,
        NULL);

    SetDelScrnIDCallbackHandler(SCR_ID_IMGVIEW_VIEW, mmi_imgview_view_detail_del_scr_callback);

#if defined(__MMI_BPP_SUPPORT__)
    if (mmi_imgview_is_printing())
    {
        mmi_imgview_cancel_printing();
    }
#endif

    /* allocate string buffer */
    g_imgview_context.filepath = gui_malloc(FMGR_PATH_BUFFER_SIZE);
    g_imgview_context.count_str = gui_malloc(60);

    /* prepare xxxx/xxxx string */
    index = mmi_fmgr_kernel_get_cur_idx();
    total_count = mmi_fmgr_kernel_get_file_count();

    mmi_fmgr_kernel_get_file_info(index, &file_info);
    sprintf(buffer, "%d/%d", (U16) index + 1, (U16) total_count);
    mmi_asc_to_ucs2((PS8) g_imgview_context.count_str, (PS8) buffer);

    /* append the name to path */
    mmi_fmgr_kernel_get_path_name(g_imgview_context.filepath);


    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMGVIEW_VIEW);
    if (guiBuffer != NULL)
    {
        buf_filepath = gui_malloc(FMGR_PATH_BUFFER_SIZE);
        ASSERT(buf_filepath!=NULL);
        mmi_imgview_get_storage_file_path(buf_filepath);

        if (mmi_ucs2cmp(buf_filepath, g_imgview_context.filepath) != 0)
        {
            gui_free(buf_filepath);
            DeleteScreenIfPresent(SCR_ID_IMGVIEW_VIEW);
            GoBackHistory();
            return;
        }
        gui_free(buf_filepath);        
    }

    /* build full patch */
    mmi_ucs2cat(g_imgview_context.filepath, file_info.file_name);

    /* DRM permission check */
#ifdef __DRM_SUPPORT__
    mmi_imgview_preprocess_drm_right();
#endif 

    g_imgview_context.is_short = file_info.is_short;
    g_imgview_context.image_type = gdi_image_get_type_from_file(g_imgview_context.filepath);

    /* entry cat222 to decode and display a image from file */
#if defined(__MMI_BPP_SUPPORT__)
    #ifdef __DRM_SUPPORT__
    if (mmi_bootup_get_active_flight_mode() == 0 && (IMGVIEW_DRM_PRINT_VALID & g_imgview_context.drm_valid)!=0 )
    #else
    if (mmi_bootup_get_active_flight_mode() == 0)
    #endif
    {
        ShowCategory222Screen(
            0,
            GetRootTitleIcon(MENU_ID_IMGVIEW_APP),    /* title */
            STR_ID_IMGVIEW_PRINT,
            IMG_GLOBAL_OPTIONS,                                  /* left soft key */
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,                    /* right soft key */
            GDI_COLOR_WHITE,                    /* content BG color */
            (PS8) NULL,  /* button bar string */
            (PS8) g_imgview_context.filepath,   /* image file name */
            file_info.is_short,                 /* is short filename */
            mmi_imgview_cat222_decode_result_hdlr,/* result callback */
            GDI_IMAGE_SRC_FROM_FILE);                              
        SetLeftSoftkeyFunction(mmi_imgview_bpp_print,KEY_EVENT_UP);
    }
    else
    {
        ShowCategory222Screen(
            0,
            GetRootTitleIcon(MENU_ID_IMGVIEW_APP),    /* title */
            0,
            0,                                  /* left soft key */
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,                    /* right soft key */
            GDI_COLOR_WHITE,                    /* content BG color */
            (PS8) g_imgview_context.count_str,  /* button bar string */
            (PS8) g_imgview_context.filepath,   /* image file name */
            file_info.is_short,                 /* is short filename */
            mmi_imgview_cat222_decode_result_hdlr,/* result callback */
            GDI_IMAGE_SRC_FROM_FILE);   
    }
#else
    ShowCategory222Screen(
        0,
        GetRootTitleIcon(MENU_ID_IMGVIEW_APP),    /* title */
        0,
        0,                                  /* left soft key */
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,                    /* right soft key */
        GDI_COLOR_WHITE,                    /* content BG color */
        (PS8) g_imgview_context.count_str,  /* button bar string */
        (PS8) g_imgview_context.filepath,   /* image file name */
        file_info.is_short,                 /* is short filename */
        mmi_imgview_cat222_decode_result_hdlr,                               /* result callback */
        GDI_IMAGE_SRC_FROM_FILE);                              
#endif

    /* if less or equal to 1 image, no need to switch to next image */
    if (total_count > 1)
    {
        SetKeyHandler(mmi_imgview_view_detail_press_up, KEY_UP_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_imgview_view_detail_press_down, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_imgview_view_detail_press_down, KEY_VOL_DOWN, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_imgview_view_detail_press_up, KEY_VOL_UP, KEY_EVENT_DOWN);
    }

    SetRightSoftkeyFunction(mmi_imgview_exit_view_detail_release, KEY_EVENT_UP);
}

/*****************************************************************************
*
* Select Prefered Storage                                                                
*
*****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_hint_set_storage
 * DESCRIPTION
 *  set storage's hint
 * PARAMETERS
 *  index       [IN]        
 *  a(?)        [IN]        Selection index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_hint_set_storage(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((PS8) hintData[(index)], 0, sizeof(hintData[(index)]));
    mmi_fmgr_get_drive_name((S8)g_imgview_context.storage, (S8*)hintData, (FMGR_MAX_DRIVE_NAME_LEN + 1) * ENCODING_LENGTH);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_highlight_set_storage
 * DESCRIPTION
 *  set storage's highlight
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_highlight_set_storage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imgview_entry_set_storage_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_imgview_entry_set_storage_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_highlight_set_view_style
 * DESCRIPTION
 *  set view style
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_highlight_set_view_style(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imgview_entry_set_view_style_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_imgview_entry_set_view_style_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_get_drive_callback
 * DESCRIPTION
 *  entry storage screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_set_drive_callback( S8 drv_letter )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /***************************************************
     * for new storage error handling machenism 
     ***************************************************/
    if (drv_letter == 0 && !IsScreenPresent(SCR_ID_CAMERA_OPTION))
    {
        DeleteScreenIfPresent(SCR_ID_IMGVIEW_STORAGE);
        if (g_imgview_context.is_storage_ready == FALSE)
        {
            DeleteUptoScrID(SCR_ID_IMGVIEW_APP);
            DeleteScreenIfPresent(SCR_ID_IMGVIEW_APP);
            g_imgview_context.is_storage_ready = TRUE;
        }
        return;
    }
    mmi_imgview_get_drive_callback(drv_letter);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_cat222_decode_result_hdlr
 * DESCRIPTION
 *  handle decode result, it is callback from cat222
 * PARAMETERS
 *  void
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
void mmi_imgview_cat222_decode_result_hdlr(GDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __DRM_SUPPORT__
    if (g_imgview_context.drm_handle != NULL)
    {
        if (result >= 0)
        {
            g_imgview_context.drm_id = 
                DRM_consume_rights(g_imgview_context.drm_handle, DRM_PERMISSION_DISPLAY, mmi_imgview_drm_callback_hdlr);
            g_imgview_context.drm_state = IMGVIEW_DRM_STATE_CONSUME;
        }

        DRM_close_file(g_imgview_context.drm_handle);
        g_imgview_context.drm_handle = NULL;
    }
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_get_drive_callback
 * DESCRIPTION
 *  entry storage screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_get_drive_callback( S8 drv_letter )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_filepath[FMGR_PATH_BUFFER_SIZE];
    S32 create_result;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (drv_letter != 0)
    {
        g_imgview_context.storage = (U16) drv_letter;
            
        mmi_imgview_get_storage_file_path(buf_filepath);
        create_result = mmi_imgview_create_file_dir(buf_filepath);
        g_imgview_context.is_storage_ready = FALSE;

        if (create_result == FS_WRITE_PROTECTION)
        {
            mmi_imgview_display_popup((PU8) GetString(FMGR_FS_WRITE_PROTECTION_TEXT),
                                        IMG_GLOBAL_WARNING,
                                        0,
                                        ST_NOTIFYDURATION,
                                        WARNING_TONE);
        }
        else if (create_result == FS_DISK_FULL)
        {
            mmi_imgview_display_popup((PU8) GetString(FMGR_FS_DISK_FULL_TEXT),
                                      IMG_GLOBAL_WARNING,
                                      0,
                                      ST_NOTIFYDURATION,
                                      WARNING_TONE);


        }
        else if (create_result == FS_ROOT_DIR_FULL)
        {
            mmi_imgview_display_popup((PU8) GetString(FMGR_FS_ROOT_DIR_FULL_TEXT),
                                      IMG_GLOBAL_WARNING,
                                      0,
                                      ST_NOTIFYDURATION,
                                      WARNING_TONE);
        }
        else
        {
            g_imgview_context.is_storage_path_changed = TRUE;
            g_imgview_context.is_storage_ready = TRUE;
            mmi_imgview_display_popup((PU8) GetString(STR_GLOBAL_DONE),
                                      IMG_GLOBAL_ACTIVATED,
                                      0,
                                      ST_NOTIFYDURATION,
                                      SUCCESS_TONE);
        #ifdef __MMI_CAMERA__
            DeleteScreenIfPresent(SCR_ID_CAMERA_STORAGE);
        #endif
        }

        DeleteUptoScrID(SCR_ID_IMGVIEW_APP);
        /* storge setting to NVRAM */
        WriteValue(NVRAM_IMGVIEW_STORAGE, &g_imgview_context.storage, DS_SHORT, &error);
    }
    else
    {
        DeleteScreenIfPresent(SCR_ID_IMGVIEW_STORAGE);
    #ifdef __MMI_CAMERA__
        if (IsScreenPresent(SCR_ID_CAMERA_OPTION))
        DeleteScreenIfPresent(SCR_ID_CAMERA_STORAGE);
    #endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_entry_set_storage_screen
 * DESCRIPTION
 *  enter set storage screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_entry_set_storage_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_IMGVIEW_STORAGE, NULL, mmi_imgview_entry_set_storage_screen, NULL);
#if defined(__MMI_CAMERA__)
    mmi_fmgr_sel_drv_and_enter(APP_CAMERA,mmi_imgview_set_drive_callback, g_imgview_context.storage);
#else
    mmi_fmgr_sel_drv_and_enter(APP_IMAGEVIEWER,mmi_imgview_set_drive_callback, g_imgview_context.storage);
#endif
}

/*****************************************************************************
*
* View Style                                                             
*
*****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_entry_set_view_style_screen
 * DESCRIPTION
 *  enter set view style screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_entry_set_view_style_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 item_list[16];
    U16 item_icon[16];
    U16 num_item;
    S16 error;
    U8 imgview_style;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_IMGVIEW_VIEW_STYLE, NULL, mmi_imgview_entry_set_view_style_screen, NULL);

    num_item = GetNumOfChild(MENU_ID_IMGVIEW_VIEW_STYLE);
    GetSequenceStringIds(MENU_ID_IMGVIEW_VIEW_STYLE, item_list);
    GetSequenceImageIds(MENU_ID_IMGVIEW_VIEW_STYLE, item_icon);
    SetParentHandler(MENU_ID_IMGVIEW_VIEW_STYLE);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ReadValue(NVRAM_IMGVIEW_VIEW_SYTLE, &imgview_style, DS_BYTE, &error);

    ShowCategory11Screen(
        STR_ID_IMGVIEW_VIEW_STYLE,
        GetRootTitleIcon(MENU_ID_IMGVIEW_APP),              /* title */
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_item,
        item_list,
        imgview_style,  /* current index */
        NULL);

    SetLeftSoftkeyFunction(mmi_imgview_set_view_style_value, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_set_view_style_value
 * DESCRIPTION
 *  set view style value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_set_view_style_value(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 imgview_style;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imgview_style = (U8) GetCurrHiliteID();

    WriteValue(NVRAM_IMGVIEW_VIEW_SYTLE, &imgview_style, DS_BYTE, &error);
    mmi_imgview_display_popup(
        (PU8) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        1,
        ST_NOTIFYDURATION,
        SUCCESS_TONE);

    DeleteNHistory(2);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_get_view_style
 * DESCRIPTION
 *  set view style value
 * PARAMETERS
 *  void
 * RETURNS
 *  U16   style (0 = IMGVIEW_VIEW_STYLE_LIST, 1 = IMGVIEW_VIEW_STYLE_MATRIX)
 *****************************************************************************/
U16 mmi_imgview_get_view_style(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 imgview_style;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imgview_style = (U8) GetCurrHiliteID();

    ReadValue(NVRAM_IMGVIEW_VIEW_SYTLE, &imgview_style, DS_BYTE, &error);

    if (imgview_style == 0xff)
    {
        imgview_style = IMGVIEW_VIEW_STYLE_LIST;
        WriteValue(NVRAM_IMGVIEW_VIEW_SYTLE, &imgview_style, DS_BYTE, &error);
    }

    return (U16) imgview_style;
}

/*****************************************************************************
*
* Initialization and Entry of ImageViewer Application                                                                  
*
*****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_highlight_app
 * DESCRIPTION
 *  app hilight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_highlight_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imgview_entry_app, KEY_EVENT_UP);
    SetKeyHandler(mmi_imgview_entry_app, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_init_app
 * DESCRIPTION
 *  init imageviwer applcation, register highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_init_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* init imageviewer application entry handler */
#if defined(__MMI_SCREEN_ROTATE__)
    g_imgview_context.imgview_rotate = 0;
#endif 
    g_imgview_context.is_printing = FALSE;
    g_imgview_context.is_storage_path_changed = FALSE;
    g_imgview_context.is_storage_ready = TRUE;
    g_imgview_context.result = MMI_IMGVIEW_OK;

#ifdef __DRM_SUPPORT__
    g_imgview_context.drm_state = IMGVIEW_DRM_STATE_EXIT;
    g_imgview_context.drm_id = 0;
    g_imgview_context.drm_handle = NULL;
#endif


#ifdef __MMI_IMAGEVIEWER_ADV__
    g_imgadv_cntx.is_err_displayed = FALSE;

    #ifdef __DRM_SUPPORT__
        g_imgadv_cntx.drm_state = IMGADV_DRM_STATE_EXIT;
        g_imgadv_cntx.drm_id = 0;
        g_imgadv_cntx.drm_handle = NULL;
    #endif
#endif
    mmi_imgview_load_setting();

    SetHiliteHandler(MENU_ID_IMGVIEW_APP, mmi_imgview_highlight_app);

    SetHiliteHandler(MENU_ID_IMGVIEW_VIEW_DETAIL, mmi_imgview_highlight_view_detail);
    SetHiliteHandler(MENU_ID_IMGVIEW_STORAGE, mmi_imgview_highlight_set_storage);
    SetHiliteHandler(MENU_ID_IMGVIEW_VIEW_STYLE, mmi_imgview_highlight_set_view_style);

    SetHintHandler(MENU_ID_IMGVIEW_STORAGE, mmi_imgview_hint_set_storage);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_exit_from_fmgr
 * DESCRIPTION
 *  exit function called by fmgr
 * PARAMETERS
 *  filename        [IN]        Filename(not used here)
 *  is_short        [IN]        
 *  is_shot(?)      [IN]        Is it short naming
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_exit_from_fmgr(void *filename, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteUptoScrID(SCR_ID_IMGVIEW_APP);
    DeleteNHistory(1);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_exit_from_fmgr_emptry_folder
 * DESCRIPTION
 *  exit function called by fmgr in empty folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_exit_from_fmgr_emptry_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteUptoScrID(SCR_ID_IMGVIEW_APP);
    DeleteNHistory(1);
    GoBackHistory();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_view_from_fmgr_del_scr_callback
 * DESCRIPTION
 *  imgview delete screen callback handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_imgview_view_from_fmgr_del_scr_callback(void* ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_imgview_context.filepath != NULL)
    {
        gui_free(g_imgview_context.filepath);
        g_imgview_context.filepath = NULL;
    }

    #ifdef __DRM_SUPPORT__
        mmi_imgview_pause_drm_consume_if_need();
    #endif

    #if defined(__MMI_BPP_SUPPORT__)
        mmi_imgview_deinitial_printing();
    #endif

    g_imgview_context.result = MMI_IMGVIEW_OK;
    return 0;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_del_scr_callback
 * DESCRIPTION
 *  imgview delete screen callback handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_imgview_del_scr_callback(void* ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgview_context.is_storage_ready = TRUE;

    #ifdef __DRM_SUPPORT__
        mmi_imgview_pause_drm_consume_if_need();
    #endif

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_entry_app
 * DESCRIPTION
 *  image viewer entry point
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_entry_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_filepath[FMGR_PATH_BUFFER_SIZE];
    FS_HANDLE file_handle;
    FMGR_FILTER filter;
    S32 create_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */

        if (mmi_usb_check_path_exported((PS8) MMI_IMGVIEW_STORAGE_FILEPATH_PHONE))
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    if (g_imgview_context.is_storage_ready == FALSE)
    {
        mmi_imgview_entry_set_storage_screen();
        return ;
    }


    EntryNewScreen(SCR_ID_IMGVIEW_APP, NULL, mmi_imgview_entry_app, NULL);

    SetDelScrnIDCallbackHandler(SCR_ID_IMGVIEW_APP, mmi_imgview_del_scr_callback);

    /* load imageviwer's storage setting */
    if (mmi_imgview_get_storage_file_path(buf_filepath)==TRUE)
        create_result = mmi_imgview_create_file_dir(buf_filepath);
    else
    {
    #if defined(MT6223P) 
        /* for MT6223P, we need to check if have more >0 drv to select by user. */
        U8 total_drv_num = 0;
        mmi_imgview_display_popup(
                (PU8) GetString(STR_ID_IMGVIEW_NOTIFY_NO_MEMORY_CARD),
                IMG_GLOBAL_WARNING,
                1,
                ST_NOTIFYDURATION,
                WARNING_TONE);

        mmi_fmgr_get_exist_storage_inline_list(NULL,&total_drv_num,NULL,NULL);

        if (total_drv_num == 0)
        {
            DeleteScreenIfPresent(SCR_ID_IMGVIEW_APP);
            return;
        }

        g_imgview_context.is_storage_ready = FALSE;
        return;
    #else
        mmi_imgview_display_popup(
                (PU8) GetString(STR_ID_IMGVIEW_NOTIFY_NO_MEMORY_CARD),
                IMG_GLOBAL_WARNING,
                1,
                ST_NOTIFYDURATION,
                WARNING_TONE);
        g_imgview_context.is_storage_ready = FALSE;
        return;
    #endif
    }

    /* reset imageviewr */
#ifdef __MMI_IMAGEVIEWER_ADV__
    mmi_imgadv_reset_app();
#endif 

    /* check if it is valid path */
    file_handle = FS_Open((PU16) buf_filepath, FS_OPEN_DIR | FS_READ_ONLY);

    if (file_handle >= 0)
    {
        FS_Close(file_handle);

        FMGR_FILTER_INIT(&filter);
        FMGR_FILTER_SET_IMAGE(&filter);

        #ifdef __DRM_SUPPORT__
        FMGR_FILTER_SET(&filter, FMGR_TYPE_ODF);
        #endif
        
        mmi_fmgr_select_path_and_enter(
            APP_IMAGEVIEWER,
            FMGR_SELECT_BROWSE|FMGR_SELECT_ARCHIVE_WITH_SINGLE_OBJECT,
            filter,
            buf_filepath,
            (PsExtFuncPtr) mmi_imgview_exit_from_fmgr);

        /* check if device is busy or not */
        if (FS_GetDevStatus(buf_filepath[0], FS_FEATURE_STATE_ENUM) == FS_DEVICE_BUSY)
        {
            /*  mmi_fmgr_select_path_and_enter will also add screen to histry */
            DeleteUptoScrID(SCR_ID_IMGVIEW_APP);

            /* Delete up to previous screen */
            DeleteNHistory(1);
        }

    }
    else
    {
        /* photo's path is not exist, and card is write protected, cant create photo folder */
        if (create_result == FS_WRITE_PROTECTION)
        {
            mmi_imgview_display_popup(
                (PU8) GetString(STR_ID_IMGVIEW_NOTIFY_WRITE_PROTECTION),
                IMG_GLOBAL_WARNING,
                1,
                ST_NOTIFYDURATION,
                WARNING_TONE);
        }
        else if (create_result == FS_DISK_FULL)
        {
            mmi_imgview_display_popup(
                (PU8) GetString(FMGR_FS_DISK_FULL_TEXT),
                IMG_GLOBAL_WARNING,
                1,
                ST_NOTIFYDURATION,
                WARNING_TONE);
        }
        else if (create_result == FS_ROOT_DIR_FULL)
        {
            mmi_imgview_display_popup(
                (PU8) GetString(FMGR_FS_ROOT_DIR_FULL_TEXT),
                IMG_GLOBAL_WARNING,
                1,
                ST_NOTIFYDURATION,
                WARNING_TONE);
        }
        else
        {
            mmi_imgview_display_popup(
                (PU8) GetString(STR_ID_IMGVIEW_NOTIFY_NO_MEMORY_CARD),
                IMG_GLOBAL_WARNING,
                1,
                ST_NOTIFYDURATION,
                WARNING_TONE);
        }
        g_imgview_context.is_storage_ready = FALSE;
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_display_popup
 * DESCRIPTION
 *  display popup.
 * PARAMETERS
 *  str_ptr                [OUT]       popup string
 *  img_id                 [OUT]       popup image
 *  image_on_bottom        [OUT]       image on buttom
 *  tone_duration          [OUT]       tone duration
 *  tone_id                [OUT]       tone id
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_imgview_display_popup(PU8 str_ptr, U16 img_id, U16 image_on_bottom, U16 tone_duration, U16 tone_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SCREEN_ROTATE__)
    DisplayPopupRotated(
        (PU8) str_ptr,
        (U16) img_id,
        (U8) image_on_bottom,
        (U32) tone_duration,
        (U8) tone_id,
        g_imgview_context.imgview_rotate);
#else 
    DisplayPopup((PU8) str_ptr, (U16) img_id, (U8) image_on_bottom, (U32) tone_duration, (U8) tone_id);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_get_storage_file_path
 * DESCRIPTION
 *  get current active storage file path.
 * PARAMETERS
 *  filepath        [OUT]       File path
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mmi_imgview_get_storage_file_path(PS8 filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 drv_buf[8];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_imgview_get_storage_disk_path(drv_buf))
    {
        mmi_ucs2cpy((PS8) filepath, (PS8) drv_buf);
        mmi_ucs2cat((PS8) filepath, (PS8) MMI_IMGVIEW_STORAGE_FILEPATH_PHONE);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_get_storage_disk_path
 * DESCRIPTION
 *  get current active storage disk path.
 * PARAMETERS
 *  drv_buf     [OUT]       Drive path buffer
 * RETURNS
 *  void
 *****************************************************************************/
static BOOL mmi_imgview_get_storage_disk_path(PS8 drv_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf[64];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (FS_NO_ERROR == FS_GetDevStatus(g_imgview_context.storage ,FS_MOUNT_STATE_ENUM))
    {
        sprintf(buf, "%c:\\", (U8)g_imgview_context.storage );
        mmi_asc_to_ucs2(drv_buf, buf);
        return TRUE;
    }
    else
    {
        return FALSE;
    }   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_create_file_dir
 * DESCRIPTION
 *  create directly from a file path (resursivly)
 * PARAMETERS
 *  filepath        [IN]        File path to create
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_imgview_create_file_dir(PS8 filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fs_ret;
    FS_HANDLE file_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fs_ret = 0;

    file_handle = FS_Open((kal_uint16*) filepath, FS_OPEN_DIR | FS_READ_ONLY);

    /* path already exist */
    if (file_handle >= 0)
    {
        FS_Close(file_handle);
        return 0;   /* already exist , 0 measn success in FS */
    }

#ifdef __MMI_MY_FAVORITE__
/* ADD FOR OP1: DUE TO THE CAMERA FOLDER IS UNDER IMAGES FOLDER*/
{
    S8 drv_buf[8];
    S8 buf_filepath[FMGR_PATH_BUFFER_SIZE];

    if (mmi_imgview_get_storage_disk_path(drv_buf))
    {
        mmi_ucs2cpy((PS8) buf_filepath, (PS8) drv_buf);
        mmi_ucs2cat((PS8) buf_filepath, (PS8) L"Images\\");
        fs_ret = FS_CreateDir((PU16)buf_filepath);
    }

    if (fs_ret < 0 && fs_ret != FS_FILE_EXISTS)
    return fs_ret;
}
#endif

    /* create directory if it is not there */
    fs_ret = FS_CreateDir((PU16) filepath);

    if (fs_ret < 0)
    {
        return fs_ret;
    }

    return fs_ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_restore_setting
 * DESCRIPTION
 *  restore setting
 * PARAMETERS
 *  void
 * RETURNS
 *  nil
 *****************************************************************************/
void mmi_imgview_restore_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgview_context.storage = (U16)MMI_PUBLIC_DRV;
    WriteValue(NVRAM_IMGVIEW_STORAGE, &g_imgview_context.storage, DS_SHORT, &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_load_setting
 * DESCRIPTION
 *  load setting
 * PARAMETERS
 *  void
 * RETURNS
 *  S32(?)
 *****************************************************************************/
void mmi_imgview_load_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* load format setting */
    ReadValue(NVRAM_IMGVIEW_STORAGE, &g_imgview_context.storage, DS_SHORT, &error);

    /* init if needed */
    if (g_imgview_context.storage == 0xffff)
    {
        g_imgview_context.storage = (U16)MMI_PUBLIC_DRV;
    }
}


#ifdef __DRM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_get_drm_result
 * DESCRIPTION
 *  get last time drm result
 * PARAMETERS
 *  void
 * RETURNS
 *  U16  MMI_IMGVIEW_OK/MMI_IMGVIEW_ERROR/MMI_IMGVIEW_ERRTYPE_DRM_INVALID
 *****************************************************************************/
S32 mmi_imgview_get_drm_result(void)
{
    return g_imgview_context.result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_start_consume
 * DESCRIPTION
 *  TO call DRM_consume_rights.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_start_consume(void)
{
    if (g_imgview_context.drm_handle != NULL)
    {
        g_imgview_context.drm_id = 
            DRM_consume_rights(g_imgview_context.drm_handle, DRM_PERMISSION_DISPLAY, mmi_imgview_drm_callback_hdlr);
        g_imgview_context.drm_state = IMGVIEW_DRM_STATE_CONSUME;

        DRM_close_file(g_imgview_context.drm_handle);
        g_imgview_context.drm_handle = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_pause_drm_consume_if_need
 * DESCRIPTION
 *  TO actually consume drm right
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgview_pause_drm_consume_if_need(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---[IMAGEVIEWER.c] consume if need, drm state = %d",g_imgview_context.drm_state);
    if ((g_imgview_context.drm_state == IMGVIEW_DRM_STATE_CONSUME) || (g_imgview_context.drm_state == IMGVIEW_DRM_STATE_PAUSE))
    {
        PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---[IMAGEVIEWER.c] consume if need, consume");
        DRM_stop_consume(g_imgview_context.drm_id);
        g_imgview_context.drm_id = 0;
        g_imgview_context.drm_state = IMGVIEW_DRM_STATE_EXIT;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_preprocess_drm_right
 * DESCRIPTION
 *  pre-process DRM right
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgview_preprocess_drm_right(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imgview_context.drm_state == IMGVIEW_DRM_STATE_EXIT)
    {
        g_imgview_context.drm_valid = mmi_imgview_process_drm_hdlr();

        /* ERROR HAPPENED */
        if ((g_imgview_context.drm_valid & IMGVIEW_DRM_DRM_FILE)==0)
        {
            g_imgview_context.result = MMI_IMGVIEW_OK;
        }
        else if (((IMGVIEW_DRM_MULTI_PART & g_imgview_context.drm_valid)!=0))
        {
            /* MULTI-PART */
            g_imgview_context.result = MMI_IMGVIEW_ERRTYPE_DRM_MULTIPART; 
        }
        else if ((IMGVIEW_DRM_DISPLAY_VALID & g_imgview_context.drm_valid)==0)
        {
            /* DISPLAY PERMISSIONT DENINED */
            g_imgview_context.result = MMI_IMGVIEW_ERRTYPE_DRM_INVALID; 
        }
        else 
            g_imgview_context.result = MMI_IMGVIEW_OK;
    }
    else if (g_imgview_context.drm_state == IMGVIEW_DRM_STATE_PAUSE)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---[IMAGEVIEWER.c] resume consume");

        /* check print right again */
        if (DRM_get_object_method(NULL,(PU16) g_imgview_context.filepath) != DRM_METHOD_NONE)
        {
            if (!DRM_validate_permission(NULL, (PU16)g_imgview_context.filepath, DRM_PERMISSION_PRINT))
            {
                g_imgview_context.drm_valid &= ~(IMGVIEW_DRM_PRINT_VALID);
            }
        }            

        /* if DRM State in PAUSE, Consume DRM Right */
        DRM_resume_consume(g_imgview_context.drm_id);
        g_imgview_context.result = MMI_IMGVIEW_OK;
        g_imgview_context.drm_state = IMGVIEW_DRM_STATE_CONSUME;

        DRM_close_file(g_imgview_context.drm_handle);
        g_imgview_context.drm_handle = NULL;
    }
    else
    {
        /* should not go into this section */
        ASSERT(0);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_drm_print_callback_hdlr
 * DESCRIPTION
 *  drm right timeout hdlr
 * PARAMETERS
 *  S32  result
 *  S32  id
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgview_drm_print_callback_hdlr(kal_int32 result, kal_int32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* dummy api */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_drm_callback_hdlr
 * DESCRIPTION
 *  drm right timeout hdlr
 * PARAMETERS
 *  S32  result
 *  S32  id
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgview_drm_callback_hdlr(kal_int32 result, kal_int32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 active_screen_id = GetActiveScreenId();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*****************************************************************
     * TIME OUT
     * ---------------------------------------------------------------
     * show popup and draw black bg on panel 
     *****************************************************************/
    PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---[IMAGEVIEWER.c] drm callback hdlr(imgview), drm state = %d",g_imgview_context.drm_state );
    if (active_screen_id  == SCR_ID_IMGVIEW_VIEW ||active_screen_id == SCR_ID_IMGVIEW_FROM_FMGR)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---[IMAGEVIEWER.c] drm callback hdlr(imgview), in viewer");

        if (g_imgview_context.drm_state == IMGVIEW_DRM_STATE_CONSUME || g_imgview_context.drm_state == IMGVIEW_DRM_STATE_PAUSE)
        {
            PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---[IMAGEVIEWER.c] drm callback hdlr(imgview),consume");
            DRM_stop_consume(g_imgview_context.drm_id);
            g_imgview_context.drm_id = 0;
            g_imgview_context.drm_state = IMGVIEW_DRM_STATE_EXIT;
        }
        
        g_imgview_context.result = MMI_IMGVIEW_ERRTYPE_DRM_INVALID; 
        g_imgview_context.err_str_ptr = STR_GLOBAL_DRM_PROHIBITED;
        mmi_imgview_display_popup(
                (PU8) GetString(STR_GLOBAL_DRM_PROHIBITED),
                    IMG_GLOBAL_WARNING,
                    1,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);
        DeleteScreenIfPresent(active_screen_id);
    }
    else if (IsScreenPresent(SCR_ID_IMGVIEW_VIEW) || IsScreenPresent(SCR_ID_IMGVIEW_FROM_FMGR))
    {
        PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---[IMAGEVIEWER.c] drm callback hdlr(imgview), in HISTORY");
        if (g_imgview_context.drm_state == IMGVIEW_DRM_STATE_CONSUME || g_imgview_context.drm_state == IMGVIEW_DRM_STATE_PAUSE)
        {
            PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---[IMAGEVIEWER.c] drm callback hdlr(imgview),consume");
            DRM_stop_consume(g_imgview_context.drm_id);
            g_imgview_context.drm_id = 0;
            g_imgview_context.drm_state = IMGVIEW_DRM_STATE_EXIT;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgview_process_drm_hdlr
 * DESCRIPTION
 *  This function check DRM right of the file.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static imgview_drm_ret_enum mmi_imgview_process_drm_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    imgview_drm_ret_enum         ret = IMGVIEW_DRM_NOT_DRM_FILE;
    FMGR_FILE_INFO_STRUCT       file_info;
    S32                         file_type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check multipart or single part first */
    file_type = mmi_fmgr_get_drm_file_type_by_path(g_imgview_context.filepath, &file_info.file_type);

    if (file_type == FMGR_TYPE_ODF)
    {
        ret = IMGVIEW_DRM_DRM_FILE;
        ret |= IMGVIEW_DRM_MULTI_PART;       
    }
    else
    {
        if (FMGR_FILTER_IS_SET_IMAGE(&file_info.file_type))
        {     
            if ((g_imgview_context.drm_handle = DRM_open_file((PU16) g_imgview_context.filepath, FS_READ_ONLY, DRM_PERMISSION_DISPLAY)) >= FS_NO_ERROR)
            {
 
                if (DRM_get_object_method(g_imgview_context.drm_handle, NULL) == DRM_METHOD_NONE)
                {
                    ret = IMGVIEW_DRM_NOT_DRM_FILE;
                    DRM_close_file(g_imgview_context.drm_handle);
                    g_imgview_context.drm_handle = NULL;
                    ret |= IMGVIEW_DRM_PRINT_VALID;
                    return ret;
                }

                ret = IMGVIEW_DRM_DRM_FILE;

                if (DRM_validate_permission(NULL, (kal_wchar *)g_imgview_context.filepath, DRM_PERMISSION_DISPLAY))
                {
                    ret |= IMGVIEW_DRM_DISPLAY_VALID;    
                    
                    if (DRM_validate_permission(NULL, (kal_wchar *)g_imgview_context.filepath, DRM_PERMISSION_PRINT))
                        ret |= IMGVIEW_DRM_PRINT_VALID;
                }
                else
                {
                   DRM_close_file(g_imgview_context.drm_handle);
                   g_imgview_context.drm_handle = NULL;
                }
            }
            else if (g_imgview_context.drm_handle  == DRM_RESULT_NO_PERMISSION)  /* file open error but not DRM related problem */
            {
                /* NOT DRM FILE */
                //ret = IMGADV_DRM_NOT_DRM_FILE;
                g_imgview_context.drm_handle = NULL;
            }
            else if (g_imgview_context.drm_handle  <= -1)  /* file open error but not DRM related problem */
            {
                /* NOT DRM FILE */
                ret = IMGVIEW_DRM_NOT_DRM_FILE;
                g_imgview_context.drm_handle = NULL;
            }
        }
        else
        {
            ret |= IMGVIEW_DRM_MIMETYPE_NON_IMAGE;
        }
    }
    return ret;    
}
#endif 


#ifdef __MMI_IMAGEVIEWER_ADV__
#if defined(__MMI_BPP_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_bpp_print
 * DESCRIPTION
 *  BPP print function, forward to BPP Engine 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgadv_bpp_print(void)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_imgview_context.is_printing == TRUE)
        ASSERT(0);

    switch(g_imgadv_cntx.image_type)
    {
        case GDI_IMAGE_TYPE_JPG :
        case GDI_IMAGE_TYPE_JPG_FILE :
        case GDI_IMAGE_TYPE_GIF :
        case GDI_IMAGE_TYPE_GIF_FILE :
        case GDI_IMAGE_TYPE_BMP :
        case GDI_IMAGE_TYPE_BMP_FILE :
        case GDI_IMAGE_TYPE_PNG :
        case GDI_IMAGE_TYPE_PNG_FILE:
        case GDI_IMAGE_TYPE_WBMP :
        case GDI_IMAGE_TYPE_WBMP_FILE:
        case GDI_IMAGE_TYPE_SVG :
        case GDI_IMAGE_TYPE_SVG_FILE:
            break;            
        default:
            mmi_imgview_display_popup(
                (PU8) GetString(STR_ID_IMGVIEW_PRINT_NOT_SUPPORT),
                    IMG_GLOBAL_WARNING,
                    1,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);
            return;
            break;
    }


    if (mmi_bt_bpp_app_is_printing() == MMI_BPP_PRINT_STATUS_BUSY)
    {
        mmi_bt_bpp_busy_popup();   
    }
    else
    {
        g_imgview_context.is_printing = TRUE;

        g_imgview_context.bpp_caption = gui_malloc(FMGR_PATH_BUFFER_SIZE);
        g_imgview_context.bpp_filepath = gui_malloc(FMGR_PATH_BUFFER_SIZE);
        g_imgview_context.image_type = g_imgadv_cntx.image_type;

        mmi_ucs2cpy((PS8) g_imgview_context.bpp_filepath , (PS8) g_imgadv_cntx.filepath);
        mmi_chset_convert(MMI_CHSET_UCS2, MMI_CHSET_UTF8,(char*)g_imgadv_cntx.buf_filename_no_ext, (char*)g_imgview_context.bpp_caption, FMGR_PATH_BUFFER_SIZE );

        g_imgview_context.file_size = g_imgadv_cntx.file_size;

        mmi_bt_bpp_app_print(MMI_BPP_APP_IMG, mmi_imgview_xhtml_table_constructor);
    }
    return;
}
#endif


#ifdef __DRM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_pause_drm_consume_if_need
 * DESCRIPTION
 *  consume DRM right if the it is in correct drm state 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_pause_drm_consume_if_need(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---[IMAGEVIEWER.c] consume if need (imgadv), drm state = %d",g_imgadv_cntx.drm_state);

    if ((g_imgadv_cntx.drm_state == IMGADV_DRM_STATE_CONSUME)||(g_imgadv_cntx.drm_state == IMGADV_DRM_STATE_PAUSE))
    {
        PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---[IMAGEVIEWER.c] consume if need (imgadv), consume");
        DRM_stop_consume(g_imgadv_cntx.drm_id);
        g_imgadv_cntx.drm_id = 0;
        g_imgadv_cntx.drm_state = IMGADV_DRM_STATE_EXIT;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_drm_callback_hdlr
 * DESCRIPTION
 *  DRM Timeout hdlr
 * PARAMETERS
 *  S32 result
 *  S32 id
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_drm_callback_hdlr(kal_int32 result, kal_int32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*****************************************************************
     * TIME OUT
     * ---------------------------------------------------------------
     * show popup and draw black bg on panel 
     *****************************************************************/
    PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---[IMAGEVIEWER.c] in drm_callback (imgadv), drm state = %d",g_imgadv_cntx.drm_state);
    if (GetActiveScreenId() == SCR_ID_IMGVIEW_VIEW)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---[IMAGEVIEWER.c] in drm_callback (imgadv), in imgadv viewer");
        if (g_imgadv_cntx.drm_state == IMGADV_DRM_STATE_CONSUME || g_imgadv_cntx.drm_state == IMGADV_DRM_STATE_PAUSE)
        {
            PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---[IMAGEVIEWER.c] in drm_callback (imgadv), consume");
            DRM_stop_consume(g_imgadv_cntx.drm_id);
            g_imgadv_cntx.drm_id = 0;
            g_imgadv_cntx.drm_state = IMGADV_DRM_STATE_EXIT;
        }
        
        g_imgadv_cntx.result = MMI_IMGADV_DRM_INVALID; 
        g_imgadv_cntx.err_str_ptr = GetString(STR_GLOBAL_DRM_PROHIBITED);
        mmi_imgadv_display_error();
    }
    else if (IsScreenPresent(SCR_ID_IMGVIEW_VIEW))
    {
        PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---[IMAGEVIEWER.c] in drm_callback (imgadv), in HISTORY");
        if (g_imgadv_cntx.drm_state == IMGADV_DRM_STATE_CONSUME || g_imgadv_cntx.drm_state == IMGADV_DRM_STATE_PAUSE)
        {
            PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---[IMAGEVIEWER.c] in drm_callback (imgadv), consume");
            DRM_stop_consume(g_imgadv_cntx.drm_id);
            g_imgadv_cntx.drm_id = 0;
            g_imgadv_cntx.drm_state = IMGADV_DRM_STATE_EXIT;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_process_drm_hdlr
 * DESCRIPTION
 *  This function check DRM right of the file.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static imgadv_drm_ret_enum mmi_imgadv_process_drm_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    imgadv_drm_ret_enum         ret = IMGADV_DRM_NOT_DRM_FILE;
    FMGR_FILE_INFO_STRUCT       file_info;
    S32                         file_type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check multipart or single part first */
    file_type = mmi_fmgr_get_drm_file_type_by_path(g_imgadv_cntx.filepath, &file_info.file_type);

    if (file_type == FMGR_TYPE_ODF)
    {
        ret = IMGADV_DRM_DRM_FILE;
        ret |= IMGADV_DRM_MULTI_PART;       
    }
    else
    {
        if (FMGR_FILTER_IS_SET_IMAGE(&file_info.file_type))
        {     
            if ((g_imgadv_cntx.drm_handle = DRM_open_file((PU16) g_imgadv_cntx.filepath, FS_READ_ONLY, DRM_PERMISSION_DISPLAY)) >= FS_NO_ERROR)
            {
 
                if (DRM_get_object_method(g_imgadv_cntx.drm_handle, NULL) == DRM_METHOD_NONE)
                {
                    ret = IMGADV_DRM_NOT_DRM_FILE;
                    DRM_close_file(g_imgadv_cntx.drm_handle);
                    g_imgadv_cntx.drm_handle = NULL;
                    return ret;
                }

                ret = IMGADV_DRM_DRM_FILE;

                if (DRM_validate_permission(NULL, (kal_wchar *)g_imgadv_cntx.filepath, DRM_PERMISSION_PRINT))
                    ret |= IMGADV_DRM_PRINT_VALID;

                if (DRM_validate_permission(NULL, (kal_wchar *)g_imgadv_cntx.filepath, DRM_PERMISSION_DISPLAY))
                {
                    ret |= IMGADV_DRM_DISPLAY_VALID;
                    g_imgadv_cntx.drm_state = IMGADV_DRM_STATE_DECODING;
                }
                else
                {
                   DRM_close_file(g_imgadv_cntx.drm_handle);
                   g_imgadv_cntx.drm_handle = NULL;
                }
            }
            else if (g_imgadv_cntx.drm_handle  == DRM_RESULT_NO_PERMISSION)  /* file open error but not DRM related problem */
            {
                /* NOT DRM FILE */
                //ret = IMGADV_DRM_NOT_DRM_FILE;
                g_imgadv_cntx.drm_handle = NULL;
            }
            else if (g_imgadv_cntx.drm_handle  <= -1)  /* file open error but not DRM related problem */
            {
                /* NOT DRM FILE */
                ret = IMGADV_DRM_NOT_DRM_FILE;
                g_imgadv_cntx.drm_handle = NULL;
            }
        }
        else
        {
            ret |= IMGADV_DRM_MIMETYPE_NON_IMAGE;
        }
    }
    return ret;    
}
#endif 


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_display_error
 * DESCRIPTION
 *  This function shows display popup.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_display_error(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgadv_cntx.is_err_displayed = TRUE;

    DisplayPopupRotated(
            (PU8)g_imgadv_cntx.err_str_ptr,
            IMG_GLOBAL_WARNING,
            1,
            ST_NOTIFYDURATION,
            WARNING_TONE,
            g_imgadv_cntx.imgview_rotate);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_get_active_osd_cntx
 * DESCRIPTION
 *  This function is called to set imgadv active osd cntx.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_get_active_osd_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GDI_LCD_LAYER_ROTATE_270 == g_imgadv_cntx.imgview_rotate)
        g_imgadv_cntx.active_osd_layout_ptr = &g_imgadv_osd_cntx_270;
    else if (GDI_LCD_LAYER_ROTATE_0 == g_imgadv_cntx.imgview_rotate)
        g_imgadv_cntx.active_osd_layout_ptr = &g_imgadv_osd_cntx;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_del_scr_callback
 * DESCRIPTION
 *  imgview delete screen callback handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_imgadv_del_scr_callback(void* ptr)
{
    #ifdef __DRM_SUPPORT__
        mmi_imgadv_pause_drm_consume_if_need();
    #endif

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_draw_osd
 * DESCRIPTION
 *  This function is called to draw osd.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_draw_osd(void)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #define DRAW_OSD_ICON(a,A)                                                                      \
    do {                                                                                            \
        gdi_draw_solid_rect(g_imgadv_cntx.active_osd_layout_ptr->##a##.offset_x,            \
                            g_imgadv_cntx.active_osd_layout_ptr->##a##.offset_y,            \
                            g_imgadv_cntx.active_osd_layout_ptr->##a##.offset_x+g_imgadv_cntx.active_osd_layout_ptr->##a##.width,               \
                            g_imgadv_cntx.active_osd_layout_ptr->##a##.offset_y+g_imgadv_cntx.active_osd_layout_ptr->##a##.height,              \
                            GDI_COLOR_TRANSPARENT);                                         \
        if (g_imgadv_cntx.active_osd_layout_ptr->##a##.is_show)                                     \
        {                                                                                           \
            if (g_imgadv_cntx.active_osd_layout_ptr->##a##.is_press == FALSE)                       \
            {                                                                                       \
                gdi_image_draw_id(g_imgadv_cntx.active_osd_layout_ptr->##a##.offset_x,              \
                                  g_imgadv_cntx.active_osd_layout_ptr->##a##.offset_y,              \
                                  (U16)(IMG_ID_IMAGEVIEWER_##A##_UP));                              \
            }                                                                                       \
            else                                                                                    \
            {                                                                                       \
                gdi_image_draw_id(g_imgadv_cntx.active_osd_layout_ptr->##a##.offset_x,              \
                                  g_imgadv_cntx.active_osd_layout_ptr->##a##.offset_y,              \
                                  (U16)(IMG_ID_IMAGEVIEWER_##A##_DOWN));                            \
            }                                                                                       \
        }                                                                                           \
    } while(0);
    gdi_layer_push_and_set_active(g_imgadv_cntx.base_layer_handle);
    DRAW_OSD_ICON(larrow,LEFT_ARROW);
    DRAW_OSD_ICON(rarrow,RIGHT_ARROW);
    DRAW_OSD_ICON(zoomin,ZOOMIN);
    DRAW_OSD_ICON(zoomout,ZOOMOUT);
    DRAW_OSD_ICON(rotate,ROTATE);

    mmi_imgadv_draw_softkey();

    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_exit_app_screen
 * DESCRIPTION
 *  imgadv exit screen handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgadv_exit_app_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_TVOUT__
    gdi_image_stop_animation(g_imgadv_cntx.animation_on_tv);
    if (mdi_tvout_is_enable())
    {
        /* restore back to GDI */
        mdi_tvout_set_owner(MDI_TV_OWNER_GDI);

        /* restore back to start mode1 */
        mdi_tvout_set_mode(
            MDI_TV_MODE_LCD_SCR,
            0,  /* layer_width */
            0); /* layer_height */

    }
#endif /* __MMI_TVOUT__ */ 
    
#ifdef __DRM_SUPPORT__
    /* based on DEL SCR will be called before exit screen hdlr */
    if (g_imgadv_cntx.drm_state == IMGADV_DRM_STATE_CONSUME)
    {
        DRM_pause_consume(g_imgadv_cntx.drm_id);
        g_imgadv_cntx.drm_state = IMGADV_DRM_STATE_PAUSE;
    }
    else if (g_imgadv_cntx.drm_state == IMGADV_DRM_STATE_DECODING)
    {
        DRM_close_file(g_imgadv_cntx.drm_handle);
        g_imgadv_cntx.drm_handle = NULL;
        g_imgadv_cntx.drm_state = IMGADV_DRM_STATE_EXIT;
    }
#endif

    gdi_anim_stop_all_by_layer(g_imgadv_cntx.cache_layer_handle);

    /* cancel timer */
    gui_cancel_timer(mmi_imgadv_start_decode);
    gui_cancel_timer(mmi_imgadv_extract_image_to_cache_layer);
    
    /* re-enable keypad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);

    if (g_imgadv_cntx.imgview_rotate == GDI_LCD_LAYER_ROTATE_270)
    {
        gdi_layer_resize(LCD_WIDTH,LCD_HEIGHT);
        gdi_lcd_set_rotate(GDI_LCD_LAYER_ROTATE_0);
    }

    /* clear bg to white color */
    gdi_layer_clear(GDI_COLOR_WHITE);


    if (g_imgadv_cntx.is_scrolling_title == TRUE)
        gui_scrolling_text_stop(&g_imgadv_cntx.scrolling_title);

    /* free buffer resource */
    mmi_imgadv_free_resource();

    /* free string resource */
    mmi_frm_scrmem_free((void*)g_imgadv_cntx.filepath);
    mmi_frm_scrmem_free((void*)g_imgadv_cntx.buf_filename_no_ext);
    mmi_frm_scrmem_free((void*)g_imgadv_cntx.count_str);
    g_imgadv_cntx.filepath = NULL;
    g_imgadv_cntx.count_str = NULL;


    /* reset imageviewer rotation, if left normally */
    if (g_imgadv_cntx.is_reset_application == TRUE)
    {
        mmi_imgadv_reset_app();
    }    

    /* restore only base layer active */
    gdi_layer_set_blt_layer(g_imgadv_cntx.base_layer_handle, 0, 0, 0);

    /* this will force title status to redraw */
    entry_full_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_reset_app
 * DESCRIPTION
 *  This function reset flags used by imgadv.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgadv_reset_app()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgadv_cntx.is_err_displayed = FALSE;
    g_imgadv_cntx.imgview_rotate = 0;
    g_imgadv_cntx.is_reset_application = FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_create_resource
 * DESCRIPTION
 *  This function is called to create resource used by imgadv.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_create_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_M3D ||
        g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_M3D_FILE )
    {
        g_imgadv_cntx.thumbnail_buf_ptr = NULL;
        g_imgadv_cntx.cache_buf_ptr = NULL;

        gdi_layer_create(
            0,
            0,
            LCD_WIDTH,
            LCD_HEIGHT,
            &g_imgadv_cntx.cache_layer_handle);

        gdi_layer_push_and_set_active(g_imgadv_cntx.cache_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        if (g_imgadv_cntx.imgview_rotate == GDI_LCD_LAYER_ROTATE_270)
        {
            gdi_layer_resize(LCD_HEIGHT,LCD_WIDTH);
        }
        gdi_layer_get_buffer_ptr(&g_imgadv_cntx.cache_buf_ptr);
        gdi_layer_pop_and_restore_active();
    }
    else
    {
        g_imgadv_cntx.thumbnail_buf_ptr = mmi_frm_scrmem_alloc(MMI_IMGADV_LAYER_SIZE);
        g_imgadv_cntx.cache_buf_ptr = mmi_frm_scrmem_alloc(MMI_IMGADV_LAYER_SIZE);

        /* create thumbnail layer resource */
        gdi_layer_create_using_outside_memory(
            0,
            0,
            LCD_WIDTH,
            LCD_HEIGHT,
            &g_imgadv_cntx.thumbnail_layer_handle,
            (PU8) g_imgadv_cntx.thumbnail_buf_ptr,
            (S32) MMI_IMGADV_LAYER_SIZE);

        gdi_layer_push_and_set_active(g_imgadv_cntx.thumbnail_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        if (g_imgadv_cntx.imgview_rotate == GDI_LCD_LAYER_ROTATE_270)
        {
            gdi_layer_resize(LCD_HEIGHT,LCD_WIDTH);
        }
        gdi_layer_pop_and_restore_active();

        /* create cache layer resource */
        gdi_layer_create_using_outside_memory(
            0,
            0,
            LCD_WIDTH,
            LCD_HEIGHT,
            &g_imgadv_cntx.cache_layer_handle,
            (PU8) g_imgadv_cntx.cache_buf_ptr,
            (S32) MMI_IMGADV_LAYER_SIZE);

        gdi_layer_push_and_set_active(g_imgadv_cntx.cache_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        if (g_imgadv_cntx.imgview_rotate == GDI_LCD_LAYER_ROTATE_270)
        {
            gdi_layer_resize(LCD_HEIGHT,LCD_WIDTH);
        }
        gdi_layer_pop_and_restore_active();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_free_resource
 * DESCRIPTION
 *  This function is called to free resource used by imgadv
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_free_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /**************************************************************
    * free thumbnail buffer ptr ! M3D did not use screen base memory
    **************************************************************/
    if (g_imgadv_cntx.thumbnail_buf_ptr != NULL && (g_imgadv_cntx.image_type != GDI_IMAGE_TYPE_M3D &&
                g_imgadv_cntx.image_type != GDI_IMAGE_TYPE_M3D_FILE ))
    {
        mmi_frm_scrmem_free((void*)g_imgadv_cntx.thumbnail_buf_ptr);
        g_imgadv_cntx.thumbnail_buf_ptr = NULL;
    }

    /**************************************************************
    * free thumbnail layer handle
    **************************************************************/
    if (g_imgadv_cntx.thumbnail_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(g_imgadv_cntx.thumbnail_layer_handle);
        g_imgadv_cntx.thumbnail_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    }

    /**************************************************************
    * free cache buffer ptr ! M3D did not use screen base memory
    **************************************************************/
    if (g_imgadv_cntx.cache_buf_ptr != NULL && (g_imgadv_cntx.image_type != GDI_IMAGE_TYPE_M3D &&
                g_imgadv_cntx.image_type != GDI_IMAGE_TYPE_M3D_FILE ))
    {
        mmi_frm_scrmem_free((void*)g_imgadv_cntx.cache_buf_ptr);
        g_imgadv_cntx.cache_buf_ptr = NULL;
    }

    /**************************************************************
    * free cache layer hendle
    **************************************************************/
    if (g_imgadv_cntx.cache_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(g_imgadv_cntx.cache_layer_handle);
        g_imgadv_cntx.cache_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_init_osd_icon_position
 * DESCRIPTION
 *  This function is called to initilize osd icon positions.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_init_osd_icon_position(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    imgadv_osd_layout_struct *active_imgadv_osd_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    #define INIT_OSD_TOUCH_ICON(__a__,__A__)                                    \
    do {                                                                        \
      if(active_imgadv_osd_ptr->##__a__##.is_show)                              \
      {                                                                         \
         gdi_image_get_dimension_id((U16)(IMG_ID_IMAGEVIEWER_##__A__##), \
                                    &(active_imgadv_osd_ptr->##__a__##.width),  \
                                    &(active_imgadv_osd_ptr->##__a__##.height)); \
         active_imgadv_osd_ptr->##__a__##.is_press = FALSE;                        \
      }                                                                         \
    } while(0);

    active_imgadv_osd_ptr = &g_imgadv_osd_cntx;

    active_imgadv_osd_ptr->larrow.is_show = TRUE;
    active_imgadv_osd_ptr->rarrow.is_show = TRUE;        


    INIT_OSD_TOUCH_ICON(larrow,LEFT_ARROW_UP );
    INIT_OSD_TOUCH_ICON(rarrow,RIGHT_ARROW_UP );
    INIT_OSD_TOUCH_ICON(zoomin,ZOOMIN_UP );
    INIT_OSD_TOUCH_ICON(zoomout,ZOOMOUT_UP );
    INIT_OSD_TOUCH_ICON(rotate,ROTATE_UP );
    
    active_imgadv_osd_ptr = &g_imgadv_osd_cntx_270;

    active_imgadv_osd_ptr->larrow.is_show = TRUE;
    active_imgadv_osd_ptr->rarrow.is_show = TRUE;        

    INIT_OSD_TOUCH_ICON(larrow,LEFT_ARROW_UP );
    INIT_OSD_TOUCH_ICON(rarrow,RIGHT_ARROW_UP );
    INIT_OSD_TOUCH_ICON(zoomin,ZOOMIN_UP );
    INIT_OSD_TOUCH_ICON(zoomout,ZOOMOUT_UP );
    INIT_OSD_TOUCH_ICON(rotate,ROTATE_UP );
    
    #ifdef INIT_OSD_TOUCH_ICON 
    #undef INIT_OSD_TOUCH_ICON
    #endif
}

#if defined(__DIRECTION_SENSOR_SUPPORT__)
void Process_image_viewer(msg_type msg_id) //for dirction_sensor
{
#if defined(NOKE_DEBUG)
	noke_dbg_printf("msg_id=%d\r\n", msg_id);
#endif
	if( GetActiveScreenId() == SCR_ID_IMGVIEW_VIEW)
 	{
           switch(msg_id)
           {
           case MSG_ID_MSENSOR_DIRECTION_0: //set group according to the data of ev_dbg_print
           case MSG_ID_MSENSOR_DIRECTION_90:            
#if defined(NOKE_DEBUG)
               noke_dbg_printf("111.imgview_rotate=%d\r\n", g_imgadv_cntx.imgview_rotate);
#endif
               if( (GDI_LCD_LAYER_ROTATE_0 != g_imgadv_cntx.imgview_rotate) )
               {  				 
                   g_imgadv_cntx.imgview_rotate = GDI_LCD_LAYER_ROTATE_270;		    		   
                   mmi_imgadv_rotate_release();	
               }
               break;

           case MSG_ID_MSENSOR_DIRECTION_180: 		   	           
           case MSG_ID_MSENSOR_DIRECTION_270:
#if defined(NOKE_DEBUG)
               noke_dbg_printf("g_imgadv_cntx.imgview_rotate=%d\r\n", g_imgadv_cntx.imgview_rotate);		
#endif
               if( (GDI_LCD_LAYER_ROTATE_270 != g_imgadv_cntx.imgview_rotate) )
               {			 
                   g_imgadv_cntx.imgview_rotate = GDI_LCD_LAYER_ROTATE_0;
                   mmi_imgadv_rotate_release();	
               }
               break;
			   
           default:
               break;
           }	
	}
}
#endif

#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_touch_scr_hit_test
 * DESCRIPTION
 *  This function check if icon is pressed on touch screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static BOOL mmi_imgadv_touch_scr_hit_test(S32 pos_x, S32 pos_y, imgadv_osd_icon_struct  *touch_obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((pos_x >= touch_obj->offset_x) &&
        (pos_x < touch_obj->offset_x + touch_obj->width) &&
        (pos_y >= touch_obj->offset_y) && (pos_y < touch_obj->offset_y + touch_obj->height))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_pen_down_hdlr
 * DESCRIPTION
 *  pen down event handler.
 * PARAMETERS
 *  pos IN position of the touched pixel
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imgadv_cntx.imgview_rotate == GDI_LCD_LAYER_ROTATE_270)
    {
        S32 tmp;

        tmp = pos.x;
        pos.x = pos.y;
        pos.y = (LCD_WIDTH - 1) - tmp;
    }


    /* LSK */
    if (mmi_imgadv_touch_scr_hit_test(pos.x, pos.y, &g_imgadv_cntx.lsk) == MMI_TRUE)
    {
        g_imgadv_cntx.touch_object = IMGADV_TOUCH_LSK;
        mmi_imgadv_lsk_press();
        return;
    }

    /* RSK */
    if (mmi_imgadv_touch_scr_hit_test(pos.x, pos.y, &g_imgadv_cntx.rsk) == MMI_TRUE)
    {
        g_imgadv_cntx.touch_object = IMGADV_TOUCH_RSK;
        mmi_imgadv_rsk_press();
        return;
    }

    /* osd test */
    #define IMGADV_OSD_ICON_TOUCH_TEST(a,A)\
    do {\
        if(g_imgadv_cntx.active_osd_layout_ptr->##a##.is_show)\
        {\
            if(mmi_imgadv_touch_scr_hit_test(pos.x, pos.y, &(g_imgadv_cntx.active_osd_layout_ptr->##a##)) == MMI_TRUE)\
            {\
                mmi_imgadv_##a##_press();\
                g_imgadv_cntx.touch_object = IMGADV_TOUCH_##A;\
                return;\
            }\
        }\
    } while(0)

    if(g_imgadv_cntx.active_osd_layout_ptr->larrow.is_show)
    {
        if(mmi_imgadv_touch_scr_hit_test(pos.x, pos.y, &(g_imgadv_cntx.active_osd_layout_ptr->larrow)) == MMI_TRUE)
        {
            mmi_imgadv_previous_image_press();
            g_imgadv_cntx.touch_object = IMGADV_TOUCH_LEFT_ARROW;
            return;
        }
    }

    if(g_imgadv_cntx.active_osd_layout_ptr->rarrow.is_show)
    {
        if(mmi_imgadv_touch_scr_hit_test(pos.x, pos.y, &(g_imgadv_cntx.active_osd_layout_ptr->rarrow)) == MMI_TRUE)
        {
            mmi_imgadv_next_image_press(); 
            g_imgadv_cntx.touch_object = IMGADV_TOUCH_RIGHT_ARROW;
            return;
        }
    }

    IMGADV_OSD_ICON_TOUCH_TEST(zoomin, ZOOMIN);
    IMGADV_OSD_ICON_TOUCH_TEST(zoomout, ZOOMOUT);
    IMGADV_OSD_ICON_TOUCH_TEST(rotate, ROTATE);
    g_imgadv_cntx.touch_object = IMGADV_TOUCH_NONE;


    /* if not touching icon , do translate image */
    if (g_imgadv_cntx.map.zoom_factor_cnt > 0)
    {
        gui_cancel_timer(mmi_imgadv_extract_image_to_cache_layer);
        g_imgadv_cntx.is_pen_down = TRUE;
        g_imgadv_cntx.pen_down_x = pos.x;
        g_imgadv_cntx.pen_down_y = pos.y;
    }

    #ifdef IMGADV_OSD_ICON_TOUCH_TEST
    #undef IMGADV_OSD_ICON_TOUCH_TEST
    #endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_pen_up_hdlr
 * DESCRIPTION
 *  pen up event handler
 * PARAMETERS
 *  pos IN position of the touched pixel
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imgadv_cntx.imgview_rotate == GDI_LCD_LAYER_ROTATE_270)
    {
        S32 tmp;

        tmp = pos.x;
        pos.x = pos.y;
        pos.y = (LCD_WIDTH - 1) - tmp;
    }

    if (g_imgadv_cntx.touch_object == IMGADV_TOUCH_NONE && 
        g_imgadv_cntx.map.zoom_factor_cnt > 0 &&
        g_imgadv_cntx.is_pen_down == TRUE)
    {
        S32 movement_x, movement_y;
        movement_x = (pos.x - g_imgadv_cntx.pen_down_x) / 5;
        movement_y = (pos.y - g_imgadv_cntx.pen_down_y) / 5;

        g_imgadv_cntx.map.wnd_offset_x += movement_x;
        g_imgadv_cntx.map.wnd_offset_y += movement_y;

        if (g_imgadv_cntx.map.wnd_offset_x < 0)
            g_imgadv_cntx.map.wnd_offset_x = 0;
        else if (g_imgadv_cntx.map.wnd_offset_x + g_imgadv_cntx.map.wnd_width > g_imgadv_cntx.map.width)
            g_imgadv_cntx.map.wnd_offset_x = g_imgadv_cntx.map.width - g_imgadv_cntx.map.wnd_width ;

        if (g_imgadv_cntx.map.wnd_offset_y < 0)
            g_imgadv_cntx.map.wnd_offset_y = 0;
        else if (g_imgadv_cntx.map.wnd_offset_y + g_imgadv_cntx.map.wnd_height > g_imgadv_cntx.map.height)
            g_imgadv_cntx.map.wnd_offset_y = g_imgadv_cntx.map.height - g_imgadv_cntx.map.wnd_height ;

        mmi_imgadv_draw_map();
        gui_start_timer(400, mmi_imgadv_extract_image_to_cache_layer);

        g_imgadv_cntx.is_pen_down = FALSE;
    }
    else
    {
        switch (g_imgadv_cntx.touch_object)
        {
            case IMGADV_TOUCH_LSK:
                mmi_imgadv_lsk_release();
                break;
            case IMGADV_TOUCH_RSK:
                mmi_imgadv_rsk_release();
                break;
            case IMGADV_TOUCH_LEFT_ARROW:
                mmi_imgadv_previous_image_release();            
                break;
            case IMGADV_TOUCH_RIGHT_ARROW:
                mmi_imgadv_next_image_release();            
                break;
            case IMGADV_TOUCH_ZOOMIN:
                mmi_imgadv_zoomin_release();
                break;
            case IMGADV_TOUCH_ZOOMOUT:
                mmi_imgadv_zoomout_release();
                break;
            case IMGADV_TOUCH_ROTATE:
                mmi_imgadv_rotate_release();
                break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_pen_move_hdlr
 * DESCRIPTION
 *  pen move event handler.
 * PARAMETERS
 *  pos IN current position of the moved pixel
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL softkey_pressed;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #define IMGADV_SWITCH_CASE(a,A)\
        case IMGADV_TOUCH_##A:\
            if (!mmi_imgadv_touch_scr_hit_test(pos.x, pos.y, &g_imgadv_cntx.active_osd_layout_ptr->##a##))\
            {\
                g_imgadv_cntx.active_osd_layout_ptr->##a##.is_press = FALSE;\
                mmi_imgadv_draw_osd();\
                gdi_lcd_repaint_all();\
                g_imgadv_cntx.touch_object = IMGADV_TOUCH_NONE;\
            }\
            break;\

    softkey_pressed = FALSE;
    if (g_imgadv_cntx.imgview_rotate == GDI_LCD_LAYER_ROTATE_270)
    {
        S32 tmp;

        tmp = pos.x;
        pos.x = pos.y;
        pos.y = (LCD_WIDTH - 1) - tmp;
    }

    if (g_imgadv_cntx.touch_object == IMGADV_TOUCH_NONE && 
        g_imgadv_cntx.map.zoom_factor_cnt > 0 &&
        g_imgadv_cntx.is_pen_down == TRUE)
    {
        S32 movement_x, movement_y;
        movement_x = (g_imgadv_cntx.pen_down_x - pos.x) / 5;
        movement_y = (g_imgadv_cntx.pen_down_y - pos.y) / 5;

        g_imgadv_cntx.map.wnd_offset_x += movement_x;
        g_imgadv_cntx.map.wnd_offset_y += movement_y;

        if (g_imgadv_cntx.map.wnd_offset_x < 0)
            g_imgadv_cntx.map.wnd_offset_x = 0;
        else if (g_imgadv_cntx.map.wnd_offset_x + g_imgadv_cntx.map.wnd_width > g_imgadv_cntx.map.width)
            g_imgadv_cntx.map.wnd_offset_x = g_imgadv_cntx.map.width - g_imgadv_cntx.map.wnd_width ;

        if (g_imgadv_cntx.map.wnd_offset_y < 0)
            g_imgadv_cntx.map.wnd_offset_y = 0;
        else if (g_imgadv_cntx.map.wnd_offset_y + g_imgadv_cntx.map.wnd_height > g_imgadv_cntx.map.height)
            g_imgadv_cntx.map.wnd_offset_y = g_imgadv_cntx.map.height - g_imgadv_cntx.map.wnd_height ;

        g_imgadv_cntx.pen_down_x = pos.x;
        g_imgadv_cntx.pen_down_y = pos.y;        

        if (g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_SVG ||
             g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_SVG_FILE )
            gdi_anim_stop_all_by_layer(g_imgadv_cntx.cache_layer_handle);

        {
            PU8 src2;
            PU8 dest;
            U16 output_clip_x1, output_clip_x2, output_clip_y1, output_clip_y2;
            U16 src_width2, src_height2;
            S32 src_offset_x, src_offset_y, src_pitch2;
            S32 dest_width, dest_height;

            #if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
                gdi_image_nb_stop_all();
            #endif


            gdi_layer_push_and_set_active(g_imgadv_cntx.thumbnail_layer_handle);
            gdi_layer_get_buffer_ptr(&src2);
            gdi_layer_get_dimension(&src_pitch2, &dest_height); /* dest_height is useless. */

            src_offset_x = g_imgadv_cntx.map.wnd_offset_x * g_imgadv_cntx.map.ratio_map_to_thumbnail;
            src_offset_y = g_imgadv_cntx.map.wnd_offset_y * g_imgadv_cntx.map.ratio_map_to_thumbnail;
            src_width2 = g_imgadv_cntx.map.wnd_width * g_imgadv_cntx.map.ratio_map_to_thumbnail;
            src_height2 = g_imgadv_cntx.map.wnd_height * g_imgadv_cntx.map.ratio_map_to_thumbnail;

            /************************************************
             *
             *  check if src_width/src_height > layer's
             *  prevent calculate clip error 
             *
             ************************************************/
            if (src_height2 > g_imgadv_cntx.thumbnail_layer_height)
                src_height2 = g_imgadv_cntx.thumbnail_layer_height;

            if (src_width2 > g_imgadv_cntx.thumbnail_layer_width)
                src_width2 = g_imgadv_cntx.thumbnail_layer_width;

            if ( src_offset_x + src_width2 > g_imgadv_cntx.thumbnail_layer_width)
                src_offset_x = g_imgadv_cntx.thumbnail_layer_width - src_width2;

            if ( src_offset_y + src_height2 > g_imgadv_cntx.thumbnail_layer_height)
                src_offset_y = g_imgadv_cntx.thumbnail_layer_height - src_height2;           

            src2 += ((src_offset_y * src_pitch2 * GDI_LAYER.bits_per_pixel) >> 3);
            src2 += ((src_offset_x * GDI_LAYER.bits_per_pixel) >> 3);

            gdi_layer_pop_and_restore_active();

            gdi_layer_push_and_set_active(g_imgadv_cntx.cache_layer_handle);
            gdi_layer_get_buffer_ptr(&dest);
            gdi_layer_get_dimension(&dest_width, &dest_height);
            gdi_layer_pop_and_restore_active();

            output_clip_x1 = 0;
            output_clip_y1 = 0;
            output_clip_x2 = dest_width - 1;
            output_clip_y2 = dest_height - 1;
            
        #ifdef GDI_USING_HW_RESIZER
            gdi_resizer(
                src2,
                src_width2,
                src_height2,
                src_pitch2,
                dest,
                dest_width,
                dest_height,
                output_clip_x1,
                output_clip_y1,
                output_clip_x2,
                output_clip_y2);
        #endif /* GDI_USING_HW_RESIZER */ 
        }    
        mmi_imgadv_draw_map();
        gdi_lcd_repaint_all();    
    }
    else
    {
        switch (g_imgadv_cntx.touch_object)
        {
            case IMGADV_TOUCH_LSK:
                if (mmi_imgadv_touch_scr_hit_test(pos.x, pos.y, &g_imgadv_cntx.lsk))
                {
                    softkey_pressed = TRUE;
                    g_imgadv_cntx.touch_object=IMGADV_TOUCH_LSK;
                }
                else
                {
                    softkey_pressed = FALSE;
                    g_imgadv_cntx.touch_object=IMGADV_TOUCH_NONE;
                }

                if (softkey_pressed != g_imgadv_cntx.lsk.is_press )
                {
                    g_imgadv_cntx.lsk.is_press = softkey_pressed;
                    mmi_imgadv_draw_osd();
                    gdi_lcd_repaint_all();
                }
                break;

            case IMGADV_TOUCH_RSK:
                if (mmi_imgadv_touch_scr_hit_test(pos.x, pos.y, &g_imgadv_cntx.rsk))
                {
                    softkey_pressed = TRUE;
                    g_imgadv_cntx.touch_object=IMGADV_TOUCH_RSK;                    
                }
                else
                {
                    softkey_pressed = FALSE;
                    g_imgadv_cntx.touch_object=IMGADV_TOUCH_NONE;
                }

                if (softkey_pressed != g_imgadv_cntx.rsk.is_press )
                {
                    g_imgadv_cntx.rsk.is_press = softkey_pressed;
                    mmi_imgadv_draw_osd();
                    gdi_lcd_repaint_all();
                }
                break;
            IMGADV_SWITCH_CASE(zoomin,ZOOMIN);
            IMGADV_SWITCH_CASE(zoomout,ZOOMOUT);
            IMGADV_SWITCH_CASE(rotate,ROTATE);
            IMGADV_SWITCH_CASE(rarrow,RIGHT_ARROW);
            IMGADV_SWITCH_CASE(larrow,LEFT_ARROW);
        }
    }
}
#endif /* __MMI_TOUCH_SCREEN__ */ 

#ifdef __MMI_TVOUT__
/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_anim_callback
 * DESCRIPTION
 *  animation callback function for gdi animate.
 * PARAMETERS
 *  gdi_result IN return code
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_anim_callback(GDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_HANDLE tvout_layer;
    PU8 p_src,p_dest;
    gdi_rect_struct clip;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (result < GDI_SUCCEED)
    {
        return;
    }

    if (mdi_tvout_is_enable())
    {
        /* buffer should only need to be get once. */
        p_src = g_imgadv_cntx.cache_buf_ptr;
       
        tvout_layer = mdi_tvout_get_active_layer();
        gdi_lcd_set_active(GDI_LCD_TVOUT_HANDLE);
        gdi_layer_push_and_set_active(tvout_layer);
        gdi_layer_get_buffer_ptr(&p_dest);

        if (g_imgadv_cntx.map.zoom_factor_cnt == 0)
        {
            clip.x1 = clip.y1 = 0;
            clip.x2 = g_imgadv_cntx.resized_img_width-1;
            clip.y2 = g_imgadv_cntx.resized_img_height-1;
            gdi_2d_memory_blt(
                p_src,
                g_imgadv_cntx.cache_layer_width,
                (g_imgadv_cntx.cache_layer_width - g_imgadv_cntx.resized_img_width) >>1,
                (g_imgadv_cntx.cache_layer_height - g_imgadv_cntx.resized_img_height) >>1,
                g_imgadv_cntx.resized_img_width,
                g_imgadv_cntx.resized_img_height,
                p_dest,
                g_imgadv_cntx.tvout_width ,
                0,                       /* the offset on the dest buffer */
                0,
                clip,
                GDI_MAINLCD_BIT_PER_PIXEL);
        }
        else if (g_imgadv_cntx.map.zoom_factor_cnt > 0) 
        {
            clip.x1 = clip.y1 = 0;
            clip.x2 = g_imgadv_cntx.cache_layer_width-1;
            clip.y2 = g_imgadv_cntx.cache_layer_height-1;
            gdi_2d_memory_blt(
                p_src,
                g_imgadv_cntx.cache_layer_width,
                0,
                0,
                g_imgadv_cntx.cache_layer_width,
                g_imgadv_cntx.cache_layer_height,
                p_dest,
                g_imgadv_cntx.tvout_width,
                0,                       /* the offset on the dest buffer */
                0,
                clip,
                GDI_MAINLCD_BIT_PER_PIXEL);            
        }
        gdi_layer_pop_and_restore_active();        
        gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);        
        mdi_tvout_blt();        
    }
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_extract_image_to_cache_layer
 * DESCRIPTION
 *  This function extract image to cache layer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_extract_image_to_cache_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
    GDI_RESULT gdi_handle = GDI_SUCCEED;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    gdi_layer_push_and_set_active(g_imgadv_cntx.cache_layer_handle);

    /* clear gdi working buffer */
    gdi_image_clear_work_buffer();

    PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---[IMAGEVIEWER.c] extract_image_to_cache()");

#if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
    gdi_nb_set_done_callback(mmi_imgadv_decode_done_callback);
    gdi_nb_set_blt(MMI_FALSE,MMI_FALSE);
#endif

    if (g_imgadv_cntx.map.zoom_factor_cnt == 0)
    {
        S32 offset_x = 0;
        S32 offset_y = 0;

        if (g_imgadv_cntx.cache_layer_width> g_imgadv_cntx.resized_img_width)
        {
            offset_x = (g_imgadv_cntx.cache_layer_width - g_imgadv_cntx.resized_img_width) >> 1;
        }

        if (g_imgadv_cntx.cache_layer_height > g_imgadv_cntx.resized_img_height)
        {
            offset_y = (g_imgadv_cntx.cache_layer_height - g_imgadv_cntx.resized_img_height) >> 1;
        }

        switch (g_imgadv_cntx.image_type)
        {
            case GDI_IMAGE_TYPE_GIF:
            case GDI_IMAGE_TYPE_GIF_FILE:
            case GDI_IMAGE_TYPE_SVG:
            case GDI_IMAGE_TYPE_SVG_FILE:
            case GDI_IMAGE_TYPE_M3D:
            case GDI_IMAGE_TYPE_M3D_FILE:

                if (g_imgadv_cntx.image_type!=GDI_IMAGE_TYPE_SVG && g_imgadv_cntx.image_type!=GDI_IMAGE_TYPE_SVG_FILE)
                    g_imgadv_cntx.map.is_zoomin_able = FALSE;

                #ifdef __MMI_TVOUT__
                if (mdi_tvout_is_enable())
                {
                    if ( g_imgadv_cntx.is_initialized == FALSE )
                    {
                        S32 tvout_width = (g_imgadv_cntx.resized_img_width > 1) ? g_imgadv_cntx.resized_img_width : 2;
                        S32 tvout_height = (g_imgadv_cntx.resized_img_height > 1) ? g_imgadv_cntx.resized_img_height : 2;
                        #ifdef MDI_TVOUT_MT6228_SERIES
                            if (tvout_width%8 != 0)
                            {
                                tvout_width += (8-(tvout_width%8));
                            }
                            g_imgadv_cntx.tvout_width = tvout_width;
                        #endif
                        mdi_tvout_set_mode(MDI_TV_MODE_OWNER_DRAW,tvout_width,tvout_height);
                        gdi_anim_set_blt_after_callback(mmi_imgadv_anim_callback);
                    }  
                }
                #endif
                gdi_layer_clear(GDI_COLOR_BLACK);

                #if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
                    g_imgadv_cntx.nb_handle = gdi_anim_nb_draw_resized_file(
                                                offset_x,
                                                offset_y,
                                                g_imgadv_cntx.resized_img_width,
                                                g_imgadv_cntx.resized_img_height,
                                                g_imgadv_cntx.filepath);                    
                #else
                    gdi_handle = gdi_anim_draw_file_resized(
                                    offset_x,
                                    offset_y,
                                    g_imgadv_cntx.resized_img_width,
                                    g_imgadv_cntx.resized_img_height,
                                    g_imgadv_cntx.filepath,
                                    NULL);
                #endif
            break;
            default:
                gdi_layer_clear(GDI_COLOR_BLACK);
                #if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
                    g_imgadv_cntx.nb_handle = gdi_image_nb_draw_resized_file(
                                                offset_x,
                                                offset_y,
                                                g_imgadv_cntx.resized_img_width,
                                                g_imgadv_cntx.resized_img_height,
                                                g_imgadv_cntx.filepath);                    
                #else
                    gdi_handle = gdi_image_draw_resized_file(
                                    offset_x,
                                    offset_y,
                                    g_imgadv_cntx.resized_img_width,
                                    g_imgadv_cntx.resized_img_height,
                                    g_imgadv_cntx.filepath);
                #endif
            break;                                
        }
    }
    else
    {
        S32 offset_x = g_imgadv_cntx.map.wnd_offset_x * g_imgadv_cntx.map.ratio_map_to_resized_image;
        S32 offset_y = g_imgadv_cntx.map.wnd_offset_y * g_imgadv_cntx.map.ratio_map_to_resized_image;
        S32 wnd_width = g_imgadv_cntx.map.wnd_width * g_imgadv_cntx.map.ratio_map_to_resized_image;
        S32 wnd_height = g_imgadv_cntx.map.wnd_height * g_imgadv_cntx.map.ratio_map_to_resized_image; 

        if ( offset_x + wnd_width > g_imgadv_cntx.resized_img_width )
            offset_x = g_imgadv_cntx.resized_img_width - wnd_width;

        if ( offset_y + wnd_height > g_imgadv_cntx.resized_img_height )
            offset_y = g_imgadv_cntx.resized_img_height - wnd_height;

        if (GDI_LCD_LAYER_ROTATE_0 == g_imgadv_cntx.imgview_rotate)
        {
            offset_x += (wnd_width-LCD_WIDTH);
            offset_y += (wnd_height-LCD_HEIGHT);
            wnd_width = LCD_WIDTH;
            wnd_height = LCD_HEIGHT;
        }
        else if (GDI_LCD_LAYER_ROTATE_270 == g_imgadv_cntx.imgview_rotate)
        {
            offset_x += (wnd_width-LCD_HEIGHT);
            offset_y += (wnd_height-LCD_WIDTH);
            wnd_width = LCD_HEIGHT;
            wnd_height = LCD_WIDTH;
        }

        /* check for some special case */
        if (g_imgadv_cntx.map.wnd_offset_y + g_imgadv_cntx.map.wnd_height == g_imgadv_cntx.map.height)
            offset_y = g_imgadv_cntx.resized_img_height - wnd_height;
        if (g_imgadv_cntx.map.wnd_offset_x + g_imgadv_cntx.map.wnd_width == g_imgadv_cntx.map.width)
            offset_x = g_imgadv_cntx.resized_img_width - wnd_width;           


        /******************************************************
         * check to prevent offset_x, offset_y to be invalid
         ******************************************************/
        if (offset_y < 0)
            offset_y = 0;

        if (offset_x < 0)
            offset_x = 0;

        switch (g_imgadv_cntx.image_type)
        {
            case GDI_IMAGE_TYPE_SVG:
            case GDI_IMAGE_TYPE_SVG_FILE:
                gdi_anim_stop_all_by_layer(g_imgadv_cntx.cache_layer_handle);
                #ifdef __MMI_TVOUT__
                if (mdi_tvout_is_enable())
                {
                    S32 tvout_width = (g_imgadv_cntx.cache_layer_width> 1) ? g_imgadv_cntx.cache_layer_width: 2;
                    S32 tvout_height = (g_imgadv_cntx.cache_layer_height> 1) ? g_imgadv_cntx.cache_layer_height: 2;

                    #ifdef MDI_TVOUT_MT6228_SERIES
                        if (tvout_width%8 != 0)
                        {
                            tvout_width += (8-(tvout_width%8));
                        }
                        g_imgadv_cntx.tvout_width = tvout_width;
                    #endif

                    mdi_tvout_set_mode(
                    MDI_TV_MODE_OWNER_DRAW,
                    tvout_width,    /* layer_width */
                    tvout_height);  /* layer_height */
                }
                #endif

                gdi_layer_clear(GDI_COLOR_BLACK);

                #if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
                    g_imgadv_cntx.nb_handle = gdi_anim_nb_draw_resized_file(
                                                -offset_x,
                                                -offset_y,
                                                g_imgadv_cntx.resized_img_width,
                                                g_imgadv_cntx.resized_img_height,
                                                g_imgadv_cntx.filepath);                    
                #else
                    gdi_handle = gdi_anim_draw_file_resized(
                                            -offset_x,
                                            -offset_y,
                                            g_imgadv_cntx.resized_img_width,
                                            g_imgadv_cntx.resized_img_height,
                                            g_imgadv_cntx.filepath,
                                            NULL);
                #endif
                break;
            case GDI_IMAGE_TYPE_JPG:
            case GDI_IMAGE_TYPE_JPG_FILE:
            default:
                gdi_layer_clear(GDI_COLOR_BLACK);					 	

                #if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
                    g_imgadv_cntx.nb_handle = gdi_image_nb_draw_resized_file(
                                                -offset_x,
                                                -offset_y,
                                                g_imgadv_cntx.resized_img_width,
                                                g_imgadv_cntx.resized_img_height,
                                                g_imgadv_cntx.filepath);                    
                #else
                    gdi_handle = gdi_image_draw_resized_file(
                                    -offset_x,
                                    -offset_y,
                                    g_imgadv_cntx.resized_img_width,
                                    g_imgadv_cntx.resized_img_height,
                                    g_imgadv_cntx.filepath);
                #endif
                break;
        }

    }

    gdi_layer_pop_and_restore_active();
    g_imgadv_cntx.result = MMI_IMGADV_OK;


#if !defined(__MMI_IMGADV_NONBLOCKING_DECODE__)

    #ifdef __DRM_SUPPORT__
    if (gdi_handle == GDI_SUCCEED && g_imgadv_cntx.is_resume != TRUE && g_imgadv_cntx.drm_handle != NULL)
    {
        g_imgadv_cntx.drm_id = 
            DRM_consume_rights(g_imgadv_cntx.drm_handle, DRM_PERMISSION_DISPLAY, mmi_imgadv_drm_callback_hdlr);
        g_imgadv_cntx.drm_state = IMGADV_DRM_STATE_CONSUME;

        DRM_close_file(g_imgadv_cntx.drm_handle);
        g_imgadv_cntx.drm_handle = NULL;
    }
    #endif

    if (gdi_handle != GDI_SUCCEED && (( g_imgadv_cntx.is_err_displayed == TRUE) && g_imgadv_cntx.result != MMI_IMGADV_NON_FIRST_TIME_DECODE_ERR))
    {
        g_imgadv_cntx.result = MMI_IMGADV_ERROR;
        gdi_layer_push_and_set_active(g_imgadv_cntx.cache_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
        return;
    }
    else if (gdi_handle != GDI_SUCCEED)
    {
        gdi_layer_push_and_set_active(g_imgadv_cntx.cache_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
        gdi_lcd_repaint_all();

        if (g_imgadv_cntx.map.zoom_factor_cnt == 0)
        {
            if (gdi_handle == GDI_JPEG_ERR_IMAGE_TOO_LARGE)
            {
                g_imgadv_cntx.err_str_ptr = GetString(STR_ID_FMGR_FILE_LIMIT_IMAGE_TOO_LARGE);
            }
            else if (gdi_handle == GDI_JPEG_ERR_FILE_FORMAT_WRONG)
            {
                g_imgadv_cntx.err_str_ptr = GetString(STR_ID_FMGR_INVALID_IMAGE_FORMAT);
            }
            else if (gdi_handle == GDI_JPEG_ERR_DECODE_TIME_OUT)
            {
                g_imgadv_cntx.err_str_ptr = GetString(STR_ID_FMGR_SYSTEM_BUSY_TO_DECODE);
            }
            else
            {
                g_imgadv_cntx.err_str_ptr = GetString(STR_ID_FMGR_INVALID_IMAGE_FORMAT);
            }
        }
        else
        {
            if (gdi_handle == GDI_JPEG_ERR_IMAGE_TOO_LARGE)
            {
                g_imgadv_cntx.err_str_ptr = GetString(STR_ID_FMGR_FILE_LIMIT_IMAGE_TOO_LARGE);
            }
            else if (gdi_handle == GDI_JPEG_ERR_FILE_FORMAT_WRONG)
            {
                g_imgadv_cntx.err_str_ptr = GetString(STR_ID_FMGR_INVALID_IMAGE_FORMAT);
            }
            else
                g_imgadv_cntx.err_str_ptr = GetString(STR_ID_FMGR_SYSTEM_BUSY_TO_DECODE);
        }


        if (g_imgadv_cntx.map.zoom_factor_cnt+1 <= 1)
        {
            g_imgadv_cntx.map.zoom_factor_cnt = 0;
            g_imgadv_cntx.result = MMI_IMGADV_FIRST_TIME_DECODE_ERR;        
        }
        else
        {
            g_imgadv_cntx.result = MMI_IMGADV_NON_FIRST_TIME_DECODE_ERR;  
            g_imgadv_cntx.map.zoom_factor_cnt--;
            g_imgadv_cntx.map.max_zoom_factor = g_imgadv_cntx.map.zoom_factor_cnt;
        }
        mmi_imgadv_display_error();
        return;
    }
    else
    {
        gdi_lcd_repaint_all();
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_extract_image_to_thumbnail_layer
 * DESCRIPTION
 *  This function extract image to thumbnail layer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_extract_image_to_thumbnail_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_M3D ||
        g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_M3D_FILE ||
        g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_GIF ||
        g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_GIF_FILE)
        return;
    PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---[IMAGEVIEWER.c] extract_image_to_thumbnail()");
    if (g_imgadv_cntx.is_resume == TRUE)
    {
        gdi_layer_push_and_set_active(g_imgadv_cntx.thumbnail_layer_handle);
        gdi_layer_resize(g_imgadv_cntx.thumbnail_layer_width ,g_imgadv_cntx.thumbnail_layer_height);
        gdi_image_draw_resized_file(
            0,
            0,
            g_imgadv_cntx.thumbnail_layer_width,
            g_imgadv_cntx.thumbnail_layer_height,
            g_imgadv_cntx.filepath);
        gdi_layer_pop_and_restore_active();

    }
    else if (g_imgadv_cntx.is_resume == FALSE && 
             g_imgadv_cntx.map.zoom_factor_cnt == 0 )
    {
        PU8 src;
        PU8 dest;
        U16 src_width, src_height, src_pitch;
        S32 src_offset_x=0, src_offset_y=0;
        S32 dest_pitch, dest_offset_x, dest_offset_y;
        gdi_rect_struct dest_clip;

        if (g_imgadv_cntx.cache_layer_width> g_imgadv_cntx.resized_img_width)
        {
            src_offset_x = (g_imgadv_cntx.cache_layer_width - g_imgadv_cntx.resized_img_width) >> 1;
        }

        if (g_imgadv_cntx.cache_layer_height > g_imgadv_cntx.resized_img_height)
        {
            src_offset_y = (g_imgadv_cntx.cache_layer_height - g_imgadv_cntx.resized_img_height) >> 1;
        }

        g_imgadv_cntx.thumbnail_layer_width = g_imgadv_cntx.resized_img_width;
        g_imgadv_cntx.thumbnail_layer_height = g_imgadv_cntx.resized_img_height;

        gdi_layer_push_and_set_active(g_imgadv_cntx.thumbnail_layer_handle);
        gdi_layer_resize(g_imgadv_cntx.thumbnail_layer_width ,g_imgadv_cntx.thumbnail_layer_height);
        gdi_layer_pop_and_restore_active();

        dest = g_imgadv_cntx.thumbnail_buf_ptr;
        src = g_imgadv_cntx.cache_buf_ptr;
        src_pitch = g_imgadv_cntx.cache_layer_width;
        dest_pitch = g_imgadv_cntx.thumbnail_layer_width;
        dest_clip.x1 = 0;
        dest_clip.y1 = 0;
        dest_clip.x2 = g_imgadv_cntx.thumbnail_layer_width- 1;
        dest_clip.y2 = g_imgadv_cntx.thumbnail_layer_height - 1;
        src_width = g_imgadv_cntx.resized_img_width;
        src_height = g_imgadv_cntx.resized_img_height;
        dest_offset_x = 0;
        dest_offset_y = 0;

        /* use 2D copy from cache layer to thumbnail layer */
        gdi_2d_memory_blt_without_transpant_check(
            src,
            src_pitch,
            src_offset_x,
            src_offset_y,
            src_width,
            src_height,
            dest,
            dest_pitch,
            dest_offset_x,
            dest_offset_y,
            dest_clip,
            GDI_MAINLCD_BIT_PER_PIXEL);

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_init_image_info
 * DESCRIPTION
 *  This function init image info.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_init_image_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---[IMAGEVIEWER.c] extract_init_image_info()");
    /* set cache layer's width/height */
    if (GDI_LCD_LAYER_ROTATE_0 == g_imgadv_cntx.imgview_rotate)
    {
        g_imgadv_cntx.cache_layer_height = LCD_HEIGHT;
        g_imgadv_cntx.cache_layer_width = LCD_WIDTH;
        g_imgadv_cntx.map.ratio_width_to_height = (float)LCD_WIDTH/LCD_HEIGHT;
    }
    else if (GDI_LCD_LAYER_ROTATE_270 == g_imgadv_cntx.imgview_rotate)
    {
        g_imgadv_cntx.cache_layer_height = LCD_WIDTH;
        g_imgadv_cntx.cache_layer_width = LCD_HEIGHT;
        g_imgadv_cntx.map.ratio_width_to_height = (float)LCD_HEIGHT/LCD_WIDTH;
    }

    /* initialize the map */
    mmi_imgadv_init_map_box();

    /* initialize resized_img_width/resized_img_height */
    if ((g_imgadv_cntx.image_width < g_imgadv_cntx.cache_layer_width)
        && (g_imgadv_cntx.image_height < g_imgadv_cntx.cache_layer_height))
    {
        g_imgadv_cntx.resized_img_width = g_imgadv_cntx.image_width;
        g_imgadv_cntx.resized_img_height = g_imgadv_cntx.image_height;
        g_imgadv_cntx.map.is_zoomin_able = FALSE;
    }
    else
    {
        float tmp_width = (float)g_imgadv_cntx.image_width / g_imgadv_cntx.cache_layer_width;
        float tmp_height = (float)g_imgadv_cntx.image_height / g_imgadv_cntx.cache_layer_height;

        if (tmp_width == tmp_height)
        {
            g_imgadv_cntx.is_width_dominate = TRUE;
            g_imgadv_cntx.resized_img_width = g_imgadv_cntx.cache_layer_width;
            g_imgadv_cntx.resized_img_height = g_imgadv_cntx.cache_layer_height;
            g_imgadv_cntx.map.ratio_map_to_resized_image = 
            g_imgadv_cntx.map.ratio_map_to_thumbnail = 
                (float)g_imgadv_cntx.resized_img_height/ g_imgadv_cntx.map.height;            
        }
        else if (tmp_width > tmp_height)
        {
            g_imgadv_cntx.is_width_dominate = FALSE;
            g_imgadv_cntx.resized_img_height = g_imgadv_cntx.image_height / tmp_width + 0.5;
            g_imgadv_cntx.resized_img_width = g_imgadv_cntx.cache_layer_width;
            g_imgadv_cntx.map.ratio_map_to_resized_image = 
            g_imgadv_cntx.map.ratio_map_to_thumbnail = 
            (float)g_imgadv_cntx.resized_img_width/g_imgadv_cntx.map.width;            
        }
        else
        {
            g_imgadv_cntx.is_width_dominate = TRUE;
            g_imgadv_cntx.resized_img_width = g_imgadv_cntx.image_width / tmp_height + 0.5;
            g_imgadv_cntx.resized_img_height = g_imgadv_cntx.cache_layer_height;
            g_imgadv_cntx.map.ratio_map_to_resized_image = 
            g_imgadv_cntx.map.ratio_map_to_thumbnail = 
                (float)g_imgadv_cntx.resized_img_height/g_imgadv_cntx.map.height;
        }
    }

    /* check if resized_img_width/resized_img_height <= 0 */
    if (g_imgadv_cntx.resized_img_width <= 0)
    {
        g_imgadv_cntx.resized_img_width = 1;
    }

    if (g_imgadv_cntx.resized_img_height <= 0)
    {
        g_imgadv_cntx.resized_img_height = 1;
    }

    /* check if zoomable */
    if ((g_imgadv_cntx.image_height < g_imgadv_cntx.cache_layer_height || g_imgadv_cntx.image_width < g_imgadv_cntx.cache_layer_width)
        ||(g_imgadv_cntx.map.ratio_map_to_image <= 0 || g_imgadv_cntx.map.width <= 0 || g_imgadv_cntx.map.height <= 0))
        g_imgadv_cntx.map.is_zoomin_able = FALSE;        
    else if ((g_imgadv_cntx.resized_img_width * g_imgadv_cntx.map.zoom_factor <= g_imgadv_cntx.image_width)
        &&(g_imgadv_cntx.resized_img_height * g_imgadv_cntx.map.zoom_factor <= g_imgadv_cntx.image_height))
        g_imgadv_cntx.map.is_zoomin_able = TRUE;
    else
        g_imgadv_cntx.map.is_zoomin_able = FALSE;
}


#ifdef __MMI_TVOUT__
/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_tvout_clear_bg
 * DESCRIPTION
 *  This function clear tvout buffer bg..
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_tvout_clear_bg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 tvout_buf_width;
    S32 tvout_buf_height;
    GDI_HANDLE tvout_layer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_tvout_is_enable())
    {
        if (g_imgadv_cntx.result >= 0)
        {
            /* get best fit size for PAL/NTSC */
            mdi_tvout_get_owner_draw_best_size(&tvout_buf_width, &tvout_buf_height);

            /* set mode to owner draw */
            mdi_tvout_set_mode(
                MDI_TV_MODE_OWNER_DRAW,
                tvout_buf_width,    /* layer_width */
                tvout_buf_height);  /* layer_height */

            tvout_layer = mdi_tvout_get_active_layer();

            gdi_layer_push_and_set_active(tvout_layer);
            gdi_layer_reset_clip();
            gdi_layer_clear(GDI_COLOR_BLACK);
            gdi_layer_pop_and_restore_active();

            /* blt to TV */
            mdi_tvout_blt();
        }
        else
        {
            /* has error, draw a black screen, use 10, 10 size to save memroy bandwidth */
            tvout_buf_width = 16;
            tvout_buf_height = 16;

            /* set mode to owner draw */
            mdi_tvout_set_mode(
                MDI_TV_MODE_OWNER_DRAW,
                tvout_buf_width,    /* layer_width */
                tvout_buf_height);  /* layer_height */

            tvout_layer = mdi_tvout_get_active_layer();

            gdi_layer_push_and_set_active(tvout_layer);
            gdi_layer_clear(GDI_COLOR_BLACK);
            gdi_layer_pop_and_restore_active();

            /* blt to TV */
            mdi_tvout_blt();

        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_tvout_decode
 * DESCRIPTION
 *  This function will decode the current file to tv buffer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_tvout_decode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 tvout_buf_width;
    S32 tvout_buf_height;
    S32 tvout_resized_offset_x;
    S32 tvout_resized_offset_y;
    S32 tvout_resized_width;
    S32 tvout_resized_height;

    GDI_HANDLE tvout_layer;
    S32 offset_x = 0;
#ifdef MDI_TVOUT_MT6228_SERIES
    S32 resized_img_w;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_tvout_is_enable())
    {
        if (g_imgadv_cntx.result >= 0 && (g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_SVG_FILE 
            || g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_M3D_FILE || g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_GIF_FILE))
        {
            // do nothing
        }
        else if (g_imgadv_cntx.result >= 0)
        {
            /* get best fit size for PAL/NTSC */
            mdi_tvout_get_owner_draw_best_size(&tvout_buf_width, &tvout_buf_height);

            if (g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_GIF_FILE)
            mdi_tvout_force_disable_vertical_filter();

            if ((g_imgadv_cntx.image_width > tvout_buf_width) ||
                (g_imgadv_cntx.image_height > tvout_buf_height))
            {
                gdi_image_util_fit_bbox(
                    tvout_buf_width,
                    tvout_buf_height,
                    g_imgadv_cntx.image_width,
                    g_imgadv_cntx.image_height,
                    &tvout_resized_offset_x,
                    &tvout_resized_offset_y,
                    &tvout_resized_width,
                    &tvout_resized_height);
            }
            else
            {
                tvout_resized_width = g_imgadv_cntx.image_width;
                tvout_resized_height = g_imgadv_cntx.image_height;
                tvout_resized_offset_x = (tvout_buf_width - g_imgadv_cntx.image_width) >> 1;
                tvout_resized_offset_y = (tvout_buf_height - g_imgadv_cntx.image_height) >> 1;
            }

            if (tvout_resized_width <= 1) tvout_resized_width = 2;
            if (tvout_resized_height <= 1) tvout_resized_height = 2;


        #ifdef MDI_TVOUT_MT6228_SERIES
            resized_img_w = tvout_resized_width;
            if (tvout_resized_width%8 != 0)
            {
                tvout_resized_width += (8-(tvout_resized_width%8));
            }
            offset_x = (tvout_resized_width - resized_img_w) >> 1;
        #endif

        /* set mode to owner draw */
        /*
        *  check if tvout_resized_width % 2 == 0 
        *  for all chips, tvout_buffer_width must be 2x.
        */
        if (tvout_resized_width % 2 == 0)
            mdi_tvout_set_mode(
                MDI_TV_MODE_OWNER_DRAW,
                tvout_resized_width,    /* layer_width */
                tvout_resized_height);  /* layer_height */
        else
            mdi_tvout_set_mode(
                MDI_TV_MODE_OWNER_DRAW,
                tvout_resized_width+1,    /* layer_width */
                tvout_resized_height);  /* layer_height */

        #ifdef MDI_TVOUT_MT6228_SERIES
            tvout_resized_width = resized_img_w;
        #endif

            tvout_layer = mdi_tvout_get_active_layer();

            /* need to set to tv lcd, gdi anim will keep this info */
            gdi_lcd_set_active(GDI_LCD_TVOUT_HANDLE);
            gdi_layer_push_and_set_active(tvout_layer);
            gdi_layer_reset_clip();
            gdi_layer_clear(GDI_COLOR_BLACK);

			g_imgadv_cntx.animation_on_tv = GDI_NULL_HANDLE;

            gdi_image_draw_animation_resized_file(
                offset_x,
                0,
                tvout_resized_width,
                tvout_resized_height,
                (PS8) g_imgadv_cntx.filepath,
                &g_imgadv_cntx.animation_on_tv);

            gdi_layer_pop_and_restore_active();
            gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
            
            /* blt to TV */
            mdi_tvout_blt();
        }
        else
        {
            /* has error, draw a black screen, use 10, 10 size to save memroy bandwidth */
            tvout_buf_width = 16;
            tvout_buf_height = 16;

            /* set mode to owner draw */
            mdi_tvout_set_mode(
                MDI_TV_MODE_OWNER_DRAW,
                tvout_buf_width,    /* layer_width */
                tvout_buf_height);  /* layer_height */

            tvout_layer = mdi_tvout_get_active_layer();

            gdi_layer_push_and_set_active(tvout_layer);
            gdi_layer_clear(GDI_COLOR_BLACK);
            gdi_layer_pop_and_restore_active();

            /* blt to TV */
            mdi_tvout_blt();

        }
    }
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_start_decode
 * DESCRIPTION
 *  This function start decode the current image.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_start_decode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    mmi_imgadv_extract_image_to_cache_layer();

    if (g_imgadv_cntx.result >= MMI_IMGADV_OK)
    {
        mmi_imgadv_extract_image_to_thumbnail_layer();
#if !defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
        mmi_imgadv_init_key_handler();
        g_imgadv_cntx.is_initialized = TRUE;
#endif        

    }
    else
    {
        /* after popup display, so gobackhistory */
        return;
    }

#ifdef __MMI_TVOUT__
    mmi_imgadv_tvout_decode();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_translate
 * DESCRIPTION
 *  This function is called when user move the left-up point of the view port to offset x and y
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_translate(S32 x, S32 y)
{
    S32 movement_x, movement_y;
    movement_x = x;
    movement_y = y;

    g_imgadv_cntx.map.wnd_offset_x += movement_x;
    g_imgadv_cntx.map.wnd_offset_y += movement_y;

    if (g_imgadv_cntx.map.wnd_offset_x < 0)
        g_imgadv_cntx.map.wnd_offset_x = 0;
    else if (g_imgadv_cntx.map.wnd_offset_x + g_imgadv_cntx.map.wnd_width > g_imgadv_cntx.map.width)
        g_imgadv_cntx.map.wnd_offset_x = g_imgadv_cntx.map.width - g_imgadv_cntx.map.wnd_width ;

    if (g_imgadv_cntx.map.wnd_offset_y < 0)
        g_imgadv_cntx.map.wnd_offset_y = 0;
    else if (g_imgadv_cntx.map.wnd_offset_y + g_imgadv_cntx.map.wnd_height > g_imgadv_cntx.map.height)
        g_imgadv_cntx.map.wnd_offset_y = g_imgadv_cntx.map.height - g_imgadv_cntx.map.wnd_height ;

    if (g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_SVG ||
         g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_SVG_FILE )
        gdi_anim_stop_all_by_layer(g_imgadv_cntx.cache_layer_handle);


    {
        PU8 src2;
        PU8 dest;
        U16 output_clip_x1, output_clip_x2, output_clip_y1, output_clip_y2;
        U16 src_width2, src_height2;
        S32 src_offset_x, src_offset_y, src_pitch2;
        S32 dest_width, dest_height;

        gdi_layer_push_and_set_active(g_imgadv_cntx.thumbnail_layer_handle);
        gdi_layer_get_buffer_ptr(&src2);
        gdi_layer_get_dimension(&src_pitch2, &dest_height); /* dest_height is useless. */
        

        src_offset_x = g_imgadv_cntx.map.wnd_offset_x * g_imgadv_cntx.map.ratio_map_to_thumbnail;
        src_offset_y = g_imgadv_cntx.map.wnd_offset_y * g_imgadv_cntx.map.ratio_map_to_thumbnail;
        src_width2 = g_imgadv_cntx.map.wnd_width * g_imgadv_cntx.map.ratio_map_to_thumbnail;
        src_height2 = g_imgadv_cntx.map.wnd_height * g_imgadv_cntx.map.ratio_map_to_thumbnail;

        /**********************************************************************************
         * check if src_width2/src_height2 > original size.
         **********************************************************************************/
        if (src_width2 > g_imgadv_cntx.thumbnail_layer_width)
            src_width2 = g_imgadv_cntx.thumbnail_layer_width;

        if (src_height2 > g_imgadv_cntx.thumbnail_layer_height)
            src_height2 = g_imgadv_cntx.thumbnail_layer_height;

        if ( src_offset_x + src_width2 > g_imgadv_cntx.thumbnail_layer_width)
            src_offset_x = g_imgadv_cntx.thumbnail_layer_width - src_width2;

        if ( src_offset_y + src_height2 > g_imgadv_cntx.thumbnail_layer_height)
            src_offset_y = g_imgadv_cntx.thumbnail_layer_height - src_height2;           

        src2 += ((src_offset_y * src_pitch2 * GDI_LAYER.bits_per_pixel) >> 3);
        src2 += ((src_offset_x * GDI_LAYER.bits_per_pixel) >> 3);
        gdi_layer_pop_and_restore_active();

        gdi_layer_push_and_set_active(g_imgadv_cntx.cache_layer_handle);
        gdi_layer_get_buffer_ptr(&dest);
        gdi_layer_get_dimension(&dest_width, &dest_height);
        gdi_layer_pop_and_restore_active();

        output_clip_x1 = 0;
        output_clip_y1 = 0;
        output_clip_x2 = dest_width - 1;
        output_clip_y2 = dest_height - 1;
        
    #ifdef GDI_USING_HW_RESIZER
        gdi_resizer(
            src2,
            src_width2,
            src_height2,
            src_pitch2,
            dest,
            dest_width,
            dest_height,
            output_clip_x1,
            output_clip_y1,
            output_clip_x2,
            output_clip_y2);
    #endif /* GDI_USING_HW_RESIZER */ 
    }    
    mmi_imgadv_draw_map();
    gdi_lcd_repaint_all();    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_move_right_press
 * DESCRIPTION
 *  This function handles the right arrow key pressed event.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_move_right_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
    gdi_image_nb_stop_all();
#endif
    gui_cancel_timer(mmi_imgadv_extract_image_to_cache_layer);
    mmi_imgadv_translate(3,0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_move_up_press
 * DESCRIPTION
 *  This function handles the up arrow key pressed event.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_move_up_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
    gdi_image_nb_stop_all();
#endif
    gui_cancel_timer(mmi_imgadv_extract_image_to_cache_layer);
    mmi_imgadv_translate(0,-3);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_move_down_press
 * DESCRIPTION
 *  This function handles the down key pressed event.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_move_down_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
    gdi_image_nb_stop_all();
#endif
    gui_cancel_timer(mmi_imgadv_extract_image_to_cache_layer);
    mmi_imgadv_translate(0,3);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_move_left_press
 * DESCRIPTION
 *  This function handles the left key pressed event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_move_left_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
    gdi_image_nb_stop_all();
#endif
    gui_cancel_timer(mmi_imgadv_extract_image_to_cache_layer);
    mmi_imgadv_translate(-3,0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_move_key_release
 * DESCRIPTION
 *  This function handles the up/right/left/down key release event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_move_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imgadv_cntx.map.zoom_factor_cnt == 0)
    {
        return;
    }
#if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
    gdi_image_nb_stop_all();
#endif

    gui_start_timer(400, mmi_imgadv_extract_image_to_cache_layer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_zoomin_press
 * DESCRIPTION
 *  This function handles zoomin key pressed event.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_zoomin_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_imgadv_extract_image_to_cache_layer);
    g_imgadv_cntx.active_osd_layout_ptr->zoomin.is_press = TRUE;
    mmi_imgadv_draw_osd();
    gdi_lcd_repaint_all();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_zoomin_release
 * DESCRIPTION
 *  This function handles zoomin key released event.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_zoomin_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgadv_cntx.active_osd_layout_ptr->zoomin.is_press = FALSE;
    mmi_imgadv_draw_osd();
    gdi_lcd_repaint_all();
    mmi_imgadv_zoomin();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_zoomout_press
 * DESCRIPTION
 *  This function handle zoomout key pressed event.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_zoomout_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_imgadv_extract_image_to_cache_layer);
    g_imgadv_cntx.active_osd_layout_ptr->zoomout.is_press = TRUE;
    mmi_imgadv_draw_osd();
    gdi_lcd_repaint_all();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_zoomout_release
 * DESCRIPTION
 *  This function handles zoomout key released event.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_zoomout_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgadv_cntx.active_osd_layout_ptr->zoomout.is_press = FALSE;
    mmi_imgadv_draw_osd();
    gdi_lcd_repaint_all();
    mmi_imgadv_zoomout();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_rotate_press
 * DESCRIPTION
 *  This function handles the rotate key pressed event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_rotate_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_imgadv_extract_image_to_cache_layer);
    g_imgadv_cntx.active_osd_layout_ptr->rotate.is_press = TRUE;
    mmi_imgadv_draw_osd();
    gdi_lcd_repaint_all();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_rotate_release
 * DESCRIPTION
 *  This function handles the rotate key released event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_rotate_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---[IMAGEVIEWER.c] before rotate() imgview_rotate = %d", g_imgadv_cntx.imgview_rotate);
    g_imgadv_cntx.active_osd_layout_ptr->rotate.is_press = FALSE;
    g_imgadv_cntx.imgview_rotate = (g_imgadv_cntx.imgview_rotate==GDI_LCD_LAYER_ROTATE_0)?GDI_LCD_LAYER_ROTATE_270 : GDI_LCD_LAYER_ROTATE_0;
    mmi_imgadv_draw_osd();
    gdi_lcd_repaint_all();

#if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
    gdi_image_nb_stop_all();
#endif

    /* Set flag for not reset imageviewer  */
    g_imgadv_cntx.is_reset_application = FALSE;
    g_imgadv_cntx.is_err_displayed = FALSE;
    EntryNewScreen(SCR_ID_IMGVIEW_VIEW, NULL, NULL, NULL);
    DeleteScreenIfPresent(SCR_ID_IMGVIEW_VIEW);
    mmi_imgadv_entry_app_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_lsk_press
 * DESCRIPTION
 *  This function handles the lsk pressed event.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_lsk_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_imgadv_extract_image_to_cache_layer);
    g_imgadv_cntx.lsk.is_press = TRUE;
    mmi_imgadv_draw_osd();
    gdi_lcd_repaint_all();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_lsk_release
 * DESCRIPTION
 *  This function handles the lsk released event.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_lsk_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgadv_cntx.lsk.is_press = FALSE;
    mmi_imgadv_draw_osd();
    gdi_lcd_repaint_all();

#if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
    gdi_image_nb_stop_all();
#endif

#if defined(__MMI_BPP_SUPPORT__)
    #ifdef __DRM_SUPPORT__
    if (mmi_bootup_get_active_flight_mode() == 0 && (IMGVIEW_DRM_PRINT_VALID & g_imgadv_cntx.drm_valid)!=0 )
    #else
    if (mmi_bootup_get_active_flight_mode() == 0)
    #endif
    {
        mmi_imgadv_bpp_print();
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_rsk_press
 * DESCRIPTION
 *  This function handles the rsk pressed event.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_rsk_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_imgadv_extract_image_to_cache_layer);
    g_imgadv_cntx.rsk.is_press = TRUE;
    mmi_imgadv_draw_osd();
    gdi_lcd_repaint_all();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_rsk_release
 * DESCRIPTION
 *  This function handles the rsk released event.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_rsk_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgadv_cntx.is_reset_application = TRUE;
    g_imgadv_cntx.rsk.is_press = FALSE;
    mmi_imgadv_draw_osd();
    gdi_lcd_repaint_all();

#if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
    gdi_image_nb_stop_all();
#endif


    if (g_imgadv_cntx.map.zoom_factor_cnt == 0)        
    {
    #ifdef __DRM_SUPPORT__
        mmi_imgadv_pause_drm_consume_if_need();
    #endif
        DeleteScreenIfPresent(SCR_FMGR_APP_FILE_OPTION);
        GoBackHistory();
    }
    else
    {
        g_imgadv_cntx.map.zoom_factor_cnt = 1;
        mmi_imgadv_zoomout();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_strolling_text_redraw_bg
 * DESCRIPTION
 *  This function clear the rect. of the scrolling text .
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_strolling_text_redraw_bg(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_scrolling_text_handle
 * DESCRIPTION
 *  This function handles scrolling text.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_scrolling_text_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_handle_scrolling_text(&g_imgadv_cntx.scrolling_title);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_draw_style_text
 * DESCRIPTION
 *  This function is called to draw style text.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_draw_style_text(PS8 str, S32 offset_x, S32 offset_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (r2lMMIFlag)
    {
        offset_x += gui_get_string_width((UI_string_type) str);
    }

    gui_move_text_cursor(offset_x, offset_y);
    gui_set_text_color(gui_color(67,87,153));
    gui_set_text_border_color(gui_color(255,255,255));
    gui_print_bordered_text((UI_string_type) str);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_init_map_box
 * DESCRIPTION
 *  This function is called to initialize the map which is used by imgadv.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_init_map_box(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---[IMAGEVIEWER.c] extract_init_map_box()");    
    if (g_imgadv_cntx.image_width > g_imgadv_cntx.image_height)
    {
        g_imgadv_cntx.map.ratio_map_to_image = (float) MMI_IMGADV_MAP_WIDTH/g_imgadv_cntx.image_width;
        g_imgadv_cntx.map.width = MMI_IMGADV_MAP_WIDTH;
        g_imgadv_cntx.map.map_offset_x = 0;
        g_imgadv_cntx.map.height = (g_imgadv_cntx.image_height * g_imgadv_cntx.map.ratio_map_to_image + 0.5);
        g_imgadv_cntx.map.map_offset_y = (MMI_IMGADV_MAP_HEIGHT - g_imgadv_cntx.map.height)>>1; 
    }
    else
    {
        g_imgadv_cntx.map.ratio_map_to_image = (float) MMI_IMGADV_MAP_HEIGHT/g_imgadv_cntx.image_height;
        g_imgadv_cntx.map.height = MMI_IMGADV_MAP_HEIGHT;
        g_imgadv_cntx.map.map_offset_y = 0;
        g_imgadv_cntx.map.width = (g_imgadv_cntx.image_width * g_imgadv_cntx.map.ratio_map_to_image + 0.5);
        g_imgadv_cntx.map.map_offset_x = (MMI_IMGADV_MAP_WIDTH - g_imgadv_cntx.map.width)>>1;
    }

    g_imgadv_cntx.map.is_zoomin_able = FALSE;
    g_imgadv_cntx.map.wnd_height = g_imgadv_cntx.map.height;
    g_imgadv_cntx.map.wnd_width = g_imgadv_cntx.map.width;
    g_imgadv_cntx.map.wnd_offset_x = 0;
    g_imgadv_cntx.map.wnd_offset_y = 0;
    g_imgadv_cntx.map.zoom_factor = 1.25;
    g_imgadv_cntx.map.zoom_factor_cnt = 0;
    g_imgadv_cntx.map.ratio_map_to_thumbnail = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_draw_map
 * DESCRIPTION
 *  This function is called to draw the small map on the screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_draw_map(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x=0, offset_y=0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    
    gdi_layer_push_and_set_active(g_imgadv_cntx.base_layer_handle);
    
    if (GDI_LCD_LAYER_ROTATE_0 == g_imgadv_cntx.imgview_rotate)
    {
        offset_x = MMI_IMGADV_MAP_POSITION_X + g_imgadv_cntx.map.map_offset_x ;
        offset_y = MMI_IMGADV_MAP_POSITION_Y + g_imgadv_cntx.map.map_offset_y ;
    }
    else if (GDI_LCD_LAYER_ROTATE_270 == g_imgadv_cntx.imgview_rotate)
    {
        offset_x = MMI_IMGADV_ROTATED_MAP_POSITION_X + g_imgadv_cntx.map.map_offset_x ;
        offset_y = MMI_IMGADV_ROTATED_MAP_POSITION_Y + g_imgadv_cntx.map.map_offset_y ;
    }

    gdi_draw_solid_rect(offset_x - 2,
                        offset_y - 2,
                        offset_x + g_imgadv_cntx.map.width + 2,
                        offset_y + g_imgadv_cntx.map.height + 2,
                        GDI_COLOR_TRANSPARENT);

    if(g_imgadv_cntx.map.zoom_factor_cnt > 0)
    {
        gdi_draw_solid_rect(offset_x - 1,
                      offset_y - 1,
                      offset_x + g_imgadv_cntx.map.width + 1,
                      offset_y + g_imgadv_cntx.map.height + 1,
                      GDI_COLOR_GRAY);

        gdi_draw_rect(offset_x - 2,
                      offset_y - 2,
                      offset_x + g_imgadv_cntx.map.width + 2,
                      offset_y + g_imgadv_cntx.map.height + 2,
                      GDI_COLOR_WHITE);

        gdi_draw_solid_rect(offset_x + g_imgadv_cntx.map.wnd_offset_x,
                            offset_y + g_imgadv_cntx.map.wnd_offset_y,
                            offset_x + g_imgadv_cntx.map.wnd_offset_x + g_imgadv_cntx.map.wnd_width,
                            offset_y + g_imgadv_cntx.map.wnd_offset_y + g_imgadv_cntx.map.wnd_height,
                            GDI_COLOR_WHITE);
    }
    gdi_layer_pop_and_restore_active();

}
    

/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_draw_num_count
 * DESCRIPTION
 *  This function is called to draw the oo/xx on the screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_draw_num_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_width;
    S32 str_height;
    S32 offset_x = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    gui_set_font(&MMI_medium_font);

    gui_measure_string((UI_string_type) g_imgadv_cntx.count_str, &str_width, &str_height);

    gdi_draw_solid_rect(g_imgadv_cntx.active_osd_layout_ptr->num_count.offset_x,
                        g_imgadv_cntx.active_osd_layout_ptr->num_count.offset_y,
                        g_imgadv_cntx.active_osd_layout_ptr->num_count.offset_x+g_imgadv_cntx.active_osd_layout_ptr->num_count.width,
                        g_imgadv_cntx.active_osd_layout_ptr->num_count.offset_y+g_imgadv_cntx.active_osd_layout_ptr->num_count.height,
                        GDI_COLOR_TRANSPARENT);

    if(g_imgadv_cntx.active_osd_layout_ptr->num_count.width > str_width)
        offset_x = (g_imgadv_cntx.active_osd_layout_ptr->num_count.width - str_width)>>1;

    mmi_imgadv_draw_style_text(
        g_imgadv_cntx.count_str,
        g_imgadv_cntx.active_osd_layout_ptr->num_count.offset_x+offset_x,
        g_imgadv_cntx.active_osd_layout_ptr->num_count.offset_y);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_draw_softkey
 * DESCRIPTION
 *  draw preview softkey
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_draw_softkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_BPP_SUPPORT__)
    S32 lsk_offset_x = 0;
    S32 lsk_offset_y = 0;
#endif
    S32 rsk_offset_x = 0;
    S32 rsk_offset_y = 0;
    S32 str_width;
    S32 str_height;
    PS8 str_ptr;
    U16 lsk_id;
    U16 rsk_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lsk_id = STR_ID_IMGVIEW_PRINT;
    rsk_id = STR_GLOBAL_BACK;

    gdi_layer_reset_clip();
    gdi_layer_reset_text_clip();

    /* if is fullscreen display, or normal display but without mmi_softkey */
    gui_set_font(&MMI_medium_font);

#if defined(__MMI_BPP_SUPPORT__)
    /* lsk */
    #ifdef __DRM_SUPPORT__
    if (mmi_bootup_get_active_flight_mode() == 0 && (IMGVIEW_DRM_PRINT_VALID & g_imgadv_cntx.drm_valid)!=0 )
    #else
    if (mmi_bootup_get_active_flight_mode() == 0)
    #endif
    {
        str_ptr = (PS8) GetString(lsk_id);

        gui_measure_string((UI_string_type) str_ptr, &str_width, &str_height);

        if (g_imgadv_cntx.imgview_rotate == GDI_LCD_LAYER_ROTATE_270)
        {
            wgui_softkey_get_offset_ex((UI_string_type) str_ptr, &lsk_offset_x, &lsk_offset_y, MMI_LEFT_SOFTKEY, MMI_FRM_SCREEN_ROTATE_270);
        }
        else
        {
            wgui_softkey_get_offset((UI_string_type) str_ptr, &lsk_offset_x, &lsk_offset_y, MMI_LEFT_SOFTKEY);        
        }

        /* check r2lMMIFlag flag to correct offset_x of string, due to we will do the change in 
         * mmi_camera_draw_style_text() */
        if (r2lMMIFlag)
        {
            lsk_offset_x -= gui_get_string_width((UI_string_type) str_ptr);
        }

        if (g_imgadv_cntx.lsk.is_press)
        {
            lsk_offset_x++;
            lsk_offset_y++;
        }

        gdi_draw_solid_rect(lsk_offset_x-2,lsk_offset_y-2,lsk_offset_x+str_width+2,lsk_offset_y+str_height+2,GDI_COLOR_TRANSPARENT);
        mmi_imgadv_draw_style_text(
            str_ptr,
            lsk_offset_x ,
            lsk_offset_y );

        g_imgadv_cntx.lsk.offset_x = lsk_offset_x;
        g_imgadv_cntx.lsk.offset_y = lsk_offset_y;
        g_imgadv_cntx.lsk.width = str_width;
        g_imgadv_cntx.lsk.height = str_height;
    }
#endif /* defined(__MMI_BPP_SUPPORT__) */

    /* rsk */
    str_ptr = (PS8) GetString(rsk_id);

    gui_measure_string((UI_string_type) str_ptr, &str_width, &str_height);
    if (g_imgadv_cntx.imgview_rotate == GDI_LCD_LAYER_ROTATE_270)
    {
        wgui_softkey_get_offset_ex((UI_string_type) str_ptr, &rsk_offset_x, &rsk_offset_y, MMI_RIGHT_SOFTKEY, MMI_FRM_SCREEN_ROTATE_270);
    }
    else
    {
        wgui_softkey_get_offset((UI_string_type) str_ptr, &rsk_offset_x, &rsk_offset_y, MMI_RIGHT_SOFTKEY);
    }

    if (r2lMMIFlag)
    {
        rsk_offset_x -= gui_get_string_width((UI_string_type) str_ptr);
    }

    if (g_imgadv_cntx.rsk.is_press)
    {
        rsk_offset_x++;
        rsk_offset_y++;
    }

    gdi_draw_solid_rect(rsk_offset_x-2,rsk_offset_y-2,rsk_offset_x+str_width+2,rsk_offset_y+str_height+2,GDI_COLOR_TRANSPARENT);
    mmi_imgadv_draw_style_text(
        str_ptr,
        rsk_offset_x,
        rsk_offset_y);

    g_imgadv_cntx.rsk.offset_x = rsk_offset_x;
    g_imgadv_cntx.rsk.offset_y = rsk_offset_y;
    g_imgadv_cntx.rsk.width = str_width;
    g_imgadv_cntx.rsk.height = str_height;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_init_default_touch_and_key_handler
 * DESCRIPTION
 *  init key handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_init_default_touch_and_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_TOUCH_SCREEN__
    /* register pen down/up/move event */
    wgui_register_pen_down_handler(mmi_imgadv_pen_down_hdlr);
    wgui_register_pen_up_handler(mmi_imgadv_pen_up_hdlr);
    wgui_register_pen_move_handler(mmi_imgadv_pen_move_hdlr);
#endif /* __MMI_TOUCH_SCREEN__ */ 

    /* if less or equal to 1 image, no need to switch to next image */
    if (g_imgadv_cntx.total_count > 1)
    {
        SetKeyHandler(mmi_imgadv_next_image_press, KEY_VOL_DOWN, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_imgadv_previous_image_press, KEY_VOL_UP, KEY_EVENT_DOWN);

        SetKeyHandler(mmi_imgadv_next_image_release, KEY_VOL_DOWN, KEY_EVENT_UP);
        SetKeyHandler(mmi_imgadv_previous_image_release, KEY_VOL_UP, KEY_EVENT_UP);
    }
#if defined(__MMI_BPP_SUPPORT__)
    #ifdef __DRM_SUPPORT__
    if (mmi_bootup_get_active_flight_mode() == 0 && (IMGADV_DRM_PRINT_VALID & g_imgadv_cntx.drm_valid)!=0 )
    #else
    if (mmi_bootup_get_active_flight_mode() == 0)
    #endif
    {
        SetKeyHandler(mmi_imgadv_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_imgadv_lsk_release, KEY_LSK, KEY_EVENT_UP);
    }
#endif
    SetKeyHandler(mmi_imgadv_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_imgadv_rsk_release, KEY_RSK, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_init_key_handler
 * DESCRIPTION
 *  init key handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_init_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_KEY);    

    if (g_imgadv_cntx.imgview_rotate == GDI_LCD_LAYER_ROTATE_270)
    {
        if (g_imgadv_cntx.map.zoom_factor_cnt > 0)
        {
            SetKeyHandler(mmi_imgadv_move_down_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_imgadv_move_left_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_imgadv_move_up_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_imgadv_move_right_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);

            SetKeyHandler(mmi_imgadv_move_key_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_imgadv_move_key_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_imgadv_move_key_release, KEY_UP_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_imgadv_move_key_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_imgadv_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_imgadv_reenter, KEY_RSK, KEY_EVENT_UP);

                        
        }
        else
        {
            SetKeyHandler(mmi_imgadv_previous_image_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_imgadv_next_image_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_imgadv_previous_image_release, KEY_UP_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_imgadv_next_image_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_imgadv_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_imgadv_rsk_release, KEY_RSK, KEY_EVENT_UP);    
        } 
    }
    else
    {
        if (g_imgadv_cntx.map.zoom_factor_cnt > 0)
        {
            SetKeyHandler(mmi_imgadv_move_down_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_imgadv_move_left_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_imgadv_move_up_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_imgadv_move_right_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

            SetKeyHandler(mmi_imgadv_move_key_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_imgadv_move_key_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_imgadv_move_key_release, KEY_UP_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_imgadv_move_key_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_imgadv_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_imgadv_reenter, KEY_RSK, KEY_EVENT_UP);
        }
        else
        {
            SetKeyHandler(mmi_imgadv_previous_image_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_imgadv_next_image_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_imgadv_previous_image_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_imgadv_next_image_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);        
            SetKeyHandler(mmi_imgadv_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_imgadv_rsk_release, KEY_RSK, KEY_EVENT_UP);
        }

    }

    SetKeyHandler(mmi_imgadv_zoomin_press, KEY_1, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_imgadv_zoomout_press, KEY_2, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_imgadv_zoomin_release, KEY_1, KEY_EVENT_UP);
    SetKeyHandler(mmi_imgadv_zoomout_release, KEY_2, KEY_EVENT_UP);
    SetKeyHandler(mmi_imgadv_rotate_press, KEY_3, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_imgadv_rotate_release, KEY_3, KEY_EVENT_UP);


    /* if less or equal to 1 image, no need to switch to next image */
    if (g_imgadv_cntx.total_count > 1)
    {
        SetKeyHandler(mmi_imgadv_next_image_press, KEY_VOL_DOWN, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_imgadv_previous_image_press, KEY_VOL_UP, KEY_EVENT_DOWN);

        SetKeyHandler(mmi_imgadv_next_image_release, KEY_VOL_DOWN, KEY_EVENT_UP);
        SetKeyHandler(mmi_imgadv_previous_image_release, KEY_VOL_UP, KEY_EVENT_UP);
    }
#if defined(__MMI_BPP_SUPPORT__)

    #ifdef __DRM_SUPPORT__
    if (mmi_bootup_get_active_flight_mode() == 0 && (IMGVIEW_DRM_PRINT_VALID & g_imgadv_cntx.drm_valid)!=0 )
    #else
    if (mmi_bootup_get_active_flight_mode() == 0)
    #endif
    {
        SetKeyHandler(mmi_imgadv_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_imgadv_lsk_release, KEY_LSK, KEY_EVENT_UP);
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_entry_app_screen
 * DESCRIPTION
 *  Entry function of imgadv viewer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgadv_entry_app_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE                   fs_handle;
    S32                         str_len;
    U8                          *guiBuffer;
    S32                         index;
    PS8                         error_str_ptr;
    S8                          buffer[30];  /* for xxxx/xxxx */
    FMGR_FILE_INFO_STRUCT       file_info;
    S32                         total_count;
    U8                          drm_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */

        if (mmi_usb_check_path_exported((PS8) MMI_IMGVIEW_STORAGE_FILEPATH_PHONE))
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    /* check if there is small screen above IMAGEVIEWER */
#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    if (mmi_is_redrawing_bk_screens() == TRUE)
    {
        return;
    }
#endif /* __MMI_UI_SMALL_SCREEN_SUPPORT__ */ 

    index = mmi_fmgr_kernel_get_cur_idx();
    total_count = mmi_fmgr_kernel_get_file_count();

    if (index >= total_count)
    {
        index = 0;
        mmi_fmgr_kernel_move_selection_down();
    }

    mmi_fmgr_kernel_get_file_info(index, &file_info);

    #ifdef __DRM_SUPPORT__
    drm_result = fmgr_check_drm_rights(&file_info, DRM_PERMISSION_DISPLAY);
    if (drm_result == FMGR_DRM_NO_PERMISSION)
    {
        g_imgadv_cntx.result = MMI_IMGADV_DRM_INVALID; 
        g_imgadv_cntx.err_str_ptr = GetString(STR_GLOBAL_DRM_PROHIBITED);
    }
    else if (drm_result == FMGR_DRM_REQUEST_RIGHTS)
    {
        entry_fmgr_request_rights_confirm();
        return;
    }
    #endif
    /* exit previous screen */
    EntryNewScreen(SCR_ID_IMGVIEW_VIEW, mmi_imgadv_exit_app_screen, mmi_imgadv_entry_app_screen, NULL);

    SetDelScrnIDCallbackHandler(SCR_ID_IMGVIEW_APP, mmi_imgadv_del_scr_callback);

    PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---[IMAGEVIEWER.c] entry_app() , imgview_rotate = %d", g_imgadv_cntx.imgview_rotate);

    /* force all playing keypad tone off */
    AudioStopReq(GetCurKeypadTone());

    /* entry full screen app */
    entry_full_screen();

    gdi_layer_reset_clip();
    gdi_layer_reset_text_clip();

    /* disable key pad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);

#if defined(__MMI_BPP_SUPPORT__)
    if (mmi_imgview_is_printing())
    {
        mmi_imgview_cancel_printing();
    }
#endif

    /* check if it is return from interrupt */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMGVIEW_VIEW);
    if (guiBuffer != NULL)
    {
        g_imgadv_cntx.is_resume = TRUE;

        /* if it is current image type is SVG with TVOUT enable, assume it is first enter imageviewer */
        if (g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_SVG ||
            g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_SVG_FILE )
        {
            g_imgadv_cntx.is_resume = FALSE; 
            g_imgadv_cntx.map.zoom_factor_cnt = 0;			

            if (g_imgadv_cntx.result == MMI_IMGADV_NON_FIRST_TIME_DECODE_ERR)
            {
                g_imgadv_cntx.is_err_displayed = FALSE;
                g_imgadv_cntx.result = MMI_IMGADV_OK;
            }
        }
    }
    else
    {
        g_imgadv_cntx.is_resume = FALSE;
        g_imgadv_cntx.map.zoom_factor_cnt = 0;
        g_imgadv_cntx.map.max_zoom_factor = 255;
    }
    /************ base layer ************/
    /* get MainLCD base handle */
    gdi_layer_get_base_handle(&g_imgadv_cntx.base_layer_handle);

    /* clear fullscreen */
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);

    if (g_imgadv_cntx.imgview_rotate == GDI_LCD_LAYER_ROTATE_0)
    {
        gdi_layer_resize(LCD_WIDTH,LCD_HEIGHT);
        gdi_lcd_set_rotate(GDI_LCD_LAYER_ROTATE_0);
    }
    else if (g_imgadv_cntx.imgview_rotate == GDI_LCD_LAYER_ROTATE_270)
    {
        gdi_layer_resize(LCD_HEIGHT,LCD_WIDTH);
        gdi_lcd_set_rotate(GDI_LCD_LAYER_ROTATE_270);
    }

    /* allocate string buffer */
    g_imgadv_cntx.filepath = mmi_frm_scrmem_alloc(FMGR_PATH_BUFFER_SIZE);
    g_imgadv_cntx.buf_filename_no_ext = mmi_frm_scrmem_alloc(FMGR_PATH_BUFFER_SIZE);
    g_imgadv_cntx.count_str = mmi_frm_scrmem_alloc(60);

    /* prepare xxxx/xxxx string */
    sprintf(buffer, "%d/%d", (U16) index + 1, (U16) total_count);
    mmi_asc_to_ucs2((PS8) g_imgadv_cntx.count_str, (PS8) buffer);

    /* append the name to path */
    mmi_fmgr_kernel_get_path_name(g_imgadv_cntx.filepath);

    mmi_ucs2cat(g_imgadv_cntx.filepath, file_info.file_name);

    g_imgadv_cntx.total_count = total_count;
    g_imgadv_cntx.is_short = file_info.is_short;
    /* end of prepare xxxx/xxxx string */   

    /* temp solution, waiting for decoder has resizer for gif and bmp */
    g_imgadv_cntx.image_type = gdi_image_get_type_from_file(g_imgadv_cntx.filepath);
    
    /* create resource for imageviewer */
    mmi_imgadv_create_resource(); 

    gdi_layer_set_blt_layer(g_imgadv_cntx.cache_layer_handle,g_imgadv_cntx.base_layer_handle,0,0);


    fs_handle = DRM_open_file((U16*)g_imgadv_cntx.filepath, FS_READ_ONLY, DRM_PERMISSION_NONE);

    if (fs_handle < 0)
    {
        /***************************************************************************
        * if the Path is lost (Memory Card be plug out)
        * Display "Path not found", then remove all imageviewer related screen.
        ***************************************************************************/
        if (fs_handle == FS_PATH_NOT_FOUND)
        {
            U16 scrnid;
            g_imgadv_cntx.err_str_ptr = GetString(FMGR_FS_PATH_NOT_FOUND_TEXT);
            mmi_imgadv_display_error();      
            for(scrnid= SCR_ID_IMGVIEW_VIEW; scrnid <= SCR_ID_IMGVIEW_VIEW_STYLE; scrnid++)
            {
                DeleteScreenIfPresent(scrnid);
            }
            return;
        }  
        else if (fs_handle == FS_ACCESS_DENIED)
        {
            U16 scrnid;
            g_imgadv_cntx.err_str_ptr = GetString(FMGR_FS_ACCESS_DENIED_TEXT);
            mmi_imgadv_display_error();      
            for(scrnid= SCR_ID_IMGVIEW_VIEW; scrnid <= SCR_ID_IMGVIEW_VIEW_STYLE; scrnid++)
            {
                DeleteScreenIfPresent(scrnid);
            }
            return;

        }
        /* open file failed */
        g_imgadv_cntx.result = MMI_IMGADV_ERROR;
        g_imgadv_cntx.err_str_ptr = GetString(STR_ID_FMGR_INVALID_IMAGE_FORMAT);
    }
    else
    {
        DRM_file_size(fs_handle, (kal_uint32*) & (g_imgadv_cntx.file_size));
        DRM_close_file(fs_handle);
    }

    /* DRM permission check */
#ifdef __DRM_SUPPORT__
    if(g_imgadv_cntx.result != MMI_IMGADV_DRM_INVALID
       && g_imgadv_cntx.is_err_displayed == FALSE)
    {
        g_imgadv_cntx.result = MMI_IMGADV_DRM_INVALID;

        if (g_imgadv_cntx.drm_state == IMGADV_DRM_STATE_EXIT)
        {
            g_imgadv_cntx.drm_valid = mmi_imgadv_process_drm_hdlr();

            /* ERROR HAPPENED */
            if ((g_imgadv_cntx.drm_valid & IMGADV_DRM_DRM_FILE)==0)
            {
                g_imgadv_cntx.result = MMI_IMGADV_OK;
                g_imgadv_cntx.drm_valid |= IMGADV_DRM_PRINT_VALID;
            }
            else if (((IMGADV_DRM_MULTI_PART & g_imgadv_cntx.drm_valid)!=0))
            {
                /* MULTI-PART */
                g_imgadv_cntx.result = MMI_IMGADV_DRM_INVALID; 
                g_imgadv_cntx.err_str_ptr = GetString(STR_ID_IMGVIEW_NOTIFY_MULTIPART_NOT_SUPPORT);
                mmi_imgadv_display_error();
                return;                
            }
            else if ((IMGADV_DRM_DISPLAY_VALID & g_imgadv_cntx.drm_valid)==0)
            {
                /* DISPLAY PERMISSIONT DENINED */
                g_imgadv_cntx.result = MMI_IMGADV_DRM_INVALID; 
                g_imgadv_cntx.err_str_ptr = GetString(STR_GLOBAL_DRM_PROHIBITED);
                mmi_imgadv_display_error();
                return;
            }
            else 
                g_imgadv_cntx.result = MMI_IMGADV_OK;
        }
        else if (g_imgadv_cntx.drm_state == IMGADV_DRM_STATE_PAUSE)
        {

            /* check print right again */
            if (DRM_get_object_method(NULL,(PU16) g_imgadv_cntx.filepath) != DRM_METHOD_NONE)
            {
                if (!DRM_validate_permission(NULL, (PU16)g_imgadv_cntx.filepath, DRM_PERMISSION_PRINT))
                {
                    g_imgadv_cntx.drm_valid&= ~(IMGADV_DRM_PRINT_VALID);
                }
            }            

            /* if DRM State in PAUSE, Consume DRM Right */
            DRM_resume_consume(g_imgadv_cntx.drm_id);
            g_imgadv_cntx.result = MMI_IMGADV_OK;
            g_imgadv_cntx.drm_state = IMGADV_DRM_STATE_CONSUME;

            DRM_close_file(g_imgadv_cntx.drm_handle);
            g_imgadv_cntx.drm_handle = NULL;
        }
        else
        {
            /* should not go into this section */
            ASSERT(0);
        }

    }
#else /* __DRM_SUPPORT__ */ 
    g_imgadv_cntx.result = MMI_IMGADV_OK;
#endif /* __DRM_SUPPORT__ */ 

    str_len = mmi_ucs2strlen(g_imgadv_cntx.filepath);

    /* find file name - by finding "\\" */
    for (index = str_len * 2 - 2; index >= 2; index -= 2)
    {
        if (mmi_ucs2ncmp((PS8) & g_imgadv_cntx.filepath[index], (PS8) L"\\", 1) == 0)
        {
            index += 2;
            break;
        }
    }

    if (g_imgadv_cntx.is_short)
    {
        mmi_chset_mixed_text_to_ucs2_str(
            (U8*) g_imgadv_cntx.buf_filename_no_ext,
            FMGR_PATH_BUFFER_SIZE,
            (U8*) (&(g_imgadv_cntx.filepath[index])),
            PhnsetGetDefEncodingType());
    }
    else
        mmi_ucs2cpy((PS8) g_imgadv_cntx.buf_filename_no_ext, (PS8) (&(g_imgadv_cntx.filepath[index])));

    mmi_fmgr_hide_ext_name(g_imgadv_cntx.buf_filename_no_ext);


    if (g_imgadv_cntx.result >= MMI_IMGADV_OK && !mmi_fmgr_util_file_limit_check(FMGR_LIMIT_IMAGE_VIEWER, (PS8) g_imgadv_cntx.filepath, &error_str_ptr))
    {
        g_imgadv_cntx.err_str_ptr = error_str_ptr;
        g_imgadv_cntx.result = MMI_IMGADV_ERROR;
    }

    if (g_imgadv_cntx.result >= MMI_IMGADV_OK)
    {
        g_imgadv_cntx.result = gdi_image_get_dimension_file(
                                        (PS8) g_imgadv_cntx.filepath,
                                        &(g_imgadv_cntx.image_width),
                                        &(g_imgadv_cntx.image_height));
        if (((g_imgadv_cntx.image_width <= 0) || (g_imgadv_cntx.image_height <= 0)) ||
            g_imgadv_cntx.result < 0)
        {        
            g_imgadv_cntx.result = MMI_IMGADV_INVALID_FORMAT;
            g_imgadv_cntx.err_str_ptr = GetString(STR_ID_FMGR_INVALID_IMAGE_FORMAT);
        }

        /* add image size limit for svg file type */
        if (g_imgadv_cntx.image_type==GDI_IMAGE_TYPE_SVG || g_imgadv_cntx.image_type==GDI_IMAGE_TYPE_SVG_FILE)
        {
            g_imgadv_cntx.image_width *= 3;
            g_imgadv_cntx.image_height *= 3;
        }
    }

#ifdef __MMI_TVOUT__
    if (mdi_tvout_is_enable())
    {
        /* if is fullscreen, we shall set to owner APP Owner draw, to avoid GDI's update */
        mdi_tvout_set_owner(MDI_TV_OWNER_APP);
    }
#endif /* __MMI_TVOUT__ */ 

    /* initialize osd icon */
    mmi_imgadv_init_osd_icon_position();

    /* get active osd cntx */
    mmi_imgadv_get_active_osd_cntx();

    /* show ooxx/ooxx */
    mmi_imgadv_draw_num_count();

    /* tmp test */
    if (g_imgadv_cntx.is_resume == FALSE)
        mmi_imgadv_init_map_box();
    
    mmi_imgadv_draw_map();

    /* draw osd */
    mmi_imgadv_draw_osd();

    /* show file name */
    {
        S32 str_width, str_height;
        gui_set_font(&MMI_medium_font);
        gui_measure_string((UI_string_type) g_imgadv_cntx.buf_filename_no_ext, &str_width, &str_height);

        if ( str_width > g_imgadv_cntx.active_osd_layout_ptr->title.width )
        {
            gui_create_scrolling_text(
                &g_imgadv_cntx.scrolling_title,
                g_imgadv_cntx.active_osd_layout_ptr->title.offset_x,
                g_imgadv_cntx.active_osd_layout_ptr->title.offset_y,
                g_imgadv_cntx.active_osd_layout_ptr->title.width,
                g_imgadv_cntx.active_osd_layout_ptr->title.height,
                (UI_string_type) g_imgadv_cntx.buf_filename_no_ext,
                mmi_imgadv_scrolling_text_handle,
                mmi_imgadv_strolling_text_redraw_bg,
                gui_color(67,87,153),
                gui_color(255, 255, 255));

            g_imgadv_cntx.scrolling_title.flags |=UI_SCROLLING_TEXT_BORDERED_TEXT;
            gui_show_scrolling_text(&g_imgadv_cntx.scrolling_title);
            g_imgadv_cntx.is_scrolling_title = TRUE;
        }
        else
        {
            S32 offset_x ;
            gdi_draw_solid_rect(g_imgadv_cntx.active_osd_layout_ptr->title.offset_x,
                                g_imgadv_cntx.active_osd_layout_ptr->title.offset_y,
                                g_imgadv_cntx.active_osd_layout_ptr->title.offset_x+g_imgadv_cntx.active_osd_layout_ptr->title.width,
                                g_imgadv_cntx.active_osd_layout_ptr->title.offset_y+g_imgadv_cntx.active_osd_layout_ptr->title.height,
                                GDI_COLOR_TRANSPARENT);


            offset_x = (g_imgadv_cntx.active_osd_layout_ptr->title.width - str_width)>>1;

            mmi_imgadv_draw_style_text(
                g_imgadv_cntx.buf_filename_no_ext,
                g_imgadv_cntx.active_osd_layout_ptr->title.offset_x+offset_x,
                g_imgadv_cntx.active_osd_layout_ptr->title.offset_y);
                    
        }
    }
    /* blt to lcd */
    gdi_lcd_repaint_all();

    /* clear ori key handler */
    ClearInputEventHandler(MMI_DEVICE_KEY);

    if (g_imgadv_cntx.is_err_displayed == TRUE) 
    {
        if (g_imgadv_cntx.result == MMI_IMGADV_OK && g_imgadv_cntx.map.max_zoom_factor != 255)
            g_imgadv_cntx.result = MMI_IMGADV_NON_FIRST_TIME_DECODE_ERR;

        switch (g_imgadv_cntx.result)
        {
            case MMI_IMGADV_OK:
            case MMI_IMGADV_ERROR:
            case MMI_IMGADV_INVALID_FORMAT:
            case MMI_IMGADV_DRM_INVALID:
            case MMI_IMGADV_FIRST_TIME_DECODE_ERR:
                g_imgadv_cntx.map.is_zoomin_able = FALSE;
                g_imgadv_cntx.map.zoom_factor_cnt = 0;
                mmi_imgadv_draw_map();
                mmi_imgadv_draw_osd();
                gdi_lcd_repaint_all();
                mmi_imgadv_init_key_handler();
                break;
            case MMI_IMGADV_NON_FIRST_TIME_DECODE_ERR:
                mmi_imgadv_draw_map();
                mmi_imgadv_draw_osd();
                mmi_imgadv_extract_image_to_cache_layer();

                if (g_imgadv_cntx.result >= MMI_IMGADV_OK)
                {
                    g_imgadv_cntx.map.is_zoomin_able = FALSE;
                    mmi_imgadv_extract_image_to_thumbnail_layer();
                }
                else
                {
                    gdi_lcd_repaint_all();
                }
            #if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
                g_imgadv_cntx.is_initialized = FALSE;
            #else
                mmi_imgadv_init_key_handler();
                mmi_imgadv_init_default_touch_and_key_handler();
            #endif           
            #ifdef __MMI_TVOUT__
                mmi_imgadv_tvout_clear_bg();
                mmi_imgadv_tvout_decode();
            #endif


                return;
                break;
        }
    }
    else if (g_imgadv_cntx.result < MMI_IMGADV_OK)
    {
        mmi_imgadv_display_error();      
        return;
    }
    else
    {
        if (g_imgadv_cntx.is_resume == FALSE)
        {
            /* it will calculate roi */
            mmi_imgadv_init_image_info();
        }

        g_imgadv_cntx.is_initialized = FALSE;
        /* start timer to decode */
        gui_start_timer(400, mmi_imgadv_start_decode);
        gdi_lcd_repaint_all();
    }
#if !defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
    mmi_imgadv_init_default_touch_and_key_handler();
#endif
#ifdef __MMI_TVOUT__
    mmi_imgadv_tvout_clear_bg();
#endif /* __MMI_TVOUT__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_zoomin
 * DESCRIPTION
 *  zoom in function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static BOOL mmi_imgadv_zoomin(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 old_wnd_width;
    S32 old_wnd_height;
    S32 old_wnd_offset_x;
    S32 old_wnd_offset_y;
    S32 old_resized_width;
    S32 old_resized_height;
    float old_ratio;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---[IMAGEVIEWER.c] zoomin()");

#ifdef __MMI_TVOUT__
    /******************************************************************************
    * if TVOUT is enable and image_type is SVG, disable zoomin function
    ******************************************************************************/
    if (mdi_tvout_is_enable() && (g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_SVG ||
             g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_SVG_FILE ))
            return FALSE; 
#endif /* __MMI_TVOUT__ */ 


    /******************************************************************************
    * if not initialized, also disable zoomin function
    ******************************************************************************/
    if (g_imgadv_cntx.is_initialized == FALSE || g_imgadv_cntx.map.is_zoomin_able == FALSE || g_imgadv_cntx.map.max_zoom_factor <= g_imgadv_cntx.map.zoom_factor_cnt)
        return FALSE;

#if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
    gdi_image_nb_stop_all();
#endif


    /* while it is first-time zoomin, if the image display on screen currently is small than lcd size,
       zoom to fit screen size, else zoom factor = 1.414 */
    if (g_imgadv_cntx.map.zoom_factor_cnt == 0)
    {
        float tmp_ratio;
    
        tmp_ratio = (float)g_imgadv_cntx.cache_layer_height/ g_imgadv_cntx.resized_img_height;
        if (g_imgadv_cntx.map.zoom_factor  < tmp_ratio)
        {
            g_imgadv_cntx.map.zoom_factor  = tmp_ratio;
            g_imgadv_cntx.is_width_dominate = TRUE;
        }

        tmp_ratio = (float)g_imgadv_cntx.cache_layer_width / g_imgadv_cntx.resized_img_width;
        if (g_imgadv_cntx.map.zoom_factor  < tmp_ratio)
        {
            g_imgadv_cntx.map.zoom_factor  = tmp_ratio;
            g_imgadv_cntx.is_width_dominate = FALSE;
        }
    }


    if ( (g_imgadv_cntx.resized_img_width * g_imgadv_cntx.map.zoom_factor > g_imgadv_cntx.image_width) ||
         (g_imgadv_cntx.resized_img_height * g_imgadv_cntx.map.zoom_factor > g_imgadv_cntx.image_height))
    {
        g_imgadv_cntx.map.is_zoomin_able = FALSE;
        return FALSE;
    }
    
    old_wnd_width = g_imgadv_cntx.map.wnd_width;
    old_wnd_height = g_imgadv_cntx.map.wnd_height;
    old_wnd_offset_x = g_imgadv_cntx.map.wnd_offset_x;
    old_wnd_offset_y = g_imgadv_cntx.map.wnd_offset_y;    
    old_resized_width = g_imgadv_cntx.resized_img_width;
    old_resized_height = g_imgadv_cntx.resized_img_height; 
    old_ratio = g_imgadv_cntx.map.ratio_map_to_resized_image;
    
    if (g_imgadv_cntx.is_width_dominate == TRUE)
    {
        g_imgadv_cntx.map.wnd_width = (g_imgadv_cntx.map.wnd_width / g_imgadv_cntx.map.zoom_factor + 0.5);
        g_imgadv_cntx.map.wnd_height = (g_imgadv_cntx.map.wnd_width / g_imgadv_cntx.map.ratio_width_to_height + 0.5);
    }
    else
    {
        g_imgadv_cntx.map.wnd_height = (g_imgadv_cntx.map.wnd_height / g_imgadv_cntx.map.zoom_factor + 0.5);
        g_imgadv_cntx.map.wnd_width = (g_imgadv_cntx.map.wnd_height * g_imgadv_cntx.map.ratio_width_to_height + 0.5);
    }

    /************************************************
     *
     *  check if new wnd_width/wnd_height > old ones
     *  prevent calculate clip error 
     *
     ************************************************/
    if (old_wnd_width < g_imgadv_cntx.map.wnd_width)
        g_imgadv_cntx.map.wnd_width = old_wnd_width;

    if (old_wnd_height < g_imgadv_cntx.map.wnd_height)
        g_imgadv_cntx.map.wnd_height = old_wnd_height;
    
    g_imgadv_cntx.map.wnd_offset_x = g_imgadv_cntx.map.wnd_offset_x + ((old_wnd_width - g_imgadv_cntx.map.wnd_width)>>1);
    g_imgadv_cntx.map.wnd_offset_y = g_imgadv_cntx.map.wnd_offset_y + ((old_wnd_height - g_imgadv_cntx.map.wnd_height)>>1);

    g_imgadv_cntx.map.zoom_factor_cnt++; 

    g_imgadv_cntx.resized_img_width= ((float)(g_imgadv_cntx.map.width * g_imgadv_cntx.cache_layer_width / g_imgadv_cntx.map.wnd_width))+0.5;
    g_imgadv_cntx.resized_img_height = ((float)(g_imgadv_cntx.map.height * g_imgadv_cntx.cache_layer_height / g_imgadv_cntx.map.wnd_height))+0.5;

    g_imgadv_cntx.map.ratio_map_to_resized_image = 
                (float)g_imgadv_cntx.resized_img_width/g_imgadv_cntx.map.width;            


    if (g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_SVG ||
         g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_SVG_FILE )
        gdi_anim_stop_all_by_layer(g_imgadv_cntx.cache_layer_handle);

    mmi_imgadv_extract_image_to_cache_layer();

    g_imgadv_cntx.map.zoom_factor  = 1.25;

    if (g_imgadv_cntx.result >= MMI_IMGADV_OK)
    {
        mmi_imgadv_draw_map();
        mmi_imgadv_draw_osd();
        gdi_lcd_repaint_all();
        mmi_imgadv_init_key_handler();    
    }
    else
    {
        g_imgadv_cntx.map.wnd_width = old_wnd_width;
        g_imgadv_cntx.map.wnd_height = old_wnd_height;
        g_imgadv_cntx.map.wnd_offset_x = old_wnd_offset_x;
        g_imgadv_cntx.map.wnd_offset_y = old_wnd_offset_y;
        g_imgadv_cntx.resized_img_width = old_resized_width;
        g_imgadv_cntx.resized_img_height = old_resized_height; 
        g_imgadv_cntx.map.ratio_map_to_resized_image = old_ratio;       
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_reenter
 * DESCRIPTION
 *  This function is called to draw the best fit image on the screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_reenter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgadv_cntx.rsk.is_press = FALSE;
    mmi_imgadv_draw_osd();
    gdi_lcd_repaint_all();
    g_imgadv_cntx.map.zoom_factor_cnt = 1;
    mmi_imgadv_zoomout();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_zoomout
 * DESCRIPTION
 *  zoom out function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static BOOL mmi_imgadv_zoomout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 old_wnd_width;
    S32 old_wnd_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "*---[IMAGEVIEWER.c] zoomout()");
  
    if (g_imgadv_cntx.map.zoom_factor_cnt == 0)
        return FALSE;
    else 
        g_imgadv_cntx.map.is_zoomin_able = TRUE;
    

#if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
    gdi_image_nb_stop_all();
#endif

    old_wnd_width = g_imgadv_cntx.map.wnd_width;
    old_wnd_height = g_imgadv_cntx.map.wnd_height;

    if (g_imgadv_cntx.map.zoom_factor_cnt == 1)
    {
        mmi_imgadv_init_map_box();

        /* due to init map will reset it to FALSE */
        g_imgadv_cntx.map.is_zoomin_able = TRUE;

        mmi_imgadv_init_key_handler();

        mmi_imgadv_draw_osd();
        
        /* initialize resized_img_width/resized_img_height */
        {
            float tmp_width = (float)g_imgadv_cntx.image_width / g_imgadv_cntx.cache_layer_width;
            float tmp_height = (float)g_imgadv_cntx.image_height / g_imgadv_cntx.cache_layer_height;

            if (tmp_width == tmp_height)
            {
                g_imgadv_cntx.is_width_dominate = TRUE;
                g_imgadv_cntx.resized_img_width = g_imgadv_cntx.cache_layer_width;
                g_imgadv_cntx.resized_img_height = g_imgadv_cntx.cache_layer_height;
                g_imgadv_cntx.map.ratio_map_to_resized_image = 
                g_imgadv_cntx.map.ratio_map_to_thumbnail = 
                    (float)g_imgadv_cntx.resized_img_height/ g_imgadv_cntx.map.height;            
            }
            else if (tmp_width > tmp_height)
            {
                g_imgadv_cntx.is_width_dominate = FALSE;
                g_imgadv_cntx.resized_img_height = g_imgadv_cntx.image_height / tmp_width + 0.5;
                g_imgadv_cntx.resized_img_width = g_imgadv_cntx.cache_layer_width;
                g_imgadv_cntx.map.ratio_map_to_resized_image = 
                g_imgadv_cntx.map.ratio_map_to_thumbnail = 
                    (float)g_imgadv_cntx.resized_img_width/g_imgadv_cntx.map.width;            
            }
            else
            {
                g_imgadv_cntx.is_width_dominate = TRUE;
                g_imgadv_cntx.resized_img_width = g_imgadv_cntx.image_width / tmp_height + 0.5;
                g_imgadv_cntx.resized_img_height = g_imgadv_cntx.cache_layer_height;
                g_imgadv_cntx.map.ratio_map_to_resized_image = 
                g_imgadv_cntx.map.ratio_map_to_thumbnail = 
                    (float)g_imgadv_cntx.resized_img_height/g_imgadv_cntx.map.height;
            }
        }
    }
    else
    {
        if (g_imgadv_cntx.is_width_dominate == TRUE)
        {
            g_imgadv_cntx.map.wnd_width = (g_imgadv_cntx.map.wnd_width * g_imgadv_cntx.map.zoom_factor + 0.5);
            g_imgadv_cntx.map.wnd_height = (g_imgadv_cntx.map.wnd_width / g_imgadv_cntx.map.ratio_width_to_height + 0.5);
        }
        else
        {
            g_imgadv_cntx.map.wnd_height = (g_imgadv_cntx.map.wnd_height * g_imgadv_cntx.map.zoom_factor + 0.5);
            g_imgadv_cntx.map.wnd_width = (g_imgadv_cntx.map.wnd_height * g_imgadv_cntx.map.ratio_width_to_height + 0.5);
        }

        /***************************************************
         *
         *  check if new wnd_width/wnd_height > default one.
         *  prevent calculate clip error 
         *
         ***************************************************/
        if (g_imgadv_cntx.map.width < g_imgadv_cntx.map.wnd_width)
            g_imgadv_cntx.map.wnd_width = g_imgadv_cntx.map.width;

        if (g_imgadv_cntx.map.height < g_imgadv_cntx.map.wnd_height)
            g_imgadv_cntx.map.wnd_height = g_imgadv_cntx.map.height;

        
        g_imgadv_cntx.map.wnd_offset_x = g_imgadv_cntx.map.wnd_offset_x - ((g_imgadv_cntx.map.wnd_width - old_wnd_width)>>1);
        g_imgadv_cntx.map.wnd_offset_y = g_imgadv_cntx.map.wnd_offset_y - ((g_imgadv_cntx.map.wnd_height - old_wnd_height)>>1);

        if (g_imgadv_cntx.map.wnd_offset_x < 0)
            g_imgadv_cntx.map.wnd_offset_x = 0;
        else if (g_imgadv_cntx.map.wnd_offset_x + g_imgadv_cntx.map.wnd_width > g_imgadv_cntx.map.width)
            g_imgadv_cntx.map.wnd_offset_x = g_imgadv_cntx.map.width - g_imgadv_cntx.map.wnd_width ;

        if (g_imgadv_cntx.map.wnd_offset_y < 0)
            g_imgadv_cntx.map.wnd_offset_y = 0;
        else if (g_imgadv_cntx.map.wnd_offset_y + g_imgadv_cntx.map.wnd_height > g_imgadv_cntx.map.height)
            g_imgadv_cntx.map.wnd_offset_y = g_imgadv_cntx.map.height - g_imgadv_cntx.map.wnd_height ;

        g_imgadv_cntx.resized_img_width= ((float)(g_imgadv_cntx.map.width * g_imgadv_cntx.cache_layer_width / g_imgadv_cntx.map.wnd_width))+0.5;
        g_imgadv_cntx.resized_img_height = ((float)(g_imgadv_cntx.map.height * g_imgadv_cntx.cache_layer_height / g_imgadv_cntx.map.wnd_height))+0.5;

        g_imgadv_cntx.map.ratio_map_to_resized_image = 
                (float)g_imgadv_cntx.resized_img_width/g_imgadv_cntx.map.width;            

        g_imgadv_cntx.map.zoom_factor_cnt--;
    }    

    if (g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_SVG ||
         g_imgadv_cntx.image_type == GDI_IMAGE_TYPE_SVG_FILE )
        gdi_anim_stop_all_by_layer(g_imgadv_cntx.cache_layer_handle);

    mmi_imgadv_draw_map();
    mmi_imgadv_extract_image_to_cache_layer();

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_next_image_press
 * DESCRIPTION
 *  This function is called to show next image.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgadv_next_image_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_imgadv_extract_image_to_cache_layer);
    g_imgadv_cntx.active_osd_layout_ptr->rarrow.is_press = TRUE;
    mmi_imgadv_draw_osd();
    gdi_lcd_repaint_all();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_previous_image_press
 * DESCRIPTION
 *  This function is called to show previous image.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgadv_previous_image_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_imgadv_extract_image_to_cache_layer);
    g_imgadv_cntx.active_osd_layout_ptr->larrow.is_press = TRUE;
    mmi_imgadv_draw_osd();
    gdi_lcd_repaint_all();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_next_image
 * DESCRIPTION
 *  press down in view detail screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgadv_next_image_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;
    S32 cur_index;
    FMGR_FILE_INFO_STRUCT file_info;
    S32 counter;
    S32 file_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgadv_cntx.active_osd_layout_ptr->rarrow.is_press = FALSE;
    mmi_imgadv_draw_osd();
    gdi_lcd_repaint_all();

    #if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
        gdi_image_nb_stop_all();
    #endif

    #ifdef __DRM_SUPPORT__
        mmi_imgadv_pause_drm_consume_if_need();
    #endif

    /* exit and clear previous screen for history - then enter again */
    cur_index = mmi_fmgr_kernel_get_cur_idx();
    file_count = mmi_fmgr_kernel_get_file_count();
    counter = 0;

    if (file_count > 1)
    {
        do
        {
            mmi_fmgr_kernel_move_selection_down();
            index = mmi_fmgr_kernel_get_cur_idx();
            mmi_fmgr_kernel_get_file_info(index, &file_info);

            counter++;

            if (!(file_info.attribute & FS_ATTR_DIR))
            {
                EntryNewScreen(SCR_ID_IMGVIEW_VIEW, NULL, NULL, NULL);
                DeleteScreenIfPresent(SCR_ID_IMGVIEW_VIEW);
                g_imgadv_cntx.is_err_displayed = FALSE;
                mmi_imgadv_entry_app_screen();
                return;
            }

            if (counter >= (file_count - 1))
            {
                return;
            }

        } while (1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_previous_image
 * DESCRIPTION
 *  press up in view detail screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgadv_previous_image_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;
    S32 cur_index;
    FMGR_FILE_INFO_STRUCT file_info;
    S32 counter;
    S32 file_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgadv_cntx.active_osd_layout_ptr->larrow.is_press = FALSE;
    mmi_imgadv_draw_osd();
    gdi_lcd_repaint_all();

    #if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
        gdi_image_nb_stop_all();
    #endif

    #ifdef __DRM_SUPPORT__
        mmi_imgadv_pause_drm_consume_if_need();
    #endif

    /* exit and clear previous screen for history - then enter again */
    cur_index = mmi_fmgr_kernel_get_cur_idx();
    file_count = mmi_fmgr_kernel_get_file_count();
    counter = 0;

    if (file_count > 1)
    {
        do
        {
            mmi_fmgr_kernel_move_selection_up();
            index = mmi_fmgr_kernel_get_cur_idx();
            mmi_fmgr_kernel_get_file_info(index, &file_info);

            counter++;

            if (!(file_info.attribute & FS_ATTR_DIR))
            {
                EntryNewScreen(SCR_ID_IMGVIEW_VIEW, NULL, NULL, NULL);
                DeleteScreenIfPresent(SCR_ID_IMGVIEW_VIEW);
                g_imgadv_cntx.is_err_displayed = FALSE;
                mmi_imgadv_entry_app_screen();
                return;
            }

            if (counter >= (file_count - 1))
            {
                return;
            }

        } while (1);
    }

}

#if defined(__MMI_IMGADV_NONBLOCKING_DECODE__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imgadv_decode_done_callback
 * DESCRIPTION
 *  decode done callback function called by gdi
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgadv_decode_done_callback(GDI_RESULT result, gdi_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetActiveScreenId()!=SCR_ID_IMGVIEW_VIEW)
    return;
    
//    ASSERT(handle == g_imgadv_cntx.nb_handle);

    if (g_imgadv_cntx.is_initialized == FALSE)
    {
        mmi_imgadv_init_key_handler();
        mmi_imgadv_init_default_touch_and_key_handler();
        g_imgadv_cntx.is_initialized = TRUE;
    }
    
    #ifdef __DRM_SUPPORT__
    if (result == GDI_SUCCEED && g_imgadv_cntx.is_resume != TRUE && g_imgadv_cntx.drm_handle != NULL)
    {
        g_imgadv_cntx.drm_id = 
            DRM_consume_rights(g_imgadv_cntx.drm_handle, DRM_PERMISSION_DISPLAY, mmi_imgadv_drm_callback_hdlr);
        g_imgadv_cntx.drm_state = IMGADV_DRM_STATE_CONSUME;

        DRM_close_file(g_imgadv_cntx.drm_handle);
        g_imgadv_cntx.drm_handle = NULL;
    }
    #endif

    if (result != GDI_SUCCEED && (( g_imgadv_cntx.is_err_displayed == TRUE) && g_imgadv_cntx.result != MMI_IMGADV_NON_FIRST_TIME_DECODE_ERR))
    {
        g_imgadv_cntx.result = MMI_IMGADV_ERROR;
        gdi_layer_push_and_set_active(g_imgadv_cntx.cache_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
        return;
    }
    else if (result != GDI_SUCCEED)
    {
        gdi_layer_push_and_set_active(g_imgadv_cntx.cache_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
        gdi_lcd_repaint_all();

        if (g_imgadv_cntx.map.zoom_factor_cnt == 0)
        {
            if (result == GDI_JPEG_ERR_IMAGE_TOO_LARGE)
            {
                g_imgadv_cntx.err_str_ptr = GetString(STR_ID_FMGR_FILE_LIMIT_IMAGE_TOO_LARGE);
            }
            else if (result== GDI_JPEG_ERR_FILE_FORMAT_WRONG)
            {
                g_imgadv_cntx.err_str_ptr = GetString(STR_ID_FMGR_INVALID_IMAGE_FORMAT);
            }
            else if (result== GDI_JPEG_ERR_DECODE_TIME_OUT)
            {
                g_imgadv_cntx.err_str_ptr = GetString(STR_ID_FMGR_SYSTEM_BUSY_TO_DECODE);
            }
            else
            {
                g_imgadv_cntx.err_str_ptr = GetString(STR_ID_FMGR_INVALID_IMAGE_FORMAT);
            }
        }
        else
        {
            if (result== GDI_JPEG_ERR_IMAGE_TOO_LARGE)
            {
                g_imgadv_cntx.err_str_ptr = GetString(STR_ID_FMGR_FILE_LIMIT_IMAGE_TOO_LARGE);
            }
            else if (result== GDI_JPEG_ERR_FILE_FORMAT_WRONG)
            {
                g_imgadv_cntx.err_str_ptr = GetString(STR_ID_FMGR_INVALID_IMAGE_FORMAT);
            }
            else
                g_imgadv_cntx.err_str_ptr = GetString(STR_ID_FMGR_SYSTEM_BUSY_TO_DECODE);
        }

        if (g_imgadv_cntx.map.zoom_factor_cnt+1 <= 1)
        {
            g_imgadv_cntx.map.zoom_factor_cnt = 0;
            g_imgadv_cntx.result = MMI_IMGADV_FIRST_TIME_DECODE_ERR;        
        }
        else
        {
            g_imgadv_cntx.result = MMI_IMGADV_NON_FIRST_TIME_DECODE_ERR;  
            g_imgadv_cntx.map.zoom_factor_cnt--;
            g_imgadv_cntx.map.max_zoom_factor = g_imgadv_cntx.map.zoom_factor_cnt;
        }
        mmi_imgadv_display_error();
        return;
    }
    else
    {
        gdi_lcd_repaint_all();
    }
}
#endif


#endif /* __MMI_IMAGEVIEWER_ADV__ */
#endif /* __MMI_IMAGE_VIEWER__ */ 

