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

/*! \file mms_if.h
 * \brief  Exported signal functions towards the MMS Service.
 *
 * Exported connector functions, i.e. from Target Device Application to the MMS 
 * client. For every connector function, the following data are listed:
 * - A brief one line description of the function
 * - A longer description of the function
 * - The type of the function. It can be either:
 *     -# Signal function: The function encapsulates the passed parameters into
 *        a MSF signal and sent it to the MMS Service 
 *        The result will be returned in a reply signal.
 *
 *     -# Converter function: unpack the recived signals into the data types
 *        used by the MFS. This function is to be registrated in MSF
 *      
 * - Reply signal name
 * - The parameters for the function
 */

#ifndef _MMS_IF_H
#define _MMS_IF_H

#ifndef _MMS_CFG_H  /* Check so the mms_cfg.h file is included before this file */
#error You must #include mms_cfg.h before this file.
#error The file mms_cfg.h contains configuration data for all other MMS files.
#error Please change the .c file that stopped from compiling because you came here
#error so that it includes mms_cfg.h before this file.
#endif /* _MMS_CFG_H */

/*--- Definitions/Declarations ---*/

/*--- Types ---*/

/*! \typedef MmsIfConvertFunction
 * Function pointer for convertion functions of the type mms_cvt_xxx(...)
 */
typedef int MmsIfConvertFunction(msf_dcvt_t *obj, void *data);
typedef int MmsIfConvertFunctionArray(msf_dcvt_t *obj, void *data, 
    MSF_UINT32 size);

/*--- Constants ---*/

/* Signals */

/* 
 *!\brief Signal Identifications 
 *                        Format:  16 bit = ! 8bit   ! 8bit  ! 
 *                                          !  SigId ! Modid !
 */

/*--- Replied signals from MMS Service ---*/
#define MMS_SIG_CREATE_MSG_REPLY     ((MSF_MODID_MMS << 8) + 0x01) 
#define MMS_SIG_DELETE_MSG_REPLY     ((MSF_MODID_MMS << 8) + 0x02)
#define MMS_SIG_FORWARD_REQ_REPLY    ((MSF_MODID_MMS << 8) + 0x03)
#define MMS_SIG_GET_NUM_OF_MSG_REPLY ((MSF_MODID_MMS << 8) + 0x04)
#define MMS_SIG_MOV_MSG_REPLY        ((MSF_MODID_MMS << 8) + 0x05)
#define MMS_SIG_RETRIEVE_MSG_REPLY   ((MSF_MODID_MMS << 8) + 0x06)
#define MMS_SIG_SEND_MSG_REPLY       ((MSF_MODID_MMS << 8) + 0x07)
#define MMS_SIG_READ_REPORT_IND      ((MSF_MODID_MMS << 8) + 0x08)
#define MMS_SIG_DELIVERY_REPORT      ((MSF_MODID_MMS << 8) + 0x09)
#define MMS_SIG_ERROR                ((MSF_MODID_MMS << 8) + 0x0A)
#define MMS_SIG_NOTIFICATION         ((MSF_MODID_MMS << 8) + 0x0B)
#define MMS_SIG_SEND_RR_REPLY        ((MSF_MODID_MMS << 8) + 0x0C)
#define MMS_SIG_MSG_DONE_REPLY       ((MSF_MODID_MMS << 8) + 0x0D)
#define MMS_SIG_GET_FLDR_REPLY       ((MSF_MODID_MMS << 8) + 0x0E)
#define MMS_SIG_FOLDER_STATUS_REPLY  ((MSF_MODID_MMS << 8) + 0x0F)
#define MMS_SIG_PROGRESS_STATUS_REPLY ((MSF_MODID_MMS << 8) + 0x10)
#define MMS_SIG_GET_MSG_INFO_REPLY   ((MSF_MODID_MMS << 8) + 0x11)

/*--- Signals sent to MMS Service ---*/             
#define MMS_SIG_CREATE_MSG           ((MSF_MODID_MMS << 8) + 0x30) 
#define MMS_SIG_DELETE_MSG           ((MSF_MODID_MMS << 8) + 0x31) 
#define MMS_SIG_FORWARD_REQ          ((MSF_MODID_MMS << 8) + 0x32) 
#define MMS_SIG_GET_NUM_OF_MSG       ((MSF_MODID_MMS << 8) + 0x33) 
#define MMS_SIG_MOVE_MSG             ((MSF_MODID_MMS << 8) + 0x34) 
#define MMS_SIG_RETRIEVE_MSG         ((MSF_MODID_MMS << 8) + 0x35) 
#define MMS_SIG_RETRIEVE_MSG_CANCEL  ((MSF_MODID_MMS << 8) + 0x36) 
#define MMS_SIG_SEND_MSG             ((MSF_MODID_MMS << 8) + 0x37) 
#define MMS_SIG_SEND_MSG_CANCEL      ((MSF_MODID_MMS << 8) + 0x38) 
#define MMS_SIG_READ_REPORT          ((MSF_MODID_MMS << 8) + 0x39) 
#define MMS_SIG_CONFIG_STR           ((MSF_MODID_MMS << 8) + 0x3A) 
#define MMS_SIG_MSG_DONE             ((MSF_MODID_MMS << 8) + 0x3B) 
#define MMS_SIG_GET_FLDR             ((MSF_MODID_MMS << 8) + 0x3C) 
#define MMS_SIG_SET_READ_MARK        ((MSF_MODID_MMS << 8) + 0x3D) 
#define MMS_SIG_GET_REPORT           ((MSF_MODID_MMS << 8) + 0x3E) 
#define MMS_SIG_FOLDER_STATUS        ((MSF_MODID_MMS << 8) + 0x3F) 
#define MMS_SIG_APP_REG              ((MSF_MODID_MMS << 8) + 0x40) 
#define MMS_SIG_GET_MSG_INFO         ((MSF_MODID_MMS << 8) + 0x41) 
#define MMS_SIG_SIM_INFO_NOTIFY_IND  ((MSF_MODID_MMS << 8) + 0x42) 

/*--- Signal parameters ---*/


/* 
 *! \brief Signal struct for sending message file type
 */ 
typedef struct
{
    MmsFileType fileType; /*!< The file type */
} MmsFileTypeSig; 


/* 
 *! \brief Signal struct for sending application registration 
 */ 
typedef struct
{
    MSF_UINT8 source; /*!< The caller MSF module id */
} MmsAppReg; 
 
/*
 *! \brief Signal Struct sending message id
 */
typedef struct 
{
   MmsMsgId  msgId; /*!< Message identification */
} MmsMsgSig;


typedef struct 
{
   MSF_UINT8      source;   /*!< Requesting module */
   MmsFolderType  folderId; /*!< Folder identification */
} MmsFolderSig;

/*
 * ! \brief Signal Struct sending message move/create done 
 */
typedef struct 
{
    MmsMsgId msgId; /*!< Message identification */
    MmsFolderType folder; /*!< folder */
} MmsMsgFolderSig;

/*
 * ! \brief Signal Struct sending read report
 */
typedef struct 
{
    MmsMsgId msgId; /*!< Message identification */
    MmsReadStatus readStatus; /*! Read status */
} MmsSendReadReport; 

/* 
 * ! \brief Signal Struct for manage the read mark for a specified file 
 */
typedef struct 
{
    MmsMsgId msgId;  /*!< Message identification */
    MSF_UINT8 value; /*!< 1= set or 0= clear */
} MmsSetReadMark;    
    
/*
 * !\brief Signal struct for sending PDU 
 */
typedef struct
{
    MSF_UINT32 length;   /*!< length of PDU */
    unsigned char *pdu;  /*!< vector holding the PDU */
} MmsPduSig; 

/* 
 * !\breif Signal struct for retrieving status for the
 *   persistent storage (mms folder)
 */
typedef struct 
{
    MSF_UINT32 usedMsgBytes; /*!< the total size of files visible in MMT list*/
    MSF_UINT32 numOfMsg;     /*!< total number of message */ 
    MSF_UINT32 totalFolderSize; /*!< total size of all files in the MMS folder */
} MmsFolderStatus; 

/******************************************************************************* 
 * Signal parameters sent from the MMS Service 
 ******************************************************************************/
#ifdef __MMS_DUAL_SIM_SUPPORT__
typedef struct  
{
  MSF_UINT8   sim_status;
  MSF_UINT8   setting_mode;
}MmsSimInfoNotifySig;
#endif

/*
 *! \brief Signal Struct replying result
 */
typedef struct 
{  
    MmsResult result; /*!< Returned operation code */
    MSF_INT32 responseStatus;  /*!< Returend response status from MMS-C in case of Sending and forwarding */
    char*     responseText;     /*! < Returend response status from MMS-C in case of Sending and forwarding in text */
} MmsResultSig;

/*
 *! \brief Signal Struct replying result
 */
typedef struct 
{  
    MmsResult result; /*!< Returned operation code */
    MSF_UINT32 msgId; /*!< Message reference identification */  
} MmsMsgDoneReplySig;

/*
 *! \brief Signal Structs replying data  
 */
typedef struct 
{
   MmsResult result; /*!< Returned operation code */
   MmsMsgId msgId;   /*!< Message reference identification */
} MmsMsgReplySig;

/*
 *! \brief Signal Structs replying data  
 */
typedef struct 
{
   MmsResult result; /*!< Returned operation code */
   MmsMsgId msgId;   /*!< Message reference identification */
   MmsMsgId rrId;    /*!< Read-report reference identification */
} MmsRRReplySig;

/*
 * ! \brief Signal struct replying number of message 
 */
typedef struct 
{ 
    MmsResult result;      /*!< Returned operation code */
    MSF_UINT32 number;     /*!< Number of messages */
    MmsFolderType folder;  /*!< Folder identity */
} MmsMsgReplyNoOfMsg;

/*
 * ! \brief Signal struct service  indication for received message
 */
typedef struct
{
    MmsNotificationType type;   /*!< Type of notification, (eg. Notification */
    MmsMsgId notifId;           /*!< Message reference identification */
    MSF_UINT32 size;            /*!< Size of message */

    /* Sender address, normally an MmsAddress but here splitted into plain types */
    MmsCharset  fromCharset;    /*!< Well-known character set as defined by IANA */
    char        *fromName;      /*!< Display name (e.g. Bill Löfgren, AU-System) */
    char        *fromAddress;   /*!< Address (e.g. bill.lofgren@ausystem.se) */
    MmsAddressType fromAddrType;/*!< Address Type (PLMN or EMAIL) */

    /* Subject, normally an MmsEncodedText but here splitted into plain types */
    MmsCharset  subjectCharset; /*!< Well-known character set as defined by IANA */
    char        *subjectText;   /*!< Text buffer, must be NULL terminated */
} MmsMsgReplyNotification;

/*
 * ! \brief Signal struct received read report 
 */
typedef struct 
{
    char *address;            /*!< Address (e.g. bill.lofgren@ausystem.se) */
    MmsAddressType addrType;  /*!< Address Type (PLMN or EMAIL) */
    MmsCharset  charset;      /*!< Well-known character set as defined by IANA */
    char        *text;        /*!< Text buffer, must be NULL terminated */ 
    MmsTimeSec date;          /*!< Arrival time of the message at the MMSProxy-Relay. */
    char *serverMessageId;    /*!< Unique reference assigned to the message */
    MmsReadStatus readStatus; /*!< Read-Status of the message.*/
    MSF_UINT32 msgId;         /*!< Message is to the orignated message or zero if it is 
                                   not found */
    MSF_UINT32 msgIdFile;     /*!< Message id for the stored message */        
} MmsMsgReadReport; 

/* 
 * ! \brief Signal struct received delivery report
 */ 
typedef struct 
{
    char *serverMsgId;          /*!< The unique reference (assigned by the MMS Proxy-Relay)
                            to the message. */
    char *address;              /*!< The recipent address. */
    MmsAddressType addrType;    /*!< Address Type (PLMN or EMAIL) */
    MmsCharset  charset;        /*!< Well-known character set as defined by IANA */
    char        *text;          /*!< Arrival time of the message at the MMSProxy-Relay. */
    MmsTimeSec date;            /*!< Date and time when the message was handled */
    MmsStatus status;           /*!< Status of the message. */
    MSF_UINT32 msgId;           /*!< Message id to the orignated message or zero not
                                     found */ 
    MSF_UINT32 msgIdFile;       /*!< Message id for the stored message */    
} MmsMsgDeliveryReportInd;

/* 
 * ! \brief Signal struct for requesting a conent list of message.
 */ 
typedef struct
{
  MmsFolderType folderId;  /*!< The folder where message is stored */
  MSF_INT32 from;          /*!< starting number in the list        */
  MSF_INT32 to;            /*!< stoping number in the list         */
} MmsMsgContentReq;

/*
 *! \brief Information kept for every message stored in a folder.
 */
typedef struct 
{
    MmsFolderType folderId; /*!< the folder location */
    MSF_UINT32 msgId;       /*!< message Id          */
#ifdef __MMS_DUAL_SIM_SUPPORT__
    MSF_UINT32 simId;       /*MMS_SIM_CARD_MASTER or MMS_SIM_CARD_SLAVE*/
#endif
    MSF_UINT32 size;        /*!< size of the message */
    MSF_UINT32 date;        /*!< date of the message */
    char serverMsgId[MAX_MMT_SERVER_MSG_ID_LEN]; /*!< server message id */
    char address[MAX_MMT_ADDRESS_LEN]; /*!< address of sender or receiver of the message */
    char subject[MAX_MMT_SUBJECT_LEN]; /*!< the subject of the message */ 
    MmsFileType suffix;     /*!< define the type of file */
    MSF_UINT8 sent;         /*!< is set to 1 if sent */
    MSF_UINT8 read;         /*!< is set to 1 if read */ 
    MSF_UINT8 rrReq;        /*!< no of requested read reports */ 
    MSF_UINT8 rrRead;       /*!< no of read read reports */
    MSF_UINT8 rrDel;        /*!< no of deleted read reports */
    MSF_UINT8 drReq;        /*!< no of requested delivery reports */
    MSF_UINT8 drRec;        /*!< no of received delivery reports */    
    MSF_BOOL forwardLock;   /*!< is set to TRUE if DRM-forward-locked */
    MmsPriority priority;   /*!< Priority of message */
    int  class;              /*!< Class of message TR18100 */
} MmsMessageFolderInfo;

typedef struct
{
    MmsMessageFolderInfo    msgFolderInfo;
    MSF_UINT8                rrListLength;
    MSF_UINT32               *rrList; /* List of MsdIds */
    MSF_UINT8                drListLength;
    MSF_UINT32               *drList; /* List of MsgIds */
} MmsMessageProperties;

/*
 * ! \brief Signal struct replying a list of stored message in folder 
 *          reply data MMS_SIG_GET_FOLDER_CONTENT
 */
typedef struct 
{
    MSF_UINT32 noOfElements;                    /*!< Number of elements in the array below */ 
    MmsMessageProperties *msgPropertyList;      /*!<    First field in an array of unspecified length */
} MmsListOfProperties;


/*--- Prototypes ---*/

/*!
 * \brief Start the interface
 *
 * This function starts the interface towards the MMS Service. It must 
 * be called before any operation in the interface is used. 
 *
 * Type: Function call
 *
 *****************************************************************************/
void MMSif_startInterface(void);

/*!
 * \brief Registry the application to the service
 *
 * This function registry the MMS application (MEA) as a receiver for 
 * notification signals. Hence, this function needs to be called before the 
 * application can receive any spontanious signals. 
 *
 * Type: Function signal
 *      signal name: #MMS_SIG_APP_REG
 *      data type    #MmsAppReg
 *
 * \param source The calling module identity
 *****************************************************************************/
 void MMSif_applicationReg(MSF_UINT8 source);
 
/*!
 * \brief Creates an empty message in the draft folder.
 *
 * All operations (e.g. send, move, modify) on messages in the MMS client uses 
 * a unique message ID. Before these operations can be performed, a message 
 * must be created in the Draft folder. This function performs both operations.
 *
 * Type: Signal Function 
 *
 * Reply Signal: 
 *      signal name: #MMS_SIG_CREATE_MSG_REPLY
 *      data type    #MmsMsgReplySig
 *
 * \param source The calling module identity
 *****************************************************************************/
void MMSif_createMessage(MSF_UINT8 source,  MmsFileType fileType);

/*!
 * \brief Deletes a stored message.
 *
 * A previously stored message is deleted from whatever folder it is stored in.
 * Both body and header part of the message is deleted.
 *
 * Type: Signal Function
 *
 * Reply signal
 *      signal name: #MMS_SIG_DELETE_MSG_REPLY
 *      data type    #MmsResultSig
 *
 * \param source The calling module identity
 * \param msgId A unique identity for a multimedia message.
 *****************************************************************************/
void MMSif_deleteMessage(MSF_UINT8 source, MmsMsgId msgId);

/*!
 * \brief Creates and sends a forward request to a MMS-Proxy-Relay.
 *
 * When a notification has been recieved, the MMS Application can send a 
 * request to the MMS-Proxy-Relay to directly forward the message to another 
 * recipient before the actually message has been fetched.
 *
 * Type: Signal Function
 *
 * Reply signal:
 *       signal name: #MMS_SIG_FORWARD_REQ_REPLY 
 *       data type:   MmsResultSig
 *
 * \param source The calling module identity
 * \param forward Information about the forward to be made, this parameter must 
 *        be copied if needed after the function returned.
 * \param contentlocation The content location from found in the notification 
 *        message to be used in the forward request.
 * \param version The protcol (PDU) version 
 *****************************************************************************/
MmsResult MMSif_forwardReq(MSF_UINT8 source, const MmsForward *forward, 
     char *contentLocation, MmsVersion version);

/*!
 * \brief Get the number of messages in one or all folder.  
 *
 * Type: Signal Function
 *
 * Reply signal:
 *       signal name: #MMS_SIG_GET_NUM_OF_MSG_REPLY
 *       data type:   #MmsMsgReplyNoOfMsg
 *
 * \param source The calling module identity
 * \param folder What folder to count messages in. If the request concerns 
 *        all folders MMS_ALL_FOLDERS should be used. 
 *****************************************************************************/
void MMSif_getNumberOfMessages(MSF_UINT8 source, MmsFolderType folder);

/*!
 * \brief Move a message between folders. 
 *
 * A message indicated by the message ID is moved from the current folder 
 * to the new folder that is given as parameter.
 *
 * Type: Signal Function 
 *
 * Reply signal:
 *       signal name: #MMS_SIG_MOV_MSG_REPLY
 *       data type:   #MmsResultSig
 *
 * \param source The calling module identity
 * \param msgId A unique identity for a multimedia message.
 * \param folder The folder that the message shall be moved to. 
 *        NOTE! MMS_ALL_FOLDERS is not a vaild value in this operation.
 *****************************************************************************/
void MMSif_moveMessage(MSF_UINT8 source, MmsMsgId msgId,
    MmsFolderType toFolder);

/*!
 * \brief Cancel an ongoing Retrieve operation for a message.
 *
 * An ongoing Retrieve operation on a multimedia message is cancelled.
 * Only one type of operation can be executed at a time so the last
 * call to MMSc_retrieveMessage for the given notification ID is terminated. 
 *
 * Type: Signal Function
 *
 * Reply signal name: None.
 *
 * \param source The calling module identity
 * \param notifId The identity of a notification.
 *****************************************************************************/
void MMSif_retrieveCancel(MSF_UINT8 source, MmsMsgId notifId);

/*!
 * \brief Retrieve a message from the MMS server.
 *
 * A multimedia message is retrieved from the MMS Proxy-Relay and is stored in the 
 * Inbox.
 *
 * Type: Signal Function
 *
 * Reply signal
 *       signal name: #MMS_SIG_RETRIEVE_MSG_REPLY
 *       data type:   #MmsMsgReplySig
 *                  
 * \param source The calling module identity
 * \param notifId The identity of a notification.
 *****************************************************************************/
void MMSif_retrieveMessage(MSF_UINT8 source, MmsMsgId notifId);

/*!
 * \brief Cancel an ongoing Send operation for a message.
 *
 * An ongoing Send operation on a multimedia message is cancelled.
 * Only one type of operation can be executed at a time so the last call
 * to MMSc_sendMessage for the given message ID is terminated.
 *
 * Type: Signal Function 
 *
 * Reply signal name: None.
 *
 * \param source The calling module identity
 * \param msgId The unique identity for a multimedia message.
 *****************************************************************************/
void MMSif_sendCancel(MSF_UINT8 source, MmsMsgId msgId);

/*!
 * \brief Sends a Multimedia Message
 * 
 * The Multimedia Message must exist and be stored in one 
 * of the folders before this function can be called. 
 *
 * Type: Signal Function 
 *
 * Reply signal:
 *       signal name: #MMS_SIG_SEND_MSG_REPLY
 *       data type:   #MmsResultSig
 *
 * \param source The calling module identity
 * \param msgId A unique identity for a multimedia message.
 *****************************************************************************/
void MMSif_sendMessage(MSF_UINT8 source, MmsMsgId msgId);

#ifdef __MMS_DUAL_SIM_SUPPORT__
void MMSif_sendMessageExt(MSF_UINT8 source, MmsMsgId msgId, MmsSimCardEnum simId);
#endif

/*!
 * \brief Sends a Read Report for a Multimedia Message
 * 
 * The TDA has detected that the Multimedia Message identified by msgId 
 * contains a Read Report flag and the TDA has decided that a Read Report shall 
 * be sent. When calling this function, all data needed will be collected an 
 * the Read Report will be sent.
 *
 * Type: Signal Function 
 *
 * Reply signal 
 *       signal name: #MMS_SIG_SEND_RR_REPLY
 *       data type:   #MmsResultSig
 *
 * \param source The calling module identity
 * \param msgId A unique identity for a multimedia message.
 * \param readStatus Status of the message to send read report on.
 *****************************************************************************/
void MMSif_sendReadReport(MSF_UINT8 source, MmsMsgId msgId,
    MmsReadStatus readStatus);
                        
/*!
 * \brief Indicates end of messge creation
 *
 * Type: Signal Function 
 *
 * Reply signal: 
 *       signal name: #MMS_SIG_MSG_DONE_REPLY
 *       data type:   #MmsMsgReplySig
 *
 * This function indicates to the MMS client that the creation of a message is 
 * done. When creating a Multimedia Message, it can contain multiple parts. 
 * When this connector is called, no more parts will be added. 
 *
 * \param msgId A unique identity for a multimedia message.
 *****************************************************************************/
 void MMSif_createMessageDone(MSF_UINT8 source, MmsMsgId msgId, MmsFolderType folder);
#ifdef __MMS_DUAL_SIM_SUPPORT__
 void MMSif_createMessageDoneExt(MSF_UINT8 source, MmsMsgId msgId, MmsFolderType folder, MmsSimCardEnum simId);
#endif
/*!
 * \brief Request a content of messages from a folder
 *
 * Type: Signal Function 
 *
 * Reply signal
 *       signal name: #MMS_SIG_GET_FLDR_REPLY
 *       data type: (void *) byte vector that must be casted to 
 *                  the type #MmsListOfProperties.
 *
 * This function reqests a list of message information stored in one of the 
 * folders. The order of the list can be sorted by fields: 
 *  - received  date
 *  - address   when the message is in the Draft, Outbox or Sent folder is 
 *              the "To" field used else is the "From" field used (inbox).
 *  - subject   compers the XX firt chars in the subject field. 
 *
 * \param folderId The folder where message is stored.  
 * \param sortedBy The content list is sorted by date, address or subject.
 * \param from  starting number in the list
 * \param to    stoping number in the list
  *****************************************************************************/
 void MMSif_getFolderContent(MSF_UINT8 source, MmsFolderType folderId, 
      int from, int to);

/*!
 * \brief Request information about a specific messages
 *
 * Type: Signal Function 
 *
 * Reply signal
 *       signal name: #MMS_SIG_GET_MSG_INFO_REPLY
 *       data type: (void *) byte vector that must be casted to 
 *                  the type #MmsListOfProperties.
 *
 * This function reqests a information about a message.
 *
 * \param source, Module ID of the requesting module (caller).  
 * \param msgId, Message that information is requested for.
  *****************************************************************************/
 void MMSif_getMessageInfo(MSF_UINT8 source, MSF_UINT32 msgId);

/*!
 * \brief Set the the read mark file 
 *
 * Type: Signal Function 
 *
 * Related Signal: None
 *
 * This function manage the setting of the read mark value for a file. 
 * The function is used to mark the file if it has been read or not. 
 *
 * \param msgId The message id that be assigned with the read mark
 * \param value Set value. 1 = read, 0 = not read. 
 *****************************************************************************/
void MMSif_setReadMark(MSF_UINT8 source, MmsMsgId msgId, MSF_UINT8 value);

/*!
 * \brief Get report conent
 * 
 * Type: Signal Function 
 * 
 * Related Signal: Depends of the report type 
 *  
 *                #MMS_SIG_READ_REPORT if the requested report was a 
 *                                     read report. 
 *                                     data type: MmsMsgReadReport  
 *
 *                #MMS_SIG_DELIVERY_REPORT if the requested report was a 
 *                                        delivery report.
 *                                        data type: MmsMsgDeliveryReportInd
 *
 *                #MMS_SIG_ERROR is used for reporting faults detected during 
 *                               this operation. 
 *
 * The function request for the content in a PDU of the type Delivery or 
 * Read Report. Note that Read Report is a PDU in 1.1 version and higher. 
 * The reports must be stored in the MMS folder.
 *****************************************************************************/
void MMSif_getReport(MSF_UINT8 source, MmsMsgId msgId);

/*!
 * \brief Request the status of peristent storage in the MMS folder
 *
 *
 * Type: Signal Function
 *
 * Reply signal
 *      signal name: #MMS_SIG_FOLDER_STATUS_REPLY
 *      data type    #MmsFolderStatus
 *
 * \param source The calling module identity
 *****************************************************************************/
void MMSif_getFolderStatus(MSF_UINT8 source, MmsFolderType folderId);

/*
 * MSF functions 
 *
 *****************************************************************************/

MSF_BOOL mmsSendSignalExt(MSF_UINT8 senderModId, MSF_UINT8 destModule,
    MSF_UINT16 signal, void *data, MmsIfConvertFunction *cvtFunPtr); 
MSF_BOOL mmsSendSignalExtArray(MSF_UINT8 senderModId, MSF_UINT8 destModule,
    MSF_UINT16 signal, void *data, MmsIfConvertFunctionArray *cvtFunPtr, 
    MSF_UINT32 size); 
MSF_BOOL mmsSendSignalExtNoData(MSF_UINT8 senderModId, MSF_UINT8 destModule,
    MSF_UINT16 signal);



/*!
 * \brief Deallocate a signal buffer
 *
 * This function is used by the MSF to free signal memory.
 *
 * Type: Function call
 *
 * \param source The calling module identity
 * \param signal Signal identity
 * \param ptr The signal buffer
 *****************************************************************************/
void mmsDestruct(MSF_UINT8 module, MSF_UINT16 signal, void *ptr); 

/*!
 * \brief Converts a serielized signal buffer into signal struct
 *
 * The function is called from MSF when signals is to be converted.
 *
 * Type: Function call
 *
 *
 * \param source The calling module identity
 * \param signal Signal identity
 * \param buffer The signal buffer
 *****************************************************************************/
void *mmsConvert (MSF_UINT8 modId, MSF_UINT16 signal, void *buffer);


/*!
 * \brief  Converts a parameters into a signal buffer for MmsAppReg 
 * 
 * \param obj  The MSF obejct. 
 * \param data The data structure to convert to
 *****************************************************************************/
int mms_cvt_MmsAppReg(msf_dcvt_t *obj, MmsAppReg *data);

/*!
 * \brief  Converts a parameters into a signal buffer for MmsMsgFolderSig 
 * 
 * \param obj  The MSF obejct. 
 * \param data The data structure to convert to
 *****************************************************************************/
int mms_cvt_MmsMsgFolder(msf_dcvt_t *obj, MmsMsgFolderSig *data); 

/*!
 * \brief  Converts a parameters into a signal buffer for MmsSendReadReport 
 * 
 * \param obj  The MSF obejct. 
 * \param data The data structure to convert to
 *****************************************************************************/
int mms_cvt_MmsSendReadReport(msf_dcvt_t *obj, MmsSendReadReport *data);

/*!
 * \brief  Converts a parameters into a signal buffer for MmsMsgSig 
 * 
 * \param obj  The MSF obejct. 
 * \param data The data structure to convert to
 *****************************************************************************/
int mms_cvt_MmsMsg(msf_dcvt_t *obj, MmsMsgSig *data);


/*!
 * \brief  Converts a parameters into a signal buffer for MmsFolderSig 
 * 
 * \param obj  The MSF obejct. 
 * \param data The data structure to convert to
 *****************************************************************************/
int mms_cvt_MmsFolderId(msf_dcvt_t *obj, MmsFolderSig *data);

/*!
 * \brief  Converts a parameters into a signal buffer for MmsResultSig 
 * 
 * \param obj  The MSF obejct. 
 * \param data The data structure to convert to
 ***********************************************************************/
int mms_cvt_MmsResult(msf_dcvt_t *obj, MmsResultSig *data);

/*!
 * \brief  Converts a parameters into a signal buffer for MmsMsgReplySig 
 * 
 * \param obj  The MSF obejct. 
 * \param data The data structure to convert to
 * \return TRUE if OK else FALSE 
 *****************************************************************************/
int mms_cvt_MmsMsgReply(msf_dcvt_t *obj, MmsMsgReplySig *data);

/*!
 * \brief  Converts a parameters into a signal buffer for MmsRRReplySig 
 * 
 * \param obj  The MSF obejct. 
 * \param data The data structure to convert to
 * \return TRUE if OK else FALSE 
 *****************************************************************************/
int mms_cvt_MmsRRReplySig(msf_dcvt_t *obj, MmsRRReplySig *data);

/*!
 * \brief  Converts a parameters into a signal buffer for MmsMsgReplyNoOfMsg 
 * 
 * \param obj  The MSF obejct. 
 * \param data The data structure to convert to
 * \return TRUE if OK else FALSE 
 *****************************************************************************/
int mms_cvt_MmsMsgReplyNoOfMsg(msf_dcvt_t *obj, MmsMsgReplyNoOfMsg *data);

/*!
 * \brief  Converts a parameters into a signal buffer for 
 *         MmsMsgReplyNotificationMsg 
 * 
 * \param obj  The MSF obejct. 
 * \param data The data structure to convert to
 * \return TRUE if OK else FALSE 
 *****************************************************************************/
int mms_cvt_MmsMsgNotificationMsg(msf_dcvt_t *obj, 
    MmsMsgReplyNotification *data);

/*!
 * \brief  Converts a parameters into a signal buffer for 
 *         MmsMsgDeliveryReportInd 
 * 
 * \param obj  The MSF obejct. 
 * \param data The data structure to convert to
 * \return TRUE if OK else FALSE 
 *****************************************************************************/
int mms_cvt_MmsMsgDeliveryReport(msf_dcvt_t *obj, 
    MmsMsgDeliveryReportInd *data);

/*!
 * \brief  Converts a parameters into a signal buffer for 
 *         MmsMsgReadReport 
 * 
 * \param obj  The MSF obejct. 
 * \param data The data structure to convert to
 * \return TRUE if OK else FALSE 
 *****************************************************************************/
int mms_cvt_MmsMsgReadReport(msf_dcvt_t *obj, MmsMsgReadReport *data);

/*!
 * \brief  Converts a parameters into a signal buffer for 
 *         MmsSetReadMark 
 * 
 * \param obj  The MSF obejct. 
 * \param data The data structure to convert to
 * \return TRUE if OK else FALSE 
 *****************************************************************************/
int mms_cvt_MmsSetReadMark(msf_dcvt_t *obj, MmsSetReadMark *data);

/*!
 * \brief  Converts a parameters into a signal buffer for 
 *         MmsSendPdu to be sent as a bit array
 * \param obj  The MSF obejct. 
 * \param data The data structure to convert to
 * \param len  The length of the data to convert
 * \return TRUE if OK else FALSE 
 *****************************************************************************/
int mms_cvt_MmsSendPdu(msf_dcvt_t *obj, MmsPduSig *data, MSF_UINT32 dataLen);

/*!
 * \brief  Converts a parameters into a signal buffer for 
 *         MmsFolderStatus 
 * 
 * \param obj  The MSF obejct. 
 * \param data The data structure to convert to
 * \return TRUE if OK else FALSE 
 *****************************************************************************/
int mms_cvt_MmsFolderStatus(msf_dcvt_t *obj, MmsFolderStatus *data);

/*!
 * \brief  Converts a parameters into a signal buffer for 
 *         MmsProgress 
 * 
 * \param obj  The MSF obejct. 
 * \param data The data structure to convert to
 * \return TRUE if OK else FALSE
 *****************************************************************************/
int mms_cvt_MmsProgressStatus(msf_dcvt_t *obj, MmsProgressStatus *data);


/*!
 *======================================================================
 * Exported MMS data structure operation functions:
 */


/*!
 *====================================
 * Operations on MmsMessageProperties.
 */

/*!
 * \brief Free the internal structure of MmsMessageProperties.
 *
 * \param properties    Structure to be freed.
 * \param module        Memory owner.
 */
void MMSif_freeMmsMessageProperties(MmsMessageProperties *properties,
                                    MSF_UINT8 module);

/*!
 * \brief Copy the internal structure of MmsMessageProperties.
 *
 * \param toProperties    Structure to be updated.
 * \param properties      Structure to be copied.
 * \param module          Memory owner.
 */
MSF_BOOL MMSif_copyMmsMessageProperties(MmsMessageProperties *toProperties, 
                                        MmsMessageProperties *fromProperties,
                                        MSF_UINT8 module);

/*!
 * \brief Free the internal structure of MmsMessageProperties.
 *
 * \param properties    Structure to be freed.
 * \param module        Memory owner.
 */
void MMSif_freeMmsListOfProperties(MmsListOfProperties *list,
                                    MSF_UINT8 module);

/*!
 * \brief Copy the internal structure of MmsMessageProperties.
 *
 * \param toProperties    Structure to be updated.
 * \param properties      Structure to be copied.
 * \param module          Memory owner.
 */
MSF_BOOL MMSif_copyMmsListOfProperties(MmsListOfProperties *toList, 
                                        MmsListOfProperties *fromList,
                                        MSF_UINT8 module);

/*!
 * \brief  Converts a parameters into a signal buffer for 
 *         MmsMessageProperties 
 * 
 * \param obj  The MSF obejct. 
 * \param data The data structure to convert to
 * \return TRUE if OK else FALSE
 *****************************************************************************/
int mms_cvt_MmsMessageProperties(msf_dcvt_t *obj, MmsMessageProperties *data);

/*
 * Convert list of message properties into a signal buffer
 *
 * \param obj  The MSF obejct. 
 * \param data The data structure to convert to
 * \return TRUE if OK else FALSE
*****************************************************************************/
int mms_cvt_MmsListOfProperties(msf_dcvt_t *obj, MmsListOfProperties *data);

#endif /* _MMS_IF_H */


