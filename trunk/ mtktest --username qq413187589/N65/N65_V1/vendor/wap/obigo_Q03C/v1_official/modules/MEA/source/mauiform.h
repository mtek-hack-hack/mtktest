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

/*!\file mauiform.h
 * \brief Common input forms.
 */

#ifndef _MAUIFORM_H_
#define _MAUIFORM_H_

/******************************************************************************
 * Constants
 *****************************************************************************/

/*! \enum MeaInputType
 *  Input types */
typedef enum
{
    MEA_TEXT_INPUT,         /* !< Multiple lines of text */
    MEA_SINGLE_LINE_INPUT,  /* !< One line of text */
    MEA_RADIO_BUTTON_INPUT, /* !< A list of radio buttons */
    MEA_SELECT_INPUT        /* !< A list of items where one can be selected */
}MeaInputType;

/*! Callback for user actions */
typedef MSF_BOOL (*MeaInputActionCallBack)(char *, unsigned int, void *, \
                                           unsigned int);

typedef void (*MeaInputActionBackCallBack)(void *, unsigned int);

/******************************************************************************
 * Data-types
 *****************************************************************************/

/* !\struct MeaInputItem 
 *  \brief Data-structure used when creating an input form 
 */
typedef struct
{
    MeaInputType type;              /* !< The type of input to create */

    MsfTextType     textType;       /* !< The type of text to input */
    char            *text;          /* !< The initial value */
    unsigned int    maxTextSize;    /* !< The maximum size of input data */

    int              selectedItem;  /* !< The item that is selected */
    MsfStringHandle  *items;        /* !< A list of strings handles to be
                                         displayed, use the handle 0 for the
                                         last element */
    void            *dataPtr;       /* !< A pointer provided in the callback */
    unsigned int    uintValue;      /* !< An integer value provided in the 
                                          callback */
    MeaInputActionCallBack callback; /*!< The OK callback function */
    MeaInputActionBackCallBack backCallback; /*!< The BACK callback function */
}MeaInputItem;

/******************************************************************************
 * Prototypes
 *****************************************************************************/

void meaInitForms(void);
void meaTerminateForms(void);
MSF_BOOL meaCreateInputForm(const MeaInputItem *item, 
    MSF_UINT32 titleStrHandle);

#endif


