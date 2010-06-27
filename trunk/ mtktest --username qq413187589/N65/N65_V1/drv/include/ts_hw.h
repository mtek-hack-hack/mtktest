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
 *    tp_hw.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef TP_HW_H
#define TP_HW_H
#include "drv_features.h"
#if defined(DRV_ADC_TOUCH_SCREEN)
   #define AUX_TS_DEBT                   (AUXADC_base+0x0030)
   #define AUX_TS_CMD                    (AUXADC_base+0x0034)
   #define AUX_TS_CON                    (AUXADC_base+0x0038)
   #define AUX_TS_DATA0                  (AUXADC_base+0x003c)

#define TS_DEBT_MASK           0x3fff

#define TS_CMD_PD_MASK         0x0003
   #define TS_CMD_PD_YDRV_SH     0x0000
   #define TS_CMD_PD_IRQ_SH      0x0001
   #define TS_CMD_PD_IRQ         0x0003
#define TS_CMD_SE_DF_MASK      0x0004
   #define TS_CMD_DIFFERENTIAL   0x0000
   #define TS_CMD_SINGLE_END     0x0004
#define TS_CMD_MODE_MASK       0x0008
   #define TS_CMD_MODE_10BIT     0x0000
   #define TS_CMD_MODE_8BIT      0x0008
#define TS_CMD_ADDR_MASK       0x0070
   #define TS_CMD_ADDR_Y         0x0010
   #define TS_CMD_ADDR_Z1        0x0030
   #define TS_CMD_ADDR_Z2        0x0040
   #define TS_CMD_ADDR_X         0x0050

#define TS_CON_SPL_MASK        0x0001
   #define TS_CON_SPL_TRIGGER    0x0001
#define TS_CON_STATUS_MASK     0x0002

#define TS_DAT0_DAT_MASK       0x03ff

#endif /*defined(DRV_ADC_TOUCH_SCREEN)*/

#endif   /*TP_HW_H*/

