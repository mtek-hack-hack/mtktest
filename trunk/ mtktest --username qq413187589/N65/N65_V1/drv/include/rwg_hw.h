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
 *    rwg_hw.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef RWG_HW_H
#define RWG_HW_H
#include "drv_features.h"

#if defined(DRV_PWM_RWG)

#define 	PWM_ENABLE		      (PWM_base+0x0000) /* PWM Enable           */
#define 	PWM4_DELAY  		   (PWM_base+0x0004) /* PWM4 Delay Duration */
#define 	PWM5_DELAY  		   (PWM_base+0x0008) /* PWM5 Delay Duration */
#define 	PWM6_DELAY  		   (PWM_base+0x000C) /* PWM6 Delay Duration */

#define 	PWM1_CON 		      (PWM_base+0x0010) /* PWM1 Control        */
#define 	PWM1_HDURATION	      (PWM_base+0x0014) /* PWM1 High Duration  */
#define 	PWM1_LDURATION	      (PWM_base+0x0018) /* PWM1 Low Duration  */
#define 	PWM1_GDURATION	      (PWM_base+0x001C) /* PWM1 Guard Duration  */
#define 	PWM1_BUF0_BASE_ADDR  (PWM_base+0x0020) /* PWM1 Buffer0 Base Address  */
#define 	PWM1_BUF0_SIZE       (PWM_base+0x0024) /* PWM1 Buffer0 Size  */
#define 	PWM1_BUF1_BASE_ADDR  (PWM_base+0x0028) /* PWM1 Buffer1 Base Address  */
#define 	PWM1_BUF1_SIZE       (PWM_base+0x002C) /* PWM1 Buffer1 Size  */
#define 	PWM1_SEND_DATA0      (PWM_base+0x0030) /* PWM1 Send Data0  */
#define 	PWM1_SEND_DATA1      (PWM_base+0x0034) /* PWM1 Send Data1  */
#define 	PWM1_WAVE_NUM        (PWM_base+0x0038) /* PWM1 Wave Number  */
#define 	PWM1_DATA_WIDTH      (PWM_base+0x003C) /* PWM1 Data Width  */
#define 	PWM1_THRESH          (PWM_base+0x0040) /* PWM1 Threshold  */
#define 	PWM1_SEND_WAVENUM    (PWM_base+0x0044) /* PWM1 Send Wave Number  */
#define 	PWM1_VALID           (PWM_base+0x0048) /* PWM1 Valid  */

#define 	PWM2_CON 		      (PWM_base+0x0050) /* PWM2 Control        */
#define 	PWM2_HDURATION	      (PWM_base+0x0054) /* PWM2 High Duration  */
#define 	PWM2_LDURATION	      (PWM_base+0x0058) /* PWM2 Low Duration  */
#define 	PWM2_GDURATION	      (PWM_base+0x005C) /* PWM2 Guard Duration  */
#define 	PWM2_BUF0_BASE_ADDR  (PWM_base+0x0060) /* PWM2 Buffer0 Base Address  */
#define 	PWM2_BUF0_SIZE       (PWM_base+0x0064) /* PWM2 Buffer0 Size  */
#define 	PWM2_BUF1_BASE_ADDR  (PWM_base+0x0068) /* PWM2 Buffer1 Base Address  */
#define 	PWM2_BUF1_SIZE       (PWM_base+0x006C) /* PWM2 Buffer1 Size  */
#define 	PWM2_SEND_DATA0      (PWM_base+0x0070) /* PWM2 Send Data0  */
#define 	PWM2_SEND_DATA1      (PWM_base+0x0074) /* PWM2 Send Data1  */
#define 	PWM2_WAVE_NUM        (PWM_base+0x0078) /* PWM2 Wave Number  */
#define 	PWM2_DATA_WIDTH      (PWM_base+0x007C) /* PWM2 Data Width  */
#define 	PWM2_THRESH          (PWM_base+0x0080) /* PWM2 Threshold  */
#define 	PWM2_SEND_WAVENUM    (PWM_base+0x0084) /* PWM2 Send Wave Number  */
#define 	PWM2_VALID           (PWM_base+0x0088) /* PWM2 Valid  */

#define 	PWM3_CON 		      (PWM_base+0x0090) /* PWM3 Control        */
#define 	PWM3_HDURATION	      (PWM_base+0x0094) /* PWM3 High Duration  */
#define 	PWM3_LDURATION	      (PWM_base+0x0098) /* PWM3 Low Duration  */
#define 	PWM3_GDURATION	      (PWM_base+0x009C) /* PWM3 Guard Duration  */
#define 	PWM3_BUF0_BASE_ADDR  (PWM_base+0x00A0) /* PWM3 Buffer0 Base Address  */
#define 	PWM3_BUF0_SIZE       (PWM_base+0x00A4) /* PWM3 Buffer0 Size  */
#define 	PWM3_BUF1_BASE_ADDR  (PWM_base+0x00A8) /* PWM3 Buffer1 Base Address  */
#define 	PWM3_BUF1_SIZE       (PWM_base+0x00AC) /* PWM3 Buffer1 Size  */
#define 	PWM3_SEND_DATA0      (PWM_base+0x00B0) /* PWM3 Send Data0  */
#define 	PWM3_SEND_DATA1      (PWM_base+0x00B4) /* PWM3 Send Data1  */
#define 	PWM3_WAVE_NUM        (PWM_base+0x00B8) /* PWM3 Wave Number  */
#define 	PWM3_DATA_WIDTH      (PWM_base+0x00BC) /* PWM3 Data Width  */
#define 	PWM3_THRESH          (PWM_base+0x00C0) /* PWM3 Threshold  */
#define 	PWM3_SEND_WAVENUM    (PWM_base+0x00C4) /* PWM3 Send Wave Number  */
#define 	PWM3_VALID           (PWM_base+0x00C8) /* PWM3 Valid  */

#define 	PWM4_CON 		      (PWM_base+0x00D0) /* PWM4 Control        */
#define 	PWM4_HDURATION	      (PWM_base+0x00D4) /* PWM4 High Duration  */
#define 	PWM4_LDURATION	      (PWM_base+0x00D8) /* PWM4 Low Duration  */
#define 	PWM4_GDURATION	      (PWM_base+0x00DC) /* PWM4 Guard Duration  */
#define 	PWM4_BUF0_BASE_ADDR  (PWM_base+0x00E0) /* PWM4 Buffer0 Base Address  */
#define 	PWM4_BUF0_SIZE       (PWM_base+0x00E4) /* PWM4 Buffer0 Size  */
#define 	PWM4_BUF1_BASE_ADDR  (PWM_base+0x00E8) /* PWM4 Buffer1 Base Address  */
#define 	PWM4_BUF1_SIZE       (PWM_base+0x00EC) /* PWM4 Buffer1 Size  */
#define 	PWM4_SEND_DATA0      (PWM_base+0x00F0) /* PWM4 Send Data0  */
#define 	PWM4_SEND_DATA1      (PWM_base+0x00F4) /* PWM4 Send Data1  */
#define 	PWM4_WAVE_NUM        (PWM_base+0x00F8) /* PWM4 Wave Number  */
#define 	PWM4_SEND_WAVENUM    (PWM_base+0x00FC) /* PWM4 Send Wave Number  */
#define 	PWM4_VALID           (PWM_base+0x0100) /* PWM4 Valid  */

#define 	PWM5_CON 		      (PWM_base+0x0110) /* PWM5 Control        */
#define 	PWM5_HDURATION	      (PWM_base+0x0114) /* PWM5 High Duration  */
#define 	PWM5_LDURATION	      (PWM_base+0x0118) /* PWM5 Low Duration  */
#define 	PWM5_GDURATION	      (PWM_base+0x011C) /* PWM5 Guard Duration  */
#define 	PWM5_BUF0_BASE_ADDR  (PWM_base+0x0120) /* PWM5 Buffer0 Base Address  */
#define 	PWM5_BUF0_SIZE       (PWM_base+0x0124) /* PWM5 Buffer0 Size  */
#define 	PWM5_BUF1_BASE_ADDR  (PWM_base+0x0128) /* PWM5 Buffer1 Base Address  */
#define 	PWM5_BUF1_SIZE       (PWM_base+0x012C) /* PWM5 Buffer1 Size  */
#define 	PWM5_SEND_DATA0      (PWM_base+0x0130) /* PWM5 Send Data0  */
#define 	PWM5_SEND_DATA1      (PWM_base+0x0134) /* PWM5 Send Data1  */
#define 	PWM5_WAVE_NUM        (PWM_base+0x0138) /* PWM5 Wave Number  */
#define 	PWM5_SEND_WAVENUM    (PWM_base+0x013C) /* PWM5 Send Wave Number  */
#define 	PWM5_VALID           (PWM_base+0x0140) /* PWM5 Valid  */

#define 	PWM6_CON 		      (PWM_base+0x0150) /* PWM6 Control        */
#define 	PWM6_HDURATION	      (PWM_base+0x0154) /* PWM6 High Duration  */
#define 	PWM6_LDURATION	      (PWM_base+0x0158) /* PWM6 Low Duration  */
#define 	PWM6_GDURATION	      (PWM_base+0x015C) /* PWM6 Guard Duration  */
#define 	PWM6_BUF0_BASE_ADDR  (PWM_base+0x0160) /* PWM6 Buffer0 Base Address  */
#define 	PWM6_BUF0_SIZE       (PWM_base+0x0164) /* PWM6 Buffer0 Size  */
#define 	PWM6_BUF1_BASE_ADDR  (PWM_base+0x0168) /* PWM6 Buffer1 Base Address  */
#define 	PWM6_BUF1_SIZE       (PWM_base+0x016C) /* PWM6 Buffer1 Size  */
#define 	PWM6_SEND_DATA0      (PWM_base+0x0170) /* PWM6 Send Data0  */
#define 	PWM6_SEND_DATA1      (PWM_base+0x0174) /* PWM6 Send Data1  */
#define 	PWM6_WAVE_NUM        (PWM_base+0x0178) /* PWM6 Wave Number  */
#define 	PWM6_SEND_WAVENUM    (PWM_base+0x017C) /* PWM6 Send Wave Number  */
#define 	PWM6_VALID           (PWM_base+0x0180) /* PWM6 Valid  */

#define  PWM_INT_ENABLE       (PWM_base+0x0190) /* PWM Interrupt Enable  */
#define  PWM_INT_STATUS       (PWM_base+0x0194) /* PWM Interrupt Status  */
#define  PWM_INT_ACK          (PWM_base+0x0198) /* PWM Interrupt Acknowledge  */

/* PWM_ENABLE register */
#define PWM_ENABLE_MASK       0x0000003F
#define PWM1_ENABLE_MASK      0x00000001
   #define PWM1_ENABLE          0x00000001
   #define PWM1_DISABLE         0x00000000
#define PWM2_ENABLE_MASK      0x00000002
   #define PWM2_ENABLE          0x00000002
   #define PWM2_DISABLE         0x00000000
#define PWM3_ENABLE_MASK      0x00000004
   #define PWM3_ENABLE          0x00000004
   #define PWM3_DISABLE         0x00000000
#define PWM4_ENABLE_MASK      0x00000008
   #define PWM4_ENABLE          0x00000008
   #define PWM4_DISABLE         0x00000000
#define PWM5_ENABLE_MASK      0x00000010
   #define PWM5_ENABLE          0x00000010
   #define PWM5_DISABLE         0x00000000
#define PWM6_ENABLE_MASK      0x00000020
   #define PWM6_ENABLE          0x00000020
   #define PWM6_DISABLE         0x00000000
#define PWM_SEQ_MODE_MASK     0x00000040
   #define PWM_SEQ_MODE_ON      0x00000040
   #define PWM_SEQ_MODE_OFF     0x00000000

/* PWM4, PWM5, PWM6 Delay Duration register */
#define PWM_DELAY_DURATON_MASK   0x0000FFFF
#define PWM_DELAY_CLKSEL_MASK    0x00010000
   #define PWM_DELAY_CLKSEL_52M    0x00000000
   #define PWM_DELAY_CLKSEL_32K    0x00010000

/* PWM1~PWM6 Control registers */
#define PWM_CON_CLKDIV_SHIFT     0
#define PWM_CON_CLKDIV_MASK      0x00000007
   #define PWM_CON_CLKDIV_1         0x00000000
   #define PWM_CON_CLKDIV_2         0x00000001
   #define PWM_CON_CLKDIV_4         0x00000010
   #define PWM_CON_CLKDIV_8         0x00000011
   #define PWM_CON_CLKDIV_16        0x00000100
   #define PWM_CON_CLKDIV_32        0x00000101
   #define PWM_CON_CLKDIV_64        0x00000110
   #define PWM_CON_CLKDIV_128       0x00000111
#define PWM_CON_CLKSEL_SHIFT     3
#define PWM_CON_CLKSEL_MASK      0x00000008
   #define PWM_CON_CLKSEL_52M       0x00000000
   #define PWM_CON_CLKSEL_32K       0x00000008
#define PWM_CON_FIXED_CLKMODE_SHIFT     4
#define PWM_CON_FIXED_CLKMODE_MASK      0x00000010
   #define PWM_CON_FIXED_CLKMODE_0       0x00000000
   #define PWM_CON_FIXED_CLKMODE_1       0x00000010
#define PWM_CON_SRCSEL_SHIFT     5
#define PWM_CON_SRCSEL_MASK      0x00000020
   #define PWM_CON_SRCSEL_FIFO      0x00000000
   #define PWM_CON_SRCSEL_MEM       0x00000020
#define PWM_CON_MODE_SHIFT       6
#define PWM_CON_MODE_MASK        0x00000040
   #define PWM_CON_MODE_PERIODIC    0x00000000
   #define PWM_CON_MODE_RANDOM      0x00000040
#define PWM_CON_IDLE_VALUE_SHIFT 7
#define PWM_CON_IDLE_VALUE_MASK  0x00000080
   #define PWM_CON_IDLE_VALUE_0     0x00000000
   #define PWM_CON_IDLE_VALUE_1     0x00000080
#define PWM_CON_GUARD_VALUE_SHIFT 8
#define PWM_CON_GUARD_VALUE_MASK 0x00000100
   #define PWM_CON_GUARD_VALUE_0    0x00000000
   #define PWM_CON_GUARD_VALUE_1    0x00000100
#define PWM_CON_STOP_BITPOS_SHIFT  9
#define PWM_CON_STOP_BITPOS_MASK  0x00007E00
#define PWM_CON_OLD_PWM_MODE_SHIFT 15
#define PWM_CON_OLD_PWM_MODE_MASK 0x00008000
   #define PWM_CON_NEW_PWM_MODE     0x00000000
   #define PWM_CON_OLD_PWM_MODE     0x00008000

/* PWM1~PWM3 Data Width registers */
#define 	PWM_DATA_WIDTH_MASK   0x00003FFF

/* PWM1~PWM3 Threshold registers */
#define 	PWM_THRESH_MASK   0x00003FFF

/* PWM1~PWM6 Data Valid registers */
#define 	PWM_DATA_VALID_MASK       0x0000000F
#define  PWM_BUF0_VALID_MASK       0x00000001
   #define  PWM_BUF0_INVALID           0x00000000
   #define  PWM_BUF0_VALID             0x00000001
#define  PWM_BUF0_VALID_WEN_MASK   0x00000002
   #define  PWM_BUF0_VALID_WDISABLE    0x00000000
   #define  PWM_BUF0_VALID_WENABLE     0x00000002
#define  PWM_BUF1_VALID_MASK       0x00000004
   #define  PWM_BUF1_INVALID           0x00000000
   #define  PWM_BUF1_VALID             0x00000004
#define  PWM_BUF1_VALID_WEN_MASK   0x00000008
   #define  PWM_BUF1_VALID_WDISABLE    0x00000000
   #define  PWM_BUF1_VALID_WENABLE     0x00000008

/* PWM Interrupt Enable registers */
#define 	PWM_INT_ENABLE_MASK          0x00000FFF
#define  PWM1_INT_FINISH_EN_MASK      0x00000001
   #define  PWM1_INT_FINISH_DISABLE     0x00000000
   #define  PWM1_INT_FINISH_ENABLE      0x00000001
#define  PWM1_INT_UNDERFLOW_EN_MASK   0x00000002
   #define  PWM1_INT_UNDERFLOW_DISABLE  0x00000000
   #define  PWM1_INT_UNDERFLOW_ENABLE   0x00000002
#define  PWM2_INT_FINISH_EN_MASK      0x00000004
   #define  PWM2_INT_FINISH_DISABLE     0x00000000
   #define  PWM2_INT_FINISH_ENABLE      0x00000004
#define  PWM2_INT_UNDERFLOW_EN_MASK   0x00000008
   #define  PWM2_INT_UNDERFLOW_DISABLE  0x00000000
   #define  PWM2_INT_UNDERFLOW_ENABLE   0x00000008
#define  PWM3_INT_FINISH_EN_MASK      0x00000010
   #define  PWM3_INT_FINISH_DISABLE     0x00000000
   #define  PWM3_INT_FINISH_ENABLE      0x00000010
#define  PWM3_INT_UNDERFLOW_EN_MASK   0x00000020
   #define  PWM3_INT_UNDERFLOW_DISABLE  0x00000000
   #define  PWM3_INT_UNDERFLOW_ENABLE   0x00000020
#define  PWM4_INT_FINISH_EN_MASK      0x00000040
   #define  PWM4_INT_FINISH_DISABLE     0x00000000
   #define  PWM4_INT_FINISH_ENABLE      0x00000040
#define  PWM4_INT_UNDERFLOW_EN_MASK   0x00000080
   #define  PWM4_INT_UNDERFLOW_DISABLE  0x00000000
   #define  PWM4_INT_UNDERFLOW_ENABLE   0x00000080
#define  PWM5_INT_FINISH_EN_MASK      0x00000100
   #define  PWM5_INT_FINISH_DISABLE     0x00000000
   #define  PWM5_INT_FINISH_ENABLE      0x00000100
#define  PWM5_INT_UNDERFLOW_EN_MASK   0x00000200
   #define  PWM5_INT_UNDERFLOW_DISABLE  0x00000000
   #define  PWM5_INT_UNDERFLOW_ENABLE   0x00000200
#define  PWM6_INT_FINISH_EN_MASK      0x00000400
   #define  PWM6_INT_FINISH_DISABLE     0x00000000
   #define  PWM6_INT_FINISH_ENABLE      0x00000400
#define  PWM6_INT_UNDERFLOW_EN_MASK   0x00000800
   #define  PWM6_INT_UNDERFLOW_DISABLE  0x00000000
   #define  PWM6_INT_UNDERFLOW_ENABLE   0x00000800

/* PWM Interrupt Status registers */
#define 	PWM_INT_STATUS_MASK        0x00000FFF
#define  PWM1_INT_FINISH_EN_ST      0x00000001
#define  PWM1_INT_UNDERFLOW_EN_ST   0x00000002
#define  PWM2_INT_FINISH_EN_ST      0x00000004
#define  PWM2_INT_UNDERFLOW_EN_ST   0x00000008
#define  PWM3_INT_FINISH_EN_ST      0x00000010
#define  PWM3_INT_UNDERFLOW_EN_ST   0x00000020
#define  PWM4_INT_FINISH_EN_ST      0x00000040
#define  PWM4_INT_UNDERFLOW_EN_ST   0x00000080
#define  PWM5_INT_FINISH_EN_ST      0x00000100
#define  PWM5_INT_UNDERFLOW_EN_ST   0x00000200
#define  PWM6_INT_FINISH_EN_ST      0x00000400
#define  PWM6_INT_UNDERFLOW_EN_ST   0x00000800

/* PWM Interrupt ACK registers */
#define 	PWM_INT_ACK_MASK         0x00000FFF
#define  PWM1_INT_FINISH_ACK      0x00000001
#define  PWM1_INT_UNDERFLOW_ACK   0x00000002
#define  PWM2_INT_FINISH_ACK      0x00000004
#define  PWM2_INT_UNDERFLOW_ACK   0x00000008
#define  PWM3_INT_FINISH_ACK      0x00000010
#define  PWM3_INT_UNDERFLOW_ACK   0x00000020
#define  PWM4_INT_FINISH_ACK      0x00000040
#define  PWM4_INT_UNDERFLOW_ACK   0x00000080
#define  PWM5_INT_FINISH_ACK      0x00000100
#define  PWM5_INT_UNDERFLOW_ACK   0x00000200
#define  PWM6_INT_FINISH_ACK      0x00000400
#define  PWM6_INT_UNDERFLOW_ACK   0x00000800

#endif  /* defined(DRV_PWM_RWG) */


#endif

