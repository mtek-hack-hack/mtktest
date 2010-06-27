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
 *  MMSMsgXMLTags.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  MMS Messsage Content XML Tags
 *
 *
 * Author: Sukrit K Mehra (PMT0050)
 * -------
 * -------
 * 
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __MMSMsgXMLTags_H__
#define __MMSMsgXMLTags_H__

#ifdef __MMI_MMS_2__
/* Elements */
#define MMI_UMMS_XML_ELEMENT_MMS "mms"
#define MMI_UMMS_XML_ELEMENT_HEADER "header"
#define MMI_UMMS_XML_ELEMENT_TO "to"
#define MMI_UMMS_XML_ELEMENT_CC "cc"
#define MMI_UMMS_XML_ELEMENT_BCC "bcc"
#define MMI_UMMS_XML_ELEMENT_FROM "from"
#define MMI_UMMS_XML_ELEMENT_SUBJECT "subject"
#define MMI_UMMS_XML_ELEMENT_REPORTED_SUBJECT "reported_msg_sub"
#define MMI_UMMS_XML_ELEMENT_READ_REPORT "rr"
#define MMI_UMMS_XML_ELEMENT_DELIVERY_REPORT "dr"
#define MMI_UMMS_XML_ELEMENT_PRIORITY "prio"
#define MMI_UMMS_XML_ELEMENT_EXPIRY "expiry"
#define MMI_UMMS_XML_ELEMENT_DELIVERY_TIME "delivery"
#define MMI_UMMS_XML_ELEMENT_VISIBLE "visible"
#define MMI_UMMS_XML_ELEMENT_BODY "body"
#define MMI_UMMS_XML_ELEMENT_SLIDE "slide"
#define MMI_UMMS_XML_ELEMENT_TEXT "text"
#define MMI_UMMS_XML_ELEMENT_IMAGE "img"
#define MMI_UMMS_XML_ELEMENT_AUDIO "audio"
#define MMI_UMMS_XML_ELEMENT_VIDEO "video"
#define MMI_UMMS_XML_ELEMENT_OBJECT "obj"
#define MMI_UMMS_XML_ELEMENT_NAME "name"
#define MMI_UMMS_XML_ELEMENT_FILE_PATH "filepath"
#define MMI_UMMS_XML_ELEMENT_VERSION "mms_version"
#define MMI_UMMS_XML_ELEMENT_DATE "date"
#define MMI_UMMS_XML_ELEMENT_MSG_CLASS "msgclass"
#define MMI_UMMS_XML_ELEMENT_MSG_SIZE	"msgsize"
#define MMI_UMMS_XML_ELEMENT_DL_SIZE    "dl_size"
#define MMI_UMMS_XML_ELEMENT_REPORT_MSG_ID "reported_msg"
#define MMI_UMMS_XML_ELEMENT_MSG_STATUS "msgStatus"
#define MMI_UMMS_XML_ELEMENT_JAVA_APP_ID "app_id"
#define MMI_UMMS_XML_ELEMENT_JAVA_REPLY_APP_ID "reply_app_id"
#define MMI_UMMS_XML_ELEMENT_CONTENT_ID "cnt_id"
#define MMI_UMMS_XML_ELEMENT_CONTENT_LOCATION "cnt_loc"
#define MMI_UMMS_XML_ELEMENT_MIME_TYPE "mime"
#define MMI_UMMS_XML_ELEMENT_STATUS "status"

/* Attributes */
#define MMI_UMMS_XML_ATTR_TYPE "type"
#define MMI_UMMS_XML_ATTR_POHNE_NUMBER "P"
#define MMI_UMMS_XML_ATTR_EMAIL_ADDR "E"
#define MMI_UMMS_XML_ATTR_BGCOLOR "bgColor"
#define MMI_UMMS_XML_ATTR_FGCOLOR "fgColor"
#define MMI_UMMS_XML_ATTR_SLIDE_NUM "slideNum"
#define MMI_UMMS_XML_ATTR_OBJ_NUM "objNum"
#define MMI_UMMS_XML_ATTR_LAYOUT "layout"
#define MMI_UMMS_XML_ATTR_INDEX "index"
#define MMI_UMMS_XML_ATTR_DURATION "dur"
#define MMI_UMMS_XML_ATTR_ID "id"
#define MMI_UMMS_XML_ATTR_BEGIN "begin"
#define MMI_UMMS_XML_ATTR_END "end"
#define MMI_UMMS_XML_ATTR_ATTACH "attach"
#define MMI_UMMS_XML_ATTR_VIRTUAL_FILE "vf"
#define MMI_UMMS_XML_ATTR_DRM "drm"
#define MMI_UMMS_XML_ATTR_SIZE "size"
#define MMI_UMMS_XML_ATTR_OFFSET "offset"
#define MMI_UMMS_XML_ATTR_TEXT_STYLE	"txtStyle"
#define MMI_UMMS_XML_ATTR_TEXT_SIZE		"txtSize"
#define MMI_UMMS_XML_ATRR_ALT_STR "alt"
#define MMI_UMMS_XML_ATTR_ENCODING_SCHEME "encoding"

#endif /* __MMI_MMS_2__ */
#endif /*__MMSMsgXMLTags_H__*/

