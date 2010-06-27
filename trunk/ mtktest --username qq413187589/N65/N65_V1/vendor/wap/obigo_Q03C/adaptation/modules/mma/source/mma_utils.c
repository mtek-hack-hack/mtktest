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
#include "msf_core.h"
#include "msf_cfg.h"
#include "msf_int.h"
#include "msf_mem.h"
#include "msf_file.h"
#include "msf_dcvt.h"
#include "msf_chrs.h"
#include "msf_cmmn.h"
#include "msf_mime.h"

/* MMS */
#include "mms_cfg.h"
#include "mms_def.h"
#include "mmsl_if.h"
#include "msig.h"
#include "fldmgr.h"
#include "mms_if.h"
#include "mltypes.h"
#include "mutils.h"

/* SLS */
#include "sls_cfg.h"
#include "sls_def.h"
#include "sls_if.h"
#include "sls_main.h"

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
#include "widget.h"
#include "Widget_extension.h"

/* MISC */
#include "app_mine.h"
#include "app_usedetails.h"
#include "fs_type.h"
#ifdef __DRM_SUPPORT__
#include "drm_def.h"
#include "drm_gprot.h"
#endif
#include "l3_inc_enums.h"  /* for bearer error code, ex. UNKNOWN_APN*/

/* Local variables */
static const SlsMediaTypeItem slsSupportedMediaTypes[] = SLS_CFG_SUPPORTED_MEDIA_TYPES;
static const SlsCharsetItem slsCharsetList[] = SLS_CFG_SUPPORTED_CHARSET;

/******************************************************************************
 * Extern variables/functions
 ******************************************************************************/
extern MSF_BOOL copyContentType( MSF_UINT8 modId, MmsContentType *toContent, const MmsContentType *fromContent);

/*****************************************************************************
 * FUNCTION
 *  translate_fs_result_to_mma
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mma_result_enum translate_fs_result_to_mma(int result)
{
    switch (result)
    {
        case HDI_FILE_OK:
            return MMA_RESULT_OK;
        case HDI_FILE_ERROR_ACCESS:
            return MMA_RESULT_FAIL_FILE_IN_USE;
        case HDI_FILE_ERROR_DELAYED:
            return MMA_RESULT_DELAYED;
        case HDI_FILE_ERROR_PATH:
            return MMA_RESULT_FAIL_FILE_NOT_FOUND;
        case HDI_FILE_ERROR_FULL:
            return MMA_RESULT_FAIL_INSUFFICIENT_STORAGE;
        case HDI_FILE_ERROR_INVALID:
        case HDI_FILE_ERROR_EOF:
        case HDI_FILE_ERROR_EXIST:
        case HDI_FILE_ERROR_SIZE:
        default:
            return MMA_RESULT_FAIL_FILE_IO;    /* An unknown error */
    }
}

/*****************************************************************************
 * FUNCTION
 *  translate_mms_result_to_mma
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mma_result_enum translate_mms_result_to_mma(MmsResult result)
{
    switch (result)
    {
        case MMS_RESULT_OK:
            return MMA_RESULT_OK;

        case MMS_RESULT_DELAYED:
            return MMA_RESULT_DELAYED;

        case MMS_RESULT_BUSY:
            return MMA_RESULT_FAIL_BUSY;

        case MMS_RESULT_INSUFFICIENT_MEMORY:
            return MMA_RESULT_FAIL_INSUFFICIENT_MEMORY;

        case MMS_RESULT_INSUFFICIENT_PERSISTENT_STORAGE:
            return MMA_RESULT_FAIL_INSUFFICIENT_STORAGE;

        case MMS_RESULT_TOO_MANY_MSG:
            return MMA_RESULT_FAIL_MAX_MSG_NUM_REACHED;

        case MMS_RESULT_COMM_FILE_NOT_FOUND:
        case MMS_RESULT_FILE_NOT_FOUND:
        case MMS_RESULT_MESSAGE_ID_NOT_FOUND:
        case MMS_RESULT_WRONG_FILE_TYPE:
            return MMA_RESULT_FAIL_FILE_NOT_FOUND;

        case MMS_RESULT_FILE_READ_ERROR:
        case MMS_RESULT_FILE_WRITE_ERROR:
        case MMS_RESULT_EOF:
            return MMA_RESULT_FAIL_FILE_IO;

        case MMS_RESULT_FOLDER_NOT_FOUND:
            return MMA_RESULT_FAIL_FOLDER_NOT_FOUND;

        case MMS_RESULT_COMM_ENTITY_TOO_LARGE:
        case MMS_RESULT_COMM_HEADER_TAG:
        case MMS_RESULT_COMM_ILLEGAL_PDU:
        case MMS_RESULT_COMM_LIMITATIONS_NOT_MET:
        case MMS_RESULT_COMM_UNEXPECTED_MESSAGE:
        case MMS_RESULT_COMM_UNSUPPORTED_MEDIA_TYPE:
        case MMS_RESULT_COMM_UNSUPPORTED_VERSION:
        case MMS_RESULT_COMM_URI_TOO_LARGE:
        case MMS_RESULT_COMM_WRONG_MMS_VERSION:
            return MMA_RESULT_FAIL_COMM_UNSUPPORT_CONTENT;

        case MMS_RESULT_CONFIG_ERROR:
            return MMA_RESULT_FAIL_COMM_CONFIG_ERROR;

        case MMS_RESULT_COMM_ADDRESS_UNRESOLVED:
        case MMS_RESULT_COMM_BAD_GATEWAY:
        case MMS_RESULT_COMM_PROXY_ERROR:
        case MMS_RESULT_COMM_SECURITY_ERROR:
        case MMS_RESULT_COMM_STATUS:
        case MMS_RESULT_COMM_TRANSACTION_ID:
            return MMA_RESULT_FAIL_COMM_CONNECT_ERROR;

        case MMS_RESULT_COMM_TIMEOUT:
            return MMA_RESULT_FAIL_COMM_SERVER_TIMEOUT;

        case MMS_RESULT_COMM_SERVER_ERROR:
        case MMS_RESULT_COMM_MMSC_VERSION:
            return MMA_RESULT_FAIL_COMM_SERVER_ERROR;

        case MMS_RESULT_COMM_UNAUTHORIZED:
            return MMA_RESULT_FAIL_COMM_UNAUTHORIZED;
            
        case MMS_RESULT_COMM_UNAVAILABLE:
        case MMS_RESULT_COMM_FORBIDDEN:
            return MMA_RESULT_FAIL_COMM_SERVICE_DENIED;

        case MMS_RESULT_COMM_FAILED:
            if (strlen(mma_conf_get_mmsc_url()) == 0)
            {
                return MMA_RESULT_FAIL_COMM_CONFIG_ERROR;
            }
            else
            {
                extern MSF_INT32 HDIa_getLastError(void);
                MSF_INT32 detail_error = HDIa_getLastError();
                switch(detail_error) {
                case UNKNOWN_APN:
                    return MMA_RESULT_FAIL_COMM_UNKNOWN_APN;
                case AUTHENTICATION_FAILURE:
                    return MMA_RESULT_FAIL_COMM_UNAUTHORIZED;
                case UNSUPPORTED_SERVICE_OPTION:
                    return MMA_RESULT_FAIL_COMM_SERVICE_DENIED;
                case UNSUBSCRIBED_SERVICE_OPTION:
                    return MMA_RESULT_FAIL_COMM_UNKNOWN_APN;
                default:
                    return MMA_RESULT_FAIL_COMM_CONNECT_ERROR;
                }
            }

        case MMS_RESULT_CANCELLED_BY_USER:
            return MMA_RESULT_FAIL_USER_CANCEL;

        default:
            return MMA_RESULT_FAIL;    /* An unknown error */
    }
}

/*****************************************************************************
 * FUNCTION
 *  translate_sls_result_to_mma
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mma_result_enum translate_sls_result_to_mma(SlsResult result)
{
    switch (result)
    {
        case SLS_RESULT_OK:
            return MMA_RESULT_OK;

        case SLS_RESULT_BUSY:
            return MMA_RESULT_FAIL_BUSY;

        case SLS_RESULT_FILE_DELAY:
            return MMA_RESULT_DELAYED;

        case SLS_RESULT_FILE_READ_FAILURE:
            return MMA_RESULT_FAIL_FILE_IO;

        case SLS_RESULT_BUFFER_FULL:
            return MMA_RESULT_FAIL_INSUFFICIENT_MEMORY;

        case SLS_RESULT_MISSING_BODY_PART:
        case SLS_RESULT_MISSING_MEDIA_OBJECTS:
        case SLS_RESULT_MISSING_MEDIA_OBJECT_SRC:
        case SLS_RESULT_SMIL_INVALID:
        case SLS_RESULT_SMIL_NOT_CREATED:
        case SLS_RESULT_PARSING_FAILED:
            return MMA_RESULT_FAIL_FILE_CORRUPTED;

        case SLS_RESULT_TO_MANY_SLIDES:
            return MMA_RESULT_FAIL_MAX_SLIDE_NUM_REACHED;
            
        case SLS_RESULT_ERROR:
        default:
            return MMA_RESULT_FAIL;    /* An unknown error */
    }
}

/*****************************************************************************
 * FUNCTION
 *  translate_sma_result_to_mma
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mma_result_enum translate_sma_result_to_mma(SmaResult result)
{
    switch (result)
    {
        case SMA_RESULT_OK:
            return MMA_RESULT_OK;

        case SMA_RESULT_BUSY:
            return MMA_RESULT_FAIL_BUSY;

        case SMA_RESULT_INSUFFICIENT_PERSISTENT_STORAGE:
            return MMA_RESULT_FAIL_INSUFFICIENT_STORAGE;
                
        case SMA_RESULT_TO_MANY_SLIDES:
            return MMA_RESULT_FAIL_MAX_SLIDE_NUM_REACHED;
            
        case SMA_RESULT_ERROR:
        default:
            return MMA_RESULT_FAIL;    /* An unknown error */
    }
}

/*************************************************************************
* FUNCTION
*	translate_mms_priority_to_mma
* DESCRIPTION
*  This function is used to convert MMS priority definition to MMA priority definition
*
* CALLS
*
* PARAMETERS
* prio
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
mma_priority_enum translate_mms_priority_to_mma(MmsPriority prio)
{
    switch(prio)
    {
    case MMS_PRIORITY_NOT_SET:
        return MMA_PRIORITY_NOT_SET;
    case MMS_PRIORITY_LOW:
        return MMA_PRIORITY_LOW;
    case MMS_PRIORITY_NORMAL:
        return MMA_PRIORITY_MEDIUM;
    case MMS_PRIORITY_HIGH:
        return MMA_PRIORITY_HIGH;
    default:
        return MMA_PRIORITY_MEDIUM;
    }
}

/*************************************************************************
* FUNCTION
*	translate_mma_priority_to_mms
* DESCRIPTION
*  This function is used to convert MMA priority definition to MMS priority definition
*
* CALLS
*
* PARAMETERS
* prio
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
MmsPriority translate_mma_priority_to_mms(mma_priority_enum prio)
{
    switch(prio)
    {
    case MMA_PRIORITY_NOT_SET:
        return MMS_PRIORITY_NOT_SET;
    case MMA_PRIORITY_LOW:
        return MMS_PRIORITY_LOW;
    case MMA_PRIORITY_MEDIUM:
        return MMS_PRIORITY_NORMAL;
    case MMA_PRIORITY_HIGH:
        return MMS_PRIORITY_HIGH;
    default:
        return MMS_PRIORITY_NORMAL;
    }
}

/*************************************************************************
* FUNCTION
*	translate_mms_expiry_to_mma
* DESCRIPTION
*  This function is used to convert MMS absolute/relative expiry definition to MMA relative expiry definition
*
* CALLS
*
* PARAMETERS
* type
* expiry
* then
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
mma_expiry_time_enum translate_mms_expiry_to_mma(MmsTimeType type, MmsTimeSec expiry, MmsTimeSec then)
{
    long diff;

    if (MMS_TIME_ABSOLUTE == type)
    {
        diff = (long)(expiry - then);
    }
    else if(MMS_TIME_RELATIVE == type)
    {
        diff = (long)expiry;        
    }
    else  /* ex. The field is absent: type = 0 */
    {
        return MMA_EXPIRY_MAX;
    }

    /*  Only positive values please */
    if (diff < 0)
    {
        diff = -diff;
    }
    
    if (diff <= MMA_1_HOUR_IN_SEC)
    {
        return MMA_EXPIRY_1_HOUR;
    }
    else if (diff > MMA_1_HOUR_IN_SEC && diff <= MMA_12_HOURS_IN_SEC) 
    {
        return MMA_EXPIRY_12_HOURS;
    }
    else if (diff > MMA_12_HOURS_IN_SEC && diff <= MMA_1_DAY_IN_SEC) 
    {
        return MMA_EXPIRY_1_DAY;
    }
    else if (diff > MMA_1_DAY_IN_SEC && diff <= MMA_1_WEEK_IN_SEC) 
    {
        return MMA_EXPIRY_1_WEEK;
    }
    else
    {
        return MMA_EXPIRY_MAX;
    }
}

/*************************************************************************
* FUNCTION
*	translate_mma_expiry_to_mms
* DESCRIPTION
*  This function is used to convert MMA relative expiry definition to MMS absolute/relative expiry definition
*
* CALLS
*
* PARAMETERS
* expiry        [IN]
* now           [IN]
* type          [OUT]
* sec           [OUT]
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void translate_mma_expiry_to_mms(mma_expiry_time_enum expiry, MmsTimeSec now, MmsTimeType *type, MmsTimeSec *sec)
{
    MmsTimeSec base_sec = 0; 
    
    *type = MEAlib_getExpiryTimeType();

    if(*type == MMS_TIME_RELATIVE)
    {
        base_sec = 0;
    }
    else
    {
        base_sec = now;
    }
    switch(expiry)
    {
    case MMA_EXPIRY_NOT_SET:
    case MMA_EXPIRY_MAX:
        *sec = 0;
        break;
    case MMA_EXPIRY_1_HOUR:
        *sec = base_sec + MMA_1_HOUR_IN_SEC;
        break;
    case MMA_EXPIRY_12_HOURS:
        *sec = base_sec + MMA_12_HOURS_IN_SEC;
        break;
    case MMA_EXPIRY_1_DAY:
        *sec = base_sec + MMA_1_DAY_IN_SEC;
        break;
    case MMA_EXPIRY_1_WEEK:
        *sec = base_sec + MMA_1_WEEK_IN_SEC;
        break;
    }
}

/*************************************************************************
* FUNCTION
*	translate_mms_delivery_to_mma
* DESCRIPTION
*  This function is used to convert MMS absolute/relative delivery time definition to 
*  MMA relative delivery time definition
*
* CALLS
*
* PARAMETERS
* type
* delivery
* then
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
mma_delivery_time_enum translate_mms_delivery_to_mma(MmsTimeType type, MmsTimeSec delivery, MmsTimeSec then)
{
    long diff;

    if (MMS_TIME_ABSOLUTE == type)
    {
        diff = (long)(delivery - then);
    }
    else if(MMS_TIME_RELATIVE == type)
    {
        diff = (long)delivery;        
    }
    else  /* ex. The field is absent: type = 0 */
    {
        return MMA_DELIVERY_IMMEDIATE;
    }

    /*  Only positive values please */
    if (diff < 0)
    {
        diff = -diff;
    }
    
    if (diff <= MMA_1_HOUR_IN_SEC)
    {
        return MMA_DELIVERY_1_HOUR;
    }
    else if (diff > MMA_1_HOUR_IN_SEC && diff <= MMA_12_HOURS_IN_SEC) 
    {
        return MMA_DELIVERY_12_HOURS;
    }
    else if (diff > MMA_12_HOURS_IN_SEC && diff <= MMA_1_DAY_IN_SEC) 
    {
        return MMA_DELIVERY_24_HOURS;
    }
    else
    {
        return MMA_DELIVERY_24_HOURS;
    }
}

/*************************************************************************
* FUNCTION
*	translate_mma_delivery_to_mms
* DESCRIPTION
*  This function is used to convert MMA relative delivery definition to MMs relative/absolute expiry definition
*
* CALLS
*
* PARAMETERS
* delivery      [IN]
* now           [IN]
* type          [OUT]
* sec           [OUT]
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void translate_mma_delivery_to_mms(mma_delivery_time_enum delivery, MmsTimeSec now, MmsTimeType *type, MmsTimeSec *sec)
{
    MmsTimeSec base_sec = 0; 
    
    *type = MEAlib_getDeliveryTimeType();

    if(*type == MMS_TIME_RELATIVE)
    {
        base_sec = 0;
    }
    else
    {
        base_sec = now;
    }
    
    switch(delivery)
    {
    case MMA_DELIVERY_NOT_SET:
    case MMA_DELIVERY_IMMEDIATE:
        *sec = 0;
        break;
    case MMA_DELIVERY_1_HOUR:
        *sec = base_sec + MMA_1_HOUR_IN_SEC;
        break;
    case MMA_DELIVERY_12_HOURS:
        *sec = base_sec + MMA_12_HOURS_IN_SEC;
        break;
    case MMA_DELIVERY_24_HOURS:
        *sec = base_sec + MMA_1_DAY_IN_SEC;
        break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mma_mem_calloc
 * DESCRIPTION
 *  Allocate memory function
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  memory pointer
 *****************************************************************************/
static void *mma_mem_calloc(kal_uint32 size)
{
    void *p = NULL;
    MMA_CALLOC(p, size);
    return p;
}

/*****************************************************************************
 * FUNCTION
 *  mma_mem_free
 * DESCRIPTION
 *  Free memory function
 * PARAMETERS
 *  p        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_mem_free(void *p)
{
    MMA_FREE(p);
}

/*****************************************************************************
 * FUNCTION
 *  mma_get_applib_ext_from_mime
 * DESCRIPTION
 *  Get applib extension from mime type 
 * PARAMETERS
 *  mime        [IN]        
 * RETURNS
 * extension string
 *****************************************************************************/
const char *mma_get_applib_ext_from_mime(const char *mime)
{
    if(mime != NULL)
    {
        applib_mime_type_struct *entry = NULL;

        entry = mime_type_look_up((kal_char *)mime, NULL, 0, 0);
        if(entry != NULL && entry->file_ext != NULL)
        {
            return entry->file_ext;
        }
    }
    return NULL;
}

/*****************************************************************************
 * FUNCTION
 *  mma_get_presentation_type
 * DESCRIPTION
 *  Get mms presentation type
 * PARAMETERS
 *  msgHeader        [IN]        
 * RETURNS
 *  The type of message presentation
 *****************************************************************************/
mma_mms_multipart_enum mma_get_multipart_type(MmsGetHeader *msgHeader)
{
    /* Check for plain text */
    if(NULL != msgHeader)
    {
        if(0 == msgHeader->bodyInfoList.numOfEntries)
        {
            return MMA_PLAIN_TEXT;
        }
        else if((MMS_VND_WAP_MULTIPART_RELATED == msgHeader->bodyInfoList.contentType->knownValue))
        {
            MmsBodyInfoList *biList = &msgHeader->bodyInfoList;
            while (NULL != biList)    /* Traverse all body-parts in hunt of a SMIL presentation */
            {
                /* Check params for current body-part - is it a SMIL ? */
                if ((MMS_VALUE_AS_STRING == biList->contentType->knownValue) &&
                    (NULL != biList->contentType->strValue) &&
                    (0 == msf_cmmn_strcmp_nc((char *)biList->contentType->strValue, MMS_MEDIA_TYPE_STRING_SMIL)))
                {
                    return MMA_SMIL;
                }
                biList = biList->next;
            }
            return MMA_MULTIPART_MIXED;
        }
        else if(MMS_VND_WAP_MULTIPART_MIXED == msgHeader->bodyInfoList.contentType->knownValue)
        {
            return MMA_MULTIPART_MIXED;
        }
        else if(MMS_VND_WAP_MULTIPART_ALTERNATIVE == msgHeader->bodyInfoList.contentType->knownValue)
        {
            return MMA_MULTIPART_ALTERNATIVE;
        }
    }
    return MMA_UNSUPPORTED;
}

/*****************************************************************************
 * FUNCTION
 *  mma_get_mime_type_from_mmsContentType
 * DESCRIPTION
 *  Get mime type string from MmsContentType info
 * PARAMETERS
 *  contentType        [IN]        
 * RETURNS
 *  mime type string
 *****************************************************************************/
const char *mma_get_mime_type_from_mmsContentType(const MmsContentType *contentType)
{
    const char *tempType = NULL;
    
    if (contentType == NULL)
    {
        return NULL;
    } 
    
    if (contentType->knownValue == MMS_VALUE_AS_STRING)
    {
        return (const char *)contentType->strValue;
    }
    else
    {
        tempType = msf_int_to_mime(contentType->knownValue);
        return tempType;
    } 
} 

/*****************************************************************************
 * FUNCTION
 *  mma_get_mime_type_from_filename
 * DESCRIPTION
 *  Get mime type from file name (extension) 
 * PARAMETERS
 *  filename        [IN]        
 * RETURNS
 * SlsMediaType
 *****************************************************************************/
const char *mma_get_mime_type_from_filename(const char *filename)
{
    if(filename != NULL)
    {
        char *ext = NULL;
        applib_mime_type_struct *entry = NULL;

        ext = strrchr(filename, '.');
        if(ext != NULL)
        {
            ext++;
            entry = mime_type_look_up(NULL, ext, 0, 0);
            if (entry == NULL)
            {
                return NULL;
            }
            return entry->mime_string;
        }
    }
    return NULL;
}

/*****************************************************************************
 * FUNCTION
 *  mma_get_mmsKnownMediaType_from_mime_type
 * DESCRIPTION
 *  Get known MMS media type from mime type.
 * PARAMETERS
 *  mime        [IN]        
 * RETURNS
 * MmsKnownMediaType
 *****************************************************************************/
MmsKnownMediaType mma_get_mmsKnownMediaType_from_mime_type(const char *mime)
{
    kal_uint32 i = 0;
    
    if(mime != NULL)
    {
        while(slsSupportedMediaTypes[i].mediaType != SLS_NOT_USED)
        {
            if(msf_cmmn_strcmp_nc(mime, slsSupportedMediaTypes[i].mimeType) == 0)
            {
                return slsSupportedMediaTypes[i].mmsMediaType;
            }
            i++;
        }
    }
    return MMS_VALUE_AS_STRING;
}

/*****************************************************************************
 * FUNCTION
 *  mma_get_slsMediaType_from_mime_type
 * DESCRIPTION
 *  Get SLS media type from mime type.
 * PARAMETERS
 *  mime        [IN]        
 * RETURNS
 * SlsMediaType
 *****************************************************************************/
SlsMediaType mma_get_slsMediaType_from_mime_type(const char *mime)
{
    kal_uint32 i = 0;
    
    if(mime != NULL && mma_is_supported_mime_type(mime) == KAL_TRUE)
    {
        while(slsSupportedMediaTypes[i].mediaType != SLS_NOT_USED)
        {
            if(msf_cmmn_strcmp_nc(mime, slsSupportedMediaTypes[i].mimeType) == 0)
            {
                return slsSupportedMediaTypes[i].mediaType;
            }
            i++;
        }
    }
    return SLS_UNKNOWN;
}

/*****************************************************************************
 * FUNCTION
 *  mma_get_slsMediaType_from_filename
 * DESCRIPTION
 *  Get SLS media type from file name (extension).
 *  ex. If the contentType cannot tell what the media type is, we use filename extension.
 * PARAMETERS
 *  filename        [IN]        
 * RETURNS
 * SlsMediaType
 *****************************************************************************/
SlsMediaType mma_get_slsMediaType_from_filename(const char *filename)
{
    if(filename != NULL)
    {
        const char *mime = mma_get_mime_type_from_filename(filename);
        return mma_get_slsMediaType_from_mime_type(mime);

    }
    return SLS_UNKNOWN;
}

/*****************************************************************************
 * FUNCTION
 *  mma_get_slsMediaType_from_mmsContentType
 * DESCRIPTION
 *  Get SLS media type from MmsContentType info
 * PARAMETERS
 *  contentType        [IN]        
 * RETURNS
 *  SlsMediaType
 *****************************************************************************/
SlsMediaType mma_get_slsMediaType_from_mmsContentType(const MmsContentType *contentType)
{
	SlsMediaType mediaType = SLS_UNKNOWN;
    const char *mime = NULL;
	int i = 0;
    
    while(SLS_NOT_USED != slsSupportedMediaTypes[i].mediaType)
    {
        if (contentType->knownValue == slsSupportedMediaTypes[i].mmsMediaType)
        {
            if (MMS_VALUE_AS_STRING != slsSupportedMediaTypes[i].mmsMediaType)
            {
                mediaType = slsSupportedMediaTypes[i].mediaType;
                mime = slsSupportedMediaTypes[i].mimeType;
                break;
            }
            else if (0 == msf_cmmn_strcmp_nc(slsSupportedMediaTypes[i].mimeType, (char *)contentType->strValue))
            {
                mediaType = slsSupportedMediaTypes[i].mediaType;
                mime = slsSupportedMediaTypes[i].mimeType;
                break;
            } 
        } 
        ++i;
    } 

    if (mma_is_supported_mime_type(mime) == KAL_FALSE)
    {
        return SLS_UNKNOWN;
    }
    else
    {
	    return mediaType;
    }
} 

/*****************************************************************************
 * FUNCTION
 *  mma_get_slsMediaObjectType_from_slsMediaType
 * DESCRIPTION
 *  Get SLS media object type from SlsMediaObjectType info
 * PARAMETERS
 *  mediaType        [IN]        
 * RETURNS
 *  SlsMediaObjectType
 *****************************************************************************/
SlsMediaObjectType mma_get_slsMediaObjectType_from_slsMediaType(SlsMediaType mediaType)
{
    int i = 0;
    while(SLS_NOT_USED != slsSupportedMediaTypes[i].mediaType)
    {
        if (mediaType == slsSupportedMediaTypes[i].mediaType)
        {
            return slsSupportedMediaTypes[i].objectType;
        }
        ++i;
    }
    return SLS_OBJECT_TYPE_NONE;
}

#ifdef __DRM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mma_drm_check_right
 * DESCRIPTION
 *  Check if DRM right is valid for a processed DRM file
 * PARAMETERS
 *  filename    [IN]
 * RETURNS
 *  kal_bool
 *****************************************************************************/
 kal_bool mma_drm_check_right(const char *filename)
{
    kal_uint8* externalFileName = NULL;
    kal_bool is_valid_right = KAL_FALSE;
    char *mime = NULL;
    SlsMediaType drmType = SLS_NOT_USED;
    SlsMediaObjectType drmGType = SLS_OBJECT_TYPE_NONE;

    ASSERT(filename);
    externalFileName = HDI_FileNameTranslate(filename);
    mime = (char *)DRM_get_content_type(0, (kal_wchar *)externalFileName);
    drmType = mma_get_slsMediaType_from_mime_type(mime);
    drmGType = mma_get_slsMediaObjectType_from_slsMediaType(drmType);
    if(drmGType != SLS_OBJECT_TYPE_NONE && drmGType != SLS_OBJECT_TYPE_DRM)
    {
        MSF_UINT8 permission = (kal_uint8)((drmGType == SLS_OBJECT_TYPE_IMAGE) ? 
            DRM_PERMISSION_DISPLAY : DRM_PERMISSION_PLAY);
    
        is_valid_right = DRM_validate_permission(0, (kal_wchar *)externalFileName, permission);
    }
    HDI_FileNameFree(externalFileName);
    return is_valid_right;
} 

/*****************************************************************************
 * FUNCTION
 *  mma_drm_check_right_vf
 * DESCRIPTION
 *  Check if DRM right is valid for DRM virtual file
 * PARAMETERS
 *  type        [IN]
 *  filename    [IN]
 *  offset      [IN]
 *  size        [IN]
 * RETURNS
 *  kal_bool
 *****************************************************************************/
mma_drm_type_enum mma_drm_check_right_vf(SlsMediaType type, const char *filename, int offset, int size)
{
    ASSERT(filename != NULL);
    if(size == 0 || (type != SLS_DRM_MESSAGE && type != SLS_DRM_CONTENT))
    {
        return MMA_DRM_NONE;
    }
    else if(type == SLS_DRM_MESSAGE)  /* MMS doesn't consume right, so FL and CD always ok */
    {
        return MMA_DRM_FL_CD;
    }
    else if(type == SLS_DRM_CONTENT)  /* Check if SD right present */
    {
        char *vFileName = NULL;                 /* virtual file name */
        MSF_INT32 handle = 0;
        kal_bool is_valid_right = KAL_FALSE;
        
        if ((handle = MSF_FILE_OPEN(MSF_MODID_MMA, filename, MSF_FILE_SET_RDONLY, 0)) < 0)
        {
            return MMA_DRM_NONE;
        }
        
        /*generate virtual file */
        MMA_CALLOC(vFileName, WIDGET_RAWFILE_NAMELEN);
        ASSERT(vFileName != NULL);
        if(HDIa_fileGenVirtualFileName(handle, vFileName, WIDGET_RAWFILE_NAMELEN, offset, size) == HDI_FILE_OK)
        {
            unsigned char *externalVFileName = HDI_FileNameTranslate(vFileName);    /* UCS2 virtual file name */
            DRM_process_virtual_file ((kal_uint8 *)"application/vnd.oma.drm.content", (kal_wchar *) externalVFileName, 
                NULL); /* process before checking right */
            is_valid_right = mma_drm_check_right(vFileName);
            HDI_FileNameFree(externalVFileName);
        }
        MMA_FREE(vFileName);
        MSF_FILE_CLOSE(handle);

        return (is_valid_right ? MMA_DRM_SD : MMA_DRM_SD_NO_RIGHT);
    }
    return MMA_DRM_NONE;
} 

/*****************************************************************************
 * FUNCTION
 *  mma_drm_get_method_type
 * DESCRIPTION
 *  Get DRM method for a processed DRM file, ex. files in file manager
 * PARAMETERS
 *  filename    [IN]
 * RETURNS
 *  mma_drm_method_enum
 *****************************************************************************/
mma_drm_method_enum mma_drm_get_method_type(const char *filename)
{
    drm_method_enum drmMethod = DRM_METHOD_NONE;
    kal_uint8* externalFileName = HDI_FileNameTranslate(filename);
    drmMethod = DRM_get_object_method(0, (kal_wchar *)externalFileName);
    HDI_FileNameFree(externalFileName);

    switch(drmMethod)
    {
    case DRM_METHOD_NONE:
        return MMA_DRM_METHOD_NONE;
    case DRM_METHOD_FORWARD_LOCK:
        return MMA_DRM_METHOD_FORWARD_LOCK;
    case DRM_METHOD_COMBINED_DELIVERY:
        return MMA_DRM_METHOD_COMBINED_DELIVERY;
    case DRM_METHOD_SEPARATE_DELIVERY:
        return MMA_DRM_METHOD_SEPARATE_DELIVERY;
    default:
        return MMA_DRM_METHOD_NONE;
    }
} 

/*****************************************************************************
 * FUNCTION
 *  mma_drm_get_content_type
 * DESCRIPTION
 *  Get mime type string for un-processed DRM file
 * PARAMETERS
 *  type        [IN]
 *  filename    [IN]
 * RETURNS
 *  mime type string
 *****************************************************************************/
const char *mma_drm_get_content_type(SlsMediaType type, const char *filename)
{
    unsigned char *externalFileName = NULL;	/* translated UCS2 vitual file name */
    const char *mime = NULL;

    ASSERT(filename != NULL && (type == SLS_DRM_MESSAGE || type == SLS_DRM_CONTENT));
    externalFileName = HDI_FileNameTranslate(filename);
    if(type == SLS_DRM_MESSAGE)  /* FL, CD */
    {
        char fileNameUTF8[100];
        unsigned char fileNameUCS2[200];
        MSF_INT32 drmOffset = 0, drmSize = 0;

        /* Get raw data offset */
        sprintf(fileNameUTF8, "dummy.vvvvvvvvvv");
        widget_utf8_to_ucs2_string(fileNameUCS2, 200, (const kal_uint8 *)fileNameUTF8);
        drmOffset = DRM_process_direct_file((kal_uint8 *)"application/vnd.oma.drm.message", 
            (kal_wchar *) externalFileName, (kal_wchar *) fileNameUCS2, (kal_uint32 *)&drmSize);
        /* fileNameUCS2 extension is from mime type in DRM right */
        widget_ucs2_to_utf8_string((kal_uint8 *)fileNameUTF8, 100, fileNameUCS2);
        mime = mma_get_mime_type_from_filename(fileNameUTF8);
    }
    else if(type == SLS_DRM_CONTENT)
    {
        DRM_process_virtual_file ((kal_uint8 *)"application/vnd.oma.drm.content", (kal_wchar *) externalFileName, NULL); /* generate RO */
        mime = (const char *)DRM_get_content_type(0, (kal_wchar *) externalFileName);
    }
    HDI_FileNameFree(externalFileName);

    return mime;
} 

/*****************************************************************************
 * FUNCTION
 *  mma_drm_get_content_type_vf
 * DESCRIPTION
 *  Get mime type string for DRM virtual file
 * PARAMETERS
 *  type        [IN]
 *  filename    [IN]
 *  offset      [IN]
 *  size        [IN]
 * RETURNS
 *  mime type string
 *****************************************************************************/
const char *mma_drm_get_content_type_vf(SlsMediaType type, const char *filepath, int offset, int size)
{
    char *vFileName = NULL;					/* vitual file name */
    MSF_INT32 handle = 0;
    const char *mime = NULL;

    ASSERT(filepath != NULL);
    if(size == 0 || (type != SLS_DRM_MESSAGE && type != SLS_DRM_CONTENT))
    {
        return NULL;
    }

    if ((handle = MSF_FILE_OPEN(MSF_MODID_MMA, filepath, MSF_FILE_SET_RDONLY, 0)) < 0)
    {
        return NULL;
    }
    
    /*generate virtual file */
    MMA_CALLOC(vFileName, WIDGET_RAWFILE_NAMELEN);
    ASSERT(vFileName != NULL);
    if(HDIa_fileGenVirtualFileName(handle, vFileName, WIDGET_RAWFILE_NAMELEN, offset, size) == HDI_FILE_OK)
    {
        mime = mma_drm_get_content_type(type, vFileName);
    }

    MMA_FREE(vFileName);
    MSF_FILE_CLOSE(handle);
    return mime;
} 
#endif /* __DRM_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  mma_get_slide
 * DESCRIPTION
 *  Get slide by its index
 * PARAMETERS
 *  body        [IN]
 *  index       [IN]
 * RETURNS
 *****************************************************************************/
mma_slide_struct *mma_get_slide(mma_body_struct *body, kal_uint32 index)
{
    mma_slide_struct *slide = NULL;

    ASSERT(body != NULL);
    for(slide = body->slides; slide != NULL && index > 0; slide = slide->next, index--);
    return slide;
}

/*****************************************************************************
 * FUNCTION
 *  mma_get_slide_index
 * DESCRIPTION
 *  Get slide index (0~)
 * PARAMETERS
 *  body        [IN]
 *  slide       [IN]
 * RETURNS
 *  -1 if not found; otherwise, the slide index
 *****************************************************************************/
kal_int32 mma_get_slide_index(mma_body_struct *body, mma_slide_struct *slide)
{
    mma_slide_struct *current = body->slides;
    kal_int32 index = 0;
    while ((NULL != current) && (current != slide))
    {
        current = current->next;
        index ++;
    }

    return ((current != slide)? -1: index);
}

/*****************************************************************************
 * FUNCTION
 *  mma_get_slide_layout
 * DESCRIPTION
 *  Get slide layout
 * PARAMETERS
 *  slide        [IN]        
 * RETURNS
 *****************************************************************************/
mma_slide_layout_enum mma_get_slide_layout(mma_slide_struct *slide)
{
    mma_slide_object_struct *text = NULL, *image = NULL;

    ASSERT(slide != NULL);
    
    /* image over video */
    if(slide->image.obj != NULL)
    {
        image = &slide->image;
    }
    else if(slide->video.obj != NULL)
    {
        image = &slide->video;
    }
    
    if(slide->text.obj != NULL)
    {
        text = &slide->text;
    }

    if(text && image)
    {
        if (image->region.position.cy.value < text->region.position.cy.value)
        {
            return MMA_LAYOUT_IMAGE_ON_TOP;
        }
        else
        {
            return MMA_LAYOUT_TEXT_ON_TOP;
        }
    }
    else
    {
        return MMA_LAYOUT_NONE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mma_get_unref_item_count
 * DESCRIPTION
 *  Get attchment number
 * PARAMETERS
 *  list        [IN]
 * RETURNS
 *  Attchment number
 *****************************************************************************/
kal_uint32 mma_get_unref_item_count(mma_unref_list_struct *list)
{
    int obj_no = 0;
    for(; list != NULL; list = list->next, obj_no++);
    return obj_no;
}

/*****************************************************************************
 * FUNCTION
 *  mma_get_total_item_count
 * DESCRIPTION
 *  Get slide object + attchment object number
 * PARAMETERS
 *  body        [IN]
 * RETURNS
 *  Total object number
 *****************************************************************************/
kal_uint32 mma_get_total_item_count(mma_body_struct *body)
{
    mma_object_struct *obj = NULL;
    kal_uint32 count = 0;

    ASSERT(body != NULL);
    obj = body->objects;
    for(; obj != NULL; obj = obj->next, count++);
    return count;
}

/*****************************************************************************
 * FUNCTION
 *  mma_get_charset_from_params
 * DESCRIPTION
 *  Get text charset from content type parameters
 * PARAMETERS
 *  param        [IN]
 *  boundary     [OUT]
 * RETURNS
 *  MSF charset enum
 *****************************************************************************/
MSF_UINT32 mma_get_charset_from_params(const MmsAllParams *param)
{
    unsigned int i;
    const SlsCharsetItem *items;

    while(param != NULL)
    {
        if(param->type == MMS_PARAM_INTEGER && param->param == MMS_CHARSET)
        {
            i = 0;
            items = slsCharsetList;
            while(MSF_CHARSET_UNKNOWN != items[i].msfCharset)
            {
                if ((unsigned)items[i].mmsCharset == param->value.integer)
                {
                    return items[i].msfCharset;
                } 
                ++i;
            } 
            return MSF_CHARSET_UNKNOWN;
        } 
        param = param->next;
    }     
    
    return MSF_CHARSET_ASCII;
}

/*****************************************************************************
 * FUNCTION
 *  mma_get_boundary_from_params
 * DESCRIPTION
 *  Get DRM boundary from content type parameters
 * PARAMETERS
 *  param        [IN]
 *  boundary     [OUT]
 * RETURNS
 *****************************************************************************/
void mma_get_boundary_from_params(char **boundary, const MmsAllParams *param)
{
    while (param != NULL)
    {
        if ((param->type == MMS_PARAM_STRING) && (param->param == MMS_TEXT_KEY) && 
            (0 == msf_cmmn_strcmp_nc((char *)param->key, "boundary")))  /* SLS_BOUNDARY */
        {
            if (param->value.string != NULL)
            {
                *boundary = msf_cmmn_strdup(MSF_MODID_MMA, (const char *)param->value.string);
                return;
            } 
        } 
        param = param->next;
    }     
} 

/*****************************************************************************
 * FUNCTION
 *  mma_get_name_from_params
 * DESCRIPTION
 *  Get multipart object filename from content type parameters
 * PARAMETERS
 *  param        [IN]
 * RETURNS
 *  filename
 *****************************************************************************/
char *mma_get_name_from_params(const MmsAllParams *param)
{
    char *to = NULL;
    const char *from = NULL;

	while(param != NULL)
    {
        MSF_UINT32 i = 0;
        MSF_UINT32 j = 0;

        if((param->type == MMS_PARAM_STRING) && (param->param == MMS_FILENAME || param->param == MMS_NAME)
            && param->value.string != NULL)
        {
          from = (const char *)param->value.string;
          to = (char*)MMA_ALLOC(strlen(from) + 1);
          
          if (*(from + i) == '"' || *(from + i) == '<')
          {
              ++i;
          } 
          
          while (*(from + i) && *(from + i) != '>' && *(from + i) != '"')
          {
              *(to + j) = *(from + i);
              ++j;
              ++i;
          } 
          *(to + j) = 0;
          break;
        } 
        param = param->next;
    }     
    return to;
} 

/*****************************************************************************
 * FUNCTION
 *  mma_get_name_from_entry_header
 * DESCRIPTION
 *  Get multipart object filename from header field, ex. content id and content location
 * PARAMETERS
 *  entries        [IN]
 * RETURNS
 *  filename
 *****************************************************************************/
char *mma_get_name_from_entry_header(const MmsEntryHeader *entries)
{
    while(entries)
    {
        if (((MMS_WELL_KNOWN_CONTENT_LOCATION == entries->headerType) || 
            (MMS_WELL_KNOWN_CONTENT_ID == entries->headerType)) && 
            (NULL != entries->value.wellKnownFieldName))
        {
            return msf_cmmn_strdup(MSF_MODID_MMA, (char*)entries->value.wellKnownFieldName);
        }
        entries = entries->next;
    }
    return NULL;
} 

/*****************************************************************************
 * FUNCTION
 *  mma_get_name_from_path
 * DESCRIPTION
 *  Get filename from filepath
 * PARAMETERS
 *  path        [IN]
 * RETURNS
 *  filename
 *****************************************************************************/
const char *mma_get_name_from_path(char *path)
{
    char *c = strrchr(path, '\\');
    char *c1 = strrchr(path, '/');

    if (c == NULL && c1 == NULL)
    {
        return NULL;
    }
    else
    {
        c = (c1 > c)? c1: c;  /* find the last / or \ */
    }

    /*Skip past "\"*/
    return (++c);
}

/*****************************************************************************
 * FUNCTION
 *  mma_get_object_from_name
 * DESCRIPTION
 *  Get object from name
 * PARAMETERS
 *  name        [IN]
 * RETURNS
 *  mma_object_struct
 *****************************************************************************/
mma_object_struct *mma_get_object_from_name(mma_body_struct *body, const char *name)
{
    mma_object_struct *obj = NULL;

    obj = body->objects;
    while (obj)
    {
        if (strcmp(obj->fileName, name) == 0)
        {
            return obj;
        }
        obj = obj->next;
    }

    return NULL;
}

/*****************************************************************************
 * FUNCTION
 *  mma_add_param_int
 * DESCRIPTION
 *  Inserts a string param first in the list of params
 * PARAMETERS
 *  allParams        [OUT] The current list
 *  param            [IN] The param to insert
 *  value            [IN] The integer value for the param to insert. 
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mma_add_param_int(struct MmsAllParamsStruct **allParams, MmsParam param, MSF_UINT32 value)
{
    MmsAllParams *newParam = NULL;

    MMA_CALLOC(newParam, sizeof(MmsAllParams));
    newParam->param = param;
    newParam->type = MMS_PARAM_INTEGER;
    newParam->value.integer = value;
    newParam->next = *allParams;  /* Insert param. Insert first in the list */
    *allParams = (struct MmsAllParamsStruct *)newParam;
}

/*****************************************************************************
 * FUNCTION
 *  mma_add_param_string
 * DESCRIPTION
 *  Inserts a string param first in the list of params
 * PARAMETERS
 *  allParams        [OUT] The current list
 *  param            [IN] The param to insert
 *  strValue         [IN] The string value for the param to insert. The strValue can
 *                         be released after the call to this function
 * RETURNS
 *  void
 *****************************************************************************/
void mma_add_param_string(MmsAllParams **allParams, MmsParam param, const char *strValue)
{
    MmsAllParams *newParam = NULL;

    MMA_CALLOC(newParam, sizeof(MmsAllParams));
    newParam->param = param;
    newParam->type = MMS_PARAM_STRING;
    newParam->value.string = (unsigned char *)msf_cmmn_strdup(MSF_MODID_MMA, strValue);
    newParam->next = *allParams;  /* Insert param. Insert first in the list */
    *allParams = (MmsAllParams *)newParam;
}

/*****************************************************************************
 * FUNCTION
 *  mma_add_entry_string
 * DESCRIPTION
 *  Inserts a string entry first in the list of entries
 * PARAMETERS
 *  entryHeads        [OUT] The current list
 *  type              [IN] The type of entry to insert
 *  strValue          [IN] The string value for the entry to insert. The strValue can
 *                         be released after the call to this function
 * RETURNS
 *  void
 *****************************************************************************/
void mma_add_entry_string(MmsEntryHeader **entryHeads, MmsEntryHeaderValueType type, const char *strValue)
 {
     MmsEntryHeader *newEntry;
     MMA_CALLOC(newEntry, sizeof(MmsEntryHeader));
     newEntry->headerType = type;
     newEntry->value.wellKnownFieldName = (unsigned char *)msf_cmmn_strdup(MSF_MODID_MMA, strValue);
     newEntry->next = *entryHeads;  /* Insert entry. Insert first in the list */
     *entryHeads = newEntry;
 }

/*****************************************************************************
 * FUNCTION
 *  mma_create_body_params
 * DESCRIPTION
 *  Creates a MmsBodyParams
 * PARAMETERS
 *  targetType        [IN] The type of message that are created, see MmsBodyPartTarget
 *  currContentType   [IN] The content type if it already exists, otherwise NULL.
 *  mediaType         [IN] The media type to add as a integer, see MmsKnownMediaType.
 *  mediaString       [IN] The media type to add as a string.
 *  name        [IN]  The name of the body-part. 
 *
 * RETURNS
 *  The created MmsBodyParams
 *****************************************************************************/
MmsBodyParams *mma_create_body_params(MmsKnownMediaType mediaType, char *mediaString, 
    const unsigned char *name, MmsCharset charset)
{
    MmsBodyParams *bp;

    MMA_CALLOC(bp, sizeof(MmsBodyParams));
    bp->targetType = MMS_MULTIPART_MESSAGE;

    if (MMS_VALUE_AS_STRING != mediaType)
    {
        bp->contentType.knownValue = mediaType;
        bp->contentType.strValue = NULL;
    }
    else if (NULL != mediaString) 
    {
        bp->contentType.knownValue = MMS_VALUE_AS_STRING;
        bp->contentType.strValue = (unsigned char *)msf_cmmn_strdup(MSF_MODID_MMA, mediaString);
    }

    /* Add the name of the body-part */
    if (NULL != name)
    {
        /* Content ID */
        if(mediaString && (0 == strcmp(mediaString, MMS_MEDIA_TYPE_STRING_SMIL)))
        {
            mma_add_entry_string(&bp->entryHeader, MMS_WELL_KNOWN_CONTENT_ID, MEAlib_getSmilContentId());
            mma_add_param_int(&bp->contentType.params, MMS_CHARSET, MMS_UTF8);
        }
        else
        {
            mma_add_entry_string(&bp->entryHeader, MMS_WELL_KNOWN_CONTENT_ID, (char *)name);
        }

        /* Content location */
        mma_add_entry_string(&bp->entryHeader, MMS_WELL_KNOWN_CONTENT_LOCATION, (char *)name);

       /* Name */
#ifdef MMS_USE_NAME_PARMS
        mma_add_param_string(&bp->contentType.params, MMS_NAME, (char *)name);  /* Always set the file name */
#else
        mma_add_param_string(&bp->contentType.params, MMS_FILENAME, (char *)name);  /* Always set the file name */
#endif
    }

    if (MMS_TYPE_TEXT_PLAIN == mediaType)
    {
        mma_add_param_int(&bp->contentType.params, MMS_CHARSET, charset);	
    }

    return bp;
}

/*****************************************************************************
 * FUNCTION
 *  mma_create_name_from_mime_type
 * DESCRIPTION
 *  Create filename from mime type
 * PARAMETERS
 *  name_part      [IN]: NULL if not provided, use as name part instead of generation
 *  mime        [IN]
 * RETURNS
 *  filename
 *****************************************************************************/
char *mma_create_name_from_mime_type(const char *name_part, const char *mime)
{
    applib_mime_type_struct *entry = NULL;
	char *name = NULL;
    const char *ext = NULL;
    kal_uint32 ext_size = 0, current_time = 0;
    static kal_uint32 counter = 0; /* Initialized to zero at start-up */

    ext = mma_get_applib_ext_from_mime(mime);
    ext_size = (ext == NULL) ? 0 : strlen(ext);

    if(name_part != NULL)
    {
        /* prefix + "." + extension + NULL */
        MMA_CALLOC(name, strlen(name_part) + 1 + ext_size + 1);
        sprintf(name, "%s.%s", name_part, ext);
    }
    else  /* generate name part */
    {
        /* current-time + "." + extension + NULL */
        MMA_CALLOC(name, sizeof(MSF_UINT32) * 2 + 1 + ext_size + 1);
        current_time = MSF_TIME_GET_CURRENT();
    
        if (NULL != ext)
        {
            sprintf(name, "%lx.%s", (long)(current_time << 8) | (counter & 0xff), ext);
        }
        else  /* w/o extension */
        {
            sprintf(name, "%lx", (long)(current_time << 8) | (counter & 0xff));
        }
    
        /* Use a counter to prevent problems if the CPU is to fast, i.e., 
           the timer has not been increased between two calls, 256 calls
           to meaCreatefileName during the same time is not likely */
        ++counter;
    }
    return name;
}

/*****************************************************************************
 * FUNCTION
 *  mma_create_name_from_nonascii_name
 * DESCRIPTION
 *  Create ASCII name from non-ASCII object name
 * PARAMETERS
 *  name        [IN] non-ASCII name
 *  with_random_suffix  [IN]
 * RETURNS
 *  generated name
 *****************************************************************************/
char *mma_create_name_from_nonascii_name(const char *name, kal_bool with_random_suffix)
{
    char *ch = NULL, *new_name = NULL;
    if (name == NULL)
    {
        return NULL;
    }

    new_name = msf_cmmn_strdup(MSF_MODID_MMA, name);
    ch = new_name;
    while (*ch != '\0')
    {
        if (*ch & 0x80)
        {
            *ch = '_';  /* use '_' to replace non-ASCII char */
        }
        ch += 1;
    }

    if (with_random_suffix)  /* name.ext => name[random_part].ext */
    {
        char *new_name2 = MMA_ALLOC(strlen(new_name) + sizeof(MSF_UINT32) * 2 + 2);
        char *ext = NULL;

        ext = strrchr(new_name, '.');
        if (ext)
        {
            *ext = '\0';
            if (*(ext + 1))
            {
                ext += 1;
            }
        }

        if (ext)
        {
            sprintf(new_name2, "%s_%lx.%s", new_name, MSF_TIME_GET_CURRENT(), ext);
        }
        else
        {
            sprintf(new_name2, "%s_%lx", new_name, MSF_TIME_GET_CURRENT());
        }

        MMA_FREE(new_name);
        new_name = new_name2;
    }

    return new_name;
}

/*****************************************************************************
 * FUNCTION
 *  mma_create_object_from_mo
 * DESCRIPTION
 *  Create an object from multipart header information
 * PARAMETERS
 *  SlsMediaObjectType    [IN]
 *  slide        [IN]
 *  mo           [IN]
 * RETURNS
 *  mma_result_enum
 *****************************************************************************/
mma_object_struct *mma_create_object_from_mo(kal_uint32 msg_id, MmsBodyInfoList *mo)
{
    mma_object_struct *obj = NULL;
    SlsMediaType type = SLS_NOT_USED;
    SlsMediaObjectType gType = SLS_OBJECT_TYPE_NONE;
    const char *mime_from_type = NULL, *mime_from_name = NULL;
    char *mime = NULL;

    ASSERT(mo != NULL);
    type = mma_get_slsMediaType_from_mmsContentType(mo->contentType);
    gType = mma_get_slsMediaObjectType_from_slsMediaType(type);
    mime_from_type = mma_get_mime_type_from_mmsContentType(mo->contentType);
    mime = (char *)mime_from_type;

    MMA_CALLOC(obj, sizeof(mma_object_struct));
    ASSERT(obj != NULL);

    /* Get file name */
    if ((obj->fileName = mma_get_name_from_params(mo->contentType->params)) == NULL &&
        (obj->fileName = mma_get_name_from_entry_header(mo->entryHeader)) == NULL)
    {
        obj->fileName = mma_create_name_from_mime_type(NULL, mime);  /* cannot handle DCF case... */
    }
    else if (mma_is_supported_mime_type(mime_from_type) == KAL_FALSE)  /* Fault tolerance: use filename rather than content type to get mimetype  */
    {
        mime_from_name = mma_get_mime_type_from_filename(obj->fileName);
        if (mime_from_name != NULL && msf_cmmn_strcmp_nc(mime_from_type, mime_from_name) != 0)
        {
            type = mma_get_slsMediaType_from_mime_type(mime_from_name);
            gType = mma_get_slsMediaObjectType_from_slsMediaType(type);
            mime = (char *)mime_from_name;
        }
    }
    else /* File name extension must sync with mime type */
    {
        if (gType != SLS_OBJECT_TYPE_DRM)
        {
            mime_from_name = mma_get_mime_type_from_filename(obj->fileName);
            if (mime_from_name == NULL || msf_cmmn_strcmp_nc(mime_from_type, mime_from_name) != 0)
            {
                /* Below check is to prevent the following condition:
                 * default applib extension is *.mid; default applid mime is audio/mid
                 * if mime_from_type = audio/midi, *.midi would be renamed as *.mid causing later SLS mapping problem
                 */
                const char *mime_from_type_ext = NULL, *mime_from_name_ext = NULL;
                mime_from_type_ext = mma_get_applib_ext_from_mime(mime_from_type);
                mime_from_name_ext = mma_get_applib_ext_from_mime(mime_from_name);
                if (msf_cmmn_strcmp_nc(mime_from_type_ext, mime_from_name_ext) != 0)
                {
                    char *new_name = NULL, *ext = NULL;
                    if ((ext = strrchr(obj->fileName, '.')) != NULL)
                    {
                        *ext = '\0';
                    }
                    new_name = mma_create_name_from_mime_type(obj->fileName, mime_from_type);
                    MMA_FREE(obj->fileName);
                    obj->fileName = new_name;
                }
            }
        }
    }

    if (gType == SLS_OBJECT_TYPE_NONE && mime == NULL)
    {
        mma_free_object(&obj);
        return NULL;
    }
     
    obj->type = type;
    obj->size = mo->size;
    obj->offset = mo->startPos;
    if(gType == SLS_OBJECT_TYPE_TEXT)
    {
        obj->charset = mma_get_charset_from_params(mo->contentType->params);
    }
    obj->filePath = MMSlib_getMessageFullPath(MSF_MODID_MMA, msg_id, fldrGetFileSuffix(msg_id));
    mma_get_boundary_from_params(&obj->boundary, mo->contentType->params);

    /* Get mime type */
    if(mime != NULL)
    {
        obj->mimeType = msf_cmmn_strdup(MSF_MODID_MMA, mime);
    }
    
    /* obj->alt: no need to give value */
    /* obj->isAttachment: no need to give value */
    obj->isVirtualFile = KAL_TRUE;
    /* obj->xmlId: no need to give value */
    /* obj->xmlDrmType: no need to give value */
    
    /* obj->drmType*/
#ifdef __DRM_SUPPORT__
    if(gType == SLS_OBJECT_TYPE_DRM)  /* check the real type of the DRM object */
    {
        char *mms_path = MMSlib_getMessageFullPath(MSF_MODID_MMA, msg_id, fldrGetFileSuffix(msg_id));
        const char *mime = mma_drm_get_content_type_vf(obj->type, mms_path, obj->offset, obj->size);
        MMA_FREE(mms_path);
        if(mime == NULL)
        {
            obj->drmType = SLS_UNKNOWN;
            obj->drmMimeType = NULL;
        }
        else  /* use the real object type */
        {
            obj->drmType = mma_get_slsMediaType_from_mime_type(mime);
            obj->drmMimeType = msf_cmmn_strdup(MSF_MODID_MMA, mime);
        }
    }
#endif
    
    return obj;
}

/*****************************************************************************
 * FUNCTION
 *  mma_create_sls_object_from_mma_slide_object
 * DESCRIPTION
 *  Create a SLS object from mma object informaion
 * PARAMETERS
 *  mma_slide_object_struct    [IN]
 * RETURNS
 *  SlsMediaObject
 *****************************************************************************/
SlsMediaObject *mma_create_sls_object_from_mma_slide_object(const mma_slide_object_struct *s_obj)
{
    const char *regionType;
    SlsMediaObject *obj = NULL;

    /* Sanity check */
    if (s_obj == NULL || NULL == s_obj->obj || (NULL == s_obj->obj->fileName))
    {
        return NULL;
    }
    else
    {
        MMA_CALLOC(obj, sizeof(SlsMediaObject));
        obj->type = s_obj->obj->type;  /* type */

        /* region */
        regionType = NULL;
        switch(mma_get_slsMediaObjectType_from_slsMediaType(s_obj->obj->type))
        {
        case SLS_OBJECT_TYPE_TEXT:
            regionType = MEAlib_getSmilTextRegionName();
            obj->color = s_obj->text_color;
            break;
        case SLS_OBJECT_TYPE_IMAGE:
        case SLS_OBJECT_TYPE_VIDEO:
            regionType = MEAlib_getSmilImageRegionName();
        case SLS_OBJECT_TYPE_AUDIO:
            break;
#ifdef __DRM_SUPPORT__
        case SLS_OBJECT_TYPE_DRM:
        {
            switch (mma_get_slsMediaObjectType_from_slsMediaType(s_obj->obj->drmType))
            {
                case SLS_OBJECT_TYPE_TEXT:
                    regionType = MEAlib_getSmilTextRegionName();
                    obj->color = s_obj->text_color;
                break;
                case SLS_OBJECT_TYPE_IMAGE:
                case SLS_OBJECT_TYPE_VIDEO:
                    regionType = MEAlib_getSmilImageRegionName();
                case SLS_OBJECT_TYPE_AUDIO:
                break;
            }
            break;
        }
#endif
        case SLS_OBJECT_TYPE_NONE:
            MMA_FREE(obj);
            return NULL;
        }

        if (NULL != regionType)  /* set region */
        {
            obj->region = msf_cmmn_strdup(MSF_MODID_MMA, regionType);
        }
        else
        {
            obj->region = NULL;
        }
        
        obj->src = msf_cmmn_strdup(MSF_MODID_MMA, s_obj->obj->fileName);
        obj->beginT = s_obj->begin;  /* Begin and end time */
        obj->endT = s_obj->end;
    }
    return obj;
}


/*****************************************************************************
 * FUNCTION
 *  mma_copy_attachment_info
 * DESCRIPTION
 *  Copy the attachemnt list info 
 * PARAMETERS
 *  sourceList        [IN]        
 * RETURNS
 *****************************************************************************/
void mma_copy_attachment_info(mma_body_struct *body, SlsUnrefItemList *sourceList)
{
    mma_unref_list_struct *dest = NULL;
    mma_object_struct *obj = NULL;
    
    if (sourceList == NULL ||
        (strcmp(sourceList->contentType, MMS_MEDIA_TYPE_STRING_SMIL) == 0 && sourceList->next == NULL))
    {
        body->unref_list = NULL;
        return;
    }
    
    while (sourceList != NULL)
    {
        const char *mime_from_name = NULL;
        if (msf_cmmn_strcmp_nc(sourceList->contentType, MMS_MEDIA_TYPE_STRING_SMIL) == 0)
        {
            sourceList = sourceList->next;
            continue;
        }

        mime_from_name = mma_get_mime_type_from_filename(sourceList->fileName);
        if (strstr(MMA_OPEN_ATTACHMENT_TYPES, sourceList->contentType) != NULL ||
            (mime_from_name != NULL && strstr(MMA_OPEN_ATTACHMENT_TYPES, mime_from_name) != NULL))
        {
            obj = body->objects;
            while (obj)
            {
                if (obj->size == sourceList->size && obj->offset == sourceList->offset && 
                    msf_cmmn_strcmp_nc(obj->fileName, sourceList->fileName) == 0)
                {
                    obj->isAttachment = KAL_TRUE;
                    break;
                }
                obj = obj->next;
            }
    
            if (obj != NULL)
            {
                if (body->unref_list == NULL)
                {
                    MMA_CALLOC(body->unref_list, sizeof(mma_unref_list_struct));
                    dest = body->unref_list;
                }
                else
                {
                    MMA_CALLOC(dest->next, sizeof(mma_unref_list_struct));
                    dest = dest->next;
                }
                dest->attachment = obj;
            }
        }
        sourceList = sourceList->next;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mma_copy_sls_root_layout
 * DESCRIPTION
 *  Copies an SlsRootLayout struct
 * PARAMETERS
 *  source     [IN] Source data
 *  dest       [OUT] Destination data
 * RETURNS
 *****************************************************************************/
void mma_copy_sls_root_layout(const SlsRootLayout *source, SlsRootLayout *dest)
{
	if (source == NULL || dest == NULL) 
    {
        return;
    }

    if (source->bgColor != SLS_COLOR_NOT_USED)
    {
        dest->bgColor = source->bgColor;
    }
    else
    {
        dest->bgColor = MEAlib_getDefaultSmilBgColor();
    }

	dest->cx.type = source->cx.type;
	dest->cx.value = source->cx.value;
	dest->cy.type = source->cy.type;
	dest->cy.value = source->cy.value;
}

/*****************************************************************************
 * FUNCTION
 *  mma_copy_sls_region
 * DESCRIPTION
 *  Copies an sls region
 * PARAMETERS
 *  source        [IN] The source region
 *  destination   [OUT] The destination region       
 * RETURNS
 *****************************************************************************/
void mma_copy_sls_region(const SlsRegion *source, SlsRegion *destination )
{
    if (source == NULL || destination == NULL) 
    {
        return;
    }
    
    destination->position.cx.type = source->position.cx.type;
    destination->position.cx.value= source->position.cx.value;
    destination->position.cy.type = source->position.cy.type;
    destination->position.cy.value= source->position.cy.value;

    destination->size.cx.type = source->size.cx.type;
    destination->size.cx.value= source->size.cx.value;
    destination->size.cy.type = source->size.cy.type;
    destination->size.cy.value= source->size.cy.value;

    destination->fit= source->fit;
}

/*****************************************************************************
 * FUNCTION
 *  mma_copy_slide_info
 * DESCRIPTION
 *  Copy the attachemnt list info
 * PARAMETERS
 *  sourceList        [IN]        
 * RETURNS
 *****************************************************************************/
void mma_copy_slide_info(mma_body_struct *body, const SlsSlideInfo *slsInfo)
{
    mma_slide_struct *slide = NULL;
    mma_object_struct *obj = NULL;

    ASSERT(body != NULL);
    if (slsInfo == NULL)
    {
        return;
    }
    
    MMA_CALLOC(slide, sizeof(mma_slide_struct));
    slide->duration = slsInfo->duration;

    /* Image: begin, end, id, text_color: no need to give value*/
	if( mma_is_valid_slsMediaType(
		mma_get_mime_type_from_filename(slsInfo->image.fileName),
		SLS_OBJECT_TYPE_IMAGE) == TRUE)
	{
	    obj = body->objects;
	    while (obj)
	    {
	        if (obj->size == slsInfo->image.size && obj->offset == slsInfo->image.offset && 
	            msf_cmmn_strcmp_nc(obj->fileName, slsInfo->image.fileName) == 0)
	        {
	            ASSERT(obj->isAttachment == KAL_FALSE);
	            break;
	        }
	        obj = obj->next;
	    }

	    if (obj != NULL)
	    {
	        slide->image.obj = obj;
	        mma_copy_sls_region(&slsInfo->image.region, &slide->image.region);
	    }
	}
    /* Video: begin, end, id, text_color: no need to give value*/
	if( mma_is_valid_slsMediaType(
		mma_get_mime_type_from_filename(slsInfo->video.fileName),
		SLS_OBJECT_TYPE_VIDEO) == TRUE)
	{
	    obj = body->objects;
	    while (obj)
	    {
	        if (obj->size == slsInfo->video.size && obj->offset == slsInfo->video.offset && 
	            msf_cmmn_strcmp_nc(obj->fileName, slsInfo->video.fileName) == 0)
	        {
	            ASSERT(obj->isAttachment == KAL_FALSE);
	            break;
	        }
	        obj = obj->next;
	    }

	    if (obj != NULL)
	    {
	        slide->video.obj = obj;
	        mma_copy_sls_region(&slsInfo->video.region, &slide->video.region);
	    }
	}    
    /* Audio: begin, end, id, text_color: no need to give value*/
	if( mma_is_valid_slsMediaType(
		mma_get_mime_type_from_filename(slsInfo->audio.fileName),
		SLS_OBJECT_TYPE_AUDIO) == TRUE)
	{
	    obj = body->objects;
	    while (obj)
	    {
	        if (obj->size == slsInfo->audio.size && obj->offset == slsInfo->audio.offset && 
	            msf_cmmn_strcmp_nc(obj->fileName, slsInfo->audio.fileName) == 0)
	        {
	            ASSERT(obj->isAttachment == KAL_FALSE);
	            break;
	        }
	        obj = obj->next;
	    }
	    
	    if (obj != NULL)
	    {
	        slide->audio.obj = obj;
	    }
	}
    /* Text: begin, end, id, text_color: no need to give value*/
	if( mma_is_valid_slsMediaType(
		mma_get_mime_type_from_filename(slsInfo->text.fileName),
		SLS_OBJECT_TYPE_TEXT) == TRUE)
	{
	    obj = body->objects;
	    while (obj)
	    {
	        if (obj->size == slsInfo->text.size && obj->offset == slsInfo->text.offset && 
	            msf_cmmn_strcmp_nc(obj->fileName, slsInfo->text.fileName) == 0)
	        {
	            ASSERT(obj->isAttachment == KAL_FALSE);
	            break;
	        }
	        obj = obj->next;
	    }
	    
	    if (obj != NULL)
	    {
	        slide->text.obj = obj;
	        slide->text.text_color = slsInfo->text.color;
	        mma_copy_sls_region(&slsInfo->text.region, &slide->text.region);
	    }
	}
    /* chain the slide to the end of the list*/
    if (body->slides == NULL)
    {
        body->slides = slide;
    }
    else
    {
        body->current_slide->next = slide;
    }
    body->current_slide = slide;

    if(body->layout == MMA_LAYOUT_NONE) /* One layout for all slides */
    {
       body->layout = mma_get_slide_layout(slide);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mma_insert_addr_to_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  addrType        [IN]        
 *  address         [?]         
 *  mmsAddr         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
void mma_insert_addr_to_list(MmsAddressType addrType, char *address, MmsAddressList **list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MmsAddressList *item = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (address == NULL || list == NULL)
    {
        return ;
    }

    MMA_CALLOC(item, sizeof(MmsAddressList));
    item->current.addrType = addrType;
    item->current.address = msf_cmmn_strdup(MSF_MODID_MMA, address);
    ASSERT(item->current.address);

    if (*list == NULL)
    {
        *list = item;
    }
    else
    {
        MmsAddressList *ptr = *list;

        while (ptr->next)
        {
            ptr = ptr->next;
        }
        ptr->next = item;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mma_insert_slide
 * DESCRIPTION
 *  Append an empty slide to body->current_slide
 * PARAMETERS
 *  body        [IN]        
 * RETURNS
 *  mma_slide_struct
 *****************************************************************************/
mma_slide_struct *mma_insert_slide(mma_body_struct *body)
{
    mma_slide_struct *slide = NULL;
    mma_setting_struct sliding;
        
    MMA_CALLOC(slide, sizeof(mma_slide_struct));
    if(body->current_slide != NULL)
    {
        slide->next = body->current_slide->next;
        body->current_slide->next = slide;
    }
    else
    {
        body->slides = slide;
        slide->next = NULL;
    }

    mma_conf_get_sliding_time(&sliding);
    slide->duration = sliding.value;
    
    body->slide_no++;
    body->current_slide = slide;
    return slide;
} /* mma_insert_slide */

/*****************************************************************************
 * FUNCTION
 *  mma_insert_object_to_tail
 * DESCRIPTION
 *  Insert an empty slide
 * PARAMETERS
 *  body        [IN]        
 * RETURNS
 *  mma_slide_struct
 *****************************************************************************/
mma_object_struct *mma_insert_object_to_tail(mma_body_struct *body)
{
    mma_object_struct *obj = NULL;

    ASSERT(body != NULL);
    MMA_CALLOC(obj, sizeof(mma_object_struct));
    
    if(body->objects != NULL)
    {
        mma_object_struct *ptr = body->objects;
        for(; ptr->next != NULL; ptr = ptr->next);
        ptr->next = obj;
    }
    else
    {
        body->objects = obj;
    }

    return obj;
}

/*****************************************************************************
 * FUNCTION
 *  mma_insert_unref_item_to_tail 
 * DESCRIPTION
 *  Insert an attachment (mainly for mixed-to-SMIL conversion)
 * PARAMETERS
 *  body        [IN/OUT]
 *  obj         [IN]
 * RETURNS
 *  mma_result_enum
 *****************************************************************************/
mma_unref_list_struct *mma_insert_unref_item_to_tail(mma_body_struct *body, mma_object_struct *obj)
{
    ASSERT(body != NULL && obj != NULL);
    if(mma_get_unref_item_count(body->unref_list) < wap_custom_get_max_mms_attachment())
    {
        mma_unref_list_struct *curr = NULL;

        MMA_CALLOC(curr, sizeof(mma_unref_list_struct));
        curr->attachment = obj;
        curr->next = NULL;

        if(body->unref_list == NULL)
        {
            body->unref_list = curr;
        }
        else  /* chain to list */
        {
            mma_unref_list_struct *ptr = NULL;
            for(ptr = body->unref_list; ptr->next != NULL; ptr = ptr->next);
            ptr->next = curr;
        }
        return curr;
    }
    
    return NULL;
}

/*****************************************************************************
 * FUNCTION
 *  mma_insert_slide_obj
 * DESCRIPTION
 *  Insert an object to the slide (mainly for mixed-to-SMIL conversion)
 * PARAMETERS
 *  SlsMediaObjectType    [IN]
 *  slide        [IN]
 *  mo           [IN]
 * RETURNS
 *  mma_result_enum
 *****************************************************************************/
void mma_insert_slide_obj(SlsMediaObjectType gType, mma_slide_struct *slide, mma_object_struct *obj)
{
    ASSERT(slide != NULL && obj != NULL && (gType == SLS_OBJECT_TYPE_TEXT || gType == SLS_OBJECT_TYPE_IMAGE ||
        gType == SLS_OBJECT_TYPE_VIDEO || gType == SLS_OBJECT_TYPE_AUDIO));

    if((gType == SLS_OBJECT_TYPE_TEXT && slide->text.obj != NULL) ||
        (gType == SLS_OBJECT_TYPE_IMAGE && slide->image.obj != NULL) ||
        (gType == SLS_OBJECT_TYPE_VIDEO && slide->video.obj != NULL) ||
        (gType == SLS_OBJECT_TYPE_AUDIO && slide->audio.obj != NULL))
    {
        return;
    }
        
    switch(gType)
    {
    case SLS_OBJECT_TYPE_TEXT:
        slide->text.text_color = MEAlib_getDefaultSmilFgColor();
        slide->text.obj = obj;
        break;
    case SLS_OBJECT_TYPE_AUDIO:
        slide->audio.obj = obj;
        break;
    case SLS_OBJECT_TYPE_IMAGE:
        slide->image.obj = obj;
        break;
    case SLS_OBJECT_TYPE_VIDEO:
        slide->video.obj = obj;
        break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mma_is_ascii_text
 * DESCRIPTION
 *  Check if the text file is all ASCII char
 * PARAMETERS
 *  filename    [IN]
 * RETURNS
 *  TRUE/FALSE
 *****************************************************************************/
kal_bool mma_is_ascii_text(const char *filepath)
{
    int fh = MSF_FILE_OPEN(MSF_MODID_MMA, filepath, MSF_FILE_SET_RDONLY, 0);
    char *buffer = NULL;
    int filesize = MSF_FILE_GETSIZE(filepath);
    int i = 0;
    
    if (fh < 0)
    {
        return FALSE;
    }
    
    MMA_CALLOC(buffer, filesize);
    ASSERT(MSF_FILE_READ(fh, buffer, filesize) == filesize);
    for (i = 0; i < filesize; i++)
    {
        if (*(buffer + i) & 0x80)
        {
            MSF_FILE_CLOSE(fh);
            return FALSE;
        }
    }
    MSF_FILE_CLOSE(fh);
    return TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mma_is_ascii_string
 * DESCRIPTION
 *  Check if the string is all ASCII char
 * PARAMETERS
 *  str    [IN]
 * RETURNS
 *  TRUE/FALSE
 *****************************************************************************/
kal_bool mma_is_ascii_string(const char *str)
{
    int i, len = strlen(str);
    
    for (i = 0; i < len; i++)
    {
        if (*(str + i) & 0x80)
        {
            return FALSE;
        }
    }
    return TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mma_is_restricted_type
 * DESCRIPTION
 *  Check if the file is restricted type
 * PARAMETERS
 *  filename    [IN]
 * RETURNS
 *  TRUE: restricted; FALSE: non-restricted
 *****************************************************************************/
kal_bool mma_is_restricted_type(const char *filename)
{
    const char *restrictedTypes = MEAlib_getOpenRestrictedAttachmentType();
    const char *restrictedImageTypes = MEAlib_getOpenRestrictedImageType();
    const char *strMimeType = NULL;
#ifdef __DRM_SUPPORT__
    mma_drm_method_enum drmMethod = MMA_DRM_METHOD_NONE;
#endif

    ASSERT(filename != NULL);
    if(MSF_FILE_GETSIZE(filename) > MMA_RESTRICTED_MESSAGE_SIZE)
    {
        return KAL_FALSE;
    }

    strMimeType = mma_get_mime_type_from_filename(filename);
#ifdef __DRM_SUPPORT__
    if(msf_cmmn_strcmp_nc(strMimeType, "application/vnd.oma.drm.content") == 0)  /* check *.dcf file or DRM segment in MMS */
    {
        return KAL_FALSE;
    }
    else if(msf_cmmn_strcmp_nc(strMimeType, "application/vnd.oma.drm.message") == 0)  /* check *.dm file or DRM segment in MMS */
    {
        strMimeType = mma_drm_get_content_type(SLS_DRM_MESSAGE, filename);  /* processed */
        drmMethod = mma_drm_get_method_type(filename);
        if(drmMethod == MMA_DRM_METHOD_COMBINED_DELIVERY)
        {
            return KAL_FALSE;
        }
    }
    else  /* check normal extension files, ex. *.jpg, mostly processed file in File Manager */
    {
        drmMethod = mma_drm_get_method_type(filename);
        if(drmMethod == MMA_DRM_METHOD_COMBINED_DELIVERY || drmMethod == MMA_DRM_METHOD_SEPARATE_DELIVERY)
        {
            return KAL_FALSE;
        }
        else if(drmMethod == MMA_DRM_METHOD_FORWARD_LOCK)
        {
            strMimeType = mma_drm_get_content_type(SLS_DRM_MESSAGE, filename);
        }
    }
#endif

    if(strMimeType != NULL && strstr(restrictedTypes, strMimeType))
    {
        /* Image resolution check  */
        if(strstr(restrictedImageTypes, strMimeType))
        {
            MsfSize dimension = {0, 0};
#ifdef __DRM_SUPPORT__
            /* TODO: FL DRM image resolution check is absent. Now we rely on FL DRM filtering later...) */
            if(drmMethod == MMA_DRM_METHOD_FORWARD_LOCK) 
            {
                return KAL_TRUE;
            }
#endif
            if(HDIa_widgetExtImageFileGetSize((char *)filename, &dimension) != TRUE ||
                dimension.width * dimension.height > MMA_RESTRICTED_RESOLUTION)
            {
                return KAL_FALSE;
            }
        }

        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mma_is_restricted_type_vf
 * DESCRIPTION
 *  Check if the virtual file is restricted type
 * PARAMETERS
 *  filename    [IN]
 *  mime        [IN]
 * RETURNS
 *  TRUE: restricted; FALSE: non-restricted
 *****************************************************************************/
kal_bool mma_is_restricted_type_vf(const char *filename, const char *mime, kal_uint32 offset, kal_uint32 size)
{
    char *vFileName = NULL;
    int fileHandle = 0;
    kal_bool isRestricted = KAL_FALSE;

    /*generate virtual file */
    if(filename == NULL || size == 0 || 
        (fileHandle = MSF_FILE_OPEN(MSF_MODID_MMA, filename, MSF_FILE_SET_RDONLY, 0)) < 0)
    {
        return KAL_FALSE;
    }

    MMA_CALLOC(vFileName, WIDGET_RAWFILE_NAMELEN);
    ASSERT(vFileName != NULL);

    if(HDIa_fileGenVirtualFileName(fileHandle, vFileName, WIDGET_RAWFILE_NAMELEN, offset, size) == HDI_FILE_OK)
    {
        /* change virtual file extension .r to original extension */
        char *name = NULL;
        char *ext = strrchr(vFileName, '.');
        *ext = '\0';
        name = mma_create_name_from_mime_type(vFileName, mime);
        MMA_FREE(vFileName);
        vFileName = name;
        if(mma_is_restricted_type((const char *)vFileName) == KAL_TRUE)
        {
            isRestricted =KAL_TRUE;
        }
    }

    MMA_FREE(vFileName);
    MSF_FILE_CLOSE(fileHandle);
    return isRestricted;
}

/*****************************************************************************
 * FUNCTION
 *  mma_is_supported_mime_type
 * DESCRIPTION
 *  To check the mime type is supported on the project.
 * PARAMETERS
 *  mime        [IN]        
 * RETURNS
 * MSF_BOOL
 *****************************************************************************/
kal_bool mma_is_supported_mime_type(const char *mime)
{
    if(mime != NULL)
    {
        applib_mime_type_struct *entry = NULL;

        if ((entry = mime_type_look_up((kal_char *)mime, NULL, 0, 0)) != NULL)
        {
            return KAL_TRUE;
        }
    }
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mma_is_valid_slsMediaType
 * DESCRIPTION
 *  To check the type is a valid slsMediaType.
 * PARAMETERS
 *  mime        [IN]        
 *  sMediaType  [IN]
 * RETURNS
 * MSF_BOOL
 *****************************************************************************/
MSF_BOOL mma_is_valid_slsMediaType(const char *mime, SlsMediaObjectType sMediaType)
{
    kal_uint32 i = 0;
    
    if(mime != NULL)
    {
        while(slsSupportedMediaTypes[i].mediaType != SLS_NOT_USED)
        {
            if(msf_cmmn_strcmp_nc(mime, slsSupportedMediaTypes[i].mimeType) == 0)
            {
            	if (slsSupportedMediaTypes[i].objectType == sMediaType)
	                return TRUE;
				else
					return FALSE;
            }
            i++;
        }
    }
    return FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mma_is_valid_address
 * DESCRIPTION
 *  Check if the address is valid address for editor
 * PARAMETERS
 *  addr        [IN]
 * RETURNS
 *  TRUE if the address is valid
 *****************************************************************************/
MSF_BOOL mma_is_valid_address(MmsAddress *addr)
{
    applib_address_node_struct *plmn = NULL;

    if (addr == NULL || addr->address == NULL)
    {
        return FALSE;
    }
        
    switch (addr->addrType)
    {
    case MMS_PLMN:
        plmn = applib_get_address_list_from_text(APPLIB_ADDR_TYPE_PHONENUMBER, mma_mem_calloc, mma_mem_free, 
            addr->address, strlen(addr->address));
        if (plmn == NULL)
        {
            return FALSE;
        }
        else if (strcmp(addr->address, plmn->data) != 0)
        {
            applib_free_address_list(&plmn, mma_mem_free);
            return FALSE;
        }
        applib_free_address_list(&plmn, mma_mem_free);
        break;
        
    case MMS_EMAIL:
        if (strchr(addr->address, '@') == NULL)
        {
            return FALSE;
        }
        else if (applib_is_valid_email_local_part(addr->address, strchr(addr->address, '@') - addr->address) == KAL_FALSE)
        {
            return FALSE;
        }
        else if (applib_is_valid_email_domain_name(strchr(addr->address, '@') + 1) == KAL_FALSE)
        {
            return FALSE;
        }
        break;
        
    case MMS_IPV4:
    default:
        return FALSE;
    }
    return TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mma_remove_invalid_address
 * DESCRIPTION
 *  Remove illegal and unsupported addresses
 * PARAMETERS
 *  header        [IN/OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void mma_remove_invalid_address(MmsGetHeader *header)
{
    MmsAddressList *list = NULL, *prev = NULL;

    if (header == NULL)
    {
        return;
    }
    
    /* From */
    if (mma_is_valid_address(&header->from) == FALSE)
    {
        MMA_FREE(header->from.address);
        header->from.address = NULL;
    }

    /* To */
    list = header->to;
    prev = NULL;
    while (list)
    {
        /* Remove non-PLMN/EMAIL type address */
        if (mma_is_valid_address(&list->current) == FALSE)
        {
            if (prev == NULL)
            {
                header->to = list->next;
                list->next = NULL;
                freeMmsAddressList(MSF_MODID_MMA, list);
                list = header->to;
            }
            else
            {
                prev->next = list->next;
                list->next = NULL;
                freeMmsAddressList(MSF_MODID_MMA, list);
                list = prev->next;
            }
        }
        else
        {
            prev = list;
            list = list->next;
        }
    }

    /* Cc */
    list = header->cc;
    prev = NULL;
    while (list)
    {
        /* Remove non-PLMN/EMAIL type address */
        if (mma_is_valid_address(&list->current) == FALSE)
        {
            if (prev == NULL)
            {
                header->cc = list->next;
                list->next = NULL;
                freeMmsAddressList(MSF_MODID_MMA, list);
                list = header->cc;
            }
            else
            {
                prev->next = list->next;
                list->next = NULL;
                freeMmsAddressList(MSF_MODID_MMA, list);
                list = prev->next;
            }
        }
        else
        {
            prev = list;
            list = list->next;
        }
    }

    /* Bcc */
    list = header->bcc;
    prev = NULL;
    while (list)
    {
        /* Remove non-PLMN/EMAIL type address */
        if (mma_is_valid_address(&list->current) == FALSE)
        {
            if (prev == NULL)
            {
                header->bcc = list->next;
                list->next = NULL;
                freeMmsAddressList(MSF_MODID_MMA, list);
                list = header->bcc;
            }
            else
            {
                prev->next = list->next;
                list->next = NULL;
                freeMmsAddressList(MSF_MODID_MMA, list);
                list = prev->next;
            }
        }
        else
        {
            prev = list;
            list = list->next;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mma_remove_slide_by_index
 * DESCRIPTION
 *  Remove a slide by index (0~)
 * PARAMETERS
 *  body        [IN]
 *  index       [IN]
 * RETURNS
 *  mma_slide_struct
 *****************************************************************************/
void mma_remove_slide_by_index(mma_body_struct *body, kal_uint32 index)
{
    mma_slide_struct *curr = NULL, *prev = NULL;
    kal_uint32 i = 0;

    if (body->slides == NULL)
    {
        return;
    }
    
    curr = body->slides;
    while (curr != NULL)
    {
        if (i == index)
        {
            break;
        }
        prev = curr;
        curr = curr->next;
        i++;
    }

    if (curr == NULL)  /* not found */
    {
        return;
    }
    
    if (prev == NULL)
    {
        body->slides = curr->next;
    }
    else
    {
        prev->next = curr->next;
    }
    curr->image.obj = NULL;
    curr->video.obj = NULL;
    curr->audio.obj = NULL;
    curr->text.obj = NULL;
    MMA_FREE(curr);
    body->slide_no--;
    body->current_slide = body->slides;
} /* mma_remove_slide_by_index */

/*****************************************************************************
 * FUNCTION
 *  mma_remove_object_in_slide
 * DESCRIPTION
 *  Remove object reference in slide structure
 * PARAMETERS
 *  list        [IN/OUT]
 *  obj       [IN]
 * RETURNS
 *****************************************************************************/
void mma_remove_object_in_slide(mma_slide_struct *list, mma_object_struct *obj)
{
    mma_slide_struct *slide = list;
    ASSERT(obj != NULL);
    while(slide != NULL)
    {
        if(slide->image.obj == obj)
        {
            slide->image.obj = NULL;
            memset(&slide->image, 0x0, sizeof(mma_slide_object_struct));
        }
        if(slide->video.obj == obj)
        {
            slide->video.obj = NULL;
            memset(&slide->video, 0x0, sizeof(mma_slide_object_struct));
        }
        if(slide->audio.obj == obj)
        {
            slide->audio.obj = NULL;
            memset(&slide->audio, 0x0, sizeof(mma_slide_object_struct));
        }
        if(slide->text.obj == obj)
        {
            slide->text.obj = NULL;
            memset(&slide->text, 0x0, sizeof(mma_slide_object_struct));
        }
        slide = slide->next;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mma_remove_object_in_unref_list
 * DESCRIPTION
 *  Remove object reference in unref list structure
 * PARAMETERS
 *  list        [IN/OUT]
 *  obj       [IN]
 * RETURNS
 *****************************************************************************/
void mma_remove_object_in_unref_list(mma_unref_list_struct **list, mma_object_struct *obj)
{
    mma_unref_list_struct *unref = NULL;

    ASSERT(obj != NULL && list != NULL);
    unref = *list;
    while(unref != NULL)
    {
        mma_unref_list_struct *tmp_u = unref->next;
        if(unref->attachment == obj)
        {
            if(unref == *list)
            {
                *list = unref->next;
                unref->next = NULL;
            }
            else
            {
                mma_unref_list_struct *prev = NULL;
                for(prev = *list; prev->next != unref && prev->next != NULL; prev = prev->next);
                if(prev->next == NULL)
                {
                    return;
                }
                else
                {
                    prev->next = unref->next;
                    unref->next = NULL;
                }
            }

            unref->attachment = NULL;
            MMA_FREE(unref);
        }
        unref = tmp_u;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mma_remove_object_list_entry
 * DESCRIPTION
 *  Remove object entry from object list w/o deallocating the structure
 * PARAMETERS
 *  list        [IN/OUT]
 *  entry       [IN]
 * RETURNS
 *****************************************************************************/
void mma_remove_object_list_entry(mma_object_struct **list, mma_object_struct *entry)
{
    mma_object_struct *ptr = NULL;
    ASSERT(list != NULL && entry != NULL);

    if(*list == entry)
    {
        *list = entry->next;
        entry->next = NULL;
    }
    else
    {
        for(ptr = *list; ptr->next != entry && ptr->next != NULL; ptr = ptr->next);
        if(ptr->next == NULL)
        {
            return;
        }
        else
        {
            ptr->next = entry->next;
            entry->next = NULL;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mma_update_unref_list
 * DESCRIPTION
 *  Sync unref list and slide info
 * PARAMETERS
 *  body        [IN/OUT]
 * RETURNS
 *****************************************************************************/
void mma_update_unref_list(mma_body_struct *body)
{
    mma_object_struct *obj = NULL;

    obj = body->objects;

    while (obj)
    {
        mma_slide_struct *slide = body->slides;
        kal_bool is_attachment = KAL_TRUE;

        while (slide)
        {
            if (slide->image.obj == obj || slide->video.obj == obj || slide->audio.obj == obj || slide->text.obj == obj)
            {
                is_attachment = KAL_FALSE;
                break;
            }
            slide = slide->next;
        }

        if (is_attachment == KAL_TRUE && obj->isAttachment == KAL_FALSE)
        {
            obj->isAttachment = KAL_TRUE;
            mma_insert_unref_item_to_tail(body, obj);
        }
        else if (is_attachment == KAL_FALSE && obj->isAttachment == KAL_TRUE)
        {
            ASSERT(0);
        }
        
        obj = obj->next;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mma_free_object
 * DESCRIPTION
 *  Dealloctes the object structure
 * PARAMETERS
 *  obj        [IN]        
 * RETURNS
 *****************************************************************************/
void mma_free_object(mma_object_struct **obj)
{
    if(obj != NULL && *obj != NULL)
    {
        MMA_FREE((*obj)->fileName);
        MMA_FREE((*obj)->filePath);
        MMA_FREE((*obj)->boundary);
        MMA_FREE((*obj)->mimeType);
        MMA_FREE((*obj)->alt);
#ifdef __DRM_SUPPORT__
        MMA_FREE((*obj)->drmMimeType);
#endif
        MMA_FREE(*obj);
        *obj = NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mma_free_sls_media_object
 * DESCRIPTION
 *  Dealloctes the SlsMediaObject structure
 * PARAMETERS
 *  obj        [IN] The media object to free
 * RETURNS
 *****************************************************************************/
void mma_free_sls_media_object(SlsMediaObject **object)
{
    if (object == NULL || *object == NULL)
    {
        return;
    }
    MMA_FREE((*object)->region);
    MMA_FREE((*object)->src);
    MMA_FREE(*object);
    *object = NULL;
}

/*****************************************************************************
 * FUNCTION
 *  mma_free_object_list
 * DESCRIPTION
 *  Dealloctes the object list structure
 * PARAMETERS
 *  slide        [IN]        
 * RETURNS
 *****************************************************************************/
void mma_free_object_list(mma_object_struct **obj)
{
    mma_object_struct *curr = NULL, *tmp = NULL;
    if(obj != NULL && *obj != NULL)
    {
        curr = *obj;
        while(curr != NULL)
        {
            tmp = curr->next;
            mma_free_object(&curr);
            /* Next item */
            curr = tmp;
        }
        curr = NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mma_free_slide_list
 * DESCRIPTION
 *  Dealloctes the slide structure
 * PARAMETERS
 *  slide        [IN]        
 * RETURNS
 *****************************************************************************/
void mma_free_slide_list(mma_slide_struct **slide)
{
    mma_slide_struct *curr = NULL, *tmp = NULL;
    if(slide != NULL && *slide != NULL)
    {
        curr = *slide;
        while(curr != NULL)
        {
            curr->image.obj = NULL;
            curr->video.obj = NULL;
            curr->audio.obj = NULL;
            curr->text.obj = NULL;
            /* Next item */
            tmp = curr;
            curr = curr->next;
            MMA_FREE(tmp);
        }
        curr = NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mma_free_unref_list
 * DESCRIPTION
 *  Dealloctes the attachment list
 * PARAMETERS
 *  list        [IN]        
 * RETURNS
 *****************************************************************************/
void mma_free_unref_list(mma_unref_list_struct **list)
{
    mma_unref_list_struct *current;
    mma_unref_list_struct *tmp;
    if ((NULL != list) && (NULL != *list))
    {
        current = *list;
        while(NULL != current)
        {
            current->attachment = NULL;
            /* Next item */
            tmp = current;
            current = current->next;
            MMA_FREE(tmp);
        }
        *list = NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mma_free_body_params
 * DESCRIPTION
 *  Dealloctes a #MmsBodyParams data structure
 * PARAMETERS
 *  bodyParams        [IN] The body param to release. The pointer is set to NULL
 * RETURNS
 *  void
 *****************************************************************************/
void mma_free_body_params(MmsBodyParams **bodyParams)
{
    MmsAllParams *param;
    MmsAllParams *tmpParam;
    MmsEntryHeader *entry;
    MmsEntryHeader *tmpEntry;

    if (NULL != *bodyParams)
    {
        /* Free params */
        param = (*bodyParams)->contentType.params;
        MMA_FREE((*bodyParams)->contentType.strValue);
        while (NULL != param)
        {
            if (MMS_PARAM_STRING == param->type)
            {
                MMA_FREE(param->value.string);
            }
            tmpParam = param;
            param = param->next;
            MMA_FREE(tmpParam);
        }
        /* Free entries */
        entry = (*bodyParams)->entryHeader;
        while (NULL != entry)
        {
            /* Free content ID or content location string */
            if ( (MMS_WELL_KNOWN_CONTENT_ID == entry->headerType) ||
                 (MMS_WELL_KNOWN_CONTENT_LOCATION == entry->headerType))
            {
                MMA_FREE(entry->value.wellKnownFieldName);
            }
            tmpEntry = entry;
            entry = entry->next;
            MMA_FREE(tmpEntry);
        }
        MMA_FREE(*bodyParams);
        *bodyParams = NULL;
    }
}

