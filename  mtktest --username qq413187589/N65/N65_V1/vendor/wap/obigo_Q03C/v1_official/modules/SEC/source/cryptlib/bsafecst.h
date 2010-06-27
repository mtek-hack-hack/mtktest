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

#ifndef _BSAFECST_H_
#define _BSAFECST_H_ 1

#include "bsafe.h"

/*
 * CST-specific routines:
 */

#include "ut.h"
#include "bsapi.h"

extern int
bsafe_pubKey2cst(ITEM *in, ut_mblk *out);

extern int
bsafe_priKey2cst(ITEM *in, ut_mblk *out);

int
bsafe_berkey2key(ut_mblk *tmp, B_KEY_OBJ key_p, bsapi_kset_key_type ktype);


/* uses some random data from prng to seed the BSAFE rng 
 * use kill_bsafe_prng(...) to kill and de-allocate memory 
 */

extern int start_bsafe_prng(prng_inst       *  prng, 
                            B_ALGORITHM_OBJ ** randomAlgorithmObj);

/* disposes of the memory allocated in start_bsafe_random_number_generator
 */
extern int kill_bsafe_prng(B_ALGORITHM_OBJ * bsafe_prng);

extern int item2mblk(ITEM * info, ut_mblk * mblk);

extern int bsafe_dsa_key2mblk(ITEM * bsafeKey, ut_mblk *cstkey);

extern u8 * bsafe_item2berinteger(ITEM * num, u8 *dest);

extern sec_off_t bsafe_sizeof_item2berinteger(ITEM * num);

extern u8 * bsafe_berinteger2item(u8 * src, ITEM *num);

extern u8 * bsafe_dsa_berparameter2pqg(u8 *data, ITEM * p, ITEM * q, ITEM * g);

#ifdef __cplusplus
}
#endif

#endif /* end _BSAFECST_H_ */

