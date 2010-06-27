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


#ifndef _KDF_H  /* prevent multiple inclusion */
#define _KDF_H

#include "cstopt.h"

#ifdef WITH_kdf

#include "ut.h"
#include "hash.h"

#ifdef __cplusplus
extern "C" {
#endif  /* def __cplusplus */

/* Most of this infrastructure is unused in CST v7.3; it's provided 
 * to make future expansion easier.
 */


/* Errors */

#define KDF_EBASE (0x00c00000)     /* Module code */

/* Type:        <kdf_algn>
 * Summary:     Canonical algorithm numbers
 * Description: The kdf_algn enum contains the canonical algorithm 
 *              numbers for use in the kdf_alg structure.
 */
typedef enum {
  KDF_NONE,
  KDF_X942FEB1999,
  KDF_MAX
} kdf_algn;


/* Type:        <kdf_x942Feb1999_params>
 * Summary:     Diffie-Hellman key derivation parameters
 * Description: This structure contains the following fields:
 *              - hashalg is the hash algorithm to be
 *                used to derive the key from the supplied information.
 *                If this field is NULL, the hash algorithm used is SHA-1.
 *              - objid is the OBJECT IDENTIFIER
 *                identifying the algorithm for which the key is to be
 *                generated. This ensures that different algorithms have
 *                different keys.
 *              - partyAInfo is a block of public
 *                information provided by the message originator. It is
 *                considered to be binary data. Its length is given by
 *                partyAInfoLen.
 *              - partyBInfo is a block of public
 *                information provided by the message recipient. It is
 *                considered to be binary data. Its length is given by
 *                partyBInfoLen.
 *              - suppPrivInfo is a block of 
 *                information that is a shared secret, known to both
 *                the sender and recipient. Its length is given by
 *                suppPrivInfoLen.
 *              - suppPubInfo is a block of 
 *                information that is a shared secret, known to both
 *                the sender and recipient. Its length is given by
 *                suppPubInfoLen.
 *              - keylen is the length of the key
 *                to be generated. It is an alternative to the
 *                suppPubInfo fields. Use it when implementing
 *                S/MIME v.3. If both suppPubInfo and keylen
 *                are non-null, keylen is ignored.
 */

typedef struct kdf_x942Feb1999_params_s {
  hash_alg    *hashalg;
  u32         *objid;
  u8          *partyAInfo;
  size_t       partyAInfoLen;
  u8          *partyBInfo;
  size_t       partyBInfoLen;
  u8          *suppPubInfo;
  size_t       suppPubInfoLen;
  u32          keylen;
  u8          *suppPrivInfo;
  size_t       suppPrivInfoLen;
}  kdf_x942Feb1999_params;

/* Type:        <kdf_params>
 * Summary:     Union of parameters for kdf algorithms
 * Description: The kdf_params structure is a union of the parameter
 *              structures required by every key derivation function.
 *              See the individual algorithms for details.
 */
typedef union kdf_params_s {
  kdf_x942Feb1999_params  x942Feb1999;
  int                     dummy;
} kdf_params;

/* Type:        <kdf_alg>
 * Summary:     Function pointers for kdf create functions
 * Description: The fields in this structure are as follows.
 *              name: a null-terminated char * containing only alphanumeric
 *                characters and "-". This is used by ut_choose() when 
 *                selecting a kdf_alg from the kdfs[] array.
 *              number: one of the canonical kdf_algn numbers given above.
 *              derive: the kdf_derive_ALG function for the given ALG.
 */

typedef struct kdf_alg_s {
  const char  *name;
  kdf_algn     number;
  int        (*derive)(ut_mblk *, kdf_params *, u8 *);
} kdf_alg;


/* Data:        <kdfs>
 * Summary:     Array of supported kdf algorithms
 * Description: The kdf array contains a pointer to the kdf_alg structure
 *              corresponding to each of the supported kdf algorithms
 *              (currently only kdf_x942Feb1999). A specific kdf algorithm 
 *              structure can be obtained from kdf using ut_choose().
 */
extern const kdf_alg CST32EXPORTDATA * CST16EXPORTDATA kdfs[];


/* Function:    <kdf_derive_x942Feb1999>
 * Summary:     Derives a key from shared value according to X9.42, Feb 1999.
 * Syntax:      int rval = kdf_derive_x942Feb1999 (ut_mblk *shared,
 *                kdf_params *params, u8 *out);
 * Description: The kdf_derive_x942Feb1999() function derives a key from
 *              the value in shared and the parameters in params, and
 *              places the result in out. Enough memory at out must
 *              already have been allocated to hold the key. The
 *              parameters in params are as follows:
 *              - params->x942Feb1999.hashalg is the hash algorithm to be
 *                used to derive the key from the supplied information.
 *                If this field is NULL, the hash algorithm used is SHA-1.
 *              - params->x942Feb1999.objid is the OBJECT IDENTIFIER
 *                identifying the algorithm for which the key is to be
 *                generated. This ensures that different algorithms have
 *                different keys.
 *              - params->x942Feb1999.partyAInfo is a block of public
 *                information provided by the message originator. It is
 *                considered to be binary data. Its length in octets is given by
 *                params->x942Feb1999.partyAInfoLen.
 *              - params->x942Feb1999.partyBInfo is a block of public
 *                information provided by the message recipient. It is
 *                considered to be binary data. Its length in octets is given by
 *                params->x942Feb1999.partyBInfoLen.
 *              - params->x942Feb1999.suppPrivInfo is a block of 
 *                information that is a shared secret, known to both
 *                the sender and recipient. Its length in octets is given by
 *                params->x942Feb1999.suppPrivInfoLen.
 *              - params->x942Feb1999.suppPubInfo is a block of 
 *                information that is a shared secret, known to both
 *                the sender and recipient. Its length in octets is given by
 *                params->x942Feb1999.suppPubInfoLen.
 *              - params->x942Feb1999.keylen is the length in bits of the
 *                key to be generated. It is an alternative to the
 *                params->x942Feb1999.suppPubInfo fields. Use it when
 *                implementing S/MIME v.3. If both suppPubInfo and
 *                keylen are non-null, keylen is ignored.
 *
 *              The parameters are ASN.1 formatted according to X9.42
 *              and passed through the hash function specified in
 *              params->x942Feb1999.hashalg. Note that prior to the
 *              formatting, the data is considered to be a byte array;
 *              so, for example, the partyAInfo has an ASN.1 OCTET
 *              STRING header placed in front of it, and then an ASN.1
 *              EXPLICIT [0] tag header placed in front of that.
 *
 * Returns:     This function returns 0 on success or -1 on failure. In
 *              debug mode, it returns -2 if shared, params, out or
 *              params->x942Feb1999.objid are NULL.
 * Memory:      This function allocates no memory.
 * Notes:       X9.42 is the key derivation function mandated for use in
 *              S/MIME. To use the function in an S/MIME compliant way:
 *              - Set params->x942Feb1999.hashalg = &hash_sha.
 *              - Set params->x942Feb1999.objid to be an algid_objid for
 *                one of the algorithms supported in S/MIME.
 *              - Set params->x942Feb1999.partyAInfo to be EITHER a
 *                pointer to a 64-byte buffer of random data (in this
 *                case setting params->x942Feb1999.partyAInfoLen = 0) OR
 *                0.
 *              - Set params->x942Feb1999.partyBInfo, 
 *                params->x942Feb1999.suppPrivInfo,
 *                params->x942Feb1999.suppPubInfo = 0.
 *              - If params->x942Feb1999.objid is an object identifier
 *                for an algorithm that has a variable keylength (e.g.
 *                RC2), set params->x942Feb1999.keylen to be the
 *                length of the key. Otherwise, it can be 0.
 */
int
kdf_derive_x942Feb1999 (ut_mblk *shared, kdf_params *params, u8 *out);


/* Data:        <kdf_x942Feb1999>
 * Summary:     Function pointers for x942Feb1999 kdf routines
 * Notes:       The ut_choose() name for this structure is "X9-42-Feb-99".
 */
extern const kdf_alg kdf_x942Feb1999;


#ifdef __cplusplus
}       /* match extern "C" { above */
#endif  /* def __cplusplus */

#endif  /* def WITH_kdf */

#endif  /* ndef _KDF_H */

