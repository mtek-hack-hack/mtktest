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
 * msf_url.h
 *
 * Library of routines for handling URLs.
 *
 * Created by Anders Edenbrandt.
 *
 * Revision history:
 *   010926, AED: New function, url_find_path.
 *   011003, AED: New functions, url_drop_fragment, url_add_fragment.
 *   011004, AED: New function, url_wmls_escape_string.
 *   011015, AED: New function, url_wmls_unescape_string.
 *   020510, AED: Modified for MSF
 *
 */
#ifndef _msf_url_h
#define _msf_url_h

#ifndef _msf_def_h
#include "msf_def.h"
#endif


/**********************************************************************
 * Constants
 **********************************************************************/

/*
 * Bit flags to select one or more of the components of a URL.
 */
#define MSF_URL_NO_COMP                 0
#define MSF_URL_SCHEME_COMP             0x1
#define MSF_URL_USERINFO_COMP           0x2
#define MSF_URL_HOST_COMP               0x4
#define MSF_URL_PORT_COMP               0x8
#define MSF_URL_AUTHORITY_COMP          MSF_URL_USERINFO_COMP | MSF_URL_HOST_COMP |\
                                          MSF_URL_PORT_COMP
#define MSF_URL_PATH_COMP               0x10
#define MSF_URL_QUERY_COMP              0x40
#define MSF_URL_FRAG_COMP               0x80
#define MSF_URL_ALL_COMP                0xff


/*
 * The different parts of a URL, used to index into the arrays
 * in the msf_url_t type.
 */
#define MSF_URL_SCHEME_PART             0
#define MSF_URL_AUTHORITY_PART          1
#define MSF_URL_PATH_PART               2
#define MSF_URL_QUERY_PART              3
#define MSF_URL_FRAGMENT_PART           4
#define MSF_URL_USERINFO_PART           5
#define MSF_URL_HOST_PART               6
#define MSF_URL_PORT_PART               7

#define MSF_URL_NUM_PARTS               8


/**********************************************************************
 * Type definitions
 **********************************************************************/

/* The scheme type */
typedef enum {
	msf_scheme_empty = 0,
	msf_scheme_http = 1,
	msf_scheme_https = 2,
	msf_scheme_file = 3,
	msf_scheme_wtai = 4,
	msf_scheme_about = 5,
	msf_scheme_function = 6,
	msf_scheme_unknown = 99
} msf_scheme_t;


/* The URL type */
typedef struct {
  msf_scheme_t  scheme_type;
  const char   *s[MSF_URL_NUM_PARTS];
  int           len[MSF_URL_NUM_PARTS];
} msf_url_t;


/**********************************************************************
 * Exported functions
 **********************************************************************/

/*
 * Return the scheme type named by the given string. Returns scheme_unknown
 * if its not one of the predefined types.
 */
msf_scheme_t
msf_url_str2scheme (char *sch);

/*
 * Return a string representation of the scheme value.
 * NOTE: the caller must NOT modify or deallocate the returned string!
 */
const char *
msf_url_scheme2str (msf_scheme_t scheme);

/*
 * Compute a hash value from a URL and store it in the location pointed
 * to by "hv". All equivalent URLs will hash to the same value,
 * but two non-equal URLs may also have the same hash value. However,
 * the probability of a collision is small.
 * Returns FALSE on error, TRUE otherwise.
 */
int
msf_url_hash (const char *url, MSF_UINT32 *hv);

/*
 * Given a base URL and a relative URL, resolve the relative reference
 * and store as an absolute URL in the string "*abs".
 * Returns TRUE on success, FALSE otherwise, in which case nothing
 * is stored in "abs".
 * NOTE: It is the callers responsibility to deallocate the returned string.
 */
int
msf_url_resolve (MSF_UINT8 module, const char *base, const char *rel, char **abs);

/*
 * Return TRUE if the two URLs are equal, FALSE otherwise.
 * "which_components" is a bitmap indicating which parts of the URLs
 * should be included in the comparison.
 * Returns FALSE in case of error.
 */
int
msf_url_equal (const char *url1, const char *url2, int which_components);

/*
 * Return TRUE if the given string URL has a valid format, FALSE otherwise.
 */
int
msf_url_is_valid (const char* url);


/************************************************************
 * Retrieval of the different parts of a URL.
 ************************************************************/

/*
 * Take a string representation of a URL and parse it into its
 * components, and store these as fields in the given URL struct.
 * All components are stored in their original (possibly escaped) form.
 * Returns TRUE if the URL could be broken down into its components,
 * and FALSE otherwise.
 * The input parameter "url" is a null-terminated character string.
 */
int
msf_url_parse (const char *url, msf_url_t *urlrec);

/*
 * Given a URL struct, construct and return a string representation
 * of the URL.
 * Returns NULL in case of error.
 * NOTE: It is the callers responsibility to deallocate the returned string.
 */
char *
msf_url_to_string (MSF_UINT8 module, msf_url_t *url);

msf_scheme_t
msf_url_get_scheme_type (const char* url);

/*
 * Extract one part of a URL.
 * Returns NULL in case of error, including that the URL is not valid,
 * or if the URL does not have the requested component.
 * NOTE: it is the responsibility of the caller to deallocate
 * the returned string.
 */
char *
msf_url_get_scheme (MSF_UINT8 module, const char* url);

char *
msf_url_get_host (MSF_UINT8 module, const char* url);

char *
msf_url_get_port (MSF_UINT8 module, const char* url);

char *
msf_url_get_hostport (MSF_UINT8 module, const char* url);

char *
msf_url_get_path (MSF_UINT8 module, const char* url);

char *
msf_url_get_parameters (MSF_UINT8 module, const char* url);

char *
msf_url_get_query (MSF_UINT8 module, const char* url);

char *
msf_url_get_fragment (MSF_UINT8 module, const char* url);


/*
 * Return a pointer to where the path part of the URL begins.
 * NOTE: returns a pointer into the original string, i.e.,
 * does not allocate any new string.
 */
const char *
msf_url_find_path (const char* url);


/*
 * Return a copy of 'url' with the fragment part (if any)
 * removed. Also sets '*fragment' to point to a copy of
 * the fragment part of 'url', or NULL if there is no fragment part.
 * NOTE: it is the responsibility of the caller to deallocate
 * the returned string, as well as the fragment string.
 */
char *
msf_url_drop_fragment (MSF_UINT8 module, const char *url, char **fragment);

/*
 * Return a copy of 'url' with the query part (if any) removed. 
 * NOTE: it is the responsibility of the caller to deallocate
 * the returned string.
 */
char *
msf_url_drop_query (MSF_UINT8 module, const char *url);

/*
 * Return a copy of 'url' with 'fragment' added as the fragment part.
 * If 'url' already has a fragment part, it is replaced with 'fragment'.
 * NOTE: it is the responsibility of the caller to deallocate
 * the returned string.
 */
char *
msf_url_add_fragment (MSF_UINT8 module, const char *url, const char *fragment);


/************************************************************
 * Other utility routines
 ************************************************************/

/*
 * Return a copy of 's' where each character belonging to the set of
 * so called "special characters" or being in the range 0x80-0xff,
 * has been replaced by a hexadecimal esacape sequence of the form "%xy".
 * NOTE: it is the callers responsibility to deallocate the returned string.
 */
char *
msf_url_escape_string (MSF_UINT8 module, const char* s);

/*
 * Return a copy of 's' where each non-ASCII character
 * has been replaced by a hexadecimal esacape sequence of the form "%xy".
 * NOTE: it is the callers responsibility to deallocate the returned string.
 */
char *
msf_url_escape_non_ascii (MSF_UINT8 module, const char* s);

/*
 * Return a copy of 's' where each hexadecimal escape sequence
 * of the form "%xy" has been replaced with the character it represents.
 * Returns NULL in case of error.
 * NOTE: it is the callers responsibility to deallocate the returned string.
 */
char *
msf_url_unescape_string (MSF_UINT8 module, const char* s);

/*
 * Return a copy of 's' where each character belonging to the set of
 * so called "special characters" or being in the range 0x80-0xff,
 * has been replaced by a hexadecimal esacape sequence of the form "%xy".
 * Returns NULL if 's' contains characters whose Unicode representation
 * is greater than 0xff.
 * NOTE: it is the callers responsibility to deallocate the returned string.
 */
char *
msf_url_wmls_escape_string (MSF_UINT8 module, const char* s);

/*
 * Return a copy of 'pbString' where each hexadecimal escape sequence
 * of the form "%xy" has been replaced with the character it represents.
 * Returns NULL if 'ps' contains characters that are not part of
 * the US-ASCII character set.
 * NOTE: it is the callers responsibility to deallocate the returned string.
 */
char*
msf_url_wmls_unescape_string (MSF_UINT8 module, const char* s);

/*
 * Copy the string "src" to the string "dst", while replacing
 * all escape sequences with the characters they represent.
 * Works correctly even if called with the same argument for src and dst.
 */
void
msf_url_unescape_string_in_place (char *dst, const char *src);

/*
 * Check if the given absolute URL has access rights,
 * given 'domain' and 'path' as access control attributes.
 *
 * Assumes that all three strings are zero-terminated character strings,
 * and that 'abs_url' is a valid absolute URL.
 * Returns FALSE if either 'abs_url' or 'domain' is NULL.
 * If 'path' is NULL, the routine works as if it were the path "/".
 *
 * The check is performed by verifying that the domain attribute
 * is a component-wise suffix of the domain part of the absolute URL,
 * and that the path attribute is a component-wise prefix of
 * the path part of the absolute URL. Comparisons of the paths
 * are case-sensitive, but comparisons of the domain components are not.
 * Handles escape sequences ("%xy") correctly.
 */
int
msf_url_check_access (char *abs_url, char *domain, char *path);

/*
 * Take an incomplete URL, like "www.abc.com", and turn it into
 * a correct absolute URL using heuristic methods. This is not a
 * well-defined process, rather it makes a guess as to what the user means.
 * In the example above, the result would be "http://www.abc.com/".
 * In case of failure, NULL is returned.
 * NOTE: it is the caller's responsibility to deallocate the returned string.
 */
char *
msf_url_make_complete (MSF_UINT8 module, char *url);

/*
 * Given two URLs, compute the minimum relative path, i.e., the shortest
 * relative path that together with 'fromUrl' can be resolved to yield
 * 'toUrl'. If 'include_fragment' is TRUE any fragment part in 'toUrl'
 * is included in the result, otherwise it is dropped.
 * Returns NULL in case of error.
 * NOTE: it is the caller's responsibility to deallocate the returned string.
 */
char *
msf_url_min_relative_path (MSF_UINT8 module, char *fromUrl, char *toUrl,
                           int include_fragment);

/*
 * Check that a URL can be parsed and has at least a scheme, host, and path
 * component.
 */
int
msf_url_is_complete (const char* url);

/*
 * Return a URL that is a copy of 'old_url', but with 'new_query'
 * appended to the query part. If 'old_url' already has a query part,
 * that old part will be separated from the new by a '&'-character.
 * Returns NULL in case of error.
 * NOTE: it is the caller's responsibility to deallocate the returned string.
 */
char *
msf_url_append_to_query (MSF_UINT8 module, char *old_url, char *new_query);

/*
 * Return the longest componentwise common prefix of two URL paths.
 * Returns NULL in case of error.
 * NOTE: it is the caller's responsibility to deallocate the returned string.
 */
char *
msf_url_longest_common_prefix (MSF_UINT8 module, char *path1, char *path2);

/*
 * Check if the URL "path1" is a prefix of "path2".
 * The prefix match is done according to the rules in section 7.4
 * in "WAP Cache Operation Specification".
 */
int
msf_url_is_prefix (char *path1, char *path2);

/*
 * Return a copy of 's' where each blank character
 * has been replaced by a hexadecimal esacape sequence of the form "%xy".
 * Returns NULL in case of error.
 * NOTE: it is the caller's responsibility to deallocate the returned string.
 */
char *
msf_url_escape_blanks (MSF_UINT8 module, const char *s);

char *
msf_url_escape_all_string (MSF_UINT8 module, const char* ps, int len);

/*
* Given the string 's' and its length, return 
* the string without white space and it's new length.
* A white space character is either SP, TAB, CR, or LF.
*/
void
msf_url_remove_blanks (char *s, int *len);


#endif
