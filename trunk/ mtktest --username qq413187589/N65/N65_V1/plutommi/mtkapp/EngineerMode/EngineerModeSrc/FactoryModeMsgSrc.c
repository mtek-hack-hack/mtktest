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
 * FactoryModeMsgSrc.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Factory mode message handler
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
 *============================================================================
 ****************************************************************************/

#if !defined(__MTK_TARGET__)
#include <windows.h>
#endif 
#include "MMI_include.h"

/* MTK Add Robin 1001 for saperate MMI feature by project */
#include "MMI_features.h"
/* MTK End */

#ifdef __MMI_FACTORY_MODE__     /* MTK Add Robin 1001 for saperate MMI feature by project */

#include "wgui.h"
#include "IdleAppProt.h"
#include "ProtocolEvents.h"
#include "DateTimeType.h"
#include "ThrdOsInterface.h"
#include "OSThreadInterfaceGprot.h"
#include "MiscFunctions.h"
/* JL #include "MainTaskGexdcl.h" */
#include "TaskInit.h"
#include "EngineerModeDef.h"
#include "EngineerModeType.h"
#include "EngineerModeProt.h"
/* micha0202 */
#include "NetworkSetupGProt.h"
#include "wgui_status_icons.h"
#include "FactoryModeProt.h"
#include "custom_util.h"
#include "lcd_sw.h"
#include "device.h"
#include "resource_audio.h"
extern kal_int32 media_aud_stop_id(module_type src_mod_id, kal_uint8 audio_id);

/* External Funtions */
extern void EntryIdleScreen(void);
extern void FM_LCDShowColor(S32 type);

extern void mdi_audio_set_audio_mode(U8 mode);


/*****************************************************************************
 * FUNCTION
 *  FM_SetGpioReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 *  level       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void FM_SetGpioReq(U8 type, U8 level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_exe_gpio_level_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = OslConstructDataPtr(sizeof(mmi_eq_exe_gpio_level_req_struct));
    msg_p->gpio_dev_type = type;
    msg_p->gpio_dev_level = level;
    FM_SendMsg(MSG_ID_MMI_EQ_EXE_GPIO_LEVEL_REQ, msg_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  FM_SendADCStartReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_SendADCStartReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FM_SendMsg(MSG_ID_MMI_EQ_START_ADC_ALL_CHANNEL_REQ, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  FM_SendADCStopReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FM_SendADCStopReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FM_SendMsg(MSG_ID_MMI_EQ_STOP_ADC_ALL_CHANNEL_REQ, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  FM_SendKeyEventReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  status      [IN]        
 *  code        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void FM_SendKeyEventReq(U8 status, U8 code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_em_keypad_event_output_req_struct *msg_p;
    S16 drv_keycode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drv_keycode = mmi_kbd_reverse_code((S16) code);

    msg_p = OslConstructDataPtr(sizeof(mmi_em_keypad_event_output_req_struct));
    msg_p->keypad_status = status;
    msg_p->keypad_code = (U8) drv_keycode;

    FM_SendMsg(MSG_ID_MMI_EM_KEYPAD_EVENT_OUTPUT_REQ, msg_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  FM_ATEntryMenuHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void FM_ATEntryMenuHdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_factory_test_ind_struct *factory_test_struct = (mmi_factory_test_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayIdleScreen();

    if (factory_test_struct->on_off == 1)
    {
        EntryFMMenu();
    }
}


/*****************************************************************************
 * FUNCTION
 *  FM_ATLCDTestMsgHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void FM_ATLCDTestMsgHdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_em_lcm_test_ind_struct *rsp_p = (mmi_em_lcm_test_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (rsp_p->color)
    {

   /***********************/
   /** FM_LCDShowColor:  **/
   /**  0 : Auto         **/
   /**  1 : Red          **/
   /**  2 : Green        **/
   /**  3 : Blue         **/
   /**  4 : White        **/
   /***********************/

        case 0: /* R */
            EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);
            ShowCategory7Screen(0, 0, 0, 0, 0, 0, NULL, NULL);
            FM_LCDShowColor(1);
            break;

        case 1: /* G */
            EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);
            ShowCategory7Screen(0, 0, 0, 0, 0, 0, NULL, NULL);
            FM_LCDShowColor(2);
            break;

        case 2: /* B */
            EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);
            ShowCategory7Screen(0, 0, 0, 0, 0, 0, NULL, NULL);
            FM_LCDShowColor(3);
            break;

        case 3: /* W */
            EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);
            ShowCategory7Screen(0, 0, 0, 0, 0, 0, NULL, NULL);
            FM_LCDShowColor(4);
            break;

        case 4: /* Back to Idle screen */
            DisplayIdleScreen();
            EntryFMMenu();
            break;

        default:
            break;
    }
    /*
     * if (rsp_p->color_type == 1)
     * {
     * FM_EntryColorTest();
     * }
     * else
     * GoBackHistory();
     */
}


/*****************************************************************************
 * FUNCTION
 *  FM_ATKeypadTestMsgHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void FM_ATKeypadTestMsgHdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_em_keypad_event_act_ind_struct *rsp_p = (mmi_em_keypad_event_act_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Lisen 0630 */
    if (rsp_p->on_off == 1)
    {
        EntryFMKeypadTest();
    }
    else if (FM_IsInKeypadTest() == MMI_TRUE)
    {
        GoBackHistory();
    }

}


/*****************************************************************************
 * FUNCTION
 *  FM_SendPlayAudioReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void FM_SendPlayAudioReq(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_play_audio_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = OslConstructDataPtr(sizeof(mmi_eq_play_audio_req_struct));
    msg_p->sound_id = index + MIN_MIDI_ID;
    msg_p->style = DEVICE_AUDIO_PLAY_INFINITE;
    FM_SendMsg(MSG_ID_MMI_EQ_PLAY_AUDIO_REQ, msg_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  FM_SendStopAudioReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void FM_SendStopAudioReq(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * mmi_eq_stop_audio_req_struct* msg_p;
     * 
     * msg_p = OslConstructDataPtr(sizeof(mmi_eq_stop_audio_req_struct));
     * msg_p->sound_id = index+MIN_MIDI_ID;
     * FM_SendMsg(MSG_ID_MMI_EQ_STOP_AUDIO_REQ, msg_p, NULL);
     */

    media_aud_stop_id(MOD_MMI, (U8) (index + MIN_MIDI_ID));
}


/*****************************************************************************
 * FUNCTION
 *  FM_SendSetAudioModeReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mode        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void FM_SendSetAudioModeReq(U8 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_audio_set_audio_mode(mode);
}

/*****************************************************************
 **  FM Mode Send Message
 *****************************************************************/


/*****************************************************************************
 * FUNCTION
 *  FM_SendMsg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id              [IN]        
 *  local_param_ptr     [?]         
 *  peer_buf_ptr        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void FM_SendMsg(U16 msg_id, void *local_param_ptr, void *peer_buf_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->src_mod_id = MOD_MMI;
    ilm_ptr->sap_id = MMI_L4C_SAP;
    ilm_ptr->dest_mod_id = MOD_L4C;

    ilm_ptr->msg_id = (kal_uint16) msg_id;
    ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) peer_buf_ptr;

    msg_send_ext_queue(ilm_ptr);

}

#endif /* __MMI_FACTORY_MODE__ */ 

