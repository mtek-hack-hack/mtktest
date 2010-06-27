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

/*! \file mamr.c
 *  \brief Handles the re-creation of a message, i.e., reads the content of a
 *         message from disk into a structure suited for MEA.
 */

/* MSF */
#include "msf_core.h"
#include "msf_mem.h"
#include "msf_int.h"
#include "msf_log.h"
#include "msf_lib.h"
#include "msf_dcvt.h"
#include "msf_wid.h"
#include "msf_chrs.h"
#include "msf_file.h"

/* MMS */
#include "mms_cfg.h"
#include "mms_def.h"
#include "mmsl_if.h"
#include "msig.h"    /* for fldmgr.h */
#include "fldmgr.h"  /* for MMS_FOLDER */

/* SLS */
#include "sls_cfg.h"
#include "sls_if.h"

/* MEA */
#include "mea_def.h"
#include "mea_cfg.h"
#include "matypes.h"
#include "mea_rc.h"
#include "maintsig.h"
#include "mamem.h"
#include "maasync.h"
#include "mamr.h"
#include "mame.h"
#include "maconf.h"
#include "macore.h"
#include "mautils.h"
#include "maslh.h"
#include "mauipm.h"
#include "maaddr.h"
#include "mauicmn.h"
#include "mamoh.h"
#ifdef WAP_SUPPORT
#include "mamh.h"    //for MeaFolder
#include "mamv.h"     //for meaMMCGetCurrentActiveMsg
#include "widget_extension.h"
#ifdef MMS_TMPLATES_MULTIPLE_LANG_SUPPORT
extern MmsMsgId meaMMCGetCurrentActiveMsg(void);
#endif
#endif

/******************************************************************************
 * Constants
 *****************************************************************************/
#define MEA_MR_FIRST_SLIDE 0    /*!< The index of the first slide in a SMIL */

/******************************************************************************
 * Static variables 
 *****************************************************************************/
extern MSF_BOOL meaContentValidFlag;
static MeaMrInstance *mrInstance;
#ifdef WAP_SUPPORT
static MSF_BOOL moIsFound = FALSE;
#endif /* WAP_SUPPORT */

#ifdef MMS_SLIM_MEM
static MeaMoDataItem *moReadMessagePart = NULL;
  #ifdef __UNIFIED_MSG_SUPPORT__
static MeaMoDataItem *moReadMixedBodyPart = NULL;
  #endif
#endif /* MMS_SLIM_MEM */
/******************************************************************************
 * Prototypes
 *****************************************************************************/
static char *createNameFromEntryHeader(const MmsEntryHeader *entries);
static MSF_BOOL createMrInstance(MeaMrInstance **inst, 
    const MeaMrStartData *mrData);
static void deleteMrInstance(MeaMrInstance **inst, MSF_BOOL useCallback, 
    MeaMrResult result);
static MSF_BOOL mrMoIsText(const MmsBodyInfoList *bi, int *charset);
static MSF_BOOL meaIsSmil(MmsGetHeader *msgHeader);
static MeaMessageType getMessageType(MmsGetHeader *msgHeader);
static MSF_BOOL readMessagePart(const MeaMrInstance *mrInst, 
    SlsMediaType slsMediaType, char *slsObjName, MeaMediaGroupType objType, 
    long offset, unsigned int size, MeaAsyncOperationHandle *handle);
static MSF_BOOL validateAddresses(const MmsAddressList *list);
static void getMsgPropertiesExpiryTime(const MeaMrInstance *inst);
static void getMsgPropertiesReplyCharging(const MeaMrInstance *inst);
static void getMsgPropertiesSubject(const MeaMrInstance *inst);
static MSF_BOOL getMsgPropAddresses(const MeaMrInstance *inst);
static MSF_BOOL mrParseHeader(MeaMrInstance *inst);
static MSF_BOOL mrReadHeader(MeaStateMachine retFsm, int retSig);
static MSF_BOOL mrReadBodyPart(MeaMrInstance *inst, MeaStateMachine retFsm, 
    int retSig);
static MSF_BOOL readText(MeaMrInstance *inst, SlsGetSlideInfoRsp *sInfo);
static MSF_BOOL readImage(MeaMrInstance *inst, SlsGetSlideInfoRsp *sInfo);
static MSF_BOOL readAudio(MeaMrInstance *inst, SlsGetSlideInfoRsp *sInfo);
static MSF_BOOL readSlideObjects(MeaMrInstance *inst, 
    SlsGetSlideInfoRsp *sInfo);
static void mrSignalHandler(MeaSignal *sig);
static void meaGetNextSlideOrClose(void);
static char *createNameFromParams(const MmsAllParams *params);
extern SlsMediaType getSlsMediaTypeFromFileName(const char *filename);
/******************************************************************************
 * Function implementation
 *****************************************************************************/

/*!
 * \brief Creates a name for one attachment.
 *
 * \param str The buffer to add the attachment name to.
 * \param strMaxLen The length of the buffer.
 * \param entries The entry header to check.
 * \return A name if one existed, otherwise NULL.
 *****************************************************************************/
static char *createNameFromEntryHeader(const MmsEntryHeader *entries)
{
    while(entries)
    {
        if (((MMS_WELL_KNOWN_CONTENT_LOCATION == entries->headerType) || 
            (MMS_WELL_KNOWN_CONTENT_ID == entries->headerType)) && 
            (NULL != entries->value.wellKnownFieldName) &&
            (0 != strlen((const char *)entries->value.wellKnownFieldName)))
        {
            char *name = msf_cmmn_strdup(MSF_MODID_MEA, (char*)entries->value.wellKnownFieldName);
            meaTransformIllegalFileName(name);
            return name;
        }
        entries = entries->next;
    }
    return NULL;
}

/*!
 * \brief Creates a name for one attachment.
 *
 * \param params The params to check.
 * \return The file name if present, otherwise NULL.
 *****************************************************************************/
static char *createNameFromParams(const MmsAllParams *params)
{
    /* try to find an MMS_FILENAME or MMS_NAME param */
    while (params) 
    {
        if (((MMS_NAME == params->param) || (MMS_FILENAME == params->param)) &&
            (MMS_PARAM_STRING == params->type) &&
            (NULL != params->value.string))
        {
            /* Use only the first valid name */
            char *name = msf_cmmn_strdup(MSF_MODID_MEA, (char *)params->value.string);
            meaTransformIllegalFileName(name);
            return name;
        }
        params = params->next;
    }
    return NULL;
}

#ifdef MMS_SLIM_MEM
MSF_BOOL isForMeaReadMessagePart(MSF_UINT32 handle, MsfNotificationType notificationType)
{
    if(moReadMessagePart)
    {
        if(moReadMessagePart->reshandle==handle)
        {
            if(notificationType!=MsfNotifyResourceLoaded)
            {
               MSF_WIDGET_RELEASE(moReadMessagePart->reshandle);
               moReadMessagePart->reshandle=0;
               moReadMessagePart=NULL;
               MEA_SIGNAL_SENDTO_U(MEA_MR_FSM,MEA_SIG_MR_MO_READ,MEA_ASIO_RESULT_ERROR);
               return TRUE;
            }
            if (!mrInstance->textHandle)
            {
            MEA_SIGNAL_SENDTO_U(MEA_MR_FSM,MEA_SIG_MR_MO_READ,MEA_ASIO_RESULT_OK);
            }
            return TRUE;
        }
    }
    return FALSE;
}

#ifdef __UNIFIED_MSG_SUPPORT__
MSF_BOOL isForMeaReadMixedBodyPart(MSF_UINT32 handle, MsfNotificationType notificationType)
{
    if(moReadMixedBodyPart && moReadMixedBodyPart->reshandle == handle)
    {
        if(notificationType != MsfNotifyResourceLoaded)
        {
            MSF_WIDGET_RELEASE(moReadMixedBodyPart->reshandle);
            moReadMixedBodyPart->reshandle = 0;
        }

        moReadMixedBodyPart=NULL;
        MEA_SIGNAL_SENDTO(MEA_MR_FSM, MEA_SIG_MR_READ_BODYPART);
        return TRUE;
    }
    return FALSE;
}
#endif
#endif /* MMS_SLIM_MEM */
/*!
 * \brief Initiates the message re-creation FSM
 *****************************************************************************/
void meaMrInit(void)
{
    mrInstance = NULL;
    meaSignalRegisterDst(MEA_MR_FSM, mrSignalHandler);
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, MAMR_7F7294D4760CE117DF91874C1E9E6004, "MR initialized.\n"));
}

/*!
 * \brief Terminates the message edit FSM.
 *****************************************************************************/
void meaMrTerminate(void)
{
    deleteMrInstance(&mrInstance, FALSE, MEA_MR_OK);
    /* Deregister queue */
    meaSignalDeregister(MEA_MR_FSM);
}

/*!
 * \brief Creates a MCR instance.
 *
 * \param inst The current instance.
 * \param mrData All needed startup data
 * \return TRUE if the instance was created, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL createMrInstance(MeaMrInstance **inst, 
    const MeaMrStartData *mrData)
{
    MeaMrInstance *newInst = NULL;

    if (NULL != *inst)
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MAMR_46AC1D7744459EEC76C15649D4EE8849, "(%s) (%d) MR instance is busy!\n", __FILE__, __LINE__));
        return FALSE;
    }

    /* Allocate the new instance */
    MEA_CALLOC(newInst, sizeof(MeaMrInstance));
    MEA_CALLOC(newInst->msg, sizeof(MeaMessage));
    MEA_CALLOC(newInst->msg->msgProperties, sizeof(MeaPropItem));
    
    /* Set-up initial data */
    newInst->mode           = mrData->mode;
    newInst->msg->fileType  = mrData->fileType;
    newInst->msg->msgId     = mrData->msgId;
    newInst->fsm            = mrData->retFsm;
    newInst->signal         = (unsigned int)mrData->retSig;
    *inst = newInst;
    /* Display progress meter */
    (void)meaPmViewShow(MEA_STR_ID_READING_MSG, TRUE, FALSE, 0, 0);
    return TRUE;
}

/*!
 * \brief Deletes a MCR instance and sends a callback signal as a result of 
 *        the operation.
 *
 * \param inst          The current instance.
 * \param useCallback   TRUE if the result of the operations is sent the the 
 *                      originating FSM, otherwise FALSE.
 * \param result        The result of the operation.
 *****************************************************************************/
static void deleteMrInstance(MeaMrInstance **inst, MSF_BOOL useCallback, 
    MeaMrResult result)
{
    MeaMrInstance *current = *inst;
    /* Check that there is a valid instance to use */
    if ((inst != NULL) && (*inst != NULL))
    {
        /* Check if the SLS module needs to be stopped */
        if ((NULL != current->msg) && (MEA_MR_SMIL == current->msg->msgType))
        {
            /* Close down the SLS module */
            meaModuleStop(MSF_MODID_SLS, FALSE);
        }

        /* Send the response */
        if (useCallback)
        {
            if (MEA_MR_OK != result)
            {
                /* The operations has failed, send the response */
                (void)MEA_SIGNAL_SENDTO_U((*inst)->fsm, (int)(*inst)->signal, 
                    result);
            }
            else
            {
                /* Check if the message can be changed to SMIL */
                if ((MEA_MR_STARTUP_NORMAL == (*inst)->mode) && 
                    (current->msg->msgType != MEA_MR_SMIL) && 
                    (NULL != current->msg->smilInfo) && 
                    (NULL == current->msg->smilInfo->mediaObjects))
                {
                    meaInsertSlide(current->msg->smilInfo);
                    current->msg->msgType = MEA_MR_SMIL;
                }
                /* Everything went fine; send generated msg in signal */
                if ((MEA_MR_SMIL == current->msg->msgType) && 
                    (NULL != current->msg->smilInfo))
                {
                    (*inst)->msg->smilInfo->currentSlide = 
                        meaGetFirstSlide((*inst)->msg->smilInfo);
                } /* if */
                (void)MEA_SIGNAL_SENDTO_UUP((*inst)->fsm, 
                    (int)current->signal, result, 0 /* (*inst)->sizeWarning */,
                    (*inst)->msg);
                current->msg = NULL; /* won't be deleted, then */
            }
        } 

        /* Close the transaction */
        if (NULL != (*inst)->transaction)
        {
            (void)MMSlib_transactionClose(MSF_MODID_MEA, 
                &(current->transaction));
            current->transaction = NULL;
        }
        /* Close the message */
        if (NULL != current->msgHandle)
        {
            (void)MMSlib_messageClose(MSF_MODID_MEA, &(current->msgHandle));
            current->msgHandle = NULL;
        }

        /* Free header */
        if (NULL != (*inst)->msgHeader)
        {
            MMSlib_freeMmsGetHeader(MSF_MODID_MEA, (*inst)->msgHeader);
            MEA_FREE(current->msgHeader);
            current->msgHeader = NULL;
        }
        /* Async IO operations */
        if (NULL != current->textHandle)
        {
            meaAsyncOperationStop(&(current->textHandle));
            current->textHandle = NULL;
        }
        if (NULL != current->imageHandle)
        {
            meaAsyncOperationStop(&(current->imageHandle));
            current->imageHandle = NULL;
        }
        if (NULL != current->audioHandle)
        {
            meaAsyncOperationStop(&(current->audioHandle));
            current->audioHandle = NULL;
        }
        /* Check if the temp buffer needs to be deleted */
        if (NULL != current->current.buffer)
        {
            MEA_FREE(current->current.buffer);
            current->current.buffer = NULL;
        }
        meaFreeMessage(&current->msg);
        /* Delete the instance */
        MEA_FREE(current);
        current = NULL;
        *inst = NULL;
        /* Done */
        /* Delete progress meter */
        meaPmViewRemove();
    }
}

/*!
 * \brief Checks if a media object is a text
 * \param bi Information about the body-part containing the media object 
 * \return TRUE if the MO is just text, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL mrMoIsText(const MmsBodyInfoList *bi, int *charset)
{
    MmsAllParams *params;
    unsigned int tmpCharset;
    MeaMediaType meaType;

    if (NULL == bi->contentType)
    {
        return FALSE;
    }
    /*Check if the content type is of type text */
    if (MMS_VALUE_AS_STRING == bi->contentType->knownValue)
    {
        /* Get the corresponding MEA type */
        meaType = meaMime2MediaType((char *)bi->contentType->strValue);
    }
    else
    {
        /* Get the corresponding MEA type */
        meaType = meaMmsKnownValueToMea(bi->contentType->knownValue);
    }
    /* Check that this is a valid text type */
    if (MEA_MEDIA_GROUP_TEXT != meaMediaType2ObjType(meaType))
    {
        /* This is not a valid text type */
        return FALSE;
    }

    /* First, try to find a charset param */
    params = bi->contentType->params;                    
    while (params)
    {
        if ((MMS_CHARSET == params->param) &&
            (MMS_PARAM_INTEGER == params->type) &&
            (MSF_CHARSET_UNKNOWN != (tmpCharset = 
            meaIsValidCharset((MmsCharset)params->value.integer))))
        {
            /* We found a charset param! Must be text, then.. */
            *charset = (int)tmpCharset;
            return TRUE;
        }
        /* Keep on looping.. */
        params = params->next;        
    }

    /* If unsuccessful at finding charset, assume these are text anyway */
    *charset = MSF_CHARSET_UNKNOWN; //modify for utf16 MSF_CHARSET_ASCII;
    return TRUE;
}

/*!
 * \brief Checks if a message contains a SMIL presentation.
 * 
 * \param msgHeader A pointer to a valid message header.
 * \return TRUE if the message contains SMIL presentation, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL meaIsSmil(MmsGetHeader *msgHeader)
{
    MmsBodyInfoList *biList;

    if ((NULL != msgHeader) && 
        (NULL != msgHeader->bodyInfoList.contentType) /*&&
        (MMS_VND_WAP_MULTIPART_RELATED == 
        msgHeader->bodyInfoList.contentType->knownValue)*/)
    {
        biList = &msgHeader->bodyInfoList;
        /* Traverse all body-parts in hunt of a SMIL presentation */
        while (NULL != biList)
        {
            /* Check params for current body-part - is it a SMIL ? */
            if ((MMS_VALUE_AS_STRING == biList->contentType->knownValue) &&
                (NULL != biList->contentType->strValue) &&
                (0 == msf_cmmn_strcmp_nc((char *)biList->contentType->strValue, 
                MMS_MEDIA_TYPE_STRING_SMIL)))
            {
                return TRUE;
            }
            biList = biList->next;
        }
    }
    return FALSE;
}

/*!
 * \brief Finds out what type of message to edit.
 *
 * \param msgHeader The message header.
 * \return The type of message, see #MrMsgType.
 *****************************************************************************/
static MeaMessageType getMessageType(MmsGetHeader *msgHeader)
{
    /* Check for plain text */
    if (NULL != msgHeader)
    {
        if (0 == msgHeader->bodyInfoList.numOfEntries)
        {
            return MEA_MR_PLAIN_TEXT;
        }
        else if (meaIsSmil(msgHeader))
        {
            return MEA_MR_SMIL;
        }
        else if (MMS_VND_WAP_MULTIPART_MIXED == 
            msgHeader->bodyInfoList.contentType->knownValue ||
            MMS_VND_WAP_MULTIPART_RELATED == 
            msgHeader->bodyInfoList.contentType->knownValue)
        {
            return MEA_MR_MULTIPART_MIXED;
        }
        else if (MMS_VND_WAP_MULTIPART_ALTERNATIVE ==
            msgHeader->bodyInfoList.contentType->knownValue)
        {
            return MEA_MR_MULTIPART_ALTERNATIVE;
        }
    }
    return MEA_MR_UNSUPPORTED;
}

/*! \brief Extracts the content-type and parameters 
 *	
 * \param The MMS header.
 * \param The position of the body-part to get information about.
 * \return The content-type of the body-part or NULL if the operation fails.
 *****************************************************************************/
static MmsContentType *getBodyPartContentType(MmsGetHeader *header, 
    MSF_UINT32 pos)
{
    MmsContentType *contentType;
    MmsBodyInfoList *list = &(header->bodyInfoList);
    while(NULL != list)
    {
        /* Find the message part */
        if (list->startPos == pos)
        {
            MEA_CALLOC(contentType, sizeof(MmsContentType));
            meaCopyContentType(contentType, list->contentType);
            return contentType;
        }
        list = list->next;
    }
    return NULL;
}

#ifdef WAP_SUPPORT
/* set MoIsFound TRUE */
void meaSetMoIsFound(void)
{
    moIsFound = TRUE;
}

/*!
 * \brief Starts the MR FSM that will read a message from disk
 *
 * \param mode What mode to read message for (i.e. REPLY -> only read header)
 * \param msgID The msgId of the message to read
 * \param fileType The type of the message to read
 * \param retFsm The FSM to receive a signal when done
 * \param retSig The signal to receive when done
 *****************************************************************************/
void meaRestartMr(MeaMrStartupMode mode, MmsMsgId msgId, MmsFileType fileType, 
                 MeaStateMachine retFsm, unsigned int retSig)
{
    MeaMrStartData *mrData;

    MEA_CALLOC(mrData, sizeof(MeaMrStartData));
    mrData->fileType   = fileType;
    mrData->msgId      = msgId;
    mrData->mode       = mode;
    mrData->retFsm     = retFsm;
    mrData->retSig     = (int)retSig;
    (void)MEA_SIGNAL_SENDTO_P(MEA_MR_FSM, MEA_SIG_MR_RESTART, (void *)mrData);
}

static void meaReverseMediaObject(MeaMoDataItem **list)
{
    MeaMoDataItem *newStartMo = *list;
    MeaMoDataItem *currentStartMo = *list;
    int index=0;
    int i, j;
    while (newStartMo && newStartMo->next)
    {
        newStartMo = newStartMo->next;
        index++;
    }

    for (i=index; i>0; i--)
    {
        MeaMoDataItem *newNextMo = currentStartMo;
        for (j=0;j<i-1;j++)
        {
            newNextMo = newNextMo->next;
        }
        newNextMo->next->next = newNextMo;
    }
    *list = newStartMo;

    if (currentStartMo)
        currentStartMo->next = NULL;
}
#endif /* WAP_SUPPORT */

/*!
 * \brief Reads a media object from the message
 *
 * \param inst          The current "Message Reader" instance
 * \param slsMediaType  The type of SLS object to read
 * \param slsObjName    The name of the media object
 * \param objType       The type of object to read, see #MeaObjectType
 * \param offset        The file offset of the content to read 
 * \param size          The size of the content to read
 * \param handle        The handle of the async operation
 *
 * \return TRUE if successful, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL readMessagePart(const MeaMrInstance *mrInst, 
    SlsMediaType slsMediaType, char *slsObjName, MeaMediaGroupType objType, 
    long offset, unsigned int size, MeaAsyncOperationHandle *handle)
{
    unsigned char *buffer;
    MeaMoDataItem *mo;
    char *bpName;
    MeaMediaType mediaType;
    MmsContentType *contentType = NULL;

    mediaType = meaSlsMediaTypeToMea(slsMediaType);
    contentType = getBodyPartContentType(mrInst->msgHeader, (unsigned long)offset);

    /* Allocate memory for the media object */
    if (MEA_MEDIA_GROUP_TEXT == objType)
    {
#ifndef  MEA_CFG_USER_TEMPLATE_SUPPORT
#if (defined(MMS_TMPLATES_MULTIPLE_LANG_SUPPORT)) && (defined(__MMI_MMS_TEMPLATES_NUM__))
		if (1 <= meaMMCGetCurrentActiveMsg() && meaMMCGetCurrentActiveMsg() <=__MMI_MMS_TEMPLATES_NUM__)
		{
			char *Ptr = NULL;
			unsigned char *mediaPtr = NULL;	
			int mediaSize = 0;
			Ptr = GetString((MSF_UINT16)(meaMMCGetCurrentActiveMsg()+MMS_STR_ID_TEMPLATES_TITLE_01-1));
			if (!Ptr) 
			{
				return FALSE;
			}
			else
			{
				mediaSize = widget_ucs2_length((kal_uint8*)Ptr)*2;
				MEA_CALLOC(mediaPtr,mediaSize+2);
				if (!mediaPtr)
				{				
					return FALSE;
				}
				memset(mediaPtr, 0x00, mediaSize+2);
				memcpy(mediaPtr, Ptr, mediaSize+1);
				mediaSize = widget_ucs2_to_utf8_length_in_bytes((kal_uint8*)mediaPtr);
				MEA_CALLOC(Ptr,mediaSize+1);
				if (Ptr)
				{
					widget_ucs2_to_utf8_string((kal_uint8*)Ptr, mediaSize+1, (kal_uint8*)mediaPtr);
				}
				else
				{
					MEA_FREE(mediaPtr);
					return FALSE;
				}
				MEA_FREE(mediaPtr);
				buffer = (unsigned char *)Ptr;
				size = mediaSize+1;
			}
		}
        else
        {
            MEA_CALLOC(buffer, size + 1);  /* Allocate extra NULL-termination byte */
        }
#else
        MEA_CALLOC(buffer, size + 1);  /* Allocate extra NULL-termination byte */
#endif /* defined(MMS_TMPLATES_MULTIPLE_LANG_SUPPORT) && defined(__MMI_MMS_TEMPLATES_NUM__) */

#else /* MEA_CFG_USER_TEMPLATE_SUPPORT*/
        MEA_CALLOC(buffer, size + 1);  /* Allocate extra NULL-termination byte */

#endif /* MEA_CFG_USER_TEMPLATE_SUPPORT*/

    }
    else
    {
        buffer = NULL;
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
#endif

    /* Check if the filename is provided */
    if (NULL != slsObjName)
    {
        bpName = msf_cmmn_strdup(MSF_MODID_MEA, slsObjName);
        /* Fault tolerance: use filename rather than content type to get mediaType */
        if (mediaType == MEA_MEDIA_TYPE_UNKNOWN)
        {
            mediaType = meaMime2MediaType(meaFileName2MimeType(bpName));
        }
    }
    else if (NULL == (bpName = meaCreateFileNameFromType(mediaType)))
    {
        /*lint -e{774} */
        MEA_FREE(buffer);
        return FALSE;
    }
#ifdef WAP_SUPPORT
    moIsFound = FALSE;
#endif
#ifdef __DRM_SUPPORT__ 
    if (NULL == (mo = meaSetSlideMo(mrInst->msg->smilInfo, mediaType, MEA_MEDIA_TYPE_UNKNOWN, contentType, 
                                    buffer, size, bpName, 0)))
#else
    if (NULL == (mo = meaSetSlideMo(mrInst->msg->smilInfo, mediaType, contentType, buffer, size, bpName, 0)))
#endif
    {
        /*lint -e{774} */
        MEA_FREE(buffer);
        return FALSE;
    }
#ifdef WAP_SUPPORT
    if (moIsFound)
        return TRUE;
#endif /* WAP_SUPPORT */

    if (MEA_MEDIA_GROUP_TEXT == objType)
    {
        mo->isRestricted = TRUE;
        /* Start the read operation */
        if (NULL == (*handle = meaAsyncOperationStart(mrInst->msg->fileName, 
        	MEA_MR_FSM, objType, MEA_SIG_MR_MO_READ, MEA_ASYNC_MODE_READ)))
	    {
       	    MEA_FREE(mo->data);
	        mo->data = NULL;
       	    mo->size = 0;
	        return FALSE;
	    }       
        
#ifndef  MEA_CFG_USER_TEMPLATE_SUPPORT

#if (defined(MMS_TMPLATES_MULTIPLE_LANG_SUPPORT)) && (defined(__MMI_MMS_TEMPLATES_NUM__))
	    if ((MEA_MEDIA_GROUP_TEXT == objType) && (1<=meaMMCGetCurrentActiveMsg() && meaMMCGetCurrentActiveMsg()<=__MMI_MMS_TEMPLATES_NUM__))
		{
			MEA_SIGNAL_SENDTO_IU(MEA_MR_FSM, MEA_SIG_MR_MO_READ, MEA_MEDIA_GROUP_TEXT, MEA_ASIO_RESULT_OK);
			return TRUE;
		}
	    else
#endif

#endif /* MEA_CFG_USER_TEMPLATE_SUPPORT*/
        meaAsyncRead(*handle, (long)offset, mo->data, size);  /* Read the content */
    }
    else
    {
        mo->acessType=meaMoInPartOfFile;
        if(mo->file)
        {
            if(mo->file->path)
                MEA_CFREE(mo->file->path);
            MEA_CFREE(mo->file);
        }
        MEA_CALLOC(mo->file,sizeof(MeaMoFileRef));
        ASSERT(mo->file != NULL);
        MEA_CALLOC(mo->file->path,strlen(mrInst->msg->fileName)+1);
        ASSERT(mo->file->path != NULL);
        strcpy(mo->file->path,mrInst->msg->fileName);
        mo->file->pos=offset;
        mo->file->size=size;
        mo->isRestricted = meaIsRestrictedTypeVF(mo->file->path, mo->content.type, mo->file->pos, mo->file->size);

#ifndef __UNIFIED_COMPOSER_SUPPORT__
#ifdef __DRM_SUPPORT__
        if (MEA_MEDIA_TYPE_DRM_CONTENT == mediaType)
        {
            if (MEA_MEDIA_GROUP_IMAGE == objType  || MEA_MEDIA_GROUP_VIDEO == objType || MEA_MEDIA_GROUP_AUDIO == objType)
            {
                MmsMsgId msgId = meaMMCGetCurrentActiveMsg();
                mo->file->filehandle = MSF_FILE_OPEN(MSF_MODID_MEA, mo->file->path, MSF_FILE_SET_RDONLY, 0);
                mo->reshandle = meaCreateDrmVirtualFileResource(MEA_MEDIA_TYPE_DRM_CONTENT, mo->file->path, offset, size, msgId, mo->file->filehandle, &mo->content.drmType);
                if(mo->reshandle > 0)
                {
                    moReadMessagePart = mo;  /* wait for widget creating mo */
                }
                else
                {
                    if(MEA_MEDIA_GROUP_IMAGE == objType  || MEA_MEDIA_GROUP_VIDEO == objType)
                    {
                        mo->reshandle = (MEA_MEDIA_GROUP_IMAGE == objType) ? MEA_GET_IMG_ID(MEA_IMG_IMAGE_ERROR) : MEA_GET_IMG_ID(MEA_IMG_VIDEO_ERROR);
                    }
                }
            }
            else
            {
                MEA_SIGNAL_SENDTO_U(MEA_MR_FSM, MEA_SIG_MR_MO_READ, MEA_ASIO_RESULT_OK);
            }
        }
        else
#endif /* __DRM_SUPPORT__ */
        {
            if (MEA_MEDIA_GROUP_IMAGE == objType || MEA_MEDIA_GROUP_VIDEO == objType)
            {
                mo->reshandle = meaCreateVirtualFileResource(mediaType, mo->file->path, offset, size);
                if(mo->reshandle > 0)
                {
                    moReadMessagePart = mo;  /* wait for widget creating mo */
                }
                else
                {
                    return FALSE;
                }
            }
            else if (!mrInstance->textHandle) //audio type. if has text object
            {
                MEA_SIGNAL_SENDTO_U(MEA_MR_FSM,MEA_SIG_MR_MO_READ,MEA_ASIO_RESULT_OK);
            }    	
        }
#endif  /* __UNIFIED_COMPOSER_SUPPORT__ */
    }
    return TRUE;
}

/*!
 * \brief Check that the addresses used can be handled.
 *
 * \param list The list of messages.
 * \return TRUE if all address types can be handled, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL validateAddresses(const MmsAddressList *list)
{
    while(NULL != list)
    {
        if ((MMS_PLMN != list->current.addrType) && 
            (MMS_EMAIL != list->current.addrType) &&
            (MMS_IPV4 != list->current.addrType))
        {
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                MAMR_E394246E5FA2FB4BCFF281859A8D6DFF, "(%s) (%d) Unsupported address type: %d!\n", __FILE__, 
                __LINE__,list->current.addrType));
            return FALSE;
        }
        list = list->next;
    }
    return TRUE;
}

/*!
 * \brief Gets the message property "Expiry Time" from the message header.
 *
 * \param inst The current instance.
 *****************************************************************************/
static void getMsgPropertiesExpiryTime(const MeaMrInstance *inst)
{
    MeaPropItem *propItem;
    long diff;

    propItem = inst->msg->msgProperties;

#ifdef WAP_SUPPORT
    if ((MEA_MR_STARTUP_FORWARD == inst->mode) ||
        (MEA_MR_STARTUP_REPLY      == inst->mode) ||
        (MEA_MR_STARTUP_REPLY_ALL  == inst->mode)|| 
        (meaGetCurrentFolder() == MEA_FOLDER_TEMPLATE))
    {
        propItem->expiryTime = meaGetConfig()->expiryTime;
        return;
    }
#endif /* WAP_SUPPORT */
    if (MMS_TIME_ABSOLUTE == inst->msgHeader->expiryTimeType)
    {
        diff = (long)(inst->msgHeader->expiryTime - inst->msgHeader->date);
    }
    else if(MMS_TIME_RELATIVE == inst->msgHeader->expiryTimeType)
    {
        diff = (long)inst->msgHeader->expiryTime;        
    }
    else  /* ex. The field is absent: inst->msgHeader->expiryTimeType = 0 */
    {
        propItem->expiryTime = MEA_EXPIRY_MAX;
        return;
    }

    /*  Only positive values please */
    if (diff < 0)
    {
        diff = -diff;
    }
    
    if (diff <= MEA_EXPIRY_1_HOUR_IN_SEC)
    {
        propItem->expiryTime = MEA_EXPIRY_1_HOUR;
    }
    else if (diff > MEA_EXPIRY_1_HOUR_IN_SEC && 
        diff <= MEA_EXPIRY_12_HOURS_IN_SEC) 
    {
        propItem->expiryTime = MEA_EXPIRY_12_HOURS;
    }
    else if (diff > MEA_EXPIRY_12_HOURS_IN_SEC && 
        diff <= MEA_EXPIRY_1_DAY_IN_SEC) 
    {
        propItem->expiryTime = MEA_EXPIRY_1_DAY;
    }
    else if (diff > MEA_EXPIRY_1_DAY_IN_SEC && 
        diff <= MEA_EXPIRY_1_WEEK_IN_SEC) 
    {
        propItem->expiryTime = MEA_EXPIRY_1_WEEK;
    }
    else
    {
        propItem->expiryTime = MEA_EXPIRY_MAX;
    }
}

/*!
 * \brief Copy reply charging properties into the proper fields from the
 *        message header.
 * \param inst The current instance.
 *****************************************************************************/
static void getMsgPropertiesReplyCharging(const MeaMrInstance *inst)
{
    MeaPropItem *propItem;

    if (!inst || !inst->msg || !inst->msg->msgProperties || !inst->msgHeader)
    {
        return;
    }

    if (((MEA_MR_STARTUP_REPLY == inst->mode) || 
        (MEA_MR_STARTUP_REPLY_ALL == inst->mode)) && 
        ((inst->msgHeader->replyCharging == MMS_REPLY_CHARGING_ACCEPTED)) ||
        ((inst->msgHeader->replyCharging == MMS_REPLY_CHARGING_ACCEPTED_TEXT_ONLY)))
    {
        /* If the forward mode is used then the message id is needed in order
           to get a reply for free */
        if (NULL != inst->msgHeader->serverMessageId)
        {
            propItem = inst->msg->msgProperties;
            propItem->replyChargingId = MEA_ALLOC(strlen(
                inst->msgHeader->serverMessageId) + 1);
            strcpy(propItem->replyChargingId, inst->msgHeader->serverMessageId);
        }
    }
    else
    {
        /* If the the operation is not a reply operation then the reply charging
           information needs to be copied */
        /* Reply charging */
#ifdef WAP_SUPPORT
        MeaConfig *config = meaGetConfig();
        propItem = inst->msg->msgProperties;
        if ((MEA_MR_STARTUP_FORWARD == inst->mode) ||
            (MEA_MR_STARTUP_REPLY      == inst->mode) ||
            (MEA_MR_STARTUP_REPLY_ALL  == inst->mode)|| 
            (meaGetCurrentFolder() == MEA_FOLDER_TEMPLATE))
        {
            propItem->replyCharging         = config->replyCharging;
            propItem->replyChargingDeadline = config->replyChargingDeadline;
            propItem->replyChargingSize     = config->replyChargingSize;
        }
        else
        {
#endif /* WAP_SUPPORT */
        switch(inst->msgHeader->replyCharging)
        {
        case MMS_REPLY_CHARGING_NOT_SET:
            inst->msg->msgProperties->replyCharging = MEA_REPLY_CHARGING_OFF;
            break;

        case MMS_REPLY_CHARGING_REQUESTED:
            inst->msg->msgProperties->replyCharging = MEA_REPLY_CHARGING_ON;
            break;

        case MMS_REPLY_CHARGING_REQUESTED_TEXT_ONLY:
            inst->msg->msgProperties->replyCharging = MEA_REPLY_CHARGING_TEXT_ONLY;
            break;

        case MMS_REPLY_CHARGING_ACCEPTED:
        case MMS_REPLY_CHARGING_ACCEPTED_TEXT_ONLY:
        default:
            inst->msg->msgProperties->replyCharging = 
                meaGetConfig()->replyCharging;
            break;
        }
        /* Get the default configuration for size on deadline if the reply 
           charging is used */
        if ((inst->msgHeader->messageType == MMS_MSG_TYPE_SEND_REQ) && 
            (inst->msg->msgProperties->replyCharging != MEA_REPLY_CHARGING_OFF))
        {
            /* Calculate the time */
            if (0 == inst->msgHeader->replyChargingDeadline)
            {
                inst->msg->msgProperties->replyChargingDeadline = MEA_REPLY_CHARGING_DEADLINE_MAX;
            }
            else if (inst->msgHeader->replyChargingDeadline <= MEA_1_DAY)
            {
                inst->msg->msgProperties->replyChargingDeadline = MEA_REPLY_CHARGING_DEADLINE_1_DAY;
            }
            else if (inst->msgHeader->replyChargingDeadline <= MEA_1_WEEK)
            {
                inst->msg->msgProperties->replyChargingDeadline = MEA_REPLY_CHARGING_DEADLINE_1_WEEK;
            }
            else
            {
                inst->msg->msgProperties->replyChargingDeadline = MEA_REPLY_CHARGING_DEADLINE_MAX;
            }
            /* Calulate the size */
            if (0 == inst->msgHeader->replyChargingSize)
            {
                inst->msg->msgProperties->replyChargingSize = MEA_REPLY_CHARGING_SIZE_MAX;
            }
            else if (inst->msgHeader->replyChargingSize <= MEA_1_KB)
            {
                inst->msg->msgProperties->replyChargingSize = MEA_REPLY_CHARGING_SIZE_1_KB;
            }
            else if (inst->msgHeader->replyChargingSize <= MEA_10_KB)
            {
                inst->msg->msgProperties->replyChargingSize = MEA_REPLY_CHARGING_SIZE_10_KB;
            }
            else
            {
                inst->msg->msgProperties->replyChargingSize = MEA_REPLY_CHARGING_SIZE_MAX;
            }
        }
#ifdef WAP_SUPPORT
        }
#endif /* WAP_SUPPORT */
    }
} 

/*!
 * \brief Gets the message property "Subject" from the message header.
 *
 * \param inst The current instance.
 *****************************************************************************/
static void getMsgPropertiesSubject(const MeaMrInstance *inst)
{
    MeaPropItem *propItem;
    char *str1;
    char *str2;
    MSF_UINT32 prefixLength;
    MSF_UINT32 oldSubjectLength; 
    MSF_UINT32 newSubjectLength; 
    MSF_UINT32 newSubjectSize;

    propItem = inst->msg->msgProperties;    

#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
    /* Save as template use forward mode but FW: should not be added here*/
    if ((MEA_MR_STARTUP_REPLY == inst->mode ||
        MEA_MR_STARTUP_REPLY_ALL == inst->mode || 
        MEA_MR_STARTUP_FORWARD == inst->mode) &&
        !meaMeIsSaveAsTemplateMode()) 
#else
    if (MEA_MR_STARTUP_REPLY == inst->mode ||
        MEA_MR_STARTUP_REPLY_ALL == inst->mode || 
        MEA_MR_STARTUP_FORWARD == inst->mode) 
#endif
    {
        /* "RE: " or "FW: " should prefix subject */
        str1 = meaGetStringFromHandle(MEA_MR_STARTUP_FORWARD == inst->mode
            ? MEA_GET_STR_ID(MEA_STR_ID_FW)         
            : MEA_GET_STR_ID(MEA_STR_ID_RE));        

        if (inst->msgHeader->subject.text != NULL)
        {            
            prefixLength = (MSF_UINT32)msf_cmmn_utf8_strlen(str1);
            oldSubjectLength = (MSF_UINT32)msf_cmmn_utf8_strlen(
                inst->msgHeader->subject.text);

            /* must limit new subject to MEA_ME_SUBJECT_MAX_SIZE characters */
            if (oldSubjectLength > MEA_MAX_SUBJECT_LENGTH - prefixLength)
            {
                newSubjectLength = MEA_MAX_SUBJECT_LENGTH - prefixLength;
            }
            else
            {
                newSubjectLength = oldSubjectLength;
            }            
               
            /* msf_cmmn_strndup() is not UTF8 aware, need to count bytes... 
             * Compare difference between the original string length and the 
             * and the limited string.
             */
            newSubjectSize = (MSF_UINT32)(msf_cmmn_utf8_str_incr(
                inst->msgHeader->subject.text, (int)newSubjectLength)
                - inst->msgHeader->subject.text);

            str2 = msf_cmmn_strndup(MSF_MODID_MEA, 
                inst->msgHeader->subject.text, (int)newSubjectSize);
            propItem->subject = msf_cmmn_str3cat(MSF_MODID_MEA, str1, str2, NULL);
            
            MEA_FREE(str1);       
            MEA_FREE(str2);
#ifdef WAP_SUPPORT
  #if 0  /* although Spec. means 40 US-ASCII chars, we do it as how reference phones do it -- 40 UTF8 chars */
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
#endif /* WAP_SUPPORT */
        }
        else
        {
            propItem->subject = str1;
        }
    }
    else
    {
        if ((NULL != inst->msgHeader->subject.text) && 
            (MMS_UTF8 == inst->msgHeader->subject.charset))
        {
            propItem->subject = MEA_ALLOC(
                strlen(inst->msgHeader->subject.text) + 1);
            strcpy(propItem->subject, inst->msgHeader->subject.text);
        }
    }
}

/*!
 * \brief Gets the message property "To" from the message header.
 *
 * \param inst The current instance.
 * \return TRUE on successful operation, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL getMsgPropAddresses(const MeaMrInstance *inst)
{
    MeaPropItem *propItem;

    propItem = inst->msg->msgProperties;

    if (MEA_MR_STARTUP_VIEW == inst->mode) 
    {
        /* in view mode there is no need to validate the addresses; show all */
        /* Copy all addresses */
        propItem->to = meaMmsToAddrList(inst->msgHeader->to, NULL);
        /* Verify From addresses */
        if (inst->msgHeader->from.address)
        {
            if (!meaAddrItemInsert(&(propItem->from), NULL, 
                meaMmsAddrTypeToMea(inst->msgHeader->from.addrType),
                inst->msgHeader->from.address))
            {
                return FALSE;
            }
        }
        /* Copy all addresses */
        propItem->cc = meaMmsToAddrList(inst->msgHeader->cc, NULL);

        if(inst->msg->fileType == MMS_SUFFIX_SEND_REQ)
        {
            propItem->bcc = meaMmsToAddrList(inst->msgHeader->bcc, NULL);
        }
    } 
    else if (MEA_MR_STARTUP_NORMAL == inst->mode) 
    {
        /* Verify To addresses */
        if (!validateAddresses(inst->msgHeader->to))
        {
            return FALSE;
        }
        /* Copy all addresses */
        propItem->to = meaMmsToAddrList(inst->msgHeader->to, NULL);
        /* Verify Cc addresses */
        if (!validateAddresses(inst->msgHeader->cc))
        {
            return FALSE;
        }
        /* Copy all addresses */
        propItem->cc = meaMmsToAddrList(inst->msgHeader->cc, NULL);
        /* Bcc addresses */
        if (inst->msg->fileType == MMS_SUFFIX_SEND_REQ)
        {
            if (!validateAddresses(inst->msgHeader->bcc))
            {
                return FALSE;
            }
            /* Copy all addresses */
            propItem->bcc = meaMmsToAddrList(inst->msgHeader->bcc, NULL);
        }
    }
    else if (MEA_MR_STARTUP_REPLY_ALL == inst->mode) 
    {
        /*
         *	REPLY_ALL algorithm: 
         *  1) copy CC and TO from the original message, excluding myself
         *  2) insert FROM-address of the original message into the TO header
         */

        /* Verify to addresses */
        if (!validateAddresses(inst->msgHeader->to))
        {
            return FALSE;
        }
        /* Copy all addresses except our own address */
#ifdef WAP_SUPPORT
        propItem->to = meaMmsToAddrList(inst->msgHeader->to, 
            inst->msgHeader->from.address);
        propItem->cc = meaMmsToAddrList(inst->msgHeader->cc, 
            NULL);
#else
        propItem->to = meaMmsToAddrList(inst->msgHeader->to, 
            meaGetConfig()->fromAddress);
        propItem->cc = meaMmsToAddrList(inst->msgHeader->cc, 
            NULL);
#endif /* WAP_SUPPORT */
    }
    
    if (MEA_MR_STARTUP_REPLY == inst->mode ||
        MEA_MR_STARTUP_REPLY_ALL == inst->mode) 
    {
        /* Copy from-address to to-address */
        if (inst->msgHeader->from.address)
        {
            if (!meaAddrItemInsert(&(propItem->to), NULL, 
                meaMmsAddrTypeToMea(inst->msgHeader->from.addrType),
                inst->msgHeader->from.address))
            {
                MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                    MAMR_7D8140206ED856E7D41E18792D77EB62, "(%s) (%d) from address missing in originating message.\n", 
                    __FILE__, __LINE__));
                return FALSE;
            }
        }
    }
    return TRUE;
}

/*!
 * \brief Gets the message properties from the message header. Also analyzes
 *        the header. 
 *
 * \param inst The current instance.
 * \return TRUE on successful operation, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL mrParseHeader(MeaMrInstance *inst)
{
    MeaPropItem *propItem;

    propItem = inst->msg->msgProperties;

    if (NULL == inst->msgHeader->bodyInfoList.contentType)
    {
        return FALSE;
    }

#ifndef  MEA_CFG_USER_TEMPLATE_SUPPORT
#if (defined(MMS_TMPLATES_MULTIPLE_LANG_SUPPORT)) && (defined(__MMI_MMS_TEMPLATES_NUM__))
	if(1<=meaMMCGetCurrentActiveMsg() && meaMMCGetCurrentActiveMsg()<=__MMI_MMS_TEMPLATES_NUM__)
	{
		char *Ptr = NULL;
		unsigned char *mediaPtr = NULL;	
		int mediaSize=0;
		Ptr = GetString((MSF_UINT16)(meaMMCGetCurrentActiveMsg() + MMS_STR_ID_TEMPLATES_TITLE_01 - 1));
		if(!Ptr) 
		{
			return FALSE;
		}
		else
		{

			mediaSize=widget_ucs2_length((kal_uint8*)Ptr)*2;
			MEA_CALLOC(mediaPtr,mediaSize+2);
			if(!mediaPtr)
			{				
				return FALSE;
			}
			memset(mediaPtr,0x00,mediaSize+2);
			memcpy(mediaPtr,Ptr,mediaSize+1);
			mediaSize=widget_ucs2_to_utf8_length_in_bytes((kal_uint8*)mediaPtr);
			MEA_CALLOC(Ptr,mediaSize+1);
			if(Ptr)
				widget_ucs2_to_utf8_string((kal_uint8*)Ptr,mediaSize+1,(kal_uint8*)mediaPtr);
			else
			{
				MEA_FREE(mediaPtr);
				return FALSE;
			}
			{
				int i=strlen(Ptr);
				int j;				
				for(j=0;j<i;j++)
				{
					if(*(Ptr+j)&0x80)
					{
						inst->msgHeader->subject.charset=MMS_UTF8;
						break;
					}
				}
			}
			MEA_FREE(mediaPtr);
			if(inst->msgHeader->subject.text!=NULL)
				MEA_FREE(inst->msgHeader->subject.text);
			inst->msgHeader->subject.text=Ptr;		
		}
	
	}
#endif /* defined(MMS_TMPLATES_MULTIPLE_LANG_SUPPORT) && defined(__MMI_MMS_TEMPLATES_NUM__) */
#endif /* MEA_CFG_USER_TEMPLATE_SUPPORT*/

    inst->msg->msgType = getMessageType(mrInstance->msgHeader);
    
    /* Sometimes only the header is needed.. (fwd, re, re all, view smil) */
    inst->onlyHeader =
        (
#ifndef WAP_SUPPORT  /* Need to parse content before forwarding */
        (MEA_MR_STARTUP_FORWARD   == mrInstance->mode) ||
#endif
        (MEA_MR_STARTUP_REPLY      == mrInstance->mode) ||
        (MEA_MR_STARTUP_REPLY_ALL  == mrInstance->mode) ||
        ((MEA_MR_STARTUP_VIEW      == mrInstance->mode) 
        && (MEA_MR_SMIL            == mrInstance->msg->msgType))); 

    /* Handle addresses */
    if (!getMsgPropAddresses(inst))
    {
        return FALSE;
    }

    if (MEA_MR_STARTUP_REPLY == inst->mode ||
        MEA_MR_STARTUP_REPLY_ALL == inst->mode ||
        MEA_MR_STARTUP_FORWARD == inst->mode || 
		(MEA_MR_STARTUP_NORMAL == inst->mode && meaGetCurrentFolder() == MEA_FOLDER_INBOX) ||
        (meaGetCurrentFolder() == MEA_FOLDER_TEMPLATE))
    {
                
        MeaConfig *config;
        config = meaGetConfig();
        propItem->deliveryReport        = config->deliveryReport;
        propItem->readReport            = config->readReport;
        propItem->senderVisibility      = config->senderVisibility;
        propItem->priority              = config->priority;
    }
    else
    {
        
	    propItem->deliveryReport = (MMS_DELIVERY_REPORT_YES == 
	        inst->msgHeader->deliveryReport);
	    propItem->readReport = (MMS_READ_REPLY_YES == inst->msgHeader->readReply);

        switch(inst->msgHeader->priority) 
        {
        case MMS_PRIORITY_LOW:
            propItem->priority = MEA_PRIORITY_LOW;
            break;
        case MMS_PRIORITY_NORMAL:
            propItem->priority = MEA_PRIORITY_NORMAL;
            break;
        case MMS_PRIORITY_HIGH:
            propItem->priority = MEA_PRIORITY_HIGH;        
            break;
        default:
            /* If not set, use the default value */
            propItem->priority = meaGetConfig()->priority;
        /*lint -e{788} */
        }
    
        switch(inst->msgHeader->visibility)
        {
        case MMS_SENDER_HIDE:
            propItem->senderVisibility = MEA_SENDER_HIDE;
            break;
        case MMS_SENDER_SHOW:
        case MMS_SENDER_VISIBILITY_NOT_SET:
        default:
            /* If not set, use the default value */
            propItem->senderVisibility = meaGetConfig()->senderVisibility;
            break;
        }
#ifdef WAP_SUPPORT
    }
#endif /* WAP_SUPPORT */
           
    /*  Copy reply charging data to the proper fields */
    getMsgPropertiesReplyCharging(inst);

    /*  Get expiry time type and value */
    getMsgPropertiesExpiryTime(inst);

    /* subject */
    getMsgPropertiesSubject(inst);

    /* Dispose of retrieved header - it isn't needed anymore. */
    return TRUE;
}

/*!
 * \brief Handles reading of a message header. Deletes instance on error.
 *
 * \param retFsm What FSM to call when encountering delayed reads
 * \param retSig The signal to send on delayed reads
 * \return TRUE on successful and completed read, FALSE otherwise
 *****************************************************************************/
static MSF_BOOL mrReadHeader(MeaStateMachine retFsm, int retSig)
{
    MmsResult res;
    MSF_BOOL  ret;

    /*
     *	Init things on first arrival here (might get here several times due 
     *  to async file API ..) On second coming, we will have a transaction
     */
    if (NULL == mrInstance->transaction) 
    {
        MEA_CALLOC(mrInstance->msgHeader, sizeof(MmsGetHeader));
        if ((MMS_RESULT_OK != MMSlib_messageOpen(MSF_MODID_MEA, 
            mrInstance->msg->msgId, mrInstance->msg->fileType, 
            &mrInstance->msgHandle)) ||
            (MMS_RESULT_OK != MMSlib_transactionOpen(MSF_MODID_MEA, 
            &(mrInstance->transaction))))
        {
            deleteMrInstance(&mrInstance, TRUE, MEA_MR_FAILED);
            return FALSE;
        } /* if */
    } /* if */

    /* Try to read the message header */
    res = MMSlib_getMessageHeader(MSF_MODID_MEA, mrInstance->msgHeader, 
        &mrInstance->msgHandle, &mrInstance->transaction);        
    if (MMS_RESULT_DELAYED == res) 
    { /* B'oh .. async. */
        meaAsyncRegister(MMSlib_getFileHandle(MSF_MODID_MEA, 
            &(mrInstance->transaction)), retFsm, retSig, 0);
        return FALSE;
    } 
    else if (MMS_RESULT_OK != res)
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
            MAMR_0061C98DF6DA82B5833195C07ED75D52, "(%s) (%d) failed to open message header!\n", __FILE__, __LINE__));
        deleteMrInstance(&mrInstance, TRUE, MEA_MR_FAILED);
        return FALSE;
    }

    /* getting here means we got the header ok; close the transaction! */
    ret = (MMS_RESULT_OK == MMSlib_transactionClose(MSF_MODID_MEA, 
        &mrInstance->transaction));
    mrInstance->transaction = NULL;

    /* Then parse and analyze the retrieved header */
    if (ret) 
    {
        /* Do not allow edit of forward locked PDU's */
        if ((mrInstance->msgHeader->forwardLock) && 
            (mrInstance->mode == MEA_MR_STARTUP_FORWARD || mrInstance->mode == MEA_MR_STARTUP_NORMAL))
        {
            deleteMrInstance(&mrInstance, TRUE, MEA_MR_FORWARD_LOCK);
            return FALSE;
        }

        if (mrParseHeader(mrInstance) != TRUE)
        {
            deleteMrInstance(&mrInstance, TRUE, MEA_MR_UNSUPPORTED_HEADER_FIELDS);
            return FALSE;
        }

        return TRUE;
    }
    else
    {
        deleteMrInstance(&mrInstance, TRUE, MEA_MR_FAILED);
        return FALSE;
    }
}

/*! \brief Checks whether the content-type of the current body-part is known
 *         by the MEA or not.
 *
 * \return TRUE if the content type is known and can be handled, otherwise 
 *         FALSE.
 *****************************************************************************/
static MSF_BOOL handleContentType(const MmsContentType *contentType, const char **mime)
{
    *mime = NULL;
    /* Handle the string alternative  */
    if (MMS_VALUE_AS_STRING == contentType->knownValue)
    {
        /* Convert to MEA type */
        if (NULL == (*mime = (char *)contentType->strValue))
        {
            return FALSE;
        }
    }
    else
    {
        /* This is the currently assigned value */
        /* Check if the media type is present in the handled media objects */
        if (NULL == (*mime = meaKnownValueToMimeType(contentType->knownValue)))
        {
            return FALSE;
        }
    }
    return TRUE;
}

#ifdef __MMI_CHSET_GB2312__

#define MEA_GB2312 2025

static MSF_UINT32 meaAdjustCharset(unsigned char *buffer, MSF_UINT32 length)
{
    MSF_UINT32 numUTF8 = 0, numGB = 0;
    MSF_BOOL isUTF8 = FALSE;
    
    while (length > 0)
    {
        isUTF8 = FALSE;
        if(*buffer > 80)
        {
            if((*buffer & 0xF0) == 0xE0)
            {
                if((length >= 3) && ((*(buffer + 1) & 0xC0) == 0x80)
                    && ((*(buffer + 2) & 0xC0) == 0x80))
                {
                    numUTF8 ++;
                    buffer += 3;
                    length -= 3;
                    isUTF8 = TRUE;
                }
            }
            else if ((*buffer & 0xE0) == 0xC0)
            {
                if((length >= 2) && ((*(buffer + 1) & 0xC0) == 0x80))
                {
                    numUTF8 ++;
                    buffer += 2;
                    length -= 2;
                    isUTF8 = TRUE;
                }
            }
            if(!isUTF8)
            {
                if((length >= 2) && (*buffer >= 0xA0) && (*buffer <= 0xFE)
                    && ((*(buffer + 1)) >= 0xA0) && ((*(buffer + 1)) <= 0xFE))
                {
                    numGB ++;
                    buffer += 2;
                    length -= 2;
                }
                else
                {
                    buffer++;
                    length--;
                }
            }
        }
        else
        {
            buffer++;
            length--;
        }
    }
    
    if(numUTF8 >= numGB)
        return MSF_CHARSET_UTF_8;
    else
        return MEA_GB2312;
}
#endif

/*!
 * \brief Handles reading of a single body-part 
 *
 * \param retFsm What FSM to call when encountering delayed reads
 * \param retSig The signal to send on delayed reads
 * \param number the body-part to read
 * \param data   Where to store the read body-part
 * \param size   Where to write the size of the read data
 * \return TRUE on successful and completed read, FALSE otherwise
 *****************************************************************************/
static MSF_BOOL mrReadBodyPart(MeaMrInstance *inst, MeaStateMachine retFsm, 
    int retSig)
{
    MmsResult       res;
    MSF_UINT32      size;
    MeaMediaType    mType;
    const char      *mime;
    char            *name;
    int             charset;
    MmsContentType  *mmsType = NULL;
    MeaMoDataItem *mo = NULL;
    MeaMediaGroupType gType;
    /*
     *	Init things on first arrival here (might get here several times due 
     *  to async file API ..) On second coming, we will have a transaction
     */
    if ((NULL == mrInstance) || (NULL == inst->current.bodyPart))
    {
        deleteMrInstance(&mrInstance, TRUE, MEA_MR_FAILED);
        return FALSE;
    }
    if (NULL == mrInstance->transaction)
    {
        if (MMS_RESULT_OK != MMSlib_transactionOpen(MSF_MODID_MEA, 
            &mrInstance->transaction))
        {
            deleteMrInstance(&mrInstance, TRUE, MEA_MR_FAILED);
            return FALSE;
        }
    }

    /* Try to read the requested body-part */
    size = inst->current.bodyPart->size;
#ifdef WAP_SUPPORT //interoperability issue
    if (size == 0)
    {
        res = MMS_RESULT_OK;
    }
#endif
    else if (mrMoIsText(inst->current.bodyPart, &charset))
    {
        /* Some MIXED messages from tools(NowSMS) may have large text, 
           so large that no enough memory to make internal error.
           So discard here.*/
        if (size > MEA_CFG_MIXED_TEXT_MAX_READ_SIZE - 1)
        {
            size = MEA_CFG_MIXED_TEXT_MAX_READ_SIZE - 1;
        }

        if (NULL == inst->current.buffer)
        {
            /* Allocate the buffer to recive the data in. Note that this is only performed the first time for each bodypart */
            MEA_CALLOC(inst->current.buffer, size + 1);
        }
        
        res = MMSlib_getBodyPart(MSF_MODID_MEA, inst->current.bodyPart->number, 
        inst->current.buffer, &size, &mrInstance->msgHandle, &mrInstance->transaction);
        
        if (MMS_RESULT_DELAYED == res)
        { 
            meaAsyncRegister(MMSlib_getFileHandle(MSF_MODID_MEA, &mrInstance->transaction), retFsm, retSig, 0);  /* B'oh .. async! */
            return FALSE;
        }
        else if (MMS_RESULT_OK != res)
        {
            if (MMS_RESULT_BUFFER_FULL != res)
            {
                MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
                  MAMR_AB088BEB2C89DCF76434CBFF7C41911E, "(%s) (%d) failed to read bodypart %d!\n", 
                  __FILE__, __LINE__, inst->current.bodyPart->number));
                deleteMrInstance(&mrInstance, TRUE, MEA_MR_FAILED);
                return FALSE;
            }
        }

        /* Some MIXED messages from tools(NowSMS) may have large text, 
           so large that no enough memory to make internal error.
           So discard here.*/
        if (size >= MEA_CFG_MIXED_TEXT_MAX_READ_SIZE - 1)
        {
            ((char*)inst->current.buffer)[MEA_CFG_MIXED_TEXT_MAX_READ_SIZE - 1] = 0;
        }
    }
    else
    {
        res=MMS_RESULT_OK;
    }

    /* Temp solution to prevent loading too many obj.*/
    if (mrMoIsText(inst->current.bodyPart, &charset))
    {
        if ((size + inst->totalLen) > MEA_CFG_MESSAGE_LOAD_MAX_SIZE)
        {
            if (inst->current.buffer)
            {
                MEA_FREE(inst->current.buffer);
                inst->current.buffer = NULL;
            }
            return TRUE;
        }
        else
        {
            inst->totalLen += size;
        }
    }

    /*
     *	Body-part retrieved successfully - add it to media object list!
     *  (first converting to UTF8 if text)
     */
    if (size > 0 && mrMoIsText(inst->current.bodyPart, &charset))
    {
        if(charset == MSF_CHARSET_UNKNOWN)
        {
            if((size > MEA_UTF16_BOM_LEN) &&
                ((memcmp((char *)inst->current.buffer, MEA_UTF16_BOM_BIG, MEA_UTF16_BOM_LEN) == 0) ||
                (memcmp((char *)inst->current.buffer, MEA_UTF16_BOM_LITTELE, MEA_UTF16_BOM_LEN) == 0)))
            {
                charset = MSF_CHARSET_UTF_16;
            }
            else
            {
#ifdef __MMI_CHSET_GB2312__
                charset = meaAdjustCharset((unsigned char *)inst->current.buffer, size);
#else
                charset = MSF_CHARSET_UTF_8;
#endif
            }
        }
        /* This is a supported text type, do the conversion to UTF-8 */
        if (!meaConvertToUTF8(charset, &size, (unsigned char **)&inst->current.buffer))
        {
            return FALSE;
        }
    }

    /* Create file ending and MIME type */
    handleContentType(inst->current.bodyPart->contentType, &mime);
    if (meaIsSupportedMimeType(mime) == FALSE)
    {
        mime = NULL;
    }
    mType = meaMime2MediaType(mime);

    /* Name of media object */
    if (NULL != (name = createNameFromParams(inst->current.bodyPart->contentType->params)))
    {
    }
    else if (NULL == (name = createNameFromEntryHeader(inst->current.bodyPart->entryHeader)))
    {
        /* No name could be extracted from the originating message, create
           a generated name */
        name = meaCreateFileNameFromMime(mime);
    }
    
    if (mime == NULL && strrchr(name, '.') != NULL)  /* fault tolerance 1: get mime from filename */
    {
        mime = meaFileName2MimeType(name);
        mType = meaMime2MediaType(mime);
    }
    
    /* Content type doesn't sync with file extension */
    if (strrchr(name, '.') == NULL || meaFileName2MimeType(name) == NULL || 
        msf_cmmn_strcmp_nc(mime, meaFileName2MimeType(name)) != 0)
    {
        meaRenameExtensionFromMime(MSF_MODID_MEA, &name, mime);
    }

    gType = meaMediaType2ObjType(mType);
    /*  copy the original content type */
    MEA_CALLOC(mmsType, sizeof(MmsContentType));
    meaCopyContentType(mmsType, inst->current.bodyPart->contentType);

    /* Add the media object to the list of objects */ 
#ifdef __DRM_SUPPORT__
    if ((mo = meaAddMo(&mrInstance->msg->smilInfo->mediaObjects, inst->current.buffer, size, mType, 
                       MEA_MEDIA_TYPE_UNKNOWN, mmsType, name, inst->current.bodyPart->number, 0)) == NULL)
#else
    if ((mo = meaAddMo(&mrInstance->msg->smilInfo->mediaObjects, inst->current.buffer, size, mType, mmsType, name,
                       inst->current.bodyPart->number, 0)) == NULL)
#endif
    {
        meaFreeMmsContentType(mmsType);
        MEA_FREE(inst->current.buffer);
        inst->current.buffer = NULL;  /* The data is now handled by the media objectslist */
        return FALSE;
    }
    else
    {
        inst->current.buffer = NULL;
        
        ASSERT(mo->file == NULL);
        MEA_CALLOC(mo->file, sizeof(MeaMoFileRef));
        ASSERT(mo->file != NULL);
        MEA_CALLOC(mo->file->path, 100);
        ASSERT(mo->file->path != NULL);
        sprintf(mo->file->path, "%s%lx.%c", MMS_FOLDER, mrInstance->msg->msgId, fldrGetFileSuffix(mrInstance->msg->msgId));
        mo->file->pos = inst->current.bodyPart->startPos;
        mo->file->size = inst->current.bodyPart->size; 
        if( mo->content.origType->knownValue == MMS_TYPE_TEXT_PLAIN )
        {
            mo->acessType=meaMoInMemory;
        }
        else
        {
            mo->acessType=meaMoInPartOfFile;
        }
        mo->isRestricted = meaIsRestrictedTypeVF(mo->file->path, mo->content.type, mo->file->pos, mo->file->size);
    }

#ifdef __UNIFIED_MSG_SUPPORT__  /* need to create resource */
    if(mrInstance->mode == MEA_MR_STARTUP_VIEW)
    {
        (void)MEA_SIGNAL_SENDTO(MEA_MR_FSM, MEA_SIG_MR_READ_BODYPART);
    }
    else
    {
      #ifdef __DRM_SUPPORT__
        if (MEA_MEDIA_TYPE_DRM_CONTENT == mType)
        {
            MmsMsgId msgId = meaMMCGetCurrentActiveMsg();
            mo->file->filehandle = MSF_FILE_OPEN(MSF_MODID_MEA, mo->file->path, MSF_FILE_SET_RDONLY, 0);
            mo->reshandle = meaCreateDrmVirtualFileResource(MEA_MEDIA_TYPE_DRM_CONTENT, 
                mo->file->path, mo->file->pos, mo->file->size, msgId, mo->file->filehandle, &mo->content.drmType);
            if(mo->reshandle > 0)
            {
                moReadMixedBodyPart = mo;  /* wait for widget creating mo */
            }
            else
            {
                (void)MEA_SIGNAL_SENDTO(MEA_MR_FSM, MEA_SIG_MR_READ_BODYPART);
            }
        }
        else
      #endif
        {
            if(MEA_MEDIA_GROUP_TEXT == gType)
            {
                (void)MEA_SIGNAL_SENDTO(MEA_MR_FSM, MEA_SIG_MR_READ_BODYPART);
            }
            else if (MEA_MEDIA_GROUP_IMAGE == gType || MEA_MEDIA_GROUP_VIDEO == gType)
            {
                mo->reshandle = meaCreateVirtualFileResource(mType, mo->file->path, mo->file->pos, size);
                if(mo->reshandle > 0)
                {
                    moReadMixedBodyPart = mo;  /* wait for widget creating mo */
                }
                else
                {
                    (void)MEA_SIGNAL_SENDTO(MEA_MR_FSM, MEA_SIG_MR_READ_BODYPART);
                }
            }
            else
            {
                (void)MEA_SIGNAL_SENDTO(MEA_MR_FSM, MEA_SIG_MR_READ_BODYPART);
            }
        }
    }
#endif /* __UNIFIED_MSG_SUPPORT__ */

    inst->current.buffer = NULL;  /* The data is now handled by the media objectslist */
    if(MMS_RESULT_OK != MMSlib_transactionClose(MSF_MODID_MEA, &mrInstance->transaction))
    {
        return FALSE;
    }
    mrInstance->transaction = NULL;

    return TRUE;
}

/*! \brief Reads the text part of the slide.
 *	
 * \param inst The current instance.
 * \param sInfo The slide information.
 * \return TRUE if successful, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL readText(MeaMrInstance *inst, SlsGetSlideInfoRsp *sInfo)
{
    MeaObjInfo *objInfo;
    inst->textHandle = NULL;

    if (0 < sInfo->slideInfo.text.size)
    {
        if (!readMessagePart(inst,
            sInfo->slideInfo.text.type, 
            sInfo->slideInfo.text.fileName, MEA_MEDIA_GROUP_TEXT, 
            (MSF_INT32)sInfo->slideInfo.text.offset, 
            sInfo->slideInfo.text.size, &(mrInstance->textHandle)))
        {
            return FALSE;
        }

        /* Handle the text color */
        if (meaGetObjInfo(inst->msg->smilInfo, MEA_MEDIA_GROUP_TEXT, &objInfo))
        {
            objInfo->textColor = sInfo->slideInfo.text.color;
        }

        return TRUE;
    }
    return FALSE;
}

/*! \brief Reads the image object that is referenced from the current slide.
 *	
 * \param inst The current instance.
 * \param sInfo The slide information.
 * \return TRUE if successful, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL readImage(MeaMrInstance *inst, SlsGetSlideInfoRsp *sInfo)
{
    inst->imageHandle = NULL;
    if (0 < sInfo->slideInfo.image.size)
    {
        if ((!readMessagePart(inst, 
            sInfo->slideInfo.image.type, 
            sInfo->slideInfo.image.fileName, MEA_MEDIA_GROUP_IMAGE,  
            (MSF_INT32)sInfo->slideInfo.image.offset, 
            sInfo->slideInfo.image.size, &(inst->imageHandle))))
        {
            return FALSE;
        }
        return TRUE;
    }
    return FALSE;
}

/*! \brief Reads the video object that is referenced from the current slide.
 *	
 * \param inst The current instance.
 * \param sInfo The slide information.
 * \return TRUE if successful, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL readVideo(MeaMrInstance *inst, SlsGetSlideInfoRsp *sInfo)
{
    if (inst->imageHandle == 0 && 0 < sInfo->slideInfo.video.size)
    {
        if ((!readMessagePart(inst, sInfo->slideInfo.video.type, sInfo->slideInfo.video.fileName, MEA_MEDIA_GROUP_VIDEO, 
        	(MSF_INT32)sInfo->slideInfo.video.offset, sInfo->slideInfo.video.size, &(inst->imageHandle))))
        {
            return FALSE;
        }
        return TRUE;
    }
    return FALSE;
}

/*! \brief Reads the image object that is referenced from the current slide.
 *	
 * \param inst The current instance.
 * \param sInfo The slide information.
 * \return TRUE if successful, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL readAudio(MeaMrInstance *inst, SlsGetSlideInfoRsp *sInfo)
{
    /* Audio */
    inst->audioHandle = NULL;
    if (0 < sInfo->slideInfo.audio.size)
    {
        if (!readMessagePart(inst, sInfo->slideInfo.audio.type, 
            sInfo->slideInfo.audio.fileName, MEA_MEDIA_GROUP_AUDIO, 
            (MSF_INT32)sInfo->slideInfo.audio.offset, 
            sInfo->slideInfo.audio.size, &(inst->audioHandle)))
        {
            return FALSE;
        }
        return TRUE;
    }
    return FALSE;
}

/*! \brief Reads the objects that are referenced from the current slide.
 *	
 * \param inst The current instance.
 * \param sInfo The slide information.
 * \return TRUE if successful, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL readSlideObjects(MeaMrInstance *inst, 
    SlsGetSlideInfoRsp *sInfo)
{
    MSF_BOOL hasText   = FALSE;
    MSF_BOOL hasImage  = FALSE;
    MSF_BOOL hasAudio  = FALSE;
    MSF_BOOL textFirst = FALSE;
    SlsMediaType sMType = SLS_UNKNOWN;
    if( sInfo->slideInfo.text.type != SLS_NOT_USED )
    {
/*        if(sInfo->slideInfo.text.size == 0)
        {
            meaContentValidFlag = FALSE;
            sInfo->slideInfo.text.type = SLS_UNKNOWN ;
        }
        else*/
        {
            sMType = getSlsMediaTypeFromFileName(sInfo->slideInfo.text.fileName);
            if(meaMediaType2ObjType(meaSlsMediaTypeToMea(sMType)) != MEA_MEDIA_GROUP_TEXT &&
               meaMediaType2ObjType(meaSlsMediaTypeToMea(sMType)) != MEA_MEDIA_GROUP_DRM )
            {
               sInfo->slideInfo.text.type = SLS_UNKNOWN ;
               meaContentValidFlag = FALSE;
            }
            else if(sInfo->slideInfo.text.type == SLS_UNKNOWN)
	        {						
                if (meaMediaType2ObjType(meaSlsMediaTypeToMea(sMType)) == MEA_MEDIA_GROUP_TEXT)
                {
    		        sInfo->slideInfo.text.type = sMType;
                }
                else
                {
                    meaContentValidFlag = FALSE;
                }
	        }

        }
    }

    if( sInfo->slideInfo.image.type != SLS_NOT_USED )
    {
        if(sInfo->slideInfo.image.size == 0)
        {
            meaContentValidFlag = FALSE;
            sInfo->slideInfo.image.type = SLS_UNKNOWN ;
        }
        else
        {
            sMType = getSlsMediaTypeFromFileName(sInfo->slideInfo.image.fileName);
            if(meaMediaType2ObjType(meaSlsMediaTypeToMea(sMType)) != MEA_MEDIA_GROUP_IMAGE &&
               meaMediaType2ObjType(meaSlsMediaTypeToMea(sMType)) != MEA_MEDIA_GROUP_DRM )
            {
               sInfo->slideInfo.image.type = SLS_UNKNOWN ;
               meaContentValidFlag = FALSE;
            }
            else if(sInfo->slideInfo.image.type == SLS_UNKNOWN)
	        {						
                if (meaMediaType2ObjType(meaSlsMediaTypeToMea(sMType)) == MEA_MEDIA_GROUP_IMAGE)
                {
    		        sInfo->slideInfo.image.type = sMType;
                }
                else
                {
                    meaContentValidFlag = FALSE;
                }
	        }

        }
    }


    if( sInfo->slideInfo.video.type != SLS_NOT_USED )
    {
        if(sInfo->slideInfo.video.size == 0)
        {
            meaContentValidFlag = FALSE;
            sInfo->slideInfo.video.type = SLS_UNKNOWN ;
        }
        else
        {
            sMType = getSlsMediaTypeFromFileName(sInfo->slideInfo.video.fileName);
            if(meaMediaType2ObjType(meaSlsMediaTypeToMea(sMType)) != MEA_MEDIA_GROUP_VIDEO &&
               meaMediaType2ObjType(meaSlsMediaTypeToMea(sMType)) != MEA_MEDIA_GROUP_DRM )
            {
               sInfo->slideInfo.video.type = SLS_UNKNOWN ;
               meaContentValidFlag = FALSE;
            }
            else if(sInfo->slideInfo.video.type == SLS_UNKNOWN)
	        {						
                if (meaMediaType2ObjType(meaSlsMediaTypeToMea(sMType)) == MEA_MEDIA_GROUP_VIDEO)
                {
    		        sInfo->slideInfo.video.type = sMType;
                }
                else
                {
                    meaContentValidFlag = FALSE;
                }
	        }

        }
    }

    if( sInfo->slideInfo.audio.type != SLS_NOT_USED )
    {
        if(sInfo->slideInfo.audio.size == 0)
        {
            meaContentValidFlag = FALSE;
            sInfo->slideInfo.audio.type = SLS_UNKNOWN ;
        }
        else
        {
            sMType = getSlsMediaTypeFromFileName(sInfo->slideInfo.audio.fileName);
            if(meaMediaType2ObjType(meaSlsMediaTypeToMea(sMType)) != MEA_MEDIA_GROUP_AUDIO &&
               meaMediaType2ObjType(meaSlsMediaTypeToMea(sMType)) != MEA_MEDIA_GROUP_DRM )
            {
               sInfo->slideInfo.audio.type = SLS_UNKNOWN ;
               meaContentValidFlag = FALSE;
            }
            else if(sInfo->slideInfo.audio.type == SLS_UNKNOWN)
	        {						
                if (meaMediaType2ObjType(meaSlsMediaTypeToMea(sMType)) == MEA_MEDIA_GROUP_AUDIO)
                {
    		        sInfo->slideInfo.audio.type = sMType;
                }
                else
                {
                    meaContentValidFlag = FALSE;
                }
	        }

        }
    }


    hasText   = (sInfo->slideInfo.text.size  > 0 && sInfo->slideInfo.text.type != SLS_UNKNOWN);
    hasImage  = ((sInfo->slideInfo.image.size > 0 && sInfo->slideInfo.image.type != SLS_UNKNOWN) || 
        (sInfo->slideInfo.video.size > 0 && sInfo->slideInfo.video.type != SLS_UNKNOWN));
    hasAudio  = (sInfo->slideInfo.audio.size > 0 && sInfo->slideInfo.audio.type != SLS_UNKNOWN);
    textFirst = FALSE;

    /* Calculate whether the image region is further up than the text region */
    if (hasText && hasImage)
    {  
        if(sInfo->slideInfo.image.size > 0)  /* text v.s. image */
        {
            if (sInfo->slideInfo.text.region.position.cy.value < sInfo->slideInfo.image.region.position.cy.value)
            {
                /* Text on top of image */
                textFirst = TRUE;
            }
            else if (sInfo->slideInfo.text.region.position.cy.value == sInfo->slideInfo.image.region.position.cy.value)
            {
                /* Check if the layout is left to right */
                if (sInfo->slideInfo.text.region.position.cx.value < sInfo->slideInfo.image.region.position.cx.value)
                {
                    /* Text on top of the image */
                    textFirst = TRUE;
                }
            }
        }
        else if(sInfo->slideInfo.video.size > 0)  /* text v.s. video */
        {
            if (sInfo->slideInfo.text.region.position.cy.value < sInfo->slideInfo.video.region.position.cy.value)
            {
                /* Text on top of image */
                textFirst = TRUE;
            }
            else if (sInfo->slideInfo.text.region.position.cy.value == sInfo->slideInfo.video.region.position.cy.value)
            {
                /* Check if the layout is left to right */
                if (sInfo->slideInfo.text.region.position.cx.value < sInfo->slideInfo.video.region.position.cx.value)
                {
                    /* Text on top of the image */
                    textFirst = TRUE;
                }
            }
        }
        
        /* Create the new objects in correct order */
        if (textFirst)
        {
            /* Text */
            if (!readText(inst, sInfo))
            {
                return FALSE;
            }
            /* Image */
            if (!readImage(inst, sInfo) && !readVideo(inst, sInfo))
            {
                return FALSE;
            }
        }
        else
        {
            /* Image */
            if (!readImage(inst, sInfo) && !readVideo(inst, sInfo))
            {
                return FALSE;
            }
            /* Text */
            if (!readText(inst, sInfo))
            {
                return FALSE;
            }
        }
    }
    else
    {
        /* Text */
        if (hasText && !readText(inst, sInfo))
        {
            return FALSE;
        }
        /* Image */
        if (hasImage && (!readImage(inst, sInfo) && !readVideo(inst, sInfo)))
        {
            return FALSE;
        }
    }
    /* Audio */
    if (hasAudio && !readAudio(inst, sInfo))
    {
        return FALSE;
    }
    return TRUE;
}

/*! \brief Gets the next valid body-part
 *	
 * \param bodyPart The list of body-parts.
 * \param getNext Tells if the next entry are of interest or not.
 *****************************************************************************/
static void handleNextBodyPart(MmsBodyInfoList **bodyPart, MSF_BOOL getNext)
{
    MmsBodyInfoList *current;

    if ((NULL == bodyPart) || (NULL == *bodyPart))
    {
        return;
    }
    current = (getNext) ? (*bodyPart)->next : *bodyPart;
    /* Do not handle the nodes in the tree in order to make a simple list */
    while ((NULL != current) && ((0 != current->numOfEntries) || 
        (current->contentType->knownValue == MMS_VND_WAP_MULTIPART_MIXED) || (current->size == 0)))
    {
        current = current->next;
    }
    *bodyPart = current;
}

/*!
 * \brief The message re-creation signal handling logic.
 *
 * \param sig The received signal.
 *****************************************************************************/
static void mrSignalHandler(MeaSignal *sig)
{
    MeaSmilSlide *sSlide;
    SlsGetSlideInfoRsp *sInfo;
    SlsOpenSmilRsp *openSmilRsp;
    SlsUnrefItemList *unref;
    MSF_BOOL ret; 

    switch(sig->type)
    {
    case MEA_SIG_MR_START:
        /*
         *	Initialization.
         */
        meaContentValidFlag = TRUE;
        ret = createMrInstance(&mrInstance, (MeaMrStartData *)sig->p_param);
        if (!ret)
        {
            (void)MEA_SIGNAL_SENDTO_U(((MeaMrStartData *)sig->p_param)->retFsm, 
                ((MeaMrStartData *)sig->p_param)->retSig, MEA_MR_FAILED);
            MEA_FREE(sig->p_param);
            deleteMrInstance(&mrInstance, TRUE, MEA_MR_FAILED);
            break;
        }
        MEA_FREE(sig->p_param);
        /* Read the header in the next state in order to support async IO */
        (void)MEA_SIGNAL_SENDTO(MEA_MR_FSM, MEA_SIG_MR_READ_HEADER);
        break;

#ifdef WAP_SUPPORT
    case MEA_SIG_MR_RESTART:
        // Transform to Mixed MMS
        ret = createMrInstance(&mrInstance, (MeaMrStartData *)sig->p_param);
        if (!ret)
        {
            (void)MEA_SIGNAL_SENDTO_U(((MeaMrStartData *)sig->p_param)->retFsm, 
                ((MeaMrStartData *)sig->p_param)->retSig, MEA_MR_FAILED);
            MEA_FREE(sig->p_param);
            deleteMrInstance(&mrInstance, TRUE, MEA_MR_FAILED);
            break;
        }
        MEA_FREE(sig->p_param);
        /* Read the header in the next state in order to support async IO */
        (void)MEA_SIGNAL_SENDTO(MEA_MR_FSM, MEA_SIG_MR_CHANGE_HEADER_TO_MIXED);
        break;
		
    case MEA_SIG_MR_CHANGE_HEADER_TO_MIXED:
        /*
         *	Read the header, analyze it, dispose of it
         */
        if (!mrReadHeader(MEA_MR_FSM, MEA_SIG_MR_CHANGE_HEADER_TO_MIXED))
        {
            /*
             * Delayed or failed;
             * if failed deleteMrInstance() has been called
             */
            break;
        } /* if */
		mrInstance->msg->msgType = MEA_MR_MULTIPART_MIXED;
        /* Just reading ALL body-parts. */
        /* Create a new SMIL presentation */

        /*  Insert code here for inserting mediaobjects outside the 
         *  smilinfo structure once the mediaobject list has been broken 
         *  out from it 
         */
        if (!meaCreateSmilInstance(&mrInstance->msg->smilInfo))
        {
            meaCleanupSmilInstance(&mrInstance->msg->smilInfo);
            deleteMrInstance(&mrInstance, TRUE, MEA_MR_FAILED);
            break;
        }
        /* Set the first object in the list to read from persistent storage */
        mrInstance->current.bodyPart = &(mrInstance->msgHeader->bodyInfoList);

        handleNextBodyPart(&mrInstance->current.bodyPart, FALSE);

        /* Read bodypart in the next state in order to support async IO */
        (void)MEA_SIGNAL_SENDTO(MEA_MR_FSM, MEA_SIG_MR_READ_BODYPART);
        break;
#endif /* WAP_SUPPORT */

    case MEA_SIG_MR_READ_HEADER:
        /*
         *	Read the header, analyze it, dispose of it
         */
        if (!mrReadHeader(MEA_MR_FSM, MEA_SIG_MR_READ_HEADER))
        {
            /*
             * Delayed or failed;
             * if failed deleteMrInstance() has been called
             */
            break;
        } /* if */

        /* Sometimes only the header is needed.. (RE/FWD, for instance) */
        if (mrInstance->onlyHeader)
        {
            /* All done! Lets die gracefully! */
            deleteMrInstance(&mrInstance, TRUE, MEA_MR_OK);
            break;
        }

        /* .. and sometimes more is needed.. */
        if (MEA_MR_SMIL == mrInstance->msg->msgType)
        {
            /* ..like reading an entire SMIL! */
            if (MMS_RESULT_OK != MMSlib_messageClose(MSF_MODID_MEA, 
                &mrInstance->msgHandle))
            {
                mrInstance->msgHandle = NULL;
                deleteMrInstance(&mrInstance, TRUE, MEA_MR_FAILED);
                break;
            }
            /* Start the SLS module, continue when the SLS is started */
            meaModuleStart(MSF_MODID_SLS, TRUE, MEA_MR_FSM, 
                MEA_SIG_MR_SLS_RSP);
        }
        else
        {
            /* ..or just reading ALL body-parts. */
            /* Create a new SMIL presentation */

            /*  Insert code here for inserting mediaobjects outside the 
             *  smilinfo structure once the mediaobject list has been broken 
             *  out from it 
             */
            if (!meaCreateSmilInstance(&mrInstance->msg->smilInfo))
            {
                meaCleanupSmilInstance(&mrInstance->msg->smilInfo);
                deleteMrInstance(&mrInstance, TRUE, MEA_MR_FAILED);
                break;
            }
            /* Set the first object in the list to read from persistent storage */
            mrInstance->current.bodyPart = &(mrInstance->msgHeader->bodyInfoList);
            handleNextBodyPart(&mrInstance->current.bodyPart, FALSE);
            /* Read bodypart in the next state in order to support async IO */
            (void)MEA_SIGNAL_SENDTO(MEA_MR_FSM, MEA_SIG_MR_READ_BODYPART);
        } /* if */
        break;

    case MEA_SIG_MR_READ_BODYPART:
        if (NULL != mrInstance->current.bodyPart && mrInstance->current.bodyPart->contentType->strValue && 
            msf_cmmn_strcmp_nc((const char*)mrInstance->current.bodyPart->contentType->strValue, MMS_MEDIA_TYPE_STRING_SMIL) == 0 )
        {
            /* Skip the SMIL part */
            handleNextBodyPart(&mrInstance->current.bodyPart, TRUE);
        }

        if (NULL == mrInstance->current.bodyPart)
        {
/* ifdef __UNIFIED_MSG_SUPPORT__*/
            /*All done! reverse mediaObjects order */
            if(mrInstance->msg->smilInfo->mediaObjects)
            {
                meaReverseMediaObject(&mrInstance->msg->smilInfo->mediaObjects);
            }
/* #endif*/

            /* No use trying to read what's not there. Make do without. */
            deleteMrInstance(&mrInstance, TRUE, MEA_MR_OK);        
            break;
        }
        
        /*
         *	Read a body-part! Might do this again and again.
         */
        if (!mrReadBodyPart(mrInstance, MEA_MR_FSM, MEA_SIG_MR_READ_BODYPART))
        {
            break;
        }

        /* Next time, next body-part (or be done) */
        handleNextBodyPart(&mrInstance->current.bodyPart, TRUE);

#ifndef __UNIFIED_MSG_SUPPORT__
        if (NULL != mrInstance->current.bodyPart) 
        {
            (void)MEA_SIGNAL_SENDTO(MEA_MR_FSM, MEA_SIG_MR_READ_BODYPART);
            break;
        }
        else
        {
            meaReverseMediaObject(&mrInstance->msg->smilInfo->mediaObjects);
            /* All done! Lets die gracefully! */
            deleteMrInstance(&mrInstance, TRUE, MEA_MR_OK);        
        }
#endif
        break;

    /* SLS handling */
    case MEA_SIG_MR_SLS_RSP:
        /*
         *	SLS is now started, let's open the SMIL.
         */
        (void)SLSif_openSmil(MSF_MODID_MEA, mrInstance->msg->msgId, 
            mrInstance->msg->fileType);
        break;

    case MEA_SIG_MR_OPEN_SMIL_RSP:
        /*
         *	The SMIL is now opened, we're ~50% done. Start parsing it. 
         */
        openSmilRsp = (SlsOpenSmilRsp *)sig->p_param;
        unref = openSmilRsp->unrefItems;
        if ((SLS_RESULT_OK != openSmilRsp->result) || (NULL == openSmilRsp->file))
        {
            meaRestartMr(mrInstance->mode, mrInstance->msg->msgId, mrInstance->msg->fileType, mrInstance->fsm, 
                mrInstance->signal);
            deleteMrInstance(&mrInstance, FALSE, MEA_MR_FAILED);
            //deleteMrInstance(&mrInstance, TRUE, MEA_MR_FAILED);
            break;
        } /* if */

        /* Create a new SMIL presentation */
        if (!meaCreateSmilInstance(&mrInstance->msg->smilInfo))
        {
            meaCleanupSmilInstance(&mrInstance->msg->smilInfo);
            deleteMrInstance(&mrInstance, TRUE, MEA_MR_FAILED);
            MEA_FREE(openSmilRsp->file);
            if(openSmilRsp->unrefItems != NULL)
            {
                meaFreeUnrefList(&openSmilRsp->unrefItems);
            }
            break;
        }
        mrInstance->msg->fileName = msf_cmmn_strdup(MSF_MODID_MEA, openSmilRsp->file);
        mrInstance->slideCount = (MSF_UINT8)openSmilRsp->noOfSlides;
        mrInstance->currentSlide = MEA_MR_FIRST_SLIDE;
        mrInstance->msg->smilInfo->bgColor = (MSF_UINT32)openSmilRsp->rootLayout.bgColor;

        /* In MR, attachment is only handled here */
        while(unref)
        {
#ifdef __DRM_SUPPORT__
            MeaMoDataItem *mo = meaAddMo(&mrInstance->msg->unrefList, NULL, unref->size, 
                meaSlsMediaTypeToMea(unref->mediaType), MEA_MEDIA_TYPE_UNKNOWN, NULL, unref->fileName, 0, 0);
#else
            MeaMoDataItem *mo = meaAddMo(&mrInstance->msg->unrefList, NULL, unref->size, 
                meaSlsMediaTypeToMea(unref->mediaType), NULL, unref->fileName, 0, 0);
#endif
            MEA_CALLOC(mo->file, sizeof(MeaMoFileRef));
            mo->file->path = msf_cmmn_strdup(MSF_MODID_MEA, mrInstance->msg->fileName);
            mo->file->pos = unref->offset;
            mo->file->size = unref->size;
            mo->isRestricted = meaIsRestrictedTypeVF(mo->file->path, mo->content.type, mo->file->pos, mo->file->size);
            mo->acessType = meaMoInPartOfFile;
            unref->fileName = NULL;
            unref = unref->next;
        }
        MEA_FREE(openSmilRsp->file);
        if(openSmilRsp->unrefItems != NULL)
        {
            meaFreeUnrefList(&openSmilRsp->unrefItems);
        }
        
        /* Get first slide; returning with MEA_SIG_MR_GET_SLIDE_INFO_RSP */
        (void)SLSif_getSlideInfo(MSF_MODID_MEA, MEA_MR_FIRST_SLIDE);
        break;

    case MEA_SIG_MR_GET_SLIDE_INFO_RSP:
        /*
         *	Slide information retrieved. Time to start as many async file 
         *  reads as it takes to read all objects in the current slide.
         *  We will get MEA_SIG_MR_MO_READ signals laters for every op.
         */
        sInfo = (SlsGetSlideInfoRsp*)sig->p_param;
        if ((NULL == sInfo) || (SLS_RESULT_OK != sInfo->result) || (NULL == mrInstance) ||
            (NULL == (sSlide = meaInsertSlide(mrInstance->msg->smilInfo))))
        {
            deleteMrInstance(&mrInstance, TRUE, MEA_MR_FAILED);
            break;
        }
        
        /* Tick progress */
        meaPmSetProgress(50+(mrInstance->currentSlide*40)/
            mrInstance->slideCount, NULL);
        meaSetDuration(mrInstance->msg->smilInfo, 
            sInfo->slideInfo.duration * 1000);
        /* Text */
        if (!readSlideObjects(mrInstance, sInfo))
        {
            meaFreeSlsSlideInfo(sInfo);
            deleteMrInstance(&mrInstance, TRUE, MEA_MR_FAILED);
            break;
        }
         /* Free slide data */
        meaFreeSlsSlideInfo(sInfo);
        meaGetNextSlideOrClose();
        break;

    case MEA_SIG_MR_MO_READ:
        /*
         *	The async FSM is done reading something.
         *  Probably a media object pointed to by a SMIL slide.
         */
        if ((NULL == mrInstance) ||
            (((MeaAsioResult)sig->u_param1 != MEA_ASIO_RESULT_OK) &&
            ( (MeaAsioResult)sig->u_param1 != MEA_ASIO_RESULT_EOF)))
        {
            deleteMrInstance(&mrInstance, TRUE, MEA_MR_FAILED);
            break;
        } /* if */
        
        /* Done with the async operation so lets stop and close it */
        /*lint -e{788} */
        switch((MeaMediaGroupType)sig->i_param)
        {
        case MEA_MEDIA_GROUP_TEXT:
            meaAsyncOperationStop(&(mrInstance->textHandle));
            mrInstance->textHandle = NULL;
            meaGetNextSlideOrClose();
            break;
        case MEA_MEDIA_GROUP_IMAGE:
#ifndef MMS_SLIM_MEM
            meaAsyncOperationStop(&(mrInstance->imageHandle));
            mrInstance->imageHandle = NULL;
            meaGetNextSlideOrClose();
            break;
        case MEA_MEDIA_GROUP_AUDIO:
            meaAsyncOperationStop(&(mrInstance->audioHandle));
            mrInstance->audioHandle = NULL;
            meaGetNextSlideOrClose();
#endif /* MMS_SLIM_MEM */
            break;
        default:
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                MAMR_7CA8012CFA984508964329BD679F6B47, "(%s) (%d) Erroneous object type = %d\n", __FILE__,
                __LINE__, sig->i_param));
            break;
        }

        //meaGetNextSlideOrClose();
        break;

    case MEA_SIG_MR_CLOSE_SMIL_RSP:
        /*
         *	We're done with the SMIL reading/parsing. Time to die - gracefully!
         */
        deleteMrInstance(&mrInstance, TRUE, 
            ((SlsResult)sig->u_param1 == SLS_RESULT_OK) ? MEA_MR_OK: MEA_MR_FAILED);
        break;

    default:
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MAMR_BE2BB4864A8947C518C6343BEC588595, "MR: Erroneous signal received (%d).\n", sig->type));
        break;
    }
    /* Remove signal data */
    meaSignalDelete(sig);
    /*lint -e{550} */
}

/*!
 * \brief Starts the MR FSM that will read a message from disk
 *
 * \param mode What mode to read message for (i.e. REPLY -> only read header)
 * \param msgID The msgId of the message to read
 * \param fileType The type of the message to read
 * \param retFsm The FSM to receive a signal when done
 * \param retSig The signal to receive when done
 *****************************************************************************/
void meaStartMr(MeaMrStartupMode mode, MmsMsgId msgId, MmsFileType fileType, 
                 MeaStateMachine retFsm, unsigned int retSig)
{
    MeaMrStartData *mrData;

    MEA_CALLOC(mrData, sizeof(MeaMrStartData));
    mrData->fileType   = fileType;
    mrData->msgId      = msgId;
    mrData->mode       = mode;
    mrData->retFsm     = retFsm;
    mrData->retSig     = (int)retSig;
    (void)MEA_SIGNAL_SENDTO_P(MEA_MR_FSM, MEA_SIG_MR_START, (void *)mrData);
}

/*!
 * \brief Frees a #MeaMessage structure completely
 *
 * \param msg The #MeaMessage structure to dispose of
 *****************************************************************************/
void meaFreeMessage(MeaMessage **msg)
{
    if ((NULL == msg) || (NULL == *msg))
    {
        return;
    } /* if */

    MEA_FREE((*msg)->fileName);
    
    /* message properties */
    meaFreePropItem((*msg)->msgProperties, FALSE);

    /* SMIL stuff */
    if ((*msg)->smilInfo != NULL)
    {
        meaCleanupSmilInstance(&(*msg)->smilInfo);
    }

    /* attachment */
    if ((*msg)->unrefList != NULL)
    {
        meaRemoveAttachment(&(*msg)->unrefList);
    }
    MEA_FREE(*msg);
    *msg = NULL;
}

/*!
 * \brief Decides what to do next while iterating through all slides - 
 *        wait for pending file ops, get next slide, or, if done, close SMIL.
 * \param msg The #MeaMessage structure to dispose of
 *****************************************************************************/
static void meaGetNextSlideOrClose(void)
{
    /* Are we waiting for something? Then wait. */
    if ((0 != mrInstance->textHandle ) ||
        (0 != mrInstance->imageHandle) ||
        (0 != mrInstance->audioHandle))
    {
        return;
    }

    /* No more file ops to wait for. Was it the last slide? */
    if (mrInstance->currentSlide >= mrInstance->slideCount - 1)
    {
        /* The operation is finished, close the SMIL */
        (void)SLSif_closeSmil(MSF_MODID_MEA);
    }
    else
    {/* Get the next slide */
        mrInstance->currentSlide++;
        (void)SLSif_getSlideInfo(MSF_MODID_MEA, 
            (MSF_UINT8)mrInstance->currentSlide);
    }                
}

