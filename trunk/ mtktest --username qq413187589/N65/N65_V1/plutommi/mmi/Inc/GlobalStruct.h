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
 *  GlobalStruct.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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

   FILENAME : Globalstruct.h

   PURPOSE     : .

   REMARKS     : nil

   AUTHOR      : Vijay Vaidya

   DATE     : .

**************************************************************/

#ifndef _GLOBALSTRUCT_H_
#define _GLOBALSTRUCT_H_

#ifdef MMI_ON_HARDWARE_P
#include "l4dr.h"

//MTK micha remarked
//already defined in callmanagementstruct.h

//      #define MAX_NUMBER                              MAX_CC_ADDR_LEN*ENCODING_LENGTH
//      #define MAX_NAME                                L4C_MAX_NAME_LEN
//#else
//      #define MAX_NUMBER                              40*ENCODING_LENGTH
//      #define MAX_NAME                                40
#endif /* MMI_ON_HARDWARE_P */ 

/* Message structure to convey timer expiry events to MMI */
typedef struct TMR_MESSAGE
{
    /* short nMsgType; */
    S16 nTimerId;
} TMR_MESSAGE;

/* Protocol task message structure */

typedef struct PRT_MESSAGE
{
    U32 nMsgLength;     /* length of the data */
    void *pPRTDataPtr;  /* pointer to data */
} PRT_MESSAGE;

/***************************************************************
Start of SMS Mailbox Definition
****************************************************************/

typedef struct DisplayListInfo
{
    S8 addr[(22) *2];
    S8 *name;
    S8 ts_date[(13) *2];
    S8 ts_time[(13) *2];
    U8 status;
    U16 mmi_index[4];
} DisplayInfo;

typedef struct MessageInfo_struct
{
    U16 ref;
    U16 residue;
    U16 index;
    U8 outOfBoundSegment;
    U8 actualSegNum;
    U8 status;
    U8 segInfo;
    U16 displayIndex;
} MessageInfo;

typedef struct AwaitedNewSMSInfo_struct
{
    U16 refNum;
    U16 residue;
    U8 total_seg;
    S8 *number;
    S8 *num7;
    U8 numType;
    S8 segs;
    U8 startSegNum;
    U16 indices[4]; /* Keep four segments indices */
    U8 scts[7];
    signed char tmrId;
    U8 visibleFlag;
} AwaitedNewSMSInfo;

#endif /* _GLOBALSTRUCT_H_ */ 

