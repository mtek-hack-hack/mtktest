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









#ifndef _phs_sia_h
#define _phs_sia_h

#include "phs_cfg.h"

#ifdef PHS_CONFIG_WAP_PUSH_MESSAGES 

#ifndef _phs_sig_h
#include "phs_sig.h"
#endif









void
phs_sia_init (void);




void
phs_sia_terminate (void);

int
phs_handle_sia_push (stk_content_t *p);

void
phs_sia_main (phs_signal_t* signal);

#endif

#endif


