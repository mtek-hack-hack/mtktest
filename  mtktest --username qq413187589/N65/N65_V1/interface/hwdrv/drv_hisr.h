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
 * Filename:
 * ---------
 *	drv_hisr.h
 *
 * Project:
 * --------
 *   ALL
 *
 * Description:
 * ------------
 *   This file is intends for central driver HISR.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _DRV_HISR_H
#define _DRV_HISR_H

#define MAX_DRV_HISR_DBG_INFO_SIZE 64	/*must be 2^n*/

typedef struct{
   kal_uint16      tag;
   kal_uint32      time;
}DRV_HISR_DBG_DATA;

typedef struct{
   DRV_HISR_DBG_DATA   	dbg_data[MAX_DRV_HISR_DBG_INFO_SIZE];
   kal_uint16     		dbg_data_idx;
}DRV_HISR_DBG_STRUCT;

typedef enum {
   DRV_EINT_HISR_ID=0,
   DRV_GPT_HISR_ID,
   DRV_DMA_HISR_ID,
   DRV_USB_HISR_ID,
   DRV_USBDMA_HISR_ID,
   DRV_USB_LOGGING_3G_HISR_ID,
   DRV_USB_LOGGING_DSP_HISR_ID,
   DRV_IRDBG_HISR_ID,
   DRV_IRDA_HISR_ID,
   DRV_UART1_HISR_ID,
   DRV_UART2_HISR_ID,
   DRV_UART3_HISR_ID,
   DRV_SIM_HISR_ID,
   DRV_MSDC_HISR_ID,
   DRV_RTC_HISR_ID,
   DRV_KP_HISR_ID,
   DRV_LCD_HISR_ID,
   DRV_NFI_HISR_ID,
   DRV_NIRQ_HISR_ID,
   DRV_NFIQ_HISR_ID,
   DRV_SPI_HISR_ID,
   DRV_CHE_HISR_ID,
   DRV_SWDBG_HISR_ID,
   DRV_USIM_HSIR_ID,
   DRV_PWM_HISR_ID,
   DRV_AUXADC_HISR_ID,
   DRV_MSDC2_HISR_ID,
   MAX_DRV_HISR_DEVICE,
   DRV_UNKNOWN_HISR_ID = 0xfe
} DRV_HISR_ID;

typedef struct {
   VOID_FUNC   hisr_func;
   kal_uint16  hisr_count;
} DRV_HISR_STRUCT;

#define drv_active_hisr(_id)  \
{\
   kal_uint32 _savedMask;\
   _savedMask = SaveAndSetIRQMask();\
   drv_hisr_status |= (1<<_id);\
   DRV_HISR_TABLE[_id].hisr_count++;\
   RestoreIRQMask(_savedMask);\
   kal_activate_hisr(drv_hisr);\
}

typedef void (* VOID_FUNCTION)(void);
extern kal_hisrid drv_hisr;
extern kal_uint64 drv_hisr_status;
extern DRV_HISR_STRUCT DRV_HISR_TABLE[MAX_DRV_HISR_DEVICE];

extern void DRV_Register_HISR(kal_uint8 hisr_id, VOID_FUNCTION hisr_func);
extern void DRV_HISR(void);
extern void drv_hisr_init(void);
#endif   /*_DRV_HISR_H*/

