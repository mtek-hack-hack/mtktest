/*
 * Copyright (C) Obigo AB, 2002-2005.
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

/*! \file mms_env.h
 * \brief  Exported functions to be used by the MSF
 *
 * Exported connector functions, i.e. from Target Device Application to the MMS 
 * client. For every connector function, the following data are listed:
 * - A brief one line description of the function
 * - A longer description of the function
 * - The parameters for the function
 */

#ifndef _MMSENV_H
#define _MMSENV_H

/*--- Definitions/Declarations ---*/

/*--- Types ---*/

/*--- Constants ---*/
        
/*--- Forwards ---*/

/*--- Externs ---*/

/*--- Macros ---*/

/*--- Prototypes ---*/

/*!
 * \brief This function is called by the system in emergency situations.
 *
 *****************************************************************************/
void MMSc_kill (void);

/*!
 * \brief Performs an execution 'tick' for the MMS client.
 *
 * When this function is called, the MMS client executes one 'tick' (or 
 * actually one state change in the internal state machines). This function 
 * is only called if MMSc_wantsToRun() has returned TRUE.
 *
 * Type: Request Connector
 *
 * Adapter Name: None.
 *
 *****************************************************************************/
void MMSc_run(void);

/*!
 * \brief Prepares the MMS client for running.
 *
 * The MMS client initializes internal memory structures, timers and data. It
 * is also reading configuration data and setting default values
 *
 * Type: Request Connector
 *
 * Adapter Name: None.
 *
 *****************************************************************************/
void MMSc_start(void);

/*!
 * \brief Cleans up all resources and ends the MMS client.
 *
 * All allocated memory and other resources are deallocated. Tasks 
 * currently running will be aborted.
 *
 * Type: Request Connector
 *
 * Adapter Name: None.
 *
 *****************************************************************************/
void MMSc_terminate(void);

/*!
 * \brief  Check if MMS wants to run. 
 *
 * This connector checks if the MMS client has any signals in its signal queue.
 * If so, the MMSc_run() function shall be called.
 *
 * Type: Request Connector
 *
 * Adapter Name: None.
 *
 * \return 1 if MMS Client has work to do, 0 otherwise
 *****************************************************************************/
int MMSc_wantsToRun(void);

/*!
 * \brief Returns the sender module identification 
 *
 * \returns the module identification 
 *
 * ONLY FOR MMS SERVICE INTERNAL USAGE.
 *****************************************************************************/
MSF_UINT8 getSenderModule(void);

#endif  /* _MMSENV_H */

