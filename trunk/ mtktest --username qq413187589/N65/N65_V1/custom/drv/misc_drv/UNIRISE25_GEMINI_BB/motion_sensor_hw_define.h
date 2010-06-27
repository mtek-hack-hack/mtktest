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
 *    motion_sensor_hw_define.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines GPIO for serial interface.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef MOTION_SENSOR_HW_DEFINE_H
#define MOTION_SENSOR_HW_DEFINE_H

#ifdef __CUST_NEW__
#if (defined(KXP74_SPI) || defined(KXP84_SPI))
   extern const char gpio_ms_spi_din_pin;
   extern const char gpio_ms_spi_dout_pin;
   extern const char gpio_ms_spi_clk_pin;
   extern const char gpio_ms_spi_cs_pin;
   extern const char gpio_ms_spi_reset_pin;

   /*GPIO for KXP84 SPI interface*/
   #define MS_SPI_DIN_PIN        gpio_ms_spi_din_pin  /*GPO*/
   #define MS_SPI_CLK_PIN        gpio_ms_spi_clk_pin /*GPO*/
   #define MS_SPI_DOUT_PIN       gpio_ms_spi_dout_pin /*GPI*/
   #define MS_SPI_CS_PIN         gpio_ms_spi_cs_pin /*GPO*/
   #define MS_SPI_RESET_PIN      gpio_ms_spi_reset_pin /*GPO*/
#elif defined(KXP84_I2C) 
   extern const char gpio_ms_i2c_addr_pin;
   extern const char gpio_ms_i2c_clk_pin;
   extern const char gpio_ms_i2c_data_pin;
   extern const char gpio_ms_i2c_cs_pin;
   extern const char gpio_ms_i2c_reset_pin;

   /*GPIO for KXP I2C interface*/
   #define MS_I2C_ADDR_PIN           gpio_ms_i2c_addr_pin  /*GPO*/
   #define MS_I2C_CLK_PIN            gpio_ms_i2c_clk_pin /*GPO*/
   #define MS_I2C_DATA_PIN           gpio_ms_i2c_data_pin /*GPI*/
   #define MS_I2C_CS_PIN             gpio_ms_i2c_cs_pin /*GPO*/
   #define MS_I2C_RESET_PIN          gpio_ms_i2c_reset_pin /*GPO*/
#elif defined(MXC6202_I2C) 
   extern const char gpio_acc_sensor_sck_pin;
   extern const char gpio_acc_sensor_sda_pin;

   /*GPIO for MEMSIC serial interface*/
   #define ACC_SENSOR_SCK     gpio_acc_sensor_sck_pin
   #define ACC_SENSOR_SDA     gpio_acc_sensor_sda_pin
#endif


#else /* __CUST_NEW__ */

/*GPIO for KXP84 SPI interface*/
#define MS_SPI_DIN_PIN        37  /*GPO*/
#define MS_SPI_CLK_PIN        52 /*GPO*/
#define MS_SPI_DOUT_PIN       54//33 /*GPI*/
#define MS_SPI_CS_PIN         39 /*GPO*/
#define MS_SPI_RESET_PIN      38 /*GPO*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*GPIO for KXP I2C interface*/
#define MS_I2C_ADDR_PIN           37  /*GPO*/
#define MS_I2C_CLK_PIN            52 /*GPO*/
#define MS_I2C_DATA_PIN           54//33 /*GPI*/
#define MS_I2C_CS_PIN             39 /*GPO*/
#define MS_I2C_RESET_PIN          38 /*GPO*/


/*GPIO for MEMSIC serial interface*/
#define ACC_SENSOR_SCK 31
#define ACC_SENSOR_SDA 32

#endif /* __CUST_NEW__ */

/* I2C slave address for MXC6202 series. */
//#define MXC6202_I2C_SLAVE_ADDR      0x20  /* MXC62020 */
//#define MXC6202_I2C_SLAVE_ADDR      0x22  /* MXC62021 */
//#define MXC6202_I2C_SLAVE_ADDR      0x24  /* MXC62022 */
//#define MXC6202_I2C_SLAVE_ADDR      0x26  /* MXC62023 */
//#define MXC6202_I2C_SLAVE_ADDR      0x28  /* MXC62024 */
#define MXC6202_I2C_SLAVE_ADDR      0x2A  /* MXC62025 */
//#define MXC6202_I2C_SLAVE_ADDR      0x2C  /* MXC62026 */
//#define MXC6202_I2C_SLAVE_ADDR      0x2E  /* MXC62027 */


#endif
