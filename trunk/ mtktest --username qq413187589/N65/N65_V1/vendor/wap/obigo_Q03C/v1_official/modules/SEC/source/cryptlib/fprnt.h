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

#ifndef _FPRNT_H /* Prevent multiple inclusion */
#define _FPRNT_H

#include "msf_lib.h"        /* For FILE */	/* LOKO 22/5 2002 */
/*loko#include "stdio.h"*/ /* For FILE */

#include "mpm.h"   /* For mpm_id & mpm_reg */


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define FPRNT_EBASE (0x00800000) /* Module Code */

#define FPRNT_EBADARGS (FPRNT_EBASE + 0x40000) /* Bad Arguments */
#define FPRNT_EFILEF (FPRNT_EBASE + 0x40001) /* File Op Failure */
#define FPRNT_ENTRNL (FPRNT_EBASE + 0x40002) /* Internal Function Failure */
#define FPRNT_EMPMF (FPRNT_EBASE + 0x40003) /* Internal MPM Failure */
#define FPRNT_ENOMEM (FPRNT_EBASE + 0x40004) /* Out Of Memory */
#define FPRNT_ESERR  (FPRNT_EBASE + 0x40005) /* Syntax Error */


/* Function:    <fprnt_stamp>
 * Syntax:      result = fprnt_stamp(database, machine, register);
 * Description: This extracts the indicated register value into the MPM portable
 *              format and hashes this down to FPRNT_FUNCS keys, each
 *              FPRNT_BITS bits long.  It then stamps this footprint in the
 *              database file (originally created with createdb - it'll be
 *              2^(FPRNT_BITS - 3) bytes long) and returns the number of unused
 *              keys it found - if this result is zero then there is a high
 *              (see prob) probability that that value has been entered in the
 *              database before.
 * Notes:       The database file should be opened for binary update (e.g. with
 *              fopen("test.db", "r+b")).
 * Failure:     If it is unable to extract the register value, either due to its
 *              size or lack of memory, fprnt_stamp() returns -1.
 */
extern int 
 CST32EXPORTTYPE CST16EXPORTTYPE
fprnt_stamp(FILE *, mpm_id, mpm_reg);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* not _FPRNT_H */





