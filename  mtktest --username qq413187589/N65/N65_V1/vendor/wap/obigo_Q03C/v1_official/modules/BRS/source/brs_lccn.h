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
















#ifndef _brs_lccn_h
#define _brs_lccn_h

#ifndef _msf_def_h
#include "msf_def.h"
#endif
#ifndef _brs_ddt_h
#include "brs_ddt.h"
#endif
#ifndef _brs_ldef_h
#include "brs_ldef.h"
#endif












int
brs_le_get_internal_default (brs_dt_tree_node_t *node, brs_le_common_t *common,
                             int property, MSF_UINT32 *value);

#endif
