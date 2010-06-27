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

/*! \file mase.h
 *  \brief Control logic for the SMIL editor.
 */

#ifndef _MASE_H_
#define _MASE_H_

/******************************************************************************
 * Constants
 *****************************************************************************/

/*!\enum MeaSeSignalId 
 * \brief Signals for the SE FSM 
 */
typedef enum 
{
    /* SMIL edit core */
    /*! Activates the SMIL editor
     * p_param  = The message, see #MeaMeInstance 
     * u_param1 = -
     * u_param2 = -
     * i_param  = -
     */
    MEA_SIG_SE_ACTIVATE,

    /*! Deactivates the SMIL editor
     * p_param  = -
     * u_param1 = -
     * u_param2 = -
     * i_param  = -
     */
    MEA_SIG_SE_DEACTIVATE,

    /*! Inserts a new slide into the presentation, the new slide is displayed
     *  to the End User.
     * p_param  = -
     * u_param1 = - (TRUE: add before, FALSE: add after)
     * u_param2 = -
     * i_param  = -
     */
    MEA_SIG_SE_INSERT_SLIDE,

    /*! Deletes the slide that is currently active
     * p_param  = -
     * u_param1 = -
     * u_param2 = -
     * i_param  = -
     */
    MEA_SIG_SE_DELETE_SLIDE,

    /* Retrieves a media object using the AFI file system.
     * u_param1 = The result, see #MeaOpenDlgResult
     * p_param  = The file-name or NULL.
     * u_param2 = -
     * i_param  = -
     */
    MEA_SIG_SE_GET_MEDIA_OBJECT,

    /*! Sets the next slide as the active one
     *
     * p_param  = -
     * u_param1 = -
     * u_param2 = -
     * i_param  = -
     */
    MEA_SIG_SE_NEXT_SLIDE,

    /*! Sets the previous slide as the active one
     *
     * p_param  = -
     * u_param1 = -
     * u_param2 = -
     * i_param  = -
     */
    MEA_SIG_SE_PREVIOUS_SLIDE,

    /*! Save the message
     *
     * p_param  = -
     * u_param1 = -
     * u_param2 = -
     * i_param  = -
     */
    MEA_SIG_SE_SAVE,

    /*! Save the message as a template
     *
     * p_param  = -
     * u_param1 = TRUE if save was ok, otherwise FALSE.
     * u_param2 = Message Id av the new message
     * i_param  = -
     */
    MEA_SIG_SE_SAVE_AS_TEMPLATE,

    /*! SMIL creation signals
     *
     * p_param  = -
     * u_param1 = TRUE if save was ok, otherwise FALSE.
     * u_param2 = Message Id av the new message
     * i_param  = -
     */
    MEA_SIG_SE_SMIL_SAVE_RSP,

    /*! Sends the message
     *
     * p_param  = -
     * u_param1 = -
     * u_param2 = -
     * i_param  = -	
     */
    MEA_SIG_SE_SEND,

    /*! Activates the main menu
     *
     * p_param  = -
     * u_param1 = -
     * u_param2 = -
     * i_param  = -
     */
    MEA_SIG_SE_NAV_MENU_ACTIVATE,

    /*! Deactivates the main menu
     *
     * p_param  = -
     * u_param1 = -
     * u_param2 = -
     * i_param  = -
     */
    MEA_SIG_SE_NAV_MENU_DEACTIVATE,

    /*! Handles insert/edit of media objects 
        The response when an object has been opened
     *
     * p_param  = (MeaAfiReadResultData *)
     * u_param1 = (MeaAfiReadResult)
     * u_param2 = -
     * i_param  = -
     */
    MEA_SIG_SE_GET_MEDIA_OBJECT_RSP,

    /*! Preview the current message
     *
     * p_param  = -
     * u_param1 = -
     * u_param2 = -
     * i_param  = -
     */
    MEA_SIG_SE_PREVIEW_SMIL,

    /*! The message is saved for the forthcoming preview
     *
     * p_param  = -
     * u_param1 = TRUE if save was ok, otherwise FALSE.
     * u_param2 = The msgId of the new message.
     * i_param  = -
     */
    MEA_SIG_SE_PREVIEW_SAVE_DONE,

    /*! The message has been previewed
     *
     * p_param  = -
     * u_param1 = -
     * u_param2 = -
     * i_param  = -
     */
    MEA_SIG_SE_PREVIEW_DONE,

    /* Removes a media object from the current presentation
     *
     * p_param  = -
     * u_param1 = the object type to remove, see #MeaMediaGroup
     * u_param2 = -
     * i_param  = -
     */
    MEA_SIG_SE_REM_OBJECT,

    /*! Launch the color selector form for the background color
     *
     * p_param  = -
     * u_param1 = -
     * u_param2 = -
     * i_param  = -
     */
    MEA_SIG_SE_SET_BG_COLOR,

    /*! The response from the color selector form
     *
     * p_param  = -
     * u_param1 = the new color
     * u_param2 = -
     * i_param  = -
     */
    MEA_SIG_SE_SET_BG_COLOR_RSP,

    /*! Launch the color selector form
     *
     * p_param  = -
     * u_param1 = -
     * u_param2 = -
     * i_param  = -
     */
    MEA_SIG_SE_SET_TEXT_COLOR,

    /*! The response from the color selector form
     *
     * u_param1 = the new color
     */
    MEA_SIG_SE_SET_TEXT_COLOR_RSP,

    /*! 
     *
     * p_param  = -
     * u_param1 = -
     * u_param2 = -
     * i_param  = -
     */
     
    MEA_SIG_SE_SET_TEXT_COLOR_ALL,

    /*! The response from the color selector form
     *
     * u_param1 = the new color
     */

    MEA_SIG_SE_SET_TEXT_COLOR_ALL_RSP,

    /*! 
     *
     * p_param  = -
     * u_param1 = -
     * u_param2 = -
     * i_param  = -
     */
    MEA_SIG_SE_GADGET_GOT_FOCUS,

    /*! 
     *
     * p_param  = -
     * u_param1 = -
     * u_param2 = -
     * i_param  = -
     */
    MEA_SIG_SE_GADGET_LOST_FOCUS,

    /*! 
     *
     * p_param  = -
     * u_param1 = -
     * u_param2 = -
     * i_param  = -
     */
    MEA_SIG_SE_EVENT_KEY_DOWN,

    /*! 
     *
     * p_param  = -
     * u_param1 = -
     * u_param2 = -
     * i_param  = -
     */
    MEA_SIG_SE_EVENT_KEY_UP,
    
    /*! Handles insert of media objects 
     *
     * p_param  = -
     * u_param1 = The type of object the handle, see #MeaMediaGroupType
     * u_param2 = -
     * i_param  = -
     */
    MEA_SIG_SE_ADD_OBJECT,

    /*! Handles replace of media objects 
     *
     * p_param  = -
     * u_param1 = The type of object the handle, see #MeaMediaGroupType
     * u_param2 = The index of the to-be-replaced attachment
     * i_param  = -
     */
    MEA_SIG_SE_REPLACE_OBJECT,

    /*! Handles inserted text
     *
     * p_param  = -
     * u_param1 = text string
     * u_param2 = -
     * i_param  = -
     */
    MEA_SIG_SE_ADD_TEXT
}MeaSeSignalId;

/* !\enum MeaSeOper
 *  \brief The types of file insert operation
 */
typedef enum
{
    MEA_SE_OPER_NONE,    /*!< No operation */
    MEA_SE_OPER_ADD,     /*!< Add file */
    MEA_SE_OPER_REPLACE  /*!< Replace file */
}MeaSeObjOper;

/******************************************************************************
* Data-structures
*****************************************************************************/
typedef struct
{
    MeaSeObjOper oper;
    MeaMediaGroupType operObjType;
    MSF_UINT32 objIndex;  /* used only for attachment */
}MeaSeInstance;

/******************************************************************************
 * Prototypes
 *****************************************************************************/

void meaSeInit(void);
void meaSeTerminate(void);
unsigned int meaSeGetDuration(void);
MSF_BOOL meaSeHandleDuration(char *duration, unsigned int notUsed, 
    void *dataPtr, unsigned int uintValue);
void meaSeTerminateGui(void);

#ifdef WAP_SUPPORT
void meaShowSlideForAttachment(void);
void meaSeRemoveAttachmentList(void);
MeaMediaGroupType meaGetCurrentSlideObjectDef(void);
int meaGetAttachmentSize(void);
MeaInsertResult meaInsertSMILObjCallback(const char * pathname);	/* called in MMI task */
MSF_UINT32 meaSeGetAttachmentNo(void);
void meaSeRemoveAttachmentByIndex(int index);
void meaSeAddAttachment(char *fileName);
attachmentObjectList *meaGetAttachmentList(void);
#endif /* WAP_SUPPORT */
#endif /* _MASE_H_ */


