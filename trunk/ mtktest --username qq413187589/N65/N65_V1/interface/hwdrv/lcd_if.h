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
 *   This file is for LCD interface driver.
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
 * include drv_features.h
 *
 * removed!
 * removed!
 * Add LCD driver feature: background color and memory output
 *
 * removed!
 * removed!
 * deprecate lcd_power_[up|down], use lcd_power_ctrl instead.
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * Also phase out 6218B.
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
 *******************************************************************************/
#ifndef __LCD_IF_H__
#define __LCD_IF_H__


#include "kal_release.h"
#include "drv_features.h"
#include "lcd_if_hw.h"

   /*won't change according to chip*/   
   #define LCD_LAYER0_ENABLE     0x80000000
   #define LCD_LAYER1_ENABLE     0x40000000
   #define LCD_LAYER2_ENABLE     0x20000000
   #define LCD_LAYER3_ENABLE     0x10000000
   #define LCD_LAYER4_ENABLE     0x08000000
   #define LCD_LAYER5_ENABLE     0x04000000
   
   #define LCD_LAYER_ROTATE_NORMAL        0
   #define LCD_LAYER_ROTATE_90            1
   #define LCD_LAYER_ROTATE_180           2
   #define LCD_LAYER_ROTATE_270           3
   #define LCD_LAYER_MIRROR               4
   #define LCD_LAYER_MIRROR_ROTATE_90     5
   #define LCD_LAYER_MIRROR_ROTATE_180    6
   #define LCD_LAYER_MIRROR_ROTATE_270    7
   
   /* definition of LCM data outptu format */
   #define LCM_8BIT_8_BPP_RGB332_1     0x00  /* RRRGGBB */
   #define LCM_8BIT_8_BPP_RGB332_2     0x01  /* BBGGGRR */
   #define LCM_8BIT_12_BPP_RGB444_1    0x08  /* RRRRGGGG, BBBBRRRR, GGGGBBBB */
   #define LCM_8BIT_12_BPP_RGB444_2    0x0B  /* GGGGRRRR, RRRRBBBB, BBBBGGGG */
   #define LCM_8BIT_16_BPP_RGB565_1    0x10  /* RRRRRGGG, GGGBBBBB */
   #define LCM_8BIT_16_BPP_RGB565_2    0x12  /* GGGBBBBB, RRRRRGGG */
   #define LCM_8BIT_16_BPP_BGR565_1    0x11  /* BBBBBGGG, GGGRRRRR */
   #define LCM_8BIT_16_BPP_BGR565_2    0x13  /* GGGRRRRR, BBBBBGGG */
   #define LCM_8BIT_18_BPP_RGB666_1    0x18  /* RRRRRRXX, GGGGGGXX, BBBBBBXX */
   #define LCM_8BIT_18_BPP_RGB666_2    0x1C  /* XXRRRRRR, XXGGGGGG, XXBBBBBB */
   #define LCM_8BIT_24_BPP_RGB888_1    0x20  /* RRRRRRRR, GGGGGGGG, BBBBBBBB */
   #define LCM_16BIT_8_BPP_RGB332_1    0x40  /* RRRGGGBBRRRGGGBB, MSB first*/
   #define LCM_16BIT_8_BPP_RGB332_2    0x42  /* RRRGGGBBRRRGGGBB, LSB first*/
   #define LCM_16BIT_8_BPP_RGB332_3    0x41  /* BBGGGRRRBBGGGRRR, MSB first */
   #define LCM_16BIT_8_BPP_RGB332_4    0x43  /* BBGGGRRRBBGGGRRR, LSB first */
   #define LCM_16BIT_12_BPP_RGB444_1   0x4C  /* XXXXRRRRGGGGBBBB */
   #define LCM_16BIT_12_BPP_RGB444_2   0x4D  /* XXXXBBBBGGGGRRRR */
   #define LCM_16BIT_12_BPP_RGB444_3   0x48  /* RRRRGGGGBBBBXXXX */
   #define LCM_16BIT_12_BPP_RGB444_4   0x49  /* BBBBGGGGRRRRXXXX */
   #define LCM_16BIT_16_BPP_RGB565_1   0x50  /* RRRRRGGGGGGBBBBB */
   #define LCM_16BIT_16_BPP_RGB565_2   0x52  /* GGGBBBBBRRRRRGGG */
   #define LCM_16BIT_16_BPP_BGR565_1   0x51  /* BBBBBGGGGGGRRRRR */
   #define LCM_16BIT_16_BPP_BGR565_2   0x53  /* GGGRRRRRBBBBBGGG */
   #define LCM_16BIT_18_BPP_RGB666_1   0x5C  /* XXXXRRRRRRGGGGGG, XXXXBBBBBBRRRRRR, XXXXGGGGGGBBBBBB */
   #define LCM_16BIT_18_BPP_RGB666_2   0x5F  /* XXXXGGGGGGRRRRRR, XXXXRRRRRRBBBBBB, XXXXBBBBBBGGGGGG */
   #define LCM_16BIT_18_BPP_RGB666_3   0x58  /* RRRRRRGGGGGGXXXX, BBBBBBRRRRRRXXXX, GGGGGGBBBBBBXXXX */
   #define LCM_16BIT_18_BPP_RGB666_4   0x5B  /* GGGGGGRRRRRRXXXX, RRRRRRBBBBBBXXXX, BBBBBBGGGGGGXXXX */
   #define LCM_16BIT_24_BPP_RGB888_1   0x60  /* RRRRRRRRGGGGGGGG, BBBBBBBBRRRRRRRR, GGGGGGGGBBBBBBBB */
   #define LCM_16BIT_24_BPP_RGB888_2   0x63  /* GGGGGGGGRRRRRRRR, RRRRRRRRBBBBBBBB, BBBBBBBBGGGGGGGG */   
   
   #define LCM_9BIT_8_BPP_RGB332_1     0x80  /* RRRGGGBBX */
   #define LCM_9BIT_8_BPP_RGB332_2     0x81  /* BBGGGRRRX */
   #define LCM_9BIT_12_BPP_RGB444_1    0x88  /* RRRRGGGGX, BBBBRRRRX, GGGGBBBBX */
   #define LCM_9BIT_12_BPP_RGB444_2    0x8B  /* GGGGRRRRX, RRRRBBBBX, BBBBGGGGX */
   #define LCM_9BIT_16_BPP_RGB565_1    0x90  /* RRRRRGGGX, GGGBBBBBX */
   #define LCM_9BIT_16_BPP_RGB565_2    0x93  /* GGGRRRRRX, BBBBBGGGX */
   #define LCM_9BIT_18_BPP_RGB666_1    0x98  /* RRRRRRGGG, GGGBBBBBB */
   #define LCM_9BIT_18_BPP_RGB666_2    0x9B  /* GGGRRRRRR, BBBBBBGGG */
   #define LCM_9BIT_24_BPP_RGB888_1    0xA0  /* RRRRRRRRX, GGGGGGGGX, BBBBBBBBX */
   #define LCM_18BIT_8_BPP_RGB332_1    0xC0  /* RRRGGGBBRRRGGGBBXX, MSB first */
   #define LCM_18BIT_8_BPP_RGB332_2    0xC2  /* RRRGGGBBRRRGGGBBXX, LSB first */
   #define LCM_18BIT_8_BPP_RGB332_3    0xC1  /* BBGGGRRRBBGGGRRRXX, MSB first */
   #define LCM_18BIT_8_BPP_RGB332_4    0xC3  /* BBGGGRRRBBGGGRRRXX, LSB first */
   #define LCM_18BIT_12_BPP_RGB444_1   0xCC  /* XXXXXXRRRRGGGGBBBB */
   #define LCM_18BIT_12_BPP_RGB444_2   0xCD  /* XXXXXXBBBBGGGGRRRR */
   #define LCM_18BIT_12_BPP_RGB444_3   0xC8  /* RRRRGGGGBBBBXXXXXX */
   #define LCM_18BIT_12_BPP_RGB444_4   0xC9  /* BBBBGGGGRRRRXXXXXX */
   #define LCM_18BIT_16_BPP_RGB565_1   0xD0  /* RRRRRGGGGGGBBBBBXX */
   #define LCM_18BIT_16_BPP_RGB565_2   0xD1  /* BBBBBGGGGGGRRRRRXX */
   #define LCM_18BIT_18_BPP_RGB666_1   0xD8  /* RRRRRRGGGGGGBBBBBB */
   #define LCM_18BIT_18_BPP_RGB666_2   0xD9  /* BBBBBBGGGGGGRRRRRR */
   #define LCM_18BIT_24_BPP_RGB888_1   0xE0  /* RRRRRRRRGGGGGGGGXX, BBBBBBBBRRRRRRRRXX, GGGGGGGGBBBBBBBBXX */
   #define LCM_18BIT_24_BPP_RGB888_2   0xE3  /* GGGGGGGGRRRRRRRRXX, RRRRRRRRBBBBBBBBXX, BBBBBBBBGGGGGGGGXX */   


typedef enum
{
   MAIN_LCD = 1,
   SUB_LCD =  2
} LCD_TYPE_ENUM;

typedef enum
{
    LCM_TRANSMISSIVE_TYPE = 0 ,
    LCM_TRANSFLECTIVE_TYPE
} LCM_TRANSMISSIVE_TRANSFLECTIVE_TYPE_ENUM;


typedef enum
{
   LCD_IDLE_STATE=0,
   LCD_INITIAL_STATE,
   LCD_STANDBY_STATE,
   LCD_SLEEP_STATE,
   LCD_SW_UPDATE_STATE,
   LCD_MEM_UPDATE_STATE,
   LCD_JPEG_VIDEO_UPDATE_STATE,
   LCD_JPEG_VIDEO_CMD_QUEUE_STATE,
   LCD_CAMERA_ACTIVE_STATE,
   LCD_CAMERA_ACTIVE_UPDATE_STATE,
   LCD_CAMERA_UPDATE_STATE,
   LCD_CAMERA_CMD_QUEUE_STATE,
   LCD_HW_UPDATE_STATE,
   LCD_DC_UPDATE_STATE,
   LCD_HW_CMD_QUEUE_STATE,
   LCD_DC_CMD_QUEUE_STATE,
   LCD_WAIT_LAST_UPDATE_STATE,
   LCD_DC_UPDATE_SLEEP_STATE,
   LCD_HW_UPDATE_SLEEP_STATE,
   LCD_DC_SLEEP_CMD_QUEUE_STATE,
   LCD_HW_SLEEP_CMD_QUEUE_STATE,
   LCD_FW_UPDATE_STATE,/*supported on MT6225 like platform*/
   LCD_FW_CMD_QUEUE_STATE,/*supported on MT6225 like platform*/
   MAX_LCD_OPERATION_STATE
}  LCD_OPERATION_STATE_ENUM;

typedef enum
{
   LCD_IDMA_TRIGGER_SRC_IRT1=0,   
   LCD_IDMA_TRIGGER_SRC_IBW1,   
   LCD_IDMA_TRIGGER_SRC_IRT2,   
   LCD_IDMA_TRIGGER_SRC_IBW2,
   MAX_LCD_IDMA_TRIGGER_SRC
}  LCD_IDMA_TRIGGER_SRC_ENUM;


/*SW XXX*/
typedef enum
{
   LCD_LAYER0 = 0,       
   LCD_LAYER1 = 1,       
   LCD_LAYER2 = 2,       
   LCD_LAYER3 = 3,       
   LCD_LAYER4 = 4,       
   LCD_LAYER5 = 5          
}  LCD_LAYER_ENUM;

typedef enum
{
   LCD_GAMMA_TABLE0 = 0,
   LCD_GAMMA_TABLE1 = 1,
   LCD_GAMMA_TABLE2 = 2
}  LCD_GAMMA_TABLE_ENUM;



/*SW XXX*/
typedef enum
{
   LCD_UPDATE_MODULE_MMI         = 0,
   LCD_UPDATE_MODULE_MEDIA          ,
   LCD_UPDATE_MODULE_JPEG_VIDEO     ,
   LCD_UPDATE_MODULE_EXT_CAMERA   
}  LCD_OWNER_ID_ENUM;



/*SW XXX*/
typedef enum
{
   LCD_SW_TRIGGER_MODE     =   0,     /* LCD SW trigger with frame buffer */   
   LCD_HW_TRIGGER_MODE     =   1,     /* LCD HW trigger with frame buffer */
   LCD_DIRECT_COUPLE_MODE  =   2      /* LCD HW trigger without frame buffer, direct couple */
}  LCD_UPDATE_MODE_ENUM;     
typedef enum
{      
   LCD_HW_TRIGGER_IBW1 =  0,
   LCD_HW_TRIGGER_IBW2 =  1,         
   LCD_HW_TRIGGER_IRT1 =  2,
   LCD_HW_TRIGGER_IRT2 =  3         
}  LCD_HW_TRIGGER_SRC_ENUM;     

typedef enum
{      
   LCD_TRANSFER_COMPLETE_EVENT =   0x00000001,
   LCD_DATA_COMPLETE_EVENT     =   0x00000002,
   LCD_CMD_COMPLETE_EVENT      =   0x00000004
}  LCD_EVENT_ENUM;     

typedef enum
{    
   LCD_COLOR_PALETTE0  =  0,
   LCD_COLOR_PALETTE1  =  1
}  LCD_PALETTTE_ENUM;     

typedef enum
{    
   LCD_WM_CONT_MODE    =     0,
   LCD_WM_BLOCK_MODE   =     1
}  LCD_MEMORY_OUTUT_MODE_ENUM;     

typedef enum
{    
   LCD_DRIVING_2MA = 0,
   LCD_DRIVING_4MA = 1,
   LCD_DRIVING_6MA = 2,
   LCD_DRIVING_8MA = 3
}  LCD_DRIVING_CURRENT_ENUM;     



/// Engineering mode
typedef enum {
   lcd_Bais_func,
   lcd_Contrast_func,
   lcd_LineRate_func,
   lcd_Temperature_Compensation_func
} lcd_func_type;

typedef struct
{
   void (* Init)(kal_uint32 background, void **buf_addr);
   void (* TurnOnPower)(kal_bool on);
   void (* SetBrightLevel)(kal_uint8 level);
   void (* TurnOnScreen)(kal_bool on);
   void (* BlockWrite)(kal_uint16 startx,kal_uint16 starty,kal_uint16 endx,kal_uint16 endy);
   void (* GetSize)(kal_uint16 *out_LCD_width,kal_uint16 *out_LCD_height);
   void (* EnterSleepMode)(void);
   void (* ExitSleepMode)(void);
   void (* TurnOnPartialDisplay) (kal_uint16 start_page,kal_uint16 end_page);
   void (* TurnOffPartialDisplay) (void);
   kal_uint8 (*GetPartialDisplayAlignment) (void);
   /*Engineering mode*/
   kal_uint8 (* GetEngineeringModeParamNumber)(lcd_func_type type);
   void (* SetBias)(kal_uint8 *bias);
   void (* SetContrast)(kal_uint8 *contrast);
   void (* SetLineRate)(kal_uint8 *linerate);
   void (* SetTemperatureCompensate)(kal_uint8 *compensate);
#ifdef __LCD_ESD_RECOVERY__
   kal_bool (* CheckESD)(void);
#endif
#ifdef LCM_ROTATE_SUPPORT
   void (* SetRotation)(kal_uint8 rotate_value);
#endif
}LCD_Funcs;



typedef struct
{
   kal_bool    layer_update_queue;     /* lcd layer parameter queue is full or not */
   kal_bool    source_key_enable;      /* enable/disable source key for specified layer */
   kal_bool    color_palette_enable;   /* enable/disable color palette for specified layer */
   kal_bool    opacity_enable;         /* enable/disable opacity for specified layer */
   kal_uint8   source_color_format;    /* color format of the specified layer, for MT6228 and MT6229 only */
   kal_uint8   color_palette_select;   /* selection of color palette table */
   kal_uint8   opacity_value;          /* opacity value for specified layer */
   kal_uint8   rotate_value;           /* rotate select for specified layer */
   kal_uint16  x_offset;               /* x axis offset from main window for specified layer */
   kal_uint16  y_offset;               /* y axis offset from main widnow for specified layer */
   kal_uint16  row_number;             /* layer buffer height of specified layer */
   kal_uint16  column_number;          /* layer buffer width of specified layer */
   kal_uint32  source_key;             /* source key color in RGB565 format for specified layer */
   kal_uint32  frame_buffer_address;   /* frame buffer start address of specified layer */
} lcd_layer_struct;



typedef struct
{
   /// module ID that request frame buffer update
   /// LCD_UPDATE_MODULE_MMI, LCD_UPDATE_MODULE_MEDIA, LCD_UPDAET_MODULE_EXT_CAMERA, LCD_UPDATE_MODULE_JPEG_VIDEO
   kal_uint8 module_id;
   /// which lcd will be updated (MAIN_LCD or SUB_LCD)
   kal_uint8 lcd_id;
   /// block caller or not
   kal_bool block_mode_flag;
   /// callback when lcd update is done
   void (* lcd_block_mode_cb)(void);
   //// frame buffer update mode (SW_TRIGGER, HW_TRIGGER or DIRECT_COUPLE)
   kal_uint8 fb_update_mode;
   /// the starting x coordinate of LCM to be updated
   kal_uint16 lcm_start_x;
   /// the starting y coordinate of LCM to be updated
   kal_uint16 lcm_start_y;
   /// the ending x coordinate of LCM to be updated
   kal_uint16 lcm_end_x;
   /// the ending y coordinate of LCM to be updated
   kal_uint16 lcm_end_y;
   /// the ROI window offset x from main window
   kal_uint16 roi_offset_x;
   /// the ROI window offset y from main window
   kal_uint16 roi_offset_y;
   /// the layers to be updated
   kal_uint32 update_layer;
   /// which layer will be applied by hw trigger or direct couple
   kal_uint32 hw_update_layer;
   /// rotate select for hardware update layer
   kal_uint8 rotate_value;

#if defined(DRV_LCD_ROI_BACKGROUND_COLOR)
   /// background color of ROI
   kal_uint32  roi_background_color;
#endif

#if defined(DRV_LCD_MEMORY_OUTPUT)
   /// enable/disable otuput to memory and LCM simultaneously
   kal_bool    memory_output;
   /// block write out or not
   kal_uint8   block_mode;
   /// output data format to memory, LCD_WMEM_RGB565 or LCD_WMEM_RGB888 for 6228, 6229.
   /// always RGB565 for 6226,6227
   kal_uint8   memory_data_format;
   /// memory block when output to memory
   kal_uint16  memory_block_width;
   /// buffer address of memory output buffer
   kal_uint32  memory_output_buffer_address;
   /// buffer size of memory output buffer
   kal_uint32  memory_output_buffer_size;
#endif //DRV_LCD_MEMORY_OUTPUT

#if (defined(DRV_IDP_6228_SERIES)||defined(DRV_IDP_6238_SERIES))  
   /// LCD_HW_TRIGGER_IBW1 or LCD_HW_TRIGGER_IBW2 that will trigger LCD
   kal_uint8   hw_trigger_src;
#endif //DRV_IDP_6228_SERIES, DRV_IDP_6238_SERIES  
   kal_bool    tv_output;   
#ifdef TV_OUT_SUPPORT
      
   //// enable/disable TV output function   
   kal_uint16  tv_output_width;
   kal_uint16  tv_output_height;
   kal_uint16  tv_output_offset_x;
   kal_uint16  tv_output_offset_y;
   /// image buffer1 for TV source buffer
   kal_uint32  tv_output_frame_buffer1_address;
   /// image buffer2 for TV source buffer
   kal_uint32  tv_output_frame_buffer2_address;
   /// image buffer size for TV source buffer
   kal_uint32  tv_output_frame_buffer_size;
#endif ///  TV_OUT_SUPPORT

}  lcd_frame_update_struct;



typedef struct
{
   kal_uint8   fb_update_mode;      /* frame buffer update mode (SW_TRIGGER, HW_TRIGGER or DIRECT_COUPLE) */

   kal_uint8   block_mode;          /* block write out or not */
   kal_uint16  dest_block_width;    /* x pitch of block write operation */
   kal_uint32  dest_buffer_address; /* the start address of desination buffer for LCD memory write out */
   kal_uint32  dest_buffer_size;
   kal_uint16  roi_offset_x;        /* x offset of interest area from dest buffer */
   kal_uint16  roi_offset_y;        /* y offset of interest area from dest buffer */
   kal_uint16  roi_width;           /* dest image width */
   kal_uint16  roi_height;          /* dest image height */
   kal_uint32  update_layer;
   kal_uint32  hw_update_layer;
   /* for MT6228 and MT6229, MT6230 only */
   kal_uint8   hw_trigger_src;         /* LCD_HW_TRIGGER_IBW1 or LCD_HW_TRIGGER_IBW2 that will trigger LCD */
   kal_uint32  roi_background_color;   /* background color of memory otuput buffer */
   kal_uint8   memory_data_format;     /* output data format */
}  lcd_frame_update_to_mem_struct;



typedef struct
{
   kal_uint8 r_table;
   kal_uint8 g_table;
   kal_uint8 b_table;
} lcd_gamma_table_struct;



/// Start of Variable Declaration

extern LCD_Funcs  *MainLCD;
extern LCD_Funcs  *SubLCD;

/// state control

extern volatile LCD_OPERATION_STATE_ENUM main_lcd_operation_state;
extern lcd_frame_update_struct main_lcd_fb_update_para;
extern volatile LCD_OPERATION_STATE_ENUM sub_lcd_operation_state;
extern lcd_frame_update_struct sub_lcd_fb_update_para;

extern kal_eventgrpid lcd_event_id;

extern volatile kal_uint8 current_update_lcd;

extern kal_uint8 lcd_dc_color_mode;
extern kal_uint8 lcd_rotate_value;
extern kal_uint8 lcd_hard_trigger_flag;
extern kal_uint32 current_lcd_hw_update_layer;
extern kal_bool lcd_window_swap_flag;
extern kal_bool bLCDBufferInINTRAM;
extern kal_uint32 lcd_roi_ctrl_shadow,lcd_roi_size_shadow,lcd_roi_offset_shadow;
extern kal_uint32 lcd_mem_out_address_shadow,lcd_mem_out_address_shadow1, lcd_mem_out_ctrl_shadow;
extern kal_uint32 lcd_frame_buffer_address;

/// HPI interface control
extern kal_uint16 old_lcd_cmd_period_count;
extern kal_uint16 hpi_cmd_period_count;
extern kal_bool hpi_power_on;
extern kal_bool lcd_is_changing_roi;
/*video editor*/
extern volatile LCD_OPERATION_STATE_ENUM temp_main_lcd_operation_state;

extern kal_uint8  lcd_sleep_mode_handler;



#if ((!defined(MT6205B))&&(!defined(MT6208)))
   extern kal_uint8 jpeg_video_play_lcd_id;
   extern volatile kal_uint8 lcd_transfer_complete;
   extern kal_uint16 lcd_cmd_period_count;

   extern kal_uint8 lcd_output_mode;
   extern kal_uint8 main_lcd_hw_trigger_output_mode;
   extern kal_uint8 sub_lcd_hw_trigger_output_mode;
   extern kal_bool bWaitForLCDUpdate;
   extern void (*lcd_prev_run_block_cb) (void);
   #if defined(DRV_IDP_SUPPORT)||defined(DRV_LCD_FW_UPDATE_SUPPORT)
      extern volatile kal_bool lcd_cmd_latch_complete;
      extern kal_uint32 lcd_hw_trigger_roi_offset,lcd_hw_trigger_roi_size,lcd_hw_trigger_roi_ctrl;
      extern kal_uint32 lcd_hw_trigger_layer;
      extern volatile kal_uint8 lcd_hw_trigger_flag;
      extern kal_uint32 lcd_hw_trigger_para[LCD_CMD_QUEUE_LENGTH];
      extern kal_uint8 current_lcd_rotate_value;
      extern kal_uint8 lcd_sleeping_state;
      
       #ifdef TV_OUT_SUPPORT
         extern kal_uint32 lcd_hw_trigger_reg;
         extern kal_uint32 lcd_roi_size_reg;
         extern kal_uint32 lcd_ctrl_reg;
         extern kal_uint32 lcd_cmq_para[LCD_CMD_QUEUE_LENGTH];
         extern kal_uint8 tv_output_buffer_count;
         extern volatile kal_uint8 tv_full_screen;
         extern kal_uint32 tv_output_buffer_base_address1;
         extern kal_uint32 tv_output_buffer_base_address2;
         extern kal_uint32 tv_output_buffer_offset_address1;
         extern kal_uint32 tv_output_buffer_offset_address2;
         extern kal_uint8 tv_output_buffer_rotate;
      #endif
   #endif
#endif



/// Start of Function Declaration



/// For Driver Internal
kal_bool INT_QueryExceptionStatus(void);
void lcd_busy_waiting(void);



/// ISR handler
void lcd_LISR(void);
void lcd_HISR(void);



/// For System Service



/// For Media Task



/// For MMI

#ifdef __LCD_ESD_RECOVERY__
   kal_bool lcd_ESD_check(void);
#endif

#ifdef __SYNC_LCM_SUPPORT__
   extern kal_uint8 sync_lcm_channel_number;
   extern kal_bool sync_lcm_enable_mode;
   extern kal_uint8 sync_lcm_hw_update_layer_rotate_value;
   extern kal_uint8 sync_lcm_delay_flag;
#endif

kal_bool lcd_is_busy(void);
void hpi_power_ctrl(kal_bool bTurnOnClock);
void set_hpi_low_period_count(kal_uint8 low_period);
void lcd_layer_swap_width_height(kal_uint32 swap_layer);
void set_lcd_layer_roate(kal_uint32 rotate_layer,kal_uint8 rotate_value);
void resume_lcd_layer_rotate(void);

kal_bool config_lcd_layer_window(kal_uint8 lcd_layer,lcd_layer_struct *layer_data);
void config_lcd_layer_window_queue(void);
kal_bool config_lcd_roi_window(kal_uint16 roi_offset_x, kal_uint16 roi_offset_y, kal_uint16 roi_column,
                               kal_uint16 roi_row);
void set_lcd_color_palette(kal_uint8 color_palette_select,kal_uint32 *color_palette_addr_ptr,
                           kal_uint8 start_index, kal_uint8 number_of_color);
void config_lcd_layer_offset(kal_uint8 lcd_layer, kal_uint16 layer_offset_x, kal_uint16 layer_offset_y);
void lcd_init(kal_uint8 lcd_id, kal_uint16 background_color);
void lcd_sleep_in(kal_uint8 lcd_id);
void lcd_sleep_out(kal_uint8 lcd_id);
void lcd_partial_on(kal_uint8 lcd_id, kal_uint16 start_line, kal_uint16 end_line);
void lcd_partial_off(kal_uint8 lcd_id);
kal_uint8 lcd_partial_display_align_line(kal_uint8 lcd_id);
void lcd_bright_level(kal_uint8 lcd_id, kal_uint8 bright_level);
void lcd_power_on(kal_uint8 lcd_id, kal_bool on);
void lcd_screen_on(kal_uint8 lcd_id, kal_bool on);
kal_uint8 lcd_get_parameter(kal_uint8 lcd_id,lcd_func_type type);
void lcd_get_size(kal_uint8 lcd_id, kal_uint16 *lcd_width, kal_uint16 *lcd_height);
void lcd_set_bias(kal_uint8 lcd_id, kal_uint8 *bias);
void lcd_set_contrast(kal_uint8 lcd_id, kal_uint8 *contrast);
void lcd_set_linerate(kal_uint8 lcd_id, kal_uint8 *linereate);
void lcd_set_linerate(kal_uint8 lcd_id, kal_uint8 *linereate);
void lcd_set_temp_compensate(kal_uint8 lcd_id, kal_uint8 *compensate);
void lcd_set_rotate(kal_uint8 lcd_id, kal_uint8 rotate_value);
void config_lcd_output(kal_bool lcd_output);
void lcd_fb_update(lcd_frame_update_struct *lcd_para);
void lcd_fb_update_to_memory(lcd_frame_update_to_mem_struct *lcd_para);
void set_lcd_dc_layer_format(kal_uint32 hw_update_layer,kal_bool direct_couple);
void lcd_stop_hw_update(kal_uint8 lcd_id);
void config_lcd_hw_layer(kal_uint32 hw_layer,kal_uint16 layer_offset_x,kal_uint16 layer_offset_y,
                         kal_uint16 layer_width, kal_uint16 layer_height);
kal_uint8 get_lcd_hw_layer_rotate_value(kal_uint32 hw_layer);

kal_uint32 get_lcd_frame_buffer_address(void);
void reset_lcd_if(void);
void assert_lcd_fb_update(kal_uint8 lcd_id, kal_uint16 start_x, kal_uint16 start_y, kal_uint16 end_x,
                          kal_uint16 end_y,kal_uint16 roi_offset_x, kal_uint16 roi_offset_y, kal_uint32 update_layer);
void lcd_dma_slow_down(kal_uint8 level);
void lcd_dma_recovery(void);
void set_lcd_driving_current(kal_uint8 current);
void lcd_wait_command_latch(void);
void lcd_get_event_timer_handle(void);

/*for GAMMA interface*/
void lcd_set_gamma_table(kal_uint8 lcd_id, /*MAIN_LCD, SUB_LCD*/
                         kal_uint8 r_table, /*0~2*/
                         kal_uint8 g_table, /*0~2*/
                         kal_uint8 b_table);/*0~2*/
void lcd_config_gamma_table(kal_uint8 start_index,/*0~255*/
                            kal_uint8 size,       /*0~255*/
                            kal_uint8 *data,
                            kal_uint8 table_id);/*0,1,2*/
void lcd_enable_gamma(kal_uint8 lcd_id, kal_bool enable);

void LCD_config_fw_layer_address(kal_uint32 addr);
void lcd_power_ctrl(kal_bool enable);

/*for mjpeg*/

void lcd_start_jpeg_video_play(lcd_frame_update_struct *lcd_para);
void lcd_stop_jpeg_video_play(kal_uint8 lcd_id);
void lcd_jpeg_video_play(kal_bool display_jpeg, lcd_frame_update_struct *lcd_para);

#endif /* __LCD_IF_H__ */


