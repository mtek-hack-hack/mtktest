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
/*
 * brs_env.h
 *
 * Created by Petter Wallin, Aug 07 2002.
 *
 * Revision  history:
 *
 */
#ifndef _brs_env_h
#define _brs_env_h


/**********************************************************************
 * Function declarations
 **********************************************************************/

void
BRSc_start (void);

int
BRSc_wantsToRun (void);

void
BRSc_run (void);

void
BRSc_kill (void);

#endif
