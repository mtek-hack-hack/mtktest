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
 * prs_a.c
 *
 * Empty implementations of adapter functions.
 */

#include "msf_log.h"
#include "prs_xtrn.h"

/*************************************
 * Functions
 *************************************/


/* int
 * PRSa_networkAccountData (const prs_net_account_data_t* netAccountData, int size);
 * 
 * 'netAccountData' is an array containing all data specified by
 * prs_br_external_numbers or prs_wap_external_numbers, present in the document.
 * 'size' tells how many items the array has.
 *
 * Each item can either be a string or an integer. The type of a specific item
 * is constant. The redundant field 'isString' is suplied: it is non-null when
 * a string. In this case the 's' part of the 'value' union is used and 'strLen'
 * is set to the string length. The strings are NUL-terminated.
 *
 * Integer values can be real integer, such as a bitrate, or an enumerated value.
 * These values can be found in prs_cnst.h.
 *
 * Returns a network account number. It can be the id of a newly created
 * account or an old account.
 */


int
PRSa_networkAccountData (const prs_net_account_data_t* netAccountData, int size)
{
  MSF_LOG_FC_BEGIN(PRSa_networkAccountData)
  MSF_LOG_FC_PTR(netAccountData, NULL); 
  MSF_LOG_FC_INT(size, NULL); 
  MSF_LOG_FC_PRE_IMPL
  MSF_LOG_FC_END
  return 0;
}


