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

/*! \file mammv.h
 *  \brief Viewer of Multipart Mixed messages (interface)
 */

#ifndef _MAMMV_H_
#define _MAMMV_H_

/******************************************************************************
 * Constants
 *****************************************************************************/

/*! \enum MeaMmvSignalId
 *  Signals for the multipart mixed message viewer FSM */
typedef enum 
{
    /*! Activate the MM message viewer.
     * p_param MeaMessage structure indicating message to view.
     */
    MEA_SIG_MMV_ACTIVATE,
    
    /*! Deactivate the MM message viewer.
     */
    MEA_SIG_MMV_DEACTIVATE,

    /*! Return signal from media object browser
     * u_param1 Type of MOB operation, see #MeaMobOperation
     * u_param2 The selected attachment, or -1 if none.
     * p_param Link information, if user selected link, see #MtrLinkEntry
     */
    MEA_SIG_MMV_MOB_OP,

    /*! Deactivate the attachment menu */
    MEA_SIG_MMV_NAV_DEACTIVATE,

    /*! Save attachment */
    MEA_SIG_MMV_NAV_SAVE,

    /*! Save done response signal */
    MEA_SIG_MMV_SAVE_DONE,

    /*! Content router done with playing
     * u_param1 Result of CR operation, see #MeaCrhResult.
     */
    MEA_SIG_MMV_CRH_DONE,

    /*! Make call response 
     * u_param1 TRUE/FALSE result 
     */
    MEA_SIG_MMV_MAKE_CALL_RSP,


    MEA_SIG_MMV_HANDLE_ACTION_RSP
    
 
}MeaMmvSignalId;

/*! \enum MeaMvNavMenuItem
 *  Possible menu items for the message viewer */
typedef enum
{
    MEA_MMV_NEXT_SLIDE,
    MEA_MMV_PREVIOUS_SLIDE,
    MEA_MMV_PLAY_SOUND,            /* !< Play sound */
    MEA_MMV_PLAY_VIDEO,            /* !< Play video */
    MEA_MMV_MOVE_TO_ARCHIVE,
    MEA_MMV_SEND,
    MEA_MMV_REPLY,
    MEA_MMV_REPLY_SMS,
    MEA_MMV_REPLY_ALL,
    MEA_MMV_FORWARD,
    MEA_MMV_EDIT,
    MEA_MMV_DELETE,
    MEA_MMV_DELETE_ALL,
    MEA_MMV_PROPERTIES,
    MEA_MMV_USE_NUMBER,
    MEA_MMV_SAVE,            /* !< Save attachment */
    MEA_MMV_BACK,            /* !< Back */
    MEA_MMV_LINK_CALL,
    MEA_MMV_LINK_BRA,
    MEA_MMV_LINK_WRITE,
    MEA_MMV_NAV_MENU_COUNT   /* !< Not used */
}MeaMmvNavMenuItem;


/******************************************************************************
 * Prototypes
 *****************************************************************************/

void meaMmvInit(void);
void meaMmvTerminate(void);

#endif /* _MAMMV_H_ */


