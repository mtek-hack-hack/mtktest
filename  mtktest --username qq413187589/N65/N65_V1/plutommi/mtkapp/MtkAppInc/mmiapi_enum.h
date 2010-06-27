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
 * mmiapi_enum.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file is defines message structures of MMI.
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
#ifndef _MMIAPI_ENUM_
#define _MMIAPI_ENUM_

typedef enum
{
    MMIAPI_DEV_CTRL_UNKNOW,

    MMIAPI_DEV_CTRL_GET,
    MMIAPI_DEV_CTRL_RELEASE,

    MMIAPI_DEV_CTRL_MAX
} MMIAPI_DEV_GET_CTRL_ACTION;

typedef enum
{
    MMIAPI_RPC_VOID,
    MMIAPI_RPC_INTEGER,
    MMIAPI_RPC_POINTER
} mmiapi_remote_proc_call_enum;

typedef enum
{
    MMIAPI_DEV_TYPE_UNKNOW,

    MMIAPI_DEV_TYPE_MAINLCD_BL,
    MMIAPI_DEV_TYPE_SUBLCD_BL,
    MMIAPI_DEV_TYPE_KEYPAD_BL,
    MMIAPI_DEV_TYPE_LED_1,  /* R */
    MMIAPI_DEV_TYPE_LED_2,  /* G */
    MMIAPI_DEV_TYPE_LED_3,  /* B */
    MMIAPI_DEV_TYPE_VIBRATOR,

    MMIAPI_DEV_TYPE_MAX
} MMIAPI_DEV_PLAY_TYPE;

typedef enum
{
    MMIAPI_DEV_LEVEL_UNKNOW,

    MMIAPI_DEV_LEVEL_0, /* Turn off */
    MMIAPI_DEV_LEVEL_1,
    MMIAPI_DEV_LEVEL_2,
    MMIAPI_DEV_LEVEL_3,
    MMIAPI_DEV_LEVEL_4,
    MMIAPI_DEV_LEVEL_5,

    MMIAPI_DEV_LEVEL_MAX
} MMIAPI_DEV_PLAY_LEVEL;

#endif /* _MMIAPI_ENUM_ */ /* _MMIAPI_STRUCT_ */

