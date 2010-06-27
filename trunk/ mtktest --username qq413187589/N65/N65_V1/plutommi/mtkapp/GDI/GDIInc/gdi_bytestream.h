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
 *  gdi_bytestream.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI Bytesteam header.
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

#ifndef _GDI_BYTESTREAM_H_
#define _GDI_BYTESTREAM_H_

#define BYTESTREAM_BUFFER_SIZE      512 /* size of file buffer cache */

extern GDI_RESULT gdi_bytestream_create(U8 *buf_ptr, U32 buf_size);
extern GDI_RESULT gdi_bytestream_create_file(const S8 *file_name);
extern GDI_RESULT gdi_bytestream_free(void);

extern void gdi_bytestream_buffer_load_file(int at_least);
extern BOOL gdi_bytestream_buffer_load_file_widthout_exception(int at_least);
extern void gdi_bytestream_seek_file(S32 offset);

extern U8(*gdi_bytestream_get_byte) (void);
extern U8(*gdi_bytestream_peek_byte) (void);
extern U8(*gdi_bytestream_peek_byte_n) (int index);
extern U16(*gdi_bytestream_get_word) (void);
extern U32(*gdi_bytestream_get_3bytes) (void);
extern U32(*gdi_bytestream_get_dword) (void);
extern void (*gdi_bytestream_get_array) (U8 *array, U32 size);
extern void (*gdi_bytestream_flush) (U32 count);
extern void (*gdi_bytestream_seek) (S32 offset);
extern S32(*gdi_bytestream_tell) (void);
extern BOOL(*gdi_bytestream_is_eof) (void);
extern U32(*gdi_bytestream_get_size) (void);

extern FS_HANDLE gdi_bytestream_handle;
extern int gdi_bytestream_file_size;
extern int gdi_bytestream_buffer_content_size;
extern int gdi_bytestream_file_offset;
extern U8 *gdi_bytestream_buffer_reader;
extern U8 gdi_bytestream_buffer[BYTESTREAM_BUFFER_SIZE];

#define     GDI_BYTESTREAM_PEEK_BYTE_FILE(X)       \
         {                                         \
            if(!gdi_bytestream_buffer_content_size)\
               gdi_bytestream_buffer_load_file(1); \
            X = *gdi_bytestream_buffer_reader;     \
         }

#define     GDI_BYTESTREAM_PEEK_BYTE_N_FILE(X,OFFSET)    \
         {                                               \
            if(gdi_bytestream_buffer_content_size<OFFSET)\
               gdi_bytestream_buffer_load_file(OFFSET);  \
            X = gdi_bytestream_buffer_reader[OFFSET];    \
         }

#define     GDI_BYTESTREAM_GET_BYTE_FILE(X)          \
         {                                           \
            if(!(gdi_bytestream_buffer_content_size))\
               gdi_bytestream_buffer_load_file(1);   \
            gdi_bytestream_buffer_content_size--;    \
            gdi_bytestream_file_offset++;            \
            X = *gdi_bytestream_buffer_reader++;     \
         }                                           \

#define     GDI_BYTESTREAM_GET_WORD_FILE(X)             \
         {                                              \
            if(gdi_bytestream_buffer_content_size<2)    \
               gdi_bytestream_buffer_load_file(2);      \
            gdi_bytestream_buffer_content_size-=2;      \
            gdi_bytestream_file_offset+=2;              \
            X = *gdi_bytestream_buffer_reader++;        \
            X |= (*gdi_bytestream_buffer_reader++) << 8;\
         }                                              \

#define     GDI_BYTESTREAM_GET_3BYTES_FILE(X)            \
         {                                               \
            if(gdi_bytestream_buffer_content_size<3)     \
               gdi_bytestream_buffer_load_file(3);       \
            gdi_bytestream_buffer_content_size-=3;       \
            gdi_bytestream_file_offset+=3;               \
            X = *gdi_bytestream_buffer_reader++;         \
            X |= (*gdi_bytestream_buffer_reader++) << 8; \
            X |= (*gdi_bytestream_buffer_reader++) << 16;\
         }                                               \

#define     GDI_BYTESTREAM_GET_DWORD_FILE(X)             \
         {                                               \
            if(gdi_bytestream_buffer_content_size<4)     \
               gdi_bytestream_buffer_load_file(4);       \
            gdi_bytestream_buffer_content_size-=4;       \
            gdi_bytestream_file_offset+=4;               \
            X = *gdi_bytestream_buffer_reader++;         \
            X |= (*gdi_bytestream_buffer_reader++) << 8; \
            X |= (*gdi_bytestream_buffer_reader++) << 16;\
            X |= (*gdi_bytestream_buffer_reader++) << 24;\
         }                                               \

#define GDI_BYTESTREAM_FLUSH_FILE(COUNT)                             \
         {                                                           \
            int count = COUNT;                                       \
            gdi_bytestream_file_offset+=count;                       \
            if(count >=BYTESTREAM_BUFFER_SIZE)                       \
               gdi_bytestream_seek_file(gdi_bytestream_file_offset); \
            else                                                     \
            {                                                        \
               while(count)                                          \
               {                                                     \
                  if(gdi_bytestream_buffer_content_size < (int)count)\
                  {                                                  \
                     count -= gdi_bytestream_buffer_content_size;    \
                     gdi_bytestream_buffer_content_size=0;           \
                     gdi_bytestream_buffer_load_file(1);             \
                  }                                                  \
                  else                                               \
                  {                                                  \
                     gdi_bytestream_buffer_content_size-=count;      \
                     gdi_bytestream_buffer_reader +=count;           \
                     count=0;                                        \
                  }                                                  \
               }                                                     \
            }                                                        \
         }                                                           \

#define GDI_BYTESTREAM_IS_EOF_FILE                 \
         (gdi_bytestream_buffer_content_size?FALSE:\
            (gdi_bytestream_buffer_load_file_widthout_exception(1))?FALSE:TRUE)

#define GDI_BYTESTREAM_TELL_FILE       gdi_bytestream_file_offset

#define GDI_BYTESTREAM_GET_ARRAY_FILE(ARRAY_POINTER,SIZE)     \
   {                                                          \
      int size = SIZE;                                        \
      while(size>0)                                           \
      {                                                       \
         int n;                                               \
         if(gdi_bytestream_buffer_content_size == 0)          \
            gdi_bytestream_buffer_load_file(1);               \
         n= GDI_MIN(size,gdi_bytestream_buffer_content_size); \
         memcpy(ARRAY_POINTER,gdi_bytestream_buffer_reader,n);\
         ARRAY_POINTER+=n;                                    \
         gdi_bytestream_buffer_content_size -=n;              \
         size -= n;                                           \
         gdi_bytestream_file_offset+=n;                       \
         gdi_bytestream_buffer_reader+=n;                     \
      }                                                       \
   }

#endif /* _GDI_BYTESTREAM_H_ */ 

