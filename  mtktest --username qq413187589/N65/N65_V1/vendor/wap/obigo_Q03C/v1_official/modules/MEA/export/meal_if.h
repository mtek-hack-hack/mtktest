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
#ifndef _MEAL_IF_H
#define _MEAL_IF_H

/*!
 * \brief Return restricted image mime type string
 * 
 * \return Mime type string
 *****************************************************************************/
const char *MEAlib_getOpenRestrictedImageType(void);

/*!
 * \brief Return restricted text mime type string
 * 
 * \return Mime type string
 *****************************************************************************/
const char *MEAlib_getOpenRestrictedTextType(void);

/*!
 * \brief Return restricted audio mime type string
 * 
 * \return Mime type string
 *****************************************************************************/
const char *MEAlib_getOpenRestrictedAudioType(void);

/*!
 * \brief Return restricted video mime type string
 * 
 * \return Mime type string
 *****************************************************************************/
const char *MEAlib_getOpenRestrictedVideoType(void);

/*!
 * \brief Return restricted attachment mime type string
 * 
 * \return Mime type string
 *****************************************************************************/
const char *MEAlib_getOpenRestrictedAttachmentType(void);

/*!
 * \brief Return image mime type string
 * 
 * \return Mime type string
 *****************************************************************************/
const char *MEAlib_getOpenImageType(void);

/*!
 * \brief Return text mime type string
 * 
 * \return Mime type string
 *****************************************************************************/
const char *MEAlib_getOpenTextType(void);

/*!
 * \brief Return audio mime type string
 * 
 * \return Mime type string
 *****************************************************************************/
const char *MEAlib_getOpenAudioType(void);

/*!
 * \brief Return video mime type string
 * 
 * \return Mime type string
 *****************************************************************************/
const char *MEAlib_getOpenVideoType(void);

/*!
 * \brief Return attachment mime type string
 * 
 * \return Mime type string
 *****************************************************************************/
const char *MEAlib_getOpenAttachmentType(void);

/*!
 * \brief Return default SMIL background color value
 * 
 * \return RGB color value (8 bits per channel, ex. 0x00FF0000 for red color)
 *****************************************************************************/
const unsigned MEAlib_getDefaultSmilBgColor(void);

/*!
 * \brief Return default SMIL foreground(text) color value
 * 
 * \return RGB color value (8 bits per channel, ex. 0x00FF0000 for red color)
 *****************************************************************************/
const unsigned MEAlib_getDefaultSmilFgColor(void);

/*!
 * \brief Return SMIL content ID string
 * 
 * \return ID
 *****************************************************************************/
const char *MEAlib_getSmilContentId(void);

/*!
 * \brief Return SMIL file name
 * 
 * \return SMIL file name
 *****************************************************************************/
const char *MEAlib_getSmilFileName(void);

/*!
 * \brief Return default SMIL text region name string
 * 
 * \return text region name string
 *****************************************************************************/
const char *MEAlib_getSmilTextRegionName(void);

/*!
 * \brief Return default SMIL image region name string
 * 
 * \return image region name string
 *****************************************************************************/
const char *MEAlib_getSmilImageRegionName(void);

/*!
 * \brief Return default subject charset setting 
 * 
 * \return MmsCharset
 *****************************************************************************/
MmsCharset MEAlib_getSubjectCharset(void);

/*!
 * \brief Return default minimum sliding duration
 * 
 * \return minimum sliding time in second
 *****************************************************************************/
const unsigned MEAlib_getMinSlidingTime(void);

/*!
 * \brief Return default maximum sliding duration
 * 
 * \return maximum sliding time in second
 *****************************************************************************/
const unsigned MEAlib_getMaxSlidingTime(void);

/*!
 * \brief Return default signature tex file path
 * 
 * \return file path
 *****************************************************************************/
const char *MEAlib_getSignatureFilePath(void);

/*!
 * \brief Return MMS screen display width
 * 
 * \return width
 *****************************************************************************/
const unsigned MEAlib_getDisplayWidth(void);

/*!
 * \brief Return MMS screen display height
 * \return width
 *****************************************************************************/
const unsigned MEAlib_getDisplayHeight(void);

/*!
 * \brief Return expiry time type setting
 * 
 * \return MMS_TIME_RELATIVE/MMS_TIME_ABSOLUTE
 *****************************************************************************/
MmsTimeType MEAlib_getExpiryTimeType(void);

/*!
 * \brief Return delivery time type setting
 * 
 * \return MMS_TIME_RELATIVE/MMS_TIME_ABSOLUTE
 *****************************************************************************/
MmsTimeType MEAlib_getDeliveryTimeType(void);

#endif /* _MEAL_IF_H */

