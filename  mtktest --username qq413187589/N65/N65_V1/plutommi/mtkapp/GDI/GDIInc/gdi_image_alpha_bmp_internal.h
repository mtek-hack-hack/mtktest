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
*  LAWS PRINCIPLES.	ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  gdi_image_alpha_bmp_internal.h
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  Internal header for alpha bitmap  
 *
 *  To do the best optimization and get away from maintaining lots of code 
 *  path, MACRO CODE TEMPLATES are heavily used here. 
 * 
 *  TODO: DO NOT USE INLINE ASSEMBLY. Currently, only use inline assembly for ADS.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *			   HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __GDI_IMAGE_ALPHA_BMP_INTERNAL_H__
#define __GDI_IMAGE_ALPHA_BMP_INTERNAL_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define RGB_16_BIT_TYPE         DRV_RGB_TO_HW(0, 255, 0)
#define COLOR_FORMAT_RGB3553    0xE007  /* 6205B, 6218 */
#define COLOR_FORMAT_RGB565     0x07E0  /* other than 6205B and 6218 */

#define DEST_ALPHA_VALUE        255     /* alpha value 255 on 32-bit ARGB destination layer */

/* Color index 0 is the transparent color. */
#define ABM_TRANSPARENT_COLOR_INDEX 0

#define MAX(a, b)   ((a) > (b) ? (a) : (b))
#define MIN(a, b)   ((a) < (b) ? (a) : (b))

/* RGB888 at bit [23:0] */
#define R_OF_RGB888(p)      (((p) << 8) >> 24)
#define G_OF_RGB888(p)      (((p) << 16) >> 24)
#define B_OF_RGB888(p)      (((p) << 24) >> 24)

/* ARGB8888 */
#define A_OF_ARGB8888(p)    ((p) >> 24)
#define R_OF_ARGB8888(p)    R_OF_RGB888(p)
#define G_OF_ARGB8888(p)    G_OF_RGB888(p)
#define B_OF_ARGB8888(p)    B_OF_RGB888(p)

/* RGB565 at bit [15:0] */
#define R_OF_RGB565(p)      ((p) >> 11)
#define G_OF_RGB565(p)      (((p) << 21) >> 26)
#define B_OF_RGB565(p)      (((p) << 27) >> 27)

/* RGB565 at the high half word bit [31:16] */
#define R_OF_HIGH_RGB565(p) ((p) >> 27)
#define G_OF_HIGH_RGB565(p) (((p) << 5) >> 26)
#define B_OF_HIGH_RGB565(p) (((p) << 11) >> 27)

#define PUT_PIXEL_16(mem, p)    *((U16*)(mem)) = p
#define PUT_PIXEL_24(mem, p)       \
    do                             \
    {                              \
        U8 *mem_8 = (U8*)(mem);    \
        mem_8[0] = p;              \
        mem_8[1] = p >> 8;         \
        mem_8[2] = p >> 16;        \
    } while (0)

/* the ARGB alpha channel must be 255 to be OPAQUE */
#define PUT_PIXEL_32(mem, p)    *((U32*)(mem)) = (p) + ((U32)DEST_ALPHA_VALUE << 24)   

#define GET_PIXEL_16(mem)       (*((U16*)(mem)))
#define GET_PIXEL_24(mem)       ((((U8*)(mem))[0]) + (((U8*)(mem))[1] << 8) + (((U8*)(mem))[2] << 16))
#define GET_PIXEL_32(mem)       (*((U32*)(mem)))

/* get palette color */
#define GET_PALETTE_COLOR_16(pal, p) GET_PIXEL_16((U8*)(pal) + 2 * (p)) // (((U16*)(pal))[p])
#define GET_PALETTE_COLOR_24(pal, p) GET_PIXEL_24((U8*)(pal) + 3 * (p))
#define GET_PALETTE_COLOR_32(pal, p) GET_PIXEL_24((U8*)(pal) + 3 * (p))

/* alpha blending for ARGB8888 is the same to RGB888 except the destination alpha value must be 1.0 */
#define alpha_blend_32bit_pixel(src_pixel, img_pixel, alpha) alpha_blend_24bit_pixel(src_pixel, img_pixel, alpha)

// TODO: support RGB3553, but it is not feasible to do that?
#define RGB888_TO_RGB16(c)  rgb888_to_rgb565(c)
#define RGB16_TO_RGB888(c)  rgb565_to_rgb888(c)

#define MAIN_BASE_LAYER_IS_16_BIT   (MMI_MAIN_BASE_LAYER_BITS_PER_PIXEL == 16)
#define MAIN_BASE_LAYER_IS_24_BIT   (MMI_MAIN_BASE_LAYER_BITS_PER_PIXEL == 24)
#define MAIN_BASE_LAYER_IS_32_BIT   (MMI_MAIN_BASE_LAYER_BITS_PER_PIXEL == 32)

#define ABM_PALETTE_BPP ((MMI_MAIN_BASE_LAYER_BITS_PER_PIXEL == 16) ? 16 : 24)


/*
 * bitstream reader
 */
#define BIT_INIT(mem_ptr)               \
    {                                   \
        U32 BR_bits_buf;                \
        U16 *BR_bits_mem_ptr;           \
        U32 BR_bits_left;               \
                                        \
        BR_bits_mem_ptr = (U16*)(mem_ptr);              \
        BR_bits_buf = 0;                \
        BR_bits_left = 0;                               \
                                                        \
        /* take care of unalignment */                  \
        if ((U32)BR_bits_mem_ptr & 1)                   \
        {                                               \
            U8 *BR_mem_8 = (U8*)BR_bits_mem_ptr;        \
                                                        \
            BR_bits_buf = *BR_mem_8++;                  \
            BR_bits_mem_ptr = (U16*)BR_mem_8;           \
            BR_bits_left = 8;                           \
        }
  
#define BIT_END() }

#define BIT_READ(cb, data_mask, bit_data)  BR_bit_reader((cb), (data_mask), BR_bits_buf, BR_bits_left, BR_bits_mem_ptr, bit_data)
#define BIT_SEEK(s)                        BR_bit_seek((s), BR_bits_buf, BR_bits_left, BR_bits_mem_ptr)

/* bitstream read, output bit_data */
#define BR_bit_reader(cb, data_bit_mask, bits_buf, bits_left, bits_mem_ptr, bit_data) \
    do                                                                              \
    {                                                                               \
        /* bits in the buffer are not enough, append the buffer with 16 bits  */    \
        if (bits_left < cb)                                                         \
        {                                                                           \
            bits_buf += (*bits_mem_ptr++) << bits_left;                             \
            bits_left += 16;                                                        \
        }                                                                           \
                                                                                    \
        /* consume bits */                                                          \
        bit_data = bits_buf & (data_bit_mask);                                      \
        bits_buf >>= cb;                                                            \
        bits_left -= cb;                                                            \
    } while (0)


/* bitstream seek */
#define BR_bit_seek(seek_bits, bits_buf, bits_left, bits_mem_ptr)  \
    do                                                              \
    {                                                               \
        if (bits_left > seek_bits)                                  \
        {                                                           \
            bits_left -= seek_bits;                                 \
            bits_buf >>= seek_bits;                                 \
        }                                                           \
        else                                                        \
        {                                                           \
            U32 sb = seek_bits;                                     \
                                                                    \
            sb -= bits_left;                                        \
            bits_mem_ptr += sb / 16;                                \
            bits_buf = *bits_mem_ptr++;                             \
            sb &= 0xF;                                              \
            /* consume skipped bits */                              \
            bits_buf >>= sb;                                        \
            bits_left = 16 - sb;                                    \
        }                                                           \
    } while (0)


/*
 * ABM decoder core functions
 */

/*
 * get a pixel from looking up the palette by the color index
 *
 * possible scenarios:
 * MAIN BASE LAYER COLOR BPP    palette color bpp
 * 16                           16
 * 24                           24
 * 32                           24
 */
#define ABM_GET_IMG_PIXEL(palette_ptr, color_index) \
    ((MAIN_BASE_LAYER_IS_16_BIT) ? GET_PALETTE_COLOR_16(palette_ptr, color_index) : GET_PALETTE_COLOR_24(palette_ptr, color_index))


/*
 * output a pixel
 *
 * possible scenarios:
 * MAIN BASE LAYER COLOR BPP    pixel color bpp -> destination layer color bpp
 * 16                           16 -> 16
 * 24                           24 -> 16, 24 -> 24
 * 32                           24 -> 16, 24 -> 24, 24 -> 32
 */
#define ABM_PUT_PIXEL(out_mem_ptr, out_pixel, TARGET_BPP)               \
    do                                                                  \
    {                                                                   \
        if (MAIN_BASE_LAYER_IS_16_BIT)                                  \
        {   /* 16 -> 16 */                                              \
            PUT_PIXEL_16(out_mem_ptr, out_pixel);                       \
        }                                                               \
        else                                                            \
        {   /* 24 -> 16, 24 -> 24, 24 -> 32 */                          \
            if (TARGET_BPP == 16)                                       \
            {   /* 24 -> 16 */                                          \
                out_pixel = RGB888_TO_RGB16(out_pixel);                 \
                                                                        \
                /* do not let blue saturated */                         \
                if (B_OF_RGB565(out_pixel) == 0x1F)                     \
                {                                                       \
                    out_pixel -= 1; /* B 0x1F -> 0x1E */                \
                }                                                       \
                                                                        \
                PUT_PIXEL_16(out_mem_ptr, out_pixel);                   \
            }                                                           \
            else if (TARGET_BPP == 24)                                  \
            {   /* 24 -> 24 */                                          \
                PUT_PIXEL_24(out_mem_ptr, out_pixel);                   \
            }                                                           \
            else if (MAIN_BASE_LAYER_IS_32_BIT)                         \
            {   /* 24 -> 32 */                                          \
                PUT_PIXEL_32(out_mem_ptr, out_pixel);                   \
            }                                                           \
        }                                                               \
    } while (0)


/*
 * read a pixel from the source layer (FOR ALPHA BLENDING ONLY)
 *
 * possible scenarios:
 * MAIN BASE LAYER COLOR BPP    destination layer color bpp
 * 16                           16
 * 24                           16, 24
 * 32                           16, 24, 32
 */
 #define ABM_READ_PIXEL(src_mem_ptr, src_pixel, SRC_BPP)                            \
    do                                                                              \
    {                                                                               \
        if (SRC_BPP == 16)                                                          \
        {                                                                           \
             src_pixel = GET_PIXEL_16(src_mem_ptr);                                 \
                                                                                    \
             if (MAIN_BASE_LAYER_IS_24_BIT || MAIN_BASE_LAYER_IS_32_BIT)            \
             {                                                                      \
                src_pixel = RGB16_TO_RGB888(src_pixel);                             \
             }                                                                      \
        }                                                                           \
        else if (SRC_BPP == 24)                                                     \
        {                                                                           \
            src_pixel = GET_PIXEL_24(src_mem_ptr);                                  \
        }                                                                           \
        else if (MAIN_BASE_LAYER_IS_32_BIT)                                         \
        {                                                                           \
            src_pixel = GET_PIXEL_32(src_mem_ptr);                                  \
        }                                                                           \
    } while (0)


/* alpha blending function */
#if MAIN_BASE_LAYER_IS_16_BIT
#define ABM_PIXEL_ALPHA_BLEND(src_pixel, img_pixel, alpha)  alpha_blend_16bit_pixel(src_pixel, img_pixel, alpha)
#else /* MAIN_BASE_LAYER_IS_16_BIT */
#define ABM_PIXEL_ALPHA_BLEND(src_pixel, img_pixel, alpha)  alpha_blend_24bit_pixel(src_pixel, img_pixel, alpha)
#endif /* MAIN_BASE_LAYER_IS_16_BIT */
    

/* the template for different code path */
#define ALPHA_ABM_DECODER(SRC_BPP, TARGET_BPP)                                                  \
    do                                                                                          \
    {                                                                                           \
        U32 temp;                                                                               \
        for (x = CLIP_WIDTH_MINUS_1; x >= 0; x--)                                               \
        {                                                                                       \
            /* get color index p from the ABM bitstream */                                      \
            BIT_READ(BPP, BPP_BIT_MASK, p);                                                     \
                                                                                                \
            if (p != ABM_TRANSPARENT_COLOR_INDEX)                                               \
            {   /* non-transparent color */                                                     \
                img_pixel = ABM_GET_IMG_PIXEL(PALETTE_PTR, p);                                  \
                                                                                                \
                color_index = p - ALPHA_CI_START;                                               \
                                                                                                \
                if (color_index >= 0)                                                           \
                {   /* alpha pixel, do alpha blending */                                        \
                    alpha = ALPHA_PTR[color_index];                                             \
                                                                                                \
                    /* read the pixel from the source layer */                                  \
                    ABM_READ_PIXEL(src_mem_ptr, src_pixel, SRC_BPP);                            \
                                                                                                \
                    /* alpha blending */                                                        \
                    out_pixel = ABM_PIXEL_ALPHA_BLEND(src_pixel, img_pixel, alpha);             \
                }                                                                               \
                else                                                                            \
                {   /* opaque pixel */                                                          \
                    out_pixel = img_pixel;                                                      \
                }                                                                               \
            }                                                                                   \
            else                                                                                \
            {   /* alpha = 0, output pixel = src pixel */                                       \
                ABM_READ_PIXEL(src_mem_ptr, src_pixel, SRC_BPP);                                \
                out_pixel = src_pixel;                                                          \
            }                                                                                   \
                                                                                                \
            ABM_PUT_PIXEL(out_mem_ptr, out_pixel, TARGET_BPP);                                  \
                                                                                                \
            /* increase src/out memory pointers */                                              \
            src_mem_ptr += (SRC_BPP) / 8;                                                       \
            out_mem_ptr += (TARGET_BPP) / 8;                                                    \
        }                                                                                       \
                                                                                                \
        /* line jump for src/out memory pointers and ABM bitstream */                           \
        temp = get_r11();                                                                       \
        dst_line_jump_bytes = temp >> 16;                                                       \
        abm_line_jump_bits = temp & 0xFFFF;                                                     \
        BIT_SEEK(abm_line_jump_bits);                                                           \
                                                                                                \
        if (MAIN_BASE_LAYER_IS_16_BIT)                                                          \
        {   /* 16->16 */                                                                        \
            src_line_jump_bytes = dst_line_jump_bytes;                                          \
        }                                                                                       \
                                                                                                \
        src_mem_ptr += src_line_jump_bytes;                                                     \
        out_mem_ptr += dst_line_jump_bytes;                                                     \
                                                                                                \
        /* y-- */                                                                               \
        DECREASE_Y_BY_1();                                                                      \
    } while (Y > 0)


#define RBG_FF00FF_VAL_IN_PALETTE	63518	//sc.wu for transparent
/* 
 * general ABM decoder for ABM images without alpha 
 */
#define ABM_DECODER_WITHOUT_ALPHA(TARGET_BPP)                                           \
    do                                                                                  \
    {                                                                                   \
        set_r9(BPP_BIT_MASK);                                                           \
        set_r10(dst_line_jump_bytes);                                                   \
        set_r11(abm_line_jump_bits);                                                    \
                                                                                        \
        while (Y > 0)                                                                   \
        {                                                                               \
            /* output a line */                                                         \
            for (x = CLIP_WIDTH_MINUS_1; x >= 0; x--)                                   \
            {                                                                           \
                /* read the pixel from bitstream */                                     \
                BIT_READ(bpp, get_r9(), p);                                             \
                                                                                        \
                /* draw the pixel if it is not transparent */                           \
                if (p != ABM_TRANSPARENT_COLOR_INDEX)                                   \
                {                                                                       \
                    img_pixel = ABM_GET_IMG_PIXEL(PALETTE_PTR, p);                      \
					if(TARGET_BPP ==16)							\
					{												\
						if(img_pixel != RBG_FF00FF_VAL_IN_PALETTE)\
                    ABM_PUT_PIXEL(out_mem_ptr, img_pixel, TARGET_BPP);                  \
                }                                                                       \
					}\
                out_mem_ptr += (TARGET_BPP) / 8;                                        \
            }                                                                           \
                                                                                        \
            /* jump to the start pixel in the next line of the ABM image */             \
            abm_line_jump_bits = get_r11();                                             \
            BIT_SEEK(abm_line_jump_bits);                                               \
                                                                                        \
            /* jump to the start pixel in the next line of the target layer */          \
            out_mem_ptr += get_r10();                                                   \
                                                                                        \
            DECREASE_Y_BY_1();  /* y-- */                                               \
        }                                                                               \
    } while (0)


/*
 * register storage
 */ 
/* 
 * R9 
 * bit[31:28]   BPP
 * bit[27:16]   ALPHA_CI_START
 * bit[15:0]    BPP_BIT_MASK 
 */
#define BPP_BIT_MASK        (get_r9() & 0xFFFF)         /* bit mask for consumed bits */
#define ALPHA_CI_START      ((get_r9() >> 16) & 0xFFF)
#define BPP                 (get_r9() >> 28)

/* R10 ALPHA_PTR */
#define ALPHA_PTR           ((U8*)get_r10())

#define PALETTE_PTR         ((U8*)get_r12())

/* 
 * R8
 * bit[31:16]   CLIP_WIDTH_MINUS_1
 * bit[15:0]    Y
 */
#define CLIP_WIDTH_MINUS_1  (get_r8() >> 16)
#define Y                   (get_r8() & 0xFFFF)
#define DECREASE_Y_BY_1()   \
    do                      \
    {                       \
        y = get_r8();       \
        y--;                \
        set_r8(y);          \
    } while (0)


#if (defined(__MTK_TARGET__) && !defined(__RVCT__))
/*
 * target, to use r8 to r11 in thumb mode
 */
static U32 register_context[4];

#define DECLARE_SET_REGISTER_FUNC(reg)  \
    static void set_r##reg(U32 value)   \
    {                                   \
        __asm                           \
        {                               \
            MOV     r##reg, value;      \
        }                               \
    }

#define DECLARE_GET_REGISTER_FUNC(reg)  \
    static U32 get_r##reg()             \
    {                                   \
        U32 value;                      \
                                        \
        __asm                           \
        {                               \
            MOV     value, r##reg;      \
        }                               \
        return value;                   \
    }                     
    
#else /* (defined(__MTK_TARGET__) && !defined(__RVCT__)) */

/* 
 * simulator, use a static array to simulate registers
 */
static U32 register_pool[16];

#define DECLARE_SET_REGISTER_FUNC(reg)  \
    static void set_r##reg(U32 value)   \
    {                                   \
       register_pool[reg] = value;      \
    }


#define DECLARE_GET_REGISTER_FUNC(reg)  \
    static U32 get_r##reg()             \
    {                                   \
        return register_pool[reg];      \
    }

#endif /* (defined(__MTK_TARGET__) && !defined(__RVCT__)) */

/*
 * For the thumb C compiler (tcc), it only utilizes r0-r7, r12, r14 
 * (total 10 regiters) for variable allocation. The following trick 
 * uses r8-r11 in thumb mode.
 */
/* set ARM register functions */
DECLARE_SET_REGISTER_FUNC(8)    /* set_r8() */
DECLARE_SET_REGISTER_FUNC(9)    /* set_r9() */
DECLARE_SET_REGISTER_FUNC(10)   /* set_r10() */
DECLARE_SET_REGISTER_FUNC(11)   /* set_r11() */
DECLARE_SET_REGISTER_FUNC(12)   /* set_r12() */ /* SCRATCH */

/* get ARM register functions */
DECLARE_GET_REGISTER_FUNC(8)    /* get_r8() */
DECLARE_GET_REGISTER_FUNC(9)    /* get_r9() */
DECLARE_GET_REGISTER_FUNC(10)   /* get_r10() */
DECLARE_GET_REGISTER_FUNC(11)   /* get_r11() */
DECLARE_GET_REGISTER_FUNC(12)   /* get_r12() */ /* SCRATCH */

/* save/restore register */
#define SAVE_REGISTER() save_register()
#define RESTORE_REGISTER() restore_register()

#if (defined(__MTK_TARGET__) && !defined(__RVCT__))

/* save r8 to r11 registers */
static void save_register(void)
{
    register_context[0] = get_r8();
    register_context[1] = get_r9();
    register_context[2] = get_r10();
    register_context[3] = get_r11();        
}
 
/* 
 * turn off C compiler optimization temporarily to prevent code from DISAPPEARING 
 * due to optimization 
 */
#pragma O0

/* restore r8 to r11 registers */
static U32 restore_register()
{    
    set_r8(register_context[0]);
    set_r9(register_context[1]);
    set_r10(register_context[2]);
    set_r11(register_context[3]);    
    
    return get_r8() + get_r9() + get_r10() + get_r11();
}

/* turn on optimization again */
#pragma O2

#else /* (defined(__MTK_TARGET__) && !defined(__RVCT__)) */

static void save_register(void) {}
static void restore_register(void) {}

#endif /* (defined(__MTK_TARGET__) && !defined(__RVCT__)) */

/* The ARM C compiler can support returning 4 32-bit variables in registers r0-r3. */
#ifdef __MTK_TARGET__
#define RET_VALUE_IN_REGS __value_in_regs
#else
#define RET_VALUE_IN_REGS
#endif

#define INVALID_RECT    (-1)

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef struct 
{
    S32 x1, y1; /* top-left point */
    S32 x2, y2; /* bottom-right point */
} rect_struct;

/* ABM pre-processing info */
typedef struct
{
     U8     *abm_bitstream_ptr;
     U8     *palette_ptr;
     U8     *src_mem_ptr;
     U8     *out_mem_ptr;

     U32    abm_start_bit_offset;
     U32    dst_bpp;
     U32    src_bpp; 
     U32    alpha_color_num;
     U32    src_line_jump_bytes;
     U32    dst_line_jump_bytes;
     U32    abm_line_jump_bits;
     U32    bpp;
     U32    palette_bpp;

     U32    r8, r9, r10, r11;
} abm_info_struct;

/***************************************************************************** 
 * Global Function
 *****************************************************************************/

#endif /* __GDI_IMAGE_ALPHA_BMP_INTERNAL_H__ */

