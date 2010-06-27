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

#ifndef _PAD_H /* prevent multiple inclusion */
#define _PAD_H

/*loko#include "stdlib.h"*/  /* For size_t */

#include "padtypes.h" /* For u8, pad_algn, ... */
#include "prng.h"     /* For prng_inst */
#include "cstopt.h"   /* For WITH_pad_bdes, WITH_pad_brsa, WITH_pad_brsaorig,
    WITH_pad_pkcs1, & WITH_pad_iso9796 */

#include "hash.h"
#include "mgf.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
    
/* Errors */

#define PAD_EBASE (0x00600000) /* Module code */

#define PAD_ENOSPC (PAD_EBASE + 0x40000) /* Not enough space to pad */
#define PAD_EPRNGF (PAD_EBASE + 0x40001) /* prng failure */
#define PAD_ECRUPT (PAD_EBASE + 0x40002) /* Padding is corrupt */
#define PAD_ENOPRM (PAD_EBASE + 0x50000) /* Null parameters detected */
#define PAD_EPARAM (PAD_EBASE + 0x40003) /* Bad Parameter */


/* Data:        <pads>
 * Summary:     Array of supported pad algorithms
 * Description: The pads array contains a pointer to the pad_alg structure
 *              corresponding to each of the supported pad algorithms.
 *              A specific pad algorithm structure can be obtained from
 *              pads using ut_choose().
 */
extern const pad_alg CST32EXPORTDATA * CST16EXPORTDATA pads[];

/*
 * Algoithm-specific declarations
 */

#ifdef WITH_pad_padnone


/* Data:        <pad_padnone>
 * Summary:     Performs no padding. 
 * Notes:       The ut_choose() name for this structure is "Pad-None".
 */

/* Function:    <pad_padnone_pad>
 * Summary:     Does nothing.
 * Syntax:      int rval = pad_padnone_pad(u8 *data, size_t unpadded, 
 *                size_t padded, pad_params *ppar);
 * Returns:     Returns 0 on success or -1 if data is null or if unpadded 
 *              is neither 0 nor equal to padded.
 */
extern int pad_padnone_pad(u8 *data, size_t unpadded, size_t padded,
    pad_params *ppar);

/* Function:    <pad_padnone_unpad>
 * Summary:     Sets the value of unpadded equal to padded.
 * Syntax:      int rval = pad_padnone_unpad(u8 *data, size_t unpadded, 
 *                size_t padded, pad_params *ppar);
 * Returns:     Returns 0 unless data is null in which case returns -1.
 */
extern int pad_padnone_unpad(u8 *data, size_t *unpadded, size_t padded,
    pad_params *ppar);

/* Function:    <pad_padnone_padsize>
 * Summary:     Returns 0.
 * Syntax:      size_t rval = pad_padnone_padsize(pad_params *ppar);
 */
extern size_t pad_padnone_padsize(pad_params *ppar);

extern const pad_alg CST32EXPORTDATA CST16EXPORTDATA pad_padnone;

#endif /* WITH_pad_padnone */


#ifdef WITH_pad_bdes

/* Data:        <pad_bdes>
 * Summary:     Baltimore-DES - for compatibility with previous DES releases
 * Description: Used with DES, Triple DES, IDEA (if provided) and RC2.
 *              Has no specific parameters; uses the prng supplied to
 *              bsapi_start_ALG.
 * Notes:       The ut_choose() name for this structure is "Baltimore-DES".
 */

/* Function:    <pad_bdes_pad>
 * Summary:     Pads data using the Baltimore-DES padding algorithm.
 * Syntax:      int rval = pad_bdes_pad(u8 *data, size_t unpadded, size_t padded,
 *                pad_params *ppar);
 */
extern int pad_bdes_pad(u8 *data, size_t unpadded, size_t padded,
    pad_params *ppar);

/* Function:    <pad_bdes_unpad>
 * Summary:     Unpads data using the Baltimore-DES padding algorithm.
 * Syntax:      int rval = pad_bdes_unpad(u8 *data, size_t unpadded, size_t padded,
 *                pad_params *ppar);
 */
extern int pad_bdes_unpad(u8 *data, size_t *unpadded, size_t padded, 
    pad_params *ppar);

/* Function:    <pad_bdes_padsize>
 * Summary:     Returns 0.
 * Syntax:      size_t rval = pad_bdes_padsize(pad_params *ppar);
 */
extern size_t pad_bdes_padsize(pad_params *ppar);

extern const pad_alg CST32EXPORTDATA CST16EXPORTDATA pad_bdes;

#endif /* WITH_pad_bdes */

#ifdef WITH_pad_pkcs5


/* Data:        <pad_pkcs5>
 * Summary:     PKCS#5 padding - fills every byte with the number of padding 
 *              bytes
 * Description: Used with DES, Triple DES, IDEA (if provided) and RC2.
 *              Doesn't require a prng.
 * Notes:       The ut_choose() name for this structure is "PKCS-5".
 */

/* Function:    <pad_pkcs_pad>
 * Summary:     Pads data using the PKCS#5 padding algorithm.
 * Syntax:      int rval = pad_pkcs5_pad(u8 *data, size_t unpadded, size_t padded,
 *                pad_params *ppar);
 */
extern int pad_pkcs5_pad(u8 *data, size_t unpadded, size_t padded,
    pad_params *ppar);

/* Function:    <pad_pkcs5_pad>
 * Summary:     Unpads data using the PKCS#5 padding algorithm.
 * Syntax:      int rval = pad_pkcs5_unpad(u8 *data, size_t unpadded, size_t padded,
 *                pad_params *ppar);
 */
extern int pad_pkcs5_unpad(u8 *data, size_t *unpadded, size_t padded,
    pad_params *ppar);

/* Function:    <pad_pkcs5_padsize>
 * Summary:     Returns -1.
 * Syntax:      size_t rval = pad_pkcs5_padsize(pad_params *ppar);
 */
extern size_t pad_pkcs5_padsize(pad_params *ppar);

extern const pad_alg CST32EXPORTDATA CST16EXPORTDATA pad_pkcs5;

#endif /* WITH_pad_bdes */

#ifdef WITH_pad_brsa
/* Data:        <pad_brsa>
 * Summary:     Baltimore-RSA - for compatibility with previous RSA releases
 * Description: Used with RSA. Uses the prng supplied to bsapi_start_ALG.
 * Notes:       The ut_choose() name for this structure is "Baltimore-RSA".
 */

/* Function:    <pad_brsa_pad>
 * Summary:     Pads data using the Baltimore-RSA padding algorithm.
 * Syntax:      int rval = pad_brsa_pad(u8 *data, size_t unpadded, size_t padded,
 *                pad_params *ppar);
 */
extern int pad_brsa_pad(u8 *data, size_t unpadded, size_t padded,
    pad_params *ppar);

/* Function:    <pad_brsa_unpad>
 * Summary:     Unpads data using the Baltimore-RSA padding algorithm.
 * Syntax:      int rval = pad_brsa_unpad(u8 *data, size_t unpadded, size_t padded,
 *                pad_params *ppar);
 */
extern int pad_brsa_unpad(u8 *data, size_t *unpadded, size_t padded,
    pad_params *ppar);

/* Function:    <pad_brsa_padsize>
 * Summary:     Returns 0.
 * Syntax:      size_t rval = pad_brsa_padsize(pad_params *ppar);
 */
extern size_t pad_brsa_padsize(pad_params *ppar);

extern const pad_alg CST32EXPORTDATA CST16EXPORTDATA pad_brsa;

#endif /* WITH_pad_brsa */

#ifdef WITH_pad_brsaorig
/* Data:        <pad_brsaorig>
 * Summary:     Baltimore-RSA-original - for compatibility with original RSA release
 * Description: Used with RSA. Uses the prng supplied to bsapi_start_rsa().
 * Notes:       The ut_choose() name for this structure is
 *              "Baltimore-RSA-original".
 */

/* Function:    <pad_brsaorig_pad>
 * Summary:     Pads data using the Baltimore-RSA-original padding algorithm.
 * Syntax:      int rval = pad_brsaorig_pad(u8 *data, size_t unpadded, size_t padded,
 *                pad_params *ppar);
 */
extern int pad_brsaorig_pad(u8 *data, size_t unpadded, size_t padded,
    pad_params *ppar);

/* Function:    <pad_brsaorig_unpad>
 * Summary:     Unpads data using the Baltimore-RSA-original padding algorithm.
 * Syntax:      int rval = pad_brsaorig_unpad(u8 *data, size_t unpadded, size_t padded,
 *                pad_params *ppar);
 */
extern int pad_brsaorig_unpad(u8 *data, size_t *unpadded, size_t padded,
    pad_params *ppar);

/* Function:    <pad_brsaorig_padsize>
 * Summary:     Returns 0.
 * Syntax:      size_t rval = pad_brsaorig_padsize(pad_params *ppar);
 */
extern size_t pad_brsaorig_padsize(pad_params *ppar);

extern const pad_alg CST32EXPORTDATA CST16EXPORTDATA pad_brsaorig;

#endif /* WITH_pad_brsaorig */

#ifdef WITH_pad_oaeppkcs

/* Data:        <pad_oaep_pkcs1>
 * Summary:     OAEP as specified in PKCS#1 v.2
 * Description: Used with RSA encryption. Uses the prng supplied to 
 *              bsapi_start_rsa(). See there for more details.
 * Notes:       The ut_choose() name for this structure is "OAEP-PKCS".
 */

/* Function:    <pad_oaep_pkcs1_pad>
 * Summary:     Pads data using the PKCS#1 OAEP padding algorithm.
 * Syntax:      int rval = pad_oaep_pkcs1_pad(u8 *data, size_t unpadded, size_t padded,
 *                pad_params *ppar);
 */
extern int pad_oaep_pkcs1_pad(u8 *data, size_t unpadded, size_t padded,
    pad_params *ppar);

/* Function:    <pad_oaep_pkcs1_unpad>
 * Summary:     Unpads data using the PKCS#1 OAEP padding algorithm.
 * Syntax:      int rval = pad_oaep_pkcs1_unpad(u8 *data, size_t unpadded, size_t padded,
 *                pad_params *ppar);
 */
extern int pad_oaep_pkcs1_unpad(u8 *data, size_t *unpadded, size_t padded,
    pad_params *ppar);

/* Function:    <pad_oaep_pkcs1_padsize>
 * Summary:     Returns 2*(halg->sizeof_hash(0)) + 1 where halg denotes the
 *              hash algorithm specified in the padding parameters.
 * Syntax:      size_t rval = pad_oaep_pkcs1_padsize(pad_params *ppar);
 */
extern size_t pad_oaep_pkcs1_padsize(pad_params *ppar);

extern const pad_alg CST32EXPORTDATA CST16EXPORTDATA pad_oaep_pkcs1;

/* Type:        <pad_oaep_pkcs1_params>
 * Summary:     Padding parameter structure for pad_oaep_pkcs1
 */
typedef struct pad_oaep_pkcs1_params_s {
  const hash_alg   *halg;
  const mgf_alg    *mgalg;
  mgf_params       mgpar;
  ut_mblk          *encpar;   /* encoding params -- can be 0 */
} pad_oaep_pkcs1_params;

#endif /* WITH_pad_oaeppkcs */

#ifdef WITH_pad_oaepset1
/* Data:        <pad_oaep_set1>
 * Summary:     OAEP as specified in SET v.1
 * Description: Used with RSA encryption. Uses the prng supplied to 
 *              bsapi_start_rsa(). See there for more details.
 * Notes:       SET hard-wires SHA-1 as the hash algorithm to be used
 *              throughout, which is why it isn't parameterizable in the 
 *              way that the hash algorithm is for oaep_pkcs1.
 * Notes:       The ut_choose() name for this structure is "OAEP_SET".
 */

/* Function:    <pad_oaep_set1_pad>
 * Summary:     Pads data using the SET OAEP padding algorithm.
 * Syntax:      int rval = pad_oaep_set1_pad(u8 *data, size_t unpadded, size_t padded,
 *                pad_params *ppar);
 */
extern int pad_oaep_set1_pad(u8 *data, size_t unpadded, size_t padded,
    pad_params *ppar);

/* Function:    <pad_oaep_set1_unpad>
 * Summary:     Unpads data using the SET OAEP padding algorithm.
 * Syntax:      int rval = pad_oaep_set1_unpad(u8 *data, size_t unpadded, size_t padded,
 *                pad_params *ppar);
 */
extern int pad_oaep_set1_unpad(u8 *data, size_t *unpadded, size_t padded,
    pad_params *ppar);

/* Function:    <pad_oaep_set1_padsize>
 * Summary:     Returns 17.
 * Syntax:      size_t rval = pad_oaep_set1_padsize(pad_params *ppar);
 */
extern size_t pad_oaep_set1_padsize(pad_params *ppar);

extern const pad_alg CST32EXPORTDATA CST16EXPORTDATA pad_oaep_set1;

#endif /* WITH_pad_oaepset1 */

#ifdef WITH_pad_pkcs1
/* Data:        <pad_pkcs1>
 * Summary:     RSA padding as specified in PKCS#1 v1
 * Description: Used with RSA. Uses the prng supplied to bsapi_start_rsa(). 
 *              Padding varies according to whether we're encrypting with
 *              the public or private key. See bsapi_start_rsa() for more 
 *              details. 
 * Notes:       The ut_choose() name for this structures is "PKCS-1".
 */

/* Function:    <pad_pkcs1_pad>
 * Summary:     Pads data using the PKCS#1 padding algorithm for RSA.
 * Syntax:      int rval = pad_pkcs1_pad(u8 *data, size_t unpadded, size_t padded,
 *                pad_params *ppar);
 */
extern int pad_pkcs1_pad(u8 *data, size_t unpadded, size_t padded,
    pad_params *ppar);

/* Function:    <pad_pkcs1_unpad>
 * Summary:     Unpads data using the PKCS#1 padding algorithm for RSA.
 * Syntax:      int rval = pad_pkcs1_unpad(u8 *data, size_t unpadded, size_t padded,
 *                pad_params *ppar);
 */
extern int pad_pkcs1_unpad(u8 *data, size_t *unpadded, size_t padded, 
    pad_params *ppar);

/* Function:    <pad_pkcs1_padsize>
 * Summary:     Returns 10.
 * Syntax:      size_t rval = pad_pkcs1_padsize(pad_params *ppar);
 */
extern size_t pad_pkcs1_padsize(pad_params *ppar);

extern const pad_alg CST32EXPORTDATA CST16EXPORTDATA pad_pkcs1;

/* Data:        <pad_pkcs1null>
 * Summary:     RSA padding as specified in PKCS#1 v1
 * Description: Used with RSA. Uses the prng supplied to bsapi_start_rsa(). 
 *              Padding varies according to whether we're encrypting with
 *              the public or private key. See bsapi_start_rsa() for more 
 *              details. 
 * Notes:       The ut_choose() name for this structures is "PKCS-1-null".
 */

/* Function:    <pad_pkcs1null_pad>
 * Summary:     Pads data using the PKCS#1 null padding algorithm for RSA.
 * Syntax:      int rval = pad_pkcs1null_pad(u8 *data, size_t unpadded, size_t padded,
 *                pad_params *ppar);
 */
extern int pad_pkcs1null_pad(u8 *data, size_t unpadded, size_t padded,
    pad_params *ppar);

/* Function:    <pad_pkcs1null_padsize>
 * Summary:     Returns 3.
 * Syntax:      size_t rval = pad_pkcs1null_padsize(pad_params *ppar);
 */
extern size_t pad_pkcs1null_padsize(pad_params *ppar);

extern const pad_alg CST32EXPORTDATA CST16EXPORTDATA pad_pkcs1null;

#endif /* WITH_pad_pkcs1 */

#ifdef WITH_pad_iso9796
/* Data:        <pad_iso9796>
 * Summary:     RSA private-key padding as specified in ISO 9796
 * Description: Used with RSA private-key operations (signing or signing-like
 *              operations). Must NOT be used for public-key operations.
 *              See bsapi_start_rsa() for more details. 
 * Notes:       The ut_choose() name for this structure is "ISO9796".
 */

/* Function:    <pad_iso9796_pad>
 * Summary:     Pads data using the ISO 9796 padding algorithm for RSA.
 * Syntax:      int rval = pad_iso9796_pad(u8 *data, size_t unpadded, size_t padded,
 *                pad_params *ppar);
 */
extern int pad_iso9796_pad(u8 *data, size_t unpadded, size_t padded,
    pad_params *ppar);

/* Function:    <pad_iso9796_unpad>
 * Summary:     Unpads data using the ISO 9796 padding algorithm for RSA.
 * Syntax:      int rval = pad_iso9796_unpad(u8 *data, size_t unpadded, size_t padded,
 *                pad_params *ppar);
 */
extern int pad_iso9796_unpad(u8 *data, size_t *unpadded, size_t padded,
    pad_params *ppar);

/* Function:    <pad_iso9796_padsize>
 * Summary:     Returns (msglen+15)/16 where msglen denotes the length 
 *              specified in the padding parameters.
 * Syntax:      size_t rval = pad_iso9796_padsize(pad_params *ppar);
 */
extern size_t pad_iso9796_padsize(pad_params *ppar);

extern const pad_alg CST32EXPORTDATA CST16EXPORTDATA pad_iso9796;

/* Type:        <pad_iso9796_params>
 * Summary:     Padding parameter structure for pad_iso9796
 */
typedef struct pad_iso9796_params_s {
  size_t   msglen;    /* keylength in bits - 1 */
} pad_iso9796_params;

#endif /* WITH_pad_iso9796 */

#ifdef WITH_pad_autod1

/* Data:       <pad_autod1_pkcs1>
 * Summary:    Deprecated
 * Description:Tries to autodetect the method of padding used (either 
 *             Baltimore-RSA, PKCS-1, or PKCS-1-null) when unpadding. Pads
 *             using PKCS-1.
 * Notes:      The ut_choose() name for this structure is "Autodetect-1-pkcs".
 */

extern int pad_autod1_pad(u8 *data, size_t unpadded, size_t padded,
    pad_params *ppar);

extern int pad_autod1_pkcs_unpad(u8 *data, size_t *unpadded, size_t padded,
    pad_params *ppar);

extern size_t pad_autod1_pkcs_padsize(pad_params *ppar);

extern const pad_alg CST32EXPORTDATA CST16EXPORTDATA pad_autod1_pkcs;

/* Data:       <pad_autod1_brsa>
 * Summary:    Deprecated
 * Description:Tries to autodetect the method of padding used (either 
 *             Baltimore-RSA, PKCS-1, or PKCS-1-null) when unpadding. Pads
 *             using PKCS-1.
 * Notes:      The ut_choose() name for this structure is "Autodetect-1-brsa".
 */
extern int pad_autod1_brsa_unpad(u8 *data, size_t *unpadded, size_t padded,
    pad_params *ppar);

extern size_t pad_autod1_brsa_padsize(pad_params *ppar);

extern const pad_alg CST32EXPORTDATA CST16EXPORTDATA pad_autod1_brsa;

#endif /* WITH_pad_autod1 */


/* Type:        <pad_params_s>
 * Summary:     Union of parameters for the various padding algorithms
 */
struct pad_params_s {
  prng_inst    *prng;
  pad_key_type  keytype;
  union {
    int                     dummy;
#ifdef WITH_pad_oaeppkcs
    pad_oaep_pkcs1_params   oaep_pkcs1;
#endif
#ifdef WITH_pad_iso9796
    pad_iso9796_params      iso9796;
#endif
  } alg;
};

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* not _PAD_H */
