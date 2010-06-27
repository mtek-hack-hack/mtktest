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





#ifndef _SLS_MEM_H
#define _SLS_MEM_H












#define SLS_ALLOC(s)          MSF_MEM_ALLOC(MSF_MODID_SLS, s)
#define SLS_CALLOC(s)         slsMemCalloc(s)
#define SLS_ALLOCTYPE(t)      slsMemCalloc(sizeof(t))
#define SLS_FREE(p)           {MSF_MEM_FREE(MSF_MODID_SLS, p); (p) = NULL;}


void *slsMemCalloc(MSF_UINT32 size);

#endif 


