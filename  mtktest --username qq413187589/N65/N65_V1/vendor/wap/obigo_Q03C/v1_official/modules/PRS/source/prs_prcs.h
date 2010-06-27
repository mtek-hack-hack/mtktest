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






#ifndef _prs_prcs_h
#define _prs_prcs_h

#ifndef _prs_main_h
#include "prs_main.h"
#endif









int
prs_process (prs_job_t* job);








int
prs_br_process_list_pre_internal (prs_node_list_t* list);

int
prs_syn_process_list_pre_internal (prs_node_list_t* list);

int
prs_wap_process_list_pre_internal (prs_node_list_t* list);

#endif


