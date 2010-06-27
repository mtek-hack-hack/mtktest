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
 * l1audio_def.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file defines all the hardware/DSP registers used in l1audio module.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef __L1AUDIO_DEF_H
#define __L1AUDIO_DEF_H

#include "l1d_cid.h"
#include "l1d_reg.h"
#include "l1d_data.h"
#include "l1audio.h"

#if defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
#undef IDMA_LONG
#undef IDMA_SHORT
#undef IDMA_CM0
#undef IDMA_PM0
#undef IDMA_DM0
#define IDMA_LONG    IDMA2_LONG
#define IDMA_SHORT   IDMA2_SHORT
#define IDMA_CM0	   IDMA2_CM0
#define IDMA_PM0	   IDMA2_PM0
#define IDMA_DM0	   IDMA2_DM0
#endif

/* -------------------------------------------------------------------------- */
/* Hardware Definition                                                        */
/* -------------------------------------------------------------------------- */
#define IS_EV_BOARD  (defined(MT6208_EVB) || defined(MT6208_CEVB) || defined(MT6205_CEVB) ||  \
                      defined(MT6218_MW001) || defined(MT6218B_EVB) || defined(MT6219_EVB) || \
                      defined(MT6217_EVB) || defined(MT6228_EVB) || defined(MT6229_EVB) || defined(MT6230_EVB) || defined(MT6268T_EVB) || \
                      defined(MT6226_EVB) || defined(MT6226D_EVB) || defined(MT6226M_EVB) || defined(MT6227_EVB) || defined(MT6227D_EVB) || defined(MT6225_EVB) || defined(MT6223_EVB) || defined(MT6235_EVB) || defined(MT6238_EVB) )

/* -------------------------------------------------------------------------- */
/* Data Type Definition                                                       */
/* -------------------------------------------------------------------------- */
#ifndef uint16
typedef kal_uint16   uint16;
typedef kal_int16    int16;
typedef kal_uint32   uint32;
typedef kal_int32    int32;
typedef kal_uint8    uint8;
typedef kal_int8     int8;
typedef kal_bool     bool;
#define true         (kal_bool)(1==1)
#define false        (kal_bool)(1==0)
#endif

/* -------------------------------------------------------------------------- */
/* Assertion check                                                            */
/* -------------------------------------------------------------------------- */
#define ASSERT_REBOOT(st)  EXT_ASSERT(st,0,0,0)

/* -------------------------------------------------------------------------- */
/* ring buffer handling                                                       */
/* -------------------------------------------------------------------------- */

/*
   Example: define a ring buffer of 8 integers, put the value 3 and get it again:

   RINGBUFFER_T(int,8) myBuffer;
   RB_PUT( myBuffer, 3 );

   int value;
   RB_GET( myBuffer, value );
*/

/*
   size must be a power of two
*/
#ifndef RINGBUFFER_T
#define RINGBUFFER_T(elemtype,size) \
   struct \
   { \
      volatile uint32 write; /* must be unsigned */ \
      volatile uint32 read;  /* must be unsigned */ \
      elemtype volatile queue[size]; \
   }

#define RB_SIZE( rb ) \
   ( sizeof( rb.queue ) / sizeof( *rb.queue ) )

#define RB_MASK( rb ) \
   ( RB_SIZE( rb ) - 1 )

#define RB_INIT( rb ) \
   ( rb.read = rb.write = 0 )

#define RB_COUNT( rb ) \
   ( rb.write - rb.read )

#define RB_FULL( rb ) \
   ( RB_COUNT( rb ) >= RB_SIZE( rb ) )

#define RB_EMPTY( rb ) \
   ( rb.write == rb.read )

#define RB_PUT( rb, value ) \
{ \
   ASSERT( !RB_FULL( rb ) ); \
   rb.queue[ rb.write & RB_MASK( rb ) ] = value; \
   ++rb.write; \
}

#define RB_GET( rb, value ) \
{ \
   ASSERT( !RB_EMPTY( rb ) ); \
   value = rb.queue[ rb.read & RB_MASK( rb ) ]; \
   ++rb.read; \
}

#define RB_PEEK( rb, value ) \
{ \
   ASSERT( !RB_EMPTY( rb ) ); \
   value = rb.queue[ rb.read & RB_MASK( rb ) ]; \
}

#define RB_PEEK_THROUGH( rb, idx, value ) \
{ \
   ASSERT( (rb.read+idx) < rb.write ); \
   value = rb.queue[ (rb.read+idx) & RB_MASK( rb ) ]; \
}

#define RB_CONSUME( rb ) \
{ \
   ASSERT( !RB_EMPTY( rb ) ); \
   ++rb.read; \
}

#define RB_UNPUT( rb, value ) \
{ \
   ASSERT( !RB_EMPTY( rb ) ); \
   --rb.write; \
   value = rb.queue[ rb.write & RB_MASK( rb ) ]; \
}

#define RB_UNGET( rb, value ) \
{ \
   ASSERT( !RB_FULL( rb ) ); \
   --rb.read; \
   rb.queue[ rb.read & RB_MASK( rb ) ] = value; \
}

#endif /* RINGBUFFER_T */
/* -------------------------------------------------------------------------- */

/* DSP to CPU interrupt for Voice Memo (SHARE_D2MCON) */
#define DSP_ENA_VM_INTERRUPT     0x0010
/* DSP to CPU interrupt for A/V Sync (SHARE_D2MCON) */
#define DSP_ENA_AVSYNC_INTERRUPT 0x0020

/* -------------------------------------------------------------------------- */
/* DSP to MCU interrupt magic number definition                               */
/* -------------------------------------------------------------------------- */
#define DP_D2C_PCM_R             0x0011
#define DP_D2C_PCM_P             0x0010
#define DP_D2C_DAF               0x1111
#define DP_D2C_AAC               0x2222
#define DP_D2C_SE_SD_DONE        0xDDEE
#define DP_D2C_SE_DONE           0xEE01
#define DP_D2C_SD_DONE           0xDD01
#define DP_D2C_AVSYNC            0x1234
#define DP_D2C_PCM_TCH_R         0xAA55
#define DP_D2C_VR_REQ            0x0012
#define DP_D2C_WAV_REC           0xAA56
#define DP_D2C_PCM_EX            0x0014
#define DP_D2C_WMA               0x3333
#define DP_D2C_WT                0x0013
#define DP_D2C_AWBPLUS           0xBBBB
#define DP_D2C_PCM_RUT           0xABCD
#define DP_D2C_3G                0x3333

/* -------------------------------------------------------------------------- */
/* DSP Internal memory access                                                 */
/* -------------------------------------------------------------------------- */
#if defined(MT6205B)
#define DSP_IN_FIR_COEFF_IN_ADDR    0x3C00
#define DSP_OUT_FIR_COEFF_OUT_ADDR  0x3C1E
#elif defined(MT6219) || defined(MT6217)
#define DSP_IN_FIR_COEFF_IN_ADDR    0x3FB4
#define DSP_OUT_FIR_COEFF_OUT_ADDR  0x3FD2
#elif defined(MT6228) || defined(MT6225)
#define DSP_IN_FIR_COEFF_IN_ADDR    0x38B2
#define DSP_OUT_FIR_COEFF_OUT_ADDR  0x38DF
#elif defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P)  || defined(MT6235) || defined(MT6238)
#define DSP_IN_FIR_COEFF_IN_ADDR    0x3F4A
#define DSP_OUT_FIR_COEFF_OUT_ADDR  0x3F77
#elif defined(MT6226_S00) || defined(MT6226M_S00) || defined(MT6227_S00)
#define DSP_IN_FIR_COEFF_IN_ADDR    0x3800
#define DSP_OUT_FIR_COEFF_OUT_ADDR  0x382D
#elif defined(MT6226_S01) || defined(MT6226M_S01) || defined(MT6227_S01) || defined(MT6226_S02) || defined(MT6226M_S02) || defined(MT6227_S02) || defined(MT6227D) || defined(MT6226D)
#define DSP_IN_FIR_COEFF_IN_ADDR    0x3872
#define DSP_OUT_FIR_COEFF_OUT_ADDR  0x389F
#else
#error new DSP FIR address is required for new CHIPSET
#endif

// Speech Engineer Parameter
#if !defined(MT6205B)
   #if defined(MT6219) || defined(MT6217)
   #define DSP_CPARA_ADDR   (DSP_DM_ADDR(0, (0x3fa8+0)))
   #define DSP_MPARA_ADDR   (DSP_DM_ADDR(0, (0x3fa8+12)))
   #elif defined(MT6227D) || defined(MT6226D)
   #define DSP_CPARA_ADDR   (DSP_DM_ADDR(0, (0x3f3d+0)))
   #define DSP_MPARA_ADDR   (DSP_DM_ADDR(0, (0x3f3d+12)))
   #elif defined(MT6226) || defined(MT6226M) || defined(MT6227) || defined(MT6229_S00) || defined(MT6230_S00)
   #define DSP_CPARA_ADDR   (DSP_DM_ADDR(0, (0x3fc8+0)))
   #define DSP_MPARA_ADDR   (DSP_DM_ADDR(0, (0x3fc8+12)))
   #elif defined(MT6229_S01) || defined(MT6230_S01)
   #define DSP_CPARA_ADDR   (DSP_DM_ADDR(2, (0x0000+0)))
   #define DSP_MPARA_ADDR   (DSP_DM_ADDR(2, (0x0000+12)))
   #elif defined(MT6229_S02) || defined(MT6230_S02) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
   #define DSP_CPARA_ADDR   (DSP_DM_ADDR(2, (0x3F96+0)))
   #define DSP_MPARA_ADDR   (DSP_DM_ADDR(2, (0x3F96+12)))
   #elif defined(MT6223) || defined(MT6223P)
   #define DSP_CPARA_ADDR   (DSP_DM_ADDR(1, (0x3F96+0)))
   #define DSP_MPARA_ADDR   (DSP_DM_ADDR(1, (0x3F96+12)))
   #elif defined(MT6228) || defined(MT6225)
   #define DSP_CPARA_ADDR   (DSP_DM_ADDR(0, (0x3be8+0)))
   #define DSP_MPARA_ADDR   (DSP_DM_ADDR(0, (0x3be8+12)))
   #else
   #error new DSP speech enhancement parameter address is required for new CHIPSET
   #endif
#endif //...!(defined(MT6208) || defined(MT6205) || defined(MT6205B))

/* -------------------------------------------------------------------------- */


#define AMR_AWB_AUDIO_PATH_SUPPORT   !( defined(MT6217) || defined(MT6219) || defined(MT6223) || defined(MT6223P) || defined(MT6205B) || defined(MT6226_S00) || defined(MT6226M_S00) || defined(MT6227_S00) || defined(MT6228_S01) || defined(MT6228_S00) || defined(MT6229_S00) || defined(MT6230_S00) )

#define DPRAM_base(a)                        ((volatile uint16*)DPRAM_CPU_base+(a))
#define DPRAM2_base(a)                       ((volatile uint16*)DPRAM2_CPU_base+(a))

#if defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)

#define DP_SP_CODEC_CTRL_base(a)             (DPRAM2_base(0x105)+(a))
#define DP_SP_AUDIO_INTERFACE_CTRL_base(a)   (DP_SP_CODEC_CTRL_base(0x09)+(a))
#define DP_SP_KT_CTRL_base(a)                (DP_SP_AUDIO_INTERFACE_CTRL_base(0x13)+(a))
#define DP_SP_8kPCM_CTRL_base(a)             (DP_SP_KT_CTRL_base(0x0A)+(a))
#define DP_SP_VM_CTRL_base(a)                (DP_SP_8kPCM_CTRL_base(0x15)+(a))
#define DP_SP_HO_SID_base(a)                 (DP_SP_VM_CTRL_base(0x4E)+(a))
#define DP_SP_AEC_CTRL_base(a)               (DP_SP_HO_SID_base(0x12)+(a))
#define DP_SP_VR_CTRL_base(a)                (DP_SP_AEC_CTRL_base(0x0F)+(a))
#define DP_SP_AUDIO_CTRL_base(a)             (DP_SP_VR_CTRL_base(0x0E)+(a))
#define DP_SP_AUDIO_ENHANCE_base(a)          (DP_SP_AUDIO_CTRL_base(0xF)+(a))
#define DP_DEBUG_FIELD_base(a)               (DP_SP_AUDIO_ENHANCE_base(0x18)+(a))
#define DP_AUDIO_CTRL_base(a)                (DPRAM2_base(0x1FC)+(a))
#define DP_AV_SYNC_CTRL_base(a)              (DPRAM2_base(0x202)+(a))
#define DP_WAV_CTRL_base(a)                  (DPRAM2_base(0x20A)+(a))
#define DP_WT_CTRL_base(a)                   (DPRAM2_base(0x20E)+(a))
#define DP_DAF_CTRL_base(a)                  (DPRAM2_base(0x20F)+(a))
#define DP_AUDIO_PP_CTRL_base(a)             (DPRAM2_base(0x22C)+(a))
#define DP_EXTRA_APPLICATION_base(a)         (DPRAM2_base(0x241)+(a))
#define DP_DYNAMIC_DOWNLOAD_base(a)          (DPRAM2_base(0x247)+(a))

#else /* IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION */

#define DP_SP_CODEC_CTRL_base(a)             (DPRAM_base(0x62)+(a))
#define DP_SP_AUDIO_INTERFACE_CTRL_base(a)   (DPRAM_base(0x6B)+(a))
#define DP_SP_KT_CTRL_base(a)                (DPRAM_base(a))
#define DP_SP_VM_CTRL_base(a)                (DPRAM_base(a))
#define DP_AV_SYNC_CTRL_base(a)              (DPRAM_base(0x26A)+(a))
#define DP_DAF_CTRL_base(a)                  (DPRAM_base(0x227)+(a))

#endif /* IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION */


/* To indicate CSD channel types */
#if defined(MT6229) || defined(MT6230) || defined(MT6235) || defined(MT6238)
#define DP_TCH_S0_FLAGS DPRAM2_base(0x021)
#else
#define DP_TCH_S0_FLAGS DPRAM_base(0x08E)
#endif
#define AMR_STATUS         DP_DAF_CTRL_base(0)
#define AMR_PARAM1         DP_DAF_CTRL_base(1)
#define AMR_PARAM2         DP_DAF_CTRL_base(2)
#if !defined(DP_GSM_MODE)
#if defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P)  || defined(MT6235) || defined(MT6238)
#define     LOGI_CHANNEL_BASE             0x0051
#define DP_GSM_MODE             ((DPRAMADDR)(DPRAM_CPU_base+(LOGI_CHANNEL_BASE+0x000)*2))
#else
#define DP_GSM_MODE             ((DPRAMADDR)(DPRAM_CPU_base+0x08D*2))
#endif
#endif

/* -------------------------------------------------------------------------- */
/* Audio Front End Hardware Control Register                                  */
/* -------------------------------------------------------------------------- */
#if defined(MT6217) || defined(MT6219) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
#define  AFE_VMCU_CON   ((APBADDR)(AFE_base+0x0000))        /* AFE MCU Cpntrol Register               */
#define  AFE_VMCU_CON1  ((APBADDR)(AFE_base+0x000C))        /* AFE Voice Analog Circuit Control Register 1   */
#define  AFE_VAC_DCON1  ((APBADDR)(AFE_base+0x000C))        /* AFE Voice Analog Circuit Control Register 1   */
#define  AFE_VDB_CON    ((APBADDR)(AFE_base+0x0014))        /* AFE Voice DAI Blue Tooth Control Register     */
#define  AFE_VLB_CON    ((APBADDR)(AFE_base+0x0018))        /* AFE Voice Loop-back Mode Control Register     */
#define  AFE_AMCU_CON0  ((APBADDR)(AFE_base+0x0020))        /* AFE Audio MCU Control Register 0gister        */
#define  AFE_AMCU_CON1  ((APBADDR)(AFE_base+0x0024))        /* AFE Audio Control Register 1                  */
#define  AFE_EDI_CON    ((APBADDR)(AFE_base+0x0028))        /* AFE Audio EDI(I2S , EIAJ) Control Register    */
#define  AFE_EQCOEF     ((APBADDR)(AFE_base+0x0040))        /* AFE Audio EQ Coefficients                     */
#define  AFE_VAGC_CON0  ((APBADDR)(AFE_base+0x0100))        /* AFE Audio AGC Control Register 0              */
#define  AFE_VAGC_CON1  ((APBADDR)(AFE_base+0x0104))        /* AFE Audio AGC Control Register 1              */
#define  AFE_VAGC_CON2  ((APBADDR)(AFE_base+0x0108))        /* AFE Audio AGC Control Register 2              */
#define  AFE_VAGC_CON3  ((APBADDR)(AFE_base+0x010c))        /* AFE Audio AGC Control Register 3              */
#define  AFE_VAGC_CON4  ((APBADDR)(AFE_base+0x0110))        /* AFE Audio AGC Control Register 4              */
#define  AFE_VAGC_CON5  ((APBADDR)(AFE_base+0x0114))        /* AFE Audio AGC Control Register 5              */
#define  AFE_VAGC_CON6  ((APBADDR)(AFE_base+0x0118))        /* AFE Audio AGC Control Register 6              */
#define  ACIF_AC_HW_VER ((APBADDR)(MIXED_base+0x0004))      /* Mix-signal Chip Version Control               */
#define  AFE_VAG_CON    ((APBADDR)(MIXED_base+0x0100))      /* AFE Voice Analog Gain Control Register        */
#define  AFE_VAC_CON0   ((APBADDR)(MIXED_base+0x0104))      /* AFE Voice Analog-Circuit Control Register 0   */
#define  AFE_VAC_CON1   ((APBADDR)(MIXED_base+0x0108))      /* AFE Voice Analog-Circuit Control Register 1   */
#define  AFE_VAPDN_CON  ((APBADDR)(MIXED_base+0x010C))      /* AFE Voice Analog Power Down Control Register  */
#define  AFE_VAGC_CON   ((APBADDR)(MIXED_base+0x0110))      /* AFE Voice AGC Control Register  */
#define  AFE_AAG_CON    ((APBADDR)(MIXED_base+0x0200))      /* AFE Audio Analog Gain Control Register        */
#define  AFE_AAC_CON    ((APBADDR)(MIXED_base+0x0204))      /* AFE Audio Analog-Circuit Control Register     */
#define  AFE_AAPDN_CON  ((APBADDR)(MIXED_base+0x0208))      /* AFE Audio Analog Power Down Control Register  */
#define  AFE_AAC_NEW    ((APBADDR)(MIXED_base+0x020C))      /* Enhanced Audio AFE Control and Parameters     */
#endif

/* -------------------------------------------------------------------------- */
/* DSP Share Registers                                                        */
/* -------------------------------------------------------------------------- */
#define SHARE_DSPCON    ((APBADDR)(SHARE_base+0x0000))       /* DSP Control Register                      */
#define SHARE_M2DI1     ((APBADDR)(SHARE_base+0x0004))       /* MCU-to-DSP Interrupt1 Register            */
#define SHARE_M2DI2     ((APBADDR)(SHARE_base+0x0008))       /* MCU-to-DSP Interrupt2 Register            */
#define SHARE_D2MCON    ((APBADDR)(SHARE_base+0x000C))       /* DSP-to-MCU Interrupt Control Register     */
#define SHARE_D2MSTA    ((APBADDR)(SHARE_base+0x0010))       /* DSP-to-MCU Interrupt Status Register      */
#define SHARE_D2MTID    ((APBADDR)(SHARE_base+0x0014))       /* DSP Task Identification Register          */
#if defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P)  || defined(MT6235) || defined(MT6238)
/*  For Slave DSP  */
#define SHARE2_DSPCON   ((APBADDR)(SHARE2_base+0x0000))      /* DSP Control Register                      */
#define SHARE2_M2DI1    ((APBADDR)(SHARE2_base+0x0004))      /* MCU-to-DSP Interrupt1 Register            */
#define SHARE2_M2DI2    ((APBADDR)(SHARE2_base+0x0008))      /* MCU-to-DSP Interrupt2 Register            */
#define SHARE2_D2MCON   ((APBADDR)(SHARE2_base+0x000C))      /* DSP-to-MCU Interrupt Control Register     */
#define SHARE2_D2MSTA   ((APBADDR)(SHARE2_base+0x0010))      /* DSP-to-MCU Interrupt Status Register      */
#define SHARE2_D2MTID   ((APBADDR)(SHARE2_base+0x0014))      /* DSP Task Identification Register          */
#endif
/* -------------------------------------------------------------------------- */
/* DSP to CPU interrupts fields                                               */
/* -------------------------------------------------------------------------- */
#if defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P)  || defined(MT6235) || defined(MT6238)
#define DP2_D2C_TASK0            DPRAM2_base(0)         /* 1st FW tsk interrupt                      */
#define DP2_D2C_TASK1            DPRAM2_base(1)         /* 2nd FW tsk interrupt                      */
#define DP2_D2C_TASK2            DPRAM2_base(2)         /* 3rd FW tsk interrupt                      */
#define DP2_D2C_TASK3            DPRAM2_base(3)         /* 4th FW tsk interrupt                      */
#define DP2_D2C_TASK4            DPRAM2_base(4)         /* 5th FW tsk interrupt                      */
#define DP2_D2C_TASK5            DPRAM2_base(5)         /* 6th FW tsk interrupt                      */
#define DP2_D2C_TASK6            DPRAM2_base(6)         /* 7th FW tsk interrupt                      */
#define DP2_D2C_TASK7            DPRAM2_base(7)         /* 8th FW tsk interrupt                      */
#endif

#if defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
#define DP_D2C_TASK0            DP2_D2C_TASK0         /* 1st FW tsk interrupt                      */
#define DP_D2C_TASK1            DP2_D2C_TASK1         /* 2nd FW tsk interrupt                      */
#define DP_D2C_TASK2            DP2_D2C_TASK2         /* 3rd FW tsk interrupt                      */
#define DP_D2C_TASK3            DP2_D2C_TASK3         /* 4th FW tsk interrupt                      */
#define DP_D2C_TASK4            DP2_D2C_TASK4         /* 5th FW tsk interrupt                      */
#define DP_D2C_TASK5            DP2_D2C_TASK5         /* 6th FW tsk interrupt                      */
#define DP_D2C_TASK6            DP2_D2C_TASK6         /* 7th FW tsk interrupt                      */
#define DP_D2C_TASK7            DP2_D2C_TASK7         /* 8th FW tsk interrupt                      */
#else
#define DP_D2C_TASK0            DPRAM_base(0)         /* 1st FW tsk interrupt                      */
#define DP_D2C_TASK1            DPRAM_base(1)         /* 2nd FW tsk interrupt                      */
#define DP_D2C_TASK2            DPRAM_base(2)         /* 3rd FW tsk interrupt                      */
#define DP_D2C_TASK3            DPRAM_base(3)         /* 4th FW tsk interrupt                      */
#define DP_D2C_TASK4            DPRAM_base(4)         /* 5th FW tsk interrupt                      */
#define DP_D2C_TASK5            DPRAM_base(5)         /* 6th FW tsk interrupt                      */
#define DP_D2C_TASK6            DPRAM_base(6)         /* 7th FW tsk interrupt                      */
#define DP_D2C_TASK7            DPRAM_base(7)         /* 8th FW tsk interrupt                      */
#endif

/* -------------------------------------------------------------------------- */
/* Speech CODEC control field                                                 */
/* -------------------------------------------------------------------------- */
#define DP_SC_FLAGS           DP_SP_CODEC_CTRL_base(0)   /* speech coder enabling flag [0]            */
                                                         /* speech decoder enable flag [1]            */
                                                         /* speech coder reset flag [4]               */
                                                         /* speech decoder reset flag [5]             */
                                                         /* 1'st speech coder flag [6]                */
                                                         /* 1'st speech decoder flag [7]              */
                                                         /* noise suppression enabling flag [8]       */
                                                         /* VBI PCM read reset flag [9]               */
                                                         /* VBI PCM write reset flag [10]             */
                                                         /* Voice Memo - Record [11]                  */
                                                         /* Voice Memo - Playback [13:12]             */
                                                         /* AMR Rate Control [14]                     */
                                                         /* AMR Handover Flag [15]                    */
#define DP_DEL_PCM_R          DP_SP_CODEC_CTRL_base(1)   /* delay for the VBI PCM read                */
#define DP_DEL_PCM_W          DP_SP_CODEC_CTRL_base(2)   /* delay for the start of speech decoder     */
#define DP_MARGIN_PCM_W       DP_SP_CODEC_CTRL_base(3)   /* margin for the VBI PCM write [7:0]        */
                                                         /* SID detection threshold LOW [9:8]         */
                                                         /* SID detection threshold High [15:10]      */
#define DP_SC_MODE            DP_SP_CODEC_CTRL_base(4)   /* CODEC type for speech decoder [7:0]       */
                                                         /* CODEC type for speech coder [15:8]        */
#define DP_SC_VAD             DP_SP_CODEC_CTRL_base(5)   /* VAD: FR, HR, EFR, AMR1m AMR2              */
#define DP_SC_MUTE            DP_SP_CODEC_CTRL_base(6)   /* speech coder muting flag [0]              */
                                                         /* speech decoder muting flag [1]            */
                                                         /* Nsync reset mode [4]                      */
                                                         /* Nsync followed by ETSI/Stepmind [5]       */
                                                         /* Nsync reset value only used in MCU [15:8] */
#define DP_NSYNC_NOT_ETSI_C   DP_SP_CODEC_CTRL_base(6)
#define DP_SC_EVLUATE_DELAY   DP_SP_CODEC_CTRL_base(7)   /* DSP evaluate speech delay offset while MCU extend frame  */
#define DP_Offset_Count       DP_SP_CODEC_CTRL_base(7)   /* Quater bits offset for Handover           */
#define DP_NSYNC_VALUE        DP_SP_CODEC_CTRL_base(8)   /* Bsync value used in a handover            */

/* -------------------------------------------------------------------------- */
/* Audio control field                                                        */
/* -------------------------------------------------------------------------- */
#define DP_VOL_OUT_PCM        DP_SP_AUDIO_INTERFACE_CTRL_base(0)  /* gain on PCM output                        */
#define DP_AUDIO_PAR          DP_SP_AUDIO_INTERFACE_CTRL_base(1)  /* input filtering flag [0]                  */
                                                                  /* output filtring flag [1]                  */
                                                                  /* PCM samples must be sent to DAI port for BT connection [2] */
                                                                  /* 16k Switch (0:DSP/1:HW) [4]               */
                                                                  /* DAI mode 0 [8]                            */
                                                                  /* DAI mode 1 [9]                            */
                                                                  /* DAI mode 2 [10]                           */
                                                                  /* DAI mode 3 [11]                           */
                                                                  /* BT cordless mode [12]                     */
                                                                  /* BT earphone mode [13]                     */
                                                                  /* speech mode [15]                          */
#define DP_AFI_COEF_LEN       DP_SP_AUDIO_INTERFACE_CTRL_base(2)  /* length of input audio filter              */
#define DP_AFI_COEF_ADD       DP_SP_AUDIO_INTERFACE_CTRL_base(3)  /* address of input audio filter             */
#define DP_AFO_COEF_LEN       DP_SP_AUDIO_INTERFACE_CTRL_base(4)  /* length of output audio filter             */
#define DP_VOL_IN_PCM         DP_SP_AUDIO_INTERFACE_CTRL_base(5)  /* gain on PCM input                         */
#define DP_SIDETONE_VOL       DP_SP_AUDIO_INTERFACE_CTRL_base(6)  /* gain on side-tone                         */

#if defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
#define DP_DigiGain_Setting                  DP_SP_AUDIO_INTERFACE_CTRL_base(7)
#define DP_Audio_Flt_Coeff_Addr              DP_SP_AUDIO_INTERFACE_CTRL_base(8)
#define DP_Audio_Flt_Coeff_Len               DP_SP_AUDIO_INTERFACE_CTRL_base(9)
#define DP_16k_Compen_Flt_Addr               DP_SP_AUDIO_INTERFACE_CTRL_base(12)
#define DP_16k_Compen_Flt_flag               DP_SP_AUDIO_INTERFACE_CTRL_base(13)
#define DP_16k_Compen_Flt_Len                DP_SP_AUDIO_INTERFACE_CTRL_base(14)
#elif defined(MT6225) || defined(MT6228)
#define DP_DigiGain_Setting                  DPRAM_base(0x00F)
#define DP_Audio_Flt_Coeff_Addr              DPRAM_base(0x296)
#define DP_Audio_Flt_Coeff_Len               DPRAM_base(0x297)
#define DP_16k_Compen_Flt_Addr               DPRAM_base(0x280)
#define DP_16k_Compen_Flt_flag               DPRAM_base(0x29a)
#define DP_16k_Compen_Flt_Len                DPRAM_base(0x29b)
#define DP_TCH_HO_SID_SET                    DPRAM_base(0x281)
#define DP_TCH_HO_SID_DATA0                  DPRAM_base(0x282)
#elif defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D)
#define DP_DigiGain_Setting                  DPRAM_base(0x00F)
#define DP_16k_Compen_Flt_flag               DPRAM_base(0x267)
#else
#define DP_DigiGain_Setting                  DPRAM_base(0x00F)
#endif

/* -------------------------------------------------------------------------- */
/* Keytone & Tone                                                             */
/* -------------------------------------------------------------------------- */
#if defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
#define DSP_TONE_CTRL1        (*DP_SP_KT_CTRL_base(0))
#define DSP_TONE_CTRL2        (*DP_SP_KT_CTRL_base(1))
#define DSP_TONE_FORCE_KT_8K  (*DP_SP_KT_CTRL_base(2))
#define DSP_TONE_F1A          (*DP_SP_KT_CTRL_base(3))
#define DSP_TONE_F1B          (*DP_SP_KT_CTRL_base(4))
#define DSP_TONE_AMP1         (*DP_SP_KT_CTRL_base(5))
#define DSP_TONE_F2A          (*DP_SP_KT_CTRL_base(6))
#define DSP_TONE_F2B          (*DP_SP_KT_CTRL_base(7))
#define DSP_TONE_AMP2         (*DP_SP_KT_CTRL_base(8))
#define DP_KT_ATT             (*DP_SP_KT_CTRL_base(9))
#else /* MT6205B, MT6218, MT6218B, MT6219, MT6228, ... */
#define DSP_TONE_F1A          (*DP_SP_KT_CTRL_base(0x042))
#define DSP_TONE_F1B          (*DP_SP_KT_CTRL_base(0x043))
#define DSP_TONE_AMP1         (*DP_SP_KT_CTRL_base(0x044))
#define DSP_TONE_F2A          (*DP_SP_KT_CTRL_base(0x045))
#define DSP_TONE_F2B          (*DP_SP_KT_CTRL_base(0x046))
#define DSP_TONE_AMP2         (*DP_SP_KT_CTRL_base(0x047))
#define DSP_TONE_CTRL1        (*DP_SP_KT_CTRL_base(0x12E))
#define DSP_TONE_CTRL2        (*DP_SP_KT_CTRL_base(0x12F))
#define DP_KT_ATT             (*DP_SP_KT_CTRL_base(0x056))
#endif

/* -------------------------------------------------------------------------- */
/* Voice Memo                                                                 */
/* -------------------------------------------------------------------------- */

#if defined(MT6229_S00) || defined(MT6230_S00)
#define DP_SD1_VM_0           DP_SP_VM_CTRL_base(0)    /* SID indicator [2:1] & TAF[3] & BFI[5]     */
#define DP_SD1_VM_1           DP_SP_VM_CTRL_base(1)    /* information bits d[15:0]                  */
#define DP_SD1_VM_17          DP_SP_VM_CTRL_base(17)    /* information bits d[275:260]              */
#define DP_SD2_VM_0           DP_SP_VM_CTRL_base(18)    /* SP flag [1]                              */
#define DP_SD2_VM_1           DP_SP_VM_CTRL_base(19)    /* information bits d[15:0]                 */
#define DP_SD2_VM_17          DP_SP_VM_CTRL_base(35)    /* information bits d[275:260]              */
#define DP_RX_TCH_S(m, n)    ((DPRAMADDR)(DP_SP_VM_CTRL_base(0)+(m*16+n)))
#define DP_TX_TCH_S(m, n)    ((DPRAMADDR)(DP_SP_VM_CTRL_base(18)+(m*16+n)))
#define DP_SC_TCH_MODE        DP_SD2_VM_17
#define DP_SD_TCH_MODE        DP_SD1_VM_17
#define DP_TX_TCH_S0_0        DP_SD2_VM_0
#define DP_RX_TCH_S0_0        DP_SD1_VM_0

#elif defined(MT6229_S01) || defined(MT6230_S01) || defined(MT6229_S02) || defined(MT6230_S02) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
#define DP_SD1_VM_0           DP_SP_VM_CTRL_base(0x31)    /* SID indicator [2:1] & TAF[3] & BFI[5]     */
#define DP_SD1_VM_1           DP_SP_VM_CTRL_base(0x32)    /* information bits d[15:0]                  */
#define DP_SD1_VM_17          DP_SP_VM_CTRL_base(0x42)    /* information bits d[275:260]              */
#define DP_SD2_VM_0           DP_SP_VM_CTRL_base(0x43)    /* SP flag [1]                              */
#define DP_SD2_VM_1           DP_SP_VM_CTRL_base(0x44)    /* information bits d[15:0]                 */
#define DP_SD2_VM_17          DP_SP_VM_CTRL_base(0x54)    /* information bits d[275:260]              */
#define DP_RX_TCH_S(m, n)    ((DPRAMADDR)(DP_SP_VM_CTRL_base(0)+(m*16+n)))
#define DP_TX_TCH_S(m, n)    ((DPRAMADDR)(DP_SP_VM_CTRL_base(18)+(m*16+n)))
#define DP_SC_TCH_MODE        DP_SP_VM_CTRL_base(0x23)
#define DP_SD_TCH_MODE        DP_SP_VM_CTRL_base(0x11)
#define DP_TX_TCH_S0_0        DP_SP_VM_CTRL_base(0x12)
#define DP_RX_TCH_S0_0        DP_SP_VM_CTRL_base(0x0)

#else /* MT6205B, MT6218, MT6218B, MT6219, MT6228, ... */
#define DP_SD1_VM_0           DP_SP_VM_CTRL_base(0x12)    /* SID indicator [2:1] & TAF[3] & BFI[5]     */
#define DP_SD1_VM_1           DP_SP_VM_CTRL_base(0x13)    /* information bits d[15:0]                  */
#define DP_SD1_VM_17          DP_SP_VM_CTRL_base(0x23)    /* information bits d[275:260]               */
#define DP_SD2_VM_0           DP_SP_VM_CTRL_base(0x24)    /* SP flag [1]                               */
#define DP_SD2_VM_1           DP_SP_VM_CTRL_base(0x25)    /* information bits d[15:0]                  */
#define DP_SD2_VM_17          DP_SP_VM_CTRL_base(0x35)    /* information bits d[275:260]               */
#define DP_TX_TCH_S(m, n)     DPRAM_base(0x147+(m)*56+(n))
#define DP_RX_TCH_S(m, n)     DPRAM_base(0x163+(m)*56+(n))
#define DP_SC_TCH_MODE        DPRAM_base(0x158)
#define DP_SD_TCH_MODE        DPRAM_base(0x174)
#define DP_TX_TCH_S0_0        DP_TX_TCH_S(0, 0)
#define DP_RX_TCH_S0_0        DP_RX_TCH_S(0, 0)

#endif

/* -------------------------------------------------------------------------- */
/* PCM                                                                        */
/* -------------------------------------------------------------------------- */
#if defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
#define DP_ASP_TYPE           DP_AUDIO_CTRL_base(0)
#define DP_ASP_FS             DP_AUDIO_CTRL_base(1)
#define DP_ASP_DEL_W          DP_AUDIO_CTRL_base(2)
#define DP_ASP_DEL_M          DP_AUDIO_CTRL_base(4)
#else
#define DP_Melody_Control     DPRAM_base(0x010)       /* melody enable [0]                         */
#define DP_ASP_TYPE           DPRAM_base(0x05B)
#define DP_ASP_FS             DPRAM_base(0x05C)
#define DP_ASP_DEL_W          DPRAM_base(0x060)
#define DP_ASP_DEL_M          DPRAM_base(0x061)
#endif

#if defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
#define DSP_PCM_CTRL          DP_WAV_CTRL_base(0)
#define DSP_PCM_W             DP_WAV_CTRL_base(1)
#define DSP_PCM_R             DP_WAV_CTRL_base(2)
#define DSP_PCM_MS            DP_WAV_CTRL_base(3)
#define DSP_PCM_REC_CTRL      DP_SP_8kPCM_CTRL_base(0)
#define DSP_PCM_REC_ADDR      DP_SP_8kPCM_CTRL_base(1)
#define DSP_PCM_REC_LEN       DP_SP_8kPCM_CTRL_base(2)
#define DSP_PCM_REC_ADDR2      DP_SP_8kPCM_CTRL_base(3)
#define DSP_PCM_REC_LEN2      DP_SP_8kPCM_CTRL_base(4)
#define DSP_PCM_DGAIN         DP_SP_AUDIO_INTERFACE_CTRL_base(7)

#elif defined(MT6225) || defined(MT6228)
#define DSP_PCM_W             DPRAM_base(0x13)
#define DSP_PCM_REC_ADDR      DPRAM_base(0x29E)
#define DSP_PCM_R             DPRAM_base(0x14)
#define DSP_PCM_REC_LEN       DPRAM_base(0x29F)
#define DSP_PCM_MS            DPRAM_base(0x15)
#define DSP_PCM_CTRL          DPRAM_base(0x5D)
#define DSP_PCM_REC_CTRL      DPRAM_base(0x5E)
#define DSP_PCM_DGAIN         DP_DigiGain_Setting

#else
#define DSP_PCM_W             DPRAM_base(0x13)
#define DSP_PCM_REC_ADDR      DPRAM_base(0x13)
#define DSP_PCM_R             DPRAM_base(0x14)
#define DSP_PCM_REC_LEN       DPRAM_base(0x14)
#define DSP_PCM_MS            DPRAM_base(0x15)
#define DSP_PCM_CTRL          DPRAM_base(0x5D)
#define DSP_PCM_REC_CTRL      DPRAM_base(0x5E)
#define DSP_PCM_DGAIN         DP_DigiGain_Setting
#endif

#if defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D)
   #define DP_PCM_EX_CTRL        (*DPRAM_base(0x25E))
   #define DP_PCM_EX_PTR         (*DPRAM_base(0x291))
   #define DP_PCM_EX_UL_LEN      (*DPRAM_base(0x292))
   #define DP_PCM_EX_DL_LEN      (*DPRAM_base(0x293))
#elif defined(MT6228) || defined(MT6225)
   #define DP_PCM_EX_CTRL        (*DPRAM_base(0x25E))
   #define DP_PCM_EX_PTR         (*DPRAM_base(0x2B3))
   #define DP_PCM_EX_UL_LEN      (*DPRAM_base(0x2B4))
   #define DP_PCM_EX_DL_LEN      (*DPRAM_base(0x2B5))
#elif defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
   #define DP_PCM_EX_CTRL        (*DPRAM2_base(0x197))
   #define DP_PCM_EX_PTR         (*DPRAM2_base(0x19a))
   #define DP_PCM_EX_UL_LEN      (*DPRAM2_base(0x19b))
   #define DP_PCM_EX_DL_LEN      (*DPRAM2_base(0x19c))
#endif

/* -------------------------------------------------------------------------- */
/* CTM                                                                        */
/* -------------------------------------------------------------------------- */

#if defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D)
   #define DP_CTM_CODEC_CTRL               (*DPRAM_base(0x25F))    // 4 LSBs for DSP CTM state
   #define DP_CTM_COSIM_CTRL               (*DPRAM_base(0x29E))
   #define DP_BFI_FACCH_REPORT             (*DPRAM_base(0x290))
   #define DP_CTM_AMR_CODEBOOK_GAIN_LIMIT  (*DPRAM_base(0x29C))
   #define DP_CTM_AMR_CODEBOOK_GAIN_UPDATE (*DPRAM_base(0x29D))
#elif defined(MT6228) || defined(MT6225)
   #define DP_CTM_CODEC_CTRL               (*DPRAM_base(0x25F))    // 4 LSBs for DSP CTM state
   #define DP_CTM_COSIM_CTRL               (*DPRAM_base(0x2C2))
   #define DP_BFI_FACCH_REPORT             (*DPRAM_base(0x2B2))
   #define DP_CTM_AMR_CODEBOOK_GAIN_LIMIT  (*DPRAM_base(0x2B6))
   #define DP_CTM_AMR_CODEBOOK_GAIN_UPDATE (*DPRAM_base(0x2B7))
#elif defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
   #define DP_CTM_CODEC_CTRL               (*DPRAM2_base(0x198))    // 4 LSBs for DSP CTM state
   #define DP_CTM_COSIM_CTRL               (*DPRAM2_base(0x19F))
   #define DP_BFI_FACCH_REPORT             (*DPRAM2_base(0x199))
   #define DP_CTM_AMR_CODEBOOK_GAIN_LIMIT  (*DPRAM2_base(0x19D))
   #define DP_CTM_AMR_CODEBOOK_GAIN_UPDATE (*DPRAM2_base(0x19E))
#endif


/* -------------------------------------------------------------------------- */
/* AMR-WB playback control                                                    */
/* -------------------------------------------------------------------------- */
#if defined(MT6229_S00) || defined(MT6230_S00)
#define DP_SD2_AWB_VM_0       DP_SP_VM_CTRL_base(0x20)     /* TX_Type [7:0] SE codec mode [15:8]    */
#define DP_SD2_AWB_VM_1       DP_SP_VM_CTRL_base(0x21)     /* information bits d[15:0]              */
#define DP_SD2_AWB_VM_18      DP_SP_VM_CTRL_base(0x32)     /* information bits d[303:288]           */
#define DP_AWB_SE_CTRL        DP_SP_AUDIO_CTRL_base(10)
#define DP_AWB_SD_CTRL        DP_SP_AUDIO_CTRL_base(11)
#elif defined(MT6229_S01) || defined(MT6230_S01) || defined(MT6229_S02) || defined(MT6230_S02) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
#define DP_SD1_AWB_VM_0       DP_SP_VM_CTRL_base(0x24)        /* TX_Type [7:0] SE codec mode [15:8]    */
#define DP_SD1_AWB_VM_1       DP_SP_VM_CTRL_base(0x25)        /* information bits d[15:0]              */
#define DP_SD1_AWB_VM_18      DP_SP_VM_CTRL_base(0x36)        /* information bits d[303:288]           */
#define DP_SD2_AWB_VM_0       DP_SP_VM_CTRL_base(0x43)        /* TX_Type [7:0] SE codec mode [15:8]    */
#define DP_SD2_AWB_VM_1       DP_SP_VM_CTRL_base(0x44)        /* information bits d[15:0]              */
#define DP_SD2_AWB_VM_18      DP_SP_VM_CTRL_base(0x70)   /* information bits d[303:288]           */
#define DP_AWB_SE_CTRL        DP_SP_AUDIO_CTRL_base(10)
#define DP_AWB_SD_CTRL        DP_SP_AUDIO_CTRL_base(11)
#else
#define DP_SD2_AWB_VM_0       DPRAM_base(0x030)     /* TX_Type [7:0] SE codec mode [15:8]    */
#define DP_SD2_AWB_VM_1       DPRAM_base(0x031)     /* information bits d[15:0]              */
#define DP_SD2_AWB_VM_18      DPRAM_base(0x11E)     /* information bits d[303:288]           */
#define DP_AWB_SE_CTRL        DPRAM_base(0x2AE)
#define DP_AWB_SD_CTRL        DPRAM_base(0x2AF)
#endif

#if defined(MT6229) || defined(MT6230) || defined(MT6235) || defined(MT6238)
#define AWBPLUS_STATUS            DP_DAF_CTRL_base(0)
#define AWBPLUS_FIFO_BASE         DP_DAF_CTRL_base(1)  /* Indicate start point for MCU to DSP stream transfer */
#define AWBPLUS_CONFIG_BASE       DP_DAF_CTRL_base(2)  /* Indicate start point for MCU to DSP configuration   */
#define AWBPLUS_ERROR_REPORT      DP_DAF_CTRL_base(3)  /* Indicate the error status                 */
#endif

/* -------------------------------------------------------------------------- */
/* DAF/AAC/WMA playback control                                               */
/* -------------------------------------------------------------------------- */
#define DAF_MAIN_CONTROL      DP_DAF_CTRL_base(0)  /* Start/Stop [0]                            */
                                                   /* Pause [1]                                 */
                                                   /* MP3 Reset [2]                             */
                                                   /* EQ_Enable [3]                             */
#define DAF_STATUS            DP_DAF_CTRL_base(1)
#define DAF_FIFO_BASE         DP_DAF_CTRL_base(2)  /* Indicate start point for MCU to DSP stream transfer */
#define DAF_FIFO_LENGTH       DP_DAF_CTRL_base(3)  /* Indicate FIFO size                        */
#define DAF_DSP_READ_PTR      DP_DAF_CTRL_base(4)  /* Indicate the next word DSP will read      */
#define DAF_MCU_WRITE_PTR     DP_DAF_CTRL_base(5)  /* Indicate the next word MCU will write     */
#define DAF_EQ_BASE_ADDR      DP_DAF_CTRL_base(6)
#define DAF_FRAME_COUNT       DP_DAF_CTRL_base(7)
#define DAF_DSP_DGAIN         DP_DigiGain_Setting  /* Digital Gain                              */

/* ------------------------------- */
#define AAC_MAIN_CONTROL      DP_DAF_CTRL_base(0)  /* Start/Stop [0]                            */
#define AAC_STATUS            DP_DAF_CTRL_base(1)
#define AAC_FIFO_BASE         DP_DAF_CTRL_base(2)  /* Indicate start point for MCU to DSP stream transfer */
#define AAC_FIFO_LENGTH       DP_DAF_CTRL_base(3)  /* Indicate FIFO size                        */
#define AAC_DSP_READ_PTR      DP_DAF_CTRL_base(4)  /* Indicate the next word DSP will read      */
#define AAC_MCU_WRITE_PTR     DP_DAF_CTRL_base(5)  /* Indicate the next word MCU will write     */
#define AAC_ERROR_REPORT      DP_DAF_CTRL_base(6)  /* Indicate the error status                 */
#define AAC_DSP_REPORT        DP_DAF_CTRL_base(7)  /* Checksum DSP status check                 */
#define AACPS_CHKSUM_ENABLE   DP_DAF_CTRL_base(6)  /* Indicate the error status */
#define AACPS_OUTPUT_CHK_SUM  DP_DAF_CTRL_base(7)  /* Checksum DSP status check */
#define AAC_DSP_DGAIN         DP_DigiGain_Setting
#define AAC_PS_CONTROL             DP_DAF_CTRL_base(0)
#define AACPS_BS_FLAG              DP_DAF_CTRL_base(1)
#define AAC_PS_BITSTR_ADDRESS      DP_DAF_CTRL_base(2)
#define AAC_PS_BITSTR_Length       DP_DAF_CTRL_base(3)
#define AAC_PS_PCM_ADDRESS         DP_DAF_CTRL_base(4)
#define AAC_PS_PCM_DMOVLAY         DP_DAF_CTRL_base(5)
#define AAC_PS_PCM_CHECKSUM        DP_DAF_CTRL_base(6)

/*  AMR_AWB_AUDIO_PATH_SUPPORT    */

#define AMR_AWB_AUDIO_PATH_CTRL    DP_DAF_CTRL_base(0)

// BSAC
#if defined(BSAC_DECODE)

#if defined(MT6229_S02) || defined(MT6230_S02) || defined(MT6268T) || defined(MT6238)
  #define BSAC_NUN_OF_SUB_FRAME        DP_DAF_CTRL_base(9)
  #define BSAC_LAYER_LENTH             DP_DAF_CTRL_base(10)
#elif defined(MT6228_S02)
  #define BSAC_NUN_OF_SUB_FRAME        DPRAM_base(0x260)
  #define BSAC_LAYER_LENTH             DPRAM_base(0x261)
#else
   #error BSAC NOT SUPPORTED
#endif

#endif //BSAC_DECODE


#if defined(AAC_PLUS_DECODE)

#if defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D)
#define AACPLUS_STATUS        DPRAM_base(0x048)
#define AACPLUS_CNTROL_WORD   DPRAM_base(0x029A)
#elif defined(MT6228) || defined(MT6225)
#define AACPLUS_STATUS        DPRAM_base(0x03A)
#define AACPLUS_CNTROL_WORD   DPRAM_base(0x02AB)
#elif defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
#define AACPLUS_STATUS	      (DPRAM2_base(0x22F))
#define AACPLUS_CNTROL_WORD   (DPRAM2_base(0x1CF))

#else
   #error AAC PLUS NOT SUPPORTED
#endif

#endif //AAC_PLUS_DECODE

/* ------------------------------- */
#if defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
#define WMA_STATUS            DP_DAF_CTRL_base(0)  /* Idle/Init/Running/End                     */
#define WMA_DEBUG             DP_DAF_CTRL_base(1)  /* Checksum DSP status check                 */
#define WMA_BUFFER_LENGTH     DP_DAF_CTRL_base(2)  /* Indicate FIFO size                        */
#define WMA_BUFFER_BASE       DP_DAF_CTRL_base(3)  /* Indicate FIFO base                        */
#define WMA_BUFFER_DSP_READ   DP_DAF_CTRL_base(3)  /* Indicate the next word DSP will read      */
#define WMA_BUFFER_MCU_WRITE  DP_DAF_CTRL_base(4)  /* Indicate the next word MCU will write     */
#define WMA_NUM_CHANNELS      DP_DAF_CTRL_base(5)
#define WMA_SAMPLING_RATE     DP_DAF_CTRL_base(6)
#define WMA_VERSION_NUMBER    DP_DAF_CTRL_base(7)
#define WMA_BYTES_PER_SECONDS DP_DAF_CTRL_base(8)
#define WMA_PACKET_LENGTH     DPRAM2_base(0x22F)
#define WMA_ENCODE_OPT        DPRAM2_base(0x230)   /* Encode Option                             */
#define WMA_CNTROL_WORD       DPRAM2_base(0x1CF)   /* Enable/Disable WMA                        */
#define WMA_DSP_DGAIN         DP_DigiGain_Setting
#define WMA_Soft_Reset	      DPRAM2_base(0x0238)
#define WMA_TOTAL_FRAME       DPRAM2_base(0x0239)
#else
#define WMA_STATUS            DP_DAF_CTRL_base(0)  /* Idle/Init/Running/End                     */
#define WMA_DEBUG             DP_DAF_CTRL_base(1)  /* Checksum DSP status check                 */
#define WMA_BUFFER_LENGTH     DP_DAF_CTRL_base(2)
#define WMA_BUFFER_BASE       DP_DAF_CTRL_base(3)
#define WMA_BUFFER_DSP_READ   DP_DAF_CTRL_base(3)  /* Indicate the next word DSP will read      */
#define WMA_BUFFER_MCU_WRITE  DP_DAF_CTRL_base(4)  /* Indicate the next word MCU will write     */
#define WMA_NUM_CHANNELS      DP_DAF_CTRL_base(5)
#define WMA_SAMPLING_RATE     DP_DAF_CTRL_base(6)
#define WMA_VERSION_NUMBER    DP_DAF_CTRL_base(7)
#define WMA_BYTES_PER_SECONDS DPRAM_base(0x038)
#define WMA_PACKET_LENGTH     DPRAM_base(0x039)
#define WMA_ENCODE_OPT        DPRAM_base(0x03A)
#define WMA_CNTROL_WORD       DPRAM_base(0x2AB)
#define WMA_DSP_DGAIN         DP_DigiGain_Setting
#define WMA_Soft_Reset	      DPRAM_base(0x003B)
#define WMA_TOTAL_FRAME       DPRAM_base(0x003C)
#endif  // IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION

/* -------------------------------------------------------------------------- */
/* Voice Recognition                                                          */
/* -------------------------------------------------------------------------- */
#if defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
#define DP_VR_STATUS          DP_SP_VR_CTRL_base(1)
#define DP_VR_RUNHPF          DP_SP_VR_CTRL_base(2)
#define DP_VR_VEC_COUNT       DP_SP_VR_CTRL_base(3)
#define DP_VR_FRAME_ENERGY    DP_SP_VR_CTRL_base(4)
#define DP_VR_CTRL            DP_SP_VR_CTRL_base(0)
#else
#define DP_VR_STATUS          DPRAM_base(0x275)
#define DP_VR_RUNHPF          DPRAM_base(0x036)
#define DP_VR_VEC_COUNT       DPRAM_base(0x037)
#define DP_VR_FRAME_ENERGY    DPRAM_base(0x038)
#define DP_VR_CTRL            DPRAM_base(0x05F)
#endif

/* -------------------------------------------------------------------------- */
/* A/V Sync Control                                                           */
/* -------------------------------------------------------------------------- */
#define A2V_INT_ENABLE        DP_AV_SYNC_CTRL_base(0)     /* State change controller                   */

#if defined(MT6229) || defined(MT6230)
#define A2V_INT_CNT           DP_AV_SYNC_CTRL_base(0x3B)
#else
#define A2V_INT_CNT           DP_AV_SYNC_CTRL_base(1)     /* Audio interrupt count                     */
#endif

#define A2V_INT_STAMP         DP_AV_SYNC_CTRL_base(2)     /* Time for DSP to trigger MCU for display   */
#define A2V_AUDIO_FRAME_COUNT DP_AV_SYNC_CTRL_base(3)     /* Audio frame count                         */
#define A2V_VIDEO_FRAME_COUNT DP_AV_SYNC_CTRL_base(4)     /* Video frame count                         */

/* -------------------------------------------------------------------------- */
/* EC / AEC / EES Control Registers                                           */
/* -------------------------------------------------------------------------- */
#if defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
#define DP_EC_SUPP            DP_SP_AEC_CTRL_base(0)
#define DP_ES_Time_Const      DP_SP_AEC_CTRL_base(7)
#define DP_ES_Vol_Const       DP_SP_AEC_CTRL_base(8)
#define DP_EES_FE_ATTEN       DP_SP_AEC_CTRL_base(11)
#define DP_EES_DT_ATTEN       DP_SP_AEC_CTRL_base(12)
#define DP_AEC_NP_ON          DP_SP_AEC_CTRL_base(9)
#define DP_AEC_CTRL           DP_SP_AEC_CTRL_base(1)
#define DP_AEC2_CTRL          DP_SP_AEC_CTRL_base(2)
#define DP_EES_CTRL           DP_SP_AEC_CTRL_base(2)
#define DP_EAEC_CTRL          DP_SP_AEC_CTRL_base(3)
#define DP_AEC_8K_CTRL        DP_SP_AEC_CTRL_base(4)
#define DP_AEC_DLBUF_ADDR     DP_SP_AEC_CTRL_base(5)
#define DP_AEC_DLBUF_LEN      DP_SP_AEC_CTRL_base(6)
#define DP_UL_NR_CTRL         DPRAM2_base(0x1CB) 
#define DP_DL_NR_CTRL         DPRAM2_base(0x1D6)
#define DP_SPE_DL_DLL_ENTRY   DPRAM2_base(0x11E) 
#else
#define DP_EC_SUPP            DPRAM_base(0x09B)     /* turn on echo suppression               */
#define DP_ES_Time_Const      DPRAM_base(0x09C)     /*                                        */
#define DP_ES_Vol_Const       DPRAM_base(0x09D)     /*                                        */
#define DP_EES_FE_ATTEN       DPRAM_base(0x09C)
#define DP_EES_DT_ATTEN       DPRAM_base(0x09D)
#define DP_AEC_NP_ON          DPRAM_base(0x09E)
#define DP_AEC_8K_CTRL        DPRAM_base(0x276)
#define DP_AEC_DLBUF_ADDR     DPRAM_base(0x277)
#define DP_AEC_DLBUF_LEN      DPRAM_base(0x278)

#if defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D)
#define DP_AEC_CTRL           DPRAM_base(0x282)
#define DP_AEC2_CTRL          DPRAM_base(0x283)
#define DP_EES_CTRL           DPRAM_base(0x283)
#define DP_UL_NR_CTRL         DPRAM_base(0x28A) 
#define DP_DL_NR_CTRL         DPRAM_base(0x28B) 
#else
#define DP_AEC_CTRL           DPRAM_base(0x268)
#define DP_AEC2_CTRL          DPRAM_base(0x269)
#define DP_EES_CTRL           DPRAM_base(0x269)
#define DP_UL_NR_CTRL         DPRAM_base(0x2D7) 
#define DP_DL_NR_CTRL         DPRAM_base(0x2D8) 
#endif  // MT6226/26M/27

#define DP_SPE_DL_DLL_ENTRY   DPRAM_base(0x25D) 

#endif  // defined(MT6229) || defined(MT6230)

/* -------------------------------------------------------------------------- */
/* Audio Equalizer Control Field                                              */
/* -------------------------------------------------------------------------- */
#if defined(MT6217) || defined(MT6219)
#define DP_AEQ_CTRL           DPRAM_base(0x48)
#elif defined(MT6226) || defined(MT6226M) || defined(MT6227) || defined(MT6226D) || defined(MT6227D)
#define DP_AEQ_CTRL           DPRAM_base(0x4A)
#endif

/* -------------------------------------------------------------------------- */
/* Audio Flexible Control Field                                               */
/* -------------------------------------------------------------------------- */
#if defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
#define DP_AUDIO_FLEXI_CTRL         DPRAM2_base(0x1CF)
#elif defined(MT6228) || defined(MT6225)
#define DP_AUDIO_FLEXI_CTRL         DPRAM_base(0x02AB)
#elif defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D)
#define DP_AUDIO_FLEXI_CTRL         DPRAM_base(0x029A)
#endif

/* -------------------------------------------------------------------------- */
/* Audio Post-Processing Control Field                                           */
/* -------------------------------------------------------------------------- */
#define APM_SUPPORT  ( defined(MT6225) || defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238) )

#if defined(MT6223) || defined(MT6223P)
#define DP2_AUDIO_PP_CTRL           DPRAM2_base(0x022C)
#elif defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
#define DP2_AUDIO_PP_CTRL           DPRAM2_base(0x022C)
#define AUDIO_PP_3D_Table_Address   DPRAM2_base(0x022D)
#define AUDIO_PP_TS_SPEED           DPRAM2_base(0x022E)
#else
#define DP2_AUDIO_PP_CTRL           DPRAM_base(0x048)
#define AUDIO_PP_3D_Table_Address   DPRAM_base(0x049)
#define AUDIO_PP_TS_SPEED           DPRAM_base(0x04A)
#endif

#if defined(MT6225)
#define PCMRUT_BUF_ADDR       DPRAM_base(0x02D9)
#define PCMRUT_BUF_LENGTH     DPRAM_base(0x02DA)
#elif defined(MT6228)
#define PCMRUT_BUF_ADDR       DPRAM_base(0x02C5)
#define PCMRUT_BUF_LENGTH     DPRAM_base(0x02C6)
#elif defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
#define PCMRUT_BUF_ADDR       DPRAM2_base(0x023A)
#define PCMRUT_BUF_LENGTH     DPRAM2_base(0x023B)
#elif defined(MT6223) || defined(MT6223P)
#define PCMRUT_BUF_ADDR       DPRAM2_base(0x022D)
#define PCMRUT_BUF_LENGTH     DPRAM2_base(0x022E)
#endif

/* -------------------------------------------------------------------------- */
/* Enhanced Audio Control Field                                               */
/* -------------------------------------------------------------------------- */
#if defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
#define DP_SBSD_CTRL          DP_SP_AUDIO_CTRL_base(0)
#define E_CTRL_HRFR           DP_SP_AUDIO_CTRL_base(3)
#define E_CTRL_AMREFR         DP_SP_AUDIO_CTRL_base(4)
#define E_CTRL_HO             DP_SP_AUDIO_CTRL_base(5)
#define DP_DEBUG_ASSERT_CTRL (DPRAM2_base(0x27c))
#else
#define DP_SBSD_CTRL          DPRAM_base(0x00B)
#define E_CTRL_HRFR           DPRAM_base(0x272)
#define E_CTRL_AMREFR         DPRAM_base(0x273)
#define E_CTRL_HO             DPRAM_base(0x274)
#endif

/* ------------------------------------------------------------------------------------------------------------------- */
#if defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
#define DP_TCH_UL_PTR         DP_SP_8kPCM_CTRL_base(7)
#define DP_TCH_UL_LEN         DP_SP_8kPCM_CTRL_base(8)
#define DP_TCH_UL_BUF_ADDR0   DP_SP_8kPCM_CTRL_base(9)
#define DP_TCH_UL_BUF_LEN     DP_SP_8kPCM_CTRL_base(10)
#define DP_TCH_DL_PTR         DP_SP_8kPCM_CTRL_base(11)
#define DP_TCH_DL_LEN         DP_SP_8kPCM_CTRL_base(12)
#define DP_TCH_DL_BUF_ADDR0   DP_SP_8kPCM_CTRL_base(13)
#define DP_TCH_DL_BUF_LEN     DP_SP_8kPCM_CTRL_base(14)
#define DP_TCH_PCM_REC_ENA    DP_SP_8kPCM_CTRL_base(5)

#elif  defined(MT6225) || defined(MT6228)

#define DP_TCH_UL_PTR         DPRAM_base(0x2A3)
#define DP_TCH_UL_LEN         DPRAM_base(0x2A4)
#define DP_TCH_UL_BUF_ADDR0   DPRAM_base(0x2A5)
#define DP_TCH_UL_BUF_LEN     DPRAM_base(0x2A6)
#define DP_TCH_DL_PTR         DPRAM_base(0x2A7)
#define DP_TCH_DL_LEN         DPRAM_base(0x2A8)
#define DP_TCH_DL_BUF_ADDR0   DPRAM_base(0x2A9)
#define DP_TCH_DL_BUF_LEN     DPRAM_base(0x2AA)
#define DP_TCH_PCM_REC_ENA    DPRAM_base(0x267)

#else
#define DP_TCH_UL_PTR         DPRAM_base(0x014)
#define DP_TCH_UL_LEN         DPRAM_base(0x015)
#define DP_TCH_UL_BUF_ADDR0   DPRAM_base(0x016)
#define DP_TCH_UL_BUF_LEN     DPRAM_base(0x017)
#define DP_TCH_DL_PTR         DPRAM_base(0x018)
#define DP_TCH_DL_LEN         DPRAM_base(0x019)
#define DP_TCH_DL_BUF_ADDR0   DPRAM_base(0x01A)
#define DP_TCH_DL_BUF_LEN     DPRAM_base(0x01B)
#if defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D)
#define DP_TCH_PCM_REC_ENA    DPRAM_base(0x281)
#else
#define DP_TCH_PCM_REC_ENA    DPRAM_base(0x267)
#endif
#endif

/*----------------------------*\
|* Uplink WB AMR in TCH buffer*|
\* ------------------------------------------------------------------------------------------------------------------- */
#if defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
#define DP_AWB_TX_TCH_S0(n)   DP_SP_VM_CTRL_base(0x35+(n))
#define DP_AWB_TX_TCH_S17(n)  DP_SP_VM_CTRL_base(0x46+(n))
#define DP_AWB_SC_TCH_MODE    DP_SP_VM_CTRL_base(0x54)
#elif defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6225)
#define DP_AWB_TX_TCH_S0(n)   DPRAM_base((0x31)+(n))
#define DP_AWB_TX_TCH_S17(n)  DPRAM_base((0x11E)+(n))
#define DP_AWB_SC_TCH_MODE    DPRAM_base(0x12C)
#else //MT6219, should not release through
#define DP_AWB_TX_TCH_S0(n)   DPRAM_base(0x1B7+(n))
#define DP_AWB_TX_TCH_S17(n)  DPRAM_base(0x1C8+(n))
#define DP_AWB_SC_TCH_MODE    DPRAM_base(0x1D6)
#endif

/*-----------------------*\
|* Audio Control Field 2 *|
\* ------------------------------------------------------------------------------------------------------------------- */
#if defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
#define DP_AUDIO_CTRL2        DP_SP_AUDIO_CTRL_base(0x2)
#else
#define DP_AUDIO_CTRL2        DPRAM_base(0x266)
#endif
/* ------------------------------------------------------------------------------------------------------------------- */
#define DP_AAC_CTRL_ASP       0x0001
#define DP_PCM_R_DIS          0x0002
/* ------------------------------------------------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/* Sound Effect                                                               */
/* -------------------------------------------------------------------------- */
#if defined(MT6229_S00) || defined(MT6230_S00)
#define DSP_SOUND_EFFECT_ADDR    DP_SP_8kPCM_CTRL_base(17)
#define DSP_SOUND_EFFECT_LEN     DP_SP_8kPCM_CTRL_base(18)
#define DSP_SOUND_EFFECT_CTRL    DP_SP_8kPCM_CTRL_base(19)
#define DSP_SOUND_EFFECT_SPH_STATE     DP_SP_8kPCM_CTRL_base(20)
#define DSP_SOUND_EFFECT_UL_GAIN     DP_SP_AUDIO_ENHANCE_base(11)
#define DSP_SOUND_EFFECT_DL_GAIN     DP_SP_AUDIO_ENHANCE_base(12)

#define DSP_PCM_REC_INT          DP_SP_8kPCM_CTRL_base(15)
#define DSP_SOUND_EFFECT_INT     DP_SP_8kPCM_CTRL_base(16)
#define DSP_DEAD_INT             DP_SP_AUDIO_ENHANCE_base(0)
#define DSP_UP_DOWN_SAMP_CTRL	 DP_SP_AUDIO_ENHANCE_base(9)

#elif defined(MT6229_S01) || defined(MT6230_S01) || defined(MT6229_S02) || defined(MT6230_S02) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
#define DSP_SOUND_EFFECT_ADDR    DP_SP_8kPCM_CTRL_base(17)
#define DSP_SOUND_EFFECT_LEN     DP_SP_8kPCM_CTRL_base(18)
#define DSP_SOUND_EFFECT_CTRL    DP_SP_8kPCM_CTRL_base(19)
#define DSP_SOUND_EFFECT_SPH_STATE     DP_SP_8kPCM_CTRL_base(20)
#define DSP_SOUND_EFFECT_UL_GAIN     DP_SP_AUDIO_CTRL_base(6)
#define DSP_SOUND_EFFECT_DL_GAIN     DP_SP_AUDIO_CTRL_base(7)

#define DSP_PCM_REC_INT          DP_SP_8kPCM_CTRL_base(15)
#define DSP_SOUND_EFFECT_INT     DP_SP_8kPCM_CTRL_base(16)
#define DSP_DEAD_INT             DP_SP_AUDIO_ENHANCE_base(0)
#define DSP_UP_DOWN_SAMP_CTRL	 DP_SP_AUDIO_ENHANCE_base(9)

#elif defined(MT6228) || defined(MT6225)
#define DSP_SOUND_EFFECT_ADDR    DPRAM_base(0x259)       /* Sound Effect DSP buffer write address     */
#define DSP_SOUND_EFFECT_LEN     DPRAM_base(0x25A)       /* Sound Effect DSP buffer write length      */
#define DSP_SOUND_EFFECT_CTRL    DPRAM_base(0x25B)       /* Sound Effect Contrl                       */
#define DSP_SOUND_EFFECT_SPH_STATE     DPRAM_base(0x25C)       /* Sound Effect DSP mix flg                  */
#define DSP_SOUND_EFFECT_UL_GAIN     DPRAM_base(0x2B8)
#define DSP_SOUND_EFFECT_DL_GAIN     DPRAM_base(0x2B9)

#define DSP_PCM_REC_INT          DPRAM_base(0x27C)
#define DSP_SOUND_EFFECT_INT     DPRAM_base(0x27D)
#define DSP_DEAD_INT             DPRAM_base(0x27E)

#else
#define DSP_SOUND_EFFECT_ADDR    DPRAM_base(0x259)       /* Sound Effect DSP buffer write address     */
#define DSP_SOUND_EFFECT_LEN     DPRAM_base(0x25A)       /* Sound Effect DSP buffer write length      */
#define DSP_SOUND_EFFECT_CTRL    DPRAM_base(0x25B)       /* Sound Effect Contrl                       */
#define DSP_SOUND_EFFECT_SPH_STATE     DPRAM_base(0x25C)       /* Sound Effect DSP mix flg                  */
#define DSP_SOUND_EFFECT_UL_GAIN     DPRAM_base(0x2B2)
#define DSP_SOUND_EFFECT_DL_GAIN     DPRAM_base(0x2B3)

#define DSP_PCM_REC_INT          DPRAM_base(0x27C)
#define DSP_SOUND_EFFECT_INT     DPRAM_base(0x27D)
#define DSP_DEAD_INT             DPRAM_base(0x27E)
#endif

/* -------------------------------------------------------------------------- */
/* DSP Wavetable Music Synthesis                                              */
/* -------------------------------------------------------------------------- */
#if defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
#define DP_WT_CTRL               (*DP_WT_CTRL_base(0))
#define DP_WT_EVT_COUNT          (*DP_WT_CTRL_base(23))
#define DP_WT_EFFECT             (*DP_WT_CTRL_base(3))
#define DP_WT_VOLUME             (*DP_WT_CTRL_base(18))
#define DP_WT_VOLUME2            (*DP_WT_CTRL_base(19))
#define DP_WT_ADDR_LO            (*DP_WT_CTRL_base(12))
#define DP_WT_ADDR_HI            (*DP_WT_CTRL_base(13))
#define DP_WT_INST_VOL_LO        (*DP_WT_CTRL_base(14))
#define DP_WT_INST_VOL_HI        (*DP_WT_CTRL_base(15))
#define DP_WT_EQPARA_LO          (*DP_WT_CTRL_base(16))
#define DP_WT_EQPARA_HI          (*DP_WT_CTRL_base(17))
#define DP_WT_RTMIDI_ADDR_LO     (*DP_WT_CTRL_base(20))
#define DP_WT_RTMIDI_ADDR_HI     (*DP_WT_CTRL_base(21))
#define DP_WT_RESET_CTRLR        (*DP_WT_CTRL_base(22))
#define DSP_WAV_PLAYEDINDEX(n)   (*DP_WT_CTRL_base(4+2*(n)))
#else
#define DP_WT_CTRL               (*DPRAM_base(0x57))
#define DP_WT_EVT_COUNT          (*DPRAM_base(0x11))
#define DP_WT_EFFECT             (*DPRAM_base(0x262))
#define DP_WT_VOLUME             (*DPRAM_base(0x263))
#define DP_WT_VOLUME2            (*DPRAM_base(0x264))
#define DP_WT_ADDR_LO            (*DPRAM_base(0x12))
#define DP_WT_ADDR_HI            (*DPRAM_base(0x13))
#define DP_WT_INST_VOL_LO        (*DPRAM_base(0x14))
#define DP_WT_INST_VOL_HI        (*DPRAM_base(0x15))
#define DP_WT_EQPARA_LO          (*DPRAM_base(0x16))
#define DP_WT_EQPARA_HI          (*DPRAM_base(0x17))
#define DP_WT_RTMIDI_ADDR_LO     (*DPRAM_base(0x1A))
#define DP_WT_RTMIDI_ADDR_HI     (*DPRAM_base(0x1B))
#define DP_WT_RESET_CTRLR        (*DPRAM_base(0x1C))
#define DSP_WAV_PLAYEDINDEX(n)   (*DPRAM_base(0x11E + 2*(n)))

#endif

/* -------------------------------------------------------------------------- */
/* VoRTP Support Definition                                                   */
/* -------------------------------------------------------------------------- */
#define VORTP_SUPPORT (defined(__VOIP__) && (defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238)))

/* -------------------------------------------------------------------------- */
/* SBC Support Definition                                                   */
/* -------------------------------------------------------------------------- */
#define D2C_MAGIC_NO_SBC 0xA4BC
#if defined(__BT_A2DP_PROFILE__) || defined(SBC_UNIT_TEST)
#define BT_A2DP_SBC_SUPPORT (defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || \
                       defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238) || defined(MT6223) || defined(MT6223P))

#if !BT_A2DP_SBC_SUPPORT && defined(__MTK_TARGET__)
#error Bluetooth A2DP is only supported on MT6225, MT6226, MT6227, MT6228, MT6229, MT6230, MT6268T, MT6223, MT6223P, MT6235, and MT6238.
#endif
/* DSP SHERIFs about Subband Analysis, these shall be defined in l1audio_def.h */

#if defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
#define DP_SB_CTRL  (*DPRAM2_base(0x231))
#define DP_SB_WRITE (*DPRAM2_base(0x232))
#define DP_SB_READ  (*DPRAM2_base(0x233))
#define DP_SB_PARAM (*DPRAM2_base(0x234))
#define DP_SB_BASE (*DPRAM2_base(0x235))
#define DP_SB_LENGTH (*DPRAM2_base(0x236))
#elif defined(MT6228) || defined(MT6225)
#define DP_SB_CTRL   (*DPRAM_base(0x2BB))
#define DP_SB_WRITE  (*DPRAM_base(0x2BC))
#define DP_SB_READ   (*DPRAM_base(0x2BD))
#define DP_SB_PARAM  (*DPRAM_base(0x2BE))
#define DP_SB_BASE 	(*DPRAM_base(0x2BF))
#define DP_SB_LENGTH (*DPRAM_base(0x2C0))
#elif defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) 
#define DP_SB_CTRL  (*DPRAM_base(0x284))
#define DP_SB_WRITE (*DPRAM_base(0x285))
#define DP_SB_READ  (*DPRAM_base(0x286))
#define DP_SB_PARAM (*DPRAM_base(0x287))
#elif  defined(MT6223) || defined(MT6223P)
#define DP_SB_CTRL  (*DPRAM2_base(0x233))
#define DP_SB_WRITE (*DPRAM2_base(0x234))
#define DP_SB_READ  (*DPRAM2_base(0x235))
#define DP_SB_PARAM (*DPRAM2_base(0x236))
#define DP_SB_BASE  (*DPRAM2_base(0x237))   // Fixed value
#define DP_SB_LENGTH (*DPRAM2_base(0x238))  // Fixed value
#else
#error Not defined !
#endif // ... defined(MT6229)

#endif
/* -------------------------------------------------------------------------- */
/* DSP Slow Idle Control                                                      */
/* -------------------------------------------------------------------------- */
#if defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
#define DP_SLOW_IDLE_CTRL  (*DPRAM2_base(0x10))
#else
#define DP_SLOW_IDLE_CTRL  (*DPRAM_base(0x4F))
#endif


/* -------------------------------------------------------------------------- */
/* AudioPlayback Via BT SCO link address and control                          */
/* -------------------------------------------------------------------------- */
#if defined(MT6228)//ECO
#define BT_AUDIO_PLAYBACK_SD_PTR_ADDR    0x322D
#define BT_AUDIO_PLAYBACK_SD_ADDR        0x3C00
#define BT_AUDIO_PLAYBACK_SD_BUF_LEN     320
#define BT_AUDIO_PLAYBACK_SD_PAGE_NUM    0
#define DP_AUDIO_VIA_8KBT_CTRL           DPRAM_base(0x02DC)
#define DP_AUDIO_VIA_8KBT_INT            DPRAM_base(0x02DD)
#define D2C_AUDIO_VIA_8KBT_ID            0xCC66
#define DP_VSBT_CTRL                     DPRAM_base(0x02DE) // 1: enable VBI and BT output simutaneous
                                                            // 0: BT output only
#elif defined(MT6225)
#define BT_AUDIO_PLAYBACK_SD_PTR_ADDR    0x2E30
#define BT_AUDIO_PLAYBACK_SD_ADDR        0x3C00
#define BT_AUDIO_PLAYBACK_SD_BUF_LEN     320
#define BT_AUDIO_PLAYBACK_SD_PAGE_NUM    0
#define DP_AUDIO_VIA_8KBT_CTRL           DPRAM_base(0x02DC)
#define DP_AUDIO_VIA_8KBT_INT            DPRAM_base(0x02DD)
#define D2C_AUDIO_VIA_8KBT_ID            0xCC66
#define DP_VSBT_CTRL                     DPRAM_base(0x02DE)

#elif defined(MT6227) || defined(MT6227D) || defined(MT6226) || defined(MT6226D) || defined(MT6226M)
#define BT_AUDIO_PLAYBACK_SD_PTR_ADDR    0x302E
#define BT_AUDIO_PLAYBACK_SD_ADDR        0x3C00
#define BT_AUDIO_PLAYBACK_SD_BUF_LEN     320
#define BT_AUDIO_PLAYBACK_SD_PAGE_NUM    0
#define DP_AUDIO_VIA_8KBT_CTRL           DPRAM_base(0x02BD)
#define DP_AUDIO_VIA_8KBT_INT            DPRAM_base(0x02BE)
#define D2C_AUDIO_VIA_8KBT_ID            0xCC66
#define DP_VSBT_CTRL                     DPRAM_base(0x02DE)//Need update

#elif defined(MT6229) || defined(MT6230) || defined(MT6268T)
#define BT_AUDIO_PLAYBACK_SD_PTR_ADDR    0x3926
#define BT_AUDIO_PLAYBACK_SD_ADDR        0x3600
#define BT_AUDIO_PLAYBACK_SD_BUF_LEN     320
#define BT_AUDIO_PLAYBACK_SD_PAGE_NUM    2
#define DP_AUDIO_VIA_8KBT_CTRL           DPRAM2_base(0x01DC)
#define DP_AUDIO_VIA_8KBT_INT            DPRAM2_base(0x01DD)
#define D2C_AUDIO_VIA_8KBT_ID            0xCC66
#define DP_VSBT_CTRL                     DPRAM2_base(0x01D8)

#elif defined(MT6235) || defined(MT6238)
#define BT_AUDIO_PLAYBACK_SD_PTR_ADDR    0x3928
#define BT_AUDIO_PLAYBACK_SD_ADDR        0x3600
#define BT_AUDIO_PLAYBACK_SD_BUF_LEN     320
#define BT_AUDIO_PLAYBACK_SD_PAGE_NUM    2
#define DP_AUDIO_VIA_8KBT_CTRL           DPRAM2_base(0x01DC)
#define DP_AUDIO_VIA_8KBT_INT            DPRAM2_base(0x01DD)
#define D2C_AUDIO_VIA_8KBT_ID            0xCC66
#define DP_VSBT_CTRL                     DPRAM2_base(0x01D8)
#endif

/* -------------------------------------------------------------------------- */
/*   8K limiter control                                                       */
/* -------------------------------------------------------------------------- */

#if defined(MT6227) || defined(MT6227D) || defined(MT6226M) || defined(MT6226) || defined(MT6226D)
#define DP_8K_LIMITER_CTRL       DPRAM_base(0x028C)                
#elif defined(MT6228) || defined(MT6225)
#define DP_8K_LIMITER_CTRL       DPRAM_base(0x02DB) 
#elif defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
#define DP_8K_LIMITER_CTRL       DPRAM2_base(0x01DB)
#endif


/* -------------------------------------------------------------------------- */
/* BlueTooth Mode Control Field (Sign-extension / linear / gain mode)         */
/* -------------------------------------------------------------------------- */
#if defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
#define DP_BT_PATCH_CTRL               DP_SP_AUDIO_ENHANCE_base(6)
#define DP_BT_MODE_CTRL                DP_SP_AUDIO_INTERFACE_CTRL_base(15)
#else
#define DP_BT_PATCH_CTRL               DPRAM_base(0x027A)
#define DP_BT_MODE_CTRL                DPRAM_base(0x027F)
#endif
/* -------------------------------------------------------------------------- */
/* 3G Speech Sherif Address                                                   */
/* -------------------------------------------------------------------------- */
#define DP_3G_STATE        (DPRAM2_base(0x1FA)) 
#define DP_3G_UL_SC_MODE   (DPRAM2_base(0x1C5))
#define DP_3G_UL_TX_TYPE   (DPRAM2_base(0x183)) 
#define DP_3G_UL_TX_ADDR   (DPRAM2_base(0x184)) 
#define DP_3G_DL_SD_MODE   (DPRAM2_base(0x1C6)) 
#define DP_3G_DL_RX_TYPE   (DPRAM2_base(0x171))
#define DP_3G_DL_RX_ADDR   (DPRAM2_base(0x172)) 
#define DP_3G_UL_TX_MODE_REPORT (*DPRAM2_base(0x194)) 
#define DP_3G_DL_RX_MODE_REPORT (*DPRAM2_base(0x182))

#if defined(MT6229) || defined(MT6230) || defined(MT6268T)
#define DP2_3G_debug_info0 (*(DPRAM2_base(0x164)))
#define DP2_3G_debug_info1 (*(DPRAM2_base(0x165)))
#define DP2_3G_debug_info7 (*(DPRAM2_base(0x16B)))
#else
#define DP2_3G_debug_info0	(*DPRAM_base(0x1B7))
#define DP2_3G_debug_info1	(*DPRAM_base(0x1B8))
#define DP2_3G_debug_info7	(*DPRAM_base(0x1BE))
#endif

/*    DSP AGC control    */
#if defined(MT6235) || defined(MT6238)
#define DP2_AGC_CTRL             DPRAM2_base(0x01DE)
#define DM_AGC_PARAMETER_PAGE    0x2
#define DM_AGC_PARAMETER_ADDR    0x321D
#endif

#define DP_SPE_debug1	(*DPRAM_base(0x2D4))
#define DP_SPE_debug2	(*DPRAM_base(0x2D5))

#endif /* __L1AUDIO_DEF_H */
