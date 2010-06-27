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
 *   sccb.h
 *
 * Project:
 * --------
 *   MT6219
 *
 * Description:
 * ------------
 *   SCCB interface
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __SCCB_H__
#define __SCCB_H__

#if (defined(MT6219)||defined(MT6228)||defined(MT6226)||defined(MT6226M)||defined(MT6226D)||defined(MT6227)||defined(MT6227D)||defined(MT6229)||defined(MT6230))
/* defination of MT6219 SCCB interface */

//#define DVT_TEST
#if (!defined(MT6219))
#define SCCB_I2C_base                 (0x800A0000)   /* SCCB Interface */
#endif

/* HW SCCB Define */
#define SCCB_READ_COMPLETE			0x01
#define SCCB_WRITE_COMPLETE		0x02

#define SCCB_CTRL_REG					(SCCB_I2C_base+0x00)
#define SCCB_DATA_LENGTH_REG			(SCCB_I2C_base+0x08)
#define SCCB_BUFFER_TIME_REG			(SCCB_I2C_base+0x0C)
#define SCCB_START_HOLD_TIME_REG		(SCCB_I2C_base+0x10)
#define SCCB_DATA_HOLD_TIME_REG		(SCCB_I2C_base+0x14)
#define SCCB_CLOCK_LOW_PERIOD_REG	(SCCB_I2C_base+0x18)
#define SCCB_CLOCK_HIGH_PERIOD_REG	(SCCB_I2C_base+0x1C)
#define SCCB_DATA_REG					(SCCB_I2C_base+0x20)
#define SCCB_START_SETUP_TIME_REG	(SCCB_I2C_base+0x24)
#define SCCB_STOP_SETUP_TIME_REG		(SCCB_I2C_base+0x28)
#define SCCB_MODE_REG					(SCCB_I2C_base+0x38)
#define SCCB_BUFFER_CLEAR_REG			(SCCB_I2C_base+0x3C)
#define SCCB_STATUS_REG					(SCCB_I2C_base+0x40)
#define SCCB_READ_DATA_REG				(SCCB_I2C_base+0x44)
#define REG_SCCB_CTRL					*((volatile unsigned short *) (SCCB_I2C_base+0x00))
#define REG_SCCB_DATA_LENGTH			*((volatile unsigned short *) (SCCB_I2C_base+0x08))
#define REG_SCCB_BUFFER_TIME			*((volatile unsigned short *) (SCCB_I2C_base+0x0C))
#define REG_SCCB_START_HOLD_TIME		*((volatile unsigned short *) (SCCB_I2C_base+0x10))
#define REG_SCCB_DATA_HOLD_TIME		*((volatile unsigned short *) (SCCB_I2C_base+0x14))
#define REG_SCCB_CLOCK_LOW_PERIOD	*((volatile unsigned short *) (SCCB_I2C_base+0x18))
#define REG_SCCB_CLOCK_HIGH_PERIOD	*((volatile unsigned short *) (SCCB_I2C_base+0x1C))
#define REG_SCCB_DATA					*((volatile unsigned short *) (SCCB_I2C_base+0x20))
#define REG_SCCB_START_SETUP_TIME	*((volatile unsigned short *) (SCCB_I2C_base+0x24))
#define REG_SCCB_STOP_SETUP_TIME		*((volatile unsigned short *) (SCCB_I2C_base+0x28))
#define REG_SCCB_MODE					*((volatile unsigned short *) (SCCB_I2C_base+0x38))
#define REG_SCCB_BUFFER_CLEAR			*((volatile unsigned short *) (SCCB_I2C_base+0x3C))
#define REG_SCCB_STATUS					*((volatile unsigned short *) (SCCB_I2C_base+0x40))
#define REG_SCCB_READ_DATA				*((volatile unsigned short *) (SCCB_I2C_base+0x44))
#if (defined(MT6226)||defined(MT6226M)||defined(MT6226D)||defined(MT6227)||defined(MT6227D)||defined(MT6229)||defined(MT6230))
#define REG_SCCB_READ_DATA_L			*((volatile unsigned short *) (SCCB_base+0x48)) //MT6227 New
#endif
#define SCCB_DATA_REG_ID_ADDRESS		0x100

#define ENABLE_SCCB							REG_SCCB_CTRL = 0x01;
#define DISABLE_SCCB							REG_SCCB_CTRL = 0x00;
#define SET_SCCB_DATA_LENGTH(n)			REG_SCCB_DATA_LENGTH = (n-1);
#define SET_SCCB_BUFFER_TIMER(n)			REG_SCCB_BUFFER_TIME = (n-1);
#define SET_SCCB_START_HOLD_TIME(n)		REG_SCCB_START_HOLD_TIME =(n-1);
#define SET_SCCB_DATA_HOLD_TIME(n)		REG_SCCB_DATA_HOLD_TIME = (n-1);
#define SET_SCCB_CLK_LOW_PERIOD(n)		REG_SCCB_CLOCK_LOW_PERIOD = (n-1);
#define SET_SCCB_CLK_HIGH_PERIOD(n)		REG_SCCB_CLOCK_HIGH_PERIOD = (n-1);
#define SET_SCCB_START_SETUP_TIME(n)	REG_SCCB_START_SETUP_TIME =(n-1);
#define SET_SCCB_STOP_SETUP_TIME(n)		REG_SCCB_STOP_SETUP_TIME = (n-1);
#define CLEAR_SCCB_BUFFER					REG_SCCB_BUFFER_CLEAR =1;
#define SET_SCCB_MASTER_MODE				REG_SCCB_MODE=1;
#define SCCB_IS_READING						(!(REG_SCCB_STATUS & 0x01))
#define SCCB_IS_WRITTING					(!(REG_SCCB_STATUS & 0x02))

#if (defined(MT6219)||defined(MT6226)||defined(MT6226M)||defined(MT6226D)||defined(MT6227)||defined(MT6227D))
#define SCCB_SERIAL_CLK_PIN		8
#define SCCB_SERIAL_DATA_PIN		9

#elif (defined(MT6228)||defined(MT6229)||defined(MT6230))

#if (defined(DVT_TEST))
#define SCCB_SERIAL_CLK_PIN		8
#define SCCB_SERIAL_DATA_PIN		9
#else
#define SCCB_SERIAL_CLK_PIN		2
#define SCCB_SERIAL_DATA_PIN		3
#endif

#endif

#ifdef __CUST_NEW__
/* SW SCCB Define */
#define SET_SCCB_CLK_OUTPUT		GPIO_InitIO_FAST(OUTPUT,SCCB_SERIAL_CLK_PIN);
#define SET_SCCB_DATA_OUTPUT		GPIO_InitIO_FAST(OUTPUT,SCCB_SERIAL_DATA_PIN);
#define SET_SCCB_DATA_INPUT		GPIO_InitIO_FAST(INPUT,SCCB_SERIAL_DATA_PIN);
#define SET_SCCB_CLK_HIGH			GPIO_WriteIO_FAST(1,SCCB_SERIAL_CLK_PIN);
#define SET_SCCB_CLK_LOW			GPIO_WriteIO_FAST(0,SCCB_SERIAL_CLK_PIN);
#define SET_SCCB_DATA_HIGH			GPIO_WriteIO_FAST(1,SCCB_SERIAL_DATA_PIN);
#define SET_SCCB_DATA_LOW			GPIO_WriteIO_FAST(0,SCCB_SERIAL_DATA_PIN);
#define GET_SCCB_DATA_BIT			GPIO_ReadIO_FAST(SCCB_SERIAL_DATA_PIN)
#else
/* SW SCCB Define */
#define SET_SCCB_CLK_OUTPUT		GPIO_InitIO(OUTPUT,SCCB_SERIAL_CLK_PIN);
#define SET_SCCB_DATA_OUTPUT		GPIO_InitIO(OUTPUT,SCCB_SERIAL_DATA_PIN);
#define SET_SCCB_DATA_INPUT		GPIO_InitIO(INPUT,SCCB_SERIAL_DATA_PIN);
#define SET_SCCB_CLK_HIGH			GPIO_WriteIO(1,SCCB_SERIAL_CLK_PIN);
#define SET_SCCB_CLK_LOW			GPIO_WriteIO(0,SCCB_SERIAL_CLK_PIN);
#define SET_SCCB_DATA_HIGH			GPIO_WriteIO(1,SCCB_SERIAL_DATA_PIN);
#define SET_SCCB_DATA_LOW			GPIO_WriteIO(0,SCCB_SERIAL_DATA_PIN);
#define GET_SCCB_DATA_BIT			GPIO_ReadIO(SCCB_SERIAL_DATA_PIN)
#endif

#define ACK_BIT \
{\
	kal_uint32 i;\
	SET_SCCB_CLK_LOW; \
	for (i=0; i<SCCB_DELAY; i++); \
	SET_SCCB_DATA_OUTPUT; \
	SET_SCCB_DATA_LOW; \
	for (i=0; i<SCCB_DELAY; i++); \
	SET_SCCB_CLK_HIGH; \
	for (i=0; i<SCCB_DELAY; i++); \
	SET_SCCB_CLK_LOW; \
	for (i=0;i<SCCB_DELAY;i++);\
}

#define NACK_BIT \
{\
	kal_uint32 i;\
	for (i=0; i<SCCB_DELAY; i++); \
	SET_SCCB_DATA_OUTPUT; \
	for (i=0; i<SCCB_DELAY; i++); \
	SET_SCCB_DATA_HIGH; \
	for (i=0; i<SCCB_DELAY; i++); \
	SET_SCCB_CLK_HIGH; \
	for (i=0; i<SCCB_DELAY; i++); \
	SET_SCCB_CLK_LOW; \
	for (i=0;i<SCCB_DELAY;i++);\
}

#define SCCB_START_TRANSMISSION	\
{\
	kal_uint32 i;\
	SET_SCCB_DATA_OUTPUT;\
   SET_SCCB_DATA_LOW;\
   for (i=0;i<SCCB_DELAY;i++);\
	SET_SCCB_CLK_LOW;\
	for (i=0;i<SCCB_DELAY;i++);\
}

#define SCCB_STOP_TRANSMISSION	\
{\
	kal_uint32 i;\
	SET_SCCB_DATA_OUTPUT;\
	SET_SCCB_DATA_LOW;\
	for (i=0;i<SCCB_DELAY;i++);\
   SET_SCCB_CLK_HIGH;\
   for (i=0;i<SCCB_DELAY;i++);\
	SET_SCCB_DATA_HIGH;\
	for (i=0;i<SCCB_DELAY;i++);\
}

/* Interface */
typedef enum
{
   SCCB_SW_8BIT=1,
   SCCB_SW_16BIT,   
   SCCB_HW_8BIT,
   SCCB_HW_16BIT
} SCCB_MODE_ENUM;

typedef struct{
	kal_uint8 TBUF;	
	kal_uint8 THDSTA;	
	kal_uint8 THDDTA;	
	kal_uint8 TLOW;	
	kal_uint8 THIGH;	
	//kal_uint8 TSUSTA;		
	kal_uint8 TSUSTO;	
} SCCB_FREQ_STRUCT;

/* Extern Global Variable */
void init_sccb(void);
kal_uint8 sccb_config(kal_uint8 mode, kal_uint8 wid, kal_uint8 rid, SCCB_FREQ_STRUCT *freq);
kal_uint8 sccb_getMode(void);
void sccb_setDelay(kal_uint32 delay);
void sccb_write(kal_uint32 cmd, kal_uint32 param);
void sccb_multi_write(kal_uint32 cmd, kal_uint32 *param, kal_uint8 num);
void sccb_cont_write(kal_uint32 cmd, kal_uint32 spec_cmd, kal_uint32 param);
kal_uint32 sccb_read (kal_uint32 cmd);
kal_uint32 sccb_phase3_read (kal_uint32 cmd);
kal_uint32 sccb_cont_read (kal_uint32 cmd, kal_uint32 spec_cmd);
kal_uint8 sccb_multi_read (kal_uint32 cmd, kal_uint32 *param, kal_uint8 num);

#elif(defined(MT6225) || defined(MT6238))
/* Interface */
typedef enum
{
   SCCB_SW_8BIT=1,
   SCCB_SW_16BIT,   
   SCCB_HW_8BIT,
   SCCB_HW_16BIT
} SCCB_MODE_ENUM;

#if defined(MT6225)
#define SCCB_SERIAL_CLK_PIN		8
#define SCCB_SERIAL_DATA_PIN		9
#elif defined(MT6238)
   #define SCCB_SERIAL_CLK_PIN		5
   #define SCCB_SERIAL_DATA_PIN		6
#endif

#ifdef __CUST_NEW__
/* SW SCCB Define */
#define SET_SCCB_CLK_OUTPUT		GPIO_InitIO_FAST(OUTPUT,SCCB_SERIAL_CLK_PIN);
#define SET_SCCB_DATA_OUTPUT		GPIO_InitIO_FAST(OUTPUT,SCCB_SERIAL_DATA_PIN);
#define SET_SCCB_DATA_INPUT		GPIO_InitIO_FAST(INPUT,SCCB_SERIAL_DATA_PIN);
#define SET_SCCB_CLK_HIGH			GPIO_WriteIO_FAST(1,SCCB_SERIAL_CLK_PIN);
#define SET_SCCB_CLK_LOW			GPIO_WriteIO_FAST(0,SCCB_SERIAL_CLK_PIN);
#define SET_SCCB_DATA_HIGH			GPIO_WriteIO_FAST(1,SCCB_SERIAL_DATA_PIN);
#define SET_SCCB_DATA_LOW			GPIO_WriteIO_FAST(0,SCCB_SERIAL_DATA_PIN);
#define GET_SCCB_DATA_BIT			GPIO_ReadIO_FAST(SCCB_SERIAL_DATA_PIN)
#else /*__CUST_NEW__*/
/* SW SCCB Define */
#define SET_SCCB_CLK_OUTPUT		GPIO_InitIO(OUTPUT,SCCB_SERIAL_CLK_PIN)
#define SET_SCCB_DATA_OUTPUT		GPIO_InitIO(OUTPUT,SCCB_SERIAL_DATA_PIN)
#define SET_SCCB_DATA_INPUT		GPIO_InitIO(INPUT,SCCB_SERIAL_DATA_PIN)
#define SET_SCCB_CLK_HIGH			GPIO_WriteIO(1,SCCB_SERIAL_CLK_PIN)
#define SET_SCCB_CLK_LOW			GPIO_WriteIO(0,SCCB_SERIAL_CLK_PIN)
#define SET_SCCB_DATA_HIGH			GPIO_WriteIO(1,SCCB_SERIAL_DATA_PIN)
#define SET_SCCB_DATA_LOW			GPIO_WriteIO(0,SCCB_SERIAL_DATA_PIN)
#define GET_SCCB_DATA_BIT			GPIO_ReadIO(SCCB_SERIAL_DATA_PIN)
#endif /*__CUST_NEW__*/



#ifdef DOUBLE_CAMERA_SUPPORT
//Huyanwei Add It 
//double camera
#define SCCB_SERIAL_CLK_PIN_2	                 8
#define SCCB_SERIAL_DATA_PIN_2		   9

#define SET_SCCB_CLK_OUTPUT_2			GPIO_InitIO(OUTPUT,SCCB_SERIAL_CLK_PIN_2);
#define SET_SCCB_DATA_OUTPUT_2		GPIO_InitIO(OUTPUT,SCCB_SERIAL_DATA_PIN_2);
#define SET_SCCB_DATA_INPUT_2			GPIO_InitIO(INPUT,SCCB_SERIAL_DATA_PIN_2);
#define SET_SCCB_CLK_HIGH_2			GPIO_WriteIO(1,SCCB_SERIAL_CLK_PIN_2);
#define SET_SCCB_CLK_LOW_2				GPIO_WriteIO(0,SCCB_SERIAL_CLK_PIN_2);
#define SET_SCCB_DATA_HIGH_2			GPIO_WriteIO(1,SCCB_SERIAL_DATA_PIN_2);
#define SET_SCCB_DATA_LOW_2			GPIO_WriteIO(0,SCCB_SERIAL_DATA_PIN_2);
#define GET_SCCB_DATA_BIT_2			GPIO_ReadIO(SCCB_SERIAL_DATA_PIN_2)

#endif  /*DOUBLE_CAMERA_SUPPORT*/


typedef struct{
	kal_uint8 TBUF;	
	kal_uint8 THDSTA;	
	kal_uint8 THDDTA;	
	kal_uint8 TLOW;	
	kal_uint8 THIGH;	
	//kal_uint8 TSUSTA;		
	kal_uint8 TSUSTO;	
} SCCB_FREQ_STRUCT;

#endif

#endif /* __SCCB_H__ */

