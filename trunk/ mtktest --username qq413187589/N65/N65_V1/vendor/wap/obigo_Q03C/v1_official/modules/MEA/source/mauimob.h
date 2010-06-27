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

/*! \file mauimob.h
 *  \brief Media object browser UI logic (headers)
 */

#ifndef _MAUIMOB_H_
#define _MAUIMOB_H_

#ifdef MMS_SLIM_MEM
/*! \enum MeaUiMobEntryType
 * Identifies the menu entry as a media object or a special operation */
typedef enum
{
    MEA_MOB_SOP,                    /*!< Entry is special operation */
    MEA_MOB_MO                      /*!< Entry is media object */
}MeaUiMobEntryType;
#endif /* MMS_SLIM_MEM */
/******************************************************************************
 * Prototypes
 *****************************************************************************/

MSF_BOOL meaUiMobAddSpecialOp(MeaMobSpecialOp op);
#ifndef __UNIFIED_MSG_SUPPORT__
void meaUiMobCreateTextView(MeaMoDataItem * textMo);
#endif
#ifdef MMS_SLIM_MEM
void addWidget(MSF_UINT32 handle, int mtrInstance, 
    MeaUiMobEntryType type, MeaMediaGroupType group, MeaMobSpecialOp sop);
MSF_BOOL meaUiMobAddWidget(MeaMoDataItem *mo);
MSF_BOOL getMixedMoInfo(const MeaMoDataItem *mo, int *startPos);
#ifdef __DRM_SUPPORT__
MSF_BOOL displayDrm(MSF_INT32 fileHandle, MeaMediaType mediaType);
#endif /* __DRM_SUPPORT__ */
#else
MSF_BOOL meaUiMobAddWidget(const MeaMoDataItem *mo);
#endif /* MS_SLIM_MEM */
MSF_BOOL meaUiInitializeForm(void);
#ifdef WIDGET_SLIDING_SMIL_VBAR
MsfWindowHandle meaUiMobGetForm(void);
#ifdef __MMI_TOUCH_SCREEN__
void meaHandleScrollEvent(MsfNotificationType event);
#endif /* __MMI_TOUCH_SCREEN__*/
#endif
MSF_BOOL meaUiMobFinalizeForm(MSF_UINT32 moIndex);
int meaUiMobCheckFocus(void);
MeaMobSpecialOp meaUiMobGetSpecialOp(void);
void meaUiMobDeleteAll(void);
void meaUiMobInit(void);
void meaUiMobTerminate(void);    
MtrLinkEntry *meaUiMobGetLink(int num);

void meaUiMobStopAudio(void);
void meaUiMobPlayAudio(void);
void meaUiMobUpdateForm(MSF_BOOL isPlaying);
void meaUiMobHandleTimer(void);

#if defined(MEA_GET_MIXED_TEXT_HEIGHT) && defined(WIDGET_SLIDING_SMIL_VBAR)
MSF_BOOL  meaUiMobCreateGetTextHeightInst(const char* text);
void meaUiMobDeleteGetTextHeightInst(void);
MSF_BOOL meaUiMobGetTextHeight(void);
void meaUiMobSetTotalTextHeightValue(void);
MSF_BOOL meaUiMobAddTextWidget(MeaMoDataItem *mo);
#endif

#endif


