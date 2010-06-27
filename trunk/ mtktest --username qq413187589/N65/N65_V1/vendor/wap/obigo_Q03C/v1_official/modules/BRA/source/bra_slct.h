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
 * bra_slct.h
 * 
 * Description:
 *    Creates select mode menu.
 *
 */

#ifndef _bra_slct_h
#define _bra_slct_h

#ifndef _bra_cfg_h
#include "bra_cfg.h" 
#endif

#ifdef BRA_CFG_SELECT_MODE

/*
 * This function creates the select mode menu.
 *
 * Note! This function is only availabe when BRA_CFG_SELECT_MODE is defined.
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void 
bra_slct_create_menu (void);

#endif /*BRA_CFG_SELECT_MODE*/

#endif
