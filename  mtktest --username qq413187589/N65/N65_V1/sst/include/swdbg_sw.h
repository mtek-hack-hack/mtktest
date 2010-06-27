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
 *   swdbg_sw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file defines data and function prototype for Software Debug Controller
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
 ****************************************************************************/

#ifndef SWDBG_SW_H

#define SWDBG_SW_H

/************************************************************************
 * Constant definitions 
 ************************************************************************/

#define SWDBG_MDTX1_MAX_SIZE 128

#define SWDBG_MDTX1_SWBUFF_SIZE 192 /* SWDBG_MDTX1_MAX_SIZE * 2 - SWDBG_MDTX_FIFOSIZE */

#define SWDBG_MDRX_RBUFF_SIZE 256

#define SWDBG_TOTAL_TX 5

#define SWDBG_MAX_TX 3

#define SWDBG_USER_DDA 0x00000001
#define SWDBG_USER_DDB 0x00000002
#define SWDBG_USER_MDTXA 0x00000004
#define SWDBG_USER_MDTXB 0x00000008
#define SWDBG_USER_MP 0x00000010
#define SWDBG_USER_MDRX 0x00000020

#define SWDBG_USER_ADDR0 0
#define SWDBG_USER_ADDR1 1
#define SWDBG_USER_ADDR2 2

#define SWDBG_DDAADR_SHIFT 16
#define SWDBG_DDBADR_SHIFT 18
#define SWDBG_MDTXAADR_SHIFT 20
#define SWDBG_MDTXBADR_SHIFT 22
#define SWDBG_MPADR_SHIFT 24
#define SWDBG_MDRXADR_SHIFT 26

#define SWDBG_MDTX1_FLUSH_CNT 100

#define SWDBG_DUMMY_CNT 512

#define SWDBG_GPIO_NORMAL 1
#define SWDBG_GPIO_ICE 2
#define SWDBG_GPIO_SWDBG 3


/************************************************************************
 * External global data definition
 ************************************************************************/
#ifdef __SWDBG_SUPPORT__
extern const UartDriver_strcut swdbgdrv;
#endif   /* __SWDBG_SUPPORT */


/************************************************************************
 * Exported fucntion prototype 
 ************************************************************************/
#if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6223) || defined(MT6223P)
extern kal_uint32 swdbg_pwr_up(void);
extern kal_uint32 swdbg_pwr_down(void);
#endif   /* MT6228 || MT6229 || MT6230 || MT6223  || MT6223P */

#if defined(MT6223) || defined(MT6223P)
extern void swdbg_config_GPIO(kal_uint32 config);
#endif   /* MT6223  || MT6223P*/

#ifdef __SWDBG_SUPPORT__
extern void swdbg_init(void);
extern kal_bool swdbg_config(kal_uint8 profile);
extern void swdbg_md_flushdata(void);
extern void swdbg_md_flushisrdata(void);
extern void swdbg_reset(void);
extern void swdbg_dd_disable(void);
#endif   /* __SWDBG_SUPPORT */

#endif   /* SWDBG_SW_H */

