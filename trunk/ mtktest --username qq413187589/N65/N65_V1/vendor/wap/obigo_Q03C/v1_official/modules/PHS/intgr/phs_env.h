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
/*
 * phs_env.h
 *
 * Created by Kent Olsson, Wed July 03 18:23:35 2001.
 *
 * Revision  history:
 * 
 *
 */

#ifndef _phs_env_h
#define _phs_env_h


void
PHSc_start (void);

int
PHSc_wantsToRun (void);

void
PHSc_run (void);

void
PHSc_kill (void);

#endif


