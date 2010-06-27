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

/*!\file macth.c
 *  Cross triggering handling.
 */

/* MSF */
#include "msf_cfg.h"
#include "msf_mem.h"
#include "msf_def.h"
#include "msf_cmmn.h"
#include "msf_lib.h"
#include "msf_core.h"
#include "msf_wid.h"
#include "msf_log.h"
#include "msf_file.h"

/* MMS */
#include "mms_def.h"

/* SLS */
#include "sls_cfg.h"
#include "sls_def.h"
#include "sls_if.h"

/* MEA */
#include "mea_rc.h"
#include "mea_cfg.h"
#include "mea_def.h"
#include "matypes.h"
#include "mamem.h"
#include "maintsig.h"
#include "macore.h"
#include "mauicmn.h"
#include "maasync.h"
#include "mauidia.h"
#include "macth.h"
#include "mamr.h"
#include "mame.h"
#include "mautils.h"
#include "masch.h"
#include "maph.h"
#ifdef WAP_SUPPORT
#include "mase.h"  //for meaSetAttachment
#include "maconf.h" //for meaConfGetCreationMode
#endif /* WAP_SUPPORT */
#ifdef __DRM_SUPPORT__
#include "widget_extension.h"
#include "fs_type.h"
#include "../../drm/include/drm_def.h" //for DRM_METHOD_FORWARD_LOCK
#include "../../drm/include/drm_gprot.h"
#include "../../drm/include/drm_main.h" //for DRM_get_object_method
#endif /* __DRM_SUPPORT__ */
#ifdef JPG_ENCODE
#include "mautils.h"  /* meaIsResizedFile() */
#endif

/*! \file macth.c
 */

/******************************************************************************
 * Constants
 *****************************************************************************/
typedef enum
{
    MEA_CTH_RESULT_OK,
    MEA_CTH_RESULT_ERROR
}MeaCthResult;

/******************************************************************************
 * Data-structures
 *****************************************************************************/

/*! \struct MeaCthInsert
 * Data-structure for storing information about content routing (Image)
 */
typedef struct
{
    char                    *buffer;        /*!< The buffer storing the image data */
    MSF_INT32               bufferSize;     /*!< The size of the buffer */
    char                    *url;       /*!< The name of the media object*/
    char                    *fileName;      /*!< The filename if the data is retrieved through a file */
    MeaMediaType            mediaType;      /*!< The media type of the content */
    MeaPropItem             *propItem;      /*!< Message properties */

    /* MTK-added field */
    MSF_BOOL isTruncated;  /* Imported text may be truncated */
}MeaCthInsert;

/*! \struct MeaCtFilterItem
*/
typedef struct
{
	const char          *asString;  /*!< The media type as a string  */
	const MeaMediaType  asInteger;  /*!< The media type as an integer,
										see #MeaMediaType */
}MeaCthFilterItem;

/******************************************************************************
 * Variables
 *****************************************************************************/

/*! Data-structure used when starting in content routing mode */
static MeaCthInsert *insertInst;

/*! Media types supported for starting the MEA in "insert" mode. */
static const MeaCthFilterItem meaCtInsertFilter[] = MEA_CFG_CT_MIME_2_MT;

static const MeaCthFilterItem meaCtInsertRestrictedFilter[] = MEA_CFG_CT_RESTRICTED_MIME_2_MT;
/******************************************************************************
 * Prototypes
 *****************************************************************************/
static void cthCreateInstance(MeaCthInsert **instance);
static void cthDeleteInstance(MeaCthInsert **instance, MeaCthResult result);
static void cthSignalHandler(MeaSignal *sig);

/******************************************************************************
 * Function implementation
 *****************************************************************************/

/*!
 * \brief Initiates the CTH FSM.
 *
 *****************************************************************************/
void meaCthInit()
{
    insertInst = NULL;
    meaSignalRegisterDst(MEA_CTH_FSM, cthSignalHandler);
}

/*!
 * \brief Terminates the CTH FSM.
 *
 *****************************************************************************/
void meaCthTerminate()
{
    if (NULL != insertInst)
    {
        cthDeleteInstance(&insertInst, MEA_CTH_RESULT_OK);
    }
    meaSignalDeregister(MEA_CTH_FSM);
}

/*! \brief Converts a mime-type to a media object type.
 *
 * \param mime The MIME type
 * \return The corresponding #MeaMediaObject type.
 *****************************************************************************/
static MeaMediaType mimeToMediaType(const char *mime)
{
    int i;

    if(meaConfGetCreationMode() == MEA_CREATION_MODE_RESTRICTED)
    {
	const char *attachMimeTypes = MEA_CFG_OPEN_RESTRICTED_ATTACHMENT_TYPES;

    	/* Can be insert as viewable media object */
        for (i = 0; NULL != meaCtInsertRestrictedFilter[i].asString; i++)
        {
            if (0 == msf_cmmn_strcmp_nc(meaCtInsertRestrictedFilter[i].asString, mime))
            {
                 return meaCtInsertRestrictedFilter[i].asInteger;
            }
        }

	/* Can be insert as attachment */
        if (strstr(attachMimeTypes, mime))
            return MEA_MEDIA_TYPE_UNKNOWN;
        else
            return MEA_MEDIA_TYPE_UNSUPPORT;		/* Can not be inserted */
    }
    else
        for (i = 0; NULL != meaCtInsertFilter[i].asString; i++)
        {
            if (0 == msf_cmmn_strcmp_nc(meaCtInsertFilter[i].asString, mime))
            {
                return meaCtInsertFilter[i].asInteger;
            }
        }
    return MEA_MEDIA_TYPE_UNKNOWN;
}

/*!
 * \brief Creates a new instance used for cross triggering (image)
 *
 * \param instance The current instance.
 *****************************************************************************/
static void cthCreateInstance(MeaCthInsert **instance)
{
    *instance = MEA_ALLOC(sizeof(MeaCthInsert));
    /* Clear the structure */
    memset(*instance, 0, sizeof(MeaCthInsert));
}

/*!
 * \brief Deletes cross triggering (image) a instance
 *
 * \param instance The current instance.
 * \param result The result that caused the deletion.
 *****************************************************************************/
static void cthDeleteInstance(MeaCthInsert **instance,
    MeaCthResult result)
{
    MeaCthInsert *inst = NULL;

    if (*instance != NULL)
    {
        inst = *instance;
        MEA_FREE(inst->buffer);
        inst->buffer = NULL;

        if (result != MEA_CTH_RESULT_OK)
        {
#ifdef JPG_ENCODE
            if(meaIsResizedFile(inst->fileName))
            {
                MSF_FILE_REMOVE(inst->fileName);
            }
#endif
        }

        MEA_FREE(inst->fileName);
        MEA_FREE(inst->url);
        MEA_FREE(inst);
        *instance = NULL;
    }
    if (result != MEA_CTH_RESULT_OK)
    {
#ifdef WAP_SUPPORT
        HDIa_widgetExtCloseTransitionAnimation();
#endif /* WAP_SUPPORT */

        /* If the start-up fails then terminate */
#ifdef __UNIFIED_MSG_SUPPORT__
        (void)MEA_SIGNAL_SENDTO(MEA_CORE_FSM, MEA_SIG_CORE_TERMINATE_APP);
#else
        MEA_TERMINATE;
#endif
    }
}

/*!
 * \brief Read content from a file.
 *
 * \param instance Current instance.
 *****************************************************************************/
static MSF_BOOL readContent(MeaCthInsert *instance)
{
    char *tmpFileName;
    tmpFileName = msf_cmmn_strdup(MSF_MODID_MEA, instance->fileName);
    if (!meaAfiLoadFromFile(MEA_CTH_FSM, MEA_SIG_CTH_FILE_NOTIFY,
        tmpFileName, NULL, ~((MSF_UINT32)0)))
    {
        return FALSE;
    }
    return TRUE;
}

/*!
 * \brief The signal handler for the CTH FSM.
 *
 * \param sig The current signal.
 *****************************************************************************/
static void cthSignalHandler(MeaSignal *sig)
{
    MeaPropItem *propItem;
    MeaCtContentInsert *ct;
    MeaStartupMode mode;
    MeaAfiReadResultData *afiData;

    /* Check which signal that was received */
    switch(sig->type)
    {
    case MEA_SIG_CTH_START:
        mode = (MeaStartupMode)sig->u_param1;
        if (MEA_STARTUP_MODE_NEW == mode)
        {
            /* The instance should have been created already */
            if (NULL == insertInst)
            {
                /* No instance has been created continue with the start-up anyway*/
                (void)MEA_SIGNAL_SENDTO_U(MEA_ME_FSM, MEA_SIG_ME_ACTIVATE, MEA_ME_STARTUP_NEW_SMIL);
                break;
            }

            if (NULL == insertInst->fileName)  /* No content to insert. Start with the message properties */
            {
                ct = MEA_ALLOC(sizeof(MeaCtContentInsert));
                memset(ct, 0, sizeof(MeaCtContentInsert));
                ct->propItem = insertInst->propItem;
                insertInst->propItem = NULL;

                (void)MEA_SIGNAL_SENDTO_UP(MEA_ME_FSM, MEA_SIG_ME_ACTIVATE, MEA_ME_STARTUP_NEW_SMIL, ct);
                cthDeleteInstance(&insertInst, MEA_CTH_RESULT_OK);
                break;
            }
            if (MEA_MEDIA_TYPE_UNKNOWN != insertInst->mediaType && MEA_MEDIA_TYPE_UNSUPPORT != insertInst->mediaType)  /* insert as resource */
            {
                if(insertInst->mediaType == MEA_MEDIA_TYPE_TEXT_PLAIN && insertInst->buffer != NULL)
                {
                    ct = MEA_ALLOC(sizeof(MeaCtContentInsert));
                    memset(ct, 0, sizeof(MeaCtContentInsert));
                    ct->buffer = (unsigned char *)insertInst->buffer;
                    ct->bufferSize = insertInst->bufferSize;
                    ct->name = insertInst->fileName;
                    ct->mediaType = insertInst->mediaType;
                    ct->propItem = insertInst->propItem;  /* message properties */
                    ct->isTruncated = insertInst->isTruncated;
                    insertInst->buffer = NULL;
                    insertInst->fileName = NULL;
                    insertInst->propItem = NULL;
                    (void)MEA_SIGNAL_SENDTO_UP(MEA_ME_FSM, MEA_SIG_ME_ACTIVATE, MEA_ME_STARTUP_NEW_SMIL, ct);
                    cthDeleteInstance(&insertInst, MEA_CTH_RESULT_OK);
                    break;
                }
                if(insertInst->mediaType != MEA_MEDIA_TYPE_TEXT_PLAIN)
                {
                    if (!readContent(insertInst))
	                {
	                    /* Content exists. Load the content before starting */
	                    meaSignalDelete(sig);  /* Delete the signal and terminate */
	                    cthDeleteInstance(&insertInst, MEA_CTH_RESULT_ERROR);  /* Long jump */
	                }
                    break;
                }
            }
            if (insertInst->mediaType != MEA_MEDIA_TYPE_UNSUPPORT && insertInst->fileName) /* inserted as attachment */
            {
                ct = MEA_ALLOC(sizeof(MeaCtContentInsert));
                memset(ct, 0, sizeof(MeaCtContentInsert));
                ct->propItem = insertInst->propItem;  /* message properties */
                insertInst->propItem = NULL;
                meaSeAddAttachment(insertInst->fileName);
                (void)MEA_SIGNAL_SENDTO_UP(MEA_ME_FSM, MEA_SIG_ME_ACTIVATE, MEA_ME_STARTUP_NEW_SMIL, ct);
                cthDeleteInstance(&insertInst, MEA_CTH_RESULT_OK);
                break;
            }
            if(insertInst->mediaType == MEA_MEDIA_TYPE_UNSUPPORT)
            {
                meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_RESTRICTED_MIME_ACTION_NONE), MEA_DIALOG_ALERT);            
                /* Delete the signal and terminate */
                meaSignalDelete(sig);
                /* Long jump */
                cthDeleteInstance(&insertInst, MEA_CTH_RESULT_ERROR);            
            }
            break;
        }
        if (MEA_STARTUP_MODE_SCHEME == mode)  /* Check if the application should be started with to, cc and/or subject filled in */
        {
            propItem = meaSchemeToPropItem(insertInst->url);
            ct = MEA_ALLOC(sizeof(MeaCtContentInsert));
            memset(ct, 0, sizeof(MeaCtContentInsert));
            ct->buffer       = NULL;
            ct->bufferSize   = 0;
            ct->mediaType    = MEA_MEDIA_TYPE_UNKNOWN;
            ct->propItem     = propItem;
            /* Time to start edit the message */
            (void)MEA_SIGNAL_SENDTO_UP(MEA_ME_FSM, MEA_SIG_ME_ACTIVATE, MEA_ME_STARTUP_NEW_SMIL, ct);
            cthDeleteInstance(&insertInst, MEA_CTH_RESULT_OK);
        }
        break;
        
    case MEA_SIG_CTH_FILE_NOTIFY:
        if (sig->u_param1 == MEA_AFI_READ_RESULT_OK)
        {
            afiData = sig->p_param;
            ct = MEA_ALLOC(sizeof(MeaCtContentInsert));
            memset(ct, 0, sizeof(MeaCtContentInsert));
            ct->name = insertInst->fileName;
            ct->mediaType = insertInst->mediaType;
            ct->propItem = insertInst->propItem;
            ct->buffer = afiData->data;
            ct->bufferSize = afiData->size;
            ct->resHandle = afiData->resHandle;
#ifdef __DRM_SUPPORT__
            {
                kal_uint8* externalFileName;
                int objType;

                externalFileName = HDI_FileNameTranslate(afiData->fileName);
                objType = DRM_get_object_method(0, (kal_wchar *)externalFileName);
                if (objType == DRM_METHOD_FORWARD_LOCK || objType == DRM_METHOD_COMBINED_DELIVERY)
                {
                    /* For safety: DRM_MESSAGE should reject in mms_content_insert_hdlr */
                    (void)meaShowDialog(MEA_GET_STR_ID(SMA_STR_ID_FAILED_TO_SAVE_DRM), MEA_DIALOG_ERROR);
                }
                else if (objType == DRM_METHOD_SEPARATE_DELIVERY)
                {
                    ct->mediaType = MEA_MEDIA_TYPE_DRM_CONTENT;
                }
                HDI_FileNameFree(externalFileName);
            }
#endif /* __DRM_SUPPORT__ */

            (void)MEA_SIGNAL_SENDTO_UP(MEA_ME_FSM, MEA_SIG_ME_ACTIVATE, MEA_ME_STARTUP_NEW_SMIL, ct);

            /* Clean-up */
            afiData->data       = NULL;
            afiData->size       = 0;
#ifdef MMS_SLIM_MEM
            afiData->resHandle = 0;
#endif
            meaAfiLoadFreeData(afiData);
            insertInst->fileName     = NULL;
            insertInst->buffer = NULL;
            insertInst->bufferSize = 0;
            insertInst->propItem = NULL;
            cthDeleteInstance(&insertInst, MEA_CTH_RESULT_OK);
        }
        else
        {
            MSF_UINT32  errStrId = 0;
        
            /* Check read result */
            switch(sig->u_param1)
            {
                case MEA_AFI_READ_RESULT_FAILED_LARGE_RESOLUTION:
                    errStrId = MEA_STR_ID_FAILED_LARGE_RESOLUTION;
                    break;
                case MEA_AFI_READ_RESULT_FAILED_FS_FULL:
                    errStrId = MEA_STR_ID_STORAGE_FULL;
                    break;
                case MEA_AFI_READ_RESULT_FAILED_NO_RESOURCE:
                    errStrId = MEA_STR_ID_EDIT_FAILED_RESOURCES_EXHAUSTED;
                    break;
                case MEA_AFI_READ_RESULT_FAILED_CORRUPT:
                    errStrId = MEA_STR_ID_FAILED_FILE_CORRUPT;
                    break;
                case MEA_AFI_READ_RESULT_TO_LARGE:
                    errStrId = MEA_STR_ID_MESSAGE_SIZE_MAXIMUM_REACHED;
                    break;
                case MEA_AFI_READ_RESULT_FAILED:
                default:
                    errStrId = MEA_STR_ID_FAILED_TO_READ_MO;
                    break;
            }
        
            (void)meaShowDialog(MEA_GET_STR_ID(errStrId), MEA_DIALOG_ERROR);

#ifndef WAP_SUPPORT
            /* Edit the message anyway without the content */
            (void)MEA_SIGNAL_SENDTO_U(MEA_ME_FSM, MEA_SIG_ME_ACTIVATE,
                MEA_ME_STARTUP_NEW_SMIL);
#endif
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, MACTH_60EBDB2B3A14C3222F03B5D239008D0E, "(%s) (%d) Failed "
                "to load content to insert in the new SMIL message\n", __FILE__,
                __LINE__));
            cthDeleteInstance(&insertInst, MEA_CTH_RESULT_ERROR);
        }
        break;

    default:
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MACTH_8D70E52B6775DA32A47FC01F55AFB01B, "(%s) (%d) Unhandled signal in cthSignalHandler!\n", __FILE__,
            __LINE__));
        break;
    }
    meaSignalDelete(sig);
}

/*! \brief Handles
 *
 * \param command The current start-up data.
 * \param startupMode The current start-up mode.
 * \return TRUE if the content was handled, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaCthHandleSchemeCt(const msf_module_execute_cmd_t *command)
{
    /* Check if the content originates from a MMSTO: */
#ifdef MEA_CFG_CT_BROWSER_SCHEMES
#ifdef MSF_MODID_BRS
    if ( (MSF_CONTENT_DATA_NONE == command->contentData->contentDataType)
         && (NULL != command->contentData->contentUrl) &&
         (command->srcModId == MSF_MODID_BRS))
    {
        cthCreateInstance(&insertInst);
        insertInst->url = MEA_ALLOC(
            strlen(command->contentData->contentUrl) + 1);
        msf_cmmn_strcpy_lc(insertInst->url,
            command->contentData->contentUrl);
        return TRUE;
    }
#else
#error The BRS module must be used in order to allow cross triggering!
    (void)command
#endif
#else
    (void)command;
#endif
    return FALSE;
}

/*! \brief De-allocates a #MeaCtContentInsert structure.
 *
 * \param ci The Structure to de-allocate.
 * \param command The current start-up data.
 * \param startupMode The current start-up mode.
 * \return TRUE if the content was handled, otherwise FALSE.
 *****************************************************************************/
void meaCtFreeContentInsert(MeaCtContentInsert *ci)
{
    if (NULL != ci)
    {
        MEA_FREE(ci->buffer);
        ci->buffer = NULL;
        ci->bufferSize = 0;
        MEA_FREE(ci->name);
        ci->name = NULL;
        meaFreePropItem(ci->propItem, FALSE);
#ifdef MMS_SLIM_MEM
        ci->resHandle = 0;
#endif
        /*lint -e{774} */
        MEA_FREE(ci);
    }
}

/*! \brief Handles cross triggering "-mode new -i"
 *
 * \param contentData Information about the content to insert, or NULL if no
 *                    content needs to be inserted.
 * \param item        The recipient(s) and the subject of the new message.
 * \param command The current command.
 *****************************************************************************/
MSF_BOOL meaCthHandleInsertContentCt(const msf_content_data_t *contentData,
    MeaPropItem *item)
{
    cthCreateInstance(&insertInst);
    
    /* Check if there are any content data to insert, i.e., pictures, sounds or text */
    if((NULL != contentData) && (NULL != contentData->routingIdentifier))
    {
        if(NULL != contentData->contentSource)  /* file */
        {
            MSF_LOG_MSG_ARGS((MSF_MODID_MEA, MSF_LOG_DETAIL_MEDIUM, MACTH_59CC146FF972E83E546D62620C852B42, "CTH: inserting content - source:%s, mimeType:%s\n",
                contentData->contentSource, contentData->routingIdentifier));

            insertInst->mediaType = mimeToMediaType(contentData->routingIdentifier);
            insertInst->fileName = msf_cmmn_strdup(MSF_MODID_MEA, contentData->contentSource);	/* Copy the file path/name */
    
    //        meaRemPathFromFileName(insertInst->url);		/* comment-out: we keep external path, e.g. /external/ */
        }
        else if(NULL != contentData->contentData)  /* buffer (text) */
        {
            MSF_LOG_MSG_ARGS((MSF_MODID_MEA, MSF_LOG_DETAIL_MEDIUM, MACTH_A4EB6B6523B02B04266466AB958D8D4E, "CTH: inserting text - mimeType:%s\n", contentData->routingIdentifier));

            insertInst->mediaType = mimeToMediaType(contentData->routingIdentifier);
            insertInst->fileName = meaCreateFileNameFromType(insertInst->mediaType);
            insertInst->buffer = msf_cmmn_strdup(MSF_MODID_MEA, (const char *)contentData->contentData);
            insertInst->bufferSize = strlen(insertInst->buffer) + 1;
            if(strlen(insertInst->buffer) < contentData->contentDataLength)
            {
                insertInst->isTruncated = TRUE;
            }
        }
    }
    
    insertInst->propItem = item;	/* Handle the to field */
    
    return TRUE;
}


