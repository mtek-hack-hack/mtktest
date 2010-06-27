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
 * CallFixedDial.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Fixed Dial List definitions
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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

   AUTHOR      : Vanita jain 

   DATE     : Jan 15,02

**************************************************************/

#ifndef _PIXTEL_CALLFIXEDDIALLIST_H
#define _PIXTEL_CALLFIXEDDIALLIST_H

extern void HighlightAddFDL(void);
extern void HighlightEditFDL(void);
extern void HighlightDeleteFDL(void);

extern void EntrySECSETFDNList(void);
extern void ExitSECSETFDNListReload(void);
extern void EntrySECSETFDNOption(void);
extern void EntrySECSETFDNDetails(void);
extern void ExitSECSETFDNDetails(void);
extern void EntrySECSETFDNDelConfirm(void);
extern void EntrySECSETFDNSaveConfirm(void);

extern void SECSETGetFdlEntriesReq(void);
extern void SECSETGetFdlEntriesRsp(void *);
extern void SECSETSetFdlEntryReq(void);
extern void SECSETSetFdlEntryRsp(void *);
extern void SECSETDelFdlReq(void);
extern void SECSETDelFdlRsp(void *);

extern void GetActiveIndex(S32);
extern void GetEntryTitle(S32);
extern void PreNewFdlEntryReq(void);
extern void FdlMakeCall(void);
extern void ViewFDList(void);
extern void FillFdlInlineEditStruct(void);
extern void GoToFDLList(void);

extern void EntrySECSETFDNBDNSaving(void);
extern void EntrySECSETFDNBDNDeleting(void);
extern void EntrySECSETFDNBDNWaiting(void);
extern void PreSaveFdlBdlEntryReq(void);

#endif /* _PIXTEL_CALLFIXEDDIALLIST_H */ 

