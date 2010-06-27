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
 * msm_env.h
 *
 * Created by Ingmar Persson
 *
 * Revision  history:
 *   021014  IPN  Added MSMc_kill.
 *   021014  IPN  Added MSMc_externalResponse.
 *
 */

#ifndef _msm_env_h
#define _msm_env_h

#ifndef _msf_core_h
#include "msf_core.h"
#endif

/* When this function has returned, you can start 
   scheduling MSF with the function MSFc_run. */
void
MSMc_startMobileSuite (const char* startOptions);

void
MSMc_terminateMobileSuite (void);

int
MSMc_wantsToRun (void);

void
MSMc_run (void);

void
MSMc_kill (void);

void
MSMc_startModule (MSF_UINT8 modId, char* startOptions);

void
MSMc_terminateModule (MSF_UINT8 modId);

void
MSMc_timerExpiredEvent (void);


/****************************************
 * Registry
 ****************************************/

void
MSMc_registrySetInit (void);

void
MSMc_registrySetPath (char* path);

void
MSMc_registrySetAddKeyInt (char* key, MSF_INT32 value);

void
MSMc_registrySetAddKeyStr (char* key, unsigned char* value, MSF_UINT16 valueLength);

void
MSMc_registrySetCommit (void);

void
MSMc_registryGet (MSF_UINT8 id, char* path, char* key);

void
MSMc_registryDelete (char* path, char* key);

int
MSMc_registryRespGetNext (MSF_UINT8 id, msf_registry_param_t* param);

void
MSMc_registryRespFree (MSF_UINT8 id);


/****************************************
 * External
 ****************************************/

void
MSMc_externalResponse (MSF_INT32 id, msf_registry_param_t* param);

void
MSMc_objectAction (const char           *mime_type,
                   MsfResourceType       data_type,
                   const unsigned char  *data,
                   MSF_INT32             data_len,
                   const char           *src_path,
                   const char           *file_name);

#ifdef MSF_CFG_OBJECT_ACTION_EXT
void
MSMc_objectActionExt (const char           *mime_type,
                      MsfResourceType       data_type,
                      const unsigned char  *data,
                      MSF_INT32             data_len,
                      const char           *src_path,
                      const char           *file_name,
                      const char*           excl_act_strings[],
                      MSF_INT32             excl_act_strings_cnt);
#endif

#endif
