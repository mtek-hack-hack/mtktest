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
 *   af.h
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
#ifndef _AF_H
#define _AF_H

#include "drv_features.h" 
#if (!defined(DRV_ISP_6219_SERIES))

#define	AF_WINDOW_W			80
#define	AF_WINDOW_H			80

/* window no */
#define	AF_WIND_NO			5//ISP support window no
/* step no */
#define	MAX_STEP_NO			24//total LUT steps can not over this no
/* peak search */
#define	AF_PARA_SHIFT		7//divided by 128
#define	AF_PARA_ROUND		64//add before shift to prevent round off error
#define	AF_FV_UINTY			128//unity with 128
/* AF result err no */
/* peak search */
#define	AF_PEAK_ERR_OK		0
#define	AF_PEAK_ERR_1		1//peak by boundary for macro
#define	AF_PEAK_ERR_2		2//peak by boundary for inf
#define	AF_PEAK_CLOSER_1	3//found closer condition 1 with i
#define	AF_PEAK_CLOSER_2	4//found closer condition 2 with i+1
#define	AF_PEAK_ERR_3		5//low contrast
#define	AF_PEAK_NULL		255//null result to be assert
/* 2nd order curve */
#define	AF_POLY_ERR_OK		0
#define	AF_POLY_ERR_1		1//fail to find denom for 2x2 inverse by curve fitting
#define	AF_POLY_ERR_2		2//fail to find local max, am*dm with wrong sign
#define	AF_POLY_ERR_3		3//sample no less than curve max
#define	AF_POLY_MACRO		4//boundary peak condition w/o curve fitting, macro
#define	AF_POLY_ERR_5		5//fail to find local max, out of range, macro side
#define	AF_POLY_ERR_6		6//fail to find local max, out of range, inf side
#define	AF_POLY_CLOSER_1	7//found closer condition w/o curve fitting
#define	AF_POLY_CLOSER_2	8//found closer condition w/o curve fitting
#define	AF_POLY_INF			9//boundary peak condition w/o curve fitting, inf
#define	AF_POLY_ERR_7		10//low contrast in peak search w/o curve fitting
/* second check */
#define	AF_CHECK_ERR_OK	0
#define	AF_CHECK_ERR_1		1//fail to final local max, error of denom for 2x2 inverse by final check, peak by step i
#define	AF_CHECK_ERR_2		2//fail to final local max, error of denom for 2x2 inverse by final check, out of check range to step i-1 side
#define	AF_CHECK_ERR_3		3//fail to final local max, error of denom for 2x2 inverse by final check, out of check range to step i+1 side
#define	AF_CHECK_ERR_4		4//fail to find local max, am*dm with wrong sign, peak by step i
#define	AF_CHECK_ERR_5		5//fail to find local max, am*dm with wrong sign, out of check range to step i-1 side
#define	AF_CHECK_ERR_6		6//fail to find local max, am*dm with wrong sign, out of check range to step i+1 side
#define	AF_CHECK_ERR_7		7//fail to find local max by final check, out of check range to step i-1 side
#define	AF_CHECK_ERR_8		8//fail to find local max by final check, out of check range to step i+1 side
#define	AF_CHECK_ERR_9		9//fail to find local max by final check, out of ovearll scan range, macro
#define	AF_CHECK_ERR_10	10//fail to find local max by final check, out of overall scan range, inf
#define	AF_CHECK_ERR_11	11//fail w/o final check by peak search error
#define	AF_CHECK_ERR_12	12//unselected window w/o focus
#define	AF_CHECK_ERR_13	13//selected but non-interesting window
#define	AF_CHECK_NULL		255//null result to be assert
/* check final result */
#define	AF_CHECK_COUNT		3
#define	AF_CHECK_COUNT_D	10
/* system clk */
#define	AF_SYSTEM_TIME		*((volatile unsigned int *) (0x80200230))
#define	AF_STEP_TIME_NO	12
#define	AF_STEP_NO			32

typedef enum
{
	AF_IDLE_STATE=0,
	AF_STANDBY_STATE,
	AF_COLLECT_STATE,
	AF_SEARCH_STATE,
	AF_FREEZE_STATE
} AF_OPERATION_STATE_ENUM;

typedef enum
{
	AF_AUTO_RANGE=0,
	AF_NORMAL_RANGE,
	AF_MACRO_RANGE,
	AF_INFINITE_RANGE
}AF_SEARCH_RANGE_ENUM;

typedef enum
{
	AF_SUCCESS=0,
	AF_TABLE_SEARCH_SUCCESS,
	AF_TABLE_SEARCH_FAIL,
	AF_DETAIL_SEARCH_FAIL,
	AF_DETAIL_SEARCH_EDGE_FAIL
}AF_RESULT_ENUM;

typedef struct
{
	AF_RESULT_ENUM	result;
	kal_uint16		best_step;
	kal_uint16		success_zone;
}af_result_struct;

typedef struct
{
	kal_uint16	AF_peak_no;//peak search no
	kal_uint16	AF_peak_setp;//peak search step
	kal_uint16	AF_search_no;//curve fitting no
	kal_int16		AF_search_step;//curve fitting step
	kal_uint8		AF_peak_result;//peak search error message
	kal_uint8		AF_curve_result;//curve fitting error message
	kal_uint32	AF_mz_FV;//peak search FV for multi-zone with overall weighting
	kal_uint8		AF_mz_no;//zone number for multi-zone
	kal_uint8		AF_DOF_start;//start index of peak
	kal_uint8		AF_DOF_end;//end index of peak
} AF_search_struct;

typedef struct
{
	kal_uint8		manual_focus_step;
	kal_uint8		af_auto_range_start_idx;
	kal_uint8		af_auto_range_end_idx;
	kal_uint8		af_normal_range_start_idx;
	kal_uint8		af_normal_range_end_idx;
	kal_uint8		af_macro_range_start_idx;
	kal_uint8		af_macro_range_end_idx;
	kal_uint8		af_infinite_range_start_idx;
	kal_uint8		af_infinite_range_end_idx;
	kal_uint16	auto_peak_select_min_fv_ratio_diff;
	kal_uint16	auto_peak_select_min_up_fv_th;
	kal_uint16	auto_peak_select_max_dn_fv_th;
	kal_uint16	auto_multi_zone_min_fv_ratio;
	kal_uint16	macro_peak_select_min_fv_ratio_diff;
	kal_uint16	macro_peak_select_min_up_fv_th;
	kal_uint16	macro_peak_select_max_dn_fv_th;
	kal_uint16	macro_multi_zone_min_fv_ratio;
	kal_uint16	infi_peak_select_min_fv_ratio_diff;
	kal_uint16	infi_peak_select_min_up_fv_th;
	kal_uint16	infi_peak_select_max_dn_fv_th;
	kal_uint16	infi_multi_zone_min_fv_ratio;
	kal_uint16	lowlight_peak_select_min_fv_ratio_diff;
	kal_uint16	lowlight_peak_select_min_up_fv_th;
	kal_uint16	lowlight_peak_select_max_dn_fv_th;
	kal_uint16	lowlight_multi_zone_min_fv_ratio;

	kal_uint16	AF_Scaling_Ratio;
	kal_uint16	AF_DF_r;
	/* low contrast check */
	kal_uint16	AF_LC_p;
	kal_uint16	AF_LC_a;
	kal_uint16	AF_LC_v;
	kal_uint16	AF_LC_m;
	kal_uint16	AF_LC_w;
	/* threshold divided by 128*/
	kal_uint16	AF_Gr_1;
	kal_uint16	AF_Gr_2;
	kal_uint16	AF_Gd_u;
	kal_uint16	AF_Gd_d;
	kal_uint16	AF_Gu_r;
	kal_uint16	AF_Gd_r;
	/* closer search */
	kal_uint16	AF_Cr_n;
	kal_uint16	AF_Cr_1;
	kal_uint16	AF_Cr_mr;
	kal_uint16	AF_Cr_dr;
	kal_uint16	AF_Cr_ur;
	/* AF contrast min FV */
	kal_uint32	AF_step_FV;
	kal_uint32	AF_noise_FV;
	kal_uint32	AF_min_FV;
	kal_uint32	AF_mid_FV;
	kal_uint32	AF_max_FV;
	/* general threshold*/
	kal_uint16	AF_FC_fmin;
	kal_uint16	AF_Gr_fm;
	kal_uint16	AF_Cr_ft;
	kal_uint16	AF_Cr_fd;
	/*search distance*/
	kal_uint8		AF_Normal_Dist;
	kal_uint8		AF_Inf_Dist;
	kal_uint8		AF_Macro_Dist;
	kal_uint8		AF_Closer_Dist;	
	/*speed up threshod*/
	kal_uint16	AF_Fast_Th_S;
	kal_uint16	AF_Fast_Th_E;
	kal_uint16	AF_LUT_min_diff_FV;
	kal_uint8		AF_LUT_min_count;
	/*step time optimize*/
	kal_uint8		AF_count_max;
	kal_uint8		AF_count_max_no;
	kal_uint8		AF_count_release;
	kal_uint8		AF_count_min;
	/*slow back*/
	kal_uint8		AF_slow_max_step;
	kal_uint8		AF_small_check_max;
	/*small search para*/
	kal_uint8		AF_detail_Rbound[2];
	kal_uint8		AF_detail_Lbound[2];
	kal_uint8		AF_detail_RC[2];
	kal_uint8		AF_detail_LC[2];
	/*speed up for small research*/
	kal_uint8		AF_shift_count;
	kal_uint8		AF_detail_shift;
	kal_bool		AF_invese_step;
	kal_uint16	AF_max_r[2];
	kal_uint16	AF_min_r[2];
	kal_bool		AF_search_dir[2];
	kal_uint8		AF_min_count[2];
	kal_uint8		AF_mini_step;
	kal_uint16	AF_parse_R;
	kal_uint16	AF_parse_L;
	kal_uint8		AF_parse_C;	
	/* window value for speed up */
	kal_uint8		AF_step_win_m0;//single or three window setting
	kal_uint8		AF_step_win_n0;//must <= 8
	kal_uint8		AF_step_win_m1;//5 zone window setting
	kal_uint8		AF_step_win_n1;//must <= 8
	/* closer check enable */
	kal_bool		AF_closer_enable;
   /* AF window shift */
   kal_uint8	AF_wind_y_delay;
   kal_uint8	AF_wind_y_delay_count;		
	kal_uint8 	AF_inv_delay;//delay for detail search start
	/* AF speed up with boundary */
	kal_int16		AF_boundary_macro;
	kal_int16		AF_boundary_inf;
}af_operation_para_struct;

typedef struct {
	kal_uint32	step;	
	kal_uint32	tick;
} af_timing_struct;

typedef struct {
	kal_uint32	pos;	
	kal_uint32	distance;
} af_step_struct;

typedef struct
{
   	kal_uint32		Step_no;
	af_step_struct		AF[AF_STEP_NO];	
}camera_lens_run_struct;


typedef struct
{
   	kal_uint32		Step_no;
   	kal_uint32		Max_frame_delay;
	af_timing_struct	Tick[AF_STEP_TIME_NO];	
}camera_lens_timing_struct;

extern af_operation_para_struct     *p_af_oper_data;
extern camera_lens_run_struct	    *p_camera_lens_step;
extern camera_lens_timing_struct    *p_camera_lens_timing;

extern AF_OPERATION_STATE_ENUM af_operation_state;
extern kal_bool  	af_detail_search;
extern kal_uint8 	af_table_search_start_idx;
extern kal_uint8 	af_table_search_end_idx;
extern kal_uint32	AF_focus_result[AF_WIND_NO][MAX_STEP_NO];
extern af_result_struct af_result;//af result

#if (defined(AF_SUPPORT))
extern af_operation_para_struct af_oper_data;
extern kal_bool	af_cal_complete;
extern kal_uint8	af_fail_count;
extern kal_uint8	af_detail_idx;
extern kal_int16	AF_final_step[AF_CHECK_COUNT];
extern kal_uint32	AF_final_result[AF_WIND_NO][AF_CHECK_COUNT];
extern kal_int16	AF_final_step_d[2][AF_CHECK_COUNT_D];
extern kal_uint32	AF_final_result_d[2][AF_WIND_NO][AF_CHECK_COUNT_D];
extern kal_uint32	AF_Result0,AF_Result1,AF_Result2,AF_Result3,AF_Result4;
extern kal_uint8 	AF_mz_win;//selected multi-zone window no
extern kal_uint8 	AF_start_idx;
extern kal_uint8 	AF_end_idx;
extern kal_int16 	AF_best_step[AF_WIND_NO];
extern kal_uint8 	AF_best_result[AF_WIND_NO];
extern AF_search_struct AF_result_p[AF_WIND_NO];
extern kal_uint8 	AF_mz_report[AF_WIND_NO+1];
extern kal_uint8 	af_check_FV;//slow down count
extern kal_uint8 	AF_small_check_count;//0: first detail parse, 1: second detail parse
/* protect no release before key press */
extern kal_uint8 	AF_release_delay;
/* AF customization */
extern camera_lens_run_struct	 camera_lens_step;
extern camera_lens_timing_struct camera_lens_timing;
/* AF stable inv step */
extern kal_int8	af_dir_inv_delay_count;

af_result_struct af_proc(void);
void af_main(void);
void init_af(void);
void af_custom_para_first_init(af_operation_para_struct *custom_para);
void get_af_info(kal_uint8 index);
void get_af_detail_info(kal_uint8 index);
void af_table_search_range_config(kal_uint8 type);
void af_window_config(kal_uint8 no,kal_uint16 Hsize,kal_uint16 Vsize,kal_uint16 Hoffset,kal_uint16 Voffset);
void af_trigger_setting(kal_uint8 trigger);
void set_af_proc_para(kal_uint8 mode, kal_bool lowlight);
void af_zone_setting(kal_uint8 zone);
void manual_focus_setting(kal_uint8 dir);
kal_uint8 get_af_table_index(kal_uint8 current_idx);
kal_int32 get_af_detail_pos(kal_uint8 index);
kal_uint8 AF_end_of_lut_search(kal_uint8 start_i, kal_uint8 end_i, kal_uint8 current_i);
kal_bool AF_check_AF_count(kal_uint8 AF_CC);
kal_uint8 AF_get_next_final_index(kal_uint8 index);
void AF_init_step_time_lut(void);
void AF_step_move_log(kal_int16 cstep);
void AF_frame_VD_log(void);
kal_bool get_focus_step(kal_uint32 *total_step,kal_uint32 *current_step);
void AF_step_move_slow(kal_int16 cstep);
kal_uint8	AF_af_detail_idx_update(kal_uint8 af_detail_idx_cc);
kal_uint8 AF_slow_back_check(kal_uint8 af_check_temp);
void AF_Set_Min_Step(kal_uint8 min_step);
void AF_Backup_Normal_Step(void);
void AF_Recover_Min_Step(void);

/* AF debug function */
#define	AF_Debug_Step_Dir		0//0:scasn from inf to macro, 1:scan from macro to inf
#define	AF_Debug_Max_Step		130//max step for debug scan, minimum step default=0
#define	AF_Debug_Scan_Step	1//step interval for -24~+25
#if(defined(AF_Debug_Function))
extern 	kal_uint8 	AF_130_all_enable;
extern 	kal_int16 	af_debug_pos;
extern 	kal_int16 	af_debug_best_pos;
extern 	kal_uint8 	af_debug_flag;
extern 	kal_uint32 	AF_debug_focus_result[AF_Debug_Max_Step+1];

typedef enum
{
	AF_Debug_Flag_Normal=0,
	AF_Debug_Flag_FullScan,
	AF_Debug_Flag_Continue,
	AF_Debug_Flag_No
} AF_DEBUG_MODE_ENUM;

void AF_Debug_Flag_Update(AF_DEBUG_MODE_ENUM AF_Debug_Para);
void	AF_debug_scan(void);
#endif  // AF_Debug_Function

#endif /* AF_SUPPORT */
#endif /* _AF_H */
#endif /* !MT6219 */
