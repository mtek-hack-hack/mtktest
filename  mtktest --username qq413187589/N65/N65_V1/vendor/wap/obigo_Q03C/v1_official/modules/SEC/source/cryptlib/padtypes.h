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

#ifndef _PADTYPES_H /* Prevent multiple inclusion */
#define _PADTYPES_H

#include "uttypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Type:        <pad_algn>
 * Summary:     Canonical algorithm numbers.
 * Description: The pad_algn enum contains the canonical algorithm 
 *              numbers for use in the pad_alg structure.
 */
typedef enum {
  PAD_NONE,
  PAD_BDES,
  PAD_BRSA,
  PAD_PKCS1,
  PAD_PKCS5,
  PAD_PKCS1NULL,
  PAD_ISO9796,
  PAD_BRSAORIG,
  PAD_AUTOD1PKCS,
  PAD_AUTOD1BRSA,
  PAD_OAEPPKCS1,
  PAD_OAEPSET1,
  PAD_PADNONE,
  PAD_MAX
} pad_algn;

/* key-type -- maps onto bsapi_kset_key_type */
typedef enum {
  PAD_KEY_TYPE_DEFAULT, PAD_PRIVATE, PAD_PUBLIC
} pad_key_type;


/* Type:        <pad_params>
 * Summary:     Union of parameters for pad algorithms
 * Description: The pad_params structure is a union of the parameter
 *              structures required by every padding algorithm.
 *              See the individual algorithms for details.
 */
typedef struct pad_params_s   pad_params;

/* Type:        <pad_alg>
 * Summary:     Function pointers for padding algorithms
 * Description: The fields in this structure are as follows.
 *              name -- A null-terminated char * containing only alphanumeric
 *                characters and "-". This is used by ut_choose() when 
 *                selecting a pad_alg from the pads[] array.
 *              number -- one of the canonical pad_algn numbers given above.
 *              pad -- the padding function.
 *              unpad -- the unpadding function.
 *              padsize -- a function returning the number of bytes which must 
 *                be used for padding. This field is only used for RSA.
 *              nullbyte -- only used for RSA. nullbyte = 1 means the 
 *                plaintext must be one byte shorter than the modulus (to 
 *                guarantee that it represents a number that's smaller than 
 *                the modulus). nullbyte = 0 means the plaintext block is the 
 *                same length as the modulus. 
 * Notes:       Neither padsize nor nullbyte affects the use of 
 *              bsapi_append_rsa() from the developer's point of view; the 
 *              RSA session uses them internally.
 */

typedef struct pad_alg_s {
  const char  *name;
  pad_algn     number;
  int        (*pad)(u8 *, size_t, size_t, pad_params *);
  int        (*unpad)(u8 *, size_t *, size_t, pad_params *);
  size_t     (*padsize)(pad_params *);
  int          nullbyte;
} pad_alg;

#ifdef __cplusplus
}
#endif

#endif /* _PADTYPES_H */
