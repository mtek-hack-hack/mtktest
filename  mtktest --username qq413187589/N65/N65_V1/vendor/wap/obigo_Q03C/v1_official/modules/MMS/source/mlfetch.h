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





#ifndef _MFETCH_H
#define _MFETCH_H




#define MMS_MESSAGE_INFO_SIZE  (POS_INT_MSG_NUMBER * sizeof(MSF_UINT32))
#define MMS_PART_INFO_SIZE (POS_INT_PART_NUMBER * sizeof(MSF_UINT32))










MSF_UINT32 getNumberOfParts( const MmsMessage *msg);
MSF_UINT32 getNumberOfSubParts( MSF_UINT32 number, const MmsMessage *msg);
MSF_UINT32 getMaxPartSize( const MmsMessage *msg);
MSF_UINT32 getMaxEntrySize( const MmsMessage *msg);
MSF_UINT32 getHeaderSize( const MmsMessage *msg);

MSF_UINT32 getEntrySize( MSF_UINT32 number, const MmsMessage *msg);
MSF_UINT32 getEntryStart( MSF_UINT32 number, const MmsMessage *msg);
MSF_UINT32 getDataSize( MSF_UINT32 number, const MmsMessage *msg); 
MSF_UINT32 getDataStart( MSF_UINT32 number, const MmsMessage *msg); 
void setHeaderSize( unsigned char *buffer, MSF_UINT32 value);
void setNumberOfParts( unsigned char *buffer, MSF_UINT32 value);
void setNumberOfSubParts( unsigned char *buffer, MSF_UINT32 number, 
    MSF_UINT32 value);
void setHeaderStart( unsigned char *buffer);
void setEntrySize( unsigned char *buffer, MSF_UINT32 number, MSF_UINT32 value);
void setEntryStart( unsigned char *buffer, MSF_UINT32 number, MSF_UINT32 value);
void setDataSize( unsigned char *buffer, MSF_UINT32 number, MSF_UINT32 value);
void setDataStart( unsigned char *buffer, MSF_UINT32 number, MSF_UINT32 value);
MmsResult readDataFromFile( MSF_UINT8 modId, unsigned char **buf, 
    MSF_UINT32 *size, int fileHandle, MSF_INT32 *filePos);
MmsResult getMessageInfo( MSF_UINT8 modId, MmsGetHeader *header,
    const MmsMessage *msg, MmsTransaction *tHandle);
MmsMessageInfo *parseMsgInfo( MSF_UINT8 modId, unsigned char *buffer, 
    MSF_UINT32 bufferSize, MSF_UINT32 *msgPtr);
MmsResult loadMessageInfoFile( MSF_UINT8 modId, MmsMessage *msg, 
    MmsTransaction *tHandle);
MmsResult getMmsHeader( MSF_UINT8 modId, MmsGetHeader *header, 
    const MmsMessage *msg, MmsTransaction *tHandle);
MmsResult parseBodyHeader( MSF_UINT8 modId, MSF_BOOL prevIsMultipart, 
    MmsBodyInfoList *msgInfo, unsigned char *data, MSF_UINT32 size);
unsigned char *findContentType( unsigned char *entry, MSF_UINT32 entrySize, 
    MSF_BOOL isMultiPart, MSF_UINT32 *headerLen);

#endif 

