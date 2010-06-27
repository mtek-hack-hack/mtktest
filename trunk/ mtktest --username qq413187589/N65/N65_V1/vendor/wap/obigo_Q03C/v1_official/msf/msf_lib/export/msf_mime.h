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
 * msf_mime.h
 *
 * File extension to MIME type conversion.
 *
 */


#ifndef _msf_mime_h
#define _msf_mime_h

#ifndef _msf_def_h
#include "msf_def.h"
#endif
#ifndef _msf_cmmn_h
#include "msf_cmmn.h"
#endif

/************************************************************ 
 * Constants
 ************************************************************/

/*
 * Media types that have a pre-defined integer representation.
 * OMNA "Well-Known Values".
 */
#define MSF_MIME_TYPE_ANY_ANY                                    0x00
#define MSF_MIME_TYPE_TEXT_ANY                                   0x01
#define MSF_MIME_TYPE_TEXT_HTML                                  0x02
#define MSF_MIME_TYPE_TEXT_PLAIN                                 0x03
#define MSF_MIME_TYPE_TEXT_X_HDML                                0x04
#define MSF_MIME_TYPE_TEXT_X_TTML                                0x05
#define MSF_MIME_TYPE_TEXT_X_VCALENDAR                           0x06
#define MSF_MIME_TYPE_TEXT_X_VCARD                               0x07
#define MSF_MIME_TYPE_TEXT_VND_WAP_WML                           0x08
#define MSF_MIME_TYPE_TEXT_VND_WAP_WMLSCRIPT                     0x09
#define MSF_MIME_TYPE_TEXT_VND_WAP_CHANNEL                       0x0a
#define MSF_MIME_TYPE_MULTIPART_ANY                              0x0b
#define MSF_MIME_TYPE_MULTIPART_MIXED                            0x0c
#define MSF_MIME_TYPE_MULTIPART_FORM_DATA                        0x0d
#define MSF_MIME_TYPE_MULTIPART_BYTERANGES                       0x0e
#define MSF_MIME_TYPE_MULTIPART_ALTERNATIVE                      0x0f
#define MSF_MIME_TYPE_APPLICATION_ANY                            0x10
#define MSF_MIME_TYPE_APPLICATION_JAVA_VM                        0x11
#define MSF_MIME_TYPE_APPLICATION_X_WWW_FORM_URLENCODED          0x12
#define MSF_MIME_TYPE_APPLICATION_X_HDMLC                        0x13
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_WMLC                   0x14
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_WMLSCRIPTC             0x15
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_CHANNELC               0x16
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_UAPROF                 0x17
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_WTLS_CA_CERTIFICATE    0x18
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_WTLS_USER_CERTIFICATE  0x19
#define MSF_MIME_TYPE_APPLICATION_X_X509_CA_CERT                 0x1a
#define MSF_MIME_TYPE_APPLICATION_X_X509_USER_CERT               0x1b
#define MSF_MIME_TYPE_IMAGE_ANY                                  0x1c
#define MSF_MIME_TYPE_IMAGE_GIF                                  0x1d
#define MSF_MIME_TYPE_IMAGE_JPEG                                 0x1e
#define MSF_MIME_TYPE_IMAGE_TIFF                                 0x1f
#define MSF_MIME_TYPE_IMAGE_PNG                                  0x20
#define MSF_MIME_TYPE_IMAGE_VND_WAP_WBMP                         0x21
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_MULTIPART_ANY          0x22
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_MULTIPART_MIXED        0x23
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_MULTIPART_FORM_DATA    0x24
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_MULTIPART_BYTERANGES   0x25
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_MULTIPART_ALTERNATIVE  0x26
#define MSF_MIME_TYPE_APPLICATION_XML                            0x27
#define MSF_MIME_TYPE_TEXT_XML                                   0x28
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_WBXML                  0x29
#define MSF_MIME_TYPE_APPLICATION_X_X968_CROSS_CERT              0x2a
#define MSF_MIME_TYPE_APPLICATION_X_X968_CA_CERT                 0x2b
#define MSF_MIME_TYPE_APPLICATION_X_X968_USER_CERT               0x2c
#define MSF_MIME_TYPE_TEXT_VND_WAP_SI                            0x2d
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_SIC                    0x2e
#define MSF_MIME_TYPE_TEXT_VND_WAP_SL                            0x2f
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_SLC                    0x30
#define MSF_MIME_TYPE_TEXT_VND_WAP_CO                            0x31
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_COC                    0x32
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_MULTIPART_RELATED      0x33
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_SIA                    0x34
#define MSF_MIME_TYPE_TEXT_VND_WAP_CONNECTIVITY_XML              0x35
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_CONNECTIVITY_WBXML     0x36
#define MSF_MIME_TYPE_APPLICATION_PKCS7_MIME                     0x37
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_HASHED_CERTIFICATE     0x38
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_SIGNED_CERTIFICATE     0x39
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_CERT_RESPONSE          0x3a
#define MSF_MIME_TYPE_APPLICATION_XHTML_XML                      0x3b
#define MSF_MIME_TYPE_APPLICATION_WML_XML                        0x3c
#define MSF_MIME_TYPE_TEXT_CSS                                   0x3d
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_MMS_MESSAGE            0x3e
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_ROLLOVER_CERTIFICATE   0x3f
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_LOCC_WBXML             0x40
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_LOC_XML                0x41
#define MSF_MIME_TYPE_APPLICATION_VND_SYNCML_DM_WBXML            0x42
#define MSF_MIME_TYPE_APPLICATION_VND_SYNCML_DM_XML              0x43
#define MSF_MIME_TYPE_APPLICATION_VND_SYNCML_NOTIFICATION        0x44
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_XHTML_XML              0x45
#define MSF_MIME_TYPE_APPLICATION_VND_WV_CSP_CIR                 0x46
#define MSF_MIME_TYPE_APPLICATION_VND_OMA_DD_XML                 0x47
#define MSF_MIME_TYPE_APPLICATION_VND_OMA_DRM_MESSAGE            0x48
#define MSF_MIME_TYPE_APPLICATION_VND_OMA_DRM_CONTENT            0x49
#define MSF_MIME_TYPE_APPLICATION_VND_OMA_DRM_RIGHTS_XML         0x4a
#define MSF_MIME_TYPE_APPLICATION_VND_OMA_DRM_RIGHTS_WBXML       0x4b
#define MSF_MIME_TYPE_APPLICATION_VND_WV_CSP_XML                 0x4c
#define MSF_MIME_TYPE_APPLICATION_VND_WV_CSP_WBXML               0x4d

/*
 * OMNA "Registered Values"
 */
#define MSF_MIME_TYPE_APPLICATION_VND_UPLANET_CACHEOP_WBXML      0x0201
#define MSF_MIME_TYPE_APPLICATION_VND_UPLANET_SIGNAL             0x0202
#define MSF_MIME_TYPE_APPLICATION_VND_UPLANET_ALERT_WBXML        0x0203
#define MSF_MIME_TYPE_APPLICATION_VND_UPLANET_LIST_WBXML         0x0204
#define MSF_MIME_TYPE_APPLICATION_VND_UPLANET_LISTCMD_WBXML      0x0205
#define MSF_MIME_TYPE_APPLICATION_VND_UPLANET_CHANNEL_WBXML      0x0206
#define MSF_MIME_TYPE_APPLICATION_VND_UPLANET_PROVISIONING_STATUS_URI  0x0207
#define MSF_MIME_TYPE_X_WAP_MULTIPART_VND_UPLANET_HEADER_SET     0x0208
#define MSF_MIME_TYPE_APPLICATION_VND_UPLANET_BEARER_CHOICE_WBXML  0x0209
#define MSF_MIME_TYPE_APPLICATION_VND_PHONECOM_MMC_WBXML         0x020a
#define MSF_MIME_TYPE_APPLICATION_VND_NOKIA_SYNCSET_WBXML        0x020b
#define MSF_MIME_TYPE_IMAGE_X_UP_WPNG                            0x020c
#define MSF_MIME_TYPE_APPLICATION_IOTA_MMC_WBXML                 0x0300
#define MSF_MIME_TYPE_APPLICATION_IOTA_MMC                       0x0301

/*
 * Other media types that have a pre-defined integer representation.
 * These are pre-defined internally by MSF and used to enable the 
 * parser to handle these media types.
 */
#define MSF_MIME_TYPE_AUDIO_ANY                                  0xa0
#define MSF_MIME_TYPE_AUDIO_MID                                  0xa1
#define MSF_MIME_TYPE_AUDIO_MPEG                                 0xa2
#define MSF_MIME_TYPE_AUDIO_X_WAV                                0xa3
#define MSF_MIME_TYPE_APPLICATION_X_VND_MMS_TEMPLATE_TEXTS       0xa4
#define MSF_MIME_TYPE_APPLICATION_X_WAP_PROV_BROWSER_SETTINGS    0xa5
#define MSF_MIME_TYPE_APPLICATION_X_WAP_PROV_BROWSER_BOOKMARKS   0xa6
#define MSF_MIME_TYPE_APPLICATION_X_WAP_PROV_SYNCSET_XML         0xa7
#define MSF_MIME_TYPE_APPLICATION_X_WAP_PROV_SYNCSET_WBXML       0xa8
#define MSF_MIME_TYPE_APPLICATION_SMIL                           0xa9

#define MSF_MIME_TYPE_IMAGE_SVG                                  0xaa
#define MSF_MIME_TYPE_IMAGE_BMP                                  0xab
#define MSF_MIME_TYPE_VIDEO_MPEG                                 0xac
#define MSF_MIME_TYPE_APPLICATION_VND_SMAF                       0xad
#define MSF_MIME_TYPE_APPLICATION_X_SMAF                         0xae
#define MSF_MIME_TYPE_AUDIO_AMR                                  0xaf
#define MSF_MIME_TYPE_APPLICATION_X_SHOCKWAVE_FLASH              0xb0
#define MSF_MIME_TYPE_APPLICATION_ZIP                            0xb1
#define MSF_MIME_TYPE_AUDIO_MIDI                                 0xb2
#define MSF_MIME_TYPE_AUDIO_X_MIDI                               0xb3
#define MSF_MIME_TYPE_AUDIO_SP_MIDI                              0xb4
#define MSF_MIME_TYPE_AUDIO_IMELODY                              0xb5
#define MSF_MIME_TYPE_TEXT_X_IMELODY                             0xb6
#define MSF_MIME_TYPE_UNKNOWN                                    0xff

/************************************************************ 
 * Exported Variables
 ************************************************************/

extern const msf_strtable_info_t msf_mime_types;

/************************************************************ 
 * Exported functions
 ************************************************************/

/*
 * Returns the corresponding mime type for a file extension 
 */
const char*
msf_mime_ext_to_mime (const char *ext);

/*
 * Returns the corresponding file extension for a mime type
 */
const char*
msf_mime_to_ext (const char *mime);

/*
 * Returns the integer representation for the mime type
 */
MSF_INT32 
msf_mime_to_int (const char *mime);

/*
 * Returns the mime type given an integer representation.
 */
const char *
msf_int_to_mime (MSF_INT32 known_value);

/*
 * Returns the integer representation for the file extension
 * Note! that it is the integer representation of the mime type
 * corresponding to the extension that is returned.
 */
MSF_INT32 
msf_mime_ext_to_int (const char *ext);

#endif
