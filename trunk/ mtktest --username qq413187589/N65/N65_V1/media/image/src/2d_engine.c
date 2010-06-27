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
 *   2D_engine.c
 *
 * Project:
 * --------
 *   For all projects on MT6219, MT6226, MT6227, MT6228 and MT6229
 *
 * Description:
 * ------------
 *   2D-engine interface code
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
 * removed!
 * removed!
 * removed!
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
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
 *
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_release.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"       /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"
#include "stacklib.h"
#include "stack_timer.h"      /*stack_timer_struct....definitions*/

#include "drv_comm.h"
#include "IntrCtrl.h"
#include "visualhisr.h"
#include "visual_comm.h"
#include "2D_engine.h"
#include "reg_base.h"
#include "math.h"

#if (defined(DRV_2D_ENGINE_V1) || defined(DRV_2D_ENGINE_V2))

g2d_parameter_struct g2d_control_data;

kal_uint8  g2d_current_owner_id=G2D_OWNER_NONE;
kal_hisrid g2d_hisr_id=NULL;
kal_eventgrpid g2d_event_id=NULL;

#ifndef __MAUI_BASIC__
extern kal_uint8 L1SM_GetHandle(void);
extern void L1SM_SleepEnable(kal_uint8 handle);
extern void L1SM_SleepDisable(kal_uint8 handle);
kal_uint8   g2d_sleep_mode_handler=0xFF;
#endif   /* __MAUI_BASIC__ */

#if defined(DRV_2D_ENGINE_V2) || (!defined(__MTK_TARGET__))
kal_uint32 subdivided_buffer[257][2];
kal_uint16 cosine_table[91]=
{65535,65525,65495,65445,65375,65285,65175,65046,64897,64728,
 64539,64330,64102,63855,63588,63301,62996,62671,62327,61964,
 61582,61182,60762,60325,59869,59394,58902,58392,57863,57318,
 56754,56174,55576,54962,54330,53683,53018,52338,51642,50930,
 50202,49459,48701,47929,46141,46340,45524,44694,43851,42994,
 42125,41242,40347,39439,38520,37589,36646,35692,34728,33753,
 32767,31771,30766,29752,28728,27696,26655,25606,24549,23485,
 22414,21336,20251,19160,18063,16961,15854,14742,13625,12504,
 11380,10251, 9120, 7986, 6850, 5711, 4571, 3429, 2287, 1143,
 0};
g2d_buffer_struct g2d_dest_buff_data;
g2d_font_attribute_struct g2d_font_attr_data;
#endif


#if (!defined(__MTK_TARGET__))
kal_uint8 g2d_sw_tilt_value[32];
#endif

#if defined(DRV_2D_ENGINE_V2)
kal_uint32 g2d_cmq[G2D_CMQ_LENGTH];
g2d_triangle_para_struct g2d_triangle_para_data;
kal_uint32 g2d_submode_ctrl_reg_shadow;
kal_uint32 g2d_comm_ctrl_reg_shadow;
kal_uint32 g2d_fire_ctrl_reg_shadow;

void (*g2d_callback) ();
#endif

/*************************************************************************
* FUNCTION
*     g2d_LISR
*
* DESCRIPTION
*     G2D LISR entry
*
* PARAMETERS
*
* RETURNS
*     None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void g2d_LISR(void)
{
#ifndef __MAUI_BASIC__
   visual_active_hisr(VISUAL_G2D_HISR_ID);
#endif
}  /* g2d_LISR() */

/*************************************************************************
* FUNCTION
*     g2d_HISR
*
* DESCRIPTION
*     G2D HISR entry
*
* PARAMETERS
*
* RETURNS
*     None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void g2d_HISR(void)
{
//   kal_set_eg_events(g2d_event_id,G2D_COMPLETE_EVENT,KAL_OR);
#if defined(DRV_2D_ENGINE_V2)
   if (g2d_callback!=NULL)
      g2d_callback();
#endif
}  /* g2d_HISR() */

/*************************************************************************
* FUNCTION
*     g2d_power_on()
*
* DESCRIPTION
*     power on G2D interface and reset G2d hardware
*
* PARAMETERS
*
* RETURNS
*     None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void g2d_power_on(void)
{
#ifdef __MTK_TARGET__

#ifndef __MAUI_BASIC__
   L1SM_SleepDisable(g2d_sleep_mode_handler);
#endif

   /// Power on G2D
   DRV_Reg(DRVPDN_CON3_CLR) = DRVPDN_CON3_G2D;
   /// Power on G2D command queue
   DRV_Reg(DRVPDN_CON3_CLR) = DRVPDN_CON3_GCMQ;

   RESET_G2D_ENGINE;
#endif
}  /* g2d_power_on() */

/*************************************************************************
* FUNCTION
*     g2d_power_off()
*
* DESCRIPTION
*     power off G2D interface and reset G2d hardware
*
* PARAMETERS
*
* RETURNS
*     None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void g2d_power_off(void)
{
#ifdef __MTK_TARGET__
   /// Power off G2D
   DRV_Reg(DRVPDN_CON3_SET) = DRVPDN_CON3_G2D;
   /// Power off G2D command queue
   DRV_Reg(DRVPDN_CON3_SET) = DRVPDN_CON3_GCMQ;

#ifndef __MAUI_BASIC__
   L1SM_SleepEnable(g2d_sleep_mode_handler);
#endif

#endif
}  /* g2d_power_off() */

/*************************************************************************
* FUNCTION
*     g2d_init
*
* DESCRIPTION
*     This function initialize G2D module
*
* PARAMETERS
*
* RETURNS
*     None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void g2d_init(void)
{
#ifdef __MTK_TARGET__
   if (g2d_event_id==NULL)
      g2d_event_id=kal_create_event_group("G2D_EVT");

   IRQ_Register_LISR(IRQ_G2D_CODE, g2d_LISR,"G2D ISR");

#ifndef __MAUI_BASIC__
   VISUAL_Register_HISR(VISUAL_G2D_HISR_ID,g2d_HISR);
#endif

   IRQSensitivity(IRQ_G2D_CODE,EDGE_SENSITIVE);
   IRQUnmask(IRQ_G2D_CODE);

#ifndef __MAUI_BASIC__
   if (g2d_sleep_mode_handler == 0xFF) {
      g2d_sleep_mode_handler=L1SM_GetHandle();
   }
#endif

#if defined(DRV_2D_ENGINE_V2)
   g2d_power_on();
   REG_G2D_CMQ_QUEUE_LENGTH=G2D_CMQ_LENGTH;
   REG_G2D_CMQ_QUEUE_BASE_ADDR=(kal_uint32) g2d_cmq;
   g2d_power_off();
#endif
#endif
}  /* g2d_init() */

/*************************************************************************
* FUNCTION
*     g2d_deinit
*
* DESCRIPTION
*     This function turn G2D module off
*
* PARAMETERS
*
* RETURNS
*     None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void g2d_deinit(void)
{
#ifdef __MTK_TARGET__
   g2d_power_off();

   IRQMask(IRQ_G2D_CODE);
#endif
}  /* g2d_deinit() */

void wait_cmq_start(void)
{
   volatile kal_uint16 i;

   for (i=0;i<0x100;i++);
}  /* wait_cmq_start() */

/*************************************************************************
* FUNCTION
*     g2d_set_clip_window
*
* DESCRIPTION
*     This function set the g2d clip window.
*
* PARAMETERS
*    g2d_data : the parameter data structure of G2D module
*
* RETURNS
*     None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void g2d_set_clip_window(g2d_parameter_struct *g2d_data)
{
#ifdef __MTK_TARGET__
   if (g2d_data->clip_mode==G2D_CLIP_ENABLE)
   {
      if ((g2d_data->clip_start_x>g2d_data->clip_end_x) ||
          (g2d_data->clip_start_y>g2d_data->clip_end_y))
         ASSERT(0);
   }

   if (G2D_ENGINE_IS_BUSY)
   {
      ENABLE_G2D_CMQ;
#if defined(DRV_2D_ENGINE_V1)
      while (G2D_CMQ_FREE_SPACE < 7) {};
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_CLIP_TOP_Y_ADDR | g2d_data->clip_start_y));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_CLIP_LEFT_X_ADDR | g2d_data->clip_start_x));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_CLIP_BOTTOM_Y_ADDR | g2d_data->clip_end_y));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_CLIP_RIGHT_X_ADDR | g2d_data->clip_end_x));
      if (g2d_data->clip_mode==G2D_CLIP_ENABLE) {
         DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_2D_COMMON_CTRL_REG_ADDR |
                        (DRV_Reg32(G2D_COMM_CTRL_REG)|REG_COMMON_CTRL_G2D_CLIP_ENABLE_BIT)));
      } else {
         DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_2D_COMMON_CTRL_REG_ADDR |
                        (DRV_Reg32(G2D_COMM_CTRL_REG)&(~REG_COMMON_CTRL_G2D_CLIP_ENABLE_BIT))));
      }

#elif defined(DRV_2D_ENGINE_V2)
      while (G2D_CMQ_FREE_SPACE < 7) {};
      ENABLE_G2D_CMQ_WRITE;
      G2D_WRITE_CMQ(G2D_CMQ_CLIP_TOP_Y_ADDR | g2d_data->clip_start_y);
      G2D_WRITE_CMQ(G2D_CMQ_CLIP_LEFT_X_ADDR | g2d_data->clip_start_x);
      G2D_WRITE_CMQ(G2D_CMQ_CLIP_BOTTOM_Y_ADDR | g2d_data->clip_end_y);
      G2D_WRITE_CMQ(G2D_CMQ_CLIP_RIGHT_X_ADDR | g2d_data->clip_end_x);
      DISABLE_G2D_CMQ_WRITE;
#endif
   }
   else
   {
      DISABLE_G2D_CMQ;
      DRV_WriteReg32(G2D_CLP_LT_REG,((g2d_data->clip_start_x <<16) | g2d_data->clip_start_y));
      DRV_WriteReg32(G2D_CLP_RB_REG,((g2d_data->clip_end_x <<16) | g2d_data->clip_end_y));
      if (g2d_data->clip_mode==G2D_CLIP_ENABLE)
      {
         ENABLE_G2D_ENGINE_CLIP;
      }
      else
      {
         DISABLE_G2D_ENGINE_CLIP;
      }
   }
#endif
}  /* g2d_set_clip_window() */

/*************************************************************************
* FUNCTION
*     g2d_set_tilt_data
*
* DESCRIPTION
*     This function set the g2d tilt parameter for font caching operation.
*
* PARAMETERS
*    color_mode : 16BPP mode (G2D_DEST_16BPP_LUT_DISABLE) or 8BPP mode (G2D_DEST_8BPP_LUT_DISABLE)
*    index : the index of tilt parameter
*    tilt_value : tilt pixel of index-th tilt parameter.
*
* RETURNS
*     None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void g2d_set_tilt_data(kal_uint8 index, kal_uint8 tilt_value)
{
#ifdef __MTK_TARGET__
#if defined(DRV_2D_ENGINE_V2)
   if (G2D_CMQ_IS_ENABLE)
   {
      while (G2D_CMQ_FREE_SPACE!=G2D_CMQ_LENGTH) {};
      DISABLE_G2D_CMQ;
      SET_G2D_TILT(index,tilt_value);
      ENABLE_G2D_CMQ;
   }
   else
   SET_G2D_TILT(index,tilt_value);
#endif
#else
   g2d_sw_tilt_value[index]=tilt_value;
#endif
}  /* g2d_set_tilt_data() */

/*************************************************************************
* FUNCTION
*     g2d_set_color_palette
*
* DESCRIPTION
*     This function set the color palette of G2D module.
*
* PARAMETERS
*    index : color palette index
*    color : color of specified color palette in RGB565 format.
*
* RETURNS
*     None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void g2d_set_color_palette(kal_uint8 index, kal_uint32 color)
{
#ifdef __MTK_TARGET__
#if defined(DRV_2D_ENGINE_V1)
   ENABLE_G2D_ENGINE_PALETTE;
   DRV_WriteReg32((G2D_PALETTE_BASE+(index<<2)),color);
   DISABLE_G2D_ENGINE_PALETTE;
#elif defined(DRV_2D_ENGINE_V2)
#endif
#endif
}  /* g2d_set_color_palette() */


void g2d_multi_bitblt_operation(g2d_parameter_struct *g2d_data)
{
#ifdef __MTK_TARGET__
#if defined(DRV_2D_ENGINE_V1)
   switch (g2d_data->dest_color_mode)
   {
      case G2D_DEST_16BPP_LUT_DISABLE:
      case G2D_DEST_16BPP_LUT_ENABLE:
         g2d_data->dest_pitch=(g2d_data->dest_pitch_width<<1);
         g2d_data->dest_base_address += ((g2d_data->dest_pitch_width * g2d_data->dest_y + g2d_data->dest_x)<<1);
      break;
      case G2D_DEST_8BPP_LUT_DISABLE:
         g2d_data->dest_pitch=g2d_data->dest_pitch_width;
         g2d_data->dest_base_address += ((g2d_data->dest_pitch_width * g2d_data->dest_y + g2d_data->dest_x));
      break;
   }

   switch (g2d_data->src_color_mode)
   {
      case G2D_SRC_16BPP_LUT_DISABLE:
         g2d_data->src_pitch=(g2d_data->src_pitch_width<<1);
         g2d_data->src_base_address += ((g2d_data->src_pitch_width * g2d_data->src_y + g2d_data->src_x)<<1);
      break;
      case G2D_SRC_8BPP_LUT_DISABLE:
      case G2D_SRC_8BPP_LUT_ENABLE:
         g2d_data->src_pitch=g2d_data->src_pitch_width;
         g2d_data->src_base_address += (g2d_data->src_pitch_width * g2d_data->src_y + g2d_data->src_x);
      break;
   }
   g2d_bitblt(g2d_data);
#endif
#endif
}  /* g2d_multi_bitblt_operation() */

void g2d_multi_bitblt(g2d_parameter_struct *g2d_data)
{
#ifdef __MTK_TARGET__
#if defined(DRV_2D_ENGINE_V1)
   kal_uint16 temp_data,temp_src_x,temp_src_y;
   short temp_dest_x,temp_dest_y;
   kal_uint16 temp_src_width,temp_src_height,temp_dest_width,temp_dest_height;

   if (((g2d_data->dest_x+g2d_data->dest_width)<0)||
       ((g2d_data->dest_y+g2d_data->dest_height)<0))
      return;

   if (g2d_data->dest_x<0)
   {
      temp_data=(0-g2d_data->dest_x)/g2d_data->src_width;
      g2d_data->dest_x+=(temp_data * g2d_data->src_width);
      g2d_data->dest_width-=(temp_data * g2d_data->src_width);
   }

   if (g2d_data->dest_y<0)
   {
      temp_data=(0-g2d_data->dest_y)/g2d_data->src_height;
      g2d_data->dest_y+=(temp_data * g2d_data->src_height);
      g2d_data->dest_height-=(temp_data * g2d_data->src_height);
   }

   temp_src_x=g2d_data->src_x;
   temp_src_y=g2d_data->src_y;
   temp_src_width=g2d_data->src_width;
   temp_src_height=g2d_data->src_height;
   temp_dest_x=g2d_data->dest_x;
   temp_dest_y=g2d_data->dest_y;
   temp_dest_width=g2d_data->dest_width;
   temp_dest_height=g2d_data->dest_height;

   if ((g2d_data->dest_x<0)&&(g2d_data->dest_y<0))
   {
      g2d_data->src_x-=g2d_data->dest_x;
      g2d_data->src_y-=g2d_data->dest_y;
      g2d_data->src_width+=g2d_data->dest_x;
      g2d_data->src_height+=g2d_data->dest_y;
      g2d_data->dest_x=0;
      g2d_data->dest_y=0;
      g2d_data->dest_width=g2d_data->src_width;
      g2d_data->dest_height=g2d_data->src_height;
      g2d_multi_bitblt_operation(g2d_data);

      g2d_data->src_x=temp_src_x;
      g2d_data->src_width=temp_src_width;
      g2d_data->dest_x=temp_src_width+temp_dest_x;
      g2d_data->dest_width=temp_dest_width-temp_src_width;
      g2d_multi_bitblt_operation(g2d_data);

      g2d_data->src_x=temp_src_x-temp_dest_x;
      g2d_data->src_y=temp_src_y;
      g2d_data->src_width=temp_src_width+temp_dest_x;
      g2d_data->src_height=temp_src_height;
      g2d_data->dest_x=0;
      g2d_data->dest_y=temp_dest_y+temp_src_height;
      g2d_data->dest_width=temp_src_width+temp_dest_x;
      g2d_data->dest_height=temp_dest_height-temp_src_height;
      g2d_multi_bitblt_operation(g2d_data);
   }
   else if (g2d_data->dest_y<0)
   {
      g2d_data->src_y-=g2d_data->dest_y;
      g2d_data->src_height+=g2d_data->dest_y;
      g2d_data->dest_y=0;
      g2d_data->dest_height=g2d_data->src_height;
      g2d_multi_bitblt_operation(g2d_data);
   }
   else if (g2d_data->dest_x<0)
   {
      g2d_data->src_x-=g2d_data->dest_x;
      g2d_data->src_width+=g2d_data->dest_x;
      g2d_data->dest_x=0;
      g2d_data->dest_width=g2d_data->src_width;
      g2d_multi_bitblt_operation(g2d_data);
   }
   g2d_data->src_x=temp_src_x;
   g2d_data->src_y=temp_src_y;
   g2d_data->src_width=temp_src_width;
   g2d_data->src_height=temp_src_height;

   if (temp_dest_x<0)
   {
      g2d_data->dest_x=temp_dest_x+temp_src_width;
      g2d_data->dest_width=(temp_dest_width-temp_src_width);
   }
   else
   {
      g2d_data->dest_x=temp_dest_x;
      g2d_data->dest_width=temp_dest_width;
   }

   if (temp_dest_y<0)
   {
      g2d_data->dest_y=temp_dest_y+temp_src_height;
      g2d_data->dest_height=(temp_dest_height-temp_src_height);
   }
   else
   {
      g2d_data->dest_y=temp_dest_y;
      g2d_data->dest_height=temp_dest_height;
   }
   g2d_multi_bitblt_operation(g2d_data);
#endif
#endif
}  /* g2d_multi_bitblt() */

#ifdef __MTK_TARGET__
void g2d_sw_font_caching(g2d_parameter_struct *g2d_data)
{
#if defined(DRV_2D_ENGINE_V1)
   kal_uint16 font_bit,font_bit_count,font_count=0;
   kal_uint16 i,j;
   kal_uint16 *font_buff_ptr;
   kal_uint8 *font_buff_ptr1,*font_data_ptr,font_data;
   short x_pos,y_pos;

   font_data_ptr=(kal_uint8 *) g2d_data->src_base_address;
   font_data=*(font_data_ptr+font_count);
   font_bit_count=0;
   font_count++;

   if (g2d_data->dest_color_mode==G2D_DEST_16BPP_LUT_DISABLE)
      g2d_data->dest_pitch=(g2d_data->dest_pitch_width<<1);
   else
      g2d_data->dest_pitch=(g2d_data->dest_pitch_width);

   if (g2d_data->dest_x<0)
   {
      if (g2d_data->dest_y>0)
      {
         if (g2d_data->dest_color_mode==G2D_DEST_16BPP_LUT_DISABLE)
            g2d_data->dest_base_address += (g2d_data->dest_y * g2d_data->dest_pitch);
         else
            g2d_data->dest_base_address += (g2d_data->dest_y * g2d_data->dest_pitch);
      }
   }
   else
   {
      if (g2d_data->dest_color_mode==G2D_DEST_16BPP_LUT_DISABLE)
         g2d_data->dest_base_address += (g2d_data->dest_x<<1);
      else
         g2d_data->dest_base_address += g2d_data->dest_x;
   }

   if (g2d_data->dest_color_mode==G2D_DEST_16BPP_LUT_DISABLE)
   {
      for (i=0;i<g2d_data->src_height;i++)
      {
         if (g2d_data->italic_mode==0)
         {
            x_pos=g2d_data->dest_x;
            y_pos=g2d_data->dest_y+i;
         }
         else
         {
            x_pos=g2d_data->dest_x+ (GET_G2D_TILT(i)>>1);
            y_pos=g2d_data->dest_y+i;
         }
         font_buff_ptr=(kal_uint16 *)(g2d_data->dest_base_address + ((y_pos*g2d_data->dest_pitch+x_pos)));

         for (j=0;j<g2d_data->src_width;j++)
         {
            font_bit = font_data & 0x01;
            if ((x_pos>=0)&&(y_pos>=0))
            {
               if (g2d_data->clip_mode)
               {
                  if ((x_pos>=g2d_data->clip_start_x) && (x_pos <=g2d_data->clip_end_x) &&
                     (y_pos>=g2d_data->clip_start_y) && (y_pos <=g2d_data->clip_end_y))
                  {  /* in clip range */
                     if (font_bit)
                     {
                        *(font_buff_ptr+j) = g2d_data->pat_fg_color;
                     }
                     else
                     {
                        if (g2d_data->font_background_mode)
                           *(font_buff_ptr+j) = g2d_data->pat_bg_color;
                     }
                  }
               }
               else
               {
                  if (font_bit)
                  {
                     *(font_buff_ptr+j) = g2d_data->pat_fg_color;
                  }
                  else
                  {
                     if (g2d_data->font_background_mode)
                        *(font_buff_ptr+j) = g2d_data->pat_bg_color;
                  }
               }
            }
            x_pos++;
            font_data>>=1;
            font_bit_count++;
            if (font_bit_count==8)
            {  /* get next byte */
               font_data=*(font_data_ptr+font_count);
               font_bit_count=0;
               font_count++;
            }
         }
      }
   }
   else
   {
      for (i=0;i<g2d_data->src_height;i++)
      {
         if (g2d_data->italic_mode==0)
         {

            x_pos=g2d_data->dest_x;
            y_pos=g2d_data->dest_y+i;
         }
         else
         {
            x_pos=g2d_data->dest_x+ (GET_G2D_TILT(i));
            y_pos=g2d_data->dest_y+i;
         }
         font_buff_ptr1=((kal_uint8 *)g2d_data->dest_base_address + ((y_pos*g2d_data->dest_pitch + x_pos)));

         for (j=0;j<g2d_data->src_width;j++)
         {
            font_bit = font_data & 0x01;
            if ((x_pos>=0)&&(y_pos>=0))
            {
               if (g2d_data->clip_mode)
               {
                  if ((x_pos>=g2d_data->clip_start_x) && (x_pos <=g2d_data->clip_end_x) &&
                     (y_pos>=g2d_data->clip_start_y) && (y_pos <=g2d_data->clip_end_y))
                  {  /* in clip range */
                     if (font_bit)
                     {
                        *(font_buff_ptr1+j) = g2d_data->pat_fg_color;
                     }
                     else
                     {
                        if (g2d_data->font_background_mode)
                           *(font_buff_ptr1+j) = g2d_data->pat_bg_color;
                     }
                  }
               }
               else
               {
                  if (font_bit)
                  {
                     *(font_buff_ptr1+j) = g2d_data->pat_fg_color;
                  }
                  else
                  {
                     if (g2d_data->font_background_mode)
                        *(font_buff_ptr1+j) = g2d_data->pat_bg_color;
                  }
               }
            }
            x_pos++;
            font_data>>=1;
            font_bit_count++;
            if (font_bit_count==8)
            {  /* get next byte */
               font_data=*(font_data_ptr+font_count);
               font_bit_count=0;
               font_count++;
            }
         }
      }
   }
#endif
}  /* g2d_sw_font_caching() */
#endif

void g2d_accelerator(g2d_parameter_struct *g2d_data)
{
#ifdef __MTK_TARGET__
#if defined(DRV_2D_ENGINE_V1)
   kal_uint8 run_twice=KAL_FALSE;
   kal_uint16 first_width,second_width;
   short temp_width_height;

   switch (g2d_data->g2d_operation_mode)
   {
      case G2D_OPERATION_LINE_DRAWING:
         if ((g2d_data->end_x<0)||(g2d_data->end_y<0))
            return;

         if (g2d_data->start_x<0)
         {
            if (g2d_data->start_y>g2d_data->end_y)
            {
               g2d_data->start_y=g2d_data->start_y-(g2d_data->start_y-g2d_data->end_y)*(0-g2d_data->start_x)
                                /(g2d_data->end_x-g2d_data->start_x);
            }
            else
            {
               g2d_data->start_y=g2d_data->start_y+(g2d_data->end_y-g2d_data->start_y)*(0-g2d_data->start_x)
                                /(g2d_data->end_x-g2d_data->start_x);
            }
            g2d_data->start_x=0;
         }

         if (g2d_data->start_y<0)
         {
            if (g2d_data->end_x!=0)
            {
               if (g2d_data->start_x<g2d_data->end_x)
                  g2d_data->start_x=g2d_data->start_y*g2d_data->end_x/(g2d_data->end_y-g2d_data->start_y)*(-1);
               else
                  g2d_data->start_x=g2d_data->start_x+g2d_data->start_y*(g2d_data->start_x-g2d_data->end_x)/
                                   (g2d_data->end_y-g2d_data->start_y);
            }
            g2d_data->start_y=0;
         }

         if (g2d_data->dest_color_mode==G2D_DEST_16BPP_LUT_DISABLE)
         {
            g2d_data->dest_base_address += ((g2d_data->start_y * g2d_data->dest_pitch_width + g2d_data->start_x)<<1);
            g2d_data->dest_pitch=(g2d_data->dest_pitch_width<<1);
         }
         else
         {
            g2d_data->dest_base_address += (g2d_data->start_y * g2d_data->dest_pitch_width + g2d_data->start_x);
            g2d_data->dest_pitch=(g2d_data->dest_pitch_width);
         }
         g2d_line_drawing(g2d_data);
      break;
      case G2D_OPERATION_FONT_CACHING:
         if ((g2d_data->dest_x>=0) && (g2d_data->dest_y>=0))
         {
            if (g2d_data->dest_color_mode==G2D_DEST_16BPP_LUT_DISABLE)
            {
               g2d_data->dest_base_address += ((g2d_data->dest_y * g2d_data->dest_pitch_width + g2d_data->dest_x)<<1);
               g2d_data->dest_pitch=(g2d_data->dest_pitch_width<<1);
            }
            else if (g2d_data->dest_color_mode==G2D_DEST_8BPP_LUT_DISABLE)
            {
               g2d_data->dest_base_address += (g2d_data->dest_y * g2d_data->dest_pitch_width + g2d_data->dest_x);
               g2d_data->dest_pitch=g2d_data->dest_pitch_width;
            }
            g2d_font_caching(g2d_data);
         }
         else
            g2d_sw_font_caching(g2d_data);
      break;
      default:
         if (g2d_data->g2d_operation_mode == G2D_OPERATION_BITBLT)
         {
            switch (g2d_data->bitblt_mode)
            {
               case BITBLT_TRANSFORM_MIRROR_ROTATE_90:
               case BITBLT_TRANSFORM_ROTATE_90:
               case BITBLT_TRANSFORM_ROTATE_270:
               case BITBLT_TRANSFORM_MIRROR_ROTATE_270:
                  g2d_data->dest_width=g2d_data->src_height;
                  g2d_data->dest_height=g2d_data->src_width;
               break;
               case BITBLT_TRANSFORM_ROTATE_180:
               case BITBLT_TRANSFORM_MIRROR:
               case BITBLT_TRANSFORM_MIRROR_ROTATE_180:
                  g2d_data->dest_width=g2d_data->src_width;
                  g2d_data->dest_height=g2d_data->src_height;
               break;
               case BITBLT_TRANSFORM_COPY:
                  if (((g2d_data->src_width!=g2d_data->dest_width)||
                       (g2d_data->src_height!=g2d_data->dest_height))&&
                      ((g2d_data->dest_x<0)||(g2d_data->dest_y<0)))
                  {
                     g2d_multi_bitblt(g2d_data);
                     return;
                  }
               break;
            }
         }
         else if (g2d_data->g2d_operation_mode==G2D_OPERATION_ALPHA_BLENDING)
         {
            g2d_data->dest_width=g2d_data->src_width;
            g2d_data->dest_height=g2d_data->src_height;
         }

         if (g2d_data->dest_x<0)
         {
            temp_width_height=g2d_data->dest_x+g2d_data->dest_width;
            if (temp_width_height<0)
               return;
            g2d_data->dest_width=temp_width_height;
            if (g2d_data->g2d_operation_mode == G2D_OPERATION_BITBLT)
            {
               switch (g2d_data->bitblt_mode)
               {
                  case BITBLT_TRANSFORM_ROTATE_90:
                  case BITBLT_TRANSFORM_MIRROR_ROTATE_90:
                     g2d_data->src_height=g2d_data->dest_width;
                  break;
                  case BITBLT_TRANSFORM_ROTATE_180:
                  case BITBLT_TRANSFORM_MIRROR:
                     g2d_data->src_width=g2d_data->dest_width;
                  break;
                  case BITBLT_TRANSFORM_ROTATE_270:
                  case BITBLT_TRANSFORM_MIRROR_ROTATE_270:
                     g2d_data->src_height=g2d_data->dest_width;
                     g2d_data->src_y-=g2d_data->dest_x;
                  break;
                  case BITBLT_TRANSFORM_COPY:
                  case BITBLT_TRANSFORM_MIRROR_ROTATE_180:
                     g2d_data->src_x-=g2d_data->dest_x;
                     g2d_data->src_width=g2d_data->dest_width;
                  break;
               }
            }
            else if (g2d_data->g2d_operation_mode == G2D_OPERATION_ALPHA_BLENDING)
            {
               g2d_data->src_x-=g2d_data->dest_x;
               g2d_data->src_width=g2d_data->dest_width;
            }
            g2d_data->dest_x=0;
         }

         if (g2d_data->dest_y<0)
         {
            temp_width_height=g2d_data->dest_y+g2d_data->dest_height;
            if (temp_width_height<0)
               return;
            g2d_data->dest_height=temp_width_height;
            if (g2d_data->g2d_operation_mode == G2D_OPERATION_BITBLT)
            {
               switch (g2d_data->bitblt_mode)
               {
                  case BITBLT_TRANSFORM_ROTATE_90:
                  case BITBLT_TRANSFORM_MIRROR_ROTATE_270:
                     g2d_data->src_width=g2d_data->dest_height;
                     g2d_data->src_x-=g2d_data->dest_y;
                  break;
                  case BITBLT_TRANSFORM_ROTATE_180:
                  case BITBLT_TRANSFORM_MIRROR_ROTATE_180:
                     g2d_data->src_height=g2d_data->dest_height;
                  break;
                  case BITBLT_TRANSFORM_ROTATE_270:
                  case BITBLT_TRANSFORM_MIRROR_ROTATE_90:
                     g2d_data->src_width=g2d_data->dest_height;
                  break;
                  case BITBLT_TRANSFORM_COPY:
                  case BITBLT_TRANSFORM_MIRROR:
                     g2d_data->src_y-=g2d_data->dest_y;
                     g2d_data->src_height=g2d_data->dest_height;
                  break;
               }
            }
            else if (g2d_data->g2d_operation_mode == G2D_OPERATION_ALPHA_BLENDING)
            {
               g2d_data->src_y-=g2d_data->dest_y;
               g2d_data->src_height=g2d_data->dest_height;
            }
            g2d_data->dest_y=0;
         }

         switch (g2d_data->dest_color_mode)
         {
            case G2D_DEST_16BPP_LUT_DISABLE:
            case G2D_DEST_16BPP_LUT_ENABLE:
               g2d_data->dest_pitch=(g2d_data->dest_pitch_width<<1);
               if (g2d_data->g2d_operation_mode==G2D_OPERATION_BITBLT)
               {
                  switch (g2d_data->bitblt_mode)
                  {
                     case BITBLT_TRANSFORM_COPY:
                     case BITBLT_TRANSFORM_MIRROR_ROTATE_270:
                        g2d_data->dest_base_address += ((g2d_data->dest_pitch_width * g2d_data->dest_y + g2d_data->dest_x)<<1);
                     break;
                     case BITBLT_TRANSFORM_ROTATE_90:
                     case BITBLT_TRANSFORM_MIRROR:
                        g2d_data->dest_base_address += ((g2d_data->dest_pitch_width * g2d_data->dest_y +
                                                       g2d_data->dest_x + g2d_data->dest_width-1)<<1);
                     break;
                     case BITBLT_TRANSFORM_ROTATE_180:
                     case BITBLT_TRANSFORM_MIRROR_ROTATE_90:
                        g2d_data->dest_base_address += ((g2d_data->dest_pitch_width * (g2d_data->dest_y+g2d_data->dest_height-1)+
                                                       g2d_data->dest_x + g2d_data->dest_width-1)<<1);
                     break;
                     case BITBLT_TRANSFORM_ROTATE_270 :
                     case BITBLT_TRANSFORM_MIRROR_ROTATE_180:
                        g2d_data->dest_base_address += ((g2d_data->dest_pitch_width * (g2d_data->dest_y+g2d_data->dest_height-1)+
                                                       g2d_data->dest_x)<<1);
                     break;
                  }
               }
               else
                  g2d_data->dest_base_address += ((g2d_data->dest_pitch_width * g2d_data->dest_y + g2d_data->dest_x)<<1);
            break;
            case G2D_DEST_8BPP_LUT_DISABLE:
               g2d_data->dest_pitch=g2d_data->dest_pitch_width;
               if (g2d_data->g2d_operation_mode==G2D_OPERATION_BITBLT)
               {
                  switch (g2d_data->bitblt_mode)
                  {
                     case BITBLT_TRANSFORM_COPY:
                     case BITBLT_TRANSFORM_MIRROR_ROTATE_270:
                        g2d_data->dest_base_address += ((g2d_data->dest_pitch_width * g2d_data->dest_y + g2d_data->dest_x));
                     break;
                     case BITBLT_TRANSFORM_ROTATE_90:
                     case BITBLT_TRANSFORM_MIRROR:
                        g2d_data->dest_base_address += ((g2d_data->dest_pitch_width * g2d_data->dest_y +
                                                       g2d_data->dest_x + g2d_data->dest_width-1));
                     break;
                     case BITBLT_TRANSFORM_ROTATE_180:
                     case BITBLT_TRANSFORM_MIRROR_ROTATE_90:
                        g2d_data->dest_base_address += ((g2d_data->dest_pitch_width * (g2d_data->dest_y+g2d_data->dest_height-1)+
                                                       g2d_data->dest_x + g2d_data->dest_width-1));
                     break;
                     case BITBLT_TRANSFORM_ROTATE_270 :
                     case BITBLT_TRANSFORM_MIRROR_ROTATE_180:
                        g2d_data->dest_base_address += ((g2d_data->dest_pitch_width * (g2d_data->dest_y+g2d_data->dest_height-1)+
                                                       g2d_data->dest_x));
                     break;
                  }
               }
               else
                  g2d_data->dest_base_address += (g2d_data->dest_pitch_width * g2d_data->dest_y + g2d_data->dest_x);
            break;
         }

         switch (g2d_data->src_color_mode)
         {
            case G2D_SRC_16BPP_LUT_DISABLE:
               g2d_data->src_pitch=(g2d_data->src_pitch_width<<1);
               g2d_data->src_base_address += ((g2d_data->src_pitch_width * g2d_data->src_y + g2d_data->src_x)<<1);
            break;
            case G2D_SRC_8BPP_LUT_DISABLE:
            case G2D_SRC_8BPP_LUT_ENABLE:
               g2d_data->src_pitch=g2d_data->src_pitch_width;
               g2d_data->src_base_address += (g2d_data->src_pitch_width * g2d_data->src_y + g2d_data->src_x);
            break;
         }
         if (g2d_data->dest_width==g2d_data->dest_pitch_width)
         {
            run_twice=KAL_TRUE;
            first_width=(g2d_data->dest_width>>1);
            second_width=g2d_data->dest_width-first_width;
            g2d_data->dest_width=first_width;
         }
         switch (g2d_data->g2d_operation_mode)
         {
            case G2D_OPERATION_RECTANGLE_FILL:
               g2d_rectangle_fill(g2d_data);
            break;
            case G2D_OPERATION_BITBLT:
               g2d_bitblt(g2d_data);
            break;
            case G2D_OPERATION_ALPHA_BLENDING:
               g2d_alpha_bitblt(g2d_data);
            break;
            case G2D_OPERATION_FONT_CACHING:
            break;
         }

         if (run_twice==KAL_TRUE)
         {
            g2d_data->dest_x+=first_width;
            if (g2d_data->dest_color_mode==G2D_DEST_16BPP_LUT_DISABLE)
            {
               g2d_data->src_base_address+=(first_width<<1);
               g2d_data->dest_base_address+=(first_width<<1);
            }
            else if (g2d_data->dest_color_mode==G2D_DEST_8BPP_LUT_DISABLE)
            {
               g2d_data->src_base_address+=(first_width);
               g2d_data->dest_base_address+=(first_width);
            }
            g2d_data->dest_width=second_width;
            switch (g2d_data->g2d_operation_mode)
            {
               case G2D_OPERATION_RECTANGLE_FILL:
                  g2d_rectangle_fill(g2d_data);
               break;
               case G2D_OPERATION_BITBLT:
                  g2d_bitblt(g2d_data);
               break;
               case G2D_OPERATION_ALPHA_BLENDING:
                  g2d_alpha_bitblt(g2d_data);
               break;
               case G2D_OPERATION_FONT_CACHING:
               break;
            }
         }
      break;
   }
#elif defined(DRV_2D_ENGINE_V2)
   g2d_data->src_pitch=g2d_data->src_pitch_width;
   g2d_data->dest_pitch=g2d_data->dest_pitch_width;
   switch (g2d_data->g2d_operation_mode)
   {
      case G2D_OPERATION_RECTANGLE_FILL:
         g2d_rectangle_fill(g2d_data);
      break;
      case G2D_OPERATION_FONT_CACHING:
         g2d_font_caching(g2d_data);
      break;
      case G2D_OPERATION_LINE_DRAWING:
         g2d_line_drawing(g2d_data);
      break;
      case G2D_OPERATION_CIRCLE_DRWAING:
         g2d_circle_drawing(g2d_data);
      break;
      case G2D_OPERATION_BEZIER_CURVE_DRAWING:
         g2d_bezier_curve_drawing(g2d_data);
      break;
      case G2D_OPERATION_TRIANGLE_FILL:
         g2d_triangle_fill(g2d_data);
      break;
      case G2D_OPERATION_BITBLT:
         g2d_bitblt(g2d_data);
      break;
      case G2D_OPERATION_ALPHA_BLENDING:
         g2d_alpha_bitblt(g2d_data);
      break;
      case G2D_OPERATION_ROP_BITBLT:
         g2d_rop_bitblt(g2d_data);
      break;
      case G2D_OPERATION_H_LINE_FILL:
         g2d_line_gradient_drawing(g2d_data);
      break;
      case G2D_OPERATION_H_LINE_COPY_MASK:
         g2d_line_copy_drawing(g2d_data);
      break;
   }
#endif
#endif
}  /* g2d_accelerator() */

/*************************************************************************
* FUNCTION
*     g2d_rectangle_fill
*
* DESCRIPTION
*     This function execute rectangle fill operation.
*
* PARAMETERS
*    g2d_data : the parameter data structure of G2D module
*
* RETURNS
*     None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void g2d_rectangle_fill(g2d_parameter_struct *g2d_data)
{
#ifdef __MTK_TARGET__
#if defined(DRV_2D_ENGINE_V1)
   g2d_power_on();

   g2d_set_clip_window(g2d_data);
   ENABLE_G2D_ENGINE_INT;
   if (G2D_ENGINE_IS_BUSY)
   {
      ENABLE_G2D_CMQ;
      while (G2D_CMQ_FREE_SPACE < 10) {};
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_DEST_BASE_L_ADDR | (g2d_data->dest_base_address & 0xFFFF)));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_DEST_BASE_H_ADDR | ((g2d_data->dest_base_address>>16) & 0xFFFF)));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_DEST_PITCH_ADDR | g2d_data->dest_pitch));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_DEST_Y_ADDR | g2d_data->dest_y));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_DEST_X_ADDR | g2d_data->dest_x));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_DEST_HEIGHT_ADDR | g2d_data->dest_height));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_DEST_WIDTH_ADDR | g2d_data->dest_width));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_PAT_FG_COLOR_ADDR | g2d_data->pat_fg_color));

      if (g2d_data->dest_color_mode==G2D_DEST_16BPP_LUT_DISABLE) {
         DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_FIRE_MODE_CTRL_REG_ADDR | FIRE_G2D_RECTANGLE_FILL));
      
      } else if (g2d_data->dest_color_mode==G2D_DEST_8BPP_LUT_DISABLE) {
         DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_FIRE_MODE_CTRL_REG_ADDR | (FIRE_G2D_RECTANGLE_FILL|FIRE_DEST_COLOR_8BPP_LUT_DIS)));
      
      } else {
         ASSERT(0);
      }
   }
   else
   {
      DISABLE_G2D_CMQ;
      DRV_WriteReg32(G2D_DEST_BASE_ADDRESS_REG,g2d_data->dest_base_address);
      DRV_WriteReg32(G2D_DEST_PITCH_REG,g2d_data->dest_pitch);
      DRV_WriteReg32(G2D_DEST_XY_REG,(g2d_data->dest_x<<16)|g2d_data->dest_y);
      DRV_WriteReg32(G2D_DEST_WIDTH_HEIGHT_REG,(g2d_data->dest_width<<16) | g2d_data->dest_height);
      DRV_WriteReg32(G2D_PAT_FG_COLOR_REG,g2d_data->pat_fg_color);
      if (g2d_data->dest_color_mode==G2D_DEST_16BPP_LUT_DISABLE)
      {
         SET_G2D_RECTANGLE_FILL_DEST_16BPP_LUT_DISABLE;
      }
      else if (g2d_data->dest_color_mode==G2D_DEST_8BPP_LUT_DISABLE)
      {
         SET_G2D_RECTANGLE_FILL_DEST_8BPP_LUT_DISABLE;
      }
      else
         ASSERT(0);
   }
   while (G2D_ENGINE_IS_BUSY) {};
//   kal_retrieve_eg_events(g2d_event_id,G2D_COMPLETE_EVENT,KAL_OR_CONSUME,&event_group,KAL_SUSPEND);
   g2d_power_off();
#elif defined(DRV_2D_ENGINE_V2)
   int temp_data;
   kal_uint32 temp_mode;
   kal_uint16 fire_mode;

   g2d_power_on();
   RESET_G2D_ENGINE;
   g2d_set_clip_window(g2d_data);
   if (g2d_data->g2d_cmq_mode==KAL_TRUE)
   {
      ENABLE_G2D_CMQ;
      temp_mode = REG_G2D_SUBMODE_CTRL;
      if (g2d_data->color_gradient_mode==G2D_REC_FILL_COLOR_GRAD_ENABLE)
      {
         while (G2D_CMQ_FREE_SPACE < 32) {};
         ENABLE_G2D_CMQ_WRITE;
         temp_data=(int) (g2d_data->alpha_gradient_x*(1<<16));
         G2D_WRITE_CMQ((G2D_CMQ_ALPHA_GRAD_X_L_ADDR|(temp_data & 0xFFFF)));
         G2D_WRITE_CMQ((G2D_CMQ_ALPHA_GRAD_X_H_ADDR|((temp_data>>16) & 0xFFFF)));
         temp_data=(int) (g2d_data->alpha_gradient_y*(1<<16));
         G2D_WRITE_CMQ((G2D_CMQ_ALPHA_GRAD_Y_L_ADDR|(temp_data & 0xFFFF)));
         G2D_WRITE_CMQ((G2D_CMQ_ALPHA_GRAD_Y_H_ADDR|((temp_data>>16) & 0xFFFF)));

         temp_data=(int) (g2d_data->red_gradient_x*(1<<16));
         G2D_WRITE_CMQ((G2D_CMQ_RED_GRAD_X_L_ADDR|(temp_data & 0xFFFF)));
         G2D_WRITE_CMQ((G2D_CMQ_RED_GRAD_X_H_ADDR|((temp_data>>16) & 0xFFFF)));
         temp_data=(int) (g2d_data->red_gradient_y*(1<<16));
         G2D_WRITE_CMQ((G2D_CMQ_RED_GRAD_Y_L_ADDR|(temp_data & 0xFFFF)));
         G2D_WRITE_CMQ((G2D_CMQ_RED_GRAD_Y_H_ADDR|((temp_data>>16) & 0xFFFF)));

         temp_data=(int) (g2d_data->green_gradient_x*(1<<16));
         G2D_WRITE_CMQ((G2D_CMQ_GREEN_GRAD_X_L_ADDR|(temp_data & 0xFFFF)));
         G2D_WRITE_CMQ((G2D_CMQ_GREEN_GRAD_X_H_ADDR|((temp_data>>16) & 0xFFFF)));
         temp_data=(int) (g2d_data->green_gradient_y*(1<<16));
         G2D_WRITE_CMQ((G2D_CMQ_GREEN_GRAD_Y_L_ADDR|(temp_data & 0xFFFF)));
         G2D_WRITE_CMQ((G2D_CMQ_GREEN_GRAD_Y_H_ADDR|((temp_data>>16) & 0xFFFF)));

         temp_data=(int) (g2d_data->blue_gradient_x*(1<<16));
         G2D_WRITE_CMQ((G2D_CMQ_BLUE_GRAD_X_L_ADDR|(temp_data & 0xFFFF)));
         G2D_WRITE_CMQ((G2D_CMQ_BLUE_GRAD_X_H_ADDR|((temp_data>>16) & 0xFFFF)));
         temp_data=(int) (g2d_data->blue_gradient_y*(1<<16));
         G2D_WRITE_CMQ((G2D_CMQ_BLUE_GRAD_Y_L_ADDR|(temp_data & 0xFFFF)));
         G2D_WRITE_CMQ((G2D_CMQ_BLUE_GRAD_Y_H_ADDR|((temp_data>>16) & 0xFFFF)));
         temp_mode |= REG_SUBMODE_CTRL_COLOR_GRADIENT_BIT;
      }
      else
      {
         while (G2D_CMQ_FREE_SPACE < 16)  {};
         ENABLE_G2D_CMQ_WRITE;
         temp_mode &= ~REG_SUBMODE_CTRL_COLOR_GRADIENT_BIT;
      }
      if (g2d_data->italic_mode==G2D_REC_FILL_ITALIC_ENABLE)
         temp_mode |= REG_SUBMODE_CTRL_ITALIC_BITBLT_BIT;
      else
         temp_mode &= ~REG_SUBMODE_CTRL_ITALIC_BITBLT_BIT;
      G2D_WRITE_CMQ(G2D_CMQ_SUBMODE_CTRL_REG_L_ADDR | (temp_mode & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_SUBMODE_CTRL_REG_H_ADDR | ((temp_mode & 0xFFFF)>>16));
      G2D_WRITE_CMQ(G2D_CMQ_DEST_BASE_L_ADDR | (g2d_data->dest_base_address & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_DEST_BASE_H_ADDR | ((g2d_data->dest_base_address>>16) & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_DEST_PITCH_ADDR | g2d_data->dest_pitch);
      G2D_WRITE_CMQ(G2D_CMQ_DEST_Y_ADDR | ((kal_uint16) g2d_data->dest_y));
      G2D_WRITE_CMQ(G2D_CMQ_DEST_X_ADDR | ((kal_uint16) g2d_data->dest_x));
      G2D_WRITE_CMQ(G2D_CMQ_DEST_HEIGHT_ADDR | g2d_data->dest_height);
      G2D_WRITE_CMQ(G2D_CMQ_DEST_WIDTH_ADDR | g2d_data->dest_width);
      G2D_WRITE_CMQ(G2D_CMQ_PAT_FG_COLOR_L_ADDR | (g2d_data->pat_fg_color&0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_PAT_FG_COLOR_H_ADDR | ((g2d_data->pat_fg_color&0xFFFF0000)>>16));

      temp_mode=REG_G2D_COMM_CTRL;
      if (g2d_data->clip_mode ==G2D_CLIP_ENABLE)
      {
         temp_mode |= REG_COMMON_CTRL_G2D_CLIP_ENABLE_BIT;
      }
      else
         temp_mode &= ~REG_COMMON_CTRL_G2D_CLIP_ENABLE_BIT;
      G2D_WRITE_CMQ(G2D_CMQ_2D_COMMON_CTRL_REG_ADDR | ((kal_uint16)temp_mode))

      G2D_WRITE_CMQ(G2D_CMQ_FIRE_MODE_CTRL_REG_ADDR |(g2d_data->dest_color_mode)|g2d_data->g2d_operation_mode);
      DISABLE_G2D_CMQ_WRITE;
      wait_cmq_start();
   }
   else
   {
      DISABLE_G2D_CMQ;
      SET_BITBLT_DIRECTION(BITBLT_TRANSFORM_DIRECTION_LT_CORNER);
      SET_BITBLT_TRANSFORM_MODE(BITBLT_TRANSFORM_COPY);
      g2d_set_clip_window(g2d_data);
      REG_G2D_DEST_BASE_ADDRESS = g2d_data->dest_base_address;
      REG_G2D_DEST_PITCH = g2d_data->dest_pitch_width;
      REG_G2D_DEST_XY = (g2d_data->dest_x<<16)|((kal_uint16) g2d_data->dest_y);
      REG_G2D_DEST_WIDTH_HEIGHT = (g2d_data->dest_width<<16) | g2d_data->dest_height;
      REG_G2D_PAT_FG_COLOR=g2d_data->pat_fg_color;
      if (g2d_data->color_gradient_mode==G2D_REC_FILL_COLOR_GRAD_ENABLE)
      {
         ENABLE_REC_FILL_COLOR_GRADIENT;
         REG_G2D_ALPHA_GRADIENT_X = (int) (g2d_data->alpha_gradient_x*(1<<16));
         REG_G2D_ALPHA_GRADIENT_Y = (int) (g2d_data->alpha_gradient_y*(1<<16));
         REG_G2D_RED_GRADIENT_X = (int) (g2d_data->red_gradient_x*(1<<16));
         REG_G2D_RED_GRADIENT_Y = (int) (g2d_data->red_gradient_y*(1<<16));
         REG_G2D_GREEN_GRADIENT_X = (int) (g2d_data->green_gradient_x*(1<<16));
         REG_G2D_GREEN_GRADIENT_Y = (int) (g2d_data->green_gradient_y*(1<<16));
         REG_G2D_BLUE_GRADIENT_X = (int) (g2d_data->blue_gradient_x*(1<<16));
         REG_G2D_BLUE_GRADIENT_Y = (int) (g2d_data->blue_gradient_y*(1<<16));
      }
      else
      {
         DISABLE_REC_FILL_COLOR_GRADIENT;
      }

      if (g2d_data->italic_mode==G2D_REC_FILL_ITALIC_ENABLE)
      {
         ENABLE_G2D_BITBLT_ITALIC_MODE;
      }
      else
      {
         DISABLE_G2D_BITBLT_ITALIC_MODE;
      }

      if (g2d_data->clip_mode ==G2D_CLIP_ENABLE)
      {
         ENABLE_G2D_ENGINE_CLIP;
      }
      else
      {
         DISABLE_G2D_ENGINE_CLIP
      }

      fire_mode=(g2d_data->dest_color_mode)|g2d_data->g2d_operation_mode;
      ENABLE_G2D_ENGINE_INT;
      REG_G2D_FIRE_CTRL=fire_mode;
   }

   while (G2D_ENGINE_IS_BUSY) {};
   g2d_power_off();
#endif
#endif
}  /* g2d_rectangle_fill() */

#if defined(DRV_2D_ENGINE_V2)
kal_uint8 g2d_bitblt_direction(g2d_parameter_struct *g2d_data)
{
   kal_uint32 src_start_address,src_end_address;
   kal_uint32 dest_start_address,dest_end_address;

   if (g2d_data->src_pitch!=g2d_data->dest_pitch)
   {
      ;  /* assert due to the different pitch of source and destination */
   }
   src_start_address=g2d_data->src_base_address;
   src_end_address=src_start_address+g2d_data->src_pitch * g2d_data->end_y;
   dest_start_address=g2d_data->dest_base_address;
   dest_end_address=dest_start_address + g2d_data->dest_pitch * g2d_data->end_y;

   if ((src_start_address<dest_end_address)||(src_end_address>dest_start_address))
      return BITBLT_TRANSFORM_DIRECTION_LT_CORNER;

   if (dest_start_address>src_end_address)
      return BITBLT_TRANSFORM_DIRECTION_RB_CORNER;

   return BITBLT_TRANSFORM_DIRECTION_LT_CORNER;
}  /* g2d_bitblt_direction() */
#endif

/*************************************************************************
* FUNCTION
*     g2d_bitblt
*
* DESCRIPTION
*     This function execute bitblt operation.
*
* PARAMETERS
*    g2d_data : the parameter data structure of G2D module
*
* RETURNS
*     None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void g2d_bitblt(g2d_parameter_struct *g2d_data)
{
#ifdef __MTK_TARGET__
#if defined(DRV_2D_ENGINE_V1)
   kal_uint16 temp_mode;
   
   if ((g2d_data->src_width == 0)  || (g2d_data->src_height == 0) ||
       (g2d_data->dest_width == 0) || (g2d_data->dest_width == 0)) {
      return;
   }

   g2d_power_on();
   switch (g2d_data->bitblt_mode)
   {
         case BITBLT_TRANSFORM_MIRROR_ROTATE_90:
         case BITBLT_TRANSFORM_ROTATE_90:
         case BITBLT_TRANSFORM_ROTATE_270:
         case BITBLT_TRANSFORM_MIRROR_ROTATE_270:
            if ((g2d_data->dest_width!=g2d_data->src_height)||(g2d_data->dest_height!=g2d_data->src_width))
               ASSERT(0);
         break;
         case BITBLT_TRANSFORM_ROTATE_180:
         case BITBLT_TRANSFORM_MIRROR:
         case BITBLT_TRANSFORM_MIRROR_ROTATE_180:
            if ((g2d_data->dest_width!=g2d_data->src_width)||(g2d_data->dest_height!=g2d_data->src_height))
               ASSERT(0);
         break;
         case BITBLT_TRANSFORM_COPY:
         break;
         default:
            ASSERT(0);
         break;
   }
   g2d_set_clip_window(g2d_data);
   ENABLE_G2D_ENGINE_INT;
   if (G2D_ENGINE_IS_BUSY)
   {
      ENABLE_G2D_CMQ;
      while (G2D_CMQ_FREE_SPACE < 20) {};
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_SRC_BASE_L_ADDR | (g2d_data->src_base_address & 0xFFFF)));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_SRC_BASE_H_ADDR | ((g2d_data->src_base_address>>16) & 0xFFFF)));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_DEST_BASE_L_ADDR | (g2d_data->dest_base_address & 0xFFFF)));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_DEST_BASE_H_ADDR | ((g2d_data->dest_base_address>>16) & 0xFFFF)));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_SRC_PITCH_ADDR | g2d_data->src_pitch));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_DEST_PITCH_ADDR | g2d_data->dest_pitch));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_SRC_Y_ADDR | g2d_data->src_y));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_SRC_X_ADDR | g2d_data->src_x));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_SRC_HEIGHT_ADDR | g2d_data->src_height));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_SRC_WIDTH_ADDR | g2d_data->src_width));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_DEST_HEIGHT_ADDR | g2d_data->dest_height));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_DEST_WIDTH_ADDR | g2d_data->dest_width));

      switch (g2d_data->bitblt_mode)
      {
         case BITBLT_TRANSFORM_MIRROR_ROTATE_90:
            DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_DEST_Y_ADDR | (g2d_data->dest_y+g2d_data->dest_height-1)));
            DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_DEST_X_ADDR | (g2d_data->dest_x+g2d_data->dest_width-1)));
         break;
         case BITBLT_TRANSFORM_ROTATE_90:
            DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_DEST_Y_ADDR | g2d_data->dest_y));
            DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_DEST_X_ADDR | (g2d_data->dest_x+g2d_data->dest_width-1)));
         break;
         case BITBLT_TRANSFORM_ROTATE_270:
            DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_DEST_Y_ADDR | (g2d_data->dest_y+g2d_data->dest_height-1)));
            DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_DEST_X_ADDR | g2d_data->dest_x));
         break;
         case BITBLT_TRANSFORM_MIRROR_ROTATE_270:
         case BITBLT_TRANSFORM_COPY:
            DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_DEST_Y_ADDR | g2d_data->dest_y));
            DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_DEST_X_ADDR | g2d_data->dest_x));
         break;
         case BITBLT_TRANSFORM_ROTATE_180:
            DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_DEST_Y_ADDR | (g2d_data->dest_y+g2d_data->dest_height-1)));
            DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_DEST_X_ADDR | (g2d_data->dest_x+g2d_data->dest_width-1)));
         break;
         case BITBLT_TRANSFORM_MIRROR:
            DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_DEST_Y_ADDR | g2d_data->dest_y));
            DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_DEST_X_ADDR | (g2d_data->dest_x+g2d_data->dest_width-1)));
         break;
         case BITBLT_TRANSFORM_MIRROR_ROTATE_180:
            DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_DEST_Y_ADDR | (g2d_data->dest_y+g2d_data->dest_height-1)));
            DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_DEST_X_ADDR | g2d_data->dest_x));
         break;
         default:
            ASSERT(0);
         break;
      }
      temp_mode=DRV_Reg32(G2D_SUBMODE_CTRL_REG);
      temp_mode &= ~REG_SUBMODE_CTRL_BITBLT_TRANSFORM_MASK;
      temp_mode |= g2d_data->bitblt_mode;
      
      if (g2d_data->src_key_mode==G2D_SRC_KEY_ENABLE) {
         temp_mode |= REG_SUBMODE_CTRL_BITBLT_TRANSPARENT_BIT;
         DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_SRCKEY_COLOR_ADDR|g2d_data->src_key_color));
      
      } else {
         temp_mode &= ~REG_SUBMODE_CTRL_BITBLT_TRANSPARENT_BIT;
      }

      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_SUBMODE_CTRL_REG_ADDR | temp_mode));

      if (g2d_data->src_color_mode==G2D_SRC_16BPP_LUT_DISABLE) {
         DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_FIRE_MODE_CTRL_REG_ADDR | FIRE_G2D_BITBLT));

      } else if (g2d_data->dest_color_mode==G2D_DEST_8BPP_LUT_DISABLE) {
         DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_FIRE_MODE_CTRL_REG_ADDR | (FIRE_G2D_BITBLT |FIRE_DEST_COLOR_8BPP_LUT_DIS)));

      } else if (g2d_data->dest_color_mode==G2D_DEST_16BPP_LUT_ENABLE) {
         temp_mode=DRV_Reg32(G2D_SUBMODE_CTRL_REG);
         temp_mode |= REG_COMMON_CTRL_G2D_PALETTE_ENABLE_BIT;
         DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_SUBMODE_CTRL_REG_ADDR | temp_mode));
         DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_FIRE_MODE_CTRL_REG_ADDR | (FIRE_G2D_BITBLT |FIRE_DEST_COLOR_16BPP_LUT_EN)));
      } else {
         ASSERT(0);
      }
   }
   else
   {
      DISABLE_G2D_CMQ;
      DRV_WriteReg32(G2D_SRC_BASE_ADDRESS_REG,g2d_data->src_base_address);
      DRV_WriteReg32(G2D_DEST_BASE_ADDRESS_REG,g2d_data->dest_base_address);
      DRV_WriteReg32(G2D_SRC_PITCH_REG,g2d_data->src_pitch);
      DRV_WriteReg32(G2D_DEST_PITCH_REG,g2d_data->dest_pitch);
      DRV_WriteReg32(G2D_SRC_XY_REG,((g2d_data->src_x<<16)|g2d_data->src_y));
      DRV_WriteReg32(G2D_SRC_WIDTH_HEIGHT_REG,((g2d_data->src_width<<16) | g2d_data->src_height));
      DRV_WriteReg32(G2D_DEST_WIDTH_HEIGHT_REG,((g2d_data->dest_width<<16) | g2d_data->dest_height));
      switch (g2d_data->bitblt_mode)
      {
         case BITBLT_TRANSFORM_MIRROR_ROTATE_90:
            DRV_WriteReg32(G2D_DEST_XY_REG,((g2d_data->dest_x+g2d_data->dest_width-1)<<16)|(g2d_data->dest_height+g2d_data->dest_y-1));
         break;
         case BITBLT_TRANSFORM_ROTATE_90:
            DRV_WriteReg32(G2D_DEST_XY_REG,((g2d_data->dest_x+g2d_data->dest_width-1)<<16)|(g2d_data->dest_y));
         break;
         case BITBLT_TRANSFORM_ROTATE_270:
            DRV_WriteReg32(G2D_DEST_XY_REG,(g2d_data->dest_x<<16)|(g2d_data->dest_height+g2d_data->dest_y-1));
         break;
         case BITBLT_TRANSFORM_MIRROR_ROTATE_270:
         case BITBLT_TRANSFORM_COPY:
            DRV_WriteReg32(G2D_DEST_XY_REG,(g2d_data->dest_x<<16)|(g2d_data->dest_y));
         break;
         case BITBLT_TRANSFORM_ROTATE_180:
            DRV_WriteReg32(G2D_DEST_XY_REG,((g2d_data->dest_x+g2d_data->dest_width-1)<<16)|(g2d_data->dest_height+g2d_data->dest_y-1));
         break;
         case BITBLT_TRANSFORM_MIRROR:
            DRV_WriteReg32(G2D_DEST_XY_REG,((g2d_data->dest_x+g2d_data->dest_width-1)<<16)|(g2d_data->dest_y));
         break;
         case BITBLT_TRANSFORM_MIRROR_ROTATE_180:
            DRV_WriteReg32(G2D_DEST_XY_REG,(g2d_data->dest_x<<16)|(g2d_data->dest_height+g2d_data->dest_y-1));
         break;
         default:
            ASSERT(0);
         break;
       }
      SET_BITBLT_TRANSFORM_MODE(g2d_data->bitblt_mode);
      if (g2d_data->src_key_mode==G2D_SRC_KEY_ENABLE)
      {
         ENABLE_BITBLT_TRANSPARENT;
         DRV_WriteReg32(G2D_SRC_KEY_COLOR_REG,g2d_data->src_key_color);
      }
      else
      {
         DISABLE_BITBLT_TRANSPARENT;
      }

      if (g2d_data->src_color_mode==G2D_SRC_16BPP_LUT_DISABLE)
      {
         DISABLE_G2D_ENGINE_PALETTE;
         SET_G2D_BITBLT_16BPP_LUT_DISABLE;
      }
      else if (g2d_data->dest_color_mode==G2D_DEST_8BPP_LUT_DISABLE)
      {
         DISABLE_G2D_ENGINE_PALETTE;
         SET_G2D_BITBLT_8BPP_LUT_DISABLE;
      }
      else if (g2d_data->dest_color_mode==G2D_DEST_16BPP_LUT_ENABLE)
      {
         ENABLE_G2D_ENGINE_PALETTE;
         SET_G2D_BITBLT_DEST_16BPP_LUT_ENABLE;
      }
      else
         ASSERT(0);
//    DISABLE_REG_G2D_ENGINE_PALETTE;
   }
   while (G2D_ENGINE_IS_BUSY) {};
//   kal_retrieve_eg_events(g2d_event_id,G2D_COMPLETE_EVENT,KAL_OR_CONSUME,&event_group,KAL_SUSPEND);
   g2d_power_off();
#elif defined(DRV_2D_ENGINE_V2)
   kal_uint16 fire_mode;
   kal_uint32 temp_mode;
   
   if ((g2d_data->src_width == 0)  || (g2d_data->src_height == 0) ||
        (g2d_data->dest_width == 0) || (g2d_data->dest_width == 0)) {
      return;
   }

   g2d_power_on();
   RESET_G2D_ENGINE;
   g2d_set_clip_window(g2d_data);
// if (G2D_ENGINE_IS_BUSY)
   if (g2d_data->g2d_cmq_mode==KAL_TRUE)
   {
      ENABLE_G2D_CMQ;
      while (G2D_CMQ_FREE_SPACE < 22) {};
      ENABLE_G2D_CMQ_WRITE;
      G2D_WRITE_CMQ(G2D_CMQ_SRC_BASE_L_ADDR | (g2d_data->src_base_address & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_SRC_BASE_H_ADDR | ((g2d_data->src_base_address>>16) & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_DEST_BASE_L_ADDR | (g2d_data->dest_base_address & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_DEST_BASE_H_ADDR | ((g2d_data->dest_base_address>>16) & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_SRC_PITCH_ADDR | g2d_data->src_pitch);
      G2D_WRITE_CMQ(G2D_CMQ_DEST_PITCH_ADDR | g2d_data->dest_pitch);
      G2D_WRITE_CMQ(G2D_CMQ_SRC_Y_ADDR | ((kal_uint16)g2d_data->src_y));
      G2D_WRITE_CMQ(G2D_CMQ_SRC_X_ADDR | ((kal_uint16) g2d_data->src_x));
      G2D_WRITE_CMQ(G2D_CMQ_SRC_HEIGHT_ADDR | g2d_data->src_height);
      G2D_WRITE_CMQ(G2D_CMQ_SRC_WIDTH_ADDR | g2d_data->src_width);
      G2D_WRITE_CMQ(G2D_CMQ_DEST_HEIGHT_ADDR | g2d_data->dest_height);
      G2D_WRITE_CMQ(G2D_CMQ_DEST_WIDTH_ADDR | g2d_data->dest_width);
      G2D_WRITE_CMQ(G2D_CMQ_SRCKEY_COLOR_L_ADDR | (g2d_data->src_key_color & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_SRCKEY_COLOR_H_ADDR | ((g2d_data->src_key_color>>16) & 0xFFFF));
      switch (g2d_data->bitblt_mode)
      {
         case BITBLT_TRANSFORM_MIRROR_ROTATE_90:
            G2D_WRITE_CMQ(G2D_CMQ_DEST_Y_ADDR | (g2d_data->dest_y+g2d_data->dest_height-1));
            G2D_WRITE_CMQ(G2D_CMQ_DEST_X_ADDR | (g2d_data->dest_x+g2d_data->dest_width-1));
         break;
         case BITBLT_TRANSFORM_ROTATE_90:
            G2D_WRITE_CMQ(G2D_CMQ_DEST_Y_ADDR | ((kal_uint16) g2d_data->dest_y));
            G2D_WRITE_CMQ(G2D_CMQ_DEST_X_ADDR | (g2d_data->dest_x+g2d_data->dest_width-1));
         break;
         case BITBLT_TRANSFORM_ROTATE_270:
            G2D_WRITE_CMQ(G2D_CMQ_DEST_Y_ADDR | (g2d_data->dest_y+g2d_data->dest_height-1));
            G2D_WRITE_CMQ(G2D_CMQ_DEST_X_ADDR | ((kal_uint16) g2d_data->dest_x));
         break;

         case BITBLT_TRANSFORM_MIRROR_ROTATE_270:
         case BITBLT_TRANSFORM_COPY:
            G2D_WRITE_CMQ(G2D_CMQ_DEST_Y_ADDR | ((kal_uint16) g2d_data->dest_y));
            G2D_WRITE_CMQ(G2D_CMQ_DEST_X_ADDR | ((kal_uint16) g2d_data->dest_x));
         break;
         case BITBLT_TRANSFORM_ROTATE_180:
            G2D_WRITE_CMQ(G2D_CMQ_DEST_Y_ADDR | (g2d_data->dest_y+g2d_data->dest_height-1));
            G2D_WRITE_CMQ(G2D_CMQ_DEST_X_ADDR | (g2d_data->dest_x+g2d_data->dest_width-1));
         break;
         case BITBLT_TRANSFORM_MIRROR:
            G2D_WRITE_CMQ(G2D_CMQ_DEST_Y_ADDR | ((kal_uint16) g2d_data->dest_y));
            G2D_WRITE_CMQ(G2D_CMQ_DEST_X_ADDR | (g2d_data->dest_x+g2d_data->dest_width-1));
         break;
         case BITBLT_TRANSFORM_MIRROR_ROTATE_180:
            G2D_WRITE_CMQ(G2D_CMQ_DEST_Y_ADDR | (g2d_data->dest_y+g2d_data->dest_height-1));
            G2D_WRITE_CMQ(G2D_CMQ_DEST_X_ADDR | ((kal_uint16) g2d_data->dest_x));
         break;
      }
      temp_mode=REG_G2D_SUBMODE_CTRL;
      temp_mode &= ~REG_SUBMODE_CTRL_BITBLT_TRANSFORM_MASK;
      temp_mode |= g2d_data->bitblt_mode;

      if (g2d_data->italic_mode==G2D_BITBLT_ITALIC_ENABLE)
         temp_mode |= REG_SUBMODE_CTRL_ITALIC_BITBLT_BIT;
      else
         temp_mode &= ~REG_SUBMODE_CTRL_ITALIC_BITBLT_BIT;

      if (g2d_data->bitblt_mode==BITBLT_TRANSFORM_COPY)
      {
         temp_mode &= ~REG_SUBMODE_CTRL_BITBLT_DIRECTION_MASK;
         temp_mode |= g2d_bitblt_direction(g2d_data);
      }
      else
         temp_mode |= BITBLT_TRANSFORM_DIRECTION_LT_CORNER;

      G2D_WRITE_CMQ(G2D_CMQ_SUBMODE_CTRL_REG_L_ADDR | (temp_mode & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_SUBMODE_CTRL_REG_H_ADDR | ((temp_mode & 0xFFFF)>>16));

      temp_mode=REG_G2D_COMM_CTRL;
      if (g2d_data->clip_mode ==G2D_CLIP_ENABLE)
         temp_mode |= REG_COMMON_CTRL_G2D_CLIP_ENABLE_BIT;
      else
         temp_mode &= ~REG_COMMON_CTRL_G2D_CLIP_ENABLE_BIT;
      if (g2d_data->src_key_mode==G2D_BITBLT_DEST_SRC_KEY_ENABLE)
         temp_mode |= REG_COMMON_CTRL_G2D_SRC_KEY_ENABLE_BIT;
      else
         temp_mode &= ~REG_COMMON_CTRL_G2D_SRC_KEY_ENABLE_BIT;

      G2D_WRITE_CMQ(G2D_CMQ_2D_COMMON_CTRL_REG_ADDR | ((kal_uint16)temp_mode))
      G2D_WRITE_CMQ(G2D_CMQ_FIRE_MODE_CTRL_REG_ADDR | (g2d_data->dest_color_mode)|
                    (g2d_data->src_color_mode)| g2d_data->g2d_operation_mode);
      DISABLE_G2D_CMQ_WRITE;
      wait_cmq_start();
   }
   else
   {
      DISABLE_G2D_CMQ;
      g2d_set_clip_window(g2d_data);
      REG_G2D_SRC_BASE_ADDRESS = g2d_data->src_base_address;
      REG_G2D_DEST_BASE_ADDRESS = g2d_data->dest_base_address;
      REG_G2D_SRC_PITCH = g2d_data->src_pitch;
      REG_G2D_DEST_PITCH = g2d_data->dest_pitch;
      REG_G2D_SRC_XY = (((kal_uint16) g2d_data->src_x)<<16)|((kal_uint16)g2d_data->src_y);
      REG_G2D_SRC_WIDTH_HEIGHT = (g2d_data->src_width<<16) | g2d_data->src_height;
      REG_G2D_DEST_WIDTH_HEIGHT = (g2d_data->dest_width<<16) | g2d_data->dest_height;
      REG_G2D_SRC_KEY_COLOR=g2d_data->src_key_color;

      switch (g2d_data->bitblt_mode)
      {
         case BITBLT_TRANSFORM_MIRROR_ROTATE_90:
            REG_G2D_DEST_XY = ((g2d_data->dest_x+g2d_data->dest_width-1)<<16)|(g2d_data->dest_height+g2d_data->dest_y-1);
         break;
         case BITBLT_TRANSFORM_ROTATE_90:
            REG_G2D_DEST_XY = ((g2d_data->dest_x+g2d_data->dest_width-1)<<16)|(((kal_uint16) g2d_data->dest_y));
         break;
         case BITBLT_TRANSFORM_ROTATE_270:
            REG_G2D_DEST_XY = (((kal_uint16) g2d_data->dest_x)<<16)|(g2d_data->dest_height+g2d_data->dest_y-1);
         break;
         case BITBLT_TRANSFORM_MIRROR_ROTATE_270:
         case BITBLT_TRANSFORM_COPY:
            REG_G2D_DEST_XY = (((kal_uint16) g2d_data->dest_x)<<16)|(((kal_uint16) g2d_data->dest_y));
         break;
         case BITBLT_TRANSFORM_ROTATE_180:
            REG_G2D_DEST_XY = ((g2d_data->dest_x+g2d_data->dest_width-1)<<16)|(g2d_data->dest_height+g2d_data->dest_y-1);
         break;
         case BITBLT_TRANSFORM_MIRROR:
            REG_G2D_DEST_XY = ((g2d_data->dest_x+g2d_data->dest_width-1)<<16)|(((kal_uint16) g2d_data->dest_y));
         break;
         case BITBLT_TRANSFORM_MIRROR_ROTATE_180:
            REG_G2D_DEST_XY = (((kal_uint16) g2d_data->dest_x)<<16)|(g2d_data->dest_height+g2d_data->dest_y-1);
         break;
       }
      SET_BITBLT_TRANSFORM_MODE(g2d_data->bitblt_mode);
      if (g2d_data->bitblt_mode==BITBLT_TRANSFORM_COPY)
      {
         SET_BITBLT_DIRECTION(g2d_bitblt_direction(g2d_data));
      }

      if (g2d_data->italic_mode==G2D_REC_FILL_ITALIC_ENABLE)
      {
         ENABLE_G2D_BITBLT_ITALIC_MODE;
      }
      else
      {
         DISABLE_G2D_BITBLT_ITALIC_MODE;
      }

      if (g2d_data->clip_mode ==G2D_CLIP_ENABLE)
      {
         ENABLE_G2D_ENGINE_CLIP;
      }
      else
      {
         DISABLE_G2D_ENGINE_CLIP
      }

      if (g2d_data->src_key_mode==G2D_BITBLT_DEST_SRC_KEY_ENABLE)
      {
         ENABLE_G2D_ENGINE_SRC_KEY;
      }
      else
      {
         DISABLE_G2D_ENGINE_SRC_KEY;
      }

      fire_mode=(g2d_data->src_color_mode)|(g2d_data->dest_color_mode)|g2d_data->g2d_operation_mode;
      ENABLE_G2D_ENGINE_INT;
      REG_G2D_FIRE_CTRL=fire_mode;
   }
   while (G2D_ENGINE_IS_BUSY) {};
   g2d_power_off();
#endif
#endif
}  /* g2d_bitblt() */

/*************************************************************************
* FUNCTION
*     g2d_alpha_bitblt
*
* DESCRIPTION
*     This function execute alpha blending operation.
*
* PARAMETERS
*    g2d_data : the parameter data structure of G2D module
*
* RETURNS
*     None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void g2d_alpha_bitblt(g2d_parameter_struct *g2d_data)
{
#ifdef __MTK_TARGET__
#if defined(DRV_2D_ENGINE_V1)
   kal_uint16 temp_mode;
// kal_uint32 event_group;

   g2d_power_on();

   g2d_set_clip_window(g2d_data);
   ENABLE_G2D_ENGINE_INT;
   if ((g2d_data->dest_width!=g2d_data->src_width)||
       (g2d_data->dest_height!=g2d_data->src_height))
       ASSERT(0);
   if (G2D_ENGINE_IS_BUSY)
   {
      ENABLE_G2D_CMQ;
      while (G2D_CMQ_FREE_SPACE < 20) {};
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_SRC_BASE_L_ADDR | (g2d_data->src_base_address & 0xFFFF)));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_SRC_BASE_H_ADDR | ((g2d_data->src_base_address>>16) & 0xFFFF)));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_DEST_BASE_L_ADDR | (g2d_data->dest_base_address & 0xFFFF)));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_DEST_BASE_H_ADDR | ((g2d_data->dest_base_address>>16) & 0xFFFF)));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_SRC_PITCH_ADDR | g2d_data->src_pitch));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_DEST_PITCH_ADDR | g2d_data->dest_pitch));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_SRC_Y_ADDR | g2d_data->src_y));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_SRC_X_ADDR | g2d_data->src_x));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_DEST_Y_ADDR | g2d_data->dest_y));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_DEST_X_ADDR | g2d_data->dest_x));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_SRC_HEIGHT_ADDR | g2d_data->src_height));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_SRC_WIDTH_ADDR | g2d_data->src_width));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_DEST_HEIGHT_ADDR | g2d_data->dest_height));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_DEST_WIDTH_ADDR | g2d_data->dest_width));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_SRC_ALPHA_ADDR | g2d_data->src_alpha));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_DEST_ALPHA_ADDR | g2d_data->dest_alpha));
      if (g2d_data->src_color_mode==G2D_SRC_16BPP_LUT_DISABLE)
      {
         DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_FIRE_MODE_CTRL_REG_ADDR | FIRE_G2D_ALPHA_BLENDING));
      }
      else if (g2d_data->src_color_mode==G2D_SRC_8BPP_LUT_ENABLE)
      {

         DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_FIRE_MODE_CTRL_REG_ADDR |(FIRE_G2D_ALPHA_BLENDING|FIRE_SRC_COLOR_8BPP_LUT_EN)));
         temp_mode=DRV_Reg32(G2D_SUBMODE_CTRL_REG);
         temp_mode |= REG_COMMON_CTRL_G2D_PALETTE_ENABLE_BIT;
         DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_SUBMODE_CTRL_REG_ADDR | temp_mode));
      }
      else
         ASSERT(0);
   }
   else
   {
      DISABLE_G2D_CMQ;
      DRV_WriteReg32(G2D_SRC_BASE_ADDRESS_REG, g2d_data->src_base_address);
      DRV_WriteReg32(G2D_DEST_BASE_ADDRESS_REG,g2d_data->dest_base_address);
      DRV_WriteReg32(G2D_SRC_PITCH_REG,g2d_data->src_pitch);
      DRV_WriteReg32(G2D_DEST_PITCH_REG,g2d_data->dest_pitch);
      DRV_WriteReg32(G2D_SRC_XY_REG,(g2d_data->src_x<<16)|g2d_data->src_y);
      DRV_WriteReg32(G2D_DEST_XY_REG,(g2d_data->dest_x<<16)|g2d_data->dest_y);
      DRV_WriteReg32(G2D_SRC_WIDTH_HEIGHT_REG,(g2d_data->src_width<<16) | g2d_data->src_height);
      DRV_WriteReg32(G2D_DEST_WIDTH_HEIGHT_REG,(g2d_data->dest_width<<16) | g2d_data->dest_height);
      REG_G2D_SRC_ALPHA =g2d_data->src_alpha;
      REG_G2D_DEST_ALPHA =g2d_data->dest_alpha;

      if (g2d_data->src_color_mode==G2D_SRC_16BPP_LUT_DISABLE)
      {
         SET_G2D_ALPHA_BLENDING_SRC_16BPP_LUT_DISABLE;
      }
      else if (g2d_data->src_color_mode==G2D_SRC_8BPP_LUT_ENABLE)
      {
         ENABLE_G2D_ENGINE_PALETTE;
         SET_G2D_ALPHA_BLENDING_SRC_8BPP_LUT_ENABLE;
      }
      else
         ASSERT(0);
//     DISABLE_REG_G2D_ENGINE_PALETTE;
   }
   while (G2D_ENGINE_IS_BUSY) {};
//   kal_retrieve_eg_events(g2d_event_id,G2D_COMPLETE_EVENT,KAL_OR_CONSUME,&event_group,KAL_SUSPEND);
   g2d_power_off();
#elif defined(DRV_2D_ENGINE_V2)
   kal_uint32 temp_mode;
   kal_uint16 fire_mode;

   g2d_power_on();
   RESET_G2D_ENGINE;
   g2d_set_clip_window(g2d_data);
// if (G2D_ENGINE_IS_BUSY)
   if (g2d_data->g2d_cmq_mode==KAL_TRUE)
   {
      ENABLE_G2D_CMQ;
      while (G2D_CMQ_FREE_SPACE < 22) {};
      ENABLE_G2D_CMQ_WRITE;
      G2D_WRITE_CMQ(G2D_CMQ_SRC_BASE_L_ADDR | (g2d_data->src_base_address & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_SRC_BASE_H_ADDR | ((g2d_data->src_base_address>>16) & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_DEST_BASE_L_ADDR | (g2d_data->dest_base_address & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_DEST_BASE_H_ADDR | ((g2d_data->dest_base_address>>16) & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_SRC_PITCH_ADDR | g2d_data->src_pitch);
      G2D_WRITE_CMQ(G2D_CMQ_DEST_PITCH_ADDR | g2d_data->dest_pitch);
      G2D_WRITE_CMQ(G2D_CMQ_SRC_Y_ADDR | ((kal_uint16)g2d_data->src_y));
      G2D_WRITE_CMQ(G2D_CMQ_SRC_X_ADDR | ((kal_uint16) g2d_data->src_x));
      G2D_WRITE_CMQ(G2D_CMQ_DEST_Y_ADDR | ((kal_uint16) g2d_data->dest_y));
      G2D_WRITE_CMQ(G2D_CMQ_DEST_X_ADDR | ((kal_uint16) g2d_data->dest_x));
      G2D_WRITE_CMQ(G2D_CMQ_SRC_HEIGHT_ADDR | g2d_data->src_height);
      G2D_WRITE_CMQ(G2D_CMQ_SRC_WIDTH_ADDR | g2d_data->src_width);
      G2D_WRITE_CMQ(G2D_CMQ_DEST_HEIGHT_ADDR | g2d_data->dest_height);
      G2D_WRITE_CMQ(G2D_CMQ_DEST_WIDTH_ADDR | g2d_data->dest_width);
      switch (g2d_data->bitblt_mode)
      {
         case BITBLT_TRANSFORM_MIRROR_ROTATE_90:
            G2D_WRITE_CMQ(G2D_CMQ_DEST_Y_ADDR | (g2d_data->dest_y+g2d_data->dest_height-1));
            G2D_WRITE_CMQ(G2D_CMQ_DEST_X_ADDR | (g2d_data->dest_x+g2d_data->dest_width-1));
         break;
         case BITBLT_TRANSFORM_ROTATE_90:
            G2D_WRITE_CMQ(G2D_CMQ_DEST_Y_ADDR | ((kal_uint16) g2d_data->dest_y));
            G2D_WRITE_CMQ(G2D_CMQ_DEST_X_ADDR | (g2d_data->dest_x+g2d_data->dest_width-1));
         break;
         case BITBLT_TRANSFORM_ROTATE_270:
            G2D_WRITE_CMQ(G2D_CMQ_DEST_Y_ADDR | (g2d_data->dest_y+g2d_data->dest_height-1));
            G2D_WRITE_CMQ(G2D_CMQ_DEST_X_ADDR | ((kal_uint16) g2d_data->dest_x));
         break;

         case BITBLT_TRANSFORM_MIRROR_ROTATE_270:
         case BITBLT_TRANSFORM_COPY:
            G2D_WRITE_CMQ(G2D_CMQ_DEST_Y_ADDR | ((kal_uint16) g2d_data->dest_y));
            G2D_WRITE_CMQ(G2D_CMQ_DEST_X_ADDR | ((kal_uint16) g2d_data->dest_x));
         break;
         case BITBLT_TRANSFORM_ROTATE_180:
            G2D_WRITE_CMQ(G2D_CMQ_DEST_Y_ADDR | (g2d_data->dest_y+g2d_data->dest_height-1));
            G2D_WRITE_CMQ(G2D_CMQ_DEST_X_ADDR | (g2d_data->dest_x+g2d_data->dest_width-1));
         break;
         case BITBLT_TRANSFORM_MIRROR:
            G2D_WRITE_CMQ(G2D_CMQ_DEST_Y_ADDR | ((kal_uint16) g2d_data->dest_y));
            G2D_WRITE_CMQ(G2D_CMQ_DEST_X_ADDR | (g2d_data->dest_x+g2d_data->dest_width-1));
         break;
         case BITBLT_TRANSFORM_MIRROR_ROTATE_180:
            G2D_WRITE_CMQ(G2D_CMQ_DEST_Y_ADDR | (g2d_data->dest_y+g2d_data->dest_height-1));
            G2D_WRITE_CMQ(G2D_CMQ_DEST_X_ADDR | ((kal_uint16) g2d_data->dest_x));
         break;
      }

      temp_mode = REG_G2D_SUBMODE_CTRL;
      if (g2d_data->italic_mode==G2D_BITBLT_ITALIC_ENABLE)
         temp_mode |= REG_SUBMODE_CTRL_ITALIC_BITBLT_BIT;
      else
         temp_mode &= ~REG_SUBMODE_CTRL_ITALIC_BITBLT_BIT;
      temp_mode &= ~REG_SUBMODE_CTRL_ALPHA_MASK;
      temp_mode |= (((kal_uint32)g2d_data->src_alpha)<<16);

      G2D_WRITE_CMQ(G2D_CMQ_SUBMODE_CTRL_REG_L_ADDR | (temp_mode & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_SUBMODE_CTRL_REG_H_ADDR | ((temp_mode & 0xFFFF0000)>>16));

      temp_mode=REG_G2D_COMM_CTRL;
      if (g2d_data->clip_mode ==G2D_CLIP_ENABLE)
      {
         temp_mode |= REG_COMMON_CTRL_G2D_CLIP_ENABLE_BIT;
      }
      else
         temp_mode &= ~REG_COMMON_CTRL_G2D_CLIP_ENABLE_BIT;
      G2D_WRITE_CMQ(G2D_CMQ_2D_COMMON_CTRL_REG_ADDR | ((kal_uint16)temp_mode))

      G2D_WRITE_CMQ(G2D_CMQ_FIRE_MODE_CTRL_REG_ADDR | (g2d_data->src_color_mode) |
                    (g2d_data->dest_color_mode) | g2d_data->g2d_operation_mode);
      DISABLE_G2D_CMQ_WRITE;
      wait_cmq_start();
   }
   else
   {
      DISABLE_G2D_CMQ;
      g2d_set_clip_window(g2d_data);
      REG_G2D_SRC_BASE_ADDRESS = g2d_data->src_base_address;
      REG_G2D_DEST_BASE_ADDRESS = g2d_data->dest_base_address;
      REG_G2D_SRC_PITCH = g2d_data->src_pitch;
      REG_G2D_DEST_PITCH = g2d_data->dest_pitch;
      REG_G2D_SRC_XY = (((kal_uint16) g2d_data->src_x)<<16)|((kal_uint16)g2d_data->src_y);
      REG_G2D_DEST_XY = (((kal_uint16) g2d_data->dest_x)<<16)|((kal_uint16) g2d_data->dest_y);
      REG_G2D_SRC_WIDTH_HEIGHT = (g2d_data->src_width<<16) | g2d_data->src_height;
      REG_G2D_DEST_WIDTH_HEIGHT = (g2d_data->dest_width<<16) | g2d_data->dest_height;

      REG_G2D_SRC_KEY_COLOR=g2d_data->src_key_color;
      switch (g2d_data->bitblt_mode)
      {
         case BITBLT_TRANSFORM_MIRROR_ROTATE_90:
            REG_G2D_DEST_XY = ((g2d_data->dest_x+g2d_data->dest_width-1)<<16)|(g2d_data->dest_height+g2d_data->dest_y-1);
         break;
         case BITBLT_TRANSFORM_ROTATE_90:
            REG_G2D_DEST_XY = ((g2d_data->dest_x+g2d_data->dest_width-1)<<16)|(((kal_uint16) g2d_data->dest_y));
         break;
         case BITBLT_TRANSFORM_ROTATE_270:
            REG_G2D_DEST_XY = (((kal_uint16) g2d_data->dest_x)<<16)|(g2d_data->dest_height+g2d_data->dest_y-1);
         break;
         case BITBLT_TRANSFORM_MIRROR_ROTATE_270:
         case BITBLT_TRANSFORM_COPY:
            REG_G2D_DEST_XY = (((kal_uint16) g2d_data->dest_x)<<16)|(((kal_uint16) g2d_data->dest_y));
         break;
         case BITBLT_TRANSFORM_ROTATE_180:
            REG_G2D_DEST_XY = ((g2d_data->dest_x+g2d_data->dest_width-1)<<16)|(g2d_data->dest_height+g2d_data->dest_y-1);
         break;
         case BITBLT_TRANSFORM_MIRROR:
            REG_G2D_DEST_XY = ((g2d_data->dest_x+g2d_data->dest_width-1)<<16)|(((kal_uint16) g2d_data->dest_y));
         break;
         case BITBLT_TRANSFORM_MIRROR_ROTATE_180:
            REG_G2D_DEST_XY = (((kal_uint16) g2d_data->dest_x)<<16)|(g2d_data->dest_height+g2d_data->dest_y-1);
         break;
       }
      SET_BITBLT_TRANSFORM_MODE(g2d_data->bitblt_mode);
      if (g2d_data->bitblt_mode==BITBLT_TRANSFORM_COPY)
      {
         SET_BITBLT_DIRECTION(g2d_bitblt_direction(g2d_data));
      }

      temp_mode = REG_G2D_SUBMODE_CTRL;

      if (g2d_data->italic_mode==G2D_BITBLT_ITALIC_ENABLE)
         temp_mode |= REG_SUBMODE_CTRL_ITALIC_BITBLT_BIT;
      else
         temp_mode &= ~REG_SUBMODE_CTRL_ITALIC_BITBLT_BIT;

      temp_mode &= ~REG_SUBMODE_CTRL_ALPHA_MASK;
      temp_mode |= (((kal_uint32)g2d_data->src_alpha)<<16);

      REG_G2D_SUBMODE_CTRL=temp_mode;
      if (g2d_data->clip_mode ==G2D_CLIP_ENABLE)
      {
         ENABLE_G2D_ENGINE_CLIP;
      }
      else
      {
         DISABLE_G2D_ENGINE_CLIP
      }
      if (g2d_data->src_key_mode==G2D_BITBLT_DEST_SRC_KEY_ENABLE)
      {
         ENABLE_G2D_ENGINE_SRC_KEY;
      }
      else
      {
         DISABLE_G2D_ENGINE_SRC_KEY;
      }

      fire_mode=(g2d_data->src_color_mode)|(g2d_data->dest_color_mode)|g2d_data->g2d_operation_mode;
      REG_G2D_FIRE_CTRL=fire_mode;
   }
   while (G2D_ENGINE_IS_BUSY) {};
   g2d_power_off();
#endif
#endif
}  /* g2d_alpha_bitblt() */

/*************************************************************************
* FUNCTION
*     g2d_line_drawing
*
* DESCRIPTION
*     This function execute line drawing operation.
*
* PARAMETERS
*    g2d_data : the parameter data structure of G2D module
*
* RETURNS
*     None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void g2d_line_drawing(g2d_parameter_struct *g2d_data)
{
#ifdef __MTK_TARGET__
#if defined(DRV_2D_ENGINE_V1)
   kal_uint16 width, height;
   kal_uint32 temp_ctrl_reg;
// kal_uint32 event_group;

   g2d_power_on();

   g2d_set_clip_window(g2d_data);
   ENABLE_G2D_ENGINE_INT;
   if (G2D_ENGINE_IS_BUSY)
   {
      ENABLE_G2D_CMQ;
      temp_ctrl_reg=DRV_Reg32(G2D_SUBMODE_CTRL_REG);
      if (g2d_data->dotted_mode==G2D_LINE_DOTTED_MODE)
         temp_ctrl_reg |= REG_SUBMODE_CTRL_DOTTED_LINE_BIT;
      else
         temp_ctrl_reg &= ~REG_SUBMODE_CTRL_DOTTED_LINE_BIT;

      if (g2d_data->end_x>g2d_data->start_x)
      {
         temp_ctrl_reg |= REG_SUBMODE_CTRL_X_INC_DEC_BIT;
         width=g2d_data->end_x-g2d_data->start_x;
      }
      else
      {
         temp_ctrl_reg &= ~REG_SUBMODE_CTRL_X_INC_DEC_BIT;
         width=g2d_data->start_x-g2d_data->end_x;
      }

      if (g2d_data->end_y>g2d_data->start_y)
      {
         temp_ctrl_reg |= REG_SUBMODE_CTRL_Y_INC_DEC_BIT;
         height=g2d_data->end_y-g2d_data->start_y;
      }
       else
      {
         temp_ctrl_reg &= ~REG_SUBMODE_CTRL_Y_INC_DEC_BIT;
         height=g2d_data->start_y-g2d_data->end_y;
      }

      while (G2D_CMQ_FREE_SPACE < 15) {};
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_DEST_BASE_L_ADDR | (g2d_data->dest_base_address & 0xFFFF)));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_DEST_BASE_H_ADDR | ((g2d_data->dest_base_address>>16) & 0xFFFF)));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_DEST_PITCH_ADDR | g2d_data->dest_pitch));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_Y_START_ADDR | g2d_data->start_y));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_X_START_ADDR | g2d_data->start_x));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_Y_END_ADDR | g2d_data->end_y));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_X_END_ADDR | g2d_data->end_x));

      if (width>height)
      {
         temp_ctrl_reg |= REG_SUBMODE_CTRL_XY_MAJOR_BIT;
         DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_SUBMODE_CTRL_REG_ADDR | temp_ctrl_reg));
         DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_K1_ADDR | (height<<1)));
         DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_K2_ADDR | (((short) (height-width))<<1)));
         DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_E_ADDR | ((short) ((height<<1) - width))));
      }
      else
      {
         temp_ctrl_reg &= ~REG_SUBMODE_CTRL_XY_MAJOR_BIT;
         DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_SUBMODE_CTRL_REG_ADDR | temp_ctrl_reg));
         DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_K1_ADDR | (width<<1)));
         DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_K2_ADDR | (((short) (width-height))<<1)));
         DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_E_ADDR | ((short) ((width<<1) - height))));
      }
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_PAT_FG_COLOR_ADDR | g2d_data->pat_fg_color));
      if (g2d_data->dest_color_mode==G2D_DEST_16BPP_LUT_DISABLE)
         DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_FIRE_MODE_CTRL_REG_ADDR | FIRE_G2D_LINE_DRAWING));
      else if (g2d_data->dest_color_mode==G2D_DEST_8BPP_LUT_DISABLE)
         DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_FIRE_MODE_CTRL_REG_ADDR | (FIRE_G2D_LINE_DRAWING |FIRE_DEST_COLOR_8BPP_LUT_DIS)));
   }
   else
   {
      DISABLE_G2D_CMQ;
      DRV_WriteReg32(G2D_DEST_BASE_ADDRESS_REG,g2d_data->dest_base_address);
      DRV_WriteReg32(G2D_DEST_PITCH_REG,g2d_data->dest_pitch);
      DRV_WriteReg32(G2D_XY_START_REG,(g2d_data->start_x<<16)|g2d_data->start_y);
      DRV_WriteReg32(G2D_XY_END_REG,(g2d_data->end_x<<16)|g2d_data->end_y);

      if (g2d_data->dotted_mode==G2D_LINE_DOTTED_MODE)
      {
         ENABLE_BITBLT_DOTTED_LINE;
      }
      else
      {
         DISABLE_BITBLT_DOTTED_LINE;
      }

      if (g2d_data->end_x>g2d_data->start_x)
      {
         SET_BITBLT_X_INCREAMENT;
         width=g2d_data->end_x-g2d_data->start_x;
      }
      else
      {
         SET_BITBLT_X_DECREAMENT;
         width=g2d_data->start_x-g2d_data->end_x;
      }

      if (g2d_data->end_y>g2d_data->start_y)
      {
         SET_BITBLT_Y_INCREAMENT;
         height=g2d_data->end_y-g2d_data->start_y;
      }
      else
      {
         SET_BITBLT_Y_DECREAMENT;
         height=g2d_data->start_y-g2d_data->end_y;
      }

      if (width>height)
      {
         SET_BITBLT_X_MAJOR;
         REG_G2D_K1=height<<1;
         REG_G2D_K2=((short) (height-width))<<1;
         REG_G2D_E=(short) ((height<<1) - width);
      }
      else
      {
         SET_BITBLT_Y_MAJOR;
         REG_G2D_K1=width<<1;
         REG_G2D_K2=((short) (width-height))<<1;
         REG_G2D_E=(short) ((width<<1) - height);
      }
      DRV_WriteReg32(G2D_PAT_FG_COLOR_REG,g2d_data->pat_fg_color);
      if (g2d_data->dest_color_mode==G2D_DEST_16BPP_LUT_DISABLE)
      {
         SET_G2D_LINE_DRAWING_DEST_16BPP_LUT_DISABLE;
      }
      else if (g2d_data->dest_color_mode==G2D_DEST_8BPP_LUT_DISABLE)
      {
         SET_G2D_LINE_DRAWING_DEST_8BPP_LUT_DISABLE;
      }
   }
   while (G2D_ENGINE_IS_BUSY) {};
//   kal_retrieve_eg_events(g2d_event_id,G2D_COMPLETE_EVENT,KAL_OR_CONSUME,&event_group,KAL_SUSPEND);

   g2d_power_off();
#elif defined(DRV_2D_ENGINE_V2)
   kal_uint32 temp_ctrl_reg;
   short delta_x,delta_y;
   kal_uint16 xy_sqrt=0;
   double temp_data1;
   kal_uint32 temp_data;
   kal_uint16 fire_mode;

   g2d_power_on();

   delta_x=g2d_data->end_x-g2d_data->start_x;
   delta_y=g2d_data->end_y-g2d_data->start_y;
   if (g2d_data->line_anti_alias_mode==G2D_LINE_ANTI_ALIAS_ENABLE)
   {
      temp_data=delta_x*delta_x + delta_y*delta_y;
      temp_data1=2*sqrt(temp_data);
      xy_sqrt=(kal_uint16) temp_data1;
   }

   RESET_G2D_ENGINE;
   g2d_set_clip_window(g2d_data);

   if (g2d_data->g2d_cmq_mode==KAL_TRUE)
   {
      ENABLE_G2D_CMQ;
      temp_ctrl_reg= REG_G2D_SUBMODE_CTRL;
      if (g2d_data->dotted_mode==G2D_LINE_DOTTED_MODE)
         temp_ctrl_reg |= REG_SUBMODE_CTRL_DOTTED_LINE_BIT;
      else
         temp_ctrl_reg &= ~REG_SUBMODE_CTRL_DOTTED_LINE_BIT;

      while (G2D_CMQ_FREE_SPACE < 15) {};
      ENABLE_G2D_CMQ_WRITE;

      G2D_WRITE_CMQ(G2D_CMQ_DEST_BASE_L_ADDR | (g2d_data->dest_base_address & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_DEST_BASE_H_ADDR | ((g2d_data->dest_base_address>>16) & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_DEST_PITCH_ADDR | g2d_data->dest_pitch);
      G2D_WRITE_CMQ(G2D_CMQ_Y_START_ADDR | ((kal_uint16) g2d_data->start_y));
      G2D_WRITE_CMQ(G2D_CMQ_X_START_ADDR | ((kal_uint16) g2d_data->start_x));
      G2D_WRITE_CMQ(G2D_CMQ_Y_END_ADDR | ((kal_uint16) g2d_data->end_y));
      G2D_WRITE_CMQ(G2D_CMQ_X_END_ADDR | ((kal_uint16) g2d_data->end_x));

      G2D_WRITE_CMQ(G2D_CMQ_PAT_FG_COLOR_L_ADDR | (g2d_data->pat_fg_color&0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_PAT_FG_COLOR_H_ADDR | ((g2d_data->pat_fg_color&0xFFFF0000)>>16));

      temp_ctrl_reg=REG_G2D_SUBMODE_CTRL;
      if (g2d_data->line_anti_alias_mode==G2D_LINE_ANTI_ALIAS_ENABLE)
      {
         temp_ctrl_reg |= REG_SUBMODE_CTRL_LINE_ANTI_ALIAS_BIT;
      }
      else
      {
         temp_ctrl_reg &= ~REG_SUBMODE_CTRL_LINE_ANTI_ALIAS_BIT;
      }
      if (g2d_data->dotted_mode==G2D_LINE_DOTTED_MODE)
      {
         temp_ctrl_reg |= REG_SUBMODE_CTRL_DOTTED_LINE_BIT;
      }
      else
      {
         temp_ctrl_reg &= ~REG_SUBMODE_CTRL_DOTTED_LINE_BIT;
      }

      G2D_WRITE_CMQ(G2D_CMQ_SUBMODE_CTRL_REG_L_ADDR | (temp_ctrl_reg & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_SUBMODE_CTRL_REG_H_ADDR | ((temp_ctrl_reg & 0xFFFF)>>16));

      temp_ctrl_reg=REG_G2D_COMM_CTRL;
      if (g2d_data->clip_mode ==G2D_CLIP_ENABLE)
      {
         temp_ctrl_reg |= REG_COMMON_CTRL_G2D_CLIP_ENABLE_BIT;
      }
      else
         temp_ctrl_reg &= ~REG_COMMON_CTRL_G2D_CLIP_ENABLE_BIT;
      G2D_WRITE_CMQ(G2D_CMQ_2D_COMMON_CTRL_REG_ADDR | ((kal_uint16)temp_ctrl_reg))

      G2D_WRITE_CMQ(G2D_CMQ_FIRE_MODE_CTRL_REG_ADDR |(g2d_data->dest_color_mode) | g2d_data->g2d_operation_mode);
      DISABLE_G2D_CMQ_WRITE;
      wait_cmq_start();
   }
   else
   {
      DISABLE_G2D_CMQ;
      g2d_set_clip_window(g2d_data);

      REG_G2D_DEST_BASE_ADDRESS = g2d_data->dest_base_address;
      REG_G2D_DEST_PITCH = g2d_data->dest_pitch;
      REG_G2D_XY_START = (((kal_uint16)(g2d_data->start_x))<<16)| ((kal_uint16)g2d_data->start_y);
      REG_G2D_XY_END = (((kal_uint16)g2d_data->end_x)<<16)|((kal_uint16)g2d_data->end_y);
      REG_G2D_LINE_XY_SQRT = (kal_uint32) xy_sqrt;
      temp_ctrl_reg=REG_G2D_SUBMODE_CTRL;
      if (g2d_data->line_anti_alias_mode==G2D_LINE_ANTI_ALIAS_ENABLE)
      {
         ENABLE_LINE_ANTI_ALIASING;
      }
      else
      {
         DISABLE_LINE_ANTI_ALIASING;
      }

      if (g2d_data->dotted_mode==G2D_LINE_DOTTED_MODE)
      {
         ENABLE_BITBLT_DOTTED_LINE;
      }
      else
      {
         DISABLE_BITBLT_DOTTED_LINE;
      }
      REG_G2D_PAT_FG_COLOR=g2d_data->pat_fg_color;
      if (g2d_data->clip_mode ==G2D_CLIP_ENABLE)
      {
         ENABLE_G2D_ENGINE_CLIP;
      }
      else
      {
         DISABLE_G2D_ENGINE_CLIP
      }
      fire_mode=(g2d_data->dest_color_mode)|g2d_data->g2d_operation_mode;
      ENABLE_G2D_ENGINE_INT;
      REG_G2D_FIRE_CTRL=fire_mode;
   }
   while (G2D_ENGINE_IS_BUSY) {};
   g2d_power_off();
#endif
#endif
} /* g2d_line_drawing() */

/*************************************************************************
* FUNCTION
*     g2d_font_caching
*
* DESCRIPTION
*     This function execute font caching operation.
*
* PARAMETERS
*    g2d_data : the parameter data structure of G2D module
*
* RETURNS
*     None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void g2d_font_caching(g2d_parameter_struct *g2d_data)
{
#ifdef __MTK_TARGET__
#if defined(DRV_2D_ENGINE_V1)
   kal_uint32 temp_ctrl_reg;
// kal_uint32 event_group;

   g2d_power_on();

   g2d_set_clip_window(g2d_data);
   ENABLE_G2D_ENGINE_INT;
   if (G2D_ENGINE_IS_BUSY)
   {
      ENABLE_G2D_CMQ;
      while (G2D_CMQ_FREE_SPACE < 18) {};

      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_SRC_BASE_L_ADDR | (g2d_data->src_base_address & 0xFFFF)));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_SRC_BASE_H_ADDR | ((g2d_data->src_base_address>>16) & 0xFFFF)));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_DEST_BASE_L_ADDR | (g2d_data->dest_base_address & 0xFFFF)));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_DEST_BASE_H_ADDR | ((g2d_data->dest_base_address>>16) & 0xFFFF)));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_SRC_HEIGHT_ADDR | g2d_data->src_height));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_SRC_WIDTH_ADDR | g2d_data->src_width));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_DEST_PITCH_ADDR | g2d_data->dest_pitch));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_DEST_Y_ADDR | g2d_data->dest_y));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_DEST_X_ADDR | g2d_data->dest_x));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_DEST_HEIGHT_ADDR | g2d_data->dest_height));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_DEST_WIDTH_ADDR | g2d_data->dest_width));

      temp_ctrl_reg=DRV_Reg32(G2D_SUBMODE_CTRL_REG);
      if (g2d_data->italic_mode==G2D_FONT_ITALIC_ENABLE)
         temp_ctrl_reg |=REG_SUBMODE_CTRL_ITALIC_FONT_BIT;
      else
         temp_ctrl_reg &=~REG_SUBMODE_CTRL_ITALIC_FONT_BIT;

      if (g2d_data->font_background_mode == G2D_FONT_BACKGROUND_ENABLE)
         temp_ctrl_reg |= REG_SUBMODE_CTRL_FONT_BACKGROUND_BIT;
      else
         temp_ctrl_reg &= ~REG_SUBMODE_CTRL_FONT_BACKGROUND_BIT;
      if (g2d_data->src_key_mode==G2D_SRC_KEY_ENABLE)
      {
         temp_ctrl_reg |= REG_SUBMODE_CTRL_BITBLT_TRANSPARENT_BIT;
         DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_SRCKEY_COLOR_ADDR|g2d_data->src_key_color));
      }
      else
         temp_ctrl_reg &= ~REG_SUBMODE_CTRL_BITBLT_TRANSPARENT_BIT;

      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_SUBMODE_CTRL_REG_ADDR | temp_ctrl_reg));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_PAT_FG_COLOR_ADDR | g2d_data->pat_fg_color));
      DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_PAT_BG_COLOR_ADDR | g2d_data->pat_bg_color));

      if (g2d_data->dest_color_mode==G2D_DEST_16BPP_LUT_DISABLE)
         DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_FIRE_MODE_CTRL_REG_ADDR | FIRE_G2D_FONT_CACHING));
      else if (g2d_data->dest_color_mode==G2D_DEST_8BPP_LUT_DISABLE)
         DRV_WriteReg32(G2D_CMQ_DATA_REG,(G2D_CMQ_FIRE_MODE_CTRL_REG_ADDR | (FIRE_G2D_FONT_CACHING |FIRE_DEST_COLOR_8BPP_LUT_DIS)));
   }
   else
   {
      DISABLE_G2D_CMQ;
      DRV_WriteReg32(G2D_SRC_BASE_ADDRESS_REG, g2d_data->src_base_address);
      DRV_WriteReg32(G2D_SRC_WIDTH_HEIGHT_REG,(g2d_data->src_width<<16) | g2d_data->src_height);
      DRV_WriteReg32(G2D_DEST_BASE_ADDRESS_REG,g2d_data->dest_base_address);
      DRV_WriteReg32(G2D_DEST_PITCH_REG,g2d_data->dest_pitch);
      DRV_WriteReg32(G2D_DEST_XY_REG,(g2d_data->dest_x<<16)|g2d_data->dest_y);
      DRV_WriteReg32(G2D_DEST_WIDTH_HEIGHT_REG,(g2d_data->dest_width<<16) | g2d_data->dest_height);
      if (g2d_data->italic_mode==G2D_FONT_ITALIC_ENABLE)
      {
         ENABLE_BITBLT_ITALIC_FONT;
      }
      else
      {
         DISABLE_BITBLT_ITALIC_FONT;
      }

      if (g2d_data->font_background_mode == G2D_FONT_BACKGROUND_ENABLE)
      {
         ENABLE_BITBLT_FONT_BACKGROUND;
      }
      else
      {
         DISABLE_BITBLT_FONT_BACKGROUND;
      }

      if (g2d_data->src_key_mode==G2D_SRC_KEY_ENABLE)
      {
         ENABLE_BITBLT_TRANSPARENT;
         DRV_WriteReg32(G2D_SRC_KEY_COLOR_REG,g2d_data->src_key_color);
      }
      else
      {
         DISABLE_BITBLT_TRANSPARENT;
      }
      DRV_WriteReg32(G2D_PAT_FG_COLOR_REG,g2d_data->pat_fg_color);
      DRV_WriteReg32(G2D_PAT_BG_COLOR_REG,g2d_data->pat_bg_color);
      if (g2d_data->dest_color_mode==G2D_DEST_16BPP_LUT_DISABLE)
      {
         SET_G2D_FONT_CACHING_DEST_16BPP_LUT_DISABLE;
      }
      else if (g2d_data->dest_color_mode==G2D_DEST_8BPP_LUT_DISABLE)
      {
         SET_G2D_FONT_CACHING_DEST_8BPP_LUT_DISABLE;
      }
   }
   while (G2D_ENGINE_IS_BUSY) {};
// kal_retrieve_eg_events(g2d_event_id,G2D_COMPLETE_EVENT,KAL_OR_CONSUME,&event_group,KAL_SUSPEND);

   g2d_power_off();
#elif defined(DRV_2D_ENGINE_V2)
   kal_uint32 temp_ctrl_reg;
   kal_uint16 fire_mode;

   g2d_power_on();
   RESET_G2D_ENGINE;
   g2d_set_clip_window(g2d_data);
// if (G2D_ENGINE_IS_BUSY)
   if (g2d_data->g2d_cmq_mode==KAL_TRUE)
   {
      ENABLE_G2D_CMQ;
      while (G2D_CMQ_FREE_SPACE < 22) {};

      ENABLE_G2D_CMQ_WRITE;
      G2D_WRITE_CMQ(G2D_CMQ_SRC_BASE_L_ADDR | (g2d_data->src_base_address & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_SRC_BASE_H_ADDR | ((g2d_data->src_base_address>>16) & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_DEST_BASE_L_ADDR | (g2d_data->dest_base_address & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_DEST_BASE_H_ADDR | ((g2d_data->dest_base_address>>16) & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_SRC_HEIGHT_ADDR | g2d_data->src_height);
      G2D_WRITE_CMQ(G2D_CMQ_SRC_WIDTH_ADDR | g2d_data->src_width);
      G2D_WRITE_CMQ(G2D_CMQ_DEST_PITCH_ADDR | g2d_data->dest_pitch);
      G2D_WRITE_CMQ(G2D_CMQ_DEST_Y_ADDR | ((kal_uint16) g2d_data->dest_y));
      G2D_WRITE_CMQ(G2D_CMQ_DEST_X_ADDR | ((kal_uint16) g2d_data->dest_x));
      G2D_WRITE_CMQ(G2D_CMQ_DEST_HEIGHT_ADDR | g2d_data->dest_height);
      G2D_WRITE_CMQ(G2D_CMQ_DEST_WIDTH_ADDR | g2d_data->dest_width);

      temp_ctrl_reg= REG_G2D_SUBMODE_CTRL;
      if (g2d_data->italic_mode==G2D_FONT_ITALIC_ENABLE)
         temp_ctrl_reg |=REG_SUBMODE_CTRL_ITALIC_FONT_BIT;
      else
         temp_ctrl_reg &=~REG_SUBMODE_CTRL_ITALIC_FONT_BIT;

      if (g2d_data->font_background_mode == G2D_FONT_BACKGROUND_ENABLE)
         temp_ctrl_reg &= ~REG_SUBMODE_CTRL_FONT_BACKGROUND_BIT;
      else
         temp_ctrl_reg |= REG_SUBMODE_CTRL_FONT_BACKGROUND_BIT;

      if (g2d_data->font_order==G2D_FONT_ORDER_LSB_FIRST)
         temp_ctrl_reg &= ~REG_SUBMODE_CTRL_FONT_ORDER_BIT;
      else
         temp_ctrl_reg |= REG_SUBMODE_CTRL_FONT_ORDER_BIT;

      temp_ctrl_reg &=~REG_SUBMODE_CTRL_START_BIT_MASK;
      temp_ctrl_reg |= (g2d_data->font_start_position<<16);

      G2D_WRITE_CMQ(G2D_CMQ_SUBMODE_CTRL_REG_L_ADDR | (temp_ctrl_reg & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_SUBMODE_CTRL_REG_H_ADDR | ((temp_ctrl_reg & 0xFFFF0000)>>16));

      G2D_WRITE_CMQ(G2D_CMQ_PAT_FG_COLOR_L_ADDR | (g2d_data->pat_fg_color&0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_PAT_FG_COLOR_H_ADDR | ((g2d_data->pat_fg_color&0xFFFF0000)>>16));
      G2D_WRITE_CMQ(G2D_CMQ_PAT_BG_COLOR_L_ADDR | (g2d_data->pat_bg_color&0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_PAT_BG_COLOR_H_ADDR | ((g2d_data->pat_bg_color&0xFFFF0000)>>16));

      temp_ctrl_reg=REG_G2D_COMM_CTRL;
      if (g2d_data->clip_mode ==G2D_CLIP_ENABLE)
      {
         temp_ctrl_reg |= REG_COMMON_CTRL_G2D_CLIP_ENABLE_BIT;
      }
      else
         temp_ctrl_reg &= ~REG_COMMON_CTRL_G2D_CLIP_ENABLE_BIT;
      G2D_WRITE_CMQ(G2D_CMQ_2D_COMMON_CTRL_REG_ADDR | ((kal_uint16)temp_ctrl_reg))
      G2D_WRITE_CMQ(G2D_CMQ_FIRE_MODE_CTRL_REG_ADDR |(g2d_data->dest_color_mode) | g2d_data->g2d_operation_mode);
      DISABLE_G2D_CMQ_WRITE;
      wait_cmq_start();
   }
   else
   {
      DISABLE_G2D_CMQ;
      SET_BITBLT_DIRECTION(BITBLT_TRANSFORM_DIRECTION_LT_CORNER);
      SET_BITBLT_TRANSFORM_MODE(BITBLT_TRANSFORM_COPY);
      g2d_set_clip_window(g2d_data);
      REG_G2D_SRC_BASE_ADDRESS = g2d_data->src_base_address;
      REG_G2D_SRC_WIDTH_HEIGHT = (g2d_data->src_width<<16) | g2d_data->src_height;
      REG_G2D_DEST_BASE_ADDRESS = g2d_data->dest_base_address;
      REG_G2D_DEST_PITCH = g2d_data->dest_pitch;
      REG_G2D_DEST_XY = (g2d_data->dest_x<<16)|((kal_uint16) g2d_data->dest_y);
      REG_G2D_DEST_WIDTH_HEIGHT = (g2d_data->src_width<<16) | g2d_data->src_height;
      if (g2d_data->italic_mode==G2D_FONT_ITALIC_ENABLE)
      {
         ENABLE_BITBLT_ITALIC_FONT;
      }
      else
      {
         DISABLE_BITBLT_ITALIC_FONT;
      }

      if (g2d_data->font_background_mode == G2D_FONT_BACKGROUND_ENABLE)
      {
         ENABLE_BITBLT_FONT_BACKGROUND;
      }
      else
      {
         DISABLE_BITBLT_FONT_BACKGROUND;
      }

      if (g2d_data->font_order==G2D_FONT_ORDER_LSB_FIRST)
      {
         SET_G2D_FONT_LSB_FIRST;
      }
      else
      {
         SET_G2D_FONT_MSB_FIRST;
      }

      REG_G2D_PAT_FG_COLOR = g2d_data->pat_fg_color;
      REG_G2D_PAT_BG_COLOR = g2d_data->pat_bg_color;
      if (g2d_data->clip_mode ==G2D_CLIP_ENABLE)
      {
         ENABLE_G2D_ENGINE_CLIP;
      }
      else
      {
         DISABLE_G2D_ENGINE_CLIP
      }
      SET_FONT_START_BIT(g2d_data->font_start_position);
      fire_mode=(g2d_data->dest_color_mode)|g2d_data->g2d_operation_mode;
      ENABLE_G2D_ENGINE_INT;
      REG_G2D_FIRE_CTRL=fire_mode;
   }
   while (G2D_ENGINE_IS_BUSY) {};
   g2d_power_off();
#endif
#endif
} /* g2d_font_caching() */

void g2d_font_begin(kal_uint32 dest_address,kal_uint16 dest_pitch,kal_bool is_italic,
                  int clipx1,int clipy1,
                  int clipx2,int clipy2)
{
#ifdef __MTK_TARGET__
   g2d_power_on();

      dest_pitch <<=1; // Currently, we only use 16bit

      g2d_control_data.dest_base_address = dest_address;
      g2d_control_data.dest_pitch = dest_pitch;

      g2d_control_data.clip_start_x = clipx1;
      g2d_control_data.clip_start_y    = clipy1;
      g2d_control_data.clip_end_x   = clipx2;
      g2d_control_data.clip_end_y   = clipy2;
#endif
}

void g2d_font_color(kal_uint32 fg_color)
{
#ifdef __MTK_TARGET__
   if(fg_color)
      g2d_control_data.pat_fg_color = fg_color;
   else
      g2d_control_data.pat_fg_color = 1;
#endif
}
void g2d_font_end(void)
{
#ifdef __MTK_TARGET__
   while (G2D_ENGINE_IS_BUSY) {};
   g2d_power_off();
#endif
}
void g2d_font_draw(kal_uint32 font_address, int width,int height,int x,int y)
{  /* optimize for font drawing () */
#ifdef __MTK_TARGET__
#if defined(DRV_2D_ENGINE_V1)
   int width_height = width << 16 | height;

   while (G2D_ENGINE_IS_BUSY) {};
   RESET_G2D_ENGINE;

   DISABLE_G2D_CMQ;
   DRV_WriteReg32(G2D_CLP_LT_REG,((g2d_control_data.clip_start_x <<16) | g2d_control_data.clip_start_y));
   DRV_WriteReg32(G2D_CLP_RB_REG,((g2d_control_data.clip_end_x <<16) | g2d_control_data.clip_end_y));
   ENABLE_G2D_ENGINE_CLIP;

   ENABLE_G2D_ENGINE_INT;
   {
      DRV_WriteReg32(G2D_SRC_BASE_ADDRESS_REG, font_address);
      DRV_WriteReg32(G2D_SRC_WIDTH_HEIGHT_REG   ,width_height);
      DRV_WriteReg32(G2D_DEST_BASE_ADDRESS_REG,g2d_control_data.dest_base_address
                                       +(x<<1)
                                       +g2d_control_data.dest_pitch * y);
      DRV_WriteReg32(G2D_DEST_PITCH_REG,g2d_control_data.dest_pitch);
      DRV_WriteReg32(G2D_DEST_XY_REG,(x<<16)|y);
      DRV_WriteReg32(G2D_DEST_WIDTH_HEIGHT_REG,width_height);
      DISABLE_BITBLT_ITALIC_FONT;
      DISABLE_BITBLT_FONT_BACKGROUND;
      DISABLE_BITBLT_TRANSPARENT;

      DRV_WriteReg32(G2D_PAT_FG_COLOR_REG,g2d_control_data.pat_fg_color);
      DRV_WriteReg32(G2D_PAT_BG_COLOR_REG,0);
         SET_G2D_FONT_CACHING_DEST_16BPP_LUT_DISABLE; // fire
   }
#endif
#endif
}

void g2d_rectangle_fill_without_clip(kal_uint32 dest_address,kal_uint32 dest_pitch,int x,int y,kal_uint32 width_height,kal_uint32 color)
{  /* optimize for rectangle fill */
#ifdef __MTK_TARGET__
#if defined(DRV_2D_ENGINE_V1)
   g2d_power_on();

   DISABLE_G2D_ENGINE_CLIP;
   ENABLE_G2D_ENGINE_INT;
      DISABLE_G2D_CMQ;
      dest_pitch <<=1; // Currently, we only use 16bit
      DRV_WriteReg32(G2D_DEST_BASE_ADDRESS_REG,dest_address
                                       +(x<<1)
                                       +dest_pitch * y);
      DRV_WriteReg32(G2D_DEST_XY_REG,(x<<16)|y);
      DRV_WriteReg32(G2D_DEST_PITCH_REG,dest_pitch);
      DRV_WriteReg32(G2D_DEST_WIDTH_HEIGHT_REG,width_height);
      DRV_WriteReg32(G2D_PAT_FG_COLOR_REG,color);
         SET_G2D_RECTANGLE_FILL_DEST_16BPP_LUT_DISABLE;

   while (G2D_ENGINE_IS_BUSY) {};
   g2d_power_off();
#endif
#endif
}  /* g2d_rectangle_fill_without_clip() */

#if defined(DRV_2D_ENGINE_V2)
void g2d_triangle_fill(g2d_parameter_struct *g2d_data)
{
#ifdef __MTK_TARGET__
#if defined(DRV_2D_ENGINE_V2)
   kal_uint32 temp_mode;
   kal_uint16 fire_mode;
   volatile kal_bool two_triangle=KAL_TRUE;

   g2d_get_triangle_slope(g2d_data->start_x,g2d_data->start_y,g2d_data->middle_x,
                          g2d_data->middle_y,g2d_data->end_x,g2d_data->end_y,
                          &g2d_triangle_para_data);

   g2d_power_on();
   RESET_G2D_ENGINE;
   g2d_set_clip_window(g2d_data);
// if (G2D_ENGINE_IS_BUSY)
   if (g2d_data->g2d_cmq_mode==KAL_TRUE)
   {
      ENABLE_G2D_CMQ;

      while (G2D_CMQ_FREE_SPACE < 22) {};

      ENABLE_G2D_CMQ_WRITE;
      G2D_WRITE_CMQ(G2D_CMQ_DEST_BASE_L_ADDR | (g2d_data->dest_base_address & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_DEST_BASE_H_ADDR | ((g2d_data->dest_base_address>>16) & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_DEST_PITCH_ADDR | g2d_data->dest_pitch);
      G2D_WRITE_CMQ(G2D_CMQ_Y_START_ADDR | ((kal_uint16)g2d_triangle_para_data.first_y));
      G2D_WRITE_CMQ(G2D_CMQ_X_START_ADDR | ((kal_uint16) g2d_triangle_para_data.first_x));
      G2D_WRITE_CMQ(G2D_CMQ_TRIANGLE_Y_END_ADDR | ((kal_uint16)g2d_triangle_para_data.middle_y));
      G2D_WRITE_CMQ(G2D_CMQ_TRIANGLE_SLOPE_R_L_ADDR | (g2d_triangle_para_data.slope2 & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_TRIANGLE_SLOPE_R_H_ADDR | ((g2d_triangle_para_data.slope2 & 0xFFFF0000)>>16));
      G2D_WRITE_CMQ(G2D_CMQ_TRIANGLE_SLOPE_L_L_ADDR | (g2d_triangle_para_data.slope1 & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_TRIANGLE_SLOPE_L_H_ADDR | ((g2d_triangle_para_data.slope1 & 0xFFFF0000)>>16));
      G2D_WRITE_CMQ(G2D_CMQ_PAT_FG_COLOR_L_ADDR | (g2d_data->pat_fg_color&0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_PAT_FG_COLOR_H_ADDR | ((g2d_data->pat_fg_color&0xFFFF0000)>>16));

      temp_mode=REG_G2D_COMM_CTRL;
      if (g2d_data->clip_mode ==G2D_CLIP_ENABLE)
      {
         temp_mode |= REG_COMMON_CTRL_G2D_CLIP_ENABLE_BIT;
      }
      else
         temp_mode &= ~REG_COMMON_CTRL_G2D_CLIP_ENABLE_BIT;
      G2D_WRITE_CMQ(G2D_CMQ_2D_COMMON_CTRL_REG_ADDR | ((kal_uint16)temp_mode))

      G2D_WRITE_CMQ(G2D_CMQ_FIRE_MODE_CTRL_REG_ADDR |(g2d_data->dest_color_mode) |
                    g2d_data->g2d_operation_mode);

      if (two_triangle==KAL_TRUE)
      {
         G2D_WRITE_CMQ(G2D_CMQ_Y_START_ADDR | ((kal_uint16)g2d_triangle_para_data.second_y));
         G2D_WRITE_CMQ(G2D_CMQ_X_START_ADDR | ((kal_uint16) g2d_triangle_para_data.second_x));
         G2D_WRITE_CMQ(G2D_CMQ_TRIANGLE_Y_END_ADDR | ((kal_uint16)g2d_triangle_para_data.middle_y));
         G2D_WRITE_CMQ(G2D_CMQ_TRIANGLE_SLOPE_R_L_ADDR | (g2d_triangle_para_data.slope4 & 0xFFFF));
         G2D_WRITE_CMQ(G2D_CMQ_TRIANGLE_SLOPE_R_H_ADDR | ((g2d_triangle_para_data.slope4 & 0xFFFF0000)>>16));
         G2D_WRITE_CMQ(G2D_CMQ_TRIANGLE_SLOPE_L_L_ADDR | (g2d_triangle_para_data.slope3 & 0xFFFF));
         G2D_WRITE_CMQ(G2D_CMQ_TRIANGLE_SLOPE_L_H_ADDR | ((g2d_triangle_para_data.slope3 & 0xFFFF0000)>>16));
         G2D_WRITE_CMQ(G2D_CMQ_FIRE_MODE_CTRL_REG_ADDR |(g2d_data->dest_color_mode) |
                       g2d_data->g2d_operation_mode);
      }
      DISABLE_G2D_CMQ_WRITE;
      wait_cmq_start();
      while (G2D_ENGINE_IS_BUSY) {};
   }
   else
   {
      DISABLE_G2D_CMQ;
//    g2d_set_clip_window(g2d_data);
      REG_G2D_DEST_BASE_ADDRESS = g2d_data->dest_base_address;
      REG_G2D_DEST_PITCH = g2d_data->dest_pitch;
      REG_G2D_XY_START = (((kal_uint16) g2d_triangle_para_data.first_x)<<16)|((kal_uint16) g2d_triangle_para_data.first_y);
      REG_G2D_TRIANGLE_Y_END = ((kal_uint16) g2d_triangle_para_data.middle_y);
      REG_G2D_TRIANGLE_SLOPE_L =g2d_triangle_para_data.slope1;
      REG_G2D_TRIANGLE_SLOPE_R =g2d_triangle_para_data.slope2;
      REG_G2D_PAT_FG_COLOR = g2d_data->pat_fg_color;

      if (g2d_data->clip_mode ==G2D_CLIP_ENABLE)
      {
         ENABLE_G2D_ENGINE_CLIP;
      }
      else
      {
         DISABLE_G2D_ENGINE_CLIP
      }
      fire_mode=(g2d_data->dest_color_mode)|g2d_data->g2d_operation_mode;
      REG_G2D_FIRE_CTRL=fire_mode;
      while (G2D_ENGINE_IS_BUSY) {};
      if (two_triangle==KAL_TRUE)
      {
         REG_G2D_XY_START = (((kal_uint16) g2d_triangle_para_data.second_x)<<16)|((kal_uint16) g2d_triangle_para_data.second_y);
         REG_G2D_TRIANGLE_SLOPE_L =g2d_triangle_para_data.slope3;
         REG_G2D_TRIANGLE_SLOPE_R =g2d_triangle_para_data.slope4;
         REG_G2D_FIRE_CTRL=fire_mode;
         while (G2D_ENGINE_IS_BUSY) {};
      }
   }
#endif
#endif
}  /* g2d_triangle_fill() */

void g2d_rop_bitblt(g2d_parameter_struct *g2d_data)
{
#ifdef __MTK_TARGET__
#if defined(DRV_2D_ENGINE_V2)
   kal_uint32 temp_mode;
   kal_uint16 fire_mode;

   g2d_power_on();
   RESET_G2D_ENGINE;
   g2d_set_clip_window(g2d_data);
// if (G2D_ENGINE_IS_BUSY)
   if (g2d_data->g2d_cmq_mode==KAL_TRUE)
   {
      ENABLE_G2D_CMQ;
      while (G2D_CMQ_FREE_SPACE < 22) {};
      ENABLE_G2D_CMQ_WRITE;
      G2D_WRITE_CMQ(G2D_CMQ_SRC_BASE_L_ADDR | (g2d_data->src_base_address & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_SRC_BASE_H_ADDR | ((g2d_data->src_base_address>>16) & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_DEST_BASE_L_ADDR | (g2d_data->dest_base_address & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_DEST_BASE_H_ADDR | ((g2d_data->dest_base_address>>16) & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_SRC_PITCH_ADDR | g2d_data->src_pitch);
      G2D_WRITE_CMQ(G2D_CMQ_DEST_PITCH_ADDR | g2d_data->dest_pitch);
      G2D_WRITE_CMQ(G2D_CMQ_SRC_Y_ADDR | ((kal_uint16) g2d_data->src_y));
      G2D_WRITE_CMQ(G2D_CMQ_SRC_X_ADDR | ((kal_uint16) g2d_data->src_x));
      G2D_WRITE_CMQ(G2D_CMQ_DEST_Y_ADDR | ((kal_uint16) g2d_data->dest_y));
      G2D_WRITE_CMQ(G2D_CMQ_DEST_X_ADDR | ((kal_uint16) g2d_data->dest_x));
      G2D_WRITE_CMQ(G2D_CMQ_SRC_HEIGHT_ADDR | g2d_data->src_height);
      G2D_WRITE_CMQ(G2D_CMQ_SRC_WIDTH_ADDR | g2d_data->src_width);
      G2D_WRITE_CMQ(G2D_CMQ_DEST_HEIGHT_ADDR | g2d_data->dest_height);
      G2D_WRITE_CMQ(G2D_CMQ_DEST_WIDTH_ADDR | g2d_data->dest_width);

      switch (g2d_data->bitblt_mode)
      {
         case BITBLT_TRANSFORM_MIRROR_ROTATE_90:
            G2D_WRITE_CMQ(G2D_CMQ_DEST_Y_ADDR | (g2d_data->dest_y+g2d_data->dest_height-1));
            G2D_WRITE_CMQ(G2D_CMQ_DEST_X_ADDR | (g2d_data->dest_x+g2d_data->dest_width-1));
         break;
         case BITBLT_TRANSFORM_ROTATE_90:
            G2D_WRITE_CMQ(G2D_CMQ_DEST_Y_ADDR | ((kal_uint16) g2d_data->dest_y));
            G2D_WRITE_CMQ(G2D_CMQ_DEST_X_ADDR | (g2d_data->dest_x+g2d_data->dest_width-1));
         break;
         case BITBLT_TRANSFORM_ROTATE_270:
            G2D_WRITE_CMQ(G2D_CMQ_DEST_Y_ADDR | (g2d_data->dest_y+g2d_data->dest_height-1));
            G2D_WRITE_CMQ(G2D_CMQ_DEST_X_ADDR | ((kal_uint16) g2d_data->dest_x));
         break;

         case BITBLT_TRANSFORM_MIRROR_ROTATE_270:
         case BITBLT_TRANSFORM_COPY:
            G2D_WRITE_CMQ(G2D_CMQ_DEST_Y_ADDR | ((kal_uint16) g2d_data->dest_y));
            G2D_WRITE_CMQ(G2D_CMQ_DEST_X_ADDR | ((kal_uint16) g2d_data->dest_x));
         break;
         case BITBLT_TRANSFORM_ROTATE_180:
            G2D_WRITE_CMQ(G2D_CMQ_DEST_Y_ADDR | (g2d_data->dest_y+g2d_data->dest_height-1));
            G2D_WRITE_CMQ(G2D_CMQ_DEST_X_ADDR | (g2d_data->dest_x+g2d_data->dest_width-1));
         break;
         case BITBLT_TRANSFORM_MIRROR:
            G2D_WRITE_CMQ(G2D_CMQ_DEST_Y_ADDR | ((kal_uint16) g2d_data->dest_y));
            G2D_WRITE_CMQ(G2D_CMQ_DEST_X_ADDR | (g2d_data->dest_x+g2d_data->dest_width-1));
         break;
         case BITBLT_TRANSFORM_MIRROR_ROTATE_180:
            G2D_WRITE_CMQ(G2D_CMQ_DEST_Y_ADDR | (g2d_data->dest_y+g2d_data->dest_height-1));
            G2D_WRITE_CMQ(G2D_CMQ_DEST_X_ADDR | ((kal_uint16) g2d_data->dest_x));
         break;
      }

      temp_mode = REG_G2D_SUBMODE_CTRL;
      if (g2d_data->italic_mode==G2D_REC_FILL_ITALIC_ENABLE)
         temp_mode |= REG_SUBMODE_CTRL_ITALIC_FONT_BIT;
      else
         temp_mode &= ~REG_SUBMODE_CTRL_ITALIC_FONT_BIT;

      temp_mode &= ~REG_SUBMODE_CTRL_ROP_CODE_MASK;
      temp_mode |= (((kal_uint32)g2d_data->rop_mode)<<16);

      G2D_WRITE_CMQ(G2D_CMQ_SUBMODE_CTRL_REG_L_ADDR | (temp_mode & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_SUBMODE_CTRL_REG_H_ADDR | ((temp_mode & 0xFFFF0000)>>16));

      temp_mode=REG_G2D_COMM_CTRL;
      if (g2d_data->clip_mode ==G2D_CLIP_ENABLE)
      {
         temp_mode |= REG_COMMON_CTRL_G2D_CLIP_ENABLE_BIT;
      }
      else
         temp_mode &= ~REG_COMMON_CTRL_G2D_CLIP_ENABLE_BIT;
      G2D_WRITE_CMQ(G2D_CMQ_2D_COMMON_CTRL_REG_ADDR | ((kal_uint16)temp_mode))
      G2D_WRITE_CMQ(G2D_CMQ_FIRE_MODE_CTRL_REG_ADDR | (g2d_data->src_color_mode) |
                    (g2d_data->dest_color_mode) | g2d_data->g2d_operation_mode);
      DISABLE_G2D_CMQ_WRITE;
      wait_cmq_start();
   }
   else
   {
      DISABLE_G2D_CMQ;
//    g2d_set_clip_window(g2d_data);
      REG_G2D_SRC_BASE_ADDRESS = g2d_data->src_base_address;
      REG_G2D_DEST_BASE_ADDRESS = g2d_data->dest_base_address;
      REG_G2D_SRC_PITCH = g2d_data->src_pitch;
      REG_G2D_DEST_PITCH = g2d_data->dest_pitch;
      REG_G2D_SRC_XY = (((kal_uint16) g2d_data->src_x)<<16)|((kal_uint16)g2d_data->src_y);
      REG_G2D_DEST_XY = (g2d_data->dest_x<<16)|((kal_uint16) g2d_data->dest_y);
      REG_G2D_SRC_WIDTH_HEIGHT = (g2d_data->src_width<<16) | g2d_data->src_height;
      REG_G2D_DEST_WIDTH_HEIGHT = (g2d_data->dest_width<<16) | g2d_data->dest_height;
      REG_G2D_SRC_KEY_COLOR=g2d_data->src_key_color;
      switch (g2d_data->bitblt_mode)
      {
         case BITBLT_TRANSFORM_MIRROR_ROTATE_90:
            REG_G2D_DEST_XY = ((g2d_data->dest_x+g2d_data->dest_width-1)<<16)|(g2d_data->dest_height+g2d_data->dest_y-1);
         break;
         case BITBLT_TRANSFORM_ROTATE_90:
            REG_G2D_DEST_XY = ((g2d_data->dest_x+g2d_data->dest_width-1)<<16)|(((kal_uint16) g2d_data->dest_y));
         break;
         case BITBLT_TRANSFORM_ROTATE_270:
            REG_G2D_DEST_XY = (((kal_uint16) g2d_data->dest_x)<<16)|(g2d_data->dest_height+g2d_data->dest_y-1);
         break;
         case BITBLT_TRANSFORM_MIRROR_ROTATE_270:
         case BITBLT_TRANSFORM_COPY:
            REG_G2D_DEST_XY = (((kal_uint16) g2d_data->dest_x)<<16)|(((kal_uint16) g2d_data->dest_y));
         break;
         case BITBLT_TRANSFORM_ROTATE_180:
            REG_G2D_DEST_XY = ((g2d_data->dest_x+g2d_data->dest_width-1)<<16)|(g2d_data->dest_height+g2d_data->dest_y-1);
         break;
         case BITBLT_TRANSFORM_MIRROR:
            REG_G2D_DEST_XY = ((g2d_data->dest_x+g2d_data->dest_width-1)<<16)|(((kal_uint16) g2d_data->dest_y));
         break;
         case BITBLT_TRANSFORM_MIRROR_ROTATE_180:
            REG_G2D_DEST_XY = (((kal_uint16) g2d_data->dest_x)<<16)|(g2d_data->dest_height+g2d_data->dest_y-1);
         break;
      }
      SET_BITBLT_TRANSFORM_MODE(g2d_data->bitblt_mode);

      temp_mode = REG_G2D_SUBMODE_CTRL;
      if (g2d_data->italic_mode==G2D_BITBLT_ITALIC_ENABLE)
         temp_mode |= REG_SUBMODE_CTRL_ITALIC_BITBLT_BIT;
      else
         temp_mode &= ~REG_SUBMODE_CTRL_ITALIC_BITBLT_BIT;

      temp_mode &= ~REG_SUBMODE_CTRL_ROP_CODE_MASK;
      temp_mode |= (((kal_uint32)g2d_data->rop_mode)<<16);
      REG_G2D_SUBMODE_CTRL=temp_mode;

      if (g2d_data->clip_mode ==G2D_CLIP_ENABLE)
      {
         ENABLE_G2D_ENGINE_CLIP;
      }
      else
      {
         DISABLE_G2D_ENGINE_CLIP
      }
      if (g2d_data->src_key_mode==G2D_BITBLT_DEST_SRC_KEY_ENABLE)
      {
         ENABLE_G2D_ENGINE_SRC_KEY;
      }
      else
      {
         DISABLE_G2D_ENGINE_SRC_KEY;
      }

      fire_mode=(g2d_data->src_color_mode)|(g2d_data->dest_color_mode)|g2d_data->g2d_operation_mode;
      REG_G2D_FIRE_CTRL=fire_mode;
   }
   while (G2D_ENGINE_IS_BUSY) {};

   g2d_power_off();
#endif
#endif
}  /* g2d_rop_bitblt() */

void g2d_circle_drawing(g2d_parameter_struct *g2d_data)
{
#ifdef __MTK_TARGET__
#if defined(DRV_2D_ENGINE_V2)
   kal_uint32 temp_mode;
   kal_uint16 fire_mode;

   g2d_power_on();
   RESET_G2D_ENGINE;
   g2d_set_clip_window(g2d_data);
// if (G2D_ENGINE_IS_BUSY)
   if (g2d_data->g2d_cmq_mode==KAL_TRUE)
   {
      ENABLE_G2D_CMQ;
      while (G2D_CMQ_FREE_SPACE < 13) {};

      ENABLE_G2D_CMQ_WRITE;
      G2D_WRITE_CMQ(G2D_CMQ_DEST_BASE_L_ADDR | (g2d_data->dest_base_address & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_DEST_BASE_H_ADDR | ((g2d_data->dest_base_address>>16) & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_DEST_PITCH_ADDR | g2d_data->dest_pitch);
      G2D_WRITE_CMQ(G2D_CMQ_CIRCLE_CENTER_Y_ADDR | ((kal_uint16)g2d_data->start_y));
      G2D_WRITE_CMQ(G2D_CMQ_CIRCLE_CENTER_X_ADDR | ((kal_uint16) g2d_data->start_x));
      G2D_WRITE_CMQ(G2D_CMQ_CIRCLE_RADIUS_ADDR | g2d_data->circle_radius);
      G2D_WRITE_CMQ(G2D_CMQ_PAT_FG_COLOR_L_ADDR | (g2d_data->pat_fg_color&0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_PAT_FG_COLOR_H_ADDR | ((g2d_data->pat_fg_color&0xFFFF0000)>>16));

      temp_mode = REG_G2D_SUBMODE_CTRL;
      temp_mode &= ~REG_SUBMODE_CTRL_ENABLE_ARCS_MASK;
      temp_mode |= (((kal_uint32)g2d_data->circle_drawing_arc)<<16);

      G2D_WRITE_CMQ(G2D_CMQ_SUBMODE_CTRL_REG_L_ADDR | (temp_mode & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_SUBMODE_CTRL_REG_H_ADDR | ((temp_mode & 0xFFFF0000)>>16));

      temp_mode=REG_G2D_COMM_CTRL;
      if (g2d_data->clip_mode ==G2D_CLIP_ENABLE)
      {
         temp_mode |= REG_COMMON_CTRL_G2D_CLIP_ENABLE_BIT;
      }
      else
         temp_mode &= ~REG_COMMON_CTRL_G2D_CLIP_ENABLE_BIT;
      G2D_WRITE_CMQ(G2D_CMQ_2D_COMMON_CTRL_REG_ADDR | ((kal_uint16)temp_mode))
      G2D_WRITE_CMQ(G2D_CMQ_FIRE_MODE_CTRL_REG_ADDR | (g2d_data->dest_color_mode) |
                    g2d_data->g2d_operation_mode);
      DISABLE_G2D_CMQ_WRITE;
      wait_cmq_start();
   }
   else
   {
      DISABLE_G2D_CMQ;
//    g2d_set_clip_window(g2d_data);
      REG_G2D_DEST_BASE_ADDRESS = g2d_data->dest_base_address;
      REG_G2D_DEST_PITCH = g2d_data->dest_pitch;
      REG_G2D_CIRCLE_CENTER = (((kal_uint16) g2d_data->start_x)<<16)|((kal_uint16) g2d_data->start_y);
      REG_G2D_CIRCLE_RADIUS = g2d_data->circle_radius;

      REG_G2D_PAT_FG_COLOR = g2d_data->pat_fg_color;
      temp_mode = REG_G2D_SUBMODE_CTRL;

      temp_mode &= ~REG_SUBMODE_CTRL_ENABLE_ARCS_MASK;
      temp_mode |= (((kal_uint32)g2d_data->circle_drawing_arc)<<16);

      REG_G2D_SUBMODE_CTRL=temp_mode;
      if (g2d_data->clip_mode ==G2D_CLIP_ENABLE)
      {
         ENABLE_G2D_ENGINE_CLIP;
      }
      else
      {
         DISABLE_G2D_ENGINE_CLIP
      }
      fire_mode=(g2d_data->dest_color_mode)|g2d_data->g2d_operation_mode;
      ENABLE_G2D_ENGINE_INT;
      REG_G2D_FIRE_CTRL=fire_mode;
   }
   while (G2D_ENGINE_IS_BUSY) {};
   g2d_power_off();
#endif
#endif
}  /* g2d_circle_drawing() */

void g2d_bezier_curve_drawing(g2d_parameter_struct *g2d_data)
{
#ifdef __MTK_TARGET__
#if defined(DRV_2D_ENGINE_V2)
   kal_uint32 temp_mode;
   kal_uint16 fire_mode;

   g2d_power_on();
   DISABLE_G2D_CMQ;
   RESET_G2D_ENGINE;
   g2d_set_clip_window(g2d_data);
   if (g2d_data->g2d_cmq_mode==KAL_TRUE)
   {
      DISABLE_G2D_CMQ;
      ENABLE_G2D_CMQ;
      while (G2D_CMQ_FREE_SPACE < 18) {};

      ENABLE_G2D_CMQ_WRITE;
      G2D_WRITE_CMQ(G2D_CMQ_DEST_BASE_L_ADDR | (g2d_data->dest_base_address & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_DEST_BASE_H_ADDR | ((g2d_data->dest_base_address>>16) & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_DEST_PITCH_ADDR | g2d_data->dest_pitch);
      G2D_WRITE_CMQ(G2D_CMQ_BEZIER_START_Y_ADDR | ((kal_uint16)g2d_data->start_y));
      G2D_WRITE_CMQ(G2D_CMQ_BEZIER_START_X_ADDR | ((kal_uint16) g2d_data->start_x));
      G2D_WRITE_CMQ(G2D_CMQ_BEZIER_MIDDLE_Y_ADDR | ((kal_uint16)g2d_data->middle_y));
      G2D_WRITE_CMQ(G2D_CMQ_BEZIER_MIDDLE_X_ADDR | ((kal_uint16) g2d_data->middle_x));
      G2D_WRITE_CMQ(G2D_CMQ_BEZIER_END_Y_ADDR | ((kal_uint16)g2d_data->end_y));
      G2D_WRITE_CMQ(G2D_CMQ_BEZIER_END_X_ADDR | ((kal_uint16) g2d_data->end_x));
      G2D_WRITE_CMQ(G2D_CMQ_BEZIER_SUBDIV_TIME_ADDR | ((g2d_data->bezier_curve_divide_time) & 0x0F));
      G2D_WRITE_CMQ(G2D_CMQ_BEZIER_BUF_START_L_ADDR | (g2d_data->buffer_address & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_BEZIER_BUF_START_H_ADDR | ((g2d_data->buffer_address & 0xFFFF0000)>>16));
      G2D_WRITE_CMQ(G2D_CMQ_PAT_FG_COLOR_L_ADDR | (g2d_data->pat_fg_color&0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_PAT_FG_COLOR_H_ADDR | ((g2d_data->pat_fg_color&0xFFFF0000)>>16));

      temp_mode=REG_G2D_COMM_CTRL;
      if (g2d_data->clip_mode ==G2D_CLIP_ENABLE)
      {
         temp_mode |= REG_COMMON_CTRL_G2D_CLIP_ENABLE_BIT;
      }
      else
         temp_mode &= ~REG_COMMON_CTRL_G2D_CLIP_ENABLE_BIT;
      G2D_WRITE_CMQ(G2D_CMQ_2D_COMMON_CTRL_REG_ADDR | ((kal_uint16)temp_mode))
      G2D_WRITE_CMQ(G2D_CMQ_FIRE_MODE_CTRL_REG_ADDR |(g2d_data->dest_color_mode) |
                    g2d_data->g2d_operation_mode);
      DISABLE_G2D_CMQ_WRITE;
      wait_cmq_start();
   }
   else
   {
      DISABLE_G2D_CMQ;
//    g2d_set_clip_window(g2d_data);
      REG_G2D_DEST_BASE_ADDRESS = g2d_data->dest_base_address;
      REG_G2D_DEST_PITCH = g2d_data->dest_pitch;
      REG_G2D_BEZIER_XY_START = (((kal_uint16) g2d_data->start_x)<<16)|((kal_uint16) g2d_data->start_y);
      REG_G2D_BEZIER_XY_MIDDLE = (((kal_uint16) g2d_data->middle_x)<<16)|((kal_uint16) g2d_data->middle_y);
      REG_G2D_BEZIER_XY_END = (((kal_uint16) g2d_data->end_x)<<16)|((kal_uint16) g2d_data->end_y);
      REG_G2D_PAT_FG_COLOR = g2d_data->pat_fg_color;
      REG_G2D_BEZIER_SUBDIV_TIME = (kal_uint32) ((g2d_data->bezier_curve_divide_time) & 0x0F);
      REG_G2D_BEZIER_BUFFER_ADDR = g2d_data->buffer_address;
      if (g2d_data->clip_mode ==G2D_CLIP_ENABLE)
      {
         ENABLE_G2D_ENGINE_CLIP;
      }
      else
      {
         DISABLE_G2D_ENGINE_CLIP;
      }
      fire_mode=(g2d_data->dest_color_mode)|g2d_data->g2d_operation_mode;
      REG_G2D_FIRE_CTRL=fire_mode;
   }
   while (G2D_ENGINE_IS_BUSY) {};
#endif
#endif
}  /* g2d_bezier_curve_drawing() */

void g2d_line_gradient_drawing(g2d_parameter_struct *g2d_data)
{
#ifdef __MTK_TARGET__
#if defined(DRV_2D_ENGINE_V2)
   kal_uint32 temp_mode;
   kal_uint16 fire_mode;
   int temp_data;

   g2d_power_on();
   RESET_G2D_ENGINE;
   g2d_set_clip_window(g2d_data);
// if (G2D_ENGINE_IS_BUSY)
   if (g2d_data->g2d_cmq_mode==KAL_TRUE)
   {
      ENABLE_G2D_CMQ;
      while (G2D_CMQ_FREE_SPACE < 18) {};

      ENABLE_G2D_CMQ_WRITE;
      G2D_WRITE_CMQ(G2D_CMQ_DEST_BASE_L_ADDR | (g2d_data->dest_base_address & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_DEST_BASE_H_ADDR | ((g2d_data->dest_base_address>>16) & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_Y_START_ADDR | ((kal_uint16) g2d_data->start_y));
      G2D_WRITE_CMQ(G2D_CMQ_X_START_ADDR | ((kal_uint16) g2d_data->start_x));
      G2D_WRITE_CMQ(G2D_CMQ_DEST_WIDTH_ADDR | (kal_uint16) g2d_data->dest_width);
      G2D_WRITE_CMQ(G2D_CMQ_GRAD_START_COLOR_L_ADDR | (g2d_data->pat_fg_color&0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_GRAD_START_COLOR_H_ADDR | ((g2d_data->pat_fg_color&0xFFFF0000)>>16));

      temp_data=(int) (g2d_data->alpha_gradient_x*(1<<16));
      G2D_WRITE_CMQ((G2D_CMQ_ALPHA_GRAD_X_L_ADDR|(temp_data & 0xFFFF)));
      G2D_WRITE_CMQ((G2D_CMQ_ALPHA_GRAD_X_H_ADDR|((temp_data>>16) & 0xFFFF)));

      temp_data=(int) (g2d_data->red_gradient_x*(1<<16));
      G2D_WRITE_CMQ((G2D_CMQ_RED_GRAD_X_L_ADDR|(temp_data & 0xFFFF)));
      G2D_WRITE_CMQ((G2D_CMQ_RED_GRAD_X_H_ADDR|((temp_data>>16) & 0xFFFF)));

      temp_data=(int) (g2d_data->green_gradient_x*(1<<16));
      G2D_WRITE_CMQ((G2D_CMQ_GREEN_GRAD_X_L_ADDR|(temp_data & 0xFFFF)));
      G2D_WRITE_CMQ((G2D_CMQ_GREEN_GRAD_X_H_ADDR|((temp_data>>16) & 0xFFFF)));

      temp_data=(int) (g2d_data->blue_gradient_x*(1<<16));
      G2D_WRITE_CMQ((G2D_CMQ_BLUE_GRAD_X_L_ADDR|(temp_data & 0xFFFF)));
      G2D_WRITE_CMQ((G2D_CMQ_BLUE_GRAD_X_H_ADDR|((temp_data>>16) & 0xFFFF)));

      temp_mode = REG_G2D_SUBMODE_CTRL;

      temp_mode=REG_G2D_COMM_CTRL;
      if (g2d_data->clip_mode ==G2D_CLIP_ENABLE)
      {
         temp_mode |= REG_COMMON_CTRL_G2D_CLIP_ENABLE_BIT;
      }
      else
         temp_mode &= ~REG_COMMON_CTRL_G2D_CLIP_ENABLE_BIT;
      G2D_WRITE_CMQ(G2D_CMQ_2D_COMMON_CTRL_REG_ADDR | ((kal_uint16)temp_mode))
      G2D_WRITE_CMQ(G2D_CMQ_FIRE_MODE_CTRL_REG_ADDR |(g2d_data->dest_color_mode) |
                    g2d_data->g2d_operation_mode);
      DISABLE_G2D_CMQ_WRITE;
      wait_cmq_start();
   }
   else
   {
      DISABLE_G2D_CMQ;
      SET_BITBLT_DIRECTION(BITBLT_TRANSFORM_DIRECTION_LT_CORNER);
      SET_BITBLT_TRANSFORM_MODE(BITBLT_TRANSFORM_COPY);
//    g2d_set_clip_window(g2d_data);
      REG_G2D_DEST_BASE_ADDRESS = g2d_data->dest_base_address;
      REG_G2D_BEZIER_XY_START = (((kal_uint16) g2d_data->start_x)<<16)|((kal_uint16) g2d_data->start_y);
      REG_G2D_DEST_WIDTH_HEIGHT = (((kal_uint16) g2d_data->dest_width)<<16);
      REG_G2D_START_COLOR = g2d_data->pat_fg_color;

      if (g2d_data->clip_mode ==G2D_CLIP_ENABLE)
      {
         ENABLE_G2D_ENGINE_CLIP;
      }
      else
      {
         DISABLE_G2D_ENGINE_CLIP
      }

      if (g2d_data->color_gradient_mode==G2D_REC_FILL_COLOR_GRAD_ENABLE)
      {
         ENABLE_REC_FILL_COLOR_GRADIENT;
         REG_G2D_ALPHA_GRADIENT_X = (int) (g2d_data->alpha_gradient_x*(1<<16));
         REG_G2D_RED_GRADIENT_X = (int) (g2d_data->red_gradient_x*(1<<16));
         REG_G2D_GREEN_GRADIENT_X = (int) (g2d_data->green_gradient_x*(1<<16));
         REG_G2D_BLUE_GRADIENT_X = (int) (g2d_data->blue_gradient_x*(1<<16));
      }
      else
      {
         DISABLE_REC_FILL_COLOR_GRADIENT;
      }

      fire_mode=(g2d_data->dest_color_mode)|g2d_data->g2d_operation_mode;
      REG_G2D_FIRE_CTRL=fire_mode;
   }
   while (G2D_ENGINE_IS_BUSY) {};
   g2d_power_off();
#endif
#endif
}  /* g2d_line_gradient_drawing() */

void g2d_line_copy_drawing(g2d_parameter_struct *g2d_data)
{
#ifdef __MTK_TARGET__
#if defined(DRV_2D_ENGINE_V2)
   kal_uint32 temp_mode;
   kal_uint16 fire_mode;

   g2d_power_on();
   RESET_G2D_ENGINE;
   g2d_set_clip_window(g2d_data);
// if (G2D_ENGINE_IS_BUSY)
   if (g2d_data->g2d_cmq_mode==KAL_TRUE)
   {
      ENABLE_G2D_CMQ;
      while (G2D_CMQ_FREE_SPACE < 14) {};
      
      ENABLE_G2D_CMQ_WRITE;
      G2D_WRITE_CMQ(G2D_CMQ_SRC_BASE_L_ADDR | (g2d_data->src_base_address & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_SRC_BASE_H_ADDR | ((g2d_data->src_base_address>>16) & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_DEST_BASE_L_ADDR | (g2d_data->dest_base_address & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_DEST_BASE_H_ADDR | ((g2d_data->dest_base_address>>16) & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_SRC_WIDTH_ADDR | ((kal_uint16) g2d_data->src_width));
      G2D_WRITE_CMQ(G2D_CMQ_DEST_WIDTH_ADDR | ((kal_uint16) g2d_data->dest_width));
      G2D_WRITE_CMQ(G2D_CMQ_GRAD_START_COLOR_L_ADDR | (g2d_data->pat_fg_color&0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_GRAD_START_COLOR_H_ADDR | ((g2d_data->pat_fg_color&0xFFFF0000)>>16));
      G2D_WRITE_CMQ(G2D_CMQ_MASK_BASE_L_ADDR|(g2d_data->buffer_address&0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_MASK_BASE_H_ADDR|((g2d_data->buffer_address>>16)&0xFFFF));

      temp_mode=REG_G2D_COMM_CTRL;
      if (g2d_data->clip_mode ==G2D_CLIP_ENABLE)
      {
         temp_mode |= REG_COMMON_CTRL_G2D_CLIP_ENABLE_BIT;
      }
      else
         temp_mode &= ~REG_COMMON_CTRL_G2D_CLIP_ENABLE_BIT;
      G2D_WRITE_CMQ(G2D_CMQ_2D_COMMON_CTRL_REG_ADDR | ((kal_uint16)temp_mode))
      G2D_WRITE_CMQ(G2D_CMQ_FIRE_MODE_CTRL_REG_ADDR |(g2d_data->dest_color_mode) |(g2d_data->src_color_mode)|
                    g2d_data->g2d_operation_mode);
      DISABLE_G2D_CMQ_WRITE;
      wait_cmq_start();
   }
   else
   {
      DISABLE_G2D_CMQ;
      SET_BITBLT_DIRECTION(BITBLT_TRANSFORM_DIRECTION_LT_CORNER);
      SET_BITBLT_TRANSFORM_MODE(BITBLT_TRANSFORM_COPY);
//    g2d_set_clip_window(g2d_data);
      REG_G2D_SRC_BASE_ADDRESS = g2d_data->src_base_address;
      REG_G2D_DEST_BASE_ADDRESS= g2d_data->dest_base_address;
      REG_G2D_SRC_WIDTH_HEIGHT = (g2d_data->src_width<<16);
      REG_G2D_DEST_WIDTH_HEIGHT = (g2d_data->dest_width<<16);
      REG_G2D_LINE_COPY_MASK_ADDR = g2d_data->buffer_address;

      if (g2d_data->clip_mode ==G2D_CLIP_ENABLE)
      {
         ENABLE_G2D_ENGINE_CLIP;
      }
      else
      {
         DISABLE_G2D_ENGINE_CLIP
      }
      (*((volatile unsigned int *) 0x80670104)) |= 0x80;

      fire_mode=(g2d_data->src_color_mode)|(g2d_data->dest_color_mode)|g2d_data->g2d_operation_mode;
      REG_G2D_FIRE_CTRL=fire_mode;
   }
   while (G2D_ENGINE_IS_BUSY) {};
   g2d_power_off();
#endif
#endif
}  /* g2d_line_copy_drawing() */
#endif

void g2d_get_triangle_slope(short start_x, short start_y, short middle_x, short middle_y,
                            short end_x, short end_y,g2d_triangle_para_struct *g2d_tri_data)
{
   kal_bool two_triangle=KAL_TRUE;
   kal_uint16 first_x=0,first_y=0,second_x=0,second_y=0,triangle_middle_y=0;
   int slope1=0,slope2=0,slope3=0,slope4=0;

   if (start_y==middle_y)
   {
      triangle_middle_y=middle_y;
      first_x=end_x;
      first_y=end_y;
      two_triangle=KAL_FALSE;
      if (start_x>middle_x)
      {
         if (end_y>middle_y)
         {
            slope1=((end_x-middle_x)<<16)/(middle_y-end_y);
            slope2=((end_x-start_x)<<16)/(start_y-end_y);
         }
         else
         {
            slope1= ((middle_x-end_x)<<16)/(middle_y-end_y);
            slope2= ((start_x-end_x)<<16)/(start_y-end_y);
         }
      }
      else
      {
         if (end_y>middle_y)
         {
            slope1= ((end_x-start_x)<<16)/(start_y-end_y);
            slope2= ((end_x-middle_x)<<16)/(middle_y-end_y);
         }
         else
         {
            slope1= ((start_x-end_x)<<16)/(start_y-end_y);
            slope2= ((middle_x-end_x)<<16)/(middle_y-end_y);
         }
      }
   }
   else if (start_y==end_y)
   {
      triangle_middle_y=end_y;
      first_x=middle_x;
      first_y=middle_y;
      two_triangle=KAL_FALSE;

      if (start_x>end_x)
      {
         if (middle_y>start_y)
         {
            slope2= ((middle_x-start_x)<<16)/(start_y-middle_y);
            slope1= ((middle_x-end_x)<<16)/(end_y-middle_y);
         }
         else
         {
            slope2= ((start_x-middle_x)<<16)/(start_y-middle_y);
            slope1= ((end_x-middle_x)<<16)/(end_y-middle_y);
         }
      }
      else
      {
         if (middle_y>start_y)
         {
            slope1= ((middle_x-start_x)<<16)/(start_y-middle_y);
            slope2= ((middle_x-end_x)<<16)/(end_y-middle_y);
         }
         else
         {
            slope1= ((start_x-middle_x)<<16)/(start_y-middle_y);
            slope2= ((end_x-middle_x)<<16)/(end_y-middle_y);
         }
      }
   }
   else if (middle_y==end_y)
   {
      triangle_middle_y=middle_y;
      first_x=start_x;
      first_y=start_y;
      two_triangle=KAL_FALSE;
      if (middle_x>end_x)
      {
         if (start_y>middle_y)
         {
            slope2= ((start_x-middle_x)<<16)/(middle_y-start_y);
            slope1= ((start_x-end_x)<<16)/(end_y-start_y);
         }
         else
         {
            slope2= ((middle_x-start_x)<<16)/(middle_y-start_y);
            slope1= ((end_x-start_x)<<16)/(end_y-start_y);
         }
      }
      else
      {
         if (start_y>middle_y)
         {
            slope1= ((start_x-middle_x)<<16)/(middle_y-start_y);
            slope2= ((start_x-end_x)<<16)/(end_y-start_y);
         }
         else
         {
            slope1= ((middle_x-start_x)<<16)/(middle_y-start_y);
            slope2= ((end_x-start_x)<<16)/(end_y-start_y);
         }
      }
      g2d_tri_data->two_triangle=KAL_FALSE;
   }
   else
   {
      if ((start_y>middle_y) && (middle_y>end_y))
      {  /* middle_y in middle */
         triangle_middle_y=middle_y;
         first_x=end_x;
         first_y=end_y;
         second_x=start_x;
         second_y=start_y;
         if (middle_x>end_x)
         {
            slope1= ((start_x-end_x)<<16)/(start_y-end_y);
            slope2= ((middle_x-end_x)<<16)/(middle_y-end_y);
            slope3= ((start_x-end_x)<<16)/(end_y-start_y);
            slope4= ((start_x-middle_x)<<16)/(middle_y-start_y);
         }
         else
         {
            slope4= ((start_x-end_x)<<16)/(end_y-start_y);
            slope3= ((start_x-middle_x)<<16)/(middle_y-start_y);
            slope2= ((start_x-end_x)<<16)/(start_y-end_y);
            slope1= ((middle_x-end_x)<<16)/(middle_y-end_y);
         }
      }
      else if ((end_y>middle_y)&&(middle_y>start_y))
      {
         triangle_middle_y=middle_y;
         first_x=start_x;
         first_y=start_y;
         second_x=end_x;
         second_y=end_y;
         if (middle_x>start_x)
         {
            slope1= ((end_x-start_x)<<16)/(end_y-start_y);
            slope4= ((end_x-middle_x)<<16)/(middle_y-end_y);
            slope3= ((end_x-start_x)<<16)/(start_y-end_y);
            slope2= ((middle_x-start_x)<<16)/(middle_y-start_y);
         }
         else
         {
            slope2= ((end_x-start_x)<<16)/(end_y-start_y);
            slope1= ((middle_x-start_x)<<16)/(middle_y-start_y);
            slope4= ((end_x-start_x)<<16)/(start_y-end_y);
            slope3= ((end_x-middle_x)<<16)/(middle_y-end_y);
         }
      }
      else if ((middle_y>start_y) && (start_y>end_y))
      {
         triangle_middle_y=start_y;
         first_x=end_x;
         first_y=end_y;
         second_x=middle_x;
         second_y=middle_y;
         if (start_x>end_x)
         {
            slope3= ((middle_x-end_x)<<16)/(end_y-middle_y);
            slope4= ((middle_x-start_x)<<16)/(start_y-middle_y);
            slope2= ((start_x-end_x)<<16)/(start_y-end_y);
            slope1= ((middle_x-end_x)<<16)/(middle_y-end_y);
         }
         else
         {
            slope4= ((middle_x-end_x)<<16)/(end_y-middle_y);
            slope3= ((middle_x-start_x)<<16)/(start_y-middle_y);
            slope1= ((start_x-end_x)<<16)/(start_y-end_y);
            slope2= ((middle_x-end_x)<<16)/(middle_y-end_y);
         }
      }
      else if ((end_y>start_y)&&(start_y>middle_y))
      {  /* start_y in middle */
         triangle_middle_y=start_y;
         first_x=middle_x;
         first_y=middle_y;
         second_x=end_x;
         second_y=end_y;
         if (start_x>middle_x)
         {
            slope1= ((end_x-middle_x)<<16)/(end_y-middle_y);
            slope2= ((start_x-middle_x)<<16)/(start_y-middle_y);
            slope4= ((end_x-start_x)<<16)/(start_y-end_y);
            slope3= ((end_x-middle_x)<<16)/(middle_y-end_y);
         }
         else
         {
            slope2= ((end_x-middle_x)<<16)/(end_y-middle_y);
            slope1= ((start_x-middle_x)<<16)/(start_y-middle_y);
            slope3= ((end_x-start_x)<<16)/(start_y-end_y);
            slope4= ((end_x-middle_x)<<16)/(middle_y-end_y);
         }
      }
      else if ((start_y>end_y)&&(end_y>middle_y))
      {
         triangle_middle_y=end_y;
         first_x=middle_x;
         first_y=middle_y;
         second_x=start_x;
         second_y=start_y;
         if (end_x>middle_x)
         {
            slope3= ((start_x-middle_x)<<16)/(middle_y-start_y);
            slope1= ((start_x-middle_x)<<16)/(start_y-middle_x);
            slope4= ((start_x-end_x)<<16)/(end_y-start_y);
            slope2= ((end_x-middle_x)<<16)/(end_y-middle_y);
         }
         else
         {
            slope4= ((start_x-middle_x)<<16)/(middle_y-start_y);
            slope2= ((start_x-middle_x)<<16)/(start_y-middle_y);
            slope3= ((start_x-end_x)<<16)/(end_y-start_y);
            slope1= ((end_x-middle_x)<<16)/(end_y-middle_y);
         }
      }
      else if ((middle_y>end_y)&&(end_y>start_y))
      {  /* end_y in middle */
         triangle_middle_y=end_y;
         first_x=start_x;
         first_y=start_y;
         second_x=middle_x;
         second_y=middle_y;
         if (end_x>start_x)
         {
            slope1= ((middle_x-start_x)<<16)/(middle_y-start_y);
            slope3= ((middle_x-start_x)<<16)/(start_y-middle_y);
            slope2= ((end_x-start_x)<<16)/(end_y-start_y);
            slope4= ((middle_x-end_x)<<16)/(end_y-middle_y);
         }
         else
         {
            slope2= ((middle_x-start_x)<<16)/(middle_y-start_y);
            slope4= ((middle_x-start_x)<<16)/(start_y-middle_y);
            slope1= ((end_x-start_x)<<16)/(end_y-start_y);
            slope3= ((middle_x-end_x)<<16)/(end_y-middle_y);
         }
      }
      g2d_tri_data->two_triangle=KAL_TRUE;
   }
   g2d_tri_data->first_x=first_x;
   g2d_tri_data->first_y=first_y;
   g2d_tri_data->second_x=second_x;
   g2d_tri_data->second_y=second_y;
   g2d_tri_data->middle_y=triangle_middle_y;
   g2d_tri_data->slope1=slope1;
   g2d_tri_data->slope2=slope2;
   g2d_tri_data->slope3=slope3;
   g2d_tri_data->slope4=slope4;
}  /* g2d_get_triangle_slope() */

#ifdef __MTK_TARGET__
#if defined(DRV_2D_ENGINE_V2)

kal_bool g2d_begin(kal_uint8 g2d_owner_id, void (*g2d_cb)())
{
   if (g2d_current_owner_id!=G2D_OWNER_NONE)
      return KAL_FALSE;
   g2d_power_on();

   RESET_G2D_ENGINE;
   DISABLE_G2D_CMQ;
   ENABLE_G2D_ENGINE_CLIP;

   REG_G2D_CMQ_QUEUE_LENGTH=G2D_CMQ_LENGTH;
   REG_G2D_CMQ_QUEUE_BASE_ADDR=(kal_uint32) g2d_cmq;
   REG_G2D_BEZIER_SUBDIV_TIME = (kal_uint32) (5 & 0x0F);
   REG_G2D_BEZIER_BUFFER_ADDR = (kal_uint32) subdivided_buffer;
   g2d_submode_ctrl_reg_shadow=REG_G2D_SUBMODE_CTRL;
   g2d_comm_ctrl_reg_shadow=REG_G2D_COMM_CTRL;

   g2d_submode_ctrl_reg_shadow=0;
   g2d_comm_ctrl_reg_shadow=0;
   g2d_fire_ctrl_reg_shadow=0;

   g2d_callback=NULL;
   g2d_current_owner_id=g2d_owner_id;
   g2d_callback = g2d_cb;
   if (g2d_callback!=NULL)
   {
      ENABLE_G2D_ENGINE_INT;
      IRQUnmask(IRQ_G2D_CODE);
   }
   else
   {
      DISABLE_G2D_ENGINE_INT;
      IRQMask(IRQ_G2D_CODE);
   }

   ENABLE_G2D_CMQ;
   DISABLE_G2D_CMQ_WRITE;

   return KAL_TRUE;
}  /* g2d_begin() */

void g2d_end(kal_uint8 g2d_owner_id)
{
   volatile kal_uint16 i;

   if (g2d_owner_id!=g2d_current_owner_id)
      return;

   while (G2D_CMQ_FREE_SPACE!=G2D_CMQ_LENGTH) {};

   for (i=0;i<0x100;i++);
   while (G2D_ENGINE_IS_BUSY) {};

   g2d_current_owner_id=G2D_OWNER_NONE;
   g2d_deinit();
}  /* g2d_end() */

void g2d_set_dest_buffer(kal_uint8 g2d_owner_id, g2d_buffer_struct *dest)
{
   if (g2d_owner_id!=g2d_current_owner_id)
      return;

   g2d_dest_buff_data.base_address=dest->base_address;
   g2d_dest_buff_data.x=dest->x;
   g2d_dest_buff_data.y=dest->y;
   g2d_dest_buff_data.pitch=dest->pitch;
   g2d_dest_buff_data.height=dest->height;
   g2d_dest_buff_data.width=dest->width;
   g2d_dest_buff_data.clip_y1=dest->clip_y1;
   g2d_dest_buff_data.clip_x1=dest->clip_x1;
   g2d_dest_buff_data.clip_y2=dest->clip_y2;
   g2d_dest_buff_data.clip_x2=dest->clip_x2;
   g2d_dest_buff_data.color_mode=dest->color_mode;

   while (G2D_CMQ_FREE_SPACE < 14) {};

   ENABLE_G2D_CMQ_WRITE;
   G2D_WRITE_CMQ(G2D_CMQ_DEST_BASE_L_ADDR | (dest->base_address & 0xFFFF));
   G2D_WRITE_CMQ(G2D_CMQ_DEST_BASE_H_ADDR | ((dest->base_address>>16) & 0xFFFF));
   G2D_WRITE_CMQ(G2D_CMQ_DEST_Y_ADDR | ((kal_uint16) dest->y));
   G2D_WRITE_CMQ(G2D_CMQ_DEST_X_ADDR | ((kal_uint16) dest->x));
   G2D_WRITE_CMQ(G2D_CMQ_DEST_PITCH_ADDR | dest->pitch);
   G2D_WRITE_CMQ(G2D_CMQ_DEST_HEIGHT_ADDR | dest->height);
   G2D_WRITE_CMQ(G2D_CMQ_DEST_WIDTH_ADDR | dest->width);
   G2D_WRITE_CMQ(G2D_CMQ_CLIP_TOP_Y_ADDR | dest->clip_y1);
   G2D_WRITE_CMQ(G2D_CMQ_CLIP_LEFT_X_ADDR | dest->clip_x1);
   G2D_WRITE_CMQ(G2D_CMQ_CLIP_BOTTOM_Y_ADDR | dest->clip_y2);
   G2D_WRITE_CMQ(G2D_CMQ_CLIP_RIGHT_X_ADDR | dest->clip_x2);
   g2d_fire_ctrl_reg_shadow &= ~REG_FIRE_CTRL_DEST_COLOR_MODE_MASK;
   g2d_fire_ctrl_reg_shadow |= dest->color_mode;
   while (!G2D_CMQ_IS_WRITABLE) {};
   DISABLE_G2D_CMQ_WRITE;
}  /* g2d_set_dest_buffer() */

void g2d_font_set_attribute(kal_uint8 g2d_owner_id, g2d_font_attribute_struct *g2d_font_attr)
{
   if (g2d_owner_id!=g2d_current_owner_id)
      return;

   g2d_font_attr_data.tilt_mode=g2d_font_attr->tilt_mode;
   g2d_font_attr_data.bold_mode=g2d_font_attr->bold_mode;
   g2d_font_attr_data.border_mode=g2d_font_attr->border_mode;
   g2d_font_attr_data.enable_bg_color=g2d_font_attr->enable_bg_color;
   g2d_font_attr_data.fg_color=g2d_font_attr->fg_color;
   g2d_font_attr_data.bg_color=g2d_font_attr->bg_color;

   if (g2d_font_attr->tilt_mode==KAL_TRUE)
      g2d_submode_ctrl_reg_shadow |= REG_SUBMODE_CTRL_ITALIC_FONT_BIT;
   else
      g2d_submode_ctrl_reg_shadow &= ~REG_SUBMODE_CTRL_ITALIC_FONT_BIT;

   if (g2d_font_attr->enable_bg_color==KAL_TRUE)
      g2d_submode_ctrl_reg_shadow &= ~REG_SUBMODE_CTRL_FONT_BACKGROUND_BIT;
   else
      g2d_submode_ctrl_reg_shadow |= REG_SUBMODE_CTRL_FONT_BACKGROUND_BIT;

   g2d_submode_ctrl_reg_shadow |= REG_SUBMODE_CTRL_BITBLT_DIRECTION_MASK;
   g2d_submode_ctrl_reg_shadow &= ~REG_SUBMODE_CTRL_BITBLT_TRANSFORM_MASK;
   g2d_submode_ctrl_reg_shadow |= BITBLT_TRANSFORM_COPY;

   while (G2D_CMQ_FREE_SPACE < 8) {};

   ENABLE_G2D_CMQ_WRITE;
   G2D_WRITE_CMQ(G2D_CMQ_SUBMODE_CTRL_REG_L_ADDR | (g2d_submode_ctrl_reg_shadow & 0xFFFF));
   G2D_WRITE_CMQ(G2D_CMQ_SUBMODE_CTRL_REG_H_ADDR | ((g2d_submode_ctrl_reg_shadow & 0xFFFF0000)>>16));
   G2D_WRITE_CMQ(G2D_CMQ_PAT_FG_COLOR_L_ADDR | (g2d_font_attr->fg_color&0xFFFF));
   G2D_WRITE_CMQ(G2D_CMQ_PAT_FG_COLOR_H_ADDR | ((g2d_font_attr->fg_color&0xFFFF0000)>>16));
   G2D_WRITE_CMQ(G2D_CMQ_PAT_BG_COLOR_L_ADDR | (g2d_font_attr->bg_color&0xFFFF));
   G2D_WRITE_CMQ(G2D_CMQ_PAT_BG_COLOR_H_ADDR | ((g2d_font_attr->bg_color&0xFFFF0000)>>16));
   while (!G2D_CMQ_IS_WRITABLE) {};
   DISABLE_G2D_CMQ_WRITE;
}  /* g2d_font_set_attribute() */

void g2d_draw_font(kal_uint8 g2d_owner_id, g2d_font_struct *g2d_font_data)
{
   if (g2d_owner_id!=g2d_current_owner_id)
      return;

   g2d_fire_ctrl_reg_shadow&=~REG_FIRE_CTRL_G2D_FUNCTION_MODE_MASK;
   g2d_fire_ctrl_reg_shadow|=G2D_OPERATION_FONT_CACHING;

   g2d_submode_ctrl_reg_shadow &=~REG_SUBMODE_CTRL_START_BIT_MASK;
   g2d_submode_ctrl_reg_shadow |= (g2d_font_data->bit_offset<<16);

   while (G2D_CMQ_FREE_SPACE < 8) {};

   ENABLE_G2D_CMQ_WRITE;
   G2D_WRITE_CMQ(G2D_CMQ_SUBMODE_CTRL_REG_L_ADDR | (g2d_submode_ctrl_reg_shadow & 0xFFFF));
   G2D_WRITE_CMQ(G2D_CMQ_SUBMODE_CTRL_REG_H_ADDR | ((g2d_submode_ctrl_reg_shadow & 0xFFFF0000)>>16));
   G2D_WRITE_CMQ(G2D_CMQ_SRC_BASE_L_ADDR | (g2d_font_data->font_address & 0xFFFF));
   G2D_WRITE_CMQ(G2D_CMQ_SRC_BASE_H_ADDR | ((g2d_font_data->font_address>>16) & 0xFFFF));
   G2D_WRITE_CMQ(G2D_CMQ_DEST_HEIGHT_ADDR | g2d_font_data->font_height);
   G2D_WRITE_CMQ(G2D_CMQ_DEST_WIDTH_ADDR | g2d_font_data->font_width);
   while (!G2D_CMQ_IS_WRITABLE) {};
   DISABLE_G2D_CMQ_WRITE;

   if ((g2d_font_attr_data.bold_mode==KAL_TRUE)|| (g2d_font_attr_data.border_mode==KAL_TRUE))
   {
      g2d_submode_ctrl_reg_shadow |= REG_SUBMODE_CTRL_FONT_BACKGROUND_BIT;
      while (G2D_CMQ_FREE_SPACE < 4) {};

      ENABLE_G2D_CMQ_WRITE;
      G2D_WRITE_CMQ(G2D_CMQ_SUBMODE_CTRL_REG_L_ADDR | (g2d_submode_ctrl_reg_shadow & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_SUBMODE_CTRL_REG_H_ADDR | ((g2d_submode_ctrl_reg_shadow & 0xFFFF0000)>>16));
      while (!G2D_CMQ_IS_WRITABLE) {};
      DISABLE_G2D_CMQ_WRITE;
   }

   if (g2d_font_attr_data.bold_mode==KAL_TRUE)
   {
      while (G2D_CMQ_FREE_SPACE < 6) {};

      ENABLE_G2D_CMQ_WRITE;
      G2D_WRITE_CMQ(G2D_CMQ_DEST_Y_ADDR | ((kal_uint16) g2d_font_data->start_y));
      G2D_WRITE_CMQ(G2D_CMQ_DEST_X_ADDR | ((kal_uint16) g2d_font_data->start_x));
      G2D_WRITE_CMQ(G2D_CMQ_FIRE_MODE_CTRL_REG_ADDR | g2d_fire_ctrl_reg_shadow);
      G2D_WRITE_CMQ(G2D_CMQ_DEST_Y_ADDR | ((kal_uint16) (g2d_font_data->start_y-1)));
      G2D_WRITE_CMQ(G2D_CMQ_FIRE_MODE_CTRL_REG_ADDR | g2d_fire_ctrl_reg_shadow);
      while (!G2D_CMQ_IS_WRITABLE) {};
      DISABLE_G2D_CMQ_WRITE;
   }
   else if (g2d_font_attr_data.border_mode==KAL_TRUE)
   {
      while (G2D_CMQ_FREE_SPACE < 35) {};

      ENABLE_G2D_CMQ_WRITE;
      G2D_WRITE_CMQ(G2D_CMQ_PAT_BG_COLOR_L_ADDR |((g2d_font_attr_data.bg_color+10)&0xFFFF) );
      G2D_WRITE_CMQ(G2D_CMQ_PAT_FG_COLOR_L_ADDR | (g2d_font_attr_data.bg_color&0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_PAT_FG_COLOR_H_ADDR | ((g2d_font_attr_data.bg_color&0xFFFF0000)>>16));
      G2D_WRITE_CMQ(G2D_CMQ_DEST_X_ADDR | ((kal_uint16) (g2d_font_data->start_x-1)));
      G2D_WRITE_CMQ(G2D_CMQ_DEST_Y_ADDR | ((kal_uint16) (g2d_font_data->start_y-1)));
      G2D_WRITE_CMQ(G2D_CMQ_FIRE_MODE_CTRL_REG_ADDR | g2d_fire_ctrl_reg_shadow);
      G2D_WRITE_CMQ(G2D_CMQ_DEST_X_ADDR | ((kal_uint16) (g2d_font_data->start_x-1)));
      G2D_WRITE_CMQ(G2D_CMQ_DEST_Y_ADDR | ((kal_uint16) (g2d_font_data->start_y+1)));
      G2D_WRITE_CMQ(G2D_CMQ_FIRE_MODE_CTRL_REG_ADDR | g2d_fire_ctrl_reg_shadow);
      G2D_WRITE_CMQ(G2D_CMQ_DEST_X_ADDR | ((kal_uint16) (g2d_font_data->start_x+1)));
      G2D_WRITE_CMQ(G2D_CMQ_DEST_Y_ADDR | ((kal_uint16) (g2d_font_data->start_y-1)));
      G2D_WRITE_CMQ(G2D_CMQ_FIRE_MODE_CTRL_REG_ADDR | g2d_fire_ctrl_reg_shadow);
      G2D_WRITE_CMQ(G2D_CMQ_DEST_X_ADDR | ((kal_uint16) (g2d_font_data->start_x+1)));
      G2D_WRITE_CMQ(G2D_CMQ_DEST_Y_ADDR | ((kal_uint16) (g2d_font_data->start_y+1)));
      G2D_WRITE_CMQ(G2D_CMQ_FIRE_MODE_CTRL_REG_ADDR | g2d_fire_ctrl_reg_shadow);
      G2D_WRITE_CMQ(G2D_CMQ_DEST_X_ADDR | ((kal_uint16) (g2d_font_data->start_x)));
      G2D_WRITE_CMQ(G2D_CMQ_DEST_Y_ADDR | ((kal_uint16) (g2d_font_data->start_y-1)));
      G2D_WRITE_CMQ(G2D_CMQ_FIRE_MODE_CTRL_REG_ADDR | g2d_fire_ctrl_reg_shadow);
      G2D_WRITE_CMQ(G2D_CMQ_DEST_X_ADDR | ((kal_uint16) (g2d_font_data->start_x)));
      G2D_WRITE_CMQ(G2D_CMQ_DEST_Y_ADDR | ((kal_uint16) (g2d_font_data->start_y+1)));
      G2D_WRITE_CMQ(G2D_CMQ_FIRE_MODE_CTRL_REG_ADDR | g2d_fire_ctrl_reg_shadow);
      G2D_WRITE_CMQ(G2D_CMQ_DEST_X_ADDR | ((kal_uint16) (g2d_font_data->start_x-1)));
      G2D_WRITE_CMQ(G2D_CMQ_DEST_Y_ADDR | ((kal_uint16) (g2d_font_data->start_y)));
      G2D_WRITE_CMQ(G2D_CMQ_FIRE_MODE_CTRL_REG_ADDR | g2d_fire_ctrl_reg_shadow);
      G2D_WRITE_CMQ(G2D_CMQ_DEST_X_ADDR | ((kal_uint16) (g2d_font_data->start_x+1)));
      G2D_WRITE_CMQ(G2D_CMQ_DEST_Y_ADDR | ((kal_uint16) (g2d_font_data->start_y)));
      G2D_WRITE_CMQ(G2D_CMQ_FIRE_MODE_CTRL_REG_ADDR | g2d_fire_ctrl_reg_shadow);
      G2D_WRITE_CMQ(G2D_CMQ_PAT_BG_COLOR_L_ADDR |((g2d_font_attr_data.fg_color+10)&0xFFFF) );
      G2D_WRITE_CMQ(G2D_CMQ_PAT_FG_COLOR_L_ADDR | (g2d_font_attr_data.fg_color&0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_PAT_FG_COLOR_H_ADDR | ((g2d_font_attr_data.fg_color&0xFFFF0000)>>16));
      G2D_WRITE_CMQ(G2D_CMQ_DEST_X_ADDR | ((kal_uint16) (g2d_font_data->start_x)));
      G2D_WRITE_CMQ(G2D_CMQ_DEST_Y_ADDR | ((kal_uint16) (g2d_font_data->start_y)));
      G2D_WRITE_CMQ(G2D_CMQ_FIRE_MODE_CTRL_REG_ADDR | g2d_fire_ctrl_reg_shadow);
      while (!G2D_CMQ_IS_WRITABLE) {};
      DISABLE_G2D_CMQ_WRITE;
   }
   else
   {
      while (G2D_CMQ_FREE_SPACE < 5) {};

      ENABLE_G2D_CMQ_WRITE;
      G2D_WRITE_CMQ(G2D_CMQ_DEST_Y_ADDR | ((kal_uint16) g2d_font_data->start_y));
      G2D_WRITE_CMQ(G2D_CMQ_DEST_X_ADDR | ((kal_uint16) g2d_font_data->start_x));
      G2D_WRITE_CMQ(G2D_CMQ_FIRE_MODE_CTRL_REG_ADDR | g2d_fire_ctrl_reg_shadow);
      while (!G2D_CMQ_IS_WRITABLE) {};
      DISABLE_G2D_CMQ_WRITE;
   }
}  /* g2d_draw_font() */

void g2d_bitblt1(kal_uint8 g2d_owner_id, g2d_bitblt_struct *g2d_bitblt_data)
{
   kal_uint16 i;

   if (g2d_owner_id!=g2d_current_owner_id)
      return;

   g2d_fire_ctrl_reg_shadow&=~REG_FIRE_CTRL_G2D_FUNCTION_MODE_MASK;
   if (g2d_bitblt_data->alpha_blending_mode==KAL_TRUE)
   {
      g2d_fire_ctrl_reg_shadow|=G2D_OPERATION_ALPHA_BLENDING;
      g2d_submode_ctrl_reg_shadow &= ~REG_SUBMODE_CTRL_ALPHA_MASK;
      g2d_submode_ctrl_reg_shadow |= (g2d_bitblt_data->alpha_value<<16);
   }
   else if (g2d_bitblt_data->rop_mode==KAL_TRUE)
   {
      g2d_fire_ctrl_reg_shadow|=G2D_OPERATION_ROP_BITBLT;
      g2d_submode_ctrl_reg_shadow &= ~REG_SUBMODE_CTRL_ROP_CODE_MASK;
      g2d_submode_ctrl_reg_shadow |= (g2d_bitblt_data->rop_value<<16);
   }
   else
      g2d_fire_ctrl_reg_shadow|=G2D_OPERATION_BITBLT;

   g2d_submode_ctrl_reg_shadow &= ~REG_SUBMODE_CTRL_BITBLT_TRANSFORM_MASK;
   g2d_submode_ctrl_reg_shadow |= g2d_bitblt_data->transform_value;

   if (g2d_bitblt_data->tilt_mode==KAL_TRUE)
      g2d_submode_ctrl_reg_shadow |= REG_SUBMODE_CTRL_ITALIC_BITBLT_BIT;
   else
      g2d_submode_ctrl_reg_shadow &= ~REG_SUBMODE_CTRL_ITALIC_BITBLT_BIT;

   g2d_submode_ctrl_reg_shadow &= ~REG_SUBMODE_CTRL_BITBLT_DIRECTION_MASK;

   if (g2d_bitblt_data->transform_value==BITBLT_TRANSFORM_COPY)
      g2d_submode_ctrl_reg_shadow |= g2d_bitblt_data->blt_direction;
   else
      g2d_submode_ctrl_reg_shadow |= BITBLT_TRANSFORM_DIRECTION_LT_CORNER;

   if (g2d_bitblt_data->src_key_mode==KAL_TRUE)
      g2d_comm_ctrl_reg_shadow |=REG_COMMON_CTRL_G2D_SRC_KEY_ENABLE_BIT;
   else
      g2d_comm_ctrl_reg_shadow &= ~REG_COMMON_CTRL_G2D_SRC_KEY_ENABLE_BIT;

   while (G2D_CMQ_FREE_SPACE < 8) {};

   ENABLE_G2D_CMQ_WRITE;
   G2D_WRITE_CMQ(G2D_CMQ_2D_COMMON_CTRL_REG_ADDR | ((kal_uint16)g2d_comm_ctrl_reg_shadow))
   G2D_WRITE_CMQ(G2D_CMQ_SRCKEY_COLOR_L_ADDR | (g2d_bitblt_data->src_key_color & 0xFFFF));
   G2D_WRITE_CMQ(G2D_CMQ_SRCKEY_COLOR_H_ADDR | ((g2d_bitblt_data->src_key_color>>16) & 0xFFFF));

   switch (g2d_bitblt_data->transform_value)
   {
      case BITBLT_TRANSFORM_MIRROR_ROTATE_90:
         G2D_WRITE_CMQ(G2D_CMQ_DEST_Y_ADDR | (g2d_dest_buff_data.y+g2d_dest_buff_data.height-1));
         G2D_WRITE_CMQ(G2D_CMQ_DEST_X_ADDR | (g2d_dest_buff_data.x+g2d_dest_buff_data.width-1));
      break;
      case BITBLT_TRANSFORM_ROTATE_90:
         G2D_WRITE_CMQ(G2D_CMQ_DEST_Y_ADDR | ((kal_uint16) g2d_dest_buff_data.y));
         G2D_WRITE_CMQ(G2D_CMQ_DEST_X_ADDR | (g2d_dest_buff_data.x+g2d_dest_buff_data.width-1));
      break;
      case BITBLT_TRANSFORM_ROTATE_270:
         G2D_WRITE_CMQ(G2D_CMQ_DEST_Y_ADDR | (g2d_dest_buff_data.y+g2d_dest_buff_data.height-1));
         G2D_WRITE_CMQ(G2D_CMQ_DEST_X_ADDR | ((kal_uint16) g2d_dest_buff_data.x));
      break;

      case BITBLT_TRANSFORM_MIRROR_ROTATE_270:
      case BITBLT_TRANSFORM_COPY:
         G2D_WRITE_CMQ(G2D_CMQ_DEST_Y_ADDR | ((kal_uint16) g2d_dest_buff_data.y));
         G2D_WRITE_CMQ(G2D_CMQ_DEST_X_ADDR | ((kal_uint16) g2d_dest_buff_data.x));
      break;
      case BITBLT_TRANSFORM_ROTATE_180:
         G2D_WRITE_CMQ(G2D_CMQ_DEST_Y_ADDR | (g2d_dest_buff_data.y+g2d_dest_buff_data.height-1));
         G2D_WRITE_CMQ(G2D_CMQ_DEST_X_ADDR | (g2d_dest_buff_data.x+g2d_dest_buff_data.width-1));
      break;
      case BITBLT_TRANSFORM_MIRROR:
         G2D_WRITE_CMQ(G2D_CMQ_DEST_Y_ADDR | ((kal_uint16) g2d_dest_buff_data.y));
         G2D_WRITE_CMQ(G2D_CMQ_DEST_X_ADDR | (g2d_dest_buff_data.x+g2d_dest_buff_data.width-1));
      break;
      case BITBLT_TRANSFORM_MIRROR_ROTATE_180:
         G2D_WRITE_CMQ(G2D_CMQ_DEST_Y_ADDR | (g2d_dest_buff_data.y+g2d_dest_buff_data.height-1));
         G2D_WRITE_CMQ(G2D_CMQ_DEST_X_ADDR | ((kal_uint16) g2d_dest_buff_data.x));
      break;
   }
   while (!G2D_CMQ_IS_WRITABLE) {};
   DISABLE_G2D_CMQ_WRITE;
   for (i=0;i<g2d_bitblt_data->list_count;i++)
   {

      g2d_fire_ctrl_reg_shadow &= ~REG_FIRE_CTRL_SOURCE_COLOR_MODE_MASK;
      g2d_fire_ctrl_reg_shadow |= g2d_bitblt_data->src_list[i].color_mode;

      while (G2D_CMQ_FREE_SPACE < 12) {};

      ENABLE_G2D_CMQ_WRITE;

      G2D_WRITE_CMQ(G2D_CMQ_SUBMODE_CTRL_REG_L_ADDR | (g2d_submode_ctrl_reg_shadow & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_SUBMODE_CTRL_REG_H_ADDR | ((g2d_submode_ctrl_reg_shadow & 0xFFFF0000)>>16));
      G2D_WRITE_CMQ(G2D_CMQ_SRC_BASE_L_ADDR | (g2d_bitblt_data->src_list[i].base_address & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_SRC_BASE_H_ADDR | ((g2d_bitblt_data->src_list[i].base_address>>16) & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_SRC_PITCH_ADDR | g2d_bitblt_data->src_list[i].pitch);
      G2D_WRITE_CMQ(G2D_CMQ_SRC_Y_ADDR | ((kal_uint16)g2d_bitblt_data->src_list[i].y));
      G2D_WRITE_CMQ(G2D_CMQ_SRC_X_ADDR | ((kal_uint16) g2d_bitblt_data->src_list[i].x));
      G2D_WRITE_CMQ(G2D_CMQ_SRC_HEIGHT_ADDR | g2d_bitblt_data->src_list[i].height);
      G2D_WRITE_CMQ(G2D_CMQ_SRC_WIDTH_ADDR | g2d_bitblt_data->src_list[i].width);
      G2D_WRITE_CMQ(G2D_CMQ_FIRE_MODE_CTRL_REG_ADDR | g2d_fire_ctrl_reg_shadow);
      while (!G2D_CMQ_IS_WRITABLE) {};
      DISABLE_G2D_CMQ_WRITE;
   }
}  /* g2d_bitblt1() */

void g2d_draw_arc1(kal_uint8 g2d_owner_id, g2d_circle_struct *g2d_circle_data)
{
   kal_uint8 draw_two_arc=0;
   kal_uint16 clip_y1,clip_y2;

   if (g2d_owner_id!=g2d_current_owner_id)
      return;

   if ((g2d_circle_data->start_angle<180) && (g2d_circle_data->end_angle>180))
      draw_two_arc=1;

   if (draw_two_arc==0)
   {
      if (g2d_circle_data->end_angle<=180)
      {
         if (g2d_circle_data->start_angle<90)
         {
            clip_y1=g2d_circle_data->circle_center_y-((g2d_circle_data->circle_radius * (cosine_table[g2d_circle_data->start_angle]+1))>>16);
            if (g2d_circle_data->end_angle<90)
               clip_y2=g2d_circle_data->circle_center_y-((g2d_circle_data->circle_radius * (cosine_table[g2d_circle_data->end_angle]+1))>>16);
            else
               clip_y2=g2d_circle_data->circle_center_y+((g2d_circle_data->circle_radius * (cosine_table[180-g2d_circle_data->end_angle]+1))>>16);
         }
         else
         {
            clip_y1=g2d_circle_data->circle_center_y+((g2d_circle_data->circle_radius * (cosine_table[180-g2d_circle_data->start_angle]+1))>>16);
            clip_y2=g2d_circle_data->circle_center_y+((g2d_circle_data->circle_radius * (cosine_table[180-g2d_circle_data->end_angle]+1))>>16);
         }
      }
      else
      {
         if (g2d_circle_data->start_angle<270)
         {
            clip_y2=g2d_circle_data->circle_center_y+((g2d_circle_data->circle_radius * (cosine_table[g2d_circle_data->start_angle-180]+1))>>16);
            if (g2d_circle_data->end_angle<270)
               clip_y1=g2d_circle_data->circle_center_y+((g2d_circle_data->circle_radius * (cosine_table[g2d_circle_data->end_angle-180]+1))>>16);
            else
               clip_y1=g2d_circle_data->circle_center_y-((g2d_circle_data->circle_radius * (cosine_table[360-g2d_circle_data->end_angle]+1))>>16);
         }
         else
         {
            clip_y1=g2d_circle_data->circle_center_y-((g2d_circle_data->circle_radius * (cosine_table[360-g2d_circle_data->end_angle]+1))>>16);
            clip_y2=g2d_circle_data->circle_center_y-((g2d_circle_data->circle_radius * (cosine_table[360-g2d_circle_data->start_angle]+1))>>16);
         }
      }
   }
   else
   {
      if (g2d_circle_data->start_angle<90)
         clip_y1=g2d_circle_data->circle_center_y-((g2d_circle_data->circle_radius * (cosine_table[g2d_circle_data->start_angle]+1))>>16);
      else
         clip_y1=g2d_circle_data->circle_center_y+((g2d_circle_data->circle_radius * (cosine_table[180-g2d_circle_data->start_angle]+1))>>16);

      if (g2d_circle_data->end_angle<270)
         clip_y2=g2d_circle_data->circle_center_y+((g2d_circle_data->circle_radius * (cosine_table[g2d_circle_data->end_angle-180]+1))>>16);
      else
         clip_y2=g2d_circle_data->circle_center_y-((g2d_circle_data->circle_radius * (cosine_table[360-g2d_circle_data->end_angle]+1))>>16);
   }

   if (draw_two_arc==0)
   {  /* draw arc 6 or arc 9 only */
      while (G2D_CMQ_FREE_SPACE < 10) {};

      ENABLE_G2D_CMQ_WRITE;
      G2D_WRITE_CMQ(G2D_CMQ_CLIP_LEFT_X_ADDR | 0);
      G2D_WRITE_CMQ(G2D_CMQ_CLIP_RIGHT_X_ADDR | 0x7FFF);
      G2D_WRITE_CMQ(G2D_CMQ_CLIP_TOP_Y_ADDR | clip_y1);
      G2D_WRITE_CMQ(G2D_CMQ_CLIP_BOTTOM_Y_ADDR | clip_y2);

      g2d_submode_ctrl_reg_shadow &= ~REG_SUBMODE_CTRL_ENABLE_ARCS_MASK;
      if (g2d_circle_data->end_angle<=180)
         g2d_submode_ctrl_reg_shadow |= (G2D_CIRCLE_ARC_1_4<<16);
      else
         g2d_submode_ctrl_reg_shadow |= (G2D_CIRCLE_ARC_2_3<<16);
      G2D_WRITE_CMQ(G2D_CMQ_SUBMODE_CTRL_REG_L_ADDR | (g2d_submode_ctrl_reg_shadow & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_SUBMODE_CTRL_REG_H_ADDR | ((g2d_submode_ctrl_reg_shadow & 0xFFFF0000)>>16));

      G2D_WRITE_CMQ(G2D_CMQ_FIRE_MODE_CTRL_REG_ADDR | g2d_fire_ctrl_reg_shadow);
      while (!G2D_CMQ_IS_WRITABLE) {};
      DISABLE_G2D_CMQ_WRITE;
   }
   else
   {  /* draw arc 6 and arc 9 */
      while (G2D_CMQ_FREE_SPACE < 14) {};

      ENABLE_G2D_CMQ_WRITE;

      G2D_WRITE_CMQ(G2D_CMQ_CLIP_LEFT_X_ADDR | 0);
      G2D_WRITE_CMQ(G2D_CMQ_CLIP_RIGHT_X_ADDR | 0x7FFF);
      G2D_WRITE_CMQ(G2D_CMQ_CLIP_TOP_Y_ADDR | clip_y1);
      G2D_WRITE_CMQ(G2D_CMQ_CLIP_BOTTOM_Y_ADDR | 0x7FFF);

      g2d_submode_ctrl_reg_shadow &= ~REG_SUBMODE_CTRL_ENABLE_ARCS_MASK;
      g2d_submode_ctrl_reg_shadow |= (G2D_CIRCLE_ARC_1_4<<16);
      G2D_WRITE_CMQ(G2D_CMQ_SUBMODE_CTRL_REG_L_ADDR | (g2d_submode_ctrl_reg_shadow & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_SUBMODE_CTRL_REG_H_ADDR | ((g2d_submode_ctrl_reg_shadow & 0xFFFF0000)>>16));

      G2D_WRITE_CMQ(G2D_CMQ_FIRE_MODE_CTRL_REG_ADDR | g2d_fire_ctrl_reg_shadow);

      G2D_WRITE_CMQ(G2D_CMQ_CLIP_TOP_Y_ADDR | clip_y2);
      G2D_WRITE_CMQ(G2D_CMQ_CLIP_BOTTOM_Y_ADDR | 0x7FFF);
      g2d_submode_ctrl_reg_shadow &= ~REG_SUBMODE_CTRL_ENABLE_ARCS_MASK;
      g2d_submode_ctrl_reg_shadow |= (G2D_CIRCLE_ARC_2_3<<16);
      G2D_WRITE_CMQ(G2D_CMQ_SUBMODE_CTRL_REG_L_ADDR | (g2d_submode_ctrl_reg_shadow & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_SUBMODE_CTRL_REG_H_ADDR | ((g2d_submode_ctrl_reg_shadow & 0xFFFF0000)>>16));
      G2D_WRITE_CMQ(G2D_CMQ_FIRE_MODE_CTRL_REG_ADDR | g2d_fire_ctrl_reg_shadow);
      while (!G2D_CMQ_IS_WRITABLE) {};
      DISABLE_G2D_CMQ_WRITE;
   }
}  /* g2d_draw_arc1() */

void g2d_draw_arc(kal_uint8 g2d_owner_id, g2d_circle_struct *g2d_circle_data)
{
   g2d_circle_struct g2d_arc_para;

   if (g2d_owner_id!=g2d_current_owner_id)
      return;

   if ((g2d_circle_data->start_angle>360) || (g2d_circle_data->end_angle>360))
      ASSERT(0);
   g2d_arc_para.circle_center_x=g2d_circle_data->circle_center_x;
   g2d_arc_para.circle_center_y=g2d_circle_data->circle_center_y;
   g2d_arc_para.circle_radius=g2d_circle_data->circle_radius;
   g2d_arc_para.start_angle=g2d_circle_data->start_angle;
   g2d_arc_para.end_angle=g2d_circle_data->end_angle;
   g2d_arc_para.circle_color=g2d_circle_data->circle_color;

   while (G2D_CMQ_FREE_SPACE < 8) {};

   ENABLE_G2D_CMQ_WRITE;
   G2D_WRITE_CMQ(G2D_CMQ_CIRCLE_CENTER_Y_ADDR | ((kal_uint16)g2d_circle_data->circle_center_y));
   G2D_WRITE_CMQ(G2D_CMQ_CIRCLE_CENTER_X_ADDR | ((kal_uint16) g2d_circle_data->circle_center_x));
   G2D_WRITE_CMQ(G2D_CMQ_CIRCLE_RADIUS_ADDR | g2d_circle_data->circle_radius);
   G2D_WRITE_CMQ(G2D_CMQ_PAT_FG_COLOR_L_ADDR | (g2d_circle_data->circle_color&0xFFFF));
   G2D_WRITE_CMQ(G2D_CMQ_PAT_FG_COLOR_H_ADDR | ((g2d_circle_data->circle_color&0xFFFF0000)>>16));
   while (!G2D_CMQ_IS_WRITABLE) {};
   DISABLE_G2D_CMQ_WRITE;
   g2d_fire_ctrl_reg_shadow&=~REG_FIRE_CTRL_G2D_FUNCTION_MODE_MASK;
   g2d_fire_ctrl_reg_shadow|=G2D_OPERATION_CIRCLE_DRWAING;

   if (g2d_circle_data->start_angle<g2d_circle_data->end_angle)
   {
      g2d_draw_arc1(g2d_owner_id,&g2d_arc_para);
   }
   else
   {
      g2d_arc_para.end_angle=360;
      g2d_draw_arc1(g2d_owner_id,&g2d_arc_para);
      g2d_arc_para.start_angle=0;
      g2d_arc_para.end_angle=g2d_circle_data->end_angle;;
      g2d_draw_arc1(g2d_owner_id,&g2d_arc_para);
   }
}  /* g2d_draw_arc() */

void g2d_draw_bezier_curve(kal_uint8 g2d_owner_id, g2d_bezier_curve_struct *g2d_bezier_data)
{
   g2d_fire_ctrl_reg_shadow&=~REG_FIRE_CTRL_G2D_FUNCTION_MODE_MASK;
   g2d_fire_ctrl_reg_shadow|=G2D_OPERATION_BEZIER_CURVE_DRAWING;

   if (g2d_owner_id!=g2d_current_owner_id)
      return;

   while (G2D_CMQ_FREE_SPACE != G2D_CMQ_LENGTH) {};

   DISABLE_G2D_CMQ;
   RESET_G2D_ENGINE;
   ENABLE_G2D_CMQ;

   while (G2D_CMQ_FREE_SPACE < 14) {};

   ENABLE_G2D_CMQ_WRITE;
   G2D_WRITE_CMQ(G2D_CMQ_BEZIER_START_Y_ADDR | ((kal_uint16)g2d_bezier_data->start_y));
   G2D_WRITE_CMQ(G2D_CMQ_BEZIER_START_X_ADDR | ((kal_uint16) g2d_bezier_data->start_x));
   G2D_WRITE_CMQ(G2D_CMQ_BEZIER_MIDDLE_Y_ADDR | ((kal_uint16)g2d_bezier_data->middle_y));
   G2D_WRITE_CMQ(G2D_CMQ_BEZIER_MIDDLE_X_ADDR | ((kal_uint16) g2d_bezier_data->middle_x));
   G2D_WRITE_CMQ(G2D_CMQ_BEZIER_END_Y_ADDR | ((kal_uint16)g2d_bezier_data->end_y));
   G2D_WRITE_CMQ(G2D_CMQ_BEZIER_END_X_ADDR | ((kal_uint16) g2d_bezier_data->end_x));
   G2D_WRITE_CMQ(G2D_CMQ_BEZIER_SUBDIV_TIME_ADDR | 5);
   G2D_WRITE_CMQ(G2D_CMQ_BEZIER_BUF_START_L_ADDR | (((kal_uint32)subdivided_buffer) & 0xFFFF));
   G2D_WRITE_CMQ(G2D_CMQ_BEZIER_BUF_START_H_ADDR | ((((kal_uint32)subdivided_buffer) & 0xFFFF0000)>>16));
   G2D_WRITE_CMQ(G2D_CMQ_PAT_FG_COLOR_L_ADDR | (g2d_bezier_data->line_color&0xFFFF));
   G2D_WRITE_CMQ(G2D_CMQ_PAT_FG_COLOR_H_ADDR | ((g2d_bezier_data->line_color&0xFFFF0000)>>16));
   G2D_WRITE_CMQ(G2D_CMQ_FIRE_MODE_CTRL_REG_ADDR | g2d_fire_ctrl_reg_shadow);
   while (!G2D_CMQ_IS_WRITABLE) {};
   DISABLE_G2D_CMQ_WRITE;
}  /* g2d_draw_bezier_curve() */

void g2d_draw_line(kal_uint8 g2d_owner_id, g2d_line_struct *g2d_line_data)
{
   short start_x,start_y,end_x,end_y;
   short delta_x,delta_y;
   kal_uint16 xy_sqrt=0;
   double temp_data1;
   kal_uint32 temp_data;
   kal_uint16 i;

   if (g2d_line_data->antialias_mode==KAL_TRUE)
      g2d_submode_ctrl_reg_shadow |= REG_SUBMODE_CTRL_LINE_ANTI_ALIAS_BIT;
   else
      g2d_submode_ctrl_reg_shadow &=~ REG_SUBMODE_CTRL_LINE_ANTI_ALIAS_BIT;

   if (g2d_line_data->dotted_mode==KAL_TRUE)
      g2d_submode_ctrl_reg_shadow |= REG_SUBMODE_CTRL_DOTTED_LINE_BIT;
   else
      g2d_submode_ctrl_reg_shadow &= ~REG_SUBMODE_CTRL_DOTTED_LINE_BIT;

   while (G2D_CMQ_FREE_SPACE < 6) {};

   ENABLE_G2D_CMQ_WRITE;
   G2D_WRITE_CMQ(G2D_CMQ_SUBMODE_CTRL_REG_L_ADDR | (g2d_submode_ctrl_reg_shadow & 0xFFFF));
   G2D_WRITE_CMQ(G2D_CMQ_SUBMODE_CTRL_REG_H_ADDR | ((g2d_submode_ctrl_reg_shadow & 0xFFFF0000)>>16));
   G2D_WRITE_CMQ(G2D_CMQ_PAT_FG_COLOR_L_ADDR | (g2d_line_data->line_color&0xFFFF));
   G2D_WRITE_CMQ(G2D_CMQ_PAT_FG_COLOR_H_ADDR | ((g2d_line_data->line_color&0xFFFF0000)>>16));
   while (!G2D_CMQ_IS_WRITABLE) {};
   DISABLE_G2D_CMQ_WRITE;

   g2d_fire_ctrl_reg_shadow&=~REG_FIRE_CTRL_G2D_FUNCTION_MODE_MASK;
   g2d_fire_ctrl_reg_shadow|=G2D_OPERATION_LINE_DRAWING;

   for (i=0;i<g2d_line_data->line_count;i++)
   {
      start_x=*((short *) (g2d_line_data->line_end_coordinate+i*4));
      start_y=*((short *) (g2d_line_data->line_end_coordinate+i*4+1));
      end_x=*((short *) (g2d_line_data->line_end_coordinate+i*4+2));
      end_y=*((short *) (g2d_line_data->line_end_coordinate+i*4+3));

      delta_x=end_x-start_x;
      delta_y=end_y-start_y;
      if (g2d_line_data->antialias_mode==KAL_TRUE)
      {
         temp_data=delta_x*delta_x + delta_y*delta_y;
         temp_data1=2*sqrt(temp_data);
         xy_sqrt=(kal_uint16) temp_data1;
      }

      while (G2D_CMQ_FREE_SPACE < 10) {};

      ENABLE_G2D_CMQ_WRITE;

      G2D_WRITE_CMQ(G2D_CMQ_Y_START_ADDR | ((kal_uint16) start_y));
      G2D_WRITE_CMQ(G2D_CMQ_X_START_ADDR | ((kal_uint16) start_x));
      G2D_WRITE_CMQ(G2D_CMQ_Y_END_ADDR | ((kal_uint16) end_y));
      G2D_WRITE_CMQ(G2D_CMQ_X_END_ADDR | ((kal_uint16) end_x));
      G2D_WRITE_CMQ(G2D_CMQ_XY_SQRT_L_ADDR | ((kal_uint16) (xy_sqrt & 0xFFFF)));

      G2D_WRITE_CMQ(G2D_CMQ_FIRE_MODE_CTRL_REG_ADDR | g2d_fire_ctrl_reg_shadow);
      while (!G2D_CMQ_IS_WRITABLE) {};
      DISABLE_G2D_CMQ_WRITE;
   }
}  /* g2d_draw_line()*/

void g2d_draw_polygon(kal_uint8 g2d_owner_id, g2d_polygon_struct *g2d_polygon_data)
{
   short start_x,start_y,end_x,end_y;
   short delta_x,delta_y;
   kal_uint16 xy_sqrt=0;
   double temp_data1;
   kal_uint32 temp_data;
   kal_uint16 i;

   if (g2d_owner_id!=g2d_current_owner_id)
      return;

   if (g2d_polygon_data->antialias_mode==KAL_TRUE)
      g2d_submode_ctrl_reg_shadow |= REG_SUBMODE_CTRL_LINE_ANTI_ALIAS_BIT;
   else
      g2d_submode_ctrl_reg_shadow &=~ REG_SUBMODE_CTRL_LINE_ANTI_ALIAS_BIT;

   if (g2d_polygon_data->dotted_mode==KAL_TRUE)
      g2d_submode_ctrl_reg_shadow |= REG_SUBMODE_CTRL_DOTTED_LINE_BIT;
   else
      g2d_submode_ctrl_reg_shadow &= ~REG_SUBMODE_CTRL_DOTTED_LINE_BIT;

   while (G2D_CMQ_FREE_SPACE < 6) {};

   ENABLE_G2D_CMQ_WRITE;
   G2D_WRITE_CMQ(G2D_CMQ_SUBMODE_CTRL_REG_L_ADDR | (g2d_submode_ctrl_reg_shadow & 0xFFFF));
   G2D_WRITE_CMQ(G2D_CMQ_SUBMODE_CTRL_REG_H_ADDR | ((g2d_submode_ctrl_reg_shadow & 0xFFFF0000)>>16));
   G2D_WRITE_CMQ(G2D_CMQ_PAT_FG_COLOR_L_ADDR | (g2d_polygon_data->line_color&0xFFFF));
   G2D_WRITE_CMQ(G2D_CMQ_PAT_FG_COLOR_H_ADDR | ((g2d_polygon_data->line_color&0xFFFF0000)>>16));

   while (!G2D_CMQ_IS_WRITABLE) {};
   DISABLE_G2D_CMQ_WRITE;

   g2d_fire_ctrl_reg_shadow&=~REG_FIRE_CTRL_G2D_FUNCTION_MODE_MASK;
   g2d_fire_ctrl_reg_shadow|=G2D_OPERATION_LINE_DRAWING;

   for (i=0;i<g2d_polygon_data->polygon_number-1;i++) //hjf
   {
      start_x=*((short *) (g2d_polygon_data->point_coordinate+i*2));
      start_y=*((short *) (g2d_polygon_data->point_coordinate+i*2+1));
      end_x=*((short *) (g2d_polygon_data->point_coordinate+i*2+2));
      end_y=*((short *) (g2d_polygon_data->point_coordinate+i*2+3));

      delta_x=end_x-start_x;
      delta_y=end_y-start_y;
      if (g2d_polygon_data->antialias_mode==KAL_TRUE)
      {
         temp_data=delta_x*delta_x + delta_y*delta_y;
         temp_data1=2*sqrt(temp_data);
         xy_sqrt=(kal_uint16) temp_data1;
      }

      while (G2D_CMQ_FREE_SPACE < 10) {};

      ENABLE_G2D_CMQ_WRITE;

      G2D_WRITE_CMQ(G2D_CMQ_Y_START_ADDR | ((kal_uint16) start_y));
      G2D_WRITE_CMQ(G2D_CMQ_X_START_ADDR | ((kal_uint16) start_x));
      G2D_WRITE_CMQ(G2D_CMQ_Y_END_ADDR | ((kal_uint16) end_y));
      G2D_WRITE_CMQ(G2D_CMQ_X_END_ADDR | ((kal_uint16) end_x));
      G2D_WRITE_CMQ(G2D_CMQ_XY_SQRT_L_ADDR | ((kal_uint16) (xy_sqrt & 0xFFFF)));

      G2D_WRITE_CMQ(G2D_CMQ_FIRE_MODE_CTRL_REG_ADDR | g2d_fire_ctrl_reg_shadow);
      while (!G2D_CMQ_IS_WRITABLE) {};
      DISABLE_G2D_CMQ_WRITE;
   }
}  /* g2d_draw_polygon() */

void g2d_fill_polygon(kal_uint8 g2d_owner_id, g2d_polygon_fill_struct *g2d_fill_polygon_data)
{  /* fill polygon by triangle fill function */
   kal_uint8 i,triangle_number;
   short start_x,start_y,middle_x,middle_y,end_x,end_y;
   g2d_triangle_para_struct g2d_triangle_data;

   if (g2d_owner_id!=g2d_current_owner_id)
      return;

   if ((g2d_fill_polygon_data->point_number%3)!=0)
      ASSERT(0);
   triangle_number=g2d_fill_polygon_data->point_number/3;

   g2d_fire_ctrl_reg_shadow&=~REG_FIRE_CTRL_G2D_FUNCTION_MODE_MASK;
   g2d_fire_ctrl_reg_shadow|=G2D_OPERATION_TRIANGLE_FILL;

   while (G2D_CMQ_FREE_SPACE < 4) {};

   ENABLE_G2D_CMQ_WRITE;
   G2D_WRITE_CMQ(G2D_CMQ_PAT_FG_COLOR_L_ADDR | (g2d_fill_polygon_data->fill_color&0xFFFF));
   G2D_WRITE_CMQ(G2D_CMQ_PAT_FG_COLOR_H_ADDR | ((g2d_fill_polygon_data->fill_color&0xFFFF0000)>>16));
   while (!G2D_CMQ_IS_WRITABLE) {};
   DISABLE_G2D_CMQ_WRITE;

   for (i=0;i<triangle_number;i++) //hjf
   {
      start_x=*((short *) (g2d_fill_polygon_data->point_coordinate+i*6));
      start_y=*((short *) (g2d_fill_polygon_data->point_coordinate+i*6+1));
      middle_x=*((short *) (g2d_fill_polygon_data->point_coordinate+i*6+2));
      middle_y=*((short *) (g2d_fill_polygon_data->point_coordinate+i*6+3));
      end_x=*((short *) (g2d_fill_polygon_data->point_coordinate+i*6+4));
      end_y=*((short *) (g2d_fill_polygon_data->point_coordinate+i*6+5));
      g2d_get_triangle_slope(start_x,start_y,middle_x,middle_y,end_x,end_y,&g2d_triangle_data);

      while (G2D_CMQ_FREE_SPACE < 10) {};

      ENABLE_G2D_CMQ_WRITE;
      G2D_WRITE_CMQ(G2D_CMQ_Y_START_ADDR | ((kal_uint16)g2d_triangle_data.first_y));
      G2D_WRITE_CMQ(G2D_CMQ_X_START_ADDR | ((kal_uint16) g2d_triangle_data.first_x));
      G2D_WRITE_CMQ(G2D_CMQ_TRIANGLE_Y_END_ADDR | ((kal_uint16)g2d_triangle_data.middle_y));
      G2D_WRITE_CMQ(G2D_CMQ_TRIANGLE_SLOPE_R_L_ADDR | (g2d_triangle_data.slope2 & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_TRIANGLE_SLOPE_R_H_ADDR | ((g2d_triangle_data.slope2 & 0xFFFF0000)>>16));
      G2D_WRITE_CMQ(G2D_CMQ_TRIANGLE_SLOPE_L_L_ADDR | (g2d_triangle_data.slope1 & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_TRIANGLE_SLOPE_L_H_ADDR | ((g2d_triangle_data.slope1 & 0xFFFF0000)>>16));
      G2D_WRITE_CMQ(G2D_CMQ_FIRE_MODE_CTRL_REG_ADDR | g2d_fire_ctrl_reg_shadow);
      if (g2d_triangle_data.two_triangle==KAL_TRUE)
{
         while (G2D_CMQ_FREE_SPACE < 10) {};

         ENABLE_G2D_CMQ_WRITE;
         G2D_WRITE_CMQ(G2D_CMQ_Y_START_ADDR | ((kal_uint16)g2d_triangle_data.second_y));
         G2D_WRITE_CMQ(G2D_CMQ_X_START_ADDR | ((kal_uint16) g2d_triangle_data.second_x));
         G2D_WRITE_CMQ(G2D_CMQ_TRIANGLE_SLOPE_R_L_ADDR | (g2d_triangle_data.slope4 & 0xFFFF));
         G2D_WRITE_CMQ(G2D_CMQ_TRIANGLE_SLOPE_R_H_ADDR | ((g2d_triangle_data.slope4 & 0xFFFF0000)>>16));
         G2D_WRITE_CMQ(G2D_CMQ_TRIANGLE_SLOPE_L_L_ADDR | (g2d_triangle_data.slope3 & 0xFFFF));
         G2D_WRITE_CMQ(G2D_CMQ_TRIANGLE_SLOPE_L_H_ADDR | ((g2d_triangle_data.slope3 & 0xFFFF0000)>>16));
         G2D_WRITE_CMQ(G2D_CMQ_FIRE_MODE_CTRL_REG_ADDR | g2d_fire_ctrl_reg_shadow);
      }
      while (!G2D_CMQ_IS_WRITABLE) {};
      DISABLE_G2D_CMQ_WRITE;
   }
}  /* g2d_fill_polygon() */

void g2d_fill_rectangle(kal_uint8 g2d_owner_id, g2d_rectangle_fill_struct *g2d_rec_fill_data)
{
   if (g2d_owner_id!=g2d_current_owner_id)
      return;

   g2d_fire_ctrl_reg_shadow&=~REG_FIRE_CTRL_G2D_FUNCTION_MODE_MASK;
   g2d_fire_ctrl_reg_shadow|=G2D_OPERATION_RECTANGLE_FILL;

   g2d_submode_ctrl_reg_shadow |= REG_SUBMODE_CTRL_BITBLT_DIRECTION_MASK;
   g2d_submode_ctrl_reg_shadow &= ~REG_SUBMODE_CTRL_BITBLT_TRANSFORM_MASK;
   g2d_submode_ctrl_reg_shadow |= BITBLT_TRANSFORM_COPY;

   if (g2d_rec_fill_data->tilt_mode==KAL_TRUE)
      g2d_submode_ctrl_reg_shadow |= REG_SUBMODE_CTRL_ITALIC_BITBLT_BIT;
   else
      g2d_submode_ctrl_reg_shadow &= ~REG_SUBMODE_CTRL_ITALIC_BITBLT_BIT;

   if (g2d_rec_fill_data->gradient_fill_mode==KAL_TRUE)
      g2d_submode_ctrl_reg_shadow |= REG_SUBMODE_CTRL_COLOR_GRADIENT_BIT;
   else
      g2d_submode_ctrl_reg_shadow &= ~REG_SUBMODE_CTRL_COLOR_GRADIENT_BIT;

   while (G2D_CMQ_FREE_SPACE < 10) {};

   ENABLE_G2D_CMQ_WRITE;
   G2D_WRITE_CMQ(G2D_CMQ_SUBMODE_CTRL_REG_L_ADDR | (g2d_submode_ctrl_reg_shadow & 0xFFFF));
   G2D_WRITE_CMQ(G2D_CMQ_SUBMODE_CTRL_REG_H_ADDR | ((g2d_submode_ctrl_reg_shadow & 0xFFFF0000)>>16));
   G2D_WRITE_CMQ(G2D_CMQ_DEST_X_ADDR | ((kal_uint16) g2d_rec_fill_data->start_x));
   G2D_WRITE_CMQ(G2D_CMQ_DEST_Y_ADDR | ((kal_uint16) g2d_rec_fill_data->start_y));
   G2D_WRITE_CMQ(G2D_CMQ_DEST_HEIGHT_ADDR | g2d_rec_fill_data->height);
   G2D_WRITE_CMQ(G2D_CMQ_DEST_WIDTH_ADDR | g2d_rec_fill_data->width);
   G2D_WRITE_CMQ(G2D_CMQ_PAT_FG_COLOR_L_ADDR | (g2d_rec_fill_data->fill_color&0xFFFF));
   G2D_WRITE_CMQ(G2D_CMQ_PAT_FG_COLOR_H_ADDR | ((g2d_rec_fill_data->fill_color&0xFFFF0000)>>16));
   while (!G2D_CMQ_IS_WRITABLE) {};
   DISABLE_G2D_CMQ_WRITE;

   if (g2d_rec_fill_data->gradient_fill_mode==KAL_TRUE)
   {
      while (G2D_CMQ_FREE_SPACE < 12) {};

      ENABLE_G2D_CMQ_WRITE;

      G2D_WRITE_CMQ((G2D_CMQ_ALPHA_GRAD_X_L_ADDR|(g2d_rec_fill_data->delta_gradient[0] & 0xFFFF)));
      G2D_WRITE_CMQ((G2D_CMQ_ALPHA_GRAD_X_H_ADDR|((g2d_rec_fill_data->delta_gradient[0]>>16) & 0xFFFF)));
      G2D_WRITE_CMQ((G2D_CMQ_ALPHA_GRAD_Y_L_ADDR|(g2d_rec_fill_data->delta_gradient[1] & 0xFFFF)));
      G2D_WRITE_CMQ((G2D_CMQ_ALPHA_GRAD_Y_H_ADDR|((g2d_rec_fill_data->delta_gradient[1]>>16) & 0xFFFF)));

      G2D_WRITE_CMQ((G2D_CMQ_RED_GRAD_X_L_ADDR|(g2d_rec_fill_data->delta_gradient[2] & 0xFFFF)));
      G2D_WRITE_CMQ((G2D_CMQ_RED_GRAD_X_H_ADDR|((g2d_rec_fill_data->delta_gradient[2]>>16) & 0xFFFF)));
      G2D_WRITE_CMQ((G2D_CMQ_RED_GRAD_Y_L_ADDR|(g2d_rec_fill_data->delta_gradient[3] & 0xFFFF)));
      G2D_WRITE_CMQ((G2D_CMQ_RED_GRAD_Y_H_ADDR|((g2d_rec_fill_data->delta_gradient[3]>>16) & 0xFFFF)));

      G2D_WRITE_CMQ((G2D_CMQ_GREEN_GRAD_X_L_ADDR|(g2d_rec_fill_data->delta_gradient[4] & 0xFFFF)));
      G2D_WRITE_CMQ((G2D_CMQ_GREEN_GRAD_X_H_ADDR|((g2d_rec_fill_data->delta_gradient[4]>>16) & 0xFFFF)));
      G2D_WRITE_CMQ((G2D_CMQ_GREEN_GRAD_Y_L_ADDR|(g2d_rec_fill_data->delta_gradient[5] & 0xFFFF)));
      G2D_WRITE_CMQ((G2D_CMQ_GREEN_GRAD_Y_H_ADDR|((g2d_rec_fill_data->delta_gradient[5]>>16) & 0xFFFF)));

      G2D_WRITE_CMQ((G2D_CMQ_BLUE_GRAD_X_L_ADDR|(g2d_rec_fill_data->delta_gradient[6] & 0xFFFF)));
      G2D_WRITE_CMQ((G2D_CMQ_BLUE_GRAD_X_H_ADDR|((g2d_rec_fill_data->delta_gradient[6]>>16) & 0xFFFF)));
      G2D_WRITE_CMQ((G2D_CMQ_BLUE_GRAD_Y_L_ADDR|(g2d_rec_fill_data->delta_gradient[7] & 0xFFFF)));
      G2D_WRITE_CMQ((G2D_CMQ_BLUE_GRAD_Y_H_ADDR|((g2d_rec_fill_data->delta_gradient[7]>>16) & 0xFFFF)));

      G2D_WRITE_CMQ(G2D_CMQ_FIRE_MODE_CTRL_REG_ADDR | g2d_fire_ctrl_reg_shadow);
      while (!G2D_CMQ_IS_WRITABLE) {};
      DISABLE_G2D_CMQ_WRITE;
   }
   else
{
      while (G2D_CMQ_FREE_SPACE < 3) {};

      ENABLE_G2D_CMQ_WRITE;

      G2D_WRITE_CMQ(G2D_CMQ_FIRE_MODE_CTRL_REG_ADDR | g2d_fire_ctrl_reg_shadow);
      while (!G2D_CMQ_IS_WRITABLE) {};
      DISABLE_G2D_CMQ_WRITE;
   }
}  /* g2d_fill_rectangle() */

void g2d_draw_gradient_h_line(kal_uint8 g2d_owner_id, g2d_gradient_line_struct *g2d_h_line_data)
{
   kal_uint16 i;
   kal_uint32 dest_address,address_offset;
   kal_uint8 bytes_per_pixel;

   if (g2d_owner_id!=g2d_current_owner_id)
      return;

   switch (g2d_dest_buff_data.color_mode)
   {
      case FIRE_DEST_COLOR_8BPP_LUT_DIS:
         bytes_per_pixel=1;
      break;
      case FIRE_DEST_COLOR_16BPP_RGB565:
      case FIRE_DEST_COLOR_16BPP_ARGB4444:
         bytes_per_pixel=2;
      break;
      case FIRE_DEST_COLOR_32BPP_ARGB8888:
         bytes_per_pixel=4;
      break;
      case FIRE_DEST_COLOR_24BPP_RGB888:
         bytes_per_pixel=3;
      break;
      default:
//       ASSERT(0);
      break;
   }
   g2d_fire_ctrl_reg_shadow&=~REG_FIRE_CTRL_G2D_FUNCTION_MODE_MASK;
   g2d_fire_ctrl_reg_shadow|=G2D_OPERATION_H_LINE_FILL;

   g2d_submode_ctrl_reg_shadow |= REG_SUBMODE_CTRL_BITBLT_DIRECTION_MASK;
   g2d_submode_ctrl_reg_shadow &= ~REG_SUBMODE_CTRL_BITBLT_TRANSFORM_MASK;
   g2d_submode_ctrl_reg_shadow |= BITBLT_TRANSFORM_COPY;
   g2d_submode_ctrl_reg_shadow |= REG_SUBMODE_CTRL_COLOR_GRADIENT_BIT;

   while (G2D_CMQ_FREE_SPACE < 5) {};
   ENABLE_G2D_CMQ_WRITE;
   G2D_WRITE_CMQ(G2D_CMQ_SUBMODE_CTRL_REG_L_ADDR | (g2d_submode_ctrl_reg_shadow & 0xFFFF));
   G2D_WRITE_CMQ(G2D_CMQ_SUBMODE_CTRL_REG_H_ADDR | ((g2d_submode_ctrl_reg_shadow & 0xFFFF0000)>>16));
   while (!G2D_CMQ_IS_WRITABLE) {};
   DISABLE_G2D_CMQ_WRITE;

   dest_address=g2d_dest_buff_data.base_address;
   for (i=0;i<g2d_h_line_data->line_number;i++)
   {
      if ((((*((short *) (g2d_h_line_data->line_start_coordinate+i*2+1))))>=0)&&
          (((*((short *) (g2d_h_line_data->line_start_coordinate+i*2))))>=0))
      {
      address_offset=(((kal_uint16)(*((short *) (g2d_h_line_data->line_start_coordinate+i*2+1))))*g2d_dest_buff_data.pitch+
                     ((kal_uint16)(*((short *) (g2d_h_line_data->line_start_coordinate+i*2)))))*bytes_per_pixel;
      while (G2D_CMQ_FREE_SPACE < 18) {};
      ENABLE_G2D_CMQ_WRITE;
      G2D_WRITE_CMQ(G2D_CMQ_DEST_BASE_L_ADDR | ((dest_address+address_offset) & 0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_DEST_BASE_H_ADDR | (((dest_address+address_offset)>>16) & 0xFFFF));
         G2D_WRITE_CMQ(G2D_CMQ_DEST_WIDTH_ADDR | ((kal_uint16) g2d_h_line_data->line_width[i]));
      G2D_WRITE_CMQ(G2D_CMQ_GRAD_START_COLOR_L_ADDR | (g2d_h_line_data->line_color&0xFFFF));
      G2D_WRITE_CMQ(G2D_CMQ_GRAD_START_COLOR_H_ADDR | ((g2d_h_line_data->line_color&0xFFFF0000)>>16));

      G2D_WRITE_CMQ((G2D_CMQ_ALPHA_GRAD_X_L_ADDR|(g2d_h_line_data->delta_gardient[i*4] & 0xFFFF)));
      G2D_WRITE_CMQ((G2D_CMQ_ALPHA_GRAD_X_H_ADDR|((g2d_h_line_data->delta_gardient[i*4]>>16) & 0xFFFF)));

      G2D_WRITE_CMQ((G2D_CMQ_RED_GRAD_X_L_ADDR|(g2d_h_line_data->delta_gardient[i*4+1] & 0xFFFF)));
      G2D_WRITE_CMQ((G2D_CMQ_RED_GRAD_X_H_ADDR|((g2d_h_line_data->delta_gardient[i*4+1]>>16) & 0xFFFF)));

      G2D_WRITE_CMQ((G2D_CMQ_GREEN_GRAD_X_L_ADDR|(g2d_h_line_data->delta_gardient[i*4+2] & 0xFFFF)));
      G2D_WRITE_CMQ((G2D_CMQ_GREEN_GRAD_X_H_ADDR|((g2d_h_line_data->delta_gardient[i*4+2]>>16) & 0xFFFF)));

      G2D_WRITE_CMQ((G2D_CMQ_BLUE_GRAD_X_L_ADDR|(g2d_h_line_data->delta_gardient[i*4+3] & 0xFFFF)));
      G2D_WRITE_CMQ((G2D_CMQ_BLUE_GRAD_X_H_ADDR|((g2d_h_line_data->delta_gardient[i*4+3]>>16) & 0xFFFF)));

      G2D_WRITE_CMQ(G2D_CMQ_FIRE_MODE_CTRL_REG_ADDR | g2d_fire_ctrl_reg_shadow);
      while (!G2D_CMQ_IS_WRITABLE) {};
      DISABLE_G2D_CMQ_WRITE;
   }
   }
}  /* g2d_draw_gradient_h_line() */

void g2d_copy_h_line(kal_uint8 g2d_owner_id, g2d_line_copy_struct *g2d_copy_h_line_data)
{
   kal_uint16 i;
   kal_uint32 dest_address,address_offset;
   kal_uint8 bytes_per_pixel;

   if (g2d_owner_id!=g2d_current_owner_id)
      return;

   switch (g2d_dest_buff_data.color_mode)
   {
      case FIRE_DEST_COLOR_8BPP_LUT_DIS:
         bytes_per_pixel=1;
      break;
      case FIRE_DEST_COLOR_16BPP_RGB565:
      case FIRE_DEST_COLOR_16BPP_ARGB4444:
         bytes_per_pixel=2;
      break;
      case FIRE_DEST_COLOR_32BPP_ARGB8888:
         bytes_per_pixel=4;
      break;
      case FIRE_DEST_COLOR_24BPP_RGB888:
         bytes_per_pixel=3;
      break;
      default:
//       ASSERT(0);
      break;
   }
   g2d_fire_ctrl_reg_shadow&=~REG_FIRE_CTRL_G2D_FUNCTION_MODE_MASK;
   g2d_fire_ctrl_reg_shadow|=G2D_OPERATION_H_LINE_COPY_MASK;
   g2d_fire_ctrl_reg_shadow &= ~REG_FIRE_CTRL_SOURCE_COLOR_MODE_MASK;
   g2d_fire_ctrl_reg_shadow |= g2d_copy_h_line_data->src->color_mode;

   g2d_submode_ctrl_reg_shadow |= REG_SUBMODE_CTRL_BITBLT_DIRECTION_MASK;
   g2d_submode_ctrl_reg_shadow &= ~REG_SUBMODE_CTRL_BITBLT_TRANSFORM_MASK;
   g2d_submode_ctrl_reg_shadow |= BITBLT_TRANSFORM_COPY;

   while (G2D_CMQ_FREE_SPACE < 8) {};

   ENABLE_G2D_CMQ_WRITE;
   G2D_WRITE_CMQ(G2D_CMQ_SUBMODE_CTRL_REG_L_ADDR | (g2d_submode_ctrl_reg_shadow & 0xFFFF));
   G2D_WRITE_CMQ(G2D_CMQ_SUBMODE_CTRL_REG_H_ADDR | ((g2d_submode_ctrl_reg_shadow & 0xFFFF0000)>>16));
   G2D_WRITE_CMQ(G2D_CMQ_SRC_BASE_L_ADDR | (g2d_copy_h_line_data->src->base_address & 0xFFFF));
   G2D_WRITE_CMQ(G2D_CMQ_SRC_BASE_H_ADDR | ((g2d_copy_h_line_data->src->base_address>>16) & 0xFFFF));
   G2D_WRITE_CMQ(G2D_CMQ_SRC_WIDTH_ADDR | ((kal_uint16) g2d_copy_h_line_data->src->width));
   while (!G2D_CMQ_IS_WRITABLE) {};
   DISABLE_G2D_CMQ_WRITE;

   dest_address=g2d_dest_buff_data.base_address;

   for (i=0;i<g2d_copy_h_line_data->line_number;i++)
   {
      if ((((*((short *) (g2d_copy_h_line_data->line_start_coordinate+i*2+1))))>=0)&&
          (((*((short *) (g2d_copy_h_line_data->line_start_coordinate+i*2))))>=0))
      {
         address_offset=(((kal_uint16)(*((short *) (g2d_copy_h_line_data->line_start_coordinate+i*2+1))))*g2d_dest_buff_data.pitch+
                        ((kal_uint16)(*((short *) (g2d_copy_h_line_data->line_start_coordinate+i*2)))))*bytes_per_pixel;
         while (G2D_CMQ_FREE_SPACE < 8) {};

         ENABLE_G2D_CMQ_WRITE;
         G2D_WRITE_CMQ(G2D_CMQ_DEST_BASE_L_ADDR | ((dest_address+address_offset) & 0xFFFF));
         G2D_WRITE_CMQ(G2D_CMQ_DEST_BASE_H_ADDR | (((dest_address+address_offset)>>16) & 0xFFFF));
         G2D_WRITE_CMQ(G2D_CMQ_DEST_WIDTH_ADDR | ((kal_uint16) g2d_copy_h_line_data->line_width[i]));
         G2D_WRITE_CMQ(G2D_CMQ_MASK_BASE_L_ADDR|(((kal_uint32) g2d_copy_h_line_data->mask_address[i])&0xFFFF));
         G2D_WRITE_CMQ(G2D_CMQ_MASK_BASE_H_ADDR|((((kal_uint32) g2d_copy_h_line_data->mask_address[i])>>16)&0xFFFF));
         G2D_WRITE_CMQ(G2D_CMQ_FIRE_MODE_CTRL_REG_ADDR | g2d_fire_ctrl_reg_shadow);
         while (!G2D_CMQ_IS_WRITABLE) {};
         DISABLE_G2D_CMQ_WRITE;
      }
   }
}  /* g2d_copy_h_line()*/
#endif
#else
kal_bool g2d_begin(kal_uint8 g2d_owner_id, void (*g2d_cb)())
{
   if (g2d_current_owner_id!=G2D_OWNER_NONE)
      return KAL_FALSE;
   g2d_current_owner_id=g2d_owner_id;
   return KAL_TRUE;
}  /* g2d_begin() */

void g2d_end(kal_uint8 g2d_owner_id)
{
   if (g2d_owner_id!=g2d_current_owner_id)
      return;
   g2d_current_owner_id=G2D_OWNER_NONE;
}  /* g2d_end() */

void g2d_set_dest_buffer(kal_uint8 g2d_owner_id, g2d_buffer_struct *dest)
{
   if (g2d_owner_id!=g2d_current_owner_id)
      return;

   g2d_dest_buff_data.base_address=dest->base_address;
   g2d_dest_buff_data.x=dest->x;
   g2d_dest_buff_data.y=dest->y;
   g2d_dest_buff_data.pitch=dest->pitch;
   g2d_dest_buff_data.height=dest->height;
   g2d_dest_buff_data.width=dest->width;
   g2d_dest_buff_data.clip_y1=dest->clip_y1;
   g2d_dest_buff_data.clip_x1=dest->clip_x1;
   g2d_dest_buff_data.clip_y2=dest->clip_y2;
   g2d_dest_buff_data.clip_x2=dest->clip_x2;
   g2d_dest_buff_data.color_mode=dest->color_mode;

   g2d_control_data.dest_base_address=dest->base_address;
   g2d_control_data.dest_x=dest->x;
   g2d_control_data.dest_y=dest->y;
   g2d_control_data.dest_pitch=dest->pitch;
   g2d_control_data.dest_width=dest->width;
   g2d_control_data.dest_height=dest->height;
   g2d_control_data.clip_start_x=dest->clip_x1;
   g2d_control_data.clip_start_y=dest->clip_y1;
   g2d_control_data.clip_end_x=dest->clip_x2;
   g2d_control_data.clip_end_y=dest->clip_y2;
   g2d_control_data.dest_color_mode=(kal_uint8) dest->color_mode;
}  /* g2d_set_dest_buffer() */

void g2d_font_set_attribute(kal_uint8 g2d_owner_id, g2d_font_attribute_struct *g2d_font_attr)
{
   if (g2d_owner_id!=g2d_current_owner_id)
      return;

   g2d_font_attr_data.tilt_mode=g2d_font_attr->tilt_mode;
   g2d_font_attr_data.bold_mode=g2d_font_attr->bold_mode;
   g2d_font_attr_data.border_mode=g2d_font_attr->border_mode;
   g2d_font_attr_data.enable_bg_color=g2d_font_attr->enable_bg_color;
   g2d_font_attr_data.fg_color=g2d_font_attr->fg_color;
   g2d_font_attr_data.bg_color=g2d_font_attr->bg_color;

   if (g2d_font_attr->tilt_mode==KAL_TRUE)
      g2d_control_data.italic_mode=G2D_REC_FILL_ITALIC_ENABLE;
   else
      g2d_control_data.italic_mode=G2D_REC_FILL_ITALIC_DISABLE;
   g2d_control_data.font_background_mode=g2d_font_attr->enable_bg_color;
   g2d_control_data.pat_fg_color=g2d_font_attr->fg_color;
   g2d_control_data.pat_bg_color=g2d_font_attr->bg_color;
}  /* g2d_font_set_attribute() */

void g2d_draw_font(kal_uint8 g2d_owner_id, g2d_font_struct *g2d_font_data)
{
   if (g2d_owner_id!=g2d_current_owner_id)
      return;

   g2d_control_data.src_base_address=g2d_font_data->font_address;
   g2d_control_data.font_start_position=g2d_font_data->bit_offset;
   g2d_control_data.font_order=G2D_FONT_ORDER_LSB_FIRST;
   g2d_control_data.dest_width=g2d_font_data->font_width;
   g2d_control_data.dest_height=g2d_font_data->font_height;
   g2d_control_data.dest_x=g2d_font_data->start_x;
   g2d_control_data.dest_y=g2d_font_data->start_y;

   if ((g2d_font_attr_data.bold_mode==KAL_TRUE)|| (g2d_font_attr_data.border_mode==KAL_TRUE))
      g2d_control_data.font_background_mode=G2D_FONT_BACKGROUND_DISABLE;

   if (g2d_font_attr_data.bold_mode==KAL_TRUE)
   {
      g2d_sw_font_caching(&g2d_control_data);
      g2d_control_data.dest_y=g2d_font_data->start_y-1;
      g2d_sw_font_caching(&g2d_control_data);
   }
   else if (g2d_font_attr_data.border_mode==KAL_TRUE)
   {
      g2d_control_data.pat_bg_color=g2d_font_attr_data.bg_color+10;
      g2d_control_data.pat_fg_color=g2d_font_attr_data.bg_color;
      g2d_control_data.dest_x=g2d_font_data->start_x-1;
      g2d_control_data.dest_y=g2d_font_data->start_y-1;
      g2d_sw_font_caching(&g2d_control_data);
      g2d_control_data.dest_x=g2d_font_data->start_x-1;
      g2d_control_data.dest_y=g2d_font_data->start_y+1;
      g2d_sw_font_caching(&g2d_control_data);
      g2d_control_data.dest_x=g2d_font_data->start_x+1;
      g2d_control_data.dest_y=g2d_font_data->start_y-1;
      g2d_sw_font_caching(&g2d_control_data);
      g2d_control_data.dest_x=g2d_font_data->start_x+1;
      g2d_control_data.dest_y=g2d_font_data->start_y+1;
      g2d_sw_font_caching(&g2d_control_data);
      g2d_control_data.dest_x=g2d_font_data->start_x;
      g2d_control_data.dest_y=g2d_font_data->start_y-1;
      g2d_sw_font_caching(&g2d_control_data);
      g2d_control_data.dest_x=g2d_font_data->start_x;
      g2d_control_data.dest_y=g2d_font_data->start_y+1;
      g2d_sw_font_caching(&g2d_control_data);
      g2d_control_data.dest_x=g2d_font_data->start_x-1;
      g2d_control_data.dest_y=g2d_font_data->start_y;
      g2d_sw_font_caching(&g2d_control_data);
      g2d_control_data.dest_x=g2d_font_data->start_x+1;
      g2d_control_data.dest_y=g2d_font_data->start_y;
      g2d_sw_font_caching(&g2d_control_data);
      g2d_control_data.pat_bg_color=(g2d_control_data.pat_bg_color&0xFFFF0000)|
                                    (g2d_font_attr_data.fg_color+10)&0xFFFF;
      g2d_control_data.pat_fg_color=g2d_font_attr_data.fg_color;
      g2d_control_data.dest_x=g2d_font_data->start_x;
      g2d_control_data.dest_y=g2d_font_data->start_y;
      g2d_sw_font_caching(&g2d_control_data);
   }
   else
      g2d_sw_font_caching(&g2d_control_data);
}  /* g2d_draw_font() */

void g2d_bitblt1(kal_uint8 g2d_owner_id, g2d_bitblt_struct *g2d_bitblt_data)
{
   kal_uint16 i;

   if (g2d_owner_id!=g2d_current_owner_id)
      return;
   if (g2d_bitblt_data->alpha_blending_mode==KAL_TRUE)
      g2d_control_data.g2d_operation_mode=G2D_OPERATION_ALPHA_BLENDING;
   else if (g2d_bitblt_data->rop_mode==KAL_TRUE)
      g2d_control_data.g2d_operation_mode=G2D_OPERATION_ROP_BITBLT;
   else
      g2d_control_data.g2d_operation_mode=G2D_OPERATION_BITBLT;

   g2d_control_data.src_alpha=g2d_bitblt_data->alpha_value;
   g2d_control_data.rop_mode=g2d_bitblt_data->rop_value;
   g2d_control_data.bitblt_mode=g2d_bitblt_data->transform_value;
   if (g2d_bitblt_data->tilt_mode==KAL_TRUE)
      g2d_control_data.italic_mode=G2D_REC_FILL_ITALIC_ENABLE;
   else
      g2d_control_data.italic_mode=G2D_REC_FILL_ITALIC_DISABLE;

   if (g2d_bitblt_data->src_key_mode==KAL_TRUE)
      g2d_control_data.src_key_mode=G2D_BITBLT_DEST_SRC_KEY_ENABLE;
   else
      g2d_control_data.src_key_mode=G2D_BITBLT_DEST_SRC_KEY_DISABLE;
   g2d_control_data.src_key_color=g2d_bitblt_data->src_key_color;
   for (i=0;i<g2d_bitblt_data->list_count;i++)
   {
      g2d_control_data.src_color_mode=g2d_bitblt_data->src_list[i].color_mode;
      g2d_control_data.src_base_address=g2d_bitblt_data->src_list[i].base_address;
      g2d_control_data.src_width=g2d_bitblt_data->src_list[i].width;
      g2d_control_data.src_height=g2d_bitblt_data->src_list[i].height;
      g2d_control_data.src_x=g2d_bitblt_data->src_list[i].x;
      g2d_control_data.src_y=g2d_bitblt_data->src_list[i].y;
      g2d_control_data.src_pitch=g2d_bitblt_data->src_list[i].pitch;
      g2d_sw_bitblt_operation(&g2d_control_data);
   }
}  /* g2d_bitblt1() */

void g2d_draw_arc1(kal_uint8 g2d_owner_id, g2d_circle_struct *g2d_circle_data)
{
   kal_uint8 draw_two_arc=0;
   kal_uint16 clip_y1,clip_y2;

   if (g2d_owner_id!=g2d_current_owner_id)
      return;

   if ((g2d_circle_data->start_angle<180) && (g2d_circle_data->end_angle>180))
      draw_two_arc=1;

   if (draw_two_arc==0)
   {
      if (g2d_circle_data->end_angle<=180)
      {
         if (g2d_circle_data->start_angle<90)
         {
            clip_y1=g2d_circle_data->circle_center_y-((g2d_circle_data->circle_radius * (cosine_table[g2d_circle_data->start_angle]+1))>>16);
            if (g2d_circle_data->end_angle<90)
               clip_y2=g2d_circle_data->circle_center_y-((g2d_circle_data->circle_radius * (cosine_table[g2d_circle_data->end_angle]+1))>>16);
            else
               clip_y2=g2d_circle_data->circle_center_y+((g2d_circle_data->circle_radius * (cosine_table[180-g2d_circle_data->end_angle]+1))>>16);
         }
         else
         {
            clip_y1=g2d_circle_data->circle_center_y+((g2d_circle_data->circle_radius * (cosine_table[180-g2d_circle_data->start_angle]+1))>>16);
            clip_y2=g2d_circle_data->circle_center_y+((g2d_circle_data->circle_radius * (cosine_table[180-g2d_circle_data->end_angle]+1))>>16);
         }
      }
      else
      {
         if (g2d_circle_data->start_angle<270)
         {
            clip_y2=g2d_circle_data->circle_center_y+((g2d_circle_data->circle_radius * (cosine_table[g2d_circle_data->start_angle-180]+1))>>16);
            if (g2d_circle_data->end_angle<270)
               clip_y1=g2d_circle_data->circle_center_y+((g2d_circle_data->circle_radius * (cosine_table[g2d_circle_data->end_angle-180]+1))>>16);
            else
               clip_y1=g2d_circle_data->circle_center_y-((g2d_circle_data->circle_radius * (cosine_table[360-g2d_circle_data->end_angle]+1))>>16);
         }
         else
         {
            clip_y1=g2d_circle_data->circle_center_y-((g2d_circle_data->circle_radius * (cosine_table[360-g2d_circle_data->end_angle]+1))>>16);
            clip_y2=g2d_circle_data->circle_center_y-((g2d_circle_data->circle_radius * (cosine_table[360-g2d_circle_data->start_angle]+1))>>16);
         }
      }
   }
   else
   {
      if (g2d_circle_data->start_angle<90)
         clip_y1=g2d_circle_data->circle_center_y-((g2d_circle_data->circle_radius * (cosine_table[g2d_circle_data->start_angle]+1))>>16);
      else
         clip_y1=g2d_circle_data->circle_center_y+((g2d_circle_data->circle_radius * (cosine_table[180-g2d_circle_data->start_angle]+1))>>16);

      if (g2d_circle_data->end_angle<270)
         clip_y2=g2d_circle_data->circle_center_y+((g2d_circle_data->circle_radius * (cosine_table[g2d_circle_data->end_angle-180]+1))>>16);
      else
         clip_y2=g2d_circle_data->circle_center_y-((g2d_circle_data->circle_radius * (cosine_table[360-g2d_circle_data->end_angle]+1))>>16);
   }

   if (draw_two_arc==0)
   {  /* draw arc 6 or arc 9 only */
      g2d_control_data.clip_start_x=0;
      g2d_control_data.clip_end_x=0x7FFF;
      g2d_control_data.clip_start_y=clip_y1;
      g2d_control_data.clip_end_y=clip_y2;
      if (g2d_circle_data->end_angle<=180)
         g2d_control_data.circle_drawing_arc = G2D_CIRCLE_ARC_1_4;
      else
         g2d_control_data.circle_drawing_arc = G2D_CIRCLE_ARC_2_3;
      g2d_sw_circle_drawing(&g2d_control_data);
   }
   else
   {  /* draw arc 6 and arc 9 */
      g2d_control_data.clip_start_x=0;
      g2d_control_data.clip_end_x=0x7FFF;
      g2d_control_data.clip_start_y=clip_y1;
      g2d_control_data.clip_end_y=0x7FFF;
      g2d_control_data.circle_drawing_arc = G2D_CIRCLE_ARC_1_4;
      g2d_sw_circle_drawing(&g2d_control_data);

      g2d_control_data.clip_start_y=clip_y2;
      g2d_control_data.circle_drawing_arc = G2D_CIRCLE_ARC_2_3;
      g2d_sw_circle_drawing(&g2d_control_data);
   }
}  /* g2d_draw_arc1() */

void g2d_draw_arc(kal_uint8 g2d_owner_id, g2d_circle_struct *g2d_circle_data)
{
   g2d_circle_struct g2d_arc_para;

   if (g2d_owner_id!=g2d_current_owner_id)
      return;

   if ((g2d_circle_data->start_angle>360) || (g2d_circle_data->end_angle>360))
      ASSERT(0);

   g2d_arc_para.circle_center_x=g2d_circle_data->circle_center_x;
   g2d_arc_para.circle_center_y=g2d_circle_data->circle_center_y;
   g2d_arc_para.circle_radius=g2d_circle_data->circle_radius;
   g2d_arc_para.start_angle=g2d_circle_data->start_angle;
   g2d_arc_para.end_angle=g2d_circle_data->end_angle;
   g2d_arc_para.circle_color=g2d_circle_data->circle_color;

   g2d_control_data.start_x=g2d_circle_data->circle_center_x;
   g2d_control_data.start_y=g2d_circle_data->circle_center_y;
   g2d_control_data.circle_radius=g2d_circle_data->circle_radius;
   g2d_control_data.pat_fg_color=g2d_circle_data->circle_color;

   if (g2d_circle_data->start_angle<g2d_circle_data->end_angle)
   {
      g2d_draw_arc1(g2d_owner_id,&g2d_arc_para);
   }
   else
   {
      g2d_arc_para.end_angle=360;
      g2d_draw_arc1(g2d_owner_id,&g2d_arc_para);
      g2d_arc_para.start_angle=0;
      g2d_arc_para.end_angle=g2d_circle_data->end_angle;;
      g2d_draw_arc1(g2d_owner_id,&g2d_arc_para);
   }
}  /* g2d_draw_arc() */

void g2d_draw_bezier_curve(kal_uint8 g2d_owner_id, g2d_bezier_curve_struct *g2d_bezier_data)
{
   if (g2d_owner_id!=g2d_current_owner_id)
      return;

   g2d_control_data.start_x=g2d_bezier_data->start_x;
   g2d_control_data.start_y=g2d_bezier_data->start_y;
   g2d_control_data.middle_x=g2d_bezier_data->middle_x;
   g2d_control_data.middle_y=g2d_bezier_data->middle_y;
   g2d_control_data.end_x=g2d_bezier_data->end_x;
   g2d_control_data.end_y=g2d_bezier_data->end_y;
   g2d_control_data.bezier_curve_divide_time=5;
   g2d_control_data.buffer_address=(kal_uint32)subdivided_buffer;
   g2d_control_data.pat_fg_color=g2d_bezier_data->line_color;
   g2d_sw_bezier_curve_drawing(&g2d_control_data);
}  /* g2d_draw_bezier_curve() */

void g2d_draw_line(kal_uint8 g2d_owner_id, g2d_line_struct *g2d_line_data)
{
   kal_uint16 i;

   if (g2d_line_data->antialias_mode==KAL_TRUE)
      g2d_control_data.line_anti_alias_mode=G2D_LINE_ANTI_ALIAS_ENABLE;
   else
      g2d_control_data.line_anti_alias_mode=G2D_LINE_ANTI_ALIAS_DISABLE;
   if (g2d_line_data->dotted_mode==KAL_TRUE)
      g2d_control_data.dotted_mode=G2D_LINE_DOTTED_MODE;
   else
      g2d_control_data.dotted_mode=G2D_LINE_LINE_MODE;
   g2d_control_data.pat_fg_color=g2d_line_data->line_color;
   for (i=0;i<g2d_line_data->line_count;i++)
   {
      g2d_control_data.start_x=*((short *) (g2d_line_data->line_end_coordinate+i*4));
      g2d_control_data.start_y=*((short *) (g2d_line_data->line_end_coordinate+i*4+1));
      g2d_control_data.end_x=*((short *) (g2d_line_data->line_end_coordinate+i*4+2));
      g2d_control_data.end_y=*((short *) (g2d_line_data->line_end_coordinate+i*4+3));

      g2d_sw_line_drawing(&g2d_control_data);
   }
}  /* g2d_draw_line()*/

void g2d_draw_polygon(kal_uint8 g2d_owner_id, g2d_polygon_struct *g2d_polygon_data)
{
   kal_uint16 i;

   if (g2d_owner_id!=g2d_current_owner_id)
      return;

   if (g2d_polygon_data->antialias_mode==KAL_TRUE)
      g2d_control_data.line_anti_alias_mode=G2D_LINE_ANTI_ALIAS_ENABLE;
   else
      g2d_control_data.line_anti_alias_mode=G2D_LINE_ANTI_ALIAS_DISABLE;
   if (g2d_polygon_data->dotted_mode==KAL_TRUE)
      g2d_control_data.dotted_mode=G2D_LINE_DOTTED_MODE;
   else
      g2d_control_data.dotted_mode=G2D_LINE_LINE_MODE;
   g2d_control_data.pat_fg_color=g2d_polygon_data->line_color;
   for (i=0;i<g2d_polygon_data->polygon_number-1;i++) //hjf
   {
      g2d_control_data.start_x=*((short *) (g2d_polygon_data->point_coordinate+i*2));
      g2d_control_data.start_y=*((short *) (g2d_polygon_data->point_coordinate+i*2+1));
      g2d_control_data.end_x=*((short *) (g2d_polygon_data->point_coordinate+i*2+2));
      g2d_control_data.end_y=*((short *) (g2d_polygon_data->point_coordinate+i*2+3));
      g2d_sw_line_drawing(&g2d_control_data);
   }
}  /* g2d_draw_polygon() */

void g2d_fill_polygon(kal_uint8 g2d_owner_id, g2d_polygon_fill_struct *g2d_fill_polygon_data)
{  /* fill polygon by triangle fill function */
   kal_uint8 i,triangle_number;
   short start_x,start_y,middle_x,middle_y,end_x,end_y;
   g2d_triangle_para_struct g2d_triangle_data;

   if (g2d_owner_id!=g2d_current_owner_id)
      return;

   if ((g2d_fill_polygon_data->point_number%3)!=0)
      ASSERT(0);
   triangle_number=g2d_fill_polygon_data->point_number/3;

   g2d_control_data.pat_fg_color=g2d_fill_polygon_data->fill_color;
   for (i=0;i<triangle_number;i++) //hjf
   {
      start_x=*((short *) (g2d_fill_polygon_data->point_coordinate+i*6));
      start_y=*((short *) (g2d_fill_polygon_data->point_coordinate+i*6+1));
      middle_x=*((short *) (g2d_fill_polygon_data->point_coordinate+i*6+2));
      middle_y=*((short *) (g2d_fill_polygon_data->point_coordinate+i*6+3));
      end_x=*((short *) (g2d_fill_polygon_data->point_coordinate+i*6+4));
      end_y=*((short *) (g2d_fill_polygon_data->point_coordinate+i*6+5));
      g2d_get_triangle_slope(start_x,start_y,middle_x,middle_y,end_x,end_y,&g2d_triangle_data);
      g2d_control_data.dest_x=g2d_triangle_data.first_x;
      g2d_control_data.dest_y=g2d_triangle_data.first_y;
      g2d_control_data.middle_y=g2d_triangle_data.middle_y;
      g2d_control_data.triangle_left_slope=g2d_triangle_data.slope1;
      g2d_control_data.triangle_right_slope=g2d_triangle_data.slope2;
      g2d_sw_triangle_fill(&g2d_control_data);
      if (g2d_triangle_data.two_triangle==KAL_TRUE)
      {
         g2d_control_data.dest_x=g2d_triangle_data.second_x;
         g2d_control_data.dest_y=g2d_triangle_data.second_y;
         g2d_control_data.middle_y=g2d_triangle_data.middle_y;
         g2d_control_data.triangle_left_slope=g2d_triangle_data.slope3;
         g2d_control_data.triangle_right_slope=g2d_triangle_data.slope4;
         g2d_sw_triangle_fill(&g2d_control_data);
      }
   }
}  /* g2d_fill_polygon() */

void g2d_fill_rectangle(kal_uint8 g2d_owner_id, g2d_rectangle_fill_struct *g2d_rec_fill_data)
{
   if (g2d_owner_id!=g2d_current_owner_id)
      return;

   if (g2d_rec_fill_data->tilt_mode==KAL_TRUE)
      g2d_control_data.italic_mode=G2D_REC_FILL_ITALIC_ENABLE;
   else
      g2d_control_data.italic_mode=G2D_REC_FILL_ITALIC_DISABLE;
   g2d_control_data.dest_x=g2d_rec_fill_data->start_x;
   g2d_control_data.dest_y=g2d_rec_fill_data->start_y;
   g2d_control_data.dest_width=g2d_rec_fill_data->width;
   g2d_control_data.dest_height=g2d_rec_fill_data->height;
   g2d_control_data.pat_fg_color=g2d_rec_fill_data->fill_color;
   if (g2d_rec_fill_data->gradient_fill_mode==KAL_TRUE)
   {
      g2d_control_data.color_gradient_mode=G2D_REC_FILL_COLOR_GRAD_ENABLE;
      g2d_control_data.alpha_gradient_x=g2d_rec_fill_data->delta_gradient[0];
      g2d_control_data.alpha_gradient_y=g2d_rec_fill_data->delta_gradient[1];
      g2d_control_data.red_gradient_x=g2d_rec_fill_data->delta_gradient[2];
      g2d_control_data.red_gradient_y=g2d_rec_fill_data->delta_gradient[3];
      g2d_control_data.green_gradient_x=g2d_rec_fill_data->delta_gradient[4];
      g2d_control_data.green_gradient_y=g2d_rec_fill_data->delta_gradient[5];
      g2d_control_data.blue_gradient_x=g2d_rec_fill_data->delta_gradient[6];
      g2d_control_data.blue_gradient_y=g2d_rec_fill_data->delta_gradient[7];
   }
   else
      g2d_control_data.color_gradient_mode=G2D_REC_FILL_COLOR_GRAD_DISABLE;
   g2d_sw_rectangle_fill(&g2d_control_data);
}  /* g2d_fill_rectangle() */

void g2d_draw_gradient_h_line(kal_uint8 g2d_owner_id, g2d_gradient_line_struct *g2d_h_line_data)
{
   kal_uint16 i;
   kal_uint32 address_offset;
   kal_uint8 bytes_per_pixel=0;

   if (g2d_owner_id!=g2d_current_owner_id)
      return;

   switch (g2d_dest_buff_data.color_mode)
   {
      case FIRE_DEST_COLOR_8BPP_LUT_DIS:
         bytes_per_pixel=1;
      break;
      case FIRE_DEST_COLOR_16BPP_RGB565:
      case FIRE_DEST_COLOR_16BPP_ARGB4444:
         bytes_per_pixel=2;
      break;
      case FIRE_DEST_COLOR_32BPP_ARGB8888:
         bytes_per_pixel=4;
      break;
      case FIRE_DEST_COLOR_24BPP_RGB888:
         bytes_per_pixel=3;
      break;
      default:
//       ASSERT(0);
      break;
   }
   for (i=0;i<g2d_h_line_data->line_number;i++)
   {
      if ((((*((short *) (g2d_h_line_data->line_start_coordinate+i*2+1))))>=0)&&
          (((*((short *) (g2d_h_line_data->line_start_coordinate+i*2))))>=0))
      {
         address_offset=(((kal_uint16)(*((short *) (g2d_h_line_data->line_start_coordinate+i*2+1))))*g2d_dest_buff_data.pitch+
                        ((kal_uint16)(*((short *) (g2d_h_line_data->line_start_coordinate+i*2)))))*bytes_per_pixel;

         g2d_control_data.dest_x=((kal_uint16)(*((short *) (g2d_h_line_data->line_start_coordinate+i*2))));
         g2d_control_data.dest_y=((kal_uint16)(*((short *) (g2d_h_line_data->line_start_coordinate+i*2+1))));
         g2d_control_data.dest_base_address=g2d_dest_buff_data.base_address+address_offset;
         g2d_control_data.pat_fg_color=g2d_h_line_data->line_color;
         g2d_control_data.alpha_gradient_x=g2d_h_line_data->delta_gardient[i*4];
         g2d_control_data.red_gradient_x=g2d_h_line_data->delta_gardient[i*4+1];
         g2d_control_data.green_gradient_x=g2d_h_line_data->delta_gardient[i*4+2];
         g2d_control_data.blue_gradient_x=g2d_h_line_data->delta_gardient[i*4+3];
         g2d_control_data.dest_width=g2d_h_line_data->line_width[i];
         g2d_sw_hline_gradient(&g2d_control_data);
      }
   }
}  /* g2d_draw_gradient_h_line() */

void g2d_copy_h_line(kal_uint8 g2d_owner_id, g2d_line_copy_struct *g2d_copy_h_line_data)
{
   kal_uint16 i;
   kal_uint32 address_offset;
   kal_uint8 bytes_per_pixel=0;

   if (g2d_owner_id!=g2d_current_owner_id)
      return;

   switch (g2d_dest_buff_data.color_mode)
   {
      case FIRE_DEST_COLOR_8BPP_LUT_DIS:
         bytes_per_pixel=1;
      break;
      case FIRE_DEST_COLOR_16BPP_RGB565:
      case FIRE_DEST_COLOR_16BPP_ARGB4444:
         bytes_per_pixel=2;
      break;
      case FIRE_DEST_COLOR_32BPP_ARGB8888:
         bytes_per_pixel=4;
      break;
      case FIRE_DEST_COLOR_24BPP_RGB888:
         bytes_per_pixel=3;
      break;
      default:
//       ASSERT(0);
      break;
   }
   g2d_control_data.src_color_mode=g2d_copy_h_line_data->src->color_mode;
   g2d_control_data.src_base_address=g2d_copy_h_line_data->src->base_address;
   g2d_control_data.src_width=(kal_uint16) g2d_copy_h_line_data->src->width;
   for (i=0;i<g2d_copy_h_line_data->line_number;i++)
   {
      if ((((*((short *) (g2d_copy_h_line_data->line_start_coordinate+i*2+1))))>=0)&&
          (((*((short *) (g2d_copy_h_line_data->line_start_coordinate+i*2))))>=0))
      {
      address_offset=(((kal_uint16)(*((short *) (g2d_copy_h_line_data->line_start_coordinate+i*2+1))))*g2d_dest_buff_data.pitch+
                     ((kal_uint16)(*((short *) (g2d_copy_h_line_data->line_start_coordinate+i*2)))))*bytes_per_pixel;
         g2d_control_data.dest_x=((kal_uint16)(*((short *) (g2d_copy_h_line_data->line_start_coordinate+i*2))));
         g2d_control_data.dest_y=((kal_uint16)(*((short *) (g2d_copy_h_line_data->line_start_coordinate+i*2+1))));
         g2d_control_data.dest_base_address=g2d_dest_buff_data.base_address+address_offset;
         g2d_control_data.dest_width=(kal_uint16) g2d_copy_h_line_data->line_width[i];
         g2d_control_data.buffer_address=(kal_uint32) g2d_copy_h_line_data->mask_address[i];
         g2d_sw_hline_copy(&g2d_control_data);
      }
   }
}  /* g2d_copy_h_line()*/

kal_uint32 rgb565_to_rgb888(kal_uint16 rgb565_data,kal_uint8 *r_data, kal_uint8 *g_data,
                            kal_uint8 *b_data)
{
   kal_uint32 rgb888_data;
   kal_uint8 src_data_r,src_data_g,src_data_b;

   src_data_r=(rgb565_data&0xf800)>>11;
   src_data_g=(rgb565_data&0x7e0)>>5;
   src_data_b=(rgb565_data&0x1f);

   if (src_data_r>=29)
      src_data_r = (src_data_r<<3)|0x7;
   else if (src_data_r>=25)
      src_data_r = (src_data_r<<3)|0x6;
   else if (src_data_r>=20)
      src_data_r = (src_data_r<<3)|0x5;
   else if (src_data_r>=16)
      src_data_r = (src_data_r<<3)|0x4;
   else if (src_data_r>=12)
      src_data_r = (src_data_r<<3)|0x3;
   else if (src_data_r>=7)
      src_data_r = (src_data_r<<3)|0x2;
   else if (src_data_r>=3)
      src_data_r = (src_data_r<<3)|0x1;
   else
      src_data_r = (src_data_r<<3);

   if (src_data_b>=29)
      src_data_b = (src_data_b<<3)|0x7;
   else if (src_data_b>=25)
      src_data_b = (src_data_b<<3)|0x6;
   else if (src_data_b>=20)
      src_data_b = (src_data_b<<3)|0x5;
   else if (src_data_b>=16)
      src_data_b = (src_data_b<<3)|0x4;
   else if (src_data_b>=12)
      src_data_b = (src_data_b<<3)|0x3;
   else if (src_data_b>=7)
      src_data_b = (src_data_b<<3)|0x2;
   else if (src_data_b>=3)
      src_data_b = (src_data_b<<3)|0x1;
   else
      src_data_b = (src_data_b<<3);

   if (src_data_g>=53)
      src_data_g = (src_data_g<<2)|0x3;
   else if (src_data_g>=32)
      src_data_g = (src_data_g<<2)|0x2;
   else if (src_data_g>=11)
      src_data_g = (src_data_g<<2)|0x1;
   else
      src_data_g = (src_data_g<<2);

   *r_data=src_data_r;
   *g_data=src_data_g;
   *b_data=src_data_b;

   rgb888_data=(src_data_r<<16)|(src_data_g<<8)|src_data_b;
   return rgb888_data;
}  /* rgb565_to_rgb888() */

void g2d_rgb565_to_rgb888(kal_uint16 rgb565_data,kal_uint32 *r_data, kal_uint32 *g_data,kal_uint32 *b_data)
{
   kal_uint8 src_data_r,src_data_g,src_data_b;

   src_data_r=(rgb565_data&0xf800)>>11;
   src_data_g=(rgb565_data&0x7e0)>>5;
   src_data_b=(rgb565_data&0x1f);

   if (src_data_r>=29)
      src_data_r = (src_data_r<<3)|0x7;
   else if (src_data_r>=25)
      src_data_r = (src_data_r<<3)|0x6;
   else if (src_data_r>=20)
      src_data_r = (src_data_r<<3)|0x5;
   else if (src_data_r>=16)
      src_data_r = (src_data_r<<3)|0x4;
   else if (src_data_r>=12)
      src_data_r = (src_data_r<<3)|0x3;
   else if (src_data_r>=7)
      src_data_r = (src_data_r<<3)|0x2;
   else if (src_data_r>=3)
      src_data_r = (src_data_r<<3)|0x1;
   else
      src_data_r = (src_data_r<<3);

   if (src_data_b>=29)
      src_data_b = (src_data_b<<3)|0x7;
   else if (src_data_b>=25)
      src_data_b = (src_data_b<<3)|0x6;
   else if (src_data_b>=20)
      src_data_b = (src_data_b<<3)|0x5;
   else if (src_data_b>=16)
      src_data_b = (src_data_b<<3)|0x4;
   else if (src_data_b>=12)
      src_data_b = (src_data_b<<3)|0x3;
   else if (src_data_b>=7)
      src_data_b = (src_data_b<<3)|0x2;
   else if (src_data_b>=3)
      src_data_b = (src_data_b<<3)|0x1;
   else
      src_data_b = (src_data_b<<3);

   if (src_data_g>=53)
      src_data_g = (src_data_g<<2)|0x3;
   else if (src_data_g>=32)
      src_data_g = (src_data_g<<2)|0x2;
   else if (src_data_g>=11)
      src_data_g = (src_data_g<<2)|0x1;
   else
      src_data_g = (src_data_g<<2);

   *r_data=src_data_r<<16;
   *g_data=src_data_g<<16;
   *b_data=src_data_b<<16;
}  /* g2d_rgb565_to_rgb888() */

kal_uint16 g2d_rgb888_to_rgb565(kal_uint32 r_data, kal_uint32 g_data,kal_uint32 b_data)
{
   kal_uint16 return_data;
   kal_uint16 red,green,blue;

   red=(kal_uint16) (r_data>>16);
   if (red>255)
      red=255;

   green=(kal_uint16) (g_data>>16);
   if (green>255)
      green=255;

   blue=(kal_uint16) (b_data>>16);
   if (blue>255)
      blue=255;

   return_data=((red & 0xF8)<<8)|((green&0xFC)<<3)|((blue&0xF8)>>3);

   return return_data;
}  /* g2d_rgb888_to_rgb565() */

kal_uint32 g2d_gradient(kal_uint8 direction, kal_uint8 type, kal_uint32 src_data)
{
   kal_uint32 gradient=0;
   int return_value;

   if (direction==0)
   {  /* x direction */
      switch (type)
      {
         case 0:  /* alpha */
//          gradient=(int) (g2d_control_data.alpha_gradient_x*(1<<16));
            gradient=(int) (g2d_control_data.alpha_gradient_x);
         break;
         case 1:  /* red */
//          gradient=(int) (g2d_control_data.red_gradient_x*(1<<16));
            gradient=(int) (g2d_control_data.red_gradient_x);
         break;
         case 2:  /* green */
//          gradient=(int) (g2d_control_data.green_gradient_x*(1<<16));
            gradient=(int) (g2d_control_data.green_gradient_x);
         break;
         case 3:  /* blue */
//          gradient=(int) (g2d_control_data.blue_gradient_x*(1<<16));
            gradient=(int) (g2d_control_data.blue_gradient_x);
         break;
      }
   }
   else
   {  /* y direction */
      switch (type)
      {
         case 0:  /* alpha */
//          gradient=(int) (g2d_control_data.alpha_gradient_y*(1<<16));
            gradient=(int) (g2d_control_data.alpha_gradient_y);
         break;
         case 1:  /* red */
//          gradient=(int) (g2d_control_data.red_gradient_y*(1<<16));
            gradient=(int) (g2d_control_data.red_gradient_y);
         break;
         case 2:  /* green */
//          gradient=(int) (g2d_control_data.green_gradient_y*(1<<16));
            gradient=(int) (g2d_control_data.green_gradient_y);
         break;
         case 3:  /* blue */
//          gradient=(int) (g2d_control_data.blue_gradient_y*(1<<16));
            gradient=(int) (g2d_control_data.blue_gradient_y);
         break;
      }
   }

   if (gradient & 0x1000000)
   {  /* negative */
      gradient |= 0xFF000000;
      return_value= src_data+gradient;
      if (return_value<0)
         return_value=0;
   }
   else
   {  /* positive */
      return_value= (src_data+(gradient&0xFFFFFF));
   }

   return (return_value);
}  /* g2d_gradient() */

void get_bitblt_data(kal_uint16 color_mode, kal_uint32 base_address, short offset_x, short offset_y,
                     kal_uint8 *alpha,kal_uint8 *red, kal_uint8 *green, kal_uint8 *blue,kal_uint16 pitch,
                     kal_uint32 *read_data)
{
   kal_uint16 *src_buff_ptr16;
   kal_uint8 *src_buff_ptr8;
   kal_uint32 *src_buff_ptr32;
   kal_uint8 src_data8;
   kal_uint16 src_data16;
   kal_uint32 src_data32;

   src_buff_ptr16=(kal_uint16 *) base_address;
   src_buff_ptr8=(kal_uint8 *)base_address;
   src_buff_ptr32=(kal_uint32 *)base_address;
   switch (color_mode)
   {
      case FIRE_DEST_COLOR_16BPP_RGB565:
      case FIRE_SRC_COLOR_16BPP_RGB565:
         src_data16=*(src_buff_ptr16+offset_y*pitch+offset_x);
         rgb565_to_rgb888(src_data16,red,green,blue);
         *read_data=(kal_uint32) src_data16;
         *alpha=0xFF;
      break;
      case FIRE_DEST_COLOR_16BPP_ARGB4444:
      case FIRE_SRC_COLOR_16BPP_ARGB4444:
         src_data16=*(src_buff_ptr16+offset_y*pitch+offset_x);
         *alpha=(src_data16 & 0xF000)>>12;
         *alpha |= (*alpha<<4);
         *red=(src_data16 & 0xF00)>>8;
         *red |= (*red<<4);
         *green=(src_data16 & 0xF0)>>4;
         *green |= (*green<<4);
         *blue=(src_data16 & 0xF);
         *blue |= (*blue<<4);
         *read_data=(kal_uint32) src_data16;
      break;
      case FIRE_DEST_COLOR_8BPP_LUT_DIS:
//    case FIRE_SRC_COLOR_8BPP_LUT_DIS:
         src_data8=*(src_buff_ptr8+offset_y*pitch+offset_x);
         *blue=src_data8;
         *read_data=(kal_uint32) src_data8;
      break;
      case FIRE_DEST_COLOR_24BPP_RGB888:
      case FIRE_SRC_COLOR_24BPP_RGB888:
         *alpha=0xFF;
         *red=*(src_buff_ptr8+(offset_y*pitch+offset_x)*3+2);
         *green=*(src_buff_ptr8+(offset_y*pitch+offset_x)*3+1);
         *blue=*(src_buff_ptr8+(offset_y*pitch+offset_x)*3);
         *read_data=((*red)<<16)|((*green)<<8)|(*blue);
      break;
      case FIRE_DEST_COLOR_32BPP_ARGB8888:
      case FIRE_SRC_COLOR_32BPP_ARGB8888:
         src_data32=*(src_buff_ptr32+offset_y*pitch+offset_x);
         *alpha=(src_data32&0xFF000000)>>24;
         *red=(src_data32&0xFF0000)>>16;
         *green=(src_data32&0xFF00)>>8;
         *blue=(src_data32&0xFF);
         *read_data=(kal_uint32) src_data32;
      break;
   }
}  /* get_bitblt_data() */

void alpha_bitbit_calculate(kal_uint8 src_alpha, kal_uint8 src_red,kal_uint8 src_green, kal_uint8 src_blue,
                            kal_uint8 *output_red, kal_uint8 *output_green, kal_uint8 *output_blue)
{
   kal_uint16 temp_r, temp_g, temp_b;

   temp_r=(kal_uint16)(src_alpha*src_red) + (kal_uint16)((0xFF-src_alpha)*(*output_red));
   *output_red=(kal_uint8) ((temp_r+(temp_r>>8)+0x80)>>8);
   temp_g=(kal_uint16)(src_alpha*src_green) + (kal_uint16)((0xFF-src_alpha)*(*output_green));
   *output_green=(kal_uint8) ((temp_g+(temp_g>>8)+0x80)>>8);
   temp_b=(kal_uint16)(src_alpha*src_blue) + (kal_uint16)((0xFF-src_alpha)*(*output_blue));
   *output_blue=(kal_uint8) ((temp_b+(temp_b>>8)+0x80)>>8);
}  /* alpha_bitbit_calculate() */

void rop_bitblt_calculate(kal_uint8 rop_type, kal_uint8 src_alpha, kal_uint8 src_red, kal_uint8 src_green, kal_uint8 src_blue,
                          kal_uint8 *output_alpha,kal_uint8 *output_red, kal_uint8 *output_green, kal_uint8 *output_blue)
{
   switch (rop_type)
   {
      case G2D_ROP_ALL_ZERO:
         *output_alpha=0;
         *output_red=0;
         *output_green=0;
         *output_blue=0;
      break;
      case G2D_ROP_INV_AFTER_SRC_OR_DEST:
         *output_alpha=~(src_alpha | *output_alpha);
         *output_red=~(src_red | *output_red);
         *output_green=~(src_green | *output_green);
         *output_blue=~(src_blue | *output_blue);
      break;
      case G2D_ROP_INV_SRC_AND_DEST:
         *output_alpha=(~src_alpha) & (*output_alpha);
         *output_red=(~src_red) & (*output_red);
         *output_green=(~src_green) & (*output_green);
         *output_blue=(~src_blue)& (*output_blue);
      break;
      case G2D_ROP_INV_SRC:
         *output_alpha=(~src_alpha);
         *output_red=(~src_red);
         *output_green=(~src_green);
         *output_blue=(~src_blue);
      break;
      case G2D_ROP_SRC_AND_INV_DEST:
         *output_alpha=(src_alpha) & (~(*output_alpha));
         *output_red=(src_red) & (~(*output_red));
         *output_green=(src_green) & (~(*output_green));
         *output_blue=(src_blue)& (~(*output_blue));
      break;
      case G2D_ROP_INV_DEST:
         *output_alpha=~(*output_alpha);
         *output_red=~(*output_red);
         *output_green=~(*output_green);
         *output_blue=~(*output_blue);
      break;
      case G2D_ROP_SRC_XOR_DEST:
         *output_alpha=((src_alpha) ^ (*output_alpha));
         *output_red=((src_red) ^ (*output_red));
         *output_green=((src_green) ^ (*output_green));
         *output_blue=((src_blue)^ (*output_blue));
      break;
      case G2D_ROP_INV_AFTER_SRC_AND_DEST:
         *output_alpha=~((src_alpha) & (*output_alpha));
         *output_red=~((src_red) & (*output_red));
         *output_green=~((src_green) & (*output_green));
         *output_blue=~((src_blue)& (*output_blue));
      break;
      case G2D_ROP_SRC_AND_DEST:
         *output_alpha=(src_alpha & *output_alpha);
         *output_red=(src_red & *output_red);
         *output_green=(src_green & *output_green);
         *output_blue=(src_blue & *output_blue);
      break;
      case G2D_ROP_INV_AFTER_SRC_XOR_DEST:
         *output_alpha=~((src_alpha) ^ (*output_alpha));
         *output_red=~((src_red) ^ (*output_red));
         *output_green=~((src_green) ^ (*output_green));
         *output_blue=~((src_blue) ^ (*output_blue));
      break;
      case G2D_ROP_INV_SRC_OR_DEST:
         *output_alpha=(~src_alpha) | (*output_alpha);
         *output_red=(~src_red) | (*output_red);
         *output_green=(~src_green) | (*output_green);
         *output_blue=(~src_blue)| (*output_blue);
      break;
      case G2D_ROP_SRC:
         *output_alpha=src_alpha ;
         *output_red=src_red ;
         *output_green=src_green;
         *output_blue=src_blue;
      break;
      case G2D_ROP_SRC_OR_INV_DEST:
         *output_alpha=(src_alpha) | (~(*output_alpha));
         *output_red=(src_red) | (~(*output_red));
         *output_green=(src_green) | (~(*output_green));
         *output_blue=(src_blue)| (~(*output_blue));
      break;
      case G2D_ROP_SRC_OR_DEST:
         *output_alpha=(src_alpha) | (*output_alpha);
         *output_red=(src_red) | (*output_red);
         *output_green=(src_green) | (*output_green);
         *output_blue=(src_blue)| (*output_blue);
      break;
      case G2D_ROP_ALL_ONE:
         *output_alpha=0xFF;
         *output_red=0xFF;
         *output_green=0xFF;
         *output_blue=0xFF;
      break;

   }
}  /* rop_bitblt_calculate() */

void g2d_sw_font_caching(g2d_parameter_struct *g2d_data)
{
   kal_uint16 font_bit,font_count=0;
   short x_pos,y_pos;
   short i,j;
   kal_uint16 *dest_buff_ptr16;
   kal_uint8 *dest_buff_ptr8,*font_data_ptr,font_data,font_bit_count;
   kal_uint32 *dest_buff_ptr32;
   kal_uint16 clip_start_x,clip_start_y,clip_end_x,clip_end_y;
   kal_uint8 fg_fill_data8=0,bg_fill_data8=0;
   kal_uint16 fg_fill_data16=0,bg_fill_data16=0;
   kal_uint32 fg_fill_data32=0,bg_fill_data32=0;
   kal_uint8 tilt_value;
   kal_uint8 tilt_index=0;

   clip_start_x=g2d_data->clip_start_x;
   clip_start_y=g2d_data->clip_start_y;
   clip_end_x=g2d_data->clip_end_x;
   clip_end_y=g2d_data->clip_end_y;

   dest_buff_ptr16=(kal_uint16 *)g2d_data->dest_base_address;
   dest_buff_ptr8=(kal_uint8 *)g2d_data->dest_base_address;
   dest_buff_ptr32=(kal_uint32 *)g2d_data->dest_base_address;
   fg_fill_data16=(kal_uint16) (g2d_data->pat_fg_color);
   bg_fill_data16=(kal_uint16) (g2d_data->pat_bg_color);
   fg_fill_data8=(kal_uint8) (g2d_data->pat_fg_color);
   bg_fill_data8=(kal_uint8) (g2d_data->pat_bg_color);
   fg_fill_data32=(kal_uint32) (g2d_data->pat_fg_color);
   bg_fill_data32=(kal_uint32) (g2d_data->pat_bg_color);

   font_count=0;
   x_pos=g2d_data->dest_x;
   y_pos=g2d_data->dest_y;
   font_data_ptr=(kal_uint8 *) g2d_data->src_base_address;
   font_data=*(font_data_ptr+font_count);
   font_bit_count=g2d_data->font_start_position;
   font_count++;

   if (g2d_data->font_order==G2D_FONT_ORDER_LSB_FIRST)
      font_data>>=font_bit_count;
   else
      font_data<<=font_bit_count;

   for (i=y_pos;i<(y_pos+g2d_data->dest_height);i++)
   {
      tilt_value=g2d_sw_tilt_value[(tilt_index&G2D_TILT_SIZE_MASK)];

      for (j=x_pos;j<(x_pos+g2d_data->dest_width);j++)
      {
         if (g2d_data->font_order==G2D_FONT_ORDER_LSB_FIRST)
            font_bit = font_data & 0x01;
         else
            font_bit = font_data & 0x80;
         if ((g2d_data->italic_mode==G2D_REC_FILL_ITALIC_DISABLE)&&
             (j>=0)&&(j>=clip_start_x)&&(j<=clip_end_x)&&(i>=0)&&(i>=clip_start_y)&&
             (i<=clip_end_y))
         {
            switch (g2d_data->dest_color_mode)
            {
               case FIRE_DEST_COLOR_16BPP_RGB565:
               case FIRE_DEST_COLOR_16BPP_ARGB4444:
                  if (font_bit)
                     *(dest_buff_ptr16+i*g2d_data->dest_pitch+j) = fg_fill_data16;
                  else if (g2d_data->font_background_mode==G2D_FONT_BACKGROUND_ENABLE)
                     *(dest_buff_ptr16+i*g2d_data->dest_pitch+j) = bg_fill_data16;
               break;
               case FIRE_DEST_COLOR_8BPP_LUT_DIS:
                  if (font_bit)
                     *(dest_buff_ptr8+i*g2d_data->dest_pitch+j) = fg_fill_data8;
                  else if (g2d_data->font_background_mode==G2D_FONT_BACKGROUND_ENABLE)
                     *(dest_buff_ptr8+i*g2d_data->dest_pitch+j) = bg_fill_data8;
               break;
               case FIRE_DEST_COLOR_24BPP_RGB888:
                  if (font_bit)
                  {
                     *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j)*3) = (kal_uint8)((fg_fill_data32)&0xFF);
                     *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j)*3+1) = (kal_uint8)(((fg_fill_data32)&0xFF00)>>8);
                     *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j)*3+2) = (kal_uint8)(((fg_fill_data32)&0xFF0000)>>16);
                  }
                  else if (g2d_data->font_background_mode==G2D_FONT_BACKGROUND_ENABLE)
                  {
                     *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j)*3) = (kal_uint8)((bg_fill_data32)&0xFF);
                     *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j)*3+1) = (kal_uint8)(((bg_fill_data32)&0xFF00)>>8);
                     *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j)*3+2) = (kal_uint8)(((bg_fill_data32)&0xFF0000)>>16);
                  }
               break;
               case FIRE_DEST_COLOR_32BPP_ARGB8888:
                  if (font_bit)
                     *(dest_buff_ptr32+i*g2d_data->dest_pitch+j) = fg_fill_data32;
                  else if (g2d_data->font_background_mode==G2D_FONT_BACKGROUND_ENABLE)
                     *(dest_buff_ptr32+i*g2d_data->dest_pitch+j) = bg_fill_data32;
               break;
            }
         }
         else if ((g2d_data->italic_mode==G2D_REC_FILL_ITALIC_ENABLE)&&
             ((j+tilt_value)>=0)&&((j+tilt_value)>=clip_start_x)&&((j+tilt_value)<=clip_end_x)
             &&(i>=0)&&(i>=clip_start_y)&&(i<=clip_end_y))
         {
            switch (g2d_data->dest_color_mode)
            {
               case FIRE_DEST_COLOR_16BPP_RGB565:
               case FIRE_DEST_COLOR_16BPP_ARGB4444:
                  if (font_bit)
                     *(dest_buff_ptr16+i*g2d_data->dest_pitch+j+tilt_value) = fg_fill_data16;
                  else if (g2d_data->font_background_mode==G2D_FONT_BACKGROUND_ENABLE)
                     *(dest_buff_ptr16+i*g2d_data->dest_pitch+j+tilt_value) = bg_fill_data16;
               break;
               case FIRE_DEST_COLOR_8BPP_LUT_DIS:
                  if (font_bit)
                     *(dest_buff_ptr8+i*g2d_data->dest_pitch+j+tilt_value) = fg_fill_data8;
                  else if (g2d_data->font_background_mode==G2D_FONT_BACKGROUND_ENABLE)
                     *(dest_buff_ptr8+i*g2d_data->dest_pitch+j+tilt_value) = bg_fill_data8;
               break;
               case FIRE_DEST_COLOR_24BPP_RGB888:
                  if (font_bit)
                  {
                     *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j+tilt_value)*3) = (kal_uint8)((fg_fill_data32)&0xFF);
                     *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j+tilt_value)*3+1) = (kal_uint8)(((fg_fill_data32)&0xFF00)>>8);
                     *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j+tilt_value)*3+2) = (kal_uint8)(((fg_fill_data32)&0xFF0000)>>16);
                  }
                  else if (g2d_data->font_background_mode==G2D_FONT_BACKGROUND_ENABLE)
                  {
                     *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j+tilt_value)*3) = (kal_uint8)((bg_fill_data32)&0xFF);
                     *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j+tilt_value)*3+1) = (kal_uint8)(((bg_fill_data32)&0xFF00)>>8);
                     *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j+tilt_value)*3+2) = (kal_uint8)(((bg_fill_data32)&0xFF0000)>>16);
                  }
               break;
               case FIRE_DEST_COLOR_32BPP_ARGB8888:
                  if (font_bit)
                     *(dest_buff_ptr32+i*g2d_data->dest_pitch+j+tilt_value) = fg_fill_data32;
                  else if (g2d_data->font_background_mode==G2D_FONT_BACKGROUND_ENABLE)
                     *(dest_buff_ptr32+i*g2d_data->dest_pitch+j+tilt_value) = bg_fill_data32;
               break;
            }
         }
         if (g2d_data->font_order==G2D_FONT_ORDER_LSB_FIRST)
            font_data>>=1;
         else
            font_data<<=1;
         font_bit_count++;
         if (font_bit_count==8)
         {  /* get next byte */
            font_data=*(font_data_ptr+font_count);
            font_bit_count=0;
            font_count++;
         }
      }
      tilt_index++;
   }
}  /* g2d_sw_font_caching() */

void g2d_sw_bitblt_operation(g2d_parameter_struct *g2d_data)
{
   short i,j;
   short dest_end_x,dest_end_y,src_end_x,src_end_y;
   kal_uint16 src_width,src_height;
   kal_uint16 *dest_buff_ptr16;
   kal_uint8 *dest_buff_ptr8;
   kal_uint32 *dest_buff_ptr32;
   kal_uint32 src_key_data;
   kal_uint16 clip_start_x,clip_start_y,clip_end_x,clip_end_y;
   kal_uint8 src_alpha,src_red,src_green,src_blue,dest_alpha,dest_red,dest_green,dest_blue;
   kal_uint8 tilt_value;
   kal_uint32 src_data32;
   kal_uint8 tilt_index=0;
   kal_uint16 src_x_index,src_y_index,src_x_offset,src_y_offset;

   clip_start_x=g2d_data->clip_start_x;
   clip_start_y=g2d_data->clip_start_y;
   clip_end_x=g2d_data->clip_end_x;
   clip_end_y=g2d_data->clip_end_y;

   dest_end_x=g2d_data->dest_width+g2d_data->dest_x;
   dest_end_y=g2d_data->dest_height+g2d_data->dest_y;
   src_end_x=g2d_data->src_width+g2d_data->src_x;
   src_end_y=g2d_data->src_height+g2d_data->src_y;

   switch (g2d_data->src_color_mode)
   {
      case FIRE_SRC_COLOR_8BPP_LUT_DIS:
         g2d_data->src_key_color &= 0xFF;
      break;
      case FIRE_SRC_COLOR_16BPP_RGB565:
      case FIRE_SRC_COLOR_16BPP_ARGB4444:
         g2d_data->src_key_color &= 0xFFFF;
      break;
      case FIRE_SRC_COLOR_32BPP_ARGB8888:
         g2d_data->src_key_color &= 0xFFFFFFFF;
      break;
      case FIRE_SRC_COLOR_24BPP_RGB888:
         g2d_data->src_key_color &= 0xFFFFFF;
      break;
   }
   src_key_data=g2d_data->src_key_color;

   switch (g2d_data->bitblt_mode)
   {
      case BITBLT_TRANSFORM_MIRROR_ROTATE_90:
      case BITBLT_TRANSFORM_ROTATE_90:
      case BITBLT_TRANSFORM_ROTATE_270:
      case BITBLT_TRANSFORM_MIRROR_ROTATE_270:
         src_width=g2d_data->src_height-g2d_data->src_y;
         src_height=g2d_data->src_width-g2d_data->src_x;
      break;
      default:
         src_width=g2d_data->src_width-g2d_data->src_x;
         src_height=g2d_data->src_height-g2d_data->src_y;
      break;
   }
   src_x_offset=g2d_data->src_x;
   src_y_offset=g2d_data->src_y;

   dest_buff_ptr16=(kal_uint16 *)g2d_data->dest_base_address;
   dest_buff_ptr8=(kal_uint8 *)g2d_data->dest_base_address;
   dest_buff_ptr32=(kal_uint32 *)g2d_data->dest_base_address;

   switch (g2d_data->bitblt_mode)
   {
      case BITBLT_TRANSFORM_MIRROR_ROTATE_90:
         src_y_index=src_y_offset;
         for (j=(dest_end_x-1);j>=g2d_data->dest_x;j--)
         {
            tilt_value=g2d_sw_tilt_value[(tilt_index&G2D_TILT_SIZE_MASK)];
            src_x_index=src_x_offset;
            if ((j>=0)&&(j>=clip_start_x)&&(j<=clip_end_x))
            {
               for (i=(dest_end_y-1);i>=g2d_data->dest_y;i--)
               {
                  if (((g2d_data->italic_mode==G2D_REC_FILL_ITALIC_DISABLE)&&
                      (i>=0)&&(i>=clip_start_y)&&(i<=clip_end_y))||
                      ((g2d_data->italic_mode==G2D_REC_FILL_ITALIC_ENABLE)&&
                      (((i+tilt_value)>=0)&&((i+tilt_value)>=clip_start_y)&&
                      ((i+tilt_value)<=clip_end_y))))
                  {
                     get_bitblt_data(g2d_data->src_color_mode, g2d_data->src_base_address,src_x_index,src_y_index,
                                     &src_alpha,&src_red,&src_green,&src_blue,g2d_data->src_pitch,&src_data32);

                     if (((g2d_data->src_key_mode==G2D_BITBLT_DEST_SRC_KEY_ENABLE)&&
                         (src_key_data!=src_data32))||
                         (g2d_data->src_key_mode==G2D_BITBLT_DEST_SRC_KEY_DISABLE))
                     {
                        switch (g2d_data->g2d_operation_mode)
                        {
                           case FIRE_G2D_BITBLT:
                              dest_alpha=src_alpha;
                              dest_red=src_red;
                              dest_green=src_green;
                              dest_blue=src_blue;
                           break;
                           case FIRE_G2D_ALPHA_BLENDING:
                              get_bitblt_data(g2d_data->dest_color_mode, g2d_data->dest_base_address,j,i,
                                              &dest_alpha,&dest_red,&dest_green,&dest_blue,g2d_data->dest_pitch,&src_data32);
                              if ((g2d_data->src_color_mode==FIRE_DEST_COLOR_16BPP_ARGB4444)||
                                  (g2d_data->src_color_mode==FIRE_DEST_COLOR_32BPP_ARGB8888))
                              {
                                 alpha_bitbit_calculate(src_alpha,src_red,src_green,src_blue,&dest_red,
                                                        &dest_green,&dest_blue);
                              }
                              else
                              {
                                 alpha_bitbit_calculate((kal_uint8)g2d_data->src_alpha,src_red,src_green,src_blue,&dest_red,
                                                        &dest_green,&dest_blue);
                              }
                              dest_alpha=0xFF;
                           break;
                           case FIRE_G2D_ROP_BITBLT:
                              get_bitblt_data(g2d_data->dest_color_mode, g2d_data->dest_base_address,j,i,
                                              &dest_alpha,&dest_red,&dest_green,&dest_blue,g2d_data->dest_pitch,&src_data32);
                              rop_bitblt_calculate(g2d_data->rop_mode,src_alpha,src_red,src_green,src_blue,&dest_alpha,&dest_red,&dest_green,&dest_blue);
                           break;
                        }
                        if (g2d_data->italic_mode==G2D_REC_FILL_ITALIC_DISABLE)
                        {
                           switch (g2d_data->dest_color_mode)
                           {
                              case FIRE_DEST_COLOR_16BPP_RGB565:
                                 *(dest_buff_ptr16+i*g2d_data->dest_pitch+j) = ((dest_red & 0xF8)<<8)|((dest_green&0xFC)<<3)|((dest_blue&0xF8)>>3);
                              break;
                              case FIRE_DEST_COLOR_16BPP_ARGB4444:
                                 if ((g2d_data->g2d_operation_mode==FIRE_G2D_ROP_BITBLT)||
                                     ((g2d_data->g2d_operation_mode==FIRE_G2D_BITBLT)&&
                                      ((g2d_data->src_color_mode==FIRE_SRC_COLOR_16BPP_ARGB4444)||
                                      (g2d_data->src_color_mode==FIRE_SRC_COLOR_32BPP_ARGB8888))))
                                    *(dest_buff_ptr16+i*g2d_data->dest_pitch+j) = ((dest_alpha&0xF0)<<8)|((dest_red & 0xF0)<<4)|(dest_green&0xF0)|((dest_blue&0xF0)>>4);
                                 else
                                    *(dest_buff_ptr16+i*g2d_data->dest_pitch+j) = 0xF000|((dest_red & 0xF0)<<4)|(dest_green&0xF0)|((dest_blue&0xF0)>>4);
                              break;
                              case FIRE_DEST_COLOR_8BPP_LUT_DIS:
                                 *(dest_buff_ptr8+i*g2d_data->dest_pitch+j) = dest_blue;
                              break;
                              case FIRE_DEST_COLOR_24BPP_RGB888:
                                 *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j)*3+2) = dest_red;
                                 *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j)*3+1) = dest_green;
                                 *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j)*3) = dest_blue;
                              break;
                              case FIRE_DEST_COLOR_32BPP_ARGB8888:
                                 if ((g2d_data->g2d_operation_mode==FIRE_G2D_ROP_BITBLT)||
                                     ((g2d_data->g2d_operation_mode==FIRE_G2D_BITBLT)&&
                                      ((g2d_data->src_color_mode==FIRE_SRC_COLOR_16BPP_ARGB4444)||
                                      (g2d_data->src_color_mode==FIRE_SRC_COLOR_32BPP_ARGB8888))))
                                    *(dest_buff_ptr32+(i*g2d_data->dest_pitch+j)) = (dest_alpha<<24)|(dest_red <<16)|(dest_green<<8)|dest_blue;
                                 else
                                    *(dest_buff_ptr32+(i*g2d_data->dest_pitch+j)) = 0xFF000000|(dest_red <<16)|(dest_green<<8)|dest_blue;
                              break;
                           }
                        }
                        else if (g2d_data->italic_mode==G2D_REC_FILL_ITALIC_ENABLE)
                        {
                           switch (g2d_data->dest_color_mode)
                           {
                              case FIRE_DEST_COLOR_16BPP_RGB565:
                                 *(dest_buff_ptr16+(i+tilt_value)*g2d_data->dest_pitch+j) = ((dest_red & 0xF8)<<8)|((dest_green&0xFC)<<3)|((dest_blue&0xF8)>>3);
                              break;
                              case FIRE_DEST_COLOR_16BPP_ARGB4444:
                                 if ((g2d_data->g2d_operation_mode==FIRE_G2D_ROP_BITBLT)||
                                     ((g2d_data->g2d_operation_mode==FIRE_G2D_BITBLT)&&
                                      ((g2d_data->src_color_mode==FIRE_SRC_COLOR_16BPP_ARGB4444)||
                                      (g2d_data->src_color_mode==FIRE_SRC_COLOR_32BPP_ARGB8888))))
                                    *(dest_buff_ptr16+(i+tilt_value)*g2d_data->dest_pitch+j) = ((dest_alpha&0xF0)<<8)|((dest_red & 0xF0)<<4)|(dest_green&0xF0)|((dest_blue&0xF0)>>4);
                                 else
                                    *(dest_buff_ptr16+(i+tilt_value)*g2d_data->dest_pitch+j) = 0xF000|((dest_red & 0xF0)<<4)|(dest_green&0xF0)|((dest_blue&0xF0)>>4);
                              break;
                              case FIRE_DEST_COLOR_8BPP_LUT_DIS:
                                 *(dest_buff_ptr8+(i+tilt_value)*g2d_data->dest_pitch+j) = dest_blue;
                              break;
                              case FIRE_DEST_COLOR_24BPP_RGB888:
                                 *(dest_buff_ptr8+((i+tilt_value)*g2d_data->dest_pitch+j)*3+2) = dest_red;
                                 *(dest_buff_ptr8+((i+tilt_value)*g2d_data->dest_pitch+j)*3+1) = dest_green;
                                 *(dest_buff_ptr8+((i+tilt_value)*g2d_data->dest_pitch+j)*3) = dest_blue;
                              break;
                              case FIRE_DEST_COLOR_32BPP_ARGB8888:
                                 if ((g2d_data->g2d_operation_mode==FIRE_G2D_ROP_BITBLT)||
                                     ((g2d_data->g2d_operation_mode==FIRE_G2D_BITBLT)&&
                                      ((g2d_data->src_color_mode==FIRE_SRC_COLOR_16BPP_ARGB4444)||
                                      (g2d_data->src_color_mode==FIRE_SRC_COLOR_32BPP_ARGB8888))))
                                    *(dest_buff_ptr32+((i+tilt_value)*g2d_data->dest_pitch+j)) = (dest_alpha<<24)|(dest_red <<16)|(dest_green<<8)|dest_blue;
                                 else
                                    *(dest_buff_ptr32+((i+tilt_value)*g2d_data->dest_pitch+j)) = 0xFF000000|(dest_red <<16)|(dest_green<<8)|dest_blue;
                              break;
                           }
                        }
                     }
                  }
                  src_x_index++;
                  if (src_x_index==src_end_x)
                     src_x_index=src_x_offset;
               }
            }
            src_y_index++;
            if (src_y_index==src_end_y)
               src_y_index=src_y_offset;
            tilt_index++;
         }
      break;
      case BITBLT_TRANSFORM_ROTATE_180:
         src_y_index=src_y_offset;
//       for (i=g2d_data->dest_y;i<dest_end_y;i++)
         for (i=(dest_end_y-1);i>=g2d_data->dest_y;i--)
         {
            tilt_value=g2d_sw_tilt_value[(tilt_index&G2D_TILT_SIZE_MASK)];
            src_x_index=src_x_offset;
            if ((i>=0)&&(i>=clip_start_y)&&(i<=clip_end_y))
            {
               for (j=(dest_end_x-1);j>=g2d_data->dest_x;j--)
               {
                  if (((g2d_data->italic_mode==G2D_REC_FILL_ITALIC_DISABLE)&&
                      (j>=0)&&(j>=clip_start_x)&&(j<=clip_end_x))||
                      ((g2d_data->italic_mode==G2D_REC_FILL_ITALIC_ENABLE)&&
                      (((j+tilt_value)>=0)&&((j+tilt_value)>=clip_start_x)&&
                      ((j+tilt_value)<=clip_end_x))))
                  {
                     get_bitblt_data(g2d_data->src_color_mode, g2d_data->src_base_address,src_x_index,src_y_index,
                                     &src_alpha,&src_red,&src_green,&src_blue,g2d_data->src_pitch,&src_data32);

                     if (((g2d_data->src_key_mode==G2D_BITBLT_DEST_SRC_KEY_ENABLE)&&
                         (src_key_data!=src_data32))||
                         (g2d_data->src_key_mode==G2D_BITBLT_DEST_SRC_KEY_DISABLE))
                     {
                        switch (g2d_data->g2d_operation_mode)
                        {
                           case FIRE_G2D_BITBLT:
                              dest_alpha=src_alpha;
                              dest_red=src_red;
                              dest_green=src_green;
                              dest_blue=src_blue;
                           break;
                           case FIRE_G2D_ALPHA_BLENDING:
                              get_bitblt_data(g2d_data->dest_color_mode, g2d_data->dest_base_address,j,i,
                                              &dest_alpha,&dest_red,&dest_green,&dest_blue,g2d_data->dest_pitch,&src_data32);
                              if ((g2d_data->src_color_mode==FIRE_DEST_COLOR_16BPP_ARGB4444)||
                                  (g2d_data->src_color_mode==FIRE_DEST_COLOR_32BPP_ARGB8888))
                              {
                                 alpha_bitbit_calculate(src_alpha,src_red,src_green,src_blue,&dest_red,
                                                        &dest_green,&dest_blue);
                              }
                              else
                              {
                                 alpha_bitbit_calculate((kal_uint8)g2d_data->src_alpha,src_red,src_green,src_blue,&dest_red,
                                                        &dest_green,&dest_blue);
                              }
                              dest_alpha=0xFF;
                           break;
                           case FIRE_G2D_ROP_BITBLT:
                              get_bitblt_data(g2d_data->dest_color_mode, g2d_data->dest_base_address,j,i,
                                              &dest_alpha,&dest_red,&dest_green,&dest_blue,g2d_data->dest_pitch,&src_data32);
                              rop_bitblt_calculate(g2d_data->rop_mode,src_alpha,src_red,src_green,src_blue,&dest_alpha,&dest_red,&dest_green,&dest_blue);
                           break;
                        }
                        if (g2d_data->italic_mode==G2D_REC_FILL_ITALIC_DISABLE)
                        {
                           switch (g2d_data->dest_color_mode)
                           {
                              case FIRE_DEST_COLOR_16BPP_RGB565:
                                 *(dest_buff_ptr16+i*g2d_data->dest_pitch+j) = ((dest_red & 0xF8)<<8)|((dest_green&0xFC)<<3)|((dest_blue&0xF8)>>3);
                              break;
                              case FIRE_DEST_COLOR_16BPP_ARGB4444:
                                 if ((g2d_data->g2d_operation_mode==FIRE_G2D_ROP_BITBLT)||
                                     ((g2d_data->g2d_operation_mode==FIRE_G2D_BITBLT)&&
                                      ((g2d_data->src_color_mode==FIRE_SRC_COLOR_16BPP_ARGB4444)||
                                      (g2d_data->src_color_mode==FIRE_SRC_COLOR_32BPP_ARGB8888))))
                                    *(dest_buff_ptr16+i*g2d_data->dest_pitch+j) = ((dest_alpha&0xF0)<<8)|((dest_red & 0xF0)<<4)|(dest_green&0xF0)|((dest_blue&0xF0)>>4);
                                 else
                                    *(dest_buff_ptr16+i*g2d_data->dest_pitch+j) = 0xF000|((dest_red & 0xF0)<<4)|(dest_green&0xF0)|((dest_blue&0xF0)>>4);
                              break;
                              case FIRE_DEST_COLOR_8BPP_LUT_DIS:
                                 *(dest_buff_ptr8+i*g2d_data->dest_pitch+j) = dest_blue;
                              break;
                              case FIRE_DEST_COLOR_24BPP_RGB888:
                                 *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j)*3+2) = dest_red;
                                 *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j)*3+1) = dest_green;
                                 *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j)*3) = dest_blue;
                              break;
                              case FIRE_DEST_COLOR_32BPP_ARGB8888:
                                 if ((g2d_data->g2d_operation_mode==FIRE_G2D_ROP_BITBLT)||
                                     ((g2d_data->g2d_operation_mode==FIRE_G2D_BITBLT)&&
                                      ((g2d_data->src_color_mode==FIRE_SRC_COLOR_16BPP_ARGB4444)||
                                      (g2d_data->src_color_mode==FIRE_SRC_COLOR_32BPP_ARGB8888))))
                                    *(dest_buff_ptr32+(i*g2d_data->dest_pitch+j)) = (dest_alpha<<24)|(dest_red <<16)|(dest_green<<8)|dest_blue;
                                 else
                                    *(dest_buff_ptr32+(i*g2d_data->dest_pitch+j)) = 0xFF000000|(dest_red <<16)|(dest_green<<8)|dest_blue;
                              break;
                           }
                        }
                        else if (g2d_data->italic_mode==G2D_REC_FILL_ITALIC_ENABLE)
                        {
                           switch (g2d_data->dest_color_mode)
                           {
                              case FIRE_DEST_COLOR_16BPP_RGB565:
                                 *(dest_buff_ptr16+i*g2d_data->dest_pitch+j+tilt_value) = ((dest_red & 0xF8)<<8)|((dest_green&0xFC)<<3)|((dest_blue&0xF8)>>3);
                              break;
                              case FIRE_DEST_COLOR_16BPP_ARGB4444:
                                 if ((g2d_data->g2d_operation_mode==FIRE_G2D_ROP_BITBLT)||
                                     ((g2d_data->g2d_operation_mode==FIRE_G2D_BITBLT)&&
                                      ((g2d_data->src_color_mode==FIRE_SRC_COLOR_16BPP_ARGB4444)||
                                      (g2d_data->src_color_mode==FIRE_SRC_COLOR_32BPP_ARGB8888))))
                                    *(dest_buff_ptr16+i*g2d_data->dest_pitch+j+tilt_value) = ((dest_alpha&0xF0)<<8)|((dest_red & 0xF0)<<4)|(dest_green&0xF0)|((dest_blue&0xF0)>>4);
                                 else
                                    *(dest_buff_ptr16+i*g2d_data->dest_pitch+j+tilt_value) = 0xF000|((dest_red & 0xF0)<<4)|(dest_green&0xF0)|((dest_blue&0xF0)>>4);
                              break;
                              case FIRE_DEST_COLOR_8BPP_LUT_DIS:
                                 *(dest_buff_ptr8+i*g2d_data->dest_pitch+j+tilt_value) = dest_blue;
                              break;
                              case FIRE_DEST_COLOR_24BPP_RGB888:
                                 *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j+tilt_value)*3+2) = dest_red;
                                 *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j+tilt_value)*3+1) = dest_green;
                                 *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j+tilt_value)*3) = dest_blue;
                              break;
                              case FIRE_DEST_COLOR_32BPP_ARGB8888:
                                 if ((g2d_data->g2d_operation_mode==FIRE_G2D_ROP_BITBLT)||
                                     ((g2d_data->g2d_operation_mode==FIRE_G2D_BITBLT)&&
                                      ((g2d_data->src_color_mode==FIRE_SRC_COLOR_16BPP_ARGB4444)||
                                      (g2d_data->src_color_mode==FIRE_SRC_COLOR_32BPP_ARGB8888))))
                                    *(dest_buff_ptr32+(i*g2d_data->dest_pitch+j+tilt_value)) = (dest_alpha<<24)|(dest_red <<16)|(dest_green<<8)|dest_blue;
                                 else
                                    *(dest_buff_ptr32+(i*g2d_data->dest_pitch+j+tilt_value)) = 0xFF000000|(dest_red <<16)|(dest_green<<8)|dest_blue;
                              break;
                           }
                        }
                     }
                  }
                  src_x_index++;
                  if (src_x_index==src_end_x)
                     src_x_index=src_x_offset;
               }
            }
            src_y_index++;
            if (src_y_index==src_end_y)
               src_y_index=src_y_offset;
            tilt_index++;
         }
      break;
      case BITBLT_TRANSFORM_ROTATE_90:
         src_y_index=src_y_offset;
         for (j=(dest_end_x-1);j>=g2d_data->dest_x;j--)
         {
            tilt_value=g2d_sw_tilt_value[(tilt_index&G2D_TILT_SIZE_MASK)];
            src_x_index=src_x_offset;
            if ((j>=0)&&(j>=clip_start_x)&&(j<=clip_end_x))
            {
               for (i=g2d_data->dest_y;i<dest_end_y;i++)
               {
                  if (((g2d_data->italic_mode==G2D_REC_FILL_ITALIC_DISABLE)&&
                      (i>=0)&&(i>=clip_start_y)&&(i<=clip_end_y))||
                      ((g2d_data->italic_mode==G2D_REC_FILL_ITALIC_ENABLE)&&
                      (((i+tilt_value)>=0)&&((i+tilt_value)>=clip_start_y)&&
                      ((i+tilt_value)<=clip_end_y))))
                  {
                     get_bitblt_data(g2d_data->src_color_mode, g2d_data->src_base_address,src_x_index,src_y_index,
                                     &src_alpha,&src_red,&src_green,&src_blue,g2d_data->src_pitch,&src_data32);

                     if (((g2d_data->src_key_mode==G2D_BITBLT_DEST_SRC_KEY_ENABLE)&&
                         (src_key_data!=src_data32))||
                         (g2d_data->src_key_mode==G2D_BITBLT_DEST_SRC_KEY_DISABLE))
                     {
                        switch (g2d_data->g2d_operation_mode)
                        {
                           case FIRE_G2D_BITBLT:
                              dest_alpha=src_alpha;
                              dest_red=src_red;
                              dest_green=src_green;
                              dest_blue=src_blue;
                           break;
                           case FIRE_G2D_ALPHA_BLENDING:
                              get_bitblt_data(g2d_data->dest_color_mode, g2d_data->dest_base_address,j,i,
                                              &dest_alpha,&dest_red,&dest_green,&dest_blue,g2d_data->dest_pitch,&src_data32);
                              if ((g2d_data->src_color_mode==FIRE_DEST_COLOR_16BPP_ARGB4444)||
                                  (g2d_data->src_color_mode==FIRE_DEST_COLOR_32BPP_ARGB8888))
                              {
                                 alpha_bitbit_calculate(src_alpha,src_red,src_green,src_blue,&dest_red,
                                                        &dest_green,&dest_blue);
                              }
                              else
                              {
                                 alpha_bitbit_calculate((kal_uint8)g2d_data->src_alpha,src_red,src_green,src_blue,&dest_red,
                                                        &dest_green,&dest_blue);
                              }
                              dest_alpha=0xFF;
                           break;
                           case FIRE_G2D_ROP_BITBLT:
                              get_bitblt_data(g2d_data->dest_color_mode, g2d_data->dest_base_address,j,i,
                                              &dest_alpha,&dest_red,&dest_green,&dest_blue,g2d_data->dest_pitch,&src_data32);
                              rop_bitblt_calculate(g2d_data->rop_mode,src_alpha,src_red,src_green,src_blue,&dest_alpha,&dest_red,&dest_green,&dest_blue);
                           break;
                        }
                        if (g2d_data->italic_mode==G2D_REC_FILL_ITALIC_DISABLE)
                        {
                           switch (g2d_data->dest_color_mode)
                           {
                              case FIRE_DEST_COLOR_16BPP_RGB565:
                                 *(dest_buff_ptr16+i*g2d_data->dest_pitch+j) = ((dest_red & 0xF8)<<8)|((dest_green&0xFC)<<3)|((dest_blue&0xF8)>>3);
                              break;
                              case FIRE_DEST_COLOR_16BPP_ARGB4444:
                                 if ((g2d_data->g2d_operation_mode==FIRE_G2D_ROP_BITBLT)||
                                     ((g2d_data->g2d_operation_mode==FIRE_G2D_BITBLT)&&
                                      ((g2d_data->src_color_mode==FIRE_SRC_COLOR_16BPP_ARGB4444)||
                                      (g2d_data->src_color_mode==FIRE_SRC_COLOR_32BPP_ARGB8888))))
                                    *(dest_buff_ptr16+i*g2d_data->dest_pitch+j) = ((dest_alpha&0xF0)<<8)|((dest_red & 0xF0)<<4)|(dest_green&0xF0)|((dest_blue&0xF0)>>4);
                                 else
                                    *(dest_buff_ptr16+i*g2d_data->dest_pitch+j) = 0xF000|((dest_red & 0xF0)<<4)|(dest_green&0xF0)|((dest_blue&0xF0)>>4);
                              break;
                              case FIRE_DEST_COLOR_8BPP_LUT_DIS:
                                 *(dest_buff_ptr8+i*g2d_data->dest_pitch+j) = dest_blue;
                              break;
                              case FIRE_DEST_COLOR_24BPP_RGB888:
                                 *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j)*3+2) = dest_red;
                                 *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j)*3+1) = dest_green;
                                 *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j)*3) = dest_blue;
                              break;
                              case FIRE_DEST_COLOR_32BPP_ARGB8888:
                                 if ((g2d_data->g2d_operation_mode==FIRE_G2D_ROP_BITBLT)||
                                     ((g2d_data->g2d_operation_mode==FIRE_G2D_BITBLT)&&
                                      ((g2d_data->src_color_mode==FIRE_SRC_COLOR_16BPP_ARGB4444)||
                                      (g2d_data->src_color_mode==FIRE_SRC_COLOR_32BPP_ARGB8888))))
                                    *(dest_buff_ptr32+(i*g2d_data->dest_pitch+j)) = (dest_alpha<<24)|(dest_red <<16)|(dest_green<<8)|dest_blue;
                                 else
                                    *(dest_buff_ptr32+(i*g2d_data->dest_pitch+j)) = 0xFF000000|(dest_red <<16)|(dest_green<<8)|dest_blue;
                              break;
                           }
                        }
                        else if (g2d_data->italic_mode==G2D_REC_FILL_ITALIC_ENABLE)
                        {
                           switch (g2d_data->dest_color_mode)
                           {
                              case FIRE_DEST_COLOR_16BPP_RGB565:
                                 *(dest_buff_ptr16+(i+tilt_value)*g2d_data->dest_pitch+j) = ((dest_red & 0xF8)<<8)|((dest_green&0xFC)<<3)|((dest_blue&0xF8)>>3);
                              break;
                              case FIRE_DEST_COLOR_16BPP_ARGB4444:
                                 if ((g2d_data->g2d_operation_mode==FIRE_G2D_ROP_BITBLT)||
                                     ((g2d_data->g2d_operation_mode==FIRE_G2D_BITBLT)&&
                                      ((g2d_data->src_color_mode==FIRE_SRC_COLOR_16BPP_ARGB4444)||
                                      (g2d_data->src_color_mode==FIRE_SRC_COLOR_32BPP_ARGB8888))))
                                    *(dest_buff_ptr16+(i+tilt_value)*g2d_data->dest_pitch+j) = ((dest_alpha&0xF0)<<8)|((dest_red & 0xF0)<<4)|(dest_green&0xF0)|((dest_blue&0xF0)>>4);
                                 else
                                    *(dest_buff_ptr16+(i+tilt_value)*g2d_data->dest_pitch+j) = 0xF000|((dest_red & 0xF0)<<4)|(dest_green&0xF0)|((dest_blue&0xF0)>>4);
                              break;
                              case FIRE_DEST_COLOR_8BPP_LUT_DIS:
                                 *(dest_buff_ptr8+(i+tilt_value)*g2d_data->dest_pitch+j) = dest_blue;
                              break;
                              case FIRE_DEST_COLOR_24BPP_RGB888:
                                 *(dest_buff_ptr8+((i+tilt_value)*g2d_data->dest_pitch+j)*3+2) = dest_red;
                                 *(dest_buff_ptr8+((i+tilt_value)*g2d_data->dest_pitch+j)*3+1) = dest_green;
                                 *(dest_buff_ptr8+((i+tilt_value)*g2d_data->dest_pitch+j)*3) = dest_blue;
                              break;
                              case FIRE_DEST_COLOR_32BPP_ARGB8888:
                                 if ((g2d_data->g2d_operation_mode==FIRE_G2D_ROP_BITBLT)||
                                     ((g2d_data->g2d_operation_mode==FIRE_G2D_BITBLT)&&
                                      ((g2d_data->src_color_mode==FIRE_SRC_COLOR_16BPP_ARGB4444)||
                                      (g2d_data->src_color_mode==FIRE_SRC_COLOR_32BPP_ARGB8888))))
                                    *(dest_buff_ptr32+((i+tilt_value)*g2d_data->dest_pitch+j)) = (dest_alpha<<24)|(dest_red <<16)|(dest_green<<8)|dest_blue;
                                 else
                                    *(dest_buff_ptr32+((i+tilt_value)*g2d_data->dest_pitch+j)) = 0xFF000000|(dest_red <<16)|(dest_green<<8)|dest_blue;
                              break;
                           }
                        }
                     }
                  }
                  src_x_index++;
                  if (src_x_index==src_end_x)
                     src_x_index=src_x_offset;
               }
            }
            src_y_index++;
            if (src_y_index==src_end_y)
               src_y_index=src_y_offset;
            tilt_index++;
         }
      break;
      case BITBLT_TRANSFORM_MIRROR_ROTATE_180:
         src_y_index=src_y_offset;
         for (i=(dest_end_y-1);i>=g2d_data->dest_y;i--)
         {
            tilt_value=g2d_sw_tilt_value[(tilt_index&G2D_TILT_SIZE_MASK)];
            src_x_index=src_x_offset;
            if ((i>=0)&&(i>=clip_start_y)&&(i<=clip_end_y))
            {
               for (j=g2d_data->dest_x;j<dest_end_x;j++)
               {
                  if (((g2d_data->italic_mode==G2D_REC_FILL_ITALIC_DISABLE)&&
                      (j>=0)&&(j>=clip_start_x)&&(j<=clip_end_x))||
                      ((g2d_data->italic_mode==G2D_REC_FILL_ITALIC_ENABLE)&&
                      (((j+tilt_value)>=0)&&((j+tilt_value)>=clip_start_x)&&
                      ((j+tilt_value)<=clip_end_x))))
                  {
                     get_bitblt_data(g2d_data->src_color_mode, g2d_data->src_base_address,src_x_index,src_y_index,
                                     &src_alpha,&src_red,&src_green,&src_blue,g2d_data->src_pitch,&src_data32);

                     if (((g2d_data->src_key_mode==G2D_BITBLT_DEST_SRC_KEY_ENABLE)&&
                         (src_key_data!=src_data32))||
                         (g2d_data->src_key_mode==G2D_BITBLT_DEST_SRC_KEY_DISABLE))
                     {
                        switch (g2d_data->g2d_operation_mode)
                        {
                           case FIRE_G2D_BITBLT:
                              dest_alpha=src_alpha;
                              dest_red=src_red;
                              dest_green=src_green;
                              dest_blue=src_blue;
                           break;
                           case FIRE_G2D_ALPHA_BLENDING:
                              get_bitblt_data(g2d_data->dest_color_mode, g2d_data->dest_base_address,j,i,
                                              &dest_alpha,&dest_red,&dest_green,&dest_blue,g2d_data->dest_pitch,&src_data32);
                              if ((g2d_data->src_color_mode==FIRE_DEST_COLOR_16BPP_ARGB4444)||
                                  (g2d_data->src_color_mode==FIRE_DEST_COLOR_32BPP_ARGB8888))
                              {
                                 alpha_bitbit_calculate(src_alpha,src_red,src_green,src_blue,&dest_red,
                                                        &dest_green,&dest_blue);
                              }
                              else
                              {
                                 alpha_bitbit_calculate((kal_uint8)g2d_data->src_alpha,src_red,src_green,src_blue,&dest_red,
                                                        &dest_green,&dest_blue);
                              }
                              dest_alpha=0xFF;
                           break;
                           case FIRE_G2D_ROP_BITBLT:
                              get_bitblt_data(g2d_data->dest_color_mode, g2d_data->dest_base_address,j,i,
                                              &dest_alpha,&dest_red,&dest_green,&dest_blue,g2d_data->dest_pitch,&src_data32);
                              rop_bitblt_calculate(g2d_data->rop_mode,src_alpha,src_red,src_green,src_blue,&dest_alpha,&dest_red,&dest_green,&dest_blue);
                           break;
                        }
                        if (g2d_data->italic_mode==G2D_REC_FILL_ITALIC_DISABLE)
                        {
                           switch (g2d_data->dest_color_mode)
                           {
                              case FIRE_DEST_COLOR_16BPP_RGB565:
                                 *(dest_buff_ptr16+i*g2d_data->dest_pitch+j) = ((dest_red & 0xF8)<<8)|((dest_green&0xFC)<<3)|((dest_blue&0xF8)>>3);
                              break;
                              case FIRE_DEST_COLOR_16BPP_ARGB4444:
                                 if ((g2d_data->g2d_operation_mode==FIRE_G2D_ROP_BITBLT)||
                                     ((g2d_data->g2d_operation_mode==FIRE_G2D_BITBLT)&&
                                      ((g2d_data->src_color_mode==FIRE_SRC_COLOR_16BPP_ARGB4444)||
                                      (g2d_data->src_color_mode==FIRE_SRC_COLOR_32BPP_ARGB8888))))
                                    *(dest_buff_ptr16+i*g2d_data->dest_pitch+j) = ((dest_alpha&0xF0)<<8)|((dest_red & 0xF0)<<4)|(dest_green&0xF0)|((dest_blue&0xF0)>>4);
                                 else
                                    *(dest_buff_ptr16+i*g2d_data->dest_pitch+j) = 0xF000|((dest_red & 0xF0)<<4)|(dest_green&0xF0)|((dest_blue&0xF0)>>4);
                              break;
                              case FIRE_DEST_COLOR_8BPP_LUT_DIS:
                                 *(dest_buff_ptr8+i*g2d_data->dest_pitch+j) = dest_blue;
                              break;
                              case FIRE_DEST_COLOR_24BPP_RGB888:
                                 *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j)*3+2) = dest_red;
                                 *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j)*3+1) = dest_green;
                                 *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j)*3) = dest_blue;
                              break;
                              case FIRE_DEST_COLOR_32BPP_ARGB8888:
                                 if ((g2d_data->g2d_operation_mode==FIRE_G2D_ROP_BITBLT)||
                                     ((g2d_data->g2d_operation_mode==FIRE_G2D_BITBLT)&&
                                      ((g2d_data->src_color_mode==FIRE_SRC_COLOR_16BPP_ARGB4444)||
                                      (g2d_data->src_color_mode==FIRE_SRC_COLOR_32BPP_ARGB8888))))
                                    *(dest_buff_ptr32+(i*g2d_data->dest_pitch+j)) = (dest_alpha<<24)|(dest_red <<16)|(dest_green<<8)|dest_blue;
                                 else
                                    *(dest_buff_ptr32+(i*g2d_data->dest_pitch+j)) = 0xFF000000|(dest_red <<16)|(dest_green<<8)|dest_blue;
                              break;
                           }
                        }
                        else if (g2d_data->italic_mode==G2D_REC_FILL_ITALIC_ENABLE)
                        {
                           switch (g2d_data->dest_color_mode)
                           {
                              case FIRE_DEST_COLOR_16BPP_RGB565:
                                 *(dest_buff_ptr16+i*g2d_data->dest_pitch+j+tilt_value) = ((dest_red & 0xF8)<<8)|((dest_green&0xFC)<<3)|((dest_blue&0xF8)>>3);
                              break;
                              case FIRE_DEST_COLOR_16BPP_ARGB4444:
                                 if ((g2d_data->g2d_operation_mode==FIRE_G2D_ROP_BITBLT)||
                                     ((g2d_data->g2d_operation_mode==FIRE_G2D_BITBLT)&&
                                      ((g2d_data->src_color_mode==FIRE_SRC_COLOR_16BPP_ARGB4444)||
                                      (g2d_data->src_color_mode==FIRE_SRC_COLOR_32BPP_ARGB8888))))
                                    *(dest_buff_ptr16+i*g2d_data->dest_pitch+j+tilt_value) = ((dest_alpha&0xF0)<<8)|((dest_red & 0xF0)<<4)|(dest_green&0xF0)|((dest_blue&0xF0)>>4);
                                 else
                                    *(dest_buff_ptr16+i*g2d_data->dest_pitch+j+tilt_value) = 0xF000|((dest_red & 0xF0)<<4)|(dest_green&0xF0)|((dest_blue&0xF0)>>4);
                              break;
                              case FIRE_DEST_COLOR_8BPP_LUT_DIS:
                                 *(dest_buff_ptr8+i*g2d_data->dest_pitch+j+tilt_value) = dest_blue;
                              break;
                              case FIRE_DEST_COLOR_24BPP_RGB888:
                                 *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j+tilt_value)*3+2) = dest_red;
                                 *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j+tilt_value)*3+1) = dest_green;
                                 *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j+tilt_value)*3) = dest_blue;
                              break;
                              case FIRE_DEST_COLOR_32BPP_ARGB8888:
                                 if ((g2d_data->g2d_operation_mode==FIRE_G2D_ROP_BITBLT)||
                                     ((g2d_data->g2d_operation_mode==FIRE_G2D_BITBLT)&&
                                      ((g2d_data->src_color_mode==FIRE_SRC_COLOR_16BPP_ARGB4444)||
                                      (g2d_data->src_color_mode==FIRE_SRC_COLOR_32BPP_ARGB8888))))
                                    *(dest_buff_ptr32+(i*g2d_data->dest_pitch+j+tilt_value)) = (dest_alpha<<24)|(dest_red <<16)|(dest_green<<8)|dest_blue;
                                 else
                                    *(dest_buff_ptr32+(i*g2d_data->dest_pitch+j+tilt_value)) = 0xFF000000|(dest_red <<16)|(dest_green<<8)|dest_blue;
                              break;
                           }
                        }
                     }
                  }
                  src_x_index++;
                  if (src_x_index==src_end_x)
                     src_x_index=src_x_offset;
               }
            }
            src_y_index++;
            if (src_y_index==src_end_y)
               src_y_index=src_y_offset;
            tilt_index++;
         }
      break;
      case BITBLT_TRANSFORM_ROTATE_270:
         src_y_index=src_y_offset;
         for (j=g2d_data->dest_x;j<dest_end_x;j++)
         {
            tilt_value=g2d_sw_tilt_value[(tilt_index&G2D_TILT_SIZE_MASK)];
            src_x_index=src_x_offset;
            if ((j>=0)&&(j>=clip_start_x)&&(j<=clip_end_x))
            {
               for (i=(dest_end_y-1);i>=g2d_data->dest_y;i--)
               {
                  if (((g2d_data->italic_mode==G2D_REC_FILL_ITALIC_DISABLE)&&
                      (i>=0)&&(i>=clip_start_y)&&(i<=clip_end_y))||
                      ((g2d_data->italic_mode==G2D_REC_FILL_ITALIC_ENABLE)&&
                      (((i+tilt_value)>=0)&&((i+tilt_value)>=clip_start_y)&&
                      ((i+tilt_value)<=clip_end_y))))
                  {
                     get_bitblt_data(g2d_data->src_color_mode, g2d_data->src_base_address,src_x_index,src_y_index,
                                     &src_alpha,&src_red,&src_green,&src_blue,g2d_data->src_pitch,&src_data32);

                     if (((g2d_data->src_key_mode==G2D_BITBLT_DEST_SRC_KEY_ENABLE)&&
                         (src_key_data!=src_data32))||
                         (g2d_data->src_key_mode==G2D_BITBLT_DEST_SRC_KEY_DISABLE))
                     {
                        switch (g2d_data->g2d_operation_mode)
                        {
                           case FIRE_G2D_BITBLT:
                              dest_alpha=src_alpha;
                              dest_red=src_red;
                              dest_green=src_green;
                              dest_blue=src_blue;
                           break;
                           case FIRE_G2D_ALPHA_BLENDING:
                              get_bitblt_data(g2d_data->dest_color_mode, g2d_data->dest_base_address,j,i,
                                              &dest_alpha,&dest_red,&dest_green,&dest_blue,g2d_data->dest_pitch,&src_data32);
                              if ((g2d_data->src_color_mode==FIRE_DEST_COLOR_16BPP_ARGB4444)||
                                  (g2d_data->src_color_mode==FIRE_DEST_COLOR_32BPP_ARGB8888))
                              {
                                 alpha_bitbit_calculate(src_alpha,src_red,src_green,src_blue,&dest_red,
                                                        &dest_green,&dest_blue);
                              }
                              else
                              {
                                 alpha_bitbit_calculate((kal_uint8)g2d_data->src_alpha,src_red,src_green,src_blue,&dest_red,
                                                        &dest_green,&dest_blue);
                              }
                              dest_alpha=0xFF;
                           break;
                           case FIRE_G2D_ROP_BITBLT:
                              get_bitblt_data(g2d_data->dest_color_mode, g2d_data->dest_base_address,j,i,
                                              &dest_alpha,&dest_red,&dest_green,&dest_blue,g2d_data->dest_pitch,&src_data32);
                              rop_bitblt_calculate(g2d_data->rop_mode,src_alpha,src_red,src_green,src_blue,&dest_alpha,&dest_red,&dest_green,&dest_blue);
                           break;
                        }
                        if (g2d_data->italic_mode==G2D_REC_FILL_ITALIC_DISABLE)
                        {
                           switch (g2d_data->dest_color_mode)
                           {
                              case FIRE_DEST_COLOR_16BPP_RGB565:
                                 *(dest_buff_ptr16+i*g2d_data->dest_pitch+j) = ((dest_red & 0xF8)<<8)|((dest_green&0xFC)<<3)|((dest_blue&0xF8)>>3);
                              break;
                              case FIRE_DEST_COLOR_16BPP_ARGB4444:
                                 if ((g2d_data->g2d_operation_mode==FIRE_G2D_ROP_BITBLT)||
                                     ((g2d_data->g2d_operation_mode==FIRE_G2D_BITBLT)&&
                                      ((g2d_data->src_color_mode==FIRE_SRC_COLOR_16BPP_ARGB4444)||
                                      (g2d_data->src_color_mode==FIRE_SRC_COLOR_32BPP_ARGB8888))))
                                    *(dest_buff_ptr16+i*g2d_data->dest_pitch+j) = ((dest_alpha&0xF0)<<8)|((dest_red & 0xF0)<<4)|(dest_green&0xF0)|((dest_blue&0xF0)>>4);
                                 else
                                    *(dest_buff_ptr16+i*g2d_data->dest_pitch+j) = 0xF000|((dest_red & 0xF0)<<4)|(dest_green&0xF0)|((dest_blue&0xF0)>>4);
                              break;
                              case FIRE_DEST_COLOR_8BPP_LUT_DIS:
                                 *(dest_buff_ptr8+i*g2d_data->dest_pitch+j) = dest_blue;
                              break;
                              case FIRE_DEST_COLOR_24BPP_RGB888:
                                 *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j)*3+2) = dest_red;
                                 *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j)*3+1) = dest_green;
                                 *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j)*3) = dest_blue;
                              break;
                              case FIRE_DEST_COLOR_32BPP_ARGB8888:
                                 if ((g2d_data->g2d_operation_mode==FIRE_G2D_ROP_BITBLT)||
                                     ((g2d_data->g2d_operation_mode==FIRE_G2D_BITBLT)&&
                                      ((g2d_data->src_color_mode==FIRE_SRC_COLOR_16BPP_ARGB4444)||
                                      (g2d_data->src_color_mode==FIRE_SRC_COLOR_32BPP_ARGB8888))))
                                    *(dest_buff_ptr32+(i*g2d_data->dest_pitch+j)) = (dest_alpha<<24)|(dest_red <<16)|(dest_green<<8)|dest_blue;
                                 else
                                    *(dest_buff_ptr32+(i*g2d_data->dest_pitch+j)) = 0xFF000000|(dest_red <<16)|(dest_green<<8)|dest_blue;
                              break;
                           }
                        }
                        else if (g2d_data->italic_mode==G2D_REC_FILL_ITALIC_ENABLE)
                        {
                           switch (g2d_data->dest_color_mode)
                           {
                              case FIRE_DEST_COLOR_16BPP_RGB565:
                                 *(dest_buff_ptr16+(i+tilt_value)*g2d_data->dest_pitch+j) = ((dest_red & 0xF8)<<8)|((dest_green&0xFC)<<3)|((dest_blue&0xF8)>>3);
                              break;
                              case FIRE_DEST_COLOR_16BPP_ARGB4444:
                                 if ((g2d_data->g2d_operation_mode==FIRE_G2D_ROP_BITBLT)||
                                     ((g2d_data->g2d_operation_mode==FIRE_G2D_BITBLT)&&
                                      ((g2d_data->src_color_mode==FIRE_SRC_COLOR_16BPP_ARGB4444)||
                                      (g2d_data->src_color_mode==FIRE_SRC_COLOR_32BPP_ARGB8888))))
                                    *(dest_buff_ptr16+(i+tilt_value)*g2d_data->dest_pitch+j) = ((dest_alpha&0xF0)<<8)|((dest_red & 0xF0)<<4)|(dest_green&0xF0)|((dest_blue&0xF0)>>4);
                                 else
                                    *(dest_buff_ptr16+(i+tilt_value)*g2d_data->dest_pitch+j) = 0xF000|((dest_red & 0xF0)<<4)|(dest_green&0xF0)|((dest_blue&0xF0)>>4);
                              break;
                              case FIRE_DEST_COLOR_8BPP_LUT_DIS:
                                 *(dest_buff_ptr8+(i+tilt_value)*g2d_data->dest_pitch+j) = dest_blue;
                              break;
                              case FIRE_DEST_COLOR_24BPP_RGB888:
                                 *(dest_buff_ptr8+((i+tilt_value)*g2d_data->dest_pitch+j)*3+2) = dest_red;
                                 *(dest_buff_ptr8+((i+tilt_value)*g2d_data->dest_pitch+j)*3+1) = dest_green;
                                 *(dest_buff_ptr8+((i+tilt_value)*g2d_data->dest_pitch+j)*3) = dest_blue;
                              break;
                              case FIRE_DEST_COLOR_32BPP_ARGB8888:
                                 if ((g2d_data->g2d_operation_mode==FIRE_G2D_ROP_BITBLT)||
                                     ((g2d_data->g2d_operation_mode==FIRE_G2D_BITBLT)&&
                                      ((g2d_data->src_color_mode==FIRE_SRC_COLOR_16BPP_ARGB4444)||
                                      (g2d_data->src_color_mode==FIRE_SRC_COLOR_32BPP_ARGB8888))))
                                    *(dest_buff_ptr32+((i+tilt_value)*g2d_data->dest_pitch+j)) = (dest_alpha<<24)|(dest_red <<16)|(dest_green<<8)|dest_blue;
                                 else
                                    *(dest_buff_ptr32+((i+tilt_value)*g2d_data->dest_pitch+j)) = 0xFF000000|(dest_red <<16)|(dest_green<<8)|dest_blue;
                              break;
                           }
                        }
                     }
                  }
                  src_x_index++;
                  if (src_x_index==src_end_x)
                     src_x_index=src_x_offset;
               }
            }
            src_y_index++;
            if (src_y_index==src_end_y)
               src_y_index=src_y_offset;
            tilt_index++;
         }
      break;
      case BITBLT_TRANSFORM_MIRROR:
         src_y_index=src_y_offset;
         for (i=g2d_data->dest_y;i<dest_end_y;i++)
         {
            tilt_value=g2d_sw_tilt_value[(tilt_index&G2D_TILT_SIZE_MASK)];
            src_x_index=src_x_offset;
            if ((i>=0)&&(i>=clip_start_y)&&(i<=clip_end_y))
            {
               for (j=(dest_end_x-1);j>=g2d_data->dest_x;j--)
               {
                  if (((g2d_data->italic_mode==G2D_REC_FILL_ITALIC_DISABLE)&&
                      (j>=0)&&(j>=clip_start_x)&&(j<=clip_end_x))||
                      ((g2d_data->italic_mode==G2D_REC_FILL_ITALIC_ENABLE)&&
                      (((j+tilt_value)>=0)&&((j+tilt_value)>=clip_start_x)&&
                      ((j+tilt_value)<=clip_end_x))))
                  {
                     get_bitblt_data(g2d_data->src_color_mode, g2d_data->src_base_address,src_x_index,src_y_index,
                                     &src_alpha,&src_red,&src_green,&src_blue,g2d_data->src_pitch,&src_data32);

                     if (((g2d_data->src_key_mode==G2D_BITBLT_DEST_SRC_KEY_ENABLE)&&
                         (src_key_data!=src_data32))||
                         (g2d_data->src_key_mode==G2D_BITBLT_DEST_SRC_KEY_DISABLE))
                     {
                        switch (g2d_data->g2d_operation_mode)
                        {
                           case FIRE_G2D_BITBLT:
                              dest_alpha=src_alpha;
                              dest_red=src_red;
                              dest_green=src_green;
                              dest_blue=src_blue;
                           break;
                           case FIRE_G2D_ALPHA_BLENDING:
                              get_bitblt_data(g2d_data->dest_color_mode, g2d_data->dest_base_address,j,i,
                                              &dest_alpha,&dest_red,&dest_green,&dest_blue,g2d_data->dest_pitch,&src_data32);
                              if ((g2d_data->src_color_mode==FIRE_DEST_COLOR_16BPP_ARGB4444)||
                                  (g2d_data->src_color_mode==FIRE_DEST_COLOR_32BPP_ARGB8888))
                              {
                                 alpha_bitbit_calculate(src_alpha,src_red,src_green,src_blue,&dest_red,
                                                        &dest_green,&dest_blue);
                              }
                              else
                              {
                                 alpha_bitbit_calculate((kal_uint8)g2d_data->src_alpha,src_red,src_green,src_blue,&dest_red,
                                                        &dest_green,&dest_blue);
                              }
                              dest_alpha=0xFF;
                           break;
                           case FIRE_G2D_ROP_BITBLT:
                              get_bitblt_data(g2d_data->dest_color_mode, g2d_data->dest_base_address,j,i,
                                              &dest_alpha,&dest_red,&dest_green,&dest_blue,g2d_data->dest_pitch,&src_data32);
                              rop_bitblt_calculate(g2d_data->rop_mode,src_alpha,src_red,src_green,src_blue,&dest_alpha,&dest_red,&dest_green,&dest_blue);
                           break;
                        }
                        if (g2d_data->italic_mode==G2D_REC_FILL_ITALIC_DISABLE)
                        {
                           switch (g2d_data->dest_color_mode)
                           {
                              case FIRE_DEST_COLOR_16BPP_RGB565:
                                 *(dest_buff_ptr16+i*g2d_data->dest_pitch+j) = ((dest_red & 0xF8)<<8)|((dest_green&0xFC)<<3)|((dest_blue&0xF8)>>3);
                              break;
                              case FIRE_DEST_COLOR_16BPP_ARGB4444:
                                 if ((g2d_data->g2d_operation_mode==FIRE_G2D_ROP_BITBLT)||
                                     ((g2d_data->g2d_operation_mode==FIRE_G2D_BITBLT)&&
                                      ((g2d_data->src_color_mode==FIRE_SRC_COLOR_16BPP_ARGB4444)||
                                      (g2d_data->src_color_mode==FIRE_SRC_COLOR_32BPP_ARGB8888))))
                                    *(dest_buff_ptr16+i*g2d_data->dest_pitch+j) = ((dest_alpha&0xF0)<<8)|((dest_red & 0xF0)<<4)|(dest_green&0xF0)|((dest_blue&0xF0)>>4);
                                 else
                                    *(dest_buff_ptr16+i*g2d_data->dest_pitch+j) = 0xF000|((dest_red & 0xF0)<<4)|(dest_green&0xF0)|((dest_blue&0xF0)>>4);
                              break;
                              case FIRE_DEST_COLOR_8BPP_LUT_DIS:
                                 *(dest_buff_ptr8+i*g2d_data->dest_pitch+j) = dest_blue;
                              break;
                              case FIRE_DEST_COLOR_24BPP_RGB888:
                                 *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j)*3+2) = dest_red;
                                 *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j)*3+1) = dest_green;
                                 *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j)*3) = dest_blue;
                              break;
                              case FIRE_DEST_COLOR_32BPP_ARGB8888:
                                 if ((g2d_data->g2d_operation_mode==FIRE_G2D_ROP_BITBLT)||
                                     ((g2d_data->g2d_operation_mode==FIRE_G2D_BITBLT)&&
                                      ((g2d_data->src_color_mode==FIRE_SRC_COLOR_16BPP_ARGB4444)||
                                      (g2d_data->src_color_mode==FIRE_SRC_COLOR_32BPP_ARGB8888))))
                                    *(dest_buff_ptr32+(i*g2d_data->dest_pitch+j)) = (dest_alpha<<24)|(dest_red <<16)|(dest_green<<8)|dest_blue;
                                 else
                                    *(dest_buff_ptr32+(i*g2d_data->dest_pitch+j)) = 0xFF000000|(dest_red <<16)|(dest_green<<8)|dest_blue;
                              break;
                           }
                        }
                        else if (g2d_data->italic_mode==G2D_REC_FILL_ITALIC_ENABLE)
                        {
                           switch (g2d_data->dest_color_mode)
                           {
                              case FIRE_DEST_COLOR_16BPP_RGB565:
                                 *(dest_buff_ptr16+i*g2d_data->dest_pitch+j+tilt_value) = ((dest_red & 0xF8)<<8)|((dest_green&0xFC)<<3)|((dest_blue&0xF8)>>3);
                              break;
                              case FIRE_DEST_COLOR_16BPP_ARGB4444:
                                 if ((g2d_data->g2d_operation_mode==FIRE_G2D_ROP_BITBLT)||
                                     ((g2d_data->g2d_operation_mode==FIRE_G2D_BITBLT)&&
                                      ((g2d_data->src_color_mode==FIRE_SRC_COLOR_16BPP_ARGB4444)||
                                      (g2d_data->src_color_mode==FIRE_SRC_COLOR_32BPP_ARGB8888))))
                                    *(dest_buff_ptr16+i*g2d_data->dest_pitch+j+tilt_value) = ((dest_alpha&0xF0)<<8)|((dest_red & 0xF0)<<4)|(dest_green&0xF0)|((dest_blue&0xF0)>>4);
                                 else
                                    *(dest_buff_ptr16+i*g2d_data->dest_pitch+j+tilt_value) = 0xF000|((dest_red & 0xF0)<<4)|(dest_green&0xF0)|((dest_blue&0xF0)>>4);
                              break;
                              case FIRE_DEST_COLOR_8BPP_LUT_DIS:
                                 *(dest_buff_ptr8+i*g2d_data->dest_pitch+j+tilt_value) = dest_blue;
                              break;
                              case FIRE_DEST_COLOR_24BPP_RGB888:
                                 *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j+tilt_value)*3+2) = dest_red;
                                 *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j+tilt_value)*3+1) = dest_green;
                                 *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j+tilt_value)*3) = dest_blue;
                              break;
                              case FIRE_DEST_COLOR_32BPP_ARGB8888:
                                 if ((g2d_data->g2d_operation_mode==FIRE_G2D_ROP_BITBLT)||
                                     ((g2d_data->g2d_operation_mode==FIRE_G2D_BITBLT)&&
                                      ((g2d_data->src_color_mode==FIRE_SRC_COLOR_16BPP_ARGB4444)||
                                      (g2d_data->src_color_mode==FIRE_SRC_COLOR_32BPP_ARGB8888))))
                                    *(dest_buff_ptr32+(i*g2d_data->dest_pitch+j+tilt_value)) = (dest_alpha<<24)|(dest_red <<16)|(dest_green<<8)|dest_blue;
                                 else
                                    *(dest_buff_ptr32+(i*g2d_data->dest_pitch+j+tilt_value)) = 0xFF000000|(dest_red <<16)|(dest_green<<8)|dest_blue;
                              break;
                           }
                        }
                     }
                  }
                  src_x_index++;
                  if (src_x_index==src_end_x)
                     src_x_index=src_x_offset;
               }
            }
            src_y_index++;
            if (src_y_index==src_end_y)
               src_y_index=src_y_offset;
            tilt_index++;
         }
      break;
      case BITBLT_TRANSFORM_MIRROR_ROTATE_270:
         src_y_index=src_y_offset;
         for (j=g2d_data->dest_x;j<dest_end_x;j++)
         {
            tilt_value=g2d_sw_tilt_value[(tilt_index&G2D_TILT_SIZE_MASK)];
            src_x_index=src_x_offset;
            if ((j>=0)&&(j>=clip_start_x)&&(j<=clip_end_x))
            {
               for (i=g2d_data->dest_y;i<dest_end_y;i++)
               {
                  if (((g2d_data->italic_mode==G2D_REC_FILL_ITALIC_DISABLE)&&
                      (i>=0)&&(i>=clip_start_y)&&(i<=clip_end_y))||
                      ((g2d_data->italic_mode==G2D_REC_FILL_ITALIC_ENABLE)&&
                      (((i+tilt_value)>=0)&&((i+tilt_value)>=clip_start_y)&&
                      ((i+tilt_value)<=clip_end_y))))
                  {
                     get_bitblt_data(g2d_data->src_color_mode, g2d_data->src_base_address,src_x_index,src_y_index,
                                     &src_alpha,&src_red,&src_green,&src_blue,g2d_data->src_pitch,&src_data32);

                     if (((g2d_data->src_key_mode==G2D_BITBLT_DEST_SRC_KEY_ENABLE)&&
                         (src_key_data!=src_data32))||
                         (g2d_data->src_key_mode==G2D_BITBLT_DEST_SRC_KEY_DISABLE))
                     {
                        switch (g2d_data->g2d_operation_mode)
                        {
                           case FIRE_G2D_BITBLT:
                              dest_alpha=src_alpha;
                              dest_red=src_red;
                              dest_green=src_green;
                              dest_blue=src_blue;
                           break;
                           case FIRE_G2D_ALPHA_BLENDING:
                              get_bitblt_data(g2d_data->dest_color_mode, g2d_data->dest_base_address,j,i,
                                              &dest_alpha,&dest_red,&dest_green,&dest_blue,g2d_data->dest_pitch,&src_data32);
                              if ((g2d_data->src_color_mode==FIRE_DEST_COLOR_16BPP_ARGB4444)||
                                  (g2d_data->src_color_mode==FIRE_DEST_COLOR_32BPP_ARGB8888))
                              {
                                 alpha_bitbit_calculate(src_alpha,src_red,src_green,src_blue,&dest_red,
                                                        &dest_green,&dest_blue);
                              }
                              else
                              {
                                 alpha_bitbit_calculate((kal_uint8)g2d_data->src_alpha,src_red,src_green,src_blue,&dest_red,
                                                        &dest_green,&dest_blue);
                              }
                              dest_alpha=0xFF;
                           break;
                           case FIRE_G2D_ROP_BITBLT:
                              get_bitblt_data(g2d_data->dest_color_mode, g2d_data->dest_base_address,j,i,
                                              &dest_alpha,&dest_red,&dest_green,&dest_blue,g2d_data->dest_pitch,&src_data32);
                              rop_bitblt_calculate(g2d_data->rop_mode,src_alpha,src_red,src_green,src_blue,&dest_alpha,&dest_red,&dest_green,&dest_blue);
                           break;
                        }
                        if (g2d_data->italic_mode==G2D_REC_FILL_ITALIC_DISABLE)
                        {
                           switch (g2d_data->dest_color_mode)
                           {
                              case FIRE_DEST_COLOR_16BPP_RGB565:
                                 *(dest_buff_ptr16+i*g2d_data->dest_pitch+j) = ((dest_red & 0xF8)<<8)|((dest_green&0xFC)<<3)|((dest_blue&0xF8)>>3);
                              break;
                              case FIRE_DEST_COLOR_16BPP_ARGB4444:
                                 if ((g2d_data->g2d_operation_mode==FIRE_G2D_ROP_BITBLT)||
                                     ((g2d_data->g2d_operation_mode==FIRE_G2D_BITBLT)&&
                                      ((g2d_data->src_color_mode==FIRE_SRC_COLOR_16BPP_ARGB4444)||
                                      (g2d_data->src_color_mode==FIRE_SRC_COLOR_32BPP_ARGB8888))))
                                    *(dest_buff_ptr16+i*g2d_data->dest_pitch+j) = ((dest_alpha&0xF0)<<8)|((dest_red & 0xF0)<<4)|(dest_green&0xF0)|((dest_blue&0xF0)>>4);
                                 else
                                    *(dest_buff_ptr16+i*g2d_data->dest_pitch+j) = 0xF000|((dest_red & 0xF0)<<4)|(dest_green&0xF0)|((dest_blue&0xF0)>>4);
                              break;
                              case FIRE_DEST_COLOR_8BPP_LUT_DIS:
                                 *(dest_buff_ptr8+i*g2d_data->dest_pitch+j) = dest_blue;
                              break;
                              case FIRE_DEST_COLOR_24BPP_RGB888:
                                 *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j)*3+2) = dest_red;
                                 *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j)*3+1) = dest_green;
                                 *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j)*3) = dest_blue;
                              break;
                              case FIRE_DEST_COLOR_32BPP_ARGB8888:
                                 if ((g2d_data->g2d_operation_mode==FIRE_G2D_ROP_BITBLT)||
                                     ((g2d_data->g2d_operation_mode==FIRE_G2D_BITBLT)&&
                                      ((g2d_data->src_color_mode==FIRE_SRC_COLOR_16BPP_ARGB4444)||
                                      (g2d_data->src_color_mode==FIRE_SRC_COLOR_32BPP_ARGB8888))))
                                    *(dest_buff_ptr32+(i*g2d_data->dest_pitch+j)) = (dest_alpha<<24)|(dest_red <<16)|(dest_green<<8)|dest_blue;
                                 else
                                    *(dest_buff_ptr32+(i*g2d_data->dest_pitch+j)) = 0xFF000000|(dest_red <<16)|(dest_green<<8)|dest_blue;
                              break;
                           }
                        }
                        else if (g2d_data->italic_mode==G2D_REC_FILL_ITALIC_ENABLE)
                        {
                           switch (g2d_data->dest_color_mode)
                           {
                              case FIRE_DEST_COLOR_16BPP_RGB565:
                                 *(dest_buff_ptr16+(i+tilt_value)*g2d_data->dest_pitch+j) = ((dest_red & 0xF8)<<8)|((dest_green&0xFC)<<3)|((dest_blue&0xF8)>>3);
                              break;
                              case FIRE_DEST_COLOR_16BPP_ARGB4444:
                                 if ((g2d_data->g2d_operation_mode==FIRE_G2D_ROP_BITBLT)||
                                     ((g2d_data->g2d_operation_mode==FIRE_G2D_BITBLT)&&
                                      ((g2d_data->src_color_mode==FIRE_SRC_COLOR_16BPP_ARGB4444)||
                                      (g2d_data->src_color_mode==FIRE_SRC_COLOR_32BPP_ARGB8888))))
                                    *(dest_buff_ptr16+(i+tilt_value)*g2d_data->dest_pitch+j) = ((dest_alpha&0xF0)<<8)|((dest_red & 0xF0)<<4)|(dest_green&0xF0)|((dest_blue&0xF0)>>4);
                                 else
                                    *(dest_buff_ptr16+(i+tilt_value)*g2d_data->dest_pitch+j) = 0xF000|((dest_red & 0xF0)<<4)|(dest_green&0xF0)|((dest_blue&0xF0)>>4);
                              break;
                              case FIRE_DEST_COLOR_8BPP_LUT_DIS:
                                 *(dest_buff_ptr8+(i+tilt_value)*g2d_data->dest_pitch+j) = dest_blue;
                              break;
                              case FIRE_DEST_COLOR_24BPP_RGB888:
                                 *(dest_buff_ptr8+((i+tilt_value)*g2d_data->dest_pitch+j)*3+2) = dest_red;
                                 *(dest_buff_ptr8+((i+tilt_value)*g2d_data->dest_pitch+j)*3+1) = dest_green;
                                 *(dest_buff_ptr8+((i+tilt_value)*g2d_data->dest_pitch+j)*3) = dest_blue;
                              break;
                              case FIRE_DEST_COLOR_32BPP_ARGB8888:
                                 if ((g2d_data->g2d_operation_mode==FIRE_G2D_ROP_BITBLT)||
                                     ((g2d_data->g2d_operation_mode==FIRE_G2D_BITBLT)&&
                                      ((g2d_data->src_color_mode==FIRE_SRC_COLOR_16BPP_ARGB4444)||
                                      (g2d_data->src_color_mode==FIRE_SRC_COLOR_32BPP_ARGB8888))))
                                    *(dest_buff_ptr32+((i+tilt_value)*g2d_data->dest_pitch+j)) = (dest_alpha<<24)|(dest_red <<16)|(dest_green<<8)|dest_blue;
                                 else
                                    *(dest_buff_ptr32+((i+tilt_value)*g2d_data->dest_pitch+j)) = 0xFF000000|(dest_red <<16)|(dest_green<<8)|dest_blue;
                              break;
                           }
                        }
                     }
                  }
                  src_x_index++;
                  if (src_x_index==src_end_x)
                     src_x_index=src_x_offset;
               }
            }
            src_y_index++;
            if (src_y_index==src_end_y)
               src_y_index=src_y_offset;
            tilt_index++;
         }
      break;
      case BITBLT_TRANSFORM_COPY:
         src_y_index=src_y_offset;
         for (i=g2d_data->dest_y;i<dest_end_y;i++)
         {
            tilt_value=g2d_sw_tilt_value[(tilt_index&G2D_TILT_SIZE_MASK)];
            src_x_index=src_x_offset;
            if ((i>=0)&&(i>=clip_start_y)&&(i<=clip_end_y))
            {
               for (j=g2d_data->dest_x;j<dest_end_x;j++)
               {
                  if (((g2d_data->italic_mode==G2D_REC_FILL_ITALIC_DISABLE)&&
                      (j>=0)&&(j>=clip_start_x)&&(j<=clip_end_x))||
                      ((g2d_data->italic_mode==G2D_REC_FILL_ITALIC_ENABLE)&&
                      (((j+tilt_value)>=0)&&((j+tilt_value)>=clip_start_x)&&
                      ((j+tilt_value)<=clip_end_x))))
                  {
                     get_bitblt_data(g2d_data->src_color_mode, g2d_data->src_base_address,src_x_index,src_y_index,
                                     &src_alpha,&src_red,&src_green,&src_blue,g2d_data->src_pitch,&src_data32);

                     if (((g2d_data->src_key_mode==G2D_BITBLT_DEST_SRC_KEY_ENABLE)&&
                         (src_key_data!=src_data32))||
                         (g2d_data->src_key_mode==G2D_BITBLT_DEST_SRC_KEY_DISABLE))
                     {
                        switch (g2d_data->g2d_operation_mode)
                        {
                           case FIRE_G2D_BITBLT:
                              dest_alpha=src_alpha;
                              dest_red=src_red;
                              dest_green=src_green;
                              dest_blue=src_blue;
                           break;
                           case FIRE_G2D_ALPHA_BLENDING:
                              get_bitblt_data(g2d_data->dest_color_mode, g2d_data->dest_base_address,j,i,
                                              &dest_alpha,&dest_red,&dest_green,&dest_blue,g2d_data->dest_pitch,&src_data32);
                              if ((g2d_data->src_color_mode==FIRE_DEST_COLOR_16BPP_ARGB4444)||
                                  (g2d_data->src_color_mode==FIRE_DEST_COLOR_32BPP_ARGB8888))
                              {
                                 alpha_bitbit_calculate(src_alpha,src_red,src_green,src_blue,&dest_red,
                                                        &dest_green,&dest_blue);
                              }
                              else
                              {
                                 alpha_bitbit_calculate((kal_uint8)g2d_data->src_alpha,src_red,src_green,src_blue,&dest_red,
                                                        &dest_green,&dest_blue);
                              }
                              dest_alpha=0xFF;
                           break;
                           case FIRE_G2D_ROP_BITBLT:
                              get_bitblt_data(g2d_data->dest_color_mode, g2d_data->dest_base_address,j,i,
                                              &dest_alpha,&dest_red,&dest_green,&dest_blue,g2d_data->dest_pitch,&src_data32);
                              rop_bitblt_calculate(g2d_data->rop_mode,src_alpha,src_red,src_green,src_blue,&dest_alpha,&dest_red,&dest_green,&dest_blue);
                           break;
                        }
                        if (g2d_data->italic_mode==G2D_REC_FILL_ITALIC_DISABLE)
                        {
                           switch (g2d_data->dest_color_mode)
                           {
                              case FIRE_DEST_COLOR_16BPP_RGB565:
                                 *(dest_buff_ptr16+i*g2d_data->dest_pitch+j) = ((dest_red & 0xF8)<<8)|((dest_green&0xFC)<<3)|((dest_blue&0xF8)>>3);
                              break;
                              case FIRE_DEST_COLOR_16BPP_ARGB4444:
                                 if ((g2d_data->g2d_operation_mode==FIRE_G2D_ROP_BITBLT)||
                                     ((g2d_data->g2d_operation_mode==FIRE_G2D_BITBLT)&&
                                      ((g2d_data->src_color_mode==FIRE_SRC_COLOR_16BPP_ARGB4444)||
                                      (g2d_data->src_color_mode==FIRE_SRC_COLOR_32BPP_ARGB8888))))
                                    *(dest_buff_ptr16+i*g2d_data->dest_pitch+j) = ((dest_alpha&0xF0)<<8)|((dest_red & 0xF0)<<4)|(dest_green&0xF0)|((dest_blue&0xF0)>>4);
                                 else
                                    *(dest_buff_ptr16+i*g2d_data->dest_pitch+j) = 0xF000|((dest_red & 0xF0)<<4)|(dest_green&0xF0)|((dest_blue&0xF0)>>4);
                              break;
                              case FIRE_DEST_COLOR_8BPP_LUT_DIS:
                                 *(dest_buff_ptr8+i*g2d_data->dest_pitch+j) = dest_blue;
                              break;
                              case FIRE_DEST_COLOR_24BPP_RGB888:
                                 *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j)*3+2) = dest_red;
                                 *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j)*3+1) = dest_green;
                                 *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j)*3) = dest_blue;
                              break;
                              case FIRE_DEST_COLOR_32BPP_ARGB8888:
                                 if ((g2d_data->g2d_operation_mode==FIRE_G2D_ROP_BITBLT)||
                                     ((g2d_data->g2d_operation_mode==FIRE_G2D_BITBLT)&&
                                      ((g2d_data->src_color_mode==FIRE_SRC_COLOR_16BPP_ARGB4444)||
                                      (g2d_data->src_color_mode==FIRE_SRC_COLOR_32BPP_ARGB8888))))
                                    *(dest_buff_ptr32+(i*g2d_data->dest_pitch+j)) = (dest_alpha<<24)|(dest_red <<16)|(dest_green<<8)|dest_blue;
                                 else
                                    *(dest_buff_ptr32+(i*g2d_data->dest_pitch+j)) = 0xFF000000|(dest_red <<16)|(dest_green<<8)|dest_blue;
                              break;
                           }
                        }
                        else if (g2d_data->italic_mode==G2D_REC_FILL_ITALIC_ENABLE)
                        {
                           switch (g2d_data->dest_color_mode)
                           {
                              case FIRE_DEST_COLOR_16BPP_RGB565:
                                 *(dest_buff_ptr16+i*g2d_data->dest_pitch+j+tilt_value) = ((dest_red & 0xF8)<<8)|((dest_green&0xFC)<<3)|((dest_blue&0xF8)>>3);
                              break;
                              case FIRE_DEST_COLOR_16BPP_ARGB4444:
                                 if ((g2d_data->g2d_operation_mode==FIRE_G2D_ROP_BITBLT)||
                                     ((g2d_data->g2d_operation_mode==FIRE_G2D_BITBLT)&&
                                      ((g2d_data->src_color_mode==FIRE_SRC_COLOR_16BPP_ARGB4444)||
                                      (g2d_data->src_color_mode==FIRE_SRC_COLOR_32BPP_ARGB8888))))
                                    *(dest_buff_ptr16+i*g2d_data->dest_pitch+j+tilt_value) = ((dest_alpha&0xF0)<<8)|((dest_red & 0xF0)<<4)|(dest_green&0xF0)|((dest_blue&0xF0)>>4);
                                 else
                                    *(dest_buff_ptr16+i*g2d_data->dest_pitch+j+tilt_value) = 0xF000|((dest_red & 0xF0)<<4)|(dest_green&0xF0)|((dest_blue&0xF0)>>4);
                              break;
                              case FIRE_DEST_COLOR_8BPP_LUT_DIS:
                                 *(dest_buff_ptr8+i*g2d_data->dest_pitch+j+tilt_value) = dest_blue;
                              break;
                              case FIRE_DEST_COLOR_24BPP_RGB888:
                                 *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j+tilt_value)*3+2) = dest_red;
                                 *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j+tilt_value)*3+1) = dest_green;
                                 *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j+tilt_value)*3) = dest_blue;
                              break;
                              case FIRE_DEST_COLOR_32BPP_ARGB8888:
                                 if ((g2d_data->g2d_operation_mode==FIRE_G2D_ROP_BITBLT)||
                                     ((g2d_data->g2d_operation_mode==FIRE_G2D_BITBLT)&&
                                      ((g2d_data->src_color_mode==FIRE_SRC_COLOR_16BPP_ARGB4444)||
                                      (g2d_data->src_color_mode==FIRE_SRC_COLOR_32BPP_ARGB8888))))
                                    *(dest_buff_ptr32+(i*g2d_data->dest_pitch+j+tilt_value)) = (dest_alpha<<24)|(dest_red <<16)|(dest_green<<8)|dest_blue;
                                 else
                                    *(dest_buff_ptr32+(i*g2d_data->dest_pitch+j+tilt_value)) = 0xFF000000|(dest_red <<16)|(dest_green<<8)|dest_blue;
                              break;
                           }
                        }
                     }
                  }
                  src_x_index++;
                  if (src_x_index==src_end_x)
                     src_x_index=src_x_offset;
               }
            }
            src_y_index++;
            if (src_y_index==src_end_y)
               src_y_index=src_y_offset;
            tilt_index++;
         }
      break;
   }
}  /* g2d_sw_bitblt_operation() */

void get_g2d_line_data(kal_uint16 color_mode,kal_uint32 base_address,short offset_x, short offset_y,
                       kal_uint8 *alpha,kal_uint8 *red, kal_uint8 *green, kal_uint8 *blue, kal_uint16 pitch)
{
   kal_uint16 *src_buff_ptr16,src_data16;
   kal_uint8 *src_buff_ptr8,src_data8;
   kal_uint32 *src_buff_ptr32,src_data32;

   if ((offset_x>=0)&&(offset_y>=0))
   {
      src_buff_ptr16=(kal_uint16 *)base_address;
      src_buff_ptr8=(kal_uint8 *)base_address;
      src_buff_ptr32=(kal_uint32 *)base_address;

      switch (color_mode)
      {
         case FIRE_DEST_COLOR_16BPP_RGB565:
            src_data16=*(src_buff_ptr16+offset_y*pitch+offset_x);
            rgb565_to_rgb888(src_data16,red,green,blue);
            *alpha=0xFF;
         break;
         case FIRE_DEST_COLOR_16BPP_ARGB4444:
            src_data16=*(src_buff_ptr16+offset_y*pitch+offset_x);
            *alpha=(src_data16 & 0xF000)>>12;
            *alpha |= (*alpha<<4);
            *red=(src_data16 & 0xF00)>>8;
            *red |= (*red<<4);
            *green=(src_data16 & 0xF0)>>4;
            *green |= (*green<<4);
            *blue=(src_data16 & 0xF);
            *blue |= (*blue<<4);
         break;
         case FIRE_DEST_COLOR_8BPP_LUT_DIS:
            src_data8=*(src_buff_ptr8+offset_y*pitch+offset_x);
            *blue=src_data8;
         break;
         case FIRE_DEST_COLOR_24BPP_RGB888:
            *alpha=0xFF;
            *red=*(src_buff_ptr8+(offset_y*pitch+offset_x)*3+2);
            *green=*(src_buff_ptr8+(offset_y*pitch+offset_x)*3+1);
            *blue=*(src_buff_ptr8+(offset_y*pitch+offset_x)*3);
         break;
         case FIRE_DEST_COLOR_32BPP_ARGB8888:
            src_data32=*(src_buff_ptr32+offset_y*pitch+offset_x);
            *alpha=(src_data32&0xFF000000)>>24;
            *red=(src_data32&0xFF0000)>>16;
            *green=(src_data32&0xFF00)>>8;
            *blue=(src_data32&0xFF);
         break;
      }
   }
   else
   {
      *alpha=0;
      *red=0;
      *green=0;
      *blue=0;
   }
}  /* get_g2d_line_data() */

void output_g2d_line_data(kal_uint32 base_address, short x_offset, short y_offset, kal_uint16 clip_start_x,
                          kal_uint16 clip_end_x,kal_uint16 clip_start_y,kal_uint16 clip_end_y,kal_uint16 color_mode,
                          kal_uint16 dest_pitch,kal_uint32 output_data)
{
   kal_uint16 *dest_buff_ptr16;
   kal_uint8 *dest_buff_ptr8;
   kal_uint32 *dest_buff_ptr32;

   dest_buff_ptr16=(kal_uint16 *)base_address;
   dest_buff_ptr8=(kal_uint8 *)base_address;
   dest_buff_ptr32=(kal_uint32 *)base_address;
   if ((x_offset>=0)&&(x_offset>=clip_start_x)&&(x_offset<=clip_end_x)&&
       (y_offset>=0)&&(y_offset>=clip_start_y)&&(y_offset<=clip_end_y))
   {
      switch (color_mode)
      {
         case FIRE_DEST_COLOR_16BPP_RGB565:
         case FIRE_DEST_COLOR_16BPP_ARGB4444:
            *(dest_buff_ptr16+y_offset*dest_pitch+x_offset) = (kal_uint16) output_data;
         break;
         case FIRE_DEST_COLOR_8BPP_LUT_DIS:
            *(dest_buff_ptr8+y_offset*dest_pitch+x_offset) = (kal_uint8) output_data;
         break;
         case FIRE_DEST_COLOR_24BPP_RGB888:
            *(dest_buff_ptr8+(y_offset*dest_pitch+x_offset)*3) = (output_data) & 0xFF;
            *(dest_buff_ptr8+(y_offset*dest_pitch+x_offset)*3+1) = ((output_data)&0xFF00)>>8;
            *(dest_buff_ptr8+(y_offset*dest_pitch+x_offset)*3+2) = ((output_data)&0xFF0000)>>16;
         break;
         case FIRE_DEST_COLOR_32BPP_ARGB8888:
            *(dest_buff_ptr32+(y_offset*dest_pitch+x_offset)) = output_data;
         break;
      }
   }
}  /* output_g2d_line_data() */

void line_alias_data(short d,kal_uint8 src_alpha,kal_uint8 src_red,kal_uint8 src_green,kal_uint8 src_blue,
                     kal_uint8 *dest_alpha,kal_uint8 *dest_red,kal_uint8 *dest_green,kal_uint8 *dest_blue,
                     kal_uint16 xy_sqrt,kal_uint16 color_mode,kal_uint32 *output_data)
{
   kal_uint8 alpha;
   kal_uint16 temp_alpha,temp_red,temp_green,temp_blue;

   if (d<(xy_sqrt>>3))
      alpha=245;
   else if (d<(xy_sqrt>>2))
      alpha=204;
   else if (d<((xy_sqrt>>2)+(xy_sqrt>>3)))
      alpha=179;
   else if (d<(xy_sqrt>>1))
      alpha=153;
   else if (d<((xy_sqrt>>1)+(xy_sqrt>>3)))
      alpha=128;
   else if (d<((xy_sqrt>>1)+(xy_sqrt>>2)))
      alpha=80;
   else if (d<xy_sqrt)
      alpha=26;
   else
      alpha=0;

   temp_alpha = alpha * src_alpha + (255-alpha)*(*dest_alpha);
   *dest_alpha = (temp_alpha + (temp_alpha>>8) + 0x80)>>8;

   temp_red = alpha * src_red + (255-alpha)*(*dest_red);
   *dest_red = (temp_red + (temp_red>>8) + 0x80)>>8;

   temp_green = alpha * src_green + (255-alpha)*(*dest_green);
   *dest_green = (temp_green + (temp_green>>8) + 0x80)>>8;

   temp_blue = alpha * src_blue + (255-alpha)*(*dest_blue);
   *dest_blue = (temp_blue + (temp_blue>>8) + 0x80)>>8;

   switch (color_mode)
   {
      case FIRE_DEST_COLOR_16BPP_RGB565:
         *output_data=((*dest_red & 0xF8)<<8)|((*dest_green&0xFC)<<3)|((*dest_blue&0xF8)>>3);
      break;
      case FIRE_DEST_COLOR_16BPP_ARGB4444:
         *output_data=0xF000|((*dest_red&0xF0)<<4)|(*dest_green&0xF0)|((*dest_blue&0xF0)>>4);
      break;
      case FIRE_DEST_COLOR_8BPP_LUT_DIS:
         *output_data=*dest_blue;
      break;
      case FIRE_DEST_COLOR_24BPP_RGB888:
         *output_data=(*dest_red<<16)|(*dest_green<<8)|(*dest_blue);
      break;
      case FIRE_DEST_COLOR_32BPP_ARGB8888:
         *output_data=0xFF000000|(*dest_red<<16)|(*dest_green<<8)|(*dest_blue);
      break;
   }
}  /* line_alias_data() */

void g2d_sw_circle_drawing(g2d_parameter_struct *g2d_data)
{
   kal_uint16 clip_start_x,clip_start_y,clip_end_x,clip_end_y;
   short center_x,center_y;
   short delta;
   short x_offset,y_offset;
   short x_index,y_index;
   kal_uint8 arc_mode;
   kal_uint16 radius;

   clip_start_x=g2d_data->clip_start_x;
   clip_start_y=g2d_data->clip_start_y;
   clip_end_x=g2d_data->clip_end_x;
   clip_end_y=g2d_data->clip_end_y;

   center_x=g2d_data->start_x;
   center_y=g2d_data->start_y;
   arc_mode=g2d_data->circle_drawing_arc;
   radius=g2d_data->circle_radius;
   delta=1-radius;
   x_index=0;
   y_index=radius;

   for (;x_index<=y_index;x_index++)
   {
      if (arc_mode&0x8)
      {
         x_offset=center_x+x_index;
         y_offset=center_y+y_index;
         output_g2d_line_data(g2d_data->dest_base_address,x_offset,y_offset,clip_start_x,clip_end_x,clip_start_y,
                              clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,g2d_data->pat_fg_color);
         x_offset=center_x+y_index;
         y_offset=center_y+x_index;
         output_g2d_line_data(g2d_data->dest_base_address,x_offset,y_offset,clip_start_x,clip_end_x,clip_start_y,
                              clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,g2d_data->pat_fg_color);
      }
      if (arc_mode & 0x1)
      {
         x_offset=center_x+x_index;
         y_offset=center_y-y_index;
         output_g2d_line_data(g2d_data->dest_base_address,x_offset,y_offset,clip_start_x,clip_end_x,clip_start_y,
                              clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,g2d_data->pat_fg_color);
         x_offset=center_x+y_index;
         y_offset=center_y-x_index;
         output_g2d_line_data(g2d_data->dest_base_address,x_offset,y_offset,clip_start_x,clip_end_x,clip_start_y,
                              clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,g2d_data->pat_fg_color);
      }
      if (arc_mode & 0x4)
      {
         x_offset=center_x-x_index;
         y_offset=center_y+y_index;
         output_g2d_line_data(g2d_data->dest_base_address,x_offset,y_offset,clip_start_x,clip_end_x,clip_start_y,
                              clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,g2d_data->pat_fg_color);
         x_offset=center_x-y_index;
         y_offset=center_y+x_index;
         output_g2d_line_data(g2d_data->dest_base_address,x_offset,y_offset,clip_start_x,clip_end_x,clip_start_y,
                              clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,g2d_data->pat_fg_color);
      }

      if (arc_mode & 0x2)
      {
         x_offset=center_x-x_index;
         y_offset=center_y-y_index;
         output_g2d_line_data(g2d_data->dest_base_address,x_offset,y_offset,clip_start_x,clip_end_x,clip_start_y,
                              clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,g2d_data->pat_fg_color);
         x_offset=center_x-y_index;
         y_offset=center_y-x_index;
         output_g2d_line_data(g2d_data->dest_base_address,x_offset,y_offset,clip_start_x,clip_end_x,clip_start_y,
                              clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,g2d_data->pat_fg_color);
      }

      if (delta<0)
      {
         delta+=((x_index<<1)+3);
      }
      else
      {
         delta+=(((x_index-y_index)<<1)+5);
         y_index--;
      }
   }
}  /* g2d_sw_circle_drawing() */

void g2d_sw_line_drawing(g2d_parameter_struct *g2d_data)
{
   kal_uint16 clip_start_x,clip_start_y,clip_end_x,clip_end_y;
   kal_uint16 abs_delta_x,abs_delta_y;
   kal_uint8 line_direction=0;
   kal_uint8 dotted_line_toggle=1;
   short start_x,start_y,end_x,end_y;
   short x_index,y_index;
   short delta;
   short delta_x,delta_y;
   kal_uint16 xy_sqrt=0;
   short d_current,d_above,d_below;
   kal_uint8 current_alpha,current_red,current_green,current_blue;
   kal_uint8 fg_alpha=0,fg_red,fg_green,fg_blue;
   kal_uint8 output_alpha,output_red,output_green,output_blue;
   kal_uint32 output_data;
   double temp_data1;
   kal_uint32 temp_data;

   clip_start_x=g2d_data->clip_start_x;
   clip_start_y=g2d_data->clip_start_y;
   clip_end_x=g2d_data->clip_end_x;
   clip_end_y=g2d_data->clip_end_y;

   switch (g2d_data->dest_color_mode)
   {
      case FIRE_DEST_COLOR_16BPP_RGB565:
         rgb565_to_rgb888((kal_uint16)g2d_data->pat_fg_color,&fg_red,&fg_green,&fg_blue);
      break;
      case FIRE_DEST_COLOR_16BPP_ARGB4444:
         fg_alpha=((g2d_data->pat_fg_color&0xF000)>>12);
         fg_alpha|=(fg_alpha<<4);
         fg_red=((g2d_data->pat_fg_color&0xF00)>>8);
         fg_red|=(fg_red<<4);
         fg_green=((g2d_data->pat_fg_color&0xF0)>>4);
         fg_green|=(fg_green<<4);
         fg_blue=(g2d_data->pat_fg_color&0xF);
         fg_blue|=(fg_blue<<4);
      break;
      case FIRE_DEST_COLOR_8BPP_LUT_DIS:
         fg_blue=(g2d_data->pat_fg_color&0xFF);
      break;
      case FIRE_DEST_COLOR_24BPP_RGB888:
         fg_red=(g2d_data->pat_fg_color&0xFF0000)>>16;
         fg_green=(g2d_data->pat_fg_color&0xFF00)>>8;
         fg_blue=(g2d_data->pat_fg_color&0xFF);
      break;
      case FIRE_DEST_COLOR_32BPP_ARGB8888:
         fg_alpha=(g2d_data->pat_fg_color&0xFF000000)>>24;
         fg_red=(g2d_data->pat_fg_color&0xFF0000)>>16;
         fg_green=(g2d_data->pat_fg_color&0xFF00)>>8;
         fg_blue=(g2d_data->pat_fg_color&0xFF);
      break;
   }
   current_alpha=fg_alpha;
   current_red=fg_red;
   current_green=fg_green;
   current_blue=fg_blue;

   if (g2d_data->start_x>g2d_data->end_x)
      abs_delta_x=g2d_data->start_x-g2d_data->end_x;
   else
      abs_delta_x=g2d_data->end_x-g2d_data->start_x;

   if (g2d_data->start_y>g2d_data->end_y)
      abs_delta_y=g2d_data->start_y-g2d_data->end_y;
   else
      abs_delta_y=g2d_data->end_y-g2d_data->start_y;

   start_x=g2d_data->start_x;
   start_y=g2d_data->start_y;
   end_x=g2d_data->end_x;
   end_y=g2d_data->end_y;

   if (abs_delta_x<abs_delta_y)
   {  /* y major */  /* swap=1 */
      if ((g2d_data->start_x<=g2d_data->end_x) &&
          (g2d_data->start_y<=g2d_data->end_y))
      {
         line_direction=1;
      }
      else if ((g2d_data->start_x>=g2d_data->end_x) &&
               (g2d_data->start_y>=g2d_data->end_y))
      {
         line_direction=2;
      }
      else if ((g2d_data->start_x<=g2d_data->end_x) &&
               (g2d_data->start_y>=g2d_data->end_y))
      {
         line_direction=3;
      }
      else if ((g2d_data->start_x>=g2d_data->end_x) &&
               (g2d_data->start_y<=g2d_data->end_y))
      {
         line_direction=4;
      }
   }
   else
   {  /* x major */  /* swap = 0 */
      if ((g2d_data->start_x>=g2d_data->end_x) &&
          (g2d_data->start_y<=g2d_data->end_y))
      {
         line_direction=5;
      }
      else if ((g2d_data->start_x<=g2d_data->end_x) &&
               (g2d_data->start_y>=g2d_data->end_y))
      {
         line_direction=6;
      }
      else if ((g2d_data->start_x<=g2d_data->end_x) &&
               (g2d_data->start_y<=g2d_data->end_y))
      {
         line_direction=7;
      }
      else if ((g2d_data->start_x>=g2d_data->end_x) &&
               (g2d_data->start_y>=g2d_data->end_y))
      {
         line_direction=8;
      }
   }

   if (g2d_data->dest_color_mode==FIRE_DEST_COLOR_32BPP_ARGB8888)
   {
      output_g2d_line_data(g2d_data->dest_base_address,start_x,start_y,clip_start_x,clip_end_x,clip_start_y,
                           clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,(g2d_data->pat_fg_color|0xFF000000));
      if (line_direction<=4)
      {
         output_g2d_line_data(g2d_data->dest_base_address,(short)(start_x+1),start_y,clip_start_x,clip_end_x,clip_start_y,
                              clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,0xFF000000);
         output_g2d_line_data(g2d_data->dest_base_address,(short)(start_x-1),start_y,clip_start_x,clip_end_x,clip_start_y,
                              clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,0xFF000000);

      }
      else
      {
         output_g2d_line_data(g2d_data->dest_base_address,start_x,(short)(start_y+1),clip_start_x,clip_end_x,clip_start_y,
                              clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,0xFF000000);
         output_g2d_line_data(g2d_data->dest_base_address,start_x,(short)(start_y-1),clip_start_x,clip_end_x,clip_start_y,
                              clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,0xFF000000);
      }
   }
   else if (g2d_data->dest_color_mode==FIRE_DEST_COLOR_16BPP_ARGB4444)
   {
      output_g2d_line_data(g2d_data->dest_base_address,start_x,start_y,clip_start_x,clip_end_x,clip_start_y,
                           clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,(g2d_data->pat_fg_color|0xF000));
      if (line_direction<=4)
      {
         output_g2d_line_data(g2d_data->dest_base_address,(short)(start_x+1),start_y,clip_start_x,clip_end_x,clip_start_y,
                              clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,0xF000);
         output_g2d_line_data(g2d_data->dest_base_address,(short)(start_x-1),start_y,clip_start_x,clip_end_x,clip_start_y,
                              clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,0xF000);

      }
      else
      {
         output_g2d_line_data(g2d_data->dest_base_address,start_x,(short)(start_y+1),clip_start_x,clip_end_x,clip_start_y,
                              clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,0xF000);
         output_g2d_line_data(g2d_data->dest_base_address,start_x,(short)(start_y-1),clip_start_x,clip_end_x,clip_start_y,
                              clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,0xF000);
      }
   }
   else
   {
      output_g2d_line_data(g2d_data->dest_base_address,start_x,start_y,clip_start_x,clip_end_x,clip_start_y,
                           clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,g2d_data->pat_fg_color);
   }
   dotted_line_toggle=(dotted_line_toggle+1)&0x01;

   delta_x=g2d_data->end_x-g2d_data->start_x;
   delta_y=g2d_data->end_y-g2d_data->start_y;
   if (g2d_data->line_anti_alias_mode==G2D_LINE_ANTI_ALIAS_ENABLE)
   {
      temp_data=delta_x*delta_x + delta_y*delta_y;
      temp_data1=2*sqrt(temp_data);
      xy_sqrt=(kal_uint16) temp_data1;
   }

   switch (line_direction)
   {
      case 1:  /* y major */
         x_index=start_x;
         y_index=start_y+1;
         delta=abs_delta_x*2-abs_delta_y;
         for (;y_index<=end_y;y_index++)
         {
            if (delta<0)
            {
               d_current=delta+abs_delta_y;
               d_above=abs_delta_y-delta;
               d_below=(3*abs_delta_y+delta);

               delta += (2*abs_delta_x);
            }
            else
            {
               d_current=delta-abs_delta_y;
               d_below=abs_delta_y+delta;
               d_above=(3*abs_delta_y-delta);

               delta+=(2*(abs_delta_x-abs_delta_y));
               x_index++;
            }

            if (g2d_data->line_anti_alias_mode==G2D_LINE_ANTI_ALIAS_DISABLE)
            {
               if (((g2d_data->dotted_mode==G2D_LINE_DOTTED_MODE)&&(dotted_line_toggle==1))||
                   (g2d_data->dotted_mode==G2D_LINE_LINE_MODE))
               {
                  output_g2d_line_data(g2d_data->dest_base_address,x_index,y_index,clip_start_x,clip_end_x,clip_start_y,
                                       clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,g2d_data->pat_fg_color);
               }
            }
            else if (g2d_data->line_anti_alias_mode==G2D_LINE_ANTI_ALIAS_ENABLE)
            {
               if (((g2d_data->dotted_mode==G2D_LINE_DOTTED_MODE)&&(dotted_line_toggle==1))||
                   (g2d_data->dotted_mode==G2D_LINE_LINE_MODE))
               {
                  if (d_current<0)
                     d_current*=(-1);
                  if (d_above<0)
                     d_above*=(-1);
                  if (d_below<0)
                     d_below*=(-1);
                  get_g2d_line_data(g2d_data->dest_color_mode,g2d_data->dest_base_address,(short)(x_index+1),y_index,
                                    &output_alpha,&output_red,&output_green,&output_blue,g2d_data->dest_pitch);
                  line_alias_data(d_above,fg_alpha,fg_red,fg_green,fg_blue,&output_alpha,&output_red,
                                  &output_green,&output_blue,xy_sqrt,g2d_data->dest_color_mode,&output_data);
                  output_g2d_line_data(g2d_data->dest_base_address,(short)(x_index+1),y_index,clip_start_x,clip_end_x,clip_start_y,
                                       clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,output_data);

                  get_g2d_line_data(g2d_data->dest_color_mode,g2d_data->dest_base_address,(short)(x_index-1),y_index,
                                    &output_alpha,&output_red,&output_green,&output_blue,g2d_data->dest_pitch);
                  line_alias_data(d_below,fg_alpha,fg_red,fg_green,fg_blue,&output_alpha,&output_red,
                                  &output_green,&output_blue,xy_sqrt,g2d_data->dest_color_mode,&output_data);
                  output_g2d_line_data(g2d_data->dest_base_address,(short)(x_index-1),y_index,clip_start_x,clip_end_x,clip_start_y,
                                       clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,output_data);

                  get_g2d_line_data(g2d_data->dest_color_mode,g2d_data->dest_base_address,x_index,y_index,
                                    &output_alpha,&output_red,&output_green,&output_blue,g2d_data->dest_pitch);
                  line_alias_data(d_current,fg_alpha,fg_red,fg_green,fg_blue,&output_alpha,&output_red,
                                  &output_green,&output_blue,xy_sqrt,g2d_data->dest_color_mode,&output_data);
                  output_g2d_line_data(g2d_data->dest_base_address,x_index,y_index,clip_start_x,clip_end_x,clip_start_y,
                                       clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,output_data);
               }
            }
            dotted_line_toggle=(dotted_line_toggle+1)&0x01;
         }
      break;
      case 2:  /* y major */
         x_index=start_x;
         y_index=start_y-1;
         delta=abs_delta_x*2-abs_delta_y;
         for (;y_index>=end_y;y_index--)
         {
            if (delta<0)
            {
               d_current=delta+abs_delta_y;
               d_above=abs_delta_y-delta;
               d_below=(3*abs_delta_y+delta);

               delta += (2*abs_delta_x);
            }
            else
            {
               d_current=delta-abs_delta_y;
               d_below=abs_delta_y+delta;
               d_above=(3*abs_delta_y-delta);

               delta+=(2*(abs_delta_x-abs_delta_y));
               x_index--;
            }

            if (g2d_data->line_anti_alias_mode==G2D_LINE_ANTI_ALIAS_DISABLE)
            {
               if (((g2d_data->dotted_mode==G2D_LINE_DOTTED_MODE)&&(dotted_line_toggle==1))||
                   (g2d_data->dotted_mode==G2D_LINE_LINE_MODE))
               {
                  output_g2d_line_data(g2d_data->dest_base_address,x_index,y_index,clip_start_x,clip_end_x,clip_start_y,
                                       clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,g2d_data->pat_fg_color);
               }
            }
            else if (g2d_data->line_anti_alias_mode==G2D_LINE_ANTI_ALIAS_ENABLE)
            {
               if (((g2d_data->dotted_mode==G2D_LINE_DOTTED_MODE)&&(dotted_line_toggle==1))||
                   (g2d_data->dotted_mode==G2D_LINE_LINE_MODE))
               {
                  if (d_current<0)
                     d_current*=(-1);
                  if (d_above<0)
                     d_above*=(-1);
                  if (d_below<0)
                     d_below*=(-1);
                  get_g2d_line_data(g2d_data->dest_color_mode,g2d_data->dest_base_address,(short)(x_index-1),y_index,
                                    &output_alpha,&output_red,&output_green,&output_blue,g2d_data->dest_pitch);
                  line_alias_data(d_above,fg_alpha,fg_red,fg_green,fg_blue,&output_alpha,&output_red,
                                  &output_green,&output_blue,xy_sqrt,g2d_data->dest_color_mode,&output_data);
                  output_g2d_line_data(g2d_data->dest_base_address,(short)(x_index-1),y_index,clip_start_x,clip_end_x,clip_start_y,
                                       clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,output_data);

                  get_g2d_line_data(g2d_data->dest_color_mode,g2d_data->dest_base_address,(short)(x_index+1),y_index,
                                    &output_alpha,&output_red,&output_green,&output_blue,g2d_data->dest_pitch);
                  line_alias_data(d_below,fg_alpha,fg_red,fg_green,fg_blue,&output_alpha,&output_red,
                                  &output_green,&output_blue,xy_sqrt,g2d_data->dest_color_mode,&output_data);
                  output_g2d_line_data(g2d_data->dest_base_address,(short)(x_index+1),y_index,clip_start_x,clip_end_x,clip_start_y,
                                       clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,output_data);

                  get_g2d_line_data(g2d_data->dest_color_mode,g2d_data->dest_base_address,x_index,y_index,
                                    &output_alpha,&output_red,&output_green,&output_blue,g2d_data->dest_pitch);
                  line_alias_data(d_current,fg_alpha,fg_red,fg_green,fg_blue,&output_alpha,&output_red,
                                  &output_green,&output_blue,xy_sqrt,g2d_data->dest_color_mode,&output_data);
                  output_g2d_line_data(g2d_data->dest_base_address,x_index,y_index,clip_start_x,clip_end_x,clip_start_y,
                                       clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,output_data);
               }
            }
            dotted_line_toggle=(dotted_line_toggle+1)&0x01;
         }
      break;
      case 3:
         x_index=start_x;
         y_index=start_y-1;
         delta=abs_delta_x*2-abs_delta_y;
         for (;y_index>=end_y;y_index--)
         {
            if (delta<0)
            {
               d_current=delta+abs_delta_y;
               d_above=abs_delta_y-delta;
               d_below=(3*abs_delta_y+delta);

               delta += (2*abs_delta_x);
            }
            else
            {
               d_current=delta-abs_delta_y;
               d_below=abs_delta_y+delta;
               d_above=(3*abs_delta_y-delta);

               delta+=(2*(abs_delta_x-abs_delta_y));
               x_index++;
            }

            if (g2d_data->line_anti_alias_mode==G2D_LINE_ANTI_ALIAS_DISABLE)
            {
               if (((g2d_data->dotted_mode==G2D_LINE_DOTTED_MODE)&&(dotted_line_toggle==1))||
                   (g2d_data->dotted_mode==G2D_LINE_LINE_MODE))
               {
                  output_g2d_line_data(g2d_data->dest_base_address,x_index,y_index,clip_start_x,clip_end_x,clip_start_y,
                                       clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,g2d_data->pat_fg_color);
               }
            }
            else if (g2d_data->line_anti_alias_mode==G2D_LINE_ANTI_ALIAS_ENABLE)
            {
               if (((g2d_data->dotted_mode==G2D_LINE_DOTTED_MODE)&&(dotted_line_toggle==1))||
                   (g2d_data->dotted_mode==G2D_LINE_LINE_MODE))
               {
                  if (d_current<0)
                     d_current*=(-1);
                  if (d_above<0)
                     d_above*=(-1);
                  if (d_below<0)
                     d_below*=(-1);
                  get_g2d_line_data(g2d_data->dest_color_mode,g2d_data->dest_base_address,(short)(x_index+1),y_index,
                                    &output_alpha,&output_red,&output_green,&output_blue,g2d_data->dest_pitch);
                  line_alias_data(d_above,fg_alpha,fg_red,fg_green,fg_blue,&output_alpha,&output_red,
                                  &output_green,&output_blue,xy_sqrt,g2d_data->dest_color_mode,&output_data);
                  output_g2d_line_data(g2d_data->dest_base_address,(short)(x_index+1),y_index,clip_start_x,clip_end_x,clip_start_y,
                                       clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,output_data);

                  get_g2d_line_data(g2d_data->dest_color_mode,g2d_data->dest_base_address,(short)(x_index-1),y_index,
                                    &output_alpha,&output_red,&output_green,&output_blue,g2d_data->dest_pitch);
                  line_alias_data(d_below,fg_alpha,fg_red,fg_green,fg_blue,&output_alpha,&output_red,
                                  &output_green,&output_blue,xy_sqrt,g2d_data->dest_color_mode,&output_data);
                  output_g2d_line_data(g2d_data->dest_base_address,(short)(x_index-1),y_index,clip_start_x,clip_end_x,clip_start_y,
                                       clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,output_data);

                  get_g2d_line_data(g2d_data->dest_color_mode,g2d_data->dest_base_address,x_index,y_index,
                                    &output_alpha,&output_red,&output_green,&output_blue,g2d_data->dest_pitch);
                  line_alias_data(d_current,fg_alpha,fg_red,fg_green,fg_blue,&output_alpha,&output_red,
                                  &output_green,&output_blue,xy_sqrt,g2d_data->dest_color_mode,&output_data);
                  output_g2d_line_data(g2d_data->dest_base_address,x_index,y_index,clip_start_x,clip_end_x,clip_start_y,
                                       clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,output_data);
               }
            }
            dotted_line_toggle=(dotted_line_toggle+1)&0x01;
         }
      break;
      case 4:
         x_index=start_x;
         y_index=start_y+1;
         delta=abs_delta_x*2-abs_delta_y;
         for (;y_index<=end_y;y_index++)
         {
            if (delta<0)
            {
               d_current=delta+abs_delta_y;
               d_above=abs_delta_y-delta;
               d_below=(3*abs_delta_y+delta);

               delta += (2*abs_delta_x);
            }
            else
            {
               d_current=delta-abs_delta_y;
               d_below=abs_delta_y+delta;
               d_above=(3*abs_delta_y-delta);

               delta+=(2*(abs_delta_x-abs_delta_y));
               x_index--;
            }

            if (g2d_data->line_anti_alias_mode==G2D_LINE_ANTI_ALIAS_DISABLE)
            {
               if (((g2d_data->dotted_mode==G2D_LINE_DOTTED_MODE)&&(dotted_line_toggle==1))||
                   (g2d_data->dotted_mode==G2D_LINE_LINE_MODE))
               {
                  output_g2d_line_data(g2d_data->dest_base_address,x_index,y_index,clip_start_x,clip_end_x,clip_start_y,
                                       clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,g2d_data->pat_fg_color);
               }
            }
            else if (g2d_data->line_anti_alias_mode==G2D_LINE_ANTI_ALIAS_ENABLE)
            {
               if (((g2d_data->dotted_mode==G2D_LINE_DOTTED_MODE)&&(dotted_line_toggle==1))||
                   (g2d_data->dotted_mode==G2D_LINE_LINE_MODE))
               {
                  if (d_current<0)
                     d_current*=(-1);
                  if (d_above<0)
                     d_above*=(-1);
                  if (d_below<0)
                     d_below*=(-1);
                  get_g2d_line_data(g2d_data->dest_color_mode,g2d_data->dest_base_address,(short)(x_index-1),y_index,
                                    &output_alpha,&output_red,&output_green,&output_blue,g2d_data->dest_pitch);
                  line_alias_data(d_above,fg_alpha,fg_red,fg_green,fg_blue,&output_alpha,&output_red,
                                  &output_green,&output_blue,xy_sqrt,g2d_data->dest_color_mode,&output_data);
                  output_g2d_line_data(g2d_data->dest_base_address,(short)(x_index-1),y_index,clip_start_x,clip_end_x,clip_start_y,
                                       clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,output_data);

                  get_g2d_line_data(g2d_data->dest_color_mode,g2d_data->dest_base_address,(short)(x_index+1),y_index,
                                    &output_alpha,&output_red,&output_green,&output_blue,g2d_data->dest_pitch);
                  line_alias_data(d_below,fg_alpha,fg_red,fg_green,fg_blue,&output_alpha,&output_red,
                                  &output_green,&output_blue,xy_sqrt,g2d_data->dest_color_mode,&output_data);
                  output_g2d_line_data(g2d_data->dest_base_address,(short)(x_index+1),y_index,clip_start_x,clip_end_x,clip_start_y,
                                       clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,output_data);

                  get_g2d_line_data(g2d_data->dest_color_mode,g2d_data->dest_base_address,x_index,y_index,
                                    &output_alpha,&output_red,&output_green,&output_blue,g2d_data->dest_pitch);
                  line_alias_data(d_current,fg_alpha,fg_red,fg_green,fg_blue,&output_alpha,&output_red,
                                  &output_green,&output_blue,xy_sqrt,g2d_data->dest_color_mode,&output_data);
                  output_g2d_line_data(g2d_data->dest_base_address,x_index,y_index,clip_start_x,clip_end_x,clip_start_y,
                                       clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,output_data);
               }
            }
            dotted_line_toggle=(dotted_line_toggle+1)&0x01;
         }
      break;
      case 5:  /* x major */
         y_index=start_y;
         x_index=start_x-1;
         delta=abs_delta_y*2-abs_delta_x;
         for (;x_index>=end_x;x_index--)
         {
            if (delta<0)
            {
               d_current=delta+abs_delta_x;
               d_above=abs_delta_x-delta;
               d_below=(3*abs_delta_x+delta);

               delta += (2*abs_delta_y);
            }
            else
            {
               d_current=delta-abs_delta_x;
               d_below=abs_delta_x+delta;
               d_above=(3*abs_delta_x-delta);

               delta+=(2*(abs_delta_y-abs_delta_x));
               y_index++;
            }

            if (g2d_data->line_anti_alias_mode==G2D_LINE_ANTI_ALIAS_DISABLE)
            {
               if (((g2d_data->dotted_mode==G2D_LINE_DOTTED_MODE)&&(dotted_line_toggle==1))||
                   (g2d_data->dotted_mode==G2D_LINE_LINE_MODE))
               {
                  output_g2d_line_data(g2d_data->dest_base_address,x_index,y_index,clip_start_x,clip_end_x,clip_start_y,
                                       clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,g2d_data->pat_fg_color);
               }
            }
            else if (g2d_data->line_anti_alias_mode==G2D_LINE_ANTI_ALIAS_ENABLE)
            {
               if (((g2d_data->dotted_mode==G2D_LINE_DOTTED_MODE)&&(dotted_line_toggle==1))||
                   (g2d_data->dotted_mode==G2D_LINE_LINE_MODE))
               {
                  if (d_current<0)
                     d_current*=(-1);
                  if (d_above<0)
                     d_above*=(-1);
                  if (d_below<0)
                     d_below*=(-1);
                  get_g2d_line_data(g2d_data->dest_color_mode,g2d_data->dest_base_address,x_index,(short)(y_index+1),
                                    &output_alpha,&output_red,&output_green,&output_blue,g2d_data->dest_pitch);
                  line_alias_data(d_above,fg_alpha,fg_red,fg_green,fg_blue,&output_alpha,&output_red,
                                  &output_green,&output_blue,xy_sqrt,g2d_data->dest_color_mode,&output_data);
                  output_g2d_line_data(g2d_data->dest_base_address,x_index,(short)(y_index+1),clip_start_x,clip_end_x,clip_start_y,
                                       clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,output_data);
                  get_g2d_line_data(g2d_data->dest_color_mode,g2d_data->dest_base_address,x_index,(short)(y_index-1),
                                    &output_alpha,&output_red,&output_green,&output_blue,g2d_data->dest_pitch);
                  line_alias_data(d_below,fg_alpha,fg_red,fg_green,fg_blue,&output_alpha,&output_red,
                                  &output_green,&output_blue,xy_sqrt,g2d_data->dest_color_mode,&output_data);
                  output_g2d_line_data(g2d_data->dest_base_address,x_index,(short)(y_index-1),clip_start_x,clip_end_x,clip_start_y,
                                       clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,output_data);
                  get_g2d_line_data(g2d_data->dest_color_mode,g2d_data->dest_base_address,x_index,y_index,
                                    &output_alpha,&output_red,&output_green,&output_blue,g2d_data->dest_pitch);
                  line_alias_data(d_current,fg_alpha,fg_red,fg_green,fg_blue,&output_alpha,&output_red,
                                  &output_green,&output_blue,xy_sqrt,g2d_data->dest_color_mode,&output_data);
                  output_g2d_line_data(g2d_data->dest_base_address,x_index,y_index,clip_start_x,clip_end_x,clip_start_y,
                                       clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,output_data);
               }
            }
            dotted_line_toggle=(dotted_line_toggle+1)&0x01;
         }
      break;
      case 6:  /* x major */
         y_index=start_y;
         x_index=start_x+1;
         delta=abs_delta_y*2-abs_delta_x;
         for (;x_index<=end_x;x_index++)
         {
            if (delta<0)
            {
               d_current=delta+abs_delta_x;
               d_above=abs_delta_x-delta;
               d_below=(3*abs_delta_x+delta);

               delta += (2*abs_delta_y);
            }
            else
            {
               d_current=delta-abs_delta_x;
               d_below=abs_delta_x+delta;
               d_above=(3*abs_delta_x-delta);

               delta+=(2*(abs_delta_y-abs_delta_x));
               y_index--;
            }

            if (g2d_data->line_anti_alias_mode==G2D_LINE_ANTI_ALIAS_DISABLE)
            {
               if (((g2d_data->dotted_mode==G2D_LINE_DOTTED_MODE)&&(dotted_line_toggle==1))||
                   (g2d_data->dotted_mode==G2D_LINE_LINE_MODE))
               {
                  output_g2d_line_data(g2d_data->dest_base_address,x_index,y_index,clip_start_x,clip_end_x,clip_start_y,
                                       clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,g2d_data->pat_fg_color);
               }
            }
            else if (g2d_data->line_anti_alias_mode==G2D_LINE_ANTI_ALIAS_ENABLE)
            {
               if (((g2d_data->dotted_mode==G2D_LINE_DOTTED_MODE)&&(dotted_line_toggle==1))||
                   (g2d_data->dotted_mode==G2D_LINE_LINE_MODE))
               {
                  if (d_current<0)
                     d_current*=(-1);
                  if (d_above<0)
                     d_above*=(-1);
                  if (d_below<0)
                     d_below*=(-1);
                  get_g2d_line_data(g2d_data->dest_color_mode,g2d_data->dest_base_address,x_index,(short)(y_index-1),
                                    &output_alpha,&output_red,&output_green,&output_blue,g2d_data->dest_pitch);
                  line_alias_data(d_above,fg_alpha,fg_red,fg_green,fg_blue,&output_alpha,&output_red,
                                  &output_green,&output_blue,xy_sqrt,g2d_data->dest_color_mode,&output_data);
                  output_g2d_line_data(g2d_data->dest_base_address,x_index,(short)(y_index-1),clip_start_x,clip_end_x,clip_start_y,
                                       clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,output_data);
                  get_g2d_line_data(g2d_data->dest_color_mode,g2d_data->dest_base_address,x_index,(short)(y_index+1),
                                    &output_alpha,&output_red,&output_green,&output_blue,g2d_data->dest_pitch);
                  line_alias_data(d_below,fg_alpha,fg_red,fg_green,fg_blue,&output_alpha,&output_red,
                                  &output_green,&output_blue,xy_sqrt,g2d_data->dest_color_mode,&output_data);
                  output_g2d_line_data(g2d_data->dest_base_address,x_index,(short)(y_index+1),clip_start_x,clip_end_x,clip_start_y,
                                       clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,output_data);
                  get_g2d_line_data(g2d_data->dest_color_mode,g2d_data->dest_base_address,x_index,y_index,
                                    &output_alpha,&output_red,&output_green,&output_blue,g2d_data->dest_pitch);
                  line_alias_data(d_current,fg_alpha,fg_red,fg_green,fg_blue,&output_alpha,&output_red,
                                  &output_green,&output_blue,xy_sqrt,g2d_data->dest_color_mode,&output_data);
                  output_g2d_line_data(g2d_data->dest_base_address,x_index,y_index,clip_start_x,clip_end_x,clip_start_y,
                                       clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,output_data);
               }
            }
            dotted_line_toggle=(dotted_line_toggle+1)&0x01;
         }
      break;
      case 7:  /* x major */
         y_index=start_y;
         x_index=start_x+1;
         delta=abs_delta_y*2-abs_delta_x;
         for (;x_index<=end_x;x_index++)
         {
            if (delta<0)
            {
               d_current=delta+abs_delta_x;
               d_above=abs_delta_x-delta;
               d_below=(3*abs_delta_x+delta);

               delta += (2*abs_delta_y);
            }
            else
            {
               d_current=delta-abs_delta_x;
               d_below=abs_delta_x+delta;
               d_above=(3*abs_delta_x-delta);

               delta+=(2*(abs_delta_y-abs_delta_x));
               y_index++;
            }

            if (g2d_data->line_anti_alias_mode==G2D_LINE_ANTI_ALIAS_DISABLE)
            {
               if (((g2d_data->dotted_mode==G2D_LINE_DOTTED_MODE)&&(dotted_line_toggle==1))||
                   (g2d_data->dotted_mode==G2D_LINE_LINE_MODE))
               {
                  output_g2d_line_data(g2d_data->dest_base_address,x_index,y_index,clip_start_x,clip_end_x,clip_start_y,
                                       clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,g2d_data->pat_fg_color);
               }
            }
            else if (g2d_data->line_anti_alias_mode==G2D_LINE_ANTI_ALIAS_ENABLE)
            {
               if (((g2d_data->dotted_mode==G2D_LINE_DOTTED_MODE)&&(dotted_line_toggle==1))||
                   (g2d_data->dotted_mode==G2D_LINE_LINE_MODE))
               {
                  if (d_current<0)
                     d_current*=(-1);
                  if (d_above<0)
                     d_above*=(-1);
                  if (d_below<0)
                     d_below*=(-1);
                  get_g2d_line_data(g2d_data->dest_color_mode,g2d_data->dest_base_address,x_index,(short)(y_index+1),
                                    &output_alpha,&output_red,&output_green,&output_blue,g2d_data->dest_pitch);
                  line_alias_data(d_above,fg_alpha,fg_red,fg_green,fg_blue,&output_alpha,&output_red,
                                  &output_green,&output_blue,xy_sqrt,g2d_data->dest_color_mode,&output_data);
                  output_g2d_line_data(g2d_data->dest_base_address,x_index,(short)(y_index+1),clip_start_x,clip_end_x,clip_start_y,
                                       clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,output_data);

                  get_g2d_line_data(g2d_data->dest_color_mode,g2d_data->dest_base_address,x_index,(short)(y_index-1),
                                    &output_alpha,&output_red,&output_green,&output_blue,g2d_data->dest_pitch);
                  line_alias_data(d_below,fg_alpha,fg_red,fg_green,fg_blue,&output_alpha,&output_red,
                                  &output_green,&output_blue,xy_sqrt,g2d_data->dest_color_mode,&output_data);
                  output_g2d_line_data(g2d_data->dest_base_address,x_index,(short)(y_index-1),clip_start_x,clip_end_x,clip_start_y,
                                       clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,output_data);

                  get_g2d_line_data(g2d_data->dest_color_mode,g2d_data->dest_base_address,x_index,y_index,
                                    &output_alpha,&output_red,&output_green,&output_blue,g2d_data->dest_pitch);
                  line_alias_data(d_current,fg_alpha,fg_red,fg_green,fg_blue,&output_alpha,&output_red,
                                  &output_green,&output_blue,xy_sqrt,g2d_data->dest_color_mode,&output_data);
                  output_g2d_line_data(g2d_data->dest_base_address,x_index,y_index,clip_start_x,clip_end_x,clip_start_y,
                                       clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,output_data);
               }
            }
            dotted_line_toggle=(dotted_line_toggle+1)&0x01;
         }
      break;
      case 8:  /* x major */
         y_index=start_y;
         x_index=start_x-1;
         delta=abs_delta_y*2-abs_delta_x;
         for (;x_index>=end_x;x_index--)
         {
            if (delta<0)
            {
               d_current=delta+abs_delta_x;
               d_above=abs_delta_x-delta;
               d_below=(3*abs_delta_x+delta);

               delta += (2*abs_delta_y);
            }
            else
            {
               d_current=delta-abs_delta_x;
               d_below=abs_delta_x+delta;
               d_above=(3*abs_delta_x-delta);

               delta+=(2*(abs_delta_y-abs_delta_x));
               y_index--;
            }

            if (g2d_data->line_anti_alias_mode==G2D_LINE_ANTI_ALIAS_DISABLE)
            {
               if (((g2d_data->dotted_mode==G2D_LINE_DOTTED_MODE)&&(dotted_line_toggle==1))||
                   (g2d_data->dotted_mode==G2D_LINE_LINE_MODE))
               {
                  output_g2d_line_data(g2d_data->dest_base_address,x_index,y_index,clip_start_x,clip_end_x,clip_start_y,
                                       clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,g2d_data->pat_fg_color);
               }
            }
            else if (g2d_data->line_anti_alias_mode==G2D_LINE_ANTI_ALIAS_ENABLE)
            {
               if (((g2d_data->dotted_mode==G2D_LINE_DOTTED_MODE)&&(dotted_line_toggle==1))||
                   (g2d_data->dotted_mode==G2D_LINE_LINE_MODE))
               {
                  if (d_current<0)
                     d_current*=(-1);
                  if (d_above<0)
                     d_above*=(-1);
                  if (d_below<0)
                     d_below*=(-1);
                  get_g2d_line_data(g2d_data->dest_color_mode,g2d_data->dest_base_address,x_index,(short)(y_index-1),
                                    &output_alpha,&output_red,&output_green,&output_blue,g2d_data->dest_pitch);
                  line_alias_data(d_above,fg_alpha,fg_red,fg_green,fg_blue,&output_alpha,&output_red,
                                  &output_green,&output_blue,xy_sqrt,g2d_data->dest_color_mode,&output_data);
                  output_g2d_line_data(g2d_data->dest_base_address,x_index,(short)(y_index-1),clip_start_x,clip_end_x,clip_start_y,
                                       clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,output_data);

                  get_g2d_line_data(g2d_data->dest_color_mode,g2d_data->dest_base_address,x_index,(short)(y_index+1),
                                    &output_alpha,&output_red,&output_green,&output_blue,g2d_data->dest_pitch);
                  line_alias_data(d_below,fg_alpha,fg_red,fg_green,fg_blue,&output_alpha,&output_red,
                                  &output_green,&output_blue,xy_sqrt,g2d_data->dest_color_mode,&output_data);
                  output_g2d_line_data(g2d_data->dest_base_address,x_index,(short)(y_index+1),clip_start_x,clip_end_x,clip_start_y,
                                       clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,output_data);

                  get_g2d_line_data(g2d_data->dest_color_mode,g2d_data->dest_base_address,x_index,y_index,
                                    &output_alpha,&output_red,&output_green,&output_blue,g2d_data->dest_pitch);
                  line_alias_data(d_current,fg_alpha,fg_red,fg_green,fg_blue,&output_alpha,&output_red,
                                  &output_green,&output_blue,xy_sqrt,g2d_data->dest_color_mode,&output_data);
                  output_g2d_line_data(g2d_data->dest_base_address,x_index,y_index,clip_start_x,clip_end_x,clip_start_y,
                                       clip_end_y,g2d_data->dest_color_mode,g2d_data->dest_pitch,output_data);
               }
            }
            dotted_line_toggle=(dotted_line_toggle+1)&0x01;
         }
      break;
   }
}  /* g2d_sw_line_drawing() */

void bezier_curve_divide(kal_uint16 start,kal_uint16 middle,kal_uint16 end)
{
   kal_uint16 first_point,third_point;

   first_point=(start+middle)>>1;
   third_point=(middle+end)>>1;
   subdivided_buffer[first_point][0]=(subdivided_buffer[start][0]+subdivided_buffer[middle][0])>>1;
   subdivided_buffer[first_point][1]=(subdivided_buffer[start][1]+subdivided_buffer[middle][1])>>1;
   subdivided_buffer[third_point][0]=(subdivided_buffer[end][0]+subdivided_buffer[middle][0])>>1;
   subdivided_buffer[third_point][1]=(subdivided_buffer[end][1]+subdivided_buffer[middle][1])>>1;
   subdivided_buffer[middle][0]=((subdivided_buffer[start][0]>>1)+(subdivided_buffer[end][0]>>1)+(subdivided_buffer[middle][0]))>>1;
   subdivided_buffer[middle][1]=((subdivided_buffer[start][1]>>1)+(subdivided_buffer[end][1]>>1)+(subdivided_buffer[middle][1]))>>1;

}  /* bezier_curve_divide() */

void g2d_sw_bezier_curve_drawing(g2d_parameter_struct *g2d_data)
{
   kal_uint16 i,j;
   kal_uint8 divided_time;
   kal_uint16 total_point,point_position,point_offset;

// g2d_control_data.clip_start_x=g2d_data->clip_start_x;
// g2d_control_data.clip_start_y=g2d_data->clip_start_y;
// g2d_control_data.clip_end_x=g2d_data->clip_end_x;
// g2d_control_data.clip_end_y=g2d_data->clip_end_y;
// g2d_control_data.pat_fg_color=g2d_data->pat_fg_color;
// g2d_control_data.dest_color_mode=g2d_data->dest_color_mode;
// g2d_control_data.clip_mode=g2d_data->clip_mode;
// g2d_control_data.dest_base_address=g2d_data->dest_base_address;
// g2d_control_data.g2d_operation_mode=FIRE_G2D_LINE_DRAWING;
// g2d_control_data.dest_pitch_width=g2d_data->dest_pitch_width;
// g2d_control_data.dest_pitch=g2d_data->dest_pitch;
   g2d_control_data.line_anti_alias_mode=G2D_LINE_ANTI_ALIAS_DISABLE;
   g2d_control_data.dotted_mode=G2D_LINE_LINE_MODE;

   divided_time=g2d_data->bezier_curve_divide_time;
   total_point=(1<<(divided_time+1))+1;
   point_position=total_point-1;
   subdivided_buffer[0][0]=(g2d_data->start_x<<4);
   subdivided_buffer[0][1]=(g2d_data->start_y<<4);
   subdivided_buffer[total_point-1][0]=(g2d_data->end_x<<4);
   subdivided_buffer[total_point-1][1]=(g2d_data->end_y<<4);
   subdivided_buffer[((total_point-1)>>1)][0]=(g2d_data->middle_x<<4);
   subdivided_buffer[((total_point-1)>>1)][1]=(g2d_data->middle_y<<4);

   if (divided_time>=1)
   {
      for (i=1;i<=divided_time;i++)
      {
         point_offset=point_position>>i;
         for (j=0;j<(1<<(i-1));j++)
         {
            bezier_curve_divide((kal_uint16)(point_offset*(j*2)),(kal_uint16)(point_offset*(j*2+1)),(kal_uint16)(point_offset*(j*2+2)));
         }
      }
   }

   for (i=0;i<(total_point-1);i++)
   {
      g2d_control_data.start_x=subdivided_buffer[i][0]>>4;
      g2d_control_data.start_y=subdivided_buffer[i][1]>>4;
      g2d_control_data.end_x=subdivided_buffer[i+1][0]>>4;
      g2d_control_data.end_y=subdivided_buffer[i+1][1]>>4;
      g2d_sw_line_drawing(&g2d_control_data);
   }
}  /* g2d_sw_bezier_curve_drawing() */

void g2d_sw_triangle_fill(g2d_parameter_struct *g2d_data)
{
   short i,j;
   kal_uint16 *dest_buff_ptr16;
   kal_uint8 *dest_buff_ptr8;
   kal_uint32 *dest_buff_ptr32;
   short start_x,end_x,end_y;
   int start_x_offset=0,end_x_offset=0;
   kal_uint32 left_slope,right_slope;
   kal_uint16 clip_start_x,clip_start_y,clip_end_x,clip_end_y;
   kal_uint8 fill_data8;
   kal_uint16 fill_data16;
   kal_uint32 fill_data32;

   clip_start_x=g2d_data->clip_start_x;
   clip_start_y=g2d_data->clip_start_y;
   clip_end_x=g2d_data->clip_end_x;
   clip_end_y=g2d_data->clip_end_y;

   dest_buff_ptr16=(kal_uint16 *)g2d_data->dest_base_address;
   dest_buff_ptr8=(kal_uint8 *)g2d_data->dest_base_address;
   dest_buff_ptr32=(kal_uint32 *)g2d_data->dest_base_address;
   fill_data16=(kal_uint16) (g2d_data->pat_fg_color);
   fill_data8=(kal_uint8) (g2d_data->pat_fg_color);
   fill_data32=(kal_uint32) (g2d_data->pat_fg_color);
   end_y=g2d_data->middle_y;
   left_slope=g2d_data->triangle_left_slope;
   right_slope=g2d_data->triangle_right_slope;
   start_x=g2d_data->dest_x;
   end_x=g2d_data->dest_x;

   if ((g2d_data->dest_y>=0)&&(g2d_data->dest_y>=clip_start_y)&&(g2d_data->dest_y<=clip_end_y)&&
       (g2d_data->dest_x>=0)&&(g2d_data->dest_x>=clip_start_x)&&(g2d_data->dest_x<=clip_end_x))
   {
      switch (g2d_data->dest_color_mode)
      {
         case FIRE_DEST_COLOR_16BPP_RGB565:
         case FIRE_DEST_COLOR_16BPP_ARGB4444:
            *(dest_buff_ptr16+g2d_data->dest_y*g2d_data->dest_pitch+g2d_data->dest_x) = fill_data16;
         break;
         case FIRE_DEST_COLOR_8BPP_LUT_DIS:
            *(dest_buff_ptr8+g2d_data->dest_y*g2d_data->dest_pitch+g2d_data->dest_x) = fill_data8;
         break;
         case FIRE_DEST_COLOR_24BPP_RGB888:
            *(dest_buff_ptr8+(g2d_data->dest_y*g2d_data->dest_pitch+g2d_data->dest_x)*3) = (kal_uint8) (fill_data32&0xFF);
            *(dest_buff_ptr8+(g2d_data->dest_y*g2d_data->dest_pitch+g2d_data->dest_x)*3+1) = (kal_uint8) ((fill_data32&0xFF00)>>8);
            *(dest_buff_ptr8+(g2d_data->dest_y*g2d_data->dest_pitch+g2d_data->dest_x)*3+2) = (kal_uint8) ((fill_data32&0xFF0000)>>16);
         break;
         case FIRE_DEST_COLOR_32BPP_ARGB8888:
            *(dest_buff_ptr32+(g2d_data->dest_y*g2d_data->dest_pitch+g2d_data->dest_x)) = fill_data32;
         break;
      }
   }

   if (g2d_data->dest_y>g2d_data->middle_y)
   {
      for (i=(g2d_data->dest_y-1);i>=g2d_data->middle_y;i--)
      {
         if (left_slope & 0x80000000) /* left_slope is negative */
            start_x_offset += (left_slope|0xF0000000);
         else
            start_x_offset +=left_slope;

         if (right_slope & 0x80000000)
            end_x_offset += (right_slope|0xF0000000);
         else
            end_x_offset += right_slope;

         if ((i>=0)&&(i>=clip_start_y)&&(i<=clip_end_y))
         {
            start_x=g2d_data->dest_x+(start_x_offset>>16);
            end_x=g2d_data->dest_x+(end_x_offset>>16);

            for (j=(start_x+1);j<=end_x;j++)
            {
               if ((j>=0)&&(j>=clip_start_x)&&(j<=clip_end_x))
               {
                  switch (g2d_data->dest_color_mode)
                  {
                     case FIRE_DEST_COLOR_16BPP_RGB565:
                     case FIRE_DEST_COLOR_16BPP_ARGB4444:
                        *(dest_buff_ptr16+i*g2d_data->dest_pitch+j) = fill_data16;
                     break;
                     case FIRE_DEST_COLOR_8BPP_LUT_DIS:
                        *(dest_buff_ptr8+i*g2d_data->dest_pitch+j) = fill_data8;
                     break;
                     case FIRE_DEST_COLOR_24BPP_RGB888:
                        *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j)*3) = (kal_uint8) (fill_data32&0xFF);
                        *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j)*3+1) = (kal_uint8) ((fill_data32&0xFF00)>>8);
                        *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j)*3+2) = (kal_uint8) ((fill_data32&0xFF0000)>>16);
                     break;
                     case FIRE_DEST_COLOR_32BPP_ARGB8888:
                        *(dest_buff_ptr32+(i*g2d_data->dest_pitch+j)) = fill_data32;
                     break;
                  }
               }
            }
         }
      }
   }
   else
   {
      for (i=(g2d_data->dest_y+1);i<=end_y;i++)
      {
         if (left_slope & 0x80000000) /* left_slope is negative */
            start_x_offset += (left_slope|0xF0000000);
         else
            start_x_offset +=left_slope;

         if (right_slope & 0x80000000)
            end_x_offset += (right_slope|0xF0000000);
         else
            end_x_offset += right_slope;

         if ((i>=0)&&(i>=clip_start_y)&&(i<=clip_end_y))
         {
            start_x=g2d_data->dest_x+(start_x_offset>>16);
            end_x=g2d_data->dest_x+(end_x_offset>>16);

            for (j=(start_x+1);j<=end_x;j++)
            {
               if ((j>=0)&&(j>=clip_start_x)&&(j<=clip_end_x))
               {
                  switch (g2d_data->dest_color_mode)
                  {
                     case FIRE_DEST_COLOR_16BPP_RGB565:
                     case FIRE_DEST_COLOR_16BPP_ARGB4444:
                        *(dest_buff_ptr16+i*g2d_data->dest_pitch+j) = fill_data16;
                     break;
                     case FIRE_DEST_COLOR_8BPP_LUT_DIS:
                        *(dest_buff_ptr8+i*g2d_data->dest_pitch+j) = fill_data8;
                     break;
                     case FIRE_DEST_COLOR_24BPP_RGB888:
                        *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j)*3) = (kal_uint8) (fill_data32&0xFF);
                        *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j)*3+1) = (kal_uint8) ((fill_data32&0xFF00)>>8);
                        *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j)*3+2) = (kal_uint8) ((fill_data32&0xFF0000)>>16);
                     break;
                     case FIRE_DEST_COLOR_32BPP_ARGB8888:
                        *(dest_buff_ptr32+(i*g2d_data->dest_pitch+j)) = fill_data32;
                     break;
                  }
               }
            }
         }
      }
   }
}  /* g2d_sw_triangle_fill() */

void g2d_sw_rectangle_fill(g2d_parameter_struct *g2d_data)
{
   short i,j;
   kal_uint16 *dest_buff_ptr16;
   kal_uint8 *dest_buff_ptr8;
   kal_uint32 *dest_buff_ptr32;
   short end_x,end_y;
   kal_uint16 clip_start_x,clip_start_y,clip_end_x,clip_end_y;
   kal_uint32 alpha=0,red,green,blue,alpha1,red1,green1,blue1;
   kal_uint8 tilt_value;
   kal_uint32 fill_color;
   kal_uint8 tilt_index=0;

   clip_start_x=g2d_data->clip_start_x;
   clip_start_y=g2d_data->clip_start_y;
   clip_end_x=g2d_data->clip_end_x;
   clip_end_y=g2d_data->clip_end_y;

   end_x=g2d_data->dest_width+g2d_data->dest_x;
   end_y=g2d_data->dest_height+g2d_data->dest_y;

   dest_buff_ptr16=(kal_uint16 *)g2d_data->dest_base_address;
   dest_buff_ptr8=(kal_uint8 *)g2d_data->dest_base_address;
   dest_buff_ptr32=(kal_uint32 *)g2d_data->dest_base_address;
   switch (g2d_data->dest_color_mode)
   {
      case FIRE_DEST_COLOR_16BPP_RGB565:
         g2d_rgb565_to_rgb888((kal_uint16)g2d_data->pat_fg_color,&red,&green,&blue);
      break;
      case FIRE_DEST_COLOR_16BPP_ARGB4444:
         alpha = (g2d_data->pat_fg_color & 0xF000)>>12;
         alpha=(alpha|(alpha<<4))<<16;
         red = (g2d_data->pat_fg_color & 0xF00)>>8;
         red=(red|(red<<4))<<16;
         green = (g2d_data->pat_fg_color & 0xF0)>>4;
         green=(green|(green<<4))<<16;
         blue = (g2d_data->pat_fg_color & 0xF);
         blue=(blue|(blue<<4))<<16;
      break;
      case FIRE_DEST_COLOR_8BPP_LUT_DIS:
         blue=(g2d_data->pat_fg_color&0xFF)<<16;
      break;
      case FIRE_DEST_COLOR_24BPP_RGB888:
         red=(g2d_data->pat_fg_color&0xFF0000);
         green=(g2d_data->pat_fg_color&0xFF00)<<8;
         blue=(g2d_data->pat_fg_color&0xFF)<<16;
      break;
      case FIRE_DEST_COLOR_32BPP_ARGB8888:
         alpha=(g2d_data->pat_fg_color&0xFF000000)>>8;
         red=(g2d_data->pat_fg_color&0xFF0000);
         green=(g2d_data->pat_fg_color&0xFF00)<<8;
         blue=(g2d_data->pat_fg_color&0xFF)<<16;
      break;
   }

   for (i=g2d_data->dest_y;i<end_y;i++)
   {
      tilt_value=g2d_sw_tilt_value[(tilt_index&G2D_TILT_SIZE_MASK)];

      if (g2d_data->color_gradient_mode==G2D_REC_FILL_COLOR_GRAD_ENABLE)
      {
         if ((i>=0)&&(i>=clip_start_y)&&(i<=clip_end_y))
         {
            alpha1=alpha;
            red1=red;
            green1=green;
            blue1=blue;
            for (j=g2d_data->dest_x;j<end_x;j++)
            {
               if ((g2d_data->italic_mode==G2D_REC_FILL_ITALIC_DISABLE)&&
                   (j>=0)&&(j>=clip_start_x)&&(j<=clip_end_x))
               {
                  switch (g2d_data->dest_color_mode)
                  {
                     case FIRE_DEST_COLOR_16BPP_RGB565:
                        *(dest_buff_ptr16+i*g2d_data->dest_pitch+j) = g2d_rgb888_to_rgb565(red1,green1,blue1);
                     break;
                     case FIRE_DEST_COLOR_16BPP_ARGB4444:
                        if ((alpha1>>16)>255)
                           fill_color=0xF000;
                        else
                           fill_color = (alpha1>>20)<<12;
                        if ((red1>>16)>255)
                           fill_color |= 0xF00;
                        else
                           fill_color |= ((red1>>20)<<8);

                        if ((green1>>16)>255)
                           fill_color |= 0xF0;
                        else
                           fill_color |= ((green1>>20)<<4);
                        if ((blue1>>16)>255)
                           fill_color |= 0xF;
                        else
                           fill_color |= (blue1>>20);
                        *(dest_buff_ptr16+i*g2d_data->dest_pitch+j) = fill_color;
                     break;
                     case FIRE_DEST_COLOR_8BPP_LUT_DIS:
                        if ((blue1>>16)>255)
                           *(dest_buff_ptr8+i*g2d_data->dest_pitch+j) = 0xFF;
                        else
                           *(dest_buff_ptr8+i*g2d_data->dest_pitch+j) = (blue1>>16);
                     break;
                     case FIRE_DEST_COLOR_24BPP_RGB888:
                        if ((red1>>16)>255)
                           *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j)*3+2) = 255;
                        else
                           *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j)*3+2) = red1>>16;
                        if ((green1>>16)>255)
                           *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j)*3+1) = 255;
                        else
                           *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j)*3+1) = green1>>16;
                        if ((blue1>>16)>255)
                           *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j)*3) = 255;
                        else
                           *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j)*3) = blue1>>16;
                     break;
                     case FIRE_DEST_COLOR_32BPP_ARGB8888:
                        if ((alpha1>>16)>255)
                           fill_color=0xFF000000;
                        else
                           fill_color = (alpha1>>16)<<24;
                        if ((red1>>16)>255)
                           fill_color |= (255<<16);
                        else
                           fill_color |= ((red1>>16)<<16);

                        if ((green1>>16)>255)
                           fill_color |= (255<<8);
                        else
                           fill_color |= ((green1>>16)<<8);
                        if ((blue1>>16)>255)
                           fill_color |= 255;
                        else
                           fill_color |= (blue1>>16);

                        *(dest_buff_ptr32+(i*g2d_data->dest_pitch+j)) = fill_color;
                     break;
                  }
               }
               else if ((g2d_data->italic_mode==G2D_REC_FILL_ITALIC_ENABLE)&&
                   (((j+tilt_value)>=0)&&((j+tilt_value)>=clip_start_x)&&
                   ((j+tilt_value)<=clip_end_x)))
               {
                  switch (g2d_data->dest_color_mode)
                  {
                     case FIRE_DEST_COLOR_16BPP_RGB565:
                        *(dest_buff_ptr16+i*g2d_data->dest_pitch+j+tilt_value) = g2d_rgb888_to_rgb565(red1,green1,blue1);
                     break;
                     case FIRE_DEST_COLOR_16BPP_ARGB4444:
                        if ((alpha1>>16)>255)
                           fill_color=0xF000;
                        else
                           fill_color = (alpha1>>20)<<12;
                        if ((red1>>16)>255)
                           fill_color |= 0xF00;
                        else
                           fill_color |= ((red1>>20)<<8);

                        if ((green1>>16)>255)
                           fill_color |= 0xF0;
                        else
                           fill_color |= ((green1>>20)<<4);
                        if ((blue1>>16)>255)
                           fill_color |= 0xF;
                        else
                           fill_color |= (blue1>>20);
                        *(dest_buff_ptr16+i*g2d_data->dest_pitch+j+tilt_value) = fill_color;
                     break;
                     case FIRE_DEST_COLOR_8BPP_LUT_DIS:
                        if ((blue1>>16)>255)
                           *(dest_buff_ptr8+i*g2d_data->dest_pitch+j+tilt_value) = 0xFF;
                        else
                           *(dest_buff_ptr8+i*g2d_data->dest_pitch+j+tilt_value) = (blue1>>16);
                     break;
                     case FIRE_DEST_COLOR_24BPP_RGB888:
                        if ((red1>>16)>255)
                           *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j+tilt_value)*3+2) = 255;
                        else
                           *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j+tilt_value)*3+2) = red1>>16;
                        if ((green1>>16)>255)
                           *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j+tilt_value)*3+1) = 255;
                        else
                           *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j+tilt_value)*3+1) = green1>>16;
                        if ((blue1>>16)>255)
                           *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j+tilt_value)*3) = 255;
                        else
                           *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j+tilt_value)*3) = blue1>>16;
                     break;
                     case FIRE_DEST_COLOR_32BPP_ARGB8888:
                        if ((alpha1>>16)>255)
                           fill_color=0xFF000000;
                        else
                           fill_color = (alpha1>>16)<<24;
                        if ((red1>>16)>255)
                           fill_color |= (255<<16);
                        else
                           fill_color |= ((red1>>16)<<16);

                        if ((green1>>16)>255)
                           fill_color |= (255<<8);
                        else
                           fill_color |= ((green1>>16)<<8);
                        if ((blue1>>16)>255)
                           fill_color |= 255;
                        else
                           fill_color |= (blue1>>16);

                        *(dest_buff_ptr32+(i*g2d_data->dest_pitch+j+tilt_value)) = fill_color;
                     break;
                  }
               }

               switch (g2d_data->dest_color_mode)
               {
                  case FIRE_DEST_COLOR_16BPP_RGB565:
                  case FIRE_DEST_COLOR_24BPP_RGB888:
                     red1=g2d_gradient(0,1,red1);
                     green1=g2d_gradient(0,2,green1);
                     blue1=g2d_gradient(0,3,blue1);
                  break;
                  case FIRE_DEST_COLOR_16BPP_ARGB4444:
                  case FIRE_DEST_COLOR_32BPP_ARGB8888:
                     alpha1=g2d_gradient(0,0,alpha1);
                     red1=g2d_gradient(0,1,red1);
                     green1=g2d_gradient(0,2,green1);
                     blue1=g2d_gradient(0,3,blue1);
                  break;
                  case FIRE_DEST_COLOR_8BPP_LUT_DIS:
                     blue1=g2d_gradient(0,3,blue1);
                  break;
               }
            }
         }
         switch (g2d_data->dest_color_mode)
         {
            case FIRE_DEST_COLOR_16BPP_RGB565:
            case FIRE_DEST_COLOR_24BPP_RGB888:
               red=g2d_gradient(1,1,red);
               green=g2d_gradient(1,2,green);
               blue=g2d_gradient(1,3,blue);
            break;
            case FIRE_DEST_COLOR_16BPP_ARGB4444:
            case FIRE_DEST_COLOR_32BPP_ARGB8888:
               alpha=g2d_gradient(1,0,alpha);
               red=g2d_gradient(1,1,red);
               green=g2d_gradient(1,2,green);
               blue=g2d_gradient(1,3,blue);
            break;
            case FIRE_DEST_COLOR_8BPP_LUT_DIS:
               blue=g2d_gradient(1,3,blue);
            break;
         }
      }
      else
      {
         if ((i>=0)&&(i>=clip_start_y)&&(i<=clip_end_y))
         {
            alpha1=alpha;
            red1=red;
            green1=green;
            blue1=blue;
            for (j=g2d_data->dest_x;j<end_x;j++)
            {
               if ((g2d_data->italic_mode==G2D_REC_FILL_ITALIC_DISABLE)&&
                   (j>=0)&&(j>=clip_start_x)&&(j<=clip_end_x))
               {
                  switch (g2d_data->dest_color_mode)
                  {
                     case FIRE_DEST_COLOR_16BPP_RGB565:
                     case FIRE_DEST_COLOR_16BPP_ARGB4444:
                        *(dest_buff_ptr16+i*g2d_data->dest_pitch+j) = g2d_data->pat_fg_color;
                     break;
                     case FIRE_DEST_COLOR_8BPP_LUT_DIS:
                        *(dest_buff_ptr8+i*g2d_data->dest_pitch+j) = (kal_uint8) g2d_data->pat_fg_color;
                     break;
                     case FIRE_DEST_COLOR_24BPP_RGB888:
                        *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j)*3) = (g2d_data->pat_fg_color) & 0xFF;
                        *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j)*3+1) = ((g2d_data->pat_fg_color)&0xFF00)>>8;
                        *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j)*3+2) = ((g2d_data->pat_fg_color)&0xFF0000)>>16;
                     break;
                     case FIRE_DEST_COLOR_32BPP_ARGB8888:
                        *(dest_buff_ptr32+(i*g2d_data->dest_pitch+j)) = g2d_data->pat_fg_color;
                     break;
                  }
               }
               else if ((g2d_data->italic_mode==G2D_REC_FILL_ITALIC_ENABLE)&&
                        (((j+tilt_value)>=0)&&((j+tilt_value)>=clip_start_x)&&
                        ((j+tilt_value)<=clip_end_x)))
               {
                  switch (g2d_data->dest_color_mode)
                  {
                     case FIRE_DEST_COLOR_16BPP_RGB565:
                     case FIRE_DEST_COLOR_16BPP_ARGB4444:
                        *(dest_buff_ptr16+i*g2d_data->dest_pitch+j+tilt_value) = g2d_data->pat_fg_color;
                     break;
                     case FIRE_DEST_COLOR_8BPP_LUT_DIS:
                        *(dest_buff_ptr8+i*g2d_data->dest_pitch+j+tilt_value) = (kal_uint8) g2d_data->pat_fg_color;
                     break;
                     case FIRE_DEST_COLOR_24BPP_RGB888:
                        *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j+tilt_value)*3) = (g2d_data->pat_fg_color) & 0xFF;
                        *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j+tilt_value)*3+1) = ((g2d_data->pat_fg_color)&0xFF00)>>8;
                        *(dest_buff_ptr8+(i*g2d_data->dest_pitch+j+tilt_value)*3+2) = ((g2d_data->pat_fg_color)&0xFF0000)>>16;
                     break;
                     case FIRE_DEST_COLOR_32BPP_ARGB8888:
                        *(dest_buff_ptr32+(i*g2d_data->dest_pitch+j+tilt_value)) = g2d_data->pat_fg_color;
                     break;
                  }
               }
            }
         }
      }
      tilt_index++;
   }
}  /* g2d_sw_rectangle_fill() */

void g2d_sw_hline_copy(g2d_parameter_struct *g2d_data)
{
   short i;
   kal_uint16 *dest_buff_ptr16,src_index=0;
   kal_uint8 *dest_buff_ptr8,*mask_buff_ptr;
   kal_uint32 *dest_buff_ptr32;
   kal_uint8 src_alpha,src_red,src_green,src_blue;
   kal_uint32 src_data32;
   kal_uint16 clip_start_x,clip_start_y,clip_end_x,clip_end_y;
   short start_x,start_y,end_x;

   clip_start_x=g2d_data->clip_start_x;
   clip_start_y=g2d_data->clip_start_y;
   clip_end_x=g2d_data->clip_end_x;
   clip_end_y=g2d_data->clip_end_y;

   start_x=g2d_data->dest_x;
   start_y=g2d_data->dest_y;
   end_x=g2d_data->dest_width+start_x;

   mask_buff_ptr=(kal_uint8 *) g2d_data->buffer_address;
   dest_buff_ptr16=(kal_uint16 *)g2d_data->dest_base_address;
   dest_buff_ptr8=(kal_uint8 *)g2d_data->dest_base_address;
   dest_buff_ptr32=(kal_uint32 *)g2d_data->dest_base_address;

   if ((start_y>=clip_start_y)&&(start_y<=clip_end_y))
   {
      for (i=0;i<g2d_data->dest_width;i++,start_x++)
      {
         if ((start_x>=0)&&(start_x>=clip_start_x)&&(start_x<=clip_end_x))
         {
            if ((*(mask_buff_ptr+i))!=0)
            {
               get_bitblt_data(g2d_data->src_color_mode, g2d_data->src_base_address,src_index,0,
                               &src_alpha,&src_red,&src_green,&src_blue,0,&src_data32);

               switch (g2d_data->dest_color_mode)
               {
                  case FIRE_DEST_COLOR_16BPP_RGB565:
                     *(dest_buff_ptr16+i) = ((src_red & 0xF8)<<8)|((src_green&0xFC)<<3)|((src_blue&0xF8)>>3);
                  break;
                  case FIRE_DEST_COLOR_16BPP_ARGB4444:
                     *(dest_buff_ptr16+i) = ((src_alpha&0xF0)<<8)|((src_red & 0xF0)<<4)|(src_green&0xF0)|((src_blue&0xF0)>>4);
                  break;
                  case FIRE_DEST_COLOR_8BPP_LUT_DIS:
                     *(dest_buff_ptr8+i) = src_blue;
                  break;
                  case FIRE_DEST_COLOR_24BPP_RGB888:
                     *(dest_buff_ptr8+i*3+2) = src_red;
                     *(dest_buff_ptr8+i*3+1) = src_green;
                     *(dest_buff_ptr8+i*3) = src_blue;
                  break;
                  case FIRE_DEST_COLOR_32BPP_ARGB8888:
                     *(dest_buff_ptr32+i) = (src_alpha<<24)|(src_red <<16)|(src_green<<8)|src_blue;
                  break;
               }
            }
            src_index++;
            if (src_index==g2d_data->src_width)
               src_index=0;
         }
      }
   }
}  /* g2d_sw_hline_copy() */

void g2d_sw_hline_gradient(g2d_parameter_struct *g2d_data)
{
   short i;
   kal_uint16 *dest_buff_ptr16;
   kal_uint8 *dest_buff_ptr8;
   kal_uint32 *dest_buff_ptr32;
   short start_x,start_y,end_x;
   kal_uint16 clip_start_x,clip_start_y,clip_end_x,clip_end_y;
   kal_uint32 alpha=0xFF,red,green,blue,alpha1,red1,green1,blue1;
   kal_uint32 fill_color;

   clip_start_x=g2d_data->clip_start_x;
   clip_start_y=g2d_data->clip_start_y;
   clip_end_x=g2d_data->clip_end_x;
   clip_end_y=g2d_data->clip_end_y;

// start_x=0;
// start_y=0;
// end_x=g2d_data->dest_width;
   start_x=g2d_data->dest_x;
   start_y=g2d_data->dest_y;
   end_x=g2d_data->dest_width+start_x;

   dest_buff_ptr16=(kal_uint16 *)g2d_data->dest_base_address;
   dest_buff_ptr8=(kal_uint8 *)g2d_data->dest_base_address;
   dest_buff_ptr32=(kal_uint32 *)g2d_data->dest_base_address;
   switch (g2d_data->dest_color_mode)
   {
      case FIRE_DEST_COLOR_16BPP_RGB565:
         g2d_rgb565_to_rgb888((kal_uint16)g2d_data->pat_fg_color,&red,&green,&blue);
      break;
      case FIRE_DEST_COLOR_16BPP_ARGB4444:
         alpha = (g2d_data->pat_fg_color & 0xF000)>>12;
         alpha=(alpha|(alpha<<4))<<16;
         red = (g2d_data->pat_fg_color & 0xF00)>>8;
         red=(red|(red<<4))<<16;
         green = (g2d_data->pat_fg_color & 0xF0)>>4;
         green=(green|(green<<4))<<16;
         blue = (g2d_data->pat_fg_color & 0xF);
         blue=(blue|(blue<<4))<<16;
      break;
      case FIRE_DEST_COLOR_8BPP_LUT_DIS:
         blue=(g2d_data->pat_fg_color&0xFF)<<16;
      break;
      case FIRE_DEST_COLOR_24BPP_RGB888:
         red=(g2d_data->pat_fg_color&0xFF0000);
         green=(g2d_data->pat_fg_color&0xFF00)<<8;
         blue=(g2d_data->pat_fg_color&0xFF)<<16;
      break;
      case FIRE_DEST_COLOR_32BPP_ARGB8888:
         alpha=(g2d_data->pat_fg_color&0xFF000000)>>8;
         red=(g2d_data->pat_fg_color&0xFF0000);
         green=(g2d_data->pat_fg_color&0xFF00)<<8;
         blue=(g2d_data->pat_fg_color&0xFF)<<16;
      break;
   }

   alpha1=alpha;
   red1=red;
   green1=green;
   blue1=blue;

   if ((start_y>=clip_start_y)&&(start_y<=clip_end_y))
   {
      for (i=0;i<g2d_data->dest_width;i++,start_x++)
      {
         if ((start_x>=0)&&(start_x>=clip_start_x)&&(start_x<=clip_end_x))
         {
            switch (g2d_data->dest_color_mode)
            {
               case FIRE_DEST_COLOR_16BPP_RGB565:
                  *(dest_buff_ptr16+i) = g2d_rgb888_to_rgb565(red1,green1,blue1);
               break;
               case FIRE_DEST_COLOR_16BPP_ARGB4444:
                  if ((alpha1>>16)>255)
                     fill_color=0xF000;
                  else
                     fill_color = (alpha1>>20)<<12;
                  if ((red1>>16)>255)
                     fill_color |= 0xF00;
                  else
                     fill_color |= ((red1>>20)<<8);

                  if ((green1>>16)>255)
                     fill_color |= 0xF0;
                  else
                     fill_color |= ((green1>>20)<<4);
                  if ((blue1>>16)>255)
                     fill_color |= 0xF;
                  else
                     fill_color |= (blue1>>20);
                  *(dest_buff_ptr16+i) = fill_color;
               break;
               case FIRE_DEST_COLOR_8BPP_LUT_DIS:
                  if ((blue1>>16)>255)
                     *(dest_buff_ptr8+i) = 0xFF;
                  else
                     *(dest_buff_ptr8+i) = (blue1>>16);
               break;
                  case FIRE_DEST_COLOR_24BPP_RGB888:
                     if ((red1>>16)>255)
                        *(dest_buff_ptr8+i*3+2) = 255;
                     else
                        *(dest_buff_ptr8+i*3+2) = red1>>16;
                     if ((green1>>16)>255)
                        *(dest_buff_ptr8+i*3+1) = 255;
                     else
                        *(dest_buff_ptr8+i*3+1) = green1>>16;
                     if ((blue1>>16)>255)
                        *(dest_buff_ptr8+i*3) = 255;
                     else
                        *(dest_buff_ptr8+i*3) = blue1>>16;
                  break;
               case FIRE_DEST_COLOR_32BPP_ARGB8888:
                  if ((alpha1>>16)>255)
                     fill_color=0xFF000000;
                  else
                     fill_color = (alpha1>>16)<<24;
                  if ((red1>>16)>255)
                     fill_color |= (255<<16);
                  else
                     fill_color |= ((red1>>16)<<16);

                  if ((green1>>16)>255)
                     fill_color |= (255<<8);
                  else
                     fill_color |= ((green1>>16)<<8);
                  if ((blue1>>16)>255)
                     fill_color |= 255;
                  else
                     fill_color |= (blue1>>16);

                  *(dest_buff_ptr32+i) = fill_color;
               break;
            }
         }
         switch (g2d_data->dest_color_mode)
         {
            case FIRE_DEST_COLOR_16BPP_RGB565:
            case FIRE_DEST_COLOR_24BPP_RGB888:
               red1=g2d_gradient(0,1,red1);
               green1=g2d_gradient(0,2,green1);
               blue1=g2d_gradient(0,3,blue1);
            break;
            case FIRE_DEST_COLOR_16BPP_ARGB4444:
            case FIRE_DEST_COLOR_32BPP_ARGB8888:
               alpha1=g2d_gradient(0,0,alpha1);
               red1=g2d_gradient(0,1,red1);
               green1=g2d_gradient(0,2,green1);
               blue1=g2d_gradient(0,3,blue1);
            break;
            case FIRE_DEST_COLOR_8BPP_LUT_DIS:
               blue1=g2d_gradient(0,3,blue1);
            break;
         }
      }
   }
}  /* g2d_sw_hline_gradient() */
#endif   /* !__MTK_TARGET__ */
#endif

