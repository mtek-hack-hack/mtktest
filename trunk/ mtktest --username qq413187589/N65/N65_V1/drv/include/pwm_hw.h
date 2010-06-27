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
 *    pwm_hw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intended for PWM driver.
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef PWM_HW_H
#define PWM_HW_H
#include "drv_features.h"

#if !defined(DRV_PWM_RWG)
#define 	PWM1_CTRL		      (PWM_base+0x0000) /* PWM Control           */
#define 	PWM1_COUNT  		   (PWM_base+0x0004) /* PWM max counter value */
#define 	PWM1_THRESHOLD 		(PWM_base+0x0008) /* PWM threshold value   */
#define  PWM1_PWR		         (0x80000000+0x0304)
#define 	PWM1_PWR_OFF		   0x0020
#if defined(DRV_PWM_PWM2)
   #define 	PWM2_CTRL		      (PWM_base+0x000C) /* PWM Control           */
   #define 	PWM2_COUNT  		   (PWM_base+0x0010) /* PWM max counter value */
   #define 	PWM2_THRESHOLD 		(PWM_base+0x0014) /* PWM threshold value   */
   #define  PWM2_PWR		         (0x80000000+0x0304)
   #define 	PWM2_PWR_OFF		   0x0400
#endif /*DRV_PWM_PWM2*/

#define	PWM_CTRL_EN		      0x8000
#define	PWM_CTRL_CLK_1		   0x0000
#define  PWM_CTRL_CLK_2		   0x0001
#define  PWM_CTRL_CLK_4		   0x0002
#define  PWM_CTRL_CLK_8		   0x0003

#if defined(DRV_PWM_CLK_SEL)
   #define PWM_CTRL_CLKSEL       0x0004
#endif   /*DRV_PWM_CLK_SEL*/

/*==================Macro====================*/
#define PWM_SetCountValue(count)	*(volatile kal_uint16 *)PWM1_COUNT = count
#define PWM_SetThres(thres)	*(volatile kal_uint16 *)PWM1_THRESHOLD = thres
#if defined(DRV_PWM_PWM2)
   #define PWM2_SetCountValue(count)	*(volatile kal_uint16 *)PWM2_COUNT = count
   #define PWM2_SetThres(thres)	      *(volatile kal_uint16 *)PWM2_THRESHOLD = thres
#endif /*DRV_PWM_PWM2*/

#endif  /* !defined(DRV_PWM_RWG) */


#endif

