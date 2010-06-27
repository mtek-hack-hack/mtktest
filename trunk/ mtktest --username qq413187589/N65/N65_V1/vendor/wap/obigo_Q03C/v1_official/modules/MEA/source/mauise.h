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
 * Description:     Definitions for the SMIL editor UI.
 */

/* !\file mauise.h
 */

#ifndef _MAUISE_H_
#define _MAUISE_H_

/******************************************************************************
 * Type definitions
 *****************************************************************************/

/*! \enum MeaSeGadgetDef
 *	
 */
typedef enum
{
    MEA_SE_GADGET_NONE = 0,     /*!< No gadget is active */
    MEA_SE_GADGET_INP_AUDIO,    /*!< The audio icon is active */
    MEA_SE_GADGET_INP_TEXT,     /*!< The text region is active */
    MEA_SE_GADGET_INP_IMAGE,    /*!< The image regin is active */
    MEA_SE_GADGET_AUDIO,        /*!< The audio icon is active */
    MEA_SE_GADGET_TEXT,         /*!< The text part is active */
    MEA_SE_GADGET_IMAGE         /*!< The image part is active */
}MeaSeGadgetDef;

/******************************************************************************
 * Data-types
 *****************************************************************************/

/******************************************************************************
 * Prototype declarations
 *****************************************************************************/

void meaSeUiInit(void);

/* Slide edit view */
MSF_BOOL meaSeCreateEditorView(void);
MSF_BOOL meaSeShowSlide(const MeaSmilInfo *smilInfo, 
    const MeaPropItem *propItem);

void meaSeSetBusy(MSF_BOOL busy);
#ifdef WAP_SUPPORT
MSF_BOOL meaSmilEditorIsActive(void);

  #ifdef __DRM_SUPPORT__
MsfImageHandle createDrmImageHandle(MSF_INT32 fileHandle, MeaMediaType type);
  #endif /* __DRM_SUPPORT__ */

  #ifdef WIDGET_ADVANCED_SMIL_EDITOR
MsfWindowHandle meaSeGetFormHandle(void);
char *meaSeGetTextBuffer(void);
  #endif /* WIDGET_ADVANCED_SMIL_EDITOR */
#endif /* WAP_SUPPORT */
void meaSeDeleteEditorView(void);

/* Active region */
MeaSeGadgetDef meaSeGetActiveGadget(void);
MeaMediaGroupType meaSeGetActiveObjType(void);
#ifndef WIDGET_ADVANCED_SMIL_EDITOR
void meaSeSetActiveObj(void);
#endif

/* Text editor */
MSF_BOOL meaSeCreateTextView(char *text, const char *title);
MSF_BOOL handleSeTvOkAction(char *text, unsigned int notUsed, void *dataPtr, unsigned int uintValue);

/* User interaction */
void meaSeHandleEvent(MsfEventType event);
void meaSeHandleNotif(MsfNotificationType notif);

#endif


