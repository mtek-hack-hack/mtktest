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

#ifndef _PKCS8_H  /* prevent multiple inclusion */
#define _PKCS8_H

#include "cstopt.h" 
#include "ut.h"

#ifdef WITH_pbe_pbe

#define PKCS8_EBASE (0x06000000)
#define PKCS8_EALGF (PKCS8_EBASE + 0x40000) /* Algorithm fetch failed */
#define PKCS8_EPKCS8DF (PKCS8_EBASE + 0x40001) /* PKCS8  Decryption failure */
#define PKCS8_EKEYF (PKCS8_EBASE + 0x40002) /* Key unreadable in file */
#define PKCS8_EPKCSF (PKCS8_EBASE + 0x40003) /* Encryption failure */
#define PKCS8_EPKCSDF (PKCS8_EBASE + 0x40004) /* PKCS8 Decryption failure */
#define PKCS8_EDECF (PKCS8_EBASE + 0x40005) /* Decryption failure */
#define PKCS8_EKEYDF (PKCS8_EBASE + 0x40006) /* Key derivation failed */
#define PKCS8_EHASH (PKCS8_EBASE + 0x40007) /* Hash Session Failure */
#define PKCS8_EPKCS8E (PKCS8_EBASE + 0x40008) /* Pbe Encryption Failure */
#define PKCS8_EMEMWF (PKCS8_EBASE + 0x50000) /* Memory write failure */
#define PKCS8_ESERR (PKCS8_EBASE + 0x50001) /* Syntax Error */
#define PKCS8_EPARAM (PKCS8_EBASE + 0x50002) /* Bad Parameter(s) */
#define PKCS8_ENTRNL (PKCS8_EBASE + 0x50003) /* Internal function failure */
#define PKCS8_ENOMEM (PKCS8_EBASE + 0x50004) /* No memory */
#define PKCS8_EBADASN (PKCS8_EBASE + 0x50005) /* Incorrect assignment */

#ifdef __cplusplus
extern "C" {
#endif


/* Function:    <pkcs8_encrypt_ascii>
 * Summary:     Encrypts a private key using PKCS#8.
 * Syntax:      int rval = pkcs8_encrypt_ascii(ut_mblk *privateKey, u32
 *                *privateKeyOID, ut_mblk *params, ut_mblk
 *                *passphrase, ut_mblk *salt, int count, u32 *pbeAlgId,
 *                ut_mblk *output);
 * Description: The pkcs8_encrypt_ascii() function encrypts a private key for
 *              RSA, DSA or Diffie-Hellman and formats the output according
 *              to the PKCS#8 standard. It takes the following parameters:
 *              privateKey -- the private key data.
 *              privateKeyOID -- the algid_objid identifying the private key.
 *                This should be algid_x509_rsa or algid_rsa_rsa for RSA,
 *                algid_ansi_dsa for DSA, algid_ansi_x942dhPubKey for DH.
 *              params -- any parameters associated with the
 *                private key (for DSA, DH).
 *              passphrase -- passphrase->data contains the passphrase.
 *                passphrase->used contains the length of the passphrase
 *                in octets. pkcs8_encrypt_ascii() expects passphrase->data 
 *                to be a sequence of 8-bit characters. It converts this string 
 *                to a big-endian 16-bit Unicode representation using 
 *                ut_ascii2bmp().
 *              salt -- contains salt data which is passed to the hash
 *                function to prevent dictionary attacks. If this is 0
 *                salt is generated internally.
 *              count -- the number of times to hash the passphrase and
 *                salt. If this is 0 it is generated randomly internally
 *                in the range [768, 1023].
 *              pbeAlgId -- the algid_objid identifying the PBE algorithm.
 *                This must be drawn from the set
 *                {algid_pkcs12_pbeWithSHAAnd128BitRC4,
 *                algid_pkcs12_pbeWithSHAAnd40BitRC4,
 *                algid_pkcs12_pbeWithSHAAnd3_KeyTripleDES_CBC,
 *                algid_pkcs12_pbeWithSHAAnd2_KeyTripleDES_CBC,
 *                algid_pkcs12_pbeWithSHAAnd128BitRC2_CBC,
 *                algid_pkcs12_pbeWithSHAAnd40BitRC2_CBC,
 *                algid_pkcs5_pbeWithMD5AndDES_CBC}
 *              output -- the PKCS#8 formatted encrypted private key is
 *                placed here on success.
 * Returns:     This function returns 0 on success, -1 on failure. Failure
 *              is caused by lack of memory, null parameters or an unrecognized
 *              pbeAlgId.
 * Memory:      Dispose of the memory allocated by this function
 *              as follows:
 *           (code)
 *              ut_dispose_mem(output->data);
 *           (/code)
 * Notes:       This function can produce PKCS#8 encrypted data for any 
 *              private key algorithm so long as you know the privateKeyOID
 *              and the parameters are correctly formatted.
 *     
 *              pkcs8_encrypt() is defined as a macro. If _UNICODE is
 *              defined it wraps pkcs8_encrypt_unicode(). If _UNICODE is 
 *              not defined it wraps pkcs8_encrypt_ascii().      
 */
int
pkcs8_encrypt_ascii(ut_mblk *privateKey, u32 *privateKeyOID,
    ut_mblk *params, ut_mblk *passphrase,
    ut_mblk *salt, int count, u32 *pbeAlgId, ut_mblk *output);

/* Function:    <pkcs8_encrypt_unicode>
 * Summary:     Encrypts a private key using PKCS#8.
 * Syntax:      int rval = pkcs8_encrypt_unicode(ut_mblk *privateKey, u32
 *                *privateKeyOID, ut_mblk *params, ut_mblk
 *                *passphrase, ut_mblk *salt, int count, u32 *pbeAlgId,
 *                ut_mblk *output);
 * Description: The pkcs8_encrypt_unicode() function encrypts a private key for
 *              RSA, DSA or Diffie-Hellman and formats the output according
 *              to the PKCS#8 standard. It takes the following parameters:
 *              privateKey -- the private key data.
 *              privateKeyOID -- the algid_objid identifying the private key.
 *                This should be algid_x509_rsa or algid_rsa_rsa for RSA,
 *                algid_ansi_dsa for DSA, algid_ansi_x942dhPubKey for DH.
 *              params -- any parameters associated with the
 *                private key (for DSA, DH).
 *              passphrase -- passphrase->data contains the passphrase.
 *                passphrase->used contains the length of the passphrase
 *                in octets. pkcs8_encrypt_unicode() expects passphrase->data
 *                to be a 16-bit Unicode string in big-endian byte order, *NOT*
 *                an array of wchar_t in host byte order.
 *              salt -- contains salt data which is passed to the hash
 *                function to prevent dictionary attacks. If this is 0
 *                salt is generated internally.
 *              count -- the number of times to hash the passphrase and
 *                salt. If this is 0 it is generated randomly internally
 *                in the range [768, 1023].
 *              pbeAlgId -- the algid_objid identifying the PBE algorithm.
 *                This must be drawn from the set
 *                {algid_pkcs12_pbeWithSHAAnd128BitRC4,
 *                algid_pkcs12_pbeWithSHAAnd40BitRC4,
 *                algid_pkcs12_pbeWithSHAAnd3_KeyTripleDES_CBC,
 *                algid_pkcs12_pbeWithSHAAnd2_KeyTripleDES_CBC,
 *                algid_pkcs12_pbeWithSHAAnd128BitRC2_CBC,
 *                algid_pkcs12_pbeWithSHAAnd40BitRC2_CBC,
 *                algid_pkcs5_pbeWithMD5AndDES_CBC}
 *              output -- the PKCS#8 formatted encrypted private key is
 *                placed here on success.
 * Returns:     This function returns 0 on success, -1 on failure. Failure
 *              is caused by lack of memory, null parameters or an unrecognized
 *              pbeAlgId.
 * Memory:      Dispose of the memory allocated by this function
 *              as follows:
 *           (code)
 *              ut_dispose_mem(output->data);
 *           (/code)
 * Notes:       This function can produce PKCS#8 encrypted data for any 
 *              private key algorithm so long as you know the privateKeyOID
 *              and the parameters are correctly formatted.
 *            
 *              pkcs8_encrypt() is defined as a macro. If _UNICODE is
 *              defined it wraps pkcs8_encrypt_unicode(). If _UNICODE is 
 *              not defined it wraps pkcs8_encrypt_ascii().           
 */
int
pkcs8_encrypt_unicode(ut_mblk *privateKey, u32 *privateKeyOID,
    ut_mblk *params, ut_mblk *passphrase,
    ut_mblk *salt, int count, u32 *pbeAlgId, ut_mblk *output);

/* Function:    <pkcs8_encrypt>
 * Summary:     Encrypts a private key using PKCS#8.
 * Description: pkcs8_encrypt() is defined as a macro. If _UNICODE is
 *              defined it wraps pkcs8_encrypt_unicode(). If _UNICODE
 *              is not defined it wraps pkcs8_encrypt_ascii().
 * Notes:       See pkcs8_encrypt_unicode() and pkcs8_encrypt_ascii().
 */
#ifdef _UNICODE
#define pkcs8_encrypt(pk,pkid,par,pp,s,c,paid,o) \
        pkcs8_encrypt_unicode(pk,pkid,par,pp,s,c,paid,o)
#else
#define pkcs8_encrypt(pk,pkid,par,pp,s,c,paid,o) \
        pkcs8_encrypt_ascii(pk,pkid,par,pp,s,c,paid,o)
#endif

/* Function:    <pkcs8_decrypt_ascii>
 * Summary:     Decrypts a private key using PKCS#8.
 * Syntax:      int rval = pkcs8_decrypt_ascii(ut_mblk *encryptedPrivateKey,
 *                ut_mblk *passphrase, ut_mblk *privateKey, ut_mblk
 *                *params, u32 **privateKeyOID);
 * Description: The pkcs8_decrypt_ascii() function reads a PKCS#8 format 
 *              private key and decrypts it with the specified passphrase.
 *              It takes the following parameters:
 *              encryptedPrivateKey -- holds the input encrypted private
 *                key;
 *              passphrase -- passphrase->data contains the passphrase.
 *                passphrase->used contains the length of the passphrase
 *                in octets. pkcs8_decrypt_ascii() expects passphrase->data
 *                to be a sequence of 8-bit characters. It converts this string
 *                to a big-endian 16-bit Unicode representation using 
 *                ut_ascii2bmp().
 *              privateKey -- on success, holds the private key data.
 *              params -- on success, holds parameters associated 
 *                with the private key (if any).
 *              privateKeyOID -- on success, holds the algid_objid identifying 
 *                the private key.
 * Returns:     This function returns 0 on success, -1 on failure. Failure
 *              is caused by lack of memory, null parameters, an unrecognized
 *              pbeAlgId or badly formatted input data.
 * Memory:      Dispose of the memory allocated by this function
 *              as follows:
 *           (code)
 *              ut_dispose_mem(privateKey->data);
 *              if (params->data)
 *                ut_dispose_mem(params->data);
 *           (/code)
 * Notes:       The function will correctly decrypt any PKCS#8 formatted
 *              encrypted private key. It's up to the developer to check the
 *              privateKeyOID to make sure that the returned key was for the
 *              algorithm identifier. The parameters in PKCS#8 are encoded
 *              in an ASN.1 OCTET STRING; the data returned in params
 *              is the contents of the OCTET STRING (ie with the header and 
 *              length fields left off).
 *
 *              The key is assumed to be DER-encoded, ie no indefinite-length.
 *    
 *              pkcs8_decrypt() is defined as a macro. If _UNICODE is
 *              defined it wraps pkcs8_decrypt_unicode(). If _UNICODE
 *              is not defined it wraps pkcs8_decrypt_ascii().
 */
int
pkcs8_decrypt_ascii(ut_mblk *encryptedPrivateKey, ut_mblk *passphrase,
    ut_mblk *privateKey, ut_mblk *params, u32 **privateKeyOID);

/* Function:    <pkcs8_decrypt_ascii>
 * Summary:     Decrypts a private key using PKCS#8.
 * Syntax:      int rval = pkcs8_decrypt_ascii(ut_mblk *encryptedPrivateKey,
 *                ut_mblk *passphrase, ut_mblk *privateKey, ut_mblk
 *                *params, u32 **privateKeyOID);
 * Description: The pkcs8_decrypt_ascii() function reads a PKCS#8 format 
 *              private key and decrypts it with the specified passphrase.
 *              It takes the following parameters:
 *              encryptedPrivateKey -- holds the input encrypted private
 *                key;
 *              passphrase -- passphrase->data contains the passphrase.
 *                passphrase->used contains the length of the passphrase
 *                in octets. pkcs8_decrypt_unicode() expects passphrase->data
 *                to be a 16-bit Unicode string in big-endian byte order, *NOT*
 *                an array of wchar_t in host byte order.
 *              privateKey -- on success, holds the private key data.
 *              params -- on success, holds parameters associated 
 *                with the private key (if any).
 *              privateKeyOID -- on success, holds the algid_objid identifying 
 *                the private key.
 * Returns:     This function returns 0 on success, -1 on failure. Failure
 *              is caused by out of memory, null parameters, unrecognized
 *              pbeAlgId or badly formatted input data.
 * Memory:      Dispose of the memory allocated by this function
 *              as follows:
 *           (code)
 *              ut_dispose_mem(privateKey->data);
 *              if (params->data)
 *                ut_dispose_mem(params->data);
 *           (/code)
 * Notes:       The function will correctly decrypt any PKCS#8 formatted
 *              encrypted private key. It's up to the developer to check the
 *              privateKeyOID to make sure that the returned key was for the
 *              algorithm identifier. The parameters in PKCS#8 are encoded
 *              in an ASN.1 OCTET STRING; the data returned in params
 *              is the contents of the OCTET STRING (ie with the header and 
 *              length fields left off).
 *
 *              The key is assumed to be DER-encoded, ie no indefinite-length.
 *              
 *              pkcs8_decrypt() is defined as a macro. If _UNICODE is
 *              defined it wraps pkcs8_decrypt_unicode(). If _UNICODE
 *              is not defined it wraps pkcs8_decrypt_ascii().
 */
int
pkcs8_decrypt_unicode(ut_mblk *encryptedPrivateKey, ut_mblk *passphrase,
    ut_mblk *privateKey, ut_mblk *params, u32 **privateKeyOID);

/* Function:    <pkcs8_decrypt>
 * Summary:     Decrypts a private key using PKCS#8.
 * Description: pkcs8_decrypt() is defined as a macro. If _UNICODE is
 *              defined it wraps pkcs8_decrypt_unicode(). If _UNICODE
 *              is not defined it wraps pkcs8_decrypt_ascii().
 * Notes:       See pkcs8_decrypt_unicode() and pkcs8_decrypt_ascii().
 */
#ifdef _UNICODE
#define pkcs8_decrypt(epk,pp,pk,par,poid) \
        pkcs8_decrypt_unicode(epk,pp,pk,par,poid)
#else
#define pkcs8_decrypt(epk,pp,pk,par,poid) \
        pkcs8_decrypt_ascii(epk,pp,pk,par,poid)
#endif


/* Function:    <pkcs8_decrypt_with_rebuilddata_ascii>
 * Summary:     Decrypts a PKCS#8 key. Keeps enough data to reencrypt it.
 * Syntax:      int rval = pkcs8_decrypt_with_rebuilddata_ascii
 *               (ut_mblk *encryptedPrivateKey, ut_mblk *passphrase,
 *                ut_mblk *privateKey, ut_mblk *params, u32 **privateKeyOID,
 *                ut_mblk *salt, int *count, u32 **pbeAlgOid);
 * Description: The pkcs8_decrypt_with_rebuilddata_ascii() function reads a 
 *              PKCS#8 format private key, decrypts it with the
 *              specified passphrase, and extracts enough information
 *              to enable the developer to re-encrypt the private key
 *              using exactly the same encryption parameters. The
 *              function takes the following parameters:
 *              encryptedPrivateKey -- holds the input encrypted private
 *                key;
 *              passphrase -- passphrase->data contains the passphrase.
 *                passphrase->used contains the length of the passphrase
 *                in octets. The function expects passphrase->data to be a
 *                sequence of 8-bit characters. It converts this string to a
 *                big-endian 16-bit Unicode representation using 
 *                ut_ascii2bmp().
 *              privateKey -- on success, holds the private key data.
 *              privateKeyOID -- on success, holds the algid_objid identifying 
 *                the private key.
 *              params -- on success, holds parameters associated 
 *                with the private key (if any).
 *              salt -- on success, holds the salt data used to generate
 *                the key-encryption key.
 *              count -- on success, holds the iteration count used in 
 *                generating the key-encryption key.
 *              pbeAlgOid -- on success, holds the algid_objid
 *                identifying the PBE encryption algorithm used to
 *                encrypt the private key.
 * Returns:     This function returns 0 on success, -1 on failure. Failure
 *              is caused by lack of memory, null parameters, unrecognized
 *              pbeAlgId or badly formatted input data.
 * Memory:      Dispose of the memory allocated by this function
 *              as follows:
 *           (code)
 *              ut_dispose_mem(privateKey->data);
 *              if (params->data)
 *                ut_dispose_mem(params->data);
 *              ut_dispose_mem(salt->data);
 *              algid_dispose_objid(*privateKeyOID);
 *              algid_dispose_objid(*pbeAlgOID);
 *           (/code)
 * Notes:       The function will correctly decrypt any PKCS#8 formatted
 *              encrypted private key. It's up to the developer to check the
 *              privateKeyOID to make sure that the returned key was for the
 *              algorithm identifier. The parameters in PKCS#8 are encoded
 *              in an ASN.1 OCTET STRING; the data returned in params
 *              is the contents of the OCTET STRING (ie with the header and 
 *              length fields left off).
 *
 *              The key is assumed to be DER-encoded, ie no indefinite-length.
 *            
 *              pkcs8_decrypt_with_rebuilddata() is defined as a macro. If 
 *              _UNICODE is defined it wraps 
 *              pkcs8_decrypt_with_rebuilddata_unicode(). If _UNICODE is not
 *              defined it wraps pkcs8_decrypt_with_rebuilddata_ascii().
 */
int
pkcs8_decrypt_with_rebuilddata_ascii(ut_mblk *encryptedPrivateKey,
   ut_mblk *passphrase, ut_mblk *privateKey, ut_mblk *params, 
   u32 **privateKeyOID, ut_mblk *salt, int *count, u32 **pbeAlgOid);

/* Function:    <pkcs8_decrypt_with_rebuilddata_unicode>
 * Summary:     Decrypts a PKCS#8 key. Keeps enough data to reencrypt it.
 * Syntax:      int rval = pkcs8_decrypt_with_rebuilddata_unicode
 *               (ut_mblk *encryptedPrivateKey, ut_mblk *passphrase,
 *                ut_mblk *privateKey, ut_mblk *params, u32 **privateKeyOID,
 *                ut_mblk *salt, int *count, u32 **pbeAlgOid);
 * Description: The pkcs8_decrypt_with_rebuilddata_unicode() function reads a 
 *              PKCS#8 format private key, decrypts it with the
 *              specified passphrase, and extracts enough information
 *              to enable the developer to re-encrypt the private key
 *              using exactly the same encryption parameters. The
 *              function takes the following parameters:
 *              encryptedPrivateKey -- holds the input encrypted private
 *                key;
 *              passphrase -- passphrase->data contains the passphrase.
 *                passphrase->used contains the length of the passphrase
 *                in octets. The function expects passphrase->data to be a
 *                16-bit Unicode string in big-endian byte order, *NOT* an
 *                array of wchar_t in host byte order.
 *              privateKey -- on success, holds the private key data.
 *              privateKeyOID -- on success, holds the algid_objid identifying 
 *                the private key.
 *              params -- on success, holds parameters associated 
 *                with the private key (if any).
 *              salt -- on success, holds the salt data used to generate
 *                the key-encryption key.
 *              count -- on success, holds the iteration count used in 
 *                generating the key-encryption key.
 *              pbeAlgOid -- on success, holds the algid_objid
 *                identifying the PBE encryption algorithm used to
 *                encrypt the private key.
 * Returns:     This function returns 0 on success, -1 on failure. Failure
 *              is caused by lack of memory, null parameters, unrecognized
 *              pbeAlgId or badly formatted input data.
 * Memory:      Dispose of the memory allocated by this function
 *              as follows:
 *           (code)
 *              ut_dispose_mem(privateKey->data);
 *              if (params->data)
 *                ut_dispose_mem(params->data);
 *              ut_dispose_mem(salt->data);
 *              algid_dispose_objid(*privateKeyOID);
 *              algid_dispose_objid(*pbeAlgOID);
 *           (/code)
 * Notes:       The function will correctly decrypt any PKCS#8 formatted
 *              encrypted private key. It's up to the developer to check the
 *              privateKeyOID to make sure that the returned key was for the
 *              algorithm identifier. The parameters in PKCS#8 are encoded
 *              in an ASN.1 OCTET STRING; the data returned in params
 *              is the contents of the OCTET STRING (ie with the header and 
 *              length fields left off).
 *
 *              The key is assumed to be DER-encoded, ie no indefinite-length.
 *       
 *              pkcs8_decrypt_with_rebuilddata() is defined as a macro. If 
 *              _UNICODE is defined it wraps 
 *              pkcs8_decrypt_with_rebuilddata_unicode(). If _UNICODE is not
 *              defined it wraps pkcs8_decrypt_with_rebuilddata_ascii().
 */
int
pkcs8_decrypt_with_rebuilddata_unicode(ut_mblk *encryptedPrivateKey,
   ut_mblk *passphrase, ut_mblk *privateKey, ut_mblk *params, 
   u32 **privateKeyOID, ut_mblk *salt, int *count, u32 **pbeAlgOid);

/* Function:    <pkcs8_decrypt_with_rebuilddata>
 * Summary:     Decrypts a PKCS#8 key. Keeps enough data to reencrypt it.
 * Description: pkcs8_decrypt_with_rebuilddata() is defined as a macro. If 
 *              _UNICODE is defined it wraps 
 *              pkcs8_decrypt_with_rebuilddata_unicode(). If _UNICODE is not
 *              defined it wraps pkcs8_decrypt_with_rebuilddata_ascii()
 * Notes:       See pkcs8_pkcs8_decrypt_with_rebuilddata_unicode() and 
 *              pkcs8_decrypt_with_rebuilddata_ascii().
 */
#ifdef _UNICODE
#define pkcs8_decrypt_with_rebuilddata(epk,pp,pk,par,poid,s,c,paid) \
        pkcs8_decrypt_with_rebuilddata_unicode(epk,pp,pk,par,poid,s,c,paid)
#else
#define pkcs8_decrypt_with_rebuilddata(epk,pp,pk,par,poid,s,c,paid) \
        pkcs8_decrypt_with_rebuilddata_ascii(epk,pp,pk,par,poid,s,c,paid)
#endif

/* Function:    <pkcs8_convert_cstv7_1_ascii>
 * Summary:     Ensures data is encrypted with standard PKCS#12 PBE.
 * Syntax:      int rval = pkcs8_convert_cstv7_1_ascii(ut_mblk *input, 
 *                ut_mblk *passphrase, ut_mblk *output);
 * Description: The pkcs8_convert_cstv7_1_ascii() function decrypts a
 *              PKCS#8 encrypted private key produced by CST v7.1 and
 *              earlier and re-encrypts it with the correct
 *              implementation of the same PBE algorithm. It corrects a
 *              bug in CST v7.1 and earlier which led to 3-key Triple
 *              DES PKCS#12 encrypted data being incorrectly encrypted
 *              in rare cases.
 *
 *              passphrase->data contains the passphrase.
 *              passphrase->used contains the length of the passphrase
 *              in octets. The function expects passphrase->data to be a
 *              sequence of 8-bit characters. It converts this string to a
 *              big-endian 16-bit Unicode representation using ut_ascii2bmp().
 * Returns:     This function returns 0 on success or -1 on failure
 *              (couldn't decrypt original data).
 * Memory:      Dispose of the memory allocated by this function
 *              as follows:
 *           (code)
 *              ut_dispose_mem(output->data);
 *           (/code)
 * Notes:       pkcs8_convert_cstv7_1() is defined as a macro. If _UNICODE is
 *              defined it wraps pkcs8_convert_cstv7_1_unicode(). If _UNICODE
 *              is not defined it wraps pkcs8_convert_cstv7_1_ascii().
 */
int
pkcs8_convert_cstv7_1_ascii(ut_mblk *input, ut_mblk *passphrase, ut_mblk *output);

/* Function:    <pkcs8_convert_cstv7_1_unicode>
 * Summary:     Ensures data is encrypted with standard PKCS#12 PBE.
 * Syntax:      int rval = pkcs8_convert_cstv7_1_unicode(ut_mblk *input, 
 *                ut_mblk *passphrase, ut_mblk *output);
 * Description: The pkcs8_convert_cstv7_1_unicode() function decrypts a
 *              PKCS#8 encrypted private key produced by CST v7.1 and
 *              earlier and re-encrypts it with the correct
 *              implementation of the same PBE algorithm. It corrects a
 *              bug in CST v7.1 and earlier which led to 3-key Triple
 *              DES PKCS#12 encrypted data being incorrectly encrypted
 *              in rare cases.
 *
 *              passphrase->data contains the passphrase.
 *              passphrase->used contains the length of the passphrase
 *              in octets. The function expects passphrase->data to be a
 *              16-bit Unicode string in big-endian byte order, *NOT* an
 *              array of wchar_t in host byte order.
 * Returns:     This function returns 0 on success or -1 on failure
 *              (couldn't decrypt original data).
 * Memory:      Dispose of the memory allocated by this function
 *              as follows:
 *           (code)
 *              ut_dispose_mem(output->data);
 *           (/code)
 * Notes:       pkcs8_convert_cstv7_1() is defined as a macro. If _UNICODE is
 *              defined it wraps pkcs8_convert_cstv7_1_unicode(). If _UNICODE
 *              is not defined it wraps pkcs8_convert_cstv7_1_ascii().             
 */
int
pkcs8_convert_cstv7_1_unicode(ut_mblk *input, ut_mblk *passphrase, ut_mblk *output);

/* Function:    <pkcs8_convert_cstv7_1>
 * Summary:     Ensures data is encrypted with standard PKCS#12 PBE.
 * Description: pkcs8_convert_cstv7_1() is defined as a macro. If _UNICODE is
 *              defined it wraps pkcs8_convert_cstv7_1_unicode(). If _UNICODE
 *              is not defined it wraps pkcs8_convert_cstv7_1_ascii().
 * Notes:       See pkcs8_convert_cstv7_1_unicode() and 
 *              pkcs8_convert_cstv7_1_ascii().
 */
#ifdef _UNICODE
#define pkcs8_convert_cstv7_1(i, p, o) pkcs8_convert_cstv7_1_unicode(i, p, o)
#else
#define pkcs8_convert_cstv7_1(i, p, o) pkcs8_convert_cstv7_1_ascii(i, p, o)
#endif

#ifdef __cplusplus
}
#endif

#endif /* def WITH_pbe_pbe */

#endif /* ndef _PKCS8_H */
