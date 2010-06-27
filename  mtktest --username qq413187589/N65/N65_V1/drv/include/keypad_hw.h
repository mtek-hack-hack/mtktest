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
 *    keypad_hw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intends for keypad driver.
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
#ifndef KEYPAD_HW_H
#define KEYPAD_HW_H
#include "drv_features.h"

#if defined(DRV_KBD_32KEYS_EQ_BELOW) || defined(FPGA)
   #define 	KP_STS			(KP_base+0x00)
   #define 	KP_LOW_KEY		(KP_base+0x04)
   #define 	KP_HI_KEY		(KP_base+0x08)
   #define 	KP_DEBOUNCE		(KP_base+0x0C)
   #define 	KP_SCAN			(KP_base+0x10)
   
   //kp_sts
   #define 	KP_STS_KEYPRESS		0x0001
   #define 	KP_STS_IDLE		      0x0000
   #define 	KP_STS_MASK		      0x0001
   
   //KP_LOW_KEY
   #define 	KP_LOW_KEY_MASK		0xffff
   
   //KP_HI_KEY
   #define 	KP_HI_KEY_MASK		   0x01ff
   
   //KP_DEBOUNCE
   #define 	KP_DEBOUNCE_TIME	   0x0400
   
   //KP_SCAN
   #define 	KP_SCAN_4KHZ		0x0007
#endif   /*DRV_KBD_32KEYS_EQ_BELOW,FPGA*/

#if defined(DRV_KBD_32KEYS_ABOVE)
   #define 	KP_STS			(KP_base+0x00)
   #define 	KP_LOW_KEY		(KP_base+0x04)
   #define 	KP_MID_KEY		(KP_base+0x08)
   #define 	KP_HI_KEY		(KP_base+0x0c)
   #define 	KP_DEBOUNCE		(KP_base+0x10)
   
   #define 	KP_STS_KEYPRESS		0x0001
   #define 	KP_STS_IDLE		      0x0000
   #define 	KP_STS_MASK		      0x0001
   
   #define 	KP_LOW_KEY_MASK		0xffff
   #define 	KP_MID_KEY_MASK		0xffff

   #define 	KP_DEBOUNCE_TIME	   0x0200
#elif defined(DRV_KBD_64KEYS_ABOVE)
   #define 	KP_STS			(KP_base+0x00)
   #define 	KP_LOW_KEY		(KP_base+0x04)
   #define 	KP_MID_KEY		(KP_base+0x08)
   #define 	KP_MID1_KEY		(KP_base+0x0c)
   #define 	KP_MID2_KEY		(KP_base+0x10)
   #define 	KP_HI_KEY		(KP_base+0x14)
   #define 	KP_DEBOUNCE		(KP_base+0x18)
   
   #define 	KP_STS_KEYPRESS		0x0001
   #define 	KP_STS_IDLE		      0x0000
   #define 	KP_STS_MASK		      0x0001
   
   #define 	KP_LOW_KEY_MASK		0xffff
   #define 	KP_MID_KEY_MASK		0xffff
   #define 	KP_MID1_KEY_MASK		0xffff
   #define 	KP_MID2_KEY_MASK		0xffff

   #define 	KP_DEBOUNCE_TIME	   0x0200
#endif   /*DRV_KBD_32KEYS_ABOVE*/

#if defined(DRV_KBD_36_KEYS)
   #define 	KP_HI_KEY_MASK		   0x00ff
#elif defined(DRV_KBD_42_KEYS)
   #define 	KP_HI_KEY_MASK		   0x07ff
#elif defined(DRV_KBD_35_KEYS)
   #define  KP_HI_KEY_MASK       0x0007
#elif defined(DRV_KBD_72_KEYS)
   #define  KP_HI_KEY_MASK       0x00ff
#endif
#endif   /*KEYPAD_HW_H*/


