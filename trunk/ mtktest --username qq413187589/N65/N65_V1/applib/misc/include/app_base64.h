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
 * app_base64.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains Base64 decode / encode function prototypes.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _APP_BASE64_H
#define _APP_BASE64_H

/* strem-style encode/decode context */
typedef struct
{
    /* private: */
    kal_uint8 buf[4];
    kal_uint8 buf_cnt;
    kal_uint8 finish_flag;
    kal_uint8 illchr_flag;
    kal_uint8 illpad_flag;

    kal_uint8 wrap_count;
    kal_uint8 wrap_max;
    kal_uint8 reserved[2];
}applib_base64_part_context;

/* all-in-one encode */
extern kal_int32 applib_base64_encode_basic(
                    const kal_char *src, 
                    kal_int32 srcl,
                    kal_char *dst,
                    kal_int32 dstl,
                    kal_bool auto_line_wrap);

/* all-in-one decode */
extern kal_int32 applib_base64_decode_basic(
                    const kal_char *src, 
                    kal_int32 srcl,
                    kal_char *dst,
                    kal_int32 dstl);

/* stream-style encode */
extern kal_int32 applib_base64_part_encode_init(
                    applib_base64_part_context *cntx,
                    kal_int32 max_part_buf_size,
                    kal_bool auto_line_wrap);

extern kal_int32 applib_base64_part_encode_append(
                    applib_base64_part_context *cntx,
                    const kal_char *src,
                    kal_int32 *srcl,
                    kal_char  *dst,
                    kal_int32 dstl);

extern kal_int32 applib_base64_part_encode_finish(
                    applib_base64_part_context* cntx,
                    kal_char *dst,
                    kal_int32 dstl);

/* stream-style decode */
extern kal_int32 applib_base64_part_decode_init(
                    applib_base64_part_context *cntx,
                    kal_int32 max_part_buf_size);

extern kal_int32 applib_base64_part_decode_append(
                    applib_base64_part_context* cntx,
                    const kal_char *src,
                    kal_int32 *srcl,
                    kal_char *dst,
                    kal_int32 dstl);

extern kal_int32 applib_base64_part_decode_finish(
                    applib_base64_part_context* cntx,
                    kal_bool* illegal_format);


/* 
 * NOTE:
 * the APIs below will be obsoleted
 * them are here only for compatible with old code 
 */

extern kal_int32 applib_base64_decode(kal_char *src, kal_uint32 srcl, kal_char *dest, kal_uint32 destl);

extern kal_uint32 applib_base64_decode_len(const kal_char *str, kal_uint32 len);

extern kal_uint16 applib_find_base64_boundary(kal_char *ptr, kal_int32 len);

extern kal_int32 applib_base64_encode(kal_char *src, kal_uint32 srcl, kal_char *dest, kal_uint32 destl);

extern kal_uint32 applib_base64_encode_len(kal_uint32 len);

#endif /* _APP_BASE64_H */ 

