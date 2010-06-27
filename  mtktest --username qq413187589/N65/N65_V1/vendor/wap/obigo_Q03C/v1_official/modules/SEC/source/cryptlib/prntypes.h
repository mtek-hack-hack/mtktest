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

#ifndef _PRNTYPES_H /* Prevent multiple inclusion */
#define _PRNTYPES_H

#include "uttypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Type:        <prng_inst>
 * Summary:     Function pointers for pseudo-random number generators
 * Description: The fields in this structure are as follows.
 *              get -- A function to retrieve random data; len random octets 
 *                are written to memory at ptr; the third parameter, prng, is 
 *                a pointer to the prng_inst structure itself. If the 
 *                generator has not been seeded prior to this function call 
 *                (they are created with a deterministic internal state), then 
 *                it will seed itself using the table module. Returns 0 on 
 *                success or -1 on failure (some prng_get() functions cannot 
 *                fail). Even if it fails, a prng_get() should always leave 
 *                the generator in a usable (although possibly unpredictable) 
 *                state. In general, the problem should be fixed before 
 *                attempting to use the generator again.
 *              destroy -- This function frees all memory associated with the 
 *                generator; prng is a pointer to the generator's prng_inst 
 *                structure.
 *              seed -- A function to mix new seed data into the generator; 
 *                len octets of data are read from memory at ptr, and mixed 
 *                into the generator's internal state. Note that this 
 *                function does not set the state of the generator, it 
 *                changes it; if the generator's state was undefined before 
 *                this call, it will still be undefined afterwards. Returns 0 
 *                on success or -1 on failure (some prng_seed() functions 
 *                cannot fail). Even if it fails, a prng_seed() should always 
 *                leave the generator in a usable (although possibly 
 *                unpredictable) state. In general, the problem should be 
 *                fixed before attempting to use the generator again.
 *              state -- This points to generator-defined internal state 
 *                information.
 */
typedef struct prng_inst_s prng_inst;

struct prng_inst_s {
  int  (*seed)(void *, size_t, prng_inst *);
  int  (*get)(void *, size_t, prng_inst *);
  void (*destroy)(prng_inst *);
  void  *state;
};


/* Type:        <prng_algn>
 * Summary:     Canonical algorithm numbers.
 * Description: The prng_algn enum contains the canonical algorithm 
 *              numbers for use in the prng_alg structure.
 */

typedef enum {
  PRNG_NONE,
  PRNG_BBS,
  PRNG_BBSNONMT,
  PRNG_LCG,
  PRNG_R48,
  PRNG_R48NONMT,
  PRNG_HSHF,
  PRNG_HSHS,
  PRNG_FIPS186,
  PRNG_FIPS186NONMT,
  PRNG_CESGRNG,
  PRNG_INTELISD,
  PRNG_NULLPRNG,
  PRNG_MAX
} prng_algn;

/* Type:        <prng_alg>
 * Summary:     Function pointers to create prngs.
 * Description: The fields in this structure are as follows.
 *              name -- A null-terminated char * containing only alphanumeric
 *                characters and "-". This is used by ut_choose() when 
 *                selecting a prng_alg from the prngs[] array.
 *              number -- one of the canonical prng_algn numbers given above.
 *              use_params -- 1 if the create() function takes parameters
 *                cast to a u8 * (currently only prng_fips186), 0 if it
 *                just takes a u8 *.
 *              threadsafe -- 1 if the algorithm is threadsafe, 0
 *                otherwise.
 *              hw -- 1 if the algorithm is hardware-based.
 *              create -- the prng_create_ALG function for the given ALG.
 */

typedef struct prng_alg_s {
  const char   *name;
  prng_algn     number;
  int           use_params;
  int           threadsafe;
  int           hw;
  prng_inst    *( CST16EXPORTTYPE *create)(u8 *);
} prng_alg;

#ifdef __cplusplus
}
#endif

#endif /* _HSHTYPES_H */
