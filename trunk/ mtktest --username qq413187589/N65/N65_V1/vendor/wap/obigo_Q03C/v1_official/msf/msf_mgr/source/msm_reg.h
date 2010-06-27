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










#ifndef _msm_reg_h
#define _msm_reg_h

#ifndef _msf_core_h
#include "msf_core.h"
#endif





#define MSM_REG_PATHNAME                          "/msm"
#define MSM_REG_FILENAME                          "/msm/registry.dat"
#define MSM_REG_MAX_LENGTH_OF_STRING_VALUE        500
#define MSM_REG_MAX_LENGTH_OF_PATH_KEY            8
#define MSM_REG_MAX_LEVELS_OF_PATHS               5






#define MSM_REGISTRY_SIG_SET          MSM_SIG_DST_MSM_REGISTRY + 1
#define MSM_REGISTRY_SIG_DELETE       MSM_SIG_DST_MSM_REGISTRY + 2
#define MSM_REGISTRY_SIG_GET          MSM_SIG_DST_MSM_REGISTRY + 3
#define MSM_REGISTRY_SIG_RUN          MSM_SIG_DST_MSM_REGISTRY + 4


















void
msm_reg_init (const char* startup_file, const char* default_file);




void
msm_reg_terminate (void);









void
msm_reg_int_set_init (void);




void
msm_reg_int_set_path (char* path);




void
msm_reg_int_set_add_key_int (char* key, MSF_INT32 value);




void
msm_reg_int_set_add_key_str (char* key, unsigned char* value, MSF_UINT16 valueLength);




void
msm_reg_int_set_commit (void);




int
msm_reg_int_resp_get_next (MSF_UINT8 id, msf_registry_param_t* param);




void
msm_reg_int_resp_free (MSF_UINT8 id);

#endif
