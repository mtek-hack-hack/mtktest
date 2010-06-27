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
 *    alerter_hw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intended for alerter driver.
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
#ifndef ALERTER_HW_H
#define ALERTER_HW_H

#if !defined(DRV_ALERTER_NOT_EXIST)
/***************************
 * Audio Alerter Registers *
 ***************************/
#define ALERTER_CNT1  (ALERTER_base+0x0000) /*Alerter val counter 1*/
#define ALERTER_THRES (ALERTER_base+0x0004) /*Alerter threshold val*/
#define ALERTER_CNT2  (ALERTER_base+0x0008) /*Alerter val counter 2*/
#define ALERTER_CTRL  (ALERTER_base+0x000C) /*Alerter control      */

#define ALERTER_CTRL_MODEMASK	0x0018
#define ALERTER_CTRL_MODE1	0x0000
#define ALERTER_CTRL_MODE2	0x0008
#define ALERTER_CTRL_MODE3	0x0010
#define ALERTER_PWR		(0x80000000+0x0304)
#define ALERTER_PWR_OFF		0x0040
#define ALERTER_CTRL_PDMOUTPUT	0x0100

#define  ALERTER_CTRL_EN		   0x8000
#define	ALERTER_CTRL_CLK_1		0x0000
#define  ALERTER_CTRL_CLK_2		0x0001
#define  ALERTER_CTRL_CLK_4		0x0002
#define  ALERTER_CTRL_CLK_8		0x0003

/*==================Macro====================*/
#define ALERTER_setCNT1(cnt1)	*(volatile kal_uint16 *)ALERTER_CNT1 = cnt1
#define ALERTER_setCNT2(cnt2)	*(volatile kal_uint16 *)ALERTER_CNT2 = cnt2
#define ALERTER_setTHRES(thres) *(volatile kal_uint16 *)ALERTER_THRES = thres

#endif /*!defined(DRV_ALERTER_NOT_EXIST)*/

#endif

