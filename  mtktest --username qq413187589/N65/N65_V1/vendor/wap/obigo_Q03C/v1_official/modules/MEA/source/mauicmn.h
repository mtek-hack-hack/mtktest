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

/*! \file mauicmn.h
 *  \brief Common functions for the GUI.
 */

#ifndef _MAUICMN_H_
#define _MAUICMN_H_

/******************************************************************************
 * Macros
 *****************************************************************************/
#define MEA_GET_STR_ID(strId)   MSF_WIDGET_STRING_GET_PREDEFINED(strId)
#define MEA_GET_IMG_ID(resId)   MSF_WIDGET_IMAGE_GET_PREDEFINED(resId, NULL)

/*! The default width and height for gadgets.
 */
#define MEA_GADGET_DEF_WIDTH            240
#define MEA_GADGET_DEF_HEIGHT           40

#define MEA_GADGET_DEF_PADDING          (5)
#define MEA_CMN_BASELINE_SIZE           (1)

 /******************************************************************************
 * Types
*****************************************************************************/

/*! \enum MeaCmnStringGadgetData */
typedef struct 
{
    MsfWindowHandle window;      /*!< Handle of the gadget window */
    MsfGadgetHandle gadget;      /*!< Handle of the gadget */
    MSF_BOOL hasLabel;           /*!< TRUE if gadget has a title */
    MSF_BOOL multipleLines;      /*!< TRUE if gadget allows multiple lines */
    MsfStringHandle gadgetString;/*!< A handle to the string in the gadget */
    MsfPosition gadgetPos;       /*!< The position the gadget will have */
    MsfSize maxSize;             /*!< The max (default) size of the gadget */
    MsfSize *gadgetSize;         /*!< Pointer to where the new optimized 
                                      size will be stored */
}MeaCmnStringGadgetData;

/*! \enum MeaSeverity */
typedef enum
{
    MEA_SEVERITY_OK,        /*!< Status OK */    
    MEA_SEVERITY_WARNING,   /*!< Status Warning */
    //MEA_SEVERITY_ASSERT,
    MEA_SEVERITY_ERROR      /*!< Status Error */
}MeaSeverity;

/******************************************************************************
 * Prototypes
 *****************************************************************************/

void meaInitGui(void);
void meaTerminateGui(void);
MsfScreenHandle meaGetScreenHandle(void);
void meaGetDisplaySize(MsfSize *ms);
int meaGetSelectedChoiceIndex(MSF_UINT32 choiceHandle);
#ifdef WAP_SUPPORT
MsfImageHandle meaGetListNumImage(int i);
#endif /* WAP_SUPPORT */
MsfStringHandle meaGetEmptyStringHandle(void);
MsfPosition *meaGetPosLeftTop(void);
int meaDisplayWindow(MsfWindowHandle windowHandle, 
    const MsfPosition *pos);
char *meaGetStringFromHandle(MsfStringHandle strHandle);
char *meaGetTextFromGadget(MsfGadgetHandle gadgetHandle);
MSF_BOOL meaSetTextInputGadgetValue(MsfGadgetHandle gadgetHandle, int maxLen, 
    const char *newStringValue);
MSF_BOOL meaSetTitle(MsfWindowHandle win, MsfStringHandle strHandle, 
    int currentProperties);
MSF_BOOL meaSetStringGadgetValue(MsfGadgetHandle gadgetHandle,
    MsfStringHandle strHandle, const char *str);
char *meaGetIntervalString(MSF_UINT32 prefix, int minVal, 
    MSF_UINT32 infix, int maxVal);
MeaSeverity meaShowSizeWarningDialog(MSF_UINT32 newMsgSize, 
    MSF_UINT32 objectSize, MeaMediaType mediaType, MeaStateMachine fsm, 
    int signal);
void meaIntToMsfColor(MSF_UINT32 rgbColor, MsfColor *msfColor);
MSF_UINT32 meaMsfToIntColor(MsfColor *msfColor);
void meaCalculateStringGadgetSize(MsfWindowHandle window, 
    MsfGadgetHandle gadget, MsfStringHandle strHandle, const MsfPosition *pos, 
    const MsfSize *maxSize, MsfSize *newSize, MSF_BOOL multipleLines);

#endif


