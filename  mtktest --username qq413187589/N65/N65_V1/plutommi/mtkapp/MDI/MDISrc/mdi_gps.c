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
 *  mdi_gps.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GPS related interface, such as GPS uart and NMEA parser
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *******************************************************************************/

#include "MMI_features.h"
#ifdef __MMI_GPS__
#include "kal_release.h"

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "uart_sw.h"

#include "kal_trace.h"  /* kal_trace() prototype */
#include "DebugInitDef.h"       /* Define trace class type */
#include "mmi_trc.h"        /*trace define*/
#include "stdlib.h"         /*math lib such as atof*/
#include "ctype.h"          /*use toupper function*/

#include "mdi_datatype.h"       /* mdi datatype */
#include "mdi_gps.h" 

/***************************************************************************** 
* Local Variable
*****************************************************************************/
static mdi_gis_gps_uart_handle_struct g_gps_uart[MDI_GIS_GPS_UART_MAX];
/***************************************************************************** 
* Local Function
*****************************************************************************/
static void mdi_gps_uart_indicate_hldr(UART_PORT port, mdi_gps_uart_event_enum param);

/***************************************************************************** 
* External Variable
*****************************************************************************/
extern module_type UART_GetOwnerID(UART_PORT port);

/*****************************************************************************
 * FUNCTION
 *  mdi_gps_uart_init
 * DESCRIPTION
 *  init gps uart mdi layer
 * PARAMETERS
 *  void 
 * RETURNS           
 * MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_gps_uart_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    for(i=0 ; i<MDI_GIS_GPS_UART_MAX ; i++)
    {
        g_gps_uart[i].port = 0xFF;
        g_gps_uart[i].mod_id = MOD_MMI;
        g_gps_uart[i].baud = 115200;
        g_gps_uart[i].bits = 1;
        g_gps_uart[i].stop_bits = 1;
        g_gps_uart[i].parity = GPS_PA_NONE;
        g_gps_uart[i].is_opened = MMI_FALSE;
        g_gps_uart[i].is_data_arrive = MMI_FALSE;
        g_gps_uart[i].gps_uart_event_callback = NULL;
    }
    return MDI_RES_GPS_UART_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_gps_uart_configure
 * DESCRIPTION
 *  configure uart port current we only support 8 bits data, 1 stop bit
 * PARAMETERS
 *  port        [IN]        port number for configure
 *  baud              [IN]        baud rate
 *  bits          [IN]        bits per transfer
 *  stop_bits               [IN]        number of stop bits
 *  parity                   [IN]        parity check
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_gps_uart_configure(U16 port, U32 baud, U8 bits, U8 stop_bits, mdi_gps_uart_parity_enum parity)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UARTDCBStruct UART_Config   = 
    {
    #ifdef __PS_SERVICE__
        UART_BAUD_115200, 
    #else 
        UART_BAUD_57600,    /* baud rate */
    #endif 
        len_8,              /* dataBits; */
        sb_1,               /* stopBits; */
        pa_none,            /* parity; */
        fc_hw,              /* no flow control; */
        0x11,               /* xonChar; */
        0x13,               /* xoffChar; */
        KAL_FALSE
    };
    module_type module_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    /*baud rate check goes here*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_GPS_UART_TRC_CONFIGURE, port, baud, bits, stop_bits, parity);
    ASSERT(port <= uart_max_port);
    switch(baud)
    {
    case 0:
        UART_Config.baud = UART_BAUD_AUTO;
    case 75:
        UART_Config.baud = UART_BAUD_75;
        break;
    case 150:
        UART_Config.baud = UART_BAUD_150;
        break;
    case 300:
        UART_Config.baud = UART_BAUD_300;
        break;
    case 600:
        UART_Config.baud = UART_BAUD_600;
        break;
    case 1200:
        UART_Config.baud = UART_BAUD_1200;
        break;
    case 2400:
        UART_Config.baud = UART_BAUD_2400;
        break;
    case 4800:
        UART_Config.baud = UART_BAUD_4800;
        break;
    case 7200:
        UART_Config.baud = UART_BAUD_7200;
        break;
    case 9600:
        UART_Config.baud = UART_BAUD_9600;
        break;
    case 14400:
        UART_Config.baud = UART_BAUD_14400;
        break;
    case 19200:
        UART_Config.baud = UART_BAUD_19200;
        break;
    case 28800:
        UART_Config.baud = UART_BAUD_28800;
        break;
    case 38400:
        UART_Config.baud = UART_BAUD_38400;
        break;
    case 57600:
        UART_Config.baud = UART_BAUD_57600;
        break;
    case 115200:
        UART_Config.baud = UART_BAUD_115200;
        break;
    case 230400:
        UART_Config.baud = UART_BAUD_230400;
        break;
    case 240800:
        UART_Config.baud = UART_BAUD_460800;
        break;
    case 921600:
        UART_Config.baud = UART_BAUD_921600;
        break;
    default:
        ASSERT(baud == 115200);
        break;
    }
    /*dataBits check goes here*/
    switch(bits)
    {
    case len_8:
        UART_Config.dataBits = len_8;
        break;
    case len_7:
        UART_Config.dataBits = len_7;
        break;
    case len_6:
        UART_Config.dataBits = len_6;
        break;
    case len_5:
        UART_Config.dataBits = len_5;
        break;
    default:
        ASSERT(bits == 8);
        break;
    }
    /*stop_bits check goes here*/
    switch(stop_bits)
    {
    case 1:
        UART_Config.stopBits = sb_1;
        break;
    case 2:
        UART_Config.stopBits = sb_2;
        break;
    case 15:
        UART_Config.stopBits = sb_1_5;
        break;
    default:
        ASSERT(stop_bits == 1);
        break;
    }
    
    /*parity check goes here*/
    switch(parity)
    {
    case GPS_PA_NONE:
        UART_Config.parity = pa_none;
        break;
    case GPS_PA_ODD:
        UART_Config.parity = pa_odd;
        break;
    case GPS_PA_EVEN:
        UART_Config.parity = pa_even;
        break;
    case GPS_PA_SPACE:
        UART_Config.parity = pa_space;
        break;
    default:
        ASSERT(parity == 0);
        break;
    }
    module_id = stack_get_active_module_id();
    UART_SetDCBConfig(port, &UART_Config, module_id);
    return MDI_RES_GPS_UART_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_gps_uart_open
 * DESCRIPTION
 *  open the uart and give the callor the uart handle
 * PARAMETERS
 *  port        [IN]        port number for open
 *  gps_uart_event_callback              [IN]        callback function of uart events
 * RETURNS           
 *  mdi_gps_uart_handle
 *****************************************************************************/
mdi_gps_uart_handle mdi_gps_uart_open(U16 port, void(*gps_uart_event_callback)(mdi_gps_uart_event_enum param))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT  ret;
    U8          buffer[51];
    U8          i,  j;
    module_type module_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_GPS_UART_TRC_OPEN, port, gps_uart_event_callback);
    ret = MDI_RES_GPS_UART_ERR_PORT_ERR_UNKNOW;
    ASSERT(port <= uart_max_port);
    module_id = stack_get_active_module_id();
    for(i=0 ; i<MDI_GIS_GPS_UART_MAX ; i++)
    {
        if (g_gps_uart[i].port == port)
        {
            MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_GPS_UART_TRC_OPEN_ALREADY_OPEN);
            return (mdi_gps_uart_handle)MDI_RES_GPS_UART_ERR_PORT_ALREADY_OPEN;
        }
    }
    for(i=0 ; i<MDI_GIS_GPS_UART_MAX ; i++)
    {
        if (g_gps_uart[i].is_opened == MMI_FALSE)
        {
            MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_GPS_UART_TRC_FIND_SLOT, i);
#ifdef GPS_MOD_ON_BROAD
            if (port == GPS_MOD_ON_BROAD_PORT_NUM)
            {
                MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_GPS_UART_TRC_ON_BROAD_GPS);
                /*internal GPS module power on goes here*/
            }
#endif
            UART_SetOwner (port,  module_id);
            if (UART_Open(port,  module_id) != MMI_TRUE)
            {
                MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_GPS_UART_TRC_OPEN_ERROR);
                return MDI_RES_GPS_UART_ERR_PORT_NUMBER_WRONG;
            }
            MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_GPS_UART_TRC_OPEN_OK);
            g_gps_uart[i].gps_uart_event_callback = gps_uart_event_callback;
            g_gps_uart[i].mod_id = module_id;
            g_gps_uart[i].port = port;
            g_gps_uart[i].is_opened = MMI_TRUE;
            /*dump out data so new mod can get data arrive msg*/
            for(j=0 ; j<100; j++)
            {
                ret = UART_GetBytes(g_gps_uart[i].port, buffer, 50, NULL, module_id);
                MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_GPS_UART_TRC_DUMP_DATA, ret);
                if (ret == 0)
                {
                    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_GPS_UART_TRC_DUMP_OK, ret);
                    break;
                }
            }
            ret = MDI_RES_GPS_UART_SUCCEED;
            break;
        }
    }
    if (ret == MDI_RES_GPS_UART_SUCCEED)
    {
        MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_GPS_UART_TRC_OPEN_RETURN_OK);
        return (mdi_gps_uart_handle)i;
    }
    else
    {
        MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_GPS_UART_TRC_OPEN_RETURN_ERR);
        return (mdi_gps_uart_handle)ret;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_gps_uart_read
 * DESCRIPTION
 *  read data from uart port
 * PARAMETERS
 *  handle        [IN]        handle of the port
 *  buffer        [OUT]        mdi uart will put data here
 *  length        [IN]        tell the mdi uart buffer length
 *  read        [OUT]        mdi uart return the number of the byte readed here
 * RETURNS           
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_gps_uart_read(mdi_gps_uart_handle handle, void* buffer, U32 length, U32 *read)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16         ret;
    U8          index;
    module_type module_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_GPS_UART_TRC_READ, handle, buffer, length, read);
    module_id = stack_get_active_module_id();
    ASSERT((S32)handle >= 0 && (S32)handle < MDI_GIS_GPS_UART_MAX);
    index = handle;
    ASSERT(g_gps_uart[index].mod_id == module_id);
    if (g_gps_uart[index].is_opened == MMI_FALSE)
    {
        return MDI_RES_GPS_UART_ERR_PORT_ERR_NOT_OPEN;
    }
    ASSERT(g_gps_uart[index].port != 0xFF);
    ret = UART_GetBytes(g_gps_uart[index].port, buffer, length, NULL, module_id);
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_GPS_UART_TRC_READ_SIZE, ret);
    if (ret == 0)
    {
        g_gps_uart[index].is_data_arrive = MMI_FALSE;
    }
    *read = ret;
    return MDI_RES_GPS_UART_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_gps_uart_write
 * DESCRIPTION
 *  write data to uart port
 * PARAMETERS
 *  handle        [IN]        handle of the port
 *  buffer        [OUT]        mdi uart will put data here
 *  length        [IN]        tell the mdi uart buffer length
 *  write        [OUT]        mdi uart return the number of byte writen here
 * RETURNS           
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_gps_uart_write(mdi_gps_uart_handle handle, void* buffer, U32 length, U32 *write)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16         ret;
    U8          index;
    module_type module_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_GPS_UART_TRC_WRITE, handle, buffer, length, write);
    module_id = stack_get_active_module_id();
    ASSERT((S32)handle >= 0 && (S32)handle < MDI_GIS_GPS_UART_MAX);
    index = handle;
    ASSERT(g_gps_uart[index].mod_id == module_id);
    if (g_gps_uart[index].is_opened == MMI_FALSE)
    {
        return MDI_RES_GPS_UART_ERR_PORT_ERR_NOT_OPEN;
    }
    ASSERT(g_gps_uart[index].port != 0xFF);
    ret = UART_PutBytes(g_gps_uart[index].port,  buffer,  length,  module_id);
    *write = ret;
    
    return MDI_RES_GPS_UART_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_gps_uart_is_data_arrive
 * DESCRIPTION
 *  check if the data is arrived
 * PARAMETERS
 *  handle        [IN]        handle of the port want to check
 * RETURNS           
 *  MMI_TRUE        data is arrived 
 *  MMI_FALSE       data is not arrived
 *****************************************************************************/
MMI_BOOL mdi_gps_uart_is_data_arrive(mdi_gps_uart_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_GPS_UART_TRC_ARRIVE, handle);
    ASSERT((S32)handle >= 0 && (S32)handle < MDI_GIS_GPS_UART_MAX);
    index = (U8)handle;
    if (g_gps_uart[index].is_data_arrive == MMI_TRUE)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_gps_uart_close
 * DESCRIPTION
 *  close the port so other app can use
 * PARAMETERS
 *  handle        [IN]        the handle of the port want to close
 * RETURNS           
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_gps_uart_close(mdi_gps_uart_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8          index;
    module_type module_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_GPS_UART_TRC_CLOSE, handle);
    module_id = stack_get_active_module_id();
    ASSERT((S32)handle >= 0 && (S32)handle < MDI_GIS_GPS_UART_MAX);
    index = (U8)handle;
    if(g_gps_uart[index].is_opened == MMI_FALSE)
    {
        return MDI_RES_GPS_UART_ERR_PORT_ALREADY_CLOSED;
    }
    ASSERT(g_gps_uart[index].mod_id == module_id);
    UART_Close(g_gps_uart[index].port,  module_id);
#ifdef GPS_MOD_ON_BROAD
    if (g_gps_uart[index].port == GPS_MOD_ON_BROAD_PORT_NUM)
    {
        /*internal GPS nodule power off goes here*/
    }
#endif
    g_gps_uart[index].port = 0xFF;
    g_gps_uart[index].mod_id = MOD_MMI;
    g_gps_uart[index].baud = 115200;
    g_gps_uart[index].bits = 1;
    g_gps_uart[index].stop_bits = 1;
    g_gps_uart[index].parity = GPS_PA_NONE;
    g_gps_uart[index].is_opened = MMI_FALSE;
    g_gps_uart[index].is_data_arrive = MMI_FALSE;
    g_gps_uart[index].gps_uart_event_callback = NULL;

    return MDI_RES_GPS_UART_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_gps_uart_indicate_hldr
 * DESCRIPTION
 *  check if need tell the app with the events happened
 * PARAMETERS
 *  port        [IN]        port number of the uart
 *  param        [IN]        the events come from the port
 * RETURNS           
 *  void
 *****************************************************************************/
static void mdi_gps_uart_indicate_hldr(UART_PORT port, mdi_gps_uart_event_enum param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type         module_id;
    U8                  i;
    module_id = stack_get_active_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_GPS_UART_TRC_INDICATE, port, param);
    for(i=0 ; i<MDI_GIS_GPS_UART_MAX ; i++)
    {
        MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_GPS_UART_TRC_EXPECTED, i, g_gps_uart[i].port, port);
        if (g_gps_uart[i].port == port)
        {
            ASSERT(g_gps_uart[i].mod_id == module_id);
            g_gps_uart[i].is_data_arrive = MMI_TRUE;
            if (g_gps_uart[i].gps_uart_event_callback != NULL)
            {
                MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_GPS_UART_TRC_CALLBACK, g_gps_uart[i].gps_uart_event_callback);
                g_gps_uart[i].gps_uart_event_callback(param);
                break;
            }
            else
            {
                MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_GPS_UART_TRC_CALLBACK, NULL);
                break;
            }
        }
    }
    return ;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_gps_uart_message_dispatcher
 * DESCRIPTION
 *  dispatcher of the mdi gps, this will get message for task needed
 * PARAMETERS
 *  ilm_ptr        [IN]        ilm_struct data
 * RETURNS           
 *  MMI_TRUE    message is processed by this function
 *  MMI_FALSE   message is not processed by this function
 *****************************************************************************/
MMI_BOOL mdi_gps_uart_message_dispatcher(void *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_p = ilm_ptr;
    MMI_BOOL handle_msg = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_GPS_UART_TRC_MSG_DISPATCHER, ilm_p->msg_id);
    switch(ilm_p->msg_id)
    {
        case MSG_ID_UART_READY_TO_READ_IND:
            MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_GPS_UART_TRC_DISPATCHER_READY_READ);
            mdi_gps_uart_indicate_hldr(((uart_ready_to_read_ind_struct*)(ilm_p->local_para_ptr))->port, MDI_GPS_UART_EVENT_DATA_ARRIVE);
            break;

        case MSG_ID_UART_READY_TO_WRITE_IND:
            MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_GPS_UART_TRC_DISPATCHER_READY_WRITE);
            break;

        case MSG_ID_UART_PLUGOUT_IND:
            MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_GPS_UART_TRC_DISPATCHER_PLUGOUT);
            mdi_gps_uart_indicate_hldr(((uart_ready_to_read_ind_struct*)(ilm_p->local_para_ptr))->port, MDI_GPS_UART_EVENT_VPORT_LOST);
            break;

        default:
            handle_msg = MMI_FALSE;
            break;
    }

    return handle_msg;

}


/*****************************************************************************
 * FUNCTION
 *  mdi_gps_spp_uart_ready_to_read_ind_hdler
 * DESCRIPTION
 *  the message proccess function of uart read to read
 * PARAMETERS
 *  msg        [IN]        the coming message
 * RETURNS           
 *  void
 *****************************************************************************/
void mdi_gps_spp_uart_ready_to_read_ind_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    uart_ready_to_read_ind_struct* uart_rtr_ind = (uart_ready_to_read_ind_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_GPS_UART_TRC_HDLR_READY_READ, uart_rtr_ind->port);
    mdi_gps_uart_indicate_hldr(uart_rtr_ind->port, MDI_GPS_UART_EVENT_DATA_ARRIVE);
}
        

/*****************************************************************************
 * FUNCTION
 *  mdi_gps_spp_uart_plugout_ind_hdler
 * DESCRIPTION
 *  the message proccess function of uart plug out
 * PARAMETERS
 *  msg        [IN]        the coming message
 * RETURNS           
 *  void
 *****************************************************************************/
void mdi_gps_spp_uart_plugout_ind_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    uart_ready_to_read_ind_struct* uart_rtr_ind = (uart_ready_to_read_ind_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_GPS_UART_TRC_HDLR_PLUGOUT, uart_rtr_ind->port);
    mdi_gps_uart_indicate_hldr(uart_rtr_ind->port, MDI_GPS_UART_EVENT_VPORT_LOST);
}
        

/*****************************************************************************
 * FUNCTION
 *  mdi_gps_spp_uart_ready_to_write_ind_hdler
 * DESCRIPTION
 *  the message proccess function of uart ready to write
 * PARAMETERS
 *  msg        [IN]        the coming message
 * RETURNS           
 *  void
 *****************************************************************************/
void mdi_gps_spp_uart_ready_to_write_ind_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    uart_ready_to_read_ind_struct* uart_rtr_ind = (uart_ready_to_read_ind_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_GPS_UART_TRC_HDLR_READY_WRITE, uart_rtr_ind->port);
}
#endif /*__MMI_GPS__*/

