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
 * sec_rc.h
 *
 * Created by Lone Koch, Tue Sep 11, 2002.
 *
 */

#ifndef _sec_rc_h
#define _sec_rc_h

#ifndef _msf_cfg_h
#include "msf_cfg.h"  
#endif

#define SEC_NUMBER_OF_STRINGS 125

extern const char * const sec_strings[][SEC_NUMBER_OF_STRINGS+1];

/***************************************************/
/* TI strings                                      */
/***************************************************/


/** Message constants **/
#ifndef WAP_SUPPORT
/* Title strings */
#define SEC_STR_ID_WARNING_TITLE             (MSF_MODID_SEC + 0x0100) /*"Warning"*/
#define SEC_STR_ID_SESS_INFO_TITLE           (MSF_MODID_SEC + 0x0200) /*"Session info"*/
#define SEC_STR_ID_STORED_CONTRACTS_TITLE    (MSF_MODID_SEC + 0x0300) /*"Stored contracts"*/
#define SEC_STR_ID_SHOW_CONTRACTS_TITLE      (MSF_MODID_SEC + 0x0400) /*"Contract"*/
#define SEC_STR_ID_CONFIRM_TITLE             (MSF_MODID_SEC + 0x0500) /*"Confirmation"*/
#define SEC_STR_ID_GEN_PIN_TITLE             (MSF_MODID_SEC + 0x0600) /*"Generate PIN"*/
#define SEC_STR_ID_HASH_TITLE                (MSF_MODID_SEC + 0x0700) /*"Hash"*/
#define SEC_STR_ID_SHOW_CERT_TITLE           (MSF_MODID_SEC + 0x0800) /*"Certificate"*/
#define SEC_STR_ID_STORE_CERT_TITLE          (MSF_MODID_SEC + 0x0900) /*"Store certificate"*/
#define SEC_STR_ID_SHOW_CERT_NAMES_TITLE     (MSF_MODID_SEC + 0x0a00) /*"Certificate names"*/
#define SEC_STR_ID_EMPTY1                    (MSF_MODID_SEC + 0x0b00) /*"Choose certificate"*/
#define SEC_STR_ID_CONF_DISP_NAME_TITLE      (MSF_MODID_SEC + 0x0c00) /*"Confirm display name"*/
#define SEC_STR_ID_CHANGE_PIN_TITLE          (MSF_MODID_SEC + 0x0d00) /*"Change PIN"*/
#define SEC_STR_ID_PIN_DIALOG_TITLE          (MSF_MODID_SEC + 0x0e00) /*"PIN Dialog"*/
#define SEC_STR_ID_ALLOW_DEL_TITLE           (MSF_MODID_SEC + 0x0f00) /*"Delete keys"*/


/* Action string constants */
#define SEC_STR_ID_OVERWRITE (MSF_MODID_SEC + 0x1000) /*"Overwrite"*/
#define SEC_STR_ID_STORE     (MSF_MODID_SEC + 0x1100) /*"Store"*/
#define SEC_STR_ID_VIEW      (MSF_MODID_SEC + 0x1200) /*"View"*/
#define SEC_STR_ID_CANCEL    (MSF_MODID_SEC + 0x1300) /*"Cancel"*/
#define SEC_STR_ID_OK        (MSF_MODID_SEC + 0x1400) /*"Ok"*/
#define SEC_STR_ID_EMPTY     (MSF_MODID_SEC + 0x1500) /*" "*/
#define SEC_STR_ID_DELETE    (MSF_MODID_SEC + 0x1600) /*"Delete"*/


/* Used in confirm dialog */
#define SEC_STR_ID_CERT1   (MSF_MODID_SEC + 0x1700) /*"Could not verify the certificate. Do you want to store it anyway?"*/
#define SEC_STR_ID_CERT2   (MSF_MODID_SEC + 0x1800) /*"A certificate with the same valid date already exists. Do you want to overwrite the stored one?"*/
#define SEC_STR_ID_CERT3   (MSF_MODID_SEC + 0x1900) /*"A certificate with an older valid date already exists. Do you want to overwrite the stored one?"*/
#define SEC_STR_ID_CERT4   (MSF_MODID_SEC + 0x1a00) /*"A certificate with a newer valid date already exists. Do you want to overwrite the stored one?"*/
#define SEC_STR_ID_CERT5   (MSF_MODID_SEC + 0x1b00) /*"The certificate has been stored."*/
#define SEC_STR_ID_CERT10  (MSF_MODID_SEC + 0x1c00) /*"You have no stored CA-certificates. Do you want to connect without server or client authentication?"*/
#define SEC_STR_ID_CERT11  (MSF_MODID_SEC + 0x1d00) /*"No matching user certificate was found. Do you want to connect without user authentication, performing only server authentication?"*/
#define SEC_STR_ID_CERT12  (MSF_MODID_SEC + 0x1e00) /*"The contract has been deleted"*/
#define SEC_STR_ID_CERT13  (MSF_MODID_SEC + 0x1f00) /*"Could not delete the contract"*/
#define SEC_STR_ID_CERT14  (MSF_MODID_SEC + 0x2000) /*"Could not show the certificate"*/
#define SEC_STR_ID_CERT15  (MSF_MODID_SEC + 0x2100) /*"Could not delete the certificate"*/
#define SEC_STR_ID_CERT16  (MSF_MODID_SEC + 0x2200) /*"No matching CA certificate was found. Do you want to continue anyway?"*/


/* Session info strings */
#define SEC_STR_ID_SESS_TLS              (MSF_MODID_SEC + 0x2300) /*"Connection type:TLS"*/
#define SEC_STR_ID_SESS_WTLS             (MSF_MODID_SEC + 0x2400) /*"Connection type:WTLS"*/
#define SEC_STR_ID_SESS_SSL              (MSF_MODID_SEC + 0x2500) /*"Connection type:SSL"*/

#define SEC_STR_ID_SESS_MD5              (MSF_MODID_SEC + 0x2600) /*"HMAC algorithm:MD5"*/
#define SEC_STR_ID_SESS_SHA1             (MSF_MODID_SEC + 0x2700) /*"HMAC algorithm:SHA-1"*/
#define SEC_STR_ID_SESS_HMAC_KEYLEN      (MSF_MODID_SEC + 0x2800) /*"HMAC key length:"*/

#define SEC_STR_ID_SESS_ENCR_NULL        (MSF_MODID_SEC + 0x2900) /*"Encryption algorithm: NULL"*/
#define SEC_STR_ID_SESS_ENCR_RC5         (MSF_MODID_SEC + 0x2a00) /*"Encryption algorithm: RC5"*/
#define SEC_STR_ID_SESS_ENCR_RC5_40      (MSF_MODID_SEC + 0x2b00) /*"Encryption algorithm: RC5 40"*/
#define SEC_STR_ID_SESS_ENCR_RC5_56      (MSF_MODID_SEC + 0x2c00) /*"Encryption algorithm: RC5 56"*/
#define SEC_STR_ID_SESS_ENCR_RC5_64      (MSF_MODID_SEC + 0x2d00) /*"Encryption algorithm: RC5 64"*/
#define SEC_STR_ID_SESS_ENCR_3DES        (MSF_MODID_SEC + 0x2e00) /*"Encryption algorithm: Triple DES"*/
#define SEC_STR_ID_SESS_ENCR_RC4_40      (MSF_MODID_SEC + 0x2f00) /*"Encryption algorithm: RC4 40"*/
#define SEC_STR_ID_SESS_ENCR_RC4_128     (MSF_MODID_SEC + 0x3000) /*"Encryption algorithm: RC4 128"*/
#define SEC_STR_ID_SESS_ENCR_KEYLEN      (MSF_MODID_SEC + 0x3100) /*"Encryption key length:"*/

#define SEC_STR_ID_SESS_KEYEXCH_NULL         (MSF_MODID_SEC + 0x3200) /*"Key exchange algorithm: NULL"*/
#define SEC_STR_ID_SESS_KEYEXCH_RSA_ANON     (MSF_MODID_SEC + 0x3300) /*"Key exchange algorithm: RSA ANON"*/
#define SEC_STR_ID_SESS_KEYEXCH_RSA_ANON_512 (MSF_MODID_SEC + 0x3400) /*"Key exchange algorithm: RSA ANON 512"*/
#define SEC_STR_ID_SESS_KEYEXCH_RSA_ANON_768 (MSF_MODID_SEC + 0x3500) /*"Key exchange algorithm: RSA ANON 768"*/
#define SEC_STR_ID_SESS_KEYEXCH_RSA          (MSF_MODID_SEC + 0x3600) /*"Key exchange algorithm: RSA"*/
#define SEC_STR_ID_SESS_KEYEXCH_RSA_512      (MSF_MODID_SEC + 0x3700) /*"Key exchange algorithm: RSA 512"*/
#define SEC_STR_ID_SESS_KEYEXCH_RSA_768      (MSF_MODID_SEC + 0x3800) /*"Encryption algorithm: RC5 768"*/
#define SEC_STR_ID_SESS_KEYEXCH_DHE_DSS      (MSF_MODID_SEC + 0x3900) /*"Key exchange algorithm: DHE DSS"*/
#define SEC_STR_ID_SESS_KEYEXCH_KEYLEN       (MSF_MODID_SEC + 0x3a00) /*"Key exchange key length:"*/

/* Warning strings */
#define SEC_STR_ID_WARNING_MISSING_NR_KEY_SIGN_TEXT  (MSF_MODID_SEC + 0x3b00) /*"No non-repudiation key was found when trying to sign a text."*/
#define SEC_STR_ID_WARNING_MISSING_AUT_KEY_OPEN_WIM  (MSF_MODID_SEC + 0x3c00) /*"No authentication key was found when trying to open the WIM."*/
#define SEC_STR_ID_WARNING_COULD_NOT_STORE_CONTRACT  (MSF_MODID_SEC + 0x3d00) /*"The contract could not be stored."*/
#define SEC_STR_ID_WARNING_INSUFFICIENT_MEMORY       (MSF_MODID_SEC + 0x3e00) /*"Not enough memory to perform the action."*/
#define SEC_STR_ID_WARNING_GENERAL_ERROR             (MSF_MODID_SEC + 0x3f00) /*"An error occured."*/
#define SEC_STR_ID_WARNING_INVALID_PARAMETER         (MSF_MODID_SEC + 0x4000) /*"Invalid input."*/
#define SEC_STR_ID_WARNING_MISSING_KEY               (MSF_MODID_SEC + 0x4100) /*"No key was found."*/
#define SEC_STR_ID_WARNING_USER_NOT_VERIFIED         (MSF_MODID_SEC + 0x4200) /*"The user has not been verified."*/

#define SEC_STR_ID_WARNING_MISSING_KEY_CONNECT       (MSF_MODID_SEC + 0x4300) /*"No authentication key was found when trying to connect."*/
#define SEC_STR_ID_WARNING_MISSING_KEY_STORE_CERT    (MSF_MODID_SEC + 0x4400) /*"No authentication key was found when trying to store a certificate."*/
#define SEC_STR_ID_WARNING_MISSING_KEY_DELETE_CERT   (MSF_MODID_SEC + 0x4500) /*"No authentication key was found when trying to delete a certificate."*/
#define SEC_STR_ID_WARNING_MISSING_KEY_CHANGE_NONREP (MSF_MODID_SEC + 0x4600) /*"No non-repudiation key was found when trying to change it."*/
#define SEC_STR_ID_WARNING_MISSING_KEY_CHANGE_AUTH   (MSF_MODID_SEC + 0x4700) /*"No authentication key was found when trying to change it."*/

/* Certificate strings */
#define SEC_STR_ID_VAL_NOT_BEF   (MSF_MODID_SEC + 0x4800) /*"Valid not before:"*/
#define SEC_STR_ID_VAL_NOT_AFT   (MSF_MODID_SEC + 0x4900) /*"Valid not after:"*/
#define SEC_STR_ID_ISSUER        (MSF_MODID_SEC + 0x4a00) /*"Issuer:"*/
#define SEC_STR_ID_SUBJECT       (MSF_MODID_SEC + 0x4b00) /*"Subject:"*/
#define SEC_STR_ID_STORE_CERT    (MSF_MODID_SEC + 0x4c00) /*"Do you want to store this certificate?"*/
#define SEC_STR_ID_FR_NAME       (MSF_MODID_SEC + 0x4d00) /*"Friendly name:"*/

/* Used in SECa_tiConfirmDispName */
#define SEC_STR_ID_CERT7   (MSF_MODID_SEC + 0x4e00) /*"An old CA-certificate has been found. Do you want to remove this certificate?"*/

#define SEC_STR_ID_CHOOSE_CERT_TITLE         (MSF_MODID_SEC + 0x4f00) /*"Choose a certificate:"*/
#define SEC_STR_ID_CHOOSE_CERT_PUB_KEY_TITLE (MSF_MODID_SEC + 0x5000) /*"Choose a certificate to get the public key from:"*/


/* PIN strings */
#define SEC_STR_ID_NONREP_KEY        (MSF_MODID_SEC + 0x5100) /*"non-repudiation key"*/
#define SEC_STR_ID_AUTH_KEY          (MSF_MODID_SEC + 0x5200) /*"authentication key"*/
#define SEC_STR_ID_GEN_PIN           (MSF_MODID_SEC + 0x5300) /*"Enter a PIN for the "*/
#define SEC_STR_ID_PIN_TOO_LONG      (MSF_MODID_SEC + 0x5400) /*"The PIN was to long. Enter a PIN for the "*/
#define SEC_STR_ID_PIN_TOO_SHORT     (MSF_MODID_SEC + 0x5500) /*"The PIN was to short. Enter a PIN for the "*/
#define SEC_STR_ID_CHANGE_PIN_NEW    (MSF_MODID_SEC + 0x5600) /*"Enter a new PIN for the "*/
#define SEC_STR_ID_CHANGE_PIN_NEW2   (MSF_MODID_SEC + 0x5700) /*"Enter the new PIN again "*/
#define SEC_STR_ID_CHANGE_PIN_OLD    (MSF_MODID_SEC + 0x5800) /*"Enter the old PIN "*/
#define SEC_STR_ID_PIN_MISMATCH      (MSF_MODID_SEC + 0x5900) /*"The new PINs did not match. Enter a new PIN for the "*/
#define SEC_STR_ID_PIN_DIALOG        (MSF_MODID_SEC + 0x5a00) /*"Enter "*/
#define SEC_STR_ID_PIN_OPEN_WIM      (MSF_MODID_SEC + 0x5b00) /*"the PIN to the authentication key to open WIM"*/
#define SEC_STR_ID_PIN_CONNECT       (MSF_MODID_SEC + 0x5c00) /*"the PIN to the authentication key to connect"*/
#define SEC_STR_ID_PIN_SIGN_TEXT     (MSF_MODID_SEC + 0x5d00) /*"the PIN to the non-repudiation key to"*/
#define SEC_STR_ID_PIN_STORE_CERT    (MSF_MODID_SEC + 0x5e00) /*"the PIN to the authentication key to store certificate"*/
#define SEC_STR_ID_PIN_DEL_CERT      (MSF_MODID_SEC + 0x5f00) /*"the PIN to the authentication key to delete certificate"*/
#define SEC_STR_ID_PIN_GEN_AUT_KEY   (MSF_MODID_SEC + 0x6000) /*"a PIN to to generate authentication key"*/
#define SEC_STR_ID_PIN_GEN_NR_KEY    (MSF_MODID_SEC + 0x6100) /*"a PIN to generate non-repudiation key"*/
#define SEC_STR_ID_PIN_PUK           (MSF_MODID_SEC + 0x6200) /*"the PUK"*/
#define SEC_STR_ID_INPUT_ERROR       (MSF_MODID_SEC + 0x6300) /*"Some error occurred. Try again"*/
#define SEC_STR_ID_WRONG_OLD_PIN     (MSF_MODID_SEC + 0x6400) /*"The wrong old PIN was entered. Enter a PIN for the"*/
#define SEC_STR_ID_WRONG_PIN         (MSF_MODID_SEC + 0x6500) /*"Could not verify the input. Enter"*/
#define SEC_STR_ID_PIN_ALLOW_DEL_AUT (MSF_MODID_SEC + 0x6600) /*"PUK to delete all authentication keys and connected user certificates"*/
#define SEC_STR_ID_PIN_ALLOW_DEL_NR  (MSF_MODID_SEC + 0x6700) /*"PUK to delete all non-repudiation keys and connected user certificates"*/

/* Hash strings */
#define SEC_STR_ID_ENTER_HASH  (MSF_MODID_SEC + 0x6800) /*"Enter hash for the display name:"*/
#define SEC_STR_ID_WRONG_HASH  (MSF_MODID_SEC + 0x6900) /*"The wrong hash was entered. Enter a hash for the display name:"*/


/* Contract strings */
#define SEC_STR_ID_CONTRACT  (MSF_MODID_SEC + 0x6a00) /*"Contract:"*/
#define SEC_STR_ID_SIGNATURE (MSF_MODID_SEC + 0x6b00) /*"Signature:"*/
#define SEC_STR_ID_TIME      (MSF_MODID_SEC + 0x6c00) /*"Time:"*/


#define SEC_STR_ID_SIGN_TEXT1  (MSF_MODID_SEC + 0x6d00) /*"Do you want to sign this:"*/


/* Month strings */
#define SEC_STR_ID_JAN     (MSF_MODID_SEC + 0x6e00) /*"January"*/
#define SEC_STR_ID_FEB     (MSF_MODID_SEC + 0x6f00) /*"February"*/
#define SEC_STR_ID_MARCH   (MSF_MODID_SEC + 0x7000) /*"March"*/
#define SEC_STR_ID_APR     (MSF_MODID_SEC + 0x7100) /*"April"*/
#define SEC_STR_ID_MAY     (MSF_MODID_SEC + 0x7200) /*"May"*/
#define SEC_STR_ID_JUNE    (MSF_MODID_SEC + 0x7300) /*"June"*/
#define SEC_STR_ID_JULY    (MSF_MODID_SEC + 0x7400) /*"July"*/
#define SEC_STR_ID_AUG     (MSF_MODID_SEC + 0x7500) /*"August"*/
#define SEC_STR_ID_SEP     (MSF_MODID_SEC + 0x7600) /*"September"*/
#define SEC_STR_ID_OCT     (MSF_MODID_SEC + 0x7700) /*"October"*/
#define SEC_STR_ID_NOV     (MSF_MODID_SEC + 0x7800) /*"November"*/
#define SEC_STR_ID_DEC     (MSF_MODID_SEC + 0x7900) /*"December"*/

#define SEC_STR_ID_WARNING_MISSING_AUT_KEY_HANDSHAKE (MSF_MODID_SEC + 0x7a00) /*"No authentication key exists (noticed when opening the WIM)."*/

#define SEC_STR_ID_CERT17  (MSF_MODID_SEC + 0x7b00) /*"The certificate could not be stored."*/
#define SEC_STR_ID_CERT18  (MSF_MODID_SEC + 0x7c00) /*"The name on the certificate does not match the name of the site. Do you want to continue anyway?"*/
#define SEC_STR_ID_CERT19  (MSF_MODID_SEC + 0x7d00) /*"Error in certificate. Do you want to continue anyway?"*/
#endif
#include "wap.h"

#endif
