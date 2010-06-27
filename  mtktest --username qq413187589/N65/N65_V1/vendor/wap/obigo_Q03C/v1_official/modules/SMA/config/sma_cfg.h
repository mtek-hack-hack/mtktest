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

/*! \file sma_cfg.h
 * \brief  configuration variables for SMA
 */

#ifndef _SMA_CFG_H
#define _SMA_CFG_H

/*--- Include files ---*/

/*--- Definitions/Declarations ---*/

/* ! Maximum number of items in a context dependent menu
 */
#define SMA_MAX_CONTEXT_LIST_ITEMS      20

/*! 
 *	Default display time for an SMA dialog (in ms)
 */
#define SMA_DIALOG_DEFAULT_TIME_OUT     3000
/*!
 *  If a media object is larger than SMA_MAX_CHUNK_SIZE, the 
 *  media object will be read in chunks. 
 */
/* MMI_UC_MAX_CHAR_NUM_IN_ONE_SLIDE = 2048 UCS2
 * SMA_MAX_CHUNK_SIZE = 2048*3 + 1
 */
#define SMA_MAX_CHUNK_SIZE 6145//4096

 
/*!
 *	Display time, in 10th of a second, for action images.
 *  Minimum value is 1000, i.e. 1 second 
 */
#define SMA_ACTION_IMAGE_TIME 2000


/*!
 *  Minimum duration in seconds for a slide 
 */
#define SMA_MIN_SLIDE_DURATION 1
#define SMA_MAX_SLIDE_DURATION 5999  /* sliding time display MM:SS */

/* MTK-defined feature option */
#ifdef WAP_SUPPORT
/*!
 *  Deciding sliding time by using the longer period of specified sliding duration and media duration
 */
#define SMA_USE_BEST_SLIDE_DURATION 1
#endif

#ifdef __MMI_OBIGO_Q03C_MMS_USER_DEFINED_TEMPLATES__
#define SMA_CFG_USER_TEMPLATE_SUPPORT
#endif

#define SMA_GET_TEXT_TOTAL_HEIGHT 1

/*!
 *  Use this define in order to support cross-triggering, where the SMA starts
 *  the BRA with a specific URL. The default schemes supported are http:// and
 *  https://. To support more schemes or for example; "www.", then add a 
 *  additional entry to the list:
 *
 *    {"www.", sizeof("www.") - 1},\
 *
 */
#define SMA_CONFIG_CROSS_TRIGGERING_SCHEMES  \
    {{"http://", sizeof("http://") - 1},\
    {"https://", sizeof("https://") - 1},\
    {NULL, 0}}

/* Audio */
#ifdef AMRWB_DECODE
#define SMA_CFG_MEDIA_OBJECT_AWB    {SLS_AUDIO_AWB, MsfAmrWB,  SLS_OBJECT_TYPE_AUDIO, "audio/amr-wb"},
#define SMA_CFG_ATTACHMENT_MEDIA_AWB    {"audio/amr-wb",            "awb"},
#else
#define SMA_CFG_MEDIA_OBJECT_AWB
#define SMA_CFG_ATTACHMENT_MEDIA_AWB
#endif

#ifdef DAF_DECODE
#define SMA_CFG_MEDIA_OBJECT_DAF    {SLS_AUDIO_MP3,		MsfMp3,  SLS_OBJECT_TYPE_AUDIO, "audio/mpeg"}, \
    {SLS_AUDIO_MP3,		MsfMp3,  SLS_OBJECT_TYPE_AUDIO, "audio/mp3"},
#define SMA_CFG_ATTACHMENT_MEDIA_MP3    {"audio/mpeg",            "mp3"}, \
    {"audio/mp3",            "mp3"},
#else
#define SMA_CFG_MEDIA_OBJECT_DAF
#define SMA_CFG_ATTACHMENT_MEDIA_MP3
#endif

#ifdef YAMAHA_MA3
#define SMA_CFG_MEDIA_OBJECT_MMF    {SLS_AUDIO_SMAF,    MsfMidi, SLS_OBJECT_TYPE_AUDIO, "application/vnd.smaf"}, \
    {SLS_AUDIO_SMAF,    MsfMidi, SLS_OBJECT_TYPE_AUDIO, "application/x-smaf"},
#define SMA_CFG_ATTACHMENT_MEDIA_MMF    {"application/vnd.smaf",            "mmf"}, \
    {"application/x-smaf",            "mmf"},
#else
#define SMA_CFG_MEDIA_OBJECT_MMF
#define SMA_CFG_ATTACHMENT_MEDIA_MMF
#endif

#ifdef WMA_DECODE
#define SMA_CFG_MEDIA_OBJECT_WMA    {SLS_AUDIO_WMA,		MsfWma,  SLS_OBJECT_TYPE_AUDIO, "audio/wma"},\
    {SLS_AUDIO_WMA,		MsfWma,  SLS_OBJECT_TYPE_AUDIO, "audio/x-ms-wma"},
#define SMA_CFG_ATTACHMENT_MEDIA_WMA    {"audio/wma",            "wma"},\
    {"audio/x-ms-wma",            "wma"},
#else
#define SMA_CFG_MEDIA_OBJECT_WMA
#define SMA_CFG_ATTACHMENT_MEDIA_WMA
#endif

#ifdef AAC_DECODE
#define SMA_CFG_MEDIA_OBJECT_AAC    {SLS_AUDIO_AAC,		MsfAac,  SLS_OBJECT_TYPE_AUDIO, "audio/aac"},
#define SMA_CFG_ATTACHMENT_MEDIA_AAC    {"audio/aac",            "aac"},
#else
#define SMA_CFG_MEDIA_OBJECT_AAC
#define SMA_CFG_ATTACHMENT_MEDIA_AAC
#endif

#if defined(MP4_CODEC) && defined(AAC_DECODE)
#define SMA_CFG_MEDIA_OBJECT_M4A    {SLS_AUDIO_M4A,		MsfM4a,  SLS_OBJECT_TYPE_AUDIO, "audio/m4a"},\
    {SLS_AUDIO_M4A,		MsfM4a,  SLS_OBJECT_TYPE_AUDIO, "audio/mp4"},\
    {SLS_AUDIO_M4A,		MsfM4a,  SLS_OBJECT_TYPE_AUDIO, "audio/x-m4a"},
#define SMA_CFG_ATTACHMENT_MEDIA_M4A    {"audio/m4a",            "m4a"},\
    {"audio/mp4",            "m4a"},\
    {"audio/x-m4a",            "m4a"},
#else
#define SMA_CFG_MEDIA_OBJECT_M4A
#define SMA_CFG_ATTACHMENT_MEDIA_M4A
#endif

#ifdef AIFF_DECODE
#define SMA_CFG_MEDIA_OBJECT_AIFF    {SLS_AUDIO_AIFF,		MsfAiff,  SLS_OBJECT_TYPE_AUDIO, "audio/x-aiff"},
#define SMA_CFG_ATTACHMENT_MEDIA_AIFF    {"audio/x-aiff",            "aiff"},
#else
#define SMA_CFG_MEDIA_OBJECT_AIFF
#define SMA_CFG_ATTACHMENT_MEDIA_AIFF
#endif

#ifdef AU_DECODE
#define SMA_CFG_MEDIA_OBJECT_BASIC    {SLS_AUDIO_BASIC,		MsfBasic,  SLS_OBJECT_TYPE_AUDIO, "audio/basic"},
#define SMA_CFG_ATTACHMENT_MEDIA_BASIC    {"audio/basic",            "au"},
#else
#define SMA_CFG_MEDIA_OBJECT_BASIC
#define SMA_CFG_ATTACHMENT_MEDIA_BASIC
#endif

/* Image */
#ifdef GDI_USING_PNG
#define SMA_CFG_MEDIA_OBJECT_PNG    {SLS_IMAGE_PNG,     MsfPng,  SLS_OBJECT_TYPE_IMAGE, "image/png"},
#define SMA_CFG_ATTACHMENT_MEDIA_PNG    {"image/png",            "png"},
#else
#define SMA_CFG_MEDIA_OBJECT_PNG
#define SMA_CFG_ATTACHMENT_MEDIA_PNG
#endif

/* Video */
#ifdef MP4_CODEC
#define SMA_CFG_MEDIA_OBJECT_3GP    {SLS_VIDEO_3GP,     Msf3gp,  SLS_OBJECT_TYPE_VIDEO, "video/3gpp"},\
    {SLS_VIDEO_3GP,     Msf3gp,  SLS_OBJECT_TYPE_VIDEO, "video/3gpp2"},\
    {SLS_VIDEO_H263,    Msf3gp,  SLS_OBJECT_TYPE_VIDEO,	"video/h263-2000"},
#define SMA_CFG_MEDIA_OBJECT_MP4    {SLS_VIDEO_MP4,     MsfMp4,  SLS_OBJECT_TYPE_VIDEO, "video/mp4"},\
    {SLS_VIDEO_MPEG,     MsfMp4,  SLS_OBJECT_TYPE_VIDEO, "video/mpeg"},
#define SMA_CFG_ATTACHMENT_MEDIA_3GP    {"video/3gpp",            "3gp"},\
    {"video/3gpp2",            "3g2"},\
    {"video/h263-2000",        "3gp"},
#define SMA_CFG_ATTACHMENT_MEDIA_MP4    {"video/mp4",            "mp4"},\
    {"video/mpeg",            "mpg"},
#else
#define SMA_CFG_MEDIA_OBJECT_3GP
#define SMA_CFG_MEDIA_OBJECT_MP4
#define SMA_CFG_ATTACHMENT_MEDIA_3GP
#define SMA_CFG_ATTACHMENT_MEDIA_MP4
#endif

#ifdef MJPG_SUPPORT
#define SMA_CFG_MEDIA_OBJECT_AVI    {SLS_VIDEO_AVI,     MsfAvi,  SLS_OBJECT_TYPE_VIDEO, "video/x-msvideo"},
#define SMA_CFG_ATTACHMENT_MEDIA_AVI    {"video/x-msvideo",            "avi"},
#else
#define SMA_CFG_MEDIA_OBJECT_AVI
#define SMA_CFG_ATTACHMENT_MEDIA_AVI
#endif

/* Attachment */
#ifdef SVG_SUPPORT
#define SMA_CFG_ATTACHMENT_MEDIA_SVG    {"image/svg+xml","svg"},
#else
#define SMA_CFG_ATTACHMENT_MEDIA_SVG
#endif

#ifdef M3D_SUPPORT
#define SMA_CFG_ATTACHMENT_MEDIA_M3D    {"application/vnd.mtk.m3d","m3d"},
#else
#define SMA_CFG_ATTACHMENT_MEDIA_M3D
#endif

#ifdef __J2ME__
#define SMA_CFG_ATTACHMENT_MEDIA_JAVA    {"text/vnd.sun.j2me.app-descriptor", "jad"},\
{"application/java-archive", "jar"},
#else
#define SMA_CFG_ATTACHMENT_MEDIA_JAVA
#endif

#ifdef __MMI_BARCODEREADER__
#define SMA_CFG_ATTACHMENT_MEDIA_QRV      {"application/qrv",      "qrv"},
#else
#define SMA_CFG_ATTACHMENT_MEDIA_QRV
#endif /*__MMI_BARCODEREADER__*/
/*! Supported media types for the SMA.
 * Add or remove items in the list in order to provide support for specific
 * formats. Please note that the SLS module should be configured accordingly,
 * i.e., the SLS data-types used in the list must be configured in the SLS
 * module.
 *
 *  Format:
 *
 * SMA media type
 *
 * {#SlsMediaType, #MsfImageFormat/#MsfSoundFormat, #SlsObjectType, mime type}
 */
#define SMA_CFG_SUPPORTED_MEDIA_TYPES {\
    {SLS_TEXT_PLAIN, 0,       SLS_OBJECT_TYPE_TEXT, "text/plain"}, \
    \
    {SLS_IMAGE_WBMP,	MsfWbmp, SLS_OBJECT_TYPE_IMAGE, "image/vnd.wap.wbmp"},\
    {SLS_IMAGE_JPG,		MsfJpeg, SLS_OBJECT_TYPE_IMAGE, "image/jpeg"}, \
    {SLS_IMAGE_BMP,		MsfBmp,  SLS_OBJECT_TYPE_IMAGE, "image/bmp"}, \
    {SLS_IMAGE_GIF,     MsfGif,  SLS_OBJECT_TYPE_IMAGE, "image/gif"}, \
    SMA_CFG_MEDIA_OBJECT_PNG\
    \
    SMA_CFG_MEDIA_OBJECT_DAF\
    {SLS_AUDIO_AMR,		MsfAmr,  SLS_OBJECT_TYPE_AUDIO, "audio/amr"}, \
    SMA_CFG_MEDIA_OBJECT_AWB\
    {SLS_AUDIO_WAV,		MsfWav,  SLS_OBJECT_TYPE_AUDIO, "audio/wav"}, \
    {SLS_AUDIO_WAV,		MsfWav,  SLS_OBJECT_TYPE_AUDIO, "audio/x-wav"}, \
    {SLS_AUDIO_MIDI,    MsfMidi, SLS_OBJECT_TYPE_AUDIO, "audio/midi"}, \
    {SLS_AUDIO_MIDI,    MsfMidi, SLS_OBJECT_TYPE_AUDIO, "audio/mid"}, \
    {SLS_AUDIO_MIDI,    MsfMidi, SLS_OBJECT_TYPE_AUDIO, "audio/sp-midi"}, \
    {SLS_AUDIO_MIDI,    MsfMidi, SLS_OBJECT_TYPE_AUDIO, "x-music/x-midi"}, \
    SMA_CFG_MEDIA_OBJECT_MMF\
    SMA_CFG_MEDIA_OBJECT_WMA\
    SMA_CFG_MEDIA_OBJECT_AAC\
    SMA_CFG_MEDIA_OBJECT_M4A\
    SMA_CFG_MEDIA_OBJECT_AIFF\
    SMA_CFG_MEDIA_OBJECT_BASIC\
    {SLS_AUDIO_IMY,    MsfImelody, SLS_OBJECT_TYPE_AUDIO, "text/x-imelody"}, \
    {SLS_AUDIO_IMY,    MsfImelody, SLS_OBJECT_TYPE_AUDIO, "audio/imelody"}, \
    \
    SMA_CFG_MEDIA_OBJECT_3GP\
    SMA_CFG_MEDIA_OBJECT_MP4\
    SMA_CFG_MEDIA_OBJECT_AVI\
    \
    {SLS_DRM_MESSAGE,	0,	     SLS_OBJECT_TYPE_DRM,	"application/vnd.oma.drm.message"}, \
    {SLS_DRM_CONTENT,	0,	     SLS_OBJECT_TYPE_DRM,	"application/vnd.oma.drm.content"}, \
    {SLS_NOT_USED,		0,       SLS_OBJECT_TYPE_NONE,						NULL}}




/*! Supported attachment types for the SMA.
 * Add or remove items in the list in order to provide support for specific
 * formats. 
 *
 * MEA_CFG_EXT_ATTACHMENT_MEDIA_TYPES in mea_cfg.h should be modified accordingly
 * MEA_CFG_OPEN_ATTACHMENT_TYPES in mea_cfg.h should be modified accordingly
 * HDIa_widgetExtFmgrMediaInput() in mobile_suite_app.c should be modified accordingly
 *
 *  Format:
 *
 * SMA media type
 *
 * {mime type, file extension}
 */
#define SMA_CFG_ATTACHMENT_MEDIA_TYPES {\
    {"image/vnd.wap.wbmp",   "wbmp"},\
    {"image/jpeg",           "jpg"},\
    {"image/jpg",            "jpg"},\
    {"image/bmp",            "bmp"},\
    {"image/bitmap",         "bmp"},\
    {"image/gif",            "gif"},\
    {"text/plain",           "txt"},\
    {"application/text",     "txt"},\
	{"chemical/x-pdb",       "pdb"},\
	{"application/vnd.mtk.mbc", "mbc"},\
    {"application/vnd.mtk.ems", "ems"},\
    SMA_CFG_ATTACHMENT_MEDIA_QRV\
    {"audio/vm",              "vm"},\
    SMA_CFG_ATTACHMENT_MEDIA_PNG\
    \
    SMA_CFG_ATTACHMENT_MEDIA_3GP\
    SMA_CFG_ATTACHMENT_MEDIA_MP4\
    SMA_CFG_ATTACHMENT_MEDIA_AVI\
    \
    {"audio/amr",            "amr"},\
    {"audio/wav",            "wav"},\
    {"audio/x-wav",          "wav"},\
    {"audio/midi",           "midi"},\
    {"audio/mid",            "midi"},\
    {"audio/sp-midi",        "midi"},\
    {"x-music/x-midi",        "midi"},\
    SMA_CFG_ATTACHMENT_MEDIA_MP3\
    SMA_CFG_ATTACHMENT_MEDIA_AWB\
    SMA_CFG_ATTACHMENT_MEDIA_MMF\
    SMA_CFG_ATTACHMENT_MEDIA_WMA\
    SMA_CFG_ATTACHMENT_MEDIA_AAC\
    SMA_CFG_ATTACHMENT_MEDIA_M4A\
    SMA_CFG_ATTACHMENT_MEDIA_AIFF\
    SMA_CFG_ATTACHMENT_MEDIA_BASIC\
    {"audio/imelody",        "imy"},\
    {"text/x-imelody",       "imy"},\
    \
    {"text/x-vcard",         "vcd"},\
    {"text/x-vcalendar",     "vcl"},\
    {"application/vnd.oma.drm.message", "dm"},\
    {"application/vnd.oma.drm.content", "dcf"},\
    {"application/vnd.mtk.lrc", "lrc"},\
    SMA_CFG_ATTACHMENT_MEDIA_JAVA\
    SMA_CFG_ATTACHMENT_MEDIA_SVG\
    SMA_CFG_ATTACHMENT_MEDIA_M3D\
    {"application/vnd.oma.drm.dcf", "odf"},\
    {"mtk/med.thm", "med"},\
    {"application/x-pilot-pdb", "pdb"},\
    \
    {NULL,                   0}}

#endif /* _SMA_CFG_H */


