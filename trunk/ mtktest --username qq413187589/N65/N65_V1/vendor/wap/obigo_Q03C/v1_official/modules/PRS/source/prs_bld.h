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






#ifndef _prs_bld_h
#define _prs_bld_h

#ifndef _prs_main_h
#include "prs_main.h"
#endif






#define PRS_STATE_ERROR         -1
#define PRS_STATE_START          0









int
prs_init_parser (msf_prsr_parserData_t*  p,
                 msf_prsr_decoderData_t* d,
                 const char*             doctype,
                 int                     len,
                 int                     wbxmlDoctype,
                 int                     charset);





int
prs_build (prs_job_t* job);





void
prs_delete_node (prs_node_list_t* nodeList, prs_node_t* node);





void
prs_free_node (prs_node_t* node);





void
prs_add_user_data_node (prs_node_list_t* list);


#endif


