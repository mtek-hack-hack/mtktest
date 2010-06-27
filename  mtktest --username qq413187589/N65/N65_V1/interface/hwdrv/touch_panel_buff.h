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
 *    serial_interface.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines Touch Panel Interface.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef TOUCH_PANEL_BUFF_H
#define TOUCH_PANEL_BUFF_H

#define tp_get_buf_roomleft(_left)   \
{\
   if ( touch_panel_data_buffer.touch_buffer_rindex <= touch_panel_data_buffer.touch_buffer_windex ) \
	{\
      _left = TOUCH_PANEL_BUFFER_SIZE - touch_panel_data_buffer.touch_buffer_windex + touch_panel_data_buffer.touch_buffer_rindex - 1;\
	}\
	else\
	{\
		_left = touch_panel_data_buffer.touch_buffer_rindex - touch_panel_data_buffer.touch_buffer_windex - 1;\
	}\
}
#define tp_get_buf_avail(_left)   \
{\
   if ( touch_panel_data_buffer.touch_buffer_windex >= touch_panel_data_buffer.touch_buffer_rindex ) \
	{\
      _left =touch_panel_data_buffer.touch_buffer_windex - touch_panel_data_buffer.touch_buffer_rindex;\
	}\
	else\
	{\
		_left = TOUCH_PANEL_BUFFER_SIZE - touch_panel_data_buffer.touch_buffer_rindex + touch_panel_data_buffer.touch_buffer_windex;\
	}\
}
#define touhc_push_data_to_buffer(_data, _state)   \
{\
   kal_uint16 room=0;\
   tp_get_buf_roomleft(room);\
   ASSERT(room!=0);\
   touch_panel_data_buffer.touch_panel_data[touch_panel_data_buffer.touch_buffer_windex]= _data;\
   touch_panel_data_buffer.touch_buffer_windex++;\
   touch_panel_data_buffer.touch_buffer_windex &= (TOUCH_PANEL_BUFFER_SIZE-1);\
   TP.touch_panel_event_cb(TP.cb_para, _state);\
}
#define touch_pop_data_from_buffer(_data)   \
{\
   if(touch_panel_data_buffer.touch_buffer_rindex==touch_panel_data_buffer.touch_buffer_windex)\
      ASSERT(0);\
   _data = touch_panel_data_buffer.touch_panel_data[touch_panel_data_buffer.touch_buffer_rindex];\
   touch_panel_data_buffer.touch_buffer_rindex++;\
   touch_panel_data_buffer.touch_buffer_rindex &= (TOUCH_PANEL_BUFFER_SIZE-1);\
}
#define touch_peek_data_from_buffer(_ptr, _num)   \
{\
   kal_uint8 _index;\
   kal_uint16 _tmp=0;\
   if(touch_panel_data_buffer.touch_buffer_rindex==touch_panel_data_buffer.touch_buffer_windex)\
      ASSERT(0);\
   _tmp=touch_panel_data_buffer.touch_buffer_rindex;\
   for(_index=0; _index<_num; _index++)\
   {\
      *(_ptr+_index) = touch_panel_data_buffer.touch_panel_data[_tmp];\
     _tmp++;\
     _tmp&= (TOUCH_PANEL_BUFFER_SIZE-1);\
   }\
}

#define touch_flush_data_buffer()   \
{\
   touch_panel_data_buffer.touch_buffer_rindex=0;\
   touch_panel_data_buffer.touch_buffer_windex=0;\
}

#endif