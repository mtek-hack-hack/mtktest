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
*  aud_daf_parser.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   daf parsing definitions
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
 * removed!
 * removed!
 * 
 *
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#ifndef __DAF_PARSER_H__
#define __DAF_PARSER_H__

#include "aud_id3_parser.h"

#define DAF_FRAME_CHECK_SIZE (20*1024)

typedef enum
{
    DAF_VERSION_1,
    DAF_VERSION_2,
    DAF_VERSION_NONE,
    DAF_VERSION_2_5
}
DAF_VERSION_ID_ENUM;

typedef enum
{
    DAF_LAYER_I,
    DAF_LAYER_II,
    DAF_LAYER_III,
    DAF_LAYER_NONE
}
DAF_LAYER_ENUM;

typedef enum
{
    DAF_CHECK_FRAME_TRUE,
    DAF_CHECK_FRAME_FALSE,
    DAF_CHECK_FRAME_EOF
}
DAF_CHECK_NEXT_FRAME_RESULT_ENUM;

typedef enum
{
    DAF_FIND_FRAME_TRUE,
    DAF_FIND_FRAME_FALSE,
    DAF_FIND_FRAME_FREE_BITRATE
}
DAF_FIND_NEXT_FRAME_RESULT_ENUM;

typedef struct
{
    kal_uint32 duration;    /* seconds */
    kal_uint32 bitrate;     /* bps */
    kal_uint32 samplerate;
    kal_uint32 channel_num;
}
daf_data_info_struct;

typedef struct
{
    kal_uint8 version;      /* DAF_VERSION_ID_ENUM */
    kal_uint8 layer;        /* DAF_LAYER_ENUM */
    kal_uint8 channel_num;  /* 1 -> mono, 2 -> stereo */
    kal_bool padding;       /* 1 -> yes, 0 -> no */
    kal_uint32 sample_rate; /* bps */
    kal_uint32 bitrate;     /* bps */
    kal_uint32 min_frame_size;
    kal_uint32 max_frame_size;
    kal_uint32 frame_size;
}
daf_header_struct;

extern kal_bool daf_parse_frame_header(kal_uint8 *data, daf_header_struct *header);

extern kal_bool daf_find_next_frame(
                    audio_input_stream_struct *input_stream,
                    daf_header_struct *header,
                    kal_uint32 move_offset);

extern kal_uint8 daf_check_next_frame(
                    audio_input_stream_struct *input_stream,
                    daf_header_struct *prev_header,
                    kal_int32 min_next_pos,
                    kal_int32 max_next_pos,
                    kal_int32 *next_pos);

extern kal_bool daf_parse(audio_input_stream_struct *input_stream, kal_uint32 *offset, daf_data_info_struct *info_p);

extern void daf_set_data_info(
                aud_info_struct *info_p,
                kal_uint32 channel_num,
                kal_uint32 duration,
                kal_uint32 size,
                kal_uint32 bitrate,
                kal_uint32 samplerate);

extern void daf_parse_data_info(
                aud_info_struct *info_p,
                audio_input_stream_struct *input_stream,
                id3_tag_struct *id3_tag);

extern kal_bool daf_seek(audio_input_stream_struct *input_stream, kal_uint32 *offset);

extern kal_bool get_aud_info(kal_wchar *filename, aud_info_struct *aud_info_p);
extern kal_bool get_aud_meta_data_file(kal_wchar *filename, aud_info_struct *aud_info_p);
extern kal_bool get_aud_meta_data_array(kal_char *ptr, kal_uint32 size, aud_info_struct *aud_info_p);

#endif /* __DAF_PARSER_H__ */ 

