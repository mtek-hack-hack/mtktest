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
 *   app_mine.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file implements common interfaces for mine type.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "fat_fs.h"
#include "app_mine.h"
#include "app_str.h"
#include "MMI_features.h"

/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/
const kal_char * const g_applib_mime_string[MIME_TYPE_MAX_NUM] = 
{
  "", "text", "image", "audio", "video", "application", "message", "multipart", ""
};

const applib_mime_type_struct g_applib_mime_tbl[] = 
{
    {"audio/amr"                               ,"amr"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_AMR                  , 0},
    {"audio/x-amr"                             ,"amr"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_AMR                  , 0},
    {"audio/imelody"                           ,"imy"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_IMELODY              , 0},
    {"audio/mid"                               ,"mid"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_MID                  , 0},
    {"audio/midi"                              ,"mid"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_MID                 , 0},
    {"audio/sp-midi"                           ,"mid"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_SPMIDI               , 0},
    {"audio/spmidi"                            ,"mid"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_SPMIDI             , 0},
    {"audio/x-midi"                            ,"mid"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_MID                , 0},
    {"audio/mid"                               ,"midi"     ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_MID                  , 0},
    {"audio/wav"                               ,"wav"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_WAV                  , 0},
    {"audio/x-wav"                             ,"wav"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_WAV                 , 0},
    {"audio/vm"                                ,"vm"       ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_VM                   , 0},
    {"image/bmp"                               ,"bmp"      ,MIME_TYPE_IMAGE      , MIME_SUBTYPE_BMP                  , 0},
    {"image/x-MS-bmp"                          ,"bmp"      ,MIME_TYPE_IMAGE      , MIME_SUBTYPE_BMP                  , 0},
    {"image/gif"                               ,"gif"      ,MIME_TYPE_IMAGE      , MIME_SUBTYPE_GIF                  , 0},
    {"image/vnd.wap.wbmp"                      ,"wbmp"     ,MIME_TYPE_IMAGE      , MIME_SUBTYPE_WBMP                 , 0},
    {"image/vnd.wap.wbmp"                      ,"wbm"      ,MIME_TYPE_IMAGE      , MIME_SUBTYPE_WBMP                 , 0},
    {"text/x-imelody"                          ,"imy"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_IMELODY             , 0},
#if defined(AU_DECODE)
    {"audio/basic"                             ,"au"       ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_AU                   , 0},
    {"audio/basic"                             ,"snd"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_SND                  , 0},
    {"audio/x-ulaw"                            ,"au"       ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_AU_XULAW             , 0},
#endif
#if defined(AIFF_DECODE)
    {"audio/x-aiff"                            ,"aiff"      ,MIME_TYPE_AUDIO     , MIME_SUBTYPE_AIFF                 , 0},
    {"audio/x-aiff"                            ,"aif"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_AIF                  , 0},
    {"audio/x-aiff"                            ,"aifc"     ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_AIFC                 , 0},
    {"audio/aiff"                              ,"aiff"     ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_AIFF                 , 0},
    {"audio/aiff"                              ,"aif"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_AIF                  , 0},
    {"audio/aiff"                              ,"aifc"     ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_AIFC                 , 0},
#endif
#if defined(__DRM_SUPPORT__)
    {"application/vnd.oma.drm.content"         ,"dcf"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_DRM_CONTENT          , 0},
    {"application/vnd.oma.drm.message"         ,"dm"       ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_DRM_MESSAGE          , 0},
    {"application/vnd.oma.drm.rights+wbxml"    ,"drc"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_DRM_RIGHTS_WBXML     , 0},
    {"application/vnd.oma.drm.rights+xml"      ,"dr"       ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_DRM_RIGHTS_XML       , 0},
#ifdef __DRM_V02__    
    {"application/vnd.oma.drm.dcf"             ,"odf"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_DRM_CONTENT_V2       , 0},
    {"application/vnd.oma.drm.roap-pdu+xml"    ,"ort"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_ROAP_PDU             , 0},
    {"application/vnd.oma.drm.roap-trigger+xml","ort"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_ROAP_TRIGGER         , 0},
    {"application/vnd.oma.drm.ro+xml"          ,"oro"      ,MIME_TYPE_APPLICATION, MIMI_SUBTYPE_PROTECTED_RO         , 0},
#endif
#endif
#if defined(__J2ME__)
    {"application/java-archive"                ,"jar"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_JAR                  , 0},
    {"application/java-vm"                     ,"class"    ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_JVM                  , 0},
    {"text/vnd.sun.j2me.app-descriptor"        ,"jad"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_JAD                  , 0},
#endif
#if defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__)
    {"mtk/med.thm"                             ,"med"         ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_THEME                , 0},
#endif
#if defined(__MMI_EBOOK_READER__)
    {"text/plain"                              ,"txt"      ,MIME_TYPE_TEXT       , MIME_SUBTYPE_PLAIN                , 0},
    {"application/x-pilot-pdb"                 ,"pdb"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_PDB                  , 0},
#endif
#if defined(__MMI_OMA_DD_DOWNLOAD__)
    {"application/vnd.oma.dd+xml"              ,"dd"       ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_OMA_DD               , 0},
    {"application/vnd.oma.dd2+xml"             ,"dd2"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_OMA_DD2              , 0},
#endif
#if defined(__MMI_VCALENDAR__)
    {"text/x-vcalendar"                        ,"vcs"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_XVCALENDAR           , 0},
    {"application/hbs-vcs"                     ,"vcs"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_HBSVCS               , 0},
    {"text/calendar"                           ,"vcs"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_CALENDAR             , 0},
#endif
#if defined(__MMI_VCARD__)
    {"text/x-vcard"                            ,"vcf"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_XVCARD               , 0},
    {"application/vcard"                       ,"vcf"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_VCARD                , 0},
#endif
#if defined(__MMI_VBOOKMARK__)
    {"text/x-vbookmark"                        ,"vbm"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_XVBOOKMARK           , 0},
    {"text/plain"                              ,"vbm"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_XVBOOKMARK           , 0},
    {"text/x-vbookmark"                        ,"url"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_XVBOOKMARK           , 0},
    {"text/plain"                              ,"url"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_XVBOOKMARK           , 0},
#endif
#if defined(__POC__)
    {"application/vnd.poc.refer-to"            ,""         ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_REFERTO              , 0},
#endif
#if defined(STREAM_SUPPORT)
    {"application/sdp"                         ,"sdp"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_SDP                  , 0},
#endif
#if defined(AAC_DECODE)
    {"audio/aac"                               ,"aac"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_AAC                  , 0},
    {"audio/x-aac"                             ,"aac"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_AAC                 , 0},
#endif
#if defined(AMRWB_DECODE)
    {"audio/amr-wb"                            ,"awb"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_AWB                  , 0},
#endif
#if defined(DAF_DECODE)
    {"audio/mp3"                               ,"mp3"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_AUDIO_MP3            , 0},
    {"audio/mpeg"                              ,"mp3"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_AUDIO_MP3           , 0},
    {"audio/x-mpeg"                            ,"mp3"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_AUDIO_MP3           , 0},
    {"audio/mpg"                               ,"mp3"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_AUDIO_MP3            , 0},
    {"audio/mpg3"                              ,"mp3"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_AUDIO_MP3           , 0},
    {"audio/x-mp3"                             ,"mp3"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_AUDIO_MP3           , 0},
    {"audio/mpeg3"                             ,"mp3"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_AUDIO_MP3            , 0},
#endif
#if defined(JPG_DECODE)
    {"image/jpeg"                              ,"jpg"      ,MIME_TYPE_IMAGE      , MIME_SUBTYPE_JPG                 , 0},
    {"image/jpg"                               ,"jpg"      ,MIME_TYPE_IMAGE      , MIME_SUBTYPE_JPG                  , 0},
    {"image/jpeg"                              ,"jpeg"     ,MIME_TYPE_IMAGE      , MIME_SUBTYPE_JPEG                 , 0},
#endif
#if defined(MJPG_SUPPORT)
    {"video/x-msvideo"                         ,"avi"      ,MIME_TYPE_VIDEO      , MIME_SUBTYPE_AVI                  , 0},
    {"video/avi"                               ,"avi"      ,MIME_TYPE_VIDEO      , MIME_SUBTYPE_AVI                  , 0},
#endif
#if defined(YAMAHA_MA3)
    {"application/vnd.smaf"                    ,"mmf"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_VSMAF                , 0},
    {"application/x-smaf"                      ,"mmf"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_XSMAF                , 0},
#endif
#if defined(MMS_SUPPORT)
    {"application/smil"                        ,"smil"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_SMIL                 , 0},
    {"multipart/mixed"                         ,""         ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_MIXED                , 0},
#endif
#if defined(MP4_CODEC) 
    {"video/3gpp"                              ,"3gp"      ,MIME_TYPE_VIDEO      , MIME_SUBTYPE_3GPP_VIDEO           , 0},
    {"video/3gp"                               ,"3gp"      ,MIME_TYPE_VIDEO      , MIME_SUBTYPE_3GPP_VIDEO           , 0},
    {"application/.3gp"                        ,"3gp"      ,MIME_TYPE_VIDEO      , MIME_SUBTYPE_3GPP_VIDEO           , 0},
    {"video/mp4"                               ,"mp4"      ,MIME_TYPE_VIDEO      , MIME_SUBTYPE_MP4                  , 0},
    {"video/mpeg"                              ,"mpg"      ,MIME_TYPE_VIDEO      , MIME_SUBTYPE_MPEG                 , 0},
    {"video/mpg"                               ,"mpg"      ,MIME_TYPE_VIDEO      , MIME_SUBTYPE_MPG                  , 0},
    {"video/3gpp2"                             ,"3g2"      ,MIME_TYPE_VIDEO      , MIME_SUBTYPE_3GPP2_VIDEO          , 0},
#endif
#if defined(__SF_MP4_SUPPORT__)
    {"video/3gpp"                              ,"3gp"      ,MIME_TYPE_VIDEO      , MIME_SUBTYPE_3GPP_VIDEO           , 0},
    {"video/3gp"                               ,"3gp"      ,MIME_TYPE_VIDEO      , MIME_SUBTYPE_3GPP_VIDEO           , 0},
    {"application/.3gp"                        ,"3gp"      ,MIME_TYPE_VIDEO      , MIME_SUBTYPE_3GPP_VIDEO           , 0},
    {"video/mp4"                               ,"mp4"      ,MIME_TYPE_VIDEO      , MIME_SUBTYPE_MP4                  , 0},
    {"video/mpeg"                              ,"mpg"      ,MIME_TYPE_VIDEO      , MIME_SUBTYPE_MPEG                 , 0},
    {"video/mpg"                               ,"mpg"      ,MIME_TYPE_VIDEO      , MIME_SUBTYPE_MPG                  , 0},
    {"video/3gpp2"                             ,"3g2"      ,MIME_TYPE_VIDEO      , MIME_SUBTYPE_3GPP2_VIDEO          , 0},
#endif
#if defined(AAC_DECODE)
    {"audio/m4a"                               ,"m4a"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_M4A                  , 0},
    {"audio/x-m4a"                             ,"m4a"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_M4A                 , 0},
#endif
#if defined(__MMI_PURE_AUDIO__)
    {"audio/3gpp"                              ,"3gp"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_3GPP_AUDIO           , 0},
    {"audio/3gp"                               ,"3gp"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_3GPP_AUDIO            , 0},
    {"audio/mp4"                               ,"mp4"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_MP4_AUDIO            , 0},    
#endif

/* temp solution here, framework team will provide new header file independent to MMI*/
#if defined(USE_HW_PNG_DECODER_V1) || defined(USE_SW_PNG_DECODER)
    {"image/png"                               ,"png"      ,MIME_TYPE_IMAGE      , MIME_SUBTYPE_PNG                  , 0},
#endif
#if defined(SVG_SUPPORT)
    {"image/svg+xml"                           ,"svg"      ,MIME_TYPE_IMAGE      , MIME_SUBTYPE_SVG                  , 0},
#endif
#if defined(WAP_SUPPORT)
    {"application/x-x509-ca-cert"              ,"cer"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_CA_CERT              , 0},
    {"application/x-x509-user-cert"            ,"usr"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_USR_CERT             , 0},
#ifdef __CERTMAN_SUPPORT__
    {"application/x-x509-ca-cert"              ,"der"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_CA_CERT              , 0},
    {"application/x-x509-ca-cert"              ,"crt"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_CA_CERT              , 0},
    {"application/x-x509-ca-cert"              ,"pem"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_CA_CERT              , 0},
    {"application/x-x509-user-cert"            ,"cer"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_USR_CERT             , 0},
    {"application/x-x509-user-cert"            ,"der"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_USR_CERT             , 0},
    {"application/x-x509-user-cert"            ,"crt"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_USR_CERT             , 0},
    {"application/x-x509-user-cert"            ,"pem"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_USR_CERT             , 0},
    {"application/x-pkcs7-certificates"        ,"p7b"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_PKCS7_CERT           , 0},
    {"application/x-pkcs7-certificates"        ,"spc"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_PKCS7_CERT           , 0},
    {"application/x-pkcs7-certificates"        ,"pem"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_PKCS7_CERT           , 0},
    {"application/x-pkcs12"                    ,"p12"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_PKCS12_CERT          , 0},
    {"application/x-pkcs12"                    ,"pfx"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_PKCS12_CERT          , 0},
#endif
    {"application/vnd.wap.connectivity-wbxml"  ,"owbxml"   ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_OMA_PROV_WBXML       , 0},
    {"application/x-wap-prov.browser-bookmarks","nbmk"     ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_NOKIA_PROV_BOOKMARKS , 0},
    {"application/x-wap-prov.browser-settings" ,"nbrw"     ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_NOKIA_PROV_BROWSER   , 0},
    {"text/css"                                ,"css"      ,MIME_TYPE_TEXT       , MIME_SUBTYPE_CSS                  , 0},
    {"text/html"                               ,"html"     ,MIME_TYPE_TEXT       , MIME_SUBTYPE_HTML                 , 0},
    {"text/vnd.wap.connectivity-xml"           ,"otext"    ,MIME_TYPE_TEXT       , MIME_SUBTYPE_OMA_PROV_XML         , 0},
    {"text/vnd.wap.wml"                        ,"wml"      ,MIME_TYPE_TEXT       , MIME_SUBTYPE_WML                  , 0},
    {"text/vnd.wap.wmlscript"                  ,"wmls"     ,MIME_TYPE_TEXT       , MIME_SUBTYPE_WMLSCRIPT            , 0},
    {"application/vnd.wap.wmlc"                ,"wmlc"     ,MIME_TYPE_TEXT       , MIME_SUBTYPE_WMLC                 , 0},
    {"application/vnd.wap.wmlscriptc"          ,"wmlsc"    ,MIME_TYPE_TEXT       , MIME_SUBTYPE_WMLSC                , 0},
#endif
#if defined(WMA_DECODE)
    {"audio/wma"                               ,"wma"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_WMA                  , 0},
    {"audio/x-ms-wma"                          ,"wma"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_WMA                  , 0},
#endif
#ifdef __IMPS__
    {"application/vnd.wv.csp.xml,", "cxml", MIME_TYPE_APPLICATION, MIME_SUBTYPE_CSP_XML, 0},
    {"application/vnd.wv.csp.wbxml", "cwbxml", MIME_TYPE_APPLICATION, MIME_SUBTYPE_CSP_WBXML, 0},
    {"application/vnd.wv.csp.cir", "ccir", MIME_TYPE_APPLICATION, MIME_SUBTYPE_CSP_CIR, 0},
    {"application/vnd.wv.csp.sms", "csms", MIME_TYPE_APPLICATION, MIME_SUBTYPE_CSP_SMS, 0},
#endif
#ifdef M3D_MMI_SUPPORT
    {"application/vnd.mtk.m3d", "m3d",     MIME_TYPE_APPLICATION, MIME_SUBTYPE_M3D, 0},
#endif
#ifdef SWFLASH_CHAOTEX
    {"application/Chaotex-cim", "cim", MIME_TYPE_APPLICATION, MIME_SUBTYPE_CIM, 0},
    {"application/Chaotex-wfd", "wfd", MIME_TYPE_APPLICATION, MIME_SUBTYPE_WFD, 0},
    {"application/vnd.mtk.cmp",  "cmp",  MIME_TYPE_APPLICATION, MIME_SUBTYPE_VIS, 0},
#endif
#ifdef __MMI_BARCODEREADER__
    {"application/vnd.mtk.mbc", "mbc", MIME_TYPE_APPLICATION, MIME_SUBTYPE_MBC, 0},
#endif
#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
    {"application/vnd.mtk.lrc", "lrc", MIME_TYPE_APPLICATION, MIME_SUBTYPE_LRC, 0},
#endif
#ifdef SYNCML_DM_SUPPORT
    {"application/vnd.syncml.dm+wbxml", "omadm", MIME_TYPE_APPLICATION, MIME_SUBTYPE_DM_WBXML, 0},
    {"application/vnd.syncml.dm+xml", "omadm", MIME_TYPE_APPLICATION, MIME_SUBTYPE_DM_XML, 0},
    {"application/vnd.syncml.notification", "omadm", MIME_TYPE_APPLICATION, MIME_SUBTYPE_DM_NOTIFICATION, 0},
#endif
#if defined(MUSICAM_DECODE)
    {"audio/mp2", "mp2", MIME_TYPE_AUDIO, MIME_SUBTYPE_AUDIO_MP2, 0},
#endif
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
    {"application/vnd.syncml.ds.notification", "omads", MIME_TYPE_APPLICATION, MIME_SUBTYPE_DS_NOTIFICATION, 0},
#endif
#ifdef LANGLN_DIGIDEA
    {"text/x-component", "dzd", MIME_TYPE_TEXT, MIME_SUBTYPE_DZD, 0},
    {"application/dzd", "dzdx", MIME_TYPE_APPLICATION, MIME_SUBTYPE_DZDX, 0},
#endif
#ifdef SWFLASH_NEOMTEL
    {"image/vnd.ziyitong.zdd", "zdd", MIME_TYPE_APPLICATION, MIME_SUBTYPE_ZDD, 0},
    {"application/vnd.mtk.vis",  "vis",  MIME_TYPE_APPLICATION, MIME_SUBTYPE_VIS, 0},
    {"application/vnd.mtk.ivis", "ivis", MIME_TYPE_APPLICATION, MIME_SUBTYPE_VIS, 0},
    {"application/vnd.mtk.kvis", "kvis", MIME_TYPE_APPLICATION, MIME_SUBTYPE_VIS, 0},
    {"application/vnd.mtk.mvis", "mvis", MIME_TYPE_APPLICATION, MIME_SUBTYPE_VIS, 0},
#endif
#ifdef __MMI_MESSAGES_EMS__
    {"application/vnd.mtk.ems", "ems", MIME_TYPE_APPLICATION, MIME_SUBTYPE_EMS, 0},
    {"application/vnd.mtk.anm", "anm", MIME_TYPE_APPLICATION, MIME_SUBTYPE_ANM, 0},
#endif    
    {"multipart/related", "", MIME_TYPE_MULTIPART, MIME_SUBTYPE_RELATED, 0}
};

const kal_int32 g_applib_mime_tbl_size = sizeof(g_applib_mime_tbl) / sizeof(applib_mime_type_struct);


/***************************************************************************** 
* Local Function
*****************************************************************************/

/***************************************************************************** 
* Global Variable
*****************************************************************************/

/***************************************************************************** 
* Global Function
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mime_tolower
 * DESCRIPTION
 *  Convert a charcater to lower case
 * PARAMETERS
 *  ch      [IN]        Charcater to be converted
 * RETURNS
 *  lower case character
 *****************************************************************************/
kal_uint8 mime_tolower(kal_uint8 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ch >= 'A' && ch <= 'Z')
    {
        return (kal_uint8) (ch + ('a' - 'A'));
    }
    return ch;
}


/*****************************************************************************
 * FUNCTION
 *  mime_strnicmp
 * DESCRIPTION
 *  Compare two string without case with maximum length
 * PARAMETERS
 *  src         [IN]        String pointer to be compared
 *  dest        [IN]        String pointer to be compared
 *  maxlen      [IN]        Lengh to be compared
 * RETURNS
 *  Ture if two string is identical, otherwise, 0
 *****************************************************************************/
kal_uint8 mime_strnicmp(kal_char *src, kal_char *dest, kal_int32 maxlen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 ch1, ch2;
    kal_char *s1, *s2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    s1 = src;
    s2 = dest;

    while (maxlen-- > 0)
    {
        ch1 = mime_tolower((kal_uint8) * s1++);
        ch2 = mime_tolower((kal_uint8) * s2++);
        if (ch1 != ch2)
        {
            return 1;
        }
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mime_stricmp
 * DESCRIPTION
 *  Compare two strings without case
 * PARAMETERS
 *  src         [IN]        String pointer to be compared
 *  dest        [IN]        String pointer to be compared
 * RETURNS
 *  Ture if two string is identical, otherwise, 0
 *****************************************************************************/
kal_int8 mime_stricmp(kal_char *src, kal_char *dest)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 len_src = strlen(src);
    kal_int32 len_dest = strlen(dest);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (len_src != len_dest)
    {
        return 1;
    }
    else
    {
        return mime_strnicmp(src, dest, len_src);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mime_string_start_with
 * DESCRIPTION
 *  Search if str2 is start with srt1
 *  str1: audio/amr-wb   str2: audio/amr-wb;case1....  => MATCH
 *  str1: audio/amr      str2: audio/amr-wb;case2....  => NOT MATCH
 * PARAMETERS
 *  str1        [IN]        String pointer to be compared
 *  str2        [IN]        String pointer to be find
 * RETURNS
 *  Ture if one string exist in another string, otherwise, 0
 *****************************************************************************/
static kal_bool mime_string_start_with(kal_char *str1, kal_char *str2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 str1_len;
    kal_int32 str2_len;
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (str1 == NULL || str2 == NULL)
    {
        return KAL_FALSE;
    }

    str1_len = strlen(str1);
    str2_len = strlen(str2);

    if (str1_len > str2_len)
    {
        return KAL_FALSE;
    }
    for (i = 0; i < str1_len; i++)
    {
        if (mime_tolower((kal_uint8) str1[i]) != mime_tolower((kal_uint8) str2[i]))
        {
            return KAL_FALSE;
        }
    }

    if(str1_len < str2_len)
    {
        if( str2[i]!= ';' && str2[i]!=',')
        {
            return KAL_FALSE;
        }
    }
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mime_type_look_up
 * DESCRIPTION
 *  Look up mime-type table. The user can pass some of search criteria for searching
 * PARAMETERS
 *  mime_string         [IN]        String of mime type, NULL if this element is not provided.
 *  file_ext            [IN]        File extension,   NULL if this element is not provided.
 *  mime_type           [IN]        Mime type, 0XFF if this element is not provided.
 *  mime_subtype        [IN]        Mime subtype, 0XFF if this element is not provided
 * RETURNS
 *  pointer to the result element. NULL if not found.
 *****************************************************************************/
applib_mime_type_struct *mime_type_look_up_ext(kal_char *mime_string, kal_char *mime_type_string, kal_char *mime_subtype_string, kal_char *file_ext, applib_mime_type_enum mime_type, applib_mime_subtype_enum mime_subtype)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;
    kal_int32 tbl_size = sizeof(g_applib_mime_tbl) / sizeof(applib_mime_type_struct);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mime_type == 0 && mime_subtype == 0 && file_ext == NULL && 
    mime_string == NULL && mime_type_string == NULL && mime_subtype_string == NULL)
    {
        return NULL;
    }

    for (i = 0; i < tbl_size; i++)
    {
        if (mime_type != 0)
            if (g_applib_mime_tbl[i].mime_type != mime_type)
            {
                continue;
            }

        if (mime_subtype != 0)
            if (g_applib_mime_tbl[i].mime_subtype != mime_subtype)
            {
                continue;
            }

        if (mime_string != NULL)
            if (mime_string_start_with( g_applib_mime_tbl[i].mime_string, mime_string) == KAL_FALSE)
            {
                continue;
            }

        if (file_ext != NULL)
        {
            if (mime_stricmp(file_ext, g_applib_mime_tbl[i].file_ext))
            continue;         
        }
        
        if(mime_type_string != NULL)
        {
            kal_char *s;
            
            s = strchr(g_applib_mime_tbl[i].mime_string, '/');
            
            ASSERT(s);
            
            if(mime_strnicmp(mime_type_string, g_applib_mime_tbl[i].mime_string, s-g_applib_mime_tbl[i].mime_string))
            continue;
        }
        
        if(mime_subtype_string != NULL)
        {
            kal_char *s;
            
            s = strchr(g_applib_mime_tbl[i].mime_string, '/');
            
            ASSERT(s);
            
            if(mime_stricmp(mime_subtype_string, s+1))
                continue;
        }

        break;
    }

    if (i == tbl_size)
    {
        return NULL;
    }
    else
    {
        return (applib_mime_type_struct*) & g_applib_mime_tbl[i];
    }
} /* end of mime_type_look_up_ext */

/*****************************************************************************
 * FUNCTION
 *  mime_type_look_up
 * DESCRIPTION
 *  Look up mime-type table. The user can pass some of search criteria for searching
 * PARAMETERS
 *  mime_string         [IN]        String of mime type, NULL if this element is not provided.
 *  file_ext            [IN]        File extension,   NULL if this element is not provided.
 *  mime_type           [IN]        Mime type, 0XFF if this element is not provided.
 *  mime_subtype        [IN]        Mime subtype, 0XFF if this element is not provided
 * RETURNS
 *  pointer to the result element. NULL if not found.
 *****************************************************************************/
applib_mime_type_struct *mime_type_look_up(
                            kal_char *mime_string,
                            kal_char *file_ext,
                            applib_mime_type_enum mime_type,
                            applib_mime_subtype_enum mime_subtype)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mime_type_look_up_ext(mime_string, NULL, NULL, file_ext, mime_type, mime_subtype);
}

/*****************************************************************************
* FUNCTION
*  mmi_da_get_extension
* DESCRIPTION
*  get extension file name of a file path
* PARAMETERS
*  file_path   IN  The file path
* RETURNS
*  Return the pointer where the extension file name start.
*   Return NULL if the file_path do not have extension file name.
*****************************************************************************/
kal_wchar *mime_get_extension(kal_wchar *file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 length, i;
    kal_wchar *ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    length = kal_wstrlen(file_path);

    /* search from tail until "." */
    for (i = length - 1; i >= 0; i--)
    {
        if (file_path[i] == '.')
        {
            return &file_path[i + 1];
        }
    }
    return ptr;
}

/*****************************************************************************
 * FUNCTION
 *  mime_get_file_type
 * DESCRIPTION
 *  Result of table look-up. NULL if no matched column found.
 * PARAMETERS
 *  file_path       [IN]        Path of file to be looked up
 * RETURNS
 *  pointer to the result element. NULL if not found.
 *****************************************************************************/
applib_mime_type_struct *mime_get_file_type(kal_wchar *file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mime_type_struct *mime;
    kal_wchar *ptr;
    kal_char file_ext[33] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ptr = mime_get_extension(file_path);

    if( ptr )
    {
        app_unicode_n_to_ansii((kal_int8*)file_ext,(kal_int8*) ptr, 32*2);

        mime = mime_type_look_up(NULL, file_ext, 0, 0);
    }
    else
    {
        mime = NULL;
    }

    return mime;
}

applib_mime_type_enum mime_get_mime_type(kal_char *mime_type)
{
    kal_uint8 i;
    
    for (i = 0;(i <= MIME_TYPE_MAX_NUM) && g_applib_mime_string[i] && mime_stricmp(mime_type, (kal_char*)g_applib_mime_string[i]); i++);

    if (i <= MIME_TYPE_MAX_NUM)
    {
        return (applib_mime_type_enum) i;
    }

    return MIME_TYPE_UNKNOWN;
}

const applib_mime_type_struct* mime_get_table(void)
{
    return g_applib_mime_tbl;
}

kal_int32 mime_get_table_size(void)
{
    return g_applib_mime_tbl_size;
}


kal_int32 mime_type_look_up_mul(kal_char** ext_array, kal_int32 array_count, app_mime_mem_alloc_funcptr_type alloc_fn,
                                applib_mime_type_struct*** result_table, kal_int32* result_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 count = 0, i, j, k;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(result_table && result_count && alloc_fn);
    ASSERT(!(*result_table));

    for(i=0;i<array_count;i++)
    {
        for(j=0;j<g_applib_mime_tbl_size;j++)
        {
            if (mime_stricmp(ext_array[i], g_applib_mime_tbl[j].file_ext) == 0)
                count++;
        }
    }

    *result_table = (applib_mime_type_struct**)alloc_fn(sizeof(applib_mime_type_struct*) * count);
    if(!(*result_table))
    {
        *result_count = -1;
        return -1;
    }
    
    k = 0;
    for(i=0;i<array_count;i++)
    {
        for(j=0;j<g_applib_mime_tbl_size;j++)
        {
            if (mime_stricmp(ext_array[i], g_applib_mime_tbl[j].file_ext) == 0)
            {
                (*result_table)[k] = (applib_mime_type_struct*)&(g_applib_mime_tbl[j]);
                k++;
            }
        }
    }

    *result_count = count;
    return count;

}

