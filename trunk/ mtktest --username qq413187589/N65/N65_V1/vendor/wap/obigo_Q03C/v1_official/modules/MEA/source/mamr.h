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
 * Description:     Message loader FSM. 
 */

/*! \file mamr.h
 *  \brief Opens an existing message and reads its content into memory for 
 *         further processing by the ME and SE FSM.
 */

#ifndef _MAMR_H_
#define _MAMR_H_

/* Prerequisites */
#ifndef _MAINTSIG_H_
#error maintsig.h needs to be included before mame.h!
#endif

/******************************************************************************
 * Constants
 *****************************************************************************/

/*!\enum MeaMrSignalId
 * \brief Signals for the MR FSM 
 */
typedef enum 
{
    /*! Starts the MR FSM
     * u_param1 = FSM, the FSM to send a callback signal to.
     * i_param  = signal, the callback signal.
     * p_param  = Start-up data, see #MeaMrStartData.
     */
    MEA_SIG_MR_START,

#ifdef WAP_SUPPORT    
    /*! Restarts the MR FSM for trying to transform to Mixed MMS
     * u_param1 = FSM, the FSM to send a callback signal to.
     * i_param  = signal, the callback signal.
     * p_param  = Start-up data, see #MeaMrStartData.
     */
    MEA_SIG_MR_RESTART,

    /*! Reads the message header and replace the header to Mixed
     */
    MEA_SIG_MR_CHANGE_HEADER_TO_MIXED,
#endif /* WAP_SUPPORT */

    /*! Reads the message header
     */
    MEA_SIG_MR_READ_HEADER,

    /*! Reads a bodypart
     */
    MEA_SIG_MR_READ_BODYPART,

    /*! The response when starting the SLS.
     */
    MEA_SIG_MR_SLS_RSP,

    /*! 
     * Notification that a file operation is completed
     * i_param  = instance no.
     * u_param1 = result, see #MeaAsyncResults.
     * u_param2 = number of bytes read
     */
    MEA_SIG_MR_MO_READ,

    /*! 
     * The response from a SMAif_openSmil operation.
     * i_param  = result, see #SlsResult.
     * u_param1 = number of slides.
     * p_param  = the file name.
     */
    MEA_SIG_MR_OPEN_SMIL_RSP,

    /*! The response from a SMAif_closeSmil operation.
     * u_param1 = The result, see #SlsResult.
     */
    MEA_SIG_MR_CLOSE_SMIL_RSP,

    /*! The response from a SMAif_getSlideInfo operation.
     * u_param1 = 
     * u_param2 = 
     * p_param  = A #SlsSlideInfo structure.
     */
    MEA_SIG_MR_GET_SLIDE_INFO_RSP

}MeaMrSignalId;

/*!\enum MeaMrStartupMode 
 * \brief Startup message types for the MR
 */
typedef enum
{
    MEA_MR_STARTUP_NORMAL    = 0x01, /*!< Edit message  */
    MEA_MR_STARTUP_FORWARD   = 0x02, /*!< Forward message     */
    MEA_MR_STARTUP_REPLY     = 0x04, /*!< Reply */
    MEA_MR_STARTUP_REPLY_ALL = 0x08, /*!< Reply to all */
    MEA_MR_STARTUP_VIEW      = 0x16  /*!< View message */
}MeaMrStartupMode;

/*! \enum MeaMcrResult 
 *  \brief Result codes from the MR FSM. 
 */
typedef enum
{
    MEA_MR_FAILED,          /*!< The operation failed */
    MEA_MR_OK,              /*!< The operation was successful */
    MEA_MR_BUSY,            /*!< The FSM is busy */
    MEA_MR_FORWARD_LOCK,    /*!< The PDU contains forward locked information
                                 and cannot be changed*/
    MEA_MR_UNSUPPORTED_HEADER_FIELDS /*!< The header cannot be handled */
}MeaMrResult;

/* Text types when converting content types as integer to a string MIME type */
#define MEA_STR_TYPE_TEXT_ANY           "text/any"
#define MEA_STR_TYPE_TEXT_HTML          "text/html"
#define MEA_STR_TYPE_TEXT_PLAIN         "text/plain"
#define MEA_STR_TYPE_TEXT_X_VCALENDAR   "text/x-vcalendar"
#define MEA_STR_TYPE_TEXT_X_VCARD       "text/x-vcard"

/* Image types when converting content types as integer to a string MIME type*/
#define MEA_STR_TYPE_IMAGE_ANY          "image/any"
#define MEA_STR_TYPE_IMAGE_GIF          "image/gif"
#define MEA_STR_TYPE_IMAGE_JPEG         "image/jpeg"
#define MEA_STR_TYPE_IMAGE_VND_WAP_WBMP "image/vnd.wap.wbmp"
#define MEA_STR_TYPE_IMAGE_PNG          "image/png"
#define MMS_STR_TYPE_IMAGE_TIFF         "image/tiff"

/* File extensions */
#define MEA_FILE_ENDING_SML             "sml"
#define MEA_FILE_ENDING_AMR             "amr"
#define MEA_FILE_ENDING_PNG             "png"
#define MEA_FILE_ENDING_TXT             "txt"
#define MEA_FILE_ENDING_HTM             "htm"
#define MEA_FILE_ENDING_VCL             "vcl"
#define MEA_FILE_ENDING_VCD             "vcd"
#define MEA_FILE_ENDING_IMG             "img"
#define MEA_FILE_ENDING_GIF             "gif"
#define MEA_FILE_ENDING_JPG             "jpg"
#define MEA_FILE_ENDING_WBMP            "wbm"
#define MEA_FILE_ENDING_TIFF            "tif"

#define MEA_STR_ENDING_UNKNOWN          ""

/* The following constants are used to tell what a message consists of */
#define MEA_MESSAGE_TYPE_TEXT           0x01
#define MEA_MESSAGE_TYPE_ATTACHMENTS    0x02
#define MEA_MESSAGE_TYPE_SMIL           0x04

/* Maximum length for a MIME content type string */
#define MEA_MAX_MEDIA_TYPE_LEN          35   
/* The maximum length of a attachment name */ 
#define MEA_MAX_ATTACH_NAME_LEN         (8+3+1)

#define MEA_UTF16_BOM_LEN                 2
#define MEA_UTF16_BOM_BIG                  "\xFE\xFF"                  
#define MEA_UTF16_BOM_LITTELE              "\xFF\xFE"

/******************************************************************************
 * Data-types
 *****************************************************************************/

/*!\struct MeaMrStartData
 * \brief Used to transport MR startup information through a signal
 */
typedef struct
{
    MeaMrStartupMode    mode;       /*!< Startup mode */
    MmsMsgId            msgId;      /*!< Current message ID */
    MmsFileType         fileType;   /*!< Current file type */
    MeaStateMachine     retFsm;     /*!< Who to tell when done */
    int                 retSig;     /*!< What to say */    
}MeaMrStartData;

/*!\enum MeaMessageType */
typedef enum
{
    MEA_MR_PLAIN_TEXT,     /*!< The message is of type plain text */
    MEA_MR_SMIL,           /*!< The message is of type SMIL */
    MEA_MR_MULTIPART_MIXED,/*!< The message is of type Multipart/mixed */
    MEA_MR_MULTIPART_ALTERNATIVE, /*!< The message is of type 
                                Multipart/alternative*/
    MEA_MR_UNSUPPORTED     /*!< The message type is not supported */
}MeaMessageType;

/*!\struct McrInstance 
 * \brief Used to transport a message through a signal when done here
 */
typedef struct 
{
    /* Startup data */
    MmsMsgId            msgId;      /*!< The current message id */
    MmsFileType         fileType;   /*!< The type of message to open */

    /* Derived data */
    char            *fileName;      /*!< The filename of the message */
    MeaMessageType  msgType;        /*!< The message type */

    /* The message properties */
    MeaPropItem     *msgProperties; /*!< Message properties */    

    /* The new SMIL presentation */
    MeaSmilInfo     *smilInfo;      /*!< The new SMIL presentation */
    MeaMoDataItem   *unrefList;
}MeaMessage;

/*!\struct McrInstance 
 * \brief Information MCR needs to keep while recreating a message
 */
typedef struct 
{
    /* Used internally */
    MeaStateMachine     fsm;             /*!< The callback FSM */
    unsigned int        signal;          /*!< The callback signal */
    MeaMrStartupMode    mode;            /*!< The start-up mode */
    MSF_BOOL            onlyHeader;      /*!< Whether to ignore body-parts */
    MSF_UINT32          currentSlide;    /*!< The index of the processed slide*/
    MSF_UINT32          slideCount;      /*!< The total number of slides */
    struct 
    {
        MmsBodyInfoList     *bodyPart; /*!< The current body-part index */
        void                *buffer;   /*!< */
    }current;
#if 0
/* under construction !*/
#endif

    MeaMessage          *msg;            /*!< The message being created */

    /* Retrieval data */
    MmsGetHeader            *msgHeader;     /*!< The retrieved header */
    MmsTransactionHandle    transaction;    /*!< Transaction handle */
    MmsMsgHandle            msgHandle;      /*!< Message handle */

    /* Handles used when reading message content */
    void *audioHandle;    /*!< Handle for async reading of audio MO */    
    void *textHandle;     /*!< Handle for async reading of text MO */
    void *imageHandle;    /*!< Handle for async reading of image MO */
    MSF_UINT32  totalLen;
}MeaMrInstance;

/******************************************************************************
 * Prototype declarations 
 *****************************************************************************/

void meaMrInit(void); 
void meaMrTerminate(void);
void meaStartMr(MeaMrStartupMode mode, MmsMsgId msgId, MmsFileType fileType, 
    MeaStateMachine retFsm, unsigned int retSig);
void meaFreeMessage(MeaMessage **msg);
#ifdef WAP_SUPPORT
void meaSetMoIsFound(void);
void meaRestartMr(MeaMrStartupMode mode, MmsMsgId msgId, MmsFileType fileType, 
                 MeaStateMachine retFsm, unsigned int retSig);
#endif
#ifdef MMS_SLIM_MEM
MSF_BOOL isForMeaReadMessagePart(MSF_UINT32 handle, MsfNotificationType notificationType);
#endif
#ifdef __UNIFIED_MSG_SUPPORT__
MSF_BOOL isForMeaReadMixedBodyPart(MSF_UINT32 handle, MsfNotificationType notificationType);
#endif                      
#endif /* _MAMR_H_ */

