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

/*! \file mmsl_if.h
 * \brief  Exported libary functions from MMS Service for creation of 
 *         MMS messages.
 *
 * Exported libray functions, i.e. used by Target Device Application (TDA) to 
 * create MMS message. 
 * For every function, the following data are listed:
 * - A brief one line description of the function
 *
 * - A longer description of the function
 *
 * - The parameters for the function 
 *           In:  is input parameters 
 *           Out: is return parameters
 */

#ifndef _MMSL_IF_H
#define _MMSL_IF_H

/*--- Definitions/Declarations ---*/

/*--- Types ---*/

/*--- Constants ---*/

/*--- Forwards ---*/

/*--- Externs ---*/

/*--- Macros ---*/

/*--- Prototypes ---*/

/*!
 * \brief Get a filehandle from a transaction
 *
 * A filehandle is requested
 * 
 * Type: Function call 
 *
 * \param modId MSF Module identification
 * \param transaction Needed for internal use. Contains no user data. 
 * \return The filehandle
 *****************************************************************************/
int MMSlib_getFileHandle( MSF_UINT8 modId, MmsTransactionHandle *transaction);

/*!
 * \brief Get a specific part from a message body
 *
 * A specific bodypart is requested by the TDA.
 * 
 * Type: Function call 
 *
 * \param modId In: MSF module identification 
 * \param number In: The number of the requested body part
 * \param data In: Buffer to add data too.
 * \param size In/Out: In: Size of data buffer. Out: bytes in buffer when done.
 * \param msg In: Information about the file and message.
 * \param transaction Needed for internal use. Contains no user data. 
 * \return Result of the operation.
 *****************************************************************************/
MmsResult MMSlib_getBodyPart(MSF_UINT8 modId, MSF_UINT32 number, 
    unsigned char *data, MSF_UINT32 *size, 
    MmsMsgHandle *msg, MmsTransactionHandle *transaction);

/*!
 * \brief Get information about a message
 *
 * Type: Function call 
 *
 * \param modId In: MSF module identification 
 * \param header Out: The message header.
 * \param msg In: Information about the file and message.
 * \param transaction Needed for internal use. Contains no user data. 
 * \return Result of the operation.
 *****************************************************************************/
MmsResult MMSlib_getMessageHeader(MSF_UINT8 modId, MmsGetHeader *mHeader, 
    MmsMsgHandle *msg, MmsTransactionHandle *transaction);

/*!
 * \brief Get a notification message
 *
 * Type: Function call 
 *
 * \param modId In: MSF module identification 
 * \param MmsNotification Out: The notification message.
 * \param msg In: Information about the file and message.
 * \param transaction Needed for internal use. Contains no user data. 
 * \return Result of the operation.
 *****************************************************************************/
MmsResult MMSlib_getNotification( MSF_UINT8 modId, MmsNotification *msgNotif,
    MmsMsgHandle *msg, MmsTransactionHandle *transaction);

/*!
 * \brief Appends a new part to the message body
 *
 * A new body part or attachment is appended to the message 
 *
 * Type: Function call
 *
 * \param modId In: MSF module identification 
 * \param params In: Body parameters, e.g. contenttype. The caller is 
 *        responsible for freeing this memory when complete.
 * \param data In: Buffer holding the body data. The caller is responsible 
 *        for freeing this memory when complete.
 * \param size In: Size of data buffer.
 * \param msg In: Information about the file and message.
 * \param transaction Needed for internal use. Contains no user data. 
 * \return Result of the operation.
 *****************************************************************************/
MmsResult MMSlib_setMessageBody(MSF_UINT8 modId, MmsBodyParams *params,
    unsigned char *data, MSF_UINT32 size, MmsMsgHandle *msg, 
    MmsTransactionHandle *transaction);

/*!
 * \brief The header information of amessage with identidy msgId is set.
 *
 * The header is inserted in the message with the specified message ID
 * Note: This function makes use of asynchron file operations. Upon a reply 
 *       indicating a "wait and try later" must this function be called again. 
 *
 * Type: Function call
 *
 * \param modId In: MSF module identification 
 * \param numOfBodyParts In: The number of body parts that belongs to this message.
 * \param header In: The header information for the message.
 * \param version In: The version of the MMS Server.
 * \param msg In: Information about the file and message.
 * \param transaction Needed for internal use. Contains no user data. 
 * \return Result of the operation.
 *****************************************************************************/
MmsResult MMSlib_setMessageHeader(MSF_UINT8 modId, MSF_UINT32 numOfBodyParts, 
    MmsSetHeader *header, MmsVersion version, MmsMsgHandle *msg, 
    MmsTransactionHandle *transaction);

/*!
 * \brief Opens a message.
 *
 *  Type: Function call
 *
 * \param modId In: MSF module identification 
 * \param msgId In: The message id of the file to be opened.
 * \param msgType In: The type of the message. Valid types 
 *                     MMS_SUFFIX_TEMPLATE
 *                     MMS_SUFFIX_NOTIFICATION
 *                     MMS_SUFFIX_IMMEDIATE
 *                     MMS_SUFFIX_SEND_REQ
 *                     MMS_SUFFIX_MSG
 * \param msgHandle Out: The messageHandle to the file opened.
 * \return Result of the operation.
*****************************************************************************/
MmsResult MMSlib_messageOpen( MSF_UINT8 modId, MmsMsgId msgId, 
    MmsFileType msgType, MmsMsgHandle *msg);

/*!
 * \brief Closes a message.
 *
 *  Type: Function call
 *
 * \param modId In: MSF module identification 
 * \param msgHandle Out: The messageHandle to the file to close.
 * \return Result of the operation.
*****************************************************************************/
MmsResult MMSlib_messageClose( MSF_UINT8 modId, MmsMsgHandle *msg);

/*!
 * \brief Opens a transaction.
 *
 *  Type: Function call
 *
 * \param modId In: MSF module identification 
 * \param transaction Needed for internal use. Contains no user data. 
 * \return Result of the operation.
*****************************************************************************/
MmsResult MMSlib_transactionOpen( MSF_UINT8 modId,
    MmsTransactionHandle *transaction);

/*!
 * \brief Closes a transaction.
 *
 *  Type: Function call
 *
 * \param modId In: MSF module identification 
 * \param transaction Needed for internal use. Contains no user data. 
 * \return Result of the operation.
*****************************************************************************/
MmsResult MMSlib_transactionClose( MSF_UINT8 modId,
    MmsTransactionHandle *transaction);

/*!
 * \brief Frees a MmsGetHeader data structure.
 *
 *  Type: Function call
 *
 * \param modId In: MSF module identification 
 * \param mHeader Out: The data to free 
*****************************************************************************/
void MMSlib_freeMmsGetHeader( MSF_UINT8 modId, MmsGetHeader *mHeader);

/*!
 * \brief Frees a MmsSetHeader data structure.
 *
 *  Type: Function call
 *
 * \param modId In: MSF module identification 
 * \param mHeader In: The data to free 
*****************************************************************************/
void MMSlib_freeMmsSetHeader( MSF_UINT8 modId, MmsSetHeader *mHeader);

/*!
 * \brief Frees a MmsNotification data structure.
 *
 *  Type: Function call
 *
 * \param modId In: MSF module identification 
 * \param mNotification In: The data to free 
*****************************************************************************/
void MMSlib_freeMmsNotification( MSF_UINT8 modId, MmsNotification *mNotification);

/*!
 * \brief Builds a full path from a message id.
 *
 *  Type: Function call
 *
 * \param modId In: MSF module identification 
 * \param msgId In: The mesesage id.
 * \param fileType In: The file suffix char
 * \return the full path or NULL 
*****************************************************************************/
char *MMSlib_getMessageFullPath( MSF_UINT8 modId, MmsMsgId msgId, 
                                MmsFileType fileType);

#endif  /* _MMSL_IF_H */


