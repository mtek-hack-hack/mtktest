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
 *    gpt_sw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intends for GPT driver.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef GPT_SW_H
#define GPT_SW_H

#define gptimer_num        1
#define gptimer_interval   10

typedef enum 
{
	clk_16k,
	clk_8k,
	clk_4k,
	clk_2k,
	clk_1k,
	clk_500,
	clk_250,
	clk_125
}gpt_clock;

typedef struct 
{
	void (*gpt1_func)(void);
	void (*gpt2_func)(void); 
}gpt_func;

typedef struct 
{
	kal_uint16   tick;
	void     (*gptimer_func)(void *parameter);
	void     *parameter;
}gptimer_item;

typedef struct
{
   kal_uint32     status;  /*1,used ,0:unused*/
   kal_bool       GPTSTOP;
   kal_uint16     GPT_TICK;
   kal_uint8      MAX_GPTIMER_ITEMS;
   gptimer_item   GPTItems[32];  /*support at most 32 gptimer*/
   gpt_func       GPT_FUNC;
   kal_hisrid     hisr;
} GPTStruct;  

#define  GPTProcess(module)   \
{\
   if((GPTTimer.status & (1<<module))&&(GPTTimer.GPT_TICK == GPTTimer.GPTItems[module].tick))\
   {\
      GPTTimer.status &= ~(1<<module);\
      GPTTimer.GPTItems[module].gptimer_func(GPTTimer.GPTItems[module].parameter);\
   }\
}

extern void GPT_clock(kal_uint8 timerNum ,gpt_clock clock);
extern void GPT_ResetTimer(kal_uint8 timerNum,kal_uint16 countValue,kal_bool autoReload);
extern void GPT_Start(kal_uint8 timerNum);
extern void GPT_Stop(kal_uint8 timerNum);
extern void GPT_init(kal_uint8 timerNum, void (*GPT_Callback)(void));
extern void GPT_LISR(void);
extern kal_uint8 GPTI_GetHandle(kal_uint8 *handle);
extern kal_bool GPTI_StartItem(kal_uint8 module,kal_uint16 tick,void (*gptimer_func)(void *),void *parameter);
extern void GPTI_StopItem(kal_uint8 module);
#if defined(DRV_GPT_GPT3)
extern kal_uint16 GPT_return_current_count(void);
extern void GPT3_Init(void);
#endif

#endif


