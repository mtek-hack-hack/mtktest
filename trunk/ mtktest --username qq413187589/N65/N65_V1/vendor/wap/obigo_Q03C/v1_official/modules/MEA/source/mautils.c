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
/*
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2004.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Teleca Mobile Technologies AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Teleca Mobile Technologies AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */

/* !\file mautils.c
 * Utility functions for MEA.
 */

/* MSF */
#include "msf_mem.h"
#include "msf_def.h"
#include "msf_cmmn.h"
#include "msf_lib.h"
#include "msf_core.h"
#include "msf_log.h"
#include "msf_chrs.h"
#include "msf_hdr.h"
#include "msf_wid.h"
#include "msf_file.h"  /* MSF_FILE_SET_RDONLY */

/* MMS */
#include "mms_def.h"
#include "mms_cfg.h"
#include "mms_if.h"  /* MmsMessageFolderInfo */
#include "mmsl_if.h"  /* MMSlib_getMessageFullPath */
#include "msig.h"
#include "fldmgr.h"  /* fldrXXX() */

/* SLS */
#include "sls_cfg.h"
#include "sls_if.h"

/* MEA */
#include "mea_cfg.h"
#include "mea_def.h"
#include "maintsig.h"
#include "matypes.h"
#include "mamem.h"
#include "mautils.h"
#include "maintsig.h"
#include "maaddr.h"
#include "maintsig.h"
#include "mea_rc.h"
#include "mamoh.h"  /* for meaGetMoReferenceCount */
#include "mamv.h"  /* for meaMMCGetCurrentActiveMsg */
#ifdef __DRM_SUPPORT__
#include "msf_mime.h" //for msf_mime_ext_to_mime
#include "fs_type.h"
#include "../../drm/include/drm_def.h"
#include "../../drm/include/drm_gprot.h"
#endif /* __DRM_SUPPORT__ */
#include "widget.h"  /* WIDGET_RAWFILE_NAMELEN */
#include "widget_extension.h"

#include "app_datetime.h"
#include "wgui_datetime.h"
#include "DateTimeType.h"

/******************************************************************************
 * Data-types
 *****************************************************************************/

/*! \struct MeaCharsetConv
 *	Structure for handling character set type conversin.
 */
typedef struct
{
#ifdef WAP_SUPPORT
    MmsCharset msfCharset;
    MSF_UINT32 mmsCharset;
#else
    MSF_UINT32 msfCharset;
    MmsCharset mmsCharset;
#endif /* WAP_SUPPORT */
}MeaCharsetConv;

/******************************************************************************
 * Constants
 *****************************************************************************/
#ifdef WAP_SUPPORT
#define MEA_MAX_DATE_SIZE               50 /* !< Maximum buffer size for date                                                 conversion */
#endif

#define MEA_MAX_ADDRS_STRLEN        300

/*! File filter for media objects */
/*lint -e{708} */
static const MeaMediaObjects supportedMediaObjects[] = MEA_CFG_MEDIA_OBJECTS;

/*! Extended supported attachment types for MEA */
static const MeaExtAttachmentType supportedExtAttachmentTypes[] = MEA_CFG_EXT_ATTACHMENT_MEDIA_TYPES;

/*! Supported character sets for the MEA */
static const MeaCharsetConv supportedCharsets[] = MEA_CFG_SUPPORTED_CHARSETS;

/*! Defines the optional UTF-8 identifier */
#define MEA_UTF8_BOM                    "\xEF\xBB\xBF"

/******************************************************************************
 * Prototypes
 *****************************************************************************/
static void handleUtf8Bom(char *str);

/******************************************************************************
 * Extern
 *****************************************************************************/
extern MSF_BOOL MMS_FILE_OPEN_BLOCK_FLAG;
extern MmsMessageFolderInfo *fldrMgrGetMsgInfo(MSF_UINT32 msgId);
/******************************************************************************
 * Function implementation
 *****************************************************************************/

/*!
 * \brief free all memory of a MmsContentType
 * 
 * \param params The content type parameters to free
 *****************************************************************************/
void meaFreeMmsContentTypeParams(MmsAllParams *params)
{
    MmsAllParams *paramPointer = NULL;  
    MSF_BOOL doFree = FALSE;
    
    while (params != NULL)
    {
        paramPointer = params->next;
        MEA_FREE(params->key);
        params->key = NULL;
        if (params->type == MMS_PARAM_STRING)
        {
            MEA_FREE(params->value.string);
            params->value.string = NULL;
        } /* if */
        
        if (!doFree)
        {
            /* do not delete first */
            doFree = TRUE;
        }
        else
        {
            MEA_FREE(params);
        } /* if */
        
        params = paramPointer;
    } /* while */
} /* freeMmsContentTypeParams */

/*!
 * \brief free all memory of a MmsContentType
 * 
 * \param contentType The content type to free
 *****************************************************************************/
void meaFreeMmsContentType(MmsContentType *contentType)
{
    if (contentType == NULL) /* get out of here */ 
    {
        return; 
    }  /* if */

    MEA_FREE(contentType->strValue);
    contentType->strValue = NULL;
    if (contentType->params)
    {
        meaFreeMmsContentTypeParams(contentType->params);
        MEA_FREE(contentType->params);
        contentType->params = NULL;
    } /* if */
   
} /*freeMmsContentType*/

/*!
 * \brief Copies an MmsContentType field
 *
 * \param toContent Destination (Must allocate memory before this call)
 * \param fromContent Source
 *****************************************************************************/
void meaCopyContentType(MmsContentType *toContent, 
    const MmsContentType *fromContent)
{
    MmsAllParams *to;
    MmsAllParams *from;
    MSF_UINT32 len = 0;

    if (fromContent == NULL)
    {   /* No data to copy so no copy needed */
        return;
    } /* if */

    toContent->knownValue = fromContent->knownValue;
    if ( fromContent->strValue == NULL)
    {
        toContent->strValue = NULL;
    }
    else
    {
        len = strlen( (const char *)fromContent->strValue) + 1;
        toContent->strValue = MEA_ALLOC(len);
        strcpy((char *)toContent->strValue, 
            (const char *)fromContent->strValue);
    } /* if */

    if (fromContent->params == NULL)
    {
        toContent->params = NULL;
        return ;
    } /* if */

    from = fromContent->params;
    to = toContent->params = MEA_ALLOC(sizeof(MmsAllParams));
    memset(to, 0, sizeof(MmsAllParams));

    while (from != NULL)
    {
        to->param = from->param;
        to->type = from->type;

        if (NULL == from->key)
        {
            to->key = NULL;
        }
        else
        {
            to->key = (unsigned char *)msf_cmmn_strdup(MSF_MODID_MEA, 
                (char *)from->key);
        }

        if (from->type == MMS_PARAM_STRING)
        {
            if (from->value.string == NULL)
            {
                to->value.string = NULL;
            }
            else
            {
                to->value.string = (unsigned char *)msf_cmmn_strdup(MSF_MODID_MEA, 
                    (char *)from->value.string);
            } /* if */
        
        }
        else if (from->type == MMS_PARAM_INTEGER)
        {
            to->value.integer = from->value.integer;
        } /* if */
    
        from = from->next;
        if (from != NULL)
        {
            MEA_CALLOC(to->next, sizeof(MmsAllParams));
            to = to->next;
        }
        else
        {
            to->next = NULL;
        } /* if */
    } /* while */

    return ;
} /* meaCopyContentType*/

/*! \brief removes a content type parameter
 *	
 * \param params The list of parameters
 * \param paramType The type of param to remove
 *****************************************************************************/
void meaRemoveMmsParam(MmsAllParams **params, MmsParam paramToRemove)
{
    MmsAllParams *tmpParam;
    MmsAllParams *prevParam = NULL;
    tmpParam = *params;
    while (NULL != tmpParam)
    {
        if (tmpParam->param == paramToRemove)
        {
            /* Remove the item from the list */
            if (NULL != prevParam)
            {
                prevParam->next = tmpParam->next;
            }
            else
            {
                /* Change the first item */
                *params = tmpParam->next;
            }
            /* Deallocate the item to remove */
            if (MMS_PARAM_STRING == tmpParam->type)
            {
                MEA_FREE(tmpParam->value.string);
            }
            MEA_FREE(tmpParam);
            /* The operation is done */
            return;
        }
        /* Next item */
        prevParam = tmpParam;
        tmpParam  = tmpParam->next;
    }
}

/*!
 * \brief Generates a name for a file
 * \param extension What extension to set on the file. (max 3 char)
 * \return The name of the media object or NULL on error.
 *****************************************************************************/
char *meaCreateFileName(const char *extension)
{
    char *name = NULL;
    unsigned int size = 0;
    static MSF_UINT32 counter; /* Initialized to zero at start-up */
    MSF_UINT32 currentTime = 0;
    unsigned int extensionSize = 0;

    if (NULL != extension)
    {
        extensionSize = strlen(extension);
    }

    /* create name for text */
    currentTime = MSF_TIME_GET_CURRENT();

    /* current-time + "." + extension + NULL */
    size = (sizeof(MSF_UINT32)*2 + 1 + extensionSize + 1);
    
    name = MEA_ALLOC((unsigned long)size);
    memset(name, 0, size);
    if (NULL != extension)
    {
        /* Use the extension */
    /*lint -e{727} */
    sprintf(name, "%lx.%s", (long)(currentTime<<8)|(counter&0xff), 
        extension);
    }
    else
    {
        /* Skip the extension */
        /*lint -e{727} */
        sprintf(name, "%lx", (long)(currentTime<<8)|(counter&0xff));
    }

    /* Use a counter to prevent problems if the CPU is to fast, i.e., 
       the timer has not been increased between two calls, 256 calls
       to meaCreatefileName during the same time is not likely */
    ++counter;
    return name;
} /* createFileName */
#ifndef __MED_MEM_POOL__
#define __MED_MEM_POOL__
#endif
#ifdef __MED_MEM_POOL__
static char name[13];
char *meaCreateFileName_jpg(const char *extension)
{
    //char *name = NULL;
    unsigned int size = 0;
    static MSF_UINT32 counter; /* Initialized to zero at start-up */
    MSF_UINT32 currentTime = 0;
    unsigned int extensionSize = 0;
	//char name[13];
    if (NULL != extension)
    {
        extensionSize = strlen(extension);
    }

    /* create name for text */
    currentTime = MSF_TIME_GET_CURRENT();

    /* current-time + "." + extension + NULL */
    //size = (sizeof(MSF_UINT32)*2 + 1 + extensionSize + 1);
    size =13;
    //name = MEA_ALLOC((unsigned long)size);
    memset(name, 0, size);
    if (NULL != extension)
    {
        /* Use the extension */
    /*lint -e{727} */
    sprintf(name, "%lx.%s", (long)(currentTime<<8)|(counter&0xff), 
        extension);
    }
    else
    {
        /* Skip the extension */
        /*lint -e{727} */
        sprintf(name, "%lx", (long)(currentTime<<8)|(counter&0xff));
    }

    /* Use a counter to prevent problems if the CPU is to fast, i.e., 
       the timer has not been increased between two calls, 256 calls
       to meaCreatefileName during the same time is not likely */
    ++counter;
    return name;
} /* createFileName */
#endif
/*!
 * \brief Creates a unique filename from the media type. A correct file 
 *        extension is appended if possible.
 *
 * \param mediaType The media type to create a unique filename from.
 * \return A unique name for the media object.
 *****************************************************************************/
char *meaCreateFileNameFromType(MeaMediaType mediaType)
{
    unsigned int i;
    const MeaMediaObjects *items;
    /*lint -e{1776}*/
    /*lint -e{788}*/
    i = 0;
    items = supportedMediaObjects;
    while(MEA_MEDIA_TYPE_UNKNOWN != items[i].mediaType)
    {
        if (mediaType == items[i].mediaType)
        {
            return meaCreateFileName(items[i].fileExtension);
        }
        ++i;
    }
    MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
            MAUTILS_414D8145857CABF0537100D8F83B1643, "(%s) (%d) erroneous media type", __FILE__, __LINE__));
    /* The type could not be determined, do not create the extension */
    return meaCreateFileName(NULL);
}

/*!
 * \brief Creates a unique filename from the media type. A correct file 
 *        extension is appended if possible.
 *
 * \param mediaType The media type to create a unique filename from.
 * \return A unique name for the media object.
 *****************************************************************************/
char *meaCreateFileNameFromMime(const char *mime)
{
    unsigned int i = 0;
    const MeaExtAttachmentType *extItems = supportedExtAttachmentTypes;
    MeaMediaType type = MEA_MEDIA_TYPE_UNKNOWN;

    if (mime == NULL)
    {
        return meaCreateFileName(NULL);
    }

    type = meaMime2MediaType(mime);
    if (type != MEA_MEDIA_TYPE_UNKNOWN)
    {
        return meaCreateFileNameFromType(type);
    }
    else
    {
        i = 0;
        while (extItems[i].mimeType != NULL)
        {
            if (0 == msf_cmmn_strcmp_nc(mime, extItems[i].mimeType))
            {
                return meaCreateFileName(extItems[i].ending);
            }
            ++i;
        }
    }

    /* The type could not be determined, do not create the extension */
    return meaCreateFileName(NULL);
}

/*! \brief converts between #MeaMediaType and #MeaObjectType.
 *
 * \param mediaType The media type to convert.
 * \return The corresponding #MeaObjectType.
 *****************************************************************************/
MeaMediaGroupType meaMediaType2ObjType(MeaMediaType mediaType)
{
    unsigned int i = 0;
    const MeaMediaObjects *items;

    items = supportedMediaObjects;
    while(items[i].mediaType != MEA_MEDIA_TYPE_UNKNOWN)
    {
        if (items[i].mediaType == mediaType)
        {
            return items[i].objectType;
        }
        ++i;
    }
    return MEA_MEDIA_GROUP_NONE;
}

/*! \brief Appends two address lists.
 *
 *  After this call the only valid MeaAddrItem is the returned one.
 *
 * \param first The first part of the new list 
 * \param second The second part of the new list 
 * \return The new list.
 *****************************************************************************/
MeaAddrItem *meaAppendAddrItems(MeaAddrItem *first, MeaAddrItem *second)
{
    MeaAddrItem *tmp;

    if (NULL == first)
    {
        return second;
    }
    for(tmp = first; NULL != tmp->next; tmp = tmp->next)
        ;
    tmp->next = second;
    return first;
}

/*!
 * \brief       Parses a property item (MEA data structure) and frees all data.
 *              Beware of static strings!
 * \param prop  The property item to parse and free
 * \param dynamicOnly TRUE if memory allocated in the structure is 
 *              de-allocated, i.e., the structure is not released.
 *****************************************************************************/
void meaFreePropItem(MeaPropItem *prop, MSF_BOOL dynamicOnly)
{
    if (NULL == prop)
    {
        return;
    }
    /* Delete addresses */
    meaAddrListFree(&(prop->to));
    meaAddrListFree(&(prop->cc));
    meaAddrListFree(&(prop->bcc));
    meaAddrListFree(&(prop->from));
    /* Subject */
    MEA_FREE(prop->subject);
    prop->subject = NULL;
    MEA_FREE(prop->replyChargingId);
    prop->replyChargingId = NULL;

    /* Check if the structure needs to be de-allocated */
    if (!dynamicOnly)
    {
        /*lint -e{774} */
        MEA_FREE(prop);
    }
}

#ifdef WAP_SUPPORT
/*!
 * \brief Convert Mms folder to Mea foler
 *
 * \param folder The mms folder
 *****************************************************************************/
MeaFolder mmsFolder2MeaFolder(MmsFolderType folder)
{
    /* Convert the folder type from MMS to MEA */
    MeaFolder meaFolder = MEA_FOLDER_NONE;

    if((folder & MMS_INBOX) || (folder & MMS_NOTIFY))
    {
        meaFolder |= MEA_FOLDER_INBOX;
    }

    if(folder & MMS_OUTBOX)
    {
        meaFolder |= MEA_FOLDER_OUTBOX;
    }

    if(folder & MMS_DRAFTS)
    {
        meaFolder |= MEA_FOLDER_DRAFTS;
    }

    if(folder & MMS_SENT)
    {
        meaFolder |= MEA_FOLDER_SENT;
    }

    if(folder & MMS_TEMPLATES)
    {
        meaFolder |= MEA_FOLDER_TEMPLATE;
    }
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    if(folder & MMS_ARCHIVE)
    {
        meaFolder |= MEA_FOLDER_ARCHIVE;
    }
#endif /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/    
#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
    if (folder & MMS_USRDEF_TEMPLATES)
    {
        meaFolder |= MEA_FOLDER_USER_TEMPLATE;
    }
#endif

    return meaFolder;
}

/*!
 * \brief Convert Mea folder to Mms foler
 *
 * \param folder The mea folder where messages is listed.
 *****************************************************************************/
MmsFolderType meaFolder2MmsFolder(MeaFolder folder)
{
    /* Convert the folder type from MEA to MMS */
    MmsFolderType mmsFolder = MMS_NO_FOLDER;

    if(folder & MEA_FOLDER_INBOX)
    {
        mmsFolder |= (MmsFolderType)(MMS_INBOX | MMS_NOTIFY);
    }

    if(folder & MEA_FOLDER_OUTBOX)
    {
        mmsFolder |= MMS_OUTBOX;
    }

    if(folder & MEA_FOLDER_DRAFTS)
    {
        mmsFolder |= MMS_DRAFTS;
    }

    if(folder & MEA_FOLDER_SENT)
    {
        mmsFolder |= MMS_SENT;
    }

    if(folder & MEA_FOLDER_TEMPLATE)
    {
        mmsFolder |= MMS_TEMPLATES;
    }
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    if(folder & MEA_FOLDER_ARCHIVE)
    {
        mmsFolder |= MMS_ARCHIVE;
    }
#endif /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/

#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
    if (folder & MEA_FOLDER_USER_TEMPLATE)
    {
        mmsFolder |= MMS_USRDEF_TEMPLATES;
    }
#endif

    return mmsFolder;
}

/* ! \brief MIME to MEA media type
 *
 * \param mime The mime type string.
 * \return The MEA media type
 *****************************************************************************/
MSF_BOOL meaCheckCharacterIsAllEnglish(const char *str)
{
	MSF_BOOL ret = TRUE;
	while(*str)
	{
		if (*str & 0x80)
		{
			ret = FALSE;
			break;
		}
		str++;
	}
	return ret;
}

/* ! \brief Filename to mime type. We don't use widget's HDIa_widgetExtFileNameToMimeType() anymore.
 * As long as file extension is supported (MTK-default + customer-extension), 
 * its MIME type string will be returned. So it can be used to determine
 * 1. if the file can be saved 2. if the file can be attachment
 *
 * \param filename
 * \return Mime type string
 *****************************************************************************/
const char *meaFileName2MimeType(const char *filename)
{
    int i = 0;
    const char *ext = NULL;
    const MeaMediaObjects *items = supportedMediaObjects;
    const MeaExtAttachmentType *extItems = supportedExtAttachmentTypes;

    if (filename == NULL)
    {
        return NULL;
    }

    ext = strrchr(filename, '.');

    if (ext == NULL)
    {
        return NULL;
    }

    ext++;
    while (items[i].mediaType != MEA_MEDIA_TYPE_UNKNOWN)
    {
        if (0 == msf_cmmn_strcmp_nc(ext, items[i].fileExtension))
        {
            return items[i].mimeType;
        }
        ++i;
    }

    i = 0;
    while (extItems[i].mimeType != NULL)
    {
        if (0 == msf_cmmn_strcmp_nc(ext, extItems[i].ending))
        {
            return extItems[i].mimeType;
        }
        ++i;
    }

    return NULL;
}

/* ! \brief MIME to MEA media type
 *
 * \param mime The mime type string.
 * \return The MEA media type
 *****************************************************************************/
MmsKnownMediaType meaMime2MmsMediaType(const char *mime)
{
    unsigned int i = 0;
    const MeaMediaObjects *items = supportedMediaObjects;
    if (!mime)
        return MMS_VALUE_AS_STRING;
    while (items[i].mediaType != MEA_MEDIA_TYPE_UNKNOWN)
    {
        if (0 == msf_cmmn_strcmp_nc(mime, items[i].mimeType))
        {
            return items[i].assignedValue;
        }
        ++i;
    }
    return MMS_VALUE_AS_STRING;
}

void meaExtractFileName(char *fName)
{
    char *c = strrchr(fName, '\\');
    char *c1 = strrchr(fName, '/');

    if (c == NULL && c1 == NULL)
    {
        return;
    }
    else
    {
        c = (c1 > c)? c1: c;  /* find the last / or \ */
    }

    /*Skip past "\"*/
    c++;

    while (*c != '\0')
    {
        *fName = *c;
        fName++;
        c++;
    }
    *fName = '\0';
}

void meaTransformIllegalFileName(char *name)
{
    const char *illegal_chars = "\\/:*?\"<>|";
    char *ch = name;

    while (*ch)
    {
        if (strchr(illegal_chars, *ch))
        {
            *ch = '_';
        }
        ch += 1;
    }
}

  #ifdef JPG_ENCODE
MSF_BOOL meaIsResizedFile(char *name)
{
    char *ext = NULL;
    if( name == NULL)
    {
        return FALSE;
    }
    if(msf_cmmn_strncmp_nc(name, MEA_IMAGE_RESIZE_FOLDER, strlen(MEA_IMAGE_RESIZE_FOLDER)) == 0 &&
        (ext = strrchr (name,'.')) != NULL && msf_cmmn_strcmp_nc(ext,".jpg") == 0)
    	return TRUE;
    else
        return FALSE;
}

void meaCleanupResizedFiles(void)
{
    static char pathname[MAX_FILE_NAME_LEN];
    int type = 0, filesize = 0, fileIdx = 0;
    char *name = NULL, *ext = NULL;
    int dirHandle = -1;
    
    sprintf (pathname, "%s", MEA_IMAGE_RESIZE_FOLDER);
    name = strrchr (pathname,'/') + 1;
    while (MSF_FILE_READ_DIR_SEQ (MEA_IMAGE_RESIZE_FOLDER, fileIdx, name, MAX_FILE_NAME_LEN, &type, &filesize, &dirHandle) == HDI_FILE_OK) 
    {
        fileIdx++;
        if (type == HDI_FILE_FILETYPE)
        {
            if((ext = strrchr (name,'.')) != NULL && msf_cmmn_strcmp_nc(ext,".jpg") == 0)
            {
                HDIa_fileRemove (pathname);
            }
        }
    }
    MSF_FILE_READ_DIR_SEQ_CLOSE(&dirHandle);    
}
  #endif

/* ! \brief Change filename extension
 *
 * \param name(I/O): original filename
 * \param type: target type
 * \return 
 *****************************************************************************/
MSF_BOOL meaRenameExtensionFromType(MSF_UINT8 modId, char **name, MeaMediaType type)
{
    const MeaMediaObjects *items = supportedMediaObjects;
    char *old = *name;
    int i = 0;

    if (name == NULL || *name == NULL)
    {
        return FALSE;
    }
    
    while(MEA_MEDIA_TYPE_UNKNOWN != items[i].mediaType)
    {
        if (type == items[i].mediaType)
        {
            char *str = strrchr(*name, '.');
            if (str != NULL)
            {
                *str = '\0';
            }
            *name = msf_cmmn_str3cat(modId, *name, ".", items[i].fileExtension);
            MSF_MEM_FREE(modId, old);
            return TRUE;
        }
        ++i;
    }

    return FALSE;
}

/* ! \brief Change filename extension
 *
 * \param name(I/O): original filename
 * \param mime: mime type string
 * \return 
 *****************************************************************************/
MSF_BOOL meaRenameExtensionFromMime(MSF_UINT8 modId, char **name, const char *mime)
{
    const MeaExtAttachmentType *extItems = supportedExtAttachmentTypes;
    MeaMediaType type = MEA_MEDIA_TYPE_UNKNOWN;
    char *old = *name;
    int i = 0;

    if (name == NULL || *name == NULL || mime == NULL)
    {
        return FALSE;
    }

    type = meaMime2MediaType(mime);
    if (type != MEA_MEDIA_TYPE_UNKNOWN)
    {
        meaRenameExtensionFromType(modId, name, type);
        return TRUE;
    }
    else
    {
        i = 0;
        while (extItems[i].mimeType != NULL)
        {
            if (0 == msf_cmmn_strcmp_nc(mime, extItems[i].mimeType))
            {
                char *str = strrchr(*name, '.');
                if (str != NULL)
                {
                    *str = '\0';
                }
                *name = msf_cmmn_str3cat(modId, *name, ".", extItems[i].ending);
                MSF_MEM_FREE(modId, old);
                return TRUE;
            }
            ++i;
        }
    }

    return FALSE;
}

/* ! \brief Check if the mime type is supported
 *
 * \param mime: mime type string
 * \return 
 *****************************************************************************/
MSF_BOOL meaIsSupportedMimeType(const char *mime)
{
    const MeaMediaObjects *items = supportedMediaObjects;
    const MeaExtAttachmentType *extItems = supportedExtAttachmentTypes;
    int i = 0;

    while (items[i].mediaType != MEA_MEDIA_TYPE_UNKNOWN)
    {
        if (0 == msf_cmmn_strcmp_nc(mime, items[i].mimeType))
        {
            return TRUE;
        }
        ++i;
    }
    
    i = 0;
    while (extItems[i].mimeType != NULL)
    {
        if (0 == msf_cmmn_strcmp_nc(mime, extItems[i].mimeType))
        {
            return TRUE;
        }
        ++i;
    }
    return FALSE;
}

/* ! \brief Check if the file is restricted type
 *
 * \param name: filename
 * \return 
 *****************************************************************************/
MSF_BOOL meaIsRestrictedType(const char *filename)
{
    const char *restrictedTypes = MEA_CFG_OPEN_RESTRICTED_ATTACHMENT_TYPES;
    const char *restrictedImageTypes = MEA_CFG_OPEN_RESTRICTED_IMAGE_TYPES;
    const char *strMimeType = NULL;

    if(filename == NULL)
    {
        return FALSE;
    }

    /* Mime type check */
    strMimeType = meaFileName2MimeType(filename);
    if (strMimeType != NULL && strstr(restrictedTypes, strMimeType))
    {
#ifdef __DRM_SUPPORT__
        kal_uint8* externalFileName = HDI_FileNameTranslate(filename);
        int objType = DRM_get_object_method(0, (kal_wchar *)externalFileName);
        if (objType == DRM_METHOD_COMBINED_DELIVERY || objType == DRM_METHOD_SEPARATE_DELIVERY)
        {
            HDI_FileNameFree(externalFileName);
            return FALSE;
        }
        HDI_FileNameFree(externalFileName);
#endif

        /* Image resolution check */
        if(strstr(restrictedImageTypes, strMimeType))
        {
            MsfSize dimension = {0, 0};
            if(HDIa_widgetExtImageFileGetSize((char *)filename, &dimension) != TRUE ||
                dimension.width * dimension.height > MEA_RESTRICTED_RESOLUTION)
            {
                return FALSE;
            }
        }
	
	return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/* ! \brief Check if the virtual file is restricted type
 *
 * \param name: original filename
 * \param offset
 * \param size
 * \return 
 *****************************************************************************/
MSF_BOOL meaIsRestrictedTypeVF(const char *filename, MeaMediaType type, MSF_UINT32 offset, MSF_UINT32 size)
{
    char *vFileName = NULL;
    int fileHandle = 0;
    MSF_BOOL isRestricted = FALSE;

    /*generate virtual file */
    if(filename == NULL || size == 0 || (fileHandle = MSF_FILE_OPEN(MSF_MODID_MEA, filename, MSF_FILE_SET_RDONLY, 0)) < 0)
    {
        return FALSE;
    }

    if(type == MEA_MEDIA_TYPE_TEXT_PLAIN)
    {
        MSF_FILE_CLOSE(fileHandle);
        return TRUE;
    }
    
    MEA_CALLOC(vFileName, WIDGET_RAWFILE_NAMELEN);
    ASSERT(vFileName != NULL);
    if(HDIa_fileGenVirtualFileName(fileHandle, vFileName, WIDGET_RAWFILE_NAMELEN, offset, size) != HDI_FILE_OK)
    {
    }
    else if(meaRenameExtensionFromType(MSF_MODID_MEA, &vFileName, type) == FALSE)  /* change virtual file extension .r to original extension */
    {
    }
    else if(meaIsRestrictedType((const char *)vFileName) == TRUE)
    {
        isRestricted = TRUE;
    }

    MEA_FREE(vFileName);
    MSF_FILE_CLOSE(fileHandle);
    return isRestricted;
}

void meaRemoveAttachment(MeaMoDataItem **list)
{
    MeaMoDataItem *mo = *list;
    if (list == NULL || *list == NULL)
    {
        return;
    }
    
    while(mo)
    {
		MeaMoDataItem *next = mo->next;
        meaDeleteMo(list, NULL, mo);
		mo = next;
    }
    *list = NULL;
}

/*!
 * \brief Creates the property text
 *
 * \param msgId: Message ID
 * \return Property text buffer (caller should release the MEA buffer)
 *****************************************************************************/
char *meaCreateMsgPropText(MmsMsgId msgId)
{
    MmsTransactionHandle tHandle;
    MmsMsgHandle mHandle;
    MmsFolderType folder;
    MmsFileType fileType;
    MmsResult res;

    MmsGetHeader *header = NULL;
    MeaAddrItem *from = NULL, *to = NULL, *cc = NULL, *bcc = NULL;
    
    kal_uint8 *text = NULL;
    char *str = NULL;
    int text_size = 0, file_size = 0;
    kal_uint8 *tmp_str = NULL;

    folder = fldrGetFolderId(msgId);
    if ((fileType = fldrGetFileSuffix(msgId)) == MMS_SUFFIX_ERROR)
    {
        return NULL;
    }

    MMS_FILE_OPEN_BLOCK_FLAG = TRUE;
    if ((MMS_RESULT_OK != MMSlib_messageOpen(MSF_MODID_MEA, msgId, fileType, &mHandle)) 
        || (MMS_RESULT_OK != MMSlib_transactionOpen(MSF_MODID_MEA, &tHandle)))
    {
        MMSlib_messageClose(MSF_MODID_MEA, &mHandle);
        MMSlib_transactionClose(MSF_MODID_MEA, &tHandle);
        MMS_FILE_OPEN_BLOCK_FLAG = FALSE;
        return NULL;
    }

    MMS_FILE_OPEN_BLOCK_FLAG = FALSE;    
    MEA_CALLOC(header, sizeof(MmsGetHeader));
    res = MMSlib_getMessageHeader(MSF_MODID_MEA, header, &mHandle, &tHandle);        

    if (res != MMS_RESULT_OK) 
    {
        MMSlib_messageClose(MSF_MODID_MEA, &mHandle);
        MMSlib_transactionClose(MSF_MODID_MEA, &tHandle);
        MMSlib_freeMmsGetHeader(MSF_MODID_MEA, header);
        return NULL;
    } 
    
    MMSlib_messageClose(MSF_MODID_MEA, &mHandle);
    MMSlib_transactionClose(MSF_MODID_MEA, &tHandle);
	
    /* Prepare text. widget_ucs2str_append_* will realloc the buffer if necessary*/
    text_size = 300;
    text = MEA_ALLOC(text_size);
    widget_utf8_to_ucs2_string(text, text_size, (kal_uint8*) "");

    from = meaMmsFromToAddrItem(&header->from);
    to = meaMmsToAddrList(header->to, NULL);
    cc = meaMmsToAddrList(header->cc, NULL);
    bcc = meaMmsToAddrList(header->bcc, NULL);

    /*
    meaRemoveInvalidAddr(&from);
    meaRemoveInvalidAddr(&to);
    meaRemoveInvalidAddr(&cc);
    meaRemoveInvalidAddr(&bcc);
*/
    meaNameLookup(from, (MeaStateMachine)0, (int)0);
    meaNameLookup(to, (MeaStateMachine)0, (int)0);
    meaNameLookup(cc, (MeaStateMachine)0, (int)0);
    meaNameLookup(bcc, (MeaStateMachine)0, (int)0);

    /* From */
    if(MMS_SUFFIX_SEND_REQ != fileType)
    {
        text = widget_ucs2str_append_id(MSF_MODID_MEA, text, &text_size, MEA_STR_ID_FROM);
        text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)":\n");
        if(from)
        {
            str = meaAddrItemToStr(from);
            if(msf_cmmn_utf8_strlen(str) != 0)
            {
                if(widget_utf8_to_ucs2_length_in_bytes((kal_uint8 *)str) + ENCODING_LENGTH > MEA_MAX_ADDRS_STRLEN)
                {
                    int i = 0, j = 0;
                    tmp_str = MEA_ALLOC(MEA_MAX_ADDRS_STRLEN);
                    memset(tmp_str, 0, MEA_MAX_ADDRS_STRLEN);
                    widget_utf8_to_ucs2_string(tmp_str, MEA_MAX_ADDRS_STRLEN, (kal_uint8 *)str);
                    for (i = MEA_MAX_ADDRS_STRLEN - ENCODING_LENGTH; i > 0; i--)
                    {
                        if (tmp_str[i] == ',')
                        {
                            break;
                        }
                    }
                    if (i > 0)
                    {
                        for (j = i; j < MEA_MAX_ADDRS_STRLEN - ENCODING_LENGTH; j++)
                        {
                            tmp_str[j] = 0;
                        }                        
                    }
                    text = widget_ucs2str_append_ucs2(MSF_MODID_MEA, text, &text_size, tmp_str);
                    widget_utf8_to_ucs2_string(tmp_str, ENCODING_LENGTH * 4, (const kal_uint8 *)"...");
                    text = widget_ucs2str_append_ucs2(MSF_MODID_MEA, text, &text_size, tmp_str);
                    MEA_FREE(tmp_str);
                }
                else
                {
                    text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)str);
                }
            }
            else
            {
                text = widget_ucs2str_append_id(MSF_MODID_MEA, text, &text_size, MEA_STR_ID_EMPTY_LIST);
            }
            MEA_FREE(str);
        }
        else
        {
            text = widget_ucs2str_append_id(MSF_MODID_MEA, text, &text_size, MEA_STR_ID_EMPTY_LIST);
        }
        text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)"\x1B\n");
    }

    /* To */
    text = widget_ucs2str_append_id(MSF_MODID_MEA, text, &text_size, MEA_STR_ID_TO);
    text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)":\n");
    if (to)
    {
        str = meaAddrItemToStr(to);
        if(msf_cmmn_utf8_strlen(str) != 0)
        {
            if(widget_utf8_to_ucs2_length_in_bytes((kal_uint8 *)str) + ENCODING_LENGTH > MEA_MAX_ADDRS_STRLEN)
            {
                int i = 0;
                tmp_str = MEA_ALLOC(MEA_MAX_ADDRS_STRLEN);
                memset(tmp_str, 0, MEA_MAX_ADDRS_STRLEN);
                widget_utf8_to_ucs2_string(tmp_str, MEA_MAX_ADDRS_STRLEN, (kal_uint8 *)str);
                for (i = MEA_MAX_ADDRS_STRLEN - ENCODING_LENGTH; i > 0; i--)
                {
                    if (tmp_str[i] == ',')
                    {
                        break;
                    }
                }
                if (i > 0)
                {
                    tmp_str[i] = 0;
                    tmp_str[i + 1] = 0;
                }
                text = widget_ucs2str_append_ucs2(MSF_MODID_MEA, text, &text_size, tmp_str);
                widget_utf8_to_ucs2_string(tmp_str, ENCODING_LENGTH * 4, (const kal_uint8 *)"...");
                text = widget_ucs2str_append_ucs2(MSF_MODID_MEA, text, &text_size, tmp_str);
                MEA_FREE(tmp_str);
            }
            else
            {
               text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)str);
            }
        }
        else
        {
            text = widget_ucs2str_append_id(MSF_MODID_MEA, text, &text_size, MEA_STR_ID_EMPTY_LIST);
        }
        MEA_FREE(str);
	}
	else
	{
        text = widget_ucs2str_append_id(MSF_MODID_MEA, text, &text_size, MEA_STR_ID_EMPTY_LIST);
	}
    text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)"\x1B\n");

    /* CC */
    text = widget_ucs2str_append_id(MSF_MODID_MEA, text, &text_size, MEA_STR_ID_CC);
    text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)":\n");
	if (cc)
	{
        str = meaAddrItemToStr(cc);
        if(msf_cmmn_utf8_strlen(str) != 0)
        {
            if(widget_utf8_to_ucs2_length_in_bytes((kal_uint8 *)str) + ENCODING_LENGTH > MEA_MAX_ADDRS_STRLEN)
            {
                int i = 0;
                tmp_str = MEA_ALLOC(MEA_MAX_ADDRS_STRLEN);
                memset(tmp_str, 0, MEA_MAX_ADDRS_STRLEN);
                widget_utf8_to_ucs2_string(tmp_str, MEA_MAX_ADDRS_STRLEN, (kal_uint8 *)str);
                for (i = MEA_MAX_ADDRS_STRLEN - ENCODING_LENGTH; i > 0; i--)
                {
                    if (tmp_str[i] == ',')
                    {
                        break;
                    }
                }
                if (i > 0)
                {
                    tmp_str[i] = 0;
                    tmp_str[i + 1] = 0;
                }
                text = widget_ucs2str_append_ucs2(MSF_MODID_MEA, text, &text_size, tmp_str);
                widget_utf8_to_ucs2_string(tmp_str, ENCODING_LENGTH * 4, (const kal_uint8 *)"...");
                text = widget_ucs2str_append_ucs2(MSF_MODID_MEA, text, &text_size, tmp_str);
                MEA_FREE(tmp_str);
            }
            else
            {
                text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)str);
            }            
        }            
        else
        {
            text = widget_ucs2str_append_id(MSF_MODID_MEA, text, &text_size, MEA_STR_ID_EMPTY_LIST);
        }
        MEA_FREE(str);
	}
	else
	{
        text = widget_ucs2str_append_id(MSF_MODID_MEA, text, &text_size, MEA_STR_ID_EMPTY_LIST);
	}
    text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)"\x1B\n");

    /* BCC */
    if(folder != MEA_FOLDER_INBOX )
    {
        text = widget_ucs2str_append_id(MSF_MODID_MEA, text, &text_size, MEA_STR_ID_BCC);
        text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)":\n");
        if (bcc)
        {
            str = meaAddrItemToStr(bcc);
            if(msf_cmmn_utf8_strlen(str) != 0)
            {
                if(widget_utf8_to_ucs2_length_in_bytes((kal_uint8 *)str) + ENCODING_LENGTH > MEA_MAX_ADDRS_STRLEN)
                {
                    int i = 0;
                    tmp_str = MEA_ALLOC(MEA_MAX_ADDRS_STRLEN);
                    memset(tmp_str, 0, MEA_MAX_ADDRS_STRLEN);
                    widget_utf8_to_ucs2_string(tmp_str, MEA_MAX_ADDRS_STRLEN, (kal_uint8 *)str);
                    for (i = MEA_MAX_ADDRS_STRLEN - ENCODING_LENGTH; i > 0; i--)
                    {
                        if (tmp_str[i] == ',')
                        {
                            break;
                        }
                    }
                    if (i > 0)
                    {
                        tmp_str[i] = 0;
                        tmp_str[i + 1] = 0;
                    }
                    text = widget_ucs2str_append_ucs2(MSF_MODID_MEA, text, &text_size, tmp_str);
                    widget_utf8_to_ucs2_string(tmp_str, ENCODING_LENGTH * 4, (const kal_uint8 *)"...");
                    text = widget_ucs2str_append_ucs2(MSF_MODID_MEA, text, &text_size, tmp_str);
                    MEA_FREE(tmp_str);
                }
                else
                {
                    text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)str);
                }                
            }                
            else
            {
                text = widget_ucs2str_append_id(MSF_MODID_MEA, text, &text_size, MEA_STR_ID_EMPTY_LIST);
            }
            MEA_FREE(str);
        }
        else
        {
            text = widget_ucs2str_append_id(MSF_MODID_MEA, text, &text_size, MEA_STR_ID_EMPTY_LIST);
        }
        
        text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)"\x1B\n");
    }
    
    /* Subject */
    text = widget_ucs2str_append_id(MSF_MODID_MEA, text, &text_size, MEA_STR_ID_SUBJECT);
    text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)":\n");

#ifndef  MEA_CFG_USER_TEMPLATE_SUPPORT
#if (defined(MMS_TMPLATES_MULTIPLE_LANG_SUPPORT)) && (defined(__MMI_MMS_TEMPLATES_NUM__))
    if (1<=meaMMCGetCurrentActiveMsg() && meaMMCGetCurrentActiveMsg()<=__MMI_MMS_TEMPLATES_NUM__)
    {
        char *strRes = NULL, *utf8Sub = NULL;
        int utf8Size = 0;
        
        strRes = GetString((MSF_UINT16)(meaMMCGetCurrentActiveMsg() + MMS_STR_ID_TEMPLATES_TITLE_01-1));
        if (!strRes) 
        {
        }
        else
        {
            utf8Size = widget_ucs2_to_utf8_length_in_bytes((kal_uint8*)strRes);
            MEA_CALLOC(utf8Sub, utf8Size + 1);
            ASSERT(utf8Sub);
            widget_ucs2_to_utf8_string((kal_uint8*)utf8Sub, utf8Size + 1, (kal_uint8*)strRes);
            text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)utf8Sub);
            MEA_FREE(utf8Sub);
        }
    }
    else
#endif /* MMS_TMPLATES_MULTIPLE_LANG_SUPPORT && __MMI_MMS_TEMPLATES_NUM__*/
#endif /* MEA_CFG_USER_TEMPLATE_SUPPORT*/
    {
        if (header->subject.text)
        {
            if(widget_utf8_to_ucs2_length_in_bytes((kal_uint8 *)header->subject.text) + ENCODING_LENGTH > MEA_MAX_ADDRS_STRLEN)
            {
                tmp_str = MEA_ALLOC(MEA_MAX_ADDRS_STRLEN);
                memset(tmp_str, 0, MEA_MAX_ADDRS_STRLEN);
                widget_utf8_to_ucs2_string(tmp_str, MEA_MAX_ADDRS_STRLEN - ENCODING_LENGTH, (kal_uint8 *)header->subject.text);
                text = widget_ucs2str_append_ucs2(MSF_MODID_MEA, text, &text_size, tmp_str);
                MEA_FREE(tmp_str);
            }
            else
            {
                text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)header->subject.text);
            }
        }
        else
        {
            text = widget_ucs2str_append_id(MSF_MODID_MEA, text, &text_size, MEA_STR_ID_EMPTY_LIST);
        }
    }	
    text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)"\x1B\n");

	/* Date */
    if (folder != MMS_TEMPLATES)
    {
        MmsTimeSec date;
        MYTIME time;
        MmsMessageFolderInfo *msgInfo = (MmsMessageFolderInfo *)fldrMgrGetMsgInfo(msgId);

        text = widget_ucs2str_append_id(MSF_MODID_MEA, text, &text_size, MEA_STR_ID_DATE);
        text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)"\n");
        str = MEA_ALLOC(MEA_MAX_DATE_SIZE);
        date = msgInfo->date + HDIa_timeGetTimeZone() * 60;
        mmi_dt_utc_sec_2_mytime(date, &time, KAL_TRUE);
        date_string(&time, (unsigned short *)str, DT_IDLE_SCREEN);
        text = widget_ucs2str_append_ucs2(MSF_MODID_MEA, text, &text_size, (kal_uint8 *)str);
        text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)"\n");
        time_string(&time, (unsigned short *)str, DT_IDLE_SCREEN);
        text = widget_ucs2str_append_ucs2(MSF_MODID_MEA, text, &text_size, (kal_uint8 *)str);
        MEA_FREE(str);
	    text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)"\x1B\n");
    }

    /* Size */
    str = MMSlib_getMessageFullPath(MSF_MODID_MEA, msgId, fileType);
	if (str)
	{
        file_size = HDIa_fileGetSize(str);
		MEA_FREE(str);	
	}
	else
	{
	    file_size = 0;
	}
    str = MEA_ALLOC(strlen("300 K")+1);
    sprintf(str, "%iK", (file_size + (MEA_1_KB - 1)) / MEA_1_KB);
    text = widget_ucs2str_append_id(MSF_MODID_MEA, text, &text_size, MEA_STR_ID_NOTIFICATION_SIZE);
    text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)":\n");
    text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)str);
    MEA_FREE(str);
    MMSlib_freeMmsGetHeader(MSF_MODID_MEA, header);

    if (from)
    {
        meaAddrListFree(&from);
    }
    if (to)
    {
        meaAddrListFree(&to);
    }
    if (cc)
    {
        meaAddrListFree(&cc);
    }
    if (bcc)
    {
        meaAddrListFree(&bcc);
    }
    return (char *)text;
}

/*!
 * \brief Creates the notification property text
 *
 * \param msgId: Message ID
 * \return Property text buffer (caller should release the MEA buffer)
 *****************************************************************************/
char *meaCreateNotifPropText(MmsMsgId msgId)
{
    MmsTransactionHandle tHandle;
    MmsMsgHandle mHandle;
    MmsFolderType folder;
    MmsFileType fileType;
    MmsResult res;

    MmsNotification *notif = NULL;
    MeaAddrItem *from = NULL;

    kal_uint8 *text = NULL;
    char *str = NULL;
    int text_size = 0, file_size = 0;
    kal_uint8 *tmp_str = NULL;

    folder = fldrGetFolderId(msgId);
    if ((fileType = fldrGetFileSuffix(msgId)) != MMS_SUFFIX_NOTIFICATION && fileType != MMS_SUFFIX_IMMEDIATE)
    {
        return NULL;
    }

    MMS_FILE_OPEN_BLOCK_FLAG = TRUE;
    if ((MMS_RESULT_OK != MMSlib_messageOpen(MSF_MODID_MEA, msgId, fileType, &mHandle)) 
        || (MMS_RESULT_OK != MMSlib_transactionOpen(MSF_MODID_MEA, &tHandle)))
    {
        MMSlib_messageClose(MSF_MODID_MEA, &mHandle);
        MMSlib_transactionClose(MSF_MODID_MEA, &tHandle);
        MMS_FILE_OPEN_BLOCK_FLAG = FALSE;
        return NULL;
    }

    MMS_FILE_OPEN_BLOCK_FLAG = FALSE;    
    MEA_CALLOC(notif, sizeof(MmsNotification));
    res = MMSlib_getNotification(MSF_MODID_MEA, notif, &mHandle, &tHandle);        

    if (res != MMS_RESULT_OK) 
    {
        MMSlib_messageClose(MSF_MODID_MEA, &mHandle);
        MMSlib_transactionClose(MSF_MODID_MEA, &tHandle);
        MMSlib_freeMmsNotification(MSF_MODID_MEA, notif);
        return NULL;
    } 
    
    MMSlib_messageClose(MSF_MODID_MEA, &mHandle);
    MMSlib_transactionClose(MSF_MODID_MEA, &tHandle);
	
    /* Prepare text. widget_ucs2str_append_* will realloc the buffer if necessary*/
    text_size = 300;
    text = MEA_ALLOC(text_size);
    widget_utf8_to_ucs2_string(text, text_size, (kal_uint8*) "");

    /* From */
    from = meaMmsFromToAddrItem(&notif->from);
    meaNameLookup(from, (MeaStateMachine)0, (int)0);
    text = widget_ucs2str_append_id(MSF_MODID_MEA, text, &text_size, MEA_STR_ID_FROM);
    text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)":\n");
    if(from)
    {
        str = meaAddrItemToStr(from);
        if(widget_utf8_to_ucs2_length_in_bytes((kal_uint8 *)str) + ENCODING_LENGTH > MEA_MAX_ADDRS_STRLEN)
        {
            tmp_str = MEA_ALLOC(MEA_MAX_ADDRS_STRLEN);
            memset(tmp_str, 0, MEA_MAX_ADDRS_STRLEN);
            widget_utf8_to_ucs2_string(tmp_str, MEA_MAX_ADDRS_STRLEN - ENCODING_LENGTH, (kal_uint8 *)str);
            text = widget_ucs2str_append_ucs2(MSF_MODID_MEA, text, &text_size, tmp_str);
            MEA_FREE(tmp_str);
        }
        else
        {
            text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)str);
        }
        MEA_FREE(str);
    }
    else
    {
        text = widget_ucs2str_append_id(MSF_MODID_MEA, text, &text_size, MEA_STR_ID_EMPTY_LIST);
    }
    text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)"\x1B\n");

    /* Subject */
    text = widget_ucs2str_append_id(MSF_MODID_MEA, text, &text_size, MEA_STR_ID_SUBJECT);
    text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)":\n");

    if (notif->subject.text)
    {
        if(widget_utf8_to_ucs2_length_in_bytes((kal_uint8 *)notif->subject.text) + ENCODING_LENGTH > MEA_MAX_ADDRS_STRLEN)
        {
            tmp_str = MEA_ALLOC(MEA_MAX_ADDRS_STRLEN);
            memset(tmp_str, 0, MEA_MAX_ADDRS_STRLEN);
            widget_utf8_to_ucs2_string(tmp_str, MEA_MAX_ADDRS_STRLEN - ENCODING_LENGTH, (kal_uint8 *)notif->subject.text);
            text = widget_ucs2str_append_ucs2(MSF_MODID_MEA, text, &text_size, tmp_str);
            MEA_FREE(tmp_str);
        }
        else
        {
            text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)notif->subject.text);
        }
    }
    else
    {
        text = widget_ucs2str_append_id(MSF_MODID_MEA, text, &text_size, MEA_STR_ID_EMPTY_LIST);
    }
    text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)"\x1B\n");

    /*Download size */
    text = widget_ucs2str_append_id(MSF_MODID_MEA, text, &text_size, MEA_STR_ID_DOWNLOAD_SIZE);
    text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)":\n");

    str = MEA_ALLOC(strlen("300 K")+1);
    sprintf(str, "%luK", (notif->length + MEA_1_KB - 1) / MEA_1_KB);
    text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)str);
    MEA_FREE(str);
    text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)"\x1B\n");

    /* Size */
    text = widget_ucs2str_append_id(MSF_MODID_MEA, text, &text_size, MEA_STR_ID_NOTIFICATION_SIZE);
    text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)":\n");

    str = MMSlib_getMessageFullPath(MSF_MODID_MEA, msgId, fileType);
    if (str)
    {
        file_size = HDIa_fileGetSize(str);
        MEA_FREE(str);	
    }
    else
    {
        file_size = 0;
    }
    str = MEA_ALLOC(strlen("300 K") + 1);
    sprintf(str, "%iK", (file_size + MEA_1_KB - 1) / MEA_1_KB);
    text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)str);

    MEA_FREE(str);
    MMSlib_freeMmsNotification(MSF_MODID_MEA, notif);
    if (from)
    {
        meaAddrListFree(&from);
    }
    return (char *)text;
}

#endif /* WAP_SUPPORT */
#ifdef __DRM_SUPPORT__
/* ! \brief file extension to MEA media type
 *
 * \param file name string.
 * \return The MEA media type
 *****************************************************************************/
MeaMediaType meaDrm2MediaType(char * fileName)
{
    MeaMediaType retType = MEA_MEDIA_TYPE_UNKNOWN;
    const char * extensionPtr = strrchr(fileName,'.');
    if (extensionPtr)
        retType = meaMime2MediaType(msf_mime_ext_to_mime(extensionPtr+1));
    return retType;
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
MSF_UINT8 meaDrmGetMethod(const char *filepath)
{
    MSF_UINT8 drmMethod = DRM_METHOD_NONE;
    kal_uint8* externalFileName = HDI_FileNameTranslate(filepath);
    drmMethod = (MSF_UINT8)DRM_get_object_method(0, (kal_wchar *)externalFileName);
    HDI_FileNameFree(externalFileName);
    return drmMethod;
} 
#endif /* __DRM_SUPPORT__ */

/* ! \brief MIME to MEA media type
 *
 * \param mime The mime type string.
 * \return The MEA media type
 *****************************************************************************/
MeaMediaType meaMime2MediaType(const char *mime)
{
    unsigned int i = 0;
    const MeaMediaObjects *items;
#ifdef WAP_SUPPORT
    if (mime == NULL)
        return MEA_MEDIA_TYPE_UNKNOWN;
#endif /* WAP_SUPPORT */

    items = supportedMediaObjects;
    while (items[i].mediaType != MEA_MEDIA_TYPE_UNKNOWN)
    {
        if (0 == msf_cmmn_strcmp_nc(mime, items[i].mimeType))
        {
            return items[i].mediaType;
        }
        ++i;
    }
    return MEA_MEDIA_TYPE_UNKNOWN;
}

/* ! \brief MEA media type to MIME 
 *
 * \param mediaType The MEA media type.
 * \return The mime type string. This string should NOT be freed!
 *****************************************************************************/
char *meaMediaType2Mime(MeaMediaType mediaType)
{
    unsigned int i = 0;
    const MeaMediaObjects *items;

    items = supportedMediaObjects;
    while (items[i].mediaType != MEA_MEDIA_TYPE_UNKNOWN)
    {
        if (items[i].mediaType == mediaType)
        {
            return (char *)items[i].mimeType;
        }
        ++i;
    }
    return NULL;
}

/*!
 * \brief Checks if the character type can be displayed.
 *
 * \param charset The #MmsCharset character type.
 * \return a charset if the character can be used, otherwise MSF_CHARSET_UNKNOWN
 *****************************************************************************/
MSF_UINT32 meaIsValidCharset(MmsCharset charset)
{
    const MeaCharsetConv *current = supportedCharsets;
    unsigned int i;
    /* Check if it is possible to do display the charset type*/
    for (i = 0; current[i].msfCharset != MMS_UNKNOWN_CHARSET; i++)
    {
        if (current[i].mmsCharset == charset)
        {
            return current[i].msfCharset;
        }
    }
    return MSF_CHARSET_UNKNOWN;
}

/*! \brief Removes the optional UTF-8 mark if it is present
 *
 * \param str The string to remove the "possible" UTF-8 mark from.
 *****************************************************************************/
static void handleUtf8Bom(char *str)
{
    if (NULL != str)
    {
        /* Check if the optional UTF-8 identifier is present */
        if ((strlen(str) > strlen(MEA_UTF8_BOM)) && 
            (memcmp(str, MEA_UTF8_BOM, strlen(MEA_UTF8_BOM)) == 0))
        {
            /* Move the content back in the buffer so that the identifier is
               removed */
            memmove(str, &(str[strlen(MEA_UTF8_BOM)]), 
                strlen(str) - strlen(MEA_UTF8_BOM) + 1);
        }
    }
}

/*!
 * \brief Converts text to UTF-8.
 *
 * \return TRUE if the conversion was successful, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaConvertToUTF8(int charset, MSF_UINT32 *size, unsigned char **text)
{
    /* MMS to MSF type conversion */
    msf_charset_convert_t *convFunc;
    long destSize;
    long srcSize;
    char *destBuffer;
    int length;

    /* Handle types that do not need any conversion */
    if ( (charset == MSF_CHARSET_UTF_8) || 
         (charset == MSF_CHARSET_ASCII))
    {
        /* Make sure that a '\0' termination is present at the end */
        if ((*text)[*size] != MSF_EOS)
        {
            /* Allocate the old text size + room for the '\0' termination */
            MEA_CALLOC(destBuffer, *size + 1);
            memcpy(destBuffer, *text, *size);
            /* Free the old data */
            MEA_FREE(*text);
            /* Set the new buffer */
            *size = strlen(destBuffer) + 1;
            *text = (unsigned char *)destBuffer;
        }
        /* Removes the option UTF8 identifier if present */
        handleUtf8Bom((char *)*text);
        return TRUE;
    }
    /* Handle character set conversion */
    length = (int)*size;
    convFunc = msf_charset_find_function_bom(charset, MSF_CHARSET_UTF_8, 
        (char *)*text, &length);
    if (NULL != convFunc)
    {
        srcSize = *size;

        /* Find buffer size, tell MSF we have lots of memory available */
        destSize = (long)((unsigned long)-1 >> 1);
        if (0 != convFunc((char *)*text, &srcSize, NULL, &destSize))
        {
            return FALSE;
        }
        /* Allocate buffer, allocate one extra byte so that there is always
           space for the '\0' termination */
        MEA_CALLOC(destBuffer, (unsigned long)destSize + sizeof(char));

        /* Do the conversion */
        if (0 != convFunc((char *)*text, (long *)size, destBuffer, 
            &destSize))
        {
            /*lint -e{774}*/
            MEA_FREE(destBuffer);
            return FALSE;
        }
        MEA_FREE(*text);
        *text = (unsigned char*)destBuffer;
        *size = strlen(destBuffer) + 1;
        /* Removes the option UTF8 identifier if present */
        handleUtf8Bom((char *)*text);
        return TRUE;
    }
    return FALSE;
}

/*! \brief Removes the slash '/' character from the file path.
 *
 * \param The filename including the path. This string is changed after 
 *        completion of this function.
 *****************************************************************************/
void meaRemPathFromFileName(char *fileName)
{
    char *tmp;
    unsigned int i;
    if (NULL == fileName)
    {
        return;
    }
    tmp = fileName;
    /* Find the last '/' */
    while(NULL != strchr(tmp, '/'))
    {
        /* get next "/"*/
        /*lint -e{613} */
        tmp = strchr(tmp, '/');
        /*lint -e{613} */
        tmp = &(tmp[1]);
    }
    /* Remove the "path" part  */
    for (i = 0; i < strlen(tmp) + 1; i++)
    {
        fileName[i] = tmp[i];
    }
}

/*!
 * \brief Converts media types from mea to MSF types
 *
 * \param format Media type to convert from
 * \return MSF media type
 *****************************************************************************/
MSF_UINT32 meaConvertMediaTypeToMsf(MeaMediaType mediaType)
{
    unsigned int i = 0;
    const MeaMediaObjects *items = supportedMediaObjects;
	
    while(MEA_MEDIA_TYPE_UNKNOWN != items[i].mediaType)
    {
        if(items[i].mediaType == mediaType && 
	    (MEA_MEDIA_GROUP_IMAGE == items[i].objectType || MEA_MEDIA_GROUP_AUDIO == items[i].objectType ||
	    MEA_MEDIA_GROUP_VIDEO == items[i].objectType))
        {
            return items[i].msfType;
        }
        ++i;
    }
    return 0;
} /* meaConvertMediaTypeToMsf */

MeaMediaType meaConvertMsfTypeToMediaType(MSF_UINT32 msfType)
{
    unsigned int i = 0;
    const MeaMediaObjects *items = supportedMediaObjects;
	
    while(MEA_MEDIA_TYPE_UNKNOWN != items[i].mediaType)
    {
        if(items[i].msfType == msfType && 
	    (MEA_MEDIA_GROUP_IMAGE == items[i].objectType || MEA_MEDIA_GROUP_AUDIO == items[i].objectType ||
	    MEA_MEDIA_GROUP_VIDEO == items[i].objectType))
        {
            return items[i].mediaType;
        }
        ++i;
    }
    return MEA_MEDIA_TYPE_UNKNOWN;
}

/*!
 * \brief Converts a MeaMediaType to a SlsMediaType
 *
 * \param mediaType Media type to convert
 * \return #SlsMediaType Converted media type
 *****************************************************************************/
SlsMediaType meaConvertMediaTypeToSls(MeaMediaType mediaType)
{
    unsigned int i = 0;
    const MeaMediaObjects *items;
    /*lint -e{788} */
    items = supportedMediaObjects;
    while(MEA_MEDIA_TYPE_UNKNOWN != items[i].mediaType)
    {
        if (mediaType == items[i].mediaType)
        {
            return items[i].slsMediaType;
        }
        ++i;
    }
    return SLS_NOT_USED;
} /* convertMediaTypeToSls */

/*!
 * \brief Converts MEA types to MMS type.
 * \param mediaType The MMS media types.
 * \param outType The MEA media type to convert to.
 * \param outStr The media type as string, if no integer value is valid.
 * \return TRUE on successful conversion, otherwise FALSE;
 *****************************************************************************/
MSF_BOOL meaMediaTypeMeaToMms(const MeaMediaType mediaType, 
    MmsKnownMediaType *outType, char **outStr)
{
    unsigned int i;
    const MeaMediaObjects *items;
    *outStr = NULL;
    /*lint -e{788} */

    items = supportedMediaObjects;
    i = 0;
    while (MEA_MEDIA_TYPE_UNKNOWN != items[i].mediaType)
    {
        if (mediaType == items[i].mediaType)
        {
            if (MMS_VALUE_AS_STRING != items[i].assignedValue)
            {
                *outType = items[i].assignedValue;
                return TRUE;
            }
            else
            {
                if (NULL == (*outStr =
                    msf_cmmn_strdup(MSF_MODID_MEA, items[i].mimeType)))
                {
                    return FALSE;
                }
                return TRUE;
            }
        }
        ++i;
    }
    MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
        MAUTILS_414D8145857CABF0537100D8F83B1643, "(%s) (%d) erroneous media type\n", __FILE__, __LINE__));
    return FALSE;
}

/*!
 * \brief Converts SLS media type to a MEA media type value.
 *
 * \param slsMediaType The SLS media type, #see SlsMediaType.
 * \return The corresponding  MEA media type, see #MeaMediaType.
 *****************************************************************************/
MeaMediaType meaSlsMediaTypeToMea(SlsMediaType slsMediaType)
{
    const MeaMediaObjects *items;
    unsigned int i;

    i = 0;
    items = supportedMediaObjects;
    while(MEA_MEDIA_TYPE_UNKNOWN != items[i].mediaType)
    {
        if (items[i].slsMediaType == slsMediaType)
        {
            return items[i].mediaType;
        }
        ++i;
    }
    return MEA_MEDIA_TYPE_UNKNOWN;
}

/*!
 * \brief Converts SLS media type to a MEA media type value.
 *
 * \param slsMediaType The SLS media type, #see SlsMediaType.
 * \return The corresponding  MEA media type, see #MeaMediaType.
 *****************************************************************************/
MeaMediaType meaMmsKnownValueToMea(MmsKnownMediaType mmsMediaType)
{
    const MeaMediaObjects *items;
    unsigned int i;

    i = 0;
    items = supportedMediaObjects;
    while(MEA_MEDIA_TYPE_UNKNOWN != items[i].mediaType)
    {
        if (items[i].assignedValue == mmsMediaType)
        {
            return items[i].mediaType;
        }
        ++i;
    }
    return MEA_MEDIA_TYPE_UNKNOWN;
}

/*! \brief Converts a #MmsKnownMediaType to a mime-string.
 *	
 * \param knownType The MMS type.
 * \return The MIME type or NULL. The caller is responsbe for de-allocating 
 *         the data.
 *****************************************************************************/
char *meaKnownValueToMimeType(MmsKnownMediaType knownType)
{
    const char *tmp;

    if (NULL != (tmp = msf_cmmn_int2str(knownType, &msf_mime_types)))
    {
        return msf_cmmn_strdup(MSF_MODID_MEA, tmp);
    }
    return NULL;
}

#ifndef WAP_SUPPORT 
/*! \brief Converts the mime-type into a known value.
 *
 * \param mimeType The mime-type to get the known value from.
 * \return The corresponding 
 *****************************************************************************/
MSF_BOOL meaMimeTypeToKnownValue(const char *mimeType, MSF_UINT32 *knownValue)
{
    int type;
    type = msf_cmmn_str2int(mimeType, strlen(mimeType), &msf_mime_types);
    if (-1 != type)
    {
        *knownValue = type;
        return TRUE;
    }
    return FALSE;
}
#endif /* ~WAP_SUPPORT */

#ifdef WAP_SUPPORT
/*! \brief Copies a #SlsUnrefItemList data-structure.
 *
 * \param info The data to copy.
 * \return A copy of the #SlsUnrefItemList data-structure.
 *****************************************************************************/
SlsUnrefItemList *meaCopySlsUnrefList(SlsUnrefItemList *sourceList)
{
	SlsUnrefItemList *destList = NULL, *destListStart = NULL;
	if (sourceList == NULL)
	{
		return NULL;
	}

	while (sourceList != NULL)
	{
        if(msf_cmmn_strcmp_nc(sourceList->contentType, MMS_MEDIA_TYPE_STRING_SMIL) != 0)
        {
            if(destList == NULL)
            {
                destList = MEA_ALLOC(sizeof(SlsUnrefItemList));
                memset(destList, 0x00, sizeof(SlsUnrefItemList));
                destListStart = destList;
            }
            destList->offset = sourceList->offset;
            destList->size = sourceList->size;
            destList->mediaType = sourceList->mediaType;
            if (sourceList->boundary)
            {
                destList->boundary = msf_cmmn_strdup(MSF_MODID_MEA, sourceList->boundary);
            }
            
            if (sourceList->fileName)
            {
                destList->fileName = msf_cmmn_strdup(MSF_MODID_MEA, sourceList->fileName);
            }
            if (sourceList->contentType)
            {
                destList->contentType = msf_cmmn_strdup(MSF_MODID_MEA, sourceList->contentType);
            }
            
            if(sourceList->next != NULL)
            {
                destList->next = MEA_ALLOC(sizeof(SlsUnrefItemList));
                memset(destList->next, 0x00, sizeof(SlsUnrefItemList));
                destList = destList->next;
            }
        }
        sourceList = sourceList->next;
	}

	return destListStart;
} /* copySlsUnrefList */

/*! \brief Dealloctes the attachemnt list
 *
 * \param attach The attachemnt list to deallocate.
 *****************************************************************************/
void meaFreeUnrefList(SlsUnrefItemList **list)
{
    SlsUnrefItemList *current;
    SlsUnrefItemList *tmp;
    if ((NULL != list) && (NULL != *list))
    {
        current = *list;
        while(NULL != current)
        {
            if (NULL != current->fileName)
            {
                MEA_FREE(current->fileName);
            }
            if (NULL != current->boundary)
            {
                MEA_FREE(current->boundary);
            }
            /* Next item */
            tmp = current;
            current = current->next;
            MEA_FREE(tmp);
        }
        *list = NULL;
    }
}
#endif
/*! \brief Copies a #SlsGetSlideInfoRsp data-structure.
 *
 * \param info The data to copy.
 * \return A copy of the #SlsGetSlideInfoRsp data-structure.
 *****************************************************************************/
SlsGetSlideInfoRsp *meaCopySlsSlideInfo(const SlsGetSlideInfoRsp *info)
{
    SlsGetSlideInfoRsp *newInfo;
    if (NULL == info)
    {
        return NULL;
    }
    /* Root info */
    newInfo = MEA_ALLOC_TYPE(SlsGetSlideInfoRsp);
    memset(newInfo, 0, sizeof(SlsGetSlideInfoRsp));

    newInfo->result = info->result;
    /* Text */
    newInfo->slideInfo.text = info->slideInfo.text;
    newInfo->slideInfo.text.fileName = 
        msf_cmmn_strdup(MSF_MODID_MEA, info->slideInfo.text.fileName);
    newInfo->slideInfo.text.boundary = 
        msf_cmmn_strdup(MSF_MODID_MEA, info->slideInfo.text.boundary);
    /* Image */
    newInfo->slideInfo.image = info->slideInfo.image;
    newInfo->slideInfo.image.fileName = 
        msf_cmmn_strdup(MSF_MODID_MEA, info->slideInfo.image.fileName);
    newInfo->slideInfo.image.boundary = 
        msf_cmmn_strdup(MSF_MODID_MEA, info->slideInfo.image.boundary);
    newInfo->slideInfo.image.alt = 
        msf_cmmn_strdup(MSF_MODID_MEA, info->slideInfo.image.alt);
    /* Audio */
    newInfo->slideInfo.audio = info->slideInfo.audio;
    newInfo->slideInfo.audio.fileName = 
        msf_cmmn_strdup(MSF_MODID_MEA, info->slideInfo.audio.fileName);
    newInfo->slideInfo.audio.boundary = 
        msf_cmmn_strdup(MSF_MODID_MEA, info->slideInfo.audio.boundary);
    newInfo->slideInfo.audio.alt = 
        msf_cmmn_strdup(MSF_MODID_MEA, info->slideInfo.audio.alt);
    /* Video */
    newInfo->slideInfo.video = info->slideInfo.video;
    newInfo->slideInfo.video.fileName = 
        msf_cmmn_strdup(MSF_MODID_MEA, info->slideInfo.video.fileName);
    newInfo->slideInfo.video.boundary = 
        msf_cmmn_strdup(MSF_MODID_MEA, info->slideInfo.video.boundary);
    newInfo->slideInfo.video.alt = 
        msf_cmmn_strdup(MSF_MODID_MEA, info->slideInfo.video.alt);

    newInfo->slideInfo.duration = info->slideInfo.duration;
    
    
    
    return newInfo;
}

/*! \brief De-alloctes a #SlsGetSlideInfoRsp data-structure
 *
 * \param info A refernece to the data to release.
 *****************************************************************************/
void meaFreeSlsSlideInfo(SlsGetSlideInfoRsp *info)
{
    if (NULL == info)
    {
        return;
    }
    MEA_FREE(info->slideInfo.text.fileName);
    MEA_FREE(info->slideInfo.text.boundary);
    MEA_FREE(info->slideInfo.image.fileName);
    MEA_FREE(info->slideInfo.image.boundary);
    MEA_FREE(info->slideInfo.image.alt);
    MEA_FREE(info->slideInfo.audio.fileName);
    MEA_FREE(info->slideInfo.audio.boundary);
    MEA_FREE(info->slideInfo.audio.alt);
    MEA_FREE(info->slideInfo.video.fileName);
    MEA_FREE(info->slideInfo.video.boundary);
    MEA_FREE(info->slideInfo.video.alt);
    MEA_FREE(info);
}

#ifdef WIDGET_VIRTUAL_FILE_SUPPORT
/*! \brief Create widget resource by using virtual file mechanism
 *
 * \param mType		[IN]
 * \param *filename	[IN]
 * \param offset		[IN]
 * \param size			[IN]
 *****************************************************************************/
MSF_UINT32 meaCreateVirtualFileResource(MeaMediaType mType, const char *filename, int offset, int size)
{
    MeaMediaGroupType gType = meaMediaType2ObjType(mType);
    MsfPartialFileData *data = NULL;
    MSF_UINT32 handle = 0;

    if(filename == NULL || size == 0)
	{
	    return 0;
	}

    if(!(gType & (MEA_MEDIA_GROUP_IMAGE | MEA_MEDIA_GROUP_AUDIO | MEA_MEDIA_GROUP_VIDEO)))
    {
        return 0;
    }

    MEA_CALLOC(data,sizeof(MsfPartialFileData));	
    ASSERT(data != NULL);
    MEA_CALLOC(data->filename,strlen(filename)+1);
    ASSERT(data->filename != NULL);
    strcpy(data->filename, filename);
    data->start_offset=offset;
    data->data_size=size;				

    switch(gType)
    {
        case MEA_MEDIA_GROUP_IMAGE:
        {
            MsfImageFormat msfFormat = (MsfImageFormat)meaConvertMediaTypeToMsf(mType);
            handle = MSF_WIDGET_IMAGE_CREATE_RESOURCE(MSF_MODID_MEA, (char*)data, (MsfResourceType)MsfResourcePartialFile, msfFormat);
            break;
        }
        case MEA_MEDIA_GROUP_AUDIO:
        {
            MsfSoundFormat msfFormat = (MsfSoundFormat)meaConvertMediaTypeToMsf(mType);
            handle = MSF_WIDGET_SOUND_CREATE_RESOURCE(MSF_MODID_MEA, (char*)data, (MsfResourceType)MsfResourcePartialFile, msfFormat);
            break;
        }
        case MEA_MEDIA_GROUP_VIDEO:
        {
            MsfVideoFormat msfFormat = (MsfVideoFormat)meaConvertMediaTypeToMsf(mType);
            handle = MSF_WIDGET_EXT_VIDEO_CREATE_RESOURCE (MSF_MODID_MEA, (char*)data, (MsfResourceType)MsfResourcePartialFile, msfFormat);
            break;
        }
        default:
            break;
    }

    MEA_FREE(data->filename);
    MEA_FREE(data);
    return handle;
}

#ifdef __DRM_SUPPORT__
/*! \brief Create DRM widget resource by using virtual file mechanism
 *
 * \param mType		[IN]
 * \param *filename	[IN]
 * \param offset		[IN]
 * \param size			[IN]
 * \param msgId		[IN]
 * \param fileHandle	[IN]
 * \param *drmType	[OUT]
 *****************************************************************************/
MSF_UINT32 meaCreateDrmVirtualFileResource(MeaMediaType mType, const char *filename, int offset, int size, 
    MmsMsgId msgId, MSF_INT32 fileHandle, MeaMediaType *drmType)
{
    char *vFileName = NULL;					/* vitual file name */
    unsigned char *externalVFileName = NULL;	/* translated UCS2 vitual file name */
    MSF_UINT32 handle = 0;

    if(fileHandle <= 0 || filename == NULL || size == 0)
    {
        return 0;
    }
    ASSERT(drmType != NULL);
    
    /*generate virtual file */
    MEA_CALLOC(vFileName, WIDGET_RAWFILE_NAMELEN);
    ASSERT(vFileName != NULL);
    if(HDIa_fileGenVirtualFileName(fileHandle, vFileName, WIDGET_RAWFILE_NAMELEN, offset, size) != HDI_FILE_OK)
    {
        MEA_CFREE(vFileName);
        return 0;
    }
    externalVFileName = HDI_FileNameTranslate(vFileName);

    if (mType == MEA_MEDIA_TYPE_DRM_MESSAGE)  /* FL, CD */
    {
        MSF_INT32 drmOffset = 0, drmSize = 0;
#ifdef MTK_TMP_PATCH  /* To fix issue casued by DRM interface change for Jataayu */
        char fileNameUTF8[WIDGET_RAWFILE_NAMELEN];
        char *outputFile = NULL;

        /* Get raw data offset */
        memset(fileNameUTF8, 0, WIDGET_RAWFILE_NAMELEN);
        sprintf(fileNameUTF8, "%s%lx-%x.vvvvvvvvvv", MMS_FOLDER, msgId, offset);
        outputFile = (char *) HDI_FileNameTranslate(fileNameUTF8);
        drmOffset = DRM_process_direct_file((kal_uint8 *)"application/vnd.oma.drm.message", (kal_wchar *) externalVFileName, (kal_wchar *) outputFile, (kal_uint32 *)&drmSize);
        widget_ucs2_to_utf8_string((kal_uint8 *)fileNameUTF8, WIDGET_RAWFILE_NAMELEN, (kal_uint8 *)outputFile);
        *drmType= meaMime2MediaType(meaFileName2MimeType(fileNameUTF8));
        sprintf(outputFile, "%s%s", HDI_EXTERNAL_PATH, fileNameUTF8);
        MSF_FILE_REMOVE(outputFile);
        HDI_FileNameFree((kal_uint8 *)outputFile);
#else
        static char fileNameUTF8[100];
        static unsigned char fileNameUCS2[200];

        /* Get raw data offset */
        sprintf(fileNameUTF8, "%lx-%x.vvvvvvvvvv", msgId, offset);
        widget_utf8_to_ucs2_string(fileNameUCS2, 200, (const kal_uint8 *)fileNameUTF8);
        drmOffset = DRM_process_direct_file((kal_uint8 *)"application/vnd.oma.drm.message", (kal_wchar *) externalVFileName, (kal_wchar *) fileNameUCS2, (kal_uint32 *)&drmSize);
        widget_ucs2_to_utf8_string((kal_uint8 *)fileNameUTF8, 100, fileNameUCS2);
        *drmType= meaMime2MediaType(meaFileName2MimeType(fileNameUTF8));
#endif
        /* create resource */
        if(*drmType != MEA_MEDIA_TYPE_UNKNOWN && drmOffset >= DRM_RESULT_OK)
        {
            MsfPartialFileData* data = NULL;
            MeaMediaGroupType drmGType = meaMediaType2ObjType(*drmType);
            
            MEA_CALLOC(data, sizeof(MsfPartialFileData));
            ASSERT(data != NULL);
            MEA_CALLOC(data->filename, strlen(filename)+1);
            ASSERT(data->filename != NULL);
            strcpy(data->filename,filename);

            data->start_offset = offset + drmOffset;
            data->data_size = drmSize;

            switch (drmGType)
            {
                case MEA_MEDIA_GROUP_IMAGE:
                {
                    MsfImageFormat msfFormat = (MsfImageFormat)meaConvertMediaTypeToMsf(*drmType);
                    handle = MSF_WIDGET_IMAGE_CREATE_RESOURCE(MSF_MODID_MEA, (char*)data, (MsfResourceType)MsfResourcePartialFile, msfFormat);
                    break;
                }
                case MEA_MEDIA_GROUP_AUDIO:
                {
                    MsfSoundFormat msfFormat = (MsfSoundFormat)meaConvertMediaTypeToMsf(*drmType);
                    handle = MSF_WIDGET_SOUND_CREATE_RESOURCE(MSF_MODID_MEA, (char*)data, (MsfResourceType)MsfResourcePartialFile, msfFormat);
                    break;
                }
                case MEA_MEDIA_GROUP_VIDEO:
                {
                    MsfVideoFormat msfFormat = (MsfVideoFormat)meaConvertMediaTypeToMsf(*drmType);
                    handle = MSF_WIDGET_EXT_VIDEO_CREATE_RESOURCE(MSF_MODID_MEA, (char*)data, (MsfResourceType)MsfResourcePartialFile, msfFormat);
                    break;
                }
                default:
                    break;
            }
            MEA_CFREE(data->filename);
            MEA_CFREE(data);
        }

        HDI_FileNameFree(externalVFileName);
        MEA_CFREE(vFileName);
        return handle;
    }    
    else if (mType == MEA_MEDIA_TYPE_DRM_CONTENT)  /* SD */
    {
        DRM_process_virtual_file ((kal_uint8 *)"application/vnd.oma.drm.content", (kal_wchar *) externalVFileName, NULL); /* generate RO */
        *drmType = meaMime2MediaType((char*)DRM_get_content_type(0, (kal_wchar *) externalVFileName));
        if(*drmType != MEA_MEDIA_TYPE_UNKNOWN)
        {
            MeaMediaGroupType drmGType = meaMediaType2ObjType(*drmType);
            MSF_UINT8 permission = (kal_uint8)((drmGType == MEA_MEDIA_GROUP_IMAGE) ? DRM_PERMISSION_DISPLAY : DRM_PERMISSION_PLAY);

            if(DRM_validate_permission(0, (kal_wchar *) externalVFileName, permission))
            {
                switch (drmGType)
                {
                    case MEA_MEDIA_GROUP_IMAGE:
                    {
                        MsfImageFormat msfFormat = (MsfImageFormat)meaConvertMediaTypeToMsf(*drmType);
                        handle = MSF_WIDGET_IMAGE_CREATE_RESOURCE(MSF_MODID_MEA, vFileName, (MsfResourceType)MsfResourceDRMFile, msfFormat);
                        break;
                    }
                    case MEA_MEDIA_GROUP_AUDIO:
                    {
                        MsfSoundFormat msfFormat = (MsfSoundFormat)meaConvertMediaTypeToMsf(*drmType);
                        handle = MSF_WIDGET_SOUND_CREATE_RESOURCE(MSF_MODID_MEA, vFileName, (MsfResourceType)MsfResourceDRMFile, msfFormat);
                        break;
                    }
                    case MEA_MEDIA_GROUP_VIDEO:
                    {
                        MsfVideoFormat msfFormat = (MsfVideoFormat)meaConvertMediaTypeToMsf(*drmType);
                        handle = MSF_WIDGET_EXT_VIDEO_CREATE_RESOURCE(MSF_MODID_MEA, vFileName, (MsfResourceType)MsfResourceDRMFile, msfFormat);
                        break;
                    }
                    default:
                        break;
                	}
            }
        }
    }
    else
    {
        WAP_DBG_ASSERT(0);		/* should not be here */
    }

    HDI_FileNameFree(externalVFileName);
    MEA_CFREE(vFileName); 
    return handle;

}
#endif
#endif
