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

#ifndef _DH_H  /* Prevent multiple inclusion */
#define _DH_H

#include "cstopt.h"  /* For WITH_dh_dh */

#ifdef WITH_dh_dh  /* if Diffie-Hellman is in the CST */

#include "ut.h"
#include "prng.h"

#ifdef __cplusplus
extern "C" {
#endif 

  /* Errors */

#define DH_EBASE   (0x00700000)    /* Module Code*/

#define DH_EPARAM (DH_EBASE + 0x07001) /* Bad Parameters */
#define DH_ENTRNL (DH_EBASE + 0x07002) /* Internal Failure */
#define DH_ENOMEM (DH_EBASE + 0x07003) /* out of memory */
#define DH_NOMPM  (DH_EBASE + 0x07004) /* NO mpm */
#define DH_EBSAFE (DH_EBASE + 0x07004) /* BSAFE Error */


/* Function:    <dh_generate_sharedparams_pkcs3>
 * Summary:     Generate parameters for PKCS#3 Diffie-Hellman
 * Syntax:      int rval = dh_generate_sharedparams_pkcs3(prng_inst *prng, u32
 *                mod_length, utb shortbase, u32 privateKeyLength,
 *                ut_mblk *output);
 * Description: The dh_generate_sharedparams_pkcs3() function uses a supplied prng
 *              to generate a modulus and base. The length of the
 *              modulus (in bits) is supplied in mod_length. If
 *              shortbase == UT_TRUE the generated base is one byte long
 *              (but greater than 8); if shortbase == UT_FALSE it is any
 *              value up to the value of the modulus. The parameters are
 *              returned as a BER-encoded string (formatted according to
 *              PKCS #3) in output->data. PrivateKeyLength is the length
 *              of the private key, which can be included in the
 *              parameter list according to PKCS #3; if privateKeyLength
 *              == 0 it is not included.
 * Returns:     This function returns 0 on success or -1 on failure.
 * Memory:      Dispose of the memory allocated by this function
 *              as follows:
 *           (code)
 *              ut_dispose_mem(output->data);
 *           (/code)
 */
extern int 
CST32EXPORTTYPE CST16EXPORTTYPE
dh_generate_sharedparams_pkcs3(prng_inst *prng, u32 mod_length, utb shortbase, 
    u32 privateKeyLength, ut_mblk *output);


/* Function:    <dh_generate_key_pkcs3>
 * Summary:     Generate a Diffie-Hellman keypair from PKCS#3-type parameters.
 * Syntax:      int rval = dh_generate_key_pkcs3(prng_inst *prng, ut_mblk
 *                *param, ut_mblk *privblk, ut_mblk *pubblk);
 * Description: The dh_generate_key_pkcs3() function, given a prng, and the
 *              parameters p and g (and optionally privateKeyLength) as
 *              a BER-encoded string within param, generates a private
 *              key and return it as a BER-encoded INTEGER in privblk,
 *              and generates a public key and return it as a
 *              BER-encoded INTEGER in pubblk. The private key is
 *              privateKeyLength bits long, if privateKeyLength was
 *              supplied in param, or a random number less than p
 *              otherwise. The public key is (g ^ priv) mod p.
 * Returns:     This function returns 0 on success or -1 on failure.
 * Memory:      Dispose of the memory allocated by this function
 *              as follows:
 *           (code)
 *              ut_dispose_mem(privblk->data);
 *              ut_dispose_mem(pubblk->data);
 *           (/code)
 */
extern int 
CST32EXPORTTYPE CST16EXPORTTYPE
dh_generate_key_pkcs3(prng_inst *, ut_mblk *, ut_mblk *, ut_mblk *);

/* Function:    <dh_derive_shared_pkcs3>
 * Summary:     Derive PKCS#3-style Diffie-Hellman shared public key.
 * Syntax:      int rval = dh_derive_shared_pkcs3(ut_mblk *param, 
 *                ut_mblk *pub, ut_mblk *priv, ut_mblk *shared);
 * Description: The dh_derive_shared_pkcs3() function derives the shared
 *              value for pub and priv using the parameters param. The
 *              result is returned in shared. The result is (pub ^ priv)
 *              mod p, p the prime that defines the group. To put this
 *              in a standard format, we:
 *              - convert the integer [(pub ^ priv) mod p] to an octet
 *                string such that the most significant byte of the
 *                octet string is the most significant byte of the
 *                integer;
 *              - if the length of this is less than the number of
 *                octets needed to represent p as an octet string, we
 *                prepend 0s until the string is the desired length.
 * Returns:     This function returns 0 on success, and -1 on failure.
 * Memory:      Dispose of the memory allocated by this function
 *              as follows:
 *           (code)
 *              ut_dispose_mem(shared->data);
 *           (/code)
 */
extern int 
CST32EXPORTTYPE CST16EXPORTTYPE
dh_derive_shared_pkcs3(ut_mblk *, ut_mblk *, ut_mblk *, ut_mblk *);

/* Function:    <dh_generate_sharedparams_x942>
 * Summary:     Generate parameters for X9.42 Diffie-Hellman
 * Syntax:      int rval = dh_generate_sharedparams_x942(prng_inst *prng, u32
 *                p_length, u32 q_length, ut_mblk *output);
 * Description: The dh_generate_sharedparams_x942() function uses the supplied prng
 *              to generate a modulus and base. The length of the
 *              modulus (in bits) is supplied in p_length. The modulus p
 *              satisfies p = jq + 1, where q is a prime of length
 *              q_length. The parameters are returned as a BER-encoded
 *              string (formatted according to ANSI X9.42) in
 *              output->data.
 * Returns:     This function returns 0 on success or -1 on failure.
 * Memory:      Dispose of the memory allocated by this function
 *              as follows:
 *           (code)
 *              ut_dispose_mem(output->data);
 *           (/code)
 */
int
CST32EXPORTTYPE CST16EXPORTTYPE
dh_generate_sharedparams_x942(prng_inst *prng, u32 p_length, u32 q_length,
    ut_mblk *output);

/* Function:    <dh_generate_key_x942>
 * Summary:     Generate a Diffie-Hellman keypair from X9.42-type parameters.
 * Syntax:      int rval = dh_generate_key_x942(prng_inst *prng, ut_mblk
 *                *param, ut_mblk *privblk, ut_mblk *pubblk);
 * Description: The dh_generate_key_x942() function, given a prng, and p, q
 *              and g as a BER-encoded string within param, generates a
 *              private key and return it as a BER-encoded * INTEGER in
 *              privblk, and generates a public key and return it as a *
 *              BER-encoded INTEGER in pubblk. The private key is less
 *              than q; the public key is (g ^ priv) mod p.
 * Returns:     This function returns 0 on success or -1 on failure.
 * Memory:      Dispose of the memory allocated by this function
 *              as follows:
 *           (code)
 *              ut_dispose_mem(privblk->data);
 *              ut_dispose_mem(pubblk->data);
 *           (/code)
 * Notes:       This function can also handle the case where the params
 *              include j.
 */
int
CST32EXPORTTYPE CST16EXPORTTYPE
dh_generate_key_x942(prng_inst *prng, ut_mblk *param, ut_mblk *privblk, 
    ut_mblk *pubblk);


/* Function:    <dh_derive_shared_x942>
 * Summary:     Derive X9.42-style Diffie-Hellman shared public key.
 * Syntax:      int rval = dh_derive_shared_x942(ut_mblk *param, 
 *                ut_mblk *pub, ut_mblk *priv, ut_mblk *shared);
 * Description: The dh_derive_shared_x942() function derives the shared
 *              value for pub and priv using the parameters param. The
 *              result is returned in shared. The result is (pub ^ priv)
 *              mod p, p the prime that defines the group. To put this
 *              in a standard format, we:
 *              - convert the integer [(pub ^ priv) mod p] to an octet
 *                string such that the most significant byte of the
 *                octet string is the most significant byte of the
 *                integer;
 *              - if the length of this is less than the number of
 *                octets needed to represent p as an octet string, we
 *                prepend 0s until the string is the desired length.
 * Returns:     This function returns 0 on success, and -1 on failure.
 * Memory:      Dispose of the memory allocated by this function
 *              as follows:
 *           (code)
 *              ut_dispose_mem(shared->data);
 *           (/code)
 * Notes:       This function can also handle the case where the params
 *              include j.
 */
extern int 
CST32EXPORTTYPE CST16EXPORTTYPE
dh_derive_shared_x942(ut_mblk *param, ut_mblk *pub, ut_mblk *priv,
    ut_mblk *shared);

/*
 * Utility functions:
 */

/* Function:    <dh_merge_priv_and_params>
 * Summary:     Put private key and shared parameters in one place.
 * Description: This function is deprecated. To store Diffie-Hellman
 *              private keys, use pkcs8_encrypt() or 
 *              pkcs12_simpleobj_create().
 */

extern int
dh_merge_priv_and_params(ut_mblk *priv, ut_mblk *params, ut_mblk *dest);



/* Function:    <dh_separate_priv_and_params>
 * Summary:     Break up private key and shared parameters
 * Description: This function is deprecated. To read Diffie-Hellman
 *              private keys, use pkcs8_decrypt() or 
 *              pkcs12_obj_simpleobj2data().
 */

extern int
dh_separate_priv_and_params(ut_mblk *src, ut_mblk *priv, ut_mblk *params);

#ifdef __cplusplus
}
#endif 


#endif  /* def WITH_dh_dh  */

#endif /* not _DH_H */
