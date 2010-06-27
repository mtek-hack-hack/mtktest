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

#ifndef _CST_PKCS12T_H    /* prevent multiple inclusion */
#define _CST_PKCS12T_H

#include "ut.h"
#include "prng.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Error values
 */

#define PKCS12_SUCCESS     (0)
#define PKCS12_NOPARAM     (-2)   /* missing parameters -- only in debug mode */
#define PKCS12_INTRNL      (-1)   /* internal error which we don't explain */
#define PKCS12_NOMEM       (1)    /* out of memory */
#define PKCS12_MISSING     (2)    /* operation requires data to be
                                   * present which hasn't been set */
#define PKCS12_CANTADD     (3)    /* operation is attempting to add
                                   * data, but the object is in an
                                   * inappropriate state to have data of
                                   * that type added */
#define PKCS12_ASN1        (4)    /* ASN.1 encoding or decoding problem */


/* error number */

#define PKCS12_EBASE   (0x07000000)

/* Type:        <pkcs12_obj>
 * Summary:     Pointer to a sequence of SafeContents
 * Description: A pkcs12_obj is an object that we manipulate with the calls
 *              below. The pkcs12_obj includes an integrity check, which 
 *              consists of either a signature or a keyed hash (HMAC). 
 */
typedef struct pkcs12_obj_s *pkcs12_obj;

/* Type:        <pkcs12_IntMode>
 * Summary:     The integrity mode
 * Description: Specifies if the integrity of the PKCS#12 object is checked
 *              by a passphrase-based HMAC (password integrity
 *              mode) or by signing it (public-key integrity mode).
 */
typedef enum {
  PKCS12_INTMODE_UNSUP = 0,  /* Error Value */
  PKCS12_INTMODE_PASSWD,     /* Passphrase-based integrity */
  PKCS12_INTMODE_PUBKEY,     /* Signed data */
  PKCS12_INTMODE_MAX
} pkcs12_IntMode;


/* Type:        <pkcs12_MacAlgId>
 * Summary:     Algorithms which can be used for password-based integrity on
 *              the entire PKCS#12 object
 * Notes:       Currently only SHA-1 is permitted by the standard. This enum
 *              is defined in case things change in the future.
 */
typedef enum {
  PKCS12_MACALGID_UNSUP = 0, /* Error value -- unsupported MAC algorithm */
  PKCS12_MACALGID_SHA1,
  PKCS12_MACALGID_MAX
} pkcs12_MacAlgId;


/* Type:        <pkcs12_SafeContents>
 * Summary:     Pointer to a sequence of SafeBags
 * Description: The SafeContents level is the level at which encryption is
 *              usually applied in PKCS#12. In other words, rather than storing
 *              your PKCS#8 encrypted private key in a SafeBag, you put your 
 *              plaintext private key in a SafeBag, put the SafeBag in a 
 *              SafeContents and encrypt the SafeContents.
 */
typedef struct pkcs12_SafeContents_s *pkcs12_SafeContents;


/* Type:        <pkcs12_SafeContentsType>
 * Summary:     Type of data in a SafeContents
 * Description: This can be unencrypted, encrypted with passphrase-based 
 *              encryption or encrypted ("enveloped") with a public key.
 *              Currently, we produce plaintext or encrypted (but not 
 *              enveloped) data and read plaintext or encrypted (but not 
 *              enveloped) data.
 */
typedef enum {
  PKCS12_SAFECON_UNSUP = 0,
  PKCS12_SAFECON_DATA,       /* unencrypted */
  PKCS12_SAFECON_ENCR,       /* encrypted with passphrase */
  PKCS12_SAFECON_ENVL,       /* enveloped with public key */
  PKCS12_SAFECON_MAX
} pkcs12_SafeContentsType;


/* Type:        <pkcs12_SafeContentsType>
 * Summary:     Algorithms that can be used to encrypt a SafeContents using
 *              passphrase-based encryption
 * Notes:       All the PKCS#12 algids use SHA-1 to derive the key from the
 *              passphrase.
 */
typedef enum {
  PKCS12_PBEALGID_UNSUP = 0, /* Error value -- unsupported PBE algorithm */
  PKCS12_PBEALGID_128RC4,    /* 128-bit RC4 */
  PKCS12_PBEALGID_40RC4,     /* 40-bit RC4 */
  PKCS12_PBEALGID_3KEY3DES,  /* Three-key Triple DES-EDE in CBC mode */
  PKCS12_PBEALGID_2KEY3DES,  /* Two-key Triple DES-EDE in CBC mode */
  PKCS12_PBEALGID_128RC2,    /* 128-bit RC2 in CBC mode */
  PKCS12_PBEALGID_40RC2,     /* 40-bit RC2 in CBC mode */
  PKCS12_PBEALGID_MAX
} pkcs12_PbeAlgId;


/* Type:        <pkcs12_SafeBag>
 * Summary:     A wrapper for your identity information
 * Description: A pkcs12_SafeBag is a wrapper for your key, your encrypted key, 
 *              your certificate, a further SafeCOntents or any additional 
 *              identity information you wish to store.
 */
typedef struct pkcs12_SafeBag_s *pkcs12_SafeBag;



/* Type:        <pkcs12_SafeBagType>
 * Summary:     Type of SafeBag
 * Description: Technically, there are six different things that can go in a SafeBag:
 *                - a KeyBag;
 *                - a PKCS-8ShroudedKeyBag;
 *                - a CertBag;
 *                - a CRLBag;
 *                - a SecretBag;
 *                - a SafeContentsBag.
 *
 *              We have chosen only to implement the first three of these, as they are all 
 *              most people will want.
 *                - a KeyBag contains an unencrypted private key. 
 *                - a PKCS-8ShroudedKeyBag contains an encrypted private key. This
 *                  should probably never be used; instead use a KeyBag and encrypt the
 *                  SafeContents containing the KeyBag.
 *                - a CertBag contains a chain of certs, stored as a .p7c file.
 *
 *              For the sake of completeness, we record that:
 *                - a CRLBag contains a CRL;
 *                - a SafeContentsBag contains a further SafeContents;
 *                - a SecretBag contains any other secret you like.
 */
typedef enum {
  PKCS12_BAGTYPE_UNSUP = 0,  /* Error value */
  PKCS12_BAGTYPE_NONE,       /* Not yet set */
  PKCS12_BAGTYPE_KEY,        /* KeyBag */
  PKCS12_BAGTYPE_SHRDKEY,    /* PKCS-8 ShroudedKeyBag */
  PKCS12_BAGTYPE_CERT,       /* CertBag */
  PKCS12_BAGTYPE_CRL,        /* CRLBag */
  PKCS12_BAGTYPE_SECRET,     /* SecretBag */
  PKCS12_BAGTYPE_SAFECON,    /* SafeContentsBag */
  PKCS12_BAGTYPE_MAX
} pkcs12_SafeBagType;


/* Type:        <pkcs12_SafeBagContents>
 * Summary:     Pointer to a pkcs12_SafeBagContents_s
 * Notes:       When inserting a KeyBag, a ShroudedKeyBag, or a CertBag
 *              into a SafeBag, they need to be cast to a SafeBagContents.
 */
typedef struct pkcs12_SafeBagContents_s *pkcs12_SafeBagContents;

/* Type:        <pkcs12_KeyBag>
 * Summary:     Pointer to a pkcs12_KeyBag_s
 * Notes:       When inserting a KeyBag, a ShroudedKeyBag, or a CertBag
 *              into a SafeBag, they need to be cast to a SafeBagContents.
 */
typedef struct pkcs12_KeyBag_s *pkcs12_KeyBag;

/* Type:        <pkcs12_ShroudedKeyBag>
 * Summary:     Pointer to a pkcs12_ShroudedKeyBag_s
 * Notes:       When inserting a KeyBag, a ShroudedKeyBag, or a CertBag
 *              into a SafeBag, they need to be cast to a SafeBagContents.
 */
typedef struct pkcs12_ShroudedKeyBag_s *pkcs12_ShroudedKeyBag;

/* Type:        <pkcs12_CertBag>
 * Summary:     Pointer to a pkcs12_CertBag_s
 * Notes:       When inserting a KeyBag, a ShroudedKeyBag, or a CertBag
 *              into a SafeBag, they need to be cast to a SafeBagContents.
 */
typedef struct pkcs12_CertBag_s *pkcs12_CertBag;


/* Type:        <pkcs12_AttributeType>
 * Summary:     Type of attribute
 * Description: Each bag contents has an associated set of zero or more 
 *              optional attributes. One of these attributes is the 
 *              "friendly name". This is a BMP (Unicode) string which 
 *              describes the contents of the SafeBag. Netscape REQUIRES that
 *              certs in a SafeBag have an associated friendly name, or it
 *              cannot import them.
 *
 *              Another attribute is the "local key ID". This is simply an
 *              octet string. However, the same octet string can be associated
 *              with both a given key and a given certificate so you can link 
 *              one with the other.
 */
typedef enum {
  PKCS12_ATTRTYPE_UNSUP = 0, /* Error value */
  PKCS12_ATTRTYPE_FNAME,     /* Friendly name */
  PKCS12_ATTRTYPE_KEYID,     /* Local Key ID */
  PKCS12_ATTRTYPE_MAX
} pkcs12_AttributeType;


/* Type:        <pkcs12_KeyAlgId>
 * Summary:     The algorithms for which keys may be stored in a pkcs12_KeyBag
 *              or pkcs12_ShroudedKeyBag
 */
typedef enum {
  PKCS12_KEYALGID_NOKEY = -1, /* No key in key bag */
  PKCS12_KEYALGID_UNSUP = 0,  /* Error value -- unsupported key algorithm */
  PKCS12_KEYALGID_RSA,
  PKCS12_KEYALGID_DSA,
  PKCS12_KEYALGID_X942DH,
#ifdef WITH_sb_ecdsa
  PKCS12_KEYALGID_ECDSA,
  PKCS12_KEYALGID_ECDSA_SB131A01,
  PKCS12_KEYALGID_ECDSA_SB163A01,
  PKCS12_KEYALGID_ECDSA_SB239A01,
  PKCS12_KEYALGID_ECDSA_SB131B01,
  PKCS12_KEYALGID_ECDSA_SB155B01,
  PKCS12_KEYALGID_ECDSA_SB163B01,
  PKCS12_KEYALGID_ECDSA_SB191B01,
  PKCS12_KEYALGID_ECDSA_SB210B01,
  PKCS12_KEYALGID_ECDSA_SB239B01,
#endif  /* def WITH_sb_ecdsa */
  PKCS12_KEYALGID_MAX
} pkcs12_KeyAlgId;


/* Type:        <pkcs12_CertBagType>
 * Summary:     Types of certificate that can can be stored in a pkcs12_CertBag
 * Notes:       Curently we only support X.509 certs.
 */
typedef enum {
  PKCS12_CBAGTYPE_UNSUP = 0,  /* Error value */
  PKCS12_CBAGTYPE_X509,       /* X.509 cert */
  PKCS12_CBAGTYPE_SDSI,       /* SDSI cert */
  PKCS12_CBAGTYPE_MAX         
} pkcs12_CertBagType;


#ifdef __cplusplus
}
#endif

#endif /* ndef _CST_PKCS12T_H */
