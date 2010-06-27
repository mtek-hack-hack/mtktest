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
 * sec_cfg.h
 *
 * Created by Lone Koch, 2002.
 *
 * Revision history:
 *
 */
#ifndef _sec_cfg_h
#define _sec_cfg_h

/* Define whether to use the Software WIM or not */
#define SEC_CFG_SWWIM

/* Define if TLS, WTLS or both will be used */
/* At least one must be defined */
#define SEC_CFG_WTLS
#ifdef WAP2
#define SEC_CFG_TLS
#endif

#ifdef SEC_CFG_TLS
/* Define if SSL will be used */
  #define SEC_CFG_SSL
#endif

#ifdef SEC_CFG_WTLS
/* Precisely one of the following macros must be defined */
  /*#define SEC_CFG_WTLS_CLASS_1*/
  #define SEC_CFG_WTLS_CLASS_2
  /*#define SEC_CFG_WTLS_CLASS_3*/
#endif
/* Define which symmetric algorithm to use when                     */
/* encrypting/decrypting data. At least one must be defined.        */
/* If SEC_CFG_TLS is defined SEC_CFG_3DES_CBC_EDE or SEC_CFG_RC4    */
/* must be defined. If SEC_CFG_WTLS is defined SEC_CFG_3DES_CBC_EDE */
/* or USE_RC5 must be defined.                                      */
#ifdef RC5_SUPPORT
#define SEC_CFG_RC5_CBC
#endif
#define SEC_CFG_3DES_CBC_EDE
#ifdef SEC_CFG_TLS
#define SEC_CFG_RC4
#endif
/* Define if TLS_DHE_DSS_WITH_3DES_EDE_CBC_SHA will be  */
/* used along with TLS_RSA_WITH_3DES_EDE_CBC_SHA in TLS */
/* If SEC_CFG_DHE_DSS is defined SEC_CFG_3DES_CBC_EDE   */
/* must be defined.                                     */
#define SEC_CFG_DHE_DSS

/* Define the length in bits of the modulus of the generated */
/* RSA or DSA keys. Typical values will be 1024 and 2048.    */
#define SEC_RSA_KEY_SIZE	  1024
#ifdef SEC_CFG_DHE_DSS
	#define SEC_DSA_KEY_SIZE	1024
#endif

/* Define which symmetric algorithm to use when encrypting */
/* and decrypting internally stored data.                  */
/* Precisely one of the following macros must be defined   */
/*#define SEC_CFG_RC5_CBC_INTERN*/
#define SEC_CFG_3DES_CBC_EDE_INTERN
/*#define SEC_CFG_RC4_INTERN*/

/*Define if MD2 is allowed to be used as a hash algorithm*/
#define SEC_CFG_MD2

/* Define maximum number of user certificates.                      */
/* The value of this constant should also include the homemade      */
/* certificates that only contains the user's public keys.          */
/* If the user has stored SEC_USER_CERT_MAX_SIZE user certificates, */
/* no new keys can be generated until a certificate has been        */
/* deleted. Must be > 0 and < 256.                                  */
#define SEC_USER_CERT_MAX_SIZE	5

/* Define if a certificate or the URL of a certificate should be returned */
/* Note: not applicable in this version of the Security Package           */
/*#define SEC_CFG_RETURN_URL_TO_CERT*/

/* Define if keyId in SEC_SIG_WTLS_GET_METHODS_RESPONSE or       */
/* SEC_SIG_WTLS_GET_CLIENT_CERT_RESPONSE should be returned with */
/* Identifier as key_hash_sha (otherwise text is returned for    */
/* WTLS certificates and x509_name for X.509 certificates)       */
#define SEC_CFG_WTLS_RETURN_PUBLIC_KEY_HASH

/* Define if it should only be possible to download */
/* CA certificates that are root certificates, i.e. */
/* selfsigned certificates                          */
#define SEC_CFG_ONLY_ROOT

/* Define if the extension "T=ca" is checked in the server WTLS */
/* certificate that is used in a WTLS secure session. If        */
/* SEC_CFG_TITLE_MUST_EXIST is defined no session will be set   */
/* if the certificate is a non-root certificate and "T=ca" is   */
/* not present in the issuer in the certificate                 */
/* (see the WAP TLS spec).                                      */
/*#define SEC_CFG_TITLE_MUST_EXIST */

/* Define the friendly name of the homemade WTLS authentication */
/*  certificate(s) only containing a public key                 */
#define SEC_PUB_KEY_CERT_NAME_AUT "My public key certificate, authentication"
/* Define the length of SEC_PUB_KEY_CERT_NAME_AUT in bytes.     */
/* Must be > 0.                                                 */
#define SEC_PUB_KEY_CERT_NAME_AUT_LEN     41
/* Define the character set of the SEC_PUB_KEY_CERT_NAME_AUT.   */
/* Must be mapped to the IANA defined character set             */
#define SEC_PUB_KEY_CERT_NAME_AUT_CHARSET 4

/* Define the friendly name of the homemade WTLS non-repudiation */
/*  certificate(s) only containing a public key                  */
#define SEC_PUB_KEY_CERT_NAME_NP "My public key certificate, non-repudiation"
/* Define the length of SEC_PUB_KEY_CERT_NAME_NP in bytes.       */
/* Must be > 0.                                                  */
#define SEC_PUB_KEY_CERT_NAME_NP_LEN     42
/* Define the character set of the SEC_PUB_KEY_CERT_NAME_NP.     */
/* Must be mapped to the IANA defined character set              */
#define SEC_PUB_KEY_CERT_NAME_NP_CHARSET 4

/* Define how many sessions we can save data to, must be > 0 and < 256 */
#define SEC_SESSION_CACHE_SIZE 1/*10*/
#define SEC_PEER_CACHE_SIZE SEC_SESSION_CACHE_SIZE


/* Define whether the certificates verified in handshakes should be		   */ 
/* stored in database/file or not. If not, the verified certificates	   */
/* are only stored as global variables. Thus no certificate will be		   */
/* returned in SECif_getCurrentCert after	an abbreviated handshake if    */
/* the browser has been switched off since the full handshake	took place */
//#define SEC_CFG_STORE_LAST_VERIFIED_CERT

/* Define if a dialog asking the user if the user wants to make an  */
/* anonymous handshake or abort handshake when the CA certificate   */
/* could not be verified (used in TLS/SSL and WTLS).                */
#define SEC_CFG_CONN_WITHOUT_CERT_DLG

/* Define whether to show Security Package warnings to the user */
//#define SEC_CFG_SHOW_WARNINGS

/* Define whether to alert the user that a key does not exists      */
/* only when openeing the WIM and performing SignText or more often */
#ifdef SEC_CFG_SHOW_WARNINGS
  /*#define SEC_CFG_EXTRA_MISSING_KEY_ERROR_CALLS*/
#endif

/* Define WMLScript Crypto-function SignText*/
//#define SEC_CFG_CAN_SIGN_TEXT

/* Define if the signed contracts should be stored */
#ifdef SEC_CFG_CAN_SIGN_TEXT
  #define SEC_CFG_STORE_CONTRACTS
#endif

/* Content-types for content routing. */
#ifdef WAP_SUPPORT

#define SEC_CFG_CONTENT  "application/vnd.wap.wtls-ca-certificate,\
application/x-x509-ca-cert,\
application/vnd.wap.hashed-certificate,\
application/vnd.wap.signed-certificate"

#else

#define SEC_CFG_CONTENT  "application/vnd.wap.wtls-ca-certificate,\
application/vnd.wap.wtls-user-certificate,\
application/x-x509-user-cert,\
application/x-x509-ca-cert,\
application/vnd.wap.hashed-certificate,\
application/vnd.wap.signed-certificate,\
application/vnd.wap.cert-response"

#endif

/*---------------------------------------------
 * TI handling
 *---------------------------------------------*/

/* The number of characters to show of the friendly */
/* name in a certificate or of the contract.        */
#define SEC_CHARS_TO_SHOW_IN_CERT 10

/* Define how many tries the user gets to   */
/* enter the wrong PIN before it is locked. */
#define SEC_MAX_NBR_PIN_TRIES     3 

/* Define the maximum input length in characters */
#define SEC_MAX_INPUT_LEN         30

/* Define the first x coordinate of the dialogs */
#define SEC_FIRST_X_POS           5/*10*/
/* Define the first y coordinate of the dialogs */
#define SEC_FIRST_Y_POS           5/*10*/

/* View certificate configurations */
#define SEC_CFG_SHOW_COUNTRY_NAME             0x00000001
#define SEC_CFG_SHOW_ORGANISATION_NAME        0x00000002
#define SEC_CFG_SHOW_ORGANISATIONAL_UNIT_NAME 0x00000004
#define SEC_CFG_SHOW_STATE_OR_PROVINCE_NAME   0x00000008
#define SEC_CFG_SHOW_COMMON_NAME              0x00000010
#define SEC_CFG_SHOW_DOMAIN_COMPONENT         0x00000020
#define SEC_CFG_SHOW_SERIAL_NUMBER            0x00000040
#define SEC_CFG_SHOW_DN_QUALIFIER             0x00000080
#define SEC_CFG_SHOW_LOCALITY_NAME            0x00000100
#define SEC_CFG_SHOW_TITLE                    0x00000200
#define SEC_CFG_SHOW_SURNAME                  0x00000400
#define SEC_CFG_SHOW_GIVENNAME                0x00000800
#define SEC_CFG_SHOW_INITIALS                 0x00001000
#define SEC_CFG_SHOW_GENERATION_QUALIFIER     0x00002000
#define SEC_CFG_SHOW_NAME                     0x00004000
#define SEC_CFG_SHOW_EMAIL_ADDRESS            0x00008000
#define SEC_CFG_SHOW_UNKNOWN_ATTRIBUTE_TYPE   0x00010000


/*---------------------------------------------
 * PIN handling
 *---------------------------------------------*/

/* Define maximum number of characters in the PIN (in char) */
#define SEC_PIN_MAX_SIZE 20

/* Define minimum number of characters in the PIN (in char) */
#define SEC_PIN_MIN_SIZE 4

/* define when to ask the user to enter PIN code */
/* if nothing else it is done                    */
/*  - 1st time the WIM is used                   */
/*  - each time SignText is used                 */
/*  - each time a root/CA certificate is stored  */
/*  - each time a private key is generated       */
/*#define SEC_CFG_PIN_CONNECT*/   /* enter PIN code each time a        */
                                  /* connection to a gateway is set up */
//#define SEC_CFG_PIN_DELETE_CERT   /* enter PIN code each time a        */
                                  /* certificate is removed            */

/* Define if PUK is used. Blocking and unblocking is */
/* handled by the TI. If SEC_CFG_PUK is defined, a   */
/* PUK has to be stored on the WIM/in the FILE API.  */
/*#define SEC_CFG_PUK*/

/* Define if user verification with the PUK should be used before */
/* permanently deleting all authentication or non-repudiation     */
/* user keys and connected user certificates .                    */
#ifdef SEC_CFG_PUK
  #define SEC_CFG_DELETE_KEY_VER
#endif

/* Define if the crypto lib shall use big or little endian. */
/* For big endian set the define to 1 and for little endian */
/* set it to 0. If not defined at all the crypto lib will   */
/* try to automaticly detect if big or little endian shall  */
/* be used*/
/*
#define WORDS_BIGENDIAN (1)
*/
/*** The following constant MUST be defined ***/

/* Define not in debug mode. Used in the cryptographic library */
#ifndef NDEBUG
#define NDEBUG
#endif    

#ifdef SEC_CFG_TLS
  #ifndef SEC_CFG_3DES_CBC_EDE
    #ifndef SEC_CFG_RC4
      #define SEC_CFG_3DES_CBC_EDE
    #endif
  #endif
#endif

#ifdef SEC_CFG_WTLS
  #ifndef SEC_CFG_3DES_CBC_EDE
    #ifndef SEC_CFG_RC5_CBC
      #define SEC_CFG_3DES_CBC_EDE
    #endif
  #endif
#endif



#endif /*_sec_cfg_h*/
