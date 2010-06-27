/*
 * Copyright (C) Obigo AB, 2002-2007.
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














#ifndef _brs_dhtm_h
#define _brs_dhtm_h

#ifndef _brs_dcmn_h
#include "brs_dcmn.h"
#endif
#if defined BRS_CONFIG_HTML || defined BRS_CONFIG_XHTML
#ifndef _brs_dmsh_h
#include "brs_dmsh.h"
#endif
#ifndef _brs_ddt_h
#include "brs_ddt.h"
#endif





#define BRS_D_I_MODE_PSEUDO_SCHEME_NAME_CONST        "imode-mic"
#define BRS_D_I_MODE_PSEUDO_SCHEME_SEPARATOR_CONST   '>'

void
brs_d_collect_imode_attrs (brs_d_doc_t *d, brs_dt_tree_node_t *n);







void
brs_d_html_option_selected (brs_d_doc_t *d, int option_handle);



#endif


#endif
