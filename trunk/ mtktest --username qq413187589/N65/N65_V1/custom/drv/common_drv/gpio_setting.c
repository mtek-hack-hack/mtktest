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
 *    gpio_setting.c
 *
 * Project:
 * --------
 *   Dragonfly
 *
 * Description:
 * ------------
 *   This Module defines the GPIO and GPO settings.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __CUST_NEW__
#include "gpio_def.h"
#include "drv_comm.h"
#include "reg_base.h"
#include "gpio_hw.h"
#include "gpio_sw.h"
#include "gpio_drv.h"

#define GPIO_PORTNULL_MODE  0
#define GPO_PORTNULL_MODE  0
#define GPIO_PORTNULL_DIR   0
#define GPIO_PORTNULL_PULL  0
#define GPIO_PORTNULL_INV   0

#define MODE0_GPIONULL     0
#define MODE1_GPIONULL     0
#define MODE2_GPIONULL     0
#define MODE3_GPIONULL     0

#define DIR_OUT_GPIONULL   0
#define DIR_IN_GPIONULL   0

/* General macro to calculate GPIO MODE register. */
#define GPIO_MODE_REG_VAL(port0, port1, port2, port3, port4, port5, port6, port7)                 \
    ((GPIO_PORT##port0##_MODE) | (GPIO_PORT##port1##_MODE<<2) | (GPIO_PORT##port2##_MODE<<4) |    \
    (GPIO_PORT##port3##_MODE<<6) | (GPIO_PORT##port4##_MODE<<8) | (GPIO_PORT##port5##_MODE<<10) | \
    (GPIO_PORT##port6##_MODE<<12) | (GPIO_PORT##port7##_MODE<<14))

/* General macro to calculate GPO MODE register. */
#define GPO_MODE_REG_VAL(port0, port1, port2, port3, port4, port5, port6, port7)                 \
    ((GPO_PORT##port0##_MODE) | (GPO_PORT##port1##_MODE<<2) | (GPO_PORT##port2##_MODE<<4) |    \
    (GPO_PORT##port3##_MODE<<6) | (GPO_PORT##port4##_MODE<<8) | (GPO_PORT##port5##_MODE<<10) | \
    (GPO_PORT##port6##_MODE<<12) | (GPO_PORT##port7##_MODE<<14))

/* General macro to calculate GPIO register with 1 bit unit. */
#define GPIO_HWORD_REG_FOR_1BIT(name, port0, port1, port2, port3, port4, port5, port6, port7, port8, port9, \
                                port10, port11, port12, port13, port14, port15)	\
    ((GPIO_PORT##port0##_##name) | (GPIO_PORT##port1##_##name<<1) | (GPIO_PORT##port2##_##name<<2) |         \
    (GPIO_PORT##port3##_##name<<3) | (GPIO_PORT##port4##_##name<<4) | (GPIO_PORT##port5##_##name<<5) |       \
    (GPIO_PORT##port6##_##name<<6) | (GPIO_PORT##port7##_##name<<7) | (GPIO_PORT##port8##_##name<<8) |       \
    (GPIO_PORT##port9##_##name<<9) | (GPIO_PORT##port10##_##name<<10) | (GPIO_PORT##port11##_##name<<11) |   \
    (GPIO_PORT##port12##_##name<<12) | (GPIO_PORT##port13##_##name<<13) | (GPIO_PORT##port14##_##name<<14) | \
    (GPIO_PORT##port15##_##name<<15))

/* General macro to calculate GPIO word-length variable value with 1 bit unit. */
#define GPIO_WORD_VAR_FOR_1BIT(name, port0, port1, port2, port3, port4, port5, port6, port7, port8, port9, port10, \
	                            port11, port12, port13, port14, port15, port16, port17, port18, port19, port20, port21, \
                               port22, port23, port24, port25, port26, port27, port28, port29, port30, port31) \
    ((name##_GPIO##port0) | (name##_GPIO##port1<<1) | (name##_GPIO##port2<<2) | (name##_GPIO##port3<<3) | (name##_GPIO##port4<<4) | \
    (name##_GPIO##port5<<5) | (name##_GPIO##port6<<6) | (name##_GPIO##port7<<7) | (name##_GPIO##port8<<8) | (name##_GPIO##port9<<9) | \
    (name##_GPIO##port10<<10) | (name##_GPIO##port11<<11) | (name##_GPIO##port12<<12) | (name##_GPIO##port13<<13) | (name##_GPIO##port14<<14) | \
    (name##_GPIO##port15<<15) | (name##_GPIO##port16<<16) | (name##_GPIO##port17<<17) | (name##_GPIO##port18<<18) | (name##_GPIO##port19<<19) | \
    (name##_GPIO##port20<<20) | (name##_GPIO##port21<<21) | (name##_GPIO##port22<<22) | (name##_GPIO##port23<<23) | (name##_GPIO##port24<<24) | \
    (name##_GPIO##port25<<25) | (name##_GPIO##port26<<26) | (name##_GPIO##port27<<27) | (name##_GPIO##port28<<28) | (name##_GPIO##port29<<29) | \
    (name##_GPIO##port30<<30) | (name##_GPIO##port31<<31))

#if defined(DRV_GPIO_REG_AS_6205B) || defined(DRV_GPIO_REG_AS_6218B) || defined(DRV_GPIO_REG_AS_6219) || defined(DRV_GPIO_REG_AS_6227) || defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6225) || defined(DRV_GPIO_REG_AS_6223) || defined(DRV_GPIO_REG_AS_6238)
   /* GPIO mode register values for different platforms. */
   #define GPIO_MODE_REG1  GPIO_MODE_REG_VAL(0, 1, 2, 3, 4, 5, 6, 7)
   #define GPIO_MODE_REG2  GPIO_MODE_REG_VAL(8, 9, 10, 11, 12, 13, 14, 15)
   #if defined(DRV_GPIO_REG_AS_6205B)
      #define GPIO_MODE_REG3  GPIO_MODE_REG_VAL(16, 17, 18, 19, 20, 21, NULL, NULL)
      #define GPO_MODE_REG    GPO_MODE_REG_VAL(0, 1, 2, 3, NULL, NULL, NULL, NULL)
   #else /* DRV_GPIO_REG_AS_6205B */
      #define GPIO_MODE_REG3  GPIO_MODE_REG_VAL(16, 17, 18, 19, 20, 21, 22, 23)
      #define GPIO_MODE_REG4  GPIO_MODE_REG_VAL(24, 25, 26, 27, 28, 29, 30, 31)
      #define GPIO_MODE_REG5  GPIO_MODE_REG_VAL(32, 33, 34, 35, 36, 37, 38, 39)
      #define GPIO_MODE_REG6  GPIO_MODE_REG_VAL(40, 41, 42, 43, 44, 45, 46, 47)
      #if defined(DRV_GPIO_REG_AS_6218B)
         #define GPO_MODE_REG  GPO_MODE_REG_VAL(0, 1, 2, NULL, NULL, NULL, NULL, NULL)
      #elif defined(DRV_GPIO_REG_AS_6219) || defined(DRV_GPIO_REG_AS_6225)
         #define GPIO_MODE_REG7  GPIO_MODE_REG_VAL(48, 49, 50, 51, 52, 53, 54, NULL)
         #if defined(DRV_GPIO_REG_AS_6219)
            #define GPO_MODE_REG  GPO_MODE_REG_VAL(0, 1, 2, 3, 4, NULL, NULL, NULL)
         #elif defined(DRV_GPIO_REG_AS_6225)
            #define GPO_MODE_REG  GPO_MODE_REG_VAL(0, 1, 2, 3, NULL, NULL, NULL, NULL)
         #endif
      #elif defined(DRV_GPIO_REG_AS_6227)
         #define GPIO_MODE_REG7  GPIO_MODE_REG_VAL(48, 49, 50, 51, 52, 53, 54, 55)
         #define GPIO_MODE_REG8  GPIO_MODE_REG_VAL(56, NULL, NULL, NULL, NULL, NULL, NULL, NULL)

         #define GPO_MODE_REG  GPO_MODE_REG_VAL(0, 1, 2, 3, 4, NULL, NULL, NULL)
      #elif defined(DRV_GPIO_REG_AS_6228)
         #define GPIO_MODE_REG7  GPIO_MODE_REG_VAL(48, 49, 50, 51, 52, 53, 54, 55)
         #define GPIO_MODE_REG8  GPIO_MODE_REG_VAL(56, 57, 58, 59, 60, 61, 62, 63)
         #define GPIO_MODE_REG9  GPIO_MODE_REG_VAL(64, 65, 66, 67, 68, 69, 70, 71)
         #define GPIO_MODE_REG10  GPIO_MODE_REG_VAL(72, 73, 74, NULL, NULL, NULL, NULL, NULL)

         #define GPO_MODE_REG  GPO_MODE_REG_VAL(0, 1, 2, NULL, NULL, NULL, NULL, NULL)
      #elif defined(DRV_GPIO_REG_AS_6223)
         #define GPIO_MODE_REG7  GPIO_MODE_REG_VAL(48, 49, 50, 51, 52, NULL, NULL, NULL)
      #elif defined(DRV_GPIO_REG_AS_6238)
         #define GPIO_MODE_REG7  GPIO_MODE_REG_VAL(48, 49, 50, 51, 52, 53, 54, 55)
         #define GPIO_MODE_REG8  GPIO_MODE_REG_VAL(56, 57, 58, 59, 60, 61, 62, 63)
         #define GPIO_MODE_REG9  GPIO_MODE_REG_VAL(64, 65, 66, 67, 68, 69, 70, 71)
         #define GPIO_MODE_REGA  GPIO_MODE_REG_VAL(72, 73, 74, 75, 76, 77, 78, 79)
         #define GPIO_MODE_REGB  GPIO_MODE_REG_VAL(80, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
      #endif
   #endif /* DRV_GPIO_REG_AS_6205B */

   /* Macros to calulate GPIO related register value of different platforms with 1 bit unit 
      for different settings, like dirction control pull-up/pull-down enable, inversion control. */
   #define GPIO_HWORD_REG1(name)  GPIO_HWORD_REG_FOR_1BIT(name, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15)
   #if defined(DRV_GPIO_REG_AS_6205B)
      #define GPIO_HWORD_REG2(name)  GPIO_HWORD_REG_FOR_1BIT(name, 16, 17, 18, 19, 20, 21, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,NULL, NULL)
   #else /* DRV_GPIO_REG_AS_6205B) */
      #define GPIO_HWORD_REG2(name)  GPIO_HWORD_REG_FOR_1BIT(name, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31)
      #define GPIO_HWORD_REG3(name)  GPIO_HWORD_REG_FOR_1BIT(name, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47)
      #if defined(DRV_GPIO_REG_AS_6219) || defined(DRV_GPIO_REG_AS_6225)  
         #define GPIO_HWORD_REG4(name)  GPIO_HWORD_REG_FOR_1BIT(name, 48, 49, 50, 51, 52, 53, 54, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
      #elif defined(DRV_GPIO_REG_AS_6227)
         #define GPIO_HWORD_REG4(name)  GPIO_HWORD_REG_FOR_1BIT(name, 48, 49, 50, 51, 52, 53, 54, 55, 56, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
      #elif defined(DRV_GPIO_REG_AS_6228)
         #define GPIO_HWORD_REG4(name)  GPIO_HWORD_REG_FOR_1BIT(name, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63)
         #define GPIO_HWORD_REG5(name)  GPIO_HWORD_REG_FOR_1BIT(name, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, NULL, NULL, NULL, NULL, NULL)
      #elif defined(DRV_GPIO_REG_AS_6223)
         #define GPIO_HWORD_REG4(name)  GPIO_HWORD_REG_FOR_1BIT(name, 48, 49, 50, 51, 52, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
      #elif defined(DRV_GPIO_REG_AS_6238)
         #define GPIO_HWORD_REG4(name)  GPIO_HWORD_REG_FOR_1BIT(name, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63)
         #define GPIO_HWORD_REG5(name)  GPIO_HWORD_REG_FOR_1BIT(name, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79)
         #define GPIO_HWORD_REG6(name)  GPIO_HWORD_REG_FOR_1BIT(name, 80, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
      #endif
   #endif /* DRV_GPIO_REG_AS_6205B */

   /* GPIO direction control register value. */
   #define GPIO_DIR_REG1   GPIO_HWORD_REG1(DIR)
   #define GPIO_DIR_REG2   GPIO_HWORD_REG2(DIR)
#if !defined(DRV_GPIO_REG_AS_6205B)
   #define GPIO_DIR_REG3   GPIO_HWORD_REG3(DIR)
   #if defined(DRV_GPIO_REG_AS_6219) || defined(DRV_GPIO_REG_AS_6227) || defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6225) || defined(DRV_GPIO_REG_AS_6223)
      #define GPIO_DIR_REG4   GPIO_HWORD_REG4(DIR)
   #endif
   #if defined(DRV_GPIO_REG_AS_6228)
      #define GPIO_DIR_REG5   GPIO_HWORD_REG5(DIR)
   #endif
   #if defined(DRV_GPIO_REG_AS_6238)
      #define GPIO_DIR_REG4   GPIO_HWORD_REG4(DIR)
      #define GPIO_DIR_REG5   GPIO_HWORD_REG5(DIR)
      #define GPIO_DIR_REG6   GPIO_HWORD_REG6(DIR)
   #endif
#endif /* !defined(DRV_GPIO_REG_AS_6205B) */
   /* GPIO Pull-up/Pull-down enable register value. */
   #define GPIO_PULL_REG1   GPIO_HWORD_REG1(PULL)
   #define GPIO_PULL_REG2   GPIO_HWORD_REG2(PULL)
#if !defined(DRV_GPIO_REG_AS_6205B)
   #define GPIO_PULL_REG3   GPIO_HWORD_REG3(PULL)
   #if defined(DRV_GPIO_REG_AS_6219) || defined(DRV_GPIO_REG_AS_6227) || defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6225) || defined(DRV_GPIO_REG_AS_6223)
      #define GPIO_PULL_REG4   GPIO_HWORD_REG4(PULL)
   #endif
   #if defined(DRV_GPIO_REG_AS_6228)
      #define GPIO_PULL_REG5   GPIO_HWORD_REG5(PULL)
   #endif
   #if defined(DRV_GPIO_REG_AS_6238)
      #define GPIO_PULL_REG4   GPIO_HWORD_REG4(PULL)
      #define GPIO_PULL_REG5   GPIO_HWORD_REG5(PULL)
      #define GPIO_PULL_REG6   GPIO_HWORD_REG6(PULL)
   #endif
#endif /* !defined(DRV_GPIO_REG_AS_6205B) */
   /* GPIO inversion control register value. */
#if !defined(DRV_GPIO_REG_AS_6205B)
   #define GPIO_INV_REG1   GPIO_HWORD_REG1(INV)
   #define GPIO_INV_REG2   GPIO_HWORD_REG2(INV)
   #define GPIO_INV_REG3   GPIO_HWORD_REG3(INV)
   #if defined(DRV_GPIO_REG_AS_6219) || defined(DRV_GPIO_REG_AS_6227) || defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6225) || defined(DRV_GPIO_REG_AS_6223)
      #define GPIO_INV_REG4   GPIO_HWORD_REG4(INV)
   #endif
   #if defined(DRV_GPIO_REG_AS_6228)
      #define GPIO_INV_REG5   GPIO_HWORD_REG5(INV)
   #endif
   #if defined(DRV_GPIO_REG_AS_6238)
      #define GPIO_INV_REG4   GPIO_HWORD_REG4(INV)
      #define GPIO_INV_REG5   GPIO_HWORD_REG5(INV)
      #define GPIO_INV_REG6   GPIO_HWORD_REG6(INV)
   #endif
#endif /* !defined(DRV_GPIO_REG_AS_6205B) */

   /* General macros to calulate GPIO word-length variable value with 1 bit unit 
      for different platform. */
#if defined(DRV_GPIO_REG_AS_6205B)
   #define GPIO_WORD_VAR0(name)  GPIO_WORD_VAR_FOR_1BIT(name, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, \
                                                    20, 21, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)		
#else /* defined(DRV_GPIO_REG_AS_6205B) */
   #define GPIO_WORD_VAR0(name)  GPIO_WORD_VAR_FOR_1BIT(name, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, \
                                                    20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31)		
   #if defined(DRV_GPIO_REG_AS_6218B)
      #define GPIO_WORD_VAR1(name)  GPIO_WORD_VAR_FOR_1BIT(name, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, NULL, \
                                                       NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
   #elif defined(DRV_GPIO_REG_AS_6219) || defined(DRV_GPIO_REG_AS_6225)
      #define GPIO_WORD_VAR1(name)  GPIO_WORD_VAR_FOR_1BIT(name, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, \
                                                       49, 50, 51, 52, 53, 54, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
   #elif defined(DRV_GPIO_REG_AS_6227)
      #define GPIO_WORD_VAR1(name)  GPIO_WORD_VAR_FOR_1BIT(name, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, \
                                                       49, 50, 51, 52, 53, 54, 55, 56, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
   #elif defined(DRV_GPIO_REG_AS_6228)
      #define GPIO_WORD_VAR1(name)  GPIO_WORD_VAR_FOR_1BIT(name, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, \
                                                  49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63)
      #define GPIO_WORD_VAR2(name)  GPIO_WORD_VAR_FOR_1BIT(name, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, NULL, NULL, NULL, NULL, \
                                                  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, \
                                                  NULL, NULL, NULL, NULL)
   #elif defined(DRV_GPIO_REG_AS_6223)
      #define GPIO_WORD_VAR1(name)  GPIO_WORD_VAR_FOR_1BIT(name, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, \
                                                       49, 50, 51, 52, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)
   #elif defined(DRV_GPIO_REG_AS_6238)
      #define GPIO_WORD_VAR1(name)  GPIO_WORD_VAR_FOR_1BIT(name, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, \
                                                  49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63)
      #define GPIO_WORD_VAR2(name)  GPIO_WORD_VAR_FOR_1BIT(name, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, \
                                                  79, 80, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, \
                                                  NULL, NULL, NULL, NULL)
   #endif
#endif /* !defined(DRV_GPIO_REG_AS_6205B) */
   /* For each GPIO mode, specify if each GPIO pin is allowed to set to this mode 
      with '1' allowed, '0' on the corresponding bit position. Bit 0 means GPIO0, 
      Bit 1 means GPIO1... etc. */
   #define GPIO_MODE0_VAR0  GPIO_WORD_VAR0(MODE0)
   #define GPIO_MODE1_VAR0  GPIO_WORD_VAR0(MODE1)
   #define GPIO_MODE2_VAR0  GPIO_WORD_VAR0(MODE2)
   #define GPIO_MODE3_VAR0  GPIO_WORD_VAR0(MODE3)
   #define GPIO_DIROUT_VAR0  GPIO_WORD_VAR0(DIR_OUT)
   #define GPIO_DIRIN_VAR0  GPIO_WORD_VAR0(DIR_IN)
#if !defined(DRV_GPIO_REG_AS_6205B)
   #define GPIO_MODE0_VAR1  GPIO_WORD_VAR1(MODE0)
   #define GPIO_MODE1_VAR1  GPIO_WORD_VAR1(MODE1)
   #define GPIO_MODE2_VAR1  GPIO_WORD_VAR1(MODE2)
   #define GPIO_MODE3_VAR1  GPIO_WORD_VAR1(MODE3)
   #define GPIO_DIROUT_VAR1  GPIO_WORD_VAR1(DIR_OUT)
   #define GPIO_DIRIN_VAR1  GPIO_WORD_VAR1(DIR_IN)
   #if defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6238)
   #define GPIO_MODE0_VAR2     GPIO_WORD_VAR2(MODE0)
   #define GPIO_MODE1_VAR2     GPIO_WORD_VAR2(MODE1)
   #define GPIO_MODE2_VAR2     GPIO_WORD_VAR2(MODE2)
   #define GPIO_MODE3_VAR2     GPIO_WORD_VAR2(MODE3)
   #define GPIO_DIROUT_VAR2    GPIO_WORD_VAR2(DIR_OUT)
   #define GPIO_DIRIN_VAR2     GPIO_WORD_VAR2(DIR_IN)
   #endif /* DRV_GPIO_REG_AS_6228 */
#endif /* !defined(DRV_GPIO_REG_AS_6205B) */

   /* For each GPO mode, specify if each GPO pin is allowed to set to this mode 
      with '1' allowed, '0' on the corresponding bit position. Bit 0 means GPO0, 
      Bit 1 means GPO1... etc. */
#if defined(DRV_GPIO_REG_AS_6205B) || defined(DRV_GPIO_REG_AS_6225)
   #define GPO_MODE0_VAR0  (MODE0_GPO0 | (MODE0_GPO1 << 1) | (MODE0_GPO2 << 2) | (MODE0_GPO3 << 3))
   #define GPO_MODE1_VAR0  (MODE1_GPO0 | (MODE1_GPO1 << 1) | (MODE1_GPO2 << 2) | (MODE1_GPO3 << 3))
   #define GPO_MODE2_VAR0  (MODE2_GPO0 | (MODE2_GPO1 << 1) | (MODE2_GPO2 << 2) | (MODE2_GPO3 << 3))
   #define GPO_MODE3_VAR0  (MODE3_GPO0 | (MODE3_GPO1 << 1) | (MODE3_GPO2 << 2) | (MODE3_GPO3 << 3))
#elif defined(DRV_GPIO_REG_AS_6219) || defined(DRV_GPIO_REG_AS_6227)
   #define GPO_MODE0_VAR0  (MODE0_GPO0 | (MODE0_GPO1 << 1) | (MODE0_GPO2 << 2) | (MODE0_GPO3 << 3) | (MODE0_GPO4 << 4))
   #define GPO_MODE1_VAR0  (MODE1_GPO0 | (MODE1_GPO1 << 1) | (MODE1_GPO2 << 2) | (MODE1_GPO3 << 3) | (MODE1_GPO4 << 4))
   #define GPO_MODE2_VAR0  (MODE2_GPO0 | (MODE2_GPO1 << 1) | (MODE2_GPO2 << 2) | (MODE2_GPO3 << 3) | (MODE2_GPO4 << 4))
   #define GPO_MODE3_VAR0  (MODE3_GPO0 | (MODE3_GPO1 << 1) | (MODE3_GPO2 << 2) | (MODE3_GPO3 << 3) | (MODE3_GPO4 << 4))
#elif defined(DRV_GPIO_REG_AS_6218B) || defined(DRV_GPIO_REG_AS_6228)
   #define GPO_MODE0_VAR0  (MODE0_GPO0 | (MODE0_GPO1 << 1) | (MODE0_GPO2 << 2))
   #define GPO_MODE1_VAR0  (MODE1_GPO0 | (MODE1_GPO1 << 1) | (MODE1_GPO2 << 2))
   #define GPO_MODE2_VAR0  (MODE2_GPO0 | (MODE2_GPO1 << 1) | (MODE2_GPO2 << 2))
   #define GPO_MODE3_VAR0  (MODE3_GPO0 | (MODE3_GPO1 << 1) | (MODE3_GPO2 << 2))
#endif

/* The '1' of the bit in the variables denotes that the mode is allowed to be set for the 
   corresponding pin. */
const kal_uint32  gpio_mode_allowed[][4] = {
   {GPIO_MODE0_VAR0, GPIO_MODE1_VAR0, GPIO_MODE2_VAR0, GPIO_MODE3_VAR0}
   #if !defined(DRV_GPIO_REG_AS_6205B)
   ,{GPIO_MODE0_VAR1, GPIO_MODE1_VAR1, GPIO_MODE2_VAR1, GPIO_MODE3_VAR1}
   #if defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6238)
   ,{GPIO_MODE0_VAR2, GPIO_MODE1_VAR2, GPIO_MODE2_VAR2, GPIO_MODE3_VAR2}
   #endif
   #endif /* !defined(DRV_GPIO_REG_AS_6205B) */
};

/* The '1' of the bit in the variables denotes that the direction output is allowed to be 
   set for the corresponding pin. */
const kal_uint32  gpio_dir_out_allowed[] = {
   GPIO_DIROUT_VAR0
   #if !defined(DRV_GPIO_REG_AS_6205B)
   ,GPIO_DIROUT_VAR1
   #if defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6238)
   ,GPIO_DIROUT_VAR2
   #endif
   #endif /* !defined(DRV_GPIO_REG_AS_6205B) */
};

/* The '1' of the bit in the variables denotes that the direction input is allowed to be 
   set for the corresponding pin. */
const kal_uint32  gpio_dir_in_allowed[] = {
	GPIO_DIRIN_VAR0
   #if !defined(DRV_GPIO_REG_AS_6205B)
   ,GPIO_DIRIN_VAR1
   #if defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6238)
   ,GPIO_DIRIN_VAR2
   #endif
   #endif /* !defined(DRV_GPIO_REG_AS_6205B) */
};

#if (!defined(DRV_GPIO_REG_AS_6223)) && (!defined(DRV_GPIO_REG_AS_6238))
const kal_uint16  gpo_mode_allowed[] = {
	GPO_MODE0_VAR0, GPO_MODE1_VAR0, GPO_MODE2_VAR0, GPO_MODE3_VAR0
};
#endif /*!defined(DRV_GPIO_REG_AS_6223)*/

#else /* DRV_GPIO_REG_AS_6205B, DRV_GPIO_REG_AS_6218B, DRV_GPIO_REG_AS_6219, DRV_GPIO_REG_AS_6227, DRV_GPIO_REG_AS_6228, DRV_GPIO_REG_AS_6225 */
#error "No support driver customization tool for this chip."
#endif /* DRV_GPIO_REG_AS_6205B, DRV_GPIO_REG_AS_6218B, DRV_GPIO_REG_AS_6219, DRV_GPIO_REG_AS_6227, DRV_GPIO_REG_AS_6228, DRV_GPIO_REG_AS_6225 */

void GPIO_setting_init(void)
{
#if defined(DRV_GPIO_REG_AS_6205B) || defined(DRV_GPIO_REG_AS_6218B) || defined(DRV_GPIO_REG_AS_6219) || defined(DRV_GPIO_REG_AS_6227) || defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6225) || defined(DRV_GPIO_REG_AS_6223) || defined(DRV_GPIO_REG_AS_6238)
   DRV_WriteReg(GPIO_MODE1, GPIO_MODE_REG1);
   DRV_WriteReg(GPIO_MODE2, GPIO_MODE_REG2);
   DRV_WriteReg(GPIO_MODE3, GPIO_MODE_REG3);
#if defined(DRV_GPIO_REG_AS_6205B)
   /* Note that for MT6205B, GPO mode register is on GPIO_MODE3, not GPO_MODE. */
   DRV_WriteReg(GPIO_MODE4, GPO_MODE_REG);
#else /* defined(DRV_GPIO_REG_AS_6205B) */
   DRV_WriteReg(GPIO_MODE4, GPIO_MODE_REG4);
   DRV_WriteReg(GPIO_MODE5, GPIO_MODE_REG5);
   DRV_WriteReg(GPIO_MODE6, GPIO_MODE_REG6);
   #if defined(DRV_GPIO_REG_AS_6219) || defined(DRV_GPIO_REG_AS_6227) || defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6225) || defined(DRV_GPIO_REG_AS_6223) || defined(DRV_GPIO_REG_AS_6238)
   DRV_WriteReg(GPIO_MODE7, GPIO_MODE_REG7);
      #if defined(DRV_GPIO_REG_AS_6227) || defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6238)
      DRV_WriteReg(GPIO_MODE8, GPIO_MODE_REG8);
         #if defined(DRV_GPIO_REG_AS_6228)
         DRV_WriteReg(GPIO_MODE9, GPIO_MODE_REG9);
         DRV_WriteReg(GPIO_MODE10, GPIO_MODE_REG10);
         #endif
         #if defined(DRV_GPIO_REG_AS_6238)
         DRV_WriteReg(GPIO_MODE9, GPIO_MODE_REG9);
         DRV_WriteReg(GPIO_MODEA, GPIO_MODE_REGA);
         DRV_WriteReg(GPIO_MODEB, GPIO_MODE_REGB);
         #endif
      #endif
   #endif
   #if (!defined(DRV_GPIO_REG_AS_6223)) && (!defined(DRV_GPIO_REG_AS_6238))
   DRV_WriteReg(GPO_MODE, GPO_MODE_REG);
   #endif
#endif /* defined(DRV_GPIO_REG_AS_6205B) */

#if defined(DRV_GPIO_REG_AS_6205B)
   DRV_WriteReg(GPIO_DIR, GPIO_DIR_REG1);
   DRV_WriteReg(GPIO_DIR2, GPIO_DIR_REG2);
#else  /* defined(DRV_GPIO_REG_AS_6205B) */
   DRV_WriteReg(GPIO_DIR1, GPIO_DIR_REG1);
   DRV_WriteReg(GPIO_DIR2, GPIO_DIR_REG2);
   DRV_WriteReg(GPIO_DIR3, GPIO_DIR_REG3);
   #if defined(DRV_GPIO_REG_AS_6219) || defined(DRV_GPIO_REG_AS_6227) || defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6225) || defined(DRV_GPIO_REG_AS_6223) || defined(DRV_GPIO_REG_AS_6238)
   DRV_WriteReg(GPIO_DIR4, GPIO_DIR_REG4);
      #if defined(DRV_GPIO_REG_AS_6228)
      DRV_WriteReg(GPIO_DIR5, GPIO_DIR_REG5);
      #endif
      #if defined(DRV_GPIO_REG_AS_6238)
      DRV_WriteReg(GPIO_DIR5, GPIO_DIR_REG5);
      DRV_WriteReg(GPIO_DIR6, GPIO_DIR_REG6);
      #endif
   #endif
#endif /* defined(DRV_GPIO_REG_AS_6205B) */

#if defined(DRV_GPIO_REG_AS_6205B)
   DRV_WriteReg(GPIO_PULLEN, GPIO_PULL_REG1);
   DRV_WriteReg(GPIO_PULLEN2, GPIO_PULL_REG2);
#else  /* defined(DRV_GPIO_REG_AS_6205B) */
   DRV_WriteReg(GPIO_PULLEN1, GPIO_PULL_REG1);
   DRV_WriteReg(GPIO_PULLEN2, GPIO_PULL_REG2);
   DRV_WriteReg(GPIO_PULLEN3, GPIO_PULL_REG3);
   #if defined(DRV_GPIO_REG_AS_6219) || defined(DRV_GPIO_REG_AS_6227) || defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6225) || defined(DRV_GPIO_REG_AS_6223) || defined(DRV_GPIO_REG_AS_6238)
   DRV_WriteReg(GPIO_PULLEN4, GPIO_PULL_REG4);
      #if defined(DRV_GPIO_REG_AS_6228)
      DRV_WriteReg(GPIO_PULLEN5, GPIO_PULL_REG5);
      #endif
      #if defined(DRV_GPIO_REG_AS_6238)
      DRV_WriteReg(GPIO_PULLEN5, GPIO_PULL_REG5);
      DRV_WriteReg(GPIO_PULLEN6, GPIO_PULL_REG6);
      #endif
   #endif
#endif /* !defined(DRV_GPIO_REG_AS_6205B) */

#if !defined(DRV_GPIO_REG_AS_6205B)
   DRV_WriteReg(GPIO_DINV1, GPIO_INV_REG1);
   DRV_WriteReg(GPIO_DINV2, GPIO_INV_REG2);
   DRV_WriteReg(GPIO_DINV3, GPIO_INV_REG3);
   #if defined(DRV_GPIO_REG_AS_6219) || defined(DRV_GPIO_REG_AS_6227) || defined(DRV_GPIO_REG_AS_6228) || defined(DRV_GPIO_REG_AS_6225) || defined(DRV_GPIO_REG_AS_6223) || defined(DRV_GPIO_REG_AS_6238)
   DRV_WriteReg(GPIO_DINV4, GPIO_INV_REG4);
      #if defined(DRV_GPIO_REG_AS_6228)
      DRV_WriteReg(GPIO_DINV5, GPIO_INV_REG5);
      #endif
      #if defined(DRV_GPIO_REG_AS_6238)
      DRV_WriteReg(GPIO_DINV5, GPIO_INV_REG5);
      DRV_WriteReg(GPIO_DINV6, GPIO_INV_REG6);
      #endif
   #endif
#endif /* !defined(DRV_GPIO_REG_AS_6205B) */

#endif /* DRV_GPIO_REG_AS_6205B, DRV_GPIO_REG_AS_6218B, DRV_GPIO_REG_AS_6219, DRV_GPIO_REG_AS_6227, DRV_GPIO_REG_AS_6228, DRV_GPIO_REG_AS_6225*/
}

#endif /* __CUST_NEW__ */
