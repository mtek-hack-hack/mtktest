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
 *	l1d_reg.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   Definition of H/W register address used in L1D
 *
 * Author:
 * -------
 * -------
 *
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *******************************************************************************/

#ifndef _L1D_REG_H_
#define _L1D_REG_H_

/*=======================================================================================================================*/
/* used for Simulation                                                                                                   */
/*-----------------------------------------------------------------------------------------------------------------------*/

typedef unsigned short  DPRAM_T;                                        /* Dual Port Ram is 16bit access (Thumb)         */
typedef unsigned long   REG_T;                                          /* Registers are 32bit access (SRM APB bus)      */

#define DIS_ALL_IRQ     0x0000                                          /* -----------------> flags in EVENT_ENABLE0     */
#define EN_DTIRQ        0x0001                                          /*                                               */
#define EN_CTIRQ1       0x0002                                          /*                                               */
#define EN_CTIRQ2       0x0004                                          /*                                               */
#define EN_BDL(n)       (1<<(6+(n)))                                    /* 0 <= n <=  5                                  */
#define EN_APC(n)       (1<<(n))                                        /* 0 <= n <=  4 ----> flags in EVENT_ENABLE1     */
#define EN_GSM          0x0000                                          /*                                               */
#define EN_BSI(n)       (1<<(n))                                        /* 0 <= n <= 15 ----> flags in EVENT_ENABLE2     */
#define EN_BPI(n)       (1<<(n))                                        /* 0 <= n <= 15 ----> flags in EVENT_ENABLE3     */

#if  (IS_FPGA_TARGET)||(IS_CHIP_MT6208)
/*FPGA,MT6208*/ #define EN_AFC3         0x8000                          /*                                               */
/*FPGA,MT6208*/ #define EN_AFC(n)       (1<<(3+(n)))                    /* 0 <= n <=  2                                  */
#endif

#if  IS_CHIP_MT6205_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6205~*/ #define EN_AFC3         0x8000                              /*                                               */
/*MT6205~*/ #define EN_AFC(n)       (1<<(12+(n)))                       /* 0 <= n <=  2                                  */
#endif

#if  (IS_FPGA_TARGET)||(IS_CHIP_MT6208)||(IS_CHIP_MT6205)
/*FPGA,MT6208,MT6205*/ #define EN_BUL(n)       (1<<(6+(n)))             /* 0 <= n <=  3                                  */
/*FPGA,MT6208,MT6205*/ #define EN_GPRS         0x0400                   /*                                               */
#endif

#if  IS_CHIP_MT6218_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6218~*/ #define EN_BUL(n)       (1<<(8+(n)))                        /* 0 <= n <=  3                                  */
/*MT6218~*/ #define EN_GPRS         0x8000                              /*                                               */
#endif


/*--------------------------------------------*/
/* define enable bit mask                     */
/*--------------------------------------------*/

#define DPRAM(offset)   ((DPRAMADDR)(DPRAM_CPU_base+(offset)*2))
#define DPRAM2(offset)  ((DPRAMADDR)(DPRAM2_CPU_base+(offset)*2))

/*=======================================================================================================================*/

#ifndef  L1D_SIM
   typedef volatile unsigned short* SRAMADDR;                           /* SRAM addr is 16 bits                          */
   typedef volatile unsigned short  SRAMDATA;                           /* SRAM data is 16 bits                          */
   typedef volatile unsigned short* APBADDR;                            /* APB addr is 32 bits                           */
   typedef volatile unsigned short  APBDATA;                            /* APB data is 16 bits                           */
   typedef volatile unsigned long*  APBADDR32;                          /* APB addr is 32 bits                           */
   typedef volatile unsigned long   APBDATA32;                          /* APB data is 16 bits                           */
   typedef volatile unsigned short* DPRAMADDR;                          /* DPRAM addr is 16 bits                         */
   typedef volatile signed   short* DPRAMADDR_S;                        /* DPRAM addr is 16 bits                         */
   typedef volatile unsigned short  DPRAMDATA;                          /* DPRAM data is 16 bits                         */
#else
   typedef unsigned short* SRAMADDR;                                    /* SRAM addr is 16 bits                          */
   typedef unsigned short  SRAMDATA;                                    /* SRAM data is 16 bits                          */
   typedef unsigned short* APBADDR;                                     /* APB addr is 32 bits                           */
   typedef unsigned short  APBDATA;                                     /* APB data is 16 bits                           */
   typedef unsigned long*  APBADDR32;                                   /* APB addr is 32 bits                           */
   typedef unsigned long   APBDATA32;                                   /* APB data is 16 bits                           */
   typedef unsigned short* DPRAMADDR;                                   /* DPRAM addr is 16 bits                         */
   typedef   signed short* DPRAMADDR_S;                                 /* DPRAM addr is 16 bits                         */
   typedef unsigned short  DPRAMDATA;                                   /* DPRAM data is 16 bits                         */
#endif

/*-----------------------------------------------------------------------------------------------------------------------*/

/*---------------------------------*/
/* Base address of MCU Peripherals */
/*---------------------------------*/
#if IS_EDGE_SAIC_CHIP_MT6238_AND_LATTER_VERSION
#define DPRAM_CPU_base          0xA0000000L                             /* Host DSP Sherif Registers                     */
#define DPRAM_CPU_end           0xA00007FEL
#define DPRAM2_CPU_base         0xA1000000L                             /* Slave DSP Sherif Registers                    */
#define DPRAM2_CPU_end          0xA10007FEL
#define CONFIG_base             0x80010000L                             /* Config registers  (Clk, Power Down, Ver)      */
#define CONFIG_end              0x8001FFFFL
#define GPIO_base               0x80020000L                             /* General Purpose Inputs/Outputs                */
#define GPIO_end                0x800201FFL
#define RGU_base                0x80030000L                             /* Reset Generation Unit                         */
#define RGU_end                 0x800300FFL
#define EMI_base                0x81000000L                             /* External Memory Interface                     */
#define EMI_end                 0x8100FFFFL
#define CIRQ_base               0x81010000L                             /* Interrupt Controller                          */
#define CIRQ_end                0x8101FFFFL
#define DMA_base                0x81020000L                             /* DMA Controller                                */
#define DMA_end                 0x8102FFFFL
#define RTC_base                0x810C0000L                             /* Real Time Clock                               */
#define RTC_end                 0x810C00FFL
#define TDMA_base               0x82000000L                             /* TDMA Timer                                    */
#define TDMA_end                0x820001FFL
#define SM_base                 0x82000200L                             /* Sleep Mode                                    */
#define SM_end                  0x820002FFL
#define BSI_base                0x82010000L                             /* Base-band Serial Interface                    */
#define BSI_end                 0x820101FFL
#define BPI_base                0x82020000L                             /* Base-band Parallel Interface                  */
#define BPI_end                 0x8202006FL
#define AFC_base                0x82030000L                             /* Automatic Frequency Control Unit              */
#define AFC_end                 0x8203001FL
#define APC_base                0x82040000L                             /* Automatic Power Control Unit                  */
#define APC_end                 0x820401CFL
#define AUXADC_base             0x82050000L                             /* Auxiliary ADC Unit                            */
#define AUXADC_end              0x820500FFL
#define DIVIDER_base            0x82060000L                             /* Divider/Modulus Coprocessor                   */
#define DIVIDER_end             0x820600FFL
#define FCS_base                0x82070000L                             /* Frame Check Sequence                          */
#define FCS_end                 0x820700FFL
#define GCU_base                0x82080000L                             /* GPRS Cipher Unit Unit                         */
#define GCU_end                 0x820800FFL
#define CSD_ACC_base            0x82090000L                             /* CSD Format Conversion Coprocessor             */
#define CSD_ACC_end             0x82090FFFL
#define SHARE_base              0x820A0000L                             /* MCU-Host  DSP Shared Register                 */
#define SHARE_end               0x820A00FFL
#define SHARE2_base             0x820C0000L                             /* MCU-Slave DSP Shared Register                 */
#define SHARE2_end              0x820C00FFL
#define PATCH_base              0x820E0000L                             /* DSP Patch Unit                                */
#define PATCH_end               0x820E01FFL
#define AFE_base                0x820F0000L                             /* Audio Front End                               */
#define AFE_end                 0x820E00FFL
#define BFE_base                0x82100000L                             /* Base-band Front End                           */
#define BFE_end                 0x821000FFL
#define PLL_CLKSQ_base          0x83000000L                             /* PLL configuration                             */
#define PLL_CLKSQ_end           0x83000FFFL               
#define MIXED_base              0x83010000L                             /* Analog Chip Interface Controller              */
#define MIXED_end               0x83010FFFL
#else
#define DPRAM_CPU_base          0x50000000L                             /* DSP Sherif Registers                          */
#define DPRAM_CPU_end           0x500007FEL
#define CONFIG_base             0x80000000L                             /* Config registers  (Clk, Power Down, Ver)      */
#define CONFIG_end              0x8000FFFFL
#define EMI_base                0x80010000L                             /* External Memory Interface                     */
#define EMI_end                 0x8001FFFFL
#define CIRQ_base               0x80020000L                             /* Interrupt Controller                          */
#define CIRQ_end                0x8002FFFFL
#define DMA_base                0x80030000L                             /* DMA Controller                                */
#define DMA_end                 0x8003FFFFL
#define RGU_base                0x80040000L                             /* Reset Generation Unit                         */
#define RGU_end                 0x800400FFL
#define GCU_base                0x80060000L                             /* GPRS Cipher Unit Unit                         */
#define GCU_end                 0x800600FFL
#define GPIO_base               0x80120000L                             /* General Purpose Inputs/Outputs                */
#define GPIO_end                0x801201FFL
#define TDMA_base               0x80200000L                             /* TDMA Timer                                    */
#define TDMA_end                0x802001FFL
#define SM_base                 0x80200200L                             /* Sleep Mode                                    */
#define SM_end                  0x802002FFL
#if IS_CHIP_MT6229_FPGA3 || IS_CHIP_MT6229_FPGA2 || IS_CHIP_MT6229_FPGA1
#define BSI_base                0x80210000L                             /* Base-band Serial Interface                    */
#define BSI_end                 0x802101FFL
#define BPI_base                0x80220000L                             /* Base-band Parallel Interface                  */
#define BPI_end                 0x802200B8L
#define AFC_base                0x80230000L                             /* Automatic Frequency Control Unit              */
#define AFC_end                 0x8023001FL
#define APC_base                0x80240000L                             /* Automatic Power Control Unit                  */
#define APC_end                 0x802401CFL
#define FCS_base                0x80250000L                             /* Frame Check Sequence                          */
#define FCS_end                 0x802500FFL
#define DIVIDER_base            0x80260000L                             /* Divider/Modulus Coprocessor                   */
#define DIVIDER_end             0x802600FFL
#define CSD_ACC_base            0x80270000L                             /* CSD Format Conversion Coprocessor             */
#define CSD_ACC_end             0x80270FFFL
#define SHARE_base              0x80300000L                             /* MCU-DSP Shared Register                       */
#define SHARE_end               0x803000FFL
#define PATCH_base              0x80310000L                             /* DSP Patch Unit                                */
#define PATCH_end               0x803101FFL
#define AFE_base                0x80280000L                             /* Audio Front End                               */
#define AFE_end                 0x802800FFL
#define BFE_base                0x80290000L                             /* Base-band Front End                           */
#define BFE_end                 0x802900FFL
#define MIXED_base              0x802A0000L                             /* Analog Chip Interface Controller              */
#define MIXED_end               0x802A0FFFL
#else
#define RTC_base                0x80210000L                             /* Real Time Clock                               */
#define RTC_end                 0x802100FFL
#define BSI_base                0x80220000L                             /* Base-band Serial Interface                    */
#define BSI_end                 0x802201FFL
#define BPI_base                0x80230000L                             /* Base-band Parallel Interface                  */
#define BPI_end                 0x802300C0L
#define AFC_base                0x80240000L                             /* Automatic Frequency Control Unit              */
#define AFC_end                 0x8024001FL
#define APC_base                0x80250000L                             /* Automatic Power Control Unit                  */
#define APC_end                 0x802501CFL
#define FCS_base                0x80260000L                             /* Frame Check Sequence                          */
#define FCS_end                 0x802600FFL
#define AUXADC_base             0x80270000L                             /* Auxiliary ADC Unit                            */
#define AUXADC_end              0x802700FFL
#define DIVIDER_base            0x80280000L                             /* Divider/Modulus Coprocessor                   */
#define DIVIDER_end             0x802800FFL
#define CSD_ACC_base            0x80290000L                             /* CSD Format Conversion Coprocessor             */
#define CSD_ACC_end             0x80290FFFL
#define SHARE_base              0x80300000L                             /* MCU-DSP Shared Register                       */
#define SHARE_end               0x803000FFL
#define PATCH_base              0x80310000L                             /* DSP Patch Unit                                */
#define PATCH_end               0x803101FFL
#define AFE_base                0x80400000L                             /* Audio Front End                               */
#define AFE_end                 0x804000FFL
#define BFE_base                0x80410000L                             /* Base-band Front End                           */
#define BFE_end                 0x804100FFL
#define MIXED_base              0x80500000L                             /* Analog Chip Interface Controller              */
#define MIXED_end               0x80500FFFL
#endif

#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
#define DPRAM2_CPU_base         0x58000000L
#define DPRAM2_CPU_end          0x580007FEL
#define SHARE2_base             0x80320000L                             /* MCU-DSP Shared Register                       */
#define SHARE2_end              0x803200FFL
#define PATCH2_base             0x80330000L                             /* MCU-DSP Shared Register                       */
#define PATCH2_end              0x803301FFL
#endif
#endif

#if IS_CHIP_MT6223 //MT6238 does not support SWDBG
#define SWDBG_base              0x80090000L                           /*Software Debug Controller */
#elif (IS_CHIP_MT6228) || (IS_CHIP_MT6229) || (IS_CHIP_MT6225_AND_LATTER_VERSION) || (IS_CHIP_MT6268T)
#define SWDBG_base              0x80070000L                           /*Software Debug Controller */
#endif

/*=======================================================================================================================*/

#if IS_EDGE_SAIC_CHIP_MT6238_AND_LATTER_VERSION
#define IDMA_LONG               0xA2310000L
#define IDMA_SHORT              0xA2310000L
#define IDMA_CM0                0xA2000000L
#define IDMA_PM0                0xA2100000L
#define IDMA_DM0                0xA2200000L
#else
   #if (IS_CHIP_MT6218B_AND_LATTER_VERSION) || (IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION) 
#define IDMA_LONG               0x60310000L
   #else
#define IDMA_LONG               0x60300000L
   #endif
#define IDMA_SHORT              0x60310000L
#define IDMA_CM0                0x60000000L
#define IDMA_PM0                0x60100000L
#define IDMA_DM0                0x60200000L
#endif

#define IDMA_LONG_ADDR                 ((DPRAMADDR)IDMA_LONG)
#define IDMA_SHORT_ADDR                ((DPRAMADDR)IDMA_SHORT)
#define DSP_CM_ADDR( _page, _addr )    ((DPRAMADDR)(IDMA_CM0+((_page)<<16)+((_addr)<<1)))
#define DSP_PM_ADDR( _page, _addr )    ((DPRAMADDR)(IDMA_PM0+((_page)<<16)+((_addr)<<1)))
#define DSP_DM_ADDR( _page, _addr )    ((DPRAMADDR)(IDMA_DM0+((_page)<<16)+((_addr)<<1)))


#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
//Slave DSP
   #if IS_EDGE_SAIC_CHIP_MT6238_AND_LATTER_VERSION
#define IDMA2_LONG              0xA3310000L
#define IDMA2_SHORT             0xA3310000L
#define IDMA2_CM0               0xA3000000L
#define IDMA2_PM0               0xA3100000L
#define IDMA2_DM0               0xA3200000L
   #else
#define IDMA2_LONG              0x68310000L
#define IDMA2_SHORT             0x68310000L
#define IDMA2_CM0               0x68000000L
#define IDMA2_PM0               0x68100000L
#define IDMA2_DM0               0x68200000L
   #endif

#define IDMA2_LONG_ADDR                 ((DPRAMADDR)IDMA2_LONG)
#define IDMA2_SHORT_ADDR                ((DPRAMADDR)IDMA2_SHORT)
#define DSP2_CM_ADDR( _page, _addr )    ((DPRAMADDR)(IDMA2_CM0+((_page)<<16)+((_addr)<<1)))
#define DSP2_PM_ADDR( _page, _addr )    ((DPRAMADDR)(IDMA2_PM0+((_page)<<16)+((_addr)<<1)))
#define DSP2_DM_ADDR( _page, _addr )    ((DPRAMADDR)(IDMA2_DM0+((_page)<<16)+((_addr)<<1)))

#endif
/*=======================================================================================================================*/

#define  LO_BYTE( data )            ((unsigned char)((data)&0x00FF))
#define  HI_BYTE( data )            ((unsigned char)(((data)>>8)&0x00FF))
#define  LO_WORD( data )            ((unsigned short)((data)&0x0000FFFFL))
#define  HI_WORD( data )            ((unsigned short)(((data)>>16)&0x0000FFFFL))
#define  TO_WORD( data )            ((unsigned short)(data))

/*=======================================================================================================================*/

#if  IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
#define  SCTRL_WORD( dev_sel, bit_count )  ((unsigned short)(((dev_sel)<<15)|((bit_count-1)<<8)))
#define  SCTRL_IMOD( dev_sel, bit_count )  ((unsigned short)(((dev_sel)<<15)|((bit_count-1)<<8)|(0x7F)))
#else
#define  SCTRL_WORD( dev_sel, bit_count )  ((unsigned short)(((dev_sel)<<15)|((bit_count-1)<<8)))
#define  SCTRL_IMOD( dev_sel, bit_count )  ((unsigned short)(((dev_sel)<<15)|((bit_count-1)<<8)|(0x1F)))
#endif


#if  (IS_FPGA_TARGET)||(IS_CHIP_MT6208)
/*FPGA,MT6208*/
/*FPGA,MT6208*/ #define  HW_WRITE_BSI_DATA( addr, data )  \
/*FPGA,MT6208*/ {  HW_WRITE( (APBADDR)((long)(addr)+0), LO_WORD(data) );  \
/*FPGA,MT6208*/    HW_WRITE( (APBADDR)((long)(addr)+4), HI_WORD(data) );  \
/*FPGA,MT6208*/ }
/*FPGA,MT6208*/
/*FPGA,MT6208*/ #define  HW_WRITE_BSI_DATA_1( data_idx, ctrl,data )  \
/*FPGA,MT6208*/ {  long     _d32;                                                 \
/*FPGA,MT6208*/    APBADDR  _reg = BSI_Dn_CON( data_idx );                        \
/*FPGA,MT6208*/    _d32 = ctrl;   HW_WRITE( _reg, TO_WORD(_d32) );  _reg += 2;    \
/*FPGA,MT6208*/    _d32 = data;   HW_WRITE( _reg, LO_WORD(_d32) );  _reg += 2;    \
/*FPGA,MT6208*/                   HW_WRITE( _reg, HI_WORD(_d32) );                \
/*FPGA,MT6208*/ }
/*FPGA,MT6208*/
/*FPGA,MT6208*/ #define  HW_WRITE_BSI_DATA_2( data_idx, ctrl1,data1, ctrl2,data2 )  \
/*FPGA,MT6208*/ {  long     _d32;                                                 \
/*FPGA,MT6208*/    APBADDR  _reg = BSI_Dn_CON( data_idx );                        \
/*FPGA,MT6208*/    _d32 = ctrl1;  HW_WRITE( _reg, TO_WORD(_d32) );  _reg += 2;    \
/*FPGA,MT6208*/    _d32 = data1;  HW_WRITE( _reg, LO_WORD(_d32) );  _reg += 2;    \
/*FPGA,MT6208*/                   HW_WRITE( _reg, HI_WORD(_d32) );  _reg += 2;    \
/*FPGA,MT6208*/    _d32 = ctrl2;  HW_WRITE( _reg, TO_WORD(_d32) );  _reg += 2;    \
/*FPGA,MT6208*/    _d32 = data2;  HW_WRITE( _reg, LO_WORD(_d32) );  _reg += 2;    \
/*FPGA,MT6208*/                   HW_WRITE( _reg, HI_WORD(_d32) );                \
/*FPGA,MT6208*/ }
/*FPGA,MT6208*/
/*FPGA,MT6208*/ #define  HW_WRITE_BSI_DATA_3( data_idx, ctrl1,data1, ctrl2,data2, ctrl3,data3 )  \
/*FPGA,MT6208*/ {  long     _d32;                                               \
/*FPGA,MT6208*/    APBADDR  _reg = BSI_Dn_CON( data_idx );                      \
/*FPGA,MT6208*/    _d32 = ctrl1;  HW_WRITE( _reg, TO_WORD(_d32) );  _reg += 2;  \
/*FPGA,MT6208*/    _d32 = data1;  HW_WRITE( _reg, LO_WORD(_d32) );  _reg += 2;  \
/*FPGA,MT6208*/                   HW_WRITE( _reg, HI_WORD(_d32) );  _reg += 2;  \
/*FPGA,MT6208*/    _d32 = ctrl2;  HW_WRITE( _reg, TO_WORD(_d32) );  _reg += 2;  \
/*FPGA,MT6208*/    _d32 = data2;  HW_WRITE( _reg, LO_WORD(_d32) );  _reg += 2;  \
/*FPGA,MT6208*/                   HW_WRITE( _reg, HI_WORD(_d32) );  _reg += 2;  \
/*FPGA,MT6208*/    _d32 = ctrl3;  HW_WRITE( _reg, TO_WORD(_d32) );  _reg += 2;  \
/*FPGA,MT6208*/    _d32 = data3;  HW_WRITE( _reg, LO_WORD(_d32) );  _reg += 2;  \
/*FPGA,MT6208*/                   HW_WRITE( _reg, HI_WORD(_d32) );              \
/*FPGA,MT6208*/ }
/*FPGA,MT6208*/
/*FPGA,MT6208*/ #define  HW_WRITE_BSI_DATA_4( data_idx, ctrl1,data1, ctrl2,data2, ctrl3,data3, ctrl4,data4 )  \
/*FPGA,MT6208*/ {  long     _d32;                                               \
/*FPGA,MT6208*/    APBADDR  _reg = BSI_Dn_CON( data_idx );                      \
/*FPGA,MT6208*/    _d32 = ctrl1;  HW_WRITE( _reg, TO_WORD(_d32) );  _reg += 2;  \
/*FPGA,MT6208*/    _d32 = data1;  HW_WRITE( _reg, LO_WORD(_d32) );  _reg += 2;  \
/*FPGA,MT6208*/                   HW_WRITE( _reg, HI_WORD(_d32) );  _reg += 2;  \
/*FPGA,MT6208*/    _d32 = ctrl2;  HW_WRITE( _reg, TO_WORD(_d32) );  _reg += 2;  \
/*FPGA,MT6208*/    _d32 = data2;  HW_WRITE( _reg, LO_WORD(_d32) );  _reg += 2;  \
/*FPGA,MT6208*/                   HW_WRITE( _reg, HI_WORD(_d32) );  _reg += 2;  \
/*FPGA,MT6208*/    _d32 = ctrl3;  HW_WRITE( _reg, TO_WORD(_d32) );  _reg += 2;  \
/*FPGA,MT6208*/    _d32 = data3;  HW_WRITE( _reg, LO_WORD(_d32) );  _reg += 2;  \
/*FPGA,MT6208*/                   HW_WRITE( _reg, HI_WORD(_d32) );  _reg += 2;  \
/*FPGA,MT6208*/    _d32 = ctrl4;  HW_WRITE( _reg, TO_WORD(_d32) );  _reg += 2;  \
/*FPGA,MT6208*/    _d32 = data4;  HW_WRITE( _reg, LO_WORD(_d32) );  _reg += 2;  \
/*FPGA,MT6208*/                   HW_WRITE( _reg, HI_WORD(_d32) );              \
/*FPGA,MT6208*/ }
/*FPGA,MT6208*/
#endif

#if  IS_CHIP_MT6205_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6205~*/
/*MT6205~*/ #define  HW_WRITE_BSI_DATA( addr, data )   \
/*MT6205~*/ {  HW_WRITE( (APBADDR32)(addr), (data) );  \
/*MT6205~*/ }
/*MT6205~*/
/*MT6205~*/ #define  HW_WRITE_BSI_DATA_1( data_idx, ctrl,data )                \
/*MT6205~*/ {  long     _d32;                                                  \
/*MT6205~*/    APBADDR  _reg = BSI_Dn_CON( data_idx );                         \
/*MT6205~*/    _d32 = ctrl;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += 2;  \
/*MT6205~*/    _d32 = data;  HW_WRITE( (APBADDR32)(_reg), _d32 );              \
/*MT6205~*/ }
/*MT6205~*/
/*MT6205~*/ #define  HW_WRITE_BSI_DATA_2( data_idx, ctrl1,data1, ctrl2,data2 )    \
/*MT6205~*/ {  long     _d32;                                                   \
/*MT6205~*/    APBADDR  _reg = BSI_Dn_CON( data_idx );                          \
/*MT6205~*/    _d32 = ctrl1;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += 2;  \
/*MT6205~*/    _d32 = data1;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _reg += 2;  \
/*MT6205~*/    _d32 = ctrl2;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += 2;  \
/*MT6205~*/    _d32 = data2;  HW_WRITE( (APBADDR32)(_reg), _d32 );              \
/*MT6205~*/ }
/*MT6205~*/
/*MT6205~*/ #define  HW_WRITE_BSI_DATA_3( data_idx, ctrl1,data1, ctrl2,data2, ctrl3,data3 )  \
/*MT6205~*/ {  long     _d32;                                                   \
/*MT6205~*/    APBADDR  _reg = BSI_Dn_CON( data_idx );                          \
/*MT6205~*/    _d32 = ctrl1;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += 2;  \
/*MT6205~*/    _d32 = data1;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _reg += 2;  \
/*MT6205~*/    _d32 = ctrl2;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += 2;  \
/*MT6205~*/    _d32 = data2;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _reg += 2;  \
/*MT6205~*/    _d32 = ctrl3;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += 2;  \
/*MT6205~*/    _d32 = data3;  HW_WRITE( (APBADDR32)(_reg), _d32 );              \
/*MT6205~*/ }
/*MT6205~*/
/*MT6205~*/ #define  HW_WRITE_BSI_DATA_4( data_idx, ctrl1,data1, ctrl2,data2, ctrl3,data3, ctrl4,data4 )  \
/*MT6205~*/ {  long     _d32;                                                   \
/*MT6205~*/    APBADDR  _reg = BSI_Dn_CON( data_idx );                          \
/*MT6205~*/    _d32 = ctrl1;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += 2;  \
/*MT6205~*/    _d32 = data1;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _reg += 2;  \
/*MT6205~*/    _d32 = ctrl2;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += 2;  \
/*MT6205~*/    _d32 = data2;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _reg += 2;  \
/*MT6205~*/    _d32 = ctrl3;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += 2;  \
/*MT6205~*/    _d32 = data3;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _reg += 2;  \
/*MT6205~*/    _d32 = ctrl4;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += 2;  \
/*MT6205~*/    _d32 = data4;  HW_WRITE( (APBADDR32)(_reg), _d32 );              \
/*MT6205~*/ }
/*MT6205~*/
/*MT6205~*/ #define  HW_WRITE_BSI_DATA_5( data_idx, ctrl1,data1, ctrl2,data2, ctrl3,data3, ctrl4,data4, ctrl5,data5 )  \
/*MT6205~*/ {  long     _d32;                                                   \
/*MT6205~*/    APBADDR  _reg = BSI_Dn_CON( data_idx );                          \
/*MT6205~*/    _d32 = ctrl1;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += 2;  \
/*MT6205~*/    _d32 = data1;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _reg += 2;  \
/*MT6205~*/    _d32 = ctrl2;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += 2;  \
/*MT6205~*/    _d32 = data2;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _reg += 2;  \
/*MT6205~*/    _d32 = ctrl3;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += 2;  \
/*MT6205~*/    _d32 = data3;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _reg += 2;  \
/*MT6205~*/    _d32 = ctrl4;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += 2;  \
/*MT6205~*/    _d32 = data4;  HW_WRITE( (APBADDR32)(_reg), _d32 );  _reg += 2;  \
/*MT6205~*/    _d32 = ctrl5;  HW_WRITE( _reg, TO_WORD(_d32) );      _reg += 2;  \
/*MT6205~*/    _d32 = data5;  HW_WRITE( (APBADDR32)(_reg), _d32 );              \
/*MT6205~*/ }
/*MT6205~*/
#endif

/*=======================================================================================================================*/
#if IS_CHIP_MT6227
/*MT6227*/ typedef  union
/*MT6227*/ {  struct
/*MT6227*/    {  /*-RX_CFG----------*/
/*MT6227*/       int      swap : 1;
/*MT6227*/       int   bypfltr : 1;
/*MT6227*/       int reserved1 : 10;
/*MT6227*/       int      lpdn : 4;
/*MT6227*/       /*-RX_CON----------*/
/*MT6227*/       int     blpen : 2;
/*MT6227*/       int reserved2 : 14;
/*MT6227*/       /*-BBRX_AC_CON-----*/
/*MT6227*/       int   calbias : 5;
/*MT6227*/       int      gain : 1;
/*MT6227*/       int    pdnchp : 1;
/*MT6227*/       int       rsv : 1;
/*MT6227*/       int      isel : 2;
/*MT6227*/       int      qsel : 2;
/*MT6227*/       int reserved3 : 4;
/*MT6227*/    } field;
/*MT6227*/    unsigned short  data[3];
/*MT6227*/ } BFERXSET;
/*MT6227*/
/*MT6227*/ typedef  union
/*MT6227*/ {  struct
/*MT6227*/    {  /*-TX_CFG----------*/
/*MT6227*/       int     apnden : 1;
/*MT6227*/       int  reserved1 : 15;
/*MT6227*/       /*-TX_CON----------*/
/*MT6227*/       int       iqswap : 1;
/*MT6227*/       int      calrcen : 1;
/*MT6227*/       int iqswap_onfly : 1;
/*MT6227*/       int    reserved2 : 13;
/*MT6227*/       /*-TX_OFF----------*/
/*MT6227*/       int       offi : 6;
/*MT6227*/       int  reserved3 : 2;
/*MT6227*/       int       offq : 6;
/*MT6227*/       int  reserved4 : 2;
/*MT6227*/       /*-BBTX_AC_CON0----*/
/*MT6227*/       int      trimq : 4;
/*MT6227*/       int      trimi : 4;
/*MT6227*/       int   calrcsel : 3;
/*MT6227*/       int       gain : 3;
/*MT6227*/       int startcalrc : 1;
/*MT6227*/       int  calrcdone : 1;
/*MT6227*/       /*-BBTX_AC_CON1----*/
/*MT6227*/       int        cmv : 3;
/*MT6227*/       int    calbias : 5;
/*MT6227*/       int   calrccnt : 4;
/*MT6227*/       int        flt : 1;
/*MT6227*/       int   calrcout : 3;
/*MT6227*/    } field;
/*MT6227*/    unsigned short  data[5];
/*MT6227*/ } BFETXSET;
/*MT6227*/
/*MT6227*/ #define  HW_READ_BFERXSET( _set )         \
/*MT6227*/ { _set.data[0] = HW_READ( RX_CFG );       \
/*MT6227*/   _set.data[1] = HW_READ( RX_CON );       \
/*MT6227*/   _set.data[2] = HW_READ( BBRX_AC_CON );  \
/*MT6227*/ }
/*MT6227*/
/*MT6227*/ #define  HW_WRITE_BFERXSET( _set )        \
/*MT6227*/ { HW_WRITE( RX_CFG     , _set.data[0] );  \
/*MT6227*/   HW_WRITE( RX_CON     , _set.data[1] );  \
/*MT6227*/   HW_WRITE( BBRX_AC_CON, _set.data[2] );  \
/*MT6227*/ }
/*MT6227*/
/*MT6227*/ #define  HW_READ_BFETXSET( _set )         \
/*MT6227*/ { _set.data[0] = HW_READ( TX_CFG );       \
/*MT6227*/   _set.data[1] = HW_READ( TX_CON );       \
/*MT6227*/   _set.data[2] = HW_READ( TX_OFF );       \
/*MT6227*/   _set.data[3] = HW_READ( BBTX_AC_CON0 ); \
/*MT6227*/   _set.data[4] = HW_READ( BBTX_AC_CON1 ); \
/*MT6227*/ }
/*MT6227*/
/*MT6227*/ #define  HW_WRITE_BFETXSET( _set )        \
/*MT6227*/ { HW_WRITE( TX_CFG      , _set.data[0] ); \
/*MT6227*/   HW_WRITE( TX_CON      , _set.data[1] ); \
/*MT6227*/   HW_WRITE( TX_OFF      , _set.data[2] ); \
/*MT6227*/   HW_WRITE( BBTX_AC_CON0, _set.data[3] ); \
/*MT6227*/   HW_WRITE( BBTX_AC_CON1, _set.data[4] ); \
/*MT6227*/ }
/*MT6227*/

#elif  IS_CHIP_MT6225_AND_LATTER_VERSION || IS_CHIP_MT6223
/*MT6223,MT6225~*/ typedef  union
/*MT6223,MT6225~*/ {  struct
/*MT6223,MT6225~*/    {  /*-RX_CFG----------*/
/*MT6223,MT6225~*/       int      swap : 1;
/*MT6223,MT6225~*/       int   bypfltr : 1;
/*MT6223,MT6225~*/       int _2xfirsel : 1;
/*MT6223,MT6225~*/       int reserved1 : 1;
/*MT6223,MT6225~*/       int   firtpno : 6; //
/*MT6223,MT6225~*/       int reserved2 : 6;
/*MT6223,MT6225~*/       /*-RX_CON----------*/
/*MT6223,MT6225~*/       int     blpen : 2;
/*MT6223,MT6225~*/       int ph_roen_w : 1;
/*MT6223,MT6225~*/       int ph_roen_n : 1;
/*MT6223,MT6225~*/       int  igainsel : 4;
/*MT6223,MT6225~*/       int pwrshftno : 4;
/*MT6223,MT6225~*/       int reserved3 : 4;
/*MT6223,MT6225~*/       /*-BBRX_AC_CON-----*/
/*MT6223,MT6225~*/       int   calbias : 5;
/*MT6223,MT6225~*/       int      gain : 2;
/*MT6223,MT6225~*/       int       rsv : 1;
/*MT6223,MT6225~*/       int      isel : 2;
/*MT6223,MT6225~*/       int      qsel : 2;
/*MT6223,MT6225~*/       int   dithdis : 1;
/*MT6223,MT6225~*/       int reserved4 : 3;
/*MT6223,MT6225~*/       /*-RX_PWR_CON----*/
/*MT6223,MT6225~*/       int  RXID_PWR_OFF : 8;
/*MT6223,MT6225~*/       int  RXID_PWR_PER : 8;
/*MT6223,MT6225~*/       /*-RX_CSSEEL_CON----*/
/*MT6223,MT6225~*/       int ST_B_WCOF_SEL : 4;
/*MT6223,MT6225~*/       int ST_B_NCOF_SEL : 4;
/*MT6223,MT6225~*/       int     reserved5 : 4;
/*MT6223,MT6225~*/       int ST_A_NCOF_SEL : 4;
/*MT6223,MT6225~*/    } field;
/*MT6223,MT6225~*/    unsigned short  data[5];
/*MT6223,MT6225~*/ } BFERXSET;
/*MT6223,MT6225~*/
/*MT6223,MT6225~*/ typedef  union
/*MT6223,MT6225~*/ {  struct
/*MT6223,MT6225~*/    {  /*-TX_CFG----------*/
/*MT6223,MT6225~*/       int     apnden : 1;
/*MT6223,MT6225~*/       int  reserved1 : 3;
/*MT6223,MT6225~*/       int      mdbyp : 1;
/*MT6223,MT6225~*/       int       sgen : 1;
/*MT6223,MT6225~*/       int  all_10_en : 2;
/*MT6223,MT6225~*/       int  reserved2 : 8;
/*MT6223,MT6225~*/       /*-TX_CON----------*/
/*MT6223,MT6225~*/       int     iqswap : 1;
/*MT6223,MT6225~*/       int  reserved3 : 7;
/*MT6223,MT6225~*/       int      phsel : 3;
/*MT6223,MT6225~*/       int  reserved4 : 5;
/*MT6223,MT6225~*/       /*-TX_OFF----------*/
/*MT6223,MT6225~*/       int       offi : 6;
/*MT6223,MT6225~*/       int  reserved5 : 2;
/*MT6223,MT6225~*/       int       offq : 6;
/*MT6223,MT6225~*/       int  reserved6 : 1;
/*MT6223,MT6225~*/       int    off_typ : 1;
/*MT6223,MT6225~*/       /*-BBTX_AC_CON0----*/
/*MT6223,MT6225~*/       int      trimq : 4;
/*MT6223,MT6225~*/       int      trimi : 4;
/*MT6223,MT6225~*/       int   calrcsel : 3;
/*MT6223,MT6225~*/       int       gain : 3;
/*MT6223,MT6225~*/       int startcalrc : 1;
/*MT6223,MT6225~*/       int  calrcdone : 1;
/*MT6223,MT6225~*/       /*-BBTX_AC_CON1----*/
/*MT6223,MT6225~*/       int        cmv : 3;
/*MT6223,MT6225~*/       int    calbias : 4;
/*MT6223,MT6225~*/       int   calrccnt : 5;
/*MT6223,MT6225~*/       int        flt : 1;
/*MT6223,MT6225~*/       int   calrcout : 3;
/*MT6223,MT6225~*/       /*-BBTX_AC_CON2----*/
/*MT6223,MT6225~*/       int  calrcopen : 1;
/*MT6223,MT6225~*/       int  calrcauto : 1;
/*MT6223,MT6225~*/       int     coarse : 2;
/*MT6223,MT6225~*/       int  reserved7 : 1;
/*MT6223,MT6225~*/       int      dwaen : 1;
/*MT6223,MT6225~*/       int    dac_ptr : 3;
/*MT6223,MT6225~*/       int  dccoarsei : 2;
/*MT6223,MT6225~*/       int  dccoarseq : 2;
/*MT6223,MT6225~*/       int  reserved8 : 3;
/*MT6223,MT6225~*/    } field;
/*MT6223,MT6225~*/    unsigned short  data[6];
/*MT6223,MT6225~*/ } BFETXSET;
/*MT6223,MT6225~*/
/*MT6223,MT6225~*/ #define  HW_READ_BFERXSET( _set )             \
/*MT6223,MT6225~*/ { _set.data[0] = HW_READ( RX_CFG );           \
/*MT6223,MT6225~*/   _set.data[1] = HW_READ( RX_CON );           \
/*MT6223,MT6225~*/   _set.data[2] = HW_READ( BBRX_AC_CON );      \
/*MT6223,MT6225~*/   _set.data[3] = HW_READ( RX_PM_CON   );      \
/*MT6223,MT6225~*/   _set.data[4] = HW_READ( RX_FIR_CSID_CON );  \
/*MT6223,MT6225~*/ }
/*MT6223,MT6225~*/
/*MT6223,MT6225~*/ #define  HW_WRITE_BFERXSET( _set )            \
/*MT6223,MT6225~*/ { HW_WRITE( RX_CFG         , _set.data[0] );  \
/*MT6223,MT6225~*/   HW_WRITE( RX_CON         , _set.data[1] );  \
/*MT6223,MT6225~*/   HW_WRITE( BBRX_AC_CON    , _set.data[2] );  \
/*MT6223,MT6225~*/   HW_WRITE( RX_PM_CON      , _set.data[3] );  \
/*MT6223,MT6225~*/   HW_WRITE( RX_FIR_CSID_CON, _set.data[4] );  \
/*MT6223,MT6225~*/ }
/*MT6223,MT6225~*/
/*MT6223,MT6225~*/ // phsel: 1's complement -> 2's before read out
/*MT6223,MT6225~*/ #define  HW_READ_BFETXSET( _set )                  \
/*MT6223,MT6225~*/ { _set.data[0] = HW_READ( TX_CFG );                \
/*MT6223,MT6225~*/   _set.data[1] = HW_READ( TX_CON );                \
/*MT6223,MT6225~*/   _set.data[2] = HW_READ( TX_OFF );                \
/*MT6223,MT6225~*/   _set.data[3] = HW_READ( BBTX_AC_CON0 );          \
/*MT6223,MT6225~*/   _set.data[4] = HW_READ( BBTX_AC_CON1 );          \
/*MT6223,MT6225~*/   _set.data[5] = HW_READ( BBTX_AC_CON2 );          \
/*MT6223,MT6225~*/   if(_set.field.phsel & ((unsigned char)1<<(3-1))) \
/*MT6223,MT6225~*/      _set.field.phsel++;                           \
/*MT6223,MT6225~*/ }
/*MT6223,MT6225~*/
/*MT6223,MT6225~*/ // phsel: 2's complement -> 1's before write in
/*MT6223,MT6225~*/ #define  HW_WRITE_BFETXSET( _set )                 \
/*MT6223,MT6225~*/ { if(_set.field.phsel & ((unsigned char)1<<(3-1))) \
/*MT6223,MT6225~*/      _set.field.phsel--;                           \
/*MT6223,MT6225~*/   HW_WRITE( TX_CFG      , _set.data[0] );          \
/*MT6223,MT6225~*/   HW_WRITE( TX_CON      , _set.data[1] );          \
/*MT6223,MT6225~*/   HW_WRITE( TX_OFF      , _set.data[2] );          \
/*MT6223,MT6225~*/   HW_WRITE( BBTX_AC_CON0, _set.data[3] );          \
/*MT6223,MT6225~*/   HW_WRITE( BBTX_AC_CON1, _set.data[4] );          \
/*MT6223,MT6225~*/   HW_WRITE( BBTX_AC_CON2, _set.data[5] );          \
/*MT6223,MT6225~*/ }
   
#elif  IS_CHIP_MT6218_AND_LATTER_VERSION
/*MT6218~*/ typedef  union
/*MT6218~*/ {  struct
/*MT6218~*/    {  /*-RX_CFG----------*/
/*MT6218~*/       int      swap : 1;
/*MT6218~*/       int   bypfltr : 1;
/*MT6218~*/       int reserved1 : 10;
/*MT6218~*/       int      lpdn : 4;
/*MT6218~*/       /*-RX_CON----------*/
/*MT6218~*/       int     blpen : 2;
/*MT6218~*/       int reserved2 : 14;
/*MT6218~*/       /*-BBRX_AC_CON-----*/
/*MT6218~*/       int   calbias : 5;
/*MT6218~*/       int      gain : 1;
/*MT6218~*/       int    pdnchp : 1;
/*MT6218~*/       int       rsv : 1;
/*MT6218~*/       int      isel : 2;
/*MT6218~*/       int      qsel : 2;
/*MT6218~*/       int reserved3 : 4;
/*MT6218~*/    } field;
/*MT6218~*/    unsigned short  data[3];
/*MT6218~*/ } BFERXSET;
/*MT6218~*/
/*MT6218~*/ typedef  union
/*MT6218~*/ {  struct
/*MT6218~*/    {  /*-TX_CFG----------*/
/*MT6218~*/       int     apnden : 1;
/*MT6218~*/       int  reserved1 : 15;
/*MT6218~*/       /*-TX_CON----------*/
/*MT6218~*/       int     iqswap : 1;
/*MT6218~*/       int    calrcen : 1;
/*MT6218~*/       int  reserved2 : 14;
/*MT6218~*/       /*-TX_OFF----------*/
/*MT6218~*/       int       offi : 6;
/*MT6218~*/       int  reserved3 : 2;
/*MT6218~*/       int       offq : 6;
/*MT6218~*/       int  reserved4 : 2;
/*MT6218~*/       /*-BBTX_AC_CON0----*/
/*MT6218~*/       int      trimq : 4;
/*MT6218~*/       int      trimi : 4;
/*MT6218~*/       int   calrcsel : 3;
/*MT6218~*/       int       gain : 3;
/*MT6218~*/       int startcalrc : 1;
/*MT6218~*/       int  calrcdone : 1;
/*MT6218~*/       /*-BBTX_AC_CON1----*/
/*MT6218~*/       int        cmv : 3;
/*MT6218~*/       int    calbias : 5;
/*MT6218~*/       int   calrccnt : 4;
/*MT6218~*/       int        flt : 1;
/*MT6218~*/       int   calrcout : 3;
/*MT6218~*/    } field;
/*MT6218~*/    unsigned short  data[5];
/*MT6218~*/ } BFETXSET;
/*MT6218~*/
/*MT6218~*/ #define  HW_READ_BFERXSET( _set )         \
/*MT6218~*/ { _set.data[0] = HW_READ( RX_CFG );       \
/*MT6218~*/   _set.data[1] = HW_READ( RX_CON );       \
/*MT6218~*/   _set.data[2] = HW_READ( BBRX_AC_CON );  \
/*MT6218~*/ }
/*MT6218~*/
/*MT6218~*/ #define  HW_WRITE_BFERXSET( _set )        \
/*MT6218~*/ { HW_WRITE( RX_CFG     , _set.data[0] );  \
/*MT6218~*/   HW_WRITE( RX_CON     , _set.data[1] );  \
/*MT6218~*/   HW_WRITE( BBRX_AC_CON, _set.data[2] );  \
/*MT6218~*/ }
/*MT6218~*/
   #if defined(MT6228)
      #if ( defined(MT6228_S00) ||  defined(MT6228_S01) )      
      /*MT6228_S00&01*/ #define  HW_READ_BFETXSET( _set )         \
      /*MT6228_S00&01*/ { _set.data[0] = HW_READ( TX_CFG );       \
      /*MT6228_S00&01*/   _set.data[1] = HW_READ( TX_CON );       \
      /*MT6228_S00&01*/   _set.data[2] = HW_READ( TX_OFF );       \
      /*MT6228_S00&01*/   _set.data[3] = HW_READ( BBTX_AC_CON0 ); \
      /*MT6228_S00&01*/   _set.data[4] = HW_READ( BBTX_AC_CON1 ); \
      /*MT6228_S00&01*/ }
      /*MT6228_S00&01*/ #define  HW_WRITE_BFETXSET( _set )        \
      /*MT6228_S00&01*/ { HW_WRITE( TX_CFG      , _set.data[0] ); \
      /*MT6228_S00&01*/   HW_WRITE( TX_CON      , _set.data[1] ); \
      /*MT6228_S00&01*/   HW_WRITE( TX_OFF      , _set.data[2] ); \
      /*MT6228_S00&01*/   HW_WRITE( BBTX_AC_CON0, _set.data[3] ); \
      /*MT6228_S00&01*/   HW_WRITE( BBTX_AC_CON1, _set.data[4] ); \
      /*MT6228_S00&01*/ }
      #else
      /*MT6228_S02~*/ #define  HW_READ_BFETXSET( _set )         \
      /*MT6228_S02~*/ { _set.data[0] = HW_READ( TX_CFG );       \
      /*MT6229_S02~*/   _set.data[1] = HW_READ( TX_CON ) & 0xFFFE;   \
      /*MT6229_S02~*/   _set.data[1] |= ((HW_READ( TDMA_EVTENA(1) )&0x80)>>7)&0x1;  \
      /*MT6228_S02~*/   _set.data[2] = HW_READ( TX_OFF );       \
      /*MT6228_S02~*/   _set.data[3] = HW_READ( BBTX_AC_CON0 ); \
      /*MT6228_S02~*/   _set.data[4] = HW_READ( BBTX_AC_CON1 ); \
      /*MT6228_S02~*/ }
      /*MT6228_S02~*/ #define  HW_WRITE_BFETXSET( _set )        \
      /*MT6228_S02~*/ { HW_WRITE( TX_CFG      , _set.data[0] ); \
      /*MT6228_S02~*/   HW_WRITE( TX_CON      , _set.data[1] ); \
      /*MT6228_S02~*/   HW_WRITE( TDMA_EVTENA(1),               \
      /*MT6228_S02~*/ ( HW_READ( TDMA_EVTENA(1) )&0xFF7F)|(( _set.data[1]<<7)&0x0080)); \
      /*MT6228_S02~*/   HW_WRITE( TX_OFF      , _set.data[2] ); \
      /*MT6228_S02~*/   HW_WRITE( BBTX_AC_CON0, _set.data[3] ); \
      /*MT6228_S02~*/   HW_WRITE( BBTX_AC_CON1, _set.data[4] ); \
      /*MT6228_S02~*/ }
      #endif
   #else
      /*MT6218~*/ #define  HW_READ_BFETXSET( _set )         \
      /*MT6218~*/ { _set.data[0] = HW_READ( TX_CFG );       \
      /*MT6218~*/   _set.data[1] = HW_READ( TX_CON );       \
      /*MT6218~*/   _set.data[2] = HW_READ( TX_OFF );       \
      /*MT6218~*/   _set.data[3] = HW_READ( BBTX_AC_CON0 ); \
      /*MT6218~*/   _set.data[4] = HW_READ( BBTX_AC_CON1 ); \
      /*MT6218~*/ }
      /*MT6218~*/ #define  HW_WRITE_BFETXSET( _set )        \
      /*MT6218~*/ { HW_WRITE( TX_CFG      , _set.data[0] ); \
      /*MT6218~*/   HW_WRITE( TX_CON      , _set.data[1] ); \
      /*MT6218~*/   HW_WRITE( TX_OFF      , _set.data[2] ); \
      /*MT6218~*/   HW_WRITE( BBTX_AC_CON0, _set.data[3] ); \
      /*MT6218~*/   HW_WRITE( BBTX_AC_CON1, _set.data[4] ); \
      /*MT6218~*/ }
   #endif

#elif IS_CHIP_MT6238   
/*MT6238~*/ typedef  union
/*MT6238~*/ {  struct
/*MT6238~*/    {  /*-RX_CFG----------*/
/*MT6238~*/       int      swap : 1;
/*MT6238~*/       int   bypfltr : 1;
/*MT6238~*/       int reserved1 : 2;
/*MT6238~*/       int   firtpno : 6;
/*MT6238~*/       int reserved2 : 6;
/*MT6238~*/       /*-RX_CON----------*/
/*MT6238~*/       int     blpen : 2;
/*MT6238~*/       int ph_roen_w : 1;
/*MT6238~*/       int ph_roen_n : 1;
/*MT6238~*/       int  igainsel : 4;
/*MT6238~*/       int pwrshftno : 4;
/*MT6238~*/       int reserved3 : 4;
/*MT6238~*/       /*-BBRX_AC_CON-----*/
/*MT6238~*/       int   calbias : 5;
/*MT6238~*/       int      gain : 2;
/*MT6238~*/       int       rsv : 1;
/*MT6238~*/       int      isel : 2;
/*MT6238~*/       int      qsel : 2;
/*MT6238~*/       int   dithdis : 1;   
/*MT6238~*/       int reserved4 : 3;
/*MT6238~*/       /*-RX_PM_CON----*/
/*MT6238~*/       int  RXID_PWR_OFF : 8;
/*MT6238~*/       int  RXID_PWR_PER : 8;
/*MT6238~*/       /*-RX_FIR_CSID_CON----*/
/*MT6238~*/       int ST_B_WCOF_SEL : 4;
/*MT6238~*/       int ST_B_NCOF_SEL : 4;
/*MT6238~*/       int     reserved5 : 4;
/*MT6238~*/       int ST_A_NCOF_SEL : 4;
/*MT6238~*/    } field;
/*MT6238~*/    unsigned short  data[5];
/*MT6238~*/ } BFERXSET;
/*MT6238~*/
/*MT6238~*/ typedef  union
/*MT6238~*/ {  struct
/*MT6238~*/    {  /*-TX_CFG----------*/
/*MT6238~*/       int     apnden : 1;
/*MT6238~*/       int      rpsel : 2;
/*MT6238~*/       int      inten : 1;
/*MT6238~*/       int      mdbyp : 1;
/*MT6238~*/       int       sgen : 1;
/*MT6238~*/       int  all_10_en : 2;
/*MT6238~*/       int   sw_qbcnt : 5;
/*MT6238~*/       int  gmsk_dtap_sym : 2;
/*MT6238~*/       int  reserved1 : 1;
/*MT6238~*/       /*-TX_CON----------*/
/*MT6238~*/       int     iqswap : 1;
/*MT6238~*/       int  reserved2 : 1;
/*MT6238~*/       int     mdsel1 : 1;
/*MT6238~*/       int     mdsel2 : 1;
/*MT6238~*/       int     mdsel3 : 1;
/*MT6238~*/       int     mdsel4 : 1;
/*MT6238~*/       int  reserved3 : 2;
/*MT6238~*/       int      phsel : 4;
/*MT6238~*/       int  gmsk_dtap_qb : 2;
/*MT6238~*/       int  reserved4 : 2;
/*MT6238~*/       /*-TX_OFF----------*/
/*MT6238~*/       int       offi : 6;
/*MT6238~*/       int  reserved5 : 2;
/*MT6238~*/       int       offq : 6;
/*MT6238~*/       int  reserved6 : 1;
/*MT6238~*/       int    off_typ : 1;   
/*MT6238~*/       /*-BBTX_AC_CON0----*/
/*MT6238~*/       int      trimq : 4;
/*MT6238~*/       int      trimi : 4;
/*MT6238~*/       int   calrcsel : 3;
/*MT6238~*/       int       gain : 3;
/*MT6238~*/       int startcalrc : 1;
/*MT6238~*/       int  calrcdone : 1;
/*MT6238~*/       /*-BBTX_AC_CON1----*/
/*MT6238~*/       int        cmv : 3;
/*MT6238~*/       int    calbias : 4;
/*MT6238~*/       int   calrccnt : 5;
/*MT6238~*/       int        flt : 1;
/*MT6238~*/       int   calrcout : 3;
/*MT6238~*/       /*-BBTX_AC_CON2----*/
/*MT6238~*/       int  calrcopen : 1;
/*MT6238~*/       int  calrcauto : 1;
/*MT6238~*/       int     coarse : 2;
/*MT6238~*/       int      dwaen : 1;
/*MT6238~*/       int    dac_ptr : 3;
/*MT6238~*/       int  reserved7 : 1;
/*MT6238~*/       int  dccoarsei : 2;
/*MT6238~*/       int  dccoarseq : 2;
/*MT6238~*/       int  reserved8 : 3;
/*MT6238~*/    } field;
/*MT6238~*/    unsigned short  data[6];
/*MT6238~*/ } BFETXSET;
/*MT6238~*/
/*MT6238~*/ #define  HW_READ_BFERXSET( _set )             \
/*MT6238~*/ { _set.data[0] = HW_READ( RX_CFG );           \
/*MT6238~*/   _set.data[1] = HW_READ( RX_CON );           \
/*MT6238~*/   _set.data[2] = HW_READ( BBRX_AC_CON );      \
/*MT6238~*/   _set.data[3] = HW_READ( RX_PM_CON   );      \
/*MT6238~*/   _set.data[4] = HW_READ( RX_FIR_CSID_CON );  \
/*MT6238~*/ }
/*MT6238~*/
/*MT6238~*/ #define  HW_WRITE_BFERXSET( _set )            \
/*MT6238~*/ { HW_WRITE( RX_CFG         , _set.data[0] );  \
/*MT6238~*/   HW_WRITE( RX_CON         , _set.data[1] );  \
/*MT6238~*/   HW_WRITE( BBRX_AC_CON    , _set.data[2] );  \
/*MT6238~*/   HW_WRITE( RX_PM_CON      , _set.data[3] );  \
/*MT6238~*/   HW_WRITE( RX_FIR_CSID_CON, _set.data[4] );  \
/*MT6238~*/ }
/*MT6238~*/
/*MT6238~*/ // phsel: 1's complement -> 2's before read out
/*MT6238~*/ #define  HW_READ_BFETXSET( _set )                              \
/*MT6238~*/ {  _set.data[0] = HW_READ( TX_CFG );                           \
/*MT6238~*/    _set.data[1] = HW_READ( TX_CON );                           \
/*MT6238~*/    _set.data[2] = HW_READ( TX_OFF );                           \
/*MT6238~*/    _set.data[3] = HW_READ( BBTX_AC_CON0 );                     \
/*MT6238~*/    _set.data[4] = HW_READ( BBTX_AC_CON1 );                     \
/*MT6238~*/    _set.data[5] = HW_READ( BBTX_AC_CON2 );                     \
/*MT6238~*/    if(_set.field.phsel & ((unsigned char)1<<(4-1)))            \
/*MT6238~*/       _set.field.phsel++;                                      \
/*MT6238~*/ }
/*MT6238~*/
/*MT6238~*/ // phsel: 2's complement -> 1's before write in
/*MT6238~*/ #define  HW_WRITE_BFETXSET( _set )                             \
/*MT6238~*/ {  if(_set.field.phsel & ((unsigned char)1<<(4-1)))            \
/*MT6238~*/       _set.field.phsel--;                                      \
/*MT6238~*/    HW_WRITE( TX_CFG      , _set.data[0] );                     \
/*MT6238~*/    HW_WRITE( TX_CON      , _set.data[1] );                     \
/*MT6238~*/    HW_WRITE( TX_OFF      , _set.data[2] );                     \
/*MT6238~*/    HW_WRITE( BBTX_AC_CON0, _set.data[3] );                     \
/*MT6238~*/    HW_WRITE( BBTX_AC_CON1, _set.data[4] );                     \
/*MT6238~*/    HW_WRITE( BBTX_AC_CON2, _set.data[5] );                     \
/*MT6238~*/ }
/*MT6238~*/
#elif ((IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION) && (!IS_CHIP_MT6223) && (!IS_CHIP_MT6238))
/*MT6229~*/ typedef  union
/*MT6229~*/ {  struct
/*MT6229~*/    {  /*-RX_CFG----------*/
/*MT6229~*/       int      swap : 1;
/*MT6229~*/       int   bypfltr : 1;
/*MT6229~*/       int _2xfirsel : 1;
/*MT6229~*/       int reserved1 : 1;
/*MT6229~*/       int   firtpno : 6;
/*MT6229~*/       int reserved2 : 6;
/*MT6229~*/       /*-RX_CON----------*/
/*MT6229~*/       int     blpen : 2;
/*MT6229~*/       int ph_roen_w : 1;
/*MT6229~*/       int ph_roen_n : 1;
/*MT6229~*/       int  igainsel : 4;
/*MT6229~*/       int pwrshftno : 4;
/*MT6229~*/       int reserved3 : 4;
/*MT6229~*/       /*-BBRX_AC_CON-----*/
/*MT6229~*/       int   calbias : 5;
/*MT6229~*/       int      gain : 2;
/*MT6229~*/       int       rsv : 1;
/*MT6229~*/       int      isel : 2;
/*MT6229~*/       int      qsel : 2;
/*MT6229~*/       int reserved4 : 4;
/*MT6229~*/       /*-RX_PM_CON----*/
/*MT6229~*/       int  RXID_PWR_OFF : 8;
/*MT6229~*/       int  RXID_PWR_PER : 8;
/*MT6229~*/       /*-RX_FIR_CSID_CON----*/
/*MT6229~*/       int ST_B_WCOF_SEL : 4;
/*MT6229~*/       int ST_B_NCOF_SEL : 4;
/*MT6229~*/       int     reserved5 : 4;
/*MT6229~*/       int ST_A_NCOF_SEL : 4;
/*MT6229~*/    } field;
/*MT6229~*/    unsigned short  data[5];
/*MT6229~*/ } BFERXSET;
/*MT6229~*/
/*MT6229~*/ typedef  union
/*MT6229~*/ {  struct
/*MT6229~*/    {  /*-TX_CFG----------*/
/*MT6229~*/       int     apnden : 1;
/*MT6229~*/       int      rpsel : 2;
/*MT6229~*/       int      inten : 1;
/*MT6229~*/       int      mdbyp : 1;
/*MT6229~*/       int       sgen : 1;
/*MT6229~*/       int  all_10_en : 2;
/*MT6229~*/       int   sw_qbcnt : 5;
/*MT6229~*/       int  gmsk_dtap_sym : 2;
/*MT6229~*/       int  reserved1 : 1;
/*MT6229~*/       /*-TX_CON----------*/
/*MT6229~*/       int     iqswap : 1;
/*MT6229~*/       int    calrcen : 1;
/*MT6229~*/       int     mdsel1 : 1;
/*MT6229~*/       int     mdsel2 : 1;
/*MT6229~*/       int     mdsel3 : 1;
/*MT6229~*/       int     mdsel4 : 1;
/*MT6229~*/       int  reserved2 : 2;
/*MT6229~*/       int      phsel : 3;
/*MT6229~*/       int  reserved3 : 1;
/*MT6229~*/       int  gmsk_dtap_qb : 2;
/*MT6229~*/       int  reserved4 : 2;
/*MT6229~*/       /*-TX_OFF----------*/
/*MT6229~*/       int       offi : 6;
/*MT6229~*/       int  reserved5 : 2;
/*MT6229~*/       int       offq : 6;
/*MT6229~*/       int  reserved6 : 2;
/*MT6229~*/       /*-BBTX_AC_CON0----*/
/*MT6229~*/       int      trimq : 4;
/*MT6229~*/       int      trimi : 4;
/*MT6229~*/       int   calrcsel : 3;
/*MT6229~*/       int       gain : 3;
/*MT6229~*/       int startcalrc : 1;
/*MT6229~*/       int  calrcdone : 1;
/*MT6229~*/       /*-BBTX_AC_CON1----*/
/*MT6229~*/       int        cmv : 3;
/*MT6229~*/       int    calbias : 4;
/*MT6229~*/       int   calrccnt : 5;
/*MT6229~*/       int        flt : 1;
/*MT6229~*/       int   calrcout : 3;
/*MT6229~*/    } field;
/*MT6229~*/    unsigned short  data[5];
/*MT6229~*/ } BFETXSET;
/*MT6229~*/
/*MT6229~*/ #define  HW_READ_BFERXSET( _set )             \
/*MT6229~*/ { _set.data[0] = HW_READ( RX_CFG );           \
/*MT6229~*/   _set.data[1] = HW_READ( RX_CON );           \
/*MT6229~*/   _set.data[2] = HW_READ( BBRX_AC_CON );      \
/*MT6229~*/   _set.data[3] = HW_READ( RX_PM_CON   );      \
/*MT6229~*/   _set.data[4] = HW_READ( RX_FIR_CSID_CON );  \
/*MT6229~*/ }
/*MT6229~*/
/*MT6229~*/ #define  HW_WRITE_BFERXSET( _set )            \
/*MT6229~*/ { HW_WRITE( RX_CFG         , _set.data[0] );  \
/*MT6229~*/   HW_WRITE( RX_CON         , _set.data[1] );  \
/*MT6229~*/   HW_WRITE( BBRX_AC_CON    , _set.data[2] );  \
/*MT6229~*/   HW_WRITE( RX_PM_CON      , _set.data[3] );  \
/*MT6229~*/   HW_WRITE( RX_FIR_CSID_CON, _set.data[4] );  \
/*MT6229~*/ }
/*MT6229~*/
/*MT6229~*/ #if IS_CHIP_MT6229_S00 || IS_CHIP_MT6268T
/*MT6229~*/ // phsel: 1's complement -> 2's before read out
/*MT6229~*/ /*MT6229_S00*/ #define  HW_READ_BFETXSET( _set )                   \
/*MT6229~*/ /*MT6229_S00*/ { _set.data[0] = HW_READ( TX_CFG );                 \
/*MT6229~*/ /*MT6229_S00*/   _set.data[1] = HW_READ( TX_CON );                 \
/*MT6229~*/ /*MT6229_S00*/   _set.data[2] = HW_READ( TX_OFF );                 \
/*MT6229~*/ /*MT6229_S00*/   _set.data[3] = HW_READ( BBTX_AC_CON0 );           \
/*MT6229~*/ /*MT6229_S00*/   _set.data[4] = HW_READ( BBTX_AC_CON1 );           \
/*MT6229~*/ /*MT6229_S00*/   if(_set.field.phsel & ((unsigned char)1<<(3-1)))  \
/*MT6229~*/ /*MT6229_S00*/      _set.field.phsel++;                            \
/*MT6229~*/ /*MT6229_S00*/ }
/*MT6229~*/ // phsel: 2's complement -> 1's before write in
/*MT6229~*/ /*MT6229_S00*/ #define  HW_WRITE_BFETXSET( _set )                 \
/*MT6238~*/ /*MT6229_S00~*/{ if(_set.field.phsel & ((unsigned char)1<<(3-1))) \
/*MT6238~*/ /*MT6229_S00~*/     _set.field.phsel--;                           \
/*MT6229~*/ /*MT6229_S00*/   HW_WRITE( TX_CFG      , _set.data[0] );          \
/*MT6229~*/ /*MT6229_S00*/   HW_WRITE( TX_CON      , _set.data[1] );          \
/*MT6229~*/ /*MT6229_S00*/   HW_WRITE( TX_OFF      , _set.data[2] );          \
/*MT6229~*/ /*MT6229_S00*/   HW_WRITE( BBTX_AC_CON0, _set.data[3] );          \
/*MT6229~*/ /*MT6229_S00*/   HW_WRITE( BBTX_AC_CON1, _set.data[4] );          \
/*MT6229~*/ /*MT6229_S00*/ }
/*MT6229~*/ #else
/*MT6229~*/ // phsel: 1's complement -> 2's before read out
/*MT6229~*/ /*MT6229_S01*/ #define  HW_READ_BFETXSET( _set )                             \
/*MT6229~*/ /*MT6229_S01*/ { _set.data[0] = HW_READ( TX_CFG );                           \
/*MT6229~*/ /*MT6229_S01*/   _set.data[1] = HW_READ( TX_CON ) & 0xFFFE;                  \
/*MT6229~*/ /*MT6229_S01*/   _set.data[1] |= ((HW_READ( TDMA_EVTENA(1) )&0x80)>>7)&0x1;  \
/*MT6229~*/ /*MT6229_S01*/   _set.data[2] = HW_READ( TX_OFF );                           \
/*MT6229~*/ /*MT6229_S01*/   _set.data[3] = HW_READ( BBTX_AC_CON0 );                     \
/*MT6229~*/ /*MT6229_S01*/   _set.data[4] = HW_READ( BBTX_AC_CON1 );                     \
/*MT6229~*/ /*MT6229_S01*/   if(_set.field.phsel & ((unsigned char)1<<(3-1)))            \
/*MT6229~*/ /*MT6229_S01*/      _set.field.phsel++;                                      \
/*MT6229~*/ /*MT6229_S01*/ }
/*MT6229~*/ // phsel: 2's complement -> 1's before write in
/*MT6229~*/ /*MT6229_S01~*/ #define  HW_WRITE_BFETXSET( _set )                                \
/*MT6238~*/ /*MT6229_S01~*/ { if(_set.field.phsel & ((unsigned char)1<<(3-1)))                \
/*MT6238~*/ /*MT6229_S01~*/      _set.field.phsel--;                                          \
/*MT6229~*/ /*MT6229_S01~*/   HW_WRITE( TX_CFG      , _set.data[0] );                         \
/*MT6229~*/ /*MT6229_S01~*/   HW_WRITE( TX_CON      , _set.data[1] );                         \
/*MT6229~*/ /*MT6229_S01~*/   HW_WRITE( TDMA_EVTENA(1),                                       \
/*MT6229~*/ /*MT6229_S01~*/ ( HW_READ( TDMA_EVTENA(1) )&0xFF7F)|(( _set.data[1]<<7)&0x0080)); \
/*MT6229~*/ /*MT6229_S01~*/   HW_WRITE( TX_OFF      , _set.data[2] );                         \
/*MT6229~*/ /*MT6229_S01~*/   HW_WRITE( BBTX_AC_CON0, _set.data[3] );                         \
/*MT6229~*/ /*MT6229_S01~*/   HW_WRITE( BBTX_AC_CON1, _set.data[4] );                         \
/*MT6229~*/ /*MT6229_S01~*/ }
/*MT6229~*/ #endif
#else
/*OTHERS*/ typedef  union
/*OTHERS*/ {  struct
/*OTHERS*/    {  /*-RX_CFG----------*/
/*OTHERS*/       int reserved1 : 1;
/*OTHERS*/       int      swap : 1;
/*OTHERS*/       int      chop : 1;
/*OTHERS*/       int    offcal : 1;
/*OTHERS*/       int      isel : 2;
/*OTHERS*/       int      qsel : 2;
/*OTHERS*/       int      gain : 1;
/*OTHERS*/       int   bypflte : 1;
/*OTHERS*/       int reserved2 : 6;
/*OTHERS*/       /*-RX_CON----------*/
/*OTHERS*/       int   calbias : 5;
/*OTHERS*/       int     blpen : 2;
/*OTHERS*/       int reserved3 : 9;
/*OTHERS*/    } field;
/*OTHERS*/    unsigned short  data[2];
/*OTHERS*/ } BFERXSET;
/*OTHERS*/
/*OTHERS*/ typedef  union
/*OTHERS*/ {  struct
/*OTHERS*/    {  /*-TX_CFG----------*/
/*OTHERS*/       int        cmv : 3;
/*OTHERS*/       int       gain : 3;
/*OTHERS*/       int        flt : 1;
/*OTHERS*/       int     lpbkrx : 1;
/*OTHERS*/       int      trimi : 4;
/*OTHERS*/       int      trimq : 4;
/*OTHERS*/       /*-TX_CON----------*/
/*OTHERS*/       int    calbias : 5;
/*OTHERS*/       int   calrcsel : 3;
/*OTHERS*/       int    calrcen : 1;
/*OTHERS*/       int     iqswap : 1;
/*OTHERS*/       int  reserved1 : 2;
/*OTHERS*/       int   calrccnt : 4;
/*OTHERS*/       /*-TX_OFFI---------*/
/*OTHERS*/       int       offi : 6;
/*OTHERS*/       int  reserved2 : 10;
/*OTHERS*/       /*-TX_OFFQ---------*/
/*OTHERS*/       int       offq : 6;
/*OTHERS*/       int  reserved3 : 10;
/*OTHERS*/    } field;
/*OTHERS*/    unsigned short  data[4];
/*OTHERS*/ } BFETXSET;
/*OTHERS*/
/*OTHERS*/ #define  HW_READ_BFERXSET( _set )         \
/*OTHERS*/ { _set.data[0] = HW_READ( RX_CFG );       \
/*OTHERS*/   _set.data[1] = HW_READ( RX_CON );       \
/*OTHERS*/ }
/*OTHERS*/
/*OTHERS*/ #define  HW_WRITE_BFERXSET( _set )        \
/*OTHERS*/ { HW_WRITE( RX_CFG , _set.data[0] );      \
/*OTHERS*/   HW_WRITE( RX_CON , _set.data[1] );      \
/*OTHERS*/ }
/*OTHERS*/
/*OTHERS*/ #define  HW_READ_BFETXSET( _set )         \
/*OTHERS*/ { _set.data[0] = HW_READ( TX_CFG );       \
/*OTHERS*/   _set.data[1] = HW_READ( TX_CON );       \
/*OTHERS*/   _set.data[2] = HW_READ( TX_OFFI );      \
/*OTHERS*/   _set.data[3] = HW_READ( TX_OFFQ );      \
/*OTHERS*/ }
/*OTHERS*/
/*OTHERS*/ #define  HW_WRITE_BFETXSET( _set )        \
/*OTHERS*/ { HW_WRITE( TX_CFG , _set.data[0] );      \
/*OTHERS*/   HW_WRITE( TX_CON , _set.data[1] );      \
/*OTHERS*/   HW_WRITE( TX_OFFI, _set.data[2] );      \
/*OTHERS*/   HW_WRITE( TX_OFFQ, _set.data[3] );      \
/*OTHERS*/ }
#endif
/*=======================================================================================================================*/

#define  AFC_EV0          TDMA_AFC(0)
#define  BDLON0           TDMA_BDLON(0)
#define  BDLOFF0          TDMA_BDLOFF(0)
#define  BULON0           TDMA_BULON(0)
#define  BULOFF0          TDMA_BULOFF(0)
#define  APC_EV0          TDMA_APC(0)
#define  BSI_EV0          TDMA_BSI(0)
#define  BPI_EV0          TDMA_BPI(0)
#define  EVENT_ENA0       TDMA_EVTENA(0)
#define  EVENT_ENA1       TDMA_EVTENA(1)
#define  EVENT_ENA2       TDMA_EVTENA(2)
#define  EVENT_ENA3       TDMA_EVTENA(3)
#define  EVENT_ENA4       TDMA_EVTENA(4)
#define  EVENT_ENA5       TDMA_EVTENA(5)
#define  EVENT_ENA6       TDMA_EVTENA(6)
#define  EVENT_ENA7       TDMA_EVTENA(7)
#define  BSI_EN           BSI_ENA    
#define  BSI_EN1          BSI_ENA1
#define  SHARE_DSPCTL     SHARE_DSPCON
#define  SHARE_D2MCTL     SHARE_D2MCON
#define  SW_RSTN          SW_PERIPH_RSTN

/*=======================================================================================================================*/

/*==============*\
|* Patch Fields *|
\* ===================================================================================================================== */
/* for MT6208 & MT6205 & MT6218                                                                                          */
/* --------------------------------------------------------------------------------------------------------------------- */
#define PATCH_ENA    ((APBADDR)(PATCH_base+0x100))                      /* patch enable register                         */
#define PATCH_P(n)   ((APBADDR)(PATCH_base+0x000+(n)*4))                /* the page number of patched instruction n      */
#define PATCH_A(n)   ((APBADDR)(PATCH_base+0x004+(n)*4))                /*     the address of patched instruction n      */
#define PATCH_IL(n)  ((APBADDR)(PATCH_base+0x008+(n)*4))                /*    low  16 bits of patched instruction n      */
#define PATCH_IH(n)  ((APBADDR)(PATCH_base+0x00C+(n)*4))                /*    high  8 bits of patched instruction n      */
#if  IS_CHIP_MT6229||IS_CHIP_MT6268T
#define PATCH2_ENA    ((APBADDR)(PATCH2_base+0x100))                      /* patch enable register                         */
#define PATCH2_P(n)   ((APBADDR)(PATCH2_base+0x000+(n)*4))                /* the page number of patched instruction n      */
#define PATCH2_A(n)   ((APBADDR)(PATCH2_base+0x004+(n)*4))                /*     the address of patched instruction n      */
#define PATCH2_IL(n)  ((APBADDR)(PATCH2_base+0x008+(n)*4))                /*    low  16 bits of patched instruction n      */
#define PATCH2_IH(n)  ((APBADDR)(PATCH2_base+0x00C+(n)*4))                /*    high  8 bits of patched instruction n      */
#endif
/* ===================================================================================================================== */

/*==========================*\
|* Audio Front End Register *|
\* ===================================================================================================================== */
/* for MT6208                                                                                                            */
/* --------------------------------------------------------------------------------------------------------------------- */
#define  VCSR                   ((APBADDR)(AFE_base+0x0000))            /* Voice-band Common Status Register             */
#define  VAGCR                  ((APBADDR)(AFE_base+0x0004))            /* Voice-band Gain Contol Register               */
#define  VACCR0                 ((APBADDR)(AFE_base+0x0008))            /* Voice-band Analog-Circuit Control Register    */
#define  VACCR1                 ((APBADDR)(AFE_base+0x000C))            /* Voice-band Analog-Circuit Control Register    */
#define  VAPDNCR                ((APBADDR)(AFE_base+0x0010))            /* Voice-band Power Down Control Register        */
#define  VBTDAICR               ((APBADDR)(AFE_base+0x0014))            /* Voice-band Blue Tooth and DAI Control Register*/
#define  VLBCR                  ((APBADDR)(AFE_base+0x0018))            /* Voice-band Look_Back mode Control Register    */
/* ===================================================================================================================== */
/* for MT6205                                                                                                            */
/* --------------------------------------------------------------------------------------------------------------------- */
#define  AFE_MCU_CON            ((APBADDR)(AFE_base+0x0000))            /* AFE MCU Cpntrol Register                      */
#define  AFE_AG_CON             ((APBADDR)(AFE_base+0x0004))            /* AFE Analog Gain Control Register              */
#define  AFE_AC_CON0            ((APBADDR)(AFE_base+0x0008))            /* AFE Analog-Circuit Control Register 0         */
#define  AFE_AC_CON1            ((APBADDR)(AFE_base+0x000C))            /* AFE Analog-Circuit Control Register 1         */
#define  AFE_APDN_CON           ((APBADDR)(AFE_base+0x0010))            /* AFE Analog Power Down Control Register        */
#define  AFE_DAI_CON            ((APBADDR)(AFE_base+0x0014))            /* AFE DAI Control Register                      */
#define  AFE_LB_CON             ((APBADDR)(AFE_base+0x0018))            /* AFE Loop-back Mode Control Register           */
/* ===================================================================================================================== */
/* for MT6218                                                                                                            */
/* --------------------------------------------------------------------------------------------------------------------- */
#define  AFE_VMCU_CON           ((APBADDR)(AFE_base+0x0000))            /* AFE Voice MCU Control Register                */
#define  AFE_VAC_DCON1          ((APBADDR)(AFE_base+0x000C))            /* AFE Voice Analog Circuit Control Register 1   */
#define  AFE_VDB_CON            ((APBADDR)(AFE_base+0x0014))            /* AFE Voice DAI Blue Tooth Control Register     */
#define  AFE_VLB_CON            ((APBADDR)(AFE_base+0x0018))            /* AFE Voice Loop-back Mode Control Register     */
#define  AFE_AMCU_CON0          ((APBADDR)(AFE_base+0x0020))            /* AFE Audio MCU Control Register 0gister        */
#define  AFE_AMCU_CON1          ((APBADDR)(AFE_base+0x0024))            /* AFE Audio Control Register 1                  */
/* ===================================================================================================================== */


/*====================*\
|* Baseband Front End *|
\*====================*/
#if  IS_CHIP_MT6218_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6218~*/ /* ===================================================================================================================== */
/*MT6218~*/ /* for MT6218                                                                                                            */
/*MT6218~*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6218~*/ #define  BFE_CON                ((APBADDR)(BFE_base+0x0000))            /* Base-band Common Control Register             */
/*MT6218~*/ #define  BFE_STA                ((APBADDR)(BFE_base+0x0004))            /* Base-band Common Control Register             */
/*MT6218~*/ #define  TX_CFG                 ((APBADDR)(BFE_base+0x0060))            /* TX Configuration Register                     */
/*MT6218~*/ #define  TX_CON                 ((APBADDR)(BFE_base+0x0064))            /* TX Configuration Register 2                   */
/*MT6218~*/ #define  TX_OFF                 ((APBADDR)(BFE_base+0x0068))            /* TX I Channel Offset Compensation Register     */
/*MT6218~*/ #define  RX_CFG                 ((APBADDR)(BFE_base+0x0010))            /* RX Configuration Register                     */
/*MT6218~*/ #define  RX_CON                 ((APBADDR)(BFE_base+0x0014))            /* RX Control Register                           */
/*MT6218~*/ #define  RX_FIR_COEF(n)         ((APBADDR)(BFE_base+0x0020+(n)*4))      /* RX Digital FIR Filter Coefficient Register  n */
#if IS_CHIP_MT6225_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6229~*/ #define  RX_NBFIR_COEF(n)       ((APBADDR)(BFE_base+0x0070+(n)*4))      /* RX Digital FIR Filter Coefficient Register  n */
/*MT6229~*/ #define  RX_PM_CON              ((APBADDR)(BFE_base+0x0018))            /* RX Interference Detection Power Measurement Control Register */
/*MT6229~*/ #define  RX_FIR_CSID_CON        ((APBADDR)(BFE_base+0x001c))            /* RX FIR Coefficient Set ID Control Register    */
#endif
/*MT6218~*/ #define  BCCR                   BFE_CON                                 /*                                               */
/*MT6218~*/ #define  BCSR                   BFE_STA                                 /*                                               */
/*MT6218~*/ #define  TX_CNTL                TX_CON                                  /*                                               */
/*MT6218~*/ #define  RX_CNTL                RX_CON                                  /*                                               */
/*MT6218~*/ #define  TX_OFFI                TX_OFF                                  /*                                               */
/*MT6218~*/ #define  TX_OFFQ                TX_OFF                                  /*                                               */
/*MT6218~*/ #define  BDLDFCR(n)             RX_FIR_COEF(n)                          /*                                               */
/*MT6218~*/ /* ===================================================================================================================== */
#else
/*OTHERS*/ /* ===================================================================================================================== */
/*OTHERS*/ /* for MT6208                                                                                                            */
/*OTHERS*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*OTHERS*/ #define  BCCR                   ((APBADDR)(BFE_base+0x00D0))            /* Base-band Common Control Register             */
/*OTHERS*/ #define  BCSR                   ((APBADDR)(BFE_base+0x00D4))            /* Base-band Common Status Register              */
/*OTHERS*/ #define  TX_CFG                 ((APBADDR)(BFE_base+0x0010))            /* TX Configuration Register                     */
/*OTHERS*/ #define  TX_CNTL                ((APBADDR)(BFE_base+0x00C0))            /* TX Configuration Register 2                   */
/*OTHERS*/ #define  TX_OFFI                ((APBADDR)(BFE_base+0x0014))            /* TX I Channel Offset Compensation Register     */
/*OTHERS*/ #define  TX_OFFQ                ((APBADDR)(BFE_base+0x0018))            /* TX Q Channel Offset Compensation Register     */
/*OTHERS*/ #define  RX_CFG                 ((APBADDR)(BFE_base+0x0000))            /* RX Configuration Register 0                   */
/*OTHERS*/ #define  RX_CNTL                ((APBADDR)(BFE_base+0x0030))            /* RX Configuration Register 1                   */
/*OTHERS*/ #define  BDLDFCR(n)             ((APBADDR)(BFE_base+0x0040+(n)*4))      /* Base-band DL Digital Filter Coeff. Reigster n */
/*OTHERS*/ /* ===================================================================================================================== */
/*OTHERS*/ /* for MT6205                                                                                                            */
/*OTHERS*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*OTHERS*/ #define  BFE_CON                ((APBADDR)(BFE_base+0x00D0))            /* Base-band Common Control Register             */
/*OTHERS*/ #define  BFE_STA                ((APBADDR)(BFE_base+0x00D4))            /* Base-band Common Status Register              */
/*OTHERS*/ /*       TX_CFG                 ((APBADDR)(BFE_base+0x0010))          *//* TX Configuration Register                     */
/*OTHERS*/ #define  TX_CON                 ((APBADDR)(BFE_base+0x00C0))            /* TX Configuration Register 2                   */
/*OTHERS*/ /*       TX_OFFI                ((APBADDR)(BFE_base+0x0014))          *//* TX I Channel Offset Compensation Register     */
/*OTHERS*/ /*       TX_OFFQ                ((APBADDR)(BFE_base+0x0018))          *//* TX Q Channel Offset Compensation Register     */
/*OTHERS*/ /*       RX_CFG                 ((APBADDR)(BFE_base+0x0000))          *//* RX Configuration Register                     */
/*OTHERS*/ #define  RX_CON                 ((APBADDR)(BFE_base+0x0030))            /* RX Control Register                           */
/*OTHERS*/ #define  RX_FIR_COEF(n)         ((APBADDR)(BFE_base+0x0040+(n)*4))      /* RX Digital FIR Filter Coefficient Register  n */
/*OTHERS*/
/*OTHERS*/ #define  HW_WRITE_BFE_TX_OFFSET_IQ( _ofs_i, _ofs_q ) \
/*OTHERS*/          {  HW_WRITE( TX_OFFI, _ofs_i );   HW_WRITE( TX_OFFQ, _ofs_q );  }
/* ===================================================================================================================== */
#endif

/*====================*\
|* TDMA Timer events *|
\*====================*/
#if  IS_CHIP_MT6218_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6218~*/ /* ===================================================================================================================== */
/*MT6218~*/ /* for MT6218                                                                                                            */
/*MT6218~*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6218~*/ #define  AC_ODS_CON             ((APBADDR)(MIXED_base+0x0000))          /* Analog Chip Output Driving Strength Control Register */
/*MT6218~*/ #define  ACIF_AC_HW_VER         ((APBADDR)(MIXED_base+0x0004))          /* Mix-signal Chip Version Control               */
/*MT6218~*/ #define  AFE_VAG_CON            ((APBADDR)(MIXED_base+0x0100))          /* AFE Voice Analog Gain Control Register        */
/*MT6218~*/ #define  AFE_VAC_CON0           ((APBADDR)(MIXED_base+0x0104))          /* AFE Voice Analog-Circuit Control Register 0   */
/*MT6218~*/ #define  AFE_VAC_CON1           ((APBADDR)(MIXED_base+0x0108))          /* AFE Voice Analog-Circuit Control Register 1   */
/*MT6218~*/ #define  AFE_VAPDN_CON          ((APBADDR)(MIXED_base+0x010C))          /* AFE Voice Analog Power Down Control Register  */
/*MT6218~*/ #define  AFE_AAG_CON            ((APBADDR)(MIXED_base+0x0200))          /* AFE Audio Analog Gain Control Register        */
/*MT6218~*/ #define  AFE_AAC_CON            ((APBADDR)(MIXED_base+0x0204))          /* AFE Audio Analog-Circuit Control Register     */
/*MT6218~*/ #define  AFE_AAPDN_CON          ((APBADDR)(MIXED_base+0x0208))          /* AFE Audio Analog Power Down Control Register  */
/*MT6218~*/ #define  BBRX_AC_CON            ((APBADDR)(MIXED_base+0x0300))          /* BBRX ADC Analog-Circuit Control Register      */
/*MT6218~*/ #define  BBTX_AC_CON0           ((APBADDR)(MIXED_base+0x0400))          /* BBTX DAC Analog-Circuit Control Register 0    */
/*MT6218~*/ #define  BBTX_AC_CON1           ((APBADDR)(MIXED_base+0x0404))          /* BBTX DAC Analog-Circuit Control Register 1    */
   #if IS_CHIP_MT6225_AND_LATTER_VERSION || IS_SAIC_CHIP_MT6223_AND_LATTER_VERSION
/*MT6218~*/ #define  BBTX_AC_CON2           ((APBADDR)(MIXED_base+0x0408))          /* BBTX DAC Analog-Circuit Control Register 2    */
   #endif
/*MT6218~*/ #define  AFC_AC_CON             ((APBADDR)(MIXED_base+0x0500))          /* AFC DAC Analog-Circuit Control Register       */
/*MT6218~*/ #define  APC_AC_CON             ((APBADDR)(MIXED_base+0x0600))          /* APC DAC Analog-Circuit Control Register       */
/*MT6218~*/ #define  AUX_AC_CON             ((APBADDR)(MIXED_base+0x0700))          /* Auxiliary ADC Analog-Circuit Control Register */
/*MT6218~*/ #define  RES_AC_CON(m,n)        ((APBADDR)(MIXED_base+0x0800+(m)*0x100+(n)*4)) /* Reserved                               */
/*MT6218~*/ /* --------------------------------------------------------------------------------------------------------------------- */
#endif

/*====================*\
|* TDMA Timer events *|
\* ===================================================================================================================== */
/* for MT6208                                                                                                            */
/* --------------------------------------------------------------------------------------------------------------------- */
#define TQ_CURRENT_COUNT        ((APBADDR)(TDMA_base+0x0000))           /* read quater bit counter [13:0]                */
#define TQ_WRAP                 ((APBADDR)(TDMA_base+0x0004))           /* latched Qbit counter reset position [13:0]    */
#define TQ_WRAP_IMMEDIATE       ((APBADDR)(TDMA_base+0x0008))           /*  direct Qbit counter reset position [13:0]    */
#define TQ_EVENT_VALID          ((APBADDR)(TDMA_base+0x000C))           /* event latch position [13:0]                   */
#define DTIRQ                   ((APBADDR)(TDMA_base+0x0010))           /* DSP interrupt        [13:0]                   */
#define CTIRQ1                  ((APBADDR)(TDMA_base+0x0014))           /* CPU tdma interrupt 1 [13:0]                   */
#define CTIRQ2                  ((APBADDR)(TDMA_base+0x0018))           /* CPU tdma interrupt 2 [13:0]                   */
#define AFC_EV(n)               ((APBADDR)(TDMA_base+0x0020+((n)*4)))   /* AFC control n [13:0]                          */
#define BDLON(n)                ((APBADDR)(TDMA_base+0x0030+((n)*8)))   /* RX window n start [13:0]                      */
#define BDLOFF(n)               ((APBADDR)(TDMA_base+0x0034+((n)*8)))   /* RX window n end   [13:0]                      */
#define BULON(n)                ((APBADDR)(TDMA_base+0x0060+((n)*8)))   /* TX window n start [13:0]                      */
#define BULOFF(n)               ((APBADDR)(TDMA_base+0x0064+((n)*8)))   /* TX window n end   [13:0]                      */
#define APC_EV(n)               ((APBADDR)(TDMA_base+0x0090+((n)*4)))   /* Power ramp control n [13:0]                   */
#define BSI_EV(n)               ((APBADDR)(TDMA_base+0x00B0+((n)*4)))   /* BSI event n [13:0]                            */
/*Notes: n<=39 in BPI_EV(n), or the addr will be wrong */
#define BPI_EV(n)               ((APBADDR)(TDMA_base+0x0100+((n)*4)+((n/20)*80)))   /* BPI evntn n [13:0]                */
#define BPI_EV_40               ((APBADDR)(TDMA_base+0x0100+0xF0))                  /* BPI evntn 40                      */
#define BPI_EV_41               ((APBADDR)(TDMA_base+0x0100+0xF4))                  /* BPI evntn 41                      */
#define EVENT_ENA(n)            ((APBADDR)(TDMA_base+0x0150+((n)*4)))   /* event enable control n                        */
#define TQ_OFFSET_CONT          ((APBADDR)(TDMA_base+0x0170))           /* Qbit Timer Control Register                   */
#define TQ_BIAS_CONT            ((APBADDR)(TDMA_base+0x0174))           /* Qbit Timer Biasing Control Register           */
#define DTX_CONT                ((APBADDR)(TDMA_base+0x0180))           /* disable BUL0/1/2/3                            */
#define RXINT_CONT              ((APBADDR)(TDMA_base+0x0184))           /* RXINT mode 1 period count & MODE0/1/2/3/4/5 setting */
#define BDL_CONT                ((APBADDR)(TDMA_base+0x0188))           /* ADC ON to BDL_ON count [15:8] & ADC OFF to BDL_OFF count [7:0] */
#define BUL_CONT1               ((APBADDR)(TDMA_base+0x018C))           /* DAC OFF to BUL_ON count [5:0] & DAC ON  to BUL_OFF count [15:8]*/
#define BUL_CONT2               ((APBADDR)(TDMA_base+0x0190))           /* APCEN to BTXEV hysteresis time in Qbit unit   */
#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
#define FB_FLAG                 ((APBADDR)(TDMA_base+0x0194))           /* FB indicator                                  */
#define FB_CLRI                 ((APBADDR)(TDMA_base+0x0198))           /* FB clear of FB indicator                      */
#endif
#if IS_CHIP_MT6238
#define TQ_WRAP_SM              ((APBADDR)(TDMA_base+0x0234))           /* latched Qbit counter reset position of SM     */
#endif
/* ===================================================================================================================== */
/* for MT6205 & MT6218                                                                                                   */
/* --------------------------------------------------------------------------------------------------------------------- */
#define TDMA_TQCNT              TQ_CURRENT_COUNT                        /* read quater bit counter [13:0]                */
#define TDMA_WRAP               TQ_WRAP                                 /* latched Qbit counter reset position [13:0]    */
#define TDMA_WRAPIMD            TQ_WRAP_IMMEDIATE                       /*  direct Qbit counter reset position [13:0]    */
#define TDMA_EVTVAL             TQ_EVENT_VALID                          /* event latch position [13:0]                   */
#define TDMA_DTIRQ              DTIRQ                                   /* DSP interrupt        [13:0]                   */
#define TDMA_CTIRQ1             CTIRQ1                                  /* CPU tdma interrupt 1 [13:0]                   */
#define TDMA_CTIRQ2             CTIRQ2                                  /* CPU tdma interrupt 2 [13:0]                   */
#define TDMA_AFC(n)             AFC_EV(n)                               /* AFC control n [13:0]                          */
#define TDMA_BDLON(n)           BDLON(n)                                /* RX window n start [13:0]                      */
#define TDMA_BDLOFF(n)          BDLOFF(n)                               /* RX window n end   [13:0]                      */
#define TDMA_BULON(n)           BULON(n)                                /* TX window n start [13:0]                      */
#define TDMA_BULOFF(n)          BULOFF(n)                               /* TX window n end   [13:0]                      */
#define TDMA_APC(n)             APC_EV(n)                               /* Power ramp control n [13:0]                   */
#define TDMA_BSI(n)             BSI_EV(n)                               /* BSI event n [13:0]                            */
#define TDMA_BPI(n)             BPI_EV(n)                               /* BPI evntn n [13:0]                            */
#define TDMA_EVTENA(n)          EVENT_ENA(n)                            /* event enable control n                        */
#define TDMA_WRAPOFS            TQ_OFFSET_CONT                          /* Qbit Timer Control Register                   */
#define TDMA_REGBIAS            TQ_BIAS_CONT                            /* Qbit Timer Biasing Control Register           */
#define TDMA_DTXCON             DTX_CONT                                /* disable BUL0/1/2/3                            */
#define TDMA_RXCON              RXINT_CONT                              /* RXINT mode 1 period count & MODE0/1/2/3/4/5 setting */
#define TDMA_BDLCON             BDL_CONT                                /* ADC ON to BDL_ON count [15:8] & ADC OFF to BDL_OFF count [7:0] */
#define TDMA_BULCON1            BUL_CONT1                               /* DAC OFF to BUL_ON count [5:0] & DAC ON  to BUL_OFF count [15:8]*/
#define TDMA_BULCON2            BUL_CONT2                               /* APCEN to BTXEV hysteresis time in Qbit unit   */
                                                                        /*                                               */
#define TDMA_BPI20              ((APBADDR)(TDMA_base+0x01A0))           /* BPI evntn 20 [13:0]                           */
#define TDMA_BPI21              ((APBADDR)(TDMA_base+0x01A4))           /* BPI evntn 21 [13:0]                           */
#if IS_CHIP_MT6227 || IS_CHIP_MT6225_AND_LATTER_VERSION
   #define TDMA_BPI22              ((APBADDR)(TDMA_base+0x01A8))           /* BPI evntn 22 [13:0]                           */
   #define TDMA_BPI23              ((APBADDR)(TDMA_base+0x01AC))           /* BPI evntn 23 [13:0]                           */
   #define TDMA_BPI24              ((APBADDR)(TDMA_base+0x01B0))           /* BPI evntn 24 [13:0]                           */
   #define TDMA_BPI25              ((APBADDR)(TDMA_base+0x01B4))           /* BPI evntn 25 [13:0]                           */

   #define TDMA_AUXEV0              ((APBADDR)(TDMA_base+0x01C0))           /* Auxiliary ADC event                           */
   #define TDMA_AUXEV1              ((APBADDR)(TDMA_base+0x01C4))           /* Auxiliary ADC event                           */
#else
   #define TDMA_AUXEV              ((APBADDR)(TDMA_base+0x01B0))           /* Auxiliary ADC event                           */
#endif
#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
#define TDMA_AUXEV0             ((APBADDR)(TDMA_base+0x0400))           /* Auxiliary ADC event 0                         */
#define TDMA_AUXEV1             ((APBADDR)(TDMA_base+0x0404))           /* Auxiliary ADC event 1                         */
#define TDMA_DSPROMPD           ((APBADDR)(TDMA_base+0x0300))           /* Via ROM Power Down [5:0]        */
#define TDMA_FB_FLAG            FB_FLAG
#define TDMA_FB_CLRI            FB_CLRI
#endif
/* ===================================================================================================================== */

/*================*\
|* BSI  registers *|
\*================*/
#if  (IS_FPGA_TARGET)||(IS_CHIP_MT6208)
/*MT6208,FPGA*/ /* ===================================================================================================================== */
/*MT6208,FPGA*/ /* for MT6208                                                                                                            */
/*MT6208,FPGA*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6208,FPGA*/ #define BSI_CON                 ((APBADDR)(BSI_base+0x0000))            /* BSI control register                          */
/*MT6208,FPGA*/ #define BSI_ENA                 ((APBADDR)(BSI_base+0x0190))            /* BSI event enable register                     */
/*MT6208,FPGA*/ #define BSI_Dn_CON(n)           ((APBADDR)(BSI_base+0x0004+(12*(n))))   /* data n control                                */
/*MT6208,FPGA*/ #define BSI_Dn_LSB(n)           ((APBADDR)(BSI_base+0x0008+(12*(n))))   /* data [15: 0]                                  */
/*MT6208,FPGA*/ #define BSI_Dn_MSB(n)           ((APBADDR)(BSI_base+0x000C+(12*(n))))   /* data [31:16]                                  */
/*MT6208,FPGA*/ #define BSI_Dn_DAT(n)           BSI_Dn_LSB(n)                           /*                                               */
/*MT6208,FPGA*/ /* --------------------------------------------------------------------------------------------------------------------- */
#endif
#if  IS_CHIP_MT6205_AND_LATTER_VERSION
/*MT6205~*/ /* ===================================================================================================================== */
/*MT6205~*/ /* for MT6205 and MT6218                                                                                                 */
/*MT6205~*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6205~*/ #define BSI_CON                 ((APBADDR)(BSI_base+0x0000))            /* BSI control register                          */
/*MT6205~*/ #define BSI_ENA                 ((APBADDR)(BSI_base+0x0190))            /* BSI event enable register                     */
/*MT6205~*/ #define BSI_Dn_CON(n)           ((APBADDR)(BSI_base+0x0004+(8*(n))))    /* data n control                                */
/*MT6205~*/ #define BSI_Dn_DAT(n)           ((APBADDR32)(BSI_base+0x0008+(8*(n))))  /* data [31:0]                                   */
#if  IS_CHIP_MT6227 || IS_CHIP_MT6228 || IS_CHIP_MT6225_AND_LATTER_VERSION
/*MT6228~*/ #define BSI_IO_CON               ((APBADDR)(BSI_base+0x0194))            /* BSI IO mode control register       */
/*MT6228~*/ #define BSI_DOUT                 ((APBADDR)(BSI_base+0x0198))            /* Software programmed data out    */
/*MT6228~*/ #define BSI_DINT                 ((APBADDR)(BSI_base+0x019C))            /* input data from RF IC                  */
#endif
 /* --------------------------------------------------------------------------------------------------------------------- */
#endif
#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6229~*/ /* ===================================================================================================================== */
/*MT6229~*/ /* for MT6229                                                                                                            */
/*MT6229~*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6229~*/ #define BSI_CON                 ((APBADDR)(BSI_base+0x0000))            /* BSI control register                          */
/*MT6229~*/ #define BSI_ENA                 ((APBADDR)(BSI_base+0x0190))            /* BSI event enable register                     */
/*MT6229~*/ #define BSI_Dn_CON(n)           ((APBADDR)(BSI_base+0x0004+(8*(n))))    /* data n control 0~39                           */
/*MT6229~*/ #define BSI_Dn_DAT(n)           ((APBADDR32)(BSI_base+0x0008+(8*(n))))  /* data [31:0]    0~39                           */
/*MT6229~*/ #define BSI_Dn_CON_2(n)         ((APBADDR)(BSI_base+0x0144+(16*(n))))    /* data n control 40~44                          */
/*MT6229~*/ #define BSI_Dn_DAT_2(n)         ((APBADDR32)(BSI_base+0x0150+(8*(n))))  /* data [31:0]    40~44                          */
/*MT6229~*/ #define BSI_ENA1                ((APBADDR)(BSI_base+0x0194))            /* BSI event enable register 1                   */
/*MT6229~*/ #define BSI_IO_CON              ((APBADDR)(BSI_base+0x0198))            /* BSI IO mode control register                  */
/*MT6229~*/ #define BSI_DOUT                ((APBADDR)(BSI_base+0x019C))            /* Software-programmed data out                  */
/*MT6229~*/ #define BSI_DINT                ((APBADDR)(BSI_base+0x01A0))            /* Input Data from RF Chip bit0                  */
/*MT6229~*/ #define BSI_PAIR_NUM            ((APBADDR)(BSI_base+0x01A4))            /* BSI pair number to be used                    */
/*MT6229~*/ /* --------------------------------------------------------------------------------------------------------------------- */
#endif
/*================*\
|* BPI registers  *|
\* ===================================================================================================================== */
/* for MT6208                                                                                                            */
/* --------------------------------------------------------------------------------------------------------------------- */
#define BPI_CTRL                ((APBADDR)(BPI_base+0x0000))                         /* BPI control register             */
#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
	#define BPI_EN                  ((APBADDR)(BPI_base+/*0x0080*/0x00B0))            /* BPI event enable register        */
	#define BPI_EN1                 ((APBADDR)(BPI_base+/*0x0084*/0x00B4))            /* BPI event enable register        */
	#define BPI_EN2                 ((APBADDR)(BPI_base+/*0x0084*/0x00B8))            /* BPI event enable register        */
#elif  IS_CHIP_MT6227 || IS_CHIP_MT6225_AND_LATTER_VERSION
   #define BPI_EN                  ((APBADDR)(BPI_base+0x0094))            /* BPI event enable register                  */
   #define BPI_EN1                 ((APBADDR)(BPI_base+0x0098))            /* BPI event enable register                  */
#else
	#define BPI_EN                  ((APBADDR)(BPI_base+0x0060))            /* BPI event enable register                  */
   #define BPI_EN1                 ((APBADDR)(BPI_base+0x0064))            /* BPI event enable register                  */
#endif
#define BPI_V(n)                ((APBADDR)(BPI_base+0x0004+((n)*4)))    /* data for event n                              */
/* ===================================================================================================================== */
/* for MT6205 & MT6218                                                                                                   */
/* --------------------------------------------------------------------------------------------------------------------- */
#define BPI_CON                 BPI_CTRL                                /* BPI control register                          */
#define BPI_ENA                 BPI_EN                                  /* BPI event enable register                     */
#define BPI_ENA1                BPI_EN1                                 /* BPI event enable register                     */
#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
#define BPI_ENA2                BPI_EN2                                 /* BPI event enable register                     */
#endif
#define BPI_DAT(n)              BPI_V(n)                                /* data for event n                              */
#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
	#define BPI_DATIMM              ((APBADDR)(BPI_base+/*0x007C*/0x00AC))            /* Force change the value of BPI output          */
#elif  IS_CHIP_MT6227 || IS_CHIP_MT6225_AND_LATTER_VERSION
    #define BPI_DATIMM              ((APBADDR)(BPI_base+0x0090))            /* Force change the value of BPI output          */
#else
	#define BPI_DATIMM              ((APBADDR)(BPI_base+0x005C))            /* Force change the value of BPI output          */
#endif
/* ===================================================================================================================== */

/*================*\
|* AFC  registers *|
\* ===================================================================================================================== */
/* for MT6208                                                                                                            */
/* --------------------------------------------------------------------------------------------------------------------- */
#define AFC_CTRL                ((APBADDR)(AFC_base+0x0000))            /* AFC control register                          */
#define AFC_DATA(n)             ((APBADDR)(AFC_base+0x0004+((n)*4)))    /* AFC data n [9:0]                              */
/* ===================================================================================================================== */
/* for MT6205 & MT6218                                                                                                   */
/* --------------------------------------------------------------------------------------------------------------------- */
#define AFC_CON                 AFC_CTRL                                /* AFC control register                          */
#define AFC_DAT(n)              AFC_DATA(n)                             /* AFC data n [9:0]                              */
#define AFC_PUPER               ((APBADDR)(AFC_base+0x0014))            /* AFC power up period                           */
#define AFC_CALIBIAS            ((APBADDR)(AFC_base+0x0028))            /* AFC programmable bias current                 */
/* --------------------------------------------------------------------------------------------------------------------- */

/*====================*\
|* APC data registers *|
\*====================*/
#if  (IS_FPGA_TARGET)||(IS_CHIP_MT6208)
/*FPGA,MT6208*/ /* ===================================================================================================================== */
/*FPGA,MT6208*/ /* for MT6208                                                                                                            */
/*FPGA,MT6208*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*FPGA,MT6208*/ #define APC_A(n)                ((APBADDR)(APC_base+0x0000+((n)*4)))    /* n'th word of APC_A                            */
/*FPGA,MT6208*/ #define APC_B(n)                ((APBADDR)(APC_base+0x0040+((n)*4)))    /* n'th word of APC_B                            */
/*FPGA,MT6208*/ #define APC_C(n)                ((APBADDR)(APC_base+0x0080+((n)*4)))    /* n'th word of APC_C                            */
/*FPGA,MT6208*/ #define APC_D(n)                ((APBADDR)(APC_base+0x00C0+((n)*4)))    /* n'th word of APC_D                            */
/*FPGA,MT6208*/ #define APC_E(n)                ((APBADDR)(APC_base+0x0100+((n)*4)))    /* n'th word of APC_E                            */
/*FPGA,MT6208*/ #define APC(m, n)               ((APBADDR)(APC_base+0x0000+((((m)*16)+(n))*4)))  /* n'th word of APC_EVm                 */
/*FPGA,MT6208*/ #define APC_CTRL                ((APBADDR)(APC_base+0x01C0))            /* APC control register                          */
/*FPGA,MT6208*/ #define APC_CON                 APC_CTRL                                /*                                               */
/*FPGA,MT6208*/ #define APC_OFFSET              ((APBADDR)(APC_base+0x01C4))            /* APC offset register                           */
/*FPGA,MT6208*/ /* --------------------------------------------------------------------------------------------------------------------- */
#endif
#if  IS_CHIP_MT6205
/*MT6205*/ /* ===================================================================================================================== */
/*MT6205*/ /* for MT6205                                                                                                            */
/*MT6205*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6205*/ #define APC_RAMPUP(n)           ((APBADDR32)(APC_base+0x0000+((n)*4)))  /* Rampup Profile #n                             */
/*MT6205*/ #define APC_RAMPDN(n)           ((APBADDR32)(APC_base+0x0010+((n)*4)))  /* Rampdown Profile #n                           */
/*MT6205*/ #define APC_RAMPUP0             APC_RAMPUP(0)                           /* Rampup Profile #0                             */
/*MT6205*/ #define APC_RAMPUP1             APC_RAMPUP(1)                           /* Rampup Profile #1                             */
/*MT6205*/ #define APC_RAMPUP2             APC_RAMPUP(2)                           /* Rampup Profile #2                             */
/*MT6205*/ #define APC_RAMPUP3             APC_RAMPUP(3)                           /* Rampup Profile #3                             */
/*MT6205*/ #define APC_RAMPDN0             APC_RAMPDN(0)                           /* Rampdown Profile #0                           */
/*MT6205*/ #define APC_RAMPDN1             APC_RAMPDN(1)                           /* Rampdown Profile #1                           */
/*MT6205*/ #define APC_RAMPDN2             APC_RAMPDN(2)                           /* Rampdown Profile #2                           */
/*MT6205*/ #define APC_RAMPDN3             APC_RAMPDN(3)                           /* Rampdown Profile #3                           */
/*MT6205*/ #define APC_SCALE               ((APBADDR)(APC_base+0x01CC))            /* APC scalling factor                           */
/*MT6205*/ #define APC_CTRL                ((APBADDR)(APC_base+0x01C0))            /* APC control register                          */
/*MT6205*/ #define APC_CON                 APC_CTRL                                /*                                               */
/*MT6205*/ #define APC_OFFSET              ((APBADDR)(APC_base+0x01C4))            /* APC offset register                           */
/*MT6205*/ /* --------------------------------------------------------------------------------------------------------------------- */
#endif
#if  IS_CHIP_MT6218_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6218~*/ /* ===================================================================================================================== */
/*MT6218~*/ /* for MT6218                                                                                                            */
/*MT6218~*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6218~*/ #define APC_RAMP(n,k)           ((APBADDR32)(APC_base+0x0000+((n)*32)+((k)*4))) /* Rampup Profile #n                             */
/*MT6218~*/ #define APC_SCALL(n)            ((APBADDR)(APC_base+0x0010+((n)*32)))   /* Rampdown Profile #n                           */
/*MT6218~*/ #define APC_SCALR(n)            ((APBADDR)(APC_base+0x0014+((n)*32)))   /* Rampdown Profile #n                           */
/*MT6218~*/ #define APC_OFS(n)              ((APBADDR)(APC_base+0x0018+((n)*32)))   /* Rampdown Profile #n                           */
/*MT6218~*/ #define APC_CTRL                ((APBADDR)(APC_base+0x00E0))            /* APC control register                          */
/*MT6218~*/ #define APC_CON                 APC_CTRL                                /*                                               */
/*MT6218~*/ #define APC_OFFSET              APC_OFS(0)                              /* APC offset register                           */
/*MT6218~*/ /* --------------------------------------------------------------------------------------------------------------------- */
#endif

/*====================*\
|*  SM data registers *|
\* ===================================================================================================================== */
/* for MT6208 & MT6205 & MT6218                                                                    */
/* --------------------------------------------------------------------------------------------------------------------- */
#define SM_PAUSE_M              ((APBADDR)(SM_base+0x000))              /* msb of pause duration [0]                     */
#define SM_PAUSE_L              ((APBADDR)(SM_base+0x004))              /* 16 lsb of pause duration [15:0]               */
#define SM_CLK_SETTLE           ((APBADDR)(SM_base+0x008))              /* clock restart duration [13:0]                 */
#define SM_FINAL_PAUSE_M        ((APBADDR)(SM_base+0x00C))              /* msb of final pause count [0]                  */
#define SM_FINAL_PAUSE_L        ((APBADDR)(SM_base+0x010))              /* 16 lsb of final pause count [15:0]            */
#define SM_QBIT_START           ((APBADDR)(SM_base+0x014))              /* TQ_CURRENT_COUNT value at start of the pause [13:0] */
#define SM_CONTROL              ((APBADDR)(SM_base+0x018))              /* 0: SM_FM_START                                */
                                                                        /* 1: SM_PAUSE_START                             */
#define SM_CON                  SM_CONTROL                              /*                                               */
#define SM_STATUS               ((APBADDR)(SM_base+0x01C))              /* 0: SM_FM_REQUEST                              */
                                                                        /* 1: SM_FM_COMPLETE                             */
                                                                        /* 4: SM_PAUSE_COMPLETE                          */
                                                                        /* 5: SM_PAUSE_INTERRUPT                         */
                                                                        /* 6: SM_PAUSE_COMPLETE                          */
                                                                        /* 7: SM_SETTLING_COMPLETE                       */
                                                                        /* 8: SM_PAUSE_ABORT                             */
#define SM_STA                  SM_STATUS                               /*                                               */
#define SM_FM_DURATION          ((APBADDR)(SM_base+0x020))              /* 32KHz measuremnt duration [15:0]              */
#define SM_FM_RESULT_M          ((APBADDR)(SM_base+0x024))              /* 10 msb of frequency measurement result [9:0]  */
#define SM_FM_RESULT_L          ((APBADDR)(SM_base+0x028))              /* 16 lsb of frequency measurement result [15:0] */
#define SM_CNF                  ((APBADDR)(SM_base+0x02C))              /* SM configuration Register                     */
#define SM_32K_FREE_RUN         ((APBADDR)(SM_base+0x030))

#ifdef __SWDBG_SUPPORT__
#define SWDBG_STA               ((APBADDR32)(SWDBG_base+0x10))          /* Software Debug Controller Status Register  FOR  L1C USE   */ 
#define SWDBG_INT               ((APBADDR)  (SWDBG_base+0x14))          /* Software Debug Controller Interrupt Register              */
#define SWDBG_INTACK            ((APBADDR)  (SWDBG_base+0x18))          /* Software Debug Controller Interrupt Acknowledge Register  */
#define SWDBG_CONA              ((APBADDR32)(SWDBG_base+0x1C))          /* Software Debug Controller Control Register A              */
#define SWDBG_CONB              ((APBADDR32)(SWDBG_base+0x20))          /* Software Debug Controller Control Register B              */
#define SWDBG_CONC              ((APBADDR32)(SWDBG_base+0x24))          /* Software Debug Controller Control Register C              */
#define SWDBG_DDCONA            ((APBADDR32)(SWDBG_base+0x30))          /* Software Debug Controller DSP Debug Control Register A    */
#define SWDBG_DDCONB            ((APBADDR32)(SWDBG_base+0x34))          /* Software Debug Controller DSP Debug Control Register B    */
#define SWDBG_MDTXCONA          ((APBADDR32)(SWDBG_base+0x40))          /* Software Debug Controller MCU TX Debug Control Register A */
#define SWDBG_MDTXCONB          ((APBADDR32)(SWDBG_base+0x44))          /* Software Debug Controller MCU TX Debug Control Register B */
#define SWDBG_MDTXA             ((APBADDR)  (SWDBG_base+0x48))          /* Software Debug Controller MCU Debug TX Data Register A    */
#define SWDBG_MDTXB             ((APBADDR)  (SWDBG_base+0x4C))          /* Software Debug Controller MCU Debug TX Data Register B    */
#define SWDBG_MDRXCON           ((APBADDR32)(SWDBG_base+0x50))          /* Software Debug Controller MCU Debug Rx control Register   */
#define SWDBG_MDRXDAT           ((APBADDR)  (SWDBG_base+0x54))          /* Software Debug Controller MCU Debug RX Data Register      */
#define SWDBG_MPCFG             ((APBADDR32)(SWDBG_base+0x60))          /* Software Debug Controller MCU Profiling Control Register  */
#define SWDBG_MPCON             ((APBADDR32)(SWDBG_base+0x64))          /* Software Debug Controller MCU Profiling Control Register  */
#define SWDBG_MPTIMER           ((APBADDR32)(SWDBG_base+0x68))          /* Software Debug Controller MCU Profiling Timer Register    */
#endif
/* --------------------------------------------------------------------------------------------------------------------- */

/*====================*\
|*  Reset Managerment *|
\* ===================================================================================================================== */
/* for MT6208 & MT6205 & MT6218                                                                    */
/* --------------------------------------------------------------------------------------------------------------------- */
#define WDT_MODE                ((APBADDR)(RGU_base+0x000))             /* Watchdog Timer Control Register               */
#define WDT_LENGTH              ((APBADDR)(RGU_base+0x004))             /* Watchdog Time-out Interval Register           */
#define WDT_RESTART             ((APBADDR)(RGU_base+0x008))             /* Watchdog Timer Restart Register               */
#define WDT_STA                 ((APBADDR)(RGU_base+0x010))             /* Watchdog Timer Status Register                */
#define WDT_RSTINTERVAL         ((APBADDR)(RGU_base+0x018))             /* Watchdog Timer Reset Signal Duration Register */
                                                                        /*                                               */
#define SW_PERIPH_RSTN          ((APBADDR)(RGU_base+0x010))             /* CPU Peripheral Software Reset Register        */
#define SW_DSP_RSTN             ((APBADDR)(RGU_base+0x014))             /* DSP Software Reset Register                   */
/* --------------------------------------------------------------------------------------------------------------------- */

/*========================*\
|* Power Down Managerment *|
\* ===================================================================================================================== */
#define PDN_CON0                ((APBADDR)(CONFIG_base+0x300))          /* Power Down Control 0 Register                 */
#define PDN_CON1                ((APBADDR)(CONFIG_base+0x304))          /* Power Down Control 1 Register                 */
#define PDN_CON2                ((APBADDR)(CONFIG_base+0x308))          /* Power Down Control 2 Register                 */
#define PDN_CON3                ((APBADDR)(CONFIG_base+0x30C))          /* Power Down Control 3 Register                 */
#define PDN_CON4                ((APBADDR)(CONFIG_base+0x330))          /* Power Down Control 4 Register                 */
#define PDN_SET0                ((APBADDR)(CONFIG_base+0x310))          /* Power Down Disable 0 Register                 */
#define PDN_SET1                ((APBADDR)(CONFIG_base+0x314))          /* Power Down Disable 1 Register                 */
#define PDN_SET2                ((APBADDR)(CONFIG_base+0x318))          /* Power Down Disable 2 Register                 */
#define PDN_SET3                ((APBADDR)(CONFIG_base+0x31C))          /* Power Down Disable 3 Register                 */
#define PDN_SET4                ((APBADDR)(CONFIG_base+0x334))          /* Power Down Disable 4 Register                 */
#define PDN_CLR0                ((APBADDR)(CONFIG_base+0x320))          /* Power Down Enable  0 Register                 */
#define PDN_CLR1                ((APBADDR)(CONFIG_base+0x324))          /* Power Down Enable  1 Register                 */
#define PDN_CLR2                ((APBADDR)(CONFIG_base+0x328))          /* Power Down Enable  2 Register                 */
#define PDN_CLR3                ((APBADDR)(CONFIG_base+0x32C))          /* Power Down Enable  3 Register                 */
#define PDN_CLR4                ((APBADDR)(CONFIG_base+0x338))          /* Power Down Enable  4 Register                 */
#define IDN_SEL                 ((APBADDR)(CONFIG_base+0x200))          /* Internal Debug Port Control Register          */
#define MPLL                    ((APBADDR)(CONFIG_base+0x100))          /* MCU Clock Select (13MxN)                      */

#if (!IS_CHIP_MT6225_AND_LATTER_VERSION) && (!IS_SAIC_CHIP_MT6223_AND_LATTER_VERSION)
#define DPLL                    ((APBADDR)(CONFIG_base+0x104))          /* DSP Clock Select (13MxN)                      */
#endif

#if IS_CHIP_MT6238
#define PLL                     ((APBADDR)(PLL_CLKSQ_base+0x000))       /* MPLL(DPLL, UPLL) Frequency Register1          */
#define PLL2                    ((APBADDR)(PLL_CLKSQ_base+0x004))       /* MPLL(DPLL, UPLL) Frequency Register2          */
#define CPLL                    ((APBADDR)(PLL_CLKSQ_base+0x008))       /* CPLL Control Register1                        */
#define CPLL2                   ((APBADDR)(PLL_CLKSQ_base+0x00C))       /* CPLL Control Register2                        */
#define TPLL                    ((APBADDR)(PLL_CLKSQ_base+0x010))       /* TPLL Control Register1                        */
#define TPLL2                   ((APBADDR)(PLL_CLKSQ_base+0x014))       /* TPLL Control Register2                        */
#define CLK_CON                 ((APBADDR)(PLL_CLKSQ_base+0x018))       /* Clock Control Register                        */
#define PDN_CON                 ((APBADDR)(PLL_CLKSQ_base+0x01C))       /* Power-down control                            */
#define SLEEP_CON               ((APBADDR)(CONFIG_base+0x114))          
#define MCUCLK_CON              ((APBADDR)(CONFIG_base+0x118))          /* MCU Clock Control Register                    */
#define DSPCLK_CON              ((APBADDR)(CONFIG_base+0x11C))          /* DSP Clock Control Register                    */

#elif IS_CHIP_MT6225_AND_LATTER_VERSION || IS_CHIP_MT6223 
#define CLK_CON                 ((APBADDR)(CONFIG_base+0x110))
#define SLEEP_CON               ((APBADDR)(CONFIG_base+0x114))
#define MCUCLK_CON              ((APBADDR)(CONFIG_base+0x118))          /* MCU Clock Control Register                    */   
#define DSPCLK_CON              ((APBADDR)(CONFIG_base+0x11C))

#elif IS_CHIP_MT6228 || IS_CHIP_MT6229 ||  IS_CHIP_MT6268T
#define UPLL                    ((APBADDR)(CONFIG_base+0x108))
#define CLK_CON                 ((APBADDR)(CONFIG_base+0x110))
#define SLEEP_CON               ((APBADDR)(CONFIG_base+0x114))
#define MCUCLK_CON              ((APBADDR)(CONFIG_base+0x118))          /* MCU Clock Control Register                    */   
#define DSPCLK_CON              ((APBADDR)(CONFIG_base+0x11C))

#else
#define CLK_CON                 ((APBADDR)(CONFIG_base+0x108))          /* Clock Switch                                  */
                                                                        /* bit 0 : 2x clock divider                      */
                                                                        /* bit 1 : MCU clock switch                      */
                                                                        /* bit 2 : DSP clock switch                      */
                                                                        /* bit 3 : UART clock switch                     */
#define SLEEP_CON               ((APBADDR)(CONFIG_base+0x10C))          /* Sleep Control Register                        */
#define UPLL                    ((APBADDR)(CONFIG_base+0x110))          /*                                               */
   #if  IS_CHIP_MT6217 || IS_CHIP_MT6227
#define MCUCLK_CON              ((APBADDR)(CONFIG_base+0x114))          /* MCU Clock Control */
   #endif                                                                  
#endif                                                                  
                                                                        
#define DMA_GLBSTA              ((APBADDR32)(DMA_base+0x0000))          /* DMA Global Status Register                    */
/* --------------------------------------------------------------------------------------------------------------------- */

/*==========================================*\
|* General Purpose Inputs/Outputs Registers *|
\* =========================================*/
#if  (IS_FPGA_TARGET)||(IS_CHIP_MT6208)
/*FPGA,MT6208*/ /* ===================================================================================================================== */
/*FPGA,MT6208*/ /* for MT6208                                                                                                            */
/*FPGA,MT6208*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*FPGA,MT6208*/ #define GPIO_DIR                ((APBADDR)(GPIO_base+0x0000*2*2))       /* GPIO Direction Register                       */
/*FPGA,MT6208*/ #define GPIO_DOUT               ((APBADDR)(GPIO_base+0x0001*2*2))       /* GPIO Data Output Register                     */
/*FPGA,MT6208*/ #define GPIO_DIN                ((APBADDR)(GPIO_base+0x0002*2*2))       /* GPIO Data Input Register                      */
/*FPGA,MT6208*/ #define GPIO_MODE1              ((APBADDR)(GPIO_base+0x0003*2*2))       /* GPIO Mode 1 Register                          */
/*FPGA,MT6208*/ #define GPIO_MODE2              ((APBADDR)(GPIO_base+0x0004*2*2))       /* GPIO Mode 2 Register                          */
/*FPGA,MT6208*/ #define GPIO_DIO                ((APBADDR)(GPIO_base+0x0006*2*2))       /* GPI Data Input & GPO Data Output Register     */
/*FPGA,MT6208*/ #define GPIO_MODE3              ((APBADDR)(GPIO_base+0x0007*2*2))       /* GPI & GPO Mode Register                       */
/*FPGA,MT6208*/ /* --------------------------------------------------------------------------------------------------------------------- */
#endif
#if  (IS_CHIP_MT6205)
/*MT6205*/ /* ===================================================================================================================== */
/*MT6205*/ /* for MT6205                                                                                                            */
/*MT6205*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6205*/ #define GPIO_DIR1               ((APBADDR)(GPIO_base+0x0000))           /* GPIO Direction Register 1                     */
/*MT6205*/ #define GPIO_DIR2               ((APBADDR)(GPIO_base+0x0004))           /* GPIO Direction Register 2                     */
/*MT6205*/ #define GPIO_PULLEN1            ((APBADDR)(GPIO_base+0x0008))           /* GPIO Pull-up/Pull-down Enable Register 1      */
/*MT6205*/ #define GPIO_PULLEN2            ((APBADDR)(GPIO_base+0x000C))           /* GPIO Pull-up/Pull-down Enable Register 2      */
/*MT6205*/ #define GPIO_DOUT1              ((APBADDR)(GPIO_base+0x0010))           /* GPIO Data Output Register 1                   */
/*MT6205*/ #define GPIO_DOUT2              ((APBADDR)(GPIO_base+0x0014))           /* GPIO Data Output Register 2                   */
/*MT6205*/ #define GPIO_DIN1               ((APBADDR)(GPIO_base+0x0018))           /* GPIO Data input Register 1                    */
/*MT6205*/ #define GPIO_DIN2               ((APBADDR)(GPIO_base+0x001C))           /* GPIO Data input Register 2                    */
/*MT6205*/ #define GPIO_DOUT               ((APBADDR)(GPIO_base+0x0020))           /* GPO  Data Output Register                     */
/*MT6205*/ #define GPIO_MODE1              ((APBADDR)(GPIO_base+0x0024))           /* GPIO Mode Control Register 1                  */
/*MT6205*/ #define GPIO_MODE2              ((APBADDR)(GPIO_base+0x0028))           /* GPIO Mode Control Register 2                  */
/*MT6205*/ #define GPIO_MODE3              ((APBADDR)(GPIO_base+0x002C))           /* GPIO Mode Control Register 3                  */
/*MT6205*/ #define GPIO_MODE4              ((APBADDR)(GPIO_base+0x0030))           /* GPIO Mode Control Register 4                  */
/*MT6205*/ /* --------------------------------------------------------------------------------------------------------------------- */
#endif
#if  (IS_CHIP_MT6218A)
/*MT6218A*/ /* ===================================================================================================================== */
/*MT6218A*/ /* for MT6218A                                                                                                            */
/*MT6218A*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6218A*/ #define GPIO_DIR1               ((APBADDR)(GPIO_base+0x0000))           /* GPIO Direction Register 1                     */
/*MT6218A*/ #define GPIO_DIR2               ((APBADDR)(GPIO_base+0x0010))           /* GPIO Direction Register 2                     */
/*MT6218A*/ #define GPIO_DIR3               ((APBADDR)(GPIO_base+0x0020))           /* GPIO Direction Register 3                     */
/*MT6218A*/ #define GPIO_PULLEN1            ((APBADDR)(GPIO_base+0x0030))           /* GPIO Pull-up/Pull-down Enable Register 1      */
/*MT6218A*/ #define GPIO_PULLEN2            ((APBADDR)(GPIO_base+0x0040))           /* GPIO Pull-up/Pull-down Enable Register 2      */
/*MT6218A*/ #define GPIO_PULLEN3            ((APBADDR)(GPIO_base+0x0050))           /* GPIO Pull-up/Pull-down Enable Register 3      */
/*MT6218A*/ #define GPIO_DOUT1              ((APBADDR)(GPIO_base+0x0060))           /* GPIO Data Output Register 1                   */
/*MT6218A*/ #define GPIO_DOUT2              ((APBADDR)(GPIO_base+0x0070))           /* GPIO Data Output Register 2                   */
/*MT6218A*/ #define GPIO_DOUT3              ((APBADDR)(GPIO_base+0x0080))           /* GPIO Data Output Register 3                   */
/*MT6218A*/ #define GPIO_DIN1               ((APBADDR)(GPIO_base+0x0090))           /* GPIO Data input Register 1                    */
/*MT6218A*/ #define GPIO_DIN2               ((APBADDR)(GPIO_base+0x0094))           /* GPIO Data input Register 2                    */
/*MT6218A*/ #define GPIO_DIN3               ((APBADDR)(GPIO_base+0x0098))           /* GPIO Data input Register 3                    */
/*MT6218A*/ #define GPO_DOUT                ((APBADDR)(GPIO_base+0x00A0))           /* GPO  Data Output Register                     */
/*MT6218A*/ #define GPIO_MODE1              ((APBADDR)(GPIO_base+0x00B0))           /* GPIO Mode Control Register 1                  */
/*MT6218A*/ #define GPIO_MODE2              ((APBADDR)(GPIO_base+0x00C0))           /* GPIO Mode Control Register 2                  */
/*MT6218A*/ #define GPIO_MODE3              ((APBADDR)(GPIO_base+0x00D0))           /* GPIO Mode Control Register 3                  */
/*MT6218A*/ #define GPIO_MODE4              ((APBADDR)(GPIO_base+0x00E0))           /* GPIO Mode Control Register 4                  */
/*MT6218A*/ #define GPIO_MODE5              ((APBADDR)(GPIO_base+0x00F0))           /* GPIO Mode Control Register 5                  */
/*MT6218A*/ #define GPIO_MODE6              ((APBADDR)(GPIO_base+0x0100))           /* GPIO Mode Control Register 6                  */
/*MT6218A*/ #define GPO_MODE                ((APBADDR)(GPIO_base+0x0110))           /* GPIO Mode Control Register 7                  */
/*MT6218A*/ /* --------------------------------------------------------------------------------------------------------------------- */
#endif
#if  IS_CHIP_MT6218B
/*MT6218B*/ /* ===================================================================================================================== */
/*MT6218B*/ /* for MT6218B                                                                                                            */
/*MT6218B*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6218B*/ #define GPIO_DIR1               ((APBADDR)(GPIO_base+0x0000))           /* GPIO Direction Register 1                     */
/*MT6218B*/ #define GPIO_DIR2               ((APBADDR)(GPIO_base+0x0010))           /* GPIO Direction Register 2                     */
/*MT6218B*/ #define GPIO_DIR3               ((APBADDR)(GPIO_base+0x0020))           /* GPIO Direction Register 3                     */
/*MT6218B*/ #define GPIO_PULLEN1            ((APBADDR)(GPIO_base+0x0030))           /* GPIO Pull-up/Pull-down Enable Register 1      */
/*MT6218B*/ #define GPIO_PULLEN2            ((APBADDR)(GPIO_base+0x0040))           /* GPIO Pull-up/Pull-down Enable Register 2      */
/*MT6218B*/ #define GPIO_PULLEN3            ((APBADDR)(GPIO_base+0x0050))           /* GPIO Pull-up/Pull-down Enable Register 3      */
/*MT6218B*/ #define GPIO_DINV1              ((APBADDR)(GPIO_base+0x0060))           /* Register 1                                    */
/*MT6218B*/ #define GPIO_DINV2              ((APBADDR)(GPIO_base+0x0070))           /* Register 2                                    */
/*MT6218B*/ #define GPIO_DINV3              ((APBADDR)(GPIO_base+0x0080))           /* Register 3                                    */
/*MT6218B*/ #define GPIO_DOUT1              ((APBADDR)(GPIO_base+0x0090))           /* GPIO Data Output Register 1                   */
/*MT6218B*/ #define GPIO_DOUT2              ((APBADDR)(GPIO_base+0x00A0))           /* GPIO Data Output Register 2                   */
/*MT6218B*/ #define GPIO_DOUT3              ((APBADDR)(GPIO_base+0x00B0))           /* GPIO Data Output Register 3                   */
/*MT6218B*/ #define GPIO_DIN1               ((APBADDR)(GPIO_base+0x00C0))           /* GPIO Data input Register 1                    */
/*MT6218B*/ #define GPIO_DIN2               ((APBADDR)(GPIO_base+0x00D0))           /* GPIO Data input Register 2                    */
/*MT6218B*/ #define GPIO_DIN3               ((APBADDR)(GPIO_base+0x00E0))           /* GPIO Data input Register 3                    */
/*MT6218B*/ #define GPO_DOUT                ((APBADDR)(GPIO_base+0x00F0))           /* GPO  Data Output Register                     */
/*MT6218B*/ #define GPIO_MODE1              ((APBADDR)(GPIO_base+0x0100))           /* GPIO Mode Control Register 1                  */
/*MT6218B*/ #define GPIO_MODE2              ((APBADDR)(GPIO_base+0x0110))           /* GPIO Mode Control Register 2                  */
/*MT6218B*/ #define GPIO_MODE3              ((APBADDR)(GPIO_base+0x0120))           /* GPIO Mode Control Register 3                  */
/*MT6218B*/ #define GPIO_MODE4              ((APBADDR)(GPIO_base+0x0130))           /* GPIO Mode Control Register 4                  */
/*MT6218B*/ #define GPIO_MODE5              ((APBADDR)(GPIO_base+0x0140))           /* GPIO Mode Control Register 5                  */
/*MT6218B*/ #define GPIO_MODE6              ((APBADDR)(GPIO_base+0x0150))           /* GPIO Mode Control Register 6                  */
/*MT6218B*/ #define GPO_MODE                ((APBADDR)(GPIO_base+0x0160))           /* GPIO Mode Control Register 7                  */
/*MT6218B*/ /* --------------------------------------------------------------------------------------------------------------------- */
#endif
#if  IS_CHIP_MT6219 || IS_CHIP_MT6227 || IS_CHIP_MT6225_AND_LATTER_VERSION || IS_CHIP_MT6223
/*MT6219~*/ /* ===================================================================================================================== */
/*MT6219~*/ /* for MT6219                                                                                                            */
/*MT6219~*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6219~*/ #define GPIO_DIR1               ((APBADDR)(GPIO_base+0x0000))           /* GPIO Direction Register 1                     */
/*MT6219~*/ #define GPIO_DIR2               ((APBADDR)(GPIO_base+0x0010))           /* GPIO Direction Register 2                     */
/*MT6219~*/ #define GPIO_DIR3               ((APBADDR)(GPIO_base+0x0020))           /* GPIO Direction Register 3                     */
/*MT6219~*/ #define GPIO_DIR4               ((APBADDR)(GPIO_base+0x0030))           /* GPIO Direction Register 4                     */
/*MT6219~*/ #define GPIO_PULLEN1            ((APBADDR)(GPIO_base+0x0040))           /* GPIO Pull-up/Pull-down Enable Register 1      */
/*MT6219~*/ #define GPIO_PULLEN2            ((APBADDR)(GPIO_base+0x0050))           /* GPIO Pull-up/Pull-down Enable Register 2      */
/*MT6219~*/ #define GPIO_PULLEN3            ((APBADDR)(GPIO_base+0x0060))           /* GPIO Pull-up/Pull-down Enable Register 3      */
/*MT6219~*/ #define GPIO_PULLEN4            ((APBADDR)(GPIO_base+0x0070))           /* GPIO Pull-up/Pull-down Enable Register 4      */
/*MT6219~*/ #define GPIO_DINV1              ((APBADDR)(GPIO_base+0x0080))           /* Register 1                                    */
/*MT6219~*/ #define GPIO_DINV2              ((APBADDR)(GPIO_base+0x0090))           /* Register 2                                    */
/*MT6219~*/ #define GPIO_DINV3              ((APBADDR)(GPIO_base+0x00A0))           /* Register 3                                    */
/*MT6219~*/ #define GPIO_DINV4              ((APBADDR)(GPIO_base+0x00B0))           /* Register 4                                    */
/*MT6219~*/ #define GPIO_DOUT1              ((APBADDR)(GPIO_base+0x00C0))           /* GPIO Data Output Register 1                   */
/*MT6219~*/ #define GPIO_DOUT2              ((APBADDR)(GPIO_base+0x00D0))           /* GPIO Data Output Register 2                   */
/*MT6219~*/ #define GPIO_DOUT3              ((APBADDR)(GPIO_base+0x00E0))           /* GPIO Data Output Register 3                   */
/*MT6219~*/ #define GPIO_DOUT4              ((APBADDR)(GPIO_base+0x00F0))           /* GPIO Data Output Register 4                   */
/*MT6219~*/ #define GPIO_DIN1               ((APBADDR)(GPIO_base+0x0100))           /* GPIO Data input Register 1                    */
/*MT6219~*/ #define GPIO_DIN2               ((APBADDR)(GPIO_base+0x0110))           /* GPIO Data input Register 2                    */
/*MT6219~*/ #define GPIO_DIN3               ((APBADDR)(GPIO_base+0x0120))           /* GPIO Data input Register 3                    */
/*MT6219~*/ #define GPIO_DIN4               ((APBADDR)(GPIO_base+0x0130))           /* GPIO Data input Register 4                    */
/*MT6219~*/ #define GPO_DOUT                ((APBADDR)(GPIO_base+0x0140))           /* GPO  Data Output Register                     */
/*MT6219~*/ #define GPIO_MODE1              ((APBADDR)(GPIO_base+0x0150))           /* GPIO Mode Control Register 1                  */
/*MT6219~*/ #define GPIO_MODE2              ((APBADDR)(GPIO_base+0x0160))           /* GPIO Mode Control Register 2                  */
/*MT6219~*/ #define GPIO_MODE3              ((APBADDR)(GPIO_base+0x0170))           /* GPIO Mode Control Register 3                  */
/*MT6219~*/ #define GPIO_MODE4              ((APBADDR)(GPIO_base+0x0180))           /* GPIO Mode Control Register 4                  */
/*MT6219~*/ #define GPIO_MODE5              ((APBADDR)(GPIO_base+0x0190))           /* GPIO Mode Control Register 5                  */
/*MT6219~*/ #define GPIO_MODE6              ((APBADDR)(GPIO_base+0x01A0))           /* GPIO Mode Control Register 6                  */
/*MT6219~*/ #define GPIO_MODE7              ((APBADDR)(GPIO_base+0x01B0))           /* GPIO Mode Control Register 7                  */
/*MT6219~*/ #define GPO_MODE                ((APBADDR)(GPIO_base+0x01C0))           /* GPO Mode Control Register                     */
/*MT6219~*/ #if IS_CHIP_MT6223 /*GPO are removed in MT6223*/
/*MT6219~*/ #undef GPO_DOUT                                                         /* GPO  Data Output Register                     */
/*MT6219~*/ #undef GPO_MODE                                                         /* GPO Mode Control Register                     */
/*MT6219~*/ #endif
/*MT6219~*/ /* --------------------------------------------------------------------------------------------------------------------- */
#endif

#if  IS_CHIP_MT6228 || IS_CHIP_MT6229 || IS_CHIP_MT6268T
/*MT6228~*/ /* ===================================================================================================================== */
/*MT6228~*/ /* for MT6218B                                                                                                            */
/*MT6228~*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6228~*/ #define GPIO_DIR1               ((APBADDR)(GPIO_base+0x0000))           /* GPIO Direction Register 1                     */
/*MT6228~*/ #define GPIO_DIR2               ((APBADDR)(GPIO_base+0x0010))           /* GPIO Direction Register 2                     */
/*MT6228~*/ #define GPIO_DIR3               ((APBADDR)(GPIO_base+0x0020))           /* GPIO Direction Register 3                     */
/*MT6228~*/ #define GPIO_DIR4               ((APBADDR)(GPIO_base+0x0030))           /* GPIO Direction Register 4                     */
/*MT6228~*/ #define GPIO_DIR5               ((APBADDR)(GPIO_base+0x0040))           /* GPIO Direction Register 5                     */
/*MT6228~*/ #define GPIO_PULLEN1            ((APBADDR)(GPIO_base+0x0050))           /* GPIO Pull-up/Pull-down Enable Register 1      */
/*MT6228~*/ #define GPIO_PULLEN2            ((APBADDR)(GPIO_base+0x0060))           /* GPIO Pull-up/Pull-down Enable Register 2      */
/*MT6228~*/ #define GPIO_PULLEN3            ((APBADDR)(GPIO_base+0x0070))           /* GPIO Pull-up/Pull-down Enable Register 3      */
/*MT6228~*/ #define GPIO_PULLEN4            ((APBADDR)(GPIO_base+0x0080))           /* GPIO Pull-up/Pull-down Enable Register 4      */
/*MT6228~*/ #define GPIO_PULLEN5            ((APBADDR)(GPIO_base+0x0090))           /* GPIO Pull-up/Pull-down Enable Register 4      */
/*MT6228~*/ #define GPIO_DINV1              ((APBADDR)(GPIO_base+0x00A0))           /* Register 1                                    */
/*MT6228~*/ #define GPIO_DINV2              ((APBADDR)(GPIO_base+0x00B0))           /* Register 2                                    */
/*MT6228~*/ #define GPIO_DINV3              ((APBADDR)(GPIO_base+0x00C0))           /* Register 3                                    */
/*MT6228~*/ #define GPIO_DINV4              ((APBADDR)(GPIO_base+0x00D0))           /* Register 4                                    */
/*MT6228~*/ #define GPIO_DINV5              ((APBADDR)(GPIO_base+0x00E0))           /* Register 4                                    */
/*MT6228~*/ #define GPIO_DOUT1              ((APBADDR)(GPIO_base+0x00F0))           /* GPIO Data Output Register 1                   */
/*MT6228~*/ #define GPIO_DOUT2              ((APBADDR)(GPIO_base+0x0100))           /* GPIO Data Output Register 2                   */
/*MT6228~*/ #define GPIO_DOUT3              ((APBADDR)(GPIO_base+0x0110))           /* GPIO Data Output Register 3                   */
/*MT6228~*/ #define GPIO_DOUT4              ((APBADDR)(GPIO_base+0x0120))           /* GPIO Data Output Register 4                   */
/*MT6228~*/ #define GPIO_DOUT5              ((APBADDR)(GPIO_base+0x0130))           /* GPIO Data Output Register 4                   */
/*MT6228~*/ #define GPIO_DIN1               ((APBADDR)(GPIO_base+0x0140))           /* GPIO Data input Register 1                    */
/*MT6228~*/ #define GPIO_DIN2               ((APBADDR)(GPIO_base+0x0150))           /* GPIO Data input Register 2                    */
/*MT6228~*/ #define GPIO_DIN3               ((APBADDR)(GPIO_base+0x0160))           /* GPIO Data input Register 3                    */
/*MT6228~*/ #define GPIO_DIN4               ((APBADDR)(GPIO_base+0x0170))           /* GPIO Data input Register 4                    */
/*MT6228~*/ #define GPIO_DIN5               ((APBADDR)(GPIO_base+0x0180))           /* GPIO Data input Register 4                    */
/*MT6228~*/ #define GPO_DOUT                ((APBADDR)(GPIO_base+0x0190))           /* GPO  Data Output Register                     */
/*MT6228~*/ #define GPIO_MODE1              ((APBADDR)(GPIO_base+0x01A0))           /* GPIO Mode Control Register 1                  */
/*MT6228~*/ #define GPIO_MODE2              ((APBADDR)(GPIO_base+0x01B0))           /* GPIO Mode Control Register 2                  */
/*MT6228~*/ #define GPIO_MODE3              ((APBADDR)(GPIO_base+0x01C0))           /* GPIO Mode Control Register 3                  */
/*MT6228~*/ #define GPIO_MODE4              ((APBADDR)(GPIO_base+0x01D0))           /* GPIO Mode Control Register 4                  */
/*MT6228~*/ #define GPIO_MODE5              ((APBADDR)(GPIO_base+0x01E0))           /* GPIO Mode Control Register 5                  */
/*MT6228~*/ #define GPIO_MODE6              ((APBADDR)(GPIO_base+0x01F0))           /* GPIO Mode Control Register 6                  */
/*MT6228~*/ #define GPIO_MODE7              ((APBADDR)(GPIO_base+0x0200))           /* GPIO Mode Control Register 6                  */
/*MT6228~*/ #define GPIO_MODE8              ((APBADDR)(GPIO_base+0x0210))           /* GPIO Mode Control Register 6                  */
/*MT6228~*/ #define GPIO_MODE9              ((APBADDR)(GPIO_base+0x0220))           /* GPIO Mode Control Register 6                  */
/*MT6228~*/ #define GPIO_MODE10             ((APBADDR)(GPIO_base+0x0230))           /* GPIO Mode Control Register 6                  */
/*MT6228~*/ #define GPO_MODE1               ((APBADDR)(GPIO_base+0x0240))           /* GPIO Mode Control Register 6                  */
/*MT6228~*/ /* --------------------------------------------------------------------------------------------------------------------- */
#endif

#if  IS_CHIP_MT6238
/*MT6238~*/ /* ===================================================================================================================== */
/*MT6238~*/ /* for MT6238                                                                                                            */
/*MT6238~*/ /* --------------------------------------------------------------------------------------------------------------------- */
/*MT6238~*/ #define GPIO_DIR1               ((APBADDR)(GPIO_base+0x0000))           /* GPIO Direction Register 1                     */
/*MT6238~*/ #define GPIO_DIR2               ((APBADDR)(GPIO_base+0x0040))           /* GPIO Direction Register 2                     */
/*MT6238~*/ #define GPIO_DIR3               ((APBADDR)(GPIO_base+0x0080))           /* GPIO Direction Register 3                     */
/*MT6238~*/ #define GPIO_DIR4               ((APBADDR)(GPIO_base+0x00C0))           /* GPIO Direction Register 4                     */
/*MT6238~*/ #define GPIO_DIR5               ((APBADDR)(GPIO_base+0x0100))           /* GPIO Direction Register 5                     */
/*MT6238~*/ #define GPIO_DIR6               ((APBADDR)(GPIO_base+0x0140))           /* GPIO Direction Register 6                     */
/*MT6238~*/ #define GPIO_PULLEN1            ((APBADDR)(GPIO_base+0x0200))           /* GPIO Pull-up/Pull-down Enable Register 1      */
/*MT6238~*/ #define GPIO_PULLEN2            ((APBADDR)(GPIO_base+0x0240))           /* GPIO Pull-up/Pull-down Enable Register 2      */
/*MT6238~*/ #define GPIO_PULLEN3            ((APBADDR)(GPIO_base+0x0280))           /* GPIO Pull-up/Pull-down Enable Register 3      */
/*MT6238~*/ #define GPIO_PULLEN4            ((APBADDR)(GPIO_base+0x02C0))           /* GPIO Pull-up/Pull-down Enable Register 4      */
/*MT6238~*/ #define GPIO_PULLEN5            ((APBADDR)(GPIO_base+0x0300))           /* GPIO Pull-up/Pull-down Enable Register 5      */
/*MT6238~*/ #define GPIO_PULLEN6            ((APBADDR)(GPIO_base+0x0340))           /* GPIO Pull-up/Pull-down Enable Register 6      */  
/*MT6238~*/ #define GPIO_PULLSEL1           ((APBADDR)(GPIO_base+0x0400))           /* GPIO Pull-up/Pull-down Select Register 1      */  
/*MT6238~*/ #define GPIO_PULLSEL2           ((APBADDR)(GPIO_base+0x0440))           /* GPIO Pull-up/Pull-down Select Register 2      */
/*MT6238~*/ #define GPIO_PULLSEL3           ((APBADDR)(GPIO_base+0x0480))           /* GPIO Pull-up/Pull-down Select Register 3      */  
/*MT6238~*/ #define GPIO_PULLSEL4           ((APBADDR)(GPIO_base+0x04C0))           /* GPIO Pull-up/Pull-down Select Register 4      */  
/*MT6238~*/ #define GPIO_PULLSEL5           ((APBADDR)(GPIO_base+0x0500))           /* GPIO Pull-up/Pull-down Select Register 5      */  
/*MT6238~*/ #define GPIO_PULLSEL6           ((APBADDR)(GPIO_base+0x0540))           /* GPIO Pull-up/Pull-down Select Register 6      */  
/*MT6238~*/ #define GPIO_DINV1              ((APBADDR)(GPIO_base+0x0600))           /* GPIO Data Inversion Control Register 1        */
/*MT6238~*/ #define GPIO_DINV2              ((APBADDR)(GPIO_base+0x0640))           /* GPIO Data Inversion Control Register 2        */
/*MT6238~*/ #define GPIO_DINV3              ((APBADDR)(GPIO_base+0x0680))           /* GPIO Data Inversion Control Register 3        */
/*MT6238~*/ #define GPIO_DINV4              ((APBADDR)(GPIO_base+0x06C0))           /* GPIO Data Inversion Control Register 4        */
/*MT6238~*/ #define GPIO_DINV5              ((APBADDR)(GPIO_base+0x0700))           /* GPIO Data Inversion Control Register 5        */
/*MT6238~*/ #define GPIO_DINV6              ((APBADDR)(GPIO_base+0x0740))           /* GPIO Data Inversion Control Register 6        */
/*MT6238~*/ #define GPIO_DOUT1              ((APBADDR)(GPIO_base+0x0800))           /* GPIO Data Output Register 1                   */
/*MT6238~*/ #define GPIO_DOUT2              ((APBADDR)(GPIO_base+0x0840))           /* GPIO Data Output Register 2                   */
/*MT6238~*/ #define GPIO_DOUT3              ((APBADDR)(GPIO_base+0x0880))           /* GPIO Data Output Register 3                   */
/*MT6238~*/ #define GPIO_DOUT4              ((APBADDR)(GPIO_base+0x08C0))           /* GPIO Data Output Register 4                   */
/*MT6238~*/ #define GPIO_DOUT5              ((APBADDR)(GPIO_base+0x0900))           /* GPIO Data Output Register 5                   */
/*MT6238~*/ #define GPIO_DOUT6              ((APBADDR)(GPIO_base+0x0940))           /* GPIO Data Output Register 6                   */
/*MT6238~*/ #define GPIO_DIN1               ((APBADDR)(GPIO_base+0x0A00))           /* GPIO Data input Register 1                    */
/*MT6238~*/ #define GPIO_DIN2               ((APBADDR)(GPIO_base+0x0A40))           /* GPIO Data input Register 2                    */
/*MT6238~*/ #define GPIO_DIN3               ((APBADDR)(GPIO_base+0x0A80))           /* GPIO Data input Register 3                    */
/*MT6238~*/ #define GPIO_DIN4               ((APBADDR)(GPIO_base+0x0AC0))           /* GPIO Data input Register 4                    */
/*MT6238~*/ #define GPIO_DIN5               ((APBADDR)(GPIO_base+0x0B00))           /* GPIO Data input Register 5                    */
/*MT6238~*/ #define GPIO_DIN6               ((APBADDR)(GPIO_base+0x0B40))           /* GPIO Data input Register 6                    */
/*MT6238~*/ #define GPIO_MODE1              ((APBADDR)(GPIO_base+0x1000))           /* GPIO Mode Control Register 1                  */
/*MT6238~*/ #define GPIO_MODE2              ((APBADDR)(GPIO_base+0x1100))           /* GPIO Mode Control Register 2                  */
/*MT6238~*/ #define GPIO_MODE3              ((APBADDR)(GPIO_base+0x1200))           /* GPIO Mode Control Register 3                  */
/*MT6238~*/ #define GPIO_MODE4              ((APBADDR)(GPIO_base+0x1300))           /* GPIO Mode Control Register 4                  */
/*MT6238~*/ #define GPIO_MODE5              ((APBADDR)(GPIO_base+0x1400))           /* GPIO Mode Control Register 5                  */
/*MT6238~*/ #define GPIO_MODE6              ((APBADDR)(GPIO_base+0x1500))           /* GPIO Mode Control Register 6                  */
/*MT6238~*/ #define GPIO_MODE7              ((APBADDR)(GPIO_base+0x1600))           /* GPIO Mode Control Register 7                  */
/*MT6238~*/ #define GPIO_MODE8              ((APBADDR)(GPIO_base+0x1700))           /* GPIO Mode Control Register 8                  */
/*MT6238~*/ #define GPIO_MODE9              ((APBADDR)(GPIO_base+0x1800))           /* GPIO Mode Control Register 9                  */
/*MT6238~*/ #define GPIO_MODEA              ((APBADDR)(GPIO_base+0x1900))           /* GPIO Mode Control Register A                  */
/*MT6238~*/ #define GPIO_MODEB              ((APBADDR)(GPIO_base+0x1A00))           /* GPIO Mode Control Register B                  */
/*MT6238~*/ #define CLK_OUT1                ((APBADDR)(GPIO_base+0x3000))           /* CLK_OUT1 Setting                              */
/*MT6238~*/ #define CLK_OUT2                ((APBADDR)(GPIO_base+0x3100))           /* CLK_OUT2 Setting                              */
/*MT6238~*/ #define CLK_OUT3                ((APBADDR)(GPIO_base+0x3200))           /* CLK_OUT3 Setting                              */
/*MT6238~*/ #define CLK_OUT4                ((APBADDR)(GPIO_base+0x3300))           /* CLK_OUT4 Setting                              */
/*MT6238~*/ #define CLK_OUT5                ((APBADDR)(GPIO_base+0x3400))           /* CLK_OUT5 Setting                              */
/*MT6238~*/ #define CLK_OUT6                ((APBADDR)(GPIO_base+0x3500))           /* CLK_OUT6 Setting                              */
/*MT6238~*/ #define CLK_OUT7                ((APBADDR)(GPIO_base+0x3600))           /* CLK_OUT7 Setting                              */
/*MT6238~*/ #define CLK_OUT8                ((APBADDR)(GPIO_base+0x3700))           /* CLK_OUT8 Setting                              */
/*MT6238~*/ #define GPIO_TM                 ((APBADDR)(GPIO_base+0x4000))           /* OE read-back selection                        */
/*MT6238~*/ /* --------------------------------------------------------------------------------------------------------------------- */
#endif

#endif
