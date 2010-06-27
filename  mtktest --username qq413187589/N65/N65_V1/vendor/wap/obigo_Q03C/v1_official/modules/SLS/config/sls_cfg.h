/*
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2004.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Teleca Mobile Technologies AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Teleca Mobile Technologies AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */

/*! \file sls_cfg.h
 * \brief  configuration variables for SLS
 */
#ifndef _SLS_CFG_H
#define _SLS_CFG_H


/*--- Include files ---*/

/*--- Definitions/Declarations ---*/
/*! Initial size for parser buffer, NOT maximum. */
#define SMA_PARSE_BUFFER_INITIAL_SIZE   100

/*! Maximum number of slides allowed in a SMIL. */
#define MAX_NO_OF_SLIDES 20
#define MAX_ELEM_DEPTH   10

/*! Maximum length of text in <alt> attribute */
#define SLS_MAX_ALT_ATTR_LEN 40

/*! Maximum length of text in <fit> attribute */
#define SLS_SMIL_ATTR_FIT_MAX_LEN 10

/*! 
*   Shows all Object in a Object List instead of only unreferenced
*/
#define SLS_SHOW_ALL_OBJECTS 0


/*! 
*   Defines if MAX_NBR_OF_SLIDES should be returnend when the smil is bigger than MAX_NBR_OF_SLIDES.
*   1 -> return  MAX_NBR_OF_SLIDES
*   0 -> returns error
*/

#define SLS_ALWAYS_VIEW_MAX_NBR_OF_SLIDES 0

/*! Setting for parsing SMIL. Some operators uses Messages
 *  containing regions that doesn't match to existing region_id.
 *  This functionality forces an unmatching region to map one
 *  of the existing region_ids.
 *  0 => no extended handling of regions
 *  1 => always map regions to region_id
 */
#define SLS_EXTENDED_HANDLING_OF_REGIONS  1

/*! \enum SlsMediaType
 *  \brief Defines the media type
 *
 * NOTE: Making changes here will probably require changes in mea_cfg.h and sma_cfg.h.
 */
typedef enum 
{
    SLS_TEXT_PLAIN = 0x01,      /*!< Plain text */ 
    SLS_IMAGE_WBMP,             /*!< Wireless bitmap image */ 
    SLS_IMAGE_JPG,              /*!< JPG image */ 
    SLS_IMAGE_GIF,              /*!< GIF image */ 
    SLS_IMAGE_PNG,              /*!< PNG image */ 
    SLS_IMAGE_BMP,              /*!< BMP image */
/*    SLS_IMAGE_TIFF,       */      /*!< TIFF image */
    SLS_DRM_MESSAGE,            /*!< application/vnd.oma.drm.message */ 
    SLS_DRM_CONTENT,            /*!< application/vnd.oma.drm.content */ 
    SLS_TEXT_X_VCARD,			/*!< V-Card */ 
    SLS_TEXT_X_VCAL,			/*!< V-Cal */ 
    SLS_VIDEO_3GP,              /*!< 3GP video */
    SLS_VIDEO_MP4,              /*!< MPEG4 video */
    SLS_VIDEO_MPEG,             /*!< MPEG/MPEG4 video */
    SLS_VIDEO_AVI,              /*!< AVI video */
    SLS_VIDEO_H263,             /*!< H263 video */
    SLS_AUDIO_MP3,              /*!< MP3 audio */ 
    SLS_AUDIO_AMR,              /*!< AMR audio */ 
    SLS_AUDIO_AWB,
    SLS_AUDIO_WMA,
    SLS_AUDIO_AAC,
    SLS_AUDIO_M4A,
    SLS_AUDIO_AIFF,
    SLS_AUDIO_BASIC,

    SLS_AUDIO_WAV,              /*!< WAV audio */
    SLS_AUDIO_VM,
    SLS_AUDIO_MIDI,             /*!< Midi audio */  //Jo
    SLS_AUDIO_SMAF,
    SLS_AUDIO_IMY,             /*!< iMelody audio */  //GH
    SLS_UNKNOWN,                /*!< Unknown media type */
    SLS_NOT_USED                /*!< Media is not used */ 
} SlsMediaType;

#ifdef AMRWB_DECODE
#define SLS_CFG_MEDIA_OBJECT_AWB         {SLS_AUDIO_AWB,		"audio/amr-wb",        MMS_VALUE_AS_STRING,         SLS_OBJECT_TYPE_AUDIO},
#else
#define SLS_CFG_MEDIA_OBJECT_AWB
#endif /* AMRWB_DECODE */

#ifdef GDI_USING_PNG
#define SLS_CFG_MEDIA_OBJECT_PNG         {SLS_IMAGE_PNG,     "image/png",        MMS_TYPE_IMAGE_PNG,          SLS_OBJECT_TYPE_IMAGE},\
										{SLS_IMAGE_PNG,	    "image/png",        MMS_VALUE_AS_STRING,         SLS_OBJECT_TYPE_IMAGE},
#else
#define SLS_CFG_MEDIA_OBJECT_PNG
#endif

/*! Supported media objects for the SLS module.
 *
 * Add or remove lines in the "table" below in order to configure the support
 * for different media types, the values in #SlsMediaType does also needs to be
 * changed accordingly. The #SlsMediaType enum is located in the source code 
 * file: sls_if.h
 *
 * NOTE: Making changes here will probably require changes in mea_cfg.h and sma_cfg.h.
 * NOTE: The list need fault tolerance for some common mistakes in incoming MMS. ex. wrong MIME: image/jpg, video/3gp
 *
 * Format:
 *
 *  {#SlsMediaType, MIME type, #MmsKnownMediaType, #SlsObjectType}
 *
 */
#define SLS_CFG_SUPPORTED_MEDIA_TYPES {\
    {SLS_TEXT_PLAIN,	"text/plain",       MMS_TYPE_TEXT_PLAIN,         SLS_OBJECT_TYPE_TEXT}, \
    \
    {SLS_IMAGE_WBMP,	"image/vnd.wap.wbmp", MMS_TYPE_IMAGE_VND_WAP_WBMP, SLS_OBJECT_TYPE_IMAGE},\
    {SLS_IMAGE_WBMP,	"image/vnd.wap.wbmp", MMS_VALUE_AS_STRING,       SLS_OBJECT_TYPE_IMAGE},\
    {SLS_IMAGE_JPG,		"image/jpeg",       MMS_TYPE_IMAGE_JPEG,         SLS_OBJECT_TYPE_IMAGE},\
    {SLS_IMAGE_JPG,		"image/jpeg",       MMS_VALUE_AS_STRING,         SLS_OBJECT_TYPE_IMAGE},\
    {SLS_IMAGE_JPG,		"image/jpg",       MMS_TYPE_IMAGE_JPEG,         SLS_OBJECT_TYPE_IMAGE},\
    {SLS_IMAGE_JPG,		"image/jpg",       MMS_VALUE_AS_STRING,         SLS_OBJECT_TYPE_IMAGE},\
    {SLS_IMAGE_GIF,     "image/gif",        MMS_TYPE_IMAGE_GIF,          SLS_OBJECT_TYPE_IMAGE},\
    {SLS_IMAGE_GIF,     "image/gif",        MMS_VALUE_AS_STRING,         SLS_OBJECT_TYPE_IMAGE},\
    {SLS_IMAGE_BMP,     "image/bmp",        MMS_VALUE_AS_STRING,         SLS_OBJECT_TYPE_IMAGE},\
    {SLS_IMAGE_BMP,		"image/bitmap",     MMS_VALUE_AS_STRING,         SLS_OBJECT_TYPE_IMAGE},\
    {SLS_IMAGE_BMP,		"image/x-MS-bmp",     MMS_VALUE_AS_STRING,         SLS_OBJECT_TYPE_IMAGE},\
    SLS_CFG_MEDIA_OBJECT_PNG\
/*    {SLS_IMAGE_TIFF,    "image/tiff",       MMS_TYPE_IMAGE_TIFF,         SLS_OBJECT_TYPE_ATTACMENT},*/\
/*    {SLS_IMAGE_TIFF,	"image/tiff",       MMS_VALUE_AS_STRING,         SLS_OBJECT_TYPE_ATTACMENT},*/\
    \
	{SLS_VIDEO_MP4,		"video/mp4",        MMS_VALUE_AS_STRING,         SLS_OBJECT_TYPE_VIDEO},\
	{SLS_VIDEO_MPEG,	"video/mpeg",       MMS_VALUE_AS_STRING,         SLS_OBJECT_TYPE_VIDEO},\
	{SLS_VIDEO_3GP,		"video/3gpp",       MMS_VALUE_AS_STRING,         SLS_OBJECT_TYPE_VIDEO},\
	{SLS_VIDEO_3GP,		"video/3gpp2",      MMS_VALUE_AS_STRING,         SLS_OBJECT_TYPE_VIDEO},\
	{SLS_VIDEO_3GP,		"video/3gp",        MMS_VALUE_AS_STRING,         SLS_OBJECT_TYPE_VIDEO},\
	{SLS_VIDEO_AVI,		"video/x-msvideo",       MMS_VALUE_AS_STRING,         SLS_OBJECT_TYPE_VIDEO},\
	{SLS_VIDEO_H263,	"video/h263-2000",  MMS_VALUE_AS_STRING,         SLS_OBJECT_TYPE_VIDEO},\
    \
    {SLS_AUDIO_AMR,		"audio/amr",        MMS_VALUE_AS_STRING,         SLS_OBJECT_TYPE_AUDIO},\
    SLS_CFG_MEDIA_OBJECT_AWB\
    {SLS_AUDIO_MP3,		"audio/mp3",        MMS_VALUE_AS_STRING,         SLS_OBJECT_TYPE_AUDIO},\
    {SLS_AUDIO_MP3,		"audio/mpeg",       MMS_VALUE_AS_STRING,         SLS_OBJECT_TYPE_AUDIO},\
    {SLS_AUDIO_WAV,		"audio/wav",        MMS_VALUE_AS_STRING,         SLS_OBJECT_TYPE_AUDIO},\
    {SLS_AUDIO_WAV,		"audio/x-wav",      MMS_VALUE_AS_STRING,         SLS_OBJECT_TYPE_AUDIO},\
    {SLS_AUDIO_MIDI,    "audio/midi",       MMS_VALUE_AS_STRING,         SLS_OBJECT_TYPE_AUDIO},\
	{SLS_AUDIO_MIDI,    "audio/mid",       MMS_VALUE_AS_STRING,         SLS_OBJECT_TYPE_AUDIO},\
    {SLS_AUDIO_MIDI,    "audio/sp-midi",       MMS_VALUE_AS_STRING,         SLS_OBJECT_TYPE_AUDIO},\
    {SLS_AUDIO_SMAF,    "application/vnd.smaf",       MMS_VALUE_AS_STRING,         SLS_OBJECT_TYPE_AUDIO},\
    {SLS_AUDIO_SMAF,    "application/x-smaf",       MMS_VALUE_AS_STRING,         SLS_OBJECT_TYPE_AUDIO},\
    {SLS_AUDIO_MIDI,    "x-music/x-midi",       MMS_VALUE_AS_STRING,         SLS_OBJECT_TYPE_AUDIO},\
    {SLS_AUDIO_IMY,    "audio/imelody",       MMS_VALUE_AS_STRING,         SLS_OBJECT_TYPE_AUDIO},\
    {SLS_AUDIO_IMY,    "text/x-imelody",       MMS_VALUE_AS_STRING,         SLS_OBJECT_TYPE_AUDIO},\
    {SLS_AUDIO_WMA,    "audio/wma",       MMS_VALUE_AS_STRING,         SLS_OBJECT_TYPE_AUDIO},\
    {SLS_AUDIO_WMA,    "audio/x-ms-wma",       MMS_VALUE_AS_STRING,         SLS_OBJECT_TYPE_AUDIO},\
    {SLS_AUDIO_AAC,    "audio/aac",        MMS_VALUE_AS_STRING,         SLS_OBJECT_TYPE_AUDIO},\
    {SLS_AUDIO_M4A,    "audio/m4a",        MMS_VALUE_AS_STRING,         SLS_OBJECT_TYPE_AUDIO},\
    {SLS_AUDIO_M4A,    "audio/mp4",        MMS_VALUE_AS_STRING,         SLS_OBJECT_TYPE_AUDIO},\
    {SLS_AUDIO_M4A,    "audio/x-m4a",        MMS_VALUE_AS_STRING,         SLS_OBJECT_TYPE_AUDIO},\
    {SLS_AUDIO_AIFF,    "audio/x-aiff",        MMS_VALUE_AS_STRING,         SLS_OBJECT_TYPE_AUDIO},\
    {SLS_AUDIO_BASIC,    "audio/basic",        MMS_VALUE_AS_STRING,         SLS_OBJECT_TYPE_AUDIO},\
    \
    {SLS_DRM_MESSAGE,	"application/vnd.oma.drm.message", MMS_VALUE_AS_STRING, SLS_OBJECT_TYPE_DRM},\
    {SLS_DRM_MESSAGE,	"application/vnd.oma.drm.message", MMS_TYPE_APP_VND_OMA_DRM_MESSAGE, SLS_OBJECT_TYPE_DRM},\
    {SLS_DRM_CONTENT,	"application/vnd.oma.drm.content", MMS_VALUE_AS_STRING, SLS_OBJECT_TYPE_DRM},\
    {SLS_DRM_CONTENT,	"application/vnd.oma.drm.content", MMS_TYPE_APP_VND_OMA_DRM_CONTENT, SLS_OBJECT_TYPE_DRM},\
	\
	{SLS_TEXT_X_VCAL,	"text/x-vcalendar",	MMS_TYPE_TEXT_X_VCALENDAR,	 SLS_OBJECT_TYPE_ATTACMENT},\
    {SLS_TEXT_X_VCARD,	"text/x-vcard",		MMS_TYPE_TEXT_X_VCARD,		 SLS_OBJECT_TYPE_ATTACMENT},\
    {SLS_TEXT_X_VCAL,	"text/x-vcalendar",	MMS_VALUE_AS_STRING,	 SLS_OBJECT_TYPE_ATTACMENT},\
    {SLS_TEXT_X_VCARD,	"text/x-vcard",		MMS_VALUE_AS_STRING,		 SLS_OBJECT_TYPE_ATTACMENT},\
    \
    {SLS_NOT_USED,      "",                 (MmsKnownMediaType)0,        (SlsMediaObjectType)0}}


/*! Supported character sets for the SLS. Add or remove items in order to change
 *  the supported types.
 *
 * Format
 *
 * {#MmsCharset, MSF charset}
 *
 * Note that the last entry of the list must be present.
 */
#define SLS_CFG_SUPPORTED_CHARSET {             \
    {MMS_US_ASCII,      MSF_CHARSET_ASCII},     \
    {MMS_UTF8,          MSF_CHARSET_UTF_8},     \
    {MMS_ISO_8859_1,    MSF_CHARSET_ISO_8859_1},\
    {MMS_ISO_8859_1,    MSF_CHARSET_LATIN_1},   \
    {MMS_UCS2,          MSF_CHARSET_UCS_2},     \
    {MMS_UTF16BE,       MSF_CHARSET_UTF_16BE},  \
    {MMS_UTF16LE,       MSF_CHARSET_UTF_16LE},  \
    {MMS_UTF16,         MSF_CHARSET_UTF_16},    \
                                                \
    /* The last entry must be present */        \
    {MMS_UNKNOWN_CHARSET, MSF_CHARSET_UNKNOWN}}


#define SLS_COLOR_SET {\
	{"white",		0xFFFFFF},\
	{"silver",		0xC0C0C0},\
	{"gray",		0x808080},\
	{"black",		0x000000},\
	{"yellow",		0xFFFF00},\
	{"fuchsia",		0xFF00FF},\
	{"red",			0xFF0000},\
	{"maroon",		0x800000},\
	{"lime",		0x00FF00},\
	{"olive",		0x808000},\
	{"green",		0x008000},\
	{"purple",		0x800080},\
	{"aqua",		0x00FFFF},\
	{"teal",		0x008080},\
	{"blue",		0x0000FF},\
	{"navy",		0x000080},\
	{NULL,			SLS_COLOR_NOT_USED}}
/*--- Types ---*/

/*--- Constants ---*/

/*--- Forwards ---*/

/*--- Externs ---*/

/*--- Macros ---*/

/*--- Global variables ---*/

/*--- Static variables ---*/

/*--- Prototypes ---*/
/******************************************************************************/

#endif /* _SLS_CFG_H */


