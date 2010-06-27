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
 *  MobileTVPlayerEnum.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Mobile TV Player Applications v0.1
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#ifndef _MMI_MOBILE_TV_PLAYER_ENUM_H_
#define _MMI_MOBILE_TV_PLAYER_ENUM_H_

typedef enum
{
    MMI_MTV_KERNEL,
    MMI_MTV_PLAYER,
    MMI_MTV_RECORDER,

    MMI_MTV_MODULE_TOTAL_COUNT

}mmi_mtv_player_module_enum;

typedef enum
{
    MTV_KERNEL_CLOSED = 0,
    MTV_KERNEL_SAVE_CONFIRM = 1,
    MTV_KERNEL_SAVING = 2,
    MTV_KERNEL_SCANNING = 3,
    MTV_KERNEL_OPENED = 4,
    MTV_KERNEL_INIT = 5,
    MTV_KERNEL_READY = 6,

    MTV_KERNEL_NULL = 7,

    MTV_KERNEL_TOTAL_COUNT

}mmi_mtv_player_kernel_state_enum;

typedef enum
{
    MTV_PLAYER_STOPPED = 0,
    MTV_PLAYER_BT_CONNECT = 1,
    MTV_PLAYER_PLAY = 2,
    MTV_PLAYER_PAUSE = 3,

    MTV_PLAYER_NULL = 4,

    MTV_PLAYER_TOTAL_COUNT

}mmi_mtv_player_player_state_enum;

typedef enum
{
    MTV_RECORDER_STOPPED = 0,
    MTV_RECORDER_RECORD = 1,
    MTV_RECORDER_SAVE_CONFIRM = 2,
    MTV_RECORDER_SAVING = 3,

    MTV_RECORDER_NULL = 4,

    MTV_RECORDER_STATE_TOTAL_COUNT

}mmi_mtv_player_recorder_state_enum;


#endif /* _MMI_MOBILE_TV_PLAYER_ENUM_H_ */

