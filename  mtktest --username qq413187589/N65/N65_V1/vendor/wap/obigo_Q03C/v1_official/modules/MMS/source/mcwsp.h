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




#ifndef _MCWSP_H
#define _MCWSP_H







typedef struct
{
    char *transactionId; 
    MmsStatus status;    
    MmsDeliveryReport allowed; 
} MmsNotifyRespInd; 
 


typedef struct
{
    char *transactionId;        
    MmsDeliveryReport allowed;  
} MmsAcknowledgeInd;










unsigned char *createWspAcknowledgeIndMsg(const MmsAcknowledgeInd *headerValues, 
    MSF_UINT32 *length, MmsVersion version);

unsigned char *createWspNotifyRespIndMsg(const MmsNotifyRespInd *header,
    MSF_UINT32 *length, MmsVersion version);

unsigned char *createWspReadReport(const MmsGetHeader *header, MSF_UINT32 *length, 
    MmsResult *result, MmsReadStatus readStatus, MmsVersion version);

#endif 

