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
 * msf_cmmn.h
 *
 * Created by Anders Edenbrandt, Fri Mar 16 13:01:30 2001.
 *
 * Common utilities for the Mobile Internet Client.
 *
 * Revision history:
 *   010509, AED: New functions, cmmn_skip_blanks and cmmn_skip_field.
 *   010629, AED: General reorganization and cleanup.
 *                Functions for string lookup.
 *   010720, FKN: REQUEST_METHOD_OPTIONS, REQUEST_METHOD_CONNECT added
 *   010806, NKE: Added const to some parameters.
 *   010829, AED: Change in cmmn_skip_field.
 *                New function, cmmn_skip_trailing_blanks
 *   010907, NKE: New function: cmmn_hex2long.
 *   010926, AED: Deleted WCHAR-routines, not needed anymore.
 *                Moved all memory-allocation routines to memalloc.h
 *   011003, AED: New function, cmmn_strcat.
 *   011003, FKN: Connection types moved to capimic.h
 *   011129, AED: New functions, cmmn_strcmp_nc, and cmmn_strncmp_nc
 *   011206, AED: New functions for UTF-8 string handling.
 *   020402, IPN: Changed to fit Mobile Suite Framework.
 *   020912, AED: New functions to convert date-time strings.
 *   050428, MAAR: ICR17556. msf_cmmn_time2str() now return number of bytes.
 *
 */
#ifndef _msf_cmmn_h
#define _msf_cmmn_h

#ifndef _msf_def_h
#include "msf_def.h"
#endif


/**********************************************************************
 * General constants and macros
 **********************************************************************/


#ifdef ABS
#undef ABS
#endif
#define ABS(a)   (((a) < 0) ? (-(a)) : (a))

#ifdef MAX
#undef MAX
#endif
#define MAX(a, b) ((a) > (b) ? (a) : (b))

#ifdef MIN
#undef MIN
#endif
#define MIN(a, b) ((a) < (b) ? (a) : (b))


/**********************************************************************
 * Global variables
 **********************************************************************/

/* Array of all ASCII characters, lower case only. */
extern const unsigned char msf_ascii_lc[256];


/**********************************************************************
 * Basic string-handling functions
 **********************************************************************/

/*
 * Return a copy of the null-terminated string 's'.
 * If s == NULL, this function returns NULL.
 * NOTE: it is the caller's responsibility to deallocate the
 * returned string.
 */
char *
msf_cmmn_strdup (MSF_UINT8 modId, const char *s);

/*
 * Return a copy of the string 's' of length at most 'len' characters.
 * Copying stops if a null-byte is found.
 * NOTE: if s == NULL, this function returns a pointer
 * to a null-terminated string of length 0. THIS MAY CHANGE IN THE FUTURE!
 * NOTE: it is the caller's responsibility to deallocate the
 * returned string.
 */
char *
msf_cmmn_strndup (MSF_UINT8 modId, const char *s, int len);

/*
 * Create and return a new string which holds the concatenation
 * of strings 's1' and 's2'.
 * NOTE: it is the caller's responsibility to deallocate the
 * returned string.
 */
char *
msf_cmmn_strcat (MSF_UINT8 modId, const char *s1, const char *s2);

/*
 * Create and return a new string which holds the concatenation
 * of strings 's1' and len2 bytes of 's2'.
 * NOTE: it is the caller's responsibility to deallocate the
 * returned string.
 */
char *
msf_cmmn_strncat (MSF_UINT8 modId, const char *s1, const char *s2, int len2);
/*
 * Create and return a new string which holds the concatenation
 * of three strings 's1', 's2' and 's3'.
 * NOTE: it is the caller's responsibility to deallocate the
 * returned string.
 */
char *
msf_cmmn_str3cat (MSF_UINT8    modId,
                  const char  *s1,
                  const char  *s2,
                  const char  *s3);

/*
 * Return a pointer to the first occurrence of the character 'c'
 * in the string 's'. The search stops at a null-byte or after
 * at most 'len' characters.
 */
char *
msf_cmmn_strnchr (const char *s, char c, int len);

/*
 * Copy the null-terminated string 'src' to 'dst',
 * while changing all uppercase letters to lower case.
 */
void
msf_cmmn_strcpy_lc (char *dst, const char *src);

/*
 * Copy at most 'len' characters from the string 'src' to 'dst',
 * while changing all uppercase letters to lower case.
 */
void
msf_cmmn_strncpy_lc (char *dst, const char *src, int len);

/*
 * Return the lower-case version of the character 'c'.
 */
char
msf_cmmn_chrlc (char c);

/*
 * Perform a string comparison just like strcmp,
 * but without regard to case.
 * NOTE: only upper and lower case versions
 * of ASCII characters are treated as equal!
 */
int
msf_cmmn_strcmp_nc (const char *s1, const char *s2);

/*
 * Perform a string comparison just like strncmp,
 * but without regard to case.
 * NOTE: only upper and lower case versions
 * of ASCII characters are treated as equal!
 */
int
msf_cmmn_strncmp_nc (const char *s1, const char *s2, int len);

/*
 * Write a textual representation of a byte as two letters "XY",
 * being the hexadecimal digits that represent the value of the byte.
 * The string is written to the location indicated by 's'.
 */
void
msf_cmmn_byte2hex (unsigned char b, char *s);

/*
 * Read a string representation, consisting of two hexadecimal
 * digits, and store the byte value it represents in the location
 * indicated by 'b'.
 * Returns FALSE if the string 's' does not start with two
 * hexadecimal digits, and TRUE otherwise.
 */
int
msf_cmmn_hex2byte (const char *s, unsigned char *b);

/*
 * Read a null-terminated string consisting of hexadecimal digits,
 * and return the integer value it represents.
 */
int
msf_cmmn_hex2int (const char *s);

/*
 * Read a null-terminated string consisting of hexadecimal digits,
 * and return the integer value it represents.
 */
long
msf_cmmn_hex2long (const char *s);

/*
 * Given a UTF-8 encoded null-terminated string,
 * return the number of Unicode characters in the string.
 */
int
msf_cmmn_utf8_strlen (const char *s);

/*
 * Given a UTF-8 encoded string of length 'len' bytes,
 * return the number of Unicode characters in the string.
 */
int
msf_cmmn_utf8_strnlen (const char *s, int len);

/*
 * Given a UTF-8 encoded string,
 * return the number of bytes in the first Unicode character.
 */
int
msf_cmmn_utf8_charlen (const char *s);

/*
 * Given a UTF-8 encoded null-terminated string,
 * move 'steps' Unicode characters forward and return
 * a pointer to the new position.
 */
char *
msf_cmmn_utf8_str_incr (const char *s, int steps);


/**********************************************************************
 * Other string functions
 **********************************************************************/

/*
 * Return a pointer to the first non-blank character
 * in the string 's'. A blank character is either SP or TAB.
 */
char *
msf_cmmn_skip_blanks (const char *s);

/*
 * Return a pointer to the first white space character
 * in the string 's', or the NULL character terminating the string.
 * A white space character is either SP, TAB, CR, or LF.
 */
char *
msf_cmmn_skip_field (const char *s);

/*
 * Given a string 's' and its length, return the length
 * of that string if trailing white space were omitted.
 * A white space character is either SP, TAB, CR, or LF.
 */
int
msf_cmmn_skip_trailing_blanks (const char *s, int len);

/*
 * Return the number of characters needed to decode
 * the string 'str' of length 'len'.
 */
int
msf_cmmn_base64_decode_len (const char *str, int len);

/*
 * Given a string of base64-encoded data, decode it and
 * place it in the output buffer.
 * On input, 'outlen' should hold the maximum size of the output buffer,
 * on output, it will hold the number of bytes placed in the output buffer .
 *
 * Returns 0 if OK, and -1 on error.
 */
int
msf_cmmn_base64_decode (const char *inbuf, int inlen, char *outbuf, int *outlen);

/*
 * Return the number of characters needed to encode
 * a string of length 'len'.
 */
int
msf_cmmn_base64_encode_len (int len);

/*
 * Given a string of data, create a base-64 encoding
 * of said data, and place it in the output buffer.
 * On input, 'outlen' should hold the maximum size of the output buffer,
 * on output, it will hold the length of the string written there.
 * The encoded string will be null-terminated.
 *
 * Returns 0 if OK, and -1 on error.
 */
int
msf_cmmn_base64_encode (const char *inbuf, int inlen, char *outbuf, int *outlen);


/**********************************************************************
 * Date-time conversions
 **********************************************************************/

/*
 * Converts a string (e.g. "Thu, 15 Nov 2001 08:12:31 GMT") into a
 * Unix 31-bit time value (seconds since 1/1 1970, GMT).
 * The date as a string can be in any of several different formats:
 *   "Sun, 06 Nov 1994 08:49:37 GMT"           RFC 822, updated by RFC 1123
 *   "Sunday, 06-Nov-94 08:49:37 GMT"          RFC 850, obsoleted by RFC 1036
 *   "Sun Nov  6 08:49:37 1994"                ANSI C's asctime() format
 *   "6 Nov 94 08:49:37 EST"                   One of many obsolete forms
 *   "[Sun,] 6 Nov 1994 08:49[:37] +0000"      RFC 2822
 *
 * The result is stored in 't'.
 * Returns TRUE on sucess, else FALSE.
 */
int
msf_cmmn_str2time (const char *s, MSF_UINT32 *t);

/*
 * Format a Unix 31-bit time value (seconds since 1/1 1970, GMT)
 * as a string in the format: "Thu, 15 Nov 2001 08:12:31 GMT"
 * (as specified in RFC 1123).
 * The parameter 't' is the given time, and the formatted string
 * is written to the string 's'.
 * Return the number of bytes written or -1 if something
 * went wrong.
 * NOTE: the string 's' must have room for at least 30 bytes.
 */
int
msf_cmmn_time2str (MSF_UINT32 t, char *s);


typedef struct  msf_cmmn_duration_t{
  MSF_UINT32          years;
  MSF_UINT32          months;
  MSF_UINT32          days;
  MSF_UINT32          hours;
  MSF_UINT32          minutes;
  MSF_UINT32          seconds;
} msf_cmmn_duration_t;

/* Parses a "duration" string (e.g. "PnYnMnDTnHnMnS") as defined in 
 * "XML Schema Part 2: Datatypes. W3C Recommendation 2 May 2001" 
 * and return the result in the duration struct
 */
void
msf_cmmn_parse_duration(const char *s, msf_cmmn_duration_t *duration);

/**********************************************************************
 * String lookup in hash tables
 **********************************************************************/

/* Different search methods for finding an integer in a string table. */
#define MSF_TABLE_SEARCH_INDEXING                 1
#define MSF_TABLE_SEARCH_BINARY                   2
#define MSF_TABLE_SEARCH_LINEAR                   3


/* A string table is an array of elements of this type: */
typedef struct {
  const char *name;
  int         value;
} msf_strtable_entry_t;

/* A string table should be complemented with a hash table
 * (automatically generated), and all the information about
 * the tables is collected in a structure of this kind: */
typedef struct {
  const unsigned char        *hash_table;
  int                         hash_table_size;
  short                       search_method;
  const msf_strtable_entry_t *string_table;
  int                         string_table_size;
} msf_strtable_info_t;


/*
 * Look up a string in the supplied hash table, and return
 * its associated integer value.
 * Returns -1 if the string was not found.
 */
int
msf_cmmn_str2int (const char *name, int length, const msf_strtable_info_t *info);

/*
 * Look up a string in the supplied hash table, and return
 * its associated integer value.
 *
 * Lower-case version. When hashing and matching, all upper-
 * case ASCII characters are regarded as their lower-case
 * counterparts. Consequently the 'info' string table can
 * only contain lower-case strings.
 *
 * Returns -1 if the string was not found.
 */
int
msf_cmmn_str2int_lc (const char *name, int length, const msf_strtable_info_t *info);

/*
 * Look up an integer value in the supplied hash table,
 * and return its associated string.
 * Returns NULL if the integer value was not found.
 * NOTE: the caller MUST NOT deallocate the returned string!
 */
const char *
msf_cmmn_int2str (int value, const msf_strtable_info_t *info);


/**********************************************************************
 * Misc routines
 **********************************************************************/

/*
 * Hash function. Given a string of indicated length,
 * this function returns a 32-bit unsigned integer
 * calculated over all positions in the string.
 */
MSF_UINT32
msf_cmmn_strhash (const char *str, int length);

/*
 * Hash function. Given a string of indicated length,
 * this function returns a 32-bit unsigned integer
 * calculated over all positions in the string.
 *
 * Lower-case version. All upper-case ASCII
 * characters are regarded as their lower-case
 * counterparts.
 */
MSF_UINT32
msf_cmmn_strhash_lc (const char *s, int len);

#endif
