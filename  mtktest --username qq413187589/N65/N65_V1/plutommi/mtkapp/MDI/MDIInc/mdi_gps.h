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
 *  mdi_gps.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GPS related interface hand file, such as GPS uart and NMEA parser
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

#ifndef _MDI_GPSUART_H_
#define _MDI_GPSUART_H_

#ifdef __MMI_GPS__

/***************************************************************************** 
* Include
*****************************************************************************/

/***************************************************************************** 
* Define
*****************************************************************************/
#define MDI_GIS_GPS_UART_MAX                    3


/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef struct 
{
   kal_uint8    ref_count;
   kal_uint16   msg_len;
   S16          port;
} mdi_gis_gps_uart_data_arrive_struct;

typedef enum
{
    MDI_GPS_UART_EVENT_DATA_ARRIVE = 0,
    MDI_GPS_UART_EVENT_VPORT_LOST,          /*virtual port is lost, maybe bluetooth connection is break*/
    MDI_GPS_UART_EVENT_UNKNOW_ERROR,
    MDI_GPS_UART_EVENT_EVENT_END
} mdi_gps_uart_event_enum;

typedef enum 
{
      GPS_PA_NONE=0,
      GPS_PA_ODD,
      GPS_PA_EVEN,
      GPS_PA_SPACE
} mdi_gps_uart_parity_enum;

typedef struct
{
    S16         port;
    U32         mod_id;
    U32         baud;
    U8          bits;
    U8          stop_bits;
    U8          parity;
    MMI_BOOL    is_opened;
    MMI_BOOL    is_data_arrive;
    void        (*gps_uart_event_callback)(mdi_gps_uart_event_enum param);           /*uart port number*/
} mdi_gis_gps_uart_handle_struct;

typedef S32 mdi_gps_uart_handle;

/*****************************************************************************              
* Extern Global Variable                                                                    
*****************************************************************************/

/*****************************************************************************              
* Extern Global Function                                                                    
*****************************************************************************/
extern MDI_RESULT mdi_gps_uart_configure(U16 port, U32 baud, U8 bits, U8 stop_bits, mdi_gps_uart_parity_enum parity);
extern mdi_gps_uart_handle mdi_gps_uart_open(U16 port,void(*gps_uart_event_callback)(mdi_gps_uart_event_enum param));
extern MDI_RESULT mdi_gps_uart_read(mdi_gps_uart_handle handle,void* buffer,U32 length, U32 *read);
extern MDI_RESULT mdi_gps_uart_write(mdi_gps_uart_handle handle, void* buffer,U32 length, U32 *write);
extern MMI_BOOL mdi_gps_uart_is_data_arrive(mdi_gps_uart_handle handle);
extern MDI_RESULT mdi_gps_uart_close(mdi_gps_uart_handle handle);
extern MMI_BOOL mdi_gps_uart_message_dispatcher(void *ilm_ptr);
#endif /* __MMI_GPS__ */ 
#endif /* _MDI_GPSUART_H_ */ 




