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
 *   image_effect.h
 *
 * Project:
 * --------
 *   MT6219,MT6226,MT6227,MT6228,MT6229
 *
 * Description:
 * ------------
 *   Header file of iamge_effect
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if (defined(ISP_SUPPORT)&&(!defined(MT6225)))
#ifndef _IMAGE_EFFECT_H
#define _IMAGE_EFFECT_H

typedef struct
{
	kal_uint8	data_type; 							/* RGB565 or RGB888 */
	kal_uint8	data_order; 						/* BGR888 or RGB888 */
	kal_uint8	src_color_mode;					/* IPP_COLOR_RGB565 or IPP_COLOR_RGB888 */
	kal_uint8	src_color_order;					/* BGR888 or RGB888 */
	kal_uint8	dest_color_mode;					/* IMGDMA_IBW_OUTPUT_RGB565 or IMGDMA_IBW_OUTPUT_RGB888 */
	kal_uint32	source_buffer_address;			/* source buffer address for image input */
	kal_uint32	dest1_buffer_address;			/* first destination buffer address for image output */
	kal_uint32	dest2_buffer_address;			/* second destination buffer address for temporary image */
	kal_uint16	image_width;						/* image width for image effect processing */
	kal_uint16	image_height;						/* image height for image effect processing */
	kal_uint8	effect_index;						/* one of the special effect enum */
	kal_uint16	adj_level;							/* level of adjustment effect */
	void (*image_effect_dec_cb) (kal_uint8 return_code);	/* call back function for iamge effect */
}	IMAGE_EFFECT_DEC_STRUCT;

/* Prototype */
void image_effect_enc_handler(void);
void effect_enc_normal(void);
void effect_enc_grayscale(void);
void effect_enc_sepia(void);
void effect_enc_sepiagreen(void);
void effect_enc_sepiablue(void);
void effect_enc_colorinv(void);
void effect_enc_grayinv(void);
void effect_enc_blackboard(void);
void effect_enc_whiteboard(void);
void effect_enc_coppercarving(void);
void effect_enc_embossment(void);
void effect_enc_bluecarving(void);
void effect_enc_contrast(void);
void effect_enc_jean(void);
void effect_enc_sketch(void);
void effect_enc_oil(void);

void image_effect_dec_handler(void);
void effect_dec_grayscale(void);
void effect_dec_sepia(void);
void effect_dec_sepiagreen(void);
void effect_dec_sepiablue(void);
void effect_dec_colorinv(void);
void effect_dec_grayinv(void);
void effect_dec_watercolor(void);
void effect_dec_lightblur(void);
void effect_dec_blur(void);
void effect_dec_strongblur(void);
void effect_dec_unsharp(void);
void effect_dec_sharpen(void);
void effect_dec_moresharpen(void);
void effect_dec_median(void);
void effect_dec_dilation(void);
void effect_dec_erosion(void);

void image_adj_dec_handler(void);
void adj_dec_hue(void);
void adj_dec_saturation(void);
void adj_dec_gamma(void);
void adj_dec_coloradj(void);
void adj_dec_brightness_contrast(void);
void imgdma_wait_done(void);
void imgdma_ibw1_callback(void);

/* Interface API */
void image_effect_enc_process(kal_uint8 effect_enc);
void image_effect_dec_process(IMAGE_EFFECT_DEC_STRUCT *effect_dec_para);
void image_adj_dec_process(IMAGE_EFFECT_DEC_STRUCT *effect_dec_para);
void adjustment_hue_para(MMDI_SCENERIO_ID owner_id, kal_uint16 degree);
void adjustment_saturation_para(MMDI_SCENERIO_ID owner_id, kal_uint8 sat_value);
void adjustment_gamma_para(MMDI_SCENERIO_ID owner_id, kal_uint8 adj_level);
void adjustment_coloradj_r_para(MMDI_SCENERIO_ID owner_id, kal_uint8 adj_level);
void adjustment_coloradj_g_para(MMDI_SCENERIO_ID owner_id, kal_uint8 adj_level);
void adjustment_coloradj_b_para(MMDI_SCENERIO_ID owner_id, kal_uint8 adj_level);
void adjustment_brightness_para(MMDI_SCENERIO_ID owner_id, kal_uint8 brightness_value);
void adjustment_contrast_para(MMDI_SCENERIO_ID owner_id, kal_uint8 contrast_value);
void adjustment_brightness_contrast_para(MMDI_SCENERIO_ID owner_id, kal_uint8 brightness_value, kal_uint8 contrast_value);
void clean_imgprc_coefficient(MMDI_SCENERIO_ID owner_id);
void adjustment_brightness_video_encode(kal_uint8 brightness_value);
void adjustment_brightness_video_decode(kal_uint8 brightness_value);
void adjustment_contrast_video_encode(kal_uint8 contrast_value);
void adjustment_contrast_video_decode(kal_uint8 contrast_value);

#endif /* _IMAGE_EFFECT_H */
#endif /* MT6219 && ISP_SUPPORT */


