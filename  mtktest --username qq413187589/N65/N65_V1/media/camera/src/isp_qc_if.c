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
 *   isp_qc_if.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   These are interface with FT for COQC/IQC
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_release.h"
#include "drv_features.h"

#if (defined(ISP_SUPPORT)&&(!defined(DRV_ISP_6225_SERIES))&&(!defined(DRV_ISP_6219_SERIES)))
#include "drv_comm.h"
#include "stdio.h"
#include "string.h"
#include "IntrCtrl.h"
#include "visual_comm.h"
#include "img_comm.h"
#include "visualhisr.h"
#include "isp_if.h"
#include "image_sensor.h"
#include "ae_awb.h"
#include "resizer.h"
#include "camera_para.h"
#include "isp_cct_if.h"
#include "med_api.h"
#include "isp_device_if.h"
#include "isp_qc_if.h"

/*************************************************
 * Defect Table Interface 	
 **************************************************/
extern kal_eventgrpid camera_isp_event_id;
extern kal_bool	switch_cap_en;
/* Input Data */
defectpixel_para_struct defectpixel_data;
defectpixel_para_struct defectpixel_cap_data;
defectpixel_para_struct defectpixel_pv_data;
kal_uint8   defect_current_mode;
kal_uint8	defect_operation_state = DEFECT_INIT_STATE;
kal_uint8	defect_operation_pv_state = DEFECT_INIT_STATE;
kal_uint16	defect_curr_search_num=0, defect_area1_search_num=0; 
kal_uint16	defect_curr_cap_search_num=0, defect_area1_cap_search_num=0; 
kal_uint16	defect_curr_pv_search_num=0, defect_area1_pv_search_num=0; 
kal_uint16	defect_curr_min_diff=0xFF, defect_area1_min_diff=0xFF;
kal_uint16	defect_curr_cap_min_diff=0xFF, defect_area1_cap_min_diff=0xFF;
kal_uint16	defect_curr_pv_min_diff=0xFF, defect_area1_pv_min_diff=0xFF;
kal_uint32  cap_search1_idx, pv_search1_idx;
#define     DEFECT_WHITEPIXEL_OFFSET (32)    // to force white pixel select

/* Result Data */
defectpixel_result_struct defectpixel_result; 
defectpixel_result_struct defectpixel_pv_result; 
defectpixel_pixel_struct search_pixel[DEFECT_MAX_SEARCH_NUM];
defectpixel_pixel_struct search_cap_pixel[DEFECT_MAX_SEARCH_NUM];
defectpixel_pixel_struct search_pv_pixel[DEFECT_MAX_SEARCH_NUM];
kal_uint32	diffValue[MAX_DEFECT_NUM], diffArea1Value[MAX_DEFECT_NUM];
kal_uint32	diffValue_pv[MAX_DEFECT_NUM], diffArea1Value_pv[MAX_DEFECT_NUM];

/* Parameters */
kal_uint16	block_pixel_count;				
kal_uint16	grap_width, grap_height;	
kal_uint16	area1_min_x=0, area1_max_x=0xFFFF, area1_min_y=0, area1_max_y=0xFFFF;		
kal_uint16 area_id; 

/* AF Lens Calibration */
kal_uint8 camera_af_loop_state_flag=0;
//0:not start,1:check&set,2:AF lut(HISR),3:AF lut algorithm,4:AF detail search,5:AF detail algorithm,6:final check,7:end

void clear_defect_para(kal_uint8	defect_mode)
{
	register kal_int32 i = MAX_DEFECT_NUM;
	register kal_uint32 *p_diffValue = diffValue;
	register kal_uint32 *p_diffArea1Value = diffArea1Value;		
    register kal_uint32 *p_diffValue_pv = diffValue_pv;
    register kal_uint32 *p_diffArea1Value_pv = diffArea1Value_pv;
		
   	if((defect_mode==DEFECT_MODE_CAPTURE)||(defect_mode==DEFECT_MODE_BOTH))
   	{
    	defect_curr_cap_search_num = defect_area1_cap_search_num = 0;   
    	defect_curr_cap_min_diff = defect_area1_cap_min_diff=0xFF;    	
    	cap_search1_idx = 0;
    	while (--i >=0)	
    	{
    		*p_diffValue++ = 0;
    		*p_diffArea1Value++ = 0;
    	}		
    	i = DEFECT_MAX_SEARCH_NUM;
        	while (--i>=0)
    	{
    	    search_pixel[i].pixel_diff = 0;
        	search_cap_pixel[i].pixel_diff = 0;    	
        }	    	
    	
    }
	if((defect_mode==DEFECT_MODE_PREVIEW)||(defect_mode==DEFECT_MODE_BOTH))		
    {
    	defect_curr_pv_search_num = defect_area1_pv_search_num = 0;    	
    	defect_curr_pv_min_diff = defect_area1_pv_min_diff=0xFF;        
        pv_search1_idx = 0;    	
    	while (--i >=0)	
    	{
    		*p_diffValue_pv++ = 0;
    		*p_diffArea1Value_pv++ = 0;		
    	}		
    	i = DEFECT_MAX_SEARCH_NUM;
    	while (--i>=0)
    	{
    	    search_pixel[i].pixel_diff = 0;
        	search_pv_pixel[i].pixel_diff = 0;
        }	    	        
    }
	if(defect_mode==DEFECT_MODE_BOTH)		
    {
    	defect_curr_search_num = defect_area1_search_num = 0;    	           	            
    	defect_curr_min_diff = defect_area1_min_diff=0xFF;
    }	
}

void camera_defect_raw_capture( kal_uint16 grab_start_x,kal_uint16 grab_start_y,
										kal_uint16 grab_width,kal_uint16 grab_height,
										kal_uint32 isp_debug_buffer)
{										
	kal_uint32 event_group;
	kal_uint16 isp_grab_start_x,isp_grab_start_y;
	kal_uint32 i;
	
	if (isp_operation_state!=ISP_STANDBY_STATE)
		ASSERT(0);

	ENABLE_CMOS_SESNOR;
	if(switch_cap_en == KAL_TRUE)
	{
		exposure_window.image_target_width=grab_width;
		exposure_window.image_target_height=grab_height;
		exposure_window.digital_zoom_factor=10;		
		
		sensor_config_data.enable_shutter_tansfer=KAL_FALSE;
		sensor_config_data.meta_mode = CAPTURE_MODE_META_EXT;	// for meta mode capture
		image_sensor_func->sensor_capture_setting(&exposure_window,&sensor_config_data);
	}
	isp_grab_start_x=exposure_window.grab_start_x;
	isp_grab_start_y=exposure_window.grab_start_y;

	/* Bayer output */
	SET_TG_GRAB_PIXEL(isp_grab_start_x+grab_start_x,grab_width-GRAB_INTERPO_WIDTH_PIXEL);
	SET_TG_GRAB_LINE(isp_grab_start_y+grab_start_y,grab_height-GRAB_INTERPO_HEIGHT_PIXEL);	
#if (defined(DRV_ISP_6219_SERIES))
	SET_SUB_SAMPLE_MODE(0);
	SET_GMC_RAW_RGB_MODE;	
	REG_ISP_DEBUG_WRITE_OUT_ADDR=(kal_uint32) isp_debug_buffer;	
#elif (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))		
	ENABLE_REZ_DISCONN;
	DISABLE_REZ_LPF;
	SET_OUTPUT_PATH_TYPE(0);	/* 0:bayer, 1:ISP output, 2:RGB888, 3:RGB565 */
	REG_ISP_OUTPUT_ADDR=(kal_uint32)isp_debug_buffer;
#endif

	// skip unstable frames 
	ENABLE_CAMERA_IDLE_INT;
	SET_CAMERA_CAPTURE_MODE;
	
	if(switch_cap_en == KAL_TRUE)
	{	
		SET_CAMERA_FRAME_RATE(0);	
		for(i=0;i<camera_oper_data.capture_delay_frame;i++)
		{
			DISABLE_VIEW_FINDER_MODE;
			kal_set_eg_events(camera_isp_event_id,0,KAL_AND);
			ENABLE_VIEW_FINDER_MODE;
		
			kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_IDLE_EVENT,KAL_OR_CONSUME,
		                          &event_group,KAL_SUSPEND);
		}
	}	
	DISABLE_VIEW_FINDER_MODE;
	kal_set_eg_events(camera_isp_event_id,0,KAL_AND);

	// start capture 
#if (defined(DRV_ISP_6219_SERIES))	
	ENABLE_GMC_DEBUG_OUTPUT;
#else
	ENABLE_CAMERA_OUTPUT_TO_MEM;
#endif	
	ENABLE_VIEW_FINDER_MODE;
	
	isp_operation_state=ISP_CAPTURE_JPEG_STATE;
	kal_retrieve_eg_events(camera_isp_event_id,CAMERA_ISP_IDLE_EVENT,KAL_OR_CONSUME,
                          &event_group,KAL_SUSPEND);
                          
	//DISABLE_CMOS_SESNOR;
	DISABLE_VIEW_FINDER_MODE;
	isp_operation_state=ISP_STANDBY_STATE;	
	switch_cap_en = KAL_FALSE;			
}

kal_int32 camera_defect_add_cap_pixel(kal_uint32 pixel_diff, kal_uint32 pos_x, kal_uint32 pos_y)
{
	if(defect_curr_cap_search_num>=(defectpixel_data.max_search_num))
		return ERR_OVER_MAX_SEARCH_NUM;
	else
	{		
		if(defect_curr_cap_min_diff>=pixel_diff)
		{
			if(defectpixel_data.search_mode_select == DEFECT_AREA_AVG)
			{														/* DEFECT_AREA_AVG */
				if(defect_curr_cap_search_num>=(defectpixel_data.max_defect_num))
					return 1;				
			}					
			else		
			{														
				if(area_id!=DEFECT_AREA_1)										
				{													/* DEFECT_AREA_CENTER_PRI & Area2 */	
					if(defect_curr_cap_search_num>=(defectpixel_data.max_defect_num))				
						return 1;
				}
				else if(defect_area1_cap_min_diff>=pixel_diff)		
				{													/* DEFECT_AREA_CENTER_PRI & Area1 */
					if(defect_area1_cap_search_num>=(defectpixel_data.max_defect_num))
						return 1;																		
				}
			}
		}			
		search_cap_pixel[defect_curr_cap_search_num].pixel_diff = (kal_uint8)pixel_diff;
		search_cap_pixel[defect_curr_cap_search_num].area_id = (kal_uint8)area_id;
		search_cap_pixel[defect_curr_cap_search_num].pos_x = (kal_uint16)pos_x;		
		search_cap_pixel[defect_curr_cap_search_num].pos_y = (kal_uint16)pos_y;	
        if(defect_operation_state == DEFECT_START_STATE)
			cap_search1_idx++;		
		defect_curr_cap_search_num++;		
		diffValue[pixel_diff]++;					
		if(area_id==DEFECT_AREA_1)
		{
			if(defect_area1_cap_min_diff>pixel_diff)			
				defect_area1_cap_min_diff = pixel_diff;			
			defect_area1_cap_search_num++;
			diffArea1Value[pixel_diff]++;						
		}
		if(defect_curr_cap_min_diff>pixel_diff)
			defect_curr_cap_min_diff = pixel_diff;			
	}
	return 1;		
}

kal_int32 camera_defect_add_pv_pixel(kal_uint32 pixel_diff, kal_uint32 pos_x, kal_uint32 pos_y)
{        
	if(defect_curr_pv_search_num>=(defectpixel_data.max_search_num))
		return ERR_OVER_MAX_SEARCH_NUM;
	else
	{		
		if(defect_curr_pv_min_diff>=pixel_diff)
		{			
			if(defectpixel_data.search_mode_select == DEFECT_AREA_AVG)
			{														/* DEFECT_AREA_AVG */
				if(defect_curr_pv_search_num>=(defectpixel_data.max_defect_num))
					return 1;				
    		}
    		else
    		{
				if(area_id!=DEFECT_AREA_1)										
				{													/* DEFECT_AREA_CENTER_PRI & Area2 */	
					if(defect_curr_pv_search_num>=(defectpixel_data.max_defect_num))				
						return 1;
        		}	
				else if(defect_area1_pv_min_diff>=pixel_diff)		
				{													/* DEFECT_AREA_CENTER_PRI & Area1 */
					if(defect_area1_pv_search_num>=(defectpixel_data.max_defect_num))
						return 1;																		
				}
			}
		}			

		search_pv_pixel[defect_curr_pv_search_num].pixel_diff = (kal_uint8)pixel_diff;
		search_pv_pixel[defect_curr_pv_search_num].area_id = (kal_uint8)area_id;
		search_pv_pixel[defect_curr_pv_search_num].pos_x = (kal_uint16)pos_x;		
		search_pv_pixel[defect_curr_pv_search_num].pos_y = (kal_uint16)pos_y;	
        if(defect_operation_pv_state == DEFECT_START_STATE)
			pv_search1_idx++;
		defect_curr_pv_search_num++;		
		diffValue_pv[pixel_diff]++;					
		if(area_id==DEFECT_AREA_1)
		{
			if(defect_area1_pv_min_diff>pixel_diff)			
				defect_area1_pv_min_diff = pixel_diff;			
			defect_area1_pv_search_num++;
			diffArea1Value_pv[pixel_diff]++;						
		}
		if(defect_curr_pv_min_diff>pixel_diff)
			defect_curr_pv_min_diff = pixel_diff;			
	}
	return 1;		
}

kal_int32 camera_defect_add_pixel( 	kal_uint32 pixel_diff, kal_uint32 pos_x, kal_uint32 pos_y)
{
    if(defect_current_mode == DEFECT_MODE_CAPTURE)
        return camera_defect_add_cap_pixel(pixel_diff, pos_x, pos_y);
    else    // preview mode
        return camera_defect_add_pv_pixel(pixel_diff, pos_x, pos_y);    
}

void camera_defect_merge_cap_pixellist(kal_uint16 defect_type_select, kal_uint16 search_mode)
{
	kal_uint32	i;		
	kal_uint32  pixel_struct_size = sizeof(defectpixel_pixel_struct);
	if((defect_type_select==DEFECT_TYPE_BLACK_PIXEL_ONLY)||(defect_type_select==DEFECT_TYPE_WHITE_PIXEL_ONLY))
	{
		memcpy(search_pixel, search_cap_pixel, DEFECT_MAX_SEARCH_NUM*pixel_struct_size);
	}
	else
	{
		kal_uint32  b_idx=0, w_idx=cap_search1_idx;
		kal_uint32  b_idx_max=b_idx, w_idx_max=w_idx;
		if(cap_search1_idx>0)
		    b_idx_max=cap_search1_idx-1;
        if((defect_curr_cap_search_num>0) && (defect_curr_cap_search_num>cap_search1_idx))
            w_idx_max=defect_curr_cap_search_num-1;		    
		for(i=0;i<defect_curr_cap_search_num;i++)
			{
			if( (b_idx>b_idx_max)||((w_idx<=w_idx_max)&&
			    ((search_cap_pixel[w_idx].pos_y<search_cap_pixel[b_idx].pos_y)||
			    ((search_cap_pixel[w_idx].pos_y==search_cap_pixel[b_idx].pos_y)&&
			     (search_cap_pixel[w_idx].pos_x<search_cap_pixel[b_idx].pos_x)))) )
			{   // add w_idx
			    if(search_mode!=DEFECT_AREA_CENTER_PRI) // for debug info
			        search_cap_pixel[w_idx].area_id = 0;    
				memcpy(&search_pixel[i], &search_cap_pixel[w_idx], pixel_struct_size);								
				    w_idx++;
			}
            else if( (w_idx>w_idx_max)||((b_idx<=b_idx_max)&&
                ((search_cap_pixel[w_idx].pos_y>search_cap_pixel[b_idx].pos_y)||
				((search_cap_pixel[w_idx].pos_y==search_cap_pixel[b_idx].pos_y)&&
    			(search_cap_pixel[w_idx].pos_x>search_cap_pixel[b_idx].pos_x)))) )
			{   // add b_idx
			    if(search_mode!=DEFECT_AREA_CENTER_PRI) // for debug info			    
			        search_cap_pixel[b_idx].area_id = 8;
				memcpy(&search_pixel[i], &search_cap_pixel[b_idx], pixel_struct_size);								
				    b_idx++;
			}		    
            else if((b_idx<=b_idx_max)&&(w_idx<=w_idx_max)&&
                    ((search_cap_pixel[w_idx].pos_y==search_cap_pixel[b_idx].pos_y)&&
                    (search_cap_pixel[w_idx].pos_x==search_cap_pixel[b_idx].pos_x)))
            {
    	        if(search_cap_pixel[w_idx].pixel_diff>=search_cap_pixel[b_idx].pixel_diff)
                {   // remove black_pixel
			        if(search_mode!=DEFECT_AREA_CENTER_PRI) // for debug info    	            
			            search_cap_pixel[w_idx].area_id = 0;
    				memcpy(&search_pixel[i], &search_cap_pixel[w_idx], pixel_struct_size);            	            
	                diffValue[search_cap_pixel[b_idx].pixel_diff]--;
	                if(search_cap_pixel[b_idx].area_id==DEFECT_AREA_1)
      		        {
               			defect_area1_cap_search_num--;
               			diffArea1Value[search_cap_pixel[b_idx].pixel_diff]--;
               	    }
        	    }            	        
                else
        	    {   // remove white_pixel
			        if(search_mode!=DEFECT_AREA_CENTER_PRI) // for debug info    	                	            
			            search_cap_pixel[b_idx].area_id = 8;        
        			memcpy(&search_pixel[i], &search_cap_pixel[b_idx], pixel_struct_size);
	                diffValue[search_cap_pixel[w_idx].pixel_diff]--;
	                if(search_cap_pixel[w_idx].area_id==DEFECT_AREA_1)
	                {
               			defect_area1_cap_search_num--;
               			diffArea1Value[search_cap_pixel[w_idx].pixel_diff]--;
            	    }
    	        }            	                    	        
				defect_curr_cap_search_num--;        	    
				    w_idx++;    
				    b_idx++;
			}
   	    }
    }
}

void camera_defect_merge_pv_pixellist(kal_uint16 defect_type_select, kal_uint16 search_mode)
{
	kal_uint32	i;		
	kal_uint32  pixel_struct_size = sizeof(defectpixel_pixel_struct);	
	if((defect_type_select==DEFECT_TYPE_BLACK_PIXEL_ONLY)||(defect_type_select==DEFECT_TYPE_WHITE_PIXEL_ONLY))
		memcpy(search_pixel, search_pv_pixel, DEFECT_MAX_SEARCH_NUM*pixel_struct_size);
    else
    {
		kal_uint32 b_idx=0, w_idx=pv_search1_idx;
		kal_uint32 b_idx_max=b_idx, w_idx_max=w_idx;		
		if(pv_search1_idx>0)
		    b_idx_max=pv_search1_idx-1;
        if((defect_curr_pv_search_num>0) && (defect_curr_pv_search_num>pv_search1_idx))
            w_idx_max=defect_curr_pv_search_num-1;		    		
		for(i=0;i<defect_curr_pv_search_num;i++)
		{		
			if( (b_idx>b_idx_max)||((w_idx<=w_idx_max)&&
			    ((search_pv_pixel[w_idx].pos_y<search_pv_pixel[b_idx].pos_y)||
			    ((search_pv_pixel[w_idx].pos_y==search_pv_pixel[b_idx].pos_y)&&
			     (search_pv_pixel[w_idx].pos_x<search_pv_pixel[b_idx].pos_x)))) )
			{   // add w_idx
		        if(search_mode!=DEFECT_AREA_CENTER_PRI) // for debug info
    		        search_pv_pixel[w_idx].area_id = 0;	                	            			    
				memcpy(&search_pixel[i], &search_pv_pixel[w_idx], pixel_struct_size);								
				    w_idx++;    
        	}            	        
            else if( (w_idx>w_idx_max)||((b_idx<=b_idx_max)&&
                    ((search_pv_pixel[w_idx].pos_y>search_pv_pixel[b_idx].pos_y)||
				     ((search_pv_pixel[w_idx].pos_y==search_pv_pixel[b_idx].pos_y)&&
    			(search_pv_pixel[w_idx].pos_x>search_pv_pixel[b_idx].pos_x)))) )
			{   // add b_idx
		        if(search_mode!=DEFECT_AREA_CENTER_PRI) // for debug info			    
		            search_pv_pixel[b_idx].area_id = 8;
				memcpy(&search_pixel[i], &search_pv_pixel[b_idx], pixel_struct_size);								
				    b_idx++;
            }
            else if((b_idx<=b_idx_max)&&(w_idx<=w_idx_max)&&
                    ((search_pv_pixel[w_idx].pos_y==search_pv_pixel[b_idx].pos_y)&&
                    (search_pv_pixel[w_idx].pos_x==search_pv_pixel[b_idx].pos_x)))
            {			
    	        if(search_pv_pixel[w_idx].pixel_diff>=search_pv_pixel[b_idx].pixel_diff)
    	        {   // remove black_pixel
    		        if(search_mode!=DEFECT_AREA_CENTER_PRI) // for debug info
    		            search_pv_pixel[w_idx].area_id = 0;
    				memcpy(&search_pixel[i], &search_pv_pixel[w_idx], pixel_struct_size);            	            
	                diffValue_pv[search_pv_pixel[b_idx].pixel_diff]--;
	                if(search_pv_pixel[b_idx].area_id==DEFECT_AREA_1)
			        {
               			defect_area1_pv_search_num--;
               			diffArea1Value_pv[search_pv_pixel[b_idx].pixel_diff]--;
               	    }
    			}
    			else
    	        {   // remove white_pixel
    		        if(search_mode!=DEFECT_AREA_CENTER_PRI) // for debug info    	            
		                search_pv_pixel[b_idx].area_id = 8;
        			memcpy(&search_pixel[i], &search_pv_pixel[b_idx], pixel_struct_size);
	                diffValue_pv[search_pv_pixel[w_idx].pixel_diff]--;
	                if(search_pv_pixel[w_idx].area_id==DEFECT_AREA_1)
			        {
               			defect_area1_pv_search_num--;
               			diffArea1Value_pv[search_pv_pixel[w_idx].pixel_diff]--;
    		        }
    		    }
				defect_curr_pv_search_num--;        	    
				    w_idx++;    				
				    b_idx++;
			}
		}		
	}
}

void camera_defect_sort_pixel_by_center_pri(kal_uint8	defect_mode, kal_uint16 search_mode, kal_uint16 defect_type_select)
{
	kal_uint16	defect_min_diff=255, defect_idx=0;
	kal_uint32	i, defect_num, area2_num;	
    register kal_uint32 *p_diffValue;
    register kal_uint32 *p_diffArea1Value;
	kal_uint32  pixel_struct_size = sizeof(defectpixel_pixel_struct);	    
	if( defect_mode==DEFECT_MODE_CAPTURE ) 
    {
        p_diffValue = &diffValue[0];
        p_diffArea1Value = &diffArea1Value[0];
    }
    else
	{
        p_diffValue = &diffValue_pv[0];
        p_diffArea1Value = &diffArea1Value_pv[0];
    }
	if(defect_area1_search_num<(defectpixel_data.max_defect_num))		
	{	/* Add all Area1 Pixels and sort Area2 Pixels */
		defect_num = defect_curr_search_num - defect_area1_search_num;	/*Area2 num*/
		area2_num = defectpixel_data.max_defect_num-defect_area1_search_num;
		for(i=defect_curr_min_diff;i<255;i++)
		{   /* select Area2 Pixels */
		    if(defect_num > (*(p_diffValue+i)-*(p_diffArea1Value+i)))
			{
    			defect_num -= (*(p_diffValue+i)-*(p_diffArea1Value+i));
    			if(defect_num<=area2_num)
    				{
				    defect_num = area2_num - defect_num;
					break;
			}			
        }
        else
        {
            defect_num = 0;
			break;
    	}			
	}			
		defect_min_diff = i;	/* min defect diff for Area2 */
		/* Search diff value inside max defect num */
		for(i=0;i<defect_area1_search_num;i++)				
		{
			if( ((search_pixel[i].pixel_diff>defect_min_diff)&&(search_pixel[i].area_id==DEFECT_AREA_2)) ||
			    ((defect_num>0)&&(search_pixel[i].pixel_diff==defect_min_diff)&&(search_pixel[i].area_id==DEFECT_AREA_2)) ||
				(search_pixel[i].area_id==DEFECT_AREA_1))
			{
				if( defect_mode==DEFECT_MODE_CAPTURE ) 
				memcpy(&(defectpixel_result.pixel_list[defect_idx]), &search_pixel[i], pixel_struct_size);					
				else
				memcpy(&(defectpixel_pv_result.pixel_list[defect_idx]), &search_pixel[i], pixel_struct_size);					
				
				defect_idx++;
                if((search_pixel[i].pixel_diff==defect_min_diff)&&(search_pixel[i].area_id==DEFECT_AREA_2))
                    defect_num--;    
			}
		}
		if( defect_mode==DEFECT_MODE_CAPTURE ) 
		{
			defectpixel_result.defect_num = defect_idx;								
			defectpixel_result.search_num = defect_curr_search_num;
		}
		else
		{
			defectpixel_pv_result.defect_num = defect_idx;								
			defectpixel_pv_result.search_num = defect_curr_search_num;
		}
	}			
	else
	{	/* Sort Area1 Pixels */
		defect_num = defect_area1_search_num;
		for(i=defect_area1_min_diff;i<255;i++)
		{
	        if(defect_num > *(p_diffArea1Value+i))
		    {
		        defect_num -= *(p_diffArea1Value+i);
				if(defect_num <= defectpixel_data.max_defect_num)
				{
				    defect_num = defectpixel_data.max_defect_num - defect_num;
					break;				    
				}
            }
            else
            {
                defect_num = 0;
				break;
		    }			
		}			
		defect_min_diff = i;
		/* Search diff value inside max defect num */
		for(i=0;i<defect_area1_search_num;i++)				
		{
			if( (search_pixel[i].pixel_diff>defect_min_diff)&&(search_pixel[i].area_id==DEFECT_AREA_1) ||
			    ((defect_num>0)&&(search_pixel[i].pixel_diff==defect_min_diff)&&(search_pixel[i].area_id==DEFECT_AREA_1)))
			{
				if( defect_mode==DEFECT_MODE_CAPTURE ) 
				memcpy(&(defectpixel_result.pixel_list[defect_idx]), &search_pixel[i], pixel_struct_size);					
				else
				memcpy(&(defectpixel_pv_result.pixel_list[defect_idx]), &search_pixel[i], pixel_struct_size);					
					
				defect_idx++;
			    if(search_pixel[i].pixel_diff==defect_min_diff)
			        defect_num--;
			}
		}
		if( defect_mode==DEFECT_MODE_CAPTURE ) 
		{
			defectpixel_result.defect_num = defect_idx;						
			defectpixel_result.search_num = defect_area1_search_num;			
		}
		else
		{
			defectpixel_pv_result.defect_num = defect_idx;						
			defectpixel_pv_result.search_num = defect_area1_search_num;			
		}
	}
}				

void camera_defect_sort_pixel_by_avg_pri(kal_uint8	defect_mode, kal_uint16 search_mode, kal_uint16 defect_type_select)
{
	kal_uint16	defect_min_diff=255, defect_num, defect_idx=0;
	kal_uint32	i;	    
	kal_uint32  pixel_struct_size = sizeof(defectpixel_pixel_struct);	    
    register kal_uint32 *p_diffValue;
    register kal_uint32 *p_diffArea1Value;
	if( defect_mode==DEFECT_MODE_CAPTURE ) 
    {
        p_diffValue = &diffValue[0];
        p_diffArea1Value = &diffArea1Value[0];
    }
    else
	{
        p_diffValue = &diffValue_pv[0];
        p_diffArea1Value = &diffArea1Value_pv[0];
    }	
	if(defect_curr_search_num < defectpixel_data.max_defect_num)
	{
		if( defect_mode==DEFECT_MODE_CAPTURE ) 
		{
    		memcpy(defectpixel_result.pixel_list, search_pixel, (defect_curr_search_num)*pixel_struct_size);
			defectpixel_result.defect_num = defect_curr_search_num;
			defectpixel_result.search_num = defect_curr_search_num;						
		}
		else
		{
			memcpy(defectpixel_pv_result.pixel_list, search_pixel, (defect_curr_search_num)*pixel_struct_size);
			defectpixel_pv_result.defect_num = defect_curr_search_num;
			defectpixel_pv_result.search_num = defect_curr_search_num;						
		}
	}
	else
	{
		/* Search defect_min_diff */
		defect_num = defect_curr_search_num;
		for(i=defect_curr_min_diff;i<=255;i++)
		{
    	    if(defect_num > *(p_diffValue+i))
    		{
    		    defect_num -= *(p_diffValue+i);
				if(defect_num <= defectpixel_data.max_defect_num)
				{
				    defect_num = defectpixel_data.max_defect_num - defect_num;
					break;				    
				}
            }
            else
            {
                defect_num = 0;
				break;
    		}			
    	}			
		defect_min_diff = i;
		/* Search diff value inside max defect num */
		for(i=0;i<defect_curr_search_num;i++)				
		{
			if( (search_pixel[i].pixel_diff>defect_min_diff) ||
			    ((defect_num>0)&&(search_pixel[i].pixel_diff==defect_min_diff)) )
			{
				if( defect_mode==DEFECT_MODE_CAPTURE ) 
				memcpy(&(defectpixel_result.pixel_list[defect_idx]), &search_pixel[i], pixel_struct_size);						
				else
				memcpy(&(defectpixel_pv_result.pixel_list[defect_idx]), &search_pixel[i], pixel_struct_size);						
				defect_idx++;
			    if(search_pixel[i].pixel_diff==defect_min_diff)
                    defect_num--;				        				    
			}
		}
		if( defect_mode==DEFECT_MODE_CAPTURE ) 
		{
			defectpixel_result.defect_num = defect_idx;			
			defectpixel_result.search_num = defect_curr_search_num;									
		}
		else
		{
			defectpixel_pv_result.defect_num = defect_idx;			
			defectpixel_pv_result.search_num = defect_curr_search_num;									
		}
	}
}		

kal_uint8 camera_defect_sort_pixel(kal_uint8	defect_mode, kal_uint16 search_mode, kal_uint16 defect_type_select)
{
	if( defect_mode==DEFECT_MODE_CAPTURE ) 	    
	{
	    camera_defect_merge_cap_pixellist(defect_type_select, search_mode);	    
	    defect_curr_search_num = defect_curr_cap_search_num;
	    defect_area1_search_num = defect_area1_cap_search_num;
	    defect_curr_min_diff = defect_curr_cap_min_diff;
	}
	else 
	{
	    camera_defect_merge_pv_pixellist(defect_type_select, search_mode);	    
	    defect_curr_search_num = defect_curr_pv_search_num;	    
	    defect_area1_search_num = defect_area1_pv_search_num;	    
	    defect_curr_min_diff = defect_curr_pv_min_diff;	    
    }	    
	if(search_mode == DEFECT_AREA_CENTER_PRI)
	    camera_defect_sort_pixel_by_center_pri(defect_mode, search_mode, defect_type_select);
	else	//DEFECT_AREA_AVG
	    camera_defect_sort_pixel_by_avg_pri(defect_mode, search_mode, defect_type_select);
	clear_defect_para(defect_mode);	
	return KAL_TRUE;					
}

/* camera_defect_find_white_pixel (capture in dark zoom) */
kal_int32 camera_defect_find_white_pixel( kal_uint16 block_width, kal_uint16 block_height, kal_uint16 pos_y_base,
												kal_uint32 isp_debug_buffer)
{
	kal_uint32	value;
	kal_uint32	pos_x, pos_y;
	kal_uint32  y_base=pos_y_base, full_width=grap_width, height=block_height+y_base;
	kal_uint32	pos_block_offset = isp_debug_buffer; 	
	kal_int32	ret = 1;
	area_id = DEFECT_AREA_1;
	// All block avg sould be 0, search Each Pixel
	for(pos_y=y_base;pos_y<height;pos_y++)
	{	
		for(pos_x=0;pos_x<full_width;pos_x+=4)	    
		{				
			value = (*(volatile unsigned int *) (pos_block_offset+pos_x));			
			if(value>0)
			{
    			// Add Pixel into Search List
        		if((value&0x00000000FF)>0)
    			{
    				if( (ret = camera_defect_add_pixel((value&0x00000000FF)+DEFECT_WHITEPIXEL_OFFSET, pos_x, pos_y)) <0 )
    				break;
    			}
        		if((value&0x0000FF00)>0)
    			{
    				if( (ret = camera_defect_add_pixel(((value&0x0000FF00)>>8)+DEFECT_WHITEPIXEL_OFFSET, (pos_x+1), pos_y)) <0 )
    				break;
    			}
       			if((value&0x00FF0000)>0)
    			{
    				if( (ret = camera_defect_add_pixel(((value&0x00FF0000)>>16)+DEFECT_WHITEPIXEL_OFFSET, (pos_x+2), pos_y)) <0 )
    				break;
    			}
        		if((value&0xFF000000)>0)
    			{
    				if( (ret = camera_defect_add_pixel(((value&0xFF000000)>>24)+DEFECT_WHITEPIXEL_OFFSET, (pos_x+3), pos_y)) <0 )
    				break;
    			}
    		}
    	}		
    	pos_block_offset += full_width;		
	}		
	return ret;
}

/* camera_defect_find_black_pixel (capture in uniform light source) */
kal_int32 camera_defect_find_black_pixel( kal_uint16 block_width, kal_uint16 block_height, kal_uint16 pos_y_base,
												kal_uint32 isp_debug_buffer)
{
	kal_uint32	value, value1;
	kal_uint32  block_avg0, block_avg1, block_avg2, block_avg3, limit0, limit1;		
	kal_uint32	x_idx, x_idx_count;
	kal_uint32	pixel_value, pixel_diff, pos_x, pos_y = pos_y_base; 
	kal_uint32	pos_x_block_offset = isp_debug_buffer, pos_block_offset;
	kal_int32	ret = 1, x, y; 
	kal_uint32	area_flag, channel_id;
	kal_uint32	block[DEFECT_MAX_BLOACK_PER_ROW][4];			
	kal_uint32  blockWidth=block_width, blockHeight=block_height, full_width = grap_width;
    kal_uint32  cal_width = grap_width<<2, pixel_count = block_pixel_count>>2;	
    kal_uint32	defect_width_num=defectpixel_data.block_width_factor;	
    kal_uint32  threshold_area1 = defectpixel_data.threshold_area1, threshold_area2=defectpixel_data.threshold_area2;
    kal_uint32	area1MinX=area1_min_x, area1MaxX=area1_max_x;		
	// Found all block avg.		
	for(x_idx=0;x_idx<defect_width_num;x_idx++)
	{
        block_avg0=block_avg1=block_avg2=block_avg3=0;	    
		pos_block_offset = pos_x_block_offset;
		// 00 01	=> (B Gb)	02 03	=>	(Gr R)
		for(y=0;y<blockHeight;y+=4)  
		{   // only cal 0/1;4/5;8/9..lines to speed up				
			for(x=0;x<blockWidth;x+=4)
			{   // only cal odd pixels to speed up
				value = (*(volatile unsigned int *) (pos_block_offset+x));
			    value1 = (*(volatile unsigned int *) (pos_block_offset+full_width+x));			    
				block_avg0 += ((value>>8)&0xFF);
				block_avg1 += (value&0xFF);
				block_avg2 += ((value1>>8)&0xFF);
				block_avg3 += (value1&0xFF);								
			}
			pos_block_offset += cal_width;			
		}
		block[x_idx][0] = (block_avg0/pixel_count);
		block[x_idx][1] = (block_avg1/pixel_count);
		block[x_idx][2] = (block_avg2/pixel_count);
		block[x_idx][3] = (block_avg3/pixel_count);												
		pos_x_block_offset += blockWidth;				
	}		
	
	// Search Each Pixel
    pos_block_offset = isp_debug_buffer;	
    channel_id = 0;    
    if((pos_y<area1_min_y)||(pos_y>area1_max_y))
        area_flag = DEFECT_AREA_2;
    else                        
        area_flag = DEFECT_AREA_1;            
    y = blockHeight;
    while (--y>=0)
	{	
        x_idx = 0;
        x_idx_count = 0;            
        block_avg0 = block[0][(channel_id<<1)];
        block_avg1 = block[0][1+(channel_id<<1)];
        limit0 = limit1 = threshold_area2;
		for(pos_x=0;pos_x<full_width;pos_x+=4)
		{				
			value = (*(volatile unsigned int *) (pos_block_offset+pos_x));
			// Check threshold				
			if(x_idx_count<blockWidth)
			    x_idx_count+=4;
            else
			{
                x_idx_count = 0;    // reset count
                x_idx++;
                block_avg0 = block[0][(channel_id<<1)];
                block_avg1 = block[0][1+(channel_id<<1)];                
				if((pos_x<area1MinX)||(pos_x>area1MaxX)||(area_flag==DEFECT_AREA_2))
				{
                    limit0 = limit1 = threshold_area2;
					area_id = DEFECT_AREA_2;										    
				}
				else
				{
                    limit0 = limit1 = threshold_area1;
					area_id = DEFECT_AREA_1;				    
				}
			}			
			// Add Pixel into Search List
			pixel_value = (value&0xFF);
			if(pixel_value<block_avg1)
			{
				pixel_diff = block_avg1-pixel_value;
    			if(pixel_diff>limit1)
			    {
    				if( (ret=camera_defect_add_pixel(pixel_diff, pos_x, pos_y)) <0)	
					break;
			    }
            }
			pixel_value = ((value>>8)&0xFF);
			if(pixel_value<block_avg0)
			{
				pixel_diff = block_avg0-pixel_value;
    			if(pixel_diff>limit0)
			    {
    				if( (ret=camera_defect_add_pixel(pixel_diff, (pos_x+1), pos_y)) <0)	
					break;
			    }
            }			
			pixel_value = ((value>>16)&0xFF);
			if(pixel_value<block_avg1)
			{
				pixel_diff = block_avg1-pixel_value;
    			if(pixel_diff>limit1)
			    {
    				if( (ret=camera_defect_add_pixel(pixel_diff, (pos_x+2), pos_y)) <0)	
					break;
			    }
            }    			
			pixel_value = ((value>>24)&0xFF);
			if(pixel_value<block_avg0)
			{
				pixel_diff = block_avg0-pixel_value;
    			if(pixel_diff>limit0)
			    {
    				if( (ret=camera_defect_add_pixel(pixel_diff, (pos_x+3), pos_y)) <0)	
					break;
    			}
    		}
    	}		
		pos_block_offset += full_width;		
        channel_id = 1 - channel_id;
        pos_y++;
	}		
	return ret;
}

void reset_camera_defectpixel(kal_uint8	defect_mode)
{
	/* Clean previous defect data*/
	clear_defect_para(defect_mode);	
	if(defect_mode==DEFECT_MODE_CAPTURE)
		defect_operation_state = DEFECT_INIT_STATE;	
	else if(defect_mode==DEFECT_MODE_PREVIEW)		
		defect_operation_pv_state = DEFECT_INIT_STATE;
	else if(defect_mode==DEFECT_MODE_BOTH)		
	{
		defect_operation_state = DEFECT_INIT_STATE;			
		defect_operation_pv_state = DEFECT_INIT_STATE;		
	}
}

kal_int32 camera_defectpixel_verify_block_factor(const kal_uint32  isp_debug_buffer_size, defectpixel_para_struct *defect_data) 
{
	kal_uint16	max_width, max_height, block_width, block_height;
	kal_uint16	cap_col_count, i;
	
	/* Check Image WXH */
	max_width = (defect_data->image_width)-(defect_data->boarder_len<<1);
	max_height = (defect_data->image_height)-(defect_data->boarder_len<<1);	
	i = (max_width&0x03);
	if(i==2)	// i==1||3 drop these pixels
	{
		defect_data->boarder_len += 1;
		max_width = (defect_data->image_width)-(defect_data->boarder_len<<1);
	}
	/* Check Block WXH */
	block_width = max_width / defect_data->block_width_factor;		
	block_height = max_height / defect_data->block_height_factor;			
	if((block_height<4)||(block_width<4))	
		return ERR_PARA_SIZE_OVER_MEM;		
	/* Check MEM Size */
	cap_col_count = (isp_debug_buffer_size/max_width)/block_height;		
	if(cap_col_count<1)
		return ERR_PARA_SIZE_OVER_MEM;				
		
	/* Check Max 32 blocks per row */
	if((defect_data->block_width_factor)>DEFECT_MAX_BLOACK_PER_ROW)
		return ERR_PARA_SIZE_OVER_BLOCK;
		
    /* Check Max defect and search Num */		
    if((defect_data->max_defect_num)>=MAX_DEFECT_NUM)
        return ERR_OVER_MAX_DEFECT_NUM;
	if((defect_data->max_search_num)>DEFECT_MAX_SEARCH_NUM)	
		return ERR_OVER_MAX_SEARCH_NUM;
        
	return 1;	
}

kal_int32 camera_defectpixel_process(	kal_uint8	defect_mode, defectpixel_para_struct *defect_data, 
													kal_uint32 	isp_debug_buffer, kal_uint32 isp_debug_buffer_size)
{
	kal_uint16	block_width, block_height, grap_height_offset;	
	kal_uint8	cap_col_count, shading_en = KAL_FALSE;
	kal_uint32	i;
	kal_int32	ret = 1;
    kal_uint16	defect_width_num=0, defect_height_num=0;		
    defect_current_mode = defect_mode;
	if( (defect_data->defect_type_select == DEFECT_TYPE_BLACK_PIXEL_ONLY)||
		(defect_data->defect_type_select == DEFECT_TYPE_WHITE_PIXEL_ONLY)||
		((defect_data->defect_type_select==DEFECT_TYPE_BOTH_BW)&&
 	  	 (defect_data->defect_type==DEFECT_TYPE_BLACK_PIXEL)) ||
		((defect_data->defect_type_select==DEFECT_TYPE_BOTH_WB)&&
		 (defect_data->defect_type==DEFECT_TYPE_WHITE_PIXEL)) )
	{
	    if( defect_mode==DEFECT_MODE_CAPTURE ) 				    
		defect_operation_state = DEFECT_START_STATE;		
		else
		defect_operation_pv_state = DEFECT_START_STATE;		
		clear_defect_para(defect_mode);		            
	}	
	
	if((defect_data->max_search_num)>DEFECT_MAX_SEARCH_NUM)	
		return ERR_OVER_MAX_SEARCH_NUM;
	
	/* Make sure shading disable */
	if(((REG_ISP_SHADING_CTRL1)&REG_SHADING_ENABLE_BIT)>0)
	    shading_en = KAL_TRUE;
	DISABLE_SHADING_COMPENSATION;
	/* Set ISP Gain as 1X*/
	isp_pregain = BASEGAIN;
	ae_set_isp_pregain();
	
	/* Init Parameter */		
	memcpy(&defectpixel_data, defect_data, sizeof(defectpixel_para_struct));		
	if(defect_mode==DEFECT_MODE_CAPTURE)
	{
		// init defectpixel_cap_data;		
		memcpy(&defectpixel_cap_data, defect_data, sizeof(defectpixel_para_struct));				
		if((defect_data->max_defect_num)>=MAX_DEFECT_NUM)
            return ERR_OVER_MAX_DEFECT_NUM;
	}
	else	// preview
	{
		// init defectpixel_pv_data;				
		memcpy(&defectpixel_pv_data, defect_data, sizeof(defectpixel_para_struct));						
		if((defect_data->max_defect_num)>=MAX_PV_DEFECT_NUM)
            return ERR_OVER_MAX_DEFECT_NUM;		
	}
	
	grap_width = defectpixel_data.image_width ;
	grap_height = defectpixel_data.image_height;

	/* Calculate defect total width/hwight */		
	defect_width_num = defectpixel_data.block_width_factor;
	defect_height_num = defectpixel_data.block_height_factor;		
	block_width = ((defectpixel_data.image_width)/defect_width_num)&0xFFFC;
	block_height = ((defectpixel_data.image_height)/defect_height_num)&0xFFFC; 
	// Max 32 blocks per row
	if(defect_width_num>DEFECT_MAX_BLOACK_PER_ROW)
		return ERR_PARA_SIZE_OVER_BLOCK;
	
	/* Define Area1 and Area2 and Thred*/
	area1_min_x = ((defect_width_num>>2)-1)*block_width;		
	area1_min_y = ((defect_height_num>>2)-1)*block_height;		
	area1_max_x = (((defect_width_num*3)>>2)-1)*block_width;
	area1_max_y = (((defect_height_num*3)>>2)-1)*block_height;	
    defectpixel_data.threshold_area1 = (defectpixel_data.threshold_area1<<7)/100;    
    defectpixel_data.threshold_area2 = (defectpixel_data.threshold_area2<<7)/100;        

	cap_col_count = (isp_debug_buffer_size/grap_width)/block_height;		
	if(cap_col_count<1)
		return ERR_PARA_SIZE_OVER_MEM;
	else if(cap_col_count>defectpixel_data.block_height_factor)	
	    cap_col_count = defectpixel_data.block_height_factor;
	grap_height = cap_col_count*block_height;	
	block_pixel_count = (((defectpixel_data.image_width)*(defectpixel_data.image_height))/(defect_width_num*defect_height_num))>>2;
	
	if(defectpixel_data.defect_type == DEFECT_TYPE_BLACK_PIXEL)		
	{
        switch_cap_en = KAL_TRUE;
        grap_height_offset = 0;
        SET_RAW_DATA_R_OFFSET_ADJ(0);
        SET_RAW_DATA_GR_OFFSET_ADJ(0);
        SET_RAW_DATA_B_OFFSET_ADJ(0);
        SET_RAW_DATA_GB_OFFSET_ADJ(0);                                    	        
				
        // Find defect pixel in this frame												
        camera_defect_raw_capture(	0, 0, grap_width, grap_height, isp_debug_buffer);			
        for(i=0;i<cap_col_count;i++)
        {
		    if((grap_height_offset+block_height)==defectpixel_data.image_height)
		    {
				ret = camera_defect_find_black_pixel(	block_width, (kal_uint16)(block_height-defectpixel_data.boarder_len), grap_height_offset, 
											 	(isp_debug_buffer+(grap_width*(block_height)*i)));
		    }
		    else
		    {
				ret = camera_defect_find_black_pixel(	block_width, block_height, grap_height_offset, 
											 	(isp_debug_buffer+(grap_width*(block_height)*i)));
			}
		    grap_height_offset = grap_height_offset + block_height;
			if(ret<0)
				break;
		}
		if((ret>0)&&((grap_height_offset+defectpixel_data.boarder_len)<(defectpixel_data.image_height)))
		{
			camera_defect_raw_capture(	0, grap_height_offset, grap_width, (kal_uint16)((defectpixel_data.image_height)-grap_height_offset), isp_debug_buffer);
			
			// Find defect pixel in this frame												
            block_pixel_count = ( block_width*((defectpixel_data.image_height)-grap_height_offset-defectpixel_data.boarder_len) )>>2;
			ret = camera_defect_find_black_pixel(	block_width, (kal_uint16)((defectpixel_data.image_height)-grap_height_offset-defectpixel_data.boarder_len), 
			        grap_height_offset, isp_debug_buffer);
		}
	}
	else
	{
        switch_cap_en = KAL_TRUE;	        
    	grap_height_offset = 0;
        /* Set OB as thred */	    	    
        SET_RAW_DATA_R_NEG_SIGN;
        SET_RAW_DATA_GR_NEG_SIGN;
        SET_RAW_DATA_B_NEG_SIGN;
        SET_RAW_DATA_GB_NEG_SIGN;            
        if(defectpixel_data.threshold_area1>31)
            defectpixel_data.threshold_area1 = 31;
        SET_RAW_DATA_R_OFFSET_ADJ(defectpixel_data.threshold_area1<<2);
        SET_RAW_DATA_GR_OFFSET_ADJ(defectpixel_data.threshold_area1<<2);
        SET_RAW_DATA_B_OFFSET_ADJ(defectpixel_data.threshold_area1<<2);
        SET_RAW_DATA_GB_OFFSET_ADJ(defectpixel_data.threshold_area1<<2);                                    
		// Find defect pixel in this frame												
		camera_defect_raw_capture(	0, 0, grap_width, grap_height,isp_debug_buffer);			
		for(i=0;i<cap_col_count;i++)
		{
		    if((grap_height_offset+block_height)==defectpixel_data.image_height)
		    {
				ret = camera_defect_find_white_pixel(	block_width, (kal_uint16)(block_height-defectpixel_data.boarder_len), grap_height_offset, 
												 	(isp_debug_buffer+(grap_width*(block_height)*i)));				        
		    }
		    else
		    {
				ret = camera_defect_find_white_pixel(	block_width, block_height, grap_height_offset, 
												 	(isp_debug_buffer+(grap_width*(block_height)*i)));
			}
		    grap_height_offset = grap_height_offset + block_height;
			if(ret<0)
				break;                												
		}	
		if((ret>0)&&((grap_height_offset+defectpixel_data.boarder_len)<(defectpixel_data.image_height)))
		{
			camera_defect_raw_capture(	0, grap_height_offset, grap_width, (kal_uint16)((defectpixel_data.image_height)-grap_height_offset), isp_debug_buffer);
			
			// Find defect pixel in this frame												
            block_pixel_count = ( block_width*((defectpixel_data.image_height)-grap_height_offset-defectpixel_data.boarder_len) )>>2;
			ret = camera_defect_find_white_pixel(	block_width, (kal_uint16)((defectpixel_data.image_height)-grap_height_offset-defectpixel_data.boarder_len), 
			        grap_height_offset, isp_debug_buffer);
		}
	}

	/* Sorting candidate pixels */	
	if(ret>0)
	{
		if((defectpixel_data.defect_type_select == DEFECT_TYPE_BLACK_PIXEL_ONLY)||		
			(defectpixel_data.defect_type_select == DEFECT_TYPE_WHITE_PIXEL_ONLY)|| 
			((defectpixel_data.defect_type_select==DEFECT_TYPE_BOTH_BW)&&
			 (defectpixel_data.defect_type==DEFECT_TYPE_WHITE_PIXEL)) ||
			((defectpixel_data.defect_type_select==DEFECT_TYPE_BOTH_WB)&&
			 (defectpixel_data.defect_type==DEFECT_TYPE_BLACK_PIXEL)) )	
		{			
			camera_defect_sort_pixel(defect_mode, defectpixel_data.search_mode_select, defectpixel_data.defect_type_select);
			
			if( defect_mode==DEFECT_MODE_CAPTURE ) 			
			{
			    defect_operation_state = DEFECT_FINISH_STATE;			
				ret = defectpixel_result.defect_num;		
			}
			else
			{
			    defect_operation_pv_state = DEFECT_FINISH_STATE;								
				ret = defectpixel_pv_result.defect_num;		
		    }				
		}				
		else
		{
	        if(defect_mode==DEFECT_MODE_CAPTURE)		    
			defect_operation_state = DEFECT_PROCESS_STATE;	
            else			    
			defect_operation_pv_state = DEFECT_PROCESS_STATE;	
			ret = ERR_STATE_UNDER_PROCESSING;
		}
	}
		
	/* Restore shading status */
	if(shading_en == KAL_TRUE)
	{
    	ENABLE_SHADING_COMPENSATION;
	}	
	return ret;
}

kal_int32 get_defectpixel_info(kal_uint8 defect_mode, defectpixel_para_struct **defect_data, defectpixel_result_struct **defect_result)
{
	/* defect_mode: Load preview mode or Load Capture Mode */
	if( defect_mode==DEFECT_MODE_CAPTURE ) 	
	{
		*defect_data = &defectpixel_cap_data;
		*defect_result = &defectpixel_result;
		if(defect_operation_state==DEFECT_FINISH_STATE)
			return defectpixel_result.defect_num;		
		else if(defect_operation_state==DEFECT_PROCESS_STATE)
			return ERR_STATE_UNDER_PROCESSING;
		else
			return ERR_STATE_INIT_PROCESS;
	}
	else
	{
		*defect_data = &defectpixel_pv_data;
		*defect_result = &defectpixel_pv_result;
		if(defect_operation_pv_state==DEFECT_FINISH_STATE)
			return defectpixel_pv_result.defect_num;		
		else if(defect_operation_pv_state==DEFECT_PROCESS_STATE)
			return ERR_STATE_UNDER_PROCESSING;
		else
			return ERR_STATE_INIT_PROCESS;						
	}

	return ERR_STATE_UNKNOWN_MODE;		
}

/* Store in NVRAM */
void copy_calibration_result_to_camera_defect(nvram_camera_defect_struct *p_cam_defect)
{
	kal_uint32 i;
	if( p_cam_defect !=NULL ) 
	{
		//capture , defect_num should <=255
		for(i=0;i<defectpixel_result.defect_num;i++)			
		{
			p_cam_defect->defect[i] = (defectpixel_result.pixel_list[i].pos_x)|(defectpixel_result.pixel_list[i].pos_y<<16);
		}
		if(i>=MAX_DEFECT_NUM)
            p_cam_defect->defect[MAX_DEFECT_NUM-1] = 0xFFFFFFFF;				
        else
		p_cam_defect->defect[i] = 0xFFFFFFFF;		
		//preview , defect_num should <=239
		for(i=MAX_DEFECT_NUM;i<defectpixel_pv_result.defect_num+MAX_DEFECT_NUM;i++)			
		{
			p_cam_defect->defect[i] = (defectpixel_pv_result.pixel_list[i-MAX_DEFECT_NUM].pos_x)|(defectpixel_pv_result.pixel_list[i-MAX_DEFECT_NUM].pos_y<<16);
		}
		if(i>=(MAX_DEFECT_NUM+MAX_PV_DEFECT_NUM))		
            p_cam_defect->defect[MAX_DEFECT_NUM+MAX_PV_DEFECT_NUM-1] = 0xFFFFFFFF;						
        else            
		p_cam_defect->defect[i] = 0xFFFFFFFF;		
	}
}

void pixellist_to_camera_defect(kal_uint8 defect_mode, const defectpixel_result_struct *defect_result, nvram_camera_defect_struct *p_cam_defect)
{
	kal_uint32 i;
	if( defect_mode==DEFECT_MODE_CAPTURE ) 
	{   // defect_num should <= 255
		for(i=0;i<defect_result->defect_num;i++)			
		{
			p_cam_defect->defect[i] = ( ((defect_result->pixel_list[i].pos_y<<16)&0xFFFF0000) | (defect_result->pixel_list[i].pos_x&0x0000FFFF) );
		}
		// Last pixel: pos_x=pos_y=0xFFFF 
		if(i>=MAX_DEFECT_NUM)
            p_cam_defect->defect[MAX_DEFECT_NUM-1] = 0xFFFFFFFF;				
        else		
		p_cam_defect->defect[i] = 0xFFFFFFFF;
		return;
	}
	else
	{   // defect_num should <= 239
		for(i=MAX_DEFECT_NUM;i<defect_result->defect_num+MAX_DEFECT_NUM;i++)			
		{
			p_cam_defect->defect[i] = ( ((defect_result->pixel_list[i-MAX_DEFECT_NUM].pos_y<<16)&0xFFFF0000) | (defect_result->pixel_list[i-MAX_DEFECT_NUM].pos_x&0x0000FFFF) );
		}
		// Last pixel: pos_x=pos_y=0xFFFF 
		if(i>=(MAX_DEFECT_NUM+MAX_PV_DEFECT_NUM))		
            p_cam_defect->defect[MAX_DEFECT_NUM+MAX_PV_DEFECT_NUM-1] = 0xFFFFFFFF;						
        else            		
		p_cam_defect->defect[i] = 0xFFFFFFFF;
		return;
	}
}

/* Load from NVRAM */
void camera_defect_to_pixellist(kal_uint8 defect_mode, const nvram_camera_defect_struct *p_cam_defect, defectpixel_result_struct *defect_result)
{	
	kal_uint32 i;
	if( defect_mode==DEFECT_MODE_CAPTURE ) 
	{
		for(i=0;i<MAX_DEFECT_NUM;i++)			
		{
			defect_result->pixel_list[i].pos_x = ((p_cam_defect->defect[i])&0xFFFF);						
			defect_result->pixel_list[i].pos_y = ((p_cam_defect->defect[i])>>16)&0xFFFF;
			defect_result->pixel_list[i].pixel_diff = 0xFF;
			defect_result->pixel_list[i].area_id = 0xFF;			
			// Last pixel: pos_x=pos_y=0xFFFF, pixel_diff=area_id=0xFF			
			if(p_cam_defect->defect[i] == 0xFFFFFFFF)	
				break;
		}
		defect_result->defect_num = i;
		defect_result->search_num = 0xFFFF;
		return;
	}
	else
	{
		for(i=MAX_DEFECT_NUM;i<MAX_DEFECT_NUM+MAX_PV_DEFECT_NUM;i++)			
		{
			defect_result->pixel_list[i-MAX_DEFECT_NUM].pos_x = ((p_cam_defect->defect[i])&0xFFFF);						
			defect_result->pixel_list[i-MAX_DEFECT_NUM].pos_y = ((p_cam_defect->defect[i])>>16)&0xFFFF;
			defect_result->pixel_list[i-MAX_DEFECT_NUM].pixel_diff = 0xFF;
			defect_result->pixel_list[i-MAX_DEFECT_NUM].area_id = 0xFF;			
			// Last pixel: pos_x=pos_y=0xFFFF, pixel_diff=area_id=0xFF			
			if(p_cam_defect->defect[i] == 0xFFFFFFFF)	
				break;
		}
		defect_result->defect_num = i-MAX_DEFECT_NUM;
		defect_result->search_num = 0xFFFF;
		return;
	}
}

kal_uint8 camera_af_lens_offset_cal(AF_OQC_cal_struct *AF_cal_in)
{
#if (defined(AF_SUPPORT)&&(!defined(YUV_SENSOR_SUPPORT)))
	kal_int16 i;
	kal_uint32 start_t, end_t;
	kal_uint16 lut_i=0xFFFF;
	camera_af_loop_state_flag = 0;
	/* check Preview & AF is on */
	if (isp_operation_state != ISP_PREVIEW_STATE)
	{
		return AFCAL_PREVIEW_OFF;	
	}
	if ((af_operation_state == AF_COLLECT_STATE) ||
		(af_operation_state == AF_SEARCH_STATE) ||
		(af_operation_state == AF_IDLE_STATE))
	{
		return AFCAL_AF_NOT_READY;	
	}
	if (dsc_status.af.mode==CAM_AF_INFINITE_MODE)
	{
		return AFCAL_AF_INVALID_MODE;	
	}
	if (ae_enable_flag == ISP_ON)
	{
		return AFCAL_AE_NOT_OFF;	
	}
	if (awb_enable_flag == ISP_ON)
	{
		return AFCAL_AWB_NOT_OFF;	
	}	
	camera_af_loop_state_flag = 1;	
	/* check table lut */
	for (i=0;i<camera_lens.INFO.af_table_num;i++)
	{
		if (AF_cal_in->AF_cal_distance == camera_lens.AF[i].distance)
		{
			lut_i = i;
			break;
		}
	}
	if (lut_i == 0xFFFF)
	{
		AF_cal_in->AF_table_step = 0xFFFF;
		return AFCAL_NO_REFERENCE_TABLE;
	}
	AF_cal_in->AF_table_step = camera_lens.AF[lut_i].pos;
	AF_cal_in->AF_cal_step = 0x0;
	/* set AF setting for offset calibration */
	AF_Set_Min_Step(AF_cal_in->AF_min_step_tol);
	/* for loop to start AF */
	camera_af_loop_state_flag = 2;
	cct_camera_operation_setting(CAM_AF_KEY, CAM_AF_ONE_TIME);	
	start_t = AF_SYSTEM_TIME;
	end_t = start_t;
	while (end_t-start_t < AFCAL_AF_MAX_TIME)
	{
		if (camera_af_loop_state_flag == 3)
		{
			af_main();
			if (af_operation_state==AF_FREEZE_STATE)
			{
				camera_af_loop_state_flag = 7;
				AF_Recover_Min_Step();	
				return AFCAL_FOCUS_FAIL;			
			}
			else
			{
				camera_af_loop_state_flag = 4;			
			}
		}
		else if (camera_af_loop_state_flag == 5)
		{
			af_main();
			camera_af_loop_state_flag = 6;
		}
		/* check tolerance */
		if (camera_af_loop_state_flag == 6)
		{
			AF_cal_in->AF_cal_step = AF_best_step[AF_mz_win];
			if (AF_best_step[AF_mz_win] >= camera_lens.AF[lut_i].pos)
			{
				if (AF_best_step[AF_mz_win] > camera_lens.AF[lut_i].pos+AF_cal_in->AF_max_tol)
				{
					camera_af_loop_state_flag = 7;
					AF_Recover_Min_Step();
					return AFCAL_OFFSET_TOOL_LARGE;
				}
				else
				{
					/* write to global variable */
					if ((kal_uint16)(AF_best_step[AF_mz_win] - (kal_int16)camera_lens.AF[lut_i].pos) > 0x7FFF)
					{
						camera_af_loop_state_flag = 7;
						AF_Recover_Min_Step();
						return AFCAL_OFFSET_OVER_LENGTH;		
					}
					else
					{
						camera_lens.INFO.af_calibration_offset = (kal_uint16)(AF_best_step[AF_mz_win] - (kal_int16)camera_lens.AF[lut_i].pos) + 0x8000;
						camera_af_loop_state_flag = 7;
						AF_Recover_Min_Step();
						return AFCAL_PASS;
					}
				}
			}
			else
			{
				if (AF_best_step[AF_mz_win]+AF_cal_in->AF_min_tol < camera_lens.AF[lut_i].pos)
				{
					camera_af_loop_state_flag = 7;
					AF_Recover_Min_Step();
					return AFCAL_OFFSET_TOOL_SMALL;
				}
				else
				{
					/* write to global variable */
					if ((kal_uint16)((kal_int16)camera_lens.AF[lut_i].pos - AF_best_step[AF_mz_win]) > 0x8000)
					{
						camera_af_loop_state_flag = 7;
						AF_Recover_Min_Step();
						return AFCAL_OFFSET_UNDER_LENGTH;		
					}
					else
					{
						camera_lens.INFO.af_calibration_offset = 0x8000 - (kal_uint16)((kal_int16)camera_lens.AF[lut_i].pos - AF_best_step[AF_mz_win]);
						camera_af_loop_state_flag = 7;
						AF_Recover_Min_Step();
						return AFCAL_PASS;
					}
				}
			
			}
		}
		kal_sleep_task(AFCAL_AF_LOOP_DELAY);
		end_t = AF_SYSTEM_TIME;
		if (start_t > end_t)
		{
#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6228_SERIES))
			end_t += 0x80000;
#else /*MT6229, MT6227, MT6226, MT6217, MT6226M*/
			end_t += 0x1000000;
#endif   /*MT6228, MT6229, MT6227, MT6226, MT6226M*/
		}
	}
	camera_af_loop_state_flag = 7;
	AF_Recover_Min_Step();
	cct_camera_operation_setting(CAM_AF_KEY, CAM_AF_RELEASE);
	/* set flag to enable next AF callback */
	IRQMask(IRQ_CAMERA_CODE);
	af_cal_complete=KAL_TRUE;
	IRQUnmask(IRQ_CAMERA_CODE);	
	return AFCAL_FOCUS_TIME_OUT;
#else
	return AFCAL_AF_NOT_SUPPORT;
#endif	
}

void camera_af_Lens_offset_cal_hisr_done(void)
{
#if (defined(AF_SUPPORT)&&(!defined(YUV_SENSOR_SUPPORT)))
	if (camera_af_loop_state_flag == 2)	//lut search
	{
		camera_af_loop_state_flag = 3;
	}
	else if (camera_af_loop_state_flag == 4)//detail search
	{
		camera_af_loop_state_flag = 5;	
	}
#endif
}
#endif  // defined(ISP_SUPPORT)&&(!defined(DRV_ISP_6225_SERIES))&&(!defined(DRV_ISP_6219_SERIES))
