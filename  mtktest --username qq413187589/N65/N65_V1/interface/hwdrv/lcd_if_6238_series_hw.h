/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001-2007
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
 * Filename:
 * ---------
 * lcd_if.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is to define LCD HW register in 6238 chips.
 *
 * Author:
 * -------
 * -------
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Log$
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
 * 
 *
 * removed!
 * removed!
 * 
 * 
 *
 *
 *
 *******************************************************************************/
#ifndef __LCD_IF_6238_SERIES_HW_H__
#define __LCD_IF_6238_SERIES_HW_H__

#include "kal_release.h"
#include "drv_features.h"


#if (defined(MT6238))
   #define LCD_PARALLEL1_CONFIG_REG    (LCD_base+0x001C)
   #define LCD_PARALLEL2_CONFIG_REG    (LCD_base+0x0020)
   #define LCD_PARALLEL_CTRL0_REG      (LCD_base+0x4000)
   #define LCD_PARALLEL_DATA0_REG      (LCD_base+0x4100)
   #define LCD_PARALLEL_CTRL1_REG      (LCD_base+0x5000)
   #define LCD_PARALLEL_DATA1_REG      (LCD_base+0x5100)
   #define LCD_PARALLEL_CTRL2_REG      (LCD_base+0x6000)
   #define LCD_PARALLEL_DATA2_REG      (LCD_base+0x6100)
   #define LCD_SERIAL_CTRL0_REG        (LCD_base+0x9000)
   #define LCD_SERIAL_DATA0_REG        (LCD_base+0x9100)
   #define LCD_SERIAL_CTRL1_REG        (LCD_base+0x8000)
   #define LCD_SERIAL_DATA1_REG        (LCD_base+0x8100)
   #define LCD_PARALLEL0_A0_LOW_ADDR   (LCD_base+0x4000)
   #define LCD_PARALLEL0_A0_HIGH_ADDR  (LCD_base+0x4100)
   #define LCD_PARALLEL1_A0_LOW_ADDR   (LCD_base+0x5000)
   #define LCD_PARALLEL1_A0_HIGH_ADDR  (LCD_base+0x5100)
   #define LCD_PARALLEL2_A0_LOW_ADDR   (LCD_base+0x6000)
   #define LCD_PARALLEL2_A0_HIGH_ADDR  (LCD_base+0x6100)
   #define LCD_SERIAL0_A0_LOW_ADDR     (LCD_base+0x9000)
   #define LCD_SERIAL0_A0_HIGH_ADDR    (LCD_base+0x9100)
   #define LCD_SERIAL1_A0_LOW_ADDR     (LCD_base+0x8000)
   #define LCD_SERIAL1_A0_HIGH_ADDR    (LCD_base+0x8100)
   
   #define LCD_STA_REG                 (LCD_base+0x0000)
   #define LCD_INT_ENABLE_REG          (LCD_base+0x0004)
   #define LCD_INT_STATUS_REG          (LCD_base+0x0008)
   #define LCD_START_REG               (LCD_base+0x000C)
   #define LCD_CTRL_REG                (LCD_base+0x0010)
   #define LCD_SERIAL_CONFIG_REG       (LCD_base+0x0014)
   #define LCD_PARALLEL_CONFIG_REG     (LCD_base+0x0018)   
   #define LCD_MAIN_WINDOW_SIZE_REG    (LCD_base+0x0040)
   #define LCD_ROI_WMEM_OFFSET_REG     (LCD_base+0x0044)
   #define LCD_ROI_WMEM_CTRL_REG       (LCD_base+0x0048)
   #define LCD_ROI_WMEM_ADDR_REG       (LCD_base+0x004C)                                    
   #define LCD_ROI_CTRL_REG            (LCD_base+0x0050)
   #define LCD_ROI_OFFSET_REG          (LCD_base+0x0054)
   #define LCD_ROI_CMD_ADDR_REG        (LCD_base+0x0058)
   #define LCD_ROI_DATA_ADDR_REG       (LCD_base+0x005C)
   #define LCD_ROI_SIZE_REG            (LCD_base+0x0060)                     
   #define LCD_ROI_HW_CTRL_REG         (LCD_base+0x0064)
   #define LCD_ROI_DC_CTRL_REG         (LCD_base+0x0068)
   #define LCD_ROI_BG_COLOR_REG        (LCD_base+0x006C) 
                                       
   #define LCD_LAYER0_BASE_ADDR        (LCD_base+0x0070)  
   #define LCD_LAYER0_CTRL_REG         (LCD_base+0x0070)
   #define LCD_LAYER0_SRC_KEY_REG      (LCD_base+0x0074)
   #define LCD_LAYER0_OFFSET_REG       (LCD_base+0x0078)
   #define LCD_LAYER0_BUFF_ADDR_REG    (LCD_base+0x007C)
   #define LCD_LAYER0_SIZE_REG         (LCD_base+0x0080)
   #define LCD_LAYER1_CTRL_REG         (LCD_base+0x0090)
   #define LCD_LAYER1_SRC_KEY_REG      (LCD_base+0x0094)
   #define LCD_LAYER1_OFFSET_REG       (LCD_base+0x0098)
   #define LCD_LAYER1_BUFF_ADDR_REG    (LCD_base+0x009C)
   #define LCD_LAYER1_SIZE_REG         (LCD_base+0x00A0)
   #define LCD_LAYER2_CTRL_REG         (LCD_base+0x00B0)
   #define LCD_LAYER2_SRC_KEY_REG      (LCD_base+0x00B4)
   #define LCD_LAYER2_OFFSET_REG       (LCD_base+0x00B8)
   #define LCD_LAYER2_BUFF_ADDR_REG    (LCD_base+0x00BC)
   #define LCD_LAYER2_SIZE_REG         (LCD_base+0x00C0)
   #define LCD_LAYER3_CTRL_REG         (LCD_base+0x00D0)
   #define LCD_LAYER3_SRC_KEY_REG      (LCD_base+0x00D4)
   #define LCD_LAYER3_OFFSET_REG       (LCD_base+0x00D8)
   #define LCD_LAYER3_BUFF_ADDR_REG    (LCD_base+0x00DC)
   #define LCD_LAYER3_SIZE_REG         (LCD_base+0x00E0)
   #define LCD_LAYER4_CTRL_REG         (LCD_base+0x00F0)
   #define LCD_LAYER4_SRC_KEY_REG      (LCD_base+0x00F4)
   #define LCD_LAYER4_OFFSET_REG       (LCD_base+0x00F8)
   #define LCD_LAYER4_BUFF_ADDR_REG    (LCD_base+0x00FC)
   #define LCD_LAYER4_SIZE_REG         (LCD_base+0x0100)
   #define LCD_LAYER5_CTRL_REG         (LCD_base+0x0110)
   #define LCD_LAYER5_SRC_KEY_REG      (LCD_base+0x0114)
   #define LCD_LAYER5_OFFSET_REG       (LCD_base+0x0118)
   #define LCD_LAYER5_BUFF_ADDR_REG    (LCD_base+0x011C)
   #define LCD_LAYER5_SIZE_REG         (LCD_base+0x0120)                        
   #define LCD_COLOR_PALETTE0_ADDR     (LCD_base+0xC400)
   #define LCD_CMD_PARAMETER_ADDR      (LCD_base+0xC800)
   #define LCD_CMD_PARAMETER2_ADDR     (LCD_base+0xC880)
   #define LCD_GAMMA_TABLE_ADDR        (LCD_base+0xC000)      
   
   #define REG_LCD_STA                 *((volatile unsigned short *) (LCD_base+0x0000))
   #define REG_LCD_INT_ENABLE          *((volatile unsigned short *) (LCD_base+0x0004))
   #define REG_LCD_INT_STATUS          *((volatile unsigned short *) (LCD_base+0x0008))
   #define REG_LCD_START               *((volatile unsigned short *) (LCD_base+0x000C))
   #define REG_LCD_CTRL                *((volatile unsigned short *) (LCD_base+0x0010))
   #define REG_LCD_SERIAL_CONFIG       *((volatile unsigned short *) (LCD_base+0x0014))
   #define REG_LCD_PARALLEL_CONFIG     *((volatile unsigned int *)   (LCD_base+0x0018))
                                       
   #define REG_LCD_PARALLEL1_CONFIG    *((volatile unsigned int *)   (LCD_base+0x001C))
   #define REG_LCD_PARALLEL2_CONFIG    *((volatile unsigned int *)   (LCD_base+0x0020))
   #define REG_LCD_PARALLEL_CTRL0      *((volatile unsigned short *) (LCD_base+0x4000))
   #define REG_LCD_PARALLEL_DATA0      *((volatile unsigned short *) (LCD_base+0x4100))
   #define REG_LCD_PARALLEL_CTRL1      *((volatile unsigned short *) (LCD_base+0x5000))
   #define REG_LCD_PARALLEL_DATA1      *((volatile unsigned short *) (LCD_base+0x5100))
   #define REG_LCD_PARALLEL_CTRL2      *((volatile unsigned short *) (LCD_base+0x6000))
   #define REG_LCD_PARALLEL_DATA2      *((volatile unsigned short *) (LCD_base+0x6100))
   #define REG_LCD_SERIAL_CTRL0        *((volatile unsigned short *) (LCD_base+0x9000))
   #define REG_LCD_SERIAL_DATA0        *((volatile unsigned short *) (LCD_base+0x9100))
   #define REG_LCD_SERIAL_CTRL1        *((volatile unsigned short *) (LCD_base+0x8000))
   #define REG_LCD_SERIAL_DATA1        *((volatile unsigned short *) (LCD_base+0x8100))
                                       
   #define REG_LCD_MAIN_WINDOW_SIZE    *((volatile unsigned int *)   (LCD_base+0x0040))
   #define REG_LCD_ROI_WMEM_OFFSET     *((volatile unsigned int *)   (LCD_base+0x0044))
   #define REG_LCD_ROI_WMEM_CTRL       *((volatile unsigned int *)   (LCD_base+0x0048))
   #define REG_LCD_ROI_WMEM_ADDR       *((volatile unsigned int *)   (LCD_base+0x004C))                                                                  
   #define REG_LCD_ROI_CTRL            *((volatile unsigned int *)   (LCD_base+0x0050))
   #define REG_LCD_ROI_OFFSET          *((volatile unsigned int *)   (LCD_base+0x0054))
   #define REG_LCD_ROI_CMD_ADDR        *((volatile unsigned int *)   (LCD_base+0x0058))
   #define REG_LCD_ROI_DATA_ADDR       *((volatile unsigned int *)   (LCD_base+0x005C))
   #define REG_LCD_ROI_SIZE            *((volatile unsigned int *)   (LCD_base+0x0060))
   #define REG_LCD_ROI_HW_CTRL         *((volatile unsigned int *)   (LCD_base+0x0064))            
   #define REG_LCD_ROI_DC_CTRL         *((volatile unsigned int *)   (LCD_base+0x0068))
   #define REG_LCD_ROI_BACKGROUND_COLOR   *((volatile unsigned int *)(LCD_base+0x006C))      
   #define REG_LCD_LAYER0_CTRL         *((volatile unsigned int *)   (LCD_base+0x0070))
   #define REG_LCD_LAYER0_SRC_KEY      *((volatile unsigned int *)   (LCD_base+0x0074))
   #define REG_LCD_LAYER0_OFFSET       *((volatile unsigned int *)   (LCD_base+0x0078))
   #define REG_LCD_LAYER0_BUFF_ADDR    *((volatile unsigned int *)   (LCD_base+0x007C))
   #define REG_LCD_LAYER0_SIZE         *((volatile unsigned int *)   (LCD_base+0x0080))
   #define REG_LCD_LAYER1_CTRL         *((volatile unsigned int *)   (LCD_base+0x0090))
   #define REG_LCD_LAYER1_SRC_KEY      *((volatile unsigned int *)   (LCD_base+0x0094))
   #define REG_LCD_LAYER1_OFFSET       *((volatile unsigned int *)   (LCD_base+0x0098))
   #define REG_LCD_LAYER1_BUFF_ADDR    *((volatile unsigned int *)   (LCD_base+0x009C))
   #define REG_LCD_LAYER1_SIZE         *((volatile unsigned int *)   (LCD_base+0x00A0))
   #define REG_LCD_LAYER2_CTRL         *((volatile unsigned int *)   (LCD_base+0x00B0))
   #define REG_LCD_LAYER2_SRC_KEY      *((volatile unsigned int *)   (LCD_base+0x00B4))
   #define REG_LCD_LAYER2_OFFSET       *((volatile unsigned int *)   (LCD_base+0x00B8))
   #define REG_LCD_LAYER2_BUFF_ADDR    *((volatile unsigned int *)   (LCD_base+0x00BC))
   #define REG_LCD_LAYER2_SIZE         *((volatile unsigned int *)   (LCD_base+0x00C0))
   #define REG_LCD_LAYER3_CTRL         *((volatile unsigned int *)   (LCD_base+0x00D0))
   #define REG_LCD_LAYER3_SRC_KEY      *((volatile unsigned int *)   (LCD_base+0x00D4))
   #define REG_LCD_LAYER3_OFFSET       *((volatile unsigned int *)   (LCD_base+0x00D8))
   #define REG_LCD_LAYER3_BUFF_ADDR    *((volatile unsigned int *)   (LCD_base+0x00DC))
   #define REG_LCD_LAYER3_SIZE         *((volatile unsigned int *)   (LCD_base+0x00E0))
   #define REG_LCD_LAYER4_CTRL         *((volatile unsigned int *)   (LCD_base+0x00F0))
   #define REG_LCD_LAYER4_SRC_KEY      *((volatile unsigned int *)   (LCD_base+0x00F4))
   #define REG_LCD_LAYER4_OFFSET       *((volatile unsigned int *)   (LCD_base+0x00F8))
   #define REG_LCD_LAYER4_BUFF_ADDR    *((volatile unsigned int *)   (LCD_base+0x00FC))
   #define REG_LCD_LAYER4_SIZE         *((volatile unsigned int *)   (LCD_base+0x0100))
   #define REG_LCD_LAYER5_CTRL         *((volatile unsigned int *)   (LCD_base+0x0110))
   #define REG_LCD_LAYER5_SRC_KEY      *((volatile unsigned int *)   (LCD_base+0x0114))
   #define REG_LCD_LAYER5_OFFSET       *((volatile unsigned int *)   (LCD_base+0x0118))
   #define REG_LCD_LAYER5_BUFF_ADDR    *((volatile unsigned int *)   (LCD_base+0x011C))
   #define REG_LCD_LAYER5_SIZE         *((volatile unsigned int *)   (LCD_base+0x0120))            

   /// bit mapping of LCD status register
   #define LCD_STATUS_RUN_BIT                         0x0001
   
   /// bit mapping of LCD interrupt enable register
   #define LCD_INT_ENABLE_COMPLETE_BIT                0x0001
   
   /// bit mapping of LCD interrupt status register
   #define LCD_INT_STATUS_COMPLETE_BIT                0x0001
   
   /// bit mapping of LCD transfer start register
   #define LCD_START_START_BIT                        0x8000
   
   /// bit mapping of LCD parallel or serial interface control register
   #define LCD_CTRL_RESET_BIT                         0x0001
         
   #define LCD_SERIAL_CONFIG_13MHZ_CLK                0x8000
   #define LCD_SERIAL_CONFIG_26MHZ_CLK                0x4000      
   #define LCD_SERIAL_CONFIG_CLK_MASK                 0xC000      
   #define LCD_SERIAL_CONFIG_CS1_POLARITY_BIT         0x0200
   #define LCD_SERIAL_CONFIG_CS0_POLARITY_BIT         0x0100
   #define LCD_SERIAL_CONFIG_9_BIT_MODE_BIT           0x0010
   #define LCD_SERIAL_CONFIG_CLOCK_DIVIDE_MASK        0x000C
   #define LCD_SERIAL_CONFIG_CLOCK_PHASE_BIT          0x0002
   #define LCD_SERIAL_CONFIG_CLOCK_POLARITY_BIT       0x0001
   
   /* bit mapping of LCD parallel config register */
   #define LCD_PARALLEL_CONFIG_CE2WR_SETUP_TIME_MASK  0xC0000000
   #define LCD_PARALLEL_CONFIG_CE2WR_HOLD_TIME_MASK   0x30000000
             
   #define LCD_PARALLEL_CLOCK_RATE_MASK               0x0000C000
   #define LCD_PARALLEL_CLOCK_26MHZ                   0x00008000
   #define LCD_PARALLEL_CLOCK_13MHZ                   0x00004000
      
   #define LCD_PARALLEL_CONFIG_WRITE_WAIT_STATE_MASK  0x00001F00
   #define LCD_PARALLEL_CONFIG_READ_LATENCY_TIME_MASK 0x0000001F
   
   /* bit mapping of LCD region of interest window control register */      
   #define LCD_ROI_CTRL_LAYER0_ENABLE_BIT             0x80000000
   #define LCD_ROI_CTRL_LAYER1_ENABLE_BIT             0x40000000
   #define LCD_ROI_CTRL_LAYER2_ENABLE_BIT             0x20000000
   #define LCD_ROI_CTRL_LAYER3_ENABLE_BIT             0x10000000
   #define LCD_ROI_CTRL_PERIOD_MASK                   0x03FF0000
   /* bit mapping of LCD region of interest and layer window offset register */
   #define LCD_WINDOW_OFFSET_Y_OFFSET_MASK            0x03FF0000
   #define LCD_WINDOW_OFFSET_X_OFFSET_MASK            0x000003FF
   
   /* bit mapping of LCD main, region of interest and layer window size register */
   #define LCD_WINDOW_SIZE_ROW_MASK                   0x03FF0000
   #define LCD_WINDOW_SIZE_COLUMN_MASK                0x000003FF
  
   
   #define LCD_LAYER_CTRL_ROTATE_MASK                 0x00003800               
   #define LCD_INT_ENABLE_DATA_COMPLETE_BIT           0x0002
   #define LCD_INT_ENABLE_CMD_COMPLETE_BIT            0x0004
   
   #define LCD_CMD_QUEUE_LENGTH                       32
   #define LCD_TOTAL_LAYER                            6
   #define LCD_MAX_OPACITY                            0xFF
   #define LCD_LAYER_ADDR_OFFSET                      0x0020      
         
   #define LCD_ROI_CTRL_LAYER_MASK                    0xFC000000   
   #define LCD_ROI_CTRL_LAYER4_ENABLE_BIT             0x08000000
   #define LCD_ROI_CTRL_LAYER5_ENABLE_BIT             0x04000000
   #define LCD_ROI_CTRL_CMD_ENABLE_BIT                0x00008000
   #define LCD_ROI_CTRL_W2MEM_BIT                     0x00004000
   #define LCD_LAYER_CTRL_DATA_SWAP_BIT               0x00010000
   #define LCD_LAYER_CTRL_SOURCE_AUTO_INC_BIT         0x00008000     /* source address auto increament */
   #define LCD_LAYER_CTRL_SOURCE_KEY_ENABLE_BIT       0x00004000
   #define LCD_LAYER_CTRL_COLOR_FORMAT_MASK           0x00000600
   #define LCD_LAYER_CTRL_OPACITY_ENABLE_BIT          0x00000100
   #define LCD_LAYER_CTRL_OPACITY_VALUE_MASK          0x000000FF
   #define LCD_ROI_CTRL_DATA_FORMAT_MASK              0x000000FF
   #define LCD_LAYER_SOURCE_COLOR_8BPP_INDEX          0
   #define LCD_LAYER_SOURCE_COLOR_RGB565              1
   #define LCD_LAYER_SOURCE_COLOR_ARGB8888            2
   #define LCD_LAYER_SOURCE_COLOR_RGB888              3
   #define LCD_LAYER_SOURCE_MONO                      4
   
   /* bit mapping of LCD interface cmd/parameter registers */
   #define LCD_CMD                                    0x00800000
   #define LCD_DATA                                   0x00000000
   /* bit mapping of LCM ROI write to Memory control register */            
   #define LCD_WMEM_RGB565                            0x0
   #define LCD_WMEM_RGB888                            0x1
   #define LCD_WMEM_ARGB8888                          0x2      
   #define LCD_ROI_WMEM_BUG_BIT                       0x0000
   #define LCD_ROI_WMEM_ALPHA_MASK                    0xff00
   #define LCD_ROI_WMEM_DC_OUT_ENABLE_BIT             0x0020
   #define LCD_ROI_WMEM_ADDRINC_DISABLE_BIT           0x0010
   #define LCD_ROI_WMEM_CONT_BIT                      0x0008
   #define LCD_ROI_WMEM_CTRL_FORMAT                   0x0006
   #define LCD_ROI_WMEM_CTRL_TO_LCM                   0x0001         
   #define LCD_LAYER_MASK                             0xFC000000
   #define LCD_DC_LAYER_MASK                          0xFC000000
   #define LCD_HW_TRIGGER_IDMA_MASK                   0x00030000	
   #define LCD_DC_COUPLE_IDMA_MASK                    0x0000FFFF
                                                      
   #define LCD_ROI_CTRL_CMDQ_SEL_BIT                  0x00002000
   #define LCD_ROI_CTRL_CMD_NUMBER_MASK               0x00001F00
   /*6228 not support gamma correction*/
   #define LCD_SERIAL_GAMMA_TABLE_SEL_MASK            0x3000         
   #define LCD_SERIAL_GAMMA_TABLE0                    0x0000
   #define LCD_SERIAL_GAMMA_TABLE1                    0x1000
   #define LCD_SERIAL_GAMMA_TABLE2                    0x2000
   #define LCD_SERIAL_GAMMA_DISABLE                   0x3000
   #define LCD_PARALLEL_GAMMA_TABLE_SEL_MASK          0x00FC0000
   #define LCD_PARALLEL_GAMMA_TABLE_R_MASK            0x00C00000
   #define LCD_PARALLEL_GAMMA_TABLE_G_MASK            0x00300000
   #define LCD_PARALLEL_GAMMA_TABLE_B_MASK            0x000C0000
                                                      
   #define LCD_PARALLEL_GAMMA_TABLE0                  0x00000000
   #define LCD_PARALLEL_GAMMA_TABLE1                  0x00100000
   #define LCD_PARALLEL_GAMMA_TABLE2                  0x00200000
   #define LCD_PARALLEL_GAMMA_DISABLE                 0x00300000      
   #define LCD_PARALLEL_CONFIG_CE2RD_SETUP_TIME_MASK  0x0F000000
   #define LCD_PARALLEL_BUS_WIDTH_MASK                0x00030000
   #define LCD_PARALLEL_BUS_WIDTH_8BIT                0x00000000
   #define LCD_PARALLEL_BUS_WIDTH_9BIT                0x00010000
   #define LCD_PARALLEL_BUS_WIDTH_16BIT               0x00020000
   #define LCD_PARALLEL_BUS_WIDTH_18BIT               0x00030000                                
               /// macros of LCD status register
   #define LCD_IS_RUNNING                           (REG_LCD_STA & LCD_STATUS_RUN_BIT)

   /// macros of LCD interrupt enable register
   #define ENABLE_LCD_TRANSFER_COMPLETE_INT         REG_LCD_INT_ENABLE |= LCD_INT_ENABLE_COMPLETE_BIT;
   #define DISABLE_LCD_TRANSFER_COMPLETE_INT        REG_LCD_INT_ENABLE &= ~LCD_INT_ENABLE_COMPLETE_BIT;

   /* macros of LCD start register */
   #define START_LCD_TRANSFER                       REG_LCD_START = 0;\
                                                    REG_LCD_START = LCD_START_START_BIT;
   #define STOP_LCD_TRANSFER                        REG_LCD_START = 0;

   /* macros of LCD control register */
   #define SET_LCD_CTRL_RESET_PIN                   REG_LCD_CTRL = LCD_CTRL_RESET_BIT;
   #define CLEAR_LCD_CTRL_RESET_PIN                 REG_LCD_CTRL = 0;
   
/*?????, start of serial interface control*/         
   /* macros of LCD serial config register */
   #define SET_LCD_SERIAL_CS1_POLARITY_HIGH         REG_LCD_SERIAL_CONFIG |= LCD_SERIAL_CONFIG_CS1_POLARITY_BIT;
   #define SET_LCD_SERIAL_CS1_POLARITY_LOW          REG_LCD_SERIAL_CONFIG &= ~LCD_SERIAL_CONFIG_CS1_POLARITY_BIT;
   #define SET_LCD_SERIAL_CS0_POLARITY_HIGH         REG_LCD_SERIAL_CONFIG |= LCD_SERIAL_CONFIG_CS0_POLARITY_BIT;
   #define SET_LCD_SERIAL_CS0_POLARITY_LOW          REG_LCD_SERIAL_CONFIG &= ~LCD_SERIAL_CONFIG_CS0_POLARITY_BIT;
   #define SET_LCD_SERIAL_9_BIT_MODE                REG_LCD_SERIAL_CONFIG |= LCD_SERIAL_CONFIG_9_BIT_MODE_BIT;
   #define SET_LCD_SERIAL_8_BIT_MODE                REG_LCD_SERIAL_CONFIG &= ~LCD_SERIAL_CONFIG_9_BIT_MODE_BIT;
   #define SET_LCD_SERIAL_DIVIDER(n)                REG_LCD_SERIAL_CONFIG &= ~LCD_SERIAL_CONFIG_CLOCK_DIVIDE_MASK;\
                                                    REG_LCD_SERIAL_CONFIG |= ((n-1)<<2);
   #define SET_LCD_SERIAL_CLOCK_PHASE_HIGH          REG_LCD_SERIAL_CONFIG |= LCD_SERIAL_CONFIG_CLOCK_PHASE_BIT;
   #define SET_LCD_SERIAL_CLOCK_PHASE_LOW           REG_LCD_SERIAL_CONFIG &= ~LCD_SERIAL_CONFIG_CLOCK_PHASE_BIT;
   #define SET_LCD_SERIAL_CLOCK_POLARITY_HIGH       REG_LCD_SERIAL_CONFIG |= LCD_SERIAL_CONFIG_CLOCK_POLARITY_BIT;
   #define SET_LCD_SERIAL_CLOCK_POLARITY_LOW        REG_LCD_SERIAL_CONFIG &= ~LCD_SERIAL_CONFIG_CLOCK_POLARITY_BIT;   
   #define SET_LCD_SERIAL_CLOCK_52M                 REG_LCD_SERIAL_CONFIG &= ~LCD_SERIAL_CONFIG_CLK_MASK;
   #define SET_LCD_SERIAL_CLOCK_26M                 REG_LCD_SERIAL_CONFIG &= ~LCD_SERIAL_CONFIG_CLK_MASK;\
                                                    REG_LCD_SERIAL_CONFIG |= LCD_SERIAL_CONFIG_26MHZ_CLK;
   #define SET_LCD_SERIAL_CLOCK_13M                 REG_LCD_SERIAL_CONFIG &= ~LCD_SERIAL_CONFIG_CLK_MASK;\
                                                    REG_LCD_SERIAL_CONFIG |= LCD_SERIAL_CONFIG_13MHZ_CLK;   
/*?????, end of serial interface control*/                                                         
   
    /* macros of LCD main window size register */
   #define SET_LCD_MAIN_WINDOW_SIZE(column,row)     REG_LCD_MAIN_WINDOW_SIZE = ((row<<16)|column);
 /*?????, start of parallel interface control*/      
   /* macros of LCD parallel config register */
   
   #define SET_LCD_PARALLEL_CLOCK_52M               REG_LCD_PARALLEL_CONFIG &= ~LCD_PARALLEL_CLOCK_RATE_MASK;
   #define SET_LCD_PARALLEL_CLOCK_26M               REG_LCD_PARALLEL_CONFIG &= ~LCD_PARALLEL_CLOCK_RATE_MASK;\
                                                    REG_LCD_PARALLEL_CONFIG |= LCD_PARALLEL_CLOCK_26MHZ;
   #define SET_LCD_PARALLEL_CLOCK_13M               REG_LCD_PARALLEL_CONFIG &= ~LCD_PARALLEL_CLOCK_RATE_MASK;\
                                                    REG_LCD_PARALLEL_CONFIG |= LCD_PARALLEL_CLOCK_13MHZ;
   #define SET_LCD_PARALLEL1_CLOCK_52M              REG_LCD_PARALLEL1_CONFIG &= ~LCD_PARALLEL_CLOCK_RATE_MASK;
   #define SET_LCD_PARALLEL1_CLOCK_26M              REG_LCD_PARALLEL1_CONFIG &= ~LCD_PARALLEL_CLOCK_RATE_MASK;\
                                                    REG_LCD_PARALLEL1_CONFIG |= LCD_PARALLEL_CLOCK_26MHZ;
   #define SET_LCD_PARALLEL1_CLOCK_13M              REG_LCD_PARALLEL1_CONFIG &= ~LCD_PARALLEL_CLOCK_RATE_MASK;\
                                                    REG_LCD_PARALLEL1_CONFIG |= LCD_PARALLEL_CLOCK_13MHZ;                                                   
   #define SET_LCD_PARALLEL2_CLOCK_52M              REG_LCD_PARALLEL2_CONFIG &= ~LCD_PARALLEL_CLOCK_RATE_MASK;
   #define SET_LCD_PARALLEL2_CLOCK_26M              REG_LCD_PARALLEL2_CONFIG &= ~LCD_PARALLEL_CLOCK_RATE_MASK;\
                                                    REG_LCD_PARALLEL2_CONFIG |= LCD_PARALLEL_CLOCK_26MHZ;
   #define SET_LCD_PARALLEL2_CLOCK_13M              REG_LCD_PARALLEL2_CONFIG &= ~LCD_PARALLEL_CLOCK_RATE_MASK;\
                                                    REG_LCD_PARALLEL2_CONFIG |= LCD_PARALLEL_CLOCK_13MHZ;                                                      
                                                   
   #define SET_LCD_PARALLEL_CE2WR_SETUP_TIME(n)     REG_LCD_PARALLEL_CONFIG &= ~LCD_PARALLEL_CONFIG_CE2WR_SETUP_TIME_MASK;\
                                                    REG_LCD_PARALLEL_CONFIG |= (n<<30);
   #define GET_LCD_PARALLEL_CE2WR_SETUP_TIME        ((REG_LCD_PARALLEL_CONFIG & LCD_PARALLEL_CONFIG_CE2WR_SETUP_TIME_MASK)>>30);
   #define SET_LCD_PARALLEL_CE2WR_HOLD_TIME(n)      REG_LCD_PARALLEL_CONFIG &= ~LCD_PARALLEL_CONFIG_CE2WR_HOLD_TIME_MASK;\
                                                    REG_LCD_PARALLEL_CONFIG |= (n<<28);                                                                                                                     
   #define SET_LCD_PARALLEL_WRITE_WAIT_STATE(n)     REG_LCD_PARALLEL_CONFIG &= ~LCD_PARALLEL_CONFIG_WRITE_WAIT_STATE_MASK;\
                                                    REG_LCD_PARALLEL_CONFIG |= (n<<8);
   #define GET_LCD_PARALLEL_WRITE_WAIT_STATE        ((REG_LCD_PARALLEL_CONFIG & LCD_PARALLEL_CONFIG_WRITE_WAIT_STATE_MASK)>>8);
   #define SET_LCD_PARALLEL_READ_LATENCY_TIME(n)    REG_LCD_PARALLEL_CONFIG &= ~LCD_PARALLEL_CONFIG_READ_LATENCY_TIME_MASK;\
                                                    REG_LCD_PARALLEL_CONFIG |= n;
   #define GET_LCD_PARALLEL_READ_LATENCY_TIME       (REG_LCD_PARALLEL_CONFIG & LCD_PARALLEL_CONFIG_READ_LATENCY_TIME_MASK);
                                                    
   #define SET_LCD_PARALLEL1_CE2WR_SETUP_TIME(n)    REG_LCD_PARALLEL1_CONFIG &= ~LCD_PARALLEL_CONFIG_CE2WR_SETUP_TIME_MASK;\
                                                    REG_LCD_PARALLEL1_CONFIG |= (n<<30);
   #define SET_LCD_PARALLEL1_CE2WR_HOLD_TIME(n)     REG_LCD_PARALLEL1_CONFIG &= ~LCD_PARALLEL_CONFIG_CE2WR_HOLD_TIME_MASK;\
                                                    REG_LCD_PARALLEL1_CONFIG |= (n<<28);
   #define SET_LCD_PARALLEL1_WRITE_WAIT_STATE(n)    REG_LCD_PARALLEL1_CONFIG &= ~LCD_PARALLEL_CONFIG_WRITE_WAIT_STATE_MASK;\
                                                    REG_LCD_PARALLEL1_CONFIG |= (n<<8);
   #define SET_LCD_PARALLEL1_READ_LATENCY_TIME(n)   REG_LCD_PARALLEL1_CONFIG &= ~LCD_PARALLEL_CONFIG_READ_LATENCY_TIME_MASK;\
                                                    REG_LCD_PARALLEL1_CONFIG |= n;
                                                    
   #define SET_LCD_PARALLEL2_CE2WR_SETUP_TIME(n)    REG_LCD_PARALLEL2_CONFIG &= ~LCD_PARALLEL_CONFIG_CE2WR_SETUP_TIME_MASK;\
                                                    REG_LCD_PARALLEL2_CONFIG |= (n<<30);
   #define SET_LCD_PARALLEL2_CE2WR_HOLD_TIME(n)     REG_LCD_PARALLEL2_CONFIG &= ~LCD_PARALLEL_CONFIG_CE2WR_HOLD_TIME_MASK;\
                                                    REG_LCD_PARALLEL2_CONFIG |= (n<<28);
   #define SET_LCD_PARALLEL2_WRITE_WAIT_STATE(n)    REG_LCD_PARALLEL2_CONFIG &= ~LCD_PARALLEL_CONFIG_WRITE_WAIT_STATE_MASK;\
                                                    REG_LCD_PARALLEL2_CONFIG |= (n<<8);
   #define SET_LCD_PARALLEL2_READ_LATENCY_TIME(n)   REG_LCD_PARALLEL2_CONFIG &= ~LCD_PARALLEL_CONFIG_READ_LATENCY_TIME_MASK;\
                                                    REG_LCD_PARALLEL2_CONFIG |= n;                                                                                                         
      
   #define SET_LCD_PARALLEL_CE2RD_SETUP_TIME(n)     REG_LCD_PARALLEL_CONFIG &= ~LCD_PARALLEL_CONFIG_CE2RD_SETUP_TIME_MASK;\
                                                    REG_LCD_PARALLEL_CONFIG |= (n<<24);
   #define SET_LCD_PARALLEL1_CE2RD_SETUP_TIME(n)    REG_LCD_PARALLEL1_CONFIG &= ~LCD_PARALLEL_CONFIG_CE2RD_SETUP_TIME_MASK;\
                                                    REG_LCD_PARALLEL1_CONFIG |= (n<<24);                                                                    
   #define SET_LCD_PARALLEL2_CE2RD_SETUP_TIME(n)    REG_LCD_PARALLEL_CONFIG &= ~LCD_PARALLEL_CONFIG_CE2RD_SETUP_TIME_MASK;\
                                                    REG_LCD_PARALLEL2_CONFIG |= (n<<24);                                                                                                                                                                                                               
   
   #define SET_LCD_PARALLEL_8BIT_DATA_BUS           REG_LCD_PARALLEL_CONFIG &= ~LCD_PARALLEL_BUS_WIDTH_MASK;
   #define SET_LCD_PARALLEL_9BIT_DATA_BUS           REG_LCD_PARALLEL_CONFIG &= ~LCD_PARALLEL_BUS_WIDTH_MASK;\
                                                    REG_LCD_PARALLEL_CONFIG |= LCD_PARALLEL_BUS_WIDTH_9BIT;
   #define SET_LCD_PARALLEL_16BIT_DATA_BUS          REG_LCD_PARALLEL_CONFIG &= ~LCD_PARALLEL_BUS_WIDTH_MASK;\
                                                    REG_LCD_PARALLEL_CONFIG |= LCD_PARALLEL_BUS_WIDTH_16BIT;
   #define SET_LCD_PARALLEL_18BIT_DATA_BUS          REG_LCD_PARALLEL_CONFIG &= ~LCD_PARALLEL_BUS_WIDTH_MASK;\
                                                    REG_LCD_PARALLEL_CONFIG |= LCD_PARALLEL_BUS_WIDTH_18BIT;
   #define SET_LCD_PARALLEL1_8BIT_DATA_BUS          REG_LCD_PARALLEL1_CONFIG &= ~LCD_PARALLEL_BUS_WIDTH_MASK;
   #define SET_LCD_PARALLEL1_9BIT_DATA_BUS          REG_LCD_PARALLEL1_CONFIG &= ~LCD_PARALLEL_BUS_WIDTH_MASK;\
                                                    REG_LCD_PARALLEL1_CONFIG |= LCD_PARALLEL_BUS_WIDTH_9BIT;
   #define SET_LCD_PARALLEL1_16BIT_DATA_BUS         REG_LCD_PARALLEL1_CONFIG &= ~LCD_PARALLEL_BUS_WIDTH_MASK;\
                                                    REG_LCD_PARALLEL1_CONFIG |= LCD_PARALLEL_BUS_WIDTH_16BIT;
   #define SET_LCD_PARALLEL1_18BIT_DATA_BUS         REG_LCD_PARALLEL1_CONFIG &= ~LCD_PARALLEL_BUS_WIDTH_MASK;\
                                                    REG_LCD_PARALLEL1_CONFIG |= LCD_PARALLEL_BUS_WIDTH_18BIT;
   #define SET_LCD_PARALLEL2_8BIT_DATA_BUS          REG_LCD_PARALLEL2_CONFIG &= ~LCD_PARALLEL_BUS_WIDTH_MASK;
   #define SET_LCD_PARALLEL2_9BIT_DATA_BUS          REG_LCD_PARALLEL2_CONFIG &= ~LCD_PARALLEL_BUS_WIDTH_MASK;\
                                                    REG_LCD_PARALLEL2_CONFIG |= LCD_PARALLEL_BUS_WIDTH_9BIT;
   #define SET_LCD_PARALLEL2_16BIT_DATA_BUS         REG_LCD_PARALLEL2_CONFIG &= ~LCD_PARALLEL_BUS_WIDTH_MASK;\
                                                    REG_LCD_PARALLEL2_CONFIG |= LCD_PARALLEL_BUS_WIDTH_16BIT;
   #define SET_LCD_PARALLEL2_18BIT_DATA_BUS         REG_LCD_PARALLEL2_CONFIG &= ~LCD_PARALLEL_BUS_WIDTH_MASK;\
                                                    REG_LCD_PARALLEL2_CONFIG |= LCD_PARALLEL_BUS_WIDTH_18BIT;
   /* macros of LCD ROI write to memory control register */
   #define LCD_WRITE_MEM_AND_LCM                    REG_LCD_ROI_WMEM_CTRL |= LCD_ROI_WMEM_CTRL_TO_LCM;
   #define LCD_WRITE_MEM_ONLY                       REG_LCD_ROI_WMEM_CTRL &= ~LCD_ROI_WMEM_CTRL_TO_LCM;
   #define SET_LCD_ROI_CTRL_W2MEM_DISCONT           REG_LCD_ROI_WMEM_CTRL |= LCD_ROI_WMEM_CONT_BIT;
   #define SET_LCD_ROI_CTRL_W2MEM_CONT              REG_LCD_ROI_WMEM_CTRL &= ~LCD_ROI_WMEM_CONT_BIT;
   /*to cover HW bug in 6227 series*/               
   #define FIX_LCD_ROI_CTRL_W2MEM_BUG               REG_LCD_ROI_CTRL &= ~LCD_ROI_WMEM_BUG_BIT;
   #define LCD_ROI_W2MEM_IS_CONT_MODE               (!(REG_LCD_ROI_WMEM_CTRL & LCD_ROI_WMEM_CONT_BIT))
   #define SET_LCD_ROI_CTRL_NUMBER_OF_CMD(n)        REG_LCD_ROI_CTRL &= ~LCD_ROI_CTRL_CMD_NUMBER_MASK;\
                                                    REG_LCD_ROI_CTRL |= ((n-1)<<8);
   /* macros of LCD write to memory offset register */   
   #define SET_LCD_ROI_WMEM_OFFSET(x,y)             REG_LCD_ROI_WMEM_OFFSET = ((y<<16)|x);                                                               
   #define SET_LCD_CMD_QUEUE1                       REG_LCD_ROI_CTRL &= ~LCD_ROI_CTRL_CMDQ_SEL_BIT;
   #define SET_LCD_CMD_QUEUE2                       REG_LCD_ROI_CTRL |= LCD_ROI_CTRL_CMDQ_SEL_BIT;
   /*gamma*/
   #define SET_GAMMA_TABLE(gamma_table_id,gamma_index,gamma_value)   \
   {\
      *((volatile unsigned int *) (LCD_GAMMA_TABLE_ADDR+(gamma_index<<2))) &= ~(0xFF<<(gamma_table_id<<3));\
      *((volatile unsigned int *) (LCD_GAMMA_TABLE_ADDR+(gamma_index<<2)))|=((gamma_value&0xFF)<<(gamma_table_id<<3));\
   }
   #define SET_LCD_SERIAL_GAMMA_TABLE(n)            REG_LCD_SERIAL_CONFIG &= ~LCD_SERIAL_GAMMA_TABLE_SEL_MASK;\
                                                    REG_LCD_SERIAL_CONFIG |= n;
   #define SET_LCD_PARALLEL_GAMMA_R_TABLE(n)        REG_LCD_PARALLEL_CONFIG &= ~LCD_PARALLEL_GAMMA_TABLE_R_MASK;\
                                                    REG_LCD_PARALLEL_CONFIG |= (n<<2);
   #define SET_LCD_PARALLEL_GAMMA_G_TABLE(n)        REG_LCD_PARALLEL_CONFIG &= ~LCD_PARALLEL_GAMMA_TABLE_G_MASK;\
                                                    REG_LCD_PARALLEL_CONFIG |= n;
   #define SET_LCD_PARALLEL_GAMMA_B_TABLE(n)        REG_LCD_PARALLEL_CONFIG &= ~LCD_PARALLEL_GAMMA_TABLE_B_MASK;\
                                                    REG_LCD_PARALLEL_CONFIG |= (n>>2);
   #define SET_LCD_PARALLEL1_GAMMA_TABLE(n)         REG_LCD_PARALLEL1_CONFIG &= ~LCD_PARALLEL_GAMMA_TABLE_SEL_MASK;\
                                                    REG_LCD_PARALLEL1_CONFIG |= n;
   #define SET_LCD_PARALLEL2_GAMMA_TABLE(n)         REG_LCD_PARALLEL2_CONFIG &= ~LCD_PARALLEL_GAMMA_TABLE_SEL_MASK;\
                                                    REG_LCD_PARALLEL_CONFIG |= n;                                                    
                                                    
                                                    
   #define LCD_WRITE_MEM_RGB565                     REG_LCD_ROI_WMEM_CTRL &= ~LCD_ROI_WMEM_CTRL_FORMAT;\
                                                    REG_LCD_ROI_WMEM_CTRL |= LCD_WMEM_RGB565;
   #define LCD_WRITE_MEM_RGB888                     REG_LCD_ROI_WMEM_CTRL &= ~LCD_ROI_WMEM_CTRL_FORMAT;\
                                                    REG_LCD_ROI_WMEM_CTRL |= LCD_WMEM_RGB888;
   #define LCD_WRITE_MEM_ARGB8888                   REG_LCD_ROI_WMEM_CTRL &= ~LCD_ROI_WMEM_CTRL_FORMAT;\
                                                    REG_LCD_ROI_WMEM_CTRL |= LCD_WMEM_ARGB8888;         
   #define SET_LCD_ENABLE_LAYER(n)                  REG_LCD_ROI_CTRL &= ~LCD_ROI_CTRL_LAYER_MASK;\
                                                       REG_LCD_ROI_CTRL |= n;
   #define SET_LCD_DISABLE_LAYER(n)                 REG_LCD_ROI_CTRL &= ~n;
                                                    
   #define SET_LCD_ROI_CTRL_CMD_LATENCY(n)          REG_LCD_ROI_CTRL &= ~LCD_ROI_CTRL_PERIOD_MASK;\
                                                    REG_LCD_ROI_CTRL |= (n<<16);\
                                                    if (n < 16) \
                                                       lcd_cmd_period_count=n;
   #define ENABLE_LCD_ROI_CTRL_CMD_FIRST            REG_LCD_ROI_CTRL |= LCD_ROI_CTRL_CMD_ENABLE_BIT;
   #define DISABLE_LCD_ROI_CTRL_CMD_FIRST           REG_LCD_ROI_CTRL &= ~LCD_ROI_CTRL_CMD_ENABLE_BIT;
   #define ENABLE_LCD_ROI_CTRL_W2MEM                REG_LCD_ROI_CTRL |= LCD_ROI_CTRL_W2MEM_BIT;
   #define DISABLE_LCD_ROI_CTRL_W2MEM               REG_LCD_ROI_CTRL &= ~LCD_ROI_CTRL_W2MEM_BIT;      
   #define SET_LCD_ROI_CTRL_OUTPUT_FORMAT(n)        REG_LCD_ROI_CTRL &= ~LCD_ROI_CTRL_DATA_FORMAT_MASK;\
                                                    REG_LCD_ROI_CTRL |= n;
   #define GET_LCD_ROI_CTRL_OUTPUT_FORMAT           (REG_LCD_ROI_CTRL & LCD_ROI_CTRL_DATA_FORMAT_MASK)
   
   /* macros of LCD region of interest window offset register */
   #define SET_LCD_ROI_WINDOW_OFFSET(x,y)           REG_LCD_ROI_OFFSET = ((y<<16) | x);
   #define GET_LCD_ROI_WINDOW_OFFSET_X              (kal_uint16) (REG_LCD_ROI_OFFSET & 0xFFFF)
   #define GET_LCD_ROI_WINDOW_OFFSET_Y              (kal_uint16) ((REG_LCD_ROI_OFFSET>>16) & 0xFFFF)   
   /* macros of LCD region of interest window size register */
   #define SET_LCD_ROI_WINDOW_SIZE(column,row)      REG_LCD_ROI_SIZE = ((row<<16) | column);
   #define GET_LCD_ROI_WINDOW_SIZE_X                (kal_uint16) (REG_LCD_ROI_SIZE & 0xFFFF)
   #define GET_LCD_ROI_WINDOW_SIZE_Y                (kal_uint16) ((REG_LCD_ROI_SIZE>>16) & 0xFFFF)
   
   
   /*macros of LCD region of interest window control register */
   #define ENABLE_ALL_LCD_LAYER_WINDOW              REG_LCD_ROI_CTRL |= LCD_ROI_CTRL_LAYER_MASK;
   #define DISABLE_ALL_LCD_LAYER_WINDOW             REG_LCD_ROI_CTRL &= ~LCD_ROI_CTRL_LAYER_MASK;
   /*the following macro are for lcd layer control*/
                                               
   #define ENABLE_LCD_LAYER0_SOURCE_KEY             REG_LCD_LAYER0_CTRL |= LCD_LAYER_CTRL_SOURCE_KEY_ENABLE_BIT;
   #define DISABLE_LCD_LAYER0_SOURCE_KEY            REG_LCD_LAYER0_CTRL &= ~LCD_LAYER_CTRL_SOURCE_KEY_ENABLE_BIT;   
   #define ENABLE_LAYER0_ADDR_AUTO_INC              REG_LCD_LAYER0_CTRL = ~LCD_LAYER_CTRL_SOURCE_AUTO_INC_BIT;
   #define DISABLE_LAYER0_ADDR_AUTO_INC             REG_LCD_LAYER0_CTRL |= LCD_LAYER_CTRL_SOURCE_AUTO_INC_BIT;
   #define ENABLE_LAYER0_READ_DATA_SWAP             REG_LCD_LAYER0_CTRL |= LCD_LAYER_CTRL_DATA_SWAP_BIT;
   #define DISABLE_LAYER0_READ_DATA_SWAP            REG_LCD_LAYER0_CTRL &= ~LCD_LAYER_CTRL_DATA_SWAP_BIT;   
   #define ENABLE_LCD_LAYER0_OPACITY                REG_LCD_LAYER0_CTRL |= LCD_LAYER_CTRL_OPACITY_ENABLE_BIT;
   #define DISABLE_LCD_LAYER0_OPACITY               REG_LCD_LAYER0_CTRL &= ~LCD_LAYER_CTRL_OPACITY_ENABLE_BIT;
                                                    
   #define GET_LCD_LAYER0_ROTATE                    (kal_uint8) ((REG_LCD_LAYER0_CTRL & LCD_LAYER_CTRL_ROTATE_MASK)>>11);
   #define SET_LCD_LAYER0_ROTATE(n)                 REG_LCD_LAYER0_CTRL &=~LCD_LAYER_CTRL_ROTATE_MASK;\
                                                    REG_LCD_LAYER0_CTRL |= (n<<11);   
   /* macros of LCD layer0 offset register */       
   #define SET_LCD_LAYER0_WINDOW_OFFSET(x,y)        REG_LCD_LAYER0_OFFSET = ((y<<16) | x);
   
   /* macros of LCD layer0 window size register */
   #define SET_LCD_LAYER0_WINDOW_SIZE(column,row)   REG_LCD_LAYER0_SIZE = ((row<<16) | column);
   #define GET_LCD_LAYER0_WINDOW_WIDTH              (kal_uint16) (REG_LCD_LAYER0_SIZE & 0xFFFF);
   #define GET_LCD_LAYER0_WINDOW_HEIGHT             (kal_uint16) ((REG_LCD_LAYER0_SIZE>>16) & 0xFFFF);
   
   /* macros of LCD layer1 window control register */
   #define ENABLE_LCD_LAYER1_SOURCE_KEY             REG_LCD_LAYER1_CTRL |= LCD_LAYER_CTRL_SOURCE_KEY_ENABLE_BIT;
   #define DISABLE_LCD_LAYER1_SOURCE_KEY            REG_LCD_LAYER1_CTRL &= ~LCD_LAYER_CTRL_SOURCE_KEY_ENABLE_BIT;   
   #define ENABLE_LAYER1_READ_DATA_SWAP             REG_LCD_LAYER1_CTRL |= LCD_LAYER_CTRL_DATA_SWAP_BIT;
   #define DISABLE_LAYER1_READ_DATA_SWAP            REG_LCD_LAYER1_CTRL &= ~LCD_LAYER_CTRL_DATA_SWAP_BIT;
   #define ENABLE_LAYER1_ADDR_AUTO_INC              REG_LCD_LAYER1_CTRL &= ~LCD_LAYER_CTRL_SOURCE_AUTO_INC_BIT;
   #define DISABLE_LAYER1_ADDR_AUTO_INC             REG_LCD_LAYER1_CTRL |= LCD_LAYER_CTRL_SOURCE_AUTO_INC_BIT;      
   #define ENABLE_LCD_LAYER1_OPACITY                REG_LCD_LAYER1_CTRL |= LCD_LAYER_CTRL_OPACITY_ENABLE_BIT;
   #define DISABLE_LCD_LAYER1_OPACITY               REG_LCD_LAYER1_CTRL &= ~LCD_LAYER_CTRL_OPACITY_ENABLE_BIT;
                                                    
   #define GET_LCD_LAYER1_ROTATE                    (kal_uint8) ((REG_LCD_LAYER1_CTRL & LCD_LAYER_CTRL_ROTATE_MASK)>>11);
   #define SET_LCD_LAYER1_ROTATE(n)                 REG_LCD_LAYER1_CTRL &=~LCD_LAYER_CTRL_ROTATE_MASK;\
                                                    REG_LCD_LAYER1_CTRL |= (n<<11);   
   
   /* macros of LCD layer1 offset register */
   #define SET_LCD_LAYER1_WINDOW_OFFSET(x,y)        REG_LCD_LAYER1_OFFSET = ((y<<16) | x);
   
   /* macros of LCD layer1 window size register */
   #define SET_LCD_LAYER1_WINDOW_SIZE(column,row)   REG_LCD_LAYER1_SIZE = ((row<<16) | column);
   #define GET_LCD_LAYER1_WINDOW_WIDTH              (kal_uint16) (REG_LCD_LAYER1_SIZE & 0xFFFF);
   #define GET_LCD_LAYER1_WINDOW_HEIGHT             (kal_uint16) ((REG_LCD_LAYER1_SIZE>>16) & 0xFFFF);
   
   /* macros of LCD layer2 window control register */
   #define ENABLE_LCD_LAYER2_SOURCE_KEY             REG_LCD_LAYER2_CTRL |= LCD_LAYER_CTRL_SOURCE_KEY_ENABLE_BIT;
   #define DISABLE_LCD_LAYER2_SOURCE_KEY            REG_LCD_LAYER2_CTRL &= ~LCD_LAYER_CTRL_SOURCE_KEY_ENABLE_BIT;   
   #define ENABLE_LAYER2_READ_DATA_SWAP             REG_LCD_LAYER2_CTRL |= LCD_LAYER_CTRL_DATA_SWAP_BIT;
   #define DISABLE_LAYER2_READ_DATA_SWAP            REG_LCD_LAYER2_CTRL &= ~LCD_LAYER_CTRL_DATA_SWAP_BIT;
   #define ENABLE_LAYER2_ADDR_AUTO_INC              REG_LCD_LAYER2_CTRL &= ~LCD_LAYER_CTRL_SOURCE_AUTO_INC_BIT;
   #define DISABLE_LAYER2_ADDR_AUTO_INC             REG_LCD_LAYER2_CTRL |= LCD_LAYER_CTRL_SOURCE_AUTO_INC_BIT;      
   #define ENABLE_LCD_LAYER2_OPACITY                REG_LCD_LAYER2_CTRL |= LCD_LAYER_CTRL_OPACITY_ENABLE_BIT;
   #define DISABLE_LCD_LAYER2_OPACITY               REG_LCD_LAYER2_CTRL &= ~LCD_LAYER_CTRL_OPACITY_ENABLE_BIT;   
   #define GET_LCD_LAYER2_ROTATE                    (kal_uint8) ((REG_LCD_LAYER2_CTRL & LCD_LAYER_CTRL_ROTATE_MASK)>>11);
   #define SET_LCD_LAYER2_ROTATE(n)                 REG_LCD_LAYER2_CTRL &=~LCD_LAYER_CTRL_ROTATE_MASK;\
                                                    REG_LCD_LAYER2_CTRL |= (n<<11);
   
   /* macros of LCD layer2 offset register */
   #define SET_LCD_LAYER2_WINDOW_OFFSET(x,y)        REG_LCD_LAYER2_OFFSET = ((y<<16) | x);
   
   /* macros of LCD layer2 window size register */
   #define SET_LCD_LAYER2_WINDOW_SIZE(column,row)   REG_LCD_LAYER2_SIZE = ((row<<16) | column);
   #define GET_LCD_LAYER2_WINDOW_WIDTH              (kal_uint16) (REG_LCD_LAYER2_SIZE & 0xFFFF);
   #define GET_LCD_LAYER2_WINDOW_HEIGHT             (kal_uint16) ((REG_LCD_LAYER2_SIZE>>16) & 0xFFFF);
   
   /* macros of LCD layer3 window control register */
   #define ENABLE_LCD_LAYER3_SOURCE_KEY             REG_LCD_LAYER3_CTRL |= LCD_LAYER_CTRL_SOURCE_KEY_ENABLE_BIT;
   #define DISABLE_LCD_LAYER3_SOURCE_KEY            REG_LCD_LAYER3_CTRL &= ~LCD_LAYER_CTRL_SOURCE_KEY_ENABLE_BIT;   
   #define ENABLE_LAYER3_READ_DATA_SWAP             REG_LCD_LAYER3_CTRL |= LCD_LAYER_CTRL_DATA_SWAP_BIT;
   #define DISABLE_LAYER3_READ_DATA_SWAP            REG_LCD_LAYER3_CTRL &= ~LCD_LAYER_CTRL_DATA_SWAP_BIT;
   #define ENABLE_LAYER3_ADDR_AUTO_INC              REG_LCD_LAYER3_CTRL &= ~LCD_LAYER_CTRL_SOURCE_AUTO_INC_BIT;
   #define DISABLE_LAYER3_ADDR_AUTO_INC             REG_LCD_LAYER3_CTRL |= LCD_LAYER_CTRL_SOURCE_AUTO_INC_BIT;   
      
   #define ENABLE_LCD_LAYER3_OPACITY                REG_LCD_LAYER3_CTRL |= LCD_LAYER_CTRL_OPACITY_ENABLE_BIT;
   #define DISABLE_LCD_LAYER3_OPACITY               REG_LCD_LAYER3_CTRL &= ~LCD_LAYER_CTRL_OPACITY_ENABLE_BIT;   
   #define GET_LCD_LAYER3_ROTATE                    (kal_uint8) ((REG_LCD_LAYER3_CTRL & LCD_LAYER_CTRL_ROTATE_MASK)>>11);
   #define SET_LCD_LAYER3_ROTATE(n)                 REG_LCD_LAYER3_CTRL &=~LCD_LAYER_CTRL_ROTATE_MASK;\
                                                    REG_LCD_LAYER3_CTRL |= (n<<11);   
   
   /* macros of LCD layer3 offset register */
   #define SET_LCD_LAYER3_WINDOW_OFFSET(x,y)        REG_LCD_LAYER3_OFFSET = ((y<<16) | x);
                                                      
   /* macros of LCD layer3 window size register */    
   #define SET_LCD_LAYER3_WINDOW_SIZE(column,row)   REG_LCD_LAYER3_SIZE = ((row<<16) | column);
   #define GET_LCD_LAYER3_WINDOW_WIDTH              (kal_uint16) (REG_LCD_LAYER3_SIZE & 0xFFFF);
   #define GET_LCD_LAYER3_WINDOW_HEIGHT             (kal_uint16) ((REG_LCD_LAYER3_SIZE>>16) & 0xFFFF);
   #define SET_LCD_LAYER0_SOURCE_KEY(color)         REG_LCD_LAYER0_SRC_KEY = color;
   #define SET_LCD_LAYER0_8BPP_INDEX_MODE           REG_LCD_LAYER0_CTRL &= ~LCD_LAYER_CTRL_COLOR_FORMAT_MASK;
   #define SET_LCD_LAYER0_RGB565_MODE               REG_LCD_LAYER0_CTRL &= ~LCD_LAYER_CTRL_COLOR_FORMAT_MASK;\
                                                    REG_LCD_LAYER0_CTRL |=(LCD_LAYER_SOURCE_COLOR_RGB565<<9);
   #define SET_LCD_LAYER0_ARGB8888_MODE             REG_LCD_LAYER0_CTRL &= ~LCD_LAYER_CTRL_COLOR_FORMAT_MASK;\
                                                    REG_LCD_LAYER0_CTRL |=(LCD_LAYER_SOURCE_COLOR_ARGB8888<<9);
   #define GET_LCD_LAYER0_COLOR_MODE                ((REG_LCD_LAYER0_CTRL & LCD_LAYER_CTRL_COLOR_FORMAT_MASK)>>9);
   #define SET_LCD_LAYER0_RGB888_MODE               REG_LCD_LAYER0_CTRL &= ~LCD_LAYER_CTRL_COLOR_FORMAT_MASK;\
                                                    REG_LCD_LAYER0_CTRL |=(LCD_LAYER_SOURCE_COLOR_RGB888<<9);
   #define SET_LCD_LAYER0_OPACITY(n)                REG_LCD_LAYER0_CTRL &= ~LCD_LAYER_CTRL_OPACITY_VALUE_MASK;\
                                                    REG_LCD_LAYER0_CTRL |= n;
   #define SET_LCD_LAYER1_SOURCE_KEY(color)         REG_LCD_LAYER1_SRC_KEY = color;
   #define SET_LCD_LAYER1_8BPP_INDEX_MODE           REG_LCD_LAYER1_CTRL &= ~LCD_LAYER_CTRL_COLOR_FORMAT_MASK;
   #define SET_LCD_LAYER1_RGB565_MODE               REG_LCD_LAYER1_CTRL &= ~LCD_LAYER_CTRL_COLOR_FORMAT_MASK;\
                                                    REG_LCD_LAYER1_CTRL |=(LCD_LAYER_SOURCE_COLOR_RGB565<<9);
   #define SET_LCD_LAYER1_ARGB8888_MODE             REG_LCD_LAYER1_CTRL &= ~LCD_LAYER_CTRL_COLOR_FORMAT_MASK;\
                                                    REG_LCD_LAYER1_CTRL |=(LCD_LAYER_SOURCE_COLOR_ARGB8888<<9);
   #define GET_LCD_LAYER1_COLOR_MODE                ((REG_LCD_LAYER1_CTRL & LCD_LAYER_CTRL_COLOR_FORMAT_MASK)>>9);
   #define SET_LCD_LAYER1_RGB888_MODE               REG_LCD_LAYER1_CTRL &= ~LCD_LAYER_CTRL_COLOR_FORMAT_MASK;\
                                                    REG_LCD_LAYER1_CTRL |=(LCD_LAYER_SOURCE_COLOR_RGB888<<9);
   #define SET_LCD_LAYER1_OPACITY(n)                REG_LCD_LAYER1_CTRL &= ~LCD_LAYER_CTRL_OPACITY_VALUE_MASK;\
                                                    REG_LCD_LAYER1_CTRL |= n;
   #define SET_LCD_LAYER2_SOURCE_KEY(color)         REG_LCD_LAYER2_SRC_KEY = color;
   #define SET_LCD_LAYER2_8BPP_INDEX_MODE           REG_LCD_LAYER2_CTRL &= ~LCD_LAYER_CTRL_COLOR_FORMAT_MASK;
   #define SET_LCD_LAYER2_RGB565_MODE               REG_LCD_LAYER2_CTRL &= ~LCD_LAYER_CTRL_COLOR_FORMAT_MASK;\
                                                    REG_LCD_LAYER2_CTRL |=(LCD_LAYER_SOURCE_COLOR_RGB565<<9);
   #define SET_LCD_LAYER2_ARGB8888_MODE             REG_LCD_LAYER2_CTRL &= ~LCD_LAYER_CTRL_COLOR_FORMAT_MASK;\
                                                    REG_LCD_LAYER2_CTRL |=(LCD_LAYER_SOURCE_COLOR_ARGB8888<<9);
   #define GET_LCD_LAYER2_COLOR_MODE                ((REG_LCD_LAYER2_CTRL & LCD_LAYER_CTRL_COLOR_FORMAT_MASK)>>9);
   #define SET_LCD_LAYER2_RGB888_MODE               REG_LCD_LAYER2_CTRL &= ~LCD_LAYER_CTRL_COLOR_FORMAT_MASK;\
                                                    REG_LCD_LAYER2_CTRL |=(LCD_LAYER_SOURCE_COLOR_RGB888<<9);
   #define SET_LCD_LAYER2_OPACITY(n)                REG_LCD_LAYER2_CTRL &= ~LCD_LAYER_CTRL_OPACITY_VALUE_MASK;\
                                                    REG_LCD_LAYER2_CTRL |= n;
   #define SET_LCD_LAYER3_SOURCE_KEY(color)         REG_LCD_LAYER3_SRC_KEY = color;
   #define SET_LCD_LAYER3_8BPP_INDEX_MODE           REG_LCD_LAYER3_CTRL &= ~LCD_LAYER_CTRL_COLOR_FORMAT_MASK;
   #define SET_LCD_LAYER3_RGB565_MODE               REG_LCD_LAYER3_CTRL &= ~LCD_LAYER_CTRL_COLOR_FORMAT_MASK;\
                                                    REG_LCD_LAYER3_CTRL |=(LCD_LAYER_SOURCE_COLOR_RGB565<<9);
   #define SET_LCD_LAYER3_ARGB8888_MODE             REG_LCD_LAYER3_CTRL &= ~LCD_LAYER_CTRL_COLOR_FORMAT_MASK;\
                                                    REG_LCD_LAYER3_CTRL |=(LCD_LAYER_SOURCE_COLOR_ARGB8888<<9);
   #define GET_LCD_LAYER3_COLOR_MODE                ((REG_LCD_LAYER3_CTRL & LCD_LAYER_CTRL_COLOR_FORMAT_MASK)>>9);
   #define SET_LCD_LAYER3_RGB888_MODE               REG_LCD_LAYER3_CTRL &= ~LCD_LAYER_CTRL_COLOR_FORMAT_MASK;\
                                                    REG_LCD_LAYER3_CTRL |=(LCD_LAYER_SOURCE_COLOR_RGB888<<9);
   #define SET_LCD_LAYER3_OPACITY(n)                REG_LCD_LAYER3_CTRL &= ~LCD_LAYER_CTRL_OPACITY_VALUE_MASK;\
                                                    REG_LCD_LAYER3_CTRL |= n;                                                 
   /* macros of LCD layer4 window control register */
   #define SET_LCD_LAYER4_SOURCE_KEY(color)         REG_LCD_LAYER4_SRC_KEY = color;
   #define ENABLE_LCD_LAYER4_SOURCE_KEY             REG_LCD_LAYER4_CTRL |= LCD_LAYER_CTRL_SOURCE_KEY_ENABLE_BIT;
   #define DISABLE_LCD_LAYER4_SOURCE_KEY            REG_LCD_LAYER4_CTRL &= ~LCD_LAYER_CTRL_SOURCE_KEY_ENABLE_BIT;
   #define ENABLE_LAYER4_ADDR_AUTO_INC              REG_LCD_LAYER4_CTRL &= ~LCD_LAYER_CTRL_SOURCE_AUTO_INC_BIT;
   #define DISABLE_LAYER4_ADDR_AUTO_INC             REG_LCD_LAYER4_CTRL |= LCD_LAYER_CTRL_SOURCE_AUTO_INC_BIT;
   #define ENABLE_LAYER4_READ_DATA_SWAP             REG_LCD_LAYER4_CTRL |= LCD_LAYER_CTRL_DATA_SWAP_BIT;
   #define DISABLE_LAYER4_READ_DATA_SWAP            REG_LCD_LAYER4_CTRL &= ~LCD_LAYER_CTRL_DATA_SWAP_BIT;
   #define SET_LCD_LAYER4_8BPP_INDEX_MODE           REG_LCD_LAYER4_CTRL &= ~LCD_LAYER_CTRL_COLOR_FORMAT_MASK;
   #define SET_LCD_LAYER4_RGB565_MODE               REG_LCD_LAYER4_CTRL &= ~LCD_LAYER_CTRL_COLOR_FORMAT_MASK;\
                                                    REG_LCD_LAYER4_CTRL |=(LCD_LAYER_SOURCE_COLOR_RGB565<<9);
   #define SET_LCD_LAYER4_ARGB8888_MODE             REG_LCD_LAYER4_CTRL &= ~LCD_LAYER_CTRL_COLOR_FORMAT_MASK;\
                                                    REG_LCD_LAYER4_CTRL |=(LCD_LAYER_SOURCE_COLOR_ARGB8888<<9);
   #define GET_LCD_LAYER4_COLOR_MODE                ((REG_LCD_LAYER4_CTRL & LCD_LAYER_CTRL_COLOR_FORMAT_MASK)>>9);
   #define SET_LCD_LAYER4_RGB888_MODE               REG_LCD_LAYER4_CTRL &= ~LCD_LAYER_CTRL_COLOR_FORMAT_MASK;\
                                                    REG_LCD_LAYER4_CTRL |=(LCD_LAYER_SOURCE_COLOR_RGB888<<9);
   #define SET_LCD_LAYER4_OPACITY(n)                REG_LCD_LAYER4_CTRL &= ~LCD_LAYER_CTRL_OPACITY_VALUE_MASK;\
                                                    REG_LCD_LAYER4_CTRL |= n;
   #define ENABLE_LCD_LAYER4_OPACITY                REG_LCD_LAYER4_CTRL |= LCD_LAYER_CTRL_OPACITY_ENABLE_BIT;
   #define DISABLE_LCD_LAYER4_OPACITY               REG_LCD_LAYER4_CTRL &= ~LCD_LAYER_CTRL_OPACITY_ENABLE_BIT;
                                                    
   #define GET_LCD_LAYER4_ROTATE                    (kal_uint8) ((REG_LCD_LAYER4_CTRL & LCD_LAYER_CTRL_ROTATE_MASK)>>11);
   #define SET_LCD_LAYER4_ROTATE(n)                 REG_LCD_LAYER4_CTRL &=~LCD_LAYER_CTRL_ROTATE_MASK;\
                                                    REG_LCD_LAYER4_CTRL |= (n<<11);

   /* macros of LCD layer4 offset register */
   #define SET_LCD_LAYER4_WINDOW_OFFSET(x,y)        REG_LCD_LAYER4_OFFSET = ((y<<16) | x);

   /* macros of LCD layer4 window size register */
   #define SET_LCD_LAYER4_WINDOW_SIZE(column,row)   REG_LCD_LAYER4_SIZE = ((row<<16) | column);
   #define GET_LCD_LAYER4_WINDOW_WIDTH              (kal_uint16) (REG_LCD_LAYER4_SIZE & 0xFFFF);
   #define GET_LCD_LAYER4_WINDOW_HEIGHT             (kal_uint16) ((REG_LCD_LAYER4_SIZE>>16) & 0xFFFF);

   /* macros of LCD layer5 window control register */
   #define SET_LCD_LAYER5_SOURCE_KEY(color)          REG_LCD_LAYER5_SRC_KEY = color;
   #define ENABLE_LCD_LAYER5_SOURCE_KEY              REG_LCD_LAYER5_CTRL |= LCD_LAYER_CTRL_SOURCE_KEY_ENABLE_BIT;
   #define DISABLE_LCD_LAYER5_SOURCE_KEY             REG_LCD_LAYER5_CTRL &= ~LCD_LAYER_CTRL_SOURCE_KEY_ENABLE_BIT;
   #define ENABLE_LAYER5_READ_DATA_SWAP              REG_LCD_LAYER5_CTRL |= LCD_LAYER_CTRL_DATA_SWAP_BIT;
   #define DISABLE_LAYER5_READ_DATA_SWAP             REG_LCD_LAYER5_CTRL &= ~LCD_LAYER_CTRL_DATA_SWAP_BIT;
   #define ENABLE_LAYER5_ADDR_AUTO_INC               REG_LCD_LAYER5_CTRL &= ~LCD_LAYER_CTRL_SOURCE_AUTO_INC_BIT;
   #define DISABLE_LAYER5_ADDR_AUTO_INC              REG_LCD_LAYER5_CTRL |= LCD_LAYER_CTRL_SOURCE_AUTO_INC_BIT;
   #define SET_LCD_LAYER5_8BPP_INDEX_MODE            REG_LCD_LAYER5_CTRL &= ~LCD_LAYER_CTRL_COLOR_FORMAT_MASK;
   #define SET_LCD_LAYER5_RGB565_MODE                REG_LCD_LAYER5_CTRL &= ~LCD_LAYER_CTRL_COLOR_FORMAT_MASK;\
                                                     REG_LCD_LAYER5_CTRL |=(LCD_LAYER_SOURCE_COLOR_RGB565<<9);
   #define SET_LCD_LAYER5_ARGB8888_MODE              REG_LCD_LAYER5_CTRL &= ~LCD_LAYER_CTRL_COLOR_FORMAT_MASK;\
                                                     REG_LCD_LAYER5_CTRL |=(LCD_LAYER_SOURCE_COLOR_ARGB8888<<9);
   #define GET_LCD_LAYER5_COLOR_MODE                 ((REG_LCD_LAYER5_CTRL & LCD_LAYER_CTRL_COLOR_FORMAT_MASK)>>9);
   #define SET_LCD_LAYER5_RGB888_MODE                REG_LCD_LAYER5_CTRL &= ~LCD_LAYER_CTRL_COLOR_FORMAT_MASK;\
                                                     REG_LCD_LAYER5_CTRL |=(LCD_LAYER_SOURCE_COLOR_RGB888<<9);
   #define SET_LCD_LAYER5_OPACITY(n)                 REG_LCD_LAYER5_CTRL &= ~LCD_LAYER_CTRL_OPACITY_VALUE_MASK;\
                                                     REG_LCD_LAYER5_CTRL |= n;
   #define ENABLE_LCD_LAYER5_OPACITY                 REG_LCD_LAYER5_CTRL |= LCD_LAYER_CTRL_OPACITY_ENABLE_BIT;
   #define DISABLE_LCD_LAYER5_OPACITY                REG_LCD_LAYER5_CTRL &= ~LCD_LAYER_CTRL_OPACITY_ENABLE_BIT;
                                                     
   #define GET_LCD_LAYER5_ROTATE                     (kal_uint8) ((REG_LCD_LAYER5_CTRL & LCD_LAYER_CTRL_ROTATE_MASK)>>11);
   #define SET_LCD_LAYER5_ROTATE(n)                  REG_LCD_LAYER5_CTRL &=~LCD_LAYER_CTRL_ROTATE_MASK;\
                                                     REG_LCD_LAYER5_CTRL |= (n<<11);
                                                     
   /* macros of LCD layer5 offset register */        
   #define SET_LCD_LAYER5_WINDOW_OFFSET(x,y)         REG_LCD_LAYER5_OFFSET = ((y<<16) | x);
                                                     
   /* macros of LCD layer5 window size register */   
   #define SET_LCD_LAYER5_WINDOW_SIZE(column,row)    REG_LCD_LAYER5_SIZE = ((row<<16) | column);
   #define GET_LCD_LAYER5_WINDOW_WIDTH               (kal_uint16) (REG_LCD_LAYER5_SIZE & 0xFFFF);
   #define GET_LCD_LAYER5_WINDOW_HEIGHT              (kal_uint16) ((REG_LCD_LAYER5_SIZE>>16) & 0xFFFF);                                                                                                       
   
   /* macros of LCD LUT registers */
   #define SET_LUT0_COLOR(index, color)              *((volatile unsigned int *) (LCD_COLOR_PALETTE0_ADDR+(index<<2))) = color;
   #define GET_LUT0_COLOR(index)                     *((volatile unsigned int *) (LCD_COLOR_PALETTE0_ADDR+(index<<2)));
   /* macros of LCD command/parameter register */    
   #define SET_LCD_CMD_PARAMETER(index,cmd,para)     *((volatile unsigned int *) (LCD_CMD_PARAMETER_ADDR + (index<<2))) = para|cmd;   
                                                     
   #define ENABLE_LCD_CMD_COMPLETE_INT               REG_LCD_INT_ENABLE |=LCD_INT_ENABLE_CMD_COMPLETE_BIT;
   #define DISABLE_LCD_CMD_COMPLETE_INT              REG_LCD_INT_ENABLE &=~LCD_INT_ENABLE_CMD_COMPLETE_BIT;
   #define ENABLE_LCD_DATA_COMPLETE_INT              REG_LCD_INT_ENABLE |=LCD_INT_ENABLE_DATA_COMPLETE_BIT;
   #define DISABLE_LCD_DATA_COMPLETE_INT             REG_LCD_INT_ENABLE &=~LCD_INT_ENABLE_DATA_COMPLETE_BIT;
   #define LCD_CMD_IS_PENDING                        (REG_LCD_STA & LCD_INT_ENABLE_CMD_COMPLETE_BIT)   
   #define SET_LCD_HW_TRIGGER_LAYER(n)               REG_LCD_ROI_HW_CTRL &= ~LCD_LAYER_MASK;\
                                                     REG_LCD_ROI_HW_CTRL |= n;
   #define GET_LCD_HW_TRIGGER_LAYER                  (REG_LCD_ROI_HW_CTRL & LCD_LAYER_MASK)
                                                     
   #define ENABLE_LCD_HW_TRIGGER_UPDATE              REG_LCD_ROI_HW_CTRL |= 0x80;
   #define DISABLE_LCD_HW_TRIGGER_UPDATE             REG_LCD_ROI_HW_CTRL = 0;      
   #define SET_LCD_DIRECT_COUPLE_LAYER(n)            REG_LCD_ROI_DC_CTRL &= ~LCD_DC_LAYER_MASK;\
                                                     REG_LCD_ROI_DC_CTRL |= (n);
   #define GET_LCD_DIRECT_COUPLE_LAYER               ((REG_LCD_ROI_DC_CTRL & LCD_DC_LAYER_MASK))
   #define SET_LCD_IBW1_TRIGGER_LAYER(n)             
   #define SET_LCD_IBW2_TRIGGER_LAYER(n)                                                          
   #define SET_LCD_HW_TRIGGER_SRC(module) REG_LCD_ROI_HW_CTRL &= ~LCD_HW_TRIGGER_IDMA_MASK;\
                                                REG_LCD_ROI_HW_CTRL |= (module<<16);  
         #define SET_LCD_DC_COUPLE_SRC(module,layer)  REG_LCD_ROI_DC_CTRL &= ~LCD_DC_COUPLE_IDMA_MASK;\
                                                      REG_LCD_ROI_DC_CTRL |= ((module)<<(14-layer*2));                                                           
   //LCD driving current control   
   #define CONFIG_LCD_DRIVING_CURRNET(current)       *((volatile unsigned short *) 0x80000708) &= ~0x03F0;\
   					                                         *((volatile unsigned short *) 0x80000708) |= ((current<<4)|(current<<7));
#else
   #error not support chip
#endif /* (defined(MT6238)) */

#endif //__LCD_IF_6238_SERIES_HW_H__