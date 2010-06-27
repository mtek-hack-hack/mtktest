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

/*! \file mamme.h
 *  \brief Message editor (Multi-Part/Mixed) control logic. 
 */

#ifndef _MAMME_H_
#define _MAMME_H_

/******************************************************************************
 * Constants
 *****************************************************************************/
/*!\enum MeaMmeSignalId 
 * \brief Signals for the MME FSM 
 */
typedef enum 
{
    /*
     *	Activation. Send a MeaMessage as p_param.
     */
    MEA_SIG_MME_ACTIVATE,
    MEA_SIG_MME_DEACTIVATE,

    /*
     *	Action received from MOB
     */
    MEA_SIG_MME_MOB_OP,


    /*
     *  Signals related to manipulating the media object list
     */
    MEA_SIG_MME_GET_MEDIA_OBJECT,
    MEA_SIG_MME_GET_MEDIA_OBJECT_REPLACEMENT,
    MEA_SIG_MME_GET_MEDIA_OBJECT_RSP,
    MEA_SIG_MME_DELETE_MO,
    MEA_SIG_MME_ADD_TEXT,
    MEA_SIG_MME_EDIT_TEXT,
    MEA_SIG_MME_PLAY_SOUND,

    /*
     *	Text editor signals
     */
    MEA_SIG_MME_TEXT_OK,
    MEA_SIG_MME_ADD_TEXT_OK,
    MEA_SIG_MME_TEXT_BACK,

    /*
     *	Dialog respnose
     */
    MEA_SIG_MME_RESTART_MOB_IND,

    /*
     *	Message saving/sending
     */
     MEA_SIG_MME_SEND,
     MEA_SIG_MME_SEND_DONE,
     MEA_SIG_MME_SAVE,
     MEA_SIG_MME_SAVE_DONE,
     MEA_SIG_MME_SAVE_AS_TEMPLATE,
     MEA_SIG_MME_SAVE_AS_TEMPLATE_DONE,

    /*
     *	Navigation menu
     */
    MEA_SIG_MME_NAV_MENU_ACTIVATE,
    MEA_SIG_MME_NAV_MENU_DEACTIVATE
}MeaMmeSignalId;

/*!\enum MeaMmeMainMenuItems 
 * \brief Menu items for the MME
 */
typedef enum
{
    MEA_MME_ADD_TEXT,               /*!< Add text */
    MEA_MME_ADD_MEDIA_OBJECT,       /*!< Add MO to the message */
    MEA_MME_DELETE_MEDIA_OBJECT,    /*!< Delete MO from the message */
    MEA_MME_REPLACE_MEDIA_OBJECT,   /*!< Replace MO in the message */
    MEA_MME_EDIT_TEXT,              /*!< Edit text */
    MEA_MME_PLAY_SOUND,             /*!< Play sound */
    MEA_MME_SAVE,                   /*!< Save message */
    MEA_MME_SAVE_AS_TEMPLATE,       /*!< Save message as template */
    MEA_MME_SEND,                   /*!< Send message */
    MEA_MME_PREVIEW,                /*!< Preview message */
    MEA_MME_BACK,                   /*!< Go back */
    MEA_MME_MENU_ITEM_COUNT         /*!< Not used */
}MeaMmeMainMenuItems;

/******************************************************************************
 * Prototypes
 *****************************************************************************/
void meaMmeInit(void);
void meaMmeTerminate(void);
void meaMmeTerminateGui(void);

#ifdef WAP_SUPPORT
MeaInsertResult meaInsertMixedObjCallback(const char * pathname);	/* called in MMI task */
#endif
#endif /* _MAMME_H_ */


