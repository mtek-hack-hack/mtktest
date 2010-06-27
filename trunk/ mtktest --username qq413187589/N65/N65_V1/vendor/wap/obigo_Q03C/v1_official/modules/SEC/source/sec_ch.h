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







#ifndef _sec_ch_h
#define _sec_ch_h

#ifndef _msf_core_h
#include "msf_core.h"
#endif

void sec_content_register(void);

void sec_content_deregister(void);

void sec_execute_cmd(char *p);

void sec_handle_pipe_sig_notify(msf_pipe_notify_t *p);


#endif
