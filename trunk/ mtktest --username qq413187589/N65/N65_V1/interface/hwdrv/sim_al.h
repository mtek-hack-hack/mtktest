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
 *    sim_al.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is used for including files for AL_SIM
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
#ifndef SIM_AL_H
#define SIM_AL_H




//#define TEST						/* test option for win32 simulation */
/*Besnon 20040407 add for Jensen's request*/
#define CHECK_30VSIM          0x10	/* 3V technical SIM */
#define CHECK_18VSIM          0x20   /* 1.8V technical SIM */
#define RESET_18V           0  /* Driver reset result = 1.8V */
#define RESET_30V                  1  /* Driver reset result = 3V */
/*End Benson 20040407*/
#define CHECK_CLOCK_MODE     0x0D	/* bit mask for SIM clock mode */ 

#define SIM_NO_ERROR            0	/* return value for SIM no error found */
#define SIM_NO_INSERT           1	/* return value for no SIM insert */	
#define SIM_CARD_ERROR          3	/* return value for SIM error found */

#define CLOCK_STOP_AT_HIGH   0x00	/* config SIM colck stop at high */  
#define CLOCK_STOP_AT_LOW    0x01	/* config SIM clock stop at low */
#define CLOCK_STOP_NOT_ALLOW 0x02	/* config SIM clock stop not allowed */

/* Define SIM command instruction ID */
#define GSM_CLS              0xA0
#define CMD_SELECT           0xA4
#define CMD_GETRES           0xC0
#define CMD_STATUS           0xF2
#define CMD_READB            0xB0
#define CMD_UPDATEB          0xD6
#define CMD_READR            0xB2
#define CMD_UPDATER          0xDC
#define CMD_INCREASE         0x32
#define CMD_VERIFYCHV        0x20
#define CMD_CHANGECHV        0x24
#define CMD_DISABLECHV       0x26
#define CMD_ENABLECHV        0x28
#define CMD_UNBLOCKCHV       0x2C
#define CMD_INVALIDATE       0x04
#define CMD_REHABILITATE     0x44
#define CMD_RUNGSMALGO       0x88
#define CMD_TERMINALPRO      0x10
#define CMD_TERMINALRES      0x14
#define CMD_ENVELOPE         0xC2
#define CMD_FETCH            0x12

/* define SIM file ID */
#define SIM_DF_GSM         0x7F20
#define SIM_DF_1800        0x7F21

typedef enum
{
	ME_UNKNOW =0,
	ME_18V_30V,
	ME_30V_ONLY,
	ME_18V_ONLY
} sim_env;

typedef enum
{
	sim_card_normal_speed = 0,
	sim_card_enhance_speed_64,
	sim_card_enhance_speed_32
} sim_card_speed_type;

/* define ATR data Structure */
typedef struct
{
  kal_uint8          info [40];
} AtrStruct;

#ifndef DRV_MULTIPLE_SIM
extern kal_uint8	 L1sim_Reset (kal_uint8 resetVolt, kal_uint8 *resultVolt,AtrStruct *Info);
extern void	 L1sim_Configure (kal_uint8 clockMode);
extern kal_uint16 L1sim_Cmd(kal_uint8  *txData,kal_uint16  txSize,kal_uint8  *result,kal_uint16  *rcvSize, kal_uint8 *Error);
extern void	 L1sim_PowerOff(void);
extern void	 L1sim_Init(void);               
extern sim_env SIM_GetCurrentEnv(void);
#endif

#endif /*SIM_AL_H*/


