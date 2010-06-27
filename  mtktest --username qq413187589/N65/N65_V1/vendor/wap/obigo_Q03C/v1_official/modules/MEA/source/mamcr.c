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

/* !\file mamcr.c
 *  \brief Message Creation FSM.
 */

/* MSF */
#include "msf_core.h"
#include "msf_mem.h"
#include "msf_int.h"
#include "msf_log.h"
#include "msf_lib.h"
#include "msf_chrs.h"   /* Character set conversion functions */
#ifdef WAP_SUPPORT
#include "msf_file.h"
#endif /* WAP_SUPPORT */

/* MMS */
#include "mms_cfg.h"
#include "mms_def.h"
#include "mmsl_if.h"
#include "mms_if.h"
#ifdef WAP_SUPPORT
#include "mutils.h"
#include "mcpdu.h"    //mcwap.h
#include "mcwap.h"    //for mmsWapGetTransactionId
#include "msig.h"     //for fldmgr.h
#include "fldmgr.h"   //for fldrMgrDeleteMessage
#include "mms_aApp.h" //for genChkSumFile
#include "mltypes.h"  //for MmsTransaction
#endif /* WAP_SUPPORT */

/* SLS */
#include "sls_cfg.h"
#include "sls_if.h"

/* MEA */
#include "maintsig.h"
#include "mea_def.h"
#include "mea_cfg.h"
#include "matypes.h"
#include "mea_rc.h"
#include "mamem.h"
#include "mamr.h"
#include "mamcr.h"
#include "mautils.h"
#include "mamh.h"
#include "madel.h"
#include "maconf.h"
#include "mautils.h"
#include "maasync.h"
#include "mauipm.h"
#include "mamoh.h"
#include "maaddr.h"
#include "maslh.h"
#ifdef WAP_SUPPORT
#include "maph.h"
#include "mase.h"  /* meaSeGetAttachmentNo */
#include "mauise.h"  //for meaSmilEditorIsActive
#include "widget_extension.h" //for HDI_EXTERNAL_PATH

extern int generateSMIL(unsigned char *strBuffer, MSF_BOOL isForEmptyMms);
#ifdef __GEMINI__
extern kal_bool is_test_sim(kal_uint8 simInterface);
#else
extern kal_bool is_test_sim(void);
#endif
extern MSF_BOOL addAttachmentToMmsMessage(MSF_UINT8 modId,MmsMsgId msgId,MSF_UINT32 numOfBodyPosition, MSF_UINT8 objectNum,attachmentObjectList *attachObjectList);		//travis
#endif /* WAP_SUPPORT */

/******************************************************************************
 * Macros
 *****************************************************************************/
#define SET_CHARSET_PARAM(allParams)        addIntParam(allParams, \
                                                MMS_CHARSET, MMS_UTF8)
#define SET_FILENAME_PARAM(allParams, str)  addStrParam(allParams, \
                                                MMS_FILENAME, str)
#ifdef MMS_USE_NAME_PARMS
#define SET_NAME_PARAM(allParams, str)  addStrParam(allParams, \
                                                MMS_NAME, str)
#endif /* MMS_USE_NAME_PARMS */
#define SET_START_REL_PARAM(allParams, str) addStrParam(allParams, \
                                                MMS_START_REL, str)
#define SET_TYPE_REL_PARAM(allParams, str)  addStrParam(allParams, \
                                                MMS_TYPE_REL,str)
#define SET_CONTENT_ID(entryHeads, str)     addStrEntry(entryHeads, \
                                                MMS_WELL_KNOWN_CONTENT_ID, str)
#define SET_CONTENT_LOCATION(entryHeads, str) addStrEntry(entryHeads, \
                                        MMS_WELL_KNOWN_CONTENT_LOCATION, str)
#define ORIGINAL_MSG_EXISTS(inst) (NULL != (inst)->origMsg)

#define IS_FORWARD_OP(inst) ((NULL != inst) && (NULL != inst->origMsg) && \
    (inst->origMsg->forwardMode))

/******************************************************************************
 * Constants
 *****************************************************************************/

/*! The filename used for the SMIL part in multi-part related messages */
#ifndef WAP_SUPPORT //move to mea_def.h
#define MEA_SMIL_FILE_NAME          "s.smil"
#endif /* ~WAP_SUPPORT */

/*!\enum MeaCreateMsgStates
 * Internal states when creating a message */
typedef enum
{
    CREATE_MSG_ID,        /* !< Creating a new message ID */
    CREATE_HEADER,        /* !< Creating the message hader */
    READ_HEADER,          /* !< Reading the message header to persistent 
                                storage from the original message during fwd */
    WRITE_HEADER,         /* !< Writing the message header to persistent 
                                storage */
    WRITE_BODY_PART,      /* !< Writing message parts */
    WRITE_SMIL_PART,      /* !< Write the plain text part of a message */
    COPY_BODY,            /* !< Copy body during forward */
    FINALISE_MSG,         /* !< Finalising the message */
    MESSAGE_DONE_RESPONSE /* !< Message is finalised */
}MeaCreateMsgStates;

/******************************************************************************
 * Data-structures
 *****************************************************************************/
/*!\struct McrOriginalMessage 
 * If allocated, contains information about the original message
 */
typedef struct 
{
    MmsMsgId                msgId;          /*!< The message ID */
    MmsFileType             fileType;       /*!< Message type */
    MSF_BOOL                del;            /*!< Delete when done ? */
    MSF_BOOL                forwardMode;    /*!< This is a forward op  */
    MmsTransactionHandle    tHandle;        /*!< Transaction handle */
    char                    *srcFile;       /*!< message filename */
    char                    *dstFile;       /*!< new message filename */
    MmsGetHeader            *hdr;           /*!< original header */
    MmsMsgHandle            msgHandle;      /*!< handle of the orig msg */
    MSF_UINT32              leftToRead;     /*!< Data left to read */
    int                     readPos;        /*!< The size read so far */
    int                     sizeToWrite;    /*!< The size to write */
    MSF_UINT32              copyBufferSize; /*!< size of copybuffer */
    unsigned char           *copyBuffer;    /*!< Buffer for async copying */
    MeaAsyncOperationHandle asioReadHandle; /*!< Read handle for AsyncIO */
    MeaAsyncOperationHandle asioWriteHandle;/*!< Write handle for AsyncIO */
} McrOriginalMessage;


/*!\struct McrInstance 
 * Data structure used when creating a message */
typedef struct
{
    MmsMsgId                msgId;          /*!< The ID of the message */
    MmsFileType             msgType;        /*!< The message type of the new message */
    MmsBodyPartTarget       targetType;     /*!< The MMS message target type */
    MmsFolderType           saveInFolder;   /*!< Which folder to save the message in */
    MeaCreateMsgStates      state;          /*!< The current state */
    MeaStateMachine         fsm;            /*!< FSM to send result to */
    int                     sig;            /*!< Signal to send */
    MmsMsgHandle            msgHandle;      /*!< The handle of the message */
    MmsTransactionHandle    tHandle;        /*!< Transaction handle */
    MmsSetHeader            *msgHdr;        /*!< The header of the message */
    MeaMessage              *msg;           /*!< The content of the message */
    /* Body part information */
    MeaMoDataItem           *currentMo;     /*!< The media object that is 
                                                 currently being stored */
    MmsBodyParams           *bodyParams;    /*!< The params for the current 
                                                 media object */
    unsigned char           *tmpBuffer;     /*!< Buffer used for SMIL 
                                                 generation */
    unsigned int            tmpSize;        /*!< Size of SMIL generation 
                                                 buffer */
#ifdef WAP_SUPPORT
    unsigned int            bodynum_pos;    /*for MMS attachment only*/
#endif
    /* Results from MMS lib operations */
    MmsResult               mmsResult;      /*!< Result of last MMSLib 
                                                 operation */
    McrOriginalMessage      *origMsg;       /*!< Data for original message */

}McrInstance;

/******************************************************************************
 * Variables
 *****************************************************************************/
static McrInstance *mcrInstance;

/******************************************************************************
 * Prototypes
 *****************************************************************************/
static void mcrSignalHandler(MeaSignal *sig);
static void cleanupMcrInstance(MeaMcrResult result);
static void releaseSmilBuffer(McrInstance *instance);

/******************************************************************************
 * Function implementation
 *****************************************************************************/

/*
 * \brief Inserts an integer param first in the list of params
 *
 * \param allParams The current list.
 * \param param     The param to insert.
 * \param value     The integer value for the param to insert.
 *****************************************************************************/
static void addIntParam(struct MmsAllParamsStruct **allParams, 
    MmsParam param, MSF_UINT32 value)
{
    MmsAllParams *newParam = NULL;

    MEA_CALLOC(newParam, sizeof(MmsAllParams));
    /* Set param value */
    newParam->param = param;
    newParam->type = MMS_PARAM_INTEGER;
    newParam->value.integer = value;

    /* Insert param. Insert first in the list */
    newParam->next = *allParams;
    *allParams = (struct MmsAllParamsStruct *)newParam;
}

/*!
 * \brief Inserts a string param first in the list of params
 *
 * \param allParams The current list.
 * \param param The param to insert.
 * \param strValue The string value for the param to insert. The strValue can
 *                 be released after the call to this function.
 *****************************************************************************/
static void addStrParam(struct MmsAllParamsStruct **allParams, 
    MmsParam param, const char *strValue)
{
    MmsAllParams *newParam = NULL;

    MEA_CALLOC(newParam, sizeof(MmsAllParams));
    /* Set param value */
    newParam->param = param;
    newParam->type = MMS_PARAM_STRING;
    newParam->value.string = 
        (unsigned char *)msf_cmmn_strdup(MSF_MODID_MEA, strValue);
    /* Insert param. Insert first in the list */
    newParam->next = *allParams;
    *allParams = (struct MmsAllParamsStruct *)newParam;
}

/*!
 * \brief Inserts a string entry first in the list of entries
 *
 * \param entryHeads The current list.
 * \param type The type of entry to insert.
 * \param strValue The string value for the entry to insert. The strValue can
 *                 be released after the call to this function.
 *****************************************************************************/
static void addStrEntry(MmsEntryHeader **entryHeads, 
    MmsEntryHeaderValueType type, const char *strValue)
{
    /* Content ID */
    MmsEntryHeader *newEntry;
    MEA_CALLOC(newEntry, sizeof(MmsEntryHeader));
    /* Set value */
    newEntry->headerType = type;
    newEntry->value.wellKnownFieldName = 
        (unsigned char *)msf_cmmn_strdup(MSF_MODID_MEA, strValue);
    /* Insert param. Insert first in the list */
    newEntry->next = *entryHeads;
    *entryHeads = newEntry;
}

/*! 
 * \brief De-allocates a #MmsBodyParams data structure.
 *
 * \param bodyParams The body param to release. The pointer is set to NULL.
 *****************************************************************************/
static void freeBodyParams(MmsBodyParams **bodyParams)
{
    MmsAllParams *param;
    MmsAllParams *tmpParam;
    MmsEntryHeader *entry;
    MmsEntryHeader *tmpEntry;

    if (NULL != *bodyParams)
    {
        /* Free params */
        param = (*bodyParams)->contentType.params;
        MEA_FREE((*bodyParams)->contentType.strValue);
        while (NULL != param)
        {
            if (MMS_PARAM_STRING == param->type)
            {
                MEA_FREE(param->value.string);
            }
            tmpParam = param;
            param = param->next;
            MEA_FREE(tmpParam);
        }
        /* Free entries */
        entry = (*bodyParams)->entryHeader;
        while (NULL != entry)
        {
            /* Free content ID or content location string */
            if ( (MMS_WELL_KNOWN_CONTENT_ID == entry->headerType) ||
                 (MMS_WELL_KNOWN_CONTENT_LOCATION == entry->headerType))
            {
                MEA_FREE(entry->value.wellKnownFieldName);
            }
            tmpEntry = entry;
            entry = entry->next;
            MEA_FREE(tmpEntry);
        }
        MEA_FREE(*bodyParams);
        *bodyParams = NULL;
    }
}

/*!
 * \brief Initiates the message creation FSM by registering its signal handler
 *****************************************************************************/
void meaMcrInit(void)
{
    /* Register queue */
    mcrInstance   = NULL;
    meaSignalRegisterDst(MEA_MCR_FSM, mcrSignalHandler);
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, MAMCR_D3726286B6BB960CE0611549B9007F35, "MCR initialised\n"));
}

/*!
 * \brief Terminates the message editor.
 *****************************************************************************/
void meaMcrTerminate(void)
{
    /* Deregister queue */
    cleanupMcrInstance(MEA_MCR_CLEANUP_SILENT);
    mcrInstance   = NULL;
    meaSignalDeregister(MEA_MCR_FSM);
}

/*!
 * \brief Converts from MEA to MMS visibility
 * 
 * \param vis Visibility in MEA format 
 * \return Visibility in MMS format
 *****************************************************************************/
static MmsSenderVisibility visibilityMeaToMms(MeaVisibilityType vis)
{
    switch (vis)
    {
#ifndef WAP_SUPPORT  //Some MMSCs don't recognize this
    case MEA_SENDER_HIDE:
        return MMS_SENDER_HIDE;
    case MEA_SENDER_SHOW:
        return MMS_SENDER_SHOW;
#endif /* ~WAP_SUPPORT */
    default:
        return MMS_SENDER_VISIBILITY_NOT_SET;
    }
} /* visibilityMeaToMms */

/*!
 * \brief Converts between MEA and MMS message priorities 
 * 
 * \param prio  Mea priority
 * \return MMS priority
 *****************************************************************************/
static MmsPriority priorityMeaToMms(MeaPriorityType prio)
{
    switch (prio) 
    {
    case MEA_PRIORITY_LOW:
        return MMS_PRIORITY_LOW;
    case MEA_PRIORITY_NORMAL:
        return MMS_PRIORITY_NORMAL;
    case MEA_PRIORITY_HIGH:
        return MMS_PRIORITY_HIGH;
    default:
        return MMS_PRIORITY_NOT_SET;
    }
} /* priorityMeaToMms */

/*!
 * \brief Sets reply charging part of an MmsSetHeader
 * 
 * \param p The current message properties.
 * \param hdr The header to set according to the configuration.
 *****************************************************************************/
void replyChargingMeaToMms(const MeaPropItem *p, MmsSetHeader *hdr)
{
    MmsTimeSec baseSeconds = 0; 
    if (MEA_REPLY_CHARGING_ON == p->replyCharging ||
        MEA_REPLY_CHARGING_TEXT_ONLY == p->replyCharging)
    {
       
        
    #if MEA_CONF_CHARGING_DEADLINE_TIME_RELATIVE
    {
        
        baseSeconds = 0;
        hdr->replyChargingDeadlineType = MMS_TIME_RELATIVE;
    }
    #else /* absolute */
    {
        baseSeconds =  hdr->date;
        hdr->replyChargingDeadlineType = MMS_TIME_ABSOLUTE;
    } /* if */
    #endif
        
        hdr->replyCharging = ((MEA_REPLY_CHARGING_ON == p->replyCharging)
            ? MMS_REPLY_CHARGING_REQUESTED
            : MMS_REPLY_CHARGING_REQUESTED_TEXT_ONLY);
        /* Reply charging deadline */
        switch(p->replyChargingDeadline)
        {
        case MEA_REPLY_CHARGING_DEADLINE_1_DAY:
            hdr->replyChargingDeadline = baseSeconds + MEA_1_DAY;
            break;
        case MEA_REPLY_CHARGING_DEADLINE_1_WEEK:
            hdr->replyChargingDeadline = baseSeconds + MEA_1_WEEK;
            break;
        case MEA_REPLY_CHARGING_DEADLINE_MAX:
            hdr->replyChargingDeadline = baseSeconds + MEA_1_YEAR;
            break;
        default:
            hdr->replyChargingDeadline = baseSeconds + MEA_1_DAY;
            break;
        }
        /* Reply charging size */
        switch(p->replyChargingSize)
        {
        case MEA_REPLY_CHARGING_SIZE_1_KB:
            hdr->replyChargingSize = MEA_1_KB;
            break;
        case MEA_REPLY_CHARGING_SIZE_10_KB:
            hdr->replyChargingSize = MEA_10_KB;
            break;
            case MEA_REPLY_CHARGING_SIZE_MAX:
            hdr->replyChargingSize = 0;
            break;
        default:
            hdr->replyChargingSize = 0;
            break;
        }
    }
    else
    {
        hdr->replyCharging = MMS_REPLY_CHARGING_NOT_SET;
    }    
    
    if ((NULL != p->replyChargingId) && (strlen(p->replyChargingId) > 0))
    {
        hdr->replyChargingId = MEA_ALLOC(strlen(p->replyChargingId) + 1);
        strcpy(hdr->replyChargingId, p->replyChargingId);
    }
    else
    {
        hdr->replyChargingId = NULL;
    }
} /* replyChargingMeaToMms */

/*!
 * \brief Sets expiry time
 * 
 * \param now Time right now
 * \param meaTime The expiry setting to use
 * \param time Expiry-time will be returned through this variable
 * \param time Expiry-type will be returned through this variable
 *****************************************************************************/
void setExpiryTime(MmsTimeSec now, MeaExpiryTimeType meaTime, MmsTimeSec *time, 
    MmsTimeType *type)
{
    MmsTimeSec baseSeconds = 0; 

    /*  Base seconds is the base to add the chosen number of seconds to. If 
     *  relative time is used no base is added otherwise current time is used.
     */

    #if MEA_CONF_EXPIRY_TIME_RELATIVE
    {
        (void)now;
        baseSeconds = 0;
        *type = MMS_TIME_RELATIVE;
    }
    #else /* absolute */
    {
        baseSeconds = now;
        *type = MMS_TIME_ABSOLUTE;
    } /* if */
    #endif

    switch (meaTime) 
    {
    case MEA_EXPIRY_1_HOUR:
        *time = baseSeconds + MEA_EXPIRY_1_HOUR_IN_SEC;
    	break;
    case MEA_EXPIRY_6_HOURS:
        *time = baseSeconds + MEA_EXPIRY_6_HOURS_IN_SEC;
        break;
    case MEA_EXPIRY_12_HOURS:
        *time = baseSeconds + MEA_EXPIRY_12_HOURS_IN_SEC;
        break;
    case MEA_EXPIRY_1_DAY:
        *time = baseSeconds + MEA_EXPIRY_1_DAY_IN_SEC;
        break;
    case MEA_EXPIRY_1_WEEK:
        *time = baseSeconds + MEA_EXPIRY_1_WEEK_IN_SEC;
        break;
    case MEA_EXPIRY_MAX:
        *time = 0;  /* IOT issue: don't give X-Mms-Expiry info. It's optional and deafult is maximum */
//        *time = baseSeconds + MEA_EXPIRY_MAX_IN_SEC;
        break;
    default:
        *time = 0;
//        *time = baseSeconds + MEA_EXPIRY_MAX_IN_SEC;
        break;
    }
} /* setExpiryTime */

/*! \brief Gets the delivery time.
 *	
 *****************************************************************************/
static void setDeliveryTime(MmsTimeSec currentTime, MmsTimeSec *toSet, 
    MeaDeliveryTimeType dTime,MmsTimeType *type)
{
    MmsTimeSec t;
    MmsTimeSec baseSeconds = 0; 

    #if MEA_CONF_DELIVERY_TIME_RELATIVE
    {
        (void)currentTime;
        baseSeconds = 0;
        *type = MMS_TIME_RELATIVE;
    }
    #else /* absolute */
    {
        baseSeconds = currentTime;
        *type = MMS_TIME_ABSOLUTE;
    } /* if */
    #endif



    switch(dTime)
    {
    case MEA_DELIVERY_TIME_IMMEDIATE:
        /* Do not set he value if no time is set */
        return;
    case MEA_DELIVERY_TIME_1_HOUR:
        t = baseSeconds + MEA_1_HOUR;
        break;
    case MEA_DELIVERY_TIME_12_HOURS:
        t =baseSeconds +  MEA_12_HOURS;
        break;
    case MEA_DELIVERY_TIME_24_HOURS:
        t =baseSeconds +  MEA_1_DAY;
        break;
    default:
        /* Do not set he value if no time is set */
        return;
    }
    *toSet =  t;
}

/*!
 * \brief   Creates an MMS header. 
 * \param hdr           The header to put data in
 * \param p             A set of message properties
 * \param oHdr          The header of the original message
 * \param numBodyParts  The number of body-parts in the new message 
 * \param isSmil        TRUE if the message is of type multi-part-related, 
 *                      otherwise FALSE:
 * \return  TRUE on success, otherwise FALSE
 *****************************************************************************/
static void meaCreateMessageHeader(McrInstance *inst, 
    const MmsGetHeader *oHdr, MSF_BOOL isSmil)
{
#ifndef WAP_SUPPORT
    MeaConfig *cfg;
    int len;
#if (MEA_CFG_SUBJECT_CHARSET == MMS_US_ASCII)
    char *asciiSubjectStart = NULL;     /* Start of US ASCII Subject buffer */
    long asciiLen = 0;                  /* Length of US ASCII Subject string */
    long utf8Len = 0;                   /* Length of UTF-8 Subject string */
#endif
#endif /* ~WAP_SUPPORT */
    
    if (NULL == inst)
    {
        return;
    }

    /* Create Header */
    MEA_CALLOC(inst->msgHdr, sizeof(MmsSetHeader));  
    MEA_CALLOC(inst->msgHdr->contentType, sizeof(MmsContentType));

    if (IS_FORWARD_OP(mcrInstance))
    {
        /*
         *	If we are in forward we need to copy the content type from the
         *  original message to the one we are creating. Assume this simple
         *  process works.
         */
        meaCopyContentType(inst->msgHdr->contentType, oHdr->bodyInfoList.contentType);
    }
    else
    {
        /* SMIL */
        if (isSmil)
        {
            inst->msgHdr->contentType->knownValue = MMS_VND_WAP_MULTIPART_RELATED;
            /* Start rel */
#ifdef WAP_SUPPORT
            SET_START_REL_PARAM(&inst->msgHdr->contentType->params, 
                MEA_SMIL_CONTENT_ID);
#else
            SET_START_REL_PARAM(&inst->msgHdr->contentType->params, 
                MEA_SMIL_FILE_NAME);
#endif
            /* Start type */
            SET_TYPE_REL_PARAM(&inst->msgHdr->contentType->params, 
                MMS_MEDIA_TYPE_STRING_SMIL);
            inst->targetType = MMS_MULTIPART_MESSAGE;
        }
        /* Multipart/Mixed */
        /* Do not set type to Plain Text for messages with 0 bodyparts (empty) */
        /* in order to comply with other brands */
        else
        {
            inst->msgHdr->contentType->knownValue = MMS_VND_WAP_MULTIPART_MIXED;
            inst->targetType = MMS_MULTIPART_MESSAGE;
        }
    }
    
    /* From: */
#ifndef WAP_SUPPORT	 //don't insert from client
    cfg = meaGetConfig();
    if ((NULL != cfg->fromName) && (strlen(cfg->fromName) > 0))
    {   /* John Doe */
        inst->msgHdr->from.name.text = MEA_ALLOC(strlen(cfg->fromName) + 1);
        strcpy(inst->msgHdr->from.name.text, cfg->fromName);
        inst->msgHdr->from.name.charset = MMS_UTF8;
    }
    inst->msgHdr->from.addrType = cfg->addressType; /* 070-12341234 vs foo@bar.net */
    len = (NULL != cfg->fromAddress) ? (int)strlen(cfg->fromAddress) : 0;
    if (len > 0)
    {
        inst->msgHdr->from.address = MEA_ALLOC((unsigned)len + 1);
        strcpy(inst->msgHdr->from.address, cfg->fromAddress);
        inst->msgHdr->fromType = MMS_FROM_ADDRESS_PRESENT;
    }
    else
#endif /* ~WAP_SUPPORT */
    {
        inst->msgHdr->fromType = MMS_FROM_INSERT_ADDRESS;
    }

    /* To/Cc/Bcc, assume this simple copy process works. */
    (void)meaAddrListToMms(inst->msg->msgProperties->to, &inst->msgHdr->to);
    (void)meaAddrListToMms(inst->msg->msgProperties->cc, &inst->msgHdr->cc);
    (void)meaAddrListToMms(inst->msg->msgProperties->bcc, &inst->msgHdr->bcc);

    /* Subject: */
    if ((NULL != inst->msg->msgProperties->subject) &&
        (strlen(inst->msg->msgProperties->subject) > 0))
    {
        switch (MEA_CFG_SUBJECT_CHARSET)
        {
        case MMS_US_ASCII:
#ifdef WAP_SUPPORT
        {
            char *asciiSubjectStart = NULL;	/* Start of US ASCII Subject buffer */
            long asciiLen = 0;				/* Length of US ASCII Subject string */
            long utf8Len = 0;				/* Length of UTF-8 Subject string */
#endif /* WAP_SUPPORT */

            utf8Len = strlen(inst->msg->msgProperties->subject);
        
            /* Get size of US-ASCII string before conversion */        
            if (0 != msf_charset_utf8_to_ascii( inst->msg->msgProperties->subject,
                &utf8Len, NULL, &asciiLen ))
            {
                MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                    MAMCR_DDFFD1BB9FD9B9D3E341FDC2EB2743D0, "(%s) (%d) Calculation of US-ASCII Subject lenght failed!\n", 
                    __FILE__, __LINE__));
                break;      /* Skip Subject */
            }
            else
            {
                /* Allocate memory for US ASCII string + end-of-string */
                inst->msgHdr->subject.text = MEA_ALLOC(asciiLen + 1);
                asciiSubjectStart = inst->msgHdr->subject.text;
            }

            /* Convert Subject string from UTF-8 to US-ASCII */
            if (0 != msf_charset_utf8_to_ascii( inst->msg->msgProperties->subject,
                &utf8Len, inst->msgHdr->subject.text, &asciiLen ))
            {
                MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                    MAMCR_B62EF7F65872476287D8ACDDC353C75E, "(%s) (%d) Subject conversion to US-ASCII failed!\n", 
                    __FILE__, __LINE__));
            }
            else
            {           
                /* Append end-of-string to US ASCII string */
                inst->msgHdr->subject.text = asciiSubjectStart + asciiLen;
                *(inst->msgHdr->subject.text) = '\0';
                inst->msgHdr->subject.text = asciiSubjectStart;

                inst->msgHdr->subject.charset = MMS_US_ASCII;
            }
            break;
#ifdef WAP_SUPPORT
        }
#endif /* WAP_SUPPORT */
        case MMS_UTF8:
#ifdef WAP_SUPPORT
        {
            inst->msgHdr->subject.text = MEA_ALLOC(strlen(inst->msg->msgProperties->subject) + 1);
            strcpy(inst->msgHdr->subject.text, inst->msg->msgProperties->subject);
            inst->msgHdr->subject.charset = MMS_UTF8;
            break;
        }
#endif
        default:
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                MAMCR_9CD9343A5839A77DA7EB9987CAB45783, "(%s) (%d) unsupported character set for subject!\n", 
                    __FILE__, __LINE__));
        }
    }

    /* Date, must be done ahead of expiry and delivery time */
    inst->msgHdr->date = MSF_TIME_GET_CURRENT();
#ifdef WAP_SUPPORT
    {
        extern MSF_UINT32 HDIa_timeLocalToUTC(MSF_UINT32 local_time);
        inst->msgHdr->date = HDIa_timeLocalToUTC(inst->msgHdr->date);
    }
#endif

    /* Read/delivery reports */
    inst->msgHdr->deliveryReport = inst->msg->msgProperties->deliveryReport 
        ? MMS_DELIVERY_REPORT_YES : MMS_DELIVERY_REPORT_NO;
    inst->msgHdr->readReply = inst->msg->msgProperties->readReport 
        ? MMS_READ_REPLY_YES : MMS_READ_REPLY_NO;
    
    /* Message class */
    inst->msgHdr->msgClass.classIdentifier = MMS_MESSAGE_CLASS_NOT_SET;
    
    /* Priority */
    inst->msgHdr->priority = priorityMeaToMms(inst->msg->msgProperties->priority);
    
    /* Sender visibility */
    inst->msgHdr->visibility = visibilityMeaToMms(inst->msg->msgProperties->senderVisibility);
    
    /* Reply Charging */
    replyChargingMeaToMms(inst->msg->msgProperties, inst->msgHdr);

    /* Delivery time (absolute) */
    setDeliveryTime(inst->msgHdr->date, &(inst->msgHdr->deliveryTime), 
        meaGetConfig()->deliveryTime,&inst->msgHdr->deliveryTimeType);

    /* Expiry time */
    setExpiryTime(inst->msgHdr->date, inst->msg->msgProperties->expiryTime,
        &inst->msgHdr->expiryTime, &inst->msgHdr->expiryTimeType);
}

/*!
 * \brief              Creates a MmsBodyParams
 *
 * \param targetType The type of message that are created, see 
 *                   #MmsBodyPartTarget
 * \param currContentType The content type if it already exists, otherwise NULL.
 * \param mediaType  The media type to add as a integer, see MmsKnownMediaType.
 * \param mediaString The media type to add as a string.
 * \param name        The name of the body-part. 
 * \return            The created MmsBodyParams
 *****************************************************************************/
#ifdef WAP_SUPPORT
 static MmsBodyParams *meaCreateBodyParams(MmsBodyPartTarget targetType, 
    const MmsContentType *currContentType, MmsKnownMediaType mediaType, 
    unsigned char *mediaString, const unsigned char *name, unsigned char*data)
#else
static MmsBodyParams *meaCreateBodyParams(MmsBodyPartTarget targetType, 
    const MmsContentType *currContentType, MmsKnownMediaType mediaType, 
    unsigned char *mediaString, const unsigned char *name)
#endif
{
    MmsBodyParams *bp;

    MEA_CALLOC(bp, sizeof(MmsBodyParams));

    if (NULL != currContentType)
    {
        /* Content type does already exist, copy and append some of the new 
           ones */
        meaCopyContentType(&bp->contentType, currContentType);
    }

    /* Add the name of the body-part */
    if (NULL != name)
    {
#ifdef WAP_SUPPORT
        /* Content ID */
	if(targetType==MMS_MULTIPART_MESSAGE && mediaString &&
		(0 == strcmp((const char *)mediaString, MMS_MEDIA_TYPE_STRING_SMIL)))
		SET_CONTENT_ID(&bp->entryHeader, MEA_SMIL_CONTENT_ID);
	else
		SET_CONTENT_ID(&bp->entryHeader, (char *)name);
#else
        /* Content ID */
        SET_CONTENT_ID(&bp->entryHeader, (char *)name);
#endif
        /* Content location */
        SET_CONTENT_LOCATION(&bp->entryHeader, (char *)name);
    }

    switch (targetType)
    {
    case MMS_MULTIPART_MESSAGE:
        /* Set content-type only if no content type exists */
        if (NULL == currContentType)
        {
            if (NULL != mediaString) 
            {
                bp->contentType.knownValue = MMS_VALUE_AS_STRING;
                bp->contentType.strValue = mediaString;
                bp->targetType = MMS_MULTIPART_MESSAGE;
                /* Set SMIL part to charset UTF-8 */
                if (0 == strcmp((const char *)mediaString, 
                    MMS_MEDIA_TYPE_STRING_SMIL))
                {
                    SET_CHARSET_PARAM(&bp->contentType.params);
                }
            }
            else if (MMS_VALUE_AS_STRING != mediaType)
            {
                bp->contentType.knownValue = mediaType;
                bp->targetType = MMS_MULTIPART_MESSAGE;
                bp->contentType.strValue = NULL;
                /* File name */

            }
        }
#ifdef MMS_USE_NAME_PARMS
        /* Always set the file name */
        SET_NAME_PARAM(&bp->contentType.params, (char *)name);
#else
        /* Always set the file name */
        SET_FILENAME_PARAM(&bp->contentType.params, (char *)name);
#endif /* MMS_USE_NAME_PARMS */
        break;
    case MMS_PLAIN_MESSAGE:
        bp->targetType = MMS_PLAIN_MESSAGE;
        break;
    case MMS_MULTIPART_ENTRY:
    default:
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MAMCR_CDBF65DDDCA275D9698F7B95818E0A06, "(%s) (%d) erroneous message type!\n", __FILE__, __LINE__));
        break;
    }
    /* Set charset to UTF-8 if the body part is of type plain text */
    if (MMS_TYPE_TEXT_PLAIN == mediaType)
    {
#ifdef WAP_SUPPORT
	if(data && meaCheckCharacterIsAllEnglish((char*)data)==TRUE)
	{
		addIntParam(&bp->contentType.params, MMS_CHARSET, MMS_US_ASCII);	
	}
        else
#endif
        {
		SET_CHARSET_PARAM(&bp->contentType.params);
        }
    } /* if */

    return bp;
}

/*!
 *\brief Initializes the copy of the body
 *
 * \param dstFilePath Full path to destination file.
 * \param sourceFilePath Full path to source file.
 * \param startPos Start position for data to read from the source file.
 * \param dataSize Size of data in source file.
 * \param instance The current instance 
 *****************************************************************************/
static void meaCopyBody(const char *dstFilePath, const char *sourceFilePath, 
    MSF_UINT32 startPos, MSF_UINT32 dataSize, McrInstance *instance)
{
    MSF_UINT32 bytesToRead = 0;
    
    MEA_FREE(instance->origMsg->copyBuffer);
    MEA_CALLOC(instance->origMsg->copyBuffer, MEA_ASIO_COPY_BUFFER_SIZE);
    instance->origMsg->copyBufferSize = MEA_ASIO_COPY_BUFFER_SIZE;
    
    instance->origMsg->readPos       = (int)startPos;
    instance->origMsg->leftToRead    = dataSize;

    /* create read async operation */
    instance->origMsg->asioReadHandle = 
        meaAsyncOperationStart(sourceFilePath, MEA_MCR_FSM, 0L, 
        MEA_SIG_MCR_ASIO_READ_RSP, MEA_ASYNC_MODE_READ);
    
     /* create write async operation */
    instance->origMsg->asioWriteHandle = 
        meaAsyncOperationStart(dstFilePath, MEA_MCR_FSM, 0L, 
        MEA_SIG_MCR_ASIO_WRITE_RSP, MEA_ASYNC_MODE_APPEND);

    instance->state = COPY_BODY;

    /* read first part of the file */
    if (instance->origMsg->leftToRead < instance->origMsg->copyBufferSize)
    {
        bytesToRead = (unsigned)instance->origMsg->leftToRead;
    }
    else
    {
        bytesToRead = (unsigned)instance->origMsg->copyBufferSize;
    } /* if */
    meaAsyncRead( instance->origMsg->asioReadHandle, 
        (MSF_INT32)instance->origMsg->readPos, instance->origMsg->copyBuffer, 
        bytesToRead);

} /* meaCopyBody */

/*!
 *\brief Checks the result of the read operation.
 *
 * \param instance Instance information, e.g. information about the 
 *         current transaction.
 * \param bytesRead Number of bytes read in last read operation.
 * \param result Result of the read operation operation
 *
 * \return TRUE if successful, else FALSE
 *****************************************************************************/
static MSF_BOOL handleReadOperation(const McrInstance *instance, int bytesRead, 
    MeaAsioResult result)
{
    /*lint -e{788} */
    switch (result)
    {
        case MEA_ASIO_RESULT_OK:
        case MEA_ASIO_RESULT_EOF:
            /* write data to file */
            instance->origMsg->readPos += (MSF_INT32)bytesRead;
            instance->origMsg->leftToRead -= (MSF_UINT32)bytesRead;
            instance->origMsg->sizeToWrite = (MSF_INT32)bytesRead;
            return TRUE;
        case MEA_ASIO_RESULT_FILE_NOT_FOUND:
        case MEA_ASIO_RESULT_ERROR:
        case MEA_ASIO_RESULT_INSUFFICIENT_PERSISTENT_STORAGE:
            return FALSE;
        case MEA_ASIO_RESULT_DELAYED:
        default:
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                MAMCR_9F073108904D8A65BD9504A0F969E7DE, "MEA_SIG_MCR_ASIO_READ_RSP invalid result code (%d)\n", 
                result));
            return FALSE;
    } /* switch */
} /* handleReadOperation */

/*!
 * \brief Checks the result of the write operation.
 * \param result Result of the write operation
 * \return TRUE if successful, else FALSE
 *****************************************************************************/
static MSF_BOOL handleWriteOperation(MeaAsioResult result)
{
    /*lint -e{788} */
    switch(result)
    {
        case MEA_ASIO_RESULT_OK:
        case MEA_ASIO_RESULT_EOF:
            return TRUE;
        case MEA_ASIO_RESULT_FILE_NOT_FOUND:
        case MEA_ASIO_RESULT_ERROR:
        case MEA_ASIO_RESULT_INSUFFICIENT_PERSISTENT_STORAGE:
            return FALSE;
        case MEA_ASIO_RESULT_DELAYED:
        default:
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                MAMCR_2BE1951D216E87139E9F8EF89ADD5924, "MEA_SIG_MCR_ASIO_WRITE_RSP invalid result code (%d)\n", 
                result));
            return FALSE;
    } /* switch */
} /* handleWriteOperation */

/*! \brief Release the temporary buffer used for SMIL messages.
 *	
 * \param instance The current instance.
 *****************************************************************************/
static void releaseSmilBuffer(McrInstance *instance)
{
    if ((NULL != instance) && (NULL != instance->tmpBuffer))
    {
        MEA_FREE(instance->tmpBuffer);
        instance->tmpBuffer = NULL;
        instance->tmpSize = 0;
    }
}

#ifdef MMS_SLIM_MEM
extern unsigned char *createBodyPartHeader(MSF_UINT8 modId, MSF_UINT32 *encHeaderLen,
    const MmsBodyParams *bodyParams, MSF_UINT32 size, MmsResult *result);

extern MmsResult writeDataToFile( MSF_UINT8 modId, unsigned char **buf, 
    MSF_UINT32 *sizeLeft, int fileHandle, MSF_INT32 *filePos);

/*
 * Set a value to a part of the message body
 *****************************************************************************/
static MmsResult MEAlib_setMessageBody (MSF_UINT8 modId, MmsBodyParams *params,
    unsigned char *data, MSF_UINT32 dataSize, MmsMsgHandle *msg, 
    MmsTransactionHandle *transaction)
{
    MmsResult result = MMS_RESULT_OK;
    MmsTransaction *tHandle = NULL;
    MmsMessage *mHandle = NULL;
    MSF_UINT32 encHeaderLen = 0;
    unsigned char *encHeader = NULL;   /* buffer to hold the encoded "header" */

    tHandle = (MmsTransaction *) *transaction;
    mHandle = (MmsMessage *) *msg;

    switch ( tHandle->state)
    {
        case 1:
            if ( params->targetType != MMS_PLAIN_MESSAGE)
            {
                if ( ( encHeader = createBodyPartHeader( modId, &encHeaderLen, 
                params, dataSize, &result)) == NULL)
                {
                    /* unable to create body header */
                    return result;
                } /* if */

                tHandle->buf = encHeader;
                tHandle->bufferPos = tHandle->buf;
                tHandle->sizeOfBuf = (int)encHeaderLen;
                tHandle->bytesLeft = encHeaderLen;
                tHandle->filePos = -1;  /* -1 = Append */
                tHandle->state = 2;     /* next state */
            } /* if */
            tHandle->fileHandle = mHandle->fileHandle;
            tHandle->isMessageFile = TRUE;
        /*lint -fallthrough*/
        case 2:
            if ( params->targetType != MMS_PLAIN_MESSAGE)
            {
                /* write body header */
                result = writeDataToFile( modId, 
                    (unsigned char **)&tHandle->bufferPos, 
                    &tHandle->bytesLeft, tHandle->fileHandle, &tHandle->filePos);
                if ( (result != MMS_RESULT_OK))
                {
							if(result != MMS_RESULT_DELAYED)
							{
								MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_LOW, modId, MAMCR_2A803716D66268F616EA6C618F303CD7, "MEAlib_setMessageBody: fail to write file,ret%d",result));
							}
                    return result;
                }/* if */
            
                /* body header written - free memory */
                MSF_MEM_FREE( modId, tHandle->buf);
                tHandle->buf = NULL;
            } /* if */
            
            tHandle->bufferPos = data;
            tHandle->bytesLeft = dataSize;
            tHandle->filePos = -1; /* append */
            tHandle->state = 3;
            break;
        /*lint -fallthrough*/
        case 3:
            tHandle->bufferPos = data;
            tHandle->bytesLeft = dataSize;
            tHandle->filePos = -1; /* append */
            /* write body data */
            result = writeDataToFile( modId, 
                (unsigned char **)&tHandle->bufferPos, 
                &tHandle->bytesLeft, tHandle->fileHandle, &tHandle->filePos);
            if ( result != MMS_RESULT_OK)
            {
                return result;
            } /* if */
            break;
        default:
            /* unknown "state" should not be here */
            result = MMS_RESULT_ERROR;
            MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_LOW, modId, MAMCR_882E558B242248B3CB2B0CEA3AA59A9F, "MEAlib_setMessageBody: received unknown state"));
            break;
    } /* switch */

    MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_LOW, modId, 
        MAMCR_4985CAC5E5B189493EC2B50C38E4DD44, "MEAlib_setMessageBody( fileHandle=%d, size=%d, targetType=%d)\n", 
        tHandle->fileHandle, dataSize, params->targetType));
    
    return result;
    
} /* MMSlib_setMessageBody */
#endif /* MMS_SLIM_MEM */

/*!
 * \brief  rename the savename if two media objects have the same name
 *         but they are located in two folders
 * \param  moItems   instance->msg->smilInfo->mediaObjects
 * \return 
 *****************************************************************************/
MeaMcrResult meaCreateSavename(MeaMoDataItem *moItems, MeaMoDataItem *mo)
{
    char objectFileName[45];
    MeaMoDataItem *to_check;
    MSF_BOOL renamed, shallBeTransform;

    MEA_CFREE(mo->savename);
    mo->savename = msf_cmmn_strdup(MSF_MODID_MEA, mo->name);
    meaExtractFileName(mo->savename);
    shallBeTransform = !meaCheckCharacterIsAllEnglish(mo->savename);

    if(shallBeTransform)
    {
        memset(objectFileName,0x00,40);                             
        sprintf(objectFileName, "%lx%s", (long)(mmsWapGetTransactionId()),strrchr(mo->savename,'.'));
        MEA_CFREE(mo->savename);
        mo->savename=msf_cmmn_strdup(MSF_MODID_MEA, objectFileName);
        if(!mo->savename)
            return MEA_MCR_FAILED;
    }

    /* rename when the savenames are idnetical */

    to_check = moItems;
    while(to_check != NULL && to_check->savename != NULL)
    {
        renamed = FALSE;
        if(strcmp(to_check->savename, mo->savename) == 0 && 
           strcmp(to_check->name, mo->name) != 0 )
        {
            renamed = TRUE;
            MEA_CFREE(mo->savename);                                
            mo->savename = meaCreateFileNameFromType(mo->content.type);
        }
       
        if(renamed == FALSE)
        {
            to_check = to_check->next;
        }
        else
        {
            to_check = moItems;
        }
    }/* while(to_check != NULL) */
    return MEA_MCR_OK;
}


/*!
 * \brief  Creates a message by filling in an MMS Header and all necessary 
 *         data, based on data from the GUI and the configuration in used. 
 *         The buffers are free'd here. 
 * \param  instance The current message cration instance.
 * \return See #MeaMcrResult.
 *****************************************************************************/
static int meaCreateMessageFSM(McrInstance *instance)
{
    MSF_UINT32 numBodyParts;
    int fHandle;
    int index;
    char *strValue;
    MmsKnownMediaType mediaType;
    MmsResult res;
    
    if (NULL == instance)
    {
        return MEA_MCR_FAILED;
    }

    switch (instance->state)
    {    
    case CREATE_MSG_ID:
        /*
         *	Start by creating a message in MMS
         */
#ifdef __UNIFIED_COMPOSER_SUPPORT__
        MMA_createMessage(MSF_MODID_MEA, instance->msgType);
        
#else
        MMSif_createMessage(MSF_MODID_MEA, instance->msgType);       
#endif

        instance->state = CREATE_HEADER;
        return MEA_MCR_WAIT_RSP; /* wait for msgId */

    case CREATE_HEADER:
        /*
         *	Message created, generate header
         */
        meaPmSetProgress(10, NULL);
        instance->mmsResult = MMSlib_messageOpen(MSF_MODID_MEA, 
            instance->msgId, instance->msgType, &instance->msgHandle);
        if (MMS_RESULT_OK != instance->mmsResult)
        {
            return MEA_MCR_FAILED;
        }
        
        instance->mmsResult = MMSlib_transactionOpen(MSF_MODID_MEA, 
            &instance->tHandle);
        if (MMS_RESULT_OK != instance->mmsResult)
        {
            return MEA_MCR_FAILED;
        }
        /* on MMS_RESULT_OK, just keep on going */

        if (IS_FORWARD_OP(instance))
        {
            /* Allocate memory for the header */
            MEA_CALLOC(instance->origMsg->hdr, sizeof(MmsGetHeader));
            /* Prepare to read the message header */
            if (MMS_RESULT_OK != MMSlib_messageOpen(MSF_MODID_MEA, 
                instance->origMsg->msgId, instance->origMsg->fileType, 
                &instance->origMsg->msgHandle))
            {
                return MEA_MCR_FAILED;
            }
            if (MMS_RESULT_OK != MMSlib_transactionOpen(MSF_MODID_MEA, 
                &instance->origMsg->tHandle))
            {
                return MEA_MCR_FAILED;
            }
            /* Read the header in the next state (to support async IO) */
            instance->state = READ_HEADER;
            /* Continue execution */
            (void)MEA_SIGNAL_SENDTO(MEA_MCR_FSM, MEA_SIG_MCR_CONTINUE);
        }
        else
        {
            instance->state = WRITE_HEADER;
            /* Do not execute the entire work at once */
            (void)MEA_SIGNAL_SENDTO(MEA_MCR_FSM, MEA_SIG_MCR_FILE_NOTIFY);
        }
        return MEA_MCR_WAIT_RSP;

    case READ_HEADER:
        /* The header of the originating message is needed in order to set
         * the correct content type and number of bodyparts for forwarding
         */
        meaPmSetProgress(20, NULL);
        res = MMSlib_getMessageHeader(MSF_MODID_MEA, instance->origMsg->hdr, 
            &instance->origMsg->msgHandle, &instance->origMsg->tHandle);
        if (MMS_RESULT_OK == res)
        {
            /* Close transaction */
            if (NULL != instance->origMsg->tHandle)
            {
                (void)MMSlib_transactionClose(MSF_MODID_MEA, 
                    &instance->origMsg->tHandle);
                instance->origMsg->tHandle = NULL;
            }
            /* Close the message */
            if (NULL != instance->origMsg->msgHandle)
            {
                (void)MMSlib_messageClose(MSF_MODID_MEA, 
                    &instance->origMsg->msgHandle);
                instance->origMsg->msgHandle = NULL;
            }     
            instance->state = WRITE_HEADER;
            /* Continue execution */
            (void)MEA_SIGNAL_SENDTO(MEA_MCR_FSM, MEA_SIG_MCR_CONTINUE);
        }
        else if (MMS_RESULT_DELAYED == res) 
        {
            /* Try to read the message again when a delayed file operation
               signal has been received */
            meaAsyncRegister(MMSlib_getFileHandle(MSF_MODID_MEA, 
                &instance->origMsg->tHandle), MEA_MCR_FSM, 
                MEA_SIG_MCR_FILE_NOTIFY, 0);
        }
        else
        {
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
                MAMCR_0061C98DF6DA82B5833195C07ED75D52, "(%s) (%d) failed to open message header!\n", __FILE__, 
                __LINE__));
            return MEA_MCR_FAILED;
        }
        return MEA_MCR_WAIT_RSP;

    case WRITE_HEADER:
        meaPmSetProgress(30, NULL);
        /* Create header, use 'name' as SMIL-indication */
        if (IS_FORWARD_OP(instance))
        {
            numBodyParts = instance->origMsg->hdr->bodyInfoList.numOfEntries;
        }
        else
        {
            /*
             *	 Calculate number of body-parts
             */
            if ((NULL != instance->msg->smilInfo) && 
                (meaIsSmilValid(instance->msg->smilInfo))) 
            {
                /* SMIL, i.e. multipart/related, make room for the SMIL */
                numBodyParts = 
                    meaGetMoCount(instance->msg->smilInfo->mediaObjects) + 1;
            }
            else if ((NULL != instance->msg->smilInfo) && 
                     (NULL != instance->msg->smilInfo->mediaObjects))
            {
                /* Multipart/mixed or text - just the media objects or text */
                numBodyParts = 
                    meaGetMoCount(instance->msg->smilInfo->mediaObjects);

                if ((1 == numBodyParts) && (MEA_MEDIA_TYPE_TEXT_PLAIN == 
                    instance->msg->smilInfo->mediaObjects->content.type)) 
                {
                    /*
                     *	 When there is only one bodypart and it's text; send 
                     *   it as a plain/text message w/o body-_PART_s
                     */
                    numBodyParts = 0;
                }
            }
            else
            {
                /* There are no bodyparts! Save anyway. */
                numBodyParts = 0;
            }

        }
        if ((NULL == instance->msgHdr) && 
            (NULL != instance->msg->msgProperties))
        {
            meaCreateMessageHeader(instance, 
                IS_FORWARD_OP(instance) ? instance->origMsg->hdr : NULL, 
                meaIsSmilValid(instance->msg->smilInfo));
        }
        else
        {
            return MEA_MCR_FAILED;
        }

        /* Set the generated header */
		//When text is only ascii characters, set charset from utf-8 to us-ascii. GH 20040428
		//When text consists of chinese words, it add as Quote <Octet 127> tag in the front of text. GH 20040429
#ifdef WAP_SUPPORT
        {
            int i=0;
            char *new_subject_p=NULL;
            int subjectLen=0;
            if(instance->msgHdr->subject.text)
            {
                subjectLen=strlen(instance->msgHdr->subject.text);
            }
            instance->msgHdr->subject.charset=MMS_US_ASCII;
            while(i<subjectLen)
            {
                if((unsigned short)*(instance->msgHdr->subject.text+i)>0x7F)
                {
                    instance->msgHdr->subject.charset=MMS_UTF8;										
                    if(i==0)
                    {
                        new_subject_p=MSF_MEM_ALLOC(MSF_MODID_MEA,subjectLen+2);
                        if(new_subject_p)
                        {
                            memset(new_subject_p,0x00,subjectLen+2);
                            *new_subject_p=0x7F; //Add <Quote> tag. It follows WAP_230_WSP_Spec. GH
                            strcpy(new_subject_p+1,instance->msgHdr->subject.text);
                            MSF_MEM_FREE(MSF_MODID_MEA,instance->msgHdr->subject.text);
                            instance->msgHdr->subject.text=new_subject_p;
                        }
                    }
                    break;
                }
                i++;
            }

            if(instance->msgHdr->subject.charset == MMS_US_ASCII && instance->msgHdr->subject.text != NULL)  /* IOT: Convert CRLF to space (RFC822: no CRLF for E-mail subject) */
            {
                int i = 0, j = 0;
                new_subject_p = msf_cmmn_strdup(MSF_MODID_MEA, instance->msgHdr->subject.text);
                
                while(i < subjectLen + 1)
                {
                    if(*(new_subject_p + i) == 0xD && *(new_subject_p + i + 1) == 0xA)
                    {
                        *(instance->msgHdr->subject.text + j) = 0x20;
                        i++;
                    }
                    else
                    {
                        *(instance->msgHdr->subject.text + j) = *(new_subject_p + i);
                    }
                    i++;
                    j++;
                }
                MSF_MEM_FREE(MSF_MODID_MEA,new_subject_p);
            }
        }
#endif	/* WAP_SUPPORT */		
             instance->msgHdr->date = 0; 
        instance->mmsResult = MMSlib_setMessageHeader(MSF_MODID_MEA, 
            numBodyParts, instance->msgHdr, meaGetConfig()->proxyVersion,
            &instance->msgHandle, &instance->tHandle);
        if (MMS_RESULT_DELAYED == instance->mmsResult)
        {
            fHandle = MMSlib_getFileHandle(MSF_MODID_MEA, &instance->tHandle);
            meaAsyncRegister(fHandle, MEA_MCR_FSM, MEA_SIG_MCR_FILE_NOTIFY, 0);
            return MEA_MCR_DELAYED; /* Async! .. we'll arrive here again, soon*/
        }
        else if (MMS_RESULT_OK != instance->mmsResult)
        {
            return MEA_MCR_FAILED;
        }
        /* on MMS_RESULT_OK, keep going */

        MMSlib_freeMmsSetHeader(MSF_MODID_MEA, instance->msgHdr);
        MEA_FREE(instance->msgHdr);
        instance->msgHdr = NULL;

        /* prep for next state */
        if ((MMS_RESULT_OK != (instance->mmsResult = MMSlib_transactionClose(
            MSF_MODID_MEA, &instance->tHandle))))
        {
            return MEA_MCR_FAILED;
        }
#ifdef WAP_SUPPORT //Write a blank slide to message, when user doesn't insert any media objects.
        if(numBodyParts==0&&!IS_FORWARD_OP(instance))
        {
            MSF_UINT8 buffer[1000];//Please doesn't modify the value.
            int bytesInbuffer=0;
            char *filepath=NULL;
            int filehandle=-1;
            bytesInbuffer=generateSMIL(buffer,TRUE);
            filepath=MMSlib_getMessageFullPath(MSF_MODID_MEA, instance->msgId, instance->msgType);
            if(filepath)
            {
                filehandle=MSF_FILE_OPEN(MSF_MODID_MEA,filepath,HDI_FILE_SET_WRONLY| HDI_FILE_SET_CUSTOM_BLOCKING,0);
                if(filehandle>=0)
                {
                    instance->bodynum_pos=MSF_FILE_GETSIZE(filepath)+28;
                    MSF_FILE_SEEK(filehandle,MSF_FILE_GETSIZE(filepath)-3,HDI_FILE_SEEK_SET);
                    if(MSF_FILE_WRITE(filehandle,buffer,bytesInbuffer)!=bytesInbuffer)
                    {
                        MSF_MEM_FREE(MSF_MODID_MEA,filepath);
                        MSF_FILE_CLOSE(filehandle);
			instance->bodynum_pos=0;
                        return MEA_MCR_FAILED;
                    }	
                }
                else
                {
                    MSF_MEM_FREE(MSF_MODID_MEA,filepath);
                    return MEA_MCR_FAILED;
                }
            }
            else
            {
                return MEA_MCR_FAILED;
            }
            MSF_MEM_FREE(MSF_MODID_MEA,filepath);
            MSF_FILE_CLOSE(filehandle);        	
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,  MAMCR_9DBCE52437CC70F9428F6AE9FED49343, "(%s) (%d) Insert a blank slide successfully.\n", __FILE__, __LINE__));
            instance->state = FINALISE_MSG;
            (void)MEA_SIGNAL_SENDTO(MEA_MCR_FSM, MEA_SIG_MCR_FILE_NOTIFY);
            return MEA_MCR_WAIT_RSP;
        }
#endif /* WAP_SUPPORT */
        if (!IS_FORWARD_OP(instance))
        {
            if (MMS_RESULT_OK != (instance->mmsResult = MMSlib_transactionOpen(
                MSF_MODID_MEA, &instance->tHandle)))
            {
                return MEA_MCR_FAILED;
            }
        }
        /*  
         *  Write message parts (bodyparts), 
         *  start copying them (forwarding), 
         *  or finalize message
         */
#ifdef WAP_SUPPORT		/* we allow empty slide */
        if ((NULL != instance->msg->smilInfo) && IS_FORWARD_OP(instance) == FALSE)
#else
        if ((NULL != instance->msg->smilInfo) && 
            (NULL != instance->msg->smilInfo->mediaObjects) && IS_FORWARD_OP(instance) == FALSE)
#endif
        {
            instance->state = WRITE_SMIL_PART;//WRITE_BODY_PART;
            instance->currentMo = instance->msg->smilInfo->mediaObjects;
#ifdef WAP_SUPPORT		
    /* Start to transform non-ascii file name to ascii file name */
			{	
				MeaMoDataItem *mo=instance->currentMo;

				while(mo)
				{
#ifdef MMS_SLIM_MEM
					if(((MmsTransaction*)instance->tHandle)->state!=3 && 
						mo->acessType==meaMoInOneFile)
					{
						if(mo->file)
						{
							if(mo->file->path)
							{
								MEA_FREE(mo->file->path);
							}
							MEA_FREE(mo->file);
						}
						MEA_CALLOC(mo->file,sizeof(MeaMoFileRef));
						if(!mo->file)
							return MEA_MCR_FAILED;
                        mo->file->path = msf_cmmn_strdup(MSF_MODID_MEA, mo->name);
						if(!mo->file->path)
							return MEA_MCR_FAILED;
						mo->file->size=mo->size;			
					}
#endif /* MMS_SLIM_MEM */

                    if (meaCreateSavename(instance->msg->smilInfo->mediaObjects,
                        mo) == MEA_MCR_FAILED)
                    {
                        return MEA_MCR_FAILED;
                    }
					mo=mo->next;
		        }
			}
#endif /* WAP_SUPPORT */
        }
        else if (IS_FORWARD_OP(instance))
        {
            /*
             *	On forward we need to open the old message and copy
             *  the entire body.
             */
            instance->origMsg->dstFile = MMSlib_getMessageFullPath(
                MSF_MODID_MEA, instance->msgId, instance->msgType);
            
            instance->origMsg->srcFile = MMSlib_getMessageFullPath(
                MSF_MODID_MEA, instance->origMsg->msgId, 
                instance->origMsg->fileType);
            if (NULL == instance->origMsg->dstFile || 
                NULL == instance->origMsg->srcFile) 
            {
                return MEA_MCR_FAILED;
            }
            /*
             *	We must close the MMS here since we will do the body copy
             *  manually with AsyncIO.
             */
            instance->mmsResult = MMSlib_messageClose(MSF_MODID_MEA, 
                &instance->msgHandle);
            if (MMS_RESULT_OK != instance->mmsResult)
            {
                return MEA_MCR_FAILED;
            }
            if (numBodyParts > 0)
            {
                /*  SMIL or Multipart/Mixed message
                 *	Copy the body from the original file so it will be exactly
                 *  the same. We must add +1 to the start position of the body
                 *  to go pass the number of body parts because this is added
                 *  by the call to MMSlib_setMessageHeader()
                 */
                meaCopyBody(instance->origMsg->dstFile, 
                    instance->origMsg->srcFile, 
                    instance->origMsg->hdr->bodyInfoList.startPos + 1, 
                    instance->origMsg->hdr->bodyInfoList.size - 1, instance);
            }
            else
            {
                /*  Text/Plain Message
                 *	Copy the body from the original file so it will be exactly
                 *  the same.
                 */
                meaCopyBody(instance->origMsg->dstFile, 
                    instance->origMsg->srcFile, 
                    instance->origMsg->hdr->bodyInfoList.startPos, 
                    instance->origMsg->hdr->bodyInfoList.size, instance);
            }
            instance->state = COPY_BODY;
        }
        else
        {
            instance->state = FINALISE_MSG;
        }

        /* Do not execute the entire work at once */
        (void)MEA_SIGNAL_SENDTO(MEA_MCR_FSM, MEA_SIG_MCR_FILE_NOTIFY);
        return MEA_MCR_WAIT_RSP;

    case WRITE_BODY_PART:
        index = meaGetMoIndex(instance->msg->smilInfo->mediaObjects, 
            instance->currentMo);
        if (-1 == index)
        {
            return MEA_MCR_FAILED;
        } /* if */
        /* Set progress to somewhere between 55 and 90 percent */
        meaPmSetProgress(55 + 35 * (unsigned int)index / meaGetMoCount(
            instance->msg->smilInfo->mediaObjects), NULL);
        strValue = NULL;
        /* Create body params if they are not previously created */
        if (NULL == instance->bodyParams)
        {
            if (meaMediaTypeMeaToMms(instance->currentMo->content.type, 
                &mediaType, &strValue))
            {
                /* Content type is known */
#ifdef WAP_SUPPORT
                if (NULL == (instance->bodyParams = meaCreateBodyParams(
                    instance->targetType, NULL, mediaType, 
                    (unsigned char *)strValue, 
                    (unsigned char *)instance->currentMo->savename,
                    (unsigned char *)instance->currentMo->data)))
#else
                if (NULL == (instance->bodyParams = meaCreateBodyParams(
                    instance->targetType, NULL, mediaType, 
                    (unsigned char *)strValue, 
                    (unsigned char *)instance->currentMo->name)))

#endif
                {
                    return MEA_MCR_FAILED;
                }
            }
            else
            {
                /* No known media type, use the content type from the 
                   originating message */
#ifdef WAP_SUPPORT
                if (NULL == (instance->bodyParams = meaCreateBodyParams(
                    instance->targetType, 
                    instance->currentMo->content.origType, mediaType, 
                    (unsigned char *)strValue, 
                    (unsigned char *)instance->currentMo->savename,
                    (unsigned char *)instance->currentMo->data)))
#else
                if (NULL == (instance->bodyParams = meaCreateBodyParams(
                    instance->targetType, 
                    instance->currentMo->content.origType, mediaType, 
                    (unsigned char *)strValue, 
                    (unsigned char *)instance->currentMo->name)))

#endif
                {
                    return MEA_MCR_FAILED;
                }
            }
        }        
        /* Write message */

#ifdef WAP_SUPPORT //For FTA test only

#ifdef __GEMINI__
	if(is_test_sim(0x00) && instance->currentMo->content.type==MEA_MEDIA_TYPE_TEXT_PLAIN)
#else
	if(is_test_sim() && instance->currentMo->content.type==MEA_MEDIA_TYPE_TEXT_PLAIN)
#endif
	{

		if(strcmp((char*)instance->currentMo->data,"fta_utf8")==0 ||
		   strcmp((char*)instance->currentMo->data,"FTA_UTF8")==0)
		{

			const unsigned char mms_fta_utf[]={
				0x46, 0x72, 0x65, 0x6E, 0x63, 0x68, 0x20, 0xC3, 0xAA, 0x20, 0x68, 0x61, 0x73, 0x20, 0x61, 0x20,
				0x72, 0x6F, 0x6F, 0x66, 0x20, 0x6F, 0x76, 0x65, 0x72, 0x20, 0x74, 0x68, 0x65, 0x20, 0x65, 0x2E, 
				0x20, 0x47, 0x65, 0x72, 0x6D, 0x61, 0x6E, 0x20, 0xC3, 0xBC, 0x20, 0x69, 0x73, 0x20, 0x61, 0x20, 
				0x75, 0x20, 0x77, 0x69, 0x74, 0x68, 0x20, 0x74, 0x77, 0x6F, 0x20, 0x64, 0x6F, 0x74, 0x73, 0x2E,
				0x20, 0x50, 0x6F, 0x6C, 0x69, 0x73, 0x68, 0x20, 0xC5, 0x82, 0x20, 0x69, 0x73, 0x20, 0x61, 0x6E,
				0x20, 0x6C, 0x20, 0x77, 0x69, 0x74, 0x68, 0x20, 0x61, 0x20, 0x2F, 0x20, 0x61, 0x63, 0x72, 0x6F,
				0x73, 0x73, 0x2E, 0x00};

			if(instance->currentMo->data)
				MEA_FREE(instance->currentMo->data);
			instance->currentMo->size=strlen((char*)mms_fta_utf)+1;
			instance->currentMo->data=MEA_ALLOC(instance->currentMo->size);
			memset(instance->currentMo->data, 0x00, instance->currentMo->size);
			kal_mem_cpy(instance->currentMo->data,mms_fta_utf,instance->currentMo->size);	
		}
		else if(strcmp((char*)instance->currentMo->data,"fta_usascii")==0||
				strcmp((char*)instance->currentMo->data,"FTA_USASCII")==0)
		{
			const unsigned char mms_fta_usascii[]={
				0x54, 
				0x68, 0x65, 0x20, 0x71, 0x75, 0x69, 0x63, 0x6B, 0x20, 0x62, 0x72, 0x6F, 0x77, 0x6E, 0x20, 0x66,
				0x6F, 0x78, 0x20, 0x6A, 0x75, 0x6D, 0x70, 0x65, 0x64, 0x20, 0x6F, 0x76, 0x65, 0x72, 0x20, 0x74,
				0x68, 0x65, 0x20, 0x6C, 0x61, 0x7A, 0x79, 0x20, 0x64, 0x6F, 0x67, 0x20, 0x31, 0x32, 0x33, 0x34,
				0x35, 0x36, 0x37, 0x38, 0x39, 0x30, 0x2F, 0x21, 0x28, 0x29, 0x0D, 0x0A, 0x00};
				
			if(instance->currentMo->data)
		       		MEA_FREE(instance->currentMo->data);
				instance->currentMo->size=strlen((char*)mms_fta_usascii)+1;
			instance->currentMo->data=MEA_ALLOC(instance->currentMo->size);
				memset(instance->currentMo->data, 0x00, instance->currentMo->size);
			kal_mem_cpy(instance->currentMo->data,mms_fta_usascii,instance->currentMo->size);	

		}	
	}
#endif /* WAP_SUPPORT */





#ifdef MMS_SLIM_MEM
		if(instance->currentMo->acessType==meaMoInMemory)
		{

			/* Remove the NULL terminator in text object */
			if(instance->currentMo->content.type==MEA_MEDIA_TYPE_TEXT_PLAIN &&
				(instance->currentMo->size>1) && 
				*(instance->currentMo->data+instance->currentMo->size-1)==0x00 &&
				*(instance->currentMo->data)!=0x00)
			{				
					/* Write message */
					instance->mmsResult = MMSlib_setMessageBody(MSF_MODID_MEA, 
							instance->bodyParams, instance->currentMo->data, 
							instance->currentMo->size-1, &instance->msgHandle, 
							&instance->tHandle);
			}
			else
			{
			    /* Write message */
			    instance->mmsResult = MMSlib_setMessageBody(MSF_MODID_MEA, 
				    instance->bodyParams, instance->currentMo->data, 
				    instance->currentMo->size, &instance->msgHandle, 
				    &instance->tHandle);
		    }
			if(MMS_RESULT_DELAYED == instance->mmsResult)
			{
            fHandle = MMSlib_getFileHandle(MSF_MODID_MEA, &instance->tHandle);
            meaAsyncRegister(fHandle, MEA_MCR_FSM, MEA_SIG_MCR_FILE_NOTIFY, 0);
            return MEA_MCR_DELAYED; /* Async! .. we'll arrive here again, soon*/
			}
			else if (MMS_RESULT_OK != instance->mmsResult)
			{
            return MEA_MCR_FAILED;
			}
        /* on MMS_RESULT_OK, keep going */
		}
		/*Write body headers to file*/
		if(((MmsTransaction*)instance->tHandle)->state!=3 && 
			(instance->currentMo->acessType==meaMoInOneFile|| instance->currentMo->acessType==meaMoInPartOfFile))
        {
            /* Write message */
				instance->mmsResult = MEAlib_setMessageBody(MSF_MODID_MEA, 
					instance->bodyParams, NULL, 
					instance->currentMo->size, &instance->msgHandle, 
					&instance->tHandle);

     			if(MMS_RESULT_DELAYED == instance->mmsResult)
      		{
            	fHandle = MMSlib_getFileHandle(MSF_MODID_MEA, &instance->tHandle);
            	meaAsyncRegister(fHandle, MEA_MCR_FSM, MEA_SIG_MCR_FILE_NOTIFY, 0);
            	return MEA_MCR_DELAYED; /* Async! .. we'll arrive here again, soon*/
        		}
        		else if (MMS_RESULT_OK != instance->mmsResult)
        		{
		       		return MEA_MCR_FAILED;
      	  	}
	        /* on MMS_RESULT_OK, keep going */					
				if(((MmsTransaction*)instance->tHandle)->state==3)
				{
					instance->currentMo->meaObjectReader= 
							meaAsyncOperationStart(instance->currentMo->file->path, MEA_MCR_FSM, 0L, 
	            		MEA_SIG_MCR_CREATE_MSG_READ_MO_FINISHED, MEA_ASYNC_MODE_READ);
				}
    		
				if(instance->currentMo->data)
				{
		        MEA_FREE(instance->currentMo->data);
		        instance->currentMo->data = NULL;
            }	
	    }

		/* Read media data from file*/
		if(instance->currentMo->data == NULL && 
			(instance->currentMo->acessType == meaMoInOneFile ||instance->currentMo->acessType==meaMoInPartOfFile))
	    {
		    instance->currentMo->data = (unsigned char*)MEA_ALLOC(MMS_MAX_CHUNK_SIZE);
		    if (!instance->currentMo->data)
			    return MEA_MCR_FAILED;
			instance->currentMo->file->tmppos = instance->currentMo->file->pos;
			instance->currentMo->file->tmpsize = instance->currentMo->file->size;
		    if (instance->currentMo->size>=MMS_MAX_CHUNK_SIZE)
		    {
				instance->currentMo->bytesInBuf = MMS_MAX_CHUNK_SIZE;
				//instance->currentMo->size=MMS_MAX_CHUNK_SIZE;
				meaAsyncRead(instance->currentMo->meaObjectReader, instance->currentMo->file->pos, instance->currentMo->data, instance->currentMo->bytesInBuf);					
		    }
		    else
		    {
			    meaAsyncRead(instance->currentMo->meaObjectReader, instance->currentMo->file->pos, instance->currentMo->data, instance->currentMo->size);				
		    }
		    return MEA_MCR_DELAYED;
	    }        
		/* Write media data to file*/
		if ((instance->mmsResult==MMS_RESULT_OK || instance->mmsResult==MMS_RESULT_DELAYED) &&
			((MmsTransaction*)instance->tHandle)->state == 3 && 
			(instance->currentMo->acessType == meaMoInOneFile ||instance->currentMo->acessType==meaMoInPartOfFile))
	    {	
			if(MMS_RESULT_DELAYED == instance->mmsResult)
			{
				instance->mmsResult = MEAlib_setMessageBody(MSF_MODID_MEA,
					instance->bodyParams, ((MmsTransaction*)instance->tHandle)->bufferPos, 
			      		instance->currentMo->bytesInBuf, &instance->msgHandle, 
					&instance->tHandle);
			}
			else
			{
				instance->mmsResult = MEAlib_setMessageBody(MSF_MODID_MEA,
					instance->bodyParams, instance->currentMo->data, 
					instance->currentMo->bytesInBuf, &instance->msgHandle, 
					&instance->tHandle);
			}
			

			if(MMS_RESULT_DELAYED == instance->mmsResult && ((MmsTransaction*)instance->tHandle)->bytesLeft!=instance->currentMo->bytesInBuf)
			{
				instance->currentMo->file->pos+=(instance->currentMo->bytesInBuf-((MmsTransaction*)instance->tHandle)->bytesLeft);				
				instance->currentMo->file->size-=(instance->currentMo->bytesInBuf-((MmsTransaction*)instance->tHandle)->bytesLeft);
				instance->currentMo->bytesInBuf=((MmsTransaction*)instance->tHandle)->bytesLeft;
			}

	    }
#else /* MMS_SLIM_MEM */
#ifdef WAP_SUPPORT
		/* Remove the NULL terminator in text object */
		if(instance->currentMo->content.type==MEA_MEDIA_TYPE_TEXT_PLAIN &&
			((MmsTransaction*)instance->tHandle)->state != 3 &&
			(instance->currentMo->size>1) && 
			*(instance->currentMo->data+instance->currentMo->size-1)==0x00 &&
			*(instance->currentMo->data)!=0x00)
		{				
			/* Write message */
			instance->mmsResult = MMSlib_setMessageBody(MSF_MODID_MEA, 
				instance->bodyParams, instance->currentMo->data, 
				instance->currentMo->size-1, &instance->msgHandle, 
				&instance->tHandle);
		}
		else
#endif /* WAP_SUPPORT */
            instance->mmsResult = MMSlib_setMessageBody(MSF_MODID_MEA, 
                instance->bodyParams, instance->currentMo->data, 
                instance->currentMo->size, &instance->msgHandle, 
                &instance->tHandle);
#endif /* MMS_SLIM_MEM */
        if (MMS_RESULT_DELAYED == instance->mmsResult)
        {
            fHandle = MMSlib_getFileHandle(MSF_MODID_MEA, &instance->tHandle);
            meaAsyncRegister(fHandle, MEA_MCR_FSM, MEA_SIG_MCR_FILE_NOTIFY, 0);
            /* Async! .. we'll arrive here again, soon. */
            return MEA_MCR_DELAYED; 
        }
        else if (MMS_RESULT_OK != instance->mmsResult)
        {
            return MEA_MCR_FAILED;
        }
#ifdef MMS_SLIM_MEM
	    if (instance->currentMo->acessType == meaMoInOneFile ||
			instance->currentMo->acessType == meaMoInPartOfFile)
	    {
		    instance->currentMo->file->pos+=instance->currentMo->bytesInBuf;		
		    instance->currentMo->file->size-=instance->currentMo->bytesInBuf;				

		    if(instance->currentMo->file->size>0)
		    {
			    instance->currentMo->bytesInBuf=instance->currentMo->file->size;
			    if(instance->currentMo->bytesInBuf>=MMS_MAX_CHUNK_SIZE)
			    {
				    instance->currentMo->bytesInBuf=MMS_MAX_CHUNK_SIZE;			
			    }
			    meaAsyncRead(instance->currentMo->meaObjectReader, instance->currentMo->file->pos, instance->currentMo->data, instance->currentMo->bytesInBuf);								
			    return MEA_MCR_DELAYED;
		    }
	    }
        if(instance->currentMo->meaObjectReader)
	    {
	        meaAsyncOperationStop(&instance->currentMo->meaObjectReader);
	    }
        if(instance->currentMo->data && instance->currentMo->acessType!=meaMoInMemory)
        {
            MEA_FREE(instance->currentMo->data);
            instance->currentMo->data=NULL;
        }
#endif /* MMS_SLIM_MEM */
        instance->mmsResult = MMSlib_transactionClose(MSF_MODID_MEA, 
            &instance->tHandle);
        if (MMS_RESULT_OK != instance->mmsResult)
        {
            return MEA_MCR_FAILED;
        }
#ifdef MMS_SLIM_MEM
	    if(instance->currentMo->acessType==meaMoInOneFile||instance->currentMo->acessType==meaMoInPartOfFile)
	    {
	    	instance->currentMo->file->pos=instance->currentMo->file->tmppos;
		    instance->currentMo->file->size=instance->currentMo->file->tmpsize;
	    }
#endif /* MMS_SLIM_MEM */
        /* Free body params */
        freeBodyParams(&instance->bodyParams);
        /* Next item */
        instance->currentMo = instance->currentMo->next;
        if ((NULL != instance->currentMo) || 
            meaIsSmilValid(instance->msg->smilInfo))
        {
            /* Open a new transcation for the next part or the smil part if 
               there are no more objects */
            instance->mmsResult = MMSlib_transactionOpen(MSF_MODID_MEA, 
                &instance->tHandle);
            if (MMS_RESULT_OK != instance->mmsResult)
            {
                return MEA_MCR_FAILED;
            }
        }
        if (NULL == instance->currentMo)
        {
#ifdef WAP_SUPPORT
            instance->state = /*(meaIsSmilValid(instance->msg->smilInfo))
                ? WRITE_SMIL_PART :*/ FINALISE_MSG;
#else
            instance->state = (meaIsSmilValid(instance->msg->smilInfo))
                ? WRITE_SMIL_PART : FINALISE_MSG;
#endif  /* WAP_SUPPORT */
        }
        /* Do not execute the entire work at once */
        (void)MEA_SIGNAL_SENDTO(MEA_MCR_FSM, MEA_SIG_MCR_FILE_NOTIFY);
        return MEA_MCR_WAIT_RSP;

    case WRITE_SMIL_PART:
        /* Only allocate dynamic data once */
        if (NULL == instance->tmpBuffer)
        {
            /* Check if the SMIL needs to be created or not */
            if (!meaCreateSmil(instance->msg->smilInfo, 
                (char **)&(instance->tmpBuffer), &(instance->tmpSize)))
            {
                return MEA_MCR_FAILED;
            }
            /* Create body params */
            strValue = MEA_ALLOC(sizeof(MMS_MEDIA_TYPE_STRING_SMIL));
            strcpy((char *)strValue, MMS_MEDIA_TYPE_STRING_SMIL);
#ifdef WAP_SUPPORT            
            if (NULL == (instance->bodyParams = meaCreateBodyParams(
                MMS_MULTIPART_MESSAGE, NULL, MMS_VALUE_AS_STRING, 
                (unsigned char *)strValue, (unsigned char *)MEA_SMIL_FILE_NAME, NULL)))
#else
            if (NULL == (instance->bodyParams = meaCreateBodyParams(
                MMS_MULTIPART_MESSAGE, NULL, MMS_VALUE_AS_STRING, 
                (unsigned char *)strValue, (unsigned char *)MEA_SMIL_FILE_NAME)))
#endif
            {
                return MEA_MCR_FAILED;
            }
        }
#ifdef WAP_SUPPORT        
    	{
			char *filepath=NULL;            
			filepath=MMSlib_getMessageFullPath(MSF_MODID_MEA, instance->msgId, instance->msgType);
			if(filepath)
			{
    			instance->bodynum_pos=MSF_FILE_GETSIZE(filepath)-1;
				MEA_FREE(filepath);	
			} 
		}
#endif  /* WAP_SUPPORT */
        meaPmSetProgress(50, NULL);
        /* Write message */
        instance->mmsResult = MMSlib_setMessageBody(MSF_MODID_MEA, 
            instance->bodyParams, instance->tmpBuffer, instance->tmpSize, 
            &instance->msgHandle, &instance->tHandle);
        if (MMS_RESULT_DELAYED == instance->mmsResult)
        {
            fHandle = MMSlib_getFileHandle(MSF_MODID_MEA, &instance->tHandle);
            meaAsyncRegister(fHandle, MEA_MCR_FSM, MEA_SIG_MCR_FILE_NOTIFY, 0);
            /* Async! .. we'll arrive here again, soon. */
            return MEA_MCR_DELAYED; 
        }
        else if (MMS_RESULT_OK != instance->mmsResult)
        {
            return MEA_MCR_FAILED;
        }
        freeBodyParams(&instance->bodyParams);
        instance->mmsResult = MMSlib_transactionClose(MSF_MODID_MEA, 
            &instance->tHandle);
        if (MMS_RESULT_OK != instance->mmsResult)
        {
            return MEA_MCR_FAILED;
        }
#ifdef WAP_SUPPORT
	if(NULL != instance->currentMo)
	{
	     instance->mmsResult = MMSlib_transactionOpen(MSF_MODID_MEA, 
                &instance->tHandle);
           if (MMS_RESULT_OK != instance->mmsResult)
           {
                return MEA_MCR_FAILED;
            }
            instance->state = WRITE_BODY_PART;//FINALISE_MSG;
	}
	else
	{
            instance->state = FINALISE_MSG;
	}        
#else
        instance->state = FINALISE_MSG;
#endif  /* WAP_SUPPORT */       
        /* Release the SMIL part */
        releaseSmilBuffer(instance);

        /* Do not execute the entire work at once */
        (void)MEA_SIGNAL_SENDTO(MEA_MCR_FSM, MEA_SIG_MCR_FILE_NOTIFY);
        return MEA_MCR_WAIT_RSP;

    case COPY_BODY:
        /*
         *  Copying the body is done in the signal handler, just return.
         */
        return MEA_MCR_WAIT_RSP;

    case FINALISE_MSG:
        meaPmSetProgress(95, NULL);

#ifdef WAP_SUPPORT /* Add attachments*/         
        if(instance->bodynum_pos!=0)
        {
            attachmentObjectList * attachmentList = meaGetAttachmentList();
            if (attachmentList)
            {
                addAttachmentToMmsMessage(MSF_MODID_MEA, instance->msgId,instance->bodynum_pos, meaSeGetAttachmentNo(), 
                    attachmentList);
            }
        }
#endif /* WAP_SUPPORT */
        if (IS_FORWARD_OP(instance)) 
        {
            /* Cleanup ASIO handles */
            if (NULL != mcrInstance->origMsg->asioReadHandle)
            {
                meaAsyncOperationStop(&mcrInstance->origMsg->asioReadHandle);
            } /* if */
            
            if (NULL != mcrInstance->origMsg->asioWriteHandle)
            {
                meaAsyncOperationStop(&mcrInstance->origMsg->asioWriteHandle);
            } /* if */
        }
        else
        {
            instance->mmsResult = MMSlib_messageClose(MSF_MODID_MEA, 
                &instance->msgHandle);
            if (MMS_RESULT_OK != instance->mmsResult)
            {
                return MEA_MCR_FAILED;
            }
        }
        /* Check if the message is going to end up */

#ifdef __UNIFIED_COMPOSER_SUPPORT__
        MMA_createMessageDone(MSF_MODID_MEA, instance->msgId, 
            instance->saveInFolder);
#else
        MMSif_createMessageDone(MSF_MODID_MEA, instance->msgId, 
            instance->saveInFolder);
#endif

        instance->state = MESSAGE_DONE_RESPONSE;
        return MEA_MCR_WAIT_RSP;
        
    case MESSAGE_DONE_RESPONSE:
        /* Delete the originating message if in "edit" mode, templates should 
           not be deleted */
	    {
            extern MmsMessageFolderInfo *fldrMgrGetMsgInfo(MSF_UINT32 msgId);
            MmsMessageFolderInfo *msgInfo = (MmsMessageFolderInfo *)fldrMgrGetMsgInfo(instance->msgId);

            msgInfo->date= MSF_TIME_GET_CURRENT();
            {
                extern MSF_UINT32 HDIa_timeLocalToUTC(MSF_UINT32 local_time);
                msgInfo->date = HDIa_timeLocalToUTC(msgInfo->date);
            }
        meaPmSetProgress(99, NULL);

#ifndef __UNIFIED_MSG_SUPPORT__  /* delayed after save/send done */
        if (ORIGINAL_MSG_EXISTS(instance) && (instance->origMsg->del))
        {
            meaDeleteMsg(instance->origMsg->msgId);
        }
#endif
        /* Update current folder */
        (void)MEA_SIGNAL_SENDTO_I(MEA_MH_FSM, MEA_SIG_MH_UPDATE_FOLDER, 
            MEA_FOLDER_NONE);
        return MEA_MCR_OK;
        }
    default:
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MAMCR_00B32A1A785392B5A554DCF32DC17D59, "(%s) (%d) erroneous state\n", __FILE__, __LINE__));
        break;
    }

    return MEA_MCR_FAILED;
}

/*!
 * \brief  Start of execution for the createMessage FSM. 
 *
 * \param fsm       callback FSM.
 * \param retSig    callback signal.
 * \param msg       message to create/send
 * \param origId    msgId of the originating msgId, if any, used for forwarding
 * \param folder    The folder to save the new message in.
 * \param del       Whether to delete original message afterwards
 * \param forwardMode Tells that this is a forward operation.
 *****************************************************************************/
void meaCreateMessage(MeaStateMachine fsm, unsigned int retSig, MeaMessage *msg, 
    MmsMsgId origId, MSF_BOOL del, MmsFolderType folder, 
    MmsFileType origFileType, MSF_BOOL forward)
{
    MeaCreateMessageSignal *sig;
        
    MEA_CALLOC(sig, sizeof(MeaCreateMessageSignal));
    sig->fsm            = fsm; 
    sig->retSig         = (int)retSig;
    sig->message        = msg;
    sig->origMsgId      = origId;
    sig->del            = del;
    sig->folder         = folder;
    sig->origFileType   = origFileType;
    sig->forwardMode    = forward;

    (void)MEA_SIGNAL_SENDTO_P(MEA_MCR_FSM, MEA_SIG_MCR_CREATE_MESSAGE, sig);
}

/*!
 * \brief Creates a instance for message creation
 * 
 * \return TRUE if successful, otherwise FALSE;
 *****************************************************************************/
static int createMcrInstance(const MeaCreateMessageSignal *msgData)
{
    /* Check that a instance can be created */
    if (NULL != mcrInstance) 
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MAMCR_6AC1A1B8B4EE2CA0D99DA38B7641ACF8, "(%s) (%d) unable to create instance.\n", __FILE__, __LINE__));
        return FALSE;
    }
    else
    {
        /* Create instance */
        MEA_CALLOC(mcrInstance, sizeof(McrInstance));
        /* Copy pointer to message information structure */
        mcrInstance->fsm            = msgData->fsm;
        mcrInstance->sig            = msgData->retSig;
        mcrInstance->msg            = msgData->message;
        mcrInstance->saveInFolder   = msgData->folder;
        if (MMS_TEMPLATES == msgData->folder)
        {
            mcrInstance->msgType = MMS_SUFFIX_TEMPLATE;
        }
#if 0 //Q03C1-2.11 don't need patch
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        else
        {
            mcrInstance->msgType = MMS_SUFFIX_SEND_REQ;
        }
        if (msgData->origMsgId > 0) 
        {
            MEA_CALLOC(mcrInstance->origMsg, sizeof(McrOriginalMessage));
            mcrInstance->origMsg->msgId          = msgData->origMsgId;
            mcrInstance->origMsg->del            = msgData->del;
            mcrInstance->origMsg->fileType       = msgData->origFileType;
            mcrInstance->origMsg->forwardMode    = msgData->forwardMode;
        }
        mcrInstance->state = CREATE_MSG_ID;
        return TRUE;
    }
}

/*!
 * \brief Deallocates the current instance and its resources.
 *
 * \param result The result to send back to the originating FSM.
 *****************************************************************************/
static void cleanupMcrInstance(MeaMcrResult result)
{
    MmsFolderType folderType = MMS_NO_FOLDER;

    if (NULL != mcrInstance)
    {
        folderType = mcrInstance->saveInFolder;

        /* Close transaction */
        if (NULL != mcrInstance->tHandle)
        {
            (void)MMSlib_transactionClose(MSF_MODID_MEA, 
                &mcrInstance->tHandle);
        }

        /* Close message */
        if (NULL != mcrInstance->msgHandle)
        {
            (void)MMSlib_messageClose(MSF_MODID_MEA, &mcrInstance->msgHandle);
            mcrInstance->msgHandle = 0;
        }

        if (NULL != mcrInstance->msgHdr)
        {
            MMSlib_freeMmsSetHeader(MSF_MODID_MEA, mcrInstance->msgHdr);
            MEA_FREE(mcrInstance->msgHdr);
            mcrInstance->msgHdr = NULL;
        }
#ifdef MMS_SLIM_MEM
	    {
		    MeaMoDataItem	*mo = mcrInstance->currentMo;
	    	while(mo)
	    	{
	    		if (mo->meaObjectReader)
			    	meaAsyncOperationStop(&mo->meaObjectReader);
			    if(mo->meaAsioReader)
				    meaAsyncOperationStop(&mo->meaAsioReader);
			    if(mo->meaAsioWriter)
				    meaAsyncOperationStop(&mo->meaAsioWriter);
	    		if (!mo->next)
	    			break;
	    		else
	    			mo = mo->next;
	    	}
	    }
#endif /* MMS_SLIM_MEM */

        /* Free originating message */
        if (ORIGINAL_MSG_EXISTS(mcrInstance)) 
        {
            if (NULL != mcrInstance->origMsg->hdr) 
            {
                /* Clean up the original header */
                MMSlib_freeMmsGetHeader(MSF_MODID_MEA, 
                    mcrInstance->origMsg->hdr);
                MEA_FREE(mcrInstance->origMsg->hdr);
                mcrInstance->origMsg->hdr = NULL;
            }

            /* Close the message */
            if (NULL != mcrInstance->origMsg->msgHandle)
            {
                (void)MMSlib_messageClose(MSF_MODID_MEA, 
                    &mcrInstance->origMsg->msgHandle);
                mcrInstance->origMsg->msgHandle = NULL;
            }                

            /* Cleanup ASIO handles */
            if (NULL != mcrInstance->origMsg->asioReadHandle)
            {
                meaAsyncOperationStop( &mcrInstance->origMsg->asioReadHandle);
            } /* if */            
            if (NULL != mcrInstance->origMsg->asioWriteHandle)
            {
                meaAsyncOperationStop( &mcrInstance->origMsg->asioWriteHandle);
            } /* if */

            /* Free filenames */
            MEA_FREE(mcrInstance->origMsg->srcFile);
            mcrInstance->origMsg->srcFile = NULL;
            
            MEA_FREE(mcrInstance->origMsg->dstFile);
            mcrInstance->origMsg->dstFile = NULL;
            
            MEA_FREE(mcrInstance->origMsg->copyBuffer);
            MEA_FREE(mcrInstance->origMsg);
            mcrInstance->origMsg = NULL;
        }

        /* Stop messing with message */
        mcrInstance->msg = NULL;

        /* Body params */
        if (NULL != mcrInstance->bodyParams)
        {
            freeBodyParams(&mcrInstance->bodyParams);
        }
        /* Handle the temporary SMIL buffer */
        releaseSmilBuffer(mcrInstance);
        /* Remove progress meter just in case */
//        meaPmViewRemove();
        
        /* Delete the message if creation fails */
        if (MEA_MCR_FAILED == result || MEA_MCR_STORAGE_FULL == result)
        {
#ifdef WAP_SUPPORT
            fldrMgrDeleteMessage(mcrInstance->msgId);
#else
            meaDeleteMsg(mcrInstance->msgId);
#endif /* WAP_SUPPORT */
        }

        /* Send response */
        if (MEA_MCR_CLEANUP_SILENT != result)
        {
            (void)MEA_SIGNAL_SENDTO_IUU(mcrInstance->fsm, mcrInstance->sig, 
                mcrInstance->msgType, result, mcrInstance->msgId);
        }

        /* Free instance */
        MEA_FREE(mcrInstance);
        mcrInstance = NULL;
    }

#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
    if (MMS_TEMPLATES != folderType)
#endif
    {
    /* If save failed must close it here*/
    if (MMS_HIDDEN != folderType || MMS_RESULT_OK != result)
    {
        HDIa_widgetExtCloseTransitionAnimation();
    }
    }
}

/*!
 * \brief The message editor signal handling logic
 * \param sig The received signal
 *****************************************************************************/
static void mcrSignalHandler(MeaSignal *sig)
{
    MmsResult res;

    switch(sig->type)
    {
    case MEA_SIG_MCR_CREATE_MESSAGE:
        HDIa_widgetExtDisplayTransitionAnimationNoEnd(TRUE);
        if (!createMcrInstance((MeaCreateMessageSignal*)sig->p_param))
        {
            cleanupMcrInstance(MEA_MCR_FAILED);
            MEA_FREE(sig->p_param);
            break;
        }
        MEA_FREE(sig->p_param);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif        
        if (MEA_MCR_FAILED == meaCreateMessageFSM(mcrInstance))
        {
            cleanupMcrInstance(MEA_MCR_FAILED);
        }
        /* The data provided through p_param is used in the createMcrInstance
            function */
        break;


    case MEA_SIG_MCR_CREATE_MSG_RESPONSE:
        res = (MmsResult)sig->u_param1;
#ifdef WAP_SUPPORT
        if (MMS_RESULT_TOO_MANY_MSG == res)
        {
            cleanupMcrInstance(MEA_MCR_TOO_MANY_MSG);
            break; 
        }
        else if (MMS_RESULT_INSUFFICIENT_PERSISTENT_STORAGE == res)
        {
            cleanupMcrInstance(MEA_MCR_STORAGE_FULL);
            break; 
        }
#endif /* WAP_SUPPORT */
        if (MMS_RESULT_OK != res) 
        {
            cleanupMcrInstance(MEA_MCR_FAILED);
            break; 
        }
        mcrInstance->msgId = (MmsMsgId)sig->u_param2;
        if (MEA_MCR_FAILED == meaCreateMessageFSM(mcrInstance))
        {
            cleanupMcrInstance(MEA_MCR_FAILED);
        }
        break;

#ifdef MMS_SLIM_MEM
    case MEA_SIG_MCR_CREATE_MSG_READ_MO_FINISHED:
	    if(sig->u_param1 != MEA_ASIO_RESULT_OK && sig->u_param1 != MEA_ASIO_RESULT_EOF)
	    {
            cleanupMcrInstance(MEA_MCR_FAILED);
	    }
#endif
    case MEA_SIG_MCR_FILE_NOTIFY:
    case MEA_SIG_MCR_CONTINUE:
        if (MEA_MCR_FAILED == meaCreateMessageFSM(mcrInstance))
        {
            cleanupMcrInstance(MEA_MCR_FAILED);
        }
        break;

    case MEA_SIG_MCR_ASIO_READ_RSP:
        if (!handleReadOperation(mcrInstance, (signed)sig->u_param2,
            (MeaAsioResult)sig->u_param1)) 
        {
            if((MeaAsioResult)sig->u_param1 == MEA_ASIO_RESULT_INSUFFICIENT_PERSISTENT_STORAGE)
            {
                cleanupMcrInstance(MEA_MCR_STORAGE_FULL);
            }
            else
            {
                cleanupMcrInstance(MEA_MCR_FAILED);
            }
        }
        else 
        {
            /* write data to the end of the file */
            meaAsyncWrite(mcrInstance->origMsg->asioWriteHandle, 
                -1, mcrInstance->origMsg->copyBuffer, 
                (unsigned)mcrInstance->origMsg->sizeToWrite);            
        }
        break;

    case MEA_SIG_MCR_ASIO_WRITE_RSP:
        if (!handleWriteOperation((MeaAsioResult)sig->u_param1))
        {
            /* Failed to write */
            /* End saving, just clean up and return */
            if((MeaAsioResult)sig->u_param1 == MEA_ASIO_RESULT_INSUFFICIENT_PERSISTENT_STORAGE)
            {
                cleanupMcrInstance(MEA_MCR_STORAGE_FULL);
            }
            else
            {
                cleanupMcrInstance(MEA_MCR_FAILED);
            }
        }
        else
        {
            if (0 == mcrInstance->origMsg->leftToRead)
            {
                /* finish the job */
                mcrInstance->state = FINALISE_MSG;
                if (MEA_MCR_FAILED == meaCreateMessageFSM(mcrInstance))
                {
                    cleanupMcrInstance(MEA_MCR_FAILED);
                }
            }
            else
            {
                /* read next part of the message */
                meaAsyncRead(mcrInstance->origMsg->asioReadHandle, 
                    (int)mcrInstance->origMsg->readPos, 
                    mcrInstance->origMsg->copyBuffer, 
                    MIN(mcrInstance->origMsg->leftToRead, 
                    mcrInstance->origMsg->copyBufferSize));
            }/* if */
        }/* if */
        break;        

    case MEA_SIG_MCR_CREATE_MSG_DONE_RESPONSE:
//        meaPmViewRemove();
#ifdef MMS_FILE_PROTECT_SUPPORT
        if(!meaSmilEditorIsActive()&&(MMS_RESULT_OK == (MmsResult)sig->u_param1))
        {
            sig->u_param1=genChkSumFile((MmsMsgId)sig->u_param2);
        }
#endif /* MMS_FILE_PROTECT_SUPPORT */       
        if (MMS_RESULT_OK != (MmsResult)sig->u_param1)
        {
            if((MmsResult)sig->u_param1 == MMS_RESULT_INSUFFICIENT_PERSISTENT_STORAGE)
            {
                cleanupMcrInstance(MEA_MCR_STORAGE_FULL);  /* Cleanup */
            }
            else
            {
                cleanupMcrInstance(MEA_MCR_FAILED);  /* Cleanup */
            }
            break;
        }
        
        cleanupMcrInstance((MEA_MCR_OK == meaCreateMessageFSM(mcrInstance)) 
            ? MEA_MCR_OK : MEA_MCR_FAILED);
        break;
        
    default:
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MAMCR_AE8133CA796C5672D4711DD11A16A05E, "MCR: Erroneous signal received (%d).\n", sig->type));
    }
    /* Remove signal data */
    meaSignalDelete(sig);
}


