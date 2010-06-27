/*
 * Copyright (C) Obigo AB, 2002-2006.
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







#ifndef _sec_pdf_h
#define _sec_pdf_h

#ifndef _msf_cfg_h
#include "msf_cfg.h"
#endif
#ifndef _msf_mem_h
#include "msf_mem.h"    
#endif
#ifndef _msf_core_h
#include "msf_core.h"   
#endif


 



#define SEC_ALLOC(s)        MSF_MEM_ALLOC(MSF_MODID_SEC,s)
#define SEC_ALLOCTYPE(t)    MSF_MEM_ALLOCTYPE(MSF_MODID_SEC,t)
#define SEC_FREE(p)         MSF_MEM_FREE(MSF_MODID_SEC,p)

 



#define SEC_CURRENT_TIME    MSF_TIME_GET_CURRENT


int sec_pdf_seed(unsigned char **seed);

#endif
