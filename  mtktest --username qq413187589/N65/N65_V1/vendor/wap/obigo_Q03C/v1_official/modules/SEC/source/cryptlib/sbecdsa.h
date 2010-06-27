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

#ifndef __SB_ECDSA_H
#define __SB_ECDSA_H

#include "sbeccom.h"

/* SB EC DSA */
#ifdef __cplusplus
extern "C" {
#endif

extern int CST32EXPORTTYPE CST16EXPORTTYPE
bsapi_generate_sharedparams_sb_ecdsa
(prng_inst *prng, ut_mblk *shrdpt, bsapi_kparam *param);

extern int CST32EXPORTTYPE CST16EXPORTTYPE
bsapi_generate_key_sb_ecdsa
(prng_inst *prng, ut_mblk *pript, ut_mblk *pubpt, bsapi_kparam *param);

extern int CST32EXPORTTYPE CST16EXPORTTYPE
bsapi_generate_privatenonce_sb_ecdsa
(prng_inst *rand_gen, ut_mblk *pnonce, bsapi_kparam *param);

extern size_t CST32EXPORTTYPE CST16EXPORTTYPE
bsapi_sizeof_iv_sb_ecdsa
(bsapi_mode *mode, bsapi_kset *keys);

extern bsapi_id CST32EXPORTTYPE CST16EXPORTTYPE
bsapi_start_sb_ecdsa
(bsapi_mode *mode, prng_inst *prngpt, bsapi_kset *keys);

extern sec_off_t CST32EXPORTTYPE CST16EXPORTTYPE
bsapi_sizeof_output_sb_ecdsa
(bsapi_id session, sec_off_t input);

extern int CST32EXPORTTYPE CST16EXPORTTYPE
bsapi_append_sb_ecdsa
(u8 *data, size_t length, bsapi_id session);

extern ut_mblk_list CST32EXPORTTYPE CST16EXPORTTYPE
bsapi_read_sb_ecdsa
(bsapi_id session);

extern ut_mblk_list CST32EXPORTTYPE CST16EXPORTTYPE
bsapi_readmost_sb_ecdsa
(bsapi_id session);

extern void CST32EXPORTTYPE CST16EXPORTTYPE
bsapi_kill_sb_ecdsa
(bsapi_id session);

extern int CST32EXPORTTYPE CST16EXPORTTYPE
bsapi_finish_sb_ecdsa
(bsapi_id session, ut_mblk_list *data);

extern void CST32EXPORTTYPE CST16EXPORTTYPE
sb_ecdsa_direct
(bsapi_id session, u8 *in, u8 *out, size_t len);

extern const char CST32EXPORTTYPE * CST16EXPORTTYPE
bsapi_get_name_sb_ecdsa
(void);

extern const bsapi_alg CST32EXPORTDATA CST16EXPORTDATA bsapi_sb_ecdsa;

extern sec_off_t
algid_sz_to_sb_ecdsa_params
(void *p);

extern u8 *
algid_to_sb_ecdsa_params
(void *p, u8 *d);

extern u8 *
algid_from_sb_ecdsa_params
(u8 *s, void **p);

extern void
algid_dispose_sb_ecdsa_params
(void *p);

extern void *
algid_copy_sb_ecdsa_params
(void *p);

extern void *
algid_pgen_sb_ecdsa
(prng_inst *prng);

extern sec_off_t
algid_sz_to_certicom_ecdsa_params
(void *p);

extern u8 *
algid_to_certicom_ecdsa_params
(void *p, u8 *d);

extern u8 *
algid_from_certicom_ecdsa_params_ec131a01
(u8 *s, void **p);

extern u8 *
algid_from_certicom_ecdsa_params_ec163a01
(u8 *s, void **p);

extern u8 *
algid_from_certicom_ecdsa_params_ec239a01
(u8 *s, void **p);

extern u8 *
algid_from_certicom_ecdsa_params_ec131b01
(u8 *s, void **p);

extern u8 *
algid_from_certicom_ecdsa_params_ec155b01
(u8 *s, void **p);

extern u8 *
algid_from_certicom_ecdsa_params_ec163b01
(u8 *s, void **p);

extern u8 *
algid_from_certicom_ecdsa_params_ec191b01
(u8 *s, void **p);

extern u8 *
algid_from_certicom_ecdsa_params_ec210b01
(u8 *s, void **p);

extern u8 *
algid_from_certicom_ecdsa_params_ec239b01
(u8 *s, void **p);

extern void
algid_dispose_certicom_ecdsa_params
(void *p);

extern void *
algid_copy_certicom_ecdsa_params
(void *p);

extern void *
algid_pgen_certicom_ecdsa
(prng_inst *prng);

extern const u32 *
algid_sb_ecdsa_get_oid_from_params
(void *p);

#ifdef __cplusplus
}
#endif

#endif /* __SB_ECDSA_H */
