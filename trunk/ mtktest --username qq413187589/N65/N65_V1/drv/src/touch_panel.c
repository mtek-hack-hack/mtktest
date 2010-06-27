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
 *    touch_panel.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module is touch panel driver.
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
#include    "drv_features.h"
#include    "drv_comm.h"
#include 	"stack_common.h"
#include    "syscomp_config.h"   /*MOD_BMT*/
#if defined(TOUCH_PANEL_SUPPORT) || defined(HAND_WRITING)
#include 	"stack_msgs.h"
#include 	"app_ltlcom.h"       /* Task message communiction */
#include    "stacklib.h"         /* Basic type for dll, evshed, stacktimer */
#include    "event_shed.h"       /* Event scheduler */
#include    "stack_timer.h"     /*Timer*/
#include    "app_buff_alloc.h"   /*buffer*/
#include    "task_config.h"      /* Task creation */
#include    "stack_ltlcom.h"       /*msg_send_ext_queue.....definitions*/
#include    "reg_base.h"
#include    "gpio_hw.h"
#include    "gpio_sw.h"
#include    "touch_panel_spi.h"
#include    "eint.h"
#include    "intrCtrl.h"
#include 	"touch_panel.h"
#include 	"touch_panel_buff.h"
#include 	"gpt_sw.h"

#if defined(DRV_TP_NO_EXT_EINT)
   extern void ts_drv_init(void);
   extern void ts_mask_int(void);
   extern void ts_unmask_int(void);
   #define TP_MASK_INT     ts_mask_int();
   #define TP_UNMASK_INT   ts_unmask_int();
#else
   #define TP_MASK_INT     EINT_Mask(TP.eint_chan)
   #define TP_UNMASK_INT   EINT_UnMask(TP.eint_chan)
#endif

TouchPanelBufferStruct    touch_panel_data_buffer;
kal_bool    touch_panel_state = touch_down_level; /*touch panel inq level*/


kal_bool send_touch_ilm=KAL_TRUE;
TouchPanelCoordStruct tp_stroke_pre;
static Touch_Panel_Event_enum tp_decode_state=TP_UNKNOWN_EVENT;/*get event state*/

/*GPT timer handle*/
kal_uint8   touch_panel_handle=0;  /*gpt handle*/
kal_uint8   touch_panel_repeat_handle=0;
/*Screen ADC Value*/
kal_uint32 ADC_X_START=230;
kal_uint32 ADC_X_END=3867;
kal_uint32 ADC_Y_START=287;
kal_uint32 ADC_Y_END=3853;
kal_uint32 SCREEN_X_START=0;
kal_uint32 SCREEN_X_END=240;
kal_uint32 SCREEN_Y_START=0;
kal_uint32 SCREEN_Y_END=320;


/*Calibration*/
#define TOUCH_CALIBRATION_POINT_NUM 3
TouchPanelCaliStruct TPCali;  /*Calibration offset and slope*/
static TouchPanelCoordStruct cali_point[TOUCH_CALIBRATION_POINT_NUM];
static TouchPanelCoordStruct cali_point_adc[TOUCH_CALIBRATION_POINT_NUM];
static kal_bool tp_cali_mode=KAL_FALSE;
static kal_uint16 tp_cali_cnt=0;
static kal_bool tp_eint_mask = KAL_FALSE;

extern TouchPanel_customize_function_struct *tp_GetFunc(void);
TouchPanel_customize_function_struct *tp_fun_ptr;


/*************************************************************************
* FUNCTION
*	touch_panel_tuning
*
* DESCRIPTION
*	This function is to calculate slope and offset.
*
* PARAMETERS
*  coord1: coordinate of calibration point 1
*  coord2: coordinate of calibration point 2
*  adc1:   ADC of calibration point 1
*  adc2:   ADC of calibration point 1
*  slope:  slope of calibration
*  offset: offset of calibration
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void touch_panel_tuning(kal_int16 coord1, kal_uint16 adc1,
                        kal_int16 coord2, kal_uint16 adc2,
                        double *slope,     double *offset)
{
   *slope=((double)(coord2-coord1)/((double)(adc2-adc1)));
   *offset=(double)coord1-(*slope)*(double)adc1;      
}
/*************************************************************************
* FUNCTION
*	touch_panel_flush
*
* DESCRIPTION
*	This function is to flush all data in ring buffer.
*
* PARAMETERS
*  None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/   
void touch_panel_flush(void)
{
   IRQMask(IRQ_GPT_CODE);
   /* only mask eint when it's unmasked. */
   if (tp_eint_mask == KAL_FALSE)
   TP_MASK_INT;
   touch_flush_data_buffer();
   /*reset decode state*/
   tp_decode_state=TP_UNKNOWN_EVENT;
   /*recover from buffer full*/
   TP.is_buff_full=KAL_FALSE;
   GPTI_StopItem(touch_panel_handle);
   GPTI_StopItem(touch_panel_repeat_handle);
   TP.skip_unrelease_state=KAL_TRUE;
   
   if (tp_eint_mask == KAL_FALSE)
   TP_UNMASK_INT;
   IRQUnmask(IRQ_GPT_CODE);
}
/*************************************************************************
* FUNCTION
*	touch_panel_flush
*
* DESCRIPTION
*	This function is to reset touch panel driver. 
*
* PARAMETERS
*  skip_unrelease_enable: skip the first unrelease events or not.
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/  
void touch_panel_reset(kal_bool skip_unrelease_enable)
{
   IRQMask(IRQ_GPT_CODE);
   TP_MASK_INT;
   /*stop calibration*/
   touch_panel_stop_cali();
   /*flush ring buffer*/   
   touch_flush_data_buffer();
   /*reset decode state*/
   tp_decode_state=TP_UNKNOWN_EVENT;
   /*configure default pen/move offset*/
   //touch_panel_conf_move_offset(MIN_PEN_MOVE_OFFSET, MAX_STROKE_MOVE_OFFSET, 10);
   /*buff full flag*/
   TP.is_buff_full=KAL_FALSE;
   TP.ext_enable=KAL_FALSE;
   /*skip the first unrelease events or not*/
   TP.skip_unrelease_enable=skip_unrelease_enable;
   if(TP.skip_unrelease_enable)
   {
      TP.skip_unrelease_state=KAL_TRUE;
      #ifdef TOUCH_PANEL_DEBUG
      dbg_printWithTime("reset and skip");
      #endif
   }   
   else
   {
      TP.skip_unrelease_state=KAL_FALSE;   
      #ifdef TOUCH_PANEL_DEBUG
      dbg_printWithTime("reset but not skip");
      #endif
   }   
   /*stop polling*/
   GPTI_StopItem(touch_panel_handle);
   GPTI_StopItem(touch_panel_repeat_handle);
   TP_UNMASK_INT;
   IRQUnmask(IRQ_GPT_CODE);
  
}
/*************************************************************************
* FUNCTION
*	touch_panel_start_cali
*
* DESCRIPTION
*	This function is to do coordinate calibration. 
*
* PARAMETERS
*  point: coordiante of calibration points
*  num:   number of calibration points
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void touch_panel_start_cali(TouchPanelCoordStruct *point, kal_uint16 num)
{
   #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #else
   kal_uint32 i;
   for(i=0;i<num;i++)
   {
      cali_point[i].x=point[i].x;   
      cali_point[i].y=point[i].y;
   }      
   #endif
   tp_cali_mode=KAL_TRUE;
}
/*************************************************************************
* FUNCTION
*	touch_panel_stop_cali
*
* DESCRIPTION
*	This function is to stop coordinate calibration.
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void touch_panel_stop_cali(void)
{
   tp_cali_mode=KAL_FALSE;  
   tp_cali_cnt=0;  
   cali_point[0].x=0;   
   cali_point[0].y=0;
   cali_point[1].x=0;
   cali_point[1].y=0;      
}
/*************************************************************************
* FUNCTION
*	touch_panel_set_cali
*
* DESCRIPTION
*	This function is to set coordinate calibration.
*
* PARAMETERS
*	cali: calibration data
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
/*MMI configures calibration accodring to the value in the NVRAM*/
void touch_panel_set_cali(TouchPanelCaliStruct cali)
{
   
   TPCali.x_slope= cali.x_slope;
   TPCali.x_offset= cali.x_offset;
   TPCali.y_slope= cali.y_slope;
   TPCali.y_offset= cali.y_offset;
}
/*************************************************************************
* FUNCTION
*	touch_panel_read_cali
*
* DESCRIPTION
*	This function is to read coordinate calibration.
*
* PARAMETERS
*	cali: the pointer to read calibraion data
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
/*MMI reads calibration after receiving MSG_ID_TP_CALI_DONE*/
/*and stores it in NVRAM*/
void touch_panel_read_cali(TouchPanelCaliStruct *cali)
{
   cali->x_slope =TPCali.x_slope;  
   cali->x_offset=TPCali.x_offset;
   cali->y_slope =TPCali.y_slope;  
   cali->y_offset=TPCali.y_offset;
}  
   
/*************************************************************************
* FUNCTION
*	touch_panel_cb_registration
*
* DESCRIPTION
*	This function is to register touch event callback function.
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void touch_panel_cb_registration (TP_EVENT_FUNC Callback, void *parameter)
{
   TP.touch_panel_event_cb=Callback;
   TP.cb_para=parameter;
}
/*************************************************************************
* FUNCTION
*	touch_panel_up_hdr
*
* DESCRIPTION
*	This function is to handle up event.
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void touch_panel_up_hdr(void)
{
   /*check if the down point is reasonable*/
   if(TP.wait_next_down==KAL_TRUE)
      return;
      
   /*reset temp coordinate*/
   TP.temp.x=0;
   TP.temp.y=0;
   /*stop polling*/     
   GPTI_StopItem(touch_panel_handle);
   GPTI_StopItem(touch_panel_repeat_handle);
   if(TP.skip_unrelease_state==KAL_FALSE)
   {   
   if(TP.area==NON_HAND_WRITING)
   {    
         tp_data_pop(PEN_UP, TP.pre.x, TP.pre.y);
   }   
   else
   {      
         tp_data_pop(STROKE_UP, TP.pre.x, TP.pre.y);
      }   
   }
   else/*TP.skip_unrelease_state==KAL_TRUE*/
      TP.skip_unrelease_state=KAL_FALSE;   

}   
//begin:ghw111
void touch_panel_down_handle_for_mmi(kal_int16 x, kal_int16 y)
{
/*	ilm_struct* ilm = NULL;
	touch_panel_extern_icon_down_struct* msg = NULL;

	if(y < 219)
		return;
	
	ilm = allocate_ilm(MOD_DRV_HISR);
	msg = (touch_panel_extern_icon_down_struct*)construct_local_para(
                                             sizeof(touch_panel_extern_icon_down_struct), 
                                             TD_CTRL);

	if((x > icon_pos[0].x1) && (x < icon_pos[0].x2))
		msg->icon_index = 0;
	else if((x > icon_pos[1].x1) && (x < icon_pos[1].x2))
		msg->icon_index = 1;
	else if((x > icon_pos[2].x1) && (x < icon_pos[2].x2))
		msg->icon_index = 2;
	else if((x > icon_pos[3].x1) && (x < icon_pos[3].x2))
		msg->icon_index = 3;
	else if((x > icon_pos[4].x1) && (x < icon_pos[4].x2))
		msg->icon_index = 4;
	else
		msg->icon_index = 0xFFFF;
	
	ilm->dest_mod_id = MOD_MMI;
	ilm->src_mod_id = MOD_DRV_HISR;
	ilm->sap_id = 0;
	ilm->msg_id = MSG_ID_TOUCH_PANEL_EXTERN_ICON_DOWN;
	ilm->local_para_ptr = (void*)msg;
	ilm->peer_buff_ptr = NULL;
	msg_send_ext_queue_to_head(ilm);*/
}   
//end:ghw111
/*************************************************************************
* FUNCTION
*	touch_panel_down_hdr
*
* DESCRIPTION
*	This function is to handle down event.
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void touch_panel_down_hdr(void)
{
   kal_int16  x, y;
   kal_uint16 i;
   kal_bool valid=KAL_FALSE;

   TP.skip_unrelease_state=KAL_FALSE;
   touch_panel_read_adc(&x, &y);
   touch_excute_cali(x,y);

//aded by ghw111
#if 0 //#ifdef  TOUCH_PANEL_PRESSURE
   if (KAL_FALSE == tp_fun_ptr->tp_pressure_check())
   {
      TP.wait_next_down=KAL_TRUE;
      return;
   }
#endif
   valid=touch_panel_adc_to_coordinate(&x,&y);/*tranlate*/  
   if(valid==KAL_TRUE)
   {
   TP.pre.x=x; 
   TP.pre.y=y;
      TP.begin.x=x; 
      TP.begin.y=y;
      TP.wait_next_down=KAL_FALSE;
   }
   else
   {
      /*use the previous down coordinate to prevent touch panel controller temp state*/
	touch_panel_down_handle_for_mmi(x, y);//added by ghw111
   	//x=TP.pre.x; 
   	//y=TP.pre.y;
   	TP.wait_next_down=KAL_TRUE;
   	return;
   }	
   TP.temp.x=0;
   TP.temp.y=0;
   if(TP.ext_enable==KAL_FALSE)/*not extend handwriting area*/
   {
      for(i=0;i<TP.hand_num;i++)
      {
         if((x>=TP.handarea[i].min.x)&&(y>=TP.handarea[i].min.y)&&
         (x<=TP.handarea[i].max.x)&&(y<=TP.handarea[i].max.y))
         {
            TP.area=HAND_WRITING;
            /*check if ext_handwriting exists?*/
            if((TP.ext_handarea.min.x!=TP.ext_handarea.max.x)&&
               (TP.ext_handarea.min.y!=TP.ext_handarea.max.y))
            {
               TP.ext_enable=KAL_TRUE;/*use extended handwriting area*/
            }   
            break;   
         }
         else/*non-handwriting*/
         {
            TP.area=NON_HAND_WRITING;                  
         }                  
      }      
   }         
   else/*extend handwriting area*/
   {
      if((x>=TP.ext_handarea.min.x)&&(y>=TP.ext_handarea.min.y)&&
         (x<=TP.ext_handarea.max.x)&&(y<=TP.ext_handarea.max.y))
      {
         TP.area=HAND_WRITING;         
      }
      else/*non-handwriting*/
      {
         TP.area=NON_HAND_WRITING;                  
      }
   }   
   if(TP.area==HAND_WRITING)            
   {            
      tp_data_pop(STROKE_DOWN, x, y);            
      touch_panel_stroke_hdr();
      touch_start_handwriting_longtap();      
   }
   else/*non-handwriting*/
   {            
      tp_data_pop(PEN_DOWN, x, y);            
      touch_panel_event_hdr();
      touch_start_longtap();
   }   
} 
/*************************************************************************
* FUNCTION
*	touch_panel_sendilm
*
* DESCRIPTION
*	This function is to send touch event indication to upper layer.
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/  
/*send touch event indication to upper layer*/
void touch_panel_sendilm(void *para, Touch_Panel_Event_enum state)
{
   ilm_struct *tp_ilm;
   module_type owner=0;
   
   
   if (send_touch_ilm)
   {
   	#ifdef TOUCH_PANEL_DEBUG
   		owner=MOD_SSDBG1;
   	#else
   		owner=MOD_MMI;
   	#endif
   	
      send_touch_ilm = KAL_FALSE;
      DRV_BuildPrimitive(tp_ilm,
                         MOD_TP_TASK,
                         owner,
                         MSG_ID_TP_EVENT_IND,
                         NULL);   
      msg_send_ext_queue(tp_ilm);
   }   
}  
/*************************************************************************
* FUNCTION
*	touch_panel_conf_handwriting
*
* DESCRIPTION
*	This function is to configure handwriting area.
*
* PARAMETERS
*	area: handwriting area
*  n: number of handwriting areas
*  ext_area: extended handwriting area
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/ 
void touch_panel_conf_handwriting(TouchPanelHandAreaStruct *area, kal_uint16 n, 
                              TouchPanelHandAreaStruct  *ext_area)
{
   kal_uint32 i;
      
   /*n handwriting area*/       
   for(i=0;i<n;i++)
   {      
      TP.handarea[i]=*(area+i);
   }   
   /*extended handwriting area*/
   TP.ext_handarea=*ext_area;
   TP.hand_num=n;
}                                     
/*************************************************************************
* FUNCTION
*	touch_panel_reset_handwriting
*
* DESCRIPTION
*	This function is to reset handwriting area as normal.
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/ 
void touch_panel_reset_handwriting(void)                               
{
   kal_uint32 savedMask;
   savedMask = SaveAndSetIRQMask();
   /*MMI will reset handwriting area*/
   TP.ext_enable=KAL_FALSE;
   RestoreIRQMask(savedMask);
}                     
/*************************************************************************
* FUNCTION
*	touch_panle_conf_sample_period
*
* DESCRIPTION
*	This function is to configure sample period in handwriting and non-handwriting area.
*
* PARAMETERS
*	low:  sample period in non-handwriting area
*  high: sample period in handwriting area
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/                       
/*configure sample period in non-handwriting and handwriting area*/
void touch_panle_conf_sample_period(kal_uint32 low, kal_uint32 high)
{
   TP.low_sample_period=low;
   TP.high_sample_period=high;
}   
/*************************************************************************
* FUNCTION
*	touch_panle_conf_timeout_period
*
* DESCRIPTION
*	This function is to configure period of long tap and repeat event.
*
* PARAMETERS
*	long tap: long tap event period
*  repeat:  repeat event period
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/                       
/*configure longtap and repeat period*/
void touch_panle_conf_timeout_period(kal_uint32 longtap, 
                                     kal_uint32 repeat,
                                     kal_uint32 handwriting_longtap)
{
   TP.handwriting_longtap_cnt=handwriting_longtap;
   TP.longtap_cnt=longtap;
   TP.repeat_cnt=repeat;
}
/*************************************************************************
* FUNCTION
*	touch_panel_event_hdr
*
* DESCRIPTION
*	This function is to handle down event in non-handwriting area.
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/ 
/*start timer in non-handwriting area*/
void touch_panel_event_hdr(void)
{
   if(TP.low_sample_period!=0)
   {
      GPTI_StartItem(touch_panel_handle,                  
                     TP.low_sample_period,
                     touch_panel_event_cb,
                     NULL);
   }                     
}  
/*************************************************************************
* FUNCTION
*	touch_start_longtap
*
* DESCRIPTION
*	This function is to long tap timer.
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void touch_start_longtap(void)
{
   if(TP.longtap_cnt!=0)          
   {
      TP.longtap_state=KAL_TRUE;
      GPTI_StartItem(touch_panel_repeat_handle,                  
                     TP.longtap_cnt,
                     touch_panel_longtap_cb,
                     NULL);  
   }   
}   
/*************************************************************************
* FUNCTION
*	touch_start_handwriting_longtap
*
* DESCRIPTION
*	This function is to start long tap timer in handwriting area.
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void touch_start_handwriting_longtap(void)
{
   if(TP.handwriting_longtap_cnt!=0)          
   {
      TP.longtap_state=KAL_TRUE;
      GPTI_StartItem(touch_panel_repeat_handle,                  
                     TP.handwriting_longtap_cnt,/*stroke long tap*/
                     touch_panel_longtap_cb,
                     NULL);  
   }   
}
/*************************************************************************
* FUNCTION
*	touch_panel_stroke_hdr
*
* DESCRIPTION
*	This function is to handle down event in handwriting area.
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void touch_panel_stroke_hdr(void)
{
     if(TP.high_sample_period!=0)
   {
      GPTI_StartItem(touch_panel_handle,                  
                     TP.high_sample_period,
                     touch_panel_stroke_cb,
                     NULL);
   }    
}                              
/*************************************************************************
* FUNCTION
*	touch_panel_get_event
*
* DESCRIPTION
*	This function is to get event from ring buffer.
*
* PARAMETERS
*	data: touch event
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
/*Get touch panel coord. value*/
kal_bool touch_panel_get_event(TouchPanelEventStruct *touch_data)
{
   kal_bool result;
   kal_uint8 hign_data=0, low_data=0;
   kal_int8 diff;
   kal_uint16 avail=0;
   //TouchPanelEventStruct data;
   IRQMask(IRQ_GPT_CODE);
   /* only mask eint when it's unmasked. */
   if (tp_eint_mask == KAL_FALSE)
   TP_MASK_INT;   
   
   if(TP.is_buff_full==KAL_TRUE)
   {
      touch_data->event=PEN_ABORT;
      touch_data->x_adc=0;
      touch_data->y_adc=0;
      if (tp_eint_mask == KAL_FALSE)
         TP_UNMASK_INT;
      IRQUnmask(IRQ_GPT_CODE);
      return KAL_TRUE;
   }
   
   tp_get_buf_avail(avail); 
   if(touch_panel_data_buffer.touch_buffer_rindex != touch_panel_data_buffer.touch_buffer_windex)   	
   {            
      if(tp_decode_state==TP_UNKNOWN_EVENT)            
      {/*complete x and y*/         
         touch_pop_data_from_buffer(touch_data->event);          
         if(touch_data->event!=STROKE_UP)/*stroke end*/
         {
            touch_pop_data_from_buffer(hign_data);/*high*/
            touch_pop_data_from_buffer(low_data);/*low*/
            touch_data->x_adc=(hign_data<<8);     
            touch_data->x_adc|=low_data;     
            touch_pop_data_from_buffer(hign_data);/*high*/
            touch_pop_data_from_buffer(low_data);/*low*/
            touch_data->y_adc=(hign_data<<8);               
            touch_data->y_adc|=low_data;     
         }   
         if(touch_data->event==STROKE_DOWN)
         {
            tp_decode_state=STROKE_MOVE;
            tp_stroke_pre.x=touch_data->x_adc;
            tp_stroke_pre.y=touch_data->y_adc;
         }    
      }
      else if(tp_decode_state==STROKE_MOVE)    
      { 
         touch_pop_data_from_buffer(diff);
         if((kal_uint8)diff==STROKE_UP) 
         {
            touch_data->event=STROKE_UP;
            touch_data->x_adc=tp_stroke_pre.x;//0;
            touch_data->y_adc=tp_stroke_pre.y;//0;
            tp_decode_state=TP_UNKNOWN_EVENT;
            tp_stroke_pre.x=0;
            tp_stroke_pre.y=0;
         }                         
         else if((kal_uint8)diff==STROKE_LONGTAP) 
         {
            //touch_pop_data_from_buffer(diff);
            touch_data->x_adc=tp_stroke_pre.x;//0;
            touch_data->y_adc=tp_stroke_pre.y;//0;
            touch_data->event=STROKE_LONGTAP;
         }   
         else/*delta x, delta y*/
         {     
            /*x*/    
            touch_data->x_adc=(kal_int16)((kal_int16)tp_stroke_pre.x+(kal_int16)diff);
            tp_stroke_pre.x=touch_data->x_adc;
            /*y*/
            touch_pop_data_from_buffer(diff);         
            touch_data->y_adc=(kal_int16)((kal_int16)tp_stroke_pre.y+(kal_int16)diff);;
            tp_stroke_pre.y=touch_data->y_adc;
            touch_data->event=STROKE_MOVE;
         }
      } 
     result = KAL_TRUE;
   }
   else
   {
      send_touch_ilm = KAL_TRUE;
      result = KAL_FALSE;
   }      
   if (tp_eint_mask == KAL_FALSE)
   TP_UNMASK_INT;
   IRQUnmask(IRQ_GPT_CODE);
   return result;      
}   
/*************************************************************************
* FUNCTION
*	touch_panel_peek_event
*
* DESCRIPTION
*	This function is to peek event from ring buffer.
*
* PARAMETERS
*	data: touch event
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool touch_panel_peek_event(TouchPanelEventStruct *touch_data)
{
   kal_bool result;
   //kal_uint8 hign_data=0, low_data=0;
   kal_uint8 peek_data[5];
   //kal_int8 diff;
   //TouchPanelEventStruct data;
   IRQMask(IRQ_GPT_CODE);
   /* only mask eint when it's unmasked. */
   if (tp_eint_mask == KAL_FALSE)
   TP_MASK_INT;   
   if (touch_panel_data_buffer.touch_buffer_rindex != touch_panel_data_buffer.touch_buffer_windex)
   {                  
      if(tp_decode_state==TP_UNKNOWN_EVENT)            
      {/*complete x and y*/         
         touch_peek_data_from_buffer(peek_data,5);   
         touch_data->event=peek_data[0];            
         if(peek_data[0]!=STROKE_UP)/*stroke end*/
         {
            touch_data->x_adc=(peek_data[1]<<8);     
            touch_data->x_adc|=peek_data[2];     
            touch_data->y_adc=(peek_data[3]<<8);               
            touch_data->y_adc|=peek_data[4];                       
         }            
      }
      else if(tp_decode_state==STROKE_MOVE)    
{
         touch_peek_data_from_buffer(peek_data,3);   
         if((kal_uint8)peek_data[0]==STROKE_UP) 
         {
            touch_data->event=STROKE_UP;
            touch_data->x_adc=0;
            touch_data->x_adc=0;            
         }                         
         else/*delta x, delta y*/
         {     
            /*x*/    
            touch_data->x_adc=(kal_int16)((kal_int16)tp_stroke_pre.x+(kal_int16)peek_data[1]);            
            /*y*/            
            touch_data->y_adc=(kal_int16)((kal_int16)tp_stroke_pre.y+(kal_int16)peek_data[2]);;                        
         }
      }       
     result = KAL_TRUE;
   }
   else   
   {
      send_touch_ilm = KAL_TRUE;
      result = KAL_FALSE;
   }
      
   if (tp_eint_mask == KAL_FALSE)
   TP_UNMASK_INT;
   IRQUnmask(IRQ_GPT_CODE);
   return result;      
}

/*************************************************************************
* FUNCTION
*	touch_panel_conf_move_offset
*
* DESCRIPTION
*	This function is to configure pen move offset and stroke move offset.
*
* PARAMETERS
*	pen_offset: pen move offset
*	stroke_offset: stroke move offset
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void touch_panel_conf_move_offset(kal_uint16 pen_offset, kal_uint16 stroke_offset, 
                                  kal_uint16 longtap_pen_offset,
                                  kal_uint16 longtap_stroke_offset)
{
   TP.pen_offset=pen_offset;
   TP.storke_offset=stroke_offset;      
   TP.longtap_pen_offset=longtap_pen_offset;
   TP.longtap_stroke_offset=longtap_stroke_offset;
}  


/*************************************************************************
* FUNCTION
*	touch_panel_exceed_penmove
*
* DESCRIPTION
*	This function is pen move event filter.
*
* PARAMETERS
*	x: x coord.
*	y: y coord.
*
* RETURNS
*	exceed MIN_PEN_MOVE_OFFSET or not
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool touch_panel_exceed_penmove(kal_int16 x, kal_int16 y)
{
   kal_int16 x_diff, y_diff;
   
   if(x>TP.pre.x)   
      x_diff=x-TP.pre.x;
   else
      x_diff=TP.pre.x-x;   
   if(y>TP.pre.y)   
      y_diff=y-TP.pre.y;
   else
      y_diff=TP.pre.y-y;      
          
   if(TP.longtap_state==KAL_FALSE)/*normal*/
   {
   if((x_diff>=TP.pen_offset||y_diff>=TP.pen_offset)
       &&(x_diff<NONHAND_WRITING_MAX_OFFSET)&&(y_diff<NONHAND_WRITING_MAX_OFFSET))   
      return KAL_TRUE;          
   else
      return KAL_FALSE;   
}  
   else/*longtap*/
   {
      if((x_diff>=TP.longtap_pen_offset||y_diff>=TP.longtap_pen_offset)
          &&(x_diff<NONHAND_WRITING_MAX_OFFSET)&&(y_diff<NONHAND_WRITING_MAX_OFFSET))   
         return KAL_TRUE;          
      else
         return KAL_FALSE;   
      
   }         
}  

/*************************************************************************
* FUNCTION
*	touch_panel_longtap_handwriting_filter
*
* DESCRIPTION
*	This function is to check longtap event in handwriting area.
*
* PARAMETERS
*	x: x coord.
*	y: y coord.
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void touch_panel_longtap_handwriting_filter(kal_int16 x, kal_int16 y)
{
   kal_int16 x_diff, y_diff;      
   
   if(x>TP.begin.x)   
      x_diff=x-TP.begin.x;
   else
      x_diff=TP.begin.x-x;    
      
   if(y>TP.begin.y)    
      y_diff=y-TP.begin.y;
   else
      y_diff=TP.begin.y-y;    
      
   if(x_diff>TP.longtap_stroke_offset||y_diff>TP.longtap_stroke_offset)/*handwriting long tap*/   
   {
      GPTI_StopItem(touch_panel_repeat_handle);          
      TP.longtap_state=KAL_FALSE;
   }   
}  
/*************************************************************************
* FUNCTION
*	touch_panel_stroke_filter
*
* DESCRIPTION
*	This function is stroke move event filter.
*
* PARAMETERS
*	x: x coord.
*	y: y coord.
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void touch_panel_stroke_filter(kal_int16 x, kal_int16 y)
{
   kal_int16 x_diff, y_diff;
   //TouchPanelCoordStruct diff;
   if(TP.longtap_state==KAL_TRUE)
      touch_panel_longtap_handwriting_filter(x, y);
      
   if(x>TP.pre.x)   
      x_diff=x-TP.pre.x;
   else
      x_diff=TP.pre.x-x;    
      
   if(y>TP.pre.y)    
      y_diff=y-TP.pre.y;
   else
      y_diff=TP.pre.y-y;     
         
   if((x_diff>TP.storke_offset||y_diff>TP.storke_offset)
       &&(x_diff<HAND_WRITING_MAX_OFFSET)&&(y_diff<HAND_WRITING_MAX_OFFSET))
   {           
      if(TP.temp.x==0&&TP.temp.y==0)      
      {
         tp_data_pop(STROKE_MOVE,(x-TP.pre.x) ,(y-TP.pre.y));
         TP.pre.x=x;
         TP.pre.y=y;
      }   
      else
      {
         /*use the previous point*/
         tp_data_pop(STROKE_MOVE, (TP.temp.x-TP.pre.x), (TP.temp.y-TP.pre.y));
         TP.pre.x=TP.temp.x;
         TP.pre.y=TP.temp.y;
         if(x>TP.pre.x)   
            x_diff=x-TP.pre.x;
         else
            x_diff=TP.pre.x-x;   
      
         if(y>TP.pre.y)   
            y_diff=y-TP.pre.y;
         else         
            y_diff=TP.pre.y-y;          
            
         if((x_diff>TP.storke_offset||y_diff>TP.storke_offset))
         {
            tp_data_pop(STROKE_MOVE, (x-TP.pre.x), (y-TP.pre.y));
            TP.pre.x=x;
            TP.pre.y=y;
            TP.temp.x=0;
            TP.temp.y=0;
         }   
         else
         {
            TP.temp.x=x;
            TP.temp.y=y;
         }                                    
      }                        
   }
   else     
   {
      TP.temp.x=x;
      TP.temp.y=y;  
   }   
} 

/*************************************************************************
* FUNCTION
*	tp_data_pop
*
* DESCRIPTION
*	This function is to "push" data to buffer.
*
* PARAMETERS
*	x: x coord.
*	y: y coord.
*  event: event type
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/  
kal_uint16 tp_roomleft_min=TOUCH_PANEL_BUFFER_SIZE;
void tp_data_pop(Touch_Panel_Event_enum event, kal_int16 x, kal_int16 y)
{
   kal_uint16 roomleft=0;
   
   tp_get_buf_roomleft(roomleft);   
   /*To get minimum roomleft*/
   if(roomleft<tp_roomleft_min)
      tp_roomleft_min=roomleft;
   
   if(TP.is_buff_full==KAL_TRUE)
      return;
   
   if(roomleft<=BASIC_EVENT_UNIT)
   {
       //if(roomleft>=1)
         //touhc_push_data_to_buffer(PEN_ABORT);         
       /*stop collect events until ring buffer is clean*/
       TP.is_buff_full=KAL_TRUE;
       return;
   }    
   
   if(event==STROKE_MOVE) 
   {
      kal_uint8 x_value;
      kal_uint8 y_value;

      /* Cast x, y to kal_uint8. */
      x_value = x;
      y_value = y;
      #ifdef TOUCH_PANEL_DEBUG
      dbg_printWithTime("Move %d,%d\r\n",(kal_int16)x,(kal_int16)y);
      #endif
      /*to avoid STROKE_UP and STROKE_LONGTAP data show in the packet*/
      if(x_value==STROKE_UP)
         x_value = STROKE_UP - 2;
      else if (x_value==STROKE_LONGTAP)
         x_value = STROKE_LONGTAP - 1;
      if(y_value==STROKE_UP)
         y_value = STROKE_UP - 2;   
      else if (y_value==STROKE_LONGTAP)
         y_value = STROKE_LONGTAP - 1;
      touhc_push_data_to_buffer(x_value,event);/*diff_x*/
      touhc_push_data_to_buffer(y_value,event);/*diff_y*/   
   }   
   else if(event==STROKE_LONGTAP) 
   {
      touhc_push_data_to_buffer(event,event);/*diff_x*/
   }   
   else if(event==STROKE_UP) 
   {
      touhc_push_data_to_buffer(event, event);         
   }
   else
   {
      //if(roomleft>=BASIC_EVENT_UNIT)
      {
         touhc_push_data_to_buffer(event, event);   
         touhc_push_data_to_buffer(x>>8, event);   
         touhc_push_data_to_buffer(x, event);
	      touhc_push_data_to_buffer(y>>8, event);   
	      touhc_push_data_to_buffer(y, event);   
	   }
   }   
      
}   
  
/*************************************************************************
* FUNCTION
*	touch_panel_check_cali
*
* DESCRIPTION
*	This function is to check calibration result.
*
* PARAMETERS
*	x: x coord.
*	y: y coord.
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/   
kal_bool touch_panel_check_cali_stage3(void)
{
   kal_int16 x, y, x_diff, y_diff;
   double x_slope, y_slope, x_offset, y_offset; 
      
   touch_panel_tuning(cali_point[0].x, cali_point_adc[0].x, 
                      cali_point[1].x, cali_point_adc[1].x, 
                      &x_slope, &x_offset);
   touch_panel_tuning(cali_point[0].y, cali_point_adc[0].y, 
                      cali_point[1].y, cali_point_adc[1].y, 
                      &y_slope, &y_offset); 
        
   x=(kal_int16)(x_slope*(double)(cali_point_adc[2].x)+x_offset);   
   y=(kal_int16)(y_slope*(double)(cali_point_adc[2].y)+y_offset); 
   
   x_diff=cali_point[2].x-x;
   y_diff=cali_point[2].y-y;
   if(x_diff>TOUCH_PANEL_CALI_CHECK_OFFSET||x_diff<-TOUCH_PANEL_CALI_CHECK_OFFSET||
      y_diff>TOUCH_PANEL_CALI_CHECK_OFFSET||y_diff<-TOUCH_PANEL_CALI_CHECK_OFFSET)
      return KAL_FALSE;
   
   return KAL_TRUE;
}   

kal_bool touch_panel_check_cali_stage1(void)
{
   kal_int32 x_adc_range, x_coord_range, x_adc_high, x_adc_low;   
   kal_int32 y_adc_range, y_coord_range, y_adc_high, y_adc_low;
   
   /*use the relative ADC difference*/
   /*X ADC Diff*/
   if(cali_point_adc[1].x>=cali_point_adc[0].x)
      x_adc_range=cali_point_adc[1].x-cali_point_adc[0].x;   
   else
      x_adc_range=cali_point_adc[0].x-cali_point_adc[1].x;   
   /*Y ADC Diff*/   
   if(cali_point_adc[1].y>=cali_point_adc[0].y)   
      y_adc_range=cali_point_adc[1].y-cali_point_adc[0].y;   
   else
      y_adc_range=cali_point_adc[0].y-cali_point_adc[1].y; 
                 
   /*X Coord Diff*/   
   if(cali_point[1].x>=cali_point[0].x)         
      x_coord_range=cali_point[1].x-cali_point[0].x;   
   else
      x_coord_range=cali_point[0].x-cali_point[1].x;      
   /*Y Coord Diff*/      
   if(cali_point[1].y>=cali_point[0].y)   
      y_coord_range=cali_point[1].y-cali_point[0].y;  
   else   
      y_coord_range=cali_point[0].y-cali_point[1].y;  
               
   x_adc_high=x_coord_range*(ADC_X_END-ADC_X_START)*150/(SCREEN_X_END-SCREEN_X_START)/100; 
   x_adc_low=x_coord_range*(ADC_X_END-ADC_X_START)*50/(SCREEN_X_END-SCREEN_X_START)/100;
   y_adc_high=y_coord_range*(ADC_Y_END-ADC_Y_START)*150/(SCREEN_Y_END-SCREEN_Y_START)/100; 
   y_adc_low=y_coord_range*(ADC_Y_END-ADC_Y_START)*50/(SCREEN_Y_END-SCREEN_Y_START)/100;       
   #ifdef TOUCH_PANEL_DEBUG
   dbg_printWithTime("x adc diff=%d high=%d low=%d\r\n",x_adc_range,x_adc_high,x_adc_low ); 
   dbg_printWithTime("y adc diff=%d high=%d low=%d\r\n",y_adc_range,y_adc_high,y_adc_low );                        
   #endif
   if((x_adc_range<x_adc_low) || (x_adc_range>x_adc_high))
      return KAL_FALSE;
   if((y_adc_range<y_adc_low) || (y_adc_range>y_adc_high))
      return KAL_FALSE;                           
   return KAL_TRUE;      
}
kal_bool touch_panel_check_cali_stage2(void)
{   
   kal_int32 x02_diff, y02_diff, x12_diff, y12_diff;
      
   /*use the point 3 to check if the previous 2 two points are opposite*/      
   if(cali_point_adc[1].x>=cali_point_adc[0].x)/*1>2>0*/
   {
      x12_diff=cali_point_adc[1].x-cali_point_adc[2].x;
      x02_diff=cali_point_adc[2].x-cali_point_adc[0].x;            
   }
   else/*0>2>1*/
   {  
      x12_diff=cali_point_adc[2].x-cali_point_adc[1].x;
      x02_diff=cali_point_adc[0].x-cali_point_adc[2].x;            
   }            
   if(cali_point_adc[1].y>=cali_point_adc[0].y)/*1>2>0*/
   {
      y12_diff=cali_point_adc[1].y-cali_point_adc[2].y;
      y02_diff=cali_point_adc[2].y-cali_point_adc[0].y;            
   }
   else/*0>2>1*/
   {  
      y12_diff=cali_point_adc[2].y-cali_point_adc[1].y;
      y02_diff=cali_point_adc[0].y-cali_point_adc[2].y;            
   }   
      
   if(y12_diff>y02_diff||x12_diff>x02_diff)
      return KAL_FALSE;      
   return KAL_TRUE;
}
kal_bool touch_panel_check_cali(void)
{
   kal_bool result1, result2, result3;
   result1=touch_panel_check_cali_stage1();
   result2=touch_panel_check_cali_stage2();
   result3=touch_panel_check_cali_stage3();
      
   if(result1==KAL_TRUE&&result2==KAL_TRUE&&result3==KAL_TRUE)
      return KAL_TRUE;
   else   
      return KAL_FALSE;
}

/*************************************************************************
* FUNCTION
*	touch_excute_cali
*
* DESCRIPTION
*	This function is to excute calibration.
*
* PARAMETERS
*	x: x coord.
*	y: y coord.
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/   
void touch_excute_cali(kal_int16 x_adc, kal_int16 y_adc)
{
   ilm_struct *tp_ilm;
   tp_cali_done_struct *local_para;
   kal_bool cali_result;
   module_type owner=0;
   if(tp_cali_mode==KAL_FALSE)
      return;
   if(tp_cali_cnt==0)         
   {
      #ifdef TOUCH_PANEL_DEBUG
      dbg_printWithTime("1st Cali %d,%d\r\n",x_adc,y_adc);
      #endif
      //touch_panel_read_adc(&(cali_point_adc[0].x),&(cali_point_adc[0].y));
      tp_cali_cnt++;
      cali_point_adc[0].x=x_adc;
      cali_point_adc[0].y=y_adc;      
   }         
   else if(tp_cali_cnt==1)   
   {
      #ifdef TOUCH_PANEL_DEBUG
      dbg_printWithTime("2nd Cali %d,%d\r\n",x_adc,y_adc);
      #endif
      tp_cali_cnt++;
      cali_point_adc[1].x=x_adc;
      cali_point_adc[1].y=y_adc;          
   }
   else if(tp_cali_cnt==2)
   {      
      cali_point_adc[2].x=x_adc;
      cali_point_adc[2].y=y_adc;          
      tp_cali_mode=KAL_FALSE;
      tp_cali_cnt=0;
      cali_result=touch_panel_check_cali();
      
      if(cali_result==KAL_TRUE) 
      {
      touch_panel_tuning(cali_point[0].x, cali_point_adc[0].x, 
                         cali_point[1].x, cali_point_adc[1].x, 
                         &TPCali.x_slope, &TPCali.x_offset);
      touch_panel_tuning(cali_point[0].y, cali_point_adc[0].y, 
                         cali_point[1].y, cali_point_adc[1].y, 
                         &TPCali.y_slope, &TPCali.y_offset);      
      #ifdef TOUCH_PANEL_DEBUG                  
      dbg_printWithTime("x slope=%f off=%f\r\n",TPCali.x_slope,TPCali.x_offset);                         
      dbg_printWithTime("y slope=%f off=%f\r\n",TPCali.y_slope,TPCali.y_offset);                         
      #endif
      }   
      #ifdef TOUCH_PANEL_DEBUG   
      dbg_printWithTime("cali result=%d\r\n",cali_result);
      #endif
	   local_para = (tp_cali_done_struct *) 
	      construct_local_para(sizeof(tp_cali_done_struct),TD_UL);
	   local_para->result=cali_result;
	   
	   #ifdef TOUCH_PANEL_DEBUG
	   	owner=MOD_SSDBG1;
	   #else
	   	owner=MOD_MMI;
	   #endif
	   
      DRV_BuildPrimitive(tp_ilm,
                         MOD_TP_TASK,
      					    owner,
                         MSG_ID_TP_CALI_DONE,
                         local_para);   
      msg_send_ext_queue(tp_ilm);                                
   }               
}  

/*************************************************************************
* FUNCTION
*	touch_panel_longtap_cb
*
* DESCRIPTION
*	This function is long tap timer callback function.
*
* PARAMETERS
*  Parameter
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/    
void touch_panel_longtap_cb(void *parameter)
{ 
   if(TP.state==DOWN)
   {
      if(TP.area==HAND_WRITING)    
      {
         tp_data_pop(STROKE_LONGTAP, TP.pre.x, TP.pre.y);      
      }
      else
      {
      tp_data_pop(PEN_LONGTAP, TP.pre.x, TP.pre.y);
      #ifdef TOUCH_PANEL_DEBUG                    
      dbg_printWithTime("PEN LONGTAP x=%d y=%d\r\n",TP.pre.x,TP.pre.y);		         
      #endif
      if(TP.repeat_cnt!=0)
      {
         GPTI_StartItem(touch_panel_repeat_handle,                  
                           TP.repeat_cnt,
                           touch_panel_repeat_cb,
                           NULL);         
      }                        
   }                        
}
}

/*************************************************************************
* FUNCTION
*	touch_panel_repeat_cb
*
* DESCRIPTION
*	This function is repeat timer callback function.
*
* PARAMETERS
*  Parameter
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/  
void touch_panel_repeat_cb(void *parameter)
{   
   if(TP.state==DOWN)
   {
      tp_data_pop(PEN_REPEAT, TP.pre.x, TP.pre.y);
      #ifdef TOUCH_PANEL_DEBUG
      dbg_printWithTime("PEN REPEAT x=%d y=%d\r\n",TP.pre.x,TP.pre.y);		         
      #endif
      if(TP.repeat_cnt!=0)
      {
         GPTI_StartItem(touch_panel_repeat_handle,                  
                           TP.repeat_cnt,
                           touch_panel_repeat_cb,
                           NULL);
      }                     
   }                         
   
}

/*************************************************************************
* FUNCTION
*	touch_panel_stroke_cb
*
* DESCRIPTION
*	This function is polling timer callback function in handwriting area.
*
* PARAMETERS
*  Parameter
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/    
void touch_panel_stroke_cb(void *parameter)
{
   kal_int16 x, y;
   kal_bool valid=KAL_FALSE;
   if(TP.state==DOWN)
   {
         touch_panel_read_adc(&x, &y);				      
		   valid=touch_panel_adc_to_coordinate(&x,&y);/*translate*/	
#if 0
	//Huyanwei Del it For Strok
		   if(valid==KAL_TRUE)
		      touch_panel_stroke_filter(x, y);		
#else
		if ((  y >= 0 ) &&  (y <= 319 ) && (x >= 0) && (x <= 239))
			touch_panel_stroke_filter(x, y);		
#endif		   
		/*start polling again*/
		touch_panel_stroke_hdr();
	}
}   

/*************************************************************************
* FUNCTION
*	touch_panel_event_cb
*
* DESCRIPTION
*	This function is polling timer callback function in non-handwriting.
*
* PARAMETERS
*  Parameter
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/    
/*Event timer callback function*/
void touch_panel_event_cb(void *parameter)
{
	kal_int16 x=0, y=0;
	kal_bool valid=KAL_FALSE;

	if(TP.state==DOWN)
	{		
#ifdef TOUCH_PANEL_PRESSURE
//      if (KAL_TRUE == tp_fun_ptr->tp_pressure_check())//modified by ghw111
      {
#endif
		   touch_panel_read_adc(&x, &y);				
		   valid=touch_panel_adc_to_coordinate(&x,&y);/*translate*/	
		   if(touch_panel_exceed_penmove(x, y)&&(valid==KAL_TRUE))
		   {
		      TP.longtap_state=KAL_FALSE;
		      tp_data_pop(PEN_MOVE, x, y);		   
		      #ifdef TOUCH_PANEL_DEBUG
		      dbg_printWithTime("PEN MOVE x=%d y=%d\r\n",x,y);
		      #endif
		      TP.pre.x=x;
		      TP.pre.y=y;    		   
		      GPTI_StopItem(touch_panel_repeat_handle);
		      if(TP.repeat_cnt!=0)/*long tap and reapeat timer*/
		      {
		         GPTI_StartItem(touch_panel_repeat_handle,                  
                              TP.repeat_cnt,
                              touch_panel_repeat_cb,
                              NULL);
            		}                  
		   }
#ifdef TOUCH_PANEL_PRESSURE
      }
#endif
		/*start polling again*/
		touch_panel_event_hdr();
	}
} 
/*************************************************************************
* FUNCTION
*	touch_panel_adc_to_coordinate
*
* DESCRIPTION
*	This function is to translate ADC to coordinate.
*
* PARAMETERS
*  x: x coord.
*  y: y coord.
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/ 
/*adc to coordinate*/
kal_bool touch_panel_adc_to_coordinate(kal_int16 *x, kal_int16 *y)
{
 
   *x=(kal_int16)(TPCali.x_slope*(double)(*x)+TPCali.x_offset);   
   *y=(kal_int16)(TPCali.y_slope*(double)(*y)+TPCali.y_offset);   
   if( (SCREEN_X_START<=*x)&&(*x<=SCREEN_X_END)&&
       (SCREEN_Y_START<=*y)&&(*y<=SCREEN_Y_END))
   {   
      //kal_prompt_trace(MOD_TP_TASK, "coord.: Valid");
      //kal_prompt_trace(MOD_TP_TASK, "coord. (x, y) = (%d, %d)", *x, *y);
      return KAL_TRUE;  
   }
   else   if( (SCREEN_X_START<=*x)&&(*x<=SCREEN_X_END)&&
                (SCREEN_Y_END<=*y))
    {
#if defined(NOKE_DEBUG)
        noke_dbg_printf("touch_panel_adc_to_coordinate x = %d, y = %d\r\n", x, y);
#endif
        return KAL_TRUE;	
    }
   else
   {   
      if(*x<SCREEN_X_START)
         *x=SCREEN_X_START;
      else if (*x>SCREEN_X_END)
         *x=SCREEN_X_END;
         
      if(*y<SCREEN_Y_START)
         *y=SCREEN_Y_START;
      else if (*y>SCREEN_Y_END+24)
         *y=SCREEN_Y_END+24;     


      {
         //kal_prompt_trace(MOD_TP_TASK, "coord.: Invalid");
      	 //return KAL_TRUE;	
        return KAL_FALSE;  
      }
   }         
   
}
/*************************************************************************
* FUNCTION
*	touch_panel_HISR
*
* DESCRIPTION
*	This function is to handle touch event.
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/    
/*touch event HISR, wake up touch panel task*/
void touch_panel_HISR(void)
{   
   kal_set_eg_events(TP.event,1,KAL_OR);
   if (touch_panel_state==touch_down_level)/*low*/
   {
      #ifdef TOUCH_PANEL_DEBUG
      dbg_printWithTime("touch down\r\n");            
      #endif
      TP.state=DOWN;
   }
   else/*high*/
   {      
      #ifdef TOUCH_PANEL_DEBUG
      dbg_printWithTime("touch up\r\n");            
      #endif
      TP.state=UP;
   }
   touch_panel_state = !touch_panel_state;
   EINT_Set_Polarity(TP.eint_chan,touch_panel_state);
   TP_UNMASK_INT;
}

/*************************************************************************
* FUNCTION
*	touch_panel_read_adc
*
* DESCRIPTION
*	This function is to read adc from touch panel module.
*
* PARAMETERS
*  x: x coord.
*  y: y coord.
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void touch_panel_read_adc(kal_int16 *x, kal_int16 *y)
{
   tp_fun_ptr->tp_read_adc(x, y);
}

/*************************************************************************
* FUNCTION
*	touch_panel_enable
*
* DESCRIPTION
*	This function is to enable/disbale touch panel module.
*
* PARAMETERS
*  x: x coord.
*  y: y coord.
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
/*enable/disable touch panel*/
void touch_panel_enable(kal_bool enable)
{  
   /*enable*/
   if(enable==KAL_TRUE)
   {
      /*EINT*/
#if 0//modified by ghw111
      tp_fun_ptr->tp_irq_enable(enable);
#endif
      TP_UNMASK_INT;
      tp_eint_mask = KAL_FALSE;
   }   
   else/*disbale*/
   {
      TP_MASK_INT;
      GPTI_StopItem(touch_panel_handle);
      GPTI_StopItem(touch_panel_repeat_handle);
#if 0//modified by ghw111
      tp_fun_ptr->tp_irq_enable(enable);
#endif
      tp_eint_mask = KAL_TRUE;
   }   
}      
/*************************************************************************
* FUNCTION
*	touch_panel_init
*
* DESCRIPTION
*	This function is to initialize touch panel module.
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/

void touch_custom_init(void)
{   
   TouchPanel_custom_data_struct *tp_data;
   
   tp_fun_ptr=tp_GetFunc();
   
   tp_data = tp_fun_ptr->tp_get_data();   
   ADC_X_START=tp_data->x_adc_start;
   ADC_X_END=tp_data->x_adc_end;
   ADC_Y_START=tp_data->y_adc_start;
   ADC_Y_END=tp_data->y_adc_end;
   SCREEN_X_START=tp_data->x_coord_start;
   SCREEN_X_END=tp_data->x_coord_end;
   SCREEN_Y_START=tp_data->y_coord_start;
   SCREEN_Y_END=tp_data->y_coord_end;
   touch_panel_state=tp_data->eint_down_level;
}   
/*touch panel initialization*/
void touch_panel_init(void)
{
   touch_custom_init();                              
   /*external interrupt*/
#if defined(DRV_TP_NO_EXT_EINT)
   ts_drv_init();
#else
   TP.eint_chan=custom_eint_get_channel(touch_panel_eint_chann);
   EINT_Set_HW_Debounce(TP.eint_chan, 10);
   EINT_Registration(TP.eint_chan,KAL_TRUE,touch_panel_state,touch_panel_HISR, KAL_TRUE);   
#endif
   TP_MASK_INT;
   /*event call back*/
   touch_panel_cb_registration(touch_panel_sendilm, NULL); 
   /*get gpt handle*/
   GPTI_GetHandle(&touch_panel_handle);
   GPTI_GetHandle(&touch_panel_repeat_handle);
   /*configure default pen/move offset*/
   touch_panel_conf_move_offset(MIN_PEN_MOVE_OFFSET, MAX_STROKE_MOVE_OFFSET, 10,10);
   /*buff full flag*/
   TP.is_buff_full=KAL_FALSE;
   /*cali*/   
   touch_panel_tuning(SCREEN_X_START, ADC_X_START, SCREEN_X_END, ADC_X_END, &TPCali.x_slope, &TPCali.x_offset);
   touch_panel_tuning(SCREEN_Y_START, ADC_Y_START, SCREEN_Y_END, ADC_Y_END, &TPCali.y_slope, &TPCali.y_offset);
   //touch_panel_start_cali(coord, 2);
}
/*UNI@banben_20070717 26_06b  解决touch_panel_init 在LCD_FunConfig之前执行，导致触摸屏颠倒*/
//modified by ghw111

void touch_panel_retuning(void)
{
          touch_custom_init();
	  touch_panel_tuning(SCREEN_X_START, ADC_X_START, SCREEN_X_END, ADC_X_END, &TPCali.x_slope, &TPCali.x_offset);
         touch_panel_tuning(SCREEN_Y_START, ADC_Y_START, SCREEN_Y_END, ADC_Y_END, &TPCali.y_slope, &TPCali.y_offset);
         //kal_prompt_trace(MOD_MED,"touch_panel_init:::  S_Y_START=%d, ADC_Y_START=%d,SCREEN_Y_END=%d,ADC_Y_END=%d",SCREEN_Y_START,ADC_Y_START,SCREEN_Y_END,ADC_Y_END);//banben
        // kal_prompt_trace(MOD_MED,"touch_panel_init:::  %f, %f",TPCali.y_slope,TPCali.y_offset);//banben
}
//modified by  ghw111
/*The following are for tests*/
void touch_panel_test(void)
{
   TouchPanelHandAreaStruct handarea[2]={
                                         {{0,0},
                                          {88,110}},   
                                         {{0,0},
                                          {88,110}}
   };

   TouchPanelHandAreaStruct ext_handarea={ {1,1},
                                           /*{176,220}*/{240,320}   };    //yake , update for 240*320 tp ..., 06-12-20 
 	/*MMI should call the following function*/
	touch_panel_enable(KAL_TRUE); 		
	touch_panel_conf_handwriting(handarea,2,&ext_handarea);
	touch_panle_conf_sample_period(10, 1);/*100ms, 20ms*/		
	touch_panle_conf_timeout_period(200,100, 200);/*2s, 1s, 2s*/	   	  
}
void tp_area_change_to_event(void)
   {
   TouchPanelHandAreaStruct handarea[2]={
                                         {{0,0},
                                          {0,0}},   
                                         {{1,1},
                                          {1,1}}
                                         };
   TouchPanelHandAreaStruct ext_handarea={ {1,1},
                                           /*{176,220}*/{240,320}   };  
   touch_panel_conf_handwriting(handarea,2,&ext_handarea);                                           
   touch_panel_reset_handwriting();
			}
void tp_area_change_to_stroke(void)
{
   TouchPanelHandAreaStruct handarea[2]={
                                         {{0,0},
                                          /*{175,219}*/{239,319}},   
                                         {{1,1},
                                          /*{176,219}*/{240,320}}
                                         };
   TouchPanelHandAreaStruct ext_handarea={ {1,1},
                                           /*{176,220}*/{240,320}   };  
   touch_panel_conf_handwriting(handarea,2,&ext_handarea);
   touch_panel_reset(KAL_TRUE);
}

void tp_cali_test(void)   
{
   TouchPanelCoordStruct coord[2]={
                                    {0,0},
                                    /*{176,220}*/{240,320}
                                  };
   touch_panel_start_cali(coord, 2);
}

void tp_cali_end_test(void)
{
   touch_panel_stop_cali();
}

void tp_kp_control(kal_uint8 key)
{
   switch (key)
   {
      case 1:
         tp_area_change_to_event();
      break;
      case 2:
         tp_area_change_to_stroke();    
      break;
      case 3:
         tp_cali_test();
      break;    
      case 4:
         tp_cali_end_test();
      break;
      case 5:
         touch_panel_reset_handwriting();                     
      break;
      default:
      break;
   }
}
#endif
