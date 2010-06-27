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

#ifndef _MGF_H  /* prevent multiple inclusion */
#define _MGF_H

#include "cstopt.h"

#ifdef WITH_mgf

#include "ut.h"
#include "hash.h"

#ifdef __cplusplus
extern "C" {
#endif  /* def __cplusplus */

/* Most of this infrastructure is unused in this release; it's provided
 * to make future expansion easier.
 */


/* ERRORS */

#define MGF_EBASE (0x00b00000)     /* Module code */

/* Type:        <mgf_algn>
 * Summary:     Canonical algorithm numbers.
 * Description: The mgf_algn enum contains the canonical algorithm 
 *              numbers for use in the mgf_alg structure.
 */

typedef enum {
  MGF_NONE,
  MGF_MGF1,
  MGF_SET1H2,
  MGF_MAX
} mgf_algn;


/* Type:        <mgf_params>
 * Summary:     Union of parameters for mgf algorithms
 * Description: The mgf_params structure is a union of the parameter
 *              structures required by every mask generation function.
 *              See the individual algorithms for details.
 */
typedef union mgf_params_s  mgf_params;


/* Type:        <mgf_alg>
 * Summary:     Function pointers for mgf create functions.
 * Description: The fields in this structure are as follows.
 *              name -- A null-terminated char * containing only alphanumeric
 *                characters and "-". This is used by ut_choose() when 
 *                selecting a mgf_alg from the mgfs[] array.
 *              number -- one of the canonical mgf_algn numbers given above.
 *              generate -- the mgf_generate_ALG function for the given ALG.
 */

typedef struct mgf_alg_s {
  const char  *name;
  mgf_algn     number;
  int        (*generate)(ut_mblk *, u8 *, size_t, const mgf_params *);
} mgf_alg;


/* Data:        <mgfs>
 * Summary:     Array of supported mgf algorithms.
 * Description: The mgfs array contains a pointer to the mgf_alg structure
 *              corresponding to each of the supported mgf algorithms.
 *              A specific mgf algorithm structure can be obtained from
 *              mgfs using ut_choose().
 */
extern const mgf_alg CST32EXPORTDATA * CST16EXPORTDATA mgfs[];


/*
 * ALGORITHM-SPECIFIC DECLARATIONS
 */


/*
 * Mask Generation Function 1 
 */

/* mgf_generate_mgf1: Generate a mask for XORing with given data using
 * the MGF1 Mask Generation Function given in PKCS#1. This is the same
 * as the Mask Generation Function H1 described in SET version 1, except
 * that SET mandates the use of SHA-1 while mgf1 takes any hash
 * algorithm.
 *
 * Parameters are:
 *   seed -- a ut_mblk containing the seed data. seed->data gives the
 *     data, seed->used gives the seed length. If seed == 0, the null
 *     string is hashed.
 *   buf -- a buffer containing the data to be XORed. If this buffer is
 *     filled with 0s the raw mask data will be returned in it.
 *   buflen -- the length of masked data desired. At least this amount
 *     of memory must have been allocated at buf.
 *   params -- a pointer to a mgf_mgf1_params structure. This is simply 
 *     a pointer to the hash_alg structure which is to be used to
 *     generate the mask from the seed.
 *
 * The function returns 0 on success, -1 on failure.
 */

extern
int
mgf_generate_mgf1(ut_mblk    *seed,
                  u8         *buf,
                  size_t      buflen,
                  const mgf_params *params);

typedef  const hash_alg * mgf_mgf1_params;


/* Data:        <mgf_mgf1>
 * Summary:     Function pointers for mgf1 mgf routines.
 * Notes:       The ut_choose() name for this structure is "MGF-1".
 */
extern const mgf_alg mgf_mgf1;


/* 
 * H2 (mask generation function from SET version 1)
 */


/* mgf_generate_set1h2: Generate a mask for XORing with given data using
 * the H2 Mask Generation Function given in SET version 1.
 * Parameters are:
 *   seed -- a ut_mblk containing the seed data. seed->data gives the
 *     data, seed->used gives the seed length. If seed == 0, the null
 *     string is hashed.
 *   buf -- a buffer containing the data to be XORed. If this buffer is
 *     filled with 0s the raw mask data will be returned in it.
 *   buflen -- this is ignored. H2 always produces 16 bytes of output.
 *   params -- this is ignored. H2 always uses SHA-1 internally.
 *   
 * The function returns 0 on success, -1 on failure.
 */    
 
int
mgf_generate_set1h2(ut_mblk    *seed,
                  u8         *buf,
                  size_t      buflen,
                  const mgf_params *params);


/* Data:        <mgf_set1h2>
 * Summary:     Function pointers for set1h2 mgf routines.
 * Notes:       The ut_choose() name for this structure is "SETv1-H2".
 */
extern const mgf_alg mgf_set1h2;

/*
 * MGF_PARAMS_S
 */

/* mgf_params_s is a union of all the algorithm-specific mgf_ALG_params
 * structures.
 */

union mgf_params_s {
  mgf_mgf1_params   mgf1;
};

#ifdef __cplusplus
}       /* match extern "C" { above */
#endif  /* def __cplusplus */

#endif  /* def WITH_mgf */

#endif  /* ndef _MGF_H */

