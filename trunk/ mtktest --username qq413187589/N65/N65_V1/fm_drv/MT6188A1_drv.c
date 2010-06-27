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
 * MT6188A1_drv.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
 *      FM Radio Driver (MT6188A1)
 *
 * Author:
 * -------
 * -------
 *
 *******************************************************************************/
#include "l1audio_def.h"

#ifdef MT6188A1

static uint8 cw_cache[74] = {0};

///#define force_mono

#define USE_I2C
/// #define MT6188_DEBUG
//#define MT6188_DEBUG_DUMP_LOG       //Option log file
//#define MT6188_timing_cal

#if defined MT6188_DEBUG
static uint8 dbg_cw_readback = 0;
#endif

#if (defined(MT6205B) || defined(MT6208)) && defined(MT6188_DEBUG_DUMP_LOG)
#error "No file system on MT6205!"
#endif

/* MT6188 Control Word */
#define CW(_A,_B)  (const)(uint8)((_A << 1) + _B)

/* General propose constant */
#define MT6188                96    /// Device ID of MT6188 = 96
#define OP_WRITE              0     /// Write to MT6188
#define OP_READ               1     /// Read from MT6188
#define MT6188_WRITE          192
#define MT6188_READ           193
#define SET_FREQ_FAIL         -1
#define LO_INJECTION          0
#define HI_INJECTION          1
#define RSSI_CHECK_FAIL       2
#define FM_TUNER_GRID         100
#define PRESET_IF             280   /// Preset IF: 280 khz
#define IF_MEASURE_COUNT      3     /// 3 * 1.9 ms = 5.7 ms
#define VCO_LOCKING_TIME      4     /// 4 * 4.615 ms
#define CALIBRATION_FAIL_COUNT_THRESHOLD 5

#if !defined( MT6205B ) && !defined( MT6208 )
#define REF_CLK_32K
#define PRESET_IF_CNT         547   //280000*64/32768 = 546.875274   
#define PRESET_IF_DELTA_O     52
#define PRESET_IF_OFFSET      15	//offset 8Khz
#define IF_CONVERT_FACTOR     512   /// 32768 / 64 = 512
#else
#define USE_MT6188_AMP
#define REF_CLK_26M
#define PRESET_IF_CNT         529   //280000 * 49152 / 26000000 = 529.33 //265   
#define PRESET_IF_DELTA_O     50
#define PRESET_IF_OFFSET      15	//offset 8Khz
#define IF_CONVERT_FACTOR     529   /// 26000000 / 49152 = 529
#endif


#ifdef USE_MT6188_AMP
void ExtSwitchInit(void);
void SwitchExtFMPath(uint8 if_on);
#endif

/* Serial communication interfaces */
void  SerialCommInit(void);
void  SerialCommRelease(void);
void  SerialCommCryClkOn(void);
void  SerialCommCryClkOff(void);
void  GPIO_WriteIO(char data,char port);

#if defined USE_I2C
void  SerialCommStart(void);
void  SerialCommStop(void);
uint8 SerialCommTxByte(uint8 data);
void  SerialCommRxByte(uint8 *data, uint8 ack);
#elif defined USE_3_WIRE
uint8 SerialCommTxByte(uint8 cw, uint8 data);
void  SerialCommRxByte(uint8 cw, uint8 *data);
#endif

typedef struct {
   uint8 addr;
   uint8 value;
} ctrl_word_setting;

typedef struct {
   uint8 addr;
   uint8 and;
   uint8 or;
} ctrl_word_operation;

extern uint8 const FM_RADIO_INPUT_LEVEL_THRESHOLD;
void FMDrv_Mute(uint8 mute);
void FMDrv_EvaluateRSSIThreshold(void);

/// Global variables for current FM status
static int16 _current_frequency = -1;
static uint8 _current_level = 0x80;
static bool  _is_fm_on = false;
static bool  _is_fm_mute = false;
static uint8 _rssi_threshold;
static uint8 _valid_rssi = 0;
static uint16 PRESET_IF_CNT_PLUS;		            //add to adjust IF rounding
static uint8 PRESET_IF_DELTA = PRESET_IF_DELTA_O;
static uint8 RSSI_offset = 0;                       //RSSI_offset;
static uint8 _rssi_threshold = 0;                   //FM_RADIO_INPUT_LEVEL_THRESHOLD for engineer mode;
static uint8 mono_flag = 0;
static uint8 Chip_ID = 0;


#ifdef MT6188_DEBUG_DUMP_LOG
extern uint32 video_get_current_time(void);
extern uint32 video_get_duration_ms(uint32 t1);
static kal_uint8 _file_name[] = {"D\0:\0\\\0f\0m\0_\0l\0o\0g\0.\0t\0x\0t\0\0\0"};
static uint32 _data_written;
static uint8  _dbg_str[128];
static FS_HANDLE  _file_handle = 0;

static kal_uint8 _channel_name[] = {"D\0:\0\\\0l\0i\0s\0_\0l\0o\0g\0.\0t\0x\0t\0\0\0"};
static uint32 _list_written;
static uint8  _list_str[128];
static FS_HANDLE  _file_list = 0;
#endif

static void MT6188_Mute(uint8 mute);
void FMDrv_EvaluateRSSIThreshold(void);

// enginner mode struct
typedef enum group_idx {
	   mono=0,
	   stereo,
	   RSSI_threshold,
	   IF_count_delta,
	   GROUP_TOTAL_NUMS
	} FACTORY_GROUP_ENUM;
	
typedef enum item_idx {
	   Sblend_OFF=0,
	   Sblend_ON,  
	   ITEM_TOTAL_NUMS
	} FACTORY_ITEM_INDEX;
// enginner mode struct

#define POWER_ON_COMMAND_COUNT_V5 62
static const ctrl_word_setting PowerOnSetting_V5[POWER_ON_COMMAND_COUNT_V5] = {
   { CW(   1, 1),    5 },
   { CW(   2, 1),   64 },{ CW(   2, 0),    4 },
   { CW(   3, 1),   28 },{ CW(   3, 0),   49 },
   { CW(   4, 1),  128 },{ CW(   4, 0),  175 },//cw(4,0)199
   { CW(   5, 1),  228 },{ CW(   5, 0),   47 },  //cw(5,0)175
   { CW(   7, 1),    0 },{ CW(   7, 0),  119 },
   { CW(   8, 1),  134 },{ CW(   8, 0),   89 }, 
   { CW(   9, 1),  152 },{ CW(   9, 0),   18 },
   { CW(  10, 1),   8 },{ CW(  10, 0),    3 },
   { CW(  11, 1),  129 },{ CW(  11, 0),    5 },
   { CW(  12, 1),    4 },{ CW(  12, 0),    3 },//cw(13, 0)136
   { CW(  13, 1),   32 },{ CW(  13, 0),  137 },//cw(14,0)254,110
   { CW(  14, 1),  255 },{ CW(  14, 0),  255 },
   { CW(  15, 1),  192 },{ CW(  15, 0),    8 },//cw(17, 1)40
   { CW(  16, 1),    8 },{ CW(  16, 0),  104 },
   { CW(  17, 1),   76 },{ CW(  17, 0),   14 },//cw(18, 0)0
   { CW(  18, 1),    6 },{ CW(  18, 0),  130 },//cw(19, 0)16
   { CW(  19, 1),    3 },{ CW(  19, 0),   56 },
   { CW(  21, 1),  167 },{ CW(  21, 0),   69 },//cw(23, 0)239/233
   { CW(  22, 1),  196 },{ CW(  22, 0),    7 },
   { CW(  23, 1),   76 },{ CW(  23, 0),  233 },
   { CW(  24, 1),    3 },{ CW(  24, 0),    0 },
   { CW(  30, 1),  136 },{ CW(  30, 0),  136 },
   { CW(  31, 1),    0 },{ CW(  31, 0),    0 },
   { CW(  32, 1),    0 },{ CW(  32, 0),    0 },
   { CW(  33, 1),    0 },{ CW(  33, 0),    0 },//cw(23, 0)239/233
   { CW(  34, 1),    0 },{ CW(  34, 0),    1 },
   { CW(  97, 1),   16 },{ CW(  97, 0),    0 },
   { CW(  98, 1),  128 },{ CW(  98, 0),    0 },
   { CW(  99, 1),  128 },{ CW(  99, 0),    0 },
   			 { CW( 101, 0),    4 },
   { CW( 103, 1),    4 },{ CW( 103, 0),   32 },
};

#define POWER_ON_COMMAND_COUNT_V4 52
static const ctrl_word_setting PowerOnSetting_V4[POWER_ON_COMMAND_COUNT_V4] = {
   { CW(  1, 1),  0 },	{ CW(  1, 0),  10 },
   { CW(  2, 1),  64 },	{ CW(  3, 1),  28 },
   { CW(  3, 0),  53 },	{ CW(  4, 1),  128 },
   { CW(  4, 0),  183 },{ CW(  5, 1),  100 },//cw(4,0)199
   { CW(  5, 0),  175 },{ CW(  7, 1),  0 },  //cw(5,0)175
   { CW(  7, 0),  247 },{ CW(  8, 1),  134 },
   { CW(  8, 0),  89 }, { CW(  9, 1),  152 },
   { CW(  9, 0),  18 }, { CW(  10, 1), 0 }, 
   { CW(  10, 0), 3 },  { CW(  11, 1), 1 },
   { CW(  11, 0), 5 },	{ CW(  12, 1), 4 },
   { CW(  12, 0), 3 },	{ CW(  13, 1), 0 },
   { CW(  13, 0), 0 },{ CW(  14, 1), 255 },//cw(13, 0)136
   { CW(  14, 0), 246 },{ CW(  15, 1), 255 },//cw(14,0)254,110
   { CW(  15, 0), 252 },{ CW(  16, 1), 108 },
   { CW(  16, 0), 108 },{ CW(  17, 1), 72 },//cw(17, 1)40
   { CW(  17, 0), 204 },{ CW(  18, 1), 6 },
   { CW(  18, 0), 34 },	{ CW(  19, 1), 3 },//cw(18, 0)0
   { CW(  19, 0), 92 }, { CW(  21, 1), 0 },//cw(19, 0)16
   { CW(  21, 0), 26 }, { CW(  22, 1), 0 },
   { CW(  22, 0), 2 },  { CW(  23, 1), 3 },
   { CW(  23, 0), 228 },{ CW(  24, 1), 3 },//cw(23, 0)239/233
   { CW(  24, 0), 0 },	{ CW(  97, 1), 16 },
   { CW(  97, 0), 0 },	{ CW(  98, 1), 128 },
   { CW(  98, 0), 0 },	{ CW(  99, 1), 128 },
   { CW(  99, 0), 0 },	{ CW(  101,0), 4 },
   { CW(  103,1), 4 },	{ CW(  103,0), 32 },
};

#define POWER_ON_COMMAND_COUNT_V3 48
static const ctrl_word_setting PowerOnSetting_V3[POWER_ON_COMMAND_COUNT_V3] = {
   { CW(  1, 1),  0 },	{ CW(  1, 0),  10 },
   { CW(  2, 1),  64 },	{ CW(  3, 1),  28 },
   { CW(  3, 0),  53 },	{ CW(  4, 1),  128 },
   { CW(  4, 0),  199 },{ CW(  5, 1),  100 },
   { CW(  5, 0),  175 },{ CW(  7, 1),  0 },  //cw(5,0)175
   { CW(  7, 0),  247 },{ CW(  8, 1),  134 },
   { CW(  8, 0),  89 }, { CW(  9, 1),  152 },
   { CW(  9, 0),  18 }, { CW(  10, 1), 0 }, 
   { CW(  10, 0), 3 },  { CW(  11, 1), 1 },
   { CW(  11, 0), 5 },	{ CW(  12, 1), 4 },
   { CW(  12, 0), 3 },	{ CW(  13, 1), 0 },
   { CW(  13, 0), 136 },{ CW(  14, 1), 255 },
   { CW(  14, 0), 110 },{ CW(  15, 1), 255 },//cw(14,0)254
   { CW(  15, 0), 252 },{ CW(  16, 1), 108 },
   { CW(  16, 0), 108 },{ CW(  17, 1), 40 },
   { CW(  17, 0), 204 },{ CW(  18, 1), 6 },
   { CW(  18, 0), 0 },	{ CW(  19, 1), 3 },
   { CW(  19, 0), 16 }, { CW(  23, 1), 3 },
   { CW(  23, 0), 239 },{ CW(  24, 1), 3 },
   { CW(  24, 0), 0 },	{ CW(  97, 1), 16 },
   { CW(  97, 0), 0 },	{ CW(  98, 1), 128 },
   { CW(  98, 0), 0 },	{ CW(  99, 1), 128 },
   { CW(  99, 0), 0 },	{ CW(  101,0), 4 },
   { CW(  103,1), 4 },	{ CW(  103,0), 32 },
}; 


#define POWER_OFF_COMMAND_COUNT 2
static const ctrl_word_operation PowerOffProc[POWER_OFF_COMMAND_COUNT] = {
   { CW(  1, 1), 0xBF, 0x40 },	//CW1_1		[6:6]	1
   { CW(  1, 1), 0x9F, 0x20 },	//CW1_1		[6:5]	1	
};

// start chip ID = 5
#define CAL_PRESET_COUNT_V5 28
static const ctrl_word_operation CalPresetProcess_V5[CAL_PRESET_COUNT_V5] = {
   { CW( 14, 0), 0x7F, 0x00 },	//CW14_0	[7:7]	0  	//S_AUTO,STEREO
   { CW( 14, 0), 0xEF, 0x10 },	//CW14_0	[4:4]	1
   { CW(  5, 1), 0xFB, 0x04 },	//CW5_1		[2:2]	1	//Window_L
   { CW(  3, 0), 0xF8, 0x05 },	//CW3_0		[2:0]	5	//AMP_P,S_DIV_3
   { CW(  3, 0), 0xFE, 0x01 },	//CW3_0		[0:0]	1	//S_DIV_256,S_DIV_128,S_DIV_3
   { CW(  3, 1), 0xE3, 0x1C },	//CW3_1		[4:2]	7	//ISEL
   { CW( 12, 0), 0xFE, 0x01 },	//CW12_0	[0:0]	1	//PLL19K_P
   { CW( 12, 0), 0xFD, 0x02 },	//CW12_0	[1:1]	1	//PLL_19K_P
   { CW(  7, 0), 0xE0, 0x17 },	//CW7_0		[4:0]	23	//VCO_PW,PRE_PW,LO_PW,VER
   { CW( 10, 1), 0xDF, 0x20 },	//CW10_1	[5:5]	1	//FRCKTEST
   { CW( 12, 1), 0xEF, 0x00 },	//CW12_1	[4:4]	0	//EN_TESTMODE_PLL19K
   { CW( 12, 1), 0x1F, 0x00 },	//CW12_1	[7:5]	0	//TEST_OUTSEL_19K[2:0]
   { CW(  6, 1), 0x0F, 0x10 },	//CW6_1		[7:4]	1	//TAR[3:0]
   { CW(  7, 1), 0xFC, 0x00 },	//CW7_1		[1:0]	0	//CAL[1:0]
   { CW( 13, 0), 0x00, 0x88 },	//CW13_0	[7:0]	136	//pilot
   { CW( 97, 1), 0xE0, 0x10 },	//CW97_1	[4:0]	16	//FRTUNE1[4:0]
   { CW( 97, 0), 0xE0, 0x00 },	//CW97_0	[4:0]	0	//FRTUNE2[4:0]
   { CW( 98, 1), 0x00, 0x80 },	//CW98_1	[7:0]	128	//DMTUNE1I[7:0]
   { CW( 98, 0), 0x00, 0x00 },	//CW98_0	[7:0]	0	//DMTUNE2I[3:0]
   { CW( 99, 1), 0x00, 0x80 },	//CW99_1	[7:0]	128	//DMTUNE1Q[7:0]
   { CW( 99, 0), 0xF0, 0x00 },	//CW99_0	[3:0]	0	//DMTUNE2Q[3:0]
   { CW(101, 0), 0xF8, 0x04 },	//CW101_0	[2:0]	4	//LPF[2:0]
   { CW(103, 1), 0x00, 0x04 },	//CW103_1	[7:0]	4	//FB_19K2[2:0]
   { CW(103, 0), 0x00, 0x20 },	//CW103_0	[7:0]	32	//IBAND_19K2[5:0]
#if defined   REF_CLK_32K //==============================================
   { CW(  3, 0), 0x1F, 0x20 }, 	//CW3_0		[7:5]  	1, 
#elif defined REF_CLK_13M
   { CW(  3, 0), 0x1F, 0x40 }, 	//CW3_0    	[7:5]  	2, 
#elif defined REF_CLK_26M
   { CW(  3, 0), 0x1F, 0xC0 }, 	//CW3_0    	[7:5]  	6, 
#endif //=================================================================
#if defined   REF_CLK_32K //==============================================
   { CW(  2, 1), 0xBF, 0x40 }, 	//CW2_1    	[6:6]  	1	//INSEL 
#else
   { CW(  2, 1), 0xBF, 0x00 }, 	//CW2_1    	[6:6]  	0	//INSEL
#endif   	
   { CW(  5, 1), 0x7F, 0x00 },	//CW5_1		[7:7]	0	//PRE_CH
   { CW(  8, 0), 0xF7, 0x08 },	//CW8_0		[3:3]	1	//AFC_CAL
};
// end chip ID = 5

#define CAL_PRESET_COUNT 27
static const ctrl_word_operation CalPresetProcess[CAL_PRESET_COUNT] = {
   { CW( 14, 0), 0x7F, 0x00 },	//CW14_0	[7:7]	0  	//S_AUTO,STEREO
   { CW( 14, 0), 0xEF, 0x10 },	//CW14_0	[4:4]	1
   { CW(  5, 1), 0xFB, 0x04 },	//CW5_1		[2:2]	1	//Window_L
   { CW(  3, 0), 0xF8, 0x05 },	//CW3_0		[2:0]	5	//AMP_P,S_DIV_3
   { CW(  3, 0), 0xFE, 0x01 },	//CW3_0		[0:0]	1	//S_DIV_256,S_DIV_128,S_DIV_3
   { CW(  3, 1), 0xE3, 0x1C },	//CW3_1		[4:2]	7	//ISEL
   { CW( 12, 0), 0xFE, 0x01 },	//CW12_0	[0:0]	1	//PLL19K_P
   { CW( 12, 0), 0xFD, 0x02 },	//CW12_0	[1:1]	1	//PLL_19K_P
   { CW(  7, 0), 0xE0, 0x17 },	//CW7_0		[4:0]	23	//VCO_PW,PRE_PW,LO_PW,VER
   { CW( 10, 1), 0xDF, 0x20 },	//CW10_1	[5:5]	1	//FRCKTEST
   { CW( 12, 1), 0xEF, 0x00 },	//CW12_1	[4:4]	0	//EN_TESTMODE_PLL19K
   { CW( 12, 1), 0x1F, 0x00 },	//CW12_1	[7:5]	0	//TEST_OUTSEL_19K[2:0]
   { CW(  6, 1), 0x0F, 0x10 },	//CW6_1		[7:4]	1	//TAR[3:0]
   { CW(  7, 1), 0xFC, 0x00 },	//CW7_1		[1:0]	0	//CAL[1:0]
   { CW( 97, 1), 0xE0, 0x10 },	//CW97_1	[4:0]	16	//FRTUNE1[4:0]
   { CW( 97, 0), 0xE0, 0x00 },	//CW97_0	[4:0]	0	//FRTUNE2[4:0]
   { CW( 98, 1), 0x00, 0x80 },	//CW98_1	[7:0]	128	//DMTUNE1I[7:0]
   { CW( 98, 0), 0x00, 0x00 },	//CW98_0	[7:0]	0	//DMTUNE2I[3:0]
   { CW( 99, 1), 0x00, 0x80 },	//CW99_1	[7:0]	128	//DMTUNE1Q[7:0]
   { CW( 99, 0), 0xF0, 0x00 },	//CW99_0	[3:0]	0	//DMTUNE2Q[3:0]
   { CW(101, 0), 0xF8, 0x04 },	//CW101_0	[2:0]	4	//LPF[2:0]
   { CW(103, 1), 0x00, 0x04 },	//CW103_1	[7:0]	4	//FB_19K2[2:0]
   { CW(103, 0), 0x00, 0x20 },	//CW103_0	[7:0]	32	//IBAND_19K2[5:0]
#if defined   REF_CLK_32K //==============================================
   { CW(  3, 0), 0x1F, 0x20 }, 	//CW3_0		[7:5]  	1, 
#elif defined REF_CLK_13M
   { CW(  3, 0), 0x1F, 0x40 }, 	//CW3_0    	[7:5]  	2, 
#elif defined REF_CLK_26M
   { CW(  3, 0), 0x1F, 0xC0 }, 	//CW3_0    	[7:5]  	6, 
#endif //=================================================================
#if defined   REF_CLK_32K //==============================================
   { CW(  2, 1), 0xBF, 0x40 }, 	//CW2_1    	[6:6]  	1	//INSEL 
#else
   { CW(  2, 1), 0xBF, 0x00 }, 	//CW2_1    	[6:6]  	0	//INSEL
#endif   	
   { CW(  5, 1), 0x7F, 0x00 },	//CW5_1		[7:7]	0	//PRE_CH
   { CW(  8, 0), 0xF7, 0x08 },	//CW8_0		[3:3]	1	//AFC_CAL
};

#define CAL_PLL_COMMAND_COUNT 21
static const ctrl_word_operation CalPLLProcess[CAL_PLL_COMMAND_COUNT] = {
   { CW( 12, 1), 0xFC, 0x03 }, 	//CW12_1   	[1:0]  	3	
   { CW(  6, 0), 0xFC, 0x01 }, 	//CW6_0    	[1:0]  	1	//WIN_S[1:0],set window source
   { CW(  7, 1), 0xFC, 0x03 }, 	//CW7_1    	[1:0]  	3	//CAL[1:0],Enable calibration
   { CW(  6, 1), 0x00, 0x66 }, 	//CW6_1    	[7:0]	102	//CNT_S, set clock source
   { CW( 25, 1), 0x00, 0x03 }, 	//CW25_1   	[7:0] 	3	//CNT_T[11:8], set target value
#if defined   REF_CLK_32K //==============================================
   { CW( 25, 0), 0x00, 0x7A }, 	//CW25_0   	[7:0] 	122	//CNT_T[7:0], set target value
#elif defined REF_CLK_13M
   { CW( 25, 0), 0x00, 0x5E }, 	//CW25_0   	[7:0]  	94
#elif defined REF_CLK_26M
   { CW( 25, 0), 0x00, 0x5E }, 	//CW25_0   	[7:0]  	94
#endif //=================================================================
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0    	[7:0]   0	//Clear all Flag register
   { CW(  6, 1), 0xFE, 0x01 }, 	//CW6_1    	[0:0]   1	//WIN_EN, start calibration
   { CW(127, 1), 0x00, 0x01 }, 	// <----------------- polling SARIFG
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0    	[7:0]   0	//reset CW1_0
   { CW(  6, 1), 0x00, 0x76 }, 	//CW6_1    	[7:0]   118	//CNT_S, set clock source
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0    	[7:0]   0	//Clear all Flag register
   { CW(  6, 1), 0xFE, 0x01 }, 	//CW6_1    	[0:0]   1	//WIN_EN, start calibration
   { CW(127, 1), 0x00, 0x01 }, 	// <----------------- polling SARIFG
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0    	[7:0]   0	//reset CW1_0
   { CW(  6, 1), 0x00, 0x56 }, 	//CW6_1    	[7:0]   86	//CAL, Enable calibration	
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0    	[7:0]   0	//Clear all Flag register
   { CW(  6, 1), 0xFE, 0x01 }, 	//CW6_1    	[0:0]   1	//WIN_EN, start calibration
   { CW(127, 1), 0x00, 0x01 }, 	// <----------------- polling SARIFG
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0    	[7:0]   0	//reset CW1_0
   { CW( 12, 1), 0xF8, 0x04 }, 	//CW12_1   	[2:0]   4	//Set Divided vaule=24 and disable calibration mode of PLL19K
};

#define CAL_DEMOD_I_COMMAND_COUNT 31
static const ctrl_word_operation CalDemodIProcess[CAL_DEMOD_I_COMMAND_COUNT] = {
   { CW(  8, 0), 0xFD, 0x02 }, 	//CW8_0   	[1:1]  1	//FM_CALI, Enalbe calibation mode of I  channel demodulator
   { CW(  8, 0), 0xFB, 0x04 }, 	//CW8_0   	[2:2]  1	//FM_CALQ, Enalbe calibation mode of Q channel demodulator
   { CW(  8, 0), 0xEF, 0x00 }, 	//CW8_0   	[4:4]  0	//DEM_RSB, Reset demodulator
   { CW(  8, 0), 0xEF, 0x10 }, 	//CW8_0   	[4:4]  1	//DEM_RSB, Reset demodulator
   { CW(  7, 1), 0xFC, 0x03 }, 	//CW7_1   	[1:0]  3	//CAL[1:0], Enable calibraton process
   { CW(  6, 0), 0xFC, 0x01 }, 	//CW6_0   	[1:0]  1	//WIN_S[1:0], Set window soure
   { CW(  6, 1), 0x00, 0xAA }, 	//CW6_1   	[7:0]  170	//CNTS[2:0],TAR[3:0], Set clock source and traget register
#if defined   REF_CLK_32K //==============================================
   { CW( 25, 0), 0x00, 0x45 }, 	//CW25_0  	[7:0]  69	//CNT_T[7:0]
#elif defined REF_CLK_13M
   { CW( 25, 0), 0x00, 0x23 }, 	//CW25_0  	[7:0]  35
#elif defined REF_CLK_26M
   { CW( 25, 0), 0x00, 0x23 }, 	//CW25_0  	[7:0]  35
#endif //=================================================================
   { CW( 25, 1), 0x00, 0x04 }, 	//CW25_1  	[7:0]  4+	//CNT_T[11:8]
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0   	[7:0]  0	//Clear all FLG registers
   { CW(  6, 1), 0xFE, 0x01 }, 	//CW6_1   	[0:0]  1	//WIN_EN, Start calibration process
   { CW(127, 1), 0x00, 0x01 }, 	// <----------------- polling SARIFG
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0   	[7:0]  0 	//reset CW1_0
   { CW(  6, 1), 0x00, 0xBA }, 	//CW6_1   	[7:0]  186	//CNTS[2:0],TAR[3:0],Set clock source and traget register   
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0   	[7:0]  0,	//Clear all FLG registers
   { CW(  6, 1), 0xFE, 0x01 }, 	//CW6_1   	[0:0]  1	//WIN_EN, Start calibration process 
   { CW(127, 1), 0x00, 0x01 }, 	// <----------------- polling SARIFG
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0   	[7:0]  0 	//reset CW1_0
   { CW(  6, 1), 0x00, 0xCC }, 	//CW6_1   	[7:0]  204	//CNTS[2:0],TAR[3:0],Set clock source and traget register   
#if defined   REF_CLK_32K //==============================================
   { CW( 25, 0), 0x00, 0xDA }, 	//CW25_0  	[7:0]  218	//CNT_T[7:0]
#elif defined REF_CLK_13M
   { CW( 25, 0), 0x00, 0xD4 }, 	//CW25_0  	[7:0]  212
#elif defined REF_CLK_26M
   { CW( 25, 0), 0x00, 0xD4 }, 	//CW25_0  	[7:0]  212
#endif //=================================================================
   { CW( 25, 1), 0x00, 0x00 }, 	//CW25_1  	[7:0]  0+	//CNT_T[11:8]
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0   	[7:0]  0	//Clear all FLG registers
   { CW(  6, 1), 0xFE, 0x01 }, 	//CW6_1   	[0:0]  1	//WIN_EN, Start calibration process
   { CW(127, 1), 0x00, 0x01 }, 	// <----------------- polling SARIFG
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0   	[7:0]  0 	//reset CW1_0
   { CW(  6, 1), 0x0F, 0xD0 }, 	//CW6_1   	[7:4]  13	//CNTS[2:0],TAR[3:0],Set clock source and traget register  
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0   	[7:0]  0	//Clear all FLG registers
   { CW(  6, 1), 0xFE, 0x01 }, 	//CW6_1   	[0:0]  1	//WIN_EN,Start calibration process 
   { CW(127, 1), 0x00, 0x01 }, 	// <----------------- polling SARIFG
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0   	[7:0]  0 	//reset CW1_0
   { CW(  8, 0), 0xF9, 0x00 }, 	//CW8_0   	[2:1]  0	//FM_CALI,Q, disable I, Q calibration mode
};

// start chip ID = 5
#define CHANNEL_FILTER_COUNT 13
static const ctrl_word_operation ChannelFilter[CHANNEL_FILTER_COUNT] = {
   { CW( 10, 1), 0xFE, 0x01 }, 	//CW10_0 	[0:0]   1	//Enable channel filter calibraton
   { CW(  7, 1), 0xFC, 0x03 }, 	//CW7_1 	[1:0]   3	//Enable calibraton process 
   { CW(  6, 0), 0xFC, 0x01 }, 	//CW6_0 	[1:0]   1	//Set window soure 
   { CW(  6, 1), 0x00, 0x28 }, 	//CW6_1 	[7:0]   40	//Set clock ource and target register  
   { CW( 25, 1), 0x00, 0x00 }, 	//CW25_1 	[7:0]   0	// 
   { CW( 25, 0), 0x00, 0x31 }, 	//CW25_0 	[7:0]   49	//(Please set this field as an user-defined value on the control program) 
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0 	[7:0]   0	//Clear all FLG registers 
   { CW(  6, 1), 0xFE, 0x01 }, 	//CW6_1 	[0:0]   1	//Start calibration process 
   { CW(127, 1), 0x00, 0x01 }, 	// <----------------- polling SARIFG
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0   	[7:0]  0 	//reset CW1_0
   { CW(  6, 1), 0x0F, 0x10 }, 	//CW6_1 	[7:4]   1	//Set clock source and target register 
   { CW(  7, 1), 0xFC, 0x00 }, 	//CW7_1 	[1:0]   0	//Disable calibration process 
   { CW( 10, 1), 0xFE, 0x00 }, 	//CW10_1 	[0:0]   0	//Disable channel filter calibraton  
};

#define MUXOFF_MN_COUNT 24
static const ctrl_word_operation MuxOff_MN[MUXOFF_MN_COUNT] = {
   { CW(  8, 0), 0xFE, 0x00 }, 	//CW8_0 	[0:0]   0	//Turn off Demod.
   { CW( 15, 0), 0xFD, 0x02 }, 	//CW15_0 	[1:1]   1	//Enable MUX calibraton (MUX_CON_CAL)
   { CW( 11, 1), 0x3F, 0x80 }, 	//CW11_1 	[7:6]   2	//Gain option (D2S_MODE, I2V_MODE)
   { CW( 14, 0), 0x6F, 0x00 }, 	//CW14_0 	[7,4]   	//Force mono mode
   { CW( 11, 1), 0xFB, 0x00 }, 	//CW11_1 	[2:2]   0	//Enable MUX mono calibration (ST_CAL) 
   { CW( 18, 1), 0x3F, 0x80 }, 	//CW18_1 	[7:6]   2	//Enable MUX L calibration (MUXLOFFCAL, TEST_LCH)
   { CW( 19, 1), 0x8F, 0x10 }, 	//CW19_1 	[6:4]   1	//Enable MUX L calibration (MUXLOFFCAL, TEST_LCH)
   { CW( 14, 1), 0xFE, 0x00 }, 	//CW14_1 	[0:0]   0	//Turn off AMP1
   { CW(  7, 1), 0xFC, 0x03 }, 	//CW7_1   	[1:0]   3 	//Enable calibraton process
   { CW(  6, 0), 0xFC, 0x01 }, 	//CW6_0 	[1:0]   1	//Set window soure
   { CW(  6, 1), 0x00, 0x90 }, 	//CW6_1 	[7:0]   144	//Set clock ource and target register 
   { CW(  9, 0), 0xBF, 0x40 }, 	//CW9_0 	[6:6]   1	//
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0   	[7:0]   0 	//Clear all FLG registers
   { CW(  6, 1), 0xFE, 0x01 }, 	//CW6_1 	[0:0]   1	//Start calibration process
   { CW(127, 1), 0x00, 0x01 }, 	// <----------------- polling SARIFG
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0   	[7:0]  0 	//reset
   { CW( 18, 1), 0x3F, 0x40 }, 	//CW18_1 	[7:6]   1	//Enable MUX R calibration (MUXROFFCAL, TEST_RCH)
   { CW( 19, 1), 0x8F, 0x20 }, 	//CW19_1 	[6:4]   2	//Enable MUX R calibration (MUXROFFCAL, TEST_RCH)
   { CW(  6, 1), 0x00, 0xA0 }, 	//CW6_1 	[7:0]   160	//Set clock source and target register
   { CW(  9, 0), 0xBF, 0x40 }, 	//CW9_0 	[6:6]   1	// 
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0   	[7:0]   0 	//Clear all FLG registers
   { CW(  6, 1), 0xFE, 0x01 }, 	//CW6_1 	[0:0]   1	//Start calibration process
   { CW(127, 1), 0x00, 0x01 }, 	// <----------------- polling SARIFG
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0   	[7:0]  0 	//reset
};

#define MUXOFF_ST_COUNT 26
static const ctrl_word_operation MuxOff_ST[MUXOFF_ST_COUNT] = {
   { CW( 14, 0), 0x6F, 0x10 }, 	//CW14_0 	[4:4]   1	//Force stereo mode
   { CW( 11, 1), 0xFB, 0x04 }, 	//CW11_1 	[2:2]   1	//Enable MUX stereo calibration (ST_CAL)
   { CW( 18, 1), 0x3F, 0x80 }, 	//CW18_1 	[7:6]   2	//Enable MUX L calibration (MUXLOFFCAL, TEST_LCH)
   { CW( 19, 1), 0x8F, 0x10 }, 	//CW19_1 	[6:4]   1	//Enable MUX L calibration (MUXLOFFCAL, TEST_LCH)
   { CW(  6, 1), 0x00, 0xB0 }, 	//CW6_1 	[7:0]   176	//Set clock source and target register
   { CW(  9, 0), 0xBF, 0x40 }, 	//CW9_0 	[6:6]   1	//
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0   	[7:0]   0 	//Clear all FLG registers
   { CW(  6, 1), 0xFE, 0x01 }, 	//CW6_1 	[0:0]   1	//Start calibration process
   { CW(127, 1), 0x00, 0x01 }, 	// <----------------- polling SARIFG
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0   	[7:0]  0 	//reset
   { CW( 18, 1), 0x3F, 0x40 }, 	//CW18_1 	[7:6]   1	//Enable MUX R calibration (MUXROFFCAL, TEST_RCH)
   { CW( 19, 1), 0x8F, 0x20 }, 	//CW19_1 	[6:4]   2	//Enable MUX R calibration (MUXROFFCAL, TEST_RCH)
   { CW(  6, 1), 0x00, 0xC0 }, 	//CW6_1 	[7:0]   192	//Set clock source and target register
   { CW(  9, 0), 0xBF, 0x40 }, 	//CW9_0 	[6:6]   1	//
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0   	[7:0]   0 	//Clear all FLG registers
   { CW(  6, 1), 0xFE, 0x01 }, 	//CW6_1 	[0:0]   1	//Start calibration process
   { CW(127, 1), 0x00, 0x01 }, 	// <----------------- polling SARIFG
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0   	[7:0]   0 	//reset
   { CW(  6, 1), 0x0F, 0x10 }, 	//CW6_1 	[7:4]   1	//Set clock source and target register
   { CW(  7, 1), 0xFC, 0x00 }, 	//CW7_1 	[1:0]   0	//Disable calibration process
   { CW(  9, 0), 0xBF, 0x00 }, 	//CW9_0 	[6:6]   0	//Resume to default value
   { CW( 18, 1), 0x3F, 0x00 }, 	//CW18_1   	[7:6]   0 	//Disable MUX calibration 
   { CW( 19, 1), 0x8F, 0x00 }, 	//CW19_1 	[6:4]   0	//Disable MUX calibration 
   { CW( 11, 1), 0xFB, 0x00 }, 	//CW11_1   	[2:2]   0 	//Disable MUX stereo calibration (ST_CAL)
   { CW(  8, 0), 0xFE, 0x01 }, 	//CW8_0 	[0:0]   1	//Turn on Demod.
   { CW( 14, 1), 0xFE, 0x01 }, 	//CW14_1   	[0:0]   1 	//Turn on AMP1
};

#define PFOSC_560K_COUNT 26
static const ctrl_word_operation Pfosc_560K[PFOSC_560K_COUNT] = {
   { CW( 10, 0), 0xFE, 0x01 }, 	//CW10_0 	[0:0]   1	//Enable PTOSC calibraton and power on PTOSC
   { CW( 10, 0), 0xFD, 0x02 }, 	//CW10_0 	[1:1]   1	//Enable PTOSC calibraton and power on PTOSC
   { CW( 10, 0), 0xFD, 0x00 }, 	//CW10_0 	[1:1]   0	//Reset PTOSC
   { CW( 10, 0), 0xFD, 0x02 }, 	//CW10_0 	[1:1]   1	//Reset PTOSC
   { CW(  6, 1), 0x00, 0xEE }, 	//CW6_1 	[7:0]   238	//Set clock ource and target register 
   { CW( 25, 1), 0x00, 0x04 }, 	//CW25_1  	[7:0]   3+,4	//CNT_T[11:8]
#if defined   REF_CLK_32K //==============================================
   { CW( 25, 0), 0x00, 0x46 }, 	//CW25_0  	[7:0]  123,70	//CNT_T[7:0]
#elif defined REF_CLK_13M
   { CW( 25, 0), 0x00, 0x5E }, 	//CW25_0  	[7:0]  94
#elif defined REF_CLK_26M
   { CW( 25, 0), 0x00, 0x5E }, 	//CW25_0  	[7:0]  94
#endif //=================================================================
   { CW(  7, 1), 0xFC, 0x03 }, 	//CW7_0   	[1:0]   3 	//
   { CW(  3, 0), 0xEF, 0x10 }, 	//CW3_0 	[4:4]   1	//
   { CW(  5, 1), 0x7F, 0x00 }, 	//CW5_1   	[7:7]   0 	//
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0   	[7:0]   0 	//Clear all FLG registers
   { CW(  6, 1), 0xFE, 0x01 }, 	//CW6_1 	[0:0]   1	//Start calibration process
   { CW(127, 1), 0x00, 0x01 }, 	// <----------------- polling SARIFG
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0   	[7:0]   0 	//reset
   { CW(  6, 1), 0x00, 0xFE }, 	//CW6_1 	[7:0]   254	//Set clock source and target register
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0   	[7:0]   0 	//Clear all FLG registers
   { CW(  6, 1), 0xFE, 0x01 }, 	//CW6_1 	[0:0]   1	//Start calibration process
   { CW(127, 1), 0x00, 0x01 }, 	// <----------------- polling SARIFG
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0   	[7:0]   0 	//reset
   { CW(  6, 1), 0x0F, 0x10 }, 	//CW6_1 	[7:4]   1	//Set clock source and target register
   { CW(  7, 1), 0xFC, 0x00 }, 	//CW7_1 	[1:0]   0	//Disable calibration process
   { CW(  3, 0), 0xEF, 0x00 }, 	//CW3_0   	[4:4]   0 	//Disable RFPLL calibration mode
   { CW(  5, 1), 0x7F, 0x80 }, 	//CW5_1 	[7:7]   1	//PRE_CH=1
   { CW(  3, 0), 0xEF, 0x10 }, 	//CW3_0   	[4:4]   1 	//CAL_PLL=1
   { CW( 14, 0), 0xF7, 0x08 }, 	//CW14_0 	[3:3]   1	//SMUTE=1
   { CW( 34, 0), 0xFE, 0x01 }, 	//CW34_0 	[0:0]   1	//
};

#define SM_CAL_OFFSET_COUNT 20
static const ctrl_word_operation SM_Cal_Offset[SM_CAL_OFFSET_COUNT] = {
   { CW( 22, 1), 0xFE, 0x01 }, 	//CW22_1  	[0:0]   1	//
   { CW( 17, 1), 0x7F, 0x00 }, 	//CW17_1   	[7:7]   0 	//
   { CW( 18, 0), 0xF7, 0x00 }, 	//CW18_0 	[3:3]   0	//
   { CW( 18, 1), 0xF7, 0x00 }, 	//CW18_1   	[3:3]   0 	//
   { CW(  6, 1), 0x0F, 0x10 }, 	//CW6_1 	[7:4]   1	//Set clock source and target register
   { CW(  7, 1), 0xFC, 0x00 }, 	//CW7_1   	[1:0]   0 	//Disable calibration process
   { CW(101, 1), 0xF0, 0x08 }, 	//CW101_1 	[3:0]   8	//
   { CW( 19, 0), 0xFD, 0x02 }, 	//CW19_0   	[1:1]   1 	//Enable and wait 20ms
   { CW(  7, 1), 0xFC, 0x03 }, 	//CW7_1 	[1:0]   3	//Enable calibration process
   { CW(  6, 1), 0x00, 0x40 }, 	//CW6_1 	[7:0]   64	//Set clock source and target register
   { CW(  9, 0), 0xBF, 0x00 }, 	//CW9_0   	[6:6]   0 	//
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0   	[7:0]   0 	//Clear all FLG registers
   { CW(  6, 1), 0xFE, 0x01 }, 	//CW6_1 	[0:0]   1	//Start calibration process
   { CW(127, 1), 0x00, 0x01 }, 	// <----------------- polling SARIFG
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0   	[7:0]   0 	//reset
   { CW(  6, 1), 0x0F, 0x10 }, 	//CW6_1 	[7:4]   1	//Set clock source and target register
   { CW(  7, 1), 0xFC, 0x00 }, 	//CW7_1 	[1:0]   0	//Disable calibration process
   { CW(  9, 0), 0xBF, 0x00 }, 	//CW9_0   	[6:6]   0 	//Resume to default value
   { CW( 19, 0), 0xFD, 0x00 }, 	//CW19_0 	[1:1]   0	//
   { CW( 22, 1), 0xFE, 0x00 }, 	//CW22_1   	[0:0]   0 	//
};

#define SM_CAL_SLOPE_COUNT 20
static const ctrl_word_operation SM_Cal_Slope[SM_CAL_SLOPE_COUNT] = {
   { CW( 22, 1), 0xFE, 0x01 }, 	//CW22_1  	[0:0]   1	//
   { CW( 17, 1), 0x7F, 0x00 }, 	//CW17_1   	[7:7]   0 	//
   { CW( 18, 0), 0xF7, 0x08 }, 	//CW18_0 	[3:3]   1	//
   { CW( 18, 1), 0xF7, 0x00 }, 	//CW18_1   	[3:3]   0 	//
   { CW( 19, 0), 0xFC, 0x03 }, 	//CW19_0 	[1:0]   3	//
   { CW(  6, 1), 0x00, 0x80 }, 	//CW6_1   	[7:0]   128 	//Set clock source and target register
   { CW(  9, 0), 0xBF, 0x40 }, 	//CW9_0   	[6:6]   1 	//
   { CW(  7, 1), 0xFC, 0x03 }, 	//CW7_1 	[1:0]   3	//Enable calibration process
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0   	[7:0]   0 	//Clear all FLG registers
   { CW(  6, 1), 0xFE, 0x01 }, 	//CW6_1 	[0:0]   1	//Start calibration process
   { CW(127, 1), 0x00, 0x01 }, 	// <----------------- polling SARIFG
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0   	[7:0]   0 	//reset
   { CW(  6, 1), 0x0F, 0x10 }, 	//CW6_1 	[7:4]   1	//Set clock source and target register
   { CW(  7, 1), 0xFC, 0x00 }, 	//CW7_1 	[1:0]   0	//Disable calibration process
   { CW(  9, 0), 0xBF, 0x00 }, 	//CW9_0   	[6:6]   0 	//Resume to default value
   { CW( 17, 1), 0x7F, 0x00 }, 	//CW17_1 	[7:7]   0	//
   { CW( 18, 0), 0xF7, 0x00 }, 	//CW18_0   	[3:3]   0 	//
   { CW( 18, 1), 0xF7, 0x00 }, 	//CW18_1 	[3:3]   0	//
   { CW( 19, 0), 0xFC, 0x00 }, 	//CW19_0 	[1:0]   0	//
   { CW( 22, 1), 0xFE, 0x00 }, 	//CW22_1   	[0:0]   0 	//
};

#define AAMP1_LCHOFF_MN_COUNT 21
static const ctrl_word_operation Aamp1_Lchoff_MN[AAMP1_LCHOFF_MN_COUNT] = {
   { CW( 19, 0), 0xFD, 0x02 }, 	//CW19_0  	[1:1]   1	//Feedthrough test signal
   { CW(  5, 0), 0xFD, 0x00 }, 	//CW5_0   	[1:1]   0 	//Turn off LNA input path
   { CW( 30, 1), 0x00, 0x00 }, 	//CW30_1   	[7:0]   0 	//
   { CW( 30, 0), 0x00, 0x00 }, 	//CW30_0   	[7:0]   0 	//
   { CW( 11, 1), 0x3F, 0x80 }, 	//CW11_1 	[7:6]   2	//Gain option (D2S_MODE, I2V_MODE)
   { CW( 14, 0), 0x6F, 0x00 }, 	//CW14_0 	[7,4]   	//Force mono mode
   { CW( 17, 0), 0x3F, 0x80 }, 	//CW17_0   	[7:6]   2 	//Enable AAMP1 L calibration
   { CW(  7, 1), 0xFC, 0x03 }, 	//CW7_0 	[1:0]   3	//Enable calibraton process
   { CW(  6, 0), 0xFC, 0x01 }, 	//CW6_0   	[1:0]   1 	//Set window soure
   { CW(  6, 1), 0x00, 0x00 }, 	//CW6_1   	[7:0]   0 	//Set clock source and target register (coarse tune)
   { CW(  9, 0), 0xBF, 0x40 }, 	//CW9_0 	[6:6]   1	//
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0   	[7:0]   0 	//Clear all FLG registers
   { CW(  6, 1), 0xFE, 0x01 }, 	//CW6_1 	[0:0]   1	//Start calibration process
   { CW(127, 1), 0x00, 0x01 }, 	// <----------------- polling SARIFG
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0   	[7:0]   0 	//reset
   { CW(  6, 1), 0x00, 0x10 }, 	//CW6_1 	[7:0]   16	//Set clock source and target register
   { CW(  9, 0), 0xBF, 0x40 }, 	//CW9_0   	[6:6]   1 	//
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0   	[7:0]   0 	//Clear all FLG registers
   { CW(  6, 1), 0xFE, 0x01 }, 	//CW6_1 	[0:0]   1	//Start calibration process
   { CW(127, 1), 0x00, 0x01 }, 	// <----------------- polling SARIFG
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0   	[7:0]   0 	//reset
};

#define AAMP1_RCHOFF_MN_COUNT 19
static const ctrl_word_operation Aamp1_Rchoff_MN[AAMP1_RCHOFF_MN_COUNT] = {
   { CW( 17, 0), 0x3F, 0x40 }, 	//CW17_0  	[7:6]   1	//Enable AAMP1 R calibration
   { CW(  6, 1), 0x00, 0x20 }, 	//CW6_1   	[7:0]   32 	//Set clock source and target register (coarse tune)
   { CW(  9, 0), 0xBF, 0x40 }, 	//CW9_0 	[6:6]   1	//
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0   	[7:0]   0 	//Clear all FLG registers
   { CW(  6, 1), 0xFE, 0x01 }, 	//CW6_1 	[0:0]   1	//Start calibration process
   { CW(127, 1), 0x00, 0x01 }, 	// <----------------- polling SARIFG
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0   	[7:0]   0 	//reset
   { CW(  6, 1), 0x00, 0x30 }, 	//CW6_1 	[7:0]   48	//Set clock source and target register
   { CW(  9, 0), 0xBF, 0x40 }, 	//CW9_0 	[6:6]   1	//
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0   	[7:0]   0 	//Clear all FLG registers
   { CW(  6, 1), 0xFE, 0x01 }, 	//CW6_1 	[0:0]   1	//Start calibration process
   { CW(127, 1), 0x00, 0x01 }, 	// <----------------- polling SARIFG
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0   	[7:0]   0 	//reset
   { CW(  6, 1), 0x0F, 0x10 }, 	//CW6_1 	[7:4]   1	//Set clock source and target register
   { CW(  7, 1), 0xFC, 0x00 }, 	//CW7_1   	[1:0]   0 	//Disable calibration process
   { CW(  9, 0), 0xBF, 0x00 }, 	//CW9_0   	[6:6]   0 	//Resume to default value
   { CW( 17, 0), 0x3F, 0x00 }, 	//CW17_0 	[7:6]   0	//Disable AAMP1 calibration
   { CW(  5, 0), 0xFD, 0x02 }, 	//CW5_0   	[1:1]   1 	//Turn on LNA input path
   { CW( 19, 0), 0xFD, 0x00 }, 	//CW19_0   	[1:1]   0 	//Disconnect test signal
};

#define CAL_PFOSC_COMMAND_COUNT_V5 22
static const ctrl_word_operation CalPfoscProcess_V5[CAL_PFOSC_COMMAND_COUNT_V5] = {
   { CW( 10, 0), 0xFE, 0x01 }, 	//CW10_0 	[0:0]   1	//RFOSC_P,FROSC_CAL 
   { CW( 10, 0), 0xFD, 0x02 }, 	//CW10_0 	[1:1]   1 	//Enable PTOSC calibraton and power on PTOSC
   { CW( 10, 0), 0xFD, 0x00 }, 	//CW10_0 	[1:1]   0 	//Reset PTOSC
   { CW( 10, 0), 0xFD, 0x02 }, 	//CW10_0 	[1:1]   1 	//Reset PTOSC
   { CW(  6, 1), 0x00, 0xEE }, 	//CW6_1   	[7:0]  	238	//Set clock ource and target register 
   { CW( 25, 1), 0x00, 0x03 }, 	//CW25_1  	[7:0]   3	//CNT_T_[11:8]
#if defined   REF_CLK_32K //==============================================
   { CW( 25, 0), 0x00, 0x7B }, 	//CW25_0  	[7:0]   123	//CNT_T_[7:0]
#elif defined REF_CLK_13M
   { CW( 25, 0), 0x00, 0x5E }, 	//CW25_0  	[7:0]   94
#elif defined REF_CLK_26M
   { CW( 25, 0), 0x00, 0x5E }, 	//CW25_0  	[7:0]   94
#endif //=================================================================
   { CW( 97, 0), 0x00, 0x08 }, 	//CW97_0 	[7:0]   8 	//
   { CW(  7, 1), 0xFC, 0x03 }, 	//CW7_0 	[1:0]   3 	//
   { CW(  3, 0), 0xEF, 0x10 }, 	//CW3_0   	[4:4]  	1	//
   { CW(  5, 1), 0x7F, 0x00 }, 	//CW5_1  	[7:7]   0	//
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0   	[7:0]   0
   { CW(  6, 1), 0xFE, 0x01 }, 	//CW6_1   	[0:0]   1	//WIN_EN
   { CW(127, 1), 0x00, 0x01 }, 	//<----------------- polling SARIFG
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0   	[7:0]   0 	//reset CW1_0
   { CW(  6, 1), 0x00, 0xFE }, 	//CW6_1   	[7:0]  	254	//Set clock source and target register
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0   	[7:0]   0
   { CW(  6, 1), 0xFE, 0x01 }, 	//CW6_1   	[0:0]   1	//WIN_EN
   { CW(127, 1), 0x00, 0x01 }, 	//<----------------- polling SARIFG
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0   	[7:0]   0 	//reset CW1_0
   { CW(  6, 1), 0x00, 0x82 }, 	//CW6_1   	[7:4]  	130	//Set clock source and target register
   { CW(  7, 1), 0xFC, 0x00 }, 	//CW7_1   	[1:0]   0	//Disable calibration process
//   { CW( 97, 0), 0xE0, 0x0F }, /// CW97_0  [4:0]  k=
//   { CW(  3, 0), 0xEF, 0x00 }, /// CW3_0   [4:4]   0   
};

#define CAL_DelayCalibration_COMMAND_COUNT_V5 18
static const ctrl_word_operation CalDelayCalibrationProcess_V5[CAL_DelayCalibration_COMMAND_COUNT_V5] = {
   { CW( 11, 1), 0xCF, 0x20 }, 	//CW11_1 	[5:4]   2	//Enable delay calibration loop 
   { CW(  6, 1), 0x0F, 0x80 }, 	//CW6_1 	[7:4]   8 	//Set target register(REFDI)
   { CW(  7, 1), 0xFC, 0x00 }, 	//CW7_1 	[1:0]   0 	//Disable calibration process
   { CW( 12, 1), 0xFC, 0x00 }, 	//CW12_1 	[1:0]   0 	//Enable PLL loop
   { CW(  6, 0), 0xFC, 0x01 }, 	//CW6_0   	[1:0]  	1	//Set windows source
   { CW(  7, 1), 0xFC, 0x03 }, 	//CW7_1  	[1:0]   3	//Enable calibration
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0   	[7:0]   0	//Clear all flag register
   { CW(  6, 1), 0xFE, 0x01 }, 	//CW6_1   	[0:0]   1	//Start calibration
   { CW(127, 1), 0x00, 0x01 }, 	//<----------------- polling SARIFG
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0   	[7:0]   0 	//reset CW1_0
   { CW(  6, 1), 0x0F, 0x90 }, 	//CW6_1   	[7:4]  	9	//Set target register(FBDI)
   { CW(  7, 1), 0xFC, 0x00 }, 	//CW7_1   	[1:0]   0	//Disable calibraton porcess
   { CW(  6, 0), 0xFC, 0x01 }, 	//CW6_0   	[1:0]   1	//Set windows source
   { CW(  7, 1), 0xFC, 0x03 }, 	//CW7_1   	[1:0]   3	//Enable calibration
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0   	[7:0]   0 	//Clear all FLAG register
   { CW(  6, 1), 0xFE, 0x01 }, 	//CW6_1   	[0:0]  	1	//Start calibration
   { CW(127, 1), 0x00, 0x01 }, 	//<----------------- polling SARIFG
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0   	[7:0]   0 	//reset CW1_0
//   { CW( 11, 1), 0xCF, 0x10 }, 	//CW11_1   	[5:4]  	0	//Disable delay calibration loop

};
//end chip ID = 5

#define CAL_PFOSC_COMMAND_COUNT 18
static const ctrl_word_operation CalPfoscProcess[CAL_PFOSC_COMMAND_COUNT] = {
   { CW( 10, 0), 0xFE, 0x01 }, 	//CW10_0 	[0:0]   1	//RFOSC_P,FROSC_CAL 
   { CW( 10, 0), 0xFD, 0x02 }, 	//CW10_0 	[1:1]   1 	//FROSC_CAL
   { CW( 10, 0), 0xFD, 0x00 }, 	//CW10_0 	[1:1]   0 
   { CW( 10, 0), 0xFD, 0x02 }, 	//CW10_0 	[1:1]   1 
   { CW(  6, 1), 0x00, 0xEE }, 	//CW6_1   	[7:0]  	238	//CNT_S[2:0],TAR[3:0]
   { CW( 25, 1), 0xF0, 0x03 }, 	//CW25_1  	[3:0]   3	//CNT_T_[11:8]
#if defined   REF_CLK_32K //==============================================
   { CW( 25, 0), 0x00, 0x7A }, 	//CW25_0  	[7:0]   122	//CNT_T_[7:0]
#elif defined REF_CLK_13M
   { CW( 25, 0), 0x00, 0x5E }, 	//CW25_0  	[7:0]   94
#elif defined REF_CLK_26M
   { CW( 25, 0), 0x00, 0x5E }, 	//CW25_0  	[7:0]   94
#endif //=================================================================
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0   	[7:0]   0
   { CW(  6, 1), 0xFE, 0x01 }, 	//CW6_1   	[0:0]   1	//WIN_EN
   { CW(127, 1), 0x00, 0x01 }, 	//<----------------- polling SARIFG
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0   	[7:0]   0 	//reset CW1_0
   { CW(  6, 1), 0x00, 0xFE }, 	//CW6_1   	[7:0]  	254	//CNT_S[2:0],TAR[3:0]
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0   	[7:0]   0
   { CW(  6, 1), 0xFE, 0x01 }, 	//CW6_1   	[0:0]   1	//WIN_EN
   { CW(127, 1), 0x00, 0x01 }, 	//<----------------- polling SARIFG
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0   	[7:0]   0 	//reset CW1_0
   { CW(  6, 1), 0x0F, 0x10 }, 	//CW6_1   	[7:4]  	1	//CNT_S[2:0],TAR[3:0]
   { CW(  7, 1), 0xFC, 0x00 }, 	//CW7_1   	[1:0]   0	//CAL[1:0]
//   { CW( 97, 0), 0xE0, 0x0F }, /// CW97_0  [4:0]  k=
//   { CW(  3, 0), 0xEF, 0x00 }, /// CW3_0   [4:4]   0   
};

#define CAL_DelayCalibration_COMMAND_COUNT 19
static const ctrl_word_operation CalDelayCalibrationProcess[CAL_DelayCalibration_COMMAND_COUNT] = {
   { CW( 11, 1), 0xCF, 0x20 }, 	//CW11_1 	[5:4]   2	//Enable delay calibration loop 
   { CW(  6, 1), 0x0F, 0x80 }, 	//CW6_1 	[7:4]   8 	//Set target register(REFDI)
   { CW(  7, 1), 0xFC, 0x00 }, 	//CW7_1 	[1:0]   0 	//Disable calibration process
   { CW( 12, 1), 0xFC, 0x00 }, 	//CW12_1 	[1:0]   0 	//Enable PLL loop
   { CW(  6, 0), 0xFC, 0x01 }, 	//CW6_0   	[1:0]  	1	//Set windows source
   { CW(  7, 1), 0xFC, 0x03 }, 	//CW7_1  	[1:0]   3	//Enable calibration
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0   	[7:0]   0	//Clear all flag register
   { CW(  6, 1), 0xFE, 0x01 }, 	//CW6_1   	[0:0]   1	//Start calibration
   { CW(127, 1), 0x00, 0x01 }, 	//<----------------- polling SARIFG
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0   	[7:0]   0 	//reset CW1_0
   { CW(  6, 1), 0x0F, 0x90 }, 	//CW6_1   	[7:4]  	9	//Set target register(FBDI)
   { CW(  7, 1), 0xFC, 0x00 }, 	//CW7_1   	[1:0]   0	//Disable calibraton porcess
   { CW(  6, 0), 0xFC, 0x01 }, 	//CW6_0   	[1:0]   1	//Set windows source
   { CW(  7, 1), 0xFC, 0x03 }, 	//CW7_1   	[1:0]   3	//Enable calibration
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0   	[7:0]   0 	//Clear all FLAG register
   { CW(  6, 1), 0xFE, 0x01 }, 	//CW6_1   	[0:0]  	1	//Start calibration
   { CW(127, 1), 0x00, 0x01 }, 	//<----------------- polling SARIFG
   { CW(  1, 0), 0x00, 0x00 }, 	//CW1_0   	[7:0]   0 	//reset CW1_0
   { CW( 11, 1), 0xCF, 0x10 }, 	//CW11_1   	[5:4]  	0	//Disable delay calibration loop

};


static uint8 MT6188_ReadCache(uint8 CW)
{
   if (CW < 58)
      return cw_cache[CW];
   else
      return cw_cache[CW-134];
}


static bool MT6188_ReadByte(uint8 CW, uint8 *data)
{
   if (CW == 255) {
      *data = 0;
      return true;
   }
#if defined USE_I2C
   SerialCommStart();                /// send the start sequence
   SerialCommTxByte(MT6188_WRITE);   /// device ID and R/W bit
   SerialCommTxByte(CW);             /// control word
   SerialCommStart();                /// resend the start sequence
   SerialCommTxByte(MT6188_READ);    /// device ID and R/W bit
   SerialCommRxByte(data, 0);        /// read data and send ACK
   SerialCommStop();                 /// send the stop sequence
#elif defined USE_3_WIRE
   SerialCommRxByte(CW, data);
#else
#error "Must define USE_I2C or USE_3_WIRE"
#endif

   return true;
}


/* MT6188 does not support sequential write. */
static bool MT6188_WriteByte(uint8 CW, uint8 data)
{
   if (CW == 255) {
      uint8 i = 0;
      uint8 dataRead;
      do {
         kal_sleep_task(1);
         MT6188_ReadByte(CW(1,0), &dataRead);
         if (i++ == 40) {
            return false;
         }
      } while ((dataRead & data)==0);
      return true;
   }
#if defined USE_I2C
   SerialCommStart();                /// send the start sequence
   SerialCommTxByte(MT6188_WRITE);   /// device ID and R/W bit
   SerialCommTxByte(CW);             /// control word   
   SerialCommTxByte(data);           /// data to be written
   SerialCommStop();                 /// send the stop sequence
#elif defined USE_3_WIRE
   SerialCommTxByte(CW, data);
#else
#error "Must define USE_I2C or USE_3_WIRE"
#endif

if (CW < 58)
      cw_cache[CW] = data;
   else
      cw_cache[CW-134] = data;


#if defined MT6188_DEBUG
   MT6188_ReadByte(CW, &dbg_cw_readback);
#endif
  
   return true;
}

#if defined MT6188_DEBUG
static void MT6188_DumpCtrlWord(void) {
   uint32 i;
   for (i=0; i<29; i++) 
   {
      MT6188_ReadByte((i<<1), &(cw_cache[i << 1]));
      MT6188_ReadByte((i<<1)+1, &(cw_cache[(i << 1)+1]));
   }

   for (i=96; i<104; i++) {
      MT6189_ReadByte((i<<1), &(cw_cache[(i-67) << 1]));
      MT6189_ReadByte((i<<1)+1, &(cw_cache[((i-67) << 1) + 1]));
   }
}
#endif

/***********************************************************************
*  Engineer mode function (API)
*
*  parameter-->group_idx: mono\stereo\RSSI_threshold\IF_count_delta
*              item_idx: sub select index
*              item_value: set parameter value
***********************************************************************/
void FMDrv_radio_item_info(kal_uint16 group_idx, kal_uint16 item_idx, kal_uint32 item_value)
{
	uint8 TmpReg,TmpReg1;
	
	SerialCommInit();
	switch (group_idx)
	{
		case mono:
			if(item_value == 1)
  			{
      				MT6188_ReadByte(CW(14, 0), &TmpReg1);
      				TmpReg1&=0x2F;
      				MT6188_WriteByte(CW(14, 0),TmpReg1|0x40);
      				mono_flag = 1;
      			}
      			else
      			{
      				MT6188_ReadByte(CW(14, 0), &TmpReg1);
      				TmpReg1&=0x2F;
      				MT6188_WriteByte(CW(14, 0),TmpReg1|0x80);
      				mono_flag = 2;
      			}
   
		break;
		case stereo:
			if(item_value == 0)
			{
				    MT6188_ReadByte(CW(14, 0), &TmpReg1);
      				TmpReg1&=0x2F;
      				MT6188_WriteByte(CW(14, 0),TmpReg1|0x40);
      				mono_flag = 1;
			}
			else
			{
				switch (item_idx)
				{
					case Sblend_ON:
						MT6188_ReadByte(CW(14, 0), &TmpReg1);
      					TmpReg1&=0x2F;
      					MT6188_WriteByte(CW(14, 0),TmpReg1|0xD0);
      					mono_flag = 3;
					break;
					case Sblend_OFF:
						MT6188_ReadByte(CW(14, 0), &TmpReg1);
      					TmpReg1&=0x2F;
      					MT6188_WriteByte(CW(14, 0),TmpReg1|0x90);
      					mono_flag = 4;
					break;
				}
			}
		break;
		case RSSI_threshold:
			if (item_value == 1)
		        	RSSI_offset = 1;
		    	else if (item_value == 2)
		        	RSSI_offset = 2;
		    	else if (item_value == 3)
		        	RSSI_offset = 3;
		    	else if (item_value == 4)
		        	RSSI_offset = 4;
		    	else if (item_value == 5)
		        	RSSI_offset = 5;
		    	else if (item_value == 6)
		        	RSSI_offset = 6;
		    	else
		    		RSSI_offset = 0;//FM_RADIO_INPUT_LEVEL_THRESHOLD;
		break;
		case IF_count_delta:
			if(item_value == 10)
			{
#if !defined( MT6205B ) && !defined( MT6208 )
				PRESET_IF_DELTA = 20;
#else
				PRESET_IF_DELTA = 19;
#endif
			}
			else if(item_value == 15)
			{
#if !defined( MT6205B ) && !defined( MT6208 )
				PRESET_IF_DELTA = 30;
#else
				PRESET_IF_DELTA = 28;
#endif
			}
			else if(item_value == 20)
			{
#if !defined( MT6205B ) && !defined( MT6208 )
				PRESET_IF_DELTA = 39;
#else
				PRESET_IF_DELTA = 38;
#endif
			}
			else if(item_value == 25)
			{
#if !defined( MT6205B ) && !defined( MT6208 )
				PRESET_IF_DELTA = 52;
#else
				PRESET_IF_DELTA = 50;
#endif
			}
			else if(item_value == 30)
			{
#if !defined( MT6205B ) && !defined( MT6208 )
				PRESET_IF_DELTA = 59;
#else
				PRESET_IF_DELTA = 58;
#endif
			}
			else
			{
#if !defined( MT6205B ) && !defined( MT6208 )
				PRESET_IF_DELTA = 39;
#else
				PRESET_IF_DELTA = 38;
#endif
			}
		break;
		
	}
	SerialCommRelease();
}

/***********************************************************************
*  Get RSSI Value (internal)
*
*  parameter-->
***********************************************************************/
static uint16 MT6188_GetCurRSSI(void)
{
   uint8 TmpReg;

   MT6188_ReadByte(CW(4, 1), &TmpReg);
   return (TmpReg & 0x1F);
}

/***********************************************************************
*  FM flag clear (internal)
*
*  parameter-->ReadClear: 0: read flag
*                         1: set flag to 0
***********************************************************************/
static uint8 MT6188_ReadIntFlags(bool ReadClear)
{
   uint8 TmpReg;
   MT6188_ReadByte(CW(1, 0), &TmpReg);
   if (ReadClear)
      MT6188_WriteByte(CW(1, 0), 0x00);
   return TmpReg;
}

/***********************************************************************
*  Get IF count (internal)
*
*  parameter-->early_check: 0: don't check IF_count variation
*                           1: check IF_count variation
*             Timing window for 32K clock: 64/32768 = 0.00195 second        
*             Timing window for 26M clock: 49152/26000000 = 0.00189 second  
***********************************************************************/
static int32 MT6188_GetCurIFCnt(uint8 count, uint8 early_check)
{
   uint32 CurIF = 0;
   uint32 WaitingCounter = 0;
   uint32 if_cnt;
   uint8  TmpReg;
   int32  i = (int32)count;
   int32  rssi_consecutive_fail = 0;
   int32  if_consecutive_fail = 0;


//	_valid_rssi = 0;
#ifdef MT6188_DEBUG_DUMP_LOG
   kal_sprintf((void*)_dbg_str, "   MT6188_GetCurIFCnt(%d, %d);\n   \0", count, early_check);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif
   
	MT6188_WriteByte(CW(24, 0), 0x00);	//Stop real-time calibration; disable 1-bit SAR

   	MT6188_WriteByte(CW(5, 1), (MT6188_ReadCache(CW(5, 1)) & 0xFB) | 0x04);	//CW5_1	[2:2]	0
   
   while (--i >= 0) 
    {
        if (Chip_ID == 5)
            MT6188_WriteByte(CW(21, 0), (MT6188_ReadCache(CW(21, 0)) & 0x7F) | 0x80);//enable IF counter
   	
	    MT6188_WriteByte(CW(6, 1), 0x14);
	    MT6188_WriteByte(CW(1, 0), 0x00);	//clear flag
	
      	MT6188_WriteByte(CW(7, 1), MT6188_ReadCache(CW(7, 1)) & 0xFC);
      	
      	MT6188_WriteByte(CW(6, 0), 0x01);
      	
      	MT6188_WriteByte(CW(1, 0), 0x00);
      	
      	MT6188_WriteByte(CW(1, 1), (MT6188_ReadCache(CW(1, 1)) & 0xF7) | 0x08);	//Enable IF counter interrupt
      	
      	MT6188_WriteByte(CW(20, 0), 0x00);	//clear IF counter
	    MT6188_WriteByte(CW(20, 1), 0x00);
      	

     	MT6188_WriteByte(CW(6, 1), (MT6188_ReadCache(CW(6, 1)) & 0xFE) | 0x01);	//Enable time window
     	
     	/// Make sure that the counting is done
      	do {
         	if (++WaitingCounter == 4096) {
            		ASSERT(0);
            		return 0;
         	}
         	MT6188_ReadByte(CW(1, 0), &TmpReg);
      	} while ((TmpReg & 0x08) == 0);
      	
      	MT6188_ReadByte(CW(20, 1), &TmpReg);
      	if_cnt = (TmpReg & 0x03);
      	if_cnt <<= 8;
      
      	MT6188_ReadByte(CW(20, 0), &TmpReg);
      	if_cnt += TmpReg;
      	     	
      	CurIF += if_cnt;
      	     	

     	MT6188_WriteByte(CW(6, 1), MT6188_ReadCache(CW(6, 1)) & 0xFE);	//Disable time window
     	
	    MT6188_WriteByte(CW(1, 0), 0x00);	//clear flag
     	      	
      	
#ifdef MT6188_DEBUG_DUMP_LOG
      kal_sprintf((void*)_dbg_str, "%d,\0", if_cnt);
      FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif


      if (early_check) 
      {
        
         if (if_cnt > (PRESET_IF_CNT + 120) ||
             if_cnt < (PRESET_IF_CNT - 120)) 
        {
            if (++if_consecutive_fail == 1) 
            {
               CurIF /= (count-i);
           
#ifdef MT6188_DEBUG_DUMP_LOG
               kal_sprintf((void*)_dbg_str, "\n   IF Early Check Fail!\n\0");
               FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif
               return -CurIF;
            }
         } 
         else 
         {
            if_consecutive_fail = 0;
         }
      }


    }
    
    CurIF = (CurIF/count);
    if (Chip_ID == 5)
        MT6188_WriteByte(CW(21, 0), 0x01);//disable IF counter
    
#ifdef MT6188_DEBUG_DUMP_LOG
   kal_sprintf((void*)_dbg_str, "\n   IF count returned: %d\n\0", CurIF);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif

   return CurIF;
}

/// Timing window for 32K clock: 64/32768 = 0.00195 second
/// Timing window for 26M clock: 49152/26000000 = 0.00189 second
static uint16 MT6188_GetCurIF(void)
{
   uint32 CurIF = MT6188_GetCurIFCnt(IF_MEASURE_COUNT,0);
   CurIF *= IF_CONVERT_FACTOR;
   CurIF += 500;
   CurIF /= 1000;
   return (uint16) CurIF;
}

/***********************************************************************
*  Set radio frequency (internal)
*
*  parameter-->CurFreq:set frequency
*              HiLoInj:set frequency is forward or backward
***********************************************************************/
static bool MT6188_SetFreq(int32 CurFreq, uint8 HiLoInj)
{
if (Chip_ID == 4 || Chip_ID ==5)       //MT6188_ECO_V4/MT6188D
{
	uint16 Divider, N2, Ns, Target;
	int32 CurFreqLSB,VCO_LSB=0,pf_LSB=0;
   	uint8  TmpReg;
   	uint16 WaitingCounter = 0,freq = 0,CurFreq_PLUS = 0;
uint32 save_irq_mask;

#ifdef MT6188_DEBUG_DUMP_LOG
   uint32 start_t, duration_t;
   kal_sprintf((void*)_dbg_str, "\nMT6188_SetFreq(%d, %d);\n\0", CurFreq, HiLoInj);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
   start_t = video_get_current_time();
#endif   
   
   	
   	_current_frequency = CurFreq/FM_TUNER_GRID;
	freq = CurFreq;

   	VCO_LSB = CurFreq;
   // Disable PLL calibration	
   {	   	
  
   	/// DividerNumber = (CurFreq +- PresetIF) * 4 / RefClock 
   	if (HiLoInj == LO_INJECTION) 
   	{
     	 	VCO_LSB -= PRESET_IF;
   	} 
   	else 
   	{
      		VCO_LSB += PRESET_IF;
   	}
   		VCO_LSB *= 4000;

#if defined   REF_CLK_32K
   	VCO_LSB += 16384;    	// rounding
   	VCO_LSB /= 32768;		// 1/32768
   	
   	pf_LSB = 3562;		//456*64*4/32.768
//   	pf_LSB += 64;		//rounding
//   	pf_LSB /= 128;		//64*4/32768
#else
   	VCO_LSB += 16927;    	// rounding
   	VCO_LSB /= 33854;	// 384/13000000
   	
   	pf_LSB = 3448;		// 456*64*4/(13000/384)
//   	pf_LSB += 66;		//rounding
//   	pf_LSB /= 132;		//64*384*4/13000000
#endif

//save_irq_mask=SaveAndSetIRQMask();        //Set IRQ to increase process speed   

	MT6188_WriteByte(CW(24, 0), 0x00);	//Stop real-time calibration

   	MT6188_WriteByte(CW(6, 1), MT6188_ReadCache(CW(6, 1)) & 0xFE);	//Reset to default without calibration   
	
   }	
   	
   	MT6188_ReadByte(CW(7, 0), &TmpReg);
   	TmpReg &= 0x1F;
   	if(CurFreq <= 84000)
   		MT6188_WriteByte(CW(7, 0), TmpReg|0xE0);  	// CW7_0  [7:5]  7
   	else if(CurFreq > 84000 && CurFreq <= 92000)
   		MT6188_WriteByte(CW(7, 0), TmpReg|0x60);  	// CW7_0  [7:5]  3
   	else if(CurFreq > 92000 && CurFreq <=100000)
   		MT6188_WriteByte(CW(7, 0), TmpReg|0x20);  	// CW7_0  [7:5]  1	
 	else if(CurFreq > 100000)
 		MT6188_WriteByte(CW(7, 0), TmpReg|0x00);  	// CW7_0  [7:5]  0
   	

   	MT6188_WriteByte(CW(5, 1), (MT6188_ReadCache(CW(5, 1)) & 0xFB) | 0x04);	//CW5_1		[2:2]	1	
   	
   	MT6188_WriteByte(CW(7, 1), MT6188_ReadCache(CW(7, 1)) & 0xFC);		//CW7_1		[1:0]	0	

  	
   	MT6188_WriteByte(CW(5, 1), (MT6188_ReadCache(CW(5, 1)) & 0x7F) | 0x80);	//CW5_1		[7:7]	1
   	
   	MT6188_WriteByte(CW(8, 0), (MT6188_ReadCache(CW(8, 0)) & 0xF7) | 0x08);	//CW8_0		[3:3]	1	

 		   	
   	/// DividerNumber = (CurFreq +- PresetIF) * 4 / RefClock 
   	if (HiLoInj == LO_INJECTION) 
   	{
     	 	CurFreq -= PRESET_IF;
   	} 
   	else 
   	{
      		CurFreq += PRESET_IF;
   	}
   		CurFreq *= 4000;
   		CurFreqLSB = CurFreq;

#if defined   REF_CLK_32K
	CurFreq += 262144;	// rounding
	CurFreq >>= 19;		// 1/16*32768
   	CurFreqLSB += 16384;    // rounding
   	CurFreqLSB /= 32768;	// 1/32768
   	
#else
	CurFreq += 270834;	// rounding
	CurFreq /= 541667; 	// 24/13000000
   	CurFreqLSB += 16927;    // rounding
   	CurFreqLSB /= 33854;	// 384/13000000
   	
#endif
   	
   	MT6188_WriteByte(CW(12, 1), (MT6188_ReadCache(CW(12, 1)) & 0xFC) | 0x03);  	// CW12_1  [1:0]  0x03	turn-on digital clock

   	MT6188_WriteByte(CW(100, 1), (MT6188_ReadCache(CW(100, 1)) & 0xC0) | 0x10);  	// CW100_1 [5:0]  0x10	Set DAC at half range
   	
   	MT6188_WriteByte(CW(100, 0), MT6188_ReadCache(CW(100, 0)) & 0xF8);  		// CW100_0 [2:0]  0	Set DAC at half range
 
   	MT6188_ReadByte(CW(4, 0), &TmpReg);
   	TmpReg &= 0x7F;
   	if (HiLoInj == LO_INJECTION) 
   	{		
   		MT6188_WriteByte(CW(4, 0), TmpReg);  	// CW4_0    [7:7] 0:Lside
   	}
   	else
   	{
   		MT6188_WriteByte(CW(4, 0), TmpReg|0x80);  // CW4_0  [7:7] 1:Hside
   	}
   	

   	MT6188_WriteByte(CW(9, 1), MT6188_ReadCache(CW(9, 1)) & 0xF9);  		// CW9_1    [2:1]  0x00	turn-off AFC loop
   	
   	MT6188_WriteByte(CW(2, 1), MT6188_ReadCache(CW(2, 1)) & 0xC0);  		// CW2_1  [5:0]  0x00	Fix VCO divider value for calibration
   	
   	MT6188_WriteByte(CW(2, 0), 0x04);  		// CW2_0  [7:0]  0x04	Fix original calibration speed
   	
   	MT6188_WriteByte(CW(18, 0), (MT6188_ReadCache(CW(18, 0)) & 0x7F) | 0x80);  	// CW18_0  [7:7] 0x80	Fix original calibration speed
   	
   	MT6188_WriteByte(CW(3, 0), (MT6188_ReadCache(CW(3, 0)) & 0xEF) | 0x10);  	// CW3_0   [4:4] 0x10	Disconnect RFPLL
   	
   	MT6188_WriteByte(CW(3, 0), (MT6188_ReadCache(CW(3, 0)) & 0xF8) | 0x05);  	// CW3_0   [2:0] 0x05	Turn-on reference clock path
   	
   	MT6188_WriteByte(CW(7, 1), (MT6188_ReadCache(CW(7, 1)) & 0xFC) | 0x03);  	// CW7_1   [1:0] 0x03  Calibration standby

   	MT6188_WriteByte(CW(6, 0), MT6188_ReadCache(CW(6, 0)) & 0xFC);  		// CW6_0   [1:0] 0x00  select calibration window
   	
   	MT6188_WriteByte(CW(6, 1), 0x00);  		// CW6_1   [7:0] 0x00  select calibratio MSB of VCO

	MT6188_WriteByte(CW(25, 0), (uint8)(CurFreq&0xFF));
   	MT6188_WriteByte(CW(25, 1), (uint8)(CurFreq>>8));  	// CW25   Set calibration target frequency

 
   	MT6188_WriteByte(CW(1, 0), 0x00);  		// CW1_0   [7:0]  clear interrupt flag
   	
   	MT6188_WriteByte(CW(6, 1), (MT6188_ReadCache(CW(6, 1)) & 0xFE) | 0x01);  	// CW6_1   [0:0]  0x01	start calibration

#ifdef MT6188_timing_cal
#ifdef MT6188_DEBUG_DUMP_LOG
   duration_t = video_get_duration_ms(start_t);
   kal_sprintf((void*)_dbg_str, "  Set_freq1: %d ms.\n\0", duration_t);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif   
#endif   

   	
   	/// Make sure that the counting is done
   	do {
   		
   	   	if ((WaitingCounter >> 8) == 1) {
   	      		return false;
   	   }
   	   	if ((++WaitingCounter & 0x00FF) != 0) {
   	      		MT6188_ReadByte(CW(1, 0), &TmpReg);
   	   }
   	} while ((TmpReg & 0x01) == 0);
   		
   	MT6188_WriteByte(CW(1, 0), 0x00);    		// Reset CW1_0	Clear interrupt flag

#ifdef MT6188_timing_cal
#ifdef MT6188_DEBUG_DUMP_LOG
   duration_t = video_get_duration_ms(start_t);
   kal_sprintf((void*)_dbg_str, "  Set_freq2: %d ms.\n\0", duration_t);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif   
#endif   

 
 	MT6188_ReadByte(CW(96, 0), &TmpReg);
   	if(TmpReg <= 63)
   		MT6188_WriteByte(CW(96, 0), TmpReg+1);	// 
   		

   	MT6188_WriteByte(CW(5, 1), MT6188_ReadCache(CW(5, 1)) & 0xFB);  		// CW5_1  [2:2]  0x00	fit LSB of VCO
	
	MT6188_WriteByte(CW(1, 0), 0x00);    		// Reset CW1_0	Clear interrupt flag 	
	
   	MT6188_WriteByte(CW(6, 0), (MT6188_ReadCache(CW(6, 0)) & 0xFC) | 0x01);  	// CW6_0  [1:0]  0x01	Select calibration window for LSB
   	
   	MT6188_WriteByte(CW(6, 1), 0x30);  		// CW6_1  [7:0]  0x30(32)  select calibration LSB1 of VCO
   	
   	MT6188_WriteByte(CW(25, 0), (uint8)(CurFreqLSB&0xFF));
   	MT6188_WriteByte(CW(25, 1), (uint8)(CurFreqLSB>>8));  	// CW25 [11:0]   Set calibration target frequency for VCO LSB


   	MT6188_WriteByte(CW(6, 1), (MT6188_ReadCache(CW(6, 1)) & 0xFE) | 0x01);  	// CW6_1  [0:0]  0x01	start calibration

#ifdef MT6188_timing_cal
#ifdef MT6188_DEBUG_DUMP_LOG
   duration_t = video_get_duration_ms(start_t);
   kal_sprintf((void*)_dbg_str, "  Set_freq3: %d ms.\n\0", duration_t);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif   
#endif
   	  	
   	/// Make sure that the counting is done
   	do {
   	   	if ((WaitingCounter >> 12) == 1) {
   	      		return false;
   	   }
   	   	if ((++WaitingCounter & 0x0FFF) != 0) {
   	      		MT6188_ReadByte(CW(1, 0), &TmpReg);
   	   }
   	} while ((TmpReg & 0x01) == 0);
   		
   	MT6188_WriteByte(CW(1, 0), 0x00);    		// Reset CW1_0

    if (Chip_ID == 5)
        MT6188_WriteByte(CW(6, 1),  (MT6188_ReadCache(CW(6, 1)) & 0x0F) | 0x10);  	// CW6_1  [7:4]  0x01

   	MT6188_WriteByte(CW(7, 1), MT6188_ReadCache(CW(7, 1)) & 0xFC);  		// CW7_1  [1:0]  0	reset to default without cali
   	
   	MT6188_WriteByte(CW(12, 1), MT6188_ReadCache(CW(12, 1)) & 0xFC);  		// CW12_1 [1:0]  0	reset to default without cali
   	
   	MT6188_WriteByte(CW(5, 1), (MT6188_ReadCache(CW(5, 1)) & 0xFB) | 0x04);  	// CW5_1  [2:2]  0x04  	reset to default without cali
   	
   	MT6188_WriteByte(CW(8, 0), (MT6188_ReadCache(CW(8, 0)) & 0xF7) | 0x08);  	// CW8_0  [3:3]  0x08  	reset to default without cali

    MT6188_WriteByte(CW(5, 1), MT6188_ReadCache(CW(5, 1)) & 0x7F);	//CW5_1		[7:7]	0

#ifdef MT6188_timing_cal
#ifdef MT6188_DEBUG_DUMP_LOG
   duration_t = video_get_duration_ms(start_t);
   kal_sprintf((void*)_dbg_str, "  Set_freq4: %d ms.\n\0", duration_t);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif   
#endif   

   
   // Enable (1-bit SAR)
   {

   	MT6188_WriteByte(CW(6, 1), MT6188_ReadCache(CW(6, 1)) & 0x0F);	//CW6_1	[7:4]	0   
	
   	MT6188_WriteByte(CW(7, 1), MT6188_ReadCache(CW(7, 1)) & 0xFC);	//CW7_1 [1:0]	0
   	
   	MT6188_WriteByte(CW(5, 1), MT6188_ReadCache(CW(5, 1)) & 0xFB);	//CW5_1	[2:2]	0

   	MT6188_WriteByte(CW(18, 0), MT6188_ReadCache(CW(18, 0)) & 0x7F);  	// CW18_0  [7:7] 0x00	Fix original calibration speed
   	   	
   	MT6188_WriteByte(CW(24, 1), (MT6188_ReadCache(CW(24, 1)) & 0xF8) | 0x05);	//CW24_1	[2:0]	3
   	
   	MT6188_WriteByte(CW(25, 0), (uint8)(VCO_LSB&0xFF));
   	MT6188_WriteByte(CW(25, 1), (uint8)(VCO_LSB>>8));  	// CW25 [11:0]   Set calibration target frequency for VCO LSB


   	MT6188_WriteByte(CW(26, 0), (uint8)(pf_LSB&0xFF));
   	MT6188_WriteByte(CW(26, 1), (uint8)(pf_LSB>>8));  	// CW26 [11:0]   Set calibration target frequency for pf
	
   	
   	MT6188_WriteByte(CW(10, 0), (MT6188_ReadCache(CW(10, 0)) & 0xFC) | 0x03);	//CW10_0	[1:0]	3
   	

	MT6188_WriteByte(CW(6, 1), 0);	//CW6_1	[0:0]	0
   	MT6188_WriteByte(CW(6, 1), 1);	//CW6_1	[0:0]	1
   	

   	MT6188_WriteByte(CW(24, 0), MT6188_ReadCache(CW(24, 0)) & 0xF8);	//CW24_0	[2:0]	M=0
   	
   	MT6188_WriteByte(CW(24, 0), (MT6188_ReadCache(CW(24, 0)) & 0xEF) | 0x10);	//CW24_0	[4:4]	1
   	
   	MT6188_WriteByte(CW(24, 0), (MT6188_ReadCache(CW(24, 0)) & 0xDF) | 0x20);	//CW24_0	[5:5]	1

//RestoreIRQMask(save_irq_mask);        //Set IRQ to increase process speed       	   	
   }
  kal_sleep_task(1);// after set frequency need to wait 5ms
   
#if defined MT6188_DEBUG
   MT6188_DumpCtrlWord();
#endif
   return true;
}                       //Chip_ID=4,MT6188_ECO_V4
else if (Chip_ID == 3)  //Chip_ID=3,MT6188_V3
{
    uint16 Divider, N2, Ns, Target;
	int32 CurFreqLSB,VCO_LSB=0,pf_LSB=0;
   	uint8  TmpReg;
   	uint16 WaitingCounter = 0,freq = 0,CurFreq_PLUS = 0;
uint32 save_irq_mask;
#ifdef MT6188_DEBUG_DUMP_LOG
   uint32 start_t, duration_t;
   kal_sprintf((void*)_dbg_str, "\nFMDrv_SetFreq(%d, %d);\n\0", CurFreq, HiLoInj);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
   start_t = video_get_current_time();
#endif   
   
   	
   	_current_frequency = CurFreq/FM_TUNER_GRID;
	freq = CurFreq;

   	VCO_LSB = CurFreq;
   // Disable PLL calibration	
   {	   	
  
   	/// DividerNumber = (CurFreq +- PresetIF) * 4 / RefClock 
   	if (HiLoInj == LO_INJECTION) 
   	{
     	 	VCO_LSB -= PRESET_IF;
   	} 
   	else 
   	{
      		VCO_LSB += PRESET_IF;
   	}
   		VCO_LSB *= 4000;

#if defined   REF_CLK_32K
   	VCO_LSB += 16384;    	// rounding
   	VCO_LSB /= 32768;		// 1/32768
   	
   	pf_LSB = 3562;		//456*64*4/32.768
//   	pf_LSB += 64;		//rounding
//   	pf_LSB /= 128;		//64*4/32768
#else
   	VCO_LSB += 16927;    	// rounding
   	VCO_LSB /= 33854;	// 384/13000000
   	
   	pf_LSB = 3448;		// 456*64*4/(13000/384)
//   	pf_LSB += 66;		//rounding
//   	pf_LSB /= 132;		//64*384*4/13000000
#endif

//save_irq_mask=SaveAndSetIRQMask();        //Set IRQ to increase process speed    

	MT6188_WriteByte(CW(24, 0), 0x00);	//Stop real-time calibration

   	MT6188_WriteByte(CW(6, 1), MT6188_ReadCache(CW(6, 1)) & 0xFE);	//Reset to default without calibration   
	
   }	
   	
   	MT6188_ReadByte(CW(7, 0), &TmpReg);
   	TmpReg &= 0x1F;
   	if(CurFreq <= 84000)
   		MT6188_WriteByte(CW(7, 0), TmpReg|0xE0);  	// CW7_0  [7:5]  7
   	else if(CurFreq > 84000 && CurFreq <= 92000)
   		MT6188_WriteByte(CW(7, 0), TmpReg|0x60);  	// CW7_0  [7:5]  3
   	else if(CurFreq > 92000 && CurFreq <=100000)
   		MT6188_WriteByte(CW(7, 0), TmpReg|0x20);  	// CW7_0  [7:5]  1	
 	else if(CurFreq > 100000)
 		MT6188_WriteByte(CW(7, 0), TmpReg|0x00);  	// CW7_0  [7:5]  0
   	

   	MT6188_WriteByte(CW(5, 1), (MT6188_ReadCache(CW(5, 1)) & 0xFB) | 0x04);	//CW5_1		[2:2]	1	
   	
   	MT6188_WriteByte(CW(7, 1), MT6188_ReadCache(CW(7, 1)) & 0xFC);		//CW7_1		[1:0]	0	
   	
   	MT6188_WriteByte(CW(5, 1), MT6188_ReadCache(CW(5, 1)) & 0x7F);		//CW5_1		[7:7]	0
   	
   	MT6188_WriteByte(CW(8, 0), MT6188_ReadCache(CW(8, 0)) & 0xF7);		//CW8_0		[3:3]	0	
   		   	
   	/// DividerNumber = (CurFreq +- PresetIF) * 4 / RefClock 
   	if (HiLoInj == LO_INJECTION) 
   	{
     	 	CurFreq -= PRESET_IF;
   	} 
   	else 
   	{
      		CurFreq += PRESET_IF;
   	}
   		CurFreq *= 4000;
   		CurFreqLSB = CurFreq;

#if defined   REF_CLK_32K
	CurFreq += 262144;	// rounding
	CurFreq >>= 19;		// 1/16*32768
   	CurFreqLSB += 16384;    // rounding
   	CurFreqLSB /= 32768;	// 1/32768
   	
#else
	CurFreq += 270834;	// rounding
	CurFreq /= 541667; 	// 24/13000000
   	CurFreqLSB += 16927;    // rounding
   	CurFreqLSB /= 33854;	// 384/13000000
   	
#endif
   	
   	MT6188_WriteByte(CW(12, 1), (MT6188_ReadCache(CW(12, 1)) & 0xFC) | 0x03);  	// CW12_1  [1:0]  0x03	turn-on digital clock

   	MT6188_WriteByte(CW(100, 1), (MT6188_ReadCache(CW(100, 1)) & 0xC0) | 0x10);  	// CW100_1 [5:0]  0x10	Set DAC at half range
   	
   	MT6188_WriteByte(CW(100, 0), MT6188_ReadCache(CW(100, 0)) & 0xF8);  		// CW100_0 [2:0]  0	Set DAC at half range
 
   	MT6188_ReadByte(CW(4, 0), &TmpReg);
   	TmpReg &= 0x7F;
   	if (HiLoInj == LO_INJECTION) 
   	{		
   		MT6188_WriteByte(CW(4, 0), TmpReg);  	// CW4_0    [7:7] 0:Lside
   	}
   	else
   	{
   		MT6188_WriteByte(CW(4, 0), TmpReg|0x80);  // CW4_0  [7:7] 1:Hside
   	}
   	

   	MT6188_WriteByte(CW(9, 1), MT6188_ReadCache(CW(9, 1)) & 0xF9);  		// CW9_1    [2:1]  0x00	turn-off AFC loop
   	
   	MT6188_WriteByte(CW(2, 1), MT6188_ReadCache(CW(2, 1)) & 0xC0);  		// CW2_1  [5:0]  0x00	Fix VCO divider value for calibration
   	
   	MT6188_WriteByte(CW(2, 0), 0x04);  		// CW2_0  [7:0]  0x04	Fix original calibration speed
   	
   	MT6188_WriteByte(CW(18, 0), (MT6188_ReadCache(CW(18, 0)) & 0x7F) | 0x80);  	// CW18_0  [7:7] 0x80	Fix original calibration speed
   	
   	MT6188_WriteByte(CW(3, 0), (MT6188_ReadCache(CW(3, 0)) & 0xEF) | 0x10);  	// CW3_0   [4:4] 0x10	Disconnect RFPLL
   	
   	MT6188_WriteByte(CW(3, 0), (MT6188_ReadCache(CW(3, 0)) & 0xF8) | 0x05);  	// CW3_0   [2:0] 0x05	Turn-on reference clock path
   	
   	MT6188_WriteByte(CW(7, 1), (MT6188_ReadCache(CW(7, 1)) & 0xFC) | 0x03);  	// CW7_1   [1:0] 0x03  Calibration standby

   	MT6188_WriteByte(CW(6, 0), MT6188_ReadCache(CW(6, 0)) & 0xFC);  		// CW6_0   [1:0] 0x00  select calibration window
   	
   	MT6188_WriteByte(CW(6, 1), 0x00);  		// CW6_1   [7:0] 0x00  select calibratio MSB of VCO

	MT6188_WriteByte(CW(25, 0), (uint8)(CurFreq&0xFF));
   	MT6188_WriteByte(CW(25, 1), (uint8)(CurFreq>>8));  	// CW25   Set calibration target frequency

   	MT6188_WriteByte(CW(1, 0), 0x00);  		// CW1_0   [7:0]  clear interrupt flag
   	
   	MT6188_WriteByte(CW(6, 1), (MT6188_ReadCache(CW(6, 1)) & 0xFE) | 0x01);  	// CW6_1   [0:0]  0x01	start calibration

#ifdef MT6188_timing_cal
#ifdef MT6188_DEBUG_DUMP_LOG
   duration_t = video_get_duration_ms(start_t);
   kal_sprintf((void*)_dbg_str, "  Set_freq1: %d ms.\n\0", duration_t);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif   
#endif   

   	
   	/// Make sure that the counting is done
   	do {
   		
   	   	if ((WaitingCounter >> 8) == 1) {
   	      		return false;
   	   }
   	   	if ((++WaitingCounter & 0x00FF) != 0) {
   	      		MT6188_ReadByte(CW(1, 0), &TmpReg);
   	   }
   	} while ((TmpReg & 0x01) == 0);
   		
   	MT6188_WriteByte(CW(1, 0), 0x00);    		// Reset CW1_0	Clear interrupt flag

#ifdef MT6188_timing_cal
#ifdef MT6188_DEBUG_DUMP_LOG
   duration_t = video_get_duration_ms(start_t);
   kal_sprintf((void*)_dbg_str, "  Set_freq2: %d ms.\n\0", duration_t);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif   
#endif   

 
 	MT6188_ReadByte(CW(96, 0), &TmpReg);
   	if(TmpReg <= 63)
   		MT6188_WriteByte(CW(96, 0), TmpReg+1);	// 
   		

   	MT6188_WriteByte(CW(5, 1), MT6188_ReadCache(CW(5, 1)) & 0xFB);  		// CW5_1  [2:2]  0x00	fit LSB of VCO
	
	MT6188_WriteByte(CW(1, 0), 0x00);    		// Reset CW1_0	Clear interrupt flag 	
	
   	MT6188_WriteByte(CW(6, 0), (MT6188_ReadCache(CW(6, 0)) & 0xFC) | 0x01);  	// CW6_0  [1:0]  0x01	Select calibration window for LSB
   	
   	MT6188_WriteByte(CW(6, 1), 0x32);  		// CW6_1  [7:0]  0x32(50)  select calibration LSB1 of VCO
   	
   	MT6188_WriteByte(CW(25, 0), (uint8)(CurFreqLSB&0xFF));
   	MT6188_WriteByte(CW(25, 1), (uint8)(CurFreqLSB>>8));  	// CW25 [11:0]   Set calibration target frequency for VCO LSB

   	MT6188_WriteByte(CW(6, 1), (MT6188_ReadCache(CW(6, 1)) & 0xFE) | 0x01);  	// CW6_1  [0:0]  0x01	start calibration

#ifdef MT6188_timing_cal
#ifdef MT6188_DEBUG_DUMP_LOG
   duration_t = video_get_duration_ms(start_t);
   kal_sprintf((void*)_dbg_str, "  Set_freq3: %d ms.\n\0", duration_t);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif   
#endif   

   	 	
   	/// Make sure that the counting is done
   	do {
   	   	if ((WaitingCounter >> 12) == 1) {
   	      		return false;
   	   }
   	   	if ((++WaitingCounter & 0x0FFF) != 0) {
   	      		MT6188_ReadByte(CW(1, 0), &TmpReg);
   	   }
   	} while ((TmpReg & 0x01) == 0);
   		
   	MT6188_WriteByte(CW(1, 0), 0x00);    		// Reset CW1_0
 
   	MT6188_WriteByte(CW(6, 1), (MT6188_ReadCache(CW(6, 1)) & 0x0F) | 0x20);  	// CW6_1  [7:4]  0x20	Select calibrate as LSB2 of VCO
   	
   	MT6188_WriteByte(CW(6, 1), (MT6188_ReadCache(CW(6, 1)) & 0xFE) | 0x01);  	// CW6_1  [0:0]  0x01	start calibration

#ifdef MT6188_timing_cal
#ifdef MT6188_DEBUG_DUMP_LOG
   duration_t = video_get_duration_ms(start_t);
   kal_sprintf((void*)_dbg_str, "  Set_freq4: %d ms.\n\0", duration_t);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif   
#endif   
 	  	
	/// Make sure that the counting is done
   	do {
   	   	if ((WaitingCounter >> 12) == 1) {
   	      		return false;
   	   }
   	   	if ((++WaitingCounter & 0x0FFF) != 0) {
   	      		MT6188_ReadByte(CW(1, 0), &TmpReg);
   	   }
   	} while ((TmpReg & 0x01) == 0);
   		
   	MT6188_WriteByte(CW(1, 0), 0x00);    		// Reset CW1_0

#ifdef MT6188_timing_cal
#ifdef MT6188_DEBUG_DUMP_LOG
   duration_t = video_get_duration_ms(start_t);
   kal_sprintf((void*)_dbg_str, "  Set_freq5: %d ms.\n\0", duration_t);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif   
#endif   
 
   	MT6188_WriteByte(CW(7, 1), MT6188_ReadCache(CW(7, 1)) & 0xFC);  		// CW7_1  [1:0]  0	reset to default without cali
   	
   	MT6188_WriteByte(CW(12, 1), MT6188_ReadCache(CW(12, 1)) & 0xFC);  		// CW12_1 [1:0]  0	reset to default without cali
   	
   	MT6188_WriteByte(CW(5, 1), (MT6188_ReadCache(CW(5, 1)) & 0xFB) | 0x04);  	// CW5_1  [2:2]  0x04  	reset to default without cali
   	
   	MT6188_WriteByte(CW(8, 0), (MT6188_ReadCache(CW(8, 0)) & 0xF7) | 0x08);  	// CW8_0  [3:3]  0x08  	reset to default without cali


   
   // Enable PLL calibration
   {

   	MT6188_WriteByte(CW(18, 0), MT6188_ReadCache(CW(18, 0)) & 0x7F);  	// CW18_0  [7:7] 0x00	Fix original calibration speed
   	
	//Reset to default without calibration
   	MT6188_WriteByte(CW(6, 1), MT6188_ReadCache(CW(6, 1)) & 0x0F);	//CW6_1	[7:4]	0   
	
	//Disable normal calibration
   	MT6188_WriteByte(CW(7, 1), MT6188_ReadCache(CW(7, 1)) & 0xFC);	//CW7_1 [1:0]	0
   	
	//Reset to default without calibration
   	MT6188_WriteByte(CW(5, 1), MT6188_ReadCache(CW(5, 1)) & 0xFB);	//CW5_1	[2:2]	0
   	
	//VCO 1-bit SAR threshold
   	MT6188_WriteByte(CW(24, 1), (MT6188_ReadCache(CW(24, 1)) & 0xF8) | 0x05);	//CW24_1	[2:0]	3
   	
   	MT6188_WriteByte(CW(25, 0), (uint8)(VCO_LSB&0xFF));
   	MT6188_WriteByte(CW(25, 1), (uint8)(VCO_LSB>>8));  	// CW25 [11:0]   Set calibration target frequency for VCO LSB


   	MT6188_WriteByte(CW(26, 0), (uint8)(pf_LSB&0xFF));
   	MT6188_WriteByte(CW(26, 1), (uint8)(pf_LSB>>8));  	// CW26 [11:0]   Set calibration target frequency for pf

   	MT6188_WriteByte(CW(10, 0), (MT6188_ReadCache(CW(10, 0)) & 0xFC) | 0x03);	//CW10_0	[1:0]	3
   	
	//Calibration standby
	MT6188_WriteByte(CW(6, 1), 0);	//CW6_1	[0:0]	0
   	MT6188_WriteByte(CW(6, 1), 1);	//CW6_1	[0:0]	1
   	
	//Set speed of real-time calibration  		
   	MT6188_WriteByte(CW(24, 0), MT6188_ReadCache(CW(24, 0)) & 0xF8);	//CW24_0	[2:0]	M=0
   	
	//Start VCO real-time calibration
   	MT6188_WriteByte(CW(24, 0), (MT6188_ReadCache(CW(24, 0)) & 0xEF) | 0x10);	//CW24_0	[4:4]	1
   	
	//Start PF real-time calibration
   	MT6188_WriteByte(CW(24, 0), (MT6188_ReadCache(CW(24, 0)) & 0xDF) | 0x20);	//CW24_0	[5:5]	1

//RestoreIRQMask(save_irq_mask);        //Set IRQ to increase process speed       	   	
   }
  kal_sleep_task(1);// after set frequency need to wait 5ms
   
#if defined MT6188_DEBUG
   MT6188_DumpCtrlWord();
#endif
   return true;
}//Chip_ID=3,MT6188_V3
}//MT6188_SetFreq


/******************************************************************************
*  Verify set frequency is forward or backward in Radio frequency select
*
*  parameter-->CurFreq:set frequency
               SignalLevel:threshold value
*******************************************************************************/
static int16 MT6188_HiLoInjectOptimizer(int32 CurFreq, int16 SignalLevel)
{
   uint16 LevelHigh, LevelLow;

   if (MT6188_SetFreq(CurFreq + 2 * PRESET_IF, HI_INJECTION) == false)
      return SET_FREQ_FAIL;
   LevelHigh = MT6188_GetCurRSSI();

   if (MT6188_SetFreq(CurFreq - 2 * PRESET_IF, HI_INJECTION) == false)
      return SET_FREQ_FAIL;
   LevelLow = MT6188_GetCurRSSI();

   if (LevelHigh < SignalLevel && LevelLow < SignalLevel)
      return RSSI_CHECK_FAIL;
   if (LevelHigh > LevelLow)
      return LO_INJECTION;
   else
      return HI_INJECTION;
}



static void MT6188_SetVolumeLevel(uint8 level) {
   /// Bug fix: Fix the mono/stereo gain issue
   const uint8 prev_level = _current_level;
   ASSERT((level & 0x7F) < 13);

   _current_level = level;

   if ((false == _is_fm_on) || _is_fm_mute) 
   {
      return;
   }

   if (prev_level == 0 && level != 0) 
   {
      MT6188_Mute(0);
   } 
   else if (prev_level != 0 && level == 0) 
   {
      /// This is a special case.
      /// If the level is set to zero, there is still sound leakage due to the HW design of MT6188.
      /// Thus, we use MT6188_Mute to force it keeps silent.
      /// However, the _is_fm_mute flag is not raised since it is not really a mute situation.
      MT6188_Mute(1);
      _is_fm_mute = 0;
      return;
   }
#if defined force_mono
mono_flag = 1;
#endif

   SerialCommInit();
   {
        uint8 volume_count;
        uint8 TmpReg;
//      MT6188_ReadByte(CW(18, 1), &TmpReg);
//      if (TmpReg & 0x80) {
         /// Stereo
//         MT6188_WriteByte(CW(16, 0), 64 | (level & 0x7F));
//         MT6188_WriteByte(CW(16, 1), 64 | (level & 0x7F));
//      } else {
         /// Mono
if (Chip_ID == 5)
{
#if !defined( MT6205B ) && !defined( MT6208 )  
    if(mono_flag == 1)
    {
         MT6188_WriteByte(CW(14, 0), 0x6E);     // only mono
    }
    else if(mono_flag == 2)
    {
        MT6188_WriteByte(CW(14, 0), 0xEE);     // mono off and S_auto
    }
    else if (mono_flag == 3)
    {
        MT6188_WriteByte(CW(14, 0), 0x7E);     // stereo + sblend_on
    }
    else if (mono_flag == 4)
    {
        MT6188_WriteByte(CW(14, 0), 0x3E);     // stereo + sblend_off
    }
    
    else
    {
        MT6188_WriteByte(CW(14, 0), 0xEE);     // S_auto
    }
    
    for(volume_count= 96; volume_count<=103; volume_count+=1)
    {      
         MT6188_WriteByte(CW(16, 0), volume_count);//108);
         MT6188_WriteByte(CW(16, 1), volume_count);//108);
    }
#else
    if(mono_flag == 1)
    {
         MT6188_WriteByte(CW(14, 0), 0x6E);     // only mono
    }
    else if(mono_flag == 2)
    {
        MT6188_WriteByte(CW(14, 0), 0xEE);     // mono off and S_auto
    }
    else if (mono_flag == 3)
    {
        MT6188_WriteByte(CW(14, 0), 0x7E);     // stereo + sblend_on
    }
    else if (mono_flag == 4)
    {
        MT6188_WriteByte(CW(14, 0), 0x3E);     // stereo + sblend_off
    }
    
    else
    {
        MT6188_WriteByte(CW(14, 0), 0xEE);     // S_auto
    }
	     MT6188_WriteByte(CW(16, 0), 96 | (level & 0x7F));
         MT6188_WriteByte(CW(16, 1), 96 | (level & 0x7F));

#endif
}   //end Chip_ID = 5
else    //start Chip_ID = 4/3
{
    #if !defined( MT6205B ) && !defined( MT6208 )  
    if(mono_flag == 1)
    {
         MT6188_WriteByte(CW(14, 0), 0x66);     // only mono
    }
    else if(mono_flag == 2)
    {
        MT6188_WriteByte(CW(14, 0), 0xE6);     // mono off and S_auto
    }
    else if (mono_flag == 3)
    {
        MT6188_WriteByte(CW(14, 0), 0x76);     // stereo + sblend_on
    }
    else if (mono_flag == 4)
    {
        MT6188_WriteByte(CW(14, 0), 0x36);     // stereo + sblend_off
    }
    
    else
    {
        MT6188_WriteByte(CW(14, 0), 0xE6);     // S_auto
    }
    
    for(volume_count= 96; volume_count<=103; volume_count+=1)
    {      
         MT6188_WriteByte(CW(16, 0), volume_count);//108);
         MT6188_WriteByte(CW(16, 1), volume_count);//108);
    }
#else
    if(mono_flag == 1)
    {
         MT6188_WriteByte(CW(14, 0), 0x66);     // only mono
    }
    else if(mono_flag == 2)
    {
        MT6188_WriteByte(CW(14, 0), 0xE6);     // mono off and S_auto
    }
    else if (mono_flag == 3)
    {
        MT6188_WriteByte(CW(14, 0), 0x76);     // stereo + sblend_on
    }
    else if (mono_flag == 4)
    {
        MT6188_WriteByte(CW(14, 0), 0x36);     // stereo + sblend_off
    }
    
    else
    {
        MT6188_WriteByte(CW(14, 0), 0xE6);     // S_auto
    }
	     MT6188_WriteByte(CW(16, 0), 96 | (level & 0x7F));
         MT6188_WriteByte(CW(16, 1), 96 | (level & 0x7F));

#endif
}   //end Chip_ID = 4/3

#ifdef MT6188_DEBUG_DUMP_LOG
   MT6188_ReadByte(CW(14, 0), &TmpReg);
   kal_sprintf((void*)_dbg_str, "   mono_flag: %d ms.\n CW14_0 = %d \n\0", mono_flag, TmpReg);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif   

   }  
   SerialCommRelease();

}

static void MT6188_Mute(uint8 mute) 
{
   uint8 TmpReg;

   _is_fm_mute = (bool)mute;
   if (false == _is_fm_on)
      return;

   if (_current_level == 0 && mute == 0)
      return;

   SerialCommInit();
/*
   TmpReg = MT6188_ReadCache(CW(14, 1)) & 0xF8;
#ifndef USE_MT6188_AMP
   TmpReg |= 0x03;
#endif
   if (mute != 0)
      TmpReg |= 0x07;
   MT6188_WriteByte(CW(14, 1), TmpReg);
*/
   if (mute == 0) 
   {
      MT6188_SetVolumeLevel(_current_level);
   } 
   else 
   {
      MT6188_WriteByte(CW(16, 0), 0);
      MT6188_WriteByte(CW(16, 1), 0);
   }
   SerialCommRelease();
}


/// level ranges from 0 to 12
void FMDrv_SetVolumeLevel(uint8 level)
{
  #ifdef MT6188_DEBUG_DUMP_LOG
   kal_sprintf((void*)_dbg_str, "\nFMDrv_SetVolumeLevel(%d);\n\0", level);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif
   MT6188_SetVolumeLevel(level);
}

void FMDrv_Mute(uint8 mute)
{
  #ifdef MT6188_DEBUG_DUMP_LOG
   kal_sprintf((void*)_dbg_str, "\nFMDrv_Mute(%d);\n\0", mute);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif
   MT6188_Mute(mute);
}


/*************************************************************
*  Radio power on Reset
*
*************************************************************/
void FMDrv_PowerOnReset(void)
{
   uint8 fail_count;
   uint8 tmp_reg,pp=0;
   int16 i;

#ifdef MT6188_DEBUG_DUMP_LOG
   uint32 start_t, duration_t;
   _file_handle = FS_Open((const WCHAR *)_file_name, FS_CREATE);
   kal_sprintf((void*)_dbg_str, "\nFMDrv_PowerOnReset();\n\0");
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
   start_t = video_get_current_time();
#endif

#ifdef MT6188_DEBUG_DUMP_LOG
    _file_list = FS_Open((const WCHAR *)_channel_name, FS_CREATE);
   kal_sprintf((void*)_list_str, "\nchannel list;\n\0");
   FS_Write(_file_list, _list_str, strlen((void*)_list_str), &_list_written);
#endif   
   
   SerialCommInit();
   SerialCommCryClkOn();

    MT6188_ReadByte(CW(0, 1), &Chip_ID);
    Chip_ID &= 0x07;


/// Power On
    if (Chip_ID == 5)
    {        
       for (i=0; i<POWER_ON_COMMAND_COUNT_V5; i++) 
       {
          MT6188_WriteByte(PowerOnSetting_V5[i].addr, PowerOnSetting_V5[i].value);
       }
    }
    else if (Chip_ID == 4)
    {
       for (i=0; i<POWER_ON_COMMAND_COUNT_V4; i++) 
       {
          MT6188_WriteByte(PowerOnSetting_V4[i].addr, PowerOnSetting_V4[i].value);
       }
    }
    else if (Chip_ID == 3)
    {
       for (i=0; i<POWER_ON_COMMAND_COUNT_V3; i++) 
       {
          MT6188_WriteByte(PowerOnSetting_V3[i].addr, PowerOnSetting_V3[i].value);
       }
    } //end Chip_ID select
 
#if defined MT6188_DEBUG
   MT6188_DumpCtrlWord();
#endif
   
/// Calibrate Preset
    if (Chip_ID == 5)
    {
        fail_count = 0;
        for (i=0; i<CAL_PRESET_COUNT_V5; i++)
        {
        	MT6188_ReadByte(CalPresetProcess_V5[i].addr, &tmp_reg);
        	tmp_reg &= CalPresetProcess_V5[i].and;
        	tmp_reg |= CalPresetProcess_V5[i].or;
        	if (false == MT6188_WriteByte(CalPresetProcess_V5[i].addr, tmp_reg)) 
        	{
        		if (++fail_count == CALIBRATION_FAIL_COUNT_THRESHOLD)
        		{
        			ASSERT(0);
        		}
        		i = 0;
        	}
        }
    }
    else
    {
        fail_count = 0;
        for (i=0; i<CAL_PRESET_COUNT; i++)
        {
        	MT6188_ReadByte(CalPresetProcess[i].addr, &tmp_reg);
        	tmp_reg &= CalPresetProcess[i].and;
        	tmp_reg |= CalPresetProcess[i].or;
        	if (false == MT6188_WriteByte(CalPresetProcess[i].addr, tmp_reg)) 
        	{
        		if (++fail_count == CALIBRATION_FAIL_COUNT_THRESHOLD)
        		{
        			ASSERT(0);
        		}
        		i = 0;
        	}
        }
    }

#if defined MT6188_DEBUG
   MT6188_DumpCtrlWord();
#endif
   
   /// Calibrate PLL
   fail_count = 0;
   for (i=0; i<CAL_PLL_COMMAND_COUNT; i++) 
   {
      MT6188_ReadByte(CalPLLProcess[i].addr, &tmp_reg);
      tmp_reg &= CalPLLProcess[i].and;
      tmp_reg |= CalPLLProcess[i].or;
      if (false == MT6188_WriteByte(CalPLLProcess[i].addr, tmp_reg)) 
      {
         if (++fail_count == CALIBRATION_FAIL_COUNT_THRESHOLD)
         {
            ASSERT(0);
         }
         i = 0;
      }
   }

#if defined MT6188_DEBUG
   MT6188_DumpCtrlWord();
#endif

   /// Calibrate demod I
   fail_count = 0;
   for (i=0; i<CAL_DEMOD_I_COMMAND_COUNT; i++) 
   {
      MT6188_ReadByte(CalDemodIProcess[i].addr, &tmp_reg);
      tmp_reg &= CalDemodIProcess[i].and;
      tmp_reg |= CalDemodIProcess[i].or;
      if (false == MT6188_WriteByte(CalDemodIProcess[i].addr, tmp_reg)) 
      {
         if (++fail_count == CALIBRATION_FAIL_COUNT_THRESHOLD)
         {
            ASSERT(0);
         }
         i = 0;
      }
   }

#if defined MT6188_DEBUG
   MT6188_DumpCtrlWord();
#endif

    if (Chip_ID == 5)
    {
        /// Channel filter
        fail_count = 0;
        for (i=0; i<CHANNEL_FILTER_COUNT; i++) 
        {
           MT6188_ReadByte(ChannelFilter[i].addr, &tmp_reg);
           tmp_reg &= ChannelFilter[i].and;
           tmp_reg |= ChannelFilter[i].or;
           if (false == MT6188_WriteByte(ChannelFilter[i].addr, tmp_reg)) 
           {
              if (++fail_count == CALIBRATION_FAIL_COUNT_THRESHOLD)
              {
                 ASSERT(0);
              }
              i = 0;
           }
        }

#if defined MT6188_DEBUG
   MT6188_DumpCtrlWord();
#endif

        /// MUXOFF_MN
        fail_count = 0;
        for (i=0; i<MUXOFF_MN_COUNT; i++) 
        {
           MT6188_ReadByte(MuxOff_MN[i].addr, &tmp_reg);
           tmp_reg &= MuxOff_MN[i].and;
           tmp_reg |= MuxOff_MN[i].or;
           if (false == MT6188_WriteByte(MuxOff_MN[i].addr, tmp_reg)) 
           {
              if (++fail_count == CALIBRATION_FAIL_COUNT_THRESHOLD)
              {
                 ASSERT(0);
              }
              i = 0;
           }
        }

#if defined MT6188_DEBUG
   MT6188_DumpCtrlWord();
#endif

        /// MUXOFF_ST
        fail_count = 0;
        for (i=0; i<MUXOFF_ST_COUNT; i++) 
        {
           MT6188_ReadByte(MuxOff_ST[i].addr, &tmp_reg);
           tmp_reg &= MuxOff_ST[i].and;
           tmp_reg |= MuxOff_ST[i].or;
           if (false == MT6188_WriteByte(MuxOff_ST[i].addr, tmp_reg)) 
           {
              if (++fail_count == CALIBRATION_FAIL_COUNT_THRESHOLD)
              {
                 ASSERT(0);
              }
              i = 0;
           }
        }

#if defined MT6188_DEBUG
   MT6188_DumpCtrlWord();
#endif

        /// PFOSC_560K
        fail_count = 0;
        for (i=0; i<PFOSC_560K_COUNT; i++) 
        {
           MT6188_ReadByte(Pfosc_560K[i].addr, &tmp_reg);
           tmp_reg &= Pfosc_560K[i].and;
           tmp_reg |= Pfosc_560K[i].or;
           if (false == MT6188_WriteByte(Pfosc_560K[i].addr, tmp_reg)) 
           {
              if (++fail_count == CALIBRATION_FAIL_COUNT_THRESHOLD)
              {
                 ASSERT(0);
              }
              i = 0;
           }
        }

#if defined MT6188_DEBUG
   MT6188_DumpCtrlWord();
#endif

        /// SM_CAL_OFFSET
        fail_count = 0;
        for (i=0; i<SM_CAL_OFFSET_COUNT; i++) 
        {
           MT6188_ReadByte(SM_Cal_Offset[i].addr, &tmp_reg);
           tmp_reg &= SM_Cal_Offset[i].and;
           tmp_reg |= SM_Cal_Offset[i].or;
           if (false == MT6188_WriteByte(SM_Cal_Offset[i].addr, tmp_reg)) 
           {
              if (++fail_count == CALIBRATION_FAIL_COUNT_THRESHOLD)
              {
                 ASSERT(0);
              }
              i = 0;
           }
        }

#if defined MT6188_DEBUG
   MT6188_DumpCtrlWord();
#endif

        /// SM_CAL_SLOPE
        fail_count = 0;
        for (i=0; i<SM_CAL_SLOPE_COUNT; i++) 
        {
           MT6188_ReadByte(SM_Cal_Slope[i].addr, &tmp_reg);
           tmp_reg &= SM_Cal_Slope[i].and;
           tmp_reg |= SM_Cal_Slope[i].or;
           if (false == MT6188_WriteByte(SM_Cal_Slope[i].addr, tmp_reg)) 
           {
              if (++fail_count == CALIBRATION_FAIL_COUNT_THRESHOLD)
              {
                 ASSERT(0);
              }
              i = 0;
           }
        }

#if defined MT6188_DEBUG
   MT6188_DumpCtrlWord();
#endif

        /// AAMP1_LCHOFF_MN
        fail_count = 0;
        for (i=0; i<AAMP1_LCHOFF_MN_COUNT; i++) 
        {
           MT6188_ReadByte(Aamp1_Lchoff_MN[i].addr, &tmp_reg);
           tmp_reg &= Aamp1_Lchoff_MN[i].and;
           tmp_reg |= Aamp1_Lchoff_MN[i].or;
           if (false == MT6188_WriteByte(Aamp1_Lchoff_MN[i].addr, tmp_reg)) 
           {
              if (++fail_count == CALIBRATION_FAIL_COUNT_THRESHOLD)
              {
                 ASSERT(0);
              }
              i = 0;
           }
        }

#if defined MT6188_DEBUG
   MT6188_DumpCtrlWord();
#endif

        /// AAMP1_RCHOFF_MN
        fail_count = 0;
        for (i=0; i<AAMP1_RCHOFF_MN_COUNT; i++) 
        {
           MT6188_ReadByte(Aamp1_Rchoff_MN[i].addr, &tmp_reg);
           tmp_reg &= Aamp1_Rchoff_MN[i].and;
           tmp_reg |= Aamp1_Rchoff_MN[i].or;
           if (false == MT6188_WriteByte(Aamp1_Rchoff_MN[i].addr, tmp_reg)) 
           {
              if (++fail_count == CALIBRATION_FAIL_COUNT_THRESHOLD)
              {
                 ASSERT(0);
              }
              i = 0;
           }
        }

        MT6188_ReadByte(CW( 30, 0), &tmp_reg);
        MT6188_WriteByte(CW( 31, 0), tmp_reg);
        
        MT6188_ReadByte(CW( 30, 1), &tmp_reg);
        MT6188_WriteByte(CW( 31, 1), tmp_reg);

#if defined MT6188_DEBUG
   MT6188_DumpCtrlWord();
#endif
    }
    
/// Calibrate Pfosc
    if (Chip_ID ==5)
    {
            uint8 k;
           fail_count = 0;
           for (i=0; i<CAL_PFOSC_COMMAND_COUNT_V5; i++) 
           {
              MT6188_ReadByte(CalPfoscProcess_V5[i].addr, &tmp_reg);
              tmp_reg &= CalPfoscProcess_V5[i].and;
              tmp_reg |= CalPfoscProcess_V5[i].or;
              if (false == MT6188_WriteByte(CalPfoscProcess_V5[i].addr, tmp_reg)) 
              {
                 if (++fail_count == CALIBRATION_FAIL_COUNT_THRESHOLD)
                 {
                    ASSERT(0);
                 }
                 i = 0;
              }
           }
        
           MT6188_ReadByte(CW( 3, 0), &tmp_reg);
           tmp_reg &= 0xEF;
           MT6188_WriteByte(CW( 3, 0), tmp_reg);
             
    }
    else    //start Chip_ID == 3/4
    {
           uint8 k;
           fail_count = 0;
           for (i=0; i<CAL_PFOSC_COMMAND_COUNT; i++) 
           {
              MT6188_ReadByte(CalPfoscProcess[i].addr, &tmp_reg);
              tmp_reg &= CalPfoscProcess[i].and;
              tmp_reg |= CalPfoscProcess[i].or;
              if (false == MT6188_WriteByte(CalPfoscProcess[i].addr, tmp_reg)) 
              {
                 if (++fail_count == CALIBRATION_FAIL_COUNT_THRESHOLD)
                 {
                    ASSERT(0);
                 }
                 i = 0;
              }
           }
        
           MT6188_ReadByte(CW( 3, 0), &tmp_reg);
           tmp_reg &= 0xEF;
           MT6188_WriteByte(CW( 3, 0), tmp_reg);
        if (Chip_ID == 4)
        {      
              MT6188_ReadByte(CW( 98, 1), &tmp_reg);	//CW98_1
            if(tmp_reg <= 61)
            {
              	MT6188_WriteByte(CW(4, 0), (MT6188_ReadCache(CW(4, 0)) & 0x8F) | 0x70);//cw4_0 [6:4] 7 	
	        }
	        else if(tmp_reg >= 62 && tmp_reg <= 65)
	        {
	        	MT6188_WriteByte(CW(4, 0), (MT6188_ReadCache(CW(4, 0)) & 0x8F) | 0x60);//cw4_0 [6:4] 6	
	        }
	        else if(tmp_reg >= 66 && tmp_reg <= 69)
	        {
	        	MT6188_WriteByte(CW(4, 0), (MT6188_ReadCache(CW(4, 0)) & 0x8F) | 0x50);//cw4_0 [6:4] 5	
	        }
	        else if(tmp_reg >= 70 && tmp_reg <= 73)
	        {
	        	MT6188_WriteByte(CW(4, 0), (MT6188_ReadCache(CW(4, 0)) & 0x8F) | 0x40);//cw4_0 [6:4] 4 	
	        }
	        else if(tmp_reg >= 74 && tmp_reg <= 79)
	        {
	        	MT6188_WriteByte(CW(4, 0), (MT6188_ReadCache(CW(4, 0)) & 0x8F) | 0x30);//cw4_0 [6:4] 3 	
	        }
	        else if(tmp_reg >= 80 && tmp_reg <= 83)
	        {
	        	MT6188_WriteByte(CW(4, 0), (MT6188_ReadCache(CW(4, 0)) & 0x8F) | 0x20);//cw4_0 [6:4] 2 	
	        }	
	        else if(tmp_reg >= 84 && tmp_reg <= 87)
	        {
	        	MT6188_WriteByte(CW(4, 0), (MT6188_ReadCache(CW(4, 0)) & 0x8F) | 0x10);//cw4_0 [6:4] 1 	
	        }
	        else if(tmp_reg >= 88)
	        {
	        	MT6188_WriteByte(CW(4, 0), (MT6188_ReadCache(CW(4, 0)) & 0x8F));//cw4_0 [6:4] 0 	
	        }
        }       //Chip_ID=4,MT6188_ECO
   }    //end Chip_ID == 3/4   
#if defined MT6188_DEBUG
   MT6188_DumpCtrlWord();
#endif

//Delay calibration
    if (Chip_ID == 5)
    {
        fail_count = 0;
      for (i=0; i<CAL_DelayCalibration_COMMAND_COUNT_V5; i++) 
      {
         MT6188_ReadByte(CalDelayCalibrationProcess_V5[i].addr, &tmp_reg);
         tmp_reg &= CalDelayCalibrationProcess_V5[i].and;
         tmp_reg |= CalDelayCalibrationProcess_V5[i].or;
         if (false == MT6188_WriteByte(CalDelayCalibrationProcess_V5[i].addr, tmp_reg)) 
         {
            if (++fail_count == CALIBRATION_FAIL_COUNT_THRESHOLD)
            {
               ASSERT(0);
            }
            i = 0;
         }
      }
   	
         	
   //RSSI calibration
//      	MT6188_WriteByte(CW( 5, 0), 0);
	MT6188_ReadByte(CW( 5, 0), &tmp_reg);	//CW5_0		[1:1]=0, 
	tmp_reg &= 0xFD;
      	MT6188_WriteByte(CW( 5, 0), (tmp_reg |= 0x00));
      	
      	kal_sleep_task(11);//wait 50ms
      	
      	MT6188_ReadByte(CW( 4, 1), &tmp_reg);	//CW4_1		[4:0]read RSSI value
      	tmp_reg &= 0x1F;
      	pp = tmp_reg;
      	MT6188_ReadByte(CW( 13, 1), &tmp_reg);	//CW13_1	
      	tmp_reg &= 0xE1;
      	MT6188_WriteByte(CW( 13, 1), (tmp_reg |= (pp << 1)));//   	write to cw(13, 1) [4:1]
      	
        MT6188_ReadByte(CW( 5, 0), &tmp_reg);	//CW5_0		[1:1]=1, 
        tmp_reg &= 0xFD;                                                                                
        MT6188_WriteByte(CW( 5, 0), (tmp_reg |= 0x02));                                                 
            
   // Disable Calibration
      MT6188_ReadByte(CW( 14, 0), &tmp_reg);	//CW14_0	[7:7]1,S_AUTO,STEREO
      tmp_reg &= 0x7F;
      MT6188_WriteByte(CW( 14, 0), (tmp_reg |= 0x80));
      
      MT6188_ReadByte(CW( 10, 1), &tmp_reg);	//CW10_1	[5:5]0,FRCKTEST
      tmp_reg &= 0xDF;
      MT6188_WriteByte(CW( 10, 1), tmp_reg);
      
      MT6188_ReadByte(CW( 11, 1), &tmp_reg);	//CW11_1	[5:4]0,FR_TEST[1:0]
      tmp_reg &= 0xCF;
      MT6188_WriteByte(CW( 11, 1), tmp_reg);
   
   	  MT6188_WriteByte(CW( 14, 0), 0xFE);	//force S_auto/S_mute/S_blend = true
   	 
#if defined MT6188_DEBUG
   MT6188_DumpCtrlWord();
#endif
    }   //end Chip_ID = 5
    else if (Chip_ID == 4)
    {
       
       	fail_count = 0;
          for (i=0; i<CAL_DelayCalibration_COMMAND_COUNT; i++) 
          {
             MT6188_ReadByte(CalDelayCalibrationProcess[i].addr, &tmp_reg);
             tmp_reg &= CalDelayCalibrationProcess[i].and;
             tmp_reg |= CalDelayCalibrationProcess[i].or;
             if (false == MT6188_WriteByte(CalDelayCalibrationProcess[i].addr, tmp_reg)) 
             {
                if (++fail_count == CALIBRATION_FAIL_COUNT_THRESHOLD)
                {
                   ASSERT(0);
                }
                i = 0;
             }
          }
       	
             	
       //RSSI calibration
          	MT6188_WriteByte(CW( 5, 0), 0);
          	
          	kal_sleep_task(11);//wait 50ms
          	
          	MT6188_ReadByte(CW( 4, 1), &tmp_reg);	//CW4_1		[4:0]read RSSI value
          	tmp_reg &= 0x1F;
          	pp = tmp_reg;
          	MT6188_ReadByte(CW( 13, 1), &tmp_reg);	//CW13_1	
          	tmp_reg &= 0xE1;
          	MT6188_WriteByte(CW( 13, 1), (tmp_reg |= (pp << 1)));//   	write to cw(13, 1) [4:1]
          	
          	MT6188_ReadByte(CW( 5, 0), &tmp_reg);	//CW5_0		[7:0]=175, Enable delay calibration loop
          	tmp_reg &= 0x00;
          	MT6188_WriteByte(CW( 5, 0), (tmp_reg |= 0xAF));
                
       // Disable Calibration
          MT6188_ReadByte(CW( 14, 0), &tmp_reg);	//CW14_0	[7:7]1,S_AUTO,STEREO
          tmp_reg &= 0x7F;
          MT6188_WriteByte(CW( 14, 0), (tmp_reg |= 0x80));
          
          MT6188_ReadByte(CW( 10, 1), &tmp_reg);	//CW10_1	[5:5]0,FRCKTEST
          tmp_reg &= 0xDF;
          MT6188_WriteByte(CW( 10, 1), tmp_reg);
          
          MT6188_ReadByte(CW( 11, 1), &tmp_reg);	//CW11_1	[5:4]0,FR_TEST[1:0]
          tmp_reg &= 0xCF;
          MT6188_WriteByte(CW( 11, 1), tmp_reg);
   
   

#if defined MT6188_DEBUG
   MT6188_DumpCtrlWord();
#endif
    }       //end Chip_ID=4,MT6188_ECO

   SerialCommRelease();
   _is_fm_on = true;
   _current_frequency = -1;
   _rssi_threshold = FM_RADIO_INPUT_LEVEL_THRESHOLD;
   if(RSSI_offset != 0)
    	_rssi_threshold = 8+RSSI_offset;    
//    	_rssi_threshold = 10+RSSI_offset;
   
#ifdef MT6188_DEBUG_DUMP_LOG
   duration_t = video_get_duration_ms(start_t);
   kal_sprintf((void*)_dbg_str, "   time cost: %d ms.\n Chip_ID = %d \n\0", duration_t, Chip_ID);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif

}


/*****************************************************************
*  Radio power off
*
*****************************************************************/
void FMDrv_PowerOffProc(void)
{
   int16 i;
   uint8 tmp_reg;
   
#ifdef MT6188_DEBUG_DUMP_LOG
   if (_file_handle == 0)
      ASSERT(0);
   kal_sprintf((void*)_dbg_str, "\nFMDrv_PowerOffProc();\n\0");
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
   FS_Close(_file_handle);
   _file_handle = 0;
#endif   

#ifdef MT6188_DEBUG_DUMP_LOG
   if (_file_list == 0)
      ASSERT(0);
   kal_sprintf((void*)_list_str, "\nFMDrv_PowerOffProc();\n\0");
   FS_Write(_file_list, _list_str, strlen((void*)_list_str), &_list_written);
   FS_Close(_file_list);
   _file_list = 0;
#endif   
   
   
#ifdef USE_MT6188_AMP
   SwitchExtFMPath(0);
#endif

   SerialCommInit();
   for (i=0; i<POWER_OFF_COMMAND_COUNT; i++) 
   {
      MT6188_ReadByte(PowerOffProc[i].addr, &tmp_reg);
      tmp_reg &= PowerOffProc[i].and;
      tmp_reg |= PowerOffProc[i].or;
      MT6188_WriteByte(PowerOffProc[i].addr, tmp_reg);
   }
   SerialCommCryClkOff();
   SerialCommRelease();
   _is_fm_on = false;
   _current_frequency = -1;
}


/*********************************************************************
*  Radio set frquency
*
*  parameter-->curf:setting frequency value
                    input value: 875 - 1080 ( 87.5 MHz - 108.0 MHz)
*********************************************************************/
void FMDrv_SetFreq( int16 curf )  /* input value: 875 - 1080 ( 87.5 MHz - 108.0 MHz)*/
{
//   if (_current_frequency != curf) {
      int16 HiLo;
      int32 curFreq = (int32)curf * FM_TUNER_GRID;
      
#ifdef MT6188_DEBUG_DUMP_LOG
   uint32 start_t, duration_t;
   kal_sprintf((void*)_dbg_str, "\nFMDrv_SetFreq(%d);\n\0", curf);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
   start_t = video_get_current_time();
#endif      
      
      FMDrv_Mute(1);
      SerialCommInit();
      HiLo = MT6188_HiLoInjectOptimizer(curFreq, 0);
//HiLo = HI_INJECTION;
      if (false == MT6188_SetFreq(curFreq, HiLo)) 
      {
         ASSERT(0);
      }
      SerialCommRelease();
      FMDrv_Mute(0);
      
#ifdef USE_MT6188_AMP
   SwitchExtFMPath(1);
#endif

#ifdef MT6188_DEBUG_DUMP_LOG
   duration_t = video_get_duration_ms(start_t);
   kal_sprintf((void*)_dbg_str, "   time cost: %d ms.\n\0", duration_t);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif

}


/**********************************************************************
*  Get really signal level in current frequency
*
*  parameter-->curf:frequency value of radio now
**********************************************************************/
uint16 FMDrv_GetSigLvl( int16 curf )
{
   uint16 rssi;
   
#ifdef MT6188_DEBUG_DUMP_LOG
   uint32 start_t, duration_t;
   kal_sprintf((void*)_dbg_str, "\nFMDrv_GetSigLvl(%d);\n\0", curf);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
   start_t = video_get_current_time();
#endif   
   
   if (curf != _current_frequency)
   	FMDrv_SetFreq( curf );
   SerialCommInit();
   rssi = MT6188_GetCurRSSI();
   SerialCommRelease();
   
#ifdef MT6188_DEBUG_DUMP_LOG
   duration_t = video_get_duration_ms(start_t);
   kal_sprintf((void*)_dbg_str, "   time cost: %d ms.\n   RSSI returned: %d.\n\0", duration_t, rssi);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif

   return rssi;
}


/**********************************************************************
*  Get really IF count in current frequency
*
*  parameter-->curf:frequency value of radio now
**********************************************************************/
uint16 FMDrv_GetIF( int16 curf)
{
   uint16 IF;

#ifdef MT6188_DEBUG_DUMP_LOG
   uint32 start_t, duration_t;
   kal_sprintf((void*)_dbg_str, "\nFMDrv_GetIF(%d);\n\0", curf);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
   start_t = video_get_current_time();
#endif

   if (curf != _current_frequency)
      FMDrv_SetFreq( curf );
   SerialCommInit();
   IF = MT6188_GetCurIF();
   SerialCommRelease();

#ifdef MT6188_DEBUG_DUMP_LOG
   duration_t = video_get_duration_ms(start_t);
   kal_sprintf((void*)_dbg_str, "   time cost: %d ms.\n   IF returned: %d.\n\0", duration_t, IF );
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif
   return IF;
}

void FMDrv_EvaluateRSSIThreshold(void) {
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef MT6188_DEBUG_DUMP_LOG
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef MT6188_DEBUG_DUMP_LOG
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef MT6188_DEBUG_DUMP_LOG
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#endif
}


/**********************************************************************
*  Radio valid station,used in auto search frequency to verify 
*  valid positon
*
*  parameter-->freq: frequency
               signalv1:signal level range is 0 ~ 15 
               is_step_up:return value(Reserved)
**********************************************************************/
uint8 FMDrv_ValidStop(int16 freq, int8 signalvl, bool is_step_up)
{
   int32 targetFreq;
   int16 IF_cnt;
   int16 RSSI;
//   int8 pt;
    
//uint32 save_irq_mask;
   
#ifdef MT6188_DEBUG_DUMP_LOG
   uint32 start_t, duration_t;
   kal_sprintf((void*)_dbg_str, "\nFMDrv_ValidStop(%d, %d, %d);\n\0", freq, signalvl, is_step_up);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
   start_t = video_get_current_time();
#endif   

//save_irq_mask=SaveAndSetIRQMask();   
   SerialCommInit();
   
   targetFreq = (int32)freq;
   targetFreq *= FM_TUNER_GRID;
   
   if (targetFreq == 104000 )
   	{
   		return 0;
   	}
 
   /// check RSSI at low side
   MT6188_SetFreq(targetFreq, LO_INJECTION);

#ifdef MT6188_timing_cal
#ifdef MT6188_DEBUG_DUMP_LOG
   duration_t = video_get_duration_ms(start_t);
   kal_sprintf((void*)_dbg_str, "  Set_freq_Lo time cost: %d ms.\n\0", duration_t);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif   
#endif
   
   if ((RSSI = (int16)MT6188_GetCurRSSI()) < _rssi_threshold) 
   {
#ifdef MT6188_DEBUG_DUMP_LOG
      duration_t = video_get_duration_ms(start_t);
      kal_sprintf((void*)_dbg_str, "   time cost: %d ms.\n   #1 RSSI Check Fail! (%d < %d)\n  RESULT:(Freq_Lo,RSSI):(%d,%d)\n\0", duration_t, RSSI, _rssi_threshold,targetFreq,RSSI);
      FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif
   	
      SerialCommRelease();
      return 0;
   }
   else
   {
#ifdef MT6188_DEBUG_DUMP_LOG
      duration_t = video_get_duration_ms(start_t);
      kal_sprintf((void*)_dbg_str, "   time cost: %d ms.\n   #1 RSSI Check OK! (%d > %d)\n  RESULT:(Freq_Lo,RSSI):(%d,%d)\n\0", duration_t, RSSI, _rssi_threshold,targetFreq,RSSI);
      FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif
    }
  
   IF_cnt = MT6188_GetCurIFCnt(IF_MEASURE_COUNT,0);

#ifdef MT6188_timing_cal
#ifdef MT6188_DEBUG_DUMP_LOG
      duration_t = video_get_duration_ms(start_t);
      kal_sprintf((void*)_dbg_str, "  IF_RSSI check time cost: %d ms.\n   IF/RSSI Check (%d,%d)\n RESULT:(Freq_Lo,IF_cnt,RSSI):(%d,%d,%d)\n\0", duration_t, IF_cnt, RSSI,targetFreq,IF_cnt,RSSI);
      FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif
#endif

if (Chip_ID == 5)
{   
    if (IF_cnt > (PRESET_IF_CNT + PRESET_IF_DELTA ) || 
       IF_cnt < (PRESET_IF_CNT - PRESET_IF_DELTA )) 
   {
      		SerialCommRelease();
      		
#ifdef MT6188_timing_cal      		
#ifdef MT6188_DEBUG_DUMP_LOG
      duration_t = video_get_duration_ms(start_t);
      kal_sprintf((void*)_dbg_str, "  IF_RSSI check time cost: %d ms.\n   IF/RSSI Check Fail! (%d,%d)\n	IF range(%d,%d)\n\0", duration_t, IF_cnt, RSSI,PRESET_IF_CNT - PRESET_IF_DELTA,PRESET_IF_CNT + PRESET_IF_DELTA );
      FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif
#endif
      		
      		return 0;
   }
   else
   {
#ifdef MT6188_timing_cal      		
#ifdef MT6188_DEBUG_DUMP_LOG
      duration_t = video_get_duration_ms(start_t);
      kal_sprintf((void*)_dbg_str, "  IF_RSSI check time cost: %d ms.\n   IF/RSSI Check OK! (%d,%d)\n	IF range(%d,%d)\n\0", duration_t, IF_cnt, RSSI,PRESET_IF_CNT - PRESET_IF_DELTA,PRESET_IF_CNT + PRESET_IF_DELTA );
      FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif
#endif
   }
}   //end Chip_ID = 5
else    //Chip_ID = 4/3
{
   if (IF_cnt > (PRESET_IF_CNT + PRESET_IF_DELTA ) || 
       IF_cnt < (PRESET_IF_CNT - PRESET_IF_DELTA - PRESET_IF_OFFSET)) 
   {
      		SerialCommRelease();
      		
#ifdef MT6188_timing_cal      		
#ifdef MT6188_DEBUG_DUMP_LOG
      duration_t = video_get_duration_ms(start_t);
      kal_sprintf((void*)_dbg_str, "  IF_RSSI check time cost: %d ms.\n   IF/RSSI Check Fail! (%d,%d)\n	IF range(%d,%d)\n\0", duration_t, IF_cnt, RSSI,PRESET_IF_CNT - PRESET_IF_DELTA - PRESET_IF_OFFSET,PRESET_IF_CNT + PRESET_IF_DELTA );
      FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif
#endif
      		
      		return 0;
   }
   else
   {
#ifdef MT6188_timing_cal      		
#ifdef MT6188_DEBUG_DUMP_LOG
      duration_t = video_get_duration_ms(start_t);
      kal_sprintf((void*)_dbg_str, "  IF_RSSI check time cost: %d ms.\n   IF/RSSI Check OK! (%d,%d)\n	IF range(%d,%d)\n\0", duration_t, IF_cnt, RSSI,PRESET_IF_CNT - PRESET_IF_DELTA - PRESET_IF_OFFSET,PRESET_IF_CNT + PRESET_IF_DELTA );
      FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif
#endif
   }
}   //end Chip_ID = 4/3

   /// check RSSI at hi side
   MT6188_SetFreq(targetFreq, HI_INJECTION);

#ifdef MT6188_timing_cal
#ifdef MT6188_DEBUG_DUMP_LOG
   duration_t = video_get_duration_ms(start_t);
   kal_sprintf((void*)_dbg_str, "  Set_freq_Hi time cost: %d ms.\n\0", duration_t);
   FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif   
#endif
   
   if ((RSSI = (int16)MT6188_GetCurRSSI()) < _rssi_threshold) 
   {
#ifdef MT6188_DEBUG_DUMP_LOG
      duration_t = video_get_duration_ms(start_t);
      kal_sprintf((void*)_dbg_str, "   time cost: %d ms.\n   #1 RSSI Check Fail! (%d < %d)\n RESULT:(Freq_Hi,RSSI):(%d,%d)\n\0", duration_t, RSSI, _rssi_threshold, targetFreq, RSSI);
      FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif
      SerialCommRelease();
      return 0;
   }
   else
   {
#ifdef MT6188_DEBUG_DUMP_LOG
      duration_t = video_get_duration_ms(start_t);
      kal_sprintf((void*)_dbg_str, "   time cost: %d ms.\n   #1 RSSI Check OK! (%d > %d)\n RESULT:(Freq_Hi,RSSI):(%d,%d)\n\0", duration_t, RSSI, _rssi_threshold, targetFreq, RSSI);
      FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif
   }
   
   IF_cnt = MT6188_GetCurIFCnt(IF_MEASURE_COUNT,0);

#ifdef MT6188_timing_cal
#ifdef MT6188_DEBUG_DUMP_LOG
      duration_t = video_get_duration_ms(start_t);
      kal_sprintf((void*)_dbg_str, "  IF_RSSI time cost: %d ms.\n   IF/RSSI Check (%d,%d)\n RESULT:(Freq_Hi,IF_cnt,RSSI):(%d,%d,%d)\n\0", duration_t, IF_cnt, RSSI,targetFreq, IF_cnt, RSSI);
      FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif
#endif

if (Chip_ID ==5)
{
    if (IF_cnt > (PRESET_IF_CNT + PRESET_IF_DELTA ) || 
       IF_cnt < (PRESET_IF_CNT - PRESET_IF_DELTA )) 
   {
      SerialCommRelease();
#ifdef MT6188_timing_cal
#ifdef MT6188_DEBUG_DUMP_LOG
      duration_t = video_get_duration_ms(start_t);
      kal_sprintf((void*)_dbg_str, "  IF_RSSI time cost: %d ms.\n   IF/RSSI Check Fail! (%d,%d)\n	IF range(%d,%d)\n\0", duration_t, IF_cnt, RSSI,PRESET_IF_CNT - PRESET_IF_DELTA,PRESET_IF_CNT + PRESET_IF_DELTA );
      FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif
#endif
      return 0;
   }
   else
   {
#ifdef MT6188_timing_cal
#ifdef MT6188_DEBUG_DUMP_LOG
      duration_t = video_get_duration_ms(start_t);
      kal_sprintf((void*)_dbg_str, "  IF_RSSI time cost: %d ms.\n   IF/RSSI Check OK! (%d,%d)\n	IF range(%d,%d)\n\0", duration_t, IF_cnt, RSSI,PRESET_IF_CNT - PRESET_IF_DELTA,PRESET_IF_CNT + PRESET_IF_DELTA );
      FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif
#endif
   }
}   //end Chip_ID = 5
else    //Chip_ID = 4/3
{   
   if (IF_cnt > (PRESET_IF_CNT + PRESET_IF_DELTA ) || 
       IF_cnt < (PRESET_IF_CNT - PRESET_IF_DELTA - PRESET_IF_OFFSET)) 
   {
      SerialCommRelease();
#ifdef MT6188_timing_cal
#ifdef MT6188_DEBUG_DUMP_LOG
      duration_t = video_get_duration_ms(start_t);
      kal_sprintf((void*)_dbg_str, "  IF_RSSI time cost: %d ms.\n   IF/RSSI Check Fail! (%d,%d)\n	IF range(%d,%d)\n\0", duration_t, IF_cnt, RSSI,PRESET_IF_CNT - PRESET_IF_DELTA - PRESET_IF_OFFSET,PRESET_IF_CNT + PRESET_IF_DELTA );
      FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif
#endif
      return 0;
   }
   else
   {
#ifdef MT6188_timing_cal
#ifdef MT6188_DEBUG_DUMP_LOG
      duration_t = video_get_duration_ms(start_t);
      kal_sprintf((void*)_dbg_str, "  IF_RSSI time cost: %d ms.\n   IF/RSSI Check OK! (%d,%d)\n	IF range(%d,%d)\n\0", duration_t, IF_cnt, RSSI,PRESET_IF_CNT - PRESET_IF_DELTA - PRESET_IF_OFFSET,PRESET_IF_CNT + PRESET_IF_DELTA );
      FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif
#endif
   }
}   //end Chip_ID = 4/3

if (Chip_ID == 5)
{
#ifdef MT6188_DEBUG_DUMP_LOG
    kal_sprintf((void*)_list_str, "  channel list/RSSI Check! (%d,%d)\n	IF range(%d,%d)\n\0", targetFreq, RSSI,PRESET_IF_CNT - PRESET_IF_DELTA,PRESET_IF_CNT + PRESET_IF_DELTA );
    FS_Write(_file_list, _list_str, strlen((void*)_list_str), &_list_written);
#endif   
}
else    //Chip_ID = 4/3
{
#ifdef MT6188_DEBUG_DUMP_LOG
    kal_sprintf((void*)_list_str, "  channel list/RSSI Check! (%d,%d)\n	IF range(%d,%d)\n\0", targetFreq, RSSI,PRESET_IF_CNT - PRESET_IF_DELTA - PRESET_IF_OFFSET,PRESET_IF_CNT + PRESET_IF_DELTA );
    FS_Write(_file_list, _list_str, strlen((void*)_list_str), &_list_written);
#endif   
}

   FMDrv_SetVolumeLevel(_current_level);
   SerialCommRelease();

//RestoreIRQMask(save_irq_mask);   

#ifdef MT6188_DEBUG_DUMP_LOG
      duration_t = video_get_duration_ms(start_t);
      kal_sprintf((void*)_dbg_str, "   time cost: %d ms.\n   Pass! RESULT:(Freq, IF, RSSI) = (%d, %d, %d)\n\0", duration_t, targetFreq, IF_cnt, RSSI);
      FS_Write(_file_handle, _dbg_str, strlen((void*)_dbg_str), &_data_written);
#endif

   return 1;
}

void FMDrv_ChipInit(void)
{
   /// power down the chip
   int32 i;
   uint8 tmp_reg;
   SerialCommInit();
   
   MT6188_ReadByte(CW(0, 1), &Chip_ID);
    Chip_ID &= 0x07;
   
   for (i=0; i<POWER_OFF_COMMAND_COUNT; i++) 
   {
      MT6188_ReadByte(PowerOffProc[i].addr, &tmp_reg);
      tmp_reg &= PowerOffProc[i].and;
      tmp_reg |= PowerOffProc[i].or;
      MT6188_WriteByte(PowerOffProc[i].addr, tmp_reg);
   }
   SerialCommCryClkOff();
   SerialCommRelease();
#ifdef USE_MT6188_AMP
   ExtSwitchInit();
#endif
}

bool FMDrv_IsChipValid( void )
{
	/// anything to do?
	return true;
}

uint16 FMDrv_ReadByte(uint8 addr)
{
	uint16 Data;
	uint8 TmpReg1, TmpReg2;
	MT6188_ReadByte(CW(addr, 0), &TmpReg1);
	MT6188_ReadByte(CW(addr, 1), &TmpReg2);
	Data = ((TmpReg2<<8)|TmpReg1);
	return Data;
}

bool FMDrv_WriteByte(uint8 addr, uint16 data)
{
	uint8 Data_M, Data_L;
	Data_M = data>>8;
	Data_L = data&0xFF;
	MT6188_WriteByte(CW(addr,0), Data_L);
	MT6188_WriteByte(CW(addr,1), Data_M);
}

void FMDrv_SoftMuteOnOff(uint8 On_Off)
{
    uint8 TmpReg;
    if (Chip_ID == 5)
    {
        if (On_Off)
        {
            MT6188_ReadByte(CW(14, 0), &TmpReg);
      	    TmpReg&=0xF7;
      	    MT6188_WriteByte(CW(14, 0),TmpReg|0x08);
      	}
      	else
      	{
      	    MT6188_ReadByte(CW(14, 0), &TmpReg);
      	    TmpReg&=0xF7;
      	    MT6188_WriteByte(CW(14, 0),TmpReg);
      	}
    }
}

void FMDrv_SoftMuteStage(uint8 stage)
{
	uint8 TmpReg;
	if (Chip_ID == 5)
	{
		        MT6188_ReadByte(CW(17, 1), &TmpReg);//CW17_1 [15]0
      	    	TmpReg&=0x7F;
      	    	MT6188_WriteByte(CW(17, 1),TmpReg);
      	    		
      	    	MT6188_ReadByte(CW(18, 0), &TmpReg);//CW18_0 [3] 1
      	    	TmpReg&=0xF7;
      	    	MT6188_WriteByte(CW(18, 0),TmpReg|0x08);
      	    		
      	    	MT6188_ReadByte(CW(18, 1), &TmpReg);//CW18_1 [11] 0
      	    	TmpReg&=0xF7;
      	    	MT6188_WriteByte(CW(18, 1),TmpReg);
      	    	
      	    	MT6188_ReadByte(CW(22, 1), &TmpReg);//CW22_1 [14:11] 1000
      	    	TmpReg&=0x87;
      	    	MT6188_WriteByte(CW(22, 1),TmpReg|0x40);
      	    	
		switch (stage)
		{
		    case 1:			      	    		
      	        		MT6188_ReadByte(CW(22, 1), &TmpReg);//CW22_1 [15] 1
      	        		TmpReg&=0x7F;
      	        		MT6188_WriteByte(CW(22, 1),TmpReg|0x80);
      	        		
      	        		MT6188_ReadByte(CW(22, 0), &TmpReg);//CW22_0 [7:5] 0
      	        		TmpReg&=0x1F;
      	        		MT6188_WriteByte(CW(22, 0),TmpReg);
		    break;
		    case 2:
		    	MT6188_ReadByte(CW(22, 1), &TmpReg);//CW22_1 [15] 0
      	        		TmpReg&=0x7F;
      	        		MT6188_WriteByte(CW(22, 1),TmpReg);
      	        		
      	        		MT6188_ReadByte(CW(22, 0), &TmpReg);//CW22_0 [7:5] 0
      	        		TmpReg&=0x1F;
      	        		MT6188_WriteByte(CW(22, 0),TmpReg);
		    break;
		    case 3:
		    	MT6188_ReadByte(CW(22, 1), &TmpReg);//CW22_1 [15] 0
      	        		TmpReg&=0x7F;
      	        		MT6188_WriteByte(CW(22, 1),TmpReg);
      	        		
      	        		MT6188_ReadByte(CW(22, 0), &TmpReg);//CW22_0 [7:5] 2
      	        		TmpReg&=0x1F;
      	        		MT6188_WriteByte(CW(22, 0),TmpReg|0x40);
		    break;
	    }
	}
}

void FMDrv_StereoBlendStage(uint8 stage)
{
	uint8 TmpReg;
	if (Chip_ID == 5)
	{
		switch (stage)
		{
		    case 1:
		    	MT6188_ReadByte(CW(17, 0), &TmpReg);//CW17_0 [4:2] 3 [0:1] 2
      	        		TmpReg&=0xE0;
      	        		MT6188_WriteByte(CW(17, 0),TmpReg|0x0E);
      	        		
      	        		MT6188_ReadByte(CW(19, 0), &TmpReg);//CW19_0 [4:2] 6 [6:5] 1
      	        		TmpReg&=0x83;
      	        		MT6188_WriteByte(CW(19, 0),TmpReg|0x38);
      	        		
      	        		MT6188_ReadByte(CW(22, 0), &TmpReg);//CW22_0 [4:2] 1
      	        		TmpReg&=0xE3;
      	        		MT6188_WriteByte(CW(22, 0),TmpReg|0x04);
      	        		
      	        		MT6188_ReadByte(CW(10, 1), &TmpReg);//CW10_1 [12:9] 4
      	        		TmpReg&=0xE1;
      	        		MT6188_WriteByte(CW(10, 1),TmpReg|0x08);
		    break;
		    case 2:
		    	MT6188_ReadByte(CW(17, 0), &TmpReg);//CW17_0 [4:2] 4 [0:1] 0
      	        		TmpReg&=0xE0;
      	        		MT6188_WriteByte(CW(17, 0),TmpReg|0x10);
      	        		
      	        		MT6188_ReadByte(CW(19, 0), &TmpReg);//CW19_0 [4:2] 7 [6:5] 1
      	        		TmpReg&=0x83;
      	        		MT6188_WriteByte(CW(19, 0),TmpReg|0x3C);
      	        		
      	        		MT6188_ReadByte(CW(22, 0), &TmpReg);//CW22_0 [4:2] 1
      	        		TmpReg&=0xE3;
      	        		MT6188_WriteByte(CW(22, 0),TmpReg|0x04);
      	        		
      	        		MT6188_ReadByte(CW(10, 1), &TmpReg);//CW10_1 [12:9] 4
      	        		TmpReg&=0xE1;
      	        		MT6188_WriteByte(CW(10, 1),TmpReg|0x08);
		    break;
		    case 3:
		    	MT6188_ReadByte(CW(17, 0), &TmpReg);//CW17_0 [4:2] 0 [0:1] 0
      	        		TmpReg&=0xE0;
      	        		MT6188_WriteByte(CW(17, 0),TmpReg);
      	        		
      	        		MT6188_ReadByte(CW(19, 0), &TmpReg);//CW19_0 [4:2] 0 [6:5] 0
      	        		TmpReg&=0x83;
      	        		MT6188_WriteByte(CW(19, 0),TmpReg);
      	        		
      	        		MT6188_ReadByte(CW(22, 0), &TmpReg);//CW22_0 [4:2] 0
      	        		TmpReg&=0xE3;
      	        		MT6188_WriteByte(CW(22, 0),TmpReg);
      	        		
      	        		MT6188_ReadByte(CW(10, 1), &TmpReg);//CW10_1 [12:9] 0
      	        		TmpReg&=0xE1;
      	        		MT6188_WriteByte(CW(10, 1),TmpReg);
		    break;
	    }
	}
}

uint8 FMDrv_GetChipID(void)
{
	uint8 ChipID;
	MT6188_ReadByte(CW(0, 1), &ChipID);
    	ChipID &= 0x07;
    	
    	return ChipID;
}

uint8 FMDrv_Get_H_L_side(kal_int16 curf) /* input value: 875 - 1080 ( 87.5 MHz - 108.0 MHz)*/
{
	uint8 tempreg;
	MT6188_ReadByte(CW(4, 0), &tempreg);
	if (tempreg & 0x80)
		return 1;
	else
		return 0;	
}

uint8 FMDrv_Get_stereo_mono(void)
{
	uint8 tempreg;
	MT6188_ReadByte(CW(14, 0), &tempreg);
	if (tempreg & 0x01)
		return 1;
	else
		return 0;	
}
#endif
