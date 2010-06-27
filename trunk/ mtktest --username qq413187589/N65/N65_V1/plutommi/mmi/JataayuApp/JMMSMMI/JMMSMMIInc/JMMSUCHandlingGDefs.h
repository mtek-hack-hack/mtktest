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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *  JMMSUCHandlingGDefs.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contans the enums,constants,structures, function prototypes used in
 * MMSTemplates.c
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __MMI_UC_JMMS_GDEFS_H
#define __MMI_UC_JMMS_GDEFS_H

#if defined (JATAAYU_SUPPORT) && defined (MMS_SUPPORT) && defined (__UNIFIED_COMPOSER_SUPPORT__)

#if defined(__DRM_ODF_SUPPORT__)
#define DEF_ODF_SUPPORT "application/vnd.oma.drm.dcf,"
#else 
#define DEF_ODF_SUPPORT ","
#endif 

#if defined (JPG_DECODE)
#define DEF_JPG_DECODE "image/jpeg,image/jpg,image/jpeg,"
#else 
#define DEF_JPG_DECODE ","
#endif 

#if defined(USE_HW_PNG_DECODER_V1) || defined(USE_SW_PNG_DECODER)
#define DEF_USE_HW_PNG_DECODER_V1_OR_USE_SW_PNG_DECODER "image/png,"
#else 
#define DEF_USE_HW_PNG_DECODER_V1_OR_USE_SW_PNG_DECODER ","
#endif 

#if defined(SVG_SUPPORT)
#define DEF_SVG_SUPPORT "image/svg+xml,"
#else 
#define DEF_SVG_SUPPORT ","
#endif 

#define JMMS_IMAGE_TYPES "image/bmp,image/x-MS-bmp,image/gif,image/vnd.wap.wbmp"               \
","                                                                                            \
DEF_JPG_DECODE                                                                                 \
","                                                                                            \
DEF_USE_HW_PNG_DECODER_V1_OR_USE_SW_PNG_DECODER                                                \
","                                                                                            \
DEF_SVG_SUPPORT                                                                                \
","                                                                                            \
DEF_ODF_SUPPORT

#if defined(__MMI_EBOOK_READER__)
#define DEF_MMI_EBOOK_READER "text/plain,"
#else 
#define DEF_MMI_EBOOK_READER ","
#endif 

#if defined(WAP_SUPPORT)
#define DEF_WAP_SUPPORT "text/html,text/vnd.wap.wml,"
#else 
#define DEF_WAP_SUPPORT ","
#endif 

#define JMMS_TEXT_TYPES DEF_MMI_EBOOK_READER               \
","                                                        \
DEF_WAP_SUPPORT                                            \

#if defined(AAC_DECODE)
#define DEF_AAC_DECODE "audio/aac,audio/x-aac,"
#else 
#define DEF_AAC_DECODE ","
#endif 

#if defined(AMRWB_DECODE)
#define DEF_AMRWB_DECODE "audio/amr-wb,"
#else 
#define DEF_AMRWB_DECODE ","
#endif 

#if defined(DAF_DECODE)
#define DEF_DAF_DECODE "audio/mp3,audio/mpeg,audio/mpg,audio/mpg3,audio/x-mp3,audio/mpeg3,"
#else 
#define DEF_DAF_DECODE ","
#endif 

#if defined(MP4_CODEC) && defined(AAC_DECODE)
#define DEF_MP4_CODEC_AND_AAC_DECODE "audio/m4a,audio/x-m4a,"
#else 
#define DEF_MP4_CODEC_AND_AAC_DECODE ","
#endif 

#if defined(WMA_DECODE)
#define DEF_WMA_DECODE "audio/wma,audio/x-ms-wma,"
#else 
#define DEF_WMA_DECODE ","
#endif 

#if defined(YAMAHA_MA3)
#define DEF_MMF_DECODE "application/vnd.smaf,application/x-smaf,"
#else 
#define DEF_MMF_DECODE ","
#endif 

#if defined(MP4_CODEC)
#define DEF_MP4_CODEC_AUDIO "audio/3gpp,"
#else 
#define DEF_MP4_CODEC_AUDIO ","
#endif 

#if defined(MUSICAM_DECODE)
#define DEF_MP2_CODEC_AUDIO "audio/mp2,"
#else 
#define DEF_MP2_CODEC_AUDIO ","
#endif 

#define JMMS_AUDIO_TYPES "audio/amr,audio/imelody,audio/mid,audio/midi,audio/sp-midi,audio/spmidi,               \
                              audio/x-midi,audio/mid,audio/wav,audio/x-wav,audio/vm,text/x-imelody,audio/basic,  \
                              audio/basic,audio/x-ulaw,audio/x-aiff"                                             \
","                                                                                                              \
DEF_AAC_DECODE                                                                                                   \
","                                                                                                              \
DEF_AMRWB_DECODE                                                                                                 \
","                                                                                                              \
DEF_DAF_DECODE                                                                                                   \
","                                                                                                              \
DEF_MP4_CODEC_AND_AAC_DECODE                                                                                     \
","                                                                                                              \
DEF_WMA_DECODE                                                                                                   \
","                                                                                                              \
DEF_MMF_DECODE                                                                                                   \
","                                                                                                              \
DEF_MP2_CODEC_AUDIO                                                                                              \
","                                                                                                              \
DEF_MP4_CODEC_AUDIO                                                                                              \
","                                                                                                              \
DEF_ODF_SUPPORT

#if defined(MJPG_SUPPORT)
#define DEF_MJPG_SUPPORT "video/x-msvideo,video/avi,"
#else 
#define DEF_MJPG_SUPPORT ","
#endif 

#if defined(MP4_CODEC)
#define DEF_MP4_CODEC_VIDEO "video/3gpp,video/3gp,application/.3gp,video/mp4,video/mpeg,video/mpg,video/3gpp2,"
#else 
#define DEF_MP4_CODEC_VIDEO ","
#endif 

#define JMMS_VIDEO_TYPES DEF_MJPG_SUPPORT               \
","                                                     \
DEF_MP4_CODEC_VIDEO                                     \
","                                                     \
DEF_ODF_SUPPORT

#if defined(__MMI_EBOOK_READER__)
#define DEF_MMI_EBOOK_READER_ATT "text/plain,application/text,application/x-pilot-pdb,chemical/x-pdb,"
#else 
#define DEF_MMI_EBOOK_READER_ATT ","
#endif 

#if defined(WAP_SUPPORT)
#define DEF_WAP_SUPPORT_ATT "text/html,text/vnd.wap.wml,"
#else 
#define DEF_WAP_SUPPORT_ATT ","
#endif 

#if defined(__DRM_SUPPORT__)
#if defined(__DRM_ODF_SUPPORT__)
#define DEF_DRM_SUPPORT "application/vnd.oma.drm.content,application/vnd.oma.drm.message,application/vnd.oma.drm.rights+wbxml,application/vnd.oma.drm.rights+xml,application/vnd.oma.drm.dcf,"
#else 
#define DEF_DRM_SUPPORT "application/vnd.oma.drm.content,application/vnd.oma.drm.message,application/vnd.oma.drm.rights+wbxml,application/vnd.oma.drm.rights+xml,"
#endif 
#else /* defined(__DRM_SUPPORT__) */ 
#define DEF_DRM_SUPPORT ","
#endif /* defined(__DRM_SUPPORT__) */ 

#if defined(__J2ME__)
#define DEF_J2ME "application/java-archive,application/java-vm,text/vnd.sun.j2me.app-descriptor,"
#else 
#define DEF_J2ME ","
#endif 

#if defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__)
#define DEF_MMI_DOWNLOADABLE_THEMES_SUPPORT "mtk/med.thm,"
#else 
#define DEF_MMI_DOWNLOADABLE_THEMES_SUPPORT ","
#endif 

#if defined(__MMI_OMA_DD_DOWNLOAD__)
#define DEF_MMI_OMA_DD_DOWNLOAD "application/vnd.oma.dd+xml,"
#else 
#define DEF_MMI_OMA_DD_DOWNLOAD ","
#endif 

#if defined(__MMI_VCALENDAR__)
#define DEF_MMI_VCALENDAR "text/x-vcalendar,application/hbs-vcs,text/calendar,"
#else 
#define DEF_MMI_VCALENDAR ","
#endif 

#if defined(__MMI_VCARD__)
#define DEF_MMI_VCARD "text/x-vcard,application/vcard,"
#else 
#define DEF_MMI_VCARD ","
#endif 

#if defined(STREAM_SUPPORT) || defined(__VOIP__) || defined(__POC__)
#define DEF_STREAM_SUPPORT_OR_VOIP_OR_POC "application/sdp,"
#else 
#define DEF_STREAM_SUPPORT_OR_VOIP_OR_POC ","
#endif 

#if defined(MMS_SUPPORT)
#define DEF_MMS_SUPPORT "application/smil,multipart/mixed,"
#else 
#define DEF_MMS_SUPPORT ","
#endif 

#ifdef __IMPS__
#define DEF_IMPS "application/vnd.wv.csp.xml,application/vnd.wv.csp.wbxml,application/vnd.wv.csp.cir,application/vnd.wv.csp.sms,"
#else 
#define DEF_IMPS ","
#endif 

#ifdef M3D_MMI_SUPPORT
#define DEF_M3D_MMI_SUPPORT "application/vnd.mtk.m3d,"
#else 
#define DEF_M3D_MMI_SUPPORT ","
#endif 

#ifdef SWFLASH_CHAOTEX
#define DEF_SWFLASH_CHAOTEX "application/Chaotex-cim,application/Chaotex-wfd,"
#else 
#define DEF_SWFLASH_CHAOTEX ","
#endif 

#ifdef __MMI_BARCODEREADER__
#define DEF_MMI_BARCODEREADER "application/mbc,"
#else 
#define DEF_MMI_BARCODEREADER ","
#endif 

#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
#define DEF_MMI_AUDIO_PLAYER_LYRIC_DISPLAY "application/vnd.mtk.lrc,"
#else 
#define DEF_MMI_AUDIO_PLAYER_LYRIC_DISPLAY ","
#endif 

#define JMMS_ATTACHMENT_TYPES "image/bmp,image/x-MS-bmp,image/gif,audio/amr,audio/imelody,audio/mid,audio/midi,audio/sp-midi,audio/spmidi,               \
                              audio/x-midi,audio/mid,audio/wav,audio/x-wav,audio/vm,text/x-imelody,audio/basic,                                          \
                              audio/basic,audio/x-ulaw,audio/x-aiff,image/vnd.wap.wbmp"                                                                  \
","                                                                                                                                                      \
DEF_JPG_DECODE                                                                                                                                           \
","                                                                                                                                                      \
DEF_USE_HW_PNG_DECODER_V1_OR_USE_SW_PNG_DECODER                                                                                                          \
","                                                                                                                                                      \
DEF_SVG_SUPPORT                                                                                                                                          \
","                                                                                                                                                      \
DEF_MMI_EBOOK_READER_ATT                                                                                                                                 \
","                                                                                                                                                      \
DEF_WAP_SUPPORT_ATT                                                                                                                                      \
","                                                                                                                                                      \
DEF_AAC_DECODE                                                                                                                                           \
","                                                                                                                                                      \
DEF_AMRWB_DECODE                                                                                                                                         \
","                                                                                                                                                      \
DEF_DAF_DECODE                                                                                                                                           \
","                                                                                                                                                      \
DEF_MP4_CODEC_AND_AAC_DECODE                                                                                                                             \
","                                                                                                                                                      \
DEF_WMA_DECODE                                                                                                                                           \
","                                                                                                                                                      \
DEF_MMF_DECODE                                                                                                                                           \
","                                                                                                                                                      \
DEF_MP4_CODEC_AUDIO                                                                                                                                      \
","                                                                                                                                                      \
DEF_MJPG_SUPPORT                                                                                                                                         \
","                                                                                                                                                      \
DEF_MP4_CODEC_VIDEO                                                                                                                                      \
","                                                                                                                                                      \
DEF_DRM_SUPPORT                                                                                                                                          \
","                                                                                                                                                      \
DEF_J2ME                                                                                                                                                 \
","                                                                                                                                                      \
DEF_MMI_DOWNLOADABLE_THEMES_SUPPORT                                                                                                                      \
","                                                                                                                                                      \
DEF_MMI_OMA_DD_DOWNLOAD                                                                                                                                  \
","                                                                                                                                                      \
DEF_MMI_VCALENDAR                                                                                                                                        \
","                                                                                                                                                      \
DEF_MMI_VCARD                                                                                                                                            \
","                                                                                                                                                      \
DEF_STREAM_SUPPORT_OR_VOIP_OR_POC                                                                                                                        \
","                                                                                                                                                      \
DEF_MMS_SUPPORT                                                                                                                                          \
","                                                                                                                                                      \
DEF_IMPS                                                                                                                                                 \
","                                                                                                                                                      \
DEF_M3D_MMI_SUPPORT                                                                                                                                      \
","                                                                                                                                                      \
DEF_SWFLASH_CHAOTEX                                                                                                                                      \
","                                                                                                                                                      \
DEF_MMI_BARCODEREADER                                                                                                                                    \
","                                                                                                                                                      \
DEF_MP2_CODEC_AUDIO                                                                                                                                      \
","                                                                                                                                                      \
DEF_MMI_AUDIO_PLAYER_LYRIC_DISPLAY

#endif /* defined (JATAAYU_SUPPORT) && defined (MMS_SUPPORT) && defined (__UNIFIED_COMPOSER_SUPPORT__) */ 
#endif /* __MMI_UC_JMMS_GDEFS_H */ 

