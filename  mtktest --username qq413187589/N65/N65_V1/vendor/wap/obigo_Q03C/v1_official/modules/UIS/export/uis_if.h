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
/*
 * uis_if.h
 *
 * Created by Klas Hermodsson, Mon May 19 16:56:01 2003.
 *
 * Revision  history:
 *
 * 2003-09-02 (KLHE): Added UISif_replyChangeMsg and UISif_notifyUnreadMsgCount.
 * 2003-09-22 (MADE): Added UISif_notifyUnreadMsgCount
 * 2003-10-03 (KLHE): Added UISif_notifyInvalidateAll,
 *                          UISif_setMsgProperty and
 *                          UISif_replySetMsgProperty.
 * 2003-10-07 (KLHE): Removed UISif_replyChangeMsg.
 * 2003-10-28 (KLHE): Made UIS_MSG_KEY_TO a title property.
 * 2003-11-20 (KLHE): Added the define UIS_NBR_OF_SYSTEM_KEYS.
 *                          Added the include of uis_ecfg.h which contains
 *                          the UIS_NBR_OF_USER_KEYS and the UIS_USER_TITLE_PROPERTY_ARRAY 
 *                          definition.
 * 2004-01-16 (KOGR): CR 13932: key UIS_MSG_KEY_STORAGE added
 * 2004-01-21 (KLHE): CR 13932: Added values for UIS_MSG_KEY_STORAGE as
 *                          UIS_MSG_KEY_VALUE_STORAGE_x.
 * 2004-01-22 (KLHE): Renamed UIS_MSG_KEY_READ_REPORT_REQUESTED to 
 *                          UIS_MSG_KEY_REPORT_STATUS and changed the type to UINT32.
 * 2004-02-16 (KOGR): CR 13636: key UIS_MSG_KEY_NBR_OF_MESSAGES_WAITING added
 * 2004-02-23 (KOGR): CR 13934/13626: added UIS_MSG_KEY_MSG_STATUS,
 *                    UIS_MSG_KEY_VALUE_MSG_STATUS_OK, UIS_MSG_KEY_VALUE_MSG_STATUS_INCOMPLETE
 */

#ifndef _uis_if_h
#define _uis_if_h

#ifndef _msf_cfg_h
  #include "msf_cfg.h"
#endif

#ifndef _msf_def_h
  #include "msf_def.h"
#endif

#ifndef _msf_dcvt_h
  #include "msf_dcvt.h"
#endif

#ifndef _uis_ecfg_h
  #include "uis_ecfg.h"
#endif

/**********************************************************************
 * Signals in the Unified Inbox API:
 **********************************************************************/

#define UIS_SIG_REGISTER                ((MSF_MODID_UIS << 8) + 0x00)
#define UIS_SIG_REPLY_REGISTER          ((MSF_MODID_UIS << 8) + 0x01)
#define UIS_SIG_DEREGISTER              ((MSF_MODID_UIS << 8) + 0x02)
#define UIS_SIG_GET_NBR_OF_MSGS         ((MSF_MODID_UIS << 8) + 0x03)
#define UIS_SIG_REPLY_NBR_OF_MSGS       ((MSF_MODID_UIS << 8) + 0x04)
#define UIS_SIG_GET_MSG_LIST            ((MSF_MODID_UIS << 8) + 0x05)
#define UIS_SIG_REPLY_MSG_LIST          ((MSF_MODID_UIS << 8) + 0x06)
#define UIS_SIG_GET_MSG                 ((MSF_MODID_UIS << 8) + 0x07)
#define UIS_SIG_REPLY_MSG               ((MSF_MODID_UIS << 8) + 0x08)
#define UIS_SIG_GET_FULL_MSG            ((MSF_MODID_UIS << 8) + 0x09)
#define UIS_SIG_REPLY_FULL_MSG          ((MSF_MODID_UIS << 8) + 0x0a)
#define UIS_SIG_DELETE_MSG              ((MSF_MODID_UIS << 8) + 0x0b)
#define UIS_SIG_REPLY_DELETE_MSG        ((MSF_MODID_UIS << 8) + 0x0c)
#define UIS_SIG_NOTIFY_MSG_DELETED      ((MSF_MODID_UIS << 8) + 0x0d)
#define UIS_SIG_CHANGE_MSG              ((MSF_MODID_UIS << 8) + 0x0e)
#define UIS_SIG_REPLY_CHANGE_MSG        ((MSF_MODID_UIS << 8) + 0x0f)
#define UIS_SIG_NOTIFY_MSG_CHANGED      ((MSF_MODID_UIS << 8) + 0x10)
#define UIS_SIG_NOTIFY_NEW_MSG          ((MSF_MODID_UIS << 8) + 0x11)
#define UIS_SIG_CREATE_MSG              ((MSF_MODID_UIS << 8) + 0x12)
#define UIS_SIG_REPLY_CREATE_MSG        ((MSF_MODID_UIS << 8) + 0x13)
#define UIS_SIG_NOTIFY_UNREAD_MSG_COUNT ((MSF_MODID_UIS << 8) + 0x14)
#define UIS_SIG_NOTIFY_INVALIDATE_ALL   ((MSF_MODID_UIS << 8) + 0x15)
#define UIS_SIG_SET_MSG_PROPERTY        ((MSF_MODID_UIS << 8) + 0x16)
#define UIS_SIG_REPLY_SET_MSG_PROPERTY  ((MSF_MODID_UIS << 8) + 0x17)

/**********************************************************************
 * Other constants:
 **********************************************************************/

#define UIS_NBR_OF_MSG_TYPES          (UIS_NBR_OF_SYSTEM_MSG_TYPES + UIS_NBR_OF_USER_MSG_TYPES)

#define UIS_NBR_OF_SYSTEM_MSG_TYPES   5
/* Message types */
#define UIS_MSG_TYPE_PUSH_SI          0x00
#define UIS_MSG_TYPE_PUSH_SL          0x01
#define UIS_MSG_TYPE_MMS              0x02
#define UIS_MSG_TYPE_EMS              0x03
#define UIS_MSG_TYPE_EMAIL            0x04

/* UIS usage roles */
#define UIS_ROLE_VIEWER               0x01
#define UIS_ROLE_OWNER                0x02 
#define UIS_ROLE_EDITOR               0x03

/* Result codes */
#define UIS_RESULT_SUCCESS            0x01
#define UIS_RESULT_FAILURE            0x02

/* Value types */
#define UIS_VALUE_TYPE_UINT32         0x00
#define UIS_VALUE_TYPE_INT32          0x01
#define UIS_VALUE_TYPE_UTF8           0x02
#define UIS_VALUE_TYPE_BOOL           0x03
#define UIS_VALUE_TYPE_BINARY         0x04

/* Max signal size (in bytes). Used to ensure that replyMsgList doesn't get too big */
#define UIS_MAX_SIGNAL_SIZE                   2000


/* internal folder names (values for UIS_MSG_KEY_FOLDER) */
#define UIS_MSG_KEY_VALUE_FOLDER_INBOX        "i"
#define UIS_MSG_KEY_VALUE_FOLDER_DRAFTS       "d"
#define UIS_MSG_KEY_VALUE_FOLDER_SENT         "s"
#define UIS_MSG_KEY_VALUE_FOLDER_OUTBOX       "o"
#define UIS_MSG_KEY_VALUE_FOLDER_TEMPLATES    "t"
#define UIS_MSG_KEY_VALUE_FOLDER_USER_DEF_0   "0"
#define UIS_MSG_KEY_VALUE_FOLDER_USER_DEF_1   "1"
#define UIS_MSG_KEY_VALUE_FOLDER_USER_DEF_2   "2"
#define UIS_MSG_KEY_VALUE_FOLDER_USER_DEF_3   "3"
#define UIS_MSG_KEY_VALUE_FOLDER_USER_DEF_4   "4"
#define UIS_MSG_KEY_VALUE_FOLDER_USER_DEF_5   "5"
#define UIS_MSG_KEY_VALUE_FOLDER_USER_DEF_6   "6"
#define UIS_MSG_KEY_VALUE_FOLDER_USER_DEF_7   "7"
#define UIS_MSG_KEY_VALUE_FOLDER_USER_DEF_8   "8" 
#define UIS_MSG_KEY_VALUE_FOLDER_USER_DEF_9   "9"
#define UIS_MSG_KEY_VALUE_FOLDER_USER_DEF_10  "10"
#define UIS_MSG_KEY_VALUE_FOLDER_USER_DEF_11  "11"
#define UIS_MSG_KEY_VALUE_FOLDER_USER_DEF_12  "12"
#define UIS_MSG_KEY_VALUE_FOLDER_USER_DEF_13  "13"
#define UIS_MSG_KEY_VALUE_FOLDER_USER_DEF_14  "14"
#define UIS_MSG_KEY_VALUE_FOLDER_USER_DEF_15  "15"

/* Priority types (values for UIS_MSG_KEY_PRIORITY) */
#define UIS_MSG_KEY_VALUE_PRIORITY_LOW        0
#define UIS_MSG_KEY_VALUE_PRIORITY_NORMAL     1
#define UIS_MSG_KEY_VALUE_PRIORITY_HIGH       2

/* Storage location (values for UIS_MSG_KEY_STORAGE) */
#define UIS_MSG_KEY_VALUE_STORAGE_LOCAL       0
#define UIS_MSG_KEY_VALUE_STORAGE_SIM         1

/* Message status (values for UIS_MSG_KEY_MSG_STATUS) */
#define UIS_MSG_KEY_VALUE_MSG_STATUS_OK          0
#define UIS_MSG_KEY_VALUE_MSG_STATUS_INCOMPLETE  1

#define UIS_NBR_OF_KEYS                       (UIS_NBR_OF_SYSTEM_KEYS + UIS_NBR_OF_USER_KEYS)
#define UIS_NBR_OF_SYSTEM_KEYS                18

/* Key types */
#define UIS_MSG_KEY_FOLDER                    0     /* UIS_VALUE_TYPE_UTF8,
                                                        see UIS_MSG_KEY_VALUE_FOLDER_x */
#define UIS_MSG_KEY_SUBTYPE                   1     /* UIS_VALUE_TYPE_UINT32 */     
#define UIS_MSG_KEY_SUBJECT                   2     /* UIS_VALUE_TYPE_UTF8 */
#define UIS_MSG_KEY_FROM                      3     /* UIS_VALUE_TYPE_UTF8 */
#define UIS_MSG_KEY_TIMESTAMP                 4     /* UIS_VALUE_TYPE_UINT32, 
                                                        nbr of seconds since 1970 */
#define UIS_MSG_KEY_READ                      5     /* UIS_VALUE_TYPE_BOOL */
#define UIS_MSG_KEY_FORWARD_LOCK              6     /* UIS_VALUE_TYPE_BOOL */
#define UIS_MSG_KEY_PRIORITY                  7     /* UIS_VALUE_TYPE_UINT32, 
                                                        see UIS_MSG_KEY_VALUE_PRIORITY_x */
#define UIS_MSG_KEY_TO                        8     /* UIS_VALUE_TYPE_UTF8 */
#define UIS_MSG_KEY_CREATED                   9     /* UIS_VALUE_TYPE_UINT32, 
                                                        nbr of seconds since 1970 */
#define UIS_MSG_KEY_EXPIRES                   10    /* UIS_VALUE_TYPE_UINT32, 
                                                        nbr of seconds since 1970 */
#define UIS_MSG_KEY_NBR_OF_ATTACHMENTS        11    /* UIS_VALUE_TYPE_UINT32 */
#define UIS_MSG_KEY_REPORT_STATUS             12    /* UIS_VALUE_TYPE_UINT32 */
#define UIS_MSG_KEY_URL                       13    /* UIS_VALUE_TYPE_UTF8 */
#define UIS_MSG_KEY_SIZE                      14    /* UIS_VALUE_TYPE_UINT32 */
#define UIS_MSG_KEY_STORAGE                   15    /* UIS_VALUE_TYPE_UINT32,
                                                        see UIS_MSG_KEY_VALUE_STORAGE_x */
#define UIS_MSG_KEY_NBR_OF_MESSAGES_WAITING   16    /* UIS_VALUE_TYPE_UINT32 */
#define UIS_MSG_KEY_MSG_STATUS                17    /* UIS_VALUE_TYPE_UINT32 */

/*
 *  UIS_TITLE_PROPERTY_ARRAY defines an array where the key defines above is the index 
 *  into the array.
 *
 *  The first param is TRUE if the property with this index is to be included
 *  in the title list.
 *  The second param is a max length. A value of zero means that there is no specified
 *  max length. Max length can only be used on keys where its value is a UTF8 string.
 *  Then max length means the maximum number of characters in ther string.
 *  All strings which exceed this length SHOULD be truncated to the specified max length.
 *
 *  Example:
 *  The following line means a key that is to be put in the title list and has a max length
 *  of 20 characters.
 *      {TRUE, 20}, \
 *
 *  Look in uis_ecfg.h for the UIS_USER_TITLE_PROPERTY_ARRAY definition
 */

typedef struct {
  int isTitleProperty;
  int maxLen;
} uis_title_property_array_element_t;

#define UIS_TITLE_PROPERTY_ARRAY UIS_USER_TITLE_PROPERTY_ARRAY

/**********************************************************************
 * Type Definitions:
 **********************************************************************/

/* unique message identifier (within its msgType) */
typedef struct {
  MSF_UINT16            handleLen;
  unsigned char         *handle;  /* binary message ID for which UIS and viewers of 
                                  these messages does not know its contents or context */
} uis_msg_handle_t;

/* A key-value pair placeholder */
typedef struct {
  MSF_UINT16            key;
  MSF_UINT8             valueType;
  MSF_UINT16            valueLen;
  unsigned char         *value;
} uis_key_value_t;

/* A representation of a message with enough info to visually represent 
the message in a list */
typedef struct {
  uis_msg_handle_t      handle;
  MSF_UINT16            titleListSize;
  uis_key_value_t       *titleList;
} uis_msg_list_item_t;

/* A placeholder for a message's second level of properties 
(e.g. needed to visualize "view properties") */
typedef struct {
  uis_msg_handle_t      handle;
  MSF_UINT16            propertyListSize;
  uis_key_value_t       *propertyList;
} uis_msg_t;

/* A placeholder for a complete message as needed when UIS is taking 
care of storage of messages of a certain msgType */
typedef struct {
  uis_msg_handle_t      handle;
  MSF_UINT16            propertyListSize;
  uis_key_value_t       *propertyList;
  MSF_UINT16            hiddenPropertyListSize;
  uis_key_value_t       *hiddenPropertyList; /* meta information that is needed to 
                                              parse/understand/modify data (see below) */
  MSF_UINT32            dataLen;
  unsigned char         *data; /* the actual message in its binary form */
} uis_full_msg_t;


/**********************************************************************
 * Signals:
 **********************************************************************/

/* For the signal UIS_SIG_REGISTER              */
typedef struct {
  MSF_UINT16            transactionId;
  MSF_UINT8             msgType;
} uis_register_t;

/* For the signal UIS_SIG_REPLY_REGISTER        */
typedef struct {
  MSF_UINT16            transactionId;
  MSF_UINT8             msgType;
  MSF_INT8              result;
} uis_reply_register_t;

/* For the signal UIS_SIG_DEREGISTER            */
typedef struct {
  MSF_UINT8             msgType;
} uis_deregister_t;

/* For the signal UIS_SIG_GET_NBR_OF_MSGS       */
typedef struct {
  MSF_UINT16            transactionId;
  MSF_UINT8             msgType;
  MSF_UINT16            filterListSize;
  uis_key_value_t       *filterList;
} uis_get_nbr_of_msgs_t;

/* For the signal UIS_SIG_REPLY_NBR_OF_MSGS     */
typedef struct {
  MSF_UINT16            transactionId;
  MSF_UINT8             msgType;
  MSF_UINT16            nbrOfMsgs;
} uis_reply_nbr_of_msgs_t;

/* For the signal UIS_SIG_GET_MSG_LIST          */
typedef struct {
  MSF_UINT16            transactionId;
  MSF_UINT8             msgType;
  MSF_UINT16            filterListSize;
  uis_key_value_t       *filterList;
  MSF_UINT16            startFromMsg;
} uis_get_msg_list_t;

/* For the signal UIS_SIG_REPLY_MSG_LIST        */
typedef struct {
  MSF_UINT16            transactionId;
  MSF_UINT8             msgType;
  MSF_UINT16            msgListSize;
  uis_msg_list_item_t   *msgList;
  MSF_UINT16            nextMsg;
} uis_reply_msg_list_t;

/* For the signal UIS_SIG_GET_MSG               */
typedef struct {
  MSF_UINT16            transactionId;
  MSF_UINT8             msgType;
  uis_msg_handle_t      handle;
} uis_get_msg_t;

/* For the signal UIS_SIG_REPLY_MSG             */
typedef struct {
  MSF_UINT16            transactionId;
  MSF_UINT8             msgType;
  MSF_INT8              result;
  uis_msg_t             msg;
} uis_reply_msg_t;

/* For the signal UIS_SIG_GET_FULL_MSG          */
typedef struct {
  MSF_UINT16            transactionId;
  MSF_UINT8             msgType;
  uis_msg_handle_t      handle;
  MSF_BOOL              getPropertyList;
  MSF_BOOL              getHiddenPropertyList;
  MSF_BOOL              getData;
} uis_get_full_msg_t;

/* For the signal UIS_SIG_REPLY_FULL_MSG        */
typedef struct {
  MSF_UINT16            transactionId;
  MSF_UINT8             msgType;
  MSF_INT8              result;
  uis_full_msg_t        msg;
} uis_reply_full_msg_t;

/* For the signal UIS_SIG_DELETE_MSG            */
typedef struct {
  MSF_UINT16            transactionId;
  MSF_UINT8             msgType;
  uis_msg_handle_t      handle;
} uis_delete_msg_t;

/* For the signal UIS_SIG_REPLY_DELETE_MSG      */
typedef struct {
  MSF_UINT16            transactionId;
  MSF_UINT8             msgType;
  uis_msg_handle_t      handle;
  MSF_INT8              result;
} uis_reply_delete_msg_t;

/* For the signal UIS_SIG_NOTIFY_MSG_DELETED    */
typedef struct {
  MSF_UINT8             msgType;
  uis_msg_handle_t      handle;
} uis_notify_msg_deleted_t;

/* For the signal UIS_SIG_CHANGE_MSG            */
typedef struct {
  MSF_UINT16            transactionId;
  MSF_UINT8             msgType;
  MSF_BOOL              changePropertyList;
  MSF_BOOL              changeHiddenPropertyList;
  MSF_BOOL              changeData;
  uis_full_msg_t        msg;
} uis_change_msg_t;

/* For the signal UIS_SIG_REPLY_CHANGE_MSG      */
typedef struct {
  MSF_UINT16            transactionId;
  MSF_UINT8             msgType;
  uis_msg_handle_t      handle;
  MSF_INT8              result;
} uis_reply_change_msg_t;

/* For the signal UIS_SIG_NOTIFY_MSG_CHANGED    */
typedef struct {
  MSF_UINT8             msgType;
  uis_msg_list_item_t   msg;
} uis_notify_msg_changed_t;

/* For the signal UIS_SIG_NOTIFY_NEW_MSG        */
typedef struct {
  MSF_UINT8             msgType;
  uis_msg_list_item_t   msg;
} uis_notify_new_msg_t;

/* For the signal UIS_SIG_CREATE_MSG            */
typedef struct {
  MSF_UINT16            transactionId;
  MSF_UINT8             msgType;
  uis_full_msg_t        msg;
} uis_create_msg_t;

/* For the signal UIS_SIG_REPLY_CREATE_MSG            */
typedef struct {
  MSF_UINT16            transactionId;
  MSF_UINT8             msgType;
  uis_msg_handle_t      handle;
  MSF_INT8              result;
} uis_reply_create_msg_t;

/* For the signal UIS_SIG_UNREAD_MSGS_NOTIFICATION */
typedef struct {
  MSF_UINT8      msgType;
  MSF_UINT16     nbrOfUnreadMsgs;
} uis_notify_unread_msg_count_t;

/* For the signal UIS_SIG_NOTIFY_INVALIDATE_ALL */
typedef struct {
  MSF_UINT8      msgType;
} uis_notify_invalidate_all_t;

/* For the signal UIS_SIG_SET_MSG_PROPERTY */
typedef struct {
  MSF_UINT16            transactionId;
  MSF_UINT8             msgType;
  uis_msg_handle_t      handle;
  uis_key_value_t       propertyValue;
} uis_set_msg_property_t;


/* For the signal UIS_SIG_REPLY_SET_MSG_PROPERTY */
typedef struct {
  MSF_UINT16            transactionId;
  MSF_UINT8             msgType;
  uis_msg_handle_t      handle;
  MSF_INT8              result;
} uis_reply_set_msg_property_t;

/*
 * Called by any other module that wants to use the UIS module.
 */
void 
UISif_startInterface (void);

/**********************************************************************
 * Signal-sending API
 * These functions should be used by any other module that wants to
 * send a signal to the UIS module.
 **********************************************************************/

/*********************************************************************/
/* Functions for modules that hold the viewer role                   */
/*********************************************************************/

/*
MSF_UINT8 src, 
MSF_UINT8 msgType
*/
void 
UISif_register (int src, int msgType);

/*
MSF_UINT8 src, 
MSF_UINT8 msgType
*/
void 
UISif_deregister (int src, int msgType);


/*********************************************************************/
/* Functions for modules that hold the viewer or editor role         */
/*********************************************************************/

/*
MSF_UINT8 src,
MSF_UINT16 transactionId,
MSF_UINT8 msgType, 
MSF_UINT16 filterListSize, 
uis_key_value_t *filterList
*/
void 
UISif_getNbrOfMsgs (int src,
                        unsigned transactionId,
                        int msgType, 
                        unsigned filterListSize, 
                        uis_key_value_t *filterList);

/*
MSF_UINT8 src,
MSF_UINT16 transactionId,
MSF_UINT8 msgType, 
MSF_UINT16 filterListSize, 
uis_key_value_t *filterList
MSF_UINT16 startFromMsg
*/
void 
UISif_getMsgList (int src,
                      unsigned transactionId,
                      int msgType, 
                      unsigned filterListSize, 
                      uis_key_value_t *filterList,
                      unsigned startFromMsg);

/*
MSF_UINT8 src, 
MSF_UINT16 transactionId,
MSF_UINT8 msgType, 
uis_msg_handle_t *handle
*/
void 
UISif_getMsg (int src, 
                  unsigned transactionId,
                  int msgType, 
                  uis_msg_handle_t *handle);

/*
MSF_UINT8 src,
MSF_UINT16 transactionId,
MSF_UINT8 msgType,
uis_msg_handle_t *handle
*/
void 
UISif_deleteMsg (int src,
                     unsigned transactionId,
                     int msgType,
                     uis_msg_handle_t *handle);

/* 
MSF_UINT8 src,
MSF_UINT16 transactionId
MSF_UINT8 msgType
uis_msg_handle_t handle
uis_key_value_t propertyValue
*/
void 
UISif_setMsgProperty (int src,
                      unsigned transactionId,
                      int msgType,
                      uis_msg_handle_t *handle,
                      uis_key_value_t *propertyValue);


/*********************************************************************/
/* Functions for modules that hold the owner role                    */
/*********************************************************************/

/*
MSF_UINT8 src, 
MSF_UINT16 transactionId,
MSF_UINT8 msgType,
MSF_INT8 result
*/
void
UISif_replyRegister (int src, 
                        unsigned transactionId,
                        int msgType,
                        int result);

/*
MSF_UINT8 src, 
MSF_UINT16 transactionId,
MSF_UINT8 msgType,
MSF_UINT16 nbrOfMsgs,
*/
void 
UISif_replyNbrOfMsgs (int src, 
                          unsigned transactionId,
                          int msgType,
                          unsigned nbrOfMsgs);

/*
MSF_UINT8 src, 
MSF_UINT16 transactionId,
MSF_UINT8 msgType,
MSF_UINT16 msgListSize,
uis_msg_list_item_t *msgList,
MSF_UINT16 nextMsg
*/
void 
UISif_replyMsgList (int src, 
                        unsigned transactionId,
                        int msgType,
                        unsigned msgListSize,
                        uis_msg_list_item_t *msgList,
                        unsigned nextMsg);

/*
MSF_UINT8 src, 
MSF_UINT16 transactionId,
MSF_UINT8 msgType,
MSF_INT8 result,
uis_msg_t *msg
*/
void 
UISif_replyMsg (int src, 
                    unsigned transactionId,
                    int msgType,
                    int result,
                    uis_msg_t *msg);

/*
MSF_UINT8 src,
MSF_UINT16 transactionId,
MSF_UINT8 msgType,
uis_msg_handle_t *handle,
MSF_INT8 result
*/
void 
UISif_replyDeleteMsg (int src,
                          unsigned transactionId,
                          int msgType,
                          uis_msg_handle_t *handle,
                          int result);

/*
MSF_UINT8 src, 
MSF_UINT8 msgType,
uis_msg_handle_t *handle
*/
void 
UISif_notifyMsgDeleted (int src, 
                            int msgType,
                            uis_msg_handle_t *handle);

/*
MSF_UINT8 src, 
MSF_UINT8 msgType,
uis_msg_list_item_t *msg
*/
void 
UISif_notifyMsgChanged (int src, 
                            int msgType,
                            uis_msg_list_item_t *msg);

/*
MSF_UINT8 src, 
MSF_UINT8 msgType,
uis_msg_list_item_t *msg
*/
void 
UISif_notifyNewMsg (int src, 
                        int msgType,
                        uis_msg_list_item_t *msg);

/*
 *  The following interface function must be used by any module acting as owner of 
 *  a message type. This function must be called after the start of such a module if
 *  the number of unread messages is > 0.
 *  This function must also be called when the number of unread messages changes.
 *
 *  The UIS module may not be started at these occasions. If UIS is not started then it is
 *  the task of the calling module to start UIS.
 */
/*
MSF_UINT8 src,
MSF_UINT8 msgType, 
MSF_UINT16 nbrOfUnreadMsgs, 
*/
void 
UISif_notifyUnreadMsgCount (int src,
                            int msgType, 
                            unsigned nbrOfUnreadMsgs);

/*
 *  This notification signals that all messages belonging to the indicated
 *  message type are no longer valid. All registered viewers will be notified
 *  and should re-fetch messages of this message type.
 */
/*
MSF_UINT8 src,
MSF_UINT8 msgType, 
*/
void 
UISif_notifyInvalidateAll (int src, int msgType);


/*
MSF_UINT8 src,
MSF_UINT16 transactionId,
MSF_UINT8 msgType,
uis_msg_handle_t *handle,
MSF_INT8 result
*/
void 
UISif_replySetMsgProperty (int src,
                          unsigned transactionId,
                          int msgType,
                          uis_msg_handle_t *handle,
                          int result);


/*********************************************************************/
/* Functions for modules that hold the editor role                   */
/*********************************************************************/

/*
MSF_UINT8 src, 
MSF_UINT16 transactionId,
MSF_UINT8 msgType, 
uis_msg_handle_t *handle, 
MSF_BOOL getPropertyList, 
MSF_BOOL getHiddenPropertyList, 
MSF_BOOL getData
*/
void 
UISif_getFullMsg (int src, 
                      unsigned transactionId,
                      int msgType, 
                      uis_msg_handle_t *handle, 
                      int getPropertyList, 
                      int getHiddenPropertyList, 
                      int getData);


/*
MSF_UINT8 src, 
MSF_UINT16 transactionId,
MSF_UINT8 msgType, 
MSF_BOOL changePropertyList,
MSF_BOOL changeHiddenPropertyList, 
MSF_BOOL changeData, 
uis_full_msg_t *msg
*/
void 
UISif_changeMsg (int src, 
                     unsigned transactionId,
                     int msgType, 
                     int changePropertyList,
                     int changeHiddenPropertyList, 
                     int changeData, 
                     uis_full_msg_t *msg);


/*
MSF_UINT8 src, 
MSF_UINT16 transactionId,
MSF_UINT8 msgType, 
uis_full_msg_t *msg
*/
void 
UISif_createMsg (int src, 
                     unsigned transactionId,
                     int msgType, 
                     uis_full_msg_t *msg);




/**********************************************************************
 * Conversion routines for all signal owned by this module.
 * None of these functions should be called directly by another module.
 **********************************************************************/


/*
 *  UIS convert functions
 */

int 
uis_cvt_register (msf_dcvt_t *obj, uis_register_t *p);

int 
uis_cvt_reply_register (msf_dcvt_t *obj, uis_reply_register_t *p);

int 
uis_cvt_deregister (msf_dcvt_t *obj, uis_deregister_t *p);

int 
uis_cvt_get_nbr_of_msgs (msf_dcvt_t *obj, uis_get_nbr_of_msgs_t *p);

int 
uis_cvt_reply_nbr_of_msgs (msf_dcvt_t *obj, uis_reply_nbr_of_msgs_t *p);

int 
uis_cvt_get_msg_list (msf_dcvt_t *obj, uis_get_msg_list_t *p);

int 
uis_cvt_reply_msg_list (msf_dcvt_t *obj, uis_reply_msg_list_t *p);

int 
uis_cvt_get_msg (msf_dcvt_t *obj, uis_get_msg_t *p);

int 
uis_cvt_reply_msg (msf_dcvt_t *obj, uis_reply_msg_t *p);

int 
uis_cvt_get_full_msg (msf_dcvt_t *obj, uis_get_full_msg_t *p);

int 
uis_cvt_reply_full_msg (msf_dcvt_t *obj, uis_reply_full_msg_t *p);

int 
uis_cvt_delete_msg (msf_dcvt_t *obj, uis_delete_msg_t *p);

int 
uis_cvt_reply_delete_msg (msf_dcvt_t *obj, uis_reply_delete_msg_t *p);

int 
uis_cvt_notify_msg_deleted (msf_dcvt_t *obj, uis_notify_msg_deleted_t *p);

int 
uis_cvt_change_msg (msf_dcvt_t *obj, uis_change_msg_t *p);

int 
uis_cvt_reply_change_msg (msf_dcvt_t *obj, uis_reply_change_msg_t *p);

int 
uis_cvt_notify_msg_changed (msf_dcvt_t *obj, uis_notify_msg_changed_t *p);

int 
uis_cvt_notify_new_msg (msf_dcvt_t *obj, uis_notify_new_msg_t *p);

int 
uis_cvt_create_msg (msf_dcvt_t *obj, uis_create_msg_t *p);
 
int 
uis_cvt_reply_create_msg (msf_dcvt_t *obj, uis_reply_create_msg_t *p);

int
uis_cvt_notify_unread_msg_count (msf_dcvt_t *obj, uis_notify_unread_msg_count_t *p);

int
uis_cvt_notify_invalidate_all (msf_dcvt_t *obj, uis_notify_invalidate_all_t *p);

int
uis_cvt_set_msg_property (msf_dcvt_t *obj, uis_set_msg_property_t *p);

int
uis_cvt_reply_set_msg_property (msf_dcvt_t *obj, uis_reply_set_msg_property_t *p);

/*
 * Convert from memory buffer for signal structs.
 */
void* 
uis_convert (MSF_UINT8 module, MSF_UINT16 signal, void* buffer);

/*
 * Released a signal structure of a signal.
 */
void 
uis_destruct (MSF_UINT8 module, MSF_UINT16 signal, void* p);

#endif


