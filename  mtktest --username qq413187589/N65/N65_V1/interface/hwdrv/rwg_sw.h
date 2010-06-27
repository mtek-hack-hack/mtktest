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
 *    rwg_sw.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef RWG_SW_H
#define RWG_SW_H

#include "drv_features.h"

#if defined(DRV_PWM_RWG)

typedef enum 
{
	PWM_OWNER_UEM=0,
   PWM_OWNER_AF,
	PWM_OWNER_NONE=0xff
}pwm_owner_e;

typedef enum 
{
	PWM_CLK_DIV_NONE=0,
	PWM_CLK_DIV_2=1,
	PWM_CLK_DIV_4=2,
	PWM_CLK_DIV_8=3,
	PWM_CLK_DIV_16=4,
	PWM_CLK_DIV_32=5,
	PWM_CLK_DIV_64=6,
	PWM_CLK_DIV_128=7
}pwm_clk_div_e;

typedef enum 
{
	PWM_CLK_SEL_52M=0,
	PWM_CLK_SEL_32K=1
}pwm_clk_sel_e;

typedef enum 
{
	PWM1=0,
	PWM2,
	PWM3,
	PWM4,
	PWM5,
	PWM6,
   PWM_COUNT
}pwm_num_e;

typedef enum
{
   PWM_FIFO_MODE=0,
   PWM_MEMO_MODE,
   PWM_OLD_MODE,
   PWM_RANDOM_MODE,
   PWM_MODE_COUNT
} pwm_mode_e;

typedef enum
{
   PWM_SEQ_EN_PWM3=0x1,
   PWM_SEQ_EN_PWM34=0x03,
   PWM_SEQ_EN_PWM35=0x05,
   PWM_SEQ_EN_PWM345=0x07,
   PWM_SEQ_EN_PWM36=0x09,
   PWM_SEQ_EN_PWM346=0x0b,
   PWM_SEQ_EN_PWM356=0x0d,
   PWM_SEQ_EN_PWM3456=0x0f
} pwm_seq_en_cnt_e;

typedef enum
{
   PWM_BUF_INVALID_NONE=0,
   PWM_BUF_0_INVALID,
   PWM_BUF_1_INVALID,
   PWM_BUF_0_1_INVALID
} pwm_buf_invalid_e;

#define   PWM_OUTPUT_LOW   0
#define   PWM_OUTPUT_HIGH  1


typedef struct 
{
   kal_uint32 data0;
   kal_uint32 data1;
   kal_uint16 repeat_count; /* 0 means endless repeat */
   kal_uint8  stop_bitpos; /* 0~63*/
   kal_uint16 high_dur; /* must>0. When set to N, the duration is N+1 clocks. */
   kal_uint16 low_dur; /* must>0. When set to N, the duration is N+1 clocks. */
   kal_uint16 guard_dur; /* must>0. When set to N, the duration is N+1 clocks. */
   kal_uint8  idle_output; /* PWM_OUTPUT_LOW or PWM_OUTPUT_HIGH */
   kal_uint8  guard_output; /* PWM_OUTPUT_LOW or PWM_OUTPUT_HIGH */
   void       (*pwm_callback)(kal_uint32 pwm_num);
}pwm_fifo_para_s;

typedef struct 
{
   kal_uint32 *buf_addr;
   kal_uint16 buf_size;
   kal_uint16 repeat_count; /* 0 means endless repeat */
   kal_uint8  stop_bitpos; /* 0~31 in the last 32bits*/
   kal_uint16 high_dur; /* must>0. When set to N, the duration is N+1 clocks. */
   kal_uint16 low_dur; /* must>0. When set to N, the duration is N+1 clocks. */
   kal_uint16 guard_dur; /* must>0. When set to N, the duration is N+1 clocks. */
   kal_uint8  idle_output; /* PWM_OUTPUT_LOW or PWM_OUTPUT_HIGH */
   kal_uint8  guard_output; /* PWM_OUTPUT_LOW or PWM_OUTPUT_HIGH */
   void       (*pwm_callback)(kal_uint32 pwm_num);
}pwm_memo_para_s;

typedef struct 
{
   kal_uint16 data_width;
   kal_uint16 threshold;
   kal_uint16 repeat_count; /* 0 means endless repeat */
   kal_uint16 guard_dur; /* must>0. When set to N, the duration is N+1 clocks. */
   kal_uint8  idle_output; /* PWM_OUTPUT_LOW or PWM_OUTPUT_HIGH */
   kal_uint8  guard_output; /* PWM_OUTPUT_LOW or PWM_OUTPUT_HIGH */
   void       (*pwm_callback)(kal_uint32 pwm_num);
}pwm_old_para_s;

typedef struct 
{
   kal_uint32 *buf0_addr;
   kal_uint32 *buf1_addr;
   kal_uint16 buf0_size; /* must>0 */
   kal_uint16 buf1_size; /* must>0 */
   kal_uint16 high_dur; /* must>0. When set to N, the duration is N+1 clocks. */
   kal_uint16 low_dur; /* must>0. When set to N, the duration is N+1 clocks. */
   kal_uint8  idle_output; /* PWM_OUTPUT_LOW or PWM_OUTPUT_HIGH */
   void       (*pwm_invalid_cb)(kal_uint32 pwm_num, kal_uint8 buf_num);
   void       (*pwm_underflow_cb)(kal_uint32 pwm_num);
}pwm_random_para_s;

extern void PWM_Init(void);
extern kal_bool PWM_Open(kal_uint8 owner, kal_uint32 pwm_num);
extern kal_bool PWM_Seq_Open(kal_uint8 owner);
extern kal_bool PWM_Close(kal_uint8 owner, kal_uint32 pwm_num);
extern kal_bool PWM_Seq_Close(kal_uint8 owner);
extern void PWM_CLK_Init(kal_uint8 owner, kal_uint32 pwm_num, kal_uint32 clk_sel, kal_uint32 clk_div);
extern kal_bool PWM_Configure(kal_uint8 owner, kal_uint32 pwm_num, kal_uint32 mode, void *para);
extern void PWM_Start(kal_uint8 owner, kal_uint32 pwm_num);
extern void PWM_Stop(kal_uint8 owner, kal_uint32 pwm_num);

/* Below are for Sequence mode */
extern void PMW_Set_Delay(kal_uint8 owner, kal_uint32 pwm_num, kal_uint32 clk_sel, kal_uint16 delay_cnt);
extern void PWM_Seq_Start(kal_uint8 owner, kal_uint8 en_cnt);
extern void PWM_Seq_Stop(kal_uint8 owner);
//extern kal_uint32 PWM_Check_Buf_Valid(kal_uint32 pwm_num);
extern void PWM_Set_Buf_Valid(kal_uint8 owner, kal_uint32 pwm_num, kal_uint32 *buf_addr, kal_uint16 buf_size, kal_bool is_buf0);

/* Below are for OLD PWM backward compatibility. */
extern void PWM1_Configure(kal_uint32 freq, kal_uint8 duty);
extern void PWM2_Configure(kal_uint32 freq, kal_uint8 duty);
extern void PWM3_Configure(kal_uint32 freq, kal_uint8 duty);
extern void PWM1_Start(void);
extern void PWM2_Start(void);
extern void PWM3_Start(void);
extern void PWM1_Stop(void);
extern void PWM2_Stop(void);
extern void PWM3_Stop(void);

extern kal_uint8  PWM1_GetCurrentLevel(void);
extern kal_uint8  PMW1_GetCurrentDuty(void);
extern kal_uint32 PMW1_GetCurrentFreq(void);
extern kal_uint8  PWM2_GetCurrentLevel(void);
extern kal_uint8  PMW2_GetCurrentDuty(void);
extern kal_uint32 PMW2_GetCurrentFreq(void);

#endif  /* defined(DRV_PWM_RWG) */

#endif

