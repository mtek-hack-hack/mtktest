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
 * prs_if.h
 *
 * Provisioning interface.
 */

#ifndef _prs_if_h
#define _prs_if_h

#ifndef _msf_cfg_h
#include "msf_cfg.h"
#endif

#ifndef _msf_def_h
#include "msf_def.h"
#endif

#ifndef _msf_dcvt_h
#include "msf_dcvt.h"
#endif


/**********************************************************************
 * Signals 
 **********************************************************************/

/* Signals sent to the PRS */

/* Signals sent from the PRS */
#define PRS_SIG_PROVISIONING_OUTPUT      ((MSF_MODID_PRS << 8) + 0x01)


/**********************************************************************
 * Signal parameters 
 **********************************************************************/

/*
 * Called by any other module that wants to use the PRS module.
 */
void
PRSif_startInterface (void);


/**********************************************************************
 * Conversion routines for all signals owned by this module.
 * None of these functions should be called directly by another module.
 **********************************************************************/

void*
prs_convert (MSF_UINT8 module, MSF_UINT16 signal, void* buffer);

void
prs_destruct (MSF_UINT8 module, MSF_UINT16 signal, void* p);


#endif


