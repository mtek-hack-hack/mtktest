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
 *  mdi_motion.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Motion sensor related interface
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
 *******************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_MOTION_APP__

#ifdef __MTK_TARGET__
   /* 
    * - For PC Simulator and MoDis, do not call media's webcam functions 
    * - For Target, call media's cam functions.
    */
#define MDI_MOTION_DRIVER_AVAIALBE
#endif /* __MTK_TARGET__ */ 

/***************************************************************************** 
* Include
*****************************************************************************/
#include "MMIDataType.h"    /* MMI Data type */
#include "debuginitdef.h"       /* MMI_ASSERT */
#include "QueueGprot.h" /* MYQUEUE */
#include "EventsGprot.h"        /* msg event hadnling */
#include "gui.h"        /* UI timer */

#include "mdi_datatype.h"       /* mdi datatype */
#include "mdi_motion.h"

#ifdef MDI_MOTION_DRIVER_AVAIALBE
#include "motion_sensor.h"      /* motion sensor driver */
#endif 

/***************************************************************************** 
* Define
*****************************************************************************/
#define MDI_MOTION_SAMPLE_PERIOD             (5)        /* value*10 ms, if 5 means 50 ms */

/* 
 * when sensitive is higher, threshold value smaller, 
 * whihc means smaller action will trigger event 
 */
#define MOTION_SHAKE_THRESHOLD_HIGH             (500)
#define MOTION_SHAKE_THRESHOLD_NORMAL           (1000)
#define MOTION_SHAKE_THRESHOLD_LOW              (1500)

#define MOTION_TILE_THRESHOLD_HIGH              (500)
#define MOTION_TILE_THRESHOLD_NORMAL            (1000)
#define MOTION_TILE_THRESHOLD_LOW               (1500)

#define MOTION_THRESHOLD_HIGH_MUTE_DURATION     (300)
#define MOTION_THRESHOLD_NORMAL_MUTE_DURATION   (300)
#define MOTION_THRESHOLD_LOW_MUTE_DURATION      (300)

/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef struct
{
    mdi_motion_tile_callback tile_callback;
    mdi_motion_shake_callback shake_callback;

    U16 sensitve;
    S32 min_time;
    S32 max_time;

    U16 sense_type;
    U16 state;
    S32 prev_x_acc;
    S32 prev_y_acc;
    S32 prev_z_acc;

    BOOL is_msg_send;
    BOOL is_mute;
} mdi_motion_cntx_struct;

typedef struct
{
    LOCAL_PARA_HDR U16 data_state;
} mdi_motion_msg_struct;

typedef enum
{
    MOTION_SENSE_SHAKE,
    MOTION_SENSE_TILE
} mdi_motion_sense_type_enum;

typedef enum
{
    MOTION_DATA_EPMTY,
    MOTION_DATA_FULL,
    MOTION_DATA_EXIST
} mdi_motion_data_state_enum;

typedef enum
{
    MOTION_STATE_POWER_OFF,
    MOTION_STATE_IDLE,
    MOTION_STATE_LISTENING
} mdi_motion_state_enum;

/***************************************************************************** 
* Global Variable
*****************************************************************************/

/***************************************************************************** 
* Global Function
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/
mdi_motion_cntx_struct g_mdi_motion_cntx;

/***************************************************************************** 
* Local Function
*****************************************************************************/
#ifdef MDI_MOTION_DRIVER_AVAIALBE
static void mdi_motion_shake_data_hdlr(void *msg_ptr);
static void mdi_motion_tile_data_hdlr(void *msg_ptr);
static void mdi_motion_disable_mute_timeout(void);
static void mdi_motion_driver_data_state_hdlr(void *parameter, Motion_Sensor_BuffState_enum state);
#endif /* MDI_MOTION_DRIVER_AVAIALBE */ 


/*****************************************************************************
 * FUNCTION
 *  mdi_motion_init
 * DESCRIPTION
 *  init MDI Camera
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_motion_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mdi_motion_cntx.state = MOTION_STATE_POWER_OFF;

    return MDI_RES_MOTION_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_motion_power_on
 * DESCRIPTION
 *  power on
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_motion_power_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* var init */
    g_mdi_motion_cntx.shake_callback = NULL;
    g_mdi_motion_cntx.tile_callback = NULL;

    g_mdi_motion_cntx.prev_x_acc = 0;
    g_mdi_motion_cntx.prev_y_acc = 0;
    g_mdi_motion_cntx.prev_z_acc = 0;
    g_mdi_motion_cntx.is_msg_send = FALSE;

#ifdef MDI_MOTION_DRIVER_AVAIALBE

    motion_sensor_power(TRUE);
    motion_sensor_conf_sample_period(MDI_MOTION_SAMPLE_PERIOD);
    motion_sensor_flush_buff();

#endif /* MDI_MOTION_DRIVER_AVAIALBE */ 

    g_mdi_motion_cntx.state = MOTION_STATE_IDLE;

    return MDI_RES_MOTION_SUCCEED;

}


/*****************************************************************************
 * FUNCTION
 *  mdi_motion_power_off
 * DESCRIPTION
 *  power off
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_motion_power_off(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MDI_MOTION_DRIVER_AVAIALBE
    motion_sensor_power(FALSE);

    g_mdi_motion_cntx.state = MOTION_STATE_POWER_OFF;

#endif /* MDI_MOTION_DRIVER_AVAIALBE */ 

    return MDI_RES_MOTION_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_motion_start_listen_shake
 * DESCRIPTION
 *  listen to shake event
 * PARAMETERS
 *  sensitive                   [IN]        
 *  shake_event_callback        [IN]        Event callback
 *  senstive(?)                 [IN]        Sensitivity
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_motion_start_listen_shake(U16 sensitive, mdi_motion_shake_callback shake_event_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 threshold;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(shake_event_callback != NULL);

    g_mdi_motion_cntx.shake_callback = shake_event_callback;
    g_mdi_motion_cntx.sense_type = MOTION_SENSE_SHAKE;
    g_mdi_motion_cntx.sensitve = sensitive;
    g_mdi_motion_cntx.state = MOTION_STATE_LISTENING;
    g_mdi_motion_cntx.is_mute = FALSE;

    switch (g_mdi_motion_cntx.sensitve)
    {
        case MDI_MOTION_SENSITIVE_HIGH:
            threshold = MOTION_SHAKE_THRESHOLD_HIGH;
            break;

        case MDI_MOTION_SENSITIVE_NORMAL:
            threshold = MOTION_SHAKE_THRESHOLD_NORMAL;
            break;

        case MDI_MOTION_SENSITIVE_LOW:
            threshold = MOTION_SHAKE_THRESHOLD_LOW;
            break;
    }

#ifdef MDI_MOTION_DRIVER_AVAIALBE
    /* register callback to retrive data */
    motion_sensor_cb_registration(mdi_motion_driver_data_state_hdlr, NULL);
    SetProtocolEventHandler(mdi_motion_shake_data_hdlr, MSG_ID_MDI_MOTION_DATA_STATE_RSP);
    motion_sensor_conf_filter(threshold);

    /* star sampling */
    motion_sensor_sample(TRUE);
#endif /* MDI_MOTION_DRIVER_AVAIALBE */ 

    return MDI_RES_MOTION_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_motion_start_listen_tile
 * DESCRIPTION
 *  listen to tile event
 * PARAMETERS
 *  sensitive               [IN]        
 *  min_callback_time       [IN]        Min callback time
 *  max_callback_time       [IN]        Max callback time
 *  tile_event_callback     [IN]        Event callback
 *  senstive(?)             [IN]        Sensitivity
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_motion_start_listen_tile(
            U16 sensitive,
            S32 min_callback_time,
            S32 max_callback_time,
            mdi_motion_tile_callback tile_event_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 threshold;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mdi_motion_cntx.tile_callback = tile_event_callback;
    g_mdi_motion_cntx.sense_type = MOTION_SENSE_TILE;
    g_mdi_motion_cntx.sensitve = sensitive;
    g_mdi_motion_cntx.min_time = min_callback_time;
    g_mdi_motion_cntx.max_time = max_callback_time;
    g_mdi_motion_cntx.state = MOTION_STATE_LISTENING;
    g_mdi_motion_cntx.is_mute = FALSE;

    switch (g_mdi_motion_cntx.sensitve)
    {
        case MDI_MOTION_SENSITIVE_HIGH:
            threshold = MOTION_TILE_THRESHOLD_HIGH;
            break;

        case MDI_MOTION_SENSITIVE_NORMAL:
            threshold = MOTION_TILE_THRESHOLD_NORMAL;
            break;

        case MDI_MOTION_SENSITIVE_LOW:
            threshold = MOTION_TILE_THRESHOLD_LOW;
            break;
    }

#ifdef MDI_MOTION_DRIVER_AVAIALBE
    /* register callback to retrive data */
    motion_sensor_cb_registration(mdi_motion_driver_data_state_hdlr, NULL);
    SetProtocolEventHandler(mdi_motion_tile_data_hdlr, MSG_ID_MDI_MOTION_DATA_STATE_RSP);
    motion_sensor_conf_filter(threshold);

    /* star sampling */
    motion_sensor_sample(TRUE);
#endif /* MDI_MOTION_DRIVER_AVAIALBE */ 

    return MDI_RES_MOTION_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_motion_stop_listen
 * DESCRIPTION
 *  stop listen to event
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_motion_stop_listen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mdi_motion_cntx.shake_callback = NULL;
    g_mdi_motion_cntx.tile_callback = NULL;
    g_mdi_motion_cntx.state = MOTION_STATE_IDLE;

#ifdef MDI_MOTION_DRIVER_AVAIALBE
    gui_cancel_timer(mdi_motion_disable_mute_timeout);
    SetProtocolEventHandler(NULL, MSG_ID_MDI_MOTION_DATA_STATE_RSP);
#endif /* MDI_MOTION_DRIVER_AVAIALBE */ 

    return MDI_RES_MOTION_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_motion_disable_mute_timeout
 * DESCRIPTION
 *  disable timeout, enable sence again
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef MDI_MOTION_DRIVER_AVAIALBE
static void mdi_motion_disable_mute_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mdi_motion_cntx.is_mute = FALSE;
}
#endif /* MDI_MOTION_DRIVER_AVAIALBE */ 


/*****************************************************************************
 * FUNCTION
 *  mdi_motion_driver_data_state_hdlr
 * DESCRIPTION
 *  callback function to handler driver's data state change.
 *  this function will be under driver's HISR. so only send message to MMI
 * PARAMETERS
 *  parameter       [IN]        Para
 *  state           [IN]        Data state
 * RETURNS
 *  MDI_RESULT(?)
 *****************************************************************************/
#ifdef MDI_MOTION_DRIVER_AVAIALBE
static void mdi_motion_driver_data_state_hdlr(void *parameter, Motion_Sensor_BuffState_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE message;
    mdi_motion_msg_struct *msg_data_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mdi_motion_cntx.state != MOTION_STATE_LISTENING)
    {
        return;
    }

    if (g_mdi_motion_cntx.is_msg_send == TRUE)
    {
        return;
    }

    if (state == BUFF_EMPTY)
    {
        return;
    }

    msg_data_ptr = OslConstructDataPtr(sizeof(mdi_motion_msg_struct));

    switch (state)
    {
        case BUFF_DATA_EXIST:
            msg_data_ptr->data_state = MOTION_DATA_EXIST;
            break;

        case BUFF_FULL:
            msg_data_ptr->data_state = MOTION_DATA_FULL;
            break;
    }

    message.oslMsgId = MSG_ID_MDI_MOTION_DATA_STATE_RSP;
    message.oslDataPtr = (oslParaType*) msg_data_ptr;
    message.oslPeerBuffPtr = NULL;
    message.oslSrcId = MOD_MMI;
    message.oslDestId = MOD_MMI;

    OslMsgSendExtQueue(&message);

    g_mdi_motion_cntx.is_msg_send = TRUE;

}
#endif /* MDI_MOTION_DRIVER_AVAIALBE */ 


/*****************************************************************************
 * FUNCTION
 *  mdi_motion_shake_data_hdlr
 * DESCRIPTION
 *  shake event data handler
 * PARAMETERS
 *  msg_ptr     [IN]        Msg data pointer
 * RETURNS
 *  MDI_RESULT(?)
 *****************************************************************************/
#ifdef MDI_MOTION_DRIVER_AVAIALBE
static void mdi_motion_shake_data_hdlr(void *msg_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 threshold;
    mdi_motion_msg_struct *msg_data_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mdi_motion_cntx.state != MOTION_STATE_LISTENING)
    {
        g_mdi_motion_cntx.is_msg_send = FALSE;
        return;
    }

    if (g_mdi_motion_cntx.shake_callback == NULL)
    {
        g_mdi_motion_cntx.is_msg_send = FALSE;
        return;
    }

    if (g_mdi_motion_cntx.is_mute == TRUE)
    {
        /* is mute, flush data */
        motion_sensor_flush_buff();
        g_mdi_motion_cntx.is_msg_send = FALSE;
        return;
    }

    msg_data_ptr = (mdi_motion_msg_struct*) msg_ptr;

    if (msg_data_ptr->data_state == MOTION_DATA_EPMTY)
    {
        return;
    }

    switch (g_mdi_motion_cntx.sensitve)
    {
        case MDI_MOTION_SENSITIVE_HIGH:
            threshold = MOTION_SHAKE_THRESHOLD_HIGH;
            break;

        case MDI_MOTION_SENSITIVE_NORMAL:
            threshold = MOTION_SHAKE_THRESHOLD_NORMAL;
            break;

        case MDI_MOTION_SENSITIVE_LOW:
            threshold = MOTION_SHAKE_THRESHOLD_LOW;
            break;
    }

    /* if has buffer, get data and text if pass threshold or not */
    if ((msg_data_ptr->data_state == MOTION_DATA_EXIST) || (msg_data_ptr->data_state == MOTION_DATA_FULL))
    {
        motion_sensor_flush_buff();
        g_mdi_motion_cntx.shake_callback();
        g_mdi_motion_cntx.is_mute = TRUE;

        switch (g_mdi_motion_cntx.sensitve)
        {
            case MDI_MOTION_SENSITIVE_HIGH:
                gui_start_timer(MOTION_THRESHOLD_HIGH_MUTE_DURATION, mdi_motion_disable_mute_timeout);
                break;

            case MDI_MOTION_SENSITIVE_NORMAL:
                gui_start_timer(MOTION_THRESHOLD_NORMAL_MUTE_DURATION, mdi_motion_disable_mute_timeout);
                break;

            case MDI_MOTION_SENSITIVE_LOW:
                gui_start_timer(MOTION_THRESHOLD_LOW_MUTE_DURATION, mdi_motion_disable_mute_timeout);
                break;

        }
    }

    /* set this flag false, allows next messge */
    g_mdi_motion_cntx.is_msg_send = FALSE;
}
#endif /* MDI_MOTION_DRIVER_AVAIALBE */ 


/*****************************************************************************
 * FUNCTION
 *  mdi_motion_tile_data_hdlr
 * DESCRIPTION
 *  tile event data handler
 * PARAMETERS
 *  msg_ptr     [IN]        Msg data pointer
 * RETURNS
 *  MDI_RESULT(?)
 *****************************************************************************/
#ifdef MDI_MOTION_DRIVER_AVAIALBE
static void mdi_motion_tile_data_hdlr(void *msg_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mdi_motion_cntx.state != MOTION_STATE_LISTENING)
    {
        return;
    }

}
#endif /* MDI_MOTION_DRIVER_AVAIALBE */ 

/*****************************************************************************
*
*  Calibration                                               
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mdi_motion_start_cali
 * DESCRIPTION
 *  start calibration
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_motion_start_cali(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MDI_RES_MOTION_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_motion_confirm_cali
 * DESCRIPTION
 *  confirm calibration
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_motion_confirm_cali(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MDI_RES_MOTION_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_motion_cancel_cali
 * DESCRIPTION
 *  cancel calibration
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_motion_cancel_cali(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MDI_RES_MOTION_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_motion_save_cali_data
 * DESCRIPTION
 *  save calibration data
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_motion_save_cali_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MDI_RES_MOTION_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_motion_load_cali_data
 * DESCRIPTION
 *  load calibration data
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_motion_load_cali_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MDI_RES_MOTION_SUCCEED;
}

#endif /* __MMI_MOTION_APP__ */ 

