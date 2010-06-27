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
 




#ifndef _MCPDU_H
#define _MCPDU_H


#define OCTET_SIZE          1
#define TAG_SIZE            1
#define TOKEN_SIZE          1
#define UINTVAR_MAX_LENGTH  5
#define SHORT_FLAG      (unsigned char)0x80
#define LENGTH_QUOTE    (unsigned char)31
#define TEXT_QUOTE      (unsigned char)127  
#define ENCODED_D_INT_LEN          31       
#define ENCODED_OCTET_LEN           1
#define MAX_SHORT_LENGTH_VALUE 31
#define SHORT_INTEGER_MIN_VALUE 31
#define SHORT_INTEGER_MAX_VALUE 127

#define ADDRESS_TYPE_TOKEN  "/TYPE"       
#define ADDRESS_TYPE_PLMN   "/TYPE=PLMN"  
#define ADDRESS_TYPE_IPV4   "/TYPE=IPv4"  
#define ADDRESS_TYPE_IPV6   "/TYPE=IPv6"  
#define ADDRESS_TYPE_EMAIL  "/TYPE=EMAIL" 







typedef enum
{
    MMS_DELIVERY_TIME_ABSOLUTE = 128,
    MMS_DELIVERY_TIME_RELATIVE = 129
} MmsDeliveryTimeType;






typedef enum
{
    MMS_EXPIRY_TIME_ABSOLUTE = 128,
    MMS_EXPIRY_TIME_RELATIVE = 129
} MmsExpiryTimeType;



typedef enum 
{
    MMS_M_SEND_REQ          = 128,
    MMS_M_SEND_CONF         = 129,
    MMS_M_NOTIFICATION_IND  = 130,
    MMS_M_NOTIFY_RESP       = 131,
    MMS_M_RETRIEVE_CONF     = 132,
    MMS_M_ACKNOWLEDGE_IND   = 133,
    MMS_M_DELIVERY_IND      = 134,
    MMS_M_READ_REC_IND      = 135,
    MMS_M_READ_ORIG_IND     = 136,
    MMS_M_FORWARD_REQ       = 137,
    MMS_M_FORWARD_CONF      = 138
} MmsMessageType;






typedef enum
{
    MMS_REPLY_CHARGING_DEADLINE_ABSOLUTE = 128,
    MMS_REPLY_CHARGING_DEADLINE_RELATIVE = 129
} MmsReplyChargingDeadlineType;






typedef enum
{
    MMS_RTRV_STATUS_OK                                  = 128,

    MMS_RTRV_STATUS_T_FAILURE                           = 192,
    MMS_RTRV_STATUS_T_MESSAGE_NOT_FOUND                 = 193,
    MMS_RTRV_STATUS_T_NETWORK_PROBLEM                   = 194,

    MMS_RTRV_STATUS_P_FAILURE                           = 224,
    MMS_RTRV_STATUS_P_SERVICE_DENIED                    = 225,
    MMS_RTRV_STATUS_P_MESSAGE_NOT_FOUND                 = 226,
    MMS_RTRV_STATUS_P_CONTENT_UNSUPPORTED               = 227,
    MMS_RTRV_STATUS_P_FOR_FUTURE_USE                    = 255
} MmsRetrieveStatus;






typedef enum
{
    MMS_RSP_STATUS_OK                                   = 128,

    

    MMS_RSP_STATUS_10_UNSPECIFIED                       = 129,
    MMS_RSP_STATUS_10_SERVICE_DENIED                    = 130,
    MMS_RSP_STATUS_10_MSG_FORMAT_CORRUPT                = 131,
    MMS_RSP_STATUS_10_ADDRESS_UNRESOLVED                = 132,
    MMS_RSP_STATUS_10_MSG_NOT_FOUND                     = 133,
    MMS_RSP_STATUS_10_NETWORK_PROBLEM                   = 134,
    MMS_RSP_STATUS_10_CONTENT_NOT_ACCEPTED              = 135,

    
    MMS_RSP_STATUS_UNSUPPORTED_MSG                      = 136,

    
    MMS_RSP_STATUS_T_FAILURE                            = 192,
    MMS_RSP_STATUS_T_SENDING_ADDRESS_UNRESOLVED         = 193,
    MMS_RSP_STATUS_T_MESSAGE_NOT_FOUND                  = 194,
    MMS_RSP_STATUS_T_NETWORK_PROBLEM                    = 195,

    MMS_RSP_STATUS_P_FAILURE                            = 224,
    MMS_RSP_STATUS_P_SERVICE_DENIED                     = 225,
    MMS_RSP_STATUS_P_MESSAGE_FORMAT_CORRUPT             = 226,
    MMS_RSP_STATUS_P_SENDING_ADDRESS_UNRESOLVED         = 227,
    MMS_RSP_STATUS_P_MESSAGE_NOT_FOUND                  = 228,
    MMS_RSP_STATUS_P_CONTENT_NOT_ACCEPTED               = 229,
    MMS_RSP_STATUS_P_REPLY_CHARG_LIMITATIONS_NOT_MET    = 230,
    MMS_RSP_STATUS_P_REPLY_CHARG_REQUEST_NOT_ACCEPTED   = 231,
    MMS_RSP_STATUS_P_REPLY_CHARG_FORWARDING_DENIED      = 232,
    MMS_RSP_STATUS_P_REPLY_CHARG_NOT_SUPPORTED          = 233,
    MMS_RSP_STATUS_P_FOR_FUTURE_USE                     = 255
} MmsResponseStatus;


typedef enum                
{
    MMS_BCC                         = 0x01,
    MMS_CC                          = 0x02,
    X_MMS_CONTENT_LOCATION          = 0x03,
    MMS_CONTENT_TYPE                = 0x04,
    MMS_DATE                        = 0x05,
    X_MMS_DELIVERY_REPORT           = 0x06,
    X_MMS_DELIVERY_TIME             = 0x07,
    X_MMS_EXPIRY                    = 0x08,
    MMS_FROM                        = 0x09,
    X_MMS_MESSAGE_CLASS             = 0x0a,
    MMS_MESSAGE_ID                  = 0x0b,
    X_MMS_MESSAGE_TYPE              = 0x0c,
    X_MMS_VERSION                   = 0x0d,
    X_MMS_MESSAGE_SIZE              = 0x0e,
    X_MMS_PRIORITY                  = 0x0f,
    X_MMS_READ_REPLY                = 0x10,
    X_MMS_REPORT_ALLOWED            = 0x11,
    X_MMS_RESPONSE_STATUS           = 0x12,
    X_MMS_RESPONSE_TEXT             = 0x13,
    X_MMS_SENDER_VISIBILITY         = 0x14,
    X_MMS_STATUS                    = 0x15,
    MMS_SUBJECT                     = 0x16,
    MMS_TO                          = 0x17,
    X_MMS_TRANSACTION_ID            = 0x18,
    X_MMS_RETRIEVE_STATUS           = 0x19,
    X_MMS_RETRIEVE_TEXT             = 0x1a,
    X_MMS_READ_STATUS               = 0x1b,
    X_MMS_REPLY_CHARGING            = 0x1c,
    X_MMS_REPLY_CHARGING_DEADLINE   = 0x1d,
    X_MMS_REPLY_CHARGING_ID         = 0x1e,
    X_MMS_REPLY_CHARGING_SIZE       = 0x1f,
    X_MMS_PREVIOUSLY_SENT_BY        = 0x20,
    X_MMS_PREVIOUSLY_SENT_DATE      = 0x21,
    APPLICATION_HEADER              = 0x7f
} MmsHeaderTag;












typedef union
{
    void *bcc;
    void *cc;
    void *contentLocation;
    void *contentType;
    MSF_UINT32 date;
    MSF_UINT8 deliveryReport;
    void *deliveryTime; 
    void *expiry; 
    void *from;
    void *messageClass;
    char *messageId;
    MSF_UINT32 messageSize;
    MSF_UINT8 messageType; 
    void *previouslySentBy;
    void *previouslySentDate;
    MSF_UINT8 priority;
    MSF_UINT8 readReply;
    MSF_UINT8 readStatus;
    MSF_UINT8 replyCharging;
    void *replyChargingDeadline;
    char *replyChargingId;
    MSF_UINT32 replyChargingSize;
    MSF_UINT8 reportAllowed; 
    MSF_UINT8 responseStatus;
    void *responseText;
    MSF_UINT8 retrieveStatus;
    void *retrieveText;
    MSF_UINT8 senderVisibility;
    MSF_UINT8 status;
    void *subject;  
    void *to; 
    char *transactionId;
    MSF_UINT8 version;
    char *applicationHeader;
} MmsHeaderValue;








#define SKIP_HIGH_BIT(a) (unsigned char)((a) & (unsigned char)0x7f)
#define SET_HIGH_BIT(a)  (unsigned char)((a) | (unsigned char)0x80)


void *cnvLongIntegerToUint32( void *from, MSF_UINT32 *to, unsigned long size);
void *cnvShortIntegerToUchar( void *from, unsigned char *to, unsigned long size);
void *cnvUcharToShortInteger( unsigned char from, void *to, unsigned long size);
void *cnvUintvarToUint32( void *from, MSF_UINT32 *to, unsigned long size);
void *cnvUint32ToLongInteger( MSF_UINT32 from, void *to, unsigned long size);
void *cnvUint32ToUintvar( MSF_UINT32 from, void *to, unsigned long size);
void *cnvUint32ToValueLength( MSF_UINT32 from, void *to, unsigned long size);
void *cnvValueLengthToUint32( void *from, MSF_UINT32 *to, unsigned long size);
void *cnvTextValueToRFC2616String( void *from, MSF_UINT8 modId,
                                   unsigned long size, unsigned char **result);
void *mmsGetBody( void *data, unsigned long size);
MSF_BOOL mmsPduAppend( void *header, unsigned long size, unsigned long *length,
    MmsHeaderTag tag, unsigned long valueSize, MmsHeaderValue value);
MSF_BOOL mmsPduGet( void *header, unsigned long size, MmsHeaderTag tag, 
    MmsHeaderValue *value);
MSF_BOOL mmsPduSanityCheck( void *data, unsigned long size);
#ifdef __MMS_DUAL_SIM_SUPPORT__
MSF_BOOL mmsPduUnrecognized(MmsSimCardEnum simId, void *data, unsigned long size);
#else
MSF_BOOL mmsPduUnrecognized( void *data, unsigned long size);
#endif
unsigned char *mmsPduSkipString(unsigned char *pos, unsigned long length);  


#endif 


