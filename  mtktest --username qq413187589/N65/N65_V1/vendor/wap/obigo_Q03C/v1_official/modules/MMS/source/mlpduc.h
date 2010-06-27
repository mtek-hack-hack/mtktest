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





#ifndef _MLPDUC_H
#define _MLPDUC_H









unsigned char *createWspSendHeader( MSF_UINT8 modId, const MmsSetHeader *header, 
    MSF_UINT32 *length, MmsResult *result, MmsVersion version, MSF_UINT32 numOfBodyParts);
unsigned char *createWspBodyPartHead( MSF_UINT8 modId, 
    const MmsBodyParams *dataValues, MSF_UINT32 *length, MSF_UINT32 size, 
    MmsResult *result);
unsigned char *createWspForward( MSF_UINT8 modId, const MmsForward *header,
    char *contentLocation, MSF_UINT32 *length, MmsResult *result, MmsVersion version);


#endif 


