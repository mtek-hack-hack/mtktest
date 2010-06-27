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








 
#ifndef _phs_mprt_h
#define _phs_mprt_h

#ifndef _phs_cfg_h
#include "phs_cfg.h"
#endif

#ifdef PHS_CONFIG_MULTIPART 

#ifndef _phs_sig_h
#include "phs_sig.h"
#endif

#ifndef _phs_main_h
#include "phs_main.h"
#endif








#define PHS_MPRT_SIG_NEW_MESSAGE                    PHS_MODULE_MPRT + 1









void
phs_mprt_init (void);

void
phs_mprt_main (phs_signal_t* signal);

#endif

#endif


