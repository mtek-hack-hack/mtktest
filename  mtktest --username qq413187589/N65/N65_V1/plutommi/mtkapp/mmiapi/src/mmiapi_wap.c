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
 * mmiapi_wap.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   MMI services for WAP
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
 *============================================================================== *******************************************************************************/

/*  Include: MMI header file */
#include "MMI_include.h"
#include "wgui_status_icons.h"
#include "MMIFrameworkMsgHandlerProt.h"
//#include "MMIFrameworkSap.h"
//#include "MMIFrameworkStruct.h"
#include "SettingProfile.h"
#include "ProfileGprots.h"
#include "CallManagementGProt.h"
#include "WapDef.h"

#include "mmiapi_struct.h"
#include "SimDetectionGexdcl.h"
#include "SimDetectionGprot.h"
#ifndef MMI_ON_WIN32
#include "mmiapi.h"
#include "mmiapi_func.h"
#endif /* MMI_ON_WIN32 */ 



#define MMI_MAX_MSG_ACTION_COUNT 10
#define MMI_MSG_ACTION_SIZE 3

static U8 mmiapi_wap_action_queue[MMI_MAX_MSG_ACTION_COUNT * MMI_MSG_ACTION_SIZE];
static U8 mmiapi_wap_q_head = 0;
static U8 mmiapi_wap_q_tail = 0;
static U8 mmiapi_wap_num_action = 0;

static void mmiapi_notify_message_action(kal_uint16 mod, kal_uint8 action);
static U8 mmiapi_dequeue_message_action(void *msg_struct);
static U8 mmiapi_enqueue_message_action(void *msg_struct);

extern void IdleSetStatusIcon(S16);
extern void IdleResetStatusIcon(S16);
extern void BlinkStatusIcon(S16);

#if defined(MMS_SUPPORT) && defined(OBIGO_Q03C) && defined(OBIGO_MMS)
extern void widget_config_mms_icon(kal_uint8 statusType);
#endif

/*****************************************************************************
 * FUNCTION
 *  mmiapi_dequeue_message_action
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_struct      [?]     
 * RETURNS
 *  
 *****************************************************************************/
static U8 mmiapi_dequeue_message_action(void *msg_struct)
{
#ifdef MMI_ON_HARDWARE_P
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmiapi_wap_q_head == mmiapi_wap_q_tail)
    {
        return 0;
    }

    memcpy(msg_struct, mmiapi_wap_action_queue + (mmiapi_wap_q_head * MMI_MSG_ACTION_SIZE), MMI_MSG_ACTION_SIZE);

    if (++mmiapi_wap_q_head == MMI_MAX_MSG_ACTION_COUNT)
    {
        mmiapi_wap_q_head = 0;
    }
    mmiapi_wap_num_action--;

    return 1;
#endif /* MMI_ON_HARDWARE_P */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_enqueue_message_action
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_struct      [?]     
 * RETURNS
 *  
 *****************************************************************************/
static U8 mmiapi_enqueue_message_action(void *msg_struct)
{
#ifdef MMI_ON_HARDWARE_P
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmiapi_wap_num_action == MMI_MAX_MSG_ACTION_COUNT)
    {
        return 0;
    }

    memcpy(mmiapi_wap_action_queue + (mmiapi_wap_q_tail * MMI_MSG_ACTION_SIZE), msg_struct, MMI_MSG_ACTION_SIZE);

    if (++mmiapi_wap_q_tail == MMI_MAX_MSG_ACTION_COUNT)
    {
        mmiapi_wap_q_tail = 0;
    }
    mmiapi_wap_num_action++;

    return 1;
#endif /* MMI_ON_HARDWARE_P */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_notify_message_action
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mod         [IN]        
 *  action      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmiapi_notify_message_action(kal_uint16 mod, kal_uint8 action)
{
#ifdef MMI_ON_HARDWARE_P
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmiapi_action_notify_ind_struct *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = mod;
    Message.oslMsgId = MSG_ID_MMIAPI_ACTION_NOTIFY_IND;
    rsp = (mmiapi_action_notify_ind_struct*) OslConstructDataPtr(sizeof(mmiapi_action_notify_ind_struct));
    rsp->action_type = action;
    Message.oslDataPtr = (oslParaType*) rsp;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
#endif /* MMI_ON_HARDWARE_P */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_message_action_register_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_message_action_register_ind(void *msg)
{
#ifdef MMI_ON_HARDWARE_P
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmiapi_action_register_ind_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = (mmiapi_action_register_ind_struct*) msg;

    if (!isInCall())
    {
        mmiapi_notify_message_action((kal_uint16) req->src_mod_id, (kal_uint8) req->action_type);
    }
    else
    {
        mmiapi_action_msg_struct msg_struct;

        msg_struct.action_type = req->action_type;
        msg_struct.src_mod_id = req->src_mod_id;
        mmiapi_enqueue_message_action(&msg_struct);
    }
#endif /* MMI_ON_HARDWARE_P */ 
}


/*****************************************************************************
 * FUNCTION
 *  MMIProcessActionMsg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MMIProcessActionMsg(void)
{
#ifdef MMI_ON_HARDWARE_P
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmiapi_action_msg_struct msg_struct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (mmiapi_dequeue_message_action(&msg_struct) != 0)
    {
        mmiapi_notify_message_action(msg_struct.src_mod_id, msg_struct.action_type);
    }
#endif /* MMI_ON_HARDWARE_P */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_get_num_message_action
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmiapi_get_num_message_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmiapi_wap_num_action;
}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_unread_push_icon_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_unread_push_icon_ind(void *msg)
{
#ifdef MMI_ON_HARDWARE_P
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmiapi_unread_push_icon_ind_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = (mmiapi_unread_push_icon_ind_struct*) msg;

    if (req->on_off == KAL_TRUE && mmi_bootup_is_sim_removed() == MMI_FALSE)    /* push button */
    {
        IdleSetStatusIcon(STATUS_ICON_WAP);
    }
    else    /* remove button */
    {
        IdleResetStatusIcon(STATUS_ICON_WAP);
    }
#endif /* MMI_ON_HARDWARE_P */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_mms_icon_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_mms_icon_ind(void *msg)
{
#ifdef MMI_ON_HARDWARE_P
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmiapi_mms_icon_ind_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = (mmiapi_mms_icon_ind_struct*) msg;
#if defined(MMS_SUPPORT) && defined(OBIGO_Q03C) && defined(OBIGO_MMS)
    widget_config_mms_icon(req->type);
#endif
    UpdateStatusIcons();
    /*
     * We don't blt full screen here because
     * it may be in widget's MsfDialog (prompt type) and wants to update mms icon
     * but MMI task may process widget_MMI_on_window_focus_changed() first and then
     * process mms_icon_ind.
     * In widget_MMI_on_window_focus_changed(), widget will release non-base layer.
     * If we blt fullscreen here, it will cause some layer's data will miss.
     */
#endif /* MMI_ON_HARDWARE_P */ 
}


/*****************************************************************************
 * FUNCTION
 *  GetMsgCount
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 GetMsgCount(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmiapi_wap_num_action;
}

