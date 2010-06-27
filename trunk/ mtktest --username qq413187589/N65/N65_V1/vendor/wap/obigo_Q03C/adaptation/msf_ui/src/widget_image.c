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
 * widget_image.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * Widget image loading and caching in filesystem
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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

#include "widget.h"
#include "msf_cmmn.h"   /* for msf_cmmn_strcmp_nc() */

#include "ScrMemMgrGprot.h"

#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"

#include "lcd_sw_rnd.h"
#include "gdi_include.h"
#include "gdi_image_bmp.h"
#include "gdi_image_wbmp.h"
#include "gdi_image_gif.h"
#include "gdi_image_jpeg.h"
#include "gdi_image_png.h"
#include "wgui_categories.h"

#include "FileManagerGprot.h"

#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "mdi_camera.h"
#include "mdi_video.h"

#include "lcd_sw_rnd.h"

#ifdef __DRM_SUPPORT__
#include "drm_gprot.h"
#endif 

#ifndef __MTK_TARGET__
#include "stdio.h"
#endif 

/*
 * NOTE: 
 * * 1. CHANGES SHOULD BE SYNCHRONIZED WITH widget_sound.c 
 * * 2. Be sure to check if widget_image_struct->raw == NULL
 * * 3. On resource creation - we can return 0 if the image creation failed (Confirmed by Teleca)
 */

typedef struct
{
    char org_file_name[WIDGET_RAWFILE_NAMELEN + 1];
    int org_file_handle;
    int ref;
} widget_virtual_file_info_struct;

#define WIDGET_VIRTUAL_FILE_INFO_TABLE_SIZE (3)

/* to check the image resolution if exceed MSF_INT16 */
#define WIDGET_IMAGE_TOO_LARGE_WIDTH        (0x7FFF)
#define WIDGET_IMAGE_TOO_LARGE_HEIGHT       (0x7FFF)

static int videoResourceCount = 0;

static void widget_send_notification_load_resource(widget_image_struct *img, /* kal_bool */ int state);
static widget_virtual_file_info_struct widget_virtual_file_info_table[WIDGET_VIRTUAL_FILE_INFO_TABLE_SIZE];
static widget_pre_image_struct widget_predefined_image_table[WAP_IMAGE_ID_END - WAP_IMAGE_ID_BEGIN];
static kal_int32 widget_initialize_image_dimension(MsfImageHandle image);
static void widget_create_video_resource(widget_image_struct *img);

#ifdef WIDGET_CHECK_IMAGE_IN_DETAIL
static kal_bool widget_check_image_in_detail(MsfImageHandle img);
#endif

/****************************************************************
 * Image format and filename extension conversion
 ***************************************************************/
typedef struct
{
    MsfImageFormat format;
    char fn_ext[6]; /* filename extension */
    const char *mime_type;
    U8 MMI_type;
} widget_image_typeinfo_struct;

/* Reference: mea_cfg.h, sma_cfg.h, sls_cfg.h, msf_mime.c */
const widget_image_typeinfo_struct widget_image_typeinfo_table[] = 
{
    {MsfBmp, ".bmp", "image/bmp", IMAGE_TYPE_BMP},
    {MsfPictogram, ".pic", NULL, IMAGE_TYPE_INVALID},
    {MsfGif, ".gif", "image/gif", IMAGE_TYPE_GIF},
    /* We will use jpg instead of .jpeg by default */
    {MsfJpeg, ".jpg", "image/jpeg", IMAGE_TYPE_JPG},
    {MsfJpeg, ".jpeg", "image/jpeg", IMAGE_TYPE_JPG},
    {MsfPng, ".png", "image/png", IMAGE_TYPE_INVALID},
    {MsfWbmp, ".wbmp", "image/vnd.wap.wbmp", IMAGE_TYPE_WBMP},
    {MsfWbmp, ".wbm", "image/vnd.wap.wbmp", IMAGE_TYPE_WBMP},
    {Msf3gp, ".3gp", "video/3gpp", IMAGE_TYPE_3GP},   /* autumn */
    {Msf3gp, ".3g2", "video/3gpp2",IMAGE_TYPE_3GP},   /* autumn */
    {MsfMp4, ".mp4", "video/mp4", IMAGE_TYPE_MP4},
    {MsfMp4, ".mpeg", "video/mpeg", IMAGE_TYPE_MP4},
    {MsfAvi, ".avi", "video/x-msvideo", IMAGE_TYPE_AVI},
    /* Actually we should not download a proprietary pbm file from WAP web site */
    {(MsfImageFormat) MsfPbmPI, ".pbm", NULL, IMAGE_TYPE_DEVICE_BITMAP}
};

#define WIDGET_IMAGE_TYPEINFO_NUM   (sizeof(widget_image_typeinfo_table)/sizeof(widget_image_typeinfo_struct))


/*****************************************************************************
 * FUNCTION
 *  widget_image_format_to_extension
 * DESCRIPTION
 *  
 * PARAMETERS
 *  format      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static const char *widget_image_format_to_extension(MsfImageFormat format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    const widget_image_typeinfo_struct *item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < WIDGET_IMAGE_TYPEINFO_NUM; i++)
    {
        item = &widget_image_typeinfo_table[i];
        if (item->format == format)
        {
            return item->fn_ext;
        }
    }
    /* WAP_DBG_ASSERT(0); */
    return ".gif";  /* It should not return NULL. Whatever! */
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtMsfToMMIImageFormat
 * DESCRIPTION
 *  Convert MsfImageFormat to MMI image type
 * PARAMETERS
 *  format      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 HDIa_widgetExtMsfToMMIImageFormat(MsfImageFormat format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    const widget_image_typeinfo_struct *item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < WIDGET_IMAGE_TYPEINFO_NUM; i++)
    {
        item = &widget_image_typeinfo_table[i];
        if (item->format == format)
        {
            return item->MMI_type;
        }
    }

    return IMAGE_TYPE_INVALID;
}

#if 0   /* Deprecated 2004.08 */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtFileNameToMimeType
 * DESCRIPTION
 *  Used by MEA to determine the content of a file from file manager
 * PARAMETERS
 *  fname       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
const char *HDIa_widgetExtFileNameToMimeType(const char *fname)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    const char *c = strrchr(fname, '.');

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (c == NULL)
    {
        return NULL;
    }

    for (i = 0; i < WIDGET_IMAGE_TYPEINFO_NUM; i++)
    {
        if (msf_cmmn_strcmp_nc(c, widget_image_typeinfo_table[i].fn_ext) == 0)
        {
            return widget_image_typeinfo_table[i].mime_type;
        }
    }

#ifdef __MMI_VCARD__
    if (msf_cmmn_strcmp_nc(c, ".vcf") == 0)
    {
        return "text/x-vcard";
    }
#endif /* __MMI_VCARD__ */ 

#ifdef __MMI_VCALENDAR__
    if (msf_cmmn_strcmp_nc(c, ".vcs") == 0)
    {
        return "text/x-vcalendar";
    }
#endif /* __MMI_VCALENDAR__ */ 

    if (msf_cmmn_strcmp_nc(c, ".mp4") == 0)
    {
        return "video/mp4";
    }
    if (msf_cmmn_strcmp_nc(c, ".mpg") == 0)
    {
        return "video/mpeg";
    }
    if (msf_cmmn_strcmp_nc(c, ".3gp") == 0)
    {
        return "video/3gpp";
    }
    if (msf_cmmn_strcmp_nc(c, ".3g2") == 0)
    {
        return "video/3gpp2";
    }
    if (msf_cmmn_strcmp_nc(c, ".avi") == 0)
    {
        return "video/x-msvideo";
    }

    if (msf_cmmn_strcmp_nc(c, ".jad") == 0)
    {
        return "text/vnd.sun.j2me.app-descriptor";
    }
    if (msf_cmmn_strcmp_nc(c, ".jar") == 0)
    {
        return "application/java-archive";
    }

    /* check sound */
    return widget_sound_file_ext_to_mime_type(c);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtMimeTypeToFileExt
 * DESCRIPTION
 *  Typically used for "Save As to filesystem"
 * PARAMETERS
 *  mime        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
/* Reference: HDIa_widgetExtFmgrMediaInput */
const char *HDIa_widgetExtMimeTypeToFileExt(const char *mime)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Even if we do not support certain content type, we still provide filename extension such that
       users can still save downloaded files. */
    char mime_type[100];    /* lower case */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mime)
    {
        return NULL;
    }

    memset(mime_type, 0x00, 100);
    msf_cmmn_strcpy_lc(mime_type, mime);

    if (strstr(mime_type, "wbmp"))
    {
        return ".wbmp";
    }
    else if (strstr(mime_type, "bmp"))
    {
        return ".bmp";
    }
    else if (strstr(mime_type, "jpeg"))
    {
        return ".jpg";
    }
    else if (strstr(mime_type, "png"))
    {
        return ".png";
    }
    else if (strstr(mime_type, "gif"))
    {
        return ".gif";
    }
    else if (strstr(mime_type, "mid"))  /* Including "audio/mid" */
    {
        return ".mid";
    }
    else if (strstr(mime_type, "smaf"))
    {
        return ".mmf";
    }
    else if (strstr(mime_type, "wav"))
    {
        return ".wav";
    }
    else if (strstr(mime_type, "amr-wb"))
    {
        return ".awb";
    }
    else if (strstr(mime_type, "amr"))
    {
        return ".amr";
    }
    else if (strstr(mime_type, "mp3") || strstr(mime_type, "audio/mpeg"))       /* with disagreement */
    {
        return ".mp3";
    }
    else if (strstr(mime_type, "imelody"))
    {
        return ".imy";
    }
    else if (strstr(mime_type, "text/x-vcard")) /* Jo, vObject support */
    {
        return ".vcf";
    }
    else if (strstr(mime_type, "text/x-vcalendar"))
    {
        return ".vcs";
    }
#ifdef __DRM_SUPPORT__
    else if (strstr(mime_type, "application/vnd.oma.drm.message"))
    {
        return ".dm";
    }
    else if (strstr(mime_type, "application/vnd.oma.drm.content"))
    {
        return ".dcf";
    }
#endif /* __DRM_SUPPORT__ */ 
    else if (strstr(mime_type, "video/3gpp"))
    {
        return ".3gp";
    }
    else if (strstr(mime_type, "video/3gpp2"))
    {
        return ".3g2";
    }
    /* On early 2005, mpeg4 MIME type is still draft, but we can compare keyword mp4 and mpeg4 */
    else if (strstr(mime_type, "video/mp4"))
    {
        return ".mp4";
    }
    else if (strstr(mime_type, "video/mpeg"))
    {
        return ".mpg";
    }
    else if (strstr(mime_type, "video/x-msvideo"))
    {
        return ".avi";
    }
    else if (strstr(mime_type, "text/vnd.sun.j2me.app-descriptor"))
    {
        return ".jad";
    }
    else if (strstr(mime_type, "application/java-archive"))
    {
        return ".jar";
    }
    else
    {
        return NULL;
    }

}

/****************************************************************
 * Rawfile manager
 ***************************************************************/

#define RAWFILE_FILE_IS_CREATED(item)  ((item)->size > 0)
#define RAWFILE_FILE_IS_EMPTY(item)    ((item)->size == 0)
#define RAWFILE_FILE_IS_BROKEN(item)   ((item)->size < 0)
#define RAWFILE_FILE_SIZE(item)        (((item)->size > 0) ? (item)->size : 0)
#define RAWFILE_FILENAME_IS_VALID(item) (strlen((item)->filename) > 0)

#define RAWFILE_GET_SLOT(file_id)   (WRAW_CTX->ptrs[(file_id)-1])
#define RAWFILE_VALID_FILE_ID(file_id) ((file_id) >= 1 && (file_id) <= MAX_WIDGET_CREATED_RAWFILE_SUM && \
                           (RAWFILE_GET_SLOT(file_id) != NULL) && RAWFILE_GET_SLOT(file_id)->handle != 0)

#define RAWFILE_FAILSAFE         (1)


/*****************************************************************************
 * FUNCTION
 *  widget_init_rawfile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_init_rawfile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WRAW_CTX->enabled = KAL_FALSE;

    /* Reset global data */
    memset(WRAW_CTX->ptrs, 0, sizeof(WRAW_CTX->ptrs));

    WRAW_CTX->total_size = 0;
    WRAW_CTX->working_buffer = MSF_MEM_ALLOC(MSF_MODID_WIDGET, WIDGET_LOAD_BUFFER_SIZE);

    /* Always try to create the directory because SweepDrive() may delete the folder */
    HDIa_fileMkDir(WIDGET_RAWFILE_DIRECTORY);
#ifndef MMS_IN_LARGE_STORAGE
    HDIa_fileMkDir(WIDGET_RAWFILE_MMS_DIRECTORY);
#endif 

    /* Remove old files */
    msm_remove_files_under_dir(WIDGET_RAWFILE_DIRECTORY);
#ifndef MMS_IN_LARGE_STORAGE
    msm_remove_files_under_dir(WIDGET_RAWFILE_MMS_DIRECTORY);
#endif 

    WRAW_CTX->enabled = KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  widget_deinit_rawfile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_deinit_rawfile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_MEM_FREE(MSF_MODID_WIDGET, WRAW_CTX->working_buffer);
    WRAW_CTX->working_buffer = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  widget_rawfile_allow_to_create_image
 * DESCRIPTION
 *  Do we need to use rawfile cache
 * PARAMETERS
 *  image_format        [IN]        (deprecated parameter)
 *  size                [IN]        (deprecated parameter)
 * RETURNS
 *  Whether we can cache image data in filesystem
 *****************************************************************************/
kal_bool widget_rawfile_allow_to_create_image(MsfImageFormat image_format, int size)
{
#if defined(__FS_QM_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Because the disk support Quota management, assume that disk full is allowed */
    int free_space;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    free_space = FS_QmGetFree((BYTE*) "Z:\\@wcache\\");
    if (WRAW_CTX->enabled &&
        (free_space < 0 /* quota not configured */  || free_space >= WIDGET_RAWFILE_RESERVE_SPACE_MIN))
#else /* defined(__FS_QM_SUPPORT__) */ 
    /* No protection at all. Deprecated */
    if (WRAW_CTX->enabled && msm_get_disk_free_space(0) > WIDGET_RAWFILE_FREE_SPACE_WATERMARK)
#endif /* defined(__FS_QM_SUPPORT__) */ 
    {
        return KAL_TRUE;
    }
    else
    {
        /* System has troubles */
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_rawfile_allow_to_create_sound
 * DESCRIPTION
 *  Do we need to use rawfile cache
 * PARAMETERS
 *  void
 * RETURNS
 *  Whether we can cache sound data in filesystem
 *****************************************************************************/
kal_bool widget_rawfile_allow_to_create_sound(void)
{
#if defined(__FS_QM_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Because the disk support Quota management, assume that disk full is allowed */
    int free_space;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    free_space = FS_QmGetFree((BYTE*) "Z:\\@wcache\\");
    if (WRAW_CTX->enabled &&
        (free_space < 0 /* quota not configured */  || free_space >= WIDGET_RAWFILE_RESERVE_SPACE_MIN))
#else /* defined(__FS_QM_SUPPORT__) */ 
    /* No protection at all. Deprecated */
    if (WRAW_CTX->enabled && msm_get_disk_free_space(0) > WIDGET_RAWFILE_FREE_SPACE_WATERMARK)
#endif /* defined(__FS_QM_SUPPORT__) */ 
    {
        return KAL_TRUE;
    }
    else
    {
        /* System has troubles */
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_rawfile_is_virtual_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_id     [IN]        Rawfild_id
 * RETURNS
 *  return KAL_TRUE if it's the virtual file
 *****************************************************************************/
kal_bool widget_rawfile_is_virtual_file(kal_int16 file_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!RAWFILE_VALID_FILE_ID(file_id))
    {
        WAP_DBG_ASSERT(0);
        return KAL_FALSE;
    }

    if (RAWFILE_GET_SLOT(file_id)->is_virtual_file == KAL_TRUE)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_rawfile_gen_virtual_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_id     [IN]        Rawfild_id
 *  org_fd      [IN]        The orginal file handle
 *  offset      [IN]        The start position
 *  size        [IN]        The virtual file size
 * RETURNS
 *  return KAL_TRUE if generating the virtual file name succeed
 *****************************************************************************/
kal_bool widget_rawfile_gen_virtual_file(kal_int16 file_id, int org_fd, int offset, int size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_rawfile_item_struct *item = RAWFILE_GET_SLOT(file_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!RAWFILE_VALID_FILE_ID(file_id))
    {
        WAP_DBG_ASSERT(0);
        return KAL_FALSE;
    }
    /* Don't need to check the offset and size. */
    /* It already check in HDIa_widgetImageCreateResource's MsfResourcePartialFile */

    if (!HDIa_fileGenVirtualFileName(org_fd, item->filename, sizeof(item->filename), offset, size))
    {
        /* generate the virtual file name succeed */
        item->is_virtual_file = TRUE;
        item->org_file_handle = org_fd;
        item->size = size;
        return KAL_TRUE;
    }

    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  widget_open_check_original_file_for_virtual_file
 * DESCRIPTION
 *  The function checks that the original file is already opened for other virtual files
 * PARAMETERS
 *  data        [IN]     The partial file data
 * RETURNS
 *  return the file handle.
 *  If open and check the file succeed, the reutrn valuse is >=0.
 *****************************************************************************/
int widget_open_check_original_file_for_virtual_file(MsfPartialFileData *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool is_found = KAL_FALSE;
    int i, empty_index = 0;
    int f = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < WIDGET_VIRTUAL_FILE_INFO_TABLE_SIZE; i++)
    {
        if (widget_virtual_file_info_table[i].org_file_name[0] == '\0')
        {
            /* try to find the index of the empty record */
            empty_index = i;
            continue;
        }
        if (!strcmp(widget_virtual_file_info_table[i].org_file_name, data->filename))
        {
            f = widget_virtual_file_info_table[i].org_file_handle;
            is_found = KAL_TRUE;
            break;
        }
    }

    if (is_found == KAL_FALSE)
    {
        f = HDIa_fileOpen(MSF_MODID_WIDGET, data->filename, HDI_FILE_SET_RDONLY, 0);
        if (f < 0)
        {
            return HDI_FILE_ERROR_ACCESS;
        }
        i = empty_index;
        WAP_DBG_ASSERT(strlen(data->filename) <= 255);
        widget_virtual_file_info_table[i].org_file_handle = f;
        strcpy(widget_virtual_file_info_table[i].org_file_name, data->filename);
    }
    /* add the reference counter */
    widget_virtual_file_info_table[i].ref++;

    if (HDIa_fileGetSize(data->filename) < (data->start_offset + data->data_size))
    {
        WAP_DBG_ASSERT(0);  /*  it should not happen */
        widget_virtual_file_info_table[i].ref--;
        if (widget_virtual_file_info_table[i].ref == 0)
        {
            HDIa_fileClose(f);
        }
        return HDI_FILE_ERROR_INVALID;
    }
    return f;
}


/*****************************************************************************
 * FUNCTION
 *  widget_close_original_file_of_virtual_file
 * DESCRIPTION
 *  Close the original file that used for the virtual files
 * PARAMETERS
 *  org_fd      [IN]        the original file handle
 * RETURNS
 *  void
 *****************************************************************************/
void widget_close_original_file_of_virtual_file(int org_fd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < WIDGET_VIRTUAL_FILE_INFO_TABLE_SIZE; i++)
    {
        if (widget_virtual_file_info_table[i].org_file_handle == org_fd)
        {
            widget_virtual_file_info_table[i].ref--;
            if (widget_virtual_file_info_table[i].ref == 0)
            {
                memset(&widget_virtual_file_info_table[i], 0, sizeof(widget_virtual_file_info_struct));
                HDIa_fileClose(org_fd);
            }
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_is_rawfile_full
 * DESCRIPTION
 *  Check if there is enough resource for rawfile mechanism
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool widget_is_rawfile_full()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_WIDGET_CREATED_RAWFILE_SUM; i++)
    {
        if (!WRAW_CTX->ptrs[i])
        {
            return KAL_FALSE;
        }
    }
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  widget_rawfile_register
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int16 widget_rawfile_register(MSF_UINT32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int16 i = 0;
    widget_rawfile_item_struct *item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(IS_IMAGE_TYPE(handle) || IS_SOUND_TYPE(handle));

    for (i = 0; i < MAX_WIDGET_CREATED_RAWFILE_SUM; i++)
    {
        if (!WRAW_CTX->ptrs[i])
        {
            item = WRAW_CTX->ptrs[i] = (widget_rawfile_item_struct*)
                MSF_MEM_ALLOC(MSF_MODID_WIDGET, sizeof(widget_rawfile_item_struct));

            memset(item, 0, sizeof(widget_rawfile_item_struct));
            item->handle = handle;
            item->size = 0;
            item->format = MsfUnsupportedMediaType;
        #ifdef MMS_IN_LARGE_STORAGE
            if (_IMG(handle)->module_id == MSF_MODID_MEA || 
                _IMG(handle)->module_id == MSF_MODID_SMA)
            {
                /* for MMS */
                sprintf(item->filename, "%s%02d", WIDGET_RAWFILE_MMS_DIRECTORY, i + 1);
            }
            else
        #endif /* MMS_IN_LARGE_STORAGE */ 
            {
                /* common case for browser */
                sprintf(item->filename, "%s%02d", WIDGET_RAWFILE_DIRECTORY, i + 1);
            }
        #ifdef RAWFILE_FAILSAFE
            WAP_DBG_ASSERT(HDIa_fileGetSize(item->filename) < 0);       /* File not existed */
            HDIa_fileRemove(item->filename);    /* failsafe */
        #endif /* RAWFILE_FAILSAFE */ 
            return i + 1;
        }
    }

    /* No empty slots. Restart mobile suite. */
    return 0;   /* UNREACHED */
}


/*****************************************************************************
 * FUNCTION
 *  widget_rawfile_deregister
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_id     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_rawfile_deregister(kal_int16 file_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_rawfile_item_struct *item = RAWFILE_GET_SLOT(file_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(RAWFILE_VALID_FILE_ID(file_id));

    if (RAWFILE_FILE_IS_CREATED(item))
    {
        if (widget_rawfile_is_virtual_file(file_id))
        {
            widget_close_original_file_of_virtual_file(item->org_file_handle);
        }
        else
        {
            /* remove the wcache file */
            HDIa_fileRemove(item->filename);
            WRAW_CTX->total_size -= item->size;
        }
    }

    MSF_MEM_FREE(MSF_MODID_WIDGET, item);
    RAWFILE_GET_SLOT(file_id) = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  widget_rawfile_getname
 * DESCRIPTION
 *  Return a name only if the file is created and not empty
 * PARAMETERS
 *  file_id     [IN]        
 * RETURNS
 *  ASCII filename
 *  It might return NULL.
 *****************************************************************************/
char *widget_rawfile_getname(kal_int16 file_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_rawfile_item_struct *item = RAWFILE_GET_SLOT(file_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!RAWFILE_VALID_FILE_ID(file_id))
    {
        WAP_DBG_ASSERT(0);
        return NULL;
    }

    if (!RAWFILE_FILENAME_IS_VALID(item))
    {
        WAP_DBG_ASSERT(0);
        return NULL;
    }

    if (!RAWFILE_FILE_IS_CREATED(item))
    {
        return NULL;    /* Invalid/Empty image */
    }

    return item->filename;
}


/*****************************************************************************
 * FUNCTION
 *  widget_rawfile_getsize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_id     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int widget_rawfile_getsize(kal_int16 file_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_rawfile_item_struct *item = RAWFILE_GET_SLOT(file_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (RAWFILE_VALID_FILE_ID(file_id))
    {
        return RAWFILE_FILE_SIZE(item);
    }
    else
    {
        WAP_DBG_ASSERT(0);
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_rawfile_write_failed
 * DESCRIPTION
 *  write the rawfile failed. The reason should be the space is not enough
 * PARAMETERS
 *  file_id     [IN]        
 * RETURNS
 *  return KAL_TRUE if the rawfile is broken
 *****************************************************************************/
kal_bool widget_rawfile_write_failed(kal_int16 file_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_rawfile_item_struct *item = RAWFILE_GET_SLOT(file_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (RAWFILE_VALID_FILE_ID(file_id))
    {
        if (RAWFILE_FILE_IS_BROKEN(item))
        {
            return KAL_TRUE;
        }
        else
        {
            return KAL_FALSE;
        }
    }
    else
    {
        WAP_DBG_ASSERT(0);
        return KAL_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_rawfile_write
 * DESCRIPTION
 *  
 *  NOTE: It is blocking I/O, and it may let the system less responsive
 * PARAMETERS
 *  file_id     [IN]        
 *  data        [IN]        
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
// TODO: Maybe we can cache the open file handle to improve performance?

void widget_rawfile_write(kal_int16 file_id, const char *data, int size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int fd;
    int tmpsize = 0;    /* for debug */
    widget_rawfile_item_struct *item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (file_id == 0)   /* When rawfile table is full. */
    {
        return;
    }

    item = RAWFILE_GET_SLOT(file_id);
    ASSERT(RAWFILE_VALID_FILE_ID(file_id));

    if (RAWFILE_FILE_IS_BROKEN(item))
    {
        return;
    }
    if (size <= 0)
    {
        /* It is possible that size == 0 */
        WAP_DBG_ASSERT(0);
        return;
    }

    WAP_DBG_ASSERT(RAWFILE_FILENAME_IS_VALID(item));

    fd = HDIa_fileOpen(
            MSF_MODID_WIDGET,
            item->filename,
            HDI_FILE_SET_WRONLY | HDI_FILE_SET_CREATE | HDI_FILE_SET_APPEND | HDI_FILE_SET_CUSTOM_BLOCKING,
            0);
    if (fd < 0 || (tmpsize = HDIa_fileWrite(fd, (void*)data, size)) < size)
    {
        /* We should not allow this to happen */
        WAP_DBG_ASSERT(0);

        WIDGET_UNUSED(tmpsize);
        if (fd >= 0)
        {
            HDIa_fileClose(fd);
        }
        HDIa_fileRemove(item->filename);
        WRAW_CTX->total_size -= item->size;

        if (tmpsize < 0)
        {
            item->size = tmpsize;   /* Mark the image as invalid */
        }
        else
        {
            item->size = HDI_FILE_ERROR_FULL;   /* -6 : Mark the image as invalid */
        }
        return;
    }

    HDIa_fileClose(fd);
    item->size += size;
    WRAW_CTX->total_size += size;

}


/*****************************************************************************
 * FUNCTION
 *  widget_rawfile_configure_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_id         [IN]        
 *  format          [IN]        
 *  file_ext        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_rawfile_configure_format(kal_int16 file_id, int format, const char *file_ext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_rawfile_item_struct *item;
    char old_filename[WIDGET_RAWFILE_NAMELEN + 1];
    char *c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!RAWFILE_VALID_FILE_ID(file_id))
    {
        return;
    }

    item = RAWFILE_GET_SLOT(file_id);

    item->format = (kal_int16) format;

    strcpy(old_filename, item->filename);
    if ((c = strrchr(item->filename, '.')) == NULL)
    {
        c = strrchr(item->filename, '\0');
    }
    ASSERT(c);
    strcpy(c, file_ext);

    ASSERT(strlen(item->filename) <= WIDGET_RAWFILE_NAMELEN);

    if (RAWFILE_FILE_IS_CREATED(item) && (item->is_virtual_file == KAL_FALSE))
    {
        /* If it's already created and isn't the virtual file. Rename it. */
    #ifdef RAWFILE_FAILSAFE
        HDIa_fileRemove(item->filename);    /* failsafe */
    #endif 
        HDIa_fileRename(old_filename, item->filename);
    }
}

/****************************************************************
 * Stub functions to adapt IMAGE_TYPE (in memory/file) & PRE_IMAGE_TYPE (in flash)
 ***************************************************************/

#ifdef WIDGET_COMPACT_PRE_IMAGE


/*****************************************************************************
 * FUNCTION
 *  widget_get_pre_image_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pimg        [IN]     
 *  data        [OUT]     
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool widget_get_pre_image_data(widget_pre_image_struct *pimg, widget_pre_image_result_data *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_image_id resId;
    S32 width, height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!pimg || pimg < widget_predefined_image_table)
    {
        WAP_DBG_ASSERT(0);
        return KAL_FALSE;
    }

    resId = (pimg - widget_predefined_image_table) + WAP_IMAGE_ID_BEGIN;

    if (resId >= WAP_IMAGE_ID_END)
    {
        WAP_DBG_ASSERT(0);
        return KAL_FALSE;
    }

#ifndef __MMI_RESOURCE_ENFB_SUPPORT__
    /* In ENFB case, because we may reload image resource dynamically, We need to re-get image data again. */
    if (resId == WIMG_CTX->pre_image_cache_id)
    {
        memcpy(data, &WIMG_CTX->pre_image_cache_data, sizeof(widget_pre_image_result_data));
        return KAL_TRUE;
    }
#endif

    data->src = (kal_uint8*)get_image(resId);
    data->length = gdi_image_get_buf_len_from_id(resId); /* doesn't include the header size */
    /* detect image format */
    switch (gdi_image_get_type_from_id(resId))
    {
        case IMAGE_TYPE_BMP:
            /* FALLTHROUGH no break */
        case IMAGE_TYPE_BMP_SEQUENCE:   /* BMP */
            data->image_format = MsfBmpPI;
            break;
        case IMAGE_TYPE_GIF:            /* GIF */
            data->image_format = MsfGifPI;
            break;
        case IMAGE_TYPE_DEVICE_BITMAP:
            /* FALLTHROUGH no break */
        case IMAGE_TYPE_DEVICE_BITMAP_SEQUENCE:
            data->image_format = (MsfImageFormat) MsfPbmPI;
            break;
        case IMAGE_TYPE_JPG:
            data->image_format = MsfJpegPI;
            break;
        case IMAGE_TYPE_PNG:
            data->image_format = MsfPngPI;
            break;
        case GDI_IMAGE_TYPE_ABM:
        case GDI_IMAGE_TYPE_ABM_SEQUENCE:
            data->image_format = (MsfImageFormat) MsfAbmPI;
            break;
        default:
            WAP_DBG_ASSERT(0);
            data->image_format = (MsfImageFormat) MsfUnsupportedMediaType;
            break;
    }
    gdi_image_get_dimension_id(resId, &width, &height);

    data->size.width = width;
    data->size.height = height;

    /* Cache result */
    WIMG_CTX->pre_image_cache_id = resId;
    memcpy(&WIMG_CTX->pre_image_cache_data, data, sizeof(widget_pre_image_result_data));

    return KAL_TRUE;
}

#endif /* WIDGET_COMPACT_PRE_IMAGE */ 


/*****************************************************************************
 * FUNCTION
 *  widget_image_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  image       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfImageFormat widget_image_format(MsfImageHandle image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IS_IMAGE_TYPE(image))
    {
        return _IMG(image)->image_format;
    }
    else if (IS_PRE_IMAGE_TYPE(image))
    {
    #ifdef WIDGET_COMPACT_PRE_IMAGE
        widget_pre_image_result_data res;

        if (widget_get_pre_image_data(_PIMG(image), &res))
        {
            return res.image_format;
        }
        else
        {
            return (MsfImageFormat) MsfUnsupportedMediaType;
        }
    #else /* WIDGET_COMPACT_PRE_IMAGE */ 
        return _PIMG(image)->image_format;
    #endif /* WIDGET_COMPACT_PRE_IMAGE */ 
    }

    WAP_DBG_ASSERT(0);
    return (MsfImageFormat) MsfUnsupportedMediaType;
}

/* Used internally to determine if we can display this image */


/*****************************************************************************
 * FUNCTION
 *  widget_image_is_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 *  image       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool widget_image_is_ready(MsfImageHandle image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IS_IMAGE_TYPE(image))
    {
        return _IMG(image)->is_done ? KAL_TRUE : KAL_FALSE;
    }
    else if (IS_PRE_IMAGE_TYPE(image))
    {
        return KAL_TRUE;
    }

    WAP_DBG_ASSERT(0);
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  widget_image_resid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  image       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int widget_image_resid(MsfImageHandle image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!image)
    {
        return 0;
    }
    else if (IS_PRE_IMAGE_TYPE(image))
    {
    #ifdef WIDGET_COMPACT_PRE_IMAGE
        MSF_UINT32 resId;
        widget_pre_image_struct *pimg = _PIMG(image);

        if (pimg < widget_predefined_image_table)
        {
            return 0;
        }
        resId = (pimg - widget_predefined_image_table) + WAP_IMAGE_ID_BEGIN;
        if (resId >= WAP_IMAGE_ID_END)
        {
            return 0;
        }
        return resId;
    #else /* WIDGET_COMPACT_PRE_IMAGE */ 
        return _PIMG(image)->resource_id;
    #endif /* WIDGET_COMPACT_PRE_IMAGE */ 
    }
    else
    {
        WAP_DBG_ASSERT(0);
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_image_width
 * DESCRIPTION
 *  
 * PARAMETERS
 *  image       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int widget_image_width(MsfImageHandle image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IS_IMAGE_TYPE(image))
    {
        return _IMG(image)->size.width;
    }
    else if (IS_PRE_IMAGE_TYPE(image))
    {
    #ifdef WIDGET_COMPACT_PRE_IMAGE
        widget_pre_image_result_data res;

        if (widget_get_pre_image_data(_PIMG(image), &res))
        {
            return res.size.width;
        }
        else
        {
            return 0;
        }
    #else /* WIDGET_COMPACT_PRE_IMAGE */ 
        return _PIMG(image)->size.width;
    #endif /* WIDGET_COMPACT_PRE_IMAGE */ 
    }

    WAP_DBG_ASSERT(0);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  widget_image_height
 * DESCRIPTION
 *  
 * PARAMETERS
 *  image       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int widget_image_height(MsfImageHandle image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IS_IMAGE_TYPE(image))
    {
        return _IMG(image)->size.height;
    }
    else if (IS_PRE_IMAGE_TYPE(image))
    {
    #ifdef WIDGET_COMPACT_PRE_IMAGE
        widget_pre_image_result_data res;

        if (widget_get_pre_image_data(_PIMG(image), &res))
        {
            return res.size.height;
        }
        else
        {
            return 0;
        }
    #else /* WIDGET_COMPACT_PRE_IMAGE */ 
        return _PIMG(image)->size.height;
    #endif /* WIDGET_COMPACT_PRE_IMAGE */ 
    }

    WAP_DBG_ASSERT(0);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  widget_image_content
 * DESCRIPTION
 *  Return the image content in memory (typically used with widget_image_content_file)
 * PARAMETERS
 *  image       [IN]        The image handle
 * RETURNS
 *  The image content stored in memory
 *  NOTE: It might return NULL if
 *  1. The image does not have content
 *  2. Its content is stored in file.
 *****************************************************************************/
kal_uint8 *widget_image_content(MsfImageHandle image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IS_IMAGE_TYPE(image))
    {
        if (_IMG(image)->raw)
        {
            return _IMG(image)->raw->data;
        }
        else
        {
            return NULL;
        }
    }
    else if (IS_PRE_IMAGE_TYPE(image))
    {
    #ifdef WIDGET_COMPACT_PRE_IMAGE
        widget_pre_image_result_data res;

        if (widget_get_pre_image_data(_PIMG(image), &res))
        {
            return res.src;
        }
        else
        {
            return NULL;
        }
    #else /* WIDGET_COMPACT_PRE_IMAGE */ 
        return _PIMG(image)->src;
    #endif /* WIDGET_COMPACT_PRE_IMAGE */ 
    }

    WAP_DBG_ASSERT(0);
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  widget_image_dimension
 * DESCRIPTION
 *  Return the image dimension
 *  (Initialized after widget_initialize_image_dimension
 * PARAMETERS
 *  image       [IN]        The image handle
 * RETURNS
 *  
 *****************************************************************************/
MsfSize *widget_image_dimension(MsfImageHandle image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Note: Non-reentrant */
    if (IS_IMAGE_TYPE(image))
    {
        return &(_IMG(image)->size);
    }
    else if (IS_PRE_IMAGE_TYPE(image))
    {
    #ifdef WIDGET_COMPACT_PRE_IMAGE
        /* Static data in case caller might modify returned structure unexpectedly */
        static MsfSize dummy_size;
        widget_pre_image_result_data res;

        if (widget_get_pre_image_data(_PIMG(image), &res))
        {
            dummy_size = res.size;
        }
        else
        {
            dummy_size.height = 0;
            dummy_size.width = 0;
        }

        return &dummy_size;
    #else /* WIDGET_COMPACT_PRE_IMAGE */ 
        return &(_PIMG(image)->size);
    #endif /* WIDGET_COMPACT_PRE_IMAGE */ 
    }

    WAP_DBG_ASSERT(0);
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  widget_image_content_file
 * DESCRIPTION
 *  Return the filename that contain the content of an image
 * PARAMETERS
 *  image       [IN]        The image handle
 * RETURNS
 *  A file name or NULL
 *****************************************************************************/
char *widget_image_content_file(MsfImageHandle image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IS_IMAGE_TYPE(image))
    {
        if (_IMG(image)->rawfile_id)
        {
            /* It might still return NULL */
            return widget_rawfile_getname(_IMG(image)->rawfile_id);
        }
        else
        {
            return NULL;
        }
    }
    else if (IS_PRE_IMAGE_TYPE(image))
    {
        return NULL;
    }

    WAP_DBG_ASSERT(0);
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtGetImageContentFile
 * DESCRIPTION
 *  Return the filename that contain the content of an MsfImageHandle
 *  export the API to other MSF modules
 * PARAMETERS
 *  image       [IN]        The image handle
 * RETURNS
 *  A file name or NULL
 *****************************************************************************/
const char* HDIa_widgetExtGetImageContentFile(MsfImageHandle image)
{
    return widget_image_content_file(image);
}


/*****************************************************************************
 * FUNCTION
 *  widget_image_length
 * DESCRIPTION
 *  Return the length of image content
 *  The user should make sure widget_image_is_ready() == TRUE
 * PARAMETERS
 *  image       [IN]        The image handle
 * RETURNS
 *  length
 *****************************************************************************/
int widget_image_length(MsfImageHandle image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IS_IMAGE_TYPE(image))
    {
        if (_IMG(image)->raw)
        {
            return _IMG(image)->raw->size;
        }
        else if (_IMG(image)->rawfile_id)
        {
            return widget_rawfile_getsize(_IMG(image)->rawfile_id);
        }
        else
        {
            return 0;
        }
    }
    else if (IS_PRE_IMAGE_TYPE(image))
    {
    #ifdef WIDGET_COMPACT_PRE_IMAGE
        widget_pre_image_result_data res;

        if (widget_get_pre_image_data(_PIMG(image), &res))
        {
            return res.length;
        }
        else
        {
            return 0;
        }
    #else /* WIDGET_COMPACT_PRE_IMAGE */ 
        return _PIMG(image)->length;
    #endif /* WIDGET_COMPACT_PRE_IMAGE */ 
    }

    WAP_DBG_ASSERT(0);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  widget_image_frame_count
 * DESCRIPTION
 *  Return the frame count of GIF image or 0 for other image types
 *  The user should make sure widget_image_is_ready() == TRUE
 * PARAMETERS
 *  image       [IN]        The image handle
 * RETURNS
 *  
 *****************************************************************************/
int widget_image_frame_count(MsfImageHandle image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IS_IMAGE_TYPE(image))
    {
        WAP_DBG_ASSERT(_IMG(image)->GIF_frames_initialized);
        return _IMG(image)->GIF_frames;
    }
    else if (IS_PRE_IMAGE_TYPE(image))
    {
        /* We neither use nor support it, although it should be supported for consistency */
        WAP_DBG_ASSERT(0);
        return 0;
    }

    WAP_DBG_ASSERT(0);
    return 0;

}


/*****************************************************************************
 * FUNCTION
 *  widget_image_check_format
 * DESCRIPTION
 *  check the image format. Used inside widget_image_set_done().
 * PARAMETERS
 *  img     [IN]        Img->image_format is modified
 * RETURNS
 *  kal_bool
 *****************************************************************************/
static kal_bool widget_image_check_format(widget_image_struct *img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 gdi_type = GDI_IMAGE_TYPE_INVALID;
    int image_format = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (img->rawfile_id)
    {
        S8 *full_name;
        char *rawfile_name = widget_image_content_file((MsfImageHandle) img);

        if (!rawfile_name)
        {
            return KAL_FALSE;
        }

        full_name = (S8*) HDI_FileNameTranslate(rawfile_name);

        gdi_type = gdi_image_get_type_from_file(full_name);

        HDI_FileNameFree((kal_uint8*) full_name);
    }
    else
    {
        /* Currently, we do not use img->raw in normal case */
        return KAL_FALSE;
    }

    switch (gdi_type)
    {
        case GDI_IMAGE_TYPE_BMP:
        case GDI_IMAGE_TYPE_BMP_FILE:
            image_format = MsfBmp;
            break;

        case GDI_IMAGE_TYPE_GIF:
        case GDI_IMAGE_TYPE_GIF_FILE:
            image_format = MsfGif;
            break;

        case GDI_IMAGE_TYPE_WBMP:
        case GDI_IMAGE_TYPE_WBMP_FILE:
            image_format = MsfWbmp;
            break;

        case GDI_IMAGE_TYPE_JPG:
        case GDI_IMAGE_TYPE_JPG_FILE:
            image_format = MsfJpeg;
            break;

        case GDI_IMAGE_TYPE_PNG:
        case GDI_IMAGE_TYPE_PNG_FILE:
            image_format = MsfPng;
            break;

        default:
            return KAL_FALSE;
    }

    if (img->image_format == image_format)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_image_auto_detect_format
 * DESCRIPTION
 *  Auto-decide the image format. Used inside widget_image_set_done().
 * PARAMETERS
 *  img     [IN]        Img->image_format is modified
 * RETURNS
 *  kal_bool
 *****************************************************************************/
static kal_bool widget_image_auto_detect_format(widget_image_struct *img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 gdi_type = GDI_IMAGE_TYPE_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (img->rawfile_id)
    {
        S8 *full_name;
        char *rawfile_name = widget_image_content_file((MsfImageHandle) img);

        if (!rawfile_name)
        {
            return KAL_FALSE;
        }

        full_name = (S8*) HDI_FileNameTranslate(rawfile_name);

        gdi_type = gdi_image_get_type_from_file(full_name);

        HDI_FileNameFree((kal_uint8*) full_name);
    }
    else
    {
        /* Currently, we do not use img->raw in normal case */
        return KAL_FALSE;
    }

    switch (gdi_type)
    {
        case GDI_IMAGE_TYPE_BMP:
        case GDI_IMAGE_TYPE_BMP_FILE:
            img->image_format = MsfBmp;
            return KAL_TRUE;

        case GDI_IMAGE_TYPE_GIF:
        case GDI_IMAGE_TYPE_GIF_FILE:
            img->image_format = MsfGif;
            return KAL_TRUE;

        case GDI_IMAGE_TYPE_WBMP:
        case GDI_IMAGE_TYPE_WBMP_FILE:
            img->image_format = MsfWbmp;
            return KAL_TRUE;

        case GDI_IMAGE_TYPE_JPG:
        case GDI_IMAGE_TYPE_JPG_FILE:
            img->image_format = MsfJpeg;
            return KAL_TRUE;

        case GDI_IMAGE_TYPE_PNG:
        case GDI_IMAGE_TYPE_PNG_FILE:
            img->image_format = MsfPng;
            return KAL_TRUE;

        default:
            return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_image_set_done
 * DESCRIPTION
 *  Set the image ready (all data is read). Then we can draw it
 * PARAMETERS
 *  img     [IN]        
 * RETURNS
 *  1 - the image is valid
 *  0 - the image is invalid (can't get the image resolution)
 *  -1 - The image is larger the limitation (WIDGET_IMAGE_MAX_WIDTH, WIDGET_IMAGE_MAX_HEIGHT)
 *  -2 - gdi draw image failed (resource is not enough)
 *****************************************************************************/
static int widget_image_set_done(widget_image_struct *img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* [is_valid_dimension]
     * 1: get dimension succeed
     * 0: can't get dimension;
     * -1: dimension is too large;
     * -2: file is corrupted;
     */
    kal_int32 is_valid_dimension = 0;

    char *rawfile_name;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (img->rawfile_id)
    {
        widget_rawfile_configure_format(
            img->rawfile_id,
            img->image_format,
            widget_image_format_to_extension(img->image_format));
    }
    is_valid_dimension = widget_initialize_image_dimension((MsfImageHandle) img);
    if (!widget_image_check_format(img))
    {
        MsfImageFormat old_format;

        old_format = img->image_format;
        if (widget_image_auto_detect_format(img) && img->image_format != old_format)
        {
            if (img->rawfile_id)
            {
                widget_rawfile_configure_format(
                    img->rawfile_id,
                    img->image_format,
                    widget_image_format_to_extension(img->image_format));
            }
            is_valid_dimension = widget_initialize_image_dimension((MsfImageHandle) img);
        }
    }

    if (is_valid_dimension > 0)
    {
        /* The image dimension should be larger than zero */
        rawfile_name = widget_image_content_file((MsfImageHandle) img);
        if (rawfile_name)
        {
            /* image file */
            S8 *error_str_ptr = NULL;
            S8 *full_name = (S8*) HDI_FileNameTranslate(rawfile_name);

            /* We don't use FMGR_LIMIT_IMAGE_VIEWER to check the image limitation 
             * because unified composer has its config "FMGR_LIMIT_MMS_CATEGORY".
             */
            if( mmi_fmgr_util_file_limit_check(FMGR_LIMIT_MMS_CATEGORY, (S8*)full_name, &error_str_ptr) == FALSE)
            {
                /* -1: dimension is too large; */
                is_valid_dimension = -1;
                img->size.width = img->size.height = 0;
            }
            HDI_FileNameFree((kal_uint8*) full_name);
        }
    }

    /* reset gdi cache */
    gdi_image_gif_reset();

    img->GIF_frames = 0;    /* Delay initialization until execution in MMI task */
    img->GIF_frames_initialized = 0;
    img->is_done = KAL_TRUE;

    if (is_valid_dimension > 0)
    {
    #ifdef WIDGET_CHECK_IMAGE_IN_DETAIL
        kal_bool ret = KAL_FALSE;
        
        ret = widget_check_image_in_detail((MsfImageHandle) img);
        /* reset gdi cache */
        gdi_image_gif_reset();
        
        if (ret == KAL_FALSE)
        {
            return -2;   /* gdi draw image failed (no resource) */
        }
        else
    #endif
        {
            return 1;   /* The image is vaild */
        }

    }
    else
    {
        /* [is_valid_dimension]
         * 0: can't get dimension;
         * -1: dimension is too large;
         * -2: file is corrupted;
         */
        if (is_valid_dimension == -1)
        {
            return -1;  /* The image is larger the limitation */
        }
        else
        {
            return 0;   /* The image is invalid */
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_image_release
 * DESCRIPTION
 *  Release image-specific data.
 * PARAMETERS
 *  img     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_image_release(widget_image_struct *img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Prevent race condition: animation timer expire after data is deallocated */
    widget_stop_animate_by_image((MsfImageHandle) img);

    /* 
     * Release raw file and data after all decoding/animation are stopped
     * Raw data is released in other place
     */
    if (img->rawfile_id)
    {
        if ((MsfVideoFormat) (img->image_format) >= MsfVideoFormatStart)
        {
            /* video */
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_RELEASE_VIDEO_RAWFILE_ID);
            HDIa_widgetExtCloseVideo();
            widget_rawfile_deregister(img->rawfile_id);
            img->rawfile_id = 0;
            if (videoResourceCount > 0)
            {
                videoResourceCount--;
            }

            if (WGUI_CTX->current_video == img)
            {
                WGUI_CTX->current_video = NULL;
                if (videoResourceCount <= 0)
                {
                    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WIDGET_VIDEO_NONE);
                    widget_execute_MMI(widget_free_video_gdi_layer, KAL_TRUE);
                    WGUI_CTX->current_video_state = WIDGET_VIDEO_NONE;
                    videoResourceCount = 0;
                }
                else
                {
                    WGUI_CTX->current_video_state = WIDGET_VIDEO_FILE_ALREADY_CHECKED;
                }
            }
        }
        else
        {
            /* image */
            widget_rawfile_deregister(img->rawfile_id);
            img->rawfile_id = 0;
        }
    }

    if (img->draw_op_head)
    {
        widget_draw_op_release(img->draw_op_head);
        img->draw_op_head = img->draw_op_tail = NULL;
    }

#ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING
    widget_stop_image_nb_draw(img);
#endif

#ifdef WIDGET_PRECACHE_IMAGE
    widget_reset_precached_image_by_image(img);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  widget_output_image_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  img     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __MTK_TARGET__
/* 
 * for debug: it works with msf_file_w32.c, but not msf_file.c
 */
static void widget_output_image_file(widget_image_struct *img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (img->is_done)
    {
        static int cnt = 0;
        char filename[128];

        switch (img->image_format)
        {
            case MsfBmp:
                sprintf(filename, "wap_%03d.bmp", cnt);
                break;
            case MsfPictogram:
                sprintf(filename, "wap_%03d.pic", cnt);
                break;
            case MsfGif:
                sprintf(filename, "wap_%03d.gif", cnt);
                break;
            case MsfJpeg:
                sprintf(filename, "wap_%03d.jpg", cnt);
                break;
            case MsfPng:
                sprintf(filename, "wap_%03d.png", cnt);
                break;
            case MsfWbmp:
                sprintf(filename, "wap_%03d.wbmp", cnt);
                break;
            case MsfPbmPI:
                sprintf(filename, "wap_%03d.pbm", cnt);
                break;
            default:
                ASSERT(0);
        }
        cnt++;
        {
            FILE *f = fopen(filename, "wb");

            if (widget_image_content((MsfImageHandle) img))     // TODO: handle widget_image_content_file
            {
                fwrite(widget_image_content((MsfImageHandle) img), widget_image_length((MsfImageHandle) img), 1, f);
            }
            fclose(f);
        }
    }
}
#endif /* __MTK_TARGET__ */ 

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetImageCreate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId               [IN]        
 *  imageData           [IN]        
 *  imageDataSize       [IN]        
 *  imageFormat         [IN]        
 *  moreData            [IN]        
 *  defaultStyle        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfImageHandle HDIa_widgetImageCreate(
                MSF_UINT8 modId,
                const char *imageData,
                int imageDataSize,
                MsfImageFormat imageFormat,
                int moreData,
                MsfStyleHandle defaultStyle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_image_struct *img = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* setting the image widget */
    img = widget_create_image(modId);
    img->module_id = modId;
    img->image_format = imageFormat;
    widget_set_attrib(img, style, defaultStyle);

    HDIa_widgetImageNextPart((MsfImageHandle) img, (char*)imageData, imageDataSize, moreData);

    return (MsfImageHandle) img;
}

/* Either img->raw or img->rawfile_id must not be 0 */


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetImageNextPart
 * DESCRIPTION
 *  
 * PARAMETERS
 *  image               [IN]        
 *  imageData           [OUT]         
 *  imageDataSize       [IN]        
 *  moreData            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetImageNextPart(MsfImageHandle image, char *imageData, int imageDataSize, int moreData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_image_struct *img;
    MSF_UINT8 modId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (image == 0)
    {
        WAP_DBG_ASSERT(0);
        return 0;
    }

    WAP_DBG_ASSERT(IS_IMAGE_TYPE(image));
    img = _IMG(image);
    modId = img->module_id;

    if (img->raw == NULL && img->rawfile_id == 0)   /* Create new image */
    {
        if (!widget_rawfile_allow_to_create_image(_IMG(image)->image_format, imageDataSize))
        {
            /* Write image content in memory  */
            widget_raw_data_struct *raw;

            raw = widget_create_raw_data_ext(modId, imageDataSize);
            widget_set_raw_data(raw, imageData, imageDataSize);
            widget_set_attrib(img, raw, raw);
        }
        else
        {
            /* Write image content in file */
            img->rawfile_id = widget_rawfile_register((MsfImageHandle) img);
            if (img->rawfile_id)
            {
                widget_rawfile_write(img->rawfile_id, imageData, imageDataSize);
                if (widget_rawfile_write_failed(img->rawfile_id))
                {
                    widget_send_notification_load_resource(img, MsfNotifyFailedFSFull);
                    return -1;
                }
            }
        }
    }
    else if (img->raw == NULL)  /*  Append rawfile_id */
    {
        /* img->rawfile_id must not be 0 */
        widget_rawfile_write(img->rawfile_id, imageData, imageDataSize);
        if (widget_rawfile_write_failed(img->rawfile_id))
        {
            widget_send_notification_load_resource(img, MsfNotifyFailedFSFull);
            return -1;
        }
    }
    else if (widget_rawfile_allow_to_create_image(_IMG(image)->image_format, _IMG(image)->raw->size + imageDataSize))
    {
        /* Free the original raw data, and append to file */
        WAP_DBG_ASSERT(img->rawfile_id == 0);
        img->rawfile_id = widget_rawfile_register((MsfImageHandle) img);
        if (img->rawfile_id)
        {
            widget_rawfile_write(img->rawfile_id, (char*)img->raw->data, img->raw->size);
            widget_rawfile_write(img->rawfile_id, imageData, imageDataSize);
            widget_set_attrib(img, raw, NULL);  /* delete orignal raw data */
            if (widget_rawfile_write_failed(img->rawfile_id))
            {
                widget_send_notification_load_resource(img, MsfNotifyFailedFSFull);
                return -1;
            }
        }
    }
    else
    {
        /* Append raw data */
        widget_raw_data_struct *raw;

        raw = widget_create_raw_data_ext(img->module_id, img->raw->size + imageDataSize);
        memcpy(raw->data, img->raw->data, img->raw->size);
        memcpy(raw->data + img->raw->size, imageData, imageDataSize);
        widget_set_attrib(img, raw, raw);
    }

    if (!moreData)
    {
        int ret = widget_image_set_done(img);

        if (ret > 0)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }

    return 1;
}

#if 0   /* NOT FULLY IMPLEMENTED */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  widget_send_notification_load_resource
 * DESCRIPTION
 *  It is only for MsfImage widgets that are created using a resource
 * PARAMETERS
 *  img         [IN]        The image
 *  state       [IN]        Success or failure
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_send_notification_load_resource(widget_image_struct *img, /* kal_bool */ int state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (img->module_id == MSF_MODID_MEA || img->module_id == MSF_MODID_SMA)
    {
        /* MMS */
        switch (state)
        {
            case MsfNotifyResourceReady:
                HDIc_widgetNotify(img->module_id, (MSF_UINT32) img, MsfNotifyResourceLoaded);
                break;
            case MsfNotifyResourceError:
                HDIc_widgetNotify(img->module_id, (MSF_UINT32) img, MsfNotifyResourceFailed);
                break;
            case MsfNotifyFailedResolution:
                /* HDIc_widgetNotify(img->module_id,(MSF_UINT32)img,MsfNotifyResourceFailed); */
                HDIc_widgetNotify(img->module_id, (MSF_UINT32) img, MsfNotifyFailedResolution);
                break;
            case MsfNotifyFailedFSFull:
                /* HDIc_widgetNotify(img->module_id,(MSF_UINT32)img,MsfNotifyResourceFailed); */
                HDIc_widgetNotify(img->module_id, (MSF_UINT32) img, MsfNotifyFailedFSFull);
                break;
            case MsfNotifyFailedNoResource:
                /* HDIc_widgetNotify(img->module_id,(MSF_UINT32)img,MsfNotifyResourceFailed); */
                HDIc_widgetNotify(img->module_id, (MSF_UINT32) img, MsfNotifyFailedNoResource);
                break;
            case MsfNotifyFailedCorrupt:
                /* HDIc_widgetNotify(img->module_id,(MSF_UINT32)img,MsfNotifyResourceFailed); */
                HDIc_widgetNotify(img->module_id, (MSF_UINT32) img, MsfNotifyFailedCorrupt);
                break;
            default:
                HDIc_widgetNotify(img->module_id, (MSF_UINT32) img, MsfNotifyResourceFailed);
                break;
        }
    }
    else
    {
        if (state == MsfNotifyResourceReady)
        {
            HDIc_widgetNotify(img->module_id, (MSF_UINT32) img, MsfNotifyResourceLoaded);
        }
        else
        {
            HDIc_widgetNotify(img->module_id, (MSF_UINT32) img, MsfNotifyResourceFailed);
        }
    }

    widget_send_update_event_to_wap();
}


/*****************************************************************************
 * FUNCTION
 *  widget_create_image_resource
 * DESCRIPTION
 *  Check and create the image resource (WAP task)
 *  Whether the image resource is created ready or not, we will send notification
 *  to MSF Module.
 * PARAMETERS
 *  img     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_create_image_resource(widget_image_struct *img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    flag = widget_image_set_done(img);
    /*
     * the return value of widget_image_set_done():
     *  1 - the image is valid
     *  0 - the image is invalid (can't get the image resolution)
     *  -1 - The image is larger the limitation (WIDGET_IMAGE_MAX_WIDTH, WIDGET_IMAGE_MAX_HEIGHT)
     *  -2 - gdi draw image failed (resource is not enough)
     */
    switch (flag)
    {
    case 1: /* 1 - the image is valid */
        widget_send_notification_load_resource(img, MsfNotifyResourceReady);
        break;
    case 0: /* 0 - the image is invalid (can't get the image resolution) */
        widget_send_notification_load_resource(img, MsfNotifyFailedCorrupt);
        break;
    case -1: /* -1 - The image is larger the limitation */
        widget_send_notification_load_resource(img, MsfNotifyFailedResolution);
        break;
    case -2: /* -2 - gdi draw image failed (resource is not enough) */
        widget_send_notification_load_resource(img, MsfNotifyFailedNoResource);
        break;
    default:
        WAP_DBG_ASSERT(0);
        widget_send_notification_load_resource(img, MsfNotifyResourceError);
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_read_image_from_file_to_raw_data
 * DESCRIPTION
 *  Callback function of reading image data from file
 *  
 *  It will do these after the image is loaded: (but it doesn't close file)
 *  1. set "done" flag
 *  2. Recompute the dimension of the image
 *  3. Send MsfNotifyResourceLoaded, etc.
 *  
 *  Note: Modify widget_read_sound_from_file also if this function is changed.
 * PARAMETERS
 *  f                   [IN]            File handle
 *  size                [IN]            Expected file size ( > 0)
 *  img                 [IN/OUT]        The image
 *  need_add_select     [IN]            Whether to add into the map "widget_fn_*"
 *  is_DRM              [IN]            
 * RETURNS
 *  WIDGET_READ_ERROR
 *  WIDGET_WAIT_SELECT
 *  WIDGET_READ_FINISH
 *****************************************************************************/
static int widget_read_image_from_file_to_raw_data(
            int f,
            int size,
            widget_image_struct *img,
            kal_bool need_add_select,
            kal_bool is_DRM)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    long ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(img->raw != NULL);

    while (img->raw->used_size < size)
    {
        /* read image data */
    #ifdef __DRM_SUPPORT__
        if (is_DRM)
        {
            kal_uint32 length;

            if (DRM_read_file(f, img->raw->data + img->raw->used_size, size - img->raw->used_size, &length) <
                FS_NO_ERROR)
            {
                ret = HDI_FILE_ERROR_INVALID;
            }
            else
            {
                if (length)
                {
                    ret = length;
                }
                else
                {	/* If read length is 0, we should return HDI_FILE_ERROR_EOF */
                    ret = HDI_FILE_ERROR_EOF;
                }
            }
        }
        else
    #endif /* __DRM_SUPPORT__ */ 
        {
            ret = HDIa_fileRead(f, img->raw->data + img->raw->used_size, size - img->raw->used_size);
        }

        if (ret < 0)
        {
            if (ret == HDI_FILE_ERROR_DELAYED)
            {
                /* In current implementation, DRM files are opened in blocking mode */
                WAP_DBG_ASSERT(!is_DRM);

                /* Wait for notification */
                if (need_add_select)
                {
                    widget_add_file_poll(f, _H(img), size);
                }
                HDIa_fileSelect(f, HDI_FILE_EVENT_READ);
                return WIDGET_WAIT_SELECT;
            }

            /* Something wrong happened */

            /* Even if "ret == HDI_FILE_ERROR_EOF", it is still incorrect. */
            WAP_DBG_ASSERT(img->raw->used_size < size);

            widget_send_notification_load_resource(img, MsfNotifyFailedCorrupt);
            return WIDGET_READ_ERROR;
        }
        else
        {
            img->raw->used_size += ret;

            if (img->raw->used_size == size)
            {
                if ((MsfVideoFormat) (img->image_format) >= MsfVideoFormatStart)
                {
                    /* 
                     *Should not reach here. 
                     * we don't support video resource in raw data style
                     */
                    WAP_DBG_ASSERT(0);
                    /* video */
                    widget_create_video_resource(img);
                }
                else
                {
                    /* image */
                    widget_create_image_resource(img);
                }

                return WIDGET_READ_FINISH;
            }
        }
    }

    /* Should not reach here */
    WAP_DBG_ASSERT(0);
    widget_send_notification_load_resource(img, MsfNotifyResourceError);
    return WIDGET_READ_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  widget_read_image_from_file_to_raw_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  f                   [IN]        
 *  size                [IN]        
 *  img                 [IN]         
 *  need_add_select     [IN]        
 *  is_DRM              [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static int widget_read_image_from_file_to_raw_file(
            int f,
            int size,
            widget_image_struct *img,
            kal_bool need_add_select,
            kal_bool is_DRM)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *buffer = WRAW_CTX->working_buffer;
    long ret;
    int rawfile_size;
    int data_to_read;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(img->rawfile_id != 0 && buffer);

    while (((rawfile_size = widget_rawfile_getsize(img->rawfile_id)) < size) && (rawfile_size >= 0))
    {
        /* read image data */
        data_to_read = size - rawfile_size;

    #ifdef __DRM_SUPPORT__
        if (is_DRM)
        {
            kal_uint32 length;

            if (DRM_read_file
                (f, buffer, (data_to_read < WIDGET_LOAD_BUFFER_SIZE) ? data_to_read : WIDGET_LOAD_BUFFER_SIZE,
                 &length) < FS_NO_ERROR)
            {
                ret = HDI_FILE_ERROR_INVALID;
            }
            else
            {
                if (length)
                {
                    ret = length;
                }
                else
                {	/* If read length is 0, we should return HDI_FILE_ERROR_EOF */
                    ret = HDI_FILE_ERROR_EOF;
                }
            }
        }
        else
    #endif /* __DRM_SUPPORT__ */ 
        {
            ret = HDIa_fileRead(
                    f,
                    buffer,
                    (data_to_read < WIDGET_LOAD_BUFFER_SIZE) ? data_to_read : WIDGET_LOAD_BUFFER_SIZE);
        }

        if (ret < 0)
        {
            if (ret == HDI_FILE_ERROR_DELAYED)
            {
                /* In current implementation, DRM files are opened in blocking mode */
                WAP_DBG_ASSERT(!is_DRM);

                /* Wait for notification */
                if (need_add_select)
                {
                    widget_add_file_poll(f, _H(img), size);
                }
                HDIa_fileSelect(f, HDI_FILE_EVENT_READ);
                return WIDGET_WAIT_SELECT;
            }

            /* Something wrong happened */

            /* Even if "ret == HDI_FILE_ERROR_EOF", it is still incorrect. */
            WAP_DBG_ASSERT(rawfile_size < size);

            widget_send_notification_load_resource(img, MsfNotifyFailedCorrupt);
            return WIDGET_READ_ERROR;
        }
        else
        {
            widget_rawfile_write(img->rawfile_id, buffer, ret);

            if (widget_rawfile_getsize(img->rawfile_id) == size)
            {
                if ((MsfVideoFormat) (img->image_format) >= MsfVideoFormatStart)
                {
                    /* video */
                    widget_create_video_resource(img);
                }
                else
                {
                    /* image */
                    widget_create_image_resource(img);
                }

                return WIDGET_READ_FINISH;
            }
            else if (widget_rawfile_write_failed(img->rawfile_id))
            {
                widget_send_notification_load_resource(img, MsfNotifyFailedFSFull);
                return WIDGET_READ_ERROR;
            }
        }
        /* Otherwise,  keep reading */
    }

    /* Should not reach here */
    WAP_DBG_ASSERT(0);
    widget_send_notification_load_resource(img, MsfNotifyResourceError);
    return WIDGET_READ_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  widget_read_image_from_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  f                   [IN]        
 *  size                [IN]        
 *  img                 [IN]         
 *  need_add_select     [IN]        
 *  is_DRM              [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int widget_read_image_from_file(int f, int size, widget_image_struct *img, kal_bool need_add_select, kal_bool is_DRM)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* We already know the image size. This is different from widget_read_image_from_pipe */
    if (img->raw)
    {
        return widget_read_image_from_file_to_raw_data(f, size, img, need_add_select, is_DRM);
    }
    else
    {
        return widget_read_image_from_file_to_raw_file(f, size, img, need_add_select, is_DRM);
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_read_image_from_pipe
 * DESCRIPTION
 *  Callback function of reading image data from pipe
 *  
 *  It will do these after the image is loaded: (but it doesn't close pipe)
 *  1. set "done" flag
 *  2. Recompute the dimension of the image
 *  3. Send MsfNotifyResourceLoaded, etc.
 *  
 *  Note: Modify widget_read_sound_from_pipe also if this function is changed.
 * PARAMETERS
 *  f                   [IN]            File handle
 *  img                 [IN/OUT]        The image
 *  need_add_select     [IN]            Whether to add into the map "widget_pn_*"
 * RETURNS
 *  WIDGET_READ_ERROR
 *  WIDGET_WAIT_SELECT
 *  WIDGET_READ_FINISH
 *****************************************************************************/
int widget_read_image_from_pipe(int f, widget_image_struct *img, kal_bool need_add_select)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    long ret;
    long size;
    int is_open;
    char *buffer = WRAW_CTX->working_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(buffer);

    while (KAL_TRUE)
    {
        /* detect current data size */
        if (HDIa_pipeStatus(f, &is_open, &size) < 0)
        {
            return WIDGET_READ_ERROR;
        }

        if (size == 0)
        {
            /* nothing left to read */

            if (!is_open)
            {
                /* The peer writer has closed the pipe */

                if (widget_image_length((MsfImageHandle) img) > 0)      /* We do read something */
                {
                    int flag;

                    flag = widget_image_set_done(img);
                    /*
                     * the return value of widget_image_set_done():
                     *  1 - the image is valid
                     *  0 - the image is invalid (can't get the image resolution)
                     *  -1 - The image is larger the limitation (WIDGET_IMAGE_MAX_WIDTH, WIDGET_IMAGE_MAX_HEIGHT)
                     *  -2 - gdi draw image failed (resource is not enough)
                     */
                    switch (flag)
                    {
                    case 1: /* 1 - the image is valid */
                        widget_send_notification_load_resource(img, MsfNotifyResourceReady);
                        break;
                    case 0: /* 0 - the image is invalid (can't get the image resolution) */
                        widget_send_notification_load_resource(img, MsfNotifyFailedCorrupt);
                        break;
                    case -1: /* -1 - The image is larger the limitation */
                        widget_send_notification_load_resource(img, MsfNotifyFailedResolution);
                        break;
                    case -2: /* -2 - gdi draw image failed (resource is not enough) */
                        widget_send_notification_load_resource(img, MsfNotifyFailedNoResource);
                        break;
                    default:
                        WAP_DBG_ASSERT(0);
                        widget_send_notification_load_resource(img, MsfNotifyResourceError);
                    }

                    return WIDGET_READ_FINISH;
                }

                /* Note the case img->is_done = KAL_FALSE */
                widget_send_notification_load_resource(img, MsfNotifyResourceError);
                return WIDGET_READ_ERROR;
            }
            else
            {
                /* Wait for notification */

                if (need_add_select)
                {
                    widget_add_pipe_poll(f, _H(img));
                }

                HDIa_pipePoll(f);
                return WIDGET_WAIT_SELECT;
            }
        }

        if (size > WIDGET_LOAD_BUFFER_SIZE)
        {
            size = WIDGET_LOAD_BUFFER_SIZE;
        }
        ret = HDIa_pipeRead(f, buffer, size);
        if (ret < 0)
        {
            if (ret == HDI_PIPE_ERROR_DELAYED)
            {
                if (need_add_select)
                {
                    widget_add_pipe_poll(f, _H(img));
                }

                HDIa_pipePoll(f);
                return WIDGET_WAIT_SELECT;
            }
            else    /* if(ret == HDI_PIPE_ERROR_CLOSED) */
            {
                WAP_DBG_ASSERT(0);  /* Should not happen, but no error */
                widget_send_notification_load_resource(img, MsfNotifyResourceError);
                return WIDGET_READ_ERROR;
            }
        }
        WAP_DBG_ASSERT(ret == size);
        if (HDIa_widgetImageNextPart((MsfImageHandle) img, buffer, ret, KAL_TRUE) == -1)
		{
			/* If write the data failed, we delete the pipe */
			HDIa_pipeDeleteByHandle(f);
		}
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtImageResizing
 * DESCRIPTION
 *  If the image dimension is larger than resized width/height, the function
 *  tries to resize the image and create MsfImageHandle at the same time
 *  We assume the caller should be MMI thread
 * PARAMETERS
 *  modId           [IN]        
 *  file            [IN]         
 *  dest_file       [IN]         
 *  resize_w        [IN]        
 *  resize_h        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetExtImageResizing(MSF_UINT8 modId, char *file, char *dest_file, int resize_w, int resize_h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *fname = NULL, *dest_fname = NULL;
    S32 img_width = 0, img_height = 0;
    GDI_RESULT gdi_ret = GDI_FAILED;
    int ret = 0; /* 0: don't need resizing;  1: resizing succeed;  <0: resizing failed */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(file != NULL);
    ASSERT(dest_file != NULL);

    /* Check the quota */
    if (widget_rawfile_allow_to_create_image(0, 0) == KAL_FALSE)
    {
        /* -10: no wcache quota */
        return MSF_WIDGET_EXT_RESIZING_FAILED_IN_NO_QUOTA; 
    }
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_IMAGE_RESIZING);

    /* Get the image dimension */
    fname = (char*)HDI_FileNameTranslate(file);
    gdi_image_get_dimension_file((PS8) fname, &img_width, &img_height);

    /* Check the original image dimension. */
    if (img_width > WIDGET_IMAGE_MAX_WIDTH_IN_RESIZING || img_height > WIDGET_IMAGE_MAX_HEIGHT_IN_RESIZING)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_IMAGE_RESIZING_TOO_LARGE);
        HDI_FileNameFree((kal_uint8*) fname);
        return MSF_WIDGET_EXT_RESIZING_FAILED_IN_GDI_FAILED;
    }
    
    if ((img_width >= 0) && (img_height >= 0))
    {
        /* calculate the dimension of the resize JPEG */
        if ((img_width > resize_w) || (img_height > resize_h))
        {
            S32 w = 0, h = 0, buf_size = 0;
            U8 *buf_ptr = NULL;

            /* need to resize */
            if ((img_width * resize_h) > (img_height * resize_w))
            {
                w = resize_w;
                h = img_height * resize_w / img_width;
                if (h == 0)
                {
                    h = 1;
                }
            }
            else
            {
                w = img_width * resize_h / img_height;
                h = resize_h;
                if (w == 0)
                {
                    w = 1;
                }
            }

            /* resize the image and encode to jpef file */
            buf_size = (w * h * GDI_MAINLCD_BIT_PER_PIXEL) >> 3;
            buf_size = ((buf_size + 3) / 4) * 4;
            if (buf_size > 0)
            {
                media_get_ext_buffer(MOD_MMI, (void **)&buf_ptr, buf_size);
                if (buf_ptr != NULL)
                {
                    dest_fname = (char*)HDI_FileNameTranslate(dest_file);
                    gdi_ret = gdi_image_encode_file_to_jpeg((PS8) fname, dest_fname, w, h, buf_ptr, buf_size);
                    HDI_FileNameFree((kal_uint8*) dest_fname);
                    media_free_ext_buffer(MOD_MMI, (void **)&buf_ptr);
                }
                switch (gdi_ret)
                {
                case GDI_SUCCEED:
                    ret = MSF_WIDGET_EXT_RESIZING_SUCCEED;
                    break;
                case GDI_IMAGE_ENCODER_ERR_DISK_FULL:
                    ret = MSF_WIDGET_EXT_RESIZING_FAILED_IN_GDI_ENCODER_ERR_DISK_FULL;
                    break;
                case GDI_IMAGE_ENCODER_ERR_WRITE_PROTECTION:
                    ret = MSF_WIDGET_EXT_RESIZING_FAILED_IN_GDI_ENCODER_ERR_WRITE_PROTECTION;
                    break;
                case GDI_IMAGE_ENCODER_ERR_NO_DISK:
                    ret = MSF_WIDGET_EXT_RESIZING_FAILED_IN_GDI_ENCODER_ERR_NO_DISK;
                    break;
                default:
                    ret = MSF_WIDGET_EXT_RESIZING_FAILED_IN_GDI_FAILED;
                }
            }
            else
            {
                /* -12: can't allocate gdi_layer for drawing image */
                ret = MSF_WIDGET_EXT_RESIZING_FAILED_IN_INSUFFICIENT_DRAWING_BUF;
            }
        }
        else
        {
            /* don't need resizing: the dimension of the original image is smaller */
            ret = MSF_WIDGET_EXT_RESIZING_SUCCEED_WITH_UNCHANGED; 
        }
    }
    else
    {
        /* -11: can't get the image dimension */
	    ret = MSF_WIDGET_EXT_RESIZING_FAILED_IN_UNKNOWN_DIMENSION;   
    }
    HDI_FileNameFree((kal_uint8*) fname);
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_IMAGE_RESIZING_END, ret);	

    return ret;
}


#ifdef __MMI_VIDEO_PLAYER__
/*****************************************************************************
 * FUNCTION
 *  widget_MMI_open_video_file_done_hdlr
 * DESCRIPTION
 *  The return callback function when open video file
 * PARAMETERS
 *  result          [IN]        
 *  video_clip      [IN]         
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool widget_MMI_open_video_file_done_hdlr(MDI_RESULT result, mdi_video_info_struct *video_clip)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_image_struct *img;
    MsfSize *size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    img = (WGUI_CTX->second_video != NULL) ? WGUI_CTX->second_video : WGUI_CTX->current_video;
    /*
     * After MMI receives the primitive MSG_ID_MEDIA_VID_FILE_READY_IND, it calls this function.
     * This function is executed in MMI thread.
     */
    size = widget_image_dimension((MsfImageHandle) img);

    if (result < 0)
    {
        /* if open file error */
        size->width = 0;
        size->height = 0;

        widget_send_notification_load_resource(img, MsfNotifyResourceError);

        img->is_done = KAL_FALSE;
        img->video_in_preview = 0;
        img->GIF_frames = 0;
        img->GIF_frames_initialized = 0;
        img->video_time_duration = 0;

        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_OPEN_VIDEO_FILE_DONE_HDLR_FAILED);
        return KAL_FALSE;
    }
    else
    {
        kal_int16 viewer_w, viewer_h;

        /* if open successfully */
        videoResourceCount++;
        size->width = (MSF_INT16) video_clip->width;
        size->height = (MSF_INT16) video_clip->height;

        /* We create the video dimension less than MMS viewer's visual area */
    #ifdef WIDGET_SLIDING_SMIL_SUPPORT
        viewer_w = WGUI_CTX->display_size.width- MSF_CFG_SCROLLBAR_WIDTH;
        viewer_h = WGUI_CTX->display_size.height - WIDGET_SLIDING_SMIL_TOP - WIDGET_SLIDING_SMIL_BOTTOM;
    #else
        viewer_w = WGUI_CTX->display_size.width - MSF_CFG_SCROLLBAR_WIDTH;
        viewer_h = WGUI_CTX->display_size.height;
    #endif
        if (size->width >= viewer_w)
        {
            size->height = viewer_w * size->height / size->width;
            size->width = viewer_w;
        }
        if (size->height >= viewer_h)
        {
            size->width = viewer_h * size->width / size->height;
            size->height = viewer_h;
        }
 
        img->is_done = KAL_TRUE;
        img->video_in_preview = 0;
        img->GIF_frames = 0;
        img->GIF_frames_initialized = 0;

        if (video_clip->total_time_duration > 0xFFFFFFFF)
        {
            img->video_time_duration = 0xFFFFFFFF;
        }
        else
        {
            /* the duration unit is ms, we need to make sure the duration should be longer than 1000 ms */
            img->video_time_duration = (video_clip->total_time_duration > 1000) ? video_clip->total_time_duration : 1000;
        }
        widget_send_notification_load_resource(img, MsfNotifyResourceReady);
    #ifdef __MMI_VIDEO_PLAYER__
        mdi_video_ply_seek(0);
        mdi_video_ply_close_clip_file();
    #endif /* __MMI_VIDEO_PLAYER__ */ 

        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_OPEN_VIDEO_FILE_DONE_HDLR_SUCCEED);

        return KAL_TRUE;
    }
}
#endif /* #ifdef __MMI_VIDEO_PLAYER__ */


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_create_video_resource
 * DESCRIPTION
 *  Create the video resource (MMI task)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_MMI_create_video_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MsfImageHandle image;
    U32  backup_video_state = 0;
    char *video_fname;
#ifdef __MMI_VIDEO_PLAYER__
    MDI_RESULT mdi_ret = -1;
    mdi_video_info_struct video_clip = {0};
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WGUI_CTX->second_video != NULL)
    {
        /*
         * The application try create the second video resource first,
         * then release the previous one if the second is created successfully.
         * But MED Task only supports one video file at the same time, 
         * the widget need to close the previous automatically.
         */
    #ifdef __MMI_VIDEO_PLAYER__
        if ((WGUI_CTX->current_video_state == WIDGET_VIDEO_PLAYING) ||
            (WGUI_CTX->current_video_state == WIDGET_VIDEO_PLAYING_OUT_OF_LCD))
        {
            mdi_video_ply_stop();
        }
        mdi_video_ply_close_clip_file();
    #endif /* __MMI_VIDEO_PLAYER__ */ 
        backup_video_state = WGUI_CTX->current_video_state;
        WGUI_CTX->current_video_state = WIDGET_VIDEO_NONE;
        image = (MsfImageHandle) WGUI_CTX->second_video;
    }
    else
    {
        image = (MsfImageHandle) WGUI_CTX->current_video;
    }
    video_fname = (char*)HDI_FileNameTranslate(widget_image_content_file(image));
#ifdef __MMI_VIDEO_PLAYER__
    /* 
     * Because mdi_api is designed for MMI task, we need to call mdi_api in MMI thread
     *
     * If we want to use mdi_video_ply_open_file, 
     * widget_MMI_open_video_file_done_hdlr() will be the callback function. 
     */
    mdi_ret = mdi_video_ply_open_clip_file((const S8*)video_fname, &video_clip);
    widget_MMI_open_video_file_done_hdlr(mdi_ret, &video_clip);

    if (mdi_ret < 0)
    {
        /* open video file error */
        if (WGUI_CTX->second_video != NULL)
        {
            /*
             * if second_video exists, it means create the second video 
             * resource failed. 
             * We need to create the previous video file automatically here.
             */
            WGUI_CTX->second_video = NULL;
            WGUI_CTX->current_video_state = backup_video_state;
        }
        else
        {
            WGUI_CTX->current_video = NULL;
            WGUI_CTX->current_video_state = WIDGET_VIDEO_NONE;
        }
    }
    else
    {
        /* open video file successfully */
        if (WGUI_CTX->second_video != NULL)
        {
            /* 
             * if second_video exists, it means create the second video resource succeed. 
             * The first video resource should be closed before playing the second.
             * ref. widget_image_release()
             */
            WGUI_CTX->second_video = NULL;
            WGUI_CTX->current_video_state = WIDGET_VIDEO_FILE_ALREADY_CHECKED;
        }
        else
        {
            /* the first video resource succeed */
            WGUI_CTX->current_video_state = WIDGET_VIDEO_FILE_ALREADY_CHECKED;
        }
    }
#endif /* __MMI_VIDEO_PLAYER__ */ 

    HDI_FileNameFree((kal_uint8*) video_fname);
}


/*****************************************************************************
 * FUNCTION
 *  widget_create_video_resource
 * DESCRIPTION
 *  Create the video resource (WAP task)
 *  In our platform, we only open one video file at the same time.
 *  When the screen switches, we should close the current video file.
 * PARAMETERS
 *  img     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_create_video_resource(widget_image_struct *img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_rawfile_configure_format(
        img->rawfile_id,
        img->image_format,
        widget_image_format_to_extension(img->image_format));

    if (widget_image_content_file((MsfImageHandle) img))
    {
        if (WGUI_CTX->current_video == NULL)
        {
            /* try to create the first video resource */
            WGUI_CTX->current_video = img;
            WGUI_CTX->current_video_state = WIDGET_VIDEO_NONE;
        }
        else
        {
            /* try to create the second video resource */
            if (WGUI_CTX->current_video == img)
            {
                /* do nothing */
                return;
            }
            else if (WGUI_CTX->second_video == NULL)
            {
                WGUI_CTX->second_video = img;
            }
            else
            {
                ASSERT(0);
            }
        }

        widget_execute_MMI(widget_MMI_create_video_resource, KAL_TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetImageCreateResource
 * DESCRIPTION
 *  
 *  Note: According to Teleca's reply, files should only be closed, but pipes should be both closed and deleted.
 * PARAMETERS
 *  modId               [IN]        
 *  resource            [IN]         
 *  resourceType        [IN]        
 *  imageFormat         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfImageHandle HDIa_widgetImageCreateResource(
                MSF_UINT8 modId,
                char *resource,
                MsfResourceType resourceType,
                MsfImageFormat imageFormat)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*
     * User applications SHOULD use the return value to find out if the image is created successfully
     *
     * We will compute the size of the image after image/file is loaded
     *
     * Note that we do set default style in this API.
     */

    widget_raw_data_struct *raw = NULL;
    widget_image_struct *img = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_VIDEO_PLAYER__    
    if ((MsfVideoFormat) imageFormat >= MsfVideoFormatStart)
    {
        /* If don't support video, return NULL directly when imageFormat is video */
        return NULL;
    }
#endif /* #ifndef __MMI_VIDEO_PLAYER__ */
    
    switch (resourceType)
    {
        case MsfResourceFile:
        {
            long size;
            int f;

            f = HDIa_fileOpen(MSF_MODID_WIDGET, resource, HDI_FILE_SET_RDONLY, 0);
            if (f < 0)
            {
                /* do nothing */ ;
            }
            else if ((size = HDIa_fileGetSize(resource)) <= 0 ||
                     (widget_is_rawfile_full() && widget_rawfile_allow_to_create_image(0, 0)))
            {
                HDIa_fileClose(f);
            }
            else
            {
                /* allocate the raw data */
                img = widget_create_image(modId);
                img->module_id = modId;
                img->image_format = imageFormat;

                if ((MsfVideoFormat) imageFormat >= MsfVideoFormatStart)
                {
                    /* video */
                    if (widget_rawfile_allow_to_create_image(imageFormat, size))
                    {
                        img->rawfile_id = widget_rawfile_register((MsfImageHandle) img);
                    }
                }
                else
                {
                    /* image */
                    /* preallocate the data because we already know the size */
                    if (widget_rawfile_allow_to_create_image(imageFormat, size))
                    {
                        img->rawfile_id = widget_rawfile_register((MsfImageHandle) img);
                    }
                    else
                    {
                        raw = widget_create_raw_data_ext(modId, size);
                        widget_set_attrib(img, raw, raw);
                    }

                }

                switch (widget_read_image_from_file(f, size, img, KAL_TRUE, KAL_FALSE))
                {
                    case WIDGET_READ_FINISH:
                        HDIa_fileClose(f);
                        break;
                    case WIDGET_WAIT_SELECT:
                        break;
                    case WIDGET_READ_ERROR:
                        HDIa_fileClose(f);
                        break;
                }
            }

        }
            break;

        case MsfResourcePipe:
        {
            /* No support video resource */
            int f;

            f = HDIa_pipeOpen(MSF_MODID_WIDGET, resource);
            if (f >= 0)
            {
                img = widget_create_image(modId);
                img->module_id = modId;
                img->image_format = imageFormat;

                switch (widget_read_image_from_pipe(f, img, KAL_TRUE))
                {
                    case WIDGET_READ_FINISH:
                        HDIa_pipeDeleteByHandle(f);
                        break;
                    case WIDGET_WAIT_SELECT:
                        /*
                         * We remove the follow code. (2005/09/27)
                         * In other situation, the upper application may create the 
                         * pipe and calls HDIa_widgetImageCreateResource() to create 
                         * the image. Sometimes the handset didn't receive the image 
                         * data from the network yet, and the function 
                         * widget_image_check_header will judge the file is invalid
                         * and delete the pipe. The image won't be showed on the screen. 
                         * Please refer MAUI_00126073              *
                         *
                         *
                         *
                         * VSWAP test case. 
                         * If we receive the invalid WBMP image, we should show the
                         * string not the empty image.
                         * We need to close the connection immediately after 
                         
                         if(!widget_image_check_header((MsfImageHandle)img))
                         HDIa_pipeDeleteByHandle(f);
                         // TODO: remove pipe map, send notification, test VSWAP
                         */
                        break;
                    case WIDGET_READ_ERROR:
                        HDIa_pipeDeleteByHandle(f);
                        break;
                }
            }
        }
            break;

        case MsfResourceBuffer:
            WAP_DBG_ASSERT(0);  /* Not supported */
            break;

        case MsfResourcePartialFile:
        {
            MsfPartialFileData *data = (MsfPartialFileData*) resource;
            int f = -1;

            WAP_DBG_ASSERT(data->start_offset >= 0 && data->data_size > 0);

            /* Check the file if already open for virtual file */
            if (!widget_is_rawfile_full())
            {
                f = widget_open_check_original_file_for_virtual_file(data);
            }
            /* already check offset and size in widget_open_check_original_file_for_virtual_file */
            if (f < 0)
            {
                /* do nothing, break directly */
                break;
            }

            /* allocate the raw data */
            img = widget_create_image(modId);
            img->module_id = modId;
            img->image_format = imageFormat;

            img->rawfile_id = widget_rawfile_register((MsfImageHandle) img);
            if (widget_rawfile_gen_virtual_file(img->rawfile_id, f, data->start_offset, data->data_size))
            {
                if ((MsfVideoFormat) imageFormat >= MsfVideoFormatStart)
                {
                    /* video */
                    widget_create_video_resource(img);
                }
                else
                {
                    /* image */
                    widget_create_image_resource(img);
                }
            }

        }
            break;

    #ifdef __DRM_SUPPORT__
        case MsfResourceDRMFile:
        {
            kal_uint32 size;
            FS_HANDLE f;
            kal_uint8 *sys_fname;

            sys_fname = HDI_FileNameTranslate(resource);
            /* Note: DRM files are opened in "blocking" mode. */
            if ((MsfVideoFormat) imageFormat >= MsfVideoFormatStart)
            {
                /* video */
                f = DRM_open_file((kal_wchar*) sys_fname, FS_READ_ONLY | FS_OPEN_SHARED, DRM_PERMISSION_PLAY);
            }
            else
            {
                f = DRM_open_file((kal_wchar*) sys_fname, FS_READ_ONLY | FS_OPEN_SHARED, DRM_PERMISSION_DISPLAY);
            }

            HDI_FileNameFree(sys_fname);
            sys_fname = NULL;

            if (f < 0)
            {
                /* do nothing */ ;
            }
            else if (DRM_file_size(f, &size) < FS_NO_ERROR || size == 0 ||
                     (widget_is_rawfile_full() && widget_rawfile_allow_to_create_image(0, 0)))
            {
                DRM_close_file(f);
            }
            else
            {
                /* allocate the raw data */
                img = widget_create_image(modId);
                img->module_id = modId;
                img->image_format = imageFormat;

                if ((MsfVideoFormat) imageFormat >= MsfVideoFormatStart)
                {
                    /* video */
                    if (widget_rawfile_allow_to_create_image(imageFormat, size))
                    {
                        img->rawfile_id = widget_rawfile_register((MsfImageHandle) img);
                    }
                }
                else
                {
                    /* image */
                    /* preallocate the data because we already know the size */
                    if (widget_rawfile_allow_to_create_image(imageFormat, size))
                    {
                        img->rawfile_id = widget_rawfile_register((MsfImageHandle) img);
                    }
                    else
                    {
                        raw = widget_create_raw_data_ext(modId, size);
                        widget_set_attrib(img, raw, raw);
                    }
                }

                switch (widget_read_image_from_file
                        (f, size, img, KAL_FALSE /* blocking mode */ , KAL_TRUE /* Is DRM */ ))
                {
                    case WIDGET_READ_FINISH:
                        DRM_close_file(f);
                        break;
                    case WIDGET_WAIT_SELECT:
                        break;
                    case WIDGET_READ_ERROR:
                        DRM_close_file(f);
                        break;
                }
            }
        }
            break;
    #endif /* __DRM_SUPPORT__ */ 

        default:
            WAP_DBG_ASSERT(0);
            break;
    }

    return (MsfImageHandle) img;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetImageCreateEmpty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId               [IN]        
 *  size                [IN]         
 *  defaultStyle        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfImageHandle HDIa_widgetImageCreateEmpty(MSF_UINT8 modId, MsfSize *size, MsfStyleHandle defaultStyle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MsfStyleHandle copy_style;

    widget_image_struct *img = widget_create_image(modId);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    img->module_id = modId;
    img->is_drawn_image = 1;

    if (size)
    {
        img->size = *size;
    }

    if (defaultStyle)
    {
        /*
         * Duplicte the style object because we will draw one the image.
         * * 
         * * FIXME. COPY-ON-WRITE of style object is a better solution. 
         * * However, the implementation will be much more complex.
         */
        copy_style = widget_style_copy(modId, defaultStyle);
        widget_set_attrib(img, style, copy_style);
        DEC_REF(copy_style);
    }
    else
    {
        widget_set_attrib(img, style, 0);
    }
    return (MsfImageHandle) img;
}

#ifdef WIDGET_BROWSER_AUTORESIZE_JPEG


/*****************************************************************************
 * FUNCTION
 *  widget_image_auto_resize_JPEG
 * DESCRIPTION
 *  In platform MT6205B, MT6218, MT6218B and MT6217, HW has limitation of
 *  encoding JPEG image, and we need to resize the JPEG in this situation.
 * PARAMETERS
 *  image           [IN]        
 *  max_size        [IN]        
 *  size            [IN]         
 * RETURNS
 *  if need to resize the JPEG
 *****************************************************************************/
kal_bool widget_image_auto_resize_JPEG(MsfImageHandle image, const MsfSize *max_size, MsfSize *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool ret = KAL_FALSE;
    widget_image_struct *img;
    S32 width, height;              /* image width/height */
    S32 zoom_width, zoom_height;
    S32 width_round, height_round;  /* round to muliply of 16 */
    S32 tmp_width, tmp_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!image || !IS_IMAGE_TYPE(image))
    {
        return ret;
    }

    img = _IMG(image);

    if (img->image_format != MsfJpeg)
    {
        return ret;
    }

    width = img->size.width;
    height = img->size.height;

    /* 
     * Reference: widget_form_sliding_SMIL_fit_image() 
     * It is tricky due to hardware limitation on MT6217/MT6218.
     */
    /* NUM_JPEG_BUFFER_PIXELS_16: The number of 16x16 blocks available in JPEG frame buffer. */
#define NUM_JPEG_BUFFER_PIXELS_16   ((GDI_LCD_WIDTH/16+1)*((GDI_LCD_HEIGHT/16+1)))

    if (max_size)
    {
        S32 dummy_x, dummy_y;

        gdi_image_util_fit_bbox(
            max_size->width,
            max_size->height,
            width,
            height,
            &dummy_x,
            &dummy_y,
            &zoom_width,
            &zoom_height);
    }
    else
    {
        zoom_width = width;
        zoom_height = height;
    }

    width_round = (zoom_width + 15) >> 4;
    height_round = (zoom_height + 15) >> 4;

    if (width_round * height_round > NUM_JPEG_BUFFER_PIXELS_16)
    {
        if (img->module_id != MSF_MODID_BRS)
        {
            /* MMS also resize image in SMIL editor. Only browser has such a large image */
            MMI_DBG_ASSERT(0);
        }
        else
        {
            do
            {
                if (width > height)
                {
                    width_round--;
                    tmp_width = width_round << 4;
                    tmp_height = tmp_width * height / width;
                    height_round = (tmp_height + 15) >> 4;
                }
                else
                {
                    height_round--;
                    tmp_height = height_round << 4;
                    tmp_width = tmp_height * width / height;
                    width_round = (tmp_width + 15) >> 4;
                }
            } while (width_round * height_round > NUM_JPEG_BUFFER_PIXELS_16);

            if (tmp_width == 0 || tmp_width == 0)
            {
                /* Very strange image size (width/height ratio is abnormal, e.g. width =  5, height = 2000) 
                   We can not fit the image into JPEG buffer. */
                WAP_DBG_ASSERT(0);
            }
            else
            {
                /* Return */
                size->width = tmp_width;
                size->height = tmp_height;
                ret = KAL_TRUE;
            }
        }
    }

    return ret;
}

#endif /* WIDGET_BROWSER_AUTORESIZE_JPEG */ 


/*****************************************************************************
 * FUNCTION
 *  widget_initialize_image_dimension
 * DESCRIPTION
 *  
 * PARAMETERS
 *  image       [IN]        
 * RETURNS
 *  Whether the image dimension is set successfully
 *     1: get dimension succeed
 *     0: can't get dimension;
 *     -1: dimension is too large;
 *     -2: file is corrupted;
 *****************************************************************************/
/*
 * NOTE: We read image header from file at the beginning, whcih prevent the 
 * * re-entrance of GDI dimension API. (WAP and MMI have the same priority, 
 * * and context switch only happens between reading files)
 */
static kal_int32 widget_initialize_image_dimension(MsfImageHandle image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* [ret]
     * 1: get dimension succeed
     * 0: can't get dimension;
     * -1: dimension is too large;
     * -2: file is corrupted;
     */
    kal_int32 ret = 0;
    GDI_RESULT gdi_ret;
    char *content, *fname;
    U32 len;
    S32 width, height;
    MsfSize *size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if supporting the image format */

    if (widget_image_format(image) >= MsfPI_Start && 
        widget_image_format(image) <= MsfPI_End)
    {
        /* Actually we only support predefined image with Pbm */
        /* get the dimension succeed */
        return 1;
    }

    if (widget_image_format(image) == MsfJpeg)
    {
    #ifndef WIDGET_JPEG_SUPPORT
        /* can't get the dimension */
        return 0;
    #endif 
    }

    if (widget_image_format(image) == MsfPng)
    {
    #ifndef GDI_USING_PNG
        /* can't get the dimension */
        return 0;
    #endif 
    }

    size = widget_image_dimension(image);
    size->width = 0;
    size->height = 0;
    content = widget_image_content_file(image);
    if (content != NULL)
    {
        fname = (char*)HDI_FileNameTranslate(content);
        gdi_ret = gdi_image_get_dimension_file((PS8) fname, &width, &height);
        HDI_FileNameFree((kal_uint8*) fname);
    }
    else
    {
        ret = KAL_FALSE;
        size->width = 0;
        size->height = 0;

        content = (char*)widget_image_content(image);
        if (content == NULL)
        {
            /* if content is NULL, it means MsfImageHandle is invalid */
            /* can't get the dimension */
            return 0;
        }

        len = (U32) widget_image_length(image);

        switch (widget_image_format(image))
        {
            case MsfBmp:
                gdi_ret = gdi_image_bmp_get_dimension((U8*) content, &width, &height);
                break;
            case MsfGif:
                gdi_ret = gdi_image_gif_get_dimension((U8*) content, &width, &height);
                break;
            case MsfWbmp:
                gdi_ret = gdi_image_wbmp_get_dimension((U8*) content, &width, &height);
                break;
            case MsfJpeg:
                gdi_ret = gdi_image_jpeg_get_dimension((U8*) content, len, &width, &height);
                break;
            case MsfPng:
            #ifdef GDI_USING_PNG
                gdi_ret = gdi_image_png_get_dimension((U8*) content, len, &width, &height);
                break;
            #endif /* GDI_USING_PNG */ 
            default:
                /* can't get the dimension */
                gdi_ret = 0;
                break;
        }
        /* 
         * After GDI supports the common API for get image dimension by the raw data,
         * we can modify the code like below.
         
         gdi_ret = gdi_image_get_dimension((U8*)content, &width, &height);
         */
    }

    if (gdi_ret >= 0)
    {
        if (width == 0 || height == 0)
        {
            /* If get the image resolution is 0, we assume the file is corrupted */
            size->width = (MSF_INT16) width;
            size->height = (MSF_INT16) height;
            /* -2: file is corrupted; */
            ret = -2;
        }
        else if (width >> 15 || height >> 15)
        {
            /* image resolution is larger than MSF_INT16 limitation */
            size->width = WIDGET_IMAGE_TOO_LARGE_WIDTH;
            size->height = WIDGET_IMAGE_TOO_LARGE_HEIGHT;
            ret = 1;
        }
        else
        {
            size->width = (MSF_INT16) width;
            size->height = (MSF_INT16) height;
            ret = 1;
        }
    }

#ifdef WIDGET_BROWSER_AUTORESIZE_JPEG
    /* 
     * In platform MT6205B, MT6218, MT6218B and MT6217, HW has limitation of
     * encoding JPEG image, and we need to resize the JPEG in this situation.
     */
    if (ret)
    {
        kal_bool jpg_resize_ret;
        MsfSize jpg_resize_size;

        if ((widget_image_format(image) == MsfJpeg) && (_IMG(image)->module_id == MSF_MODID_BRS))
        {
            jpg_resize_ret = widget_image_auto_resize_JPEG(image, NULL, &jpg_resize_size);
            if (jpg_resize_ret)
            {
                size->width = jpg_resize_size.width;
                size->height = jpg_resize_size.height;
                _IMG(image)->is_jpeg_auto_resize = 1;
            }
        }
    }
#endif /* WIDGET_BROWSER_AUTORESIZE_JPEG */ 

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_initialize_image_frame_count
 * DESCRIPTION
 *  For non-GIF images, frame count is set as 0
 * PARAMETERS
 *  image       [IN]        
 * RETURNS
 *  Whether the image frame count is set successfully
 *****************************************************************************/
kal_bool widget_MMI_initialize_image_frame_count(MsfImageHandle image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *content;
    S32 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Compared to widget_initialize_image_dimension(), this function must be executed 
       in MMI task */
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

    if (!IS_IMAGE_TYPE(image))
    {
        /* predefined images are not supported */
        WAP_DBG_ASSERT(0);
        return KAL_FALSE;
    }

    if (widget_image_format(image) != MsfGif)
    {
        _IMG(image)->GIF_frames = 0;
        return KAL_TRUE;
    }

    count = 0;
    content = (U8*) widget_image_content(image);
    if (content)
    {
        int size = widget_image_length(image);

        /* If the GIF image is truncated, gdi_image_gif_get_frame_count might return failure, 
           but count might be greater than 0 */
        gdi_image_gif_get_frame_count(content, size, &count);

        WAP_DBG_ASSERT(count >= 0);
        _IMG(image)->GIF_frames = count;

        return KAL_TRUE;
    }
    else if ((content = (U8*) widget_image_content_file(image)) != NULL)
    {
        char *full_name;

        full_name = (char*)HDI_FileNameTranslate((char*)content);

        gdi_image_gif_get_frame_count_file(full_name, &count);

        HDI_FileNameFree((kal_uint8*) full_name);

        WAP_DBG_ASSERT(count >= 0);
        _IMG(image)->GIF_frames = count;

        return KAL_TRUE;
    }
    else
    {
        _IMG(image)->GIF_frames = 0;
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetImageCreateFormat
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId               [IN]        
 *  imageData           [IN]         
 *  imageFormat         [IN]        
 *  resourceType        [IN]        
 *  defaultStyle        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfImageHandle HDIa_widgetImageCreateFormat(
                MSF_UINT8 modId,
                MsfCreateData *imageData,
                const char *imageFormat,
                MsfResourceType resourceType,
                MsfStyleHandle defaultStyle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int image_format = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* We may add custom features like Video. (c.f. MEA) */
    if (msf_cmmn_strcmp_nc(imageFormat, "image/bmp") == 0)
    {
        image_format = MsfBmp;
    }   /* pictogram not supported */
    else if (msf_cmmn_strcmp_nc(imageFormat, "image/gif") == 0)
    {
        image_format = MsfGif;
    }
    else if (msf_cmmn_strcmp_nc(imageFormat, "image/jpeg") == 0)
    {
        image_format = MsfJpeg;
    }
    else if (msf_cmmn_strcmp_nc(imageFormat, "image/png") == 0)
    {
        image_format = MsfPng;
    }
    else if (msf_cmmn_strcmp_nc(imageFormat, "image/vnd.wap.wbmp") == 0)
    {
        image_format = MsfWbmp;
    }
    /* image/x-portable-bitmap is different from our proprietary Pbm */

    if (image_format < 0)
    {
        return (MsfImageHandle) 0;
    }

    if (resourceType == MsfResourcePipe || resourceType == MsfResourceFile)
    {
        return (MsfImageHandle) HDIa_widgetImageCreateResource(
                                    modId,
                                    (char*)imageData->resource,
                                    resourceType,
                                    (MsfImageFormat) image_format);
    }
    else
    {
        return (MsfImageHandle) HDIa_widgetImageCreate(
                                    modId,
                                    imageData->directData->data,
                                    imageData->directData->dataSize,
                                    (MsfImageFormat) image_format,
                                    imageData->directData->moreData,
                                    defaultStyle);
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetImageGetPredefined
 * DESCRIPTION
 *  
 * PARAMETERS
 *  resId           [IN]        
 *  resString       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfImageHandle HDIa_widgetImageGetPredefined(MSF_UINT32 resId, const char *resString)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_pre_image_struct *w = NULL;
    kal_uint32 index;

#ifndef WIDGET_COMPACT_PRE_IMAGE
    kal_uint8 *src;
    int width, height;
#endif /* WIDGET_COMPACT_PRE_IMAGE */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* This is mandatory because we do not have any predefined images of resource string. 
       If we do not return 0, some images will displayed in wrong way. */
    if (resString != NULL)
    {
        return 0;
    }

    /* use a dummy image */
    if (resId < WAP_IMAGE_ID_BEGIN || resId >= WAP_IMAGE_ID_END)
    {
        /* Enable this assert to check the range of image ID */
        WAP_DBG_ASSERT(0);
        resId = WAP_IMAGE_WAP_LOGO;
    }

    index = resId - WAP_IMAGE_ID_BEGIN;

    /* get a preallocated slot */
    w = &widget_predefined_image_table[index];

#ifdef WIDGET_COMPACT_PRE_IMAGE
    w->data_type = WIDGET_PRE_IMAGE_TYPE;
    w->flag = WIDGET_FLAG_STATIC;
#else /* WIDGET_COMPACT_PRE_IMAGE */ 
    src = (kal_uint8*) get_image((kal_uint16) (resId));

    /*
     * Use a dummy image if the image does not exist.
     * * Otherwise it might produce 'access violation'
     */
    if (src == NULL)
    {
        src = (kal_uint8*) get_image(WAP_IMAGE_WAP_LOGO);
        ASSERT(src);
    }

    w->data_type = WIDGET_PRE_IMAGE_TYPE;
    w->flag = WIDGET_FLAG_STATIC;
    w->src = gdi_image_get_buf_ptr_from_id((kal_uint16)resId);
    w->length = gdi_image_get_buf_len_from_id((kal_uint16)resId);

    /* detect image format */
    switch (gdi_image_get_type_from_id((kal_uint16)resId))
    {
        case IMAGE_TYPE_BMP:
            /* FALLTHROUGH no break */
        case IMAGE_TYPE_BMP_SEQUENCE:   /* BMP */
            w->image_format = MsfBmpIP;
            break;
        case IMAGE_TYPE_GIF:            /* GIF */
            w->image_format = MsfGifIP;
            break;
        case IMAGE_TYPE_DEVICE_BITMAP:
            /* FALLTHROUGH no break */
        case IMAGE_TYPE_DEVICE_BITMAP_SEQUENCE:
            w->image_format = MsfPbmIP;
            break;
        case IMAGE_TYPE_JPG:
            w->image_format = MsfJpegIP;
            break;
        case IMAGE_TYPE_PNG:
            w->image_format = MsfPngIP;
            break;
        default:
            w->image_format = MsfUnsupportedMediaType;
            break;
    }
    gui_measure_image((kal_uint8*) src, (S32*) & width, (S32*) & height);

    w->size.width = width;
    w->size.height = height;
    w->resource_id = resId;
#endif /* WIDGET_COMPACT_PRE_IMAGE */ 

    return (MsfImageHandle) w;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtImageGetPredefinedBuffer
 * DESCRIPTION
 *  For testing
 * The application use this function to add the image resource into MMS,
 * and they process these resource in the normal image format
 * PARAMETERS
 *  resId       [IN]        
 *  length      [OUT]         
 *  type        [OUT]         
 * RETURNS
 *  
 *****************************************************************************/
const kal_uint8 *HDIa_widgetExtImageGetPredefinedBuffer(MSF_UINT32 resId, int *length, MsfImageFormat *type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *src;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    src = (kal_uint8*) get_image((kal_uint16) (resId));
    if (src)
    {
        *length = gdi_image_get_buf_len_from_id((kal_uint16)resId);
        switch (gdi_image_get_type_from_id((kal_uint16)resId))
        {
            case IMAGE_TYPE_BMP:
                /* FALLTHROUGH no break */
            case IMAGE_TYPE_BMP_SEQUENCE:   /* BMP */
                *type = MsfBmp;
                break;
            case IMAGE_TYPE_GIF:            /* GIF */
                *type = MsfGif;
                break;
            case IMAGE_TYPE_DEVICE_BITMAP:
                /* FALLTHROUGH no break */
            case IMAGE_TYPE_DEVICE_BITMAP_SEQUENCE:
                *type = (MsfImageFormat) MsfPbmPI;
                break;
            case IMAGE_TYPE_JPG:
                *type = MsfJpeg;
                break;
            case IMAGE_TYPE_PNG:
                *type = MsfPng;
                break;
            default:
                *type = (MsfImageFormat) MsfUnsupportedMediaType;
                break;
        }
        return gdi_image_get_buf_ptr_from_id((kal_uint16)resId);

    }
    else
    {
        *length = 0;
        return NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtImageGadgetGetSourceFile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  return NULL if there is not rawfile cache or something wrong happened.
 *****************************************************************************/
const char *HDIa_widgetExtImageGadgetGetSourceFile(MsfGadgetHandle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!IS_GADGET_IMAGE_TYPE(handle))
    {
        WAP_DBG_ASSERT(0);
        return NULL;
    }
    return widget_image_content_file(_GIMG(handle)->image);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtEnablePreCacheImage
 * DESCRIPTION
 *  Try to cache the image in memory if possible
 * PARAMETERS
 *  img     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtEnablePreCacheImage(MsfImageHandle img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(WIDGET_PRECACHE_IMAGE) && !defined WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING
    if (!IS_IMAGE_TYPE(img))
    {
        WAP_DBG_ASSERT(IS_PRE_IMAGE_TYPE(img));
        return;
    }
    /* WAP_DBG_ASSERT(_IMG(img)->precache_state == WIDGET_PRECACHE_IMAGE_NONE); */
    _IMG(img)->precache_state = WIDGET_PRECACHE_IMAGE_ACCEPT;
#endif /* WIDGET_PRECACHE_IMAGE */ 
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtDisableImageAnimation
 * DESCRIPTION
 *  Disable GIF animation (typically used by SMIL editor and player)
 * PARAMETERS
 *  img     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtDisableImageAnimation(MsfImageHandle img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!IS_IMAGE_TYPE(img))
    {
        WAP_DBG_ASSERT(IS_PRE_IMAGE_TYPE(img));
        return;
    }
    _IMG(img)->disable_animation = 1;

    if (WGUI_CTX->is_widget_screen)
    {
        widget_paint();
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtEnableImageAnimation
 * DESCRIPTION
 *  Enable GIF animation (default)
 * PARAMETERS
 *  img     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtEnableImageAnimation(MsfImageHandle img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!IS_IMAGE_TYPE(img))
    {
        WAP_DBG_ASSERT(IS_PRE_IMAGE_TYPE(img));
        return;
    }
    _IMG(img)->disable_animation = 0;

    if (WGUI_CTX->is_widget_screen)
    {
        widget_paint();
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_init_image
 * DESCRIPTION
 *  Initialization of image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_init_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef WIDGET_COMPACT_PRE_IMAGE
    WIMG_CTX->pre_image_cache_id = 0;
#endif 
    WIMG_CTX->gif_head = NULL;
    WIMG_CTX->busy_indication_icon = NULL;

    memset(
        widget_virtual_file_info_table,
        0,
        sizeof(widget_virtual_file_info_struct) * WIDGET_VIRTUAL_FILE_INFO_TABLE_SIZE);
}


/*****************************************************************************
 * FUNCTION
 *  widget_deinit_image
 * DESCRIPTION
 *  De-initialization of image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_deinit_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_gif_animation_struct *node = WIMG_CTX->gif_head, *next;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (node)
    {
        next = node->next;
        MSF_MEM_FREE(MSF_MODID_WIDGET, node);
        node = next;
    }
    WIMG_CTX->gif_head = NULL;
}

/****************************************************************
 * ANIMATION
 ***************************************************************/

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

/****************************************************************
 * Video
 ***************************************************************/


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtVideoCreateResource
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId               [IN]        
 *  resource            [IN]         
 *  resourceType        [IN]        
 *  videoFormat         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfImageHandle HDIa_widgetExtVideoCreateResource(
                MSF_UINT8 modId,
                char *resource,
                MsfResourceType resourceType,
                MsfVideoFormat videoFormat)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MsfResourceTypeExt type = (MsfResourceTypeExt)resourceType;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * The video only is supported in MMS. The browser can't show the video in the page.
     */
    if ((type == MsfResourcePartialFile || type == MsfResourceFile
    #ifdef __DRM_SUPPORT__
         || type == MsfResourceDRMFile
    #endif
        ) && (videoFormat >= MsfVideoFormatStart))
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_VIDEO_CREATE_RESOURCE);
        return (HDIa_widgetImageCreateResource(modId, resource, resourceType, (MsfImageFormat) videoFormat));
    }
    return (MsfImageHandle) NULL;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtGetVideoDurationTime
 * DESCRIPTION
 *  Get the video duration time
 * PARAMETERS
 *  image       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 HDIa_widgetExtGetVideoDurationTime(MsfImageHandle image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IS_IMAGE_TYPE(image) && (_IMG(image)->rawfile_id != 0))
    {
        WAP_DBG_ASSERT(WGUI_CTX->current_video_state != WIDGET_VIDEO_NONE);
        return (_IMG(image)->video_time_duration);
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtPlayVideo
 * DESCRIPTION
 *  Play the video
 * PARAMETERS
 *  image       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtPlayVideo(MsfImageHandle image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IS_IMAGE_TYPE(image) && (_IMG(image)->video_in_preview == 0) && (_IMG(image)->rawfile_id != 0))
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_PLAY_VIDEO);

        WGUI_CTX->current_video = _IMG(image);
        if (WGUI_CTX->current_video_state == WIDGET_VIDEO_FILE_ALREADY_CHECKED ||
            WGUI_CTX->current_video_state == WIDGET_VIDEO_STOP)
        {
            WGUI_CTX->current_video_state = WIDGET_VIDEO_READY_TO_PLAY;
        }
        if (WGUI_CTX->is_widget_screen)
        {
            widget_paint();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtStopVideo
 * DESCRIPTION
 *  Stop to play the video
 * PARAMETERS
 *  image       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtStopVideo(MsfImageHandle image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VIDEO_PLAYER__
    widget_video_state state = WGUI_CTX->current_video_state;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IS_IMAGE_TYPE(image) && (_IMG(image)->video_in_preview == 0) && (_IMG(image)->rawfile_id != 0))
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_STOP_VIDEO);
        WAP_DBG_ASSERT(WGUI_CTX->video_gdi_layer != 0);
    #ifdef __MMI_VIDEO_PLAYER__
        if ((state == WIDGET_VIDEO_PLAYING) || (state == WIDGET_VIDEO_PLAYING_OUT_OF_LCD))
        {
            widget_execute_MMI((func_void) mdi_video_ply_stop, KAL_TRUE);
            if (WGUI_CTX->video_gdi_layer)
            {
                mdi_video_ply_seek_and_get_frame(0, WGUI_CTX->video_gdi_layer);
            }
            widget_execute_MMI((func_void) mdi_video_ply_close_clip_file, KAL_TRUE);

         /****************************************************************************
         * Reset proper state for stoping video
         *****************************************************************************/
            /* resume background audio */
            mdi_audio_resume_background_play();
            /* let MMI can sleep */
            TurnOffBacklight();
            gdi_layer_set_blt_layer(wgui_base_layer, 0, 0, 0);
        #ifdef __MMI_SUBLCD__
            widget_freeze_sub_lcd(MMI_FALSE);
        #endif 
        }
    #endif /* __MMI_VIDEO_PLAYER__ */ 

        WGUI_CTX->current_video_state = WIDGET_VIDEO_STOP;
        if (WGUI_CTX->is_widget_screen)
        {
            widget_paint();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtCloseVideo
 * DESCRIPTION
 *  Close the video resource
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtCloseVideo()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* release video's gdi_layer */
    /*
     * When the application create the new video resource first and then 
     * release the previous, we don't need to update WGUI_CTX info.
     * We will reset WGUI_CTX related video info. if the application 
     * releases the current video resource.
     */

    if (WGUI_CTX->current_video_state == WIDGET_VIDEO_OPENED_WAIT_PLAY ||
        WGUI_CTX->current_video_state == WIDGET_VIDEO_PLAYING_OUT_OF_LCD ||
        WGUI_CTX->current_video_state == WIDGET_VIDEO_PLAYING)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_CLOSE_VIDEO_WHEN_FILE_IS_OPENED);
    #ifdef __MMI_VIDEO_PLAYER__
        if (WGUI_CTX->current_video_state == WIDGET_VIDEO_PLAYING ||
            WGUI_CTX->current_video_state == WIDGET_VIDEO_PLAYING_OUT_OF_LCD)
        {
            widget_execute_MMI((func_void) mdi_video_ply_stop, KAL_FALSE);
            widget_execute_MMI((func_void)mdi_video_ply_close_clip_file, KAL_TRUE);
            /****************************************************************************
             * Reset proper state for stoping video
             *****************************************************************************/
            /* resume background audio */
            mdi_audio_resume_background_play();
            /* let MMI can sleep */
            TurnOffBacklight();
        #ifdef __MMI_SUBLCD__
            /* 
             * Need to close the video file first because
             * we doesn't support decode the jpeg file when playing the video.
             */
            widget_freeze_sub_lcd(MMI_FALSE);
        #endif 
        }
	    else
	    {
            widget_execute_MMI((func_void)mdi_video_ply_close_clip_file, KAL_TRUE);
        }
    #endif /* __MMI_VIDEO_PLAYER__ */ /* #ifdef __MMI_VIDEO_PLAYER__ */
        if (WGUI_CTX->current_video_state != WIDGET_VIDEO_NONE &&
            WGUI_CTX->current_video_state != WIDGET_VIDEO_FILE_ALREADY_CHECKED &&
            WGUI_CTX->current_video_state != WIDGET_VIDEO_STOP &&
            WGUI_CTX->current_video_state != WIDGET_VIDEO_PREVIEW)
        {
            /* the video will play when goback to widget screen */
            WGUI_CTX->current_video_state = WIDGET_VIDEO_READY_TO_PLAY;
        }

    }

    widget_execute_MMI(widget_free_video_gdi_layer, KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtDisableVideoPlay
 * DESCRIPTION
 *  Disable video play, only show the still image (typically used by SMIL editor)
 * PARAMETERS
 *  image       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtDisableVideoPlay(MsfImageHandle image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IS_IMAGE_TYPE(image))
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_DISABLE_VIDEO_PLAY);
        WAP_DBG_ASSERT(WGUI_CTX->current_video_state != WIDGET_VIDEO_OPENED_WAIT_PLAY ||
                       WGUI_CTX->current_video_state != WIDGET_VIDEO_PLAYING ||
                       WGUI_CTX->current_video_state != WIDGET_VIDEO_PLAYING_OUT_OF_LCD);

        WGUI_CTX->current_video_state = WIDGET_VIDEO_PREVIEW;
        _IMG(image)->video_in_preview = 1;

        if (WGUI_CTX->is_widget_screen)
        {
            widget_paint();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtEnableVideoPlay
 * DESCRIPTION
 *  Enable video play (default, play the video in SMIL player)
 * PARAMETERS
 *  image       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtEnableVideoPlay(MsfImageHandle image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IS_IMAGE_TYPE(image))
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_ENABLE_VIDEO_PLAY);
        _IMG(image)->video_in_preview = 0;
        WGUI_CTX->current_video_state = WIDGET_VIDEO_FILE_ALREADY_CHECKED;

        if (WGUI_CTX->is_widget_screen)
        {
            widget_paint();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtImageFileGetSize
 * DESCRIPTION
 *  Query the image dimension accoriding the file path
 * PARAMETERS
 *  file        [IN]     
 *  size        [OUT]     
 * RETURNS
 *  
 *****************************************************************************/
kal_bool HDIa_widgetExtImageFileGetSize(char *file, MsfSize *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *fname = NULL;
    GDI_RESULT gdi_ret = GDI_FAILED;
    MSF_INT32 width = 0, height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    size->width = 0;
    size->height = 0;

    fname = (char*)HDI_FileNameTranslate(file);
    gdi_ret = gdi_image_get_dimension_file((PS8) fname, (S32*) & width, (S32*) & height);
    HDI_FileNameFree((kal_uint8*) fname);
    if (gdi_ret >= 0)
    {
        size->width = (MSF_INT16) width;
        size->height = (MSF_INT16) height;
        return KAL_TRUE;
    }

    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtCheckImageFile
 * DESCRIPTION
 *  Check the image file is valid
 * PARAMETERS
 *  file        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
kal_bool HDIa_widgetExtCheckImageFile(char *file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT gdi_ret = GDI_FAILED;
    S32        width = 0, height = 0;
    kal_int32  w = UI_device_width >> 2;
    kal_int32  h = UI_device_height >> 2;
    kal_uint8  *buffer_ptr = NULL;
    kal_uint8  buffer[(12*12*GDI_MAINLCD_BIT_PER_PIXEL)>>3];
    gdi_handle fake_layer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check image resolution */
    gdi_ret = gdi_image_get_dimension_file((PS8) file, (S32*) & width, (S32*) & height);
    if (gdi_ret < 0 || 
        width <= 0 || height <= 0 ||
        width > WIDGET_IMAGE_MAX_WIDTH || 
        height > WIDGET_IMAGE_MAX_HEIGHT)
    {
        return KAL_FALSE;
    }

    /* Check if drawing the image succeed */
    buffer_ptr = MSF_MEM_ALLOC(MSF_MODID_WIDGET, (w*h*GDI_MAINLCD_BIT_PER_PIXEL)>>3);
    if (buffer_ptr == NULL)
    {
        /* buffer[(12*12*GDI_MAINLCD_BIT_PER_PIXEL)>>3] */
        buffer_ptr = buffer;
        w = 12;
        h = 12;
    }

    gdi_layer_create_using_outside_memory(
        0,
        0,
        w,
        h,
        &fake_layer,
        (PU8) buffer_ptr,
        (S32) (w*h*GDI_MAINLCD_BIT_PER_PIXEL)>>3);

    gdi_layer_push_and_set_active(fake_layer);
    gdi_ret = gdi_image_draw_resized_file(0, 0, w, h, (S8 *)file);
    gdi_layer_pop_and_restore_active();
    gdi_layer_free(fake_layer);
    if (buffer_ptr != buffer)
    {
        MSF_MEM_FREE(MSF_MODID_WIDGET, buffer_ptr);
    }

    if (gdi_ret == GDI_SUCCEED)
    {
        return KAL_TRUE;
    }

    return KAL_FALSE;
}


#ifdef WIDGET_CHECK_IMAGE_IN_DETAIL
/*****************************************************************************
 * FUNCTION
 *  widget_check_image_in_detail
 * DESCRIPTION
 *  Check the MsfImage is valid in detail
 * PARAMETERS
 *  image       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool widget_check_image_in_detail(MsfImageHandle image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT gdi_ret = GDI_FAILED;
    char *content, *fname;
    kal_int32  w = UI_device_width >> 2;
    kal_int32  h = UI_device_height >> 2;
    kal_uint8  *buffer_ptr = NULL;
    kal_uint8  buffer[(12*12*GDI_MAINLCD_BIT_PER_PIXEL)>>3];
    gdi_handle fake_layer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if supporting the image format */
    if (widget_image_format(image) >= MsfPI_Start && 
        widget_image_format(image) <= MsfPI_End)
    {
        /* Actually we only support predefined image with Pbm */
        return KAL_TRUE;
    }

    if (widget_image_format(image) == MsfJpeg)
    {
    #ifndef WIDGET_JPEG_SUPPORT
        return KAL_FALSE;
    #endif 
    }

    if (widget_image_format(image) == MsfPng)
    {
    #ifndef GDI_USING_PNG
        return KAL_FALSE;
    #endif 
    }

    buffer_ptr = MSF_MEM_ALLOC(MSF_MODID_WIDGET, (w*h*GDI_MAINLCD_BIT_PER_PIXEL)>>3);
    if (buffer_ptr == NULL)
    {
        /* buffer[(12*12*GDI_MAINLCD_BIT_PER_PIXEL)>>3] */
        buffer_ptr = buffer;
        w = 12;
        h = 12;
    }

    gdi_layer_create_using_outside_memory(
        0,
        0,
        w,
        h,
        &fake_layer,
        (PU8) buffer_ptr,
        (S32) (w*h*GDI_MAINLCD_BIT_PER_PIXEL)>>3);
    gdi_layer_push_and_set_active(fake_layer);

    content = widget_image_content_file(image);
    if (content != NULL)
    {   /* image file */
        fname = (char*)HDI_FileNameTranslate(content);
        gdi_ret = gdi_image_draw_resized_file(0, 0, w, h, (S8 *)fname);
        HDI_FileNameFree((kal_uint8*) fname);
    }
    else
    {   /* image data */
        content = (char*)widget_image_content(image);
        if (content != NULL)
        {
            gdi_ret = gdi_image_draw_resized_frames(0, 0, w, h, (U8*) content, 0);
        }
    }
    gdi_layer_pop_and_restore_active();
    gdi_layer_free(fake_layer);
    if (buffer_ptr != buffer)
    {
        MSF_MEM_FREE(MSF_MODID_WIDGET, buffer_ptr);
    }

    if (gdi_ret == GDI_SUCCEED)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}
#endif /* WIDGET_CHECK_IMAGE_IN_DETAIL */


