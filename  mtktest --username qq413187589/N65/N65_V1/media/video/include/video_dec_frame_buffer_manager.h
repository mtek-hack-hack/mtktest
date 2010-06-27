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
 *
 * Filename:
 * ---------
 *   video_dec_frame_buffer_manager.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Video frame buffer management
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef VIDEO_DEC_FRAME_BUFFER_MANAGER_H
#define VIDEO_DEC_FRAME_BUFFER_MANAGER_H

/* frame buffer mode*/
typedef enum
{
    MPEG4_FRAME_BUFFER_NORMAL_MODE,
    MPEG4_FRAME_BUFFER_MEMORY_MODE
}MPEG4_FRAME_BUFFER_MODE;

/* Config frame buffer mode.  
* @param frame_buffer_mode MPEG4_FRAME_BUFFER_MODE(normal and memory mode)
* @return None
*/
extern void mpeg4_dec_config_frame_buffer_mode(MPEG4_FRAME_BUFFER_MODE frame_buffer_mode, kal_uint32 prev_display_addr);


/* Set current display frame address. 
* @param frame buffer start address
* @return None
*/
extern void  mpeg4_dec_set_display_frame_addr(kal_uint32 frame_addr);


/* Get current display frame address. 
* @param None
* @return frame buffer start address
*/
extern kal_uint32 mpeg4_dec_get_display_frame_addr(void);


/* Get previous display frame address. 
* @param None
* @return frame buffer start address
*/
extern kal_uint32 mpeg4_dec_get_prev_display_frame_addr(void);


#ifdef DRV_MP4_V2

#define MPEG4_FRAME_BUFFER_COUNT   5 //This is minimum number

/* frame buffer control structure */
typedef struct
{
    kal_uint32 frame_buffer_addr[MPEG4_FRAME_BUFFER_COUNT]; 
    kal_uint32 frame_buffer_size;
    kal_uint8 rec_frame_index;
    kal_uint8 max_frame_buffer_count;
    MPEG4_FRAME_BUFFER_MODE frame_buffer_mode;
} MPEG4_FRAME_BUFFER_CTRL_STRUCT;

/* real frame buffer type and address */
typedef struct
{
    kal_uint32 rec_addr;
    kal_uint32 ref_addr;
    kal_uint32 deblock_addr;
} MPEG4_FRAME_BUFFER_ADDR;


/* Init frame buffer.
* @param max_width  frame buffer width
* @param max_height  frame buffer height
* @return None
*/
extern void mpeg4_dec_frame_buffer_init(kal_uint16 max_width, kal_uint16 max_height);


/* Init frame buffer memory as zero 
* @param None
* @return None
*/
extern void mpeg4_dec_frame_buffer_init_value(void);


/* Get next frame buffer setting according to current rec frame index
* @param frame_buffer  MPEG4_FRAME_BUFFER_ADDR
* @return None
*/
extern void mpeg4_dec_frame_buffer_next(MPEG4_FRAME_BUFFER_ADDR * frame_buffer);


/* Get curernt frame buffer setting according to current rec frame index
* @param frame_buffer  MPEG4_FRAME_BUFFER_ADDR
* @return None
*/
extern void mpeg4_dec_frame_buffer_current(MPEG4_FRAME_BUFFER_ADDR * frame_buffer);


/* Get previous frame buffer setting according to current index
* @param frame_buffer  MPEG4_FRAME_BUFFER_ADDR
* @return None
*/
extern void mpeg4_dec_frame_buffer_prev(MPEG4_FRAME_BUFFER_ADDR * frame_buffer);


/* Sort frame buffer according to the rec_addr input
* @param rec_addr  sort according to the rec address
* @param frame_buffer  MPEG4_FRAME_BUFFER_ADDR
* @return None
*/
extern void mpeg4_dec_sort_frame_buffer(kal_uint32 rec_addr, MPEG4_FRAME_BUFFER_ADDR * frame_buffer);


/* Sort frame buffer according to the rec_addr input, and get next frame buffer setting.
* @param rec_addr  sort according to the rec address
* @param frame_buffer  MPEG4_FRAME_BUFFER_ADDR
* @return None
*/
extern void mpeg4_dec_sort_frame_buffer_next(kal_uint32 rec_addr, MPEG4_FRAME_BUFFER_ADDR * frame_buffer);


/* Sort frame buffer according to the rec_addr input, and get previous frame buffer setting.
* @param rec_addr  sort according to the rec address
* @param frame_buffer  MPEG4_FRAME_BUFFER_ADDR
* @return None
*/
extern void mpeg4_dec_sort_frame_buffer_prev(kal_uint32 rec_addr, MPEG4_FRAME_BUFFER_ADDR * frame_buffer);

#endif  /*DRV_MP4_V2*/

#endif /*VIDEO_DEC_FRAME_BUFFER_MANAGER_H*/
