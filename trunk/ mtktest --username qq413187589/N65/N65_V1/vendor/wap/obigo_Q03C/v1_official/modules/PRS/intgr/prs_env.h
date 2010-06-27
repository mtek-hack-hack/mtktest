/*
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2003.
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
 * prs_env.h
 */

#ifndef _prs_env_h
#define _prs_env_h


/**********************************************************************
 * Function declarations
 **********************************************************************/

void
PRSc_start (void);

int
PRSc_wantsToRun (void);

void
PRSc_run (void);

void
PRSc_kill (void);


#endif


