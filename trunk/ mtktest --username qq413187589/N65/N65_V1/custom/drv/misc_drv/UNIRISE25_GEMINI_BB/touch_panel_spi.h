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
 *    serial_interface.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines Serial Interface.
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
#ifndef TOUCH_PANEL_SPI_H
#define TOUCH_PANEL_SPI_H
 
#ifdef __CUST_NEW__
   extern const char gpio_tp_spi_din_pin;
   extern const char gpio_tp_spi_clk_pin;
   extern const char gpio_tp_spi_dout_pin;
   extern const char gpio_tp_spi_cs_pin;
   extern const char gpio_tp_spi_busy_pin;

   #define SPI_DIN_PIN     gpio_tp_spi_din_pin  /*GPO*/
   #define SPI_CLK_PIN     gpio_tp_spi_clk_pin /*GPO*/ 
   #define SPI_DOUT_PIN    gpio_tp_spi_dout_pin /*GPI*/ 
   #define SPI_CS_PIN      gpio_tp_spi_cs_pin /*GPO*/ 
   #define SPI_BUSY_PIN    gpio_tp_spi_busy_pin /*GPI*/ 
#else /* __CUST_NEW__ */
#if 1/*Jupiter_Plus*/
   #define SPI_DIN_PIN     40  /*GPO*/
   #define SPI_CLK_PIN     16 /*GPO*/ 
   #define SPI_DOUT_PIN    18 /*GPI*/ 
   #define SPI_CS_PIN      19 /*GPO*/ 
   #define SPI_BUSY_PIN    17 /*GPI*/ 
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif /* __CUST_NEW__ */

#define SET_CLK_HIGH()			(GPIO_WriteIO(1,SPI_CLK_PIN))
#define SET_CLK_LOW()			(GPIO_WriteIO(0,SPI_CLK_PIN))
#define SET_DATA_HIGH()	      GPIO_WriteIO(1,SPI_DIN_PIN)
#define SET_DATA_LOW()			GPIO_WriteIO(0,SPI_DIN_PIN)
#define GET_DATA_BIT()			GPIO_ReadIO(SPI_DOUT_PIN)
#define GET_BUSY_BIT()        GPIO_ReadIO(SPI_BUSY_PIN)

void serial_write_bit_high(void);
void serial_write_bit_low(void);
void serial_delay(void);
void serial_write_data(kal_uint8 data);
kal_uint16 serial_read_data(void);
void serial_init(void);
#endif
