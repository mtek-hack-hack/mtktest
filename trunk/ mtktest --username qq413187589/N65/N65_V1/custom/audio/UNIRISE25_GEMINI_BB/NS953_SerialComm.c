/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*******************************************************************************/

/*******************************************************************************
 *
 * Filename:
 * ---------
 * NS953_SerialComm.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
 *      Serial communication interfaces (I2C protocol)
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
 *==============================================================================
  *******************************************************************************/
#if (defined(NS953))
#include "l1audio_def.h"

/* GPIO definition */
#define SDA 9    /* MT6227EVB : 9 */
#define SCL 8    /* MT6227EVB : 8 */
#define CRYCLK 12    /* MT6227EVB: 12 */

void GPIO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada);
void GPIO_InitIO(char direction, char port);
void GPIO_WriteIO(char data,char port);
char GPIO_ReadIO(char port);

uint8 const FM_RADIO_INPUT_LEVEL_THRESHOLD = 1;

void SerialCommStart(void) /* start or re-start */
{
   GPIO_WriteIO(0,SCL);
   GPIO_InitIO(1,SDA);
   GPIO_WriteIO(1,SDA);
   GPIO_WriteIO(1,SCL);
   GPIO_WriteIO(0,SDA);   /* start condition */
}

void SerialCommStop(void)
{
   GPIO_WriteIO(0,SCL);
   GPIO_InitIO(1,SDA);
   GPIO_WriteIO(0,SDA);
   GPIO_WriteIO(1,SCL);
   GPIO_WriteIO(1,SDA); /* stop condition */
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
   GPIO_InitIO(1,SCL);
}

void SerialCommCryClkOn(void)
{
   GPIO_ModeSetup(CRYCLK,3); /* 32.768kHz reference frequency */
}

void SerialCommCryClkOff(void)
{
   GPIO_ModeSetup(CRYCLK,0);
}

#endif
