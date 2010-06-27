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
 *   isp_cct_if.h
 *
 * Project:
 * --------
 *   MT6219,MT6226,MT6227,MT6228,MT6229
 *
 * Description:
 * ------------
 *   These are interface with FT for CCT
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
 ****************************************************************************/
#ifndef _ISP_CCT_IF_H
#define _ISP_CCT_IF_H

#include "drv_features.h" 
#if (defined(ISP_SUPPORT))

enum
{
	CAPTRUE_MODE_RAW_8BIT = 0,		// RAW, 8Bit, capture to internal ram
	CAPTRUE_MODE_YUV,				// YUV, capture to internal ram
	CAPTRUE_MODE_RAW_10BIT,			// RAW, 10Bit, capture to internal ram
	CAPTRUE_MODE_RGB888,			// RGB888, capture to internal ram
	CAPTRUE_MODE_RGB565,			// RGB565, capture to internal ram
	CAPTRUE_MODE_EXT_RAW_8BIT,      // RAW, 8Bit, capture to external ram
	CAPTRUE_MODE_EXT_RAW_10BIT,		// RAW, 10Bit, capture to external ram	
	CAPTRUE_MODE_EXT_YUV,			// YUV, capture to external ram
	CAPTRUE_MODE_EXT_RGB888,		// RGB888, capture to external ram
	CAPTRUE_MODE_EXT_RGB565,		// RGB565, capture to external ram
	CAPTRUE_MODE_JPEG		    	// JPEG capture
};

typedef struct
{
    kal_int16   grab_start_x;		/* the image startgrab x */       
    kal_int16   grab_start_y;       /* the image startgrab y */  
    kal_int16   grab_width;         /* the image width */  
    kal_int16   grab_height;        /* the image height */  
    kal_uint8   sub_sample_mode;    /* the image sub_sample_mode */ 
    kal_uint8   debug_mode;         /* output image format */ 
    kal_uint32  isp_debug_buffer;   /* output image buffer address */ 
    kal_uint8   flash_mode;         /* flash mode: CAM_FLASH_OFF, CAM_FLASH_ON */
    kal_uint16  curr_lum;           /* adjust flash param(flash_mode==CAM_FLASH_ON only), 0xFFFF, stop adjust*/
    kal_uint16  target_lum;         /* adjust flash param(flash_mode==CAM_FLASH_ON only)*/
} camera_capture_cct_struct;

typedef struct
{
	kal_uint8 SHADING_RANGE_EN;
	kal_uint8 SHADING_EN;
	kal_uint8 K_FACTOR;
	kal_uint8 RADIUS_FACTOR;
	kal_uint16 SHADING_CENTERX;
	kal_uint16 SHADING_CENTERY;
	kal_uint8 SHADING_RANGE_HI;
	kal_uint8 SHADING_RANGE_LO;
	kal_uint8 SHADING_KR;
	kal_uint8 SHADING_KG;
	kal_uint8 SHADING_KB;
	kal_uint8 SHADING_CURVE_EN;
	kal_uint8 SHADING_CURVE_SEL;
	kal_uint8 SHADING_GAMMA[3][11];
}cct_shading_comp_struct;

typedef struct
{
	kal_uint8 ADC_EN;
	kal_uint8 ADL_EN;
	kal_uint8 ADR_EN;
	kal_uint8 ADU_EN;
	kal_uint8 ADD_EN;
	kal_uint8	DEADCHECK;
	kal_uint8	BRIGHTTHD;
	kal_uint8	BLACKTHD;
	kal_uint8 GCHECKTHD;
	kal_uint8 RBCHECKTHD;
	kal_uint8 GCORRECTTHD;
	kal_uint8 RBCORRECTTHD;	
}cct_autodefect_comp_struct;

void init_camera_cct(kal_uint32 cct_lcd_layer0_buffer);
void camera_preview_cct(camera_preview_process_struct *isp_cct_data);
kal_uint8 camera_capture_cct(camera_capture_cct_struct *isp_cct_data);

void exit_camera_preview_cct(void);
void recover_sensor_setting(void);
void get_banding_factor(kal_uint8 *baseshutter_60hz,kal_uint8 *baseshutter_50hz);

kal_uint32  isp_cct_get_isp_id(void);
kal_bool  isp_cct_is_gamma_table_supported(void);
void isp_cct_set_gamma_table(const kal_uint8 gamma_table[1024]);
void isp_cct_get_gamma_table(kal_uint8 gamma_table[1024]);

/* different register setting for shading & autodefect */
kal_bool  isp_cct_is_shading_supported(void);
kal_bool  isp_cct_is_capmode_supported(kal_uint8    mode);
void get_camera_shading_set(cct_shading_comp_struct *p_cam_addr, camera_comp_set_num p_set_mode);/* read from global variable */
void set_camera_shading_set(const cct_shading_comp_struct *p_cam_addr, camera_comp_set_num p_set_mode);/* write to global variable */
kal_bool  isp_cct_is_autodefect_supported(void);
void get_camera_autodefect_set(cct_autodefect_comp_struct *p_cam_addr, camera_comp_set_num p_set_mode);/* read from global variable */
void set_camera_autodefect_set(const cct_autodefect_comp_struct *p_cam_addr, camera_comp_set_num p_set_mode);/* write to global variable */

void cct_apply_camera_shading_to_reg(camera_comp_set_num p_set_mode);/* apply global variable to reg */
void cct_update_camera_shading_from_reg(camera_comp_set_num p_set_mode);/* apply reg to global variable */
void cct_apply_camera_autodefect_to_reg(camera_comp_set_num p_set_mode);/* apply global variable to reg */
void cct_update_camera_autodefect_from_reg(camera_comp_set_num p_set_mode);/* apply reg to global variable */

kal_bool  isp_cct_is_defect_table_supported(void);
kal_bool  isp_cct_is_autodefct_count_supported(void);
kal_uint16  cct_read_autodefct_count(void);

kal_uint16  isp_cct_is_cct_af_support(void);
kal_bool cct_defect_table_on_off(kal_bool set_flag);
void cct_camera_operation_setting(kal_uint8 func_sel, kal_uint16 para);
kal_bool cct_backup_bypass_pre_adjust(void);
kal_bool cct_recover_pre_adjust(void);

kal_bool  cct_get_isp_gamma1024_ONOFF(void);
kal_bool  cct_set_isp_gamma1024_ONOFF(kal_bool gamma_flag);
kal_bool  cct_get_isp_gamma_ONOFF(void);
void  cct_set_isp_gamma_ONOFF(kal_bool gamma_flag);

kal_bool  isp_cct_is_iso_priority_supported(void);
kal_bool cct_iso_set_gain(const kal_uint16 gain[3]);
kal_bool cct_iso_get_gain(kal_uint16 gain[3]); 
kal_bool cct_iso_set_value(const kal_uint16 value[3]);
kal_bool cct_iso_get_value(kal_uint16 value[3]); 
#endif /* _ISP_CCT_IF_H */
#endif /* MT6219||MT6228||MT6226||MT6227||MT6229 */


