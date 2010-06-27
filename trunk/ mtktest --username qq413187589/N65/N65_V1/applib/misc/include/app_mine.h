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

/*******************************************************************************
 * Filename:
 * ---------
 *   app_mine.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file defines structure, contant, and function prototypes for mine type interfaces.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef __APP_MINE_H__
#define __APP_MINE_H__

 /***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/* mime type */
typedef enum
{
    MIME_TYPE_NONE = 0,
    MIME_TYPE_TEXT,
    MIME_TYPE_IMAGE,
    MIME_TYPE_AUDIO,
    MIME_TYPE_VIDEO,
    MIME_TYPE_APPLICATION,
    MIME_TYPE_MESSAGE,
    MIME_TYPE_MULTIPART,
    MIME_TYPE_UNKNOWN,
    MIME_TYPE_MAX_NUM
} applib_mime_type_enum;

typedef enum
{
    MIME_SUBTYPE_NONE = 0,
    MIME_SUBTYPE_AMR                  ,         /*audio/amr                                  */
    MIME_SUBTYPE_IMELODY              ,         /*audio/imelody                              */
    MIME_SUBTYPE_MID                  ,         /*audio/mid                                  */
    MIME_SUBTYPE_MIDI                 ,         /*audio/midi                                 */
    MIME_SUBTYPE_SPMIDI               ,         /*audio/sp-midi                              */
    MIME_SUBTYPE_SPMIDI_1             ,
    MIME_SUBTYPE_WAV                  ,         /*audio/wav                                  */
    MIME_SUBTYPE_VM                   ,         /*audio/vm                                   */
    MIME_SUBTYPE_XMIDI                ,         /*audio/x-midi                               */
    MIME_SUBTYPE_XWAV                 ,         /*audio/x-wav                                */
    MIME_SUBTYPE_BMP                  ,         /*image/bmp                                  */
    MIME_SUBTYPE_BMP_1                ,         /*image/x-MS-bmp                             */
    MIME_SUBTYPE_GIF                  ,         /*image/gif                                  */
    MIME_SUBTYPE_WBMP                 ,         /*image/vnd.wap.wbmp                         */
    MIME_SUBTYPE_XIMELODY             ,         /*text/x-imelody                             */
    MIME_SUBTYPE_DRM_CONTENT          ,         /*application/vnd.oma.drm.content            */
    MIME_SUBTYPE_DRM_MESSAGE          ,         /*application/vnd.oma.drm.message            */
    MIME_SUBTYPE_DRM_RIGHTS_WBXML     ,         /*application/vnd.oma.drm.rights+wbxml       */
    MIME_SUBTYPE_DRM_RIGHTS_XML       ,         /*application/vnd.oma.drm.rights+xml         */
    MIME_SUBTYPE_DRM_CONTENT_V2       ,         /*application/vnd.oma.drm.dcf                */
    MIME_SUBTYPE_ROAP_PDU             ,         /*"application/vnd.oma.drm.roap-pdu+xml"     */
    MIME_SUBTYPE_ROAP_TRIGGER         ,         /*"application/vnd.oma.drm.roap-trigger+xml" */
    MIMI_SUBTYPE_PROTECTED_RO         ,         /*"application/vnd.oma.drm.ro              " */
    MIME_SUBTYPE_JAR                  ,         /*application/java-archive                   */
    MIME_SUBTYPE_JVM                  ,         /*application/java-vm                        */
    MIME_SUBTYPE_JAD                  ,         /*text/vnd.sun.j2me.app-descriptor           */
    MIME_SUBTYPE_THEME                ,         /*OMAapp/mtk.med.thm,mtk/med.thm             */
    MIME_SUBTYPE_PLAIN                ,         /*text/plain                                 */
    MIME_SUBTYPE_OMA_DD               ,         /*application/vnd.oma.dd+xml                 */
    MIME_SUBTYPE_HBSVCS               ,         /*application/hbs-vcs                        */
    MIME_SUBTYPE_CALENDAR             ,         /*text/calendar                              */
    MIME_SUBTYPE_XVCALENDAR           ,         /*text/x-vcalendar                           */
    MIME_SUBTYPE_VCARD                ,         /*application/vcard                          */
    MIME_SUBTYPE_XVCARD               ,         /*text/x-vcard                               */
    MIME_SUBTYPE_REFERTO              ,         /*application/vnd.poc.refer-to               */
    MIME_SUBTYPE_SDP                  ,         /*application/sdp                            */
    MIME_SUBTYPE_AAC                  ,         /*audio/aac                                  */
    MIME_SUBTYPE_XAAC                 ,         /*audio/x-aac                                */
    MIME_SUBTYPE_AWB                  ,         /*audio/amr-wb                               */
    MIME_SUBTYPE_AUDIO_MP3            ,         /*audio/mp3                                  */
    MIME_SUBTYPE_AUDIO_MPEG           ,         /*audio/mpeg                                 */
    MIME_SUBTYPE_AUDIO_MPG            ,         /*audio/mpg                                  */
    MIME_SUBTYPE_AUDIO_MPG3           ,         /*audio/mpg3                                 */
    MIME_SUBTYPE_AUDIO_XMP3           ,        /*audio/x-mp3                                */
    MIME_SUBTYPE_JPEG                 ,         /*image/jpeg                                 */
    MIME_SUBTYPE_JPG                  ,         /*image/jpg                                  */
    MIME_SUBTYPE_AVI                  ,         /*video/x-msvideo                            */
    MIME_SUBTYPE_AVI_1                ,         /*video/avi                                  */
    MIME_SUBTYPE_VSMAF                ,         /*application/vnd.smaf                       */
    MIME_SUBTYPE_XSMAF                ,         /*application/x-smaf                         */
    MIME_SUBTYPE_SMIL                 ,         /*application/smil                           */
    MIME_SUBTYPE_MIXED                ,         /*multipart/mixed                            */
    MIME_SUBTYPE_3GPP_VIDEO           ,         /*video/3gp                                  */
    MIME_SUBTYPE_3GPP_VIDEO_1         ,         /*video/3gpp                                 */
    MIME_SUBTYPE_3GPP_VIDEO_2         ,         /*application/.3gp                           */
    MIME_SUBTYPE_3GPP_AUDIO           ,         /*audio/3gpp                                 */
    MIME_SUBTYPE_3GP_AUDIO            ,         /*audio/3gp                                  */
    MIME_SUBTYPE_3GPP2_VIDEO          ,         /*video/3gpp2                                */
    MIME_SUBTYPE_MP4                  ,         /*video/mp4                                  */
    MIME_SUBTYPE_MP4_AUDIO            ,         /*audio/mp4                                  */
    MIME_SUBTYPE_MPEG                 ,         /*video/mpeg                                 */
    MIME_SUBTYPE_MPG                  ,         /*video/mpg                                  */
    MIME_SUBTYPE_M4A                  ,         /*audio/m4a                                  */
    MIME_SUBTYPE_XM4A                 ,         /*audio/x-m4a                                */
    MIME_SUBTYPE_PNG                  ,         /*image/png                                  */
    MIME_SUBTYPE_SVG                  ,         /*image/svg+xml                              */
    MIME_SUBTYPE_CA_CERT              ,         /*application/x-x509-ca-cert                 */
    MIME_SUBTYPE_USR_CERT             ,         /*application/x-x509-user-cert               */
    MIME_SUBTYPE_OMA_PROV_WBXML       ,         /*application/vnd.wap.connectivity-wbxml     */
    MIME_SUBTYPE_PKCS7_CERT           ,         /*application/x-pkcs7-certificates           */
    MIME_SUBTYPE_PKCS12_CERT          ,         /*application/x-pkcs12                       */
    MIME_SUBTYPE_NOKIA_PROV_BOOKMARKS ,         /*application/x-wap-prov.browser-bookmarks   */
    MIME_SUBTYPE_NOKIA_PROV_BROWSER   ,         /*application/x-wap-prov.browser-settings    */
    MIME_SUBTYPE_CSS                  ,         /*text/css                                   */
    MIME_SUBTYPE_HTML                 ,         /*text/html                                  */
    MIME_SUBTYPE_OMA_PROV_XML         ,         /*text/vnd.wap.connectivity-xml              */
    MIME_SUBTYPE_WML                  ,         /*text/vnd.wap.wml                           */
    MIME_SUBTYPE_WMLSCRIPT            ,         /*text/vnd.wap.wmlscript                     */
    MIME_SUBTYPE_WMLC                 ,         /*application/vnd.wap.wmlc                   */
    MIME_SUBTYPE_WMLSC                ,         /*application/vnd.wap.wmlscriptc             */
    MIME_SUBTYPE_WMA                  ,         /*audio/wma                                  */
    MIME_SUBTYPE_WMA_1                ,         /*audio/x-ms-wma                             */
    MIME_SUBTYPE_CSP_XML              ,         /*application/vnd.wv.csp.xml                 */
    MIME_SUBTYPE_CSP_WBXML            ,         /*application/vnd.wv.csp.wbxml               */
    MIME_SUBTYPE_CSP_CIR              ,         /*application/vnd.wv.csp.cir */
    MIME_SUBTYPE_CSP_SMS              ,         /*application/vnd.wv.csp.sms */
    MIME_SUBTYPE_M3D                  ,         /*application/vnd.mtk.m3d */
    MIME_SUBTYPE_WFD                  ,         /*application/Chaotex-wfd                    */
    MIME_SUBTYPE_CIM                  ,         /*application/Chaotex-cim                    */
    MIME_SUBTYPE_ZDD                  ,         /*image/vnd.ziyitong.zdd                     */
    MIME_SUBTYPE_VIS                  ,         /*application/vnd.mtk.vis                    */
    MIME_SUBTYPE_AU                   ,         /*audio/au*/
    MIME_SUBTYPE_PDB                  ,         /*application/x-pilot-pdb*/
    MIME_SUBTYPE_AU_XULAW             ,         /*audio/x-ulaw */
    MIME_SUBTYPE_AIFF                 ,         /*audio/x-aiff*/
    MIME_SUBTYPE_AIF                  ,         /*audio/x-aiff*/
    MIME_SUBTYPE_AIFC                 ,         /*audio/x-aiff*/
    MIME_SUBTYPE_SND                  ,         /*audio/basic*/
    MIME_SUBTYPE_MBC                  ,         /*application/vnd.mtk.mbc                    */
    MIME_SUBTYPE_LRC                  ,         /*application/vnd.mtk.lrc                    */
    MIME_SUBTYPE_DM_WBXML             ,         /*application/vnd.syncml.dm+wbxml            */
    MIME_SUBTYPE_DM_XML               ,         /*application/vnd.syncml.dm+xml              */
    MIME_SUBTYPE_DM_NOTIFICATION      ,         /*application/vnd.syncml.notification        */
    MIME_SUBTYPE_RELATED              ,         /*multipart/related*/
    MIME_SUBTYPE_AUDIO_MP2            ,         /*"audio/mp2"*/
    MIME_SUBTYPE_DS_NOTIFICATION      ,         /*application/vnd.syncml.ds.notification     */
    MIME_SUBTYPE_OMA_DD2              ,         /*application/vnd.oma.dd2+xml                */
    MIME_SUBTYPE_DZD                  ,         /*text/x-component                           */
    MIME_SUBTYPE_DZDX                 ,         /*application/dzd                            */
    MIME_SUBTYPE_XVBOOKMARK           ,         /*text/x-vbookmark                           */
    MIME_SUBTYPE_EMS                  ,         /*application/vnd.mtk.ems*/
    MIME_SUBTYPE_ANM                  ,         /*application/vnd.mtk.anm*/
    MIME_SUBTYPE_UNRECOGNIZED,  /* Un-recognized file type */
    MIME_SUBTYPE_NUM            /* Number of supported mime subtype */
} applib_mime_subtype_enum;

typedef enum
{
    MIME_MMI_TYPE = 0
} applib_mime_mmi_type;

typedef struct
{

    kal_char *mime_string;                  /* The string of mime type and mime subtype */
    kal_char *file_ext;                     /* File extension */
    applib_mime_type_enum mime_type;        /* Mime type */
    applib_mime_subtype_enum mime_subtype;  /* Mime subtype */
    applib_mime_mmi_type mmi_type;          /* file type of MMI task */
} applib_mime_type_struct;

typedef void* (*app_mime_mem_alloc_funcptr_type)(kal_uint32 size);

/*****************************************************************************              
* Extern Global Variable                                                                    
**************************************************************************** */

/*****************************************************************************              
* Extern Global Function                                                                    
**************************************************************************** */
extern applib_mime_type_struct *mime_type_look_up_ext(kal_char *mime_string, kal_char *mime_type_string, kal_char *mime_subtype_string, kal_char *file_ext, applib_mime_type_enum mime_type, applib_mime_subtype_enum mime_subtype);
extern applib_mime_type_struct *mime_type_look_up(
                                    kal_char *mime_string,
                                    kal_char *file_ext,
                                    applib_mime_type_enum mime_type,
                                    applib_mime_subtype_enum mime_subtype);


extern kal_int32 mime_type_look_up_mul(kal_char** ext_array, kal_int32 array_count, app_mime_mem_alloc_funcptr_type alloc_fn,
                                       applib_mime_type_struct*** result_table, kal_int32* result_count);

extern applib_mime_type_struct *mime_get_file_type(kal_wchar *file_path);
extern applib_mime_type_enum mime_get_mime_type(kal_char *mime_type);

extern const applib_mime_type_struct* mime_get_table(void);
extern kal_int32 mime_get_table_size(void);

#endif /* __APP_MINE_H__ */ 

