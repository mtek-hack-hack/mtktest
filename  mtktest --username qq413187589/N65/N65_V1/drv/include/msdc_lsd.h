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
 *   msdc_lsd.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   header file of software SD/MMC controller interface 
 *   
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================ 
 ****************************************************************************/
 #ifndef MSDC_LSD_H
 #define MSDC_LSD_H


 /*following 2 definitions should be defined in this file*/
#define LSD_HPI
#define LSD_CONTROLLER


#define	LSD_LCDARB_FREE	0
#define	LSD_LCDARB_LCD	1
#define	LSD_LCDARB_SD		2

/*DRV_LSD macro definition*/
#define	LSD_MSDC_CFG	0
#define	LSD_MSDC_STA	1
#define	LSD_MSDC_INT	2
#define	LSD_MSDC_DAT	3 
#define	LSD_MSDC_PS		4
#define	LSD_MSDC_IOCON	5
#define	LSD_SDC_CFG		6
#define	LSD_SDC_CMD		7
#define	LSD_SDC_ARG		8
#define	LSD_SDC_STA		9
#define	LSD_SDC_RESP0	10
#define	LSD_SDC_RESP1	11
#define	LSD_SDC_RESP2	12
#define	LSD_SDC_RESP3	13
#define	LSD_SDC_CMDSTA	14
#define	LSD_SDC_DATSTA	15
#define	LSD_SDC_CSTA	16
#define	LSD_SDC_IRQMASK0	17
#define	LSD_SDC_IRQMASK1	18
#define	LSD_CMD47_46	0x40
#define	LSD_CMD55		0x37
#define	LSD_CMD41		0x29

typedef enum {
	LSD_SPEED_INIT = 0,
	LSD_SPEED_26M = 2,
	LSD_SPEED_52M = 3
} T_LSD_SPEED;

typedef enum {
	LSD_cardInsertion = 0,
	LSD_cardRemoval = 1
}T_LSD_CardDetection;

typedef enum {
	LSD_MSDCCLKBPI2 = 0,
	LSD_MSDCCLKBPI3 = 1
}T_LSD_MSDCCLK;





extern kal_uint32 LSD_dbgInfo[];
extern kal_uint32 LSD_dbgInfoIndex;
#define LSD_DBG_INFO_NUM	128

#define LSD_NOT_SUPPORTED 0x1

void LSD_HISR_Registration(void);
kal_bool LSD_Support(void);
void LSD_SetBit32(kal_uint32 address,kal_uint32 maskValue);
void LSD_ClrBit32(kal_uint32 address,kal_uint32 maskValue);
void LSD_WriteReg32(kal_uint32 address, kal_uint32 data);
void LSD_ReadReg16(kal_uint32 adrs, kal_uint16 *pdata);
void LSD_ReadReg32(kal_uint32 adrs, kal_uint32 *pdata);
kal_uint32 LSD_Reg32(kal_uint32 adrs);
void LSD_PDNControl(kal_bool ON);
void LSD_CLR_FIFO(void);
void LSD_Reset(void);
kal_uint32 LSD_IS_BUSY(void);
void LSD_HostSetClock(int speed);
void LSD_readFIFO(kal_uint32 *adrs, kal_uint32 count);
void LSD_HostSetBuffer(kal_uint8 *datPtr);
T_LSD_CardDetection LSD_cardDetection(void);

/*following APIs is provided to FMT, DMT cant see DRV_LSD, can't use DRV_LSD seperate*/
#ifdef __MTK_TARGET__
void MSDC_unsealMountOperation(void);
void NotifyFMTWhenCardPresent(void);
void LSD_Slower(kal_uint8 slowFactor);
#else
#define MSDC_unsealMountOperation()
#define NotifyFMTWhenCardPresent()
#define LSD_Slower(a)
#endif

#ifdef DRV_LSD
#define LSD_STOP_IMMEDIATLY //this should only be seen in DRV_LSD scope, can't be seen in other platform

void LSD_TakeControl(kal_uint32 owner);
void LSD_GiveControl(kal_uint32 owner);
void LSD_startFastFormat(void);
void LSD_closeFastFormat(void);
#else
#define LSD_startFastFormat
#define LSD_closeFastFormat
#define LSD_TakeControl(a)
#define LSD_GiveControl(a)
#endif

 #endif
