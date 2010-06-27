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








#ifndef _MFIELDP_H
#define _MFIELDP_H 







unsigned char *parseContentType( MSF_UINT8 modId, MmsContentType **cType,
     const unsigned char *contentTypeData, MSF_UINT32 length);
MSF_BOOL parseFromAddress( MSF_UINT8 modId, unsigned char *headerData, 
    const MSF_UINT32 headerSize, MmsAddress *from);
unsigned char *parseEntryHeader( MSF_UINT8 modId, unsigned char *headerStart, 
    MSF_UINT32 bufSize, MmsBodyInfoList *bodyInfoList);
MmsAddressList* parseAddress( MSF_UINT8 modId, MmsHeaderTag tag, 
    unsigned char *headerData, MSF_UINT32 headerDataSize);
MSF_BOOL parseHeaderTime( unsigned char *headerData, 
    MSF_UINT32 headerDataSize, MmsGetHeader *mHeader,MmsHeaderTag tag);
MSF_BOOL parseEncodedStringValue( MSF_UINT8 modId, unsigned char *buf, 
    MSF_UINT32 size, MSF_UINT32 *lengthOfString, MmsEncodedText *eText);
MmsStatus checkStatus( MSF_UINT8 status);
unsigned char *parseOneAddress( MSF_UINT8 modId, unsigned char *buffer, 
    MSF_UINT32 size, MmsAddress *address);


#endif 


