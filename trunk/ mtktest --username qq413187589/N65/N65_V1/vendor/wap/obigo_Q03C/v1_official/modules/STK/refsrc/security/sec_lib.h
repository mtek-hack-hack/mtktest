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
/*
 * sec_lib.h
 *
 * Created by Anna Andréasson, Thu Jun 20, 2002.
 *
 */

#ifndef _sec_lib_h
#define _sec_lib_h

#ifndef _sec_if_h
#include "sec_if.h" /* for sec_key_object etc*/
#endif

#ifndef _msf_def_h
#include "msf_def.h"
#endif

int SEClib_isInitialised(void);
int SEClib_initialise(void);
int SEClib_terminate(void);

/*************************************************************
 * Bulk encryption algorithms
 *************************************************************/

/*
 * Encrypt single-part data.
 * NOTE: Only used for block encryption methods.
 * For block encryption methods, the input plaintext data has certain
 * length constraints. If these constraints are not satisfied, then
 * SEClib_encrypt will fail with return code SEC_ERR_DATA_LENGTH.
 * The ciphertext is always of the same length as the plaintext.
 */
int SEClib_encrypt(sec_cipher_alg cipherAlg, sec_key_object key,
                   const unsigned char *data, int dataLen, 
                   unsigned char *encryptedData);

/*
 * Decrypt single-part data.
 * NOTE: Only used for block decryption methods.
 * For block decryption methods, the input ciphertext has certain
 * length constraints. If these constraints are not satisfied, then
 * SEClib_decrypt will fail with return code SEC_ERR_DATA_LENGTH.
 * The ciphertext is always of the same length as the plaintext.
 */
int SEClib_decrypt(sec_cipher_alg cipherAlg, sec_key_object key,
                   const unsigned char *data, int dataLen,
                   unsigned char *decryptedData);

/*
 * Initialise an encryption operation.
 * NOTE: Only used for stream encryption methods.
 * "cipherAlg" is the encryption algorithm to use,
 * "key" and "keyLen" give the cipher key,
 * and on return "handleptr" will point to a new handle
 * to be used in subsequent operations.
 * After calling SEClib_encryptInit, one calls SEClib_encryptUpdate
 * zero or more times, followed by SEClib_encryptFinal, to encrypt data in
 * multiple parts. The encryption operation is active until one makes
 * a call to SEClib_encryptFinal. To process additional data
 * (in single or multiple parts), one must call SEClib_encryptInit again.
 */
int SEClib_encryptInit(sec_cipher_alg cipherAlg, 
                       const unsigned char *key, int keyLen,
                       sec_cipher_handle *handleptr);

/*
 * Continue a multiple-part encryption operation,
 * processing another data part.
 * "handle" is the handle of the encryption operation,
 * "data" points to the data to be encrypted, and "dataLen"
 * is the length of the plaintext data.
 * The length of the encrypted data is always the same as the length
 * of the plaintext.
 * The encryption operation must have been initialised with SEClib_encryptInit.
 * A call to SEClib_encryptUpdate which results in an error terminates
 * the current encryption operation.
 */
int SEClib_encryptUpdate(sec_cipher_handle handle,
                         const unsigned char *data, int dataLen,
                         unsigned char *encryptedData);

/*
 * Finish a multiple-part encryption operation.
 * The encryption operation must have been initialised with SEClib_encryptInit.
 * A call to SEClib_encryptFinal always terminates the active
 * encryption operation.
 */
int SEClib_encryptFinal(sec_cipher_handle handle);


/*
 * Initialise a decryption operation.
 * NOTE: Only used for stream encryption methods.
 * "cipherAlg" is the decryption algorithm to use,
 * "key" and "keyLen" give the cipher key,
 * and on return "handleptr" will point to a new handle
 * to be used in subsequent operations.
 * After calling SEClib_decryptInit, one calls SEClib_decryptUpdate
 * zero or more times, followed by SEClib_decryptFinal, to decrypt data in
 * multiple parts. The decryption operation is active until one makes
 * a call to SEClib_decryptFinal. To process additional data
 * (in single or multiple parts), one must call SEClib_decryptInit again.
 */
int SEClib_decryptInit(sec_cipher_alg cipherAlg,
                       const unsigned char *key, int keyLen,
                       sec_cipher_handle *handleptr);

/*
 * Continue a multiple-part decryption operation,
 * processing another data part.
 * "handle" is the handle of the decryption operation,
 * "data" points to the data to be decrypted, and "dataLen"
 * is the length of the ciphertext.
 * The length of the decrypted data is always the same as the length
 * of the ciphertext.
 * The decryption operation must have been initialised with SEClib_decryptInit.
 * A call to SEClib_decryptUpdate which results in an error terminates
 * the current decryption operation.
 */
int SEClib_decryptUpdate(sec_cipher_handle handle,
                         const unsigned char *data, int dataLen,
                         unsigned char *decryptedData);

/*
 * Finish a multiple-part decryption operation.
 * The decryption operation must have been initialised with SEClib_decryptInit.
 * A call to SEClib_decryptFinal always terminates the active
 * decryption operation.
 */
int SEClib_decryptFinal(sec_cipher_handle handle);

/************************************************************
 * Secure hash algorithms
 ************************************************************/

/*
 * Compute a hash digest of given single-part data.
 * SEClib_hash is equivalent to a call to SEClib_hashInit, followed
 * by a sequence of SEClib_hashUpdate operations, and terminated
 * by a call to SEClib_hashFinal.
 */
int SEClib_hash (sec_hash_alg alg,
                 const unsigned char *data, int dataLen,
                 unsigned char *digest);

/*
 * Initialise a hash operation.
 * "alg" is the hash algorithm to use, and on return "handleptr"
 * will point to a new handle to be used in subsequent operations.
 * After calling SEClib_hashInit, one calls SEClib_hashUpdate zero or
 * more times, followed by SEClib_hashFinal, to digest data in
 * multiple parts. The hash operation is active until one makes
 * a call to SEClib_hashFinal to actually obtain
 * the final piece of ciphertext. To process additional data
 * (in single or multiple parts), one must call SEClib_hashInit again.
 */
int SEClib_hashInit(sec_hash_alg alg, sec_hash_handle *handleptr);

/*
 * Continue a multiple-part hash operation, processing another data part.
 * "handle" is the handle of the hash operation, "part" points to the
 * data part, and "partLen" is the length of the data part.
 * The hash operation must have been initialised with SEClib_hashInit.
 * A call to SEClib_hashUpdate which results in an error terminates
 * the current hash operation.
 */
int SEClib_hashUpdate(sec_hash_handle handle,
                      const unsigned char *part, int partLen);

/*
 * Finish a multiple-part hash operation.
 * "handle" is the handle of the hash operation, and "digest" is the location
 * that receives the computed message digest.
 * The hash operation must have been initialised with SEClib_hashInit.
 * A call to SEClib_hashFinal always terminates the active hash operation.
 */
int SEClib_hashFinal(sec_hash_handle handle, unsigned char *digest);

/*************************************************************
 * HMAC
 *************************************************************/

/*
 * Initialise a HMAC operation.
 * "alg" is the hash algorithm to use, "key" and "keyLen" give the
 * HMAC key, and on return "handleptr" will point to a new handle
 * to be used in subsequent operations.
 * After calling SEClib_hmacInit, one calls SEClib_hmacUpdate zero or
 * more times, followed by SEClib_hmacFinal, to digest data in
 * multiple parts. The HMAC operation is active until one makes
 * a call to SEClib_hmacFinal to actually obtain
 * the final digest. To process additional data
 * (in single or multiple parts), one must call SEClib_hmacInit again.
 */
int SEClib_hmacInit(sec_hash_alg alg,
                    const unsigned char *key, int keyLen,
                    sec_hmac_handle *handleptr);

/*
 * Continue a multiple-part HMAC operation, processing another data part.
 * "handle" is the handle of the HMAC operation, "part" points to the
 * data part, and "partLen" is the length of the data part.
 * The HMAC operation must have been initialised with SEClib_hmacInit.
 * A call to SEClib_hmacUpdate which results in an error terminates
 * the current HMAC operation.
 */
int SEClib_hmacUpdate(sec_hmac_handle handle,
                      const unsigned char *part, 
                      int partLen);

/*
 * Finish a multiple-part HMAC operation.
 * "handle" is the handle of the HMAC operation, and "digest" is
 * the location that receives the computed digest.
 * The HMAC operation must have been initialised with SEClib_hmacInit.
 * A call to SEClib_hmacFinal always terminates the active HMAC operation.
 */
int SEClib_hmacFinal(sec_hmac_handle handle, unsigned char *digest);


/***********************************************************************
 * Random number generation
 ***********************************************************************/

/* Generate random (or pseudo-random) data. "randomData" points to
 * the location that receives the data and "randomLen" is the number
 * of bytes of data to be generated.
 */
int SEClib_generateRandom (unsigned char *randomData, int randomLen);

int SEClib_sslHashUpdateWMasterSec(sec_hash_handle handle, int masterSecretId);

#endif


