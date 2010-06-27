/*************************************************************************
 *
 * MODULE NAME:    rda5868.h
 * PROJECT CODE:   rda5868
 * DESCRIPTION:    rda5868 include file.
 * MAINTAINER:     mql
 * CREATION DATE:  18/12/08
 *
 * SOURCE CONTROL: $Id: rda5868.h,v 2.6 2009/8/14, 18:08:38 mql Exp $
 *
 * LICENSE:
 *     This source code is copyright (c) 2008-2009 rda.
 *     All rights reserved.
 *
 * NOTES TO USERS:
 *   None.
 *				 
 *************************************************************************/
#ifndef  __RDA_5868_H__
#define __RDA_5868_H__



/* GPIO definition */
#if 1
#define RDA5868_CRYCLK		101		/// 32.768 kHz clock GPO2 mode == 2
#define CRYCLK_MSK			3		///	GPO2 mode msk
#define RDA5868_SDA			9		/// I2C data pin  
#define RDA5868_SCL			8       ///  I2C clock pin
#define RDA5868_POWER_EN                6
#define RDA5868_RESET                34
#define RDA5868_UART_RXD      49
#define RDA5868_UART_TXD     50
#define RDA5868_PCM_CLK      51
#define RDA5868_PCM_DOUT    52
#define RDA5868_PCM_DIN      53
#define RDA5868_PCM_SYNC     54
#else


#define RDA5868_SDA		34		/// I2C data pin  
#define RDA5868_SCL			41       ///  I2C clock pin
#ifdef __CUST_NEW__

extern const char gpio_bt_reset_pin; 
extern const char gpio_bt_power_pin;
extern const char gpio_bt_urxd3_pin; 
extern const char gpio_bt_utxd3_pin;

#define RDA5868_POWER_EN     gpio_bt_power_pin
#define RDA5868_RESET            gpio_bt_reset_pin
#define RDA5868_UART_RXD     gpio_bt_urxd3_pin
#define RDA5868_UART_TXD     gpio_bt_utxd3_pin

#else

extern  const unsigned char bt_gpio_setting[16] ;
#define RDA5868_POWER_EN    (bt_gpio_setting[0])
#define RDA5868_RESET            (bt_gpio_setting[2])
#define RDA5868_UART_RXD     (bt_gpio_setting[6])
#define RDA5868_UART_TXD     (bt_gpio_setting[7])
#endif
#endif

////#define RDABT_DELAY(DURATION) 	{unsigned int i; for(i = 1; i <= (80000*DURATION); i++){}}

#define RDABT_DELAY(DURATION) kal_sleep_task(DURATION)

typedef enum{
	RDA_NONE_CHIP = 0,
	RDA_5868_R5,
	RDA_5868_R7

}RDABT_CHIP_ENUM;

#define  __RDA5868_USE_IIC__
//#define _RDA_PATCH_UART_


#ifdef __RDA5868_USE_IIC__
#define __RDA_SOFT_RESET__
#endif


#define __RDA_CHIP_R5__
#define __RDA_CHIP_R7__

#ifdef __RDA_CHIP_R7__

#if !defined( _RDA_PATCH_UART_) && !defined(__RDA_CHIP_6611__)
#define __RDA_SLEEP_ROM__
#endif

//#define __RDA_SHARE_CRYSTAL__
//#define __DISABLE_SYNC_WITHGSM__
#endif

#if (defined(__RDA_CHIP_R5__) && defined(__RDA_CHIP_R7__) ) && defined(__RDA5868_USE_IIC__)
#define __RDA_AUTO_CHIP__
#endif

#if defined(__RDA_CHIP_6611__) && defined(__RDA_SLEEP_ROM__)
#error cant define __RDA_SLEEP_ROM__ on rda6611
#endif

#if defined(__RDA_CHIP_6611__) && !defined(__RDA_CHIP_R7__)
#error please define __RDA_CHIP_R7__
#endif

#if defined(__RDA_CHIP_6611__) && (defined(__RDA_CHIP_R5__) || defined(__RDA5868_USE_IIC__))
#error please undefine r5 iic
#endif


#if (defined(__RDA_CHIP_R5__) && defined(__RDA_CHIP_R7__) ) && !defined(__RDA5868_USE_IIC__)
#error please define __RDA5868_USE_IIC__
#endif

#if !defined(__RDA_CHIP_R5__) && !defined(__RDA_CHIP_R7__) 
#error  none chip define
#endif


#if defined(__RDA5868_32M_CRYSTAL__) && !defined(__RDA5868_USE_IIC__)
#error please define __RDA5868_USE_IIC__
#endif

void GPO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada);
void GPIO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada);
void GPIO_WriteIO(char data, char port);
void GPIO_InitIO(char direction, char port);

void RDA_bt_SerialCommCryClkOff(void);
void RDA_bt_SerialCommCryClkOn(void);
void RDA_bt_Power_On_Reset(void);

void rda5868_uart_start(void);
void rda5868_uart_configure(unsigned baud);
void rda5868_uart_stop(void);
unsigned char rda5868_uart_tx(kal_uint8 *buf, unsigned short num_to_send, unsigned short *num_send);

void RDA_bt_SerialCommInit(void);
void rda5400_write_data(unsigned char regaddr, unsigned short *data, unsigned char datalen);
void rda5868_read_data(unsigned int regaddr, unsigned int *data, unsigned char datalen);

#ifdef __RDA_CHIP_R5__
void RDA5400_Intialization(void);
void  Rda5868_rf_Write(void);
#endif

#ifdef __RDA_CHIP_R7__
void RDA5400_Intialization_2(void);
void Rda5868_rf_Write_2(void);
#endif

#ifdef __RDA_AUTO_CHIP__
kal_uint8 rdabt_get_chipid(void);
#endif

#endif

