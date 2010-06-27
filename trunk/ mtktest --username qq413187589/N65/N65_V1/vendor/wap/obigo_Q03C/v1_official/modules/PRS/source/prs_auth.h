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






#ifndef _prs_auth_h
#define _prs_auth_h

#ifndef _prs_main_h
#include "prs_main.h"
#endif






#define PRS_NETWPIN       0
#define PRS_USERPIN       1
#define PRS_USERNETWPIN   2
#define PRS_USERPINMAC    3

#define PRS_AUTH_STATE_GET_PIN        0
#define PRS_AUTH_STATE_REG_PIN1_RCVD  1
#define PRS_AUTH_STATE_USER_PIN_RCVD  2
#define PRS_AUTH_STATE_REG_PIN2_RCVD  3











int
prs_authenticate (prs_job_t* job);







int
prs_extract_auth_info (prs_job_t* job, char *contentHeaders);






void
prs_handle_widget_action (prs_job_t* job, msf_widget_action_t *p);







void
prs_handle_reg_continue_auth (prs_job_t*     job, 
                              char*          paramName,
                              unsigned char* param, 
                              MSF_UINT16     paramLen);

#endif


