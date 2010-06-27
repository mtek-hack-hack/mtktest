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
#include "kal_release.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"       	/* Task message communiction */
#include "wap_ps_struct.h"

/* MSF */
#include "msf_def.h"
#include "msf_int.h"
#include "msf_mem.h"
#include "msf_dcvt.h"
#include "msf_cmmn.h"

/* MMS */
#include "mms_def.h"
#include "mms_cfg.h"
#include "mms_if.h"
#include "msig.h"
#include "fldmgr.h"

/* SLS */
#include "sls_def.h"
#include "sls_cfg.h"
#include "sls_if.h"

/* SMA */
#include "sma_def.h"

/* MEA */
#include "meal_if.h"

/* MMA */
#include "mmsadp.h"
#include "mma_def.h"
#include "mma_conf.h"
#include "mma_utils.h"

/* Widget */
#include "wapadp.h"
#include "Widget_extension.h"

/* Misc */
#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "UnifiedMessageGProt.h"
#include "UnifiedComposerGProt.h"
#include "FileManagerGProt.h"

#ifdef __UNIFIED_COMPOSER_SUPPORT__

#define IS_EMAIL(x) (strchr(x, '@') != NULL)

/* Refer to Sls_if.c */
#define SLS_SMIL_START      "<smil>\n"
#define SLS_SMIL_END        "</smil>\n"
#define SLS_HEAD_START      "<head>\n"
#define SLS_HEAD_END        "</head>\n"
#define SLS_BODY_START      "<body>\n"
#define SLS_BODY_END        "</body>\n"
#define SLS_PAR_START       "<par dur=\"%dms\">\n"
#define SLS_PAR_END         "</par>\n"
#define SLS_TEXT_T1         "<text src=\"%s\" region=\"%s\" "
#define SLS_TEXT_T4         "<param name=\"foregroundcolor\" value=\"%s\" /></text>\n"
#define SLS_TEXT_T6         ">\n"
#define SLS_IMAGE_T1        "<img src=\"%s\" region=\"%s\" "
#define SLS_IMAGE_T4        "/>\n"
#define SLS_VIDEO_T1        "<video src=\"%s\" region=\"%s\" "
#define SLS_VIDEO_T4        "/>\n"
#define SLS_AUDIO_T1         "<audio src=\"%s\" "
#define SLS_AUDIO_T4        "/>\n"
#define SLS_LAYOUT_START    "<layout>\n"
#define SLS_LAYOUT_END      "</layout>\n"
#define SLS_ROOT_LAYOUT_T1  "<root-layout width=\""
#define SLS_ROOT_LAYOUT_T2  "\" height=\""
#define SLS_ROOT_LAYOUT_T3  "\" background-color=\""
#define SLS_ROOT_LAYOUT_T4  "\"/>\n"
#define SLS_REGION_T1       "<region id=\""
#define SLS_REGION_T2       "\" width=\""
#define SLS_REGION_T3       "\" height=\""
#define SLS_REGION_T4       "\" left=\""
#define SLS_REGION_T5       "\" top=\""
#define SLS_REGION_T6       "\" "
#define SLS_REGION_T7       "/>\n"

#define SLS_FIT_FILL   "fit=\"fill\""
#define SLS_FIT_HIDDEN "fit=\"hidden\""
#define SLS_FIT_MEET   "fit=\"meet\""
#define SLS_FIT_SCROLL "fit=\"scroll\""
#define SLS_FIT_SLICE  "fit=\"slice\""

#define COLOR_RGB_STR       "#RRGGBB"
/******************************************************************************
 * Local variables/functions
 ******************************************************************************/
static kal_uint32 req_id = 0;
/*************************************************************************
* FUNCTION
*	wap_translate_um_folder_2_mms_folder
* DESCRIPTION
*  This function is used to convert MMA folder definition to MMS folder definition
*
* CALLS
*
* PARAMETERS
* box
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
MmsFolderType wap_translate_mma_folder_2_mms_folder(mma_folder_enum box)
{
    MmsFolderType folder = MMS_NO_FOLDER;

    if(box & MMA_FOLDER_INBOX)
    {
        folder |= MMS_INBOX;
    }

    if(box & MMA_FOLDER_SENT)
    {
        folder |= MMS_SENT;
    }

    if(box & MMA_FOLDER_OUTBOX)
    {
        folder |= MMS_OUTBOX;
    }

    if(box & MMA_FOLDER_DRAFT)
    {
        folder |= MMS_DRAFTS;
    }

    if(box & MMA_FOLDER_TEMPLATE)
    {
        folder |= MMS_TEMPLATES;
    }

    if(box & MMA_FOLDER_ARCHIVE)
    {
        folder |= MMS_ARCHIVE;
    }

#ifdef __MMI_OBIGO_Q03C_MMS_USER_DEFINED_TEMPLATES__
    if(box & MMA_FOLDER_USRDEF_TEMPLATE)
    {
        folder |= MMS_USRDEF_TEMPLATES;
    }
#endif

    return folder;
}

/*************************************************************************
* FUNCTION
*	wap_translate_mms_folder_2_mma_folder
* DESCRIPTION
*  This function is used to convert MMA folder definition to UM folder definition
*
* CALLS
*
* PARAMETERS
* box
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
mma_folder_enum wap_translate_mms_folder_2_mma_folder(MmsFolderType folder)
{
    mma_folder_enum box = 0;

    if(folder & MMS_INBOX)
    {
        box |= MMA_FOLDER_INBOX;
    }

    if(folder & MMS_SENT)
    {
        box |= MMA_FOLDER_SENT;
    }

    if(folder & MMS_OUTBOX)
    {
        box |= MMA_FOLDER_OUTBOX;
    }

    if(folder & MMS_DRAFTS)
    {
        box |= MMA_FOLDER_DRAFT;
    }

    if(folder & MMS_TEMPLATES)
    {
        box |= MMA_FOLDER_TEMPLATE;
    }

    if(folder & MMS_ARCHIVE)
    {
        box |= MMA_FOLDER_ARCHIVE;
    }

#ifdef __MMI_OBIGO_Q03C_MMS_USER_DEFINED_TEMPLATES__
    if(folder & MMS_USRDEF_TEMPLATES)
    {
        box |= MMA_FOLDER_USRDEF_TEMPLATE;
    }
#endif

    return box;
}

static kal_uint8 len_uintvar(kal_uint32 n)
{
    if (n < 0x80)
    {
        return 1;
    }
    else if (n < 0x4000)
    {
        return 2;
    }
    else if (n < 0x200000)
    {
        return 3;
    }
    else if (n < 0x10000000)
    {
        return 4;
    }
    else
    {
        return 5;
    } 
} 

static kal_uint8 len_value_length(kal_uint32 n)
{
    kal_uint8 size = 0;
    if(n > 30)
    {
        size += len_uintvar(n);
        size++;  /* Length-quote */
    }
    else
    {
        size = 1;
    }

    return size;
} 

static char *ucs2_to_utf8_string(const kal_uint8 *ucs2)
{
    kal_uint32 len = 0;
    char *utf8 = NULL;

    len = widget_ucs2_to_utf8_length_in_bytes(ucs2);
    utf8 = MSF_MEM_ALLOC(MSF_MODID_MMA, len + 1);
    widget_ucs2_to_utf8_string((kal_uint8*)utf8, len + 1, ucs2);
    return utf8;
}

/*****************************************************************************
 * FUNCTION
 *  mma_uc_set_file_mgr_filter_for_image
 * DESCRIPTION
 *  Set the image filter
 * PARAMETERS
 *  filter        [OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_uc_set_file_mgr_filter_for_image(FMGR_FILTER* filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(filter);
    
    FMGR_FILTER_SET(filter, FMGR_TYPE_BMP);
    FMGR_FILTER_SET(filter, FMGR_TYPE_GIF);
    FMGR_FILTER_SET(filter, FMGR_TYPE_WBM);
    FMGR_FILTER_SET(filter, FMGR_TYPE_WBMP);
#ifdef GDI_USING_PNG
    FMGR_FILTER_SET(filter, FMGR_TYPE_PNG);
#endif 
#ifdef JPG_DECODE
    FMGR_FILTER_SET(filter, FMGR_TYPE_JPG);
    FMGR_FILTER_SET(filter, FMGR_TYPE_JPEG);
#endif
#ifdef SVG_SUPPORT
    FMGR_FILTER_SET(filter, FMGR_TYPE_SVG);
#endif 

    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER_DOT);
}

/*****************************************************************************
 * FUNCTION
 *  mma_uc_set_file_mgr_filter_for_image_restricted
 * DESCRIPTION
 *  Set the image filter
 * PARAMETERS
 *  filter        [OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_uc_set_file_mgr_filter_for_image_restricted(FMGR_FILTER* filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(filter);
    
    switch(wap_get_mms_content_class())
    {
    
    case WAP_MMS_CONTENT_CLASS_VIDEO_RICH:
    case WAP_MMS_CONTENT_CLASS_VIDEO_BASIC:
    case WAP_MMS_CONTENT_CLASS_IMAGE_RICH:
    case WAP_MMS_CONTENT_CLASS_IMAGE_BASIC:
        FMGR_FILTER_SET(filter, FMGR_TYPE_GIF);
        FMGR_FILTER_SET(filter, FMGR_TYPE_WBMP);
        FMGR_FILTER_SET(filter, FMGR_TYPE_WBM);
#ifdef JPG_DECODE
        FMGR_FILTER_SET(filter, FMGR_TYPE_JPG);
        FMGR_FILTER_SET(filter, FMGR_TYPE_JPEG);
#endif
        break;
    }
    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER_DOT);
}

/*****************************************************************************
 * FUNCTION
 *  mma_uc_set_file_mgr_filter_for_audio
 * DESCRIPTION
 *  Set the audio filter
 * PARAMETERS
 *  filter        [OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_uc_set_file_mgr_filter_for_audio(FMGR_FILTER* filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(filter);
    
    FMGR_FILTER_SET(filter, FMGR_TYPE_IMY);
    FMGR_FILTER_SET(filter, FMGR_TYPE_MID);
    FMGR_FILTER_SET(filter, FMGR_TYPE_MIDI);
    FMGR_FILTER_SET(filter, FMGR_TYPE_WAV);
    FMGR_FILTER_SET(filter, FMGR_TYPE_AMR);
    FMGR_FILTER_SET(filter, FMGR_TYPE_VM);
#ifdef AAC_DECODE
    FMGR_FILTER_SET(filter, FMGR_TYPE_AAC);
#endif 
#ifdef DAF_DECODE
    FMGR_FILTER_SET(filter, FMGR_TYPE_DAF);
#endif 
#ifdef AMRWB_DECODE
    FMGR_FILTER_SET(filter, FMGR_TYPE_AWB);
#endif 
#ifndef MT6205B
    FMGR_FILTER_SET(filter, FMGR_TYPE_AIF);
    FMGR_FILTER_SET(filter, FMGR_TYPE_AIFF);
    FMGR_FILTER_SET(filter, FMGR_TYPE_AIFC);
    FMGR_FILTER_SET(filter, FMGR_TYPE_AU);
    FMGR_FILTER_SET(filter, FMGR_TYPE_SND);
#endif
#if defined(MP4_CODEC) && defined(AAC_DECODE)
    FMGR_FILTER_SET(filter, FMGR_TYPE_M4A);
#endif 
#if defined(EXT_AUDIO_CHIP) || defined(MMF_DECODE)
    FMGR_FILTER_SET(filter, FMGR_TYPE_MMF);
#endif 
#ifdef WMA_DECODE
    FMGR_FILTER_SET(filter, FMGR_TYPE_WMA);
#endif 
#ifdef MUSICAM_DECODE
    FMGR_FILTER_SET(filter, FMGR_TYPE_MP2);
#endif  

    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER_DOT);
}

/*****************************************************************************
 * FUNCTION
 *  mma_uc_set_file_mgr_filter_for_audio_restricted
 * DESCRIPTION
 *  Set the audio filter
 * PARAMETERS
 *  filter        [OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_uc_set_file_mgr_filter_for_audio_restricted(FMGR_FILTER* filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(filter);
    
    switch(wap_get_mms_content_class())
    {
    case WAP_MMS_CONTENT_CLASS_VIDEO_RICH:
    case WAP_MMS_CONTENT_CLASS_VIDEO_BASIC:
    case WAP_MMS_CONTENT_CLASS_IMAGE_RICH:
        FMGR_FILTER_SET(filter, FMGR_TYPE_MID);
        FMGR_FILTER_SET(filter, FMGR_TYPE_MIDI);
    
    case WAP_MMS_CONTENT_CLASS_IMAGE_BASIC:
        FMGR_FILTER_SET(filter, FMGR_TYPE_AMR);
        break;
    }
    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER_DOT);
}

/*****************************************************************************
 * FUNCTION
 *  mma_uc_set_file_mgr_filter_for_video
 * DESCRIPTION
 *  Set the video filter
 * PARAMETERS
 *  filter        [OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_uc_set_file_mgr_filter_for_video(FMGR_FILTER* filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(filter);

#ifdef MP4_CODEC
    FMGR_FILTER_SET(filter, FMGR_TYPE_3GP);
    FMGR_FILTER_SET(filter, FMGR_TYPE_MP4);
    FMGR_FILTER_SET(filter, FMGR_TYPE_3G2);
#endif 
#ifdef MJPG_SUPPORT
    FMGR_FILTER_SET(filter, FMGR_TYPE_AVI);
#endif 

    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER_DOT);
}

/*****************************************************************************
 * FUNCTION
 *  mma_uc_set_file_mgr_filter_for_video_restricted
 * DESCRIPTION
 *  Set the video filter
 * PARAMETERS
 *  filter        [OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_uc_set_file_mgr_filter_for_video_restricted(FMGR_FILTER* filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(filter);
    
    switch(wap_get_mms_content_class())
    {
    case WAP_MMS_CONTENT_CLASS_VIDEO_RICH:
    case WAP_MMS_CONTENT_CLASS_VIDEO_BASIC:
#ifdef MP4_CODEC
        FMGR_FILTER_SET(filter, FMGR_TYPE_3GP);
        FMGR_FILTER_SET(filter, FMGR_TYPE_MP4);
        FMGR_FILTER_SET(filter, FMGR_TYPE_3G2);
#endif 
    
    case WAP_MMS_CONTENT_CLASS_IMAGE_RICH:
    case WAP_MMS_CONTENT_CLASS_IMAGE_BASIC:
        break;
    }
    
    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER_DOT);
}

/*****************************************************************************
 * FUNCTION
 *  mma_uc_set_file_mgr_filter_for_attachment
 * DESCRIPTION
 *  Set the attachment filter
 * PARAMETERS
 *  filter        [OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_uc_set_file_mgr_filter_for_attachment(FMGR_FILTER* filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 count = 0, index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	FMGR_FILTER_INIT(filter);

    FMGR_FILTER_SET_ALL(filter);
    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER_DOT);
    FMGR_FILTER_CLEAR(filter, FMGR_TYPE_DM);
}

/*****************************************************************************
 * FUNCTION
 *  mma_uc_set_file_mgr_filter_for_attachment_restricted
 * DESCRIPTION
 *  Set the attachment filter
 * PARAMETERS
 *  filter        [OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_uc_set_file_mgr_filter_for_attachment_restricted(FMGR_FILTER* filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(filter);
    
    switch(wap_get_mms_content_class())
    {
    case WAP_MMS_CONTENT_CLASS_VIDEO_RICH:
    case WAP_MMS_CONTENT_CLASS_VIDEO_BASIC:
#ifdef MP4_CODEC
        FMGR_FILTER_SET(filter, FMGR_TYPE_3GP);
        FMGR_FILTER_SET(filter, FMGR_TYPE_MP4);
        FMGR_FILTER_SET(filter, FMGR_TYPE_3G2);
#endif 

    case WAP_MMS_CONTENT_CLASS_IMAGE_RICH:
        FMGR_FILTER_SET(filter, FMGR_TYPE_MID);
        FMGR_FILTER_SET(filter, FMGR_TYPE_MIDI);

    case WAP_MMS_CONTENT_CLASS_IMAGE_BASIC:
#ifdef __MMI_EBOOK_READER__
        FMGR_FILTER_SET(filter, FMGR_TYPE_EBOOK_TXT);
#endif
        FMGR_FILTER_SET(filter, FMGR_TYPE_GIF);
        FMGR_FILTER_SET(filter, FMGR_TYPE_WBMP);
        FMGR_FILTER_SET(filter, FMGR_TYPE_WBM);
#ifdef JPG_DECODE
        FMGR_FILTER_SET(filter, FMGR_TYPE_JPG);
        FMGR_FILTER_SET(filter, FMGR_TYPE_JPEG);
#endif
        FMGR_FILTER_SET(filter, FMGR_TYPE_AMR);
        break;
    }

    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER_DOT);
}

/*****************************************************************************
 * FUNCTION
 *  mma_uc_set_file_mgr_filter
 * DESCRIPTION
 *  Get free file space
 * PARAMETERS
 *  void
 * RETURNS
 *  free space
 *****************************************************************************/
void mma_uc_set_file_mgr_filter(void* filter, mma_uc_filter_mode_enum media_type_to_insert)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
	switch(media_type_to_insert)
	{
		case MMA_UC_FILTER_MODE_IMAGE_OPEN_MODE:
			mma_uc_set_file_mgr_filter_for_image((FMGR_FILTER *)filter);
			break;
		
		case MMA_UC_FILTER_MODE_IMAGE_RESTRICTED_MODE:
			mma_uc_set_file_mgr_filter_for_image_restricted((FMGR_FILTER *)filter);
			break;

		case MMA_UC_FILTER_MODE_AUDIO_OPEN_MODE:
			mma_uc_set_file_mgr_filter_for_audio((FMGR_FILTER *)filter);
			break;

		case MMA_UC_FILTER_MODE_AUDIO_RESTRICTED_MODE:
			mma_uc_set_file_mgr_filter_for_audio_restricted((FMGR_FILTER *)filter);
			break;

		case MMA_UC_FILTER_MODE_VIDEO_OPEN_MODE:
			mma_uc_set_file_mgr_filter_for_video((FMGR_FILTER *)filter);
			break;

		case MMA_UC_FILTER_MODE_VIDEO_RESTRICTED_MODE:
			mma_uc_set_file_mgr_filter_for_video_restricted((FMGR_FILTER *)filter);
			break;

		case MMA_UC_FILTER_MODE_ATTACHMENT_OPEN_MODE:
			mma_uc_set_file_mgr_filter_for_attachment((FMGR_FILTER *)filter);
			break;

		case MMA_UC_FILTER_MODE_ATTACHMENT_RESTRICTED_MODE:
			mma_uc_set_file_mgr_filter_for_attachment_restricted((FMGR_FILTER *)filter);
			break;

		case MMA_UC_FILTER_MODE_TEXT_OPEN_MODE:
		case MMA_UC_FILTER_MODE_TEXT_RESTRICTED_MODE:
			break;
	}
	
	return;
}

/*****************************************************************************
 * FUNCTION
 *  mma_uc_calc_object_multipart_header_size
 * DESCRIPTION
 *  Calculate multipart header size including
 *  - Headers: ContentType
 *    * general form (Value-length, Media-type(value/string), Parameter(charset(only text, smil), Name))
 *  - Headers: Content Location, Content ID
 * PARAMETERS
 *  filename      [IN]        UTF8 encoding
 * RETURNS
 *  size in bytes
 *****************************************************************************/
static kal_uint32 mma_uc_calc_object_multipart_header_size(const char *filename)
{
        kal_uint32 hd_size = 0, ct_size = 0;
        const char *mime = NULL;
        MmsKnownMediaType type = MMS_VALUE_AS_STRING;
        kal_bool is_smil = KAL_FALSE;

        ASSERT(filename != NULL);
        mime = mma_get_mime_type_from_filename(filename);
        is_smil = (strcmp(MMS_MEDIA_TYPE_STRING_SMIL, mime) == 0);
        
        /* ContentType */
        /* Media-type */
        if((type = mma_get_mmsKnownMediaType_from_mime_type(mime)) != MMS_VALUE_AS_STRING)
        {
            ct_size += 1;  /* value */
        }
        else
        {
            ct_size += (strlen(mime) + 1);  /* string */
        }
    
        /* Parameter Charset */
        if(type == MMS_TYPE_TEXT_PLAIN || is_smil)
        {
            ct_size += 2;  /* 0x81 0x?? */
        }
    
        /* Parameter Name */
        ct_size += (strlen(filename) + 2);  /* 0x85 + [name] + '\0'*/

        /* Value-length */
        ct_size += len_value_length(ct_size);
        hd_size += ct_size;

        /* Content Location: 0x8e + [name] + '\0'*/
        hd_size += (strlen(filename) + 2);
        
        /* Content ID: 0xc0 + '"' + '<' + [name] + '>' + '\0'*/
        if (is_smil)
        {
            hd_size += (strlen(MEAlib_getSmilContentId()) + 5);
        }
        else
        {
            hd_size += (strlen(filename) + 5);
        }

        /* HeadersLen */
        hd_size += len_uintvar(hd_size);

        return hd_size;
}

/*****************************************************************************
 * FUNCTION
 *  wap_mma_uc_calc_header_attribute_size
 * DESCRIPTION
 *  Calculate MMS header to/cc/bcc/subject field length
 * PARAMETERS
 *  attr      [IN]
 *  data      [IN]
 * RETURNS
 *  size in bytes
 *****************************************************************************/
kal_uint32 wap_mma_uc_calc_header_attribute_size(mma_header_attr_enum attr, const kal_wchar *data)
{
    kal_uint32 i = 0, size = 0;
    char *utf8_data = NULL;
    MmsCharset charset = MMS_US_ASCII;
    
    switch (attr)
    {
    case MMA_HEADER_ADDRESS:
        if (IS_EMAIL((char *)data))
        {
            utf8_data = ucs2_to_utf8_string((kal_uint8 *)data);  /* work fine for ascii */
            size = strlen(utf8_data) + 2;  /* 0x97 + [Email] + '\0' */
        }
        else
        {
            /* UC use ASCII string to save phone number */
            size = strlen((char *)data) + strlen("/TYPE=PLMN") + 2;  /* 0x97 + [#]/TYPE=PLMN + '\0' */
        }
        break;
        
    case MMA_HEADER_SUBJECT:
        utf8_data = ucs2_to_utf8_string((kal_uint8 *)data);  /* work fine for ascii */
        for (i = 0; *(utf8_data + i) != '\0'; i++)
        {
            if ((unsigned char)*(utf8_data + i) > 0x7F)
            {
                charset = MMS_UTF8;
            }
        }

        if(charset == MMS_US_ASCII)
        {
            size = strlen(utf8_data) + 2;  /* 0x96 + [Subject] + '\0' */
        }
        else
        {
            size += (strlen(utf8_data) + 3);  /* 0x96 + 0xea + [Subject] + '\0' */
            size = ((unsigned char)*utf8_data > 0x7F) ? (size + 1) : size;  /* 0x96 + 0xea + (0x7F) + [Subject] + '\0'*/

            /* Value-length */
            size += len_value_length(size);  /* 0x96 + value-length + 0xea + (0x7F) + [Subject] + '\0'*/
        }
        break;
        
    default:
        ASSERT(0);
    }

    MSF_MEM_FREE(MSF_MODID_MMA, utf8_data);
    return size;  
}

/*****************************************************************************
 * FUNCTION
 *  wap_mma_uc_calc_header_size
 * DESCRIPTION
 *  Calculate MMS header size including
 *  - X-Mms-Message-Type: 8C 80
 *  - X-Mms-Transaction-Id: 98 XX XX XX XX XX XX XX XX XX XX 00  (possible longest length)
 *  - X-Mms-MMS_Version: 8D 9X
 *  - Date: 85 04 XX XX XX XX  (possible longest length)
 *  - From: 89 01 81
 *  - To: wap_mma_uc_calc_header_attribute_size()
 *  - Cc: wap_mma_uc_calc_header_attribute_size()
 *  - Bcc: wap_mma_uc_calc_header_attribute_size()
 *  - Subject: wap_mma_uc_calc_header_attribute_size()
 *  - X-Mms-Expiry: 88 [Value-Length] 81 [Short-length] XX XX (XX)
 *  - X-Mms-Delivery-Time: 87 [Value-Length:05] 81 [Short-length:03] 01 51 80  (approximate: use 1 day as delivery time)
 *  - X-Mms-Priority: 8F 8X
 *  - X-Mms-Delivery-Report: 86 8X 
 *  - X-Mms-Read-Report: 90 8X 
 *  - Content-type: 84  [Value-Length:1D] B3 89 [MMS_MEDIA_TYPE_STRING_SMIL: application/smil] 00 8A 3C [MEAlib_getSmilContentId()] 3E 00
 *  - nEntries: [uintvar]
 * PARAMETERS
 *  mms      [IN]        
 * RETURNS
 *  size in bytes
 *****************************************************************************/
kal_uint32 wap_mma_uc_calc_header_size(const mmi_uc_msg_struct *mms)
{
    kal_uint32 size = 0, tmp_size = 0;
    mmi_uc_addr_struct *addr = NULL;

    /* X-Mms-Message-Type ~ From*/
    size = 2 + 12 + 2 + 6 + 3;

    /* To */
    addr = mms->to_head;
    while (addr)
    {
        size += wap_mma_uc_calc_header_attribute_size(MMA_HEADER_ADDRESS, (kal_wchar *)addr->addr);
        addr = addr->next;
    }
 
    /* Cc */
    addr = mms->cc_head;
    while (addr)
    {
        size += wap_mma_uc_calc_header_attribute_size(MMA_HEADER_ADDRESS, (kal_wchar *)addr->addr);
        addr = addr->next;
    }
    
    /* Bcc */
    addr = mms->bcc_head;
    while (addr)
    {
        size += wap_mma_uc_calc_header_attribute_size(MMA_HEADER_ADDRESS, (kal_wchar *)addr->addr);
        addr = addr->next;
    }

    /* Subject */
    size += wap_mma_uc_calc_header_attribute_size(MMA_HEADER_SUBJECT, (kal_wchar *)mms->subject);

    /* X-Mms-Expiry */
    switch (mms->expiry_time)
    {
    case MMA_EXPIRY_NOT_SET:
        break;
    case MMA_EXPIRY_1_HOUR:
        size += 6;  /* 88 [Value-Length:04] 81 [Short-length:02] XX XX */
    case MMA_EXPIRY_12_HOURS:
        size += 6;
    case MMA_EXPIRY_1_DAY:
        size += 7;  /* 88 [Value-Length:05] 81 [Short-length:03] XX XX XX */
    case MMA_EXPIRY_1_WEEK:
        size += 7;
    case MMA_EXPIRY_MAX:
        break;
    }

    /* X-Mms-Delivery-Time */
    switch (mms->delivery_time)
    {
    case MMA_DELIVERY_NOT_SET:
    case MMA_DELIVERY_IMMEDIATE:
        break;
    case MMA_DELIVERY_1_HOUR:
        size += 6;  /* 87 [Value-Length:04] 81 [Short-length:02] XX XX */
    case MMA_DELIVERY_12_HOURS:
        size += 6;  /* 87 [Value-Length:04] 81 [Short-length:02] XX XX */
    case MMA_DELIVERY_24_HOURS:
        size += 7;  /* 87 [Value-Length:05] 81 [Short-length:03] XX XX XX */
    }

    /* X-Mms-Priority ~ X-Mms-Read-Report */
    size += (2 + 2 + 2);

    /* Content-type */
    tmp_size = 5 + strlen(MMS_MEDIA_TYPE_STRING_SMIL)  + strlen(MEAlib_getSmilContentId()) +  strlen("<>");
    size +=  (1 + len_uintvar(tmp_size) + tmp_size);

    /* nEntries */
    size += len_uintvar(mms->total_object_num + 1);  /* add SMIL part */

    return size;
}

/*****************************************************************************
 * FUNCTION
 *  wap_mma_uc_calc_slide_smil_size
 * DESCRIPTION
 *  This function is to calculate SMIL description size for slide (<par ...></par>)
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  smil description size
 *****************************************************************************/
kal_uint32 wap_mma_uc_calc_slide_smil_size(kal_uint32 sec)
{
    kal_uint32 size = 0, buffer_len = 0;
    char *buffer = NULL, *tmp = NULL;
    char str[8];

    sprintf(str, "%d", (int)sec * MMA_1_SEC_IN_MSEC);
    buffer_len = strlen(SLS_PAR_START) + strlen(SLS_PAR_END) + strlen(str) + 1;  
    tmp = MSF_MEM_ALLOC(MSF_MODID_MMA, buffer_len);
    buffer = MSF_MEM_ALLOC(MSF_MODID_MMA, buffer_len);
    sprintf(tmp, SLS_PAR_START, (int)sec * MMA_1_SEC_IN_MSEC);  /* <par dur="?000ms"> */
    strcpy(buffer, tmp);
    strcat(buffer, SLS_PAR_END);  /* </par> */
    size = strlen(buffer);

    MSF_MEM_FREE(MSF_MODID_MMA, tmp);
    MSF_MEM_FREE(MSF_MODID_MMA, buffer);
    return size;
}

/*****************************************************************************
 * FUNCTION
 *  wap_mma_uc_calc_msg_size
 * DESCRIPTION
 *  This function is to 
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint32 wap_mma_uc_calc_msg_size(const mmi_uc_msg_struct *mms)  /* including SMIL size */
{
    kal_uint32 size = 0, smil_size = 0;
    char buffer[8];
    mmi_uc_slide_struct *slide = NULL;
    mmi_uc_object_struct *obj = NULL;

    size = wap_mma_uc_calc_header_size(mms);

    /* SMIL multipart header*/
    size += mma_uc_calc_object_multipart_header_size(MEAlib_getSmilFileName());

    /* SMIL body */
    smil_size = strlen(SLS_SMIL_START) + strlen(SLS_SMIL_END) + strlen(SLS_HEAD_START) 
    + strlen(SLS_HEAD_END) + strlen(SLS_BODY_START) + strlen(SLS_BODY_END) 
    + strlen(SLS_LAYOUT_START) + strlen(SLS_LAYOUT_END);
    
    /* SMIL body: <root-layout width="XXX" height="XXX"/> */
    smil_size += (strlen(SLS_ROOT_LAYOUT_T1) + strlen(SLS_ROOT_LAYOUT_T2) + 
        strlen(SLS_ROOT_LAYOUT_T4));
    sprintf(buffer, "%d", MEAlib_getDisplayWidth());
    smil_size += strlen(buffer);
    sprintf(buffer, "%d", MEAlib_getDisplayHeight());
    smil_size += strlen(buffer);
    smil_size += strlen(SLS_ROOT_LAYOUT_T3);
    sprintf(buffer, "%.6x", MEAlib_getDefaultSmilBgColor());    
    smil_size += strlen(buffer)+1;

    /* SMIL body: <region id="XXX" width="XX%" height="XX%" left="XX%" top="XX%" /> */
    smil_size += 2 * (strlen(SLS_REGION_T1) + strlen(SLS_REGION_T2) + strlen(SLS_REGION_T3) +
        strlen(SLS_REGION_T4) + strlen(SLS_REGION_T5) + strlen(SLS_REGION_T6) + strlen(SLS_REGION_T7)) + 
        strlen(SLS_FIT_MEET) + strlen(SLS_FIT_SCROLL);
    smil_size += (strlen(MEAlib_getSmilImageRegionName()) + strlen(MEAlib_getSmilTextRegionName()));
    smil_size += 4* strlen("100%");  /* May not precise: +1 byte */
    smil_size += 4* strlen("0%");

    /* SMIL body: slide info */
    slide = mms->slide_head;
    while (slide)
    {
        smil_size += wap_mma_uc_calc_slide_smil_size(slide->duration);
        slide = slide->next;
    }
    
    obj = mms->object_head;
    while (obj)
    {
        switch (obj->type)
        {
        case MMI_UC_OBJECT_TYPE_IMAGE:
            smil_size += wap_mma_uc_calc_object_smil_size(MMA_INSERT_IMAGE, obj->file_path);
            break;
        case MMI_UC_OBJECT_TYPE_AUDIO:
            smil_size += wap_mma_uc_calc_object_smil_size(MMA_INSERT_AUDIO, obj->file_path);
            break;
        case MMI_UC_OBJECT_TYPE_VIDEO:
            smil_size += wap_mma_uc_calc_object_smil_size(MMA_INSERT_VIDEO, obj->file_path);
            break;
        case MMI_UC_OBJECT_TYPE_TEXT:
            smil_size += wap_mma_uc_calc_object_smil_size(MMA_INSERT_TEXT, obj->file_path);
            break;
        }
        obj = obj->next;
    }

    size += smil_size;

    /* SMIL multipart header: DataLen */
    size += len_uintvar(smil_size);
    
    /* multipart excepts SMIL, refer to  wap_mma_uc_calc_object_multipart_size() */
    obj = mms->object_head;
    while(obj)
    {
        char *utf8_filename = NULL;
    
        utf8_filename = ucs2_to_utf8_string((kal_uint8 *)obj->file_name);
        /* DataLen */
        size += len_uintvar(obj->size);
    
        /* HeadersLen, Headers */
        size += mma_uc_calc_object_multipart_header_size((const char *)utf8_filename);
        
        /* body */
        size += obj->size;

        obj = obj->next;
        MSF_MEM_FREE(MSF_MODID_MMA, utf8_filename);
    }

    return size;
}

/*****************************************************************************
 * FUNCTION
 *  wap_mma_uc_calc_object_multipart_size
 * DESCRIPTION
 *  Calculate multipart size including
 *  - header: 
 *    + HeadersLen, Headers: mma_uc_calc_object_multipart_header_size()
 *    + DataLen
 *  - body:
 * PARAMETERS
 *  filepath      [IN]        UCS2 encoding
 * RETURNS
 *  size in bytes
 *****************************************************************************/
kal_uint32 wap_mma_uc_calc_object_multipart_size(const kal_wchar *filepath)
{
    kal_uint32 size = 0, filesize = mma_get_mmi_file_size(filepath);
    char *utf8_filepath = NULL;
    const char *utf8_filename = NULL;

    /* DataLen */
    size += len_uintvar(filesize);

    utf8_filepath = ucs2_to_utf8_string((kal_uint8 *)filepath);
    utf8_filename = mma_get_name_from_path(utf8_filepath);

    /* HeadersLen, Headers */
    size += mma_uc_calc_object_multipart_header_size(utf8_filename);
    
    /* body */
    size += filesize;
    
    MSF_MEM_FREE(MSF_MODID_MMA, utf8_filepath);
    return size;
}

/*****************************************************************************
 * FUNCTION
 *  wap_mma_uc_calc_object_smil_size
 * DESCRIPTION
 *  Calculate SMIL description length (begin, end, dur, alt parameters are not supported)
 * PARAMETERS
 *  type      [IN]
 *  filepath  [IN]
 * RETURNS
 *  size in bytes
 *****************************************************************************/
kal_uint32 wap_mma_uc_calc_object_smil_size(mma_insert_type_enum type, const kal_wchar *filepath)
{
    kal_uint32 size = 0, buffer_len = 0;
    char *utf8_filepath = NULL, *buffer = NULL, *tmp = NULL;
    const char *utf8_filename = NULL, *t_region_name = NULL, *i_region_name = NULL;

    if (type != MMA_INSERT_ATTACHMENT)
    {
        utf8_filepath = ucs2_to_utf8_string((kal_uint8 *)filepath);
        utf8_filename = mma_get_name_from_path(utf8_filepath);
    
        t_region_name = MEAlib_getSmilTextRegionName();
        i_region_name = MEAlib_getSmilImageRegionName();
    }
    
    switch(type)
    {
    case MMA_INSERT_TEXT:
    {
        char str[8];
        buffer_len = strlen(SLS_TEXT_T1) + strlen(SLS_TEXT_T4) + strlen(SLS_TEXT_T6) + strlen(utf8_filename) + 
            strlen(t_region_name) + strlen(COLOR_RGB_STR) + 1;
        tmp = MSF_MEM_ALLOC(MSF_MODID_MMA, buffer_len);
        buffer = MSF_MEM_ALLOC(MSF_MODID_MMA, buffer_len);
        sprintf(tmp, SLS_TEXT_T1, utf8_filename, t_region_name);  /* <text src="??.??" region="Text" */
        strcpy(buffer, tmp);
        strcat(buffer, SLS_TEXT_T6);  /* > */
        sprintf(str, "#%6x", MEAlib_getDefaultSmilFgColor());  /* #RRGGBB */
        sprintf(tmp, SLS_TEXT_T4, str);  /* <param name="foregroundcolor" value="#RRGGBB" /></text>*/
        strcat(buffer, tmp);
        size = strlen(buffer);
        break;
    }
    
    case MMA_INSERT_IMAGE:
        buffer_len = strlen(SLS_IMAGE_T1) + strlen(SLS_IMAGE_T4) + strlen(utf8_filename) + strlen(i_region_name) + 1;
        tmp = MSF_MEM_ALLOC(MSF_MODID_MMA, buffer_len);
        buffer = MSF_MEM_ALLOC(MSF_MODID_MMA, buffer_len);
        sprintf(tmp, SLS_IMAGE_T1, utf8_filename, i_region_name);  /* <img src="??.??" region="Image" */
        strcpy(buffer, tmp);
        strcat(buffer, SLS_IMAGE_T4);  /* /> */
        size = strlen(buffer);
        break;
        
    case MMA_INSERT_AUDIO:
        buffer_len = strlen(SLS_AUDIO_T1) + strlen(SLS_AUDIO_T4) + strlen(utf8_filename) + 1;
        tmp = MSF_MEM_ALLOC(MSF_MODID_MMA, buffer_len);
        buffer = MSF_MEM_ALLOC(MSF_MODID_MMA, buffer_len);
        sprintf(tmp, SLS_AUDIO_T1, utf8_filename);  /* <audio src="??.??" /> */
        strcpy(buffer, tmp);
        strcat(buffer, SLS_AUDIO_T4);  /* /> */
        size = strlen(buffer);
        break;

    case MMA_INSERT_VIDEO:
        buffer_len = strlen(SLS_VIDEO_T1) + strlen(SLS_VIDEO_T4) + strlen(utf8_filename) + strlen(i_region_name) + 1;
        tmp = MSF_MEM_ALLOC(MSF_MODID_MMA, buffer_len);
        buffer = MSF_MEM_ALLOC(MSF_MODID_MMA, buffer_len);
        sprintf(tmp, SLS_VIDEO_T1, utf8_filename, i_region_name);  /* <video src="??.??" region="Image" */
        strcpy(buffer, tmp);
        strcat(buffer, SLS_VIDEO_T4);  /* /> */
        size = strlen(buffer);
        break;

    case MMA_INSERT_ATTACHMENT:
        size = 0;
        break;
        
    default:
        ASSERT(0);
    }

    MSF_MEM_FREE(MSF_MODID_MMA, tmp);
    MSF_MEM_FREE(MSF_MODID_MMA, buffer);
    MSF_MEM_FREE(MSF_MODID_MMA, utf8_filepath);
    return size;
}

void wap_mma_uc_insert_object_check(mma_creation_mode_enum creation_mode, const kal_wchar *filepath, 
    mma_insert_type_enum type, kal_uint32 current_msg_size, kal_uint32 max_msg_size, mma_insert_check_struct *info)
{
    kal_uint32 add_size = 0;
    const char *mime = NULL;
    char *utf8_filepath = NULL;
    char *utf8_filepath_ext = NULL;
    mma_drm_method_enum drmMethod = MMA_DRM_METHOD_NONE;

    utf8_filepath = ucs2_to_utf8_string((kal_uint8 *)filepath);
    utf8_filepath_ext = msf_cmmn_strcat(MSF_MODID_MMA, HDI_EXTERNAL_PATH, utf8_filepath);
    info->result = KAL_TRUE;

    if ((mime = mma_get_mime_type_from_filename(utf8_filepath)) == NULL)
    {
        info->result = KAL_FALSE;
        goto check_end;
    }

    if (type == MMA_INSERT_UNKNOWN)
    {
        if (mma_conf_get_creation_mode() == MMA_CREATION_MODE_FREE)
        {
            if (strstr(MMA_OPEN_TEXT_TYPES, mime))
            {
                type = MMA_INSERT_TEXT;
            }
            else if (strstr(MMA_OPEN_IMAGE_TYPES, mime))
            {
                type = MMA_INSERT_IMAGE;
            }
            else if (strstr(MMA_OPEN_AUDIO_TYPES, mime))
            {
                type = MMA_INSERT_AUDIO;
            }
            else if (strstr(MMA_OPEN_VIDEO_TYPES, mime))
            {
                type = MMA_INSERT_VIDEO;
            }
            else if (strstr(MMA_OPEN_ATTACHMENT_TYPES, mime))
            {
                type = MMA_INSERT_ATTACHMENT;
            }
            else
            {
                info->result = KAL_FALSE;
                goto check_end;
            }
        }
        else
        {
            if (strstr(MMA_OPEN_RESTRICTED_TEXT_TYPES, mime))
            {
                type = MMA_INSERT_TEXT;
            }
            else if (strstr(MMA_OPEN_RESTRICTED_IMAGE_TYPES, mime))
            {
                type = MMA_INSERT_IMAGE;
            }
            else if (strstr(MMA_OPEN_RESTRICTED_AUDIO_TYPES, mime))
            {
                type = MMA_INSERT_AUDIO;
            }
            else if (strstr(MMA_OPEN_RESTRICTED_VIDEO_TYPES, mime))
            {
                type = MMA_INSERT_VIDEO;
            }
            else if (strstr(MMA_OPEN_RESTRICTED_ATTACHMENT_TYPES, mime))
            {
                type = MMA_INSERT_ATTACHMENT;
            }
            else
            {
                info->result = KAL_FALSE;
                info->creation_mode_violate = KAL_TRUE;
                goto check_end;
            }
        }
        
        info->insert_type = type;  /* ? */
    }
    
    switch(type)
    {
    case MMA_INSERT_TEXT:
        add_size = wap_mma_uc_calc_object_multipart_size(filepath);
        add_size += wap_mma_uc_calc_object_smil_size(MMA_INSERT_TEXT, filepath);
        break;
    case MMA_INSERT_IMAGE:
        add_size = wap_mma_uc_calc_object_multipart_size(filepath);
        add_size += wap_mma_uc_calc_object_smil_size(MMA_INSERT_IMAGE, filepath);
        break;
    case MMA_INSERT_AUDIO:
        add_size = wap_mma_uc_calc_object_multipart_size(filepath);
        add_size += wap_mma_uc_calc_object_smil_size(MMA_INSERT_AUDIO, filepath);
        break;
    case MMA_INSERT_VIDEO:
        add_size = wap_mma_uc_calc_object_multipart_size(filepath);
        add_size += wap_mma_uc_calc_object_smil_size(MMA_INSERT_VIDEO, filepath);
        break;
    case MMA_INSERT_ATTACHMENT:
        add_size = wap_mma_uc_calc_object_multipart_size(filepath);
        break;
    default:
        ASSERT(0);
    }

    /* size check */
    if (current_msg_size + add_size > max_msg_size)
    {
        info->result = KAL_FALSE;
        info->oversize = KAL_TRUE;
        goto check_end;
    }
    else if (mma_get_mmi_file_size(filepath) == 0)
    {
        info->result = KAL_FALSE;
        goto check_end;
    }
    else
    {
        info->oversize = KAL_FALSE;
    }

    /* creation mode check */
    if (mma_conf_get_creation_mode() == MMA_CREATION_MODE_FREE)
    {
        info->creation_mode_violate = KAL_FALSE;
    }
    else
    {
        if (mma_is_restricted_type(utf8_filepath_ext))
        {
            info->creation_mode_violate = KAL_FALSE;
        }
        else
        {
            info->result = KAL_FALSE;
            info->creation_mode_violate = KAL_TRUE;
            goto check_end;
        }
    }

#ifdef __DRM_SUPPORT__
    /* DRM check */
    drmMethod = mma_drm_get_method_type(utf8_filepath_ext);
    if (drmMethod == MMA_DRM_METHOD_NONE)
    {
        info->drm_type = MMA_DRM_NONE;
    }
    else if (drmMethod == MMA_DRM_METHOD_FORWARD_LOCK || drmMethod == MMA_DRM_METHOD_COMBINED_DELIVERY)
    {
        info->result = KAL_FALSE;
        info->drm_type = MMA_DRM_FL_CD;
        goto check_end;
    }
    else
    {
        if (mma_drm_check_right(utf8_filepath_ext) == KAL_TRUE)
        {
            info->drm_type = MMA_DRM_SD;
        }
        else
        {
            info->drm_type = MMA_DRM_SD_NO_RIGHT;
        }
    }
#else
    info->drm_type = MMA_DRM_NONE;
#endif

    /* sanity check */
    switch(type)
    {
    case MMA_INSERT_IMAGE:
        if (drmMethod == MMA_DRM_METHOD_NONE && HDIa_widgetExtCheckImageFile((char *)filepath) == KAL_FALSE)
        {
            info->result = KAL_FALSE;
            goto check_end;
        }
        break;
    default:
        break;
    }


check_end:    
    MSF_MEM_FREE(MSF_MODID_MMA, utf8_filepath);
    MSF_MEM_FREE(MSF_MODID_MMA, utf8_filepath_ext);
    return;
}

mma_folder_enum wap_mma_get_box(kal_uint32 msg_id)
{
    MmsFolderType folder = fldrGetFolderId((MSF_UINT32)msg_id);
    return wap_translate_mms_folder_2_mma_folder(folder);
}

/*****************************************************************************
 * FUNCTION
 *  wap_mma_get_request_id
 * DESCRIPTION
 *  Get non-zero request id for issuing a request. 
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 wap_mma_get_request_id(void)
{
    if(req_id + 1 == 0)
    {
        ++req_id;
    }
    return ++req_id;
}

/*****************************************************************************
 * FUNCTION
 *  mma_compare_request_id
 * DESCRIPTION
 *  Get earlier request id 
 * PARAMETERS
 *  id1      [IN]
 *  id2      [IN]
 * RETURNS
 *  Earlier request id
 *****************************************************************************/
kal_uint32 mma_compare_request_id(kal_uint32 id1, kal_uint32 id2)
{
    if(id1 == id2) return id1;
    
    if((req_id > id1 && req_id > id2) || (req_id < id1 && req_id < id2))
    {
        return (id1 < id2)? id1 : id2;
    }
    else if(req_id < id1 && req_id > id2)  /* wrap around */
    {
        return id1;
    }
    else  /* wrap around : req_id > id1 && req_id < id2 */
    {
        return id2;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mma_get_mmi_file_size
 * DESCRIPTION
 *  Get file size by using MMI UCS2 filename
 * PARAMETERS
 *  filepath      [IN]
 * RETURNS
 *  file size
 *****************************************************************************/
kal_uint32 mma_get_mmi_file_size(const kal_wchar *filepath)
{
    kal_int32 file_handle;
    kal_uint32 size = 0;
    
    file_handle = FS_Open((WCHAR*)filepath, FS_READ_ONLY);
    if(file_handle >= 0)
    {
        if(FS_GetFileSize(file_handle, &size) != FS_NO_ERROR)
        {
            ASSERT(0);
        }
    }
    else
    {
        return 0;
    }
    FS_Close(file_handle);
    return size;
}
#endif /* __UNIFIED_COMPOSER_SUPPORT__ */
