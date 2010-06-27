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

#ifndef __MONTY_H
#define __MONTY_H

#include "mpm.h"

#ifdef __cplusplus
extern "C" {
#endif

extern void
mpm_prep_montgomery
(mpm_id machine);

extern void
mpm_to_montgomery
(mpm_id machine, mpm_reg dst, mpm_reg src);

extern void
mpm_from_montgomery
(mpm_id machine, mpm_reg dst, mpm_reg src);

extern void
mpm_mulm_montgomery
(mpm_id machine, mpm_reg dst, mpm_reg x, mpm_reg y);

extern void
mpm_expm_montgomery
(mpm_id machine, mpm_reg dst, mpm_reg x, mpm_reg y);

#ifdef __cplusplus
}
#endif

#endif  /* ndef __MONTY_H */
