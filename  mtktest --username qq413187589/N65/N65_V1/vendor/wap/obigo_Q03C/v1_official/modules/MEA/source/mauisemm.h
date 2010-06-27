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

/* !\file mauisemm.h
 *  \brief The main menu for the SMIL editor.
 */

#ifndef _MAUISEMM_H_
#define _MAUISEMM_H_

/******************************************************************************
 * Definitions
 *****************************************************************************/

/*!\enum MeaSeMainMenuItems 
 * Menu items for the SMIL editor 
 */
typedef enum
{
    MEA_SE_TEXT_FG_COLOR,       /*!< Change the text color */
    MEA_SE_TEXT_FG_COLOR_ALL,    /*!< Change the text color for all objects */
    MEA_SE_TEXT_BG_COLOR,       /*!< Change the text background color */
    MEA_SE_OBJ_TIMING_START,    /*!< Set the "begin" time for the object */
    MEA_SE_OBJ_TIMING_DURATION, /*!< Set the duration for the object */
    MEA_SE_DELETE_OBJECT,       /*!< Delete the currently active object */
    MEA_SE_ADD_SLIDE_BEFORE,    /*!< Insert a new page before */
    MEA_SE_ADD_SLIDE_AFTER,     /*!< Insert a new page after */
    MEA_SE_INSERT_PAGE,         /*!< Insert a new page */
    MEA_SE_DELETE_SLIDE,        /*!< Delete the current slide */
    MEA_SE_DURATION,            /*!< Set the slide duration */
    MEA_SE_BG_COLOR,            /*!< Background color */
    MEA_SE_SAVE,                /*!< Save the message */
    MEA_SE_SAVE_AS_TEMPLATE,    /*!< Save the message as a template */
    MEA_SE_SEND,                /*!< Send the message */
    //MEA_SE_SAVE_AND_SEND,     /*!< Send and save the message */
    MEA_SE_ADD_TEXT,
    MEA_SE_ADD_BOOKMARK_TEXT,
    MEA_SE_ADD_IMAGE,
    MEA_SE_ADD_AUDIO,
    MEA_SE_ADD_ATTACHMENT,
    MEA_SE_EDIT_TEXT,
    MEA_SE_EDIT_IMAGE,
    MEA_SE_EDIT_AUDIO,
    MEA_SE_EDIT_ATTACHMENT,
    MEA_SE_REMOVE_IMAGE,
    MEA_SE_REMOVE_AUDIO,
    MEA_SE_ADD_VIDEO,
    MEA_SE_EDIT_VIDEO,
    MEA_SE_REMOVE_VIDEO,
    MEA_SE_REMOVE_ATTACHMENT,
    MEA_SE_PREVIOUS_SLIDE,
    MEA_SE_NEXT_SLIDE,
    MEA_SE_PREVIEW_SMIL,        /*!< Preview the message using the SMA */
    MEA_SE_INPUT_METHOD,
    MEA_SE_BACK,                /*!< Go back */
    MEA_SE_MENU_ITEM_COUNT      /*!< Not used */
}MeaSeMainMenuItems;

typedef struct 
{
    MsfWindowHandle menuHandle; /*!< The menu handle */
}MeaSeAttachmentListView;

/******************************************************************************
 * Prototype declarations
 *****************************************************************************/

/* Navigation menu for the SE */
MSF_BOOL meaSeCreateNavMenu(int slideCount, int initiated,
    int slideIndex);
void meaSeDeleteNavMenu(void);

#endif


