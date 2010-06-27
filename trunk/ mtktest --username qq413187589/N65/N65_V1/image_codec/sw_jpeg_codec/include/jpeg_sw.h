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
 *   jpeg_sw.h
 *
 * Project:
 * --------
 *   MT6225
 *
 * Description:
 * ------------
 *   This file is intends for jpeg software codec.
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
 ****************************************************************************/
#ifndef _JPEG_SW_H
#define _JPEG_SW_H

#if defined(__SW_JPEG_CODEC_SUPPORT__) || !defined(__MTK_TARGET__)
#include "kal_non_specific_general_types.h"
#include "image.h"

#if defined(__MTK_TARGET__)
/// for __SW_JPEG_USING_DCM__ option
#include "drv_features.h"
#endif

extern const kal_int16 std_luminance_quant_tbl[64];
extern const kal_int16 std_chrominance_quant_tbl[64];
extern const kal_int32 fixed_fdct_scale[64];
extern const kal_int16 std_luminance_quant_tbl[64];
extern const kal_int16 std_chrominance_quant_tbl[64];
extern const kal_uint8 dc_luminance_bits[17];
extern const kal_uint8 dc_luminance_val[12];
extern const kal_uint16 dc_lum_symbol_2_code_tbl[12];
extern const kal_uint8 dc_lum_symbol_2_size_tbl[12];
extern const kal_uint8 dc_chrominance_bits[17];
extern const kal_uint8 dc_chrominance_val[12];
extern const kal_uint16 dc_chrom_symbol_2_code_tbl[12];
extern const kal_uint8 dc_chrom_symbol_2_size_tbl[12];

extern const kal_uint8 ac_luminance_bits[17];
extern const kal_uint8 ac_luminance_val[162];
extern const kal_uint16 ac_lum_symbol_2_code_tbl[256];
extern const kal_uint8 ac_lum_symbol_2_size_tbl[256];
extern const kal_uint8 ac_chrominance_bits[17];
extern const kal_uint8 ac_chrominance_val[162];
extern const kal_uint16 ac_chrom_symbol_2_code_tbl[256];
extern const kal_uint8 ac_chrom_symbol_2_size_tbl[256];
extern const kal_uint8 Z_ZAG_TBL[64];

#define JPEG_ENCODER_HIGH_QUALITY   0
#define JPEG_ENCODER_GOOD_QUALITY   1
#define JPEG_ENCODER_FAIR_QUALITY   2 /* using default quantization table */
#define JPEG_ENCODER_POOR_QUALITY   3

#define QUANT_FRACTION_BITS   12  // Used for Quantization table fix point
#define FDCT_FRAC_BIT         11  // fractional bits of cosine coefficient

#define JPEG_MARKER_SOI    0xD8
#define JPEG_MARKER_SOF0   0xC0
#define JPEG_MARKER_DQT    0xDB
#define JPEG_MARKER_DHT    0xC4
#define JPEG_MARKER_SOS    0xDA
#define JPEG_MARKER_EOI    0xD9

#define JPEG_HUFF_DC_INDEX_0  0x00
#define JPEG_HUFF_DC_INDEX_1  0x01
#define JPEG_HUFF_AC_INDEX_0  0x10
#define JPEG_HUFF_AC_INDEX_1  0x11

typedef kal_int16 JCOEF;

#define JPEG_SW_ENC_REQUIRED_INT_MEM_SIZE 512

#define DRV_JPG_ENC_DIRECT_COUPLE_SUPPORT
#define JPEG_ENC_IP_THRESH_WIDTH    320
#define JPEG_ENC_IP_THRESH_HEIGHT   240

typedef struct
{
   IMAGE_FORMAT_ENUM input_type;    /* IMAGE_FORMAT_RGB565 or IMAGE_FORMAT_YUV420 */
   IMAGE_FORMAT_ENUM output_type;   /* IMAGE_FORMAT_GRAY or IMAGE_FORMAT_YUV420 */

   kal_uint32 image_buffer_address; /* the RGB565 image buffer start address */
   kal_uint8 *jpeg_yuv_data[3];     /* If the data type is YUV420, put the raw data here. Otherwise this will be an intermediate
                                       buffer for storing the YUV data transformed from the RGB565 data buffer*/

   kal_uint32 jpeg_yuv_size[3];     /* The buffer size of jpeg_yuv_data[3] */

   kal_uint32 intmem_start_address; /* internal memory start address for hardware engine buffer */
   kal_uint32 intmem_size;          /* internal memory size for hardware engine buffer */

   kal_uint16 image_width;          /* the width of image source */
   kal_uint16 image_height;         /* the height of image source */

   kal_uint8  image_quality;        /* the image quality after encoded */

   kal_uint32 jpeg_file_start_address;    /* the start address for encoded JPEG file */
   kal_uint32 jpeg_file_buffer_size;      /* the maximum size of jpeg file after encode */

   /* SW direct Couple for LCD*/
#ifdef DRV_JPG_ENC_DIRECT_COUPLE_SUPPORT
   kal_bool memory_output;                /* output another image for LCD output */
   IMAGE_FORMAT_ENUM memory_output_type;
   kal_uint16 memory_output_width;        /* image width for LCD output */
   kal_uint16 memory_output_height;       /* image height for LCD output */
   kal_uint32 memory_output_buffer_address;
   kal_uint32 memory_output_buffer_size;
#endif

} jpeg_sw_encode_process_struct;



typedef struct
{
   kal_uint8 *bits;
   kal_uint8 *huffval;
   kal_uint16 *ehufco;
   kal_uint8 *ehufsi;
} HUFF_TBL;


typedef struct
{
   IMAGE_FORMAT_ENUM input_type;    /* IMAGE_FORMAT_RGB565 or IMAGE_FORMAT_YUV420 */
   IMAGE_FORMAT_ENUM output_type;      /* IMAGE_FORMAT_GRAY or IMAGE_FORMAT_YUV420 */

   kal_uint8 image_quality;
   kal_uint8 num_of_comp;
   kal_uint8 max_h_sample_factor;
   kal_uint8 max_v_sample_factor;

   kal_uint8 *jpeg_yuv_data[3];

   kal_uint32 jpeg_file_start_address;

   kal_uint16 image_width; /* the width of image source */
   kal_uint16 image_height;   /* the height of image source */

   kal_uint16 jpg_encode_width;  /* Encode width after padding */
   kal_uint16 jpg_encode_height; /* Encode height after padding */

   kal_uint16 MCUs_per_row;   /* # of MCUs across the image */
   kal_uint16 num_mcu_row;

   /* Bellow this line is the info. of each Y,U,V component */
   kal_uint16 sample_width[3];

   kal_uint8 h_sample_factor[3]; /* sample factor of Y,U,V component */
   kal_uint8 v_sample_factor[3];

   kal_uint8 MCU_DU_width[3]; /* number of blocks per MCU, horizontally */
   kal_uint8 MCU_DU_height[3];   /* number of blocks per MCU, vertically */

   /* Bellow this line is the table ptrs and block ptrs */
   kal_int16 *block;
   kal_int32 *dct_ptr;
   kal_int16 *Quant[2];
   kal_int16 *Scaled_Quant[2];
   kal_uint8 q_table_no[3];
   kal_uint8 dc_huff_table_no[3];
   kal_uint8 ac_huff_table_no[3];
   HUFF_TBL dc_huff_table[2];
   HUFF_TBL ac_huff_table[2];
   kal_int32 last_dc_val[3];
} jpeg_sw_encode_para_struct;



typedef struct
{
   kal_uint32 *int_ram_start_ptr;
   kal_uint32 int_ram_total_length;
   kal_uint32 int_ram_index;
   kal_bool int_ram_init;
} JPEG_MEM_STRUCT;


#if defined(__MTK_TARGET__) || defined (__SW_JPEG_CODEC_SUPPORT__)
   #define jpeg_encode_process_struct jpeg_sw_encode_process_struct
   kal_uint32 jpeg_encode_process(jpeg_encode_process_struct *jpeg_encode_config_data);
#else
   kal_uint32 jpeg_sw_encode_process(jpeg_sw_encode_process_struct *jpeg_encode_config_data);
#endif

#endif

#endif //_JPEG_SW_H
