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

/*!\file maph.c
 * \brief Packet handler for the MEA.
 */

/* MSF */
#include "msf_cfg.h"
#include "msf_mem.h"
#include "msf_def.h"
#include "msf_cmmn.h"
#include "msf_lib.h"
#include "msf_core.h"
#include "msf_log.h"
#include "msf_dlg.h"
#include "msf_wid.h"
#include "msf_afi.h"
#include "msf_sas.h"

#ifdef WAP_SUPPORT
#include "msf_file.h" /* for MSF_FILE_GETSIZE */
#endif

#ifdef MSF_CONFIG_DRE
#include "msf_dre.h"
#endif

/* MMS */
#include "mms_def.h"
#include "mms_cfg.h"

/* MEA */
#include "mamem.h"
#include "mea_def.h"
#include "mapckg.h"
#include "maintsig.h"
#include "mauicmn.h"
#include "maph.h"

#ifdef WAP_SUPPORT
#include "mea_cfg.h"	/* for MAX_FILE_NAME_LEN */
#include "mauidia.h" //for MEA_DIALOG_ERROR
#include "widget_extension.h" // for HDIa_widgetExtFmgrMediaInput...
#include "matypes.h" /* for MeaMediaGroupType */
#include "CommonScreens.h" /* for DisplayPopup() */
#include "settingprofile.h" /* for MESSAGE_TONE */
#include "mamme.h" /* for meaIsMixedInsertionAllowed() */
#include "mase.h" /* for meaIsSMILInsertionAllowed() */
#endif /* WAP_SUPPORT */

#ifdef __DRM_SUPPORT__
#include "fs_type.h"       //for drm_def.h and FS_READ_ONLY
#include "../../drm/include/drm_gprot.h" 
#include "../../drm/include/drm_def.h"
#endif /* __DRM_SUPPORT__ */
#ifdef MMS_SLIM_MEM
#include "sls_cfg.h"	//for mautils.h
#include "sls_if.h"		//for mautils.h
#include "mautils.h"	//for meaMediaType2ObjType
#endif /* MMS_SLIM_MEM */
/******************************************************************************
 * Constants
 *****************************************************************************/
#define MEA_AFI_READ_CHUNK_SIZE         1024

/*
 * Dialog package standard functions to be registered in the
 * package encapsulation.
 */
static const mea_pckg_fnc_list_t funcList = {
        msf_dlg_init, 
        msf_dlg_handle_signal,
        msf_dlg_get_private_data, 
        msf_dlg_set_private_data,
        msf_dlg_terminate, 
        msf_dlg_delete,
        msf_dlg_get_result,
        msf_dlg_result_free
};

static const mea_pckg_fnc_list_t afiFuncList = {
        msf_afi_init, 
        msf_afi_handle_signal,
        msf_afi_get_private_data, 
        msf_afi_set_private_data,
        msf_afi_terminate, 
        NULL,
        msf_afi_get_result,
        msf_afi_result_free
};

static const mea_pckg_fnc_list_t sasFuncList = {
		msf_sas_init, 
        msf_sas_handle_signal,
        msf_sas_get_private_data, 
        msf_sas_set_private_data,
        msf_sas_terminate, 
        msf_sas_delete,
        msf_sas_get_result,
        msf_sas_result_free
};

/******************************************************************************
 * Data-types
 *****************************************************************************/

/*! \enum MeaAfiReadState 
 * States used when reading a file from persistent storage
 */
typedef enum
{
    MEA_AFI_READ_INIT,          /*!< */
    MEA_AFI_READ_OPEN,          /*!< */
    MEA_AFI_READ_SEEK,          /*!< */
    MEA_AFI_READ_GET_SIZE,      /*!< */
    MEA_AFI_READ_GET_MIME_TYPE, /*!< */
    MEA_AFI_READ_READ_CHUNK,    /*!< */
    MEA_AFI_READ_CLOSE          /*!< */
}MeaAfiReadState;

/*! \struct MeaAfiReadOp
 *	
 */
typedef struct
{
    MeaAfiReadState     state;
    MSF_UINT32          afiOpId;

    MSF_INT32           fileHandle;

    mea_pkg_handle_t    *afiHandle;

    MSF_UINT32          pos;

    MeaAfiReadResultData *res;

    MeaStateMachine     fsm;
    MSF_UINT32          maxSize;
    int                 signal;
}MeaAfiReadOp;

/******************************************************************************
 * Static data
 *****************************************************************************/
/* Package */
static mea_pckg_handle_t *pHandle;      /* Package encapsulation handle */
static mea_pkg_id_t       dlgPckId;     /* Dialog package ID */
static mea_pkg_handle_t  *dlgHandle;    /* Dialog instance ID */
#ifndef WAP_SUPPORT
static MSF_UINT32         dlgOperId;    /* */
#endif /* ~WAP_SUPPORT */
/* AFI */
static MeaAfiReadOp     *afiReadOp;
static mea_pkg_id_t     afiPckId;

/* SAS */
static mea_pkg_id_t     sasPckId;       
static mea_pkg_handle_t *sasHandle; 

/******************************************************************************
 * Prototypes
 *****************************************************************************/
static MSF_BOOL createReadInst(MeaAfiReadOp **rOp, char *fileName, 
    MeaStateMachine fsm, int signal, void *callbackData, MSF_UINT32 maxSize);
static MSF_BOOL handleReadOp(mea_pkg_handle_t *rHandle, MeaAfiReadOp **rOp, 
    mea_pckg_result_t *result);
static void deleteReadInst(mea_pckg_handle_t *rHandle, MeaAfiReadOp **rOp, 
    MeaAfiReadResult result);
static void phSignalHandler(MeaSignal *sig);

/******************************************************************************
 * Function implementation
 *****************************************************************************/
#ifdef MMS_SLIM_MEM
MSF_BOOL isForMeaAfiLoadFromFile(MSF_UINT32 handle,MsfNotificationType notificationType)
{
	if (afiReadOp != NULL && afiReadOp->res != NULL && afiReadOp->res->resHandle == handle)
	{
		if((MsfNotificationTypeExt)notificationType!=MsfNotifyResourceReady)
		{
		    MeaAfiReadResult err;
		    switch((MsfNotificationTypeExt)notificationType)
		    {
		        case MsfNotifyFailedResolution:
		        	err = MEA_AFI_READ_RESULT_FAILED_LARGE_RESOLUTION;  /* resolution larger than widget can support */
				MSF_WIDGET_RELEASE(afiReadOp->res->resHandle);    /* However, widget has already cached the file */
		        	break;
		        case MsfNotifyFailedFSFull:
		        	err = MEA_AFI_READ_RESULT_FAILED_FS_FULL;  /* file system is full */
		        	break;
		        case MsfNotifyFailedNoResource:
		        	err = MEA_AFI_READ_RESULT_FAILED_NO_RESOURCE;  /* no meory, file handle, ... */
		        	MSF_WIDGET_RELEASE(afiReadOp->res->resHandle);    /* However, widget has already cached the file */
		        	break;
		        case MsfNotifyFailedCorrupt:
		        	err = MEA_AFI_READ_RESULT_FAILED_CORRUPT;  /* image cannot get dimension */
                    MSF_WIDGET_RELEASE(afiReadOp->res->resHandle);    /* However, widget has already cached the file */
		        	break;
		        default:
		        	err = MEA_AFI_READ_RESULT_FAILED;
                    MSF_WIDGET_RELEASE(afiReadOp->res->resHandle);    /* However, widget has already cached the file */                    
		        	break;
		    }
			msf_afi_close(afiReadOp->afiHandle, afiReadOp->fileHandle);
			deleteReadInst(pHandle, &afiReadOp, err);
		}
		else
		{
		        (void)MEA_SIGNAL_SENDTO_P(MEA_PH_FSM, MEA_SIG_PH_READ_RESULT, NULL);
		}
		return TRUE;
	}
	return FALSE;
}
#endif /* MMS_SLIM_MEM */

/*! \brief Creates an instance for loading content from persistent storage
 *         through the use of AFI.
 *
 * \param rOp The new instance is written to this pointer.
 * \param fileName The file to open and read from.
 * \param fsm The callback FSM.
 * \param signal The callback signal.
 * \param callbackData The data that should be provided in the callback signal.
 * \maxSize The maximum size of the file to read.
 * \return 
 *****************************************************************************/
static MSF_BOOL createReadInst(MeaAfiReadOp **rOp, 
    char *fileName, MeaStateMachine fsm, int signal, void *callbackData, 
    MSF_UINT32 maxSize)
{
    MeaAfiReadOp *curr;
    MEA_CALLOC(curr, sizeof(MeaAfiReadOp));
    MEA_CALLOC(curr->res, sizeof(MeaAfiReadResultData));
    if (NULL == (curr->afiHandle = mea_pckg_create_inst(pHandle, 
        afiPckId)))
    {
        return FALSE;
    }

    curr->state         = MEA_AFI_READ_INIT;
    curr->fsm           = fsm;
    curr->signal        = signal;
    curr->pos           = 0;
    curr->maxSize       = maxSize;

    curr->res->fileName     = fileName;
    curr->res->callbackData = callbackData;
    curr->res->size         = 0;
#ifdef MMS_SLIM_MEM
    curr->res->resHandle = 0;    /* the resource handle created in handleReadOp() */
#endif

    *rOp = curr;
    return TRUE;
}

/*! \brief This is the state-machine for the read operation.
 *
 * \param rHandle The handle of the package.
 * \param rOp The current instance.
 * \param result The result of the previous operation.
 *****************************************************************************/
static MSF_BOOL handleReadOp(mea_pkg_handle_t *rHandle, MeaAfiReadOp **rOp, 
    mea_pckg_result_t *result)
{
    msf_afi_result_open_t           *openRes;
    msf_afi_result_get_attributes_t *getRes;
#ifndef MMS_SLIM_MEM
    msf_afi_result_read_t           *readRes;
    MSF_UINT32                      bytesToRead;
#endif
    MSF_UINT32                      iRes;
    msf_pck_attr_list_t             *attrList;
    MeaAfiReadOp                    *curr;

    if (NULL == (curr = *rOp))
    {
        return FALSE;
    }
    switch(curr->state)
    {
    case MEA_AFI_READ_INIT:
    case MEA_AFI_READ_OPEN:
        if (NULL == result)
        {
            if (MSF_PACKAGE_ERROR == (curr->afiOpId = msf_afi_open(
                curr->afiHandle, curr->res->fileName, MSF_AFI_RDONLY, NULL)))
            {
                deleteReadInst(rHandle, rOp, MEA_AFI_READ_RESULT_FAILED);
                return FALSE;
            }
            if (!mea_pckg_reg_operation(pHandle, curr->afiHandle, 
                curr->afiOpId, 0, 0, NULL))
            {
                deleteReadInst(rHandle, rOp, MEA_AFI_READ_RESULT_FAILED);
                return FALSE;
            }
            break;
        }
        else
        {
            openRes = mea_pckg_get_result_data(result);
            if (MSF_AFI_OK == openRes->result)
            {
                curr->state = MEA_AFI_READ_GET_SIZE;
                curr->fileHandle = openRes->file_handle;
            }
            else
            {
                deleteReadInst(rHandle, rOp, MEA_AFI_READ_RESULT_FAILED);
                return FALSE;
            }
        }
        (void)MEA_SIGNAL_SENDTO_P(MEA_PH_FSM, MEA_SIG_PH_READ_RESULT, NULL);
        break;

    case MEA_AFI_READ_GET_SIZE:
        if (NULL == result)
        {
            if (MSF_PACKAGE_ERROR == (curr->afiOpId = 
                msf_afi_get_attributes(curr->afiHandle, curr->res->fileName, 
                MSF_PCK_ATTRIBUTE_SIZE)))
            {
                deleteReadInst(rHandle, rOp, MEA_AFI_READ_RESULT_FAILED);
                return FALSE;
            }
            if (!mea_pckg_reg_operation(pHandle, curr->afiHandle, 
                curr->afiOpId, 0, 0, NULL))
            {
                deleteReadInst(rHandle, rOp, MEA_AFI_READ_RESULT_FAILED);
                return FALSE;
            }
            break;
        }
        else
        {
            getRes = mea_pckg_get_result_data(result);
            if (MSF_AFI_OK == getRes->result)
            {
                attrList = getRes->attr_list;
                while (NULL != attrList)
                {
                    if (MSF_PCK_ATTRIBUTE_SIZE == attrList->attribute)
                    {
                        curr->res->size = attrList->_u.i;
                    }
                    attrList = attrList->next;
                }
                if (curr->res->size > curr->maxSize)
                {
                    deleteReadInst(rHandle, rOp, MEA_AFI_READ_RESULT_TO_LARGE);
#ifdef WAP_SUPPORT
                    //curr->state = MEA_AFI_READ_CLOSE;
					msf_afi_close(curr->afiHandle, curr->fileHandle);
#endif /* WAP_SUPPORT */
                    return FALSE;
                }
#ifdef WAP_SUPPORT
                else if(curr->res->size == 0)
                {
                    deleteReadInst(rHandle, rOp, MEA_AFI_READ_RESULT_FAILED);
                    msf_afi_close(curr->afiHandle, curr->fileHandle);
                    return FALSE;
                }
#endif

                /* Allocate the data buffer */
#ifndef MMS_SLIM_MEM
                if (NULL == (curr->res->data = MEA_ALLOC(curr->res->size)))
                {
                    deleteReadInst(rHandle, rOp, MEA_AFI_READ_RESULT_FAILED);
                    return FALSE;
                }
#endif /* ~MMS_SLIM_MEM */
                result = NULL;
                curr->state = MEA_AFI_READ_GET_MIME_TYPE;
            }
            else
            {
                return FALSE;
            }
        }
        (void)MEA_SIGNAL_SENDTO_P(MEA_PH_FSM, MEA_SIG_PH_READ_RESULT, NULL);
        break;

    case MEA_AFI_READ_GET_MIME_TYPE:
        /* Get the mime-type in its own state since it may be missing */
        if (NULL == result)
        {
            if (MSF_PACKAGE_ERROR == (curr->afiOpId = 
                msf_afi_get_attributes(curr->afiHandle, curr->res->fileName, 
                MSF_PCK_ATTRIBUTE_MIME)))
            {
                deleteReadInst(rHandle, rOp, MEA_AFI_READ_RESULT_FAILED);
                return FALSE;
            }
            if (!mea_pckg_reg_operation(pHandle, curr->afiHandle, 
                curr->afiOpId, 0, 0, NULL))
            {
                deleteReadInst(rHandle, rOp, MEA_AFI_READ_RESULT_FAILED);
                return FALSE;
            }
            break;
        }
        else
        {
            getRes = mea_pckg_get_result_data(result);
            if (MSF_AFI_OK == getRes->result)
            {
                attrList = getRes->attr_list;
                while (NULL != attrList)
                {
                    if (MSF_PCK_ATTRIBUTE_MIME == attrList->attribute)
                    {
                        /* Copy the content type */
                        curr->res->mimeType = 
                            msf_cmmn_strdup(MSF_MODID_MEA, attrList->_u.s);
                    }
                    attrList = attrList->next;
                }
            }
            /* Perform the next state even though the mime-type is missing */
            result = NULL;
#ifdef MMS_SLIM_MEM
            MEA_FREE(curr->res->mimeType);  /* we don't use MSF framework value since it has own concern to make any modification */
            curr->res->mimeType = msf_cmmn_strdup(MSF_MODID_MEA, meaFileName2MimeType(curr->res->fileName));
            
            if( curr->res && curr->res->mimeType)
            {
                MeaMediaGroupType mType;
                mType=meaMediaType2ObjType(meaMime2MediaType(curr->res->mimeType));
                
                if(mType == MEA_MEDIA_GROUP_VIDEO)
                {
                    MsfVideoFormat msfFormat = (MsfImageFormat)meaConvertMediaTypeToMsf(meaMime2MediaType(curr->res->mimeType));
                    if(msfFormat > MsfVideoFormatStart)
                    {
#ifdef __DRM_SUPPORT__
                        kal_uint8 *externalFileName = HDI_FileNameTranslate(curr->res->fileName);
                        int objType = DRM_get_object_method(0, (kal_wchar *)externalFileName);
                        if (objType == DRM_METHOD_SEPARATE_DELIVERY)  //It's DRM file
                        {
                            MEA_FREE(curr->res->mimeType);
                            curr->res->mimeType = MEA_ALLOC(strlen("application/vnd.oma.drm.content")+1);// = MEA_MEDIA_TYPE_DRM_CONTENT;
                            strcpy(curr->res->mimeType, "application/vnd.oma.drm.content");
                            memset(curr->res->mimeType+strlen("application/vnd.oma.drm.content"), 0x00, 1);
                            curr->res->drmMimeType = msf_cmmn_strdup(MSF_MODID_MEA, (char*)DRM_get_content_type(0, (kal_wchar *)externalFileName));
                            if (DRM_validate_permission(0, (kal_wchar *)externalFileName, DRM_PERMISSION_PLAY))
                            {
                                curr->res->resHandle = MSF_WIDGET_EXT_VIDEO_CREATE_RESOURCE(MSF_MODID_MEA, curr->res->fileName, 
                                                                     (MsfResourceType)MsfResourceDRMFile, (MsfVideoFormat)msfFormat); //mo->content.type is DRM_CONTENT
                            }
                            else  /* no right: still allow insertion */
                            {
                                curr->state = MEA_AFI_READ_CLOSE;  /* Next state */
                                (void)MEA_SIGNAL_SENDTO_P(MEA_PH_FSM, MEA_SIG_PH_READ_RESULT, NULL);
                                HDI_FileNameFree(externalFileName);
                                break;
                            }
                        }
                        else
                        {
                            curr->res->resHandle = MSF_WIDGET_EXT_VIDEO_CREATE_RESOURCE(MSF_MODID_MEA, curr->res->fileName, MsfResourceFile, (MsfImageFormat)msfFormat);
                        }
                        HDI_FileNameFree(externalFileName);
#else
                        curr->res->resHandle =MSF_WIDGET_EXT_VIDEO_CREATE_RESOURCE (MSF_MODID_MEA, curr->res->fileName, (MsfResourceType)MsfResourceFile, (MsfVideoFormat)msfFormat);
#endif
                        if (curr->res->resHandle == 0)
                        {
                            deleteReadInst(rHandle, rOp, MEA_AFI_READ_RESULT_FAILED);
                            return FALSE;
                        }
                        curr->state = MEA_AFI_READ_CLOSE;
                    }
                    else
                    {
                        curr->state = MEA_AFI_READ_CLOSE;    /* Next state */
                        (void)MEA_SIGNAL_SENDTO_P(MEA_PH_FSM, MEA_SIG_PH_READ_RESULT, NULL);
                    }
                }
                else if(mType == MEA_MEDIA_GROUP_IMAGE)
                {
                    MsfImageFormat msfFormat = (MsfImageFormat)meaConvertMediaTypeToMsf(meaMime2MediaType(curr->res->mimeType));
                    if (0 < msfFormat)
                    {
#ifdef __DRM_SUPPORT__
                        kal_uint8 *externalFileName = HDI_FileNameTranslate(curr->res->fileName);
                        int objType = DRM_get_object_method(0, (kal_wchar *)externalFileName);
                        if (objType == DRM_METHOD_SEPARATE_DELIVERY)  //It's DRM file
                        {
                            MEA_FREE(curr->res->mimeType);
                            curr->res->mimeType = MEA_ALLOC(strlen("application/vnd.oma.drm.content")+1);// = MEA_MEDIA_TYPE_DRM_CONTENT;
                            strcpy(curr->res->mimeType, "application/vnd.oma.drm.content");
                            memset(curr->res->mimeType+strlen("application/vnd.oma.drm.content"), 0x00, 1);
                            curr->res->drmMimeType = msf_cmmn_strdup(MSF_MODID_MEA, (char*)DRM_get_content_type(0, (kal_wchar *)externalFileName));
                            if (DRM_validate_permission(0, (kal_wchar *)externalFileName, DRM_PERMISSION_DISPLAY))
                            {
                                curr->res->resHandle = MSF_WIDGET_IMAGE_CREATE_RESOURCE(MSF_MODID_MEA, curr->res->fileName, 
                                                                     (MsfResourceType)MsfResourceDRMFile, (MsfImageFormat)msfFormat); //mo->content.type is DRM_CONTENT
                            }
                            else if (DRM_validate_permission(0, (kal_wchar *)externalFileName, DRM_PERMISSION_PLAY))  /* Audio */
                            {
                                curr->state = MEA_AFI_READ_CLOSE;  /* Next state */
                                (void)MEA_SIGNAL_SENDTO_P(MEA_PH_FSM, MEA_SIG_PH_READ_RESULT, NULL);
                                HDI_FileNameFree(externalFileName);
                                break;
                            }
                            else  /* no right: still allow insertion */
                            {
                                curr->state = MEA_AFI_READ_CLOSE;  /* Next state */
                                (void)MEA_SIGNAL_SENDTO_P(MEA_PH_FSM, MEA_SIG_PH_READ_RESULT, NULL);
                                HDI_FileNameFree(externalFileName);
                                break;
                            }
                        }
                        else
                        {
                            curr->res->resHandle = MSF_WIDGET_IMAGE_CREATE_RESOURCE(MSF_MODID_MEA, curr->res->fileName, MsfResourceFile, (MsfImageFormat)msfFormat);
                        }
                        HDI_FileNameFree(externalFileName);
#else
                        curr->res->resHandle = MSF_WIDGET_IMAGE_CREATE_RESOURCE(MSF_MODID_MEA, curr->res->fileName, MsfResourceFile, (MsfImageFormat)msfFormat);
#endif /* __DRM_SUPPORT__ */
                        if (curr->res->resHandle == 0)
                        {
                            deleteReadInst(rHandle, rOp, MEA_AFI_READ_RESULT_FAILED);
                            return FALSE;
                        }
                        curr->state = MEA_AFI_READ_CLOSE;				
                        break;
                    }
                    else
                    {
                        curr->state = MEA_AFI_READ_CLOSE;
                        /* Next state */
                        (void)MEA_SIGNAL_SENDTO_P(MEA_PH_FSM, MEA_SIG_PH_READ_RESULT, NULL);
                    }			 
                }
                else
                {
                    curr->state = MEA_AFI_READ_CLOSE;
                    /* Next state */
                    (void)MEA_SIGNAL_SENDTO_P(MEA_PH_FSM, MEA_SIG_PH_READ_RESULT, NULL);		
                }
            }
#else
            curr->state = MEA_AFI_READ_SEEK;
#endif /* MMS_SLIM_MEM */
        }
#ifndef MMS_SLIM_MEM
        /* Next state */
        (void)MEA_SIGNAL_SENDTO_P(MEA_PH_FSM, MEA_SIG_PH_READ_RESULT, NULL);
#endif /* ~MMS_SLIM_MEM */
        break;

#ifndef MMS_SLIM_MEM
    case MEA_AFI_READ_SEEK:
        if (msf_afi_seek(curr->afiHandle, curr->fileHandle, curr->pos, 
            HDI_FILE_SEEK_SET) < 0)
        {
            deleteReadInst(rHandle, rOp, MEA_AFI_READ_RESULT_FAILED);
            return FALSE;
        }
        result = NULL;
        curr->state = MEA_AFI_READ_READ_CHUNK;
        (void)MEA_SIGNAL_SENDTO_P(MEA_PH_FSM, MEA_SIG_PH_READ_RESULT, NULL);
        break;

    case MEA_AFI_READ_READ_CHUNK:
        readRes = NULL;
        if (NULL != result)
        {
            readRes = mea_pckg_get_result_data(result);
            if (MSF_AFI_OK != readRes->result)
            {
                deleteReadInst(rHandle, rOp, MEA_AFI_READ_RESULT_FAILED);
                return FALSE;
            }
            curr->pos +=readRes->data_len;
            (void)MEA_SIGNAL_SENDTO_P(MEA_PH_FSM, MEA_SIG_PH_READ_RESULT,
                NULL);
            break;
        }
        /* Calculate the size to read */
        if (curr->pos < curr->res->size)
        {
            bytesToRead = (curr->res->size - curr->pos > MEA_AFI_READ_CHUNK_SIZE) ? 
                    MEA_AFI_READ_CHUNK_SIZE: curr->res->size - curr->pos;
            /* Read the data */
            if (bytesToRead > 0)
            {
                if (MSF_PACKAGE_ERROR == (curr->afiOpId = msf_afi_read(
                    curr->afiHandle, curr->fileHandle, 
                    &((unsigned char *)curr->res->data)[curr->pos], 
                    bytesToRead)))
                {
                    deleteReadInst(rHandle, rOp, MEA_AFI_READ_RESULT_FAILED);
                    return FALSE;
                }
                if (!mea_pckg_reg_operation(pHandle, curr->afiHandle, 
                    curr->afiOpId, 0, 0, NULL))
                {
                    deleteReadInst(rHandle, rOp, MEA_AFI_READ_RESULT_FAILED);
                    return FALSE;
                }
            }
            break;
        }
        else
        {
            result = NULL;
            curr->state = MEA_AFI_READ_CLOSE;
        }
        (void)MEA_SIGNAL_SENDTO_P(MEA_PH_FSM, MEA_SIG_PH_READ_RESULT, NULL);
        break;
#endif

    case MEA_AFI_READ_CLOSE:
        if (NULL != result)
        {
            iRes = mea_pckg_get_result_uint(result);
            /* Result struct is missing in AFI */
            if (MSF_AFI_OK == iRes)
            {
                deleteReadInst(rHandle, rOp, MEA_AFI_READ_RESULT_OK);
                return TRUE;
            }
            
        }
        if (MSF_PACKAGE_ERROR == (curr->afiOpId = 
            msf_afi_close(curr->afiHandle, curr->fileHandle)))
        {
            deleteReadInst(rHandle, rOp, MEA_AFI_READ_RESULT_FAILED);
            return FALSE;
        }
        if (!mea_pckg_reg_operation(pHandle, curr->afiHandle, 
            curr->afiOpId, MEA_PH_FSM, MEA_SIG_PH_READ_RESULT, NULL))
        {
            deleteReadInst(rHandle, rOp, MEA_AFI_READ_RESULT_FAILED);
            return FALSE;
        }        
        break;
    default:
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
            MAPH_0CC5AD5898762E662B63C52B3A9486CD, "(%s) (%d) unhandled signal to the AFI load file FSM\n", __FILE__, 
            __LINE__));
        break;
    }
    return TRUE;
}

/*! \brief De-allocates the read instance.
 *
 * \param rHandle The packet handle.
 * \param rOp The read operation instance.
 * \param result The result of  the operation.
 *****************************************************************************/
static void deleteReadInst(mea_pckg_handle_t *rHandle, MeaAfiReadOp **rOp, 
    MeaAfiReadResult result)
{
    MeaAfiReadOp *curr;
    curr = *rOp;
    if (NULL == curr)
    {
        return;
    }
    /* Send The response */
    if (MEA_AFI_READ_RESULT_OK == result)
    {
        /* Send the response back */
        (void)MEA_SIGNAL_SENDTO_UP(curr->fsm, curr->signal, result, curr->res);
        curr->res = NULL;
    }
    else if (result != MEA_AFI_READ_RESULT_INT_TERM)
    {
        (void)MEA_SIGNAL_SENDTO_UP(curr->fsm, curr->signal, result, NULL);
    }
    /* Delete open AFI handles */
    mea_pckg_terminate(rHandle, curr->afiHandle, FALSE);
    /* De-allocate memory */
    /* File buffer */
    if ((NULL != curr->res) && (NULL != curr->res->data))
    {
        MEA_FREE(curr->res->data);
        curr->res->data = NULL;
    }
    /* File-name*/
    if ((NULL != curr->res) && (NULL != curr->res->fileName))
    {
        MEA_FREE(curr->res->fileName);
        curr->res->fileName = NULL;
    }
    /* Mime type */
    if ((NULL != curr->res) && (NULL != curr->res->mimeType))
    {
        MEA_FREE(curr->res->mimeType);
        curr->res->mimeType = NULL;
    }
    /* The result data  */
    if (NULL != curr->res)
    {
        MEA_FREE(curr->res);
        curr->res = NULL;
    }
    MEA_FREE(curr);
    *rOp = NULL;
}


/*! \brief MEA package operation completion entry point function.
 *
 * \param fsm      Fsm to forward signal to.
 * \param signal   Signal to send to fsm.
 * \param pkg_inst Package instance to completed operation.
 * \param id       Package operation ID.
 * \param result   Package operation result (type-cast per operation)
 * \param data     Private data provided at registration of operation.
 *
 * \return 0.
 *
 * NOTE: The result is deallocated when this function returns.
 *       If result data is to be kept, either copy or snatch pointer
 *       and set it to NULL (so that the free operation not can free it). 
 *****************************************************************************/
static int meaPacketSignalHand(MSF_INT32 fsm, MSF_INT32 signal,
    mea_pkg_id_t pckg_id, mea_pkg_handle_t *pkg_inst, MSF_INT32 id, 
    mea_pckg_result_t *result, void *data)
{
    pkg_inst = NULL;
    id = 0;
    data = NULL;

    if (dlgPckId == pckg_id)
    {
        (void)MEA_SIGNAL_SENDTO_UP((MeaStateMachine)fsm, signal, 
            ((msf_dlg_result_open_t *)result->oper_result._u.data)->result,
            ((msf_dlg_result_open_t *)result->oper_result._u.data)->file_name);
        ((msf_dlg_result_open_t *)result->oper_result._u.data)->file_name = NULL;
        MEA_FREE(result->oper_result._u.data);
        result->oper_result._u.data = NULL;
    }
    else if ((NULL != afiReadOp) && (afiPckId == pckg_id))
    {
        if (!handleReadOp(pHandle, &afiReadOp, result))
        {
            deleteReadInst(pHandle, &afiReadOp, MEA_AFI_READ_RESULT_FAILED);
        }
    }
	else if (sasPckId == pckg_id)
    {
		(void)MEA_SIGNAL_SENDTO_U((MeaStateMachine)fsm, signal, 
            ((msf_sas_result_save_as_t *)result->oper_result._u.data)->result);
    }
    return 0;
}

/*! \brief Initiates the package handling for MEA.
 *
 * \return TRUE on successful initialization.
 *
 * Initializes the:
 * - Dialog package
 * - Afi package
 *
 *****************************************************************************/
MSF_BOOL meaPhInit(void)
{
    /* Initiate encapsulation */
    if (NULL == (pHandle = mea_pckg_create(MSF_MODID_MEA)))
    {
        return FALSE;
    }

     /* Dlg */
    if (0 == (dlgPckId = mea_pckg_reg_pckg(pHandle, &funcList)))
    {
        return FALSE;
    }
    if (NULL == (dlgHandle = mea_pckg_create_inst(pHandle, dlgPckId)))
    {
        return FALSE;
    }
    /* AFI */
    if (0 == (afiPckId = mea_pckg_reg_pckg(pHandle, &afiFuncList)))
    {
        return FALSE;
    }

	/* SAS */
	if (0 == (sasPckId = mea_pckg_reg_pckg(pHandle, &sasFuncList)))
    {
        return FALSE;
    }
    if (NULL == (sasHandle = mea_pckg_create_inst(pHandle, sasPckId)))
    {
        return FALSE;
    }


    /* Sets callback function */
    if (!mea_pckg_set_response_handler(pHandle, meaPacketSignalHand))
    {
        return FALSE;
    }
    meaSignalRegisterDst(MEA_PH_FSM, phSignalHandler);
    return TRUE;
}

/*! \brief Calls package encapsulation signal handler.
 *
 * \param signal   External signal to handle.
 * \param p        Signal data.
 *
 * \return Returns TRUE if signal is consumed.
 *****************************************************************************/
MSF_BOOL meaPhHandleSignal(MSF_UINT16 signal, void *p)
{
    int res;

    res = mea_pckg_handle_signal(pHandle, signal, p);
    switch(res)
    {
    case MSF_PACKAGE_OPERATION_COMPLETE:
    case MSF_PACKAGE_SIGNAL_NOT_HANDLED:
        return FALSE;
        //break;
    case MSF_PACKAGE_SIGNAL_HANDLED:
        return TRUE;
    default:
        return FALSE;
    }
}

/*! \brief Terminates MEA package handling
 *
 * Terminates packages:
 * - Dialog package
 * - Afi package
 *
 *****************************************************************************/
void meaPhTerminate(void)
{
    (void)mea_pckg_unreg_pckg(pHandle, afiPckId);
    (void)mea_pckg_unreg_pckg(pHandle, dlgPckId);
    mea_pckg_destroy(pHandle);
    pHandle = 0;
    meaSignalDeregister(MEA_PH_FSM);
}

#ifdef WAP_SUPPORT //use MTK_FMGR
typedef struct 
{
	int signal;
	MeaStateMachine fsm;
	MeaInsertObjCallBack callback;
} meaOpenDlgCreateMediaInputStruct;

static meaOpenDlgCreateMediaInputStruct mea_media_input_cntx;

void mea_open_dlg_create_media_input_done_hdlr(const char *pathname, void *arg)	/* This function is executed as MMI task */
{
    *(MSF_BOOL *)arg = FALSE;

    if(pathname == NULL)	/* User press back, leave FileManager: arg=TRUE */
    {
	    (void)MEA_SIGNAL_SENDTO_U(mea_media_input_cntx.fsm, mea_media_input_cntx.signal, (unsigned long)MSF_DLG_RETURN_CANCELLED);
	    *(MSF_BOOL *)arg = TRUE;
    }
    else
    {
        int filesize = MSF_FILE_GETSIZE(pathname);

        if(filesize < 0)		/* Abnormal file, stay in FileManager: arg=FALSE */
        {
            const kal_uint8* text = HDIa_widgetExtStringGetUCS2buffer(MEA_GET_STR_ID(MEA_STR_ID_FAILED_TO_READ_MO));
            DisplayPopup((kal_uint8 *)text, IMG_GLOBAL_ERROR, 0, 2000, ERROR_TONE);
        }
        else if (filesize > MMS_DEFAULT_MAX_MSG_SIZE * 3)
        {
            const kal_uint8* text = HDIa_widgetExtStringGetUCS2buffer(MEA_GET_STR_ID(MEA_STR_ID_MESSAGE_SIZE_MAXIMUM_REACHED));
            DisplayPopup((kal_uint8 *)text, IMG_GLOBAL_ERROR, 0, 2000, ERROR_TONE);
            HDIa_widgetExtCloseTransitionAnimation();
        }
        else 
        {
            MeaInsertResult result = MEA_ERR_INSERT; 
            
            switch(mea_media_input_cntx.callback(pathname))
            {
                case MEA_INSERT_OK:
                {
                    result = MEA_INSERT_OK;	              
                    break;
                }
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
#endif                
                case MEA_ERR_INSERT:
                case MEA_ERR_INSERT_UNKNOWN:
                {
                    const kal_uint8* text = HDIa_widgetExtStringGetUCS2buffer(MEA_GET_STR_ID(MEA_STR_ID_FAILED_TO_READ_MO));
                    DisplayPopup((kal_uint8 *)text, IMG_GLOBAL_ERROR, 0, 2000, ERROR_TONE);
                    break;
                }
                case MEA_ERR_INSERT_DRM:
                {
                    const kal_uint8* text = HDIa_widgetExtStringGetUCS2buffer(MEA_GET_STR_ID(MEA_STR_ID_FAILED_TO_INSERT_DRM));
                    DisplayPopup((kal_uint8 *)text, IMG_GLOBAL_ERROR, 0, 2000, ERROR_TONE);
                    break;
                }
                case MEA_ERR_INSERT_RESIZE:
                {
                    const kal_uint8* text = HDIa_widgetExtStringGetUCS2buffer(MEA_GET_STR_ID(MEA_STR_ID_FAILED_TO_RESIZE_IMAGE));
                    DisplayPopup((kal_uint8 *)text, IMG_GLOBAL_ERROR, 0, 2000, ERROR_TONE);
                    HDIa_widgetExtCloseTransitionAnimation();
                    break;
                }
                case MEA_ERR_INSERT_LARGE:
                {
                    const kal_uint8* text = HDIa_widgetExtStringGetUCS2buffer(MEA_GET_STR_ID(MEA_STR_ID_MESSAGE_SIZE_MAXIMUM_REACHED));
                    DisplayPopup((kal_uint8 *)text, IMG_GLOBAL_ERROR, 0, 2000, ERROR_TONE);
                    HDIa_widgetExtCloseTransitionAnimation();
                    break;
                }
                case MEA_ERR_INSERT_EMPTY:
                {
                    const kal_uint8* text = HDIa_widgetExtStringGetUCS2buffer(MEA_GET_STR_ID(MEA_STR_ID_FAILED_TO_ADD_EMPTY_OBJECT));
                    DisplayPopup((kal_uint8 *)text, IMG_GLOBAL_ERROR, 0, 2000, ERROR_TONE);
                    HDIa_widgetExtCloseTransitionAnimation();
                    break;
                }
                case MEA_ERR_INSERT_CORRUPT:
                {
                    const kal_uint8* text = HDIa_widgetExtStringGetUCS2buffer(MEA_GET_STR_ID(MEA_STR_ID_FAILED_FILE_CORRUPT));
                    DisplayPopup((kal_uint8 *)text, IMG_GLOBAL_ERROR, 0, 2000, ERROR_TONE);
                    HDIa_widgetExtCloseTransitionAnimation();
                    break;
                }
                case MEA_ERR_INSERT_DISK_FULL:
                {
                    const kal_uint8* text = HDIa_widgetExtStringGetUCS2buffer(MEA_GET_STR_ID(MEA_STR_ID_STORAGE_FULL));
                    DisplayPopup((kal_uint8 *)text, IMG_GLOBAL_ERROR, 0, 2000, ERROR_TONE);
                    HDIa_widgetExtCloseTransitionAnimation();
                    break;
                }
                case MEA_ERR_INSERT_RESOURCE_EXHAUSTED:
                {
                    const kal_uint8* text = HDIa_widgetExtStringGetUCS2buffer(MEA_GET_STR_ID(MEA_STR_ID_EDIT_FAILED_RESOURCES_EXHAUSTED));
                    DisplayPopup((kal_uint8 *)text, IMG_GLOBAL_ERROR, 0, 2000, ERROR_TONE);
                    HDIa_widgetExtCloseTransitionAnimation();
                    break;
                }
                case MEA_ERR_INSERT_UNRESTRICTED:
                {
                    const kal_uint8* text = HDIa_widgetExtStringGetUCS2buffer(MEA_GET_STR_ID(MEA_STR_ID_RESTRICTED_MIME_ACTION_NONE));
                    DisplayPopup((kal_uint8 *)text, IMG_GLOBAL_ERROR, 0, 2000, ERROR_TONE);
                    HDIa_widgetExtCloseTransitionAnimation();
                    break;
                }
                default:
                {
                    const kal_uint8* text = HDIa_widgetExtStringGetUCS2buffer(MEA_GET_STR_ID(MEA_STR_ID_FAILED_TO_READ_MO));
                    DisplayPopup((kal_uint8 *)text, IMG_GLOBAL_ERROR, 0, 2000, ERROR_TONE);
                    break;
                }
            }

            if(result == MEA_INSERT_OK)
            {
                char *return_pathname = NULL;
                return_pathname = MEA_ALLOC(strlen(pathname)+1);
                ASSERT(return_pathname);

                strcpy(return_pathname, pathname);
                (void)MEA_SIGNAL_SENDTO_UP(mea_media_input_cntx.fsm, mea_media_input_cntx.signal, MSF_DLG_RETURN_OK, return_pathname);
                *(MSF_BOOL *)arg = TRUE;                
            }
		else
		{   
#ifdef JPG_ENCODE
			char *return_pathname = NULL;
			return_pathname = MEA_ALLOC(strlen(pathname)+1);
			ASSERT(return_pathname);
			strcpy(return_pathname, pathname);
	              if (meaIsResizedFile(return_pathname))     
       	       {
				MSF_FILE_REMOVE(return_pathname);
			}
#endif				
		}
       }
    }
}

MSF_BOOL meaOpenDlgCreateMediaInput(MeaStateMachine fsm, int signal, 
    const char *mimeTypes, MeaInsertObjCallBack callback)
{
    MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
    MAPH_963EF9348EE76AF90733BD21CDE4EAC2, "(%s) (%d) meaOpenDlgCreateMediaInput fsm = %d, signal = %d, "
    "mimeTypes = %s\n", __FILE__, __LINE__, fsm, signal, mimeTypes));

	// If there are two invocation of this function, the latter one override the first one.
	mea_media_input_cntx.signal = signal;
	mea_media_input_cntx.fsm = fsm;
	mea_media_input_cntx.callback = callback;	

	return HDIa_widgetExtFmgrMediaInput(mimeTypes, mea_open_dlg_create_media_input_done_hdlr, NULL);
} /* meaCreateMediaInputDlg */

#else /* WAP_SUPPORT */
/*! \brief Creates a dialog for input 
 *
 * \param fsm       Fsm that receives internal signal at completion.
 * \param signal    Signal to send to fsm at completion of the operation.
 * \param mimeTypes Comma separated list of mime-types wildcard '*' are allowed.
 * \return A handle to the operation or 0 if the operation fails.
 *****************************************************************************/
MSF_BOOL meaOpenDlgCreateMediaInput(MeaStateMachine fsm, int signal, 
    const char *mimeTypes)
{
    MSF_UINT32 permissions;
    MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
        MAPH_963EF9348EE76AF90733BD21CDE4EAC2, "(%s) (%d) meaOpenDlgCreateMediaInput fsm = %d, signal = %d, "
        "mimeTypes = %s\n", __FILE__, __LINE__, fsm, signal, mimeTypes));
    #ifdef MSF_CONFIG_DRE
        permissions = MSF_DRE_PERMISSION_FORWARD;
    #else
        permissions = 0;
    #endif
    if ((dlgOperId = msf_dlg_create_open(dlgHandle, meaGetScreenHandle(),
        permissions, mimeTypes)) > 0)
    {
        if (!mea_pckg_reg_operation(pHandle, dlgHandle, dlgOperId, fsm, 
            signal, NULL))
        {
            return FALSE;
        }
    }
    else
    {
        return FALSE;
    }
    return TRUE;
} /* meaCreateMediaInputDlg */
#endif /* WAP_SUPPORT */

/*! \brief Aborts the open dialog.
 *
 * \param The handle of the operation to abort.
 *****************************************************************************/
#ifdef WAP_SUPPORT //use MTK_FMGR
void meaOpenDlgMediaInputAbort(void)
{
	HDIa_widgetExtFmgrMediaInputAbort();
}
#else
void *meaOpenDlgMediaInputAbort(void)
{
    void *ptr = NULL;
    (void)mea_pckg_cancel(pHandle, dlgHandle, dlgPckId, &ptr);
    return ptr;
}
#endif /* WAP_SUPPORT */

/*! \brief Load a file from persistent storage.
 *
 * \param fsm The callback FSM
 * \param signal The callback signal
 * \param fileName The AFI file path of the file to read.
 * \param callbackData The callback data.
 * \param maxSize The maximum file size of the file to open.
 * \return TRUE if the operation is successful, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaAfiLoadFromFile(MeaStateMachine fsm, int signal, 
    char *fileName, void *callbackData, MSF_UINT32 maxSize)
{
    MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
        MAPH_A65221F717D80AE23CE5B0E1F394F7EE, "(%s) (%d) meaAfiLoadFromFile fsm = %d, signal = %d, "
        "fileName = %s, callbackData = %x, maxSize\n", __FILE__, __LINE__, 
        fsm, signal, fileName, callbackData, maxSize));
#ifdef WAP_SUPPORT
    if (!(fileName && (fileName[0] == '/' || fileName[0] == '\\')))
    {
        (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_FAILED_TO_READ_MO), 
            MEA_DIALOG_ERROR);
        return FALSE;
    }
#endif /* WAP_SUPPORT */
    if (NULL == afiReadOp)
    {
        if (!createReadInst(&afiReadOp, fileName, fsm, signal, 
            callbackData, maxSize) || !handleReadOp(pHandle, &afiReadOp, NULL))
        {
            deleteReadInst(pHandle, &afiReadOp, MEA_AFI_READ_RESULT_FAILED);
            return FALSE;
        }
    }
    else
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
            MAPH_CB28435C961DBBA30F9D4908AADF38D2, "(%s) (%d) meaAfiLoadFromFile instance is busy\n", __FILE__, 
            __LINE__));
        return FALSE;
    }
    return TRUE;
}

/*! \brief Abort the current file operation.
 *
 * \return Returns the data provided in the call to #meaAfiLoadFromFile.
 *****************************************************************************/
void *meaAfiLoadFromFileAbort(void)
{
    void *ptr = NULL;
    if (NULL != afiReadOp)
    {
        (void)mea_pckg_cancel(pHandle, afiReadOp->afiHandle, afiReadOp->afiOpId, 
            &ptr);
        deleteReadInst(pHandle, &afiReadOp, MEA_AFI_READ_RESULT_INT_TERM);
    }
    return ptr;
}

/*! \brief Signal handling for the packet handler.
 *
 * \param sig The incoming signal
 *****************************************************************************/
static void phSignalHandler(MeaSignal *sig)
{
    switch(sig->type)
    {
    case MEA_SIG_PH_READ_RESULT:
        (void)handleReadOp(pHandle, &afiReadOp, sig->p_param);
        break;
    }
    meaSignalDelete(sig);
}

/*! brief De-allocates a #MeaAfiReadResultData data-structure.
 *
 * \param The data to de-allocate.
 *****************************************************************************/
void meaAfiLoadFreeData(MeaAfiReadResultData *data)
{
    if (NULL != data)
    {
        if (NULL != data->data)
        {
            MEA_FREE(data->data);
        }
        if (NULL != data->mimeType)
        {
            MEA_FREE(data->mimeType);
        }
        if (NULL != data->fileName)
        {
            MEA_FREE(data->fileName);
        }
#ifdef __DRM_SUPPORT__
        if (NULL != data->drmMimeType)
        {
            MEA_FREE(data->drmMimeType);
        }
#endif
        /*lint -e{774} */
        MEA_FREE(data);
    }
}

#ifdef MMS_SLIM_MEM
void meaAfiReleaseHandle(MeaAfiReadResultData *data)
{
    if (NULL != data)
    {
        if (data->resHandle != 0)
        {
            MSF_WIDGET_RELEASE(data->resHandle);
            data->resHandle = 0;
        }
    }
}
#endif

/*! \brief Creates a dialog for Save As 
 *
 * \param fsm       Fsm that receives internal signal at completion.
 * \param signal    Signal to send to fsm at completion of the operation.
 * \param mimeType  Comma separated list of mime-types wildcard '*' are allowed.
 * \param 
 * \param 
 * \return A handle to the operation or 0 if the operation fails.
 *****************************************************************************/
MSF_UINT32 meaCreateSaveAs(MeaStateMachine fsm, int signal, 
    char *mimeTypes, const char *fileName, char *data, long dataLen)
{
    MSF_INT32 operId;
	msf_pck_attr_list_t *attrList;
	MSF_UINT32 ret;

	msf_pck_attr_init(&attrList);
	msf_pck_add_attr_string_value (MSF_MODID_MEA, &attrList, 
		MSF_PCK_ATTRIBUTE_MIME, mimeTypes);
	msf_pck_add_attr_int_value (MSF_MODID_MEA, &attrList,
		MSF_PCK_ATTRIBUTE_SIZE, dataLen);
 

	if ((operId = msf_sas_create_save_as(sasHandle, fileName, mimeTypes, 
		MSF_PCK_DATA_TYPE_BUFFER, data, dataLen, NULL, attrList, 
		meaGetScreenHandle(), MSF_SAS_ALLOW_OVERWRITE)) > 0)
    {
        mea_pckg_reg_operation(pHandle, sasHandle, operId, fsm, signal, NULL);
        ret = operId;
    }
    else
    {
        ret = 0;
    } /* if */

	msf_pck_attr_free(MSF_MODID_MEA, attrList);

	return ret;
} /* meaCreateSaveAs */


