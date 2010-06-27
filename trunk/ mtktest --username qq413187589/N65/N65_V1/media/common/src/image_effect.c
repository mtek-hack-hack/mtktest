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
 *   image_effect.c
 *
 * Project:
 * --------
 *   MT6219,MT6226,MT6227,MT6228,MT6229,MT6230
 *
 * Description:
 * ------------
 *   This driver provides two categories effects which are special
 *   effect and adjustment effect.
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
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
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if (defined(ISP_SUPPORT)&&(!defined(MT6225)))
#include "drv_comm.h"
#include "visualhisr.h"
#include "visual_comm.h"
#include "isp_if.h"
#include "imgproc.h"
#include "resizer.h"
#include "imgdma.h"
#include "camera_para.h"
#include "image_effect.h"
#include "med_api.h"
#include "kal_release.h"
#include "jpeg.h"
#include "img_comm.h"

kal_uint8 image_effect_enc;
IMAGE_EFFECT_DEC_STRUCT	image_effect_dec_para;
IMAGE_EFFECT_DEC_STRUCT	image_adj_dec_para;
#if (defined(MT6219)||defined(MT6226)||defined(MT6226M)||defined(MT6226D)||defined(MT6227)||defined(MT6227D))
IMGDMA_IBW1_STRUCT ibw1_para;
IMGDMA_IBR1_STRUCT ibr1_para;
#endif
#if (defined(MT6228)||defined(MT6229)||defined(MT6230))
ipp_effect_struct ipp_config_data;
#endif
volatile kal_uint8 IBW1_COMPLETE_FLAG=0;

const kal_uint8 sine[91]={	 0, 1, 2, 3, 4, 6, 7, 8, 9,10,
									11,12,13,14,15,17,18,19,20,21,
									22,23,24,25,26,27,28,29,30,31,
									32,33,34,35,36,37,38,39,39,40,
									41,42,43,44,44,45,46,47,48,48,
									49,50,50,51,52,52,53,54,54,55,
									55,56,57,57,58,58,58,59,59,60,
									60,61,61,61,62,62,62,62,63,63,
									63,63,63,64,64,64,64,64,64,64,
									64};

const kal_uint8 gamma[9][17]={ {0,25, 9,7,5,5, 5, 4, 3,50,18,14,10,10,10, 8, 7},
										 {0,22,10,7,6,5, 5, 4, 4,44,20,14,12,10,10, 8, 9},
										 {0,18,10,7,7,6, 6, 5, 4,36,20,14,14,12,12,10, 9},
										 {0,12, 9,8,8,7, 7, 6, 6,24,18,16,16,14,14,12,14},
										 {0, 8, 8,8,8,8, 8, 8, 7,16,16,16,16,16,16,16,16},
										 {1, 5, 7,8,8,9, 8,10, 8,10,14,16,16,18,16,20,18},
										 {1, 3, 5,7,8,9,10,11,10, 6,10,14,16,18,20,22,23},
										 {1, 2, 3,6,8,9,11,12,12, 4, 6,12,16,18,22,24,27},
										 {1, 1, 3,5,7,9,12,13,13, 2, 6,10,14,18,24,26,30}};

const kal_uint8 coloradj_rb[9][7]={ {8, 3,16,16, 6,16,27},
												{8, 4,16,16, 8,16,25},
												{8, 6,16,16,12,16,21},
												{8, 7,16,16,14,16,19},
												{8, 8,16,16,16,16,16},
												{8,10,16,16,20,16,11},
												{8,12,16,16,23,16, 8},
												{8,13,16,16,26,16, 5},
												{8,14,16,16,28,16, 2}};

const kal_uint8 coloradj_g[9][7]={ 	{16, 6,32,32, 6,16,26},
												{16, 8,32,32, 8,16,25},
												{16,12,32,32,12,16,20},
												{16,14,32,32,14,16,19},
												{16,16,32,32,16,16,16},
												{16,20,32,32,20,16,12},
												{16,23,32,32,23,16, 8},
												{16,26,32,32,26,16, 6},
												{16,28,32,32,28,16, 3}};

/*************************************************************************
* FUNCTION
*	image_effect_enc_process
*
* DESCRIPTION
*	This function process special effect in PREVIEW, CAPTURE and MPEG4
*	ENCODE mode.
*
* PARAMETERS
*	effect_enc	:	one of the image effect enum
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void image_effect_enc_process(kal_uint8 effect_enc)
{
	effect_enc_normal();
	image_effect_enc=effect_enc;
	image_effect_enc_handler();
}

/*************************************************************************
* FUNCTION
*	image_effect_dec_process
*
* DESCRIPTION
*	This function provides special effect in VIDEO PLAYBACK,
*	IMAGE PLAYBACK and POST-PORCESSING mode.
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
void image_effect_dec_process(IMAGE_EFFECT_DEC_STRUCT *effect_dec_para)
{
#if (defined(MT6219)||defined(MT6226)||defined(MT6226M)||defined(MT6226D)||defined(MT6227)||defined(MT6227D))
	RESZ_CFG_STRUCT rez_cfg;
	RESZ_PXL_CFG_STRUCT rez_pxl_cfg;
	kal_uint16 src_width, src_height, target_width, target_height;

	image_effect_dec_para.data_type=effect_dec_para->data_type;
	image_effect_dec_para.data_order=effect_dec_para->data_order;
	image_effect_dec_para.source_buffer_address=effect_dec_para->source_buffer_address;
	image_effect_dec_para.dest1_buffer_address=effect_dec_para->dest1_buffer_address;
	image_effect_dec_para.dest2_buffer_address=effect_dec_para->dest2_buffer_address;
	image_effect_dec_para.image_width=effect_dec_para->image_width;
	image_effect_dec_para.image_height=effect_dec_para->image_height;
	image_effect_dec_para.effect_index=effect_dec_para->effect_index;
	image_effect_dec_para.image_effect_dec_cb=effect_dec_para->image_effect_dec_cb;

	ibw1_para.bs=image_effect_dec_para.dest1_buffer_address;
	ibw1_para.pxlnum=(image_effect_dec_para.image_width)*(image_effect_dec_para.image_height);
	ibw1_para.cb=imgdma_ibw1_callback;
	ibr1_para.type=image_effect_dec_para.data_type;
	ibr1_para.order=image_effect_dec_para.data_order;
	ibr1_para.bs=image_effect_dec_para.source_buffer_address;
	ibr1_para.pxlnum=(image_effect_dec_para.image_width)*(image_effect_dec_para.image_height);

	rez_cfg.src1=SRC_MEM;
	rez_cfg.pcontinue=0;
	rez_cfg.pixel_sel=1;
	rez_cfg.run2=0;

	rez_pxl_cfg.wmsize=4;	//3<wmsize<17
	rez_pxl_cfg.wmbase=0;

	src_width=image_effect_dec_para.image_width;
	src_height=image_effect_dec_para.image_height;
	target_width=image_effect_dec_para.image_width;
	target_height=image_effect_dec_para.image_height;

	RESZ_Open(SCENARIO_IMG_EFFECT_ID);
	RESZ_Config(&rez_cfg,&rez_pxl_cfg, SCENARIO_IMG_EFFECT_ID);
	RESZ_SetSize(src_width, src_height, target_width, target_height,SCENARIO_IMG_EFFECT_ID);
	RESZ_Start(SCENARIO_IMG_EFFECT_ID);

	IBW1_COMPLETE_FLAG=0;
	IMGPROC_Open(SCENARIO_IMG_EFFECT_ID);
	IMGPROC_SelectMode(IMGPROC_IMAGE_CON_IE, SCENARIO_IMG_EFFECT_ID);
	image_effect_dec_handler();
	IMGPROC_Close(SCENARIO_IMG_EFFECT_ID);
	RESZ_Close(SCENARIO_IMG_EFFECT_ID);
#elif (defined(MT6228)||defined(MT6229)||defined(MT6230))
	image_effect_dec_para.data_type=effect_dec_para->data_type;
	image_effect_dec_para.data_order=effect_dec_para->data_order;
	image_effect_dec_para.source_buffer_address=effect_dec_para->source_buffer_address;
	image_effect_dec_para.dest1_buffer_address=effect_dec_para->dest1_buffer_address;
	image_effect_dec_para.dest2_buffer_address=effect_dec_para->dest2_buffer_address;
	image_effect_dec_para.effect_index=effect_dec_para->effect_index;
	IBW1_COMPLETE_FLAG=0;
		
	ipp_config_data.src_color_mode=effect_dec_para->data_type;
	ipp_config_data.src_color_order=effect_dec_para->data_order;
	ipp_config_data.dest_color_mode=effect_dec_para->dest_color_mode;
	ipp_config_data.src_address=effect_dec_para->source_buffer_address;
	ipp_config_data.dest_address=effect_dec_para->dest1_buffer_address;
	ipp_config_data.src_width=effect_dec_para->image_width;
	ipp_config_data.src_height=effect_dec_para->image_height;
	ipp_config_data.ipp_effect_cb=imgdma_ibw1_callback;

	open_image_data_path(SCENARIO_IMG_EFFECT_ID);
	image_effect_dec_handler();
	close_image_data_path(SCENARIO_IMG_EFFECT_ID);
#endif
}

/*************************************************************************
* FUNCTION
*	image_adj_dec_process
*
* DESCRIPTION
*	This function provides adjustment effects in IMAGE PLAYBACK and
*	POST-PORCESSING mode.
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
void image_adj_dec_process(IMAGE_EFFECT_DEC_STRUCT *effect_dec_para)
{
#if (defined(MT6219)||defined(MT6226)||defined(MT6226M)||defined(MT6226D)||defined(MT6227)||defined(MT6227D))
	RESZ_CFG_STRUCT rez_cfg;
	RESZ_PXL_CFG_STRUCT rez_pxl_cfg;
	kal_uint16 src_width, src_height, target_width, target_height;

	image_adj_dec_para.data_type=effect_dec_para->data_type;
	image_adj_dec_para.data_order=effect_dec_para->data_order;
	image_adj_dec_para.source_buffer_address=effect_dec_para->source_buffer_address;
	image_adj_dec_para.dest1_buffer_address=effect_dec_para->dest1_buffer_address;
	image_adj_dec_para.image_width=effect_dec_para->image_width;
	image_adj_dec_para.image_height=effect_dec_para->image_height;
	image_adj_dec_para.effect_index=effect_dec_para->effect_index;
	image_adj_dec_para.adj_level=effect_dec_para->adj_level;
	image_adj_dec_para.image_effect_dec_cb=effect_dec_para->image_effect_dec_cb;

	ibw1_para.bs=image_adj_dec_para.dest1_buffer_address;
	ibw1_para.pxlnum=(image_adj_dec_para.image_width)*(image_adj_dec_para.image_height);
	ibw1_para.cb=imgdma_ibw1_callback;
	ibr1_para.type=image_adj_dec_para.data_type;
	ibr1_para.order=image_adj_dec_para.data_order;
	ibr1_para.bs=image_adj_dec_para.source_buffer_address;
	ibr1_para.pxlnum=(image_adj_dec_para.image_width)*(image_adj_dec_para.image_height);

	rez_cfg.src1=SRC_MEM;
	rez_cfg.pcontinue=0;
	rez_cfg.pixel_sel=1;
	rez_cfg.run2=0;

	rez_pxl_cfg.wmsize=4;	//3<wmsize<17
	rez_pxl_cfg.wmbase=0;

	src_width=image_adj_dec_para.image_width;
	src_height=image_adj_dec_para.image_height;
	target_width=image_adj_dec_para.image_width;
	target_height=image_adj_dec_para.image_height;

	RESZ_Open(SCENARIO_IMG_EFFECT_ID);
	RESZ_Config(&rez_cfg,&rez_pxl_cfg, SCENARIO_IMG_EFFECT_ID);
	RESZ_SetSize(src_width, src_height, target_width, target_height,SCENARIO_IMG_EFFECT_ID);
	RESZ_Start(SCENARIO_IMG_EFFECT_ID);

	IBW1_COMPLETE_FLAG=0;
	IMGPROC_Open(SCENARIO_IMG_EFFECT_ID);
	clean_imgprc_coefficient(SCENARIO_IMG_EFFECT_ID);
	IMGPROC_SelectMode(IMGPROC_IMAGE_CON_IE, SCENARIO_IMG_EFFECT_ID);
	image_adj_dec_handler();
	IMGPROC_Close(SCENARIO_IMG_EFFECT_ID);
	RESZ_Close(SCENARIO_IMG_EFFECT_ID);
#elif (defined(MT6228)||defined(MT6229)||defined(MT6230))
	image_adj_dec_para.effect_index=effect_dec_para->effect_index;
	image_adj_dec_para.adj_level=effect_dec_para->adj_level;
	IBW1_COMPLETE_FLAG=0;

	ipp_config_data.src_color_mode=effect_dec_para->data_type;
	ipp_config_data.src_color_order=effect_dec_para->data_order;
	ipp_config_data.dest_color_mode=effect_dec_para->dest_color_mode;
	ipp_config_data.src_address=effect_dec_para->source_buffer_address;
	ipp_config_data.dest_address=effect_dec_para->dest1_buffer_address;
	ipp_config_data.src_width=effect_dec_para->image_width;
	ipp_config_data.src_height=effect_dec_para->image_height;
	ipp_config_data.ipp_effect_cb=imgdma_ibw1_callback;

	open_image_data_path(SCENARIO_IMG_EFFECT_ID);
	image_adj_dec_handler();
	close_image_data_path(SCENARIO_IMG_EFFECT_ID);
#endif
}

/*************************************************************************
* FUNCTION
*	adjustment_hue_para
*
* DESCRIPTION
*	This function adjustments hue parameters in PREVIEW and CAPTURE mode
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
void adjustment_hue_para(MMDI_SCENERIO_ID owner_id, kal_uint16 degree)
{
	IMGPROC_HUE_STURCT hue_para;

	if(degree<=90)
	{
		hue_para.c11=sine[90-degree];
		hue_para.c12=sine[degree];
		hue_para.c21=-sine[degree];
		hue_para.c22=sine[90-degree];
	}
	else if(degree>90 && degree<=180)
	{
		hue_para.c11=-sine[degree-90];
		hue_para.c12=sine[180-degree];
		hue_para.c21=-sine[180-degree];
		hue_para.c22=-sine[degree-90];
	}
	else if(degree>180 && degree<=270)
	{
		hue_para.c11=-sine[270-degree];
		hue_para.c12=-sine[degree-180];
		hue_para.c21=sine[degree-180];
		hue_para.c22=-sine[270-degree];
	}
	else if(degree>270 && degree<=360)
	{
		hue_para.c11=sine[degree-270];
		hue_para.c12=-sine[360-degree];
		hue_para.c21=sine[360-degree];
		hue_para.c22=sine[degree-270];
	}
	else
	{
		ASSERT(0);
	}

	IMGPROC_SetHUE(owner_id, &hue_para);
}

/*************************************************************************
* FUNCTION
*	adjustment_saturation_para
*
* DESCRIPTION
*	This function adjustments saturation parameters in PREVIEW and CAPTURE
*	mode
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
void adjustment_saturation_para(MMDI_SCENERIO_ID owner_id, kal_uint8 sat_value)
{
	/* Input data mapping between MMI and driver */
	if(sat_value<128)
	{
		sat_value/=4;
	}
	else
	{
//		sat_value=((sat_value-128)*7/4)+32;
		sat_value=((sat_value-128)*3/4)+32;	/* modify for workaround HW bug */
	}

	IMGPROC_SetSAT(owner_id, sat_value);
}

/*************************************************************************
* FUNCTION
*	adjustment_gamma_para
*
* DESCRIPTION
*	This function adjustments gamma parameters in PREVIEW and VIDEO PLAYBACK
*	mode
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
void adjustment_gamma_para(MMDI_SCENERIO_ID owner_id, kal_uint8 adj_level)
{
	IMGPROC_GAMMA_STRUCT gma_para;

	gma_para.gamma=gamma[adj_level][0];
	gma_para.off0=gamma[adj_level][1];
	gma_para.off1=gamma[adj_level][2];
	gma_para.off2=gamma[adj_level][3];
	gma_para.off3=gamma[adj_level][4];
	gma_para.off4=gamma[adj_level][5];
	gma_para.off5=gamma[adj_level][6];
	gma_para.off6=gamma[adj_level][7];
	gma_para.off7=gamma[adj_level][8];
	gma_para.slp0=gamma[adj_level][9];
	gma_para.slp1=gamma[adj_level][10];
	gma_para.slp2=gamma[adj_level][11];
	gma_para.slp3=gamma[adj_level][12];
	gma_para.slp4=gamma[adj_level][13];
	gma_para.slp5=gamma[adj_level][14];
	gma_para.slp6=gamma[adj_level][15];
	gma_para.slp7=gamma[adj_level][16];

	IMGPROC_SetGamma(owner_id, &gma_para);
}

/*************************************************************************
* FUNCTION
*	adjustment_coloradj_r_para
*
* DESCRIPTION
*	This function adjustments coloradj R parameters in PREVIEW mode
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
void adjustment_coloradj_r_para(MMDI_SCENERIO_ID owner_id, kal_uint8 adj_level)
{
	IMGPROC_COLORIZE_STRUCT clr_para;

	clr_para.r1x=coloradj_rb[adj_level][0];
	clr_para.r1y=coloradj_rb[adj_level][1];
	clr_para.r2x=coloradj_rb[adj_level][2];
	clr_para.r2y=coloradj_rb[adj_level][3];
	clr_para.r0slp=coloradj_rb[adj_level][4];
	clr_para.r1slp=coloradj_rb[adj_level][5];
	clr_para.r2slp=coloradj_rb[adj_level][6];
	clr_para.g1x=0;
	clr_para.g1y=0;
	clr_para.g2x=0;
	clr_para.g2y=0;
	clr_para.g0slp=16;
	clr_para.g1slp=16;
	clr_para.g2slp=16;
	clr_para.b1x=0;
	clr_para.b1y=0;
	clr_para.b2x=0;
	clr_para.b2y=0;
	clr_para.b0slp=16;
	clr_para.b1slp=16;
	clr_para.b2slp=16;

	IMGPROC_SetColorize(owner_id, &clr_para);
}

/*************************************************************************
* FUNCTION
*	adjustment_coloradj_g_para
*
* DESCRIPTION
*	This function adjustments coloradj G parameters in PREVIEW mode
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
void adjustment_coloradj_g_para(MMDI_SCENERIO_ID owner_id, kal_uint8 adj_level)
{
	IMGPROC_COLORIZE_STRUCT clr_para;

	clr_para.r1x=0;
	clr_para.r1y=0;
	clr_para.r2x=0;
	clr_para.r2y=0;
	clr_para.r0slp=16;
	clr_para.r1slp=16;
	clr_para.r2slp=16;
	clr_para.g1x=coloradj_g[adj_level][0];
	clr_para.g1y=coloradj_g[adj_level][1];
	clr_para.g2x=coloradj_g[adj_level][2];
	clr_para.g2y=coloradj_g[adj_level][3];
	clr_para.g0slp=coloradj_g[adj_level][4];
	clr_para.g1slp=coloradj_g[adj_level][5];
	clr_para.g2slp=coloradj_g[adj_level][6];
	clr_para.b1x=0;
	clr_para.b1y=0;
	clr_para.b2x=0;
	clr_para.b2y=0;
	clr_para.b0slp=16;
	clr_para.b1slp=16;
	clr_para.b2slp=16;

	IMGPROC_SetColorize(owner_id, &clr_para);
}

/*************************************************************************
* FUNCTION
*	adjustment_coloradj_b_para
*
* DESCRIPTION
*	This function adjustments coloradj B parameters in PREVIEW mode
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
void adjustment_coloradj_b_para(MMDI_SCENERIO_ID owner_id, kal_uint8 adj_level)
{
	IMGPROC_COLORIZE_STRUCT clr_para;

	clr_para.r1x=0;
	clr_para.r1y=0;
	clr_para.r2x=0;
	clr_para.r2y=0;
	clr_para.r0slp=16;
	clr_para.r1slp=16;
	clr_para.r2slp=16;
	clr_para.g1x=0;
	clr_para.g1y=0;
	clr_para.g2x=0;
	clr_para.g2y=0;
	clr_para.g0slp=16;
	clr_para.g1slp=16;
	clr_para.g2slp=16;
	clr_para.b1x=coloradj_rb[adj_level][0];
	clr_para.b1y=coloradj_rb[adj_level][1];
	clr_para.b2x=coloradj_rb[adj_level][2];
	clr_para.b2y=coloradj_rb[adj_level][3];
	clr_para.b0slp=coloradj_rb[adj_level][4];
	clr_para.b1slp=coloradj_rb[adj_level][5];
	clr_para.b2slp=coloradj_rb[adj_level][6];

	IMGPROC_SetColorize(owner_id, &clr_para);
}

/*************************************************************************
* FUNCTION
*	adjustment_brightness_para
*
* DESCRIPTION
*	This function adjustments brightness parameters in PREVIEW, CAPTURE,
*	VIDEO RECORD and VIDEO PLAYBACK mode
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
void adjustment_brightness_para(MMDI_SCENERIO_ID owner_id, kal_uint8 brightness_value)
{
	IMGPROC_BRI_CON_STURCT cba_para;

	if(brightness_value>=128)
	{
		cba_para.bright=(brightness_value-128)<<1;
		cba_para.dark=0;
	}
	else
	{
		cba_para.dark=((128-brightness_value)<<1)-1;
		cba_para.bright=0;
	}
	cba_para.contrast=32;

	IMGPROC_SetBrightContrast(owner_id, &cba_para);
}

/*************************************************************************
* FUNCTION
*	adjustment_brightness_video_encode
*
* DESCRIPTION
*	This function adjustments brightness parameters in	VIDEO RECORD mode
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
void adjustment_brightness_video_encode(kal_uint8 brightness_value)
{
	IMGPROC_BRI_CON_STURCT cba_para;

	if(brightness_value>=128)
	{
		cba_para.bright=(brightness_value-128)<<1;
		cba_para.dark=0;
	}
	else
	{
		cba_para.dark=((128-brightness_value)<<1)-1;
		cba_para.bright=0;
	}
	cba_para.contrast=(*((volatile unsigned short *) (IMGPROC_CONADJ)))&0xFF;

	IMGPROC_SetBrightContrast(SCENARIO_MPEG_ENCODE_ID, &cba_para);
}

/*************************************************************************
* FUNCTION
*	adjustment_brightness_video_decode
*
* DESCRIPTION
*	This function adjustments brightness parameters in	VIDEO DECORD mode
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
void adjustment_brightness_video_decode(kal_uint8 brightness_value)
{
	IMGPROC_BRI_CON_STURCT cba_para;

	if(brightness_value>=128)
	{
		cba_para.bright=(brightness_value-128)<<1;
		cba_para.dark=0;
	}
	else
	{
		cba_para.dark=((128-brightness_value)<<1)-1;
		cba_para.bright=0;
	}
	cba_para.contrast=(*((volatile unsigned short *) (IMGPROC_CONADJ)))&0xFF;

	IMGPROC_SetBrightContrast(SCENARIO_MPEG_DECODE_ID, &cba_para);
}

/*************************************************************************
* FUNCTION
*	adjustment_contrast_para
*
* DESCRIPTION
*	This function adjustments contrast parameters in PREVIEW, CAPTURE,
*	VIDEO RECORD and VIDEO PLAYBACK mode
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
void adjustment_contrast_para(MMDI_SCENERIO_ID owner_id, kal_uint8 contrast_value)
{
	IMGPROC_BRI_CON_STURCT cba_para;

	/* Input data mapping between MMI and driver */
	if(contrast_value<128)
	{
		contrast_value/=4;
	}
	else
	{
//		contrast_value=((contrast_value-128)*7/4)+32;
		contrast_value=((contrast_value-128)*3/4)+32;	// decrease maximum contrast gain
	}

 	cba_para.contrast=contrast_value;
 	cba_para.bright=0;
 	cba_para.dark=0;

	IMGPROC_SetBrightContrast(owner_id, &cba_para);
}

/*************************************************************************
* FUNCTION
*	adjustment_contrast_video_encode
*
* DESCRIPTION
*	This function adjustments contrast parameters in VIDEO RECORD mode
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
void adjustment_contrast_video_encode(kal_uint8 contrast_value)
{
	IMGPROC_BRI_CON_STURCT cba_para;

	/* Input data mapping between MMI and driver */
	if(contrast_value<128)
	{
		contrast_value/=4;
	}
	else
	{
		contrast_value=((contrast_value-128)*3/4)+32;	// decrease maximum contrast gain
	}

 	cba_para.contrast=contrast_value;
 	cba_para.bright=(*((volatile unsigned short *) (IMGPROC_BRIADJ1)))&0xFF;
 	cba_para.dark=(*((volatile unsigned short *) (IMGPROC_BRIADJ2)))&0xFF;

	IMGPROC_SetBrightContrast(SCENARIO_MPEG_ENCODE_ID, &cba_para);
}

/*************************************************************************
* FUNCTION
*	adjustment_contrast_video_decode
*
* DESCRIPTION
*	This function adjustments contrast parameters in VIDEO DECORD mode
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
void adjustment_contrast_video_decode(kal_uint8 contrast_value)
{
	IMGPROC_BRI_CON_STURCT cba_para;

	/* Input data mapping between MMI and driver */
	if(contrast_value<128)
	{
		contrast_value/=4;
	}
	else
	{
		contrast_value=((contrast_value-128)*3/4)+32;	// decrease maximum contrast gain
	}

 	cba_para.contrast=contrast_value;
 	cba_para.bright=(*((volatile unsigned short *) (IMGPROC_BRIADJ1)))&0xFF;
 	cba_para.dark=(*((volatile unsigned short *) (IMGPROC_BRIADJ2)))&0xFF;

	IMGPROC_SetBrightContrast(SCENARIO_MPEG_DECODE_ID, &cba_para);
}

/*************************************************************************
* FUNCTION
*	adjustment_brightness_contrast_para
*
* DESCRIPTION
*	This function adjustments brightness and contrast parameters in PREVIEW,
*  CAPTURE,	VIDEO RECORD and VIDEO PLAYBACK mode
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
void adjustment_brightness_contrast_para(MMDI_SCENERIO_ID owner_id, kal_uint8 brightness_value, kal_uint8 contrast_value)
{
	IMGPROC_BRI_CON_STURCT cba_para;
	
	/* Brightness Setting */
	if(brightness_value>=128)
	{
		cba_para.bright=(brightness_value-128)<<1;
		cba_para.dark=0;
	}
	else
	{
		cba_para.dark=((128-brightness_value)<<1)-1;
		cba_para.bright=0;
	}
	
	/* Contrast Setting */
	if(contrast_value<128)
	{
		contrast_value/=4;
	}
	else
	{
//		contrast_value=((contrast_value-128)*7/4)+32;
		contrast_value=((contrast_value-128)*3/4)+32;	// decrease maximum contrast gain
	}
 	cba_para.contrast=contrast_value;

	IMGPROC_SetBrightContrast(owner_id, &cba_para);
}

/*************************************************************************
* FUNCTION
*	image_effect_enc_handler
*
* DESCRIPTION
*	This function handles the effects in PREVIEW, CAPTURE and MPEG4
*	ENCODE mode.
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
void image_effect_enc_handler(void)
{
	switch(image_effect_enc)
	{
		case CAM_EFFECT_ENC_NORMAL:
			effect_enc_normal();
			break;
		case CAM_EFFECT_ENC_GRAYSCALE:
			effect_enc_grayscale();
			break;
		case CAM_EFFECT_ENC_SEPIA:
			effect_enc_sepia();
			break;
		case CAM_EFFECT_ENC_SEPIAGREEN:
			effect_enc_sepiagreen();
			break;
		case CAM_EFFECT_ENC_SEPIABLUE:
			effect_enc_sepiablue();
			break;
		case CAM_EFFECT_ENC_COLORINV:
			effect_enc_colorinv();
			break;
		case CAM_EFFECT_ENC_GRAYINV:
			effect_enc_grayinv();
			break;
		case CAM_EFFECT_ENC_BLACKBOARD:
			effect_enc_blackboard();
			break;
		case CAM_EFFECT_ENC_WHITEBOARD:
			effect_enc_whiteboard();
			break;
		case CAM_EFFECT_ENC_COPPERCARVING:
			effect_enc_coppercarving();
			break;
		case CAM_EFFECT_ENC_EMBOSSMENT:
			effect_enc_embossment();
			break;
		case CAM_EFFECT_ENC_BLUECARVING:
			effect_enc_bluecarving();
			break;
		case CAM_EFFECT_ENC_CONTRAST:
			effect_enc_contrast();
			break;
		case CAM_EFFECT_ENC_JEAN:
			effect_enc_jean();
			break;
		case CAM_EFFECT_ENC_SKETCH:
			effect_enc_sketch();
			break;
		case CAM_EFFECT_ENC_OIL:
			effect_enc_oil();
			break;
		default:
			effect_enc_normal();
			break;
	}
}

/*************************************************************************
* FUNCTION
*	image_effect_dec_handler
*
* DESCRIPTION
*	This function handles the effects in VIDEO PLAYBACK,
*	IMAGE PLAYBACK and POST-PORCESSING mode.
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
void image_effect_dec_handler(void)
{
	switch(image_effect_dec_para.effect_index)
	{
		case CAM_EFFECT_DEC_GRAYSCALE:
			effect_dec_grayscale();
			break;
		case CAM_EFFECT_DEC_SEPIA:
			effect_dec_sepia();
			break;
		case CAM_EFFECT_DEC_SEPIAGREEN:
			effect_dec_sepiagreen();
			break;
		case CAM_EFFECT_DEC_SEPIABLUE:
			effect_dec_sepiablue();
			break;
		case CAM_EFFECT_DEC_COLORINV:
			effect_dec_colorinv();
			break;
		case CAM_EFFECT_DEC_GRAYINV:
			effect_dec_grayinv();
			break;
		case CAM_EFFECT_DEC_WATERCOLOR:
			effect_dec_watercolor();
			break;
		case CAM_EFFECT_DEC_LIGHTBLUR:
			effect_dec_lightblur();
			break;
		case CAM_EFFECT_DEC_BLUR:
			effect_dec_blur();
			break;
		case CAM_EFFECT_DEC_STRONGBLUR:
			effect_dec_strongblur();
			break;
		case CAM_EFFECT_DEC_UNSHARP:
			effect_dec_unsharp();
			break;
		case CAM_EFFECT_DEC_SHARPEN:
			effect_dec_sharpen();
			break;
		case CAM_EFFECT_DEC_MORESHARPEN:
			effect_dec_moresharpen();
			break;
		case CAM_EFFECT_DEC_MEDIAN:
			effect_dec_median();
			break;
		case CAM_EFFECT_DEC_DILATION:
			effect_dec_dilation();
			break;
		case CAM_EFFECT_DEC_EROSION:
			effect_dec_erosion();
			break;
		default:
			break;
	}
}

/*************************************************************************
* FUNCTION
*	image_adj_dec_handler
*
* DESCRIPTION
*	This function handles the effects in IMAGE PLAYBACK and
*	POST-PORCESSING mode.
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
void image_adj_dec_handler(void)
{
	switch(image_adj_dec_para.effect_index)
	{
		case CAM_ADJ_DEC_HUE:
			adj_dec_hue();
			break;
		case CAM_ADJ_DEC_SATURATION:
			adj_dec_saturation();
			break;
		case CAM_ADJ_DEC_GAMMA:
			adj_dec_gamma();
			break;
		case CAM_ADJ_DEC_ADJR:
			adj_dec_coloradj();
			break;
		case CAM_ADJ_DEC_ADJG:
			adj_dec_coloradj();
			break;
		case CAM_ADJ_DEC_ADJB:
			adj_dec_coloradj();
			break;
		case CAM_ADJ_DEC_CONTRAST:
			adj_dec_brightness_contrast();
			break;
		case CAM_ADJ_DEC_BRIGHTNESS:
			adj_dec_brightness_contrast();
			break;
		default:
			break;
	}
}

/*************************************************************************
*
*						IMAGE EFFECT PARAMETER SETTING
*
**************************************************************************/

/*************************************************************************
* FUNCTION
*	effect_enc_normal
*
* DESCRIPTION
*	This function provides non effect in PREVIEW, CAPTURE and MPEG4
*	ENCODE mode.
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
void effect_enc_normal(void)
{
	kal_uint8 i;

	for(i=28;i<53;i++)
	{
		   *((volatile unsigned int *) (CAMERA_base + i*4))=camera_para.ISP.reg[i];
	}

	if(camera_para.PREDGAMMA.gamma_select!=0)
	{
		SET_GAMMA_B1(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][0]);
		SET_GAMMA_B2(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][1]);
		SET_GAMMA_B3(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][2]);
		SET_GAMMA_B4(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][3]);
		SET_GAMMA_B5(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][4]);
		SET_GAMMA_B6(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][5]);
		SET_GAMMA_B7(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][6]);
		SET_GAMMA_B8(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][7]);
		SET_GAMMA_B9(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][8]);
		SET_GAMMA_B10(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][9]);
		SET_GAMMA_B11(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][10]);
	}

   if(isp_operation_state==ISP_MPEG4_ENCODE_STATE)
		set_camera_mode_para(CAMERA_PARA_VIDEO_MODE);
	else
   	set_camera_mode_para(CAMERA_PARA_PREVIEW_MODE);
}

/*************************************************************************
* FUNCTION
*	effect_enc_grayscale
*
* DESCRIPTION
*	This function provides gray scale effect in PREVIEW, CAPTURE and MPEG4
*	ENCODE mode.
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
void effect_enc_grayscale(void)
{
	/* Hue setting */
	SET_HUE_U_GAIN(0);
	SET_HUE_V_GAIN(0);
	/* Color Matrix*/
	SET_COLOR_MATRIX1(0,0,0);
	SET_COLOR_MATRIX3(0,0,0);
}

/*************************************************************************
* FUNCTION
*	effect_enc_sepia
*
* DESCRIPTION
*	This function provides sepia effect in PREVIEW, CAPTURE and MPEG4 ENCODE
*	mode.
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
void effect_enc_sepia(void)
{
	/* Hue setting */
	SET_HUE_U_GAIN(0);
	SET_HUE_V_GAIN(0);
	SET_HUE_U_OFFSET(158);
	SET_HUE_V_OFFSET(30);
	/* Color Matrix*/
	SET_COLOR_MATRIX1(0,0,0);
	SET_COLOR_MATRIX3(0,0,0);
}

/*************************************************************************
* FUNCTION
*	effect_enc_sepiagreen
*
* DESCRIPTION
*	This function provides green sepia effect in PREVIEW, CAPTURE and MPEG4
*	ENCODE mode.
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
void effect_enc_sepiagreen(void)
{
	/* Hue setting */
	SET_HUE_U_GAIN(0);
	SET_HUE_V_GAIN(0);
	SET_HUE_U_OFFSET(145);
	SET_HUE_V_OFFSET(145);
	/* Color Matrix*/
	SET_COLOR_MATRIX1(0,0,0);
	SET_COLOR_MATRIX3(0,0,0);
}

/*************************************************************************
* FUNCTION
*	effect_enc_sepiablue
*
* DESCRIPTION
*	This function provides blue sepia effect in PREVIEW, CAPTURE and MPEG4
*	ENCODE mode.
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
void effect_enc_sepiablue(void)
{
	/* Hue setting */
	SET_HUE_U_GAIN(0);
	SET_HUE_V_GAIN(0);
	SET_HUE_U_OFFSET(88);
	SET_HUE_V_OFFSET(158);
	/* Color Matrix*/
	SET_COLOR_MATRIX1(0,0,0);
	SET_COLOR_MATRIX3(0,0,0);
}

/*************************************************************************
* FUNCTION
*	effect_enc_colorinv
*
* DESCRIPTION
*	This function provides color invert effect in PREVIEW, CAPTURE and MPEG4
*	ENCODE mode.
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
void effect_enc_colorinv(void)
{
	ENABLE_OPD_GAMMA_OUT_INVERSION;
}

/*************************************************************************
* FUNCTION
*	effect_enc_grayinv
*
* DESCRIPTION
*	This function provides gray color invert effect in PREVIEW, CAPTURE and
*	MPEG4 ENCODE mode.
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
void effect_enc_grayinv(void)
{
	SET_HUE_U_GAIN(0);
	SET_HUE_V_GAIN(0);
	ENABLE_OPD_GAMMA_OUT_INVERSION;
	/* Color Matrix*/
	SET_COLOR_MATRIX1(0,0,0);
	SET_COLOR_MATRIX3(0,0,0);
}

/*************************************************************************
* FUNCTION
*	effect_enc_blackboard
*
* DESCRIPTION
*	This function provides blackboard effect in PREVIEW, CAPTURE and
*	MPEG4 ENCODE mode.
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
void effect_enc_blackboard(void)
{
	/* Hue setting */
	SET_HUE_U_GAIN(0);
	SET_HUE_V_GAIN(0);
	/* Edge setting */
	ENABLE_RGB_EDGE_GAIN;
	DISABLE_EDGE_EFFECT_OIL;
	SET_EDGE_GAIN_KNEESEL(3);
	SET_EDGE_GAIN_LINE(0);
	SET_EDGE_GAIN_H2(31);
	SET_EDGE_GAIN_H(0);
	SET_EDGE_SPECI_PONLY(1);
	SET_EDGE_SPECI_GAIN(0);
	SET_EDGE_GAIN_VB(31);
	DISABLE_EDGE_GAIN_SPECIABS;
	DISABLE_EDGE_GAIN_SPECIINV;
	DISABLE_OPD_GAMMA_OUT_INVERSION;
	SET_EDGE_CORE_H(0);
	SET_EDGE_V_CTRL_E_TH1_V(4);
	ENABLE_EMBOSS1;
	ENABLE_EMBOSS2;
	SET_INTERPOLATION_THRE_LEDGE(127);
	/* Color Matrix*/
	SET_COLOR_MATRIX1(0,0,0);
	SET_COLOR_MATRIX2(0,0,0);
	SET_COLOR_MATRIX3(0,0,0);
	/* Flare setting */
	SET_GAMMA_RGB_FLARE_SIGN_R_LOW;
	SET_GAMMA_RGB_FLARE_R(0);
	SET_GAMMA_RGB_FLARE_SIGN_G_LOW;
	SET_GAMMA_RGB_FLARE_G(0);
	SET_GAMMA_RGB_FLARE_SIGN_B_LOW;
	SET_GAMMA_RGB_FLARE_B(0);
	/* Contrast Gain setting */
	SET_AWB_R_GAIN(128);
	SET_AWB_G_GAIN(128);
	SET_AWB_B_GAIN(128);
	/* Y Edge */
	ENABLE_Y_EDGE;
	SET_Y_EDGE_GAIN(15);
}

/*************************************************************************
* FUNCTION
*	effect_enc_whiteboard
*
* DESCRIPTION
*	This function provides whiteboard effect in PREVIEW, CAPTURE and
*	MPEG4 ENCODE mode.
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
void effect_enc_whiteboard(void)
{
	/* Hue setting */
	SET_HUE_U_GAIN(0);
	SET_HUE_V_GAIN(0);
	/* Edge setting */
	ENABLE_RGB_EDGE_GAIN;
	DISABLE_EDGE_EFFECT_OIL;
	SET_EDGE_GAIN_KNEESEL(3);
	SET_EDGE_GAIN_LINE(0);
	SET_EDGE_GAIN_H2(31);
	SET_EDGE_GAIN_H(0);
	SET_EDGE_SPECI_PONLY(1);
	SET_EDGE_SPECI_GAIN(0);
	SET_EDGE_GAIN_VB(31);
	DISABLE_EDGE_GAIN_SPECIABS;
	DISABLE_EDGE_GAIN_SPECIINV;
	ENABLE_OPD_GAMMA_OUT_INVERSION;
	SET_EDGE_CORE_H(0);
	SET_EDGE_V_CTRL_E_TH1_V(4);
	ENABLE_EMBOSS1;
	ENABLE_EMBOSS2;
	SET_INTERPOLATION_THRE_LEDGE(127);
	/* Color Matrix*/
	SET_COLOR_MATRIX1(0,0,0);
	SET_COLOR_MATRIX2(0,0,0);
	SET_COLOR_MATRIX3(0,0,0);
	/* Flare setting */
	SET_GAMMA_RGB_FLARE_SIGN_R_LOW;
	SET_GAMMA_RGB_FLARE_R(0);
	SET_GAMMA_RGB_FLARE_SIGN_G_LOW;
	SET_GAMMA_RGB_FLARE_G(0);
	SET_GAMMA_RGB_FLARE_SIGN_B_LOW;
	SET_GAMMA_RGB_FLARE_B(0);
	/* Contrast Gain setting */
	SET_AWB_R_GAIN(128);
	SET_AWB_G_GAIN(128);
	SET_AWB_B_GAIN(128);
	/* Contrast setting */
	SET_Y_CONTRAST_GAIN(127);
	/* Brightness setting */
	SET_Y_BRIGHT_OFFSET(255);
	/* Y Edge */
	DISABLE_Y_EDGE;			
}

/*************************************************************************
* FUNCTION
*	effect_enc_coppercarving
*
* DESCRIPTION
*	This function provides copper carving effect in PREVIEW, CAPTURE and
*	MPEG4 ENCODE mode.
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
void effect_enc_coppercarving(void)
{
	/* Hue setting */
	SET_HUE_U_GAIN(0);
	SET_HUE_V_GAIN(0);
	SET_HUE_U_OFFSET(188);
	SET_HUE_V_OFFSET(40);
	/* Edge setting */
	ENABLE_RGB_EDGE_GAIN;
	ENABLE_EDGE_EFFECT_OIL;
	SET_EDGE_GAIN_KNEESEL(3);
	SET_EDGE_GAIN_H2(15);
	SET_EDGE_GAIN_H(0);
	SET_EDGE_GAIN_VB(15);
	ENABLE_EMBOSS1;
	ENABLE_EMBOSS2;
	SET_INTERPOLATION_THRE_LEDGE(127);
	/* Color Matrix*/
	SET_COLOR_MATRIX1(0,0,0);
	SET_COLOR_MATRIX2(0,0,0);
	SET_COLOR_MATRIX3(0,0,0);
	/* Flare setting */
	SET_GAMMA_RGB_FLARE_SIGN_R_LOW;
	SET_GAMMA_RGB_FLARE_R(63);
	SET_GAMMA_RGB_FLARE_SIGN_G_LOW;
	SET_GAMMA_RGB_FLARE_G(63);
	SET_GAMMA_RGB_FLARE_SIGN_B_LOW;
	SET_GAMMA_RGB_FLARE_B(63);
	/* Contrast Gain setting */
	SET_AWB_R_GAIN(255);
	SET_AWB_G_GAIN(255);
	SET_AWB_B_GAIN(255);
}

/*************************************************************************
* FUNCTION
*	effect_enc_embossment
*
* DESCRIPTION
*	This function provides embossment effect in PREVIEW, CAPTURE and
*	MPEG4 ENCODE mode.
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
void effect_enc_embossment(void)
{
	/* Hue setting */
	SET_HUE_U_GAIN(0);
	SET_HUE_V_GAIN(0);
	/* Edge setting */
	ENABLE_RGB_EDGE_GAIN;
	DISABLE_EDGE_EFFECT_OIL;
	SET_EDGE_GAIN_KNEESEL(3);
	SET_EDGE_GAIN_LINE(2);
	SET_EDGE_GAIN_H2(31);
	SET_EDGE_GAIN_H(0);
	SET_EDGE_SPECI_PONLY(0);
	SET_EDGE_SPECI_GAIN(0);
	SET_EDGE_GAIN_VB(31);
	DISABLE_EDGE_GAIN_SPECIABS;
	DISABLE_EDGE_GAIN_SPECIINV;
	DISABLE_OPD_GAMMA_OUT_INVERSION;
	SET_EDGE_CORE_H(8);
	SET_EDGE_V_CTRL_E_TH1_V(8);
	ENABLE_EMBOSS1;
	ENABLE_EMBOSS2;
	SET_INTERPOLATION_THRE_LEDGE(127);
	/* Color Matrix*/
	SET_COLOR_MATRIX1(0,0,0);
	SET_COLOR_MATRIX2(0,0,0);
	SET_COLOR_MATRIX3(0,0,0);
	/* Flare setting */
	SET_GAMMA_RGB_FLARE_SIGN_R_LOW;
	SET_GAMMA_RGB_FLARE_R(63);
	SET_GAMMA_RGB_FLARE_SIGN_G_LOW;
	SET_GAMMA_RGB_FLARE_G(63);
	SET_GAMMA_RGB_FLARE_SIGN_B_LOW;
	SET_GAMMA_RGB_FLARE_B(63);
	/* Contrast Gain setting */
	SET_AWB_R_GAIN(255);
	SET_AWB_G_GAIN(255);
	SET_AWB_B_GAIN(255);
}

/*************************************************************************
* FUNCTION
*	effect_enc_bluecarving
*
* DESCRIPTION
*	This function provides blue carving effect in PREVIEW, CAPTURE and
*	MPEG4 ENCODE mode.
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
void effect_enc_bluecarving(void)
{
	/* Hue setting */
	SET_HUE_U_GAIN(0);
	SET_HUE_V_GAIN(0);
	SET_HUE_U_OFFSET(88);
	SET_HUE_V_OFFSET(158);
	/* Edge setting */
	ENABLE_RGB_EDGE_GAIN;
	DISABLE_EDGE_EFFECT_OIL;
	SET_EDGE_GAIN_KNEESEL(3);
	SET_EDGE_GAIN_LINE(2);
	SET_EDGE_GAIN_H2(31);
	SET_EDGE_GAIN_H(0);
	SET_EDGE_SPECI_PONLY(0);
	SET_EDGE_SPECI_GAIN(0);
	SET_EDGE_GAIN_VB(31);
	DISABLE_EDGE_GAIN_SPECIABS;
	DISABLE_EDGE_GAIN_SPECIINV;
	DISABLE_OPD_GAMMA_OUT_INVERSION;
	SET_EDGE_CORE_H(8);
	SET_EDGE_V_CTRL_E_TH1_V(8);
	ENABLE_EMBOSS1;
	ENABLE_EMBOSS2;
	SET_INTERPOLATION_THRE_LEDGE(127);
	/* Color Matrix*/
	SET_COLOR_MATRIX1(0,0,0);
	SET_COLOR_MATRIX2(0,0,0);
	SET_COLOR_MATRIX3(0,0,0);
	/* Flare setting */
	SET_GAMMA_RGB_FLARE_SIGN_R_LOW;
	SET_GAMMA_RGB_FLARE_R(0);
	SET_GAMMA_RGB_FLARE_SIGN_G_LOW;
	SET_GAMMA_RGB_FLARE_G(0);
	SET_GAMMA_RGB_FLARE_SIGN_B_LOW;
	SET_GAMMA_RGB_FLARE_B(0);
	/* Contrast Gain setting */
	SET_AWB_R_GAIN(128);
	SET_AWB_G_GAIN(128);
	SET_AWB_B_GAIN(128);
}

/*************************************************************************
* FUNCTION
*	effect_enc_contrast
*
* DESCRIPTION
*	This function provides high contrast effect in PREVIEW, CAPTURE and
*	MPEG4 ENCODE mode.
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
void effect_enc_contrast(void)
{
	/* Hue setting */
	SET_HUE_U_GAIN(0);
	SET_HUE_V_GAIN(0);
	/* Edge setting */
	ENABLE_RGB_EDGE_GAIN;
	ENABLE_EDGE_EFFECT_OIL;
	SET_EDGE_GAIN_KNEESEL(0);
	SET_EDGE_GAIN_LINE(0);
	SET_EDGE_GAIN_H2(0);
	SET_EDGE_GAIN_H(0);
	SET_EDGE_SPECI_PONLY(0);
	SET_EDGE_SPECI_GAIN(0);
	SET_EDGE_GAIN_VB(0);
	SET_EDGE_CORE_H(0);
	SET_EDGE_V_CTRL_E_TH1_V(35);
	/* Contrast setting */
	SET_Y_CONTRAST_GAIN(127);
	/* Brightness setting */
	SET_Y_BRIGHT_OFFSET(255);
}

/*************************************************************************
* FUNCTION
*	effect_enc_jean
*
* DESCRIPTION
*	This function provides jean effect in PREVIEW, CAPTURE and
*	MPEG4 ENCODE mode.
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
void effect_enc_jean(void)
{
	/* Hue setting */
	SET_HUE_U_GAIN(0);
	SET_HUE_V_GAIN(0);
	SET_HUE_U_OFFSET(88);
	SET_HUE_V_OFFSET(158);
	/* Edge setting */
	ENABLE_RGB_EDGE_GAIN;
	DISABLE_EDGE_EFFECT_OIL;
	SET_EDGE_GAIN_KNEESEL(3);
	SET_EDGE_GAIN_LINE(15);
	SET_EDGE_GAIN_H2(31);
	SET_EDGE_GAIN_H(15);
	SET_EDGE_SPECI_PONLY(0);
	SET_EDGE_SPECI_GAIN((kal_uint32)2);
	SET_EDGE_GAIN_VB(31);
	SET_EDGE_CORE_H(0);
	SET_EDGE_V_CTRL_E_TH1_V(4);
	ENABLE_EMBOSS2;
}

/*************************************************************************
* FUNCTION
*	effect_enc_sketch
*
* DESCRIPTION
*	This function provides sketch effect in PREVIEW, CAPTURE and
*	MPEG4 ENCODE mode.
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
void effect_enc_sketch(void)
{
	/* Hue setting */
	SET_HUE_U_GAIN(0);
	SET_HUE_V_GAIN(0);
	/* Edge setting */
	ENABLE_RGB_EDGE_GAIN;
	DISABLE_EDGE_EFFECT_OIL;
	SET_EDGE_GAIN_KNEESEL(0);
	SET_EDGE_GAIN_LINE(15);
	SET_EDGE_GAIN_H2(31);
	SET_EDGE_GAIN_H(0);
	SET_EDGE_SPECI_PONLY(0);
	SET_EDGE_SPECI_GAIN(0);
	SET_EDGE_GAIN_VB(31);
	ENABLE_EDGE_GAIN_SPECIABS;
	DISABLE_EDGE_GAIN_SPECIINV;
	DISABLE_OPD_GAMMA_OUT_INVERSION;
	SET_EDGE_CORE_H(0);
	SET_EDGE_V_CTRL_E_TH1_V(4);
	ENABLE_EMBOSS1;
	ENABLE_EMBOSS2;
	SET_INTERPOLATION_THRE_LEDGE(127);
	/* Color Matrix*/
	SET_COLOR_MATRIX1(0,0,0);
	SET_COLOR_MATRIX3(0,0,0);
}

/*************************************************************************
* FUNCTION
*	effect_enc_oil
*
* DESCRIPTION
*	This function provides oil effect in PREVIEW, CAPTURE and
*	MPEG4 ENCODE mode.
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
void effect_enc_oil(void)
{
	/* Hue setting */
	SET_HUE_U_GAIN(50);
	SET_HUE_V_GAIN(50);
	/* Edge setting */
	ENABLE_RGB_EDGE_GAIN;
	ENABLE_EDGE_EFFECT_OIL;
	SET_EDGE_GAIN_KNEESEL(3);
	SET_EDGE_GAIN_LINE(15);
	SET_EDGE_GAIN_H2(31);
	SET_EDGE_GAIN_H(15);
	SET_EDGE_SPECI_PONLY(0);
	SET_EDGE_SPECI_GAIN(1);
	SET_EDGE_GAIN_VB(31);
	SET_EDGE_CORE_H(0);
	SET_EDGE_V_CTRL_E_TH1_V(35);
	DISABLE_EMBOSS1;
	ENABLE_EMBOSS2;
}

/*************************************************************************
* FUNCTION
*	effect_dec_grayscale
*
* DESCRIPTION
*	This function provides gray scale effect in VIDEO PLAYBACK, IMAGE PLAYBACK
*	and POST-PORCESSING mode.
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
void effect_dec_grayscale(void)
{
	IMGPROC_PIXEL_EFFECT_STURCT pixel_effect_para;

	/* config Image Processor */
	pixel_effect_para.hsa=IMGPROC_HSA_GRAY;
	pixel_effect_para.cba=0;
	pixel_effect_para.inv=0;
	pixel_effect_para.clr=0;
	pixel_effect_para.gma=0;

#if (defined(MT6219)||defined(MT6226)||defined(MT6226M)||defined(MT6226D)||defined(MT6227)||defined(MT6227D))
	/* config Image DMA */
	IMGDMA_Init();
	IMGDMA_Open(SCENARIO_IMG_EFFECT_ID);

	IMGPROC_SetPixelEffect( &pixel_effect_para, SCENARIO_IMG_EFFECT_ID);

	/* start Image Processor */
	IMGPROC_Start(SCENARIO_IMG_EFFECT_ID);

	/* start Image DMA */
	IMGDMA_IBW1Config( &ibw1_para, 1, SCENARIO_IMG_EFFECT_ID);
	IMGDMA_IBR1Config( &ibr1_para, 1, SCENARIO_IMG_EFFECT_ID);

	/* wait Image DMA */
	imgdma_wait_done();

	/* close Image DMA */
	IMGDMA_Close(SCENARIO_IMG_EFFECT_ID);

#elif (defined(MT6228)||defined(MT6229)||defined(MT6230))
	ipp_config_data.pixel_effect_para=pixel_effect_para;
	config_pixel_effect_data_path(&ipp_config_data);
	/* wait Image DMA */
	imgdma_wait_done();
#endif
}

/*************************************************************************
* FUNCTION
*	effect_dec_sepia
*
* DESCRIPTION
*	This function provides sepia effect in VIDEO PLAYBACK, IMAGE PLAYBACK
*	and POST-PORCESSING mode.
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
void effect_dec_sepia(void)
{
	IMGPROC_PIXEL_EFFECT_STURCT pixel_effect_para;

	/* config Image Processor */
	pixel_effect_para.hsa=IMGPROC_HSA_COLORIZE;
	pixel_effect_para.cba=0;
	pixel_effect_para.inv=0;
	pixel_effect_para.clr=0;
	pixel_effect_para.gma=0;

#if (defined(MT6219)||defined(MT6226)||defined(MT6226M)||defined(MT6226D)||defined(MT6227)||defined(MT6227D))
	/* config Image DMA */
	IMGDMA_Init();
	IMGDMA_Open(SCENARIO_IMG_EFFECT_ID);

	IMGPROC_SetPixelEffect( &pixel_effect_para, SCENARIO_IMG_EFFECT_ID);
	DRV_WriteReg32(IMGPROC_COLORIZEU, -30);
	DRV_WriteReg32(IMGPROC_COLORIZEV, 36);

	/* start Image Processor */
	IMGPROC_Start(SCENARIO_IMG_EFFECT_ID);

	/* start Image DMA */
	IMGDMA_IBW1Config( &ibw1_para, 1, SCENARIO_IMG_EFFECT_ID);
	IMGDMA_IBR1Config( &ibr1_para, 1, SCENARIO_IMG_EFFECT_ID);

	/* wait Image DMA */
	imgdma_wait_done();

	/* close Image DMA */
	IMGDMA_Close(SCENARIO_IMG_EFFECT_ID);

#elif (defined(MT6228)||defined(MT6229)||defined(MT6230))
	ipp_config_data.pixel_effect_para=pixel_effect_para;
	DRV_WriteReg32(IMGPROC_COLORIZEU, -30);
	DRV_WriteReg32(IMGPROC_COLORIZEV, 36);
	config_pixel_effect_data_path(&ipp_config_data);
	/* wait Image DMA */
	imgdma_wait_done();
#endif
}

/*************************************************************************
* FUNCTION
*	effect_dec_sepiagreen
*
* DESCRIPTION
*	This function provides green sepia effect in VIDEO PLAYBACK, IMAGE PLAYBACK
*	and POST-PORCESSING mode.
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
void effect_dec_sepiagreen(void)
{
	IMGPROC_PIXEL_EFFECT_STURCT pixel_effect_para;

	/* config Image Processor */
	pixel_effect_para.hsa=IMGPROC_HSA_COLORIZE;
	pixel_effect_para.cba=0;
	pixel_effect_para.inv=0;
	pixel_effect_para.clr=0;
	pixel_effect_para.gma=0;

#if (defined(MT6219)||defined(MT6226)||defined(MT6226M)||defined(MT6226D)||defined(MT6227)||defined(MT6227D))
	/* config Image DMA */
	IMGDMA_Init();
	IMGDMA_Open(SCENARIO_IMG_EFFECT_ID);

	IMGPROC_SetPixelEffect( &pixel_effect_para, SCENARIO_IMG_EFFECT_ID);
	DRV_WriteReg32(IMGPROC_COLORIZEU, -30);
	DRV_WriteReg32(IMGPROC_COLORIZEV, -30);

	/* start Image Processor */
	IMGPROC_Start(SCENARIO_IMG_EFFECT_ID);

	/* start Image DMA */
	IMGDMA_IBW1Config( &ibw1_para, 1, SCENARIO_IMG_EFFECT_ID);
	IMGDMA_IBR1Config( &ibr1_para, 1, SCENARIO_IMG_EFFECT_ID);

	/* wait Image DMA */
	imgdma_wait_done();

	/* close Image DMA */
	IMGDMA_Close(SCENARIO_IMG_EFFECT_ID);

#elif (defined(MT6228)||defined(MT6229)||defined(MT6230))
	ipp_config_data.pixel_effect_para=pixel_effect_para;
	DRV_WriteReg32(IMGPROC_COLORIZEU, -30);
	DRV_WriteReg32(IMGPROC_COLORIZEV, -30);
	config_pixel_effect_data_path(&ipp_config_data);
	/* wait Image DMA */
	imgdma_wait_done();
#endif
}

/*************************************************************************
* FUNCTION
*	effect_dec_sepiablue
*
* DESCRIPTION
*	This function provides blue sepia effect in VIDEO PLAYBACK, IMAGE PLAYBACK
*	and POST-PORCESSING mode.
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
void effect_dec_sepiablue(void)
{
	IMGPROC_PIXEL_EFFECT_STURCT pixel_effect_para;

	/* config Image Processor */
	pixel_effect_para.hsa=IMGPROC_HSA_COLORIZE;
	pixel_effect_para.cba=0;
	pixel_effect_para.inv=0;
	pixel_effect_para.clr=0;
	pixel_effect_para.gma=0;

#if (defined(MT6219)||defined(MT6226)||defined(MT6226M)||defined(MT6226D)||defined(MT6227)||defined(MT6227D))
	/* config Image DMA */
	IMGDMA_Init();
	IMGDMA_Open(SCENARIO_IMG_EFFECT_ID);

	IMGPROC_SetPixelEffect( &pixel_effect_para, SCENARIO_IMG_EFFECT_ID);
	DRV_WriteReg32(IMGPROC_COLORIZEU, 88);
	DRV_WriteReg32(IMGPROC_COLORIZEV, -30);

	/* start Image Processor */
	IMGPROC_Start(SCENARIO_IMG_EFFECT_ID);

	/* start Image DMA */
	IMGDMA_IBW1Config( &ibw1_para, 1, SCENARIO_IMG_EFFECT_ID);
	IMGDMA_IBR1Config( &ibr1_para, 1, SCENARIO_IMG_EFFECT_ID);

	/* wait Image DMA */
	imgdma_wait_done();

	/* close Image DMA */
	IMGDMA_Close(SCENARIO_IMG_EFFECT_ID);

#elif (defined(MT6228)||defined(MT6229)||defined(MT6230))
	ipp_config_data.pixel_effect_para=pixel_effect_para;
	DRV_WriteReg32(IMGPROC_COLORIZEU, 88);
	DRV_WriteReg32(IMGPROC_COLORIZEV, -30);
	config_pixel_effect_data_path(&ipp_config_data);
	/* wait Image DMA */
	imgdma_wait_done();
#endif
}

/*************************************************************************
* FUNCTION
*	effect_dec_colorinv
*
* DESCRIPTION
*	This function provides color invert effect in VIDEO PLAYBACK, IMAGE PLAYBACK
*	and POST-PORCESSING mode.
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
void effect_dec_colorinv(void)
{
	IMGPROC_PIXEL_EFFECT_STURCT pixel_effect_para;
	IMGPROC_GAMMA_STRUCT gma_para;

	/* config Image Processor */
	pixel_effect_para.hsa=IMGPROC_HSA_NONE;
	pixel_effect_para.cba=0;
	pixel_effect_para.inv=1;
	pixel_effect_para.clr=0;
	pixel_effect_para.gma=1;
	gma_para.gamma=0;
	gma_para.off0=0;
	gma_para.off1=0;
	gma_para.off2=0;
	gma_para.off3=0;
	gma_para.off4=0;
	gma_para.off5=0;
	gma_para.off6=0;
	gma_para.off7=0;
	gma_para.slp0=0x10;
	gma_para.slp1=0x10;
	gma_para.slp2=0x10;
	gma_para.slp3=0x10;
	gma_para.slp4=0x10;
	gma_para.slp5=0x10;
	gma_para.slp6=0x10;
	gma_para.slp7=0x10;
	IMGPROC_SetGamma(SCENARIO_IMG_EFFECT_ID, &gma_para);

#if (defined(MT6219)||defined(MT6226)||defined(MT6226M)||defined(MT6226D)||defined(MT6227)||defined(MT6227D))
	/* config Image DMA */
	IMGDMA_Init();
	IMGDMA_Open(SCENARIO_IMG_EFFECT_ID);

	IMGPROC_SetPixelEffect( &pixel_effect_para, SCENARIO_IMG_EFFECT_ID);

	/* start Image Processor */
	IMGPROC_Start(SCENARIO_IMG_EFFECT_ID);

	/* start Image DMA */
	IMGDMA_IBW1Config( &ibw1_para, 1, SCENARIO_IMG_EFFECT_ID);
	IMGDMA_IBR1Config( &ibr1_para, 1, SCENARIO_IMG_EFFECT_ID);

	/* wait Image DMA */
	imgdma_wait_done();

	/* close Image DMA */
	IMGDMA_Close(SCENARIO_IMG_EFFECT_ID);

#elif (defined(MT6228)||defined(MT6229)||defined(MT6230))
	ipp_config_data.pixel_effect_para=pixel_effect_para;
	config_pixel_effect_data_path(&ipp_config_data);
	/* wait Image DMA */
	imgdma_wait_done();
#endif
}

/*************************************************************************
* FUNCTION
*	effect_dec_grayinv
*
* DESCRIPTION
*	This function provides gray color invert effect in VIDEO PLAYBACK,
*	IMAGE PLAYBACK and POST-PORCESSING mode.
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
void effect_dec_grayinv(void)
{
	IMGPROC_PIXEL_EFFECT_STURCT pixel_effect_para;

	/* config Image Processor */
	pixel_effect_para.hsa=IMGPROC_HSA_GRAY;
	pixel_effect_para.cba=0;
	pixel_effect_para.inv=1;
	pixel_effect_para.clr=0;
	pixel_effect_para.gma=0;

#if (defined(MT6219)||defined(MT6226)||defined(MT6226M)||defined(MT6226D)||defined(MT6227)||defined(MT6227D))
	/* config Image DMA */
	IMGDMA_Init();
	IMGDMA_Open(SCENARIO_IMG_EFFECT_ID);

	IMGPROC_SetPixelEffect( &pixel_effect_para, SCENARIO_IMG_EFFECT_ID);

	/* start Image Processor */
	IMGPROC_Start(SCENARIO_IMG_EFFECT_ID);

	/* start Image DMA */
	IMGDMA_IBW1Config( &ibw1_para, 1, SCENARIO_IMG_EFFECT_ID);
	IMGDMA_IBR1Config( &ibr1_para, 1, SCENARIO_IMG_EFFECT_ID);

	/* wait Image DMA */
	imgdma_wait_done();

	/* close Image DMA */
	IMGDMA_Close(SCENARIO_IMG_EFFECT_ID);

#elif (defined(MT6228)||defined(MT6229)||defined(MT6230))
	ipp_config_data.pixel_effect_para=pixel_effect_para;
	config_pixel_effect_data_path(&ipp_config_data);
	/* wait Image DMA */
	imgdma_wait_done();
#endif
}

/*************************************************************************
* FUNCTION
*	effect_dec_watercolor
*
* DESCRIPTION
*	This function provides watercolor effect in VIDEO PLAYBACK,
*	IMAGE PLAYBACK and POST-PORCESSING mode.
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
void effect_dec_watercolor(void)
{
	IMGPROC_MASK_STURCT	filter_coef;

	clean_imgprc_coefficient(SCENARIO_IMG_EFFECT_ID);

	filter_coef.c11=0;
	filter_coef.c12=-1;
	filter_coef.c13=0;
	filter_coef.c21=-1;
	filter_coef.c22=5;
	filter_coef.c23=-1;
	filter_coef.c31=0;
	filter_coef.c32=-1;
	filter_coef.c33=0;

#if (defined(MT6219)||defined(MT6226)||defined(MT6226M)||defined(MT6226D)||defined(MT6227)||defined(MT6227D))
	/* 5 times median + moresharpen */
	DRV_WriteReg32(IMGPROC_START_SRC, image_effect_dec_para.source_buffer_address);
	DRV_WriteReg32(IMGPROC_START_DST, image_effect_dec_para.dest2_buffer_address);
	DRV_WriteReg32(IMGPROC_IMGWIDTH, image_effect_dec_para.image_width);
	DRV_WriteReg32(IMGPROC_IMGHEIGHT, image_effect_dec_para.image_height);
	IMGPROC_SetMask(FILTER_MED, SCENARIO_IMG_EFFECT_ID);
	IMGPROC_Start(SCENARIO_IMG_EFFECT_ID);
	IMGPROC_WaitComplete(SCENARIO_IMG_EFFECT_ID);

	DRV_WriteReg32(IMGPROC_START_SRC, image_effect_dec_para.dest2_buffer_address);
	DRV_WriteReg32(IMGPROC_START_DST, image_effect_dec_para.dest1_buffer_address);
	IMGPROC_Start(SCENARIO_IMG_EFFECT_ID);
	IMGPROC_WaitComplete(SCENARIO_IMG_EFFECT_ID);

	DRV_WriteReg32(IMGPROC_START_SRC, image_effect_dec_para.dest1_buffer_address);
	DRV_WriteReg32(IMGPROC_START_DST, image_effect_dec_para.dest2_buffer_address);
	IMGPROC_Start(SCENARIO_IMG_EFFECT_ID);
	IMGPROC_WaitComplete(SCENARIO_IMG_EFFECT_ID);

	DRV_WriteReg32(IMGPROC_START_SRC, image_effect_dec_para.dest2_buffer_address);
	DRV_WriteReg32(IMGPROC_START_DST, image_effect_dec_para.dest1_buffer_address);
	IMGPROC_Start(SCENARIO_IMG_EFFECT_ID);
	IMGPROC_WaitComplete(SCENARIO_IMG_EFFECT_ID);

	DRV_WriteReg32(IMGPROC_START_SRC, image_effect_dec_para.dest1_buffer_address);
	DRV_WriteReg32(IMGPROC_START_DST, image_effect_dec_para.dest2_buffer_address);
	IMGPROC_Start(SCENARIO_IMG_EFFECT_ID);
	IMGPROC_WaitComplete(SCENARIO_IMG_EFFECT_ID);

	DRV_WriteReg32(IMGPROC_START_SRC, image_effect_dec_para.dest2_buffer_address);
	DRV_WriteReg32(IMGPROC_START_DST, image_effect_dec_para.dest1_buffer_address);
	IMGPROC_SetMask(FILTER_HP, SCENARIO_IMG_EFFECT_ID);
	IMGPROC_SetMaskContent(SCENARIO_IMG_EFFECT_ID, &filter_coef);

	IMGPROC_Start(SCENARIO_IMG_EFFECT_ID);
	IMGPROC_WaitComplete(SCENARIO_IMG_EFFECT_ID);
#elif (defined(MT6228)||defined(MT6229)||defined(MT6230))
	ipp_config_data.filter_mode=IPP_FILTER_MEDIAN_RANKING;
	ipp_config_data.dest_address=image_effect_dec_para.dest2_buffer_address;
	config_filter_effect_data_path(&ipp_config_data);
	IMGPROC_WaitComplete(SCENARIO_IMG_EFFECT_ID);

	ipp_config_data.src_address=image_effect_dec_para.dest2_buffer_address;
	ipp_config_data.dest_address=image_effect_dec_para.dest1_buffer_address;
	config_filter_effect_data_path(&ipp_config_data);
	IMGPROC_WaitComplete(SCENARIO_IMG_EFFECT_ID);

	ipp_config_data.src_address=image_effect_dec_para.dest1_buffer_address;
	ipp_config_data.dest_address=image_effect_dec_para.dest2_buffer_address;
	config_filter_effect_data_path(&ipp_config_data);
	IMGPROC_WaitComplete(SCENARIO_IMG_EFFECT_ID);

	ipp_config_data.src_address=image_effect_dec_para.dest2_buffer_address;
	ipp_config_data.dest_address=image_effect_dec_para.dest1_buffer_address;
	config_filter_effect_data_path(&ipp_config_data);
	IMGPROC_WaitComplete(SCENARIO_IMG_EFFECT_ID);

	ipp_config_data.src_address=image_effect_dec_para.dest1_buffer_address;
	ipp_config_data.dest_address=image_effect_dec_para.dest2_buffer_address;
	config_filter_effect_data_path(&ipp_config_data);
	IMGPROC_WaitComplete(SCENARIO_IMG_EFFECT_ID);

	ipp_config_data.src_address=image_effect_dec_para.dest2_buffer_address;
	ipp_config_data.dest_address=image_effect_dec_para.dest1_buffer_address;
	config_filter_effect_data_path(&ipp_config_data);
	IMGPROC_WaitComplete(SCENARIO_IMG_EFFECT_ID);

	IMGPROC_SetMaskContent(SCENARIO_IMG_EFFECT_ID, &filter_coef);
	ipp_config_data.filter_mode=IPP_FILTER_LINEAR_HP;
	config_filter_effect_data_path(&ipp_config_data);
	IMGPROC_WaitComplete(SCENARIO_IMG_EFFECT_ID);
#endif
}

/*************************************************************************
* FUNCTION
*	effect_dec_lightblur
*
* DESCRIPTION
*	This function provides lightblur effect in VIDEO PLAYBACK,
*	IMAGE PLAYBACK and POST-PORCESSING mode.
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
void effect_dec_lightblur(void)
{
	IMGPROC_MASK_STURCT	filter_coef;

	clean_imgprc_coefficient(SCENARIO_IMG_EFFECT_ID);

	filter_coef.c11=1;
	filter_coef.c12=1;
	filter_coef.c13=1;
	filter_coef.c21=1;
	filter_coef.c22=1;
	filter_coef.c23=1;
	filter_coef.c31=1;
	filter_coef.c32=1;
	filter_coef.c33=1;

#if (defined(MT6219)||defined(MT6226)||defined(MT6226M)||defined(MT6226D)||defined(MT6227)||defined(MT6227D))
	DRV_WriteReg32(IMGPROC_START_SRC, image_effect_dec_para.source_buffer_address);
	DRV_WriteReg32(IMGPROC_START_DST, image_effect_dec_para.dest1_buffer_address);
	DRV_WriteReg32(IMGPROC_IMGWIDTH, image_effect_dec_para.image_width);
	DRV_WriteReg32(IMGPROC_IMGHEIGHT, image_effect_dec_para.image_height);

	IMGPROC_SetMask(FILTER_LP, SCENARIO_IMG_EFFECT_ID);
	IMGPROC_SetMaskContent(SCENARIO_IMG_EFFECT_ID, &filter_coef);
	IMGPROC_Start(SCENARIO_IMG_EFFECT_ID);

	IMGPROC_WaitComplete(SCENARIO_IMG_EFFECT_ID);
#elif (defined(MT6228)||defined(MT6229)||defined(MT6230))
	IMGPROC_SetMaskContent(SCENARIO_IMG_EFFECT_ID, &filter_coef);
	ipp_config_data.filter_mode=IPP_FILTER_LINEAR_LP;
	config_filter_effect_data_path(&ipp_config_data);
	IMGPROC_WaitComplete(SCENARIO_IMG_EFFECT_ID);
#endif
}

/*************************************************************************
* FUNCTION
*	effect_dec_blur
*
* DESCRIPTION
*	This function provides blur effect in VIDEO PLAYBACK,
*	IMAGE PLAYBACK and POST-PORCESSING mode.
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
void effect_dec_blur(void)
{
#if (defined(MT6219)||defined(MT6226)||defined(MT6226M)||defined(MT6226D)||defined(MT6227)||defined(MT6227D))
	clean_imgprc_coefficient(SCENARIO_IMG_EFFECT_ID);

	DRV_WriteReg32(IMGPROC_START_SRC, image_effect_dec_para.source_buffer_address);
	DRV_WriteReg32(IMGPROC_START_DST, image_effect_dec_para.dest1_buffer_address);
	DRV_WriteReg32(IMGPROC_IMGWIDTH, image_effect_dec_para.image_width);
	DRV_WriteReg32(IMGPROC_IMGHEIGHT, image_effect_dec_para.image_height);

	IMGPROC_SetMask(FILTER_BLUR, SCENARIO_IMG_EFFECT_ID);
	IMGPROC_Start(SCENARIO_IMG_EFFECT_ID);

	IMGPROC_WaitComplete(SCENARIO_IMG_EFFECT_ID);
#elif (defined(MT6228)||defined(MT6229)||defined(MT6230))
	ipp_config_data.filter_mode=IPP_FILTER_BLUR;
	config_filter_effect_data_path(&ipp_config_data);
	IMGPROC_WaitComplete(SCENARIO_IMG_EFFECT_ID);
#endif
}

/*************************************************************************
* FUNCTION
*	effect_dec_strongblur
*
* DESCRIPTION
*	This function provides strong blur effect in VIDEO PLAYBACK,
*	IMAGE PLAYBACK and POST-PORCESSING mode.
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
void effect_dec_strongblur(void)
{
#if (defined(MT6219)||defined(MT6226)||defined(MT6226M)||defined(MT6226D)||defined(MT6227)||defined(MT6227D))
	clean_imgprc_coefficient(SCENARIO_IMG_EFFECT_ID);

	DRV_WriteReg32(IMGPROC_START_SRC, image_effect_dec_para.source_buffer_address);
	DRV_WriteReg32(IMGPROC_START_DST, image_effect_dec_para.dest1_buffer_address);
	DRV_WriteReg32(IMGPROC_IMGWIDTH, image_effect_dec_para.image_width);
	DRV_WriteReg32(IMGPROC_IMGHEIGHT, image_effect_dec_para.image_height);

	IMGPROC_SetMask(FILTER_BLUR_MORE, SCENARIO_IMG_EFFECT_ID);
	IMGPROC_Start(SCENARIO_IMG_EFFECT_ID);

	IMGPROC_WaitComplete(SCENARIO_IMG_EFFECT_ID);
#elif (defined(MT6228)||defined(MT6229)||defined(MT6230))
	ipp_config_data.filter_mode=IPP_FILTER_MORE_BLUR;
	config_filter_effect_data_path(&ipp_config_data);
	IMGPROC_WaitComplete(SCENARIO_IMG_EFFECT_ID);
#endif
}

/*************************************************************************
* FUNCTION
*	effect_dec_unsharp
*
* DESCRIPTION
*	This function provides unsharp effect in VIDEO PLAYBACK,
*	IMAGE PLAYBACK and POST-PORCESSING mode.
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
void effect_dec_unsharp(void)
{
	IMGPROC_MASK_STURCT	filter_coef;

	clean_imgprc_coefficient(SCENARIO_IMG_EFFECT_ID);

	filter_coef.c11=1;
	filter_coef.c12=1;
	filter_coef.c13=1;
	filter_coef.c21=1;
	filter_coef.c22=1;
	filter_coef.c23=1;
	filter_coef.c31=1;
	filter_coef.c32=1;
	filter_coef.c33=1;

#if (defined(MT6219)||defined(MT6226)||defined(MT6226M)||defined(MT6226D)||defined(MT6227)||defined(MT6227D))
	DRV_WriteReg32(IMGPROC_START_SRC, image_effect_dec_para.source_buffer_address);
	DRV_WriteReg32(IMGPROC_START_DST, image_effect_dec_para.dest1_buffer_address);
	DRV_WriteReg32(IMGPROC_IMGWIDTH, image_effect_dec_para.image_width);
	DRV_WriteReg32(IMGPROC_IMGHEIGHT, image_effect_dec_para.image_height);

	IMGPROC_SetMask(FILTER_UNSHAP, SCENARIO_IMG_EFFECT_ID);
	IMGPROC_SetMaskContent(SCENARIO_IMG_EFFECT_ID, &filter_coef);
	IMGPROC_Start(SCENARIO_IMG_EFFECT_ID);

	IMGPROC_WaitComplete(SCENARIO_IMG_EFFECT_ID);
#elif (defined(MT6228)||defined(MT6229)||defined(MT6230))
	IMGPROC_SetMaskContent(SCENARIO_IMG_EFFECT_ID, &filter_coef);
	ipp_config_data.filter_mode=IPP_FILTER_UNSHARP;
	config_filter_effect_data_path(&ipp_config_data);
	IMGPROC_WaitComplete(SCENARIO_IMG_EFFECT_ID);
#endif
}

/*************************************************************************
* FUNCTION
*	effect_dec_sharpen
*
* DESCRIPTION
*	This function provides sharpen effect in VIDEO PLAYBACK,
*	IMAGE PLAYBACK and POST-PORCESSING mode.
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
void effect_dec_sharpen(void)
{
	IMGPROC_MASK_STURCT	filter_coef;

	clean_imgprc_coefficient(SCENARIO_IMG_EFFECT_ID);

	filter_coef.c11=0;
	filter_coef.c12=-1;
	filter_coef.c13=0;
	filter_coef.c21=-1;
	filter_coef.c22=7;
	filter_coef.c23=-1;
	filter_coef.c31=0;
	filter_coef.c32=-1;
	filter_coef.c33=0;

#if (defined(MT6219)||defined(MT6226)||defined(MT6226M)||defined(MT6226D)||defined(MT6227)||defined(MT6227D))
	DRV_WriteReg32(IMGPROC_START_SRC, image_effect_dec_para.source_buffer_address);
	DRV_WriteReg32(IMGPROC_START_DST, image_effect_dec_para.dest1_buffer_address);
	DRV_WriteReg32(IMGPROC_IMGWIDTH, image_effect_dec_para.image_width);
	DRV_WriteReg32(IMGPROC_IMGHEIGHT, image_effect_dec_para.image_height);

	IMGPROC_SetMask(FILTER_HP_SCAL, SCENARIO_IMG_EFFECT_ID);
	IMGPROC_SetMaskContent(SCENARIO_IMG_EFFECT_ID, &filter_coef);
	IMGPROC_SetMaskScaleDown(SCENARIO_IMG_EFFECT_ID, 3);
	IMGPROC_Start(SCENARIO_IMG_EFFECT_ID);

	IMGPROC_WaitComplete(SCENARIO_IMG_EFFECT_ID);
#elif (defined(MT6228)||defined(MT6229)||defined(MT6230))
	IMGPROC_SetMaskContent(SCENARIO_IMG_EFFECT_ID, &filter_coef);
	ipp_config_data.filter_mode=IPP_FILTER_LINEAR_HP_SCALE_DOWN;
	config_filter_effect_data_path(&ipp_config_data);
	IMGPROC_WaitComplete(SCENARIO_IMG_EFFECT_ID);
#endif
}

/*************************************************************************
* FUNCTION
*	effect_dec_moresharpen
*
* DESCRIPTION
*	This function provides more sharpen effect in VIDEO PLAYBACK,
*	IMAGE PLAYBACK and POST-PORCESSING mode.
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
void effect_dec_moresharpen(void)
{
	IMGPROC_MASK_STURCT	filter_coef;

	clean_imgprc_coefficient(SCENARIO_IMG_EFFECT_ID);

	filter_coef.c11=0;
	filter_coef.c12=-1;
	filter_coef.c13=0;
	filter_coef.c21=-1;
	filter_coef.c22=5;
	filter_coef.c23=-1;
	filter_coef.c31=0;
	filter_coef.c32=-1;
	filter_coef.c33=0;

#if (defined(MT6219)||defined(MT6226)||defined(MT6226M)||defined(MT6226D)||defined(MT6227)||defined(MT6227D))
	DRV_WriteReg32(IMGPROC_START_SRC, image_effect_dec_para.source_buffer_address);
	DRV_WriteReg32(IMGPROC_START_DST, image_effect_dec_para.dest1_buffer_address);
	DRV_WriteReg32(IMGPROC_IMGWIDTH, image_effect_dec_para.image_width);
	DRV_WriteReg32(IMGPROC_IMGHEIGHT, image_effect_dec_para.image_height);

	IMGPROC_SetMask(FILTER_HP, SCENARIO_IMG_EFFECT_ID);
	IMGPROC_SetMaskContent(SCENARIO_IMG_EFFECT_ID, &filter_coef);
	IMGPROC_Start(SCENARIO_IMG_EFFECT_ID);

	IMGPROC_WaitComplete(SCENARIO_IMG_EFFECT_ID);
#elif (defined(MT6228)||defined(MT6229)||defined(MT6230))
	IMGPROC_SetMaskContent(SCENARIO_IMG_EFFECT_ID, &filter_coef);
	ipp_config_data.filter_mode=IPP_FILTER_LINEAR_HP;
	config_filter_effect_data_path(&ipp_config_data);
	IMGPROC_WaitComplete(SCENARIO_IMG_EFFECT_ID);
#endif
}

/*************************************************************************
* FUNCTION
*	effect_dec_median
*
* DESCRIPTION
*	This function provides median effect in VIDEO PLAYBACK,
*	IMAGE PLAYBACK and POST-PORCESSING mode.
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
void effect_dec_median(void)
{
#if (defined(MT6219)||defined(MT6226)||defined(MT6226M)||defined(MT6226D)||defined(MT6227)||defined(MT6227D))
	clean_imgprc_coefficient(SCENARIO_IMG_EFFECT_ID);

	DRV_WriteReg32(IMGPROC_START_SRC, image_effect_dec_para.source_buffer_address);
	DRV_WriteReg32(IMGPROC_START_DST, image_effect_dec_para.dest1_buffer_address);
	DRV_WriteReg32(IMGPROC_IMGWIDTH, image_effect_dec_para.image_width);
	DRV_WriteReg32(IMGPROC_IMGHEIGHT, image_effect_dec_para.image_height);

	IMGPROC_SetMask(FILTER_MED, SCENARIO_IMG_EFFECT_ID);
	IMGPROC_Start(SCENARIO_IMG_EFFECT_ID);

	IMGPROC_WaitComplete(SCENARIO_IMG_EFFECT_ID);
#elif (defined(MT6228)||defined(MT6229)||defined(MT6230))
	ipp_config_data.filter_mode=IPP_FILTER_MEDIAN_RANKING;
	config_filter_effect_data_path(&ipp_config_data);
	IMGPROC_WaitComplete(SCENARIO_IMG_EFFECT_ID);
#endif
}

/*************************************************************************
* FUNCTION
*	effect_dec_dilation
*
* DESCRIPTION
*	This function provides dilation effect in VIDEO PLAYBACK,
*	IMAGE PLAYBACK and POST-PORCESSING mode.
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
void effect_dec_dilation(void)
{
#if (defined(MT6219)||defined(MT6226)||defined(MT6226M)||defined(MT6226D)||defined(MT6227)||defined(MT6227D))
	clean_imgprc_coefficient(SCENARIO_IMG_EFFECT_ID);

	DRV_WriteReg32(IMGPROC_START_SRC, image_effect_dec_para.source_buffer_address);
	DRV_WriteReg32(IMGPROC_START_DST, image_effect_dec_para.dest1_buffer_address);
	DRV_WriteReg32(IMGPROC_IMGWIDTH, image_effect_dec_para.image_width);
	DRV_WriteReg32(IMGPROC_IMGHEIGHT, image_effect_dec_para.image_height);

	IMGPROC_SetMask(FILTER_MAX, SCENARIO_IMG_EFFECT_ID);
	IMGPROC_Start(SCENARIO_IMG_EFFECT_ID);

	IMGPROC_WaitComplete(SCENARIO_IMG_EFFECT_ID);
#elif (defined(MT6228)||defined(MT6229)||defined(MT6230))
	ipp_config_data.filter_mode=IPP_FILTER_MAXIMUM_RANKING;
	config_filter_effect_data_path(&ipp_config_data);
	IMGPROC_WaitComplete(SCENARIO_IMG_EFFECT_ID);
#endif
}

/*************************************************************************
* FUNCTION
*	effect_dec_erosion
*
* DESCRIPTION
*	This function provides erosion effect in VIDEO PLAYBACK,
*	IMAGE PLAYBACK and POST-PORCESSING mode.
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
void effect_dec_erosion(void)
{
#if (defined(MT6219)||defined(MT6226)||defined(MT6226M)||defined(MT6226D)||defined(MT6227)||defined(MT6227D))
	clean_imgprc_coefficient(SCENARIO_IMG_EFFECT_ID);

	DRV_WriteReg32(IMGPROC_START_SRC, image_effect_dec_para.source_buffer_address);
	DRV_WriteReg32(IMGPROC_START_DST, image_effect_dec_para.dest1_buffer_address);
	DRV_WriteReg32(IMGPROC_IMGWIDTH, image_effect_dec_para.image_width);
	DRV_WriteReg32(IMGPROC_IMGHEIGHT, image_effect_dec_para.image_height);

	IMGPROC_SetMask(FILTER_MIN, SCENARIO_IMG_EFFECT_ID);
	IMGPROC_Start(SCENARIO_IMG_EFFECT_ID);

	IMGPROC_WaitComplete(SCENARIO_IMG_EFFECT_ID);
#elif (defined(MT6228)||defined(MT6229)||defined(MT6230))
	ipp_config_data.filter_mode=IPP_FILTER_MINIMUM_RANKING;
	config_filter_effect_data_path(&ipp_config_data);
	IMGPROC_WaitComplete(SCENARIO_IMG_EFFECT_ID);
#endif
}

/*************************************************************************
* FUNCTION
*	adj_dec_hue
*
* DESCRIPTION
*	This function provides hue adjustment in IMAGE PLAYBACK
*	and POST-PORCESSING mode.
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
void adj_dec_hue(void)
{
	IMGPROC_PIXEL_EFFECT_STURCT pixel_effect_para;
	IMGPROC_HUE_STURCT hue_para;

	/* config Image Processor */
	if(image_adj_dec_para.adj_level==0)
		pixel_effect_para.hsa=IMGPROC_HSA_NONE;
	else
		pixel_effect_para.hsa=IMGPROC_HSA_HUE;
	pixel_effect_para.cba=0;
	pixel_effect_para.inv=0;
	pixel_effect_para.clr=0;
	pixel_effect_para.gma=0;

	if(image_adj_dec_para.adj_level<=90)
	{
		hue_para.c11=sine[90-image_adj_dec_para.adj_level];
		hue_para.c12=sine[image_adj_dec_para.adj_level];
		hue_para.c21=-sine[image_adj_dec_para.adj_level];
		hue_para.c22=sine[90-image_adj_dec_para.adj_level];
	}
	else if(image_adj_dec_para.adj_level>90 && image_adj_dec_para.adj_level<=180)
	{
		hue_para.c11=-sine[image_adj_dec_para.adj_level-90];
		hue_para.c12=sine[180-image_adj_dec_para.adj_level];
		hue_para.c21=-sine[180-image_adj_dec_para.adj_level];
		hue_para.c22=-sine[image_adj_dec_para.adj_level-90];
	}
	else if(image_adj_dec_para.adj_level>180 && image_adj_dec_para.adj_level<=270)
	{
		hue_para.c11=-sine[270-image_adj_dec_para.adj_level];
		hue_para.c12=-sine[image_adj_dec_para.adj_level-180];
		hue_para.c21=sine[image_adj_dec_para.adj_level-180];
		hue_para.c22=-sine[270-image_adj_dec_para.adj_level];
	}
	else if(image_adj_dec_para.adj_level>270 && image_adj_dec_para.adj_level<=360)
	{
		hue_para.c11=sine[image_adj_dec_para.adj_level-270];
		hue_para.c12=-sine[360-image_adj_dec_para.adj_level];
		hue_para.c21=sine[360-image_adj_dec_para.adj_level];
		hue_para.c22=sine[image_adj_dec_para.adj_level-270];
	}
	else
	{
		ASSERT(0);
	}

	IMGPROC_SetHUE(SCENARIO_IMG_EFFECT_ID, &hue_para);

#if (defined(MT6219)||defined(MT6226)||defined(MT6226M)||defined(MT6226D)||defined(MT6227)||defined(MT6227D))
	/* config Image DMA */
	IMGDMA_Open(SCENARIO_IMG_EFFECT_ID);

	IMGPROC_SetPixelEffect( &pixel_effect_para, SCENARIO_IMG_EFFECT_ID);

	/* start Image Processor */
	IMGPROC_Start(SCENARIO_IMG_EFFECT_ID);

	/* start Image DMA */
	IMGDMA_IBW1Config( &ibw1_para, 1, SCENARIO_IMG_EFFECT_ID);
	IMGDMA_IBR1Config( &ibr1_para, 1, SCENARIO_IMG_EFFECT_ID);

	/* wait Image DMA */
	imgdma_wait_done();

	/* close Image DMA */
	IMGDMA_Close(SCENARIO_IMG_EFFECT_ID);

#elif (defined(MT6228)||defined(MT6229)||defined(MT6230))
	ipp_config_data.pixel_effect_para=pixel_effect_para;
	config_pixel_effect_data_path(&ipp_config_data);
	/* wait Image DMA */
	imgdma_wait_done();
#endif
}

/*************************************************************************
* FUNCTION
*	adj_dec_saturation
*
* DESCRIPTION
*	This function provides saturation adjustment in IMAGE PLAYBACK
*	and POST-PORCESSING mode.
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
void adj_dec_saturation(void)
{
	IMGPROC_PIXEL_EFFECT_STURCT pixel_effect_para;

	/* config Image Processor */
	if(image_adj_dec_para.adj_level==128)
		pixel_effect_para.hsa=IMGPROC_HSA_NONE;
	else
		pixel_effect_para.hsa=IMGPROC_HSA_SAT;
	pixel_effect_para.cba=0;
	pixel_effect_para.inv=0;
	pixel_effect_para.clr=0;
	pixel_effect_para.gma=0;
	IMGPROC_SetPixelEffect( &pixel_effect_para, SCENARIO_IMG_EFFECT_ID);

	/* Input data mapping between MMI and driver */
	if(image_adj_dec_para.adj_level<128)
	{
		image_adj_dec_para.adj_level/=4;
	}
	else if(image_adj_dec_para.adj_level>=128 && image_adj_dec_para.adj_level<256)
	{
//		image_adj_dec_para.adj_level=((image_adj_dec_para.adj_level-128)*7/4)+32;
		image_adj_dec_para.adj_level=((image_adj_dec_para.adj_level-128)*3/4)+32;	/* modify for workaround HW bug */
	}
	else
	{
		ASSERT(0);
	}

	IMGPROC_SetSAT(SCENARIO_IMG_EFFECT_ID, (kal_uint8)image_adj_dec_para.adj_level);

#if (defined(MT6219)||defined(MT6226)||defined(MT6226M)||defined(MT6226D)||defined(MT6227)||defined(MT6227D))
	/* config Image DMA */
	IMGDMA_Open(SCENARIO_IMG_EFFECT_ID);

	/* start Image Processor */
	IMGPROC_Start(SCENARIO_IMG_EFFECT_ID);

	/* start Image DMA */
	IMGDMA_IBW1Config( &ibw1_para, 1, SCENARIO_IMG_EFFECT_ID);
	IMGDMA_IBR1Config( &ibr1_para, 1, SCENARIO_IMG_EFFECT_ID);

	/* wait Image DMA */
	imgdma_wait_done();

	/* close Image DMA */
	IMGDMA_Close(SCENARIO_IMG_EFFECT_ID);

#elif (defined(MT6228)||defined(MT6229)||defined(MT6230))
	ipp_config_data.pixel_effect_para=pixel_effect_para;
	config_pixel_effect_data_path(&ipp_config_data);
	/* wait Image DMA */
	imgdma_wait_done();
#endif
}

/*************************************************************************
* FUNCTION
*	adj_dec_gamma
*
* DESCRIPTION
*	This function provides gamma adjustment in IMAGE PLAYBACK
*	and POST-PORCESSING mode.
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
void adj_dec_gamma(void)
{
	IMGPROC_PIXEL_EFFECT_STURCT pixel_effect_para;
	IMGPROC_GAMMA_STRUCT gma_para;

	/* config Image Processor */
	pixel_effect_para.hsa=IMGPROC_HSA_NONE;
	pixel_effect_para.cba=0;
	pixel_effect_para.inv=0;
	pixel_effect_para.clr=0;
	pixel_effect_para.gma=1;
	gma_para.gamma=gamma[image_adj_dec_para.adj_level][0];
	gma_para.off0=gamma[image_adj_dec_para.adj_level][1];
	gma_para.off1=gamma[image_adj_dec_para.adj_level][2];
	gma_para.off2=gamma[image_adj_dec_para.adj_level][3];
	gma_para.off3=gamma[image_adj_dec_para.adj_level][4];
	gma_para.off4=gamma[image_adj_dec_para.adj_level][5];
	gma_para.off5=gamma[image_adj_dec_para.adj_level][6];
	gma_para.off6=gamma[image_adj_dec_para.adj_level][7];
	gma_para.off7=gamma[image_adj_dec_para.adj_level][8];
	gma_para.slp0=gamma[image_adj_dec_para.adj_level][9];
	gma_para.slp1=gamma[image_adj_dec_para.adj_level][10];
	gma_para.slp2=gamma[image_adj_dec_para.adj_level][11];
	gma_para.slp3=gamma[image_adj_dec_para.adj_level][12];
	gma_para.slp4=gamma[image_adj_dec_para.adj_level][13];
	gma_para.slp5=gamma[image_adj_dec_para.adj_level][14];
	gma_para.slp6=gamma[image_adj_dec_para.adj_level][15];
	gma_para.slp7=gamma[image_adj_dec_para.adj_level][16];

	IMGPROC_SetGamma(SCENARIO_IMG_EFFECT_ID, &gma_para);

#if (defined(MT6219)||defined(MT6226)||defined(MT6226M)||defined(MT6226D)||defined(MT6227)||defined(MT6227D))
	/* config Image DMA */
	IMGDMA_Open(SCENARIO_IMG_EFFECT_ID);

	IMGPROC_SetPixelEffect( &pixel_effect_para, SCENARIO_IMG_EFFECT_ID);

	/* start Image Processor */
	IMGPROC_Start(SCENARIO_IMG_EFFECT_ID);

	/* start Image DMA */
	IMGDMA_IBW1Config( &ibw1_para, 1, SCENARIO_IMG_EFFECT_ID);
	IMGDMA_IBR1Config( &ibr1_para, 1, SCENARIO_IMG_EFFECT_ID);

	/* wait Image DMA */
	imgdma_wait_done();

	/* close Image DMA */
	IMGDMA_Close(SCENARIO_IMG_EFFECT_ID);

#elif (defined(MT6228)||defined(MT6229)||defined(MT6230))
	ipp_config_data.pixel_effect_para=pixel_effect_para;
	config_pixel_effect_data_path(&ipp_config_data);
	/* wait Image DMA */
	imgdma_wait_done();
#endif
}

/*************************************************************************
* FUNCTION
*	adj_dec_coloradj
*
* DESCRIPTION
*	This function provides coloradj adjustment in IMAGE PLAYBACK
*	and POST-PORCESSING mode.
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
void adj_dec_coloradj(void)
{
	IMGPROC_PIXEL_EFFECT_STURCT pixel_effect_para;
	IMGPROC_COLORIZE_STRUCT clr_para;

	/* config Image Processor */
	pixel_effect_para.hsa=IMGPROC_HSA_NONE;
	pixel_effect_para.cba=0;
	pixel_effect_para.inv=0;
	pixel_effect_para.clr=1;
	pixel_effect_para.gma=0;

	if(image_adj_dec_para.effect_index==CAM_ADJ_DEC_ADJR)
	{
		clr_para.r1x=coloradj_rb[image_adj_dec_para.adj_level][0];
		clr_para.r1y=coloradj_rb[image_adj_dec_para.adj_level][1];
		clr_para.r2x=coloradj_rb[image_adj_dec_para.adj_level][2];
		clr_para.r2y=coloradj_rb[image_adj_dec_para.adj_level][3];
		clr_para.r0slp=coloradj_rb[image_adj_dec_para.adj_level][4];
		clr_para.r1slp=coloradj_rb[image_adj_dec_para.adj_level][5];
		clr_para.r2slp=coloradj_rb[image_adj_dec_para.adj_level][6];
		clr_para.g1x=0;
		clr_para.g1y=0;
		clr_para.g2x=0;
		clr_para.g2y=0;
		clr_para.g0slp=16;
		clr_para.g1slp=16;
		clr_para.g2slp=16;
		clr_para.b1x=0;
		clr_para.b1y=0;
		clr_para.b2x=0;
		clr_para.b2y=0;
		clr_para.b0slp=16;
		clr_para.b1slp=16;
		clr_para.b2slp=16;
	}
	else if(image_adj_dec_para.effect_index==CAM_ADJ_DEC_ADJG)
	{
		clr_para.r1x=0;
		clr_para.r1y=0;
		clr_para.r2x=0;
		clr_para.r2y=0;
		clr_para.r0slp=16;
		clr_para.r1slp=16;
		clr_para.r2slp=16;
		clr_para.g1x=coloradj_g[image_adj_dec_para.adj_level][0];
		clr_para.g1y=coloradj_g[image_adj_dec_para.adj_level][1];
		clr_para.g2x=coloradj_g[image_adj_dec_para.adj_level][2];
		clr_para.g2y=coloradj_g[image_adj_dec_para.adj_level][3];
		clr_para.g0slp=coloradj_g[image_adj_dec_para.adj_level][4];
		clr_para.g1slp=coloradj_g[image_adj_dec_para.adj_level][5];
		clr_para.g2slp=coloradj_g[image_adj_dec_para.adj_level][6];
		clr_para.b1x=0;
		clr_para.b1y=0;
		clr_para.b2x=0;
		clr_para.b2y=0;
		clr_para.b0slp=16;
		clr_para.b1slp=16;
		clr_para.b2slp=16;
	}
	else if(image_adj_dec_para.effect_index==CAM_ADJ_DEC_ADJB)
	{
		clr_para.r1x=0;
		clr_para.r1y=0;
		clr_para.r2x=0;
		clr_para.r2y=0;
		clr_para.r0slp=16;
		clr_para.r1slp=16;
		clr_para.r2slp=16;
		clr_para.g1x=0;
		clr_para.g1y=0;
		clr_para.g2x=0;
		clr_para.g2y=0;
		clr_para.g0slp=16;
		clr_para.g1slp=16;
		clr_para.g2slp=16;
		clr_para.b1x=coloradj_rb[image_adj_dec_para.adj_level][0];
		clr_para.b1y=coloradj_rb[image_adj_dec_para.adj_level][1];
		clr_para.b2x=coloradj_rb[image_adj_dec_para.adj_level][2];
		clr_para.b2y=coloradj_rb[image_adj_dec_para.adj_level][3];
		clr_para.b0slp=coloradj_rb[image_adj_dec_para.adj_level][4];
		clr_para.b1slp=coloradj_rb[image_adj_dec_para.adj_level][5];
		clr_para.b2slp=coloradj_rb[image_adj_dec_para.adj_level][6];
	}

	IMGPROC_SetColorize(SCENARIO_IMG_EFFECT_ID, &clr_para);
#if (defined(MT6219)||defined(MT6226)||defined(MT6226M)||defined(MT6226D)||defined(MT6227)||defined(MT6227D))
	/* config Image DMA */
	IMGDMA_Open(SCENARIO_IMG_EFFECT_ID);

	IMGPROC_SetPixelEffect( &pixel_effect_para, SCENARIO_IMG_EFFECT_ID);

	/* start Image Processor */
	IMGPROC_Start(SCENARIO_IMG_EFFECT_ID);

	/* start Image DMA */
	IMGDMA_IBW1Config( &ibw1_para, 1, SCENARIO_IMG_EFFECT_ID);
	IMGDMA_IBR1Config( &ibr1_para, 1, SCENARIO_IMG_EFFECT_ID);

	/* wait Image DMA */
	imgdma_wait_done();

	/* close Image DMA */
	IMGDMA_Close(SCENARIO_IMG_EFFECT_ID);

#elif (defined(MT6228)||defined(MT6229)||defined(MT6230))
	ipp_config_data.pixel_effect_para=pixel_effect_para;
	config_pixel_effect_data_path(&ipp_config_data);
	/* wait Image DMA */
	imgdma_wait_done();
#endif
}

/*************************************************************************
* FUNCTION
*	adj_dec_brightness_contrast
*
* DESCRIPTION
*	This function provides brightness and contrast adjustment in IMAGE PLAYBACK
*	and POST-PORCESSING mode.
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
void adj_dec_brightness_contrast(void)
{
	IMGPROC_PIXEL_EFFECT_STURCT pixel_effect_para;
	IMGPROC_BRI_CON_STURCT cba_para;

	/* config Image Processor */
	pixel_effect_para.hsa=IMGPROC_HSA_NONE;
	if(image_adj_dec_para.adj_level==128)
		pixel_effect_para.cba=0;
	else
		pixel_effect_para.cba=1;
	pixel_effect_para.inv=0;
	pixel_effect_para.clr=0;
	pixel_effect_para.gma=0;

	if(image_adj_dec_para.effect_index==CAM_ADJ_DEC_BRIGHTNESS)
	{
		if(image_adj_dec_para.adj_level>=128 && image_adj_dec_para.adj_level<256)
		{
			cba_para.bright=(image_adj_dec_para.adj_level-128)<<1;
		 	cba_para.dark=0;
		}
		else if(image_adj_dec_para.adj_level<128)
		{
 			cba_para.dark=((128-image_adj_dec_para.adj_level)<<1)-1;
		 	cba_para.bright=0;
 		}
 		else
 		{
 			ASSERT(0);
 		}
 		cba_para.contrast=32;
 	}
 	else if(image_adj_dec_para.effect_index==CAM_ADJ_DEC_CONTRAST)
 	{
		/* Input data mapping between MMI and driver */
		if(image_adj_dec_para.adj_level<128)
		{
			image_adj_dec_para.adj_level/=4;
		}
		else if(image_adj_dec_para.adj_level>=128 && image_adj_dec_para.adj_level<256)
		{
//			image_adj_dec_para.adj_level=((image_adj_dec_para.adj_level-128)*7/4)+32;
			image_adj_dec_para.adj_level=((image_adj_dec_para.adj_level-128)*3/4)+32;	// decrease maximum contrast gain
		}
	 	else
	 	{
	 		ASSERT(0);
	 	}
	 	cba_para.contrast=image_adj_dec_para.adj_level;
	 	cba_para.bright=0;
	 	cba_para.dark=0;
 	}

	IMGPROC_SetBrightContrast(SCENARIO_IMG_EFFECT_ID, &cba_para);
#if (defined(MT6219)||defined(MT6226)||defined(MT6226M)||defined(MT6226D)||defined(MT6227)||defined(MT6227D))
	/* config Image DMA */
	IMGDMA_Open(SCENARIO_IMG_EFFECT_ID);

	IMGPROC_SetPixelEffect( &pixel_effect_para, SCENARIO_IMG_EFFECT_ID);

	/* start Image Processor */
	IMGPROC_Start(SCENARIO_IMG_EFFECT_ID);

	/* start Image DMA */
	IMGDMA_IBW1Config( &ibw1_para, 1, SCENARIO_IMG_EFFECT_ID);
	IMGDMA_IBR1Config( &ibr1_para, 1, SCENARIO_IMG_EFFECT_ID);

	/* wait Image DMA */
	imgdma_wait_done();

	/* close Image DMA */
	IMGDMA_Close(SCENARIO_IMG_EFFECT_ID);

#elif (defined(MT6228)||defined(MT6229)||defined(MT6230))
	ipp_config_data.pixel_effect_para=pixel_effect_para;
	config_pixel_effect_data_path(&ipp_config_data);
	/* wait Image DMA */
	imgdma_wait_done();
#endif
}

/*************************************************************************
* FUNCTION
*	clean_imgprc_coefficient
*
* DESCRIPTION
*	Clean Hue, Saturation, Brightness and Contrast coefficients in image
*	processor
*
* PARAMETERS
*	MMDI_SCENERIO_ID
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void clean_imgprc_coefficient(MMDI_SCENERIO_ID owner_id)
{
#if (defined(MT6219)||defined(MT6226)||defined(MT6226M)||defined(MT6226D)||defined(MT6227)||defined(MT6227D))
	adjustment_hue_para(owner_id, 0);
	adjustment_saturation_para(owner_id, 128);
	adjustment_brightness_para(owner_id, 128);
	adjustment_contrast_para(owner_id, 128);
#endif
}

void imgdma_wait_done(void)
{
	volatile kal_uint8 i;

	while (IBW1_COMPLETE_FLAG!=1)
	{
//		kal_sleep_task(1);
		for(i=0;i<0x10;i++);
	};
}

void imgdma_ibw1_callback(void)
{
	IBW1_COMPLETE_FLAG=1;
}
#endif

