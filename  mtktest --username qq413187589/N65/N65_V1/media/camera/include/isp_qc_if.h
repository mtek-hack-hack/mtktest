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
 *   isp_qc_if.h
 *
 * Project:
 * --------
 *   MT6226,MT6227,MT6228,MT6229,MT6230
 *
 * Description:
 * ------------
 *   These are interface with FT for COQC/CIQC Tool
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
 
#ifndef _ISP_QC_IF_H
#define _ISP_QC_IF_H

#include "drv_features.h"
#include "isp_cct_if.h"

/*************************************************
 * Defect Table Interface 	
 **************************************************/
#if (defined(DRV_ISP_6219_SERIES))
#define	GRAB_INTERPO_WIDTH_PIXEL		(4)
#define	GRAB_INTERPO_HEIGHT_PIXEL		(2)
#elif (defined(DRV_ISP_6227_SERIES))
#define	GRAB_INTERPO_WIDTH_PIXEL		(4)
#define	GRAB_INTERPO_HEIGHT_PIXEL		(4)
#elif (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
#define	GRAB_INTERPO_WIDTH_PIXEL		(6)
#define	GRAB_INTERPO_HEIGHT_PIXEL		(6)
#endif

/* DEFECT PIXEL*/
#define	DEFECT_MAX_SEARCH_NUM			(1024)
#define	DEFECT_MAX_BLOACK_PER_ROW		(32)	// 3M=2048*1536, 2048/32=64, so, min block width=64

#define	ERR_OVER_MAX_SEARCH_NUM			(-1)
#define	ERR_OVER_MAX_DEFECT_NUM			(-2)

#define	ERR_STATE_INIT_PROCESS			(-3)
#define	ERR_STATE_UNDER_PROCESSING		(-4)
#define	ERR_STATE_UNKNOWN_MODE			(-5)

#define	ERR_PARA_SIZE_NOT_ALIGN			(-10)
#define	ERR_PARA_SIZE_OVER_MEM			(-11)
#define	ERR_PARA_SIZE_OVER_BLOCK		(-12)

/* Error Message for OQC AF offset calibration */
#define AFCAL_PASS							(0)		//Cal OK
#define AFCAL_NO_REFERENCE_TABLE			(1)		//TABLE without same distance for calibration	
#define AFCAL_PREVIEW_OFF					(2)		//Preview didn't turn ON
#define AFCAL_AE_NOT_OFF					(3)		//AF invalid sence mode
#define AFCAL_AWB_NOT_OFF					(4)		//AF invalid sence mode
#define AFCAL_AF_INVALID_MODE				(5)		//AF invalid sence mode
#define AFCAL_AF_NOT_READY					(6)		//AF not ready
#define AFCAL_FOCUS_FAIL					(7)		//AF Fail
#define AFCAL_FOCUS_TIME_OUT				(8)		//AF time out
#define AFCAL_OFFSET_TOOL_LARGE			(9)		//OFFSET over max bound
#define AFCAL_OFFSET_TOOL_SMALL			(10)		//OFFSET under min bound
#define AFCAL_OFFSET_OVER_LENGTH			(11)		//OFFSET over storage bound
#define AFCAL_OFFSET_UNDER_LENGTH		(12)		//OFFSET under storage bound
#define AFCAL_AF_NOT_SUPPORT				(0xFF)	//AF not support

/* Other AF calibration definition */
#define AFCAL_AF_MAX_TIME					(0x40000)//max tick by 32K timer
#define AFCAL_AF_LOOP_DELAY				(100)		//loop check delay by ms

typedef enum
{
	DEFECT_INIT_STATE=0,
	DEFECT_START_STATE,
	DEFECT_PROCESS_STATE,
	DEFECT_FINISH_STATE	
}DEFECT_OPERATION_STATE_ENUM;

enum
{
	DEFECT_MODE_NONE = 0,
	DEFECT_MODE_CAPTURE,
	DEFECT_MODE_PREVIEW,	
	DEFECT_MODE_BOTH
};

enum
{
	DEFECT_AREA_AVG=1,
	DEFECT_AREA_CENTER_PRI
};

enum
{
	DEFECT_AREA_1=1,
	DEFECT_AREA_2
};

enum
{
	DEFECT_TYPE_BLACK_PIXEL=1,
	DEFECT_TYPE_WHITE_PIXEL		
};

enum
{
	DEFECT_TYPE_BLACK_PIXEL_ONLY=1,
	DEFECT_TYPE_WHITE_PIXEL_ONLY,		
	DEFECT_TYPE_BOTH_BW,		
	DEFECT_TYPE_BOTH_WB			
};

typedef struct
{
	kal_uint8	search_mode_select;	/* Area1 or Avg. priority*/
	kal_uint8	defect_type;			/* Black or white */	
	kal_uint8	defect_type_select;	/* Black only or white only or B&W or W&B */
	kal_uint8	threshold_area1;		/* threshold condition for area 1*/
	kal_uint8	threshold_area2;		/* threshold condition for area 2*/
	kal_uint16	image_width;			/* image width */
	kal_uint16	image_height;			/* image height */
	kal_uint16	block_width_factor;	/* block width factor */
	kal_uint16	block_height_factor;	/* block height factor */
	kal_uint16	boarder_len;			/* boarder length */
	kal_uint16	max_defect_num;		/* max defect pixel limit */
	kal_uint16	max_search_num;		/* max search pixel limit */
} defectpixel_para_struct;

typedef struct
{
	kal_uint8	area_id;
	kal_uint8	pixel_diff;		
	kal_uint16	pos_x;
	kal_uint16	pos_y;
} defectpixel_pixel_struct;

typedef struct
{
	kal_uint16	defect_num;				/* defect pixel found */
	kal_uint16	search_num;				/* searched pixel */	
	defectpixel_pixel_struct	pixel_list[256];
} defectpixel_result_struct;

typedef struct
{
	kal_uint32 AF_cal_distance;	//calibration chart distance, 2.5M=250
	kal_uint32 AF_table_step;		//if table with same distance, fill in table step
	kal_uint16 AF_cal_step;			//if AF OK, calibrated step will fill in
	kal_uint32 AF_max_tol;			//if cal_step>AF_table_step+AF_max_tol, report over max tol
	kal_uint32 AF_min_tol;			//if cal_step<AF_table_step-AF_min_tol, report under min tol
	kal_uint8 AF_min_step_tol;		//precision of minimum step
}AF_OQC_cal_struct;

#if (defined(ISP_SUPPORT)&&(!defined(DRV_ISP_6225_SERIES))&&(!defined(DRV_ISP_6219_SERIES)))
extern defectpixel_para_struct defectpixel_data;

void reset_camera_defectpixel(kal_uint8	defect_mode);
kal_int32 camera_defectpixel_verify_block_factor(const kal_uint32  isp_debug_buffer_size, defectpixel_para_struct *defect_data);
kal_int32 camera_defectpixel_process(	kal_uint8	defect_mode, defectpixel_para_struct *defect_data, kal_uint32 	isp_debug_buffer, kal_uint32 isp_debug_buffer_size);
kal_int32 get_defectpixel_info(kal_uint8 defect_mode, defectpixel_para_struct **defect_data, defectpixel_result_struct **defect_result);

void copy_calibration_result_to_camera_defect(nvram_camera_defect_struct *p_cam_defect);
void pixellist_to_camera_defect(kal_uint8 defect_mode, const defectpixel_result_struct *defect_result, nvram_camera_defect_struct *p_cam_defect);
void camera_defect_to_pixellist(kal_uint8 defect_mode, const nvram_camera_defect_struct *p_cam_defect, defectpixel_result_struct *defect_result);

kal_uint8 camera_af_lens_offset_cal(AF_OQC_cal_struct *AF_cal_in);
void camera_af_Lens_offset_cal_hisr_done(void);

#endif  // #if (defined(ISP_SUPPORT)&&(!defined(DRV_ISP_6225_SERIES))&&(!defined(DRV_ISP_6219_SERIES)))
#endif  // _ISP_QC_IF_H
