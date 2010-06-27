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
 * sec_env.h
 *
 * Created by Anna Andréasson
 *
 * Revision  history:
 *
 *
 */

#ifndef _sec_env_h
#define _sec_env_h

void
SECc_start (void);

int
SECc_wantsToRun (void);

void
SECc_run (void);

void
SECc_kill (void);


#endif
