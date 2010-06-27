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
*  aud_id3_parser.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   id3 parsing definitions
*
* Author:
* -------
*  Tim Chen
*
*==============================================================================
*           HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * $Log$
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#ifndef __ID3_PARSER_H__
#define __ID3_PARSER_H__

#include "aud_input_stream.h"

#define ID3_TAG_POOL_SIZE 570   /* number of bytes */
#define ID3_TAG_FS_READ_BUF_SIZE (4*1024)
#define ID3_TAG_GENRE_NUM 148
#define PARSE_ID3_FRAME_NO_SPACE -1
#define PARSE_ID3_FRAME_SUCCESS 0
#define PARSE_ID3_FRAME_ABORT 1

#define MAX_ID3_TITLE_LEN 80
#define MAX_ID3_ARTIST_LEN 80
#define MAX_ID3_ALBUM_LEN 80
#define MAX_ID3_GENRE_LEN 30
#define MAX_ID3_YEAR_LEN 10
#define MAX_ID3_COPYRIGHT_LEN 40

typedef struct
{
    unsigned short title[MAX_ID3_TITLE_LEN + 1];
    unsigned short artist[MAX_ID3_ARTIST_LEN + 1];
    unsigned short album[MAX_ID3_ALBUM_LEN + 1];
    unsigned short genre[MAX_ID3_GENRE_LEN + 1];
    unsigned short year[MAX_ID3_YEAR_LEN + 1];
    unsigned short copyright[MAX_ID3_COPYRIGHT_LEN + 1];
    unsigned short duration[9];
    unsigned short size[11];
    unsigned short quality[25];
    unsigned short filename[42];
    unsigned short channel_num;
}
aud_info_struct;

typedef enum
{
    ID3_FRAME_TITLE,
    ID3_FRAME_ARTIST,
    ID3_FRAME_ALBUM,
    ID3_FRAME_GENRE,
    ID3_FRAME_YEAR,
    ID3_FRAME_COPYRIGHT,
    NUM_OF_ID3_FRAME
}
ID3_TAG_FRAME_ENUM;

typedef enum
{
    ID3_FRAME_TEXT_ENCODING_ISO_8859_1,
    ID3_FRAME_TEXT_ENCODING_UTF16,
    ID3_FRAME_TEXT_ENCODING_UTF16_BE,
    ID3_FRAME_TEXT_ENCODING_UTF8
}
ID3_TAG_FRAME_TEXT_ENCODING_ENUM;

typedef enum
{
    ID3_UTF16_BE,
    ID3_UTF16_LE,
    ID3_UTF16_UNKNOWN_BYTE_ORDER
}
ID3_TAG_UTF16_BYTE_ORDER_ENUM;

typedef struct
{
    kal_wchar *next_p;
    kal_uint32 available_words;
    kal_wchar text[ID3_TAG_POOL_SIZE / 2];
}
id3_tag_text_pool_struct;

typedef struct
{
    kal_wchar *text;
    kal_uint32 size;    /* include null terminator */
}
id3_tag_frame_struct;

typedef struct
{
    kal_wchar id[4];
    kal_uint32 size;        /* include header & data */
    kal_uint32 data_offset;
    kal_uint32 data_size;   /* data size after unsync */
    kal_bool unsync;
}
id3_tag_frame_header_struct;

typedef struct
{
    id3_tag_frame_struct frames[NUM_OF_ID3_FRAME];
    id3_tag_text_pool_struct text_pool;

    kal_uint32 v2_size;                 /* not include header & footer size (original size) */
    kal_uint32 v2_reverse_unsync_size;  /* tag size after reverse unsync process, it's valid when v2_unsync is set */
    kal_uint8 v2_major_ver;
    kal_bool v2_unsync;
    kal_bool v2_footer;
    kal_bool v2_exthdr;
    kal_bool v2_crc;                    /* it's valid when v2_exthdr flag is set */
    kal_uint32 v2_exthdr_size;          /* it's valid when v2_exthdr flag is set */
}
id3_tag_struct;

typedef struct
{
    kal_uint8 offset;
    kal_uint8 size;
}
id3_tag_v1_field_struct;

extern kal_int32 med_util_utf8_to_ucs2(kal_uint8 *dest, kal_uint32 dest_size, kal_uint8 *src, kal_uint32 src_size);

extern kal_int32 id3_tag_utf16_to_ucs2(
                    kal_uint8 byte_order,
                    kal_uint8 *dest,
                    kal_uint32 dest_size,
                    kal_uint8 *src,
                    kal_uint32 src_size);

extern kal_int32 id3_tag_parse_number(kal_wchar *text, kal_uint32 text_size);

extern kal_uint32 id3_tag_get_unsync_uint32(kal_uint8 *data, kal_uint8 size);

extern kal_uint32 id3_tag_get_uint32(kal_uint8 *data, kal_uint8 size);

extern kal_uint32 id3_tag_reverse_unsync_process(kal_uint8 *data, kal_uint32 size);

extern void id3_text_pool_init(id3_tag_text_pool_struct *id3_text_pool);

extern void id3_text_pool_consume(id3_tag_text_pool_struct *id3_text_pool, kal_uint32 num_of_words);

extern void id3_frame_init(id3_tag_frame_struct *id3_frame);

extern void id3_tag_init(id3_tag_struct *id3_tag);

extern kal_bool id3_tag_parse_v2_tag_header(kal_uint8 *data, id3_tag_struct *id3_tag);

extern kal_bool id3_tag_parse_v2_tag_extended_header(
                    kal_uint8 *data,
                    id3_tag_struct *id3_tag,
                    kal_bool data_full_load);

extern kal_int8 id3_tag_parse_v2_frame_header(
                    kal_uint8 *data,
                    kal_int32 size,
                    id3_tag_frame_header_struct *frame_header,
                    id3_tag_struct *id3_tag);

extern kal_bool id3_tag_parse_v2_frame_data(
                    kal_uint8 *data,
                    id3_tag_frame_header_struct *frame_header,
                    id3_tag_struct *id3_tag);

extern kal_int8 id3_tag_match_v2_frame_id_from_list(kal_uint8 *id, const char *id_list[], kal_uint8 size);

extern kal_bool id3_tag_parse_v2_tag(audio_input_stream_struct *input_streame, id3_tag_struct *id3_tag);

extern kal_bool id3_tag_parse_v1_tag(audio_input_stream_struct *input_stream, id3_tag_struct *id3_tag);

extern kal_int32 id3_tag_parse_v2_tag_size(kal_uint8 *data);

extern kal_bool id3_tag_parse(audio_input_stream_struct *input_stream, id3_tag_struct *id3_tag);

#endif /* __ID3_PARSER_H__ */ 

