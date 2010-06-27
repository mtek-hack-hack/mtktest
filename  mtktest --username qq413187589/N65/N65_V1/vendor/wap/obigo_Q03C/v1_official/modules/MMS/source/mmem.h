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





#ifndef _MMEM_H
#define _MMEM_H












#define MMS_ALLOC(s)          MSF_MEM_ALLOC( MSF_MODID_MMS, s)
#define MMS_CALLOC(s)         mmsMemCalloc(s)
#define MMS_ALLOCTYPE(t)      mmsMemCalloc(sizeof(t))
#define MMS_FREE(p)           {MSF_MEM_FREE( MSF_MODID_MMS, p); (p) = NULL;}


void *mmsMemCalloc(MSF_UINT32 size);

#endif 


