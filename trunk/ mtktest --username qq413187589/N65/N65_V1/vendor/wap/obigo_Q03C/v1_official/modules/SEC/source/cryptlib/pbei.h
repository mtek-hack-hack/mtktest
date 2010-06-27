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


#ifndef _PBE_I_H  /* prevent multiple inclusion */
#define _PBE_I_H

#include "cstopt.h" 
#include "ut.h"
#include "bsapi.h"
#include "algid.h"   /* for algid_encpara */

#ifdef WITH_pbe_pbe

#ifdef __cplusplus
extern "C" {
#endif


#define PBE_EBASE (0x05000000) 

#define PBE_EALGF (PBE_EBASE + 0x40000) /* Algorithm fetch failed */
#define PBE_EPBEDF (PBE_EBASE + 0x40001) /* PBE  Decryption failure */
#define PBE_EKEYF (PBE_EBASE + 0x40002) /* Key unreadable in file */
#define PBE_EPKCSF (PBE_EBASE + 0x40003) /* Encryption failure */
#define PBE_EPKCSDF (PBE_EBASE + 0x40004) /* PKCS8 Decryption failure */
#define PBE_EDECF (PBE_EBASE + 0x40005) /* Decryption failure */
#define PBE_EKEYDF (PBE_EBASE + 0x40006) /* Key derivation failed */
#define PBE_EHASH (PBE_EBASE + 0x40007) /* Hash Session Failure */
#define PBE_EPBEE (PBE_EBASE + 0x40008) /* Pbe Encryption Failure */
#define PBE_EMEMWF (PBE_EBASE + 0x50000) /* Memory write failure */
#define PBE_ESERR (PBE_EBASE + 0x50001) /* Syntax Error */
#define PBE_EPARAM (PBE_EBASE + 0x50002) /* Bad Parameter(s) */
#define PBE_ENTRNL (PBE_EBASE + 0x50003) /* Internal function failure */
#define PBE_ENOMEM (PBE_EBASE + 0x50004) /* No memory */
#define PBE_EBADASN (PBE_EBASE + 0x50005) /* Incorrect assignement */

#define DEFAULT_SALT_LEN  (8)

/*=========================================================================*/

/*
 * The following 170-odd lines describe a simple, high-level API to
 * passphrase-based encryption functions using one of the following
 * OIDs...
 */

/* specific OIDs. These are the only valid oid arguments to pbe_encrypt
 * and pkcs8_encrypt_old. The OID names describe the hash algorithm used to 
 * derive the key and the symmetric algorithm used to encrypt; 
 * SHAAnd3_KeyTripleDES_CBC and SHAAnd128BitRC2_CBC are the strongest. */

extern u32 algid_pkcs12_3Key3DES_cstv7_1[];


/*
 * For encrypting an RSA private key and outputting in a portable
 * format, use PKCS#8...
 */

/****************************************************************************
 *
 * pkcs8_encrypt_old: encrypts a PKCS#1 RSA private key using a passphrase and 
 * formats the output according to PKCS#8, PKCS#5.
 * 
 * privateKey contains the data you wish to protect
 * privateKeyOID is the private key OID
 * passphrase contains the passphrase
 * salt can optionally contain an mblk of random data to append to
 *   the passphrase before hashing. If salt == 0 we will generate the salt 
 *   internally (note that this is different from our implementation of 
 *   PKCS#5, which generates the salt internally if *salt = 0).
 * c can optionally contain the iteration count, which is the number of
 *   times to hash the passphrase+salt before using the output as a key+IV.
 * output will contain the output. Call with &output rather than by declaring
 *   output as ut_mblk* in the calling function.
 *   Note that output->data must not point to allocated memory. If you've
 *   used output before the call to this function, call ut_dispose_mem(&output)
 *   before passing output to pkcs8_encrypt_old.
 *
 * The hash algorithm used is MD5; the encryption algorithm used is DES-CBC.
 *
 * Returns 0 on failure, 1 on success.
 *
 ***************************************************************************/

extern
int
pkcs8_encrypt_old(
  ut_mblk *privateKey,
  u32     *privateKeyOID,
  ut_mblk *passphrase,
  ut_mblk *salt, 
  int      c, 
  u32     *oid,
  ut_mblk *output);


/****************************************************************************
 *
 * pkcs8_decrypt_old: decrypts PKCS#8-formatted encrypted data.
 *
 * encryptedPrivateKey contains the encrypted data
 * passphrase contains the passphrase
 * output will contain the output. Call with &output rather than by declaring
 *   output as ut_mblk* in the calling function.
 *   Note that output->data must not point to allocated memory. If you've
 *   used output before the call to this function, call ut_dispose_mem(&output)
 *   before passing output to pkcs8_decrypt_old.
 *
 * The hash algorithm used is MD5; the encryption algorithm used is DES-CBC.
 *
 * Returns 0 on failure, 1 on success.
 *
 ***************************************************************************/

extern
int
pkcs8_decrypt_old(ut_mblk *encryptedPrivateKey, ut_mblk *passphrase,
            ut_mblk *output);


/*
 * For general passphrase-based encryption, use pbe_encrypt.
 */


/****************************************************************************
 *
 * pbe_encrypt: Encrypts sensitiveData->data with passphrase->data, using
 * the oid to tell it which encryption algorithm and key-derivation
 * algorithm to use.
 #
 * Performs one-pass encryption only, so don't encrypt more than 64K
 * at a time...
 *
 * oid is the oid -- one of the above algid_*_pbeWith* oids.
 * sensitiveData contains the data you wish to protect
 * passphrase contains the passphrase
 * salt contains an mblk of random data which is appended to the
 *   passphrase before hashing. To generate the salt internally (which
 *   is done by hashing the passphrase + data), set salt->data = 0 and
 *   salt->size equal to the number of bytes of salt you want.
 *   If salt = 0 we do not append salt.
 * c contains the iteration count, which is the number of times to
 *   hash the passphrase+salt before deriving the key and IV from it.
 *   If *c = 0 the iteration count will be calculated so that the compression
 *   function in the hash function is called 5 times (equivalent to hashing
 *   5 64-byte blocks).
 * output will contain the output. Call with &output rather than by declaring
 *   output as ut_mblk * in the calling function.
 *   Note that output->data must not point to allocated memory. If you've
 *   used output before the call to this function, call ut_dispose_mem(&output)
 *   before passing output to pbe_encrypt.
 *
 * Returns 1 on success, 0 on failure.
 *
 * NOTE: the memory at salt->data must be disposed of explicitly even if
 * the salt is generated internally.
 *
 ***************************************************************************/

extern
int
pbe_encrypt_ascii(
  u32       *oid,
  ut_mblk   *sensitiveData,
  ut_mblk   *passphrase,
  ut_mblk   *salt,
  int       *c,
  ut_mblk   *output);

extern
int
pbe_encrypt_unicode(
  u32       *oid,
  ut_mblk   *sensitiveData,
  ut_mblk   *passphrase,
  ut_mblk   *salt,
  int       *c,
  ut_mblk   *output);

#ifdef _UNICODE
#define pbe_encrypt(o,s,p,st,c,op) pbe_encrypt_unicode(o,s,p,st,c,op)
#else /* def/ndef _UNICODE */
#define pbe_encrypt(o,s,p,st,c,op) pbe_encrypt_ascii(o,s,p,st,c,op)
#endif

/****************************************************************************
 *
 * pbe_decrypt: Decrypts sensitiveData->data with passphrase->data, using
 * the oid to tell it which decryption algorithm and key-derivation
 * algorithm to use.
 #
 * Performs one-pass decryption only, so don't decrypt more than 64K
 * at a time...
 *
 * sensitiveData contains the encrypted data
 * passphrase contains the passphrase
 * salt contains an mblk of random data which is appended to the
 *   passphrase before hashing.
 * c contains the iteration count, which is the number of times to
 *   hash the passphrase+salt before deriving the key and IV from it.
 * output will contain the output. Call with &output rather than by declaring
 *   output as ut_mblk * in the calling function.
 *   Note that output->data must not point to allocated memory. If you've
 *   used output before the call to this function, call ut_dispose_mem(&output)
 *   before passing output to pkcs12_decrypt.
 *
 * Returns 1 on success, 0 on failure.
 *
 ***************************************************************************/

extern
int
pbe_decrypt_ascii(
  u32       *oid,
  ut_mblk   *sensitiveData,
  ut_mblk   *passphrase,
  ut_mblk   *salt,
  int       *c,
  ut_mblk   *output);

extern
int
pbe_decrypt_unicode(
  u32       *oid,
  ut_mblk   *sensitiveData,
  ut_mblk   *passphrase,
  ut_mblk   *salt,
  int       *c,
  ut_mblk   *output);

#ifdef _UNICODE
#define pbe_decrypt(o,s,p,st,c,op) pbe_decrypt_unicode(o,s,p,st,c,op)
#else /* def/ndef _UNICODE */
#define pbe_decrypt(o,s,p,st,c,op) pbe_decrypt_ascii(o,s,p,st,c,op)
#endif


/*=========================================================================*/


/*
 * The rest of this header file defines a lower-level API to
 * passphrase-based encryption.
 *
 */

typedef enum {
  PKCS12_ENCRYPTIONKEY = 1,
  PKCS12_IV = 2,
  PKCS12_MACKEY = 3
} pkcs12_ID;

typedef struct pbe_params_s {
  ut_mblk *salt;
  u32      iterationCount;
} pbe_params;


/* lets us swap between PKCS-12 and PKCS-5 for key derivation from passphrase */

typedef enum {
  PBE_PKCS_5,
  PBE_PKCS_12,
  PBE_PKCS_12_OLD,
  PBE_PKCS_12_CSTV7_1,
  PBE_MAX
} pbe_algn;

typedef struct pbe_alg_s {
  const char  *name;
  pbe_algn     number;  
  int        (*initialise)(u32 *, bsapi_kset *, bsapi_mode *, 
                 const bsapi_alg **);
  int        (*deriveKeyAndIV)(ut_mblk *, int, pbe_params *, u32 *, ut_mblk *, 
                 ut_mblk *);
  int        (*encrypt)(u32 *, ut_mblk *, ut_mblk *, ut_mblk *, int *, 
                 ut_mblk *);
  int        (*decrypt)(u32 *, ut_mblk *, ut_mblk *, ut_mblk *, int *, 
                 ut_mblk *);
  int        (*encrypt_unicode)(u32 *, ut_mblk *, ut_mblk *, ut_mblk *, int *, 
                 ut_mblk *);
  int        (*decrypt_unicode)(u32 *, ut_mblk *, ut_mblk *, ut_mblk *, int *, 
                 ut_mblk *);
} pbe_alg;

extern const pbe_alg pbe_pkcs5;
const extern pbe_alg pbe_pkcs12;
const extern pbe_alg pbe_pkcs12_old;
const extern pbe_alg pbe_pkcs12_cstv7_1;

/* pbe_select: returns pbe_pkcs12, pbe_pkcs5, or 0 (error) given an OID */

extern const pbe_alg *pbe_select (const u32 *oid);

/*
 * PKCS 12 routines:
 */

/****************************************************************************
 *
 * pkcs12_deriveKeyAndIV(
 *  ut_mblk    *passphrase -- the passphrase.
 *  int         notASCII -- set to 0 if the passphrase is in ASCII characters
 *                    rather than Unicode. Under PKCS#12 all characters
 *                    have to be entered in Unicode; if they're ASCII we
 *                    convert to Unicode by putting a null byte in front
 *                    of each character. If not ASCII then the byte array
 *                    must contain big-endian byte-pairs corresponding to
 *                    the Unicode passphrase.
 *  pbe_params *params -- contains the salt bytes and iteration count.
 *                    These fields must be filled in -- the function
 *                    will not derive them itself.
 *  u32        *oid -- one of the six PKCS#12 objids declared above.
 *  ut_mblk    *key -- will contain the key. There must be no memory
 *                    allocated at key->data; we allocate the memory
 *                    internally with ut_new_mem.
 *  ut_mblk    *iv -- will contain the iv. There must be no memory
 *                    allocated at iv->data; we allocate the memory
 *                    internally with ut_new_mem.
 * );
 * returns 1 on success, 0 on failure.
 *
 ****************************************************************************/

extern
int pkcs12_deriveKeyAndIV(
    ut_mblk    *passphrase,
    int         notASCII,
    pbe_params *params,
    u32        *oid,
    ut_mblk    *key,
    ut_mblk    *IV);


/****************************************************************************
 *
 * pkcs12_derive(
 *  ut_mblk    *passphrase -- the passphrase.
 *  int         notASCII -- set to 0 if the passphrase is in ASCII characters
 *                    rather than Unicode. Under PKCS#12 all characters
 *                    have to be entered in Unicode; if they're ASCII we
 *                    convert to Unicode by putting a null byte in front
 *                    of each character. If not ASCII then the byte array
 *                    must contain big-endian byte-pairs corresponding to
 *                    the Unicode passphrase.
 *  pbe_params *params -- contains the salt bytes
 *  pkcs12_ID   output_type -- PKCS12_ENCRYPTIONKEY, PKCS12_IV, PKCS12_MACKEY;
 *                    defines whether we're deriving an encryption key, an
 *                    encryption IV, or a key for a MAC.
 *  u32        *algInfo -- If output_type is IV or Encryption Key: Object ID: 
 *                    one of the above six.
 *                    If output_type is MAC Key: the length of the MAC key to 
 *                    be produced (if algInfo [not *algInfo] == 0 we produce 
 *                    20 bytes).
 *  ut_mblk    *output -- will contain the output.
 * );
 * returns 1 on success, 0 on failure.
 *
 ****************************************************************************/

extern
int pkcs12_derive(
    ut_mblk    *passphrase,
    int         notASCII,
    pbe_params *params,
    pkcs12_ID   output_type,
    u32        *algInfo,
    ut_mblk    *output);

/****************************************************************************
 *
 * pkcs12_initialise -- sets default bsapi_alg, bsapi_kset, bsapi_mode
 * values according to the oid.
 *
 * Returns 0 on failure (couldn't recognise OID). Returns 1 on success.
 *
 ***************************************************************************/

extern
int
pkcs12_initialise (
  u32                *oid,
  bsapi_kset         *bkeys,
  bsapi_mode         *bmode,
  const bsapi_alg   **balg);



/****************************************************************************
 *
 * pkcs12_encrypt: Encrypts sensitiveData->data with passphrase->data, using
 * PKCS#12 to derive the key for the algorithm given by oid.
 #
 * Performs one-pass encryption only, so don't encrypt more than 64K
 * at a time...
 *
 * sensitiveData contains the data you wish to protect
 * passphrase contains the passphrase.  If not ASCII then the byte array
 *                    must contain big-endian byte-pairs corresponding to
 *                    the Unicode passphrase.
 * salt contains an mblk of random data which is appended to the
 *   passphrase before hashing. If salt->data  == 0 we generate eight
 *   bytes of salt internally. If salt = 0 we do not append salt.
 * c contains the iteration count, which is the number of times to
 *   hash the passphrase+salt before deriving the key and IV from it.
 *   If *c = 0 the iteration count will be calculated so that the compression
 *   function in the hash function is called 5 times (equivalent to hashing
 *   5 64-byte blocks).
 * output will contain the output. Call with &output rather than by declaring
 *   output as ut_mblk * in the calling function.
 *   Note that output->data must not point to allocated memory. If you've
 *   used output before the call to this function, call ut_dispose_mem(&output)
 *   before passing output to pkcs12_encrypt.
 *
 * Returns 1 on success, 0 on failure.
 *
 * NOTE: the memory at salt->data must be disposed of explicitly.
 *
 ***************************************************************************/

extern
int
pkcs12_encrypt_ascii(
  u32       *oid,
  ut_mblk   *sensitiveData,
  ut_mblk   *passphrase,
  ut_mblk   *salt,
  int       *c,
  ut_mblk   *output);


extern
int
pkcs12_encrypt_unicode(
  u32       *oid,
  ut_mblk   *sensitiveData,
  ut_mblk   *passphrase,
  ut_mblk   *salt,
  int       *c,
  ut_mblk   *output);

#ifndef _UNICODE
#define pkcs12_encrypt(o,sd,pp,sl,c,out) pkcs12_encrypt_ascii(o,sd,pp,sl,c,out)
#else
#define pkcs12_encrypt(o,sd,pp,sl,c,out) pkcs12_encrypt_unicode(o,sd,pp,sl,c,out)
#endif /* def/ndef _UNICODE */


/****************************************************************************
 *
 * pkcs12_decrypt: Decrypts sensitiveData->data with passphrase->data, using
 * PKCS#12 to derive the key for the algorithm given by oid.
 #
 * Performs one-pass decryption only, so don't decrypt more than 64K
 * at a time...
 *
 * sensitiveData contains the data you wish to protect
 * passphrase contains the passphrase. If not ASCII then the byte array
 *                    must contain big-endian byte-pairs corresponding to
 *                    the Unicode passphrase.
 * salt contains an mblk of random data which is appended to the
 *   passphrase before hashing.
 * c contains the iteration count, which is the number of times to
 *   hash the passphrase+salt before deriving the key and IV from it.
 * output will contain the output. Call with &output rather than by declaring
 *   output as ut_mblk * in the calling function.
 *   Note that output->data must not point to allocated memory. If you've
 *   used output before the call to this function, call ut_dispose_mem(&output)
 *   before passing output to pkcs12_decrypt.
 *
 * Returns 1 on success, 0 on failure.
 *
 ***************************************************************************/

extern
int
pkcs12_decrypt_ascii(
  u32       *oid,
  ut_mblk   *sensitiveData,
  ut_mblk   *passphrase,
  ut_mblk   *salt,
  int       *c,
  ut_mblk   *output);

extern
int
pkcs12_decrypt_unicode(
  u32       *oid,
  ut_mblk   *sensitiveData,
  ut_mblk   *passphrase,
  ut_mblk   *salt,
  int       *c,
  ut_mblk   *output);

#ifndef _UNICODE
#define pkcs12_decrypt(o,sd,pp,sl,c,out) pkcs12_decrypt_ascii(o,sd,pp,sl,c,out)
#else
#define pkcs12_decrypt(o,sd,pp,sl,c,out) pkcs12_decrypt_unicode(o,sd,pp,sl,c,out)
#endif /* def/ndef _UNICODE */

/* We have to support two old, incorrect versions too... */

extern int pkcs12_old_deriveKeyAndIV( ut_mblk *passphrase, int notASCII,
 pbe_params *params, u32 *oid, ut_mblk *key, ut_mblk *IV);
extern int pkcs12_old_derive(ut_mblk *passphrase, int notASCII,
 pbe_params *params, pkcs12_ID output_type, u32 *algInfo, ut_mblk *output);
extern int pkcs12_old_initialise ( u32 *oid, bsapi_kset *bkeys, 
  bsapi_mode *bmode, const bsapi_alg   **balg);
extern int pkcs12_old_encrypt_ascii( u32 *oid, ut_mblk *sensitiveData,
  ut_mblk *passphrase, ut_mblk *salt, int *c, ut_mblk *output);
extern int pkcs12_old_decrypt_ascii( u32 *oid, ut_mblk *sensitiveData, 
  ut_mblk *passphrase, ut_mblk *salt, int *c, ut_mblk *output);
extern int pkcs12_old_encrypt_unicode( u32 *oid, ut_mblk *sensitiveData,
  ut_mblk *passphrase, ut_mblk *salt, int *c, ut_mblk *output);
extern int pkcs12_old_decrypt_unicode( u32 *oid, ut_mblk *sensitiveData, 
  ut_mblk *passphrase, ut_mblk *salt, int *c, ut_mblk *output);

extern int pkcs12_deriveKeyAndIV_cstv7_1( ut_mblk *passphrase, int notASCII,
 pbe_params *params, u32 *oid, ut_mblk *key, ut_mblk *IV);
extern int pkcs12_derive_cstv7_1(ut_mblk *passphrase, int notASCII,
 pbe_params *params, pkcs12_ID output_type, u32 *algInfo, ut_mblk *output);
extern int pkcs12_initialise_cstv7_1(u32 *oid, bsapi_kset *bkeys, 
  bsapi_mode *bmode, const bsapi_alg  **balg);
extern int pkcs12_encrypt_cstv7_1_ascii(u32 *oid, ut_mblk *sensitiveData,
  ut_mblk *passphrase, ut_mblk *salt, int *c, ut_mblk *output);
extern int pkcs12_decrypt_cstv7_1_ascii(u32 *oid, ut_mblk *sensitiveData, 
  ut_mblk *passphrase, ut_mblk *salt, int *c, ut_mblk *output);
extern int pkcs12_encrypt_cstv7_1_unicode(u32 *oid, ut_mblk *sensitiveData,
  ut_mblk *passphrase, ut_mblk *salt, int *c, ut_mblk *output);
extern int pkcs12_decrypt_cstv7_1_unicode(u32 *oid, ut_mblk *sensitiveData, 
  ut_mblk *passphrase, ut_mblk *salt, int *c, ut_mblk *output);

#ifndef _UNICODE
#define pkcs12_old_encrypt(o,sd,pp,sl,c,out) \
  pkcs12_old_encrypt_ascii(o,sd,pp,sl,c,out)
#define pkcs12_old_decrypt(o,sd,pp,sl,c,out) \
  pkcs12_old_decrypt_ascii(o,sd,pp,sl,c,out)
#define pkcs12_encrypt_cstv7_1(o,sd,pp,sl,c,out) \
  pkcs12_encrypt_cstv7_1_ascii(o,sd,pp,sl,c,out)
#define pkcs12_decrypt_cstv7_1(o,sd,pp,sl,c,out) \
  pkcs12_decrypt_cstv7_1_ascii(o,sd,pp,sl,c,out)
#else
#define pkcs12_old_encrypt(o,sd,pp,sl,c,out) \
  pkcs12_old_encrypt_unicode(o,sd,pp,sl,c,out)
#define pkcs12_old_decrypt(o,sd,pp,sl,c,out) \
  pkcs12_old_decrypt_unicode(o,sd,pp,sl,c,out)
#define pkcs12_encrypt_cstv7_(o,sd,pp,sl,c,out) \
  pkcs12_encrypt_cstv7_1_unicode(o,sd,pp,sl,c,out)
#define pkcs12_decrypt_cstv7_1(o,sd,pp,sl,c,out) \
  pkcs12_decrypt_cstv7_1_unicode(o,sd,pp,sl,c,out)
#endif /* def/ndef _UNICODE */


/*
 * PKCS#5 routines...
 */


/****************************************************************************
 *
 * pkcs5_deriveKeyAndIV(
 *  ut_mblk    *passphrase -- the passphrase.
 *  int         ignoreMe -- ignore me.
 *  pbe_params *params -- contains the salt bytes.
 *  u32        *oid -- one of the six PKCS#12 objids declared above.
 *  ut_mblk    *key -- will contain the key.
 *  ut_mblk    *iv -- will contain the iv.
 * );
 * returns 1 on success, 0 on failure.
 *
 ****************************************************************************/

extern
int 
pkcs5_deriveKeyAndIV(
  ut_mblk    *passphrase,
  int         ignoreMe,
  pbe_params *params,
  u32        *oid,
  ut_mblk    *key,
  ut_mblk    *IV);



/****************************************************************************
 *
 * pkcs5_initialise -- sets default bsapi_alg, bsapi_kset, bsapi_mode
 * values according to the oid.
 *
 * Returns 0 on failure (couldn't recognise OID). Returns 1 on success.
 *
 ***************************************************************************/

extern
int
pkcs5_initialise (
  u32                *oid,
  bsapi_kset         *bkeys,
  bsapi_mode         *bmode,
  const bsapi_alg   **balg);


/****************************************************************************
 *
 * pkcs5_encrypt: Encrypts sensitiveData->data with passphrase->data.
 * Performs one-pass encryption only, so don't encrypt more than 64K
 * at a time...
 *
 * sensitiveData contains the data you wish to protect
 * passphrase contains the passphrase.  If not ASCII then the byte array
 *                    must contain big-endian byte-pairs corresponding to
 *                    the Unicode passphrase.
 * salt contains an mblk of random data which is appended to the
 *   passphrase before hashing. If salt->data  == 0 we generate eight 
 *   bytes of salt internally. If salt = 0 we do not append salt.
 * c contains the iteration count, which is the number of times to
 *   hash the passphrase+salt before deriving the key and IV from it.
 *   If *c = 0 the iteration count will be calculated so that the compression
 *   function in the hash function is called 5 times (equivalent to hashing
 *   5 64-byte blocks).
 * output will contain the output. Call with &output rather than by declaring
 *   output as ut_mblk * in the calling function.
 *   Note that output->data must not point to allocated memory. If you've
 *   used output before the call to this function, call ut_dispose_mem(&output)
 *   before passing output to pkcs5_encrypt.
 *
 * Note that in unicode mode, passphrase should be an array of big-endian
 * byte pairs corresponding to the passphrase, not including a terminating
 * zero. A pointer to a u16* array is incorrect.
 *
 * The hash algorithm used is MD5; the encryption algorithm used is DES-CBC.
 * The OIDs are handled by the pkcs8_encrypt_old function.
 *
 ***************************************************************************/

extern
int 
pkcs5_encrypt_ascii(
  u32 *oid,
  ut_mblk *sensitiveData, 
  ut_mblk *passphrase, 
  ut_mblk *salt, 
  int *c, 
  ut_mblk *output);

extern
int 
pkcs5_encrypt_unicode(
  u32 *oid,
  ut_mblk *sensitiveData, 
  ut_mblk *passphrase, 
  ut_mblk *salt, 
  int *c, 
  ut_mblk *output);

#ifndef _UNICODE
#define pkcs5_encrypt(o,sd,pp,sl,c,out) pkcs5_encrypt_ascii(o,sd,pp,sl,c,out)
#else
#define pkcs5_encrypt(o,sd,pp,sl,c,out) pkcs5_encrypt_unicode(o,sd,pp,sl,c,out)
#endif /* def/ndef _UNICODE */



/****************************************************************************
 *
 * pkcs5_decrypt: Decrypts sensitiveData->data with passphrase->data.
 * Performs one-pass decryption only, so don't decrypt more than 64K
 * at a time...
 *
 * sensitiveData contains the data you wish to protect
 * passphrase contains the passphrase.  If not ASCII then the byte array
 *                    must contain big-endian byte-pairs corresponding to
 *                    the Unicode passphrase.
 * salt contains an mblk of random data which is appended to the
 *   passphrase before hashing. 
 * c contains the iteration count, which is the number of times to
 *   hash the passphrase+salt before deriving the key and IV from it.
 *   If *c = 0 the iteration count will be calculated so that the compression
 *   function in the hash function is called 5 times (equivalent to hashing
 *   5 64-byte blocks).
 * output will contain the output. Call with &output rather than by declaring
 *   output as ut_mblk * in the calling function.
 *   Note that output->data must not point to allocated memory. If you've
 *   used output before the call to this function, call ut_dispose_mem(&output)
 *   before passing output to pkcs5_decrypt.
 *
 * Note that in unicode mode, passphrase should be an array of big-endian
 * byte pairs corresponding to the passphrase, not including a terminating
 * zero. A pointer to a u16* array is incorrect.
 *
 * The hash algorithm used is MD5; the decryption algorithm used is DES-CBC.
 * The OIDs are handled by the pkcs8_decrypt_old function.
 *
 * Returns 1 on success, 0 on failure.
 *
 ***************************************************************************/

extern
int 
pkcs5_decrypt_ascii(
  u32 *oid,
  ut_mblk *sensitiveData, 
  ut_mblk *passphrase, 
  ut_mblk *salt, 
  int *c, 
  ut_mblk *output);

extern
int 
pkcs5_decrypt_unicode(
  u32 *oid,
  ut_mblk *sensitiveData, 
  ut_mblk *passphrase, 
  ut_mblk *salt, 
  int *c, 
  ut_mblk *output);


#ifndef _UNICODE
#define pkcs5_decrypt(o,sd,pp,sl,c,out) pkcs5_decrypt_ascii(o,sd,pp,sl,c,out)
#else
#define pkcs5_decrypt(o,sd,pp,sl,c,out) pkcs5_decrypt_unicode(o,sd,pp,sl,c,out)
#endif /* def/ndef _UNICODE */


/* pkcs8_berMblk2privateKeyData: turns a PKCS#8-format private key into
 * the ut_mblks that bsapi can handle. Doesn't do any interpretation of
 * the oid, so DSA and DH shared parameters end up in the params block,
 * NOT in the private key.
 *
 * Allocates memory at privateKey->data and params->data (dispose of 
 * with ut_dispose_mem) and oid (dispose of with algid_dispose_objid).
 *
 * Returns 0 on success, 1 on failure.
 */


int
pkcs8_berMblk2privateKeyData(ut_mblk   *input,
                             ut_mblk   *privateKey,
                             ut_mblk   *params, 
                             u32      **oid);


/* disassemble encrypted private key data into an OID, pbe_params, and
 * the encrypted data.
 *
 * Allocates memory at privateKey->data, params->salt (dispose with
 * ut_dispose_mblk_f) and *oid.
 */

int
pkcs8_berMblk2encryptedPrivateKeyData(ut_mblk     *input,
                                      ut_mblk     *privateKey,
                                      algid_encpara  *params,
                                      u32        **oid);


/* pkcs8_berMblk2oidParamsAndData
 *
 * Takes the ber-encoded string:
 * SEQUENCE {
 *    (if useVersion) INTEGER version,
 *    SEQUENCE {
 *      Algorithm Identifier OID,
 *      OCTET STRING params
 *    }
 *    OCTET STRING keyData
 * }
 * and extracts the OID, the params, and the keyData fields. Note that
 * the params are in the format that algid_beraid2aid interprets them
 * into -- pbe_params for a pbe OID, ut_mblk * if the OID identifies a
 * public-key algorithm that takes parameters. We do this rather than
 * returning the algid structure because the algid structure doesn't
 * actually contain the relevant pbe commands which would be of use.
 * It's up to the calling function to dispose of the parameters and that
 * function is supposed to know what format the parameters are in.
 *
 * Returns 0 on success, -1 on internal failure.
 *
 * Assumes that data is definite-length encoded.
 */

int
pkcs8_berMblk2oidParamsAndData(ut_mblk    *input,
                               ut_mblk    *data,
                               void      **params, 
                               u32       **oid);





/* pkcs8_keyAndParams2berMblk
 *
 * Takes a ut_mblk containing a key, (optionally) a ut_mblk containing
 * parameters, and an object ID, and returns a PKCS#8-formatted private
 * key. Doesn't handle attributes.
 *
 * In fact, this function simply makes sure the key and parameters have
 * the correct form for passing to pkcs8_oidParamsAndData2berMblk().
 *
 * Returns 0 on success, -1 on failure.
 */

int
pkcs8_keyAndParams2berMblk(ut_mblk   *privateKey,
                           ut_mblk   *params, 
                           u32 *oid,
                           ut_mblk   *output);


/* pkcs8_encryptedPrivateKey2berMblk: outputs pkcs#8-formatted encrypted
 * private key data. 
 *
 * Simply a wrapper for pkcs8_oidParamsAndData2berMblk.
 */

int
pkcs8_encryptedPrivateKey2berMblk(ut_mblk    *encryptedPrivateKey,
                                  algid_encpara *params,
                                  u32        *oid,
                                  ut_mblk    *output);


#ifdef __cplusplus
}
#endif

#endif /* def WITH_pbe_pbe */

#endif /* ndef _PBE_I_H */
