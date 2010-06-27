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









#ifndef _MLPDUP_H
#define _MLPDUP_H
 






MmsResult parseMmsNotification( MSF_UINT8 modId, unsigned char *headerData, 
    MSF_UINT32 headerDataSize, MmsNotification *mmsNotification, MmsVersion *version);
MSF_BOOL parseDeliveryReport( MSF_UINT8 modId, unsigned char *headerData, 
    MSF_UINT32 headerDataSize, MmsDeliveryInd *mmsDelivery);
void parseForwardConf( unsigned char *headerData, MSF_UINT32 headerDataSize, 
    MmsForwardConf *mmsForwardConf);    
MmsReadOrigInd *parseReadReport( MSF_UINT8 modId, unsigned char *pdu, MSF_UINT32 len);
MmsResult parseMmsHeader(  MSF_UINT8 modId, unsigned char *headerData, 
    MSF_UINT32 headerDataSize, MmsGetHeader *mHeader, MmsVersion *version);

#endif 


