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

/*******************************************************************************
 * Filename:
 * ---------
 *	 gdi_animate.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Animate API
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
* $ Log $
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _GDI_ANIMATE_H_
#define _GDI_ANIMATE_H_

/****************************************************************************
* Define
*****************************************************************************/
typedef enum
{
	GDI_ANIM_FLAG_IS_FREE,
	GDI_ANIM_FLAG_IS_ANIMATING,
	GDI_ANIM_FLAG_IS_STOP_AFTER_CALLBACK
} gdi_anim_used_enum;

typedef struct {
	S32					serial_id;
	S32					offset_x;								/* draw position x */
	S32					offset_y;								/* draw position y */
	S32					resized_width;
	S32					resized_height;
	U32					image_length;							/* length of gif data */
	U32					img_flag;
	U8					*image_ptr;								/* pointer to start of gif raw data */
	void					(*callback)(GDI_RESULT result);	/* call back funtion when animation finished [MUST init]*/
    void					(*draw_before_callback)(GDI_RESULT result);   /* Invoke calback function before image is decode */
	void					(*blt_before_callback)(GDI_RESULT result);	/* call back funtion when animation frame before blt [MUST init]*/
	void					(*blt_after_callback)(GDI_RESULT result);	/* call back funtion when animation frame after blt [MUST init]*/
	gdi_handle			layer_handle;							/* draw on which layer */
	gdi_handle			lcd_handle;								/* play on which lcd */	
	S16					clipx1,clipy1,clipx2,clipy2;
	U16					width;									/* width of this animation */
	U16					height;									/* height of this animation */
	U32					start_frame;							/* start frame when not play from the start */
	U32					frame_index;							/* next frame index */
	U32					frames;									// total frames
	gdi_anim_used_enum	is_used;									/* this slot is use or not [MUST init] */ 
	S32     			anim_count;							/* -1 means loop forever */
	gdi_image_src_enum	src_type;
	gdi_anim_pos_type_enum pos_type;
    gdi_handle          job_handle;
	U8					image_identifier;
} gdi_image_anim_struct;


typedef struct
{
	gdi_image_anim_struct	anim_list[GDI_ANIM_COUNT];
	void								(*anim_callback)(GDI_RESULT result);
    void								(*anim_draw_before_callback)(GDI_RESULT result);
	void								(*anim_blt_before_callback)(GDI_RESULT result);
	void								(*anim_blt_after_callback)(GDI_RESULT result);
     
    BOOL                    disable_blt;
    S32                     anim_count;
} gdi_anim_cntx_struct;


/****************************************************************************
* Function
*****************************************************************************/
extern void gdi_anim_init(void);
extern void gdi_anim_set_delay(U32 delay);
extern GDI_RESULT gdi_anim_stop_all_by_layer(gdi_handle layer);
extern GDI_RESULT gdi_anim_set_job_handle(gdi_handle anim_handle,gdi_handle job_handle);
extern GDI_RESULT gdi_anim_stop_by_job_handle(gdi_handle job_handle);
extern GDI_RESULT gdi_anim_stop_by_all_job_handle(void);
extern S32 gdi_anim_get_current_frame_number(gdi_handle serial_handle);
#endif /* _GDI_ANIMATE_H_ */


