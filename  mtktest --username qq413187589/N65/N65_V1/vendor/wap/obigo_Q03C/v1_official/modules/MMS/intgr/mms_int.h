/*
 * Copyright (C) Obigo AB, 2002-2005.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Obigo AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Obigo AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */

/*! \file mms_int.h
 * \brief  Exported adapter function from MMS Service 
 *         Note - in the folder refsrc there is reference (example code) that 
 *                implements the protyped adapter functions in this file.
 *
 * Exported adapter functions, from MMS to e.g. Target Device Application
 * For every adapter function, the following data are listed:
 * - A brief one line description of the function
 * - A longer description of the function
 * - The parameters for the function
 */

#ifndef _MMSINT_H
#define _MMSINT_H

/*--- Definitions/Declarations ---*/

/*--- Types ---*/

/*--- Constants ---*/
        
/*--- Forwards ---*/

/*--- Externs ---*/

/*--- Macros ---*/

/*--- Prototypes ---*/

/*!
 * \brief New message as been received
 *
 * This adapter function is called when a new message, notification or 
 * Read/Delivery Report has been received. 
 * The purpose of this function is to tell the User via a ring tone or 
 * other effects that an MMS message has arrived. It is useful when no 
 * MMS application is running (MEA).
 * It also provides information about the number of messages in the inbox
 * or notification folder and how many of these that are unread.
 *
 * Type: Adapter
 *
 * \param msgType           The type of the message that is received
 * \param msgId             The message ID of the message received
 * \param from              Address from where the message/report is sent
 * \param subject           Subject of the message (NULL for Read and Delivery Reports)
 * \param size              Size of the message (0 for Read and Delivery Reports)
 * \param numOfMsg          Number of messages
 * \param numOfUnreadMsg    Number of unread messages
 * \param numOfNotif        Number of notifications
 * \param numOfUnredaNotif  Number of unread notifications
 * \param numOfRR           Number of read reports
 * \param numOfUnreadRR     Number of unread reports
 * \param numOfDR           Number of read reports
 * \param numOfUnreadDR     Number of unread delivery reports
 * \param reason            Notification status
 *****************************************************************************/
void MMSa_newMessage(MmsFileType msgType, MmsMsgId msgId, 
    MmsAddress *from, MmsEncodedText *subject, MSF_UINT32 size,
    MSF_UINT32 numOfMsg,   MSF_UINT32 numOfUnreadMsg,
    MSF_UINT32 numOfNotif, MSF_UINT32 numOfUnreadNotif,
    MSF_UINT32 numOfRR,    MSF_UINT32 numOfUnreadRR,
    MSF_UINT32 numOfDR,    MSF_UINT32 numOfUnreadDR,
    MmsNotificationReason reason
    ); 

/*!
 * \brief Provides inbox message status
 *
 * This adapter function is called when at system startup,
 * and when an message is read or deleted.
 * It provides information about the number of messages in the inbox
 * or notification folder and how many of these that are unread.
 *
 * Type: Adapter
 *
 * \param numOfMsg          Number of messages
 * \param numOfUnreadMsg    Number of unread messages
 * \param numOfNotif        Number of notifications
 * \param numOfUnredaNotif  Number of unread notifications
 * \param numOfRR           Number of read reports
 * \param numOfUnreadRR     Number of unread reports
 * \param numOfDR           Number of read reports
 * \param numOfUnreadDR     Number of unread delivery reports
*****************************************************************************/
void MMSa_messageStatus(MSF_UINT32 numOfMsg,   MSF_UINT32 numOfUnreadMsg,
                        MSF_UINT32 numOfNotif, MSF_UINT32 numOfUnreadNotif,
                        MSF_UINT32 numOfRR,    MSF_UINT32 numOfUnreadRR,
                        MSF_UINT32 numOfDR,    MSF_UINT32 numOfUnreadDR); 


/*!
 * \brief Report send/retrieve progress status.
 * 
 * This adapter is called when a send/retrieve is started, stopped and during
 * the transfer.
 *
 * This function can be used to indicate transfer beeing in progress and
 * that the progress is still occurring.
 *
 * Type: Adapter
 *
 *\param progressData, Progress information
 *****************************************************************************/
void MMSa_progressStatus(MmsProgressStatus *progressData);

/*!
 * \brief Error report
 * 
 * This adapter is called when a error occurs in the MMS when there is no 
 * application connected to the MMS API. 
 * Typical error that can be reported is the  
 * MMS_RESULT_TOO_MANY_MSG, when max number of messages has 
 * been stored and the MMS is working in immediate retrival mode. 
 *
 * Type: Adapter
 *
 *\param errorCode The error code. 
 *****************************************************************************/
void MMSa_error(MmsResult errorCode); 

/*!
 * \brief Get cellular roaming status
 * 
 * This function is called by the MMS service when a new message notification
 * is received to decide if cellular is in roaming.
 *
 * \return The functions returns true if in roaming otherwise false.
 *
 * Type: Adapter
 *
 *****************************************************************************/
MSF_BOOL MMSa_getRoamingStatus(void); 


#endif  /* _MMSINT_H */

