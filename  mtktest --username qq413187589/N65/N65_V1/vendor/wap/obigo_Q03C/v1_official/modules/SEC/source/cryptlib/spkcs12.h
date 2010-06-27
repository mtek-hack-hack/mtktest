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

#ifndef _SPKCS12_H
#define _SPKCS12_H

#include "cstlib.h"
#include "pkcs12t.h"  /* for pkcs12_keyAlgId */ 
											/* pkcs12t.h includes ut.h that includes uttypes.h. LOKO 14/5 2001 */
/* ************** */
/* 20/3 2001 LOKO */
/*#include "wchar.h"*/     /* For wchar_t */	
/* ************** */
  
#ifdef __cplusplus
extern "C" {
#endif

/* Type:        <pkcs12_simpleobj>
 * Summary:     Structure for holding PKCS#12 object information
 */
typedef pkcs12_obj pkcs12_simpleobj;
 
/* Type:        <pkcs12_obj2simpleobj_rval>
 * Summary:     Return values for functions that manipulate PKCS#12 objects             
 */ 
typedef enum {
  PKCS12_OBJ2SIMPLEOBJ_SUCCESS = 0,
  PKCS12_OBJ2SIMPLEOBJ_FAILINTEGRITY,
  PKCS12_OBJ2SIMPLEOBJ_FAILDECRYPT,
  PKCS12_OBJ2SIMPLEOBJ_FAILFORMAT,
  PKCS12_OBJ2SIMPLEOBJ_FAILKEYALG,
  PKCS12_OBJ2SIMPLEOBJ_FAILINTERNAL
} pkcs12_obj2simpleobj_rval;

#define PKCS12_OBJ2SIMPLEOBJ_MAX PKCS12_OBJ2SIMPLEOBJ_FAILINTERNAL


#ifndef _CST_PKCS12_H  

/* original prototype for this is in the internal header file pkcs12.h */

/* Function:    <pkcs12_obj_destroy>
 * Summary:     Destroys PKCS#12 objects.
 */

extern
void
pkcs12_obj_destroy(pkcs12_simpleobj);

#endif  /* ndef _CST_PKCS_12 */

/* Function:    <pkcs12_simpleobj_create>
 * Summary:     Builds a standard PKCS#12 object.
 * Syntax:      pkcs12_simpleobj rval = pkcs12_simpleobj_create(ut_mblk *key,
 *                ut_mblk *params, pkcs12_KeyAlgId keyAlgId, ut_mblk
 *                **certs, int noOfCerts, _TCHAR *caFriendlyName, _TCHAR
 *                *keyFriendlyName, _TCHAR *password, int strength);
 * Description: The pkcs12_simpleobj_create() "function" is a macro which
 *              wraps one of two functions,
 *              pkcs12_simpleobj_create_ascii() and
 *              pkcs12_simpleobj_create_unicode(). If this header file
 *              is compiled with the CST_UNICODE flag defined,
 *              pkcs12_simpleobj_create() wraps
 *              pkcs12_simpleobj_create_unicode(); otherwise, it wraps
 *              pkcs12_simpleobj_create_ascii(). The function is
 *              provided for legacy reasons, and to make it slightly
 *              less laborious to write applications which use either
 *              ASCII or Unicode, but not both.
 * Notes:       See pkcs12_simpleobj_create_unicode() and 
 *              pkcs12_simpleobj_create_ascii().
 */
#ifdef _UNICODE
#  define pkcs12_simpleobj_create(k,pa,kid,cts,ncts,cfr,kfr,pwd,str) \
          pkcs12_simpleobj_create_unicode(k,pa,kid,cts,ncts,cfr,kfr,pwd,str)
#else
#  define pkcs12_simpleobj_create(k,pa,kid,cts,ncts,cfr,kfr,pwd,str) \
          pkcs12_simpleobj_create_ascii(k,pa,kid,cts,ncts,cfr,kfr,pwd,str)
#endif /* def _UNICODE */


/* Function:    <pkcs12_simpleobj_create_ascii>
 * Summary:     Builds a standard PKCS#12 object using ASCII characters.
 * Syntax:      pkcs12_simpleobj rval = pkcs12_simpleobj_create_ascii(
 *                ut_mblk *key, ut_mblk *params, pkcs12_KeyAlgId
 *                keyAlgId, ut_mblk **certs, int noOfCerts, char
 *                *caFriendlyName, char *keyFriendlyName, char
 *                *password, int strength);
 * Description: The pkcs12_simpleobj_create_ascii() function creates a PKCS#12
 *              object (PFX) which provides a secure store for your
 *              personal cryptographic information. It takes the following
 *              parameters.
 *              key -- the private key.
 *              params -- the shared key parameters; can be 0 for RSA.
 *              keyAlgId -- the Algorithm Identifier for the private key,
 *                as defined by the pkcs12_keyAlgId enum in pkcs12t.h.
 *              certs -- an array of pointers to ut_mblks containing all the 
 *                certs necessary to establish trust with the user.
 *              noOfCerts -- the number of certs in certs.
 *              caFriendlyName -- an ASCII character string which is associated
 *                with the root CA cert (which is assumed to be in
 *                certs[noOfCerts-1]). This field must be provided if the p12 
 *                is to be imported into Netscape. Note that the string is 
 *                converted to Unicode internally.
 *              keyFriendlyName -- an ASCII character string which is 
 *                associated with the user's private key. This field must be 
 *                provided if the p12 is to be imported into Netscape. Note 
 *                that the string is converted to Unicode internally.
 *              password -- an ASCII character string which is used to 
 *                generate the key that encrypts the data and the key which 
 *                is used in the MAC.
 *              strength -- relates to the iteration count which is used when
 *                generating the encryption- and MACing- key. Can be set to 
 *                0 or 1. If 0, the the encryption count is a random value 
 *                between 512 and 1023, the iteration count is 1, and the 
 *                data is encrypted with 40-bit RC4. If 1, both counts are
 *                different random values between 512 and 1023, and the data 
 *                is encrypted with Triple-DES. If it is set to 1,
 *                Internet Explorer and Netscape will not be able to import 
 *                the file.
 * Returns:     The function returns 0 on failure or the new pkcs12_simpleobj 
 *              on success.
 * Memory:      Dispose of the memory allocated by this function
 *              as follows:
 *           (code)
 *              pkcs12_obj_destroy(rval);
 *           (/code)
 * Notes:       There are many other reasons why Netscape or IE might not
 *              be able to import the PKCS#12 file -- missing extensions,
 *              keylength too long for browsers exported from the US, etc.
 */

extern
pkcs12_simpleobj
pkcs12_simpleobj_create_ascii(ut_mblk          *key,
                              ut_mblk          *params,
                              pkcs12_KeyAlgId   keyAlgId,
                              ut_mblk         **certs,
                              int               noOfCerts,
                              char             *caFriendlyName,
                              char             *keyFriendlyName,
                              char             *password,
                              int               strength);


/* Function:    <pkcs12_simpleobj_create_unicode>
 * Summary:     Builds a standard PKCS#12 object using Unicode characters.
 * Syntax:      pkcs12_simpleobj rval = pkcs12_simpleobj_create_unicode(
 *                ut_mblk *key, ut_mblk *params, pkcs12_KeyAlgId
 *                keyAlgId, ut_mblk **certs, int noOfCerts, wchar_t
 *                *caFriendlyName, wchar_t *keyFriendlyName, wchar_t
 *                *password, int strength);
 * Description: The pkcs12_simpleobj_create_unicode() function creates a PKCS#12
 *              object (PFX) which provides a secure store for your
 *              personal cryptographic information. It takes the following
 *              parameters.
 *              key -- the private key.
 *              params -- the shared key parameters; can be 0 for RSA.
 *              keyAlgId -- the Algorithm Identifier for the private key,
 *                as defined by the pkcs12_keyAlgId enum in pkcs12t.h.
 *              certs -- an array of pointers to ut_mblks containing all the 
 *                certs necessary to establish trust with the user.
 *              noOfCerts -- the number of certs in certs.
 *              caFriendlyName -- a Unicode character string which is associated
 *                with the root CA cert (which is assumed to be in
 *                certs[noOfCerts-1]). This field must be provided if the p12 
 *                is to be imported into Netscape.
 *              keyFriendlyName -- a Unicode character string which is 
 *                associated with the user's private key. This field must be 
 *                provided if the p12 is to be imported into Netscape.
 *              password -- a Unicode character string which is used to 
 *                generate the key that encrypts the data and the key which 
 *                is used in the MAC.
 *              strength -- relates to the iteration count which is used when
 *                generating the encryption- and MACing- key. Can be set to 
 *                0 or 1. If 0, the the encryption count is a random value 
 *                between 512 and 1023, the iteration count is 1, and the 
 *                data is encrypted with 40-bit RC4. If 1, both counts are
 *                different random values between 512 and 1023, and the data 
 *                is encrypted with Triple-DES. If it is set to 1,
 *                Internet Explorer and Netscape will not be able to import 
 *                the file.
 * Notes:       The function returns 0 on failure or the new pkcs12_simpleobj 
 *              on success.
 * Memory:      Dispose of the memory allocated by this function
 *              as follows:
 *           (code)
 *              pkcs12_obj_destroy(rval);
 *           (/code)
 * Notes:       There are many other reasons why Netscape or IE might not
 *              be able to import the PKCS#12 file -- missing extensions,
 *              keylength too long for browsers exported from the US, etc.
 *
 *              The use of wchar_t is a change from earlier versions of
 *              the CST which used u16 *.
 */

extern
pkcs12_simpleobj
pkcs12_simpleobj_create_unicode(ut_mblk          *key,
                                ut_mblk          *params,
                                pkcs12_KeyAlgId   keyAlgId,
                                ut_mblk         **certs,
                                int               noOfCerts,
                                wchar_t           *caFriendlyName,
                                wchar_t          *keyFriendlyName,
                                wchar_t          *password,
                                int               strength);


/* Function:    <pkcs12_simpleobj_2file>
 * Summary:     Writes a pkcs12_simpleobj to a file.
 * Syntax:      int rval = pkcs12_simpleobj_2file(pkcs12_simpleobj object,
 *                FILE *dest);
 * Description: The pkcs12_simpleobj_2file() function BER-encodes the PKCS#12
 *              simple object created with pkcs12_simpleobj_create() and
 *              writes the result to dest. 
 * Returns:     The function  returns 0 on success or -1 on failure.
 * Memory:      This function allocates no memory.
 * Notes:       By convention, PKCS#12 objects are stored in a file with
 *              the extension .p12.
 *
 *              The use of wchar_t is a change from earlier versions of
 *              the CST which used u16 *.
 */

extern
int
pkcs12_simpleobj_2file(pkcs12_simpleobj  object,
                       FILE             *dest);


#ifndef _CST_PKCS12_H  

/* original prototype for these are in the internal header file pkcs12.h */

/* Function:    <pkcs12_obj_sizeof2ber>
 * Summary:     Gets the size of a BER-encoded PKCS#12 object.
 * Syntax:      size_t rval = pkcs12_obj_sizeof2ber(pkcs12_obj obj);
 * Description: The pkcs12_obj_sizeof2ber() function returns the length,
 *              in bytes, of the BER encoding of the PKCS#12 object obj.
 * Memory:      This function allocates no memory.
 */
extern
sec_off_t
pkcs12_obj_sizeof2ber(pkcs12_obj   obj);

/* Function:    <pkcs12_obj_2ber>
 * Summary:     BER-encodes a PKCS#12 object.
 * Syntax:      u8 * rval = pkcs12_obj_2ber(pkcs12_obj obj, u8 *dest);
 * Description: The pkcs12_obj_2ber() function BER-encodes the PKCS#12
 *              object obj and writes the BER-encoded data to dest.
 *              Sufficient memory must have been allocated at dest to
 *              hold the BER-encoded data. The amount of memory to
 *              allocate is given by pkcs12_obj2_sizeof2ber.
 *
 *              This function returns a pointer to the byte after the
 *              last byte written on success or 0 on failure.
 * Memory:      This function allocates no memory.
 */
extern
u8 *
pkcs12_obj_2ber(pkcs12_obj  obj,
                u8         *dest);

#endif /* ndef _CST_PKCS12_H */



/* Function:    <pkcs12_obj_fromfile>
 * Summary:     Reads a .p12 file and returns a pointer to the pkcs12_obj in it.
 * Syntax:      pkcs12_obj rval = pkcs12_obj_fromfile(FILE *src);
 * Description: The pkcs12_obj_fromfile() function reads a PKCS#12 object from
 *              src and returns a pointer to it in rval. No parsing of the
 *              object is done until the call to pkcs12_simpleobj_2data. 
 *
 *              On failure, the function returns 0.
 * Memory:      Dispose of the memory allocated by this function
 *              as follows:
 *           (code)
 *              pkcs12_obj_destroy (rval);
 *           (/code)
 */
extern
pkcs12_obj
pkcs12_obj_fromfile(FILE *src);


/* Function:    <pkcs12_obj_fromBuffer>
 * Summary:     Converts a BER-encoded PKCS#12 object to a usable pkcs12_obj.
 * Syntax:      pkcs12_obj rval = pkcs12_obj_fromBuffer(u8 *src);
 * Description: The pkcs12_obj_fromBuffer() function reads a PKCS#12 object from
 *              src and returns a pointer to it in rval.
 *
 *              On failure, the function returns 0.
 * Memory:      Dispose of the memory allocated by this function
 *              as follows:
 *           (code)
 *              pkcs12_obj_destroy (rval);
 *           (/code)
 */
extern
pkcs12_obj
pkcs12_obj_fromBuffer(u8 *src);


/* Function:    <pkcs12_obj_simpleobj2data>
 * Summary:     Decodes a standard PKCS#12 object.
 * Syntax:      pkcs12_obj2simpleobj_rval rval =
 *                pkcs12_obj_simpleobj2data(pkcs12_obj obj, _TCHAR
 *                *password, ut_mblk *key, ut_mblk *params,
 *                pkcs12_KeyAlgId *keyAlgId, ut_mblk ***certs, int
 *                *noOfCerts);
 * Description: The pkcs12_obj_simpleobj2data() "function" is actually
 *              a macro. If the _UNICODE flag is defined it wraps 
 *              pkcs12_obj_simpleobj2data_unicode(). Otherwise, it wraps
 *              pkcs12_obj_simpleobj2data_ascii().
 * Notes:       See pkcs12_obj_simpleobj2data_unicode() and 
 *              pkcs12_obj_simpleobj2data_ascii().
 *              
 */

#ifdef _UNICODE
#  define pkcs12_obj_simpleobj2data(o,p,k,pa,kaid,cts,ncts) \
          pkcs12_obj_simpleobj2data_unicode(o,p,k,pa,kaid,cts,ncts)
#else
#  define pkcs12_obj_simpleobj2data(o,p,k,pa,kaid,cts,ncts) \
          pkcs12_obj_simpleobj2data_ascii(o,p,k,pa,kaid,cts,ncts)
#endif

/* Function:    <pkcs12_obj_simpleobj2data_ascii>
 * Summary:     Decodes a standard PKCS#12 object.
 * Syntax:      pkcs12_obj2simpleobj_rval rval =
 *                pkcs12_obj_simpleobj2data_ascii(pkcs12_obj obj, char
 *                *password, ut_mblk *key, ut_mblk *params,
 *                pkcs12_KeyAlgId *keyAlgId, ut_mblk ***certs, int
 *                *noOfCerts);
 * Description: The pkcs12_obj_simpleobj2data_ascii() function attempts to
 *              decode the PKCS#12 object returned from 
 *              pkcs12_obj_fromfile(), under the assumptions that:
 *              - It has no data other than encrypted private keys,
 *                private keys and certs;
 *              - There is no more than one private key in the PKCS#12
 *                object.
 *              - The same passphrase was used for both integrity checking
 *                and encryption.
 *              .p12 files produced by both Netscape and Internet Explorer
 *              conform to these assumptions.
 *
 *              The function takes the following parameters:
 *              obj -- the object that was read from the file by 
 *                pkcs12_obj_fromfile().
 *              password -- the ASCII password.
 *              key -- on success, holds the key.
 *              params -- on success, holds parameters associated with the key
 *                (for DSA and Diffie-Hellman).
 *              keyAlgId -- on success, holds the keyAlgId (as defined by the 
 *                pkcs12_keyAlgId enum in pkcs12t.h) if the key algorithm
 *                identifier in the .p12 was recognized, or 
 *                PKCS12_KEYALGID_UNSUP otherwise.
 *              certs -- on success, holds a pointer to an array of pointers to
 *                ut_mblks which contain the certs. The cert which is 
 *                associated with key will be in *certs[0]. Apart from this the
 *                certs are presented in the order in which they were found 
 *                inside the .p12 file.
 *              noOfCerts -- on success, holds the number of certs.
 * Returns:     The function returns:
 *              PKCS12_OBJ2SIMPLEOBJ_SUCCESS -- on success;
 *              PKCS12_OBJ2SIMPLEOBJ_FAILINTEGRITY -- if the object fails the
 *                integrity check;
 *              PKCS12_OBJ2SIMPLEOBJ_FAILDECRYPT -- if there is a decryption 
 *                error;
 *              PKCS12_OBJ2SIMPLEOBJ_FAILFORMAT -- if the object decrypts 
 *                correctly but cannot be unambiguously put into the simpleobj 
 *                format (for example, if it contains two different private 
 *                keys);
 *              PKCS12_OBJ2SIMPLEOBJ_FAILKEYALG -- if the key algorithm was 
 *                unknown;
 *              PKCS12_OBJ2SIMPLEOBJ_FAILINTERNAL -- if there is an internal 
 *                error.
 * Memory:      Dispose of the memory allocated by this function
 *              as follows:
 *           (code)
 *              ut_mblk **certs;
 *              ut_mblk   key;
 *              ...
 *              pkcs12_obj_simpleobj2data_ascii(obj, password, &key, &keyAlgId, 
 *                &certs, &noOfCerts);
 *              ...
 *              ut_dispose_mem(key.data)
 *              while (noOfCerts)
 *                ut_dispose_mblk_f(certs[--noOfCerts]);
 *              ut_dispose_mem(certs);
 *           (/code)
 * Notes:       Note that FAILINTEGRITY or FAILDECRYPT can be caused by 
 *              providing the wrong passphrase. Also note that (in theory)
 *              you can use a different passphrase for integrity checking 
 *              and encryption, and this interface only works for 
 *              implementations which use the same passphrase for both
 *              (though this applies to all known existing implementations, 
 *              including Netscape, IE and pkcs12_simpleobj_create()).
 */


extern
pkcs12_obj2simpleobj_rval
pkcs12_obj_simpleobj2data_ascii(pkcs12_obj         obj,
                                char              *password,
                                ut_mblk           *key,
                                ut_mblk           *params,
                                pkcs12_KeyAlgId   *keyAlgId,
                                ut_mblk         ***certs,
                                int               *noOfCerts);

/* Function:    <pkcs12_obj_simpleobj2data_unicode>
 * Summary:     Decodes a standard PKCS#12 object.
 * Syntax:      pkcs12_obj2simpleobj_rval rval =
 *                pkcs12_obj_simpleobj2data_unicode(pkcs12_obj obj, wchar_t
 *                *password, ut_mblk *key, ut_mblk *params,
 *                pkcs12_KeyAlgId *keyAlgId, ut_mblk ***certs, int
 *                *noOfCerts);
 * Description: The pkcs12_obj_simpleobj2data_unicode() function attempts to
 *              decode the PKCS#12 object returned from 
 *              pkcs12_obj_fromfile(), under the assumptions that:
 *              - It has no data other than encrypted private keys,
 *                private keys and certs;
 *              - There is no more than one private key in the PKCS#12
 *                object.
 *              - The same passphrase was used for both integrity checking
 *                and encryption.
 *              .p12 files produced by both Netscape and Internet Explorer
 *              conform to these assumptions.
 *
 *              The function takes the following parameters:
 *              obj -- the object that was read from the file by 
 *                pkcs12_obj_fromfile().
 *              password -- the Unicode password.
 *              key -- on success, holds the key.
 *              params -- on success, holds parameters associated with the key
 *                (for DSA and Diffie-Hellman).
 *              keyAlgId -- on success, holds the keyAlgId (as defined by the 
 *                pkcs12_keyAlgId enum in pkcs12t.h) if the key algorithm
 *                identifier in the .p12 was recognized, or 
 *                PKCS12_KEYALGID_UNSUP otherwise.
 *              certs -- on success, holds a pointer to an array of pointers to
 *                ut_mblks which contain the certs. The cert which is 
 *                associated with key will be in *certs[0]. Apart from this the
 *                certs are presented in the order in which they were found 
 *                inside the .p12 file.
 *              noOfCerts -- on success, holds the number of certs.
 * Returns:     The functions returns:
 *              PKCS12_OBJ2SIMPLEOBJ_SUCCESS -- on success;
 *              PKCS12_OBJ2SIMPLEOBJ_FAILINTEGRITY -- if the object fails the
 *                integrity check;
 *              PKCS12_OBJ2SIMPLEOBJ_FAILDECRYPT -- if there is a decryption 
 *                error;
 *              PKCS12_OBJ2SIMPLEOBJ_FAILFORMAT -- if the object decrypts 
 *                correctly but cannot be unambiguously put into the simpleobj 
 *                format (for example, if it contains two different private 
 *                keys);
 *              PKCS12_OBJ2SIMPLEOBJ_FAILKEYALG -- if the key algorithm was 
 *                unknown;
 *              PKCS12_OBJ2SIMPLEOBJ_FAILINTERNAL -- if there is an internal 
 *                error.
 * Memory:      Dispose of the memory allocated by this function
 *              as follows:
 *           (code)
 *              ut_mblk **certs;
 *              ut_mblk   key;
 *              ...
 *              pkcs12_obj_simpleobj2data_unicode(obj, password, &key,  
 *                &keyAlgId, &certs, &noOfCerts);
 *              ...
 *              ut_dispose_mem(key.data)
 *              while (noOfCerts)
 *                ut_dispose_mblk_f(certs[--noOfCerts]);
 *              ut_dispose_mem(certs);
 *           (/code)
 * Notes:       Note that FAILINTEGRITY or FAILDECRYPT can be caused by 
 *              providing the wrong passphrase. Also note that (in theory)
 *              you can use a different passphrase for integrity checking 
 *              and encryption, and this interface only works for 
 *              implementations which use the same passphrase for both
 *              (though this applies to all known existing implementations, 
 *              including Netscape, IE and pkcs12_simpleobj_create()).
 * 
 */
extern
pkcs12_obj2simpleobj_rval
pkcs12_obj_simpleobj2data_unicode(pkcs12_obj         obj,
                                  wchar_t           *password,
                                  ut_mblk           *key,
                                  ut_mblk           *params,
                                  pkcs12_KeyAlgId   *keyAlgId,
                                  ut_mblk         ***certs,
                                  int               *noOfCerts);


/* Function:    <pkcs12_obj_simpleobj2rebuilddata>
 * Summary:     Decodes a standard PKCS#12 object.
 * Syntax:      pkcs12_obj2simpleobj_rval rval =
 *                pkcs12_obj_simpleobj2rebuilddata(pkcs12_obj obj, _TCHAR
 *                *password, ut_mblk *key, ut_mblk *params,
 *                pkcs12_KeyAlgId *keyAlgId, ut_mblk ***certs, int
 *                *noOfCerts, int *strength);
 * Description: The pkcs12_obj_simpleobj2rebuilddata() "function" is actually
 *              a macro. If the _UNICODE flag is defined it wraps 
 *              pkcs12_obj_simpleobj2rebuilddata_unicode(). Otherwise, it wraps
 *              pkcs12_obj_simpleobj2rebuilddata_ascii().
 * Notes:       See pkcs12_obj_simpleobj2rebuilddata_unicode() and 
 *              pkcs12_obj_simpleobj2rebuilddata_ascii().
 *              
 */

#ifdef _UNICODE
#  define pkcs12_obj_simpleobj2rebuilddata(o,p,k,pa,kaid,cts,ncts,s) \
          pkcs12_obj_simpleobj2rebuilddata_unicode(o,p,k,pa,kaid,cts,ncts,s)
#else
#  define pkcs12_obj_simpleobj2rebuilddata(o,p,k,pa,kaid,cts,ncts,s) \
          pkcs12_obj_simpleobj2rebuilddata_ascii(o,p,k,pa,kaid,cts,ncts,s)
#endif



/* Function:    <pkcs12_obj_simpleobj2rebuilddata_ascii>
 * Summary:     Decodes a standard PKCS#12 object.
 * Syntax:      pkcs12_obj2simpleobj_rval rval =
 *                pkcs12_obj_simpleobj2rebuilddata_ascii(pkcs12_obj obj, char
 *                *password, ut_mblk *key, ut_mblk *params,
 *                pkcs12_KeyAlgId *keyAlgId, ut_mblk ***certs, int
 *                *noOfCerts, int *strength);
 * Description: The pkcs12_obj_simpleobj2rebuilddata() function attempts to
 *              decode the PKCS#12 object returned from 
 *              pkcs12_obj_fromfile(), under the assumptions that:
 *              - It has no data other than encrypted private keys,
 *                private keys and certs;
 *              - There is no more than one private key in the PKCS#12
 *                object.
 *              - The same passphrase was used for both integrity checking
 *                and encryption.
 *              .p12 files produced by both Netscape and Internet Explorer
 *              conform to these assumptions.
 *
 *              The function takes the following parameters:
 *              obj -- the object that was read from the file by 
 *                pkcs12_obj_fromfile().
 *              password -- the ASCII password.
 *              key -- on success, holds the key.
 *              params -- on success, holds parameters associated with the key
 *                (for DSA and Diffie-Hellman).
 *              keyAlgId -- on success, holds the keyAlgId (as defined by the 
 *                pkcs12_keyAlgId enum in pkcs12t.h) if the key algorithm
 *                identifier in the .p12 was recognized, or 
 *                PKCS12_KEYALGID_UNSUP otherwise.
 *              certs -- on success, holds a pointer to an array of pointers to
 *                ut_mblks which contain the certs. The cert which is 
 *                associated with key will be in *certs[0]. Apart from this the
 *                certs are presented in the order in which they were found 
 *                inside the .p12 file.
 *              noOfCerts -- on success, holds the number of certs.
 *              strength -- on success, holds 0 if the PKCS#12 object
 *                can be imported into a browser, 1 if it can't (which
 *                implies it was encrypted with strong encryption).
 *
 *              The pkcs12_obj_simpleobj2rebuilddata_ascii() function
 *              therefore provides you with enough information to add
 *              extra items to a pkcs12_simpleobj and rebuild it as an
 *              object of the appropriate strength.
 * Returns:     The functions returns:
 *              PKCS12_OBJ2SIMPLEOBJ_SUCCESS -- on success;
 *              PKCS12_OBJ2SIMPLEOBJ_FAILINTEGRITY -- if the object fails the
 *                integrity check;
 *              PKCS12_OBJ2SIMPLEOBJ_FAILDECRYPT -- if there is a decryption 
 *                error;
 *              PKCS12_OBJ2SIMPLEOBJ_FAILFORMAT -- if the object decrypts 
 *                correctly but cannot be unambiguously put into the simpleobj 
 *                format (for example, if it contains two different private 
 *                keys);
 *              PKCS12_OBJ2SIMPLEOBJ_FAILKEYALG -- if the key algorithm was 
 *                unknown;
 *              PKCS12_OBJ2SIMPLEOBJ_FAILINTERNAL -- if there is an internal 
 *                error.
 * Memory:      Dispose of the memory allocated by this function
 *              as follows: 
 *           (code)
 *              ut_mblk **certs;
 *              ut_mblk   key;
 *              ...
 *              pkcs12_obj_simpleobj2rebuilddata_ascii(obj, password, &key,  
 *                &keyAlgId, &certs, &noOfCerts, strength);
 *              ...
 *              ut_dispose_mem(key.data)
 *              while (noOfCerts)
 *                ut_dispose_mblk_f(certs[--noOfCerts]);
 *              ut_dispose_mem(certs);
 *           (/code)
 * Notes:       Note that FAILINTEGRITY or FAILDECRYPT can be caused by 
 *              providing the wrong passphrase. Also note that (in theory)
 *              you can use a different passphrase for integrity checking 
 *              and encryption, and this interface only works for 
 *              implementations which use the same passphrase for both
 *              (though this applies to all known existing implementations, 
 *              including Netscape, IE and pkcs12_simpleobj_create()).
 */

extern
pkcs12_obj2simpleobj_rval
pkcs12_obj_simpleobj2rebuilddata_ascii(pkcs12_obj         obj,
                                       char              *password,
                                       ut_mblk           *key,
                                       ut_mblk           *params,
                                       pkcs12_KeyAlgId   *keyAlgId,
                                       ut_mblk         ***certs,
                                       int               *noOfCerts,
                                       int               *strength);


/* Function:    <pkcs12_obj_simpleobj2rebuilddata_unicode>
 * Summary:     Decodes a standard PKCS#12 object.
 * Syntax:      pkcs12_obj2simpleobj_rval rval =
 *                pkcs12_obj_simpleobj2rebuilddata_unicode(pkcs12_obj obj, 
 *                wchar_t *password, ut_mblk *key, ut_mblk *params,
 *                pkcs12_KeyAlgId *keyAlgId, ut_mblk ***certs, int
 *                *noOfCerts, int *strength);
 * Description: The pkcs12_obj_simpleobj2rebuilddata_unicode() function
 *              attempts to decode the PKCS#12 object returned from 
 *              pkcs12_obj_fromfile(), under the assumptions that:
 *              - It has no data other than encrypted private keys,
 *                private keys and certs;
 *              - There is no more than one private key in the PKCS#12
 *                object.
 *              - The same passphrase was used for both integrity checking
 *                and encryption.
 *              .p12 files produced by both Netscape and Internet Explorer
 *              conform to these assumptions.
 *
 *              The function takes the following parameters:
 *              obj -- the object that was read from the file by 
 *                pkcs12_obj_fromfile().
 *              password -- the ASCII password.
 *              key -- on success, holds the key.
 *              params -- on success, holds parameters associated with the key
 *                (for DSA and Diffie-Hellman).
 *              keyAlgId -- on success, holds the keyAlgId (as defined by the 
 *                pkcs12_keyAlgId enum in pkcs12t.h) if the key algorithm
 *                identifier in the .p12 was recognized, or 
 *                PKCS12_KEYALGID_UNSUP otherwise.
 *              certs -- on success, holds a pointer to an array of pointers to
 *                ut_mblks which contain the certs. The cert which is 
 *                associated with key will be in *certs[0]. Apart from this the
 *                certs are presented in the order in which they were found 
 *                inside the .p12 file.
 *              noOfCerts -- on success, holds the number of certs.
 *              strength -- on success, holds 0 if the PKCS#12 object
 *                can be imported into a browser, 1 if it can't (which
 *                implies it was encrypted with strong encryption).
 *
 *              The pkcs12_obj_simpleobj2rebuilddata_unicode() function
 *              therefore provides you with enough information to add
 *              extra items to a pkcs12_simpleobj and rebuild it as an
 *              object of the appropriate strength.
 * Returns:     The function returns:
 *              PKCS12_OBJ2SIMPLEOBJ_SUCCESS -- on success;
 *              PKCS12_OBJ2SIMPLEOBJ_FAILINTEGRITY -- if the object fails the
 *                integrity check;
 *              PKCS12_OBJ2SIMPLEOBJ_FAILDECRYPT -- if there is a decryption 
 *                error;
 *              PKCS12_OBJ2SIMPLEOBJ_FAILFORMAT -- if the object decrypts 
 *                correctly but cannot be unambiguously put into the simpleobj 
 *                format (for example, if it contains two different private 
 *                keys);
 *              PKCS12_OBJ2SIMPLEOBJ_FAILKEYALG -- if the key algorithm was 
 *                unknown;
 *              PKCS12_OBJ2SIMPLEOBJ_FAILINTERNAL -- if there is an internal 
 *                error.
 * Memory:      Dispose of the memory allocated by this function
 *              as follows (example given for pkcs12_obj_simpleobj2data(),
 *              but applies to both functions):
 *           (code)
 *              ut_mblk **certs;
 *              ut_mblk   key;
 *              ...
 *              pkcs12_obj_simpleobj2rebuilddata_unicode(obj, password, &key,  
 *                &keyAlgId, &certs, &noOfCerts, strength);
 *              ...
 *              ut_dispose_mem(key.data)
 *              while (noOfCerts)
 *                ut_dispose_mblk_f(certs[--noOfCerts]);
 *              ut_dispose_mem(certs);
 *           (/code)
 * Notes:       Note that FAILINTEGRITY or FAILDECRYPT can be caused by 
 *              providing the wrong passphrase. Also note that (in theory)
 *              you can use a different passphrase for integrity checking 
 *              and encryption, and this interface only works for 
 *              implementations which use the same passphrase for both
 *              (though this applies to all known existing implementations, 
 *              including Netscape, IE and pkcs12_simpleobj_create()).
 */

extern
pkcs12_obj2simpleobj_rval
pkcs12_obj_simpleobj2rebuilddata_unicode(pkcs12_obj         obj,
                                         wchar_t           *password,
                                         ut_mblk           *key,
                                         ut_mblk           *params,
                                         pkcs12_KeyAlgId   *keyAlgId,
                                         ut_mblk         ***certs,
                                         int               *noOfCerts,
                                         int               *strength);




/* Function:    <pkcs12_simpleobj_convert_cstv7_1>
 * Summary:     Ensures that a PKCS#12 object is correctly encrypted.
 * Syntax:      int rval = pkcs12_simpleobj_convert_cstv7_1(
 *                pkcs12_obj input, ut_mblk *passphrase);
 * Description: The pkcs12_simpleobj_convert_cstv7_1() "function" is a 
 *              macro which wraps one of two functions,
 *              pkcs12_simpleobj_convert_cstv7_1_ascii() and
 *              pkcs12_simpleobj_convert_cstv7_1_unicode(). If this
 *              header file is compiled with the CST_UNICODE flag
 *              defined, pkcs12_simpleobj_convert_cstv7_1() wraps
 *              pkcs12_simpleobj_convert_cstv7_1_unicode(); otherwise,
 *              it wraps pkcs12_simpleobj_convert_cstv7_1_ascii(). The
 *              function is provided for legacy reasons, and to make it
 *              slightly less laborious to write applications which use
 *              either ASCII or Unicode, but not both.
 */
#ifdef _UNICODE
#  define pkcs12_simpleobj_convert_cstv7_1(i,pp) \
          pkcs12_simpleobj_convert_cstv7_1_unicode(i,pp)
#else
#  define pkcs12_simpleobj_convert_cstv7_1(i,pp) \
          pkcs12_simpleobj_convert_cstv7_1_ascii(i,pp)
#endif /* def _UNICODE */

/* Function:    <pkcs12_simpleobj_convert_cstv7_1_ascii>
 * Summary:     Ensures that a PKCS#12 object is correctly encrypted.
 * Syntax:      int rval = pkcs12_simpleobj_convert_cstv7_1_ascii(
 *                pkcs12_obj input, ut_mblk *passphrase);
 * Description: The pkcs12_simpleobj_convert_cstv7_1() function decrypts
 *              the object obj using passphrase and re-encrypts it using
 *              the same passphrase. This can be used to ensure that
 *              PKCS#12 objects produced using CST v7.1 and earlier do
 *              not suffer from the bug in CST v7.1 and earlier which
 *              resulted in PKCS#12-encrypted data occasionally being
 *              non-compliant with the standard.
 *
 *              The object is decrypted and re-encrypted "in place"; in
 *              other words, we don't create an object but alter the
 *              existing object (if necessary). After calling this
 *              function, the object can be written to file with
 *              pkcs12_simpleobj_2file().
 * 
 *              This function returns:
 *              PKCS12_OBJ2SIMPLEOBJ_SUCCESS -- on success;
 *              PKCS12_OBJ2SIMPLEOBJ_FAILINTEGRITY -- if the object
 *                fails the integrity check;
 *              PKCS12_OBJ2SIMPLEOBJ_FAILDECRYPT -- if there is a decryption
 *                error;
 *              PKCS12_OBJ2SIMPLEOBJ_FAILINTERNAL -- if there is an internal
 *                error.
 * Memory:      This function allocates no memory.
 * Notes:       Note that FAILINTEGRITY or FAILDECRYPT can be caused by
 *              providing the wrong passphrase.
 */
extern
pkcs12_obj2simpleobj_rval
pkcs12_simpleobj_convert_cstv7_1_ascii(pkcs12_obj obj, char *password);

/* Function:    <pkcs12_simpleobj_convert_cstv7_1_unicode>
 * Summary:     Ensures that a PKCS#12 object is correctly encrypted.
 * Syntax:      int rval = pkcs12_simpleobj_convert_cstv7_1_unicode(
 *                pkcs12_obj input, ut_mblk *passphrase);
 * Description: The pkcs12_simpleobj_convert_cstv7_1() function decrypts
 *              the object obj using passphrase and re-encrypts it using
 *              the same passphrase. This can be used to ensure that
 *              PKCS#12 objects produced using CST v7.1 and earlier do
 *              not suffer from the bug in CST v7.1 and earlier which
 *              resulted in PKCS#12-encrypted data occasionally being
 *              non-compliant with the standard.
 *
 *              The object is decrypted and re-encrypted "in place"; in
 *              other words, we don't create an object but alter the
 *              existing object (if necessary). After calling this
 *              function, the object can be written to file with
 *              pkcs12_simpleobj_2file().
 * 
 *              This function returns:
 *              PKCS12_OBJ2SIMPLEOBJ_SUCCESS -- on success;
 *              PKCS12_OBJ2SIMPLEOBJ_FAILINTEGRITY -- if the object
 *                fails the integrity check;
 *              PKCS12_OBJ2SIMPLEOBJ_FAILDECRYPT -- if there is a decryption
 *                error;
 *              PKCS12_OBJ2SIMPLEOBJ_FAILINTERNAL -- if there is an internal
 *                error.
 * Memory:      This function allocates no memory.
 * Notes:       Note that FAILINTEGRITY or FAILDECRYPT can be caused by
 *              providing the wrong passphrase.
 *
 *              The use of wchar_t is a change from earlier versions of
 *              the CST which used u16 *.
 */
extern
pkcs12_obj2simpleobj_rval
pkcs12_simpleobj_convert_cstv7_1_unicode(pkcs12_obj obj, wchar_t *password);

#ifdef __cplusplus
}
#endif

#endif  /* ndef _SPKCS12_H */
