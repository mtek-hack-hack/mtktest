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
 * msf_pipe.h
 *
 * Created by Ingmar Persson
 *
 * Revision  history:
 *   020905, AED: Added error codes
 *   021014, IPN: Added MSF_PIPE_CLOSE_ALL
 *
 */
#ifndef _msf_pipe_h
#define _msf_pipe_h

#ifndef _msf_int_h
#include "msf_int.h"
#endif

/****************************************
 * Named Pipes
 ****************************************/

/* Notification types */
#define MSF_PIPE_EVENT_CLOSED                     HDI_PIPE_EVENT_CLOSED
#define MSF_PIPE_EVENT_READ                       HDI_PIPE_EVENT_READ
#define MSF_PIPE_EVENT_WRITE                      HDI_PIPE_EVENT_WRITE

#ifdef NEW_PIPE_ERROR_EVENT
#define MSF_PIPE_EVENT_CLOSED_ERROR               HDI_PIPE_EVENT_CLOSED_ERROR
#endif

/*
 * Error codes
 */
#define MSF_PIPE_ERROR_BAD_HANDLE                 HDI_PIPE_ERROR_BAD_HANDLE
#define MSF_PIPE_ERROR_INVALID_PARAM              HDI_PIPE_ERROR_INVALID_PARAM
#define MSF_PIPE_ERROR_EXISTS                     HDI_PIPE_ERROR_EXISTS
#define MSF_PIPE_ERROR_IS_OPEN                    HDI_PIPE_ERROR_IS_OPEN
#define MSF_PIPE_ERROR_DELAYED                    HDI_PIPE_ERROR_DELAYED
#define MSF_PIPE_ERROR_RESOURCE_LIMIT             HDI_PIPE_ERROR_RESOURCE_LIMIT
#define MSF_PIPE_ERROR_CLOSED                     HDI_PIPE_ERROR_CLOSED
#define MSF_PIPE_ERROR_NOT_FOUND                  HDI_PIPE_ERROR_NOT_FOUND

#ifdef NEW_PIPE_ERROR_EVENT
#define MSF_PIPE_ERROR_CLOSED_ERROR               HDI_PIPE_ERROR_CLOSED_ERROR
#endif


/*
 * Functions
 */
#define MSF_PIPE_CREATE                           HDIa_pipeCreate
#define MSF_PIPE_OPEN                             HDIa_pipeOpen
#define MSF_PIPE_CLOSE                            HDIa_pipeClose
#define MSF_PIPE_DELETE                           HDIa_pipeDelete
#define MSF_PIPE_READ                             HDIa_pipeRead
#define MSF_PIPE_WRITE                            HDIa_pipeWrite
#define MSF_PIPE_POLL                             HDIa_pipePoll
#define MSF_PIPE_STATUS                           HDIa_pipeStatus
#define MSF_PIPE_CLOSE_ALL                        HDIa_pipeCloseAll

#ifdef NEW_PIPE_ERROR_EVENT
#define MSF_PIPE_CLOSE_ERROR                      HDIa_pipeCloseError
#endif

#endif
