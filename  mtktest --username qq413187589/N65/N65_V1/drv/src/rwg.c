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
 *    rwg.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intended for Random Waveform Generator (Enhaced PWM) driver.
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
#include "drv_features.h"
#include "drv_comm.h"

#if defined(DRV_PWM_RWG)
#include "reg_base.h"
#include "rwg_hw.h"
#include "rwg_sw.h"
#include "drvpdn.h"
#include	"intrCtrl.h"
#include "drv_hisr.h"
#include "custom_hw_default.h"
#include "swdbg_sw.h"


#define __PWM_NEED_MAIN_POWER__

static kal_uint8  PWM1_LEVEL_SAVE;   /*for MMI usage*/
static kal_uint8  PWM2_LEVEL_SAVE;   /*for MMI usage*/
static kal_uint32 PWM1_FRE_SAVE;   /*for MMI usage*/
static kal_uint32 PWM2_FRE_SAVE;   /*for MMI usage*/
static kal_uint8  PWM1_DUTY_SAVE;   /*for MMI usage*/
static kal_uint8  PWM2_DUTY_SAVE;   /*for MMI usage*/
#ifdef __PWM3_FOR_MMI__
static kal_uint8  PWM3_LEVEL_SAVE;   /*for MMI usage*/
static kal_uint32 PWM3_FRE_SAVE;   /*for MMI usage*/
static kal_uint8  PWM3_DUTY_SAVE;   /*for MMI usage*/
#endif /*__PWM3_FOR_MMI__*/

typedef void (*pwm_cb_fx)(kal_uint32 pwm_num);
typedef void (*pwm_invalid_cb_fx)(kal_uint32 pwm_num, kal_uint8 buf_num);

typedef struct 
{
   kal_uint8 owner;
   kal_uint8 mode;
   kal_bool  is_start;
   pwm_cb_fx pwm_cb;
   pwm_invalid_cb_fx pwm_invalid_cb;
} pwm_handle_s;

static kal_bool pwm_seq_mode_on;
static kal_uint8 pwm_seq_owner;
static pwm_handle_s pwm_handle_array[PWM_COUNT];

//static pwm_cb_fx  pwm_cb_array[PWM_COUNT*2] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//static pwm_invalid_cb_fx  pwm_invalid_cb_array[PWM_COUNT] = {0, 0, 0, 0, 0, 0};
#if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__)
static kal_uint8 PWM_PDNhandle;
static kal_uint16 PWM_52M_USED_MASK;
static kal_bool   PWM_52M_ENABLE;
#endif

static kal_uint32 PWM_Check_Buf_Valid(kal_uint32 pwm_num)
{
	kal_uint32 tmp;
	kal_uint32 base_addr;
   kal_uint32 ret_value = 0;

   if (pwm_num <= PWM3)
      base_addr = PWM1_VALID + 0x40*pwm_num;
   else
      base_addr = PWM4_VALID + 0x40*(pwm_num-PWM4);
   tmp = DRV_Reg32(base_addr);
   //if (PWM_BUF0_INVALID == (tmp & PWM_BUF0_VALID_MASK))
   if (!(tmp & PWM_BUF0_VALID_MASK))
   {
      /*if (!(tmp & PWM_BUF1_VALID_MASK))
         ret_value = PWM_BUF_0_1_INVALID;
      else*/
         ret_value = PWM_BUF_0_INVALID;
   }
   //if (PWM_BUF1_INVALID == (tmp & PWM_BUF1_VALID_MASK))
   else //if (!(tmp & PWM_BUF1_VALID_MASK))
      ret_value = PWM_BUF_1_INVALID;
   //else
      //ret_value = PWM_BUF_INVALID_NONE;
   return ret_value;
}

void PWM_Set_Buf_Valid(kal_uint8 owner, kal_uint32 pwm_num, kal_uint32 *buf_addr, kal_uint16 buf_size, kal_bool is_buf0)
{
	kal_uint32 tmp;
	kal_uint32 base_addr;
   kal_uint32 savedMask;
   pwm_handle_s   *handle;

   handle = pwm_handle_array+pwm_num;
   if ((pwm_num >= PWM_COUNT) || (handle->owner!=owner))
   {
      ASSERT(0);
      return;
   }
   if ((handle->is_start==KAL_FALSE)||(handle->mode!=PWM_RANDOM_MODE))
   {
      ASSERT(0);
      return;
   }
   if (is_buf0)
   {
      if ((0 != buf_addr) && (0 != buf_size))
      {
         base_addr = PWM1_BUF0_BASE_ADDR + 0x40*pwm_num;
         DRV_WriteReg32(base_addr, buf_addr);
         base_addr = PWM1_BUF0_SIZE + 0x40*pwm_num;
         DRV_WriteReg32(base_addr, buf_size);
      }
      if (pwm_num <= PWM3)
         base_addr = PWM1_VALID + 0x40*pwm_num;
      else
         base_addr = PWM4_VALID + 0x40*(pwm_num-PWM4);
      savedMask = SaveAndSetIRQMask();
      tmp = DRV_Reg32(base_addr);
      tmp |= (PWM_BUF0_VALID_WENABLE|PWM_BUF0_VALID);
      DRV_WriteReg32(base_addr, tmp);
      RestoreIRQMask(savedMask);
   }
   else
   {
      if ((0 != buf_addr) && (0 != buf_size))
      {
         base_addr = PWM1_BUF1_BASE_ADDR + 0x40*pwm_num;
         DRV_WriteReg32(base_addr, buf_addr);
         base_addr = PWM1_BUF1_SIZE + 0x40*pwm_num;
         DRV_WriteReg32(base_addr, buf_size);
      }
      if (pwm_num <= PWM3)
         base_addr = PWM1_VALID + 0x40*pwm_num;
      else
         base_addr = PWM4_VALID + 0x40*(pwm_num-PWM4);
      savedMask = SaveAndSetIRQMask();
      tmp = DRV_Reg32(base_addr);
      tmp |= (PWM_BUF1_VALID_WENABLE|PWM_BUF1_VALID);
      DRV_WriteReg32(base_addr, tmp);
      RestoreIRQMask(savedMask);
   }
}

/*
static void pwm_random_finish_cb(kal_uint32 pwm_num)
{
   kal_uint32 tmp;
   kal_uint32 base_addr;
   kal_uint32 count = 0;

   if (pwm_invalid_cb_array[pwm_num] != NULL)
   {
      if (PWM_BUF_0_INVALID == PWM_Check_Buf_Valid(pwm_num))
         (pwm_invalid_cb_array[pwm_num])(pwm_num, PWM_BUF_0_INVALID);
      else
         (pwm_invalid_cb_array[pwm_num])(pwm_num, PWM_BUF_1_INVALID);
   }
}
*/

void PWM_LISR(void)
{
   IRQMask(IRQ_PWM_CODE);
   drv_active_hisr(DRV_PWM_HISR_ID);
}

void PWM_HISR(void)
{
   kal_uint32  int_status;
   kal_uint32  index;
   kal_uint32  mask;

   int_status = DRV_Reg32(PWM_INT_STATUS);
   index = PWM1;
   mask = 1;
   while (index < PWM_COUNT)
   {
      pwm_handle_s   *handle;

      handle = pwm_handle_array+index;
      //mask = (0x00000001<<index);
      if (int_status & mask)
      {
         if (handle->mode==PWM_RANDOM_MODE)
         {
            if (handle->pwm_invalid_cb!=NULL)
               handle->pwm_invalid_cb(index, PWM_Check_Buf_Valid(index));
         }
         else
         {
            if (handle->pwm_cb!=NULL)
               handle->pwm_cb(index);
            handle->is_start = KAL_FALSE;
         }
	      //DRV_WriteReg32(PWM_INT_ACK, mask);
      }
      mask = (mask<<1);
      if (int_status & mask)
      {
         if (handle->mode==PWM_RANDOM_MODE)
         {
            if (handle->pwm_cb!=NULL)
               handle->pwm_cb(index);
            handle->is_start = KAL_FALSE;
         }
	      //DRV_WriteReg32(PWM_INT_ACK, mask);
      }
      mask = (mask<<1);
      index++;
   }
   DRV_WriteReg32(PWM_INT_ACK, int_status);
   IRQClearInt(IRQ_PWM_CODE);
   IRQUnmask(IRQ_PWM_CODE);

   /*
   if (int_status & PWM1_INT_FINISH_EN_ST)
   {
   }
   if (int_status & PWM2_INT_FINISH_EN_ST)
   {
   }
   if (int_status & PWM3_INT_FINISH_EN_ST)
   {
   }
   if (int_status & PWM4_INT_FINISH_EN_ST)
   {
   }
   if (int_status & PWM5_INT_FINISH_EN_ST)
   {
   }
   if (int_status & PWM6_INT_FINISH_EN_ST)
   {
   }
   if (int_status & PWM1_INT_UNDERFLOW_EN_ST)
   {
   }
   if (int_status & PWM2_INT_UNDERFLOW_EN_ST)
   {
   }
   if (int_status & PWM3_INT_UNDERFLOW_EN_ST)
   {
   }
   if (int_status & PWM4_INT_UNDERFLOW_EN_ST)
   {
   }
   if (int_status & PWM5_INT_UNDERFLOW_EN_ST)
   {
   }
   if (int_status & PWM6_INT_UNDERFLOW_EN_ST)
   {
   }*/
}

void PWM_Init(void)
{
   kal_uint8   index;

   for (index=PWM1; index < PWM_COUNT; index++)
   {
      pwm_handle_s   *handle;

      handle = pwm_handle_array+index;
      handle->owner = PWM_OWNER_NONE;
      handle->mode = PWM_MODE_COUNT;
      handle->is_start = KAL_FALSE;
      handle->pwm_cb = NULL;
      handle->pwm_invalid_cb = NULL;
   }
   #if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__)
   PWM_PDNhandle = L1SM_GetHandle();;
   PWM_52M_USED_MASK = 0;
   PWM_52M_ENABLE = KAL_FALSE;
   #endif
   pwm_seq_mode_on = KAL_FALSE;
   pwm_seq_owner = PWM_OWNER_NONE;
   DRV_Register_HISR(DRV_PWM_HISR_ID, PWM_HISR);
   IRQ_Register_LISR(IRQ_PWM_CODE, PWM_LISR,"PWM handler");
   IRQSensitivity(IRQ_PWM_CODE,LEVEL_SENSITIVE);
   IRQUnmask(IRQ_PWM_CODE);
}

void PWM_CLK_Init(kal_uint8 owner, kal_uint32 pwm_num, kal_uint32 clk_sel, kal_uint32 clk_div)
{
	kal_uint32 tmp;
	kal_uint32 base_addr;
   kal_uint32 savedMask;
   pwm_handle_s   *handle;

   handle = pwm_handle_array+pwm_num;
   if ((pwm_num >= PWM_COUNT) || (handle->owner!=owner))
   {
      ASSERT(0);
      return;
   }
   if (handle->is_start==KAL_TRUE)
   {
      ASSERT(0);
      return;
   }
   base_addr = PWM1_CON + 0x40*pwm_num;
   savedMask = SaveAndSetIRQMask();
   tmp = DRV_Reg32(base_addr);
   tmp &= ~(PWM_CON_CLKDIV_MASK|PWM_CON_CLKSEL_MASK);
   tmp |= (PWM_CON_CLKDIV_MASK&(clk_div<<PWM_CON_CLKDIV_SHIFT));
   tmp |= (PWM_CON_CLKSEL_MASK&(clk_sel<<PWM_CON_CLKSEL_SHIFT));
	DRV_WriteReg32(base_addr,tmp);
   #if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__)
   if (clk_sel == PWM_CLK_SEL_52M)
      PWM_52M_USED_MASK |= (0x0001 << pwm_num);
   else
      PWM_52M_USED_MASK &= (~(0x0001 << pwm_num));
   #endif
   RestoreIRQMask(savedMask);
}

kal_bool PWM_Configure(kal_uint8 owner, kal_uint32 pwm_num, kal_uint32 mode, void *para)
{
	kal_uint32 tmp;
	kal_uint32 base_addr;
   pwm_handle_s   *handle;
   kal_uint32 savedMask;

   handle = pwm_handle_array+pwm_num;
   if ((pwm_num >= PWM_COUNT) || (handle->owner!=owner))
   {
      ASSERT(0);
      return KAL_FALSE;
   }
   if (handle->is_start==KAL_TRUE)
   {
      ASSERT(0);
      return KAL_FALSE;
   }
   base_addr = PWM1_CON + 0x40*pwm_num;
   savedMask = SaveAndSetIRQMask();
	tmp = DRV_Reg32(base_addr);
   switch(mode)
   {
   case PWM_FIFO_MODE:
      {
         pwm_fifo_para_s   *fifo_para;

         fifo_para = (pwm_fifo_para_s *)para;
         if ((fifo_para->high_dur==0) || (fifo_para->low_dur==0)/* || (fifo_para->guard_dur==0)*/)
         {
            RestoreIRQMask(savedMask);
            ASSERT(0);
            return KAL_FALSE;
         }
         tmp &= ~(PWM_CON_SRCSEL_MASK|PWM_CON_MODE_MASK|PWM_CON_IDLE_VALUE_MASK|PWM_CON_GUARD_VALUE_MASK|
                  PWM_CON_STOP_BITPOS_MASK|PWM_CON_OLD_PWM_MODE_MASK);
         tmp |= (PWM_CON_SRCSEL_FIFO |
                 PWM_CON_MODE_PERIODIC |
                 ((fifo_para->idle_output<<PWM_CON_IDLE_VALUE_SHIFT)&PWM_CON_IDLE_VALUE_MASK) |
                 ((fifo_para->guard_output<<PWM_CON_GUARD_VALUE_SHIFT)&PWM_CON_GUARD_VALUE_MASK) |
                 ((fifo_para->stop_bitpos<<PWM_CON_STOP_BITPOS_SHIFT)&PWM_CON_STOP_BITPOS_MASK) |
                 PWM_CON_NEW_PWM_MODE);
         DRV_WriteReg32(base_addr, tmp);
         RestoreIRQMask(savedMask);
         base_addr = PWM1_SEND_DATA0 + 0x40*pwm_num;
         DRV_WriteReg32(base_addr, fifo_para->data0);
         base_addr = PWM1_SEND_DATA1 + 0x40*pwm_num;
         DRV_WriteReg32(base_addr, fifo_para->data1);
         base_addr = PWM1_WAVE_NUM + 0x40*pwm_num;
         DRV_WriteReg32(base_addr, fifo_para->repeat_count);
         base_addr = PWM1_HDURATION + 0x40*pwm_num;
         DRV_WriteReg32(base_addr, fifo_para->high_dur);
         base_addr = PWM1_LDURATION + 0x40*pwm_num;
         DRV_WriteReg32(base_addr, fifo_para->low_dur);
         base_addr = PWM1_GDURATION + 0x40*pwm_num;
         DRV_WriteReg32(base_addr, fifo_para->guard_dur);
         savedMask = SaveAndSetIRQMask();
         tmp = DRV_Reg32(PWM_INT_ENABLE);
         tmp &= ~((PWM1_INT_FINISH_EN_MASK|PWM1_INT_UNDERFLOW_EN_MASK) << (pwm_num*2));
         if (fifo_para->pwm_callback != 0)
         {
            tmp |= ((PWM1_INT_FINISH_ENABLE|PWM1_INT_UNDERFLOW_DISABLE) << (pwm_num*2));
         }
         handle->mode = PWM_FIFO_MODE;
         handle->pwm_cb = fifo_para->pwm_callback;
         handle->pwm_invalid_cb = NULL;
         DRV_WriteReg32(PWM_INT_ENABLE, tmp);
         RestoreIRQMask(savedMask);
         //pwm_cb_array[pwm_num*2] = fifo_para->pwm_callback;
         //pwm_cb_array[pwm_num*2+1] = 0;
      }
      break;
   case PWM_MEMO_MODE:
      {
         pwm_memo_para_s   *mem_para;

         mem_para = (pwm_memo_para_s *)para;
         if ((mem_para->high_dur==0) || (mem_para->low_dur==0)/* || (mem_para->guard_dur==0)*/)
         {
            RestoreIRQMask(savedMask);
            return KAL_FALSE;
         }
         tmp &= ~(PWM_CON_SRCSEL_MASK|PWM_CON_MODE_MASK|PWM_CON_IDLE_VALUE_MASK|PWM_CON_GUARD_VALUE_MASK|
                  PWM_CON_STOP_BITPOS_MASK|PWM_CON_OLD_PWM_MODE_MASK);
         tmp |= (PWM_CON_SRCSEL_MEM |
                 PWM_CON_MODE_PERIODIC |
                 ((mem_para->idle_output<<PWM_CON_IDLE_VALUE_SHIFT)&PWM_CON_IDLE_VALUE_MASK) |
                 ((mem_para->guard_output<<PWM_CON_GUARD_VALUE_SHIFT)&PWM_CON_GUARD_VALUE_MASK) |
                 ((mem_para->stop_bitpos<<PWM_CON_STOP_BITPOS_SHIFT)&PWM_CON_STOP_BITPOS_MASK) |
                 PWM_CON_NEW_PWM_MODE);
         DRV_WriteReg32(base_addr, tmp);
         RestoreIRQMask(savedMask);
         base_addr = PWM1_BUF0_BASE_ADDR + 0x40*pwm_num;
         DRV_WriteReg32(base_addr, mem_para->buf_addr);
         base_addr = PWM1_BUF0_SIZE + 0x40*pwm_num;
         DRV_WriteReg32(base_addr, mem_para->buf_size);
         base_addr = PWM1_WAVE_NUM + 0x40*pwm_num;
         DRV_WriteReg32(base_addr, mem_para->repeat_count);
         base_addr = PWM1_HDURATION + 0x40*pwm_num;
         DRV_WriteReg32(base_addr, mem_para->high_dur);
         base_addr = PWM1_LDURATION + 0x40*pwm_num;
         DRV_WriteReg32(base_addr, mem_para->low_dur);
         base_addr = PWM1_GDURATION + 0x40*pwm_num;
         DRV_WriteReg32(base_addr, mem_para->guard_dur);
         savedMask = SaveAndSetIRQMask();
         tmp = DRV_Reg32(PWM_INT_ENABLE);
         tmp &= ~((PWM1_INT_FINISH_EN_MASK|PWM1_INT_UNDERFLOW_EN_MASK) << (pwm_num*2));
         if (mem_para->pwm_callback != 0)
         {
            tmp |= ((PWM1_INT_FINISH_ENABLE|PWM1_INT_UNDERFLOW_DISABLE) << (pwm_num*2));
         }
         handle->mode = PWM_MEMO_MODE;
         handle->pwm_cb = mem_para->pwm_callback;
         handle->pwm_invalid_cb = NULL;
         DRV_WriteReg32(PWM_INT_ENABLE, tmp);
         RestoreIRQMask(savedMask);
      }
      break;
   case PWM_OLD_MODE:
      {
         pwm_old_para_s   *old_para;

         if (pwm_num > PWM3)
         {
            RestoreIRQMask(savedMask);
            return KAL_FALSE;
         }

         old_para = (pwm_old_para_s *)para;
         //if (old_para->guard_dur==0)
            //return KAL_FALSE;
         tmp &= ~(PWM_CON_IDLE_VALUE_MASK|PWM_CON_GUARD_VALUE_MASK|PWM_CON_OLD_PWM_MODE_MASK);
         tmp |= (((old_para->idle_output<<PWM_CON_IDLE_VALUE_SHIFT)&PWM_CON_IDLE_VALUE_MASK) |
                 ((old_para->guard_output<<PWM_CON_GUARD_VALUE_SHIFT)&PWM_CON_GUARD_VALUE_MASK) |
                 PWM_CON_OLD_PWM_MODE);
         DRV_WriteReg32(base_addr, tmp);
         RestoreIRQMask(savedMask);
         base_addr = PWM1_DATA_WIDTH + 0x40*pwm_num;
         DRV_WriteReg32(base_addr, old_para->data_width);
         base_addr = PWM1_THRESH + 0x40*pwm_num;
         DRV_WriteReg32(base_addr, old_para->threshold);
         base_addr = PWM1_WAVE_NUM + 0x40*pwm_num;
         DRV_WriteReg32(base_addr, old_para->repeat_count);
         base_addr = PWM1_GDURATION + 0x40*pwm_num;
         DRV_WriteReg32(base_addr, old_para->guard_dur);
         savedMask = SaveAndSetIRQMask();
         tmp = DRV_Reg32(PWM_INT_ENABLE);
         tmp &= ~((PWM1_INT_FINISH_EN_MASK|PWM1_INT_UNDERFLOW_EN_MASK) << (pwm_num*2));
         if (old_para->pwm_callback != 0)
         {
            tmp |= ((PWM1_INT_FINISH_ENABLE|PWM1_INT_UNDERFLOW_DISABLE) << (pwm_num*2));
         }
         handle->mode = PWM_OLD_MODE;
         handle->pwm_cb = old_para->pwm_callback;
         handle->pwm_invalid_cb = NULL;
         DRV_WriteReg32(PWM_INT_ENABLE, tmp);
         RestoreIRQMask(savedMask);
      }
      break;
   case PWM_RANDOM_MODE:
      {
         pwm_random_para_s   *random_para;

         random_para = (pwm_random_para_s *)para;
         if ((random_para->high_dur==0) || (random_para->low_dur==0) 
            || (random_para->buf0_size==0)|| (random_para->buf1_size==0))
         {
            RestoreIRQMask(savedMask);
            return KAL_FALSE;
         }
         tmp &= ~(PWM_CON_SRCSEL_MASK|PWM_CON_MODE_MASK|PWM_CON_IDLE_VALUE_MASK|PWM_CON_OLD_PWM_MODE_MASK);
         tmp |= (PWM_CON_SRCSEL_MEM |
                 PWM_CON_MODE_RANDOM |
                 ((random_para->idle_output<<PWM_CON_IDLE_VALUE_SHIFT)&PWM_CON_IDLE_VALUE_MASK) |
                 PWM_CON_NEW_PWM_MODE);
         DRV_WriteReg32(base_addr, tmp);
         RestoreIRQMask(savedMask);
         base_addr = PWM1_BUF0_BASE_ADDR + 0x40*pwm_num;
         DRV_WriteReg32(base_addr, random_para->buf0_addr);
         base_addr = PWM1_BUF0_SIZE + 0x40*pwm_num;
         DRV_WriteReg32(base_addr, random_para->buf0_size);
         base_addr = PWM1_BUF1_BASE_ADDR + 0x40*pwm_num;
         DRV_WriteReg32(base_addr, random_para->buf1_addr);
         base_addr = PWM1_BUF1_SIZE + 0x40*pwm_num;
         DRV_WriteReg32(base_addr, random_para->buf1_size);
         base_addr = PWM1_HDURATION + 0x40*pwm_num;
         DRV_WriteReg32(base_addr, random_para->high_dur);
         base_addr = PWM1_LDURATION + 0x40*pwm_num;
         DRV_WriteReg32(base_addr, random_para->low_dur);
         if (pwm_num <= PWM3)
            base_addr = PWM1_VALID + 0x40*pwm_num;
         else
            base_addr = PWM4_VALID + 0x40*(pwm_num-PWM4);
         tmp = (PWM_BUF0_VALID|PWM_BUF0_VALID_WENABLE|PWM_BUF1_VALID|PWM_BUF1_VALID_WENABLE);
         DRV_WriteReg32(base_addr, tmp);
         savedMask = SaveAndSetIRQMask();
         tmp = DRV_Reg32(PWM_INT_ENABLE);
         tmp &= ~((PWM1_INT_FINISH_EN_MASK|PWM1_INT_UNDERFLOW_EN_MASK) << (pwm_num*2));
         if (random_para->pwm_invalid_cb != 0)
            tmp |= (PWM1_INT_FINISH_ENABLE << (pwm_num*2));
         if (random_para->pwm_underflow_cb != 0)
            tmp |= (PWM1_INT_UNDERFLOW_ENABLE << (pwm_num*2));
         handle->mode = PWM_RANDOM_MODE;
         handle->pwm_cb = random_para->pwm_underflow_cb;
         handle->pwm_invalid_cb = random_para->pwm_invalid_cb;
         DRV_WriteReg32(PWM_INT_ENABLE, tmp);
         RestoreIRQMask(savedMask);
         //pwm_cb_array[pwm_num*2] = pwm_random_finish_cb;
         //pwm_invalid_cb_array[pwm_num] = random_para->pwm_invalid_cb;
         //pwm_cb_array[pwm_num*2+1] = random_para->pwm_underflow_cb;
      }
      break;
   default:
      RestoreIRQMask(savedMask);
      return KAL_FALSE;
      break;
   }
   return KAL_TRUE;
}

void PWM_Start(kal_uint8 owner, kal_uint32 pwm_num)
{
	kal_uint32 tmp;
   pwm_handle_s   *handle;
   kal_uint32 savedMask;

   handle = pwm_handle_array+pwm_num;
   if ( (handle->owner!=owner) || 
      ((pwm_seq_mode_on==KAL_FALSE) && (pwm_num >= PWM_COUNT)) || 
      ((pwm_seq_mode_on==KAL_TRUE) && (pwm_num >= PWM3)) )
   {
      ASSERT(0);
      return;
   }
   if (handle->is_start==KAL_TRUE)
   {
      //ASSERT(0);
      return ;
   }
   if (pwm_num == PWM1)
      DRV_WriteReg(DRVPDN_CON1_CLR,DRVPDN_CON1_PWM1);
   else if (pwm_num == PWM2)
      DRV_WriteReg(DRVPDN_CON1_CLR,DRVPDN_CON1_PWM2);
   else
      DRV_WriteReg(DRVPDN_CON0_CLR,DRVPDN_CON0_PWM3);

   //Power on?
   savedMask = SaveAndSetIRQMask();
   handle->is_start=KAL_TRUE;
	tmp = DRV_Reg32(PWM_ENABLE);
   #if (defined(MTK_SLEEP_ENABLE) && !defined(__FUE__))
   if ((PWM_52M_ENABLE == KAL_FALSE) && (tmp & PWM_52M_USED_MASK))
   {
      PWM_52M_ENABLE = KAL_TRUE;
      L1SM_SleepDisable(PWM_PDNhandle);
   }
   #endif
   if (!(tmp & 0x003f))
      DRV_WriteReg(DRVPDN_CON0_CLR,DRVPDN_CON0_PWM);
   tmp &= ~(PWM1_ENABLE_MASK << pwm_num);
   tmp |= (PWM1_ENABLE << pwm_num);
   DRV_WriteReg32(PWM_ENABLE, tmp);
   RestoreIRQMask(savedMask);
}

void PWM_Stop(kal_uint8 owner, kal_uint32 pwm_num)
{
	kal_uint32 tmp;
   pwm_handle_s   *handle;
   kal_uint32 savedMask;

   handle = pwm_handle_array+pwm_num;
   if ( (handle->owner!=owner) || 
      ((pwm_seq_mode_on==KAL_FALSE) && (pwm_num >= PWM_COUNT)) || 
      ((pwm_seq_mode_on==KAL_TRUE) && (pwm_num >= PWM3)) )
   {
      ASSERT(0);
      return;
   }
   savedMask = SaveAndSetIRQMask();
   handle->is_start=KAL_FALSE;
	tmp = DRV_Reg32(PWM_ENABLE);
   tmp &= ~(PWM1_ENABLE_MASK << pwm_num);
   tmp |= (PWM1_DISABLE << pwm_num);
   DRV_WriteReg32(PWM_ENABLE, tmp);
#ifndef __PWM_NEED_MAIN_POWER__
   if (!(tmp & 0x003f))
      DRV_WriteReg(DRVPDN_CON1_SET,DRVPDN_CON1_PWM);
#endif
   #if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__)
   if ((PWM_52M_ENABLE == KAL_TRUE) && !(tmp & PWM_52M_USED_MASK))
   {
      PWM_52M_ENABLE = KAL_FALSE;
      L1SM_SleepEnable(PWM_PDNhandle);
   }
   #endif
   if ((pwm_num >= PWM3) && (!(tmp & 0x003c)))
      DRV_WriteReg(DRVPDN_CON0_SET,DRVPDN_CON0_PWM3);
   RestoreIRQMask(savedMask);
   //Power off?
   if (pwm_num == PWM1)
      DRV_WriteReg(DRVPDN_CON1_SET,DRVPDN_CON1_PWM1);
   else if (pwm_num == PWM2)
      DRV_WriteReg(DRVPDN_CON1_SET,DRVPDN_CON1_PWM2);

}

void PMW_Set_Delay(kal_uint8 owner, kal_uint32 pwm_num, kal_uint32 clk_sel, kal_uint16 delay_cnt)
{
   kal_uint32 clk_delay_sel;

   if ((owner!=pwm_seq_owner) || (pwm_seq_mode_on==KAL_FALSE))
   {
      ASSERT(0);
      return;
   }
   if ((pwm_num < PWM4) || (pwm_num >= PWM_COUNT))
      return;
   clk_delay_sel = (clk_sel==PWM_CLK_SEL_52M) ? PWM_DELAY_CLKSEL_52M : PWM_DELAY_CLKSEL_32K;
   DRV_WriteReg32((PWM4_DELAY+(pwm_num-PWM4)*4), (clk_delay_sel| (delay_cnt&PWM_DELAY_DURATON_MASK)));
}

void PWM_Seq_Start(kal_uint8 owner, kal_uint8 en_cnt)
{
   kal_uint32 en_reg;
   kal_uint32 saved_en_reg;
   kal_uint32 savedMask;
   pwm_handle_s   *handle;

   if ((owner!=pwm_seq_owner) || (pwm_seq_mode_on==KAL_FALSE))
   {
      ASSERT(0);
      return;
   }
   ASSERT(en_cnt&0x01);
   savedMask = SaveAndSetIRQMask();
   en_reg = DRV_Reg32(PWM_ENABLE);
   saved_en_reg = en_reg;
   en_reg &= (PWM1_ENABLE_MASK|PWM2_ENABLE_MASK);
   handle = pwm_handle_array+PWM3;
   if (en_cnt&0x01)
   {
      en_reg |= PWM3_ENABLE;
      handle->is_start=KAL_TRUE;
   }
   else
      handle->is_start=KAL_FALSE;
   handle++;
   if (en_cnt&0x02)
   {
      en_reg |= PWM4_ENABLE;
      handle->is_start=KAL_TRUE;
   }
   else
      handle->is_start=KAL_FALSE;
   handle++;
   if (en_cnt&0x04)
   {
      en_reg |= PWM5_ENABLE;
      handle->is_start=KAL_TRUE;
   }
   else
      handle->is_start=KAL_FALSE;
   handle++;
   if (en_cnt&0x08)
   {
      en_reg |= PWM6_ENABLE;
      handle->is_start=KAL_TRUE;
   }
   else
      handle->is_start=KAL_FALSE;
   #if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__)
   if ((PWM_52M_ENABLE == KAL_FALSE) && (en_reg & PWM_52M_USED_MASK))
   {
      PWM_52M_ENABLE = KAL_TRUE;
      L1SM_SleepDisable(PWM_PDNhandle);
   }
   #endif
   if (!(saved_en_reg & 0x003f))
      DRV_WriteReg(DRVPDN_CON1_CLR,DRVPDN_CON1_PWM);
   DRV_WriteReg(DRVPDN_CON0_CLR,DRVPDN_CON0_PWM3);
   DRV_WriteReg32(PWM_ENABLE, (en_reg|PWM_SEQ_MODE_ON));
   RestoreIRQMask(savedMask);
}

void PWM_Seq_Stop(kal_uint8 owner)
{
   kal_uint32 savedMask;
   kal_uint32 en_reg;
   pwm_handle_s   *handle;
   kal_uint8   index;

   if ((owner!=pwm_seq_owner) || (pwm_seq_mode_on==KAL_FALSE))
   {
      ASSERT(0);
      return;
   }
   savedMask = SaveAndSetIRQMask();
   en_reg = DRV_Reg32(PWM_ENABLE);
   en_reg &= (PWM1_ENABLE_MASK|PWM2_ENABLE_MASK);
   DRV_WriteReg32(PWM_ENABLE, (en_reg|PWM3_DISABLE|PWM4_DISABLE|PWM5_DISABLE|PWM6_DISABLE|PWM_SEQ_MODE_OFF));
   for (index=PWM3; index <= PWM6; index++)
   {
      handle = pwm_handle_array+index;
      handle->is_start=KAL_FALSE;
   }
#ifndef __PWM_NEED_MAIN_POWER__
   if (!(en_reg & 0x003f))
      DRV_WriteReg(DRVPDN_CON1_SET,DRVPDN_CON1_PWM);
#endif
   DRV_WriteReg(DRVPDN_CON0_SET,DRVPDN_CON0_PWM3);
   #if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__)
   if ((PWM_52M_ENABLE == KAL_TRUE) && !(en_reg & PWM_52M_USED_MASK))
   {
      PWM_52M_ENABLE = KAL_FALSE;
      L1SM_SleepEnable(PWM_PDNhandle);
   }
   #endif
   RestoreIRQMask(savedMask);
}

kal_bool PWM_Open(kal_uint8 owner, kal_uint32 pwm_num)
{
   pwm_handle_s   *handle;

#ifdef __PWM_NEED_MAIN_POWER__
   /* For register access bug, we have to turn on the PWM main power first. 
      Should be remove afterward. */
   DRV_WriteReg(DRVPDN_CON0_CLR,DRVPDN_CON0_PWM);
#endif

   handle = pwm_handle_array+pwm_num;
   if ((pwm_num >= PWM_COUNT) || (handle->owner!=PWM_OWNER_NONE))
   {
      ASSERT(0);
      return KAL_FALSE;
   }
   handle->owner = owner;
   handle->mode = PWM_MODE_COUNT;
   handle->is_start = KAL_FALSE;
   handle->pwm_cb = NULL;
   handle->pwm_invalid_cb = NULL;
   return KAL_TRUE;
}

kal_bool PWM_Close(kal_uint8 owner, kal_uint32 pwm_num)
{
   pwm_handle_s   *handle;

   handle = pwm_handle_array+pwm_num;
   if ((pwm_num >= PWM_COUNT) || (handle->owner!=owner))
   {
      ASSERT(0);
      return KAL_FALSE;
   }
   if (handle->is_start == KAL_TRUE)
   {
      PWM_Stop(owner, pwm_num);
      handle->is_start = KAL_FALSE;
   }
   handle->owner = PWM_OWNER_NONE;
   handle->mode = PWM_MODE_COUNT;
   handle->pwm_cb = NULL;
   handle->pwm_invalid_cb = NULL;
   return KAL_TRUE;
}

kal_bool PWM_Seq_Open(kal_uint8 owner)
{
   kal_uint32     idx;
   pwm_handle_s   *handle;

   if (pwm_seq_owner!=PWM_OWNER_NONE)
   {
      ASSERT(0);
      return KAL_FALSE;
   }
#ifdef __PWM_NEED_MAIN_POWER__
   /* For register access bug, we have to turn on the PWM main power first. 
      Should be remove afterward. */
   DRV_WriteReg(DRVPDN_CON0_CLR,DRVPDN_CON0_PWM);
#endif
   handle = pwm_handle_array+PWM3;
   for (idx=PWM3; idx < PWM_COUNT; idx++)
   {
      handle->owner = owner;
      handle->mode = PWM_MODE_COUNT;
      handle->is_start = KAL_FALSE;
      handle->pwm_cb = NULL;
      handle->pwm_invalid_cb = NULL;
      handle++;
   }
   pwm_seq_owner = owner;
   pwm_seq_mode_on = KAL_TRUE;
   return KAL_TRUE;
}

kal_bool PWM_Seq_Close(kal_uint8 owner)
{
   kal_uint32     idx;
   pwm_handle_s   *handle;

   if (pwm_seq_owner!=owner)
   {
      ASSERT(0);
      return KAL_FALSE;
   }
   handle = pwm_handle_array+PWM3;
   for (idx=PWM3; idx < PWM_COUNT; idx++)
   {
      if (handle->is_start == KAL_TRUE)
      {
         PWM_Stop(owner, idx);
         handle->is_start = KAL_FALSE;
      }
      handle->owner = PWM_OWNER_NONE;
      handle->mode = PWM_MODE_COUNT;
      handle->pwm_cb = NULL;
      handle->pwm_invalid_cb = NULL;
      handle++;
   }
   pwm_seq_owner = PWM_OWNER_NONE;
   pwm_seq_mode_on = KAL_FALSE;
   return KAL_TRUE;
}

void PWM_Config_Old(kal_uint8 owner, kal_uint32 pwm_num, kal_uint32 freq, kal_uint8 duty)
{
   kal_uint32 clock;
   kal_uint32 tmp;
   kal_uint16 clkdiv;
   kal_uint16 reg;
   pwm_old_para_s   old_para;
   pwm_old_para_s   *old_para_p;
      
   old_para_p = &old_para;
   ASSERT(duty <= 100);

   reg = DRV_Reg(PWM1_CON+0x40*pwm_num);
   
   clkdiv = (1 << ((reg & PWM_CON_CLKDIV_MASK)>>PWM_CON_CLKDIV_SHIFT));
   
   if (reg & PWM_CON_CLKSEL_MASK)
      clock = 32000;
   else
      clock = 52000000;
   
   clock = clock/clkdiv;
   
   if(0==freq)
      tmp = clock/(freq+1);
   else 
      tmp = clock/(freq); 
   
   tmp--;
   old_para_p->data_width = tmp;
   tmp = ((tmp+1)*duty)/100;
   old_para_p->threshold = tmp;
   old_para_p->repeat_count = 0;
   old_para_p->guard_dur = 0;
   old_para_p->idle_output =  PWM_OUTPUT_LOW;
   old_para_p->guard_output = PWM_OUTPUT_LOW;
   old_para_p->pwm_callback = 0;
   PWM_Configure(owner, pwm_num, PWM_OLD_MODE, (void *)old_para_p);
}

void PWM1_Configure(kal_uint32 freq, kal_uint8 duty)
{
   pwm_handle_s   *handle;

   handle = pwm_handle_array+PWM1;
   ASSERT(handle->owner != PWM_OWNER_NONE);
   PWM1_FRE_SAVE=freq;
   PWM1_DUTY_SAVE=duty;
   PWM_Config_Old(handle->owner, PWM1, freq, duty);
}
/*duty=50 ==> 50%*/
void PWM1_Start(void)
{
   pwm_handle_s   *handle;

   handle = pwm_handle_array+PWM1;
   ASSERT(handle->owner != PWM_OWNER_NONE);
   PWM_Start(handle->owner, PWM1);
}

void PWM1_Stop(void)
{
   pwm_handle_s   *handle;

   handle = pwm_handle_array+PWM1;
   ASSERT(handle->owner != PWM_OWNER_NONE);
   PWM_Stop(handle->owner, PWM1);
}

void PWM2_Configure(kal_uint32 freq, kal_uint8 duty)
{
   pwm_handle_s   *handle;

   handle = pwm_handle_array+PWM2;
   ASSERT(handle->owner != PWM_OWNER_NONE);
   PWM2_FRE_SAVE=freq;
   PWM2_DUTY_SAVE=duty;
   PWM_Config_Old(handle->owner, PWM2, freq, duty);
}
/*duty=50 ==> 50%*/
void PWM2_Start(void)
{
   pwm_handle_s   *handle;

   handle = pwm_handle_array+PWM2;
   ASSERT(handle->owner != PWM_OWNER_NONE);
   PWM_Start(handle->owner, PWM2);
}

void PWM2_Stop(void)
{
   pwm_handle_s   *handle;

   handle = pwm_handle_array+PWM2;
   ASSERT(handle->owner != PWM_OWNER_NONE);
   PWM_Stop(handle->owner, PWM2);
}

void PWM3_Configure(kal_uint32 freq, kal_uint8 duty)
{
#ifdef __PWM3_FOR_MMI__
   pwm_handle_s   *handle;

   handle = pwm_handle_array+PWM3;
   ASSERT(handle->owner != PWM_OWNER_NONE);
   PWM3_FRE_SAVE=freq;
   PWM3_DUTY_SAVE=duty;
   PWM_Config_Old(handle->owner, PWM3, freq, duty);
#endif /*__PWM3_FOR_MMI__*/
}
/*duty=50 ==> 50%*/
void PWM3_Start(void)
{
#ifdef __PWM3_FOR_MMI__
   pwm_handle_s   *handle;

   handle = pwm_handle_array+PWM3;
   ASSERT(handle->owner != PWM_OWNER_NONE);
   PWM_Start(handle->owner, PWM3);
#endif /*__PWM3_FOR_MMI__*/
}

void PWM3_Stop(void)
{
#ifdef __PWM3_FOR_MMI__
   pwm_handle_s   *handle;

   handle = pwm_handle_array+PWM3;
   ASSERT(handle->owner != PWM_OWNER_NONE);
   PWM_Stop(handle->owner, PWM3);
#endif /*__PWM3_FOR_MMI__*/
}

/*level = 1~5, level = 0, close PWM*/
void PWM_level(kal_uint8 level)
{
   if (level > 5)
      ASSERT(0);
   
   PWM1_LEVEL_SAVE = level;
   if (level)
   {
      PWM1_Configure(PWM1_Level_Info[level-1][0],PWM1_Level_Info[level-1][1]);
      PWM1_Start();
   }
   else
   {
      PWM1_Stop();
   }
}

void PWM2_level(kal_uint8 level)
{
   if (level > 5)
      ASSERT(0);
   
   PWM2_LEVEL_SAVE = level;
   if (level)
   {
      PWM2_Configure(PWM2_Level_Info[level-1][0],PWM2_Level_Info[level-1][1]);
      PWM2_Start();
   }
   else
   {
      PWM2_Stop();
   }
}

void PWM3_level(kal_uint8 level)
{
#ifdef __PWM3_FOR_MMI__
   if (level > 5)
      ASSERT(0);
   
   PWM3_LEVEL_SAVE = level;
   if (level)
   {
      PWM3_Configure(PWM3_Level_Info[level-1][0],PWM3_Level_Info[level-1][1]);
      PWM3_Start();
   }
   else
   {
      PWM3_Stop();
   }
#endif /*__PWM3_FOR_MMI__*/
}

kal_uint8 PWM1_GetCurrentLevel(void)
{
   return PWM1_LEVEL_SAVE;
}
kal_uint32 PMW1_GetCurrentFreq(void)
{   
   return PWM1_FRE_SAVE;   
}   
kal_uint8 PMW1_GetCurrentDuty(void)
{   
   return PWM1_DUTY_SAVE;     
}

kal_uint8 PWM2_GetCurrentLevel(void)
{
   return PWM2_LEVEL_SAVE;
}
kal_uint32 PMW2_GetCurrentFreq(void)
{
   return PWM2_FRE_SAVE;      
}   
kal_uint8 PMW2_GetCurrentDuty(void)
{
   return PWM2_DUTY_SAVE;      
}   

/* For PWM3~PMW6 general frequncey and duty waveform. */
typedef struct {
   kal_uint32  freq;
   kal_uint16  steps;
} pwm_freq_steps;

static pwm_freq_steps   pwm_freq_steps_array[PWM_COUNT-PWM2];

void PWM_Config_Freq_Steps(kal_uint8 owner, kal_uint32 pwm_num, kal_uint32 freq, kal_uint16 steps)
{
   pwm_handle_s   *handle;

   handle = pwm_handle_array+pwm_num;
   if ((pwm_num <= PWM2) || (pwm_num > PWM6) || (handle->owner!=owner))
   {
      ASSERT(0);
      return;
   }
   pwm_freq_steps_array[pwm_num-PWM3].freq = freq;
   pwm_freq_steps_array[pwm_num-PWM3].steps = steps;
}

void PWM_Set_Duty(kal_uint8 owner, kal_uint32 pwm_num, kal_uint16 duty)
{
   kal_uint32 clock;
   kal_uint32 tmp;
   kal_uint16 clkdiv;
   kal_uint16 reg;
   pwm_fifo_para_s   fifo_para;
   pwm_fifo_para_s   *fifo_para_p;
   pwm_freq_steps    *freq_steps_p;
   pwm_handle_s      *handle;
      
   handle = pwm_handle_array+pwm_num;
   if ((pwm_num <= PWM2) || (pwm_num > PWM6) || (handle->owner!=owner))
   {
      ASSERT(0);
      return;
   }
   freq_steps_p = pwm_freq_steps_array+(pwm_num-PWM3);
   if (duty > freq_steps_p->steps)
   {
      ASSERT(0);
      return;
   }
   fifo_para_p = &fifo_para;
   reg = DRV_Reg(PWM1_CON+0x40*pwm_num);
   clkdiv = (1 << ((reg & PWM_CON_CLKDIV_MASK)>>PWM_CON_CLKDIV_SHIFT));
   
   if (reg & PWM_CON_CLKSEL_MASK)
      clock = 32000;
   else
      clock = 52000000;
   
   clock = clock/clkdiv;
   
   if(0==freq_steps_p->freq)
      freq_steps_p->freq++;
   tmp = clock/freq_steps_p->freq;
   if (duty == freq_steps_p->steps)
      fifo_para_p->data0 = 0xffffffff;
   else if (duty == 0)
      fifo_para_p->data0 = 0;
   else
      fifo_para_p->data0 = 0x55555555;

   fifo_para_p->data1 = 0;
   fifo_para_p->repeat_count = 0;
   fifo_para_p->stop_bitpos = 31;
   fifo_para_p->high_dur = tmp*duty/freq_steps_p->steps;  
   fifo_para_p->low_dur = tmp*(freq_steps_p->steps-duty)/freq_steps_p->steps;
   if (fifo_para_p->high_dur > 1)
   {
      fifo_para_p->high_dur--;
   }
   else if (fifo_para_p->high_dur==0)
   {
      fifo_para_p->high_dur++;
   }
   if (fifo_para_p->low_dur > 1)
   {
      fifo_para_p->low_dur--;
   }
   else if (fifo_para_p->low_dur==0)
   {
      fifo_para_p->low_dur++;
   }
   fifo_para_p->guard_dur = 0;
   fifo_para_p->idle_output = PWM_OUTPUT_LOW;
   fifo_para_p->guard_output = PWM_OUTPUT_LOW;
   fifo_para_p->pwm_callback = NULL;
   PWM_Configure(owner, pwm_num, PWM_FIFO_MODE, (void *)fifo_para_p);
}

#endif  /* defined(DRV_PWM_RWG) */
