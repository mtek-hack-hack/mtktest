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
 *   swimg_resizer.h
 *
 *
 * Description:
 * ------------
 *   software resizer functions
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
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#ifndef _SWIMG_RESIZER_H_
#define _SWIMG_RESIZER_H_
#include "image.h"

#define SWIMG_LIB_SUPPORT

#define SWIMG_RESIZER_SCALE_BITS 19
// for color format
#define RGB565(r,g,b) ((r&0xF8)<<8)|((g&0xFC)<<3)|(b>>3)
#define RED(value) ((value&0xF800)>>8)  //extract the red value from RGB565
#define GREEN(value) ((value&0x7E0)>>3) //extract the green value from RGB565
#define BLUE(value)  ((value&0x1F)<<3)  //extract the blue value from RGB565
#define RGB2Y(r,g,b) ((306*r+601*g+117*b)>>10)
#define RGB2CB(b,y)  ((((b-y)*579)>>10)+128)
#define RGB2CR(r,y)  ((((r-y)*730)>>10)+128)
#define YUV2R(y,cr)  (((y<<10)+ 1436*(cr-128))>>10)
#define YUV2G(y,cb,cr) (((y<<10)-352*(cb-128)-731*(cr-128))>>10)
#define YUV2B(y,cb)   (((y<<10)+1815*(cb-128))>>10)
#define FOUR_BYTE_ALIGN(size)  (((size+3)>>2)*4)
//

typedef enum
{
 SWIMG_RESIZER_SUCCESS,
 SWIMG_RESIZER_FAIL,
 SWIMG_RESIZER_BUFF_INSUFFICIENT,
 SWIMG_RESIZER_FUNC_NOT_SUPPORT,
 SWIMG_RESIZER_IS_BUSY,
 SWIMG_RESIZER_PARTIAL_SIZE_ERROR,
 SWIMG_RESIZER_NEED_INIT_ERROR,
 SWIMG_RESIZER_INIT_ARGUMENT_ERROR
}SWIMG_RESIZER_STATUS_ENUM;

typedef enum
{
 SWIMG_Y_DD_RESIZE_RGB565,
 SWING_YUV420_DD_RESIZE_RGB565,     /*Drop & Duplicate Resizing*/
 SWIMG_YUV420_BYPASS_RESIZE_RGB565, /*Bypass resize, color space transformation */
 SWIMG_YUV420_IP_RESIZE_RGB565,     /*Interpolation Resize*/
//Remind: The below doesn't support block resize.
 SWIMG_Y_DD_RESIZE_YUV420,
 SWIMG_RGB565_DD_RESIZE_YUV420,     /*Drop & Duplicate Resizing*/
 SWIMG_RGB565_BYPASS_RESIZE_YUV420, /*Bypass resize, color space transformation */
 SWIMG_RGB565_IP_RESIZE_YUV420      /*Interpolation Resize*/
}SWIMG_RESIZER_FUNC_ENUM;

typedef struct
{
   SWIMG_RESIZER_FUNC_ENUM resize_func;
   IMAGE_FORMAT_ENUM input_type;    /* IMAGE_FORMAT_YUV420 */
   IMAGE_FORMAT_ENUM output_type;   /* IMAGE_FORMAT_RGB565 */

   kal_uint32  tar_width;           /* the width of target image */
   kal_uint32  tar_height;          /* the height of target image */
   kal_uint32  src_width;
   kal_uint32  src_height;

   kal_uint32  partial_x_size,partial_y_size;      /* dimension of input_data each time when calling swimg_resize_process */
   kal_uint32  input_buff_width[3];                /* Pitch bytes of each component*/

   kal_uint8*  output_buff;
   kal_uint32  output_buff_size;

   kal_uint8* upYOut;               // The output in Y channel
   kal_uint8* upUOut;               // The output in U channel
   kal_uint8* upVOut;               // The output in V channel
   kal_uint32 uYSize;               // The size of Y channel

   kal_bool image_pitch_mode;       /* KAL_TRUE or KAL_FALSE for block mode of decoded image */
   kal_uint32 image_pitch_bytes; /* pitch width */
   kal_uint32 image_clip_x1;        /* clip window start x for clipping decoded image */
   kal_uint32 image_clip_x2;        /* clip window end x for clipping decoded image */
   kal_uint32 image_clip_y1;        /* clip window start y for clipping decoded image */
   kal_uint32 image_clip_y2;        /* clip window end y for clipping decoded image */

   void* (*get_buffer_func)(kal_uint32);
} swimg_resizer_config_struct;

typedef struct
{
   swimg_resizer_config_struct cfg;
   kal_bool is_busy;

   kal_uint32 h_ratio;
   kal_uint32 v_ratio;

   kal_uint32  x_blk_cnt;
   kal_uint32  y_blk_cnt;
   kal_uint32  x_blk_num;
   kal_uint32  y_blk_num;

   kal_uint32  clip_x1;       /* clip window start x for clipping decoded image */
   kal_uint32  clip_x2;       /* clip window end x for clipping decoded image */
   kal_uint32  clip_y1;       /* clip window start y for clipping decoded image */
   kal_uint32  clip_y2;       /* clip window end y for clipping decoded image */
   kal_uint32  image_buffer_width;

}swimg_resizer_dcb_struct;

// for fully image resizer structure, added by BaoZen Shaw.
typedef struct swimg_fully_resize_struct
{
   IMAGE_FORMAT_ENUM InputType;    // IMAGE_FORMAT_RGB565 */
   IMAGE_FORMAT_ENUM OutputType;   // IMAGE_FORMAT_YUV420 */
   kal_uint32 uTarWidth;           // the width of target image */
   kal_uint32 uTarHeight;          // the height of target image */
   kal_uint32 uSrcWidth;           // the width of src image
   kal_uint32 uSrcHeight;          // the height of src image
   kal_uint8 *upYOut;              // The output in Y channel
   kal_uint8 *upUOut;              // The output in U channel
   kal_uint8 *upVOut;              // The output in V channel
   kal_uint32 uYSize;              // The size of Y channel
   kal_uint32 uMemStartAddress;    // memory pool start address
   kal_uint32 uMemSize;            // memory pool size
} SWIMG_RESIZE_INFO;


typedef struct
{
   kal_uint32 *int_ram_start_ptr;
   kal_uint32 int_ram_total_length;
   kal_uint32 int_ram_index;
   kal_bool   int_ram_init;
} SWIMG_MEM_STRUCT;


#define SATURATE_ZERO(value)     (~((signed int)(value) >> 31) & (value))


/// lower must equals to 0
#define RANGE_LIMIT(lower, upper, s)   ((s) > (upper)) ? (upper) : (SATURATE_ZERO(s))

/*
#define RANGE_LIMIT(lower, upper, s)   \
{                                      \
   if (s > upper)                      \
   {                                   \
      r = upper;                       \
   }                                   \
   else                                \
   {                                   \
      r = SATURATE_ZERO(s);            \
   }                                   \
}
*/



/* APIs */
SWIMG_RESIZER_STATUS_ENUM swimg_resizer_init(swimg_resizer_config_struct* swimg_resizer_cfg);
SWIMG_RESIZER_STATUS_ENUM swimg_resizer_deinit(void);
//The fallow two functions for fully block resize
SWIMG_RESIZER_STATUS_ENUM swimg_fully_resize_init(SWIMG_RESIZE_INFO* SwImgResizeInfo);
SWIMG_RESIZER_STATUS_ENUM swimg_fully_resize_deinit(void);
kal_uint32 swimg_get_require_msm_size( kal_uint16 uTarX, kal_uint16 uTarY);

kal_bool    swimg_resizer_is_this_row_needded(kal_uint32 compID,kal_uint32 row);
kal_bool    swimg_resizer_is_this_col_needded(kal_uint32 compID,kal_uint32 col);
kal_bool    swimg_resizer_is_this_blk_needded(kal_uint32 y_blk,kal_uint32 x_blk);
kal_bool    swimg_resizer_is_next_blk_needed(void);
kal_bool*   swimg_resize_get_src_row_need_tbl(void);
kal_bool*   swimg_resize_get_src_col_need_tbl(void);
kal_uint32 swimg_resize_get_resize_ratio(void);
kal_bool get_swimg_resizer_status(void);
//extern SWIMG_RESIZER_STATUS_ENUM (*swimg_resizer_put_data)(kal_uint8**);
extern SWIMG_RESIZER_STATUS_ENUM (*swimg_resizer_put_data)(void*);
#endif //_SWIMG_RESIZER_H_
