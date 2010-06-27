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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *	osc_errcode.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 * Header file for OSCAR (Operating System Call Adapter) error code
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __OSC_ERRCODE_H__
#define __OSC_ERRCODE_H__

/* MACRO **************************************************************************/

#define  OSC_NO_ERROR		               0
#define  OSC_ERR_PLATFORM_CALL_FAIL       -1    //fail on platform call, always -1
#define  OSC_ERR_UNSUPPORTED_PLATFORM     -2
#define  OSC_ERR_NULL_ENTRY_FUNC          -3
#define  OSC_ERR_NULL_NAME                -4
#define  OSC_ERR_DD_LIST_TYPE             -5
#define  OSC_ERR_DD_LIST_NODE             -6
#define  OSC_ERR_DD_LIST_NULL             -7
#define  OSC_ERR_INVALID_PARAM            -8
#define  OSC_ERR_INVALID_THREAD           -9
#define  OSC_ERR_INVALID_TIMEOUT          -10
#define  OSC_ERR_INVALID_TIME_SLICE       -11
#define  OSC_ERR_INVALID_QUERY            -12
#define  OSC_ERR_INVALID_LOCK             -13
#define  OSC_ERR_INVALID_SUSPEND          -14
#define  OSC_ERR_INVALID_SEMAPHORE        -15
#define  OSC_ERR_INVALID_STATE            -16
#define  OSC_ERR_INVALID_CALLER           -17
#define  OSC_ERR_INVALID_TIMER            -18
#define  OSC_ERR_INVALID_BUFFER           -19
#define  OSC_ERR_INVALID_QUEUE            -20
#define  OSC_ERR_INVALID_MESSAGE          -21
#define  OSC_ERR_INVAILD_EVENT            -22
#define  OSC_ERR_INVAILD_ACTION           -23
#define  OSC_ERR_INVALID_ISR_SRC          -24
#define  OSC_ERR_NAME_TOO_LONG            -25
#define  OSC_ERR_PRIORITY                 -26
#define  OSC_ERR_MISS_TICK_TIME           -27
#define  OSC_ERR_OVER_DEF_NUM             -28
#define  OSC_ERR_RESOURCE_NOT_PURE        -29
#define  OSC_ERR_BUFF_NOT_AVAILABLE       -30
#define  OSC_ERR_QUEUE_EMPTY              -31
#define  OSC_ERR_MISMATCH_EVENT           -32
#define  OSC_ERR_SEMA_NO_AVAILABLE        -33
#define  OSC_ERR_SYSTEM_BUSY              -34
#define  OSC_ERR_TIMER_EMPTY              -35
#define  OSC_ERR_MULTI_SUSPEND            -36
#define  OSC_ERR_ISR_REGISTERED           -37
#define  OSC_ERR_MALLOC_FAIL              -38
#define  OSC_ERR_DEAD_LOCK                -39

#endif //__OSC_ERRCODE_H__
