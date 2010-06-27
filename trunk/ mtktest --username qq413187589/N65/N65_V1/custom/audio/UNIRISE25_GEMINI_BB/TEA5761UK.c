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
 *
 * Filename:
 * ---------
 * TEA5761UK.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
 *      TEA5761UK Driver
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
*********************************************************************************/
#include "l1audio_def.h"
#include "sccb.h"

#if (defined(TEA5761UK))
/* GPIO definition */
#define SDA 9    /* EV200 : 9 */
#define SCL 8   /* EV200 :  8 */
#define CRYCLK 41    /* EV200 : 41  */
#define BUSENABLE 1   /* EV200 : 1 */

extern void GPIO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada);
extern void GPIO_InitIO(char direction, char port);
extern void GPIO_WriteIO(char data,char port);
extern char GPIO_ReadIO(char port);

uint8 const FM_RADIO_INPUT_LEVEL_THRESHOLD = 1;

/*       ______        */
/*  SDA        |       */
/*             |____   */
/*          ________   */
/*  SCL     |          */
/*     _____|          */

void SerialCommStart(void) /* start or re-start */
{
   GPIO_WriteIO(1,BUSENABLE);  /* bus enabled */
   GPIO_WriteIO(0,SCL);
   GPIO_InitIO(1,SDA);
   GPIO_WriteIO(1,SDA);
   GPIO_WriteIO(1,SCL);
   GPIO_WriteIO(0,SDA);   /* start condition */
}

/*              ____   */
/*  SDA        |       */
/*       ______|       */
/*          ________   */
/*  SCL     |          */
/*     _____|          */

void SerialCommStop(void)
{
   GPIO_WriteIO(0,SCL);
   GPIO_InitIO(1,SDA);
   GPIO_WriteIO(0,SDA);
   GPIO_WriteIO(1,SCL);
   GPIO_WriteIO(1,SDA); /* stop condition */
   GPIO_WriteIO(0,BUSENABLE); /* bus disabled */
   
}

void SerialCommPullHigh(void)
{
   GPIO_ModeSetup(SCL,0);
   GPIO_ModeSetup(SDA,0);
   GPIO_InitIO(1,SDA);
   GPIO_InitIO(1,SCL);
   GPIO_WriteIO(1,SDA);
   GPIO_WriteIO(1,SCL);
}

void SerialCommPullLow(void)
{
   GPIO_ModeSetup(SCL,0);
   GPIO_ModeSetup(SDA,0);
   GPIO_InitIO(1,SDA);
   GPIO_InitIO(1,SCL);
   GPIO_WriteIO(0,SCL);
   GPIO_WriteIO(0,SDA);
}

uint8 SerialCommTxByte(uint8 data) /* return 0 --> ack */
{
   int32 i;
   
   for(i=7; i>=0; i--){
      GPIO_WriteIO( 0, SCL); /* low */
   /* The bus operates at a maximum clock frequency of 400 kHz */
      if(i==7)GPIO_InitIO(1,SDA);  // dummy
      GPIO_WriteIO(((data>>i)&0x01), SDA);
      GPIO_WriteIO( 1, SCL); /* high */
   }
   GPIO_WriteIO(0, SCL); /* low */
   GPIO_InitIO(0,SDA);
   GPIO_WriteIO(1, SCL); /* high */
   return GPIO_ReadIO(SDA);
}

void SerialCommRxByte(uint8 *data, uint8 ack)
{
   int32 i;
   uint32 dataCache;

   dataCache = 0;
   for(i=7; i>=0; i--){
      GPIO_WriteIO(0, SCL);
      if(i==7)GPIO_InitIO(0,SDA);
      { // For EV200 only, solve a hardware bug
      	kal_int32 cnt;  // dummy for_loop
      	for(cnt=0; cnt<20; cnt++);
      }
      GPIO_WriteIO(1, SCL);
      dataCache |= (GPIO_ReadIO(SDA)<<i);
   }
   GPIO_WriteIO(0, SCL);
   GPIO_InitIO(1,SDA);
   GPIO_WriteIO(ack, SDA);
   GPIO_WriteIO(1, SCL);
   *data = (uint8)dataCache;
}

void SerialCommInit(void)
{
   GPIO_ModeSetup(SCL,0);
   GPIO_ModeSetup(SDA,0);
   GPIO_ModeSetup(BUSENABLE,0);
   GPIO_InitIO(1,SCL);
   GPIO_InitIO(1,BUSENABLE);
}

void SerialCommCryClkOn(void)
{
   GPIO_ModeSetup(CRYCLK,3); /* 32.768kHz reference frequency */
}

void SerialCommCryClkOff(void)
{
   GPIO_ModeSetup(CRYCLK,0);
   SerialCommPullLow(); // For EV200 only, solve a hardware bug
}

void SerialCommCAMReset(void)
{  // For EV200 only, solve a hardware bug
   init_isp_if();
   kal_sleep_task(4);
   power_off_isp();
   SerialCommPullHigh();
}

#endif // defined(TEA5761UK)