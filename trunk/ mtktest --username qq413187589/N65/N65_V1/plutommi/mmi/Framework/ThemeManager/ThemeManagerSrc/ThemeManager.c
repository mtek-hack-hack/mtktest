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
 * ThemeManager.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is the source file for Theme Manager.
 *
 * Author:
 * -------
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/*  Include: MMI header file */
#include "MMI_features.h"
#include "stdC.h"
#include "L4Dr.h"
#include "MMIDatatype.h"
#include "GlobalDefs.h"
#include "GlobalScrEnum.h"
#include "Unicodexdcl.h"
#include "frameworkGprot.h"
#include "frameworkProt.h"
#include "gui.h"
#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "DebugInitDef.h"
#include "MMIThemes.h"
#include "FunAndGamesDefs.h"
#include "gui_themes.h"
#include "drm_gprot.h"
#include "SimDetectionGexdcl.h"
#include "PhoneBookDef.h"
#include "ProtocolEvents.h"
#include "xml_def.h"
#include "FileMgr.h"
#include "FileManagerDef.h"
#include "FileManagerGProt.h"
#include "MyPicture.h"
#include "commonscreens.h"
#include "poweronoffdisplaydefs.h"
#include "mmi_phnset_dispchar.h"
#include "Conversions.h"
#include "PhoneSetupGprots.h"
#include "SettingProfile.h"
#include "ProfileGprots.h"
#include "JavaAgencyDef.h"
#include "ExtDeviceDefs.h"
#include "app_crc.h"

/***************************************************************************** 
* Define
*****************************************************************************/

#define NVRAM_EF_THEME_MANAGER_RECORD_TOTAL 1

/* cache size */
#if defined(__MMI_DLT_CACHE_SUPPORT__)
    #define DLT_LOAD_ALWAYS_CACHE_SIZE      ((__DLT_ALWAYS_LOAD_BUFFER_SIZE__) * 1024)
    #define DLT_LOAD_ON_DEMAND_CACHE_SIZE   ((__DLT_LOAD_ON_DEMAND_BUFFER_SIZE__) * 1024)
#endif /* __MMI_DLT_CACHE_SUPPORT__ */ 

/* File buffer size for input to crc check */
#define TM_FILE_BUFF_SIZE    512


/***************************************************************************** 
* Typedef 
*****************************************************************************/
/***************************************************************************** 
* Local Variable
*****************************************************************************/

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
static MMI_BOOL g_tm_was_theme_alarm_cb = MMI_FALSE;    /* Was there a theme alarm expiry when usb was plugged in */
#endif
/***************************************************************************** 
* Local Function
*****************************************************************************/

/***************************************************************************** 
* Global Variable
*****************************************************************************/
theme_details_struct g_tm_activated_theme;
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
static tm_context_struct g_tm_cntx;
__align(4)
static tm_theme_list_struct g_tm_theme_list[TOTAL_THEMES_COUNT];
static U8 g_tm_theme_image_dirty_bits[(MAX_MMI_IMAGEID_IMAGES / 8) + 1];
__align(4)
static tm_theme_list_struct g_tm_NvramThmArr[MAX_DOWNLOADED_THEMES];
static BOOL g_tm_USB_mode = FALSE;
#endif   /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */

#if (defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__))
#if (defined(__MMI_DLT_CACHE_SUPPORT__))
static U8 g_tm_load_always_cache[DLT_LOAD_ALWAYS_CACHE_SIZE];
static U8 g_tm_load_ondemand_cache[DLT_LOAD_ON_DEMAND_CACHE_SIZE];
static U32 g_tm_load_always_offset = 0;
static U32 g_tm_load_ondemand_offset = 0;
#endif /* (defined(__MMI_DLT_CACHE_SUPPORT__)) */ 
/***************************************************************
Start Supported Theme version Table
***************************************************************/
FLOAT g_tm_supported_thm_version_table[MAX_SUPPORTED_VERSION_NUM] = 
{
    3.0
};

/***************************************************************
End of Supported Theme version Table
***************************************************************/
U16 g_tm_checkThemeVersion; /* Variable check for theme versioning */
extern U16 mmi_ta_check_theme_file_version_compatibility(FLOAT theme_version);
extern U16 mmi_ta_check_theme_file_lcd_dim_compatibiltiy(U32 lcd_width, U32 lcd_height);
extern BOOL PhnsetIsWPCurrentTheme(void);
extern BOOL PhnsetIsScrSvrCurrentTheme(void);
extern void ThemeManagerSetWallpaper(U16);
extern void ThemeManagerSetScreensaver(U16);
extern XML_PARSER_STRUCT g_tc_parser;
extern tc_deviceinfo_struct g_tc_deviceInfo;
extern tc_theme_download_info_struct g_tc_themeInfo;
extern DYNAUDIOINFO gDwnlThmToneInfo[MAXIMUM_THEMES_TONES];
static U16 gVirAudFileNameList[MAXIMUM_THEMES_TONES][FS_GenVFN_SIZE + 8];
#endif /* (defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__)) */ 

extern oslMsgqid mmi_ext_qid;
extern MMI_BOOL g_keypad_flag;
extern drv_get_key_func keypad_ptr;
extern theme_details_struct *MMI_themes;

extern void SetThemes(U8 index);
extern void initialize_status_icons(void);

/* PMT DLT_FIXES - TK 20060321 START */
extern S32 GetThemesNames(U8 **dest[]);

/* PMT DLT_FIXES - TK 20060321 END */
extern U8 g_tc_audiothmfileformat;
void mmi_dispchar_get_img_id(U8 nDataItemId, U16 *pBuffer);

/***************************************************************************** 
* Global Function
*****************************************************************************/

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  mmi_tm_create_image_header_pool
 * DESCRIPTION
 *  This function is for initializing image header buffer
 * PARAMETERS
 *  ds_p                [?]             
 *  mempool_p           [?]             
 *  unit_size           [IN]            
 *  total_pool_size     [IN]            
 *  a(?)                [IN/OUT]        First variable, used as returns
 *  b(?)                [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_tm_create_image_header_pool(
        tm_theme_image_header_struct *ds_p,
        void *mempool_p,
        U16 unit_size,
        U32 total_pool_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ds_p->mempool_p = mempool_p;
    ds_p->current_offset = 0;
    ds_p->unit_size = unit_size;
    ds_p->total_pool_size = total_pool_size;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_reset_imageid_image_header_pool
 * DESCRIPTION
 *  this function resets the image header pool buffer for images with IDs
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_tm_reset_imageid_image_header_pool(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_tm_reset_image_header_pool(&(g_tm_cntx.imageid_images_headers));
    memset(&g_tm_cntx.image_cache, 0xFF, sizeof(g_tm_cntx.image_cache));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_reset_non_imageid_image_header_pool
 * DESCRIPTION
 *  this function resets the image header pool buffer for images without IDs
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_tm_reset_non_imageid_image_header_pool(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_tm_reset_image_header_pool(&(g_tm_cntx.non_imageid_images_headers));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_reset_image_header_pool
 * DESCRIPTION
 *  this function resets the image header pool buffer
 * PARAMETERS
 *  ds_p        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_tm_reset_image_header_pool(tm_theme_image_header_struct *ds_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ds_p->current_offset = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_add_image_header_to_pool
 * DESCRIPTION
 *  this function adds image header to pool buffer
 * PARAMETERS
 *  ds_p        [?]     
 *  buff        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void *mmi_tm_add_image_header_to_pool(tm_theme_image_header_struct *ds_p, void *buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *temp_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((ds_p->current_offset + ds_p->unit_size) > ds_p->total_pool_size)
    {
        return NULL;
    }
    else
    {
        memcpy((ds_p->mempool_p + ds_p->current_offset), buff, ds_p->unit_size);
        temp_ptr = ds_p->mempool_p + ds_p->current_offset;
        ds_p->current_offset += ds_p->unit_size;
        return temp_ptr;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_get_downloaded_theme_image
 * DESCRIPTION
 *  It returns downloadable theme image pointer
 * PARAMETERS
 *  image_offset        [IN]        
 *  nArrIndex           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *mmi_tm_get_downloaded_theme_image(U32 image_offset, S32 nArrIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 size;
    void *image_p;
    U8 buff[MAX_THEME_IMAGE_HEADER_LENGTH] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (FS_ParseFH(g_tm_cntx.theme_file_handle) >= 0)
    {
        if (g_tm_cntx.image_cache[nArrIndex].nOffset != -1)
        {
            return (void*)((S8*) g_tm_cntx.imageid_images_headers.mempool_p +
                            g_tm_cntx.image_cache[nArrIndex].nOffset);
        }

        if (DRM_seek_file(g_tm_cntx.theme_file_handle, image_offset, FS_FILE_BEGIN) >= 0 )
        {
            if (DRM_read_file(g_tm_cntx.theme_file_handle, buff, THEME_IMAGE_INFO_HEADER, (U32*) & size) !=
                FS_NO_ERROR)
            {
  	  	 	   mmi_tm_handle_file_access_failed();
  		       return NULL;
            }
        }
        else
        {
 	      mmi_tm_handle_file_access_failed();
  	      return NULL;
        }


        /* offset in next 4 bytes */
        buff[8] = (U8) (image_offset & 0x000000ff);
        buff[9] = (U8) ((image_offset >> 8) & 0x000000ff);
        buff[10] = (U8) ((image_offset >> 16) & 0x000000ff);
        buff[11] = (U8) ((image_offset >> 24) & 0x000000ff);

        /* file handle in next 4 bytes */
        buff[12] = (U8) (g_tm_cntx.theme_file_handle & 0x000000ff);
        buff[13] = (U8) ((g_tm_cntx.theme_file_handle >> 8) & 0x000000ff);
        buff[14] = (U8) ((g_tm_cntx.theme_file_handle >> 16) & 0x000000ff);
        buff[15] = (U8) ((g_tm_cntx.theme_file_handle >> 24) & 0x000000ff);

        image_p = mmi_tm_add_image_header_to_pool(&(g_tm_cntx.imageid_images_headers), buff);
        if (image_p)
        {
            g_tm_cntx.image_cache[nArrIndex].nOffset =
                (U16) ((S8*) image_p - (S8*) g_tm_cntx.imageid_images_headers.mempool_p);
            return image_p;
        }
    }

    return GetDefaultImage();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_check_theme_file_phone_model_compatibility
 * DESCRIPTION
 *  validates Theme Phone Model.
 * PARAMETERS
 *  theme_phone_model       [IN]        
 * RETURNS
 *  true if compatible otherwise false
 *****************************************************************************/
U16 mmi_tm_check_theme_file_phone_model_compatibility(PS8 theme_phone_model)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strncmp(theme_phone_model, mmi_get_phone_model(), MAX_MODEL_ID_LEN))
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_theme_version_and_deviceinfo_check
 * DESCRIPTION
 *  It checks theme version and deviceinfo in DLT file(.med)
 * PARAMETERS
 *  theme_struct_p      [?]     
 * RETURNS
 *  true  : if successfully checks,
 *  false : if unable to check
 *****************************************************************************/
BOOL mmi_tm_theme_version_and_deviceinfo_check(tm_theme_list_struct *theme_struct_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 theme_file_name[(MAX_DWNL_THM_PATH_LEN + MAX_THEME_NAME_LENGTH) * ENCODING_LENGTH] = {0};
    U8 tmp_path[50] = {0};
    FS_HANDLE tmp_theme_file_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_tm_checkThemeVersion = TRUE;
    if (theme_struct_p->theme_type == THEME_TYPE_DOWNLOADED_PHONE)
    {
        sprintf((PS8) tmp_path, "%c%s", MMI_PUBLIC_DRV, DOWNLOADED_THEMES_PATH);
        mmi_asc_to_ucs2((PS8) theme_file_name, (PS8) tmp_path);
    }
    else
    {
        sprintf((PS8) tmp_path, "%c%s", MMI_CARD_DRV, DOWNLOADED_THEMES_PATH);
        mmi_asc_to_ucs2((PS8) theme_file_name, (PS8) tmp_path);
    }
    mmi_ucs2cat((PS8) theme_file_name, (PS8) theme_struct_p->theme_name);

    //      last_theme_file_handle = g_tm_cntx.theme_file_handle;
    //tmp_theme_file_handle = DRM_open_file((U16*)theme_file_name, FS_READ_ONLY, 0/*DRM_PERMISSION_NONE*/); 
    tmp_theme_file_handle = DRM_open_file((U16*) theme_file_name, FS_READ_ONLY | FS_OPEN_SHARED, 0);

    if (tmp_theme_file_handle < FS_NO_ERROR)
    {
        return FALSE;
    }

    if (xml_new_parser(&g_tc_parser) == -1)
    {
        return FALSE;
    }
    xml_register_element_handler(&g_tc_parser, mmi_tc_my_xml_elem_start_hdlr, mmi_tc_my_xml_elem_end_hdlr);
    /* PMT DLT_FIXES - TK 20060321 START */
    g_tc_parser.pos = THEME_FILE_SIZE_HEADER + THEME_CHECKSUM_HEADER_SIZE;
    /* PMT DLT_FIXES - TK 20060321 END */
    xml_parse_file_from_offset(&g_tc_parser, tmp_theme_file_handle);

    DRM_close_file(tmp_theme_file_handle);
    g_tm_checkThemeVersion = FALSE;
    if (mmi_ta_check_theme_file_version_compatibility((FLOAT) g_tc_themeInfo.version))
    {
        return TRUE;
    }
    return FALSE;
}

#ifdef __MMI_DLT_CACHE_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_clear_ondemand_cache
 * DESCRIPTION
 *  clears the ondemand cache by clearing pointer and making offset as zero
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_tm_clear_ondemand_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (g_tm_load_ondemand_offset && count < g_tm_cntx.theme_imageid_image_count)
    {
        if (g_tm_cntx.theme_image_list[count].image_type == THEME_IMG_LOAD_ONDEMAND)
        {
            g_tm_cntx.theme_image_list[count].image_cache_ptr = NULL;
        }
        ++count;
    }
    g_tm_load_ondemand_offset = 0;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_get_image_load_type
 * DESCRIPTION
 *  To determine the load type of an image
 * PARAMETERS
 *  img_list_index      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
tm_image_load_type_enum mmi_tm_get_image_load_type(U32 img_list_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_tm_cntx.theme_image_list[img_list_index].image_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_find_img_in_cache
 * DESCRIPTION
 *  returns image pointer
 * PARAMETERS
 *  img_list_index      [IN]        
 *  type                [IN]        
 * RETURNS
 *  
 *****************************************************************************/
PU8 mmi_tm_find_img_in_cache(U32 img_list_index, tm_image_load_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_tm_cntx.theme_image_list[img_list_index].image_cache_ptr;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_add_to_DLT_img_cache
 * DESCRIPTION
 *  add an image to image cache
 * PARAMETERS
 *  image_offset        [IN]        
 *  img_load_type       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
PU8 mmi_tm_add_to_DLT_img_cache(U32 image_offset, tm_image_load_type_enum img_load_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 size;
    U32 fp;
    U8 buff[MAX_THEME_IMAGE_HEADER_LENGTH] = {0};
    S32 image_file_size;
    S32 dlt_img_cache_size;
    PU8 image_buff;
    PU32 cache_offset;
    PU8 cache_ptr;
	PU8 p_img_ret=NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ( FS_GetFilePosition(g_tm_cntx.theme_file_handle, &fp) != FS_NO_ERROR )
    {
        mmi_tm_handle_file_access_failed();
        return NULL;
    }

    if( DRM_seek_file(g_tm_cntx.theme_file_handle, image_offset, FS_FILE_BEGIN) >= 0)
    {
        if ( DRM_read_file(g_tm_cntx.theme_file_handle, buff, THEME_IMAGE_INFO_HEADER, (U32*) & size) != FS_NO_ERROR )
        {
            mmi_tm_handle_file_access_failed();
            return NULL;
        }
    }
    else
    {
        mmi_tm_handle_file_access_failed();
        return NULL;
    }

    image_file_size = (U8) buff[4];
    image_file_size = (image_file_size << 8) | (U8) buff[3];
    image_file_size = (image_file_size << 8) | (U8) buff[2];

    switch (img_load_type)
    {
        case THEME_IMG_LOAD_ALWAYS:
            cache_ptr = g_tm_load_always_cache;
            cache_offset = &g_tm_load_always_offset;
            dlt_img_cache_size = DLT_LOAD_ALWAYS_CACHE_SIZE;
            break;
        case THEME_IMG_LOAD_ONDEMAND:
        default:
            cache_ptr = g_tm_load_ondemand_cache;
            cache_offset = &g_tm_load_ondemand_offset;
            dlt_img_cache_size = DLT_LOAD_ON_DEMAND_CACHE_SIZE;
    }

    /* 4-byte algin */
    if (((U32) cache_ptr + *cache_offset) % 4)
    {
        *cache_offset += 4 - (((U32) cache_ptr + *cache_offset) % 4);
    }
    image_buff = cache_ptr + *cache_offset;

    /* Refer gdi_image_parse_resource_internal() in Gdi_image.c for header format information */
    if (buff[0] == GDI_IMAGE_TYPE_BMP_FILE_OFFSET || 
        buff[0] == GDI_IMAGE_TYPE_GIF_FILE_OFFSET || 
        buff[0] == GDI_IMAGE_TYPE_JPG_FILE_OFFSET ||
        buff[0] == GDI_IMAGE_TYPE_ABM_FILE_OFFSET ||
        buff[0] == GDI_IMAGE_TYPE_PNG_FILE_OFFSET)
    {
        if ((*cache_offset + image_file_size + 8) > dlt_img_cache_size) /* 8 extra bytes for internal Header */
        {
            if ( DRM_seek_file(g_tm_cntx.theme_file_handle, fp, FS_FILE_BEGIN) < 0)
            {
                mmi_tm_handle_file_access_failed();
            }
            return NULL;
        }
        image_buff[1] = buff[1];
        image_buff[2] = buff[2];
        image_buff[3] = buff[3];
        image_buff[4] = buff[4];
        image_buff[5] = buff[5];
        image_buff[6] = buff[6];
        image_buff[7] = buff[7];

		/* change image type since we load data from file to cache */
        switch (buff[0])
        {
            case GDI_IMAGE_TYPE_GIF_FILE_OFFSET:
                image_buff[0] = GDI_IMAGE_TYPE_GIF;
                break;

            case GDI_IMAGE_TYPE_BMP_FILE_OFFSET:
                image_buff[0] = GDI_IMAGE_TYPE_BMP;
                break;

            case GDI_IMAGE_TYPE_JPG_FILE_OFFSET:
                image_buff[0] = GDI_IMAGE_TYPE_JPG;
                break;

            case GDI_IMAGE_TYPE_ABM_FILE_OFFSET:
                image_buff[0] = GDI_IMAGE_TYPE_ABM;
                break;

            case GDI_IMAGE_TYPE_PNG_FILE_OFFSET:
                image_buff[0] = GDI_IMAGE_TYPE_PNG;
                break;

            default:
				break;
        }
        p_img_ret = image_buff;
    }

	/* load data to cache from file */
	if (p_img_ret != NULL)
    {
        if ( DRM_read_file(g_tm_cntx.theme_file_handle, image_buff + 8, image_file_size, (U32*) & size) != FS_NO_ERROR )
    {
            mmi_tm_handle_file_access_failed();
            return NULL;
        }

        *cache_offset += (image_file_size + 8); /* 8 extra bytes for Header */
    }

    if ( DRM_seek_file(g_tm_cntx.theme_file_handle, fp, FS_FILE_BEGIN) < 0)
    {
        mmi_tm_handle_file_access_failed();
        return NULL;
    }
	return p_img_ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_add_img_id_to_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  img_list_index      [IN]        
 *  image_offset        [IN]        
 *  type                [IN]        
 * RETURNS
 *  
 *****************************************************************************/
PU8 mmi_tm_add_img_id_to_cache(U32 img_list_index, U32 image_offset, tm_image_load_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 pImage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pImage = mmi_tm_add_to_DLT_img_cache(image_offset, type);
    g_tm_cntx.theme_image_list[img_list_index].image_cache_ptr = pImage;

    PRINT_INFORMATION("mmi_tm_add_img_id_to_cache: img_list_index =%d, image_offset = %d type = %d\n", img_list_index,
                       image_offset, type);

    return pImage;
}
#endif /* __MMI_DLT_CACHE_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_create_non_imageid_image
 * DESCRIPTION
 *  this function creates non id image buffer and add it to pool
 * PARAMETERS
 *  image_offset        [IN]        
 *  type                [IN]        
 * RETURNS
 *  current image pointer in image pool buffer
 *****************************************************************************/
PU8 mmi_tm_create_non_imageid_image(U32 image_offset, tm_image_load_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 size;
    U32 fp;
    PU8 pImage;
    U8 buff[MAX_THEME_IMAGE_HEADER_LENGTH] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DLT_CACHE_SUPPORT__
    if (type != THEME_IMG_LOAD_NEVER)
    {
        pImage = mmi_tm_add_to_DLT_img_cache(image_offset, type);

        if (pImage)
        {
            PRINT_INFORMATION("mmi_tm_create_non_imageid_image: image_offset =%d, type = %d\n", image_offset, type);
            return pImage;
        }
    }
#endif /* __MMI_DLT_CACHE_SUPPORT__ */ 
    if ( FS_GetFilePosition(g_tm_cntx.theme_file_handle, &fp) != FS_NO_ERROR )
    {
        mmi_tm_handle_file_access_failed();
        return NULL;
    }

    if ( DRM_seek_file(g_tm_cntx.theme_file_handle, image_offset, FS_FILE_BEGIN) >=0 )
    {
        if ( DRM_read_file(g_tm_cntx.theme_file_handle, buff, THEME_IMAGE_INFO_HEADER, (U32*) & size) != FS_NO_ERROR )
        {
            mmi_tm_handle_file_access_failed();
            return NULL;
        }
    }
    else
    {
        mmi_tm_handle_file_access_failed();
        return NULL;
    }

    /* offset in next 4 bytes */
    buff[8] = (U8) (image_offset & 0x000000ff);
    buff[9] = (U8) ((image_offset >> 8) & 0x000000ff);
    buff[10] = (U8) ((image_offset >> 16) & 0x000000ff);
    buff[11] = (U8) ((image_offset >> 24) & 0x000000ff);

    /* file handle in next 4 bytes */
    buff[12] = (U8) (g_tm_cntx.theme_file_handle & 0x000000ff);
    buff[13] = (U8) ((g_tm_cntx.theme_file_handle >> 8) & 0x000000ff);
    buff[14] = (U8) ((g_tm_cntx.theme_file_handle >> 16) & 0x000000ff);
    buff[15] = (U8) ((g_tm_cntx.theme_file_handle >> 24) & 0x000000ff);

    if ( DRM_seek_file(g_tm_cntx.theme_file_handle, fp, FS_FILE_BEGIN) < 0)
    {
        mmi_tm_handle_file_access_failed();
        return NULL;
    }

    return (PU8) mmi_tm_add_image_header_to_pool(&(g_tm_cntx.non_imageid_images_headers), buff);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_handle_audio
 * DESCRIPTION
 *  this function handles downloadable theme audio files
 * PARAMETERS
 *  audio_offset        [IN]        
 *  audio_size          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_tm_handle_audio(U32 audio_offset, U32 audio_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 virtual_audio_fname[FS_GenVFN_SIZE + 8];
    S32 fs_result;

    /* PMT DLT_FIXES - TK 20060325 START */
    S8 TempName[MAX_IMAGE_NAME_PATH_WIDTH + MAX_AUDIO_NAME_WIDTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* PMT DLT_FIXES - TK 20060325 END */

    if (g_tc_audiothmfileformat == THEME_AUDIO)
    {
        mmi_asc_to_ucs2((S8*) gDwnlThmToneInfo[0].AudioName, THEME_AUDIO_FILE);   /* currently only one audio is suported. Will be changed */
    }
    else if (g_tc_audiothmfileformat == THEME_MIDI)
    {
        mmi_asc_to_ucs2((S8*) gDwnlThmToneInfo[0].AudioName, THEME_AUDIO_MID_FILE);
    }
    else if (g_tc_audiothmfileformat == THEME_MP3)
    {
        mmi_asc_to_ucs2((S8*) gDwnlThmToneInfo[0].AudioName, THEME_AUDIO_MP3_FILE);
    }
    /* PMT DLT_FIXES - TK 20060325 START */
    memset(TempName, 0, (MAX_IMAGE_NAME_PATH_WIDTH + MAX_AUDIO_NAME_WIDTH));
    mmi_asc_to_ucs2((S8*) TempName, THEME_AUDIO_FOLDER_PATH);
    FS_CreateDir((PU16) TempName);
    //      CreateDir((U8*)TempName);
    //PMT DLT_FIXES - TK 20060325 END
    //      mmi_asc_to_ucs2((S8*)gDwnlThmToneInfo[0].AudioName, THEME_AUDIO_FILE);//currently only one audio is suported. Will be changed
    memset(virtual_audio_fname, 0, sizeof(virtual_audio_fname));
    fs_result = FS_GenVirtualFileName(
                    g_tm_cntx.theme_file_handle,
                    (U16*) virtual_audio_fname,
                    (unsigned int)FS_GenVFN_SIZE,
                    audio_offset,
                    audio_size);
    mmi_ucs2cat((PS8) virtual_audio_fname, (PS8) ".");
    mmi_ucs2cat((PS8) virtual_audio_fname, mmi_fmgr_extract_ext_file_name((PS8) gDwnlThmToneInfo[0].AudioName));
    mmi_ucs2cpy((S8*) gVirAudFileNameList[0], (S8*) virtual_audio_fname);
    if (fs_result >= 0)
    {
        g_tm_cntx.theme_has_ringtone = TRUE;
        gDwnlThmToneInfo[0].AudioId = CURRENT_THEME_INCOMING_CALL_TONE;
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_FMGR_SPACE_NOT_AVAILABLE),
            IMG_GLOBAL_EMPTY,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            WARNING_TONE);
    }

    /* PMT DLT_FIXES - TK 20060328 END */
}




/*****************************************************************************
 * FUNCTION
 *  mmi_tm_activate_downloaded_theme
 * DESCRIPTION
 *  This function activates downloadable theme
 * PARAMETERS
 *  theme_struct_p      [?]     
 * RETURNS
 *  theme error code
 *****************************************************************************/
tm_theme_error_enum mmi_tm_activate_downloaded_theme(tm_theme_list_struct *theme_struct_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    tm_theme_error_enum result;
    S16 err;
    U8 theme_file_name[(MAX_DWNL_THM_PATH_LEN + MAX_THEME_NAME_LENGTH) * ENCODING_LENGTH] = {0};
    U8 tmp_path[50] = {0};
    U16 nmodels = 0;
    BOOL phonemodelcheck = FALSE;
    FS_HANDLE last_theme_file_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (theme_struct_p->theme_type == THEME_TYPE_DOWNLOADED_PHONE)
    {
        sprintf((PS8) tmp_path, "%c%s", MMI_PUBLIC_DRV, DOWNLOADED_THEMES_PATH);
        mmi_asc_to_ucs2((PS8) theme_file_name, (PS8) tmp_path);
    }
    else
    {
        sprintf((PS8) tmp_path, "%c%s", MMI_CARD_DRV, DOWNLOADED_THEMES_PATH);
        mmi_asc_to_ucs2((PS8) theme_file_name, (PS8) tmp_path);
    }
    {
        mmi_ucs2cat((PS8) theme_file_name, (PS8) theme_struct_p->theme_name);
    }


    last_theme_file_handle = g_tm_cntx.theme_file_handle;
    // g_tm_cntx.theme_file_handle = DRM_open_file((U16*)theme_file_name, FS_READ_ONLY, 0/*DRM_PERMISSION_NONE*/);
    g_tm_cntx.theme_file_handle = DRM_open_file((U16*) theme_file_name, FS_READ_ONLY | FS_OPEN_SHARED, 0);

    if (g_tm_cntx.theme_file_handle < FS_NO_ERROR)
    {
        g_tm_cntx.theme_file_handle = last_theme_file_handle;
        return THEME_ERROR_THEME_NOT_AVAILABLE;
    }

    if ( theme_struct_p->theme_checksum_verified == CHECKSUM_VERIFIED_BAD )
    {
        DRM_close_file(g_tm_cntx.theme_file_handle);
        g_tm_cntx.theme_file_handle = last_theme_file_handle;
        return THEME_ERROR_FILE_FORMAT_BAD;
    }
    else
    {
        result = mmi_tm_verify_theme_checksum(theme_file_name);

        if (result == THEME_ERROR_SUCCESS)
        {
            theme_struct_p->theme_checksum_verified = CHECKSUM_VERIFIED_OK;
            WriteRecord(
                NVRAM_EF_THEME_MANAGER_LID,
                1,
                (void*)(g_tm_theme_list + g_tm_cntx.sys_thm_cnt),
                NVRAM_EF_THEME_MANAGER_RECORD_SIZE,
                &err);
        }
        else
        {
            theme_struct_p->theme_checksum_verified = CHECKSUM_VERIFIED_BAD;
            WriteRecord(
                NVRAM_EF_THEME_MANAGER_LID,
                1,
                (void*)(g_tm_theme_list + g_tm_cntx.sys_thm_cnt),
                NVRAM_EF_THEME_MANAGER_RECORD_SIZE,
                &err);
            DRM_close_file(g_tm_cntx.theme_file_handle);
            g_tm_cntx.theme_file_handle = last_theme_file_handle;
            return THEME_ERROR_FILE_FORMAT_BAD;
        }
    }

    memset(&g_tc_deviceInfo, 0, sizeof(tc_deviceinfo_struct));
    memset(&g_tc_themeInfo, 0, sizeof(tc_theme_download_info_struct));

    if (mmi_tm_theme_version_and_deviceinfo_check(theme_struct_p) != TRUE)
    {
        DRM_close_file(g_tm_cntx.theme_file_handle);
        g_tm_cntx.theme_file_handle = last_theme_file_handle;
        return THEME_ERROR_VERSION_FAILURE;
    }
    if (!mmi_ta_check_theme_file_lcd_dim_compatibiltiy(g_tc_deviceInfo.lcdwidth, g_tc_deviceInfo.lcdht))
    {
        DRM_close_file(g_tm_cntx.theme_file_handle);
        g_tm_cntx.theme_file_handle = last_theme_file_handle;
        return THEME_ERROR_LCD_SIZE_MISMATCH;
    }
    while (*g_tc_deviceInfo.model_ID[nmodels] && nmodels < MAX_PHONE_MODELS)
    {
        if (mmi_tm_check_theme_file_phone_model_compatibility((PS8) g_tc_deviceInfo.model_ID[nmodels]) == TRUE)
        {
            phonemodelcheck = TRUE;
            break;
        }
        ++nmodels;
    }
    if (!phonemodelcheck)
    {
        DRM_close_file(g_tm_cntx.theme_file_handle);
        g_tm_cntx.theme_file_handle = last_theme_file_handle;
        return THEME_ERROR_PHONE_MODEL_MISMATCH;
    }

    DRM_close_file(last_theme_file_handle);

    g_tm_cntx.theme_has_alternate_image = FALSE;
    g_tm_activated_theme.system_image_list = NULL;
    g_tm_activated_theme.theme_image_details_list = g_tm_cntx.theme_image_list;

    mmi_tm_reset_imageid_image_header_pool();
    mmi_tm_reset_non_imageid_image_header_pool();
#ifdef __MMI_DLT_CACHE_SUPPORT__
    g_tm_load_always_offset = 0;
    mmi_tm_clear_ondemand_cache();
#endif /* __MMI_DLT_CACHE_SUPPORT__ */ 
    g_tm_cntx.theme_imageid_image_count = 0;
    memset(g_tm_theme_image_dirty_bits, 0, sizeof(g_tm_theme_image_dirty_bits));
    g_tm_cntx.theme_has_wallpaper = FALSE;
    g_tm_cntx.theme_has_screensaver = FALSE;
    g_tm_cntx.theme_has_ringtone = FALSE;

    if (!mmi_tc_convert_theme_file_to_mmi_theme(&(g_tm_activated_theme.theme), g_tm_cntx.theme_file_handle))
    {
        return THEME_ERROR_FAILURE;
    }
    mmi_tm_sort_theme_image_table();

    set_MMI_theme(g_tm_activated_theme.theme);
    MMI_apply_current_theme();

    g_tm_cntx.curr_activated_theme_id = theme_struct_p->theme_id;
    g_tm_cntx.curr_activated_theme_type = theme_struct_p->theme_type;
    WriteValue(THEME_MANAGER_CURR_THEME_ID, (void*)&g_tm_cntx.curr_activated_theme_id, DS_DOUBLE, &err);

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    /* reset ResMem cache so that DLT img can get 1st priority to load in GetImage() */
    mmi_frm_resmem_reset(MMI_FRM_RESMEM_TYPE_ALWAYS_EXIST | MMI_FRM_RESMEM_TYPE_LOD_ON_DEMAND);
#endif

    return THEME_ERROR_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_activate_theme_from_fmgr
 * DESCRIPTION
 *  This function activates theme from file manager
 * PARAMETERS
 *  theme_type          [IN]        
 *  theme_name_p        [IN]     
 *  is_short            [IN]    
 * RETURNS
 *  theme error code
 *****************************************************************************/
U8 mmi_tm_get_themes_for_fmgr(tm_theme_list_struct **theme_list_p, PS8 filename, tm_theme_type_enum storage_type);

tm_theme_error_enum mmi_tm_activate_theme_from_fmgr(tm_theme_type_enum theme_type, U8 *theme_name_p, MMI_BOOL is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U8 found = 0;
    tm_theme_error_enum result;
    U16 filename[(MAX_THEME_NAME_LENGTH + 1)];
    tm_theme_list_struct *theme_list_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ( mmi_tm_get_usb_mode() )
    {
        return THEME_ERROR_USB_MODE_ON;
    }

    if (is_short)
    {
        /* convert short name */
        mmi_chset_mixed_text_to_ucs2_str(
            (U8*) filename,
            MAX_THEME_NAME_LENGTH * ENCODING_LENGTH,
            (U8*) theme_name_p,
            PhnsetGetDefEncodingType());
    }
    else
    {
        mmi_ucs2cpy((PS8) filename, (PS8) theme_name_p);
    }

    /* Check if theme already on the list */
    for (i = g_tm_cntx.sys_thm_cnt; i < g_tm_cntx.total_thm_cnt; ++i)
    {
        if ((mmi_ucs2cmp((PS8) g_tm_theme_list[i].theme_name, (PS8) filename) == 0) &&
            (g_tm_theme_list[i].theme_type == theme_type))
        {
            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        /* Try to add theme to theme list */
        mmi_tm_get_themes_for_fmgr(&theme_list_p, (PS8) filename, theme_type);

        /* Theme still might not have been added: Check */
        for (i = g_tm_cntx.sys_thm_cnt; i < g_tm_cntx.total_thm_cnt; ++i)
        {
            if ((mmi_ucs2cmp((PS8) g_tm_theme_list[i].theme_name, (PS8) filename) == 0) &&
                (g_tm_theme_list[i].theme_type == theme_type))
            {
                found = 1;
                break;
            }
        }
    }
    if (found == 0)
    {
        return THEME_ERROR_MAX_COUNT_REACHED;
    }
    else
    {
        if (g_tm_cntx.curr_activated_theme_id == g_tm_theme_list[i].theme_id)
        {
            return THEME_ERROR_ALREADY_ACTIVATED;
        }
        else
        {
            result = mmi_tm_activate_downloaded_theme(&g_tm_theme_list[i]);
        }
    }

    if (result == THEME_ERROR_SUCCESS)
    {
        /* only set theme wallpaper when selected by user */
            if ( PhnsetIsWPCurrentTheme() ) 
            {
                ThemeManagerSetWallpaper(IMG_ID_DISPCHAR_THEME_WALLPAPER);
            }
        
                if (PhnsetIsScrSvrCurrentTheme())
                {
            ThemeManagerSetScreensaver(IMG_ID_DISPCHAR_THEME_SCREENSAVER);
        }

        if (g_tm_cntx.theme_has_ringtone)
        {
            ThemeManagerSetRingTone(CURRENT_THEME_INCOMING_CALL_TONE);
	#ifdef __MMI_DUAL_PROFILE_SUPPORT__
	     ThemeManagerSetCard2RingTone(CURRENT_THEME_INCOMING_CALL_TONE);
	#endif	/* __MMI_DUAL_PROFILE_SUPPORT__ */
            ThemeManagerSetAlarmTone(CURRENT_THEME_ALARM_EXPIRY_TONE);
        }
        else
        {
            ThemeManagerResetRingTone();
	#ifdef __MMI_DUAL_PROFILE_SUPPORT__
	     ThemeManagerResetCard2RingTone();
	#endif	/* __MMI_DUAL_PROFILE_SUPPORT__ */
            ThemeManagerResetAlarmTone();
        }
        initialize_status_icons();
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_delete_theme
 * DESCRIPTION
 *  This function deletes the theme with the corresponding theme id
 * PARAMETERS
 *  theme_id        [IN]        
 *  error_type      [IN]        
 * RETURNS
 *  theme error code
 *****************************************************************************/
tm_theme_error_enum mmi_tm_delete_theme(THEME_ID theme_id, PS32 error_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, found = 0;
    S16 err;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = g_tm_cntx.sys_thm_cnt; i < g_tm_cntx.total_thm_cnt; ++i)
    {
        if (g_tm_theme_list[i].theme_id == theme_id)
        {
            found = 1;
            break;
        }
    }

    if (!found)
    {
        return THEME_ERROR_THEME_NOT_AVAILABLE;
    }
    else
    {
        U8 tmp_file_name[50];
        U8 file_name[100];

        if (g_tm_theme_list[i].theme_type == THEME_TYPE_DOWNLOADED_PHONE)
        {
            sprintf((PS8) tmp_file_name, "%c%s", MMI_PUBLIC_DRV, DOWNLOADED_THEMES_PATH);
            mmi_asc_to_ucs2((PS8) file_name, (PS8) tmp_file_name);
        }
        else
        {
            sprintf((PS8) tmp_file_name, "%c%s", MMI_CARD_DRV, DOWNLOADED_THEMES_PATH);
            mmi_asc_to_ucs2((PS8) file_name, (PS8) tmp_file_name);
        }

        mmi_ucs2cat((PS8) file_name, (PS8) g_tm_theme_list[i].theme_name);

        if ((*error_type = FS_Delete((U16*) file_name)) == FS_NO_ERROR)
        {
            for (; i < g_tm_cntx.total_thm_cnt - 1; ++i)
            {
                memcpy((void*)&g_tm_theme_list[i], (void*)&g_tm_theme_list[i + 1], sizeof(tm_theme_list_struct));
            }
            memset((void*)&g_tm_theme_list[g_tm_cntx.total_thm_cnt - 1], 0, sizeof(tm_theme_list_struct));
            WriteRecord(
                NVRAM_EF_THEME_MANAGER_LID,
                1,
                (void*)(g_tm_theme_list + g_tm_cntx.sys_thm_cnt),
                NVRAM_EF_THEME_MANAGER_RECORD_SIZE,
                &err);
            --g_tm_cntx.total_thm_cnt;

            return THEME_ERROR_SUCCESS;
        }
        else
        {
            return THEME_ERROR_FAILURE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_delete_theme_from_fmgr
 * DESCRIPTION
 *  This function deletes theme with the corresponding theme name from file manager
 * PARAMETERS
 *  theme_type          [IN]        
 *  theme_name_p        [?]         
 *  error_type          [IN]        
 * RETURNS
 *  theme error code
 *****************************************************************************/
tm_theme_error_enum mmi_tm_delete_theme_from_fmgr(tm_theme_type_enum theme_type, U8 *theme_name_p, PS32 error_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, found = 0;
    U8 tmp_file_name[50];
    U8 file_name[100];
    S16 err;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = g_tm_cntx.sys_thm_cnt; i < g_tm_cntx.total_thm_cnt; ++i)
    {
        if (!mmi_ucs2cmp((PS8) g_tm_theme_list[i].theme_name, (PS8) theme_name_p) &&
            (g_tm_theme_list[i].theme_type == theme_type))
        {
            found = 1;
            break;
        }
    }

    if (theme_type == THEME_TYPE_DOWNLOADED_PHONE)
    {
        sprintf((PS8) tmp_file_name, "%c%s", MMI_PUBLIC_DRV, DOWNLOADED_THEMES_PATH);
        mmi_asc_to_ucs2((PS8) file_name, (PS8) tmp_file_name);
    }
    else
    {
        sprintf((PS8) tmp_file_name, "%c%s", MMI_CARD_DRV, DOWNLOADED_THEMES_PATH);
        mmi_asc_to_ucs2((PS8) file_name, (PS8) tmp_file_name);
    }

    mmi_ucs2cat((PS8) file_name, (PS8) theme_name_p);

    if (found)
    {
        if (g_tm_theme_list[i].theme_id == g_tm_cntx.curr_activated_theme_id)
        {
            return THEME_ERROR_ALREADY_ACTIVATED;
        }
        if ((*error_type = FS_Delete((U16*) file_name)) == FS_NO_ERROR)
        {
            for (; i < g_tm_cntx.total_thm_cnt - 1; ++i)
            {
                memcpy((void*)&g_tm_theme_list[i], (void*)&g_tm_theme_list[i + 1], sizeof(tm_theme_list_struct));
            }
            memset((void*)&g_tm_theme_list[g_tm_cntx.total_thm_cnt - 1], 0, sizeof(tm_theme_list_struct));
            WriteRecord(
                NVRAM_EF_THEME_MANAGER_LID,
                1,
                (void*)(g_tm_theme_list + g_tm_cntx.sys_thm_cnt),
                NVRAM_EF_THEME_MANAGER_RECORD_SIZE,
                &err);
            --g_tm_cntx.total_thm_cnt;

            return THEME_ERROR_SUCCESS;
        }
        else
        {
            return THEME_ERROR_DELETE_FAILURE;
        }
    }
    else if ((*error_type = FS_Delete((U16*) file_name)) == FS_NO_ERROR)
    {
        return THEME_ERROR_SUCCESS;
    }
    else
    {
        return THEME_ERROR_FAILURE;
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_tm_get_current_theme_ringtone
 * DESCRIPTION
 *  This function gets the current theme ringtone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_tm_get_current_theme_ringtone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_tm_cntx.theme_has_ringtone;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_get_theme_version_table
 * DESCRIPTION
 *  This function gets the theme version table
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
const FLOAT *mmi_tm_get_theme_version_table(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_tm_supported_thm_version_table;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_verify_theme_checksum
 * DESCRIPTION
 *  This function checks the theme file checksum
 * PARAMETERS
 *  file_name_p     [?]     
 * RETURNS
 *  theme error code
 *****************************************************************************/
tm_theme_error_enum mmi_tm_verify_theme_checksum(U8 *file_name_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 no_of_char;
    U32 checksum[2];
    FS_HANDLE file;
    U32 theme_file_size;
    U32 bytes_read = 0;
    U8 *file_buffer;
    U32 tc_checksumkey = 0xFFFFFFFF;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    file = FS_Open((WCHAR*) file_name_p, FS_READ_ONLY);

    if (!file)
    {
        return THEME_ERROR_FILE_FORMAT_BAD;
    }
    else
    {
        /* Read checksum & File Size here, after Opening file get it's size */
        if (FS_GetFileSize(file, &theme_file_size) != FS_NO_ERROR)
        {
            FS_Close(file);
            return THEME_ERROR_FILE_FORMAT_BAD;
        }

        /* 4 bytes of File Size are used to calculate CRC therefore we need to include in CRC checking */
        FS_Read(file, (void *)&checksum, THEME_CHECKSUM_HEADER_SIZE + THEME_FILE_SIZE_HEADER, &no_of_char);

        if (no_of_char < (THEME_CHECKSUM_HEADER_SIZE + THEME_FILE_SIZE_HEADER))
        {
            FS_Close(file);
            return THEME_ERROR_FILE_FORMAT_BAD;
        }

        if (theme_file_size != checksum[1])
        {
            FS_Close(file);
            return THEME_ERROR_FILE_FORMAT_BAD;
        }

        /* allocate buffer for file read */
        file_buffer = OslMalloc(TM_FILE_BUFF_SIZE);

        /* Tricky THEME_NO_OF_BYTE_TO_CHECK_FOR_CRC is assumed to be multiple of TM_FILE_BUFF_SIZE */
        while (bytes_read < (THEME_NO_OF_BYTE_TO_CHECK_FOR_CRC))        /*  0x80000 Bytes => 512 * 1024 = 524288 Bytes */
        {
            FS_Read(file, (void *)file_buffer, TM_FILE_BUFF_SIZE, &no_of_char);
            if (no_of_char > 0)
            {
                bytes_read += no_of_char;
                tc_checksumkey = applib_crc_update(tc_checksumkey, file_buffer, (U16)no_of_char);

                if (no_of_char < TM_FILE_BUFF_SIZE)
                    break;
            }
            /* PMT DLT_FIXES - TK 20060321 START */
            else
            {
                break;  /* boundary value analysis is not consider here so this loop is */

            }
            /* PMT DLT_FIXES - TK 20060321 END */
        }

        OslMfree(file_buffer);
        
    }
    FS_Close(file);
    if (tc_checksumkey == checksum[0])
    {
        return THEME_ERROR_SUCCESS;
    }
    else
    {
        return THEME_ERROR_FILE_FORMAT_BAD;
    }
}

#ifdef __DLT_ENABLE_PROCESS_QUEUE__


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_theme_process_queue
 * DESCRIPTION
 *  This function polls for message queue
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        None/Error status
 *  b(?)        [IN]            None
 * RETURNS
 *  theme error code
 *****************************************************************************/
tm_theme_error_enum mmi_tm_theme_process_queue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE queueNode;

    /* MMIEQNVRAMREADRSP *readMessage; */

    unsigned int my_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_NVM_READ_REC_INT_HDLR, nFileId, nRecordId); */

    /* SendNVRAMReadReq(nFileId,nRecordId); */

    OslReceiveMsgExtQ(mmi_ext_qid, &queueNode);
    OslGetMyTaskIndex(&my_index);
    OslStackSetActiveModuleID(my_index, MOD_MMI);

    switch (queueNode.msg_id)
    {
            /* case PRT_INCOMINGCALL_EVENT:
               ProtocolEventHandler((U16)queueNode.oslMsgId,(void*)queueNode.oslDataPtr,(int)queueNode.oslSrcId, (void*) queueNode.oslPeerBuffPtr );
               return THEME_ERROR_INCOMING_CALL;
               break; */

        case MSG_ID_MMI_EQ_PLAY_AUDIO_RSP:
        case MSG_ID_MMI_EQ_STOP_AUDIO_RSP:
        case MSG_ID_MMI_EQ_EXE_GPIO_LEVEL_RSP:
        case MSG_ID_MMI_EQ_SET_VOLUME_RSP:
            OslFreeInterTaskMsg(&queueNode);
            break;
        case MSG_ID_MMI_EQ_KEYPAD_DETECT_IND:
        {
            if (mmi_bootup_is_searching_or_idle_reached() == MMI_FALSE)
            {
                KeyHandleBeforePWRON((void*)queueNode.oslDataPtr);
            }
            else
            {
                mmi_eq_keypad_detect_ind_struct *p;

                p = (mmi_eq_keypad_detect_ind_struct*) queueNode.local_para_ptr;
                g_keypad_flag = MMI_TRUE;
                keypad_ptr = p->func;
            }
            OslFreeInterTaskMsg(&queueNode);
            break;
        }
        case MSG_ID_MMI_EQ_GET_RTC_TIME_RSP:
        {
            if (mmi_bootup_is_searching_or_idle_reached() == MMI_FALSE)
            {
                ProtocolEventHandler(
                    (U16) queueNode.oslMsgId,
                    (void*)queueNode.oslDataPtr,
                    (int)queueNode.oslSrcId,
                    (void*)queueNode.oslPeerBuffPtr);
                OslFreeInterTaskMsg(&queueNode);
                break;
            }
        }
        case MSG_ID_TIMER_EXPIRY:
        {
            /* if(!g_pwr_context.idleScreenFirst) */
            {
                kal_uint16 msg_len;

                EvshedMMITimerHandler(get_local_para_ptr(queueNode.oslDataPtr, &msg_len));
                break;
            }
            /* else
               {
               stack_timer_struct* stack_timer_ptr;
               stack_timer_ptr = (stack_timer_struct*)queueNode.oslDataPtr;
               if (!stack_is_time_out_valid(stack_timer_ptr))
               {
               PRINT_INFORMATION("==========Time out is not valid==========");
               OslFreeInterTaskMsg(&queueNode);       
               break;   
               }
               } */
        }
        default:
        {
            ilm_struct ilm_ptr;
            U8 flag = 0;

            ilm_ptr.src_mod_id = queueNode.src_mod_id;
            ilm_ptr.dest_mod_id = queueNode.dest_mod_id;
            ilm_ptr.msg_id = queueNode.msg_id;
            ilm_ptr.sap_id = queueNode.sap_id;
            ilm_ptr.local_para_ptr = queueNode.local_para_ptr;
            ilm_ptr.peer_buff_ptr = queueNode.peer_buff_ptr;
            flag = OslWriteCircularQ(&ilm_ptr);
            /* TIMER use special data in the local_para_ptr field. Can NOT treat as general ILM */
            if ((queueNode.src_mod_id != MOD_TIMER) && (flag == 1))
            {
                hold_local_para(ilm_ptr.local_para_ptr);
                hold_peer_buff(ilm_ptr.peer_buff_ptr);
            }

            OslFreeInterTaskMsg(&queueNode);
            break;
        }
    }
    OslFreeInterTaskMsg(&queueNode);
    return THEME_ERROR_PROCESS_QUEUE_SUCESS;
}
#endif /* __DLT_ENABLE_PROCESS_QUEUE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_handle_theme_activation_error_status
 * DESCRIPTION
 *  This function handles error status at the time of theme activation
 * PARAMETERS
 *  status      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_tm_handle_theme_activation_error_status(U16 status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (status)
    {
        case THEME_ERROR_SUCCESS:
            DisplayPopup(
                (PU8) GetString(STR_THEME_ACTIVATE_SUCCESS),
                IMG_GLOBAL_ACTIVATED,
                0,
                UI_POPUP_NOTIFYDURATION_TIME,
                SUCCESS_TONE);
            break;
        case THEME_ERROR_SPACE_NOT_AVAILABLE:
            DisplayPopup(
                (PU8) GetString(STR_ID_FMGR_SPACE_NOT_AVAILABLE),
                IMG_GLOBAL_EMPTY,
                0,
                UI_POPUP_NOTIFYDURATION_TIME,
                WARNING_TONE);
            break;
        case THEME_ERROR_THEME_NOT_AVAILABLE:
            DisplayPopup(
                (PU8) GetString(STR_THEME_NOT_AVAILABLE),
                IMG_GLOBAL_ERROR,
                0,
                UI_POPUP_NOTIFYDURATION_TIME,
                WARNING_TONE);
            break;
        case THEME_ERROR_FILE_FORMAT_BAD:
            DisplayPopup(
                (PU8) GetString(STR_THEME_FORMAT_NOT_SUPPORTED),
                IMG_GLOBAL_ERROR,
                0,
                UI_POPUP_NOTIFYDURATION_TIME,
                WARNING_TONE);
            break;
        case THEME_ERROR_FAILURE:
            DisplayPopup(
                (PU8) GetString(STR_THEME_UNKNOWN_ERROR),
                IMG_GLOBAL_ERROR,
                0,
                UI_POPUP_NOTIFYDURATION_TIME,
                WARNING_TONE);
            break;
        case THEME_ERROR_ALREADY_ACTIVATED:
            DisplayPopup(
                (PU8) GetString(STR_ID_FMGR_ALREADY_ACTIVE),
                IMG_GLOBAL_ACTIVATED,
                0,
                UI_POPUP_NOTIFYDURATION_TIME,
                WARNING_TONE);
            break;
        case THEME_ERROR_MAX_COUNT_REACHED:
            DisplayPopup((PU8) GetString(STR_ID_FMGR_MAX_COUNT_REACHED), IMG_GLOBAL_ERROR, 0, 1000, WARNING_TONE);
            break;
        case THEME_ERROR_VERSION_FAILURE:
            DisplayPopup(
                (PU8) GetString(STR_DOWNLOAD_THEME_UNSUPPORTED),
                IMG_GLOBAL_WARNING,
                0,
                UI_POPUP_NOTIFYDURATION_TIME,
                WARNING_TONE);
            break;
        case THEME_ERROR_PROCESS_QUEUE_SUCESS:
            DisplayPopup(NULL, IMG_PROCESSING_PHONEBOOK, 1, UI_POPUP_NOTIFYDURATION_TIME, 0);
            break;
        case THEME_ERROR_LCD_SIZE_MISMATCH:
            DisplayPopup(
                (PU8) GetString(STR_LCD_SIZE_MISMATCH),
                IMG_GLOBAL_ERROR,
                TRUE,
                UI_POPUP_NOTIFYDURATION_TIME,
                WARNING_TONE);
            break;
        case THEME_ERROR_FILENAME_INCORRECT:
            DisplayPopup(
                (PU8) GetString(STR_THEME_ERROR_FILENAME_INCORRECT),
                IMG_GLOBAL_WARNING,
                0,
                UI_POPUP_NOTIFYDURATION_TIME,
                WARNING_TONE);
            break;
        case THEME_ERROR_PHONE_MODEL_MISMATCH:
            DisplayPopup(
                (PU8) GetString(STR_THEME_ERROR_PHONE_MODEL_MISMATCH),
                IMG_GLOBAL_WARNING,
                0,
                UI_POPUP_NOTIFYDURATION_TIME,
                WARNING_TONE);
            break;
        case THEME_ERROR_USB_MODE_ON:
            DisplayPopup(
                (PU8) GetString(STR_ID_USB_MODE_EXPORTED_WARNING),
                IMG_GLOBAL_ERROR,
                TRUE,
                UI_POPUP_NOTIFYDURATION_TIME,
                WARNING_TONE);
            break;
        default:
            DisplayPopup(
                (PU8) GetString(STR_THEME_UNKNOWN_ERROR),
                IMG_GLOBAL_ERROR,
                0,
                UI_POPUP_NOTIFYDURATION_TIME,
                WARNING_TONE);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_set_was_theme_alarm_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_tm_set_was_theme_alarm_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_tm_was_theme_alarm_cb = MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_tm_init_theme_usb_mode_plugin_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_tm_init_theme_usb_mode_plugin_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S16 err;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_tm_get_curr_theme_type() != THEME_TYPE_SYSTEM)  /* fixed for usb */
    {
		WriteValue(NVRAM_USB_PREVIOUS_THEME_INDEX, (void*)&g_tm_cntx.curr_activated_theme_id, DS_DOUBLE, &err);
        ActivateDefaultTheme();
        g_thm_cntx.CurrTheme = mmi_tm_get_current_theme_id();
    }
    g_tm_USB_mode = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_init_theme_usb_mode_plugout_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_tm_init_theme_usb_mode_plugout_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 period;
	S16 err;
    U64 buff;     
	U32 usb_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ReadValue(NVRAM_USB_PREVIOUS_THEME_INDEX, (void*)&buff, DS_DOUBLE, &err);
	usb_id = (U32) buff;
	if (usb_id != -1)
	{			
		WriteValue(THEME_MANAGER_CURR_THEME_ID, (void*)&usb_id, DS_DOUBLE, &err);
        mmi_tm_activate_theme(usb_id);
		usb_id = -1;
		WriteValue(NVRAM_USB_PREVIOUS_THEME_INDEX, (void*)&usb_id, DS_DOUBLE, &err);
	}
    g_tm_USB_mode = FALSE;
    if (g_tm_was_theme_alarm_cb == MMI_TRUE)
    {
        ThemeAlarmCallBack(0, &period, 0);
        g_tm_was_theme_alarm_cb = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_get_usb_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
BOOL mmi_tm_get_usb_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_tm_USB_mode || (g_pwr_context.PowerOnMode == POWER_ON_USB))
    {
        return TRUE;
    }
    return FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_tm_get_audio_filename
 * DESCRIPTION
 *  It gives the theme tone virtual file name
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  string of theme tone virtual file name
 *****************************************************************************/
S8 *mmi_tm_get_audio_filename(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (S8*) gVirAudFileNameList[index];
}


#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */

#if (defined(__MMI_THEMES_V2_SUPPORT__))

/*****************************************************************************
 * FUNCTION
 *  mmi_tm_activate_default_theme
 * DESCRIPTION
 *  This function is called when the file access has failed for some reason.
 *  As a safegaurd it activates the default theme to insure nothing else breaks
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_tm_activate_default_theme(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __J2ME__
	U8 IsJavaPlaying = FALSE;
#endif	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("mmi_tm_activate_default_theme");
    if (mmi_tm_get_curr_theme_type() != THEME_TYPE_SYSTEM)
    {
#ifdef __J2ME__
        if (GetActiveScreenId() ==  SCR_JAVA_APP)
        {
            EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);
            ShowCategory66Screen(
                STR_SCR3001_THEMES_CAPTION,
                0,
                0,
                0,
                0,
                0,
                (PU8) GetString(STR_ID_DLT_THM_PROGRESS),
                IMG_THEME_ACTIVATION,
                NULL);
          IsJavaPlaying = TRUE;
        }
#endif /* __J2ME__ */ 

        mmi_tm_activate_theme(DefaultThmID);
        g_thm_cntx.CurrTheme = mmi_tm_get_current_theme_id();
        SetThemes(g_thm_cntx.CurrTheme);
        DisplayPopup( (U8*) GetString(STR_DEFAULT_THEME_ACTIVATION), 
                    IMG_GLOBAL_WARNING,
                    0,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    WARNING_TONE);
#ifdef __J2ME__
		if(IsJavaPlaying == TRUE)
		{
			DeleteUptoScrID(SCR_JAVA_APP);
		}
#endif
    
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_tm_handle_file_access_failed
 * DESCRIPTION
 *  This function is called when the file access has failed for some reason.
 *  As a safegaurd it activates the default theme to insure nothing else breaks
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_tm_handle_file_access_failed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_start_timer ( 200,  mmi_tm_activate_default_theme ); 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_theme_manager_init
 * DESCRIPTION
 *  It initilizes the global theme structure 'g_tm_cntx'
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_theme_manager_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((void*)&g_tm_cntx, 0, sizeof(tm_context_struct));
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__      /* ritesh */
    mmi_tm_create_image_header_pool(
        &(g_tm_cntx.imageid_images_headers),
        g_tm_cntx.imageid_images_headers_pool,
        MAX_THEME_IMAGE_HEADER_LENGTH,
        (MAX_THEME_IMAGE_HEADER_LENGTH * MAX_THEME_IMAGEID_IMAGES));
    mmi_tm_create_image_header_pool(
        &(g_tm_cntx.non_imageid_images_headers),
        g_tm_cntx.non_imageid_images_headers_pool,
        MAX_THEME_IMAGE_HEADER_LENGTH,
        (MAX_THEME_IMAGE_HEADER_LENGTH * MAX_THEME_NON_IMAGEID_IMAGES));
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ /* ritesh */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_get_system_theme_image
 * DESCRIPTION
 *  It returns system theme image pointer
 * PARAMETERS
 *  image_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *mmi_tm_get_system_theme_image(U32 image_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_tm_activated_theme.system_image_list[image_index];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_set_imageid
 * DESCRIPTION
 *  this function sets the image id and image offset of the image
 * PARAMETERS
 *  image_id            [IN]        
 *  image_offset        [IN]        
 *  type                [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_tm_set_imageid(U16 image_id, U32 image_offset, tm_image_load_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 image_index;
    U16 n_byte;
    U8 n_bit;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_tm_cntx.theme_imageid_image_count >= MAX_THEME_IMAGEID_IMAGES)
    {
        return;
    }
    else
    {
        PRINT_INFORMATION("mmi_tm_set_imageid: image_id =%d has type = %d\n", image_id, type);
		if(image_id == IMG_ID_DISPCHAR_THEME_WALLPAPER)
			g_tm_cntx.theme_has_wallpaper = TRUE;

		if(image_id == IMG_ID_DISPCHAR_THEME_SCREENSAVER)
			g_tm_cntx.theme_has_screensaver = TRUE;

        g_tm_cntx.theme_image_list[g_tm_cntx.theme_imageid_image_count].image_id = image_id;
        g_tm_cntx.theme_image_list[g_tm_cntx.theme_imageid_image_count].image_offset = image_offset;
    #ifdef __MMI_DLT_CACHE_SUPPORT__
        g_tm_cntx.theme_image_list[g_tm_cntx.theme_imageid_image_count].image_type = type;
        g_tm_cntx.theme_image_list[g_tm_cntx.theme_imageid_image_count].image_cache_ptr = 0;
    #endif /* __MMI_DLT_CACHE_SUPPORT__ */ 
        ++g_tm_cntx.theme_imageid_image_count;

        g_tm_cntx.theme_has_alternate_image = TRUE;
        image_index = GetImageIndex(image_id);

        n_byte = (image_index >> 3);
        n_bit = (image_index % 8);

        g_tm_theme_image_dirty_bits[n_byte] |= (0x80 >> n_bit);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_get_themes_for_fmgr
 * DESCRIPTION
 *  1. Purge the theme list of any non-existant themes
 *  2. Add theme to list if space available.
 * PARAMETERS
 *  theme_list_p        [IN]        
 *  filename            [IN]        
 *  storage_type        [IN]        
 * RETURNS
 *  total number of themes
 *****************************************************************************/
U8 mmi_tm_get_themes_for_fmgr(tm_theme_list_struct **theme_list_p, PS8 filename, tm_theme_type_enum storage_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nvm_card_thm_cnt = 0;
    tm_theme_list_struct *tmp_theme_list_p;

    U8 j, k;
    S16 err;
    U32 max_theme_id;
    U64 buff;
    U8 *temp_name;
    U8 nSystemThemeCount;
    S16 error_code;

    S8 tmp_str[MAX_DWNL_THM_PATH_LEN + MAX_THEME_SEARCH_STR_LEN];
    U16 theme_path[MAX_DWNL_THM_PATH_LEN + MAX_THEME_SEARCH_STR_LEN + MAX_THEME_NAME_LENGTH + 1];
    U16 theme_path_phone[MAX_DWNL_THM_PATH_LEN];    /* Plus 2 for MMI_PUBLIC_DRV: check */
    U16 theme_path_card[MAX_DWNL_THM_PATH_LEN];     /* Plus 2 for MMI_CARD_DRV: check */
    U16 theme_search_path[MAX_DWNL_THM_PATH_LEN + MAX_THEME_SEARCH_STR_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nSystemThemeCount = (U8) GetThemesNames((U8 ***) & temp_name);
    if (nSystemThemeCount > MAX_SYSTEM_THEMES)
    {
        nSystemThemeCount = MAX_SYSTEM_THEMES;
    }
    memset((void*)g_tm_theme_list, 0, sizeof(tm_theme_list_struct) * TOTAL_THEMES_COUNT);
    g_tm_cntx.total_thm_cnt = 0;
    g_tm_cntx.sys_thm_cnt = 0;

    for (j = 0; j < nSystemThemeCount; ++j)
    {
        mmi_ucs2ncpy(
            (PS8) g_tm_theme_list[j].theme_name,
            GetString((U16) (STR_THEME_DEFAULT + j)),
            MAX_THEME_NAME_LENGTH);
        g_tm_theme_list[j].theme_checksum_verified = CHECKSUM_VERIFIED_OK;
        g_tm_theme_list[j].theme_id = j + 1;
        g_tm_theme_list[j].theme_type = THEME_TYPE_SYSTEM;
    }
    g_tm_cntx.total_thm_cnt = g_tm_cntx.sys_thm_cnt = nSystemThemeCount;

    /* Read Themes from NVRAM */
    ReadRecord(
        NVRAM_EF_THEME_MANAGER_LID,
        1,
        (void*)(g_tm_theme_list + g_tm_cntx.sys_thm_cnt),
        NVRAM_EF_THEME_MANAGER_RECORD_SIZE,
        &err);
    /* err = 1 => NVRAM_READ_SUCCESS */
    if (err != NVRAM_READ_SUCCESS)
    {
        *theme_list_p = g_tm_theme_list;
        return g_tm_cntx.total_thm_cnt;
    }

    /* Sukrit: A better way to do it will be through something like does file exists on phone folder */

    sprintf(tmp_str, "%c%s", MMI_PUBLIC_DRV, DOWNLOADED_THEMES_PATH);
    mmi_asc_to_ucs2((PS8) theme_path_phone, tmp_str);

    sprintf(tmp_str, "%c%s", MMI_CARD_DRV, DOWNLOADED_THEMES_PATH);
    mmi_asc_to_ucs2((PS8) theme_path_card, tmp_str);

    ReadValue(THEME_MANAGER_MAX_THEME_ID, (void*)&buff, DS_DOUBLE, &err);
    max_theme_id = (U32) buff;
    if (max_theme_id == 0xFFFFFFFF || err == -1)
    {
        max_theme_id = 10;
        WriteValue(THEME_MANAGER_MAX_THEME_ID, (void*)&max_theme_id, DS_DOUBLE, &err);
    }

    tmp_theme_list_p = (tm_theme_list_struct*) & g_tm_NvramThmArr;

    /* Get all themes from NVRAM list, which are actually present on Phone, in a new theme list */
    /* Also, Count number of themes on phone and card that are actually on NVRAM */

    for (j = g_tm_cntx.sys_thm_cnt, k = 0; j < TOTAL_THEMES_COUNT; ++j)
    {
        if ((g_tm_theme_list[j].theme_type == THEME_TYPE_DOWNLOADED_PHONE))
        {
            mmi_ucs2ncpy((PS8) theme_path, (PS8) theme_path_phone, MAX_DWNL_THM_PATH_LEN);
            mmi_ucs2ncat((PS8) theme_path, (PS8) g_tm_theme_list[j].theme_name, MAX_THEME_NAME_LENGTH);
            error_code = FS_GetAttributes(theme_path);
            if (((error_code >= 0) && (error_code != FS_ATTR_DIR)) || (error_code == FS_ACCESS_DENIED))
            {
                memcpy((void*)(tmp_theme_list_p + k), (void*)&g_tm_theme_list[j], sizeof(tm_theme_list_struct));
                ++k;
            }
        }
        else if (g_tm_theme_list[j].theme_type == THEME_TYPE_DOWNLOADED_CARD)
        {
            mmi_ucs2ncpy((PS8) theme_path, (PS8) theme_path_card, MAX_DWNL_THM_PATH_LEN);
            mmi_ucs2ncat((PS8) theme_path, (PS8) g_tm_theme_list[j].theme_name, MAX_THEME_NAME_LENGTH);
            error_code = FS_GetAttributes(theme_path);
            if (((error_code >= 0) && (error_code != FS_ATTR_DIR)) || (error_code == FS_ACCESS_DENIED))
            {
                nvm_card_thm_cnt++;
            }
        }
    }

    /* Insert new Phone themes in NVRAM list */
    sprintf(tmp_str, "%c%s%s", MMI_PUBLIC_DRV, DOWNLOADED_THEMES_PATH, THEME_SEARCH_STR);
    mmi_asc_to_ucs2((PS8) theme_search_path, tmp_str);
    if (storage_type == THEME_TYPE_DOWNLOADED_PHONE && k < (MAX_DOWNLOADED_THEMES - nvm_card_thm_cnt))
    {
        memset((void*)&tmp_theme_list_p[k], 0, sizeof(tm_theme_list_struct));
        mmi_ucs2ncpy((PS8) tmp_theme_list_p[k].theme_name, (PS8) filename, MAX_THEME_NAME_LENGTH);
        tmp_theme_list_p[k].theme_checksum_verified = CHECKSUM_NOT_VERIFIED;
        tmp_theme_list_p[k].theme_id = ++max_theme_id;
        tmp_theme_list_p[k].theme_type = THEME_TYPE_DOWNLOADED_PHONE;
        ++k;
    }

    /* Get all themes from NVRAM list, which are actually present on card, in a new theme list */
    for (j = g_tm_cntx.sys_thm_cnt; j < TOTAL_THEMES_COUNT; ++j)
    {
        if ((g_tm_theme_list[j].theme_type == THEME_TYPE_DOWNLOADED_CARD))
        {
            mmi_ucs2ncpy((PS8) theme_path, (PS8) theme_path_card, MAX_DWNL_THM_PATH_LEN);
            mmi_ucs2ncat((PS8) theme_path, (PS8) g_tm_theme_list[j].theme_name, MAX_THEME_NAME_LENGTH);
            error_code = FS_GetAttributes(theme_path);
            if (((error_code >= 0) && (error_code != FS_ATTR_DIR)) || (error_code == FS_ACCESS_DENIED))
            {
                memcpy((void*)(tmp_theme_list_p + k), (void*)&g_tm_theme_list[j], sizeof(tm_theme_list_struct));
                ++k;
            }
        }
    }

    /* Insert new Card themes in NVRAM list */
    sprintf(tmp_str, "%c%s%s", MMI_CARD_DRV, DOWNLOADED_THEMES_PATH, THEME_SEARCH_STR);
    mmi_asc_to_ucs2((PS8) theme_search_path, tmp_str);

    if (storage_type == THEME_TYPE_DOWNLOADED_CARD && k < MAX_DOWNLOADED_THEMES)
    {
        memset((void*)&tmp_theme_list_p[k], 0, sizeof(tm_theme_list_struct));
        mmi_ucs2ncpy((PS8) tmp_theme_list_p[k].theme_name, (PS8) filename, MAX_THEME_NAME_LENGTH);
        tmp_theme_list_p[k].theme_checksum_verified = CHECKSUM_NOT_VERIFIED;
        tmp_theme_list_p[k].theme_id = ++max_theme_id;
        tmp_theme_list_p[k].theme_type = THEME_TYPE_DOWNLOADED_CARD;
        ++k;
    }

    g_tm_cntx.total_thm_cnt = g_tm_cntx.sys_thm_cnt + k;

    memset((void*)(g_tm_theme_list + g_tm_cntx.sys_thm_cnt), 0, sizeof(tm_theme_list_struct) * MAX_DOWNLOADED_THEMES);
    memcpy((void*)(g_tm_theme_list + g_tm_cntx.sys_thm_cnt), tmp_theme_list_p, sizeof(tm_theme_list_struct) * k);

    /* Write Themes back to NVRAM */
    WriteRecord(
        NVRAM_EF_THEME_MANAGER_LID,
        1,
        (void*)(g_tm_theme_list + g_tm_cntx.sys_thm_cnt),
        NVRAM_EF_THEME_MANAGER_RECORD_SIZE,
        &err);
    /* err = 4 => NVRAM_WRITE_SUCCESS */
    WriteValue(THEME_MANAGER_MAX_THEME_ID, (void*)&max_theme_id, DS_DOUBLE, &err);

    *theme_list_p = g_tm_theme_list;
    return g_tm_cntx.total_thm_cnt;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_checkfile_exists
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_tm_checkfile_exists(PS16 filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fh;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fh = FS_Open((WCHAR*) filename, FS_READ_ONLY);
    if (fh > 0)
    {
        FS_Close(fh);
        return MMI_TRUE;
    }
    else
    {
        FS_Close(fh);
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_get_themes
 * DESCRIPTION
 *  1. Purge the theme list of any non-existant themes
 *  2. Add any new themes if available.
 * PARAMETERS
 *  theme_list_p        [IN]        
 * RETURNS
 *  total number of themes
 *****************************************************************************/
U8 mmi_tm_get_themes(tm_theme_list_struct **theme_list_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 dwnl_ph_thm_cnt = 0;
    S32 dwnl_card_thm_cnt = 0;
    S32 nvm_card_thm_cnt = 0;
    tm_theme_list_struct *tmp_theme_list_p;

    U8 j, k;
    S16 err;
    U32 max_theme_id;
    U64 buff;
    U8 *temp_name;
    U8 nSystemThemeCount;
    S16 error_code;

    S8 tmp_str[MAX_DWNL_THM_PATH_LEN + MAX_THEME_SEARCH_STR_LEN];
    U16 theme_path[MAX_DWNL_THM_PATH_LEN + MAX_THEME_SEARCH_STR_LEN + MAX_THEME_NAME_LENGTH + 1];
    U16 theme_path_phone[MAX_DWNL_THM_PATH_LEN];    /* Plus 2 for MMI_PUBLIC_DRV: check */
    U16 theme_path_card[MAX_DWNL_THM_PATH_LEN];     /* Plus 2 for MMI_CARD_DRV: check */
    U16 theme_search_path[MAX_DWNL_THM_PATH_LEN + MAX_THEME_SEARCH_STR_LEN];

    U8 theme_type_bitmap[MAX_DOWNLOADED_THEMES] = {0};
    FS_HANDLE fh_cur;
    FS_DOSDirEntry file_info;
    U16 filename[MAX_THEME_NAME_LENGTH + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nSystemThemeCount = (U8) GetThemesNames((U8 ***) & temp_name);
    if (nSystemThemeCount > MAX_SYSTEM_THEMES)
    {
        nSystemThemeCount = MAX_SYSTEM_THEMES;
    }

    memset((void*)g_tm_theme_list, 0, sizeof(tm_theme_list_struct) * TOTAL_THEMES_COUNT);
    g_tm_cntx.total_thm_cnt = 0;
    g_tm_cntx.sys_thm_cnt = 0;

    for (j = 0; j < nSystemThemeCount; ++j)
    {
        mmi_ucs2ncpy(
            (PS8) g_tm_theme_list[j].theme_name,
            GetString((U16) (STR_THEME_DEFAULT + j)),
            MAX_THEME_NAME_LENGTH);
        g_tm_theme_list[j].theme_checksum_verified = CHECKSUM_VERIFIED_OK;
        g_tm_theme_list[j].theme_id = j + 1;
        g_tm_theme_list[j].theme_type = THEME_TYPE_SYSTEM;
    }

    g_tm_cntx.total_thm_cnt = g_tm_cntx.sys_thm_cnt = nSystemThemeCount;

    /* Read Themes from NVRAM */
    ReadRecord(
        NVRAM_EF_THEME_MANAGER_LID,
        1,
        (void*)(g_tm_theme_list + g_tm_cntx.sys_thm_cnt),
        NVRAM_EF_THEME_MANAGER_RECORD_SIZE,
        &err);
    /* err = 1 => NVRAM_READ_SUCCESS */
    if (err != NVRAM_READ_SUCCESS)
    {
        *theme_list_p = g_tm_theme_list;
        return g_tm_cntx.total_thm_cnt;
    }

    /* Sukrit: A better way to do it will be through something like does file exists on phone folder */

    sprintf(tmp_str, "%c%s", MMI_PUBLIC_DRV, DOWNLOADED_THEMES_PATH);
    mmi_asc_to_ucs2((PS8) theme_path_phone, tmp_str);
    dwnl_ph_thm_cnt = FS_Count(theme_path_phone, FS_FILE_TYPE, NULL, 0);

    sprintf(tmp_str, "%c%s", MMI_CARD_DRV, DOWNLOADED_THEMES_PATH);
    mmi_asc_to_ucs2((PS8) theme_path_card, tmp_str);
    dwnl_card_thm_cnt = FS_Count(theme_path_card, FS_FILE_TYPE, NULL, 0);

    ReadValue(THEME_MANAGER_MAX_THEME_ID, (void*)&buff, DS_DOUBLE, &err);
    max_theme_id = (U32) buff;
    if (max_theme_id == 0xFFFFFFFF || err == -1)
    {
        max_theme_id = 10;
        WriteValue(THEME_MANAGER_MAX_THEME_ID, (void*)&max_theme_id, DS_DOUBLE, &err);
    }

    tmp_theme_list_p = (tm_theme_list_struct*) & g_tm_NvramThmArr;

    /* Get all themes from NVRAM list, which are actually present on Phone, in a new theme list */
    /* Also, Count number of themes on phone and card that are actually on NVRAM */

    for (j = g_tm_cntx.sys_thm_cnt, k = 0; j < TOTAL_THEMES_COUNT; ++j)
    {
        if ((g_tm_theme_list[j].theme_type == THEME_TYPE_DOWNLOADED_PHONE))
        {
            mmi_ucs2ncpy((PS8) theme_path, (PS8) theme_path_phone, MAX_DWNL_THM_PATH_LEN);
            mmi_ucs2ncat((PS8) theme_path, (PS8) g_tm_theme_list[j].theme_name, MAX_THEME_NAME_LENGTH);
            error_code = FS_GetAttributes(theme_path);
            if (((error_code >= 0) && (error_code != FS_ATTR_DIR)) || (error_code == FS_ACCESS_DENIED))
            {
                memcpy((void*)(tmp_theme_list_p + k), (void*)&g_tm_theme_list[j], sizeof(tm_theme_list_struct));
                theme_type_bitmap[k] = THEME_TYPE_DOWNLOADED_PHONE;
                ++k;
                dwnl_ph_thm_cnt--;
            }
        }
        else if (g_tm_theme_list[j].theme_type == THEME_TYPE_DOWNLOADED_CARD)
        {
            mmi_ucs2ncpy((PS8) theme_path, (PS8) theme_path_card, MAX_DWNL_THM_PATH_LEN);
            mmi_ucs2ncat((PS8) theme_path, (PS8) g_tm_theme_list[j].theme_name, MAX_THEME_NAME_LENGTH);
            error_code = FS_GetAttributes(theme_path);
            if (((error_code >= 0) && (error_code != FS_ATTR_DIR)) || (error_code == FS_ACCESS_DENIED))
            {
                nvm_card_thm_cnt++;
                dwnl_card_thm_cnt--;
            }
        }
    }

    /* Insert new Phone themes in NVRAM list */

    sprintf(tmp_str, "%c%s%s", MMI_PUBLIC_DRV, DOWNLOADED_THEMES_PATH, THEME_SEARCH_STR);
    mmi_asc_to_ucs2((PS8) theme_search_path, tmp_str);
    if (dwnl_ph_thm_cnt > 0 && k < (MAX_DOWNLOADED_THEMES - nvm_card_thm_cnt))
    {
        if ((fh_cur = FS_FindFirst(
                        (U16*) theme_search_path,
                        0,
                        0,
                        &file_info,
                        (U16*) filename,
                        MAX_THEME_NAME_LENGTH * ENCODING_LENGTH)) >= 0)
        {
            do
            {
                MMI_BOOL theme_already_on_nvram_list = MMI_FALSE;

                /* Check if theme already in the list */
                for (j = g_tm_cntx.sys_thm_cnt; j < TOTAL_THEMES_COUNT; ++j)
                {
                    if (theme_type_bitmap[j - g_tm_cntx.sys_thm_cnt] == THEME_TYPE_DOWNLOADED_PHONE &&
                        mmi_ucs2cmp(
                            (PS8) tmp_theme_list_p[j - g_tm_cntx.sys_thm_cnt].theme_name,
                            (PS8) filename) == 0)
                    {
                        theme_already_on_nvram_list = MMI_TRUE;
                        theme_type_bitmap[j - g_tm_cntx.sys_thm_cnt] = 0xFF;
                        break;
                    }
                }

                if (theme_already_on_nvram_list == MMI_FALSE)
                {
                    memset((void*)&tmp_theme_list_p[k], 0, sizeof(tm_theme_list_struct));

                    if (file_info.NTReserved == FS_SFN_MATCH) /* File system returned a short file name */
                    {
                        mmi_chset_mixed_text_to_ucs2_str(
                            (U8*) tmp_theme_list_p[k].theme_name,
                            MAX_THEME_NAME_LENGTH * ENCODING_LENGTH,
                            (U8*) filename,
                            PhnsetGetDefEncodingType());
                    }
                    else
                    {
                        mmi_ucs2ncpy((PS8) tmp_theme_list_p[k].theme_name, (PS8) filename, MAX_THEME_NAME_LENGTH);
                    }

                    tmp_theme_list_p[k].theme_checksum_verified = CHECKSUM_NOT_VERIFIED;
                    tmp_theme_list_p[k].theme_id = ++max_theme_id;
                    tmp_theme_list_p[k].theme_type = THEME_TYPE_DOWNLOADED_PHONE;
                    ++k;
                    dwnl_ph_thm_cnt--;
                }
            } while (k < (MAX_DOWNLOADED_THEMES - nvm_card_thm_cnt) &&
                     (FS_FindNext(fh_cur, &file_info, (U16*) filename, MAX_THEME_NAME_LENGTH * ENCODING_LENGTH) ==
                      FS_NO_ERROR));
            FS_FindClose(fh_cur);
        }
    }

    /* Get all themes from NVRAM list, which are actually present on card, in a new theme list */
    for (j = g_tm_cntx.sys_thm_cnt; j < TOTAL_THEMES_COUNT; ++j)
    {
        if ((g_tm_theme_list[j].theme_type == THEME_TYPE_DOWNLOADED_CARD))
        {
            mmi_ucs2ncpy((PS8) theme_path, (PS8) theme_path_card, MAX_DWNL_THM_PATH_LEN);
            mmi_ucs2ncat((PS8) theme_path, (PS8) g_tm_theme_list[j].theme_name, MAX_THEME_NAME_LENGTH);

            error_code = FS_GetAttributes(theme_path);
            if (((error_code >= 0) && (error_code != FS_ATTR_DIR)) || (error_code == FS_ACCESS_DENIED))
            {
                memcpy((void*)(tmp_theme_list_p + k), (void*)&g_tm_theme_list[j], sizeof(tm_theme_list_struct));
                theme_type_bitmap[k] = THEME_TYPE_DOWNLOADED_CARD;
                ++k;
            }
        }
    }

    /* Insert new Card themes in NVRAM list */
    sprintf(tmp_str, "%c%s%s", MMI_CARD_DRV, DOWNLOADED_THEMES_PATH, THEME_SEARCH_STR);
    mmi_asc_to_ucs2((PS8) theme_search_path, tmp_str);

    if (dwnl_card_thm_cnt > 0 && k < MAX_DOWNLOADED_THEMES)
    {
        if ((fh_cur = FS_FindFirst(
                        (U16*) theme_search_path,
                        0,
                        0,
                        &file_info,
                        (U16*) filename,
                        MAX_THEME_NAME_LENGTH * ENCODING_LENGTH)) >= 0)
        {
            do
            {
                MMI_BOOL theme_already_on_nvram_list = MMI_FALSE;

                /* Check if theme already in the list */
                for (j = g_tm_cntx.sys_thm_cnt; j < TOTAL_THEMES_COUNT; ++j)
                {
                    if (theme_type_bitmap[j - g_tm_cntx.sys_thm_cnt] == THEME_TYPE_DOWNLOADED_CARD &&
                        mmi_ucs2cmp(
                            (PS8) tmp_theme_list_p[j - g_tm_cntx.sys_thm_cnt].theme_name,
                            (PS8) filename) == 0)
                    {
                        theme_already_on_nvram_list = MMI_TRUE;
                        theme_type_bitmap[j - g_tm_cntx.sys_thm_cnt] = 0xFF;
                        break;
                    }
                }

                if (theme_already_on_nvram_list == MMI_FALSE)
                {
                    memset((void*)&tmp_theme_list_p[k], 0, sizeof(tm_theme_list_struct));

                    if (file_info.NTReserved == FS_SFN_MATCH) /* File system returned a short file name */
                    {
                        mmi_chset_mixed_text_to_ucs2_str(
                            (U8*) tmp_theme_list_p[k].theme_name,
                            MAX_THEME_NAME_LENGTH * ENCODING_LENGTH,
                            (U8*) filename,
                            PhnsetGetDefEncodingType());
                    }
                    else
                    {
                        mmi_ucs2ncpy((PS8) tmp_theme_list_p[k].theme_name, (PS8) filename, MAX_THEME_NAME_LENGTH);
                    }

                    tmp_theme_list_p[k].theme_checksum_verified = CHECKSUM_NOT_VERIFIED;
                    tmp_theme_list_p[k].theme_id = ++max_theme_id;
                    tmp_theme_list_p[k].theme_type = THEME_TYPE_DOWNLOADED_CARD;
                    dwnl_card_thm_cnt--;
                    ++k;
                }

            } while (k < MAX_DOWNLOADED_THEMES &&
                     (FS_FindNext(fh_cur, &file_info, (U16*) filename, MAX_THEME_NAME_LENGTH * ENCODING_LENGTH) ==
                      FS_NO_ERROR));
            FS_FindClose(fh_cur);

        }
    }

    g_tm_cntx.total_thm_cnt = g_tm_cntx.sys_thm_cnt + k;

    memset((void*)(g_tm_theme_list + g_tm_cntx.sys_thm_cnt), 0, sizeof(tm_theme_list_struct) * MAX_DOWNLOADED_THEMES);
    memcpy((void*)(g_tm_theme_list + g_tm_cntx.sys_thm_cnt), tmp_theme_list_p, sizeof(tm_theme_list_struct) * k);

    /* Write Themes back to NVRAM */
    WriteRecord(
        NVRAM_EF_THEME_MANAGER_LID,
        1,
        (void*)(g_tm_theme_list + g_tm_cntx.sys_thm_cnt),
        NVRAM_EF_THEME_MANAGER_RECORD_SIZE,
        &err);
    /* err = 4 => NVRAM_WRITE_SUCCESS */
    WriteValue(THEME_MANAGER_MAX_THEME_ID, (void*)&max_theme_id, DS_DOUBLE, &err);

    *theme_list_p = g_tm_theme_list;
    return g_tm_cntx.total_thm_cnt;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_tm_activate_theme_at_bootup
 * DESCRIPTION
 *  This function activates theme at bootup time
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_tm_activate_theme_at_bootup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0, found = 0, result;
    U32 curr_theme_id;
	U32 usb_id;  
	S16 err;	
	U64 buff;   

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_USB_PREVIOUS_THEME_INDEX, (void*)&buff, DS_DOUBLE, &err);
	usb_id = (U32) buff;
	if (usb_id != -1)
	{
		WriteValue(THEME_MANAGER_CURR_THEME_ID, (void*)&usb_id, DS_DOUBLE, &err);
		usb_id = -1;
		WriteValue(NVRAM_USB_PREVIOUS_THEME_INDEX, (void*)&usb_id, DS_DOUBLE, &err);
	}
    curr_theme_id = mmi_tm_get_current_theme_id();
    for (i = 0; i < g_tm_cntx.total_thm_cnt; ++i)
    {
        if (curr_theme_id == g_tm_theme_list[i].theme_id)
        {
            found = 1;
            break;
        }
    }

    if (found)
    {
        if (g_tm_theme_list[i].theme_type == THEME_TYPE_SYSTEM)
        {
            result = mmi_tm_activate_system_theme(&g_tm_theme_list[i]);
        }
    #ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__      /* ritesh */
        else
        {
            result = mmi_tm_activate_downloaded_theme(&g_tm_theme_list[i]);
        }
    #endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 
        if (result != THEME_ERROR_SUCCESS)
        {
            mmi_tm_activate_system_theme(&g_tm_theme_list[0]);
            if (PhnsetIsWPCurrentTheme())
            {
                ThemeManagerSetWallpaper(IMG_ID_PHNSET_WP_0);
            }
            if (PhnsetIsScrSvrCurrentTheme())
            {
                ThemeManagerSetScreensaver(IMG_ID_PHNSET_SS_0);
            }
        #ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__      /* ritesh */
            ThemeManagerResetRingTone();
	#ifdef __MMI_DUAL_PROFILE_SUPPORT__
	     ThemeManagerResetCard2RingTone();
	#endif	/* __MMI_DUAL_PROFILE_SUPPORT__ */
            ThemeManagerResetAlarmTone();
        #endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ /* ritesh */
        }
        else
        {
            /* only set theme wallpaper when selected by user */
                if ( PhnsetIsWPCurrentTheme() ) 
                {
                    ThemeManagerSetWallpaper(IMG_ID_DISPCHAR_THEME_WALLPAPER);
                }
        
                    if (PhnsetIsScrSvrCurrentTheme())
                    {
                ThemeManagerSetScreensaver(IMG_ID_DISPCHAR_THEME_SCREENSAVER);
			}
        }

    }
    else
    {
        mmi_tm_activate_system_theme(&g_tm_theme_list[0]);
        if (PhnsetIsWPCurrentTheme())
        {
            ThemeManagerSetWallpaper(IMG_ID_PHNSET_WP_0);
        }

        if (PhnsetIsScrSvrCurrentTheme())
        {
            ThemeManagerSetScreensaver(IMG_ID_PHNSET_SS_0);
        }
    #ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__      /* ritesh */
        ThemeManagerResetRingTone();
    #ifdef __MMI_DUAL_PROFILE_SUPPORT__
	ThemeManagerResetCard2RingTone();
    #endif	/* __MMI_DUAL_PROFILE_SUPPORT__ */
        ThemeManagerResetAlarmTone();
    #endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ /* ritesh */
    }

    initialize_status_icons();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_activate_theme
 * DESCRIPTION
 *  This function activates theme at the time of theme selection
 * PARAMETERS
 *  theme_id        [IN]        
 * RETURNS
 *  theme error code
 *****************************************************************************/
tm_theme_error_enum mmi_tm_activate_theme(THEME_ID theme_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    tm_theme_error_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ShowCategory66Screen(STR_SCR3001_THEMES_CAPTION,0, 0, 0, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, (PU8)GetString(STR_ID_DLT_THM_PROGRESS), IMG_THEME_ACTIVATION, NULL); */

    if (g_tm_cntx.curr_activated_theme_id == theme_id)
    {
        return THEME_ERROR_ALREADY_ACTIVATED;
    }

    for (i = 0; i < g_tm_cntx.total_thm_cnt; ++i)
    {
        if (theme_id == g_tm_theme_list[i].theme_id)
        {
            break;
        }
    }

    if (g_tm_theme_list[i].theme_type == THEME_TYPE_SYSTEM)
    {
        result = mmi_tm_activate_system_theme(&g_tm_theme_list[i]);
    }
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__      /* ritesh */
    else
    {
        result = mmi_tm_activate_downloaded_theme(&g_tm_theme_list[i]);
    }
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ /* ritesh */

    if (result == THEME_ERROR_SUCCESS)
    {
        /* only set theme wallpaper when selected by user */
            if ( PhnsetIsWPCurrentTheme() ) 
            {
                ThemeManagerSetWallpaper(IMG_ID_DISPCHAR_THEME_WALLPAPER);
            }
    
                if (PhnsetIsScrSvrCurrentTheme())
                {
            ThemeManagerSetScreensaver(IMG_ID_DISPCHAR_THEME_SCREENSAVER);
        }
    #ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__      /* ritesh */
        if (g_tm_cntx.theme_has_ringtone)
        {
            ThemeManagerSetRingTone(CURRENT_THEME_INCOMING_CALL_TONE);
	#ifdef __MMI_DUAL_PROFILE_SUPPORT__
	     ThemeManagerSetCard2RingTone(CURRENT_THEME_INCOMING_CALL_TONE);
	#endif	/* __MMI_DUAL_PROFILE_SUPPORT__ */
            ThemeManagerSetAlarmTone(CURRENT_THEME_ALARM_EXPIRY_TONE);
        }
        else
        {
            ThemeManagerResetRingTone();
	#ifdef __MMI_DUAL_PROFILE_SUPPORT__
	     ThemeManagerResetCard2RingTone();
	#endif	/* __MMI_DUAL_PROFILE_SUPPORT__ */
            ThemeManagerResetAlarmTone();
        }
    #endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ /* ritesh */

        initialize_status_icons();
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_activate_system_theme
 * DESCRIPTION
 *  This function activates system theme
 * PARAMETERS
 *  theme_struct_p      [?]     [?]
 * RETURNS
 *  theme error code
 *****************************************************************************/
tm_theme_error_enum mmi_tm_activate_system_theme(tm_theme_list_struct *theme_struct_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 err;
    U64 buff;     
	U32 usb_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* reset NVRAM_USB_PREVIOUS_THEME_INDEX if there's value there */
    if (g_tm_USB_mode == TRUE)
    {
    	ReadValue(NVRAM_USB_PREVIOUS_THEME_INDEX, (void*)&buff, DS_DOUBLE, &err);
    	usb_id = (U32) buff;
    	if (usb_id != -1)
    	{			
    		usb_id = -1;
    		WriteValue(NVRAM_USB_PREVIOUS_THEME_INDEX, (void*)&usb_id, DS_DOUBLE, &err);
    	}
    }
    
    /* todo: To copy from MCT */
    g_tm_cntx.curr_activated_theme_type = theme_struct_p->theme_type;
    g_tm_cntx.theme_has_alternate_image = FALSE;
    g_tm_activated_theme.system_image_list = NULL;
    g_tm_activated_theme.theme = NULL;
    g_tm_activated_theme.theme_image_details_list = NULL;
    g_tm_cntx.theme_has_wallpaper = FALSE;
    g_tm_cntx.theme_has_screensaver = FALSE;
    g_tm_cntx.theme_has_ringtone = FALSE;
    set_MMI_theme((MMI_theme*) MMI_themes[(theme_struct_p->theme_id - 1)].theme);
    MMI_apply_current_theme();

    DRM_close_file(g_tm_cntx.theme_file_handle);
    g_tm_cntx.theme_file_handle = 0;

    g_tm_cntx.curr_activated_theme_id = theme_struct_p->theme_id;
    g_tm_cntx.curr_activated_theme_type = theme_struct_p->theme_type;
    WriteValue(THEME_MANAGER_CURR_THEME_ID, (void*)&g_tm_cntx.curr_activated_theme_id, DS_DOUBLE, &err);
    return THEME_ERROR_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_sort_theme_image_table
 * DESCRIPTION
 *  this function sort the table containg image id to offset mapping
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_tm_sort_theme_image_table(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_tm_cntx.theme_imageid_image_count)
    {
        mmi_tm_image_table_quick_sort(0, (U16) (g_tm_cntx.theme_imageid_image_count - 1));
        mmi_tm_image_table_insertion_sort(0, (U16) (g_tm_cntx.theme_imageid_image_count - 1));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_image_table_quick_sort
 * DESCRIPTION
 *  It sorts the table using quick sort algorithm
 * PARAMETERS
 *  l       [IN]        
 *  r       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_tm_image_table_quick_sort(U16 l, U16 r)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, j;
    U32 pivot;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((r - l) > 4)
    {
        i = (r + l) / 2;
        if (g_tm_activated_theme.theme_image_details_list[l].image_id >
            g_tm_activated_theme.theme_image_details_list[i].image_id)
        {
            mmi_tm_image_table_swap_node(l, i);
        }
        if (g_tm_activated_theme.theme_image_details_list[l].image_id >
            g_tm_activated_theme.theme_image_details_list[r].image_id)
        {
            mmi_tm_image_table_swap_node(l, r);
        }
        if (g_tm_activated_theme.theme_image_details_list[i].image_id >
            g_tm_activated_theme.theme_image_details_list[r].image_id)
        {
            mmi_tm_image_table_swap_node(i, r);
        }

        j = r - 1;
        mmi_tm_image_table_swap_node(i, j);
        i = l;
        pivot = g_tm_activated_theme.theme_image_details_list[j].image_id;

        for (;;)
        {
            do
            {
            } while (g_tm_activated_theme.theme_image_details_list[++i].image_id < pivot);
            do
            {
            } while (g_tm_activated_theme.theme_image_details_list[--j].image_id > pivot);

            if (j < i)
            {
                break;
            }

            mmi_tm_image_table_swap_node(i, j);
        }

        mmi_tm_image_table_swap_node(i, (U16) (r - 1));
        mmi_tm_image_table_quick_sort(l, j);
        mmi_tm_image_table_quick_sort((U16) (i + 1), r);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_image_table_insertion_sort
 * DESCRIPTION
 *  It sorts the table using insertion sort algorithm
 * PARAMETERS
 *  lo      [IN]        
 *  hi      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_tm_image_table_insertion_sort(U16 lo, U16 hi)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, j;
    theme_image_detail_struct elem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = lo + 1; i <= hi; ++i)
    {
        memcpy(&elem, &g_tm_activated_theme.theme_image_details_list[i], sizeof(theme_image_detail_struct));

        j = i;
        while (j > lo)
        {
            if (g_tm_activated_theme.theme_image_details_list[j - 1].image_id <= elem.image_id)
            {
                break;
            }
            memcpy(
                &g_tm_activated_theme.theme_image_details_list[j],
                &g_tm_activated_theme.theme_image_details_list[j - 1],
                sizeof(theme_image_detail_struct));
            j--;
        }
        memcpy(&g_tm_activated_theme.theme_image_details_list[j], &elem, sizeof(theme_image_detail_struct));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_image_table_swap_node
 * DESCRIPTION
 *  It swaps the theme images
 * PARAMETERS
 *  i       [IN]        
 *  j       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_tm_image_table_swap_node(U16 i, U16 j)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    theme_image_detail_struct temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(&temp, &g_tm_activated_theme.theme_image_details_list[i], sizeof(theme_image_detail_struct));
    memcpy(
        &g_tm_activated_theme.theme_image_details_list[i],
        &g_tm_activated_theme.theme_image_details_list[j],
        sizeof(theme_image_detail_struct));
    memcpy(&g_tm_activated_theme.theme_image_details_list[j], &temp, sizeof(theme_image_detail_struct));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_get_current_theme_id
 * DESCRIPTION
 *  This function gets the current theme ID
 * PARAMETERS
 *  void
 * RETURNS
 *  numeric theme id value
 *****************************************************************************/
U32 mmi_tm_get_current_theme_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 err;
    U64 buff;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(THEME_MANAGER_CURR_THEME_ID, (void*)&buff, DS_DOUBLE, &err);
    g_tm_cntx.curr_activated_theme_id = (U32) buff;
    if (g_tm_cntx.curr_activated_theme_id == 0xFFFFFFFF || err == -1)
    {
        g_tm_cntx.curr_activated_theme_id = 1;
        WriteValue(THEME_MANAGER_CURR_THEME_ID, (void*)&g_tm_cntx.curr_activated_theme_id, DS_DOUBLE, &err);
    }

    return g_tm_cntx.curr_activated_theme_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_does_theme_have_alt_image
 * DESCRIPTION
 *  This function checks whether downloadable theme has alternative image or not
 * PARAMETERS
 *  void
 * RETURNS
 *  true if alternate image present otherwise false
 *****************************************************************************/
U8 mmi_tm_does_theme_have_alt_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_tm_cntx.theme_has_alternate_image;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_is_theme_dirty_bit_set
 * DESCRIPTION
 *  This function checks whether dirty bit is set for the image or not
 * PARAMETERS
 *  image_index     [IN]        
 * RETURNS
 *  true if dirty bit set otherwise false
 *****************************************************************************/
U8 mmi_tm_is_theme_dirty_bit_set(U16 image_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 n_byte;
    U16 n_bit;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    n_byte = (image_index >> 3);
    n_bit = (image_index % 8);

    return (U8) ((g_tm_theme_image_dirty_bits[n_byte]) & (0x80 >> n_bit));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_get_theme_image_offset_or_index
 * DESCRIPTION
 *  This function gets the offset/index for the image
 * PARAMETERS
 *  image_id            [IN]        
 *  nArrayIndex_p       [?]         [?]
 * RETURNS
 *  numeric value of image offset or index
 *****************************************************************************/
U32 mmi_tm_get_theme_image_offset_or_index(U16 image_id, S32 *nArrayIndex_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nFirst = 0;
    S32 nLast = g_tm_cntx.theme_imageid_image_count;
    S32 nMid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (nLast >= nFirst)
    {
        nMid = (nFirst + nLast) / 2;;
        if (g_tm_activated_theme.theme_image_details_list[nMid].image_id == image_id)
        {
            *nArrayIndex_p = nMid;
            return g_tm_activated_theme.theme_image_details_list[nMid].image_offset;
        }
        if (image_id > g_tm_activated_theme.theme_image_details_list[nMid].image_id)
        {
            nFirst = nMid + 1;
        }
        else
        {
            nLast = nMid - 1;
        }
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_get_curr_theme_type
 * DESCRIPTION
 *  This function returns the current activated theme type
 * PARAMETERS
 *  void
 * RETURNS
 *  numeric value of the theme type
 *****************************************************************************/
U8 mmi_tm_get_curr_theme_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_tm_cntx.curr_activated_theme_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_get_total_themes_count
 * DESCRIPTION
 *  It gets the total no. of the themes
 * PARAMETERS
 *  void
 * RETURNS
 *  total number of themes
 *****************************************************************************/
U8 mmi_tm_get_total_themes_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_tm_cntx.total_thm_cnt;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_get_current_theme_wallapaper
 * DESCRIPTION
 *  This function gets the current theme wallpaper
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_tm_get_current_theme_wallapaper(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_tm_cntx.theme_has_wallpaper;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_get_current_theme_screensaver
 * DESCRIPTION
 *  This function gets the current theme screensaver
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_tm_get_current_theme_screensaver(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_tm_cntx.theme_has_screensaver;
}
#endif /* (defined(__MMI_THEMES_V2_SUPPORT__)) */ 


