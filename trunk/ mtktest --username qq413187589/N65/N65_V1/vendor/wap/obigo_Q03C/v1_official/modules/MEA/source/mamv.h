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

/*! \file mamv.h
 *  \brief Message Viewer control logic.
 */

#ifndef _MAMV_H_
#define _MAMV_H_

/******************************************************************************
 * Constants
 *****************************************************************************/

/*! \enum MeaMVSignalId
 *  Signals for the message viewer FSM */
typedef enum 
{
    /*! Activate the message viewer.
     * i_param: filetype
     * u_param1: message-id to view
     */
    MEA_SIG_MV_ACTIVATE,
    
    /*! The response to the MMSif_getMsgInfo
     *
     *  p_param = the message info, see #MmsMessageFolderInfo
     */
    MEA_SIG_MV_GET_MSG_TYPE_RSP,

    /*
     *	The response gotten when MCR is done loading a message
     */
    MEA_SIG_MV_MR_DONE,

    /*! Deactivate the message viewer.
     */
    MEA_SIG_MV_DEACTIVATE,

    /*! View the SMIL message.
     */
    MEA_SIG_MV_VIEW_SMIL,
     
    /*! Activate the viewer for message properties
     *
     */
    MEA_SIG_MV_PROP_ACTIVATE,

    /*! Read the message confirm
     */
    MEA_SIG_MV_ACTIVATE_CONFIRM,

    /*! The viewer for message properties (Opens prop view directly)
     */
    MEA_SIG_MV_PROP_VIEW,
    /*! The viewer for message status (Opens status view directly)
     */
    MEA_SIG_MV_STATUS_VIEW,
    /*! The viewer for message properties (Opens prop view via a confirm window)
     */
    MEA_SIG_MV_PROP_VIEW_CONFIRM,

    /*! The viewer for notification properties (Opens prop view directly with option menu)
     */
    MEA_SIG_MV_NOTIF,
    /*! The end user presses ok when the property viewer is active
     *
     */
    MEA_SIG_MV_PROP_OK,

    /*!
     * View content (SMIL/MM)
     */
    MEA_SIG_MV_VIEW_CONTENT,


    /*! The MMS service has returned requested Read Report data 
     *
     */
    MEA_SIG_MV_RR, 

    /*! The MMS service has returned requested Delivery Report data 
     *
     */
    MEA_SIG_MV_DR,

    /*! This signal is sent if a read-report shall be sent.
     * u_param = MeaConfirmDialogResult, ok or cancel.
     */
    MEA_SIG_MV_SEND_READ_REPORT,
    
    /*! The SMA has finished playing the SMIL presentation 
     *
     */
    MEA_SIG_MV_PLAY_DONE,

    /*! The download response
     *
     */
    MEA_SIG_MV_DOWNLOAD_RSP,

    /* Address lookup response
     *
     * p_param = The lookup entry, see #MeaAddrItem
     */
    MEA_SIG_MV_NAME_LOOKUP_RSP

}MeaMvSignalId;

/*! \enum MeaMvPropNavMenuItem
 *  Possible menu items for the message viewer */
typedef enum
{
    MEA_MV_DOWNLOAD,
    MEA_MV_PROP_DELETE,        /* !< Delete the message */
    MEA_MV_PROP_DELETE_ALL,    /* !< Delete all messages in the folder */
    MEA_MV_PROP_USE_DETAILS,     /* !< Use number/email/url in the message */
    MEA_MV_PROP_MOVE_TO_ARCHIVE  /* !< Move to archive*/
}MeaMvPropNavMenuItem;

/******************************************************************************
 * Data-structures
 *****************************************************************************/

/******************************************************************************
 * Prototypes
 *****************************************************************************/
#ifdef WAP_SUPPORT
MSF_BOOL hasMvInstance(void);
void mvClearMvInstance(void);
void mvClearMvInstanceForCancelDownload(void);
void meaMvSetActiveMsgId(MmsMsgId msgId);
void meaMvTransformToMixed(void);
void meaMvSetPlySmilFailed(MSF_BOOL flag);
#endif /* WAP_SUPPORT */
#if defined(WAP_SUPPORT) || defined(__DRM_SUPPORT__)
MmsMsgId meaMMCGetCurrentActiveMsg(void);
#endif /* defined(WAP_SUPPORT) || defined(__DRM_SUPPORT__) */

void meaMvInit(void);
void meaMvTerminate(void);

#endif /* _MAMV_H_ */










































