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
 *  StopwatchDef.h
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

   FILENAME : StopwatchDef.h

   PURPOSE     : contains macro definitions for stop watch application.

   REMARKS     : nil

   AUTHOR      : Deepali Gupta

   DATE     : 05/01/2004

**************************************************************/

#ifndef _STOPWATCH_DEF_H
#define _STOPWATCH_DEF_H

#include "MMI_features.h"
#ifdef __MMI_STOPWATCH__

#include "MMIDataType.h" 

enum STR_STOPWATCH_LIST
{
    STR_STOPWATCH_TITLE = STOPWATCH_BASE + 1,
    STR_TYPICAL_STOPWATCH,
    STR_MULTIPURPOSE_STOPWATCH,
    STR_SPLIT_TIMING,
    STR_LAP_TIMING,
    STR_VIEW_RECORD,
    STR_STOPWATCH_START,
    STR_STOPWATCH_STOP,
    STR_STOPWATCH_SPLIT,
    STR_STOPWATCH_LAP,
    STR_STOPWATCH_RESUME,
    STR_STOPWATCH_MEMORY_FULL,
    STR_STOPWATCH_NOT_SAVED,
    STR_STOPWATCH_REPLACE_RECORD,
    STR_STOPWATCH_SAVE_STOPWATCH,
    /* Robin 0726, use global string defination */
    //STR_STOPWATCH_LIST_EMPTY,
    //STR_VIEW_STOPWATCH_LIST_OPTION_VIEW,
    //STR_VIEW_STOPWATCH_LIST_OPTION_DELETEALL,
    //STR_CONFIRM_DELETE_ALL_RECORD,
    STR_EMPTY_NAME,
    STR_MUTIPURPOSE_TITLE_MSG,
    STR_MUTIPURPOSE_TITLE_SIDE_MSG,
    STR_DISCONTINUE_TIMER_QUERY
};

enum IMG_STOPWATCH_LIST
{
    IMG_MULTIPURPOSE_TIMER1 = STOPWATCH_BASE + 1,
    IMG_MULTIPURPOSE_TIMER2,
    IMG_MULTIPURPOSE_TIMER3,
    IMG_MULTIPURPOSE_TIMER4,
    IMG_TYPICALSW_BACKGROUND,
#if defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_320X240__)
    IMG_TYPICALSW_LIST_BACKGROUND,
#endif 
    IMG_STOPWATCH_ICON
};

enum SCR_STOPWATCH_LIST
{
    SCR_STOPWATCH = STOPWATCH_BASE + 1,
    SCR_TYPICAL_STOPWATCH,
    SCR_MULTIPURPOSE_STOPWATCH,
    SCR_SPLIT_TIMING,
    SCR_VIEW_RECORD,
    SCR_ENTER_RECORD_NAME,
    SCR_SAVE_OPTIONS,
    SCR_VIEW_RECORD_OPTIONS,
    SCR_VIEW_SAVED_RECORD,
    SCR_REPLACE_RECORD
};

#endif /* __MMI_STOPWATCH__ */ 
#endif /* _STOPWATCH_DEF_H */ 

