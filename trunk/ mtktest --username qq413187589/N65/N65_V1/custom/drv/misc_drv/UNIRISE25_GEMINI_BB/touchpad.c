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
 *    TouchPad.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is defined for keypad table
 *
 * Author:msz00184
 * -------
 * 
 *
 *============================================================================
*/

#if (defined(TOUCH_PAD_SUPPORT) && defined(__MTK_TARGET__))

#include "touchpad_custom.h"

extern kal_int32 EINT_SW_Debounce_Modify(kal_uint8 eintno, kal_uint8 debounce_time);
extern module_type UART_GetOwnerID(UART_PORT);
extern void UART_ClrRxBuffer(UART_PORT port, module_type ownerid);

extern kbd_buffer_struct kbd_buffer; 
extern kal_bool kbd_push_assert;
extern kal_uint8 kbd_owner_stat;

extern const kal_uint8 touchpad_key_map[MAX_TOUCHPAD_KEY];
kal_uint8 touchpad_input_key[TOUCHPAD_MAX_UART_LENGTH];
//kal_uint8 touchpad_press_count = 0;
kal_bool touchpad_eint_status = LEVEL_LOW;
//kal_bool	touchpad_status = TOUCHPAD_KEY_UP_STATE;    //default state: up
kal_bool touchpad_send_key_up = KAL_FALSE;   //default state: up
kal_uint8 touchpad_gpthandle;
kal_uint8 touchpad_last_key;
kal_uint8 touchpad_eint_no;
//-----------------------------------------------------------------------------

void touchpad_uart_configure(unsigned baud)
{
    UARTDCBStruct dcb = {
        UART_BAUD_38400,    /* init */
        len_8,      /* dataBits; */
        sb_1,       /* stopBits; */
        pa_none,    /* parity; */
        fc_none,
        0x11,   /* xonChar; */
        0x13,   /* xoffChar; */
        KAL_FALSE
    };

    dcb.baud = (UART_baudrate) baud;
    UART_SetDCBConfig(TOUCHPAD_UART_PORT, &dcb, MOD_TOUCHPAD);
}
//-----------------------------------------------------------------------------

void touchpad_RepeatHandler(void *parameter)
{
    kal_uint8      roomleft;
    ilm_struct*	touchpad_ilm = NULL;

    IRQMask(IRQ_KPAD_CODE);
    kbdbuffer_get_roomleft(roomleft);
    #ifdef KBD_DBGMODE
       ASSERT(roomleft != 0);
    #endif
    if (roomleft <= 1)
    {
       GPTI_StartItem(touchpad_gpthandle,
               KBD.repeat_time,
               touchpad_RepeatHandler,
               NULL);

       IRQUnmask(IRQ_KPAD_CODE);
       return;
    }
    kbd_push_onekey_to_kbdbuffer(kbd_onekey_repeated, touchpad_last_key);
    IRQUnmask(IRQ_KPAD_CODE);

    if (send_kbdilm) {
        send_kbdilm = KAL_FALSE;
        DRV_BuildPrimitive(touchpad_ilm, MOD_TOUCHPAD, MOD_UEM, MSG_ID_DRVUEM_KEYPAD_IND, NULL);
        msg_send_ext_queue(touchpad_ilm);
    }

    GPTI_StartItem(touchpad_gpthandle, KBD.repeat_time, touchpad_RepeatHandler, NULL);
}
//-----------------------------------------------------------------------------

void touchpad_LongPressHandler(void *parameter)
{
    kal_uint8      roomleft;
    ilm_struct*	touchpad_ilm = NULL;

    IRQMask(IRQ_KPAD_CODE);
    kbdbuffer_get_roomleft(roomleft);
    #ifdef KBD_DBGMODE
       ASSERT(roomleft != 0);
    #endif
    if (roomleft <= 1)
    {
       GPTI_StartItem(touchpad_gpthandle,
               KBD.longpress_timeout,
               touchpad_LongPressHandler,
               NULL);

       IRQUnmask(IRQ_KPAD_CODE);
       return;
    }
    kbd_push_onekey_to_kbdbuffer(kbd_onekey_longpress, touchpad_last_key);
    IRQUnmask(IRQ_KPAD_CODE);

    if (send_kbdilm) {
        send_kbdilm = KAL_FALSE;
        DRV_BuildPrimitive(touchpad_ilm, MOD_TOUCHPAD, MOD_UEM, MSG_ID_DRVUEM_KEYPAD_IND, NULL);
        msg_send_ext_queue(touchpad_ilm);
    }

    GPTI_StartItem(touchpad_gpthandle, KBD.repeat_time, touchpad_RepeatHandler, NULL);
}
//-----------------------------------------------------------------------------

kal_uint8 touchpad_get_keys(void)
{
    kal_uint8 key = 0;
    kal_uint8 key_position = 0xFF;
    kal_uint8 j, count_key = 0;
    kal_uint16 touchpad_temp_key;
    // kal_uint8 touchpad_eint_no = custom_eint_get_channel( touchpad_eint_chann );

    touchpad_temp_key = (touchpad_input_key[0] & 0x3F) | ((touchpad_input_key[1] & 0x0F) << 6);
    for (j = 0; j < 10; j++) {
        if (touchpad_temp_key & (1 << j)) {
            key_position = j;
            count_key++;

            #if defined(TOUCHPAD_DEBUG)	
                kal_prompt_trace(MOD_ENG, "count_key++ ");
            #endif
        }
    }
    if (touchpad_send_key_up == KAL_TRUE)
    {
      GPTI_StopItem(touchpad_gpthandle);

      IRQMask(IRQ_GPT_CODE);
      IRQMask(IRQ_KPAD_CODE);
      kbd_push_onekey_to_kbdbuffer(WM_KEYRELEASE, touchpad_last_key);
      if (count_key!=1)
      {
         kbd_owner_stat = KBD_OWNER_NONE;
         touchpad_send_key_up = KAL_FALSE;
      }
      else
      {
         kal_uint8 roomleft;

         kbdbuffer_get_roomleft(roomleft);
         #ifdef KBD_DBGMODE
            ASSERT(roomleft!=0);
         #endif
         if (roomleft<2)
         {
            count_key = 0;
            kbd_owner_stat = KBD_OWNER_NONE;
            touchpad_send_key_up = KAL_FALSE;
         }
         else
         {
            key = touchpad_key_map[ key_position];
            kbd_push_onekey_to_kbdbuffer(WM_KEYPRESS, key);
            touchpad_last_key = key;
         }
      }
      IRQUnmask(IRQ_KPAD_CODE);
      IRQUnmask(IRQ_GPT_CODE);

      if (count_key == 1)
      {
        GPTI_StartItem(touchpad_gpthandle, KBD.longpress_timeout, touchpad_LongPressHandler, NULL);
      }
      //touchpad_press_count = count_key;
      //EINT_UnMask(touchpad_eint_no);
      return 1;
    }
    else
    {
       kal_uint8 roomleft;

       kbdbuffer_get_roomleft(roomleft);
       #ifdef KBD_DBGMODE
          ASSERT(roomleft!=0);
       #endif
       /* Only accept one key. */
       if ((count_key != 1) || (roomleft < 2))
       {
          kbd_owner_stat = KBD_OWNER_NONE;
          return 0;
       }
        key = touchpad_key_map[ key_position];
        touchpad_last_key = key;

        GPTI_StartItem(touchpad_gpthandle, KBD.longpress_timeout, touchpad_LongPressHandler, NULL);

        #if defined(TOUCHPAD_DEBUG)
            kal_prompt_trace(MOD_ENG, "(touchpad) Event Code : %d", key);
        #endif

        IRQMask(IRQ_GPT_CODE);
        IRQMask(IRQ_KPAD_CODE); 
        kbd_push_onekey_to_kbdbuffer(WM_KEYPRESS, key);
        IRQUnmask(IRQ_KPAD_CODE);
        IRQUnmask(IRQ_GPT_CODE);

        touchpad_send_key_up = KAL_TRUE;
		  //touchpad_press_count = count_key;
        //EINT_UnMask(touchpad_eint_no);
        return 1;
    }

    #if defined(TOUCHPAD_DEBUG)	
        kal_prompt_trace(MOD_ENG, "count_key= %d", count_key);
        kal_prompt_trace(MOD_ENG, "key_position= %d", key_position);
    #endif

    //touchpad_press_count=count_key;
    //EINT_UnMask(touchpad_eint_no);
    return 0;
}

/*****************************************************************************
* FUNCTION :		Touchpad_HISR
*   
* DESCRIPTION:
*   				Touch keypad LISR
* PARAMETERS:
*   				void
* RETURNS:
*  				boid 
* GLOBALS AFFECTED:
*   				None
*****************************************************************************/
void Touchpad_HISR(void)
{
//	kal_uint8 touchpad_eint_no = custom_eint_get_channel(touchpad_eint_chann);

    TOUCHPAD_UART_PutBytes(TOUCHPAD_UART_PORT, 0x50);

    //touchpad_eint_status = !touchpad_eint_status;
    //EINT_Set_Polarity(touchpad_eint_no, touchpad_eint_status);

//	touchpad_status=!touchpad_status;
    //if(touchpad_status==TOUCHPAD_KEY_UP_STATE)
    GPTI_StopItem(touchpad_gpthandle);
} 
//-----------------------------------------------------------------------------

kal_uint16 touchpad_uart_read_data(kal_uint8 port, kal_uint16 len)
{
    kal_uint16 result;

    /* here's we really read the data from UART */
    result = TOUCHPAD_UART_GetBytes(port, (kal_uint8*) touchpad_input_key, len, NULL, MOD_TOUCHPAD);

    if (result != len) {
        touchpad_input_key[0] = 0;
        touchpad_input_key[1] = 0;
    }

    #if defined(TOUCHPAD_DEBUG)
        kal_prompt_trace(MOD_ENG, "touchpad_input_key[0]= %x", touchpad_input_key[0]);
        kal_prompt_trace(MOD_ENG, "touchpad_input_key[1]= %x", touchpad_input_key[1]);
        kal_prompt_trace(MOD_ENG, "result= %x", result);
    #endif

   return result;
}
//-----------------------------------------------------------------------------

kal_bool touchpad_read_from_uart(kal_uint8 port)
{
    /*
    if (port == uart_port_null) {
        return;
    }

    if (UART_GetOwnerID(port) != MOD_TOUCHPAD) {
        return;
    }
    */
    if (kbd_owner_stat == KBD_OWNER_TOUCHPAD)
    {
      kal_uint16   ret_len;
      ret_len = touchpad_uart_read_data(port, TOUCHPAD_MAX_UART_LENGTH);
      return (ret_len == TOUCHPAD_MAX_UART_LENGTH)? KAL_TRUE:KAL_FALSE;
    }
    else
    {
      UART_ClrRxBuffer(TOUCHPAD_UART_PORT, MOD_TOUCHPAD);
      touchpad_input_key[0] = 0;
      touchpad_input_key[1] = 0;
      return KAL_FALSE;
    }

}
//-----------------------------------------------------------------------------

void touchpad_uart_ready_to_write_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
}
//-----------------------------------------------------------------------------

void touchpad_uart_ready_to_read_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    uart_ready_to_read_ind_struct* msg_ptr = NULL;
    msg_ptr = (uart_ready_to_read_ind_struct*) local_para_ptr;
    touchpad_read_from_uart(msg_ptr->port);

    return;
}
//-----------------------------------------------------------------------------

extern kal_uint8 send_Rxilm[MAX_UART_PORT_NUM];

void touchpad_uart_rx_cb(UART_PORT port)
{
    ilm_struct *msg;
    ASSERT(port == TOUCHPAD_UART_PORT);

    if (send_Rxilm[port]) { /* RX indication has been sent */
        msg = allocate_ilm(MOD_UART1_HISR + TOUCHPAD_UART_PORT - uart_port1);
        msg->src_mod_id = MOD_UART1_HISR + TOUCHPAD_UART_PORT - uart_port1;
        msg->dest_mod_id = MOD_TOUCHPAD;
        msg->sap_id = INVALID_SAP;
        msg->msg_id = MSG_ID_UART_READY_TO_READ_IND;
        msg->local_para_ptr = NULL;
        msg->peer_buff_ptr = NULL;
        msg_send_ext_queue(msg);
        send_Rxilm[port] = KAL_FALSE;
    }
}
//-----------------------------------------------------------------------------

void touchpad_uart_register_cb(void)
{
#ifdef __MTK_TARGET__
    UART_Register_RX_cb(TOUCHPAD_UART_PORT, MOD_TOUCHPAD, touchpad_uart_rx_cb);
#endif
}
//-----------------------------------------------------------------------------

void uart_close_tst_if_touchpad_use(void)
{    
    extern kal_bool tst_is_L1Trc_open;
    extern kal_bool tst_is_PsTrc_open;
    extern UART_PORT TST_PORT;
    extern UART_PORT tst_L1Trc_port;
    extern UART_PORT tst_PsTrc_port;
    
    if (tst_L1Trc_port == TST_PORT) {
        tst_is_L1Trc_open = KAL_FALSE;
    }

    if (tst_PsTrc_port == TST_PORT) {
        tst_is_PsTrc_open = KAL_FALSE;
    }
}

/*****************************************************************************
* FUNCTION :
*   Touchpad_PowerOn
*
* DESCRIPTION:
*   This function power on/off touchpad controller
*
* PARAMETERS:
*   bOn : TRUE -> power on controller,
*         FALSE -> power off controller
*
* RETURNS:
*   None
*
* GLOBALS AFFECTED:
*   None
*****************************************************************************/
void Touchpad_PowerOn(const kal_bool bOn)
{
    GPIO_ModeSetup(TOUCH_PAD_KEY_LDO_POWER, 0);
    GPIO_InitIO(OUTPUT, TOUCH_PAD_KEY_LDO_POWER);
    GPIO_WriteIO(bOn ? 1 : 0, TOUCH_PAD_KEY_LDO_POWER);

    UART_TurnOnPower(TOUCHPAD_UART_PORT, bOn);
}
//-----------------------------------------------------------------------------

/*****************************************************************************
* FUNCTION :
*   Touchpad_AutoLowPowerMode
*
* DESCRIPTION:
*   This function controls low power mode
*
* PARAMETERS:
*   bOn : TRUE -> automatic low power mode (power saving)
*         FALSE -> always normal mode
*
* RETURNS:
*   None
*
* GLOBALS AFFECTED:
*   None
*****************************************************************************/
void Touchpad_AutoLowPowerMode(const kal_bool bOn)
{
    // TOUCH_PAD_KEY_LOW_POWER keeps high, the touchpad controller will
    // enter low power mode after each detection done
    GPIO_ModeSetup(TOUCH_PAD_KEY_LOW_POWER, 0);
    GPIO_InitIO(OUTPUT, TOUCH_PAD_KEY_LOW_POWER);
    GPIO_WriteIO(bOn ? 1 : 0, TOUCH_PAD_KEY_LOW_POWER);
}

/*****************************************************************************
* FUNCTION :
*   Touchpad_Init
*
* DESCRIPTION:
*   This function initializes touchpad setting
*
* PARAMETERS:
*   NONE
*
* RETURNS:
*   None
*
* GLOBALS AFFECTED:
*   None
*****************************************************************************/
void Touchpad_Init(void)
{
    kal_bool bSuccess = KAL_FALSE;

    GPTI_GetHandle(&touchpad_gpthandle);

    if (UART_GetOwnerID(TOUCHPAD_UART_PORT) == MOD_TST ||
        UART_GetOwnerID(TOUCHPAD_UART_PORT) == MOD_TST_READER) {
        uart_close_tst_if_touchpad_use();
    }

//    UART_Close(TOUCHPAD_UART_PORT, MOD_TOUCHPAD);   // Kerwin 10/29
    UART_Close(TOUCHPAD_UART_PORT, UART_GetOwnerID(TOUCHPAD_UART_PORT));   // Kerwin 10/29

    // bind UART port to TOUCHPAD task
    bSuccess = UART_Open(TOUCHPAD_UART_PORT, MOD_TOUCHPAD);
    ASSERT(bSuccess == KAL_TRUE);

    #if defined(TOUCHPAD_DEBUG)
        kal_prompt_trace(MOD_ENG, "uart_open_result= %d", bSuccess);
    #endif

    touchpad_uart_configure(TOUCHPAD_UART_BAUD_RATE);

    touchpad_uart_register_cb();    // should not use the default callback funtion, or it will cause the ctrl buffer-----construct local para, then cause fatal error

/*
    //EINT_Registration( touchpad_eint_no, KAL_TRUE, LEVEL_LOW, Touchpad_HISR, KAL_TRUE );
    //  EINT_Registration( touchpad_eint_no, KAL_TRUE, touchpad_eint_status, Touchpad_HISR, KAL_TRUE );
    #if defined(TOUCH_PAD_USE_KEY_COLUMN)
        //  EINT_Registration( touchpad_eint_no, KAL_TRUE, touchpad_eint_status, Touchpad_HISR, KAL_FALSE);
    #else
        EINT_Registration( touchpad_eint_no, KAL_TRUE, touchpad_eint_status, Touchpad_HISR, KAL_TRUE);
        //EINT_Registration( touchpad_eint_no, KAL_TRUE, touchpad_eint_status, Touchpad_HISR, KAL_FALSE );
        EINT_Set_HW_Debounce(touchpad_eint_no, 2);
        EINT_SW_Debounce_Modify(touchpad_eint_no,2);                              
        EINT_UnMask(touchpad_eint_no); 
    #endif
*/
    Touchpad_PowerOn(KAL_TRUE);
    Touchpad_AutoLowPowerMode(KAL_TRUE);
}
//-----------------------------------------------------------------------------

void touchpad_main(task_entry_struct* task_entry_ptr)
{
    ilm_struct current_ilm;
    ilm_struct* ilm_ptr = &current_ilm;
	ilm_struct* touchpad_ilm;
    kal_uint16 get_key_result;

    Touchpad_Init();

    while(1) {
        receive_msg_ext_q(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm);

		switch (ilm_ptr->msg_id) {
        case MSG_ID_UART_READY_TO_READ_IND:
           while(1)
           {
              kal_bool more_data;

               more_data = touchpad_read_from_uart(TOUCHPAD_UART_PORT);
               if (more_data == KAL_FALSE)
                  break;
               //UART_GetBytes(TOUCHPAD_UART_PORT,touchpad_input_key,2,NULL,MOD_TOUCHPAD);
               //UART_ClrRxBuffer(TOUCHPAD_UART_PORT);
               get_key_result = touchpad_get_keys();

               #if defined(TOUCHPAD_DEBUG)
                   kal_prompt_trace(MOD_ENG, "get_key_result= %d", get_key_result);
               #endif
               if (get_key_result) {
                   if (send_kbdilm) {
                       send_kbdilm = KAL_FALSE;
                       DRV_BuildPrimitive(touchpad_ilm, MOD_TOUCHPAD, MOD_UEM, MSG_ID_DRVUEM_KEYPAD_IND, NULL);
                       msg_send_ext_queue(touchpad_ilm);
                   }
               }
           }
            break;

        case MSG_ID_UART_READY_TO_WRITE_IND:
            break;

        default:
            #if defined(TOUCHPAD_DEBUG)
                kal_prompt_trace(MOD_ENG, "Unknow Message__touchpad");  // nknow Message received
            #endif
            break;
        }
    }
}
//-----------------------------------------------------------------------------

kal_bool touchpad_task_reset(task_indx_type task_indx)
{
    /****************************************************************
    * Do task's reset here.                                         *
    * Notice that: shouldn't execute modules reset handler since    *
    * stack_task_reset() will do.                                   *
    ****************************************************************/
    return KAL_TRUE;
}

/*************************************************************************
* FUNCTION
*	
*
* DESCRIPTION
*	
*
* PARAMETERS
*	task_index	-	task's index
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool touchpad_task_end(task_indx_type task_indx)
{
    /****************************************************************
    * Do task's termination here.                                   *
    * Notice that: shouldn't execute modules reset handler since    *
    * stack_task_end() will do.                                     *
    ****************************************************************/
    return KAL_TRUE;
}
//-----------------------------------------------------------------------------

kal_bool Touchpad_Task_Create(comptask_handler_struct** handle)
{
    static const comptask_handler_struct touchpad_handler_info = {
        touchpad_main,  /* task entry function */
        NULL,   /* task initialization function */
        NULL,   /* task configuration function */
        touchpad_task_reset,    /* task reset handler */
        touchpad_task_end   /* task termination handler */
    };

    *handle = (comptask_handler_struct *) &touchpad_handler_info;

    return KAL_TRUE;
}
//-----------------------------------------------------------------------------

kal_bool custom_touchpad_task_create(comptask_handler_struct **handle)
{
#if defined(TOUCH_PAD_SUPPORT)
    return Touchpad_Task_Create(handle);
#else
    return KAL_FALSE;
#endif
}

#endif  /*  (defined(TOUCH_PAD_SUPPORT) && defined(__MTK_TARGET__)) */
