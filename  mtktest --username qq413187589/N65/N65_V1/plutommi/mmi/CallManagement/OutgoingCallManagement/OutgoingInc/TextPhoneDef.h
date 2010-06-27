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
 *  TextPhoneDef.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef __MMI_UCM__

#ifndef _TEXT_PHONE_DEF_H
#define _TEXT_PHONE_DEF_H

#define MAX_CTM_DATA_COUNT          64
#define MAX_CTM_DATA_BUFFER_LEN     ((MAX_CTM_DATA_COUNT+1)<<1)
#define MAX_CTM_EDITOR_COUNT        20
#define MAX_CTM_EDITOR_BUFFER_LEN   ((MAX_CTM_EDITOR_COUNT+1)<<1)

typedef enum
{
    MMI_CTM_STATE_IDLE,
    MMI_CTM_STATE_OPENING,
    MMI_CTM_STATE_OPENED,
    MMI_CTM_STATE_CONNECTING,
    MMI_CTM_STATE_CONNECTED,
    MMI_CTM_STATE_SENDING,
    MMI_CTM_STATE_CLOSING
} MMI_CTM_STATE_ENUM;

typedef enum
{
    MMI_CTM_SETTING_BAUDOT,
    MMI_CTM_SETTING_HCO,
    MMI_CTM_SETTING_VCO,
    MMI_CTM_SETTING_MANUAL_DIRECT,
    MMI_CTM_SETTING_AUTO_DIRECT
} MMI_CTM_SETTING_ENUM;

typedef struct
{
    MMI_CTM_STATE_ENUM state;
    U8 mode_setting;    /* auto, manual, baudot */
    U8 mode_activated;
    pBOOL tty_status;
    pBOOL status;       /* CTM on/off */
    U16 remote_len;
    U16 local_len;
    U16 pending_len;
    U16 sent_len;
    S32 index;
    U8 remote_buffer[MAX_CTM_DATA_BUFFER_LEN];
    U8 local_buffer[MAX_CTM_DATA_BUFFER_LEN];
    U8 editor_buffer[MAX_CTM_EDITOR_BUFFER_LEN];
    U8 pending_buffer[MAX_CTM_EDITOR_BUFFER_LEN];
} mmi_ctm_context_struct;

extern mmi_ctm_context_struct *ctm_p;

#endif /* _TEXT_PHONE_DEF_H */ 
#endif /* __MMI_UCM__ */

#ifdef __MMI_UCM__
#include "TextPhoneDefEX.h"
#endif /* __MMI_UCM__ */
