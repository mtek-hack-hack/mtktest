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
 
#ifndef _MCREATE_H
#define _MCREATE_H















unsigned char *createBodyPartHeader(MSF_UINT8 modId, MSF_UINT32 *encHeaderLen,
    const MmsBodyParams *bodyParams, MSF_UINT32 size, MmsResult *result );

MmsResult writeDataToFile( MSF_UINT8 modId, unsigned char **buf, 
    MSF_UINT32 *sizeLeft, int fileHandle, MSF_INT32 *filePos);
void freeBodyParams( MSF_UINT8 modId, MmsBodyParams *bodyParams);


#endif 


