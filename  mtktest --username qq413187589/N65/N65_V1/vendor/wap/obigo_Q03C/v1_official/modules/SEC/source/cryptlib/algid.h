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

#ifndef _CST_ALGID_H /* Prevent multiple inclusion */
#define _CST_ALGID_H

/*
 * Includes
 */

/*loko#include "stdlib.h"*/  /* For size_t */
/*Removed by ANAO 29/3-2001 #include "time.h"*/   /* For struct tm & time_t */

#include "cstopt.h" /* For CSTxxEXPORTxxxx and WITH_xxxx defines. */
#include "ut.h"     /* For u32, ut_mblk, u8, & utb */
#include "prng.h"
#include "bsapi.h"
#include "hash.h"
#include "bstypes.h" 
/*loko#include "string.h"

#ifdef __cplusplus
extern "C" {
#endif*/  /* __cplusplus */

/*
 * Errors
 */

#define ALGID_EBASE (0x01000000) /* Module code */

#define ALGID_ENOMEM (ALGID_EBASE + 0x40000) /* Unable to allocate %d bytes" */
#define ALGID_ECERTF (ALGID_EBASE + 0x40100) /* Unable to allocate certificate */
#define ALGID_ECOPYF (ALGID_EBASE + 0x40200) /* Unable to copy %s */
#define ALGID_ESETFL (ALGID_EBASE + 0x40300) /* Unable to set %s */
#define ALGID_EA1ERR (ALGID_EBASE + 0x40400) /* ASN.1 error:     %s */
#define ALGID_EKGENF (ALGID_EBASE + 0x40600) /* Unable to generate keys */
#define ALGID_EHASHF (ALGID_EBASE + 0x40700) /* Unable to hash certificate */
#define ALGID_ESIGNF (ALGID_EBASE + 0x40800) /* Unable to sign certificate */
#define ALGID_EVRFYF (ALGID_EBASE + 0x40900) /* Unable to verify certificate */
#define ALGID_EOPENF (ALGID_EBASE + 0x40a00) /* Unable to open file %s */
#define ALGID_EREADF (ALGID_EBASE + 0x40b00) /* Unable to read file %s */
#define ALGID_EWRITE (ALGID_EBASE + 0x40c00) /* Unable to write file %s */
#define ALGID_EPARAM (ALGID_EBASE + 0x40d00) /* FAIL/ABORT Bad parameters */
#define ALGID_EBADOB (ALGID_EBASE + 0x40e00) /* Unrecognised object */
#define ALGID_EBADEX (ALGID_EBASE + 0x40f00) /* Bad extension */
#define ALGID_EUNEXT (ALGID_EBASE + 0x41000) /* unknown extension */
#define ALGID_ETIME  (ALGID_EBASE + 0x41100) /* trouble with time conversions */


/* Type:        <algid_objid>
 * Summary:     Object Identifier (OID) field
 * Description: The first u32 is the number of u32s that make up the actual 
 *              OID. The second u32 is 1 if the memory holding the OID should
 *              be disposed of, 0 otherwise. The remaining values give the OID.
 */
typedef u32 * algid_objid;

/* Type:        <algid_encpara>
 * Summary:     Structure for holding the parameter details of an algorithm
 *              identifier
 */
typedef struct algid_encpara_s algid_encpara;

struct algid_encpara_s {
  bsapi_kparam  kparam;           /* e.g. DES_NOEIGHTS */
  bsapi_kset    kset;             /* skeleton key set */
  bsapi_mode    mode;             /* most useful for ECB v CBC */
  void         *xtra;             /* extra parameters */
};                                

/* Type:        <algid_algs>
 * Summary:     Structure for holding the function pointers associated with an OID
 */
typedef struct {                  /* used to pass a set of alg info around. */
  const bsapi_alg *enc;
  u32 *enc_oid;
  const hash_alg *hash;
  u32 *hash_oid;
  void (*dispose)(void *);        /* free these parameters */
  sec_off_t (*sz_to)(void *);         /* size of BER-encoded algorithm params */
/*  off_t (*sz_to)(void *);*/         /* size of BER-encoded algorithm params */
  u8 *(*to)(void *, u8 *);        /* BER-encode algorithm parameters */
  u8 *(*from)(u8 *, void **);     /* BER-decode algorithm parameters */
  void *(*copy)(void *);          /* copy the parameters */
  void *(*para_gen)(prng_inst *); /* auto-generate params if possible */
  const char *name;
} algid_algs;

/* Type:        <algid_algid>
 * Summary:     Structure for writing and reading algorithm identifiers
 */
typedef struct algid_algid_t {
  u32              *oid;   /* not const; comes from berobjid2objid sometimes */
  void             *params;
  const algid_algs *proc;  /* saves looking up more than once */
} algid_algid;

typedef struct {
  algid_algid owf;		/* the hash function to use */
  algid_algid mac;		/* the actual mac function to feed */
} algid_xtrapara_pbm;


/* Type:        <aid_ent>
 * Summary:     Lookup table which is used in internal functions. Published
 *              because it can be used to get a list of OID-name pairs.
 */
typedef struct {
  u32 *oid;
  const algid_algs *alg;
} aid_ent;

extern const aid_ent *aid_tab;

/* Function:    <sizeof_aid_tab>
 * Summary:     Gives size of aid_tab.
 * Syntax:      size_t rval = sizeof_aid_tab();
 * Notes:       Divide by sizeof(aid_ent) to get number of entries.
 */
extern size_t sizeof_aid_tab(void);

#define _new_obj(o) {(o)=ut_new_mem(sizeof(*(o)));memset((o),0,sizeof(*(o)));}


/* Object identifiers for RSA, with and without hash functions
 */

#ifdef WITH_bsapi_rsa
#ifdef WITH_hash_md2
  extern u32 CST32EXPORTDATA CST16EXPORTDATA 
    algid_rsa_md2rsa[]; /* md2withRSA */
#endif /* def WITH_hash_md2 */
#ifdef WITH_hash_md5
  extern u32 CST32EXPORTDATA CST16EXPORTDATA 
    algid_rsa_md5rsa[]; /* md5withRSA */
#endif /* def WITH_hash_md5 */
  extern u32 CST32EXPORTDATA CST16EXPORTDATA 
    algid_x509_rsa[]; /* rsa enc (X.509 style) */
#ifdef WITH_hash_ripemd
  extern u32 CST32EXPORTDATA CST16EXPORTDATA 
    algid_balt_rsaripe[]; /* rsa + ripemd */
#endif /* def WITH_hash_ripemd */
#ifdef WITH_hash_mdc2
  extern u32 CST32EXPORTDATA CST16EXPORTDATA 
    algid_balt_rsasmdc2[]; /* rsa + smdc2 */
  extern u32 CST32EXPORTDATA CST16EXPORTDATA 
    algid_balt_rsadmdc2[]; /* rsa + dmdc2 */
#endif /* def WITH_hash_mdc2 */
#ifdef WITH_hash_sha
  extern u32 CST32EXPORTDATA CST16EXPORTDATA 
    algid_rsa_sha1rsa[]; /* sha1withRSA */
#endif /* def WITH_hash_sha */
  extern u32 CST32EXPORTDATA CST16EXPORTDATA 
    algid_rsa_rsa[]; /* rsa enc */
#ifdef WITH_pad_oaeppkcs
  extern u32 CST32EXPORTDATA CST16EXPORTDATA 
    algid_rsa_rsaes_oaep[]; /* rsa enc with OAEP */
  extern u32 CST32EXPORTDATA CST16EXPORTDATA 
    algid_rsa_mgf1[]; /* MGF1 mask generation */
  extern u32 CST32EXPORTDATA CST16EXPORTDATA 
    algid_rsa_pSpecified[]; /* encoding parameters are specified */
#endif  /* def WITH_pad_oaeppkcs */
#ifdef WITH_pad_pkcs1
  extern u32 CST32EXPORTDATA CST16EXPORTDATA 
    algid_pkcs1_rsa[]; /* RSA with PKCS#1 padding */
#endif /* def WITH_pad_pkcs1 */
#endif  /* def WITH_bsapi_rsa */

/* Object identifiers for DSA
 */

#ifdef WITH_bsapi_dsa
  extern u32 CST32EXPORTDATA CST16EXPORTDATA algid_dsa[];
  extern u32 CST32EXPORTDATA CST16EXPORTDATA algid_ansi_dsa[];
  extern u32 CST32EXPORTDATA CST16EXPORTDATA algid_ansi_dsa_sha1[];
  extern u32 CST32EXPORTDATA CST16EXPORTDATA algid_dsa_sha1[];
#endif /* def WITH_bsapi_dsa */

/* Object identifiers for Diffie-Hellman
 */

#ifdef WITH_dh_dh
  extern u32 CST32EXPORTDATA CST16EXPORTDATA 
    algid_dhKeyAg[]; /* dhKeyAgreement as defined in PKCS#3 */
  extern u32 CST32EXPORTDATA CST16EXPORTDATA 
    algid_ansi_x942dhPubKey[]; /* ANSI x9.42 D-H OID: 1, 2, 840, 10046, 2 */
#endif /* def WITH_dh_dh */

#ifdef WITH_sb_ecdsa
/* Object identifiers for ECDSA using Certicom's Security Builder
 */

  extern u32 CST32EXPORTDATA CST16EXPORTDATA algid_ansi_ecdsa_sha1[];
  extern u32 CST32EXPORTDATA CST16EXPORTDATA algid_ansi_ecdsa[];
  extern u32 CST32EXPORTDATA CST16EXPORTDATA algid_certicom_ecdsa_sha1[];
  extern u32 CST32EXPORTDATA CST16EXPORTDATA algid_certicom_ecdsa_ec131a01[];
  extern u32 CST32EXPORTDATA CST16EXPORTDATA algid_certicom_ecdsa_ec163a01[];
  extern u32 CST32EXPORTDATA CST16EXPORTDATA algid_certicom_ecdsa_ec239a01[];
  extern u32 CST32EXPORTDATA CST16EXPORTDATA algid_certicom_ecdsa_ec131b01[];
  extern u32 CST32EXPORTDATA CST16EXPORTDATA 
    algid_certicom_ecdsa_ec155b01[];/* 155b01 decommissioned */
  extern u32 CST32EXPORTDATA CST16EXPORTDATA algid_certicom_ecdsa_ec163b01[];
  extern u32 CST32EXPORTDATA CST16EXPORTDATA algid_certicom_ecdsa_ec191b01[];
  extern u32 CST32EXPORTDATA CST16EXPORTDATA 
    algid_certicom_ecdsa_ec210b01[];/* 210b01 decommissioned */
  extern u32 CST32EXPORTDATA CST16EXPORTDATA 
    algid_certicom_ecdsa_ec239b01[];/* To find: 113a01 163a02 239a02 239a03 163b02 160p01 192p01 */
  

#endif /* WITH_sb_ecdsa */

/* Object identifiers for symmetric encryption algorithms
 */

#ifdef WITH_bsapi_des
  extern u32 CST32EXPORTDATA CST16EXPORTDATA 
    algid_ansi_descbc[]; /* Des CBC */
  extern u32 CST32EXPORTDATA CST16EXPORTDATA 
    algid_rsa_desede3cbc[]; /* Des EDE3 CBC */
  extern u32 CST32EXPORTDATA CST16EXPORTDATA
    algid_ansi_x942_des[];   /* {6, 0, 1, 2, 840, 10046, 1, 1}; Des */
  extern u32 CST32EXPORTDATA CST16EXPORTDATA
    algid_ansi_x942_3des[];  /* {6, 0, 1, 2, 840, 10046, 1, 2}; Des EDE3 */
  extern u32 CST32EXPORTDATA CST16EXPORTDATA 
    algid_teletrust_des3ecb_pad[]; /* {8, 0, 1, 3, 36, 3, 1, 3, 1, 1}  */                            
  extern u32 CST32EXPORTDATA CST16EXPORTDATA 
    algid_teletrust_desecb_pad[];  /* {7, 0, 1, 3, 36, 3, 1, 1, 1}  */                            
#endif /* def WITH_bsapi_des */

#ifdef WITH_bsapi_rc2
  extern u32 CST32EXPORTDATA CST16EXPORTDATA 
    algid_rsa_rc2cbc[];     /* RC2 enc */
#endif /* def WITH_bsapi_rc2 */
#ifdef WITH_bsapi_rc4
  extern u32 CST32EXPORTDATA CST16EXPORTDATA
    algid_rsa_rc4[];  /* {6, 0, 1, 2, 840, 113549, 3, 4} */
#endif /* def WITH_bsapi_rc4 */
#ifdef WITH_bsapi_rc5
  extern u32 CST32EXPORTDATA CST16EXPORTDATA 
    algid_rsa_rc5cbc[];  /* {6, 0, 1, 2, 840, 113549, 3, 8};  RC5 CBC */    
  extern u32 CST32EXPORTDATA CST16EXPORTDATA 
    algid_rsa_rc5cbc_pad[];/* {6, 0, 1, 2, 840, 113549, 3, 9};  RC5 CBC PAD */    
#endif /* def WITH_bsapi_rc5 */

#ifdef WITH_bsapi_idea
  extern u32 CST32EXPORTDATA CST16EXPORTDATA 
    algid_ascom_ideaecb[];/* {11, 0, 1, 3, 6, 1, 4, 1, 188, 7, 1, 1, 1}; IDEA ECB */    
  extern u32 CST32EXPORTDATA CST16EXPORTDATA 
    algid_ascom_ideacbc[];/* {11, 0, 1, 3, 6, 1, 4, 1, 188, 7, 1, 1, 2}; IDEA CBC */    
#endif /* WITH_bsapi_idea */

/* Object identifiers for hash algorithms
 */

#ifdef WITH_hash_md2
  extern u32 CST32EXPORTDATA CST16EXPORTDATA 
    algid_rsa_md2[]; /* md2 */
#endif /* def WITH_hash_md2 */
#ifdef WITH_hash_md5
  extern u32 CST32EXPORTDATA CST16EXPORTDATA 
    algid_rsa_md5[]; /* md5 */
#endif /* def WITH_hash_md5 */
#ifdef WITH_hash_ripemd
  extern u32 CST32EXPORTDATA CST16EXPORTDATA 
    algid_balt_ripe[]; /* ripemd */
#endif /* def WITH_hash_ripemd */
#ifdef WITH_hash_mdc2
  extern u32 CST32EXPORTDATA CST16EXPORTDATA 
    algid_balt_smdc2[]; /* smdc2 */
  extern u32 CST32EXPORTDATA CST16EXPORTDATA 
    algid_balt_dmdc2[]; /* dmdc2 */
#endif /* def WITH_hash_mdc2 */
#ifdef WITH_hash_sha
  extern u32 CST32EXPORTDATA CST16EXPORTDATA 
    algid_ansi_sha1[]; /* ANSI label of sha1 */
#endif /* def WITH_hash_sha */

/* Object identifiers for passphrase-based encryption algorithms 
 */
  extern u32 CST32EXPORTDATA CST16EXPORTDATA
    algid_pkcs12[];
  extern u32 CST32EXPORTDATA CST16EXPORTDATA
    algid_pkcs12_pbeIds[];
  extern u32 CST32EXPORTDATA CST16EXPORTDATA
    algid_pkcs12_pbeWithSHAAnd128BitRC4[];
  extern u32 CST32EXPORTDATA CST16EXPORTDATA
    algid_pkcs12_pbeWithSHAAnd40BitRC4[];
  extern u32 CST32EXPORTDATA CST16EXPORTDATA
    algid_pkcs12_pbeWithSHAAnd3_KeyTripleDES_CBC[];
  extern u32 CST32EXPORTDATA CST16EXPORTDATA
    algid_pkcs12_pbeWithSHAAnd2_KeyTripleDES_CBC[];
  extern u32 CST32EXPORTDATA CST16EXPORTDATA
    algid_pkcs12_pbeWithSHAAnd128BitRC2_CBC[];
  extern u32 CST32EXPORTDATA CST16EXPORTDATA
    algid_pkcs12_pbeWithSHAAnd40BitRC2_CBC[];
  extern u32 CST32EXPORTDATA CST16EXPORTDATA
    algid_pkcs5_pbeWithMD5AndDES_CBC[];

/* Incorrect algids for backward compatibility */
  extern u32 CST32EXPORTDATA CST16EXPORTDATA
    algid_pkcs12_pbeWithSHAAnd128BitRC4_wrong[];
  extern u32 CST32EXPORTDATA CST16EXPORTDATA
    algid_pkcs12_pbeWithSHAAnd40BitRC4_wrong[];
  extern u32 CST32EXPORTDATA CST16EXPORTDATA
    algid_pkcs12_pbeWithSHAAnd3_KeyTripleDES_CBC_wrong[];
  extern u32 CST32EXPORTDATA CST16EXPORTDATA
    algid_pkcs12_pbeWithSHAAnd2_KeyTripleDES_CBC_wrong[];
  extern u32 CST32EXPORTDATA CST16EXPORTDATA
    algid_pkcs12_pbeWithSHAAnd128BitRC2_CBC_wrong[];
  extern u32 CST32EXPORTDATA CST16EXPORTDATA
    algid_pkcs12_pbeWithSHAAnd40BitRC2_CBC_wrong[];

/* Object identifiers for PKCS#7 message types
 */
  extern u32 CST32EXPORTDATA CST16EXPORTDATA
    algid_pkcs7[];  /* root ID */
  extern u32 CST32EXPORTDATA CST16EXPORTDATA
    algid_pkcs7_data[];  /* plain DATA type */
  extern u32 CST32EXPORTDATA CST16EXPORTDATA
    algid_pkcs7_signed[];  /* plain DATA type */
  extern u32 CST32EXPORTDATA CST16EXPORTDATA
    algid_pkcs7_enveloped[];  /* plain DATA type */
  extern u32 CST32EXPORTDATA CST16EXPORTDATA
    algid_pkcs7_digested[];  /* plain DATA type */
  extern u32 CST32EXPORTDATA CST16EXPORTDATA
    algid_pkcs7_encrypted[];  /* plain DATA type */

/* Object identifiers for Message Authentication Codes (MACs)
 */

extern u32 algid_entrust_pbmac[];
extern u32 algid_hmac_sha1[];
extern u32 algid_mac_des[];



/*
 * By and large we recommend implementing the algid_oid2alg() function to
 * determine which algid to use. These are provided because they feature in 
 * lookup tables that are commonly used in other Baltimore toolkits.
 */

extern algid_algid algid_alg_rsa_md5;
extern algid_algid algid_alg_rsa_sha1;
extern algid_algid algid_alg_dsa_sha1;
extern algid_algid algid_alg_sb_ecdsa_sha1;


/* Function:    <algid_new_algid>
 * Summary:     Creates a new algid_algid object based on the given object
 *              identifier (OID).
 * Syntax:      algid_algid rval = algid_new_algid(algid_objid oid,
 *                prng_inst *prng);
 * Description: The algid_new_algid() function fills in an algid_algid
 *              object. Internally, it calls algid_oid2alg(oid) to get
 *              the function set associated with oid, and then calls
 *              the para_gen function from that function set. prng is
 *              the random number generator that you use to generate
 *              the algorithm parameters. 
 *
 *              Parameters are generated for the following algorithms.
 *
 *              DES-CBC, RC2_CBC, Triple DES-EDE-CBC (corresponding to
 *              oid = algid_ansi_descbc, algid_rsa_desede3cbc,
 *              algid_rsa_rc2cbc respectively):   
 *              - rval.params->kset.padalg = &pad_pkcs5;
 *              - rval.params->kset.iv is filled with an eight-byte
 *                random array.
 *              - (for DES and Triple DES) rval.params->kparam.des.security 
 *                = DES_NOEIGHTS;
 *
 *              All PBE algorithms (algid_pkcs12_pbeWithSHAAnd128BitRC4,
 *              algid_pkcs12_pbeWithSHAAnd40BitRC4,
 *              algid_pkcs12_pbeWithSHAAnd3_KeyTripleDES_CBC,
 *              algid_pkcs12_pbeWithSHAAnd2_KeyTripleDES_CBC,
 *              algid_pkcs12_pbeWithSHAAnd128BitRC2_CBC,
 *              algid_pkcs12_pbeWithSHAAnd40BitRC2_CBC,
 *              algid_pkcs5_pbeWithMD5AndDES_CBC):   Fills in a pbe_params
 *              structure with 20 (for SHA-1) or 16 (for MD5) bytes of
 *              salt, and an iteration count randomly chosen in the
 *              range (1000, 1255).
 *
 *              The function returns a filled algid_algid structure. If
 *              the OID was not recognized, algid.proc contains a
 *              pointer to a generic algid_algs structure that correctly
 *              converts the algid_algid object to a BER-encoded
 *              algorithm identifier with the given OID and a NULL
 *              parameters field. This behavior is inherited from
 *              algid_oid2alg().
 * Memory:      Dispose of the algid created with algid_dispose_algid().             
 * Errors:      If the OID is null, or we ran out of memory on the call to
 *              algid_copy_algid, algid_new_algid() returns an algid_algid 
 *              object with all fields set to NULL.
 * Notes:       Since parameters are public quantities, they can safely
 *              be generated with a fast prng such as prng_lcg (see
 *              prng_create_lcg for more details).
 */
extern algid_algid algid_new_algid(algid_objid oid, prng_inst *prng);

/* Function:    <algid_copy_algid>
 * Summary:     Copies an algid_algid object.
 * Syntax:      algid_algid rval = algid_copy_algid(algid_algid src);
 * Description: The algid_copy_algid function copies src to rval.
 * Returns:     A filled algid_algid structure. If src.oid is non-null
 *              and src.proc is null, algid_copy_algid calls
 *              algid_oid2alg to fill in the proc field in the copy.
 * Memory:      Dispose of the copy created with algid_dispose_algid().
 * Errors:      The function will fail if there are parameters and it can't
 *              allocate space for them, or if it runs out of memory attempting
 *              to copy src.oid. In the case of failure, it returns an
 *              algid_algid with all fields set to NULL.
 */
extern algid_algid CST32EXPORTTYPE CST16EXPORTTYPE
algid_copy_algid(algid_algid src);

/* Function:    <algid_dispose_algid>
 * Summary:     Disposes of dynamic memory in an algid_algid.
 * Syntax:      algid_dispose_algid(algid_algid aid);
 * Description: The algid_dispose_algid() function disposes of all 
 *              dynamically allocated memory in aid. If the memory for
 *              aid itself was explicitly allocated with ut_new_mem,
 *              dispose of it using ut_dispose_mem.
 * Memory:      This function allocates no memory.
 */
extern void CST32EXPORTTYPE CST16EXPORTTYPE
algid_dispose_algid(algid_algid aid);

/* Function:    <algid_cmp_algid>
 * Summary:     Compares two algid_algids.
 * Syntax:      utb cval = algid_cmp_algid(algid_algid first,
 *                algid_algid second);
 * Description: The algid_cmp_algid() function compares two algid_algid
 *              objects. The result is UT_TRUE if algids have same
 *              object identifiers and same parameters, UT_FALSE
 *              otherwise. The objids are compared, subidentifier by
 *              subidentifier. The parameters are compared in a context-
 *              specific manner determined by the OIDs.
 * Returns:     The function returns UT_TRUE if the algids are the same, 
 *              UT_FALSE if they differ.
 * Memory:      This function allocates no memory.
 * Notes:       In many cases, it is more sensible to call
 *              algid_cmp_objid (first.oid, second.oid) first.
 */
extern utb CST32EXPORTTYPE CST16EXPORTTYPE
algid_cmp_algid(const algid_algid, const algid_algid);

/* Function:    <algid_sizeof_aid2beraid>
 * Summary:     Gives memory needed to write DER-encoded algorithm identifier.
 * Syntax:      off_t size = algid_sizeof_aid2beraid(algid_algid aid);
 * Description: The algid_sizeof_ai2beraid() function returns the amount
 *              of memory needed to write the full DER encoding of aid.
 *              The algid_algid object is encoded as ASN.1 type
 *              AlgorithmIdentifier (SEQUENCE of OBJECT IDENTIFIER and
 *              parameters). If aid.proc is not filled in, the function
 *              fills it in by calling algid_oid2alg(aid.oid). This can
 *              result in unexpected behavior if the OID is not
 *              recognized.
 * Returns:     The function returns the amount of memory needed to write out 
 *              the DER encoding of aid.
 * Memory:      This function allocates no memory.
 */
extern sec_off_t CST32EXPORTTYPE CST16EXPORTTYPE
algid_sizeof_aid2beraid(algid_algid aid);

/* Function:    <algid_aid2beraid>
 * Summary:     DER-encodes an algorithm identifier.
 * Syntax:      u8 *dest = algid_aid2beraid(algid_algid aid, u8 *dest);
 * Description: The algid_aid2beraid() function takes an algid_algid structure,
 *              aid, DER-encodes it, and writes the output to dest. At least
 *              algid_sizeof_aid2beraid(aid) octets of memory must
 *              already have been allocated at dest.
 * Returns:     The function returns 0 on failure and a pointer to the octet
 *              after the last octet written on success. It fails only if
 *              there's an internal failure in algid_objid2berobjid().
 * Memory:      This function allocates no memory.
 */
extern u8 CST32EXPORTTYPE * CST16EXPORTTYPE
algid_aid2beraid(algid_algid aid, u8 *dest);

/* Function:    <algid_beraid2aid>
 * Summary:     Decodes a DER-encoded algorithm identifier.
 * Syntax:      src = algid_beraid2aid(src, (algid_algid *) &targ);
 * Description: The algid_beraid2aid() function converts the DER-encoded
 *              ASN.1 algorithm identifier in src to an algid_algid
 *              structure in targ, calling algid_oid2alg(targ.oid) to
 *              fill in the function table. The parameters are decoded
 *              according to the resulting targ.proc->from() function.
 * Returns:     On success, returns a pointer to the octet after the last one 
 *              read. On failure (initial tag not SEQUENCE, next tag
 *              not OBJECT IDENTIFIER, couldn't allocate memory for
 *              targ.oid or couldn't parse parameters if they were
 *              expected to be present in the BER data),  returns 0.
 * Memory:      Dispose of targ with algid_dispose_algid(targ).
 * Notes:       It is possible to produce an incorrect DER-encoded
 *              byte array that will be correctly parsed by this
 *              function. In particular, if the parameters are encoded
 *              as an ASN.1 SEQUENCE, not all functions will check that
 *              the end of the last data field is aligned with the
 *              expected end of the sequence. This could lead to
 *              the next BER-decoding function giving an error.
 */
extern u8 CST32EXPORTTYPE * CST16EXPORTTYPE
algid_beraid2aid(u8 *src, algid_algid *targ);

/* Function:    <algid_oid2alg>
 * Summary:     Gets the function table associated with an object identifier.
 * Syntax:      algid_algs *algs = algid_oid2alg(algid_objid oid);
 * Description: The algid_oid2alg() function produces the
 *              algid_algs function table associated with the OBJECT
 *              IDENTIFIER oid. If the function does not recognise oid,
 *              it returns a default algid_algs table with:  
 *              - algs->enc = 0;
 *              - algs->hash = 0;
 *              - algs->hash_oid = 0;
 *              - algs->para_gen simply returns 0;
 *              - algs->sz_to, algs->to, algs->from provide functions
 *                that encode and decode the algorithm identifier
 *                as an oid with NULL parameters.
 *
 *              This behavior is so that a message containing a generic
 *              OID can be parsed even if the OID isn't recognised.
 * Returns:     An algid_algs structure containing the functions
 *              appropriate to the given algorithm.
 * Memory:      This function allocates no memory.
 * Notes:       It should never really be necessary to call this
 *              function directly; it's wrapped by algid_new_algid(),
 *              algid_copy_algid() and algid_beraid2aid().
 */
extern const algid_algs CST32EXPORTTYPE * CST16EXPORTTYPE
algid_oid2alg(algid_objid oid);

/* Function:    <algid_dispose_objid>
 * Summary:     Disposes of the memory associated with an algid_objid.
 * Syntax:      algid_dispose_objid(oid);
 * Description: The algid_dispose_objid() function ensures that oid is
 *              not using any dynamically allocated memory. If oid[1] = 0 
 *              (i.e. oid refers to a predefined static const
 *              algid_objid), it does nothing. Otherwise, it calls
 *              ut_dispose_mem(oid).
 * Returns:     This function returns no value.
 * Memory:      This function allocates no memory.
 */
extern void CST32EXPORTTYPE CST16EXPORTTYPE
algid_dispose_objid(algid_objid oid);

/* Function:    <algid_copy_objid>
 * Summary:     Copies an algid_objid.
 * Syntax:      algid_objid new_oid = algid_copy_objid(algid_objid oid);
 * Description: The algid_copy_objid() function copies oid to new_oid.
 *              If oid[1] == 1 (i.e. oid was dynamically allocated, for
 *              example by algid_berobjid2objid()), the function copies it 
 *              to new memory (allocating the memory); otherwise (i.e. oid 
 *              is one of the global static algid_objids declared above),
 *              it just returns a link to it.
 * Returns:     A pointer to the copy of oid on success or 0 on
 *              failure (due to null input, or to being given a
 *              malformed oid that requires the allocation of
 *              impossible amounts of memory).
 * Memory:      Dispose of new_oid with algid_dispose_objid(new_oid).
 */
extern algid_objid CST32EXPORTTYPE CST16EXPORTTYPE
algid_copy_objid(algid_objid oid);

/* Function:    <algid_cmp_objid>
 * Summary:     Compares two algid_objid's.
 * Syntax:      int result = algid_cmp_objid(algid_objid a,
                  algid_objid b);
 * Description: The algid_cmp_objid() function compares a and b to see
 *              which is greater. If a has a different number of entries
 *              from b, it compares the number of entries. Otherwise it
 *              compares on an entry by entry basis.
 * Returns:     The function returns 0 if a and b are the same; -1 if a < b; 
 *              1 if a > b.
 * Memory:      This function allocates no memory.
 * See also:    algid_cmp_algid.
 */
extern int CST32EXPORTTYPE CST16EXPORTTYPE
algid_cmp_objid(const u32 *, const u32 *);

/* Function:    <algid_sizeof_objid2berobjid>
 * Summary:     Gives the memory needed to write a DER-encoded object
 *              identifier.
 * Syntax:      off_t  len = algid_sizeof_objid2berobjid(algid_objid oid);
 * Description: The algid_sizeof_objid2berobjid() function takes oid, an 
 *              algid_objid array, and returns the number of
 *              octets of memory that must be allocated to store the
 *              DER-encoded OBJECT IDENTIFIER.
 * Returns:     The number of octets of memory needed to store the DER
 *              encoding of oid.
 * Memory:      This function allocates no memory.
 * Notes:       Note that if this function can't get the length of the
 *              algid_objid object, it returns 2 (the length of the
 *              DER-encoded data 06 00, which corresponds to a
 *              null-length object identifier).
 */
extern sec_off_t  CST32EXPORTTYPE CST16EXPORTTYPE
algid_sizeof_objid2berobjid(algid_objid oid);

/* Function:    <algid_objid2berobjid>
 * Summary:     DER-encodes an object identifier and writes it out.
 * Syntax:      dest = algid_objid2berobjid(oid, dest);
 * Description: The function DER-encodes the given object identifier, oid,
 *              and writes the result to dest. At least
 *              algid_sizeof_objid2berobjid(oid) octets of memory must
 *              have been allocated at dest.
 * Returns:     On success, this function returns a pointer to the byte after
 *              the last byte written. On failure (couldn't encode the length
 *              of oid), it returns 0.
 * Memory:      This function allocates no memory.
 */
extern u8 CST32EXPORTTYPE * CST16EXPORTTYPE
algid_objid2berobjid(algid_objid obj, u8 *buf);

/* Function:    <algid_berobjid2objid>
 * Summary:     Decodes a DER-encoded object identifier.
 * Syntax:      u8 *src = algid_berobjid2objid(u8 *src, (algid_objid *) &oid);
 * Description: The algid_berobjid2objid() function parses the DER-encoded
 *              ASN.1 OBJECT IDENTIFIER in src and converts it to an
 *              algid_objid in oid.
 * Returns:     On success, this function returns a pointer to the octet after
 *              the last one read. On failure (initial tag not 
 *              OBJECT IDENTIFIER or unable to allocate memory at oid), it 
 *              returns 0.
 * Memory:      Dispose of oid with algid_dispose_objid(oid).
 */
extern u8 CST32EXPORTTYPE * CST16EXPORTTYPE
algid_berobjid2objid(u8 *src, algid_objid *targ);

/* Function:    <algid_size2sizeoftype>
 * Summary:     Deprecated.
 * Syntax:      off_t  mlen = 
 *                algid_size2sizeoftype(sec_off_t  len, ut_asn1type type);
 * Description: Deprecated. Use asn1_size2sizeoftype() instead.
 */
extern sec_off_t  CST32EXPORTTYPE CST16EXPORTTYPE
algid_size2sizeoftype(sec_off_t len, ut_asn1type type);

/* Function:    <algid_sizeof_sizetype2bertaglen>
 * Summary:     Deprecated.
 * Syntax:      off_t mlen = algid_sizeof_sizetype2bertaglen(off_t len,
 *                ut_asn1type type);
 * Description: Deprecated. Use asn1_sizeof_sizetype2bertaglen() instead.
 */
extern sec_off_t CST32EXPORTTYPE CST16EXPORTTYPE
algid_sizeof_sizetype2bertaglen (sec_off_t len, ut_asn1type type);

/* Function:    <algid_sizetype2bertaglen>
 * Summary:     Deprecated.
 * Syntax:      dest = algid_sizetype2bertaglen(dest, len, type);
 * Description: Deprecated. Use asn1_sizetype2bertaglen() instead.
 */
extern u8 CST32EXPORTTYPE * CST16EXPORTTYPE
algid_sizetype2bertaglen(u8 *dest, sec_off_t size, ut_asn1type tag);

/* Function:    <algid_bertaglen2size>
 * Summary:     Deprecated.
 * Syntax:      src = algid_bertaglen2size(src, etag, &len);
 * Description: Deprecated. Use asn1_bertaglen2size() instead.
 */
extern u8 CST32EXPORTTYPE * CST16EXPORTTYPE
algid_bertaglen2size(u8 *src, ut_asn1type etag, sec_off_t *len);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* not _CST_ALGID_H */

