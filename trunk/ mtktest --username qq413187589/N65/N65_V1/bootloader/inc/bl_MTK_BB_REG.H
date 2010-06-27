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
 *   bl_MTK_BB_REG.h
 *
 * Project:
 * --------
 *   NFB - Bootloader
 *
 * Description:
 * ------------
 *   This file defines the register mapping for MTK BB-chip that Boot-loader
 *   needs.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _BOOTLOADER_MTK_BB_REG_H
#define _BOOTLOADER_MTK_BB_REG_H

#if defined(MT6238)
#define CONFIG_base                 (0x80010000)   /* Config registers  (Clk, Power Down, Ver) */
#define TDMA_base                   (0x82000000)   /* TDMA Timer */
#else
#define CONFIG_base                 (0x80000000)   /* Config registers  (Clk, Power Down, Ver) */
#define TDMA_base                   (0x80200000)   /* TDMA Timer */
#endif

#define SM_CTRL                     (TDMA_base+0x218)
#define SM_STAT                     (TDMA_base+0x21c)
#define SM_FMDURATION               (TDMA_base+0x220)
#define SM_FM_RESULT_LOW            (TDMA_base+0x228)
#define SM_FM_RESULT_HIGH           (TDMA_base+0x224)
#define SM_CTRL_FM_START            0x0001
#define SM_STAT_FM_RDY              0x0002
#define SM_FM_RESULT_HIGH_MASK      0x03ff

#define DRVPDN_CON0                 (CONFIG_base+0x0300)
#define DRVPDN_CON1                 (CONFIG_base+0x0304)
#define DRVPDN_CON2                 (CONFIG_base+0x0308)
#define DRVPDN_CON3                 (CONFIG_base+0x030c)
#define DRVPDN_CON2_TDMA            0x0001


#define DRVPDN_CON0_SET          (CONFIG_base+0x0310)
#define DRVPDN_CON1_SET          (CONFIG_base+0x0314)
#define DRVPDN_CON2_SET          (CONFIG_base+0x0318)
#define DRVPDN_CON3_SET          (CONFIG_base+0x031c)

#define DRVPDN_CON0_CLR          (CONFIG_base+0x0320)
#define DRVPDN_CON1_CLR          (CONFIG_base+0x0324)
#define DRVPDN_CON2_CLR          (CONFIG_base+0x0328)
#define DRVPDN_CON3_CLR          (CONFIG_base+0x032c)



/* Macros for register read/write */
#define DRV_WriteReg(addr,data)     ((*(volatile kal_uint16 *)(addr)) = (kal_uint16)(data))
#define DRV_Reg(addr)               (*(volatile kal_uint16 *)(addr))
#define DRV_WriteReg32(addr,data)   ((*(volatile kal_uint32 *)(addr)) = (kal_uint32)(data))
#define DRV_Reg32(addr)             (*(volatile kal_uint32 *)(addr))
#define DRV_WriteReg8(addr,data)    ((*(volatile kal_uint8 *)(addr)) = (kal_uint8)(data))
#define DRV_Reg8(addr)              (*(volatile kal_uint8 *)(addr))


#endif /* _BOOTLOADER_MTK_BB_REG_H */

