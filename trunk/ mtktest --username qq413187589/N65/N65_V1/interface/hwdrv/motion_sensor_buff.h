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
 *    motion_sensor_buff.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module is for motion sensor driver.
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
#ifndef MOTION_SENSOR_BUFF_H
#define MOTION_SENSOR_BUFF_H

#define ms_get_buf_roomleft(_left)   \
{\
   if ( motion_sensor_buff.motion_sensor_rindex <= motion_sensor_buff.motion_sensor_windex ) \
	{\
      _left = MOTION_SENSOR_BUFFER_SIZE - motion_sensor_buff.motion_sensor_windex + motion_sensor_buff.motion_sensor_rindex - 1;\
	}\
	else\
	{\
		_left = motion_sensor_buff.motion_sensor_rindex - motion_sensor_buff.motion_sensor_windex - 1;\
	}\
}
#define ms_get_buf_avail(_left)   \
{\
   if ( motion_sensor_buff.motion_sensor_windex >= motion_sensor_buff.motion_sensor_rindex ) \
	{\
      _left =motion_sensor_buff.motion_sensor_windex - motion_sensor_buff.motion_sensor_rindex;\
	}\
	else\
	{\
		_left = MOTION_SENSOR_BUFFER_SIZE - motion_sensor_buff.motion_sensor_rindex + motion_sensor_buff.motion_sensor_windex;\
	}\
}
#define motion_push_data_to_buffer(_data)   \
{\
   kal_uint16 room=0;\
   ms_get_buf_roomleft(room);\
   ASSERT(room!=0);\
   motion_sensor_buff.motion_sensor_data[motion_sensor_buff.motion_sensor_windex]= _data;\
   motion_sensor_buff.motion_sensor_windex++;\
   motion_sensor_buff.motion_sensor_windex &= (MOTION_SENSOR_BUFFER_SIZE-1);\
   if(room==1)\
      motion_sensor_data.cb_func(motion_sensor_data.para, BUFF_FULL);\
   else\
      motion_sensor_data.cb_func(motion_sensor_data.para, BUFF_DATA_EXIST);\
}
#define motion_pop_data_from_buffer(_data)   \
{\
   if(motion_sensor_buff.motion_sensor_rindex==motion_sensor_buff.motion_sensor_windex)\
      ASSERT(0);\
   (_data) = motion_sensor_buff.motion_sensor_data[motion_sensor_buff.motion_sensor_rindex];\
   motion_sensor_buff.motion_sensor_rindex++;\
   motion_sensor_buff.motion_sensor_rindex &= (MOTION_SENSOR_BUFFER_SIZE-1);\
}


#define motion_flush_data_buffer()   \
{\
   motion_sensor_buff.motion_sensor_rindex=0;\
   motion_sensor_buff.motion_sensor_windex=0;\
}

#endif
