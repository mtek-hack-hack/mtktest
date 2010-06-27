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
 * msf_chrs.h
 *
 * Created by Anders Edenbrandt, Mon May 14 14:47:28 2001.
 *
 *
 * Revision history:
 *   010629, AED: New functions to convert to UTF8.
 *                Hash table for charset names.
 *   010806, NKE: Changed src-parameter to const for codecvt_convert_t.
 *   020429, AED: Modified to fit into Mobile Suite Framework.
 *
 */
#ifndef _msf_chrs_h
#define _msf_chrs_h

#ifndef _msf_def_h
#include "msf_def.h"
#endif

/**********************************************************************
 * Constants
 **********************************************************************/

#define MSF_CHARSET_UNKNOWN       0
#define MSF_CHARSET_ASCII         3
#define MSF_CHARSET_ISO_8859_1    4
#define MSF_CHARSET_LATIN_1       4
#define MSF_CHARSET_UCS_2         1000
#define MSF_CHARSET_UTF_16BE      1013
#define MSF_CHARSET_UTF_16LE      1014
#define MSF_CHARSET_UTF_16        1015
#define MSF_CHARSET_UTF_8         106


/**********************************************************************
 * Type definitions:
 **********************************************************************/

/*
 * Convert the string in 'src' from one character encoding to another.
 * The conversion stops if either the source buffer is exhausted,
 * or the destination buffer becomes full. If 'dst' is NULL,
 * no characters are written to the destination but the size
 * indicators, '*srcLen' and '*dstLen' are still updated.
 * This way, one can use a first call to the conversion function
 * to find out how large a destination buffer is needed to do
 * the conversion.
 *
 * NOTE: This routine must always convert an integral number of
 * characters from the source set. For example, if converting
 * from UTF-8 and there is only the first byte of a 2-byte
 * encoding left, then the source buffer is considered exhausted.
 *
 * Returns 0 on success and -1 on failure (i.e., if an illegal
 * character was detected in the input sequence).
 */
typedef int
msf_charset_convert_t (const char *src, /* The source buffer. */

                       long *srcLen,    /* On input, the number of bytes
                                         * available in the source buffer;
                                         * on output, the number of source
                                         * bytes consumed. */

                       char *dst,       /* The destination buffer. */

                       long *dstLen);   /* On input, the amount of free space
                                         * in the destination buffer;
                                         * on output, the number of bytes
                                         * placed in the output buffer. */



/**********************************************************************
 * Global Variables:
 **********************************************************************/

/*
 * Unicode character code offsets for UTF-8 encodings
 * that consist of 1, 2, 3 or 4 bytes. Index the array
 * with the number of bytes in the UTF-8 encoding.
 */
extern const MSF_UINT32 msf_charset_offsets_from_utf8[5];

/*
 * Number of bytes per UTF-8 character. To be indexed with the
 * first 4 bits of an UTF-8 character.
 */
extern const unsigned char msf_charset_utf8_bytes_per_character[16];


/**********************************************************************
 * Misc Functions:
 **********************************************************************/

/*
 * Find a suitable conversion function that can convert
 * from charset 'fromCharset' to charset 'toCharset'.
 * Returns NULL if no matching conversion function could be found.
 */
msf_charset_convert_t *
msf_charset_find_function (int fromCharset, int toCharset);

/*
 * Find a suitable conversion function that can convert
 * from charset 'fromCharset' to charset 'toCharset',
 * using any Byte-Order Mark that might be present in the source.
 * On calling this function, the parameter '*len' should hold the number
 * of bytes available in 'src', and on return '*len' is either 0
 * (if no BOM was found) or 2 (if a 2 byte BOM was found).
 * If there is no BOM, but 'fromCharset' is an ambigous character encoding
 * (that is, UCS-2 or UTF-16) then this function will attempt to guess
 * the byte order by checking if either of the two first bytes is zero.
 * Returns NULL if no matching conversion function could be found.
 */
msf_charset_convert_t *
msf_charset_find_function_bom (int fromCharset, int toCharset, const char *src, int *len);

/*
 * Given an integer representation of a charset,
 * return a pointer to a string holding the name of that charset.
 * NOTE: the caller MUST NOT deallocate or modify the returned string!
 */
const char *
msf_charset_int2str (int charset);

/*
 * Given a charset name as a string, return its integer value.
 * Returns -1 if the string does not have an integer representation.
 */
int
msf_charset_str2int (const char *name, int length); 

/*
 * Convert one Unicode character encoded as UTF-8 to its Unicode character code.
 * The character code is stored in the location pointed to by 'uc'.
 * Returns the number of bytes used from the UTF-8 string, or -1 on error.
 */
int
msf_charset_utf8_to_unicode (const char *s, MSF_UINT32 *uc);

/*
 * Convert one Unicode character to UTF-8. The encoded string is stored in 's'.
 * Returns the number of bytes stored, or -1 on error.
 */
int
msf_charset_unicode_to_utf8 (MSF_UINT32 uc, char *s);


/**********************************************************************
 * Character Encoding Conversion Functions:
 **********************************************************************/

int
msf_charset_ascii_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen);

int
msf_charset_latin1_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen);

int
msf_charset_utf16be_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen);

int
msf_charset_utf16le_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen);

int
msf_charset_utf16_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen);

int
msf_charset_ucs2be_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen);

int
msf_charset_ucs2le_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen);

int
msf_charset_ucs2_to_utf8 (const char *src, long *srcLen, char *dst, long *dstLen);


int
msf_charset_utf8_to_ascii (const char *src, long *srcLen, char *dst, long *dstLen);

int
msf_charset_utf8_to_latin1 (const char *src, long *srcLen, char *dst, long *dstLen);

int
msf_charset_utf8_to_utf16be (const char *src, long *srcLen, char *dst, long *dstLen);

int
msf_charset_utf8_to_utf16le (const char *src, long *srcLen, char *dst, long *dstLen);

int
msf_charset_utf8_to_utf16 (const char *src, long *srcLen, char *dst, long *dstLen);

int
msf_charset_utf8_to_ucs2be (const char *src, long *srcLen, char *dst, long *dstLen);

int
msf_charset_utf8_to_ucs2le (const char *src, long *srcLen, char *dst, long *dstLen);

int
msf_charset_utf8_to_ucs2 (const char *src, long *srcLen, char *dst, long *dstLen);


int
msf_charset_ascii_to_utf16be (const char *src, long *srcLen, char *dst, long *dstLen);

int
msf_charset_ascii_to_utf16le (const char *src, long *srcLen, char *dst, long *dstLen);


int
msf_charset_latin1_to_utf16be (const char *src, long *srcLen, char *dst, long *dstLen);

int
msf_charset_latin1_to_utf16le (const char *src, long *srcLen, char *dst, long *dstLen);


int
msf_charset_utf16be_to_utf16le (const char *src, long *srcLen, char *dst, long *dstLen);

int 
msf_charset_utf8_to_utf8 (const char *src, long *src_len, char *dst, long *dst_len);

#endif
