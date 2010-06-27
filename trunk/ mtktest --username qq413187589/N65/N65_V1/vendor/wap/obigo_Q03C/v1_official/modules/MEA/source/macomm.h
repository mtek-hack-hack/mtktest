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

/* !\file macomm.h
 *  Network communication handling.
 */

#ifndef _MACOMM_H_
#define _MACOMM_H_

/******************************************************************************
* Constants
*****************************************************************************/

/*! \enum MeaCommSignalId
 *  Signals for the COMM FSM */
typedef enum 
{
    /* ---------- Send message --------------------*/
    /*! Send a message
     * i_param  = signal
     * u_param1 = fsm
     * u_param2 = msgId
     */
    MEA_SIG_COMM_SEND_MESSAGE, /* Not used! Use meaSendMessage() instead! */
        
    MEA_SIG_COMM_SEND_NETWORK_STATUS_RSP,
        
    MEA_SIG_COMM_SEND_MESSAGE_INFO_RETRIEVED,
                    
    MEA_SIG_COMM_SEND_MESSAGE_SIZE_OK, 

    MEA_SIG_COMM_SEND_VERIFICATION_RSP,
        
    /*! Send message response from the MMS Service
     * u_param1 = result
     * u_param2 = msgId
     */
    MEA_SIG_COMM_SEND_MSG_RESPONSE,

    /*! Cancel an ongoing send operation.
     * u_param1 = msgId
     */
    MEA_SIG_COMM_SEND_CANCEL,

    /* ------------ Message retrieval -------------*/
    /*7- ! Download a message.
     * i_param  = signal
     * u_param1 = fsm
     * u_param2 = msgId - the message to download 
     */
    MEA_SIG_COMM_DOWNLOAD,

#ifdef WAP_SUPPORT    
    /*! Download confirmation.
     * i_param  = signal
     * u_param1 = fsm
     * u_param2 = msgId - the message to download 
     */
    MEA_SIG_COMM_DOWNLOAD_CONFIRM,
    
    /*! Retrieval modes and possibly user interaction is done.
     * u_param1 = result
     */
    MEA_SIG_COMM_DOWNLOAD_CONFIRM_RSP,
    
    /*! Retrieval modes and possibly user interaction is done.
     * u_param1 = result
     */
    MEA_SIG_COMM_DOWNLOAD_MODE_RSP,
#endif /* WAP_SUPPORT*/
    /* The reposne for the "get messge info" reguest
     *
     * p_param = The message info or NULL, see #MmsMessageFolderInfo.
     */
    MEA_SIG_COMM_DOWNLOAD_MSG_TYPE_RSP,

    /*! Network status information from registry has been updated.
     */
    MEA_SIG_COMM_DOWNLOAD_NETWORK_STATUS_RSP,

    /*! Read notification response.
     */
    MEA_SIG_COMM_DOWNLOAD_NOTIF_FILE_NOTIFY_RSP,

    /*! Retrieval modes and possibly user interaction is done.
     * u_param1 = result
     */
    MEA_SIG_COMM_DOWNLOAD_VERIFICATION_RSP,

    /*! The message download response from the MMS Service.
     * u_param1 = result
     * u_param2 = msgId
     */
    MEA_SIG_COMM_DOWNLOAD_RESPONSE,

    /*! Cancel message download
     * u_param1 = msgId the id of the notification that are currently 
     *                  downloaded
     */
    MEA_SIG_COMM_DOWNLOAD_CANCEL,

    /*! Message send/download status sent from the MMS Service
     * p_param = The current send/download status, see MmsProgressStatus.
     */
    MEA_SIG_COMM_PROGRESS_STATUS,

    /*! User closed settings error dialog */
    MEA_SIG_COMM_SETTINGS_FAILED_DIALOG_RSP,

    /*! User choose to download a expired mm */
    MEA_SIG_COMM_DOWNLOAD_EXPIRED_MM,

    MEA_SIG_COMM_CHOOSE_SIM_TO_SEND,

    MEA_SIG_COMM_NAV_MENU_DEACTIVATE

}MeaCommSignalId;

/*!\enum MeaCommMainMenuItems 
 * \brief Menu items for the COMM
 */
typedef enum
{
    MEA_COMM_CHOOSE_SIM_1,       /*!< SIM 1 */
    MEA_COMM_CHOOSE_SIM_2,       /*!< SIM 2 */
    MEA_COMM_BACK,               /*!< Go back */
    MEA_COMM_MENU_ITEM_COUNT     /*!< Not used */
}MeaCommMainMenuItems;


/*! \enum MeaSendResult
 *  Response signal data for send */
typedef enum
{
    MEA_SEND_OK,        /* The message was sent successfully */
    MEA_SEND_FAILED,    /* The send operation failed */
    MEA_SEND_FAILED_REFUSED,    /*!< The message was refused by the server */
#ifdef WAP_SUPPORT
    MEA_SEND_FAILED_COMM, /*!< Communication error */
    MEA_SEND_FAILED_SETTING,
    MEA_SEND_TIMEOUT,
#endif /* WAP_SUPPORT */
    MEA_SEND_CANCELLED, /* The send operation was cancelled */
    MEA_SEND_TERMINATE_SILENT,     /* Used internally by the state machine */
    MEA_SEND_BUSY,
    MEA_SEND_COMM_ADDRESS_UNRESOLVED,
    MEA_SEND_COMM_BAD_GATEWAY,
    MEA_SEND_COMM_ENTITY_TOO_LARGE,
    MEA_SEND_COMM_FAILED,
    MEA_SEND_COMM_FILE_NOT_FOUND,
    MEA_SEND_COMM_FORBIDDEN,
    MEA_SEND_COMM_HEADER_TAG,
    MEA_SEND_COMM_ILLEGAL_PDU,
    MEA_SEND_COMM_LIMITATIONS_NOT_MET,
    MEA_SEND_COMM_PROXY_ERROR,
    MEA_SEND_COMM_MMSC_VERSION,
    MEA_SEND_COMM_SECURITY_ERROR,
    MEA_SEND_COMM_SERVER_ERROR,
    MEA_SEND_COMM_STATUS,
    MEA_SEND_COMM_TRANSACTION_ID,
    MEA_SEND_COMM_UNAUTHORIZED,
    MEA_SEND_COMM_UNAVAILABLE,
    MEA_SEND_COMM_UNEXPECTED_MESSAGE,
    MEA_SEND_COMM_UNSUPPORTED_VERSION,
    MEA_SEND_COMM_URI_TOO_LARGE
}MeaSendResult;

/*! \enum MeaDownloadResult
 *  Response signal data for message retrieval  */
typedef enum
{
    MEA_DOWNLOAD_OK,        /* The message was downloaded successfully */
    MEA_DOWNLOAD_FAILED,    /* The send operation failed */
    MEA_DOWNLOAD_FAILED_NO_SPACE_LEFT, /* The message could not be stored */
    MEA_DOWNLOAD_BUSY,
    MEA_DOWNLOAD_FAILED_MAX_RETRIEVAL_SIZE_EXCEEDED,
    MEA_DOWNLOAD_FAILED_ILLEGAL_PDU,
    MEA_DOWNLOAD_CANCELLED, /* The download operation was cancelled */
    MEA_DOWNLOAD_TERMINATE_SILENT, /* Used internally by the state machine */
    MEA_DOWNLOAD_TOO_MANY_MSG      /* Max number of files in the mms directory reached */
}MeaDownloadResult;

/******************************************************************************
 * Prototype declarations 
 *****************************************************************************/

void meaCommInit(void); 
void meaCommTerminate(void);
void meaSendMessage(MeaStateMachine fsm, unsigned int retSig, MmsMsgId msgId,
                    MSF_BOOL showWarning);
void meaDownloadMessage(MeaStateMachine fsm, unsigned int retSig, 
                        MmsMsgId msgId);
#ifdef WAP_SUPPORT
void clearProgressPercent(void);
void verifyDownload(int signal, MSF_UINT32 size, MmsMsgId msgId);
void meaShowSendDialogWithText(MeaSendResult result, char *responseText);
  #ifdef __UNIFIED_MSG_SUPPORT__
void meaSendEditedMessage(MeaStateMachine fsm, unsigned int retSig, MmsMsgId msgId, MmsMsgId origMsgId, 
    MSF_BOOL showWarning);
  #endif
#endif /* WAP_SUPPORT */
MSF_BOOL meaShowDownloadErrorDialog(MeaDownloadResult result, 
    MeaStateMachine fsm, int signal);
void meaShowSendDialog(MeaSendResult result, MeaStateMachine fsm,
    int signal);
                      
#endif /* _MACOMM_H_ */


