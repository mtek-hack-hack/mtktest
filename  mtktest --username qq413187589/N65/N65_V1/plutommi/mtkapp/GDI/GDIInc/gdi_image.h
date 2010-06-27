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
 *  gdi_image.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI Image header file.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _GDI_IMAGE_H_
#define _GDI_IMAGE_H_

/****************************************************************************
* Define                                                              
*****************************************************************************/
#define GDI_IMAGE_CODEC_TIMEOUT  6 // seconds

/****************************************************************************
* Struct / Typedef                                                                 
*****************************************************************************/

typedef struct
{
    GDI_RESULT(*draw_before) (U32 flag, U32 frame_pos, S32 x, S32 y, S32 w, S32 h, U8 *data_ptr, U32 img_size);
    GDI_RESULT(*draw) (U32 flag, U32 frame_pos, S32 x, S32 y, S32 w, S32 h, U8 *data_ptr, U32 img_size);
    GDI_RESULT(*draw_after) (U32 flag, U32 frame_pos, S32 x, S32 y, S32 w, S32 h, U8 *data_ptr, U32 img_size);
    GDI_RESULT(*get_dimension) (U32 flag, U8 *data_ptr, U32 img_size, S32 *width, S32 *height);
    GDI_RESULT(*get_pos_info) (U32 flag, U8 *data_ptr, U32 img_size, BOOL quick_mode, S32 *total_pos,
                               gdi_anim_pos_type_enum *pos_type);
    BOOL(*is_match_file_type) (U8 *file_name);
} gdi_image_codecs_struct;


typedef enum
{
    GDI_INTRAM_TYPE_MED_INT_STACK_MEM,
    GDI_INTRAM_TYPE_INVALID
} gdi_intram_type_enum;

extern kal_uint32 INT_SwitchStackToRun(void *stack_start, kal_uint32 stack_size, kal_func_ptr func, kal_uint32 argc, ...);

#if !defined(WIN32)
#define GDI_INTRAM_CALL(RESULT,FUNC,STACK_SIZE, ARGS_SUM,ARGS_LIST) \
    do                                                                                                                  \
    {                                                                                                                   \
        U32 mem_begin;                                                                                                  \
        gdi_intram_type_enum mem_type;                                                                                  \
        if(gdi_intram_malloc(STACK_SIZE,&mem_type,&mem_begin)==GDI_SUCCEED)                                             \
        {                                                                                                               \
            RESULT = INT_SwitchStackToRun((void *)mem_begin, STACK_SIZE,(kal_func_ptr) FUNC, ARGS_SUM,ARGS_LIST);       \
            gdi_intram_free(mem_type,mem_begin);                                                                        \
        }                                                                                                               \
        else                                                                                                            \
        {                                                                                                               \
            RESULT = FUNC(ARGS_LIST);                                                                                   \
        }                                                                                                               \
    }while(0)
#else
#define GDI_INTRAM_CALL(RESULT,FUNC,STACK_SIZE, ARGS_SUM,ARGS_LIST) RESULT = FUNC(ARGS_LIST)
#endif

    
extern const gdi_image_codecs_struct gdi_image_codecs[GDI_IMAGE_TYPE_SUM + 1];
extern const U16 *gdi_image_ext_name[];
extern BOOL gdi_memory_output;
extern U16 gdi_memory_output_width;
extern U16 gdi_memory_output_height;
extern U32 gdi_memory_output_buffer_address;
extern U32 gdi_memory_output_buffer_size;

/****************************************************************************
* Function Declar                                                              
*****************************************************************************/
/* init function */
extern GDI_RESULT gdi_image_init(void);
extern void gdi_image_parse_resource_internal(U8 *res_src, U8 **data_ptr, U8 *img_type, S32 *img_size, S32 *frame_number, S32 *width, S32 *height);
extern GDI_RESULT gdi_image_parse_info(
                    gdi_image_src_enum src_type,
                    U8 *img_src,
                    U8 **data_ptr,
                    U8 *img_type,
                    S32 *img_size,
                    S32 *frame_number,
                    S32 *width,
                    S32 *height);

extern GDI_RESULT gdi_image_codec_get_dimension(
                    gdi_image_src_enum src_type,
                    U8 *img_src,
                    U8 img_type,
                    S32 img_size,
                    S32 *width,
                    S32 *height,
                    U32 flag);
extern GDI_RESULT gdi_image_codec_get_frame_count(
                    gdi_image_src_enum src_type,
                    U8 *img_src,
                    U8 img_type,
                    S32 img_size,
                    S32 *frame_count,
                    U32 flag);
extern U32 gdi_image_codec_get_flag(void);

extern GDI_RESULT gdi_image_single_bank_cache_load(const U8 *img_src, S32 img_size, BOOL *reloaded);
extern U8 *gdi_image_single_bank_cache_get_buffer(void);
extern void gdi_image_single_bank_cache_reset(void);
extern void gdi_image_single_bank_cache_reset_entry(const U8 *img_src, S32 img_size);

extern GDI_RESULT gdi_intram_malloc(U32 size,gdi_intram_type_enum *mem_type,U32 *mem_begin);
extern void gdi_intram_free(gdi_intram_type_enum mem_type,S32 mem_begin);

extern void gdi_image_set_timeout(S32 seconds);
extern void gdi_image_clear_timeout(void);
extern BOOL gdi_image_is_timeout(void);
extern void gdi_image_set_abort(BOOL is_abort);
extern BOOL gdi_image_is_abort(void);
extern BOOL gdi_nb_is_high_priority(void);
#endif /* _GDI_IMAGE_H_ */ 

