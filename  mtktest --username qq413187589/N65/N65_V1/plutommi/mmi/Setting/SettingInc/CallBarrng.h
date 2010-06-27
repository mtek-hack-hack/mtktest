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

/*******************************************************************************
 * Filename:
 * ---------
 * CallBarring.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   <file description>.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : Calls_Defs.h

   PURPOSE     : Call application 

   REMARKS     : nil

   AUTHOR      : PixTel

   DATE     : Jan 15,02

**************************************************************/
#ifndef _PIXTEL_CALLBARRING_H
#define _PIXTEL_CALLBARRING_H

typedef enum
{
    BARRING_OUTGOING_ALLCALLS,
    BARRING_OUTGOING_INTERCALL,
    BARRING_OUTGOING_INTEREXCEPTHOME,
    BARRING_INCOMING_ALLCALLS,
    BARRING_INCOMING_ROAMING
} SSBarType;

typedef enum
{
    BARRING_ON,
    BARRING_OFF,
    BARRING_QUERY,
    BARRING_CHANGE_PSW,
    BARRING_CANCEL_ALL
} SSBarAction;

extern void MakeCall(PS8);
extern void InitCallBarring(void);
extern void HighlightCALLSETCallBarring(void);
extern void EntryCALLSETBarringMain(void);
extern void HighlightCALLSETCallBarringOutgoing(void);
extern void HighlightCALLSETCallBarringIncoming(void);
extern void HighlightCALLSETCallBarringCancelAll(void);
extern void HighlightCALLSETCallBarringChangePwd(void);
extern void EntryCALLSETBarringOut(void);
extern void EntryCALLSETBarringIn(void);
extern void EntryScrCallBarringCancelAll(void);
extern void EntryScrCallBarringChnPass(void);
extern void HighlightCALLSETCallBarringAllOutCalls(void);
extern void HighlightCALLSETCallBarringAllOutInter(void);
extern void HighlightCALLSETCallBarringAllOutInterExcHome(void);
extern void HighlightCALLSETCallBarringAllInCalls(void);
extern void HighlightCALLSETCallBarringAllInRoaming(void);
extern void EntryCALLSETBarringOption(void);
extern void HighlightCALLSETCallBarringActive(void);
extern void HighlightCALLSETCallBarringDeactive(void);
extern void HighlightCALLSETCallBarringQuery(void);
extern void EntryCALLSETBarringPass(void);
extern void CallBarrOption(void);
extern void SendCallBarrActivate(void);
extern void SendCallBarrDeactivate(void);
extern void SendBarrQuery(void);
extern void SendCancelAllReq(void);
extern void CallBarringCancelAllRsp(void *);
extern void SendChangePswdReq(void);
extern void EntryCALLSETBarringOldPass(void);
extern void EntryCALLSETBarringNewPass(void);
extern void EntryCALLSETBarringCfrmPass(void);

extern void CheckOldpassword(void);
extern void CheckNewpassword(void);
extern void CheckConfirmpassword(void);
extern void CheckBarpassword(void);

#endif /* _PIXTEL_CALLBARRING_H */ 

