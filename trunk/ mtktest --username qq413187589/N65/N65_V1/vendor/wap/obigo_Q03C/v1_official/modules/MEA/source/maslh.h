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

/* !\file maslh.h
 * Logic for SMIL slide handling.
 */

#ifndef _MASLH_H_
#define _MASLH_H_

/******************************************************************************
 * Macros
 *****************************************************************************/
/* Default sizes used when calculating the message size*/
#define MEA_ENTRY_SIZE              (52)  /*!< The size of one entry excluding dynamic data*/
#ifdef WAP_SUPPORT
#define MEA_HEADER_SIZE             (140)   /*!< The header size and message class */
#else
#define MEA_HEADER_SIZE             (100)   /*!< The header size excluding dynamic data */
#endif /* WAP_SUPPORT */
#define MEA_SMIL_SIZE               (264)  /*!< The SMIL size excluding dynamic data  */
#define MEA_SMIL_PAR_SIZE           (27)    /*!< The size of on "par" tag */
#define MEA_SMIL_MO_SIZE            (30)    /*!< The header size for one media object */
#define MEA_AUDIO_SMIL_SRC_REG_SIZE (16)
#define MEA_SMIL_SRC_REG_SIZE       (28)    /*!< The header size for one media object, ex: text src="??" region="??" */
#define MEA_SMIL_NONASCII_FNAME_SIZE    (10)    /*!< The header size for non ascii file name */
#define MEA_SMIL_TXT_PARAM_SIZE     (55)    /*!< The header size for parameter size of text, ex: backgroundcolor */

/******************************************************************************
 * Prototypes
 *****************************************************************************/

MSF_BOOL meaCreateSmilInstance(MeaSmilInfo **smilInfo);
void meaCleanupSmilInstance(MeaSmilInfo **smilInfo);
void meaDeleteAllSlides(MeaSmilInfo *smilInfo);
#ifdef WAP_SUPPORT
MSF_BOOL meaDeleteAllEmptySlides(MeaSmilInfo *smilInfo);
MSF_BOOL meaIsObjectInSlide(MeaMoDataItem *item, MeaSmilSlide *slide);
MeaMediaGroupType meaGetLayoutOrder(const MeaSmilInfo *sInfo);
#endif /* WAP_SUPPORT */
MSF_BOOL meaDeleteSlide(MeaSmilInfo *smilInfo);
MSF_BOOL meaDeleteSlideMo(MeaSmilInfo *smilInfo, MeaMediaGroupType objType);
MeaSmilSlide *meaGetCurrentSlide(const MeaSmilInfo *smilInfo);
unsigned int meaGetDuration(const MeaSmilInfo *smilInfo);
MeaSmilSlide *meaGetFirstSlide(const MeaSmilInfo *smilInfo);
MeaSmilSlide *meaGetNextSlide(MeaSmilInfo *smilInfo);
MeaSmilSlide *meaGetPreviousSlide(MeaSmilInfo *smilInfo);
unsigned int meaGetSlideCount(const MeaSmilInfo *smilInfo);
unsigned int meaGetSlideIndex(const MeaSmilInfo *smilInfo, 
    const MeaSmilSlide *slide);
MeaSmilSlide *meaInsertSlide(MeaSmilInfo *smilInfo);
#ifdef WAP_SUPPORT
MeaSmilSlide *meaInsertSlideBefore(MeaSmilInfo *smilInfo);
#endif
void meaSetDuration(const MeaSmilInfo *smilInfo, unsigned int);
#ifdef __DRM_SUPPORT__ 
MeaMoDataItem *meaSetSlideMo(MeaSmilInfo *smilInfo, MeaMediaType type, MeaMediaType drmType,
    MmsContentType *mmsType, unsigned char *buffer, unsigned int size, char *name, MSF_UINT32 resHandle);
#else
MeaMoDataItem *meaSetSlideMo(MeaSmilInfo *smilInfo, MeaMediaType type, 
    MmsContentType *mmsType, unsigned char *buffer, unsigned int size, char *name, MSF_UINT32 resHandle);
#endif
MeaMoDataItem *meaGetMo(const MeaSmilInfo *smilInfo, MeaMediaGroupType objType);
MSF_BOOL meaGetObjInfo(const MeaSmilInfo *sInfo, MeaMediaGroupType type, 
    MeaObjInfo **objInfo);
MSF_UINT32 meaCalculateMsgSize(const MeaSmilInfo *smilInfo, 
    const MeaPropItem *propItem);
void meaOptimizeMoList(MeaSmilInfo *smilInfo);
MSF_BOOL meaCreateSmil(MeaSmilInfo *smilInfo, char **buffer, unsigned int *size);
MSF_BOOL meaIsSmilValid(const MeaSmilInfo *sInfo);
MeaMediaGroupType meaGetSlideObjectDef(const MeaSmilInfo *sInfo);

#endif /* _MASLH_H_ */


