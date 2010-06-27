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
 *  gdi_primitve.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI primitive header file.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _GDI_PRIMITIVE_H_
#define _GDI_PRIMITIVE_H_

/****************************************************************************
* Main LCD                                                                 
*****************************************************************************/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_SUBLCD__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SUBLCD__ */
#endif /* 0 */ 
/* define blue as transprent color */

/* Assert */
#define GDI_ASSERT(exp)       ASSERT(exp)
#ifndef __PRODUCTION_RELEASE__
#define GDI_DEBUG_ASSERT(exp) ASSERT(exp)
#else 
#define GDI_DEBUG_ASSERT(exp)
#endif 


extern jmp_buf gdi_jmpbuf;
extern BOOL gdi_jmpbuf_is_used;

#define GDI_RAISE(ret_code)   longjmp (gdi_jmpbuf, ret_code)
#define GDI_TRY                                \
   {                                           \
      int jmpret;                              \
      int backup_gdi_mutex_cnt = gdi_mutex.cnt;\
      GDI_ASSERT(!gdi_jmpbuf_is_used);         \
      gdi_jmpbuf_is_used = TRUE;               \
      jmpret = setjmp (gdi_jmpbuf);            \
      if(jmpret == 0 )                         \
      {

#define GDI_CATCH_BEGIN                     \
      }                                     \
      else                                  \
      {                                     \
         GDI_UNLOCK_N(backup_gdi_mutex_cnt);\
         {

#define GDI_CATCH_END            \
         }                       \
      }                          \
      gdi_jmpbuf_is_used = FALSE;\
   }

#define GDI_CATCH(N) if(jmpret == N)

/* check rect within clip, if exceed limit, will return */
#define GDI_CLIP_TWO_RECT(X1, Y1, X2, Y2,CX1,CY1,CX2,CY2,NULL_ACTION)\
{                                                                    \
   if(X1 > X2) { NULL_ACTION; }                                      \
   else if(Y1 > Y2)  { NULL_ACTION; }                                \
   else if(X2 < CX1) { NULL_ACTION; }                                \
   else if(Y2 < CY1) { NULL_ACTION; }                                \
   else if(X1 > CX2) { NULL_ACTION; }                                \
   else if(Y1 > CY2) { NULL_ACTION; }                                \
   else                                                              \
   {                                                                 \
      if(X1 < CX1) { X1 = CX1; }                                     \
      if(Y1 < CY1) { Y1 = CY1; }                                     \
      if(X2 > CX2) { X2 = CX2; }                                     \
      if(Y2 > CY2) { Y2 = CY2; }                                     \
   }                                                                 \
}

#define GDI_CLIP_RECT_TEST(X1, Y1, X2, Y2,NULL_ACTION)    \
{                                                         \
   if(X1 > X2) { NULL_ACTION; }                           \
   else if(Y1 > Y2)  { NULL_ACTION; }                     \
   else if(X2 < GDI_LAYER.clipx1) { NULL_ACTION; }        \
   else if(Y2 < GDI_LAYER.clipy1) { NULL_ACTION; }        \
   else if(X1 > GDI_LAYER.clipx2) { NULL_ACTION; }        \
   else if(Y1 > GDI_LAYER.clipy2) { NULL_ACTION; }        \
   else                                                   \
   {                                                      \
      if(X1 < GDI_LAYER.clipx1) { X1 = GDI_LAYER.clipx1; }\
      if(Y1 < GDI_LAYER.clipy1) { Y1 = GDI_LAYER.clipy1; }\
      if(X2 > GDI_LAYER.clipx2) { X2 = GDI_LAYER.clipx2; }\
      if(Y2 > GDI_LAYER.clipy2) { Y2 = GDI_LAYER.clipy2; }\
   }                                                      \
}

/****************************************************************************
* function
*****************************************************************************/
extern void gdi_memset16(U8 *address, U16 pixel, int size);
extern S32 gdi_sizeof_pixels(gdi_color_format cf, S32 width, S32 height);
extern S32 gdi_bits_per_pixel(gdi_color_format cf);
extern gdi_color_format gdi_get_color_format(S32 bits);

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// GDI Software resizer
///////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct
{
    U8 *dest;
    S32 bitsperpixels;
    S32 src_height_range;   /* Source */
    S32 dest_height_range;  /* Destination */
    S32 offset_dx;
    S32 offset_dy;

    S32 want_dx1, want_dx2; /* wanted rendering area */
    S32 want_dy1, want_dy2;

    S32 want_sx;    /* current wanted point (want_x,want_y) */
    S32 want_sy;

    S16 *want_sx_table;
    S16 *want_sx_table_end;
    S16 *next_want_sx;
    S32 next_want_dy;

    S32 dir_x;
    S32 dir_y;

    /* for non resize used */
    S32 want_start_sx, want_start_sy;
    S32 want_end_sx, want_end_sy;
    S32 dest_pitch_jump;
} gdi_resizer_struct;

typedef void (*gdi_resizer_put_func) (gdi_color c, BOOL want_draw);
extern gdi_resizer_put_func gdi_resizer_put;
extern gdi_resizer_struct GDI_RESIZER;

#define IS_GDI_RESIZER_WANT_DRAW(SX,SY)   (SX == GDI_RESIZER.want_sx && SY == GDI_RESIZER.want_sy)

#define GDI_NON_RESIZER_PUT_X(COLOR,WANT_DRAW)                    \
   do                                                             \
   {                                                              \
      if(WANT_DRAW)                                               \
         GDI_RESIZER_PUT_PIXEL(COLOR);                            \
      GDI_RESIZER_INCREASE_DEST;                                  \
      if(GDI_RESIZER.want_sx == GDI_RESIZER.want_end_sx)          \
      {                                                           \
         if(GDI_RESIZER.want_sy == GDI_RESIZER.want_end_sy)       \
         {                                                        \
            GDI_RESIZER.want_sx = 0x0fffffff;/* very large number */\
         }                                                        \
         else/* move to next line begin */                         \
         {                                                        \
            GDI_RESIZER.want_sx = GDI_RESIZER.want_start_sx;      \
            GDI_RESIZER.want_sy += GDI_RESIZER.dir_y;             \
            GDI_RESIZER.dest += GDI_RESIZER.dest_pitch_jump;      \
         }                                                        \
      }                                                           \
      else                                                        \
      {                                                           \
         GDI_RESIZER.want_sx += GDI_RESIZER.dir_x;                \
      }                                                           \
   }while(0)

extern BOOL gdi_resizer_init(
                S32 src_width,
                S32 src_height,
                S32 src_clipx1,
                S32 src_clipy1,
                S32 src_clipx2,
                S32 src_clipy2,
                S32 dest_x1,
                S32 dest_y1,
                S32 dest_x2,
                S32 dest_y2);

extern void gdi_resizer_set_want_sy(S32 want_sy);

#endif /* _GDI_PRIMITIVE_H_ */ 

