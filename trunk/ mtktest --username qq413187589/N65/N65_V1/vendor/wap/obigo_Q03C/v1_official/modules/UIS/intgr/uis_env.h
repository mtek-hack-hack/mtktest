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
 * uis_env.h
 *
 * Created by Klas Hermodsson, Tue 03 June 2003.
 *
 * Revision  history:
 * 
 *
 */

#ifndef _uis_env_h
#define _uis_env_h


void
UISc_start (void);

int
UISc_wantsToRun (void);

void
UISc_run (void);

void
UISc_kill (void);

#endif


