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
 * msf_hdr.h
 *
 * Created by Anders Edenbrandt, Mon Sep 09 08:13:35 2002.
 *
 * Revision history:
 */
#ifndef _msf_hdr_h
#define _msf_hdr_h

#ifndef _msf_def_h
#include "msf_def.h"
#endif
#ifndef _msf_cmmn_h
#include "msf_cmmn.h"
#endif
#ifndef _msf_mime_h
#include "msf_mime.h"
#endif


/************************************************************ 
 * Constants
 ************************************************************/

/* 
 * Supported header fields.
 * The numeric representation is the one used by WSP.
 * No suffix means that the code belongs to encoding version 1.1-1.2.
 */
#define MSF_HDR_ACCEPT                            0x00
#define MSF_HDR_ACCEPT_CHARSET                    0x01
#define MSF_HDR_ACCEPT_ENCODING                   0x02
#define MSF_HDR_ACCEPT_LANGUAGE                   0x03
#define MSF_HDR_ACCEPT_RANGES                     0x04
#define MSF_HDR_AGE                               0x05
#define MSF_HDR_ALLOW                             0x06
#define MSF_HDR_AUTHORIZATION                     0x07
#define MSF_HDR_CACHE_CONTROL                     0x08
#define MSF_HDR_CONNECTION                        0x09
#define MSF_HDR_CONTENT_BASE                      0x0a
#define MSF_HDR_CONTENT_ENCODING                  0x0b
#define MSF_HDR_CONTENT_LANGUAGE                  0x0c
#define MSF_HDR_CONTENT_LENGTH                    0x0d
#define MSF_HDR_CONTENT_LOCATION                  0x0e
#define MSF_HDR_CONTENT_MD5                       0x0f
#define MSF_HDR_CONTENT_RANGE                     0x10
#define MSF_HDR_CONTENT_TYPE                      0x11
#define MSF_HDR_DATE                              0x12
#define MSF_HDR_ETAG                              0x13
#define MSF_HDR_EXPIRES                           0x14
#define MSF_HDR_FROM                              0x15
#define MSF_HDR_HOST                              0x16
#define MSF_HDR_IF_MODIFIED_SINCE                 0x17
#define MSF_HDR_IF_MATCH                          0x18
#define MSF_HDR_IF_NONE_MATCH                     0x19
#define MSF_HDR_IF_RANGE                          0x1a
#define MSF_HDR_IF_UNMODIFIED_SINCE               0x1b
#define MSF_HDR_LOCATION                          0x1c
#define MSF_HDR_LAST_MODIFIED                     0x1d
#define MSF_HDR_MAX_FORWARDS                      0x1e
#define MSF_HDR_PRAGMA                            0x1f
#define MSF_HDR_PROXY_AUTHENTICATE                0x20
#define MSF_HDR_PROXY_AUTHORIZATION               0x21
#define MSF_HDR_PUBLIC                            0x22
#define MSF_HDR_RANGE                             0x23
#define MSF_HDR_REFERER                           0x24
#define MSF_HDR_RETRY_AFTER                       0x25
#define MSF_HDR_SERVER                            0x26
#define MSF_HDR_TRANSFER_ENCODING                 0x27
#define MSF_HDR_UPGRADE                           0x28
#define MSF_HDR_USER_AGENT                        0x29
#define MSF_HDR_VARY                              0x2a
#define MSF_HDR_VIA                               0x2b
#define MSF_HDR_WARNING                           0x2c
#define MSF_HDR_WWW_AUTHENTICATE                  0x2d
#define MSF_HDR_CONTENT_DISPOSITION               0x2e
#define MSF_HDR_X_WAP_APPLICATION_ID              0x2f
#define MSF_HDR_X_WAP_CONTENT_URI                 0x30
#define MSF_HDR_X_WAP_INITIATOR_URI               0x31
#define MSF_HDR_ACCEPT_APPLICATION                0x32
#define MSF_HDR_BEARER_INDICATION                 0x33
#define MSF_HDR_PUSH_FLAG                         0x34
#define MSF_HDR_PROFILE                           0x35
#define MSF_HDR_PROFILE_DIFF                      0x36
#define MSF_HDR_PROFILE_WARNING                   0x37
#define MSF_HDR_EXPECT                            0x38
#define MSF_HDR_TE                                0x39
#define MSF_HDR_TRAILER                           0x3a
#define MSF_HDR_ACCEPT_CHARSET_1_3                0x3b
#define MSF_HDR_ACCEPT_ENCODING_1_3               0x3c
#define MSF_HDR_CACHE_CONTROL_1_3                 0x3d
#define MSF_HDR_CONTENT_RANGE_1_3                 0x3e
#define MSF_HDR_X_WAP_TOD                         0x3f
#define MSF_HDR_CONTENT_ID                        0x40
#define MSF_HDR_SET_COOKIE                        0x41
#define MSF_HDR_COOKIE                            0x42
#define MSF_HDR_ENCODING_VERSION                  0x43
#define MSF_HDR_PROFILE_WARNING_1_4               0x44
#define MSF_HDR_CONTENT_DISPOSITION_1_4           0x45
#define MSF_HDR_X_WAP_SECURITY                    0x46
#define MSF_HDR_CACHE_CONTROL_1_4                 0x47
#define MSF_HDR_EXPECT_1_5                        0x48
#define MSF_HDR_X_WAP_LOC_INVOCATION              0x49
#define MSF_HDR_X_WAP_LOC_DELIVERY                0x4a

/* The following headers do not have any WSP values. */
#define MSF_HDR_X_WAP_CPITAG                      0x6e
#define MSF_HDR_X_WAP_PUSH_PROVURL                0x6f
#define MSF_HDR_X_WAP_PUSH_ACCEPT                 0x70
#define MSF_HDR_X_WAP_PUSH_ACCEPT_CHARSET         0x71
#define MSF_HDR_X_WAP_PUSH_ACCEPT_ENCODING        0x72
#define MSF_HDR_X_WAP_PUSH_ACCEPT_LANGUAGE        0x73
#define MSF_HDR_X_WAP_PUSH_ACCEPT_APP_ID          0x74
#define MSF_HDR_X_WAP_PUSH_MSG_SIZE               0x75 
#define MSF_HDR_X_WAP_PUSH_ACCEPT_MAX_PUSH_REQ    0x76 
#define MSF_HDR_X_WAP_TERMINAL_ID                 0x77
#define MSF_HDR_X_WAP_PUSH_INFO                   0x78
#define MSF_HDR_X_WAP_PUSH_STATUS                 0x79
#define MSF_HDR_X_WAP_PUSH_OTA_VERSION            0x7a
#define MSF_HDR_X_WAP_BEARER_INDICATION           0x7b
#define MSF_HDR_X_WAP_AUTHENTICATE                0x7c
#define MSF_HDR_X_WAP_AUTHORIZATION               0x7d
#define MSF_HDR_X_WAP_PROFILE                     0x7e
#define MSF_HDR_X_WAP_PROFILE_DIFF                0x7f
#define MSF_HDR_X_WAP_PROFILE_WARNING             0x80
#define MSF_HDR_X_UP_TPD_E2E_HEADERS              0x81
#define MSF_HDR_X_FORWARDED_FOR                   0x82
#define MSF_HDR_CONTENT_TRANSFER_ENCODING         0x83
#define MSF_HDR_REFRESH                           0x84
#define MSF_HDR_X_DRM                             0x85
#define MSF_HDR_SET_COOKIE2                       0x86                     
#define MSF_HDR_COOKIE2                           0x87
#define MSF_HDR_X_VODAFONE_3GPDP_CONTEXT          0x88
#define MSF_HDR_X_OMA_DRM_SEPARATE_DELIVERY       0x89
#define MSF_HDR_RIGHTS_ISSUER                     0x8a
#define MSF_HDR_CONTENT_NAME                      0x8b
#define MSF_HDR_CONTENT_DESCRIPTION               0x8c
#define MSF_HDR_CONTENT_VENDOR                    0x8d
#define MSF_HDR_ICON_URI                          0x8e
#define MSF_HDR_ENCRYPTION_METHOD                 0x8f
#define MSF_HDR_UNKNOWN                           0x90



/* Languages */
#define MSF_LANGUAGE_AA                 0x01
#define MSF_LANGUAGE_AB                 0x02
#define MSF_LANGUAGE_AF                 0x03
#define MSF_LANGUAGE_AM                 0x04
#define MSF_LANGUAGE_AR                 0x05
#define MSF_LANGUAGE_AS                 0x06
#define MSF_LANGUAGE_AY                 0x07
#define MSF_LANGUAGE_AZ                 0x08
#define MSF_LANGUAGE_BA                 0x09
#define MSF_LANGUAGE_BE                 0x0A
#define MSF_LANGUAGE_BG                 0x0B
#define MSF_LANGUAGE_BH                 0x0C
#define MSF_LANGUAGE_BI                 0x0D
#define MSF_LANGUAGE_BN                 0x0E
#define MSF_LANGUAGE_BO                 0x0F
#define MSF_LANGUAGE_BR                 0x10
#define MSF_LANGUAGE_CA                 0x11
#define MSF_LANGUAGE_CO                 0x12
#define MSF_LANGUAGE_CS                 0x13
#define MSF_LANGUAGE_CY                 0x14
#define MSF_LANGUAGE_DA                 0x15
#define MSF_LANGUAGE_DE                 0x16
#define MSF_LANGUAGE_DZ                 0x17
#define MSF_LANGUAGE_EL                 0x18
#define MSF_LANGUAGE_EN                 0x19
#define MSF_LANGUAGE_EO                 0x1A
#define MSF_LANGUAGE_ES                 0x1B
#define MSF_LANGUAGE_ET                 0x1C
#define MSF_LANGUAGE_EU                 0x1D
#define MSF_LANGUAGE_FA                 0x1E
#define MSF_LANGUAGE_FI                 0x1F
#define MSF_LANGUAGE_FJ                 0x20
#define MSF_LANGUAGE_FO                 0x82
#define MSF_LANGUAGE_FR                 0x22
#define MSF_LANGUAGE_FY                 0x83
#define MSF_LANGUAGE_GA                 0x24
#define MSF_LANGUAGE_GD                 0x25
#define MSF_LANGUAGE_GL                 0x26
#define MSF_LANGUAGE_GN                 0x27
#define MSF_LANGUAGE_GU                 0x28
#define MSF_LANGUAGE_HA                 0x29
#define MSF_LANGUAGE_HE                 0x2A
#define MSF_LANGUAGE_HI                 0x2B
#define MSF_LANGUAGE_HR                 0x2C
#define MSF_LANGUAGE_HU                 0x2D
#define MSF_LANGUAGE_HY                 0x2E
#define MSF_LANGUAGE_IA                 0x84
#define MSF_LANGUAGE_ID                 0x30
#define MSF_LANGUAGE_IE                 0x86
#define MSF_LANGUAGE_IK                 0x87
#define MSF_LANGUAGE_IS                 0x33
#define MSF_LANGUAGE_IT                 0x34
#define MSF_LANGUAGE_IU                 0x89
#define MSF_LANGUAGE_JA                 0x36
#define MSF_LANGUAGE_JW                 0x37
#define MSF_LANGUAGE_KA                 0x38
#define MSF_LANGUAGE_KK                 0x39
#define MSF_LANGUAGE_KL                 0x8A
#define MSF_LANGUAGE_KM                 0x3B
#define MSF_LANGUAGE_KN                 0x3C
#define MSF_LANGUAGE_KO                 0x3D
#define MSF_LANGUAGE_KS                 0x3E
#define MSF_LANGUAGE_KU                 0x3F
#define MSF_LANGUAGE_KY                 0x40
#define MSF_LANGUAGE_LA                 0x8B
#define MSF_LANGUAGE_LN                 0x42
#define MSF_LANGUAGE_LO                 0x43
#define MSF_LANGUAGE_LT                 0x44
#define MSF_LANGUAGE_LV                 0x45
#define MSF_LANGUAGE_MG                 0x46
#define MSF_LANGUAGE_MI                 0x47
#define MSF_LANGUAGE_MK                 0x48
#define MSF_LANGUAGE_ML                 0x49
#define MSF_LANGUAGE_MN                 0x4A
#define MSF_LANGUAGE_MO                 0x4B
#define MSF_LANGUAGE_MR                 0x4C
#define MSF_LANGUAGE_MS                 0x4D
#define MSF_LANGUAGE_MT                 0x4E
#define MSF_LANGUAGE_MY                 0x4F
#define MSF_LANGUAGE_NA                 0x81
#define MSF_LANGUAGE_NE                 0x51
#define MSF_LANGUAGE_NL                 0x52
#define MSF_LANGUAGE_NO                 0x53
#define MSF_LANGUAGE_OC                 0x54
#define MSF_LANGUAGE_OM                 0x55
#define MSF_LANGUAGE_OR                 0x56
#define MSF_LANGUAGE_PA                 0x57
#define MSF_LANGUAGE_PO                 0x58
#define MSF_LANGUAGE_PS                 0x59
#define MSF_LANGUAGE_PT                 0x5A
#define MSF_LANGUAGE_QU                 0x5B
#define MSF_LANGUAGE_RM                 0x8C
#define MSF_LANGUAGE_RN                 0x5D
#define MSF_LANGUAGE_RO                 0x5E
#define MSF_LANGUAGE_RU                 0x5F
#define MSF_LANGUAGE_RW                 0x60
#define MSF_LANGUAGE_SA                 0x61
#define MSF_LANGUAGE_SD                 0x62
#define MSF_LANGUAGE_SG                 0x63
#define MSF_LANGUAGE_SH                 0x64
#define MSF_LANGUAGE_SI                 0x65
#define MSF_LANGUAGE_SK                 0x66
#define MSF_LANGUAGE_SL                 0x67
#define MSF_LANGUAGE_SM                 0x68
#define MSF_LANGUAGE_SN                 0x69
#define MSF_LANGUAGE_SO                 0x6A
#define MSF_LANGUAGE_SQ                 0x6B
#define MSF_LANGUAGE_SR                 0x6C
#define MSF_LANGUAGE_SS                 0x6D
#define MSF_LANGUAGE_ST                 0x6E
#define MSF_LANGUAGE_SU                 0x6F
#define MSF_LANGUAGE_SV                 0x70
#define MSF_LANGUAGE_SW                 0x71
#define MSF_LANGUAGE_TA                 0x72
#define MSF_LANGUAGE_TE                 0x73
#define MSF_LANGUAGE_TG                 0x74
#define MSF_LANGUAGE_TH                 0x75
#define MSF_LANGUAGE_TI                 0x76
#define MSF_LANGUAGE_TK                 0x77
#define MSF_LANGUAGE_TL                 0x78
#define MSF_LANGUAGE_TN                 0x79
#define MSF_LANGUAGE_TO                 0x7A
#define MSF_LANGUAGE_TR                 0x7B
#define MSF_LANGUAGE_TS                 0x7C
#define MSF_LANGUAGE_TT                 0x7D
#define MSF_LANGUAGE_TW                 0x7E
#define MSF_LANGUAGE_UG                 0x7F
#define MSF_LANGUAGE_UK                 0x50
#define MSF_LANGUAGE_UR                 0x21
#define MSF_LANGUAGE_UZ                 0x23
#define MSF_LANGUAGE_VI                 0x2F
#define MSF_LANGUAGE_VO                 0x85
#define MSF_LANGUAGE_WO                 0x31
#define MSF_LANGUAGE_XH                 0x32
#define MSF_LANGUAGE_YI                 0x88
#define MSF_LANGUAGE_YO                 0x35
#define MSF_LANGUAGE_ZA                 0x3A
#define MSF_LANGUAGE_ZH                 0x41
#define MSF_LANGUAGE_ZU                 0x5C
#define MSF_LANGUAGE_UNKNOWN            0xff


/* Application id, well known values */
#define MSF_X_WAP_APPLICATION                     0x00
#define MSF_X_WAP_APPLICATION_PUSH_SIA            0x01
#define MSF_X_WAP_APPLICATION_WML_UA              0x02
#define MSF_X_WAP_APPLICATION_WTA_UA              0x03
#define MSF_X_WAP_APPLICATION_MMS_UA              0x04
#define MSF_X_WAP_APPLICATION_PUSH_SYNCML         0x05
#define MSF_X_WAP_APPLICATION_LOC_UA              0x06

/* Application id, registered values */
#define MSF_X_WAP_MICROSOFT_LOCALCONTENT_UA       0x8000
#define MSF_X_WAP_MICROSOFT_IMCLIENT_UA           0x8001
#define MSF_X_WAP_DOCOMO_IMODE_MAIL_UA            0x8002
#define MSF_X_WAP_DOCOMO_IMODE_MR_UA              0x8003
#define MSF_X_WAP_DOCOMO_IMODE_MF_UA              0x8004


/**************************************************
 * Type definitions 
 ***************************************************/

typedef struct msf_hdr_st msf_hdr_t;


/************************************************************ 
 * Exported Variables
 ************************************************************/

extern const msf_strtable_info_t msf_hdr_names;
extern const msf_strtable_info_t msf_languages;


/************************************************************ 
 * Exported functions
 ************************************************************/

/*
 * Create a new, empty header table
 */ 
msf_hdr_t*
msf_hdr_create (MSF_UINT8 module);

/* 
 * Deallocate a header table and all its content 
 */
void
msf_hdr_delete (msf_hdr_t* hdr);

/*
 * Copy a header table 
 */ 
msf_hdr_t* 
msf_hdr_copy (msf_hdr_t* hdr);

/*
 * Delete all fields of the specified kind.
 */
void
msf_hdr_delete_field (msf_hdr_t *hdr, int field_name);


/************************************************************
 * Routines to add information to a header table. 
 ************************************************************/

/*
 * Add a string to the header table.
 * The string is copied into the table, and will be deallocated
 * when the header table is removed.
 * Returns TRUE on success and FALSE on error.
 */
int
msf_hdr_add_string (msf_hdr_t *hdr, int field_name, const char* value);

/*
 * Add a parameter value to a header that is already in the table.
 * The string is copied, and will be deallocated when the header
 * table is deleted.
 * Returns TRUE on success, or FALSE on error.
 */
int
msf_hdr_add_parameter (msf_hdr_t *hdr, int field_name,
                       const char *parameter, const char* value);

/*
 * Parses one line of text as an HTTP header, and adds
 * the relevant content to the header table.
 * The parameter 'str' is a null-terminated character string holding
 * one line of text, and 'len' is the number of characters in 'str'.
 * Returns TRUE on success and FALSE on error.
 */
int
msf_hdr_add_header_from_text_line (msf_hdr_t *hdr, const char *str, int len);

/*
 * Given a text string that holds a number of lines, each
 * terminated by <CR><LF> (except perhaps the last one),
 * this function reads these lines and adds the header value to the table.
 * Returns TRUE on success and FALSE on error.
 */
int
msf_hdr_add_headers_from_text (msf_hdr_t *hdr, const char *text);

/**********************************************************************
 * Routines to retrieve information from a header table. 
 **********************************************************************/

/* 
 * Make a string out of the contents of a header structure.
 * Returns TRUE on success and FALSE on error.
 */
int
msf_hdr_make_string (msf_hdr_t *hdr, char **str);

/*
 * Get a MSF_UINT32 value from the first element with the given header name.
 * Returns TRUE if a header element was found, and FALSE otherwise.
 */
int
msf_hdr_get_uint32 (msf_hdr_t *hdr, int field_name, MSF_UINT32 *value);

/*
 * Get a string value from the first element with the given header name.
 * Returns NULL if the requested header element is not in the table.
 * NOTE: the caller MUST NOT deallocate the returned string!
 */
const char *
msf_hdr_get_string (msf_hdr_t *hdr, int field_name);

/*
 * Get a parameter value from the first element with the given field name.
 * Returns NULL if the requested header element is not in the table,
 * or the header field does not have a parameter with the given name.
 * NOTE: it is the responsibility of the caller to deallocate the string!
 */
char *
msf_hdr_get_parameter (msf_hdr_t *hdr, int field_name, const char *parameter);

#endif
