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
 *
 * Filename:
 * ---------
 *    video_hw.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    This file defines video HW register.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef VIDEO_HW_H
#define VIDEO_HW_H

#include "reg_base.h"

#ifdef DRV_MP4_V1
   #define MP4_CODEC_COMD			           (MP4_base+0x00000000)  /*WO*/
   #define MP4_CODEC_CONF			           (MP4_base+0x00000004)  /*R/W*/
   #define MP4_DEC_STS			              (MP4_base+0x00000008)  /*RO*/
   #define MP4_ENC_STS			              (MP4_base+0x0000000C)  /*RO*/
   #define MP4_IRQ_MASK			              (MP4_base+0x00000010)  /*R/W*/
   #define MP4_IRQ_STS			              (MP4_base+0x00000014)  /*RO*/
   #define MP4_IRQ_ACK			              (MP4_base+0x00000018)  /*WC*/
   #define MP4_ENC_CONF			              (MP4_base+0x0000001C)  /*R/W*/
   #define MP4_CODEC_BASE		              (MP4_base+0x00000100)  /*R/W*/
   #define MP4_VOP_ADDR	                    (MP4_base+0x00000104)  /*18~31 RO 0~17 R/W */
   #define MP4_REF_ADDR			              (MP4_base+0x00000108)  /*18~31 RO 0~17 R/W */
   #define MP4_REC_ADDR			              (MP4_base+0x0000010C)  /*18~31 RO 0~17 R/W */
   #define MP4_STORE_ADDR			           (MP4_base+0x00000110)  /*18~31 RO 0~17 R/W */
   #define MP4_DACP_ADDR			           (MP4_base+0x00000114)  /*18~31 RO 0~17 R/W */
   #define MP4_VOP_STRUC0                   (MP4_base+0x00000200)  /*R/W*/
   #define MP4_VOP_STRUC1                   (MP4_base+0x00000204)  /*R/W*/
   #define MP4_VOP_STRUC2                   (MP4_base+0x00000208)  /*R/W*/
   #define MP4_VOP_STRUC3                   (MP4_base+0x0000020C)  /*R/W*/
   #define MP4_MB_STRUC0                    (MP4_base+0x00000210)  /*R/W*/
   #define MP4_MB_STRUC1                    (MP4_base+0x00000214)   /*R/W*/
   #define MP4_MB_STRUC2                    (MP4_base+0x00000218)   /*R/W*/
   #define MP4_MB_STRUC3                    (MP4_base+0x0000021C)   /*R/W*/
   #define MP4_MB_STRUC4                    (MP4_base+0x00000220)   /*R/W*/
   #define MP4_MB_STRUC5                    (MP4_base+0x00000224)   /*R/W*/
   #define MP4_MB_STRUC6                    (MP4_base+0x00000228)   /*R/W*/
   #define MP4_MB_STRUC7                    (MP4_base+0x0000022C)   /*R/W*/
   #define MP4_VLC_COMD                     (MP4_base+0x00000300)    /*WO*/
   #define MP4_VLC_STS                      (MP4_base+0x00000304)    /*RO*/
   #define MP4_VLC_ADDR                     (MP4_base+0x00000308)    /*WO*/
   #define MP4_VLC_BIT                      (MP4_base+0x0000030C)    /*WO*/
   #define MP4_VLC_LIMIT                    (MP4_base+0x00000310)    /*R/W*/
   #define MP4_VLC_WORD                     (MP4_base+0x00000314)    /*RO*/
   #define MP4_VLC_BITCNT                   (MP4_base+0x00000318)    /*RO*/
   /* Software Decode Mode */               
   #define MP4_SVLD_COMD                    (MP4_base+0x00000400)
   #define MP4_SVLD_BITCNT                  (MP4_base+0x00000404)
   #define MP4_SVLD_MARK                    (MP4_base+0x00000408)
   #define MP4_SVLD_CODE                    (MP4_base+0x0000040C)
   /* Motion Estimation Debug */
   #define MP4_SAD_Y				              (MP4_base+0x00000500)
   #define MP4_SAD_U		                    (MP4_base+0x00000504)
   #define MP4_SAD_V				              (MP4_base+0x00000508)
   
   /*MP4_CODEC_COMD*/
   #define MP4_CODEC_COMD_START	           0x2
   #define MP4_CODEC_COMD_ReSeT	           0x1
   
   /*MP4_CODEC_CONF*/
   #define MP4_CODEC_CONF_ENC		            0x01
   #define MP4_CODEC_CONF_IRQ		            0x02
   #define MP4_CODEC_CONF_DCT		            0x04
   #define MP4_CODEC_CONF_VPGOB	            0x08
   #define MP4_CODEC_CONF_STEP_MASK          0x000f0000
   #define MP4_CODEC_CONF_HALF	            0x00100000
   #define MP4_CODEC_CONF_FME		            0x00200000
   #define MP4_CODEC_CONF_DQUAN	            0x00400000
   #define MP4_CODEC_CONF_PMV	               0x00800000
   #define MP4_CODEC_CONF_MASK      	      0x0FF000F
   #define MP4_CODEC_CONF_STEP_BITCNT        16
   #define MP4_CODEC_CONF_STEP_COUNT         2
   #define MP4_CODEC_CONF_STEP_VALUE         (MP4_CODEC_CONF_STEP_COUNT << MP4_CODEC_CONF_STEP_BITCNT)
                                            
   /*MP4_IRQ_MASK*/
   #define MP4_IRQ_MASK_VLD		           0x1
   #define MP4_IRQ_MASK_RLD		           0x2
   #define MP4_IRQ_MASK_MARK		           0x4
   #define MP4_IRQ_MASK_DEC		           0x8
   #define MP4_IRQ_MASK_ENC		           0x10
   #define MP4_IRQ_MASK_BLOCK		           0x20
   #define MP4_IRQ_MASK_PACK		           0x40
   #define MP4_IRQ_MASK_DMA		           0x80
   
   /*MP4_IRQ_STS*/
   #define MP4_IRQ_STS_VLD		              0x1
   #define MP4_IRQ_STS_RLD		              0x2
   #define MP4_IRQ_STS_MARK		           0x4
   #define MP4_IRQ_STS_DEC		              0x8
   #define MP4_IRQ_STS_ENC		              0x10
   #define MP4_IRQ_STS_BLOCK		           0x20
   #define MP4_IRQ_STS_PACK		           0x40
   #define MP4_IRQ_STS_DMA		              0x80
   #define MP4_IRQ_STS_MASK		           0x7F
   
   /*MP4_IRQ_ACK*/
   #define MP4_IRQ_ACK_VLD		              0x01   
   #define MP4_IRQ_ACK_RLD		              0x02   
   #define MP4_IRQ_ACK_MARK	              0x04   
   #define MP4_IRQ_ACK_DEC		              0x08   
   #define MP4_IRQ_ACK_ENC		              0x10
   #define MP4_IRQ_ACK_BLOCK	              0x20
   #define MP4_IRQ_ACK_PACK	              0x40
   #define MP4_IRQ_ACK_DMA		              0x80
   #define MP4_IRQ_ACK_MASK		           0x7F
   
   /*MP4_ENC_CONF*/
   #define MP4_ENC_CONF_SKIP_MASK           0x0000003f
   #define MP4_ENC_CONF_INTRA_MASK          0x00003f00
   #define MP4_ENC_CONF_PACK	              0x00010000
   #define MP4_ENC_CONF_PCAKCNT_MASK	     0x07fe0000
   #define MP4_ENC_CONF_SKIP_BITCNT         0  
   #define MP4_ENC_CONF_INTRA_BITCNT        8              
   
   /*MP4_CODEC_BASE*/
   #define MP4_CODEC_BASE_MASK		         0xFFFC0000
   
   /*MP4_VOP_STRUC0*/ /*MP4_VOP_STRUC0_XXX = (1 << MP4_VOP_STRUC0_XXX_BITCNT)*/
   #define MP4_VOP_STRUC0_TYPE	            0x0001
   #define MP4_VOP_STRUC0_DATA	            0x0002
   #define MP4_VOP_STRUC0_RVLC      	      0x0004
   #define MP4_VOP_STRUC0_SHORT              0x0010
   #define MP4_VOP_STRUC0_FCODE_MASK         0x00e0
   #define MP4_VOP_STRUC0_QUANT_MASK         0x1f00
   #define MP4_VOP_STRUC0_VLCTHR_MASK        0xe000
   #define MP4_VOP_STRUC0_ROUND	            0x00010000
   #define MP4_VOP_STRUC0_TYPE_BITCNT	      0
   #define MP4_VOP_STRUC0_DATA_BITCNT	      1
   #define MP4_VOP_STRUC0_RVLC_BITCNT	      2
   #define MP4_VOP_STRUC0_SHORT_BITCNT	      4
   #define MP4_VOP_STRUC0_FCODE_BITCNT	      5
   #define MP4_VOP_STRUC0_QUANT_BITCNT	      8
   #define MP4_VOP_STRUC0_VLCTHR_BITCNT	   13
   #define MP4_VOP_STRUC0_ROUND_BITCNT	      16
   
   /*MP4_VOP_STRUC1*/
   #define MP4_VOP_STRUC1_XLIMIT_MASK	      0x001f
   #define MP4_VOP_STRUC1_YLIMIT_MASK	      0x1f00
   #define MP4_VOP_STRUC1_MBLENGTH_MASK	   0x000f0000
   #define MP4_VOP_STRUC1_HEADERBIT_MASK     0x1f000000
   #define MP4_VOP_STRUC1_XLIMIT_BITCNT	   0
   #define MP4_VOP_STRUC1_YLIMIT_BITCNT	   8
   #define MP4_VOP_STRUC1_MBLENGTH_BITCNT	   16
   #define MP4_VOP_STRUC1_HEADERBIT_BITCNT   24
   
   /*MP4_VOP_STRUC2*/
   #define MP4_VOP_STRUC2_START_XPOS_MASK    0x001f
   #define MP4_VOP_STRUC2_START_YPOS_MASK    0x1f00
   #define MP4_VOP_STRUC2_MBCOUNT_MASK	      0x01ff0000
   #define MP4_VOP_STRUC2_START_XPOS_BITCNT  0
   #define MP4_VOP_STRUC2_START_YPOS_BITCNT  8
   #define MP4_VOP_STRUC2_MBCOUNT_BITCNT	   16
   
   /*MP4_VOP_STRUC3*/
   #define MP4_VOP_STRUC3_CURR_XPOS_MASK     0x001f    
   #define MP4_VOP_STRUC3_CURR_YPOS_MASK     0x1f00    
   #define MP4_VOP_STRUC3_MBCOUNT_MASK	      0x01ff0000
   #define MP4_VOP_STRUC3_CURR_XPOS_BITCNT   0
   #define MP4_VOP_STRUC3_CURR_YPOS_BITCNT   8
   #define MP4_VOP_STRUC3_MBCOUNT_BITCNT	   16
   
   /*MP4_MB_STRUC0*/
   #define MP4_MB_STRUC0_CODEC	            0x0001
   #define MP4_MB_STRUC0_TYPE_MASK           0x00e0
   #define MP4_MB_STRUC0_PATTERN_MASK	      0x03f0
   #define MP4_MB_STRUC0_DQUANT_MASK	      0x0c00
   #define MP4_MB_STRUC0_AC		            0x1000
   #define MP4_MB_STRUC0_DCVLC_MASK	         0x2000
   #define MP4_MB_STRUC0_QUANTIZER_MASK	   0x0007c000
   #define MP4_MB_STRUC0_CODEC_BITCNT	      0
   #define MP4_MB_STRUC0_TYPE_BITCNT	      1
   #define MP4_MB_STRUC0_PATTERN_BITCNT	   5
   #define MP4_MB_STRUC0_DQUANT_BITCNT	      10
   #define MP4_MB_STRUC0_AC_BITCNT		      12
   #define MP4_MB_STRUC0_DCVLC_BITCNT	      13
   #define MP4_MB_STRUC0_QUANTIZER_BITCNT	   14
   
   /*MP4_VLC_COMD*/
   #define MP4_VLC_COMD_START	               0x0001
   #define MP4_VLC_COMD_STOP	               0x0002
   #define MP4_VLC_COMD_FLUSH	               0x0004
   #define MP4_VLC_COMD_RELOAD	            0x0008
   
   /*MP4_VLC_LIMIT*/
   #define MP4_VLC_LIMIT_MASK                0x0000ffff

#else /* !DRV_MP4_V1 */

   #define MP4_CODEC_COMD                    (MP4_base+0x0) /*RW*/
   #define MP4_VLC_DMA_COMD                  (MP4_base+0x4) /*WO*/
   /*ENC register*/
   #define MP4_ENC_CODEC_CONF                (MP4_base+0x100) /*RW*/
   #define MP4_ENC_STS                       (MP4_base+0x104) /*RO*/
   #define MP4_ENC_IRQ_MASK                  (MP4_base+0x108) /*RW*/
   #define MP4_ENC_IRQ_STS                   (MP4_base+0x10c) /*RO*/
   #define MP4_ENC_IRQ_ACK			            (MP4_base+0x110) /*WC*/
   #define MP4_ENC_CONF			               (MP4_base+0x114) /*R/W*/
   #define MP4_ENC_CODEC_BASE		            (MP4_base+0x120) /*R/W*/
   #define MP4_ENC_VOP_ADDR	               (MP4_base+0x124) /*RW*/
   #define MP4_ENC_REF_ADDR			         (MP4_base+0x128) /*RW*/
   #define MP4_ENC_REC_ADDR			         (MP4_base+0x12C) /*RW*/
   #define MP4_ENC_STORE_ADDR			         (MP4_base+0x130) /*RW*/
   #define MP4_ENC_DACP_ADDR			         (MP4_base+0x134) /*RW*/
   #define MP4_ENC_MVP_ADDR			         (MP4_base+0x138) /*RW, new*/
   #define MP4_ENC_VOP_STRUC0                (MP4_base+0x140) /*R/W*/
   #define MP4_ENC_VOP_STRUC1                (MP4_base+0x144) /*R/W*/
   #define MP4_ENC_VOP_STRUC2                (MP4_base+0x148) /*R/W*/
   #define MP4_ENC_VOP_STRUC3                (MP4_base+0x14c) /*R/W*/
   #define MP4_ENC_MB_STRUC0                 (MP4_base+0x150) /*R/W*/
   #define MP4_ENC_VLC_ADDR                  (MP4_base+0x160) /*WO*/
   #define MP4_ENC_VLC_BIT                   (MP4_base+0x164) /*WO*/
   #define MP4_ENC_VLC_LIMIT                 (MP4_base+0x168) /*R/W*/
   #define MP4_ENC_VLC_WORD                  (MP4_base+0x16c) /*RO*/
   #define MP4_ENC_VLC_BITCNT                (MP4_base+0x170) /*RO*/
   #define MP4_ENC_RESYNC_CONF0              (MP4_base+0x180) /*RO*/
   #define MP4_ENC_RESYNC_CONF1              (MP4_base+0x184) /*RO*/
   #define MP4_ENC_TIME_BASE                 (MP4_base+0x188) /*RO*/
#ifdef DRV_MP4_V2_ENHANCE
   #define MP4_ENC_REF_INT_ADDR              (MP4_base+0x18c)    /*RW*/
   #define MP4_ENC_CUR_INT_ADDR              (MP4_base+0x190)    /*RW*/
   #define MP4_ENC_CYCLE_COUNT               (MP4_base+0x194)    /*RO*/   
#endif   
   /*DEC register*/
   #define MP4_DEC_CODEC_CONF                (MP4_base+0x200) /*RW*/
   #define MP4_DEC_STS                       (MP4_base+0x204) /*RO*/
   #define MP4_DEC_IRQ_MASK                  (MP4_base+0x208) /*RW*/
   #define MP4_DEC_IRQ_STS                   (MP4_base+0x20c) /*RO*/
   #define MP4_DEC_IRQ_ACK			            (MP4_base+0x210) /*WC*/
   #define MP4_DEC_CODEC_BASE		            (MP4_base+0x220) /*R/W*/
   #define MP4_DEC_REF_ADDR			         (MP4_base+0x224) /*RW*/
   #define MP4_DEC_REC_ADDR			         (MP4_base+0x228) /*RW*/
   #define MP4_DEC_DEBLOCK_ADDR		         (MP4_base+0x22c) /*RW*/
   #define MP4_DEC_STORE_ADDR			         (MP4_base+0x230) /*RW*/
   #define MP4_DEC_DACP_ADDR			         (MP4_base+0x234) /*RW*/
   #define MP4_DEC_MVP_ADDR			         (MP4_base+0x238) /*RW, new*/
   #define MP4_DEC_VOP_STRUC0                (MP4_base+0x240) /*R/W*/
   #define MP4_DEC_VOP_STRUC1                (MP4_base+0x244) /*R/W*/
   #define MP4_DEC_VOP_STRUC2                (MP4_base+0x248) /*R/W*/
   #define MP4_DEC_MB_STRUC0                 (MP4_base+0x24c) /*R/W*/
   #define MP4_DEC_VLC_ADDR                  (MP4_base+0x260) /*WO*/
   #define MP4_DEC_VLC_BIT                   (MP4_base+0x264) /*WO*/
   #define MP4_DEC_VLC_LIMIT                 (MP4_base+0x268) /*R/W*/
   #define MP4_DEC_VLC_WORD                  (MP4_base+0x26c) /*RO*/
   #define MP4_DEC_VLC_BITCNT                (MP4_base+0x270) /*RO*/
#ifdef DRV_MP4_V2_ENHANCE
   #define MP4_DEC_QS_ADDR                   (MP4_base+0x27c)    /*RW*/
   #define MP4_DEC_CYCLE_COUNT               (MP4_base+0x280)    /*RO*/
#endif    
   /*Core*/
   #define MP4_CORE_CONF                     (MP4_base+0x300) /*RW*/
   #define MP4_CORE_CODEC_CONF               (MP4_base+0x304) /*RW, ENC*/
   #define MP4_CORE_DUPLEX_STS               (MP4_base+0x308) /*RO*/
   #define MP4_CORE_CODEC_BASE		         (MP4_base+0x310) /*R/W*/
   #define MP4_CORE_VOP_ADDR	               (MP4_base+0x314) /*RW*/
   #define MP4_CORE_REF_ADDR			         (MP4_base+0x318) /*RW*/
   #define MP4_CORE_REC_ADDR			         (MP4_base+0x31c) /*RW*/
   #define MP4_CORE_DEBLOCK_ADDR		         (MP4_base+0x320) /*RW*/
   #define MP4_CORE_STORE_ADDR		         (MP4_base+0x324) /*RW*/
   #define MP4_CORE_DACP_ADDR			         (MP4_base+0x328) /*RW*/
   #define MP4_CORE_MVP_ADDR			         (MP4_base+0x32c) /*RW, new*/
   #define MP4_CORE_VOP_STRUC0               (MP4_base+0x330) /*R/W*/
   #define MP4_CORE_VOP_STRUC1               (MP4_base+0x334) /*R/W*/
   #define MP4_CORE_VOP_STRUC2               (MP4_base+0x338) /*R/W*/
   #define MP4_CORE_VOP_STRUC3               (MP4_base+0x33c) /*R/W*/
   #define MP4_CORE_MB_STRUC0                (MP4_base+0x340) /*R/W*/
   #define MP4_CORE_MB_STRUC1                (MP4_base+0x344) /*R/W*/
   #define MP4_CORE_MB_STRUC2                (MP4_base+0x348) /*R/W*/
   #define MP4_CORE_MB_STRUC3                (MP4_base+0x34c) /*R/W*/
   #define MP4_CORE_MB_STRUC4                (MP4_base+0x350) /*R/W*/
   #define MP4_CORE_MB_STRUC5                (MP4_base+0x354) /*R/W*/
   #define MP4_CORE_MB_STRUC6                (MP4_base+0x358) /*R/W*/
   #define MP4_CORE_MB_STRUC7                (MP4_base+0x35c) /*R/W*/
   #define MP4_CORE_VLC_STS                  (MP4_base+0x370) /*RO*/
   #define MP4_CORE_VLE_STS                  (MP4_base+0x374) /*RO*/
   #define MP4_CORE_VLC_ADDR                 (MP4_base+0x378) /*WO*/
   #define MP4_CORE_VLC_BIT                  (MP4_base+0x37c) /*WO*/
   #define MP4_CORE_VLC_LIMIT                (MP4_base+0x380) /*R/W*/
   #define MP4_CORE_VLC_WORD                 (MP4_base+0x384) /*RO*/
   #define MP4_CORE_VLC_BITCNT               (MP4_base+0x388) /*RO*/
   #define MP4_CORE_SVLD_COMD                (MP4_base+0x400)
   #define MP4_CORE_SVLD_BITCNT              (MP4_base+0x404)
   #define MP4_CORE_SVLD_MARK                (MP4_base+0x408)
   #define MP4_CORE_SVLD_CODE                (MP4_base+0x40C)
   #define MP4_CORE_SAD_Y				         (MP4_base+0x500)
   #define MP4_CORE_SAD_U		               (MP4_base+0x504)
   #define MP4_CORE_SAD_V				         (MP4_base+0x508)
   #define MP4_CORE_RESYNC_CONF0             (MP4_base+0x600) /*R/W*/
   #define MP4_CORE_RESYNC_CONF1             (MP4_base+0x604) /*R/W*/
   #define MP4_CORE_TIME_BASE                (MP4_base+0x60c) /*R/W*/
   
   /*Common, MP4_CODEC_COMD*/
   #define MP4_CODEC_COMD_CORE_RST                    0x0001
   #define MP4_CODEC_COMD_ENC_RST                     0x0002
   #define MP4_CODEC_COMD_DEC_RST                     0x0004
   #define MP4_CODEC_COMD_ENC_START                   0x0008
   #define MP4_CODEC_COMD_DEC_START                   0x0010
   /*Common, MP4_VLC_DMA_COMD*/
   #define MP4_VLC_DMA_COMD_STOP                      0x0001
   #define MP4_VLC_DMA_COMD_RELOAD                    0x0002
   
   /*Encoder, MP4_ENC_CODEC_CONF*/
   #define MP4_ENC_CODEC_CONF_ENC		               0x0001
   #define MP4_ENC_CODEC_CONF_IRQ		               0x0002
   #define MP4_ENC_CODEC_CONF_DCT		               0x0004
   #define MP4_ENC_CODEC_CONF_VPGOB	                  0x0008
   #define MP4_ENC_CODEC_CONF_STEP	                  0x0010
   #define MP4_ENC_CODEC_CONF_STEP_MASK               0x00f0
   #define MP4_ENC_CODEC_CONF_HALF	                  0x0100
   #define MP4_ENC_CODEC_CONF_FME		               0x0200
   #define MP4_ENC_CODEC_CONF_DQUAN	                  0x0400
   #define MP4_ENC_CODEC_CONF_PMV                     0x0800
   #define MP4_ENC_CODEC_CONF_MC_BURST                0x1000
   #define MP4_ENC_CODEC_CONF_ME_BURST                0x2000
   #define MP4_ENC_CODEC_CONF_CHECK_TV                0x10000
#ifdef DRV_MP4_V2_ENHANCE
   #define MP4_ENC_CODEC_CONF_PREFETCH                0x20000   
#endif
   #define MP4_ENC_CODEC_CONF_STEP_BITCNT             4
   #define MP4_ENC_CODEC_CONF_STEP_COUNT              2
   #define MP4_ENC_CODEC_CONF_STEP_VALUE              (MP4_ENC_CODEC_CONF_STEP_COUNT << MP4_ENC_CODEC_CONF_STEP_BITCNT)
   /*Encoder, MP4_ENC_IRQ_MASK*/
   #define MP4_ENC_IRQ_MASK_ENC	                     0x0001
   #define MP4_ENC_IRQ_MASK_BLOCK	                  0x0002
   #define MP4_ENC_IRQ_MASK_PACK    	               0x0004
   #define MP4_ENC_IRQ_MASK_DMA	                     0x0008
   /*Encoder, MP4_ENC_IRQ_STS*/
   #define MP4_ENC_IRQ_STS_ENC	                     0x0001
   #define MP4_ENC_IRQ_STS_BLOCK	                     0x0002
   #define MP4_ENC_IRQ_STS_PACK    	                  0x0004
   #define MP4_ENC_IRQ_STS_DMA	                     0x0008
   /*Encoder, MP4_ENC_IRQ_ACK*/
   #define MP4_ENC_IRQ_ACK_ENC	                     0x0001
   #define MP4_ENC_IRQ_ACK_BLOCK	                     0x0002
   #define MP4_ENC_IRQ_ACK_PACK    	                  0x0004
   #define MP4_ENC_IRQ_ACK_DMA	                     0x0008
   /*Encoder, MP4_ENC_CONF*/
   #define MP4_ENC_CONF_SKIP_MASK                     0x0000003f
   #define MP4_ENC_CONF_INTRA_MASK                    0x00003f00
   #define MP4_ENC_CONF_PACK	                        0x00010000
   #define MP4_ENC_CONF_PCAKCNT_MASK	               0x07fe0000
   #define MP4_ENC_CONF_SKIP_BITCNT                   0
   #define MP4_ENC_CONF_INTRA_BITCNT                  8
   #define MP4_ENC_CONF_PACK_BITCNT                   16
   #define MP4_ENC_CONF_PACKCNT_BITCNT              17
   /*Encoder, MP4_ENC_VOP_STRUC0*/ /*MP4_VOP_STRUC0_XXX = (1 << MP4_VOP_STRUC0_XXX_BITCNT)*/
   #define MP4_ENC_VOP_STRUC0_TYPE	                  0x0001
   #define MP4_ENC_VOP_STRUC0_DATA	                  0x0002
   #define MP4_ENC_VOP_STRUC0_RVLC      	            0x0004
   #define MP4_ENC_VOP_STRUC0_SHORT                   0x0010
   #define MP4_ENC_VOP_STRUC0_FCODE_MASK              0x00e0
   #define MP4_ENC_VOP_STRUC0_QUANT_MASK              0x1f00
   #define MP4_ENC_VOP_STRUC0_VLCTHR_MASK             0xe000
   #define MP4_ENC_VOP_STRUC0_ROUND	                  0x00010000
   #define MP4_ENC_VOP_STRUC0_TYPE_BITCNT	            0
   #define MP4_ENC_VOP_STRUC0_DATA_BITCNT	            1
   #define MP4_ENC_VOP_STRUC0_RVLC_BITCNT	            2
   #define MP4_ENC_VOP_STRUC0_SHORT_BITCNT	         4
   #define MP4_ENC_VOP_STRUC0_FCODE_BITCNT	         5
   #define MP4_ENC_VOP_STRUC0_QUANT_BITCNT	         8
   #define MP4_ENC_VOP_STRUC0_VLCTHR_BITCNT	         13
   #define MP4_ENC_VOP_STRUC0_ROUND_BITCNT	         16
   /*Encoder, MP4_ENC_VOP_STRUC1*/
   #define MP4_ENC_VOP_STRUC1_XLIMIT_MASK	            0x001f
   #define MP4_ENC_VOP_STRUC1_YLIMIT_MASK	            0x1f00
   #define MP4_ENC_VOP_STRUC1_MBLENGTH_MASK	         0x000f0000
   #define MP4_ENC_VOP_STRUC1_HEADERBIT_MASK          0x1f000000
   #define MP4_ENC_VOP_STRUC1_XLIMIT_BITCNT	         0
   #define MP4_ENC_VOP_STRUC1_YLIMIT_BITCNT	         8
   #define MP4_ENC_VOP_STRUC1_MBLENGTH_BITCNT	      16
   #define MP4_ENC_VOP_STRUC1_HEADERBIT_BITCNT        24
   /*Encoder, MP4_ENC_VOP_STRUC2*/
   #define MP4_ENC_VOP_STRUC2_START_XPOS_MASK         0x001f
   #define MP4_ENC_VOP_STRUC2_START_YPOS_MASK         0x1f00
   #define MP4_ENC_VOP_STRUC2_MBCOUNT_MASK	         0x01ff0000
   #define MP4_ENC_VOP_STRUC2_START_XPOS_BITCNT       0
   #define MP4_ENC_VOP_STRUC2_START_YPOS_BITCNT       8
   #define MP4_ENC_VOP_STRUC2_MBCOUNT_BITCNT	         16
   /*Encoder, MP4_ENC_VOP_STRUC3*/
   #define MP4_ENC_VOP_STRUC3_CURR_XPOS_MASK          0x001f    
   #define MP4_ENC_VOP_STRUC3_CURR_YPOS_MASK          0x1f00    
   #define MP4_ENC_VOP_STRUC3_MBCOUNT_MASK	         0x01ff0000
   #define MP4_ENC_VOP_STRUC3_CURR_XPOS_BITCNT        0
   #define MP4_ENC_VOP_STRUC3_CURR_YPOS_BITCNT        8
   #define MP4_ENC_VOP_STRUC3_MBCOUNT_BITCNT	         16
   /*Encoder, MP4_ENC_MB_STRUC0*/
   #define MP4_ENC_MB_STRUC0_CODEC	                  0x0001
   #define MP4_ENC_MB_STRUC0_TYPE_MASK                0x00e0
   #define MP4_ENC_MB_STRUC0_PATTERN_MASK	            0x03f0
   #define MP4_ENC_MB_STRUC0_DQUANT_MASK	            0x0c00
   #define MP4_ENC_MB_STRUC0_AC		                  0x1000
   #define MP4_ENC_MB_STRUC0_DCVLC_MASK	            0x2000
   #define MP4_ENC_MB_STRUC0_QUANTIZER_MASK	         0xc000
   #define MP4_ENC_MB_STRUC0_CODEC_BITCNT	            0
   #define MP4_ENC_MB_STRUC0_TYPE_BITCNT	            1
   #define MP4_ENC_MB_STRUC0_PATTERN_BITCNT	         5
   #define MP4_ENC_MB_STRUC0_DQUANT_BITCNT	         10
   #define MP4_ENC_MB_STRUC0_AC_BITCNT		            12
   #define MP4_ENC_MB_STRUC0_DCVLC_BITCNT	            13
   #define MP4_ENC_MB_STRUC0_QUANTIZER_BITCNT	      14
   /*Encoder, MP4_ENC_VLC_LIMIT*/
   #define MP4_ENC_VLC_LIMIT_MASK                     0xffff
   /*Encoder, MP4_ENC_RESYNC_CONF0*/
   #define MP4_ENC_RESYNC_CONF0_PERIOD_BITS_MASK      0x3fffffff
   #define MP4_ENC_RESYNC_CONF0_MODE_MB               0x40000000
   #define MP4_ENC_RESYNC_CONF0_MODE_BITS             0x0
   #define MP4_ENC_RESYNC_CONF0_MODE_EN               0x80000000
   /*Encoder, MP4_ENC_RESYNC_CONF1*/
   #define MP4_ENC_RESYNC_CONF1_PERIOD_MB_MASK        0x0000ffff
   #define MP4_ENC_RESYNC_CONF1_HE_VALUE              0x00010000
   /*Encoder, MP4_ENC_TIME_BASE, VTI=VOP_TIME_INCREMENT, MTB=MODULE_TIME_BASE*/
   #define MP4_ENC_TIME_BASE_VTI_MASK                 0x0000ffff
   #define MP4_ENC_TIME_BASE_VTI_BW                   0x000f0000
   #define MP4_ENC_TIME_BASE_MTB_MASK                 0x01f00000
   
   /*Decoder, MP4_DEC_CODEC_CONF*/
   #define MP4_DEC_CODEC_CONF_ENC		               0x0001
   #define MP4_DEC_CODEC_CONF_IRQ		               0x0002
   #define MP4_DEC_CODEC_CONF_DCT		               0x0004
   #define MP4_DEC_CODEC_CONF_VPGOB	                  0x0008
   #define MP4_DEC_CODEC_CONF_STEP	                  0x0010
   #define MP4_DEC_CODEC_CONF_STEP_MASK               0x00f0
   #define MP4_DEC_CODEC_CONF_HALF	                  0x0100
   #define MP4_DEC_CODEC_CONF_FME		               0x0200
   #define MP4_DEC_CODEC_CONF_DQUAN	                  0x0400
   #define MP4_DEC_CODEC_CONF_PMV                     0x0800
   #define MP4_DEC_CODEC_CONF_MC_BURST                0x1000
   #define MP4_DEC_CODEC_CONF_COPY_REC                0x4000
   #define MP4_DEC_CODEC_CONF_DEBLOCK                 0x8000
   #define MP4_DEC_CODEC_CONF_CHECK_TV                0x10000
   /*Decoder, MP4_DEC_IRQ_MASK*/
   #define MP4_DEC_IRQ_MASK_VLD	                     0x0001
   #define MP4_DEC_IRQ_MASK_RLD	                     0x0002
   #define MP4_DEC_IRQ_MASK_MARK	        	            0x0004
   #define MP4_DEC_IRQ_MASK_DEC	                     0x0008
   #define MP4_DEC_IRQ_MASK_BLOCK	                  0x0010
   #define MP4_DEC_IRQ_MASK_DMA	                     0x0020
   /*Decoder, MP4_DEC_IRQ_STS*/
   #define MP4_DEC_IRQ_STS_VLD	                     0x0001
   #define MP4_DEC_IRQ_STS_RLD	                     0x0002
   #define MP4_DEC_IRQ_STS_MARK	        	            0x0004
   #define MP4_DEC_IRQ_STS_DEC	                     0x0008
   #define MP4_DEC_IRQ_STS_BLOCK	                     0x0010
   #define MP4_DEC_IRQ_STS_DMA	                     0x0020
   /*Decoder, MP4_DEC_IRQ_ACK*/
   #define MP4_DEC_IRQ_ACK_VLD	                     0x0001
   #define MP4_DEC_IRQ_ACK_RLD	                     0x0002
   #define MP4_DEC_IRQ_ACK_MARK	        	            0x0004
   #define MP4_DEC_IRQ_ACK_DEC	                     0x0008
   #define MP4_DEC_IRQ_ACK_BLOCK	                     0x0010
   #define MP4_DEC_IRQ_ACK_DMA	                     0x0020
   /*Decoder, MP4_DEC_VOP_STRUC0*/ /*MP4_VOP_STRUC0_XXX = (1 << MP4_VOP_STRUC0_XXX_BITCNT)*/
   #define MP4_DEC_VOP_STRUC0_TYPE	                  0x0001
   #define MP4_DEC_VOP_STRUC0_DATA	                  0x0002
   #define MP4_DEC_VOP_STRUC0_RVLC      	            0x0004
   #define MP4_DEC_VOP_STRUC0_SHORT                   0x0010
   #define MP4_DEC_VOP_STRUC0_FCODE_MASK              0x00e0
   #define MP4_DEC_VOP_STRUC0_QUANT_MASK              0x1f00
   #define MP4_DEC_VOP_STRUC0_VLCTHR_MASK             0xe000
   #define MP4_DEC_VOP_STRUC0_ROUND	                  0x00010000
   #define MP4_DEC_VOP_STRUC0_TYPE_BITCNT	            0
   #define MP4_DEC_VOP_STRUC0_DATA_BITCNT	            1
   #define MP4_DEC_VOP_STRUC0_RVLC_BITCNT	            2
   #define MP4_DEC_VOP_STRUC0_SHORT_BITCNT	         4
   #define MP4_DEC_VOP_STRUC0_FCODE_BITCNT	         5
   #define MP4_DEC_VOP_STRUC0_QUANT_BITCNT	         8
   #define MP4_DEC_VOP_STRUC0_VLCTHR_BITCNT	         13
   #define MP4_DEC_VOP_STRUC0_ROUND_BITCNT	         16
   /*Decoder, MP4_DEC_VOP_STRUC1*/
   #define MP4_DEC_VOP_STRUC1_XLIMIT_MASK	            0x001f
   #define MP4_DEC_VOP_STRUC1_YLIMIT_MASK	            0x1f00
   #define MP4_DEC_VOP_STRUC1_MBLENGTH_MASK	         0x000f0000
   #define MP4_DEC_VOP_STRUC1_HEADERBIT_MASK          0x1f000000
   #define MP4_DEC_VOP_STRUC1_XLIMIT_BITCNT	         0
   #define MP4_DEC_VOP_STRUC1_YLIMIT_BITCNT	         8
   #define MP4_DEC_VOP_STRUC1_MBLENGTH_BITCNT	      16
   #define MP4_DEC_VOP_STRUC1_HEADERBIT_BITCNT        24
   /*Decoder, MP4_DEC_VOP_STRUC2*/
   #define MP4_DEC_VOP_STRUC2_START_XPOS_MASK         0x001f
   #define MP4_DEC_VOP_STRUC2_START_YPOS_MASK         0x1f00
   #define MP4_DEC_VOP_STRUC2_MBCOUNT_MASK	         0x01ff0000
   #define MP4_DEC_VOP_STRUC2_START_XPOS_BITCNT       0
   #define MP4_DEC_VOP_STRUC2_START_YPOS_BITCNT       8
   #define MP4_DEC_VOP_STRUC2_MBCOUNT_BITCNT	         16
   /*Decoder, MP4_DEC_MB_STRUC0*/
   #define MP4_DEC_MB_STRUC0_CODEC	                  0x0001
   #define MP4_DEC_MB_STRUC0_TYPE_MASK                0x00e0
   #define MP4_DEC_MB_STRUC0_PATTERN_MASK	            0x03f0
   #define MP4_DEC_MB_STRUC0_DQUANT_MASK	            0x0c00
   #define MP4_DEC_MB_STRUC0_AC		                  0x1000
   #define MP4_DEC_MB_STRUC0_DCVLC_MASK	            0x2000
   #define MP4_DEC_MB_STRUC0_QUANTIZER_MASK	         0x0007c000
   #define MP4_DEC_MB_STRUC0_CODEC_BITCNT	            0
   #define MP4_DEC_MB_STRUC0_TYPE_BITCNT	            1
   #define MP4_DEC_MB_STRUC0_PATTERN_BITCNT	         5
   #define MP4_DEC_MB_STRUC0_DQUANT_BITCNT	         10
   #define MP4_DEC_MB_STRUC0_AC_BITCNT		            12
   #define MP4_DEC_MB_STRUC0_DCVLC_BITCNT	            13
   #define MP4_DEC_MB_STRUC0_QUANTIZER_BITCNT	      14
   /*Decoder, MP4_DEC_VLC_LIMIT*/
   #define MP4_DEC_VLC_LIMIT_MASK                     0xffff
   
   /*Core, MP4_CORE_CODEC_CONF*/
   #define MP4_CORE_CODEC_CONF_ENC		               0x0001
   #define MP4_CORE_CODEC_CONF_IRQ		               0x0002
   #define MP4_CORE_CODEC_CONF_DCT		               0x0004
   #define MP4_CORE_CODEC_CONF_VPGOB	               0x0008
   #define MP4_CORE_CODEC_CONF_STEP	                  0x0010
   #define MP4_CORE_CODEC_CONF_STEP_MASK              0x00f0
   #define MP4_CORE_CODEC_CONF_HALF	                  0x0100
   #define MP4_CORE_CODEC_CONF_FME		               0x0200
   #define MP4_CORE_CODEC_CONF_DQUAN	               0x0400
   #define MP4_CORE_CODEC_CONF_PMV                    0x0800
   #define MP4_CORE_CODEC_CONF_MC_BURST               0x1000
   #define MP4_CORE_CODEC_CONF_ME_BURST               0x2000
   #define MP4_CORE_CODEC_CONF_COPY_REC               0x4000
   #define MP4_CORE_CODEC_CONF_DEBLOCK                0x8000
   #define MP4_CORE_CODEC_CONF_CHECK_TV               0x10000
   /*Core, MP4_CORE_CONF*/
   #define MP4_CORE_ENC_CONF_SKIP_MASK                0x0000003f
   #define MP4_CORE_ENC_CONF_INTRA_MASK               0x00003f00
   #define MP4_CORE_ENC_CONF_PACK	                  0x00010000
   #define MP4_CORE_ENC_CONF_PCAKCNT_MASK	            0x07fe0000
   /*Core, MP4_CORE_VOP_STRUC0*/ /*MP4_VOP_STRUC0_XXX = (1 << MP4_VOP_STRUC0_XXX_BITCNT)*/
   #define MP4_CORE_VOP_STRUC0_TYPE	                  0x0001
   #define MP4_CORE_VOP_STRUC0_DATA	                  0x0002
   #define MP4_CORE_VOP_STRUC0_RVLC      	            0x0004
   #define MP4_CORE_VOP_STRUC0_SHORT                  0x0010
   #define MP4_CORE_VOP_STRUC0_FCODE_MASK             0x00e0
   #define MP4_CORE_VOP_STRUC0_QUANT_MASK             0x1f00
   #define MP4_CORE_VOP_STRUC0_VLCTHR_MASK            0xe000
   #define MP4_CORE_VOP_STRUC0_ROUND	               0x00010000
   #define MP4_CORE_VOP_STRUC0_TYPE_BITCNT	         0
   #define MP4_CORE_VOP_STRUC0_DATA_BITCNT	         1
   #define MP4_CORE_VOP_STRUC0_RVLC_BITCNT	         2
   #define MP4_CORE_VOP_STRUC0_SHORT_BITCNT	         4
   #define MP4_CORE_VOP_STRUC0_FCODE_BITCNT	         5
   #define MP4_CORE_VOP_STRUC0_QUANT_BITCNT	         8
   #define MP4_CORE_VOP_STRUC0_VLCTHR_BITCNT	         13
   #define MP4_CORE_VOP_STRUC0_ROUND_BITCNT	         16
   /*Core, MP4_CORE_VOP_STRUC1*/
   #define MP4_CORE_VOP_STRUC1_XLIMIT_MASK	         0x001f
   #define MP4_CORE_VOP_STRUC1_YLIMIT_MASK	         0x1f00
   #define MP4_CORE_VOP_STRUC1_MBLENGTH_MASK	         0x000f0000
   #define MP4_CORE_VOP_STRUC1_HEADERBIT_MASK         0x1f000000
   #define MP4_CORE_VOP_STRUC1_XLIMIT_BITCNT	         0
   #define MP4_CORE_VOP_STRUC1_YLIMIT_BITCNT	         8
   #define MP4_CORE_VOP_STRUC1_MBLENGTH_BITCNT	      16
   #define MP4_CORE_VOP_STRUC1_HEADERBIT_BITCNT       24
   /*Core, MP4_CORE_VOP_STRUC2*/
   #define MP4_CORE_VOP_STRUC2_START_XPOS_MASK        0x001f
   #define MP4_CORE_VOP_STRUC2_START_YPOS_MASK        0x1f00
   #define MP4_CORE_VOP_STRUC2_MBCOUNT_MASK	         0x01ff0000
   #define MP4_CORE_VOP_STRUC2_START_XPOS_BITCNT      0
   #define MP4_CORE_VOP_STRUC2_START_YPOS_BITCNT      8
   #define MP4_CORE_VOP_STRUC2_MBCOUNT_BITCNT	      16
   /*Core, MP4_CORE_VOP_STRUC3*/
   #define MP4_CORE_VOP_STRUC3_CURR_XPOS_MASK         0x001f    
   #define MP4_CORE_VOP_STRUC3_CURR_YPOS_MASK         0x1f00    
   #define MP4_CORE_VOP_STRUC3_MBCOUNT_MASK	         0x01ff0000
   #define MP4_CORE_VOP_STRUC3_CURR_XPOS_BITCNT       0
   #define MP4_CORE_VOP_STRUC3_CURR_YPOS_BITCNT       8
   #define MP4_CORE_VOP_STRUC3_MBCOUNT_BITCNT	      16
   /*Core, MP4_CORE_MB_STRUC0*/
   #define MP4_CORE_MB_STRUC0_CODEC	                  0x0001
   #define MP4_CORE_MB_STRUC0_TYPE_MASK               0x00e0
   #define MP4_CORE_MB_STRUC0_PATTERN_MASK	         0x03f0
   #define MP4_CORE_MB_STRUC0_DQUANT_MASK	            0x0c00
   #define MP4_CORE_MB_STRUC0_AC		                  0x1000
   #define MP4_CORE_MB_STRUC0_DCVLC_MASK	            0x2000
   #define MP4_CORE_MB_STRUC0_QUANTIZER_MASK	         0xc000
   #define MP4_CORE_MB_STRUC0_CODEC_BITCNT	         0
   #define MP4_CORE_MB_STRUC0_TYPE_BITCNT	            1
   #define MP4_CORE_MB_STRUC0_PATTERN_BITCNT	         5
   #define MP4_CORE_MB_STRUC0_DQUANT_BITCNT	         10
   #define MP4_CORE_MB_STRUC0_AC_BITCNT		         12
   #define MP4_CORE_MB_STRUC0_DCVLC_BITCNT	         13
   #define MP4_CORE_MB_STRUC0_QUANTIZER_BITCNT	      14
   /*Core, MP4_CORE_VLC_LIMIT*/
   #define MP4_CORE_VLC_LIMIT_MASK                    0xffff
   /*Core, MP4_CORE_RESYNC_CONF0*/
   #define MP4_CORE_RESYNC_CONF0_PERIOD_BITS_MASK     0x3fffffff
   #define MP4_CORE_RESYNC_CONF0_MODE_MB              0x40000000
   #define MP4_CORE_RESYNC_CONF0_MODE_BITS            0x0
   #define MP4_CORE_RESYNC_CONF0_MODE_EN              0x80000000
   /*Core, MP4_CORE_RESYNC_CONF1*/
   #define MP4_CORE_RESYNC_CONF1_PERIOD_MB_MASK       0x0000ffff
   #define MP4_CORE_RESYNC_CONF1_HE_VALUE             0x00010000
   /*Core, MP4_CORE_TIME_BASE, VTI=VOP_TIME_INCREMENT, MTB=MODULE_TIME_BASE*/
   #define MP4_CORE_TIME_BASE_VTI_MASK                0x0000ffff
   #define MP4_CORE_TIME_BASE_VTI_BW                  0x000f0000
   #define MP4_CORE_TIME_BASE_MTB_MASK                0x01f00000

#endif /*DRV_MP4_V1*/

#endif /*VIDEO_HW_H*/


