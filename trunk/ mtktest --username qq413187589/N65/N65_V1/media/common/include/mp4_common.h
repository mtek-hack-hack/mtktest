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
 * mp4_common.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   MPEG-4 Common Definitions
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
 
#ifndef __MP4_COMMON_H__
#define __MP4_COMMON_H__

#define MP4_BRAND_3GP5 0x33677035
#define MP4_BRAND_3GP6 0x33677036

#define BOX_TYPE_FTYP 0x66747970
#define BOX_TYPE_MOOV 0x6D6F6F76
#define BOX_TYPE_MVHD 0x6D766864
#define BOX_TYPE_TRAK 0x7472616B
#define BOX_TYPE_TKHD 0x746B6864
#define BOX_TYPE_MDIA 0x6D646961
#define BOX_TYPE_MDHD 0x6D646864
#define BOX_TYPE_HDLR 0x68646C72
#define BOX_TYPE_MINF 0x6D696E66
#define BOX_TYPE_SMHD 0x736d6864
#define BOX_TYPE_DINF 0x64696E66
#define BOX_TYPE_DREF 0x64726566
#define BOX_TYPE_URL  0x75726C20
#define BOX_TYPE_STBL 0x7374626C
#define BOX_TYPE_STSD 0x73747364
#define BOX_TYPE_STTS 0x73747473
#define BOX_TYPE_STSC 0x73747363
#define BOX_TYPE_STSZ 0x7374737A
#define BOX_TYPE_STCO 0x7374636F
#define BOX_TYPE_STSS 0x73747373
#define BOX_TYPE_ESDS 0x65736473
#define BOX_TYPE_DAMR 0x64616D72
#define BOX_TYPE_D263 0x64323633
#define BOX_TYPE_BITR 0x62697472
#define BOX_TYPE_MDAT 0x6D646174

#define HDLR_TYPE_VIDE 0x76696465
#define HDLR_TYPE_SOUN 0x736F756E

#define SAMPLE_FMT_MP4V 0x6D703476
#define SAMPLE_FMT_MP4A 0x6D703461
#define SAMPLE_FMT_SAMR 0x73616D72
#define SAMPLE_FMT_SAWB 0x73617762
#define SAMPLE_FMT_S263 0x73323633

typedef enum {
   MP4_AUDIO_NONE = 0,
   MP4_AUDIO_AAC,
   MP4_AUDIO_AMR,
   MP4_AUDIO_AMR_WB
} MP4_Audio_Type;

typedef enum {
   MP4_VIDEO_NONE = 0,
   MP4_VIDEO_MPEG4,
   MP4_VIDEO_H263
} MP4_Video_Type;

/* the value also used as array index for sample tables */
typedef enum {
   MP4_TRACK_AUDIO = 0,
   MP4_TRACK_VIDEO = 1
} MP4_Track_Type;

#define MP4_RESERVED_TRACK_NO 0xFF

#define ADTS_HEADER_SIZE 7
/*
 * 63+4+2+4+4+4+4+2+3+4+1+4+1+4+1+2+1+16*5*3+16*4*2+16*5 = 556
 * (556+7)/8 = 70 (byte_alignment)
 * 70 + 1 (comment_field_bytes) = 71
 */
#define ADIF_HEADER_SIZE 63
 
#endif

