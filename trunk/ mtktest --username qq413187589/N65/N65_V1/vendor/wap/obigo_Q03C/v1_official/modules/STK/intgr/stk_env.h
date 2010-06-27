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
 * stk_env.h
 *
 * Created by Anders Edenbrandt, Thu May 02 17:19:40 2002.
 *
 * Revision  history:
 *
 */
#ifndef _stk_env_h
#define _stk_env_h


/**********************************************************************
 * Function declarations
 **********************************************************************/

void
STKc_start (void);

int
STKc_wantsToRun (void);

void
STKc_run (void);

void
STKc_kill (void);

#endif
