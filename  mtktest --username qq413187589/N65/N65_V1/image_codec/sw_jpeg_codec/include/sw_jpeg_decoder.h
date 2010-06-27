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
 *   sw_jpeg_decoder.h
 *
 *
 * Description:
 * ------------
 *   header file of software jpeg decoder code
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#if(defined __SW_JPEG_CODEC_SUPPORT__ || !defined(__MTK_TARGET__))

#ifndef __SW_JPEG_DECODER_H__
#define __SW_JPEG_DECODER_H__

#define JPEG_SUPPORT_TIMEOUT_FUNC

#define RESIZER_SCALE_BITS 20

/*
#define JPEG_FORMAT_444 0
#define JPEG_FORMAT_422 1
#define JPEG_FORMAT_420 2
#define JPEG_FORMAT_GRAY 3
*/


#define JPEG_SW_RESIZE_IP_UPPER_BOUND  176

#define JPEG_SW_DECODER_HIGH_QUALITY 0
#define JPEG_SW_DECODER_FINE_QUALITY 1
#define JPEG_SW_DECODER_FAIR_QUALITY 2
#define JPEG_SW_DECODER_POOR_QUALITY 3

typedef struct
{
   kal_uint8 bits[17];     /* bits[k] = # of symbols with codes of */
   kal_uint8 huffman_value[256];    /* The symbols, in order of incr code length */
   kal_uint8 huffman_table_count;
} huffman_table_struct;

typedef struct
{
   kal_int16 component_id;
   kal_int16 component_index;
   kal_int16 h_samp_factor;
   kal_int16 v_samp_factor;
   kal_int16 quant_table_num;
   kal_int16 dc_table_num;
   kal_int16 ac_table_num;
   kal_bool component_needed;
   kal_uint8 idct_loop_counter;
   kal_uint8 idct_h_increase;
   kal_uint8 idct_v_increase;
} component_info;

#define HUFF_LOOKAHEAD  8
#define HUFF_MASK       ((1<<HUFF_LOOKAHEAD)-1)


typedef struct
{
   kal_int32 maxcode[18];
   kal_int32 valoffset[17];
   huffman_table_struct *pub;
   kal_uint8 look_nbits[1 << HUFF_LOOKAHEAD];
   kal_uint8 look_sym[1 << HUFF_LOOKAHEAD];
} d_derived_table;



#define BIT_BUF_SIZE  32   /* size of buffer in bits */


#define MIN_GET_BITS  (BIT_BUF_SIZE - 7)


#define HUFF_EXTEND(x, s)  ((x) < (1 << ((s) - 1)) ? (x) + (((-1) << (s)) + 1) : (x))


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else

#define FILL_BIT_BUFFER(vld_buffer_reg, bits_left_reg, nbits)                    \
{                                                                                \
   if (0 == unread_marker)                                                       \
   {                                                                             \
      while (bits_left_reg < MIN_GET_BITS)                                       \
      {                                                                          \
         register kal_uint32 c;                                                  \
         if (_jpeg_file_ptr >= _jpeg_file_ptr_end)                               \
         {                                                                       \
            jpeg_sw_read_file();                                                 \
         }                                                                       \
         c = *_jpeg_file_ptr++;                                                  \
                                                                                 \
         if (0xFF == c)                                                          \
         {                                                                       \
            do                                                                   \
            {                                                                    \
               if (_jpeg_file_ptr >= _jpeg_file_ptr_end)                         \
               {                                                                 \
                  jpeg_sw_read_file();                                           \
               }                                                                 \
               c = *_jpeg_file_ptr++;                                            \
            } while (0xFF == c);                                                 \
                                                                                 \
            if (0 == c)                                                          \
            {                                                                    \
               c = 0xFF;                                                         \
            }                                                                    \
            else                                                                 \
            {                                                                    \
               unread_marker = c;                                                \
               if (nbits > bits_left_reg)                                        \
               {                                                                 \
                  THROW(5);                                                      \
               }                                                                 \
               vld_buffer_reg <<= (MIN_GET_BITS - bits_left_reg);                \
               bits_left_reg = MIN_GET_BITS;                                     \
               break;                                                            \
            }                                                                    \
         }                                                                       \
         vld_buffer_reg = (vld_buffer_reg << 8) | c;                             \
         bits_left_reg += 8;                                                     \
      }                                                                          \
   }                                                                             \
   else                                                                          \
   {                                                                             \
      if (nbits > bits_left_reg)                                                 \
      {                                                                          \
         THROW(5);                                                               \
      }                                                                          \
      vld_buffer_reg <<= (MIN_GET_BITS - bits_left_reg);                         \
      bits_left_reg = MIN_GET_BITS;                                              \
   }                                                                             \
}
#endif



#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else


#define HUFF_SLOW_DECODE(result, vld_buffer_reg, bits_left_reg, htbl, nb)        \
{                                                                                \
   register kal_int32 code;                                                      \
   register kal_int32 *maxcode = htbl->maxcode;                                  \
   if (bits_left_reg < nb)                                                       \
   {                                                                             \
      FILL_BIT_BUFFER(vld_buffer_reg, bits_left_reg, nb);                        \
   }                                                                             \
   bits_left_reg -= nb;                                                          \
   code = (vld_buffer_reg >> bits_left_reg) & ((1 << nb) - 1);                   \
   while (code > maxcode[nb])                                                    \
   {                                                                             \
      code <<= 1;                                                                \
      if (bits_left_reg < 1)                                                     \
      {                                                                          \
         FILL_BIT_BUFFER(vld_buffer_reg, bits_left_reg, 1);                      \
      }                                                                          \
      (bits_left_reg)--;                                                           \
      code |= ((vld_buffer_reg >> bits_left_reg) & 1);                           \
      nb++;                                                                      \
   }                                                                             \
   if (nb > 16)                                                                  \
   {                                                                             \
      THROW(6);                                                                  \
   }                                                                             \
   result = htbl->pub->huffman_value[code + htbl->valoffset[nb]];                \
}



#define HUFF_DECODE(result, vld_buffer_reg, bits_left_reg, htbl, slowlabel)      \
{                                                                                \
   register kal_uint32 nb, look;                                                 \
   if (bits_left_reg < HUFF_LOOKAHEAD)                                           \
   {                                                                             \
      FILL_BIT_BUFFER(vld_buffer_reg, bits_left_reg, 0);                         \
      if (bits_left_reg < HUFF_LOOKAHEAD)                                        \
      {                                                                          \
         nb = 1;                                                                 \
         goto slowlabel;                                                         \
      }                                                                          \
   }                                                                             \
                                                                                 \
   look = (vld_buffer_reg >> (bits_left_reg - HUFF_LOOKAHEAD)) & HUFF_MASK;      \
   if ((nb = htbl->look_nbits[look]) != 0)                                       \
   {                                                                             \
      DROP_BITS(vld_buffer_reg, bits_left_reg, nb);                              \
      result = htbl->look_sym[look];                                             \
   }                                                                             \
   else                                                                          \
   {                                                                             \
      nb = HUFF_LOOKAHEAD + 1;                                                   \
slowlabel:                                                                       \
      HUFF_SLOW_DECODE(result, vld_buffer_reg, bits_left_reg, htbl, nb);         \
   }                                                                             \
}
#endif



#define GET_BITS(vld_buffer, bits_left, min_bits) \
   (((kal_int16) (vld_buffer >> (bits_left -= (min_bits)))) & ((1 << (min_bits)) - 1))


#define PEEK_BITS(vld_buffer, bits_left, min_bits) \
   (((unsigned char) (vld_buffer >> (bits_left - (min_bits)))))


#define DROP_BITS(vld_buffer, bits_left, min_bits) \
   ((bits_left) -= (min_bits))


#define CHECK_BIT_BUFFER(vld_buffer_reg, bits_left_reg, nbits) \
{                                                              \
   if (bits_left_reg < (nbits))                                \
   {                                                           \
      FILL_BIT_BUFFER(vld_buffer_reg, bits_left_reg,nbits);    \
   }                                                           \
}


typedef struct
{
   kal_uint16 EOBRUN;            /* remaining EOBs in EOBRUN */
   kal_int32 last_dc_val[4];     /* last DC coef for each component */
} savable_state;


typedef struct
{
   kal_bool insufficient_data;   /* set TRUE after emitting warning */
   kal_int32 vld_buffer;         /* current bit-extraction buffer */
   kal_uint16 bits_left;         /* # of unused bits in it */
   savable_state saved;          /* Other state at start of MCU */
   kal_uint16 restarts_to_go;    /* MCUs left in this restart interval */

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
   d_derived_table dc_derived_tables[2];
   d_derived_table ac_derived_tables[2];
#endif

   d_derived_table *dc_cur_tables[10];
   d_derived_table *ac_cur_tables[10];
   d_derived_table *ac_derived_table;  /* active table during an AC scan */
   kal_bool dc_needed[10];
   kal_bool ac_needed[10];
} huff_entropy_decoder;

typedef huff_entropy_decoder *huff_entropy_ptr;

#if defined(__SW_JPEG_USING_DCM__)
void sw_jpeg_dec_set_dcm_flag(kal_bool flag);
#endif

kal_uint8 sw_jpeg_decode(kal_uint32 file_handle);
void jpeg_dec_intmem_init(void *start_ptr,kal_uint32 length);
void jpeg_dec_intmem_deinit(void);

#define JPEG_SW_DECODER_INTMEM_OVERFLOW  0xff

/* IDCT Functions */
typedef enum
{
   IDCT_COL_NONE=0x00,
   IDCT_COL_0=0x01,
   IDCT_COL_1=0x02,
   IDCT_COL_2=0x04,
   IDCT_COL_3=0x08,
   IDCT_COL_4=0x10,
   IDCT_COL_5=0x20,
   IDCT_COL_6=0x40,
   IDCT_COL_7=0x80,
   IDCT_COL_0_7=0x81,
   IDCT_COL_1_6=0x42,
   IDCT_COL_2_5=0x24,
   IDCT_COL_3_4=0x18,
   IDCT_COL_0_3_4_7=0x99,
   IDCT_COL_1_2_5_6=0x66,
   IDCT_COL_ALL=0xff
}IDCT_COL;

#define jpeg_decoder_1st_idct_col_0_7(inptr,quantptr,wsptr,blk_zero_tbl)\
   for (ctr = 0; ctr < 8; ctr++)\
   {\
      switch(blk_zero_tbl[ctr])\
      {\
      case 0:\
         while(ctr<8){\
            wsptr[0]=0;\
            wsptr[7]=0;\
            wsptr+= 8;\
            ctr++;}\
         goto _1st_idct_end;\
      case 1:\
         x1 =  (inptr[0] * quantptr[0]);\
         wsptr[0] = x1;\
         wsptr[7] = x1;\
         break;\
      case 2:\
         x1 =  (inptr[1] * quantptr[1]);\
         d12 =  (x1 * 615)>>10;\
         x1 = (x1 * 1204) >> 10;\
         c7 = (x1 * 25)>>6;\
         x3 = x1 - c7;\
         x1 =  (inptr[0] * quantptr[0]);\
         x2=d12+x3;\
         wsptr[0] = (x1 + x2);\
         wsptr[7] = (x1 - x2);\
         break;\
      case 3:\
         x1 =  (inptr[1] * quantptr[1]);\
         c4 = ((x1 ) * 922)>>10;\
         b12 = (x1 * 1537)>>10;\
         d12 = b12 - c4;\
         x4 = ((x1) * 1204) >> 10;\
         c7 = (x1 * 25)>>6;\
         x3 = x4 - c7;\
         b3 =  (inptr[0] * quantptr[0]);\
         d0 =  (inptr[2] * quantptr[2]);\
         x5 = (d0 * 784)>>10;\
         x1 = ((d0) * 554)>>10;\
         d1 = x1 + x5;\
         x2=d12+x3;\
         x1=b3+d1;\
         wsptr[0] = (x1 + x2);\
         wsptr[7] = (x1 - x2);\
         break;\
      default:\
      x1 =  (inptr[1] * quantptr[1]);\
      x2 =  (inptr[3] * quantptr[3]);\
      x3 =  (inptr[5] * quantptr[5]);\
      x4 =  (inptr[7] * quantptr[7]);\
      c4 = ((x1 + x4) * 922)>>10;\
      b12 = (x1 * 1537)>>10;\
      d12 = b12 - c4;\
      x4 = x2 + x4;\
      x3 = x1 + x3;\
      x1 = ((x4+x3) * 1204) >> 10;\
      c7 = (x3 * 25)>>6;\
      x3 = x1 - c7;\
      x1 =  (inptr[0] * quantptr[0]);\
      x2 =  (inptr[4] * quantptr[4]);\
      b3 = (x1 + x2);\
      x1 =  (inptr[2] * quantptr[2]);\
      x2 =  (inptr[6] * quantptr[6]);\
      x5 = (x1 * 784)>>10;\
      x1 = ((x1 + x2) * 554)>>10;\
      d1 = x1 + x5;\
      x2=d12+x3;\
      x1=b3+d1;\
      wsptr[0] = (x1 + x2);\
      wsptr[7] = (x1 - x2);\
         break;\
      }\
      inptr+=8;\
      quantptr+= 8;\
      wsptr+= 8;\
  }

#define jpeg_decoder_1st_idct_col_2_5(inptr,quantptr,wsptr,blk_zero_tbl)\
   for (ctr = 0; ctr < 8; ctr++)\
   {\
      switch(blk_zero_tbl[ctr])\
   {\
       case 0:\
         while(ctr<8){\
            wsptr[2]=0;\
            wsptr[5]=0;\
            wsptr+= 8;\
            ctr++;}\
         goto _1st_idct_end;\
       case 1:\
         x1 =  (inptr[1] * quantptr[1]);\
         wsptr[2] = x1;\
         wsptr[5] = x1;\
         break;\
       case 2:\
         x1 =  (inptr[1] * quantptr[1]);\
         c7 = (x1 * 25)>>6;\
         x3 = x1 - c7;\
         x1 =  (inptr[0] * quantptr[0]);\
         wsptr[2] = (x1 + x3);\
         wsptr[5] = (x1 - x3);\
         break;\
      case 3:\
         x1 =  (inptr[1] * quantptr[1]);\
         x4 = ((x1) * 1204) >> 10;\
         c7 = (x1 * 25)>>6;\
         x3 = x4 - c7;\
         b3 =  (inptr[0] * quantptr[0]);\
         d0 =  (inptr[2] * quantptr[2]);\
         x1 = b3 - d0;\
         wsptr[2] = (x1 + x3);\
         wsptr[5] = (x1 - x3);\
         break;\
       default:\
      x1 =  (inptr[1] * quantptr[1]);\
      x2 =  (inptr[3] * quantptr[3]);\
      x3 =  (inptr[5] * quantptr[5]);\
      x4 =  (inptr[7] * quantptr[7]);\
      b10 = (x3 * 2102)>>10;\
      c5 = ((x2 + x3) * 2624)>>10;\
      d5 = b10 - c5;\
      x4 = x2 + x4;\
      x3 = x1 + x3;\
      x1 = ((x4+x3) * 1204) >> 10;\
      c7 = (x3 * 25)>>6;\
      x3 = x1 - c7;\
      x1 =  (inptr[0] * quantptr[0]);\
      x2 =  (inptr[4] * quantptr[4]);\
      b4 = (x1 - x2);\
      x1 =  (inptr[2] * quantptr[2]);\
      x2 =  (inptr[6] * quantptr[6]);\
      x6 = (x2 * 1892)>>10;\
      x1 = ((x1 + x2) * 554)>>10;\
      d0 = x1 - x6;\
      x1 = b4 - d0;\
      x2 = d5 + x3;\
      wsptr[2] = (x1 + x2);\
      wsptr[5] = (x1 - x2);\
         break;\
      }\
      inptr+=8;\
      quantptr+= 8;\
      wsptr+= 8;\
  }

#define jpeg_decoder_1st_idct_col_3_4(inptr,quantptr,wsptr,blk_zero_tbl)\
   for (ctr = 0; ctr < 8; ctr++)\
   {\
      switch(blk_zero_tbl[ctr])\
   {\
       case 0:\
         while(ctr<8){\
            wsptr[3]=0;\
            wsptr[4]=0;\
            wsptr+= 8;\
            ctr++;}\
         goto _1st_idct_end;\
       case 1:\
         x1 =  (inptr[0] * quantptr[0]);\
         wsptr[3] = x1;\
         wsptr[4] = x1;\
         break;\
       case 2:\
         x4 =  (inptr[1] * quantptr[1]);\
         c4 = (x4 * 922)>>10;\
         x4 = ((x4) * 1204) >> 10;\
         x1 =  (inptr[0] * quantptr[0]);\
         x2 = x4-c4;\
         wsptr[3] = (x1 + x2);\
         wsptr[4] = (x1 - x2);\
         break;\
      case 3:\
         x1 =  (inptr[1] * quantptr[1]);\
         x4 = ((x1) * 1204) >> 10;\
         b3 =  (inptr[0] * quantptr[0]);\
         d0 =  (inptr[2] * quantptr[2]);\
         x5 = (d0 * 784)>>10;\
         x1 = ((d0) * 554)>>10;\
         d1 = x1 + x5;\
         x1 = b3 - d1;\
         wsptr[3] = (x1 + x4);\
         wsptr[4] = (x1 - x4);\
         break;\
       default:\
      x1 =  (inptr[1] * quantptr[1]);\
      x2 =  (inptr[3] * quantptr[3]);\
      x3 =  (inptr[5] * quantptr[5]);\
      x4 =  (inptr[7] * quantptr[7]);\
      b9 = (x4 * 306)>>10;\
      c4 = ((x1 + x4) * 922)>>10;\
      d4 = b9 - c4;\
      x4 = x2 + x4;\
      x3 = x1 + x3;\
      x1 = ((x4+x3) * 1204) >> 10;\
      c6 = (x4 * 2009)>>10;\
      x4 = x1 - c6;\
      x1 =  (inptr[0] * quantptr[0]);\
      x2 =  (inptr[4] * quantptr[4]);\
      b3 = (x1 + x2);\
      x1 =  (inptr[2] * quantptr[2]);\
      x2 =  (inptr[6] * quantptr[6]);\
      x5 = (x1 * 784)>>10;\
      x1 = ((x1 + x2) * 554)>>10;\
      d1 = x1 + x5;\
      x1 = b3 - d1;\
      x2 = d4 + x4;\
      wsptr[3] = (x1 + x2);\
      wsptr[4] = (x1 - x2);\
         break;\
      }\
      inptr+=8;\
      quantptr+= 8;\
      wsptr+= 8;\
  }

#define jpeg_decoder_1st_idct_col_1_6(inptr,quantptr,wsptr,blk_zero_tbl)\
   for (ctr = 0; ctr < 8; ctr++)\
   {\
      switch(blk_zero_tbl[ctr])\
      {\
       case 0:\
         while(ctr<8){\
            wsptr[1]=0;\
            wsptr[6]=0;\
            wsptr+= 8;\
            ctr++;}\
          goto _1st_idct_end;\
       case 1:\
         x1 =  (inptr[0] * quantptr[0]);\
         wsptr[1] = x1;\
         wsptr[6] = x1;\
         break;\
       case 2:\
         x3 =  (inptr[1] * quantptr[1]);\
         x2 = ((x3) * 1204) >> 10;\
         x1 =  (inptr[0] * quantptr[0]);\
         wsptr[1] = (x1 + x2);\
         wsptr[6] = (x1 - x2);\
         break;\
      case 3:\
         x1 =  (inptr[1] * quantptr[1]);\
         c4 = ((x1) * 922)>>10;\
         b12 = (x1 * 1537)>>10;\
         d12 = b12 - c4;\
         x4 = ((x1) * 1204) >> 10;\
         c7 = (x1 * 25)>>6;\
         x3 = x4 - c7;\
         b3 =  (inptr[0] * quantptr[0]);\
         d0 =  (inptr[2] * quantptr[2]);\
         x1 = ((d0) * 554)>>10;\
         x2=d12+x3;\
         x1 = b3 + d0;\
         wsptr[1] = (x1 + x2);\
         wsptr[6] = (x1 - x2);\
         break;\
       default:\
      x1 =  (inptr[1] * quantptr[1]);\
      x2 =  (inptr[3] * quantptr[3]);\
      x3 =  (inptr[5] * quantptr[5]);\
      x4 =  (inptr[7] * quantptr[7]);\
      c5 = ((x2 + x3) * 2624)>>10;\
      b11 = (x2 * 3146)>>10;\
      d11 = b11 - c5;\
      x4 = x2 + x4;\
      x3 = x1 + x3;\
      x1 = ((x4+x3) * 1204) >> 10;\
      c6 = (x4 * 2009)>>10;\
      x4 = x1 - c6;\
      x1 =  (inptr[0] * quantptr[0]);\
      x2 =  (inptr[4] * quantptr[4]);\
      b4 = (x1 - x2);\
      x1 =  (inptr[2] * quantptr[2]);\
      x2 =  (inptr[6] * quantptr[6]);\
      x6 = (x2 * 1892)>>10;\
      d0 = x1 - x6;\
      x2 = d11 + x4;\
      x1 = b4 + d0;\
      wsptr[1] = (x1 + x2);\
      wsptr[6] = (x1 - x2);\
         break;\
      }\
      inptr+=8;\
      quantptr+= 8;\
      wsptr+= 8;\
  }

#define jpeg_decoder_1st_idct_col_0_3_4_7(inptr,quantptr,wsptr,blk_zero_tbl)\
   for (ctr = 0; ctr < 8; ctr++)\
   {\
      switch(blk_zero_tbl[ctr])\
      {\
       case 0:\
         while(ctr<8){\
            wsptr[0]=0;\
            wsptr[7]=0;\
            wsptr[3]=0;\
            wsptr[4]=0;\
            wsptr+= 8;\
            ctr++;}\
         goto _1st_idct_end;\
       case 1:\
         x1 =  (inptr[0] * quantptr[0]);\
         wsptr[0]=x1;\
         wsptr[7]=x1;\
         wsptr[3]=x1;\
         wsptr[4]=x1;\
         break;\
       case 2:\
         x1 =  (inptr[1] * quantptr[1]);\
         c4 = ((x1) * 922)>>10;\
         b12 = (x1 * 1537)>>10;\
         d12 = b12 - c4;\
         x4 = ((x1) * 1204) >> 10;\
         c7 = (x4 * 25)>>6;\
         x3 = x4 - c7;\
         x1 =  (inptr[0] * quantptr[0]);\
         x2=d12+x3;\
         wsptr[0] = (x1 + x2);\
         wsptr[7] = (x1 - x2);\
         x2 = x4-c4;\
         wsptr[3] = (x1 + x2);\
         wsptr[4] = (x1 - x2);\
         break;\
      case 3:\
         x1 =  (inptr[1] * quantptr[1]);\
         c4 = ((x1 ) * 922)>>10;\
         b12 = (x1 * 1537)>>10;\
         d12 = b12 - c4;\
         x4 = ((x1) * 1204) >> 10;\
         c7 = (x1 * 25)>>6;\
         x3 = x4 - c7;\
         b3 =  (inptr[0] * quantptr[0]);\
         d0 =  (inptr[2] * quantptr[2]);\
         x5 = (d0 * 784)>>10;\
         x1 = ((d0) * 554)>>10;\
         d1 = x1 + x5;\
         x2=d12+x3;\
         x1=b3+d1;\
         wsptr[0] = (x1 + x2);\
         wsptr[7] = (x1 - x2);\
         x1 = b3 - d1;\
         wsptr[3] = (x1 + x4);\
         wsptr[4] = (x1 - x4);\
         break;\
       default:\
      x1 =  (inptr[1] * quantptr[1]);\
      x2 =  (inptr[3] * quantptr[3]);\
      x3 =  (inptr[5] * quantptr[5]);\
      x4 =  (inptr[7] * quantptr[7]);\
      b9 = (x4 * 306)>>10;\
      c4 = ((x1 + x4) * 922)>>10;\
      d4 = b9 - c4;\
      b12 = (x1 * 1537)>>10;\
      d12 = b12 - c4;\
      x4 = x2 + x4;\
      x3 = x1 + x3;\
      x1 = ((x4+x3) * 1204) >> 10;\
      c6 = (x4 * 2009)>>10;\
      x4 = x1 - c6;\
      c7 = (x3 * 25)>>6;\
      x3 = x1 - c7;\
      x1 =  (inptr[0] * quantptr[0]);\
      x2 =  (inptr[4] * quantptr[4]);\
      b3 = (x1 + x2);\
      x1 =  (inptr[2] * quantptr[2]);\
      x2 =  (inptr[6] * quantptr[6]);\
      x5 = (x1 * 784)>>10;\
      x1 = ((x1 + x2) * 554)>>10;\
      d1 = x1 + x5;\
      x2=d12+x3;\
      x1=b3+d1;\
      wsptr[0] = (x1 + x2);\
      wsptr[7] = (x1 - x2);\
      x1 = b3 - d1;\
      x2 = d4 + x4;\
      wsptr[3] = (x1 + x2);\
      wsptr[4] = (x1 - x2);\
         break;\
      }\
      inptr+=8;\
      quantptr+= 8;\
      wsptr+= 8;\
  }

#define jpeg_decoder_1st_idct_col_1_2_5_6(inptr,quantptr,wsptr,blk_zero_tbl)\
   for (ctr = 0; ctr < 8; ctr++)\
   {\
      switch(blk_zero_tbl[ctr])\
   {\
       case 0:\
         while(ctr<8){\
            wsptr[2]=0;\
            wsptr[5]=0;\
            wsptr[1]=0;\
            wsptr[6]=0;\
            wsptr+= 8;\
            ctr++;}\
          goto _1st_idct_end;\
      case 1:\
         x1 =  (inptr[0] * quantptr[0]);\
         wsptr[2]=x1;\
         wsptr[5]=x1;\
         wsptr[1]=x1;\
         wsptr[6]=x1;\
         break;\
      case 2:\
         x1 =  (inptr[1] * quantptr[1]);\
         x1 = ((x1) * 1204) >> 10;\
         x4 = x1 ;\
         c7 = (x1 * 25)>>6;\
         x2 = x1 - c7;\
         b4 =  (inptr[0] * quantptr[0]);\
         d0 = ((x1 ) * 554)>>10;\
         x1 = b4 - d0;\
         wsptr[2] = (x1 + x2);\
         wsptr[5] = (x1 - x2);\
         x1 = b4 + d0;\
         wsptr[1] = (x1 + x4);\
         wsptr[6] = (x1 - x4);\
         break;\
      case 3:\
         x1 =  (inptr[1] * quantptr[1]);\
         c4 = ((x1 ) * 922)>>10;\
         b12 = (x1 * 1537)>>10;\
         d12 = b12 - c4;\
         x4 = ((x1) * 1204) >> 10;\
         c7 = (x1 * 25)>>6;\
         x3 = x4 - c7;\
         b3 =  (inptr[0] * quantptr[0]);\
         d0 =  (inptr[2] * quantptr[2]);\
         x2=d12+x3;\
         x1 = b3 - d0;\
         wsptr[2] = (x1 + x3);\
         wsptr[5] = (x1 - x3);\
         x1 = b3 + d0;\
         wsptr[1] = (x1 + x2);\
         wsptr[6] = (x1 - x2);\
         break;\
      default:\
      x1 =  (inptr[1] * quantptr[1]);\
      x2 =  (inptr[3] * quantptr[3]);\
      x3 =  (inptr[5] * quantptr[5]);\
      x4 =  (inptr[7] * quantptr[7]);\
      b10 = (x3 * 2102)>>10;\
      c5 = ((x2 + x3) * 2624)>>10;\
      d5 = b10 - c5;\
      b11 = (x2 * 3146)>>10;\
      d11 = b11 - c5;\
      x4 = x2 + x4;\
      x3 = x1 + x3;\
      x1 = ((x4+x3) * 1204) >> 10;\
      c6 = (x4 * 2009)>>10;\
      x4 = x1 - c6;\
      c7 = (x3 * 25)>>6;\
      x3 = x1 - c7;\
      x1 =  (inptr[0] * quantptr[0]);\
      x2 =  (inptr[4] * quantptr[4]);\
      b4 = (x1 - x2);\
      x1 =  (inptr[2] * quantptr[2]);\
      x2 =  (inptr[6] * quantptr[6]);\
      x6 = (x2 * 1892)>>10;\
      x1 = ((x1 + x2) * 554)>>10;\
      d0 = x1 - x6;\
      x1 = b4 - d0;\
      x2 = d5 + x3;\
      wsptr[2] = (x1 + x2);\
      wsptr[5] = (x1 - x2);\
      x2 = d11 + x4;\
      x1 = b4 + d0;\
      wsptr[1] = (x1 + x2);\
      wsptr[6] = (x1 - x2);\
         break;\
      }\
      inptr+=8;\
      quantptr+= 8;\
      wsptr+= 8;\
  }

#define jpeg_decoder_1st_idct_col_all(inptr,quantptr,wsptr,blk_zero_tbl)\
   for (ctr = 0; ctr < 8; ctr++)\
   {\
      switch(blk_zero_tbl[ctr])\
      {\
       case 0:\
         while(ctr<8){\
            wsptr[0]=0;\
            wsptr[1]=0;\
            wsptr[2]=0;\
            wsptr[3]=0;\
            wsptr[4]=0;\
            wsptr[5]=0;\
            wsptr[6]=0;\
            wsptr[7]=0;\
            wsptr+= 8;\
            ctr++;}\
         goto _1st_idct_end;\
      case 1:\
         x1 =  (inptr[0] * quantptr[0]);\
         wsptr[0]=x1;\
         wsptr[1]=x1;\
         wsptr[2]=x1;\
         wsptr[3]=x1;\
         wsptr[4]=x1;\
         wsptr[5]=x1;\
         wsptr[6]=x1;\
         wsptr[7]=x1;\
         break;\
       case 2:\
         x1 =  (inptr[1] * quantptr[1]);\
         c4 = ((x1 ) * 922)>>10;\
         b12 = (x1 * 1537)>>10;\
         d12 = b12 - c4;\
         x4 = ((x1) * 1204) >> 10;\
         c7 = (x1 * 25)>>6;\
         x3 = x4 - c7;\
         b3 =  (inptr[0] * quantptr[0]);\
         x2=d12+x3;\
         wsptr[0] = (b3 + x2);\
         wsptr[7] = (b3 - x2);\
         wsptr[2] = (b3 + x3);\
         wsptr[5] = (b3 - x3);\
         x2 = x4-c4;\
         wsptr[3] = (b3 + x2);\
         wsptr[4] = (b3 - x2);\
         wsptr[1] = (b3 + x4);\
         wsptr[6] = (b3 - x4);\
         break;\
      case 3:\
         x1 =  (inptr[1] * quantptr[1]);\
         c4 = ((x1 ) * 922)>>10;\
         b12 = (x1 * 1537)>>10;\
         d12 = b12 - c4;\
         x4 = ((x1) * 1204) >> 10;\
         c7 = (x1 * 25)>>6;\
         x3 = x4 - c7;\
         b3 =  (inptr[0] * quantptr[0]);\
         x1 =  (inptr[2] * quantptr[2]);\
         x5 = (x1 * 784)>>10;\
         d0 = ((x1 ) * 554)>>10;\
         d1 = d0 + x5;\
         x2=d12+x3;\
         x1=b3+d1;\
         wsptr[0] = (x1 + x2);\
         wsptr[7] = (x1 - x2);\
         x1 = b3 - d0;\
         wsptr[2] = (x1 + x3);\
         wsptr[5] = (x1 - x3);\
         x1 = b3 - d1;\
         x2 = x4-c4;\
         wsptr[3] = (x1 + x2);\
         wsptr[4] = (x1 - x2);\
         x1 = b3 + d0;\
         wsptr[1] = (x1 + x4);\
         wsptr[6] = (x1 - x4);\
         break;\
       default:\
      x1 =  (inptr[1] * quantptr[1]);\
      x2 =  (inptr[3] * quantptr[3]);\
      x3 =  (inptr[5] * quantptr[5]);\
      x4 =  (inptr[7] * quantptr[7]);\
      b9 = (x4 * 306)>>10;\
      c4 = ((x1 + x4) * 922)>>10;\
      d4 = b9 - c4;\
      b10 = (x3 * 2102)>>10;\
      c5 = ((x2 + x3) * 2624)>>10;\
      d5 = b10 - c5;\
      b11 = (x2 * 3146)>>10;\
      d11 = b11 - c5;\
      b12 = (x1 * 1537)>>10;\
      d12 = b12 - c4;\
      x4 = x2 + x4;\
      x3 = x1 + x3;\
      x1 = ((x4+x3) * 1204) >> 10;\
      c6 = (x4 * 2009)>>10;\
      x4 = x1 - c6;\
      c7 = (x3 * 25)>>6;\
      x3 = x1 - c7;\
      x1 =  (inptr[0] * quantptr[0]);\
      x2 =  (inptr[4] * quantptr[4]);\
      b3 = (x1 + x2);\
      b4 = (x1 - x2);\
      x1 =  (inptr[2] * quantptr[2]);\
      x2 =  (inptr[6] * quantptr[6]);\
      x5 = (x1 * 784)>>10;\
      x6 = (x2 * 1892)>>10;\
      x1 = ((x1 + x2) * 554)>>10;\
      d0 = x1 - x6;\
      d1 = x1 + x5;\
      x2=d12+x3;\
      x1=b3+d1;\
      wsptr[0] = (x1 + x2);\
      wsptr[7] = (x1 - x2);\
      x1 = b4 - d0;\
      x2 = d5 + x3;\
      wsptr[2] = (x1 + x2);\
      wsptr[5] = (x1 - x2);\
      x1 = b3 - d1;\
      x2 = d4 + x4;\
      wsptr[3] = (x1 + x2);\
      wsptr[4] = (x1 - x2);\
      x2 = d11 + x4;\
      x1 = b4 + d0;\
      wsptr[1] = (x1 + x2);\
      wsptr[6] = (x1 - x2);\
         break;\
      }\
      inptr+=8;\
      quantptr+= 8;\
      wsptr+= 8;\
  }


#endif /*__SW_JPEG_DECODER_H__*/
#endif /* __SW_JPEG_CODEC_SUPPORT__ !__MTK_TARGET__*/
