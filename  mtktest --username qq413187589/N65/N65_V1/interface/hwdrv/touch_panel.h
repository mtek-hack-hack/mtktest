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
 *   This Module defines Touch Panel Interface.
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
#ifndef TOUCH_PANEL_H
#define TOUCH_PANEL_H

#define   TOUCH_PANEL_BUFFER_SIZE 512
#define   TOUCH_PANEL_BUFFER_HIGH_THRES TOUCH_PANEL_BUFFER_SIZE*90/100
#define   TOUCH_PANEL_BUFFER_LOW_THRES TOUCH_PANEL_BUFFER_SIZE*80/100
#define   MIN_PEN_MOVE_OFFSET 5
#define   HAND_WRITING_MAX_OFFSET 50
#define   NONHAND_WRITING_MAX_OFFSET 100
#define   BASIC_EVENT_UNIT   5
#define   MAX_STROKE_MOVE_OFFSET 1
#define   HAND_WRITING_AREA_NUM  3
#define   TOUCH_PANEL_CALI_CHECK_OFFSET  6

#define   touch_down_level   LEVEL_LOW   /*touch down level*/
#define   touch_up_level     LEVEL_HIGH  /*touch up level*/

typedef enum {
      UP,
      DOWN
} Touch_Panel_PenState_enum;

typedef enum {
      HAND_WRITING,
      NON_HAND_WRITING
} Touch_Panel_Area_enum;
typedef enum {
      PEN_DOWN,    /*0*/  
      PEN_UP,      /*1*/
      PEN_MOVE,    /*2*/
      PEN_LONGTAP, /*3*/     
      PEN_REPEAT,  /*4*/ 
      PEN_ABORT,   /*5*/ 
      TP_UNKNOWN_EVENT,/*6*/
      STROKE_MOVE,     /*7*/
      STROKE_DOWN=0xc0, /*0*/        /*1*/
      STROKE_LONGTAP=0x7e,   /*8*/
      STROKE_UP=0x7f/*127*/
} Touch_Panel_Event_enum;
typedef struct
{   
   kal_int16 x;  /*x coordinate*/
   kal_int16 y;  /*y coordinate*/ 
}TouchPanelCoordStruct; 
typedef struct
{  
   TouchPanelCoordStruct min;
   TouchPanelCoordStruct max;
}TouchPanelHandAreaStruct; 

typedef struct
{  
   /*x*/ 
   double x_slope;
   double x_offset; 
   /*y*/   
   double y_slope;
   double y_offset; 
}TouchPanelCaliStruct ; 
typedef void (*TP_EVENT_FUNC)(void *parameter, Touch_Panel_Event_enum state) ; 
typedef struct
{   
   kal_eventgrpid    event;               /*event id*/
   kal_uint8         gpthandle;           /*gpt handle*/
   kal_uint8         eint_chan;
   kal_uint32        longtap_cnt;         /*LongTap cnt*/
   kal_uint32        handwriting_longtap_cnt;         /*LongTap cnt*/
   kal_uint32        repeat_cnt;          /*Repeat cnt*/
   kal_uint32        low_sample_period;
   kal_uint32        high_sample_period;
   TouchPanelHandAreaStruct handarea[HAND_WRITING_AREA_NUM];    /*hand area*/
   TouchPanelHandAreaStruct ext_handarea;     /*extended area*/
   kal_uint16               hand_num;   
   kal_bool                 ext_enable;   /*extended stroke or not*/
   TouchPanelCoordStruct cur;             /*current point coord.*/
   TouchPanelCoordStruct pre;             /*previous point coord.*/
   TouchPanelCoordStruct temp;             /*previous point coord.*/      
   TouchPanelCoordStruct begin;             /*the first down point coord.*/      
   TP_EVENT_FUNC touch_panel_event_cb;
   void     *cb_para;
   Touch_Panel_Area_enum area;            /*(non)handwriting*/  
   Touch_Panel_PenState_enum      state;  /*Down or UP*/  
   kal_bool  skip_unrelease_enable;
   kal_bool  skip_unrelease_state;   
   kal_bool  is_buff_full;
   kal_bool  wait_next_down;      /*inidcate if the down point reasonable*/
   kal_uint16 pen_offset;         /*pen move offset*/
   kal_uint16 longtap_pen_offset;/*longtap pen move offset*/
   kal_uint16 longtap_stroke_offset; /*longtap stroke move offset*/
   kal_uint16 storke_offset;     /*stroke offset*/
   kal_bool   longtap_state;     /*wait longtap timeout or not*/
}TouchPanelDataStruct;

typedef struct
{
   kal_int16     x_adc;
   kal_int16     y_adc;
   Touch_Panel_Event_enum event;
}TouchPanelEventStruct;

typedef struct
{
   kal_uint8      touch_panel_data[TOUCH_PANEL_BUFFER_SIZE];
   kal_uint16      touch_buffer_rindex;
   kal_uint16      touch_buffer_windex;
}TouchPanelBufferStruct;

typedef struct {
   /*ADC*/
	kal_uint32 x_adc_start;
	kal_uint32 x_adc_end;
	kal_uint32 y_adc_start;
	kal_uint32 y_adc_end;
	/*Coord.*/
	kal_uint32 x_coord_start;
	kal_uint32 x_coord_end;
	kal_uint32 y_coord_start;
	kal_uint32 y_coord_end;
	/*EINT*/
	kal_uint8  eint_down_level;	
} TouchPanel_custom_data_struct;

typedef struct {  
   TouchPanel_custom_data_struct * (*tp_get_data)(void);
   void (*tp_read_adc)(kal_int16 *x, kal_int16 *y);
#ifdef TOUCH_PANEL_PRESSURE
   kal_bool (*tp_pressure_check)(void);
#endif
   void (*tp_irq_enable)(kal_bool on);
}TouchPanel_customize_function_struct;  


typedef struct  
{       
	kal_uint8 	ref_count;
	kal_uint16 	msg_len;			/* LOCAL_PARA_HDR */	
	kal_bool 	result;
}tp_cali_done_struct; 
/********************Function Declaration********************/
/********************For upper layer*************************/
void touch_panel_enable(kal_bool enable);/*enable/disable touch panel*/
kal_bool touch_panel_get_event(TouchPanelEventStruct *touch_data);/*get touch event*/
void touch_panle_conf_timeout_period(kal_uint32 longtap, 
                                     kal_uint32 repeat,
                                     kal_uint32 handwriting_longtap);
void touch_panle_conf_sample_period(kal_uint32 low, kal_uint32 high);
void touch_panel_flush(void);/*flsuh data in ring buffer*/
void touch_panel_start_cali(TouchPanelCoordStruct *point, kal_uint16 num);
void touch_panel_stop_cali(void);
void touch_panel_read_cali(TouchPanelCaliStruct *cali);
void touch_panel_set_cali(TouchPanelCaliStruct cali);
void touch_panel_reset(kal_bool skip_unrelease_enable);
void touch_panel_reset_handwriting(void);
void touch_panel_conf_move_offset(kal_uint16 pen_offset, kal_uint16 stroke_offset, 
                                  kal_uint16 longtap_pen_offset,
                                  kal_uint16 longtap_stroke_offset);
void touch_panel_conf_handwriting(TouchPanelHandAreaStruct *area, kal_uint16 n, 
                              TouchPanelHandAreaStruct  *ext_area);
void touch_panel_cb_registration (TP_EVENT_FUNC function, void *parameter);
/********************For touch panel driver only*************/
void touch_panel_read_adc(kal_int16 *x, kal_int16 *y);
kal_bool touch_panel_adc_to_coordinate(kal_int16 *x, kal_int16 *y);/*tranlate*/
void touch_panel_event_cb(void *parameter);
void touch_panel_repeat_cb(void *parameter);
void touch_panel_longtap_cb(void *parameter);
void touch_panel_stroke_cb(void *parameter);
void touch_panel_up_hdr(void);
void touch_panel_down_hdr(void);
void touch_panel_event_hdr(void);
void touch_start_longtap(void);
void touch_panel_stroke_hdr(void);
void touch_excute_cali(kal_int16 x_adc, kal_int16 y_adc);
void touch_panel_sendilm(void *para, Touch_Panel_Event_enum state);
void tp_data_pop(Touch_Panel_Event_enum event, kal_int16 x, kal_int16 y);
void touch_panel_init(void);
void touch_start_handwriting_longtap(void);
/*variable*/
extern TouchPanelDataStruct TP;
extern Touch_Panel_Event_enum touch_panel_track_stauts; /*pen/stroke status*/
extern TouchPanelBufferStruct    touch_panel_data_buffer;
extern TouchPanelCoordStruct pre_coord;
extern TouchPanelCoordStruct tp_stroke_pre;
#endif