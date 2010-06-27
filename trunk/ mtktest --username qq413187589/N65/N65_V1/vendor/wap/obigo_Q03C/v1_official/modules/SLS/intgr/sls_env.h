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
/*! \file sls_env.h
 * \brief  <brief description>
 */

#ifndef _SLS_ENV_H
#define _SLS_ENV_H

/*--- Definitions/Declarations ---*/

/*--- Types ---*/

/*--- Constants ---*/

/*--- Forwards ---*/

/*--- Externs ---*/

/*--- Macros ---*/

void
SLSc_start(void);

int
SLSc_wantsToRun(void);

void
SLSc_run(void);

/*!
 * \brief This function is called by the system in emergency situations.
 *
 *****************************************************************************/
void SLSc_kill (void);

/*!
 * \brief Used to emergency stop the SMIL Service in case of no available memory
 *
 * ONLY FOR SLS SERVICE INTERNAL USAGE.
 *****************************************************************************/
void sls_exception_handler(void);


#endif /* _SLS_ENV_H */



