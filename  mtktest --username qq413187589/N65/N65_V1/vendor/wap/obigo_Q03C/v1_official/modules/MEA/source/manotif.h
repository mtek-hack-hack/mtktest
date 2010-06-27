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

/*!\file manotif.h
 * \brief Reads a MMS notification. 
 */

#ifndef _MANOTIF_H_
#define _MANOTIF_H_

/******************************************************************************
 * Constants
 *****************************************************************************/

/*! \enum MeaReadNotifStates
 *  Message states when reding a message */
typedef enum
{
    MEA_MAL_OPEN_NOTIF,         /* !< Opening the notification */
    MEA_MAL_READ_NOTIF          /* !< Reading the notification */
}MeaReadNotifStates;

/*! \enum MeaReadNotifResult
 *  Possible return values when reading a message */
typedef enum
{
    MEA_READ_NOTIF_ERROR,     /* !< Error reading the notification */
    MEA_READ_NOTIF_DELAYED,   /* !< The operation is delayed */
    MEA_READ_NOTIF_NEW_STATE, /* !< The operation is split into several calls */
    MEA_READ_NOTIF_DONE       /* !< The message was successfully read */
}MeaReadNotifResult;

/******************************************************************************
 * Data-types
 *****************************************************************************/

/*! \struct MeaGetNotifInstance
 *  Data type used for notification parsing */
typedef struct
{
    MmsMsgHandle         msgHandle;
    MmsTransactionHandle tr;
    MmsMsgId             msgId;
    MmsFileType          msgType;
    MmsResult            mmsRes;
    MmsNotification      *notif;
    MeaReadNotifStates   state; 
    MeaStateMachine      notifyFsm;    /*!< FSM to report delayed file 
                                            operations to */
    int                  notifySignal; /*!< Signal sent when a delayed file 
                                            operation can be continued */
}MeaGetNotifInstance;

/******************************************************************************
 * Prototypes
 *****************************************************************************/

MeaReadNotifResult meaGetNotifFSM(MeaGetNotifInstance *inst);
#ifdef WAP_SUPPORT
MeaReadNotifResult meaGetNotifLength(MmsMsgId msgId, MmsFileType msgType, MSF_UINT32 *msgLength);
#endif /* WAP_SUPPORT */
MSF_BOOL meaCreateGetNotifInstance(MeaGetNotifInstance **inst, MmsMsgId msgId,
    MmsFileType msgType, MeaStateMachine notifyFsm, 
    int notifySignal);
void meaCleanupGetNotifInstance(MeaGetNotifInstance **inst);

#endif /* _MANOTIF_H_ */


