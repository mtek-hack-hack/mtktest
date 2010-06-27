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

/*!\file mase.c
 * SMIL editor control logic. 
 */

/* MSF */
#include "msf_mem.h"
#include "msf_int.h"
#include "msf_log.h"
#include "msf_lib.h"
#include "msf_wid.h"
#include "msf_core.h"
#include "msf_dlg.h"
#ifdef WAP_SUPPORT
#include "msf_file.h"  //for MSF_FILE_GETSIZE
#endif /* WAP_SUPPORT */

/* MMS Service/Lib */
#include "mms_def.h"
#ifdef WAP_SUPPORT
#include "mms_aApp.h" //for attachment
#include "mcpdu.h"  //for mcwap.h
#include "mcwap.h"  //for mmsWapGetTransactionId
#include "msig.h"     //for fldmgr.h
#include "fldmgr.h"  //for fldrMgrDeleteMessage
#endif /* WAP_SUPPORT */

/* SLS */
#include "sls_cfg.h"
#include "sls_if.h"

/* MEA*/
#include "mea_def.h"
#include "mea_cfg.h"
#include "matypes.h"
#include "maintsig.h"
#include "mase.h"
#include "mamr.h"
#include "mame.h"
#include "mautils.h"
#include "maslh.h"
#include "mauise.h"
#include "mamem.h"
#include "maintsig.h"
#include "macore.h"
#include "mauicmn.h"
#include "mea_rc.h"
#include "mautils.h"
#include "mauidia.h"
#include "madel.h"
#include "maph.h"
#include "mauicols.h"
#include "mauisemm.h"
#include "mamoh.h"
#ifdef WAP_SUPPORT
#include "mauimenu.h" //for updateEditContent
#include "mauime.h" 
#include "mamv.h"  //for meaMvSetActiveMsgId
#include "maconf.h" //for meaConfGetCreationMode
#include "widget_extension.h" //HDIa_xxx
#endif

#ifdef __DRM_SUPPORT__
#include "fs_type.h"
#include "../../drm/include/drm_def.h" //for DRM_METHOD_XXX
#include "../../drm/include/drm_gprot.h"
#include "../../drm/include/drm_main.h"
#endif /* __DRM_SUPPORT__ */

/******************************************************************************
 * Constants
 *****************************************************************************/

/*! Colors used for setting back-ground and forground color in SMIL.
 *	 
 */
static const MSF_UINT32 bgColors[] = MEA_CFG_SMIL_BG_COLORS;
static const MSF_UINT32 txtColors[] = MEA_CFG_SMIL_TEXT_COLORS;

/******************************************************************************
 * Data-structures
 *****************************************************************************/

/******************************************************************************
 * Static data-types
 *****************************************************************************/

/*!\brief The current message */
static MeaMeInstance *currentMsg;
#ifdef WAP_SUPPORT
static MeaSeInstance *currSeInst;
static MSF_INT32 attachmentSize = 0;
static attachmentObjectList *meaAttachmentList = NULL;
#endif /* WAP_SUPPORT */

/******************************************************************************
 * Prototypes
 *****************************************************************************/
extern MeaMoDataItem *meaFindMo(MeaMoDataItem *mo, const char *name);
static MSF_BOOL handleActivate(const MeaMessage *msg);
static void handleGetMediaObject(const MeaMessage *msg, int dlgResult, 
    char *fileName);
static MSF_BOOL deleteSlide(const MeaMessage *msg);
static void changeSlide(const MeaMessage *msg, MSF_BOOL next);
#ifdef WAP_SUPPORT
static void meaFreeAttachmentList(void);
#endif /* WAP_SUPPORT */
static void exitSmilCreate(MSF_BOOL showDialog, MSF_UINT32 strId);
static void seSignalHandler(MeaSignal *sig);
static MSF_BOOL editText(const MeaMessage *msg);
static MSF_BOOL editMediaObject(const MeaMessage *msg, MeaMediaGroupType objType);
static MeaSeverity setMediaObject(MeaSmilInfo *smilInfo, 
    const MeaPropItem *propItem, MeaAfiReadResultData *objData, 
    MeaAfiReadResult readResult);
extern void meaSeFocusObject(MeaMediaGroupType type);
/******************************************************************************
 * Function implementation
 *****************************************************************************/

/*!
 * \brief Edits the current media object or inserts new content.
 *
 * \param smilInfo The current SMIL presentation.
 * \return TRUE on OK else FALSE
 *****************************************************************************/
static MSF_BOOL editMediaObject(const MeaMessage *msg, MeaMediaGroupType objType)
{
    switch (objType)
    {
    case MEA_MEDIA_GROUP_IMAGE:
        if(meaConfGetCreationMode() == MEA_CREATION_MODE_RESTRICTED)
            return meaOpenDlgCreateMediaInput(MEA_SE_FSM, MEA_SIG_SE_GET_MEDIA_OBJECT, 
                MEA_CFG_OPEN_RESTRICTED_IMAGE_TYPES, meaInsertSMILObjCallback);
        else        
            return meaOpenDlgCreateMediaInput(MEA_SE_FSM, MEA_SIG_SE_GET_MEDIA_OBJECT, 
                MEA_CFG_OPEN_IMAGE_TYPES, meaInsertSMILObjCallback);
    case MEA_MEDIA_GROUP_AUDIO:
        if(meaConfGetCreationMode() == MEA_CREATION_MODE_RESTRICTED)
            return meaOpenDlgCreateMediaInput(MEA_SE_FSM, MEA_SIG_SE_GET_MEDIA_OBJECT, 
                MEA_CFG_OPEN_RESTRICTED_AUDIO_TYPES, meaInsertSMILObjCallback);
        else        
            return meaOpenDlgCreateMediaInput(MEA_SE_FSM, MEA_SIG_SE_GET_MEDIA_OBJECT, 
                MEA_CFG_OPEN_AUDIO_TYPES, meaInsertSMILObjCallback);
    case MEA_MEDIA_GROUP_VIDEO:
        if(meaConfGetCreationMode() == MEA_CREATION_MODE_RESTRICTED)
            return meaOpenDlgCreateMediaInput(MEA_SE_FSM, MEA_SIG_SE_GET_MEDIA_OBJECT, MEA_CFG_OPEN_RESTRICTED_VIDEO_TYPES, meaInsertSMILObjCallback);
        else        
            return meaOpenDlgCreateMediaInput(MEA_SE_FSM, MEA_SIG_SE_GET_MEDIA_OBJECT, MEA_CFG_OPEN_VIDEO_TYPES, meaInsertSMILObjCallback);
    case MEA_MEDIA_GROUP_TEXT:
            return editText(msg);
    case MEA_MEDIA_GROUP_ATTACHMENT:
        if(meaConfGetCreationMode() == MEA_CREATION_MODE_RESTRICTED)
            return meaOpenDlgCreateMediaInput(MEA_SE_FSM, MEA_SIG_SE_GET_MEDIA_OBJECT, 
                MEA_CFG_OPEN_RESTRICTED_ATTACHMENT_TYPES, meaInsertSMILObjCallback);
        else        
            return meaOpenDlgCreateMediaInput(MEA_SE_FSM, MEA_SIG_SE_GET_MEDIA_OBJECT, 
                MEA_CFG_OPEN_ATTACHMENT_TYPES, meaInsertSMILObjCallback);
    case MEA_MEDIA_GROUP_NONE:
        return FALSE;
    }
    return FALSE;
} /* editMediaObjects */

/*! \brief Edit the text part of the current slide
 *	
 * \param msg The current message.
 *****************************************************************************/
static MSF_BOOL editText(const MeaMessage *msg)
{
    char *text = NULL;
    /* get the current text */
    if ((NULL != meaGetCurrentSlide(msg->smilInfo)) &&
        (NULL != meaGetMo(msg->smilInfo, MEA_MEDIA_GROUP_TEXT)))
    {
        text = (char *)(meaGetMo(msg->smilInfo, MEA_MEDIA_GROUP_TEXT)->data);
    }
    /* Display the text */
    if (!meaSeCreateTextView(text, msg->msgProperties->subject))
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MASE_9E84D7BEDA1489079387DC65151ED050, "Create text view failed!\n"));
        return FALSE;
    } /* if */
    return TRUE;
}

/*!
 * \brief Exit the SMIL creation.
 *
 * \param showDialog TRUE if an error dialog should be displayed, otherwise
 *                   FALSE.
 * \param strId The string ID of the text to display in the dialog.
 *****************************************************************************/
static void exitSmilCreate(MSF_BOOL showDialog, MSF_UINT32 strId)
{
    /* Display dialog */
    if (showDialog)
    {
        (void)meaShowDialog(MEA_GET_STR_ID(strId), MEA_DIALOG_ERROR);
    }
    /* terminate ME och SE */
    meaMeTerminateGui();
    meaSeTerminateGui();
    (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_DEACTIVATE);
    (void)MEA_SIGNAL_SENDTO(MEA_SE_FSM, MEA_SIG_SE_DEACTIVATE);
} /* exitSmilCreate */

#ifdef WIDGET_ADVANCED_SMIL_EDITOR
/*! \brief Adds text object to a message
 *
 * \param objData the media object and information about it
 * \param readResult the result of the load object operation
 * \return  MEA_SEVERITY_OK if mo added, MEA_SEVERITY_WARNING 
 *          if mo added with warning, MEA_SEVERITY_ERROR if mo not added
 *****************************************************************************/
MeaSeverity meaSeSetTextObject(MeaAfiReadResultData *objData)
{
    int msgSize = meaCalculateMsgSize(currentMsg->theMessage->smilInfo, currentMsg->theMessage->msgProperties);
    MeaMoDataItem *item = meaGetMo(currentMsg->theMessage->smilInfo, MEA_MEDIA_GROUP_TEXT);
	widget_string_pack_struct title;
	char *sizeBuffer;

    if(!objData)
    {
        ASSERT(0);
    }

    if(item != NULL)
    {
        msgSize = msgSize - item->size + objData->size;
    }
    else
    {
        msgSize += objData->size;
    }

    /* Update title string :
     * If msgSize > MEA_CFG_MESSAGE_SIZE_MAXIMUM, the text MO won't be inserted successfully.
     * But we shall update the size, because the text is in editor. This is also informative */

    /* Format string: do not use string resource ID, ex. MEA_STR_ID_KB, for font consistency */
    sizeBuffer = MEA_ALLOC((MSF_UINT32)(strlen("300 KB ") + 1));
    sprintf(sizeBuffer, "%d KB ", (msgSize + (MEA_1_KB - 1)) / MEA_1_KB);
    title.type = WIDGET_STRING_PACK_UTF8;
    title._u.ucs2 = (kal_uint8*)sizeBuffer;
    HDIa_widgetExtSmilEditorUpdateTitle2(meaSeGetFormHandle(), title);
	MEA_FREE(sizeBuffer);

    if(msgSize > MEA_CFG_MESSAGE_SIZE_MAXIMUM)
    {
        meaShowSizeWarningDialog(msgSize, objData->size, MEA_MEDIA_TYPE_TEXT_PLAIN, 0, 0);
        return MEA_SEVERITY_ERROR;
    }

    currSeInst->oper = MEA_SE_OPER_ADD;
    currSeInst->operObjType = MEA_MEDIA_GROUP_TEXT;
    return setMediaObject(currentMsg->theMessage->smilInfo, 
        currentMsg->theMessage->msgProperties, objData, MEA_AFI_READ_RESULT_OK);
}
#endif /* WIDGET_ADVANCED_SMIL_EDITOR */

/*! \brief Adds a media object to a SMIL structure and removes the old object
 *         if any.
 *
 * \param smilInfo the SMIL structure to insert the media object into
 * \param propItem properties of the message to modify
 * \param objData the media object and information about it
 * \param readResult the result of the load object operation
 * \return  MEA_SEVERITY_OK if mo added, MEA_SEVERITY_WARNING 
 *          if mo added with warning, MEA_SEVERITY_ERROR if mo not added
 *****************************************************************************/
static MeaSeverity setMediaObject(MeaSmilInfo *smilInfo, 
    const MeaPropItem *propItem, MeaAfiReadResultData *objData, 
    MeaAfiReadResult readResult)
{
    MeaMediaType        mType = MEA_MEDIA_TYPE_UNKNOWN;
#ifdef __DRM_SUPPORT__ 
    MeaMediaType        drmType = MEA_MEDIA_TYPE_UNKNOWN;
#endif
    MSF_UINT32  errStrId = 0;

    /* Check read result */
    switch(readResult)
    {
        case MEA_AFI_READ_RESULT_OK:
            break;
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

    if (readResult != MEA_AFI_READ_RESULT_OK || NULL == objData)
    {
        (void)meaShowDialog(MEA_GET_STR_ID(errStrId), MEA_DIALOG_ERROR);
        return MEA_SEVERITY_ERROR;
    }

    /* Check media type */
    if (NULL != objData->mimeType) 
    {
        mType = meaMime2MediaType(objData->mimeType);
#ifdef __DRM_SUPPORT__ 
        if (NULL != objData->drmMimeType) 
        {
            drmType = meaMime2MediaType(objData->drmMimeType);
        }
#endif
    }

    if (NULL == objData->fileName)
    {
        if (NULL == (objData->fileName = meaCreateFileNameFromType(mType)))
        {
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_FAILED_TO_READ_MO),
                MEA_DIALOG_ERROR);
            return MEA_SEVERITY_ERROR;
        }
    }

    /* Auto insert slide */
    if (currSeInst->oper == MEA_SE_OPER_ADD)
    {
        MeaMediaGroupType visibleObjs = meaGetCurrentSlideObjectDef();
        switch (currSeInst->operObjType)
        {
        case MEA_MEDIA_GROUP_TEXT:
            break;
        case MEA_MEDIA_GROUP_IMAGE:
            if ((visibleObjs & MEA_MEDIA_GROUP_IMAGE) || (visibleObjs & MEA_MEDIA_GROUP_VIDEO))
            {
                if (smilInfo->noOfSlides >= MEA_CFG_SLIDE_LIMIT)
                {
                    (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_SLIDE_LIMIT_REACHED), MEA_DIALOG_ALERT);
                    return MEA_SEVERITY_ERROR;
                }

                if (NULL == meaInsertSlide(smilInfo))
                {
                    return MEA_SEVERITY_ERROR;
                } 
            }
            break;
        case MEA_MEDIA_GROUP_AUDIO:
            if ((visibleObjs & MEA_MEDIA_GROUP_AUDIO) || (visibleObjs & MEA_MEDIA_GROUP_VIDEO))
            {
                if (smilInfo->noOfSlides >= MEA_CFG_SLIDE_LIMIT)
                {
                    (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_SLIDE_LIMIT_REACHED), MEA_DIALOG_ALERT);
                    return MEA_SEVERITY_ERROR;
                }

                if (NULL == meaInsertSlide(smilInfo))
                {
                    return MEA_SEVERITY_ERROR;
                } 
            }
            break;
            
        case MEA_MEDIA_GROUP_VIDEO:
            if ((visibleObjs & MEA_MEDIA_GROUP_IMAGE) || (visibleObjs & MEA_MEDIA_GROUP_VIDEO)
                || (visibleObjs & MEA_MEDIA_GROUP_AUDIO))
            {
                if (smilInfo->noOfSlides >= MEA_CFG_SLIDE_LIMIT)
                {
                    (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_SLIDE_LIMIT_REACHED), MEA_DIALOG_ALERT);
                    return MEA_SEVERITY_ERROR;
                }

                if (NULL == meaInsertSlide(smilInfo))
                {
                    return MEA_SEVERITY_ERROR;
                } 
            }
            break;
        default:
            return MEA_SEVERITY_ERROR;
        }
    }

    /* Insert object to slide and mo list */

    /* All text were deleted in editor, delete the original mo object */
    if (!objData->size && MEA_MEDIA_TYPE_TEXT_PLAIN == mType && NULL != meaGetMo(smilInfo, meaMediaType2ObjType(mType)))
    {
        (void)meaDeleteSlideMo(smilInfo, meaMediaType2ObjType(mType));
        return MEA_SEVERITY_OK;
    }
    else if (objData->size &&
#ifdef __DRM_SUPPORT__ 
     (NULL == meaSetSlideMo(smilInfo, mType, drmType, NULL, objData->data, objData->size, objData->fileName, objData->resHandle)))
#else
     (NULL == meaSetSlideMo(smilInfo, mType, NULL, objData->data, objData->size, objData->fileName, objData->resHandle)))
#endif
    {
        (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_FAILED_TO_READ_MO), MEA_DIALOG_ERROR);
        return MEA_SEVERITY_ERROR;
    }
    /* The data is consumed by the meaSetSlideMo, set pointers to NULL */
    objData->data = NULL;
    objData->fileName = NULL;

    meaOptimizeMoList(smilInfo);
    return MEA_SEVERITY_OK;
}

#ifdef WAP_SUPPORT
/*!
 * \When an attachment is added/edited/removed, call this function to setSeModifiedFlag
 *****************************************************************************/
void meaShowSlideForAttachment(void)
{
    if (!meaSeShowSlide(currentMsg->theMessage->smilInfo, currentMsg->theMessage->msgProperties))
    {
        exitSmilCreate(TRUE, MEA_STR_ID_EDIT_FAILED_RESOURCES_EXHAUSTED);
    }
}

MSF_UINT32 meaSeGetAttachmentPayloadSize(char *filepath)
{
    MSF_INT32 payloadSize = 0;  /* rough estimation, can be improved */
    MmsKnownMediaType mType = MMS_VALUE_AS_STRING;
    const char *strMimeType = NULL;
    char *filename = NULL;

    strMimeType = meaFileName2MimeType(filepath);
    if (strMimeType == NULL)
    {
        ASSERT(0);
    }

    mType = meaMime2MmsMediaType(strMimeType);
    filename = msf_cmmn_strdup(MSF_MODID_MEA, filepath);
    meaExtractFileName(filename);
    if (mType == MMS_VALUE_AS_STRING)
    {
        payloadSize += 1 + strlen(strMimeType);
    }
    else
    {
        payloadSize += 2;
    }

    payloadSize += 1 + strlen(filename);  /* Name param */
    payloadSize += 1 + strlen(filename);  /* Content location */
    payloadSize += 4 + strlen(filename);  /* Content ID : "<...> */
    payloadSize += MSF_FILE_GETSIZE(filepath);
    MEA_FREE(filename);
    return payloadSize;
}

MSF_UINT32 meaSeGetAttachmentNo(void)
{
    MSF_UINT32 i;
    attachmentObjectList *ptr = meaAttachmentList;
    for (i = 0; ptr != NULL; ptr = ptr->next, i++);
    return i;
}

attachmentObjectList *meaSeGetAttachmentByIndex(int index)
{
    int i;
    attachmentObjectList *ptr = meaAttachmentList;

    if (index < 0 || index >= MEA_MAX_ATTACHMENT_NO)
    {
        return NULL;
    }

    for (i = 0; i < index && ptr != NULL; i++, ptr = ptr->next);
    return ptr;
}

void meaSeRemoveAttachmentByIndex(int index)
{
    int i;
    attachmentObjectList *ptr = meaAttachmentList;
    attachmentObjectList *prev = NULL;

    if (meaAttachmentList == NULL)
    {
        return;
    }
    
    for (i = 0; i < index && ptr != NULL; i++, prev = ptr, ptr = ptr->next);

    if (ptr == NULL)
    {
        return;
    }
    else if (prev == NULL)
    {
        meaAttachmentList = ptr->next;
    }
    else
    {
        prev->next = ptr->next;
    }

    /* Update size */
    attachmentSize -= meaSeGetAttachmentPayloadSize((char *)ptr->filepath);
    ASSERT(attachmentSize >= 0);

    MEA_FREE(ptr->filepath);
    ptr->filepath = NULL;
    MEA_FREE(ptr->filename);
    ptr->filename = NULL;
    if (ptr->mimetype_mode == 1)
    {
        MEA_FREE(ptr->mimetype_svalue);
        ptr->mimetype_svalue = NULL;
    }
    MEA_FREE(ptr);
}

void meaSeReplaceAttachment(int index, char *fileName)
{
    attachmentObjectList *item = NULL;
    MmsKnownMediaType mType = MMS_VALUE_AS_STRING;
    const char *strMimeType = NULL;

#ifdef __DRM_SUPPORT__
    if (meaDrmGetMethod(fileName) == DRM_METHOD_SEPARATE_DELIVERY)
    {
        strMimeType = "application/vnd.oma.drm.content";
    }
    else
#endif
    strMimeType = meaFileName2MimeType(fileName);

    if (!strMimeType)
    {
        meaShowDialog(MEA_GET_STR_ID(MSF_STR_ID_DLG_MIME_ACTION_NONE), MEA_DIALOG_ERROR);
        return;
    }
    
    mType = meaMime2MmsMediaType(strMimeType);
    item = MEA_ALLOC(sizeof(attachmentObjectList));
    item->next = NULL;
    item->charset = MMS_UTF8;
    item->isTextObject = FALSE;

    item->filepath = (MSF_UINT8 *)msf_cmmn_strdup(MSF_MODID_MEA, fileName);
    meaExtractFileName(fileName);
    item->filename = (MSF_UINT8 *)msf_cmmn_strdup(MSF_MODID_MEA, fileName);

    if (mType == MMS_VALUE_AS_STRING)
    {
        item->mimetype_mode = 1;
        item->mimetype_svalue = (MSF_UINT8 *)msf_cmmn_strdup(MSF_MODID_MEA, strMimeType);
    }
    else
    {
        item->mimetype_mode = 0;
        item->mimetype_cvalue = (MSF_UINT8)mType;
    }

    meaSeRemoveAttachmentByIndex(index);
    if (index == 0)
    {
        item->next = meaAttachmentList;
        meaAttachmentList = item;
    }
    else
    {
        int i;
        attachmentObjectList *prev = meaAttachmentList;
        for (i = 1; i < index && prev->next; i++, prev = prev->next);  /* start from 1, we get prev */
        item->next = prev->next;
        prev->next = item;
    }

    /* Update size */
    attachmentSize += meaSeGetAttachmentPayloadSize((char *)item->filepath);
}

void meaSeAddAttachment(char *fileName)
{
    attachmentObjectList *item = NULL;
    MmsKnownMediaType mType = MMS_VALUE_AS_STRING;
    const char *strMimeType = NULL;

#ifdef __DRM_SUPPORT__
    if (meaDrmGetMethod(fileName) == DRM_METHOD_SEPARATE_DELIVERY)
    {
        strMimeType = "application/vnd.oma.drm.content";
    }
    else
#endif
    strMimeType = meaFileName2MimeType(fileName);

    if (meaSeGetAttachmentNo() >= MEA_MAX_ATTACHMENT_NO)
    {
        meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_ATTACH_MAXIMUM_REACHED), MEA_DIALOG_ERROR);
        return;
    }
    else if (!strMimeType)
    {
        meaShowDialog(MEA_GET_STR_ID(MSF_STR_ID_DLG_MIME_ACTION_NONE), MEA_DIALOG_ERROR);
        return;
    }
    
    mType = meaMime2MmsMediaType(strMimeType);
    item = MEA_ALLOC(sizeof(attachmentObjectList));
    item->next = NULL;
    item->charset = MMS_UTF8;
    item->isTextObject = FALSE;

    item->filepath = (MSF_UINT8 *)msf_cmmn_strdup(MSF_MODID_MEA, fileName);
    meaExtractFileName(fileName);
    item->filename = (MSF_UINT8 *)msf_cmmn_strdup(MSF_MODID_MEA, fileName);

    if (mType == MMS_VALUE_AS_STRING)
    {
        item->mimetype_mode = 1;
        item->mimetype_svalue = (MSF_UINT8 *)msf_cmmn_strdup(MSF_MODID_MEA, strMimeType);
    }
    else
    {
        item->mimetype_mode = 0;
        item->mimetype_cvalue = (MSF_UINT8)mType;
    }

    /* chain to the list */
    if (meaAttachmentList)
    {
        attachmentObjectList *ptr = meaAttachmentList;
        for (; ptr->next; ptr = ptr->next);
        ptr->next = item;
    }
    else
    {
        meaAttachmentList = item;
    }

    /* Update size */
    attachmentSize += meaSeGetAttachmentPayloadSize((char *)item->filepath);
}

/*return attachmentSize*/
int meaGetAttachmentSize(void)
{
    return attachmentSize;
}

static void meaFreeAttachmentList(void)
{
    MEA_FREE(meaAttachmentList->filepath);
    meaAttachmentList->filepath = NULL;
    MEA_FREE(meaAttachmentList->filename);
    meaAttachmentList->filename = NULL;
    if (meaAttachmentList->mimetype_mode == 1)
    {
        MEA_FREE(meaAttachmentList->mimetype_svalue);
        meaAttachmentList->mimetype_svalue = NULL;
    }
}

void meaSeRemoveAttachmentList(void)
{
    meaFreeAttachmentList();
    MEA_FREE(meaAttachmentList);
    meaAttachmentList = NULL;
    attachmentSize = 0;
}

attachmentObjectList * meaGetAttachmentList(void)
{
    return meaAttachmentList;
}

MeaMediaGroupType meaGetCurrentSlideObjectDef()
{
	return meaGetSlideObjectDef(currentMsg->theMessage->smilInfo);
}

MeaInsertResult meaInsertSMILObjCallback(const char *return_pathname)	/* called in MMI task */
{
    const char * strMimeType = NULL;
    MeaMediaType mType = MEA_MEDIA_TYPE_UNKNOWN;
    MSF_INT32 filesize = 0;
    MSF_INT32 spaceLeft = 0;
    MSF_INT32 oldMOSize = 0;
    MSF_UINT32 oldMsgSize = 0;

    if(return_pathname == NULL)
        return MEA_ERR_INSERT;

    /* 1. MIME CHECK */
    strMimeType = meaFileName2MimeType(return_pathname);

    if (strMimeType)
        mType = meaMime2MediaType(strMimeType);

    /* 2. Creation Mode check */
    if(meaConfGetCreationMode() == MEA_CREATION_MODE_RESTRICTED && meaIsRestrictedType(return_pathname) == FALSE)
    {
        return MEA_ERR_INSERT_UNRESTRICTED;
    }
#if 0    /* !! Remove the comment-out after video type is added to MEA_CFG_MEDIA_OBJECTS */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 

    /* 2. DRM CHECK */
#ifdef __DRM_SUPPORT__
    if (mType != MEA_MEDIA_TYPE_TEXT_PLAIN)
    {
        kal_uint8* externalFileName = HDI_FileNameTranslate(return_pathname);
        int objType = DRM_get_object_method(0, (kal_wchar *)externalFileName);
        if (objType == DRM_METHOD_FORWARD_LOCK || objType == DRM_METHOD_COMBINED_DELIVERY)
        {
            HDI_FileNameFree(externalFileName);
            return MEA_ERR_INSERT_DRM;
        }
        else if (objType == DRM_METHOD_SEPARATE_DELIVERY) 
        {
            mType = MEA_MEDIA_TYPE_DRM_CONTENT;
        }
        HDI_FileNameFree(externalFileName);
    }
#endif /* __DRM_SUPPORT__ */

    /* 3. IMAGE RESIZE */
#ifdef JPG_ENCODE
    if(currSeInst->operObjType == MEA_MEDIA_GROUP_IMAGE && meaMediaType2ObjType(mType) == MEA_MEDIA_GROUP_IMAGE)
    {
        MsfSize size = {0, 0}, resize = {0, 0};

        meaConfGetImageResizeValue(&resize);
        if(HDIa_widgetExtImageFileGetSize((char *)return_pathname, &size) != TRUE)
        {
            return MEA_ERR_INSERT_CORRUPT;
        }

        if((resize.width == 0 && resize.height == 0) || (size.width <= resize.width && size.height <= resize.height))  /* resizing off */
        {
        }
        else
        {
            char *name = NULL;
            char dest_name[MAX_FILE_NAME_LEN];
            int ret = MSF_WIDGET_EXT_RESIZING_SUCCEED;
            
            HDIa_widgetExtDisplayTransitionAnimationNoEnd(2);
            if (!HDIa_fileCheckDirExist(MEA_IMAGE_RESIZE_FOLDER))
            {
                (void)MSF_FILE_MKDIR(MEA_IMAGE_RESIZE_FOLDER);
            }

            memset(dest_name, 0x0 , MAX_FILE_NAME_LEN);
            name = meaCreateFileName("jpg");
            sprintf(dest_name, "%s%s", MEA_IMAGE_RESIZE_FOLDER, name);
            MEA_FREE(name);

            ret = HDIa_widgetExtImageResizing(MSF_MODID_MEA, (char *)return_pathname, (char *) dest_name, resize.width, resize.height);
            switch(ret)
            {
            case MSF_WIDGET_EXT_RESIZING_SUCCEED:
                strcpy((char *)return_pathname, dest_name);
            case MSF_WIDGET_EXT_RESIZING_SUCCEED_WITH_UNCHANGED:
                break;
            case MSF_WIDGET_EXT_RESIZING_FAILED_IN_GDI_ENCODER_ERR_DISK_FULL:
                return MEA_ERR_INSERT_DISK_FULL;
            case MSF_WIDGET_EXT_RESIZING_FAILED_IN_INSUFFICIENT_DRAWING_BUF:
            case MSF_WIDGET_EXT_RESIZING_FAILED_IN_NO_QUOTA:
                return MEA_ERR_INSERT_RESOURCE_EXHAUSTED;
            case MSF_WIDGET_EXT_RESIZING_FAILED_IN_UNKNOWN_DIMENSION:
                return MEA_ERR_INSERT_CORRUPT;
            case MSF_WIDGET_EXT_RESIZING_FAILED_IN_GDI_FAILED:
            case MSF_WIDGET_EXT_RESIZING_FAILED_IN_GDI_ENCODER_ERR_NO_DISK:
            case MSF_WIDGET_EXT_RESIZING_FAILED_IN_GDI_ENCODER_ERR_WRITE_PROTECTION:
            default:
                return MEA_ERR_INSERT_RESIZE;
            }
        }
    }
#endif /* JPG_ENCODE */

    /* 4. SIZE CHECK (after resizing) */
    filesize = MSF_FILE_GETSIZE(return_pathname);
    if(filesize <= 0)
    {
        return MEA_ERR_INSERT_EMPTY;
    }

    /* 5. MMS SIZE CHECK */
    strMimeType = meaFileName2MimeType(return_pathname);
    mType = meaMime2MediaType(strMimeType);
    oldMsgSize = meaCalculateMsgSize(currentMsg->theMessage->smilInfo, currentMsg->theMessage->msgProperties);
    spaceLeft = ((MSF_INT32)((MSF_INT32)MEA_CFG_MESSAGE_SIZE_MAXIMUM -(MSF_INT32)oldMsgSize) < 0) ? 0 : (MEA_CFG_MESSAGE_SIZE_MAXIMUM -oldMsgSize);
    
    if (currSeInst->operObjType == MEA_MEDIA_GROUP_ATTACHMENT)	/* The file is for attachment */
    {
        attachmentObjectList *old = NULL;
        oldMOSize = 0;
        if (currSeInst->oper == MEA_SE_OPER_REPLACE)
        {
            old = meaSeGetAttachmentByIndex(currSeInst->objIndex);
            oldMOSize = meaSeGetAttachmentPayloadSize((char *)old->filepath);
        }

        if (meaSeGetAttachmentPayloadSize((char *)return_pathname) > spaceLeft + oldMOSize)
        {
            return MEA_ERR_INSERT_LARGE;
        }

        if(msm_get_disk_free_space(WAP_STORAGE_MMS) < meaSeGetAttachmentPayloadSize((char *)return_pathname) + oldMsgSize)
        {
            return MEA_ERR_INSERT_DISK_FULL;        
        }
    }
    else if (meaFindMo(currentMsg->theMessage->smilInfo->mediaObjects, return_pathname) == NULL)  /* The file is for SMIL media object */
    {
        MeaMoDataItem * item = NULL;
        item = meaGetMo(currentMsg->theMessage->smilInfo, meaMediaType2ObjType(mType));
        if (currSeInst->oper == MEA_SE_OPER_REPLACE && 
            meaGetMoReferenceCount(currentMsg->theMessage->smilInfo->slides, item) == 1)    /* Replace original MO in slide */
        {
            oldMOSize = item->size;
            if (filesize > (spaceLeft + oldMOSize) && 
                meaFindMo(currentMsg->theMessage->smilInfo->mediaObjects , return_pathname) == NULL)
                return MEA_ERR_INSERT_LARGE;
        }
        else if(filesize + MEA_ENTRY_SIZE + MEA_SMIL_MO_SIZE > spaceLeft && 
            meaFindMo(currentMsg->theMessage->smilInfo->mediaObjects , return_pathname) == NULL)
        {
            return MEA_ERR_INSERT_LARGE;
        }
        else if(msm_get_disk_free_space(WAP_STORAGE_MMS) < filesize + oldMsgSize)
        {
            return MEA_ERR_INSERT_DISK_FULL;        
        }
    }
    return MEA_INSERT_OK;	
}
#endif /* WAP_SUPPORT */
/*! \brief Handles the activation of the SMIL editor
 *	
 * \param msg The current message.
 * \return TRUE if successful, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL handleActivate(const MeaMessage *msg)
{
    /* No regions defined */
    if ((NULL == msg) || (NULL == msg->smilInfo))
    {
        return FALSE;
    }
   
    /* Check if a slide needs to be inserted */
    if (0 == meaGetSlideCount(currentMsg->theMessage->smilInfo))
    {
        /* Insert the first slide */
        if (NULL == meaInsertSlide(currentMsg->theMessage->smilInfo))
        {
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                MASE_3406209EF10F6E1267812905A3309A95, "(%s) (%d) Insert slide failed in message activation\n", 
                __FILE__, __LINE__));
            return FALSE;
        } 
#ifdef WAP_SUPPORT
        (void)MEA_SIGNAL_SENDTO(MEA_SE_FSM, MEA_SIG_SE_NAV_MENU_ACTIVATE);
#endif /* WAP_SUPPORT */
    }
    /* Display the editor */
#ifndef WIDGET_ADVANCED_SMIL_EDITOR
    else if (!meaSeCreateEditorView())
#else
    if (!meaSeCreateEditorView())
#endif /* ~WIDGET_ADVANCED_SMIL_EDITOR */
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MASE_DB69CBBF206B25BFBA876AAD2562A668, "(%s) (%d) Creation of editor view failed!\n", __FILE__, __LINE__));
        return FALSE;
    } 
    else if (!meaSeShowSlide(currentMsg->theMessage->smilInfo, 
        currentMsg->theMessage->msgProperties))
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MASE_E9FDF953426C179DCD4F651B8DE3273B, "(%s) (%d) Show slide failed in!\n", __FILE__, __LINE__));
        return FALSE;
    }
    return TRUE;
}

/*! \brief Handles to load a media object from persistent storage.
 *
 * \param msg the current message.
 * \param dlgResult The result from the open dialog.
 * \param fileName The file name of the object to load.
 * \return TRUE if successful, otherwise FALSE.
 *****************************************************************************/
static void handleGetMediaObject(const MeaMessage *msg, int dlgResult, 
    char *fileName)
{
    MeaMoDataItem *item;
    MSF_UINT32 spaceLeft = 0;
    MSF_INT32 size;

    if (MSF_DLG_RETURN_OK == dlgResult)
    {
        /*
         *	No use loading media objects larger than;
         *  a) the #MEA_CFG_MESSAGE_SIZE_MAXIMUM barrier, and 
         *  b) the maximum media object size; #MEA_CFG_INSERT_MEDIA_OBJECT_MAX_SIZE
         */
        size = MEA_CFG_MESSAGE_SIZE_MAXIMUM - meaCalculateMsgSize(msg->smilInfo, msg->msgProperties);
        if (size < 0)
        {
            size = 0;
        }
        
        if (currSeInst->operObjType == MEA_MEDIA_GROUP_ATTACHMENT)  /* the insertion is for attachment */
        {
            if (currSeInst->oper == MEA_SE_OPER_REPLACE)
            {
                meaSeReplaceAttachment(currSeInst->objIndex, fileName);
            }
            else
            {
                meaSeAddAttachment(fileName);
            }
            
            if (!meaSeShowSlide(msg->smilInfo, msg->msgProperties))
            {
                exitSmilCreate(TRUE, MEA_STR_ID_EDIT_FAILED_RESOURCES_EXHAUSTED);
            }
                return;
        }
        else
        {
            MeaMoDataItem * item = NULL;
            const char * strMimeType = meaFileName2MimeType(fileName);
            MeaMediaType mType = MEA_MEDIA_TYPE_UNKNOWN;
            if (strMimeType)
                mType = meaMime2MediaType(strMimeType);
            if (NULL != (item = meaGetMo(msg->smilInfo, meaMediaType2ObjType(mType))))
            {
                size += item->size; //old media object size
                size += MEA_ENTRY_SIZE + MEA_SMIL_MO_SIZE; //tag size
            }
        }

#ifdef MMS_SLIM_MEM
        /* if the object has been inserted, use existing resource handle */
        if ((NULL != (item = meaFindMo(msg->smilInfo->mediaObjects, fileName))) /*&& meaIsObjectInSlide(item, msg->smilInfo->slides)*/ && item->reshandle != 0)
        {
            MeaAfiReadResultData *objData;
            MEA_CALLOC(objData, sizeof(MeaAfiReadResultData));
            objData->fileName = msf_cmmn_strdup(MSF_MODID_MEA, fileName);
            objData->mimeType = msf_cmmn_strdup(MSF_MODID_MEA, meaFileName2MimeType(fileName));
            objData->size = item->size;
            objData->resHandle = item->reshandle;
            (void)MEA_SIGNAL_SENDTO_UP(MEA_SE_FSM, MEA_SIG_SE_GET_MEDIA_OBJECT_RSP, MEA_AFI_READ_RESULT_OK, objData);
        }
        else
#endif
        {

        spaceLeft = MIN(size, MEA_CFG_INSERT_MEDIA_OBJECT_MAX_SIZE);
        
        if (!meaAfiLoadFromFile(MEA_SE_FSM, MEA_SIG_SE_GET_MEDIA_OBJECT_RSP, fileName, NULL, spaceLeft))
        {
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_FAILED_TO_READ_MO), MEA_DIALOG_ERROR);
            meaSeSetBusy(FALSE);
        }
        else 
        {
            /* show transition screen during widget copies wcache */
#ifdef JPG_ENCODE
            if (currSeInst->operObjType != MEA_MEDIA_GROUP_IMAGE || meaConfGetImageResize() == MEA_IMAGE_RESIZE_OFF)
#endif
            HDIa_widgetExtDisplayTransitionAnimationNoEnd(TRUE);
        }
        }
    }
    else
    {
        meaSeSetBusy(FALSE);
    }
}

/*! \brief insert a new slide into the SMIL.
 *	
 * \param msg The current message.
 * \return TRUE on success, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL insertSlide(const MeaMessage *msg, MSF_BOOL prepend)
{
    if ((NULL == msg) || (NULL == msg->smilInfo))
    {
        return FALSE;
    }
    if (meaGetSlideCount(msg->smilInfo) < MEA_CFG_SLIDE_LIMIT)
    {
        if (prepend)  /* Add before */
        {
            if(NULL == meaInsertSlideBefore(msg->smilInfo))
            {
                MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                    MASE_110B1EE58F68EF784DB3C09928BD85D3, "(%s) (%d) Insertion of slide failed!\n", __FILE__, __LINE__));
                return FALSE;
            } 
        }
        else  /* Add after */
        {
            if(NULL == meaInsertSlide(msg->smilInfo))
            {
                MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                    MASE_110B1EE58F68EF784DB3C09928BD85D3, "(%s) (%d) Insertion of slide failed!\n", __FILE__, __LINE__));
                return FALSE;
            } 
        }

        if(meaCalculateMsgSize(msg->smilInfo, msg->msgProperties) > MEA_CFG_MESSAGE_SIZE_MAXIMUM) /*TRAVIS*/
        {
            (void)meaShowDialog(MEA_GET_STR_ID(
                MEA_STR_ID_MESSAGE_SIZE_MAXIMUM_REACHED), MEA_DIALOG_ERROR);
            meaDeleteSlide(msg->smilInfo);
            return TRUE;
        }


        if(!meaSeShowSlide(msg->smilInfo, msg->msgProperties))
        {
            return FALSE;
        }
    }
    else
    {
        (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_SLIDE_LIMIT_REACHED), 
            MEA_DIALOG_ALERT);
    }
    return TRUE;
}

/*! \brief Deles a slide in the current SMIL presentation.
 *	
 * \param msg The current message.
 * \return TRUE on success, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL deleteSlide(const MeaMessage *msg)
{
    if ((NULL == msg) || (NULL == msg->smilInfo))
    {
        return FALSE;
    }
    if (!meaDeleteSlide(msg->smilInfo))
    {
        return FALSE;
    }
    if (meaGetSlideCount(currentMsg->theMessage->smilInfo) < 1)
    {
        /* Insert a new slide if there are no more slides */
        if (NULL == meaInsertSlide(currentMsg->theMessage->smilInfo))
        {
            return FALSE;
        }
    }
#ifdef WIDGET_ADVANCED_SMIL_EDITOR
    HDIa_widgetExtSmilEditorChangeSlide(1);
#endif /*WIDGET_ADVANCED_SMIL_EDITOR*/
    if(!meaSeShowSlide(currentMsg->theMessage->smilInfo, 
        currentMsg->theMessage->msgProperties))
    {
        return FALSE;
    }
    return TRUE;
}

/*! \brief Changes the curently active slide.
 *	
 * \param msg The current message.
 * \param next TRUE if the next slide should be displayed. FALSE for the 
 *             previous slide.
 *****************************************************************************/
static void changeSlide(const MeaMessage *msg, MSF_BOOL next)
{
    MeaSmilSlide *changeTo;
    if ((NULL == msg) || (NULL == msg->smilInfo))
    {
        return;
    }
    changeTo = (next) ? meaGetNextSlide(msg->smilInfo): 
        meaGetPreviousSlide(msg->smilInfo);

    if (NULL == changeTo)
    {
        return;
    }
#ifdef WIDGET_ADVANCED_SMIL_EDITOR    
    HDIa_widgetExtSmilEditorChangeSlide(KAL_TRUE);
#endif /*WIDGET_ADVANCED_SMIL_EDITOR*/    
    if(!meaSeShowSlide(msg->smilInfo, msg->msgProperties))
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MASE_008AB78CE0FB1D2AB931B72F4AAD62F9, "(5s) (%d) Show slide failed!\n", __FILE__, __LINE__));
        exitSmilCreate(TRUE, MEA_STR_ID_EDIT_FAILED_RESOURCES_EXHAUSTED);
    } /* if */
}

/*!
 * \brief The SMIL editor signal handling logic
 *
 * \param sig The received signal
 *****************************************************************************/
static void seSignalHandler(MeaSignal *sig)
{
    MeaSmilSlide            *smilSlide;
    MeaAfiReadResultData    *objData;
    MeaAfiReadResult        readResult;
    MeaObjInfo              *objInfo;

#ifdef WAP_SUPPORT //Q04A
    /* Verify that a valid instance is used */
    if ((sig->type != MEA_SIG_SE_ACTIVATE) && (NULL == currentMsg))
    {
        meaSignalDelete(sig);
        return;
    }
#endif /* WAP_SUPPORT */
    switch(sig->type)
    {
    case MEA_SIG_SE_ACTIVATE:
        currentMsg = sig->p_param;
        if (!handleActivate(currentMsg->theMessage))
        {
            exitSmilCreate(TRUE, MEA_STR_ID_EDIT_FAILED_RESOURCES_EXHAUSTED);
        }
        break;

    case MEA_SIG_SE_GET_MEDIA_OBJECT:
        if ((NULL == currentMsg) || (NULL == currentMsg->theMessage))
        {
            exitSmilCreate(FALSE, 0);
            break;
        }
        handleGetMediaObject(currentMsg->theMessage, (int)sig->u_param1, 
            sig->p_param);
        break;

    case MEA_SIG_SE_GET_MEDIA_OBJECT_RSP:
        HDIa_widgetExtCloseTransitionAnimation();
        /*
         *	Data has been fetched for inclusion into MM.
         */
            objData = (MeaAfiReadResultData *)sig->p_param;
            readResult = (MeaAfiReadResult)sig->u_param1; 
        /*
         *  If the message or media is too large then show error dialog and return
         *  to add media dialog, do not exit. TR15210
         */
        if (MEA_SEVERITY_ERROR != setMediaObject(currentMsg->theMessage->smilInfo, currentMsg->theMessage->msgProperties, objData, readResult))
        {
            if (!meaSeShowSlide(currentMsg->theMessage->smilInfo, currentMsg->theMessage->msgProperties))
            {
#ifdef MMS_SLIM_MEM
                meaAfiReleaseHandle(objData);
#endif
                meaAfiLoadFreeData(objData);
                exitSmilCreate(TRUE, MEA_STR_ID_EDIT_FAILED_RESOURCES_EXHAUSTED);
                break;
            }

#ifndef WIDGET_ADVANCED_SMIL_EDITOR
            meaSeFocusObject(currSeInst->operObjType);
#endif
        } 
        else
        {
#ifdef MMS_SLIM_MEM
            meaAfiReleaseHandle(objData);
#endif
        }

        currSeInst->oper = MEA_SE_OPER_NONE;
        currSeInst->operObjType = MEA_MEDIA_GROUP_NONE;
        /* Free data */
        meaSeSetBusy(FALSE);
        meaAfiLoadFreeData(objData);
        break;

    case MEA_SIG_SE_ADD_OBJECT:
        currSeInst->oper = MEA_SE_OPER_ADD;
        currSeInst->operObjType = (MeaMediaGroupType)sig->u_param1;
        if (!editMediaObject(currentMsg->theMessage, currSeInst->operObjType))
        {
            exitSmilCreate(TRUE, MEA_STR_ID_EDIT_FAILED_RESOURCES_EXHAUSTED);
            meaSeSetBusy(FALSE);
        }
        break;

    case MEA_SIG_SE_REPLACE_OBJECT:        
        currSeInst->oper = MEA_SE_OPER_REPLACE;
        currSeInst->operObjType = (MeaMediaGroupType)sig->u_param1;
        if (currSeInst->operObjType == MEA_MEDIA_GROUP_ATTACHMENT)
        {
            currSeInst->objIndex = (MSF_UINT32)sig->u_param2;
        }
        
        if (!editMediaObject(currentMsg->theMessage, currSeInst->operObjType))
        {
            exitSmilCreate(TRUE, MEA_STR_ID_EDIT_FAILED_RESOURCES_EXHAUSTED);
            meaSeSetBusy(FALSE);
        }
        break;

    case MEA_SIG_SE_DEACTIVATE:
#ifdef WAP_SUPPORT
		if (((NULL == currentMsg) || (NULL == currentMsg->theMessage) || (NULL == currentMsg->theMessage->smilInfo))
			&& !meaGetAttachmentList())
		{
			meaMeUpdateEditContent(NULL, NULL, 0);
		}
		else
		{
			meaMeUpdateEditContent(currentMsg->theMessage->smilInfo, currentMsg->theMessage->msgProperties, currentMsg->mode);
		}
#endif /* WAP_SUPPORT */
        currentMsg = NULL;
        meaSeTerminateGui();
        break;

    case MEA_SIG_SE_INSERT_SLIDE:
#if MEA_CFG_INSERT_SLIDE_OPTION == 1
        if ((NULL == currentMsg) || !insertSlide(currentMsg->theMessage, sig->u_param1))
#else
        if ((NULL == currentMsg) || !insertSlide(currentMsg->theMessage, FALSE))
#endif
        {
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                MASE_03F8D044F6D8C048D130BD339FBD0DAA, "Show slide failed in (%d)\n", sig->type));
            exitSmilCreate(TRUE, MEA_STR_ID_EDIT_FAILED_RESOURCES_EXHAUSTED);
        }
        break;

    case MEA_SIG_SE_DELETE_SLIDE:
        if ((NULL == currentMsg) || (!deleteSlide(currentMsg->theMessage)))
        {
            exitSmilCreate(TRUE, MEA_STR_ID_EDIT_FAILED_RESOURCES_EXHAUSTED);
            break;
        }
        break;

    case MEA_SIG_SE_NEXT_SLIDE:
        if (NULL == currentMsg)
        {
            exitSmilCreate(FALSE, 0);
            break;
        }
        changeSlide(currentMsg->theMessage, TRUE);
        break;

    case MEA_SIG_SE_PREVIOUS_SLIDE:
        if (NULL == currentMsg)
        {
            exitSmilCreate(FALSE, 0);
            break;
        }
        changeSlide(currentMsg->theMessage, FALSE);        
        break;

    case MEA_SIG_SE_REM_OBJECT:
        if (!meaDeleteSlideMo(currentMsg->theMessage->smilInfo, 
            (MeaMediaGroupType)sig->u_param1))
        {
            exitSmilCreate(TRUE, MEA_STR_ID_EDIT_FAILED_RESOURCES_EXHAUSTED);
            break;
        }
        if (!meaSeShowSlide(currentMsg->theMessage->smilInfo, 
            currentMsg->theMessage->msgProperties))
        {
            exitSmilCreate(TRUE, MEA_STR_ID_EDIT_FAILED_RESOURCES_EXHAUSTED);
            break;
        }
        meaSeSetBusy(FALSE);
        break;

    /*
     *	PREVIEW
     */
    case MEA_SIG_SE_PREVIEW_SMIL:
        /* Create a new message */
        (void)MEA_SIGNAL_SENDTO_UU(MEA_ME_FSM, MEA_SIG_ME_SAVE_PREVIEW, 
            MEA_SE_FSM, MEA_SIG_SE_PREVIEW_SAVE_DONE);
        meaSeSetBusy(TRUE);
        break;

    case MEA_SIG_SE_PREVIEW_SAVE_DONE:
        /* Start the SMA */
        if ((MSF_BOOL)sig->u_param1)
        {
            /*
             *	Start the SMA in order to play the message, all preview 
             *  messages are of type MMS_SUFFIX_SEND_REQ
             */
            meaPlaySmil(currentMsg->theMessage->msgId, 
                currentMsg->theMessage->fileType, MEA_SE_FSM, 
                MEA_SIG_SE_PREVIEW_DONE);
        }
        else
        {
            /* Failed to save, ME will have shown an error message  */
            meaSeSetBusy(FALSE);
        }
        break;

    case MEA_SIG_SE_PREVIEW_DONE:
        /* The preview has been performed. Delete the temporary message */
        if ((NULL != currentMsg) && (NULL != currentMsg->theMessage))
        {
#ifdef WAP_SUPPORT //without delete response from MMS
            fldrMgrDeleteMessage(currentMsg->theMessage->msgId);
  #ifdef MMS_FILE_PROTECT_SUPPORT
            delChkSumFile(currentMsg->theMessage->msgId);
  #endif /* MMS_FILE_PROTECT_SUPPORT */
#else
            meaDeleteMsg(currentMsg->theMessage->msgId);
#endif /* WAP_SUPPORT */
            currentMsg->theMessage->msgId = 0;
        }
        meaSeSetBusy(FALSE);

        HDIa_widgetExtCloseTransitionAnimation();

#ifdef __MMI_NONBLOCKING_DECODE__
		meaSeShowSlide(currentMsg->theMessage->smilInfo, 
        currentMsg->theMessage->msgProperties);
#endif /*__MMI_NONBLOCKING_DECODE__*/

        break;

    /*
     *	SAVING/SENDING
     */
    case MEA_SIG_SE_SAVE:
        meaSeSetBusy(TRUE);
        /* Check for "edit template" */
        if ((currentMsg->origMsgId != 0) && 
            (MMS_SUFFIX_TEMPLATE == currentMsg->origFileType))
        {
            /* If editing a template and trying to save the content, it should
               then be saved as a template */
            (void)MEA_SIGNAL_SENDTO_UU(MEA_ME_FSM, MEA_SIG_ME_SAVE_AS_TEMPLATE, 
                MEA_SE_FSM, MEA_SIG_SE_SMIL_SAVE_RSP);
        }
        else
        {
            /* Perform an ordinary save */
            (void)MEA_SIGNAL_SENDTO_UU(MEA_ME_FSM, MEA_SIG_ME_SAVE, MEA_SE_FSM, 
                MEA_SIG_SE_SMIL_SAVE_RSP);
        }
        break;
        
    case MEA_SIG_SE_SAVE_AS_TEMPLATE:
        meaSeSetBusy(TRUE);
        (void)MEA_SIGNAL_SENDTO_UU(MEA_ME_FSM, MEA_SIG_ME_SAVE_AS_TEMPLATE, 
            MEA_SE_FSM, MEA_SIG_SE_SMIL_SAVE_RSP);
        break;
        
    case MEA_SIG_SE_SEND:
        meaSeSetBusy(TRUE);
        (void)MEA_SIGNAL_SENDTO_UU(MEA_ME_FSM, MEA_SIG_ME_SEND, MEA_SE_FSM, 
            MEA_SIG_SE_SMIL_SAVE_RSP);
        break;

    case MEA_SIG_SE_SMIL_SAVE_RSP:
        meaSeSetBusy(FALSE);
        if ((MSF_BOOL)sig->u_param1)
        {    
            /*
             *	All done, let's shut down. 
             *  Any error messages will have been shown by ME.
             */
            exitSmilCreate(FALSE, 0);
        } /* if */        
        break;        
    
    /*
     *	MENU interaction
     */
    case MEA_SIG_SE_NAV_MENU_ACTIVATE:
        if ((NULL != currentMsg) && (NULL != currentMsg->theMessage) &&
            (NULL != currentMsg->theMessage->smilInfo))
        {
            smilSlide = meaGetCurrentSlide(currentMsg->theMessage->smilInfo);
            if (NULL != smilSlide)
            {
                if (!meaSeCreateNavMenu( 
                    (signed)meaGetSlideCount(currentMsg->theMessage->smilInfo), 
  #ifdef WIDGET_ADVANCED_SMIL_EDITOR
                    meaIsSmilValid(currentMsg->theMessage->smilInfo) || 
                        HDIa_widgetExtSmilEditorGetTextLength(meaSeGetFormHandle(), 0), 
  #else
                    meaIsSmilValid(currentMsg->theMessage->smilInfo), 
  #endif /* WIDGET_ADVANCED_SMIL_EDITOR */
                    meaGetSlideIndex(currentMsg->theMessage->smilInfo, smilSlide)))
                {
                    meaSeDeleteNavMenu();
                }
            }
            else
            {
                MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                    MASE_22293721A4C39D7BB4577D95EDF170E8, "Get current slide failed in (%d)\n", sig->type));
                exitSmilCreate(FALSE, 0);
            } /* if */
        }
        break;

    case MEA_SIG_SE_NAV_MENU_DEACTIVATE:
        meaSeDeleteNavMenu();
#ifdef WAP_SUPPORT
        if (!meaSmilEditorIsActive())
            meaDeleteSlide(currentMsg->theMessage->smilInfo);
#endif /* WAP_SUPPORT */
        break;

    case MEA_SIG_SE_ADD_TEXT:
#ifdef WIDGET_ADVANCED_SMIL_EDITOR
        if ((char *)sig->u_param1 != NULL)
        {
            char *string = (char *)sig->u_param1, *text_buf = meaSeGetTextBuffer();
            int cur_text_len = msf_cmmn_utf8_strlen(text_buf), ucs2_str_len = 0;
            kal_uint8 *ucs2_str = NULL;

            ucs2_str_len = (widget_utf8_length((const kal_uint8 *)string) + 1 ) * ENCODING_LENGTH;
            ucs2_str = MEA_ALLOC(ucs2_str_len);
            widget_utf8_to_ucs2_string((kal_uint8*)ucs2_str, ucs2_str_len, (const kal_uint8*)string);
            HDIa_widgetExtSmilEditorInsetText(
                meaSeGetFormHandle(), 
                (const kal_uint8*)ucs2_str);

            if (cur_text_len + msf_cmmn_utf8_strlen(string) > MEA_MAX_TEXT_LENGTH)
            {
                /*
                 * We have to show the popup after calling HDIa_widgetExtSmilEditorInsetText
                 * because HDIa_widgetExtSmilEditorInsetText will also update the editor at the same time.
                 * If we show the popup first, the animation background may be mess by the editor update.
                 */
                char *new_end = NULL;
                new_end = msf_cmmn_utf8_str_incr(string, MEA_MAX_TEXT_LENGTH - cur_text_len);
                *new_end = '\0';

                 if (cur_text_len == MEA_MAX_TEXT_LENGTH)
                 {
                    (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_MAX_TEXT_LEN_REACHED), MEA_DIALOG_ERROR);                    
                 }
                 else
                 {
                    (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_CONTENT_TRUNCATED), MEA_DIALOG_ERROR);                    
                 }
            }

            MEA_FREE(ucs2_str);
            MEA_FREE(text_buf);
            meaSeDeleteNavMenu();
        }
#endif
        break;

    /* Colors */
    case MEA_SIG_SE_SET_BG_COLOR:
        if (!meaCreateColorSelector(bgColors, sizeof(bgColors)/sizeof(bgColors[0]), 
            MEA_COLOR_NOT_VISIBLE, currentMsg->theMessage->smilInfo->bgColor, 
            MEA_SE_FSM, MEA_SIG_SE_SET_BG_COLOR_RSP))
        {
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                MASE_70A715337745FBFCA6BD529F7DA6013D, "(%s) (%d) failed to create the color selection dialog!\n"));
            exitSmilCreate(TRUE, MEA_STR_ID_EDIT_FAILED_RESOURCES_EXHAUSTED);
        }
        break;

    case MEA_SIG_SE_SET_BG_COLOR_RSP:
        if (NULL != currentMsg)
        {
            currentMsg->theMessage->smilInfo->bgColor = (MSF_UINT32)sig->u_param1;
            if (!meaSeShowSlide(currentMsg->theMessage->smilInfo, 
                currentMsg->theMessage->msgProperties))
            {
                MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                    MASE_0F7755F853854F85CC954FD8F4906952, "(%s) (%d) failed to update the SMIL editor GUI!\n"));
                exitSmilCreate(TRUE, MEA_STR_ID_EDIT_FAILED_RESOURCES_EXHAUSTED);
            }
        }
        break;

    case MEA_SIG_SE_SET_TEXT_COLOR:
        if (!meaGetObjInfo(currentMsg->theMessage->smilInfo, MEA_MEDIA_GROUP_TEXT, &objInfo) ||
            (!meaCreateColorSelector(txtColors, sizeof(txtColors)/sizeof(txtColors[0]), 
            MEA_COLOR_NOT_VISIBLE, objInfo->textColor, MEA_SE_FSM, 
            MEA_SIG_SE_SET_TEXT_COLOR_RSP)))
        {
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                MASE_70A715337745FBFCA6BD529F7DA6013D, "(%s) (%d) failed to create the color selection dialog!\n"));
            exitSmilCreate(TRUE, MEA_STR_ID_EDIT_FAILED_RESOURCES_EXHAUSTED);
        }
        break;

    case MEA_SIG_SE_SET_TEXT_COLOR_RSP:
        if ((NULL != currentMsg) && 
            (meaGetObjInfo(currentMsg->theMessage->smilInfo, 
            MEA_MEDIA_GROUP_TEXT, &objInfo)))
        {
            objInfo->textColor = (MSF_UINT32)sig->u_param1;
            if (!meaSeShowSlide(currentMsg->theMessage->smilInfo, 
                currentMsg->theMessage->msgProperties))
            {
                MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                    MASE_0F7755F853854F85CC954FD8F4906952, "(%s) (%d) failed to update the SMIL editor GUI!\n"));
                exitSmilCreate(TRUE, MEA_STR_ID_EDIT_FAILED_RESOURCES_EXHAUSTED);
            }
        }
        break;

        /* The text renderer (MTR)
         *	
         */
    case MEA_SIG_SE_SET_TEXT_COLOR_ALL:
        if (!meaGetObjInfo(currentMsg->theMessage->smilInfo, MEA_MEDIA_GROUP_TEXT, &objInfo) ||
            (!meaCreateColorSelector(txtColors, sizeof(txtColors)/sizeof(txtColors[0]), 
            MEA_COLOR_NOT_VISIBLE, objInfo->textColor, MEA_SE_FSM, 
            MEA_SIG_SE_SET_TEXT_COLOR_ALL_RSP)))
        {
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                MASE_70A715337745FBFCA6BD529F7DA6013D, "(%s) (%d) failed to create the color selection dialog!\n"));
            exitSmilCreate(TRUE, MEA_STR_ID_EDIT_FAILED_RESOURCES_EXHAUSTED);
        }
        break;

    case MEA_SIG_SE_SET_TEXT_COLOR_ALL_RSP:
        if (NULL != currentMsg) 
        {

            MeaSmilSlide* slide=currentMsg->theMessage->smilInfo->slides;
            currentMsg->theMessage->smilInfo->fgColorDefault=(MSF_UINT32)sig->u_param1;
            while(slide!=NULL)
            {
#ifdef WAP_SUPPORT
                int i;
                for(i=0;i<MEA_MAX_SMIL_OBJS;i++)
#else
                int i=0;
                for(i;i<MEA_MAX_SMIL_OBJS;i++)     
#endif /* WAP_SUPPORT */
                {
                    if(slide->objects[i]!=NULL)
                    {
                        slide->objects[i]->textColor= (MSF_UINT32)sig->u_param1;
                    }
                }
                
                slide=slide->next;
            }
            

            if (!meaSeShowSlide(currentMsg->theMessage->smilInfo, 
                currentMsg->theMessage->msgProperties))
            {
                MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                    MASE_0F7755F853854F85CC954FD8F4906952, "(%s) (%d) failed to update the SMIL editor GUI!\n"));
                exitSmilCreate(TRUE, MEA_STR_ID_EDIT_FAILED_RESOURCES_EXHAUSTED);
            }
        }
        break;
    case MEA_SIG_SE_GADGET_GOT_FOCUS:
        meaSeHandleNotif(MsfNotifyFocus);
        break;

    case MEA_SIG_SE_GADGET_LOST_FOCUS:
        meaSeHandleNotif(MsfNotifyLostFocus);
        break;

    case MEA_SIG_SE_EVENT_KEY_DOWN:
        meaSeHandleEvent(MsfKey_Down);
        break;

    case MEA_SIG_SE_EVENT_KEY_UP:
        meaSeHandleEvent(MsfKey_Up);
        break;

    default:
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MASE_71911A0E4A3A752EA47DEF87292B4F7D, "seSignalHandler erroneous signal received(%d)\n", sig->type));
        break;
    }

    meaSignalDelete(sig);
} /* seSignalHandler */

/*!
 * \brief Changes the duration for the current slide.
 *
 * \param duration A string with the new duration value.
 * \param notUsed Not used.
 * \param dataPtr Not used.
 * \param uintValue Not used.
 * \return TRUE if successful, otherwise FALSE.
 *****************************************************************************/
/*lint -e{818} */
MSF_BOOL meaSeHandleDuration(char *duration, unsigned int notUsed, 
    void *dataPtr, unsigned int uintValue)
{
    int value;
    MSF_BOOL ret = FALSE;
    if ((0 != notUsed) && (NULL != dataPtr) && (0 != uintValue))
    {
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, 
            MASE_4F2B772E76E7CD5FB4F13B26B91F1C03, "(%s) (%d) erroneous default value!\n", __FILE__, __LINE__));
    }

    if (NULL != duration)
    {
        value = atoi(duration);
        if ((value >= MEA_CFG_MIN_DURATION) && (value <= MEA_CFG_MAX_DURATION))
        {
            meaSetDuration(currentMsg->theMessage->smilInfo, (unsigned)value*1000);
            (void)MEA_SIGNAL_SENDTO(MEA_SE_FSM, MEA_SIG_SE_NAV_MENU_DEACTIVATE);
            ret = TRUE;
            meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_DONE), MEA_DIALOG_PROMPT_DONE);
        }
        else
        {
            char *dlgStr = NULL;
            dlgStr = meaGetIntervalString(MEA_STR_ID_INTERVAL_PREFIX, MEA_CFG_MIN_DURATION, 
                        MEA_STR_ID_INTERVAL_INFIX, MEA_CFG_MAX_DURATION);
            (void)showErrorDlg(dlgStr);
            MEA_FREE(dlgStr);
        }
    }
    MEA_FREE(duration);
    return ret;
}

/*!
 * \brief Gets the duration for the current slide.
 *
 * \return The duration for the current slide.
 *****************************************************************************/
unsigned int meaSeGetDuration(void) 
{
    unsigned int value = MEA_CFG_DEFAULT_DURATION;
    if ((NULL != currentMsg) && (NULL != currentMsg->theMessage) && 
        (NULL != currentMsg->theMessage->smilInfo))
    {
        value = meaGetDuration(currentMsg->theMessage->smilInfo);
    }
    else
    {
        exitSmilCreate(FALSE, 0);
    }
    return value;
}

/*!
 * \brief Initiates the SMIL editor by registering its signal handler and 
 *          initiating the data structures used for handling SMIL slides
 *****************************************************************************/
void meaSeInit(void)
{
    meaSignalRegisterDst(MEA_SE_FSM, seSignalHandler);
    MEA_CALLOC(currSeInst, sizeof(MeaSeInstance));
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
        MASE_FAA5120F0ED41029D483DAB26157AE0B, "SE FSM initialised!\n"));
} /* meaSeInit */

/*!
 * \brief Terminates the SMIL editor by de-registering its signal handler and 
 *          freeing all data structures used
 *****************************************************************************/
void meaSeTerminate(void)
{
    meaSignalDeregister(MEA_SE_FSM);
    MEA_FREE(currSeInst);
    currSeInst = NULL;
    currentMsg = NULL;
    /* Delete all dialogs */
    meaSeTerminateGui();
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, MASE_AC683386710105BA84368DB1B33CACB4, "SE FSM terminated!\n"));
} /* meaSeTerminate */

/*!
 * \brief Terminates the GUI for the SMIL editor.
 *****************************************************************************/
void meaSeTerminateGui()
{
    meaSeDeleteEditorView();
    (void)meaOpenDlgMediaInputAbort();
    (void)meaAfiLoadFromFileAbort();
    meaDeleteColorSelector();
    meaSeDeleteNavMenu();
}


