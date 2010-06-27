/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
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

/*! \file mea_cfg.h
 *  Compile-time configurations for the MEA.
 */

#ifndef _MEA_CFG_H_  
#define _MEA_CFG_H_

#include "mea_def.h"

#ifndef _CUSTOM_WAP_CONFIG_H
#include "custom_wap_config.h"
#endif /* ~_CUSTOM_WAP_CONFIG_H */

/******************************************************************************
 * Defines 
 *****************************************************************************/
#ifdef WAP_SUPPORT
  #ifdef __DRM_SUPPORT__
#define MMS_DRM_FOLDER "/external/Z:\\@MMS_DRM\\"
#define MMS_DCF_FOLDER "/external/Z:\\@MMS_DRM\\DCF\\"
#define DRM_FOLDER "/external/Z:\\@DRM\\"
  #endif

#define MEA_ME_MAX_EMAIL_ADDRESS_SIZE     60
#define MAX_FILE_NAME_LEN 261
#define MEA_FOLDER_PATH "/mea/"

#define MEA_SIG_SET_FILE "/mea/signature"
#define MEA_SIG_TEXT_FILE "/mea/signature.txt"
#define MEA_SIG_FILE_NAME "signature.txt"

#define MEA_CREATION_MODE_SET_FILE "/mea/mode"  
#define MEA_IMAGE_RESIZE_SET_FILE "/mea/imageResize"
#define MEA_IMAGE_RESIZE_FOLDER  "/mms/"  /* same as MMS_FOLDER */

#define MEA_CFG_SHOW_RESPONSE_TEXT 1  /* 0: not show response text when sending failed; 1: show... */

/*! This define is used to handle sending timeout.
 *  Many problematic servers cannot response M-Send.conf immediately or they don't even response it. 
 *  So we have to introduce timeout mechanism to handle the situation, especially for foreground sending popup issue
 *
 *  Value 0: display successful when receiving M-Send.conf; 
 *  Value > 0: display successful after waiting MEA_CFG_SEND_TIMEOUT second(s)*/
#define MEA_CFG_SEND_TIMEOUT 0

/* 0: request read report when starting player
   1: request read report when exiting player */
#define MEA_CFG_REQ_RR_AFTER_READ_FINISH 1

/* 0: Original: Only one option "Add Slide"
   1: 2 options "Add Slide Before" and "Add Slide After" */
#define MEA_CFG_INSERT_SLIDE_OPTION 1

#define MEA_MAX_ATTACHMENT_NO 3  /* At least 1 */

#define MEA_MAX_TEXT_LENGTH  612

#define MEA_MAX_SUBJECT_LENGTH  40

#define MEA_GET_MIXED_TEXT_HEIGHT

#endif

/*! The MEA can be invoked from the BRA or BRS when a mmsto:, mms: or mailto:
 *  scheme is found.
 *
 *  Use this define in order to enable cross triggering from the browser.
 */
#undef MEA_CFG_CT_BROWSER_SCHEMES /*#define MEA_CFG_CT_BROWSER_SCHEMES   "mms,mmsto,mailto"*/
//SendAsMMS Jo 030819
//#define MEA_CFG_CT_BROWSER_SCHEMES   "mms,mmsto,mailto"

/*! This define should state all supported schemes from MEA to the browser 
 *  through cross triggering. This constant should not be defined if the 
 *  BRA/BRS is not present, i.e. the MEA cannot start the BRA/BRS.
 */
#define MEA_CFG_CT_SCHEMES  \
    {{"http://", sizeof("http://") - 1},\
     {"https://", sizeof("https://") - 1},\
     {NULL, 0}\
    }

/*! In order to use an external phone book this constant needs to be defined.
 */
#define MEA_CFG_USE_EXT_PB


/*! 
*  Use content Routing for Know objects or only for unkown.
*/

#define MEA_USE_CONTENT_ROUTING  0

/* Audio support */
#ifdef DAF_DECODE
#define MEA_CFG_MEDIA_OBJECT_DAF     {MEA_MEDIA_TYPE_MP3,        MEA_MEDIA_GROUP_AUDIO, "audio/mpeg",          MMS_VALUE_AS_STRING, SLS_AUDIO_MP3, MsfMp3, "mp3"},\
    {MEA_MEDIA_TYPE_MP3,        MEA_MEDIA_GROUP_AUDIO, "audio/mp3",          MMS_VALUE_AS_STRING, SLS_AUDIO_MP3, MsfMp3, "mp3"},\
    {MEA_MEDIA_TYPE_MP3,        MEA_MEDIA_GROUP_AUDIO, "audio/mpg3",          MMS_VALUE_AS_STRING, SLS_AUDIO_MP3, MsfMp3, "mp3"},
#define MEA_CFG_OPEN_AUDIO_DAF ",audio/mpeg,audio/mp3"
#define MEA_CFG_CT_MIME_2_MT_DAF {"audio/mpeg", MEA_MEDIA_TYPE_MP3},\
    {"audio/mp3", MEA_MEDIA_TYPE_MP3},
#else
#define MEA_CFG_MEDIA_OBJECT_DAF
#define MEA_CFG_OPEN_AUDIO_DAF
#define MEA_CFG_CT_MIME_2_MT_DAF
#endif

#ifdef AMRWB_DECODE
#define MEA_CFG_MEDIA_OBJECT_AWB     {MEA_MEDIA_TYPE_AWB,        MEA_MEDIA_GROUP_AUDIO, "audio/amr-wb",          MMS_VALUE_AS_STRING, SLS_AUDIO_AWB, MsfAmrWB, "awb"},
#define MEA_CFG_OPEN_AUDIO_AWB ",audio/amr-wb"
#define MEA_CFG_CT_MIME_2_MT_AWB {"audio/amr-wb", MEA_MEDIA_TYPE_AWB},
#else
#define MEA_CFG_MEDIA_OBJECT_AWB
#define MEA_CFG_OPEN_AUDIO_AWB
#define MEA_CFG_CT_MIME_2_MT_AWB
#endif

#ifdef YAMAHA_MA3
#define MEA_CFG_MEDIA_OBJECT_MMF    {MEA_MEDIA_TYPE_SMAF,       MEA_MEDIA_GROUP_AUDIO, "application/vnd.smaf",         MMS_VALUE_AS_STRING, SLS_AUDIO_MIDI, MsfMidi, "mmf"},\
    {MEA_MEDIA_TYPE_SMAF,       MEA_MEDIA_GROUP_AUDIO, "application/x-smaf",         MMS_VALUE_AS_STRING, SLS_AUDIO_MIDI, MsfMidi, "mmf"},
#define MEA_CFG_OPEN_AUDIO_MMF ",application/vnd.smaf,application/x-smaf"
#define MEA_CFG_CT_MIME_2_MT_MMF {"application/vnd.smaf", MEA_MEDIA_TYPE_SMAF},\
    {"application/x-smaf", MEA_MEDIA_TYPE_SMAF},
#else
#define MEA_CFG_MEDIA_OBJECT_MMF
#define MEA_CFG_OPEN_AUDIO_MMF
#define MEA_CFG_CT_MIME_2_MT_MMF
#endif

#ifdef WMA_DECODE
#define MEA_CFG_MEDIA_OBJECT_WMA     {MEA_MEDIA_TYPE_WMA,        MEA_MEDIA_GROUP_AUDIO, "audio/wma",          MMS_VALUE_AS_STRING, SLS_AUDIO_WMA, MsfWma, "wma"},\
    {MEA_MEDIA_TYPE_WMA,        MEA_MEDIA_GROUP_AUDIO, "audio/x-ms-wma",          MMS_VALUE_AS_STRING, SLS_AUDIO_WMA, MsfWma, "wma"},
#define MEA_CFG_OPEN_AUDIO_WMA ",audio/wma,audio/x-ms-wma"
#define MEA_CFG_CT_MIME_2_MT_WMA {"audio/wma", MEA_MEDIA_TYPE_WMA},\
    {"audio/x-ms-wma", MEA_MEDIA_TYPE_WMA},
#else
#define MEA_CFG_MEDIA_OBJECT_WMA
#define MEA_CFG_OPEN_AUDIO_WMA
#define MEA_CFG_CT_MIME_2_MT_WMA
#endif

#ifdef AAC_DECODE
#define MEA_CFG_MEDIA_OBJECT_AAC     {MEA_MEDIA_TYPE_AAC,        MEA_MEDIA_GROUP_AUDIO, "audio/aac",          MMS_VALUE_AS_STRING, SLS_AUDIO_AAC, MsfAac, "aac"},
#define MEA_CFG_OPEN_AUDIO_AAC ",audio/aac"
#define MEA_CFG_CT_MIME_2_MT_AAC {"audio/aac", MEA_MEDIA_TYPE_AAC},
#else
#define MEA_CFG_MEDIA_OBJECT_AAC
#define MEA_CFG_OPEN_AUDIO_AAC
#define MEA_CFG_CT_MIME_2_MT_AAC
#endif

#if defined(MP4_CODEC) && defined(AAC_DECODE)
#define MEA_CFG_MEDIA_OBJECT_M4A     {MEA_MEDIA_TYPE_M4A,        MEA_MEDIA_GROUP_AUDIO, "audio/m4a",          MMS_VALUE_AS_STRING, SLS_AUDIO_M4A, MsfM4a, "m4a"},\
    {MEA_MEDIA_TYPE_M4A,        MEA_MEDIA_GROUP_AUDIO, "audio/mp4",          MMS_VALUE_AS_STRING, SLS_AUDIO_M4A, MsfM4a, "m4a"},\
    {MEA_MEDIA_TYPE_M4A,        MEA_MEDIA_GROUP_AUDIO, "audio/x-m4a",          MMS_VALUE_AS_STRING, SLS_AUDIO_M4A, MsfM4a, "m4a"},
#define MEA_CFG_OPEN_AUDIO_M4A ",audio/m4a"
#define MEA_CFG_CT_MIME_2_MT_M4A {"audio/m4a", MEA_MEDIA_TYPE_M4A},
#else
#define MEA_CFG_MEDIA_OBJECT_M4A
#define MEA_CFG_OPEN_AUDIO_M4A
#define MEA_CFG_CT_MIME_2_MT_M4A
#endif

#ifdef AIFF_DECODE
#define MEA_CFG_MEDIA_OBJECT_AIFF     {MEA_MEDIA_TYPE_AIFF,        MEA_MEDIA_GROUP_AUDIO, "audio/x-aiff",          MMS_VALUE_AS_STRING, SLS_AUDIO_AIFF, MsfAiff, "aif"},\
    {MEA_MEDIA_TYPE_AIFF,        MEA_MEDIA_GROUP_AUDIO, "audio/x-aiff",          MMS_VALUE_AS_STRING, SLS_AUDIO_AIFF, MsfAiff, "aiff"},\
    {MEA_MEDIA_TYPE_AIFF,        MEA_MEDIA_GROUP_AUDIO, "audio/x-aiff",          MMS_VALUE_AS_STRING, SLS_AUDIO_AIFF, MsfAiff, "aifc"},
#define MEA_CFG_OPEN_AUDIO_AIFF ",audio/x-aiff"
#define MEA_CFG_CT_MIME_2_MT_AIFF {"audio/x-aiff", MEA_MEDIA_TYPE_AIFF},
#else
#define MEA_CFG_MEDIA_OBJECT_AIFF
#define MEA_CFG_OPEN_AUDIO_AIFF
#define MEA_CFG_CT_MIME_2_MT_AIFF
#endif

#ifdef AU_DECODE
#define MEA_CFG_MEDIA_OBJECT_BASIC     {MEA_MEDIA_TYPE_BASIC,        MEA_MEDIA_GROUP_AUDIO, "audio/basic",          MMS_VALUE_AS_STRING, SLS_AUDIO_BASIC, MsfBasic, "au"},\
    {MEA_MEDIA_TYPE_BASIC,        MEA_MEDIA_GROUP_AUDIO, "audio/basic",          MMS_VALUE_AS_STRING, SLS_AUDIO_BASIC, MsfBasic, "snd"},
#define MEA_CFG_OPEN_AUDIO_BASIC ",audio/basic"
#define MEA_CFG_CT_MIME_2_MT_BASIC {"audio/basic", MEA_MEDIA_TYPE_BASIC},
#else
#define MEA_CFG_MEDIA_OBJECT_BASIC
#define MEA_CFG_OPEN_AUDIO_BASIC
#define MEA_CFG_CT_MIME_2_MT_BASIC
#endif

/* Image support */
#ifdef GDI_USING_PNG
#define MEA_CFG_MEDIA_OBJECT_PNG     {MEA_MEDIA_TYPE_PNG,        MEA_MEDIA_GROUP_IMAGE, "image/png",          MMS_TYPE_IMAGE_PNG,  SLS_IMAGE_PNG, MsfPng, "png"},
#define MEA_CFG_OPEN_IMAGE_PNG ",image/png"
#define MEA_CFG_CT_MIME_2_MT_PNG {"image/png", MEA_MEDIA_TYPE_PNG},
#else
#define MEA_CFG_MEDIA_OBJECT_PNG
#define MEA_CFG_OPEN_IMAGE_PNG
#define MEA_CFG_CT_MIME_2_MT_PNG
#endif

/* Video support */
#ifdef MJPG_SUPPORT
#define MEA_CFG_MEDIA_OBJECT_AVI    {MEA_MEDIA_TYPE_AVI,    MEA_MEDIA_GROUP_VIDEO,    "video/x-msvideo",    MMS_VALUE_AS_STRING,    SLS_VIDEO_AVI,    MsfAvi,    "avi"},
#define MEA_CFG_OPEN_VIDEO_AVI ",video/x-msvideo"
#define MEA_CFG_CT_MIME_2_MT_AVI {"video/x-msvideo", MEA_MEDIA_TYPE_AVI},
#else
#define MEA_CFG_MEDIA_OBJECT_AVI
#define MEA_CFG_OPEN_VIDEO_AVI
#define MEA_CFG_CT_MIME_2_MT_AVI
#endif

#ifdef MP4_CODEC
#define MEA_CFG_MEDIA_OBJECT_3GP_MP4  {MEA_MEDIA_TYPE_3GP,    MEA_MEDIA_GROUP_VIDEO,    "video/3gpp",    MMS_VALUE_AS_STRING, SLS_VIDEO_3GP, Msf3gp, "3gp"},\
    {MEA_MEDIA_TYPE_3GP,    MEA_MEDIA_GROUP_VIDEO,    "video/3gp",    MMS_VALUE_AS_STRING, SLS_VIDEO_3GP, Msf3gp, "3gp"},\
    {MEA_MEDIA_TYPE_3GP,    MEA_MEDIA_GROUP_VIDEO,    "video/3gpp2",   MMS_VALUE_AS_STRING, SLS_VIDEO_3GP, Msf3gp, "3g2"},\
    {MEA_MEDIA_TYPE_MP4,    MEA_MEDIA_GROUP_VIDEO,    "video/mp4",    MMS_VALUE_AS_STRING, SLS_VIDEO_MP4, MsfMp4, "mp4"},\
    {MEA_MEDIA_TYPE_MPEG,    MEA_MEDIA_GROUP_VIDEO,    "video/mpeg",    MMS_VALUE_AS_STRING, SLS_VIDEO_MPEG, MsfMp4, "mpg"},
#define MEA_CFG_CT_MIME_2_MT_3GP_MP4  {"video/3gpp", MEA_MEDIA_TYPE_3GP},\
                                 {"video/3gpp2", MEA_MEDIA_TYPE_3GP},\
                                 {"video/mp4", MEA_MEDIA_TYPE_MP4},\
                                 {"video/mpeg", MEA_MEDIA_TYPE_MPEG},
#else
#define MEA_CFG_MEDIA_OBJECT_3GP_MP4
#define MEA_CFG_CT_MIME_2_MT_3GP_MP4
#endif

/* Attachment support */
#ifdef SVG_SUPPORT
#define MEA_CFG_EXT_ATTACHMENT_SVG  {"image/svg+xml","svg"},
#define MEA_CFG_OPEN_EXT_ATTACHMENT_SVG "image/svg+xml,"
#else
#define MEA_CFG_EXT_ATTACHMENT_SVG
#define MEA_CFG_OPEN_EXT_ATTACHMENT_SVG
#endif

#ifdef M3D_SUPPORT
#define MEA_CFG_EXT_ATTACHMENT_M3D  {"application/vnd.mtk.m3d","m3d"},
#define MEA_CFG_OPEN_EXT_ATTACHMENT_M3D "application/vnd.mtk.m3d,"
#else
#define MEA_CFG_EXT_ATTACHMENT_M3D
#define MEA_CFG_OPEN_EXT_ATTACHMENT_M3D
#endif

#ifdef __J2ME__
#define MEA_CFG_EXT_ATTACHMENT_JAVA  {"text/vnd.sun.j2me.app-descriptor", "jad"},    \
{"application/java-archive", "jar"},
#define MEA_CFG_OPEN_EXT_ATTACHMENT_JAVA "text/vnd.sun.j2me.app-descriptor,application/java-archive,"
#else
#define MEA_CFG_EXT_ATTACHMENT_JAVA
#define MEA_CFG_OPEN_EXT_ATTACHMENT_JAVA
#endif

#ifdef __MMI_BARCODEREADER__
#define MEA_CFG_EXT_ATTACHMENT_QRV      {"application/qrv", "qrv"},
#define MEA_CFG_OPEN_EXT_ATTACHMENT_QRV "application/qrv,"
#else
#define MEA_CFG_EXT_ATTACHMENT_QRV
#define MEA_CFG_OPEN_EXT_ATTACHMENT_QRV
#endif /*__MMI_BARCODEREADER__*/

#ifdef __MMI_OBIGO_Q03C_MMS_USER_DEFINED_TEMPLATES__
#define MEA_CFG_USER_TEMPLATE_SUPPORT
#endif

#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
#define MEA_MH_LANG_FILE "/mea/syslang"
#endif

/*! The MEA has support for several media types for audio, text and image
 * when creating (and edit) a multimedia message. Add or remove support by add
 * or remove items in the list, see #MeaMediaType for supported types.
 *
 * NOTE: The list need fault tolerance for some common mistakes in incoming MMS. ex. wrong MIME: image/jpg, video/3gp
 *
 * format:
 *
 * {#MeaMediaType, #MeaMediaGroupType, mime-type, IANA assigned number, #SlsMediaType, Msf type, file extension}
 */ 
#define MEA_CFG_MEDIA_OBJECTS   {\
    {MEA_MEDIA_TYPE_JPEG,       MEA_MEDIA_GROUP_IMAGE, "image/jpeg",         MMS_TYPE_IMAGE_JPEG, SLS_IMAGE_JPG, MsfJpeg, "jpg"},\
    {MEA_MEDIA_TYPE_JPEG,       MEA_MEDIA_GROUP_IMAGE, "image/jpeg",         MMS_TYPE_IMAGE_JPEG, SLS_IMAGE_JPG, MsfJpeg, "jpeg"},\
    {MEA_MEDIA_TYPE_JPEG,       MEA_MEDIA_GROUP_IMAGE, "image/jpg",         MMS_TYPE_IMAGE_JPEG, SLS_IMAGE_JPG, MsfJpeg, "jpg"},\
    {MEA_MEDIA_TYPE_JPEG,       MEA_MEDIA_GROUP_IMAGE, "image/jpg",         MMS_TYPE_IMAGE_JPEG, SLS_IMAGE_JPG, MsfJpeg, "jpeg"},\
    {MEA_MEDIA_TYPE_WBMP,       MEA_MEDIA_GROUP_IMAGE, "image/vnd.wap.wbmp", MMS_TYPE_IMAGE_VND_WAP_WBMP, SLS_IMAGE_WBMP, MsfWbmp, "wbmp"},\
    {MEA_MEDIA_TYPE_WBMP,       MEA_MEDIA_GROUP_IMAGE, "image/vnd.wap.wbmp", MMS_TYPE_IMAGE_VND_WAP_WBMP, SLS_IMAGE_WBMP, MsfWbmp, "wbm"},\
    {MEA_MEDIA_TYPE_GIF,        MEA_MEDIA_GROUP_IMAGE, "image/gif",          MMS_TYPE_IMAGE_GIF,  SLS_IMAGE_GIF, MsfGif, "gif"},\
    MEA_CFG_MEDIA_OBJECT_PNG\
    {MEA_MEDIA_TYPE_BMP,        MEA_MEDIA_GROUP_IMAGE, "image/bmp",          MMS_VALUE_AS_STRING, SLS_IMAGE_BMP, MsfBmp, "bmp"},\
    {MEA_MEDIA_TYPE_BMP,        MEA_MEDIA_GROUP_IMAGE, "image/bitmap",       MMS_VALUE_AS_STRING, SLS_IMAGE_BMP, MsfBmp, "bmp"},\
    {MEA_MEDIA_TYPE_BMP,        MEA_MEDIA_GROUP_IMAGE, "image/x-MS-bmp",       MMS_VALUE_AS_STRING, SLS_IMAGE_BMP, MsfBmp, "bmp"},\
    \
    {MEA_MEDIA_TYPE_TEXT_PLAIN, MEA_MEDIA_GROUP_TEXT,  "text/plain",         MMS_TYPE_TEXT_PLAIN, SLS_TEXT_PLAIN, 0, "txt"},\
    {MEA_MEDIA_TYPE_TEXT_PLAIN, MEA_MEDIA_GROUP_TEXT,  "application/text",   MMS_TYPE_TEXT_PLAIN, SLS_TEXT_PLAIN, 0, "txt"},\
    \
    {MEA_MEDIA_TYPE_AMR,        MEA_MEDIA_GROUP_AUDIO, "audio/amr",          MMS_VALUE_AS_STRING, SLS_AUDIO_AMR, MsfAmr, "amr"},\
    MEA_CFG_MEDIA_OBJECT_AWB\
    {MEA_MEDIA_TYPE_WAV,        MEA_MEDIA_GROUP_AUDIO, "audio/x-wav",        MMS_VALUE_AS_STRING, SLS_AUDIO_WAV, MsfWav, "wav"},\
    {MEA_MEDIA_TYPE_WAV,        MEA_MEDIA_GROUP_AUDIO, "audio/wav",          MMS_VALUE_AS_STRING, SLS_AUDIO_WAV, MsfWav, "wav"},\
    {MEA_MEDIA_TYPE_MIDI,       MEA_MEDIA_GROUP_AUDIO, "audio/midi",         MMS_VALUE_AS_STRING, SLS_AUDIO_MIDI, MsfMidi, "midi"},\
    {MEA_MEDIA_TYPE_MIDI,       MEA_MEDIA_GROUP_AUDIO, "audio/midi",         MMS_VALUE_AS_STRING, SLS_AUDIO_MIDI, MsfMidi, "mid"},\
    {MEA_MEDIA_TYPE_MIDI,       MEA_MEDIA_GROUP_AUDIO, "audio/mid",         MMS_VALUE_AS_STRING, SLS_AUDIO_MIDI, MsfMidi, "midi"},\
    {MEA_MEDIA_TYPE_MIDI,       MEA_MEDIA_GROUP_AUDIO, "audio/mid",         MMS_VALUE_AS_STRING, SLS_AUDIO_MIDI, MsfMidi, "mid"},\
    {MEA_MEDIA_TYPE_MIDI,       MEA_MEDIA_GROUP_AUDIO, "audio/sp-midi",         MMS_VALUE_AS_STRING, SLS_AUDIO_MIDI, MsfMidi, "midi"},\
    {MEA_MEDIA_TYPE_MIDI,       MEA_MEDIA_GROUP_AUDIO, "audio/sp-midi",         MMS_VALUE_AS_STRING, SLS_AUDIO_MIDI, MsfMidi, "mid"},\
    {MEA_MEDIA_TYPE_MIDI,       MEA_MEDIA_GROUP_AUDIO, "x-music/x-midi",         MMS_VALUE_AS_STRING, SLS_AUDIO_MIDI, MsfMidi, "midi"},\
    {MEA_MEDIA_TYPE_MIDI,       MEA_MEDIA_GROUP_AUDIO, "x-music/x-midi",         MMS_VALUE_AS_STRING, SLS_AUDIO_MIDI, MsfMidi, "mid"},\
    MEA_CFG_MEDIA_OBJECT_MMF\
    {MEA_MEDIA_TYPE_IMY,       MEA_MEDIA_GROUP_AUDIO, "text/x-imelody",         MMS_VALUE_AS_STRING, SLS_AUDIO_IMY, MsfImelody, "imy"},\
    {MEA_MEDIA_TYPE_IMY,       MEA_MEDIA_GROUP_AUDIO, "audio/imelody",         MMS_VALUE_AS_STRING, SLS_AUDIO_IMY, MsfImelody, "imy"},\
    MEA_CFG_MEDIA_OBJECT_DAF\
    MEA_CFG_MEDIA_OBJECT_WMA\
    MEA_CFG_MEDIA_OBJECT_AAC\
    MEA_CFG_MEDIA_OBJECT_M4A\
    MEA_CFG_MEDIA_OBJECT_AIFF\
    MEA_CFG_MEDIA_OBJECT_BASIC\
    \
    MEA_CFG_MEDIA_OBJECT_3GP_MP4\
    MEA_CFG_MEDIA_OBJECT_AVI\
    \
    {MEA_MEDIA_TYPE_VCARD, MEA_MEDIA_GROUP_NONE,	"text/x-vcard", MMS_TYPE_TEXT_X_VCARD, SLS_TEXT_X_VCARD, 0, "vcf"}, \
    {MEA_MEDIA_TYPE_VCALENDAR, MEA_MEDIA_GROUP_NONE,	"text/x-vcalendar", MMS_TYPE_TEXT_X_VCALENDAR, SLS_TEXT_X_VCAL, 0, "vcs"}, \
    \
    {MEA_MEDIA_TYPE_DRM_MESSAGE, MEA_MEDIA_GROUP_DRM,	"application/vnd.oma.drm.message", MMS_VALUE_AS_STRING, SLS_DRM_MESSAGE, 0, "dm"}, \
    {MEA_MEDIA_TYPE_DRM_MESSAGE, MEA_MEDIA_GROUP_DRM,	"application/vnd.oma.drm.message", MMS_TYPE_APP_VND_OMA_DRM_MESSAGE, SLS_DRM_MESSAGE, 0, "dm"}, \
    {MEA_MEDIA_TYPE_DRM_CONTENT, MEA_MEDIA_GROUP_DRM,	"application/vnd.oma.drm.content", MMS_VALUE_AS_STRING, SLS_DRM_CONTENT, 0, "dcf"}, \
    {MEA_MEDIA_TYPE_DRM_CONTENT, MEA_MEDIA_GROUP_DRM,	"application/vnd.oma.drm.content", MMS_TYPE_APP_VND_OMA_DRM_CONTENT, SLS_DRM_CONTENT, 0, "dcf"}, \
    {MEA_MEDIA_TYPE_DRM_CONTENT, MEA_MEDIA_GROUP_DRM,	"application/dcf", MMS_VALUE_AS_STRING, SLS_DRM_MESSAGE, 0, "dcf"}, \
    {MEA_MEDIA_TYPE_DRM_CONTENT, MEA_MEDIA_GROUP_DRM,	"application/dcf", MMS_TYPE_APP_VND_OMA_DRM_CONTENT, SLS_DRM_CONTENT, 0, "dcf"}, \
    {MEA_MEDIA_TYPE_UNKNOWN,     MEA_MEDIA_GROUP_NONE,  "",                   MMS_TYPE_ANY_ANY,    SLS_NOT_USED,  0,      ""}}

/*! Extended supported attachment types for the MEA.
 * Support attachment type more than MEA_CFG_MEDIA_OBJECTS. Add or remove items 
 * in the list in order to provide support for specific formats. 
 *
 * 1. SMA_CFG_ATTACHMENT_MEDIA_TYPES in sma_cfg.h should be modified accordingly
 * 2. MEA_CFG_EXT_ATTACHMENT_MEDIA_TYPES, MEA_CFG_OPEN_EXT_ATTACHMENT_TYPES in mea_cfg.h should be modified accordingly
 * 3. HDIa_widgetExtFmgrMediaInput() in mobile_suite_app.c should be modified accordingly
 *
 *  Format:
 * {mime type, file extension}
 */
#define MEA_CFG_EXT_ATTACHMENT_MEDIA_TYPES {\
    {"application/vnd.mtk.lrc", "lrc"},    \
    MEA_CFG_EXT_ATTACHMENT_JAVA\
    MEA_CFG_EXT_ATTACHMENT_QRV\
    MEA_CFG_EXT_ATTACHMENT_SVG\
    MEA_CFG_EXT_ATTACHMENT_M3D\
    {"text/plain", "txt"},\
    {"application/text", "txt"},\
	{"chemical/x-pdb", "pdb"},\
    {"mtk/med.thm", "med"},\
    {"audio/vm", "vm"},\
    {"application/vnd.mtk.ems", "ems"},\
    {"application/vnd.oma.drm.dcf", "odf"},\
    {"application/vnd.mtk.mbc", "mbc"},\
    {"application/x-pilot-pdb", "pdb"},\
    {NULL,                   0}}

#define MEA_CFG_OPEN_EXT_ATTACHMENT_TYPES  MEA_CFG_OPEN_EXT_ATTACHMENT_SVG\
    MEA_CFG_OPEN_EXT_ATTACHMENT_QRV\
    MEA_CFG_OPEN_EXT_ATTACHMENT_M3D\
    MEA_CFG_OPEN_EXT_ATTACHMENT_JAVA\
    "application/vnd.mtk.lrc,"\
    "text/plain,"\
    "application/text,"\
    "mtk/med.thm,"\
    "chemical/x-pdb,"\
    "audio/vm,"\
    "application/vnd.mtk.ems,"\
    "application/vnd.oma.drm.dcf,"\
    "application/vnd.mtk.mbc,"\
    "application/x-pilot-pdb"

/*! This is the filter for file manager. MIME-types presented in this list
 *  is the ones that can be included in a message. Note that the 
 *  #MEA_CFG_MEDIA_OBJECTS needs to contain the same values in order to be able
 *  to actually add the object to the message.
 */
#define MEA_CFG_OPEN_RESTRICTED_IMAGE_TYPES "image/jpeg,image/vnd.wap.wbmp,image/gif"
#define MEA_CFG_OPEN_RESTRICTED_TEXT_TYPES  "text/plain,application/text"
#define MEA_CFG_OPEN_RESTRICTED_AUDIO_TYPES "audio/midi,audio/mid,audio/amr,x-music/x-midi,audio/sp-midi"
#define MEA_CFG_OPEN_RESTRICTED_VIDEO_TYPES "video/3gpp,video/3gpp2,video/mpeg,video/mp4"
#define MEA_CFG_OPEN_RESTRICTED_ATTACHMENT_TYPES MEA_CFG_OPEN_RESTRICTED_IMAGE_TYPES\
	","\
	MEA_CFG_OPEN_RESTRICTED_TEXT_TYPES\
	","\
	MEA_CFG_OPEN_RESTRICTED_AUDIO_TYPES\
	","\
	MEA_CFG_OPEN_RESTRICTED_VIDEO_TYPES\
    ",text/x-vcard,text/x-vcalendar"

#define MEA_CFG_OPEN_IMAGE_TYPES MEA_CFG_OPEN_RESTRICTED_IMAGE_TYPES\
	MEA_CFG_OPEN_IMAGE_PNG\
	",image/bmp,image/bitmap"
#define MEA_CFG_OPEN_TEXT_TYPES  MEA_CFG_OPEN_RESTRICTED_TEXT_TYPES
#define MEA_CFG_OPEN_AUDIO_TYPES MEA_CFG_OPEN_RESTRICTED_AUDIO_TYPES\
	MEA_CFG_OPEN_AUDIO_AWB\
	MEA_CFG_OPEN_AUDIO_DAF\
	MEA_CFG_OPEN_AUDIO_MMF\
	MEA_CFG_OPEN_AUDIO_WMA\
	MEA_CFG_OPEN_AUDIO_AAC\
	MEA_CFG_OPEN_AUDIO_M4A\
	MEA_CFG_OPEN_AUDIO_AIFF\
	MEA_CFG_OPEN_AUDIO_BASIC\
	",audio/wav,audio/x-wav,text/x-imelody,audio/imelody"
#define MEA_CFG_OPEN_VIDEO_TYPES MEA_CFG_OPEN_RESTRICTED_VIDEO_TYPES\
	MEA_CFG_OPEN_VIDEO_AVI
#define MEA_CFG_OPEN_ATTACHMENT_TYPES MEA_CFG_OPEN_IMAGE_TYPES\
	","\
	MEA_CFG_OPEN_TEXT_TYPES\
	","\
	MEA_CFG_OPEN_AUDIO_TYPES\
	","\
	MEA_CFG_OPEN_VIDEO_TYPES\
	","\
	MEA_CFG_OPEN_EXT_ATTACHMENT_TYPES\
	",text/x-vcard,text/x-vcalendar"\
    

/*! The MEA uses UTF-8 for all internal strings. When editing messages created
 *  by other software a different character set may be used. Therefore the MEA
 *  must perform a conversion to UTF-8. The following definitions sets the 
 *  defines which character sets that are supported and how to convert between
 *  MMS and MSF definitions.
 *	
 * format:
 *
 *    {Mms character set #MmsCharset, MSF character set}
 */
#define MEA_CFG_SUPPORTED_CHARSETS  {{MMS_US_ASCII, MSF_CHARSET_ASCII},\
    {MMS_UTF8, MSF_CHARSET_UTF_8}, {MMS_UTF16BE, MSF_CHARSET_UTF_16BE},\
    {MMS_UTF16LE, MSF_CHARSET_UTF_16LE}, {MMS_UTF16, MSF_CHARSET_UTF_16},\
    {MMS_ISO_8859_1, MSF_CHARSET_ISO_8859_1}, {MMS_UCS2, MSF_CHARSET_UCS_2},\
    /* The next line must be present */\
    {MMS_UNKNOWN_CHARSET, MSF_CHARSET_UNKNOWN}}

/*! The character set of the Subject field of created messages
 *  Text-string | Value-length Char-set Text-string
 *  [OMA-MMS-ENC, Section 7.2.12]. Change when MMS Proxy-Relays don't handle
 *  UTF-8 encoded subject fields correctly.
 *
 *	Supported values:
 *      MMS_UTF8        Value-length and Char-set=UTF-8 addded
 *      MMS_US_ASCII    Value-length and Char-set omitted
 */
#define MEA_CFG_SUBJECT_CHARSET                 MMS_UTF8

/*! Exclude operations from object-actions. When viewing a multi-part mixed
 *  message and the user chooses to perform an action on the object, it is
 *  possible to block some of the possible operations. 
 *
 * Format: {"action 1", "action 2", "action n"}
 *
 * For information about which operations that are possible see, msf_cfg.h and
 * msf_act.h.
 */
#define MEA_CFG_EXCLUDE_ACTIONS     {"-mode new -i"}

/*! The maximum size of a text to include into a SMIL presentation.
 *  Texts larger than the stated size is going to be rejected with
 *  an alert to the End User. Setting this variable to a value larger than 
 *  MEA_CFG_MESSAGE_SIZE_MAXIMUM or MEA_CFG_INSERT_MEDIA_OBJECT_MAX_SIZE 
 *  renders it useless. 
 */      
#define MEA_CFG_INSERT_TEXT_MAX_SIZE            (30*1024)  /* 30k */
 
/*! The maximum size of an image to include into a SMIL presentation.
 *  Images larger than the stated size is going to be rejected with
 *  an alert to the End User. Setting this variable to a value larger than 
 *  MEA_CFG_MESSAGE_SIZE_MAXIMUM or MEA_CFG_INSERT_MEDIA_OBJECT_MAX_SIZE 
 *  renders it useless. 
 */      
#define MEA_CFG_INSERT_IMAGE_MAX_SIZE           (30*1024)  /* 30k */

/*! The maximum size of a media object to include into a SMIL presentation.
 *  Media objects larger than the stated size is going to be rejected with
 *  an alert to the End User. Setting this variable to a value larger than 
 *  MEA_CFG_MESSAGE_SIZE_MAXIMUM renders it useless. 
 */
#define MEA_CFG_INSERT_MEDIA_OBJECT_MAX_SIZE    (wap_custom_get_max_mms_msg_size()) /* 95k */

/*! The maximum size in total of an MM. It is not possible to create or view  
 *  larger messages than this value. Upon viewing, a warning is issued. 
 */
#define MEA_CFG_MESSAGE_SIZE_MAXIMUM            (wap_custom_get_max_mms_msg_size())//99000 /* 100k */

/*! The size of an MM that will generate a warning if surpassed that informs
 *	the user of the fact that this message may not be viewable by others.
 *  (i.e. it won't comply with MMS conformance specification)
 *  Setting this value above MEA_CFG_MESSAGE_SIZE_MAXIMUM and 
 *  MEA_CFG_INSERT_MEDIA_OBJECT_MAX_SIZE renders it useless.
 */
#define MEA_CFG_MESSAGE_SIZE_WARNING            (39*1024) /* 39k */

/*! The max size of a text shown in MIXED viewer. 
 *   Texts larger than the stated size is going to be rejected.
 */
/* MMI_UC_MAX_CHAR_NUM_IN_ONE_SLIDE = 2048 UCS2
 * MEA_CFG_MIXED_TEXT_MAX_SIZE = 2048*3 + 1
 */
#define MEA_CFG_MIXED_TEXT_MAX_SIZE    (6145) /*(4096) MEA_CFG_INSERT_TEXT_MAX_SIZE*/
#define MEA_CFG_MIXED_TEXT_MAX_READ_SIZE    (MEA_CFG_MIXED_TEXT_MAX_SIZE + 4)
#define MEA_CFG_MESSAGE_LOAD_MAX_SIZE (100*1024) 

/*! The MEA can be started in an edit mode where content is inserted in the
 *  first slide. The following definition states which MIME types that are
 *  supported.
 */

#define MEA_CFG_CT_RESTRICTED_MIME_2_MT    {{"text/plain", MEA_MEDIA_TYPE_TEXT_PLAIN},\
                                 {"application/text", MEA_MEDIA_TYPE_TEXT_PLAIN},\
                                 \
                                 {"image/jpeg", MEA_MEDIA_TYPE_JPEG},\
                                 {"image/vnd.wap.wbmp", MEA_MEDIA_TYPE_WBMP},\
                                 {"image/gif", MEA_MEDIA_TYPE_GIF},\
                                 \
                                 {"audio/amr", MEA_MEDIA_TYPE_AMR},\
                                 {"audio/midi", MEA_MEDIA_TYPE_MIDI},\
                                 {"audio/mid", MEA_MEDIA_TYPE_MIDI},\
                                 {"audio/sp-midi", MEA_MEDIA_TYPE_MIDI},\
                                 \
                                 MEA_CFG_CT_MIME_2_MT_3GP_MP4\
                                 \
                                 {NULL, MEA_MEDIA_TYPE_END_TYPE}}

#define MEA_CFG_CT_MIME_2_MT    {{"text/plain", MEA_MEDIA_TYPE_TEXT_PLAIN},\
                                 {"application/text", MEA_MEDIA_TYPE_TEXT_PLAIN},\
                                 \
                                 {"image/jpeg", MEA_MEDIA_TYPE_JPEG},\
                                 {"image/vnd.wap.wbmp", MEA_MEDIA_TYPE_WBMP},\
                                 {"image/gif", MEA_MEDIA_TYPE_GIF},\
                                 MEA_CFG_CT_MIME_2_MT_PNG\
                                 \
                                 {"image/bmp", MEA_MEDIA_TYPE_BMP},\
                                 {"image/bitmap", MEA_MEDIA_TYPE_BMP},\
                                 \
                                 {"audio/x-wav", MEA_MEDIA_TYPE_WAV},\
                                 {"audio/wav", MEA_MEDIA_TYPE_WAV},\
                                 {"audio/amr", MEA_MEDIA_TYPE_AMR},\
                                 MEA_CFG_CT_MIME_2_MT_AWB\
                                 {"audio/midi", MEA_MEDIA_TYPE_MIDI},\
                                 {"audio/mid", MEA_MEDIA_TYPE_MIDI},\
                                 {"audio/sp-midi", MEA_MEDIA_TYPE_MIDI},\
                                 MEA_CFG_CT_MIME_2_MT_DAF\
                                 MEA_CFG_CT_MIME_2_MT_MMF\
                                 MEA_CFG_CT_MIME_2_MT_WMA\
                                 MEA_CFG_CT_MIME_2_MT_AAC\
                                 MEA_CFG_CT_MIME_2_MT_M4A\
                                 MEA_CFG_CT_MIME_2_MT_AIFF\
                                 MEA_CFG_CT_MIME_2_MT_BASIC\
                                 {"text/x-imelody", MEA_MEDIA_TYPE_IMY},\
                                 \
                                 MEA_CFG_CT_MIME_2_MT_3GP_MP4\
                                 MEA_CFG_CT_MIME_2_MT_AVI\
                                 \
                                 {NULL, MEA_MEDIA_TYPE_END_TYPE}}

/*! When setting any port number a verifications is performed against the
 *  limits defined below.
 */
#define MEA_CFG_MIN_PORT                        0
#define MEA_CFG_MAX_PORT                        65535

/*! When creating a SMIL presentation it is possible to limit the number of
 *  slides valid for one presentation.
 */
#define MEA_CFG_SLIDE_LIMIT                     (wap_custom_get_max_mms_slide()) /* Ramped up high enough to be of no consequence */

/*! When multiple MMS addresses id displayed to the End User or if the End User
 * wants to input multiple addresses the following separator is used.
 */
#define MEA_CFG_MMS_ADDRESS_SEPARATOR        ", "

/*! When displaying the To or Cc field of a received message and the adderss 
 * type is email and the "name" is provided, the MEA_EMAIL_BEGIN_STR and
 * MEA_EMAIL_END_STR separates the email address from the name, e.g.,
 * homer@simpson.com <Homer Simpson>
 */
#define MEA_CFG_EMAIL_BEGIN_STR                 " <"
#define MEA_CFG_EMAIL_END_STR                   ">"

/*! The maximum number of digits for duration 
 */
#define MEA_CFG_DURATION_SIZE                   2

/*! The maximum and minimum value for slide duration in seconds.
 *
 */
#define MEA_CFG_MAX_DURATION                    60
#define MEA_CFG_MIN_DURATION                    1

/*! The default duration for each slide, in milliseconds 
 */
#define MEA_CFG_DEFAULT_DURATION                5000

/*! The default setting for read report 0 is off and 1 is on.
 */
#define MEA_CFG_READ_REPORT                     0

/*! The default setting for delivery report 0 is off and 1 is on.
 */
#define MEA_CFG_DELIVERY_REPORT                 MMS_DELIVERY_REPORT_NOT_SET

/*! The default setting for expiry time type. Relative time will be used default..
 */
#define MEA_CONF_EXPIRY_TIME_RELATIVE           TRUE

/*! The default setting for expiry time type. Relative time will be used default..
 */
#define MEA_CONF_DELIVERY_TIME_RELATIVE          TRUE


/*! The default setting for expiry time type. Relative time will be used default..
 */
#define MEA_CONF_CHARGING_DEADLINE_TIME_RELATIVE TRUE

/*! The default setting for expiry time, see #MeaExpiryTimeType for valid values.
 */
#define MEA_CFG_EXPIRY_TIME                     MEA_EXPIRY_MAX

/*! The default setting for priority, see #MeaPriorityType for valid values.
 */
#define MEA_CFG_PRIORITY                        MEA_PRIORITY_NORMAL

/*! The default setting for reply charging, see #MeaReplyChargingType for valid
 *  values
 */
#define MEA_CFG_REPLY_CHARGING                  MEA_REPLY_CHARGING_OFF

/*! The default setting for reply charging deadline, see
 *  #MeaReplyChargingDeadlineType for valid values
 */
#define MEA_CFG_REPLY_CHARGING_DEADLINE         MEA_REPLY_CHARGING_DEADLINE_1_DAY

/*! The default setting for reply charging size, see #MeaReplyChargingSizeType 
 *  for valid values
 */
#define MEA_CFG_REPLY_CHARGING_SIZE             MEA_REPLY_CHARGING_SIZE_1_KB

/*! The default setting for "save on send", 0 for removing a message after send
 *  1 for saving the message in the "sent" folder after send.
 */
#define MEA_CFG_SAVE_ON_SEND                    0

/*! The default setting for allowing PERSONAL messages. 0=no 1=yes */
#define MEA_CFG_ALLOW_PERSONAL                  1

/*! The default setting for allowing ADVERTISMENT messages. 0=no 1=yes */
#define MEA_CFG_ALLOW_ADVERT                    1

/*! The default setting for allowing INFORMATIONAL messages. 0=no 1=yes */
#define MEA_CFG_ALLOW_INFO                      1

/*! The default setting for allowing AUTO messages. 0=no 1=yes */
#define MEA_CFG_ALLOW_AUTO                      1

/*! The default setting for allowing anonymous senders. 0=no 1=yes */
#define MEA_CFG_ALLOW_ANONYM                    1

/*! The default setting for the treat as delayed flag. 0=no 1=yes */
#define MEA_CFG_TREAT_AS_DELAYED                1

/*! The default setting for allowing user defined string in message class. 
 *  ""=not used */
#define MEA_CFG_ALLOW_STRING                    ""

/*! The default setting for allowing immediate retrieval from only one server
 *  ""=not used */
#define MEA_CFG_IM_SERVER                       ""

/*! The default setting for MSISDN if nothing is implemented in /EXTERNAL 
 *  This setting will control which token the MMS Service will send in the 
 *  From field [OMA-MMS-ENC, 7.2.14] in outgoing PDUs. 
 *  Non-empty-string => Address-present-token
 *                "" => Insert-address-token 
 */
#define MEA_CFG_MSISDN                          "0922222222"

/*! The maximum number of digits to set for the immediate retrieval size */
#define MEA_CFG_MAX_IM_RETR_SIZE_DIGITS         7

/*! Minimum possible value of message size for immediate retrieval */
#define MEA_CFG_MIN_MSG_SIZE                    500

#ifndef WAP_SUPPORT //use MMS_DEFAULT_MAX_MSG_SIZE
/*! Maximum possible value of message size for immediate retrieval */
#define MEA_CFG_MAX_MSG_SIZE                    50000//4000000
#endif /* WAP_SUPPORT */

/*! The maximum number of digits to set for the message retrieval size */
#define MEA_CFG_MAX_RETRIEVAL_SIZE_DIGITS       3//7

/*! Minimum possible value of retrieval size of a message. 0 is the largest 
    possible */
#define MEA_CFG_MIN_RETR_SIZE                   1

/*! Maximum possible value of retrieval size of a message */
#if defined(WAP_CUSTOM_CFG_MMS_RETR_SIZE_FILTER) && WAP_CUSTOM_CFG_MMS_RETR_SIZE_FILTER == 0
#define MEA_CFG_MAX_RETR_SIZE                   0
#else
#define MEA_CFG_MAX_RETR_SIZE                   MEA_CFG_MESSAGE_SIZE_MAXIMUM
#endif

/*! MMS version to use against MMSC. 0x10=MMS_VERSION_10 0x11=MMS_VERSION_11 */
#define MEA_CFG_MMSC_VERSION                    0x11

/*! The maximum number of addresses to add to a message during creation */
#define MEA_CFG_MAX_RECIPIENT_ADDRESSES         (wap_custom_get_max_mms_address())

/*! The default background color for SMIL presentations. The color is RGB and
    number of bits per channel are 8. Example 0x00FF0000 for red color  */
#define MEA_CFG_DEFAULT_SMIL_BG_COLOR           0x00FFFFFF

/*! The default text color for SMIL presentations. The color is RGB and
    number of bits per channel are 8. Example 0x0000FF00 for green color  */
#define MEA_CFG_DEFAULT_SMIL_TEXT_COLOR         0x00000000

/*! \brief Possible background colors for SMIL presentations
 *  
 * Format of the colors are: RGB 8-bits for each channel, i.e, 0xRRGGBB
 */
#define MEA_CFG_SMIL_BG_COLORS  {0x000000, \
                                 0x404040, 0x808080, 0xC0C0C0, 0xFFFFFF,\
                                 0x400000, 0x800000, 0xC00000, 0xFF0000,\
                                 0x004000, 0x008000, 0x00C000, 0x00FF00,\
                                 0x000040, 0x000080, 0x0000C0, 0x0000FF}

/*! \brief Possible text colors for SMIL presentations
 *  
 * Format of the colors are: RGB 8-bits for each channel, i.e, 0xRRGGBB
 */
#define MEA_CFG_SMIL_TEXT_COLORS   {0x000000, \
                                    0x404040, 0x808080, 0xC0C0C0, 0xFFFFFF,\
                                    0x400000, 0x800000, 0xC00000, 0xFF0000,\
                                    0x004000, 0x008000, 0x00C000, 0x00FF00,\
                                    0x000040, 0x000080, 0x0000C0, 0x0000FF}

/*! The default setting for Show number. For possible values see 
 * #MeaVisibilityType 
 */
#define MEA_CFG_SHOW_NUMBER                       MEA_SENDER_SHOW

/*! The default setting for X-Mms-Report-Allowed according to MMS Standard */
#ifdef __OP01_MMS_RETRIEVE_SETTING__
#define MEA_CFG_DELIVERY_REPORT_ALLOWED           MMS_DELIVERY_REPORT_NO //0=Yes 1=No
#else
#define MEA_CFG_DELIVERY_REPORT_ALLOWED           MMS_DELIVERY_REPORT_YES //0=Yes 1=No
#endif /*__OP01_MMS_RETRIEVE_SETTING__*/

/*! The default setting for Send read report. 0=On request 1=Always 2=Never*/
#ifdef __OP01_MMS_RETRIEVE_SETTING__
#define MEA_CFG_SEND_READ_REPORT                  MEA_SEND_READ_REPORT_NEVER
#else
#define MEA_CFG_SEND_READ_REPORT                  0
#endif /*__OP01_MMS_RETRIEVE_SETTING__*/

/*! The default setting for Delivery time. 0=Immediate 1=1h 2=12h 3=24h */
#define MEA_CFG_DELIVERY_TIME                     MEA_DELIVERY_TIME_IMMEDIATE //0

/*! The assumed default roaming status. 0 = not roaming, 1 = roaming.*/
#define MEA_CFG_DEFAULT_ROAMING_STATUS            0

/* The assumed default bearer status. 0 = no bearer, 1 = bearer. */
#define MEA_CFG_DEFAULT_BEARER_STATUS             1

/* Default retrieval setting for home network */
#define MEA_CFG_RETRIEVAL_MODE                    MEA_RETRIEVAL_MODE_AUTOMATIC  

/* Default retrieval setting for roaming network */
#define MEA_CFG_RETRIEVAL_MODE_ROAMING \
    MEA_RETRIEVAL_MODE_ROAMING_AUTOMATIC


#endif


