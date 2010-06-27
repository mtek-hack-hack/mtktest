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

/*! \file mamob.h
 *  \brief Media object browser
 */

#ifndef _MAMOB_H_
#define _MAMOB_H_

/******************************************************************************
 * Constants
 *****************************************************************************/

/*! \enum MeaMobSignalId
 *  Signals for the media object viewer FSM */
typedef enum 
{
    /*! Activate the media object viewer.
     * p_param: structure containing startup parameters (see #MeaMobActivation)
     */
    MEA_SIG_MOB_ACTIVATE,
    
    /*! Deactivate the media object viewer.
     */
    MEA_SIG_MOB_DEACTIVATE,

    /*! Signal used by mob to add one media object at a time (time slicing) 
     */
    MEA_SIG_MOB_ADD_NEXT_MO,

    /*! Signal used by mod to add a special operation 
     */
    MEA_SIG_MOB_ADD_NEXT_SOP,

    /*! Signal used by mob to start creating window with widgets
    */
    MEA_SIG_MOB_FINALIZE_WINDOW,

    /*! Signal sent by gui to MOB when Menu button is pressed
     */
    MEA_SIG_MOB_MENU_SELECTED,

    /*! Signal sent by gui to MOB when Ok button is pressed
     */
    MEA_SIG_MOB_OK_SELECTED,

    /*! Signal sent by gui to MOB when Stop button is pressed
     */
    MEA_SIG_MOB_STOP_SELECTED,

    /*! Signal sent by gui to MOB when focus is altered
     */
    MEA_SIG_MOB_FOCUS_ACTIVITY,

    MEA_SIG_MOB_WAIT_WIDGET,
    MEA_SIG_MOB_READ_FINISHED,
    //Finish the async read operation of DRM object
    MEA_SIG_MOB_READ_DRM_MO_RSP,
    //Finish the async write operation of DRM object
    MEA_SIG_MOB_WRITE_DRM_MO_RSP,
    //Copy DRM object finished
    MEA_SIG_MOB_COPY_DRM_FINISHED,
    /*! Signal sent to MOB when End User presses left on joystick 
     */
    MEA_SIG_MOB_KEY_LEFT,

    /*! Signal sent to MOB when End User presses right on joystick 
     */
    MEA_SIG_MOB_KEY_RIGHT,

    /*!Signal sent to MOB when scrollbar scrolled by pen
     */
    MEA_SIG_MOB_EVENT_SCROLL,

    MEA_SIG_MOB_GET_TEXT_TOTAL_HEIGHT,
    MEA_SIG_MOB_GET_TEXT_TOTAL_HEIGHT_CONTINUE,
    MEA_SIG_MOB_GET_TEXT_TOTAL_HEIGHT_FINISHED,    

    /*! Signal sent to MOB when End User replay the current mob 
     */
    MEA_SIG_MOB_PLAY_AUDIO,
    MEA_SIG_MOB_PLAY_VIDEO
}MeaMobSignalId;

/*! \enum MeaMobOperation
 *  Operation in MOB that requires external activity */
typedef enum
{
    MEA_MOB_DEACTIVATED,   /*!< MOB deactivated, i.e. back pressed */
    MEA_MOB_SELECT,        /*!< Entry selected in MOB */
    MEA_MOB_MENU,          /*!< Menu button pressed on entry */
    MEA_MOB_SPECIAL_OP,    /*!< Special operation selected */
    MEA_MOB_FOCUS_ACTIVITY /*!< Changed focus within attachment list */
}MeaMobOperation;

/*! \enum MeaMobSpecialOp
 *  Internal, special operation, selectable through attachment list */
typedef enum
{
    MEA_MOB_SOP_NO_OP     = 0x0000, /*!< No op, just end of list marker */
    MEA_MOB_SOP_NEXT_PAGE = 0x0001, /*!< Next page selector */
    MEA_MOB_SOP_PREV_PAGE = 0x0002, /*!< Previous page selector */
    MEA_MOB_SOP_ADD_MO    = 0x0004  /*!< Add media object */
}MeaMobSpecialOp;

/*! Number of different special operations */
#define MEA_MOB_SOP_COUNT   3

/*! Maximum number of media objects to display per page  */
#ifdef WAP_SUPPORT
#define MEA_MAX_NUMBER_OF_MO_ON_PAGE 1
#else
#define MEA_MAX_NUMBER_OF_MO_ON_PAGE 5
#endif /* WAP_SUPPORT */

/*! Maximum total height in pixels of all image and text widgets per page */
#define MEA_MAX_PAGE_HEIGHT          100

/******************************************************************************
 * Data-structures
 *****************************************************************************/

/*! \struct MeaMobActivation
 *  Initialization parameters for activation of MOB */
typedef struct
{
    MeaMoDataItem   *moList;               /*!< media objects */
    MeaMobSpecialOp sop;                   /*!< special operations */    
    MsfStringHandle winTitle;              /*!< window title */
    MeaStateMachine fsm;                   /*!< the fsm that gets MOB op 
                                                reports */
    int             signal;                /*!< the signal to use when sending
                                                MOB op reports */
}MeaMobActivation;

/******************************************************************************
 * Prototypes
 *****************************************************************************/

void meaMobInit(void);
void meaMobTerminate(void);
void meaMobActivate(MeaMoDataItem *moList, MeaMobSpecialOp sop, 
    MsfStringHandle winTitle, MeaStateMachine fsm, int signal); 
MSF_BOOL meaMobIsActive(void);
#ifdef WAP_SUPPORT
int meaMobGetMoIndex(const MeaMoDataItem *mo);
unsigned int meaMobGetMoCount(void);
//MSF_BOOL meaMobCheckIsText(void);
#ifndef __UNIFIED_MSG_SUPPORT__
MSF_BOOL meaMobCheckIsEmpty(void);
#endif
#endif /*WAP_SUPPORT*/
#ifdef MMS_SLIM_MEM
MSF_BOOL meaCopyDrmMo(const char *dstFilePath, const char *sourceFilePath, MeaMoDataItem *mo, 
    MeaStateMachine fsm, unsigned int readRetSig, unsigned int writeRetSig);
void meaReadMixedMoFinished(MSF_UINT32  handle, MsfNotificationType notificationType);
#endif /* MMS_SLIM_MEM */

#endif /* _MAMOB_H_ */


