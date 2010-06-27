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
 *   af.c
 *
 * Project:
 * --------
 *   MT6226,MT6227,MT6228,MT6229
 *
 * Description:
 * ------------
 *   Auto Focus Algorithm
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#include "kal_release.h"
#include "drv_features.h"

#if (defined(ISP_SUPPORT)&&(!defined(DRV_ISP_6219_SERIES)))
#include "drv_comm.h"
#include "IntrCtrl.h"
#include "ae_awb.h"
#include "isp_if.h"
#include "image_sensor.h"
#include "sccb.h"
#include "camera_para.h"
#include "med_api.h"
#include "af.h"

/**************   AF DECLARATION    ****************************************/
kal_uint32	AF_focus_result[AF_WIND_NO][MAX_STEP_NO];
kal_uint8 	af_table_search_start_idx=0;
kal_uint8 	af_table_search_end_idx=0;
kal_bool  	af_detail_search=KAL_FALSE;
AF_OPERATION_STATE_ENUM af_operation_state=AF_IDLE_STATE;
af_result_struct af_result={0xFF,0,1};

#if (defined(AF_SUPPORT))
extern kal_uint8 af_count;
extern kal_uint8 ae_count;

extern kal_uint8 AF_small_check_count;
extern void (*cam_focus_cb) (kal_uint8 return_code);

/* call by af zone setting for 6228 */
extern kal_uint16	isp_grab_start_y;
extern volatile kal_uint8 isp_digital_zoom_factor;

/**************   AF DECLARATION    ****************************************/
af_operation_para_struct af_oper_data;
kal_bool		af_cal_complete=KAL_TRUE;
kal_uint8	af_fail_count=0;
kal_uint8	af_detail_idx=0;
kal_uint8	af_zone_width=AF_WINDOW_W,af_zone_height=AF_WINDOW_H;
kal_uint32	AF_Result0,AF_Result1,AF_Result2,AF_Result3,AF_Result4;
/* af backup normal mode setting */
kal_uint32	af_bacup_p_limit, af_backup_autodefect, af_backup_edge, af_backup_LPF;
/* AF zone check valid flag */
kal_bool		af_zone_valid_flag = KAL_FALSE;
/****************************************************************************
 *          AF Main
 ****************************************************************************/
void af_main(void)
{
#if (!defined(YUV_SENSOR_SUPPORT))
	if(af_operation_state==AF_SEARCH_STATE)//prevent cb later than AF key release
	{
		af_result=af_proc();
	
		if(af_detail_search==KAL_FALSE)	/* Table Search */
		{
			if(af_result.result==AF_TABLE_SEARCH_SUCCESS)
			{
				af_operation_state=AF_COLLECT_STATE;
				af_detail_search=KAL_TRUE;
				af_detail_idx=0;
				af_count=0;
				af_dir_inv_delay_count = -1;//clear inv step delay count
			}
			else if(af_result.result==AF_TABLE_SEARCH_FAIL)
			{
				if((dsc_status.af.mode==CAM_AF_AUTO_MODE) || (dsc_status.af.mode==CAM_AF_MACRO_MODE))
				{
					af_operation_state=AF_FREEZE_STATE;
					lens_func->lens_af_move_to((kal_int32)camera_lens.INFO.af_hyper_pos);
					AF_step_move_log((kal_int16)camera_lens.INFO.af_hyper_pos);
					dsc_status.af.index=0xFF;
					cam_focus_cb(0xFF);	/* Inform MMI AF Fail */
				}
				else if(dsc_status.af.mode==CAM_AF_INFINITE_MODE)
				{
					af_fail_count++;
					if(af_fail_count<2)
					{
						dsc_status.af.range=AF_NORMAL_RANGE;	/* Switch to NORMAL range search */
						af_table_search_range_config(dsc_status.af.range);
						lens_func->lens_af_move_to((kal_int32)camera_lens_step.AF[af_table_search_end_idx].pos);
						AF_step_move_log((kal_int16)camera_lens_step.AF[af_table_search_end_idx].pos);
						dsc_status.af.index=af_table_search_end_idx;
						af_operation_state=AF_COLLECT_STATE;
						af_count=0;
					}
					else
					{
						af_operation_state=AF_FREEZE_STATE;
						lens_func->lens_af_move_to((kal_int32)camera_lens.INFO.af_hyper_pos);
						AF_step_move_log((kal_int16)camera_lens.INFO.af_hyper_pos);
						dsc_status.af.index=0xFF;
						cam_focus_cb(0xFF);	/* Inform MMI AF Fail */
						// Config back to Infinite Range
						dsc_status.af.range=AF_INFINITE_RANGE;
						af_table_search_range_config(dsc_status.af.range);
					}
				}
			}
			else
				ASSERT(0);
			}
		else		/* Detail Search */
		{
			if((af_result.result==AF_SUCCESS)||(af_result.result==AF_DETAIL_SEARCH_FAIL))
			{
				lens_func->lens_af_move_to((kal_int32)af_result.best_step);
				AF_step_move_log((kal_int16)af_result.best_step);
				af_operation_state=AF_FREEZE_STATE;
				cam_focus_cb((kal_uint8)af_result.success_zone);	/* Inform MMI AF Success Zone */
				// Config back to original range
				if(dsc_status.af.mode==CAM_AF_INFINITE_MODE)
				{
					dsc_status.af.range=AF_INFINITE_RANGE;
					af_table_search_range_config(dsc_status.af.range);
				}
			}
			else if(af_result.result==AF_DETAIL_SEARCH_EDGE_FAIL)
			{
				if((dsc_status.af.mode==CAM_AF_AUTO_MODE) || (dsc_status.af.mode==CAM_AF_MACRO_MODE))
				{
					ASSERT(0);
				}
				else if(dsc_status.af.mode==CAM_AF_INFINITE_MODE)
				{
					af_fail_count++;
					if(af_fail_count<2)
					{
						af_detail_search=KAL_FALSE;				/* Go back to table search */
						dsc_status.af.range=AF_NORMAL_RANGE;	/* Switch to NORMAL range search */
						af_table_search_range_config(dsc_status.af.range);
						lens_func->lens_af_move_to((kal_int32)camera_lens_step.AF[af_table_search_end_idx].pos);
						AF_step_move_log((kal_int16)camera_lens_step.AF[af_table_search_end_idx].pos);
						dsc_status.af.index=af_table_search_end_idx;
						af_operation_state=AF_COLLECT_STATE;
						af_count=0;
					}
					else
						ASSERT(0);				
				}
			}
			else
				ASSERT(0);
		}
	}
	/* set flag to enable next AF callback */
	IRQMask(IRQ_CAMERA_CODE);
	af_cal_complete=KAL_TRUE;
	IRQUnmask(IRQ_CAMERA_CODE);	
#endif
}

kal_bool get_focus_step(kal_uint32 *total_step,kal_uint32 *current_step)
{
#if (!defined(YUV_SENSOR_SUPPORT))
	if(lens_func->get_lens_af_status() != AF_STATUS_READY)
		return KAL_FALSE;
	else
	{
		*total_step=camera_lens.INFO.af_me_macro_pos;
		*current_step=lens_func->get_lens_af_current_pos();
		return KAL_TRUE;
	}
#endif	
}

#if (!defined(YUV_SENSOR_SUPPORT))
void af_custom_para_first_init(af_operation_para_struct *custom_para)//jhyu:customize
{
	custom_para->AF_DF_r = 104 ;
	/* low contrast check */
	custom_para->AF_LC_p = 124;
	custom_para->AF_LC_a = 120;
	custom_para->AF_LC_v = 112;
	custom_para->AF_LC_m = 36;
	custom_para->AF_LC_w = 8;
	/* threshold divided by 128*/
	custom_para->AF_Gr_1 = 121;
	custom_para->AF_Gr_2 = 121;
	custom_para->AF_Gd_u = 16;
	custom_para->AF_Gd_d = 16;
	custom_para->AF_Gu_r = 19;
	custom_para->AF_Gd_r = 19;
	/* closer search */
	custom_para->AF_Cr_n = 121;
	custom_para->AF_Cr_1 = 100;
	custom_para->AF_Cr_mr = 100;
	custom_para->AF_Cr_dr = 79;
	custom_para->AF_Cr_ur = 79;
	/* AF contrast min FV */
	custom_para->AF_step_FV = 5000;
	custom_para->AF_noise_FV = 1000;
	custom_para->AF_min_FV = 500;
	custom_para->AF_mid_FV = 3000;
	custom_para->AF_max_FV = 80000;
	/* general threshold*/
	custom_para->AF_FC_fmin = 16;
	custom_para->AF_Gr_fm = 50;
	custom_para->AF_Cr_ft = 36;
	custom_para->AF_Cr_fd = 79;
	/*search distance*/
	custom_para->AF_Normal_Dist = 6;
	custom_para->AF_Inf_Dist = 3;
	custom_para->AF_Macro_Dist =8;
	custom_para->AF_Closer_Dist = 6;
	/*speed up threshod*/
	custom_para->AF_Fast_Th_S = 102;
	custom_para->AF_Fast_Th_E = 110;
	custom_para->AF_LUT_min_diff_FV = 8000;
	custom_para->AF_LUT_min_count = 3;
	/*step time optimize*/
	custom_para->AF_count_max = 2;
	custom_para->AF_count_max_no = 5;
	custom_para->AF_count_release = 4;//default
	custom_para->AF_count_min = 4;
	/*slow back*/
	custom_para->AF_slow_max_step = 8;
	custom_para->AF_small_check_max = 1;
	/*small search para*/
	custom_para->AF_detail_Rbound[0] = 2;
	custom_para->AF_detail_Rbound[1] = 2;
	custom_para->AF_detail_Lbound[0] = 2;
	custom_para->AF_detail_Lbound[1] = 2;
	custom_para->AF_detail_RC[0] = 3;
	custom_para->AF_detail_RC[1] = 3;
	custom_para->AF_detail_LC[0] = 2;
	custom_para->AF_detail_LC[1] = 2;
	/*speed up for small research*/
	custom_para->AF_shift_count = 1;//default
	custom_para->AF_detail_shift = 2;//default
	custom_para->AF_invese_step = KAL_FALSE;
	custom_para->AF_max_r[0] = 112;
	custom_para->AF_max_r[1] = 112;
	custom_para->AF_min_r[0] = 120;
	custom_para->AF_min_r[1] = 120;
	custom_para->AF_search_dir[0] = KAL_FALSE; 
	custom_para->AF_search_dir[1] = KAL_FALSE; 
	custom_para->AF_min_count[0] = 5;
	custom_para->AF_min_count[1] = 5;
	custom_para->AF_mini_step = 2;
	custom_para->AF_parse_R = 112;
	custom_para->AF_parse_L = 120;
	custom_para->AF_parse_C = 1;
	/* window value for speed up */	
	custom_para->AF_step_win_m0 = 1;//single or three window setting
	custom_para->AF_step_win_n0	 = 3;//must <= 8
	custom_para->AF_step_win_m1 = 1;//5 zone window setting
	custom_para->AF_step_win_n1	 = 4;//must <= 8
	custom_para->AF_closer_enable = KAL_FALSE;
	custom_para->AF_inv_delay = 2;//default
#if (defined(DRV_ISP_6228_SERIES))
	custom_para->AF_wind_y_delay_count = 2;//delay two frames for AF window setting
#else
	custom_para->AF_wind_y_delay_count = 0;//no delay two frames for AF window setting
#endif
	/* AF speed up */
	custom_para->AF_boundary_macro= (kal_int16)camera_lens.INFO.af_me_macro_pos;
	custom_para->AF_boundary_inf = (kal_int16)camera_lens.INFO.af_me_home_pos;
}

void init_af(void)
{
	ENABLE_ATF_EDGE;
	DISABLE_ATF_AREA_ALL;
	
    p_af_oper_data = &af_oper_data;	
    p_camera_lens_step = &camera_lens_step;
    p_camera_lens_timing = &camera_lens_timing;	
	
	AF_init_step_time_lut();
	af_custom_para_first_init(&af_oper_data);
}

void get_af_info(kal_uint8 index)
{
	AF_focus_result[0][index]=AF_Result0;
	AF_focus_result[1][index]=AF_Result1;
	AF_focus_result[2][index]=AF_Result2;
	AF_focus_result[3][index]=AF_Result3;
	AF_focus_result[4][index]=AF_Result4;
}

void get_af_detail_info(kal_uint8 index)
{
	AF_final_result_d[AF_small_check_count][0][index]=AF_Result0;
	AF_final_result_d[AF_small_check_count][1][index]=AF_Result1;
	AF_final_result_d[AF_small_check_count][2][index]=AF_Result2;
	AF_final_result_d[AF_small_check_count][3][index]=AF_Result3;
	AF_final_result_d[AF_small_check_count][4][index]=AF_Result4;
}

void af_window_config(kal_uint8 no,kal_uint16 Hsize,kal_uint16 Vsize,kal_uint16 Hoffset,kal_uint16 Voffset)
{
	kal_uint16	startH, startV;
#if(defined(DRV_ISP_6228_SERIES))
	kal_uint32	blank_V;
	blank_V = get_vd_blanking_lines();
	if (ISP_MIN_DIGITAL_ZOOM_FACTOR == isp_digital_zoom_factor)
	{
		startH = Hoffset>>4;
		startV = (Voffset+blank_V+exposure_window.grab_start_y)>>4;
	}
	else
	{
		startH = Hoffset>>4;
		startV = (Voffset+blank_V+isp_grab_start_y)>>4;	
	}
#else
	startH = Hoffset>>4;
	startV = Voffset>>4;
#endif
	SET_AF_WINDOW(no, startH, startV, startH+(Hsize>>4), startV+(Vsize>>4));
}

void af_zone_setting(kal_uint8 zone)
{
	kal_int16 offsetX, offsetY;
	
	if((zone==CAM_AF_SINGLE_ZONE)||(zone==CAM_AF_MULTI3_ZONE)||(zone==CAM_AF_MULTI5_ZONE))
	{
		/* Zone 0 */
		offsetX=(isp_preview_config_data.af_zone0_x - isp_preview_config_data.camera_offset_x)* isp_grab_width / isp_preview_config_data.target_width;
		offsetX-=(af_zone_width>>1);
		offsetY=(isp_preview_config_data.af_zone0_y - isp_preview_config_data.camera_offset_y)* isp_grab_height / isp_preview_config_data.target_height;
		offsetY-=(af_zone_height>>1);
		if((offsetX<0)||(offsetY<0)||((offsetX+af_zone_width)>isp_grab_width)||((offsetY+af_zone_height)>isp_grab_height))
		{
			af_zone_valid_flag = KAL_FALSE;
			af_window_config(1,isp_grab_width,isp_grab_height,0,0);
		}
		else
		{
			af_zone_valid_flag = KAL_TRUE;
			af_window_config(1,af_zone_width,af_zone_height,(kal_uint16)offsetX,(kal_uint16)offsetY);
		}
	}
	
	if((zone==CAM_AF_MULTI3_ZONE)||(zone==CAM_AF_MULTI5_ZONE))
	{
		/* Zone 1 */
		offsetX=(isp_preview_config_data.af_zone1_x - isp_preview_config_data.camera_offset_x)* isp_grab_width / isp_preview_config_data.target_width;
		offsetX-=(af_zone_width>>1);
		offsetY=(isp_preview_config_data.af_zone1_y - isp_preview_config_data.camera_offset_y)* isp_grab_height / isp_preview_config_data.target_height;
		offsetY-=(af_zone_height>>1);
		if((offsetX<0)||(offsetY<0)||((offsetX+af_zone_width)>isp_grab_width)||((offsetY+af_zone_height)>isp_grab_height))
		{
			af_zone_valid_flag = KAL_FALSE;
			af_window_config(2,isp_grab_width,isp_grab_height,0,0);
		}
		else
		{
			af_zone_valid_flag = KAL_TRUE;
			af_window_config(2,af_zone_width,af_zone_height,(kal_uint16)offsetX,(kal_uint16)offsetY);
		}
		/* Zone 2 */
		offsetX=(isp_preview_config_data.af_zone2_x - isp_preview_config_data.camera_offset_x)* isp_grab_width / isp_preview_config_data.target_width;
		offsetX-=(af_zone_width>>1);
		offsetY=(isp_preview_config_data.af_zone2_y - isp_preview_config_data.camera_offset_y)* isp_grab_height / isp_preview_config_data.target_height;
		offsetY-=(af_zone_height>>1);
		if((offsetX<0)||(offsetY<0)||((offsetX+af_zone_width)>isp_grab_width)||((offsetY+af_zone_height)>isp_grab_height))
		{
			af_zone_valid_flag = KAL_FALSE;
			af_window_config(3,isp_grab_width,isp_grab_height,0,0);
		}
		else
		{
			af_zone_valid_flag = KAL_TRUE;
			af_window_config(3,af_zone_width,af_zone_height,(kal_uint16)offsetX,(kal_uint16)offsetY);
		}
	}

	if(zone==CAM_AF_MULTI5_ZONE)
	{
		/* Zone 3 */
		offsetX=(isp_preview_config_data.af_zone3_x - isp_preview_config_data.camera_offset_x)* isp_grab_width / isp_preview_config_data.target_width;
		offsetX-=(af_zone_width>>1);
		offsetY=(isp_preview_config_data.af_zone3_y - isp_preview_config_data.camera_offset_y)* isp_grab_height / isp_preview_config_data.target_height;
		offsetY-=(af_zone_height>>1);
		if((offsetX<0)||(offsetY<0)||((offsetX+af_zone_width)>isp_grab_width)||((offsetY+af_zone_height)>isp_grab_height))
		{
			af_zone_valid_flag = KAL_FALSE;
			af_window_config(4,isp_grab_width,isp_grab_height,0,0);
		}
		else
		{
			af_zone_valid_flag = KAL_TRUE;
			af_window_config(4,af_zone_width,af_zone_height,(kal_uint16)offsetX,(kal_uint16)offsetY);
		}	
		/* Zone 4 */
		offsetX=(isp_preview_config_data.af_zone4_x - isp_preview_config_data.camera_offset_x)* isp_grab_width / isp_preview_config_data.target_width;
		offsetX-=(af_zone_width>>1);
		offsetY=(isp_preview_config_data.af_zone4_y - isp_preview_config_data.camera_offset_y)* isp_grab_height / isp_preview_config_data.target_height;
		offsetY-=(af_zone_height>>1);
		if((offsetX<0)||(offsetY<0)||((offsetX+af_zone_width)>isp_grab_width)||((offsetY+af_zone_height)>isp_grab_height))
		{
			af_zone_valid_flag = KAL_FALSE;
			af_window_config(5,isp_grab_width,isp_grab_height,0,0);
		}
		else
		{
			af_zone_valid_flag = KAL_TRUE;
			af_window_config(5,af_zone_width,af_zone_height,(kal_uint16)offsetX,(kal_uint16)offsetY);
		}
	}
}

void  AF_Backup_Model_setting(kal_bool flag)
{
	/* only backup auto defect & P_limit */
	if (KAL_TRUE == flag)/* backup */
	{
		af_bacup_p_limit = REG_ISP_PREPROCESS_CTRL1;
		af_backup_autodefect = REG_ISP_AUTO_DEFECT_CTRL1;
		af_backup_edge =REG_ISP_COLOR_PROCESS_STAGE_CTRL2;
		af_backup_LPF = REG_ISP_LPF_CTRL;
	}
	else/* restore */
	{
		af_bacup_p_limit &= REG_PREPROCESS1_PIXEL_LIMIT_MASK;
		REG_ISP_PREPROCESS_CTRL1 &= ~REG_PREPROCESS1_PIXEL_LIMIT_MASK;
		REG_ISP_PREPROCESS_CTRL1 |= af_bacup_p_limit;
		af_backup_autodefect &= 0xF8000000;
		REG_ISP_AUTO_DEFECT_CTRL1 &= ~0xF8000000;
		REG_ISP_AUTO_DEFECT_CTRL1 |= af_backup_autodefect;
		af_backup_edge &= REG_CPS2_RGB_EDGE_ENABLE_BIT;
		REG_ISP_COLOR_PROCESS_STAGE_CTRL2 &= ~REG_CPS2_RGB_EDGE_ENABLE_BIT;
		REG_ISP_COLOR_PROCESS_STAGE_CTRL2 |= af_backup_edge;
		af_backup_LPF &= (REG_LPF_Y_LPF_ENABLE_BIT|REG_LPF_C_LPF_ENABLE_BIT);
		REG_ISP_LPF_CTRL &= ~(REG_LPF_Y_LPF_ENABLE_BIT|REG_LPF_C_LPF_ENABLE_BIT);
		REG_ISP_LPF_CTRL |= af_backup_LPF;
	}
}

void af_trigger_setting(kal_uint8 trigger)
{
	while(lens_func->get_lens_af_status() == AF_STATUS_OPERATING){};
	
	if(lens_func->get_lens_af_status() == AF_STATUS_READY)
	{
		if((trigger==CAM_AF_ONE_TIME) || (trigger==CAM_AF_CONTINUE))
		{
			/* check af zone setting valid */
			if (af_zone_valid_flag == KAL_FALSE)
			{
				ASSERT(0);/* af zone init with incorrect region */
			}
			if (stack_query_boot_mode()!=FACTORY_BOOT)
			{
				AF_Backup_Model_setting(KAL_TRUE);/* backup preview setting */
			}
#if(defined(AF_Debug_Function))
			if (af_debug_flag == 1)
			{
				if (AF_130_all_enable == 0)//scan full
				{
					if (AF_Debug_Step_Dir == 0)//step + 1
					{	
						af_debug_pos=0;//debug 130 full scan
					}
					else//step - 1
					{
						af_debug_pos=AF_Debug_Max_Step;//debug 130 full scan		
					}
					lens_func->lens_af_move_to((kal_int32)af_debug_pos);
					AF_step_move_log((kal_int16)af_debug_pos);
				}
			}
			else
			{
#endif
				lens_func->lens_af_move_to((kal_int32)camera_lens_step.AF[af_table_search_end_idx].pos);
			AF_step_move_log((kal_int16)camera_lens_step.AF[af_table_search_end_idx].pos);
			dsc_status.af.index=af_table_search_end_idx;
#if(defined(AF_Debug_Function))				
			}			
#endif
		}
		else /* CAM_AF_RELEASE */
		{
			dsc_status.af.trigger = CAM_AF_RELEASE;/* set at first to prevent prempty by HISR */
			if (stack_query_boot_mode()!=FACTORY_BOOT)
			{
				AF_Backup_Model_setting(KAL_FALSE);/* restore preview setting */
			}
			/* reset to default range */
			if (dsc_status.af.mode==CAM_AF_INFINITE_MODE)
			{
				dsc_status.af.range=AF_INFINITE_RANGE;			
			}
			af_table_search_range_config(dsc_status.af.range);			
			lens_func->lens_af_move_to((kal_int32)camera_lens.INFO.af_hyper_pos);
			AF_step_move_log((kal_int16)camera_lens.INFO.af_hyper_pos);
			dsc_status.af.index=0xFF;
		}
	}
	if (cam_focus_cb==0x0)/* null callback of AF */
	{
		ASSERT(0);
	}
}

kal_uint8 get_af_table_index(kal_uint8 current_idx)
{
	kal_uint8 next_idx;
	if(current_idx < af_table_search_start_idx)
	{
		next_idx = AF_end_of_lut_search(af_table_search_start_idx, af_table_search_end_idx, current_idx);
		if (next_idx == af_table_search_start_idx)
		{
			af_operation_state=AF_SEARCH_STATE;
			next_idx = current_idx;
		}
		else
		{
			next_idx=current_idx+1;
		}
	}
	else if(current_idx==af_table_search_start_idx)
	{
		next_idx=af_table_search_start_idx;
		af_operation_state=AF_SEARCH_STATE;
	}
	else
	{
		next_idx=af_table_search_start_idx;
		ASSERT(0);
	}
	return next_idx;
}

kal_int32 get_af_detail_pos(kal_uint8 index)
{
	kal_uint8 af_id;
	af_id = AF_get_next_final_index(index);
	if (af_id == index)
	{
		af_operation_state=AF_SEARCH_STATE;
	}
	return AF_final_step_d[AF_small_check_count][af_id];
}

void af_table_search_range_config(kal_uint8 type)
{
	switch(type)
	{
		case AF_AUTO_RANGE:
			af_table_search_start_idx = af_oper_data.af_auto_range_start_idx;
			af_table_search_end_idx	= af_oper_data.af_auto_range_end_idx;
		break;
		case AF_NORMAL_RANGE:
			/* consistence between inf & normal range */			
			if (dsc_status.af.mode==CAM_AF_INFINITE_MODE)
			{
				af_table_search_end_idx	= af_oper_data.af_infinite_range_start_idx+1;
			}
			else
			{
				af_table_search_end_idx	= af_oper_data.af_normal_range_end_idx;
			}			
			af_table_search_start_idx = af_oper_data.af_normal_range_start_idx;
		break;
		case AF_MACRO_RANGE:
			af_table_search_start_idx = af_oper_data.af_macro_range_start_idx;
			af_table_search_end_idx	= af_oper_data.af_macro_range_end_idx;
		break;
		case AF_INFINITE_RANGE:
			af_table_search_start_idx = af_oper_data.af_infinite_range_start_idx;
			af_table_search_end_idx	= af_oper_data.af_infinite_range_end_idx;
		break;		
	}
}

void manual_focus_setting(kal_uint8 dir)
{
	if(dsc_status.af.mode==CAM_AF_MANUAL_MODE)
	{
		if(dir == CAM_FOCUS_FORWARD)
			lens_func->lens_af_step_cw(af_oper_data.manual_focus_step);
		else if(dir == CAM_FOCUS_BACKWARD)
			lens_func->lens_af_step_ccw(af_oper_data.manual_focus_step);
	}
	else
	{
		ASSERT(0);
	}
}
#endif  /* AF_SUPPORT*/
#endif /* (YUV_SENSOR_SUPPORT) */
#endif /* ISP_SUPPORT && (MT6226||MT6227||MT6228||MT6229) */
