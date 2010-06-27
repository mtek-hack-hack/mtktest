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






#ifndef _prs_val_h
#define _prs_val_h

#ifndef _prs_main_h
#include "prs_main.h"
#endif









int
prs_validate (prs_job_t* job);









int
prs_br_validate_node_internal (prs_node_t* node);

int 
prs_syn_validate_node_internal (prs_node_t* node);

int 
prs_wap_validate_node_internal (prs_node_t* node);








int
prs_br_fill_in_node (prs_node_t* node);

int
prs_syn_fill_in_node (prs_node_t* node);

int
prs_wap_fill_in_node (prs_node_t* node);

#endif


