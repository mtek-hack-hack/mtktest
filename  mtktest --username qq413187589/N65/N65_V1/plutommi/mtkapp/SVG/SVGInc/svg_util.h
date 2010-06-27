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
#ifndef _SVG_UTIL_H
#define _SVG_UTIL_H

#define svg_strtod(A,B)     strtod((const char*)A,(char**)B)

extern svg_enum svg_const_pool_init(void);
extern U8 *svg_const_pool(U8 *value);
extern U8 *svg_const_pool_raw(U8 *value, U32 len);
extern U8 *svg_const_pool_utf82ucs2(U8 *data, U32 *dest_len);

extern void svg_fp_to_dos_slash(U16 *p);
extern void svg_fp_to_dirname(U16 *p);
extern void svg_fp_concat_path(U16 *path, U16 *path1);

extern U32 svg_base64_len(U32 len);
extern void svg_base64_decode(U8 *dest, U32 *len, U8 *src, U32 srcl);

extern float svg_vec_to_angle(float x, float y);

#define STRCPY(S1,S2)      strcpy((char*)(S1),(char*)(S2))
#define STRCMP(S1,S2)      strcmp((char*)(S1),(char*)(S2))
#define STRLEN(S1)         strlen((char*)(S1))
#define STRCHR(S1,C)    strchr((char*)(S1),(int)C)
#define STRNCMP(S1,S2,N)   strncmp((char*)(S1),(char*)(S2),(size_t)N)
#define STRSTR(S1,S2)      strstr((char*)(S1),(char*)(S2))
#define STRICMP(S1,S2)     stricmp((char*)(S1),(char*)(S2))

typedef struct
{
    U32 max_len;    /* exclude max null char */
    U32 len;        /* exclude end null char */
    U8 *data;       /* memory space is (max_len +1) for null char */
} svg_string_t;

extern svg_string_t *svg_str_new(U8 *src);
extern void svg_str_delete(svg_string_t *str);
extern void svg_str_resize(svg_string_t *str, int max_len);
extern void svg_str_append(svg_string_t *str, U8 *data);
extern void svg_qsort(void *base, unsigned num, unsigned width, int (*comp)(const void *, const void *));
#endif /* _SVG_UTIL_H */ 

