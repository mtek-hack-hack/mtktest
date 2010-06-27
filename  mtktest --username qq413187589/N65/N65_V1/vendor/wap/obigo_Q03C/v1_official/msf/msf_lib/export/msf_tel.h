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
 * msf_tel.h
 *
 * Created by Ingmar Persson
 *
 * Revision  history:
 *   
 *
 */
#ifndef _msf_tel_h
#define _msf_tel_h

#ifndef _msf_int_h
#include "msf_int.h"
#endif

/**********************************************************************
 * Telephone
 **********************************************************************/

/*
 * Result types
 */
#define MSF_TEL_OK                            HDI_TEL_OK
#define MSF_TEL_ERROR_UNSPECIFIED             HDI_TEL_ERROR_UNSPECIFIED
#define MSF_TEL_ERROR_CALLED_PARTY_IS_BUSY    HDI_TEL_ERROR_CALLED_PARTY_IS_BUSY
#define MSF_TEL_ERROR_NETWORK_NOT_AVAILABLE   HDI_TEL_ERROR_NETWORK_NOT_AVAILABLE
#define MSF_TEL_ERROR_CALLED_PARTY_NO_ANSWER  HDI_TEL_ERROR_CALLED_PARTY_NO_ANSWER
#define MSF_TEL_ERROR_NO_ACTIVE_CONNECTION    HDI_TEL_ERROR_NO_ACTIVE_CONNECTION
#define MSF_TEL_ERROR_INVALID                 HDI_TEL_ERROR_INVALID

/*
 * Functions
 */
#define MSF_TEL_MAKE_CALL                     HDIa_telMakeCall
#define MSF_TEL_SEND_DTMF                     HDIa_telSendDtmf


/**********************************************************************
 * Phonebook
 **********************************************************************/

/*
 * Result types
 */
#define MSF_PB_OK                             HDI_PB_OK
#define MSF_PB_ERROR_UNSPECIFIED              HDI_PB_ERROR_UNSPECIFIED
#define MSF_PB_ERROR_IN_NAME                  HDI_PB_ERROR_IN_NAME
#define MSF_PB_ERROR_NUMBER_TO_LONG           HDI_PB_ERROR_NUMBER_TO_LONG
#define MSF_PB_ERROR_PHONE_BOOK_ENTRY         HDI_PB_ERROR_PHONE_BOOK_ENTRY
#define MSF_PB_ERROR_PHONE_BOOK_IS_FULL       HDI_PB_ERROR_PHONE_BOOK_IS_FULL
#define MSF_PB_ERROR_INVALID                  HDI_PB_ERROR_INVALID

/*
 * Functions
 */
#define MSF_PB_ADD_ENTRY                      HDIa_pbAddEntry

#endif
