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
 *
 * Filename:
 * ---------
 * fmt_def.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
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
 *==============================================================================
 *******************************************************************************/

#ifndef _FMT_DEF_H_
#define _FMT_DEF_H_

#define FMT_MAX_BUFFER_SIZE   16600

/****************************************************************************
* Filter
*****************************************************************************/
#define FMGR_MAX_FILTER_COUNT (FMGR_TYPE_COUNT-5)

typedef enum
{
    FMGR_TYPE_ALL = 1,  /* this is for FMT to delete all files at once */
    FMGR_TYPE_UNKNOW,
    FMGR_TYPE_FOLDER,
    FMGR_TYPE_FOLDER_DOT,

    /* image */
    FMGR_TYPE_BMP,
    FMGR_TYPE_JPG,
    FMGR_TYPE_JPEG,
    FMGR_TYPE_GIF,
    FMGR_TYPE_PNG,
    FMGR_TYPE_EMS,
    FMGR_TYPE_ANM,
    FMGR_TYPE_WBMP,
    FMGR_TYPE_WBM,
    FMGR_TYPE_SVG,
    FMGR_TYPE_M3D,

    /* audio */
    FMGR_TYPE_IMY,
    FMGR_TYPE_MID,
    FMGR_TYPE_MIDI,
    FMGR_TYPE_WAV,
    FMGR_TYPE_AMR,
    FMGR_TYPE_AAC,
    FMGR_TYPE_DAF,
    FMGR_TYPE_MP2,
    FMGR_TYPE_VM,
    FMGR_TYPE_AWB,
    FMGR_TYPE_AIF,
    FMGR_TYPE_AIFF,
    FMGR_TYPE_AIFC,
    FMGR_TYPE_AU,
    FMGR_TYPE_SND,
    FMGR_TYPE_M4A,
    FMGR_TYPE_MMF,
    FMGR_TYPE_WMA,

    /* video */
    FMGR_TYPE_3GP,
    FMGR_TYPE_MP4,
    FMGR_TYPE_MPG,
    FMGR_TYPE_AVI,
    FMGR_TYPE_3G2,
    FMGR_TYPE_SDP,
    FMGR_TYPE_RAM,

    /* SW Flash */
    FMGR_TYPE_ZDD,
    FMGR_TYPE_VIS,
    FMGR_TYPE_IVIS,
    FMGR_TYPE_KVIS,
    FMGR_TYPE_MVIS,

    /* swflash */
    FMGR_TYPE_CMP,

    /* others */
    FMGR_TYPE_JAD,
    FMGR_TYPE_JAR,
    FMGR_TYPE_VCF,
    FMGR_TYPE_VCS,
    FMGR_TYPE_LRC,

    FMGR_TYPE_EBOOK_TXT,
    FMGR_TYPE_EBOOK_PDB,

    FMGR_TYPE_THEME,

    /* barcode reader */
    FMGR_TYPE_MBC,

    /* DRM 1.0 */
    FMGR_TYPE_DCF,
    FMGR_TYPE_DM,

    /* Bookmark */
    FMGR_TYPE_WML,
    FMGR_TYPE_HTML,
    FMGR_TYPE_HTM,
    FMGR_TYPE_XHTML,

    /* Fota Full Image */
    FMGR_TYPE_FOTA_FULL,

    /* DRM 2.0 */
    FMGR_TYPE_ODF,

    /* V-Bookmark */
    FMGR_TYPE_URL,
    FMGR_TYPE_VBM,

    /* end */
    FMGR_TYPE_COUNT
} fmgr_filter_type_enum;

typedef enum
{
    FMGR_GROUP_IMAGE = 1,
    FMGR_GROUP_AUDIO,
    FMGR_GROUP_VIDEO,
    FMGR_GROUP_SWFLASH,
    FMGR_GROUP_AVATAR,
    FMGR_GROUP_UNKNOWN
} fmgr_file_group_enum;

#define FMGR_MAX_FILE_TYPE_COUNT (4*32)

typedef struct
{
    unsigned int mask[FMGR_MAX_FILE_TYPE_COUNT / 32];
} fmgr_filter_mask_struct;

typedef fmgr_filter_mask_struct FMGR_FILTER;

#ifdef MMI_ON_WIN32
extern BOOL mmi_fmgr_check_audio_filter(FMGR_FILTER *file_type);
extern BOOL mmi_fmgr_check_image_filter(FMGR_FILTER *file_type);
extern BOOL mmi_fmgr_check_video_filter(FMGR_FILTER *file_type);
extern BOOL mmi_fmgr_check_swflash_filter (FMGR_FILTER *file_type);
#else /* MMI_ON_WIN32 */ 
extern unsigned char mmi_fmgr_check_audio_filter(FMGR_FILTER *file_type);
extern unsigned char mmi_fmgr_check_image_filter(FMGR_FILTER *file_type);
extern unsigned char mmi_fmgr_check_video_filter(FMGR_FILTER *file_type);
extern unsigned char mmi_fmgr_check_swflash_filter (FMGR_FILTER *file_type);
#endif /* MMI_ON_WIN32 */ 
extern void mmi_fmgr_set_audio_filter(FMGR_FILTER *file_type);
extern void mmi_fmgr_set_image_filter(FMGR_FILTER *file_type);
extern void mmi_fmgr_set_video_filter(FMGR_FILTER *file_type);
extern void mmi_fmgr_set_swflash_filter(FMGR_FILTER *file_type);

#define FMGR_FILTER_INIT(a)      (memset((a)->mask, 0, sizeof((a)->mask)))
#define FMGR_FILTER_SET(a,b)     ( ((a)->mask[b/32]) |= (((unsigned int)1)<<(b%32)) )
#define FMGR_FILTER_IS_SET(a,b)  ( ((a)->mask[b/32]) & (((unsigned int)1)<<(b%32)) )

#define FMGR_FILTER_CLEAR(a,b)   ((a)->mask[b/32] &= (~(((unsigned int)1)<<(b%32))))

#define FMGR_FILTER_SET_AUDIO(a)       mmi_fmgr_set_audio_filter (a)
#define FMGR_FILTER_IS_SET_AUDIO(a)    mmi_fmgr_check_audio_filter (a)

#define FMGR_FILTER_SET_IMAGE(a)       mmi_fmgr_set_image_filter (a)
#define FMGR_FILTER_IS_SET_IMAGE(a)    mmi_fmgr_check_image_filter (a)

#define FMGR_FILTER_SET_VIDEO(a)       mmi_fmgr_set_video_filter (a)
#define FMGR_FILTER_IS_SET_VIDEO(a)    mmi_fmgr_check_video_filter (a)

#define FMGR_FILTER_SET_SWFLASH(a)       mmi_fmgr_set_swflash_filter (a)
#define FMGR_FILTER_IS_SET_SWFLASH(a)    mmi_fmgr_check_swflash_filter (a)

#define FMGR_FILTER_SET_ALL(a)                \
do {                                          \
   memset((a)->mask, 0xff, sizeof((a)->mask));\
} while(0)

/* filter structure */
typedef struct
{
    unsigned int type;
    char ext[6];
} fmgr_filter_struct;

typedef enum
{
    FMT_MOVE,
    FMT_COPY
} fmt_copy_enum;

extern void mmi_fmgr_remove_last_dir(char *path);

#endif /* _FMT_DEF_H_ */ 

