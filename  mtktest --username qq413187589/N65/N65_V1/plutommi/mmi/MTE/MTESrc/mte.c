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
 *  mte.c
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  MoDIS Theme Editor, MoDIS only.
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

#ifndef __MTK_TARGET__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#include "stdC.h"
#include "L4Dr1.h"
#include "PixtelDataTypes.h"
#include "GlobalDefs.h"
#include "EventsGprot.h"
#include "CustDataProts.h"
#include "CustMenuRes.h"
#include "HistoryGprot.h"
#include "FrameworkStruct.h"
#include "TimerEvents.h"
#include "EventsDef.h"
#include "Unicodexdcl.h"
#include "gui_setting.h"
#include "gui_themes.h"
#include "wgui.h"
#include "wgui_categories.h"
#include "wgui_categories_inputs.h"
#include "wgui_categories_popup.h"
#include "kal_release.h"
#include "osc_type.h"
#include "osc_func.h"
#include "gdi_include.h"
#include "mmiapi.h"
#include "ABMLoader.h"

/* example screens */
#include "SettingGenum.h"
#include "IdleAppDef.h"
#include "PhoneSetup.h"
#include "SettingResDef.h"

#include "mteGprot.h"
#include "mte.h"
#include "mte_img_resource.h"

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
static U8 *g_mmi_mte_image_folder_path = NULL;
static S32  g_mmi_mte_language_id = MMI_MTE_LANG_ENGLISH;
static mmi_mte_state_enum g_mmi_mte_state = MMI_MTE_STATE_INACTIVE;
static U8 g_mmi_mte_abm_exe_path[MMI_MTE_MAX_PATH_LEN];
static U8 g_mmi_mte_example_screen_buffer[MMI_MTE_EXAMPLE_SCREEN_BUF_SIZE];

static S32 g_mmi_mte_example_screen_tab_num = 0;

static const mmi_mte_font_struct g_mmi_mte_font[MMI_MTE_FONT_TYPE_NUM] =
{
    MMI_MTE_FONT_DECLARE(MMI_MTE_FONT_DEFAULT),
    MMI_MTE_FONT_DECLARE(MMI_MTE_FONT_UI_DEFAULT),
    MMI_MTE_FONT_DECLARE(MMI_MTE_FONT_SMALL),
    MMI_MTE_FONT_DECLARE(MMI_MTE_FONT_MEDIUM),     
    MMI_MTE_FONT_DECLARE(MMI_MTE_FONT_LARGE),    
    MMI_MTE_FONT_DECLARE(MMI_MTE_FONT_VKBD),     
    MMI_MTE_FONT_DECLARE(MMI_MTE_FONT_SUBLCD),
    MMI_MTE_FONT_DECLARE(MMI_MTE_FONT_DIALER_F1),
    MMI_MTE_FONT_DECLARE(MMI_MTE_FONT_DIALER_F2),
    MMI_MTE_FONT_DECLARE(MMI_MTE_FONT_MEDIUM_BOLD),
    MMI_MTE_FONT_DECLARE(MMI_MTE_FONT_NEW_FONT1),    
    MMI_MTE_FONT_DECLARE(MMI_MTE_FONT_NEW_FONT2),    
    MMI_MTE_FONT_DECLARE(MMI_MTE_FONT_NEW_FONT3),    
    MMI_MTE_FONT_DECLARE(MMI_MTE_FONT_NEW_FONT4)   
};

static void *g_mmi_mte_system_variable[MMI_MTE_SYSTEM_VALUE_NUM] = {NULL};

/*
 * Image related
 */
static gdi_handle   g_mmi_mte_anim_handle = GDI_NULL_HANDLE;
/* working buffer for the image resource */
static U32 g_mmi_mte_image_buffer[(MMI_MTE_MAX_IMAGE_RESOURCE_SIZE + 8) / 4];
static gdi_handle g_mmi_mte_image_layer_handle = GDI_NULL_HANDLE;
/* output image layer */
static U32 g_mmi_mte_image_layer_buffer[MMI_MTE_MAX_IMAGE_RESOURCE_SIZE];
static U8 *g_mmi_mte_output_buffer;
static S32 g_mmi_mte_output_image_width, g_mmi_mte_output_image_height;
static void (*g_mmi_mte_image_frame_finish_callback)(char *output_buffer, int output_image_width, int output_image_height);

/* 
 * MTE RPC 
 */
static int *g_mte_rpc_msg;  /* RPC message */
static int g_mmi_mte_api_index;
static int mmi_mte_ret_value;
static void (*mte_api_finish_callback)(void);
static void mmi_mte_rpc_handler(void *msg);
static void (*g_mmi_mte_switch_screen_callback)(void);

/*
 * Static functions
 */
static mmi_mte_resource_map_struct g_mmi_mte_res_map_table[MMI_MTE_SYSTEM_IMAGE_RESOURCE_NUM];
static S32 g_mmi_mte_resource_mapping_table_count = 0;
static void mmi_mte_free_res_mapping_table(void);
static U32 mmi_mte_get_image_resource_size(U8 *res_ptr);
static MMI_BOOL mmi_mte_is_ems_image(S8 *filename);

static void mte_to_mmi_hisr(void);

static void mmi_mte_dummy_function(void);

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
/*
 * System theme
 */
extern S32 mtk_n_MMI_themes;
#ifndef __MMI_THEMES_V2_SUPPORT__    
extern const MMI_theme *mtk_MMI_themes[];
#else /* __MMI_THEMES_V2_SUPPORT__ */
extern const theme_details_struct mtk_MMI_themes[];
#endif /* __MMI_THEMES_V2_SUPPORT__ */
extern U8* MMI_theme_names[];

extern const U16 gIndexIconsImageList[];

/*
 * External global functions
 */
extern UI_filled_area* dm_get_current_scr_bg_filler(void);

/* 
 * MMI
 */
extern MMI_BOOL MMI_softkey_filler_disabled;

#ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
/* techno bar clock */
extern U8 g_clock_type;
#endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */ 

extern FuncPtr Cat165TimerExpireCallBack;

/***************************************************************************** 
 * Local Function
 *****************************************************************************/

/* 
 * Memory allocation
 *
 * Disable OSCAR scheduler for safety.
 */
 
/*****************************************************************************
 * FUNCTION
 *  MTE_ALLOC
 * DESCRIPTION
 *  Allocates 4-byte aligned memory.
 * PARAMETERS
 *  alloc_size      [IN]    memory allocation size
 * RETURNS
 *  Memory pointer
 *****************************************************************************/
static void *MTE_ALLOC(U32 alloc_size)            
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8     alloc_mem_ptr;
    U32     *aligned_mem_ptr;
    U32     aligned_size;
    U32     padding_bytes;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     * The real address is stored in front of the aligned memory buffer.
     *
     * 4-BYTE PADDING + 4-BYTE REAL ADRRESS + MEMORY IN SIZE 
     */
    /* Do not accept zero size. This is different to the C malloc() behavior. */
    if (alloc_size == 0)
    {
        return NULL;
    }

    /* add 4-byte real address and preserve another 4-byte for padding */
    aligned_size = alloc_size + 4 + 4;

    OSC_Sys_Schedule_Enable(0);
    alloc_mem_ptr = (PU8)malloc(aligned_size);    
    OSC_Sys_Schedule_Enable(1);    

    if (alloc_mem_ptr)
    {
        padding_bytes = 4 - ((U32)alloc_mem_ptr & 0x3);
        aligned_mem_ptr = (U32*)(alloc_mem_ptr + padding_bytes);
        aligned_mem_ptr[0] = (U32)alloc_mem_ptr;
        
        return (aligned_mem_ptr + 1);
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  MTE_FREE
 * DESCRIPTION
 *  Frees 4-byte aligned memory.
 * PARAMETERS
 *  mem       [IN]  allocated memory pointer
 * RETURNS
 *  void
 *****************************************************************************/
static void MTE_FREE(void *mem)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32     *alloc_mem_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mem == NULL)
    {
        return;
    }

    alloc_mem_ptr = (U32*)mem;
    alloc_mem_ptr = (U32*)alloc_mem_ptr[-1];

    OSC_Sys_Schedule_Enable(0);
    free(alloc_mem_ptr);
    OSC_Sys_Schedule_Enable(1);        
}


/*
 * Image
 */
 
/*****************************************************************************
 * FUNCTION
 *  mmi_mte_translate_image_type_from_mte_to_gdi
 * DESCRIPTION
 *  Converts the MTE image type to the GDI image type.
 * PARAMETERS
 *  mte_image_type  [IN]   MTE input image type
 * RETURNS
 *  GDI image type
 *****************************************************************************/
static U8 mmi_mte_translate_image_type_from_mte_to_gdi(mmi_mte_image_enum mte_image_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 gdi_image_type;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mte_image_type)
    {
        case MMI_MTE_IMAGE_GIF:
            gdi_image_type = GDI_IMAGE_TYPE_GIF;
            break;

        case MMI_MTE_IMAGE_JPG:
            gdi_image_type = GDI_IMAGE_TYPE_JPG;
            break;

        case MMI_MTE_IMAGE_BMP:
            gdi_image_type = GDI_IMAGE_TYPE_BMP;
            break;

        case MMI_MTE_IMAGE_PNG:
            gdi_image_type = GDI_IMAGE_TYPE_PNG;
            break;

        case MMI_MTE_IMAGE_BMP_TO_ABM:
        case MMI_MTE_IMAGE_PNG_TO_ABM:
            gdi_image_type = GDI_IMAGE_TYPE_ABM;
            break;

        default:
            return GDI_IMAGE_TYPE_INVALID;
    }

    return gdi_image_type;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_translate_image_type_from_gdi_to_mte
 * DESCRIPTION
 *  Converts the GDI image type to the MTE image type.
 * PARAMETERS
 *  gdi_image_type      [IN]    GDI image type
 * RETURNS
 *  MTE image type
 *****************************************************************************/
static mmi_mte_image_enum mmi_mte_translate_image_type_from_gdi_to_mte(U8 gdi_image_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 mte_image_type;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (gdi_image_type)
    {
        case GDI_IMAGE_TYPE_GIF:
            mte_image_type = MMI_MTE_IMAGE_GIF;
            break;

        case GDI_IMAGE_TYPE_JPG:
            mte_image_type = MMI_MTE_IMAGE_JPG;
            break;

        case GDI_IMAGE_TYPE_BMP:
            mte_image_type = MMI_MTE_IMAGE_BMP;
            break;

        case GDI_IMAGE_TYPE_PNG:
            mte_image_type = MMI_MTE_IMAGE_PNG;
            break;

        case GDI_IMAGE_TYPE_ABM:
            mte_image_type = MMI_MTE_IMAGE_BMP_TO_ABM;
            break;

        default:
            return MMI_MTE_IMAGE_NONE;
    }

    return mte_image_type;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_image_resource_info
 * DESCRIPTION
 *  Gets image resource information.
 * PARAMETERS
 *  img_res_ptr          [IN]   image resource pointer
 *  img_data_ptr         [OUT]  image data pointer
 *  mte_image_type       [OUT]  MTE image type
 *  width                [OUT]  width
 *  height               [OUT]  height
 *  size                 [OUT]  size
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mte_get_image_resource_info(char *img_res_ptr, char **img_data_ptr, mmi_mte_image_enum *mte_image_type, int *width, int *height, int *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 header = (PU8)img_res_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *img_data_ptr = header + 8;
    *mte_image_type = mmi_mte_translate_image_type_from_gdi_to_mte(header[0]);
    *size = (S32)mmi_mte_get_image_resource_size(header);
    *width = (header[7] << 4) | (header[6] >> 4);
    *height = ((header[6] & 0xF) << 8) | header[5];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_file_size
 * DESCRIPTION
 *  Get the file size.
 * PARAMETERS
 *  filename       [IN]     filename
 * RETURNS
 *  File size in bytes.
 *****************************************************************************/
static int mmi_mte_get_file_size(char *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE    *fp;
    S32     fpos, file_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fp = fopen(filename, "rb");   
    if (fp == NULL)
    {
        return 0;
    }
    
    /* save the current file position */
    fpos = ftell(fp);

    /* seek to the EOF */    
    fseek(fp, 0, SEEK_END);

    /* get file size */
    file_size = ftell(fp);

    fclose(fp);

    return file_size;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_filter_image_type
 * DESCRIPTION
 *  Changes the image type due to some constraints.
 * PARAMETERS
 *  image_type       [IN]   input image type
 *  is_full_screen   [IN]   is full screen
 * RETURNS
 *  Filtered image type.
 *****************************************************************************/
static unsigned int mmi_mte_filter_image_type(unsigned int image_type, MMI_BOOL is_full_screen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* discard unsupported image types */
#ifndef GDI_USING_JPEG
    image_type &= ~MMI_MTE_IMAGE_JPG;
#endif /* GDI_USING_JPEG */

    /* do not use PNG if alpha blending is not supported */
#ifndef __MMI_ALPHA_BLENDING__
    image_type &= ~MMI_MTE_IMAGE_PNG;
#endif /* __MMI_ALPHA_BLENDING__ */

    /* JPG is not allowed on 6205 and 6223. */
#if (defined(MT6223_SERIES) || defined(MT6205_SERIES))
    image_type &= ~MMI_MTE_IMAGE_JPG;
#endif /* (defined(MT6223_SERIES) || defined(MT6205_SERIES)) */

    /* GIF is not allowed on 6205, 6223, and 6225 for full screen images. */
#if (defined(MT6223_SERIES) || defined(MT6205_SERIES) || defined(MT6225_SERIES))
    if (is_full_screen == MMI_TRUE)
    {
        image_type &= ~MMI_MTE_IMAGE_GIF;
    }
#endif /* (defined(MT6223_SERIES) || defined(MT6205_SERIES) || defined(MT6225_SERIES)) */

    /* do not allow raw PNG, use ABM instead */
    if (image_type & MMI_MTE_IMAGE_PNG)
    {
        image_type &= ~MMI_MTE_IMAGE_PNG;
        image_type |= MMI_MTE_IMAGE_PNG_TO_ABM;
    }

    /* use ABM instead of BMP */
    if (image_type & MMI_MTE_IMAGE_BMP)
    {
        image_type &= ~MMI_MTE_IMAGE_BMP;
        image_type |= MMI_MTE_IMAGE_BMP_TO_ABM;
    }

    /* If there is no format available, use MMI_MTE_IMAGE_BMP_TO_ABM. */
    if (image_type == MMI_MTE_IMAGE_NONE)
    {
        // TODO: ASSERT here? */
        image_type = MMI_MTE_IMAGE_BMP_TO_ABM;
    }

    return image_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_make_resource_header
 * DESCRIPTION
 *  Make 8-byte MMI resource header
 * PARAMETERS
 *  header       [IN]   header buffer
 *  type         [IN]   GDI image type
 *  width        [IN]   image width
 *  height       [IN]   image height
 *  size         [IN]   image size
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_make_resource_header(U8 *header, U8 type, S32 width, S32 height, S32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    header[0] = type;
    header[1] = 1;  /* number of frames */
    header[2] = size & 0xFF;
    header[3] = (size >> 8) & 0xFF;
    header[4] = (size >> 16) & 0xFF;
    header[5] = height & 0xFF;
    header[6] = ((height >> 8) & 0xF) | ((width & 0xF) << 4);
    header[7] = (width >> 4) & 0xFF;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_theme_image_dimension
 * DESCRIPTION
 *  Get the dimension for an image theme component
 * PARAMETERS
 *  theme_component       [IN]      theme component strucuture
 *  lcd_dimension         [IN]      current LCD dimension
 *  width                 [OUT]     image width
 *  height                [OUT]     image height
 * RETURNS
 *  0: The dimension is undefined.
 *  1: The dimension is defined.
 *****************************************************************************/
static int mmi_mte_get_theme_image_dimension(mmi_mte_theme_component_struct *theme_component, mmi_mte_lcd_dimension_enum lcd_dimension, int *width, int *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *width = theme_component->internal_data.image_dimension[lcd_dimension][0];
    *height = theme_component->internal_data.image_dimension[lcd_dimension][1];
    
    if ((*width == 0) && (*height == 0))
    {
        return 0;
    } 
    else
    {
        return 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_convert_image_layer_to_32
 * DESCRIPTION
 *  Converts the image layer to the 32-bit ARGB output buffer.
 * PARAMETERS
 *  image_layer      [IN]   image layer handle
 *  out_buffer       [OUT]  32-bit output buffer
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_convert_image_layer_to_32(gdi_handle image_layer, U8* out_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32         width, height;
    S32         x, y;
    gdi_color   c;
    U32         a, r, g, b;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(image_layer);
    gdi_layer_get_dimension(&width, &height);

    for (y = 0; y < height; y++)
    {
        for (x = 0; x < width; x++)
        {
            c = gdi_act_get_pixel(x, y);
            gdi_act_color_to_rgb(&a, &r, &g, &b, c);
            *out_buffer++ = b;
            *out_buffer++ = g;
            *out_buffer++ = r;
            *out_buffer++ = a;
        }
    }

    gdi_layer_pop_and_restore_active();
}


/*
 * MTE RPC
 */

/*****************************************************************************
 * FUNCTION
 *  mmi_to_mte_isr
 * DESCRIPTION
 *  MMI to MTE finish notification ISR
 * PARAMETERS
 *  param1       [IN]   NOT USED
 * RETURNS
 *  NULL
 *****************************************************************************/
static void *mmi_to_mte_isr(void * param1, ...)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MTE_UNUSED_PARAMETER(param1);
    
    mte_api_finish_callback();

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mte_to_mmi_hisr
 * DESCRIPTION
 *  MTE to MMI RPC request HISR
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mte_to_mmi_hisr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int     *msg;
    static int msg_buf[16];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* copy arguments into local message buffer */
    msg = msg_buf;
    memcpy(msg, g_mte_rpc_msg, sizeof(int) * 16);

    /* send RPC request message to the MMI task */
    SEND_MESSAGE(MOD_MMI, MOD_MMI, 0, MMI_MTE_MESSAGE_ID, msg, NULL);    
}


/*****************************************************************************
 * FUNCTION
 *  mte_to_mmi_isr
 * DESCRIPTION
 *  MTE to MMI RPC request ISR
 * PARAMETERS
 *  param1       [IN]   NOT USED
 * RETURNS
 *  NULL
 *****************************************************************************/
static void *mte_to_mmi_isr(void * param1, ...)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_hisrid  hisr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MTE_UNUSED_PARAMETER(param1);
    
    hisr = kal_create_hisr("MTE_TO_MMI_HISR", 0, 1024, (kal_hisr_func_ptr)mte_to_mmi_hisr, 0);
    kal_activate_hisr(hisr);

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_rpc_handler
 * DESCRIPTION
 *  MMI message handler for MTE RPC.
 * PARAMETERS
 *  msg       [IN]  local message buffer
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_rpc_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int     *args, api_index;
    func_8_int_params_ptr  f8;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* turn on backlight */
    TurnOnBacklight(1);   

    args = (int *)msg;
    api_index = args[0];
    f8 = (func_8_int_params_ptr)g_mmi_mte_function_table[api_index];

    MTE_DEBUG("mmi_mte_rpc_handler RUN JOB %d\n", api_index);
    mmi_mte_ret_value = f8(args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8]);
  
    /* notify the MTE UI we're finished */
    MTE_DEBUG("mmi_mte_rpc_handler FINISH JOB\n");
    OSC_Activate_ISR(MTE_MMI_TO_MTE_ISR);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_rpc_invoker
 * DESCRIPTION
 *  Fills the RPC request structure.
 * PARAMETERS
 *  a0       [IN]   1st argument
 *  a1       [IN]   2nd argument
 *  a2       [IN]   3rd argument
 *  a3       [IN]   4th argument
 *  a4       [IN]   5th argument
 *  a5       [IN]   6th argument
 *  a6       [IN]   7th argument
 *  a7       [IN]   8th argument
 * RETURNS
 *  0
 *****************************************************************************/
static int mmi_mte_rpc_invoker(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    static int msg[16];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg[0] = g_mmi_mte_api_index;
    msg[1] = a0;
    msg[2] = a1;
    msg[3] = a2;
    msg[4] = a3;    
    msg[5] = a4;
    msg[6] = a5;
    msg[7] = a6;
    msg[8] = a7;    

    g_mte_rpc_msg = msg;

    MTE_DEBUG("mmi_mte_rpc_invoker REQUEST %d\n", msg[0]);
    
    OSC_Activate_ISR(MTE_MTE_TO_MMI_ISR);
   
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_register_finish_callback
 * DESCRIPTION
 *  Registers the finish callback function by the MTE UI. The callback function
 *  is used internally by MTE, which is actually SetEvent() to let the MTE UI 
 *  thread continue from WaitForSingleObject().
 * PARAMETERS
 *  finish_cb       [IN]    finish callback function
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_register_finish_callback(void (*finish_cb)(void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mte_api_finish_callback = finish_cb;
}


/*
 * Example Screen
 */

/*****************************************************************************
 * FUNCTION
 *  mmi_mte_is_component_in_dm_group
 * DESCRIPTION
 *  Checks if the component ID is in the specified DM group.
 * PARAMETERS
 *  component_id       [IN]     MTE theme component ID
 *  dm_group_id        [IN]     Draw Manager group ID
 * RETURNS
 *  0: No.
 *  1: Yes.
 *****************************************************************************/
static int mmi_mte_is_component_in_dm_group(int component_id, int dm_group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int g;
    const mmi_mte_control_set_group_struct  *control_set_group;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    control_set_group = g_mmi_mte_control_set_group + dm_group_id;

    for (g = 0; g < control_set_group->num; g++)
    {
        if (component_id == control_set_group->component_id[g])
        {
            return 1;
        }                    
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_append_control_set
 * DESCRIPTION
 *  Appends the source DM control set to the output control set.
 * PARAMETERS
 *  dst_control_set       [IN]      destination control set pointer
 *  control_set_num       [IN/OUT]  destination control set number
 *  src_control_set       [IN]      source control set pointer
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_append_control_set(U8 *dst_control_set, S32 *control_set_num, U8 *src_control_set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(dst_control_set + *control_set_num, src_control_set + 1, src_control_set[0]); 
    *control_set_num += src_control_set[0];    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_is_component_in_screen
 * DESCRIPTION
 *  Checks if the MTE theme component ID belongs to the screen or category.
 * PARAMETERS
 *  component_id       [IN]     MTE theme component ID
 *  screen_id          [IN]     screen id
 *  category_id        [IN]     category id
 * RETURNS
 *  0: No.
 *  1: Yes.
 *****************************************************************************/
static int mmi_mte_is_component_in_screen(S32 component_id, S32 screen_id, S32 category_id)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int filter_category_id, filter_screen_id;
    const mmi_mte_current_screen_filter_struct *filter;
    int filter_component_num;
    const int *filter_component_id;
    int i, f;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (f = 0; f < MMI_MTE_CURRENT_SCREEN_FILTER_NUM; f++)
    {
        filter = &g_mmi_mte_current_screen_filter[f];
        filter_category_id = filter->category_id ? filter->category_id : category_id;
        filter_screen_id = filter->screen_id ? filter->screen_id : screen_id;

        if ((filter_category_id == category_id) && (filter_screen_id == screen_id))
        {
            filter_component_num = filter->component_set.num;
            filter_component_id = filter->component_set.component_id;
            for (i = 0; i < filter_component_num; i++)
            {
                if ((filter_component_id[i] != MMI_MTE_INVALID_FILTER_COMPONENT) && (component_id == filter_component_id[i]))
                {
                    return 1;
                }
            }
        }
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_dummy_function
 * DESCRIPTION
 *  MTE Dummy function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_dummy_function(void)
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
 *  mmi_mte_example_screen_get_async_items
 * DESCRIPTION
 *  A fake get async menu item callback function for MTE example screens.
 * PARAMETERS
 *  start_index       [IN]  menu item start index
 *  menuData          [IN]  menu item data to be returned
 *  num_item          [IN]  number of items requested
 * RETURNS
 *  The number of returned menu items.
 *****************************************************************************/
static S32 mmi_mte_example_screen_get_async_items(S32 start_index, gui_iconlist_menu_item *menuData, S32 num_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < num_item; i++)
    {
        for (j = 0; j < FIXED_ICONLIST_MAX_TEXT_COLUMNS; j++)
        {
            menuData[i].item_list[j] = NULL;
        }

        for (j = 0; j < FIXED_ICONLIST_MAX_ICON_COLUMNS; j++)
        {
            menuData[i].image_list[j] = NULL;
        }

        menuData[i].item_list[0] = (UI_string_type)GetString(STR_GLOBAL_OK);
    }

    return num_item;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_example_screen_get_hint_items
 * DESCRIPTION
 *  A fake get async menu item hint callback function for MTE example screens.
 * PARAMETERS
 *  start_index       [IN]
 *  hint_array        [IN]
 * RETURNS
 *  1
 *****************************************************************************/
static S32 mmi_mte_example_screen_get_hint_items(S32 start_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hint_array[0] = (UI_string_type)GetString(STR_GLOBAL_OK);

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_example_screen_entry_screen_editor
 * DESCRIPTION
 *  Editor example screen entry function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_example_screen_entry_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MTE_EXAMPLE, NULL, mmi_mte_example_screen_entry_editor, NULL);

    mmi_ucs2cpy((S8*)g_mmi_mte_example_screen_buffer, GetString(STR_GLOBAL_OK));
    
    ShowCategory5Screen(
        STR_GLOBAL_EDIT,
        IMG_GLOBAL_OK,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        INPUT_TYPE_ALPHANUMERIC_UPPERCASE,
        (U8*)g_mmi_mte_example_screen_buffer,
        100,
        NULL);

    SetLeftSoftkeyFunction(mmi_mte_dummy_function, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_example_screen_entry_call
 * DESCRIPTION
 *  Calling example screen entry function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_example_screen_entry_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MTE_EXAMPLE, NULL, mmi_mte_example_screen_entry_call, NULL);
    
    ShowCategory18Screen(
        0,
        0,
        0,
        STR_GLOBAL_ABORT,
        0, 
        STR_GLOBAL_OK,
        (U8*)L"1234567890",
        0,
        0,
        IMG_GLOBAL_OK,
        NULL,
        FALSE,
        NULL);
    
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_example_screen_entry_rotated_popup
 * DESCRIPTION
 *  Rotated popup example screen entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_example_screen_entry_rotated_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MTE_EXAMPLE, NULL, mmi_mte_example_screen_entry_rotated_popup, NULL);

#ifdef __MMI_SCREEN_ROTATE__
    mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
#endif /* __MMI_SCREEN_ROTATE__ */

    ShowCategory65Screen((PU8)GetString(STR_GLOBAL_OK), IMG_GLOBAL_INFO, NULL);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_example_screen_entry_rotated_list
 * DESCRIPTION
 *  Rotated list example screen entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_example_screen_entry_rotated_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16     string_list[1] = {STR_GLOBAL_OK};
    U16     image_list[1] = {IMG_GLOBAL_L1};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MTE_EXAMPLE, NULL, mmi_mte_example_screen_entry_rotated_list, NULL);

#ifdef __MMI_SCREEN_ROTATE__
    mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
#endif /* __MMI_SCREEN_ROTATE__ */

    ShowCategory52Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        1,
        string_list,
        image_list,
        NULL,
        0,
        0,
        NULL);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_example_screen_entry_PIN
 * DESCRIPTION
 *  PIN example screen entry function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_example_screen_entry_PIN(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MTE_EXAMPLE, NULL, mmi_mte_example_screen_entry_PIN, NULL);

    mmi_ucs2cpy((S8*)g_mmi_mte_example_screen_buffer, (S8*)L"12");

    ShowCategory111Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        STR_SETTING_OLD_PIN,
        INPUT_TYPE_ALPHANUMERIC_PASSWORD,
        (U8*)g_mmi_mte_example_screen_buffer,
        4 + 1,
        NULL,
        NULL);

    SetLeftSoftkeyFunction(mmi_mte_dummy_function, KEY_EVENT_UP);
    SetCategory111RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_example_screen_entry_check_list
 * DESCRIPTION
 *  Check list example screen entry function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_example_screen_entry_check_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;
    U8 *itemlist[5];
    PU8 ItemListState = (PU8)g_mmi_mte_example_screen_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MTE_EXAMPLE, NULL, mmi_mte_example_screen_entry_check_list, NULL);

    for (index = 0; index < 5; index++)
    {
        itemlist[index] = (PU8)GetString(STR_GLOBAL_OK);
        ItemListState[index] = 0;        
    }

    ItemListState[0] = 1;
    ItemListState[2] = 1;
 
    ShowCategory12Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        index,
        itemlist,
        (U8*)ItemListState,
        0,
        NULL);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_example_screen_entry_multirow_list
 * DESCRIPTION
 *  Multirow list example screen entry function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_example_screen_entry_multirow_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MTE_EXAMPLE, NULL, mmi_mte_example_screen_entry_multirow_list, NULL);

    /* display shortcut */
    wgui_reset_disable_shortcut_display();

    ShowCategory85Screen(
        (PU8)GetString(STR_GLOBAL_OK),
        IMG_GLOBAL_OK,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MAX_SUB_MENUS,
        mmi_mte_example_screen_get_async_items,
        mmi_mte_example_screen_get_hint_items,
        0,
        IMG_GLOBAL_OK,
        IMG_GLOBAL_OK,
        NULL);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_example_screen_entry_tab
 * DESCRIPTION
 *  Tab list example screen entry function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_example_screen_entry_tab(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL    is_list_ready;
    tab_bar_item_type MMI_tab_bar_items[3];
    S32     i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MTE_EXAMPLE, NULL, mmi_mte_example_screen_entry_tab, NULL);

    for (i = 0; i < g_mmi_mte_example_screen_tab_num; i++)
    {
        MMI_tab_bar_items[i].icon = (PU8)GetImage(gIndexIconsImageList[i]);
        MMI_tab_bar_items[i].text = NULL;
        MMI_tab_bar_items[i].flags = 0;
    }

    ShowCategory425Screen(
        (PU8)GetString(STR_GLOBAL_OK),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        g_mmi_mte_example_screen_tab_num,
        0,
        MMI_tab_bar_items,
        MAX_SUB_MENUS,
        mmi_mte_example_screen_get_async_items,
        mmi_mte_example_screen_get_hint_items,
        (PU8)GetImage(IMG_GLOBAL_L1),
        (PU8)GetImage(IMG_GLOBAL_L1),
        0,
        NULL,
        &is_list_ready);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* blink tab 1 */
    if (g_mmi_mte_example_screen_tab_num)
    {
        Category425BlinkTab(1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_example_screen_entry_twoline_list
 * DESCRIPTION
 *  Two-line list example screen entry function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_example_screen_entry_twoline_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8     string_list[12];
    S32     i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    EntryNewScreen(SCR_ID_MTE_EXAMPLE, NULL, mmi_mte_example_screen_entry_twoline_list, NULL);
    
    for (i = 0; i < 12; i++)
    {
         string_list[i] = (PU8)GetString(STR_GLOBAL_OK);
    }
    
    ShowCategory354Screen(
        (PU8)GetString(STR_GLOBAL_OK),
        IMG_GLOBAL_OK,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        12,
        string_list,
        string_list,
        (PU16)gIndexIconsImageList,
        0,
        NULL);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_example_screen_entry_popup
 * DESCRIPTION
 *  Popup screen entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_example_screen_entry_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MTE_EXAMPLE, NULL, mmi_mte_example_screen_entry_popup, NULL);
    
    ShowCategory165Screen_ext(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        get_string(STR_GLOBAL_OK),
        IMG_GLOBAL_WARNING,
        10,
        NULL);
        
    SetCat165TimerExpireFunc(mmi_mte_dummy_function);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);        
}


#ifdef UI_SMALL_LIST_SCREEN

/*****************************************************************************
 * FUNCTION
 *  mmi_mte_example_screen_entry_small_list
 * DESCRIPTION
 *  Small list entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_example_screen_entry_small_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U16 str_list[6], icon_list[6];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MTE_EXAMPLE, NULL, mmi_mte_example_screen_entry_small_list, NULL);

    for (i = 0; i < 6; i++)
    {
        str_list[i] = STR_GLOBAL_1 + i;
        icon_list[i] = IMG_GLOBAL_L1 + i;
    }

    ShowCategory10Screen(
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        6,
        str_list,
        icon_list,
        0,
        NULL);
        
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);  
}


#endif /* UI_SMALL_LIST_SCREEN */


#ifdef __MMI_CASCADE_MENU__

/*****************************************************************************
 * FUNCTION
 *  mmi_mte_example_screen_entry_cascade_menu
 * DESCRIPTION
 *  Cascading menu entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_example_screen_entry_cascade_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MTE_EXAMPLE, NULL, mmi_mte_example_screen_entry_cascade_menu, NULL);

    // TODO: should use a test menu resource
    SetMenuItemDimmed(GetSeqItemId_Ext(MENU_SIM_OPTION_ID, 0), MMI_TRUE);

    DisplayCascadingMenu(MENU_SIM_OPTION_ID, NULL);
}


#endif /* __MMI_CASCADE_MENU__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_set_example_main_menu_style
 * DESCRIPTION
 *  Sets the main menu style.
 * PARAMETERS
 *  style       [IN]    main menu style
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_set_example_main_menu_style(U8 style)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MAINMENU_STYLE_CHANGE_EN__
    extern PHNSET_CNTX *g_phnset_cntx_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phnset_cntx_p->MenuStyle = style;
#endif /* __MMI_MAINMENU_STYLE_CHANGE_EN__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_example_screen_entry_symbol_picker
 * DESCRIPTION
 *  Symbol picker entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_example_screen_entry_symbol_picker(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MTE_EXAMPLE, NULL, mmi_mte_example_screen_entry_symbol_picker, NULL);
    
    /* The following code is from EntrySymbolPickerScreenFromMenuList(). */
    mmi_fe_enable_proprietary_symbol_display();
    PrepareSymbolTableAndShowCategory(NULL);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* 
     * clear LSK to prevent calling the symbol picker default LSK handler,
     * which will insert the selected symbol into the non-existence input box.
     */     
    ChangeLeftSoftkey(0, 0);             
    clear_left_softkey(); 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_search_dm_group_in_control_set
 * DESCRIPTION
 *  Searchs a DM group id in the control set.
 * PARAMETERS
 *  group_id                [IN]    DM group ID
 *  local_control_set       [IN]    control set
 *  control_set_num         [IN]    number of DM groups in the control set
 * RETURNS
 *  Index if found, otherwise -1.
 *****************************************************************************/
static S32 mmi_mte_search_dm_group_in_control_set(S32 group_id, U8 *local_control_set, S32 control_set_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < control_set_num; i++)
    {
        if (local_control_set[i] == group_id)
        {
            return i;
        }
    }

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_remove_dm_group_in_control_set
 * DESCRIPTION
 *  Removes a specified group id in the control set.
 * PARAMETERS
 *  group_id                [IN]    DM group ID
 *  local_control_set       [IN]    control set
 *  control_set_num         [IN]    number of DM groups in the control set
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_remove_dm_group_in_control_set(S32 group_id, U8 *local_control_set, S32 control_set_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = mmi_mte_search_dm_group_in_control_set(group_id, local_control_set, control_set_num);

    if (i == -1)
    {
        return;
    }

    /* remove the group by replacing it by a dummy ID */
    local_control_set[i] = DM_BASE_LAYER_START;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_remove_dm_group_in_filter
 * DESCRIPTION
 *  Remove discarded DM groups in the control set.
 * PARAMETERS
 *  screen_id               [IN]    current screen ID
 *  category_id             [IN]    current category ID
 *  local_control_set       [IN]    control set
 *  control_set_num         [IN]    number of DM groups in the control set
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_remove_dm_group_in_filter(S32 screen_id, S32 category_id, U8 *local_control_set, S32 control_set_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 filter_category_id, filter_screen_id;
    const mmi_mte_current_screen_filter_struct *filter;
    S32 discard_num;
    const int *discard_component_id;
    S32 i, j, f;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (f = 0; f < MMI_MTE_CURRENT_SCREEN_FILTER_NUM; f++)
    {
        filter = &g_mmi_mte_current_screen_filter[f];
        filter_category_id = filter->category_id ? filter->category_id : category_id;
        filter_screen_id = filter->screen_id ? filter->screen_id : screen_id;

        if ((filter_category_id == category_id) && (filter_screen_id == screen_id))
        {
            discard_num = filter->discard_dm.num;
            discard_component_id = filter->discard_dm.dm_group_id;
            for (i = 0; i < discard_num; i++)
            {
                mmi_mte_remove_dm_group_in_control_set(discard_component_id[i], local_control_set, control_set_num); 
            }
        }
    }
}


/*
 * Image Resource Replacement
 */

/*****************************************************************************
 * FUNCTION
 *  mmi_mte_search_resource_mapping_table_by_id
 * DESCRIPTION
 *  Get the index in the resource mapping table by a resource ID.
 * PARAMETERS
 *  id       [IN]   image resource ID
 * RETURNS
 *  -1: Not found.
 *  Others: Index.
 *****************************************************************************/
static int mmi_mte_search_resource_mapping_table_by_id(U32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_mmi_mte_resource_mapping_table_count; i++)
    {
        if (g_mmi_mte_res_map_table[i].id == id)
        {
            return i;
        }
    }

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_image_resource_size
 * DESCRIPTION
 *  Get the image resource size.
 * PARAMETERS
 *  res_ptr       [IN]  MMI image resource pointer
 * RETURNS
 *  Image resource size. (not including the 8-byte resource header)
 *****************************************************************************/
static U32 mmi_mte_get_image_resource_size(U8 *res_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return res_ptr[2] | (res_ptr[3] << 8) | (res_ptr[4] << 16);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_free_res_mapping_table
 * DESCRIPTION
 *  Free the resource mapping table.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_free_res_mapping_table(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_mmi_mte_resource_mapping_table_count; i++)
    {
        if (g_mmi_mte_res_map_table[i].buf)
        {
            MTE_FREE(g_mmi_mte_res_map_table[i].buf);
            g_mmi_mte_res_map_table[i].buf = NULL;
        }
    }

    g_mmi_mte_resource_mapping_table_count = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_allocate_image_buffer
 * DESCRIPTION
 *  Allocates the image buffer with the optional initialization data. 
 * PARAMETERS
 *  size            [IN]    size in bytes
 *  init_data       [IN]    initialization data
 * RETURNS
 *  Allocated memory pointer.
 *****************************************************************************/
static U8 *mmi_mte_allocate_image_buffer(U32 size, U8 *init_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8*     alloc_buf;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((alloc_buf = (U8*)MTE_ALLOC(size)) == NULL)
    {
        return NULL;
    }
    
    if (init_data)
    {
        memcpy(alloc_buf, init_data, size);
    }

    return alloc_buf;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_read_file_into_buffer
 * DESCRIPTION
 *  Read a file into the memory
 * PARAMETERS
 *  filename         [IN]   filename
 *  buffer           [IN]   buffer pointer
 *  buffer_len       [IN]   buffer size
 *  read_bytes       [OUT]  file size
 * RETURNS
 *  0: Success.
 *  1: Error.
 *****************************************************************************/
static int mmi_mte_read_file_into_buffer(S8 *filename, U8 *buffer, S32 buffer_len, S32 *read_bytes)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE    *fp;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        return 1;
    }

    /* The 8-byte header space is already reserved in the buffer. */
    *read_bytes = fread(buffer, 1, buffer_len, fp);
    
    fclose(fp);  

    /* error out if the file is not properly loaded into the buffer */
    if ((*read_bytes == 0) || (mmi_mte_get_file_size(filename) != *read_bytes))
    {
        return 1;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_is_file_exist
 * DESCRIPTION
 *  Checks if a file exists.
 * PARAMETERS
 *  file_path       [IN]    file path
 * RETURNS
 *  MMI_TRUE if yes; otherwise MMI_FALSE.
 *****************************************************************************/
static MMI_BOOL mmi_mte_is_file_exist(S8 *file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *fp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fp = fopen(file_path, "rb"))
    {
        fclose(fp);
    
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_load_image_resource_from_file
 * DESCRIPTION
 *  Convert an image from file to image resource (add a 8-byte resource header)
 * PARAMETERS
 *  filename       [IN]     image filename
 *  resource_size  [OUT]    resource size in bytes
 * RETURNS
 *  0: Success. 
 *  1: Failure.
 *****************************************************************************/
static int mmi_mte_load_image_resource_from_file(S8 *filename, S32 *resource_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     read_bytes;
    U16     image_type;
    U8      *image_data;
    S32     width, height;
    S32     mte_image_type;
    S8      command_line_str[MMI_MTE_MAX_PATH_LEN];
    S8      abm_exe_path[MMI_MTE_MAX_PATH_LEN];
    S8      temp_filename[MMI_MTE_MAX_PATH_LEN];
    mmi_mte_abm_encoder_error_enum  ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* cannot load EMS BMP files in EMS_IMAGE_PATH. */   
    if (mmi_mte_is_ems_image(filename))
    {
        return 1;
    }

    /* reserve the 8-byte header in the beginning */
    image_data = (U8*)g_mmi_mte_image_buffer + 8;
    *resource_size = 0;
    
    if (mmi_mte_read_file_into_buffer(filename, image_data, MMI_MTE_MAX_IMAGE_RESOURCE_SIZE - 8, &read_bytes))
    {
        return 1;
    }

    image_type = gdi_image_get_type_from_mem(image_data);

    /* map image type to MTE definition */
    switch (image_type)
    {
        case GDI_IMAGE_TYPE_GIF:
            mte_image_type = MMI_MTE_IMAGE_GIF;
            break;

        case GDI_IMAGE_TYPE_JPG:
            mte_image_type = MMI_MTE_IMAGE_JPG;
            break;

        case GDI_IMAGE_TYPE_BMP:
            mte_image_type = MMI_MTE_IMAGE_BMP;
            break;

        case GDI_IMAGE_TYPE_PNG:
            mte_image_type = MMI_MTE_IMAGE_PNG;
            break;

        default:
            return 1;
    }

    /* convert PNG to ABM */
    if (image_type == GDI_IMAGE_TYPE_PNG)
    {
        read_bytes = MMI_MTE_MAX_IMAGE_RESOURCE_SIZE - 8;

        ret = mmi_mte_encode_abm_image(MMI_MTE_ABMENC_MODE_OUTPUT_MEM, MMI_MTE_IMAGE_PNG_TO_ABM, filename, image_data, &read_bytes);
        if (ret != MMI_MTE_ABMENC_NO_ERROR)
        {
            return 1;
        }

        image_type = GDI_IMAGE_TYPE_ABM;
        mte_image_type = MMI_MTE_IMAGE_PNG_TO_ABM;
    }

    /* make the resource header */
    mmi_mte_get_image_dimension(mte_image_type, image_data, &width, &height);
    mmi_mte_make_resource_header((U8*)g_mmi_mte_image_buffer, (U8)image_type, width, height, read_bytes);
    *resource_size = read_bytes + 8;
    
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_check_theme
 * DESCRIPTION
 *  Checks and makes the report of the MMI theme.
 * PARAMETERS
 *  mmi_theme       [IN]    MMI theme
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_check_theme(MMI_theme *mmi_theme)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i;
    mmi_mte_theme_component_struct *c;
    void    *theme_data_address;
    U32     data_ptr;
    UI_filled_area *filler;
    UI_font_type   font;
    PU8     image;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MTE_DEBUG("\n");

    for (i = 0; i < mmi_mte_get_theme_component_num(); i++)
    {
        /* The theme component info structure is actually non-constant. */
        c = (mmi_mte_theme_component_struct*)mmi_mte_get_theme_component(i);
        theme_data_address = mmi_mte_translate_theme_component_data_pointer(c, mmi_theme);
        data_ptr = *((U32*)theme_data_address);

        filler = (UI_filled_area*)data_ptr;
        font = (UI_font_type)data_ptr;
        image = (PU8)data_ptr;
        
        switch (c->type)
        {
            case MMI_MTE_THEME_DATA_TYPE_FILLER:
                /* override filler allow NULL */
                if (filler == NULL)
                {
                    if (!(c->filler_flag & MMI_MTE_FILLER_ALLOW_NULL))
                    {
                        MTE_DEBUG("[MTE] %s filler allow null inconsistency.\n", c->name);
                    }

                    c->filler_flag |= MMI_MTE_FILLER_ALLOW_NULL;
                }
                
                /* override filler allow single border */                
                if (filler && (filler->flags & UI_FILLED_AREA_SINGLE_BORDER))
                {
                    if (!(c->filler_flag & MMI_MTE_FILLER_ALLOW_BORDER))
                    {
                        MTE_DEBUG("[MTE] %s filler allow border inconsistency.\n", c->name);
                    }

                    c->filler_flag |= MMI_MTE_FILLER_ALLOW_BORDER;
                }                
                break;

            case MMI_MTE_THEME_DATA_TYPE_FONT:
                /* check non-system font */                
                if (font)
                {
                    if (mmi_mte_translate_font_pointer(font) == MMI_MTE_FONT_TYPE_UNDEF)
                    {
                        MTE_DEBUG("Theme compoent %s has an invalid font type.\n", c->name);
                    }
                }            
                break;

            default:
                break;
        }            
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_to_lower_string
 * DESCRIPTION
 *  Converts a string to the lower case.
 * PARAMETERS
 *  str_in        [IN]  input string
 *  str_out       [IN]  output string
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_to_lower_string(S8 *str_in, S8 *str_out)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8      c;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do 
    {   
        c = *str_in++;
        *str_out++ = tolower(c);
    } while (c);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_is_ems_image
 * DESCRIPTION
 *  Checks if the image file is an EMS image.
 * PARAMETERS
 *  filename       [IN]     image filename
 * RETURNS
 *  MMI_TRUE if yes; otherwise, MMI_FALSE;
 *****************************************************************************/
static MMI_BOOL mmi_mte_is_ems_image(S8 *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8      lowercase_filename[MMI_MTE_MAX_PATH_LEN];    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_mte_to_lower_string(filename, lowercase_filename);

    if (strstr(lowercase_filename, "mainlcd\\sms\\pic"))
    {
        return MMI_TRUE;
    }
    
    return MMI_FALSE;
}


/***************************************************************************** 
 * Global Function
 *****************************************************************************/

/*
 * MTE UI API
 */

/*****************************************************************************
 * FUNCTION
 *  mmi_mte_init
 * DESCRIPTION
 *  MTE initialization in MMI side
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mte_init()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, theme_num;
    const MMI_theme *theme_list[MMI_MTE_MAX_THEME_NUMBER];
    const char *theme_name_list[MMI_MTE_MAX_THEME_NUMBER];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set the MTE RPC handler as the handler. */
    SetProtocolEventHandler(mmi_mte_rpc_handler, MMI_MTE_MESSAGE_ID);

    /* register ISRs for MTE RPC */
    OSC_Register_ISR(MTE_MMI_TO_MTE_ISR, mmi_to_mte_isr);
    OSC_Register_ISR(MTE_MTE_TO_MMI_ISR, mte_to_mmi_isr);

    /* check all system themes */
    theme_num = mmi_mte_get_system_theme_data(MMI_MTE_MAX_THEME_NUMBER, theme_list, theme_name_list);
    for (i = 0; i < theme_num; i++)
    {
        mmi_mte_check_theme((MMI_theme*)theme_list[i]);
    }
}


/*****************************************************************************
 * FUNCTION
 *  w32_mmi_mte_api
 * DESCRIPTION
 *  The function returns the function pointer of a specified api_index.
 *  NOTE: THIS FUNCTION SHALL NOT BE USED BY MTE UI.
 * PARAMETERS
 *  api_index       [IN]    API index
 * RETURNS
 *  A function pointer of MTE API.
 *****************************************************************************/
void (*w32_mmi_mte_api(int api_index))(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_mte_api_index = api_index;

    if (api_index == MMI_MTE_RPC_REGISTER_FINISH_CALLBACK_API_INDEX)
    {
        return (void_func_ptr)mmi_mte_register_finish_callback;
    } 
    else if (api_index == MMI_MTE_RPC_GET_RETURN_VALUE_API_INDEX)
    {
        return (void_func_ptr)mmi_mte_ret_value;
    }

    /* Do RPC only for necessary APIs for better performance. */
    for (i = 0; i < MMI_MTE_API_NEED_SYNC_NUM; i++)
    {
        if (mmi_mte_api_need_sync_index[i] == api_index)
        {
            return (void_func_ptr)mmi_mte_rpc_invoker;
        }
    }

    return (void_func_ptr)g_mmi_mte_function_table[api_index];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_baseband_chip
 * DESCRIPTION
 *  The function returns the current baseband chip name string.
 * PARAMETERS
 *  void
 * RETURNS
 *  BB chip name ASCII string.
 *****************************************************************************/
const char *mmi_mte_get_baseband_chip(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * release_bb_chip() in init.c is not available in MoDIS. So, just do it directly.
     * The available chip names are from option.mak.
     */
#if defined(MT6218B)
        return "MT6218B";
#elif defined(MT6217)
        return "MT6217";
#elif defined(MT6219)
        return "MT6219";
#elif defined(MT6226M)
        return "MT6226M";
#elif defined(MT6229)
        return "MT6229";
#elif defined(MT6230)
        return "MT6230";
#elif defined(MT6228)
        return "MT6228";
#elif defined(MT6227)
        return "MT6227";
#elif defined(MT6227D)
        return "MT6227D";
#elif defined(MT6226)
        return "MT6226";
#elif defined(MT6226D)
        return "MT6226D";
#elif defined(MT6208)
        return "MT6208";
#elif defined(MT6205B)
        return "MT6205B";
#elif defined(MT6205C)
        return "MT6205C";
#elif defined(MT6225)
        return "MT6225";
#elif defined(MT6223)
        return "MT6223";
#elif defined(MT6223P)
        return "MT6223P";
#elif defined(MT6238)
        return "MT6238";
#else
        return "UNKNOWN";
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_lcd_resolution
 * DESCRIPTION
 *  Get the LCD width and height.
 * PARAMETERS
 *  lcd_type       [IN]     lcd type. main lcd: MMI_MTE_LCD_TYPE_MAIN, sub lcd: MMI_MTE_LCD_TYPE_SUB
 *  width          [OUT]    lcd width     
 *  height         [OUT]    lcd height
 * RETURNS
 *  0: success, 1: failure (e.g. The sublcd is not avaialable.)
 *****************************************************************************/
int mmi_mte_get_lcd_resolution(mmi_mte_lcd_type_enum lcd_type, int *width, int *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (lcd_type == MMI_MTE_LCD_TYPE_MAIN)
    {
        *width = GDI_LCD_WIDTH;
        *height = GDI_LCD_HEIGHT;

        return 0;
    }
#ifdef __MMI_SUBLCD__
    else
    {
        *width = GDI_SUBLCD_WIDTH;
        *height = GDI_SUBLCD_HEIGHT;        
    
        return  0;
    }
#endif /* __MMI_SUBLCD__ */        

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_theme_component_symbol_info
 * DESCRIPTION
 *  The function returns the symbol string of a specified theme component. 
 * PARAMETERS
 *  theme_component       [IN]  pointer to a theme component structure
 * RETURNS
 *  Symbol ASCII string.
 *****************************************************************************/
const char *mmi_mte_get_theme_component_symbol_info(const mmi_mte_theme_component_struct *theme_component)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return theme_component->internal_data.symbol_name;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_translate_font_pointer
 * DESCRIPTION
 *  Translate from a UI_font_type pointer to predefined font type.
 * PARAMETERS
 *  font_ptr       [IN]     font pointer
 * RETURNS
 *  Recognized font type.
 *****************************************************************************/
mmi_mte_theme_data_type_enum mmi_mte_translate_font_pointer(UI_font_type font_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_MTE_FONT_TYPE_NUM; i++)
    {
        if (g_mmi_mte_font[i].ptr == font_ptr)
        {
            return i;
        }
    }

    return MMI_MTE_FONT_TYPE_UNDEF;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_font_symbol
 * DESCRIPTION
 *  Provide font symbol name suitable to print on ThemeRes.c.
 * PARAMETERS
 *  font_type       [IN]        font type
 * RETURNS
 *  Font symbol name in ASCII. NULL if undefined.
 *****************************************************************************/
const char *mmi_mte_get_font_symbol(mmi_mte_theme_data_type_enum font_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (font_type >= MMI_MTE_FONT_TYPE_NUM)
    {
        return NULL;
    }    
    
    return g_mmi_mte_font[font_type].name;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_theme_component_image_info
 * DESCRIPTION
 *  The function returns the input image type of a specified theme component. 
 * PARAMETERS
 *  theme_component            [IN]     pointer to a theme component structure
 *  recommend_width            [OUT]    recommended image width. If it equals to 0, there is no recommendation.
 *  recommend_height           [OUT]    recommended image height. If it equals to 0, there is no recommendation.
 *  max_width                  [OUT]    max image width
 *  max_height                 [OUT]    max image height
 *  allowed_image_type         [OUT]    a flag union to identify supported input image formats. (bitwise ORed)
 *  recommend_image_type       [OUT]    recommended image type. At most one image type is recommended. If there is not special recommendation, it may returns MMI_MTE_IMAGE_NONE.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mte_get_theme_component_image_info(mmi_mte_theme_component_struct *theme_component, int *recommend_width, int *recommend_height, int *max_width, int *max_height, unsigned int *allowed_image_type, mmi_mte_image_enum *recommend_image_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int             lcd_width, lcd_height;
    unsigned int    selectable_image_type;
    int             iw, ih;
    MMI_BOOL        is_full_screen;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if the theme component does not contain images, return none. */
    if (theme_component->internal_data.image_type == MMI_MTE_IMAGE_NONE)
    {
        *allowed_image_type = MMI_MTE_IMAGE_NONE;
        *recommend_image_type = MMI_MTE_IMAGE_NONE;
        
        return;
    }
    
    mmi_mte_get_lcd_resolution(theme_component->lcd_type, &lcd_width, &lcd_height);        
    
    *max_width = lcd_width;
    *max_height = lcd_height; 
    
    if (!mmi_mte_get_theme_image_dimension(theme_component, MTE_CURRENT_LCD_RES, &iw, &ih) && 
        !mmi_mte_get_theme_image_dimension(theme_component, MMI_MTE_LCD_DEFAULT, &iw, &ih))
    {
        *recommend_width = 0;
        *recommend_height = 0;        
    }            
    else
    {
        *recommend_width = iw;
        *recommend_height = ih;
        *max_width = iw;
        *max_height = ih;
    }        
    
    if (lcd_width * lcd_height == iw * ih)
    {
        is_full_screen = MMI_TRUE;
    }
    else
    {
        is_full_screen = MMI_FALSE;
    }    

    /* allowed image types */
    selectable_image_type = theme_component->internal_data.image_type;
    selectable_image_type = mmi_mte_filter_image_type(selectable_image_type & 0xFFFF, is_full_screen);    
    *allowed_image_type = selectable_image_type;

    /* recommended image type out of allowed ones */
    *recommend_image_type = mmi_mte_filter_image_type(theme_component->internal_data.image_type >> 16, is_full_screen);
    *allowed_image_type |= *recommend_image_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_image_info_string
 * DESCRIPTION
 *  Return NULL or a recommended warning/information string when choosing a certain image type.
 * PARAMETERS
 *  image_type       [IN]   image type
 * RETURNS
 *  A hint string for a specified image type in Unicode.
 *****************************************************************************/
const char *mmi_mte_get_image_info_string(mmi_mte_image_enum image_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* HAVE TO sync with gui_image_query_cache_type() */
#if (defined(MT6205_SERIES) || defined(MT6223_SERIES))
    if ((image_type == MMI_MTE_IMAGE_JPG) || (image_type == MMI_MTE_IMAGE_GIF))
    {
        return (const char *)L"The selected image type is smaller than BMP but slower on this platform.";
    }
#endif /* (defined(MT6205_SERIES) || defined(MT6223_SERIES)) */

#if defined(MT6225_SERIES)
    if (image_type == MMI_MTE_IMAGE_GIF)
    {
        return (const char *)L"GIF decoding is slow on 6225 platforms.";
    }
#endif /* defined(MT6225_SERIES) */

    return (const char *)L"";
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_image_dimension
 * DESCRIPTION
 *  Get image width and height.
 * PARAMETERS
 *  image_type       [IN]   input image type
 *  image_data       [IN]   input image data
 *  width            [OUT]  input image width
 *  height           [OUT]  input image height
 * RETURNS
 *  0: success, 1: failure
 *****************************************************************************/
int mmi_mte_get_image_dimension(mmi_mte_image_enum image_type, char *image_data, int *width, int *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT  ret;
    U8          input_image_type;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    input_image_type = mmi_mte_translate_image_type_from_mte_to_gdi(image_type);

    if (input_image_type == GDI_IMAGE_TYPE_INVALID)
    {
        return 1;
    }
    
    ret = gdi_image_codec_get_dimension(
            GDI_IMAGE_SRC_FROM_MEMORY,
            image_data,
            input_image_type,
            MMI_MTE_MAX_IMAGE_RESOURCE_SIZE,
            width,
            height,
            0);

    if (ret == GDI_SUCCEED)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_image_finish_callback
 * DESCRIPTION
 *  GDI image frame finish callback
 * PARAMETERS
 *  result      [IN]    GDI result
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mte_image_finish_callback(GDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* convert the image layer to 32-bit output buffer */
    mmi_mte_convert_image_layer_to_32(g_mmi_mte_image_layer_handle, g_mmi_mte_output_buffer);

    if (g_mmi_mte_image_frame_finish_callback)
    {
        g_mmi_mte_image_frame_finish_callback((char*)g_mmi_mte_output_buffer, g_mmi_mte_output_image_width, g_mmi_mte_output_image_height);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_start_decode_image
 * DESCRIPTION
 *  Decode an image to the output buffer. The pixel format of the output buffer is ARGB8888. 
 *  Although resizing is supported here, it is NOT recommended to do resizing since the GDI 
 *  resizing quality is not good. Moreover, some image decoders do not support resizing.
 * PARAMETERS
 *  image_type                 [IN]     input image type
 *  image_data                 [IN]     The memory space for the string pointer array is allocated by the caller. It should be 4-byte aligned.
 *  image_size                 [IN]     input image size
 *  output_buffer              [OUT]    output buffer. It should be 4-byte aligned.
 *  output_buffer_size         [IN]     output buffer size (output_image_width * output_image_height * 4)
 *  output_image_width         [IN]     output image width
 *  output_image_height        [IN]     output image height
 *  frame_finish_callback      [IN]     frame finish callback function. If this callback is not NULL, it is invoked after each frame is decoded. For example, MTE can bitblt out the decoded buffer in this callback for GIF animation.
 * RETURNS
 *  0: Success.
 *  1: Decoder error.
 *****************************************************************************/
int mmi_mte_start_decode_image(mmi_mte_image_enum image_type, char *image_data, int image_size, char *output_buffer, unsigned int output_buffer_size, int output_image_width, int output_image_height, void (*frame_finish_callback)(char *output_buffer, int output_image_width, int output_image_height))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT      ret;
    U8              input_image_type;
    S32             frame_num;
    gdi_handle      old_src_layer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = GDI_FAILED;
    
    g_mmi_mte_output_buffer = (U8*)output_buffer;
    
    mmi_mte_stop_decode_image();

    /* free the layer if it was created */
    if (g_mmi_mte_image_layer_handle > 0)
    {
        gdi_layer_free(g_mmi_mte_image_layer_handle);
        g_mmi_mte_image_layer_handle = GDI_NULL_HANDLE;
    }

    /* pass too large images */
    if (output_image_width * output_image_height * 4 > MMI_MTE_MAX_IMAGE_RESOURCE_SIZE)
    {
        return 1;
    }

    /* image output layer */
    gdi_layer_create_using_outside_memory(
        0,
        0,
        output_image_width,
        output_image_height,
        &g_mmi_mte_image_layer_handle,
        (kal_uint8*)g_mmi_mte_image_layer_buffer,
        MMI_MTE_MAX_IMAGE_RESOURCE_SIZE);        

    gdi_layer_lock_frame_buffer();
    gdi_layer_push_and_set_active(g_mmi_mte_image_layer_handle);
    /* fill white background for ALPHA images, such as PNG and ABM. */
    gdi_layer_clear(GDI_COLOR_WHITE);

    g_mmi_mte_image_frame_finish_callback = frame_finish_callback;

    if (frame_finish_callback)
    {
        gdi_anim_set_blt_after_callback(mmi_mte_image_finish_callback);
    }

    input_image_type = mmi_mte_translate_image_type_from_mte_to_gdi(image_type);

    if (input_image_type == GDI_IMAGE_TYPE_ABM)
    {
        old_src_layer = gdi_image_abm_set_source_layer(g_mmi_mte_image_layer_handle);
    }

    if (input_image_type == GDI_IMAGE_TYPE_BMP)
    {
        /* 
         * The BMP decoder does not use the first palette color as the transparent color if the BMP is from memory. 
         * Use gdi_image_codec_draw() to decode the BMP as resource.
         */
        ret = gdi_image_codec_draw(
                GDI_IMAGE_SRC_FROM_RESOURCE_WITHOUT_HEADER,
                (U8*)image_data,
                GDI_IMAGE_TYPE_BMP,
                image_size,
                0,
                0,
                0,
                0,
                0,
                0);        
    }
    else
    {
        ret = gdi_anim_draw_mem(0, 0, (U8*)image_data, input_image_type, image_size, &g_mmi_mte_anim_handle);
    }
    
    if (input_image_type == GDI_IMAGE_TYPE_ABM)
    {
        gdi_image_abm_set_source_layer(old_src_layer);
    }    

    gdi_layer_pop_and_restore_active();
    gdi_layer_unlock_frame_buffer();
    
    if (ret < 0)
    {
        return 1;
    }

    /* convert the image layer to 32-bit output buffer */
    mmi_mte_convert_image_layer_to_32(g_mmi_mte_image_layer_handle, g_mmi_mte_output_buffer);
 
    return 0;  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_stop_decode_image
 * DESCRIPTION
 *  Stop GIF animation.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mte_stop_decode_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_mte_anim_handle > 0)
    {
        gdi_anim_stop(g_mmi_mte_anim_handle);
    }

    g_mmi_mte_anim_handle = GDI_NULL_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_theme_schema_version
 * DESCRIPTION
 *  The function returns the MTE version information.
 * PARAMETERS
 *  major_verno       [IN]  major version number
 *  minor_verno       [IN]  minor version number
 * RETURNS
 *  The MTE version string.
 *****************************************************************************/
const char *mmi_mte_get_theme_schema_version(int *major_verno, int *minor_verno)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* increase the verno for the new branch */
    *major_verno = 1;
    *minor_verno = 0;

    return (const char *)release_verno();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_theme_component_num
 * DESCRIPTION
 *  Get the total number of theme components.
 * PARAMETERS
 *  void
 * RETURNS
 *  The total number of theme components.
 *****************************************************************************/
int mmi_mte_get_theme_component_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_MTE_THEME_COMPONENT_NUM;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_theme_component
 * DESCRIPTION
 *  Get the theme component structure by its id.
 * PARAMETERS
 *  component_id       [IN]     theme component id. Range: 0 to (mmi_mte_get_theme_component_num() - 1)
 * RETURNS
 *  Pointer to the theme component structure by its id.
 *****************************************************************************/
const mmi_mte_theme_component_struct *mmi_mte_get_theme_component(int component_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (component_id >= mmi_mte_get_theme_component_num())
    {
        return NULL;
    }

    return &g_mmi_mte_theme_component_info[component_id];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_theme_components_in_current_screen
 * DESCRIPTION
 *  Return a list of theme component names used in the current screen.
 * PARAMETERS
 *  max_component_number        [IN]    number of available component (at least 100 is suggested)
 *  theme_component_list        [OUT]   a list of theme component structure pointers. The memory space for the string pointer array is allocated by the caller.
 * RETURNS
 *  Number of components in the returned theme_component_list.
 *****************************************************************************/
int mmi_mte_get_theme_components_in_current_screen(int max_component_number, const mmi_mte_theme_component_struct *theme_component_list[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i, j, g;
    U8      *control_set_ptr = NULL;
    S16     *coordinate_set;
    S32     control_set_num, old_control_set_num;
    const mmi_mte_theme_component_struct *tc;
    S32     control_set_id;
    S32     done;
    S32     count;
    U8      local_control_set[128];
    S32     dm_data_flag;
    S32     current_category_id, current_screen_id;
    S32     *theme_component_category_id_filter;
    S32     category_filter_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (max_component_number > mmi_mte_get_theme_component_num())
    {
        max_component_number = mmi_mte_get_theme_component_num();
    }

    dm_get_dm_data_flag(&dm_data_flag);
    current_category_id = g_dm_data.s32CatId;
    current_screen_id = GetActiveScreenId();

    /* special screen check */
    count = 0;    

    /* get the control set of the current category */
    control_set_ptr = dm_search_control_set((U16)g_dm_data.s32CatId, &coordinate_set);    

    /* prevent screen without control set, such as the camera screen. */
    if (control_set_ptr == NULL)
    {
        return 0;
    }

    old_control_set_num = (S32)control_set_ptr[0];
    control_set_num = 0;

    /* expand draw manager BASE control sets */
    for (j = 0; j < old_control_set_num; j++)
    {
        control_set_id = control_set_ptr[j + 1];

        switch (control_set_id)
        {
            case DM_BASE_CONTROL_SET1:
        #if !defined(GUI_SUBMENU_USE_SPECIFIC_STYLE)
            case DM_BASE_CONTROL_SET_SUBMENU:
        #endif /* !defined(GUI_SUBMENU_USE_SPECIFIC_STYLE) */
        #if !defined(GUI_COMMON_USE_SPECIFIC_STYLE)
            case DM_BASE_CONTROL_SET_COMMON:
        #endif /*!defined(GUI_COMMON_USE_SPECIFIC_STYLE) */
            {
                extern const U8 dm_base_control_set[];               
                mmi_mte_append_control_set(local_control_set, &control_set_num, (U8*)dm_base_control_set);
                break;
            }                

            case DM_BASE_CONTROL_SET2:
            {
                extern const U8 dm_base_control_set2[];
                mmi_mte_append_control_set(local_control_set, &control_set_num, (U8*)dm_base_control_set2);        
                break;
            }

        #if defined(GUI_SUBMENU_USE_SPECIFIC_STYLE)
            case DM_BASE_CONTROL_SET_SUBMENU:
            {
                extern const U8 dm_base_control_set_submenu[];
                mmi_mte_append_control_set(local_control_set, &control_set_num, (U8*)dm_base_control_set_submenu);        
                break;
            }

        #endif /* defined(GUI_SUBMENU_USE_SPECIFIC_STYLE) */

        #if defined(GUI_COMMON_USE_SPECIFIC_STYLE)
            case DM_BASE_CONTROL_SET_COMMON:
            {
                extern const U8 dm_base_control_set_common[];
                mmi_mte_append_control_set(local_control_set, &control_set_num, (U8*)dm_base_control_set_common);                    
                break;
            }
        #endif /* defined(GUI_COMMON_USE_SPECIFIC_STYLE) */

            default:
                local_control_set[control_set_num++] = control_set_id;
                break;
        }

    }

    /* remove dm groups in filter */
    mmi_mte_remove_dm_group_in_filter(current_screen_id, current_category_id, local_control_set, control_set_num);

    /* popup rule: remove multiline inputbox group */
    if (mmi_mte_search_dm_group_in_control_set(DM_POPUP_BACKGROUND, local_control_set, control_set_num) != -1)
    {
        mmi_mte_remove_dm_group_in_control_set(DM_MULTILINE_INPUTBOX1, local_control_set, control_set_num);
    }

    /* remove DM_TITLE_1 if no title, e.g. popups */
    if (dm_data_flag & DM_NO_TITLE)
    {
        mmi_mte_remove_dm_group_in_control_set(DM_TITLE1, local_control_set, control_set_num);
    }
    /* remove DM_BUTTON_BAR1 if no softkey, e.g., the touch idle screen */
    if (dm_data_flag & DM_NO_SOFTKEY)
    {
        mmi_mte_remove_dm_group_in_control_set(DM_BUTTON_BAR1, local_control_set, control_set_num);
    }
    /* remove DM_STATUS_BAR1 if no status bar */
    if (dm_data_flag & DM_NO_STATUS_BAR)
    {
        mmi_mte_remove_dm_group_in_control_set(DM_STATUS_BAR1, local_control_set, control_set_num);
    }
        

    /* PAGE menu special rule. Do not use included theme components in the filter. */
#ifdef __MMI_MAINMENU_PAGE_SUPPORT__
    if (current_category_id == MMI_CATEGORY14_LIST_ID)
    {
    #ifdef __MMI_MAINMENU_STYLE_CHANGE_EN__
        if (PhnsetGetMainMenuStyle() == PHNSET_MAINMENU_STYLE_PAGE)
        {
            current_category_id = MMI_CATEGORY_END;
        }
    #endif
    }    
#endif /* __MMI_MAINMENU_PAGE_SUPPORT__ */

    /* check each component */
    for (i = 0; i < mmi_mte_get_theme_component_num(); i++)
    {                
        tc = mmi_mte_get_theme_component(i);

        done = 0;

        /* check if the theme component is in the specified rule */
        if (mmi_mte_is_component_in_screen(tc->id, current_screen_id, current_category_id))
        {
            done = 1;
        }

        /* check the theme component category id filter */
        theme_component_category_id_filter = tc->internal_data.category_filter;
        if (theme_component_category_id_filter)
        {
            while ((category_filter_id = *theme_component_category_id_filter++) != -1)
            {
                if (current_category_id == category_filter_id)
                {
                    done = 1;
                    break;
                }
            }
        }

        /* 
         * NEGATIVE rules
         */        
#ifdef __MMI_SCREEN_ROTATE__
        /* only show rotated_xxxx components in the rotated environment */
        if (!mmi_frm_is_screen_width_height_swapped())
        {
            if (!strncmp(tc->name, "rotated_", 8))
            {
                continue;
            }
        }    
#endif /* __MMI_SCREEN_ROTATE__ */
        
        /* status_icon_bar_filler does not work in wallpaper on bottom. */
        if (!strcmp(tc->name, "status_icon_bar_filler") &&
            ((wgui_is_wallpaper_on_bottom() == MMI_TRUE) ||
             (dm_get_wallpaper_layer() > 0)))
        {
            continue;
        }

        /* softkey_bar_bkg_filler does not work in wallpaper on bottom and MMI_softkey_filler_disabled. */
        if (!strcmp(tc->name, "softkey_bar_bkg_filler"))
        {
            if (MMI_softkey_filler_disabled && wgui_is_wallpaper_on_bottom())
            {
                continue;
            }

        #ifndef __MMI_MAINLCD_128X128__
            /* For non 128x128, IMG_SOFTKEY_BAR image is used instead. See show_softkey_background_with_clipping(). */
            if (!wgui_is_wallpaper_on_bottom())
            {
                continue;
            }
        #endif /* __MMI_MAINLCD_128X128__ */
        }

        /*
         * Idle screen analog clock
         */
        if (current_screen_id == IDLE_SCREEN_ID)         
        {
    #ifndef __MMI_UI_TECHNO_IDLESCREEN_BAR__
        #ifdef __MMI_ANALOG_CLOCK__        
            if ((U32)PhnsetGetCurWallpaperName() == (U32)GetString(STR_ID_PHNSET_DISPCHAR_ANALOG))
            {   /* analog clock on the idle screen */
                if (!strcmp(tc->name, "analog_hand_hour_color") ||
                    !strcmp(tc->name, "analog_hand_min_color") ||
                    !strcmp(tc->name, "analog_axis_color"))
                {
                    done = 1;
                }
            }
        #endif /* __MMI_ANALOG_CLOCK__ */
    #else /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */
            if (g_clock_type == ANALOG)
            {
                if (!strcmp(tc->name, "analog_hand_hour_color") ||
                    !strcmp(tc->name, "analog_hand_min_color"))
                {
                    done = 1;
                }            
            }
    #endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */
        }


        /*
         * hint description text color for list menus
         */
         // TODO: should use a new component for the hint description text color
    #ifndef __MMI_UI_HINTS_IN_MENUITEM__
        if (wgui_pop_up_descriptions_n_items && !strcmp(tc->name, "popup_description_text_color"))
        {
            done = 1;
        }
    #endif /* __MMI_UI_HINTS_IN_MENUITEM__ */


        /* category 165 ext popup_description_text_color for the countdown text */
        // 07B only, removed in 08A
        if (!strcmp(tc->name, "popup_description_text_color") && (current_category_id == MMI_CATEGORY165_ID) && (Cat165TimerExpireCallBack != UI_dummy_function))
        {
            done = 1;
        }
        
        /* check if any control set contains the theme component. */
        for (j = 0; j < control_set_num && !done; j++)
        {                
            control_set_id = (S32)local_control_set[j];

            /* DM_SCR_BG SPECIAL RULE */
            if (control_set_id == DM_SCR_BG)
            {                
                if ((dm_get_current_scr_bg_filler() == current_MMI_theme->main_menu_bkg_filler) &&
                    !strcmp(tc->name, "main_menu_bkg_filler"))
                {
                    done = 1;
                    break;
                }
                else if ((dm_get_current_scr_bg_filler() == current_MMI_theme->sub_menu_bkg_filler) &&
                    !strcmp(tc->name, "sub_menu_bkg_filler"))
                {
                    done = 1;
                    break;
                }
            }

            /* check if the theme component belongs to one of the DM group */
            if (mmi_mte_is_component_in_dm_group(tc->id, control_set_id))
            {
                done = 1;
                break;
            }
        }

        /* do not exceed the caller limit */
        if (count >= max_component_number)
        {
            break;
        }

        /* add the component into the returned list */
        if (done == 1)
        {
            theme_component_list[count++] = tc;
        }
    }
    
    return count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_component_group_num
 * DESCRIPTION
 *  Get the total number of component groups.
 * PARAMETERS
 *  void
 * RETURNS
 *  The total number of component groups.
 *****************************************************************************/
int mmi_mte_get_component_group_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_MTE_THEME_COMPONENT_GROUP_NUM;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_component_group_name
 * DESCRIPTION
 *  Get the group name by its id.
 * PARAMETERS
 *  group_id       [IN]     group id. Range: 0 to mmi_mte_get_component_group_num() - 1
 * RETURNS
 *  The group name string in Unicode.
 *****************************************************************************/
const char *mmi_mte_get_component_group_name(int group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (group_id >= mmi_mte_get_component_group_num())
    {
        return NULL;
    }
   
    return (const char*)g_mmi_mte_theme_component_group_name[group_id];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_system_theme_data
 * DESCRIPTION
 *  Get current fixed compiled system theme information.
 * PARAMETERS
 *  max_theme_number        [IN]    max number of returned system themes for theme_list[] and theme_name_list[]. (At least 20 is suggested)
 *  theme_list[]            [OUT]   system theme structure list    
 *  theme_name_list[]       [OUT]   list of system theme name strings in ASCII
 * RETURNS
 *  Number of available system themes.
 *****************************************************************************/
int mmi_mte_get_system_theme_data(int max_theme_number, const MMI_theme *theme_list[], const char *theme_name_list[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (max_theme_number > mtk_n_MMI_themes)
    {
        max_theme_number = mtk_n_MMI_themes;
    }

    for (i = 0; i < max_theme_number; i++)
    {
    #ifndef __MMI_THEMES_V2_SUPPORT__
        theme_list[i] = mtk_MMI_themes[i];
    #else /* __MMI_THEMES_V2_SUPPORT__ */
        theme_list[i] = mtk_MMI_themes[i].theme;
    #endif /* __MMI_THEMES_V2_SUPPORT__ */

        theme_name_list[i] = (const char *)MMI_theme_names[i];
    }
    
    return max_theme_number;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_current_system_theme
 * DESCRIPTION
 *  Gets the current activated MMI theme.
 * PARAMETERS
 *  void
 * RETURNS
 *  Current activated MMI theme.
 *****************************************************************************/
MMI_theme *mmi_mte_get_current_system_theme(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return current_MMI_theme;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_refresh_screen
 * DESCRIPTION
 *  Refresh MoDIS MMI screen. It is typically invoked when theme data or image file is changed.
 * PARAMETERS
 *  lcd_type       [IN]     SubLCD or Main LCD
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mte_refresh_screen(mmi_mte_lcd_type_enum lcd_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MTE_EXAMPLE, NULL, NULL, NULL);
    ShowCategoryDummyScreen();
    ExecSubLCDCurrExitHandler();
    GoBackBothLCDHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_activate_theme
 * DESCRIPTION
 *  Activate a theme.
 * PARAMETERS
 *  theme       [IN]    MMI theme to be activated
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mte_activate_theme(MMI_theme *theme)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_mte_state_enum  mte_state;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();

    /* 
     * Enter a new screen first and then apply the theme to prevent 
     * some categories from restoring the theme variable.
     */
    EntryNewScreen(SCR_ID_MTE_EXAMPLE, NULL, NULL, NULL);
    ShowCategoryDummyScreen();

    /* Temporarily change the MTE state because set_MMI_theme() will not work when mte is active. */
    mte_state = mmi_mte_is_active();
    mmi_mte_set_state(MMI_MTE_STATE_INACTIVE);
    set_MMI_theme(theme);
    mmi_mte_set_state(mte_state);
    MMI_apply_current_theme();
    
    mmi_mte_refresh_screen(MMI_MTE_LCD_TYPE_MAIN);
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, 0, 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_translate_theme_component_data_pointer
 * DESCRIPTION
 *  Return the pointer to the theme component in the given MMI_theme. 
 *  This function links two structures 'mmi_mte_theme_component_struct' and 'MMI_theme' together.
 * PARAMETERS
 *  theme_component       [IN]  pointer to the theme component structure
 *  theme                 [IN]  pointer to MMI theme
 * RETURNS
 *  Return theme component data pointer, which needs type casting according to the component type.
 *****************************************************************************/
void *mmi_mte_translate_theme_component_data_pointer(const mmi_mte_theme_component_struct *theme_component, MMI_theme *theme)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (U8*)theme + theme_component->internal_data.mmi_theme_offset;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_register_switch_screen_callback
 * DESCRIPTION
 *  This registered callback function is called when a screen change happens in MMI. 
 *  MTE can use this callback to update the component list of [Screen 5] when the 
 *  theme component filter is set to "Current Screen".
 * PARAMETERS
 *  switch_screen_callback      [IN]    switch screen callback function
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mte_register_switch_screen_callback(void (*switch_screen_callback)(void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_mte_switch_screen_callback = switch_screen_callback;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_example_screen_num
 * DESCRIPTION
 *  Get the number of example screens.
 * PARAMETERS
 *  void
 * RETURNS
 *  Number of example screens.
 *****************************************************************************/
int mmi_mte_get_example_screen_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_MTE_EXAMPLE_SCREEN_NUM;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_example_screen_name
 * DESCRIPTION
 *  Get the example screen name by its screen index.
 * PARAMETERS
 *  screen_index       [IN]     screen index
 * RETURNS
 *  Name of the specified screen in Unicode.
 *****************************************************************************/
const char *mmi_mte_get_example_screen_name(int screen_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (screen_index > mmi_mte_get_example_screen_num())
    {
        return NULL;   
    }

    return (const char*)g_mmi_mte_example_screen_name[screen_index];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_show_example_screen
 * DESCRIPTION
 *  Show an example screen by its screen index. This function is provided to 
 *  let users be able to choose a screen to work on.
 * PARAMETERS
 *  screen_index       [IN]     screen index
 * RETURNS
 *  0: Success.
 *  1: Failure. Invalid screen index.
 *****************************************************************************/
int mmi_mte_show_example_screen(int screen_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 old_menu_style = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    /*
     *  to goto a screen normally, it is safer to go back to the idle first.
     */
    gdi_layer_lock_frame_buffer();
    GoBacknHistory((U16)(GetScreenCountInHistory() - 1));

#ifdef __MMI_MAINMENU_STYLE_CHANGE_EN__
    old_menu_style = PhnsetGetMainMenuStyle();
#endif /* __MMI_MAINMENU_STYLE_CHANGE_EN__ */            
                 
    switch (screen_index)
    {
        /*
         * Idle Screen
         */
        case MMI_MTE_EXAMPLE_SCREEN_IDLE: 
            break;

        /*
         * 6 Styles of Main Menus
         */
    #if defined(__MMI_MAINMENU_MATRIX_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
        case MMI_MTE_EXAMPLE_SCREEN_MATRIX_MAIN_MENU:
            mmi_mte_set_example_main_menu_style(PHNSET_MAINMENU_STYLE_MATRIX);
            goto_main_menu();
            break;
    #endif /* defined(__MMI_MAINMENU_MATRIX_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__) */

    #if defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
        case MMI_MTE_EXAMPLE_SCREEN_BIDEGREE_MAIN_MENU:
            goto_main_menu();
            break;
    #endif /* defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__) */    

    #if defined(__MMI_MAINMENU_LIST_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
        case MMI_MTE_EXAMPLE_SCREEN_LIST_MAIN_MENU:
            mmi_mte_set_example_main_menu_style(PHNSET_MAINMENU_STYLE_LIST);
            goto_main_menu();
            break;
    #endif /* defined(__MMI_MAINMENU_LIST_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__) */

    #if defined(__MMI_MAINMENU_PAGE_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
        case MMI_MTE_EXAMPLE_SCREEN_PAGE_MAIN_MENU:
            mmi_mte_set_example_main_menu_style(PHNSET_MAINMENU_STYLE_PAGE);
            goto_main_menu();
            break;
    #endif /* defined(__MMI_MAINMENU_PAGE_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__) */    

    #if defined(__MMI_MAINMENU_CIRCULAR_SUPPORT__) && defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
        case MMI_MTE_EXAMPLE_SCREEN_3D_CIRCULAR_MAIN_MENU:
            mmi_mte_set_example_main_menu_style(PHNSET_MAINMENU_STYLE_CIRCULE);
            goto_main_menu();
            break;
    #endif /* defined(__MMI_MAINMENU_CIRCULAR_SUPPORT__) && defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__) */    

    #if defined(__MMI_MAINMENU_ROTATE_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
        case MMI_MTE_EXAMPLE_SCREEN_ROTATE_MAIN_MENU:
            mmi_mte_set_example_main_menu_style(PHNSET_MAINMENU_STYLE_ROTATE);
            goto_main_menu();
            break;
    #endif /* defined(__MMI_MAINMENU_ROTATE_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__) */    

        case MMI_MTE_EXAMPLE_SCREEN_LIST: /* list menu */            
            /* setting menu */
            EntryScrSettingMenu();
            break;

        case MMI_MTE_EXAMPLE_SCREEN_INLINE:
            mmi_phb_entry_op_add_entry();
            break;

        case MMI_MTE_EXAMPLE_SCREEN_EDITOR:
            mmi_mte_example_screen_entry_editor();
            break;

        case MMI_MTE_EXAMPLE_SCREEN_CALL:
            mmi_mte_example_screen_entry_call();
            break;

        case MMI_MTE_EXAMPLE_SCREEN_DIALER:
            /* dialer from idle */
            IdleScreenDigitHandler();
            break;

    #ifdef __MMI_CALENDAR__            
        case MMI_MTE_EXAMPLE_SCREEN_CALENDAR:
            /* calendar */
            ClndrPreEntryApp();
            break;
    #endif /* __MMI_CALENDAR__ */             

    #ifdef __MMI_SCREEN_ROTATE__
        case MMI_MTE_EXAMPLE_SCREEN_ROTATED_POPUP:
            mmi_mte_example_screen_entry_rotated_popup();            
            break;

        case MMI_MTE_EXAMPLE_SCREEN_ROTATED_LIST:
            mmi_mte_example_screen_entry_rotated_list();
            break;            
    #endif /* __MMI_SCREEN_ROTATE__ */

        case MMI_MTE_EXAMPLE_SCREEN_PIN:
            /* PIN single line input */
            mmi_mte_example_screen_entry_PIN();
            break;

        case MMI_MTE_EXAMPLE_SCREEN_SYMBOL_PICKER:
            mmi_mte_example_screen_entry_symbol_picker();
            break;

        case MMI_MTE_EXAMPLE_SCREEN_RADIO_LIST:
            EntryPhnsetLang();
            break;

        case MMI_MTE_EXAMPLE_SCREEN_CHECK_LIST:
            mmi_mte_example_screen_entry_check_list();
            break;

        case MMI_MTE_EXAMPLE_SCREEN_MULTIROW_LIST:
            mmi_mte_example_screen_entry_multirow_list();
            break;

    #if defined(__MMI_IMPS__) || defined(__MMI_UCM__) || defined(__MMI_VOIP__)
        case MMI_MTE_EXAMPLE_SCREEN_TAB_LIST:
            g_mmi_mte_example_screen_tab_num = 3;
            mmi_mte_example_screen_entry_tab();
            break;

        case MMI_MTE_EXAMPLE_SCREEN_TAB_LIST_WITHOUT_TAB:
            g_mmi_mte_example_screen_tab_num = 0;
            mmi_mte_example_screen_entry_tab();
            break;
    #endif /* defined(__MMI_IMPS__) || defined(__MMI_UCM__) || defined(__MMI_VOIP__) */
    
        case MMI_MTE_EXAMPLE_SCREEN_TWOLINE_LIST:
            mmi_mte_example_screen_entry_twoline_list();
            break;

        case MMI_MTE_EXAMPLE_SCREEN_POPUP:
            mmi_mte_example_screen_entry_popup();
            break;           

    #if defined(UI_SMALL_LIST_SCREEN)        
        case MMI_MTE_EXAMPLE_SCREEN_SMALL_LIST:
            mmi_mte_example_screen_entry_small_list();
            break;
    #endif /* defined(UI_SMALL_LIST_SCREEN) */ 

    #if defined(__MMI_CASCADE_MENU__)
        case MMI_MTE_EXAMPLE_SCREEN_CASCADE_MENU:
            mmi_mte_example_screen_entry_cascade_menu();
            break;
    #endif /* defined(__MMI_CASCADE_MENU__) */        

        default:
            gdi_layer_unlock_frame_buffer();
            return 1;
    }

    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, 0, 0);

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_show_example_screen_by_group
 * DESCRIPTION
 *  Show the example screen by group index.
 * PARAMETERS
 *  group_index       [IN]  group index
 * RETURNS
 *  0: Success.
 *  1: Failure. Invalid group index.
 *****************************************************************************/
int mmi_mte_show_example_screen_by_group(int group_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((group_index < 0) || (group_index >= MMI_MTE_THEME_COMPONENT_GROUP_NUM))
    {
        return 1;
    }
    
    switch (group_index)
    {
        case MMI_MTE_GROUP_SCREEN_IDLE:
        case MMI_MTE_GROUP_CLOCK:
            mmi_mte_show_example_screen(MMI_MTE_EXAMPLE_SCREEN_IDLE);
            break;

        case MMI_MTE_GROUP_INPUTBOX_MULTITAP:
        case MMI_MTE_GROUP_INPUTBOX:
        case MMI_MTE_GROUP_INPUTBOX_KEYBOARD:
        case MMI_MTE_GROUP_INPUTBOX_IME:
            mmi_mte_show_example_screen(MMI_MTE_EXAMPLE_SCREEN_EDITOR);
            break;

        case MMI_MTE_GROUP_SCROLLBAR:
        case MMI_MTE_GROUP_TITLE:
        case MMI_MTE_GROUP_SUBMENU_LIST:
        case MMI_MTE_GROUP_SOFTKEY:
        case MMI_MTE_GROUP_STATUS_ICONS:
            mmi_mte_show_example_screen(MMI_MTE_EXAMPLE_SCREEN_LIST);
            break;

        case MMI_MTE_GROUP_SCREEN_SYMBOL_PICKER:        
        case MMI_MTE_GROUP_SUBMENU_MATRIX:
            mmi_mte_show_example_screen(MMI_MTE_EXAMPLE_SCREEN_SYMBOL_PICKER);
            break;

        case MMI_MTE_GROUP_INLINE_EDITOR:
            mmi_mte_show_example_screen(MMI_MTE_EXAMPLE_SCREEN_INLINE);
            break;

        case MMI_MTE_GROUP_MAIN_MENU_MATRIX:
        #if defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
        case MMI_MTE_GROUP_MAIN_MENU_BIDEGREE:
            mmi_mte_show_example_screen(MMI_MTE_EXAMPLE_SCREEN_BIDEGREE_MAIN_MENU);
        #elif defined(__MMI_MAINMENU_MATRIX_SUPPORT__)
            mmi_mte_show_example_screen(MMI_MTE_EXAMPLE_SCREEN_MATRIX_MAIN_MENU);
        #endif /* defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__) */              
            break;

        case MMI_MTE_GROUP_MAIN_MENU_CIRCULAR:
        #if defined(__MMI_MAINMENU_CIRCULAR_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
	        mmi_mte_show_example_screen(MMI_MTE_EXAMPLE_SCREEN_3D_CIRCULAR_MAIN_MENU);
        #endif /* defined(__MMI_MAINMENU_CIRCULAR_SUPPORT__) && defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__) */
            break;

        case MMI_MTE_GROUP_MAIN_MENU_LIST:        
        #if defined(__MMI_MAINMENU_LIST_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
            mmi_mte_show_example_screen(MMI_MTE_EXAMPLE_SCREEN_LIST_MAIN_MENU);
        #endif /* defined(__MMI_MAINMENU_LIST_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__) */
            break;

        case MMI_MTE_GROUP_COMMON:
            break;

        case MMI_MTE_GROUP_SCREEN_PIN_INPUT:
            mmi_mte_show_example_screen(MMI_MTE_EXAMPLE_SCREEN_PIN);
            break;

        case MMI_MTE_GROUP_SCREEN_CALLING:
            mmi_mte_show_example_screen(MMI_MTE_EXAMPLE_SCREEN_CALL);
            break;

        case MMI_MTE_GROUP_SCREEN_DIALER:
            mmi_mte_show_example_screen(MMI_MTE_EXAMPLE_SCREEN_DIALER);
            break;        

        case MMI_MTE_GROUP_CALENDAR:
        #ifdef __MMI_CALENDAR__ 
            mmi_mte_show_example_screen(MMI_MTE_EXAMPLE_SCREEN_CALENDAR);
        #endif /* __MMI_CALENDAR__ */
            break;

        case MMI_MTE_GROUP_TAB:
        #if defined(__MMI_IMPS__) || defined(__MMI_UCM__) || defined(__MMI_VOIP__)        
            mmi_mte_show_example_screen(MMI_MTE_EXAMPLE_SCREEN_TAB_LIST);
        #endif /* defined(__MMI_IMPS__) || defined(__MMI_UCM__) || defined(__MMI_VOIP__) */
            break;

        case MMI_MTE_GROUP_SCREEN_POPUP:
            mmi_mte_show_example_screen(MMI_MTE_EXAMPLE_SCREEN_POPUP);
            break;
        
        case MMI_MTE_GROUP_SCREEN_ROTATED:
        #if defined(__MMI_SCREEN_ROTATE__)        
             mmi_mte_show_example_screen(MMI_MTE_EXAMPLE_SCREEN_ROTATED_LIST);
        #endif /* defined(__MMI_SCREEN_ROTATE__) */
            break;

        case MMI_MTE_GROUP_SCREEN_SMALL_MENU:
        #if defined(UI_SMALL_LIST_SCREEN)        
             mmi_mte_show_example_screen(MMI_MTE_EXAMPLE_SCREEN_SMALL_LIST);
        #endif /* defined(UI_SMALL_LIST_SCREEN) */      
            break;

        case MMI_MTE_GROUP_SUBMENU_CASCADE:
        #if defined(__MMI_CASCADE_MENU__)
            mmi_mte_show_example_screen(MMI_MTE_EXAMPLE_SCREEN_CASCADE_MENU);
        #endif /* defined(__MMI_CASCADE_MENU__) */
            break;
        
        default:
            break;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_set_image_source
 * DESCRIPTION
 *  Get the image resource name by the full-path filename under the image resource folder.
 * PARAMETERS
 *  use_image_folder       [IN]     0: use system images. 1: use local image files located 'folder_path'
 *  folder_path            [IN]     the path containing local image files
 * RETURNS
 *  0: Success.
 *  1: Cannot open <folder_path>
 *****************************************************************************/
int mmi_mte_set_image_source(int use_image_folder, const char *folder_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8      tmp_file_path[MMI_MTE_MAX_PATH_LEN];
    FILE    *fp;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (use_image_folder == 0)
    {
        g_mmi_mte_image_folder_path = NULL;
    }
    else
    {   
        /* 
         * Check the folder path validity by a dirty trick to invoke 
         * ANSI C FILE I/O functions only...Of course, not workable on the target.
         */
        /* The STAMP file is named as "_REMOVE_ME_" under the target folder. */
        tmp_file_path[MMI_MTE_MAX_PATH_LEN - 15 - 1] = 0;
        strncpy(tmp_file_path, folder_path, MMI_MTE_MAX_PATH_LEN - 15 - 1);
        strcat(tmp_file_path, "\\_REMOVE_ME_");
       
        if ((fp = fopen(tmp_file_path, "w")) == NULL)
        {
            return 1;
        }

        fclose(fp);

        /* remove the STAMP file */
        remove(tmp_file_path);

        g_mmi_mte_image_folder_path = (U8*)folder_path;        
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_image_resource_total_size
 * DESCRIPTION
 *  Get the total size of image resource.
 * PARAMETERS
 *  in_local_folder       [IN]      0: the size of system images. 1: the size of local image files located 'folder_path'
 * RETURNS
 *  The total size of all images in byte; return 0 if local folder path was not 
 *  initialized by mmi_mte_set_image_source().
 *****************************************************************************/
int mmi_mte_get_image_resource_total_size(int in_local_folder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i;
    S32     total_size;
    U8      file_path[MMI_MTE_MAX_PATH_LEN];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (in_local_folder == 0)
    {
        return MMI_MTE_SYSTEM_IMAGE_RESOURCE_SIZE;
    }

    if (g_mmi_mte_image_folder_path == NULL)
    {
        return 0;
    }

    total_size = 0;
    
    for (i = 0; i < MMI_MTE_SYSTEM_IMAGE_RESOURCE_NUM; i++)
    {        
        if (g_mmi_mte_img_resource[i].path && (g_mmi_mte_img_resource[i].size > 0))
        {
            _snprintf(file_path, MMI_MTE_MAX_PATH_LEN - 1, "%s\\%s", g_mmi_mte_image_folder_path, g_mmi_mte_img_resource[i].path);        
            total_size += mmi_mte_get_file_size(file_path) + 8; /* plus 8-byte resource header */
        }
    }        

    return total_size;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_set_language
 * DESCRIPTION
 *  Set the MTE language.
 * PARAMETERS
 *  language_id       [IN]      0: English. 1: Simplified Chinese
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mte_set_language(int language_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i;
    S32     theme_component_num;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (language_id >= MMI_MTE_LANGUAGE_NUM)
    {
        return;    
    }
    
    g_mmi_mte_language_id = language_id;

    /* switch string pointer arrays */
    g_mmi_mte_example_screen_name = g_mmi_mte_language[language_id].example_screen_name;
    g_mmi_mte_theme_component_description = g_mmi_mte_language[language_id].theme_component_description;
    g_mmi_mte_theme_component_group_name = g_mmi_mte_language[language_id].theme_component_group_name;
    
    /* replace theme component descriptions with the specified language  */
    theme_component_num = mmi_mte_get_theme_component_num();
    for (i = 0; i < theme_component_num; i++)
    {
        g_mmi_mte_theme_component_info[i].description = (char*)g_mmi_mte_theme_component_description[i];
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_welcome_string
 * DESCRIPTION
 *  Prompt some messages to users about the theme to be edited. 
 * PARAMETERS
 *  theme       [IN]    mmi theme
 * RETURNS
 *  String to be displayed in the welcome screen. If the string is null, do not show the welcome screen.
 *****************************************************************************/
const char *mmi_mte_get_welcome_string(const MMI_theme *theme)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return NULL;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_image_header
 * DESCRIPTION
 *  Get the 8-byte image resource header.
 * PARAMETERS
 *  header           [IN]   output header buffer
 *  image_type       [IN]   image type
 *  width            [IN]   image width
 *  height           [IN]   image height
 *  size             [IN]   image size (not including the 8-byte header)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mte_get_image_header(char *header, mmi_mte_image_enum image_type, int width, int height, int size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_mte_make_resource_header(
        (PU8)header,
        mmi_mte_translate_image_type_from_mte_to_gdi(image_type),
        width,
        height,
        size);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_image_data_length
 * DESCRIPTION
 *  Get the image resource size.
 * PARAMETERS
 *  image_ptr       [IN]    image data
 * RETURNS
 *  The size of the image data in bytes plus 8 (the 8-byte header)
 *****************************************************************************/
int mmi_mte_get_image_data_length(char *image_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8      *data_ptr;
    U8      img_type;
    S32     img_size;
    S32     frame_number;
    S32     width;
    S32     height;
    GDI_RESULT  ret;
            
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = gdi_image_parse_info(
            GDI_IMAGE_SRC_FROM_RESOURCE,
            image_ptr,
            &data_ptr,
            &img_type,
            &img_size,
            &frame_number,
            &width,
            &height);

    if (ret != GDI_SUCCEED)
    {
        return 0;
    }

    return img_size + 8;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_set_state
 * DESCRIPTION
 *  Set the MTE current state.
 * PARAMETERS
 *  state       [IN]    MTE state
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mte_set_state(mmi_mte_state_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_mte_state = state;
}


/*
 * MMI interface API
 */

/*****************************************************************************
 * FUNCTION
 *  mmi_mte_is_active
 * DESCRIPTION
 *  Checks if the MTE is active.
 * PARAMETERS
 *  void
 * RETURNS
 *  0: Inactive.
 *  1: Active. 
 *****************************************************************************/
S32 mmi_mte_is_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (S32)g_mmi_mte_state;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_is_resource_replacement_working
 * DESCRIPTION
 *  Checks if the resource replacement is enabled.
 * PARAMETERS
 *  void
 * RETURNS
 *  0: Disabled.
 *  1: Enabled.
 *****************************************************************************/
S32 mmi_mte_is_resource_replacement_working(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_mte_image_folder_path)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_mmi_notify_screen_switch
 * DESCRIPTION
 *  Screen switch notification from MMI.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mte_mmi_notify_screen_switch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_mte_switch_screen_callback)
    {   
        /* 
         * cancel the screen switch timer from mmi_mte_mmi_notify_new_screen() to
         * prevent the category show function from refreshing again.
         */
        gui_cancel_timer(mmi_mte_mmi_notify_screen_switch);

        OSC_Sys_Schedule_Enable(0);
        g_mmi_mte_switch_screen_callback();
        OSC_Sys_Schedule_Enable(1);           
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_mmi_notify_new_screen
 * DESCRIPTION
 *  EntryNewScreen notification from MMI.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mte_mmi_notify_new_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_mte_switch_screen_callback)
    {   
        gui_start_timer(0, mmi_mte_mmi_notify_screen_switch);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_image_resource_buffer_by_id
 * DESCRIPTION
 *  Loads the image resource from the file and returns the buffer pointer 
 *  for a specific image resource ID.
 * PARAMETERS
 *  image_id       [IN] image resource ID
 * RETURNS
 *  Image buffer pointer
 *****************************************************************************/
U8 *mmi_mte_get_image_resource_buffer_by_id(U32 image_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i;
    U8      file_path[MMI_MTE_MAX_PATH_LEN];
    S32     resource_size;
    U8      *img_buf;
    U8      *old_resource_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_MTE_SYSTEM_IMAGE_RESOURCE_NUM; i++)
    {        
        if (g_mmi_mte_img_resource[i].id == image_id)
        {
            if (g_mmi_mte_img_resource[i].path == NULL)
            {
                MTE_DEBUG("%d %s PATH NULL!\n", image_id, file_path);
                return NULL;
            }
            
            _snprintf(file_path, MMI_MTE_MAX_PATH_LEN - 1, "%s\\%s", g_mmi_mte_image_folder_path, g_mmi_mte_img_resource[i].path); 
            if (mmi_mte_load_image_resource_from_file(file_path, &resource_size) == 1)
            {
                MTE_DEBUG("%d %s NOT FOUND!\n", image_id, file_path);
                return NULL;
            }
            else
            {               
                i = mmi_mte_search_resource_mapping_table_by_id(image_id);
                
                if (i == -1)
                {   /* add a new entry */
                    if ((img_buf = mmi_mte_allocate_image_buffer(resource_size, (U8*)g_mmi_mte_image_buffer)) == NULL)
                    {
                        return NULL;
                    }
                    
                    g_mmi_mte_res_map_table[g_mmi_mte_resource_mapping_table_count].buf = img_buf;
                    g_mmi_mte_res_map_table[g_mmi_mte_resource_mapping_table_count].id = image_id;
                    g_mmi_mte_resource_mapping_table_count++;                    
                }               
                else
                {   /* replace an old entry */
                    old_resource_ptr = g_mmi_mte_res_map_table[i].buf;

                    /* 
                     * Allocate new buffer for the existing resource only if it is changed.
                     * This is a workaround for screens keeping pointers to image resources, such as the main menu.
                     */                                       
                    if (old_resource_ptr)
                    {
                        if ((mmi_mte_get_image_resource_size(old_resource_ptr) == resource_size - 8) &&
                            !memcmp(old_resource_ptr, g_mmi_mte_image_buffer, resource_size))
                        {                            
                            return old_resource_ptr;
                        }
                        
                        MTE_FREE(old_resource_ptr);
                    }

                    if ((img_buf = mmi_mte_allocate_image_buffer(resource_size, (U8*)g_mmi_mte_image_buffer)) == NULL)
                    {
                        return NULL;
                    }
                    
                    g_mmi_mte_res_map_table[i].buf = img_buf;                    
                }

                return img_buf;
            }
        }
    }        

    return NULL;   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_value
 * DESCRIPTION
 *  Gets MTE system variables.
 * PARAMETERS
 *  name       [IN]     system variable name
 * RETURNS
 *  The specified MTE system variable value.
 *****************************************************************************/
void *mmi_mte_get_value(mmi_mte_system_value_enum name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((name >= 0) && (name < MMI_MTE_SYSTEM_VALUE_NUM));
    
    return g_mmi_mte_system_variable[name];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_set_value
 * DESCRIPTION
 *  Set the MTE system variable.
 * PARAMETERS
 *  name        [IN]    system varaible name
 *  value       [IN]    system variable value
 * RETURNS
 *  0: Successful.
 *  1: Failed.
 *****************************************************************************/
int mmi_mte_set_value(mmi_mte_system_value_enum name, void *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32         str_len;
    void        *var;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((name >= 0) && (name < MMI_MTE_SYSTEM_VALUE_NUM));

    switch (name)
    {
        case MMI_MTE_SYSTEM_VALUE_CONVERT_EXE_PATH:
        case MMI_MTE_SYSTEM_VALUE_TEMP_PATH:
            /* make sure the string length does not exceed the 1024 limitation */
            str_len = strlen(value);
            if (str_len > MMI_MTE_MAX_PATH_LEN)
            {
                return 1;
            }

            var = mmi_mte_get_value(name);
            if (var)
            {
                MTE_FREE(var);         
            }

            var = MTE_ALLOC(str_len + 1);
            g_mmi_mte_system_variable[name] = var;
            
            strcpy(var, value);
            break;
    
        default:
            break;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_encode_abm_image
 * DESCRIPTION
 *  Encodes a PNG or BMP image to an ABM image.
 * PARAMETERS
 *  mode                       [IN]     ABM encoder mode
 *  input_image_type           [IN]     input image type
 *  input_filename             [IN]     input filename
 *  output_abm_bitstream       [IN/OUT] output file name or output buffer
 *  output_size                [IN/OUT] output size in bytes
 * RETURNS
 *  MMI_MTE_ABMENC_NO_ERROR: success
 *  MMI_MTE_ABMENC_INPUT_TYPE_ERROR: only support BMP and PNG input
 *  MMI_MTE_ABMENC_PNG_CONVERT_ERROR: convert PNG to BMP by convert.exe error
 *  MMI_MTE_ABMENC_ABM_ENCODE_ERROR: convert BMP to ABM error
 *  MMI_MTE_ABMENC_OUTPUT_ABM_FILE_ERROR: output ABM file error
 *  MMI_MTE_ABMENC_OUTPUT_BUFFER_OVERFLOW: Output size is more than given. (only in MMI_MTE_ABMENC_MODE_OUTPUT_MEM mode)
 *****************************************************************************/
mmi_mte_abm_encoder_error_enum mmi_mte_encode_abm_image(mmi_mte_abmenc_mode_enum mode, mmi_mte_image_enum input_image_type, char *input_filename, char *output_abm_bitstream, int *output_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     ret;
    S32     w, h;
    PU8     abm_buf_p;

    S8      *output_abm_filename;
    S8      command_line_str[MMI_MTE_MAX_PATH_LEN * 3];    
    S8      temp_filename[MMI_MTE_MAX_PATH_LEN];
    FILE    *fp;
    S32     output_buffer_limit_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    output_buffer_limit_size = *output_size;
        
    /* only accept BMP and PNG input formats */
    if ((input_image_type != MMI_MTE_IMAGE_BMP_TO_ABM) && (input_image_type != MMI_MTE_IMAGE_PNG_TO_ABM))
    {
        return MMI_MTE_ABMENC_INPUT_TYPE_ERROR;
    }

    /* use convert.exe to convert PNG to BMP first */
    if (input_image_type == MMI_MTE_IMAGE_PNG_TO_ABM)
    {        
        temp_filename[MMI_MTE_MAX_PATH_LEN - 1] = 0;
        _snprintf(temp_filename, MMI_MTE_MAX_PATH_LEN - 1, "%s%s", mmi_mte_get_value(MMI_MTE_SYSTEM_VALUE_TEMP_PATH), MMI_MTE_ABM_TEMP_FILENAME);    
        _snprintf(
            command_line_str, 
            MMI_MTE_MAX_PATH_LEN * 3 - 1, 
            "\"\"%s\" -channel Alpha -negate png:\"%s\" bmp:\"%s\"\"", 
            mmi_mte_get_value(MMI_MTE_SYSTEM_VALUE_CONVERT_EXE_PATH), 
            input_filename, 
            temp_filename);

        /* change input filename to the converted temp filename */            
        input_filename = temp_filename;

        if (system(command_line_str))
        {
            return MMI_MTE_ABMENC_PNG_CONVERT_ERROR;
        }
    }

    output_abm_filename = output_abm_bitstream;
    w = h = 0;
    abm_buf_p = (PU8)g_mmi_mte_image_buffer;    

    ret = ABM_load(
            (PU8)input_filename,
            __MMI_DEVICE_BMP_FORMAT__,
            (U8)(input_image_type == MMI_MTE_IMAGE_PNG_TO_ABM ? IMAGE_TYPE_PNG : IMAGE_TYPE_BMP),
            abm_buf_p,
            output_size,
            &w,
            &h);    

    /* remove the temporary BMP file */
    if (input_image_type == MMI_MTE_IMAGE_PNG_TO_ABM)
    {
        remove(temp_filename);
    }

    /* ABM encoder failure */
    if ((w == 0) && (h == 0) || (ret == ABM_ENC_RETURN_KEEP_ORIGINAL))
    {
        return MMI_MTE_ABMENC_ABM_ENCODE_ERROR;
    }

    /* file output mode, save the bitstream to the output file */
    if (mode == MMI_MTE_ABMENC_MODE_OUTPUT_FILE)
    {
        if ((fp = fopen(output_abm_filename, "wb")) == NULL)
        {
            return MMI_MTE_ABMENC_OUTPUT_ABM_FILE_ERROR;
        }
       
        if (fwrite(abm_buf_p, *output_size, 1, fp) != 1)
        {
            fclose(fp);
            
            return MMI_MTE_ABMENC_OUTPUT_ABM_FILE_ERROR;
        }

        fclose(fp);            
    }
    else
    {
        if (*output_size > output_buffer_limit_size)
        {
            return MMI_MTE_ABMENC_OUTPUT_BUFFER_OVERFLOW;
        }
    
        /* buffer output mode, simply memcpy */
        memcpy(output_abm_bitstream, abm_buf_p, *output_size);
    }

    return MMI_MTE_ABMENC_NO_ERROR;
}


#else /* __MTK_TARGET__ */

/* avoid the target compilation warning */
char g_mmi_mte_avoid_warning;

#endif /* __MTK_TARGET__ */


