/*
 * Copyright (C) Obigo AB, 2002-2007.
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






























#ifndef _brs_sili_h
#define _brs_sili_h

#include "brs_cfg.h"
#ifdef BRS_CONFIG_WMLS
#ifndef  _msf_def_h
#include "msf_def.h"
#endif

#ifndef  _brs_sisi_h
#include "brs_sisi.h"
#endif

#ifdef BRS_CONFIG_PLUGIN
#ifndef  _brs_plg_h
#include "brs_plg.h"
#endif
#endif

int
brs_si_CallLibraryFunction (brs_si_si_t *si, int lib_index, int func_index);

void
brs_si_Lib_LoadStringDone (brs_si_si_t *si, int charset, char *str,
                           MSF_UINT32 str_len, int status);

#ifdef BRS_CONFIG_WMLS_CRYPTO
void
brs_si_Lib_textSigned (brs_si_si_t *si, int algoritm, int sigLen,
                       unsigned char *signature, 
                       unsigned char *hashedKey, int hashedKeyLen, 
                       unsigned char *certificate, int certificateLen,
                       int certificateType, int err);
#endif

#ifdef BRS_CONFIG_PLUGIN
int
brs_si_Lib_ProprietaryLibraryFunctionResponse (brs_si_si_t *si,
                                               int status_code,
                                               brs_plg_wmls_var_t *result_var);

#endif
#endif
#endif
