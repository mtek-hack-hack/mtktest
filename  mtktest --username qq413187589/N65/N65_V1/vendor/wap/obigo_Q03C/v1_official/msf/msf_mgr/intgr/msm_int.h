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
 * msm_int.h
 *
 * Created by Ingmar Persson
 *
 * Revision  history:
 * 
 *
 */

#ifndef _msm_int_h
#define _msm_int_h

#ifndef _msf_core_h
#include "msf_core.h"
#endif

/****************************************
 * Module status
 ****************************************/
#define MSM_MODULE_STATUS_CREATED         MODULE_STATUS_CREATED
#define MSM_MODULE_STATUS_ACTIVE          MODULE_STATUS_ACTIVE
#define MSM_MODULE_STATUS_SHUTTING_DOWN   MODULE_STATUS_SHUTTING_DOWN
#define MSM_MODULE_STATUS_TERMINATED      MODULE_STATUS_TERMINATED


void
MSMa_createTask (MSF_UINT8 modId);

void
MSMa_moduleStatus (MSF_UINT8 modId, int status);

void
MSMa_terminated (void);


/****************************************
 * Timers
 ****************************************/

void
MSMa_setTimer (MSF_UINT32 timeInterval);

void
MSMa_resetTimer (void);


/****************************************
 * Registry
 ****************************************/

void
MSMa_registryResponse (MSF_UINT8 id);


/****************************************
 * External
 ****************************************/

void
MSMa_externalGet (MSF_INT32 id, const char* path, const char* key);

#endif
