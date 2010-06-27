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

/*#include "stddef.h"*/ /* for size_t *//* Removed 14/5 2001 LOKO */
																				/* size_t is defined in uttypes.h (included in ut.h) */
#include "ut.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Function:     <ut_sizeof_bin2cdkx>
 * Summary:      The number of bytes needed to store binary data in CDK format.
 * Syntax:       size_t olen = ut_sizeof_bin2cdkx(size_t ilen);
 * Description:  The ut_sizeof_bin2cdkx() function returns the number of 
 *               octets of memory needed to store ilen octets of data in the 
 *               CDK's "binary" format. This format consists of an ASCII hex 
 *               dump of the binary data. The number returned is 2*ilen + 1
 *               (for the terminating NULL byte)
 * Returns:      The number of octets of memory needed to to ilen octets of 
 *               data in the CDK's "binary" format.
 */
size_t
ut_sizeof_bin2cdkx(size_t ilen);

/* Function:     <ut_bin2cdkx>
 * Summary:      Store binary data in CDK format.
 * Syntax:       u8 *rval = ut_bin2cdkx(u8 *data, size_t ilen, char *dest);
 * Description:  The ut_bin2cdkx() writes ilen octets of data to dest in the 
 *               CDK's "binary" format. This format consists of an ASCII hex 
 *               dump of the binary data. It returns a pointer to the byte 
 *               after the last byte written. At least ut_sizeof_bin2cdkx()
 *               octets of memory must have been allocated at dest prior to
 *               calling this function.
 * Returns:      A pointer to the byte after the last byte written. Doesn't
 *               fail.
 */
u8 *
ut_bin2cdkx(u8 *data, size_t ilen, u8 *dest);

/* Function:     <ut_sizeof_cdkx2bin>
 * Summary:      The number of bytes needed to store CDK data as binary data.
 * Syntax:       size_t olen = ut_sizeof_cdkx2bin(const char *cdata);
 * Description:  The ut_sizeof_cdkx2bin() function returns the maximum number 
 *               of octets of memory needed to store the data from cdata as
 *               binary. We read from cdata to the first character that is
 *               not a-f, A-F, 0-9 or a white space and return (no of non-
 *               whitespace characters + 1)/2.
 * Returns:      The number of octets of memory needed to store the data from
 *               cdata as binary.
 */
size_t
ut_sizeof_cdkx2bin(const char *cdata);

/* Function:     <ut_cdkx2bin>
 * Summary:      Store binary data in CDK format.
 * Syntax:       u8 *rval = ut_cdkx2bin(const char *cdata, u8 *dest);
 * Description:  The ut_cdkx2bin() converts the ASCII hex-dumped binary
 *               data at cdata to straightforward binary data at dest. At 
 *               least ut_sizeof_cdkx2bin octets of memory must have been
 *               allocated at dest.
 *               We read the hex data at cdata until we reach a character
 *               other than 0-9, a-f, A-F or " ". If this results in an odd 
 *               number of characters there is taken to be an implicit 
 *               leading 0; each group of two characters is then converted 
 *               into a single byte and written to dest. We return a pointer 
 *               to the byte after the last byte written.
 * Returns:      A pointer to the byte after the last byte written. Doesn't
 *               fail.
 */
u8 *
ut_cdkx2bin(const char *cdata, u8 *dest);

int
cdk_privkey2mblk(char *n, char *e, char *d, char *p, 
                 char *q, char * dcrtp, char *dcrtq, 
                 char *qcrtp, ut_mblk *privblk);

int
cdk_pubkey2mblk(char *n, char *e, ut_mblk *pubblk);


/* allocates memory at e, n, p and d for private keys, e and n for public
 * keys. If you KNOW the key being passed in is a public key you can 
 * safely set p and d to 0. 
 *
 * Only reads PKCS#1 style keys.
 */
int
cdk_mblk2key(ut_mblk *in, char **e, char **n, char **p, char **d);



#ifdef __cplusplus
}
#endif
