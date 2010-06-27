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
#ifndef _CSTIO_H /* Prevent multiple inclusion */
#define _CSTIO_H

#include "ut.h"     /* for ut_mblk */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/* Errors */

#define  CSTIO_EBASE  (0x00a00000)  /* Module code */
#define  CSTIO_EFILE  (CSTIO_EBASE + 0x40000)  /* Couldn't open file */
#define  CSTIO_EHASH  (CSTIO_EBASE + 0x40001)  /* hash failure */
#define  CSTIO_ECRYPT (CSTIO_EBASE + 0x40002)  /* encrypt/decrypt failure */


/* Function:    <write_mblk_ascii>
 * Summary:     Writes data to a file.
 * Syntax:      rval = write_mblk_ascii(filename, mblk);
 * Description: Opens filename and writes mblk->data to it.
 * Failure:     On failure to open or write to file, returns 0.
 * Notes:       write_mblk() is defined as a macro. If _UNICODE is defined it
 *              wraps write_mblk_unicode(). If _UNICODE is not defined it
 *              wraps write_mblk_ascii().
 */
extern int 
 CST32EXPORTTYPE CST16EXPORTTYPE
write_mblk_ascii(char *file, ut_mblk *mblk);


/* Function:    <read_mblk_ascii>
 * Summary:     Reads data from a file.
 * Syntax:      rval = read_mblk_ascii(filename, mblk)
 * Description: Opens filename and reads contents into mblk->data, setting
 *              mblk->size and mblk->used appropriately.
 * Failure:     Returns 0 on failure to stat, open or read from file.
 * Notes:       read_mblk() is defined as a macro. If _UNICODE is defined it
 *              wraps read_mblk_unicode(). If _UNICODE is not defined it
 *              wraps read_mblk_ascii().
 */
extern int 
 CST32EXPORTTYPE CST16EXPORTTYPE
read_mblk_ascii(char *file, ut_mblk *mblk);

/* Function:    <cst_io_get_xorstring>
 * Summary:     XORs a passphrase with random data.
 * Syntax:      xorstring = cst_io_get_xorstring();
 * Description: Hashes the current time repeatedly until we have 120 apparently
 *              random bytes, which we return so they can be XORed with a 
 *              passphrase as it is entered. Note that this isn't very
 *              secure - we use effectively 8 bits of entropy (if that) 
 *              to get 120 apparently-random bytes - but the point is to
 *              make opportunistic attacks a little harder.
 * Failure:     Caused by failure to hash properly. Returns 0 on failure.
 */
u8 CST32EXPORTTYPE * CST16EXPORTTYPE
cst_io_get_xorstring(void);

/* Function:    <pwrite_mblk_ascii>
 * Summary:     Stores passphrase protected data to disc.
 * Syntax:      rval = pwrite_mblk_ascii(filename, mblk, passphrase, len,
 *                xorstring, salt, c, ichk);
 * Description: Stores a passphrase protected mblk to disc. 
 *              filename is the name of the output file.
 *              mblk->data will be output.
 *              passphrase is the passphrase.
 *              len is the length of the passphrase.
 *              xorstring is a pointer to a pseudo-random string which was 
 *              XORed with passphrase on entry so that it would not be too 
 *              obvious if swapped out to disk. If xorstring (not *xorstring)
 *              == 0 no xoring is performed.
 *              salt is an eight-byte string appended to passphrase to frustrate
 *              dictionary attacks. If salt = 0 no salt is used; if *salt = 0
 *              a salt string is generated and returned in salt -- eight
 *              bytes of memory must have been allocated for this, and it is
 *              up to the user to store the salt securely. 
 *              c is the number of times the passphrase + salt are to be hashed
 *              to get the key -- this should be small for a long passphrase
 *              and big for a short passphrase, to foil timing attacks. If
 *              c == 0 it is set equal to 1 within the function -- this is so
 *              the simplest possible implementation goes pwrite_mblk(filename,
 *              mblk, passphrase, len, 0, 0, 0, 0).
 *              ichk is a flag saying whether to carry out an integrity
 *              check (ichk == 1) or not (ichk == 0). If ichk == 1 a hash of the
 *              key is prepended to the output encrypted data. Setting ichk == 0
 *              gives pkcs-5 compliant pass phrase protection.
 *              Passphrase+salt are hashed c times with SHA-1; the first eight 
 *              bytes of the final hash form the key, and the last eight bytes
 *              the IV, to CBC-DES encrypt mblk->data and output it to
 *              filename. 
 * Failure:     Returns 0 on failure to open or write to file,
 *              failure to hash, or failure to encrypt.
 * Notes:       pwrite_mblk() is defined as a macro. If _UNICODE is defined it
 *              wraps pwrite_mblk_unicode(). If _UNICODE is not defined it
 *              wraps pwrite_mblk_ascii().
 */
extern int 
 CST32EXPORTTYPE CST16EXPORTTYPE
pwrite_mblk_ascii(char *file, ut_mblk *mblk, u8 *pphr, size_t len, 
                       u8 *xorstr, u8 *salt, int c, int ichk);


/* Function:    <pread_mblk_ascii>
 * Summary:     Reads passphrase protected data from disc.
 * Syntax:      rval = pread_mblk_ascii(filename, mblk, passphrase, len, xorstring,
 *                               salt, c, ichk);
 * Description: Reads a passphrase protected mblk from disc. 
 *              filename is the name of the input file.
 *              mblk->data will contain the decrypted data.
 *              passphrase is the passphrase.
 *              len is the length of the passphrase.
 *              xorstring is a pointer to a pseudo-random string which was 
 *              XORed with passphrase on entry so that it would not be too 
 *              obvious if swapped out to disk. If xorstring (not *xorstring)
 *              == 0 no xoring is performed.
 *              salt is an eight-byte string appended to passphrase to frustrate
 *              dictionary attacks. If salt = 0 no salt is used; otherwise it
 *              must be retrieved from somewhere.
 *              c is the number of times the passphrase + salt are to be hashed
 *              to get the key -- this should be small for a long passphrase
 *              and big for a short passphrase, to foil timing attacks. If
 *              c == 0 it is set equal to 1 within the function -- this is so
 *              the simplest possible implementation goes pwrite_mblk(filename,
 *               mblk, passphrase, len, 0, 0, 0, 0).
 *              ichk is a flag saying whether to carry out an integrity
 *              check (ichk == 1) or not (ichk == 0). If ichk == 1 a hash of the
 *              key is calculated and compared with the first twenty bytes of
 *              the input data; if they agree the remainder is decrypted. ichk
 *              == 0 gives pkcs-5 compliant pass phrase protection.
 *              Passphrase+salt are hashed c times with SHA-1; the first eight 
 *              bytes of the final hash form the key, and the last eight bytes
 *              the IV, to CBC-DES decrypt the data in filename and place it
 *              in mblk->data.
 *              Note that all three of salt, c and ichk must be the same as
 *              in the corresponding call to pwrite_mblk() for the decryption
 *              to succeed.
 * Failure:     Returns 0 on failure to stat, open or read from file, failure
 *              of integrity check, failure to hash, or failure to decrypt.
 * Notes:       pread_mblk() is defined as a macro. If _UNICODE is defined it
 *              wraps pread_mblk_unicode(). If _UNICODE is not defined it
 *              wraps pread_mblk_ascii().
 */
extern int 
 CST32EXPORTTYPE CST16EXPORTTYPE
pread_mblk_ascii(char *file, ut_mblk *mblk, u8 *pphr, size_t len, 
                       u8 *xorstr, u8 *salt, int c, int ichk);


/* Function:    <write_mblk_unicode>
 * Summary:     Writes data to a file.
 * Syntax:      rval = write_mblk_unicode(filename, mblk);
 * Description: Opens filename and writes mblk->data to it.
 * Failure:     On failure to open or write to file, returns 0.
 * Notes:       write_mblk() is defined as a macro. If _UNICODE is defined it
 *              wraps write_mblk_unicode(). If _UNICODE is not defined it
 *              wraps write_mblk_ascii().
 */
#ifndef CST_NO_UNICODE
int
CST32EXPORTTYPE CST16EXPORTTYPE
write_mblk_unicode(wchar_t *file, ut_mblk *mblk);

/* Function:    <read_mblk_unicode>
 * Summary:     Reads data from a file.
 * Syntax:      rval = read_mblk_unicode(filename, mblk)
 * Description: Opens filename and reads contents into mblk->data, setting
 *              mblk->size and mblk->used appropriately.
 * Failure:     Returns 0 on failure to stat, open or read from file.
 * Notes:       read_mblk() is defined as a macro. If _UNICODE is defined it
 *              wraps read_mblk_unicode(). If _UNICODE is not defined it
 *              wraps read_mblk_ascii().
 */
int
CST32EXPORTTYPE CST16EXPORTTYPE
read_mblk_unicode(wchar_t *file, ut_mblk *mblk);

/* Function:    <pwrite_mblk_unicode>
 * Summary:     Stores passphrase protected data to disc.
 * Syntax:      rval = pwrite_mblk_unicode(filename, mblk, passphrase, len,
 *                xorstring, salt, c, ichk);
 * Description: Stores a passphrase protected mblk to disc. 
 *              filename is the name of the output file.
 *              mblk->data will be output.
 *              passphrase is the passphrase.
 *              len is the length of the passphrase.
 *              xorstring is a pointer to a pseudo-random string which was 
 *              XORed with passphrase on entry so that it would not be too 
 *              obvious if swapped out to disk. If xorstring (not *xorstring)
 *              == 0 no xoring is performed.
 *              salt is an eight-byte string appended to passphrase to frustrate
 *              dictionary attacks. If salt = 0 no salt is used; if *salt = 0
 *              a salt string is generated and returned in salt -- eight
 *              bytes of memory must have been allocated for this, and it is
 *              up to the user to store the salt securely. 
 *              c is the number of times the passphrase + salt are to be hashed
 *              to get the key -- this should be small for a long passphrase
 *              and big for a short passphrase, to foil timing attacks. If
 *              c == 0 it is set equal to 1 within the function -- this is so
 *              the simplest possible implementation goes pwrite_mblk(filename,
 *              mblk, passphrase, len, 0, 0, 0, 0).
 *              ichk is a flag saying whether to carry out an integrity
 *              check (ichk == 1) or not (ichk == 0). If ichk == 1 a hash of the
 *              key is prepended to the output encrypted data. Setting ichk == 0
 *              gives pkcs-5 compliant pass phrase protection.
 *              Passphrase+salt are hashed c times with SHA-1; the first eight 
 *              bytes of the final hash form the key, and the last eight bytes
 *              the IV, to CBC-DES encrypt mblk->data and output it to
 *              filename. 
 * Failure:     Returns 0 on failure to open or write to file,
 *              failure to hash, or failure to encrypt.
 * Notes:       pwrite_mblk() is defined as a macro. If _UNICODE is defined it
 *              wraps pwrite_mblk_unicode(). If _UNICODE is not defined it
 *              wraps pwrite_mblk_ascii().
 */
int
CST32EXPORTTYPE CST16EXPORTTYPE
pwrite_mblk_unicode(wchar_t *file, ut_mblk *mblk, u8 *passphrase, size_t plen,
            u8 *xorstring, u8 *salt, int c, int integ_check);

/* Function:    <pread_mblk_unicode>
 * Summary:     Reads passphrase protected data from disc.
 * Syntax:      rval = pread_mblk_unicode(filename, mblk, passphrase, len, xorstring,
 *                               salt, c, ichk);
 * Description: Reads a passphrase protected mblk from disc. 
 *              filename is the name of the input file.
 *              mblk->data will contain the decrypted data.
 *              passphrase is the passphrase.
 *              len is the length of the passphrase.
 *              xorstring is a pointer to a pseudo-random string which was 
 *              XORed with passphrase on entry so that it would not be too 
 *              obvious if swapped out to disk. If xorstring (not *xorstring)
 *              == 0 no xoring is performed.
 *              salt is an eight-byte string appended to passphrase to frustrate
 *              dictionary attacks. If salt = 0 no salt is used; otherwise it
 *              must be retrieved from somewhere.
 *              c is the number of times the passphrase + salt are to be hashed
 *              to get the key -- this should be small for a long passphrase
 *              and big for a short passphrase, to foil timing attacks. If
 *              c == 0 it is set equal to 1 within the function -- this is so
 *              the simplest possible implementation goes pwrite_mblk(filename,
 *               mblk, passphrase, len, 0, 0, 0, 0).
 *              ichk is a flag saying whether to carry out an integrity
 *              check (ichk == 1) or not (ichk == 0). If ichk == 1 a hash of the
 *              key is calculated and compared with the first twenty bytes of
 *              the input data; if they agree the remainder is decrypted. ichk
 *              == 0 gives pkcs-5 compliant pass phrase protection.
 *              Passphrase+salt are hashed c times with SHA-1; the first eight 
 *              bytes of the final hash form the key, and the last eight bytes
 *              the IV, to CBC-DES decrypt the data in filename and place it
 *              in mblk->data.
 *              Note that all three of salt, c and ichk must be the same as
 *              in the corresponding call to pwrite_mblk() for the decryption
 *              to succeed.
 * Failure:     Returns 0 on failure to stat, open or read from file, failure
 *              of integrity check, failure to hash, or failure to decrypt.
 * Notes:       pread_mblk() is defined as a macro. If _UNICODE is defined it
 *              wraps pread_mblk_unicode(). If _UNICODE is not defined it
 *              wraps pread_mblk_ascii().
 */
int
CST32EXPORTTYPE CST16EXPORTTYPE
pread_mblk_unicode(wchar_t *file, ut_mblk *mblk, u8 *passphrase, size_t plen,
           u8 *xorstring, u8 *salt, int c, int integ_check);

#endif /* #ifndef CST_NO_UNICODE */


#ifdef _UNICODE
#  define write_mblk(f,m) write_mblk_unicode(f,m)
#  define read_mblk(f,m) read_mblk_unicode(f,m)
#  define pwrite_mblk(f,m,pp,pl,xs,sl,c,ic) \
      pwrite_mblk_unicode(f,m,pp,pl,xs,sl,c,ic)
#  define pread_mblk(f,m,pp,pl,xs,sl,c,ic) \
      pread_mblk_unicode(f,m,pp,pl,xs,sl,c,ic)
#else
#  define write_mblk(f,m) write_mblk_ascii(f,m)
#  define read_mblk(f,m) read_mblk_ascii(f,m)
#  define pwrite_mblk(f,m,pp,pl,xs,sl,c,ic) \
      pwrite_mblk_ascii(f,m,pp,pl,xs,sl,c,ic)
#  define pread_mblk(f,m,pp,pl,xs,sl,c,ic) \
      pread_mblk_ascii(f,m,pp,pl,xs,sl,c,ic)
#endif /* def/ndef _UNICODE */


#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* not _CSTIO_H */

