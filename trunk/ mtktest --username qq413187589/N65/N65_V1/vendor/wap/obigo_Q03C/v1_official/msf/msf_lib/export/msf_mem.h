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
/*
 * msf_mem.h
 *
 * Created by Anders Edenbrandt, Wed Sep 26 09:59:07 2001.
 *
 *
 * Revision history:
 *   020402, IPN: Changed to fit Mobile Suite Framework.
 *   021014, IPN: Fixed the internal memory allocator to fit MSF.
 *   021014, IPN: Added an exception function parameter in msf_mem_init.
 *
 */
#ifndef _msf_mem_h
#define _msf_mem_h

#ifndef _msf_def_h
#include "msf_def.h"
#endif
#ifndef _msf_cfg_h
#include "msf_cfg.h"
#endif

/************************************************************
 * Macros
 ************************************************************/

#define MSF_MEM_INIT                  msf_mem_init
#define MSF_MEM_FREE_ALL              msf_mem_free_all

#ifdef MSF_LOG_MODULE

#define MSF_MEM_ALLOC(id, s)          msf_mem_alloc (id, s, __FILE__, __LINE__)
#define MSF_MEM_ALLOCTYPE(id, t) (t *)msf_mem_alloc (id, sizeof (t), __FILE__, __LINE__)
#define MSF_MEM_FREE(id, p)           msf_mem_free (id, p, __FILE__, __LINE__)

#else

#define MSF_MEM_ALLOC(id, s)          msf_mem_alloc (id, s)
#define MSF_MEM_ALLOCTYPE(id, t) (t *)msf_mem_alloc (id, sizeof (t))
#define MSF_MEM_FREE(id, p)           msf_mem_free (id, p)

#endif

#define MSF_MEM_GET_SIZE              msf_mem_get_size

/************************************************************
 * Typedef
 ************************************************************/

typedef void msf_mem_exception_func_t (void);


/************************************************************
 * Functions
 ************************************************************/

#ifdef MSF_LOG_MODULE
void *
msf_mem_alloc (MSF_UINT8 modId, MSF_UINT32 size, const char *filename, int lineno);
#else
void *
msf_mem_alloc (MSF_UINT8 modId, MSF_UINT32 size);
#endif

#ifdef MSF_LOG_MODULE
void
msf_mem_free (MSF_UINT8 modId, void *p, const char *filename, int lineno);
#else
void
msf_mem_free (MSF_UINT8 modId, void *p);
#endif

MSF_UINT32
msf_mem_get_size (void *mem);

MSF_UINT32
msf_mem_allocated_bytes (MSF_UINT8 modId);

void
msf_mem_free_all (MSF_UINT8 modId);

/*
 * Initialise the memory handler. The parameter exceptionHandler is
 * a pointer to an exception function. This function is called when
 * a memory allocation is failed. If the module doesn't have any
 * exception function, set exceptionHandler to NULL, which results
 * in when a memory allocation is failed NULL is returned.
 *
 */
void
msf_mem_init (MSF_UINT8 modId, msf_mem_exception_func_t* exceptionHandler);

#endif
