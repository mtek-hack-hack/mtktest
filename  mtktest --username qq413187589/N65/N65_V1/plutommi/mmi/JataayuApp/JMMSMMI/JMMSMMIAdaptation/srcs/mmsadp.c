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
#include "MMI_include.h"
#ifdef __UNIFIED_COMPOSER_SUPPORT__

#include "wap_ps_struct.h"
#include "lcd_sw_rnd.h"
#include "lcd_sw_inc.h"
#include "fmt_def.h"
#include "wapadp.h"
#include "mmsadp.h"
#include "JMMSJSRHandler.h"     /* included for mmscharset , to be discussed with neeraj */
#include "JMMSUCHandlingGProt.h"
#include "JMMSUCWrappersProt.h"
#include "JMMSCoreAPI.h"
#include "JMMSDRMHandler.h"
#include "JMMSStoreHandling.h"
#include "UnifiedMessageGProt.h"
#include "UnifiedComposerGProt.h"
#include "drm_def.h"
#include "Ucs2prot.h"
#include "Conversions.h"
#include "jdd_MessagingConfig.h"
#include "jdd_videoapi.h"
#include "mdi_datatype.h"       /* dependent headers for AudioPlayerProt.h" */
#if defined(__MMI_AUDIO_PLAYER__)
#include "AudioPlayerProt.h"
#include "mdi_audio.h"
#endif /* defined(__MMI_AUDIO_PLAYER__) */ 
#ifdef __MMI_VIDEO_PLAYER__
#include "mdi_video.h"
#endif /* __MMI_VIDEO_PLAYER__ */ 

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
#define SLS_ROOT_LAYOUT_T4  "\"/>\n"
#define SLS_REGION_T1       "<region id=\""
#define SLS_REGION_T2       "\" width=\""
#define SLS_REGION_T3       "\" height=\""
#define SLS_REGION_T4       "\" left=\""
#define SLS_REGION_T5       "\" top=\""
#define SLS_REGION_T6       "\" />\n"

#define JMMS_SMIL_CONTENT_ID         "Smil-Part"
#define JMMS_SMIL_FILE_NAME          "s.smil"
#define JMMS_MEDIA_TYPE_STRING_SMIL  "application/smil"
#define JMMS_IMAGE_REGION            "Image"    /* !< The image region name definition */
#define JMMS_TEXT_REGION             "Text"     /* !< The text region name definition */
#define JMMS_CFG_DEFAULT_SMIL_TEXT_COLOR         0x00000000
#define JMMS_CFG_MAX_DURATION                    60
#define COLOR_RGB_STR       "#RRGGBB"
#define JMMS_DIGIT_TO_STRING_MAX_SIZE  8

extern BOOL MimeSupportedInContentClass(S32 contant_class, U8 *mime_type);
extern JC_UINT8 CheckMediaResolutionInContentClass(EContentClass eContentClass, JC_UINT32 uiWidth, JC_UINT32 uiHeight);
static kal_uint32 wap_mma_uc_calc_object_smil_size_internal(
                    mma_insert_type_enum type,
                    const kal_wchar *filepath,
                    S32 is_file_name);
extern JC_BOOLEAN mmi_jdd_check_for_image_size_and_resolution(S8 *path, S32 width, S32 height, U32 media_size);
extern int mmi_charset_ucs2_to_utf8_length_in_bytes(const kal_uint8 *raw);

/******************************************************************************
 * Local variables/functions
 ******************************************************************************/
static kal_uint32 req_id = 0;


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_len_uintvar
 * DESCRIPTION
 *  This function is to calculate the size of passed string
 * CALLS
 *  
 * PARAMETERS
 *  value       [IN]        
 * RETURNS
 *  kal_uint8
 *****************************************************************************/
static kal_uint8 mmi_jmms_uc_len_uintvar(kal_uint32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (value < 0x80)
    {
        return 1;
    }
    else if (value < 0x4000)
    {
        return 2;
    }
    else if (value < 0x200000)
    {
        return 3;
    }
    else if (value < 0x10000000)
    {
        return 4;
    }
    else
    {
        return 5;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_uc_len_value_length
 * DESCRIPTION
 *  This function is to calculate the complete size of passed string
 * CALLS
 *  
 * PARAMETERS
 *  value       [IN]        
 * RETURNS
 *  kal_uint8
 *****************************************************************************/
static kal_uint8 mmi_jmms_uc_len_value_length(kal_uint32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (value > 30)
    {
        size += mmi_jmms_uc_len_uintvar(value);
        size++; /* Length-quote */
    }
    else
    {
        size = 1;
    }

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
 *  sec     [IN]        
 * RETURNS
 *  smil description size
 *****************************************************************************/
kal_uint32 wap_mma_uc_calc_slide_smil_size(kal_uint32 sec)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 size = 0, buffer_len = 0;
    char *buffer = NULL, *tmp = NULL;
    char str[JMMS_DIGIT_TO_STRING_MAX_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(str, "%d", (int)sec * 1000);
    buffer_len = strlen(SLS_PAR_START) + strlen(SLS_PAR_END) + strlen(str) + 1;
    buffer = (char*)OslMalloc(buffer_len);
    tmp = (char*)OslMalloc(buffer_len);
    sprintf(tmp, SLS_PAR_START, (int)sec * 1000);   /* <par dur="?000ms"> */
    strcpy(buffer, tmp);
    strcat(buffer, SLS_PAR_END);                    /* </par> */
    size = strlen(buffer);
    size = strlen(buffer);

    if (tmp != NULL)
    {
        OslMfree(tmp);
    }
    if (buffer != NULL)
    {
        OslMfree(buffer);
    }
    return size;
}


/*****************************************************************************
 * FUNCTION
 *  mma_uc_calc_object_multipart_header_size
 * DESCRIPTION
 *  Calculate multipart header size including
 *  - Headers: ContentType
 *  * general form (Value-length, Media-type(value/string), Parameter(charset(only text, smil), Name))
 *  - Headers: Content Location, Content ID
 * PARAMETERS
 *  filename_p      [IN]        
 * RETURNS
 *  size in bytes
 *****************************************************************************/
static kal_uint32 mma_uc_calc_object_multipart_header_size(const kal_wchar *filename_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_uint32 hd_size = 0, ct_size = 0, len = 0;
    kal_uint8 *mime_p = NULL;
    char *utf8_filename_p = NULL;
    mma_insert_type_enum type = MMA_INSERT_UNKNOWN;
    kal_bool is_smil = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(filename_p != NULL);
    len = mmi_charset_ucs2_to_utf8_length_in_bytes((kal_uint8*) filename_p);
    utf8_filename_p = OslMalloc(len + ENCODING_LENGTH);
    memset(utf8_filename_p, 0, len + ENCODING_LENGTH);
    mmi_chset_ucs2_to_utf8_string((kal_uint8*) utf8_filename_p, len + 1, (kal_uint8*) filename_p);    /* work fine for ascii */
    mime_p = (kal_uint8*) mmi_jmms_uc_get_mime_string_from_file(filename_p, MMA_INSERT_UNKNOWN);
    if (mime_p != NULL)
    {
        is_smil = (strcmp(JMMS_MEDIA_TYPE_STRING_SMIL, (char*)mime_p) == 0);
    }

    type = mmi_jmms_uc_get_mms_media_type_from_file(filename_p, MMA_INSERT_UNKNOWN);

    if (type != MMA_INSERT_UNKNOWN)
    {
        ct_size += 1;   /* value */
    }
    else
    {
        if (mime_p == NULL)
        {
            ct_size += 1;   /* value */
        }
        else
        {
            ct_size += (strlen((char*)mime_p) + 1); /* string */
        }
    }

    /* Parameter Charset */
    if (type == MMA_INSERT_TEXT || is_smil)
    {
        ct_size += 2;   /* 0x81 0x?? */
    }

    /* Parameter Name */
    ct_size += (strlen((char*)utf8_filename_p) + 2);    /* 0x85 + [name] + '\0' */

    /* Value-length */
    ct_size += mmi_jmms_uc_len_value_length(ct_size);
    hd_size += ct_size;

    /* Content Location: 0x8e + [name] + '\0' */
    hd_size += (strlen((char*)utf8_filename_p) + 2);

    /* Content ID: 0xc0 + '"' + '<' + [name] + '>' + '\0' */
    if (is_smil)
    {
        hd_size += (strlen(JMMS_SMIL_CONTENT_ID) + 5);
    }
    else
    {
        hd_size += (strlen((char*)utf8_filename_p) + 5);
    }

    /* HeadersLen */
    hd_size += mmi_jmms_uc_len_uintvar(hd_size);
    if (mime_p != NULL)
    {
        jdd_MemFree(mime_p);
        mime_p = NULL;
    }
    OslMfree(utf8_filename_p);
    utf8_filename_p = NULL;
    return hd_size;
}


/*****************************************************************************
 * FUNCTION
 *  wap_mma_uc_calc_header_attribute_size
 * DESCRIPTION
 *  Calculate MMS header to/cc/bcc/subject field length
 * PARAMETERS
 *  attr        [IN]        
 *  data        [IN]        
 * RETURNS
 *  size in bytes
 *****************************************************************************/
kal_uint32 wap_mma_uc_calc_header_attribute_size(mma_header_attr_enum attr, const kal_wchar *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i = 0, size = 0, len = 0;
    mmi_jmms_charset charset = MMS_US_ASCII;
    char *utf8_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (attr)
    {
        case MMA_HEADER_ADDRESS:
            if (IS_EMAIL((S8*) data))
            {
                size = strlen((S8*) data) + 2;  /* 0x97 + [Email] + '\0' */
            }
            else
            {
                size = strlen((S8*) data) + strlen("/TYPE=PLMN") + 2;  /* 0x97 + [#]/TYPE=PLMN + '\0' */
            }
            break;

        case MMA_HEADER_SUBJECT:
            len = mmi_charset_ucs2_to_utf8_length_in_bytes((kal_uint8*) data);
            utf8_data = OslMalloc(len + ENCODING_LENGTH);
            memset(utf8_data, 0, len + ENCODING_LENGTH);
            mmi_chset_ucs2_to_utf8_string((kal_uint8*) utf8_data, len + 1, (kal_uint8*) data);        /* work fine for ascii */
            for (i = 0; *(utf8_data + i) != '\0'; i++)
            {
                if ((unsigned char)*(utf8_data + i) > 0x7F)
                {
                    charset = MMS_UTF8;
                }
            }

            if (charset == MMS_US_ASCII)
            {
                size = strlen(utf8_data) + 2;   /* 0x96 + [Subject] + '\0' */
            }
            else
            {
                size += (strlen(utf8_data) + 3);    /* 0x96 + 0xea + [Subject] + '\0' */
                size = ((unsigned char)*utf8_data > 0x7F) ? (size + 1) : size;  /* 0x96 + 0xea + (0x7F) + [Subject] + '\0' */

                /* Value-length */
                size += mmi_jmms_uc_len_value_length(size); /* 0x96 + value-length + 0xea + (0x7F) + [Subject] + '\0' */
            }
            OslMfree(utf8_data);
            utf8_data = NULL;
            break;

        default:
            ASSERT(0);
    }
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
 *  mms     [IN]        
 * RETURNS
 *  size in bytes
 *****************************************************************************/
kal_uint32 wap_mma_uc_calc_header_size(const mmi_uc_msg_struct *mms)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 size = 0, tmp_size = 0;
    mmi_uc_addr_struct *addr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* X-Mms-Message-Type ~ From */
    size = 2 + 12 + 2 + 6 + 3;

    /* To */
    addr = mms->to_head;
    while (addr)
    {
        size += wap_mma_uc_calc_header_attribute_size(MMA_HEADER_ADDRESS, (kal_wchar*) addr->addr);
        addr = addr->next;
    }

    /* Cc */
    addr = mms->cc_head;
    while (addr)
    {
        size += wap_mma_uc_calc_header_attribute_size(MMA_HEADER_ADDRESS, (kal_wchar*) addr->addr);
        addr = addr->next;
    }

    /* Bcc */
    addr = mms->bcc_head;
    while (addr)
    {
        size += wap_mma_uc_calc_header_attribute_size(MMA_HEADER_ADDRESS, (kal_wchar*) addr->addr);
        addr = addr->next;
    }

    /* Subject */
    size += wap_mma_uc_calc_header_attribute_size(MMA_HEADER_SUBJECT, (kal_wchar*) mms->subject);

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
    tmp_size = 5 + strlen(JMMS_MEDIA_TYPE_STRING_SMIL) + strlen(JMMS_SMIL_CONTENT_ID) + strlen("<>");
    size += (1 + mmi_jmms_uc_len_uintvar(tmp_size) + tmp_size);

    /* nEntries */
    size += mmi_jmms_uc_len_uintvar(mms->total_object_num + 1); /* add SMIL part */

    return size;
}


/*****************************************************************************
 * FUNCTION
 *  wap_mma_uc_calc_msg_size
 * DESCRIPTION
 *  Calculate MMS message size
 * PARAMETERS
 *  mms     [IN]        
 * RETURNS
 *  size in bytes
 *****************************************************************************/
kal_uint32 wap_mma_uc_calc_msg_size(const mmi_uc_msg_struct *mms)      /* including SMIL size */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 size = 0, smil_size = 0;
    char buffer[JMMS_DIGIT_TO_STRING_MAX_SIZE] = {0, };
    mmi_uc_slide_struct *slide = NULL;
    mmi_uc_object_struct *obj = NULL;
    kal_wchar ucs2_filename[MMA_MAX_INTERNAL_FILENAME_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    size = wap_mma_uc_calc_header_size(mms);

    /* SMIL multipart header */
    mmi_chset_utf8_to_ucs2_string((kal_uint8*) ucs2_filename, 32, (kal_uint8*) JMMS_SMIL_FILE_NAME);
    size += mma_uc_calc_object_multipart_header_size(ucs2_filename);
    /* SMIL body */
    smil_size = strlen(SLS_SMIL_START) + strlen(SLS_SMIL_END) + strlen(SLS_HEAD_START)
        + strlen(SLS_HEAD_END) + strlen(SLS_BODY_START) + strlen(SLS_BODY_END)
        + strlen(SLS_LAYOUT_START) + strlen(SLS_LAYOUT_END);

    /* SMIL body: <root-layout width="XXX" height="XXX"/> */
    smil_size += (strlen(SLS_ROOT_LAYOUT_T1) + strlen(SLS_ROOT_LAYOUT_T2) + strlen(SLS_ROOT_LAYOUT_T4));
    sprintf(buffer, "%d", mmi_jmms_get_display_width());
    smil_size += strlen(buffer);
    sprintf(buffer, "%d", mmi_jmms_get_display_height());
    smil_size += strlen(buffer);

    /* SMIL body: <region id="XXX" width="XX%" height="XX%" left="XX%" top="XX%" /> */
    smil_size += 2 * (strlen(SLS_REGION_T1) + strlen(SLS_REGION_T2) + strlen(SLS_REGION_T3) +
                      strlen(SLS_REGION_T4) + strlen(SLS_REGION_T5) + strlen(SLS_REGION_T6));
    smil_size += (strlen(JMMS_IMAGE_REGION) + strlen(JMMS_TEXT_REGION));
    smil_size += 4 * strlen("100%");
    smil_size += 4 * strlen("0%");

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
                smil_size += wap_mma_uc_calc_object_smil_size_internal(MMA_INSERT_IMAGE, obj->file_name, 1);
                break;
            case MMI_UC_OBJECT_TYPE_AUDIO:
                smil_size += wap_mma_uc_calc_object_smil_size_internal(MMA_INSERT_AUDIO, obj->file_name, 1);
                break;
            case MMI_UC_OBJECT_TYPE_VIDEO:
                smil_size += wap_mma_uc_calc_object_smil_size_internal(MMA_INSERT_VIDEO, obj->file_name, 1);
                break;
            case MMI_UC_OBJECT_TYPE_TEXT:
                smil_size += wap_mma_uc_calc_object_smil_size_internal(MMA_INSERT_TEXT, obj->file_name, 1);
                break;
        }
        obj = obj->next;
    }

    size += smil_size;

    /* multipart excepts SMIL, refer to  wap_mma_uc_calc_object_multipart_size() */
    obj = mms->object_head;
    while (obj)
    {
        /* DataLen */
        size += mmi_jmms_uc_len_uintvar(obj->size);

        /* HeadersLen, Headers */
        size += mma_uc_calc_object_multipart_header_size(obj->file_name);
        /* body */
        size += obj->size;
        obj = obj->next;
    }

    return size;
}


/*****************************************************************************
 * FUNCTION
 *  wap_mma_uc_calc_object_multipart_size
 * DESCRIPTION
 *  Calculate multipart size including
 *  - header:
 *  + HeadersLen, Headers: mma_uc_calc_object_multipart_header_size()
 *  + DataLen
 *  - body:
 * PARAMETERS
 *  filepath        [IN]        UCS2 encoding
 * RETURNS
 *  size in bytes
 *****************************************************************************/
kal_uint32 wap_mma_uc_calc_object_multipart_size(const kal_wchar *filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 size = 0, filesize = mma_get_mmi_file_size(filepath);
    const kal_wchar *filename = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    filename = (kal_wchar*) mmi_jmms_uc_get_name_from_path_ucs2(filepath);
    /* DataLen */
    size += mmi_jmms_uc_len_uintvar(filesize);
    size += mma_uc_calc_object_multipart_header_size(filename);
    /* body */
    size += filesize;

    return size;
}


/*****************************************************************************
 * FUNCTION
 *  wap_mma_uc_calc_object_smil_size_internal
 * DESCRIPTION
 *  Calculate SMIL description length (begin, end, dur, alt parameters are not supported)
 * PARAMETERS
 *  type                [IN]        
 *  filepath            [IN]        
 *  is_file_name        [IN]        
 * RETURNS
 *  size in bytes
 *****************************************************************************/
static kal_uint32 wap_mma_uc_calc_object_smil_size_internal(
                    mma_insert_type_enum type,
                    const kal_wchar *filepath,
                    S32 is_file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 size = 0, buffer_len = 0;
    char *buffer = NULL, *tmp = NULL;
    char *utf8_filename = NULL, *t_region_name = NULL, *i_region_name = NULL;
    char *utf8_filepath = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type != MMA_INSERT_ATTACHMENT)
    {

        kal_uint32 len = 0;

        len = mmi_charset_ucs2_to_utf8_length_in_bytes((kal_uint8*) filepath);
        utf8_filepath = OslMalloc(len + ENCODING_LENGTH);
        memset(utf8_filepath, 0, len + ENCODING_LENGTH);
        mmi_chset_ucs2_to_utf8_string((kal_uint8*) utf8_filepath, len + 1, (kal_uint8*) filepath);    /* work fine for ascii */
        if (is_file_name)
        {
            utf8_filename = utf8_filepath;
        }
        else
        {
            utf8_filename = (char*)mmi_jmms_uc_get_name_from_path((char*)utf8_filepath);
        }
        i_region_name = JMMS_IMAGE_REGION;
        t_region_name = JMMS_TEXT_REGION;
    }

    switch (type)
    {
        case MMA_INSERT_TEXT:
        {
            char str[JMMS_DIGIT_TO_STRING_MAX_SIZE];

            buffer_len = strlen(SLS_TEXT_T1) + strlen(SLS_TEXT_T4) + strlen(SLS_TEXT_T6) + strlen(utf8_filename) +
                strlen(t_region_name) + strlen(COLOR_RGB_STR) + 1;
            buffer = (char*)OslMalloc(buffer_len);
            tmp = (char*)OslMalloc(buffer_len);

            sprintf(tmp, SLS_TEXT_T1, utf8_filename, t_region_name);    /* <text src="??.??" region="Text" */
            strcpy(buffer, tmp);
            strcat(buffer, SLS_TEXT_T6);    /* > */
            sprintf(str, "#%6x", JMMS_CFG_DEFAULT_SMIL_TEXT_COLOR);     /* #RRGGBB */
            sprintf(tmp, SLS_TEXT_T4, str);     /* <param name="foregroundcolor" value="#RRGGBB" /></text> */
            strcat(buffer, tmp);
            size = strlen(buffer);
            break;
        }

        case MMA_INSERT_IMAGE:
            buffer_len = strlen(SLS_IMAGE_T1) + strlen(SLS_IMAGE_T4) + strlen(utf8_filename) + strlen(i_region_name) + 1;
            buffer = (char*)OslMalloc(buffer_len);
            tmp = (char*)OslMalloc(buffer_len);
            sprintf(tmp, SLS_IMAGE_T1, utf8_filename, i_region_name);   /* <img src="??.??" region="Image" */
            strcpy(buffer, tmp);
            strcat(buffer, SLS_IMAGE_T4);   /* /> */
            size = strlen(buffer);
            break;

        case MMA_INSERT_AUDIO:
            buffer_len = strlen(SLS_AUDIO_T1) + strlen(SLS_AUDIO_T4) + strlen(utf8_filename) + 1;
            buffer = (char*)OslMalloc(buffer_len);
            tmp = (char*)OslMalloc(buffer_len);
            sprintf(tmp, SLS_AUDIO_T1, utf8_filename);  /* <audio src="??.??" /> */
            strcpy(buffer, tmp);
            strcat(buffer, SLS_AUDIO_T4);               /* /> */
            size = strlen(buffer);
            break;

        case MMA_INSERT_VIDEO:
            buffer_len = strlen(SLS_VIDEO_T1) + strlen(SLS_VIDEO_T4) + strlen(utf8_filename) + strlen(i_region_name) + 1;
            buffer = (char*)OslMalloc(buffer_len);
            tmp = (char*)OslMalloc(buffer_len);
            sprintf(tmp, SLS_VIDEO_T1, utf8_filename, i_region_name);   /* <video src="??.??" region="Image" */
            strcpy(buffer, tmp);
            strcat(buffer, SLS_VIDEO_T4);   /* /> */
            size = strlen(buffer);
            break;

        case MMA_INSERT_ATTACHMENT:
            size = 0;
            break;

        default:
            ASSERT(0);
    }

    if (utf8_filepath != NULL)
    {
        OslMfree(utf8_filepath);
    }
    if (tmp != NULL)
    {
        OslMfree(tmp);
    }
    if (buffer != NULL)
    {
        OslMfree(buffer);
    }
    return size;
}


/*****************************************************************************
 * FUNCTION
 *  wap_mma_uc_calc_object_smil_size
 * DESCRIPTION
 *  Calculate SMIL description length (begin, end, dur, alt parameters are not supported)
 * PARAMETERS
 *  type            [IN]        
 *  filepath        [IN]        
 * RETURNS
 *  size in bytes
 *****************************************************************************/
kal_uint32 wap_mma_uc_calc_object_smil_size(mma_insert_type_enum type, const kal_wchar *filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return wap_mma_uc_calc_object_smil_size_internal(type, filepath, 0);
}


/*****************************************************************************
 * FUNCTION
 *  wap_mma_uc_insert_object_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  creation_mode           [IN]        
 *  filepath                [IN]        
 *  type                    [IN]        
 *  current_msg_size        [IN]        
 *  max_msg_size            [IN]        
 *  info                    [OUT]         
 * RETURNS
 *  void
 *****************************************************************************/
void wap_mma_uc_insert_object_check(
        mma_creation_mode_enum creation_mode,
        const kal_wchar *filepath,
        mma_insert_type_enum type,
        kal_uint32 current_msg_size,
        kal_uint32 max_msg_size,
        mma_insert_check_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_uint32 add_size = 0;
    mma_drm_type_enum drm_method = MMA_DRM_NONE;
    mma_insert_type_enum local_type = type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    info->result = KAL_TRUE;
    info->detail_result = MMA_RESULT_OK;
	info->oversize = KAL_FALSE;
	info->creation_mode_violate = E_FALSE;

    if (type == MMA_INSERT_UNKNOWN &&
        (mmi_ucs2str((S8*) filepath, (S8*) L"3gp") != NULL || mmi_ucs2str((S8*) filepath, (S8*) L"mp4") != NULL))
    {
        if (mdi_audio_is_pure_audio((void*)filepath) == KAL_TRUE)
        {
            local_type = MMA_INSERT_AUDIO;
        }
        else
        {
            local_type = 0;
        }
    }
    if (creation_mode == MMA_CREATION_MODE_FREE)
    {
        local_type = mmi_jmms_uc_get_mms_media_type_from_file(filepath, local_type);
        info->creation_mode_violate = E_FALSE;

    }
    else
    {
        kal_uint8 *mime_string = (kal_uint8*) mmi_jmms_uc_get_mime_string_from_file(filepath, local_type);
        kal_bool mime_supported = E_FALSE;

        if (mime_string != NULL)
        {
            if (strcmp((kal_char*) mime_string, (kal_char*) "audio/mid") == 0)
            {
                mime_supported = MimeSupportedInContentClass(wap_get_mms_content_class(), (kal_uint8*) "audio/midi");
            }
            else
            {
                mime_supported = MimeSupportedInContentClass(wap_get_mms_content_class(), mime_string);
            }
            jdd_MemFree(mime_string);
            mime_string = NULL;
        }

        if (mime_supported)
        {
            local_type = mmi_jmms_uc_get_mms_media_type_from_file(filepath, local_type);
            info->creation_mode_violate = E_FALSE;
        }
        else
        {
            info->result = E_FALSE;
            info->creation_mode_violate = E_TRUE;
            info->detail_result = MMA_RESULT_FAIL_UNSUPPORT_CONTENT;
            return;
        }
    }
    if (type == MMA_INSERT_UNKNOWN)
    {
        if (local_type == MMA_INSERT_UNKNOWN)
        {
            type = MMA_INSERT_ATTACHMENT;
        }
        else
        {
            type = local_type;
        }
    }
    info->insert_type = type;

    switch (type)
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
		if (creation_mode == MMA_CREATION_MODE_FREE)
		{
			info->detail_result = MMA_RESULT_FAIL_MAX_MSG_SIZE_REACHED;
		}
		else
		{
			info->detail_result = MMA_RESULT_FAIL_CREATION_MODE_MAX_MSG_SIZE_REACHED;		
		}
        return;
    }
    else if (mma_get_mmi_file_size(filepath) == 0)
    {
        info->result = KAL_FALSE;
        info->detail_result = MMA_RESULT_FAIL_FILE_EMPTY;
        return;
    }
    else
    {
        info->oversize = KAL_FALSE;
    }

#ifdef __DRM_SUPPORT__
    /* DRM check */
    drm_method = mmi_jmms_get_drm_method_type((kal_wchar*) filepath);
    if (drm_method == DRM_METHOD_NONE)
    {
        info->drm_type = MMA_DRM_NONE;
    }
    else if (drm_method == DRM_METHOD_FORWARD_LOCK || drm_method == DRM_METHOD_COMBINED_DELIVERY)
    {
        info->result = MMI_FALSE;
        info->drm_type = MMA_DRM_FL_CD;
        info->detail_result = MMA_RESULT_FAIL_UNSUPPORT_CONTENT;
        return;
    }
    else
    {
        if (mmi_jmms_check_drm_rights((kal_wchar*) filepath) == MMI_TRUE)
        {
            info->drm_type = MMA_DRM_SD;
        }
        else
        {
            info->drm_type = MMA_DRM_SD_NO_RIGHT;
        }
        if (creation_mode != MMA_CREATION_MODE_FREE)
        {
            info->result = E_FALSE;
            info->creation_mode_violate = E_TRUE;
			info->detail_result = MMA_RESULT_FAIL_UNSUPPORT_CONTENT;
            return;
        }
    }
#else /* __DRM_SUPPORT__ */ 
    info->drm_type = drm_method;
#endif /* __DRM_SUPPORT__ */ 
    /* Check Resolution */

    if (creation_mode != MMA_CREATION_MODE_FREE &&
        (info->drm_type == MMA_DRM_NONE || info->drm_type == MMA_DRM_SD) &&
        (type == MMA_INSERT_IMAGE || type == MMA_INSERT_VIDEO
         || (type == MMA_INSERT_ATTACHMENT && (local_type == MMA_INSERT_IMAGE || local_type == MMA_INSERT_VIDEO))))
    {
        kal_bool resolution_supported = E_TRUE;
        kal_int32 img_widthv = 0, img_heightv = 0;
        mma_image_resizing_struct resize_struct = {0, };

        if (type == MMA_INSERT_IMAGE || local_type == MMA_INSERT_IMAGE)
        {
            gdi_image_get_dimension_file((S8*) filepath, &img_widthv, &img_heightv);
            mmi_jmms_uc_conf_get_image_resizing(&resize_struct);
            if (resize_struct.enable == KAL_TRUE &&
                (img_widthv > resize_struct.width || img_heightv > resize_struct.height))
            {
                img_widthv = resize_struct.width;
                img_heightv = resize_struct.height;
            }
        }
    #ifdef __MMI_VIDEO_PLAYER__
        if (type == MMA_INSERT_VIDEO || local_type == MMA_INSERT_VIDEO)
        {
            mmi_jdd_videoapp_get_video_file_size_info(
                (S8*) filepath,
                (kal_uint32*) & img_widthv,
                (kal_uint32*) & img_heightv);
        }
	#endif /* __MMI_VIDEO_PLAYER__ */
        resolution_supported =
            (kal_bool) mmi_jmms_is_media_resolution_in_content_class_limit(
                        wap_get_mms_content_class(),
                        (kal_uint32) img_widthv,
                        (kal_uint32) img_heightv);

        if (resolution_supported == E_FALSE)
        {
            info->result = E_FALSE;
            info->creation_mode_violate = E_TRUE;
            info->detail_result = MMA_RESULT_FAIL_UNSUPPORT_CONTENT;
            return;
        }
    }

    /* sanity check */
    switch (type)
    {
        case MMA_INSERT_IMAGE:
            if (info->drm_type == MMA_DRM_NONE || info->drm_type == MMA_DRM_SD)
            {
                kal_int32 img_widthv = 0, img_heightv = 0;

                gdi_image_get_dimension_file((S8*) filepath, &img_widthv, &img_heightv);
                if (mmi_jdd_check_for_image_size_and_resolution(
                        (S8*) filepath,
                        img_widthv,
                        img_heightv,
                        mma_get_mmi_file_size(filepath)) == 0 ||
                    mmi_mms_uc_check_image_file((kal_uint8*) filepath) == MMI_FALSE)
                {
                    info->result = KAL_FALSE;
                    info->detail_result = MMA_RESULT_FAIL_FILE_CORRUPTED;
                    return;
                }
            }

            break;

        #ifdef __MMI_VIDEO_PLAYER__
        case MMA_INSERT_VIDEO:
            if (info->drm_type == MMA_DRM_NONE || info->drm_type == MMA_DRM_SD)
            {
                MDI_RESULT result_video = 0;
                U32 img_widthv = 0, img_heightv = 0;

                result_video = mmi_jdd_videoapp_get_video_file_size_info(
                                (S8*) filepath,
                                (JC_UINT32*) & img_widthv,
                                (JC_UINT32*) & img_heightv);
                if (result_video == MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED)
                {
                    info->result = KAL_FALSE;
                    info->detail_result = MMA_RESULT_FAIL_FILE_CORRUPTED;
                    return;
                }
            }
            break;
        #endif /* __MMI_VIDEO_PLAYER__ */ 

        case MMA_INSERT_AUDIO:
            if (info->drm_type == MMA_DRM_NONE || info->drm_type == MMA_DRM_SD)
            {
                U32 audio_duration = 0;
                S32 audio_result = 0;

                audio_result = mdi_audio_get_duration((S8*) filepath, (U32*) & audio_duration);
                if (audio_result != GDI_SUCCEED)
                {
                    info->result = KAL_FALSE;
                    info->detail_result = MMA_RESULT_FAIL_FILE_CORRUPTED;
                    return;
                }
            }
            break;

        default:
            break;
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  wap_mma_get_box
 * DESCRIPTION
 *  Get box from message id
 * PARAMETERS
 *  msg_id          [IN]        
 *  result(?)       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mma_folder_enum wap_mma_get_box(kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_jmms_get_mma_folder_type_from_id(msg_id);
}

/* Vikas End for UC */


/*****************************************************************************
 * FUNCTION
 *  wap_mma_get_request_id
 * DESCRIPTION
 *  Get non-zero request id for issuing a request.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 wap_mma_get_request_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (req_id + 1 == 0)
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
 *  id1     [IN]        
 *  id2     [IN]        
 * RETURNS
 *  Earlier request id
 *****************************************************************************/
kal_uint32 mma_compare_request_id(kal_uint32 id1, kal_uint32 id2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id1 == id2)
    {
        return id1;
    }

    if ((req_id > id1 && req_id > id2) || (req_id < id1 && req_id < id2))
    {
        return (id1 < id2) ? id1 : id2;
    }
    else if (req_id < id1 && req_id > id2)  /* wrap around */
    {
        return id1;
    }
    else    /* wrap around : req_id > id1 && req_id < id2 */
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
 *  filepath        [IN]        
 * RETURNS
 *  file size
 *****************************************************************************/
kal_uint32 mma_get_mmi_file_size(const kal_wchar *filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 file_handle;
    kal_uint32 size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    file_handle = FS_Open((WCHAR*) filepath, FS_READ_ONLY);
    if (file_handle >= 0)
    {
        if (FS_GetFileSize(file_handle, &size) != FS_NO_ERROR)
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
			mmi_jmms_set_file_mgr_filter_for_image((FMGR_FILTER *)filter);
			break;
		
		case MMA_UC_FILTER_MODE_IMAGE_RESTRICTED_MODE:
			mmi_jmms_set_file_mgr_filter_for_image_restricted((FMGR_FILTER *)filter);
			break;

		case MMA_UC_FILTER_MODE_AUDIO_OPEN_MODE:
			mmi_jmms_set_file_mgr_filter_for_audio((FMGR_FILTER *)filter);
			break;

		case MMA_UC_FILTER_MODE_AUDIO_RESTRICTED_MODE:
			mmi_jmms_set_file_mgr_filter_for_audio_restricted((FMGR_FILTER *)filter);
			break;

		case MMA_UC_FILTER_MODE_VIDEO_OPEN_MODE:
			mmi_jmms_set_file_mgr_filter_for_video((FMGR_FILTER *)filter);
			break;

		case MMA_UC_FILTER_MODE_VIDEO_RESTRICTED_MODE:
			mmi_jmms_set_file_mgr_filter_for_video_restricted((FMGR_FILTER *)filter);
			break;

		case MMA_UC_FILTER_MODE_ATTACHMENT_OPEN_MODE:
			mmi_jmms_set_file_mgr_filter_for_attachment((FMGR_FILTER *)filter);
			break;

		case MMA_UC_FILTER_MODE_ATTACHMENT_RESTRICTED_MODE:
			mmi_jmms_set_file_mgr_filter_for_attachment_restricted((FMGR_FILTER *)filter);
			break;

		case MMA_UC_FILTER_MODE_TEXT_OPEN_MODE:
		case MMA_UC_FILTER_MODE_TEXT_RESTRICTED_MODE:
			break;
	}
	
	return;
}


/*****************************************************************************
 * FUNCTION
 *  mms_get_free_file_space
 * DESCRIPTION
 *  Get free file space for MMS in bytes
 * PARAMETERS
 *  void
 * RETURNS
 *  free space in byte
 *****************************************************************************/
kal_uint32 mms_get_free_file_space(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
	return mmi_jmms_get_free_space();
}

#else /* __UNIFIED_COMPOSER_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_dummy_mmsadp_fun
 * DESCRIPTION
 *  Just to remove warning
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_dummy_mmsadp_fun(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* dummy */
}

#endif /* __UNIFIED_COMPOSER_SUPPORT__ */ 

