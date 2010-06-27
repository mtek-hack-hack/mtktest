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
 * sec_int.h
 *
 * Created by Lone Koch
 *
 * Revision history:
 *
 */

#ifndef _sec_int_h
#define _sec_int_h

/* This function returns a seed.    */
/* seed is the seed to the random number generator    */
/* seedLen is the length of seed, 16 <= seedLen <= 20. */
int SECa_seed(unsigned char *seed, int *seedLen);

#endif

