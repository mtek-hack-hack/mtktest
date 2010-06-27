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

/*! \file mammv.c
 *  \brief Viewer of Multipart Mixed message (implementation)
 */

/* MSF */
#include "msf_log.h"
#include "msf_lib.h"
#include "msf_wid.h"
#include "msf_mem.h"
#include "msf_core.h"
#include "msf_act.h"


/* MMS */
#include "mms_cfg.h"
#include "mms_def.h"
#include "mms_if.h"

/* SLS */
#include "sls_cfg.h"
#include "sls_if.h"

/* MEA */
#include "mea_rc.h"
#include "mea_cfg.h"
#include "matypes.h"
#include "maintsig.h"
#include "mamr.h"
#include "mamem.h"
#include "macrh.h"
#include "mauidia.h"
#include "mautils.h"
#include "mauicmn.h"
#include "maph.h"
#include "mammv.h"
#include "mamob.h"
#include "mauimmv.h"
#include "mtr.h"
#include "masrh.h"
#include "mtr_cmn.h"
#ifdef WAP_SUPPORT
#include "mamv.h"
  #ifdef MMS_SLIM_MEM
  #include "msf_pipe.h"
  #include "msf_file.h"
  #include "msf_act.h"  //for msf_act_object_action_drm

  #include "widget.h"  /* virtual file */
  #endif /* MMS_SLIM_MEM */
#endif /* WAP_SUPPORT */

/******************************************************************************
 * Constants
 *****************************************************************************/
/* Possible DRM content types */
#ifndef WAP_SUPPORT
static const char *meaMmvDrmContentTypes[] = 
    {"application/vnd.oma.dd+xml", "application/vnd.oma.drm.message", 
    "application/vnd.oma.drm.content", "application/vnd.oma.drm.rights+xml", 
    "application/vnd.oma.drm.rights+wbxml", NULL};

/* Boundary parameter; used for DRM content send */
#define MEA_MMV_DRM_BOUNDARY        "boundary"

#define MEA_EQUAL_STR               "="
#endif /* WAP_SUPPORT */

/******************************************************************************
 * Data-structures
 *****************************************************************************/

/*! \struct MeaMmvInstance
 * Data-structure for storing multipart/mixed viewer instances
 */
typedef struct
{
    MeaMoDataItem        *currentMo;      /* !< current media object in list */
    MeaMoDataItem        *moList;         /* !< media object list */
    MmsMsgId             msgId;           /* !< message id */
    MmsFileType          fileType;        /* !< file type */
    msf_act_action_entry_t  *actions;       /* !< */
    MSF_UINT32              actionCount;    /* !< */
    MSF_UINT32              actionId;       /* !< */
}MeaMmvInstance;

/******************************************************************************
 * Variables
 *****************************************************************************/

static MeaMmvInstance *mmvInstance;       /* !< The mp/m viewer instance */
#ifdef MMS_SLIM_MEM
static msf_pck_handle_t* meaActHandle;
#endif /* WAP_SUPPORT */

/******************************************************************************
 * Prototypes
 *****************************************************************************/
static MeaMoDataItem *getMoAtIndex(const MeaMmvInstance *inst, int index);

#if MEA_USE_CONTENT_ROUTING!=1
static MSF_BOOL createMenu(const MeaMmvInstance *inst);
#endif
#ifndef WAP_SUPPORT
static void viewUnknownMo(const MeaMmvInstance *inst);
#ifdef MMS_SLS_SLIM_MEM
static MSF_BOOL viewAudioMo(MeaMmvInstance *inst);
#else
static MSF_BOOL viewAudioMo(const MeaMmvInstance *inst);
#endif
#endif /* ~WAP_SUPPORT */
static void setCurrentMo(MeaMmvInstance *inst, int index);
#ifndef WAP_SUPPORT
static void startBra(char *url);
static MSF_BOOL viewLink(void *linkIn, MeaStateMachine fsm, int sig);
static MSF_BOOL viewMo(const MeaMmvInstance *inst);
#endif /* WAP_SUPPORT */
static void saveMo(const MeaMmvInstance *instance);
static void meaMmvCreateInstance(MeaMmvInstance **instance,
                                 const MeaMessage *srcInstance);
static void meaMmvDeleteInstance(MeaMmvInstance **instance);
static void handleMobOp(MeaMmvInstance *inst, MeaMobOperation op, int i, 
    MtrLinkEntry *p);
static void meaMmvMain(MeaSignal *sig);


/******************************************************************************
 * Function implementation
 *****************************************************************************/

/*!
 * \brief Get the media object at a specified index
 * \param inst  The current instance
 * \param index The requested position in list (zero based)
 * \return The request media object or NULL if illegal bounds
 *****************************************************************************/
static MeaMoDataItem *getMoAtIndex(const MeaMmvInstance *inst, int index)
{
    MeaMoDataItem *mo = inst->moList;

    while (index && mo != NULL)
    {
        mo = mo->next;
        index--;
    }

    return mo;
}

#if MEA_USE_CONTENT_ROUTING!=1
/*!
 * \brief Create and view attachment menu 
 * \param inst The current instance
 * \return TRUE upon success
 *****************************************************************************/
static MSF_BOOL createMenu(const MeaMmvInstance *inst)
{    
    return meaUiMmvCreateMenu(inst->currentMo);
}
#endif
#ifndef WAP_SUPPORT
/*! \brief Creates the MIME-type for the current media object 
 *
 * \param mo The current media object
 * \return A mime-type if successful, otherwise NULL. Note that the caller is
 *         responsible for deallocating the mime-type string.
 *****************************************************************************/
static char *makeMimeType(const MeaMoDataItem *mo)
{
    char           *mimeType = NULL;
    char           *tmpType;

    if (NULL == (tmpType = meaMediaType2Mime(mo->content.type)))
    {
        if (NULL != mo->content.origType)
        {
            if (MMS_VALUE_AS_STRING == mo->content.origType->knownValue)
            {
                mimeType = msf_cmmn_strdup(MSF_MODID_MEA, 
                    (char *)mo->content.origType->strValue);
            }
            else
            {
                mimeType = meaKnownValueToMimeType(
                    mo->content.origType->knownValue);
            }
            
        }
    }
    else
    {
        /* Copy the data */
        mimeType = msf_cmmn_strdup(MSF_MODID_MEA, tmpType);
    }
    return mimeType;
}

/*! \brief Extracts the boundary if the content is DRM protected.
 *
 * \param mo The current media object.
 * \param mimeType The current mime type as a string.
 * \return The boundary param (http header) if the content is DRM, 
 *         otherwise NULL. The caller is responsible for deallocating the 
 *         returned boundary.
 *****************************************************************************/
static char *handleDrm(const MeaMoDataItem *mo, char *mimeType)
{
    unsigned int i;
    MmsAllParams *param;
    char *ret;

    /* Go through all content types that needs to boundary parameter */
    for (i = 0; NULL != meaMmvDrmContentTypes[i]; i++)
    {
        /* Check if it is a DRM content type */
        if (0 == msf_cmmn_strcmp_nc(mimeType, meaMmvDrmContentTypes[i]))
        {
            /* Content type found, extract the boundary */
            param = mo->content.origType->params;
            while(NULL != param)
            {
                if ((MMS_TEXT_KEY == param->param) && (NULL != param->key) &&
                    (0 == msf_cmmn_strcmp_nc((char *)param->key, 
                    MEA_MMV_DRM_BOUNDARY)) && (NULL != param->value.string))
                {
                    /* Boundary found, copy and return */
                    ret = MEA_ALLOC(sizeof(MEA_MMV_DRM_BOUNDARY) + 
                        sizeof(MEA_EQUAL_STR) + strlen((char *)param->value.string) + 
                        sizeof(MSF_EOS));
                    strcpy(ret, MEA_MMV_DRM_BOUNDARY);
                    strcat(ret, MEA_EQUAL_STR);
                    strcat(ret, (char *)param->value.string);
                    return ret;
                }
                param = param->next;
            }
        }
    }
    return NULL;
}

/*!
 * \brief Send a media object to the content router
 * \param inst  The current instance
 * \return TRUE upon success
 *****************************************************************************/
static void viewUnknownMo(const MeaMmvInstance *inst)
{
    MeaCrhBodyPart *crhBodyPart;
    MEA_CALLOC(crhBodyPart, sizeof(MeaCrhBodyPart));

    /* Handle content type */

    if (NULL == (crhBodyPart->contentType = makeMimeType(inst->currentMo)))
    {
        return;
    }
    crhBodyPart->index          =  (MSF_UINT32)inst->currentMo->bpIndex;
    crhBodyPart->fsm            = MEA_MMV_FSM;
    crhBodyPart->signal         = MEA_SIG_MMV_CRH_DONE;
    crhBodyPart->contentHeaders = handleDrm(inst->currentMo, crhBodyPart->contentType);
    crhBodyPart->mmsMsgId       = inst->msgId;
    crhBodyPart->fileType       = inst->fileType;
    crhBodyPart->readPos        = 0;
    crhBodyPart->fileName       = inst->currentMo->name;
    /* Start the content router FSM*/
    (void)MEA_SIGNAL_SENDTO_P(MEA_CRH_FSM, MEA_SIG_CRH_START, crhBodyPart);    
}
//#endif /* ~WAP_SUPPORT */

#if MEA_USE_CONTENT_ROUTING==1   

/*!
 * \brief Send a media object to the content router
 * \param inst  The current instance
 * \return TRUE upon success
 *****************************************************************************/
static void getActionsForMo(const MeaMmvInstance *inst)
{
    MeaCrhBodyPart *crhBodyPart;
    MEA_CALLOC(crhBodyPart, sizeof(MeaCrhBodyPart));

    /* Handle content type */

    if (NULL == (crhBodyPart->contentType = makeMimeType(inst->currentMo)))
    {
        return;
    }
    crhBodyPart->index          =  (MSF_UINT32)inst->currentMo->bpIndex;
    crhBodyPart->fsm            = MEA_MMV_FSM;
    crhBodyPart->signal         = MEA_SIG_MMV_HANDLE_ACTION_RSP;
    crhBodyPart->contentHeaders = handleDrm(inst->currentMo, crhBodyPart->contentType);
    crhBodyPart->mmsMsgId       = inst->msgId;
    crhBodyPart->fileType       = inst->fileType;
    crhBodyPart->readPos        = 0;
    crhBodyPart->fileName       = inst->currentMo->name;
    /* Start the content router FSM*/
    (void)MEA_SIGNAL_SENDTO_P(MEA_CRH_FSM, MEA_SIG_CRH_START, crhBodyPart);    
}
#endif
//#ifndef WAP_SUPPORT
/*!
 * \brief Preview an audio media object
 * \param inst  The current instance
 * \return TRUE upon success
 *****************************************************************************/
static MSF_BOOL viewAudioMo(const MeaMmvInstance *inst)
{
    MeaMoDataItem *mo = inst->currentMo;

    if (mo == NULL)
    {
        return FALSE;
    }
    
    /* play audio */
    return meaUiMmvPlayAudio(mo->data, mo->content.type, mo->size);
}
#endif /* ~WAP_SUPPORT */

/*!
 * \brief Set current media object by index
 * \param inst  The current instance
 * \param index Index 
 *****************************************************************************/
static void setCurrentMo(MeaMmvInstance *inst, int index)
{
    if (index >= 0)
    {
        inst->currentMo = getMoAtIndex(inst, index);    
    }
    else
    {
        inst->currentMo = NULL;
    }
}

#ifndef WAP_SUPPORT
/*!
 * \brief Starts the BRA with a specific URL.
 *
 * \param url The URL to open in the BRA.
 *****************************************************************************/
static void startBra(char *url)
{
#ifdef MSF_MODID_BRA
    msf_content_data_t  contentData;

    memset(&contentData, 0, sizeof(msf_content_data_t));
    contentData.contentUrl = url;
    contentData.contentDataType = MSF_CONTENT_DATA_NONE;
    MSF_MODULE_START(MSF_MODID_MEA, MSF_MODID_BRA, NULL, &contentData, NULL);
#else
    MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
        MAMMV_BC4F74D83BDE9AC286AF7667079A7191, "(%s) (%d) Failed to start the BRA with the URL: %s, because the BRA"
        "is not defined!\n", __FILE__, __LINE__, url));
#endif
}

/*!
 * \brief Handles the viewing of a link detected inside a text object
 * 
 * \param linkIn  The particular link
 * \param fsm     The fsm to call when viewing is done
 * \param sig     The signal to send when viewing is done
 * \return TRUE upon success
 *****************************************************************************/
static MSF_BOOL viewLink(void *linkIn, MeaStateMachine fsm, int sig)
{
    MtrLinkEntry *link = (MtrLinkEntry *)linkIn;

    if ((NULL == link) || (NULL == link->link))
    {
        return FALSE;
    } /* if */

    switch (link->scheme)
    {
    case MTR_SCHEME_HTTP:
    case MTR_SCHEME_HTTPS:
    case MTR_SCHEME_WWW:
        startBra(link->link);
        return TRUE;

    case MTR_SCHEME_PHONE:
        meaSrhMakeCall(fsm, sig, link->link);
        return TRUE;

    case MTR_SCHEME_NONE:
    case MTR_SCHEME_MAIL:
    default:
        (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_UNHANDLED_LINK), 
            MEA_DIALOG_ALERT);
        return FALSE;
    } /* switch */

} /* viewLink */

/*!
 * \brief Preview a media object
 * \param inst  The current instance
 * \return TRUE upon success
 *****************************************************************************/
static MSF_BOOL viewMo(const MeaMmvInstance *inst)
{
    MeaMoDataItem *mo = inst->currentMo;

    if (mo == NULL)
    {
        return FALSE;
    }

    /* Dispatch media object according to its media type */
    switch (meaMediaType2ObjType(mo->content.type))
    {
    case MEA_MEDIA_GROUP_AUDIO:
        /* play audio */
        return viewAudioMo(inst);
    case MEA_MEDIA_GROUP_IMAGE:
        /* insert code here to view images */
        return TRUE;
    case MEA_MEDIA_GROUP_TEXT:
        /* insert code here to view text */
        return TRUE;
    case MEA_MEDIA_GROUP_NONE:
    default:
        /* let the content router handle the media object */
        viewUnknownMo(inst);
        return TRUE;
    }
}
#endif /* ~WAP_SUPPORT */


#ifdef MMS_SLIM_MEM
static void meaActTerminate(void)
{
  if (meaActHandle)
  {
    msf_act_terminate (meaActHandle);
    meaActHandle = NULL;
  }
}

msf_pck_handle_t * meaGetActHandle(void)
{
    return meaActHandle;
}
#endif /* MMS_SLIM_MEM */

/*!
 * \brief Save the media object
 *
 * \param instance The current instance.
 *****************************************************************************/
static void saveMo(const MeaMmvInstance *instance)
{
    MeaMoDataItem *mo = instance->currentMo;
#ifdef MMS_SLIM_MEM
    MSF_INT32             actId;
    msf_pck_result_t      result;
    char *vFileName = NULL;
    const char *mime = NULL;
    int fileHandle = 0;

    meaUiMmvDeleteMenu();   
    vFileName = MEA_ALLOC(WIDGET_RAWFILE_NAMELEN);
    ASSERT(vFileName != NULL);

    fileHandle = MSF_FILE_OPEN( MSF_MODID_SMA, mo->file->path, MSF_FILE_SET_RDONLY, 0);
    if(fileHandle < 0)
    {
        MEA_FREE(vFileName);
        fileHandle = 0;
        meaShowDialog(MEA_GET_STR_ID(SMA_STR_ID_FAILED_TO_SAVE),MEA_DIALOG_ERROR);
        return;
    }

    if(HDIa_fileGenVirtualFileName(fileHandle, vFileName, WIDGET_RAWFILE_NAMELEN, mo->file->pos, mo->file->size) != HDI_FILE_OK)
    {
        MEA_FREE(vFileName);
        MSF_FILE_CLOSE(fileHandle);
        fileHandle = 0;
        meaShowDialog(MEA_GET_STR_ID(SMA_STR_ID_FAILED_TO_SAVE),MEA_DIALOG_ERROR);
        return;
    }

    if((mime = meaFileName2MimeType(mo->name)) == NULL)
    {
        mime = MEA_UNKNOWN_MIME_STR;
    }
    meaActHandle = (msf_pck_handle_t*)msf_act_init(MSF_MODID_MEA);
    actId = msf_act_object_action_drm (meaActHandle,
                   0, 
                   mime,
                   MsfResourceFile,
                   NULL,
                   mo->size,
                   vFileName,
                   NULL,
                   mo->name,
                   0, //for drm
                   meaGetScreenHandle(),
                   NULL,
                   NULL,
                   0);

    msf_act_get_result (meaActHandle, actId, &result);
    msf_act_result_free (meaActHandle, &result);
    meaActTerminate();
    MEA_FREE(vFileName);
    MSF_FILE_CLOSE(fileHandle);
#else
    (void)meaCreateSaveAs(MEA_MMV_FSM, MEA_SIG_MMV_SAVE_DONE, 
        meaMediaType2Mime(mo->content.type) , mo->name, (char*)mo->data, (long)mo->size);
#endif /* MMS_SLIM_MEM */
}

/*!
 * \brief Creates a new instance used for viewing multipart/mixed msgs
 *
 * \param instance The current instance.
 * \param srcInstance The old getMsg instance.
 *****************************************************************************/
static void meaMmvCreateInstance(MeaMmvInstance **instance,
    const MeaMessage *srcInstance)
{   
    *instance = MEA_ALLOC(sizeof(MeaMmvInstance));
    /* Clear the structure */
    memset(*instance, 0, sizeof(MeaMmvInstance));

    (*instance)->moList = srcInstance->smilInfo->mediaObjects;
    (*instance)->msgId = srcInstance->msgId;
    (*instance)->fileType = srcInstance->fileType;
#ifdef WAP_SUPPORT
    if(srcInstance->smilInfo->mediaObjects != NULL)
    {
        if (srcInstance->msgType == MEA_MR_PLAIN_TEXT && srcInstance->smilInfo->mediaObjects->next == NULL &&
            srcInstance->smilInfo->mediaObjects->content.type == -1)
        {
            srcInstance->smilInfo->mediaObjects->content.type = MEA_MEDIA_TYPE_TEXT_PLAIN;
        }
    }
#endif /* WAP_SUPPORT */
}

/*!
 * \brief Deletes multipart/mixed viewer instance 
 *
 * \param instance The current instance.
 *****************************************************************************/
static void meaMmvDeleteInstance(MeaMmvInstance **instance)
{
    if (*instance != NULL)
    {
        MEA_FREE(*instance);
        *instance = NULL;
    }
}




/*!
 * \brief Handle signal received from MOB 
 * \param inst  the current instance
 * \param op    the MOB operation
 * \param i     integer parameter to MOB operation
 * \param p     pointer parameter to MOB operation
 *****************************************************************************/
static void handleMobOp(MeaMmvInstance *inst, MeaMobOperation op, int i, 
    MtrLinkEntry *p)

{
#ifndef WAP_SUPPORT		
    MtrLinkEntry *links = p;
#endif /* WAP_SUPPORT */
 

    switch (op)
    {   
    case MEA_MOB_SELECT:
#ifndef WAP_SUPPORT		
        /* User pressed Ok */
        if (i < 0)
        {
            break;
        }
        setCurrentMo(inst, i);
        if (NULL != p)
        {
            if (!viewLink(p, MEA_MMV_FSM, MEA_SIG_MMV_MAKE_CALL_RSP))
            {
                MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                    MAMMV_582D04C5BE147DCAA432649027E59DAA, "%s(%d): mmv failed to view link\n", 
                    __FILE__, __LINE__));                      
            }
            /*lint -e{774} */
            mtrFreeLinks(&links);
        }
        else
        {
            if (!viewMo(inst))
            {
                MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                    MAMMV_010B314ABFBF8C56105021D96EAF7D09, "%s(%d): mmv failed to view media object\n", 
                    __FILE__, __LINE__));                      
            }
        } /* if */
        break;

    case MEA_MOB_MENU:
#endif /* ~WAP_SUPPORT */
        /* User pressed Menu */
         
        setCurrentMo(inst, i);
 
#if MEA_USE_CONTENT_ROUTING==1      
         getActionsForMo(inst);
#else
        if (!createMenu(inst))
        {
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                MAMMV_0901EE799926AD7B35A3DF91D56F8C66, "%s(%d): mmv Menu failed to open\n", 
                __FILE__, __LINE__));                      
        }
       
#endif
        break;

    case MEA_MOB_FOCUS_ACTIVITY:
    case MEA_MOB_SPECIAL_OP:
    case MEA_MOB_DEACTIVATED:
        /* do nothing */
        break;

    default:
        break;
    }
}

/*!
 * \brief Signal handler for the multipart mixed message viewer 
 * \param sig The received signal 
 *****************************************************************************/
static void meaMmvMain(MeaSignal *sig)
{
    switch ((MeaMmvSignalId) sig->type)
    {
    case MEA_SIG_MMV_ACTIVATE:     
        if( mmvInstance != NULL )
        {
            break;
        }
        meaMmvCreateInstance(&mmvInstance,(MeaMessage*)sig->p_param);

        /* activate MOB and let it do the browsing of attachments */
#ifdef WAP_SUPPORT //Change string to View
        meaMobActivate(mmvInstance->moList, MEA_MOB_SOP_NO_OP,
            MEA_STR_ID_VIEW, MEA_MMV_FSM, 
            MEA_SIG_MMV_MOB_OP);
#else
        meaMobActivate(mmvInstance->moList, MEA_MOB_SOP_NO_OP,
            MEA_STR_ID_VIEW_ATTACHMENTS, MEA_MMV_FSM, 
            MEA_SIG_MMV_MOB_OP);
#endif /* WAP_SUPPORT */
        break; 
        
    case MEA_SIG_MMV_DEACTIVATE:
        /* Clean-up the mmv instance */
        if (mmvInstance)
        {
            meaMmvDeleteInstance(&mmvInstance);
#ifdef WAP_SUPPORT
            (void)MEA_SIGNAL_SENDTO(MEA_MV_FSM, MEA_SIG_MV_PLAY_DONE);
#endif /* WAP_SUPPORT */
        }
        else
        {
            /* No MMV instance, delete MV directly.*/
            (void)MEA_SIGNAL_SENDTO(MEA_MV_FSM, MEA_SIG_MV_DEACTIVATE);
        }

        break;

    case MEA_SIG_MMV_MOB_OP:
        /* Handle key press from MOB */
        if (MEA_MOB_DEACTIVATED == (MeaMobOperation)sig->u_param1)
        {
            /* User selected Back, or MOB was deactivated */
            (void)MEA_SIGNAL_SENDTO(MEA_MMV_FSM, MEA_SIG_MMV_DEACTIVATE);
        }
        else
        {
            handleMobOp(mmvInstance, (MeaMobOperation)sig->u_param1, 
                sig->i_param, sig->p_param);
        }           
        break;
        
    case MEA_SIG_MMV_MAKE_CALL_RSP:
        /* sig->u_param1 has a TRUE/FALSE result */
        /* deliberately ignored since srh handles error dialogs for us */        
        break;
            
    case MEA_SIG_MMV_NAV_DEACTIVATE:
        /* Displayed menu was deactivated */
        meaUiMmvDeleteMenu();
        break;

    case MEA_SIG_MMV_NAV_SAVE:
        /* Save operation selected from menu */
        saveMo(mmvInstance);
        break;

    case MEA_SIG_MMV_SAVE_DONE:
        /* Save operation finished */
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MAMMV_25089AF8905EFF9704992FDBC00AC3E6, "%s(%d): Save object done\n", 
            __FILE__, __LINE__));
        meaUiMmvDeleteMenu();        
        break;

    case MEA_SIG_MMV_CRH_DONE:
        /* Content router handler finished */
        if (sig->u_param1 != MEA_CRH_VIEW_ATTACH_OK)
        {
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_ATTACH_ERROR), 
                MEA_DIALOG_ALERT);
        }
        meaUiMmvDeleteMenu();
        break;

    case MEA_SIG_MMV_HANDLE_ACTION_RSP:
         /* Content router handler finished */
        if (sig->u_param1 != MEA_CRH_VIEW_ATTACH_OK)
        {
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_ATTACH_ERROR), 
                MEA_DIALOG_ALERT);
        }
        meaUiMmvDeleteMenu();
        break;

    default: 
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MAMMV_5D088F8A8F427BC1516107E77A681AE4, "%s(%d): mmvSignalHandler erroneous signal received(%d)\n", 
            __FILE__, __LINE__, sig->type));       
        break;
    }
    meaSignalDelete(sig);
}

/*!
 * \brief Registers signal handler
 *****************************************************************************/
void meaMmvInit(void)
{
    mmvInstance = NULL;
    meaSignalRegisterDst(MEA_MMV_FSM, meaMmvMain); /* set sig-handler */
    MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
        MAMMV_406015625083040A2A368D8ED98F7C17, "MEA MMV: initialized\n"));
}

/*!
 * \brief Terminates, by de-registering signal handler
 *****************************************************************************/
void meaMmvTerminate(void)
{
    /* Clean-up the mmv instance */
    meaMmvDeleteInstance(&mmvInstance);

    /* Deregister signal handler */
    meaSignalDeregister(MEA_MMV_FSM);
    MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, MAMMV_A6267CFB8C2685F2A3AB72C369752E11, "MEA MMV: terminated\n"));
#ifdef MMS_SLIM_MEM
    meaActTerminate();
#endif /* MMS_SLIM_MEM */
}


