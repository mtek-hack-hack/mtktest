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

/******************************  
 * NOTES, 23/7/97:
 *  
 * When compiling with Win32:
 * 1) use the preprocessor definition NOCRYPT;
 * 2) include the directory vbcst\include in the include path.
 *  
 * When linking with Win32:
 * 1) Ignore the default library Winadvapi32.lib.
 *  
 * Notes on the usage of each function can be found by its documentation.
 *  
 * When using Visual Basic:
 * 1) It is not possible to pass a NULL byte array from a Visual Basic
 * function. Instead, you should pass the array {N, U, L, L, \0}.
 *  
 * IMPORTANT NOTE:
 * This is a CAPI-like interface to CST. CST is not a Cryptographic
 * Service Provider (CSP) as defined by Microsoft, which leads to
 * some changes in the API. Most notably:
 * 1) GetUserKey is no longer supported -- users' keys are passed
 * around like any other key
 * 2) Because of this, the function CSTSignHash replaces the function
 * CryptSignHash.
 */

#ifndef __VBCST_H__
#define __VBCST_H__
   
#include "config.h" /* for __DOS__ */

#ifdef __DOS__
#  include "windows.h"

#  ifdef  WIN32
#    define WIN16EXP  _stdcall 
#    define SETLASTERROR(x)    SetLastError(x)
#  else   /* WIN16 */
#    define WIN16EXP __export FAR __pascal    
#    define CONST const  
#    define SETLASTERROR(x)  /* (ut_log1(0UL, UT_ACONTINUE, "%ld", x)) */
#  endif

#else /* __DOS__/Not __DOS__ */

#  define WIN16EXP
#  define SETLASTERROR(x)  /* (ut_log1(0UL, UT_ACONTINUE, "%ld", x)) */
#  define CONST const  

#  include "ut.h"  /* for u8, u16, u32, utb */
  typedef u8 BYTE;
  typedef u16 WORD ;
  typedef u32 DWORD;
  typedef char * LPCSTR;
  typedef int BOOL;

#  ifndef TRUE
#  define TRUE (1==1)
#  endif

#  ifndef FALSE
#  define FALSE (1==0)
#  endif

#endif /* def/ndef __DOS__ */

  typedef unsigned long HCRYPTPROV;
  typedef unsigned long HCRYPTKEY;
  typedef unsigned long HCRYPTHASH;

#include "bsapi.h"  /* for bsapi_* structures -- only used in the cst2capi
                     * functions declared at the end of this file */

#ifdef __cplusplus
extern "C" {
#endif

/* * Algorithm IDs and Flags
*/

/* ALG_ID crackers */
#define GET_ALG_CLASS(x)                (x & (7 << 13))
#define GET_ALG_TYPE(x)                 (x & (15 << 9))
#define GET_ALG_SID(x)                  (x & (511))

/* Algorithm classes */
#define ALG_CLASS_ANY                   (0)
#define ALG_CLASS_SIGNATURE             (1 << 13)
#define ALG_CLASS_MSG_ENCRYPT           (2 << 13)
#define ALG_CLASS_DATA_ENCRYPT          (3 << 13)
#define ALG_CLASS_HASH                  (4 << 13)
#define ALG_CLASS_KEY_EXCHANGE          (5 << 13)

/* Algorithm types */
#define ALG_TYPE_ANY                    (0)
#define ALG_TYPE_DSS                    (1 << 9)
#define ALG_TYPE_RSA                    (2 << 9)
#define ALG_TYPE_BLOCK                  (3 << 9)
#define ALG_TYPE_STREAM                 (4 << 9)

/* Generic sub-ids */
#define ALG_SID_ANY                     (0)

/* Some RSA sub-ids  */
#define ALG_SID_RSA_ANY                 0
#define ALG_SID_RSA_PKCS                1
#define ALG_SID_RSA_MSATWORK            2
#define ALG_SID_RSA_ENTRUST             3
#define ALG_SID_RSA_PGP                 4

/* Some DSS sub-ids */
#define ALG_SID_DSS_ANY                 0
#define ALG_SID_DSS_PKCS                1
#define ALG_SID_DSS_DMS                 2

/* Block cipher sub ids */
/* DES sub_ids */
#define ALG_SID_DES                     1
#define ALG_SID_3DES                    3

#define ALG_SID_IDEA                    5

/* RC2 sub-ids */
#define ALG_SID_RC2                     2

/* Stream cipher sub-ids */
#define ALG_SID_RC4                     1
#define ALG_SID_SEAL                    2

/* Hash sub ids */
#define ALG_SID_MD2                     1
#define ALG_SID_MD4                     2
#define ALG_SID_MD5                     3
#define ALG_SID_SHA                     4
#define ALG_SID_MAC                     5

/* Our silly example sub-id */
#define ALG_SID_EXAMPLE                 80

#ifndef ALGIDDEF
#define ALGIDDEF
typedef DWORD ALG_ID;
#endif

/* error Alg_IDs */
#define NTE_BAD_ID                     (NTE_FAIL + 1)
/* algorithm identifier definitions */
#define CALG_MD2        (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_MD2)
#define CALG_MD4        (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_MD4)
#define CALG_MD5        (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_MD5)
#define CALG_SHA        (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_SHA)
#define CALG_MAC        (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_MAC)
#define CALG_RSA_SIGN   (ALG_CLASS_SIGNATURE | ALG_TYPE_RSA | ALG_SID_RSA_ANY)
#define CALG_DSS_SIGN   (ALG_CLASS_SIGNATURE | ALG_TYPE_DSS | ALG_SID_DSS_ANY)
#define CALG_RSA_KEYX   (ALG_CLASS_KEY_EXCHANGE|ALG_TYPE_RSA|ALG_SID_RSA_ANY)
#define CALG_DES        (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_BLOCK|ALG_SID_DES)
#define CALG_RC2        (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_BLOCK|ALG_SID_RC2)
#define CALG_RC4        (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_STREAM|ALG_SID_RC4)
#define CALG_SEAL       (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_STREAM|ALG_SID_SEAL)


/* Algorithm IDS that aren't covered in WINCRYPT.H... */

/* Algorithm sub-ids
 * All of these IDs are 256 + x, where 0 < x < 255; they should
 * therefore not conflict with future versions of wincrypt.h.
 */

#define ALG_SID_RSA          0x101
#define ALG_SID_RSA_512      0x102
#define ALG_SID_RSA_768      0x103
#define ALG_SID_RSA_1024     0x104
#define ALG_SID_RSA_2048     0x105
#define ALG_SID_RSA_4096     0x106
#define ALG_SID_DSS          0x107
#define ALG_SID_DSS_512      0x108
#define ALG_SID_DSS_768      0x109
#define ALG_SID_DSS_1024     0x10a
#define ALG_SID_BSA4         0x10b
#define ALG_SID_BSA5         0x10c
#define ALG_SID_CSTVB60_3DES 0x10d

/* Algorithm IDs: */

#define CALG_RSA       (ALG_CLASS_SIGNATURE | ALG_TYPE_RSA | ALG_SID_RSA)
#define CALG_RSA_512   (ALG_CLASS_SIGNATURE | ALG_TYPE_RSA | ALG_SID_RSA_512)
#define CALG_RSA_768   (ALG_CLASS_SIGNATURE | ALG_TYPE_RSA | ALG_SID_RSA_768)
#define CALG_RSA_1024  (ALG_CLASS_SIGNATURE | ALG_TYPE_RSA | ALG_SID_RSA_1024)
#define CALG_RSA_2048  (ALG_CLASS_SIGNATURE | ALG_TYPE_RSA | ALG_SID_RSA_2048)
#define CALG_RSA_4096  (ALG_CLASS_SIGNATURE | ALG_TYPE_RSA | ALG_SID_RSA_4096)

#define CALG_DSS       (ALG_CLASS_SIGNATURE | ALG_TYPE_DSS | ALG_SID_DSS)
#define CALG_DSS_512   (ALG_CLASS_SIGNATURE | ALG_TYPE_DSS | ALG_SID_DSS_512)
#define CALG_DSS_768   (ALG_CLASS_SIGNATURE | ALG_TYPE_DSS | ALG_SID_DSS_768)
#define CALG_DSS_1024  (ALG_CLASS_SIGNATURE | ALG_TYPE_DSS | ALG_SID_DSS_1024)

#define CALG_3DES      (ALG_CLASS_DATA_ENCRYPT | ALG_TYPE_BLOCK | ALG_SID_3DES)
#define CALG_CSTVB60_3DES \
      (ALG_CLASS_DATA_ENCRYPT | ALG_TYPE_BLOCK | ALG_SID_CSTVB60_3DES)
#define CALG_IDEA      (ALG_CLASS_DATA_ENCRYPT | ALG_TYPE_BLOCK | ALG_SID_IDEA)

#define CALG_BSA4      (ALG_CLASS_DATA_ENCRYPT | ALG_TYPE_STREAM | ALG_SID_BSA4)
#define CALG_BSA5      (ALG_CLASS_DATA_ENCRYPT | ALG_TYPE_STREAM | ALG_SID_BSA5)
  


/* typedef struct _VTableProvStruc { */
/*    FARPROC FuncVerifyImage;             */
/* } VTableProvStruc, *PVTableProvStruc */

/* dwFlags definitions for CryptAquireContext */
#define CRYPT_VERIFYCONTEXT     0xF0000000
#define CRYPT_NEWKEYSET         0x8
#define CRYPT_DELETEKEYSET      0x10

/* dwFlag definitions for CryptGenKey */
#define CRYPT_EXPORTABLE        0x00000001
#define CRYPT_USER_PROTECTED    0x00000002
#define CRYPT_CREATE_SALT       0x00000004
#define CRYPT_UPDATE_KEY        0x00000008

/* exported key blob definitions */
#define SIMPLEBLOB              0x1
#define PUBLICKEYBLOB           0x6
#define PRIVATEKEYBLOB          0x5

#define AT_KEYEXCHANGE          1
#define AT_SIGNATURE            2

#define CRYPT_USERDATA          1

/* dwParam */
#define KP_IV                   1       /* Initialization vector */
#define KP_SALT                 2       /* Salt value */
#define KP_PADDING              3       /* Padding values */
#define KP_MODE                 4       /* Mode of the cipher */
#define KP_MODE_BITS            5       /* Number of bits to feedback */
#define KP_PERMISSIONS          6       /* Key permissions DWORD */
#define KP_ALGID                7       /* Key algorithm */
#define KP_BLOCKLEN             8       /* Block size of the cipher */

/* KP_PADDING */
/* Blockcipher padding */
#define PKCS5_PADDING           1       /* PKCS 5 (sec 6.2) padding method */
#define BDES_PADDING            2

/* Blockcipher padding */
#define PKCS1_PADDING          33       /* PKCS 1 padding */
#define PKCS1NULL_PADDING      34  
#define BRSA_PADDING           35
#define AUTODETECT_PADDING     36

/* KP_MODE */
#define CRYPT_MODE_CBC          1       /* Cipher block chaining */
#define CRYPT_MODE_ECB          2       /* Electronic code book */
#define CRYPT_MODE_OFB          3       /* Output feedback mode */
#define CRYPT_MODE_CFB          4       /* Cipher feedback mode */
#define CRYPT_MODE_CTS          5       /* Ciphertext stealing mode */

/* KP_PERMISSIONS */
#define CRYPT_ENCRYPT           0x0001  /* Allow encryption */
#define CRYPT_DECRYPT           0x0002  /* Allow decryption */
#define CRYPT_EXPORT            0x0004  /* Allow key to be exported */
#define CRYPT_READ              0x0008  /* Allow parameters to be read */
#define CRYPT_WRITE             0x0010  /* Allow parameters to be set */
#define CRYPT_MAC               0x0020  /* Allow MACs to be used with key */

#define HP_ALGID                0x0001  /* Hash algorithm */
#define HP_HASHVAL              0x0002  /* Hash value */
#define HP_HASHSIZE             0x0004  /* Hash value size */

/* Flags for CryptImportKey (non-standard) */
#define IMPORT_CSTVB60          0x0001  /* Importing keys from CST for VB 6.0 */

#define CRYPT_FAILED            FALSE
#define CRYPT_SUCCEED           TRUE

#define RCRYPT_SUCCEEDED(rt)     ((rt) == CRYPT_SUCCEED)
#define RCRYPT_FAILED(rt)        ((rt) == CRYPT_FAILED)


/*********************************************  
 * Initialisation and Shutdown
 *  
 * FUNCTIONS:
 * CSTInitProvider
 * CSTReleaseProvider
 *********************************************/


/* BOOL
 * WIN16EXP
 * CSTInitProvider(
 *   HCRYPTPROV *hProv,
 *   DWORD       dwFlags)
 * 
 * DIFFERENT FROM STANDARD CAPI FUNCTIONALITY
 *
 * This function initializes the CST library as follows:
 * - It turns on critical section protection within the CST library so
 *   it can safely be used in a multithreaded application
 * - It initializes a global random number generator, which can be
 *   seeded with user-obtained seed to provide better randomness within
 *   the library's key generation functions.
 *
 * dwFlags should be NULL. In release mode, dwFlags is ignored. In debug 
 * mode, if dwFlags is non-NULL, an error log from the CST for VB
 * is written to "cstvbapp.log".
 *
 * If you are calling this function you should call it before calling
 * any other CST for VB functions. The HCRYPTPROV returned should be
 * passed to:
 *
 * - CryptGenKey()
 * - CryptGenRandom()
 *
 * If you call this function at the start of your application you must
 * call CSTReleaseProvider() at the end.
 */

BOOL
WIN16EXP
CSTInitProvider(
  HCRYPTPROV *hProv,
  DWORD       dwFlags);


/* BOOL
 * WIN16EXP
 * CSTReleaseProvider(
 *   HCRYPTPROV hProv)
 *
 * DIFFERENT FROM STANDARD CAPI FUNCTIONALITY
 *
 * This function frees all memory associated with the CST library and
 * closes the global random number generator. It must be
 * called if you have previously called CSTInitProvider(), and should
 * not be called otherwise. You must not call any other CST for VB
 * functions after calling this function.
 */

BOOL
WIN16EXP
CSTReleaseProvider(
  HCRYPTPROV hProv);

 

/*********************************************  
 * Random Numbers
 *  
 * FUNCTIONS:
 * CSTSeedRandom
 * CryptGenRandom
 *********************************************/

/* CSTSeedRandom(
 *  HCRYPTPROV hProv, -- the provider. May not be NULL.
 *  DWORD dwLen,      -- the amount of seed data in pbBuffer
 *  BYTE *pbBuffer    -- the location of the seed data.
 * )
 *
 * DIFFERENT FROM STANDARD CAPI FUNCTIONALITY
 *
 * For good randomness in key generation, you should seed the global
 * random number generator beforehand. To do this, you must initialize
 * the generator with CSTInitProvider, pass the HCRYPTPROV that this
 * produces into CSTSeedRandom, and then pass the same HCRYPTPROV to
 * CryptGenKey.
 *
 * The random number generator supplied in this function is the 
 * Blum-Blum-Shub random number generator, which is widely regarded as
 * the most cryptographically secure of commonly used random number
 * generators.
 */


BOOL
WIN16EXP
CSTSeedRandom(
    HCRYPTPROV hProv,
    DWORD dwLen,
    BYTE *pbBuffer);


/* CryptGenRandom(
 *  HCRYPTPROV hProv, -- the provider: can be NULL in this case
 *  DWORD dwLen,      -- the amount of random data to be placed in pbBuffer
 *  BYTE *pbBuffer    -- the location of the random data. Can also contain
 *                       a seed for the random number generator (this is
 *                       highly recommended). If the input data in pbBuffer
 *                       is not to be used for seeding the first byte 
 *                       should be zero. Conversely, if the data is to be
 *                       used for seeding you should ensure that the first
 *                       byte is not zero.
 * )
 *
 * The random number generator supplied in this function is the 
 * Blum-Blum-Shub random number generator, which is widely regarded as
 * the most cryptographically secure of commonly used random number
 * generators. However, it is slow relative to other generators. If
 * you require twenty bytes or less of apparently random data it is 
 * probably faster to collect some seed data and put it through a
 * hashing algorithm such as MD5 or SHA.
 */


BOOL
WIN16EXP
CryptGenRandom(
    HCRYPTPROV hProv,
    DWORD dwLen,
    BYTE *pbBuffer);


/*******************************************  
 * Key Generation
 *  
 * FUNCTIONS:
 * CryptDestroyKey
 * CryptGenKey
 * CryptDeriveKey
 * CryptGetKeyParam
 * CryptSetKeyParam
 *******************************************/

/* CryptGenKey (
 *   HCRYPTPROV hProv, -- the CSP: can be NULL or the CSP returned from
 *                        CSTInitProvider(). We recommend that you use
 *                        the non-null CSP and seed the global random
 *                        number generator using CSTSeedRandom() before
 *                        calling this function.
 *   ALG_ID Algid,     -- the ALG_ID. ALG_IDs are listed in the file
 *                        privcapi.h (C) and privcapi.txt (Visual Basic).
 *                        For a full list of the ALG_IDs supported by
 *                        CST CAPI, see either of these files or the
 *                        first switch(Algid) command below.
 *   DWORD dwFlags,    -- the Flags described in the CAPI reference.
 *                        This field can be NULL. CST CAPI enforces the
 *                        following behavior:
 *                        CRYPT_EXPORTABLE: All keys are exportable.
 *                        CRYPT_CREATE_SALT: Salt is not created.
 *                        CRYPT_USER_PROTECTED: No user protection is set.
 *   HCRYPTKEY *phkey, -- a handle to the capi key. Used only for outputting
 *                        the result of the key generation.
 *  )
 */

BOOL
WIN16EXP
CryptGenKey(
    HCRYPTPROV hProv,
    ALG_ID Algid,
    DWORD dwFlags,
    HCRYPTKEY *phKey);

/* CryptDeriveKey(
 *  HCRYPTPROV hProv,     -- NULL
 *  ALG_ID Algid,         -- Algorithm ID for the key to be generated.
 *                           This must be CALG_DES, CALG_3DES,
 *                           CALG_CSTVB60_3DES, or CALG_IDEA:
 *                           in other words, an algorithm of type ALG_TYPE_
 *                           BLOCK. 
 *  HCRYPTHASH hBaseData, -- A handle to a hash session which must have
 *                           been created with CryptCreateHash and
 *                           primed with the seed data (eg a passphrase)
 *                           using CryptHashData. We cheekily get the
 *                           hash data out of the hash session, use it 
 *                           as the seed to a CST random number generator,
 *                           and feed it into the normal bsapi_generate_key
 *                           routines.
 *  DWORD dwFlags,        -- NULL
 *  HCRYPTKEY *phKey      -- A handle to the key to be created.
 * )
 */

BOOL
WIN16EXP
CryptDeriveKey(
    HCRYPTPROV hProv,
    ALG_ID Algid,
    HCRYPTHASH hBaseData,
    DWORD dwFlags,
    HCRYPTKEY *phKey);

/* CryptDestroyKey(  -- deallocates the memory used by a kset.
 *    HCRYPTKEY hKey
 * )
 */

BOOL
WIN16EXP
CryptDestroyKey(
    HCRYPTKEY hKey);

/* CryptSetKeyParam( -- changes parameters to the encryption process.
 *  HCRYPTKEY hKey,  -- the keyset generated by CryptGenKey
 *  DWORD dwParam,   -- tells the routine how to interpret the data in
 *                      *pbData. Flags are:
 *                      KP_SALT -- ignored by this implementation
 *                      KP_PERMISSIONS -- ignored by this implementation
 *                      KP_IV -- pbData is the initialization vector for 
 *                        CBC, CFB, or OFB modes of DES or IDEA. This 
 *                        initialization vector should be eight bytes long. 
 *                      KP_PADDING -- pbData contains a DWORD specifying
 *                        the padding used. Valid pbDatas depend on the
 *                        algorithm:
 *                        BSA4/BSA5/DSS:
 *                          Ignored.
 *                        RSA:
 *                          PKCS1_PADDING (default)
 *                          PKCS1NULL_PADDING 
 *                          BRSA_PADDING
 *                          AUTODETECT_PADDING
 *                        DES/Triple DES/IDEA:
 *                          PKCS5_PADDING (default)
 *                          BDES_PADDING
 *                        Note that there is rarely any reason not to use
 *                        the default padding algorithm. An attempt to
 *                        specify an inappropriate padding algorithm
 *                        will result in the default one being used.
 *                      KP_MODE -- pbData contains a DWORD specifying the
 *                        encryption mode. Only of use for block ciphers
 *                        DES, Triple DES, and IDEA. Valid pbDatas are:
 *                          CRYPT_MODE_ECB
 *                          CRYPT_MODE_CBC (default)
 *                          CRYPT_MODE_OFB
 *                          CRYPT_MODE_CFB
 *                        Note that CRYPT_MODE_CTS is not supported and
 *                        will result in CRYPT_MODE_CBC being used.
 *                      KP_FEEDBACK -- pbData contains a DWORD specifying
 *                        the number of bits to feed back in CFB or OFB
 *                        mode. The default is 8 bits in CFB, 64 in OFB.
 *                        CryptSetKeyParam should be called with KP_FEEDBACK
 *                        only after it's been called with KP_MODE.
 *  BYTE *pbData,    -- Contains the data. See dwParam for details of what
 *                      should be in here.
 *  DWORD dwFlags    -- should be NULL.
 * )
 */

BOOL
WIN16EXP
CryptSetKeyParam(
    HCRYPTKEY hKey,
    DWORD dwParam,
    BYTE *pbData,
    DWORD dwFlags);

/* CryptGetKeyParam -- the inverse of CryptSetKeyParam above */

BOOL
WIN16EXP
CryptGetKeyParam(
    HCRYPTKEY hKey,
    DWORD dwParam,
    BYTE *pbData,
    DWORD *pdwDataLen,
    DWORD dwFlags);

/********************************************  
 * Key Import/Export
 * 
 * FUNCTIONS:
 * CryptImportKey
 * CryptExportKey
 ********************************************/


/* CryptExportKey(
 *  HCRYPTKEY hKey,    -- a pointer to the key which will be exported
 *  HCRYPTKEY hExpKey, -- The key which is used to encrypt the exported
 *                        key, if it is to be encrypted. This key is 
 *                        produced by CryptDeriveKey.
 *  DWORD dwBlobType,  -- SIMPLEBLOB, PUBLICKEYBLOB or PRIVATEKEYBLOB.
 *                        SIMPLEBLOB should be used if the key being
 *                        exported is from a symmetric algorithm.
 *                        PUBLICKEYBLOB and PRIVATEKEYBLOB should be
 *                        used to export, respectively, the public key
 *                        or the private key from a key for an asymmetric
 *                        algorithm (in this case, only RSA or DSS).
 *                        The public key will not normally be encrypted
 *                        so hExpKey should be NULL if dwBlobType is
 *                        PRIVATEKEYBLOB.
 *  DWORD dwFlags,     -- should be NULL
 *  BYTE *pbData,      -- output data buffer or NULL. If it is NULL, 
 *                        pdwDataLen is returned containing the length
 *                        that the output data will be. If it is
 *                        nonzero, pdwDataLen contains the allocated
 *                        length for the output data. If this length is
 *                        less than the necessary length, the necessary
 *                        length is put in pdwDataLen and the function
 *                        returns FALSE.
 *  DWORD *pdwDataLen  -- allocated length for pbData; see pbData above
 *                        for discussion.
 * )
 */


BOOL
WIN16EXP
CryptExportKey(
    HCRYPTKEY hKey,
    HCRYPTKEY hExpKey,
    DWORD dwBlobType,
    DWORD dwFlags,
    BYTE *pbData,
    DWORD *pdwDataLen);


/* CryptImportKey(
 *  HCRYPTPROV hProv,   -- NULL.
 *  CONST BYTE *pbData, -- contains the data that was passed out
 *                         of CryptExportKey
 *  DWORD dwDataLen,    -- the length of pbData.
 *  HCRYPTKEY hPubKey,  -- the key to be used to decrypt the
 *                         imported key. This can be derived
 *                         from a password, or it can be the
 *                         recipient's private key. Note that
 *                         we do not explicitly support signed
 *                         key blobs.
 *  DWORD dwFlags,      -- Set to IMPORT_CSTVB60 if the key being
 *                         imported was generated using the CST for
 *                         Visual Basic v. 6.0. This will ensure
 *                         interoperability between the different keying
 *                         of Triple DES in CST for VB v 6.0 and
 *                         subsequent releases.
 *  HCRYPTKEY *phKey    -- a handle to the key to be passed out.
 * 
 * DIFFERENT FROM STANDARD CAPI FUNCTIONALITY
 *
 * This function differs from standard CAPI functionality in that it
 * allows the user to specify the flag passed to dwFlags. In standard
 * CAPI this flag must be NULL.
 * )
 */

BOOL
WIN16EXP
CryptImportKey(
    HCRYPTPROV hProv,
    CONST BYTE *pbData,
    DWORD dwDataLen,
    HCRYPTKEY hPubKey,
    DWORD dwFlags,
    HCRYPTKEY *phKey);


/********************************************  
 * Hashing 
 *  
 * FUNCTIONS:
 * CryptCreateHash
 * CryptDestroyHash
 * CryptGetHashParam
 * CryptHashData
 * CryptHashSessionKey
 ********************************************/

/* CryptCreateHash(
 *  HCRYPTPROV hProv,  -- NULL in this implementation
 *  ALG_ID Algid,      -- can be: CALG_MD2, CALG_MD5, or CALG_SHA. Other
 *                        algorithms which are available through the main
 *                        CST interface will be made available through
 *                        CAPI in due course.
 *  HCRYPTKEY hKey,    -- NULL for all currently supported algorithms
 *  DWORD dwFlags,     -- NULL in this implementation
 *  HCRYPTHASH *phHash -- returns a handle to the hash session.
 * )
 */


BOOL
WIN16EXP
CryptCreateHash(
    HCRYPTPROV hProv,
    ALG_ID Algid,
    HCRYPTKEY hKey,
    DWORD dwFlags,
    HCRYPTHASH *phHash);

/* CryptDestroyHash(
 *  HCRYPTHASH hHash  -- Hash session to be shut down.
 * )
 */


BOOL
WIN16EXP
CryptDestroyHash(
    HCRYPTHASH hHash);

/* CryptGetHashParam( -- returns the result of a hash operation.
 *  HCRYPTHASH hHash, -- handle to the hash object
 *  DWORD dwParam,    -- can be:
 *                       HP_ALGID -- returns the Algorithm ID
 *                       HP_HASHSIZE -- returns the size of the output
 *                       HP_HASHVAL -- returns the actual hash.
 *  BYTE *pbData,     -- A container for the data. Must be large enough
 *                       to hold the output.
 *  DWORD *pdwDataLen,-- The size of pbData. Is replaced on exit with the
 *                       size of the data in pbData.
 *  DWORD dwFlags     -- should be NULL.
 * )
 */


BOOL
WIN16EXP
CryptGetHashParam(
    HCRYPTHASH hHash,
    DWORD dwParam,
    BYTE *pbData,
    DWORD *pdwDataLen,
    DWORD dwFlags);

/* CryptHashData(       -- feeds data into a hash session.
 *  HCRYPTHASH hHash,   -- a hash session handle
 *  CONST BYTE *pbData, -- the input data
 *  DWORD dwDataLen,    -- the input data length
 *  DWORD dwFlags       -- should be NULL
 * )
 */


BOOL
WIN16EXP
CryptHashData(
    HCRYPTHASH hHash,
    /* CONST elided */ BYTE *pbData,
    DWORD dwDataLen,
    DWORD dwFlags);

/* CryptHashSessionKey( -- hashes the session key data from a HCRYPTKEY
 *  HCRYPTHASH hHash,   -- the hash session to be used; must have been
 *                         created with CryptCreateHash()
 *  HCRYPTKEY hKey,     -- the session key
 *  DWORD dwFlags       -- should be NULL.
 * )
 *                         NOTE: Although the CAPI manual says that calls
 *                         to CryptHashSessionKey() can be interspersed
 *                         with calls to CryptHashData(), this will of
 *                         course produce a hash of the key and the other
 *                         data concatenated. To get or use a hash of the key
 *                         only you must call one of the four functions
 *                         CryptDeriveKey, CryptGetHashParam, CryptSignHash,
 *                         or CryptVerifySignature without making any calls
 *                         to CryptHashData.
 *  *                         NOTE 2: HashSessionKey doesn't actually care
 *                         whether the key is a session key or not. It will
 *                         hash any private/secret key in the keyset.
 */


BOOL
WIN16EXP
CryptHashSessionKey(
    HCRYPTHASH hHash,
    HCRYPTKEY hKey,
    DWORD dwFlags);

/********************************************  * Encryption/Decryption
 *  * FUNCTIONS:
 * CryptDecrypt
 * CryptEncrypt
 ********************************************/



/* CryptEncrypt(
 *  HCRYPTKEY hKey,    -- the key containing all details necessary for
 *                        performing the encryption
 *  HCRYPTHASH hHash,  -- Should be NULL unless you want to hash the
 *                        plaintext while encrypting it. If you want
 *                        to perform this hash, the hash object must
 *                        have been created with CryptCreateHash.
 *  BOOL Final,        -- Set to TRUE if this is the final block (ie
 *                        if padding is to be performed). Set to FALSE
 *                        or NULL otherwise.
 *  DWORD dwFlags,     -- should be NULL 
 *  BYTE *pbData,      -- contains the input plaintext. The output
 *                        ciphertext is written here as well. Or this
 *                        can be NULL, in which case the function
 *                        merely returns the amount of output that will
 *                        be generated by *pdwDataLen amount of input.
 *  DWORD *pdwDataLen, -- Input: the length of the input data. Output:
 *                        the length of the output data.
 *  DWORD dwBufLen     -- The amount of memory allocated in pbData to
 *                        take the output data.
 * )
 */


BOOL
WIN16EXP
CryptEncrypt(
    HCRYPTKEY hKey,
    HCRYPTHASH hHash,
    BOOL Final,
    DWORD dwFlags,
    BYTE *pbData,
    DWORD *pdwDataLen,
    DWORD dwBufLen);

/* CryptDecrypt(
 *  HCRYPTKEY hKey,   -- the session key, obtained by CryptGenKey or
 *                       CryptImportKey.
 *  HCRYPTHASH hHash, -- Contains a handle to the hash session being
 *                       used. This field need only be filled in if
 *                       you are simultaneously decrypting a message
 *                       and hashing the plaintext. Otherwise it should
 *                       be NULL.
 *  BOOL Final,       -- This flag is TRUE if you are performing the 
 *                       final part of an encryption session, FALSE
 *                       otherwise.
 *  DWORD dwFlags,    -- should be NULL
 *  BYTE *pbData,     -- contains the input data, and has the output
 *                       data written into it. When decrypting, the
 *                       output will never be longer than the input
 *                       so we needn't worry about memory reallocation.
 *  DWORD *pdwDataLen -- is passed in containing the input data length
 *                       and returned containing the output data length.
 * )
 */


BOOL
WIN16EXP
CryptDecrypt(
    HCRYPTKEY hKey,
    HCRYPTHASH hHash,
    BOOL Final,
    DWORD dwFlags,
    BYTE *pbData,
    DWORD *pdwDataLen);

/********************************************  * Sign/Verify 
 *  * FUNCTIONS:
 * CSTSignHash
 * CryptVerifySignature
 ********************************************/

/* Because the CST isn't a full CSP (Cryptographic Service Provider)
 * as described in the CAPI manual, we do not support referencing
 * keys by AT_EXCHANGE and AT_SIGNING. Therefore the interface to
 * signing is slightly different in this implementation than in
 * CAPI. The DWORD dwKeySpec is replaced by a HCRYPTKEY structure.
 */

/* CSTSignHash(
 *  HCRYPTHASH hHash,    -- the hash object. Once the hash has been
 *                          signed the hash object should be destroyed
 *                          with CryptDestroyHash(). 
 *  HCRYPTKEY hKey,      -- the key to be used for encryption
 *  LPCSTR sDescription, -- a description which is hashed with the data
 *                          to be signed.
 *  DWORD dwFlags,       -- NULL
 *  BYTE *pbSignature,   -- An array sufficiently large to contain
 *                          the signature; or NULL, in which case
 *                          pdwSigLen is returned containing the size
 *                          the array should be.
 *  DWORD *pdwSigLen     -- The size allocated for pbSignature.
 * )
 */

     
BOOL
WIN16EXP
CSTSignHash(
    HCRYPTHASH hHash,
    HCRYPTKEY hKey,
    LPCSTR sDescription,
    DWORD dwFlags,
    BYTE *pbSignature,
    DWORD *pdwSigLen);



BOOL
WIN16EXP
CryptVerifySignatureA(
    HCRYPTHASH hHash,
    CONST BYTE *pbSignature,
    DWORD dwSigLen,
    HCRYPTKEY hPubKey,
    LPCSTR sDescription,
    DWORD dwFlags);

/************************************************************************
 *   The following functions are part of CAPI but are not currently 
 *   supported
 ************************************************************************/

BOOL
WIN16EXP
CryptSetHashParam(
    HCRYPTHASH hHash,
    DWORD dwParam,
    BYTE *pbData,
    DWORD dwFlags);


BOOL
WIN16EXP
CryptSetProvParam(
    HCRYPTPROV hProv,
    DWORD dwParam,
    BYTE *pbData,
    DWORD dwFlags);


BOOL
WIN16EXP
CryptGetProvParam(
    HCRYPTPROV hProv,
    DWORD dwParam,
    BYTE *pbData,
    DWORD *pdwDataLen,
    DWORD dwFlags);


BOOL
WIN16EXP
CryptGetUserKey(
    HCRYPTPROV hProv,
    DWORD dwKeySpec,
    HCRYPTKEY *phUserKey);


BOOL
WIN16EXP
CryptGetHashValue(
    HCRYPTHASH hHash,
    DWORD dwFlags,
    BYTE *pbHash,
    DWORD *pdwHashLen);

/****************************************************************************
 * 
 * CST Compatibility functions
 *
 ****************************************************************************/

extern
int
 CST32EXPORTTYPE CST16EXPORTTYPE
CSTExportCapiKeys(
    bsapi_kset *bkeys,
    bsapi_mode *bmode,
    u32 dwBlobType,
    ALG_ID alg_id,
    u8 **ckeys,
    size_t *len);

extern
int
CST32EXPORTTYPE CST16EXPORTTYPE
CSTImportCapiKeys(
    u8 *ckeys,
    size_t len,
    u32 *dwBlobType,
    ALG_ID *alg_id,
    bsapi_kset *bkeys,
    bsapi_mode *bmode);

extern int
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_sharedparams_vb60_des(prng_inst *prng, ut_mblk *shrdpt,
    bsapi_kparam *param);
extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_key_vb60_des(prng_inst *prng, ut_mblk *secpt,
    ut_mblk *pubpt, bsapi_kparam *param);
extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_privatenonce_vb60_des (prng_inst *rand_gen, ut_mblk *pnonce, 
    bsapi_kparam *param);
extern size_t 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_sizeof_iv_vb60_des(bsapi_mode *mode, bsapi_kset *keys);
extern bsapi_id 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_start_vb60_des(bsapi_mode *mode, prng_inst *prngpt,
    bsapi_kset *keys);
extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_append_vb60_des(u8 *data, size_t length, bsapi_id session);
extern ut_mblk_list 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_read_vb60_des(bsapi_id session);
extern ut_mblk_list 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_readmost_vb60_des(bsapi_id session);
extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_finish_vb60_des(bsapi_id session, ut_mblk_list *data);
extern sec_off_t 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_sizeof_output_vb60_des(bsapi_id session, sec_off_t input);
extern void 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_kill_vb60_des(bsapi_id session);
extern const char CST32EXPORTTYPE * CST16EXPORTTYPE
    bsapi_get_name_vb60_des(void);
extern void 
  CST32EXPORTTYPE CST16EXPORTTYPE
    vb60_des_direct(bsapi_id session, u8 *in, u8 *out, size_t len);
extern const bsapi_alg CST32EXPORTDATA CST16EXPORTDATA bsapi_vb60_des;

extern int
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_sharedparams_vb60_triple_des(prng_inst *prng,
    ut_mblk *shrdpt, bsapi_kparam *param);
extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_key_vb60_triple_des(prng_inst *prng, ut_mblk *secpt,
    ut_mblk *pubpt, bsapi_kparam *param);
extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_privatenonce_vb60_triple_des (prng_inst *rand_gen,
    ut_mblk *pnonce, bsapi_kparam *param);
extern size_t 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_sizeof_iv_vb60_triple_des(bsapi_mode *mode, bsapi_kset *keys);
extern bsapi_id 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_start_vb60_triple_des(bsapi_mode *mode, prng_inst *prngpt,
    bsapi_kset *keys);
extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_append_vb60_triple_des(u8 *data, size_t length, bsapi_id session);
extern ut_mblk_list 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_read_vb60_triple_des(bsapi_id session);
extern ut_mblk_list 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_readmost_vb60_triple_des(bsapi_id session);
extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_finish_vb60_triple_des(bsapi_id session, ut_mblk_list *data);
extern sec_off_t 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_sizeof_output_vb60_triple_des(bsapi_id session, sec_off_t input);
extern void 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_kill_vb60_triple_des(bsapi_id session);
extern const char CST32EXPORTTYPE * CST16EXPORTTYPE
    bsapi_get_name_vb60_triple_des(void);
extern void 
  CST32EXPORTTYPE CST16EXPORTTYPE
    vb60_triple_des_direct(bsapi_id session, u8 *in, u8 *out, size_t len);
extern const bsapi_alg CST32EXPORTDATA CST16EXPORTDATA bsapi_vb60_triple_des;

#ifdef __cplusplus
}       /* Balance extern "C" above */
#endif

#endif /* ndef __VBCST_H__ */
