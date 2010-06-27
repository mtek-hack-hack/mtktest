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





#ifndef _MFIELDC_H
#define _MFIELDC_H






unsigned char *createContentType(MSF_UINT8 modId, MSF_UINT32 *size,
    const MmsContentType *contentInfo);
unsigned char *createMsgClass( MSF_UINT8 modId, unsigned long *size,
    MmsMessageClass msgClass);
MSF_BOOL createFromField( MSF_UINT8 modId, const MmsAddress *from, 
    MSF_UINT32 fromType, unsigned char **buf, unsigned long *bufLength);
MSF_BOOL createDestinationField( MSF_UINT8 modId, MmsAddressList *addrList, 
    unsigned char *pduHeader, unsigned long bufSize, unsigned long *actLength, 
    MmsHeaderValue *valueOfTag, MmsHeaderTag headerTag);
unsigned char *createTimeField( MSF_UINT8 modId, unsigned long *size, MSF_UINT32 theTime, MmsTimeType timeType);
MSF_BOOL createEncodedStringValue( MSF_UINT8 modId, const char *text, MmsCharset charset,
    unsigned long *size, unsigned char **retPtr);
void calculateSize( const MmsContentType *contentInfo, MSF_UINT32 *size);
MSF_UINT32 calculateEntryHeadersSize( MmsEntryHeader *entryHeader);
unsigned char *createEntryHeaders( MmsEntryHeader *entryHeader, 
    unsigned char *buffer);
unsigned long getSizeOfAddress( MmsAddressList *addrList);
unsigned long getSizeOfEncodedText(MmsEncodedText eText);
char *generateMmsTransactionId( MSF_UINT8 modId, unsigned long *length);

#endif 


